#include <generated/autoconf.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/delay.h>

#include <linux/kernel.h>   /* DBG_PRINT()    */
#include <linux/slab.h>     /* kmalloc()      */
#include <linux/types.h>    /* size_t         */
#include <linux/semaphore.h>
#include <linux/cdev.h>
#include <linux/dma-mapping.h>
#include <linux/export.h>
#include <asm/uaccess.h>    /* copy_*_user    */
#include <asm/barrier.h> /*dsb()*/

#include <mach/irqs.h>
#include <linux/interrupt.h>
#include <linux/pageremap.h>

#include <asm/cacheflush.h>

#include <mach/system.h>
#include <rbus/osdovl_reg.h>

#include <gal/rtk_gdma_driver.h>
#include <gal/rtk_osdcomp_driver.h>
#include <gal/rtk_osdcomp_scale_coef.h>



extern unsigned int globe_disp_pixel_mode;	/* 0: 1pixel, 1: 2pixel */


struct workqueue_struct     *psCmpReceiveWorkQueue;
struct cmp_receive_work sCmpReceiveWork[MAX_COMP_BUFF];

/* gdma workqueue  */
extern struct workqueue_struct *psGdmaReceiveWorkQueue;
extern struct gdma_receive_work sGdmaReceiveWork[GDMA_MAX_PIC_Q_SIZE];

/* use in GDMA_Update */
extern volatile int osdSyncStamp[GDMA_PLANE_MAXNUM];	/*  keep the setting which picture has syncstamp */
extern volatile int osdSyncStampTimeout[GDMA_PLANE_MAXNUM];


extern gdma_dev *gdma_devices;
extern int gdma_nr_devs;

COMP_CONTROL *comp_ctl;
int osd_comp_init_module_status = COM_MOD_INIT;


/*
*	record OSD plane by prog done flag and disable the indicated OSD plane when compress done
*/
volatile unsigned int gActiveOffPlane = 0;


#ifdef _TEST_CODE_OSDCOMP_
uint g_decompress_virt_buf_addr;
uint g_decompress_phy_buf_addr;
#endif


/** @brief Initial function of Offline OSD compress and blending
*  @param None
*  @return GDMA_SUCCESS or negative value
*/
int osd_comp_work_queue_init(void)
{
	int result, i;
	GD_PRINT_2(KERN_EMERG"\n\n=======================================================================\n\n");
	/* printk("[OSD_COMP]: osd_comp_init_module\n"); */

	comp_ctl = kmalloc(sizeof(COMP_CONTROL), GFP_KERNEL);
	if (!(comp_ctl)) {
		result = -ENOMEM;
		osd_comp_cleanup_module();   /* fail */
		return result;
	}
	memset(comp_ctl, 0, sizeof(COMP_CONTROL));
	memset(sCmpReceiveWork, 0, sizeof(struct cmp_receive_work)*MAX_COMP_BUFF);
	sema_init(&comp_ctl->compress_sem, 0);
	sema_init(&comp_ctl->softabort_sem, 1);
	sema_init(&comp_ctl->dequeue_sem, 1);
	sema_init(&comp_ctl->pli_sem, 1);

	comp_ctl->comp_sem = COMP_SEM_COUNT;/* Can't_USE_SEM+ */
	comp_ctl->comp_process = 1;
	comp_ctl->compress_ratio = DEFAULT_COMPRESS_RATIO;
	comp_ctl->seg_size = DEFAULT_SEG_SIZE;/* (w*h*ratio/50) */
	psCmpReceiveWorkQueue = alloc_ordered_workqueue("OsdCompressRecevie", WQ_FREEZABLE | WQ_MEM_RECLAIM | WQ_HIGHPRI);
	memset(&sCmpReceiveWork[0], 0x00, sizeof(sCmpReceiveWork));
	for (i = 0; i < MAX_COMP_BUFF; i++) {
		INIT_WORK((struct work_struct *)&sCmpReceiveWork[i], osd_comp_receive_dequeue);
	}
	return GDMA_SUCCESS;
}

int osd_comp_work_queue(void)
{
	if (osd_comp_init_module_status == COM_MOD_INIT) {
		osd_comp_init_module_status = COM_MOD_START;
		osd_comp_init_module();
	} else if (osd_comp_init_module_status == COM_MOD_END)
		return 1;

	return GDMA_SUCCESS;
}

