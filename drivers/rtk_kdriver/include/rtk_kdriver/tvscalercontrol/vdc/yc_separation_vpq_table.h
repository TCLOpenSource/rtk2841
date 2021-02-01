
typedef enum _VPQ_INPUT_SRC_TYPE
{
	/* 0 */ INPUT_SRC_AV,
	/* 1 */ INPUT_SRC_TV,
	/* 2 */ INPUT_SRC_EXTV,
	/* 3 */ INPUT_SRC_MAX
}VPQ_INPUT_SRC_TYPE;

typedef enum _VPQ_YCDELAY_TYPE
{
	/* 0 */ YCDELAY_Y,
	/* 1 */ YCDELAY_CB,
	/* 2 */ YCDELAY_CR,
	/* 3 */ YCDELAY_NEW_Y,
	/* 4 */ YCDELAY_NEW_CB,
	/* 5 */ YCDELAY_NEW_CR,
	/* 6 */ YCDELAY_NEW_CKY,
	/* 7 */ YCDELAY_4FSC_Y,
	/* 8 */ YCDELAY_4FSC_CB,
	/* 9 */ YCDELAY_4FSC_CR,
	/* 10*/ YCDLEAY_MAX
}VPQ_YCDELAY_TYPE;

typedef enum _VPQ_YCSEP_STATUS
{
	/* 0 */ YCSEP_STATUS_1D,
	/* 1 */ YCSEP_STATUS_2D3D,
	/* 2 */ YCSEP_STATUS_MAX
}VPQ_YCSEP_STATUS;

typedef enum _VPQ_DCTI_TYPE
{
	/* 0 */ VPQ_DCTI_1D,
	/* 1 */ VPQ_DCTI_2D,
	/* 2 */ VPQ_DCTI_3D,
	/* 3 */ VPQ_DCTI_MAX
}VPQ_DCTI_TYPE;

typedef enum _VPQ_INPUT_FORMAT
{
	/* 0 */ FORMAT_NTSC,
	/* 1 */ FORMAT_PALM,
	/* 2 */ FORMAT_NTSC50,
	/* 3 */ FORMAT_PALN,
	/* 4 */ FORMAT_NTSC443,
	/* 5 */ FORMAT_PAL60,
	/* 6 */ FORMAT_PALI,
	/* 7 */ FORMAT_SECAM,
	/* 8 */ FORMAT_MAX
}VPQ_INPUT_FORMAT;

typedef enum _VPQ_TABLE
{
	/* 0  */ TABLE1,
	/* 1  */ TABLE2,
	/* 2  */ TABLE3,
	/* 3  */ TABLE4,
	/* 4  */ TABLE5,
	/* 5  */ TABLE6,
	/* 6  */ TABLE7,
	/* 7  */ TABLE8,
	/* 8  */ TABLE9,
	/* 9  */ TABLE10,
	/* 10 */ TABLE11,
	/* 11 */ TABLE12,
	/* 12 */ TABLE13,
	/* 13 */ TABLE14,
	/* 14 */ TABLE15,
	/* 15 */ TABLE16,
	/* 16 */ TABLE_MAX,
}VPQ_TABLE;

typedef enum _VPQ_PRJ_NUMBER
{
	/* 0 */ PRJ_NO_0,
	/* 1 */ PRJ_NO_1,
	/* 2 */ PRJ_NO_2,
	/* 3 */ PRJ_NO_3,
	/* 4 */ PRJ_NO_4,
	/* 5 */ PRJ_NUM_MAX
} VPQ_PRJ_NUMBER;

typedef enum _VPQ_PRJ_TABLE_ITEM
{
	/* 0 */ PRJ_TBL_IDX_DEALY,
	/* 1 */ PRJ_TBL_IDX_DIGITAL_FILTER,
	/* 2 */ PRJ_TBL_IDX_Y_EQ_FILTER,
	/* 3 */ PRJ_TBL_IDX_1D_TBL,
	/* 4 */ PRJ_TBL_IDX_2D_TBL,
	/* 5 */ PRJ_TBL_IDX_3D_TBL,
	/* 6 */ PRJ_TBL_IDX_3DDMA_TBL,
	/* 7 */ PRJ_TBL_IDX_2D_POSTP_ALPHA,
	/* 8 */ PRJ_TBL_IDX_3D_POSTP_ALPHA,
	/* 9 */ PRJ_TBL_ITEM_MAX
} VPQ_PRJ_TABLE_ITEM;

