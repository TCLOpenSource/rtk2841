#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/ioctl.h>

#include <scalercommon/vipCommon.h>
#include <tvscalercontrol/vip/color.h>
#include <scalercommon/vipCommon.h>
#include <tvscalercontrol/vip/dcc.h>
#include <tvscalercontrol/vip/peaking.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/vip/nr.h>
#include <tvscalercontrol/vip/di_ma.h>
#include <tvscalercontrol/vip/film.h>
#include <tvscalercontrol/vip/icm.h>
#include <tvscalercontrol/vip/localdimming.h>
#include <tvscalercontrol/vip/xc.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <tvscalercontrol/vip/gibi_od.h>
#include <tvscalercontrol/vip/intra.h>
#include <tvscalercontrol/vip/localcontrast.h>
#include <tvscalercontrol/vip/tc_hdr.h>
#include <tvscalercontrol/scaler/vipinclude.h>

#include "rtk_gen_vpqtable.h"

extern ADCGainOffset m_defaultYPbPrGainOffsetData;
extern ADCGainOffset m_defaultVgaGainOffset;
extern VIP_TABLE_DATA_STRUCT m_defaultColorDataTable;
extern VIP_TABLE_DATA_STRUCT m_defaultColorFacTable;
extern VIP_TABLE_DATA_STRUCT_EX m_defaultPictureModeTable;
extern VIP_TABLE_DATA_STRUCT m_defaultColorTempTable;
extern SLR_VIP_TABLE m_defaultVipTable;
extern SLR_VIP_TABLE_CUSTOM_TV001 m_customVipTable;
extern SLR_VIP_TABLE_CUSTOM_TV002 m_customVipTable_demo_tv002;

extern DRV_RPC_AutoMA_Flag S_RPC_AutoMA_Flag;
extern DRV_VipNewDcti_auto_adjust tVipNewDcti_auto_adjust[DCTI_TABLE_LEVEL_MAX];
extern DRV_VipNewDDcti_Table gVipDNewDcti_Table[DCTI_TABLE_LEVEL_MAX];
extern DRV_VipNewIDcti_Table gVipINewDcti_Table[DCTI_TABLE_LEVEL_MAX];
extern DRV_D_vcti_t gVipVcti_Table[DCTI_TABLE_LEVEL_MAX];
extern DRV_D_vcti_lpf_t gVipVcti_lpf_Table[DCTI_TABLE_LEVEL_MAX];
extern DRV_VipUV_Delay_TOP_Table gVipUV_Delay_TOP_Table;
extern DRV_VipChromaCompensation_t g_Chroma_Compensation_Curve[8];
extern DRV_Dnoise_Coef Dnoise_Coef[10];
extern DRV_Dnoise_Level Dnoise_Level[11];
extern DRV_SU_table_8tap_t SU_table_8tap[9];
extern DRV_SU_table_6tap_t SU_table_6tap[9];
extern DRV_Dirsu_Table gVipDirsu_Table[MAX_DIRECTIONAL_WEIGHTING_LEVEL];
extern DRV_di_smd_table_t gSMDtable[7];
extern DRV_di_ma_hme_table gHMETable[gHMETable_MAX];
extern DRV_di_ma_hmc_table gHMCTable[gHMCTable_MAX];
extern DRV_di_ma_pan_table gPanTable[gPANTable_MAX];
extern DRV_film_table_t gFilmInitTable[5];
extern DRV_Intra_Ver2_Table gVipIntra_Set_Ver2_tab;
extern DRV_NEW_UVC gUVCTable[new_UVC_MAX];
extern DRV_Gamma_BS gBSTable[Blue_Stretch_MAX];
extern DRV_SU_PK_Mask gVipSupk_Mask;
extern DRV_Skipir_Ring gVipSkipir_Ring[11];
extern DRV_Skipir_Islet gVipSkipir_Islet[11];
extern DRV_EMFMk2 gVipEmfMk2[11];
extern DRV_2Dpk_Seg gVip2Dpk_Seg;
extern DRV_2Dpk_Tex_Detect gVip2Dpk_Tex_Detect;
extern DRV_OSD_sharp gVipOSD_sharp;
extern DRV_D_DLTI_Table D_DLTI_Table[D_DLTI_table_num];
extern DRV_Un_Shp_Mask gVipUn_Shp_Mask;
extern DRV_Color_Mapping gCMTable[Color_Mapping_MAX];
extern RPC_DCC_Curve_boundary_table Curve_boundary_table[Curve_boundary_table_MAX];
extern RPC_DCC_Advance_control_table Advance_control_table[Advance_control_table_MAX];
extern unsigned short sRGB_Hue_Mapping[129];
extern unsigned char sRGB_RGB_LUT[3][129];
extern signed short sRGB_YUV2RGB[3][3];
extern signed short sRGB_RGB2YUV[3][3];
extern short sRGB_APPLY[3][3];
extern unsigned int YUV2RGB_Matrix_COEF_601_YCbCr;
extern unsigned short tYUV2RGB_COEF_TVBOX_SD;
extern unsigned short tYUV2RGB_COEF_TVBOX_HD;
extern unsigned short tYUV2RGB_COEF_601_YCbCr_NOClampY;
extern unsigned short tYUV2RGB_COEF[YUV2RGB_TBL_SELECT_ITEM_MAX][tUV2RGB_COEF_Items_Max];
extern unsigned char ConBriMapping_Offset_Table[16][VIP_YUV2RGB_LEVEL_SELECT_MAX][2];
extern unsigned char AVBlackLevelMapping_Table[8][3][4];
extern unsigned char ATVBlackLevelMapping_Table[8][3][4];
extern unsigned short tRGB2YUV_COEF_709_YUV_0_255;
extern unsigned short tRGB2YUV_COEF_709_YUV_16_235;
extern unsigned short tRGB2YUV_COEF_709_RGB_0_255;
extern unsigned short tRGB2YUV_COEF_709_RGB_16_235;
extern unsigned short tRGB2YUV_COEF_601_RGB_0_255;
extern unsigned short tRGB2YUV_COEF_601_RGB_16_235;
extern unsigned short tRGB2YUV_COEF_601_YCbCr_0_255;
extern unsigned short tRGB2YUV_COEF_601_YCbCr_16_235;
extern unsigned short tRGB2YUV_COEF_601_YCbCr_16_255;
extern unsigned short tRGB2YUV_COEF_TVBOX_SD;
extern unsigned short tRGB2YUV_COEF_TVBOX_720;
extern unsigned short tRGB2YUV_COEF_TVBOX_1080;
extern unsigned short tRGB2YUV_COEF[RGB2YUV_COEF_MATRIX_MODE_Max][RGB2YUV_COEF_MATRIX_ITEMS_Max];
extern DRV_Local_Dimming_Table Local_Dimming_Table[LD_Table_NUM];
extern unsigned int LD_Backlight_Profile_Interpolation_table[LD_Table_NUM][BL_Profile_Table_NUM][BL_Profile_Table_ROW][BL_Profile_Table_COLUMN];
extern DRV_LD_Data_Compensation_NewMode_2DTable LD_Data_Compensation_NewMode_2DTable[LD_Table_NUM];
extern DRV_Local_Contrast_Table Local_Contrast_Table[LC_Table_NUM];
extern unsigned int LC_Backlight_Profile_Interpolation_table[LC_Table_NUM][2][125];
extern unsigned int LC_ToneMappingSlopePoint_Table[LC_Table_ToneM_NUM][LC_Curve_ToneM_PointSlope];
extern DRV_di_ma_init_table DI_MA_Init_Table;
extern DRV_di_ma_adjust_table DI_MA_Adjust_Table[DI_MA_Adjust_Table_MAX];
extern DRV_di_TNR_XC_table di_TNR_XC_table[di_TNR_XC_table_MAX];
extern Scaler_DI_Coef_t Scaler_DI_Coef_table[VIP_QUALITY_SOURCE_NUM];
extern DRV_Adaptive_Gamma_Ctrl Adaptive_Gamma_Ctrl_Table[12];
extern DRV_od_table_t OD_table;
extern DRV_od_table_mode_t OD_setting_table[VIP_QUALITY_SOURCE_NUM];
extern DRV_FIR_Coef FIR_Coef_Ctrl[DRV_FIR_Coef_4Tap_NUM];
extern DRV_TwoStepSU_Table TwoStepSU_Table[TwoStepSU_Table_NUM];
extern DRV_ScalingDown_COEF_TAB ScaleDown_COEF_TAB;
extern unsigned int PCID_table;
extern unsigned int PCID2_Table;
extern unsigned char PCID2_Pol_Table_R;
extern unsigned char PCID2_Pol_Table_G;
extern unsigned char PCID2_Pol_Table_B;
extern DRV_MA_SNR_IESM_Coef pq_misc_MA_SNR_IESM_TBL[MA_SNR_IESM_TBL_MAX];
extern unsigned int t_inv_GAMMA[512];
extern int t_gamma_curve_22[1025];
extern unsigned short Power1div22Gamma[1025];
extern unsigned short Power22InvGamma[1025];
extern unsigned short LinearInvGamma[1025];
extern unsigned short LEDOutGamma[257];
extern DRV_Vip_Profile_Table gVip_Profile_Table[PROFILE_TABLE_TOTAL];
extern VIP_PQ_ByPass_Struct PQ_ByPass_Struct[VIP_PQ_ByPass_TBL_Max];
extern bool PQ_check_source_table[PQ_check_MAX][VIP_QUALITY_SOURCE_NUM];
extern PQ_check_struct PQ_check_register_table[200];
extern PQ_check_diff_struct PQ_check_register_diff_table[200];
extern VIP_I_De_XC_TBL I_De_XC_TBL[I_De_XC_TBL_Max];
extern VIP_I_De_Contour_TBL I_De_Contour_TBL[I_De_Contour_TBL_Max];
extern unsigned short BOE_RGBW_TAB_160624[16128];
extern unsigned short BOE_RGBW_TAB_160713[16128];
extern VIP_Output_InvOutput_Gamma Output_InvOutput_Gamma[Output_InvOutput_Gamma_TBL_MAX];
extern UINT8 hdr_table[HDR_TABLE_NUM][HDR_ITEM_MAX];
extern UINT32 hdr_YUV2RGB[VIP_HDR_DM_CSC1_YUV2RGB_TABLE_Max][12];
extern UINT32 hdr_RGB2OPT[HDR_RGB2OPT_TABLE_NUM][9];
extern unsigned int HDR10_3DLUT_17x17x17[17*17*17*3];
extern UINT32 EOTF_LUT_HLG_DEFAULT[1025];
extern UINT16 OETF_LUT_HLG_DEFAULT[1025];
extern UINT32 EOTF_LUT_R[1025];
extern UINT16 OETF_LUT_R[1025];
extern UINT16 HDR10_3DLUT_24x24x24[HDR_24x24x24_size][3];
extern unsigned short HLG_3DLUT_24x24x24[HDR_24x24x24_size][3];
extern unsigned short HLG_OETF_LUT_R[OETF_size];
extern unsigned int HLG_EOTF_LUT_R[EOTF_size];
extern DRV_TCHDR_Table TCHDR_Table[TC_Table_NUM];
//extern DRV_TCHDR_COEF_C_lut TCHDR_COEF_C_LUT_TBL;
extern DRV_TCHDR_COEF_I_lut TCHDR_COEF_I_LUT_TBL;
extern DRV_TCHDR_COEF_S_lut TCHDR_COEF_S_LUT_TBL;
//extern DRV_TCHDR_COEF_P_lut TCHDR_COEF_P_LUT_TBL;
//extern DRV_TCHDR_COEF_D_lut TCHDR_COEF_D_LUT_TBL;

