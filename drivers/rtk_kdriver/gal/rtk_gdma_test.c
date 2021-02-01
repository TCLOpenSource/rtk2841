
#if 0
/* only for 4 taps */
void GDMA_SetVideoScalingCoeffs (unsigned short *coeff, int delta_phase, int init_phase, int taps)
{
	int i;

	if (ABS(delta_phase - 0x4000) < 0x20 && init_phase == 0) {
		memset (coeff, 0, taps << 3);
		for (i = 1; i <= 4; i++)
			coeff[(taps << 2) - i] = 0x1000;
	} else if (taps == 2) { /*  not used cause vout 2 tap coeff is set once in init & SE use 16 phase */
		for (i = 0; i < 8; i++)
			coeff[i] = GDMA_coef_2t8p_swap[i^1];
	} else {
		/* find the best coefficient set based on scaling ratio */
		if (delta_phase >= 0x4000) { /* down-scaling */
			for (i = 1; i < GDMA_NUM_COEFF_RATIOS - 1; i++) {
				/* VscaleRatio is incrementing, we find the first one that's bigger than or equal to delta
				instead of min ads diff. This way it will round up to lower pass filter to avoid alias */
				if (GDMA_ScaleRatio[i] >= delta_phase)
					break;
			}
		} else /* upscaling */
			i = 0;

		memcpy (coeff, GDMA_coef_4t8p_ratio_swap_[i][0], taps << 3);
	}
}
#endif



#if defined(_TEST_CODE_GDMA_) || defined(_TEST_CODE_OSDCOMP_)

GRAPHIC_LAYERS_OBJECT *android_test_layer1;
GRAPHIC_LAYERS_OBJECT *android_test_layer2;
GRAPHIC_LAYERS_OBJECT *android_test_layer3;
GRAPHIC_LAYERS_OBJECT *android_test_layer4;
PICTURE_LAYERS_OBJECT *pic_test_layer1;
PICTURE_LAYERS_OBJECT *pic_test_layer2;
PICTURE_LAYERS_OBJECT *pic_test_layer3;
unsigned int *g_OSDPalettePattern;
unsigned int g_sleeptime = 1, g_stop = 0;


#include "gdma_rtk_logo.h"	/* gdma_rtk_logo_260x200 */
#include "gdma_rtk_cursor.h"	/* mycursor_120x160 */
#include "gdma_lollipop_360x240.h"	/* lollipop_360x240 */
#include "gdma_yuyv422_packed_1920x1080.h"
//#include "gdma_fbdc320x240.info.bin.h"
//#include "gdma_fbdc640x480.info.bin.h"
//#include "gdma_fbdcsummer_1280x720.info.h"
//#include "gdma_fbdcNew_Zealand_1280x720.info.h"
//#include "gdma_fbdcLandscape_1920x1080.info.h"
//#include "gdma_fbdc1920x1080.info.h"

#endif


#ifdef _TEST_CODE_OSDCOMP_
unsigned int g_wbType_test = 0;
unsigned int g_comp_offlineplane_test = 0;
unsigned int g_comp_onlineplane_test = 0;


int osdcompthread1_fn(void *data)
{
	gdma_dev *gdma = &gdma_devices[0];
	unsigned long j0, j1;
	int delay = 60*HZ;
	j0 = jiffies;
	j1 = j0 + delay;
	int panelW = gdma->dispWin[0].width;
	int panelH = gdma->dispWin[0].height;
	int x = 0, y = 0, lineflag = 0;

	pr_debug(KERN_EMERG "In thread1\n");

	while (1) {
		/* pr_debug("osdthread1_fn...1111 \n"); */
		osd_comp_pre_receive_picture(pic_test_layer1);
		msleep(50);
		/* ssleep(1); */
/*
		// cursor test
		y += 1;
		x = (panelW*y)/panelH;

		if ((y+pic_test_layer1->layer[OSD1_3].normal[0].dst_height) > panelH ||
			(x+pic_test_layer1->layer[OSD1_3].normal[0].dst_width) > panelW)
			x = y = 0;

		pic_test_layer1->layer[OSD1_3].normal[0].dst_x = x;
		pic_test_layer1->layer[OSD1_3].normal[0].dst_y = y;
*/
	}

	return 0;
}

int osdcompthread2_fn(void *data)
{
	gdma_dev *gdma = &gdma_devices[0];
	int panelW = gdma->dispWin[0].width;
	int panelH = gdma->dispWin[0].height;
	int x = 0, y = 0;
	unsigned long j0, j1;
	int delay = 40*HZ;
	j0 = jiffies;
	j1 = j0 + delay;


	pr_debug(KERN_EMERG "In thread2\n");

	while (1) {
		/* pr_debug("osdthread2_fn...2222 \n"); */
		osd_comp_pre_receive_picture(pic_test_layer2);
		msleep(50);
		/* ssleep(3); */
/*
		y += 1;
		x = (panelW*y)/panelH;

		if ((y+android_test_layer2->layer[5].dst_height) > panelH ||
			(x+android_test_layer2->layer[5].dst_width) > panelW)
			x = y = 0;

		android_test_layer2->layer[5].dst_x = (int)x;
		android_test_layer2->layer[5].dst_y = (int)y;
*/
	}

	return 0;
}

int osdcompthread3_fn(void *data)
{
	gdma_dev *gdma = &gdma_devices[0];
	unsigned long j0, j1;
	int delay = 20*HZ;
	j0 = jiffies;
	j1 = j0 + delay;
	int panelW = gdma->dispWin[0].width;
	int panelH = gdma->dispWin[0].height;
	int x = 0, y = 0, lineflag = 0;

	pr_debug(KERN_EMERG "In thread3\n");

	while (1) {
		/* pr_debug("osdthread3_fn...3333 \n"); */
		osd_comp_pre_receive_picture(pic_test_layer3);
		msleep(50);

		/* random test */
		y = (get_random_int() % panelH);
		x = (get_random_int() % panelW);

		if ((y+pic_test_layer3->layer[OSD1_1].normal[0].dst_height) > panelH) {
			pic_test_layer3->layer[OSD1_1].normal[0].dst_y = panelH - pic_test_layer3->layer[OSD1_1].normal[0].dst_height;
		} else {
			pic_test_layer3->layer[OSD1_1].normal[0].dst_y = y;
		}

		if ((x+pic_test_layer3->layer[OSD1_1].normal[0].dst_width) > panelW) {
			pic_test_layer3->layer[OSD1_1].normal[0].dst_x = panelW - pic_test_layer3->layer[OSD1_1].normal[0].dst_width;
		} else {
			pic_test_layer3->layer[OSD1_1].normal[0].dst_x = x;
		}
	}

	return 0;
}



int osdthread1_fn(void *data)
{
	gdma_dev *gdma = &gdma_devices[0];
	unsigned long j0, j1;
	int delay = 60*HZ;
	j0 = jiffies;
	j1 = j0 + delay;
	int panelW = gdma->dispWin[0].width;
	int panelH = gdma->dispWin[0].height;
	int x = 0, y = 0, lineflag = 0;

	pr_debug(KERN_EMERG "In thread1\n");

	while (1) {

		GDMA_ReceiveGraphicLayers(android_test_layer1);

		g_sleeptime = rtd_inl(0xb800501c);
		if (g_sleeptime)
			msleep(g_sleeptime);
		if (g_stop == 2379) break;
#if 0
		/* cursor test*/
		y += 1;
		x = (panelW*y)/panelH;

		if ((y+android_test_layer1->layer[OSD1_3].dst_height) > panelH ||
			(x+android_test_layer1->layer[OSD1_3].dst_width) > panelW)
			x = y = 0;

		android_test_layer1->layer[OSD1_3].dst_x = x;
		android_test_layer1->layer[OSD1_3].dst_y = y;
#endif
	}

	return 0;
}

int osdthread2_fn(void *data)
{
	gdma_dev *gdma = &gdma_devices[0];
	int panelW = gdma->dispWin[0].width;
	int panelH = gdma->dispWin[0].height;
	int x = 0, y = 0;
	unsigned long j0, j1;
	int delay = 40*HZ;
	j0 = jiffies;
	j1 = j0 + delay;


	pr_debug(KERN_EMERG "In thread2\n");

	while (1) {
		GDMA_ReceiveGraphicLayers(android_test_layer2);
		g_sleeptime = rtd_inl(0xb800501c);
		if (g_sleeptime)
			msleep(g_sleeptime + 1);
		if (g_stop == 2379) break;
	}

	return 0;
}

int osdthread3_fn(void *data)
{
	gdma_dev *gdma = &gdma_devices[0];
	unsigned long j0, j1;
	int delay = 20*HZ;
	j0 = jiffies;
	j1 = j0 + delay;
	int panelW = gdma->dispWin[0].width;
	int panelH = gdma->dispWin[0].height;
	int x = 0, y = 0, lineflag = 0;

	pr_debug(KERN_EMERG "In thread3\n");

	while (1) {

		android_test_layer3->layer_num = 1;

		GDMA_ReceiveGraphicLayers(android_test_layer3);
		g_sleeptime = rtd_inl(0xb800501c);
		if (g_sleeptime)
			msleep(g_sleeptime + 2);
		if (g_stop == 2379) break;

#if 0
		/* random test*/
		y = (get_random_int() % panelH);
		x = (get_random_int() % panelW);

		if ((y+android_test_layer3->layer[OSD1_1].dst_height) > panelH) {
			android_test_layer3->layer[OSD1_1].dst_y = panelH - android_test_layer3->layer[OSD1_1].dst_height;
		} else {
			android_test_layer3->layer[OSD1_1].dst_y = y;
		}

		if ((x+android_test_layer3->layer[OSD1_1].dst_width) > panelW) {
			android_test_layer3->layer[OSD1_1].dst_x = panelW - android_test_layer3->layer[OSD1_1].dst_width;
		} else {
			android_test_layer3->layer[OSD1_1].dst_x = x;
		}
#endif
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

	}

	return 0;
}

int osdthread4_fn(void)
{
	unsigned long j0, j1;
	int delay = 20*HZ;
	j0 = jiffies;
	j1 = j0 + delay;

	pr_debug(KERN_EMERG "In thread4\n");

	while (1) {
		android_test_layer3->layer_num = 3;

		GDMA_ReceiveGraphicLayers(android_test_layer3);
		g_sleeptime = rtd_inl(0xb800501c);
		if (g_sleeptime)
			msleep(g_sleeptime + 3);
		if (g_stop == 2379) break;
	}

	return 0;
}

int osdthread5_fn(void)
{
	gdma_dev *gdma = &gdma_devices[0];
	unsigned long j0, j1;
	int delay = 20*HZ;
	j0 = jiffies;
	j1 = j0 + delay;
	int panelW = gdma->dispWin[0].width;
	int panelH = gdma->dispWin[0].height;
	int x = 0, y = 0, lineflag = 0;

	pr_debug(KERN_EMERG "In thread5\n");

	while (1) {

		GDMA_ReceiveGraphicLayers(android_test_layer4);
		g_sleeptime = rtd_inl(0xb800501c);
		if (g_sleeptime)
			msleep(g_sleeptime + 4);
		if (g_stop == 2379) break;

#if 1
		/* random test*/
		y = (get_random_int() % panelH);
		x = (get_random_int() % panelW);

		if ((y+android_test_layer4->layer[3].dst_height) > panelH) {
			android_test_layer4->layer[3].dst_y = panelH - android_test_layer4->layer[3].dst_height;
		} else {
			android_test_layer4->layer[3].dst_y = y;
		}

		if ((x+android_test_layer4->layer[3].dst_width) > panelW) {
			android_test_layer4->layer[3].dst_x = panelW - android_test_layer4->layer[3].dst_width;
		} else {
			android_test_layer4->layer[3].dst_x = x;
		}
#endif

	}

	return 0;
}






void osdcomp_test(void)
{
	int iloop = 0, jloop = 0;
	static unsigned int *fillcolor = NULL;
	static unsigned int *fillcolor_osd2 = NULL;
	static unsigned int *fillcolor_osd3 = NULL;
	static unsigned char *fillcursor = NULL;
	ushort winID = 0;
	GDMA_WIN *win = NULL;
	static VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN *create_win;
	static VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN *draw_win;
	gdma_dev *gdma = &gdma_devices[0];
	dma_addr_t addr1, addr2, addr3, addr4;
	static PICTURE_LAYERS_OBJECT *pic_layer;
	static GRAPHIC_LAYERS_OBJECT *android_layer;
	osd_clear_x osdcmp_clearx;
	osd_clear_y osdcmp_cleary;
	osd_planealpha_ar osdcmp_plane_ar;
	osd_planealpha_gb osdcmp_plane_gb;
	osdcmp_clearx.value = 0;
	osdcmp_cleary.value = 0;
	osdcmp_plane_ar.plane_alpha_r = 0xff;
	osdcmp_plane_ar.plane_alpha_a = 0xff;
	osdcmp_plane_gb.plane_alpha_b = 0xff;
	osdcmp_plane_gb.plane_alpha_g = 0xff;

	if (g_OSDPalettePattern == NULL)
		g_OSDPalettePattern =  kmalloc(256*4, GFP_KERNEL);
	if (fillcursor == NULL)
		fillcursor = kmalloc(256*256, GFP_KERNEL);
	if (pic_layer == NULL)
		pic_layer = kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (draw_win == NULL)
		draw_win = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (create_win == NULL)
		create_win = kmalloc(sizeof(VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN), GFP_KERNEL);
	if (win == NULL)
		win = kmalloc(sizeof(GDMA_WIN), GFP_KERNEL);
	if (fillcolor == NULL)
		fillcolor = kmalloc(1280*720*4, GFP_KERNEL);
	if (fillcolor_osd2 == NULL)
		fillcolor_osd2 = kmalloc(1280*720*4, GFP_KERNEL);
	if (fillcolor_osd3 == NULL)
		fillcolor_osd3 = kmalloc(640*360*4, GFP_KERNEL);
	if (android_layer == NULL)
		android_layer = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);
	if (win == NULL || fillcolor == NULL || create_win == NULL ||
		draw_win == NULL || pic_layer == NULL || fillcolor_osd2 == NULL ||
		android_layer == NULL || fillcolor_osd3 == NULL) {
		pr_debug(KERN_EMERG"malloc fail\n");
		return;
	}
	memset(fillcursor, 0xff, 256*256);
	memset(g_OSDPalettePattern, 0x00, 256*4);
	memset(android_layer, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
	memset(pic_layer, 0, sizeof(PICTURE_LAYERS_OBJECT));
	memset(draw_win, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(create_win, 0, sizeof(VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN));
	memset(win, 0, sizeof(GDMA_WIN));
	memset(fillcolor, 0xff, 1280*720*4);
	memset(fillcolor_osd2, 0xff, 1280*720*4);
	memset(fillcolor_osd3, 0xff, 640*360*4);
	pr_debug(KERN_EMERG"memset = win=0x%x,fillcolor=0x%x,fillcolor_osd2=0x%x,fillcolor_osd3=0x%x\n", win, fillcolor, fillcolor_osd2, fillcolor_osd3);
	pr_debug(KERN_EMERG"virtual = win=0x%x,fillcolor=0x%x\n", virt_to_phys(win), virt_to_phys(fillcolor));
	pr_debug(KERN_EMERG"fillcolor_osd2=0x%x\n", virt_to_phys(fillcolor_osd2));
	pr_debug(KERN_EMERG"fillcolor_osd3=0x%x\n", virt_to_phys(fillcolor_osd3));

	dsb();

	addr1 = dma_map_single(gdma->dev, (void *)fillcolor, 1280*720*4, DMA_TO_DEVICE);
	addr2 = dma_map_single(gdma->dev, (void *)fillcolor_osd2, 1280*720*4, DMA_TO_DEVICE);
	addr3 = dma_map_single(gdma->dev, (void *)fillcolor_osd3, 640*360*4, DMA_TO_DEVICE);
	addr4 = dma_map_single(gdma->dev, (void *)fillcursor, 256*256, DMA_TO_DEVICE);

	if (dma_mapping_error(gdma->dev, addr1))
		pr_debug("dma_map_single fail addr1 \n");
	if (dma_mapping_error(gdma->dev, addr2))
		pr_debug("dma_map_single fail addr2 \n");
	if (dma_mapping_error(gdma->dev, addr3))
		pr_debug("dma_map_single fail addr3 \n");
	if (dma_mapping_error(gdma->dev, addr4))
		pr_debug("dma_map_single fail addr4 \n");

	for (iloop = 0; iloop < 256*256; iloop++) {
		fillcursor[iloop] = 0;
	}
	for (iloop = 0; iloop < 256; iloop++) {
		g_OSDPalettePattern[iloop] = 0xFF0000FF;
	}
	memcpy (gdma->OSD_CLUT[0], (void *)(g_OSDPalettePattern), sizeof(unsigned int) * 256);

	/*  make image source */
	int div = ((640 * 360) / 10);
	for (iloop = 0; iloop < 1280*720; iloop++) {
		if (iloop < ((1280*720)/2)) {
			jloop = iloop%1280;
			if (jloop < 300)
				fillcolor[iloop] = 0xff0000ff;/* Red//RGBA, big-endian */
			else if ((jloop >= 300) && (jloop < 600))
				fillcolor[iloop] = 0xff00ff00;/* Green */
			else if ((jloop >= 600) && (jloop < 1280))
				fillcolor[iloop] = 0xffff0000;/* Blue */
		} else {
			jloop = iloop%1280;
			if (jloop < 500)
				fillcolor[iloop] = 0xffff00ff;/* Red */
			else if ((jloop >= 500) && (jloop < 1000))
				fillcolor[iloop] = 0xffffffff;/* white */
			else if ((jloop >= 1000) && (jloop < 1280))
				fillcolor[iloop] = 0xff00ffff;/* yellow */
		}

		if (iloop < ((1280*720)/4))
			fillcolor_osd2[iloop] = 0xff7b7b7b;/* Red//RGBA, big-endian */
		else if (iloop >= ((1280*720)/4) && iloop < ((1280*720)/2))
			fillcolor_osd2[iloop] = 0xffffffff;
		else if (iloop >= ((1280*720)/2) && iloop < (((1280*720)/4)*3))
			fillcolor_osd2[iloop] = 0xff7b7b7b;
		else if (iloop >= (((1280*720)/4)*3) && iloop < (1280*720))
			fillcolor_osd2[iloop] = 0xffffffff;

		if (iloop < div)
			fillcolor_osd3[iloop] = 0xff0000ff;/* Red//RGBA, big-endian */
		else if (iloop >= (div * 1) && iloop < (div * 2))
			fillcolor_osd3[iloop] = 0xff00ffff;
		else if (iloop >= (div * 2) && iloop < (div * 3))
			fillcolor_osd3[iloop] = 0xffffffff;
		else if (iloop >= (div * 3) && iloop < (div * 4))
			fillcolor_osd3[iloop] = 0xffff0000;
		else if (iloop >= (div * 4) && iloop < (div * 5))
			fillcolor_osd3[iloop] = 0xff7b7b7b;
		else if (iloop >= (div * 5) && iloop < (div * 6))
			fillcolor_osd3[iloop] = 0xffff00ff;
		else if (iloop >= (div * 6) && iloop < (div * 7))
			fillcolor_osd3[iloop] = 0xff000000;
		else if (iloop >= (div * 7) && iloop < (div * 8))
			fillcolor_osd3[iloop] = 0xff808080;
		else if (iloop >= (div * 8) && iloop < (div * 9))
			fillcolor_osd3[iloop] = 0xff404040;
		else if (iloop >= (div * 9) && iloop < (div * 10))
			fillcolor_osd3[iloop] = 0xffa0a0a0;
	}

	dma_sync_single_for_device(gdma->dev, addr1, 1280*720*4, DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr2, 1280*720*4, DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr3, 640*360*4, DMA_TO_DEVICE);

	/* dsb(); */
	/* ssleep(5); */
	dma_unmap_single(gdma->dev, addr1, 1280*720*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr2, 1280*720*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr3, 640*360*4, DMA_TO_DEVICE);


#if (_TEST_CODE_OSDCOMP_ == 1)
	create_win->plane = VO_GRAPHIC_OSD5;
	create_win->winPos.x = 0;
	create_win->winPos.y = 0;
	create_win->winPos.height = 720;
	create_win->winPos.width = 1280;
	create_win->colorFmt = VO_OSD_COLOR_FORMAT_RGBA8888;
	create_win->rgbOrder = VO_OSD_COLOR_RGB;
	create_win->colorKey = -1;
	create_win->compressed = 1;
	create_win->alpha = 0;
	winID = GDMA_CreateGraphicWindow(create_win);

	pr_debug("GDMA_CreateGraphicWindow:: OSD ID=%d \n", winID);

	draw_win->plane = VO_GRAPHIC_OSD5;
	draw_win->winID = winID;
	draw_win->storageMode = VO_GRAPHIC_SEQUENTIAL;
	draw_win->paletteIndex = 0;
	draw_win->compressed = 1;
	draw_win->interlace_Frame = 0;
	draw_win->bottomField = 0;
	draw_win->startX[0] = 0;
	draw_win->startY[0] = 0;
	draw_win->imgPitch[0] = 1280*4;
	draw_win->pImage[0] = (unsigned int)virt_to_phys((long)fillcolor);
	draw_win->go = 1;


	if (GDMA_DrawGraphicWindow(draw_win) == GDMA_SUCCESS)
		pr_debug("GDMA_DrawGraphicWindow:: Successfully \n");

	GDMA_DeleteGraphicWindow(winID, VO_GRAPHIC_OSD1, 1);

#endif

#if (_TEST_CODE_OSDCOMP_ == 2)

	pic_layer->layer_num = 1;
	pic_layer->layer[OSD1_1].normal_num = 2;
	pic_layer->layer[OSD1_1].normal[0].src_type = SRC_NORMAL;
	pic_layer->layer[OSD1_1].normal[0].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	/*pic_layer->layer[OSD1_1].normal[0].fbdc_format;*/
	pic_layer->layer[OSD1_1].normal[0].context = 0;
	pic_layer->layer[OSD1_1].normal[0].key_en = 0;
	pic_layer->layer[OSD1_1].normal[0].colorkey = -1;		   /* -1: disable colorkey */
	pic_layer->layer[OSD1_1].normal[0].alpha = 0;			   /*  0: disable constant alpha */
	pic_layer->layer[OSD1_1].normal[0].x = 0;/* src */
	pic_layer->layer[OSD1_1].normal[0].y = 0;/* src */
	pic_layer->layer[OSD1_1].normal[0].width = 1280;/* src */
	pic_layer->layer[OSD1_1].normal[0].height = 720;/* src */
	pic_layer->layer[OSD1_1].normal[0].address = (unsigned int)virt_to_phys((long)fillcolor);
	pic_layer->layer[OSD1_1].normal[0].pitch = pic_layer->layer[OSD1_1].normal[0].width * 4;
	pic_layer->layer[OSD1_1].normal[0].seg_addr[0] = ONE_PIXEL_SEG;/* for compress and decompress use */
	/*pic_layer->layer[OSD1_1].normal[0].picLayout;*/
	pic_layer->layer[OSD1_1].normal[0].compressed = 1;	/*	indicate this layer needs to do compression for OSD compress */
	pic_layer->layer[OSD1_1].normal[0].wbType = RTKCOMPRESS;
	/*pic_layer->layer[OSD1_1].normal[0].seg_num;*/
	/*pic_layer->layer[OSD1_1].normal[0].current_comp_idx; */	/* for compress use */
	pic_layer->layer[OSD1_1].normal[0].comp_plane = VO_GRAPHIC_OSD3;		/*	compose plane */
	pic_layer->layer[OSD1_1].normal[0].plane = VO_GRAPHIC_OSD4; 			 /*  final display plane */
	pic_layer->layer[OSD1_1].normal[0].dst_x = 0;/* dst */
	pic_layer->layer[OSD1_1].normal[0].dst_y = 0;/* dst */
	pic_layer->layer[OSD1_1].normal[0].dst_width = TWOK_W;/* dst */
	pic_layer->layer[OSD1_1].normal[0].dst_height = ONEK_H;/* dst */
	pic_layer->layer[OSD1_1].normal[0].layer_used = 1;/* for compress */
	pic_layer->layer[OSD1_1].normal[0].plane_ar = osdcmp_plane_ar; 	/*	fbdc only 8 bits, mixer has 9 bits */
	pic_layer->layer[OSD1_1].normal[0].plane_gb = osdcmp_plane_gb; 	/*	fbdc only 8 bits, mixer has 9 bits */
	pic_layer->layer[OSD1_1].normal[0].clear_x = osdcmp_clearx;
	pic_layer->layer[OSD1_1].normal[0].clear_y = osdcmp_cleary;
	pic_layer->layer[OSD1_1].normal[0].show = 1;					/* 1: show this plane. 0:hide */
	/*pic_layer->layer[OSD1_1].normal[0].decompress;	*/   /*	for continue compress test, indicate this layer needs to decompress for OSD compression or GDMA */
	/*pic_layer->layer[OSD1_1].normal[0].paletteformat;*/ /* YVUA-->0  BGRA-->1 */
	/*pic_layer->layer[OSD1_1].normal[0].paletteIndex;*/
	/*pic_layer->layer[OSD1_1].normal[0].rgb_order;*/
	/*pic_layer->layer[OSD1_1].normal[0].syncInfo;*/
	pic_layer->layer[OSD1_1].normal[0].offlineOrder = C0;   /*  for offline blend use */
	pic_layer->layer[OSD1_1].normal[0].scale_factor = 1;	/* layer scale factor based on panel size & fb size */
	/*pic_layer->layer[OSD1_1].normal[0].isFromOffline;		*/			/* image data from offline */

	pic_layer->layer[OSD1_1].normal[1].src_type = SRC_NORMAL;
	pic_layer->layer[OSD1_1].normal[1].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	/*pic_layer->layer[OSD1_1].normal[1].fbdc_format;*/
	pic_layer->layer[OSD1_1].normal[1].context = 0;
	pic_layer->layer[OSD1_1].normal[1].key_en = 0;
	pic_layer->layer[OSD1_1].normal[1].colorkey = -1;		   /* -1: disable colorkey */
	pic_layer->layer[OSD1_1].normal[1].alpha = 0xff;			   /*  0: disable constant alpha */
	pic_layer->layer[OSD1_1].normal[1].x = 0;/* src */
	pic_layer->layer[OSD1_1].normal[1].y = 0;/* src */
	pic_layer->layer[OSD1_1].normal[1].width = 360;/* src */
	pic_layer->layer[OSD1_1].normal[1].height = 240;/* src */
	pic_layer->layer[OSD1_1].normal[1].address = (unsigned int)virt_to_phys((long)lollipop_360x240);
	pic_layer->layer[OSD1_1].normal[1].pitch = pic_layer->layer[OSD1_1].normal[1].width * 4;
	pic_layer->layer[OSD1_1].normal[1].seg_addr[0] = ONE_PIXEL_SEG;/* for compress and decompress use */
	/*pic_layer->layer[OSD1_1].normal[1].picLayout;*/
	pic_layer->layer[OSD1_1].normal[1].compressed = 1;	/*	indicate this layer needs to do compression for OSD compress */
	pic_layer->layer[OSD1_1].normal[1].wbType = RTKCOMPRESS;
	/*pic_layer->layer[OSD1_1].normal[1].seg_num;*/
	/*pic_layer->layer[OSD1_1].normal[1].current_comp_idx = 0;*/ 	/* for compress use */
	pic_layer->layer[OSD1_1].normal[1].comp_plane = VO_GRAPHIC_OSD5;		/*	compose plane */
	pic_layer->layer[OSD1_1].normal[1].plane = VO_GRAPHIC_OSD4; 			 /*  final display plane */
	pic_layer->layer[OSD1_1].normal[1].dst_x = 50;/* dst */
	pic_layer->layer[OSD1_1].normal[1].dst_y = 50;/* dst */
	pic_layer->layer[OSD1_1].normal[1].dst_width = 360;/* dst */
	pic_layer->layer[OSD1_1].normal[1].dst_height = 240;/* dst */
	pic_layer->layer[OSD1_1].normal[1].layer_used = 1;/* for compress */
	pic_layer->layer[OSD1_1].normal[1].plane_ar = osdcmp_plane_ar; 	/*	fbdc only 8 bits, mixer has 9 bits */
	pic_layer->layer[OSD1_1].normal[1].plane_gb = osdcmp_plane_gb; 	/*	fbdc only 8 bits, mixer has 9 bits */
	pic_layer->layer[OSD1_1].normal[1].clear_x = osdcmp_clearx;
	pic_layer->layer[OSD1_1].normal[1].clear_y = osdcmp_cleary;
	pic_layer->layer[OSD1_1].normal[1].show = 1;					/* 1: show this plane. 0:hide */
	/*pic_layer->layer[OSD1_1].normal[1].decompress;	*/  /*	for continue compress test, indicate this layer needs to decompress for OSD compression or GDMA */
	/*pic_layer->layer[OSD1_1].normal[1].paletteformat;*/ /* YVUA-->0  BGRA-->1 */
	/*pic_layer->layer[OSD1_1].normal[1].paletteIndex;*/
	/*pic_layer->layer[OSD1_1].normal[1].rgb_order;*/
	/*pic_layer->layer[OSD1_1].normal[1].syncInfo;*/
	pic_layer->layer[OSD1_1].normal[1].offlineOrder = C1;   /*  for offline blend use */
	pic_layer->layer[OSD1_1].normal[1].scale_factor = 1;	/* layer scale factor based on panel size & fb size */
	/*pic_layer->layer[OSD1_1].normal[1].isFromOffline;	*/				/* image data from offline */

	osd_comp_pre_receive_picture(pic_layer);
#endif

#if (_TEST_CODE_OSDCOMP_ == 3)

	android_layer->layer_num = 2;

	android_layer->layer[OSD1_1].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_layer->layer[OSD1_1].context = 0; /*  ?? */
	android_layer->layer[OSD1_1].key_en = 0;
	android_layer->layer[OSD1_1].colorkey = -1;
	android_layer->layer[OSD1_1].alpha = 0;/* 0x80; */
	android_layer->layer[OSD1_1].x = 0;
	android_layer->layer[OSD1_1].y = 0;
	android_layer->layer[OSD1_1].height = 720;
	android_layer->layer[OSD1_1].width = 1280;
	android_layer->layer[OSD1_1].address = (unsigned int)virt_to_phys(fillcolor);
	android_layer->layer[OSD1_1].pitch = 1280*4;
	/*android_layer->layer[OSD1_1].plane = VO_GRAPHIC_OSD1;*/
	android_layer->layer[OSD1_1].dst_x = 0;
	android_layer->layer[OSD1_1].dst_y = 0;
	android_layer->layer[OSD1_1].dst_height = 720;
	android_layer->layer[OSD1_1].dst_width = 1280;
	android_layer->layer[OSD1_1].compressed = 1;
	/* android_layer->layer[OSD1_1].handle = 1; */
	osdcmp_plane.plane_alpha_a = 0x80;
	osdcmp_plane.plane_alpha_r = 0x80;
	osdcmp_clearx.x_sta = 20;
	osdcmp_clearx.x_end = 40;
	osdcmp_cleary.y_sta = 20;
	osdcmp_cleary.y_end = 40;
	android_layer->layer[OSD1_1].plane_ar = osdcmp_plane_ar;
	android_layer->layer[OSD1_1].plane_gb = osdcmp_plane_gb;
	android_layer->layer[OSD1_1].clear_x = osdcmp_clearx;
	android_layer->layer[OSD1_1].clear_y = osdcmp_cleary;

	android_layer->layer[OSD1_2].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_layer->layer[OSD1_2].context = 0; /*  ?? */
	android_layer->layer[OSD1_2].key_en = 0;
	android_layer->layer[OSD1_2].colorkey = -1;
	android_layer->layer[OSD1_2].alpha = 0x80;
	android_layer->layer[OSD1_2].x = 0;
	android_layer->layer[OSD1_2].y = 0;
	android_layer->layer[OSD1_2].height = 720;
	android_layer->layer[OSD1_2].width = 1280;
	android_layer->layer[OSD1_2].address = (unsigned int)virt_to_phys(fillcolor_osd2);
	android_layer->layer[OSD1_2].pitch = 1280*4;
	/*android_layer->layer[OSD1_2].plane = VO_GRAPHIC_OSD2;*/
	android_layer->layer[OSD1_2].dst_x = 32;
	android_layer->layer[OSD1_2].dst_y = 32;
	android_layer->layer[OSD1_2].dst_height = 720;
	android_layer->layer[OSD1_2].dst_width = 1280;
	android_layer->layer[OSD1_2].compressed = 1;
	/* android_layer->layer[OSD1_2].handle = 1; */
	osdcmp_plane_ar.value = 0xffffffff;
	osdcmp_plane_gb.value = 0xffffffff;
	osdcmp_clearx.x_sta = 100;
	osdcmp_clearx.x_end = 200;
	osdcmp_cleary.y_sta = 100;
	osdcmp_cleary.y_end = 200;
	android_layer->layer[OSD1_2].plane_ar = osdcmp_plane_ar;
	android_layer->layer[OSD1_2].plane_gb = osdcmp_plane_gb;
	android_layer->layer[OSD1_2].clear_x = osdcmp_clearx;
	android_layer->layer[OSD1_2].clear_y = osdcmp_cleary;
	GDMA_ReceiveGraphicLayers(android_layer);
#endif

#if (_TEST_CODE_OSDCOMP_ == 4)

	/*osdcmp_plane_ar.value = 0xffffffff;
	osdcmp_plane_gb.value = 0xffffffff;*/

	int osd_idx1, osd_idx2, osd_idx3, osd_idx4;
	VO_GRAPHIC_PLANE plane1, plane2, plane3, plane4;
	u32 dst_w1, dst_w2, dst_w3, dst_w4;
	u32 dst_h1, dst_h2, dst_h3, dst_h4;
	osd_idx1 = OSD1_1;
	osd_idx2 = OSD1_2;
	osd_idx3 = OSD1_3;
	osd_idx4 = MAX_COMP_VIRTUAL_LAYERS;
	plane1 = VO_GRAPHIC_OSD1;
	plane2 = VO_GRAPHIC_OSD2;
	plane3 = VO_GRAPHIC_OSD3;
	plane4 = VO_GRAPHIC_OSD2;

#if 0
	/*  one layer scaling */
	dst_w1 = 1280;
	dst_w2 = 1920;
	dst_w3 = 640;

	dst_h1 = 720;
	dst_h2 = 1080;
	dst_h3 = 360;
#endif
#if 0
	/*  two layers scaling */
	dst_w1 = 1280;
	dst_w2 = 1920;
	dst_w3 = 1280;

	dst_h1 = 720;
	dst_h2 = 1080;
	dst_h3 = 720;
#endif
#if 1
	/*  three layers scaling */
	dst_w1 = 1920;
	dst_w2 = 1920;
	dst_w3 = 1280;
	dst_w4 = 120;

	dst_h1 = 1080;
	dst_h2 = 1080;
	dst_h3 = 720;
	dst_h4 = 160;
#endif

	android_layer->layer_num = 4;

	android_layer->layer[osd_idx1].src_type = SRC_NORMAL;
	android_layer->layer[osd_idx1].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_layer->layer[osd_idx1].context = 0; /*  ?? */
	android_layer->layer[osd_idx1].key_en = 0;
	android_layer->layer[osd_idx1].colorkey = -1;
	android_layer->layer[osd_idx1].alpha = 0x80;
	android_layer->layer[osd_idx1].x = 0;
	android_layer->layer[osd_idx1].y = 0;
	android_layer->layer[osd_idx1].height = 720;
	android_layer->layer[osd_idx1].width = 1280;
	android_layer->layer[osd_idx1].address = (unsigned int)virt_to_phys(fillcolor);
	android_layer->layer[osd_idx1].pitch = android_layer->layer[osd_idx1].width*4;
	android_layer->layer[osd_idx1].dst_x = 0;
	android_layer->layer[osd_idx1].dst_y = 0;
	android_layer->layer[osd_idx1].dst_height = dst_h1;
	android_layer->layer[osd_idx1].dst_width = dst_w1;
	android_layer->layer[osd_idx1].compressed = 1;
	android_layer->layer[osd_idx1].plane_ar = osdcmp_plane_ar;
	android_layer->layer[osd_idx1].plane_gb = osdcmp_plane_gb;
	osdcmp_clearx.x_sta = 20;
	osdcmp_clearx.x_end = 400;
	osdcmp_cleary.y_sta = 900;
	osdcmp_cleary.y_end = 1000;
	android_layer->layer[osd_idx1].clear_x = osdcmp_clearx;
	android_layer->layer[osd_idx1].clear_y = osdcmp_cleary;
	android_layer->layer[osd_idx1].syncstamp = 0;
	android_layer->layer[osd_idx1].show = 1;
	android_layer->layer[osd_idx1].scale_factor = 1;

	android_layer->layer[osd_idx2].src_type = SRC_NORMAL;
	android_layer->layer[osd_idx2].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_layer->layer[osd_idx2].context = 0; /*  ?? */
	android_layer->layer[osd_idx2].key_en = 0;
	android_layer->layer[osd_idx2].colorkey = -1;
	android_layer->layer[osd_idx2].alpha = 0x80;
	android_layer->layer[osd_idx2].x = 0;
	android_layer->layer[osd_idx2].y = 0;
	android_layer->layer[osd_idx2].height = 720;
	android_layer->layer[osd_idx2].width = 1280;
	android_layer->layer[osd_idx2].address = (unsigned int)virt_to_phys(fillcolor_osd2);
	android_layer->layer[osd_idx2].pitch = android_layer->layer[osd_idx2].width*4;
	android_layer->layer[osd_idx2].dst_x = 0;
	android_layer->layer[osd_idx2].dst_y = 0;
	android_layer->layer[osd_idx2].dst_height = dst_h2;
	android_layer->layer[osd_idx2].dst_width = dst_w2;
	android_layer->layer[osd_idx2].compressed = 1;
	android_layer->layer[osd_idx2].plane_ar = osdcmp_plane_ar;
	android_layer->layer[osd_idx2].plane_gb = osdcmp_plane_gb;
	osdcmp_clearx.x_sta = 1700;
	osdcmp_clearx.x_end = 1800;
	osdcmp_cleary.y_sta = 100;
	osdcmp_cleary.y_end = 200;
	android_layer->layer[osd_idx2].clear_x = osdcmp_clearx;
	android_layer->layer[osd_idx2].clear_y = osdcmp_cleary;
	android_layer->layer[osd_idx2].syncstamp = 0;
	android_layer->layer[osd_idx2].show = 1;
	android_layer->layer[osd_idx2].scale_factor = 1;

	android_layer->layer[osd_idx3].src_type = SRC_NORMAL;
	android_layer->layer[osd_idx3].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_layer->layer[osd_idx3].context = 0; /*  ?? */
	android_layer->layer[osd_idx3].key_en = 0;
	android_layer->layer[osd_idx3].colorkey = -1;
	android_layer->layer[osd_idx3].alpha = 0x80;
	android_layer->layer[osd_idx3].x = 0;
	android_layer->layer[osd_idx3].y = 0;
	android_layer->layer[osd_idx3].height = 360;
	android_layer->layer[osd_idx3].width = 640;
	android_layer->layer[osd_idx3].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_layer->layer[osd_idx3].pitch = android_layer->layer[osd_idx3].width*4;
	android_layer->layer[osd_idx3].dst_x = 100;
	android_layer->layer[osd_idx3].dst_y = 100;
	android_layer->layer[osd_idx3].dst_height = dst_h3;
	android_layer->layer[osd_idx3].dst_width = dst_w3;
	android_layer->layer[osd_idx3].compressed = 1;
	android_layer->layer[osd_idx3].plane_ar = osdcmp_plane_ar;
	android_layer->layer[osd_idx3].plane_gb = osdcmp_plane_gb;
	osdcmp_clearx.x_sta = 50;
	osdcmp_clearx.x_end = 200;
	osdcmp_cleary.y_sta = 50;
	osdcmp_cleary.y_end = 200;
	android_layer->layer[osd_idx3].clear_x = osdcmp_clearx;
	android_layer->layer[osd_idx3].clear_y = osdcmp_cleary;
	android_layer->layer[osd_idx3].syncstamp = 0;
	android_layer->layer[osd_idx3].show = 1;
	android_layer->layer[osd_idx3].scale_factor = 1;

	android_layer->layer[osd_idx4].src_type = SRC_MOUSE_NORMAL;
	android_layer->layer[osd_idx4].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_layer->layer[osd_idx4].context = 0; /*  ?? */
	android_layer->layer[osd_idx4].key_en = 0;
	android_layer->layer[osd_idx4].colorkey = -1;
	android_layer->layer[osd_idx4].alpha = 0x80;
	android_layer->layer[osd_idx4].x = 0;
	android_layer->layer[osd_idx4].y = 0;
	android_layer->layer[osd_idx4].height = 160;
	android_layer->layer[osd_idx4].width = 120;
	android_layer->layer[osd_idx4].address = virt_to_phys((unsigned int)mycursor_120x160);
	android_layer->layer[osd_idx4].pitch = android_layer->layer[osd_idx4].width*4;
	android_layer->layer[osd_idx4].dst_x = 200;
	android_layer->layer[osd_idx4].dst_y = 200;
	android_layer->layer[osd_idx4].dst_height = dst_h4;
	android_layer->layer[osd_idx4].dst_width = dst_w4;
	android_layer->layer[osd_idx4].compressed = 0;
	android_layer->layer[osd_idx4].plane_ar = osdcmp_plane_ar;
	android_layer->layer[osd_idx4].plane_gb = osdcmp_plane_gb;
	osdcmp_clearx.x_sta = 0;
	osdcmp_clearx.x_end = 0;
	osdcmp_cleary.y_sta = 0;
	osdcmp_cleary.y_end = 0;
	android_layer->layer[osd_idx4].clear_x = osdcmp_clearx;
	android_layer->layer[osd_idx4].clear_y = osdcmp_cleary;
	android_layer->layer[osd_idx4].syncstamp = 0;
	android_layer->layer[osd_idx4].show = 1;
	android_layer->layer[osd_idx4].scale_factor = 1;

	/*  set the color order */
	/* android_layer->blend_mode = OSD1_OSD2_OSD3; */

	GDMA_ReceiveGraphicLayers(android_layer);

#endif

#if (_TEST_CODE_OSDCOMP_ == 5)

	int osd_idx1;
	VO_GRAPHIC_PLANE plane1;
	u32 dst_w1;
	u32 dst_h1;
	osd_idx1 = OSD1_1;
	plane1 = VO_GRAPHIC_OSD1;

	/*  one layers scaling + continue compress */
	dst_w1 = 1280;
	dst_h1 = 720;

	android_layer->layer_num = 1;

	android_layer->layer[osd_idx1].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_layer->layer[osd_idx1].context = 0; /*  ?? */
	android_layer->layer[osd_idx1].key_en = 0;
	android_layer->layer[osd_idx1].colorkey = -1;
	android_layer->layer[osd_idx1].alpha = 0x80;
	android_layer->layer[osd_idx1].x = 0;
	android_layer->layer[osd_idx1].y = 0;
	android_layer->layer[osd_idx1].height = 360;
	android_layer->layer[osd_idx1].width = 640;
	android_layer->layer[osd_idx1].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_layer->layer[osd_idx1].pitch = android_layer->layer[osd_idx1].width*4;
	/*android_layer->layer[osd_idx1].plane = plane1;*/
	android_layer->layer[osd_idx1].dst_x = 0;
	android_layer->layer[osd_idx1].dst_y = 0;
	android_layer->layer[osd_idx1].dst_height = dst_h1;
	android_layer->layer[osd_idx1].dst_width = dst_w1;
	android_layer->layer[osd_idx1].compressed = 1;
	/* android_layer->layer[osd_idx1].handle = 1; */

	/*  set the color order */
	android_layer->blend_mode = OSD1_OSD2_OSD3;

	GDMA_ReceiveGraphicLayers(android_layer);

#endif


#if 0
	pr_debug("osdcomp_test:: +++while loop \n");
	/*  wait for compress process */
	while (gdma->picCount[GDMA_PLANE_OSD1] == 0) {
		ssleep(1);
		pr_debug("while (gdma->picCount[GDMA_PLANE_OSD1] == 0)...loop \n");
	}
	pr_debug("osdcomp_test:: ---while loop \n");

	/*  force to set one */
	gdma->ctrl.sync[GDMA_PLANE_OSD1] = gdma->ctrl.sync[GDMA_PLANE_OSD2] = 1;

	/*  pointer to new image which was compressed by OSD compress */
	gdma->curPic[GDMA_PLANE_OSD1] = (gdma->picQrd[GDMA_PLANE_OSD1] + 1) & (GDMA_MAX_PIC_Q_SIZE - 1);
	gdma->curPic[GDMA_PLANE_OSD2] = (gdma->picQrd[GDMA_PLANE_OSD2] + 1) & (GDMA_MAX_PIC_Q_SIZE - 1);

	if (GDMA_Update (gdma, 0) == GDMA_SUCCESS)
		pr_debug("GDMA_Update:: Successfully \n");
#endif
}

void gdma_osdx_offline_test(unsigned int osdx)
{
	static VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN *create_win;
	static VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN *draw_win, *draw_win2, *draw_win3, *draw_win4, *draw_win5;

	/* int hs = 0, vs = 0, */
	int winID, winID2, winID3, winID4, winID5;
	/* gdma_dev *gdma = &gdma_devices[0]; */
	int iloop = 0, jloop = 0;
	static unsigned int *fillcolor = NULL, *fillcolor_osd2 = NULL;
	GDMA_WIN *win = NULL;
	u32 dst_w1, dst_w2, dst_w3, dst_w4, dst_w5, dst_w6;
	u32 dst_h1, dst_h2, dst_h3, dst_h4, dst_h5, dst_h6;
	u32 src_w1, src_w2, src_w3, src_w4, src_w5, src_w6;
	u32 src_h1, src_h2, src_h3, src_h4, src_h5, src_h6;

	if (draw_win == NULL)
		draw_win = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win2 == NULL)
		draw_win2 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win3 == NULL)
		draw_win3 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win4 == NULL)
		draw_win4 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win5 == NULL)
		draw_win5 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (create_win == NULL)
		create_win = kmalloc(sizeof(VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN), GFP_KERNEL);
	if (win == NULL)
		win = kmalloc(sizeof(GDMA_WIN), GFP_KERNEL);
	if (fillcolor == NULL)
		fillcolor = kmalloc(1280*720*4, GFP_KERNEL);
	if (fillcolor_osd2 == NULL)
		fillcolor_osd2 = kmalloc(1280*720*4, GFP_KERNEL);
	if (win == NULL || fillcolor == NULL || fillcolor_osd2 == NULL) {
		pr_debug(KERN_EMERG"malloc fail\n");
		return;
	}

	memset(draw_win, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win2, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win3, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win4, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win5, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(create_win, 0, sizeof(VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN));
	memset(win, 0, sizeof(GDMA_WIN));
	memset(fillcolor, 0xff, 1280*720);
	memset(fillcolor_osd2, 0xff, 1280*720);
	pr_debug(KERN_EMERG"memset = win=0x%x,fillcolor=0x%x\n", (unsigned int)win, (unsigned int)fillcolor);
	pr_debug(KERN_EMERG"virtual = win=0x%x,fillcolor=0x%x\n", virt_to_phys(win), virt_to_phys(fillcolor));
	pr_debug(KERN_EMERG"fillcolor_osd2=0x%x\n", virt_to_phys(fillcolor_osd2));

	for (iloop = 0; iloop < 1280*720; iloop++) {
		if (iloop < ((1280*720)/2)) {
			jloop = iloop%1280;
			if (jloop < 300)
				fillcolor[iloop] = 0xff0000ff;/* Red/RGBA */
			else if ((jloop >= 300) && (jloop < 600))
				fillcolor[iloop] = 0xff00ff00;/* Green */
			else if ((jloop >= 600) && (jloop < 1280))
				fillcolor[iloop] = 0xffff0000;/* Blue */
		} else {
			jloop = iloop%1280;
			if (jloop < 500)
				fillcolor[iloop] = 0xffff00ff;/* Red */
			else if ((jloop >= 500) && (jloop < 1000))
				fillcolor[iloop] = 0xffffffff;/* white */
			else if ((jloop >= 1000) && (jloop < 1280))
				fillcolor[iloop] = 0xff00ffff;/* yellow */
		}

		if (iloop < ((1280*720)/4))
			fillcolor_osd2[iloop] = 0xff7b7b7b;/* Red//RGBA, big-endian */
		else if (iloop >= ((1280*720)/4) && iloop < ((1280*720)/2))
			fillcolor_osd2[iloop] = 0xffffffff;
		else if (iloop >= ((1280*720)/2) && iloop < (((1280*720)/4)*3))
			fillcolor_osd2[iloop] = 0xff7b7b7b;
		else if (iloop >= (((1280*720)/4)*3) && iloop < (1280*720))
			fillcolor_osd2[iloop] = 0xffffffff;
	}


	src_w1 = 1280;
	src_h1 = 720;
	src_w2 = 1280;
	src_h2 = 720;
	src_w3 = 360;
	src_h3 = 240;
	src_w4 = 260;
	src_h4 = 200;
	src_w5 = 120;
	src_h5 = 160;

	if (osdx == VO_GRAPHIC_OSD1) {
		create_win->plane = VO_GRAPHIC_OSD1;
		create_win->winPos.x = 0;
		create_win->winPos.y = 0;
		create_win->winPos.height = src_h1;
		create_win->winPos.width = src_w1;
		create_win->colorFmt = VO_OSD_COLOR_FORMAT_RGBA8888;
		create_win->rgbOrder = VO_OSD_COLOR_RGB;
		create_win->colorKey = -1;
		create_win->compressed = 1;
		create_win->alpha = 0xff;
		winID = GDMA_CreateGraphicWindow(create_win);
		pr_debug("GDMA_CreateGraphicWindow:: OSD ID1=%d \n", winID);
	}
	if (osdx == VO_GRAPHIC_OSD2) {
		create_win->plane = VO_GRAPHIC_OSD2;
		create_win->winPos.x = 0;
		create_win->winPos.y = 0;
		create_win->winPos.height = src_h2;
		create_win->winPos.width = src_w2;
		create_win->colorFmt = VO_OSD_COLOR_FORMAT_RGBA8888;
		create_win->rgbOrder = VO_OSD_COLOR_RGB;
		create_win->colorKey = -1;
		create_win->compressed = 1;
		create_win->alpha = 0xff;
		winID2 = GDMA_CreateGraphicWindow(create_win);
		pr_debug("GDMA_CreateGraphicWindow:: OSD ID2=%d \n", winID2);
	}
	if (osdx == VO_GRAPHIC_OSD3) {
		create_win->plane = VO_GRAPHIC_OSD3;
		create_win->winPos.x = 0;
		create_win->winPos.y = 0;
		create_win->winPos.height = src_h3;
		create_win->winPos.width = src_w3;
		create_win->colorFmt = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		create_win->rgbOrder = VO_OSD_COLOR_RGB;
		create_win->colorKey = -1;
		create_win->compressed = 1;
		create_win->alpha = 0xff;
		winID2 = GDMA_CreateGraphicWindow(create_win);
		pr_debug("GDMA_CreateGraphicWindow:: OSD ID3=%d \n", winID3);
	}
	if (osdx == VO_GRAPHIC_OSD4) {
		create_win->plane = VO_GRAPHIC_OSD4;
		create_win->winPos.x = 0;
		create_win->winPos.y = 0;
		create_win->winPos.height = src_h4;
		create_win->winPos.width = src_w4;
		create_win->colorFmt = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		create_win->rgbOrder = VO_OSD_COLOR_RGB;
		create_win->colorKey = -1;
		create_win->compressed = 1;
		create_win->alpha = 0xff;
		winID2 = GDMA_CreateGraphicWindow(create_win);
		pr_debug("GDMA_CreateGraphicWindow:: OSD ID4=%d \n", winID4);
	}
	if (osdx == VO_GRAPHIC_OSD5) {
		create_win->plane = VO_GRAPHIC_OSD5;
		create_win->winPos.x = 0;
		create_win->winPos.y = 0;
		create_win->winPos.height = src_h5;
		create_win->winPos.width = src_w5;
		create_win->colorFmt = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		create_win->rgbOrder = VO_OSD_COLOR_RGB;
		create_win->colorKey = -1;
		create_win->compressed = 1;
		create_win->alpha = 0xff;
		winID2 = GDMA_CreateGraphicWindow(create_win);
		pr_debug("GDMA_CreateGraphicWindow:: OSD ID5=%d \n", winID5);
	}

	if (osdx == VO_GRAPHIC_OSD1) {
		draw_win->plane = VO_GRAPHIC_OSD1;
		draw_win->winID = winID;
		draw_win->storageMode = VO_GRAPHIC_SEQUENTIAL;
		draw_win->paletteIndex = 0;
		draw_win->compressed = 1;
		draw_win->interlace_Frame = 0;
		draw_win->bottomField = 0;
		draw_win->startX[0] = 0;
		draw_win->startY[0] = 0;
		draw_win->imgPitch[0] = src_w1*4;
		draw_win->pImage[0] = virt_to_phys(fillcolor);
		draw_win->go = 1;
		g_comp_offlineplane_test = VO_GRAPHIC_OSD1;
		g_comp_onlineplane_test = VO_GRAPHIC_OSD5;

		if (GDMA_DrawGraphicWindow(draw_win) == GDMA_SUCCESS)
			pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD1 Successfully \n");

		GDMA_DeleteGraphicWindow(winID, VO_GRAPHIC_OSD1, 1);
	}
	if (osdx == VO_GRAPHIC_OSD2) {
		draw_win2->plane = VO_GRAPHIC_OSD2;
		draw_win2->winID = winID2;
		draw_win2->storageMode = VO_GRAPHIC_SEQUENTIAL;
		draw_win2->paletteIndex = 0;
		draw_win2->compressed = 1;
		draw_win2->interlace_Frame = 0;
		draw_win2->bottomField = 0;
		draw_win2->startX[0] = 0;
		draw_win2->startY[0] = 0;
		draw_win2->imgPitch[0] = src_w2*4;
		draw_win2->pImage[0] = virt_to_phys(fillcolor_osd2);
		draw_win2->go = 1;
		g_comp_offlineplane_test = VO_GRAPHIC_OSD2;
		g_comp_onlineplane_test = VO_GRAPHIC_OSD5;

		if (GDMA_DrawGraphicWindow(draw_win2) == GDMA_SUCCESS)
			pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD2 Successfully \n");

		GDMA_DeleteGraphicWindow(winID2, VO_GRAPHIC_OSD2, 1);
	}
	if (osdx == VO_GRAPHIC_OSD3) {
		draw_win3->plane = VO_GRAPHIC_OSD3;
		draw_win3->winID = winID3;
		draw_win3->storageMode = VO_GRAPHIC_SEQUENTIAL;
		draw_win3->paletteIndex = 0;
		draw_win3->compressed = 1;
		draw_win3->interlace_Frame = 0;
		draw_win3->bottomField = 0;
		draw_win3->startX[0] = 0;
		draw_win3->startY[0] = 0;
		draw_win3->imgPitch[0] = src_w3*4;
		draw_win3->pImage[0] = virt_to_phys(lollipop_360x240);
		draw_win3->go = 1;
		g_comp_offlineplane_test = VO_GRAPHIC_OSD3;
		g_comp_onlineplane_test = VO_GRAPHIC_OSD5;

		if (GDMA_DrawGraphicWindow(draw_win3) == GDMA_SUCCESS)
			pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD3 Successfully \n");

		GDMA_DeleteGraphicWindow(winID3, VO_GRAPHIC_OSD3, 1);
	}
	if (osdx == VO_GRAPHIC_OSD4) {
		draw_win4->plane = VO_GRAPHIC_OSD4;
		draw_win4->winID = winID4;
		draw_win4->storageMode = VO_GRAPHIC_SEQUENTIAL;
		draw_win4->paletteIndex = 0;
		draw_win4->compressed = 1;
		draw_win4->interlace_Frame = 0;
		draw_win4->bottomField = 0;
		draw_win4->startX[0] = 0;
		draw_win4->startY[0] = 0;
		draw_win4->imgPitch[0] = src_w4*4;
		draw_win4->pImage[0] = virt_to_phys(gdma_rtk_logo_260x200);
		draw_win4->go = 1;
		g_comp_offlineplane_test = VO_GRAPHIC_OSD4;
		g_comp_onlineplane_test = VO_GRAPHIC_OSD5;

		if (GDMA_DrawGraphicWindow(draw_win4) == GDMA_SUCCESS)
			pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD4 Successfully \n");

		GDMA_DeleteGraphicWindow(winID4, VO_GRAPHIC_OSD4, 1);
	}
	if (osdx == VO_GRAPHIC_OSD5) {
		draw_win5->plane = VO_GRAPHIC_OSD5;
		draw_win5->winID = winID5;
		draw_win5->storageMode = VO_GRAPHIC_SEQUENTIAL;
		draw_win5->paletteIndex = 0;
		draw_win5->compressed = 1;
		draw_win5->interlace_Frame = 0;
		draw_win5->bottomField = 0;
		draw_win5->startX[0] = 0;
		draw_win5->startY[0] = 0;
		draw_win5->imgPitch[0] = src_w5*4;
		draw_win5->pImage[0] = virt_to_phys(mycursor_120x160);
		draw_win5->go = 1;
		g_comp_offlineplane_test = VO_GRAPHIC_OSD5;
		g_comp_onlineplane_test = VO_GRAPHIC_OSD4;

		if (GDMA_DrawGraphicWindow(draw_win5) == GDMA_SUCCESS)
			pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD5 Successfully \n");

		GDMA_DeleteGraphicWindow(winID5, VO_GRAPHIC_OSD5, 1);
	}

}

