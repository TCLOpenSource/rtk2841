#include "tvscalercontrol/scalerdrv/scalerdisplay.h"
#include <scalercommon/scalerDrvCommon.h>

#include "tvscalercontrol/scaler/scalerstruct.h"
#include "tvscalercontrol/hdmirx/hdmifun.h"
#include "tvscalercontrol/scalerdrv/overscanTable.h"
#include "tvscalercontrol/vip/ultrazoom.h"

//FOR overscan at VGIP

static OVERSCAN_INFO m_overScanList[] = {

	{SOURCE_TIMING_UNKNOWN, 400, 400},		// default

	{SOURCE_TIMING_ATV_480I, 363, 370},
	{SOURCE_TIMING_ATV_576I, 364, 376},

	{SOURCE_TIMING_AV_480I, 380, 372},
	{SOURCE_TIMING_AV_576I, 367, 373},

	{SOURCE_TIMING_SV_480I, 380, 380},
	{SOURCE_TIMING_SV_576I, 380, 380},

	{SOURCE_TIMING_YPBPR_480I, 360, 376},
	{SOURCE_TIMING_YPBPR_480P, 360, 376},
	{SOURCE_TIMING_YPBPR_576I, 360, 376},
	{SOURCE_TIMING_YPBPR_576P, 376, 376},
	{SOURCE_TIMING_YPBPR_720P, 383, 385},
	{SOURCE_TIMING_YPBPR_1080I, 385, 385},
	{SOURCE_TIMING_YPBPR_1080P, 385, 385},

	{SOURCE_TIMING_VGA, 400, 400},

	{SOURCE_TIMING_HDMI_480I, 380, 372},
	{SOURCE_TIMING_HDMI_480P, 384, 386},
	{SOURCE_TIMING_HDMI_576I, 382, 386},
	{SOURCE_TIMING_HDMI_576P, 384, 386},
	{SOURCE_TIMING_HDMI_720P, 383, 384},
	{SOURCE_TIMING_HDMI_1080I, 384, 384},
	{SOURCE_TIMING_HDMI_1080P, 384, 384},

	//USER: Vincent_Lee  DATE: 2011/9/7  TODO: VO source use 100% overscan
	{SOURCE_TIMING_VO_480I, 400, 400},
	//{SOURCE_TIMING_VO_480P, 93, 93},
	{SOURCE_TIMING_VO_480P, 400, 400},
	{SOURCE_TIMING_VO_576I, 400, 400},
	{SOURCE_TIMING_VO_576P, 400, 400},
	{SOURCE_TIMING_VO_720P, 400, 400},
	//{SOURCE_TIMING_VO_1080I, 93, 93},
	{SOURCE_TIMING_VO_1080I, 400, 400},
	{SOURCE_TIMING_VO_1080P, 400, 400},
	{SOURCE_TIMING_VO_4K2KI, 400, 400},
	{SOURCE_TIMING_VO_4K2KP, 400, 400},

};

#if 0
static OVERSCAN_INFO m_overScanList_100[] = {

	{SOURCE_TIMING_UNKNOWN, 100, 100},		// default

	{SOURCE_TIMING_ATV_480I, 100, 100},
	{SOURCE_TIMING_ATV_576I, 100, 100},

	{SOURCE_TIMING_AV_480I, 100, 100},
	{SOURCE_TIMING_AV_576I, 100, 100},

	{SOURCE_TIMING_SV_480I, 100, 100},
	{SOURCE_TIMING_SV_576I, 100, 100},

	{SOURCE_TIMING_YPBPR_480I, 100, 100},
	{SOURCE_TIMING_YPBPR_480P, 100, 100},
	{SOURCE_TIMING_YPBPR_576I, 100, 100},
	{SOURCE_TIMING_YPBPR_576P, 100, 100},
	{SOURCE_TIMING_YPBPR_720P, 100, 100},
	{SOURCE_TIMING_YPBPR_1080I, 100, 100},
	{SOURCE_TIMING_YPBPR_1080P, 100, 100},

	{SOURCE_TIMING_VGA, 100, 100},

	{SOURCE_TIMING_HDMI_480I, 100, 100},
	{SOURCE_TIMING_HDMI_480P, 100, 100},
	{SOURCE_TIMING_HDMI_576I, 100, 100},
	{SOURCE_TIMING_HDMI_576P, 100, 100},
	{SOURCE_TIMING_HDMI_720P, 100, 100},
	{SOURCE_TIMING_HDMI_1080I, 100, 100},
	{SOURCE_TIMING_HDMI_1080P, 100, 100},

	//USER: Vincent_Lee  DATE: 2011/9/7  TODO: VO source use 100% overscan
	{SOURCE_TIMING_VO_480I, 100, 100},
	//{SOURCE_TIMING_VO_480P, 93, 93},
	{SOURCE_TIMING_VO_480P, 100, 100},
	{SOURCE_TIMING_VO_576I, 100, 100},
	{SOURCE_TIMING_VO_576P, 100, 100},
	{SOURCE_TIMING_VO_720P, 100, 100},
	//{SOURCE_TIMING_VO_1080I, 93, 93},
	{SOURCE_TIMING_VO_1080I, 100, 100},
	{SOURCE_TIMING_VO_1080P, 100, 100},
	{SOURCE_TIMING_VO_4K2KI, 100, 100},
	{SOURCE_TIMING_VO_4K2KP, 100, 100},

};
#endif