VPQC_FILE_struct file_info[];

void VPQ_GenFile_setfile_info(VPQC_FILE_struct *file_info, unsigned int id, unsigned int* array , unsigned int size)
{
	file_info->id = id;
	file_info->size = size;
	file_info->crc = crc32(array,size);
	file_info->array_index = array;
}

int main(int argc,char **argv)
{
#if 1
	char File_Title[7] = "VPQGEN";
	int File_item = 0;
	int File_start_offset=0;
	int i;
	
	printf("start change table\n");
	FILE *fPtr;


	fPtr = fopen("vpqtable.dat", "wb");
	if (!fPtr) {
		printf("open file error\n");
		return 0;
	}
#if 1
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_m_defaultYPbPrGainOffsetData, &m_defaultYPbPrGainOffsetData, sizeof(m_defaultYPbPrGainOffsetData));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_m_defaultVgaGainOffset, &m_defaultVgaGainOffset, sizeof(m_defaultVgaGainOffset));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_m_defaultColorDataTable, &m_defaultColorDataTable, sizeof(VIP_TABLE_DATA_STRUCT));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_m_defaultColorFacTable, &m_defaultColorFacTable, sizeof(VIP_TABLE_DATA_STRUCT));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_m_defaultPictureModeTable, &m_defaultPictureModeTable, sizeof(VIP_TABLE_DATA_STRUCT_EX));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_m_defaultColorTempTable, &m_defaultColorTempTable, sizeof(VIP_TABLE_DATA_STRUCT));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_m_defaultVipTable, &m_defaultVipTable, sizeof(m_defaultVipTable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_m_customVipTable, &m_customVipTable, sizeof(m_customVipTable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_m_customVipTable_demo_tv002, &m_customVipTable_demo_tv002, sizeof(m_customVipTable_demo_tv002));	File_item++;

	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_S_RPC_AutoMA_Flag, &S_RPC_AutoMA_Flag, sizeof(S_RPC_AutoMA_Flag));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tVipNewDcti_auto_adjust, &tVipNewDcti_auto_adjust, sizeof(tVipNewDcti_auto_adjust));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipDNewDcti_Table, &gVipDNewDcti_Table, sizeof(gVipDNewDcti_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipINewDcti_Table, &gVipINewDcti_Table, sizeof(gVipINewDcti_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipVcti_Table, &gVipVcti_Table, sizeof(gVipVcti_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipVcti_lpf_Table, &gVipVcti_lpf_Table, sizeof(gVipVcti_lpf_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipUV_Delay_TOP_Table, &gVipUV_Delay_TOP_Table, sizeof(gVipUV_Delay_TOP_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_g_Chroma_Compensation_Curve, &g_Chroma_Compensation_Curve, sizeof(g_Chroma_Compensation_Curve));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Dnoise_Coef, &Dnoise_Coef, sizeof(Dnoise_Coef));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Dnoise_Level, &Dnoise_Level, sizeof(Dnoise_Level));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR256_CEC1x00_Hamm, &SUFIR256_CEC1x00_Hamm, sizeof(SUFIR256_CEC1x00_Hamm));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR256_CEP0x75, &SUFIR256_CEP0x75, sizeof(SUFIR256_CEP0x75));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR256_PM41x5_32, &SUFIR256_PM41x5_32, sizeof(SUFIR256_PM41x5_32));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR256_PM46_32, &SUFIR256_PM46_32, sizeof(SUFIR256_PM46_32));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR256_PM56_32, &SUFIR256_PM56_32, sizeof(SUFIR256_PM56_32));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR256_CLS0x80, &SUFIR256_CLS0x80, sizeof(SUFIR256_CLS0x80));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR256_Sinc3z_Hamm, &SUFIR256_Sinc3z_Hamm, sizeof(SUFIR256_Sinc3z_Hamm));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIRcls256_96s2_45, &SUFIRcls256_96s2_45, sizeof(SUFIRcls256_96s2_45));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SU_table_8tap, &SU_table_8tap, sizeof(SU_table_8tap));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR192_Sinc2x6_Hamm, &SUFIR192_Sinc2x6_Hamm, sizeof(SUFIR192_Sinc2x6_Hamm));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR192_PM52_32, &SUFIR192_PM52_32, sizeof(SUFIR192_PM52_32));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR192_Sinc2x4_Hamm, &SUFIR192_Sinc2x4_Hamm, sizeof(SUFIR192_Sinc2x4_Hamm));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR192_PM56_32, &SUFIR192_PM56_32, sizeof(SUFIR192_PM56_32));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR192_PM52_36, &SUFIR192_PM52_36, sizeof(SUFIR192_PM52_36));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR192_Sinc2x2_Hamm, &SUFIR192_Sinc2x2_Hamm, sizeof(SUFIR192_Sinc2x2_Hamm));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIR192_Hann0x70, &SUFIR192_Hann0x70, sizeof(SUFIR192_Hann0x70));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SUFIRcls192_84s2_55, &SUFIRcls192_84s2_55, sizeof(SUFIRcls192_84s2_55));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_SU_table_6tap, &SU_table_6tap, sizeof(SU_table_6tap));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipDirsu_Table, &gVipDirsu_Table, sizeof(gVipDirsu_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gSMDtable, &gSMDtable, sizeof(gSMDtable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gHMETable, &gHMETable, sizeof(gHMETable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gHMCTable, &gHMCTable, sizeof(gHMCTable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gPanTable, &gPanTable, sizeof(gPanTable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gFilmInitTable, &gFilmInitTable, sizeof(gFilmInitTable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipIntra_Set_Ver2_tab, &gVipIntra_Set_Ver2_tab, sizeof(gVipIntra_Set_Ver2_tab));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gUVCTable, &gUVCTable, sizeof(gUVCTable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gBSTable, &gBSTable, sizeof(gBSTable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipSupk_Mask, &gVipSupk_Mask, sizeof(gVipSupk_Mask));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Ring, &gVipSkipir_Ring, sizeof(gVipSkipir_Ring));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Islet, &gVipSkipir_Islet, sizeof(gVipSkipir_Islet));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipEmfMk2, &gVipEmfMk2, sizeof(gVipEmfMk2));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Seg, &gVip2Dpk_Seg, sizeof(gVip2Dpk_Seg));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Tex_Detect, &gVip2Dpk_Tex_Detect, sizeof(gVip2Dpk_Tex_Detect));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipOSD_sharp, &gVipOSD_sharp, sizeof(gVipOSD_sharp));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_D_DLTI_Table, &D_DLTI_Table, sizeof(D_DLTI_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVipUn_Shp_Mask, &gVipUn_Shp_Mask, sizeof(gVipUn_Shp_Mask));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gCMTable, &gCMTable, sizeof(gCMTable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Curve_boundary_table, &Curve_boundary_table, sizeof(Curve_boundary_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Advance_control_table, &Advance_control_table, sizeof(Advance_control_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_sRGB_Hue_Mapping, &sRGB_Hue_Mapping, sizeof(sRGB_Hue_Mapping));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_sRGB_RGB_LUT, &sRGB_RGB_LUT, sizeof(sRGB_RGB_LUT));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_sRGB_YUV2RGB, &sRGB_YUV2RGB, sizeof(sRGB_YUV2RGB));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_sRGB_RGB2YUV, &sRGB_RGB2YUV, sizeof(sRGB_RGB2YUV));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_sRGB_APPLY, &sRGB_APPLY, sizeof(sRGB_APPLY));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_YUV2RGB_Matrix_COEF_601_YCbCr, &YUV2RGB_Matrix_COEF_601_YCbCr, sizeof(YUV2RGB_Matrix_COEF_601_YCbCr));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_SD, &tYUV2RGB_COEF_TVBOX_SD, sizeof(tYUV2RGB_COEF_TVBOX_SD));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_HD, &tYUV2RGB_COEF_TVBOX_HD, sizeof(tYUV2RGB_COEF_TVBOX_HD));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_601_YCbCr_NOClampY, &tYUV2RGB_COEF_601_YCbCr_NOClampY, sizeof(tYUV2RGB_COEF_601_YCbCr_NOClampY));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF, &tYUV2RGB_COEF, sizeof(tYUV2RGB_COEF));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_ConBriMapping_Offset_Table, &ConBriMapping_Offset_Table, sizeof(ConBriMapping_Offset_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_AVBlackLevelMapping_Table, &AVBlackLevelMapping_Table, sizeof(AVBlackLevelMapping_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_ATVBlackLevelMapping_Table, &ATVBlackLevelMapping_Table, sizeof(ATVBlackLevelMapping_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_0_255, &tRGB2YUV_COEF_709_YUV_0_255, sizeof(tRGB2YUV_COEF_709_YUV_0_255));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_16_235, &tRGB2YUV_COEF_709_YUV_16_235, sizeof(tRGB2YUV_COEF_709_YUV_16_235));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_0_255, &tRGB2YUV_COEF_709_RGB_0_255, sizeof(tRGB2YUV_COEF_709_RGB_0_255));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_16_235, &tRGB2YUV_COEF_709_RGB_16_235, sizeof(tRGB2YUV_COEF_709_RGB_16_235));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_0_255, &tRGB2YUV_COEF_601_RGB_0_255, sizeof(tRGB2YUV_COEF_601_RGB_0_255));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_16_235, &tRGB2YUV_COEF_601_RGB_16_235, sizeof(tRGB2YUV_COEF_601_RGB_16_235));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_0_255, &tRGB2YUV_COEF_601_YCbCr_0_255, sizeof(tRGB2YUV_COEF_601_YCbCr_0_255));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_235, &tRGB2YUV_COEF_601_YCbCr_16_235, sizeof(tRGB2YUV_COEF_601_YCbCr_16_235));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_255, &tRGB2YUV_COEF_601_YCbCr_16_255, sizeof(tRGB2YUV_COEF_601_YCbCr_16_255));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_720, &tRGB2YUV_COEF_TVBOX_720, sizeof(tRGB2YUV_COEF_TVBOX_720));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_1080, &tRGB2YUV_COEF_TVBOX_1080, sizeof(tRGB2YUV_COEF_TVBOX_1080));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF, &tRGB2YUV_COEF, sizeof(tRGB2YUV_COEF));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Local_Dimming_Table, &Local_Dimming_Table, sizeof(Local_Dimming_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_LD_Backlight_Profile_Interpolation_table, &LD_Backlight_Profile_Interpolation_table, sizeof(LD_Backlight_Profile_Interpolation_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_LD_Data_Compensation_NewMode_2DTable, &LD_Data_Compensation_NewMode_2DTable, sizeof(LD_Data_Compensation_NewMode_2DTable));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Local_Contrast_Table, &Local_Contrast_Table, sizeof(Local_Contrast_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_LC_Backlight_Profile_Interpolation_table, &LC_Backlight_Profile_Interpolation_table, sizeof(LC_Backlight_Profile_Interpolation_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_LC_ToneMappingSlopePoint_Table, &LC_ToneMappingSlopePoint_Table, sizeof(LC_ToneMappingSlopePoint_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_DI_MA_Init_Table, &DI_MA_Init_Table, sizeof(DI_MA_Init_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_DI_MA_Adjust_Table, &DI_MA_Adjust_Table, sizeof(DI_MA_Adjust_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_di_TNR_XC_table, &di_TNR_XC_table, sizeof(di_TNR_XC_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Scaler_DI_Coef_table, &Scaler_DI_Coef_table, sizeof(Scaler_DI_Coef_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Adaptive_Gamma_Ctrl_Table, &Adaptive_Gamma_Ctrl_Table, sizeof(Adaptive_Gamma_Ctrl_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_OD_table, &OD_table, sizeof(OD_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_OD_setting_table, &OD_setting_table, sizeof(OD_setting_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_FIR_Coef_Ctrl, &FIR_Coef_Ctrl, sizeof(FIR_Coef_Ctrl));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_TwoStepSU_Table, &TwoStepSU_Table, sizeof(TwoStepSU_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_ScaleDown_COEF_TAB, &ScaleDown_COEF_TAB, sizeof(ScaleDown_COEF_TAB));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_PCID_table, &PCID_table, sizeof(PCID_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_PCID2_Table, &PCID2_Table, sizeof(PCID2_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_R, &PCID2_Pol_Table_R, sizeof(PCID2_Pol_Table_R));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_G, &PCID2_Pol_Table_G, sizeof(PCID2_Pol_Table_G));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_B, &PCID2_Pol_Table_B, sizeof(PCID2_Pol_Table_B));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_pq_misc_MA_SNR_IESM_TBL, &pq_misc_MA_SNR_IESM_TBL, sizeof(pq_misc_MA_SNR_IESM_TBL));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_t_inv_GAMMA, &t_inv_GAMMA, sizeof(t_inv_GAMMA));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_t_gamma_curve_22, &t_gamma_curve_22, sizeof(t_gamma_curve_22));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Power1div22Gamma, &Power1div22Gamma, sizeof(Power1div22Gamma));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Power22InvGamma, &Power22InvGamma, sizeof(Power22InvGamma));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_LinearInvGamma, &LinearInvGamma, sizeof(LinearInvGamma));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_LEDOutGamma, &LEDOutGamma, sizeof(LEDOutGamma));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_gVip_Profile_Table, &gVip_Profile_Table, sizeof(gVip_Profile_Table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_PQ_ByPass_Struct, &PQ_ByPass_Struct, sizeof(PQ_ByPass_Struct));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_PQ_check_source_table, &PQ_check_source_table, sizeof(PQ_check_source_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_PQ_check_register_table, &PQ_check_register_table, sizeof(PQ_check_register_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_PQ_check_register_diff_table, &PQ_check_register_diff_table, sizeof(PQ_check_register_diff_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_I_De_XC_TBL, &I_De_XC_TBL, sizeof(I_De_XC_TBL));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_I_De_Contour_TBL, &I_De_Contour_TBL, sizeof(I_De_Contour_TBL));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160624, &BOE_RGBW_TAB_160624, sizeof(BOE_RGBW_TAB_160624));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160713, &BOE_RGBW_TAB_160713, sizeof(BOE_RGBW_TAB_160713));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Output_InvOutput_Gamma, &Output_InvOutput_Gamma, sizeof(Output_InvOutput_Gamma));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_hdr_table, &hdr_table, sizeof(hdr_table));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_hdr_YUV2RGB, &hdr_YUV2RGB, sizeof(hdr_YUV2RGB));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_hdr_RGB2OPT, &hdr_RGB2OPT, sizeof(hdr_RGB2OPT));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_17x17x17, &HDR10_3DLUT_17x17x17, sizeof(HDR10_3DLUT_17x17x17));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_HLG_DEFAULT, &EOTF_LUT_HLG_DEFAULT, sizeof(EOTF_LUT_HLG_DEFAULT));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_OETF_LUT_HLG_DEFAULT, &OETF_LUT_HLG_DEFAULT, sizeof(OETF_LUT_HLG_DEFAULT));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_R, &EOTF_LUT_R, sizeof(EOTF_LUT_R));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_OETF_LUT_R, &OETF_LUT_R, sizeof(OETF_LUT_R));	File_item++;
	//VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_Tone_Mapping_LUT_R, &(m_defaultVipTable.Tone_Mapping_LUT_R[0]), sizeof(m_defaultVipTable->Tone_Mapping_LUT_R));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_24x24x24, &HDR10_3DLUT_24x24x24, sizeof(HDR10_3DLUT_24x24x24));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_HLG_3DLUT_24x24x24, &HLG_3DLUT_24x24x24, sizeof(HLG_3DLUT_24x24x24));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_HLG_OETF_LUT_R, &HLG_OETF_LUT_R, sizeof(HLG_OETF_LUT_R));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_HLG_EOTF_LUT_R, &HLG_EOTF_LUT_R, sizeof(HLG_EOTF_LUT_R));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_TCHDR_Table, &TCHDR_Table, sizeof(TCHDR_Table));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_C_LUT_TBL, &TCHDR_COEF_C_LUT_TBL, sizeof(TCHDR_COEF_C_LUT_TBL));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_I_LUT_TBL, &TCHDR_COEF_I_LUT_TBL, sizeof(TCHDR_COEF_I_LUT_TBL));	File_item++;
	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_S_LUT_TBL, &TCHDR_COEF_S_LUT_TBL, sizeof(TCHDR_COEF_S_LUT_TBL));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_P_LUT_TBL, &TCHDR_COEF_P_LUT_TBL, sizeof(TCHDR_COEF_P_LUT_TBL));	File_item++;
