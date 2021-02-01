/* 20140523 Local Dimming header file*/
#ifndef __LOCALDIMMING_H__
#define __LOCALDIMMING_H__

#ifdef __cplusplus
extern "C" {
#endif
/* some include about scaler*/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <scalercommon/vipCommon.h>
#else
#include <scaler/vipCommon.h>
#endif


#define BL_Profile_Table_NUM 6
#define BL_Profile_Table_ROW 8
#define BL_Profile_Table_COLUMN 40
#define LD_Table_NUM 7

typedef struct {
	unsigned char ld_comp_en;
	unsigned char ld_db_en;
	unsigned char ld_db_apply;
	unsigned char ld_db_read_level;
	unsigned char ld_3d_mode;
	unsigned char ld_blk_hnum;
	unsigned char ld_blk_vnum;
	unsigned char ld_subblk_mode;
	unsigned char ld_gdim_mode;
	unsigned char ld_blk_type;
	unsigned char ld_hist_mode;
	unsigned char ld_tenable;
	unsigned char ld_valid;
	unsigned short ld_blk_hsize;
	unsigned short ld_blk_vsize;

} DRV_LD_Global_Ctrl;


typedef struct {
	unsigned char ld_maxgain;
	unsigned char ld_avegain;
	unsigned char ld_histshiftbit;
	unsigned char ld_hist0gain;
	unsigned char ld_hist1gain;
	unsigned char ld_hist2gain;
	unsigned char ld_hist3gain;
	unsigned char ld_hist4gain;
	unsigned char ld_hist5gain;
	unsigned char ld_hist6gain;
	unsigned char ld_hist7gain;

} DRV_LD_Backlight_Decision;



typedef struct
{
	unsigned char ld_spatialcoef0;
	unsigned char ld_spatialcoef1;
	unsigned char ld_spatialcoef2;
	unsigned char ld_spatialcoef3;
	unsigned char ld_spatialcoef4;
	unsigned char ld_spatialcoef5;
	unsigned char ld_spatialcoef6;
	unsigned char ld_spatialcoef7;
	unsigned char ld_spatialcoef8;
	unsigned char ld_spatialcoef9;
	unsigned char ld_spatialcoef10;
	unsigned char spatial_new_mode;
	unsigned char ld_spatialnewcoef00;
	unsigned char ld_spatialnewcoef01;
	unsigned char ld_spatialnewcoef02;
	unsigned char ld_spatialnewcoef03;
	unsigned char ld_spatialnewcoef04;
	unsigned char ld_spatialnewcoef10;
	unsigned char ld_spatialnewcoef11;
	unsigned char ld_spatialnewcoef12;
	unsigned char ld_spatialnewcoef13;
	unsigned char ld_spatialnewcoef14;
	unsigned char ld_spatialnewcoef20;
	unsigned char ld_spatialnewcoef21;
	unsigned char ld_spatialnewcoef22;
	unsigned char ld_spatialnewcoef23;
	unsigned char ld_spatialnewcoef24;
	unsigned char ld_spatialnewcoef30;
	unsigned char ld_spatialnewcoef31;
	unsigned char ld_spatialnewcoef32;
	unsigned char ld_spatialnewcoef33;
	unsigned char ld_spatialnewcoef34;
	unsigned char ld_spatialnewcoef05;
	unsigned char ld_spatialnewcoef15;
	unsigned char ld_spatialnewcoef25;
	unsigned char ld_spatialnewcoef35;
	unsigned char ld_spatialnewcoef40;
	unsigned char ld_spatialnewcoef41;
	unsigned char ld_spatialnewcoef50;
} DRV_LD_Spatial_Filter;

typedef struct {
	unsigned char ld_spatialremapen;
	unsigned short ld_spatialremaptab[65];
} DRV_LD_Spatial_Remap;

typedef struct {
	unsigned char ld_backlightboosten;
	unsigned short ld_boost_gain_lut[65];
	unsigned short ld_boost_curve_lut[65];
} DRV_LD_Boost;



typedef struct {

	unsigned char ld_tmp_pos0thd;
	unsigned char ld_tmp_pos1thd;
	unsigned char ld_tmp_posmingain;
	unsigned char ld_tmp_posmaxgain;
	unsigned char ld_tmp_neg0thd;
	unsigned char ld_tmp_neg1thd;
	unsigned char ld_tmp_negmingain;
	unsigned char ld_tmp_negmaxgain;
	unsigned char ld_tmp_maxdiff;
	unsigned char ld_tmp_scenechangegain1;

} DRV_LD_Temporal_Filter;

typedef struct {
	unsigned char ld_blu_wr_num;
	unsigned short ld_blu_spitotal;
	unsigned char ld_blu_spien;
	unsigned char ld_blu_nodim;
	unsigned char ld_blu_usergain;
} DRV_LD_Backlight_Final_Decision;


typedef struct {
	unsigned char ld_data_comp_mode;
	unsigned char ld_comp_satrange;
	unsigned char ld_comp_softmax;
	unsigned char ld_comp_minlimit;
	unsigned char ld_softcomp_gain;
	unsigned char ld_comp_maxmode;
	unsigned char ld_comp_inv_shift;
	unsigned char ld_comp_inv_mode;
	unsigned char ld_srcgainsel;
} DRV_LD_Data_Compensation;


typedef struct {
	unsigned int ld_comp_2Dtable[17][17];
} DRV_LD_Data_Compensation_NewMode_2DTable;





typedef struct {
	unsigned char ld_tab_hsize;
	unsigned int ld_hfactor;
	unsigned char ld_hinitphase3_right;
	unsigned char ld_hboundary;
	unsigned char ld_hinitphase1;
	unsigned char ld_hinitphase2;
	unsigned char ld_hinitphase3_left;
	unsigned char ld_tab_vsize;
	unsigned int ld_vfactor;
	unsigned char ld_vinitphase3_right;
	unsigned char ld_vboundary;
	unsigned char ld_vinitphase1;
	unsigned char ld_vinitphase2;
	unsigned char ld_vinitphase3_left;

	unsigned char ld_blight_update_en;
	unsigned char ld_blight_sw_mode;
	unsigned char ld_table_sw_mode;

	unsigned char ld_htabsel_0;
	unsigned char ld_htabsel_1;
	unsigned char ld_htabsel_2;
	unsigned char ld_htabsel_3;
	unsigned char ld_htabsel_4;
	unsigned char ld_htabsel_5;
	unsigned char ld_htabsel_6;
	unsigned char ld_htabsel_7;
	unsigned char ld_htabsel_8;
	unsigned char ld_htabsel_9;
	unsigned char ld_htabsel_10;
	unsigned char ld_htabsel_11;
	unsigned char ld_htabsel_12;
	unsigned char ld_htabsel_13;
	unsigned char ld_htabsel_14;
	unsigned char ld_htabsel_15;
	unsigned char ld_htabsel_16;
	unsigned char ld_htabsel_17;
	unsigned char ld_htabsel_18;
	unsigned char ld_htabsel_19;
	unsigned char ld_htabsel_20;
	unsigned char ld_htabsel_21;
	unsigned char ld_htabsel_22;
	unsigned char ld_htabsel_23;
	unsigned char ld_htabsel_24;
	unsigned char ld_htabsel_25;
	unsigned char ld_htabsel_26;
	unsigned char ld_htabsel_27;
	unsigned char ld_htabsel_28;
	unsigned char ld_htabsel_29;
	unsigned char ld_htabsel_30;
	unsigned char ld_htabsel_31;
	unsigned char ld_vtabsel_0;
	unsigned char ld_vtabsel_1;
	unsigned char ld_vtabsel_2;
	unsigned char ld_vtabsel_3;
	unsigned char ld_vtabsel_4;
	unsigned char ld_vtabsel_5;
	unsigned char ld_vtabsel_6;
	unsigned char ld_vtabsel_7;
	unsigned char ld_vtabsel_8;
	unsigned char ld_vtabsel_9;
	unsigned char ld_vtabsel_10;
	unsigned char ld_vtabsel_11;
	unsigned char ld_vtabsel_12;
	unsigned char ld_vtabsel_13;
	unsigned char ld_vtabsel_14;
	unsigned char ld_vtabsel_15;
	unsigned char ld_vtabsel_16;
	unsigned char ld_vtabsel_17;
	unsigned char ld_vtabsel_18;
	unsigned char ld_vtabsel_19;
	unsigned char ld_vtabsel_20;
	unsigned char ld_vtabsel_21;
	unsigned char ld_vtabsel_22;
	unsigned char ld_vtabsel_23;
	unsigned char ld_vtabsel_24;
	unsigned char ld_vtabsel_25;
	unsigned char ld_vtabsel_26;
	unsigned char ld_vtabsel_27;
	unsigned char ld_vtabsel_28;
	unsigned char ld_vtabsel_29;
	unsigned char ld_vtabsel_30;
	unsigned char ld_vtabsel_31;
} DRV_LD_Backlight_Profile_Interpolation;

typedef struct {
	unsigned char ld_demo_en;
	unsigned char ld_demo_mode;
	unsigned short ld_demo_top;
	unsigned short ld_demo_bottom;
	unsigned short ld_demo_left;
	unsigned short ld_demo_right;
} DRV_LD_Demo_Window;

typedef struct {
	DRV_LD_Global_Ctrl LD_Global_Ctrl;
	DRV_LD_Backlight_Decision LD_Backlight_Decision;
	DRV_LD_Spatial_Filter LD_Spatial_Filter;
	DRV_LD_Spatial_Remap LD_Spatial_Remap;
	DRV_LD_Boost LD_Boost;
	DRV_LD_Temporal_Filter LD_Temporal_Filter;
	DRV_LD_Backlight_Final_Decision LD_Backlight_Final_Decision;
	DRV_LD_Data_Compensation LD_Data_Compensation;
	DRV_LD_Backlight_Profile_Interpolation LD_Backlight_Profile_Interpolation;
	DRV_LD_Demo_Window LD_Demo_Window;

} DRV_Local_Dimming_Table;

typedef struct {
	unsigned char ctrlMode;
	unsigned char bCtrl;
	unsigned short width;
	unsigned short height;

} DRV_HAL_VPQ_LED_LDCtrlDemoMode;

typedef enum {
	LED_ONOFF = 0,	// each led block flicker sequentially.
	LED_H_ONOFF_EXT,	// led horizontal moving box pattern on for external localdimming chip.
	LED_V_ONOFF_EXT,	// led vertical moving box pattern on for external localdimming chip.
	SPLIT_SCREEN,	// half of screen is made from white pattern, and show local dimming effect.
	DEMOTYPE_SIZE_MAX
} LOCALDIMMING_DEMO_TYPE_T;


typedef enum {
	HAL_BL_DIRECT_M = 0,
	HAL_BL_DIRECT_L,
	HAL_BL_EDGE_LED,
	HAL_BL_ALEF_LED,
	HAL_BL_OLED,
	HAL_BL_END,
} HAL_BACKLIGHT_TYPE_T;

typedef enum {
	HAL_LED_BAR_6 = 0,
	HAL_LED_BAR_12,
	HAL_LED_BAR_16,
	HAL_LED_BAR_20,
	HAL_LED_BAR_240,
	HAL_LED_BAR_MAX
} HAL_LED_BAR_TYPE_T;

typedef enum {
	HAL_LDIM_NONE			= 0,		/* Not support Local dimming.*/
	HAL_LDIM_INTERNAL		= 1,		/* Use internal Local dimming block.*/
	HAL_LDIM_EXTERNAL		= 2,		/* Use external Local dimming IC.*/
} HAL_LDIM_IC_T;

typedef enum {
	HAL_WCG_PANEL_LED				= 0,
	HAL_WCG_PANEL_LED_ULTRAHD		= 1,
	HAL_WCG_PANEL_OLED				= 2,
	HAL_WCG_PANEL_OLED_ULTRAHD		= 3
} HAL_WCG_PANEL_TYPE_T;

typedef struct {
	unsigned char hal_inch;				/* panel size			ex) 47, 55*/
	unsigned char hal_bl_type;			/* led backlight type		ex) alef, edge*/
	unsigned char hal_bar_type;			/* led bar type			ex) h6,h12, v12*/
	unsigned char hal_maker;			/* panel maker			ex) lgd, auo*/
	HAL_LDIM_IC_T hal_icType;	/* localdimming control type	ex) internal localdiming block*/
	HAL_WCG_PANEL_TYPE_T hal_panel_type;
} HAL_LED_PANEL_INFO_T;

/* RTK style for KADP_LED_DB_LUT_T*/
typedef struct {
	unsigned char hal_ld_maxgain;
	unsigned char hal_ld_avegain;
	unsigned char hal_ld_histshiftbit;
	unsigned char hal_ld_hist0gain;
	unsigned char hal_ld_hist1gain;
	unsigned char hal_ld_hist2gain;
	unsigned char hal_ld_hist3gain;
	unsigned char hal_ld_hist4gain;
	unsigned char hal_ld_hist5gain;
	unsigned char hal_ld_hist6gain;
	unsigned char hal_ld_hist7gain;
} KADP_LED_BACKLIGHT_DECISION;

typedef struct
{
	unsigned char hal_ld_spatialnewcoef00;
	unsigned char hal_ld_spatialnewcoef01;
	unsigned char hal_ld_spatialnewcoef02;
	unsigned char hal_ld_spatialnewcoef03;
	unsigned char hal_ld_spatialnewcoef04;
	unsigned char hal_ld_spatialnewcoef05;
	unsigned char hal_ld_spatialnewcoef10;
	unsigned char hal_ld_spatialnewcoef11;
	unsigned char hal_ld_spatialnewcoef12;
	unsigned char hal_ld_spatialnewcoef13;
	unsigned char hal_ld_spatialnewcoef14;
	unsigned char hal_ld_spatialnewcoef15;

} KADP_LED_SPATIAL_FILTER;

typedef struct {

	unsigned char hal_ld_tmp_pos0thd;
	unsigned char hal_ld_tmp_pos1thd;
	unsigned char hal_ld_tmp_posmingain;
	unsigned char hal_ld_tmp_posmaxgain;
	unsigned char hal_ld_tmp_neg0thd;
	unsigned char hal_ld_tmp_neg1thd;
	unsigned char hal_ld_tmp_negmingain;
	unsigned char hal_ld_tmp_negmaxgain;
	unsigned char hal_ld_tmp_maxdiff;
	unsigned char hal_ld_tmp_scenechangegain1;

} KADP_LED_TEMPORAL_FILTER;

typedef struct {
	unsigned char hal_ld_spatialremapen;
	unsigned short hal_ld_spatialremaptab[65];
} KADP_LED_REMAP_CURVE;

typedef struct {
	unsigned int hal_ld_comp_2Dtable[17][17];
} KADP_LED_DATA_COMP;

typedef struct
{
	unsigned char LD_UI_Index; //UI index
	KADP_LED_BACKLIGHT_DECISION hal_backlight_decision;
	KADP_LED_SPATIAL_FILTER hal_spatial_filter;
	KADP_LED_TEMPORAL_FILTER hal_temporal_filter;
	KADP_LED_REMAP_CURVE hal_remap_curve;
	KADP_LED_DATA_COMP hal_data_comp_table;
} KADP_LED_DB_LUT_T;



void drvif_color_set_LD_Enable(unsigned char enable);
void drvif_color_set_LD_Global_Ctrl(DRV_LD_Global_Ctrl *ptr);
void drvif_color_set_LD_Backlight_Decision(DRV_LD_Backlight_Decision *ptr);
void drvif_color_set_LD_Spatial_Filter(DRV_LD_Spatial_Filter *ptr);
void drvif_color_set_LD_Spatial_Remap(DRV_LD_Spatial_Remap *ptr);
void drvif_color_set_LD_Boost(DRV_LD_Boost *ptr);
void drvif_color_set_LD_Temporal_Filter(DRV_LD_Temporal_Filter *ptr);
void drvif_color_set_LD_Backlight_Final_Decision(DRV_LD_Backlight_Final_Decision *ptr);
void drvif_color_set_LD_Data_Compensation(DRV_LD_Data_Compensation *ptr);
void drvif_color_set_LD_Data_Compensation_NewMode_2DTable(DRV_LD_Data_Compensation_NewMode_2DTable *ptr);
void drvif_color_set_LD_Backlight_Profile_Interpolation(DRV_LD_Backlight_Profile_Interpolation *ptr);
void drvif_color_set_LD_BL_Profile_Interpolation_Table(unsigned int *ptr);
void drvif_color_set_LD_Demo_Window(DRV_LD_Demo_Window *ptr);
void drvif_color_set_LD_Backlight_Profile_Interpolation_Table(int ptr[6][4][20]);

void drvif_HAL_VPQ_LED_LDEnable(unsigned char bCtrl);
void drvif_HAL_VPQ_LED_LDEnablePixelCompensation(unsigned char bCtrl);
void drvif_HAL_VPQ_LED_LDCtrlDemoMode(DRV_HAL_VPQ_LED_LDCtrlDemoMode *ptr);
void drvif_HAL_VPQ_LED_LDCtrlSPI(unsigned char *LDCtrlSPI);
unsigned char drvif_color_get_LD_GetAPL_TV006(unsigned short *BLValue);

void drvif_color_Set_Local_Dimming_Full(unsigned char nValue);
void drvif_color_Set_Local_Dimming_Off(unsigned char nValue);
void drvif_color_Local_Dimming_Init(unsigned char nValue);

unsigned char drvif_color_get_LD_Enable(void);

#ifdef __cplusplus
}
#endif

#endif /* __LOCALDIMMING_H__*/


