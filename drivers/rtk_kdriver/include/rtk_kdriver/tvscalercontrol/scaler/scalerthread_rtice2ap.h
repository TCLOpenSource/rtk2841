#ifndef __SCALERThread_rtice2AP_H__
#define __SCALERThread_rtice2AP_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <scalercommon/vipCommon.h>
#include <scalercommon/vipRPCCommon.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>

typedef struct {
unsigned short id;
unsigned int size;
unsigned int saddr;
unsigned int eaddr;
unsigned char mode0;
unsigned char mode1;
} ap_data_param;

typedef enum _VIP_TOOL_ACCESS_INFO_Item{

/*Basic OSD Control Item*/
	TOOLACCESS_Contrast = 0,
	TOOLACCESS_Brightness,
	TOOLACCESS_Saturation,
	TOOLACCESS_Hue,
/*Eng. menu item*/
	TOOLACCESS_VD_Contrast,
	TOOLACCESS_VD_Brightness,
	TOOLACCESS_VD_Saturation,
	TOOLACCESS_VD_Hue,
	TOOLACCESS_Gamma,
	TOOLACCESS_DCTI,
	TOOLACCESS_DLTI,
	TOOLACCESS_MADI_HMC,
	TOOLACCESS_MADI_HME,
	TOOLACCESS_MADI_PAN,
	TOOLACCESS_DI_MA_Adjust_Table,
	TOOLACCESS_DI_DiSmd,
	TOOLACCESS_TNRXC_Ctrl,
	TOOLACCESS_TNRXC_MK2,
	TOOLACCESS_ScaleUPH,
	TOOLACCESS_ScaleUPH_8tap,
	TOOLACCESS_ScaleUPV_6tap,
	TOOLACCESS_ScaleUPV,
	TOOLACCESS_ScaleUPDir,
	TOOLACCESS_ScaleUPDir_Weighting,
	TOOLACCESS_ScaleDOWN_H_Table,
	TOOLACCESS_ScaleDOWN_V_Table,
	TOOLACCESS_ScaleDOWN_444To422,
	TOOLACCESS_D_UVDelay_en,
	TOOLACCESS_D_UVDelay,
	TOOLACCESS_Pattern_Off,
	TOOLACCESS_Pattern_Red,
	TOOLACCESS_Pattern_Green,
	TOOLACCESS_Pattern_Blue,
	TOOLACCESS_Pattern_White,
	TOOLACCESS_Pattern_Black,
	TOOLACCESS_Pattern_Color_Bar,
	TOOLACCESS_Pattern_Gray_Bar,
	TOOLACCESS_Magic_Off,
	TOOLACCESS_SetMagic_Still_DEMO,
	TOOLACCESS_SetMagic_Still_DEMO_Inverse,
	TOOLACCESS_SetMagic_Dynamic_DEMO,
	TOOLACCESS_SetMagic_Move,
	TOOLACCESS_SetMagic_Move_Inverse,
	TOOLACCESS_SetMagic_Zoom,
	TOOLACCESS_SetMagic_Optimize,
	TOOLACCESS_SetMagic_Enhance,
	TOOLACCESS_VD_SetYC_Separation,
	TOOLACCESS_VD_Set3D_Table,
	TOOLACCESS_VD_Set2D_Chroma_BW_Low,
	TOOLACCESS_VD_SetSetDCTI_Table,
	TOOLACCESS_VD_Set2D_Table,
	TOOLACCESS_VD_SetNarrow_BPF_Y,
	TOOLACCESS_VD_SetWide_BPF_Y,
	TOOLACCESS_VD_SetWide_BPF_C,
	TOOLACCESS_VD_SetNarrow_BPF_C,
	TOOLACCESS_VD_SetVflag_Remg_Thr,
	TOOLACCESS_VD_SetVflag_Mag_Thr,
	TOOLACCESS_VD_SetY_Noise_Thr,
	TOOLACCESS_VD_SetNoise_Max_Hdy,
	TOOLACCESS_VD_SetNoise_Y_Add_DC,
	TOOLACCESS_VD_SetBlend_Ratio,
	TOOLACCESS_VD_SetTDma_Enable,
	TOOLACCESS_VD_SetTDma_Mode,
	TOOLACCESS_VD_SetDeb_Print,
	TOOLACCESS_VD_Set625_Mode,
	TOOLACCESS_VD_SetMV_Check,
	TOOLACCESS_VD_SetClamp_Mode,
	TOOLACCESS_VD_SetRc_Rate_Func,
	TOOLACCESS_VD_SetRc_Rate_Value,
	TOOLACCESS_VD_SetV_Clamp,
	TOOLACCESS_VD_SetClamp_Delay,
	TOOLACCESS_VD_SetClamp_Delay_Value,
	TOOLACCESS_VD_SetSetH_State_Write,
	TOOLACCESS_VD_SetHsync_Start,
	TOOLACCESS_VD_SetV_State_Write,
	TOOLACCESS_VD_SetV_Detect_Mode,
	TOOLACCESS_VD_SetVsync_Ctrl,
	TOOLACCESS_VD_SetC_State_W,
	TOOLACCESS_VD_SetAuto_BP,
	TOOLACCESS_VD_SetCkill_Mode,
	TOOLACCESS_VD_SetCkill_Value,
	TOOLACCESS_VD_SetSet_Dgain,
	TOOLACCESS_VD_SetFix_Dgain,
	TOOLACCESS_VD_SetSet_Cgain,
	TOOLACCESS_VD_SetFix_Cgain,
	TOOLACCESS_VD_Set27M_LPF,
	TOOLACCESS_VD_Set27M_Table,
	TOOLACCESS_VD_Set108M_LPF,
	TOOLACCESS_VD_SetSecam_F_sel,
	TOOLACCESS_VD_SetSecam2,
	TOOLACCESS_VD_Set443358pk_sel,
	TOOLACCESS_VD_Set443thr,
	TOOLACCESS_VD_Set358thr,
	TOOLACCESS_VD_SetSoft_Reset,
	TOOLACCESS_VD_PQ_SetBypassPQ,
	TOOLACCESS_VD_PQ_Set1D3D_Pos,
	TOOLACCESS_VD_PQ_SetContrast,
	TOOLACCESS_VD_PQ_SetBrightness,
	TOOLACCESS_VD_PQ_SetSaturation,
	TOOLACCESS_VD_PQ_SetYC_Delay,
	TOOLACCESS_VD_PQ_SetY1delay_En,
	TOOLACCESS_VD_PQ_SetCb1delay_En,
	TOOLACCESS_VD_PQ_SetCr1delay_En,
	TOOLACCESS_VD_PQ_SetY1delay,
	TOOLACCESS_VD_PQ_SetCb1delay,
	TOOLACCESS_VD_PQ_SetCr1delay,
	TOOLACCESS_VD_PQ_SetKill_Ydelay_En,
	TOOLACCESS_VD_PQ_SetKill_Ydelay,
	TOOLACCESS_VD_PQ_SetSCART_Con,
	TOOLACCESS_VD_PQ_SetSCART_Bri,
	TOOLACCESS_VD_PQ_SetSCART_Sat_cr,
	TOOLACCESS_VD_PQ_SetSCART_Sat_cb,


	TOOLACCESS_DCC_PQ_current_mean,	/*read only*/
	TOOLACCESS_DCC_PQ_current_dev,	/*read only*/
	TOOLACCESS_DCC_PQ_Level,
	TOOLACCESS_DCC_PQ_Cubic_index,
	TOOLACCESS_DCC_PQ_Cubic_low,
	TOOLACCESS_DCC_PQ_Cubic_high,

	TOOLACCESS_VIP_QUALITY_Coef,                 	/*20*/
	TOOLACCESS_VIP_QUALITY_Extend_Coef,           	/*21*/
	TOOLACCESS_VIP_QUALITY_Extend2_Coef,         	/*22*/
	TOOLACCESS_VIP_QUALITY_Extend3_Coef,        	/*23*/
	TOOLACCESS_tICM_ini,				  			/* 24*/
	TOOLACCESS_SHPTable,			  				/* 25*/
	TOOLACCESS_Hist_Y_Mean_Value,			  		/* 26*/
	TOOLACCESS_TABLE_NTSC_3D,			  			/* 28*/
	TOOLACCESS_MANUAL_NR,			  				/* 29*/
	/*TOOLACCESS_PQA_Input_Table,			 			*/ /* 30*/
	/*TOOLACCESS_PQA_Table,			  				*/ /* 31*/
	TOOLACCESS_SmartPic_clue_Motion_Cal,			/*32*/
	TOOLACCESS_SmartPic_clue_HSI_Histogram_Cal, 	/*33*/
	TOOLACCESS_SmartPic_clue_VD_Noise_Cal, 			/*34*/
	TOOLACCESS_ISR_Print_Ctrl,
	TOOLACCESS_xvYcc_mode,
	TOOLACCESS_BP_Function_CTRL,
	TOOLACCESS_BP_Function_TBL,
	TOOLACCESS_ADV_API_CTRL,
	TOOLACCESS_ADV_API_TBL,
	TOOLACCESS_DBC_STATUS,
	TOOLACCESS_DBC_SW_REG,

	TOOLACCESS_ICM_7axis_adjust,
	TOOLACCESS_switch_DVIandHDMI,
	TOOLACCESS_AutoMA_API_CTRL,

	TOOLACCESS_Debug_Buff_8,
	TOOLACCESS_Debug_Buff_16,
	TOOLACCESS_Debug_Buff_32,
	TOOLACCESS_Debug_HDR,		/* read only*/

	TOOLACCESS_MAX,
	/*==== from MacArthur3===*/
	TOOLACCESS_GetIdxTable_IDMax = 1024,
	TOOLACCESS_GetIdxTable_Type = 1025,
	TOOLACCESS_GetIdxTable_MaxNum = 1026,
	TOOLACCESS_GetIdxTable_StringName = 1027,


	/* For PQA*/
	TOOLACCESS_PQA_Table_Size = 1028,
	TOOLACCESS_PQA_Table = 1029,
	TOOLACCESS_PQA_Level_Table = 1030,
	TOOLACCESS_PQA_Level_Index_Table = 1031,
	TOOLACCESS_PQA_Input_Table = 1032,
	TOOLACCESS_PQA_FlowCtrl_Input_Type = 1033,
	TOOLACCESS_PQA_FlowCtrl_Input_Item = 1034,
	TOOLACCESS_PQA_SPM_Info_Get = 1035,

	TOOLACCESS_DCC_Curve_Control_Coef = 1100,
	TOOLACCESS_DCC_Boundary_check_Table = 1101,
	TOOLACCESS_DCC_Level_and_Blend_Coef_Table = 1102,/*(DCC_MISC)*/
	TOOLACCESS_DCC_Hist_Factor_Table = 1103,
	TOOLACCESS_DCC_AdaptCtrl_Level_Table = 1104,
	TOOLACCESS_DCC_AdaptCtrl_Param = 1105,

	TOOLACCESS_DCC_UserDef_Ctrl_TABLE = 1106,
	TOOLACCESS_DCC_UserDef_Curve_All_TABLE = 1107,
	TOOLACCESS_DCC_UserDef_Curve_Current_TABLE = 1108,
	TOOLACCESS_DCC_Database_Curve_CRTL_All_Table = 1109,
	TOOLACCESS_DCC_Database_Curve_CRTL_Curve_Current_Table = 1110,
	TOOLACCESS_DCC_Database_Curve_CRTL_Histogram_Current_Table = 1111,
	TOOLACCESS_DCC_Histogram_Curve = 1112,

	TOOLACCESS_DCC_S_Curve = 1113, 									/*read only*/
	TOOLACCESS_DCC_Histogram_Adjust = 1114,							/*read only*/
    	TOOLACCESS_DCC_APL = 1115,								/*read only*/
	TOOLACCESS_DCC_Apply_Curve = 1116,										/*read only*/
	TOOLACCESS_DCC_Curve_Boundary_Type = 1117,
	TOOLACCESS_DCC_Curve_Boundary = 1118,
	TOOLACCESS_DCC_panel_compensation_Curve = 1119,
	TOOLACCESS_DCC_DataBaseHistogrm = 1120,
	TOOLACCESS_DCC_Database_Curve_CRTL_User_Gain_Parameter_Current_Table = 1121,
	TOOLACCESS_VIP_DCC_Advance_Level_Control_Flag = 1122,
	TOOLACCESS_VIP_DCC_Advance_Level_Control_Step_DT_Table = 1123,
	TOOLACCESS_VIP_DCC_Identity_Condition_Check = 1124,

	TOOLACCESS_ICM_Global_Adjust = 1200,
	TOOLACCESS_ICM_BOX_Adjust = 1201,
	TOOLACCESS_ICM_ReadWrite_Buf = 1202,
	TOOLACCESS_ICM_ReadWrite_CurrentPrevious_Buf = 1203,

	TOOLACCESS_DisplayInformation_table = 1300, 						/*read only*/

	TOOLACCESS_YUV2RGB_Global_Sat_Gain = 1400,
	TOOLACCESS_YUV2RGB_Global_Hue_Gain = 1401,
	TOOLACCESS_YUV2RGB_Global_Contrast_Gain = 1402,
	TOOLACCESS_YUV2RGB_Global_Brightness_Gain = 1403,

	TOOLACCESS_Function_Coef_Dlti = 1500,
	TOOLACCESS_Function_Coef_Dcti = 1501,
	TOOLACCESS_Function_Coef_iDlti = 1502,
	TOOLACCESS_Function_Coef_iDcti = 1503,
	TOOLACCESS_Function_Coef_VDcti = 1504,
	TOOLACCESS_Function_Coef_UV_Delay_En = 1505,
	TOOLACCESS_Function_Coef_UV_Delay = 1506,
	TOOLACCESS_Function_Coef_YUV2RGB = 1507,
	TOOLACCESS_Function_Coef_Film_Mode = 1508,
	TOOLACCESS_Function_Coef_Intra = 1509,
	TOOLACCESS_Function_Coef_MA = 1510,
	TOOLACCESS_Function_Coef_TnrXC = 1511,
	TOOLACCESS_Function_Coef_Ma_Chroma_Error = 1512,
	TOOLACCESS_Function_Coef_NM_Level = 1513,
	TOOLACCESS_Function_Coef_Madi_Hme = 1514,
	TOOLACCESS_Function_Coef_Madi_Hmc = 1515,
	TOOLACCESS_Function_Coef_Madi_Pan = 1516,
	TOOLACCESS_Function_Coef_Di_Smd = 1517,
	TOOLACCESS_Function_Coef_Reserve18 = 1518,
	TOOLACCESS_Function_Coef_Reserve19 = 1519,
	TOOLACCESS_Function_Coef_Reserve20 = 1520,

	TOOLACCESS_Function_Extend_CDS = 1521,
	TOOLACCESS_Function_Extend_Emfmk2 = 1522,
	TOOLACCESS_Function_Extend_Skipir_Dering = 1523,
	TOOLACCESS_Function_Extend_Skipir_Dnoise = 1524,
	TOOLACCESS_Function_Extend_Dnoise_Table = 1525,
	TOOLACCESS_Function_Extend_Adatp_Gamma = 1526,
	TOOLACCESS_Function_Extend_LD_Ebabel = 1527,
	TOOLACCESS_Function_Extend_LD_Table_Select = 1528,
	TOOLACCESS_Function_Extend_Reserve08 = 1529,
	TOOLACCESS_Function_Extend_Reserve09 = 1530,
	TOOLACCESS_Function_Extend_Reserve10 = 1531,
	TOOLACCESS_Function_Extend_Reserve11 = 1532,
	TOOLACCESS_Function_Extend_Reserve12 = 1533,
	TOOLACCESS_Function_Extend_Reserve13 = 1534,
	TOOLACCESS_Function_Extend_Reserve14 = 1535,
	TOOLACCESS_Function_Extend_Reserve15 = 1536,
	TOOLACCESS_Function_Extend_Reserve16 = 1537,
	TOOLACCESS_Function_Extend_Reserve17 = 1538,
	TOOLACCESS_Function_Extend_Reserve18 = 1539,
	TOOLACCESS_Function_Extend_Reserve19 = 1540,
	TOOLACCESS_Function_Extend_Reserve20 = 1541,

	TOOLACCESS_Function_Extend2_SU_H = 1542,
	TOOLACCESS_Function_Extend2_SU_V = 1543,
	TOOLACCESS_Function_Extend2_S_PK = 1544,
	TOOLACCESS_Function_Extend2_SUPK_Mask = 1545,
	TOOLACCESS_Function_Extend2_Unsharp_Mask = 1546,
	TOOLACCESS_Function_Extend2_Egsm_PostSHP_Table = 1547,
	TOOLACCESS_Function_Extend2_Iegsm_Table = 1548,
	TOOLACCESS_Function_Extend2_SR_Init_Table = 1549,
	TOOLACCESS_Function_Extend2_SR_Edge_Gain = 1550,
	TOOLACCESS_Function_Extend2_SR_TEX_Gain = 1551,
	TOOLACCESS_Function_Extend2_SD_H_Table = 1552,
	TOOLACCESS_Function_Extend2_SD_V_Table = 1553,
	TOOLACCESS_Function_Extend2_SD_444TO422 = 1554,
	TOOLACCESS_Function_Extend2_Color_Space_Control = 1555,
	TOOLACCESS_Function_Extend2_SU_H_8Tab = 1556,
	TOOLACCESS_Function_Extend2_SU_V_6Tab = 1557,
	TOOLACCESS_Function_Extend2_OSD_Sharpness = 1558,
	TOOLACCESS_Function_Extend2_SU_DIR = 1559,
	TOOLACCESS_Function_Extend2_SU_DIR_Weigh = 1560,
	TOOLACCESS_Function_Extend2_Reserve19 = 1561,
	TOOLACCESS_Function_Extend2_Reserve20 = 1562,

	TOOLACCESS_Function_Extend3_VD_CON_BRI_HUE_SAT = 1563,
	TOOLACCESS_Function_Extend3_ICM_Tablee = 1564,
	TOOLACCESS_Function_Extend3_Gamma = 1565,
	TOOLACCESS_Function_Extend3_S_Gamma_Index = 1566,
	TOOLACCESS_Function_Extend3_S_Gamma_Low = 1567,
	TOOLACCESS_Function_Extend3_S_Gamma_High = 1568,
	TOOLACCESS_Function_Extend3_DCC_Table = 1569,
	TOOLACCESS_Function_Extend3_DCC_Color_Indep_t = 1570,
	TOOLACCESS_Function_Extend3_DCC_Chroma_Comp_t = 1571,
	TOOLACCESS_Function_Extend3_Sharpness_Table = 1572,
	TOOLACCESS_Function_Extend3_NR_Table = 1573,
	TOOLACCESS_Function_Extend3_PQA_INPUT_TABLE = 1574,
	TOOLACCESS_Function_Extend3_MB_Peaking = 1575,
	TOOLACCESS_Function_Extend3_blue_stretch = 1576,
	TOOLACCESS_Function_Extend3_Reserve14 = 1577,
	TOOLACCESS_Function_Extend3_Reserve15 = 1578,
	TOOLACCESS_Function_Extend3_Reserve16 = 1579,
	TOOLACCESS_Function_Extend3_Reserve17 = 1580,
	TOOLACCESS_Function_Extend3_Reserve18 = 1581,
	TOOLACCESS_Function_Extend3_Reserve19 = 1582,
	TOOLACCESS_Function_Extend3_Reserve20 = 1583,

	TOOLACCESS_Function_Extend4_Reserve00 = 1584,
	TOOLACCESS_Function_Extend4_Reserve01 = 1585,
	TOOLACCESS_Function_Extend4_Reserve02 = 1586,
	TOOLACCESS_Function_Extend4_Reserve03 = 1587,
	TOOLACCESS_Function_Extend4_Reserve04 = 1588,
	TOOLACCESS_Function_Extend4_Reserve05 = 1589,
	TOOLACCESS_Function_Extend4_Reserve06 = 1590,
	TOOLACCESS_Function_Extend4_Reserve07 = 1591,
	TOOLACCESS_Function_Extend4_Reserve08 = 1592,
	TOOLACCESS_Function_Extend4_Reserve09 = 1593,
	TOOLACCESS_Function_Extend4_Reserve10 = 1594,
	TOOLACCESS_Function_Extend4_Reserve11 = 1595,
	TOOLACCESS_Function_Extend4_Reserve12 = 1696,
	TOOLACCESS_Function_Extend4_Reserve13 = 1697,
	TOOLACCESS_Function_Extend4_Reserve14 = 1698,
	TOOLACCESS_Function_Extend4_Reserve15 = 1699,
	TOOLACCESS_Function_Extend4_Reserve16 = 1600,
	TOOLACCESS_Function_Extend4_Reserve17 = 1601,
	TOOLACCESS_Function_Extend4_Reserve18 = 1602,
	TOOLACCESS_Function_Extend4_Reserve19 = 1603,
	TOOLACCESS_Function_Extend4_Reserve20 = 1604,

	TOOLACCESS_Function_Table3D_Reserve00 = 1605,
	TOOLACCESS_Function_Table3D_Reserve01 = 1606,
	TOOLACCESS_Function_Table3D_Reserve02 = 1607,
	TOOLACCESS_Function_Table3D_Reserve03 = 1608,
	TOOLACCESS_Function_Table3D_Reserve04 = 1609,
	TOOLACCESS_Function_Table3D_Reserve05 = 1610,
	TOOLACCESS_Function_Table3D_Reserve06 = 1611,
	TOOLACCESS_Function_Table3D_Reserve07 = 1612,
	TOOLACCESS_Function_Table3D_Reserve08 = 1613,
	TOOLACCESS_Function_Table3D_Reserve09 = 1614,
	TOOLACCESS_Function_Table3D_Reserve10 = 1615,
	TOOLACCESS_Function_Table3D_Reserve11 = 1616,
	TOOLACCESS_Function_Table3D_Reserve12 = 1617,
	TOOLACCESS_Function_Table3D_Reserve13 = 1618,
	TOOLACCESS_Function_Table3D_Reserve14 = 1619,
	TOOLACCESS_Function_Table3D_Reserve15 = 1620,
	TOOLACCESS_Function_Table3D_Reserve16 = 1621,
	TOOLACCESS_Function_Table3D_Reserve17 = 1622,
	TOOLACCESS_Function_Table3D_Reserve18 = 1623,
	TOOLACCESS_Function_Table3D_Reserve19 = 1624,
	TOOLACCESS_Function_Table3D_Reserve20 = 1625,

	TOOLACCESS_Function_Coef_ALL = 1626,
	TOOLACCESS_Function_Extend_ALL = 1627,
	TOOLACCESS_Function_Extend2_ALL = 1628,
	TOOLACCESS_Function_Extend3_ALL = 1629,
	TOOLACCESS_Function_Extend4_ALL = 1630,
	TOOLACCESS_Function_TABLE3D_ALL = 1631,

	TOOLACCESS_DumpDi = 1700,
	TOOLACCESS_LocalContrast_Curve = 1710,
	TOOLACCESS_D_3D_LUT_GAMMA_control = 1711,
	
	/*below for tv006 request*/
	TOOLACCESS_SRGB_33_Matrix = 1800, /*for assign sRGB 3*3 matrix*/
	TOOLACCESS_ICM_GainAdjust = 1801, /*for ICM gain adjuest*/
	TOOLACCESS_DSE_Gain = 1802, /*for DSE gain*/
	TOOLACCESS_D_3D_LUT_Index = 1803, /*for D domain 3D Lut get index*/
	TOOLACCESS_D_3D_LUT_Reset = 1804, /*for D domain 3D Lut default value reset*/
	TOOLACCESS_OD_Table = 1805, /*for OverDrive*/
	/*above for tv006 request*/
	/*for tv006 debug*/
	TOOLACCESS_VPQ_IOCTL_StopRun_cmd = 1860,
	TOOLACCESS_VPQ_LED_IOCTL_StopRun_cmd = 1861,
	TOOLACCESS_VPQ_MEMC_IOCTL_StopRun_cmd = 1862,
	TOOLACCESS_VPQ_MEMC_DynamicBypass = 1865,
	TOOLACCESS_VPQ_DIGameMode_Only = 1866,
	TOOLACCESS_VPQ_IOCTL_StopRun = 1870,
	/*for demo*/
	TOOLACCESS_DemoOverscan = 1887,
	TOOLACCESS_DemoPQ = 1888,
	TOOLACCESS_ONEKEY_HDR = 1889,
	TOOLACCESS_ONEKEY_BBC = 1890,
	TOOLACCESS_ONEKEY_SDR2HDR = 1891,
	TOOLACCESS_TC_DEMO = 1892,



	/* HDR(DM/DM2) */
	/*HDR  3d  17*17*17 lut table,*/
	TOOLACCESS_DM_HDR_3D_Lut_TBL = 1900,
	TOOLACCESS_DM_HDR_1D_Lut_TBL = 1901,//yuan::20151027
  	TOOLACCESS_DM_HDR_1D_Lut_TBL_table1 = 1902,//yuan::20151027
	TOOLACCESS_DM2_HDR_EOTF_TBL = 1903,
	TOOLACCESS_DM2_HDR_OETF_TBL = 1904,
	TOOLACCESS_DM2_HDR_Tone_Mapping_TBL = 1905,
	TOOLACCESS_DM2_HDR_24x24x24_3D_TBL = 1906,
	TOOLACCESS_DM2_HDR_3D_TBL_FromReg = 1907,

	/* D Doamin 3d  17*17*17 lut table,*/
	TOOLACCESS_D_3D_Lut_TBL = 1950,

	/*All system Info*/
	TOOLACCESS_VIP_System_Info = 2100,
	TOOLACCESS_VO_Info = 2101,
	TOOLACCESS_DRM_Info_Frame = 2102,
	TOOLACCESS_AVI_Info_Frame = 2103,

	/* PQ Power Saving mode*/
	TOOLACCESS_VIP_PQ_Power_Saving = 2200,

	/* check PQ function */
	TOOLACCESS_PQ_CHECK_ALL = 3000,

	/* for TV030 */
	TOOLACCESS_MagicGammaR_TV030=5000,
	TOOLACCESS_MagicGammaG_TV030=5001,
	TOOLACCESS_MagicGammaB_TV030=5002,

	/* for TV001*/
	TOOLACCESS_TV001_black_stretch_and_white_stretch = 9000,

	/* for TV002*/
	TOOLACCESS_TV002_STYLE = 10000,
	TOOLACCESS_BP_CTRL_TV002 = 10001,
	TOOLACCESS_BP_CTRL_TBL_TV002 = 10002,
	TOOLACCESS_BP_STATUS_TV002 = 10003,
	TOOLACCESS_BP_TBL_TV002 = 10004,
	TOOLACCESS_DBC_STATUS_TV002 = 10005,
	TOOLACCESS_DBC_CTRL_TV002 = 10006,
	TOOLACCESS_DBC_SW_REG_TV002 = 10007,
	TOOLACCESS_ID_Detect_result_TV002 = 10008,
	TOOLACCESS_ID_Detect_Apply_flag_TV002 = 10009,
	TOOLACCESS_Zero_D_DBC_STATUS_TV002 = 10010,
	TOOLACCESS_Zero_D_DBC_CTRL_TV002 = 10011,
	TOOLACCESS_Zero_D_DBC_LUT_TV002 = 10012,
	TOOLACCESS_DBC_LUT_TV002 = 10013,
	TOOLACCESS_DBC_DCC_S_High_CMPS_LUT_TV002 = 10014,

} VIP_TOOL_ACCESS_INFO_Item;


