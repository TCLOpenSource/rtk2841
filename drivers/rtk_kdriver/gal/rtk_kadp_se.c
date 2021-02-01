#include <linux/string.h>
#include <linux/kernel.h>
#include <rtk_kadp_se.h>
#include <rtk_se_lib.h>

#define SE_WAIT_DONE

#define EXT_BASE_UNIT 18
#if SE_SE20 || SE_OLD
static KGAL_SURFACE_INFO_T g_st_tmp_surf;
#endif

#if SE_OLD
#define LIMIT_XY  4096
#else
#define LIMIT_XY  8192
#endif


/************************************************************************
*  Static function prototypes
************************************************************************/
static bool SEDFBDrawGuard(KGAL_DRAW_FLAGS_T* pDrawFlags,
	KGAL_DRAW_SETTINGS_T* pDrawSettings,SE_BLEND_EX_T* pEx);

static bool SEBoundaryGuard(KGAL_SURFACE_INFO_T* pSurface,
	KGAL_RECT_T* pRect);

static bool SEFormatGuard(KGAL_SURFACE_INFO_T* pSurface,
	SEINFO_SETUPMODE stpMode, SE_COLOR_FORMAT_EX_T *fmt, bool st);

static void inner_wait_done(void);

//static bool inner_update_se_clut(KGAL_SURFACE_INFO_T *surf);


#if SE_SE20 || SE_SE20_EXT
static bool inner_fast_fill(KGAL_SURFACE_INFO_T* pDstSurface,
	KGAL_RECT_T* pDstRect, UINT32 color,
	KGAL_DRAW_FLAGS_T* pDrawFlags,
	KGAL_DRAW_SETTINGS_T* pDrawSettings);
#endif

#if SE_SE20
static bool inner_fbc_Blit(KGAL_SURFACE_INFO_T* pSrcSurface,
	KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface,
	UINT16 dx, UINT16 dy, KGAL_BLIT_FLAGS_T* pBlitFlags,
	KGAL_BLIT_SETTINGS_T* pBlitSettings);

static bool inner_fbc_stchblit(KGAL_SURFACE_INFO_T* pSrcSurface,
	KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface,
	KGAL_RECT_T* pDstRect, KGAL_BLIT_FLAGS_T* pBlitFlags,
	KGAL_BLIT_SETTINGS_T* pBlitSettings);

static bool inner_argb_fbc_stchblit(KGAL_SURFACE_INFO_T* pSrcSurface,
	KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface,
	KGAL_RECT_T* pDstRect, KGAL_BLIT_FLAGS_T* pBlitFlags,
	KGAL_BLIT_SETTINGS_T* pBlitSettings);
#endif


#if SE_SE20 || SE_SE20_EXT
static bool inner_fast_cpy_conv(KGAL_SURFACE_INFO_T* pSrcSurface,
	KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface,
	UINT16 dx, UINT16 dy, KGAL_BLIT_FLAGS_T* pBlitFlags,
	KGAL_BLIT_SETTINGS_T* pBlitSettings);
#endif

bool KGAL_FormatConv(KGAL_SURFACE_INFO_T* pSrcSurface,
	KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface,
	UINT16 dx, UINT16 dy, KGAL_BLIT_FLAGS_T* pBlitFlags,
	KGAL_BLIT_SETTINGS_T* pBlitSettings);


#if SE_SE20 || SE_OLD
static bool inner_rotate(KGAL_SURFACE_INFO_T* pSrcSurface,
	KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface,
	UINT16 dx, UINT16 dy, KGAL_BLIT_FLAGS_T* pBlitFlags,
	KGAL_BLIT_SETTINGS_T* pBlitSettings);

static bool inner_mirror(KGAL_SURFACE_INFO_T* pSrcSurface,
	KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface,
	UINT16 dx, UINT16 dy, KGAL_BLIT_FLAGS_T* pBlitFlags,
	KGAL_BLIT_SETTINGS_T* pBlitSettings);
#endif

static KGAL_BLIT_FLAGS_T _strmBlitFg = (KGAL_BLIT_FLAGS_T)
	(KGAL_BLIT_ROTATE90 | KGAL_BLIT_ROTATE180 |
	KGAL_BLIT_ROTATE270| KGAL_BLIT_VERTICAL_MIRROR|
	KGAL_BLIT_HORIZONTAL_MIRROR);

static bool inner_set_pinfo(KGAL_SURFACE_INFO_T* psf,
	SE_PROCINFO_T* ppi, KGAL_RECT_T* prt, unsigned int offset);



static bool inner_set_pinfo(KGAL_SURFACE_INFO_T* psf,
	SE_PROCINFO_T* ppi, KGAL_RECT_T* prt, unsigned int offset) {

#if SE_SE20
	unsigned int fbdc_dt_offset = 0;
#endif

	if(psf == NULL || ppi == NULL || prt == NULL || offset > 3) {
		return false;
	}

#if SE_SE20
	if(psf->pixelFormat == KGAL_PIXEL_FORMAT_FBC) {
		ppi->byBaseAddressIndex = offset;
		ppi->uAddr = psf->physicalAddress + 0x100;
		ppi->uPitch = psf->width;
		fbdc_dt_offset = psf->width*psf->height/16/4;

		if(fbdc_dt_offset<=128)
			fbdc_dt_offset = 128;
		else
			fbdc_dt_offset = (fbdc_dt_offset+127)/128*128;

		ppi->byChronmaAddressIndex = offset+2;
		ppi->uAddr_c1 = ppi->uAddr + fbdc_dt_offset;
		ppi->uPitch_c1 = psf->width;

	}else{
#endif
		ppi->byBaseAddressIndex = offset;
		ppi->uAddr = psf->physicalAddress;
		ppi->uPitch = psf->pitch;
#if SE_SE20
	}
#endif

	ppi->wDataX = prt->x;
	ppi->wDataY = prt->y;
	ppi->wDataWidth = prt->w;
	ppi->wDataHeight = prt->h;

	return true;
}


static bool SEFormatConvGuard(KGAL_SURFACE_INFO_T* pSSurface,
	KGAL_SURFACE_INFO_T* pDSurface,
	SEINFO_CONVERSION* pConvType,
	SEINFO_SRC_FORMAT* pConvSrcFormat,
	SEINFO_DEST_FORMAT* pConvDestFormat) {

	if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8 &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB) {
		*pConvType = SEINFO_CONVERSION_INDEX_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_INDEX8;
		*pConvDestFormat = SEINFO_DEST_FORMAT_ARGB8888;
	}else if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB) {
		*pConvType = SEINFO_CONVERSION_ARGB_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_ARGB8888;
		*pConvDestFormat = SEINFO_DEST_FORMAT_ARGB8888;
	}else if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8 &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {
		*pConvType = SEINFO_CONVERSION_ARGB_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_ARGB8888;
		*pConvDestFormat = SEINFO_DEST_FORMAT_ARGB8888;
	}else if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_RGB888 &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB) {
		*pConvType = SEINFO_CONVERSION_ARGB_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_RGB888;
		*pConvDestFormat = SEINFO_DEST_FORMAT_ARGB8888;
	}else if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_RGB888) {
		*pConvType = SEINFO_CONVERSION_ARGB_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_ARGB8888;
		*pConvDestFormat = SEINFO_DEST_FORMAT_RGB888;
	}else if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB4444 &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB) {
		*pConvType = SEINFO_CONVERSION_ARGB_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_ARGB4444;
		*pConvDestFormat = SEINFO_DEST_FORMAT_ARGB8888;
	}else if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB4444 ) {
		*pConvType = SEINFO_CONVERSION_ARGB_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_ARGB4444;
		*pConvDestFormat = SEINFO_DEST_FORMAT_ARGB8888;
	}else if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB4444 ) {
		*pConvType = SEINFO_CONVERSION_ARGB_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_ARGB8888;
		*pConvDestFormat = SEINFO_DEST_FORMAT_ARGB4444;
	}else if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB4444 &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB4444 ) {
		*pConvType = SEINFO_CONVERSION_ARGB_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_ARGB4444;
		*pConvDestFormat = SEINFO_DEST_FORMAT_ARGB4444;
	}else if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_RGB16 &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB) {
		*pConvType = SEINFO_CONVERSION_ARGB_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_RGB565;
		*pConvDestFormat = SEINFO_DEST_FORMAT_ARGB8888;
	}else if(pSSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB &&
		pDSurface->pixelFormat == KGAL_PIXEL_FORMAT_RGB16) {
		*pConvType = SEINFO_CONVERSION_ARGB_ARGB;
		*pConvSrcFormat = SEINFO_SRC_FORMAT_ARGB8888;
		*pConvDestFormat = SEINFO_DEST_FORMAT_RGB565;
	}else{
		return false;
	}

	return true;
}


static void inner_flush_surface( KGAL_SURFACE_INFO_T* pDestSurface)
{
	return;
}

static void inner_wait_done(void) {
#if defined(SE_WAIT_DONE)
	//SE_WaitCmdDone(400, 0);
#endif
}

#if SE_SE20 || SE_OLD
static bool inner_check_I8addr(void) {
		g_st_tmp_surf.physicalAddress = SE_Get_mem();
	g_st_tmp_surf.width = LUT8_WIDTH;
	g_st_tmp_surf.height = LUT8_HEIGHT;
		g_st_tmp_surf.pixelFormat = KGAL_PIXEL_FORMAT_ARGB;

	if(g_st_tmp_surf.physicalAddress == 0)
		return false;
	return true;

}

static bool inner_lut82argb(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pSrcRect) {

	KGAL_RECT_T trect;
	KGAL_BLIT_FLAGS_T tflags = KGAL_BLIT_NOFX;
	KGAL_BLIT_SETTINGS_T tsettings;

	if(pSrcRect->w > LUT8_WIDTH || pSrcRect->h > LUT8_HEIGHT) {
		printk(KERN_ERR"[GAL][%s] LUT8 size out of range.", __func__);
		return false;
	}

	if(inner_check_I8addr() == false)
		return false;

	if(pSrcSurface->pixelFormat != KGAL_PIXEL_FORMAT_LUT8)
		return false;

	tsettings.srcBlend = KGAL_BLEND_ONE;
	tsettings.dstBlend = KGAL_BLEND_ZERO;

	trect.x = pSrcRect->x;
	trect.y = pSrcRect->y;
	trect.w = pSrcRect->w;
	trect.h = pSrcRect->h;

	pDstSurface->width = pSrcSurface->width;
	pDstSurface->height = pSrcSurface->height;
	pDstSurface->physicalAddress = g_st_tmp_surf.physicalAddress;
	pDstSurface->pitch = pSrcSurface->pitch*4;
	pDstSurface->pixelFormat = KGAL_PIXEL_FORMAT_ARGB;
	pDstSurface->bpp = pSrcSurface->bpp*4;

/*
	baker, RHAL will call set palette, don't need to add this
	if(inner_update_se_clut(pSrcSurface) == false) {
		return false;
	}
*/
	if(KGAL_FormatConv(pSrcSurface, &trect, pDstSurface, pSrcRect->x, pSrcRect->y, &tflags, &tsettings) == false) {
		printk(KERN_ERR"[GAL][%s] fail.", __func__);
		return false;
	}

	return true;
}