static VGIP_ADJUSTMENT_INFO m_AdjustmentList[] = {
    {SOURCE_TIMING_UNKNOWN, 0, 0, 0, 0,0,0,0,0,0}, // default

    {SOURCE_TIMING_ATV_480I, 0, 5, 1, 4,-200,0,240,245,0},
    {SOURCE_TIMING_ATV_576I, -10, 0, 1, -1,0,0,60,191,0},

    {SOURCE_TIMING_AV_480I, 16, -11, 1, 0,0,0,240,245,0},
    {SOURCE_TIMING_AV_576I, 3, -3, 3, -1,0,0,255,154,0},

    {SOURCE_TIMING_SV_480I, 0, 0, 0, 0,0,0,0,0,0},
    {SOURCE_TIMING_SV_576I, 0, 0, 0, 0,0,0,0,0,0},

    {SOURCE_TIMING_YPBPR_480I, -11, 12, 5, -6,0,0,166,206,0},
    {SOURCE_TIMING_YPBPR_480P, -3, 3, 7, -15,0,0,0,0,0},
    {SOURCE_TIMING_YPBPR_576I, -7, 11, 3, -6,0,0,0,0,0},
    {SOURCE_TIMING_YPBPR_576P, 3, -3, 0, -3,0,0,0,0,0},
    {SOURCE_TIMING_YPBPR_720P, 3, 1, 9, -16,0,-1000,255,161,0},
    {SOURCE_TIMING_YPBPR_1080I, 5, -6, 1, 0,0,0,2,92,0},
    {SOURCE_TIMING_YPBPR_1080P, 5, -6, 1, 0,0,0,153,181,0},

    {SOURCE_TIMING_VGA, 0, 0, 0, 0,0,0,0,0,0},

    {SOURCE_TIMING_HDMI_480I, 2, 7, 1, 6,0,0,0,228,1},
    {SOURCE_TIMING_HDMI_480P, 0, 0, 2, -1,0,0,169,201,0},
    {SOURCE_TIMING_HDMI_576I, 1, 1, 3, 0,0,0,163,159,1},
    {SOURCE_TIMING_HDMI_576P, 1, 0, 2, -3,0,-1000,203,221,1},
    {SOURCE_TIMING_HDMI_720P, 0, 1, 1, 0,0,0,255,255,1},
    {SOURCE_TIMING_HDMI_1080I, 1, 3, 1, -1,0,0,255,255,1},
    {SOURCE_TIMING_HDMI_1080P, 0, 0, 1, 1,0,0,255,255,0},

    {SOURCE_TIMING_VO_480I, 0, 0, 0, 0,0,0,0,0,0},
    {SOURCE_TIMING_VO_480P, 0, 0, 0, 0,0,0,0,0,0},
    {SOURCE_TIMING_VO_576I, 0, 0, 0, 0,0,0,0,0,0},
    {SOURCE_TIMING_VO_576P, 0, 0, 0, 0,0,0,0,0,0},
    {SOURCE_TIMING_VO_720P, 0, 0, 0, 0,0,0,0,0,0},
    {SOURCE_TIMING_VO_1080I, 0, 0, 0, 0,0,0,0,0,0},
    {SOURCE_TIMING_VO_1080P, 0, 0, 0, 0,0,0,0,0,0},
    {SOURCE_TIMING_VO_4K2KI, 0, 0, 0, 0,0,0,0,0,0},
    {SOURCE_TIMING_VO_4K2KP, 0, 0, 0, 0,0,0,0,0,0},
};

#if 0
static VGIP_ADJUSTMENT_INFO m_AdjustmentList_100[] = {
    {SOURCE_TIMING_UNKNOWN, 0, 0, 0, 0,0,0,0,0}, // default

    {SOURCE_TIMING_ATV_480I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_ATV_576I, 0, 0, 0, 0,0,0,0,0},

    {SOURCE_TIMING_AV_480I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_AV_576I, 0, 0, 0, 0,0,0,0,0},

    {SOURCE_TIMING_SV_480I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_SV_576I, 0, 0, 0, 0,0,0,0,0},

    {SOURCE_TIMING_YPBPR_480I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_YPBPR_480P, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_YPBPR_576I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_YPBPR_576P, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_YPBPR_720P, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_YPBPR_1080I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_YPBPR_1080P, 0, 0, 0, 0,0,0,0,0},

    {SOURCE_TIMING_VGA, 0, 0, 0, 0,0,0,0,0},

    {SOURCE_TIMING_HDMI_480I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_HDMI_480P, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_HDMI_576I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_HDMI_576P, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_HDMI_720P, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_HDMI_1080I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_HDMI_1080P, 0, 0, 0, 0,0,0,0,0},

    {SOURCE_TIMING_VO_480I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_VO_480P, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_VO_576I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_VO_576P, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_VO_720P, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_VO_1080I, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_VO_1080P, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_VO_4K2KI, 0, 0, 0, 0,0,0,0,0},
    {SOURCE_TIMING_VO_4K2KP, 0, 0, 0, 0,0,0,0,0},
};
#endif

