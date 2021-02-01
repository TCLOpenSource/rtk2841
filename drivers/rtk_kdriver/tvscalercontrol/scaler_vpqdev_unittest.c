/*Kernel Header file*/
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/fs.h>		/* everything... */
#include <linux/cdev.h>
#include <linux/platform_device.h>

#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/pageremap.h>
#include <linux/kthread.h>
#include <linux/freezer.h>
#include <linux/hrtimer.h>
#include <linux/vmalloc.h>

/*RBUS Header file*/
#include <scalercommon/scalerCommon.h>

/*TVScaler Header file*/
#include "tvscalercontrol/io/ioregdrv.h"
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/vip/scalerColor.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>
#include <tvscalercontrol/vip/viptable.h>
#include <tvscalercontrol/scaler_vpqmemcdev.h>
#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/avd/avdctrl.h>
#include "scaler_vpqdev.h"
#include "scaler_vpqdev_unittest.h"
#include "scaler_vscdev.h"
#include <tvscalercontrol/vip/pq_rpc.h>
//#include <mach/RPCDriver.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/sfg_reg.h>
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/vip/gibi_od.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/vip/tc_hdr.h>
#include <tvscalercontrol/vip/dcc.h>
#include <tvscalercontrol/vip/di_ma.h>
#include <tvscalercontrol/vip/intra.h>
#include <tvscalercontrol/vip/localcontrast.h>
#include <tvscalercontrol/vip/xc.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/scalerdrv/scalerip.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <rbus/mis_gpio_reg.h>
#include <mach/rtk_log.h>
#include <tvscalercontrol/panel/panelapi.h>
//#include <tvscalercontrol/vo/rtk_vo.h>
#include <asm/io.h>


#define TAG_NAME "VPQUT"

//#define	vip_malloc(x)	kmalloc(x, GFP_KERNEL)
//#define	vip_free(x)	kfree(x)

static dev_t vpqut_dev;/*vpqut device number*/
static struct cdev vpqut_cdev;
static struct task_struct *checkusb_tsk;

static struct semaphore VPQUT_Semaphore;

extern PQ_device_struct *g_Share_Memory_PQ_device_struct;

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
//extern UINT16 Tone_Mapping_LUT_R[129];
extern UINT16 HDR10_3DLUT_24x24x24[HDR_24x24x24_size][3];
extern unsigned short HLG_3DLUT_24x24x24[HDR_24x24x24_size][3];
extern unsigned short HLG_OETF_LUT_R[OETF_size];
extern unsigned int HLG_EOTF_LUT_R[EOTF_size];
#if 0	/* juwen, move to "tc_hdr", elieli */
extern DRV_TCHDR_Table TCHDR_Table[TC_Table_NUM];
extern DRV_TCHDR_COEF_C_lut TCHDR_COEF_C_LUT_TBL;
extern DRV_TCHDR_COEF_I_lut TCHDR_COEF_I_LUT_TBL;
extern DRV_TCHDR_COEF_S_lut TCHDR_COEF_S_LUT_TBL;
extern DRV_TCHDR_COEF_P_lut TCHDR_COEF_P_LUT_TBL;
extern DRV_TCHDR_COEF_D_lut TCHDR_COEF_D_LUT_TBL;
#endif
unsigned int crc32(const void *buf, unsigned int size);

extern unsigned char Setup_IMD(StructDisplayInfo* info);

int vpqut_open(struct inode *inode, struct file *filp)
{
	return 0;
}

ssize_t  vpqut_read(struct file *filep, char *buffer, size_t count, loff_t *offp)
{
	return count;
}

#ifdef CONFIG_RTK_USBDUMP_ENABLE
static int checkusb_file(void *arg);
#endif
ssize_t vpqut_write(struct file *filep, const char *buffer, size_t count, loff_t *offp)
{
	#ifdef CONFIG_RTK_USBDUMP_ENABLE
	if(checkusb_tsk == NULL){
		checkusb_tsk = kthread_create(checkusb_file, NULL, "check_usb");
		if (checkusb_tsk) {
			wake_up_process(checkusb_tsk);
		}else{
			rtd_printk(KERN_ERR, TAG_NAME, "scalevpqut: kthread_create error...\n");
		}
	}
	#endif
	return count;
}

int vpqut_release(struct inode *inode, struct file *filep)
{
	return 0;
}

static struct file* file_open(const char* path, int flags, int rights) {
	struct file* filp = NULL;
	mm_segment_t oldfs;
	int err = 0;

	oldfs = get_fs();
	set_fs(get_ds());
	filp = filp_open(path, flags, rights);
	set_fs(oldfs);
	if(IS_ERR(filp)) {
		err = PTR_ERR(filp);
		return NULL;
	}
	return filp;
}

static void file_close(struct file* file) {
	filp_close(file, NULL);
}

static int file_read(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size) {
	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());

	ret = vfs_read(file, data, size, &offset);

	set_fs(oldfs);
	return ret;
}

static int file_write(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size) {
	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());

	ret = vfs_write(file, data, size, &offset);

	set_fs(oldfs);
	return ret;
}

static int file_sync(struct file* file) {
	vfs_fsync(file, 0);
	return 0;
}