static bool inner_srcfmtconv(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_SURFACE_INFO_T* pTSurface, KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pSrcRect) {
	KGAL_RECT_T trect;
	KGAL_BLIT_FLAGS_T tflags = KGAL_BLIT_NOFX;
	KGAL_BLIT_SETTINGS_T tsettings;

	if(pSrcRect->w > LUT8_WIDTH || pSrcRect->h > LUT8_HEIGHT) {
		printk(KERN_ERR"[GAL][%s] [%d*%d] size out of range.", __func__,pSrcRect->w,pSrcRect->h);
		return false;
	}

	if(inner_check_I8addr() == false)
		return false;

	tsettings.srcBlend = KGAL_BLEND_ONE;
	tsettings.dstBlend = KGAL_BLEND_ZERO;

	trect.x = pSrcRect->x;
	trect.y = pSrcRect->y;
	trect.w = pSrcRect->w;
	trect.h = pSrcRect->h;

	pDstSurface->width = pSrcSurface->width;
	pDstSurface->height = pSrcSurface->height;
	pDstSurface->physicalAddress = g_st_tmp_surf.physicalAddress;
	pDstSurface->pitch = pTSurface->pitch;
	pDstSurface->pixelFormat = pTSurface->pixelFormat;
	pDstSurface->bpp = pTSurface->bpp;

	if(KGAL_FormatConv(pSrcSurface, &trect, pDstSurface, pSrcRect->x, pSrcRect->y, &tflags, &tsettings) == false) {
		printk(KERN_ERR"[GAL][%s] fail.", __func__);
		return false;
	}

	return true;
}
#endif

#if SE_SE20_EXT || SE_SE20
static bool inner_stretch_check(KGAL_RECT_T* pSrcRect, KGAL_RECT_T* pDstRect) {
#if SE_SE20_EXT
	if(pSrcRect->w < EXT_BASE_UNIT ||
		pSrcRect->h < EXT_BASE_UNIT ||
		pDstRect->w < EXT_BASE_UNIT ||
		pDstRect->h < EXT_BASE_UNIT)
		return false;
	return true;
#else
	if(pSrcRect->w < EXT_BASE_UNIT ||
		pSrcRect->h < EXT_BASE_UNIT ||
		pDstRect->w < EXT_BASE_UNIT ||
		pDstRect->h < EXT_BASE_UNIT)
		return false;
	if(((pDstRect->x+pDstRect->w - 1)%16 == 14 ||
		    (pDstRect->x+pDstRect->w - 1 )%16 == 15 )
		&& (pDstRect->h - 1)%16 == 15) {
		return true;
	}
	if(pSrcRect->w == 1366 && pSrcRect->h == 768
		&& pDstRect->w == 1920 && pDstRect->h == 1080)
		return true;
	else if(pSrcRect->w == 1280 && pSrcRect->h == 720
		&& pDstRect->w == 1920 && pDstRect->h == 1080)
		return true;
	else if(pSrcRect->w == 783 && pSrcRect->h == 522
		&& pDstRect->w == 1920 && pDstRect->h == 1080)
		return true;

	if((pDstRect->x+pDstRect->w)%16 == 0
		|| (pDstRect->x+pDstRect->w)%16 >=3)
		return true;
#if 0
	if((pDstRect->x+pDstRect->w)%16 == 0
		|| (pDstRect->x+pDstRect->w)%16 >=3)
		return true;
	else if((pDstRect->x+pDstRect->w)%16 == 1
		|| (pDstRect->x+pDstRect->w)%16 == 2) {
		return false;
	}
#endif

	return false;
#endif
}
#endif
#if 0
static int inner_set_se_clut(KGAL_PALETTE_SURFACE_INFO_T *local_palette)
{
	if(local_palette == 0) {
		printk(KERN_ERR"%s,%d trace..\n", __func__, __LINE__);
		return -1;
	}
	if(local_palette->Surface.pixelFormat != KGAL_PIXEL_FORMAT_LUT8) {
		printk(KERN_ERR"%s,%d trace..\n", __func__, __LINE__);
		return -1;
	}
	if(local_palette->palette.length > 256) {
		printk(KERN_ERR"%s,%d trace..\n", __func__, __LINE__);
		return -1;
	}

	printk(KERN_ERR"%s,%d trace..\n", __func__, __LINE__);
	SE_WriteClut((UINT32*)&local_palette->palette.palette, local_palette->palette.length);
	return true;

}
#endif
#if 0
static bool inner_update_se_clut(KGAL_SURFACE_INFO_T *surf)
{
	if(surf == NULL) {
		return false;
	}
	if(surf->pixelFormat != KGAL_PIXEL_FORMAT_LUT8) {
		return false;
	}
	SE_WriteClut((UINT32*)&surf->paletteInfo.palette, surf->paletteInfo.length);

	//if(inner_set_se_clut(&stps) == false) {
	//	return false;
	//}
	return true;

}
#endif

#if SE_SE20_EXT || SE_SE20
static int inner_ext_fmt_check(KGAL_PIXEL_FORMAT_T* p_ori_fmt,
	SEINFO_EXT_COLOR_FORMAT_T* p_ext_fmt) {

	switch(*p_ori_fmt)
	{
		case KGAL_PIXEL_FORMAT_ARGB:
			*p_ext_fmt = SEINFO_EXT_COLOR_FORMAT_ARGB8888;
			break;
		case KGAL_PIXEL_FORMAT_ARGB1555:
			*p_ext_fmt = SEINFO_EXT_COLOR_FORMAT_ARGB1555;
			break;
		case KGAL_PIXEL_FORMAT_RGB16:
			*p_ext_fmt = SEINFO_EXT_COLOR_FORMAT_YUY2_422;
			break;
		case KGAL_PIXEL_FORMAT_ARGB4444:
			*p_ext_fmt = SEINFO_EXT_COLOR_FORMAT_ARGB4444;
			break;
		case KGAL_PIXEL_FORMAT_RGB888:
			*p_ext_fmt = SEINFO_EXT_COLOR_FORMAT_RGB888;
			break;
		case KGAL_PIXEL_FORMAT_FBC:
			*p_ext_fmt = SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8;
			break;
		case KGAL_PIXEL_FORMAT_LUT8:
			*p_ext_fmt = SEINFO_EXT_COLOR_FORMAT_INDEX8;
			break;
		case KGAL_PIXEL_FORMAT_NV12:
			*p_ext_fmt = SEINFO_EXT_COLOR_FORMAT_NV12_420;
			break;
		case KGAL_PIXEL_FORMAT_YUY2:
			*p_ext_fmt = SEINFO_EXT_COLOR_FORMAT_YUY2_422;
			break;
		case KGAL_PIXEL_FORMAT_NV16:
			*p_ext_fmt = SEINFO_EXT_COLOR_FORMAT_NV12_422;
			break;
		default:
			return false;
	}
	return true;
}
#endif