int osd_comp_receive_enqueue(PICTURE_LAYERS_OBJECT *data)
{
	COMPOSE_PICTURE_OBJECT *com_picObj = &data->layer[0];
	COMP_WIN *win = NULL, *ctlcmpwin = NULL;
	OSD_WIN *win_tmp = NULL;
	GDMA_PICTURE_OBJECT *picObj = NULL;
	int work_idx = -1;
	int idx = 0, iloop = 0, layerIdx = 0;
	gdma_dev *gdma = &gdma_devices[0];
	int i;
	dma_addr_t addr;

	down(&comp_ctl->softabort_sem);

	/* search free work */
	for (i = 0; i < MAX_COMP_BUFF; i++) {
		if (sCmpReceiveWork[((idx+i)%MAX_COMP_BUFF)].used == 0) {
			idx = ((idx+i)%MAX_COMP_BUFF);
			break;
		}
	}

	if (i == MAX_COMP_BUFF) {
		printk(KERN_EMERG"%s: 2 compress buffer full, comp_ctl->comp_sem=%d \n", __FUNCTION__, comp_ctl->comp_sem);
		up(&comp_ctl->softabort_sem);
		return COMP_BUF_FULL;/* compress buffer full */
	}

	GD_PRINT_2(KERN_EMERG"FIND Empty Compress bufer  idx= %d\n", idx);

	/* down(osd_comp_sem) here */
	if ((comp_ctl->comp_sem == 0)) {
		up(&comp_ctl->softabort_sem);
		printk(KERN_EMERG"%s: 1 compress buffer full \n", __FUNCTION__);
		return COMP_BUF_FULL;/* compress buffer full */
	}
	comp_ctl->comp_sem--;/* Can't_USE_SEM+ */
	GD_PRINT_2(KERN_EMERG"D %d\n", comp_ctl->comp_sem);

	/* sCmpReceiveWork queue is equal to comp_ctl */
	work_idx = idx;
	if (sCmpReceiveWork[work_idx].used == 0)
		sCmpReceiveWork[work_idx].used = 1;
	else {
		up(&comp_ctl->softabort_sem);
		printk(KERN_EMERG"%s: compress buffer something wrong \n", __FUNCTION__);
		return COMP_BUF_WORK_FULL;/* compress buffer work full */
	}

	/* compress path */
	sCmpReceiveWork[work_idx].current_comp_idx = work_idx;

	ctlcmpwin = &comp_ctl->comp_win[work_idx];
	ctlcmpwin->buf_status = BUF_USED;

	/*  pointer to GDMA_PICTURE_OBJECT structure */
	if (com_picObj->fbdc_num > 0)
		picObj = &com_picObj->fbdc[0];
	else if (com_picObj->normal_num > 0)
		picObj = &com_picObj->normal[0];

	win = &sCmpReceiveWork[work_idx].comp_win;
	memset(&sCmpReceiveWork[work_idx].comp_win, 0x0, sizeof(COMP_WIN));

	if (picObj->seg_addr[1] == 0) {
		/*  use buffer which PLI creates */
		win->comp_done = NULL;
		win->seg_addr[0].alloc_virt_addr = ctlcmpwin->seg_addr[0].alloc_virt_addr;
		win->seg_addr[0].alloc_phy_16byte_addr = ctlcmpwin->seg_addr[0].alloc_phy_16byte_addr;
		win->seg_addr[1].alloc_virt_addr = ctlcmpwin->seg_addr[1].alloc_virt_addr;
		win->seg_addr[1].alloc_phy_16byte_addr = ctlcmpwin->seg_addr[1].alloc_phy_16byte_addr;
	} else {
		/*  for write-back function */
		/*  use buffer space from upper level */
		win->comp_done = (unsigned char *)picObj->seg_addr[0];
		win->seg_addr[0].alloc_virt_addr = (unsigned int)phys_to_virt(picObj->seg_addr[1]);
		win->seg_addr[0].alloc_phy_16byte_addr = picObj->seg_addr[1];
	}

	win->buf_status = BUF_USED;
	win->context = picObj->context;
	win->wbType = picObj->wbType;
	win->plane = picObj->plane;
	win->syncInfo = picObj->syncInfo;
	win->picLayout = picObj->picLayout;
	/*win->show = 1;*/  /*  always show the picture which want to do compress process */
	win->show = picObj->show;
	win->scale_factor = picObj->scale_factor;

	GD_PRINT_2(KERN_EMERG"%s win->plane=%d, picObj->comp_plane=%d\n", __FUNCTION__, win->plane, picObj->comp_plane);
	GD_PRINT_2(KERN_EMERG"%s win->wbType=%d\n", __FUNCTION__, win->wbType);

	for (layerIdx = 0; layerIdx < data->layer_num; layerIdx++) {
		com_picObj = &data->layer[layerIdx];

		/*  for normal win info. */
		for (iloop = 0; iloop < com_picObj->normal_num; iloop++) {
			picObj = &com_picObj->normal[iloop];
			if (picObj->layer_used) {
				GD_PRINT_2(KERN_EMERG"%s--%d Normal picObj->comp_plane=%d\n", __FUNCTION__, __LINE__, picObj->comp_plane);
				switch (picObj->comp_plane) {
				case VO_GRAPHIC_OSD1:
					win_tmp = &win->OSD1_WIN;
					break;
				case VO_GRAPHIC_OSD2:
					win_tmp = &win->OSD2_WIN;
					break;
				case VO_GRAPHIC_OSD3:
					win_tmp = &win->OSD3_WIN;
					break;
				case VO_GRAPHIC_OSD4:
					win_tmp = &win->OSD4_WIN;
					break;
				case VO_GRAPHIC_OSD5:
					win_tmp = &win->OSD5_WIN;
					break;
				default:
					break;
				}
				addr = dma_map_single(gdma->dev, (void *)(win_tmp), sizeof(OSD_WIN), DMA_TO_DEVICE);

				win_tmp->used = 1;
				win_tmp->nxtAddr.addr     = 0;
				win_tmp->nxtAddr.last     = 1;
				win_tmp->winXY.x          = 0;
				win_tmp->winXY.y          = 0;
				win_tmp->winWH.width      = picObj->width;
				win_tmp->winWH.height     = picObj->height;
				win_tmp->attr.extendMode  = 0;
				win_tmp->attr.rgbOrder    = VO_OSD_COLOR_RGB;
				win_tmp->attr.objType     = 0;
				win_tmp->attr.type        = picObj->format & 0x1f;
				win_tmp->attr.littleEndian = picObj->format >> 5;
				win_tmp->attr.alphaEn     = (win_tmp->attr.alpha   = picObj->alpha) >  0 ? 1 : 0;
				win_tmp->attr.compress     = picObj->decompress;
				win_tmp->colorKey.keyEn   = (picObj->colorkey != -1);
				win_tmp->colorKey.key     = picObj->colorkey;

				/*  address is physical address from upper layer */
				win_tmp->top_addr         = picObj->address + (gdma->ctrl.enableVFlip ? picObj->y + picObj->height - 1 : 0) * picObj->pitch;

				win_tmp->pitch            = picObj->pitch;
				win_tmp->objOffset.objXoffset = picObj->x;
				win_tmp->objOffset.objYoffset = gdma->ctrl.enableVFlip ? 0 : picObj->y;

				win_tmp->dst_x = picObj->dst_x;
				win_tmp->dst_y = picObj->dst_y;
				win_tmp->dst_width = picObj->dst_width;
				win_tmp->dst_height = picObj->dst_height;

				win_tmp->plane_ar.value = picObj->plane_ar.value;
				win_tmp->plane_gb.value = picObj->plane_gb.value;
				win_tmp->clear_x.value = picObj->clear_x.value;
				win_tmp->clear_y.value = picObj->clear_y.value;
				win_tmp->offlineOrder = picObj->offlineOrder;

				if (win_tmp->attr.type < 3)
					win_tmp->CLUT_addr = ((unsigned int) gdma->OSD_CLUT[picObj->paletteIndex]);

				dsb();
				dma_sync_single_for_device(gdma->dev, addr, sizeof(OSD_WIN), DMA_TO_DEVICE);
				dma_unmap_single(gdma->dev, addr, sizeof(OSD_WIN), DMA_TO_DEVICE);

				GD_PRINT_2(KERN_EMERG"%s-%d,[%d] w=%d,h=%d\n", __FUNCTION__, __LINE__, iloop, win_tmp->winWH.width, win_tmp->winWH.height);
				GD_PRINT_2(KERN_EMERG"win_tmp->attr.type=0x%x, alphaen=0x%x, KeyEn=0x%x, color=0x%x\n", win_tmp->attr.type, win_tmp->attr.alphaEn, win_tmp->colorKey.keyEn, win_tmp->colorKey.key);
				GD_PRINT_2(KERN_EMERG"source addr=0x%x, objXoffset=%d, objYoffset=%d\n", win_tmp->top_addr, win_tmp->objOffset.objXoffset, win_tmp->objOffset.objYoffset);
				GD_PRINT_2(KERN_EMERG"win_tmp->pitch=%d, destination info[%d,%d,%d,%d]\n", win_tmp->pitch, win_tmp->dst_x, win_tmp->dst_y, win_tmp->dst_width, win_tmp->dst_height);
			}
		}

		/*  for fbdc win info. */
		for (iloop = 0; iloop < com_picObj->fbdc_num; iloop++) {

			if (iloop < 3)
				picObj = &com_picObj->fbdc[iloop];
			else
				break;

			if (picObj->layer_used) {
				GD_PRINT_2(KERN_EMERG"%s--%d FBDC picObj->comp_plane=%d\n", __FUNCTION__, __LINE__, picObj->comp_plane);
				switch (picObj->comp_plane) {
				case VO_GRAPHIC_OSD1:
					win_tmp = &win->OSD1_WIN;
					break;
				case VO_GRAPHIC_OSD2:
					win_tmp = &win->OSD2_WIN;
					break;
				case VO_GRAPHIC_OSD3:
					win_tmp = &win->OSD3_WIN;
					break;
				case VO_GRAPHIC_OSD4:
					win_tmp = &win->OSD4_WIN;
					break;
				case VO_GRAPHIC_OSD5:
					win_tmp = &win->OSD5_WIN;
					break;
				default:
					break;
				}
				if (iloop != 0)
					if (com_picObj->fbdc[iloop].comp_plane != com_picObj->fbdc[iloop-1].comp_plane)
						printk(KERN_ERR"%s FBDC's comp_plane is NOT the same \n", __FUNCTION__);

				addr = dma_map_single(gdma->dev, (void *)(win_tmp), sizeof(OSD_WIN), DMA_TO_DEVICE);

				win_tmp->used = 1;
				win_tmp->nxtAddr.addr     = 0;
				win_tmp->nxtAddr.last     = 1;
				win_tmp->winXY.x          = 0;
				win_tmp->winXY.y          = 0;
				win_tmp->winWH.width      = ((picObj->width+picObj->dst_x) > win_tmp->winWH.width) ? (picObj->width+picObj->dst_x) : win_tmp->winWH.width;
				win_tmp->winWH.height     = ((picObj->height+picObj->dst_y) > win_tmp->winWH.height) ? (picObj->height+picObj->dst_y) : win_tmp->winWH.height;
				win_tmp->attr.extendMode  = 0;
				win_tmp->attr.rgbOrder    = VO_OSD_COLOR_RGB;
				win_tmp->attr.objType     = 0;
				win_tmp->attr.type        = VO_OSD_COLOR_FORMAT_ARGB8888 & 0x1f;
				win_tmp->attr.littleEndian = VO_OSD_COLOR_FORMAT_ARGB8888 >> 5;
				win_tmp->attr.alphaEn     = 0;
				win_tmp->attr.compress     = picObj->decompress;
				win_tmp->attr.IMGcompress   = 1;
				win_tmp->colorKey.keyEn   = (picObj->colorkey != -1);
				win_tmp->colorKey.key     = picObj->colorkey;

				win_tmp->pitch  = (picObj->pitch > win_tmp->pitch) ? picObj->pitch : win_tmp->pitch;
				win_tmp->objOffset.objXoffset = picObj->x;
				win_tmp->objOffset.objYoffset = gdma->ctrl.enableVFlip ? 0 : picObj->y;

				win_tmp->dst_x = 0;
				win_tmp->dst_y = 0;
				win_tmp->dst_width = (picObj->dst_width > win_tmp->dst_width) ? picObj->dst_width : win_tmp->dst_width;
				win_tmp->dst_height = (picObj->dst_height > win_tmp->dst_height) ? picObj->dst_height : win_tmp->dst_height;

				/*  fbdc's plane_alpha uses in pre-blend step */
				/*  Does NOT use the plane_alpha in the offline-blend */
				win_tmp->plane_ar.plane_alpha_r = 0xff;
				win_tmp->plane_ar.plane_alpha_a = 0xff;
				win_tmp->plane_gb.plane_alpha_g = 0xff;
				win_tmp->plane_gb.plane_alpha_b = 0xff;

				win_tmp->clear_x.value = picObj->clear_x.value;
				win_tmp->clear_y.value = picObj->clear_y.value;
				win_tmp->offlineOrder = picObj->offlineOrder;

				win_tmp->fbdc_attr.pre_blend_c0_sel = 1;
				win_tmp->fbdc_attr.pre_blend_c1_sel = 2;
				win_tmp->fbdc_attr.pre_blend_c2_sel = 3;

				if (win_tmp->attr.type < 3)
					win_tmp->CLUT_addr = ((unsigned int) gdma->OSD_CLUT[picObj->paletteIndex]);

				if (iloop == 0) {     /*  FBDC1 */
					win_tmp->fbdc1_addr = picObj->address + (gdma->ctrl.enableVFlip ? picObj->y + picObj->height - 1 : 0) * picObj->pitch;
					win_tmp->fbdc_attr.fbdc_1st_en = 1;
					win_tmp->fbdc_attr.const_a_1st = ((win_tmp->fbdc_attr.alpha_1st = picObj->alpha) > 0) ? 1 : 0;
					win_tmp->fbdc_attr.plane_alpha_c0 = (picObj->plane_ar.plane_alpha_a != 0xff || picObj->plane_ar.plane_alpha_r != 0xff ||
														 picObj->plane_gb.plane_alpha_g != 0xff || picObj->plane_gb.plane_alpha_b != 0xff) ? 1 : 0;
					win_tmp->fbdc_plane_alpha_c2.plane_alpha_a = (picObj->plane_ar.plane_alpha_a > 255) ? 255 : picObj->plane_ar.plane_alpha_a;
					win_tmp->fbdc_plane_alpha_c2.plane_alpha_r = (picObj->plane_ar.plane_alpha_r > 255) ? 255 : picObj->plane_ar.plane_alpha_r;
					win_tmp->fbdc_plane_alpha_c2.plane_alpha_g = (picObj->plane_gb.plane_alpha_g > 255) ? 255 : picObj->plane_gb.plane_alpha_g;
					win_tmp->fbdc_plane_alpha_c2.plane_alpha_b = (picObj->plane_gb.plane_alpha_b > 255) ? 255 : picObj->plane_gb.plane_alpha_b;
					/*win_tmp->fbdc_attr.pre_blend_c0_sel = 1;*/
					win_tmp->fbdc_format.fbdc_fmt_1st = picObj->fbdc_format;
					win_tmp->fbdc1_totaltile.x_total_tile = (picObj->width / 16);
					win_tmp->fbdc1_totaltile.y_total_tile = (picObj->height / 4);
					win_tmp->fbdc1_xy_pixel.x_pic_pixel = picObj->width;
					win_tmp->fbdc1_xy_pixel.y_pic_pixel = picObj->height;
					win_tmp->fbdc1_xy_sta.x_sta = picObj->x;
					win_tmp->fbdc1_xy_sta.y_sta = (gdma->ctrl.enableVFlip ? (picObj->height-1) : picObj->y);
					win_tmp->fbdc1_preblend_xy_sta.x_sta = picObj->dst_x/picObj->scale_factor;
					win_tmp->fbdc1_preblend_xy_sta.y_sta = picObj->dst_y/picObj->scale_factor;
				} else if (iloop == 1) { /*  FBDC2 */
					win_tmp->fbdc2_addr = picObj->address + (gdma->ctrl.enableVFlip ? picObj->y + picObj->height - 1 : 0) * picObj->pitch;
					win_tmp->fbdc_attr.pre_blend_en = 1;    /*  more than and equal to two fbdc layers */
					win_tmp->fbdc_attr.fbdc_2nd_en = 1;
					win_tmp->fbdc_attr.const_a_2nd = ((win_tmp->fbdc_attr.alpha_2nd = picObj->alpha) > 0) ? 1 : 0;
					win_tmp->fbdc_attr.plane_alpha_c1 = (picObj->plane_ar.plane_alpha_a != 0xff || picObj->plane_ar.plane_alpha_r != 0xff ||
														 picObj->plane_gb.plane_alpha_g != 0xff || picObj->plane_gb.plane_alpha_b != 0xff) ? 1 : 0;
					win_tmp->fbdc_plane_alpha_c1.plane_alpha_a = (picObj->plane_ar.plane_alpha_a > 255) ? 255 : picObj->plane_ar.plane_alpha_a;
					win_tmp->fbdc_plane_alpha_c1.plane_alpha_r = (picObj->plane_ar.plane_alpha_r > 255) ? 255 : picObj->plane_ar.plane_alpha_r;
					win_tmp->fbdc_plane_alpha_c1.plane_alpha_g = (picObj->plane_gb.plane_alpha_g > 255) ? 255 : picObj->plane_gb.plane_alpha_g;
					win_tmp->fbdc_plane_alpha_c1.plane_alpha_b = (picObj->plane_gb.plane_alpha_b > 255) ? 255 : picObj->plane_gb.plane_alpha_b;
					/*win_tmp->fbdc_attr.pre_blend_c1_sel = 2;*/
					win_tmp->fbdc_format.fbdc_fmt_2nd = picObj->fbdc_format;
					win_tmp->fbdc2_totaltile.x_total_tile = (picObj->width / 16);
					win_tmp->fbdc2_totaltile.y_total_tile = (picObj->height / 4);
					win_tmp->fbdc2_xy_pixel.x_pic_pixel = picObj->width;
					win_tmp->fbdc2_xy_pixel.y_pic_pixel = picObj->height;
					win_tmp->fbdc2_xy_sta.x_sta = picObj->x;
					win_tmp->fbdc2_xy_sta.y_sta = (gdma->ctrl.enableVFlip ? (picObj->height-1) : picObj->y);
					win_tmp->fbdc2_preblend_xy_sta.x_sta = picObj->dst_x/picObj->scale_factor;
					win_tmp->fbdc2_preblend_xy_sta.y_sta = picObj->dst_y/picObj->scale_factor;
				} else if (iloop == 2) { /*  FBDC3 */
					win_tmp->fbdc3_addr = picObj->address + (gdma->ctrl.enableVFlip ? picObj->y + picObj->height - 1 : 0) * picObj->pitch;
					win_tmp->fbdc_attr.fbdc_3rd_en = 1;
					win_tmp->fbdc_attr.const_a_3rd = ((win_tmp->fbdc_format.alpha_3rd = picObj->alpha) > 0) ? 1 : 0;
					win_tmp->fbdc_attr.plane_alpha_c2 = (picObj->plane_ar.plane_alpha_a != 0xff || picObj->plane_ar.plane_alpha_r != 0xff ||
														 picObj->plane_gb.plane_alpha_g != 0xff || picObj->plane_gb.plane_alpha_b != 0xff) ? 1 : 0;
					win_tmp->fbdc_plane_alpha_c1.plane_alpha_a = (picObj->plane_ar.plane_alpha_a > 255) ? 255 : picObj->plane_ar.plane_alpha_a;
					win_tmp->fbdc_plane_alpha_c1.plane_alpha_r = (picObj->plane_ar.plane_alpha_r > 255) ? 255 : picObj->plane_ar.plane_alpha_r;
					win_tmp->fbdc_plane_alpha_c1.plane_alpha_g = (picObj->plane_gb.plane_alpha_g > 255) ? 255 : picObj->plane_gb.plane_alpha_g;
					win_tmp->fbdc_plane_alpha_c1.plane_alpha_b = (picObj->plane_gb.plane_alpha_b > 255) ? 255 : picObj->plane_gb.plane_alpha_b;
					/*win_tmp->fbdc_attr.pre_blend_c2_sel = 3;*/
					win_tmp->fbdc_format.fbdc_fmt_3rd = picObj->fbdc_format;
					win_tmp->fbdc3_totaltile.x_total_tile = (picObj->width / 16);
					win_tmp->fbdc3_totaltile.y_total_tile = (picObj->height / 4);
					win_tmp->fbdc3_xy_pixel.x_pic_pixel = picObj->width;
					win_tmp->fbdc3_xy_pixel.y_pic_pixel = picObj->height;
					win_tmp->fbdc3_xy_sta.x_sta = picObj->x;
					win_tmp->fbdc3_xy_sta.y_sta = (gdma->ctrl.enableVFlip ? (picObj->height-1) : picObj->y);
					win_tmp->fbdc3_preblend_xy_sta.x_sta = picObj->dst_x/picObj->scale_factor;
					win_tmp->fbdc3_preblend_xy_sta.y_sta = picObj->dst_y/picObj->scale_factor;
				}

				/*  k blend factor */
				win_tmp->fbdc_blend1st.k1_blend = 0xc;
				win_tmp->fbdc_blend1st.k2_blend = 0x3;
				win_tmp->fbdc_blend1st.k3_blend = 0x2d;
				win_tmp->fbdc_blend1st.k4_blend = 0x3;
				win_tmp->fbdc_blend2nd.k1_blend = 0xc;
				win_tmp->fbdc_blend2nd.k2_blend = 0x3;
				win_tmp->fbdc_blend2nd.k3_blend = 0x2d;
				win_tmp->fbdc_blend2nd.k4_blend = 0x3;

				dsb();
				dma_sync_single_for_device(gdma->dev, addr, sizeof(OSD_WIN), DMA_TO_DEVICE);
				dma_unmap_single(gdma->dev, addr, sizeof(OSD_WIN), DMA_TO_DEVICE);

				GD_PRINT_2(KERN_EMERG"%s-%d,[%d] w=%d,h=%d\n", __FUNCTION__, __LINE__, iloop, win_tmp->winWH.width, win_tmp->winWH.height);
				GD_PRINT_2(KERN_EMERG"win_tmp->attr.type=%d, alphaen=%d, color=%d,color=%d\n", win_tmp->attr.type, win_tmp->attr.alphaEn, win_tmp->colorKey.keyEn, win_tmp->colorKey.key);
				GD_PRINT_2(KERN_EMERG"top_addr=0x%x, objXoffset=%d, objYoffset=%d\n", win_tmp->top_addr, win_tmp->objOffset.objXoffset, win_tmp->objOffset.objYoffset);
				GD_PRINT_2(KERN_EMERG"win_tmp->pitch=%d, [%d,%d,%d,%d]\n", win_tmp->pitch, win_tmp->dst_x, win_tmp->dst_y, win_tmp->dst_width, win_tmp->dst_height);
				GD_PRINT_2(KERN_EMERG"%s-%d,[%d] w=%d,h=%d\n", __FUNCTION__, __LINE__, iloop, win_tmp->winWH.width, win_tmp->winWH.height);
				GD_PRINT_2(KERN_EMERG"%s-%d, x=%d,y=%d,dst_width=%d,dst_height=%d\n", __FUNCTION__, __LINE__, win_tmp->dst_x, win_tmp->dst_y, win_tmp->dst_width, win_tmp->dst_height);
			}
		}
	}

	dsb();

	/* call osd_comp_receive_dequeue */
	queue_work(psCmpReceiveWorkQueue, &(sCmpReceiveWork[work_idx].CmpReceiveWork));

	up(&comp_ctl->softabort_sem);

	return GDMA_SUCCESS;
}

