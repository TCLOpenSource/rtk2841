/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * The file is a declaration and definition header file
 *
 * @author 	$Author:  $
 * @date 	$Date:  $
 * @version 	$Revision:  $
 * @ingroup
 */

 /**
 * @addtogroup
 * @{
 */

#ifndef _INPROCVIDEO_H
#define _INPROCVIDEO_H

//#include "rtd_types.h"

typedef enum _INPROCVIDE_TABLE_INFO {
	INPROCVIDE_TABLE_AV,
	INPROCVIDE_TABLE_VIDEO8,
	INPROCVIDE_TABLE_AV_OFFSET,
	INPROCVIDE_TABLE_SV_OFFSET
}INPROCVIDE_TABLE_INFO;

void drvif_inprocvideo_init(void);
//unsigned char drvif_inprocvideo_setup(void);
unsigned char drvif_inprocvideo_setup(unsigned char a_ucSrc, StructDisplayInfo* a_ptDispInfo, ModeInformationType* a_ptTimingInfo);
//void drvif_inprocvideo_config_capture(unsigned char display, unsigned char modecnt);
void drvif_inprocvideo_config_capture(unsigned char a_ucSrc, unsigned char display, unsigned char modecnt, StructDisplayInfo* a_ptDispInfo, ModeInformationType* a_ptTimingInfo,unsigned char vd_mode, unsigned char supportColor);
unsigned char drvif_inprocvideo_regTable(INPROCVIDE_TABLE_INFO info , unsigned short *ptr);
void drvif_inprocvideo_offline_measure_check(SCALER_DISP_CHANNEL Display);

unsigned char drvif_inprocvideo_setup_NoSignal(unsigned char a_ucSrc, StructDisplayInfo* a_ptDispInfo, ModeInformationType* a_ptTimingInfo, unsigned char a_ucColorStd);
unsigned char drvif_inprocvideo_setup_ex(unsigned char a_ucSrc, StructDisplayInfo* a_ptDispInfo, ModeInformationType* a_ptTimingInfo, unsigned char ucVideoMode);
unsigned char drvif_inprocvideo_setup_NotMeasure(unsigned char a_ucSrc, StructDisplayInfo* a_ptDispInfo, ModeInformationType* a_ptTimingInfo, unsigned char ucModeCur, unsigned char supportColor);

#endif /* _INPROCVIDEO_H */

 /**
 *
 * @}
 */