#if SE_SE20 || SE_SE20_EXT
bool inner_fast_cpy_conv(KGAL_SURFACE_INFO_T* pSrcSurface,
	KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface,
	UINT16 dx, UINT16 dy, KGAL_BLIT_FLAGS_T* pBlitFlags,
	KGAL_BLIT_SETTINGS_T* pBlitSettings) {

	SE_EXT_FMT_CONV_T stExFmt;
	KGAL_SURFACE_INFO_T* pfSrcSurface = pSrcSurface;
	SE_PROCINFO_T  stSrcProcInfo,stDstProcInfo;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_MANUAL;//dummy

	memset(&stSrcProcInfo, 0, sizeof(stSrcProcInfo));
	memset(&stDstProcInfo, 0, sizeof(stDstProcInfo));
	memset(&stExFmt, 0x00, sizeof(SE_EXT_FMT_CONV_T));

	if(SEFormatGuard(pDstSurface, stMode,
		    &stExFmt.st_blend_layer0.stcolorfmt,true) == false)
		return false;


	if(pfSrcSurface->pixelFormat != KGAL_PIXEL_FORMAT_LUT8  &&
		pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {
		return false;
	}

	if(inner_set_pinfo(pfSrcSurface, &stSrcProcInfo, pSrcRect, 0) == false)
		return false;

	if(inner_set_pinfo(pDstSurface, &stDstProcInfo, pSrcRect, 1) == false)
		return false;

	stDstProcInfo.wDataX = dx;
	stDstProcInfo.wDataY = dy;


	if(pfSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8
		&& pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {

		stSrcProcInfo.wDataX = 0;
		stSrcProcInfo.wDataY = 0;
		stSrcProcInfo.wDataWidth = pfSrcSurface->width;
		stSrcProcInfo.wDataHeight = pfSrcSurface->height/4;
		stSrcProcInfo.uPitch = pfSrcSurface->width*4;

		stDstProcInfo.wDataX = 0;
		stDstProcInfo.wDataY = 0;
		stDstProcInfo.wDataWidth = stSrcProcInfo.wDataWidth;
		stDstProcInfo.wDataHeight = stSrcProcInfo.wDataHeight;
		stDstProcInfo.uPitch = stSrcProcInfo.uPitch;

		stExFmt.src1_format = SEINFO_EXT_COLOR_FORMAT_ARGB8888;
		stExFmt.src2_format = SEINFO_EXT_COLOR_FORMAT_ARGB8888;
		stExFmt.result_format = SEINFO_EXT_COLOR_FORMAT_ARGB8888;

	}else{

		if(inner_ext_fmt_check(&pfSrcSurface->pixelFormat,
				&stExFmt.src1_format ) == false)
			return false;
		if(inner_ext_fmt_check(&pfSrcSurface->pixelFormat,
				&stExFmt.src2_format ) == false)
			return false;
		if(inner_ext_fmt_check(&pDstSurface->pixelFormat,
				&stExFmt.result_format ) == false)
			return false;
	}

	stExFmt.st_blend_layer0.bEnableWithBitblit = false;

	stExFmt.src1_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
	stExFmt.src2_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;

	if(pfSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB
		&& pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_FBC
		&& pfSrcSurface->width <= 900) {
		stExFmt.st_blend_layer0.bEnableWithBitblit = true;
		stExFmt.st_blend_layer0.ropMode = SEINFO_ROP_MODE;
	}

#if SE_SE20_EXT
	if(*pBlitFlags & KGAL_BLIT_ROTATE90)
		stExFmt.st_blend_layer0.rot = SE20INFO_ROTATE_90;
	else if (*pBlitFlags & KGAL_BLIT_ROTATE180)
		stExFmt.st_blend_layer0.rot = SE20INFO_ROTATE_180;
	else if (*pBlitFlags & KGAL_BLIT_ROTATE270)
		stExFmt.st_blend_layer0.rot = SE20INFO_ROTATE_270;
	else
		stExFmt.st_blend_layer0.rot = SE20INFO_ROTATE_0;


	if (*pBlitFlags & (KGAL_BLIT_HORIZONTAL_MIRROR |KGAL_BLIT_VERTICAL_MIRROR))
		stExFmt.st_blend_layer0.mir = SE20INFO_MIRROR_XY;
	else if(*pBlitFlags & KGAL_BLIT_VERTICAL_MIRROR)
		stExFmt.st_blend_layer0.mir = SE20INFO_MIRROR_Y;
	else if (*pBlitFlags & KGAL_BLIT_HORIZONTAL_MIRROR)
		stExFmt.st_blend_layer0.mir = SE20INFO_MIRROR_X;
	else
		stExFmt.st_blend_layer0.mir = SE20INFO_MIRROR_0;

	if(stExFmt.st_blend_layer0.rot && stExFmt.st_blend_layer0.mir)
		return false;
#endif
	SE_EXT_FormatConversion(&stDstProcInfo, &stSrcProcInfo,
		(void*)&stExFmt);

	inner_wait_done();


	return true;
}
#endif

#if SE_SE20 || SE_OLD
static bool inner_rotate(KGAL_SURFACE_INFO_T* pSrcSurface,
	KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface,
	UINT16 dx, UINT16 dy, KGAL_BLIT_FLAGS_T* pBlitFlags,
	KGAL_BLIT_SETTINGS_T* pBlitSettings)
{
	SE_EXT_FMT_CONV_T stExFmt;
	KGAL_SURFACE_INFO_T* pfSrcSurface = pSrcSurface;
	SE_PROCINFO_T  stSrcProcInfo,stDstProcInfo;
	SEINFO_ROTATE rotmode = SEINFO_ROTATE_DISABLE;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_MANUAL;//dummy

	memset(&stSrcProcInfo, 0, sizeof(stSrcProcInfo));
	memset(&stDstProcInfo, 0, sizeof(stDstProcInfo));
	memset(&stExFmt, 0x00, sizeof(SE_EXT_FMT_CONV_T));


	if(SEFormatGuard(pDstSurface, stMode, &stExFmt.st_blend_layer0.stcolorfmt,true) == false)
		return false;
	if(inner_set_pinfo(pfSrcSurface, &stSrcProcInfo, pSrcRect, 0) == false)
		return false;

	if(inner_set_pinfo(pDstSurface, &stDstProcInfo, pSrcRect, 1) == false)
		return false;

	if(*pBlitFlags & KGAL_BLIT_ROTATE90)
		rotmode = SEINFO_ROTATE_90;
	else if (*pBlitFlags & KGAL_BLIT_ROTATE180)
		rotmode = SEINFO_ROTATE_180;
	else if (*pBlitFlags & KGAL_BLIT_ROTATE270)
		rotmode = SEINFO_ROTATE_270;
	else {
		return false;
	}

	stDstProcInfo.wDataX = dx;
	stDstProcInfo.wDataY = dy;

	SE_Rotate(&stDstProcInfo, &stSrcProcInfo,
		rotmode, (void*)&stExFmt);

	return true;
}

bool inner_mirror(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_RECT_T* pSrcRect,
	KGAL_SURFACE_INFO_T* pDstSurface, UINT16 dx, UINT16 dy,
	KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings) {
	SE_EXT_FMT_CONV_T stExFmt;
	KGAL_SURFACE_INFO_T* pfSrcSurface = pSrcSurface;
	SE_PROCINFO_T  stSrcProcInfo,stDstProcInfo;
	SEINFO_MIRRORMODE mode = 0;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_MANUAL;//dummy

	memset(&stSrcProcInfo, 0, sizeof(stSrcProcInfo));
	memset(&stDstProcInfo, 0, sizeof(stDstProcInfo));
	memset(&stExFmt, 0x00, sizeof(SE_EXT_FMT_CONV_T));


	if(SEFormatGuard(pDstSurface, stMode, &stExFmt.st_blend_layer0.stcolorfmt,true) == false)
		return false;

	if(inner_set_pinfo(pfSrcSurface, &stSrcProcInfo, pSrcRect, 0) == false)
		return false;

	if(inner_set_pinfo(pDstSurface, &stDstProcInfo, pSrcRect, 1) == false)
		return false;

	if ((*pBlitFlags & (KGAL_BLIT_HORIZONTAL_MIRROR|KGAL_BLIT_VERTICAL_MIRROR)) == (KGAL_BLIT_HORIZONTAL_MIRROR|KGAL_BLIT_VERTICAL_MIRROR))
		mode = SEINFO_MIRROR_XY;
	else if(*pBlitFlags & KGAL_BLIT_VERTICAL_MIRROR)
		mode = SEINFO_MIRROR_Y;
	else if (*pBlitFlags & KGAL_BLIT_HORIZONTAL_MIRROR)
		mode = SEINFO_MIRROR_X;
	else {
		return false;
	}

	stDstProcInfo.wDataX = dx;
	stDstProcInfo.wDataY = dy;

	SE_Mirror(&stDstProcInfo, &stSrcProcInfo,
		mode, (void*)&stExFmt);

	return true;
}
#endif

#if SE_SE20_EXT || SE_SE20
bool inner_fast_fill(KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pDstRect,
        UINT32 color, KGAL_DRAW_FLAGS_T* pDrawFlags, KGAL_DRAW_SETTINGS_T* pDrawSettings)
{

	SE_EXT_FMT_CONV_T stExFmt;
	SE_PROCINFO_T stSrcProcInfo, stDstProcInfo;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_CONST;

	memset(&stSrcProcInfo, 0, sizeof(stSrcProcInfo));
	memset(&stDstProcInfo, 0, sizeof(stDstProcInfo));
	memset(&stExFmt, 0x00, sizeof(SE_EXT_FMT_CONV_T));


	if(SEDFBDrawGuard(pDrawFlags, pDrawSettings ,&stExFmt.st_blend_layer0) == false)
		return false;
	if(SEBoundaryGuard(pDstSurface, pDstRect) == false)
		return false;
	// for FMT , ths stMode is fake.
	if(*pDrawFlags != KGAL_DRAW_NOFX)
		stMode = SEINFO_BITBLT_SETUP_MANUAL;

	if(SEFormatGuard(pDstSurface, stMode, &stExFmt.st_blend_layer0.stcolorfmt,false) == false)
		return false;

	stExFmt.st_blend_layer0.constColorValue = color;

	stExFmt.src1_select = SEINFO_BITBLT_EXT_SELECT_CONST;
	stExFmt.src2_select = SEINFO_BITBLT_EXT_SELECT_CONST;

	if(*pDrawFlags == KGAL_DRAW_NOFX ||
		(stExFmt.st_blend_layer0.srcAlphaModeSelect == SEINFO_BITBLT_ALPHA_DFB_CONSTANT_1 &&
		stExFmt.st_blend_layer0.selSrcClrBlend == SEINFO_DFB_BLEND_CONST_1 &&
		stExFmt.st_blend_layer0.destAlphaModeSelect == SEINFO_BITBLT_ALPHA_DFB_CONSTANT_0 &&
		stExFmt.st_blend_layer0.selDestClrBlend == SEINFO_DFB_BLEND_CONST_0)) {
		//will run fast fmt
		stExFmt.st_blend_layer0.ropMode = SEINFO_ROP_MODE;
		stExFmt.st_blend_layer0.bEnableWithBitblit= false;
	}else{
		stExFmt.st_blend_layer0.ropMode = SEINFO_ALPHA_BLENDING;
		stExFmt.st_blend_layer0.bEnableWithBitblit= true;
	}


	if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.src1_format ) == false)
		return false;
	if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.src2_format ) == false)
		return false;
	if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.result_format ) == false)
		return false;

	/*NOTICE:*/
	if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_FBC) {
		stExFmt.src1_format = SEINFO_EXT_COLOR_FORMAT_ARGB8888;
		stExFmt.src2_format = SEINFO_EXT_COLOR_FORMAT_ARGB8888;
		stExFmt.result_format = SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8;
		//stExFmt.st_blend_layer0.ropMode = SEINFO_ALPHA_BLENDING;
	}
	if(inner_set_pinfo(pDstSurface, &stSrcProcInfo, pDstRect, 0) == false)
		return false;

	if(inner_set_pinfo(pDstSurface, &stDstProcInfo, pDstRect, 1) == false)
		return false;


	if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {
		stExFmt.src1_format = SEINFO_EXT_COLOR_FORMAT_ARGB8888;
		stExFmt.src2_format = SEINFO_EXT_COLOR_FORMAT_ARGB8888;
		stExFmt.result_format = SEINFO_EXT_COLOR_FORMAT_ARGB8888;
		/*Don't need to divide by 4 , caz' pitch value is index8 */
		//stSrcProcInfo.wDataHeight/=4;
		stExFmt.st_blend_layer0.constColorValue = (color&0xff) | (color&0xff)<<8 | (color&0xff)<<16 | (color&0xff)<<24;
	}
	SE_EXT_FormatConversion(&stDstProcInfo, &stSrcProcInfo,
		(void*)&stExFmt);

	inner_wait_done();

	return true;
}
#endif

static bool SEStretchFactorGuard(KGAL_RECT_T* psRect, KGAL_RECT_T* pdRect,
	SEINFO_SACLING_TYPE* pht, UINT32* phf,
	SEINFO_SACLING_TYPE* pvt, UINT32* pvf) {

	if(pdRect->w == 0 || pdRect->h == 0)
		return false;

	*phf = (psRect->w<<14)/pdRect->w;
	*pvf = (psRect->h<<14)/pdRect->h;

#if 1
	if(*phf <= 0x3ffff)
		*pht = SEINFO_SCALING_DOWN;
	else
		return false;
#else
	if((*phf <= 0x20000 && *phf >= 0x800))
		*pht = SEINFO_SCALING_DOWN;
	else
		return false; //if there is hw limit.
#endif

#if 1
	if(*pvf <= 0x3ffff)
		*pvt = SEINFO_SCALING_DOWN;
	else
		return false;
#else
	if((*pvf <= 0x20000 && *pvf >= 0x800))
		*pvt = SEINFO_SCALING_DOWN;
	else
		return false; //if there is hw limit.
#endif

	if(psRect->w == 1 || psRect->h == 1)
		return false;

	return true;
};

static bool SEBoundaryGuard(KGAL_SURFACE_INFO_T* pSurface, KGAL_RECT_T* pRect) {
	UINT16 shiftX = 0, shiftY = 0;
	if(pSurface == NULL || pRect == NULL)
		return false;
	if((pRect->w) > pSurface->width || (pRect->h) > pSurface->height)
		return false;
	if(pSurface->physicalAddress == 0)
		return false;
	if((pRect->x >= LIMIT_XY) || (pRect->y >= LIMIT_XY)) {
		if(pRect->x >= LIMIT_XY) {
			shiftX = LIMIT_XY;
			pRect->x -= shiftX;
		}
		if(pRect->y >= LIMIT_XY) {
			shiftY = LIMIT_XY;
			pRect->y -= shiftY;
		}
		pSurface->physicalAddress += pSurface->pitch * shiftY + (pSurface->bpp/8) * shiftX;
	}
	return true;
}