void osd_comp_receive_dequeue(struct work_struct *psWork)
{
	struct cmp_receive_work *ptr_work;
	int ret;

	down(&comp_ctl->dequeue_sem);
	/* note *ptr_work is global variable. */
	ptr_work = (struct cmp_receive_work *) psWork;

	GD_PRINT_2(KERN_EMERG"++ %s... \n", __FUNCTION__);

	ret = osd_comp_process(ptr_work);
	if (GDMA_SUCCESS != ret) {
		printk(KERN_ERR "%s osd_comp_process fail, ret=%d \n", __FUNCTION__, ret);

		/* release comp semaphore */
		comp_ctl->comp_sem++;

		/* release buffer */
		comp_ctl->comp_win[ptr_work->current_comp_idx].buf_status = BUF_EMPTY;
		sCmpReceiveWork[ptr_work->current_comp_idx].comp_win.buf_status = BUF_EMPTY;
		sCmpReceiveWork[ptr_work->current_comp_idx].used = 0;/* should in last line */
	}
	/* ptr_work->used = 0;//should in last line */

	up(&comp_ctl->dequeue_sem);

}

void osd_comp_init_module(void)
{
	int j = 0;
	/* just alloc one large memory, then divid it into small regions for osd compress */
	for (j = 0; j < MAX_COMP_BUFF; j++) {
#if 1   /*  use PLI function */
		comp_ctl->comp_win[j].seg_addr[0].alloc_virt_addr = (unsigned int)dvr_malloc_specific(comp_ctl->seg_size, GFP_DCU2/*GFP_DCU1*/);
		comp_ctl->comp_win[j].seg_addr[0].alloc_phy_16byte_addr = dvr_to_phys((void *)comp_ctl->comp_win[j].seg_addr[0].alloc_virt_addr);

		/* for 2 pixels mode */
		comp_ctl->comp_win[j].seg_addr[1].alloc_virt_addr = (unsigned int)dvr_malloc_specific(comp_ctl->seg_size, GFP_DCU2/*GFP_DCU1*/);
		comp_ctl->comp_win[j].seg_addr[1].alloc_phy_16byte_addr = dvr_to_phys((void *)comp_ctl->comp_win[j].seg_addr[1].alloc_virt_addr);
#else   /*  use kmalloc function */
		comp_ctl->comp_win[j].seg_addr[0].alloc_virt_addr = (unsigned int)kmalloc(comp_ctl->seg_size, GFP_KERNEL);
		comp_ctl->comp_win[j].seg_addr[0].alloc_phy_16byte_addr = virt_to_phys((void *)comp_ctl->comp_win[j].seg_addr[0].alloc_virt_addr);
#endif
		printk(KERN_EMERG"[OSD_COMP]:comp_ctl->comp_win[%d].seg_addr[0].alloc_virt_addr  = %x, alloc_phy_16byte_addr=%x\n", j, comp_ctl->comp_win[j].seg_addr[0].alloc_virt_addr, comp_ctl->comp_win[j].seg_addr[0].alloc_phy_16byte_addr);
		printk(KERN_EMERG"[OSD_COMP]:comp_ctl->comp_win[%d].seg_addr[1].alloc_virt_addr  = %x, alloc_phy_16byte_addr=%x\n", j, comp_ctl->comp_win[j].seg_addr[1].alloc_virt_addr, comp_ctl->comp_win[j].seg_addr[1].alloc_phy_16byte_addr);
	}

#ifdef _TEST_CODE_OSDCOMP_
	g_decompress_virt_buf_addr = (unsigned int)kmalloc(comp_ctl->seg_size, GFP_KERNEL);
	g_decompress_phy_buf_addr = virt_to_phys((void *)g_decompress_virt_buf_addr);
	printk(KERN_EMERG"[OSD_COMP]:g_decompress_virt_buf_addr=0x%x, g_decompress_phy_buf_addr=0x%x\n", g_decompress_virt_buf_addr, g_decompress_phy_buf_addr);
#endif

	GD_PRINT_2(KERN_EMERG"comp_ctl->compress_ratio = %d,  comp_ctl->seg_size = %d\n", comp_ctl->compress_ratio, comp_ctl->seg_size);

	/* Todo:reset flow */
	/* CLKEN=1 -> CLKEN=0 -> RSTN=0 -> RSTN=1 -> CLKEN=1 */

	osd_comp_init_module_status = COM_MOD_END;

}


int osd_comp_init_module_reg(void)
{
	cmp_setting_RBUS osdcomp_cmp_setting_reg;
	decmp1_setting_RBUS gdma_decmp_setting_reg;

	/* enable compress done interrupt */
	rtd_outl(GDMA_OSD_INTST_reg, ~1); /*  clear status */
	rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(0) | GDMA_OSD_INTEN_wdma_done(1));


	/* setting compress ratio */
	osdcomp_cmp_setting_reg.regValue = rtd_inl(GDMA_CMP_SETTING_reg);
	osdcomp_cmp_setting_reg.max_pixel_bits = 32;
	osdcomp_cmp_setting_reg.short_term_bits = (osdcomp_cmp_setting_reg.max_pixel_bits*DEFAULT_COMPRESS_RATIO)/100;
	osdcomp_cmp_setting_reg.frame_bits = (osdcomp_cmp_setting_reg.max_pixel_bits*DEFAULT_COMPRESS_RATIO)/100;
	osdcomp_cmp_setting_reg.cmp_a_ch_mark = 0;
	rtd_outl(GDMA_CMP_SETTING_reg, osdcomp_cmp_setting_reg.regValue);


	/* setting decompress */
	gdma_decmp_setting_reg.regValue = rtd_inl(GDMA_DECMP1_SETTING_reg);
	gdma_decmp_setting_reg.decmp_frame_bits = (osdcomp_cmp_setting_reg.max_pixel_bits*DEFAULT_COMPRESS_RATIO)/100;
	gdma_decmp_setting_reg.decmp_fl_mode = 1;
	rtd_outl(GDMA_DECMP1_SETTING_reg, gdma_decmp_setting_reg.regValue);
	rtd_outl(GDMA_DECMP2_SETTING_reg, gdma_decmp_setting_reg.regValue);

	/* setting compreoss resolution and segement num */
	rtd_outl(GDMA_CMP_RESOLUTION_reg,
			 GDMA_CMP_RESOLUTION_cmp_width((TWOK_W+31)>>5)|
			 GDMA_CMP_RESOLUTION_cmp_height(ONEK_H));

	/* set offline_blending enable & offline enable */
	/* rtd_outl(GDMA_OFFLINE_BLEND_reg, GDMA_OFFLINE_BLEND_offline_blend_en(1)); // data from mixer */
	/*rtd_outl(GDMA_ONLINE_reg, GDMA_ONLINE_set_osd3_offline(1) | GDMA_ONLINE_set_osd5_offline(1));*/

	comp_ctl->start_compress = 1;

	GD_PRINT_2(KERN_EMERG"GDMA_COMP_INTST_reg[0x%x]        0x%x\n", GDMA_COMP_INTST_reg, rtd_inl(GDMA_COMP_INTST_reg));
	GD_PRINT_2(KERN_EMERG"GDMA_OSD_INTST_reg[0x%x]        0x%x\n", GDMA_OSD_INTST_reg, rtd_inl(GDMA_OSD_INTST_reg));
	return 0;
}


void osd_comp_cleanup_module(void)
{
	int i;
	for (i = 0;  i < 1; i++) {
		if (comp_ctl->comp_win[i].seg_addr[i].alloc_virt_addr) {
			dvr_free((void *)comp_ctl->comp_win[i].seg_addr[i].alloc_virt_addr);
			comp_ctl->comp_win[i].seg_addr[i].alloc_virt_addr = (unsigned int)NULL;
			comp_ctl->comp_win[i].seg_addr[i].alloc_phy_16byte_addr = (unsigned int)NULL;
		}
	}
}



/** @brief this function would transfer PICTURE_LAYERS_OBJECT to COMPOSE_PICTURE_OBJECT each
*  @param data the content of structure is layers which wants to compress or blend
*  @return GDMA_SUCCESS or negative value
*/
int osd_comp_pre_receive_picture(PICTURE_LAYERS_OBJECT *data)
{
	int err = -50;

	if (data->layer_num > GDMA_LAYER_NUM || data->layer_num == 0) {
		printk(KERN_EMERG"%s, Error data->layer_num=%d\n", __FUNCTION__, data->layer_num);
		return -100;
	}

	GD_PRINT_2(KERN_EMERG"++ %s, data->layer_num=%d\n", __FUNCTION__, data->layer_num);

	err = osd_comp_receive_picture(data);
	if (err != GDMA_SUCCESS) {
		printk(KERN_EMERG"%s, osd_comp_receive_picture failed, err=%d \n", __FUNCTION__, err);
		return err;
	}

	return GDMA_SUCCESS;
}

/** @brief this function works for offline mode, output format could be RTK compress, ARGB8888, RGB888 type
*  @param data the content of structure is from upper level that wants to display
*  @return GDMA_SUCCESS or negative value
*/
int osd_comp_graphic_layers_wb_offline(GRAPHIC_LAYERS_OBJECT *data)
{
	int err = -50, loop = 0, layerIdx = 0;
	static PICTURE_LAYERS_OBJECT *picLayerObj;
	int fbdcNum = 0, normalNum = 0;
	int fbdcIdx = 0, normalIdx = 0;
	VO_GRAPHIC_PLANE offlinePlane = VO_GRAPHIC_OSD1;
	/* int ScaleRatio[GDMA_LAYER_NUM];     // MSB for height, LSB for width */
	int offlineOrder = 0;

	if (picLayerObj == NULL)
		picLayerObj = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (picLayerObj == NULL)
		return err;


	/*	switch online/offline */
	GDMA_SwitchOnlineOffline(1, 1);

	for (loop = 0; loop < data->layer_num; loop++) {
		if (data->layer[loop].src_type == SRC_NORMAL || data->layer[loop].src_type == SRC_MOUSE_NORMAL)
			normalNum++;

		if (data->layer[loop].src_type == SRC_FBDC || data->layer[loop].src_type == SRC_MOUSE_FBDC)
			fbdcNum++;
	}
	if (fbdcNum > 6)
		printk(KERN_ERR"%s FBDC layers exceeds 6 layers \n", __FUNCTION__);
	if (normalNum > 4)
		printk(KERN_ERR"%s Normal/Mouse layers exceeds 4 layers \n", __FUNCTION__);
	if ((fbdcNum > 0) && (normalNum > 1))
		printk(KERN_ERR"%s Too many layers \n", __FUNCTION__);
	if (data->wb_img_addr == 0)
		printk(KERN_ERR"%s Write-back address needs to set! \n", __FUNCTION__);


	memset(picLayerObj, 0, sizeof(PICTURE_LAYERS_OBJECT));

	for (loop = 0; loop < data->layer_num; loop++) {

		if (fbdcIdx > 2) {
			offlinePlane = (VO_GRAPHIC_PLANE)(offlinePlane + 1);
			if (offlinePlane == VO_GRAPHIC_OSD4)
				offlinePlane = (VO_GRAPHIC_PLANE)(offlinePlane + 1);

			fbdcIdx = 0;
			layerIdx++;
		}

		if (normalIdx > 0) {
			offlinePlane = (VO_GRAPHIC_PLANE)(offlinePlane + 1);
			if (offlinePlane == VO_GRAPHIC_OSD4)
				offlinePlane = (VO_GRAPHIC_PLANE)(offlinePlane + 1);
			normalIdx = 0;
			layerIdx++;
		}

		if (data->layer[loop].src_type == SRC_FBDC) {
			GDMA_CopyLayerInfo(&picLayerObj->layer[layerIdx].fbdc[fbdcIdx], &data->layer[loop]);
			picLayerObj->layer[layerIdx].fbdc[fbdcIdx].compressed = 1;
			picLayerObj->layer[layerIdx].fbdc[fbdcIdx].wbType = data->wbType;
			picLayerObj->layer[layerIdx].fbdc[fbdcIdx].comp_plane = offlinePlane;
			picLayerObj->layer[layerIdx].fbdc[fbdcIdx].offlineOrder = (E_BLEND_ORDER)offlineOrder;
			offlineOrder++;

			/*  write back function enable */
			picLayerObj->layer[layerIdx].fbdc[fbdcIdx].seg_addr[0] = (unsigned int)&data->comp_done;	/*  compress_done flag */
			picLayerObj->layer[layerIdx].fbdc[fbdcIdx].seg_addr[1] = data->wb_img_addr;	/*  osd comp write-back address */

			picLayerObj->layer[layerIdx].onlineOrder = (E_BLEND_ORDER)layerIdx;
			picLayerObj->layer[layerIdx].fbdc_num++;
			fbdcIdx++;
		}

		if (data->layer[loop].src_type == SRC_NORMAL) {
			GDMA_CopyLayerInfo(&picLayerObj->layer[layerIdx].normal[normalIdx], &data->layer[loop]);
			picLayerObj->layer[layerIdx].normal[normalIdx].compressed = 1;
			picLayerObj->layer[layerIdx].normal[normalIdx].wbType = data->wbType;
			picLayerObj->layer[layerIdx].normal[normalIdx].comp_plane = offlinePlane;
			picLayerObj->layer[layerIdx].normal[normalIdx].offlineOrder = (E_BLEND_ORDER)offlineOrder;
			offlineOrder++;

			/*  write back function enable */
			picLayerObj->layer[layerIdx].normal[normalIdx].seg_addr[0] = (unsigned int)&data->comp_done;	/*  compress_done flag */
			picLayerObj->layer[layerIdx].normal[normalIdx].seg_addr[1] = data->wb_img_addr;	/*  osd comp write-back address */

			picLayerObj->layer[layerIdx].onlineOrder = (E_BLEND_ORDER)layerIdx;
			picLayerObj->layer[layerIdx].normal_num++;
			normalIdx++;
		}

	}
	picLayerObj->layer_num = ++layerIdx;

	err = osd_comp_receive_picture(picLayerObj);
	return err;
}