void osdComp_multiQThread_test(unsigned int arg)
{
	int iloop = 0, jloop = 0, compress = 0;
	gdma_dev *gdma = &gdma_devices[0];
	dma_addr_t addr1, addr2, addr3, addr4;
	static unsigned int *fillcolor = NULL;
	static unsigned int *fillcolor_osd2 = NULL;
	static unsigned int *fillcolor_osd3 = NULL;
	static unsigned char *fillcursor = NULL;

	osd_planealpha_ar osdcmp_plane_ar;
	osd_planealpha_gb osdcmp_plane_gb;
	osd_clear_x osdcmp_clearx;
	osd_clear_y osdcmp_cleary;

	int osd_idx1, osd_idx2, osd_idx3;
	VO_GRAPHIC_PLANE plane1, plane2;/* , plane3; */
	u32 dst_w1, dst_w2, dst_w3, dst_w4, dst_w5, dst_w6;
	u32 dst_h1, dst_h2, dst_h3, dst_h4, dst_h5, dst_h6;
	u32 src_w1, src_w2, src_w3, src_w4, src_w5, src_w6;
	u32 src_h1, src_h2, src_h3, src_h4, src_h5, src_h6;
	int div;
	static struct task_struct *thread1, *thread2, *thread3;
	char our_thread1[8] = "compthread1";
	char our_thread2[8] = "compthread2";
	char our_thread3[8] = "compthread3";

	osdcmp_clearx.value = 0;
	osdcmp_cleary.value = 0;

	if (fillcolor == NULL)
		fillcolor = kmalloc(1280*720*4, GFP_KERNEL);
	if (fillcolor_osd2 == NULL)
		fillcolor_osd2 = kmalloc(1280*720*4, GFP_KERNEL);
	if (fillcolor_osd3 == NULL)
		fillcolor_osd3 = kmalloc(640*360*4, GFP_KERNEL);
	if (fillcursor == NULL)
		fillcursor = kmalloc(256*256, GFP_KERNEL);
	if (g_OSDPalettePattern == NULL)
		g_OSDPalettePattern =  kmalloc(256*4, GFP_KERNEL);
	if (android_test_layer1 == NULL)
		android_test_layer1 = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);
	if (android_test_layer2 == NULL)
		android_test_layer2 = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);
	if (android_test_layer3 == NULL)
		android_test_layer3 = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);
	if (pic_test_layer1 == NULL)
		pic_test_layer1 = kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (pic_test_layer2 == NULL)
		pic_test_layer2 = kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (pic_test_layer3 == NULL)
		pic_test_layer3 = kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);

	if (fillcolor == NULL || fillcolor_osd2 == NULL || fillcursor == NULL ||
		android_test_layer3 == NULL || fillcolor_osd3 == NULL || android_test_layer1 == NULL ||
		g_OSDPalettePattern == NULL || android_test_layer2 == NULL ||
		pic_test_layer1 == NULL || pic_test_layer2 == NULL || pic_test_layer3 == NULL) {
		pr_debug(KERN_EMERG"malloc fail\n");
		return;
	}
	memset(android_test_layer1, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
	memset(android_test_layer2, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
	memset(android_test_layer3, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
	memset(pic_test_layer1, 0, sizeof(PICTURE_LAYERS_OBJECT));
	memset(pic_test_layer2, 0, sizeof(PICTURE_LAYERS_OBJECT));
	memset(pic_test_layer3, 0, sizeof(PICTURE_LAYERS_OBJECT));
	memset((void *)fillcolor, 0xff, 1280*720*4);
	memset((void *)fillcolor_osd2, 0xff, 1280*720*4);
	memset((void *)fillcolor_osd3, 0xff, 640*360*4);
	memset((void *)fillcursor, 0xff, 256*256);
	memset(g_OSDPalettePattern, 0x00, 256*4);
	pr_debug(KERN_EMERG"Virtual fillcolor=0x%x,fillcolor_osd2=0x%x,fillcolor_osd3=0x%x\n", (uint32_t)fillcolor, (uint32_t)fillcolor_osd2, (uint32_t)fillcolor_osd3);
	pr_debug(KERN_EMERG"Physical fillcolor=0x%x\n", virt_to_phys(fillcolor));
	pr_debug(KERN_EMERG"Physical fillcolor_osd2=0x%x\n", virt_to_phys(fillcolor_osd2));
	pr_debug(KERN_EMERG"Physical fillcolor_osd3=0x%x\n", virt_to_phys(fillcolor_osd3));

	dsb();
	addr1 = dma_map_single(gdma->dev, (void *)fillcolor, 1280*720*4, DMA_TO_DEVICE);
	addr2 = dma_map_single(gdma->dev, (void *)fillcolor_osd2, 1280*720*4, DMA_TO_DEVICE);
	addr3 = dma_map_single(gdma->dev, (void *)fillcolor_osd3, 640*360*4, DMA_TO_DEVICE);
	addr4 = dma_map_single(gdma->dev, (void *)fillcursor, 256*256, DMA_TO_DEVICE);

	if (dma_mapping_error(gdma->dev, addr1))
		pr_debug("dma_map_single fail addr1 \n");
	if (dma_mapping_error(gdma->dev, addr2))
		pr_debug("dma_map_single fail addr2 \n");
	if (dma_mapping_error(gdma->dev, addr3))
		pr_debug("dma_map_single fail addr3 \n");
	if (dma_mapping_error(gdma->dev, addr4))
		pr_debug("dma_map_single fail addr4 \n");

	for (iloop = 0; iloop < 256*256; iloop++) {
		fillcursor[iloop] = 0;
	}
	for (iloop = 0; iloop < 256; iloop++) {
		g_OSDPalettePattern[iloop] = 0xFF0000FF;
	}
	memcpy (gdma->OSD_CLUT[0], (void *)(g_OSDPalettePattern), sizeof(unsigned int) * 256);

	/*  make image source */
	div = ((640 * 360) / 10);
	for (iloop = 0; iloop < 1280*720; iloop++) {
		if (iloop < ((1280*720)/2)) {
			jloop = iloop%1280;
			if (jloop < 300)
				fillcolor[iloop] = 0xff0000ff;/* Red//RGBA, big-endian */
			else if ((jloop >= 300) && (jloop < 600))
				fillcolor[iloop] = 0xff00ff00;/* Green */
			else if ((jloop >= 600) && (jloop < 1280))
				fillcolor[iloop] = 0xffff0000;/* Blue */
		} else {
			jloop = iloop%1280;
			if (jloop < 500)
				fillcolor[iloop] = 0xffff00ff;/* Red */
			else if ((jloop >= 500) && (jloop < 1000))
				fillcolor[iloop] = 0xffffffff;/* white */
			else if ((jloop >= 1000) && (jloop < 1280))
				fillcolor[iloop] = 0xff00ffff;/* yellow */
		}

		if (iloop < ((1280*720)/4))
			fillcolor_osd2[iloop] = 0xff7b7b7b;/* Red//RGBA, big-endian */
		else if (iloop >= ((1280*720)/4) && iloop < ((1280*720)/2))
			fillcolor_osd2[iloop] = 0xffffffff;
		else if (iloop >= ((1280*720)/2) && iloop < (((1280*720)/4)*3))
			fillcolor_osd2[iloop] = 0xff7b7b7b;
		else if (iloop >= (((1280*720)/4)*3) && iloop < (1280*720))
			fillcolor_osd2[iloop] = 0xffffffff;

		if (iloop < div)
			fillcolor_osd3[iloop] = 0xff0000ff;/* Red//RGBA, big-endian */
		else if (iloop >= (div * 1) && iloop < (div * 2))
			fillcolor_osd3[iloop] = 0xff00ffff;
		else if (iloop >= (div * 2) && iloop < (div * 3))
			fillcolor_osd3[iloop] = 0xffffffff;
		else if (iloop >= (div * 3) && iloop < (div * 4))
			fillcolor_osd3[iloop] = 0xffff0000;
		else if (iloop >= (div * 4) && iloop < (div * 5))
			fillcolor_osd3[iloop] = 0xff7b7b7b;
		else if (iloop >= (div * 5) && iloop < (div * 6))
			fillcolor_osd3[iloop] = 0xffff00ff;
		else if (iloop >= (div * 6) && iloop < (div * 7))
			fillcolor_osd3[iloop] = 0xff000000;
		else if (iloop >= (div * 7) && iloop < (div * 8))
			fillcolor_osd3[iloop] = 0xff808080;
		else if (iloop >= (div * 8) && iloop < (div * 9))
			fillcolor_osd3[iloop] = 0xff404040;
		else if (iloop >= (div * 9) && iloop < (div * 10))
			fillcolor_osd3[iloop] = 0xffa0a0a0;
	}

	dma_sync_single_for_device(gdma->dev, addr1, 1280*720*4, DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr2, 1280*720*4, DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr3, 640*360*4, DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr4, 256*256, DMA_TO_DEVICE);

	dma_unmap_single(gdma->dev, addr1, 1280*720*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr2, 1280*720*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr3, 640*360*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr4, 256*256, DMA_TO_DEVICE);

	osdcmp_plane_ar.plane_alpha_r = 0xff;
	osdcmp_plane_ar.plane_alpha_a = 0xff;
	osdcmp_plane_gb.plane_alpha_g = 0xff;
	osdcmp_plane_gb.plane_alpha_b = 0xff;


	osd_idx1 = OSD1_1;
	osd_idx2 = OSD1_2;
	osd_idx3 = OSD1_3;
	/* osd_idx3 = OSD1_3; */
	plane1 = VO_GRAPHIC_OSD1;
	plane2 = VO_GRAPHIC_OSD2;
	/* plane3 = VO_GRAPHIC_OSD3; */

	/* compressed test flag */
	compress = 0;

	/*  thread1: 2 layers: normal */
	src_w1 = 1280;
	src_h1 = 720;
	dst_w1 = gdma->dispWin[0].width;
	dst_h1 = gdma->dispWin[0].height;
	src_w2 = 260;
	src_h2 = 200;
	dst_w2 = 260;
	dst_h2 = 200;
	src_w3 = 120;
	src_h3 = 160;
	dst_w3 = 120;
	dst_h3 = 160;

	android_test_layer1->layer_num = 3;

	/*g_sleeptime = arg;*/

	android_test_layer1->layer[osd_idx1].src_type = SRC_NORMAL;
	android_test_layer1->layer[osd_idx1].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer1->layer[osd_idx1].context = 0; /*  ?? */
	android_test_layer1->layer[osd_idx1].key_en = 0;
	android_test_layer1->layer[osd_idx1].colorkey = -1;
	android_test_layer1->layer[osd_idx1].alpha = 0x80;
	android_test_layer1->layer[osd_idx1].x = 0;
	android_test_layer1->layer[osd_idx1].y = 0;
	android_test_layer1->layer[osd_idx1].height = src_h1;
	android_test_layer1->layer[osd_idx1].width = src_w1;
	android_test_layer1->layer[osd_idx1].address = (unsigned int)virt_to_phys(fillcolor);
	android_test_layer1->layer[osd_idx1].pitch = android_test_layer1->layer[osd_idx1].width*4;
	android_test_layer1->layer[osd_idx1].dst_x = 0;
	android_test_layer1->layer[osd_idx1].dst_y = 0;
	android_test_layer1->layer[osd_idx1].dst_height = dst_h1;
	android_test_layer1->layer[osd_idx1].dst_width = dst_w1;
	android_test_layer1->layer[osd_idx1].compressed = compress;    /*compress test*/
	android_test_layer1->layer[osd_idx1].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[osd_idx1].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[osd_idx1].clear_x = osdcmp_clearx;
	android_test_layer1->layer[osd_idx1].clear_y = osdcmp_cleary;
	android_test_layer1->layer[osd_idx1].syncstamp = 0;
	android_test_layer1->layer[osd_idx1].show = 1;

	android_test_layer1->layer[osd_idx2].src_type = SRC_NORMAL;
	android_test_layer1->layer[osd_idx2].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[osd_idx2].context = 0; /*  ?? */
	android_test_layer1->layer[osd_idx2].key_en = 0;
	android_test_layer1->layer[osd_idx2].colorkey = -1;
	android_test_layer1->layer[osd_idx2].alpha = 0xff;
	android_test_layer1->layer[osd_idx2].x = 0;
	android_test_layer1->layer[osd_idx2].y = 0;
	android_test_layer1->layer[osd_idx2].height = src_h2;
	android_test_layer1->layer[osd_idx2].width = src_w2;
	android_test_layer1->layer[osd_idx2].address = (unsigned int)virt_to_phys(gdma_rtk_logo_260x200);
	android_test_layer1->layer[osd_idx2].pitch = android_test_layer1->layer[osd_idx2].width*4;
	android_test_layer1->layer[osd_idx2].dst_x = 0;
	android_test_layer1->layer[osd_idx2].dst_y = 0;
	android_test_layer1->layer[osd_idx2].dst_height = dst_h2;
	android_test_layer1->layer[osd_idx2].dst_width = dst_w2;
	android_test_layer1->layer[osd_idx2].compressed = compress;
	android_test_layer1->layer[osd_idx2].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[osd_idx2].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[osd_idx2].clear_x = osdcmp_clearx;
	android_test_layer1->layer[osd_idx2].clear_y = osdcmp_cleary;
	android_test_layer1->layer[osd_idx2].syncstamp = 0;
	android_test_layer1->layer[osd_idx2].show = 1;

	android_test_layer1->layer[osd_idx3].src_type = SRC_NORMAL;
	android_test_layer1->layer[osd_idx3].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[osd_idx3].context = 0; /*  ?? */
	android_test_layer1->layer[osd_idx3].key_en = 0;
	android_test_layer1->layer[osd_idx3].colorkey = -1;
	android_test_layer1->layer[osd_idx3].alpha = 0x80;
	android_test_layer1->layer[osd_idx3].x = 0;
	android_test_layer1->layer[osd_idx3].y = 0;
	android_test_layer1->layer[osd_idx3].height = src_h3;
	android_test_layer1->layer[osd_idx3].width = src_w3;
	android_test_layer1->layer[osd_idx3].address = (unsigned int)virt_to_phys(mycursor_120x160);
	android_test_layer1->layer[osd_idx3].pitch = android_test_layer1->layer[osd_idx3].width*4;
	android_test_layer1->layer[osd_idx3].dst_x = 0;
	android_test_layer1->layer[osd_idx3].dst_y = 0;
	android_test_layer1->layer[osd_idx3].dst_height = dst_h3;
	android_test_layer1->layer[osd_idx3].dst_width = dst_w3;
	android_test_layer1->layer[osd_idx3].compressed = compress;
	android_test_layer1->layer[osd_idx3].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[osd_idx3].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[osd_idx3].clear_x = osdcmp_clearx;
	android_test_layer1->layer[osd_idx3].clear_y = osdcmp_cleary;
	android_test_layer1->layer[osd_idx3].syncstamp = 0;
	android_test_layer1->layer[osd_idx3].show = 1;

	pic_test_layer1->layer_num = 1;
	pic_test_layer1->layer[0].normal_num = 2;
	GDMA_CopyLayerInfo(&pic_test_layer1->layer[0].normal[0], &android_test_layer1->layer[osd_idx1]);
	GDMA_CopyLayerInfo(&pic_test_layer1->layer[0].normal[1], &android_test_layer1->layer[osd_idx2]);
	pic_test_layer1->layer[0].normal[0].src_type = SRC_NORMAL;
	pic_test_layer1->layer[0].normal[1].src_type = SRC_NORMAL;
	pic_test_layer1->layer[0].normal[0].comp_plane = VO_GRAPHIC_OSD3;
	pic_test_layer1->layer[0].normal[1].comp_plane = VO_GRAPHIC_OSD5;
	pic_test_layer1->layer[0].normal[0].plane = VO_GRAPHIC_OSD4;
	pic_test_layer1->layer[0].normal[1].plane = VO_GRAPHIC_OSD4;
	pic_test_layer1->layer[0].normal[0].wbType = RTKCOMPRESS;
	pic_test_layer1->layer[0].normal[1].wbType = RTKCOMPRESS;
	pic_test_layer1->layer[0].normal[0].compressed = 1;
	pic_test_layer1->layer[0].normal[1].compressed = 1;
	pic_test_layer1->layer[0].normal[0].offlineOrder = C0;
	pic_test_layer1->layer[0].normal[1].offlineOrder = C1;
	/*osd_comp_pre_receive_picture(pic_test_layer1);*/

	/*  thread2: 6 layers */
	src_w1 = 1280;
	src_h1 = 720;
	dst_w1 = 1280;
	dst_h1 = 720;
	src_w2 = 640;
	src_h2 = 360;
	dst_w2 = 1280;
	dst_h2 = 720;
	src_w3 = 1280;
	src_h3 = 720;
	dst_w3 = 1280;
	dst_h3 = 720;
	src_w4 = 256;
	src_h4 = 256;
	dst_w4 = 256;
	dst_h4 = 256;
	src_w5 = 260;
	src_h5 = 200;
	dst_w5 = 260;
	dst_h5 = 200;
	src_w6 = 120;
	src_h6 = 160;
	dst_w6 = 120;
	dst_h6 = 160;


	android_test_layer2->layer_num = 2;
	android_test_layer2->layer[0].src_type = SRC_NORMAL;
	android_test_layer2->layer[0].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer2->layer[0].context = 0; /*  ?? */
	android_test_layer2->layer[0].key_en = 0;
	android_test_layer2->layer[0].colorkey = -1;
	android_test_layer2->layer[0].alpha = 0x80;
	android_test_layer2->layer[0].x = 0;
	android_test_layer2->layer[0].y = 0;
	android_test_layer2->layer[0].height = src_h1;
	android_test_layer2->layer[0].width = src_w1;
	android_test_layer2->layer[0].address = (unsigned int)virt_to_phys(fillcolor_osd2);
	android_test_layer2->layer[0].pitch = android_test_layer2->layer[0].width*4;
	android_test_layer2->layer[0].dst_x = 0;
	android_test_layer2->layer[0].dst_y = 0;
	android_test_layer2->layer[0].dst_height = dst_h1;
	android_test_layer2->layer[0].dst_width = dst_w1;
	android_test_layer2->layer[0].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[0].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[0].clear_x = osdcmp_clearx;
	android_test_layer2->layer[0].clear_y = osdcmp_cleary;
	android_test_layer2->layer[0].syncstamp = 0;
	android_test_layer2->layer[0].show = 1;
	android_test_layer2->layer[0].compressed = compress;

	android_test_layer2->layer[1].src_type = SRC_NORMAL;
	android_test_layer2->layer[1].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer2->layer[1].context = 0; /*  ?? */
	android_test_layer2->layer[1].key_en = 0;
	android_test_layer2->layer[1].colorkey = -1;
	android_test_layer2->layer[1].alpha = 0x80;
	android_test_layer2->layer[1].x = 0;
	android_test_layer2->layer[1].y = 0;
	android_test_layer2->layer[1].height = src_h2;
	android_test_layer2->layer[1].width = src_w2;
	android_test_layer2->layer[1].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_test_layer2->layer[1].pitch = android_test_layer2->layer[1].width*4;
	android_test_layer2->layer[1].dst_x = 100;
	android_test_layer2->layer[1].dst_y = 100;
	android_test_layer2->layer[1].dst_height = dst_h2;
	android_test_layer2->layer[1].dst_width = dst_w2;
	android_test_layer2->layer[1].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[1].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[1].clear_x = osdcmp_clearx;
	android_test_layer2->layer[1].clear_y = osdcmp_cleary;
	android_test_layer2->layer[1].syncstamp = 0;
	android_test_layer2->layer[1].show = 1;
	android_test_layer2->layer[1].compressed = compress;

	android_test_layer2->layer[2].src_type = SRC_NORMAL;
	android_test_layer2->layer[2].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer2->layer[2].context = 0; /*  ?? */
	android_test_layer2->layer[2].key_en = 0;
	android_test_layer2->layer[2].colorkey = -1;
	android_test_layer2->layer[2].alpha = 0x80;
	android_test_layer2->layer[2].x = 0;
	android_test_layer2->layer[2].y = 0;
	android_test_layer2->layer[2].height = src_h3;
	android_test_layer2->layer[2].width = src_w3;
	android_test_layer2->layer[2].address = (unsigned int)virt_to_phys(fillcolor_osd2);
	android_test_layer2->layer[2].pitch = android_test_layer2->layer[2].width*4;
	android_test_layer2->layer[2].dst_x = 200;
	android_test_layer2->layer[2].dst_y = 200;
	android_test_layer2->layer[2].dst_height = dst_h3;
	android_test_layer2->layer[2].dst_width = dst_w3;
	android_test_layer2->layer[2].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[2].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[2].clear_x = osdcmp_clearx;
	android_test_layer2->layer[2].clear_y = osdcmp_cleary;
	android_test_layer2->layer[2].syncstamp = 0;
	android_test_layer2->layer[2].show = 1;
	android_test_layer2->layer[2].compressed = compress;

	android_test_layer2->layer[3].src_type = SRC_NORMAL;
	android_test_layer2->layer[3].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer2->layer[3].context = 0; /*  ?? */
	android_test_layer2->layer[3].key_en = 0;
	android_test_layer2->layer[3].colorkey = -1;
	android_test_layer2->layer[3].alpha = 0x80;
	android_test_layer2->layer[3].x = 0;
	android_test_layer2->layer[3].y = 0;
	android_test_layer2->layer[3].height = src_h4;
	android_test_layer2->layer[3].width = src_w4;
	android_test_layer2->layer[3].address = (unsigned int)virt_to_phys(fillcursor);
	android_test_layer2->layer[3].pitch = android_test_layer2->layer[3].width*4;
	android_test_layer2->layer[3].dst_x = 300;
	android_test_layer2->layer[3].dst_y = 300;
	android_test_layer2->layer[3].dst_height = dst_h4;
	android_test_layer2->layer[3].dst_width = dst_w4;
	android_test_layer2->layer[3].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[3].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[3].clear_x = osdcmp_clearx;
	android_test_layer2->layer[3].clear_y = osdcmp_cleary;
	android_test_layer2->layer[3].syncstamp = 0;
	android_test_layer2->layer[3].show = 1;
	android_test_layer2->layer[3].compressed = compress;

	android_test_layer2->layer[4].src_type = SRC_NORMAL;
	android_test_layer2->layer[4].format = VO_OSD_COLOR_FORMAT_ARGB8888;
	android_test_layer2->layer[4].context = 0; /*  ?? */
	android_test_layer2->layer[4].key_en = 0;
	android_test_layer2->layer[4].colorkey = -1;
	android_test_layer2->layer[4].alpha = 0x80;
	android_test_layer2->layer[4].x = 0;
	android_test_layer2->layer[4].y = 0;
	android_test_layer2->layer[4].height = src_h5;
	android_test_layer2->layer[4].width = src_w5;
	android_test_layer2->layer[4].address = (unsigned int)virt_to_phys(gdma_rtk_logo_260x200);
	android_test_layer2->layer[4].pitch = android_test_layer2->layer[4].width*4;
	android_test_layer2->layer[4].dst_x = 500;
	android_test_layer2->layer[4].dst_y = 500;
	android_test_layer2->layer[4].dst_height = dst_h5;
	android_test_layer2->layer[4].dst_width = dst_w5;
	android_test_layer2->layer[4].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[4].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[4].clear_x = osdcmp_clearx;
	android_test_layer2->layer[4].clear_y = osdcmp_cleary;
	android_test_layer2->layer[4].syncstamp = 0;
	android_test_layer2->layer[4].show = 1;
	android_test_layer2->layer[4].compressed = compress;

	android_test_layer2->layer[5].src_type = SRC_MOUSE_NORMAL;
	android_test_layer2->layer[5].format = VO_OSD_COLOR_FORMAT_ARGB8888;
	android_test_layer2->layer[5].context = 0; /*  ?? */
	android_test_layer2->layer[5].key_en = 0;
	android_test_layer2->layer[5].colorkey = -1;
	android_test_layer2->layer[5].alpha = 0x80;
	android_test_layer2->layer[5].x = 0;
	android_test_layer2->layer[5].y = 0;
	android_test_layer2->layer[5].height = src_h6;
	android_test_layer2->layer[5].width = src_w6;
	android_test_layer2->layer[5].address = (unsigned int)virt_to_phys(mycursor_120x160);
	android_test_layer2->layer[5].pitch = android_test_layer2->layer[5].width*4;
	android_test_layer2->layer[5].dst_x = 600;
	android_test_layer2->layer[5].dst_y = 600;
	android_test_layer2->layer[5].dst_height = dst_h6;
	android_test_layer2->layer[5].dst_width = dst_w6;
	android_test_layer2->layer[5].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[5].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[5].clear_x = osdcmp_clearx;
	android_test_layer2->layer[5].clear_y = osdcmp_cleary;
	android_test_layer2->layer[5].syncstamp = 0;
	android_test_layer2->layer[5].show = 1;
	android_test_layer2->layer[5].compressed = compress;


	pic_test_layer2->layer_num = 1;
	pic_test_layer2->layer[0].normal_num = 2;
	GDMA_CopyLayerInfo(&pic_test_layer2->layer[0].normal[0], &android_test_layer2->layer[0]);
	GDMA_CopyLayerInfo(&pic_test_layer2->layer[0].normal[1], &android_test_layer2->layer[1]);
	pic_test_layer2->layer[0].normal[0].src_type = SRC_NORMAL;
	pic_test_layer2->layer[0].normal[1].src_type = SRC_NORMAL;
	pic_test_layer2->layer[0].normal[0].comp_plane = VO_GRAPHIC_OSD3;
	pic_test_layer2->layer[0].normal[1].comp_plane = VO_GRAPHIC_OSD5;
	pic_test_layer2->layer[0].normal[0].plane = VO_GRAPHIC_OSD1;
	pic_test_layer2->layer[0].normal[1].plane = VO_GRAPHIC_OSD1;
	pic_test_layer2->layer[0].normal[0].wbType = ARGB8888;
	pic_test_layer2->layer[0].normal[1].wbType = ARGB8888;
	pic_test_layer2->layer[0].normal[0].compressed = 1;
	pic_test_layer2->layer[0].normal[1].compressed = 1;
	pic_test_layer2->layer[0].normal[0].offlineOrder = C0;
	pic_test_layer2->layer[0].normal[1].offlineOrder = C1;
	/*osd_comp_pre_receive_picture(pic_test_layer2);*/

	/*  thread3: osd2 */
	src_w1 = 360;
	src_h1 = 240;
	dst_w1 = 360;
	dst_h1 = 240;


	android_test_layer3->layer_num = 1;

	android_test_layer3->layer[osd_idx1].src_type = SRC_NORMAL;
	android_test_layer3->layer[osd_idx1].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer3->layer[osd_idx1].context = 0; /*  ?? */
	android_test_layer3->layer[osd_idx1].key_en = 0;
	android_test_layer3->layer[osd_idx1].colorkey = -1;
	android_test_layer3->layer[osd_idx1].alpha = 0x80;
	android_test_layer3->layer[osd_idx1].x = 0;
	android_test_layer3->layer[osd_idx1].y = 0;
	android_test_layer3->layer[osd_idx1].height = src_h1;
	android_test_layer3->layer[osd_idx1].width = src_w1;
	android_test_layer3->layer[osd_idx1].address = (unsigned int)virt_to_phys(lollipop_360x240);
	android_test_layer3->layer[osd_idx1].pitch = android_test_layer3->layer[osd_idx1].width*4;
	android_test_layer3->layer[osd_idx1].dst_x = 0;
	android_test_layer3->layer[osd_idx1].dst_y = 0;
	android_test_layer3->layer[osd_idx1].dst_height = dst_h1;
	android_test_layer3->layer[osd_idx1].dst_width = dst_w1;
	android_test_layer3->layer[osd_idx1].compressed = compress;
	android_test_layer3->layer[osd_idx1].plane_ar = osdcmp_plane_ar;
	android_test_layer3->layer[osd_idx1].plane_gb = osdcmp_plane_gb;
	android_test_layer3->layer[osd_idx1].clear_x = osdcmp_clearx;
	android_test_layer3->layer[osd_idx1].clear_y = osdcmp_cleary;
	android_test_layer3->layer[osd_idx1].syncstamp = 0;
	android_test_layer3->layer[osd_idx1].show = 1;
	android_test_layer3->layer[osd_idx1].compressed = compress;

	pic_test_layer3->layer_num = 1;
	pic_test_layer3->layer[0].normal_num = 1;
	GDMA_CopyLayerInfo(&pic_test_layer3->layer[0].normal[0], &android_test_layer3->layer[osd_idx1]);
	pic_test_layer3->layer[0].normal[0].src_type = SRC_NORMAL;
	pic_test_layer3->layer[0].normal[0].comp_plane = VO_GRAPHIC_OSD3;
	pic_test_layer3->layer[0].normal[0].plane = VO_GRAPHIC_OSD4;
	pic_test_layer3->layer[0].normal[0].wbType = RTKCOMPRESS;
	pic_test_layer3->layer[0].normal[0].compressed = 1;
	pic_test_layer3->layer[0].normal[0].offlineOrder = C0;
	/*osd_comp_pre_receive_picture(pic_test_layer3);*/

	pr_debug(KERN_EMERG "in osdcomp init");
	thread1 = kthread_create(osdcompthread1_fn, NULL, our_thread1);
	thread2 = kthread_create(osdcompthread2_fn, NULL, our_thread2);
	thread3 = kthread_create(osdcompthread3_fn, NULL, our_thread3);
	if ((thread1)) {
		pr_debug(KERN_EMERG "in comp if1\n");
		wake_up_process(thread1);
	}
	if ((thread2)) {
		pr_debug(KERN_EMERG "in comp if2\n");
		wake_up_process(thread2);
	}
	if ((thread3)) {
		pr_debug(KERN_EMERG "in comp if3\n");
		wake_up_process(thread3);
	}

}


#endif



#ifdef _TEST_CODE_GDMA_

void gdma_test(void)
{
	int hs = 0, vs = 0, canvasW, canvasH, hdphs, vdphs, hout, vout;
	gdma_dev *gdma = &gdma_devices[0];
	int iloop = 0, jloop = 0;
	unsigned int *fillcolor = NULL;
	unsigned int *fillcolor_osd2 = NULL;
	GDMA_WIN *win = NULL, *win2 = NULL;
	win = kmalloc(sizeof(GDMA_WIN), GFP_KERNEL);
	win2 = kmalloc(sizeof(GDMA_WIN), GFP_KERNEL);
	fillcolor = kmalloc(1280*720*4, GFP_KERNEL);
	fillcolor_osd2 = kmalloc(1280*720*4, GFP_KERNEL);
	if (win == NULL || fillcolor == NULL || fillcolor_osd2 == NULL ||
		win2 == NULL) {
		pr_debug(KERN_EMERG"malloc fail\n");
		return;
	}
	memset(win, 0, sizeof(GDMA_WIN));
	memset(win2, 0, sizeof(GDMA_WIN));
	memset(fillcolor, 0xff, 1280*720);
	memset(fillcolor_osd2, 0xff, 1280*720);
	pr_debug(KERN_EMERG"memset = win=0x%x,fillcolor=0x%x\n", win, fillcolor);
	pr_debug(KERN_EMERG"virtual = win=0x%x,fillcolor=0x%x\n", virt_to_phys(win), virt_to_phys(fillcolor));
	pr_debug(KERN_EMERG"virtual = win2=0x%x,fillcolor_osd2=0x%x\n", virt_to_phys(win2), virt_to_phys(fillcolor_osd2));

	for (iloop = 0; iloop < 1280*720; iloop++) {
		if (iloop < ((1280*720)/2)) {
			jloop = iloop%1280;
			if (jloop < 300)
				fillcolor[iloop] = 0xff0000ff;/* Red/ RGBA */
			else if ((jloop >= 300) && (jloop < 600))
				fillcolor[iloop] = 0xff00ff00;/* Green */
			else if ((jloop >= 600) && (jloop < 1280))
				fillcolor[iloop] = 0xffff0000;/* Blue */
		} else {
			jloop = iloop%1280;
			if (jloop < 500)
				fillcolor[iloop] = 0xffff00ff;/* Red */
			else if ((jloop >= 500) && (jloop < 1000))
				fillcolor[iloop] = 0xffffffff;/* white */
			else if ((jloop >= 1000) && (jloop < 1280))
				fillcolor[iloop] = 0xff00ffff;/* yellow */
		}

		if (iloop < ((1280*720)/4))
			fillcolor_osd2[iloop] = 0xff7b7b7b;/* Red/RGBA, big-endian */
		else if (iloop >= ((1280*720)/4) && iloop < ((1280*720)/2))
			fillcolor_osd2[iloop] = 0xffffffff;
		else if (iloop >= ((1280*720)/2) && iloop < (((1280*720)/4)*3))
			fillcolor_osd2[iloop] = 0xff7b7b7b;
		else if (iloop >= (((1280*720)/4)*3) && iloop < (1280*720))
			fillcolor_osd2[iloop] = 0xffffffff;
	}

	win->nxtAddr.addr     = 0;
	win->nxtAddr.last     = 1;
	win->winXY.x          = 0;
	win->winXY.y          = 0;
	win->winWH.width      = 1280;
	win->winWH.height     = 720;
	win->attr.extendMode  = 0;
	win->attr.rgbOrder    = 0;
	win->attr.objType     = 0;
	win->attr.type        = 0xf;
	win->attr.littleEndian = 0;
	win->top_addr         = virt_to_phys(fillcolor);
	win->pitch            = 1280*4;

	win2->nxtAddr.addr     = 0;
	win2->nxtAddr.last     = 1;
	win2->winXY.x          = 0;
	win2->winXY.y          = 0;
	win2->winWH.width      = 1280;
	win2->winWH.height     = 720;
	win2->attr.extendMode  = 0;
	win2->attr.rgbOrder    = 0;
	win2->attr.objType     = 0;
	win2->attr.type        = 0xf;
	win2->attr.littleEndian = 0;
	win2->top_addr         = virt_to_phys(fillcolor_osd2);
	win2->pitch            = 1280*4;

	rtd_outl(GDMA_OSD1_reg, ~1);
	rtd_outl(GDMA_OSD1_reg, 0x10001);
	rtd_outl(GDMA_OSD1_CTRL_reg, ~1);
	rtd_outl(GDMA_OSD1_WI_reg, (virt_to_phys(win) & ~0xe0000000));
	rtd_outl(GDMA_OSD1_SIZE_reg, 0x050002d0);

	rtd_outl(GDMA_OSD2_reg, ~1);
	rtd_outl(GDMA_OSD2_reg, 0x10001);
	rtd_outl(GDMA_OSD2_CTRL_reg, ~1);
	rtd_outl(GDMA_OSD2_WI_reg, (virt_to_phys(win2) & ~0xe0000000));
	rtd_outl(GDMA_OSD2_SIZE_reg, 0x050002d0);



	/*rtd_outl(GDMA_OSD1_CTRL_reg, 3 | GDMA_OSD1_CTRL_vs(vs) | GDMA_OSD1_CTRL_hs(hs));*/
	/*rtd_outl(GDMA_OSD2_CTRL_reg, 3 | GDMA_OSD2_CTRL_vs(vs) | GDMA_OSD2_CTRL_hs(hs));*/
	rtd_outl(GDMA_CTRL_reg, 0x61);
	rtd_outl(OSDOVL_Mixer_CTRL2_reg, 0x7F);

	pr_debug("rtd_inl(%x)=0x%x\n", GDMA_OSD1_reg, rtd_inl(GDMA_OSD1_reg));
	pr_debug("rtd_inl(%x)=0x%x\n", GDMA_OSD1_CTRL_reg, rtd_inl(GDMA_OSD1_CTRL_reg));
	pr_debug("rtd_inl(%x)=0x%x\n", GDMA_OSD1_WI_reg, rtd_inl(GDMA_OSD1_WI_reg));
	pr_debug("rtd_inl(%x)=0x%x\n", GDMA_OSD1_SIZE_reg, rtd_inl(GDMA_OSD1_SIZE_reg));
	pr_debug("rtd_inl(%x)=0x%x\n", GDMA_OSD1_CTRL_reg, rtd_inl(GDMA_OSD1_CTRL_reg));
	pr_debug("rtd_inl(%x)=0x%x\n", GDMA_CTRL_reg, rtd_inl(GDMA_CTRL_reg));

}

void osdGdma_syncPic_test(void)
{
	int iloop = 0, jloop = 0;
	gdma_dev *gdma = &gdma_devices[0];
	dma_addr_t addr1, addr2, addr3;
	volatile unsigned int *fillcolor = NULL;
	volatile unsigned int *fillcolor_osd2 = NULL;
	volatile unsigned int *fillcolor_osd3 = NULL;
	GRAPHIC_LAYERS_OBJECT *android_layer;

	osd_planealpha_ar osdcmp_plane_ar;
	osd_planealpha_gb osdcmp_plane_gb;
	osd_clear_x osdcmp_clearx;
	osd_clear_y osdcmp_cleary;

	int osd_idx1, osd_idx2;/* , osd_idx3; */
	VO_GRAPHIC_PLANE plane1, plane2;/* , plane3; */
	u32 dst_w1, dst_w2;
	u32 dst_h1, dst_h2;
	u32 src_w1, src_w2;
	u32 src_h1, src_h2;
	int div;

	fillcolor = kmalloc(1280*720*4, GFP_KERNEL);
	fillcolor_osd2 = kmalloc(1280*720*4, GFP_KERNEL);
	fillcolor_osd3 = kmalloc(640*360*4, GFP_KERNEL);
	android_layer = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);
	if (fillcolor == NULL || fillcolor_osd2 == NULL ||
		android_layer == NULL || fillcolor_osd3 == NULL) {
		pr_debug("malloc fail\n");
		return;
	}
	memset(android_layer, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
	memset((void *)fillcolor, 0xff, 1280*720*4);
	memset((void *)fillcolor_osd2, 0xff, 1280*720*4);
	memset((void *)fillcolor_osd3, 0xff, 640*360*4);
	pr_debug("fillcolor=0x%x,fillcolor_osd2=0x%x,fillcolor_osd3=0x%x\n", (uint32_t)fillcolor, (uint32_t)fillcolor_osd2, (uint32_t)fillcolor_osd3);
	pr_debug("fillcolor=0x%x\n", virt_to_phys(fillcolor));
	pr_debug("fillcolor_osd2=0x%x\n", virt_to_phys(fillcolor_osd2));
	pr_debug("fillcolor_osd3=0x%x\n", virt_to_phys(fillcolor_osd3));

	dsb();
	addr1 = dma_map_single(gdma->dev, (void *)fillcolor, 1280*720*4, DMA_TO_DEVICE);
	addr2 = dma_map_single(gdma->dev, (void *)fillcolor_osd2, 1280*720*4, DMA_TO_DEVICE);
	addr3 = dma_map_single(gdma->dev, (void *)fillcolor_osd3, 640*360*4, DMA_TO_DEVICE);

	if (dma_mapping_error(gdma->dev, addr1))
		pr_debug("dma_map_single fail addr1 \n");
	if (dma_mapping_error(gdma->dev, addr2))
		pr_debug("dma_map_single fail addr2 \n");
	if (dma_mapping_error(gdma->dev, addr3))
		pr_debug("dma_map_single fail addr3 \n");

	/*  make image source */
	div = ((640 * 360) / 10);
	for (iloop = 0; iloop < 1280*720; iloop++) {
		if (iloop < ((1280*720)/2)) {
			jloop = iloop%1280;
			if (jloop < 300)
				fillcolor[iloop] = 0xff0000ff;/* Red//RGBA, big-endian */
			else if ((jloop >= 300) && (jloop < 600))
				fillcolor[iloop] = 0xff00ff00;/* Green */
			else if ((jloop >= 600) && (jloop < 1280))
				fillcolor[iloop] = 0xffff0000;/* Blue */
		} else {
			jloop = iloop%1280;
			if (jloop < 500)
				fillcolor[iloop] = 0xffff00ff;/* Red */
			else if ((jloop >= 500) && (jloop < 1000))
				fillcolor[iloop] = 0xffffffff;/* white */
			else if ((jloop >= 1000) && (jloop < 1280))
				fillcolor[iloop] = 0xff00ffff;/* yellow */
		}

		if (iloop < ((1280*720)/4))
			fillcolor_osd2[iloop] = 0xff7b7b7b;/* Red//RGBA, big-endian */
		else if (iloop >= ((1280*720)/4) && iloop < ((1280*720)/2))
			fillcolor_osd2[iloop] = 0xffffffff;
		else if (iloop >= ((1280*720)/2) && iloop < (((1280*720)/4)*3))
			fillcolor_osd2[iloop] = 0xff7b7b7b;
		else if (iloop >= (((1280*720)/4)*3) && iloop < (1280*720))
			fillcolor_osd2[iloop] = 0xffffffff;

		if (iloop < div)
			fillcolor_osd3[iloop] = 0xff0000ff;/* Red//RGBA, big-endian */
		else if (iloop >= (div * 1) && iloop < (div * 2))
			fillcolor_osd3[iloop] = 0xff00ffff;
		else if (iloop >= (div * 2) && iloop < (div * 3))
			fillcolor_osd3[iloop] = 0xffffffff;
		else if (iloop >= (div * 3) && iloop < (div * 4))
			fillcolor_osd3[iloop] = 0xffff0000;
		else if (iloop >= (div * 4) && iloop < (div * 5))
			fillcolor_osd3[iloop] = 0xff7b7b7b;
		else if (iloop >= (div * 5) && iloop < (div * 6))
			fillcolor_osd3[iloop] = 0xffff00ff;
		else if (iloop >= (div * 6) && iloop < (div * 7))
			fillcolor_osd3[iloop] = 0xff000000;
		else if (iloop >= (div * 7) && iloop < (div * 8))
			fillcolor_osd3[iloop] = 0xff808080;
		else if (iloop >= (div * 8) && iloop < (div * 9))
			fillcolor_osd3[iloop] = 0xff404040;
		else if (iloop >= (div * 9) && iloop < (div * 10))
			fillcolor_osd3[iloop] = 0xffa0a0a0;
	}

	dma_sync_single_for_device(gdma->dev, addr1, 1280*720*4, DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr2, 1280*720*4, DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr3, 640*360*4, DMA_TO_DEVICE);

	dma_unmap_single(gdma->dev, addr1, 1280*720*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr2, 1280*720*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr3, 640*360*4, DMA_TO_DEVICE);

	osdcmp_plane_ar.plane_alpha_r = 0xff;
	osdcmp_plane_ar.plane_alpha_a = 0xff;
	osdcmp_plane_gb.plane_alpha_g = 0xff;
	osdcmp_plane_gb.plane_alpha_b = 0xff;


	osd_idx1 = OSD1_1;
	osd_idx2 = OSD1_2;
	/* osd_idx3 = OSD1_3; */
	plane1 = VO_GRAPHIC_OSD1;
	plane2 = VO_GRAPHIC_OSD2;
	/* plane3 = VO_GRAPHIC_OSD3; */


	/*  step1: osd1+osd2 */
	src_w1 = 1280;
	src_w2 = 1280;
	src_h1 = 720;
	src_h2 = 720;
	dst_w1 = gdma->dispWin[0].width;
	dst_w2 = 1280;
	dst_h1 = gdma->dispWin[0].height;
	dst_h2 = 720;

	android_layer->layer_num = 2;

	android_layer->layer[osd_idx1].src_type = SRC_NORMAL;
	android_layer->layer[osd_idx1].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_layer->layer[osd_idx1].context = 0; /*  ?? */
	android_layer->layer[osd_idx1].key_en = 0;
	android_layer->layer[osd_idx1].colorkey = -1;
	android_layer->layer[osd_idx1].alpha = 0x80;
	android_layer->layer[osd_idx1].x = 0;
	android_layer->layer[osd_idx1].y = 0;
	android_layer->layer[osd_idx1].height = src_h1;
	android_layer->layer[osd_idx1].width = src_w1;
	android_layer->layer[osd_idx1].address = (unsigned int)virt_to_phys(fillcolor);
	android_layer->layer[osd_idx1].pitch = android_layer->layer[osd_idx1].width*4;
	android_layer->layer[osd_idx1].dst_x = 0;
	android_layer->layer[osd_idx1].dst_y = 0;
	android_layer->layer[osd_idx1].dst_height = dst_h1;
	android_layer->layer[osd_idx1].dst_width = dst_w1;
	android_layer->layer[osd_idx1].plane_ar = osdcmp_plane_ar;
	android_layer->layer[osd_idx1].plane_gb = osdcmp_plane_gb;
	android_layer->layer[osd_idx1].clear_x = osdcmp_clearx;
	android_layer->layer[osd_idx1].clear_y = osdcmp_cleary;
	android_layer->layer[osd_idx1].syncstamp = 0;
	android_layer->layer[osd_idx1].show = 1;

	android_layer->layer[osd_idx2].src_type = SRC_NORMAL;
	android_layer->layer[osd_idx2].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_layer->layer[osd_idx2].context = 0; /*  ?? */
	android_layer->layer[osd_idx2].key_en = 0;
	android_layer->layer[osd_idx2].colorkey = -1;
	android_layer->layer[osd_idx2].alpha = 0x80;
	android_layer->layer[osd_idx2].x = 0;
	android_layer->layer[osd_idx2].y = 0;
	android_layer->layer[osd_idx2].height = src_h2;
	android_layer->layer[osd_idx2].width = src_w2;
	android_layer->layer[osd_idx2].address = (unsigned int)virt_to_phys(fillcolor_osd2);
	android_layer->layer[osd_idx2].pitch = android_layer->layer[osd_idx2].width*4;
	android_layer->layer[osd_idx2].dst_x = 0;
	android_layer->layer[osd_idx2].dst_y = 0;
	android_layer->layer[osd_idx2].dst_height = dst_h2;
	android_layer->layer[osd_idx2].dst_width = dst_w2;
	android_layer->layer[osd_idx2].plane_ar = osdcmp_plane_ar;
	android_layer->layer[osd_idx2].plane_gb = osdcmp_plane_gb;
	android_layer->layer[osd_idx2].clear_x = osdcmp_clearx;
	android_layer->layer[osd_idx2].clear_y = osdcmp_cleary;
	android_layer->layer[osd_idx2].syncstamp = 0;
	android_layer->layer[osd_idx2].show = 1;
	GDMA_ReceiveGraphicLayers(android_layer);
	msleep(5000);

#if 1
	/*  step2: osd1(+syncstamp)+osd2 */
	src_w1 = 1280;
	src_h1 = 720;
	dst_w1 = gdma->dispWin[0].width;
	dst_h1 = gdma->dispWin[0].height;
	src_w2 = 640;
	src_h2 = 360;
	dst_w2 = 640;
	dst_h2 = 360;

	android_layer->layer[osd_idx1].height = src_h1;
	android_layer->layer[osd_idx1].width = src_w1;
	android_layer->layer[osd_idx1].address = (unsigned int)virt_to_phys(fillcolor_osd2);
	android_layer->layer[osd_idx1].dst_height = dst_h1;
	android_layer->layer[osd_idx1].dst_width = dst_w1;
	android_layer->layer[osd_idx1].syncstamp = 0x12345678;
	android_layer->layer[osd_idx1].show = 1;
	android_layer->layer[osd_idx1].pitch = android_layer->layer[osd_idx1].width*4;
	android_layer->layer[osd_idx2].height = src_h2;
	android_layer->layer[osd_idx2].width = src_w2;
	android_layer->layer[osd_idx2].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_layer->layer[osd_idx2].dst_height = dst_h2;
	android_layer->layer[osd_idx2].dst_width = dst_w2;
	android_layer->layer[osd_idx2].syncstamp = 0x12345678;
	android_layer->layer[osd_idx2].show = 1;
	android_layer->layer[osd_idx2].pitch = android_layer->layer[osd_idx2].width*4;
	GDMA_ReceiveGraphicLayers(android_layer);
	msleep(5000);

	/*  step3: osd1+osd2(syncstamp) */
	src_w1 = 640;
	src_h1 = 360;
	dst_w1 = gdma->dispWin[0].width;
	dst_h1 = gdma->dispWin[0].height;
	src_w2 = 1280;
	src_h2 = 720;
	dst_w2 = 1280;
	dst_h2 = 720;
	plane1 = VO_GRAPHIC_OSD2;
	plane2 = VO_GRAPHIC_OSD1;

	android_layer->layer[osd_idx1].height = src_h1;
	android_layer->layer[osd_idx1].width = src_w1;
	android_layer->layer[osd_idx1].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_layer->layer[osd_idx1].dst_height = dst_h1;
	android_layer->layer[osd_idx1].dst_width = dst_w1;
	android_layer->layer[osd_idx1].syncstamp = 0x86;
	android_layer->layer[osd_idx1].show = 1;
	android_layer->layer[osd_idx1].pitch = android_layer->layer[osd_idx1].width*4;
	android_layer->layer[osd_idx2].height = src_h2;
	android_layer->layer[osd_idx2].width = src_w2;
	android_layer->layer[osd_idx2].address = (unsigned int)virt_to_phys(fillcolor);
	android_layer->layer[osd_idx2].dst_height = dst_h2;
	android_layer->layer[osd_idx2].dst_width = dst_w2;
	android_layer->layer[osd_idx2].syncstamp = 0x86;
	android_layer->layer[osd_idx2].show = 1;
	android_layer->layer[osd_idx2].pitch = android_layer->layer[osd_idx2].width*4;
	GDMA_ReceiveGraphicLayers(android_layer);
	msleep(5000);
#else
	/*  step2: osd1+osd2(+syncstamp) */
	dst_w1 = gdma->dispWin[0].width;
	dst_w2 = 640;
	dst_h1 = gdma->dispWin[0].height;
	dst_h2 = 360;
	src_w1 = 1280;
	src_w2 = 640;
	src_h1 = 720;
	src_h2 = 360;
	android_layer->layer[osd_idx1].height = src_h1;
	android_layer->layer[osd_idx1].width = src_w1;
	android_layer->layer[osd_idx1].address = (unsigned int)virt_to_phys(fillcolor_osd2);
	android_layer->layer[osd_idx1].dst_height = dst_h1;
	android_layer->layer[osd_idx1].dst_width = dst_w1;
	android_layer->layer[osd_idx1].syncstamp = 0;
	android_layer->layer[osd_idx1].show = 1;
	android_layer->layer[osd_idx1].pitch = android_layer->layer[osd_idx1].width*4;
	android_layer->layer[osd_idx2].height = src_h2;
	android_layer->layer[osd_idx2].width = src_w2;
	android_layer->layer[osd_idx2].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_layer->layer[osd_idx2].dst_height = dst_h2;
	android_layer->layer[osd_idx2].dst_width = dst_w2;
	android_layer->layer[osd_idx2].syncstamp = 0x12345678;
	android_layer->layer[osd_idx2].show = 1;
	android_layer->layer[osd_idx2].pitch = android_layer->layer[osd_idx2].width*4;
	GDMA_ReceiveGraphicLayers(android_layer);
	msleep(1500);

	/*  step3: osd1(syncstamp)+osd2 */
	dst_w1 = gdma->dispWin[0].width;
	dst_w2 = 1280;
	dst_h1 = gdma->dispWin[0].height;
	dst_h2 = 720;
	src_w1 = 640;
	src_w2 = 1280;
	src_h1 = 360;
	src_h2 = 720;
	android_layer->layer[osd_idx1].height = src_h1;
	android_layer->layer[osd_idx1].width = src_w1;
	android_layer->layer[osd_idx1].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_layer->layer[osd_idx1].dst_height = dst_h1;
	android_layer->layer[osd_idx1].dst_width = dst_w1;
	android_layer->layer[osd_idx1].syncstamp = 0x12345678;
	android_layer->layer[osd_idx1].show = 1;
	android_layer->layer[osd_idx1].pitch = android_layer->layer[osd_idx1].width*4;
	android_layer->layer[osd_idx2].height = src_h2;
	android_layer->layer[osd_idx2].width = src_w2;
	android_layer->layer[osd_idx2].address = (unsigned int)virt_to_phys(fillcolor);
	android_layer->layer[osd_idx2].dst_height = dst_h2;
	android_layer->layer[osd_idx2].dst_width = dst_w2;
	android_layer->layer[osd_idx2].syncstamp = 0;
	android_layer->layer[osd_idx2].show = 1;
	android_layer->layer[osd_idx2].pitch = android_layer->layer[osd_idx2].width*4;
	GDMA_ReceiveGraphicLayers(android_layer);
	msleep(1500);
#endif
	/*  step4: hide osd1/2 */
	dst_w1 = gdma->dispWin[0].width;
	dst_w2 = gdma->dispWin[1].width;
	dst_h1 = gdma->dispWin[0].height;
	dst_h2 = gdma->dispWin[1].height;
	src_w1 = 640;
	src_w2 = 1280;
	src_h1 = 360;
	src_h2 = 720;
	/* android_layer->layer[osd_idx1].plane = VO_GRAPHIC_OSD1; */
	/* android_layer->layer[osd_idx1].plane = VO_GRAPHIC_OSD2; */
	android_layer->layer[osd_idx1].height = src_h1;
	android_layer->layer[osd_idx1].width = src_w1;
	android_layer->layer[osd_idx1].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_layer->layer[osd_idx1].dst_height = dst_h1;
	android_layer->layer[osd_idx1].dst_width = dst_w1;
	android_layer->layer[osd_idx1].syncstamp = 0;
	android_layer->layer[osd_idx1].show = 0;
	android_layer->layer[osd_idx1].pitch = android_layer->layer[osd_idx1].width*4;
	android_layer->layer_num = 1;
	GDMA_ReceiveGraphicLayers(android_layer);
	msleep(5000);

	/*  step5: hide osd2/1 */
	/* android_layer->layer[osd_idx1].plane = VO_GRAPHIC_OSD1; */
	/* android_layer->layer[osd_idx1].plane = VO_GRAPHIC_OSD2; */
	android_layer->layer[osd_idx1].height = src_h1;
	android_layer->layer[osd_idx1].width = src_w1;
	android_layer->layer[osd_idx1].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_layer->layer[osd_idx1].dst_height = dst_h1;
	android_layer->layer[osd_idx1].dst_width = dst_w1;
	android_layer->layer[osd_idx1].syncstamp = 0;
	android_layer->layer[osd_idx1].show = 0;
	android_layer->layer[osd_idx1].pitch = android_layer->layer[osd_idx1].width*4;
	GDMA_ReceiveGraphicLayers(android_layer);
	msleep(5000);
}


void osdGdma_multiQThread_test(unsigned int arg)
{
	int iloop = 0, jloop = 0, compress = 0, pic_fbWbase;
	static int draw_once_flag = 0;
	gdma_dev *gdma = &gdma_devices[0];
	dma_addr_t addr1, addr2, addr3, addr4;
	static unsigned int *fillcolor = NULL;
	static unsigned int *fillcolor_osd2 = NULL;
	static unsigned int *fillcolor_osd3 = NULL;
	static unsigned char *fillcursor = NULL;
	osd_planealpha_ar osdcmp_plane_ar;
	osd_planealpha_gb osdcmp_plane_gb;
	osd_clear_x osdcmp_clearx;
	osd_clear_y osdcmp_cleary;
	ONLINE_WRRITEBACK_STRUCT wb;

	int osd_idx1, osd_idx2, osd_idx3;
	VO_GRAPHIC_PLANE plane1, plane2;/* , plane3; */
	u32 dst_w1, dst_w2, dst_w3, dst_w4, dst_w5, dst_w6;
	u32 dst_h1, dst_h2, dst_h3, dst_h4, dst_h5, dst_h6;
	u32 src_w1, src_w2, src_w3, src_w4, src_w5, src_w6;
	u32 src_h1, src_h2, src_h3, src_h4, src_h5, src_h6;
	int div;
	static struct task_struct *thread1, *thread2, *thread3, *thread4, *thread5;
	char our_thread1[8] = "thread1";
	char our_thread2[8] = "thread2";
	char our_thread3[8] = "thread3";
	char our_thread4[8] = "thread4";
	char our_thread5[8] = "thread5";

	VO_RECTANGLE disp_res;
	getDispSize(&disp_res);
	pic_fbWbase = disp_res.width;

	osdcmp_clearx.value = 0;
	osdcmp_cleary.value = 0;

	if (arg == 2379) {
		g_sleeptime = g_stop = arg;
	} else {
		g_sleeptime = rtd_inl(0xb800501c);
		g_stop = 0;
	}

	pr_debug("g_sleeptime= %d, g_stop = %d \n", g_sleeptime, g_stop);

	if (fillcolor == NULL)
		fillcolor = kmalloc(1280*720*4, GFP_KERNEL);
	if (fillcolor_osd2 == NULL)
		fillcolor_osd2 = kmalloc(1280*720*4, GFP_KERNEL);
	if (fillcolor_osd3 == NULL)
		fillcolor_osd3 = kmalloc(640*360*4, GFP_KERNEL);
	if (fillcursor == NULL)
		fillcursor = kmalloc(256*256, GFP_KERNEL);
	if (g_OSDPalettePattern == NULL)
		g_OSDPalettePattern =  kmalloc(256*4, GFP_KERNEL);
	if (android_test_layer1 == NULL)
		android_test_layer1 = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);
	if (android_test_layer2 == NULL)
		android_test_layer2 = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);
	if (android_test_layer3 == NULL)
		android_test_layer3 = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);
	if (android_test_layer4 == NULL)
		android_test_layer4 = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);

	if (fillcolor == NULL || fillcolor_osd2 == NULL || fillcursor == NULL ||
		android_test_layer3 == NULL || fillcolor_osd3 == NULL || android_test_layer1 == NULL ||
		g_OSDPalettePattern == NULL || android_test_layer2 == NULL || android_test_layer4 == NULL) {
		pr_debug(KERN_EMERG"malloc fail\n");
		return;
	}

	if (draw_once_flag == 0) {
		memset(android_test_layer1, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
		memset(android_test_layer2, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
		memset(android_test_layer3, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
		memset(android_test_layer4, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
		memset((void *)fillcolor, 0xff, 1280*720*4);
		memset((void *)fillcolor_osd2, 0xff, 1280*720*4);
		memset((void *)fillcolor_osd3, 0xff, 640*360*4);
		memset((void *)fillcursor, 0xff, 256*256);
		memset(g_OSDPalettePattern, 0x00, 256*4);
	}
	pr_debug(KERN_EMERG"Virtual fillcolor=0x%x,fillcolor_osd2=0x%x,fillcolor_osd3=0x%x\n", (uint32_t)fillcolor, (uint32_t)fillcolor_osd2, (uint32_t)fillcolor_osd3);
	pr_debug(KERN_EMERG"Physical fillcolor=0x%x\n", virt_to_phys(fillcolor));
	pr_debug(KERN_EMERG"Physical fillcolor_osd2=0x%x\n", virt_to_phys(fillcolor_osd2));
	pr_debug(KERN_EMERG"Physical fillcolor_osd3=0x%x\n", virt_to_phys(fillcolor_osd3));

	dsb();
	addr1 = dma_map_single(gdma->dev, (void *)fillcolor, 1280*720*4, DMA_TO_DEVICE);
	addr2 = dma_map_single(gdma->dev, (void *)fillcolor_osd2, 1280*720*4, DMA_TO_DEVICE);
	addr3 = dma_map_single(gdma->dev, (void *)fillcolor_osd3, 640*360*4, DMA_TO_DEVICE);
	addr4 = dma_map_single(gdma->dev, (void *)fillcursor, 256*256, DMA_TO_DEVICE);

	if (dma_mapping_error(gdma->dev, addr1))
		pr_debug("dma_map_single fail addr1 \n");
	if (dma_mapping_error(gdma->dev, addr2))
		pr_debug("dma_map_single fail addr2 \n");
	if (dma_mapping_error(gdma->dev, addr3))
		pr_debug("dma_map_single fail addr3 \n");
	if (dma_mapping_error(gdma->dev, addr4))
		pr_debug("dma_map_single fail addr4 \n");

	for (iloop = 0; iloop < 256*256; iloop++) {
		fillcursor[iloop] = 0;
	}
	for (iloop = 0; iloop < 256; iloop++) {
		g_OSDPalettePattern[iloop] = 0xFF0000FF;
	}
	memcpy (gdma->OSD_CLUT[0], (void *)(g_OSDPalettePattern), sizeof(unsigned int) * 256);

	if (draw_once_flag == 0) {
		/*  make image source */
		div = ((640 * 360) / 10);
		for (iloop = 0; iloop < 1280*720; iloop++) {
			if (iloop < ((1280*720)/2)) {
				jloop = iloop%1280;
				if (jloop < 300)
					fillcolor[iloop] = 0xff0000ff;/* Red//RGBA, big-endian */
				else if ((jloop >= 300) && (jloop < 600))
					fillcolor[iloop] = 0xff00ff00;/* Green */
				else if ((jloop >= 600) && (jloop < 1280))
					fillcolor[iloop] = 0xffff0000;/* Blue */
			} else {
				jloop = iloop%1280;
				if (jloop < 500)
					fillcolor[iloop] = 0xffff00ff;/* Red */
				else if ((jloop >= 500) && (jloop < 1000))
					fillcolor[iloop] = 0xffffffff;/* white */
				else if ((jloop >= 1000) && (jloop < 1280))
					fillcolor[iloop] = 0xff00ffff;/* yellow */
			}

			if (iloop < ((1280*720)/4))
				fillcolor_osd2[iloop] = 0xff7b7b7b;/* Red//RGBA, big-endian */
			else if (iloop >= ((1280*720)/4) && iloop < ((1280*720)/2))
				fillcolor_osd2[iloop] = 0xffffffff;
			else if (iloop >= ((1280*720)/2) && iloop < (((1280*720)/4)*3))
				fillcolor_osd2[iloop] = 0xff7b7b7b;
			else if (iloop >= (((1280*720)/4)*3) && iloop < (1280*720))
				fillcolor_osd2[iloop] = 0xffffffff;

			if (iloop < div)
				fillcolor_osd3[iloop] = 0xff0000ff;/* Red//RGBA, big-endian */
			else if (iloop >= (div * 1) && iloop < (div * 2))
				fillcolor_osd3[iloop] = 0xff00ffff;
			else if (iloop >= (div * 2) && iloop < (div * 3))
				fillcolor_osd3[iloop] = 0xffffffff;
			else if (iloop >= (div * 3) && iloop < (div * 4))
				fillcolor_osd3[iloop] = 0xffff0000;
			else if (iloop >= (div * 4) && iloop < (div * 5))
				fillcolor_osd3[iloop] = 0xff7b7b7b;
			else if (iloop >= (div * 5) && iloop < (div * 6))
				fillcolor_osd3[iloop] = 0xffff00ff;
			else if (iloop >= (div * 6) && iloop < (div * 7))
				fillcolor_osd3[iloop] = 0xff000000;
			else if (iloop >= (div * 7) && iloop < (div * 8))
				fillcolor_osd3[iloop] = 0xff808080;
			else if (iloop >= (div * 8) && iloop < (div * 9))
				fillcolor_osd3[iloop] = 0xff404040;
			else if (iloop >= (div * 9) && iloop < (div * 10))
				fillcolor_osd3[iloop] = 0xffa0a0a0;
		}
		draw_once_flag = 1;
	}

	dma_sync_single_for_device(gdma->dev, addr1, 1280*720*4, DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr2, 1280*720*4, DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr3, 640*360*4, DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr4, 256*256, DMA_TO_DEVICE);

	dma_unmap_single(gdma->dev, addr1, 1280*720*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr2, 1280*720*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr3, 640*360*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr4, 256*256, DMA_TO_DEVICE);

	osdcmp_plane_ar.plane_alpha_r = 0xff;
	osdcmp_plane_ar.plane_alpha_a = 0xff;
	osdcmp_plane_gb.plane_alpha_g = 0xff;
	osdcmp_plane_gb.plane_alpha_b = 0xff;


	/* compressed test flag */
	compress = 0;

	/*  thread1: 2 layers: normal */
	src_w1 = 1280;
	src_h1 = 720;
	dst_w1 = 1280;
	dst_h1 = 720;
	src_w2 = 1280;
	src_h2 = 720;
	dst_w2 = 1920;
	dst_h2 = 1080;
	src_w3 = 360;
	src_h3 = 240;
	dst_w3 = 1920;
	dst_h3 = 1080;
	src_w4 = 260;
	src_h4 = 200;
	dst_w4 = 260;
	dst_h4 = 200;
	src_w5 = 120;
	src_h5 = 160;
	dst_w5 = 1920;
	dst_h5 = 1080;

	android_test_layer1->layer_num = 5;
	android_test_layer1->cookie = 0;

	android_test_layer1->layer[0].src_type = SRC_NORMAL;
	android_test_layer1->layer[0].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer1->layer[0].context = 0; /*  ?? */
	android_test_layer1->layer[0].key_en = 0;
	android_test_layer1->layer[0].colorkey = -1;
	android_test_layer1->layer[0].alpha = 0x00;
	android_test_layer1->layer[0].x = 0;
	android_test_layer1->layer[0].y = 0;
	android_test_layer1->layer[0].height = src_h1;
	android_test_layer1->layer[0].width = src_w1;
	android_test_layer1->layer[0].address = virt_to_phys(fillcolor);
	android_test_layer1->layer[0].pitch = android_test_layer1->layer[0].width*4;
	android_test_layer1->layer[0].dst_x = 0;
	android_test_layer1->layer[0].dst_y = 0;
	android_test_layer1->layer[0].dst_height = dst_h1;
	android_test_layer1->layer[0].dst_width = dst_w1;
	android_test_layer1->layer[0].compressed = compress;    /*compress test*/
	android_test_layer1->layer[0].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[0].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[0].clear_x = osdcmp_clearx;
	android_test_layer1->layer[0].clear_y = osdcmp_cleary;
	android_test_layer1->layer[0].syncstamp = 0;
	android_test_layer1->layer[0].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[0].show = 1;


	android_test_layer1->layer[1].src_type = SRC_NORMAL;
	android_test_layer1->layer[1].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[1].context = 0; /*  ?? */
	android_test_layer1->layer[1].key_en = 0;
	android_test_layer1->layer[1].colorkey = -1;
	android_test_layer1->layer[1].alpha = 0x80;
	android_test_layer1->layer[1].x = 0;
	android_test_layer1->layer[1].y = 0;
	android_test_layer1->layer[1].height = src_h2;
	android_test_layer1->layer[1].width = src_w2;
	android_test_layer1->layer[1].address = virt_to_phys(fillcolor_osd2);
	android_test_layer1->layer[1].pitch = android_test_layer1->layer[1].width*4;
	android_test_layer1->layer[1].dst_x = 0;
	android_test_layer1->layer[1].dst_y = 0;
	android_test_layer1->layer[1].dst_height = dst_h2;
	android_test_layer1->layer[1].dst_width = dst_w2;
	android_test_layer1->layer[1].compressed = compress;
	android_test_layer1->layer[1].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[1].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[1].clear_x = osdcmp_clearx;
	android_test_layer1->layer[1].clear_y = osdcmp_cleary;
	android_test_layer1->layer[1].syncstamp = 0;
	android_test_layer1->layer[1].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[1].show = 1;


	android_test_layer1->layer[2].src_type = SRC_NORMAL;
	android_test_layer1->layer[2].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[2].context = 0; /*  ?? */
	android_test_layer1->layer[2].key_en = 0;
	android_test_layer1->layer[2].colorkey = -1;
	android_test_layer1->layer[2].alpha = 0x80;
	android_test_layer1->layer[2].x = 0;
	android_test_layer1->layer[2].y = 0;
	android_test_layer1->layer[2].height = src_h3;
	android_test_layer1->layer[2].width = src_w3;
	android_test_layer1->layer[2].address = virt_to_phys(lollipop_360x240);
	android_test_layer1->layer[2].pitch = android_test_layer1->layer[2].width*4;
	android_test_layer1->layer[2].dst_x = 0;
	android_test_layer1->layer[2].dst_y = 0;
	android_test_layer1->layer[2].dst_height = dst_h3;
	android_test_layer1->layer[2].dst_width = dst_w3;
	android_test_layer1->layer[2].compressed = compress;
	android_test_layer1->layer[2].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[2].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[2].clear_x = osdcmp_clearx;
	android_test_layer1->layer[2].clear_y = osdcmp_cleary;
	android_test_layer1->layer[2].syncstamp = 0;
	android_test_layer1->layer[2].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[2].show = 1;


	android_test_layer1->layer[3].src_type = SRC_NORMAL;
	android_test_layer1->layer[3].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[3].context = 0; /*  ?? */
	android_test_layer1->layer[3].key_en = 0;
	android_test_layer1->layer[3].colorkey = -1;
	android_test_layer1->layer[3].alpha = 0x80;
	android_test_layer1->layer[3].x = 0;
	android_test_layer1->layer[3].y = 0;
	android_test_layer1->layer[3].height = src_h4;
	android_test_layer1->layer[3].width = src_w4;
	android_test_layer1->layer[3].address = virt_to_phys(gdma_rtk_logo_260x200);
	android_test_layer1->layer[3].pitch = android_test_layer1->layer[3].width*4;
	android_test_layer1->layer[3].dst_x = 200;
	android_test_layer1->layer[3].dst_y = 200;
	android_test_layer1->layer[3].dst_height = dst_h4;
	android_test_layer1->layer[3].dst_width = dst_w4;
	android_test_layer1->layer[3].compressed = compress;
	android_test_layer1->layer[3].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[3].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[3].clear_x = osdcmp_clearx;
	android_test_layer1->layer[3].clear_y = osdcmp_cleary;
	android_test_layer1->layer[3].syncstamp = 0;
	android_test_layer1->layer[3].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[3].show = 1;

	android_test_layer1->layer[4].src_type = SRC_NORMAL;
	android_test_layer1->layer[4].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[4].context = 0; /*  ?? */
	android_test_layer1->layer[4].key_en = 0;
	android_test_layer1->layer[4].colorkey = -1;
	android_test_layer1->layer[4].alpha = 0x80;
	android_test_layer1->layer[4].x = 0;
	android_test_layer1->layer[4].y = 0;
	android_test_layer1->layer[4].height = src_h5;
	android_test_layer1->layer[4].width = src_w5;
	android_test_layer1->layer[4].address = virt_to_phys(mycursor_120x160);
	android_test_layer1->layer[4].pitch = android_test_layer1->layer[4].width*4;
	android_test_layer1->layer[4].dst_x = 0;
	android_test_layer1->layer[4].dst_y = 0;
	android_test_layer1->layer[4].dst_height = dst_h5;
	android_test_layer1->layer[4].dst_width = dst_w5;
	android_test_layer1->layer[4].compressed = compress;
	android_test_layer1->layer[4].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[4].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[4].clear_x = osdcmp_clearx;
	android_test_layer1->layer[4].clear_y = osdcmp_cleary;
	android_test_layer1->layer[4].syncstamp = 0;
	android_test_layer1->layer[4].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[4].show = 1;

	//if (arg == 1)
	//	GDMA_ReceiveGraphicLayers(android_test_layer1);

#if 0	/*  */
	src_w1 = 1280;
	src_h1 = 720;
	dst_w1 = disp_res.width;
	dst_h1 = disp_res.height;
	src_w2 = 1280;
	src_h2 = 720;
	dst_w2 = disp_res.width;
	dst_h2 = disp_res.height;
	src_w3 = 360;
	src_h3 = 240;
	dst_w3 = 770;//(u32)(360 * 3) / 2;
	dst_h3 = 650;//(u32)(240 * 3) / 2;
	src_w4 = 120;
	src_h4 = 160;
	dst_w4 = (u32)(120 * 3) / 2;
	dst_h4 = (u32)(160 * 3) / 2;

	/* compressed test flag */
	compress = 0;


	android_test_layer1->layer_num = 2;
	android_test_layer1->layer[0].src_type = SRC_NORMAL;
	android_test_layer1->layer[0].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer1->layer[0].context = 0; /*  ?? */
	android_test_layer1->layer[0].key_en = 0;
	android_test_layer1->layer[0].colorkey = -1;
	android_test_layer1->layer[0].alpha = 0x00;
	android_test_layer1->layer[0].x = 0;
	android_test_layer1->layer[0].y = 0;
	android_test_layer1->layer[0].height = src_h1;
	android_test_layer1->layer[0].width = src_w1;
	android_test_layer1->layer[0].address = (unsigned int)virt_to_phys(fillcolor);
	android_test_layer1->layer[0].pitch = android_test_layer1->layer[0].width*4;
	android_test_layer1->layer[0].dst_x = 0;
	android_test_layer1->layer[0].dst_y = 0;
	android_test_layer1->layer[0].dst_height = dst_h1;
	android_test_layer1->layer[0].dst_width = dst_w1;
	android_test_layer1->layer[0].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[0].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[0].clear_x = osdcmp_clearx;
	android_test_layer1->layer[0].clear_y = osdcmp_cleary;
	android_test_layer1->layer[0].syncstamp = 0;
	android_test_layer1->layer[0].show = 1;
	android_test_layer1->layer[0].compressed = compress;
	android_test_layer1->layer[0].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer1->layer[1].src_type = SRC_NORMAL;
	android_test_layer1->layer[1].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer1->layer[1].context = 0; /*  ?? */
	android_test_layer1->layer[1].key_en = 0;
	android_test_layer1->layer[1].colorkey = -1;
	android_test_layer1->layer[1].alpha = 0x80;
	android_test_layer1->layer[1].x = 0;
	android_test_layer1->layer[1].y = 0;
	android_test_layer1->layer[1].height = src_h2;
	android_test_layer1->layer[1].width = src_w2;
	android_test_layer1->layer[1].address = (unsigned int)virt_to_phys(fillcolor_osd2);
	android_test_layer1->layer[1].pitch = android_test_layer1->layer[1].width*4;
	android_test_layer1->layer[1].dst_x = 0;
	android_test_layer1->layer[1].dst_y = 0;
	android_test_layer1->layer[1].dst_height = dst_h2;
	android_test_layer1->layer[1].dst_width = dst_w2;
	android_test_layer1->layer[1].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[1].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[1].clear_x = osdcmp_clearx;
	android_test_layer1->layer[1].clear_y = osdcmp_cleary;
	android_test_layer1->layer[1].syncstamp = 0;
	android_test_layer1->layer[1].show = 1;
	android_test_layer1->layer[1].compressed = compress;
	android_test_layer1->layer[1].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer1->layer[2].src_type = SRC_NORMAL;
	android_test_layer1->layer[2].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[2].context = 0; /*  ?? */
	android_test_layer1->layer[2].key_en = 0;
	android_test_layer1->layer[2].colorkey = -1;
	android_test_layer1->layer[2].alpha = 0x80;
	android_test_layer1->layer[2].x = 0;
	android_test_layer1->layer[2].y = 0;
	android_test_layer1->layer[2].height = src_h3;
	android_test_layer1->layer[2].width = src_w3;
	android_test_layer1->layer[2].address = (unsigned int)virt_to_phys(lollipop_360x240);
	android_test_layer1->layer[2].pitch = android_test_layer1->layer[2].width*4;
	android_test_layer1->layer[2].dst_x = 100;
	android_test_layer1->layer[2].dst_y = 100;
	android_test_layer1->layer[2].dst_height = dst_h3;
	android_test_layer1->layer[2].dst_width = dst_w3;
	android_test_layer1->layer[2].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[2].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[2].clear_x = osdcmp_clearx;
	android_test_layer1->layer[2].clear_y = osdcmp_cleary;
	android_test_layer1->layer[2].syncstamp = 0;
	android_test_layer1->layer[2].show = 1;
	android_test_layer1->layer[2].compressed = compress;
	android_test_layer1->layer[2].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer1->layer[3].src_type = SRC_NORMAL;
	android_test_layer1->layer[3].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[3].context = 0; /*  ?? */
	android_test_layer1->layer[3].key_en = 0;
	android_test_layer1->layer[3].colorkey = -1;
	android_test_layer1->layer[3].alpha = 0x80;
	android_test_layer1->layer[3].x = 0;
	android_test_layer1->layer[3].y = 0;
	android_test_layer1->layer[3].height = src_h4;
	android_test_layer1->layer[3].width = src_w4;
	android_test_layer1->layer[3].address = (unsigned int)virt_to_phys(mycursor_120x160);
	android_test_layer1->layer[3].pitch = android_test_layer1->layer[3].width*4;
	android_test_layer1->layer[3].dst_x = 460;
	android_test_layer1->layer[3].dst_y = 340;
	android_test_layer1->layer[3].dst_height = dst_h4;
	android_test_layer1->layer[3].dst_width = dst_w4;
	android_test_layer1->layer[3].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[3].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[3].clear_x = osdcmp_clearx;
	android_test_layer1->layer[3].clear_y = osdcmp_cleary;
	android_test_layer1->layer[3].syncstamp = 0;
	android_test_layer1->layer[3].show = 1;
	android_test_layer1->layer[3].compressed = compress;
	android_test_layer1->layer[3].scale_factor = disp_res.width/pic_fbWbase;
#endif


	/*  thread2: 6 layers */
	src_w1 = 1280;
	src_h1 = 720;
	dst_w1 = 1280;//disp_res.width;
	dst_h1 = 720;//disp_res.height;
	src_w2 = 640;
	src_h2 = 360;
	dst_w2 = 640;
	dst_h2 = 360;
	src_w3 = 360;
	src_h3 = 240;
	dst_w3 = 360;
	dst_h3 = 240;
	src_w4 = 120;
	src_h4 = 160;
	dst_w4 = 120;
	dst_h4 = 160;
	src_w5 = 260;
	src_h5 = 200;
	dst_w5 = 260;
	dst_h5 = 200;
	src_w6 = 120;
	src_h6 = 160;
	dst_w6 = 120;
	dst_h6 = 160;

	/* compressed test flag */
	compress = 1;


	android_test_layer2->layer_num = 4;
	android_test_layer2->layer[0].src_type = SRC_NORMAL;
	android_test_layer2->layer[0].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer2->layer[0].context = 0; /*  ?? */
	android_test_layer2->layer[0].key_en = 0;
	android_test_layer2->layer[0].colorkey = -1;
	android_test_layer2->layer[0].alpha = 0x00;
	android_test_layer2->layer[0].x = 0;
	android_test_layer2->layer[0].y = 0;
	android_test_layer2->layer[0].height = src_h1;
	android_test_layer2->layer[0].width = src_w1;
	//android_test_layer2->layer[0].address = (unsigned int)virt_to_phys(fillcolor);
	android_test_layer2->layer[0].address = (unsigned int)virt_to_phys(fillcolor_osd2);
	android_test_layer2->layer[0].pitch = android_test_layer2->layer[0].width*4;
	android_test_layer2->layer[0].dst_x = 0;
	android_test_layer2->layer[0].dst_y = 0;
	android_test_layer2->layer[0].dst_height = dst_h1;
	android_test_layer2->layer[0].dst_width = dst_w1;
	android_test_layer2->layer[0].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[0].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[0].clear_x = osdcmp_clearx;
	android_test_layer2->layer[0].clear_y = osdcmp_cleary;
	android_test_layer2->layer[0].syncstamp = 0;
	android_test_layer2->layer[0].show = 1;
	android_test_layer2->layer[0].compressed = compress;
	android_test_layer2->layer[0].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer2->layer[1].src_type = SRC_NORMAL;
	android_test_layer2->layer[1].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer2->layer[1].context = 0; /*  ?? */
	android_test_layer2->layer[1].key_en = 0;
	android_test_layer2->layer[1].colorkey = -1;
	android_test_layer2->layer[1].alpha = 0x80;
	android_test_layer2->layer[1].x = 0;
	android_test_layer2->layer[1].y = 0;
	android_test_layer2->layer[1].height = src_h2;
	android_test_layer2->layer[1].width = src_w2;
	//android_test_layer2->layer[1].address = (unsigned int)virt_to_phys(fillcolor_osd2);
	android_test_layer2->layer[1].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_test_layer2->layer[1].pitch = android_test_layer2->layer[1].width*4;
	android_test_layer2->layer[1].dst_x = 0;
	android_test_layer2->layer[1].dst_y = 0;
	android_test_layer2->layer[1].dst_height = dst_h2;
	android_test_layer2->layer[1].dst_width = dst_w2;
	android_test_layer2->layer[1].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[1].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[1].clear_x = osdcmp_clearx;
	android_test_layer2->layer[1].clear_y = osdcmp_cleary;
	android_test_layer2->layer[1].syncstamp = 0;
	android_test_layer2->layer[1].show = 1;
	android_test_layer2->layer[1].compressed = compress;
	android_test_layer2->layer[1].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer2->layer[2].src_type = SRC_NORMAL;
	android_test_layer2->layer[2].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer2->layer[2].context = 0; /*  ?? */
	android_test_layer2->layer[2].key_en = 0;
	android_test_layer2->layer[2].colorkey = -1;
	android_test_layer2->layer[2].alpha = 0x80;
	android_test_layer2->layer[2].x = 0;
	android_test_layer2->layer[2].y = 0;
	android_test_layer2->layer[2].height = src_h3;
	android_test_layer2->layer[2].width = src_w3;
	android_test_layer2->layer[2].address = (unsigned int)virt_to_phys(lollipop_360x240);
	android_test_layer2->layer[2].pitch = android_test_layer2->layer[2].width*4;
	android_test_layer2->layer[2].dst_x = 100;
	android_test_layer2->layer[2].dst_y = 100;
	android_test_layer2->layer[2].dst_height = dst_h3;
	android_test_layer2->layer[2].dst_width = dst_w3;
	android_test_layer2->layer[2].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[2].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[2].clear_x = osdcmp_clearx;
	android_test_layer2->layer[2].clear_y = osdcmp_cleary;
	android_test_layer2->layer[2].syncstamp = 0;
	android_test_layer2->layer[2].show = 1;
	android_test_layer2->layer[2].compressed = compress;
	android_test_layer2->layer[2].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer2->layer[3].src_type = SRC_NORMAL;
	android_test_layer2->layer[3].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer2->layer[3].context = 0; /*  ?? */
	android_test_layer2->layer[3].key_en = 0;
	android_test_layer2->layer[3].colorkey = -1;
	android_test_layer2->layer[3].alpha = 0x80;
	android_test_layer2->layer[3].x = 0;
	android_test_layer2->layer[3].y = 0;
	android_test_layer2->layer[3].height = src_h4;
	android_test_layer2->layer[3].width = src_w4;
	android_test_layer2->layer[3].address = (unsigned int)virt_to_phys(mycursor_120x160);
	android_test_layer2->layer[3].pitch = android_test_layer2->layer[3].width*4;
	android_test_layer2->layer[3].dst_x = 460;
	android_test_layer2->layer[3].dst_y = 340;
	android_test_layer2->layer[3].dst_height = dst_h4;
	android_test_layer2->layer[3].dst_width = dst_w4;
	android_test_layer2->layer[3].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[3].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[3].clear_x = osdcmp_clearx;
	android_test_layer2->layer[3].clear_y = osdcmp_cleary;
	android_test_layer2->layer[3].syncstamp = 0;
	android_test_layer2->layer[3].show = 1;
	android_test_layer2->layer[3].compressed = compress;
	android_test_layer2->layer[3].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer2->layer[4].src_type = SRC_NORMAL;
	android_test_layer2->layer[4].format = VO_OSD_COLOR_FORMAT_ARGB8888;
	android_test_layer2->layer[4].context = 0; /*  ?? */
	android_test_layer2->layer[4].key_en = 0;
	android_test_layer2->layer[4].colorkey = -1;
	android_test_layer2->layer[4].alpha = 0x80;
	android_test_layer2->layer[4].x = 0;
	android_test_layer2->layer[4].y = 0;
	android_test_layer2->layer[4].height = src_h5;
	android_test_layer2->layer[4].width = src_w5;
	android_test_layer2->layer[4].address = (unsigned int)virt_to_phys(gdma_rtk_logo_260x200);
	android_test_layer2->layer[4].pitch = android_test_layer2->layer[4].width*4;
	android_test_layer2->layer[4].dst_x = 500;
	android_test_layer2->layer[4].dst_y = 500;
	android_test_layer2->layer[4].dst_height = dst_h5;
	android_test_layer2->layer[4].dst_width = dst_w5;
	android_test_layer2->layer[4].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[4].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[4].clear_x = osdcmp_clearx;
	android_test_layer2->layer[4].clear_y = osdcmp_cleary;
	android_test_layer2->layer[4].syncstamp = 0;
	android_test_layer2->layer[4].show = 1;
	android_test_layer2->layer[4].compressed = compress;
	android_test_layer2->layer[4].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer2->layer[5].src_type = SRC_MOUSE_NORMAL;
	android_test_layer2->layer[5].format = VO_OSD_COLOR_FORMAT_ARGB8888;
	android_test_layer2->layer[5].context = 0; /*  ?? */
	android_test_layer2->layer[5].key_en = 0;
	android_test_layer2->layer[5].colorkey = -1;
	android_test_layer2->layer[5].alpha = 0x80;
	android_test_layer2->layer[5].x = 0;
	android_test_layer2->layer[5].y = 0;
	android_test_layer2->layer[5].height = src_h6;
	android_test_layer2->layer[5].width = src_w6;
	android_test_layer2->layer[5].address = (unsigned int)virt_to_phys(mycursor_120x160);
	android_test_layer2->layer[5].pitch = android_test_layer2->layer[5].width*4;
	android_test_layer2->layer[5].dst_x = 600;
	android_test_layer2->layer[5].dst_y = 600;
	android_test_layer2->layer[5].dst_height = dst_h6;
	android_test_layer2->layer[5].dst_width = dst_w6;
	android_test_layer2->layer[5].plane_ar = osdcmp_plane_ar;
	android_test_layer2->layer[5].plane_gb = osdcmp_plane_gb;
	android_test_layer2->layer[5].clear_x = osdcmp_clearx;
	android_test_layer2->layer[5].clear_y = osdcmp_cleary;
	android_test_layer2->layer[5].syncstamp = 0;
	android_test_layer2->layer[5].show = 1;
	android_test_layer2->layer[5].compressed = compress;
	android_test_layer2->layer[5].scale_factor = disp_res.width/pic_fbWbase;

	//if (arg == 2)
	//	GDMA_ReceiveGraphicLayers(android_test_layer2);

	/*  thread3:  */
	src_w1 = 360;
	src_h1 = 240;
	dst_w1 = 360;
	dst_h1 = 240;
	src_w2 = 260;
	src_h2 = 200;
	dst_w2 = 260;
	dst_h2 = 200;
	src_w3 = 120;
	src_h3 = 160;
	dst_w3 = 120;
	dst_h3 = 160;
	src_w4 = 120;
	src_h4 = 160;
	dst_w4 = 256;
	dst_h4 = 256;
	src_w5 = 260;
	src_h5 = 200;
	dst_w5 = 260;
	dst_h5 = 200;
	src_w6 = 120;
	src_h6 = 160;
	dst_w6 = 120;
	dst_h6 = 160;

	/* compressed test flag */
	compress = 0;


	android_test_layer3->layer_num = 1;

	android_test_layer3->layer[0].src_type = SRC_NORMAL;
	android_test_layer3->layer[0].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer3->layer[0].context = 0; /*  ?? */
	android_test_layer3->layer[0].key_en = 0;
	android_test_layer3->layer[0].colorkey = -1;
	android_test_layer3->layer[0].alpha = 0xff;
	android_test_layer3->layer[0].x = 0;
	android_test_layer3->layer[0].y = 0;
	android_test_layer3->layer[0].height = src_h1;
	android_test_layer3->layer[0].width = src_w1;
	android_test_layer3->layer[0].address = (unsigned int)virt_to_phys(lollipop_360x240);
	android_test_layer3->layer[0].pitch = android_test_layer3->layer[0].width*4;
	android_test_layer3->layer[0].dst_x = 111;
	android_test_layer3->layer[0].dst_y = 111;
	android_test_layer3->layer[0].dst_height = dst_h1;
	android_test_layer3->layer[0].dst_width = dst_w1;
	android_test_layer3->layer[0].compressed = compress;
	android_test_layer3->layer[0].plane_ar = osdcmp_plane_ar;
	android_test_layer3->layer[0].plane_gb = osdcmp_plane_gb;
	android_test_layer3->layer[0].clear_x = osdcmp_clearx;
	android_test_layer3->layer[0].clear_y = osdcmp_cleary;
	android_test_layer3->layer[0].syncstamp = 0;
	android_test_layer3->layer[0].show = 1;
	android_test_layer3->layer[0].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer3->layer[1].src_type = SRC_NORMAL;
	android_test_layer3->layer[1].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer3->layer[1].context = 0; /*  ?? */
	android_test_layer3->layer[1].key_en = 0;
	android_test_layer3->layer[1].colorkey = -1;
	android_test_layer3->layer[1].alpha = 0xff;
	android_test_layer3->layer[1].x = 0;
	android_test_layer3->layer[1].y = 0;
	android_test_layer3->layer[1].height = src_h2;
	android_test_layer3->layer[1].width = src_w2;
	android_test_layer3->layer[1].address = (unsigned int)virt_to_phys(gdma_rtk_logo_260x200);
	android_test_layer3->layer[1].pitch = android_test_layer3->layer[1].width*4;
	android_test_layer3->layer[1].dst_x = 222;
	android_test_layer3->layer[1].dst_y = 222;
	android_test_layer3->layer[1].dst_height = dst_h2;
	android_test_layer3->layer[1].dst_width = dst_w2;
	android_test_layer3->layer[1].compressed = compress;
	android_test_layer3->layer[1].plane_ar = osdcmp_plane_ar;
	android_test_layer3->layer[1].plane_gb = osdcmp_plane_gb;
	android_test_layer3->layer[1].clear_x = osdcmp_clearx;
	android_test_layer3->layer[1].clear_y = osdcmp_cleary;
	android_test_layer3->layer[1].syncstamp = 0;
	android_test_layer3->layer[1].show = 1;
	android_test_layer3->layer[1].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer3->layer[2].src_type = SRC_NORMAL;
	android_test_layer3->layer[2].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer3->layer[2].context = 0; /*  ?? */
	android_test_layer3->layer[2].key_en = 0;
	android_test_layer3->layer[2].colorkey = -1;
	android_test_layer3->layer[2].alpha = 0xff;
	android_test_layer3->layer[2].x = 0;
	android_test_layer3->layer[2].y = 0;
	android_test_layer3->layer[2].height = src_h3;
	android_test_layer3->layer[2].width = src_w3;
	android_test_layer3->layer[2].address = (unsigned int)virt_to_phys(mycursor_120x160);
	android_test_layer3->layer[2].pitch = android_test_layer3->layer[2].width*4;
	android_test_layer3->layer[2].dst_x = 333;
	android_test_layer3->layer[2].dst_y = 333;
	android_test_layer3->layer[2].dst_height = dst_h3;
	android_test_layer3->layer[2].dst_width = dst_w3;
	android_test_layer3->layer[2].compressed = compress;
	android_test_layer3->layer[2].plane_ar = osdcmp_plane_ar;
	android_test_layer3->layer[2].plane_gb = osdcmp_plane_gb;
	android_test_layer3->layer[2].clear_x = osdcmp_clearx;
	android_test_layer3->layer[2].clear_y = osdcmp_cleary;
	android_test_layer3->layer[2].syncstamp = 0;
	android_test_layer3->layer[2].show = 1;
	android_test_layer3->layer[2].scale_factor = disp_res.width/pic_fbWbase;

	//if (arg == 3)
	//	GDMA_ReceiveGraphicLayers(android_test_layer3);
	//if (arg == 4) {
	//	android_test_layer3->layer_num = 3;
	//	GDMA_ReceiveGraphicLayers(android_test_layer3);
	//}


	/*  thread5:  */
	src_w1 = 640;
	src_h1 = 360;
	dst_w1 = 640;
	dst_h1 = 360;
	src_w2 = 360;
	src_h2 = 240;
	dst_w2 = 360;
	dst_h2 = 240;
	src_w3 = 260;
	src_h3 = 200;
	dst_w3 = 260;
	dst_h3 = 200;
	src_w4 = 120;
	src_h4 = 160;
	dst_w4 = 120;
	dst_h4 = 160;


	/* compressed test flag */
	compress = 1;


	android_test_layer4->layer_num = 4;

	android_test_layer4->layer[0].src_type = SRC_NORMAL;
	android_test_layer4->layer[0].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer4->layer[0].context = 0; /*  ?? */
	android_test_layer4->layer[0].key_en = 0;
	android_test_layer4->layer[0].colorkey = -1;
	android_test_layer4->layer[0].alpha = 0xff;
	android_test_layer4->layer[0].x = 0;
	android_test_layer4->layer[0].y = 0;
	android_test_layer4->layer[0].height = src_h1;
	android_test_layer4->layer[0].width = src_w1;
	android_test_layer4->layer[0].address = (unsigned int)virt_to_phys(fillcolor_osd3);
	android_test_layer4->layer[0].pitch = android_test_layer4->layer[0].width*4;
	android_test_layer4->layer[0].dst_x = 960;
	android_test_layer4->layer[0].dst_y = 540;
	android_test_layer4->layer[0].dst_height = dst_h1;
	android_test_layer4->layer[0].dst_width = dst_w1;
	android_test_layer4->layer[0].compressed = compress;
	android_test_layer4->layer[0].plane_ar = osdcmp_plane_ar;
	android_test_layer4->layer[0].plane_gb = osdcmp_plane_gb;
	android_test_layer4->layer[0].clear_x = osdcmp_clearx;
	android_test_layer4->layer[0].clear_y = osdcmp_cleary;
	android_test_layer4->layer[0].syncstamp = 0;
	android_test_layer4->layer[0].show = 1;
	android_test_layer4->layer[0].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer4->layer[1].src_type = SRC_NORMAL;
	android_test_layer4->layer[1].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer4->layer[1].context = 0; /*  ?? */
	android_test_layer4->layer[1].key_en = 0;
	android_test_layer4->layer[1].colorkey = -1;
	android_test_layer4->layer[1].alpha = 0xff;
	android_test_layer4->layer[1].x = 0;
	android_test_layer4->layer[1].y = 0;
	android_test_layer4->layer[1].height = src_h2;
	android_test_layer4->layer[1].width = src_w2;
	android_test_layer4->layer[1].address = (unsigned int)virt_to_phys(lollipop_360x240);
	android_test_layer4->layer[1].pitch = android_test_layer4->layer[1].width*4;
	android_test_layer4->layer[1].dst_x = 1000;
	android_test_layer4->layer[1].dst_y = 600;
	android_test_layer4->layer[1].dst_height = dst_h2;
	android_test_layer4->layer[1].dst_width = dst_w2;
	android_test_layer4->layer[1].compressed = compress;
	android_test_layer4->layer[1].plane_ar = osdcmp_plane_ar;
	android_test_layer4->layer[1].plane_gb = osdcmp_plane_gb;
	android_test_layer4->layer[1].clear_x = osdcmp_clearx;
	android_test_layer4->layer[1].clear_y = osdcmp_cleary;
	android_test_layer4->layer[1].syncstamp = 0;
	android_test_layer4->layer[1].show = 1;
	android_test_layer4->layer[1].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer4->layer[2].src_type = SRC_NORMAL;
	android_test_layer4->layer[2].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer4->layer[2].context = 0; /*  ?? */
	android_test_layer4->layer[2].key_en = 0;
	android_test_layer4->layer[2].colorkey = -1;
	android_test_layer4->layer[2].alpha = 0xff;
	android_test_layer4->layer[2].x = 0;
	android_test_layer4->layer[2].y = 0;
	android_test_layer4->layer[2].height = src_h3;
	android_test_layer4->layer[2].width = src_w3;
	android_test_layer4->layer[2].address = (unsigned int)virt_to_phys(gdma_rtk_logo_260x200);
	android_test_layer4->layer[2].pitch = android_test_layer4->layer[2].width*4;
	android_test_layer4->layer[2].dst_x = 1200;
	android_test_layer4->layer[2].dst_y = 700;
	android_test_layer4->layer[2].dst_height = dst_h3;
	android_test_layer4->layer[2].dst_width = dst_w3;
	android_test_layer4->layer[2].compressed = compress;
	android_test_layer4->layer[2].plane_ar = osdcmp_plane_ar;
	android_test_layer4->layer[2].plane_gb = osdcmp_plane_gb;
	android_test_layer4->layer[2].clear_x = osdcmp_clearx;
	android_test_layer4->layer[2].clear_y = osdcmp_cleary;
	android_test_layer4->layer[2].syncstamp = 0;
	android_test_layer4->layer[2].show = 1;
	android_test_layer4->layer[2].scale_factor = disp_res.width/pic_fbWbase;

	android_test_layer4->layer[3].src_type = SRC_MOUSE_NORMAL;
	android_test_layer4->layer[3].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer4->layer[3].context = 0; /*  ?? */
	android_test_layer4->layer[3].key_en = 0;
	android_test_layer4->layer[3].colorkey = -1;
	android_test_layer4->layer[3].alpha = 0xff;
	android_test_layer4->layer[3].x = 0;
	android_test_layer4->layer[3].y = 0;
	android_test_layer4->layer[3].height = src_h4;
	android_test_layer4->layer[3].width = src_w4;
	android_test_layer4->layer[3].address = (unsigned int)virt_to_phys(mycursor_120x160);
	android_test_layer4->layer[3].pitch = android_test_layer4->layer[3].width*4;
	android_test_layer4->layer[3].dst_x = 333;
	android_test_layer4->layer[3].dst_y = 333;
	android_test_layer4->layer[3].dst_height = dst_h4;
	android_test_layer4->layer[3].dst_width = dst_w4;
	android_test_layer4->layer[3].compressed = compress;
	android_test_layer4->layer[3].plane_ar = osdcmp_plane_ar;
	android_test_layer4->layer[3].plane_gb = osdcmp_plane_gb;
	android_test_layer4->layer[3].clear_x = osdcmp_clearx;
	android_test_layer4->layer[3].clear_y = osdcmp_cleary;
	android_test_layer4->layer[3].syncstamp = 0;
	android_test_layer4->layer[3].show = 1;
	android_test_layer4->layer[3].scale_factor = disp_res.width/pic_fbWbase;

	//if (arg == 5)
	//	GDMA_ReceiveGraphicLayers(android_test_layer4);

#if 0
	pr_debug(KERN_EMERG "in init");
	if (thread1 == NULL)
		thread1 = kthread_create(osdthread1_fn, NULL, our_thread1);
	if (thread2 == NULL)
		thread2 = kthread_create(osdthread2_fn, NULL, our_thread2);
	if (thread3 == NULL)
		thread3 = kthread_create(osdthread3_fn, NULL, our_thread3);
	if (thread4 == NULL)
		thread4 = kthread_create(osdthread4_fn, NULL, our_thread4);
	if (thread5 == NULL)
		thread5 = kthread_create(osdthread5_fn, NULL, our_thread5);



	if (arg != 2379) {

		if (arg == 6666) {
			iloop = 300;
			while (iloop--) {
				GDMA_ReceiveGraphicLayers(android_test_layer4);
				g_sleeptime = rtd_inl(0xb800501c);

				if (g_sleeptime)
					msleep(g_sleeptime);

				//GDMA_ENTER_CRITICAL();
				//GDMA_SwitchOnlineOffline(1, 1);
				//GDMA_EXIT_CRITICAL();

				GDMA_ReceiveGraphicLayers(android_test_layer2);

				if (g_sleeptime)
					msleep(g_sleeptime);
				if (g_stop == 0x2379)
					break;
			}
			pr_debug(KERN_EMERG "busy loop gdma_ctrl done....\n");
		}

		if ((thread1) && (arg == 1 || arg == 12 || arg == 13 || arg == 14 || arg == 15 ||
			arg == 123 || arg == 1234 || arg == 12345)) {

			pr_debug(KERN_EMERG "in if1\n");
			wake_up_process(thread1);
		}
		if ((thread2) && (arg == 2 || arg == 12 || arg == 23 || arg == 24 || arg == 25 ||
			arg == 123 || arg == 1234 || arg == 12345)) {

			pr_debug(KERN_EMERG "in if2\n");
			wake_up_process(thread2);
		}

		if ((thread3) && (arg == 3 || arg == 13 || arg == 23 || arg == 34 || arg == 35 ||
			arg == 123 || arg == 1234 || arg == 12345)) {

			pr_debug(KERN_EMERG "in if3\n");
			wake_up_process(thread3);
		}
		if ((thread4) && (arg == 4 || arg == 14 || arg == 24 || arg == 34 || arg == 45 ||
			arg == 1234 || arg == 12345)) {

			pr_debug(KERN_EMERG "in if4\n");
			wake_up_process(thread4);
		}
		if ((thread5) && (arg == 5 || arg == 15 || arg == 25 || arg == 35 || arg == 45 ||
			arg == 12345)) {

			pr_debug(KERN_EMERG "in if5\n");
			wake_up_process(thread5);
		}

	}
	else {
		if (thread1 != NULL) {
			kthread_stop(thread1);
			thread1 = NULL;
		}
		if (thread2 != NULL) {
			kthread_stop(thread2);
			thread2 = NULL;
		}
		if (thread3 != NULL) {
			kthread_stop(thread3);
			thread3 = NULL;
		}
		if (thread4 != NULL) {
			kthread_stop(thread4);
			thread4 = NULL;
		}
		if (thread5 != NULL) {
			kthread_stop(thread5);
			thread5 = NULL;
		}
		pr_debug("kthread stop\n");
	}
#endif
}


void gdma_osdx_test(unsigned int osdx)
{
	static VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN *create_win;
	static VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN *draw_win, *draw_win2, *draw_win3, *draw_win4, *draw_win5;

	/* int hs = 0, vs = 0, */
	int winID, winID2, winID3, winID4, winID5;
	/* gdma_dev *gdma = &gdma_devices[0]; */
	int iloop = 0, jloop = 0;
	static unsigned int *fillcolor = NULL, *fillcolor_osd2 = NULL;
	GDMA_WIN *win = NULL;
	u32 dst_w1, dst_w2, dst_w3, dst_w4, dst_w5, dst_w6;
	u32 dst_h1, dst_h2, dst_h3, dst_h4, dst_h5, dst_h6;
	u32 src_w1, src_w2, src_w3, src_w4, src_w5, src_w6;
	u32 src_h1, src_h2, src_h3, src_h4, src_h5, src_h6;

	if (draw_win == NULL)
		draw_win = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win2 == NULL)
		draw_win2 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win3 == NULL)
		draw_win3 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win4 == NULL)
		draw_win4 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win5 == NULL)
		draw_win5 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (create_win == NULL)
		create_win = kmalloc(sizeof(VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN), GFP_KERNEL);
	if (win == NULL)
		win = kmalloc(sizeof(GDMA_WIN), GFP_KERNEL);
	if (fillcolor == NULL)
		fillcolor = kmalloc(1280*720*4, GFP_KERNEL);
	if (fillcolor_osd2 == NULL)
		fillcolor_osd2 = kmalloc(1280*720*4, GFP_KERNEL);
	if (win == NULL || fillcolor == NULL || fillcolor_osd2 == NULL) {
		pr_debug(KERN_EMERG"malloc fail\n");
		return;
	}

	memset(draw_win, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win2, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win3, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win4, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win5, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(create_win, 0, sizeof(VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN));
	memset(win, 0, sizeof(GDMA_WIN));
	memset(fillcolor, 0xff, 1280*720);
	memset(fillcolor_osd2, 0xff, 1280*720);
	pr_debug(KERN_EMERG"memset = win=0x%x,fillcolor=0x%x\n", (unsigned int)win, (unsigned int)fillcolor);
	pr_debug(KERN_EMERG"virtual = win=0x%x,fillcolor=0x%x\n", virt_to_phys(win), virt_to_phys(fillcolor));
	pr_debug(KERN_EMERG"fillcolor_osd2=0x%x\n", virt_to_phys(fillcolor_osd2));

	for (iloop = 0; iloop < 1280*720; iloop++) {
		if (iloop < ((1280*720)/2)) {
			jloop = iloop%1280;
			if (jloop < 300)
				fillcolor[iloop] = 0xff0000ff;/* Red/RGBA */
			else if ((jloop >= 300) && (jloop < 600))
				fillcolor[iloop] = 0xff00ff00;/* Green */
			else if ((jloop >= 600) && (jloop < 1280))
				fillcolor[iloop] = 0xffff0000;/* Blue */
		} else {
			jloop = iloop%1280;
			if (jloop < 500)
				fillcolor[iloop] = 0xffff00ff;/* Red */
			else if ((jloop >= 500) && (jloop < 1000))
				fillcolor[iloop] = 0xffffffff;/* white */
			else if ((jloop >= 1000) && (jloop < 1280))
				fillcolor[iloop] = 0xff00ffff;/* yellow */
		}

		if (iloop < ((1280*720)/4))
			fillcolor_osd2[iloop] = 0xff7b7b7b;/* Red//RGBA, big-endian */
		else if (iloop >= ((1280*720)/4) && iloop < ((1280*720)/2))
			fillcolor_osd2[iloop] = 0xffffffff;
		else if (iloop >= ((1280*720)/2) && iloop < (((1280*720)/4)*3))
			fillcolor_osd2[iloop] = 0xff7b7b7b;
		else if (iloop >= (((1280*720)/4)*3) && iloop < (1280*720))
			fillcolor_osd2[iloop] = 0xffffffff;
	}


	src_w1 = 1280;
	src_h1 = 720;
	src_w2 = 1280;
	src_h2 = 720;
	src_w3 = 360;
	src_h3 = 240;
	src_w4 = 260;
	src_h4 = 200;
	src_w5 = 120;
	src_h5 = 160;

	if (osdx & (1<<VO_GRAPHIC_OSD1)) {
		create_win->plane = VO_GRAPHIC_OSD1;
		create_win->winPos.x = 0;
		create_win->winPos.y = 0;
		create_win->winPos.height = src_h1;
		create_win->winPos.width = src_w1;
		create_win->colorFmt = VO_OSD_COLOR_FORMAT_RGBA8888;
		create_win->rgbOrder = VO_OSD_COLOR_RGB;
		create_win->colorKey = -1;
		create_win->compressed = 0;
		create_win->alpha = 0;
		winID = GDMA_CreateGraphicWindow(create_win);
		pr_debug("GDMA_CreateGraphicWindow:: OSD ID1=%d \n", winID);
	}
	if (osdx & (1<<VO_GRAPHIC_OSD2)) {
		create_win->plane = VO_GRAPHIC_OSD2;
		create_win->winPos.x = 0;
		create_win->winPos.y = 0;
		create_win->winPos.height = src_h2;
		create_win->winPos.width = src_w2;
		create_win->colorFmt = VO_OSD_COLOR_FORMAT_RGBA8888;
		create_win->rgbOrder = VO_OSD_COLOR_RGB;
		create_win->colorKey = -1;
		create_win->compressed = 0;
		create_win->alpha = 0x80;
		winID2 = GDMA_CreateGraphicWindow(create_win);
		pr_debug("GDMA_CreateGraphicWindow:: OSD ID2=%d \n", winID2);
	}
	if (osdx & (1<<VO_GRAPHIC_OSD3)) {
		create_win->plane = VO_GRAPHIC_OSD3;
		create_win->winPos.x = 0;
		create_win->winPos.y = 0;
		create_win->winPos.height = src_h3;
		create_win->winPos.width = src_w3;
		create_win->colorFmt = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		create_win->rgbOrder = VO_OSD_COLOR_RGB;
		create_win->colorKey = -1;
		create_win->compressed = 0;
		create_win->alpha = 0x80;
		winID2 = GDMA_CreateGraphicWindow(create_win);
		pr_debug("GDMA_CreateGraphicWindow:: OSD ID3=%d \n", winID3);
	}
	if (osdx & (1<<VO_GRAPHIC_OSD4)) {
		create_win->plane = VO_GRAPHIC_OSD4;
		create_win->winPos.x = 0;
		create_win->winPos.y = 0;
		create_win->winPos.height = src_h4;
		create_win->winPos.width = src_w4;
		create_win->colorFmt = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		create_win->rgbOrder = VO_OSD_COLOR_RGB;
		create_win->colorKey = -1;
		create_win->compressed = 0;
		create_win->alpha = 0x80;
		winID2 = GDMA_CreateGraphicWindow(create_win);
		pr_debug("GDMA_CreateGraphicWindow:: OSD ID4=%d \n", winID4);
	}
	if (osdx & (1<<VO_GRAPHIC_OSD5)) {
		create_win->plane = VO_GRAPHIC_OSD5;
		create_win->winPos.x = 0;
		create_win->winPos.y = 0;
		create_win->winPos.height = src_h5;
		create_win->winPos.width = src_w5;
		create_win->colorFmt = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		create_win->rgbOrder = VO_OSD_COLOR_RGB;
		create_win->colorKey = -1;
		create_win->compressed = 0;
		create_win->alpha = 0x80;
		winID2 = GDMA_CreateGraphicWindow(create_win);
		pr_debug("GDMA_CreateGraphicWindow:: OSD ID5=%d \n", winID5);
	}

	if (osdx & (1<<VO_GRAPHIC_OSD1)) {
		draw_win->plane = VO_GRAPHIC_OSD1;
		draw_win->winID = winID;
		draw_win->storageMode = VO_GRAPHIC_SEQUENTIAL;
		draw_win->paletteIndex = 0;
		draw_win->compressed = 0;
		draw_win->interlace_Frame = 0;
		draw_win->bottomField = 0;
		draw_win->startX[0] = 0;
		draw_win->startY[0] = 0;
		draw_win->imgPitch[0] = src_w1*4;
		draw_win->pImage[0] = virt_to_phys(fillcolor);
		/*draw_win->pImage[0] = virt_to_phys(fillcolor_osd2);*/
		draw_win->go = 1;

		if (GDMA_DrawGraphicWindow(draw_win) == GDMA_SUCCESS)
			pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD1 Successfully \n");

		GDMA_DeleteGraphicWindow(winID, VO_GRAPHIC_OSD1, 1);
	}
	if (osdx & (1<<VO_GRAPHIC_OSD2)) {
		draw_win2->plane = VO_GRAPHIC_OSD2;
		draw_win2->winID = winID2;
		draw_win2->storageMode = VO_GRAPHIC_SEQUENTIAL;
		draw_win2->paletteIndex = 0;
		draw_win2->compressed = 0;
		draw_win2->interlace_Frame = 0;
		draw_win2->bottomField = 0;
		draw_win2->startX[0] = 0;
		draw_win2->startY[0] = 0;
		draw_win2->imgPitch[0] = src_w2*4;
		draw_win2->pImage[0] = virt_to_phys(fillcolor_osd2);
		draw_win2->go = 1;

		if (GDMA_DrawGraphicWindow(draw_win2) == GDMA_SUCCESS)
			pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD2 Successfully \n");

		GDMA_DeleteGraphicWindow(winID2, VO_GRAPHIC_OSD2, 1);
	}
	if (osdx & (1<<VO_GRAPHIC_OSD3)) {
		draw_win3->plane = VO_GRAPHIC_OSD3;
		draw_win3->winID = winID3;
		draw_win3->storageMode = VO_GRAPHIC_SEQUENTIAL;
		draw_win3->paletteIndex = 0;
		draw_win3->compressed = 0;
		draw_win3->interlace_Frame = 0;
		draw_win3->bottomField = 0;
		draw_win3->startX[0] = 0;
		draw_win3->startY[0] = 0;
		draw_win3->imgPitch[0] = src_w3*4;
		draw_win3->pImage[0] = virt_to_phys(lollipop_360x240);
		draw_win3->go = 1;

		if (GDMA_DrawGraphicWindow(draw_win3) == GDMA_SUCCESS)
			pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD3 Successfully \n");

		GDMA_DeleteGraphicWindow(winID3, VO_GRAPHIC_OSD3, 1);
	}
	if (osdx & (1<<VO_GRAPHIC_OSD4)) {
		draw_win4->plane = VO_GRAPHIC_OSD4;
		draw_win4->winID = winID4;
		draw_win4->storageMode = VO_GRAPHIC_SEQUENTIAL;
		draw_win4->paletteIndex = 0;
		draw_win4->compressed = 0;
		draw_win4->interlace_Frame = 0;
		draw_win4->bottomField = 0;
		draw_win4->startX[0] = 0;
		draw_win4->startY[0] = 0;
		draw_win4->imgPitch[0] = src_w4*4;
		draw_win4->pImage[0] = virt_to_phys(gdma_rtk_logo_260x200);
		draw_win4->go = 1;

		if (GDMA_DrawGraphicWindow(draw_win4) == GDMA_SUCCESS)
			pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD4 Successfully \n");

		GDMA_DeleteGraphicWindow(winID4, VO_GRAPHIC_OSD4, 1);
	}
	if (osdx & (1<<VO_GRAPHIC_OSD5)) {
		draw_win5->plane = VO_GRAPHIC_OSD5;
		draw_win5->winID = winID5;
		draw_win5->storageMode = VO_GRAPHIC_SEQUENTIAL;
		draw_win5->paletteIndex = 0;
		draw_win5->compressed = 0;
		draw_win5->interlace_Frame = 0;
		draw_win5->bottomField = 0;
		draw_win5->startX[0] = 0;
		draw_win5->startY[0] = 0;
		draw_win5->imgPitch[0] = src_w5*4;
		draw_win5->pImage[0] = virt_to_phys(mycursor_120x160);
		draw_win5->go = 1;

		if (GDMA_DrawGraphicWindow(draw_win5) == GDMA_SUCCESS)
			pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD5 Successfully \n");

		GDMA_DeleteGraphicWindow(winID5, VO_GRAPHIC_OSD5, 1);
	}

}