static bool SEFormatGuard(KGAL_SURFACE_INFO_T* pSurface, SEINFO_SETUPMODE stpMode, SE_COLOR_FORMAT_EX_T *fmt, bool st /*=false*/)
{
	bool bBPPCheck = false;
	SEINFO_COLOR_FORMAT_T stSEFormat;

	if(pSurface == NULL)
		return false;

	if(pSurface->width > 8192 || pSurface->width == 0 ||
		pSurface->height > 8192 || pSurface->height == 0 ||
		pSurface->pitch > 8192*4 || pSurface->pitch ==0 ||
		pSurface->bpp > 32 || pSurface->bpp==0) {
		return false;
	}
	memset((void *)&stSEFormat, 0, sizeof(SEINFO_COLOR_FORMAT_T));

	switch(pSurface->pixelFormat) {
		case KGAL_PIXEL_FORMAT_ARGB:
		{
			stSEFormat = SEINFO_COLOR_FORMAT_ARGB8888;
			if(pSurface->bpp == 32)
				bBPPCheck = true;
			break;
		}
		case KGAL_PIXEL_FORMAT_FBC:
		{
#if SE_SE20
			stSEFormat = SEINFO_COLOR_FORMAT_ARGB8888;
			pSurface->bpp = 32;
			if(pSurface->bpp == 32)
				bBPPCheck = true;
#else
			bBPPCheck = false;
#endif
			break;
		}
		case KGAL_PIXEL_FORMAT_LUT8:
		{
			stSEFormat = SEINFO_COLOR_FORMAT_INDEX8;
			if(pSurface->bpp ==8)
				bBPPCheck = true;
			break;
		}
		case KGAL_PIXEL_FORMAT_ARGB1555:
		{
			stSEFormat = SEINFO_COLOR_FORMAT_ARGB1555;
			bBPPCheck = true;
			break;
		}
		case KGAL_PIXEL_FORMAT_RGB16:
		{
			stSEFormat = SEINFO_COLOR_FORMAT_RGB565;
			if(pSurface->bpp ==16)
				bBPPCheck = true;
			break;
		}
		case KGAL_PIXEL_FORMAT_ARGB4444:
		{
			stSEFormat = SEINFO_COLOR_FORMAT_ARGB4444;
			if(pSurface->bpp ==16)
				bBPPCheck = true;
			break;
		}
		case KGAL_PIXEL_FORMAT_RGB888:
		{
			stSEFormat = SEINFO_COLOR_FORMAT_RGB888;
			if(pSurface->bpp ==24)
				bBPPCheck = true;
			break;
		}
		case KGAL_PIXEL_FORMAT_NV12:
		case KGAL_PIXEL_FORMAT_YUY2:
		case KGAL_PIXEL_FORMAT_NV16:
		{
#if SE_SE20 || SE_SE20_EXT
			stSEFormat = SEINFO_COLOR_FORMAT_YUV422;
			if(pSurface->bpp ==16)
				bBPPCheck = true;
#else
			bBPPCheck = false;
#endif
			break;
		}
		default:
		{
			break;
		}
	}

	fmt->byColorFormat = stSEFormat;
	fmt->byArgbAlphaLocation = SEINFO_ARGB_ALPHA_LEFTMOST;
	fmt->byOutputArgbAlphaLocation = SEINFO_ARGB_ALPHA_LEFTMOST;

	if(bBPPCheck){
		fmt->bEnableRoundingOption = true;
		if(stpMode == SEINFO_BITBLT_SETUP_CONST) {
			fmt->bInputSrcColorFormatBigEndian = true;
			fmt->bInputDestColorFormatBigEndian = true;
		}else{
			if(st == true) {
				fmt->bInputSrcColorFormatBigEndian = false;
			}else{
				fmt->bInputSrcColorFormatBigEndian = true;
			}
		}
	}

	return bBPPCheck;

}


static bool SEBLENDGuard(KGAL_BLEND_FUNCTION_T stpBlend, SEINFO_ALPHAMODE_T* pAlpha , SEINFO_DFB_CLR_BLEND_MODE* pRGB) {

	switch(stpBlend) {
	case KGAL_BLEND_ZERO:
		*pAlpha = SEINFO_BITBLT_ALPHA_DFB_CONSTANT_0;
		*pRGB = SEINFO_DFB_BLEND_CONST_0;
		break;
	case KGAL_BLEND_ONE:
		*pAlpha = SEINFO_BITBLT_ALPHA_DFB_CONSTANT_1;
		*pRGB = SEINFO_DFB_BLEND_CONST_1;
		break;
	case KGAL_BLEND_SRCCOLOR:
		*pAlpha = SEINFO_BITBLT_ALPHA_SRC;
		*pRGB = SEINFO_DFB_BLEND_RGB_SRC;
		break;
	case KGAL_BLEND_INVSRCCOLOR:
		*pAlpha = SEINFO_BITBLT_ALPHA_1_SRC;
		*pRGB = SEINFO_DFB_BLEND_RGB_1_SRC;
		break;
	case KGAL_BLEND_SRCALPHA:
		*pAlpha = SEINFO_BITBLT_ALPHA_SRC;
		*pRGB = SEINFO_DFB_BLEND_ALPHA_SRC;
		break;
	case KGAL_BLEND_INVSRCALPHA:
		*pAlpha = SEINFO_BITBLT_ALPHA_1_SRC;
		*pRGB = SEINFO_DFB_BLEND_ALPHA_1_SRC;
		break;
	case KGAL_BLEND_DESTALPHA:
		*pAlpha = SEINFO_BITBLT_ALPHA_DEST;
		*pRGB = SEINFO_DFB_BLEND_ALPHA_DEST;
		break;
	case KGAL_BLEND_INVDESTALPHA:
		*pAlpha = SEINFO_BITBLT_ALPHA_1_DEST;
		*pRGB = SEINFO_DFB_BLEND_ALPHA_1_DEST;
		break;
	case KGAL_BLEND_DESTCOLOR:
		*pAlpha = SEINFO_BITBLT_ALPHA_DEST;
		*pRGB = SEINFO_DFB_BLEND_RGB_DEST;
		break;
	case KGAL_BLEND_INVDESTCOLOR:
		*pAlpha = SEINFO_BITBLT_ALPHA_1_DEST;
		*pRGB = SEINFO_DFB_BLEND_RGB_1_DEST;
		break;
	case KGAL_BLEND_CONSTALPHA:
		*pAlpha = SEINFO_BITBLT_ALPHA_CONST;
		*pRGB = SEINFO_DFB_BLEND_CONST_1;
		break;
	default:
		return false;
	}
	return true;
}


static bool SEDFBGuard(KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings,
	SE_BLEND_EX_T* pEx,KGAL_PIXEL_FORMAT_T srcf,KGAL_PIXEL_FORMAT_T dstf) {

	if(pBlitFlags == NULL || pBlitSettings == NULL || pEx == NULL) {
		return false;
	}


	if(*pBlitFlags & KGAL_BLIT_DST_PREMULTIPLY)
		pEx->bEnableDfbDstPremultiply = true;
	if(*pBlitFlags & KGAL_BLIT_SRC_PREMULTCOLOR ||
		*pBlitFlags & KGAL_BLIT_BLEND_ALPHACHANNEL_BCM ||
		*pBlitFlags & KGAL_BLIT_BLEND_ALPHACHANNEL_COLORALPHA_BCM ||
		*pBlitFlags & KGAL_BLIT_BLEND_ALPHACHANNEL_COLORIZE_BCM) {
		pEx->bEnableDfbSrcPremulcolor = true;
		pEx->constAplhaValue = (UINT8)pBlitSettings->alpha;
	}
	if(*pBlitFlags & KGAL_BLIT_SRC_PREMULTIPLY)
		pEx->bEnableDfbSrcPremultiply = true;
	if(*pBlitFlags & KGAL_BLIT_XOR)
		pEx->bEnableDfbXor = true;

	if(*pBlitFlags & KGAL_BLIT_COLORIZE ||
		*pBlitFlags & KGAL_BLIT_BLEND_ALPHACHANNEL_COLORIZE_BCM)
		pEx->bEnableDfbColorize = true;

	if(*pBlitFlags & KGAL_BLIT_BLEND_COLORALPHA ||
		*pBlitFlags & KGAL_BLIT_BLEND_ALPHACHANNEL_COLORALPHA_BCM) {
#if 0
		/*this is real case , but ap don't want his ..*/
		pEx->bEnableDfbReplaceSrcAlphaWithConstAlpha=true;
		pEx->constAlphaValueForBlendColorAlpha = (UINT8)pBlitSettings->alpha;
#else
		/*ap want COLORALPHA and transpancy also. */
		pEx->constAplhaValue = (UINT8)pBlitSettings->alpha;
#endif
	}

	if(*pBlitFlags & KGAL_BLIT_DEMULTIPLY)
		pEx->bEnableDfbDemultiply = true;

	if(*pBlitFlags & KGAL_BLIT_BLEND_ALPHACHANNEL ||
		*pBlitFlags & KGAL_BLIT_BLEND_ALPHACHANNEL_BCM ||
		*pBlitFlags & KGAL_BLIT_BLEND_ALPHACHANNEL_COLORALPHA_BCM ||
		*pBlitFlags & KGAL_BLIT_BLEND_ALPHACHANNEL_COLORIZE_BCM) {
		pEx->bEnableDfbModulateSrcAlphaWithConstAlpha=true;
		pEx->constAplhaValue = (UINT8)pBlitSettings->alpha;
	}

	if(*pBlitFlags & KGAL_BLIT_SRC_COLORKEY) {
		pEx->colorKeySelect=SEINFO_COLORKEY_SOURCE;
		pEx->constSrcColorKeyValue = pBlitSettings->srcColorkey;
	}

	if(*pBlitFlags & KGAL_BLIT_DST_COLORKEY) {
		if(pEx->colorKeySelect)
			pEx->colorKeySelect=SEINFO_COLORKEY_BOTH;
		else
			pEx->colorKeySelect=SEINFO_COLORKEY_DESTINATION;
		pEx->constDstColorKeyValue = pBlitSettings->dstColorkey;
	}

	if(SEBLENDGuard(pBlitSettings->srcBlend, &pEx->srcAlphaModeSelect,
			&pEx->selSrcClrBlend)== false)
		return false;

	if(SEBLENDGuard(pBlitSettings->dstBlend, &pEx->destAlphaModeSelect,
			&pEx->selDestClrBlend)== false)
		return false;

	if(pBlitSettings->srcBlend == KGAL_BLEND_CONSTALPHA) {
		if(srcf == KGAL_PIXEL_FORMAT_ARGB4444)
			pEx->srcAplhaValue = (pBlitSettings->srcColorkey >>12);
		else
			pEx->srcAplhaValue = (pBlitSettings->srcColorkey >>24);
	}


	if(pBlitSettings->dstBlend == KGAL_BLEND_CONSTALPHA) {
		if(dstf == KGAL_PIXEL_FORMAT_ARGB4444)
			pEx->destAplhaValue = (pBlitSettings->dstColorkey >>12);
		else
			pEx->destAplhaValue = (pBlitSettings->dstColorkey >>24);
	}

	if(*pBlitFlags & KGAL_BLIT_OUTPUT_ALPHA_CONST) {
		pEx->outputAlphaModeSelect = SEINFO_OUTPUT_ALPHA_CONST;
		pEx->destAplhaValue = (UINT8)pBlitSettings->alpha;
	}


	return true;
}