/** @brief this function triggers a write-back data in online path, output format could be RTK compress, ARGB8888, RGB888 type
*  @param wb indicates write-back address & write-back type
*  @param protectFlag	check comp_ctl->dequeue_sem semaphore or not
*  @return GDMA_SUCCESS or negative value
*/
int osd_comp_graphic_layers_wb_online(ONLINE_WRRITEBACK_STRUCT *wb, int protectFlag)
{
	#define MIXER_WB_OSD1			1
	#define MIXER_WB_OSD2			2
	#define MIXER_WB_OSD3			3
	#define MIXER_WB_OSD4			4
	#define MIXER_WB_OSD5			5
	#define MIXER_WB_OSD6			6
	#define MIXER_WB_COUT			8
	#define MIXER_WB_CTMP1		9
	#define MIXER_WB_CTMP2		10
	#define MIXER_WB_CTMP3		11
	#define MIXER_WB_CTMP4		12
	online_RBUS online_reg;
	offline_blend_RBUS offline_blend_reg;
	cmp_setting_RBUS osdcomp_cmp_setting_reg;
	GDMA_PIC_DATA *curPic;
	int tryflag = 0, disPlane, finishCnt = 0, tmp;
	VO_RECTANGLE res;
	gdma_dev *gdma = &gdma_devices[0];
	int onlinePlane[GDMA_PLANE_MAXNUM] = {GDMA_PLANE_OSD1, GDMA_PLANE_OSD2, GDMA_PLANE_OSD3, GDMA_PLANE_OSD4, GDMA_PLANE_OSD5, GDMA_PLANE_OSD6, 0};
	int onlineIdx = 0;
	unsigned long timeout = jiffies + (HZ/25);		/* 40 ms */
	unsigned int prog_done_mask = GDMA_CTRL_osd_others_prog_done_mask | GDMA_CTRL_osd5_prog_done_mask |
										GDMA_CTRL_osd4_prog_done_mask | GDMA_CTRL_osd3_prog_done_mask |
										GDMA_CTRL_osd2_prog_done_mask | GDMA_CTRL_osd1_prog_done_mask;

	getDispSize(&res);

	/* clear finish flag */
	rtd_outl(GDMA_OSD_INTST_reg, GDMA_OSD_INTST_osd6_fin_mask |
											GDMA_OSD_INTST_osd5_fin_mask |
											GDMA_OSD_INTST_osd4_fin_mask |
											GDMA_OSD_INTST_osd3_fin_mask |
											GDMA_OSD_INTST_osd2_fin_mask |
											GDMA_OSD_INTST_osd1_fin_mask);

__ONLINE_WB__:
	GD_PRINT_2(KERN_EMERG"+++%s, wb->wbaddr=0x%x, wb->wbType=%d, protectFlag=%d \n", __FUNCTION__, wb->wbAddr, wb->wbType, protectFlag);
	GD_PRINT_2(KERN_EMERG"%s, WB_EN=0x%x, osd_status=0x%x \n", __FUNCTION__, rtd_inl(GDMA_WRITE_BACK_EN_reg), rtd_inl(GDMA_OSD_STATUS_reg));

	/* TODO: add a semaphore to separate between this function and osd_comp_receive_dequeue */
	if (protectFlag) {
		down(&comp_ctl->dequeue_sem);
		GDMA_ENTER_CRITICAL();
	}

	down(&gdma->sem_receive);
	/* drop uncompleted picture: cancel all work */
	for (onlineIdx = 0; onlineIdx < GDMA_MAX_PIC_Q_SIZE; onlineIdx++) {
		while (cancel_work_sync(&(sGdmaReceiveWork[onlineIdx].GdmaReceiveWork)) == true)
			printk("%s, Work idx:%d is pending...\n", __FUNCTION__, onlineIdx);

		sGdmaReceiveWork[onlineIdx].used = 0;
		gdma->pic[GDMA_PLANE_OSD1][onlineIdx].workqueueDone = 0;
		gdma->pic[GDMA_PLANE_OSD2][onlineIdx].workqueueDone = 0;
		gdma->pic[GDMA_PLANE_OSD3][onlineIdx].workqueueDone = 0;
		gdma->pic[GDMA_PLANE_OSD4][onlineIdx].workqueueDone = 0;
		gdma->pic[GDMA_PLANE_OSD5][onlineIdx].workqueueDone = 0;
		gdma->pic[GDMA_PLANE_OSD6][onlineIdx].workqueueDone = 0;
		gdma->pic[GDMA_PLANE_OSD1][onlineIdx].syncInfo.syncstamp = 0;
		gdma->pic[GDMA_PLANE_OSD2][onlineIdx].syncInfo.syncstamp = 0;
		gdma->pic[GDMA_PLANE_OSD3][onlineIdx].syncInfo.syncstamp = 0;
		gdma->pic[GDMA_PLANE_OSD4][onlineIdx].syncInfo.syncstamp = 0;
		gdma->pic[GDMA_PLANE_OSD5][onlineIdx].syncInfo.syncstamp = 0;
		gdma->pic[GDMA_PLANE_OSD6][onlineIdx].syncInfo.syncstamp = 0;
	}
	for (onlineIdx = 0; onlineIdx < GDMA_PLANE_MAXNUM; onlineIdx++) {
		disPlane = onlinePlane[onlineIdx];

		tmp = gdma->curPic[disPlane];
		while (tmp != gdma->picQwr[disPlane]) {
			tmp = ((tmp + 1) & (GDMA_MAX_PIC_Q_SIZE - 1));
			curPic = gdma->pic[disPlane] + tmp;
			if (curPic->isFromOffline == 1)
				osd_decomp_handler((GDMA_PIC_DATA *)curPic);
		}
		gdma->picQrd[disPlane] = gdma->curPic[disPlane] = gdma->picQwr[disPlane] = 0;
		gdma->ctrl.osdfirstEn[disPlane] = 0;
		gdma->ctrl.sync[disPlane] = 0;
		osdSyncStamp[onlineIdx] = 0;
		osdSyncStampTimeout[onlineIdx]= 0;
	}
	up(&gdma->sem_receive);


	/* check finish flag rising */
	if (GDMA_OSD1_CTRL_get_osd1_en(rtd_inl(GDMA_OSD1_CTRL_reg)))
		finishCnt++;
	if (GDMA_OSD2_CTRL_get_osd2_en(rtd_inl(GDMA_OSD2_CTRL_reg)))
		finishCnt++;
	if (GDMA_OSD3_CTRL_get_osd3_en(rtd_inl(GDMA_OSD3_CTRL_reg)))
		finishCnt++;
	if (GDMA_OSD4_CTRL_get_osd4_en(rtd_inl(GDMA_OSD4_CTRL_reg)))
		finishCnt++;
	if (GDMA_OSD5_CTRL_get_osd5_en(rtd_inl(GDMA_OSD5_CTRL_reg)))
		finishCnt++;
	GD_PRINT_2(KERN_EMERG"%s, finishCnt=%d \n", __FUNCTION__, finishCnt);

	timeout = jiffies + ((HZ/25)*3);
 	while (1) {
		tmp = 0;
		if (GDMA_OSD_INTST_get_osd1_fin(rtd_inl(GDMA_OSD_INTST_reg)))
			tmp++;
		if (GDMA_OSD_INTST_get_osd2_fin(rtd_inl(GDMA_OSD_INTST_reg)))
			tmp++;
		if (GDMA_OSD_INTST_get_osd3_fin(rtd_inl(GDMA_OSD_INTST_reg)))
			tmp++;
		if (GDMA_OSD_INTST_get_osd4_fin(rtd_inl(GDMA_OSD_INTST_reg)))
			tmp++;
		if (GDMA_OSD_INTST_get_osd5_fin(rtd_inl(GDMA_OSD_INTST_reg)))
			tmp++;

		if (tmp == finishCnt) {
			GD_PRINT_2(KERN_EMERG"%s, tmp == finishCnt \n", __FUNCTION__);
			break;
		}

		if (time_before(jiffies, timeout) == 0) {	/* over 40*3 ms */
			printk(KERN_EMERG"%s, TimeOut. finish NOT ready, finishCnt=%d, tmp=%d \n", __FUNCTION__, finishCnt, tmp);
			break;
		}
	}

	/* wait hw clear programming done */
	timeout = jiffies + (HZ/25);
 	while (rtd_inl(GDMA_CTRL_reg) & prog_done_mask) {
		if (time_before(jiffies, timeout) == 0) {	/* over 40 ms */
			printk(KERN_EMERG"%s,%d, TimeOut. prog_done NOT clear \n", __FUNCTION__, __LINE__);
			break;
		}
	}

	/*  switch the data from online path */
	offline_blend_reg.regValue = rtd_inl(GDMA_OFFLINE_BLEND_reg);
	offline_blend_reg.offline_blend_en = 0;
	rtd_outl(GDMA_OFFLINE_BLEND_reg, offline_blend_reg.regValue);

	/*  switch to online for write_back_src_sel */
	online_reg.regValue = rtd_inl(GDMA_ONLINE_reg);
	online_reg.write_back_src_sel = 0;  /*  online */
	rtd_outl(GDMA_ONLINE_reg, online_reg.regValue);

	/*  programming done */
	rtd_outl(GDMA_CTRL_reg, GDMA_CTRL_osd_others_prog_done(1) |
									GDMA_CTRL_write_data(1));

	/* wait hw clear programming done */
	timeout = jiffies + (HZ/25);
	while (rtd_inl(GDMA_CTRL_reg) & GDMA_CTRL_osd_others_prog_done(1)) {
		if (time_before(jiffies, timeout) == 0) {	/* over 40 ms */
			printk(KERN_EMERG"%s, TimeOut. osd_others prog done NOT clear \n", __FUNCTION__);
			break;
		}
	}


	/* setting compress ratio */
	osdcomp_cmp_setting_reg.regValue = rtd_inl(GDMA_CMP_SETTING_reg);
	osdcomp_cmp_setting_reg.max_pixel_bits = 32;
	osdcomp_cmp_setting_reg.short_term_bits = (osdcomp_cmp_setting_reg.max_pixel_bits*DEFAULT_COMPRESS_RATIO)/100;
	osdcomp_cmp_setting_reg.frame_bits = (osdcomp_cmp_setting_reg.max_pixel_bits*DEFAULT_COMPRESS_RATIO)/100;
	osdcomp_cmp_setting_reg.cmp_a_ch_mark = 0;
	rtd_outl(GDMA_CMP_SETTING_reg, osdcomp_cmp_setting_reg.regValue);

	/* setting compreoss resolution */
	rtd_outl(GDMA_CMP_RESOLUTION_reg, GDMA_CMP_RESOLUTION_cmp_width((res.width+31)>>5) |
												GDMA_CMP_RESOLUTION_cmp_height(res.height));

	/* write-back pitch */
	rtd_outl(GDMA_WRITE_BACK_reg, GDMA_WRITE_BACK_pitch(res.width * 4) |
											GDMA_WRITE_BACK_pitch_3d(res.width * 4));

	/* set write-back address */
	rtd_outl(GDMA_WDMA_ADR_SEG0_reg, wb->wbAddr);

	/*  write-back type */
	//rtd_outl(GDMA_WRITE_BACK_EN_reg, GDMA_WRITE_BACK_EN_write_back_format(wb->wbType) |
	//											GDMA_WRITE_BACK_EN_write_back_en(1));

	/* mixer writeback settings */
	rtd_outl(OSDOVL_Mixer_writeback_reg, OSDOVL_Mixer_writeback_writeback_sel(MIXER_WB_CTMP4) |
													OSDOVL_Mixer_writeback_writeback_en(1));
	rtd_outl(OSDOVL_Mixer_writeback_size_reg, OSDOVL_Mixer_writeback_size_width(res.width) |
														OSDOVL_Mixer_writeback_size_height(res.height));
	rtd_outl(OSDOVL_Mixer_writeback_position_reg, OSDOVL_Mixer_writeback_position_x(0) |
															OSDOVL_Mixer_writeback_position_y(0));

	/* write & wait mixer apply */
	rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, rtd_inl(OSDOVL_OSD_Db_Ctrl_reg) |
												OSDOVL_OSD_Db_Ctrl_db_load(1));

	/* wait mixer db_load */
	timeout = jiffies + (HZ/25);
	while (rtd_inl(OSDOVL_OSD_Db_Ctrl_reg) & OSDOVL_OSD_Db_Ctrl_db_load(1)) {
		if (time_before(jiffies, timeout) == 0) {	/* over 40 ms */
			printk(KERN_EMERG"%s, TimeOut. mixer db_load NOT clear \n", __FUNCTION__);
			break;
		}
	}


	/*  write-back type */
	rtd_outl(GDMA_WRITE_BACK_EN_reg, GDMA_WRITE_BACK_EN_write_back_format(wb->wbType) |
												GDMA_WRITE_BACK_EN_write_back_en(1));

	/*  programming done */
	rtd_outl(GDMA_CTRL_reg, GDMA_CTRL_osd_others_prog_done(1) |
									GDMA_CTRL_write_data(1));

	/* wait hw clear programming done */
	timeout = jiffies + (HZ/25);
	while (rtd_inl(GDMA_CTRL_reg) & GDMA_CTRL_osd_others_prog_done(1)) {
		if (time_before(jiffies, timeout) == 0) {	/* over 40 ms */
			printk(KERN_EMERG"%s,%d, TimeOut. osd_others prog done NOT clear \n", __FUNCTION__, __LINE__);
			break;
		}
	}


	/*  wait for write-back done */
	timeout = jiffies + ((HZ/25)*3);
	while (GDMA_OSD_INTST_get_wdma_done(rtd_inl(GDMA_OSD_INTST_reg))) {
		if (time_before(jiffies, timeout) == 0) {	/* over 40*3 ms */
			printk(KERN_EMERG"%s, TimeOut. write-back done NOT rising \n", __FUNCTION__);
			printk(KERN_EMERG"%s, 0x%x=0x%x \n", __FUNCTION__, GDMA_ONLINE_reg, rtd_inl(GDMA_ONLINE_reg));
			printk(KERN_EMERG"%s, 0x%x=0x%x \n", __FUNCTION__, GDMA_RESOURCE_LB_reg, rtd_inl(GDMA_RESOURCE_LB_reg));
			printk(KERN_EMERG"%s, 0x%x=0x%x \n", __FUNCTION__, GDMA_DMA_INTST_reg, rtd_inl(GDMA_DMA_INTST_reg));
			break;
		}
	}

	/*  wait for write-back en clear */
	timeout = jiffies + ((HZ/25)*3);
	while (GDMA_WRITE_BACK_EN_get_write_back_en(rtd_inl(GDMA_WRITE_BACK_EN_reg))) {
		if (time_before(jiffies, timeout) == 0) {	/* over 40*3 ms */
			printk(KERN_EMERG"%s, TimeOut. write-back en NOT clear \n", __FUNCTION__);
			break;
		}
	}

	/* error check */
	if (GDMA_DMA_INTST_get_wdma_ovfl(rtd_inl(GDMA_DMA_INTST_reg))) {
		printk(KERN_EMERG"%s, wdma overflow, try again...\n", __FUNCTION__);
		rtd_outl(GDMA_DMA_INTST_reg, GDMA_DMA_INTST_write_data(0) | GDMA_DMA_INTST_wdma_ovfl(1));
		tryflag = 1;
	}
	if (GDMA_DMA_INTST_get_wdma_udfl(rtd_inl(GDMA_DMA_INTST_reg))) {
		printk(KERN_EMERG"%s, wdma underflow, try again...\n", __FUNCTION__);
		rtd_outl(GDMA_DMA_INTST_reg, GDMA_DMA_INTST_write_data(0) | GDMA_DMA_INTST_wdma_udfl(1));
		tryflag = 1;
	}
	if (tryflag) {
		tryflag = 0;
		goto __ONLINE_WB__;
	}

	rtd_outl(GDMA_OSD_INTST_reg, GDMA_OSD_INTST_wdma_done_mask);
	GD_PRINT_2(KERN_EMERG"%s, write-back done \n", __FUNCTION__);

	/*  switch back to offline for write_back_src_sel */
	online_reg.regValue = rtd_inl(GDMA_ONLINE_reg);
	online_reg.write_back_src_sel = 1;  /*  offline */
	rtd_outl(GDMA_ONLINE_reg, online_reg.regValue);

	/* clear mixer write-back */
	rtd_outl(OSDOVL_Mixer_writeback_reg, 0);

	/*  other programming done & mixer apply */
	/* write & wait mixer apply */
	rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, rtd_inl(OSDOVL_OSD_Db_Ctrl_reg) |
												OSDOVL_OSD_Db_Ctrl_db_load(1));
	rtd_outl(GDMA_CTRL_reg, GDMA_CTRL_osd_others_prog_done(1) |
									GDMA_CTRL_write_data(1));

	/* wait hw clear programming done */
	timeout = jiffies + (HZ/25);
 	while (rtd_inl(GDMA_CTRL_reg) & GDMA_CTRL_osd_others_prog_done(1)) {
		if (time_before(jiffies, timeout) == 0) {	/* over 40 ms */
			printk(KERN_EMERG"%s,%d, TimeOut. osd_others prog done NOT clear \n", __FUNCTION__, __LINE__);
			break;
		}
	}
	timeout = jiffies + (HZ/25);
	while (rtd_inl(OSDOVL_OSD_Db_Ctrl_reg) & OSDOVL_OSD_Db_Ctrl_db_load(1)) {
		if (time_before(jiffies, timeout) == 0) {	/* over 40 ms */
			printk(KERN_EMERG"%s,%d, TimeOut. mixer db_load NOT clear \n", __FUNCTION__, __LINE__);
			break;
		}
	}


	if (protectFlag) {
		up(&comp_ctl->dequeue_sem);
		GDMA_EXIT_CRITICAL();
	}


	GD_PRINT_2(KERN_EMERG"---%s, write-back function return \n", __FUNCTION__);

	return GDMA_SUCCESS;
}