/*
*   traditional path test
*/
void gdma_receivepicture_test(unsigned int arg)
{
	static VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN *create_win;
	static VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN *draw_win, *draw_win2, *draw_win3, *draw_win4, *draw_win5;

	/* int hs = 0, vs = 0, */
	int winID, winID2, winID3, winID4, winID5;
	gdma_dev *gdma = &gdma_devices[0];
	int iloop = 0, jloop = 0;
	static unsigned int *fillcolor = NULL, *fillcolor_osd2 = NULL;
	static unsigned int wbaddr = 0;
	GDMA_WIN *win = NULL;
	u32 dst_w1, dst_w2, dst_w3, dst_w4, dst_w5, dst_w6;
	u32 dst_h1, dst_h2, dst_h3, dst_h4, dst_h5, dst_h6;
	u32 src_w1, src_w2, src_w3, src_w4, src_w5, src_w6;
	u32 src_h1, src_h2, src_h3, src_h4, src_h5, src_h6;
	ONLINE_WRRITEBACK_STRUCT wb;

	if (draw_win == NULL)
		draw_win = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win2 == NULL)
		draw_win2 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win3 == NULL)
		draw_win3 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win4 == NULL)
		draw_win4 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (draw_win5 == NULL)
		draw_win5 = kmalloc(sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN), GFP_KERNEL);
	if (create_win == NULL)
		create_win = kmalloc(sizeof(VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN), GFP_KERNEL);
	if (win == NULL)
		win = kmalloc(sizeof(GDMA_WIN), GFP_KERNEL);
	if (fillcolor == NULL)
		fillcolor = kmalloc(1280*720*4, GFP_KERNEL);
	if (fillcolor_osd2 == NULL)
		fillcolor_osd2 = kmalloc(1280*720*4, GFP_KERNEL);
	if (wbaddr == 0)
		/*wbaddr = kmalloc(TWOK_W*ONEK_H*4, GFP_KERNEL);*/
		wbaddr = (unsigned int)dvr_malloc_specific(TWOK_W*ONEK_H*4, GFP_DCU1);
	if (win == NULL || fillcolor == NULL || fillcolor_osd2 == NULL || wbaddr == NULL) {
		pr_debug(KERN_EMERG"malloc fail\n");
		return;
	}

	memset(draw_win, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win2, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win3, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win4, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(draw_win5, 0, sizeof(VIDEO_RPC_VOUT_DRAW_GRAPHIC_WIN));
	memset(create_win, 0, sizeof(VIDEO_RPC_VOUT_CREATE_GRAPHIC_WIN));
	memset(win, 0, sizeof(GDMA_WIN));
	memset(fillcolor, 0xff, 1280*720);
	memset(fillcolor_osd2, 0xff, 1280*720);
	pr_debug(KERN_EMERG"memset = win=0x%x,fillcolor=0x%x\n", (unsigned int)win, (unsigned int)fillcolor);
	pr_debug(KERN_EMERG"virtual = win=0x%x,fillcolor=0x%x\n", virt_to_phys(win), virt_to_phys(fillcolor));
	pr_debug(KERN_EMERG"fillcolor_osd2=0x%x\n", virt_to_phys(fillcolor_osd2));
	pr_debug(KERN_EMERG"wbaddr=0x%x\n", dvr_to_phys((void *)wbaddr));


	for (iloop = 0; iloop < 1280*720; iloop++) {
		if (iloop < ((1280*720)/2)) {
			jloop = iloop%1280;
			if (jloop < 300)
				fillcolor[iloop] = 0xff0000ff;/* Red/RGBA */
			else if ((jloop >= 300) && (jloop < 600))
				fillcolor[iloop] = 0xff00ff00;/* Green */
			else if ((jloop >= 600) && (jloop < 1280))
				fillcolor[iloop] = 0xffff0000;/* Blue */
		} else {
			jloop = iloop%1280;
			if (jloop < 500)
				fillcolor[iloop] = 0xffff00ff;/* Red */
			else if ((jloop >= 500) && (jloop < 1000))
				fillcolor[iloop] = 0xffffffff;/* white */
			else if ((jloop >= 1000) && (jloop < 1280))
				fillcolor[iloop] = 0xff00ffff;/* yellow */
		}

		if (iloop < ((1280*720)/4))
			fillcolor_osd2[iloop] = 0xff7b7b7b;/* Red//RGBA, big-endian */
		else if (iloop >= ((1280*720)/4) && iloop < ((1280*720)/2))
			fillcolor_osd2[iloop] = 0xffffffff;
		else if (iloop >= ((1280*720)/2) && iloop < (((1280*720)/4)*3))
			fillcolor_osd2[iloop] = 0xff7b7b7b;
		else if (iloop >= (((1280*720)/4)*3) && iloop < (1280*720))
			fillcolor_osd2[iloop] = 0xffffffff;
	}


	/*src_w1 = 1920;//1280;*/
	/*src_h1 = 1080;//720;*/
	src_w1 = 1280;
	src_h1 = 720;
	src_w2 = 1280;
	src_h2 = 720;
	src_w3 = 360;
	src_h3 = 240;
	src_w4 = 260;
	src_h4 = 200;
	src_w5 = 120;
	src_h5 = 160;

	create_win->plane = VO_GRAPHIC_OSD1;
	create_win->winPos.x = 0;
	create_win->winPos.y = 0;
	create_win->winPos.height = src_h1;
	create_win->winPos.width = src_w1;
	create_win->colorFmt = VO_OSD_COLOR_FORMAT_RGBA8888;
	/*create_win->colorFmt = VO_OSD_COLOR_FORMAT_YCBYCR88;*/	/* m-cap 422 test*/
	create_win->rgbOrder = VO_OSD_COLOR_RGB;
	create_win->colorKey = -1;
	create_win->compressed = 0;
	create_win->alpha = 0;
	winID = GDMA_CreateGraphicWindow(create_win);
	pr_debug("GDMA_CreateGraphicWindow:: OSD ID1=%d \n", winID);
	create_win->plane = VO_GRAPHIC_OSD2;
	create_win->winPos.x = 0;
	create_win->winPos.y = 0;
	create_win->winPos.height = src_h2;
	create_win->winPos.width = src_w2;
	create_win->colorFmt = VO_OSD_COLOR_FORMAT_RGBA8888;
	create_win->rgbOrder = VO_OSD_COLOR_RGB;
	create_win->colorKey = -1;
	create_win->compressed = 0;
	create_win->alpha = 0x80;
	winID2 = GDMA_CreateGraphicWindow(create_win);
	pr_debug("GDMA_CreateGraphicWindow:: OSD ID2=%d \n", winID2);
	create_win->plane = VO_GRAPHIC_OSD3;
	create_win->winPos.x = 0;
	create_win->winPos.y = 0;
	create_win->winPos.height = src_h3;
	create_win->winPos.width = src_w3;
	create_win->colorFmt = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	create_win->rgbOrder = VO_OSD_COLOR_RGB;
	create_win->colorKey = -1;
	create_win->compressed = 0;
	create_win->alpha = 0x80;
	winID2 = GDMA_CreateGraphicWindow(create_win);
	pr_debug("GDMA_CreateGraphicWindow:: OSD ID3=%d \n", winID3);
	create_win->plane = VO_GRAPHIC_OSD4;
	create_win->winPos.x = 0;
	create_win->winPos.y = 0;
	create_win->winPos.height = src_h4;
	create_win->winPos.width = src_w4;
	create_win->colorFmt = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	create_win->rgbOrder = VO_OSD_COLOR_RGB;
	create_win->colorKey = -1;
	create_win->compressed = 0;
	create_win->alpha = 0x80;
	winID2 = GDMA_CreateGraphicWindow(create_win);
	pr_debug("GDMA_CreateGraphicWindow:: OSD ID4=%d \n", winID4);
	create_win->plane = VO_GRAPHIC_OSD5;
	create_win->winPos.x = 0;
	create_win->winPos.y = 0;
	create_win->winPos.height = src_h5;
	create_win->winPos.width = src_w5;
	create_win->colorFmt = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	create_win->rgbOrder = VO_OSD_COLOR_RGB;
	create_win->colorKey = -1;
	create_win->compressed = 0;
	create_win->alpha = 0x80;
	winID2 = GDMA_CreateGraphicWindow(create_win);
	pr_debug("GDMA_CreateGraphicWindow:: OSD ID5=%d \n", winID5);

	draw_win->plane = VO_GRAPHIC_OSD1;
	draw_win->winID = winID;
	draw_win->storageMode = VO_GRAPHIC_SEQUENTIAL;
	draw_win->paletteIndex = 0;
	draw_win->compressed = 0;
	draw_win->interlace_Frame = 0;
	draw_win->bottomField = 0;
	draw_win->startX[0] = 0;
	draw_win->startY[0] = 0;
	draw_win->imgPitch[0] = src_w1*4;
	draw_win->pImage[0] = virt_to_phys(fillcolor);
	/*draw_win->imgPitch[0] = src_w1*2; */
	/*draw_win->pImage[0] = virt_to_phys(yuv422_1920x1080); */
	draw_win->go = 1;

	if (GDMA_DrawGraphicWindow(draw_win) == GDMA_SUCCESS)
		pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD1 Successfully \n");

	draw_win2->plane = VO_GRAPHIC_OSD2;
	draw_win2->winID = winID2;
	draw_win2->storageMode = VO_GRAPHIC_SEQUENTIAL;
	draw_win2->paletteIndex = 0;
	draw_win2->compressed = 0;
	draw_win2->interlace_Frame = 0;
	draw_win2->bottomField = 0;
	draw_win2->startX[0] = 0;
	draw_win2->startY[0] = 0;
	draw_win2->imgPitch[0] = src_w2*4;
	draw_win2->pImage[0] = virt_to_phys(fillcolor_osd2);
	draw_win2->go = 1;

	if (GDMA_DrawGraphicWindow(draw_win2) == GDMA_SUCCESS)
		pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD2 Successfully \n");

	draw_win3->plane = VO_GRAPHIC_OSD3;
	draw_win3->winID = winID3;
	draw_win3->storageMode = VO_GRAPHIC_SEQUENTIAL;
	draw_win3->paletteIndex = 0;
	draw_win3->compressed = 0;
	draw_win3->interlace_Frame = 0;
	draw_win3->bottomField = 0;
	draw_win3->startX[0] = 0;
	draw_win3->startY[0] = 0;
	draw_win3->imgPitch[0] = src_w3*4;
	draw_win3->pImage[0] = virt_to_phys(lollipop_360x240);
	draw_win3->go = 1;

	if (GDMA_DrawGraphicWindow(draw_win3) == GDMA_SUCCESS)
		pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD3 Successfully \n");

	draw_win4->plane = VO_GRAPHIC_OSD4;
	draw_win4->winID = winID4;
	draw_win4->storageMode = VO_GRAPHIC_SEQUENTIAL;
	draw_win4->paletteIndex = 0;
	draw_win4->compressed = 0;
	draw_win4->interlace_Frame = 0;
	draw_win4->bottomField = 0;
	draw_win4->startX[0] = 0;
	draw_win4->startY[0] = 0;
	draw_win4->imgPitch[0] = src_w4*4;
	draw_win4->pImage[0] = virt_to_phys(gdma_rtk_logo_260x200);
	draw_win4->go = 1;

	if (GDMA_DrawGraphicWindow(draw_win4) == GDMA_SUCCESS)
		pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD4 Successfully \n");

	draw_win5->plane = VO_GRAPHIC_OSD5;
	draw_win5->winID = winID5;
	draw_win5->storageMode = VO_GRAPHIC_SEQUENTIAL;
	draw_win5->paletteIndex = 0;
	draw_win5->compressed = 0;
	draw_win5->interlace_Frame = 0;
	draw_win5->bottomField = 0;
	draw_win5->startX[0] = 0;
	draw_win5->startY[0] = 0;
	draw_win5->imgPitch[0] = src_w5*4;
	draw_win5->pImage[0] = virt_to_phys(mycursor_120x160);
	draw_win5->go = 1;

	if (GDMA_DrawGraphicWindow(draw_win5) == GDMA_SUCCESS)
		pr_debug("gdma_receivepicture_test:GDMA_DrawGraphicWindow:: OSD5 Successfully \n");

	GDMA_DeleteGraphicWindow(winID, VO_GRAPHIC_OSD1, 1);
	GDMA_DeleteGraphicWindow(winID2, VO_GRAPHIC_OSD2, 1);
	GDMA_DeleteGraphicWindow(winID3, VO_GRAPHIC_OSD3, 1);
	GDMA_DeleteGraphicWindow(winID4, VO_GRAPHIC_OSD4, 1);
	GDMA_DeleteGraphicWindow(winID5, VO_GRAPHIC_OSD5, 1);

	/* online write-back test */
	if (arg == 1) {
		/*ssleep(10); */
		wb.wbAddr = dvr_to_phys((void *)wbaddr);
		wb.wbType = RTKCOMPRESS;	/* ARGB8888  // RBG888 */
		osd_comp_graphic_layers_wb_online(&wb, 1);

		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, 0);
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD2, 0);
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD3, 0);
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD4, 0);
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD5, 0);
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD1, 1);
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD2, 1);
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD3, 1);
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD4, 1);
		GDMA_ConfigOSDxEnable(GDMA_PLANE_OSD5, 1);

		/* send to OSD4 to display for decompression */
		GDMA_PICTURE_OBJECT *picObj;
		PICTURE_LAYERS_OBJECT *pic_layer;

		pic_layer = kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
		memset(pic_layer, 0, sizeof(PICTURE_LAYERS_OBJECT));
		picObj = &pic_layer->layer[0].normal[0];

		pic_layer->layer_num = 1;
		pic_layer->layer[0].normal_num = 1;
		pic_layer->layer[0].onlineOrder = C0;

		picObj->src_type = SRC_NORMAL;
		picObj->format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		/*picObj->fbdc_format;*/
		picObj->context = 0;
		picObj->key_en = 0;
		picObj->colorkey = -1;
		picObj->alpha = 0;
		picObj->x = 0;
		picObj->y = 0;
		picObj->width = gdma->dispWin[0].width;
		picObj->height = gdma->dispWin[0].height;
		picObj->address = wb.wbAddr;
		picObj->pitch = picObj->width * 4;
		picObj->seg_addr[0] = wb.wbAddr;
		picObj->seg_addr[1] = wb.wbAddr;
		/*picObj->picLayout;*/
		picObj->compressed = 0;
		/*picObj->wbType;*/
		/*picObj->seg_num;*/
		/*picObj->current_comp_idx;*/
		/*picObj->comp_plane;*/
		picObj->plane = VO_GRAPHIC_OSD4;
		picObj->dst_x = 0;
		picObj->dst_y = 0;
		picObj->dst_width = gdma->dispWin[0].width;
		picObj->dst_height = gdma->dispWin[0].height;
		picObj->layer_used = 1;
		picObj->plane_ar.plane_alpha_a = 0xff;
		picObj->plane_ar.plane_alpha_r = 0xff;
		picObj->plane_gb.plane_alpha_g = 0xff;
		picObj->plane_gb.plane_alpha_b = 0xff;
		picObj->clear_x.value = 0;
		picObj->clear_y.value = 0;
		picObj->show = 1;
		picObj->decompress = 1;
		/*picObj->paletteformat;*/
		/*picObj->paletteIndex;*/
		/*picObj->rgb_order;*/
		picObj->syncInfo.syncstamp = 0;
		/*picObj->offlineOrder;*/
		picObj->scale_factor = 1;
		/*picObj->isFromOffline;*/

		GDMA_ReceivePicture(pic_layer);
	}
}

