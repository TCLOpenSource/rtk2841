#ifndef _DCC_H_
#define _DCC_H_


/*#include "rtd_types.h"*/
/*******************************************************************************
*Definitions*
******************************************************************************/

#define DCC_USERTABLE_ROW_MAX		5
#define DCC_USERTABLE_COL_MAX		36

/*******************************************************************************
 * Structure
 ******************************************************************************/


typedef struct {
	unsigned short chroma_gain_limit;
	unsigned char	chroma_gain_seg0;
	unsigned char	chroma_gain_seg1;
	unsigned char	chroma_gain_seg2;
	unsigned char	chroma_gain_seg3;
	unsigned char	chroma_gain_seg4;
	unsigned char	chroma_gain_seg5;
	unsigned char	chroma_gain_seg6;
	unsigned char	chroma_gain_seg7;
	unsigned char	chroma_gain_seg8;
	unsigned char chroma_gain_intp_en;
} DRV_VipChromaCompensation_t;


/*******************************************************************************
*functions*
******************************************************************************/

unsigned char drvif_color_regDCL_table(unsigned short *table);
void drvif_color_old_dcc_setlevel(unsigned char disp, unsigned char DCC_level);
void drvif_color_new_dcc_setlevel(unsigned char disp, unsigned char DCC_level);


void drvif_color_dcc_hist_on(unsigned char display, int status);
void drvif_color_set_dcc_overlap_table(void);
void drvif_color_dcc_Curve_init(unsigned char display);
unsigned char drvif_color_dcc_Curve_Write(unsigned char display, unsigned char CurveSegNum, unsigned int *sAccLUT);
void drvif_color_set_dcc_chroma_compensation_Init(unsigned char display);
void drvif_color_dcc_on(unsigned char enable);
void drvif_color_set_dcc_Color_Independent(VIP_DCC_Color_Independent_Blending_Table *ptr);
void drvif_color_set_dcc_Skin_Tone_User_Curve(Color_Independent_USER_CURVE *ptr);
/*void drvif_color_set_dcc_chroma_compensation_Limit_Mode(unsigned char display,UINT8 gain,UINT16 gain_limit);*/
void drvif_color_set_dcc_chroma_compensation_Curve_Mode(unsigned char display, VIP_DCC_Chroma_Compensation_TABLE *table);
void drvif_color_set_dcc_Luma_offset(unsigned char display, unsigned char offset_level);
void drvif_color_get_dcc_current_curve(unsigned int *pCurveNode, unsigned int nodenum, unsigned char display);
unsigned char drvif_color_dcc_db_switch(void);
void drvif_color_set_dcc_Chroma_enhance(void);

void drvif_color_DCC_ctrl_YUV2RGB(unsigned char data_format_sel, unsigned char data_range_sel);

#endif /* _DCC_H_ */
