#ifndef __VIP_REG_DEF_H__
#define __VIP_REG_DEF_H__
#if CONFIG_FIRMWARE_IN_KERNEL
#if 0
#include "rbus/rbusColorReg.h"
#include "rbus/rbusColor_dccReg.h"
#include "rbus/rbusColor_dlctiReg.h"
#include "rbus/rbusColor_icmReg.h"
#include "rbus/rbusColor_sharpReg.h"
#include "rbus/rbusColor_mb_peakingReg.h"
#include "rbus/rbusCon_briReg.h"
/*#include "rbusDiReg.h"*/
#include "rbus/rbusDiReg.h"
#include "rbus/rbusDitherReg.h"
#include "rbus/rbusGammaReg.h"
#include "rbus/rbusHistogramReg.h"
#include "rbus/rbusNrReg.h"
#include "rbus/rbusMpegnrReg.h"
#include "rbus/rbusPeakingReg.h"
#include "rbus/rbusProfileReg.h"
#include "rbus/rbusRgb2yuvReg.h"
#include "rbus/rbusScaledownReg.h"
#include "rbus/rbusHsd_ditherReg.h"
#include "rbus/rbusScaleupReg.h"
#include "rbus/rbusYuv2rgbReg.h"
#include "rbus/rbusIedge_smoothReg.h"
//#include "rbus/rbusPpOverlayReg.h"
#include <rbus/ppoverlay_reg.h>
#include "rbus/dfilter_reg.h"
#include "rbus/rbusODReg.h"
#include "rbus/rbusOD_DMAReg.h"	/*Elsie 20131206*/
#include "rbus/rbusColor_osd_shpnrReg.h"
#include "rbus/rbusSRGBReg.h"
#include <rbus/vgip_reg.h>
#include "rbus/rbusOutputgammaReg.h"
#include "rbus/rbusInv_gammaReg.h"
#include "rbus/rbusVDPQReg.h"
#include "scalercommon/vipCommon.h"
#include "rbus/rbusIDCTIReg.h" /*JZ 20140705*/
#include "rbus/rbusColor_edge_smoothReg.h"
#include "rbus/rbusDe_ContourReg.h"
#include "rbus/rbusColorMapReg.h"
#include "rbus/rbusColor_TempReg.h"
#include "rbus/rbusColor_uvcoringReg.h"
#include "rbus/rbusC3DLUTReg.h"
#include "rbus/rbusLCReg.h"

#include "rbus/rbusBLUReg.h" /*Hawaii 20140526*/
#include "rbus/ldspi_reg.h"
#include "rbus/rbusPinmuxReg.h"
#include "rbus/dm_reg.h"/* for hdr lut table, elieli*/
#include "rbus/rbusSub_DitherReg.h"
#include "rbus/rbusMain_DitherReg.h"
#else
#include "rbus/color_reg.h"
#include "rbus/color_dcc_reg.h"
#include "rbus/color_dlcti_reg.h"
#include "rbus/color_icm_reg.h"
#include "rbus/color_sharp_reg.h"
#include "rbus/color_mb_peaking_reg.h"
#include "rbus/con_bri_reg.h"
/*#include "rbusDiReg.h"*/
#include "rbus/di_reg.h"
#include "rbus/dither_reg.h"
#include "rbus/gamma_reg.h"
#include "rbus/histogram_reg.h"
#include "rbus/nr_reg.h"
#include "rbus/mpegnr_reg.h"
#include "rbus/peaking_reg.h"
#include "rbus/profile_reg.h"
#include "rbus/rgb2yuv_reg.h"
#include "rbus/scaledown_reg.h"
#include "rbus/hsd_dither_reg.h"
#include "rbus/scaleup_reg.h"
#include "rbus/yuv2rgb_reg.h"
#include "rbus/iedge_smooth_reg.h"
//#include "rbus/rbusPpOverlayReg.h"
#include <rbus/ppoverlay_reg.h>
#include "rbus/dfilter_reg.h"
#include "rbus/od_reg.h"
#include "rbus/od_dma_reg.h"	/*Elsie 20131206*/
//#include "rbus/rbusColor_osd_shpnrReg.h"
#include "rbus/srgb_reg.h"
#include <rbus/vgip_reg.h>
#include "rbus/outputgamma_reg.h"
#include "rbus/inv_gamma_reg.h"
#include "rbus/vdpq_reg.h"
#include "scalercommon/vipCommon.h"
#include "scalercommon/vipRPCCommon.h"
#include "rbus/idcti_reg.h" /*JZ 20140705*/
#include "rbus/color_edge_smooth_reg.h"
// 161213 henry mark @ Mac5
#if 0
#include "rbus/de_contour_reg.h"
#include "rbus/ipq_decontour_reg.h"
#include "rbus/invoutputgamma_reg.h"	/*jyyang 20160616*/
#include "rbus/two_step_uzu_reg.h" /*jyyang 20160614*/
#include "rbus/dispd_boe_rgbw_reg.h"	/*jyyang 20160624*/
#include "rbus/color_sld_reg.h"/*juwen 20160616*/
#include "rbus/d_histogram_reg.h"/*Terrence 20160701*/
#include "rbus/colormap_reg.h"
#include "rbus/color_temp_reg.h"
#include "rbus/sub_dither_reg.h"
#endif
#include "rbus/de_xcxl_reg.h"
#include "rbus/lc_reg.h"
#include "rbus/color_uvcoring_reg.h"
#include "rbus/c3dlut_reg.h"