static OVERSCAN_INFO *xGetOverScanInfo(SOURCE_TIMING timing, SLR_RATIO_TYPE ratio_type)
{
	int i = 0, count = sizeof(m_overScanList)/sizeof(OVERSCAN_INFO);

#ifdef ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE
	unsigned char bIsNonIdmaSg3dMode=0;
	SLR_3D_TYPE cur3dtype = (SLR_3D_TYPE)Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE);
	// non-IDMA SG 3D mode H/V position adjustment
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE()  && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == FALSE)
		&& drvif_scaelr3d_decide_is_3D_display_mode() && drvif_scaler3d_decide_3d_SG_Disable_IDMA(cur3dtype))
	{
		bIsNonIdmaSg3dMode = TRUE;
	}

	if(bIsNonIdmaSg3dMode == TRUE){ // [3D] 3D overscan for non-IDMA SG 3D mode
		int count_tab = sizeof(m_overScanList_3D_TaB)/sizeof(OVERSCAN_INFO);
		count = sizeof(m_overScanList_3D_SBS)/sizeof(OVERSCAN_INFO);
		if((cur3dtype == SLR_3D_TOP_AND_BOTTOM) && (count != count_tab)){
			printk("\n[3D][WARN] SBS/TaB 3D mode count(%d/%d) not sync!!\n\n", count, count_tab);
			return &m_overScanList_3D_TaB[0];
		}

		for (i=0; i<count; i++) {
			if ((cur3dtype == SLR_3D_SIDE_BY_SIDE_HALF) && (m_overScanList_3D_SBS[i].timing == timing)){
				return &m_overScanList_3D_SBS[i];
			}else if ((cur3dtype == SLR_3D_TOP_AND_BOTTOM) && (m_overScanList_3D_TaB[i].timing == timing)){
				return &m_overScanList_3D_TaB[i];
			}
		}
		printk("[3D] FAIL FIND TIMING/MODE=%d/%d\n", timing, cur3dtype);
		// [FIX-ME] bypass 3D overscan in FP 3D mode
		if(cur3dtype == SLR_3D_FRAME_PACKING)
			return &m_overScanList[0];
		else
		return (cur3dtype == SLR_3D_TOP_AND_BOTTOM? &m_overScanList_3D_TaB[0]: &m_overScanList_3D_SBS[0]);
	}
#endif
#if 0
	switch(ratio_type)
	{
		case SLR_RATIO_DISABLE:
		case SLR_ASPECT_RATIO_100:
		case SLR_RATIO_POINTTOPOINT:
		case SLR_RATIO_FIT:
			for (i=0; i<count; i++)
			{
				if (m_overScanList_100[i].timing == timing)
				return &m_overScanList_100[i];
			}
			return &m_overScanList_100[0];
			break;

		case SLR_RATIO_BBY_WIDE_1:
		default:
			for (i=0; i<count; i++)
			{
				if (m_overScanList[i].timing == timing)
				return &m_overScanList[i];
			}
			return &m_overScanList[0];
			break;

	}
#endif
for (i=0; i<count; i++)
{
	if (m_overScanList[i].timing == timing)
	return &m_overScanList[i];
}
return &m_overScanList[0];

}