#ifdef CONFIG_RTK_USBDUMP_ENABLE
int rtk_get_usb_path(char *buf);
static int checkusb_file(void *arg)
{
	char buf[255] = {0};
	static struct file *vpq_table_file = NULL;
	VPQC_FILE_struct *file_info=NULL;

	char File_Title[7]={0};
	int File_item = 0;
	int File_start_offset=0;
	int i;

	sfg_sfg_force_bg_at_dif_RBUS sfg_force_bg_at_dif_reg;
	sfg_force_bg_at_dif_reg.regValue = IoReg_Read32(SFG_SFG_FORCE_BG_AT_DIF_reg);
	while(1) {
		msleep(1000);
		memset(buf,0,sizeof(buf));
		rtk_get_usb_path(buf);

		if(strlen(buf)!=0){
			strcat(buf,"/vpqtable.dat");
			vpq_table_file = (file_open(buf, O_RDWR, 0600));
			if (vpq_table_file) {

				file_read(vpq_table_file, 0, &File_Title, sizeof(char)*7);

				if(strcmp(File_Title, "VPQGEN")==0){		// check title
					sfg_force_bg_at_dif_reg.en_force_bg_dif = 1;
					sfg_force_bg_at_dif_reg.bg_dif_blu = 0;
					sfg_force_bg_at_dif_reg.bg_dif_grn = 1023;
					sfg_force_bg_at_dif_reg.bg_dif_red = 0;
					IoReg_Write32(SFG_SFG_FORCE_BG_AT_DIF_reg, sfg_force_bg_at_dif_reg.regValue);

					
					file_read(vpq_table_file, 7, &File_item, sizeof(int));					//get total item number
					file_read(vpq_table_file, 11, &File_start_offset, sizeof(int));

					file_info = (VPQC_FILE_struct *)dvr_malloc(sizeof(VPQC_FILE_struct)*File_item);
					if(file_info == NULL){
						printk(KERN_ERR "[VPQ table]checkusb_file alloc memory error\n");
						break;
					}
					
					file_read(vpq_table_file, File_start_offset, file_info, sizeof(VPQC_FILE_struct)*File_item);

					for(i=0; i<File_item; i++){
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_m_defaultYPbPrGainOffsetData, &m_defaultYPbPrGainOffsetData, sizeof(m_defaultYPbPrGainOffsetData));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_m_defaultVgaGainOffset, &m_defaultVgaGainOffset, sizeof(m_defaultVgaGainOffset));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_m_defaultColorDataTable, &m_defaultColorDataTable, sizeof(VIP_TABLE_DATA_STRUCT));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_m_defaultColorFacTable, &m_defaultColorFacTable, sizeof(VIP_TABLE_DATA_STRUCT));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_m_defaultPictureModeTable, &m_defaultPictureModeTable, sizeof(VIP_TABLE_DATA_STRUCT_EX));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_m_defaultColorTempTable, &m_defaultColorTempTable, sizeof(VIP_TABLE_DATA_STRUCT));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_m_defaultVipTable, &m_defaultVipTable, sizeof(m_defaultVipTable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_m_customVipTable, &m_customVipTable, sizeof(m_customVipTable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_m_customVipTable_demo_tv002, &m_customVipTable_demo_tv002, sizeof(m_customVipTable_demo_tv002));	

						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_S_RPC_AutoMA_Flag, &S_RPC_AutoMA_Flag, sizeof(S_RPC_AutoMA_Flag));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tVipNewDcti_auto_adjust, &tVipNewDcti_auto_adjust, sizeof(tVipNewDcti_auto_adjust));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipDNewDcti_Table, &gVipDNewDcti_Table, sizeof(gVipDNewDcti_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipINewDcti_Table, &gVipINewDcti_Table, sizeof(gVipINewDcti_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipVcti_Table, &gVipVcti_Table, sizeof(gVipVcti_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipVcti_lpf_Table, &gVipVcti_lpf_Table, sizeof(gVipVcti_lpf_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipUV_Delay_TOP_Table, &gVipUV_Delay_TOP_Table, sizeof(gVipUV_Delay_TOP_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_g_Chroma_Compensation_Curve, &g_Chroma_Compensation_Curve, sizeof(g_Chroma_Compensation_Curve));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Dnoise_Coef, &Dnoise_Coef, sizeof(Dnoise_Coef));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Dnoise_Level, &Dnoise_Level, sizeof(Dnoise_Level));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR256_CEC1x00_Hamm, &SUFIR256_CEC1x00_Hamm, sizeof(SUFIR256_CEC1x00_Hamm));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR256_CEP0x75, &SUFIR256_CEP0x75, sizeof(SUFIR256_CEP0x75));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR256_PM41x5_32, &SUFIR256_PM41x5_32, sizeof(SUFIR256_PM41x5_32));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR256_PM46_32, &SUFIR256_PM46_32, sizeof(SUFIR256_PM46_32));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR256_PM56_32, &SUFIR256_PM56_32, sizeof(SUFIR256_PM56_32));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR256_CLS0x80, &SUFIR256_CLS0x80, sizeof(SUFIR256_CLS0x80));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR256_Sinc3z_Hamm, &SUFIR256_Sinc3z_Hamm, sizeof(SUFIR256_Sinc3z_Hamm));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIRcls256_96s2_45, &SUFIRcls256_96s2_45, sizeof(SUFIRcls256_96s2_45));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SU_table_8tap, &SU_table_8tap, sizeof(SU_table_8tap));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR192_Sinc2x6_Hamm, &SUFIR192_Sinc2x6_Hamm, sizeof(SUFIR192_Sinc2x6_Hamm));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR192_PM52_32, &SUFIR192_PM52_32, sizeof(SUFIR192_PM52_32));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR192_Sinc2x4_Hamm, &SUFIR192_Sinc2x4_Hamm, sizeof(SUFIR192_Sinc2x4_Hamm));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR192_PM56_32, &SUFIR192_PM56_32, sizeof(SUFIR192_PM56_32));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR192_PM52_36, &SUFIR192_PM52_36, sizeof(SUFIR192_PM52_36));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR192_Sinc2x2_Hamm, &SUFIR192_Sinc2x2_Hamm, sizeof(SUFIR192_Sinc2x2_Hamm));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIR192_Hann0x70, &SUFIR192_Hann0x70, sizeof(SUFIR192_Hann0x70));	
					//	VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SUFIRcls192_84s2_55, &SUFIRcls192_84s2_55, sizeof(SUFIRcls192_84s2_55));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_SU_table_6tap, &SU_table_6tap, sizeof(SU_table_6tap));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipDirsu_Table, &gVipDirsu_Table, sizeof(gVipDirsu_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gSMDtable, &gSMDtable, sizeof(gSMDtable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gHMETable, &gHMETable, sizeof(gHMETable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gHMCTable, &gHMCTable, sizeof(gHMCTable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gPanTable, &gPanTable, sizeof(gPanTable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gFilmInitTable, &gFilmInitTable, sizeof(gFilmInitTable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipIntra_Set_Ver2_tab, &gVipIntra_Set_Ver2_tab, sizeof(gVipIntra_Set_Ver2_tab));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gUVCTable, &gUVCTable, sizeof(gUVCTable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gBSTable, &gBSTable, sizeof(gBSTable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipSupk_Mask, &gVipSupk_Mask, sizeof(gVipSupk_Mask));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Ring, &gVipSkipir_Ring, sizeof(gVipSkipir_Ring));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipSkipir_Islet, &gVipSkipir_Islet, sizeof(gVipSkipir_Islet));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipEmfMk2, &gVipEmfMk2, sizeof(gVipEmfMk2));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Seg, &gVip2Dpk_Seg, sizeof(gVip2Dpk_Seg));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVip2Dpk_Tex_Detect, &gVip2Dpk_Tex_Detect, sizeof(gVip2Dpk_Tex_Detect));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipOSD_sharp, &gVipOSD_sharp, sizeof(gVipOSD_sharp));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_D_DLTI_Table, &D_DLTI_Table, sizeof(D_DLTI_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVipUn_Shp_Mask, &gVipUn_Shp_Mask, sizeof(gVipUn_Shp_Mask));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gCMTable, &gCMTable, sizeof(gCMTable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Curve_boundary_table, &Curve_boundary_table, sizeof(Curve_boundary_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Advance_control_table, &Advance_control_table, sizeof(Advance_control_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_sRGB_Hue_Mapping, &sRGB_Hue_Mapping, sizeof(sRGB_Hue_Mapping));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_sRGB_RGB_LUT, &sRGB_RGB_LUT, sizeof(sRGB_RGB_LUT));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_sRGB_YUV2RGB, &sRGB_YUV2RGB, sizeof(sRGB_YUV2RGB));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_sRGB_RGB2YUV, &sRGB_RGB2YUV, sizeof(sRGB_RGB2YUV));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_sRGB_APPLY, &sRGB_APPLY, sizeof(sRGB_APPLY));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_YUV2RGB_Matrix_COEF_601_YCbCr, &YUV2RGB_Matrix_COEF_601_YCbCr, sizeof(YUV2RGB_Matrix_COEF_601_YCbCr));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_SD, &tYUV2RGB_COEF_TVBOX_SD, sizeof(tYUV2RGB_COEF_TVBOX_SD));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_TVBOX_HD, &tYUV2RGB_COEF_TVBOX_HD, sizeof(tYUV2RGB_COEF_TVBOX_HD));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF_601_YCbCr_NOClampY, &tYUV2RGB_COEF_601_YCbCr_NOClampY, sizeof(tYUV2RGB_COEF_601_YCbCr_NOClampY));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tYUV2RGB_COEF, &tYUV2RGB_COEF, sizeof(tYUV2RGB_COEF));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_ConBriMapping_Offset_Table, &ConBriMapping_Offset_Table, sizeof(ConBriMapping_Offset_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_AVBlackLevelMapping_Table, &AVBlackLevelMapping_Table, sizeof(AVBlackLevelMapping_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_ATVBlackLevelMapping_Table, &ATVBlackLevelMapping_Table, sizeof(ATVBlackLevelMapping_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_0_255, &tRGB2YUV_COEF_709_YUV_0_255, sizeof(tRGB2YUV_COEF_709_YUV_0_255));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_YUV_16_235, &tRGB2YUV_COEF_709_YUV_16_235, sizeof(tRGB2YUV_COEF_709_YUV_16_235));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_0_255, &tRGB2YUV_COEF_709_RGB_0_255, sizeof(tRGB2YUV_COEF_709_RGB_0_255));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_709_RGB_16_235, &tRGB2YUV_COEF_709_RGB_16_235, sizeof(tRGB2YUV_COEF_709_RGB_16_235));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_0_255, &tRGB2YUV_COEF_601_RGB_0_255, sizeof(tRGB2YUV_COEF_601_RGB_0_255));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_RGB_16_235, &tRGB2YUV_COEF_601_RGB_16_235, sizeof(tRGB2YUV_COEF_601_RGB_16_235));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_0_255, &tRGB2YUV_COEF_601_YCbCr_0_255, sizeof(tRGB2YUV_COEF_601_YCbCr_0_255));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_235, &tRGB2YUV_COEF_601_YCbCr_16_235, sizeof(tRGB2YUV_COEF_601_YCbCr_16_235));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_601_YCbCr_16_255, &tRGB2YUV_COEF_601_YCbCr_16_255, sizeof(tRGB2YUV_COEF_601_YCbCr_16_255));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_720, &tRGB2YUV_COEF_TVBOX_720, sizeof(tRGB2YUV_COEF_TVBOX_720));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF_TVBOX_1080, &tRGB2YUV_COEF_TVBOX_1080, sizeof(tRGB2YUV_COEF_TVBOX_1080));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_tRGB2YUV_COEF, &tRGB2YUV_COEF, sizeof(tRGB2YUV_COEF));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Local_Dimming_Table, &Local_Dimming_Table, sizeof(Local_Dimming_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_LD_Backlight_Profile_Interpolation_table, &LD_Backlight_Profile_Interpolation_table, sizeof(LD_Backlight_Profile_Interpolation_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_LD_Data_Compensation_NewMode_2DTable, &LD_Data_Compensation_NewMode_2DTable, sizeof(LD_Data_Compensation_NewMode_2DTable));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Local_Contrast_Table, &Local_Contrast_Table, sizeof(Local_Contrast_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_LC_Backlight_Profile_Interpolation_table, &LC_Backlight_Profile_Interpolation_table, sizeof(LC_Backlight_Profile_Interpolation_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_LC_ToneMappingSlopePoint_Table, &LC_ToneMappingSlopePoint_Table, sizeof(LC_ToneMappingSlopePoint_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_DI_MA_Init_Table, &DI_MA_Init_Table, sizeof(DI_MA_Init_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_DI_MA_Adjust_Table, &DI_MA_Adjust_Table, sizeof(DI_MA_Adjust_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_di_TNR_XC_table, &di_TNR_XC_table, sizeof(di_TNR_XC_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Scaler_DI_Coef_table, &Scaler_DI_Coef_table, sizeof(Scaler_DI_Coef_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Adaptive_Gamma_Ctrl_Table, &Adaptive_Gamma_Ctrl_Table, sizeof(Adaptive_Gamma_Ctrl_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_OD_table, &OD_table, sizeof(OD_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_OD_setting_table, &OD_setting_table, sizeof(OD_setting_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_FIR_Coef_Ctrl, &FIR_Coef_Ctrl, sizeof(FIR_Coef_Ctrl));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_TwoStepSU_Table, &TwoStepSU_Table, sizeof(TwoStepSU_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_ScaleDown_COEF_TAB, &ScaleDown_COEF_TAB, sizeof(ScaleDown_COEF_TAB));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_PCID_table, &PCID_table, sizeof(PCID_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_PCID2_Table, &PCID2_Table, sizeof(PCID2_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_R, &PCID2_Pol_Table_R, sizeof(PCID2_Pol_Table_R));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_G, &PCID2_Pol_Table_G, sizeof(PCID2_Pol_Table_G));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_PCID2_Pol_Table_B, &PCID2_Pol_Table_B, sizeof(PCID2_Pol_Table_B));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_pq_misc_MA_SNR_IESM_TBL, &pq_misc_MA_SNR_IESM_TBL, sizeof(pq_misc_MA_SNR_IESM_TBL));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_t_inv_GAMMA, &t_inv_GAMMA, sizeof(t_inv_GAMMA));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_t_gamma_curve_22, &t_gamma_curve_22, sizeof(t_gamma_curve_22));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Power1div22Gamma, &Power1div22Gamma, sizeof(Power1div22Gamma));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Power22InvGamma, &Power22InvGamma, sizeof(Power22InvGamma));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_LinearInvGamma, &LinearInvGamma, sizeof(LinearInvGamma));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_LEDOutGamma, &LEDOutGamma, sizeof(LEDOutGamma));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_gVip_Profile_Table, &gVip_Profile_Table, sizeof(gVip_Profile_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_PQ_ByPass_Struct, &PQ_ByPass_Struct, sizeof(PQ_ByPass_Struct));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_PQ_check_source_table, &PQ_check_source_table, sizeof(PQ_check_source_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_PQ_check_register_table, &PQ_check_register_table, sizeof(PQ_check_register_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_PQ_check_register_diff_table, &PQ_check_register_diff_table, sizeof(PQ_check_register_diff_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_I_De_XC_TBL, &I_De_XC_TBL, sizeof(I_De_XC_TBL));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_I_De_Contour_TBL, &I_De_Contour_TBL, sizeof(I_De_Contour_TBL));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160624, &BOE_RGBW_TAB_160624, sizeof(BOE_RGBW_TAB_160624));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_BOE_RGBW_TAB_160713, &BOE_RGBW_TAB_160713, sizeof(BOE_RGBW_TAB_160713));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Output_InvOutput_Gamma, &Output_InvOutput_Gamma, sizeof(Output_InvOutput_Gamma));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_hdr_table, &hdr_table, sizeof(hdr_table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_hdr_YUV2RGB, &hdr_YUV2RGB, sizeof(hdr_YUV2RGB));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_hdr_RGB2OPT, &hdr_RGB2OPT, sizeof(hdr_RGB2OPT));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_17x17x17, &HDR10_3DLUT_17x17x17, sizeof(HDR10_3DLUT_17x17x17));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_HLG_DEFAULT, &EOTF_LUT_HLG_DEFAULT, sizeof(EOTF_LUT_HLG_DEFAULT));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_OETF_LUT_HLG_DEFAULT, &OETF_LUT_HLG_DEFAULT, sizeof(OETF_LUT_HLG_DEFAULT));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_EOTF_LUT_R, &EOTF_LUT_R, sizeof(EOTF_LUT_R));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_OETF_LUT_R, &OETF_LUT_R, sizeof(OETF_LUT_R));	
						//VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_Tone_Mapping_LUT_R, &(m_defaultVipTable.Tone_Mapping_LUT_R[0]), sizeof(m_defaultVipTable.Tone_Mapping_LUT_R));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_HDR10_3DLUT_24x24x24, &HDR10_3DLUT_24x24x24, sizeof(HDR10_3DLUT_24x24x24));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_HLG_3DLUT_24x24x24, &HLG_3DLUT_24x24x24, sizeof(HLG_3DLUT_24x24x24));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_HLG_OETF_LUT_R, &HLG_OETF_LUT_R, sizeof(HLG_OETF_LUT_R));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_HLG_EOTF_LUT_R, &HLG_EOTF_LUT_R, sizeof(HLG_EOTF_LUT_R));	