#if 1/*RTICE2AP_DEBUG_TOOL_ENABLE*/
/*int rtice_get_vip_table(unsigned int id, unsigned short size, unsigned char *num_type, unsigned char *buf);*/
int rtice_get_vip_table(ap_data_param rtice_param, unsigned char *num_type, unsigned char *buf);
/*int rtice_set_vip_table(unsigned int id, unsigned short size, unsigned char *buf);*/
int rtice_set_vip_table(ap_data_param rtice_param, unsigned char *buf);
int rtice_set_IdxTable2Buff(unsigned short mode, unsigned short size, unsigned char *num_type, unsigned char *buf);	/*return idx table size*/
int rtice_SetGet_PQA_Table_Info(VIP_TOOL_ACCESS_INFO_Item mode, unsigned char isSet_Flag, unsigned short size, unsigned char *num_type, unsigned char *buf);	/*return idx table size*/
int rtice_SetGet_YUV2RGB_Table_Info(VIP_TOOL_ACCESS_INFO_Item mode, unsigned char isSet_Flag, unsigned short size,
	unsigned char *num_type, unsigned char *buf, _system_setting_info *system_setting_info, SLR_VIP_TABLE *vipTable_ShareMem);	/*return idx table size*/
int rtice_Set_YUV2RGB_Sat(unsigned short satGain, _system_setting_info *system_setting_info, SLR_VIP_TABLE *gVip_Table);
int rtice_Set_YUV2RGB_Hue(unsigned short hueGain, _system_setting_info *system_setting_info, SLR_VIP_TABLE *gVip_Table);
int rtice_Set_YUV2RGB_Contrast(unsigned short ContrastGain, _system_setting_info *system_setting_info, SLR_VIP_TABLE *gVip_Table);
int rtice_Set_YUV2RGB_Bri(unsigned short BriGain, _system_setting_info *system_setting_info, SLR_VIP_TABLE *gVip_Table);
void rtice_Covert_ICM_Gain_Struct(CHIP_COLOR_ICM_GAIN_ADJUST_T *pDB, CHIP_COLOR_ICM_GAIN_ADJUST_RTICE_T *pRTICE, unsigned char flag);