//	VPQ_GenFile_setfile_info(&file_info[File_item], VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_D_LUT_TBL, &TCHDR_COEF_D_LUT_TBL, sizeof(TCHDR_COEF_D_LUT_TBL));	File_item++;


#endif
	File_start_offset =  sizeof(File_Title) + sizeof(File_item) + sizeof(File_start_offset);

	file_info[0].index = File_start_offset + sizeof(VPQC_FILE_struct)*File_item;
	for(i=1; i< File_item;i++){
		file_info[i].index = file_info[i-1].index + file_info[i-1].size;		
	}

	for(i=0; i< File_item;i++){
		printf("%d,	%d,	%d,	%d\n",i, file_info[i].id, file_info[i].index,file_info[i].size);
	}

	fwrite(&File_Title, sizeof(char)*7, 1, fPtr);
	fwrite(&File_item, sizeof(int), 1, fPtr);
	fwrite(&File_start_offset, sizeof(int), 1, fPtr);
	
	fwrite(&file_info, sizeof(VPQC_FILE_struct)*File_item, 1, fPtr);

	for(i=0; i< File_item;i++){
		fwrite(file_info[i].array_index, file_info[i].size, 1, fPtr);
	}


	fclose(fPtr);
#else	
	VPQ_FunctionTest_PQ_misc_Table_ioctl();
	VPQ_FunctionTest_VIP_Table_ioctl();
	VPQ_FunctionTest_Run_Setup_IMD_ioctl();
	