void Mode_get_cur_overscan_ratio(unsigned short *h_ratio, unsigned short *v_ratio, SLR_RATIO_TYPE ratio_type)
{
	unsigned int timingMode = Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	OVERSCAN_INFO *pOverscanInfo = NULL;
	unsigned char src_type;
#if defined(ENABLE_DRIVER_I3DDMA) && defined(ENABLE_I3DDMA_3D_OVERSCAN)
	src_type = modestate_I3DDMA_get_2dSrcType();
#else
	src_type = Scaler_InputSrcGetMainChType();
#endif
	timingMode =  Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);

	pr_debug("src type=%d %d\n",src_type,timingMode);


	switch (src_type)
	{
		case _SRC_VO:
		{
			//if (SourceControl_GetPlaybackType() == PLAYBACK_MODE_JPEG)
			//{
			//	*h_ratio = 100;
			//	*v_ratio = 100;
			//}
			//else
			{
				switch (timingMode)
				{
				case _MODE_480I:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_VO_480I, ratio_type);
					break;
				case _MODE_480P:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_VO_480P, ratio_type);
					break;
				case _MODE_576I:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_VO_576I, ratio_type);
					break;
				case _MODE_576P:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_VO_576P, ratio_type);
					break;
				case _MODE_720P50:
				case _MODE_720P60:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_VO_720P, ratio_type);
					break;
				case _MODE_1080I25:
				case _MODE_1080I30:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_VO_1080I, ratio_type);
					break;
				case _MODE_1080P50:
				case _MODE_1080P60:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_VO_1080P, ratio_type);
					break;
					case _MODE_4k2kI30:
					case _MODE_4k2kP30:
						pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_VO_4K2KP, ratio_type);
						break;
				default:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_VO_480I, ratio_type);
					break;
				}
			}
			break;
		}
		case _SRC_TV:
			if (timingMode == _MODE_480I)
				pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_ATV_480I, ratio_type);
			else
				pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_ATV_576I, ratio_type);
			break;

		case _SRC_CVBS:
		case _SRC_SCART:
			if (timingMode == _MODE_480I)
				pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_AV_480I, ratio_type);
			else
				pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_AV_576I, ratio_type);
			break;

		case _SRC_SV:
		case _SRC_SCART_RGB:
			if (timingMode == _MODE_480I)
				pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_SV_480I, ratio_type);
			else
				pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_SV_576I, ratio_type);
			break;

		case _SRC_YPBPR:
				switch (timingMode)
				{
				case _MODE_480I:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_YPBPR_480I, ratio_type);
					break;
				case _MODE_480P:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_YPBPR_480P, ratio_type);
					#ifdef YPBPR_SD_SAMPLE_CLOCK_54M
						pOverscanInfo->hRatio = 380;
						pOverscanInfo->vRatio = 380;
						pr_debug("Get overscan ration 95%\n");
					#endif

					break;
				case _MODE_576I:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_YPBPR_576I, ratio_type);
					break;
				case _MODE_576P:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_YPBPR_576P, ratio_type);
					break;
				case _MODE_720P50:
				case _MODE_720P60:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_YPBPR_720P, ratio_type);
					break;
				case _MODE_1080I25:
				case _MODE_1080I30:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_YPBPR_1080I, ratio_type);
					break;
				case _MODE_1080P50:
				case _MODE_1080P60:

				case _MODE_1080P23:
				case _MODE_1080P24:
				case _MODE_1080P25:
				case _MODE_1080P29:
				case _MODE_1080P30:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_YPBPR_1080P, ratio_type);
					break;
				default:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_YPBPR_480I, ratio_type);
					break;
				}

			break;

		case _SRC_VGA:
			pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_VGA, ratio_type);
			break;

		case _SRC_HDMI:
			//////////////////////////////////////////
			//By Gilbert(2009/6/19)
			//DVI don't need overscan
			///////////////////////////////////////////
			/* //chengying mark avoid overscan is error if occur DVI mode
			if (DisplayControl_GetScreenMode() == true) {
				//DVI screen mode will skip overscan, and show total screen data
				drvif_HDMI_SetScreenMode(HDMI_OSD_MODE_DVI);
				return;
			} else {
				drvif_HDMI_SetScreenMode(HDMI_OSD_MODE_AUTO);
				//HDMI screen mode will perform overscan, and scaler will cut 4-lines of (up+down) before overscan
				//drvif_HDMI_SetScreenModeDVI(false);
			}
			*/

			if (drvif_IsHDMI() == MODE_HDMI) {
				switch (timingMode)
				{
				case _MODE_480I:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_HDMI_480I, ratio_type);
					break;
				case _MODE_480P:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_HDMI_480P, ratio_type);
					break;
				case _MODE_576I:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_HDMI_576I, ratio_type);
					break;
				case _MODE_576P:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_HDMI_576P, ratio_type);
					break;
				case _MODE_720P50:
				case _MODE_720P60:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_HDMI_720P, ratio_type);
					break;
				case _MODE_1080I25:
				case _MODE_1080I30:
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_HDMI_1080I, ratio_type);
					break;
				case _MODE_1080P50:
				case _MODE_1080P23:
				case _MODE_1080P24:
				case _MODE_1080P25:
				case _MODE_1080P29:
				case _MODE_1080P30:
				case _MODE_1080P60:		//xiacong 20120803 move here
					pr_debug("ok overscan\n");
					pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_HDMI_1080P, ratio_type);
					break;
			//	case _MODE_1080P60:
				default:
					pr_debug("no overscan..........\n");
					//pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_HDMI_480I);
					*h_ratio = 400;
					*v_ratio = 400;
					break;
				}
			} else { // DVI
				*h_ratio = 400;
				*v_ratio = 400;
			}
			break;
		default:
			pOverscanInfo = xGetOverScanInfo(SOURCE_TIMING_UNKNOWN, ratio_type);
			break;
	}

	if (pOverscanInfo != NULL) {
		*h_ratio = pOverscanInfo->hRatio;
		*v_ratio = pOverscanInfo->vRatio;
	}
}