int osd_comp_receive_picture(PICTURE_LAYERS_OBJECT *data)
{
	int layerIdx;
	int first_layer = -1;
	GDMA_PICTURE_OBJECT *picObj = NULL;
	COMPOSE_PICTURE_OBJECT *com_picObj = &data->layer[0];
	int ret = GDMA_SUCCESS;

	if (com_picObj->fbdc_num > 0) {
		for (layerIdx = 0; layerIdx < com_picObj->fbdc_num; layerIdx++) {
			if (com_picObj->fbdc[layerIdx].layer_used == 1) {
				first_layer = layerIdx;
				break;
			}
		}
	} else if (com_picObj->normal_num > 0) {
		for (layerIdx = 0; layerIdx < com_picObj->normal_num; layerIdx++) {
			if (com_picObj->normal[layerIdx].layer_used == 1) {
				first_layer = layerIdx;
				break;
			}
		}
	}

	GD_PRINT_2(KERN_EMERG"%s com_picObj->fbdc_num=%d, com_picObj->normal_num=%d \n", __FUNCTION__, com_picObj->fbdc_num, com_picObj->normal_num);

	if (first_layer == -1)
		return COMP_PICOBJ_INFO_ERROR;
	else {
		if (com_picObj->fbdc_num > 0)
			picObj = &com_picObj->fbdc[first_layer];
		else if (com_picObj->normal_num > 0)
			picObj = &com_picObj->normal[first_layer];
	}

	GD_PRINT_2(KERN_EMERG"%s, first_layer=%d, comp_ctl->start_compress=%d\n", __FUNCTION__, first_layer, comp_ctl->start_compress);

	if (picObj->compressed == 1) {
		/* when use osd compression, we just enable it. */
		if (!comp_ctl->start_compress) {
			down(&comp_ctl->pli_sem);
			if (!osd_comp_work_queue())
				/*
				*   do OSD_COMP at first time
				*   Don't drop this picture, when syncstamp mechanism was used, another picture maybe wait the compressed picture
				*/
				;/* return COMP_PICOBJ_INFO_ERROR;*/
			if (comp_ctl->start_compress == 0)
				osd_comp_init_module_reg();
			up(&comp_ctl->pli_sem);
		}

		ret = osd_comp_receive_enqueue(data);
	} else {
		printk(KERN_EMERG"%s, warning for this layer is NOT compress layer \n", __FUNCTION__);
		return COMP_PICOBJ_INFO_ERROR;
	}

	return ret;
}


static int check_osdcomp_used(void)
{
	/* return 1: used, 0:avalible */
	/* fox modify for check osd_compress 2013/07/08 */
	if ((GDMA_OSD_INTST_get_wdma_done(rtd_inl(GDMA_OSD_INTST_reg)) == 1) ||
		(GDMA_CTRL_get_offline_go(rtd_inl(GDMA_CTRL_reg)) == 0))
		return 0;
	else
		return 1;
}

/** @brief set cX_sel & plane_alpha_en of offline_blend register
*  @param src indicate the HW OSD number
*  @param dest blend order
*  @param planeAlphaEn enable/disable the plane alpha
*  @return None
*/
static void osd_comp_offline_blend_set(GDMA_DISPLAY_PLANE src, E_BLEND_ORDER dest, int planeAlphaEn)
{
	offline_blend_RBUS offline_blend_reg;
	unsigned int cx_sel_old = 0, cx_sel_new = 0;

	offline_blend_reg.regValue = rtd_inl(GDMA_OFFLINE_BLEND_reg);

	GD_PRINT_2(KERN_EMERG"%s, src=%d, blend order=%d, planeAlphaEn=%d \n", __FUNCTION__, src, dest, planeAlphaEn);

	if (dest == C0) {
		cx_sel_old = offline_blend_reg.c0_sel;
		cx_sel_new = offline_blend_reg.c0_sel = src;
		offline_blend_reg.c0_plane_alpha_en = planeAlphaEn;
	} else if (dest == C1) {
		cx_sel_old = offline_blend_reg.c1_sel;
		cx_sel_new = offline_blend_reg.c1_sel = src;
		offline_blend_reg.c1_plane_alpha_en = planeAlphaEn;
	} else if (dest == C2) {
		cx_sel_old = offline_blend_reg.c2_sel;
		cx_sel_new = offline_blend_reg.c2_sel = src;
		offline_blend_reg.c2_plane_alpha_en = planeAlphaEn;
	} else if (dest == C3) {
		cx_sel_old = offline_blend_reg.c3_sel;
		cx_sel_new = offline_blend_reg.c3_sel = src;
		offline_blend_reg.c3_plane_alpha_en = planeAlphaEn;
	}

	/* conflict protect */
	if (offline_blend_reg.c0_sel == cx_sel_new && dest != C0)
		offline_blend_reg.c0_sel = cx_sel_old;
	else if (offline_blend_reg.c1_sel == cx_sel_new && dest != C1)
		offline_blend_reg.c1_sel = cx_sel_old;
	else if (offline_blend_reg.c2_sel == cx_sel_new && dest != C2)
		offline_blend_reg.c2_sel = cx_sel_old;
	else if (offline_blend_reg.c3_sel == cx_sel_new && dest != C3)
		offline_blend_reg.c3_sel = cx_sel_old;

	GD_PRINT_2(KERN_EMERG"%s, set offline_blend_reg=0x%x \n", __FUNCTION__, offline_blend_reg.regValue);

	rtd_outl(GDMA_OFFLINE_BLEND_reg, offline_blend_reg.regValue);
}