static bool SEDFBDrawGuard(KGAL_DRAW_FLAGS_T* pDrawFlags,
	KGAL_DRAW_SETTINGS_T* pDrawSettings,SE_BLEND_EX_T* pEx) {

	if(pDrawFlags == NULL || pDrawSettings == NULL || pEx == NULL) {
		return false;
	}

	if(*pDrawFlags & KGAL_DRAW_DST_PREMULTIPLY)
		pEx->bEnableDfbDstPremultiply = true;

	if(*pDrawFlags & KGAL_DRAW_SRC_PREMULTIPLY)
		pEx->bEnableDfbSrcPremultiply = true;

	if(*pDrawFlags & KGAL_DRAW_XOR)
		pEx->bEnableDfbXor = true;

	if(*pDrawFlags & KGAL_DRAW_DEMULTIPLY)
		pEx->bEnableDfbDemultiply = true;


	if(*pDrawFlags & KGAL_DRAW_DST_COLORKEY) {
		pEx->colorKeySelect=SEINFO_COLORKEY_DESTINATION;
		pEx->constDstColorKeyValue = pDrawSettings->dstColorkey;
	}

	if (SEBLENDGuard(pDrawSettings->srcBlend, &pEx->srcAlphaModeSelect , &pEx->selSrcClrBlend)== false)
		return false;

	if (SEBLENDGuard(pDrawSettings->dstBlend, &pEx->destAlphaModeSelect , &pEx->selDestClrBlend)== false)
		return false;

	return true;
};


#if SE_OLD
static bool SEDrawDispatch(KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pDstRect,
        UINT32 color, KGAL_DRAW_FLAGS_T* pDrawFlags, KGAL_DRAW_SETTINGS_T* pDrawSettings)
{
	SE_BLEND_EX_T stEx;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_CONST;
	SE_PROCINFO_T  stSrcProcInfo, stDesProcInfo;

	memset(&stEx, 0x00, sizeof(SE_BLEND_EX_T));
	memset( &stSrcProcInfo, 0, sizeof(stSrcProcInfo));
	memset( &stDesProcInfo, 0, sizeof(stDesProcInfo));

	if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8
		&& *pDrawFlags != KGAL_DRAW_NOFX) {
		return false;
	}
	if(SEDFBDrawGuard(pDrawFlags, pDrawSettings ,&stEx) == false)
		return false;
	if(SEBoundaryGuard(pDstSurface, pDstRect) == false)
		return false;
	if(*pDrawFlags != KGAL_DRAW_NOFX)
		stMode = SEINFO_BITBLT_SETUP_MANUAL;
	if(SEFormatGuard(pDstSurface, stMode, &stEx.stcolorfmt, false) == false)
		return false;

	stEx.constColorValue = color;

	stSrcProcInfo.wDataX = pDstRect->x;
	stSrcProcInfo.wDataY = pDstRect->y;
	stSrcProcInfo.wDataWidth = pDstRect->w;
	stSrcProcInfo.wDataHeight = pDstRect->h;
	stSrcProcInfo.byBaseAddressIndex = 0;
	stSrcProcInfo.uAddr = pDstSurface->physicalAddress;
	stSrcProcInfo.uPitch = pDstSurface->pitch;

	stDesProcInfo.wDataX = pDstRect->x;
	stDesProcInfo.wDataY = pDstRect->y;
	stDesProcInfo.wDataWidth = pDstRect->w;
	stDesProcInfo.wDataHeight = pDstRect->h;
	stDesProcInfo.byBaseAddressIndex = 0;
	stDesProcInfo.uAddr = pDstSurface->physicalAddress;
	stDesProcInfo.uPitch = pDstSurface->pitch;

	inner_flush_surface(pDstSurface);
	if(*pDrawFlags == KGAL_DRAW_NOFX) {
		stEx.srcAlphaModeSelect = SEINFO_BITBLT_ALPHA_DISABLE;
		stEx.destAlphaModeSelect = SEINFO_BITBLT_ALPHA_DISABLE;

		SE_BitBltEx(&stDesProcInfo,&stSrcProcInfo,
			SEINFO_OUTPUT_ALPHA_NORMAL, 0,
			stMode, SEINFO_BITBLT_CORNER_NONE,
			SEINFO_ROPCODE_COPY,(void*)&stEx , 0);

		inner_wait_done();
		return true;

	}else if(*pDrawFlags & KGAL_DRAW_BLEND) {

		stMode = SEINFO_BITBLT_SETUP_CONST;
		stDesProcInfo.byBaseAddressIndex = 1;
		stDesProcInfo.uAddr = pDstSurface->physicalAddress;
		stDesProcInfo.uPitch = pDstSurface->pitch;

		stEx.bEnableWithBitblit=true; //fake
		stEx.bEnableDirectFB=true;

		SE_BitBltEx(&stDesProcInfo,&stSrcProcInfo,
			SEINFO_OUTPUT_ALPHA_NORMAL, 0,
			stMode, SEINFO_BITBLT_CORNER_NONE,
			SEINFO_ROPCODE_COPY,(void*)&stEx , 0);
		inner_wait_done();
		return true;
	}else{
		return false;
	}

	return false;

};
#endif

#if SE_SE20
bool inner_fbc_Blit(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_RECT_T* pSrcRect,
	KGAL_SURFACE_INFO_T* pDstSurface, UINT16 dx, UINT16 dy,
	KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings)
{
	SE_PROCINFO_T  stSrcProcInfo,stDstProcInfo;
	SE_EXT_FMT_CONV_T stExFmt;
	SE_BLEND_EX_T stEx;
	KGAL_SURFACE_INFO_T* pfSrcSurface = pSrcSurface;
	KGAL_SURFACE_INFO_T* pfDstSurface = pDstSurface;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_MANUAL;

	memset( &stSrcProcInfo, 0, sizeof(stSrcProcInfo));
	memset( &stDstProcInfo, 0, sizeof(stDstProcInfo));
	memset(&stExFmt, 0x00, sizeof(SE_EXT_FMT_CONV_T));
	memset(&stEx, 0x00, sizeof(SE_BLEND_EX_T));

	if(SEFormatGuard(pSrcSurface, stMode, &stEx.stcolorfmt,true) == false)
		return false;

	if(SEDFBGuard(pBlitFlags, pBlitSettings ,&stExFmt.st_blend_layer0,pSrcSurface->pixelFormat,pDstSurface->pixelFormat) == false)
		return false;

	if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8
		&& *pBlitFlags != KGAL_BLIT_NOFX) {
		return false;
	}

/*
	baker, RHAL will call set palette, don't need to add this
	if(pfSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {

		if(inner_update_se_clut(pSrcSurface) == false)
			return false;

	}
*/

	if(inner_set_pinfo(pfSrcSurface, &stSrcProcInfo, pSrcRect, 0) == false)
		return false;
	if(inner_set_pinfo(pfDstSurface, &stDstProcInfo, pSrcRect, 1) == false)
		return false;


	stDstProcInfo.wDataX = dx;
	stDstProcInfo.wDataY = dy;

	stExFmt.src1_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
	stExFmt.src2_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;

	if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.src1_format ) == false)
		return false;
	if(inner_ext_fmt_check(&pfSrcSurface->pixelFormat, &stExFmt.src2_format ) == false)
		return false;
	if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.result_format ) == false)
		return false;


	if(*pBlitFlags != KGAL_BLIT_NOFX) {
		stExFmt.st_blend_layer0.ropMode = SEINFO_ALPHA_BLENDING;
		stExFmt.st_blend_layer0.bEnableWithBitblit= true;
	}

	if(SE_EXT_FormatConversion(&stDstProcInfo, &stSrcProcInfo, (void*)&stExFmt) == false) {
		return false;
	}


	inner_wait_done();

	return true;
}
#endif


bool KGAL_Blit(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface, UINT16 dx, UINT16 dy, KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings)
{
	KGAL_SURFACE_INFO_T* pfSrcSurface = pSrcSurface;
	KGAL_RECT_T stTarget;

	SE_PROCINFO_T  stSrcProcInfo,stDstProcInfo;
	SE_EXT_FMT_CONV_T stExFmt;
	SE_BLEND_EX_T stEx;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_MANUAL;
#if SE_SE20 || SE_OLD
	KGAL_SURFACE_INFO_T tdmySurface;
#endif
	memset( &stSrcProcInfo, 0, sizeof(stSrcProcInfo));
	memset( &stDstProcInfo, 0, sizeof(stDstProcInfo));
	memset(&stExFmt, 0x00, sizeof(SE_EXT_FMT_CONV_T));
	memset(&stEx, 0x00, sizeof(SE_BLEND_EX_T));

	if(*pBlitFlags & _strmBlitFg) {
		if(pfSrcSurface->pixelFormat != KGAL_PIXEL_FORMAT_ARGB  ||
			pDstSurface->pixelFormat != KGAL_PIXEL_FORMAT_ARGB)
			return false;
	}

#if SE_SE20 || SE_OLD
	if(*pBlitFlags & (KGAL_BLIT_ROTATE90|KGAL_BLIT_ROTATE180|KGAL_BLIT_ROTATE270))
		return inner_rotate(pSrcSurface, pSrcRect, pDstSurface, dx, dy, pBlitFlags, pBlitSettings);

	if(*pBlitFlags & (KGAL_BLIT_VERTICAL_MIRROR|KGAL_BLIT_HORIZONTAL_MIRROR))
		return inner_mirror(pSrcSurface, pSrcRect, pDstSurface, dx, dy, pBlitFlags, pBlitSettings);
#else
	if(*pBlitFlags & _strmBlitFg)
		return inner_fast_cpy_conv(pfSrcSurface, pSrcRect, pDstSurface, dx, dy, pBlitFlags, pBlitSettings);
#endif
	if(SEBoundaryGuard(pSrcSurface, pSrcRect) == false)
		return false;

	if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8
		&& *pBlitFlags != KGAL_BLIT_NOFX) {
		return false;
	}

	stTarget.x = dx;
	stTarget.y = dy;
	stTarget.w = pSrcRect->w;
	stTarget.h = pSrcRect->h;

	if(SEBoundaryGuard(pDstSurface, &stTarget) == false)
		return false;
	if(SEFormatGuard(pSrcSurface, stMode, &stEx.stcolorfmt,true) == false)
		return false;
	if(SEDFBGuard(pBlitFlags, pBlitSettings ,&stEx,pSrcSurface->pixelFormat,pDstSurface->pixelFormat) == false)
		return false;
#if SE_SE20
	if(*pBlitFlags != KGAL_BLIT_NOFX &&
		(pSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_FBC || pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_FBC))
		return inner_fbc_Blit(pSrcSurface, pSrcRect, pDstSurface, dx, dy, pBlitFlags, pBlitSettings);
#else
	if(pSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_FBC || pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_FBC)
		return false;