void Mode_scaler_overscan(stDISPLAY_OVERSCAN_DATA *pt_scan, SLR_RATIO_TYPE ratio_type)
{
	unsigned short ulResult;
	unsigned short h_ratio, v_ratio;

	Mode_get_cur_overscan_ratio(&h_ratio, &v_ratio, ratio_type);

	pr_debug("hratio=%d vratio=%d\n",h_ratio,v_ratio);

	if (h_ratio == 400 && v_ratio == 400)
		return;

	//Elsie 20140508
	//limitation of nonlinear scaling up: width <= 1810
	if(Scaler_DispCheckRatio(SLR_RATIO_PANORAMA) &&
		(Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR) >= _MODE_1080I25) &&
		(Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR) <= _MODE_1080PM60))
		h_ratio = 377;

	ulResult = pt_scan->VHeight*(400-v_ratio)/400;

	pt_scan->VStart = pt_scan->VStart + ulResult/2;
	pt_scan->VHeight = pt_scan->VHeight - ulResult;

	ulResult = pt_scan->HWidth*(400-h_ratio)/400;

	pt_scan->HStart = pt_scan->HStart + ulResult/2;
	pt_scan->HWidth = pt_scan->HWidth - ulResult;
}

void Mode_scaler_VGIP_Adjustment(stVGIP_ADJUSTMENT_INFO *pt_data, SLR_RATIO_TYPE ratio_type)
{
        unsigned int timingMode;
        unsigned char src_type;
        VGIP_ADJUSTMENT_INFO table = {0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0};
	unsigned char bIsNonIdmaSg3dMode=0;

	pr_debug("Mode_scaler_VGIP_Adjustment\n");

	src_type = Scaler_InputSrcGetMainChType();
	timingMode= Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);

#if 0	//#ifdef ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE
	// non-IDMA SG 3D mode H/V position adjustment
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE()  && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == FALSE)
		&& drvif_scaelr3d_decide_is_3D_display_mode() && drvif_scaler3d_decide_3d_SG_Disable_IDMA(Scaler_Disp3dGetInfo(SLR_DISP_3D_3DTYPE)))
	{
		bIsNonIdmaSg3dMode = TRUE;
	}

	// Need to be fine tuned
	if(bIsNonIdmaSg3dMode){
		if((src_type != _SRC_TV) && (src_type != _SRC_CVBS)){
			pt_data->h_start += 0;
			pt_data->h_width += 0;
			pt_data->v_start += 0;
			pt_data->v_length += 0;
			return;
		}
	}

#endif

	VGIP_ADJUSTMENT_INFO* pAdjustmentList;
#if 0
	switch(ratio_type)
	{
		case SLR_RATIO_DISABLE:
		case SLR_ASPECT_RATIO_100:
		case SLR_RATIO_POINTTOPOINT:
		case SLR_RATIO_FIT:
			pAdjustmentList = m_AdjustmentList_100;
			break;
		case SLR_RATIO_BBY_WIDE_1:
		default:
			pAdjustmentList = m_AdjustmentList;
			break;
	}