/** @brief compress or blend process that set related register and wait the done interrupt
*  @param ptr_work the pointer to workqueue structure which defines the layer information
*  @return GDMA_SUCCESS or negative value
*/
int osd_comp_process(struct cmp_receive_work *ptr_work)
{
	dma_addr_t addr;
	COMP_WIN *compwin = NULL;
	OSD_WIN *osdwin = NULL;
	wdma_crc_RBUS osdcomp_wdma_crc_reg;
	offline_blend_RBUS offline_blend_reg;
	gdma_dev *gdma = &gdma_devices[0];
	int comp_wait_max = 0;
	int iloop, clearRegion;
	resource_lb_RBUS resource_lb_reg;
	mid_blend_RBUS mid_blend_reg;
	line_buffer_end_RBUS line_buffer_end_reg;
#ifdef GDMA_DEBUG_HWC
	int idx;
#endif
	/* int planeAlpha[MAX_OSD_NUM]; */
	int canvasW = 0, canvasH = 0;
	unsigned int offset = 0;
	GDMA_DISPLAY_PLANE offPlane;

	/* HW available check */
	if (check_osdcomp_used()) {
		GD_PRINT_2(KERN_EMERG"C [0x%x]=0x%x\n", GDMA_OSD_INTST_reg, rtd_inl(GDMA_OSD_INTST_reg));
		GD_PRINT_2(KERN_EMERG"C [0x%x]=0x%x\n", GDMA_CTRL_reg, rtd_inl(GDMA_CTRL_reg));
		return COMP_HW_USED;
	}

	/* Can't_USE_SEM+ */
	if (comp_ctl->comp_process) {
		comp_ctl->comp_process--;
	} else {
		GD_PRINT_2(KERN_EMERG"OC \n");
		return COMP_HW_USED;
	}

	/*	switch online/offline */
	compwin = &ptr_work->comp_win;
	down(&gdma->sem_gfxreceive);	/* stopping picture enters if switching from online to offline */

	GDMA_ENTER_CRITICAL();
	GDMA_SwitchOnlineOffline(1, compwin->OSD1_WIN.used);

	/*
	sCmpReceiveWork[ptr_work->current_comp_idx].used = 0;
	comp_ctl->comp_win[ptr_work->current_comp_idx].buf_status = BUF_EMPTY;
	comp_ctl->comp_process++;
	comp_ctl->comp_sem++;
	up(&gdma->sem_gfxreceive);
	GDMA_EXIT_CRITICAL();
	return 0;
	*/

	/* change OSDSRx_switch_to to offline use */
	line_buffer_end_reg.regValue = rtd_inl(GDMA_LINE_BUFFER_END_reg);
	line_buffer_end_reg.osdsr3_switch_to = GDMA_PLANE_OSD4;
	line_buffer_end_reg.osdsr4_switch_to = GDMA_PLANE_OSD3;
	line_buffer_end_reg.osdsr5_switch_to = GDMA_PLANE_OSD5;
	rtd_outl(GDMA_LINE_BUFFER_END_reg, line_buffer_end_reg.regValue);

	/* do NOT go to mid-blend in default */
	resource_lb_reg.regValue = rtd_inl(GDMA_RESOURCE_LB_reg);
	resource_lb_reg.set_osd3_go_middle_blend = 0;
	resource_lb_reg.set_osd4_go_middle_blend = 0;
	resource_lb_reg.set_osd5_go_middle_blend = 0;
	rtd_outl(GDMA_RESOURCE_LB_reg, resource_lb_reg.regValue);

	/* disable mid-blend */
	mid_blend_reg.regValue = rtd_inl(GDMA_MID_BLEND_reg);
	mid_blend_reg.mid_blend_en = 0;
	rtd_outl(GDMA_MID_BLEND_reg, mid_blend_reg.regValue);

	/* point to comp wininfo */
	compwin = &ptr_work->comp_win;

	GD_PRINT_2(KERN_EMERG"%s ptr_work->current_comp_idx=%d \n", __FUNCTION__, ptr_work->current_comp_idx);

	if (compwin->buf_status == BUF_USED) {
		compwin->buf_status = BUF_COMPRESSING;

		/*  disable offline_blend enable */
		offline_blend_reg.regValue = rtd_inl(GDMA_OFFLINE_BLEND_reg);
		offline_blend_reg.offline_blend_en = 0;
		rtd_outl(GDMA_OFFLINE_BLEND_reg, offline_blend_reg.regValue);

		gActiveOffPlane = 0;
		/* update compress info to register */
		for (iloop = 0; iloop < MAX_OSD_NUM; iloop++) {

			if (iloop == 0 && compwin->OSD1_WIN.used == 1) {
				osdwin = &compwin->OSD1_WIN;
				offPlane = GDMA_PLANE_OSD1;
				gActiveOffPlane |= GDMA_CTRL_osd1_prog_done(1);
			} else if (iloop == 1 && compwin->OSD2_WIN.used == 1) {
				osdwin = &compwin->OSD2_WIN;
				offset = 0x100;
				offPlane = GDMA_PLANE_OSD2;
				gActiveOffPlane |= GDMA_CTRL_osd2_prog_done(1);
			} else if (iloop == 2 && compwin->OSD3_WIN.used == 1) {
				osdwin = &compwin->OSD3_WIN;
				offset = 0x200;
				offPlane = GDMA_PLANE_OSD3;
				gActiveOffPlane |= GDMA_CTRL_osd3_prog_done(1);
			} else if (iloop == 3 && compwin->OSD4_WIN.used == 1) {
				osdwin = &compwin->OSD4_WIN;
				offset = 0x300;
				offPlane = GDMA_PLANE_OSD4;
				gActiveOffPlane |= GDMA_CTRL_osd4_prog_done(1);
			} else if (iloop == 4 && compwin->OSD5_WIN.used == 1) {
				osdwin = &compwin->OSD5_WIN;
				offset = 0x400;
				offPlane = GDMA_PLANE_OSD5;
				gActiveOffPlane |= GDMA_CTRL_osd5_prog_done(1);
			} else
				continue;

			GD_PRINT_2(KERN_EMERG"%s, offline:offPlane=%d, online:compwin->plane=%d \n", __FUNCTION__, offPlane, compwin->plane);

			/*  TODO: register setting from COMP_WIN  & OSD_WIN */
			addr = dma_map_single(gdma->dev, (void *)(osdwin), sizeof(OSD_WIN), DMA_TO_DEVICE);
			clearRegion = (osdwin->clear_x.value != 0 && osdwin->clear_y.value != 0);

			rtd_outl(GDMA_OSD1_CTRL_reg+offset, GDMA_OSD1_CTRL_write_data(1) |
															 GDMA_OSD1_CTRL_osd1_en(1) |
															 GDMA_OSD1_CTRL_rotate(gdma->ctrl.enableVFlip));

			rtd_outl(GDMA_OSD1_reg+offset, GDMA_OSD1_write_data(1) |
													 GDMA_OSD1_clear_region_en(clearRegion));

			rtd_outl(GDMA_OSD1_WI_reg+offset, GDMA_OSD1_WI_addr (virt_to_phys(osdwin)));
			rtd_outl(GDMA_OSD1_SIZE_reg+offset, GDMA_OSD1_SIZE_w(osdwin->winWH.width) | GDMA_OSD1_SIZE_h(osdwin->winWH.height));

			/*  clear region */
			rtd_outl(GDMA_OSD1_CLEAR1_reg+offset, osdwin->clear_x.value);
			rtd_outl(GDMA_OSD1_CLEAR2_reg+offset, osdwin->clear_y.value);

			/*  offline blend order setting & offline plane alpha setting */
			/* planeAlpha[iloop] = (osdwin->plane_argb.value != 0xffffffff); */
			osd_comp_offline_blend_set(offPlane, osdwin->offlineOrder, (osdwin->plane_ar.plane_alpha_a != 0xff || osdwin->plane_ar.plane_alpha_r != 0xff ||
									   osdwin->plane_gb.plane_alpha_g != 0xff || osdwin->plane_gb.plane_alpha_b != 0xff));

			if (osdwin->offlineOrder == C0)
				rtd_outl(GDMA_OFFLINE_BLEND_C0_reg, GDMA_OFFLINE_BLEND_C0_plane_alpha_a(osdwin->plane_ar.plane_alpha_a) |
						 GDMA_OFFLINE_BLEND_C0_plane_alpha_r(osdwin->plane_ar.plane_alpha_r) |
						 GDMA_OFFLINE_BLEND_C0_plane_alpha_g(osdwin->plane_gb.plane_alpha_g) |
						 GDMA_OFFLINE_BLEND_C0_plane_alpha_b(osdwin->plane_gb.plane_alpha_b));
			else if (osdwin->offlineOrder == C1)
				rtd_outl(GDMA_OFFLINE_BLEND_C1_reg, GDMA_OFFLINE_BLEND_C1_plane_alpha_a(osdwin->plane_ar.plane_alpha_a) |
						 GDMA_OFFLINE_BLEND_C1_plane_alpha_r(osdwin->plane_ar.plane_alpha_r) |
						 GDMA_OFFLINE_BLEND_C1_plane_alpha_g(osdwin->plane_gb.plane_alpha_g) |
						 GDMA_OFFLINE_BLEND_C1_plane_alpha_b(osdwin->plane_gb.plane_alpha_b));
			else if (osdwin->offlineOrder == C2)
				rtd_outl(GDMA_OFFLINE_BLEND_C2_reg, GDMA_OFFLINE_BLEND_C2_plane_alpha_a(osdwin->plane_ar.plane_alpha_a) |
						 GDMA_OFFLINE_BLEND_C2_plane_alpha_r(osdwin->plane_ar.plane_alpha_r) |
						 GDMA_OFFLINE_BLEND_C2_plane_alpha_g(osdwin->plane_gb.plane_alpha_g) |
						 GDMA_OFFLINE_BLEND_C2_plane_alpha_b(osdwin->plane_gb.plane_alpha_b));
			else if (osdwin->offlineOrder == C3)
				rtd_outl(GDMA_OFFLINE_BLEND_C3_reg, GDMA_OFFLINE_BLEND_C3_plane_alpha_a(osdwin->plane_ar.plane_alpha_a) |
						 GDMA_OFFLINE_BLEND_C3_plane_alpha_r(osdwin->plane_ar.plane_alpha_r) |
						 GDMA_OFFLINE_BLEND_C3_plane_alpha_g(osdwin->plane_gb.plane_alpha_g) |
						 GDMA_OFFLINE_BLEND_C3_plane_alpha_b(osdwin->plane_gb.plane_alpha_b));

			dsb();
			dma_sync_single_for_device(gdma->dev, addr, sizeof(OSD_WIN), DMA_TO_DEVICE);
			dma_unmap_single(gdma->dev, addr, sizeof(OSD_WIN), DMA_TO_DEVICE);

			/*  calculate the canvas size by source size
			*/
			if (canvasW < ((osdwin->dst_x/compwin->scale_factor) + osdwin->winWH.width))
				canvasW = ((osdwin->dst_x/compwin->scale_factor) + osdwin->winWH.width);
			if (canvasH < ((osdwin->dst_y/compwin->scale_factor) + osdwin->winWH.height))
				canvasH = ((osdwin->dst_y/compwin->scale_factor) + osdwin->winWH.height);

			/* blend position */
			if (offPlane == GDMA_PLANE_OSD1)
				osd_sr_configLocation(GDMA_PLANE_OSD1, osdwin->dst_x/compwin->scale_factor, osdwin->dst_y/compwin->scale_factor);
			else if (offPlane == GDMA_PLANE_OSD2)
				osd_sr_configLocation(GDMA_PLANE_OSD2, osdwin->dst_x/compwin->scale_factor, osdwin->dst_y/compwin->scale_factor);
			else if (offPlane == GDMA_PLANE_OSD3)
				osd_sr_configLocation(GDMA_PLANE_OSD3, osdwin->dst_x/compwin->scale_factor, osdwin->dst_y/compwin->scale_factor);
			else if (offPlane == GDMA_PLANE_OSD4)
				osd_sr_configLocation(GDMA_PLANE_OSD4, osdwin->dst_x/compwin->scale_factor, osdwin->dst_y/compwin->scale_factor);
			else if (offPlane == GDMA_PLANE_OSD5)
				osd_sr_configLocation(GDMA_PLANE_OSD5, osdwin->dst_x/compwin->scale_factor, osdwin->dst_y/compwin->scale_factor);

#ifdef GDMA_DEBUG_HWC/* For DEBUG */
			printk(KERN_EMERG"%s, GDMA_CTRL_reg[0x%x]       0x%x\n", __FUNCTION__, GDMA_CTRL_reg, rtd_inl(GDMA_CTRL_reg));
			printk(KERN_EMERG"%s, GDMA_OSD%d_CTRL_reg[0x%x]       0x%x\n", __FUNCTION__, offPlane, GDMA_OSD1_CTRL_reg+offset, rtd_inl(GDMA_OSD1_CTRL_reg+offset));
			printk(KERN_EMERG"%s, GDMA_OSD%d_reg[0x%x]       0x%x\n", __FUNCTION__, offPlane, GDMA_OSD1_reg+offset, rtd_inl(GDMA_OSD1_reg+offset));
			printk(KERN_EMERG"%s, GDMA_OSD%d_WI_reg[0x%x]       0x%x\n", __FUNCTION__, offPlane, GDMA_OSD1_WI_reg+offset, rtd_inl(GDMA_OSD1_WI_reg+offset));
			printk(KERN_EMERG"%s, GDMA_OSD%d_SIZE_reg[0x%x]       0x%x\n", __FUNCTION__, offPlane, GDMA_OSD1_SIZE_reg+offset, rtd_inl(GDMA_OSD1_SIZE_reg+offset));
			printk(KERN_EMERG"%s, canvasW=%d, canvasH=%d \n", __FUNCTION__, canvasW, canvasH);
			printk(KERN_EMERG"%s, compress compwin=0x%x,phy=0x%x\n", __FUNCTION__, (unsigned int)osdwin, virt_to_phys(osdwin));
			for (idx = 0; idx < 30; idx++) {
				printk("%s, wininfo+0x%x=0x%x\n", __FUNCTION__, idx*4, *((unsigned int *)osdwin+idx));
			}
#endif

		}

		/*  offline_blend canvas size setting */
		rtd_outl(GDMA_OFF_BLEND_SIZE_reg, GDMA_OFF_BLEND_SIZE_w(canvasW) |
													GDMA_OFF_BLEND_SIZE_h(canvasH));

		/* non-RTK compress type would set pitch */
		if (compwin->wbType != RTKCOMPRESS)
			rtd_outl(GDMA_WRITE_BACK_reg, GDMA_WRITE_BACK_pitch(canvasW*4) |
													GDMA_WRITE_BACK_pitch_3d(canvasW*4));

		/*  offline_blend enable */
		offline_blend_reg.regValue = rtd_inl(GDMA_OFFLINE_BLEND_reg);
		offline_blend_reg.offline_blend_en = 1;
		rtd_outl(GDMA_OFFLINE_BLEND_reg, offline_blend_reg.regValue);

		/*  offline_blend factor */
		/*
		rtd_outl(GDMA_OFFLINE_BLEND_B1_reg, GDMA_OFFLINE_BLEND_B1_k1(0x0c) | GDMA_OFFLINE_BLEND_B1_k2(0x3F) |
				 GDMA_OFFLINE_BLEND_B1_k3(0x0c) | GDMA_OFFLINE_BLEND_B1_k4(0x3F));
		rtd_outl(GDMA_OFFLINE_BLEND_B2_reg, GDMA_OFFLINE_BLEND_B2_k1(0x0c) | GDMA_OFFLINE_BLEND_B2_k2(0x3F) |
				 GDMA_OFFLINE_BLEND_B2_k3(0x0c) | GDMA_OFFLINE_BLEND_B2_k4(0x3F));
		rtd_outl(GDMA_OFFLINE_BLEND_B3_reg, GDMA_OFFLINE_BLEND_B3_k1(0x0c) | GDMA_OFFLINE_BLEND_B3_k2(0x3F) |
				 GDMA_OFFLINE_BLEND_B3_k3(0x0c) | GDMA_OFFLINE_BLEND_B3_k4(0x3F));
		*/

		GD_PRINT_2(KERN_EMERG"before GDMA_WRITE_BACK_EN_reg[0x%x]        0x%x\n", GDMA_WRITE_BACK_EN_reg, rtd_inl(GDMA_WRITE_BACK_EN_reg));

		/*  write-back type & enable */
		rtd_outl(GDMA_WRITE_BACK_EN_reg, GDMA_WRITE_BACK_EN_write_back_format(compwin->wbType) | GDMA_WRITE_BACK_EN_write_back_en(1));


		/* for 2 pixel 2 segment RTK-compresss */
		if (globe_disp_pixel_mode == 1 && compwin->wbType == RTKCOMPRESS && canvasW == FOURK_W && canvasH == TWOK_H) {
		//if (globe_disp_pixel_mode == 1 && compwin->wbType == RTKCOMPRESS) {	// for testing
			rtd_outl(GDMA_CMP_RESOLUTION_reg, GDMA_CMP_RESOLUTION_cmp_segment(1) |
														GDMA_CMP_RESOLUTION_cmp_width(((canvasW*2)+31)>>5) |
														GDMA_CMP_RESOLUTION_cmp_height(canvasH/2));
			/* seg1 wdma address */
			rtd_outl(GDMA_WDMA_ADR_SEG1_reg, GDMA_WDMA_ADR_SEG1_addr(compwin->seg_addr[1].alloc_phy_16byte_addr));

			GD_PRINT_2(KERN_EMERG"2 segment compress: GDMA_CMP_RESOLUTION_reg=0x%x\n", rtd_inl(GDMA_CMP_RESOLUTION_reg));
		} else {
			/* setting compreoss resolution */
			rtd_outl(GDMA_CMP_RESOLUTION_reg, GDMA_CMP_RESOLUTION_cmp_width((canvasW+31)>>5) |
														GDMA_CMP_RESOLUTION_cmp_height(canvasH));
		}

		/*  wdma crc calculation */
		osdcomp_wdma_crc_reg.regValue = rtd_inl(GDMA_WDMA_CRC_reg);
		osdcomp_wdma_crc_reg.start = 1;
		rtd_outl(GDMA_WDMA_CRC_reg, osdcomp_wdma_crc_reg.regValue);

		/*  compress dstination address setting */
		rtd_outl(GDMA_WDMA_ADR_SEG0_reg, GDMA_WDMA_ADR_SEG0_addr(compwin->seg_addr[0].alloc_phy_16byte_addr));


#ifdef GDMA_DEBUG_HWC/* For DEBUG */
		printk(KERN_EMERG"GDMA_OFFLINE_BLEND_reg[0x%x]        0x%x\n", GDMA_OFFLINE_BLEND_reg, rtd_inl(GDMA_OFFLINE_BLEND_reg));
		printk(KERN_EMERG"GDMA_OFF_BLEND_SIZE_reg[0x%x]        0x%x\n", GDMA_OFF_BLEND_SIZE_reg, rtd_inl(GDMA_OFF_BLEND_SIZE_reg));
		printk("GDMA_OFFLINE_BLEND_C0_reg[0x%x]        0x%x\n", GDMA_OFFLINE_BLEND_C0_reg, rtd_inl(GDMA_OFFLINE_BLEND_C0_reg));
		printk("GDMA_OFFLINE_BLEND_C1_reg[0x%x]        0x%x\n", GDMA_OFFLINE_BLEND_C1_reg, rtd_inl(GDMA_OFFLINE_BLEND_C1_reg));
		printk("GDMA_OFFLINE_BLEND_C2_reg[0x%x]        0x%x\n", GDMA_OFFLINE_BLEND_C2_reg, rtd_inl(GDMA_OFFLINE_BLEND_C2_reg));
		printk("GDMA_OFFLINE_BLEND_C3_reg[0x%x]        0x%x\n", GDMA_OFFLINE_BLEND_C3_reg, rtd_inl(GDMA_OFFLINE_BLEND_C3_reg));
		printk("GDMA_OFFLINE_BLEND_B1_reg[0x%x]        0x%x\n", GDMA_OFFLINE_BLEND_B1_reg, rtd_inl(GDMA_OFFLINE_BLEND_B1_reg));
		printk("GDMA_OFFLINE_BLEND_B2_reg[0x%x]        0x%x\n", GDMA_OFFLINE_BLEND_B2_reg, rtd_inl(GDMA_OFFLINE_BLEND_B2_reg));
		printk("GDMA_OFFLINE_BLEND_B3_reg[0x%x]        0x%x\n", GDMA_OFFLINE_BLEND_B3_reg, rtd_inl(GDMA_OFFLINE_BLEND_B3_reg));
		printk(KERN_EMERG"GDMA_WRITE_BACK_EN_reg[0x%x]        0x%x\n", GDMA_WRITE_BACK_EN_reg, rtd_inl(GDMA_WRITE_BACK_EN_reg));
		printk("GDMA_CMP_RESOLUTION_reg[0x%x]        0x%x\n", GDMA_CMP_RESOLUTION_reg, rtd_inl(GDMA_CMP_RESOLUTION_reg));
		printk("GDMA_CMP_SETTING_reg[0x%x]        0x%x\n", GDMA_CMP_SETTING_reg, rtd_inl(GDMA_CMP_SETTING_reg));
		printk("GDMA_DECMP1_RESOLUTION_reg[0x%x]        0x%x\n", GDMA_DECMP1_RESOLUTION_reg, rtd_inl(GDMA_DECMP1_RESOLUTION_reg));
		printk("GDMA_DECMP1_SETTING_reg[0x%x]        0x%x\n", GDMA_DECMP1_SETTING_reg, rtd_inl(GDMA_DECMP1_SETTING_reg));
		printk("GDMA_DECMP2_RESOLUTION_reg[0x%x]        0x%x\n", GDMA_DECMP2_RESOLUTION_reg, rtd_inl(GDMA_DECMP2_RESOLUTION_reg));
		printk("GDMA_DECMP2_SETTING_reg[0x%x]        0x%x\n", GDMA_DECMP2_SETTING_reg, rtd_inl(GDMA_DECMP2_SETTING_reg));
		printk("GDMA_COMP_INTEN_reg[0x%x]        0x%x\n", GDMA_COMP_INTEN_reg, rtd_inl(GDMA_COMP_INTEN_reg));
		printk("GDMA_COMP_INTST_reg[0x%x]        0x%x\n", GDMA_COMP_INTST_reg, rtd_inl(GDMA_COMP_INTST_reg));
		printk("GDMA_OSD_INTEN_reg[0x%x]        0x%x\n", GDMA_OSD_INTEN_reg, rtd_inl(GDMA_OSD_INTEN_reg));
		printk("GDMA_OSD_INTST_reg[0x%x]        0x%x\n", GDMA_OSD_INTST_reg, rtd_inl(GDMA_OSD_INTST_reg));
		printk(KERN_EMERG"GDMA_WRITE_BACK_reg[0x%x]        0x%x\n", GDMA_WRITE_BACK_reg, rtd_inl(GDMA_WRITE_BACK_reg));
		printk("GDMA_WDMA_ADR_SEG0_reg[0x%x]        0x%x\n", GDMA_WDMA_ADR_SEG0_reg, rtd_inl(GDMA_WDMA_ADR_SEG0_reg));
		printk("GDMA_WDMA_ADR_SEG1_reg[0x%x]        0x%x\n", GDMA_WDMA_ADR_SEG1_reg, rtd_inl(GDMA_WDMA_ADR_SEG1_reg));
#endif


		/*  if 3D settig compress dst address and enable d3_mode */
		/*  magellan2 does NOT support d3_mode to output two frame simultaneously */
		/*
		*(volatile u32*)GET_MAPPED_RBUS_ADDR(OSDCOMP_WDMA_ADR_SEG0_3D_reg) = OSDCOMP_WDMA_ADR_SEG0_3D_a(win3D->seg_addr[0].alloc_phy_16byte_addr);
		*/

		/* calculate the line buffer */
		GDMA_LineBufferCal();

		dsb();

		GD_PRINT_2(KERN_EMERG"go\n");

		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(1) | GDMA_OSD_INTEN_wdma_done(1));
		rtd_outl(GDMA_COMP_INTEN_reg, 3);
		rtd_outl(GDMA_CTRL_reg, GDMA_CTRL_write_data(1) |
										GDMA_CTRL_osd_others_prog_done(1) |
										GDMA_CTRL_offline_go(1));

		GDMA_EXIT_CRITICAL();

#ifdef GDMA_DEBUG_HWC
		printk("After go bit GDMA_OSD_INTEN_reg[0x%x] = 0x%x\n", GDMA_OSD_INTEN_reg, rtd_inl(GDMA_OSD_INTEN_reg));
		printk("After go bit GDMA_OSD_INTST_reg[0x%x] = 0x%x\n", GDMA_OSD_INTST_reg, rtd_inl(GDMA_OSD_INTST_reg));
		printk("After go bit GDMA_COMP_INTEN_reg[0x%x] = 0x%x\n", GDMA_COMP_INTEN_reg, rtd_inl(GDMA_COMP_INTEN_reg));
		printk("After go bit GDMA_COMP_INTST_reg[0x%x] = 0x%x\n", GDMA_COMP_INTST_reg, rtd_inl(GDMA_COMP_INTST_reg));
		printk("After go bit GDMA_DECOMP_INTEN_reg[0x%x] = 0x%x\n", GDMA_DECOMP_INTEN_reg, rtd_inl(GDMA_DECOMP_INTEN_reg));
		printk("After go bit GDMA_DECOMP_INTST_reg[0x%x] = 0x%x\n", GDMA_DECOMP_INTST_reg, rtd_inl(GDMA_DECOMP_INTST_reg));
		printk("After GDMA_CTRL_reg[0x%x]        0x%x\n", GDMA_CTRL_reg, rtd_inl(GDMA_CTRL_reg));
#endif
	} else {
		printk(KERN_ERR"%s, Error! No compress data in OSDCOMP WorkQueue \n", __FUNCTION__);
		comp_ctl->comp_process++;/* Can't_USE_SEM+ */
		up(&gdma->sem_gfxreceive);
		return GDMA_FAIL;
	}

	/*  waiting for wdma done */
	while (down_timeout(&comp_ctl->compress_sem, msecs_to_jiffies(1000)) != 0) {
		if (comp_wait_max++ >= COMP_MAX_WAIT_TIME) {
			printk(KERN_ERR "%s-%d comp not ready \n", __FUNCTION__, __LINE__);
		}
	}


	/*  clear INT flag & disable Interrupt */
	rtd_outl(GDMA_OSD_INTST_reg, GDMA_OSD_INTST_write_data(0) | GDMA_OSD_INTST_wdma_done(1));
	rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(0) | GDMA_OSD_INTEN_wdma_done(1));
	rtd_outl(GDMA_COMP_INTEN_reg, 0);

	/*  disable offline_blend enable */
	offline_blend_reg.regValue = rtd_inl(GDMA_OFFLINE_BLEND_reg);
	offline_blend_reg.offline_blend_en = 0;
	rtd_outl(GDMA_OFFLINE_BLEND_reg, offline_blend_reg.regValue);

	dsb();

	if (compwin->comp_done == NULL) {
		/*  compress done, then send to gdma picture queue */
		osd_comp_send_gdma(ptr_work);
	} else {
		/*  for write-back function */
		*(compwin->comp_done) = 1;
	}

	comp_ctl->comp_process++;/* Can't_USE_SEM+ */
	up(&gdma->sem_gfxreceive);

	return GDMA_SUCCESS;
}