#endif
	//===============================================set palette
	if(pSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {
		if(*pBlitFlags == KGAL_BLIT_NOFX
			&& pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {
#if SE_OLD
				return KGAL_FormatConv(pfSrcSurface, pSrcRect, pDstSurface, dx, dy, pBlitFlags, pBlitSettings);
#else
				return inner_fast_cpy_conv(pfSrcSurface, pSrcRect, pDstSurface, dx, dy, pBlitFlags, pBlitSettings);
#endif
		}

#if SE_SE20 || SE_OLD
		if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB) {
			if(inner_lut82argb(pfSrcSurface, &tdmySurface, pSrcRect) == false)
				return false;
			pfSrcSurface = &tdmySurface;
		}else{
			return false;
		}
#else
		/*
		baker, RHAL will call set palette, don't need to add this
		if(inner_update_se_clut(pSrcSurface) == false)
			return false;
		*/
#endif
	}

	if(*pBlitFlags == KGAL_BLIT_NOFX && pfSrcSurface->pixelFormat == pDstSurface->pixelFormat ) {
#if SE_SE20 || SE_SE20_EXT
		return inner_fast_cpy_conv(pfSrcSurface, pSrcRect, pDstSurface, dx, dy, pBlitFlags, pBlitSettings);
#else
		return KGAL_FormatConv(pfSrcSurface, pSrcRect, pDstSurface, dx, dy, pBlitFlags, pBlitSettings);
#endif
	}

#if SE_OLD
	if(pfSrcSurface->pixelFormat != pDstSurface->pixelFormat) {
		if(inner_srcfmtconv(pSrcSurface, pDstSurface, &tdmySurface, pSrcRect) == false) {
			return false;
		}
		pfSrcSurface = &tdmySurface;
	}
#endif

#if SE_SE20 || SE_SE20_EXT
	if(SEFormatGuard(pSrcSurface, stMode, &stExFmt.st_blend_layer0.stcolorfmt, true) == false)
		return false;
#else
	if(SEFormatGuard(pDstSurface, stMode, &stEx.stcolorfmt, true) == false)
		return false;
	if(pSrcSurface->physicalAddress == 0xffffffff) {
		stMode = SEINFO_BITBLT_SETUP_CONST;
		stEx.constColorValue = (pBlitSettings->color&0xff000000) >> 24 |
			(pBlitSettings->color&0xff0000) >> 8 |
			(pBlitSettings->color&0xff00) << 8 |
			(pBlitSettings->color&0xff) << 24 ;
	}else{
		stEx.constColorValue = pBlitSettings->color;
	}
#endif


	if(inner_set_pinfo(pfSrcSurface, &stSrcProcInfo, pSrcRect, 0) == false)
		return false;
	if(inner_set_pinfo(pDstSurface, &stDstProcInfo, pSrcRect, 1) == false)
		return false;

	stDstProcInfo.wDataX = stTarget.x;
	stDstProcInfo.wDataY = stTarget.y;

	stEx.bEnableWithBitblit=true; //dummy
	stEx.bEnableDirectFB=true;

	inner_flush_surface(pSrcSurface);
	inner_flush_surface(pDstSurface);


#if SE_SE20 || SE_SE20_EXT
	memcpy(&stExFmt.st_blend_layer0, &stEx, sizeof(SE_BLEND_EX_T));
	stExFmt.st_blend_layer0.ropMode = SEINFO_ALPHA_BLENDING;
	stExFmt.st_blend_layer0.bEnableWithBitblit= true;

	stExFmt.src1_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
	stExFmt.src2_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
	if(pfSrcSurface->physicalAddress == 0xffffffff) {
		stExFmt.src2_select = SEINFO_BITBLT_EXT_SELECT_CONST;
		stExFmt.st_blend_layer0.constColorValue = pBlitSettings->color;
	}

	if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.src1_format ) == false)
		return false;
	if(inner_ext_fmt_check(&pfSrcSurface->pixelFormat, &stExFmt.src2_format ) == false)
		return false;
	if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.result_format ) == false)
		return false;

	if(pfSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_NV12 || pfSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_NV16){
		stSrcProcInfo.uPitch = pfSrcSurface->width;
		stSrcProcInfo.uAddr_c1 = pfSrcSurface->physicalAddress + pfSrcSurface->width*pDstSurface->height;
		stSrcProcInfo.uPitch_c1 = pfSrcSurface->width/2;
		stSrcProcInfo.byChronmaAddressIndex = 3;
	}

	if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_NV12 || pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_NV16){
		stDstProcInfo.uPitch = pDstSurface->width;
		stDstProcInfo.uAddr_c1 = pDstSurface->physicalAddress + pDstSurface->width*pDstSurface->height;
		stDstProcInfo.uPitch_c1 = pDstSurface->width/2;
		stDstProcInfo.byChronmaAddressIndex = 4;
	}

	SE_EXT_FormatConversion(&stDstProcInfo, &stSrcProcInfo,
		(void*)&stExFmt);
	inner_wait_done();
#else
	SE_BitBltEx(&stDstProcInfo, &stSrcProcInfo,
		SEINFO_OUTPUT_ALPHA_NORMAL, 0,
		stMode, SEINFO_BITBLT_CORNER_NONE,
		SEINFO_ROPCODE_COPY, (void*)&stEx, 0);
#endif
	inner_wait_done();


	return true;
}

#if SE_SE20
bool inner_argb_fbc_stchblit(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pDstRect, KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings)
{

	KGAL_SURFACE_INFO_T* pfDstSurface = pDstSurface;
	SEINFO_SACLING_TYPE stVType = SEINFO_SCALING_DISABLE;
	SEINFO_SACLING_TYPE stHType = SEINFO_SCALING_DISABLE;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_MANUAL;
	SE_PROCINFO_T  stSrcProcInfo,stDstProcInfo;
	UINT32 u32VFactor=0, u32HFactor=0;
	SE_EXT_FMT_CONV_T stExFmt;

	memset(&stExFmt, 0x00, sizeof(SE_EXT_FMT_CONV_T));
	memset(&stSrcProcInfo, 0x00, sizeof(SE_PROCINFO_T));
	memset(&stDstProcInfo, 0x00, sizeof(SE_PROCINFO_T));

	if(pSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {
		return false;
	}

	//base on dest
	if(SEFormatGuard(pDstSurface, stMode, &stExFmt.st_blend_layer0.stcolorfmt, true) == false)
		return false;

	if(SEDFBGuard(pBlitFlags, pBlitSettings ,&stExFmt.st_blend_layer0,pSrcSurface->pixelFormat,pDstSurface->pixelFormat) == false)
		return false;

	if(SEStretchFactorGuard(pSrcRect, pDstRect, &stHType, &u32HFactor, &stVType, &u32VFactor) == false)
		return false;

	if(inner_set_pinfo(pSrcSurface, &stSrcProcInfo, pSrcRect, 0) == false)
		return false;

	if(inner_set_pinfo(pfDstSurface, &stDstProcInfo, pDstRect, 1) == false)
		return false;

	stExFmt.src1_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
	stExFmt.src2_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
	stExFmt.st_blend_layer0.ropMode = SEINFO_ALPHA_BLENDING;

	if(*pBlitFlags != KGAL_BLIT_NOFX) {
		stExFmt.st_blend_layer0.bEnableWithBitblit=true;
		stExFmt.st_blend_layer0.bEnableDirectFB=true;
	}else{
		stExFmt.st_blend_layer0.bEnableWithBitblit=false;
		stExFmt.st_blend_layer0.bEnableDirectFB=false;
		stExFmt.st_blend_layer0.srcAlphaModeSelect = SEINFO_BITBLT_ALPHA_DISABLE;
		stExFmt.st_blend_layer0.destAlphaModeSelect = SEINFO_BITBLT_ALPHA_DISABLE;
	}


	if(inner_ext_fmt_check(&pSrcSurface->pixelFormat, &stExFmt.src1_format ) == false)
		return false;
	if(inner_ext_fmt_check(&pSrcSurface->pixelFormat, &stExFmt.src2_format ) == false)
		return false;
	if(inner_ext_fmt_check(&pfDstSurface->pixelFormat, &stExFmt.result_format ) == false)
		return false;

	inner_flush_surface(pSrcSurface);
	inner_flush_surface(pDstSurface);

	inner_wait_done();
	SE_Stretch_ext(&stDstProcInfo, &stSrcProcInfo,
			stVType, u32VFactor, SEINFO_VSCALING_2TAP,
			stHType, u32HFactor, SEINFO_HSCALING_2TAP,
			SEINFO_STRETCH_FIR, SEINFO_ALPHAPROC_DISABLE, 0, (void*)&stExFmt);

	inner_wait_done();

	return true;
}

bool inner_fbc_stchblit(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pDstRect, KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings)
{
	SEINFO_SACLING_TYPE stVType = SEINFO_SCALING_DISABLE;
	SEINFO_SACLING_TYPE stHType = SEINFO_SCALING_DISABLE;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_MANUAL;
	KGAL_SURFACE_INFO_T* pfSrcSurface = pSrcSurface;
	SE_PROCINFO_T  stSrcProcInfo,stDstProcInfo;
	UINT32 u32VFactor=0, u32HFactor=0;
	SE_EXT_FMT_CONV_T stExFmt;

	if(pfSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {
		return false;
	}


	memset(&stExFmt, 0x00, sizeof(SE_EXT_FMT_CONV_T));
	memset(&stSrcProcInfo, 0x00, sizeof(SE_PROCINFO_T));
	memset(&stDstProcInfo, 0x00, sizeof(SE_PROCINFO_T));

	//base on dest
	if(SEFormatGuard(pDstSurface, stMode, &stExFmt.st_blend_layer0.stcolorfmt, true) == false)
		return false;

	if(SEDFBGuard(pBlitFlags, pBlitSettings ,&stExFmt.st_blend_layer0,pSrcSurface->pixelFormat,pDstSurface->pixelFormat) == false)
		return false;

	if(SEStretchFactorGuard(pSrcRect, pDstRect, &stHType, &u32HFactor, &stVType, &u32VFactor) == false)
		return false;

	if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {
		return false;
	}

	if(inner_stretch_check(pSrcRect, pDstRect) == false) {
		return false;
	}

	if(inner_set_pinfo(pfSrcSurface, &stSrcProcInfo, pSrcRect, 0) == false)
		return false;

	if(inner_set_pinfo(pDstSurface, &stDstProcInfo, pDstRect, 1) == false)
		return false;

	stExFmt.src1_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
	stExFmt.src2_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
	stExFmt.st_blend_layer0.bEnableWithBitblit=true; //fake
	stExFmt.st_blend_layer0.bEnableDirectFB=true;
	stExFmt.st_blend_layer0.ropMode = SEINFO_ALPHA_BLENDING;

	inner_flush_surface(pSrcSurface);
	inner_flush_surface(pDstSurface);

	if(*pBlitFlags == KGAL_BLIT_NOFX) {
		stExFmt.st_blend_layer0.bEnableWithBitblit=false;
		stExFmt.st_blend_layer0.bEnableDirectFB=false;
		stExFmt.st_blend_layer0.srcAlphaModeSelect = SEINFO_BITBLT_ALPHA_DISABLE;
		stExFmt.st_blend_layer0.destAlphaModeSelect = SEINFO_BITBLT_ALPHA_DISABLE;
	}

	if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.src1_format ) == false)
		return false;
	if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.result_format ) == false)
		return false;
	if(inner_ext_fmt_check(&pfSrcSurface->pixelFormat, &stExFmt.src2_format ) == false)
		return false;

	SE_Stretch_ext(&stDstProcInfo, &stSrcProcInfo,
			stVType, u32VFactor, SEINFO_VSCALING_2TAP,
			stHType, u32HFactor, SEINFO_HSCALING_2TAP,
			SEINFO_STRETCH_FIR, SEINFO_ALPHAPROC_DISABLE, 0, (void*)&stExFmt);
	inner_wait_done();
	return true;
}
#endif
bool KGAL_StretchBlit(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pDstRect, KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings)
{
	SEINFO_SACLING_TYPE stVType = SEINFO_SCALING_DISABLE;
	SEINFO_SACLING_TYPE stHType = SEINFO_SCALING_DISABLE;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_MANUAL;
	SE_PROCINFO_T  stSrcProcInfo,stDstProcInfo;
	SE_BLEND_EX_T stEx;
	UINT32 u32VFactor=0, u32HFactor=0;
	SEINFO_STRETCH_HTAP byHTap = SEINFO_HSCALING_2TAP;
	SEINFO_STRETCH_VTAP byVTap = SEINFO_VSCALING_2TAP;
	KGAL_SURFACE_INFO_T* pfSrcSurface = pSrcSurface;
#if SE_SE20 || SE_OLD
	KGAL_SURFACE_INFO_T tdmySurface;
#endif
	KGAL_RECT_T fbcDstRect;
	memset(&fbcDstRect, 0x00, sizeof(KGAL_RECT_T));
	memset(&stSrcProcInfo, 0x00, sizeof(SE_PROCINFO_T));
	memset(&stDstProcInfo, 0x00, sizeof(SE_PROCINFO_T));
	memset(&stEx, 0x00, sizeof(SE_BLEND_EX_T));

	if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8 && *pBlitFlags != KGAL_BLIT_NOFX) {
		return false;
	}

	if(SEBoundaryGuard(pSrcSurface, pSrcRect) == false)
		return false;

	if(SEBoundaryGuard(pDstSurface, pDstRect) == false)
		return false;

	if(SEDFBGuard(pBlitFlags, pBlitSettings ,&stEx,pSrcSurface->pixelFormat,pDstSurface->pixelFormat) == false)
		return false;

	//===============================================set palette
	if(pSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_LUT8) {
#if SE_SE20 || SE_OLD
		if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB) {
			if(inner_lut82argb(pfSrcSurface, &tdmySurface, pSrcRect) == false)
				return false;
			pfSrcSurface = &tdmySurface;
		}else{
			return false;
		}