int rtice_Get_VIP_System_Info(_system_setting_info *system_setting_info, _RPC_system_setting_info *RPC_system_setting_info, SLR_VIP_TABLE *gVip_Table, unsigned int* pVIPSysInfo);
int rtice_Get_VO_Info(_system_setting_info *system_setting_info, SLR_VIP_TABLE *gVip_Table, unsigned int* pVOInfo);
int rtice_Get_HDMI_AVI_Info(_system_setting_info *system_setting_info, SLR_VIP_TABLE *gVip_Table, unsigned int *pAviInfo);
int rtice_Get_HDMI_DRM_Info(_system_setting_info *system_setting_info, SLR_VIP_TABLE *gVip_Table, unsigned int *pDrmInfo);

int  rtice_ICM_ReadWrite_CurrentPrevious_Buff_save(ap_data_param rtice_param, unsigned char *num_type, unsigned int *curPre_buf, _system_setting_info *system_setting_info, unsigned char isSet_Flag);
int  rtice_ICM_ReadWrite_From_CurrentPrevious_Buff(ap_data_param rtice_param, unsigned char *num_type, unsigned char *buf, _system_setting_info *system_setting_info, unsigned char isSet_Flag);

int  rtice_SetGet_HDR_DM2(ap_data_param rtice_param, unsigned char *num_type, unsigned char *buf, _system_setting_info *system_setting_info, unsigned char isSet_Flag);