#if 0	/* juwen, move to "tc_hdr", elieli */
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_TCHDR_Table, &TCHDR_Table, sizeof(TCHDR_Table));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_C_LUT_TBL, &TCHDR_COEF_C_LUT_TBL, sizeof(TCHDR_COEF_C_LUT_TBL));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_I_LUT_TBL, &TCHDR_COEF_I_LUT_TBL, sizeof(TCHDR_COEF_I_LUT_TBL));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_S_LUT_TBL, &TCHDR_COEF_S_LUT_TBL, sizeof(TCHDR_COEF_S_LUT_TBL));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_P_LUT_TBL, &TCHDR_COEF_P_LUT_TBL, sizeof(TCHDR_COEF_P_LUT_TBL));	
						VPQ_GenFile_setfile_data(vpq_table_file, &file_info[i], VPQUT_IOC_PQ_CMD_SET_TCHDR_COEF_D_LUT_TBL, &TCHDR_COEF_D_LUT_TBL, sizeof(TCHDR_COEF_D_LUT_TBL));	
#endif
					}

					msleep(2000);
					VipTableInit();
//					xLoadDefaultTable();
					Setup_IMD(Scaler_DispGetInfoPtr());
					dvr_free((void *)file_info);
					sfg_force_bg_at_dif_reg.en_force_bg_dif = 0;
					IoReg_Write32(SFG_SFG_FORCE_BG_AT_DIF_reg, sfg_force_bg_at_dif_reg.regValue);
				}

				file_close(vpq_table_file);
			}
			
			break;
		}

		if (freezing(current))
			try_to_freeze();
		if (kthread_should_stop())
			break;
	}
	checkusb_tsk = NULL;
	return 0;
}
#endif

#if 1
int vpqut_copy_vpqtable(struct file *table_file, VPQC_FILE_struct *array_info, unsigned int* array, unsigned int size){
	int ret = 0;
	if(array_info->size != size){
		printk(KERN_ERR "[VPQ table]case %d size error	%d != %d\n",array_info->id, array_info->size, size);
		ret = -1;
	}else{
		file_read(table_file, array_info->index, array, array_info->size);
		if(array_info->crc != crc32(array, size)){
			printk(KERN_ERR "[VPQ table]case %d  write crc error	%x != %x\n",array_info->id, array_info->crc, crc32(array, size));
			ret = -1;
		}
	}
	return ret;
}
#endif

int VPQ_GenFile_setfile_data(struct file *table_file, VPQC_FILE_struct *file_info, unsigned int id, unsigned int* array , unsigned int size)
{
	if(file_info->id == id)
		vpqut_copy_vpqtable(table_file, file_info, array, size);
	return 0;
}

