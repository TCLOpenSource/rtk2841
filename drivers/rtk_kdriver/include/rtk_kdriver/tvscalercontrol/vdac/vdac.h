#ifndef _VDAC_H
#define _VDAC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <tvscalercontrol/io/ioregdrv.h>
//#include <tvscalercontrol/frontend/ifd_rtd296x_analog.h>

#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#define rtd_inl(x)     									IoReg_Read32(x)
//#define rtd_maskl(x, y, z)     							IoReg_Mask32(x,y,z)

typedef enum  {
	VDAC_TV_SRC_SEL_VD = 0,
	VDAC_TV_SRC_SEL_ADC =3,
	VDAC_TV_SRC_SEL_IFD_DEBUG =4,
	VDAC_TV_SRC_SEL_LSADC =5,
	VDAC_TV_SRC_SEL_TV_TVE =6,
	VDAC_TV_SRC_SEL_BOX_TVE =7,
}VDAC_TV_SRC_SEL;


void drvif_vdac_init(void);
void drvif_vdac_tvdac_power_on(unsigned char enable);
void drvif_vdac_yppdac_power_on(unsigned char enable);
void drvif_vdac_source_sel(VDAC_TV_SRC_SEL sel);


#ifdef __cplusplus
}
#endif

#endif //VDAC_H