#endif

	pAdjustmentList = m_AdjustmentList;

        switch(src_type)
        {
            case _SRC_VO:
                switch (timingMode)
		{
		case _MODE_480I:
			table.h_start = pAdjustmentList[SOURCE_TIMING_VO_480I].h_start;
			table.h_width = pAdjustmentList[SOURCE_TIMING_VO_480I].h_width;
			table.v_start = pAdjustmentList[SOURCE_TIMING_VO_480I].v_start;
			table.v_length = pAdjustmentList[SOURCE_TIMING_VO_480I].v_length;
			break;
		case _MODE_480P:
			table.h_start = pAdjustmentList[SOURCE_TIMING_VO_480P].h_start;
			table.h_width = pAdjustmentList[SOURCE_TIMING_VO_480P].h_width;
			table.v_start = pAdjustmentList[SOURCE_TIMING_VO_480P].v_start;
			table.v_length = pAdjustmentList[SOURCE_TIMING_VO_480P].v_length;
			break;
		case _MODE_576I:
			table.h_start = pAdjustmentList[SOURCE_TIMING_VO_576I].h_start;
			table.h_width = pAdjustmentList[SOURCE_TIMING_VO_576I].h_width;
			table.v_start = pAdjustmentList[SOURCE_TIMING_VO_576I].v_start;
			table.v_length = pAdjustmentList[SOURCE_TIMING_VO_576I].v_length;
			break;
		case _MODE_576P:
			table.h_start = pAdjustmentList[SOURCE_TIMING_VO_576P].h_start;
			table.h_width = pAdjustmentList[SOURCE_TIMING_VO_576P].h_width;
			table.v_start = pAdjustmentList[SOURCE_TIMING_VO_576P].v_start;
			table.v_length = pAdjustmentList[SOURCE_TIMING_VO_576P].v_length;
			break;
		case _MODE_720P50:
		case _MODE_720P60:
			table.h_start = pAdjustmentList[SOURCE_TIMING_VO_720P].h_start;
			table.h_width = pAdjustmentList[SOURCE_TIMING_VO_720P].h_width;
			table.v_start = pAdjustmentList[SOURCE_TIMING_VO_720P].v_start;
			table.v_length = pAdjustmentList[SOURCE_TIMING_VO_720P].v_length;
			break;
		case _MODE_1080I25:
		case _MODE_1080I30:
			table.h_start = pAdjustmentList[SOURCE_TIMING_VO_1080I].h_start;
			table.h_width = pAdjustmentList[SOURCE_TIMING_VO_1080I].h_width;
			table.v_start = pAdjustmentList[SOURCE_TIMING_VO_1080I].v_start;
			table.v_length = pAdjustmentList[SOURCE_TIMING_VO_1080I].v_length;
			break;
		case _MODE_1080P50:
		case _MODE_1080P60:
			table.h_start = pAdjustmentList[SOURCE_TIMING_VO_1080P].h_start;
			table.h_width = pAdjustmentList[SOURCE_TIMING_VO_1080P].h_width;
			table.v_start = pAdjustmentList[SOURCE_TIMING_VO_1080P].v_start;
			table.v_length = pAdjustmentList[SOURCE_TIMING_VO_1080P].v_length;
			break;
		case _MODE_4k2kI30:
		case _MODE_4k2kP30:
			table.h_start = pAdjustmentList[SOURCE_TIMING_VO_4K2KP].h_start;
			table.h_width = pAdjustmentList[SOURCE_TIMING_VO_4K2KP].h_width;
			table.v_start = pAdjustmentList[SOURCE_TIMING_VO_4K2KP].v_start;
			table.v_length = pAdjustmentList[SOURCE_TIMING_VO_4K2KP].v_length;
			break;
		default:
			break;
		}
                break;
            case _SRC_TV:
                if (timingMode == _MODE_480I){
			 if(bIsNonIdmaSg3dMode){
				// non-IDMA SG 3D mode H/V position adjustment
	                    table.v_start = pAdjustmentList[SOURCE_TIMING_ATV_480I].v_start+2;
	                    table.h_start = pAdjustmentList[SOURCE_TIMING_ATV_480I].h_start-4;
			 }
			 else
			 {
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_ATV_480I].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_ATV_480I].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_ATV_480I].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_ATV_480I].v_length;
				}
			 }
                } else {
			 if(bIsNonIdmaSg3dMode){
				// non-IDMA SG 3D mode H/V position adjustment
				table.v_start = pAdjustmentList[SOURCE_TIMING_ATV_480I].v_start+1;
				table.h_start = pAdjustmentList[SOURCE_TIMING_ATV_480I].h_start+10;
				table.v_length = pAdjustmentList[SOURCE_TIMING_ATV_576I].v_length;//-2;
			 }
			 else
			 {
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_ATV_576I].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_ATV_576I].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_ATV_576I].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_ATV_576I].v_length;
				}
			}
                    //drvif_set_uzu_coeff(pAdjustmentList[SOURCE_TIMING_AV_576I].h_factor, pAdjustmentList[SOURCE_TIMING_AV_480I].v_factor, pAdjustmentList[SOURCE_TIMING_AV_480I].h_initial, pAdjustmentList[SOURCE_TIMING_AV_480I].v_initial);
                }
                break;
            case _SRC_CVBS:
            case _SRC_SCART:
                if (timingMode == _MODE_480I){
			 if(bIsNonIdmaSg3dMode){
				// non-IDMA SG 3D mode H/V position adjustment
	                    table.v_start = pAdjustmentList[SOURCE_TIMING_ATV_480I].v_start+2;
	                    table.h_start = pAdjustmentList[SOURCE_TIMING_ATV_480I].h_start-4;
			 }
			 else
			 {
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_AV_480I].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_AV_480I].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_AV_480I].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_AV_480I].v_length;
				}
			}
                    //drvif_set_uzu_coeff(pAdjustmentList[SOURCE_TIMING_AV_480I].h_factor, pAdjustmentList[SOURCE_TIMING_AV_480I].v_factor, pAdjustmentList[SOURCE_TIMING_AV_480I].h_initial, pAdjustmentList[SOURCE_TIMING_AV_480I].v_initial);
                } else {
			 if(bIsNonIdmaSg3dMode){
				// non-IDMA SG 3D mode H/V position adjustment
				table.v_start = pAdjustmentList[SOURCE_TIMING_ATV_480I].v_start+1;
				table.h_start = pAdjustmentList[SOURCE_TIMING_ATV_480I].h_start+8;
				table.v_length = pAdjustmentList[SOURCE_TIMING_ATV_576I].v_length;//-2;
			 }
			 else
			 {
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_AV_576I].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_AV_576I].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_AV_576I].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_AV_576I].v_length;
				}
			}
                    //drvif_set_uzu_coeff(pAdjustmentList[SOURCE_TIMING_AV_576I].h_factor, pAdjustmentList[SOURCE_TIMING_AV_576I].v_factor, pAdjustmentList[SOURCE_TIMING_AV_576I].h_initial, pAdjustmentList[SOURCE_TIMING_AV_576I].v_initial);
                }
                break;
            case _SRC_SV:
            case _SRC_SCART_RGB:
			if (timingMode == _MODE_480I){
			    table.h_start = pAdjustmentList[SOURCE_TIMING_SV_480I].h_start;
			    table.h_width = pAdjustmentList[SOURCE_TIMING_SV_480I].h_width;
			    table.v_start = pAdjustmentList[SOURCE_TIMING_SV_480I].v_start;
			    table.v_length = pAdjustmentList[SOURCE_TIMING_SV_480I].v_length;
			} else {
			    table.h_start = pAdjustmentList[SOURCE_TIMING_SV_576I].h_start;
			    table.h_width = pAdjustmentList[SOURCE_TIMING_SV_576I].h_width;
			    table.v_start = pAdjustmentList[SOURCE_TIMING_SV_576I].v_start;
			    table.v_length = pAdjustmentList[SOURCE_TIMING_SV_576I].v_length;
			}
			break;

            case _SRC_YPBPR:
                    switch (timingMode)
                    {
			case _MODE_480I:
			{
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_YPBPR_480I].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_YPBPR_480I].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_YPBPR_480I].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_YPBPR_480I].v_length;
				}
				break;
			}
			case _MODE_480P:
			{
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_YPBPR_480P].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_YPBPR_480P].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_YPBPR_480P].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_YPBPR_480P].v_length;
				}
				break;
			}
			case _MODE_576I:
			{
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_YPBPR_576I].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_YPBPR_576I].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_YPBPR_576I].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_YPBPR_576I].v_length;
				}
				break;
			}
			case _MODE_576P:
			{
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_YPBPR_576P].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_YPBPR_576P].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_YPBPR_576P].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_YPBPR_576P].v_length;
				}
				break;
			}
			case _MODE_720P50:
			case _MODE_720P60:
			{
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_YPBPR_720P].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_YPBPR_720P].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_YPBPR_720P].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_YPBPR_720P].v_length;
				}
				//drvif_set_uzu_coeff(pAdjustmentList[SOURCE_TIMING_YPBPR_720P].h_factor, pAdjustmentList[SOURCE_TIMING_YPBPR_720P].v_factor, pAdjustmentList[SOURCE_TIMING_YPBPR_720P].h_initial, pAdjustmentList[SOURCE_TIMING_YPBPR_720P].v_initial);
				break;
			}
			case _MODE_1080I25:
			case _MODE_1080I30:
			{
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_YPBPR_1080I].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_YPBPR_1080I].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_YPBPR_1080I].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_YPBPR_1080I].v_length;
				}
				//drvif_set_uzu_coeff(pAdjustmentList[SOURCE_TIMING_YPBPR_1080I].h_factor, pAdjustmentList[SOURCE_TIMING_YPBPR_1080I].v_factor, pAdjustmentList[SOURCE_TIMING_YPBPR_1080I].h_initial, pAdjustmentList[SOURCE_TIMING_YPBPR_1080I].v_initial);
                        	break;
			}
			case _MODE_1080P50:
			case _MODE_1080P60:
			case _MODE_1080P23:
			case _MODE_1080P24:
			case _MODE_1080P25:
			case _MODE_1080P29:
			case _MODE_1080P30:
			{
				{
					table.h_start = pAdjustmentList[SOURCE_TIMING_YPBPR_1080P].h_start ;
					table.h_width = pAdjustmentList[SOURCE_TIMING_YPBPR_1080P].h_width;
					table.v_start = pAdjustmentList[SOURCE_TIMING_YPBPR_1080P].v_start;
					table.v_length = pAdjustmentList[SOURCE_TIMING_YPBPR_1080P].v_length;
				}
				//drvif_set_uzu_coeff(pAdjustmentList[SOURCE_TIMING_YPBPR_1080P].h_factor, pAdjustmentList[SOURCE_TIMING_YPBPR_1080P].v_factor, pAdjustmentList[SOURCE_TIMING_YPBPR_1080P].h_initial, pAdjustmentList[SOURCE_TIMING_YPBPR_1080P].v_initial);
				break;
			}
                    default:
				break;
                    }
                break;
            case _SRC_VGA:
			table.h_start = pAdjustmentList[SOURCE_TIMING_VGA].h_start;
			table.h_width = pAdjustmentList[SOURCE_TIMING_VGA].h_width;
			table.v_start = pAdjustmentList[SOURCE_TIMING_VGA].v_start;
			table.v_length = pAdjustmentList[SOURCE_TIMING_VGA].v_length;
			break;

            case _SRC_HDMI:
                //////////////////////////////////////////
                //By Gilbert(2009/6/19)
                //DVI don't need overscan
                ///////////////////////////////////////////
                if (drvif_IsHDMI() == MODE_HDMI) {
                    switch (timingMode)
                    {
                    case _MODE_480I:
				table.h_start = pAdjustmentList[SOURCE_TIMING_HDMI_480I].h_start;
				table.h_width = pAdjustmentList[SOURCE_TIMING_HDMI_480I].h_width;
				table.v_start = pAdjustmentList[SOURCE_TIMING_HDMI_480I].v_start;
				table.v_length = pAdjustmentList[SOURCE_TIMING_HDMI_480I].v_length;
				table.partial_drop = pAdjustmentList[SOURCE_TIMING_HDMI_480I].partial_drop;
				break;
                    case _MODE_480P:
				table.h_start = pAdjustmentList[SOURCE_TIMING_HDMI_480P].h_start;
				table.h_width = pAdjustmentList[SOURCE_TIMING_HDMI_480P].h_width;
				table.v_start = pAdjustmentList[SOURCE_TIMING_HDMI_480P].v_start;
				table.v_length = pAdjustmentList[SOURCE_TIMING_HDMI_480P].v_length;
				table.partial_drop = pAdjustmentList[SOURCE_TIMING_HDMI_480P].partial_drop;
				break;
                    case _MODE_576I:
				table.h_start = pAdjustmentList[SOURCE_TIMING_HDMI_576I].h_start;
				table.h_width = pAdjustmentList[SOURCE_TIMING_HDMI_576I].h_width;
				table.v_start = pAdjustmentList[SOURCE_TIMING_HDMI_576I].v_start;
				table.v_length = pAdjustmentList[SOURCE_TIMING_HDMI_576I].v_length;
				table.partial_drop = pAdjustmentList[SOURCE_TIMING_HDMI_576I].partial_drop;
				break;
                    case _MODE_576P:
				table.h_start = pAdjustmentList[SOURCE_TIMING_HDMI_576P].h_start;
				table.h_width = pAdjustmentList[SOURCE_TIMING_HDMI_576P].h_width;
				table.v_start = pAdjustmentList[SOURCE_TIMING_HDMI_576P].v_start;
				table.v_length = pAdjustmentList[SOURCE_TIMING_HDMI_576P].v_length;
				table.partial_drop = pAdjustmentList[SOURCE_TIMING_HDMI_576P].partial_drop;
				break;
                    case _MODE_720P50:
                    case _MODE_720P60:
				table.h_start = pAdjustmentList[SOURCE_TIMING_HDMI_720P].h_start;
				table.h_width = pAdjustmentList[SOURCE_TIMING_HDMI_720P].h_width;
				table.v_start = pAdjustmentList[SOURCE_TIMING_HDMI_720P].v_start;
				table.v_length = pAdjustmentList[SOURCE_TIMING_HDMI_720P].v_length;
				table.partial_drop = pAdjustmentList[SOURCE_TIMING_HDMI_720P].partial_drop;
				break;
                    case _MODE_1080I25:
                    case _MODE_1080I30:
				table.h_start = pAdjustmentList[SOURCE_TIMING_HDMI_1080I].h_start;
				table.h_width = pAdjustmentList[SOURCE_TIMING_HDMI_1080I].h_width;
				table.v_start = pAdjustmentList[SOURCE_TIMING_HDMI_1080I].v_start;
				table.v_length = pAdjustmentList[SOURCE_TIMING_HDMI_1080I].v_length;
				table.partial_drop = pAdjustmentList[SOURCE_TIMING_HDMI_1080I].partial_drop;
                        break;
                    case _MODE_1080P23:
                    case _MODE_1080P24:
                    case _MODE_1080P25:
                    case _MODE_1080P29:
                    case _MODE_1080P30:
                    case _MODE_1080P50:
                    case _MODE_1080P60:
				table.h_start = pAdjustmentList[SOURCE_TIMING_HDMI_1080P].h_start;
				table.h_width = pAdjustmentList[SOURCE_TIMING_HDMI_1080P].h_width;
				table.v_start = pAdjustmentList[SOURCE_TIMING_HDMI_1080P].v_start;
				table.v_length = pAdjustmentList[SOURCE_TIMING_HDMI_1080P].v_length;
				table.partial_drop = pAdjustmentList[SOURCE_TIMING_HDMI_1080P].partial_drop;
				break;
                    default:
				break;
                    }
                }
                break;
            default:
                break;
        }
pr_debug("table.partial_drop = %d\n",table.partial_drop);
	drvif_color_enable_scaleup_hor_start_drop(table.partial_drop);
	if (table.partial_drop) {
		table.h_start = table.h_start - 1;
		table.h_width = table.h_width + 1;
	}

	pt_data->h_start += table.h_start;
	pt_data->h_width += table.h_width;
	pt_data->v_start += table.v_start;
	pt_data->v_length += table.v_length;

}

#if 0
void Overscan_Init(void)
{
	fwif_display_regTable(DISPLAY_REG_FUNC_OVERSCAN, (void *)&Mode_scaler_overscan);
	fwif_display_regTable(DISPLAY_REG_FUNC_VGIP_ADJUSTMENT, (void *)&Mode_scaler_VGIP_Adjustment);
	//fwif_display_regTable(DISPLAY_REG_FUNC_GET_SRC_OVERSCAN, (void *)&Mode_get_cur_overscan_ratio);
}
#endif