/** @brief compressed or blending picture would send to GDMA workqueue
*  @param ptr_work the pointer to workqueue structure which defines the layer information
*  @return GDMA_SUCCESS
*/
int osd_comp_send_gdma(struct cmp_receive_work *ptr_work)
{
	int iloop, dst_x = 0xFFFF, dst_y = 0xFFFF, validflag = 0;
	unsigned int dst_width = 0, dst_height = 0;
	unsigned int canvasW = 0, canvasH = 0;
	COMP_BUFF_IDX comp_idx = ptr_work->current_comp_idx;
	GDMA_PICTURE_OBJECT *picObj = NULL;
	static PICTURE_LAYERS_OBJECT *picLayerObj;
	OSD_WIN *osdwin = NULL;
	COMP_WIN *compwin = &ptr_work->comp_win;
	osd_planealpha_ar planealpha_ar;
	osd_planealpha_gb planealpha_gb;
	int ret = GDMA_SUCCESS, gdma_ret = GDMA_SUCCESS;

	if (picLayerObj == NULL)
		picLayerObj = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (picLayerObj == NULL)
		return COMP_ALLOC_NOT_READY;

	/*  clear picLayerObj */
	memset((void *)picLayerObj, 0, sizeof(PICTURE_LAYERS_OBJECT));

	/*  get the final width & height from GDMA_OFF_BLEND_SIZE_reg */
	canvasW = GDMA_OFF_BLEND_SIZE_get_w(rtd_inl(GDMA_OFF_BLEND_SIZE_reg));
	canvasH = GDMA_OFF_BLEND_SIZE_get_h(rtd_inl(GDMA_OFF_BLEND_SIZE_reg));

	GD_PRINT_2(KERN_EMERG"h\n");
	GD_PRINT_2(KERN_EMERG"%s, comp_idx=%d \n", __FUNCTION__, comp_idx);

	comp_ctl->comp_win[comp_idx].buf_status = BUF_READY2DISPLAY;
	ptr_work->comp_win.buf_status = BUF_READY2DISPLAY;

	picLayerObj->layer_num = 1;
	picLayerObj->layer[0].normal_num = 1;
	picLayerObj->layer[0].onlineOrder = C0;
	picObj = &picLayerObj->layer[0].normal[0];
	picObj->current_comp_idx  = comp_idx;

	/* calculate new dst_x/y */
	for (iloop = 0; iloop < MAX_OSD_NUM; iloop++) {

		if (iloop == 0 && compwin->OSD1_WIN.used == 1) {
			osdwin = &compwin->OSD1_WIN;
			validflag = 1;
		} else if (iloop == 1 && compwin->OSD2_WIN.used == 1) {
			osdwin = &compwin->OSD2_WIN;
			validflag = 1;
		} else if (iloop == 2 && compwin->OSD3_WIN.used == 1) {
			osdwin = &compwin->OSD3_WIN;
			validflag = 1;
		} else if (iloop == 3 && compwin->OSD4_WIN.used == 1) {
			osdwin = &compwin->OSD4_WIN;
			validflag = 1;
		} else if (iloop == 4 && compwin->OSD5_WIN.used == 1) {
			osdwin = &compwin->OSD5_WIN;
			validflag = 1;
		} else
			continue;

		GD_PRINT_2(KERN_EMERG"%s, iloop=%d \n", __FUNCTION__, iloop);

		if (dst_width < osdwin->dst_width)
			dst_width = osdwin->dst_width;
		if (dst_height < osdwin->dst_height)
			dst_height = osdwin->dst_height;

		/* find the top-left position */
		if (osdwin->dst_x < dst_x)
			dst_x = osdwin->dst_x;
		if (osdwin->dst_y < dst_y)
			dst_y = osdwin->dst_y;
	}

	/* default plane alpha */
	planealpha_ar.plane_alpha_r = 0xff;
	planealpha_ar.plane_alpha_a = 0xff;
	planealpha_gb.plane_alpha_b = 0xff;
	planealpha_gb.plane_alpha_g = 0xff;

	/* destination w/h */
	if (canvasW > dst_width)
		dst_width = canvasW;
	if (canvasH > dst_height)
		dst_height = canvasH;


	if (validflag) {

		picObj->address = compwin->seg_addr[0].alloc_phy_16byte_addr;
		/*picObj->alpha = osdwin->attr.alpha;*/
		picObj->alpha = 0x00;
		/* picObj->clear_x = ; */
		/* picObj->clear_y = ; */
		picObj->colorkey = -1;
		/* picObj->compressed */
		/* picObj->comp_plane */
		picObj->context = compwin->context;
		if (compwin->wbType == RTKCOMPRESS)
			picObj->decompress = 1;
		else
			picObj->decompress = 0;
		picObj->dst_height = dst_height;
		picObj->dst_width = dst_width;
		picObj->dst_x = 0;//dst_x;
		picObj->dst_y = 0;//dst_y;

		GD_PRINT_2(KERN_EMERG"%s, destination=[%d,%d,%d,%d] \n", __FUNCTION__, picObj->dst_x, picObj->dst_y, picObj->dst_width, picObj->dst_height);

		if (compwin->wbType == RTKCOMPRESS || compwin->wbType == ARGB8888)
			picObj->format = ((VO_OSD_COLOR_FORMAT_ARGB8888) | (osdwin->attr.littleEndian<<5));
		else if (compwin->wbType == RBG888)
			picObj->format = ((VO_OSD_COLOR_FORMAT_RGB888) | (osdwin->attr.littleEndian<<5));
		picObj->height = canvasH;
		picObj->key_en = 0;
		picObj->layer_used = 1;
		/* picObj->offlineOrder */
		/* picObj->paletteIndex = ; */
		picObj->picLayout = compwin->picLayout;
		picObj->pitch = canvasW*4;

		picObj->plane = compwin->plane;
		if (compwin->wbType == RTKCOMPRESS) {
			/*
			*	only OSD4/5 support de-compress function if using RTKcompress
			*	force to OSD4 to display if using RTK compress
			*/
			if (picObj->plane != VO_GRAPHIC_OSD4 && picObj->plane != VO_GRAPHIC_OSD5)
				picObj->plane = VO_GRAPHIC_OSD4;
			/*picObj->plane = VO_GRAPHIC_OSD5;*/
		}
		picObj->plane_ar = planealpha_ar;
		picObj->plane_gb = planealpha_gb;
		picObj->seg_addr[0] = compwin->seg_addr[0].alloc_phy_16byte_addr;
		picObj->seg_addr[1] = compwin->seg_addr[1].alloc_phy_16byte_addr;
		picObj->seg_num = ONE_PIXEL_SEG;
		picObj->show = compwin->show;
		picObj->src_type = SRC_NORMAL;
		picObj->syncInfo = compwin->syncInfo;
		/* picObj->wbType */
		picObj->width = canvasW;
		picObj->x = 0;
		picObj->y = 0;
		picObj->isFromOffline = 1;
		picObj->scale_factor = compwin->scale_factor;

	} else {
		printk(KERN_ERR"%s, Error! OSD_COMP workqueue has something wrong! \n", __FUNCTION__);
		ret = COMP_PICOBJ_INFO_ERROR;
	}

	comp_ctl->comp_win[comp_idx].buf_status = BUF_READY2DISPLAY;
	ptr_work->comp_win.buf_status = BUF_READY2DISPLAY;

	if (validflag)
		gdma_ret = GDMA_ReceivePicture(picLayerObj);

	if (gdma_ret != GDMA_SUCCESS) {
		/* not going to GDMA work queue */
		printk(KERN_EMERG"%s, call GDMA_ReceivePicture failed \n", __FUNCTION__);
		comp_ctl->comp_win[comp_idx].buf_status = BUF_EMPTY;
		sCmpReceiveWork[comp_idx].comp_win.buf_status = BUF_EMPTY;
		sCmpReceiveWork[comp_idx].used = 0;/* should in last line */
	}

	comp_ctl->comp_sem++;

	return ret;
}