unsigned int table_size;
extern StructDisplayInfo* Scaler_DispGetInfoPtr(void);
long vpqut_ioctl(struct file *file, unsigned int cmd,  unsigned long arg)
{
	int ret = 0;
	switch (cmd){
		case VPQUT_IOC_REG:
		{
			VPQUT_REG_struct buf;
			if (copy_from_user(&buf, (int __user *)arg, sizeof(VPQUT_REG_struct))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQUT_IOC_REGISTER fail\n");
				ret = -1;
			} else {
				if(buf.type == 'r'){
					printk(KERN_EMERG "VPQUT_IOC_REG read\n");
					buf.value = IoReg_Read32(buf.reg);
					copy_to_user((void __user *)arg, (void *)&buf, sizeof(VPQUT_REG_struct));
				}else if(buf.type == 'w'){
					printk(KERN_EMERG "VPQUT_IOC_REG write\n");
					IoReg_Write32(buf.reg, buf.value);
				}
				ret = 0;
			}
		}
		break;
		case VPQUT_IOC_REG_BIT:
		{
			VPQUT_REG_struct buf;
			if (copy_from_user(&buf, (int __user *)arg, sizeof(VPQUT_REG_struct))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQUT_IOC_REGISTER fail\n");
				ret = -1;
			} else {
				if(buf.type == 'r'){
					printk(KERN_EMERG "VPQUT_IOC_REG_BIT read\n");
					buf.value = IoReg_Read32(buf.reg);
					buf.value = (buf.value & (andREG_Table2[buf.bit[0]] & andREG_Table1[buf.bit[1]]))>>buf.bit[1];
					copy_to_user((void __user *)arg, (void *)&buf, sizeof(VPQUT_REG_struct));
				}else if(buf.type == 'w'){
					printk(KERN_EMERG "VPQUT_IOC_REG_BIT write\n");

					buf.value = (IoReg_Read32(buf.reg) & ((andREG_Table1[buf.bit[0]]<<1) | (andREG_Table2[buf.bit[1]]>>1))) | (buf.value<<buf.bit[1]);
					IoReg_Write32(buf.reg, buf.value);
				}
			}
		}
		break;
		case VPQUT_IOC_GET_MEM_INFO:
		{
			int i;
			StructMemBlock MemTag[MEMIDX_UNKNOW];
			for(i=0;i<MEMIDX_UNKNOW;i++){
				MemTag[i].Allocate_StartAddr = drvif_memory_get_MemTag_addr(i)->Allocate_StartAddr;
				MemTag[i].Allocate_VirAddr = drvif_memory_get_MemTag_addr(i)->Allocate_VirAddr;
				MemTag[i].Size = drvif_memory_get_MemTag_addr(i)->Size;
				MemTag[i].Status = drvif_memory_get_MemTag_addr(i)->Status;
				MemTag[i].StartAddr = drvif_memory_get_MemTag_addr(i)->StartAddr;
			}
			copy_to_user((void __user *)arg, (void *)&MemTag, sizeof(StructMemBlock)*MEMIDX_UNKNOW);

		}
		break;
		case VPQUT_IOC_SET_DI_MEM:
		{
			void __iomem *base;
			StructMemBlock DI_mem_info;
			DI_mem_info.Allocate_StartAddr = drvif_memory_get_MemTag_addr(MEMIDX_DI)->Allocate_StartAddr;
			DI_mem_info.Allocate_VirAddr = drvif_memory_get_MemTag_addr(MEMIDX_DI)->Allocate_VirAddr;
			DI_mem_info.Size = drvif_memory_get_MemTag_addr(MEMIDX_DI)->Size;
			DI_mem_info.Status = drvif_memory_get_MemTag_addr(MEMIDX_DI)->Status;
			DI_mem_info.StartAddr = drvif_memory_get_MemTag_addr(MEMIDX_DI)->StartAddr;

			base = ioremap(DI_mem_info.StartAddr, DI_mem_info.Size);
			if (copy_from_user(base, (int __user *)arg, DI_mem_info.Size)) {
				printk(KERN_EMERG "vpqut ioctl VPQUT_IOC_SET_DI_MEM fail\n");
				ret = -1;
			}
			iounmap(base);
		}
		break;
		case VPQUT_IOC_GET_DI_MEM:
		{
			void __iomem *base;
			StructMemBlock DI_mem_info;
			DI_mem_info.Allocate_StartAddr = drvif_memory_get_MemTag_addr(MEMIDX_DI)->Allocate_StartAddr;
			DI_mem_info.Allocate_VirAddr = drvif_memory_get_MemTag_addr(MEMIDX_DI)->Allocate_VirAddr;
			DI_mem_info.Size = drvif_memory_get_MemTag_addr(MEMIDX_DI)->Size;
			DI_mem_info.Status = drvif_memory_get_MemTag_addr(MEMIDX_DI)->Status;
			DI_mem_info.StartAddr = drvif_memory_get_MemTag_addr(MEMIDX_DI)->StartAddr;

			base = ioremap(DI_mem_info.StartAddr, DI_mem_info.Size);
			if(copy_to_user((void __user *)arg, base, DI_mem_info.Size)){
				printk(KERN_EMERG "vpqut ioctl VPQUT_IOC_GET_DI_MEM fail\n");
				ret = -1;
			}
			iounmap(base);
		}
		break;
		case VPQUT_IOC_GET_VD_MEM_INFO:
		{
			StructMemBlock VD_mem_info = {0};
			VD_mem_info.StartAddr = AVD_vpq_mem_isAllocated();
			VD_mem_info.Size = _SDRAM_3D_COM_USE;
			if(copy_to_user((void __user *)arg, &VD_mem_info, sizeof(StructMemBlock))){
				printk(KERN_EMERG "vpqut ioctl VPQUT_IOC_GET_VD_MEM fail\n");
				ret = -1;
			}
		}
		break;
		case VPQUT_IOC_SET_VD_MEM:
		{
			unsigned int StartAddr;
			void __iomem *base;
			StartAddr = AVD_vpq_mem_isAllocated();

			base = ioremap(StartAddr, _SDRAM_3D_COM_USE);
			if (copy_from_user(base, (int __user *)arg, _SDRAM_3D_COM_USE)) {
				printk(KERN_EMERG "vpqut ioctl VPQUT_IOC_SET_VD_MEM fail\n");
				ret = -1;
			}
			iounmap(base);
		}
		break;
		case VPQUT_IOC_GET_VD_MEM:
		{
			unsigned int StartAddr;
			void __iomem *base;
			StartAddr = AVD_vpq_mem_isAllocated();

			base = ioremap(StartAddr, _SDRAM_3D_COM_USE);
			if(copy_to_user((void __user *)arg, base, _SDRAM_3D_COM_USE)){
				printk(KERN_EMERG "vpqut ioctl VPQUT_IOC_GET_VD_MEM fail\n");
				ret = -1;
			}
			iounmap(base);
		}
		break;
		case VPQUT_IOC_SET_TABLE_SIZE:
		{
			if (copy_from_user(&table_size, arg, (sizeof(unsigned int)))) {
				printk(KERN_EMERG "vpqut ioctl VPQUT_IOC_SET_TABLE_SIZE fail\n");
				ret = 1;
			}
		}
		break;
		case VPQUT_IOC_SET_m_defaultVipTable:
		{
			if(table_size!=sizeof(SLR_VIP_TABLE)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_m_defaultVipTable fail	%d != %d\n",table_size,sizeof(SLR_VIP_TABLE));
				ret = 2;
				break;
			}
			if (copy_from_user(&m_defaultVipTable, (void __user *)arg, (sizeof(SLR_VIP_TABLE)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_m_defaultVipTable fail\n");
				ret = 1;
				break;
			}
			printk(KERN_EMERG "[rock]vpqut ioctl VPQUT_IOC_SET_m_defaultVipTable ok\n");
			VipTableInit();
//			fwif_color_video_quality_handler();
//			Setup_IMD(Scaler_DispGetInfoPtr());
		}
		break;
		case VPQUT_IOC_SET_Run_Setup_IMD:
		{
			Setup_IMD(Scaler_DispGetInfoPtr());
		}
		case VPQUT_IOC_SET_S_RPC_AutoMA_Flag:
		{
			if(table_size!=sizeof(S_RPC_AutoMA_Flag)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_S_RPC_AutoMA_Flag fail	%d != %d\n",table_size,sizeof(S_RPC_AutoMA_Flag));
				ret = 2;
				break;
			}
			if (copy_from_user(&S_RPC_AutoMA_Flag, (void __user *)arg, (sizeof(S_RPC_AutoMA_Flag)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_S_RPC_AutoMA_Flag fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_tVipNewDcti_auto_adjust:
		{
			if(table_size!=sizeof(tVipNewDcti_auto_adjust)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tVipNewDcti_auto_adjust fail	%d != %d\n",table_size,sizeof(tVipNewDcti_auto_adjust));
				ret = 2;
				break;
			}
			if (copy_from_user(&tVipNewDcti_auto_adjust, (void __user *)arg, (sizeof(tVipNewDcti_auto_adjust)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tVipNewDcti_auto_adjust fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipDNewDcti_Table:
		{
			if(table_size!=sizeof(gVipDNewDcti_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipDNewDcti_Table fail	%d != %d\n",table_size,sizeof(gVipDNewDcti_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipDNewDcti_Table, (void __user *)arg, (sizeof(gVipDNewDcti_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipDNewDcti_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipINewDcti_Table:
		{
			if(table_size!=sizeof(gVipINewDcti_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipINewDcti_Table fail	%d != %d\n",table_size,sizeof(gVipINewDcti_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipINewDcti_Table, (void __user *)arg, (sizeof(gVipINewDcti_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipINewDcti_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipVcti_Table:
		{
			if(table_size!=sizeof(gVipVcti_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipVcti_Table fail	%d != %d\n",table_size,sizeof(gVipVcti_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipVcti_Table, (void __user *)arg, (sizeof(gVipVcti_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipVcti_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipVcti_lpf_Table:
		{
			if(table_size!=sizeof(gVipVcti_lpf_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipVcti_lpf_Table fail	%d != %d\n",table_size,sizeof(gVipVcti_lpf_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipVcti_lpf_Table, (void __user *)arg, (sizeof(gVipVcti_lpf_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipVcti_lpf_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipUV_Delay_TOP_Table:
		{
			if(table_size!=sizeof(gVipUV_Delay_TOP_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipUV_Delay_TOP_Table fail	%d != %d\n",table_size,sizeof(gVipUV_Delay_TOP_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipUV_Delay_TOP_Table, (void __user *)arg, (sizeof(gVipUV_Delay_TOP_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipUV_Delay_TOP_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_g_Chroma_Compensation_Curve:
		{
			if(table_size!=sizeof(g_Chroma_Compensation_Curve)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_g_Chroma_Compensation_Curve fail	%d != %d\n",table_size,sizeof(g_Chroma_Compensation_Curve));
				ret = 2;
				break;
			}
			if (copy_from_user(&g_Chroma_Compensation_Curve, (void __user *)arg, (sizeof(g_Chroma_Compensation_Curve)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_g_Chroma_Compensation_Curve fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_Dnoise_Coef:
		{
			if(table_size!=sizeof(Dnoise_Coef)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Dnoise_Coef fail	%d != %d\n",table_size,sizeof(Dnoise_Coef));
				ret = 2;
				break;
			}
			if (copy_from_user(&Dnoise_Coef, (void __user *)arg, (sizeof(Dnoise_Coef)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Dnoise_Coef fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_Dnoise_Level:
		{
			if(table_size!=sizeof(Dnoise_Level)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Dnoise_Level fail	%d != %d\n",table_size,sizeof(Dnoise_Level));
				ret = 2;
				break;
			}
			if (copy_from_user(&Dnoise_Level, (void __user *)arg, (sizeof(Dnoise_Level)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Dnoise_Level fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_SU_table_8tap:
		{
			if(table_size!=sizeof(SU_table_8tap)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_SU_table_8tap fail	%d != %d\n",table_size,sizeof(SU_table_8tap));
				ret = 2;
				break;
			}
			if (copy_from_user(&SU_table_8tap, (void __user *)arg, (sizeof(SU_table_8tap)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_SU_table_8tap fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_SU_table_6tap:
		{
			if(table_size!=sizeof(SU_table_6tap)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_SU_table_6tap fail	%d != %d\n",table_size,sizeof(SU_table_6tap));
				ret = 2;
				break;
			}
			if (copy_from_user(&SU_table_6tap, (void __user *)arg, (sizeof(SU_table_6tap)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_SU_table_6tap fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipDirsu_Table:
		{
			if(table_size!=sizeof(gVipDirsu_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipDirsu_Table fail	%d != %d\n",table_size,sizeof(gVipDirsu_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipDirsu_Table, (void __user *)arg, (sizeof(gVipDirsu_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipDirsu_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gSMDtable:
		{
			if(table_size!=sizeof(gSMDtable)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gSMDtable fail	%d != %d\n",table_size,sizeof(gSMDtable));
				ret = 2;
				break;
			}
			if (copy_from_user(&gSMDtable, (void __user *)arg, (sizeof(gSMDtable)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gSMDtable fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gHMETable:
		{
			if(table_size!=sizeof(gHMETable)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gHMETable fail	%d != %d\n",table_size,sizeof(gHMETable));
				ret = 2;
				break;
			}
			if (copy_from_user(&gHMETable, (void __user *)arg, (sizeof(gHMETable)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gHMETable fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gHMCTable:
		{
			if(table_size!=sizeof(gHMCTable)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gHMCTable fail	%d != %d\n",table_size,sizeof(gHMCTable));
				ret = 2;
				break;
			}
			if (copy_from_user(&gHMCTable, (void __user *)arg, (sizeof(gHMCTable)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gHMCTable fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gPanTable:
		{
			if(table_size!=sizeof(gPanTable)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gPanTable fail	%d != %d\n",table_size,sizeof(gPanTable));
				ret = 2;
				break;
			}
			if (copy_from_user(&gPanTable, (void __user *)arg, (sizeof(gPanTable)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gPanTable fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gFilmInitTable:
		{
			if(table_size!=sizeof(gFilmInitTable)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gFilmInitTable fail	%d != %d\n",table_size,sizeof(gFilmInitTable));
				ret = 2;
				break;
			}
			if (copy_from_user(&gFilmInitTable, (void __user *)arg, (sizeof(gFilmInitTable)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gFilmInitTable fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipIntra_Set_Ver2_tab:
		{
			if(table_size!=sizeof(gVipIntra_Set_Ver2_tab)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipIntra_Set_Ver2_tab fail	%d != %d\n",table_size,sizeof(gVipIntra_Set_Ver2_tab));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipIntra_Set_Ver2_tab, (void __user *)arg, (sizeof(gVipIntra_Set_Ver2_tab)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipIntra_Set_Ver2_tab fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gUVCTable:
		{
			if(table_size!=sizeof(gUVCTable)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gUVCTable fail	%d != %d\n",table_size,sizeof(gUVCTable));
				ret = 2;
				break;
			}
			if (copy_from_user(&gUVCTable, (void __user *)arg, (sizeof(gUVCTable)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gUVCTable fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gBSTable:
		{
			if(table_size!=sizeof(gBSTable)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gBSTable fail	%d != %d\n",table_size,sizeof(gBSTable));
				ret = 2;
				break;
			}
			if (copy_from_user(&gBSTable, (void __user *)arg, (sizeof(gBSTable)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gBSTable fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipSupk_Mask:
		{
			if(table_size!=sizeof(gVipSupk_Mask)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipSupk_Mask fail	%d != %d\n",table_size,sizeof(gVipSupk_Mask));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipSupk_Mask, (void __user *)arg, (sizeof(gVipSupk_Mask)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipSupk_Mask fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipSkipir_Ring:
		{
			if(table_size!=sizeof(gVipSkipir_Ring)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipSkipir_Ring fail	%d != %d\n",table_size,sizeof(gVipSkipir_Ring));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipSkipir_Ring, (void __user *)arg, (sizeof(gVipSkipir_Ring)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipSkipir_Ring fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipSkipir_Islet:
		{
			if(table_size!=sizeof(gVipSkipir_Islet)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipSkipir_Islet fail	%d != %d\n",table_size,sizeof(gVipSkipir_Islet));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipSkipir_Islet, (void __user *)arg, (sizeof(gVipSkipir_Islet)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipSkipir_Islet fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipEmfMk2:
		{
			if(table_size!=sizeof(gVipEmfMk2)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipEmfMk2 fail	%d != %d\n",table_size,sizeof(gVipEmfMk2));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipEmfMk2, (void __user *)arg, (sizeof(gVipEmfMk2)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipEmfMk2 fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVip2Dpk_Seg:
		{
			if(table_size!=sizeof(gVip2Dpk_Seg)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVip2Dpk_Seg fail	%d != %d\n",table_size,sizeof(gVip2Dpk_Seg));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVip2Dpk_Seg, (void __user *)arg, (sizeof(gVip2Dpk_Seg)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVip2Dpk_Seg fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVip2Dpk_Tex_Detect:
		{
			if(table_size!=sizeof(gVip2Dpk_Tex_Detect)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVip2Dpk_Tex_Detect fail	%d != %d\n",table_size,sizeof(gVip2Dpk_Tex_Detect));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVip2Dpk_Tex_Detect, (void __user *)arg, (sizeof(gVip2Dpk_Tex_Detect)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVip2Dpk_Tex_Detect fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipOSD_sharp:
		{
			if(table_size!=sizeof(gVipOSD_sharp)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipOSD_sharp fail	%d != %d\n",table_size,sizeof(gVipOSD_sharp));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipOSD_sharp, (void __user *)arg, (sizeof(gVipOSD_sharp)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipOSD_sharp fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_D_DLTI_Table:
		{
			if(table_size!=sizeof(D_DLTI_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_D_DLTI_Table fail	%d != %d\n",table_size,sizeof(D_DLTI_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&D_DLTI_Table, (void __user *)arg, (sizeof(D_DLTI_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_D_DLTI_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gVipUn_Shp_Mask:
		{
			if(table_size!=sizeof(gVipUn_Shp_Mask)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVipUn_Shp_Mask fail	%d != %d\n",table_size,sizeof(gVipUn_Shp_Mask));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVipUn_Shp_Mask, (void __user *)arg, (sizeof(gVipUn_Shp_Mask)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVipUn_Shp_Mask fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_gCMTable:
		{
			if(table_size!=sizeof(gCMTable)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gCMTable fail	%d != %d\n",table_size,sizeof(gCMTable));
				ret = 2;
				break;
			}
			if (copy_from_user(&gCMTable, (void __user *)arg, (sizeof(gCMTable)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gCMTable fail\n");
				ret = 1;
				break;
			}
		}
		break;
		case VPQUT_IOC_SET_Curve_boundary_table:
		{
			if(table_size!=sizeof(Curve_boundary_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Curve_boundary_table fail	%d != %d\n",table_size,sizeof(Curve_boundary_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&Curve_boundary_table, (void __user *)arg, (sizeof(Curve_boundary_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Curve_boundary_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_Advance_control_table:
		{
			if(table_size!=sizeof(Advance_control_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Advance_control_table fail	%d != %d\n",table_size,sizeof(Advance_control_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&Advance_control_table, (void __user *)arg, (sizeof(Advance_control_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Advance_control_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_sRGB_Hue_Mapping:
		{
			if(table_size!=sizeof(sRGB_Hue_Mapping)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_sRGB_Hue_Mapping fail	%d != %d\n",table_size,sizeof(sRGB_Hue_Mapping));
				ret = 2;
				break;
			}
			if (copy_from_user(&sRGB_Hue_Mapping, (void __user *)arg, (sizeof(sRGB_Hue_Mapping)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_sRGB_Hue_Mapping fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_sRGB_RGB_LUT:
		{
			if(table_size!=sizeof(sRGB_RGB_LUT)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_sRGB_RGB_LUT fail	%d != %d\n",table_size,sizeof(sRGB_RGB_LUT));
				ret = 2;
				break;
			}
			if (copy_from_user(&sRGB_RGB_LUT, (void __user *)arg, (sizeof(sRGB_RGB_LUT)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_sRGB_RGB_LUT fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_sRGB_YUV2RGB:
		{
			if(table_size!=sizeof(sRGB_YUV2RGB)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_sRGB_YUV2RGB fail	%d != %d\n",table_size,sizeof(sRGB_YUV2RGB));
				ret = 2;
				break;
			}
			if (copy_from_user(&sRGB_YUV2RGB, (void __user *)arg, (sizeof(sRGB_YUV2RGB)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_sRGB_YUV2RGB fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_sRGB_RGB2YUV:
		{
			if(table_size!=sizeof(sRGB_RGB2YUV)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_sRGB_RGB2YUV fail	%d != %d\n",table_size,sizeof(sRGB_RGB2YUV));
				ret = 2;
				break;
			}
			if (copy_from_user(&sRGB_RGB2YUV, (void __user *)arg, (sizeof(sRGB_RGB2YUV)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_sRGB_RGB2YUV fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_sRGB_APPLY:
		{
			if(table_size!=sizeof(sRGB_APPLY)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_sRGB_APPLY fail	%d != %d\n",table_size,sizeof(sRGB_APPLY));
				ret = 2;
				break;
			}
			if (copy_from_user(&sRGB_APPLY, (void __user *)arg, (sizeof(sRGB_APPLY)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_sRGB_APPLY fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_YUV2RGB_Matrix_COEF_601_YCbCr:
		{
			if(table_size!=sizeof(YUV2RGB_Matrix_COEF_601_YCbCr)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_YUV2RGB_Matrix_COEF_601_YCbCr fail	%d != %d\n",table_size,sizeof(YUV2RGB_Matrix_COEF_601_YCbCr));
				ret = 2;
				break;
			}
			if (copy_from_user(&YUV2RGB_Matrix_COEF_601_YCbCr, (void __user *)arg, (sizeof(YUV2RGB_Matrix_COEF_601_YCbCr)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_YUV2RGB_Matrix_COEF_601_YCbCr fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tYUV2RGB_COEF_TVBOX_SD:
		{
			if(table_size!=sizeof(tYUV2RGB_COEF_TVBOX_SD)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tYUV2RGB_COEF_TVBOX_SD fail	%d != %d\n",table_size,sizeof(tYUV2RGB_COEF_TVBOX_SD));
				ret = 2;
				break;
			}
			if (copy_from_user(&tYUV2RGB_COEF_TVBOX_SD, (void __user *)arg, (sizeof(tYUV2RGB_COEF_TVBOX_SD)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tYUV2RGB_COEF_TVBOX_SD fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tYUV2RGB_COEF_TVBOX_HD:
		{
			if(table_size!=sizeof(tYUV2RGB_COEF_TVBOX_HD)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tYUV2RGB_COEF_TVBOX_HD fail	%d != %d\n",table_size,sizeof(tYUV2RGB_COEF_TVBOX_HD));
				ret = 2;
				break;
			}
			if (copy_from_user(&tYUV2RGB_COEF_TVBOX_HD, (void __user *)arg, (sizeof(tYUV2RGB_COEF_TVBOX_HD)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tYUV2RGB_COEF_TVBOX_HD fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tYUV2RGB_COEF_601_YCbCr_NOClampY:
		{
			if(table_size!=sizeof(tYUV2RGB_COEF_601_YCbCr_NOClampY)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tYUV2RGB_COEF_601_YCbCr_NOClampY fail	%d != %d\n",table_size,sizeof(tYUV2RGB_COEF_601_YCbCr_NOClampY));
				ret = 2;
				break;
			}
			if (copy_from_user(&tYUV2RGB_COEF_601_YCbCr_NOClampY, (void __user *)arg, (sizeof(tYUV2RGB_COEF_601_YCbCr_NOClampY)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tYUV2RGB_COEF_601_YCbCr_NOClampY fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tYUV2RGB_COEF:
		{
			if(table_size!=sizeof(tYUV2RGB_COEF)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tYUV2RGB_COEF fail	%d != %d\n",table_size,sizeof(tYUV2RGB_COEF));
				ret = 2;
				break;
			}
			if (copy_from_user(&tYUV2RGB_COEF, (void __user *)arg, (sizeof(tYUV2RGB_COEF)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tYUV2RGB_COEF fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_ConBriMapping_Offset_Table:
		{
			if(table_size!=sizeof(ConBriMapping_Offset_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_ConBriMapping_Offset_Table fail	%d != %d\n",table_size,sizeof(ConBriMapping_Offset_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&ConBriMapping_Offset_Table, (void __user *)arg, (sizeof(ConBriMapping_Offset_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_ConBriMapping_Offset_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_AVBlackLevelMapping_Table:
		{
			if(table_size!=sizeof(AVBlackLevelMapping_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_AVBlackLevelMapping_Table fail	%d != %d\n",table_size,sizeof(AVBlackLevelMapping_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&AVBlackLevelMapping_Table, (void __user *)arg, (sizeof(AVBlackLevelMapping_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_AVBlackLevelMapping_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_ATVBlackLevelMapping_Table:
		{
			if(table_size!=sizeof(ATVBlackLevelMapping_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_ATVBlackLevelMapping_Table fail	%d != %d\n",table_size,sizeof(ATVBlackLevelMapping_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&ATVBlackLevelMapping_Table, (void __user *)arg, (sizeof(ATVBlackLevelMapping_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_ATVBlackLevelMapping_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_709_YUV_0_255:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_709_YUV_0_255)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_709_YUV_0_255 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_709_YUV_0_255));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_709_YUV_0_255, (void __user *)arg, (sizeof(tRGB2YUV_COEF_709_YUV_0_255)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_709_YUV_0_255 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_709_YUV_16_235:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_709_YUV_16_235)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_709_YUV_16_235 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_709_YUV_16_235));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_709_YUV_16_235, (void __user *)arg, (sizeof(tRGB2YUV_COEF_709_YUV_16_235)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_709_YUV_16_235 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_709_RGB_0_255:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_709_RGB_0_255)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_709_RGB_0_255 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_709_RGB_0_255));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_709_RGB_0_255, (void __user *)arg, (sizeof(tRGB2YUV_COEF_709_RGB_0_255)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_709_RGB_0_255 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_709_RGB_16_235:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_709_RGB_16_235)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_709_RGB_16_235 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_709_RGB_16_235));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_709_RGB_16_235, (void __user *)arg, (sizeof(tRGB2YUV_COEF_709_RGB_16_235)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_709_RGB_16_235 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_601_RGB_0_255:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_601_RGB_0_255)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_601_RGB_0_255 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_601_RGB_0_255));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_601_RGB_0_255, (void __user *)arg, (sizeof(tRGB2YUV_COEF_601_RGB_0_255)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_601_RGB_0_255 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_601_RGB_16_235:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_601_RGB_16_235)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_601_RGB_16_235 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_601_RGB_16_235));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_601_RGB_16_235, (void __user *)arg, (sizeof(tRGB2YUV_COEF_601_RGB_16_235)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_601_RGB_16_235 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_601_YCbCr_0_255:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_601_YCbCr_0_255)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_601_YCbCr_0_255 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_601_YCbCr_0_255));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_601_YCbCr_0_255, (void __user *)arg, (sizeof(tRGB2YUV_COEF_601_YCbCr_0_255)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_601_YCbCr_0_255 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_601_YCbCr_16_235:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_601_YCbCr_16_235)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_601_YCbCr_16_235 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_601_YCbCr_16_235));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_601_YCbCr_16_235, (void __user *)arg, (sizeof(tRGB2YUV_COEF_601_YCbCr_16_235)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_601_YCbCr_16_235 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_601_YCbCr_16_255:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_601_YCbCr_16_255)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_601_YCbCr_16_255 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_601_YCbCr_16_255));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_601_YCbCr_16_255, (void __user *)arg, (sizeof(tRGB2YUV_COEF_601_YCbCr_16_255)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_601_YCbCr_16_255 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_TVBOX_SD:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_TVBOX_SD)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_TVBOX_SD fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_TVBOX_SD));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_TVBOX_SD, (void __user *)arg, (sizeof(tRGB2YUV_COEF_TVBOX_SD)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_TVBOX_SD fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_TVBOX_720:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_TVBOX_720)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_TVBOX_720 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_TVBOX_720));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_TVBOX_720, (void __user *)arg, (sizeof(tRGB2YUV_COEF_TVBOX_720)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_TVBOX_720 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF_TVBOX_1080:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF_TVBOX_1080)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_TVBOX_1080 fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF_TVBOX_1080));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF_TVBOX_1080, (void __user *)arg, (sizeof(tRGB2YUV_COEF_TVBOX_1080)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF_TVBOX_1080 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_tRGB2YUV_COEF:
		{
			if(table_size!=sizeof(tRGB2YUV_COEF)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF fail	%d != %d\n",table_size,sizeof(tRGB2YUV_COEF));
				ret = 2;
				break;
			}
			if (copy_from_user(&tRGB2YUV_COEF, (void __user *)arg, (sizeof(tRGB2YUV_COEF)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_tRGB2YUV_COEF fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_Local_Dimming_Table:
		{
			if(table_size!=sizeof(Local_Dimming_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Local_Dimming_Table fail	%d != %d\n",table_size,sizeof(Local_Dimming_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&Local_Dimming_Table, (void __user *)arg, (sizeof(Local_Dimming_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Local_Dimming_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_LD_Backlight_Profile_Interpolation_table:
		{
			if(table_size!=sizeof(LD_Backlight_Profile_Interpolation_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_LD_Backlight_Profile_Interpolation_table fail	%d != %d\n",table_size,sizeof(LD_Backlight_Profile_Interpolation_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&LD_Backlight_Profile_Interpolation_table, (void __user *)arg, (sizeof(LD_Backlight_Profile_Interpolation_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_LD_Backlight_Profile_Interpolation_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_LD_Data_Compensation_NewMode_2DTable:
		{
			if(table_size!=sizeof(LD_Data_Compensation_NewMode_2DTable)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_LD_Data_Compensation_NewMode_2DTable fail	%d != %d\n",table_size,sizeof(LD_Data_Compensation_NewMode_2DTable));
				ret = 2;
				break;
			}
			if (copy_from_user(&LD_Data_Compensation_NewMode_2DTable, (void __user *)arg, (sizeof(LD_Data_Compensation_NewMode_2DTable)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_LD_Data_Compensation_NewMode_2DTable fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_Local_Contrast_Table:
		{
			if(table_size!=sizeof(Local_Contrast_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Local_Contrast_Table fail	%d != %d\n",table_size,sizeof(Local_Contrast_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&Local_Contrast_Table, (void __user *)arg, (sizeof(Local_Contrast_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Local_Contrast_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_LC_Backlight_Profile_Interpolation_table:
		{
			if(table_size!=sizeof(LC_Backlight_Profile_Interpolation_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_LC_Backlight_Profile_Interpolation_table fail	%d != %d\n",table_size,sizeof(LC_Backlight_Profile_Interpolation_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&LC_Backlight_Profile_Interpolation_table, (void __user *)arg, (sizeof(LC_Backlight_Profile_Interpolation_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_LC_Backlight_Profile_Interpolation_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_LC_ToneMappingSlopePoint_Table:
		{
			if(table_size!=sizeof(LC_ToneMappingSlopePoint_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_LC_ToneMappingSlopePoint_Table fail	%d != %d\n",table_size,sizeof(LC_ToneMappingSlopePoint_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&LC_ToneMappingSlopePoint_Table, (void __user *)arg, (sizeof(LC_ToneMappingSlopePoint_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_LC_ToneMappingSlopePoint_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_DI_MA_Init_Table:
		{
			if(table_size!=sizeof(DI_MA_Init_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_DI_MA_Init_Table fail	%d != %d\n",table_size,sizeof(DI_MA_Init_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&DI_MA_Init_Table, (void __user *)arg, (sizeof(DI_MA_Init_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_DI_MA_Init_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_DI_MA_Adjust_Table:
		{
			if(table_size!=sizeof(DI_MA_Adjust_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_DI_MA_Adjust_Table fail	%d != %d\n",table_size,sizeof(DI_MA_Adjust_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&DI_MA_Adjust_Table, (void __user *)arg, (sizeof(DI_MA_Adjust_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_DI_MA_Adjust_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_di_TNR_XC_table:
		{
			if(table_size!=sizeof(di_TNR_XC_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_di_TNR_XC_table fail	%d != %d\n",table_size,sizeof(di_TNR_XC_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&di_TNR_XC_table, (void __user *)arg, (sizeof(di_TNR_XC_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_di_TNR_XC_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_Scaler_DI_Coef_table:
		{
			if(table_size!=sizeof(Scaler_DI_Coef_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Scaler_DI_Coef_table fail	%d != %d\n",table_size,sizeof(Scaler_DI_Coef_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&Scaler_DI_Coef_table, (void __user *)arg, (sizeof(Scaler_DI_Coef_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Scaler_DI_Coef_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_Adaptive_Gamma_Ctrl_Table:
		{
			if(table_size!=sizeof(Adaptive_Gamma_Ctrl_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Adaptive_Gamma_Ctrl_Table fail	%d != %d\n",table_size,sizeof(Adaptive_Gamma_Ctrl_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&Adaptive_Gamma_Ctrl_Table, (void __user *)arg, (sizeof(Adaptive_Gamma_Ctrl_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Adaptive_Gamma_Ctrl_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_OD_table:
		{
			if(table_size!=sizeof(OD_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_OD_table fail	%d != %d\n",table_size,sizeof(OD_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&OD_table, (void __user *)arg, (sizeof(OD_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_OD_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_OD_setting_table:
		{
			if(table_size!=sizeof(OD_setting_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_OD_setting_table fail	%d != %d\n",table_size,sizeof(OD_setting_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&OD_setting_table, (void __user *)arg, (sizeof(OD_setting_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_OD_setting_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_FIR_Coef_Ctrl:
		{
			if(table_size!=sizeof(FIR_Coef_Ctrl)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_FIR_Coef_Ctrl fail	%d != %d\n",table_size,sizeof(FIR_Coef_Ctrl));
				ret = 2;
				break;
			}
			if (copy_from_user(&FIR_Coef_Ctrl, (void __user *)arg, (sizeof(FIR_Coef_Ctrl)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_FIR_Coef_Ctrl fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_TwoStepSU_Table:
		{
			if(table_size!=sizeof(TwoStepSU_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_TwoStepSU_Table fail	%d != %d\n",table_size,sizeof(TwoStepSU_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&TwoStepSU_Table, (void __user *)arg, (sizeof(TwoStepSU_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_TwoStepSU_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_ScaleDown_COEF_TAB:
		{
			if(table_size!=sizeof(ScaleDown_COEF_TAB)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_ScaleDown_COEF_TAB fail	%d != %d\n",table_size,sizeof(ScaleDown_COEF_TAB));
				ret = 2;
				break;
			}
			if (copy_from_user(&ScaleDown_COEF_TAB, (void __user *)arg, (sizeof(ScaleDown_COEF_TAB)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_ScaleDown_COEF_TAB fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_PCID_table:
		{
			if(table_size!=sizeof(PCID_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_PCID_table fail	%d != %d\n",table_size,sizeof(PCID_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&PCID_table, (void __user *)arg, (sizeof(PCID_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_PCID_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_PCID2_Table:
		{
			if(table_size!=sizeof(PCID2_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_PCID2_Table fail	%d != %d\n",table_size,sizeof(PCID2_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&PCID2_Table, (void __user *)arg, (sizeof(PCID2_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_PCID2_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_PCID2_Pol_Table_R:
		{
			if(table_size!=sizeof(PCID2_Pol_Table_R)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_PCID2_Pol_Table_R fail	%d != %d\n",table_size,sizeof(PCID2_Pol_Table_R));
				ret = 2;
				break;
			}
			if (copy_from_user(&PCID2_Pol_Table_R, (void __user *)arg, (sizeof(PCID2_Pol_Table_R)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_PCID2_Pol_Table_R fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_PCID2_Pol_Table_G:
		{
			if(table_size!=sizeof(PCID2_Pol_Table_G)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_PCID2_Pol_Table_G fail	%d != %d\n",table_size,sizeof(PCID2_Pol_Table_G));
				ret = 2;
				break;
			}
			if (copy_from_user(&PCID2_Pol_Table_G, (void __user *)arg, (sizeof(PCID2_Pol_Table_G)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_PCID2_Pol_Table_G fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_PCID2_Pol_Table_B:
		{
			if(table_size!=sizeof(PCID2_Pol_Table_B)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_PCID2_Pol_Table_B fail	%d != %d\n",table_size,sizeof(PCID2_Pol_Table_B));
				ret = 2;
				break;
			}
			if (copy_from_user(&PCID2_Pol_Table_B, (void __user *)arg, (sizeof(PCID2_Pol_Table_B)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_PCID2_Pol_Table_B fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_pq_misc_MA_SNR_IESM_TBL:
		{
			if(table_size!=sizeof(pq_misc_MA_SNR_IESM_TBL)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_ fail	%d != %d\n",table_size,sizeof(pq_misc_MA_SNR_IESM_TBL));
				ret = 2;
				break;
			}
			if (copy_from_user(&pq_misc_MA_SNR_IESM_TBL, (void __user *)arg, (sizeof(pq_misc_MA_SNR_IESM_TBL)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_ fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_t_inv_GAMMA:
		{
			if(table_size!=sizeof(t_inv_GAMMA)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_t_inv_GAMMA fail	%d != %d\n",table_size,sizeof(t_inv_GAMMA));
				ret = 2;
				break;
			}
			if (copy_from_user(&t_inv_GAMMA, (void __user *)arg, (sizeof(t_inv_GAMMA)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_t_inv_GAMMA fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_t_gamma_curve_22:
		{
			if(table_size!=sizeof(t_gamma_curve_22)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_t_gamma_curve_22 fail	%d != %d\n",table_size,sizeof(t_gamma_curve_22));
				ret = 2;
				break;
			}
			if (copy_from_user(&t_gamma_curve_22, (void __user *)arg, (sizeof(t_gamma_curve_22)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_t_gamma_curve_22 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_Power1div22Gamma:
		{
			if(table_size!=sizeof(Power1div22Gamma)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Power1div22Gamma fail	%d != %d\n",table_size,sizeof(Power1div22Gamma));
				ret = 2;
				break;
			}
			if (copy_from_user(&Power1div22Gamma, (void __user *)arg, (sizeof(Power1div22Gamma)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Power1div22Gamma fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_Power22InvGamma:
		{
			if(table_size!=sizeof(Power22InvGamma)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Power22InvGamma fail	%d != %d\n",table_size,sizeof(Power22InvGamma));
				ret = 2;
				break;
			}
			if (copy_from_user(&Power22InvGamma, (void __user *)arg, (sizeof(Power22InvGamma)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Power22InvGamma fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_LinearInvGamma:
		{
			if(table_size!=sizeof(LinearInvGamma)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_LinearInvGamma fail	%d != %d\n",table_size,sizeof(LinearInvGamma));
				ret = 2;
				break;
			}
			if (copy_from_user(&LinearInvGamma, (void __user *)arg, (sizeof(LinearInvGamma)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_LinearInvGamma fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_LEDOutGamma:
		{
			if(table_size!=sizeof(LEDOutGamma)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_LEDOutGamma fail	%d != %d\n",table_size,sizeof(LEDOutGamma));
				ret = 2;
				break;
			}
			if (copy_from_user(&LEDOutGamma, (void __user *)arg, (sizeof(LEDOutGamma)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_LEDOutGamma fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_gVip_Profile_Table:
		{
			if(table_size!=sizeof(gVip_Profile_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_gVip_Profile_Table fail	%d != %d\n",table_size,sizeof(gVip_Profile_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&gVip_Profile_Table, (void __user *)arg, (sizeof(gVip_Profile_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_gVip_Profile_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_PQ_ByPass_Struct:
		{
			if(table_size!=sizeof(PQ_ByPass_Struct)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_PQ_ByPass_Struct fail	%d != %d\n",table_size,sizeof(PQ_ByPass_Struct));
				ret = 2;
				break;
			}
			if (copy_from_user(&PQ_ByPass_Struct, (void __user *)arg, (sizeof(PQ_ByPass_Struct)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_PQ_ByPass_Struct fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_PQ_check_source_table:
		{
			if(table_size!=sizeof(PQ_check_source_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_PQ_check_source_table fail	%d != %d\n",table_size,sizeof(PQ_check_source_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&PQ_check_source_table, (void __user *)arg, (sizeof(PQ_check_source_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_PQ_check_source_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_PQ_check_register_table:
		{
			if(table_size!=sizeof(PQ_check_register_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_PQ_check_register_table fail	%d != %d\n",table_size,sizeof(PQ_check_register_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&PQ_check_register_table, (void __user *)arg, (sizeof(PQ_check_register_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_PQ_check_register_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_PQ_check_register_diff_table:
		{
			if(table_size!=sizeof(PQ_check_register_diff_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_PQ_check_register_diff_table fail	%d != %d\n",table_size,sizeof(PQ_check_register_diff_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&PQ_check_register_diff_table, (void __user *)arg, (sizeof(PQ_check_register_diff_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_PQ_check_register_diff_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_I_De_XC_TBL:
		{
			if(table_size!=sizeof(I_De_XC_TBL)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_I_De_XC_TBL fail	%d != %d\n",table_size,sizeof(I_De_XC_TBL));
				ret = 2;
				break;
			}
			if (copy_from_user(&I_De_XC_TBL, (void __user *)arg, (sizeof(I_De_XC_TBL)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_I_De_XC_TBL fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_I_De_Contour_TBL:
		{
			if(table_size!=sizeof(I_De_Contour_TBL)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_I_De_Contour_TBL fail	%d != %d\n",table_size,sizeof(I_De_Contour_TBL));
				ret = 2;
				break;
			}
			if (copy_from_user(&I_De_Contour_TBL, (void __user *)arg, (sizeof(I_De_Contour_TBL)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_I_De_Contour_TBL fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_BOE_RGBW_TAB_160624:
		{
			if(table_size!=sizeof(BOE_RGBW_TAB_160624)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_BOE_RGBW_TAB_160624 fail	%d != %d\n",table_size,sizeof(BOE_RGBW_TAB_160624));
				ret = 2;
				break;
			}
			if (copy_from_user(&BOE_RGBW_TAB_160624, (void __user *)arg, (sizeof(BOE_RGBW_TAB_160624)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_BOE_RGBW_TAB_160624 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_BOE_RGBW_TAB_160713:
		{
			if(table_size!=sizeof(BOE_RGBW_TAB_160713)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_BOE_RGBW_TAB_160713 fail	%d != %d\n",table_size,sizeof(BOE_RGBW_TAB_160713));
				ret = 2;
				break;
			}
			if (copy_from_user(&BOE_RGBW_TAB_160713, (void __user *)arg, (sizeof(BOE_RGBW_TAB_160713)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_BOE_RGBW_TAB_160713 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_Output_InvOutput_Gamma:
		{
			if(table_size!=sizeof(Output_InvOutput_Gamma)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Output_InvOutput_Gamma fail	%d != %d\n",table_size,sizeof(Output_InvOutput_Gamma));
				ret = 2;
				break;
			}
			if (copy_from_user(&Output_InvOutput_Gamma, (void __user *)arg, (sizeof(Output_InvOutput_Gamma)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Output_InvOutput_Gamma fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_hdr_table:
		{
			if(table_size!=sizeof(hdr_table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_hdr_table fail	%d != %d\n",table_size,sizeof(hdr_table));
				ret = 2;
				break;
			}
			if (copy_from_user(&hdr_table, (void __user *)arg, (sizeof(hdr_table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_hdr_table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_hdr_YUV2RGB:
		{
			if(table_size!=sizeof(hdr_YUV2RGB)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_hdr_YUV2RGB fail	%d != %d\n",table_size,sizeof(hdr_YUV2RGB));
				ret = 2;
				break;
			}
			if (copy_from_user(&hdr_YUV2RGB, (void __user *)arg, (sizeof(hdr_YUV2RGB)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_hdr_YUV2RGB fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_hdr_RGB2OPT:
		{
			if(table_size!=sizeof(hdr_RGB2OPT)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_hdr_RGB2OPT fail	%d != %d\n",table_size,sizeof(hdr_RGB2OPT));
				ret = 2;
				break;
			}
			if (copy_from_user(&hdr_RGB2OPT, (void __user *)arg, (sizeof(hdr_RGB2OPT)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_hdr_RGB2OPT fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_HDR10_3DLUT_17x17x17:
		{
			if(table_size!=sizeof(HDR10_3DLUT_17x17x17)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_HDR10_3DLUT_17x17x17 fail	%d != %d\n",table_size,sizeof(HDR10_3DLUT_17x17x17));
				ret = 2;
				break;
			}
			if (copy_from_user(&HDR10_3DLUT_17x17x17, (void __user *)arg, (sizeof(HDR10_3DLUT_17x17x17)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_HDR10_3DLUT_17x17x17 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_EOTF_LUT_HLG_DEFAULT:
		{
			if(table_size!=sizeof(EOTF_LUT_HLG_DEFAULT)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_EOTF_LUT_HLG_DEFAULT fail	%d != %d\n",table_size,sizeof(EOTF_LUT_HLG_DEFAULT));
				ret = 2;
				break;
			}
			if (copy_from_user(&EOTF_LUT_HLG_DEFAULT, (void __user *)arg, (sizeof(EOTF_LUT_HLG_DEFAULT)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_EOTF_LUT_HLG_DEFAULT fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_OETF_LUT_HLG_DEFAULT:
		{
			if(table_size!=sizeof(OETF_LUT_HLG_DEFAULT)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_OETF_LUT_HLG_DEFAULT fail	%d != %d\n",table_size,sizeof(OETF_LUT_HLG_DEFAULT));
				ret = 2;
				break;
			}
			if (copy_from_user(&OETF_LUT_HLG_DEFAULT, (void __user *)arg, (sizeof(OETF_LUT_HLG_DEFAULT)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_OETF_LUT_HLG_DEFAULT fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_EOTF_LUT_R:
		{
			if(table_size!=sizeof(EOTF_LUT_R)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_EOTF_LUT_R fail	%d != %d\n",table_size,sizeof(EOTF_LUT_R));
				ret = 2;
				break;
			}
			if (copy_from_user(&EOTF_LUT_R, (void __user *)arg, (sizeof(EOTF_LUT_R)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_EOTF_LUT_R fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_OETF_LUT_R:
		{
			if(table_size!=sizeof(OETF_LUT_R)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_OETF_LUT_R fail	%d != %d\n",table_size,sizeof(OETF_LUT_R));
				ret = 2;
				break;
			}
			if (copy_from_user(&OETF_LUT_R, (void __user *)arg, (sizeof(OETF_LUT_R)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_OETF_LUT_R fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_Tone_Mapping_LUT_R:
		{
			#if 0
			if(table_size!=sizeof(Tone_Mapping_LUT_R)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_Tone_Mapping_LUT_R fail	%d != %d\n",table_size,sizeof(Tone_Mapping_LUT_R));
				ret = 2;
				break;
			}
			if (copy_from_user(&Tone_Mapping_LUT_R, (void __user *)arg, (sizeof(Tone_Mapping_LUT_R)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_Tone_Mapping_LUT_R fail\n");
				ret = 1;
				break;
			}
			#endif
		}
		break;

		case VPQUT_IOC_SET_HDR10_3DLUT_24x24x24:
		{
			if(table_size!=sizeof(HDR10_3DLUT_24x24x24)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_HDR10_3DLUT_24x24x24 fail	%d != %d\n",table_size,sizeof(HDR10_3DLUT_24x24x24));
				ret = 2;
				break;
			}
			if (copy_from_user(&HDR10_3DLUT_24x24x24, (void __user *)arg, (sizeof(HDR10_3DLUT_24x24x24)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_HDR10_3DLUT_24x24x24 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_HLG_3DLUT_24x24x24:
		{
			if(table_size!=sizeof(HLG_3DLUT_24x24x24)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_HLG_3DLUT_24x24x24 fail	%d != %d\n",table_size,sizeof(HLG_3DLUT_24x24x24));
				ret = 2;
				break;
			}
			if (copy_from_user(&HLG_3DLUT_24x24x24, (void __user *)arg, (sizeof(HLG_3DLUT_24x24x24)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_HLG_3DLUT_24x24x24 fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_HLG_OETF_LUT_R:
		{
			if(table_size!=sizeof(HLG_OETF_LUT_R)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_HLG_OETF_LUT_R fail	%d != %d\n",table_size,sizeof(HLG_OETF_LUT_R));
				ret = 2;
				break;
			}
			if (copy_from_user(&HLG_OETF_LUT_R, (void __user *)arg, (sizeof(HLG_OETF_LUT_R)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_HLG_OETF_LUT_R fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_HLG_EOTF_LUT_R:
		{
			if(table_size!=sizeof(HLG_EOTF_LUT_R)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_HLG_EOTF_LUT_R fail	%d != %d\n",table_size,sizeof(HLG_EOTF_LUT_R));
				ret = 2;
				break;
			}
			if (copy_from_user(&HLG_EOTF_LUT_R, (void __user *)arg, (sizeof(HLG_EOTF_LUT_R)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_HLG_EOTF_LUT_R fail\n");
				ret = 1;
				break;
			}
		}
		break;
#if 0 	/* juwen, move to "tc_hdr", elieli */
		case VPQUT_IOC_SET_TCHDR_Table:
		{
			if(table_size!=sizeof(TCHDR_Table)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_TCHDR_Table fail	%d != %d\n",table_size,sizeof(TCHDR_Table));
				ret = 2;
				break;
			}
			if (copy_from_user(&TCHDR_Table, (void __user *)arg, (sizeof(TCHDR_Table)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_TCHDR_Table fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_TCHDR_COEF_C_LUT_TBL:
		{
			if(table_size!=sizeof(TCHDR_COEF_C_LUT_TBL)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_TCHDR_COEF_C_LUT_TBL fail	%d != %d\n",table_size,sizeof(TCHDR_COEF_C_LUT_TBL));
				ret = 2;
				break;
			}
			if (copy_from_user(&TCHDR_COEF_C_LUT_TBL, (void __user *)arg, (sizeof(TCHDR_COEF_C_LUT_TBL)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_TCHDR_COEF_C_LUT_TBL fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_TCHDR_COEF_I_LUT_TBL:
		{
			if(table_size!=sizeof(TCHDR_COEF_I_LUT_TBL)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_TCHDR_COEF_I_LUT_TBL fail	%d != %d\n",table_size,sizeof(TCHDR_COEF_I_LUT_TBL));
				ret = 2;
				break;
			}
			if (copy_from_user(&TCHDR_COEF_I_LUT_TBL, (void __user *)arg, (sizeof(TCHDR_COEF_I_LUT_TBL)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_TCHDR_COEF_I_LUT_TBL fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_TCHDR_COEF_S_LUT_TBL:
		{
			if(table_size!=sizeof(TCHDR_COEF_S_LUT_TBL)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_TCHDR_COEF_S_LUT_TBL fail	%d != %d\n",table_size,sizeof(TCHDR_COEF_S_LUT_TBL));
				ret = 2;
				break;
			}
			if (copy_from_user(&TCHDR_COEF_S_LUT_TBL, (void __user *)arg, (sizeof(TCHDR_COEF_S_LUT_TBL)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_TCHDR_COEF_S_LUT_TBL fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_TCHDR_COEF_P_LUT_TBL:
		{
			if(table_size!=sizeof(TCHDR_COEF_P_LUT_TBL)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_TCHDR_COEF_P_LUT_TBL fail	%d != %d\n",table_size,sizeof(TCHDR_COEF_P_LUT_TBL));
				ret = 2;
				break;
			}
			if (copy_from_user(&TCHDR_COEF_P_LUT_TBL, (void __user *)arg, (sizeof(TCHDR_COEF_P_LUT_TBL)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_TCHDR_COEF_P_LUT_TBL fail\n");
				ret = 1;
				break;
			}
		}
		break;

		case VPQUT_IOC_SET_TCHDR_COEF_D_LUT_TBL:
		{
			if(table_size!=sizeof(TCHDR_COEF_D_LUT_TBL)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_TCHDR_COEF_D_LUT_TBL fail	%d != %d\n",table_size,sizeof(TCHDR_COEF_D_LUT_TBL));
				ret = 2;
				break;
			}
			if (copy_from_user(&TCHDR_COEF_D_LUT_TBL, (void __user *)arg, (sizeof(TCHDR_COEF_D_LUT_TBL)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_TCHDR_COEF_D_LUT_TBL fail\n");
				ret = 1;
				break;
			}
		}
		break;
#endif
#if 0
		case VPQUT_IOC_SET_:
		{
			if(table_size!=sizeof(tVipNewDcti_auto_adjust)){
				printk(KERN_EMERG "[error][size]vpqut ioctl VPQUT_IOC_SET_ fail	%d != %d\n",table_size,sizeof(tVipNewDcti_auto_adjust));
				ret = 2;
				break;
			}
			if (copy_from_user(&tVipNewDcti_auto_adjust, (void __user *)arg, (sizeof(tVipNewDcti_auto_adjust)))) {
				printk(KERN_EMERG "[error][copy_from_user]vpqut ioctl VPQUT_IOC_SET_ fail\n");
				ret = 1;
				break;
			}
		}
		break;
#endif
	}
	return ret;
}


struct file_operations vpqut_fops = {
	.owner = THIS_MODULE,
	.open = vpqut_open,
	.release = vpqut_release,
	.read  = vpqut_read,
	.write = vpqut_write,
	.unlocked_ioctl = vpqut_ioctl,
};

static struct class *vpqut_class = NULL;
static struct platform_device *vpqut_platform_devs = NULL;
static struct platform_driver vpqut_platform_driver = {
	.driver = {
		.name = "vpqutheck",
		.bus = &platform_bus_type,
    },
} ;

static char *vpqut_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

int vpqut_module_init(void)
{
	int result;
	result = alloc_chrdev_region(&vpqut_dev, 0, 1, "vpqutdev");

	if (result != 0) {
		rtd_printk(KERN_ERR, TAG_NAME, "Cannot allocate VPQ device number\n");
		return result;
	}

	vpqut_class = class_create(THIS_MODULE, "vpqutdev");
	if (IS_ERR(vpqut_class)) {
		rtd_printk(KERN_ERR, TAG_NAME, "scalevpqut: can not create class...\n");
		result = PTR_ERR(vpqut_class);
		goto fail_class_create;
	}

	vpqut_class->devnode = vpqut_devnode;

	vpqut_platform_devs = platform_device_register_simple("vpqutdev", -1, NULL, 0);
	if (platform_driver_register(&vpqut_platform_driver) != 0) {
		rtd_printk(KERN_ERR, TAG_NAME, "scalevpqut: can not register platform driver...\n");
		result = -ENOMEM;
		goto fail_platform_driver_register;
	}

	cdev_init(&vpqut_cdev, &vpqut_fops);
	result = cdev_add(&vpqut_cdev, vpqut_dev, 1);
	if (result < 0) {
		rtd_printk(KERN_ERR, TAG_NAME, "scalevpqut: can not add character device...\n");
		goto fail_cdev_init;
	}

	device_create(vpqut_class, NULL, vpqut_dev, NULL, "vpqutdev");

	sema_init(&VPQUT_Semaphore, 1);

	#ifdef CONFIG_RTK_USBDUMP_ENABLE
	checkusb_tsk = kthread_create(checkusb_file, NULL, "check_usb");
	if (checkusb_tsk) {
		wake_up_process(checkusb_tsk);
	}else{
		rtd_printk(KERN_ERR, TAG_NAME, "scalevpqut: kthread_create error...\n");
	}
	#endif
	
	return 0;/*Success*/

fail_cdev_init:
	platform_driver_unregister(&vpqut_platform_driver);
fail_platform_driver_register:
	platform_device_unregister(vpqut_platform_devs);
	vpqut_platform_devs = NULL;
	class_destroy(vpqut_class);
fail_class_create:
	vpqut_class = NULL;
	unregister_chrdev_region(vpqut_dev, 1);
	return result;

}



void __exit vpqut_module_exit(void)
{
	if (vpqut_platform_devs == NULL)
		BUG();

	kthread_stop(checkusb_tsk);

	device_destroy(vpqut_class, vpqut_dev);
	cdev_del(&vpqut_cdev);

	platform_driver_unregister(&vpqut_platform_driver);
	platform_device_unregister(vpqut_platform_devs);
	vpqut_platform_devs = NULL;

	class_destroy(vpqut_class);
	vpqut_class = NULL;

	unregister_chrdev_region(vpqut_dev, 1);

}

module_init(vpqut_module_init);
module_exit(vpqut_module_exit);