/*
*	OSD palette test
*/
void gdma_osdpalette_test(unsigned int arg)
{
	int iloop = 0, jloop = 0, compress = 0, pic_fbWbase;
	static int draw_once_flag = 0;
	gdma_dev *gdma = &gdma_devices[0];
	dma_addr_t addr1, addr2, addr3, addr4;
	static unsigned char *fillcolor = NULL;
	osd_planealpha_ar osdcmp_plane_ar;
	osd_planealpha_gb osdcmp_plane_gb;
	osd_clear_x osdcmp_clearx;
	osd_clear_y osdcmp_cleary;
	ONLINE_WRRITEBACK_STRUCT wb;

	int osd_idx1, osd_idx2, osd_idx3;
	VO_GRAPHIC_PLANE plane1, plane2;/* , plane3; */
	u32 dst_w1, dst_w2, dst_w3, dst_w4, dst_w5, dst_w6;
	u32 dst_h1, dst_h2, dst_h3, dst_h4, dst_h5, dst_h6;
	u32 src_w1, src_w2, src_w3, src_w4, src_w5, src_w6;
	u32 src_h1, src_h2, src_h3, src_h4, src_h5, src_h6;
	int div;

	VO_RECTANGLE disp_res;
	getDispSize(&disp_res);
	pic_fbWbase = disp_res.width;

	osdcmp_clearx.value = 0;
	osdcmp_cleary.value = 0;

	if (arg == 2379) {
		g_sleeptime = g_stop = arg;
	} else {
		g_sleeptime = rtd_inl(0xb800501c);
		g_stop = 0;
	}

	pr_debug("g_sleeptime= %d, g_stop = %d \n", g_sleeptime, g_stop);

	if (fillcolor == NULL)
		fillcolor = kmalloc(1280*720*4, GFP_KERNEL);
	if (g_OSDPalettePattern == NULL)
		g_OSDPalettePattern =  kmalloc(256*4, GFP_KERNEL);
	if (android_test_layer1 == NULL)
		android_test_layer1 = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);

	if (fillcolor == NULL || android_test_layer1 == NULL) {
		pr_debug(KERN_EMERG"malloc fail\n");
		return;
	}

	if (draw_once_flag == 0) {
		memset(android_test_layer1, 0, sizeof(GRAPHIC_LAYERS_OBJECT));
		memset((void *)fillcolor, 0xff, 1280*720*4);
		memset(g_OSDPalettePattern, 0x00, 256*4);
	}
	pr_debug(KERN_EMERG"Virtual fillcolor=0x%x \n", (uint32_t)fillcolor);
	pr_debug(KERN_EMERG"Physical fillcolor=0x%x\n", virt_to_phys(fillcolor));

	dsb();
	addr1 = dma_map_single(gdma->dev, (void *)fillcolor, 1280*720*4, DMA_TO_DEVICE);

	if (dma_mapping_error(gdma->dev, addr1))
		pr_debug("dma_map_single fail addr1 \n");


	/* Palette format is ABGR */
	g_OSDPalettePattern[0] = 0xFFFF0000;
	g_OSDPalettePattern[1] = 0xFF00FF00;
	g_OSDPalettePattern[2] = 0xFF0000FF;
	g_OSDPalettePattern[3] = 0xFFFFFFFF;
	g_OSDPalettePattern[4] = 0xFF000000;


	memcpy (gdma->OSD_CLUT[0], (void *)(g_OSDPalettePattern), sizeof(unsigned int) * 256);

	if (draw_once_flag == 0) {
		/*  make image source */
		div = ((640 * 360) / 10);
		for (iloop = 0; iloop < 1280*720; iloop++) {
			if (iloop < ((1280*720)/2)) {
				jloop = iloop%1280;
				if (jloop < 300)
					fillcolor[iloop] = 0;/* */
				else if ((jloop >= 300) && (jloop < 600))
					fillcolor[iloop] = 1;/*  */
				else if ((jloop >= 600) && (jloop < 1280))
					fillcolor[iloop] = 2;/*  */
			} else {
				jloop = iloop%1280;
				if (jloop < 500)
					fillcolor[iloop] = 3;/*  */
				else if ((jloop >= 500) && (jloop < 1000))
					fillcolor[iloop] = 4;/*  */
				else if ((jloop >= 1000) && (jloop < 1280))
					fillcolor[iloop] = 0;/*  */
			}

		}
		draw_once_flag = 1;
	}

	dma_sync_single_for_device(gdma->dev, addr1, 1280*720*4, DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr1, 1280*720*4, DMA_TO_DEVICE);


	osdcmp_plane_ar.plane_alpha_r = 0xff;
	osdcmp_plane_ar.plane_alpha_a = 0xff;
	osdcmp_plane_gb.plane_alpha_g = 0xff;
	osdcmp_plane_gb.plane_alpha_b = 0xff;


	/* compressed test flag */
	compress = 0;

	/*  thread1: 2 layers: normal */
	src_w1 = 1280;
	src_h1 = 720;
	dst_w1 = 1280;
	dst_h1 = 720;

	GDMA_PICTURE_OBJECT *picObj;
	static PICTURE_LAYERS_OBJECT *pic_layer = NULL;

	if (pic_layer== NULL)
		pic_layer = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (pic_layer == NULL) {
		pr_debug("%s, pic_layer kmalloc failed \n", __FUNCTION__);
		return;
	}
	memset(pic_layer, 0, sizeof(PICTURE_LAYERS_OBJECT));
	picObj = &pic_layer->layer[0].normal[0];


	picObj->format = VO_OSD_COLOR_FORMAT_8BIT;
	picObj->plane = VO_GRAPHIC_OSD1;
	pic_layer->layer[0].onlineOrder = C0;


	pic_layer->layer_num = 1;
	pic_layer->layer[0].normal_num = 1;
	//pic_layer->layer[0].onlineOrder = C0;

	picObj->src_type = SRC_NORMAL;
	//picObj->format;
	//picObj->fbdc_format;
	picObj->context = 0;
	picObj->key_en = 0;
	picObj->colorkey = -1;
	picObj->alpha = 0;
	picObj->x = 0;
	picObj->y = 0;
	picObj->width = src_w1;
	picObj->height = src_h1;
	picObj->address = virt_to_phys(fillcolor);
	picObj->pitch = src_w1;
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
	picObj->paletteformat = 1; /* rgba format */
	//picObj->paletteIndex;
	//picObj->rgb_order;
	picObj->syncInfo.syncstamp = 0;
	//picObj->offlineOrder;
	picObj->scale_factor = 1;
	//picObj->isFromOffline;

	picObj->dst_x = 0;
	picObj->dst_y = 0;

	picObj->dst_width = dst_w1;
	picObj->dst_height = dst_h1;


	GDMA_ReceivePicture(pic_layer);
}