extern unsigned char VPQ_PRJ_TABLE_SEL[PRJ_NUM_MAX][PRJ_TBL_ITEM_MAX];
extern unsigned char VPQ_1D_TABLE_REMAPPING[INPUT_SRC_MAX][FORMAT_MAX];
extern unsigned char VPQ_2D_TABLE_REMAPPING[INPUT_SRC_MAX][FORMAT_MAX];
extern unsigned char VPQ_3D_TABLE_REMAPPING[INPUT_SRC_MAX][FORMAT_MAX];
extern unsigned char VPQ_CTI_TABLE_REMAPPING[VPQ_DCTI_MAX][INPUT_SRC_MAX][FORMAT_MAX];

/*===================================*/
/*========= VDTOP paramters =========*/
/*===================================*/
extern unsigned char VTOP_1D_HSYNC_START_TBL[INPUT_SRC_MAX][FORMAT_MAX][2];
extern unsigned char VTOP_2D_HSYNC_START_TBL[INPUT_SRC_MAX][FORMAT_MAX][2];
extern unsigned char VTOP_3D_HSYNC_START_TBL[INPUT_SRC_MAX][FORMAT_MAX][2];

/*=================================================*/
/*========= POST-PROC. Alpha_Weight Table =========*/
/*=================================================*/
extern unsigned char VPQ_2D_POSTP_ALPHAWEI_SET[PRJ_NUM_MAX][INPUT_SRC_MAX][FORMAT_MAX][19];
extern unsigned char VPQ_3D_POSTP_ALPHAWEI_SET[PRJ_NUM_MAX][INPUT_SRC_MAX][FORMAT_MAX][19];

extern unsigned int VPQ_Y_EQ_FILTER[PRJ_NUM_MAX][2][41];
extern unsigned char VPQ_YCBCR_DELAY_TABLE[PRJ_NUM_MAX][YCSEP_STATUS_MAX][INPUT_SRC_MAX][FORMAT_MAX][YCDLEAY_MAX];
extern unsigned char VPQ_FRONT_DIGITAL_FILTER[PRJ_NUM_MAX][YCSEP_STATUS_MAX][FORMAT_MAX][INPUT_SRC_MAX][5];
extern unsigned char VPQ_POSTP_CTI_SET1[18];
extern unsigned char VPQ_POSTP_CTI_SET2[18];
extern unsigned char VPQ_POSTP_CTI_SET3[18];
extern unsigned char VPQ_POSTP_CTI_SET4[18];
extern unsigned char VPQ_POSTP_CTI_SET5[18];

/*======================================================================*/
/*============================== 1D Table ==============================*/
/*======================================================================*/
#define VPQ_SETTING_MAX 256
extern unsigned int VPQ_1D_SET1[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_1D_SET2[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_1D_SET3[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_1D_SET4[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_1D_SET5[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_1D_SET6[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_1D_SET7[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_1D_SET8[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_1D_SET9[PRJ_NUM_MAX][VPQ_SETTING_MAX];

/*======================================================================*/
/*============================== 2D Table ==============================*/
/*======================================================================*/
extern unsigned int VPQ_2D_SET1[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET2[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET3[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET4[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET5[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET6[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET7[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET8[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET9[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET10[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET11[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET12[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET13[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET14[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET15[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_2D_SET16[PRJ_NUM_MAX][VPQ_SETTING_MAX];

/*======================================================================*/
/*============================== 3D Table ==============================*/
/*======================================================================*/
extern unsigned int VPQ_3DDMA_SET1[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET2[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET3[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET4[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET5[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET6[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET7[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET8[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET9[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET10[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET11[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET12[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET13[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET14[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET15[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3DDMA_SET16[PRJ_NUM_MAX][VPQ_SETTING_MAX];

extern unsigned int VPQ_3D_SET1[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET2[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET3[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET4[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET5[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET6[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET7[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET8[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET9[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET10[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET11[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET12[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET13[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET14[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET15[PRJ_NUM_MAX][VPQ_SETTING_MAX];
extern unsigned int VPQ_3D_SET16[PRJ_NUM_MAX][VPQ_SETTING_MAX];

