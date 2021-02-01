#ifndef __I3DDMA_UZD_H_
#define __I3DDMA_UZD_H__

#ifdef __cplusplus
extern "C" {
#endif
//#include <rbus/rbusTypes.h>
//#include <rtd_types.h>

//#include <scaler/scalerCommon.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/scaler/scalerlib.h>

/*================================ Definitions ==============================*/
#define _RGB2YUV_m11				0x00
#define _RGB2YUV_m12				0x01
#define _RGB2YUV_m13				0x02
#define _RGB2YUV_m21				0x03
#define _RGB2YUV_m22				0x04
#define _RGB2YUV_m23				0x05
#define _RGB2YUV_m31				0x06
#define _RGB2YUV_m32				0x07
#define _RGB2YUV_m33				0x08
#define _RGB2YUV_Yo_even			0x09
#define _RGB2YUV_Yo_odd			0x0a
#define _RGB2YUV_Y_gain				0x0b
#define _RGB2YUV_sel_RGB			0x0c
#define _RGB2YUV_set_Yin_offset		0x0d
#define _RGB2YUV_set_UV_out_offset	0x0e
#define _RGB2YUV_sel_UV_off			0x0f
#define _RGB2YUV_Matrix_bypass		0x10
#define _RGB2YUV_Enable_Y_gain		0x11


/*================================ I3DDMA color rgb2yuv ==============================*/
void I3DDMA_color_colorspacergb2yuvtransfer(DISPD_CAP_SRC idmaDispD_in_sel);


/*================================ I3DDMA scaling down ==============================*/
void I3DDMA_ultrazoom_set_scale_down(SIZE* in_Size, SIZE* out_Size, unsigned char panorama);
void I3DDMA_ultrazoom_config_scaling_down(SIZE* in_Size, SIZE* out_Size, unsigned char panorama);


#ifdef __cplusplus
}
#endif


#endif

