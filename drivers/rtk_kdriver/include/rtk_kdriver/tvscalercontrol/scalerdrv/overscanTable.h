#ifndef __OVERSCAN_H__
#define __OVERSCAN_H__
#include "rtd_types.h"

#include <tvscalercontrol/scalerdrv/scalerdisplay.h>

typedef enum _SOURCE_TIMING {

	SOURCE_TIMING_UNKNOWN = 0,
	SOURCE_TIMING_ATV_480I,
	SOURCE_TIMING_ATV_576I,
	SOURCE_TIMING_AV_480I,
	SOURCE_TIMING_AV_576I,
	SOURCE_TIMING_SV_480I,
	SOURCE_TIMING_SV_576I,
	SOURCE_TIMING_YPBPR_480I,
	SOURCE_TIMING_YPBPR_480P,
	SOURCE_TIMING_YPBPR_576I,
	SOURCE_TIMING_YPBPR_576P,
	SOURCE_TIMING_YPBPR_720P,
	SOURCE_TIMING_YPBPR_1080I,
	SOURCE_TIMING_YPBPR_1080P,
	SOURCE_TIMING_VGA,
	SOURCE_TIMING_HDMI_480I,
	SOURCE_TIMING_HDMI_480P,
	SOURCE_TIMING_HDMI_576I,
	SOURCE_TIMING_HDMI_576P,
	SOURCE_TIMING_HDMI_720P,
	SOURCE_TIMING_HDMI_1080I,
	SOURCE_TIMING_HDMI_1080P,
	SOURCE_TIMING_VO_480I,
	SOURCE_TIMING_VO_480P,
	SOURCE_TIMING_VO_576I,
	SOURCE_TIMING_VO_576P,
	SOURCE_TIMING_VO_720P,
	SOURCE_TIMING_VO_1080I,
	SOURCE_TIMING_VO_1080P,
	SOURCE_TIMING_VO_4K2KI,
	SOURCE_TIMING_VO_4K2KP,
	SOURCE_TIMING_MAX

} SOURCE_TIMING;

typedef struct _OVERSCAN_INFO {

	SOURCE_TIMING			timing;
	unsigned short 			hRatio;
	unsigned short 			vRatio;

} OVERSCAN_INFO;

typedef struct _VGIP_ADJUSTMENT_INFO {

	unsigned char        timing;
	char          h_start;
	char          h_width;
	char          v_start;
	char          v_length;
	int	h_factor;
	int	v_factor;
	unsigned char	h_initial;
	unsigned char	v_initial;
	unsigned char	partial_drop;
} VGIP_ADJUSTMENT_INFO;

//void Overscan_Init(void);
void Mode_scaler_overscan(stDISPLAY_OVERSCAN_DATA *pt_scan, SLR_RATIO_TYPE ratio_type);
void Mode_scaler_VGIP_Adjustment(stVGIP_ADJUSTMENT_INFO *pt_data, SLR_RATIO_TYPE ratio_type);

#endif // __OVERSCAN_H__