/*
*   fbdc test
*/
void gdma_fbdc_test(unsigned int arg)
{
	int compress = 0, pic_fbWbase;
	gdma_dev *gdma = &gdma_devices[0];
	int iloop = 0, jloop = 0;
	u32 dst_w1, dst_w2, dst_w3, dst_w4, dst_w5, dst_w6;
	u32 dst_h1, dst_h2, dst_h3, dst_h4, dst_h5, dst_h6;
	u32 src_w1, src_w2, src_w3, src_w4, src_w5, src_w6;
	u32 src_h1, src_h2, src_h3, src_h4, src_h5, src_h6;
	osd_planealpha_ar osdcmp_plane_ar;
	osd_planealpha_gb osdcmp_plane_gb;
	osd_clear_x osdcmp_clearx;
	osd_clear_y osdcmp_cleary;
	VO_RECTANGLE disp_res;
	static unsigned int wbaddr = 0;
	ONLINE_WRRITEBACK_STRUCT wb;
	static u32 pliaddr1 = 0, pliaddr2 = 0, pliaddr3 = 0, pliaddr4 = 0, pliaddr5 = 0, pliaddr6 = 0;
	getDispSize(&disp_res);

	if (android_test_layer1 == NULL)
		android_test_layer1 = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);
	if (wbaddr == 0)
		wbaddr = (unsigned int)dvr_malloc_specific(TWOK_W*ONEK_H*4, GFP_DCU1);

	if (android_test_layer1 == NULL) {
		pr_debug(KERN_EMERG"malloc fail\n");
		return;
	}
	memset(android_test_layer1, 0, sizeof(GRAPHIC_LAYERS_OBJECT));

	if (pliaddr1 == 0) {
		pliaddr1 = (unsigned int)dvr_malloc_specific(0x800000, GFP_DCU2);
		pliaddr2 = (unsigned int)dvr_malloc_specific(0x800000, GFP_DCU2);
		pliaddr3 = (unsigned int)dvr_malloc_specific(0x400000, GFP_DCU2);
		pliaddr4 = (unsigned int)dvr_malloc_specific(0x400000, GFP_DCU2);
		pliaddr5 = (unsigned int)dvr_malloc_specific(0x200000, GFP_DCU2);
		pliaddr6 = (unsigned int)dvr_malloc_specific(0x200000, GFP_DCU2);
		/*dvr_to_phys((void *)pliaddr1);*/
		pr_debug(KERN_EMERG"pliaddr1=0x%x, pliaddr2=0x%x \n", dvr_to_phys((void *)pliaddr1), dvr_to_phys((void *)pliaddr2));
		pr_debug(KERN_EMERG"pliaddr3=0x%x, pliaddr4=0x%x \n", dvr_to_phys((void *)pliaddr3), dvr_to_phys((void *)pliaddr4));
		pr_debug(KERN_EMERG"pliaddr5=0x%x, pliaddr6=0x%x \n", dvr_to_phys((void *)pliaddr5), dvr_to_phys((void *)pliaddr6));
		pr_debug(KERN_EMERG"wbaddr=0x%x\n", dvr_to_phys((void *)wbaddr));
	}

	osdcmp_clearx.value = 0;
	osdcmp_cleary.value = 0;
	osdcmp_plane_ar.plane_alpha_r = 0xff;
	osdcmp_plane_ar.plane_alpha_a = 0xff;
	osdcmp_plane_gb.plane_alpha_g = 0xff;
	osdcmp_plane_gb.plane_alpha_b = 0xff;

	pic_fbWbase = disp_res.width;


	unsigned int fbdc320x240_info_bin = dvr_to_phys((void *)pliaddr6);
	unsigned int fbdc640x480 = dvr_to_phys((void *)pliaddr5);
	unsigned int fbdcsummer_1280x720 = dvr_to_phys((void *)pliaddr4);
	unsigned int fbdcNew_Zealand_1280x720 = dvr_to_phys((void *)pliaddr3);
	unsigned int fbdcLandscape_1920x1080 = dvr_to_phys((void *)pliaddr2);
	unsigned int fbdc1920x1080 = dvr_to_phys((void *)pliaddr1);

	/*
	src_w1 = 320;
	src_h1 = 240;
	dst_w1 = 1920;
	dst_h1 = 1080;
	*/

	src_w1 = 1280;
	src_h1 = 720;
	dst_w1 = 1280;
	dst_h1 = 720;


	//src_w1 = 1920;
	//src_h1 = 1080;
	//dst_w1 = 1920;
	//dst_h1 = 1080;

	src_w2 = 1920;
	src_h2 = 1080;
	dst_w2 = 1920;
	dst_h2 = 1080;

	//src_w3 = 1280;
	//src_h3 = 720;
	//dst_w3 = 1280;
	//dst_h3 = 720;
	src_w3 = 1920;
	src_h3 = 1080;
	dst_w3 = 1920;
	dst_h3 = 1080;

	src_w4 = 1280;
	src_h4 = 720;
	dst_w4 = 1280;
	dst_h4 = 720;

	src_w5 = 640;
	src_h5 = 480;
	dst_w5 = 640;
	dst_h5 = 480;

	src_w6 = 320;
	src_h6 = 240;
	dst_w6 = 320;
	dst_h6 = 240;


	android_test_layer1->layer_num = 6;

	/*g_sleeptime = arg;*/

	android_test_layer1->layer[0].src_type = SRC_FBDC;
	/*android_test_layer1->layer[0].format = VO_OSD_COLOR_FORMAT_RGBA8888;*/
	android_test_layer1->layer[0].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
	//android_test_layer1->layer[0].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
	android_test_layer1->layer[0].context = 0; /*  ?? */
	android_test_layer1->layer[0].key_en = 0;
	android_test_layer1->layer[0].colorkey = -1;
	android_test_layer1->layer[0].alpha = 0x00;
	android_test_layer1->layer[0].x = 0;
	android_test_layer1->layer[0].y = 0;
	android_test_layer1->layer[0].height = src_h1;
	android_test_layer1->layer[0].width = src_w1;
	//android_test_layer1->layer[0].address = (unsigned int)(fbdc1920x1080);
	android_test_layer1->layer[0].address = (unsigned int)(fbdcNew_Zealand_1280x720);
	android_test_layer1->layer[0].pitch = android_test_layer1->layer[0].width*4;
	android_test_layer1->layer[0].dst_x = 0;
	android_test_layer1->layer[0].dst_y = 0;
	android_test_layer1->layer[0].dst_height = dst_h1;
	android_test_layer1->layer[0].dst_width = dst_w1;
	android_test_layer1->layer[0].compressed = compress;    /*compress test*/
	android_test_layer1->layer[0].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[0].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[0].clear_x = osdcmp_clearx;
	android_test_layer1->layer[0].clear_y = osdcmp_cleary;
	android_test_layer1->layer[0].syncstamp = 0;
	android_test_layer1->layer[0].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[0].show = 1;


	android_test_layer1->layer[1].src_type = SRC_FBDC;
	/*android_test_layer1->layer[1].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;*/
	android_test_layer1->layer[1].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
	android_test_layer1->layer[1].context = 0; /*  ?? */
	android_test_layer1->layer[1].key_en = 0;
	android_test_layer1->layer[1].colorkey = -1;
	android_test_layer1->layer[1].alpha = 0x00;
	android_test_layer1->layer[1].x = 0;
	android_test_layer1->layer[1].y = 0;
	android_test_layer1->layer[1].height = src_h2;
	android_test_layer1->layer[1].width = src_w2;
	android_test_layer1->layer[1].address = (unsigned int)(fbdcLandscape_1920x1080);
	android_test_layer1->layer[1].pitch = android_test_layer1->layer[1].width*4;
	android_test_layer1->layer[1].dst_x = 0;
	android_test_layer1->layer[1].dst_y = 0;
	android_test_layer1->layer[1].dst_height = dst_h2;
	android_test_layer1->layer[1].dst_width = dst_w2;
	android_test_layer1->layer[1].compressed = compress;
	android_test_layer1->layer[1].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[1].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[1].clear_x = osdcmp_clearx;
	android_test_layer1->layer[1].clear_y = osdcmp_cleary;
	android_test_layer1->layer[1].syncstamp = 0;
	android_test_layer1->layer[1].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[1].show = 1;


	android_test_layer1->layer[2].src_type = SRC_FBDC;
	/*android_test_layer1->layer[2].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;*/
	android_test_layer1->layer[2].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
	android_test_layer1->layer[2].context = 0; /*  ?? */
	android_test_layer1->layer[2].key_en = 0;
	android_test_layer1->layer[2].colorkey = -1;
	android_test_layer1->layer[2].alpha = 0x00;
	android_test_layer1->layer[2].x = 0;
	android_test_layer1->layer[2].y = 0;
	android_test_layer1->layer[2].height = src_h3;
	android_test_layer1->layer[2].width = src_w3;
	//android_test_layer1->layer[2].address = (unsigned int)(fbdcNew_Zealand_1280x720);
	android_test_layer1->layer[2].address = (unsigned int)(fbdc1920x1080);
	android_test_layer1->layer[2].pitch = android_test_layer1->layer[2].width*4;
	android_test_layer1->layer[2].dst_x = 0;
	android_test_layer1->layer[2].dst_y = 0;
	android_test_layer1->layer[2].dst_height = dst_h3;
	android_test_layer1->layer[2].dst_width = dst_w3;
	android_test_layer1->layer[2].compressed = compress;
	android_test_layer1->layer[2].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[2].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[2].clear_x = osdcmp_clearx;
	android_test_layer1->layer[2].clear_y = osdcmp_cleary;
	android_test_layer1->layer[2].syncstamp = 0;
	android_test_layer1->layer[2].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[2].show = 1;


	android_test_layer1->layer[3].src_type = SRC_FBDC;
	/*android_test_layer1->layer[3].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;*/
	android_test_layer1->layer[3].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
	android_test_layer1->layer[3].context = 0; /*  ?? */
	android_test_layer1->layer[3].key_en = 0;
	android_test_layer1->layer[3].colorkey = -1;
	android_test_layer1->layer[3].alpha = 0x80;
	android_test_layer1->layer[3].x = 0;
	android_test_layer1->layer[3].y = 0;
	android_test_layer1->layer[3].height = src_h4;
	android_test_layer1->layer[3].width = src_w4;
	android_test_layer1->layer[3].address = (unsigned int)(fbdcsummer_1280x720);
	android_test_layer1->layer[3].pitch = android_test_layer1->layer[3].width*4;
	android_test_layer1->layer[3].dst_x = 200;
	android_test_layer1->layer[3].dst_y = 200;
	android_test_layer1->layer[3].dst_height = dst_h4;
	android_test_layer1->layer[3].dst_width = dst_w4;
	android_test_layer1->layer[3].compressed = compress;
	android_test_layer1->layer[3].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[3].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[3].clear_x = osdcmp_clearx;
	android_test_layer1->layer[3].clear_y = osdcmp_cleary;
	android_test_layer1->layer[3].syncstamp = 0;
	android_test_layer1->layer[3].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[3].show = 1;


	android_test_layer1->layer[4].src_type = SRC_FBDC;
	/*android_test_layer1->layer[4].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;*/
	android_test_layer1->layer[4].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
	android_test_layer1->layer[4].context = 0; /*  ?? */
	android_test_layer1->layer[4].key_en = 0;
	android_test_layer1->layer[4].colorkey = -1;
	android_test_layer1->layer[4].alpha = 0x80;
	android_test_layer1->layer[4].x = 0;
	android_test_layer1->layer[4].y = 0;
	android_test_layer1->layer[4].height = src_h5;
	android_test_layer1->layer[4].width = src_w5;
	android_test_layer1->layer[4].address = (unsigned int)(fbdc640x480);
	android_test_layer1->layer[4].pitch = android_test_layer1->layer[4].width*4;
	android_test_layer1->layer[4].dst_x = 0;
	android_test_layer1->layer[4].dst_y = 0;
	android_test_layer1->layer[4].dst_height = dst_h5;
	android_test_layer1->layer[4].dst_width = dst_w5;
	android_test_layer1->layer[4].compressed = compress;
	android_test_layer1->layer[4].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[4].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[4].clear_x = osdcmp_clearx;
	android_test_layer1->layer[4].clear_y = osdcmp_cleary;
	android_test_layer1->layer[4].syncstamp = 0;
	android_test_layer1->layer[4].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[4].show = 1;


	android_test_layer1->layer[5].src_type = SRC_FBDC;
	/*android_test_layer1->layer[5].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;*/
	android_test_layer1->layer[5].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
	android_test_layer1->layer[5].context = 0; /*  ?? */
	android_test_layer1->layer[5].key_en = 0;
	android_test_layer1->layer[5].colorkey = -1;
	android_test_layer1->layer[5].alpha = 0x80;
	android_test_layer1->layer[5].x = 0;
	android_test_layer1->layer[5].y = 0;
	android_test_layer1->layer[5].height = src_h6;
	android_test_layer1->layer[5].width = src_w6;
	android_test_layer1->layer[5].address = (unsigned int)(fbdc320x240_info_bin);
	android_test_layer1->layer[5].pitch = android_test_layer1->layer[5].width*4;
	android_test_layer1->layer[5].dst_x = 640;
	android_test_layer1->layer[5].dst_y = 480;
	android_test_layer1->layer[5].dst_height = dst_h6;
	android_test_layer1->layer[5].dst_width = dst_w6;
	android_test_layer1->layer[5].compressed = compress;
	android_test_layer1->layer[5].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[5].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[5].clear_x = osdcmp_clearx;
	android_test_layer1->layer[5].clear_y = osdcmp_cleary;
	android_test_layer1->layer[5].syncstamp = 0;
	android_test_layer1->layer[5].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[5].show = 1;

	if (arg == 0) {
		GDMA_ReceiveGraphicLayers(android_test_layer1);
		/*GDMA_ReceivePicture(&pic_layer);*/
	} else if (arg == 1) {
		/* TODO: two FBDC layers go through offline and make RTK compress, then  display out */

		src_w1 = 1280;
		src_h1 = 720;
		dst_w1 = 1920;
		dst_h1 = 1080;
		src_w2 = 640;
		src_h2 = 480;
		dst_w2 = 640;
		dst_h2 = 480;
		src_w3 = 320;
		src_h3 = 240;
		dst_w3 = 320;
		dst_h3 = 240;

		compress = 1;

		android_test_layer1->layer_num = 3;

		android_test_layer1->layer[0].src_type = SRC_FBDC;
		/*android_test_layer1->layer[0].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;*/
		android_test_layer1->layer[0].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
		android_test_layer1->layer[0].context = 0; /*  ?? */
		android_test_layer1->layer[0].key_en = 0;
		android_test_layer1->layer[0].colorkey = -1;
		android_test_layer1->layer[0].alpha = 0x00;
		android_test_layer1->layer[0].x = 0;
		android_test_layer1->layer[0].y = 0;
		android_test_layer1->layer[0].height = src_h1;
		android_test_layer1->layer[0].width = src_w1;
		android_test_layer1->layer[0].address = (unsigned int)(fbdcsummer_1280x720);
		android_test_layer1->layer[0].pitch = android_test_layer1->layer[0].width*4;
		android_test_layer1->layer[0].dst_x = 200;
		android_test_layer1->layer[0].dst_y = 200;
		android_test_layer1->layer[0].dst_height = dst_h1;
		android_test_layer1->layer[0].dst_width = dst_w1;
		android_test_layer1->layer[0].compressed = compress;
		android_test_layer1->layer[0].plane_ar = osdcmp_plane_ar;
		android_test_layer1->layer[0].plane_gb = osdcmp_plane_gb;
		android_test_layer1->layer[0].clear_x = osdcmp_clearx;
		android_test_layer1->layer[0].clear_y = osdcmp_cleary;
		android_test_layer1->layer[0].syncstamp = 0;
		android_test_layer1->layer[0].scale_factor = disp_res.width/pic_fbWbase;
		android_test_layer1->layer[0].show = 1;


		android_test_layer1->layer[1].src_type = SRC_FBDC;
		/*android_test_layer1->layer[1].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;*/
		android_test_layer1->layer[1].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
		android_test_layer1->layer[1].context = 0; /*  ?? */
		android_test_layer1->layer[1].key_en = 0;
		android_test_layer1->layer[1].colorkey = -1;
		android_test_layer1->layer[1].alpha = 0x00;
		android_test_layer1->layer[1].x = 0;
		android_test_layer1->layer[1].y = 0;
		android_test_layer1->layer[1].height = src_h2;
		android_test_layer1->layer[1].width = src_w2;
		android_test_layer1->layer[1].address = (unsigned int)(fbdc640x480);
		android_test_layer1->layer[1].pitch = android_test_layer1->layer[1].width*4;
		android_test_layer1->layer[1].dst_x = 0;
		android_test_layer1->layer[1].dst_y = 0;
		android_test_layer1->layer[1].dst_height = dst_h2;
		android_test_layer1->layer[1].dst_width = dst_w2;
		android_test_layer1->layer[1].compressed = compress;
		android_test_layer1->layer[1].plane_ar = osdcmp_plane_ar;
		android_test_layer1->layer[1].plane_gb = osdcmp_plane_gb;
		android_test_layer1->layer[1].clear_x = osdcmp_clearx;
		android_test_layer1->layer[1].clear_y = osdcmp_cleary;
		android_test_layer1->layer[1].syncstamp = 0;
		android_test_layer1->layer[1].scale_factor = disp_res.width/pic_fbWbase;
		android_test_layer1->layer[1].show = 1;


		android_test_layer1->layer[2].src_type = SRC_FBDC;
		/*android_test_layer1->layer[2].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;*/
		android_test_layer1->layer[2].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;
		android_test_layer1->layer[2].context = 0; /*  ?? */
		android_test_layer1->layer[2].key_en = 0;
		android_test_layer1->layer[2].colorkey = -1;
		android_test_layer1->layer[2].alpha = 0x00;
		android_test_layer1->layer[2].x = 0;
		android_test_layer1->layer[2].y = 0;
		android_test_layer1->layer[2].height = src_h3;
		android_test_layer1->layer[2].width = src_w3;
		android_test_layer1->layer[2].address = (unsigned int)(fbdc320x240_info_bin);
		android_test_layer1->layer[2].pitch = android_test_layer1->layer[2].width*4;
		android_test_layer1->layer[2].dst_x = 640;
		android_test_layer1->layer[2].dst_y = 480;
		android_test_layer1->layer[2].dst_height = dst_h3;
		android_test_layer1->layer[2].dst_width = dst_w3;
		android_test_layer1->layer[2].compressed = compress;
		android_test_layer1->layer[2].plane_ar = osdcmp_plane_ar;
		android_test_layer1->layer[2].plane_gb = osdcmp_plane_gb;
		android_test_layer1->layer[2].clear_x = osdcmp_clearx;
		android_test_layer1->layer[2].clear_y = osdcmp_cleary;
		android_test_layer1->layer[2].syncstamp = 0;
		android_test_layer1->layer[2].scale_factor = disp_res.width/pic_fbWbase;
		android_test_layer1->layer[2].show = 1;


		GDMA_ReceiveGraphicLayers(android_test_layer1);
	} else if (arg == 2) {

		GDMA_ReceiveGraphicLayers(android_test_layer1);

		unsigned int start, end;

		start = rtd_inl(MIS_SCPU_CLK90K_LO_reg);
		wb.wbAddr = dvr_to_phys((void *)wbaddr);
		wb.wbType = RTKCOMPRESS;	/* ARGB8888  // RBG888 */
		osd_comp_graphic_layers_wb_online(&wb, 1);
		end = rtd_inl(MIS_SCPU_CLK90K_LO_reg);
		pr_debug(KERN_EMERG"online write-back time %d \n", end-start);

		src_w1 = disp_res.width;
		src_h1 = disp_res.height;
		dst_w1 = disp_res.width;
		dst_h1 = disp_res.height;

		android_test_layer1->layer_num = 1;

		android_test_layer1->layer[0].src_type = SRC_NORMAL;
		android_test_layer1->layer[0].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		/*android_test_layer1->layer[0].fbdc_format = FBDC_COLOR_FORMAT_U8U8U8U8;*/
		android_test_layer1->layer[0].context = 0; /*  ?? */
		android_test_layer1->layer[0].key_en = 0;
		android_test_layer1->layer[0].colorkey = -1;
		android_test_layer1->layer[0].alpha = 0x00;
		android_test_layer1->layer[0].x = 0;
		android_test_layer1->layer[0].y = 0;
		android_test_layer1->layer[0].height = src_h1;
		android_test_layer1->layer[0].width = src_w1;
		android_test_layer1->layer[0].address = (unsigned int)(wb.wbAddr);
		android_test_layer1->layer[0].pitch = android_test_layer1->layer[0].width*4;
		android_test_layer1->layer[0].dst_x = 0;
		android_test_layer1->layer[0].dst_y = 0;
		android_test_layer1->layer[0].dst_height = dst_h1;
		android_test_layer1->layer[0].dst_width = dst_w1;
		android_test_layer1->layer[0].compressed = 0;
		android_test_layer1->layer[0].decompress = 1;
		android_test_layer1->layer[0].plane_ar = osdcmp_plane_ar;
		android_test_layer1->layer[0].plane_gb = osdcmp_plane_gb;
		android_test_layer1->layer[0].clear_x = osdcmp_clearx;
		android_test_layer1->layer[0].clear_y = osdcmp_cleary;
		android_test_layer1->layer[0].syncstamp = 0;
		android_test_layer1->layer[0].scale_factor = disp_res.width/pic_fbWbase;
		android_test_layer1->layer[0].show = 1;
		GDMA_ReceiveGraphicLayers(android_test_layer1);
	}
}