#include "rbus/blu_reg.h" /*Hawaii 20140526*/
#include "rbus/ldspi_reg.h"
#include "rbus/pinmux_lvdsphy_reg.h"
#include "rbus/dm_reg.h"/* for hdr lut table, elieli*/
#include "rbus/main_dither_reg.h"
#include "rbus/rgbw_reg.h"	/*jyyang 20160616*/
#include "rbus/lg_m_plus_reg.h"

#endif
#else
#include "rbusColorReg.h"
#include "rbusColor_dccReg.h"
#include "rbusColor_dlctiReg.h"
#include "rbusColor_icmReg.h"
#include "rbusColor_sharpReg.h"
#include "rbusColor_mb_peakingReg.h"
#include "rbusCon_briReg.h"
/*#include "rbusDiReg.h"*/
#include "rbusDiReg.h"
#include "rbusDitherReg.h"
#include "rbusGammaReg.h"
#include "rbusHistogramReg.h"
#include "rbusNrReg.h"
#include "rbusMpegnrReg.h"
#include "rbusPeakingReg.h"
#include "rbusProfileReg.h"
#include "rbusRgb2yuvReg.h"
#include "rbusScaledownReg.h"
#include "rbusHsd_ditherReg.h"
#include "rbusScaleupReg.h"
#include "rbusYuv2rgbReg.h"
#include "rbusIedge_smoothReg.h"
//#include "rbusPpOverlayReg.h"
#include "ppoverlay_reg.h"
#include "rbusDfilterReg.h"
#include "rbusODReg.h"
#include "rbusOD_DMAReg.h"
#include "rbusColor_osd_shpnrReg.h"
#include "rbusSRGBReg.h"
#include "rbusVgipReg.h"
/*#include "rbusOutput_gammaReg.h"*/
#include "rbusInv_gammaReg.h"
#include "rbusVDPQReg.h"
#include "scaler/vipCommon.h"
#include "rbusIdctiReg.h" /*JZ 20140705*/
#include "rbusColor_edge_smoothReg.h"
#include "rbusColor_TempReg.h"	/*Elsie 20150226*/
#include "rbusColor_uvcoringReg.h"	/*Chris 20150305*/
#include "rbusBLUReg.h" /*Hawaii 20140526*/
#include "rbusDe_ContourReg.h"	/*yingru 20150306*/
#include "rbusColorMapReg.h"	/*Elsie 20150317*/
#include "rbusVDTopReg.h"	/*Elsie 20150317*/
#include "rbusC3DLUTReg.h"
#include "rbusLCReg.h"
#endif

/*20101223 nick187-----------------------------------------------------*/
#if CONFIG_FIRMWARE_IN_KERNEL
/* rtd_xxx series are already defined mach/io.h*/
/*#define rtd_outl(x, y)     								IoReg_Write32(x,y)*/
/*#define rtd_inl(x)     									IoReg_Read32(x)*/
#else
#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#define rtd_inl(x)     									IoReg_Read32(x)
#endif

#define scaler_rtd_inl		rtd_inl
#define scaler_rtd_outl		rtd_outl
#define scaler_rtd_maskl	rtd_maskl

/*20101224 nick187 , temporarily add def. below for compiler (should be modified after video CPU is ready)------------*/
/**
 * GDE Buffer for Device Driver
 */
typedef short                       INT16;



typedef struct _SCALERDRV_BUFFERINFO {
		unsigned int	phyAddr;			/* return physical addr to display lib*/
		unsigned int	memSize;			/* memory size*/
		unsigned int	offset;				/* offset of vma*/
		unsigned int	flag;				/* 0: first memory, 1: Second memory*/
} SCALERDRV_BUFFERINFO;

/*#ifdef ENABLE_DCR*/
/**
 * DCR Table
 */
typedef struct _SCALERDRV_DCRTABLE {
		unsigned char DCR_TABLE[5][5];	/* DCR table*/
} SCALERDRV_DCRTABLE;
/*#endif*/

/*#ifdef VIP_AUTOMA_OVER_AP*/
#define New_DCR_TABLE_NUM    3
#define DCR_TABLE_ROW_NUM    6
#define DCR_TABLE_COL_NUM    5
#define DCT_TABLE_NUM    5
typedef struct _ISR_SCALERDRV_DCRTABLE {
		unsigned char nTPV_New_DCR;
		unsigned char nDCRDefault;
		unsigned char DCR_Table[New_DCR_TABLE_NUM][DCR_TABLE_ROW_NUM][DCR_TABLE_COL_NUM];    /*20121121 and*/
		unsigned char DCR_TABLE[DCT_TABLE_NUM][5];	/* DCR table*/
} ISR_SCALERDRV_DCRTABLE;
/*#endif */ /*#ifdef CONFIG_ENABLE_VIP_PSEUDO_RPC*/
/**
 * ioctl commands.
 */


/*-----------------------------------------------------------------------------------------*/
#endif
