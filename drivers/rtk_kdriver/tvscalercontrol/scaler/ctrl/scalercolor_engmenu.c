/*******************************************************************************
* @file    scalerColor_engineermenu.c
* @brief
* @note    Copyright (c) 2017 RealTek Technology Co., Ltd.
*		   All rights reserved.
*		   No. 2, Innovation Road II,
*		   Hsinchu Science Park,
*		   Hsinchu 300, Taiwan
*
* @log
* Revision 0.1	2017/01/19
* create
*******************************************************************************/
/*******************************************************************************
 * Header include
******************************************************************************/

#include <tvscalercontrol/scaler/scalercolor_engmenu.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/vdc/yc_separation_vpq.h>
#include <scalercommon/scalerCommon.h>

HAL_VPQ_ENG_SIZE ENG_size = {
	HAL_VPQ_ENG_ITEM_MAX_NUM, HAL_VPQ_ENG_ID_MAX_NUM
};

HAL_VPQ_ENG_STRUCT ENG_STRUCT = {
	{	//ENG_ITEM_STRUCT
		{HAL_VPQ_ENG_VIP_QUALITY_Coef,		"Coef",	},
		{HAL_VPQ_ENG_VIP_QUALITY_Extend_Coef,	"Extend_Coef"},
		{HAL_VPQ_ENG_OTHER,			"Others", },
	},
	{	//ENG_ID_STRUCT
		{HAL_VPQ_ENG_VIP_QUALITY_Coef,		HAL_VPQ_ENG_DLTi,									"DLTi",		HAL_VPQ_ENG_scrollbox,	0,	255,	{0},},
		{HAL_VPQ_ENG_VIP_QUALITY_Coef,		HAL_VPQ_ENG_DCTi,									"DCTi",		HAL_VPQ_ENG_scrollbox,	0,	255,	{0},},
		{HAL_VPQ_ENG_VIP_QUALITY_Extend_Coef,	HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_ENG_CDS,						"CDS",		HAL_VPQ_ENG_scrollbox,	0,	255,	{0},},
		{HAL_VPQ_ENG_VIP_QUALITY_Extend_Coef,	HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_ENG_EMFMK2i,						"EMFMK2",	HAL_VPQ_ENG_scrollbox,	0,	255,	{0},},
		{HAL_VPQ_ENG_VIP_QUALITY_Extend_Coef,	HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_ENG_LC_DEMO_MODE,					"LC_MODE",	HAL_VPQ_ENG_scrollbox,	0,	5,		{0},},
		{HAL_VPQ_ENG_OTHER,			(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)+HAL_VPQ_ENG_OD_EN_TEST,	"OD_EN_TEST",	HAL_VPQ_ENG_combobox,	0,	1,		{{"OFF"},{"ON"}},},
		{HAL_VPQ_ENG_OTHER,			(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)+HAL_VPQ_ENG_OD_BIT_TEST,	"OD_BIT_TEST",	HAL_VPQ_ENG_scrollbox,	0,	7,		{0},},
		{HAL_VPQ_ENG_OTHER,			(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)+HAL_VPQ_ENG_VDPQ_PRJ_ID,	"VDPQ_Style",	HAL_VPQ_ENG_scrollbox,	0,	7,		{0},},
		{HAL_VPQ_ENG_OTHER,			(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)+HAL_VPQ_ENG_PQ_TABLE_BIN_EN,	"PQ Table load",	HAL_VPQ_ENG_combobox,	0,	1,		{{"not_bin"},{"bin"}},},
	},
};

HAL_VPQ_ENG_TWOLAYER_STRUCT ENG_TWOLAYER_STRUCT = {
	{	//ENG_ITEM_STRUCT
		{HAL_VPQ_ENG_VIP_QUALITY_Coef,		"Coef",		HAL_VPQ_Coef_ID_MAX_NUM},
		{HAL_VPQ_ENG_VIP_QUALITY_Extend_Coef,	"Extend_Coef", 	HAL_VPQ_Extend_Coef_ID_MAX_NUM},
		{HAL_VPQ_ENG_OTHER,			"Others", 	HAL_VPQ_OTHER_ID_MAX_NUM},
	},
	{	//ENG_ID_STRUCT
		{HAL_VPQ_ENG_VIP_QUALITY_Coef,		HAL_VPQ_ENG_DLTi,		"DLTi",			HAL_VPQ_ENG_scrollbox,	0,	255,	{0},},
		{HAL_VPQ_ENG_VIP_QUALITY_Coef,		HAL_VPQ_ENG_DCTi,		"DCTi",			HAL_VPQ_ENG_scrollbox,	0,	255,	{0},},
		{HAL_VPQ_ENG_VIP_QUALITY_Extend_Coef,	HAL_VPQ_ENG_CDS,		"CDS",			HAL_VPQ_ENG_scrollbox,	0,	255,	{0},},
		{HAL_VPQ_ENG_VIP_QUALITY_Extend_Coef,	HAL_VPQ_ENG_EMFMK2i,		"EMFMK2",		HAL_VPQ_ENG_scrollbox,	0,	255,	{0},},
		{HAL_VPQ_ENG_VIP_QUALITY_Extend_Coef,	HAL_VPQ_ENG_LC_DEMO_MODE,	"LC_MODE",		HAL_VPQ_ENG_scrollbox,	0,	5,		{0},},
		{HAL_VPQ_ENG_OTHER,			HAL_VPQ_ENG_OD_EN_TEST,		"OD_EN_TEST",		HAL_VPQ_ENG_combobox,	0,	1,		{{"OFF"},{"ON"}},},
		{HAL_VPQ_ENG_OTHER,			HAL_VPQ_ENG_OD_BIT_TEST,	"OD_BIT_TEST",		HAL_VPQ_ENG_scrollbox,	0,	7,		{0},},
		{HAL_VPQ_ENG_OTHER,			HAL_VPQ_ENG_VDPQ_PRJ_ID,	"VDPQ_Style",		HAL_VPQ_ENG_scrollbox,	0,	7,		{0},},
		{HAL_VPQ_ENG_OTHER,			HAL_VPQ_ENG_PQ_TABLE_BIN_EN,		"PQ Table load",	HAL_VPQ_ENG_combobox,	0,	1,		{{{"not_bin"}},{{"bin"}}},},
	},
};