/*
*   osd split test
*/
void gdma_osd_split_test(unsigned int arg)
{
	CONFIG_OSDSPLIT_STRUCT data;
	int loop = 0;

	data.osdSplitEn = arg;
	data.osdSplitHeaderEn = 1;
	data.header_h_sta = 0;
	data.header_v_sta = 0;
	data.emptyPixel = 0;

	for (loop = 0; loop < (sizeof(data.osdSplitHeader)/sizeof(unsigned int)); loop++)
		data.osdSplitHeader[loop] = 0x12345678;

	GDMA_OSDSplitSet(&data);
}

/*
*	suspend / resume test
*/
void gdma_suspend_resume_test(unsigned int arg)
{
	osdovl_osd_db_ctrl_RBUS osd_db_ctrl_reg;

	pr_debug(KERN_EMERG"++++%s \n", __FUNCTION__);

	gdma_osdx_test((1<<VO_GRAPHIC_OSD1) | (1<<VO_GRAPHIC_OSD2));

	gdma_suspend(NULL);

#if 0
	/* IP reset */
	/* disable osd/gdma clock  */
	rtd_outl(CRT_SYS_DISPCLKSEL_reg, rtd_inl(CRT_SYS_DISPCLKSEL_reg) &
										~(CRT_SYS_DISPCLKSEL_clken_disp_osd(1) |
										CRT_SYS_DISPCLKSEL_clken_disp_gdma(1)));

	/* reset */
	msleep(10);
	rtd_outl(CRT_SYS_SRST1_reg, rtd_inl(CRT_SYS_SRST1_reg) & ~CRT_SYS_SRST1_rstn_disp_mask);
	msleep(10);
	rtd_outl(CRT_SYS_SRST1_reg, rtd_inl(CRT_SYS_SRST1_reg) | CRT_SYS_SRST1_rstn_disp_mask);
	msleep(10);

	/* clock enable */
	rtd_outl(CRT_SYS_DISPCLKSEL_reg, rtd_inl(CRT_SYS_DISPCLKSEL_reg) |
										CRT_SYS_DISPCLKSEL_clken_disp_osd(1) |
										CRT_SYS_DISPCLKSEL_clken_disp_gdma(1));
#else
	rtd_outl(GDMA_OSD1_CTRL_reg, ~1);
	rtd_outl(GDMA_OSD2_CTRL_reg, ~1);
	rtd_outl(GDMA_OSD4_CTRL_reg, ~1);
	rtd_outl(GDMA_OSD1_reg, ~1);
	rtd_outl(GDMA_OSD2_reg, ~1);
	rtd_outl(GDMA_OSD4_reg, ~1);
	rtd_outl(GDMA_OSD1_WI_reg, 0);
	rtd_outl(GDMA_OSD2_WI_reg, 0);
	rtd_outl(GDMA_OSD4_WI_reg, 0);
	rtd_outl(GDMA_OSD1_SIZE_reg, 0);
	rtd_outl(GDMA_OSD2_SIZE_reg, 0);
	rtd_outl(GDMA_OSD4_SIZE_reg, 0);
	rtd_outl(GDMA_ONLINE_reg, 0);
	rtd_outl(GDMA_LINE_BUFFER_STA_reg, 0);
	rtd_outl(GDMA_LINE_BUFFER_SIZE_reg, 0);
	rtd_outl(GDMA_LINE_BUFFER_END_reg, 0);
	rtd_outl(OSDOVL_Mixer_CTRL2_reg, 0);
	rtd_outl(OSDOVL_Mixer_layer_sel_reg, 0);
	rtd_outl(OSD_SR_1_Scaleup_Ctrl0_reg, 0);
	rtd_outl(OSD_SR_1_Scaleup_Ctrl1_reg, 0);
	rtd_outl(OSD_SR_1_H_Location_Ctrl_reg, 0);
	rtd_outl(OSD_SR_1_V_Location_Ctrl_reg, 0);
	rtd_outl(OSD_SR_2_Scaleup_Ctrl0_reg, 0);
	rtd_outl(OSD_SR_2_Scaleup_Ctrl1_reg, 0);
	rtd_outl(OSD_SR_2_H_Location_Ctrl_reg, 0);
	rtd_outl(OSD_SR_2_V_Location_Ctrl_reg, 0);
	rtd_outl(OSD_SR_3_Scaleup_Ctrl0_reg, 0);
	rtd_outl(OSD_SR_3_Scaleup_Ctrl1_reg, 0);
	rtd_outl(OSD_SR_3_H_Location_Ctrl_reg, 0);
	rtd_outl(OSD_SR_3_V_Location_Ctrl_reg, 0);

	osd_db_ctrl_reg.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
	osd_db_ctrl_reg.db_load = 1;
	rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, osd_db_ctrl_reg.regValue); /*  mixer apply */
	rtd_outl(GDMA_CTRL_reg, GDMA_CTRL_osd_others_prog_done_mask |
									GDMA_CTRL_osd4_prog_done_mask |
									GDMA_CTRL_osd2_prog_done_mask |
									GDMA_CTRL_osd1_prog_done_mask);  /*  gdma & sr programming done */