#else
		/*
		baker, RHAL will call set palette, don't need to add this
		if(inner_update_se_clut(pSrcSurface) == false)
			return false;
		*/
#endif
	}else{
#if SE_OLD
		if(pSrcSurface->pixelFormat != pDstSurface->pixelFormat) {
			KGAL_BLIT_FLAGS_T tflags = KGAL_BLIT_NOFX;
			if(inner_check_I8addr() == false)
				return false;
			tdmySurface.width = pSrcSurface->width;
			tdmySurface.height = pSrcSurface->height;
			tdmySurface.physicalAddress = g_st_tmp_surf.physicalAddress;
			tdmySurface.pitch = pDstSurface->pitch;
			tdmySurface.pixelFormat = pDstSurface->pixelFormat;
			tdmySurface.bpp = pDstSurface->bpp;
			if(KGAL_FormatConv(pfSrcSurface, pSrcRect, &tdmySurface, pSrcRect->x, pSrcRect->y, &tflags, pBlitSettings) ==false) {
				return false;
			}
			pfSrcSurface = &tdmySurface;
		}
#endif
	}

	if(pfSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_FBC || pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_FBC) {
#if SE_SE20
		if(inner_stretch_check(pSrcRect, pDstRect) == false) {
			memcpy(&fbcDstRect, pDstRect, sizeof(KGAL_RECT_T));

			if((pDstRect->x+pDstRect->w)%16<=2) {
				fbcDstRect.w+=2;
				if(inner_stretch_check(pSrcRect, &fbcDstRect) == false) {
					return false;
				}
				if(pfSrcSurface->pixelFormat != pDstSurface->pixelFormat) {
					return inner_argb_fbc_stchblit(pfSrcSurface, pSrcRect, pDstSurface, &fbcDstRect, pBlitFlags, pBlitSettings);
				}else{
					return inner_fbc_stchblit(pSrcSurface, pSrcRect, pDstSurface, &fbcDstRect, pBlitFlags, pBlitSettings);
				}
			}
			return false;
		}
		if(pfSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB && pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_FBC) {
			return inner_argb_fbc_stchblit(pfSrcSurface, pSrcRect, pDstSurface, pDstRect, pBlitFlags, pBlitSettings);
		}else if(pfSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_FBC && pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB ) {
			return inner_argb_fbc_stchblit(pfSrcSurface, pSrcRect, pDstSurface, pDstRect, pBlitFlags, pBlitSettings);
		}else{
			return inner_fbc_stchblit(pSrcSurface, pSrcRect, pDstSurface, pDstRect, pBlitFlags, pBlitSettings);
		}
#else
		return false;
#endif
	}

#if SE_OLD
	if(pfSrcSurface->pixelFormat != pDstSurface->pixelFormat) {
		if(inner_srcfmtconv(pSrcSurface, pDstSurface, &tdmySurface, pSrcRect) == false) {
			return false;
		}
		pfSrcSurface = &tdmySurface;
	}
#endif

	if(SEStretchFactorGuard(pSrcRect, pDstRect, &stHType, &u32HFactor, &stVType, &u32VFactor) == false)
		return false;
	if(SEFormatGuard(pfSrcSurface, stMode, &stEx.stcolorfmt, true) == false)
		return false;
	if(inner_set_pinfo(pfSrcSurface, &stSrcProcInfo, pSrcRect, 0) == false)
		return false;
	if(inner_set_pinfo(pDstSurface, &stDstProcInfo, pDstRect, 1) == false)
		return false;

	inner_flush_surface(pSrcSurface);
	inner_flush_surface(pDstSurface);

	stEx.bEnableWithBitblit=true; //fake
	stEx.bEnableDirectFB=true;

	if(*pBlitFlags == KGAL_BLIT_NOFX ) {
		stEx.bEnableWithBitblit=false;
		stEx.bEnableDirectFB=false;
		stEx.srcAlphaModeSelect = SEINFO_BITBLT_ALPHA_DISABLE;
		stEx.destAlphaModeSelect = SEINFO_BITBLT_ALPHA_DISABLE;
	}

#if SE_SE20_EXT || SE_SE20
	if(inner_stretch_check(pSrcRect, pDstRect) == true) {

		SE_EXT_FMT_CONV_T stExFmt;
		memset(&stExFmt, 0x00, sizeof(SE_EXT_FMT_CONV_T));

		if(SEDFBGuard(pBlitFlags, pBlitSettings ,&stExFmt.st_blend_layer0,pSrcSurface->pixelFormat,pDstSurface->pixelFormat) == false)
			return false;

		stExFmt.st_blend_layer0.ropMode = SEINFO_ALPHA_BLENDING;
		stExFmt.st_blend_layer0.bEnableWithBitblit = stEx.bEnableWithBitblit;

		stExFmt.src1_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
		stExFmt.src2_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;

		if(SEFormatGuard(pDstSurface, stMode, &stExFmt.st_blend_layer0.stcolorfmt, true) == false)
			return false;

		if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.src1_format ) == false)
			return false;
		if(inner_ext_fmt_check(&pfSrcSurface->pixelFormat, &stExFmt.src2_format ) == false)
			return false;
		if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.result_format ) == false)
			return false;

		byHTap = SEINFO_HSCALING_2TAP;
		byVTap = SEINFO_VSCALING_4TAP;

		SE_Stretch_ext(&stDstProcInfo, &stSrcProcInfo,
				stVType, u32VFactor, byVTap,
				stHType, u32HFactor, byHTap,
				SEINFO_STRETCH_FIR, SEINFO_ALPHAPROC_DISABLE, 0, (void*)&stExFmt);
	}else{
#if SE_SE20_EXT

		SE_EXT_FMT_CONV_T stExFmt;
		memset(&stExFmt, 0x00, sizeof(SE_EXT_FMT_CONV_T));

		if(SEDFBGuard(pBlitFlags, pBlitSettings ,&stExFmt.st_blend_layer0,pSrcSurface->pixelFormat,pDstSurface->pixelFormat) == false)
			return false;
		stExFmt.st_blend_layer0.ropMode = SEINFO_ALPHA_BLENDING;
		stExFmt.st_blend_layer0.bEnableWithBitblit = stEx.bEnableWithBitblit;
		stExFmt.src1_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
		stExFmt.src2_select = SEINFO_BITBLT_EXT_SELECT_MANUAL;
		if(SEFormatGuard(pDstSurface, stMode, &stExFmt.st_blend_layer0.stcolorfmt, true) == false)
			return false;
		if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.src1_format ) == false)
			return false;
		if(inner_ext_fmt_check(&pfSrcSurface->pixelFormat, &stExFmt.src2_format ) == false)
			return false;
		if(inner_ext_fmt_check(&pDstSurface->pixelFormat, &stExFmt.result_format ) == false)
			return false;
		if(stDstProcInfo.wDataX && (((stDstProcInfo.wDataX-1)%16 + stDstProcInfo.wDataWidth) == 16))
			stDstProcInfo.wDataX -=1;
		else if(stDstProcInfo.wDataX == 0 && stDstProcInfo.wDataWidth == 16)
			stDstProcInfo.wDataX +=1;
		if(stDstProcInfo.wDataY && (((stDstProcInfo.wDataY-1)%16 + stDstProcInfo.wDataHeight) == 16))
			stDstProcInfo.wDataY -=1;
		else if(stDstProcInfo.wDataY == 0 && (stDstProcInfo.wDataHeight == 16))
			stDstProcInfo.wDataY +=1;

		byHTap = SEINFO_HSCALING_2TAP;
		byVTap = SEINFO_VSCALING_4TAP;

		SE_Stretch_ext(&stDstProcInfo, &stSrcProcInfo,
				stVType, u32VFactor, byVTap,
				stHType, u32HFactor, byHTap,
				SEINFO_STRETCH_FIR, SEINFO_ALPHAPROC_DISABLE, 0, (void*)&stExFmt);
#else

		byHTap = SEINFO_HSCALING_2TAP;
		byVTap = SEINFO_VSCALING_2TAP;

		if((u32HFactor > 0x20000 || u32HFactor < 0x800)
		  || (u32VFactor > 0x20000 || u32VFactor < 0x800))
			byVTap = SEINFO_VSCALING_4TAP;

		SE_Stretch(&stDstProcInfo, &stSrcProcInfo,
				stVType, u32VFactor, byVTap,
				stHType, u32HFactor, byHTap,
				SEINFO_STRETCH_FIR, SEINFO_ALPHAPROC_DISABLE, 0, (void*)&stEx);