#endif
	return 0;
}
#if 0
int VPQ_FunctionTest_Run_Setup_IMD_ioctl()
{
	int fd;
	fd = open(DEVFILE, O_RDWR);
	if(fd < 0)
		return -1;
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Run_Setup_IMD, int), NULL);
	close(fd);
	return 0;
}

int VPQ_FunctionTest_VIP_Table_ioctl()
{
	int fd, size;
	long ioctl_return_value;
	fd = open(DEVFILE, O_RDWR);
	if(fd < 0)
		return -1;
	size = sizeof(SLR_VIP_TABLE);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_m_defaultVipTable, int), &m_defaultVipTable);
	if(ioctl_return_value==1)
		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_m_defaultVipTable error\n");
	else if(ioctl_return_value==2)
		printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_m_defaultVipTable error\n");

	close(fd);
	return 0;
}

#if 1
//extern SLR_VIP_MISC_TABLE m_defaultVipMiscTable;
int VPQ_FunctionTest_PQ_misc_Table_ioctl()
{
#if 1
	int fd,size;
	long ioctl_return_value;
	fd = open(DEVFILE, O_RDWR);
	if(fd < 0)
		return -1;
	
#if 1
	size = sizeof(S_RPC_AutoMA_Flag);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_S_RPC_AutoMA_Flag, int), &S_RPC_AutoMA_Flag);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_S_RPC_AutoMA_Flag finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_S_RPC_AutoMA_Flag error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_S_RPC_AutoMA_Flag error\n");

	size = sizeof(tVipNewDcti_auto_adjust);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tVipNewDcti_auto_adjust, int), &tVipNewDcti_auto_adjust);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tVipNewDcti_auto_adjust finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tVipNewDcti_auto_adjust error\n");
	else if(ioctl_return_value==2) 	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tVipNewDcti_auto_adjust error\n");

	size = sizeof(gVipDNewDcti_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipDNewDcti_Table, int), &gVipDNewDcti_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipDNewDcti_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipDNewDcti_Table error\n");
	else if(ioctl_return_value==2) 	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipDNewDcti_Table error\n");

	size = sizeof(gVipINewDcti_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipINewDcti_Table, int), &gVipINewDcti_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipINewDcti_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipINewDcti_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipINewDcti_Table error\n");

	size = sizeof(gVipVcti_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipVcti_Table, int), &gVipVcti_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipVcti_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipVcti_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipVcti_Table error\n");

	size = sizeof(gVipVcti_lpf_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipVcti_lpf_Table, int), &gVipVcti_lpf_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipVcti_lpf_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipVcti_lpf_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipVcti_lpf_Table error\n");

	size = sizeof(gVipUV_Delay_TOP_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipUV_Delay_TOP_Table, int), &gVipUV_Delay_TOP_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipUV_Delay_TOP_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipUV_Delay_TOP_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipUV_Delay_TOP_Table error\n");

	size = sizeof(g_Chroma_Compensation_Curve);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_g_Chroma_Compensation_Curve, int), &g_Chroma_Compensation_Curve);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_g_Chroma_Compensation_Curve finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_g_Chroma_Compensation_Curve error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_g_Chroma_Compensation_Curve error\n");

	size = sizeof(Dnoise_Coef);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Dnoise_Coef, int), &Dnoise_Coef);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Dnoise_Coef finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Dnoise_Coef error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Dnoise_Coef error\n");

	size = sizeof(Dnoise_Level);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Dnoise_Level, int), &Dnoise_Level);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Dnoise_Level finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Dnoise_Level error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Dnoise_Level error\n");

	size = sizeof(SU_table_8tap);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_SU_table_8tap, int), &SU_table_8tap);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_SU_table_8tap finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_SU_table_8tap error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_SU_table_8tap error\n");

	size = sizeof(SU_table_6tap);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_SU_table_6tap, int), &SU_table_6tap);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_SU_table_6tap finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_SU_table_6tap error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_SU_table_6tap error\n");

	size = sizeof(gVipDirsu_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipDirsu_Table, int), &gVipDirsu_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipDirsu_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipDirsu_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipDirsu_Table error\n");

	size = sizeof(gSMDtable);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gSMDtable, int), &gSMDtable);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gSMDtable finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gSMDtable error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gSMDtable error\n");

	size = sizeof(gHMETable);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gHMETable, int), &gHMETable);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gHMETable finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gHMETable error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gHMETable error\n");

	size = sizeof(gHMCTable);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gHMCTable, int), &gHMCTable);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gHMCTable  finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gHMCTable error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gHMCTable error\n");

	size = sizeof(gPanTable);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gPanTable, int), &gPanTable);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gPanTable finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gPanTable error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gPanTable error\n");

	size = sizeof(gFilmInitTable);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gFilmInitTable, int), &gFilmInitTable);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gFilmInitTable finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gFilmInitTable error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gFilmInitTable error\n");

	size = sizeof(gVipIntra_Set_Ver2_tab);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipIntra_Set_Ver2_tab, int), &gVipIntra_Set_Ver2_tab);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipIntra_Set_Ver2_tab finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipIntra_Set_Ver2_tab error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipIntra_Set_Ver2_tab error\n");

	size = sizeof(gUVCTable);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gUVCTable, int), &gUVCTable);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gUVCTable finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gUVCTable error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gUVCTable error\n");

	size = sizeof(gBSTable);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gBSTable, int), &gBSTable);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gBSTable finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gBSTable error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gBSTable error\n");

	size = sizeof(gVipSupk_Mask);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipSupk_Mask, int), &gVipSupk_Mask);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipSupk_Mask finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipSupk_Mask error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipSupk_Mask error\n");

	size = sizeof(gVipSkipir_Ring);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Ring, int), &gVipSkipir_Ring);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Ring finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Ring error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Ring error\n");

	size = sizeof(gVipSkipir_Islet);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Islet, int), &gVipSkipir_Islet);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Islet finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Islet error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Islet error\n");

	size = sizeof(gVipEmfMk2);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipEmfMk2, int), &gVipEmfMk2);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipEmfMk2 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipEmfMk2 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipEmfMk2 error\n");

	size = sizeof(gVip2Dpk_Seg);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Seg, int), &gVip2Dpk_Seg);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Seg finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Seg error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Seg error\n");

	size = sizeof(gVip2Dpk_Tex_Detect);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Tex_Detect, int), &gVip2Dpk_Tex_Detect);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Tex_Detect finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Tex_Detect error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Tex_Detect error\n");

	size = sizeof(gVipOSD_sharp);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipOSD_sharp, int), &gVipOSD_sharp);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipOSD_sharp finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipOSD_sharp error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipOSD_sharp error\n");

	size = sizeof(D_DLTI_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_D_DLTI_Table, int), &D_DLTI_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_D_DLTI_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_D_DLTI_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_D_DLTI_Table error\n");

	size = sizeof(gVipUn_Shp_Mask);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVipUn_Shp_Mask, int), &gVipUn_Shp_Mask);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVipUn_Shp_Mask finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVipUn_Shp_Mask error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVipUn_Shp_Mask error\n");

	size = sizeof(gCMTable);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gCMTable, int), &gCMTable);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gCMTable finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gCMTable error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gCMTable error\n");

	size = sizeof(Curve_boundary_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Curve_boundary_table, int), &Curve_boundary_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Curve_boundary_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Curve_boundary_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Curve_boundary_table error\n");

	size = sizeof(Advance_control_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Advance_control_table, int), &Advance_control_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Advance_control_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Advance_control_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Advance_control_table error\n");

	size = sizeof(sRGB_Hue_Mapping);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_sRGB_Hue_Mapping, int), &sRGB_Hue_Mapping);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_sRGB_Hue_Mapping finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_sRGB_Hue_Mapping error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_sRGB_Hue_Mapping error\n");

	size = sizeof(sRGB_RGB_LUT);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_sRGB_RGB_LUT, int), &sRGB_RGB_LUT);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_sRGB_RGB_LUT finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_sRGB_RGB_LUT error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_sRGB_RGB_LUT error\n");

	size = sizeof(sRGB_YUV2RGB);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_sRGB_YUV2RGB, int), &sRGB_YUV2RGB);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_sRGB_YUV2RGB finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_sRGB_YUV2RGB error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_sRGB_YUV2RGB error\n");

	size = sizeof(sRGB_RGB2YUV);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_sRGB_RGB2YUV, int), &sRGB_RGB2YUV);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_sRGB_RGB2YUV finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_sRGB_RGB2YUV error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_sRGB_RGB2YUV error\n");

	size = sizeof(sRGB_APPLY);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_sRGB_APPLY, int), &sRGB_APPLY);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_sRGB_APPLY finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_sRGB_APPLY error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_sRGB_APPLY error\n");

	size = sizeof(YUV2RGB_Matrix_COEF_601_YCbCr);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_YUV2RGB_Matrix_COEF_601_YCbCr, int), &YUV2RGB_Matrix_COEF_601_YCbCr);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_YUV2RGB_Matrix_COEF_601_YCbCr finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_YUV2RGB_Matrix_COEF_601_YCbCr error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_YUV2RGB_Matrix_COEF_601_YCbCr error\n");

	size = sizeof(tYUV2RGB_COEF_TVBOX_SD);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_SD, int), &tYUV2RGB_COEF_TVBOX_SD);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_SD finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_SD error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_SD error\n");

	size = sizeof(tYUV2RGB_COEF_TVBOX_HD);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_HD, int), &tYUV2RGB_COEF_TVBOX_HD);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_HD finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_HD error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_HD error\n");

	size = sizeof(tYUV2RGB_COEF_601_YCbCr_NOClampY);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_601_YCbCr_NOClampY, int), &tYUV2RGB_COEF_601_YCbCr_NOClampY);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_601_YCbCr_NOClampY finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_601_YCbCr_NOClampY error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_601_YCbCr_NOClampY error\n");

	size = sizeof(tYUV2RGB_COEF);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF, int), &tYUV2RGB_COEF);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF error\n");

	size = sizeof(ConBriMapping_Offset_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_ConBriMapping_Offset_Table, int), &ConBriMapping_Offset_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_ConBriMapping_Offset_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_ConBriMapping_Offset_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_ConBriMapping_Offset_Table error\n");

	size = sizeof(AVBlackLevelMapping_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_AVBlackLevelMapping_Table, int), &AVBlackLevelMapping_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_AVBlackLevelMapping_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_AVBlackLevelMapping_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_AVBlackLevelMapping_Table error\n");

	size = sizeof(ATVBlackLevelMapping_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_ATVBlackLevelMapping_Table, int), &ATVBlackLevelMapping_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_ATVBlackLevelMapping_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_ATVBlackLevelMapping_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_ATVBlackLevelMapping_Table error\n");

	size = sizeof(tRGB2YUV_COEF_709_YUV_0_255);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_0_255, int), &tRGB2YUV_COEF_709_YUV_0_255);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_0_255 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_0_255 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_0_255 error\n");

	size = sizeof(tRGB2YUV_COEF_709_YUV_16_235);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_16_235, int), &tRGB2YUV_COEF_709_YUV_16_235);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_16_235 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_16_235 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_16_235 error\n");

	size = sizeof(tRGB2YUV_COEF_709_RGB_0_255);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_0_255, int), &tRGB2YUV_COEF_709_RGB_0_255);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_0_255 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_0_255 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_0_255 error\n");

	size = sizeof(tRGB2YUV_COEF_709_RGB_16_235);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_16_235, int), &tRGB2YUV_COEF_709_RGB_16_235);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_16_235 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_16_235 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_16_235 error\n");

	size = sizeof(tRGB2YUV_COEF_601_RGB_0_255);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_0_255, int), &tRGB2YUV_COEF_601_RGB_0_255);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_0_255 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_0_255 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_0_255 error\n");

	size = sizeof(tRGB2YUV_COEF_601_RGB_16_235);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_16_235, int), &tRGB2YUV_COEF_601_RGB_16_235);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_16_235 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_16_235 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_16_235 error\n");

	size = sizeof(tRGB2YUV_COEF_601_YCbCr_0_255);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_0_255, int), &tRGB2YUV_COEF_601_YCbCr_0_255);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_0_255 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_0_255 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_0_255 error\n");

	size = sizeof(tRGB2YUV_COEF_601_YCbCr_16_235);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_235, int), &tRGB2YUV_COEF_601_YCbCr_16_235);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_235 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_235 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_235 error\n");

	size = sizeof(tRGB2YUV_COEF_601_YCbCr_16_255);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_255, int), &tRGB2YUV_COEF_601_YCbCr_16_255);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_255 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_255 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_255 error\n");

	size = sizeof(tRGB2YUV_COEF_TVBOX_SD);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_SD, int), &tRGB2YUV_COEF_TVBOX_SD);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_SD finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_SD error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_SD error\n");

	size = sizeof(tRGB2YUV_COEF_TVBOX_720);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_720, int), &tRGB2YUV_COEF_TVBOX_720);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_720 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_720 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_720 error\n");

	size = sizeof(tRGB2YUV_COEF_TVBOX_1080);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_1080, int), &tRGB2YUV_COEF_TVBOX_1080);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_1080 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_1080 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_1080 error\n");

	size = sizeof(tRGB2YUV_COEF);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF, int), &tRGB2YUV_COEF);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF error\n");

	size = sizeof(Local_Dimming_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Local_Dimming_Table, int), &Local_Dimming_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Local_Dimming_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Local_Dimming_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Local_Dimming_Table error\n");

	size = sizeof(LD_Backlight_Profile_Interpolation_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_LD_Backlight_Profile_Interpolation_table, int), &LD_Backlight_Profile_Interpolation_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_LD_Backlight_Profile_Interpolation_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_LD_Backlight_Profile_Interpolation_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_LD_Backlight_Profile_Interpolation_table error\n");

	size = sizeof(LD_Data_Compensation_NewMode_2DTable);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_LD_Data_Compensation_NewMode_2DTable, int), &LD_Data_Compensation_NewMode_2DTable);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_LD_Data_Compensation_NewMode_2DTable finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_LD_Data_Compensation_NewMode_2DTable error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_LD_Data_Compensation_NewMode_2DTable error\n");

	size = sizeof(Local_Contrast_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Local_Contrast_Table, int), &Local_Contrast_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Local_Contrast_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Local_Contrast_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Local_Contrast_Table error\n");

	size = sizeof(LC_Backlight_Profile_Interpolation_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_LC_Backlight_Profile_Interpolation_table, int), &LC_Backlight_Profile_Interpolation_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_LC_Backlight_Profile_Interpolation_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_LC_Backlight_Profile_Interpolation_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_LC_Backlight_Profile_Interpolation_table error\n");

	size = sizeof(LC_ToneMappingSlopePoint_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_LC_ToneMappingSlopePoint_Table, int), &LC_ToneMappingSlopePoint_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_LC_ToneMappingSlopePoint_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_LC_ToneMappingSlopePoint_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_LC_ToneMappingSlopePoint_Table error\n");

	size = sizeof(DI_MA_Init_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_DI_MA_Init_Table, int), &DI_MA_Init_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_DI_MA_Init_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_DI_MA_Init_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_DI_MA_Init_Table error\n");

	size = sizeof(DI_MA_Adjust_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_DI_MA_Adjust_Table, int), &DI_MA_Adjust_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_DI_MA_Adjust_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_DI_MA_Adjust_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_DI_MA_Adjust_Table error\n");

	size = sizeof(di_TNR_XC_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_di_TNR_XC_table, int), &di_TNR_XC_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_di_TNR_XC_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_di_TNR_XC_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_di_TNR_XC_table error\n");

	size = sizeof(Scaler_DI_Coef_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Scaler_DI_Coef_table, int), &Scaler_DI_Coef_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Scaler_DI_Coef_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Scaler_DI_Coef_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Scaler_DI_Coef_table error\n");

	size = sizeof(Adaptive_Gamma_Ctrl_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Adaptive_Gamma_Ctrl_Table, int), &Adaptive_Gamma_Ctrl_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Adaptive_Gamma_Ctrl_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Adaptive_Gamma_Ctrl_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Adaptive_Gamma_Ctrl_Table error\n");

	size = sizeof(OD_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_OD_table, int), &OD_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_OD_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_OD_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_OD_table error\n");

	size = sizeof(OD_setting_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_OD_setting_table, int), &OD_setting_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_OD_setting_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_OD_setting_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_OD_setting_table error\n");

	size = sizeof(FIR_Coef_Ctrl);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_FIR_Coef_Ctrl, int), &FIR_Coef_Ctrl);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_FIR_Coef_Ctrl finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_FIR_Coef_Ctrl error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_FIR_Coef_Ctrl error\n");

	size = sizeof(TwoStepSU_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TwoStepSU_Table, int), &TwoStepSU_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_TwoStepSU_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_TwoStepSU_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_TwoStepSU_Table error\n");

	size = sizeof(ScaleDown_COEF_TAB);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_ScaleDown_COEF_TAB, int), &ScaleDown_COEF_TAB);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_ScaleDown_COEF_TAB finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_ScaleDown_COEF_TAB error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_ScaleDown_COEF_TAB error\n");

	size = sizeof(PCID_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_PCID_table, int), &PCID_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_PCID_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_PCID_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_PCID_table error\n");

	size = sizeof(PCID2_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_PCID2_Table, int), &PCID2_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_PCID2_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_PCID2_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_PCID2_Table error\n");

	size = sizeof(PCID2_Pol_Table_R);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_R, int), &PCID2_Pol_Table_R);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_R finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_R error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_R error\n");

	size = sizeof(PCID2_Pol_Table_G);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_G, int), &PCID2_Pol_Table_G);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_G finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_G error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_G error\n");

	size = sizeof(PCID2_Pol_Table_B);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_B, int), &PCID2_Pol_Table_B);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_B finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_B error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_B error\n");

	size = sizeof(pq_misc_MA_SNR_IESM_TBL);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_pq_misc_MA_SNR_IESM_TBL, int), &pq_misc_MA_SNR_IESM_TBL);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_pq_misc_MA_SNR_IESM_TBL finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_pq_misc_MA_SNR_IESM_TBL error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_pq_misc_MA_SNR_IESM_TBL error\n");

	size = sizeof(t_inv_GAMMA);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_t_inv_GAMMA, int), &t_inv_GAMMA);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_t_inv_GAMMA finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_t_inv_GAMMA error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_t_inv_GAMMA error\n");

	size = sizeof(t_gamma_curve_22);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_t_gamma_curve_22, int), &t_gamma_curve_22);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_t_gamma_curve_22 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_t_gamma_curve_22 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_t_gamma_curve_22 error\n");

	size = sizeof(Power1div22Gamma);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Power1div22Gamma, int), &Power1div22Gamma);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Power1div22Gamma finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Power1div22Gamma error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Power1div22Gamma error\n");

	size = sizeof(Power22InvGamma);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Power22InvGamma, int), &Power22InvGamma);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Power22InvGamma finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Power22InvGamma error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Power22InvGamma error\n");

	size = sizeof(LinearInvGamma);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_LinearInvGamma, int), &LinearInvGamma);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_LinearInvGamma finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_LinearInvGamma error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_LinearInvGamma error\n");

	size = sizeof(LEDOutGamma);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_LEDOutGamma, int), &LEDOutGamma);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_LEDOutGamma finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_LEDOutGamma error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_LEDOutGamma error\n");

	size = sizeof(gVip_Profile_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_gVip_Profile_Table, int), &gVip_Profile_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_gVip_Profile_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_gVip_Profile_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_gVip_Profile_Table error\n");

	size = sizeof(PQ_ByPass_Struct);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_PQ_ByPass_Struct, int), &PQ_ByPass_Struct);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_PQ_ByPass_Struct finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_PQ_ByPass_Struct error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_PQ_ByPass_Struct error\n");

	size = sizeof(PQ_check_source_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_PQ_check_source_table, int), &PQ_check_source_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_PQ_check_source_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_PQ_check_source_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_PQ_check_source_table error\n");

	size = sizeof(PQ_check_register_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_PQ_check_register_table, int), &PQ_check_register_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_PQ_check_register_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_PQ_check_register_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_PQ_check_register_table error\n");

	size = sizeof(PQ_check_register_diff_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_PQ_check_register_diff_table, int), &PQ_check_register_diff_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_PQ_check_register_diff_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_PQ_check_register_diff_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_PQ_check_register_diff_table error\n");

	size = sizeof(I_De_XC_TBL);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_I_De_XC_TBL, int), &I_De_XC_TBL);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_I_De_XC_TBL finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_I_De_XC_TBL error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_I_De_XC_TBL error\n");

	size = sizeof(I_De_Contour_TBL);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_I_De_Contour_TBL, int), &I_De_Contour_TBL);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_I_De_Contour_TBL finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_I_De_Contour_TBL error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_I_De_Contour_TBL error\n");

	size = sizeof(BOE_RGBW_TAB_160624);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160624, int), &BOE_RGBW_TAB_160624);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160624 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160624 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160624 error\n");

	size = sizeof(BOE_RGBW_TAB_160713);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160713, int), &BOE_RGBW_TAB_160713);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160713 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160713 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160713 error\n");

	size = sizeof(Output_InvOutput_Gamma);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Output_InvOutput_Gamma, int), &Output_InvOutput_Gamma);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Output_InvOutput_Gamma finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Output_InvOutput_Gamma error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Output_InvOutput_Gamma error\n");

	size = sizeof(hdr_table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_hdr_table, int), &hdr_table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_hdr_table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_hdr_table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_hdr_table error\n");

	size = sizeof(hdr_YUV2RGB);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_hdr_YUV2RGB, int), &hdr_YUV2RGB);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_hdr_YUV2RGB finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_hdr_YUV2RGB error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_hdr_YUV2RGB error\n");

	size = sizeof(hdr_RGB2OPT);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_hdr_RGB2OPT, int), &hdr_RGB2OPT);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_hdr_RGB2OPT finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_hdr_RGB2OPT error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_hdr_RGB2OPT error\n");

	size = sizeof(HDR10_3DLUT_17x17x17);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_17x17x17, int), &HDR10_3DLUT_17x17x17);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_17x17x17 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_17x17x17 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_17x17x17 error\n");

	size = sizeof(EOTF_LUT_HLG_DEFAULT);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_HLG_DEFAULT, int), &EOTF_LUT_HLG_DEFAULT);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_HLG_DEFAULT finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_HLG_DEFAULT error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_HLG_DEFAULT error\n");

	size = sizeof(OETF_LUT_HLG_DEFAULT);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_OETF_LUT_HLG_DEFAULT, int), &OETF_LUT_HLG_DEFAULT);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_OETF_LUT_HLG_DEFAULT finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_OETF_LUT_HLG_DEFAULT error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_OETF_LUT_HLG_DEFAULT error\n");

	size = sizeof(EOTF_LUT_R);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_R, int), &EOTF_LUT_R);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_R finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_R error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_R error\n");

	size = sizeof(OETF_LUT_R);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_OETF_LUT_R, int), &OETF_LUT_R);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_OETF_LUT_R finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_OETF_LUT_R error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_OETF_LUT_R error\n");

	size = sizeof(Tone_Mapping_LUT_R);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_Tone_Mapping_LUT_R, int), &Tone_Mapping_LUT_R);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_Tone_Mapping_LUT_R finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_Tone_Mapping_LUT_R error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_Tone_Mapping_LUT_R error\n");

	size = sizeof(HDR10_3DLUT_24x24x24);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_24x24x24, int), &HDR10_3DLUT_24x24x24);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_24x24x24 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_24x24x24 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_24x24x24 error\n");

	size = sizeof(HLG_3DLUT_24x24x24);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_HLG_3DLUT_24x24x24, int), &HLG_3DLUT_24x24x24);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_HLG_3DLUT_24x24x24 finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_HLG_3DLUT_24x24x24 error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_HLG_3DLUT_24x24x24 error\n");

	size = sizeof(HLG_OETF_LUT_R);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_HLG_OETF_LUT_R, int), &HLG_OETF_LUT_R);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_HLG_OETF_LUT_R finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_HLG_OETF_LUT_R error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_HLG_OETF_LUT_R error\n");

	size = sizeof(HLG_EOTF_LUT_R);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_HLG_EOTF_LUT_R, int), &HLG_EOTF_LUT_R);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_HLG_EOTF_LUT_R finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_HLG_EOTF_LUT_R error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_HLG_EOTF_LUT_R error\n");

	size = sizeof(TCHDR_Table);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TCHDR_Table, int), &TCHDR_Table);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_TCHDR_Table finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_TCHDR_Table error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_TCHDR_Table error\n");