#endif

	ssleep(10);

	gdma_resume(NULL);
}

/*
*   switch online/offline test
*/
void gdma_switchOnOffline_test(unsigned int arg)
{
	int compress = 0, pic_fbWbase;

	gdma_dev *gdma = &gdma_devices[0];
	int iloop = 0, jloop = 0;
	static unsigned int *fillcolor = NULL, *fillcolor_osd2 = NULL;
	static unsigned int wbaddr = 0;
	u32 dst_w1, dst_w2, dst_w3, dst_w4, dst_w5, dst_w6;
	u32 dst_h1, dst_h2, dst_h3, dst_h4, dst_h5, dst_h6;
	u32 src_w1, src_w2, src_w3, src_w4, src_w5, src_w6;
	u32 src_h1, src_h2, src_h3, src_h4, src_h5, src_h6;
	ONLINE_WRRITEBACK_STRUCT wb;
	osd_planealpha_ar osdcmp_plane_ar;
	osd_planealpha_gb osdcmp_plane_gb;
	osd_clear_x osdcmp_clearx;
	osd_clear_y osdcmp_cleary;
	VO_RECTANGLE disp_res;
	getDispSize(&disp_res);

	osdcmp_clearx.value = 0;
	osdcmp_cleary.value = 0;
	osdcmp_plane_ar.plane_alpha_r = 0xff;
	osdcmp_plane_ar.plane_alpha_a = 0xff;
	osdcmp_plane_gb.plane_alpha_g = 0xff;
	osdcmp_plane_gb.plane_alpha_b = 0xff;
	pic_fbWbase = disp_res.width;

	if (fillcolor == NULL)
		fillcolor = kmalloc(1280*720*4, GFP_KERNEL);
	if (fillcolor_osd2 == NULL)
		fillcolor_osd2 = kmalloc(1280*720*4, GFP_KERNEL);
	if (wbaddr == 0)
		/*wbaddr = kmalloc(TWOK_W*ONEK_H*4, GFP_KERNEL);*/
		wbaddr = (unsigned int)dvr_malloc_specific(TWOK_W*ONEK_H*4, GFP_DCU1);
	if (android_test_layer1 == NULL)
		android_test_layer1 = kmalloc(sizeof(GRAPHIC_LAYERS_OBJECT), GFP_KERNEL);
	if (fillcolor == NULL || fillcolor_osd2 == NULL || wbaddr == NULL) {
		pr_debug(KERN_EMERG"malloc fail\n");
		return;
	}

	memset(fillcolor, 0xff, 1280*720);
	memset(fillcolor_osd2, 0xff, 1280*720);
	pr_debug(KERN_EMERG"fillcolor=0x%x\n", (unsigned int)fillcolor);
	pr_debug(KERN_EMERG"fillcolor=0x%x\n", virt_to_phys(fillcolor));
	pr_debug(KERN_EMERG"fillcolor_osd2=0x%x\n", virt_to_phys(fillcolor_osd2));
	pr_debug(KERN_EMERG"wbaddr=0x%x\n", dvr_to_phys((void *)wbaddr));


	for (iloop = 0; iloop < 1280*720; iloop++) {
		if (iloop < ((1280*720)/2)) {
			jloop = iloop%1280;
			if (jloop < 300)
				fillcolor[iloop] = 0xff0000ff;/* Red/RGBA */
			else if ((jloop >= 300) && (jloop < 600))
				fillcolor[iloop] = 0xff00ff00;/* Green */
			else if ((jloop >= 600) && (jloop < 1280))
				fillcolor[iloop] = 0xffff0000;/* Blue */
		} else {
			jloop = iloop%1280;
			if (jloop < 500)
				fillcolor[iloop] = 0xffff00ff;/* Red */
			else if ((jloop >= 500) && (jloop < 1000))
				fillcolor[iloop] = 0xffffffff;/* white */
			else if ((jloop >= 1000) && (jloop < 1280))
				fillcolor[iloop] = 0xff00ffff;/* yellow */
		}

		if (iloop < ((1280*720)/4))
			fillcolor_osd2[iloop] = 0xff7b7b7b;/* Red//RGBA, big-endian */
		else if (iloop >= ((1280*720)/4) && iloop < ((1280*720)/2))
			fillcolor_osd2[iloop] = 0xffffffff;
		else if (iloop >= ((1280*720)/2) && iloop < (((1280*720)/4)*3))
			fillcolor_osd2[iloop] = 0xff7b7b7b;
		else if (iloop >= (((1280*720)/4)*3) && iloop < (1280*720))
			fillcolor_osd2[iloop] = 0xffffffff;
	}


	src_w1 = 1280;
	src_h1 = 720;
	dst_w1 = 1920;
	dst_h1 = 1080;
	src_w2 = 1280;
	src_h2 = 720;
	dst_w2 = 1920;
	dst_h2 = 1080;
	src_w3 = 360;
	src_h3 = 240;
	dst_w3 = 1920;
	dst_h3 = 1080;
	src_w4 = 260;
	src_h4 = 200;
	dst_w4 = 260;
	dst_h4 = 200;
	src_w5 = 120;
	src_h5 = 160;
	dst_w5 = 1920;
	dst_h5 = 1080;

	compress = 0;

	memset(android_test_layer1, 0, sizeof(GRAPHIC_LAYERS_OBJECT));

	android_test_layer1->layer_num = 5;
	android_test_layer1->cookie = 0;

	android_test_layer1->layer[0].src_type = SRC_NORMAL;
	android_test_layer1->layer[0].format = VO_OSD_COLOR_FORMAT_RGBA8888;
	android_test_layer1->layer[0].context = 0; /*  ?? */
	android_test_layer1->layer[0].key_en = 0;
	android_test_layer1->layer[0].colorkey = -1;
	android_test_layer1->layer[0].alpha = 0x00;
	android_test_layer1->layer[0].x = 0;
	android_test_layer1->layer[0].y = 0;
	android_test_layer1->layer[0].height = src_h1;
	android_test_layer1->layer[0].width = src_w1;
	android_test_layer1->layer[0].address = virt_to_phys(fillcolor);
	android_test_layer1->layer[0].pitch = android_test_layer1->layer[0].width*4;
	android_test_layer1->layer[0].dst_x = 0;
	android_test_layer1->layer[0].dst_y = 0;
	android_test_layer1->layer[0].dst_height = dst_h1;
	android_test_layer1->layer[0].dst_width = dst_w1;
	android_test_layer1->layer[0].compressed = compress;    /*compress test*/
	android_test_layer1->layer[0].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[0].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[0].clear_x = osdcmp_clearx;
	android_test_layer1->layer[0].clear_y = osdcmp_cleary;
	android_test_layer1->layer[0].syncstamp = 0;
	android_test_layer1->layer[0].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[0].show = 1;


	android_test_layer1->layer[1].src_type = SRC_NORMAL;
	android_test_layer1->layer[1].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[1].context = 0; /*  ?? */
	android_test_layer1->layer[1].key_en = 0;
	android_test_layer1->layer[1].colorkey = -1;
	android_test_layer1->layer[1].alpha = 0x80;
	android_test_layer1->layer[1].x = 0;
	android_test_layer1->layer[1].y = 0;
	android_test_layer1->layer[1].height = src_h2;
	android_test_layer1->layer[1].width = src_w2;
	android_test_layer1->layer[1].address = virt_to_phys(fillcolor_osd2);
	android_test_layer1->layer[1].pitch = android_test_layer1->layer[1].width*4;
	android_test_layer1->layer[1].dst_x = 0;
	android_test_layer1->layer[1].dst_y = 0;
	android_test_layer1->layer[1].dst_height = dst_h2;
	android_test_layer1->layer[1].dst_width = dst_w2;
	android_test_layer1->layer[1].compressed = compress;
	android_test_layer1->layer[1].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[1].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[1].clear_x = osdcmp_clearx;
	android_test_layer1->layer[1].clear_y = osdcmp_cleary;
	android_test_layer1->layer[1].syncstamp = 0;
	android_test_layer1->layer[1].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[1].show = 1;


	android_test_layer1->layer[2].src_type = SRC_NORMAL;
	android_test_layer1->layer[2].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[2].context = 0; /*  ?? */
	android_test_layer1->layer[2].key_en = 0;
	android_test_layer1->layer[2].colorkey = -1;
	android_test_layer1->layer[2].alpha = 0x80;
	android_test_layer1->layer[2].x = 0;
	android_test_layer1->layer[2].y = 0;
	android_test_layer1->layer[2].height = src_h3;
	android_test_layer1->layer[2].width = src_w3;
	android_test_layer1->layer[2].address = virt_to_phys(lollipop_360x240);
	android_test_layer1->layer[2].pitch = android_test_layer1->layer[2].width*4;
	android_test_layer1->layer[2].dst_x = 0;
	android_test_layer1->layer[2].dst_y = 0;
	android_test_layer1->layer[2].dst_height = dst_h3;
	android_test_layer1->layer[2].dst_width = dst_w3;
	android_test_layer1->layer[2].compressed = compress;
	android_test_layer1->layer[2].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[2].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[2].clear_x = osdcmp_clearx;
	android_test_layer1->layer[2].clear_y = osdcmp_cleary;
	android_test_layer1->layer[2].syncstamp = 0;
	android_test_layer1->layer[2].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[2].show = 1;


	android_test_layer1->layer[3].src_type = SRC_NORMAL;
	android_test_layer1->layer[3].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[3].context = 0; /*  ?? */
	android_test_layer1->layer[3].key_en = 0;
	android_test_layer1->layer[3].colorkey = -1;
	android_test_layer1->layer[3].alpha = 0x80;
	android_test_layer1->layer[3].x = 0;
	android_test_layer1->layer[3].y = 0;
	android_test_layer1->layer[3].height = src_h4;
	android_test_layer1->layer[3].width = src_w4;
	android_test_layer1->layer[3].address = virt_to_phys(gdma_rtk_logo_260x200);
	android_test_layer1->layer[3].pitch = android_test_layer1->layer[3].width*4;
	android_test_layer1->layer[3].dst_x = 200;
	android_test_layer1->layer[3].dst_y = 200;
	android_test_layer1->layer[3].dst_height = dst_h4;
	android_test_layer1->layer[3].dst_width = dst_w4;
	android_test_layer1->layer[3].compressed = compress;
	android_test_layer1->layer[3].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[3].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[3].clear_x = osdcmp_clearx;
	android_test_layer1->layer[3].clear_y = osdcmp_cleary;
	android_test_layer1->layer[3].syncstamp = 0;
	android_test_layer1->layer[3].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[3].show = 1;

	android_test_layer1->layer[4].src_type = SRC_NORMAL;
	android_test_layer1->layer[4].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
	android_test_layer1->layer[4].context = 0; /*  ?? */
	android_test_layer1->layer[4].key_en = 0;
	android_test_layer1->layer[4].colorkey = -1;
	android_test_layer1->layer[4].alpha = 0x80;
	android_test_layer1->layer[4].x = 0;
	android_test_layer1->layer[4].y = 0;
	android_test_layer1->layer[4].height = src_h5;
	android_test_layer1->layer[4].width = src_w5;
	android_test_layer1->layer[4].address = virt_to_phys(mycursor_120x160);
	android_test_layer1->layer[4].pitch = android_test_layer1->layer[4].width*4;
	android_test_layer1->layer[4].dst_x = 0;
	android_test_layer1->layer[4].dst_y = 0;
	android_test_layer1->layer[4].dst_height = dst_h5;
	android_test_layer1->layer[4].dst_width = dst_w5;
	android_test_layer1->layer[4].compressed = compress;
	android_test_layer1->layer[4].plane_ar = osdcmp_plane_ar;
	android_test_layer1->layer[4].plane_gb = osdcmp_plane_gb;
	android_test_layer1->layer[4].clear_x = osdcmp_clearx;
	android_test_layer1->layer[4].clear_y = osdcmp_cleary;
	android_test_layer1->layer[4].syncstamp = 0;
	android_test_layer1->layer[4].scale_factor = disp_res.width/pic_fbWbase;
	android_test_layer1->layer[4].show = 1;

	GDMA_ReceiveGraphicLayers(android_test_layer1);

	/* online write-back & coming compress picture to show test */
	if (arg == 1) {

		src_w1 = 1280;
		src_h1 = 720;
		dst_w1 = 1920;
		dst_h1 = 1080;
		src_w2 = 360;
		src_h2 = 240;
		dst_w2 = 360;
		dst_h2 = 240;
		src_w3 = 260;
		src_h3 = 200;
		dst_w3 = 260;
		dst_h3 = 200;
		src_w4 = 120;
		src_h4 = 160;
		dst_w4 = 120;
		dst_h4 = 160;

		compress = 1;

		memset(android_test_layer1, 0, sizeof(GRAPHIC_LAYERS_OBJECT));


		android_test_layer1->layer_num = 4;
		android_test_layer1->cookie = 0;

		android_test_layer1->layer[0].src_type = SRC_NORMAL;
		android_test_layer1->layer[0].format = VO_OSD_COLOR_FORMAT_RGBA8888;
		android_test_layer1->layer[0].context = 0; /*  ?? */
		android_test_layer1->layer[0].key_en = 0;
		android_test_layer1->layer[0].colorkey = -1;
		android_test_layer1->layer[0].alpha = 0xff;
		android_test_layer1->layer[0].x = 0;
		android_test_layer1->layer[0].y = 0;
		android_test_layer1->layer[0].height = src_h1;
		android_test_layer1->layer[0].width = src_w1;
		android_test_layer1->layer[0].address = virt_to_phys(fillcolor);
		android_test_layer1->layer[0].pitch = android_test_layer1->layer[0].width*4;
		android_test_layer1->layer[0].dst_x = 0;
		android_test_layer1->layer[0].dst_y = 0;
		android_test_layer1->layer[0].dst_height = dst_h1;
		android_test_layer1->layer[0].dst_width = dst_w1;
		android_test_layer1->layer[0].compressed = compress;    /*compress test*/
		android_test_layer1->layer[0].plane_ar = osdcmp_plane_ar;
		android_test_layer1->layer[0].plane_gb = osdcmp_plane_gb;
		android_test_layer1->layer[0].clear_x = osdcmp_clearx;
		android_test_layer1->layer[0].clear_y = osdcmp_cleary;
		android_test_layer1->layer[0].syncstamp = 0;
		android_test_layer1->layer[0].scale_factor = disp_res.width/pic_fbWbase;
		android_test_layer1->layer[0].show = 1;


		android_test_layer1->layer[1].src_type = SRC_NORMAL;
		android_test_layer1->layer[1].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		android_test_layer1->layer[1].context = 0; /*  ?? */
		android_test_layer1->layer[1].key_en = 0;
		android_test_layer1->layer[1].colorkey = -1;
		android_test_layer1->layer[1].alpha = 0xff;
		android_test_layer1->layer[1].x = 0;
		android_test_layer1->layer[1].y = 0;
		android_test_layer1->layer[1].height = src_h2;
		android_test_layer1->layer[1].width = src_w2;
		android_test_layer1->layer[1].address = virt_to_phys(lollipop_360x240);
		android_test_layer1->layer[1].pitch = android_test_layer1->layer[1].width*4;
		android_test_layer1->layer[1].dst_x = 0;
		android_test_layer1->layer[1].dst_y = 0;
		android_test_layer1->layer[1].dst_height = dst_h2;
		android_test_layer1->layer[1].dst_width = dst_w2;
		android_test_layer1->layer[1].compressed = compress;
		android_test_layer1->layer[1].plane_ar = osdcmp_plane_ar;
		android_test_layer1->layer[1].plane_gb = osdcmp_plane_gb;
		android_test_layer1->layer[1].clear_x = osdcmp_clearx;
		android_test_layer1->layer[1].clear_y = osdcmp_cleary;
		android_test_layer1->layer[1].syncstamp = 0;
		android_test_layer1->layer[1].scale_factor = disp_res.width/pic_fbWbase;
		android_test_layer1->layer[1].show = 1;


		android_test_layer1->layer[2].src_type = SRC_NORMAL;
		android_test_layer1->layer[2].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		android_test_layer1->layer[2].context = 0; /*  ?? */
		android_test_layer1->layer[2].key_en = 0;
		android_test_layer1->layer[2].colorkey = -1;
		android_test_layer1->layer[2].alpha = 0xff;
		android_test_layer1->layer[2].x = 0;
		android_test_layer1->layer[2].y = 0;
		android_test_layer1->layer[2].height = src_h3;
		android_test_layer1->layer[2].width = src_w3;
		android_test_layer1->layer[2].address = virt_to_phys(gdma_rtk_logo_260x200);
		android_test_layer1->layer[2].pitch = android_test_layer1->layer[2].width*4;
		android_test_layer1->layer[2].dst_x = 0;
		android_test_layer1->layer[2].dst_y = 0;
		android_test_layer1->layer[2].dst_height = dst_h3;
		android_test_layer1->layer[2].dst_width = dst_w3;
		android_test_layer1->layer[2].compressed = compress;
		android_test_layer1->layer[2].plane_ar = osdcmp_plane_ar;
		android_test_layer1->layer[2].plane_gb = osdcmp_plane_gb;
		android_test_layer1->layer[2].clear_x = osdcmp_clearx;
		android_test_layer1->layer[2].clear_y = osdcmp_cleary;
		android_test_layer1->layer[2].syncstamp = 0;
		android_test_layer1->layer[2].scale_factor = disp_res.width/pic_fbWbase;
		android_test_layer1->layer[2].show = 1;


		android_test_layer1->layer[3].src_type = SRC_NORMAL;
		android_test_layer1->layer[3].format = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE;
		android_test_layer1->layer[3].context = 0; /*  ?? */
		android_test_layer1->layer[3].key_en = 0;
		android_test_layer1->layer[3].colorkey = -1;
		android_test_layer1->layer[3].alpha = 0xff;
		android_test_layer1->layer[3].x = 0;
		android_test_layer1->layer[3].y = 0;
		android_test_layer1->layer[3].height = src_h4;
		android_test_layer1->layer[3].width = src_w4;
		android_test_layer1->layer[3].address = virt_to_phys(mycursor_120x160);
		android_test_layer1->layer[3].pitch = android_test_layer1->layer[3].width*4;
		android_test_layer1->layer[3].dst_x = 200;
		android_test_layer1->layer[3].dst_y = 200;
		android_test_layer1->layer[3].dst_height = dst_h4;
		android_test_layer1->layer[3].dst_width = dst_w4;
		android_test_layer1->layer[3].compressed = compress;
		android_test_layer1->layer[3].plane_ar = osdcmp_plane_ar;
		android_test_layer1->layer[3].plane_gb = osdcmp_plane_gb;
		android_test_layer1->layer[3].clear_x = osdcmp_clearx;
		android_test_layer1->layer[3].clear_y = osdcmp_cleary;
		android_test_layer1->layer[3].syncstamp = 0;
		android_test_layer1->layer[3].scale_factor = disp_res.width/pic_fbWbase;
		android_test_layer1->layer[3].show = 1;

		GDMA_ReceiveGraphicLayers(android_test_layer1);
	}
}

#endif