#endif
	}
#else

	byHTap = SEINFO_HSCALING_2TAP;
	byVTap = SEINFO_VSCALING_2TAP;

	if((u32HFactor > 0x20000 || u32HFactor < 0x800)
	  || (u32VFactor > 0x20000 || u32VFactor < 0x800))
		byVTap = SEINFO_VSCALING_4TAP;

	SE_Stretch(&stDstProcInfo, &stSrcProcInfo,
			stVType, u32VFactor, byVTap,
			stHType, u32HFactor, byHTap,
			//SEINFO_STRETCH_REPEAT_DROP, SEINFO_ALPHAPROC_DISABLE, 0, (void*)&stEx);
			SEINFO_STRETCH_FIR, SEINFO_ALPHAPROC_DISABLE, 0, (void*)&stEx);
#endif
	inner_wait_done();
	return true;
}
bool KGAL_FillRectangle(KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pDstRect, UINT32 color, KGAL_DRAW_FLAGS_T* pDrawFlags, KGAL_DRAW_SETTINGS_T* pDrawSettings)
{
#if SE_SE20_EXT || SE_SE20
	return inner_fast_fill(pDstSurface, pDstRect, color, pDrawFlags, pDrawSettings);
#else
	return SEDrawDispatch(pDstSurface, pDstRect, color, pDrawFlags, pDrawSettings);
#endif
}
bool KGAL_DrawRectangle(KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pDstRect, UINT32 color, KGAL_DRAW_FLAGS_T* pDrawFlags, KGAL_DRAW_SETTINGS_T* pDrawSettings)
{
	UINT32 u32Degree =1;
	KGAL_RECT_T stRect;

	//baker, check the whole range in the first time, the below function will check the partial line.
	//if the degree is big enough(maybe more than 30?!), we need to think about the overlap range in the future...
	if(SEBoundaryGuard(pDstSurface, pDstRect) == false)
		return false;
	stRect.x = pDstRect->x;
	stRect.y = pDstRect->y;
	stRect.w = pDstRect->w;
	stRect.h = u32Degree;

#if SE_SE20_EXT || SE_SE20
	if(inner_fast_fill(pDstSurface, &stRect, color, pDrawFlags, pDrawSettings) != true)
#else
	if(SEDrawDispatch(pDstSurface, &stRect, color, pDrawFlags, pDrawSettings) != true)
#endif
		return false;
	stRect.w = u32Degree;
	stRect.h = pDstRect->h;
#if SE_SE20_EXT || SE_SE20
	if(inner_fast_fill(pDstSurface, &stRect, color, pDrawFlags, pDrawSettings) != true)
#else
	if(SEDrawDispatch(pDstSurface, &stRect, color, pDrawFlags, pDrawSettings) != true)
#endif
		return false;
	if(pDstRect->w > u32Degree) {
		stRect.x = pDstRect->x + pDstRect->w - u32Degree;
		stRect.y = pDstRect->y;
		stRect.w = u32Degree;
		stRect.h = pDstRect->h;
#if SE_SE20_EXT || SE_SE20
		if(inner_fast_fill(pDstSurface, &stRect, color, pDrawFlags, pDrawSettings) != true)
#else
		if(SEDrawDispatch(pDstSurface, &stRect, color, pDrawFlags, pDrawSettings) != true)
#endif
			return false;
	}
	if(pDstRect->h > u32Degree) {
		stRect.x = pDstRect->x;
		stRect.y = pDstRect->y + pDstRect->h - u32Degree;
		stRect.w = pDstRect->w;
		stRect.h = u32Degree;
#if SE_SE20_EXT || SE_SE20
		if(inner_fast_fill(pDstSurface, &stRect, color, pDrawFlags, pDrawSettings) != true)
#else
		if(SEDrawDispatch(pDstSurface, &stRect, color, pDrawFlags, pDrawSettings) != true)
#endif
			return false;
	}
	return true;
}
bool KGAL_DrawLine(KGAL_SURFACE_INFO_T* pDSurface, KGAL_LINE_T* pDstLine, UINT32 color, KGAL_DRAW_FLAGS_T* pDrawFlags, KGAL_DRAW_SETTINGS_T* pDrawSettings)
{

	KGAL_RECT_T DstRect;

	if(pDstLine == NULL || pDrawFlags == NULL || pDrawSettings == NULL) {
		return false;
	}

	if(pDstLine->x1 > pDstLine->x2 || pDstLine->y1 > pDstLine->y2 ||
		(pDstLine->x2 != pDstLine->x1 && pDstLine->y2 != pDstLine->y1)) {
		return false;
	}

	DstRect.x = pDstLine->x1;
	DstRect.y = pDstLine->y1;
	if(pDstLine->x2 == pDstLine->x1)
		DstRect.w = 1;
	else
		DstRect.w = pDstLine->x2 - pDstLine->x1;

	if(pDstLine->y2 == pDstLine->y1)
		DstRect.h = 1;
	else
		DstRect.h = pDstLine->y2 - pDstLine->y1;

#if SE_SE20_EXT || SE_SE20
	return inner_fast_fill(pDSurface, &DstRect, color, pDrawFlags, pDrawSettings);
#else
	return SEDrawDispatch(pDSurface, &DstRect, color, pDrawFlags, pDrawSettings);
#endif

}

bool KGAL_SyncGraphic(void)
{
#if defined(SE_WAIT_DONE)
	if(SE_WaitCmdDone(400, 0))
		return true;
	else
		return false;
#endif
	return true;
}

bool KGAL_FormatConv(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_RECT_T* pSrcRect,
	KGAL_SURFACE_INFO_T* pDstSurface, UINT16 dx, UINT16 dy,
	KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings)
{
	SEINFO_CONVERSION	stConvType;
	SEINFO_DEST_FORMAT  stConvDestFormat;
	SEINFO_SRC_FORMAT   stConvSrcFormat;
	SE_BLEND_EX_T stEx;
	KGAL_RECT_T stTarget;
	SE_PROCINFO_T  stSrcProcInfo,stDesProcInfo;
	SEINFO_SETUPMODE stMode = SEINFO_BITBLT_SETUP_MANUAL;

	memset( &stSrcProcInfo, 0, sizeof(stSrcProcInfo));
	memset( &stDesProcInfo, 0, sizeof(stDesProcInfo));
	memset(&stEx, 0x00, sizeof(SE_BLEND_EX_T));

	if(SEBoundaryGuard(pSrcSurface, pSrcRect) == false)
		return false;

	stTarget.x = dx;
	stTarget.y = dy;
	stTarget.w = pSrcRect->w;
	stTarget.h = pSrcRect->h;

	if(SEBoundaryGuard(pDstSurface, &stTarget) == false)
		return false;

	if(SEDFBGuard(pBlitFlags, pBlitSettings ,&stEx,pSrcSurface->pixelFormat,pDstSurface->pixelFormat) == false)
		return false;

	if(SEFormatGuard(pSrcSurface, stMode, &stEx.stcolorfmt, true) == false)
		return false;

	if(SEFormatConvGuard(pSrcSurface, pDstSurface, &stConvType, &stConvSrcFormat, &stConvDestFormat) == false)
		return false;

#if 0
	if(pSrcSurface->pixelFormat == KGAL_PIXEL_FORMAT_ARGB) {
		if(pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_RGB888 ||
			pDstSurface->pixelFormat == KGAL_PIXEL_FORMAT_RGB16) {
		/* The data is sotred as RGBA
		* left gets GBA, right gets RGB
		* stretch can't change order, so we add enable for this
		 */
		stEx.stcolorfmt.byArgbAlphaLocation = SEINFO_ARGB_ALPHA_RIGHTMOST;
		//stEx.stcolorfmt.bOutputColorFormatBigEndian = false;
		stEx.stcolorfmt.bInputSrcColorFormatBigEndian = true;
		stEx.stcolorfmt.bInputDestColorFormatBigEndian = true;
		//stEx.stcolorfmt.bInputSrcColorFormatBigEndian = true;
		}
	}
#endif

	//add coordination protection
	stSrcProcInfo.wDataX = pSrcRect->x;
	stSrcProcInfo.wDataY = pSrcRect->y;
	stSrcProcInfo.wDataWidth = pSrcRect->w;
	stSrcProcInfo.wDataHeight = pSrcRect->h;
	stSrcProcInfo.byBaseAddressIndex = 0;
	stSrcProcInfo.uAddr = pSrcSurface->physicalAddress;
	stSrcProcInfo.uPitch = pSrcSurface->pitch;

	stDesProcInfo.wDataX = dx;
	stDesProcInfo.wDataY = dy;
	stDesProcInfo.wDataWidth = pSrcRect->w;
	stDesProcInfo.wDataHeight = pSrcRect->h;
	stDesProcInfo.byBaseAddressIndex = 1;
	stDesProcInfo.uAddr = pDstSurface->physicalAddress;
	stDesProcInfo.uPitch = pDstSurface->pitch;
#if GAL_DEBUG
	printk(KERN_ERR"BAKER%s,%d, [%d,%d,%d,%d,%d,%08x,%04x] to [%d,%d,%d,%d,%d,%08x,%04x]\n",
		__func__,__LINE__,
		stSrcProcInfo.wDataX,
		stSrcProcInfo.wDataY,
		stSrcProcInfo.wDataWidth,
		stSrcProcInfo.wDataHeight,
		pSrcSurface->pixelFormat,
		stSrcProcInfo.uAddr,
		stSrcProcInfo.uPitch,
		stDesProcInfo.wDataX,
		stDesProcInfo.wDataY,
		stDesProcInfo.wDataWidth,
		stDesProcInfo.wDataHeight,
		pDstSurface->pixelFormat,
		stDesProcInfo.uAddr,
		stDesProcInfo.uPitch);
#endif
	if(*pBlitFlags == KGAL_BLIT_NOFX)
	{
		stEx.srcAlphaModeSelect = SEINFO_BITBLT_ALPHA_DISABLE;
		stEx.destAlphaModeSelect = SEINFO_BITBLT_ALPHA_DISABLE;
	} else {
		stEx.bEnableWithBitblit=true; //dummy
		stEx.bEnableDirectFB=true;
	}
	inner_flush_surface(pSrcSurface);
	inner_flush_surface(pDstSurface);

	SE_FormatConversion(&stDesProcInfo, &stSrcProcInfo,
		stConvType, stConvDestFormat, stConvSrcFormat, SEINFO_COLORKEY_NONE,
		SEINFO_OUTPUT_ALPHA_NORMAL, 0, &stEx);
	inner_wait_done();
	return true;
}

bool KGAL_SetSurfacePalette(KGAL_PALETTE_SURFACE_INFO_T *local_palette)
{
	if(local_palette == NULL) {
		return false;
	}
	if(local_palette->Surface.pixelFormat != KGAL_PIXEL_FORMAT_LUT8) {
		return false;
	}
	if(local_palette->palette.length > 256) {
		return false;
	}

	SE_WriteClut((UINT32*)&local_palette->palette.palette,
		local_palette->palette.length,
		local_palette->palette.startpale);
	return true;
}