/*==================Singal Layer============================================*/

HAL_VPQ_ENG_STRUCT* Scaler_Get_ENGMENU(void)
{
	return &ENG_STRUCT;
}


HAL_VPQ_ENG_SIZE* Scaler_Get_ENGMENU_size(void)
{
	return &ENG_size;
}

unsigned int Scaler_Get_ENGMENU_ID(unsigned int ID)
{
	unsigned int ret = 0;
	switch (ID) {
		case HAL_VPQ_ENG_DLTi:
			ret = (unsigned int)Scaler_GetDLti();
			break;
		case HAL_VPQ_ENG_DCTi:
			ret = (unsigned int)Scaler_GetDCti();
			break;
		case (HAL_VPQ_ENG_CDS+HAL_VPQ_Coef_ID_MAX_NUM):
			ret = (unsigned int)Scaler_GetCDSTable();
			break;
		case (HAL_VPQ_ENG_EMFMK2i+HAL_VPQ_Coef_ID_MAX_NUM):
			ret = (unsigned int)Scaler_GetEMF_Mk2();
			break;
		case (HAL_VPQ_ENG_LC_DEMO_MODE+HAL_VPQ_Coef_ID_MAX_NUM):
			ret = (unsigned int)Scaler_IamLC_DemoFunction(255);
			break;
		case (HAL_VPQ_ENG_OD_EN_TEST+(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)):
			ret = Scaler_Get_OD_Enable();
			break;
		case (HAL_VPQ_ENG_OD_BIT_TEST+(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)):
			ret = Scaler_Get_OD_Bits();
			break;
		case (HAL_VPQ_ENG_VDPQ_PRJ_ID+(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)):
			ret = drvif_module_vpq_get_ProjectId();
			break;
		case (HAL_VPQ_ENG_PQ_TABLE_BIN_EN+(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)):
			ret = Scaler_Get_PQ_table_bin_En();
			break;
	}

	return ret;
}

unsigned int Scaler_Set_ENGMENU_ID(unsigned int ID, int value)
{
	unsigned int ret = 0;
	switch (ID) {
		case HAL_VPQ_ENG_DLTi:
			Scaler_SetDLti((unsigned char)value);
			break;
		case HAL_VPQ_ENG_DCTi:
			Scaler_SetDCti((unsigned char)value);
			break;
		case (HAL_VPQ_ENG_CDS+HAL_VPQ_Coef_ID_MAX_NUM):
			Scaler_SetCDSTable((unsigned char)value);
			break;
		case (HAL_VPQ_ENG_EMFMK2i+HAL_VPQ_Coef_ID_MAX_NUM):
			Scaler_SetEMF_Mk2((unsigned char)value);
			break;
		case (HAL_VPQ_ENG_LC_DEMO_MODE+HAL_VPQ_Coef_ID_MAX_NUM):
			ret = (unsigned int)Scaler_IamLC_DemoFunction(value);
			break;
		case (HAL_VPQ_ENG_OD_EN_TEST+(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)):
			ret = Scaler_OD_Test(value);
			break;
		case (HAL_VPQ_ENG_OD_BIT_TEST+(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)):
			ret = Scaler_Set_OD_Bits(value);
			break;
		case (HAL_VPQ_ENG_VDPQ_PRJ_ID+(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)):
			ret = drvif_module_vpq_set_ProjectId(value);
			drvif_module_vpq_SetYcSep(VDC_YCSEPARATE_DEFAULT);
			break;
		case (HAL_VPQ_ENG_PQ_TABLE_BIN_EN+(HAL_VPQ_Coef_ID_MAX_NUM+HAL_VPQ_Extend_Coef_ID_MAX_NUM)):
			break;
	}

	return ret;
}
/*===================================================================*/


/*==================Two Layer============================================*/
HAL_VPQ_ENG_TWOLAYER_STRUCT* Scaler_Get_ENG_TWOLAYER_MENU(void)
{
	return &ENG_TWOLAYER_STRUCT;
}