#if 0
/** @brief check normal layers status to arragement osd3/4/5 to mid-blend
*			the related setting including mid-blend registers, OSDSRx_switch_to, mixer_order, etc.
*   @param updatedNum	indicated how many layers will be updated at the same time
*   @param updatedOSDx	indicated which layers will be updated at the same time
*   @return None
*/
void GDMA_MidBlendSet(unsigned int updatedNum, unsigned int updatedOSDx)
{
	/* Do we need this in Mac5*/
	gdma_dev *gdma = &gdma_devices[0];
	osd3_ctrl_RBUS osd3_ctrl_reg;
	osd4_ctrl_RBUS osd4_ctrl_reg;
	osd5_ctrl_RBUS osd5_ctrl_reg;
	GDMA_WIN *win = NULL, *win3 = NULL, *win4 = NULL, *win5 = NULL;
	resource_lb_RBUS resource_lb_reg;
	line_buffer_end_RBUS line_buffer_end_reg;
	osdovl_mixer_layer_sel_RBUS mixer_layer_sel_reg;
	unsigned int cx_sel_old = 0, cx_sel_new = 0, loop;
	E_BLEND_ORDER midblend_onlineOrder = C2;
	GDMA_PIC_DATA *curPic;
	mid_blend_RBUS mid_blend_reg;
	mid_blend_c0_RBUS mid_blend_cx_reg;
	unsigned int planeAlpha_en;
	int canvasW = 0, canvasH = 0, dstX = 0x1fff, dstY = 0x1fff, dstW = 0 , dstH = 0;
	VO_RECTANGLE srcWin, dispWin;
	struct gdma_receive_work tmpwork;

	DBG_PRINT(KERN_EMERG"%s, updatedNum=%d, updatedOSDx=0x%x \n", __FUNCTION__, updatedNum, updatedOSDx);

	//if (updatedNum <= 3)
	//	return ;

	memset(&srcWin, 0, sizeof(VO_RECTANGLE));
	memset(&dispWin, 0, sizeof(VO_RECTANGLE));

	osd3_ctrl_reg.regValue = rtd_inl(GDMA_OSD3_CTRL_reg);
	osd4_ctrl_reg.regValue = rtd_inl(GDMA_OSD4_CTRL_reg);
	osd5_ctrl_reg.regValue = rtd_inl(GDMA_OSD5_CTRL_reg);
	line_buffer_end_reg.regValue = rtd_inl(GDMA_LINE_BUFFER_END_reg);
	win3 = phys_to_virt(rtd_inl(GDMA_OSD3_WI_reg));
	win4 = phys_to_virt(rtd_inl(GDMA_OSD4_WI_reg));
	win5 = phys_to_virt(rtd_inl(GDMA_OSD5_WI_reg));

	/* check osd3 & osd4 status */
	if (osd3_ctrl_reg.osd3_en && osd4_ctrl_reg.osd4_en &&
		win3->attr.IMGcompress == 0 && win4->attr.IMGcompress == 0 &&
		line_buffer_end_reg.bundle_osd3_osd4 == 0) {

		DBG_PRINT(KERN_EMERG"%s, start mid-blend setting... \n", __FUNCTION__);

		/* go to mid-blend */
		resource_lb_reg.regValue = rtd_inl(GDMA_RESOURCE_LB_reg);
		resource_lb_reg.set_osd1_go_middle_blend = 1;
		resource_lb_reg.set_osd2_go_middle_blend = 1;
		resource_lb_reg.set_osd3_go_middle_blend = 1;
		rtd_outl(GDMA_RESOURCE_LB_reg, resource_lb_reg.regValue);

		/* switch OSDSR3_switch_to OSD6 */
		line_buffer_end_reg.osdsr3_switch_to = GDMA_PLANE_OSD6;
		rtd_outl(GDMA_LINE_BUFFER_END_reg, line_buffer_end_reg.regValue);

		/* mixer order set */
		/*  TODO: Mixer : online blend order
		*	because k blend-factor setting, mixer layer order will reverse
		*/
		mixer_layer_sel_reg.regValue = rtd_inl(OSDOVL_Mixer_layer_sel_reg);
		if (midblend_onlineOrder == C0) {
			cx_sel_old = mixer_layer_sel_reg.c0_sel;
			cx_sel_new = mixer_layer_sel_reg.c0_sel = GDMA_PLANE_OSD6;
		} else if (midblend_onlineOrder == C1) {
			cx_sel_old = mixer_layer_sel_reg.c1_sel;
			cx_sel_new = mixer_layer_sel_reg.c1_sel = GDMA_PLANE_OSD6;
		} else if (midblend_onlineOrder == C2) {
			cx_sel_old = mixer_layer_sel_reg.c2_sel;
			cx_sel_new = mixer_layer_sel_reg.c2_sel = GDMA_PLANE_OSD6;
		} else if (midblend_onlineOrder == C3) {
			cx_sel_old = mixer_layer_sel_reg.c3_sel;
			cx_sel_new = mixer_layer_sel_reg.c3_sel = GDMA_PLANE_OSD6;
		} else if (midblend_onlineOrder == C4) {
			cx_sel_old = mixer_layer_sel_reg.c4_sel;
			cx_sel_new = mixer_layer_sel_reg.c4_sel = GDMA_PLANE_OSD6;
		}

		/* conflict protect */
		if (mixer_layer_sel_reg.c0_sel == cx_sel_new && midblend_onlineOrder != C0)
			mixer_layer_sel_reg.c0_sel = cx_sel_old;
		else if (mixer_layer_sel_reg.c1_sel == cx_sel_new && midblend_onlineOrder != C1)
			mixer_layer_sel_reg.c1_sel = cx_sel_old;
		else if (mixer_layer_sel_reg.c2_sel == cx_sel_new && midblend_onlineOrder != C2)
			mixer_layer_sel_reg.c2_sel = cx_sel_old;
		else if (mixer_layer_sel_reg.c3_sel == cx_sel_new && midblend_onlineOrder != C3)
			mixer_layer_sel_reg.c3_sel = cx_sel_old;
		else if (mixer_layer_sel_reg.c4_sel == cx_sel_new && midblend_onlineOrder != C4)
			mixer_layer_sel_reg.c4_sel = cx_sel_old;
		rtd_outl(OSDOVL_Mixer_layer_sel_reg, mixer_layer_sel_reg.regValue);
		DBG_PRINT(KERN_EMERG"%s OSDOVL_Mixer_layer_sel_reg=0x%x \n", __FUNCTION__, mixer_layer_sel_reg.regValue);

		/* 	mid-blend settings
		*	including x, y coordinate, blend size, plane alpha, etc.
		*/
		mid_blend_reg.regValue = rtd_inl(GDMA_MID_BLEND_reg);
		mid_blend_reg.mid_blend_en = 1;
		for (loop = GDMA_PLANE_OSD3; loop <= GDMA_PLANE_OSD5; loop++) {

			if (loop == GDMA_PLANE_OSD3 && osd3_ctrl_reg.osd3_en == 0)
				continue;
			else if (loop == GDMA_PLANE_OSD4 && osd4_ctrl_reg.osd4_en == 0)
				continue;
			else if (loop == GDMA_PLANE_OSD5 && osd5_ctrl_reg.osd5_en == 0)
				continue;

			DBG_PRINT(KERN_EMERG"%s OSD%d enable & go to mid-blend \n", __FUNCTION__, loop);

			curPic = gdma->pic[loop] + gdma->curPic[loop];
			planeAlpha_en = 0;
			mid_blend_cx_reg.regValue = 0xffffffff;

			/* plane alpha check */
			if ((curPic->plane_ar.plane_alpha_r != 0xff) || (curPic->plane_ar.plane_alpha_a != 0xff)) {
				planeAlpha_en = 1;
				mid_blend_cx_reg.plane_alpha_r = curPic->plane_ar.plane_alpha_r & 0xFF;
				mid_blend_cx_reg.plane_alpha_a = curPic->plane_ar.plane_alpha_a & 0xFF;
			}
			if ((curPic->plane_gb.plane_alpha_g != 0xff) || (curPic->plane_gb.plane_alpha_b != 0xff)) {
				planeAlpha_en = 1;
				mid_blend_cx_reg.plane_alpha_g = curPic->plane_gb.plane_alpha_g & 0xFF;
				mid_blend_cx_reg.plane_alpha_b = curPic->plane_gb.plane_alpha_b & 0xFF;
			}

			if (loop == GDMA_PLANE_OSD3) {
				if (planeAlpha_en)
					mid_blend_reg.c3_plane_alpha_en = 1;
				rtd_outl(GDMA_MID_BLEND_C3_reg, mid_blend_cx_reg.regValue);

				win = win3;
				rtd_outl(GDMA_MID_BLEND_OSD3_reg, GDMA_MID_BLEND_OSD3_x(win3->dst_x/curPic->scale_factor) |
															GDMA_MID_BLEND_OSD3_y(win3->dst_y/curPic->scale_factor));
			} else if (loop == GDMA_PLANE_OSD4) {
				if (planeAlpha_en)
					mid_blend_reg.c2_plane_alpha_en = 1;
				rtd_outl(GDMA_MID_BLEND_C2_reg, mid_blend_cx_reg.regValue);

				win = win4;
				rtd_outl(GDMA_MID_BLEND_OSD4_reg, GDMA_MID_BLEND_OSD4_x(win4->dst_x/curPic->scale_factor) |
															GDMA_MID_BLEND_OSD4_y(win4->dst_y/curPic->scale_factor));
			} else if (loop == GDMA_PLANE_OSD5) {
				if (planeAlpha_en)
					mid_blend_reg.c1_plane_alpha_en = 1;
				rtd_outl(GDMA_MID_BLEND_C1_reg, mid_blend_cx_reg.regValue);

				win = win5;
				rtd_outl(GDMA_MID_BLEND_OSD5_reg, GDMA_MID_BLEND_OSD5_x(win5->dst_x/curPic->scale_factor) |
															GDMA_MID_BLEND_OSD5_y(win5->dst_y/curPic->scale_factor));
			}

			/*  calculate the canvas size by source size */
			if (canvasW < ((win->dst_x/curPic->scale_factor) + win->winWH.width))
				canvasW = ((win->dst_x/curPic->scale_factor) + win->winWH.width);
			if (canvasH < ((win->dst_y/curPic->scale_factor) + win->winWH.height))
				canvasH = ((win->dst_y/curPic->scale_factor) + win->winWH.height);

			/* calcualte the destination width & height & x & y */
			if (dstW < (win->dst_width + win->dst_x))
				dstW = win->dst_width + win->dst_x;
			if (dstH < win->dst_height + win->dst_y)
				dstH = win->dst_height+ win->dst_y;
			if (win->dst_x < dstX)
				dstX = win->dst_x;
			if (win->dst_y < dstY)
				dstY = win->dst_y;
		}

		DBG_PRINT(KERN_EMERG"%s mid-blend canvas w=%d, h=%d \n", __FUNCTION__, canvasW, canvasH);
		DBG_PRINT(KERN_EMERG"%s mid-blend to OSD_SR: dstX=%d, dstY=%d, dstW=%d, dstH=%d \n", __FUNCTION__, dstX, dstY, dstW, dstH);

		/* write canvasW & canvasH */
		rtd_outl(GDMA_MID_BLEND_SIZE_reg, GDMA_MID_BLEND_SIZE_w(canvasW) | GDMA_MID_BLEND_SIZE_h(canvasH));
		/* write final mid_blend register setting */
		rtd_outl(GDMA_MID_BLEND_reg, mid_blend_reg.regValue);
		/* OSD_SR settings */
		if (canvasW != dstW || canvasH != dstH) {
			srcWin.x = srcWin.y = 0;
			dispWin.x = 0;//dstX;
			dispWin.y = 0;//dstY;
			srcWin.width = canvasW;
			srcWin.height = canvasH;
			dispWin.width = dstW;
			dispWin.height = dstH;
			tmpwork.disPlane = GDMA_PLANE_OSD6;
			tmpwork.picQwr = 0;

			drv_PreScale(1, srcWin, dispWin, GDMA_PLANE_OSD6, &tmpwork);
			drv_scaleup(1, GDMA_PLANE_OSD6);
		}

	} else {

		mid_blend_reg.regValue = rtd_inl(GDMA_MID_BLEND_reg);
		if (mid_blend_reg.mid_blend_en) {
			/* do NOT go to mid-blend */
			resource_lb_reg.regValue = rtd_inl(GDMA_RESOURCE_LB_reg);
			resource_lb_reg.set_osd1_go_middle_blend = 0;
			resource_lb_reg.set_osd2_go_middle_blend = 0;
			resource_lb_reg.set_osd3_go_middle_blend = 0;
			rtd_outl(GDMA_RESOURCE_LB_reg, resource_lb_reg.regValue);

			/* disable mid-blend */
			mid_blend_reg.mid_blend_en = 0;
			rtd_outl(GDMA_MID_BLEND_reg, mid_blend_reg.regValue);

			/* restore to OSD4 for osdsr3_switch_to */
			line_buffer_end_reg.regValue = rtd_inl(GDMA_LINE_BUFFER_END_reg);
			line_buffer_end_reg.osdsr3_switch_to = GDMA_PLANE_OSD4;
			rtd_outl(GDMA_LINE_BUFFER_END_reg, line_buffer_end_reg.regValue);

			/* OSD_SR re-setting if OSD4 enable */
			if (updatedOSDx & GDMA_CTRL_osd4_prog_done(1))
				drv_scaleup(1, GDMA_PLANE_OSD4);

			DBG_PRINT(KERN_EMERG"%s mid-blend DISABLE \n", __FUNCTION__);
		}
	}
}


/** @brief Calculate the line buufer setting
*			take care that offline lb does NOT affect to current online lb
*   @param progDone indicate which OSD path will be used in this time
*   @return None
*/
void GDMA_LineBufferCal(void)
{
	volatile int disPlane, cnt4k2kpath = 0, lbSize = 0;
	int lbSetCnt, startIdx = 0, loop = 0, midloop = 0;
	unsigned int offset = 0;
	GDMA_WIN *win = NULL;
	line_buffer_sta_RBUS line_buffer_sta_reg;
	line_buffer_size_RBUS line_buffer_size_reg;
	line_buffer_end_RBUS line_buffer_end_reg;
	resource_lb_RBUS resource_lb_reg;

	*(unsigned int *)&line_buffer_end_reg = rtd_inl(GDMA_LINE_BUFFER_END_reg);
	line_buffer_end_reg.regValue = rtd_inl(GDMA_LINE_BUFFER_END_reg);
	line_buffer_size_reg.regValue = 0;
	line_buffer_sta_reg.regValue = 0;


	/* decides L4/5/6 */
	for (loop = 0; loop < 3; loop++) {
		lbSize = 0;

		if (loop == 0)
			disPlane = line_buffer_end_reg.osdsr1_switch_to;
		else if (loop == 1)
			disPlane = line_buffer_end_reg.osdsr2_switch_to;
		else if (loop == 2)
			disPlane = line_buffer_end_reg.osdsr3_switch_to;

		DBG_PRINT(KERN_EMERG"%s L%d disPlane=%d \n", __FUNCTION__, loop+4, disPlane);

		if (disPlane == GDMA_PLANE_OSD2)
			offset = 0x100;
		else if (disPlane == GDMA_PLANE_OSD3)
			offset = 0x200;
		else if (disPlane == GDMA_PLANE_OSD4)
			offset = 0x300;
		else if (disPlane == GDMA_PLANE_OSD5)
			offset = 0x400;

		/* OSD HW enable & OSD_SR enable */
		if (disPlane != GDMA_PLANE_OSD6) {
			if (GDMA_OSD1_CTRL_get_osd1_en(rtd_inl(GDMA_OSD1_CTRL_reg+offset)) &&
				osd_sr_check_onoff_status(disPlane)) {

				lbSize = 2;
			}

			/* bundle case */
			win = phys_to_virt(rtd_inl(GDMA_OSD1_WI_reg+offset));
			if (line_buffer_end_reg.bundle_osdsr1_osdsr2 && loop == 0) {
				if (win->winWH.width > TWOK_W && win->winWH.height > ONEK_H)
					lbSize = 4;
				else
					lbSize = 3;
			}

		} else if (disPlane == GDMA_PLANE_OSD6 && GDMA_MID_BLEND_get_mid_blend_en(rtd_inl(GDMA_MID_BLEND_reg))) {
			*(unsigned int *)&resource_lb_reg = rtd_inl(GDMA_RESOURCE_LB_reg);
			resource_lb_reg.regValue = rtd_inl(GDMA_RESOURCE_LB_reg);

			DBG_PRINT(KERN_EMERG"%s mid-blend's OSD_SR setting... \n", __FUNCTION__);

			for (midloop = 0; midloop < 5; midloop++) {
				if (midloop == 0 && resource_lb_reg.set_osd1_go_middle_blend)
					offset = 0x0;
				else if (midloop == 1 && resource_lb_reg.set_osd2_go_middle_blend)
					offset = 0x100;
				else if (midloop == 2 && resource_lb_reg.set_osd3_go_middle_blend)
					offset = 0x200;
				else
					continue;

				if (GDMA_OSD1_CTRL_get_osd1_en(rtd_inl(GDMA_OSD1_CTRL_reg+offset)) &&
					osd_sr_check_onoff_status(disPlane)) {

					lbSize = 2;
				}
			}

			DBG_PRINT(KERN_EMERG"%s L%d disPlane=%d, lbSize=%d \n", __FUNCTION__, loop+4, disPlane, lbSize);
		}

		if (loop == 0)
			line_buffer_size_reg.l4 = lbSize;
		else if (loop == 1)
			line_buffer_size_reg.l5 = lbSize;
		else if (loop == 2)
			line_buffer_size_reg.l6 = lbSize;

		DBG_PRINT(KERN_EMERG"%s L%d lbSize=%d \n", __FUNCTION__, loop+4, lbSize);
	}

	/* decides L1/2/3 */
	for (loop = 0; loop < 3; loop++) {
		lbSize = 0;

		if (loop == 0) {
			disPlane = GDMA_PLANE_OSD1;
			offset = 0x0;
		} else if (loop == 1) {
			disPlane = GDMA_PLANE_OSD2;
			offset = 0x100;
		} else if (loop == 2) {
			disPlane = GDMA_PLANE_OSD3;
			offset = 0x200;
		}

		DBG_PRINT(KERN_EMERG"%s L%d disPlane=%d \n", __FUNCTION__, loop, disPlane);

		if (GDMA_OSD1_CTRL_get_osd1_en(rtd_inl(GDMA_OSD1_CTRL_reg+offset))) {
			win = phys_to_virt(rtd_inl(GDMA_OSD1_WI_reg+offset));

			if (win->winWH.width > TWOK_W && win->winWH.height > ONEK_H) {

				if (cnt4k2kpath == 0)
					lbSize = 4;
				else if (cnt4k2kpath == 1)
					lbSize = 6;
				else
					pr_debug(KERN_EMERG"Warnning, Don't use three 4K2K path, line buffer is NOT enough\n");

				/* non-fbdc layer does NOT need line buffer in L1, L2, L3 */
				if (win->attr.IMGcompress == 0)
					lbSize = 0;

				cnt4k2kpath++;
			} else if (win->winWH.width <= TWOK_W && win->winWH.height <= ONEK_H) {

				lbSize = 3;
				/* non-fbdc layer does NOT need line buffer in L1, L2, L3 */
				if (win->attr.IMGcompress == 0)
					lbSize = 0;
			}
		}

		if (loop == 0)
			line_buffer_size_reg.l1 = lbSize;
		else if (loop == 1)
			line_buffer_size_reg.l2 = lbSize;
		else if (loop == 2)
			line_buffer_size_reg.l3 = lbSize;

		DBG_PRINT(KERN_EMERG"%s L%d lbSize=%d \n", __FUNCTION__, loop, lbSize);
	}

	/* decides L7/8 */
	if (line_buffer_end_reg.bundle_osdsr1_osdsr2)
		line_buffer_size_reg.l7 = 2;
	if (line_buffer_end_reg.bundle_osdsrbypass4_osdsrbypass5)
		line_buffer_size_reg.l8 = 2;
	DBG_PRINT(KERN_EMERG"%s L7 lbSize=%d, L8 lbSize=%d \n", __FUNCTION__, line_buffer_size_reg.l7, line_buffer_size_reg.l8);

	lbSetCnt = line_buffer_size_reg.l1 +
					line_buffer_size_reg.l2 +
					line_buffer_size_reg.l3 +
					line_buffer_size_reg.l4 +
					line_buffer_size_reg.l5 +
					line_buffer_size_reg.l6 +
					line_buffer_size_reg.l7 +
					line_buffer_size_reg.l8;

	if (lbSetCnt > GDMA_TOTAL_LB_SIZE)
		pr_debug(KERN_EMERG"Warnning, Line Buffer is NOT enough, lbSetCnt=%d\n", lbSetCnt);

	/* line buffer setting */
	line_buffer_sta_reg.l6 = startIdx;		/* L6 assign first for online switch to offline that does affect to online lb location */
	startIdx = startIdx + line_buffer_size_reg.l6;
	line_buffer_sta_reg.l1 = startIdx;
	startIdx = startIdx + line_buffer_size_reg.l1;
	line_buffer_sta_reg.l2 = startIdx;
	startIdx = startIdx + line_buffer_size_reg.l2;
	line_buffer_sta_reg.l3 = startIdx;
	startIdx = startIdx + line_buffer_size_reg.l3;
	line_buffer_sta_reg.l4 = startIdx;
	startIdx = startIdx + line_buffer_size_reg.l4;
	line_buffer_sta_reg.l5 = startIdx;
	startIdx = startIdx + line_buffer_size_reg.l5;
	line_buffer_sta_reg.l7 = startIdx;
	startIdx = startIdx + line_buffer_size_reg.l7;
	line_buffer_sta_reg.l8 = startIdx;

	if (line_buffer_size_reg.l1 == 0)
		line_buffer_sta_reg.l1 = 0;
	if (line_buffer_size_reg.l2 == 0)
		line_buffer_sta_reg.l2 = 0;
	if (line_buffer_size_reg.l3 == 0)
		line_buffer_sta_reg.l3 = 0;
	if (line_buffer_size_reg.l4 == 0)
		line_buffer_sta_reg.l4 = 0;
	if (line_buffer_size_reg.l5 == 0)
		line_buffer_sta_reg.l5 = 0;
	if (line_buffer_size_reg.l6 == 0)
		line_buffer_sta_reg.l6 = 0;
	if (line_buffer_size_reg.l7 == 0)
		line_buffer_sta_reg.l7 = 0;
	if (line_buffer_size_reg.l8 == 0)
		line_buffer_sta_reg.l8 = 0;

	DBG_PRINT(KERN_EMERG"%s, GDMA_LINE_BUFFER_STA_reg=0x%x \n", __FUNCTION__, line_buffer_sta_reg.regValue);
	DBG_PRINT(KERN_EMERG"%s, GDMA_LINE_BUFFER_SIZE_reg=0x%x \n", __FUNCTION__, line_buffer_size_reg.regValue);

	rtd_outl(GDMA_LINE_BUFFER_STA_reg, line_buffer_sta_reg.regValue);
	rtd_outl(GDMA_LINE_BUFFER_SIZE_reg, line_buffer_size_reg.regValue);
}
#endif


#if 0
/** @brief keep current screen by online write-back & disable other OSD1/2/3/5.
*			when online switchs to offline state...
*   @param None
*   @return None
*/
void GDMA_OnlineWritebackDisplay(void)
{
	gdma_dev *gdma = &gdma_devices[0];
	online_RBUS online_reg;
	dma_addr_t addr, addr_3d;
	decmp1_resolution_RBUS decmp1_resolution_reg;
	resource_lb_RBUS resource_lb_reg;
	line_buffer_end_RBUS line_buffer_end_reg;
	mid_blend_RBUS mid_blend_reg;
	unsigned int onlineProgDone;
	unsigned int cx_sel_old = 0, cx_sel_new = 0;
	osdovl_osd_db_ctrl_RBUS osd_db_ctrl_reg;
	osdovl_mixer_layer_sel_RBUS mixer_layer_sel_reg;
	ONLINE_WRRITEBACK_STRUCT wb;
	static PICTURE_LAYERS_OBJECT *picLayerObj = NULL;
	static GDMA_WIN *onlineWin = NULL, *onlineWin3D = NULL;
	GDMA_PIC_MATCH_SYNCSTAMP syncinfo[GDMA_LAYER_NUM];
	VO_RECTANGLE disp_res;
	unsigned long timeout = jiffies + (HZ/25);		/* 40 ms */
	unsigned int prog_done_mask = GDMA_CTRL_osd_others_prog_done_mask | GDMA_CTRL_osd5_prog_done_mask |
										GDMA_CTRL_osd4_prog_done_mask | GDMA_CTRL_osd3_prog_done_mask |
										GDMA_CTRL_osd2_prog_done_mask | GDMA_CTRL_osd1_prog_done_mask;
	VO_RECTANGLE srcWin, dispWin;

	memset(&srcWin, 0, sizeof(VO_RECTANGLE));
	memset(&dispWin, 0, sizeof(VO_RECTANGLE));

	DBG_PRINT(KERN_EMERG"++++%s \n", __FUNCTION__);

	getDispSize(&disp_res);

	if (picLayerObj == NULL)
		picLayerObj = (PICTURE_LAYERS_OBJECT *)kmalloc(sizeof(PICTURE_LAYERS_OBJECT), GFP_KERNEL);
	if (onlineWin == NULL)
		onlineWin = (GDMA_WIN *)kmalloc(sizeof(GDMA_WIN), GFP_KERNEL);
	if (onlineWin3D == NULL)
		onlineWin3D = (GDMA_WIN *)kmalloc(sizeof(GDMA_WIN), GFP_KERNEL);

	if (picLayerObj == NULL || onlineWin == NULL || onlineWin3D == NULL) {
		pr_debug(KERN_EMERG"%s, kmalloc failed ... \n", __FUNCTION__);
		return ;
	}

	/* allocate the online write-back buffer */
	if (gOnlineWbaddr == 0) {
		gOnlineWbaddr = (unsigned int)dvr_malloc_specific(((FOURK_W*TWOK_H)*4*DEFAULT_COMPRESS_RATIO/100), GFP_DCU2);
		gOnlineWbaddr = dvr_to_phys((void *)gOnlineWbaddr);

		if (gOnlineWbaddr == 0) {
			pr_debug(KERN_EMERG"%s, Allocated gOnlineWbaddr failed \n", __FUNCTION__);
			return ;
		} else
			pr_debug(KERN_EMERG"%s, gOnlineWbaddr=0x%x\n", __FUNCTION__, gOnlineWbaddr);
	}


	memset(picLayerObj, 0x0, sizeof(PICTURE_LAYERS_OBJECT));
	memset(&syncinfo, 0x0, sizeof(syncinfo));
	memset(onlineWin, 0x0, sizeof(GDMA_WIN));
	memset(onlineWin3D, 0x0, sizeof(GDMA_WIN));

	DBG_PRINT(KERN_EMERG"%s, 00 OSD_SR_3_UDFLOW_reg=0x%x \n", __FUNCTION__, rtd_inl(OSD_SR_3_UDFLOW_reg));

	/* online write-back & disable OSD1/2/3/5 */
	wb.wbAddr = gOnlineWbaddr;
	wb.wbType = RTKCOMPRESS;	/* ARGB8888  // RBG888 */
	osd_comp_graphic_layers_wb_online(&wb, 0);

	DBG_PRINT(KERN_EMERG"%s, OSDOVL_Mixer_layer_sel_reg=0x%x \n", __FUNCTION__, rtd_inl(OSDOVL_Mixer_layer_sel_reg));
	DBG_PRINT(KERN_EMERG"%s, 11 OSD_SR_3_UDFLOW_reg=0x%x \n", __FUNCTION__, rtd_inl(OSD_SR_3_UDFLOW_reg));

	/* wait hw clear programming done */
	timeout = jiffies + (HZ/25);
 	while (rtd_inl(GDMA_CTRL_reg) & prog_done_mask) {
		if (time_before(jiffies, timeout) == 0) {	/* over 40 ms */
			pr_debug(KERN_EMERG"%s,%d, TimeOut. prog_done NOT clear \n", __FUNCTION__, __LINE__);
			break;
		}
	}



	addr = dma_map_single(gdma->dev, (void *)onlineWin, sizeof(GDMA_WIN), DMA_TO_DEVICE);
	addr_3d = dma_map_single(gdma->dev, (void *)onlineWin3D, sizeof(GDMA_WIN), DMA_TO_DEVICE);

	rtd_outl(GDMA_OSD1_CTRL_reg, ~1);
	rtd_outl(GDMA_OSD2_CTRL_reg, ~1);
	rtd_outl(GDMA_OSD3_CTRL_reg, ~1);
	rtd_outl(GDMA_OSD5_CTRL_reg, ~1);

	/*
	* workaround for mantis 0074577:
	* [Merlin][Mag2][GDMA] when OSD offlineosd_disable bit is NOT work
	* osdx_size_h set to zero that can workaround this issue
	*/
	rtd_outl(GDMA_OSD1_SIZE_reg, 0);
	rtd_outl(GDMA_OSD2_SIZE_reg, 0);
	rtd_outl(GDMA_OSD3_SIZE_reg, 0);
	rtd_outl(GDMA_OSD5_SIZE_reg, 0);

	onlineWin->nxtAddr.addr     = 0;
	onlineWin->nxtAddr.last     = 1;
	onlineWin->winXY.x          = 0;
	onlineWin->winXY.y          = 0;
	onlineWin->winWH.width      = disp_res.width;
	onlineWin->winWH.height     = disp_res.height;
	onlineWin->attr.extendMode  = 0;
	onlineWin->attr.rgbOrder    = VO_OSD_COLOR_RGB;
	onlineWin->attr.objType     = 0;
	onlineWin->attr.type        = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE & 0x1f;
	onlineWin->attr.littleEndian = VO_OSD_COLOR_FORMAT_ARGB8888_LITTLE >> 5;
	onlineWin->attr.alphaEn     = 0;//(onlineWin->attr.alpha   = 0) >  0 ? 1 : 0;
	onlineWin->pitch            = disp_res.width * 4;
	onlineWin->attr.keepPreCLUT = 1;
	onlineWin->attr.clut_fmt    = 0;

	onlineWin->objOffset.objXoffset = 0;
	onlineWin->objOffset.objYoffset = 0;

	onlineWin->dst_x = 0;
	onlineWin->dst_y = 0;
	onlineWin->dst_width = disp_res.width;
	onlineWin->dst_height = disp_res.height;
	onlineWin->attr.compress = 1;
	onlineWin->used = 1;
	onlineWin->colorKey.keyEn   = 0;
	onlineWin->colorKey.key     = 0x00ffffff;
	onlineWin->top_addr         = wb.wbAddr + (gdma->ctrl.enableVFlip ? disp_res.height - 1 : 0) * onlineWin->pitch;

	memcpy(onlineWin3D, onlineWin, sizeof(GDMA_WIN));

	dma_sync_single_for_device(gdma->dev, addr, sizeof(GDMA_WIN), DMA_TO_DEVICE);
	dma_sync_single_for_device(gdma->dev, addr_3d, sizeof(GDMA_WIN), DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr, sizeof(GDMA_WIN), DMA_TO_DEVICE);
	dma_unmap_single(gdma->dev, addr_3d, sizeof(GDMA_WIN), DMA_TO_DEVICE);

	/* do NOT go to mid-blend in default */
	resource_lb_reg.regValue = rtd_inl(GDMA_RESOURCE_LB_reg);
	resource_lb_reg.set_osd1_go_middle_blend = 0;
	resource_lb_reg.set_osd2_go_middle_blend = 0;
	resource_lb_reg.set_osd3_go_middle_blend = 0;
	rtd_outl(GDMA_RESOURCE_LB_reg, resource_lb_reg.regValue);

	/* disable mid-blend */
	mid_blend_reg.regValue = rtd_inl(GDMA_MID_BLEND_reg);
	mid_blend_reg.mid_blend_en = 0;
	rtd_outl(GDMA_MID_BLEND_reg, mid_blend_reg.regValue);

	line_buffer_end_reg.regValue = rtd_inl(GDMA_LINE_BUFFER_END_reg);
	line_buffer_end_reg.osdsr3_switch_to = GDMA_PLANE_OSD4;
	rtd_outl(GDMA_LINE_BUFFER_END_reg, line_buffer_end_reg.regValue);

	/*decmp1_resolution_reg.regValue = 0;*/
	decmp1_resolution_reg.decmp_segment = 0;
	decmp1_resolution_reg.decmp_width = ((disp_res.width+31)>>5);
	decmp1_resolution_reg.decmp_height = disp_res.height;
	/*rtd_outl(GDMA_DECMP1_RESOLUTION_reg, decmp1_resolution_reg.regValue);*/

	rtd_outl(GDMA_OSD4_CLEAR1_reg, 0x00);
	rtd_outl(GDMA_OSD4_CLEAR2_reg, 0x00);

	/* enable OSD4 */
	rtd_outl(GDMA_OSD4_CTRL_reg, GDMA_OSD4_CTRL_write_data(1) | GDMA_OSD4_CTRL_osd4_en(1) | GDMA_OSD4_CTRL_rotate(gdma->ctrl.enableVFlip) | GDMA_OSD4_CTRL_d3_mode(gdma->ctrl.enable3D));

	rtd_outl(GDMA_OSD4_WI_reg, virt_to_phys(onlineWin));
	rtd_outl(GDMA_OSD4_WI_3D_reg, virt_to_phys(onlineWin3D));
	rtd_outl(GDMA_OSD4_SIZE_reg, GDMA_OSD4_SIZE_w(disp_res.width) | GDMA_OSD4_SIZE_h(disp_res.height));

	/* disable OSD4_SR */
	rtd_outl(OSD_SR_3_Scaleup_Ctrl0_reg, 0x0);
	rtd_outl(OSD_SR_3_Scaleup_Ctrl1_reg, 0x0);
	rtd_outl(OSD_SR_3_V_Location_Ctrl_reg, OSD_SR_3_V_Location_Ctrl_osd_height(disp_res.height));
	rtd_outl(OSD_SR_3_H_Location_Ctrl_reg, OSD_SR_3_H_Location_Ctrl_osd_width(disp_res.width));

	mixer_layer_sel_reg.regValue = rtd_inl(OSDOVL_Mixer_layer_sel_reg);
	cx_sel_old = mixer_layer_sel_reg.c4_sel;
	cx_sel_new = mixer_layer_sel_reg.c4_sel = GDMA_PLANE_OSD4;

	/* conflict protect */
	if (mixer_layer_sel_reg.c0_sel == cx_sel_new)
		mixer_layer_sel_reg.c0_sel = cx_sel_old;
	else if (mixer_layer_sel_reg.c1_sel == cx_sel_new && C0 != C1)
		mixer_layer_sel_reg.c1_sel = cx_sel_old;
	else if (mixer_layer_sel_reg.c2_sel == cx_sel_new && C0 != C2)
		mixer_layer_sel_reg.c2_sel = cx_sel_old;
	else if (mixer_layer_sel_reg.c3_sel == cx_sel_new && C0 != C3)
		mixer_layer_sel_reg.c3_sel = cx_sel_old;
	else if (mixer_layer_sel_reg.c4_sel == cx_sel_new && C0 != C4)
		mixer_layer_sel_reg.c4_sel = cx_sel_old;
	rtd_outl(OSDOVL_Mixer_layer_sel_reg, mixer_layer_sel_reg.regValue);

	onlineProgDone = GDMA_CTRL_write_data(1) | GDMA_CTRL_osd_others_prog_done(1);
	/*  only check real online OSD HW */
	online_reg.regValue = rtd_inl(GDMA_ONLINE_reg);
	if (online_reg.set_osd1_offline == 0)
		onlineProgDone |= GDMA_CTRL_osd1_prog_done(1);
	if (online_reg.set_osd2_offline == 0)
		onlineProgDone |= GDMA_CTRL_osd2_prog_done(1);
	if (online_reg.set_osd3_offline == 0)
		onlineProgDone |= GDMA_CTRL_osd3_prog_done(1);

	osd_db_ctrl_reg.regValue = rtd_inl(OSDOVL_OSD_Db_Ctrl_reg);
	osd_db_ctrl_reg.db_load = 1;

	GDMA_LineBufferCal();

	DBG_PRINT(KERN_EMERG"%s, onlineProgDone = 0x%x \n", __FUNCTION__, onlineProgDone);
	DBG_PRINT(KERN_EMERG"%s, osd_db_ctrl = 0x%x \n", __FUNCTION__, osd_db_ctrl_reg.regValue);

	rtd_outl(OSDOVL_OSD_Db_Ctrl_reg, osd_db_ctrl_reg.regValue); /*  mixer apply */
	rtd_outl(GDMA_CTRL_reg, onlineProgDone);  /*  gdma & sr programming done */

	/* wait hw clear programming done */
	timeout = jiffies + (HZ/25);
 	while (rtd_inl(GDMA_CTRL_reg) & prog_done_mask) {
		if (time_before(jiffies, timeout) == 0) {	/* over 40 ms */
			pr_debug(KERN_EMERG"%s,%d, TimeOut. prog_done NOT clear \n", __FUNCTION__, __LINE__);
			break;
		}
	}


	DBG_PRINT(KERN_EMERG"%s, 22 OSD_SR_3_UDFLOW_reg=0x%x \n", __FUNCTION__, rtd_inl(OSD_SR_3_UDFLOW_reg));
	DBG_PRINT(KERN_EMERG"----%s \n", __FUNCTION__);

}
#endif

#if 0
GDMA_ONOFF_SWITCH GDMA_SwitchOnlineOffline(int hasCompress, int osd1offline)
{
	online_RBUS online_reg;
	unsigned int isOnlineState = -1;	/* 1: online state; 0: offline state */
	GDMA_ONOFF_SWITCH ret_state = ONLINE_STATE;

	/* check offline state or online state */
	online_reg.regValue = rtd_inl(GDMA_ONLINE_reg);

	if ((osd1offline == 1 && (online_reg.set_osd1_offline == 0 || online_reg.set_osd2_offline == 0 ||
									online_reg.set_osd3_offline == 0 || online_reg.set_osd5_offline == 0)) ||
		(osd1offline == 0 && (online_reg.set_osd2_offline == 0 || online_reg.set_osd3_offline == 0 ||
									online_reg.set_osd5_offline == 0))) {
		isOnlineState = 1;
		ret_state = ONLINE_STATE;
	}
	//if ((online_reg.set_osd1_offline == 1 || online_reg.set_osd2_offline == 1 ||
	//	online_reg.set_osd3_offline == 1 || online_reg.set_osd5_offline == 1) && (online_reg.set_osd4_offline == 0)) {
	//	isOnlineState = 0;
	//	ret_state = OFFLINE_STATE;
	//}
	DBG_PRINT(KERN_EMERG"%s online_reg.regValue=0x%x, isOnlineState=%d \n", __FUNCTION__, online_reg.regValue, isOnlineState);

	/*  */
	if (hasCompress && isOnlineState == 1) {
		GDMA_OnlineWritebackDisplay();
		/* switch OSD1/2/3/5 to offline */
		online_reg.regValue = rtd_inl(GDMA_ONLINE_reg);
		online_reg.set_osd1_offline = osd1offline;
		online_reg.set_osd2_offline = 1;
		online_reg.set_osd3_offline = 1;
		online_reg.set_osd5_offline = 1;
		rtd_outl(GDMA_ONLINE_reg, online_reg.regValue);
		if (osd1offline)
			DBG_PRINT(KERN_EMERG"%s OSD1/2/3/5 switch to offline \n", __FUNCTION__);
		else
			DBG_PRINT(KERN_EMERG"%s OSD2/3/5 switch to offline \n", __FUNCTION__);
		return ON_2_OFFLINE_SWITCH;
	}
#if 0
	if (hasCompress == 0 && isOnlineState == 0) {
		/* switch OSD1/2/3/5 to online */
		online_reg.set_osd1_offline = 0;
		online_reg.set_osd2_offline = 0;
		online_reg.set_osd3_offline = 0;
		online_reg.set_osd5_offline = 0;
		//mdelay(3000);
		rtd_outl(GDMA_ONLINE_reg, online_reg.regValue);
		DBG_PRINT(KERN_EMERG"%s OSD1/2/3/5 switch to online \n", __FUNCTION__);
		//mdelay(3000);
		return OFF_2_ONLINE_SWITCH;
	}
#endif
	return ret_state;
}
#endif








//=======================================================================compress