#if 0
	size = sizeof(TCHDR_COEF_C_LUT_TBL);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_C_LUT_TBL, int), &TCHDR_COEF_C_LUT_TBL);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_C_LUT_TBL finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_C_LUT_TBL error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_C_LUT_TBL error\n");
#endif
	size = sizeof(TCHDR_COEF_I_LUT_TBL);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_I_LUT_TBL, int), &TCHDR_COEF_I_LUT_TBL);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_I_LUT_TBL finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_I_LUT_TBL error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_I_LUT_TBL error\n");

	size = sizeof(TCHDR_COEF_S_LUT_TBL);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_S_LUT_TBL, int), &TCHDR_COEF_S_LUT_TBL);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_S_LUT_TBL finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_S_LUT_TBL error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_S_LUT_TBL error\n");
#if 0
	size = sizeof(TCHDR_COEF_P_LUT_TBL);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_P_LUT_TBL, int), &TCHDR_COEF_P_LUT_TBL);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_P_LUT_TBL finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_P_LUT_TBL error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_P_LUT_TBL error\n");
#endif
#if 0
	size = sizeof(TCHDR_COEF_D_LUT_TBL);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_D_LUT_TBL, int), &TCHDR_COEF_D_LUT_TBL);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_D_LUT_TBL finsh\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_D_LUT_TBL error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_D_LUT_TBL error\n");
