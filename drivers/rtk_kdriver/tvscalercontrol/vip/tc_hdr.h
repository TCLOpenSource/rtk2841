/* 20160608 Still Logo Detect header file*/
#ifndef  __TCHDR_H__
#define  __TCHDR_H__

#ifdef __cplusplus
extern "C" {
#endif
/* some include about scaler*/
#if CONFIG_FIRMWARE_IN_KERNEL
#include <scalercommon/vipCommon.h>
#else
#include <scaler/vipCommon.h>
#endif

#define TC_Table_NUM 5
#if 1//juwen, 170216, TCv1.3.0_computeMetaData
#define Min(a, b)   ( ((a) < (b)) ? (a) : (b) )
#define Max(a, b)   ( ((a) < (b)) ? (b) : (a) )
#define CLAMP(v, a, b)  ((v < a)? a: ((v > b)? b: v))
#define YUV_FULL_RANGE    1
#define YUV_LIMITED_RANGE 0
#define BT1886 0
#define PQ     1
#define BT709  2
#define ARIB   3
#define HDR2MDR 1
#define SDR2MDR 2
#define sdrDisplayLuminance 100
#define INT32_MIN -2147483648
#define INT32_MAX 2147483647
enum { SHIFT = 16 };
enum { ONE = 1 << SHIFT };
enum { HALF = 1 << (SHIFT - 1) };

#define TCHDR_COEF_C_LUT_TBL_SIZE 33
#define TCHDR_COEF_I_LUT_TBL_SIZE 33
#define TCHDR_COEF_S_LUT_TBL_SIZE 33
#define TCHDR_COEF_P_LUT_TBL_SIZE 33
#define TCHDR_COEF_D_LUT_RED_TBL_SIZE 33
#define TCHDR_COEF_D_LUT_GREEN_TBL_SIZE 33
#define TCHDR_COEF_D_LUT_BLUE_TBL_SIZE 33
#endif//juwen, 170216, TCv1.3.0_computeMetaData

typedef struct {
	unsigned char tchdr_tc_enable;
	unsigned char tchdr_certification_enable;
	unsigned char tchdr_tc_certification_bitout;

} DRV_TCHDR_enable;


typedef struct {
	unsigned short tchdr_footroom_int;
	unsigned short tchdr_l_headroom_int;
	unsigned short tchdr_c_headroom_int;
	unsigned short tchdr_inv_y_limited_range_ratio_int;
	unsigned short tchdr_inv_chroma_limited_range_ratio_int;
} DRV_TCHDR_RangeAdaption;



typedef struct {
	unsigned short tchdr_alpha_a;
	unsigned short tchdr_alpha_b;
} DRV_TCHDR_l_compute;

//C LUT-----------------------------------------
typedef struct {
	unsigned char tchdr_c_lut_rw_sel;
	unsigned char tchdr_c_lut_read_en;
	unsigned char tchdr_c_lut_write_en;
	unsigned char tchdr_c_lut_rw_addr;//read only
	unsigned short tchdr_c_wr_lut_data0;
	unsigned short tchdr_c_wr_lut_data1;
	unsigned short tchdr_c_rd_lut_data0;//read only
	unsigned short tchdr_c_rd_lut_data1;//read only

} DRV_TCHDR_C_lut;


//S LUT-----------------------------------------
typedef struct {
	unsigned char tchdr_s_lut_rw_sel;
	unsigned char tchdr_s_lut_read_en;
	unsigned char tchdr_s_lut_write_en;
	unsigned char tchdr_s_lut_rw_addr;//read only
	unsigned short tchdr_s_wr_lut_data0;
	unsigned short tchdr_s_wr_lut_data1;
	unsigned short tchdr_s_rd_lut_data0;//read only
	unsigned short tchdr_s_rd_lut_data1;//read only

} DRV_TCHDR_S_lut;

//I LUT-----------------------------------------
typedef struct {
	unsigned char tchdr_i_lut_rw_sel;
	unsigned char tchdr_i_lut_read_en;
	unsigned char tchdr_i_lut_write_en;
	unsigned char tchdr_i_lut_rw_addr;//read only
	unsigned short tchdr_i_wr_lut_data0;
	unsigned short tchdr_i_wr_lut_data1;
	unsigned short tchdr_i_rd_lut_data0;//read only
	unsigned short tchdr_i_rd_lut_data1;//read only

} DRV_TCHDR_I_lut;

//P LUT-----------------------------------------
typedef struct {
	unsigned char tchdr_p_lut_acc_sel;
	unsigned char tchdr_p_lut_rw_sel;

	unsigned char tchdr_p_lut_read_en;
	unsigned char tchdr_p_lut_write_en;

	unsigned char tchdr_p_lut_rw_addr;//read only
	unsigned char tchdr_p_lut_acc_ready;//read only

	unsigned char tchdr_p_hw_lut1_rd_acc;//read only
	unsigned char tchdr_p_fw_lut1_wr_acc;//read only
	unsigned char tchdr_p_fw_lut1_rd_acc;//read only
	unsigned char tchdr_p_hw_lut0_rd_acc;//read only
	unsigned char tchdr_p_fw_lut0_wr_acc;//read only
	unsigned char tchdr_p_fw_lut0_rd_acc;//read only

	unsigned short tchdr_p_wr_lut_data0;
	unsigned short tchdr_p_wr_lut_data1;

	unsigned short tchdr_p_rd_lut_data0;//read only
	unsigned short tchdr_p_rd_lut_data1;//read only

} DRV_TCHDR_P_lut;


//T compute-----------------------------------------
typedef struct {

	signed short tchdr_oct0;//????????????UNSIGN/SIGN??????????
	signed short tchdr_oct1;//????????????UNSIGN/SIGN??????????
	signed short tchdr_oct2;//????????????UNSIGN/SIGN??????????

} DRV_TCHDR_T_compute;

//M compute-----------------------------------------
typedef struct {

	signed short tchdr_oct3;//????????????UNSIGN/SIGN??????????
	signed short tchdr_oct4;//????????????UNSIGN/SIGN??????????
	signed short tchdr_oct5;//????????????UNSIGN/SIGN??????????
	signed short tchdr_oct6;//????????????UNSIGN/SIGN??????????

} DRV_TCHDR_M_compute;

//D LUT-----------------------------------------
typedef struct {
	unsigned char tchdr_dlut_step0;
	unsigned char tchdr_dlut_step1;
	unsigned char tchdr_dlut_step2;
	unsigned char tchdr_dlut_step3;

	unsigned char tchdr_dlut_threshold0;
	unsigned char tchdr_dlut_threshold1;
	unsigned char tchdr_dlut_threshold2;


} DRV_TCHDR_D_lut_step_thl;

//D LUT-----------------------------------------
typedef struct {
	unsigned char tchdr_d_lut_rw_sel;
	unsigned char tchdr_d_lut_rw_addr;//read only
	unsigned char tchdr_d_lut_read_en;
	unsigned char tchdr_d_lut_write_en;

	unsigned short tchdr_d_wr_lut_data0;//R
	unsigned short tchdr_d_wr_lut_data1;//R

	unsigned short tchdr_d_wr_lut_data2;//G
	unsigned short tchdr_d_wr_lut_data3;//G

	unsigned short tchdr_d_wr_lut_data4;//B
	unsigned short tchdr_d_wr_lut_data5;//B

	unsigned short tchdr_d_rd_lut_data0;//R,read only
	unsigned short tchdr_d_rd_lut_data1;//R,read only

	unsigned short tchdr_d_rd_lut_data2;//G,read only
	unsigned short tchdr_d_rd_lut_data3;//G,read only

	unsigned short tchdr_d_rd_lut_data4;//B,read only
	unsigned short tchdr_d_rd_lut_data5;//B,read only

} DRV_TCHDR_D_lut;


//Double Buffer Control-----------------------------------------
typedef struct {

	unsigned char tchdr_tc_db_en;
	unsigned char tchdr_tc_db_read_sel;
	unsigned char tchdr_tc_db_apply;

} DRV_TCHDR_double_buffer_ctrl;

#if 1//juwen, 170216, TCv1.3.0_computeMetaData
typedef struct _sl_hdr1_metadata_variables {
  int tmInputSignalBlackLevelOffset;
  int tmInputSignalWhiteLevelOffset;
  int shadowGain;
  int highlightGain;
  int midToneWidthAdjFactor;
  int tmOutputFineTuningNumVal;
  int tmOutputFineTuningX[10];
  int tmOutputFineTuningY[10];
  int saturationGainNumVal;
  int saturationGainX[6];
  int saturationGainY[6];
} sl_hdr1_metadata_variables;

typedef struct _sl_hdr1_metadata_tables {
  int luminanceMappingNumVal;
  int luminanceMappingX[33];
  int luminanceMappingY[33];
  int colourCorrectionNumVal;
  int colourCorrectionX[33];
  int colourCorrectionY[33];
  int chromaToLumaInjectionMuA;
  int chromaToLumaInjectionMuB;
} sl_hdr1_metadata_tables;

typedef struct _SL_HDR1_metadata {
  int specVersion;
  int payloadMode;
  int hdrPicColourSpace;
  int hdrMasterDisplayColourSpace;
  int hdrMasterDisplayMaxLuminance;
  int hdrMasterDisplayMinLuminance;
  int sdrPicColourSpace;
  int sdrMasterDisplayColourSpace;
  union
  {
    sl_hdr1_metadata_variables variables;
    sl_hdr1_metadata_tables tables;
  } u;
} SL_HDR1_metadata;

typedef struct {
	unsigned short tchdr_dlut_step0;
	unsigned short tchdr_dlut_step1;
	unsigned short tchdr_dlut_step2;
	unsigned short tchdr_dlut_step3;


} DRV_TCHDR_D_lut_step;


typedef struct {
	unsigned short tchdr_dlut_threshold0;
	unsigned short tchdr_dlut_threshold1;
	unsigned short tchdr_dlut_threshold2;


} DRV_TCHDR_D_lut_thl;

//D LUT--------------------------------------------------------
#define NUM_D_LUT_DEFAULT 45
#define TCHDR_SIZE_D_LUT 65

typedef struct {

	DRV_TCHDR_D_lut_step           TCHDR_v130_D_lut_step;
	DRV_TCHDR_D_lut_thl             TCHDR_v130_D_lut_thl;
	unsigned short 				    TCHDR_v130_COEF_D_Lut[TCHDR_SIZE_D_LUT];

} DRV_TCHDR_v130_D_Table_settings;


#endif//juwen, 161202, TCv1.2.2_computeMetaData



//pq_misc_table structure--------------------------------------------------------


typedef struct {
	DRV_TCHDR_enable					TCHDR_enable;
	DRV_TCHDR_RangeAdaption             TCHDR_RangeAdaption ;
	DRV_TCHDR_l_compute                     TCHDR_l_compute;
	DRV_TCHDR_T_compute                    TCHDR_T_compute;
	DRV_TCHDR_M_compute                   TCHDR_M_compute;
	DRV_TCHDR_D_lut_step_thl             TCHDR_D_lut_step_thl;

/*
	DRV_TCHDR_double_buffer_ctrl	        TCHDR_double_buffer_ctrl;

	DRV_TCHDR_C_lut                          TCHDR_C_lut
	DRV_TCHDR_S_lut                          TCHDR_S_lut
	DRV_TCHDR_I_lut                           TCHDR_I_lut
	DRV_TCHDR_P_lut                           TCHDR_P_lut
	DRV_TCHDR_D_lut                          TCHDR_D_lut
*/
} DRV_TCHDR_Table;


//C LUT--------------------------------------------------------
#define IDX_C_LUT 4
#define TCHDR_SIZE_C_LUT 65

typedef struct _DRV_TCHDR_COEF_C_lut {
	unsigned short TCHDR_COEF_C_Lut[IDX_C_LUT][TCHDR_SIZE_C_LUT];

} DRV_TCHDR_COEF_C_lut;


//I LUT--------------------------------------------------------
#define IDX_I_LUT 4
#define TCHDR_SIZE_I_LUT 65

typedef struct _DRV_TCHDR_COEF_I_lut {
	unsigned short TCHDR_COEF_I_Lut[IDX_I_LUT][TCHDR_SIZE_I_LUT];

} DRV_TCHDR_COEF_I_lut;


//S LUT--------------------------------------------------------
#define IDX_S_LUT 4
#define TCHDR_SIZE_S_LUT 65

typedef struct _DRV_TCHDR_COEF_S_lut {
	unsigned short TCHDR_COEF_S_Lut[IDX_S_LUT][TCHDR_SIZE_S_LUT];

} DRV_TCHDR_COEF_S_lut;


//P LUT--------------------------------------------------------
#define IDX_P_LUT 4
#define TCHDR_SIZE_P_LUT 65

typedef struct _DRV_TCHDR_COEF_P_lut {
	unsigned short TCHDR_COEF_P_Lut[IDX_P_LUT][TCHDR_SIZE_P_LUT];

} DRV_TCHDR_COEF_P_lut;

//D LUT--------------------------------------------------------
#define IDX_D_LUT 7
#define TCHDR_SIZE_D_LUT 65

typedef struct _DRV_TCHDR_COEF_D_lut {
	unsigned short TCHDR_COEF_D_Lut[IDX_D_LUT][TCHDR_SIZE_D_LUT];

}DRV_TCHDR_COEF_D_lut;

//FW ctrl items--------------------------------------------------------
typedef enum _VIP_TC_HDR_CTRL_ITEMS {
	TC_HDR_display_OETF = 0,
	TC_HDR_display_Brightness,
	TC_HDR_display_proc_mode,
	TC_HDR_display_yuv_range,
	VIP_TC_HDR_CTRL_ITEMS_MAX,

} VIP_TC_HDR_CTRL_ITEMS;

typedef struct _DRV_TC_HDR_CTRL {
	int Enable;
	int TC_CTRL[VIP_TC_HDR_CTRL_ITEMS_MAX];

	int TC_Debug_Log;
	int TC_Debug_Delay;

} DRV_TC_HDR_CTRL;


void drvif_color_set_TC_Enable(unsigned char enable);
void drvif_color_set_TC_certification_Enable(unsigned char certification_enable,unsigned char certification_bitout);
void drvif_color_set_TC_Range_Adaptation(DRV_TCHDR_RangeAdaption *ptr);
void drvif_color_set_TC_L_Compute(DRV_TCHDR_l_compute *ptr);
void drvif_color_set_TC_T_Compute(DRV_TCHDR_T_compute *ptr);
void drvif_color_set_TC_M_Compute(DRV_TCHDR_M_compute *ptr);

void drvif_color_set_TC_Write_C_LUT(unsigned short *ptr);
void drvif_color_set_TC_Read_C_LUT(unsigned int *read_reg_ptr);

void drvif_color_set_TC_Write_I_LUT(unsigned short *ptr);
void drvif_color_set_TC_Read_I_LUT(unsigned int *read_reg_ptr);


void drvif_color_set_TC_Write_S_LUT(unsigned short *ptr);
void drvif_color_set_TC_Read_S_LUT(unsigned int *read_reg_ptr);


char drvif_color_set_TC_Write_P_LUT(unsigned short *ptr);
char drvif_color_set_TC_Read_P_LUT(unsigned int *read_reg_ptr);

void decode_TC_Read_LUTs_regValue(unsigned int *p_regArray, unsigned short *p_C_LUT_coff);//(input, output)


void drvif_color_set_TC_D_LUT_Step_Threshold(DRV_TCHDR_D_lut_step_thl *ptr);
void drvif_color_set_TC_Read_D_LUT(unsigned int *read_reg_ptr_R, unsigned int *read_reg_ptr_G, unsigned int *read_reg_ptr_B);
void drvif_color_set_TC_Write_D_LUT(unsigned short *ptr_R, unsigned short *ptr_G, unsigned short *ptr_B);

DRV_TC_HDR_CTRL* drvif_fwif_color_Get_TC_CTRL(void);

void drvif_fwif_color_set_TC_Enable(unsigned char src_idx, bool enable);
//read
void drvif_fwif_color_set_TC_Read_C_LUT(unsigned short *c_lut_coef_read_ptr);
void drvif_fwif_color_set_TC_Read_I_LUT(unsigned short *i_lut_coef_read_ptr);
void drvif_fwif_color_set_TC_Read_S_LUT(unsigned short *s_lut_coef_read_ptr);
void drvif_fwif_color_set_TC_Read_P_LUT(unsigned short *p_lut_coef_read_ptr);
void drvif_fwif_color_set_TC_Read_D_LUT(unsigned short *d_lut_red_coef_read_ptr,unsigned short *d_lut_green_coef_read_ptr,unsigned short *d_lut_blue_coef_read_ptr);
//write
void drvif_fwif_color_set_TC_v130_Range_Adaptation(unsigned char src_idx, unsigned char TableIdx);
void drvif_fwif_color_set_TC_v130_Compute_muA_muB(SL_HDR1_metadata *sl_hdr1_metadata, unsigned short *muA, unsigned short *muB);
void drvif_fwif_color_set_TC_v130_L_Compute(unsigned short *muA, unsigned short *muB);
void drvif_fwif_color_set_TC_v130_T_Compute(signed short  *OCT);
void drvif_fwif_color_set_TC_v130_M_Compute(signed short  *OCT);

void drvif_fwif_color_set_TC_v130_Compute_C_LUT(int proc_mode, SL_HDR1_metadata *sl_hdr1_metadata, int TargetDisplayLuminance, unsigned short *C_LUT);
void drvif_fwif_color_set_TC_v130_Compute_P_LUT(int proc_mode, SL_HDR1_metadata *sl_hdr1_metadata, int TargetDisplayLuminance, unsigned short *P_LUT);
void drvif_fwif_color_set_TC_v130_Write_C_LUT(unsigned short *C_LUT);
void drvif_fwif_color_set_TC_v130_Write_P_LUT(unsigned short *P_LUT);
void drvif_fwif_color_set_TC_v130_Fill_D_LUT(int proc_mode, int curve, int MaxTargetDisplayLum, unsigned short *D_LUT, unsigned short *D_LUT_THRESHOLD, unsigned short *D_LUT_STEP);
void drvif_fwif_color_set_TC_v130_Write_D_LUT(unsigned short *D_LUT);
void drvif_fwif_color_set_TC_v130_D_LUT_Step_Threshold(unsigned short *D_LUT_THRESHOLD, unsigned short *D_LUT_STEP);

void drvif_fwif_color_set_TC_v130_Write_I_LUT(unsigned char src_idx,unsigned char I_lut_idx);
void drvif_fwif_color_set_TC_v130_Write_S_LUT(unsigned char src_idx,unsigned char S_lut_idx);

void drvif_fwif_color_set_TC_v130_HW_setting_call_Each_Frame(
	//struct sl_hdr1_metadata *sl_hdr1_metadata,
	unsigned short *muA,
	unsigned short *muB,
	signed short  *OCT,
	unsigned short *C_LUT,
	unsigned short *P_LUT,
	unsigned short *D_LUT,
	unsigned short *D_LUT_THRESHOLD,
	unsigned short *D_LUT_STEP,
 	int yuv_range,
    int      *p_RGB2YUV_i     // Input, pointer to p_RGB2YUV_i matrix
);


void drvif_fwif_color_set_TC_v130_HW_setting_init(
	//struct sl_hdr1_metadata *sl_hdr1_metadata,
	unsigned short *muA,
	unsigned short *muB,
	signed short  *OCT,
	unsigned short *C_LUT,
	unsigned short *P_LUT,
	unsigned short *D_LUT,
	unsigned short *D_LUT_THRESHOLD,
	unsigned short *D_LUT_STEP,
 	int yuv_range,
    int      *p_RGB2YUV_i     // Input, pointer to p_RGB2YUV_i matrix
);

#ifdef __cplusplus
}
#endif

#endif // __TCHDR_H__