unsigned int Scaler_Get_VIP_QUALITY_Coef_ID(unsigned int ID)
{
	unsigned int ret = 0;
	switch (ID) {
		case HAL_VPQ_ENG_DLTi:
			ret = (unsigned int)Scaler_GetDLti();
			break;
		case HAL_VPQ_ENG_DCTi:
			ret = (unsigned int)Scaler_GetDCti();
			break;
	}
	return ret;
}

unsigned int Scaler_Get_VIP_QUALITY_Extend_Coef_ID(unsigned int ID)
{
	unsigned int ret = 0;
	switch (ID) {
		case HAL_VPQ_ENG_CDS:
			ret = (unsigned int)Scaler_GetCDSTable();
			break;
		case HAL_VPQ_ENG_EMFMK2i:
			ret = (unsigned int)Scaler_GetEMF_Mk2();
			break;
		case HAL_VPQ_ENG_LC_DEMO_MODE:
			ret = (unsigned int)Scaler_GetIamLC_DemoFunction();
			break;
	}
	return ret;
}

unsigned int Scaler_Get_ENG_OTHER_ID(unsigned int ID)
{
	unsigned int ret = 0;
	switch (ID) {
		case HAL_VPQ_ENG_OD_EN_TEST:
			ret = Scaler_Get_OD_Enable();
			break;
		case HAL_VPQ_ENG_OD_BIT_TEST:
			ret = Scaler_Get_OD_Bits();
			break;
		case HAL_VPQ_ENG_VDPQ_PRJ_ID:
			ret = drvif_module_vpq_get_ProjectId();
			break;
		case HAL_VPQ_ENG_PQ_TABLE_BIN_EN:
			ret = Scaler_Get_PQ_table_bin_En();
			break;
	}
	return ret;
}

unsigned int Scaler_Get_ENG_TWOLAYER_MENU_ID(unsigned int ITEM, unsigned int ID)
{
	unsigned int ret = 0;
	switch (ITEM){
		case HAL_VPQ_ENG_VIP_QUALITY_Coef:
			ret = Scaler_Get_VIP_QUALITY_Coef_ID(ID);
			break;
		case HAL_VPQ_ENG_VIP_QUALITY_Extend_Coef:
			ret = Scaler_Get_VIP_QUALITY_Extend_Coef_ID(ID);
			break;
		case HAL_VPQ_ENG_OTHER:
			ret = Scaler_Get_ENG_OTHER_ID(ID);
			break;
	}
	return ret;
}

unsigned int Scaler_Set_VIP_QUALITY_Coef_ID(unsigned int ID, int value)
{
	unsigned int ret = 0;
	switch (ID) {
		case HAL_VPQ_ENG_DLTi:
			Scaler_SetDLti((unsigned char)value);
			break;
		case HAL_VPQ_ENG_DCTi:
			Scaler_SetDCti((unsigned char)value);
			break;
	}
	return ret;
}
unsigned int Scaler_Set_VIP_QUALITY_Extend_Coef_ID(unsigned int ID, int value)
{
	unsigned int ret = 0;
	switch (ID) {
		case HAL_VPQ_ENG_CDS:
			Scaler_SetCDSTable((unsigned char)value);
			break;
		case HAL_VPQ_ENG_EMFMK2i:
			Scaler_SetEMF_Mk2((unsigned char)value);
			break;
		case HAL_VPQ_ENG_LC_DEMO_MODE:
			ret = (unsigned int)Scaler_IamLC_DemoFunction(value);
			break;
	}
	return ret;
}

unsigned int Scaler_Set_ENG_OTHER_ID(unsigned int ID, int value)
{
	unsigned int ret = 0;
	switch (ID) {
		case HAL_VPQ_ENG_OD_EN_TEST:
			ret = Scaler_OD_Test(value);
			break;
		case HAL_VPQ_ENG_OD_BIT_TEST:
			ret = Scaler_Set_OD_Bits(value);
			break;
		case HAL_VPQ_ENG_VDPQ_PRJ_ID:
			ret = drvif_module_vpq_set_ProjectId(value);
			drvif_module_vpq_SetYcSep(VDC_YCSEPARATE_DEFAULT);
			break;
		case HAL_VPQ_ENG_PQ_TABLE_BIN_EN:
			break;
	}
	return ret;
}

unsigned int Scaler_Set_ENG_TWOLAYER_MENU_ID(unsigned int ITEM, unsigned int ID, int value)
{
	unsigned int ret = 0;
	switch (ITEM) {
		case HAL_VPQ_ENG_VIP_QUALITY_Coef:
			Scaler_Set_VIP_QUALITY_Coef_ID(ID, value);
			break;
		case HAL_VPQ_ENG_VIP_QUALITY_Extend_Coef:
			Scaler_Set_VIP_QUALITY_Extend_Coef_ID(ID, value);
			break;
		case HAL_VPQ_ENG_OTHER:
			Scaler_Set_ENG_OTHER_ID(ID, value);
			break;
	}

	return ret;
}
/*==============================================================*/


