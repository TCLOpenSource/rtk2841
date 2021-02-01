/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2009
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: Jennifer $
 * @date 	$Date: 2015/10/13 16:30 $
 * @version 	$Revision: 0.1 $
 * @ingroup 	VIDEO_DECODER
 */

 /**
 * @addtogroup vdc
 * @{
 */


/*================ Module dependency  =============== */

#ifdef __cplusplus
extern "C" {
#endif

/*================ VIDEO_DECODER tables  =============== */
extern void module_vdc_TV_DCTIeh_Table_write(unsigned short *table);
extern unsigned char VDC_DCTI_SET1[18];
extern unsigned char VDC_DCTI_SET2[18];
extern unsigned char VDC_DCTI_SET3[18];
extern unsigned char VDC_DCTI_SET4[18];
extern unsigned char VDC_DCTI_SET5[18];
extern unsigned short VDC_DCTI_Enhance_3db_1level[5];
extern unsigned short VDC_DCTI_Enhance_3db_2level[5];
extern unsigned short VDC_DCTI_Enhance_9db_1level[5];
extern unsigned short VDC_DCTI_Enhance_9db_2level[5];
extern unsigned short VDC_DCTI_Enhance_6db_1level[5];
extern unsigned short VDC_DCTI_Enhance_6db_2level[5];
extern unsigned short VDC_DCTI_Enhance_12db_1level[5];
extern unsigned short VDC_DCTI_Enhance_12db_2level[5];
#ifdef VD_hdto_adjust
extern UINT32 VDC_HDTO_table[4][6];
#endif

extern unsigned char VDC_3D_POSTP_ALPHAWEI_SET[2][8][19];
extern unsigned char VDC_2D_POSTP_ALPHAWEI_SET[2][8][19];

extern unsigned short INPUT_FILTER_55MHZ[72];
extern unsigned short INPUT_FILTER_60MHZ[72];
extern unsigned short INPUT_FILTER_65MHZ[72];
extern unsigned short INPUT_FILTER_70MHZ[72];
extern unsigned short INPUT_FILTER_75MHZ[72];
extern unsigned short INPUT_FILTER_80MHZ[72];
extern unsigned short INPUT_FILTER_85MHZ[72];

//extern unsigned char VD_NEW_YCbCr_Delay_TABLE_MAP[2][3][8][4];

#ifdef __cplusplus
}
#endif