#endif
#endif
#if 0
	size = sizeof(S_RPC_AutoMA_Flag);
	ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_TABLE_SIZE, int), &size);
	ioctl_return_value = ioctl(fd, _IOW(VPQUT_IOC_MAGIC, VPQUT_IOC_PQ_CMD_SET_, int), &S_RPC_AutoMA_Flag);
	//if(ioctl_return_value==0)		printk(KERN_EMERG "[pass]VPQUT_IOC_PQ_CMD_SET_ error\n");
	if(ioctl_return_value==1)		printk(KERN_EMERG "[error][ioctl]VPQUT_IOC_PQ_CMD_SET_ error\n");
	else if(ioctl_return_value==2)	printk(KERN_EMERG "[error][size]VPQUT_IOC_PQ_CMD_SET_ error\n");
#endif

	close(fd);
	return 0;
#endif
}
#endif
#endif

unsigned int crc32(const void *buf, unsigned int size)
{
	static unsigned int crc32_tab[] = {
		0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
		0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
		0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
		0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
		0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
		0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
		0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
		0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
		0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
		0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
		0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
		0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
		0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
		0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
		0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
		0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
		0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
		0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
		0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
		0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
		0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
		0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
		0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
		0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
		0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
		0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
		0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
		0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
		0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
		0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
		0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
		0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
		0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
		0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
		0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
		0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
		0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
		0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
		0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
		0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
		0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
		0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
		0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
	};
	const unsigned char *p;
	unsigned int crc = 0xFFFFFFFF;

	p = (const unsigned char *)buf;
	crc = crc ^ ~0U;

	while (size--)
		crc = crc32_tab[(crc ^ *p++) & 0xFF] ^ (crc >> 8);

	return crc ^ ~0U;
}