int  rtice_SetGet_PQ_Power_Saving(ap_data_param rtice_param, unsigned char *num_type, unsigned char *buf, _system_setting_info *system_setting_info, unsigned char isSet_Flag);
int  rtice_Set_D_LUT_17to9(unsigned int *array);
int  rtice_Set_D_LUT_9to17(unsigned int *array);
/* TV 002 function*/
int  rtice_SetGet_BP_TV002(ap_data_param rtice_param, unsigned char *num_type, unsigned char *buf, _system_setting_info *system_setting_info, unsigned char isSet_Flag);
int  rtice_SetGet_DBC_TV002(ap_data_param rtice_param, unsigned char *num_type, unsigned char *buf, _system_setting_info *system_setting_info, unsigned char isSet_Flag);
int  rtice_SetGet_Zero_D_DBC_TV002(ap_data_param rtice_param, unsigned char *num_type, unsigned char *buf, _system_setting_info *system_setting_info, unsigned char isSet_Flag);

int rtice_set_Function_Coef(ap_data_param rtice_param, unsigned char *buf, unsigned char isSet_Flag);
int rtice_set_Function_Extend_Coef(ap_data_param rtice_param, unsigned char *buf, unsigned char isSet_Flag);
int rtice_set_Function_Extend2_Coef(ap_data_param rtice_param, unsigned char *buf, unsigned char isSet_Flag);
int rtice_set_Function_Extend3_Coef(ap_data_param rtice_param, unsigned char *buf, unsigned char isSet_Flag);


#endif



#ifdef __cplusplus
}
#endif


#endif /* __SCALER_LIB_H__*/


