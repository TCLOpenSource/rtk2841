/* 20160608 Still Logo Detect header file*/
#ifndef  __STILLLOGODETECT_H__
#define  __STILLLOGODETECT_H__

#ifdef __cplusplus
extern "C" {
#endif
/* some include about scaler*/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <scalercommon/vipCommon.h>
#else
#include <scaler/vipCommon.h>
#endif

#ifdef MAC5_NO_SLD
void drvif_color_set_SLD_Enable(unsigned char enable);

#if 1 /*SLD, hack, elieli*/
void drvif_color_set_SLD_control(DRV_SLD_Ctrl *ptr);
void drvif_color_set_SLD_input_size(DRV_SLD_Size *ptr);
void drvif_color_set_SLD_curve_map(DRV_SLD_CurveMap *ptr);
void drvif_color_set_SLD_drop(DRV_SLD_DROP *ptr);
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif // __LOCALCONTRAST_H__