/** @brief this function handle about OSD_COMP, called from GDMA_irq_handler
*  @param None
*  @return None
*/
int osd_comp_handler(int compress_done, int compress_int)
{
	offline_blend_RBUS offline_blend_reg;

	/*  Not OSD compression INT */
	if (compress_int == 0 || compress_done == 0)
		return COMP_INT_NOT_READY;

	GD_PRINT_2(KERN_EMERG"%s, GDMA_OSD_INTEN_reg=0x%x, GDMA_OSD_INTST_reg=0x%x \n", __FUNCTION__, rtd_inl(GDMA_OSD_INTEN_reg), rtd_inl(GDMA_OSD_INTST_reg));

	if (compress_done) {
		GD_PRINT_2(KERN_EMERG"%s, compress done \n", __FUNCTION__);
		rtd_outl(GDMA_OSD_INTST_reg, GDMA_OSD_INTST_write_data(0) | GDMA_OSD_INTST_wdma_done(1));
		rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(0) | GDMA_OSD_INTEN_wdma_done(1));
		rtd_outl(GDMA_COMP_INTEN_reg, 0);

		/*  clear offline OSD ctrl register */
		if (gActiveOffPlane & GDMA_CTRL_osd1_prog_done(1)) {
			rtd_outl(GDMA_OSD1_CTRL_reg, ~1);
			/*
			* workaround for mantis 0074577:
			* [Merlin][Mag2][GDMA] when OSD offline¡Aosd_disable bit is NOT work
			* osdx_size_h set to zero that can workaround this issue
			*/
			rtd_outl(GDMA_OSD1_SIZE_reg, 0);
		}
		if (gActiveOffPlane & GDMA_CTRL_osd2_prog_done(1)) {
			rtd_outl(GDMA_OSD2_CTRL_reg, ~1);
			rtd_outl(GDMA_OSD2_SIZE_reg, 0);
		}
		if (gActiveOffPlane & GDMA_CTRL_osd3_prog_done(1)) {
			rtd_outl(GDMA_OSD3_CTRL_reg, ~1);
			rtd_outl(GDMA_OSD3_SIZE_reg, 0);
		}
		if (gActiveOffPlane & GDMA_CTRL_osd4_prog_done(1)) {
			rtd_outl(GDMA_OSD4_CTRL_reg, ~1);
			rtd_outl(GDMA_OSD4_SIZE_reg, 0);
		}
		if (gActiveOffPlane & GDMA_CTRL_osd5_prog_done(1)) {
			rtd_outl(GDMA_OSD5_CTRL_reg, ~1);
			rtd_outl(GDMA_OSD5_SIZE_reg, 0);
		}

		/* clear write-back en */
		rtd_outl(GDMA_WRITE_BACK_EN_reg, rtd_inl(GDMA_WRITE_BACK_EN_reg)&~GDMA_WRITE_BACK_EN_write_back_en_mask);

		/*  disable offline_blend enable */
		offline_blend_reg.regValue = rtd_inl(GDMA_OFFLINE_BLEND_reg);
		offline_blend_reg.offline_blend_en = 0;
		rtd_outl(GDMA_OFFLINE_BLEND_reg, offline_blend_reg.regValue);

		GD_PRINT_2(KERN_EMERG"%s, gActiveOffPlane = 0x%x \n", __FUNCTION__, gActiveOffPlane);
		/* clear gActiveOffPlane */
		gActiveOffPlane = 0;

		/* unlock compress lock */
		up(&comp_ctl->compress_sem);
		return GDMA_SUCCESS;
	}

	if (GDMA_DMA_INTST_get_wdma_ovfl(rtd_inl(GDMA_DMA_INTST_reg))) {
		printk(KERN_EMERG"GDMA: wdma overflow\n");
		rtd_outl(GDMA_DMA_INTST_reg, GDMA_DMA_INTST_write_data(0) | GDMA_DMA_INTST_wdma_ovfl(1));
	}

	if (GDMA_DMA_INTST_get_wdma_udfl(rtd_inl(GDMA_DMA_INTST_reg))) {
		printk(KERN_EMERG"GDMA: wdma underflow\n");
		rtd_outl(GDMA_DMA_INTST_reg, GDMA_DMA_INTST_write_data(0) | GDMA_DMA_INTST_wdma_udfl(1));
	}

	if (GDMA_DMA_INTST_get_wdma_acc_sync(rtd_inl(GDMA_DMA_INTST_reg))) {
		printk(KERN_EMERG"GDMA: wdma accident\n");
		rtd_outl(GDMA_DMA_INTST_reg, GDMA_DMA_INTST_write_data(0) | GDMA_DMA_INTST_wdma_acc_sync(1));
	}

	return COMP_INT_NOT_READY;

}

/*
* osd_decomp_handler been called by GDMA_irq_handler
*/
void osd_decomp_handler(GDMA_PIC_DATA *curPic)
{
	/* this is called from GDMA_irq_handler
	*   one buffer displayed
	*
	*   check if the other buffer is ready_disp
	*   if yes and
	*          - mark previous buffer as not_ready_disp (when it is compressed buffer)
	*          - up(osd_comp_sem) (when it is a compressed buffer)
	*   if no  - do nothing
	*/
	int i;

	if ((curPic->seg_num == ONE_PIXEL_SEG) /*&& (win->attr.compress == 1)*/) {
		GD_PRINT_2(KERN_EMERG"%s, curPic->current_comp_idx=%d \n", __FUNCTION__, curPic->current_comp_idx);
		GD_PRINT_2(KERN_EMERG"%s, curPic->seg_num=%d, curPic->OSDwin.attr.compress=%d\n", __FUNCTION__, curPic->seg_num, curPic->OSDwin.attr.compress);
		if(curPic->current_comp_idx < COMP_BUFF0 || curPic->current_comp_idx > COMP_BUFF2)
			GD_PRINT_2(KERN_EMERG"%s, curPic->current_comp_idx=%d  out of bounder!!, skip! \n", __FUNCTION__, curPic->current_comp_idx);
			return;

		if (comp_ctl->comp_win[curPic->current_comp_idx].buf_status == BUF_READY2DISPLAY) {
			comp_ctl->comp_win[curPic->current_comp_idx].buf_status = BUF_DISPLAYING;
			for (i = 0; i < MAX_COMP_BUFF; i++) {
				if (i != curPic->current_comp_idx && comp_ctl->comp_win[i].buf_status == BUF_DISPLAYING) {
					/* printk("curPic->current_comp_idx=%d i=%d\n",curPic->current_comp_idx,i); */
					comp_ctl->comp_win[i].buf_status = BUF_EMPTY;
					sCmpReceiveWork[i].comp_win.buf_status = BUF_EMPTY;
					sCmpReceiveWork[i].used = 0;/* should in last line */
					break;
				}
			}

			/* comp_ctl->comp_sem++;   //Can't_USE_SEM+ */
			/* printk("U %d, %d\n",comp_ctl->comp_sem,__LINE__); */
		}
		GD_PRINT_2(KERN_EMERG"osd_decomp_handler end\n");
	}
}


void osd_comp_softwareAbort(void)
{
	int idx = 0;
	online_RBUS online_reg;
	update_RBUS update_reg;

	down(&comp_ctl->softabort_sem);

	GD_PRINT_2(KERN_EMERG"++ %s.......................... \n", __FUNCTION__);

	/*  cancel all work */
	for (idx = 0; idx < MAX_COMP_BUFF; idx++) {
		if (cancel_work_sync(&(sCmpReceiveWork[idx].CmpReceiveWork)) == true)
			printk("%s,Work idx:%d is pending...\n", __FUNCTION__, idx);
	}

	/*  mantis - 0068703 */
	online_reg.regValue = rtd_inl(GDMA_ONLINE_reg);
	update_reg.regValue = rtd_inl(GDMA_UPDATE_reg);
	if (online_reg.set_osd1_offline == 1)
		update_reg.osd1_bypass_acc_sync_fix = 1;
	if (online_reg.set_osd2_offline == 1)
		update_reg.osd2_bypass_acc_sync_fix = 1;
	if (online_reg.set_osd3_offline == 1)
		update_reg.osd3_bypass_acc_sync_fix = 1;
	if (online_reg.set_osd4_offline == 1)
		update_reg.osd4_bypass_acc_sync_fix = 1;
	if (online_reg.set_osd5_offline == 1)
		update_reg.osd5_bypass_acc_sync_fix = 1;
	rtd_outl(GDMA_UPDATE_reg, update_reg.regValue | GDMA_UPDATE_write_data(1));

	/*  set software abort bit */
	rtd_outl(GDMA_CTRL_reg, GDMA_CTRL_write_data(1) | GDMA_CTRL_offline_software_abort(1));

	/*  disable OSD COMP Interrupt */
	rtd_outl(GDMA_OSD_INTEN_reg, GDMA_OSD_INTEN_write_data(0) | GDMA_OSD_INTEN_wdma_done(1));

	/*  wait software abort bit to clear by HW finish */
	while (1) {
		if ((rtd_inl(GDMA_CTRL_reg) & GDMA_CTRL_offline_software_abort(1)) == 0)
			break;

		GD_PRINT_2(KERN_EMERG"%s, wait for software abort clear \n", __FUNCTION__);
	}

	memset(sCmpReceiveWork, 0, sizeof(struct cmp_receive_work)*MAX_COMP_BUFF);
	comp_ctl->comp_sem = COMP_SEM_COUNT;/* Can't_USE_SEM+ */
	comp_ctl->comp_process = 1;

	for (idx = 1; idx < MAX_COMP_BUFF; idx++)
		comp_ctl->comp_win[idx].buf_status = BUF_EMPTY;

	for (idx = 0; idx < MAX_COMP_BUFF; idx++)
		INIT_WORK((struct work_struct *)&sCmpReceiveWork[idx], osd_comp_receive_dequeue);

	/*  mantis - 0068703 */
	update_reg.regValue = 0;
	if (online_reg.set_osd1_offline == 1)
		update_reg.osd1_bypass_acc_sync_fix = 1;
	if (online_reg.set_osd2_offline == 1)
		update_reg.osd2_bypass_acc_sync_fix = 1;
	if (online_reg.set_osd3_offline == 1)
		update_reg.osd3_bypass_acc_sync_fix = 1;
	if (online_reg.set_osd4_offline == 1)
		update_reg.osd4_bypass_acc_sync_fix = 1;
	if (online_reg.set_osd5_offline == 1)
		update_reg.osd5_bypass_acc_sync_fix = 1;
	rtd_outl(GDMA_UPDATE_reg, update_reg.regValue);

	up(&comp_ctl->softabort_sem);

	GD_PRINT_2(KERN_EMERG"%s, software abort done... \n", __FUNCTION__);
}

EXPORT_SYMBOL(osd_comp_handler);
EXPORT_SYMBOL(osd_comp_init_module);
EXPORT_SYMBOL(osd_comp_init_module_reg);
EXPORT_SYMBOL(osd_comp_cleanup_module);
EXPORT_SYMBOL(osd_comp_softwareAbort);
EXPORT_SYMBOL(osd_comp_graphic_layers_wb_offline);
EXPORT_SYMBOL(osd_comp_graphic_layers_wb_online);
