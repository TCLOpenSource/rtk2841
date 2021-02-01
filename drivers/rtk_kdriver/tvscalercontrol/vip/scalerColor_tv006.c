#if CONFIG_FIRMWARE_IN_KERNEL

#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
//#include <mach/RPCDriver.h>
#include <linux/pageremap.h>
/*some include about AP*/
#include <tvscalercontrol/scaler/scalercolorlib.h>
#include <tvscalercontrol/scaler/scalertimer.h>
#include <tvscalercontrol/io/ioregdrv.h>

/*some include about VIP Driver*/
/*#include <tvscalercontrol/vip/scalerColor.h>*/
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/vip/scalerColor_tv006.h>
#include <tvscalercontrol/vip/di_ma.h>
#include <tvscalercontrol/vip/peaking.h>
#include <tvscalercontrol/vip/icm.h>
#include <tvscalercontrol/vip/dcc.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/vip/color.h>
#include <tvscalercontrol/vip/xc.h>
#include <tvscalercontrol/vip/intra.h>
#include <tvscalercontrol/vip/nr.h>
#include <tvscalercontrol/vip/film.h>
#include <tvscalercontrol/vip/pq_adaptive.h>
#include <tvscalercontrol/vip/gibi_od.h>
#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/vip/localdimming.h>
#include <tvscalercontrol/vip/localcontrast.h>

/*some include about scaler*/
#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
/*some include about rbus*/
/*some include about device driver*/
#include <tvscalercontrol/hdmirx/hdmifun.h>
//#include <tvscalercontrol/hdmirx/hdmiInternal.h>
#include <mach/rtk_log.h>
//#include <mach/io.h>
#define TAG_NAME "VPQ"

// for register dump
#include <tvscalercontrol/io/ioregdrv.h>
#undef rtd_outl
#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#undef rtd_inl
#define rtd_inl(x)     									IoReg_Read32(x)
#undef rtd_maskl
#define rtd_maskl(x, y, z)     							IoReg_Mask32(x,y,z)
#undef rtd_setbits
#define rtd_setbits(offset, Mask) rtd_outl(offset, (rtd_inl(offset) | Mask))
#undef rtd_clearbits
#define rtd_clearbits(offset, Mask) rtd_outl(offset, ((rtd_inl(offset) & ~(Mask))))

#else

/*some include about AP*/
#include <Platform_Lib/TVScalerControl/scaler/scalerLib.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerColorLib.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerTimer.h>
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>

/*some include about VIP Driver*/
/*#include <tvscalercontrol/vip/scalerColor.h>*/
#include <Platform_Lib/TVScalerControl/vip/scalerColor_tv006.h>
#include <Platform_Lib/TVScalerControl/vip/di_ma.h>
#include <Platform_Lib/TVScalerControl/vip/peaking.h>
#include <Platform_Lib/TVScalerControl/vip/icm.h>
#include <Platform_Lib/TVScalerControl/vip/dcc.h>
#include <Platform_Lib/TVScalerControl/vip/ultrazoom.h>
#include <Platform_Lib/TVScalerControl/vip/color.h>
#include <Platform_Lib/TVScalerControl/vip/xc.h>
#include <Platform_Lib/TVScalerControl/vip/intra.h>
#include <Platform_Lib/TVScalerControl/vip/nr.h>
#include <Platform_Lib/TVScalerControl/vip/film.h>
#include <Platform_Lib/TVScalerControl/vip/pq_adaptive.h>
#include <Platform_Lib/TVScalerControl/vip/gibi_od.h>
#include <Platform_Lib/TVScalerControl/vdc/video.h>
#include <Platform_Lib/TVScalerControl/vip/localdimming.h>
#include <Platform_Lib/TVScalerControl/vip/localcontrast.h>

/*some include about scaler*/
#include <scaler/scalerDrvCommon.h>
#include <rbusHistogramReg.h>
/*some include about rbus*/
/*some include about device driver*/
//#include <Platform_Lib/TVScalerControl/hdmiRx/hdmiFun.h>
#endif
#if CONFIG_FIRMWARE_IN_KERNEL
//#define VIPprintf(fmt, args...)	printk(KERN_DEBUG fmt, ##args)	//20150822 roger mark for image release
#define VIPprintf(fmt, args...)
#define	vip_malloc(x)	kmalloc(x, GFP_KERNEL)
#define	vip_free(x)	kfree(x)
#else
//#define VIPprintf(fmt, args...)	printf(fmt, ##args)	//20150822 roger mark for image release
#define VIPprintf(fmt, args...)
#define	vip_malloc(x)	malloc(x)
#define	vip_free(x)	free(x)
#endif
extern unsigned int vpq_project_id; /*pre_id:16 main_id:8 sub1_id:8 sub2_id:8, example->lg=tv006*/


#define Monotonic_Check 1 // Mac5p fix me : temporary shift 2 bits, need to modify webos code and VIP panel tables

static RGB2YUV_BLACK_LEVEL rgb2yuv_bl_tv006 = RGB2YUV_BLACK_LEVEL_AUTO;
CHIP_NOISE_REDUCTION_T *pNR_Table_tv006;
CHIP_MPEG_NOISE_REDUCTION_T *pMPEGNR_Table_tv006;
extern unsigned short tYUV2RGB_COEF[YUV2RGB_TBL_SELECT_ITEM_MAX][tUV2RGB_COEF_Items_Max];

extern unsigned short Power22InvGamma[1025];
extern unsigned short LinearInvGamma[1025];
unsigned char bCinemaModeEn;
unsigned char bNr_Input=0;
extern unsigned char vsc_get_adaptivestream_flag(void);

unsigned short OutGamma_4CHDGA_R[257];
unsigned short OutGamma_4CHDGA_G[257];
unsigned short OutGamma_4CHDGA_B[257];
unsigned short OutGamma_4CHDGA_W[257];


extern UINT32 EOTF_LUT_HLG_DEFAULT[1025];
extern UINT16 OETF_LUT_HLG_DEFAULT[1025];
extern unsigned int PQModeInfo_flag[5];
unsigned int Ori_PQA_Table[PQA_TABLE_MAX][PQA_MODE_MAX][PQA_ITEM_MAX][PQA_LEVEL_MAX];

void fwif_color_set_rgb2yuv_black_level_tv006(RGB2YUV_BLACK_LEVEL lv)
{
	_system_setting_info *VIP_system_info_structure_table = NULL;

	rgb2yuv_bl_tv006 = lv;

	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		VIPprintf("~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	VIP_system_info_structure_table->OSD_Info.OSD_Film_Mode = lv; // borrow film mode flag, transfer black level to video f/w


}

RGB2YUV_BLACK_LEVEL fwif_color_get_rgb2yuv_black_level_tv006(void)
{
	return rgb2yuv_bl_tv006;
}

unsigned char fwif_color_get_colorspacergb2yuvtransfer_table_tv006(unsigned char channel, unsigned char nSrcType, unsigned char nSD_HD, bool bUse_HDMI_Range_Detect)
{
	unsigned char video_format;
	/*unsigned short *table_index = 0;*/
	unsigned char table_num;
	unsigned char CHOOSE_DATA_RANGE = 1;
	UINT8 data_range = 0; /*morgan_shen  20121112  choose rgb2yuv table by the flag of data range.*/
	RGB2YUV_BLACK_LEVEL blk_lv = fwif_color_get_rgb2yuv_black_level_tv006();
	UINT8 isBt2020_Vo =0, isBt2020_HDMI = 0;
	UINT8 isHDMIFullRangeYCC = 0;
	SLR_VOINFO* pVOInfo = NULL;
	/*pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());*/

	HDMI_AVI_T pAviInfo;
	/*drvif_Hdmi_GetAviInfoFrame((unsigned char*) (&pAviInfo)); //pAviInfo size = 16 bytes*/

	extern unsigned char RGB2YUV_if_RGB_mode;
	/*extern unsigned short tRGB2YUV_COEF_YCC601_BYPASS_NORMAL_GAIN[];*/
	/*extern unsigned short tRGB2YUV_COEF_YCC709_BYPASS_NORMAL_GAIN[];*/
	/*extern unsigned short tRGB2YUV_COEF_YCC601_0_255_TO_YCC601_16_235[];*/
	/*extern unsigned short tRGB2YUV_COEF_YCC709_0_255_TO_YCC709_16_235[];*/
	/*extern unsigned short tRGB2YUV_COEF_YCC709_16_235_TO_YCC601_16_235[];*/
	/*extern unsigned short tRGB2YUV_COEF_YCC709_0_255_TO_YCC601_16_235[];*/
	/*extern unsigned short tRGB2YUV_COEF_BYPASS_NORMAL_GAIN[];*/
	/*extern unsigned short tRGB2YUV_COEF_BYPASS_0_255_TO_16_235[];*/
	/*extern unsigned short tRGB2YUV_COEF_RGB_0_255_TO_YCC601_16_235[];*/
	/*extern unsigned short tRGB2YUV_COEF_RGB_16_235_TO_YCC601_16_235[];*/
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	if (RGB2YUV_BLACK_LEVEL_AUTO == blk_lv)
		bUse_HDMI_Range_Detect = true;
	else
		bUse_HDMI_Range_Detect = false;

	if (fwif_color_get_force_run_i3ddma_enable(channel)) {
		if (nSrcType == _SRC_HDMI) {
			if (drvif_IsHDMI() && drvif_Hdmi_GetColorSpace() != 0 && (Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_MODECURR) != _MODE_NEW)) {
				extern unsigned int vpqex_project_id;
				if (vpqex_project_id == 0x00060000) {
					if (drvif_Hdmi_GetColorSpace() != 0)
						isHDMIFullRangeYCC = drvif_IsRGB_YUV_RANGE()==MODE_RAG_FULL?1:0;
				} else {
					switch(Scaler_GetHDMI_CSC_DataRange_Mode()) {
					case HDMI_CSC_DATA_RANGE_MODE_AUTO:
						isHDMIFullRangeYCC = drvif_IsRGB_YUV_RANGE()==MODE_RAG_FULL?1:0;
						break;
					case HDMI_CSC_DATA_RANGE_MODE_FULL:
						isHDMIFullRangeYCC = 1;
						break;
					case HDMI_CSC_DATA_RANGE_MODE_LIMITED:
					default:
						isHDMIFullRangeYCC = 0;
						break;
						;
					}
				}
			}
		}
		if (nSrcType == _SRC_VGA || nSrcType == _SRC_HDMI || nSrcType == _SRC_SCART_RGB)
			nSrcType = _SRC_VO;
	}

	VIPprintf("drvif_color_get_colorspacergb2yuvtransfer_table_tv006, nSrcType = %d, nSD_HD = %d\n", nSrcType, nSD_HD);

	/* for bt2020*/
	if (VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag == 1 && VIP_system_info_structure_table->BT2020_CTRL.Mode == BT2020_MODE_Constant) {
		table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
		VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_2020_ConstantY;
		return table_num;
	} else if (VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag == 1 && VIP_system_info_structure_table->BT2020_CTRL.Mode == BT2020_MODE_Non_Constant) {
		table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
		VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_2020_NonConstantY;
		return table_num;
	}

		if (nSrcType == _SRC_VGA) {
			if (RGB2YUV_BLACK_LEVEL_LOW == blk_lv) {
				if (!nSD_HD) {
					table_num = RGB2YUV_COEF_RGB_16_235_TO_YCC601_16_235;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
				} else {
					table_num = RGB2YUV_COEF_RGB_16_235_TO_YCC709_16_235;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
				}
			} else {
				if (!nSD_HD) {
					table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC601_16_235;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
				} else {
					table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC709_16_235;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
				}
			}
			RGB2YUV_if_RGB_mode = TRUE;

		} else if ((nSrcType == _SRC_YPBPR) || (nSrcType == _SRC_COMPONENT))  {
			if (RGB2YUV_BLACK_LEVEL_HIGH == blk_lv) {
				if (!nSD_HD) {
					table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
				} else {
					table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
				}
			} else {
				if (!nSD_HD) {
					table_num = RGB2YUV_COEF_TV006_YPP_LOW;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
				} else {
					table_num = RGB2YUV_COEF_TV006_YPP_LOW;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
				}
			}
		} else if (nSrcType == _SRC_SCART_RGB) {
			if (RGB2YUV_BLACK_LEVEL_HIGH == blk_lv) {
				if (!nSD_HD) {
					table_num = RGB2YUV_COEF_BYPASS_0_255_TO_16_235;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
				} else {
					table_num = RGB2YUV_COEF_BYPASS_0_255_TO_16_235;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
				}
			} else {
				if (!nSD_HD) {
					table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
				} else {
					table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
					VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
				}
			}
		} else if ((nSrcType == _SRC_TV) || (nSrcType == _SRC_CVBS) || (nSrcType == _SRC_SV) || (nSrcType == _SRC_SCART)) {
			table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
			VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
		} else if (nSrcType == _SRC_HDMI) {
			video_format = drvif_Hdmi_GetColorSpace();
			VIPprintf(" == =  RGB2YUV video_format = %d == = 	\n", video_format);
			if (CHOOSE_DATA_RANGE) {
				data_range = drvif_IsRGB_YUV_RANGE();  /*0 :default 1 : Limited Range 2: Full Range*/
				VIPprintf(" == =  RGB2YUV  DATA_RANGE = %d  (0 :default 1 : Limited Range 2: Full Range) == =   \n", data_range);
			}
			/* get csc*/
			drvif_Hdmi_GetAviInfoFrame((unsigned char*) (&pAviInfo)); //pAviInfo size = 16 bytes
			if (pAviInfo.EC == 5 || pAviInfo.EC == 6)
				isBt2020_HDMI = 1;
			else
				isBt2020_HDMI = 0;

			if (drvif_IsHDMI() && (Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_MODECURR) != _MODE_NEW)) /*HDMI Video Mode,  gary for xoceco 20071227*/{
				if (video_format !=  0) {/*YUV444 or YUV422*/
					if (!nSD_HD) {
						if ((bUse_HDMI_Range_Detect && data_range == MODE_RAG_FULL) || (RGB2YUV_BLACK_LEVEL_HIGH == blk_lv)) {
							table_num = RGB2YUV_COEF_BYPASS_0_255_TO_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
						} else {
							table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
						}
					} else {
						if ((bUse_HDMI_Range_Detect && data_range == MODE_RAG_FULL) || (RGB2YUV_BLACK_LEVEL_HIGH == blk_lv)) {
							table_num = RGB2YUV_COEF_BYPASS_0_255_TO_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
						} else {
							table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
						}
						}
						VIPprintf("RGB2YUV_SRC_HDMI_YUV\n");
				} else {/*RGB*/

					RGB2YUV_if_RGB_mode = TRUE;
					if (RGB2YUV_BLACK_LEVEL_LOW == blk_lv) {
						if (isBt2020_HDMI == 1) {
							table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC2020_0_255;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_2020_NonConstantY;
						} else if (!nSD_HD) {
							table_num = RGB2YUV_COEF_RGB_16_235_TO_YCC601_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
						} else {
							table_num = RGB2YUV_COEF_RGB_16_235_TO_YCC709_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
						}
					} else {
						if (isBt2020_HDMI == 1) {
							table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC2020_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_2020_NonConstantY;
						} else if (!nSD_HD) {
							table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC601_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
						} else {
							table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC709_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
						}
					}

					VIPprintf("RGB2YUV_SRC_HDMI_RGB\n");
				}
			} else { /*DVI mode*/
				if ((video_format&(_BIT4|_BIT5))) { /*YUV444 or YUV422*/
					if (!nSD_HD) {
						if (RGB2YUV_BLACK_LEVEL_HIGH == blk_lv) {
							table_num = RGB2YUV_COEF_BYPASS_0_255_TO_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
						} else {
							table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
						}
					} else {
						if (RGB2YUV_BLACK_LEVEL_HIGH == blk_lv) {
							table_num = RGB2YUV_COEF_BYPASS_0_255_TO_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
						} else {
							table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
						}
					}
					VIPprintf("RGB2YUV_SRC_DVI_YUV\n");
				} else {/*RGB*/
					RGB2YUV_if_RGB_mode = TRUE;
					if (RGB2YUV_BLACK_LEVEL_LOW == blk_lv) {
						if (!nSD_HD) {
							table_num = RGB2YUV_COEF_RGB_16_235_TO_YCC601_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
						} else {
							table_num = RGB2YUV_COEF_RGB_16_235_TO_YCC709_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
						}
					} else {
						if (!nSD_HD) {
							table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC601_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
						} else {
							table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC709_16_235;
							VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
						}
					}
					VIPprintf("RGB2YUV_SRC_DVI_RGB\n");
				}
			}
		} else if (nSrcType == _SRC_VO) {
			/*GAME source must enter RGB to YUV*/
			/*if (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane()) == 2)*/
			pVOInfo = Scaler_VOInfoPointer(Scaler_Get_CurVoInfo_plane());
			if (pVOInfo == NULL) {
				isBt2020_Vo = 0;
			} else {
				if (pVOInfo->colour_primaries == 9)	/* bt2020*/
					isBt2020_Vo = 1;
				else
					isBt2020_Vo = 0;
			}

		    if ((Scaler_DispGetInputInfo(SLR_INPUT_COLOR_SPACE) == COLOR_RGB) || (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane()) == 2)) {
				if (RGB2YUV_BLACK_LEVEL_LOW == blk_lv) {
					if (isBt2020_Vo == 1) {
						table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC2020_0_255;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_2020_NonConstantY;
					}
					else if (!nSD_HD) {
						table_num = RGB2YUV_COEF_RGB_16_235_TO_YCC601_16_235;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
					} else {
						table_num = RGB2YUV_COEF_RGB_16_235_TO_YCC709_16_235;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
					}
				} else {
					if (isBt2020_Vo == 1) {
						table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC2020_16_235;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_2020_NonConstantY;
					}
					else if (!nSD_HD) {
						table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC601_16_235;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
					} else {
						table_num = RGB2YUV_COEF_RGB_0_255_TO_YCC709_16_235;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
					}
				}
			} else if (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane()) == 0) { /*DTV source*/
				if (RGB2YUV_BLACK_LEVEL_HIGH == blk_lv || isHDMIFullRangeYCC) {
					if (!nSD_HD) {
						table_num = RGB2YUV_COEF_BYPASS_0_255_TO_16_235;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
					} else {
						table_num = RGB2YUV_COEF_BYPASS_0_255_TO_16_235;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
					}
				} else {
					if (!nSD_HD) {
						table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
					} else {
						table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
					}
				}
			} else {  /*Jpeg source*/
				if (RGB2YUV_BLACK_LEVEL_HIGH == blk_lv) {
					if (!nSD_HD) {
						table_num = RGB2YUV_COEF_BYPASS_0_255_TO_16_235;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
					} else {
						table_num = RGB2YUV_COEF_BYPASS_0_255_TO_16_235;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
					}
				} else {
					if (!nSD_HD) {
						table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
					} else {
						table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
						VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_709_Limted;
					}
				}
			}
			if (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_JPEG)
				VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
		} else {
			/*which_tab = 0;*/
			VIPprintf("unhandler type%d\n", nSrcType);
			table_num = RGB2YUV_COEF_BYPASS_NORMAL_GAIN;
			VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode = YUV2RGB_INPUT_601_Limted;
			/*return NULL;*/
	  }
	  return table_num;

}

void fwif_color_Set_NR_Table_tv006(CHIP_NOISE_REDUCTION_T *ptr)
{
	if (ptr == NULL) {
		VIPprintf("fwif_color_Set_NR_Table_tv006 error\n");
		return;
	}
	pNR_Table_tv006 = ptr;
	VIPprintf(" == = Set_NR_Table_tv006 == = \n");

}
CHIP_NOISE_REDUCTION_T *fwif_color_Get_NR_Table_tv006(void)
{
	if (pNR_Table_tv006 == NULL) {
		VIPprintf("pNR_Table_tv006 is NULL\n");
		return NULL;
	}
	return (CHIP_NOISE_REDUCTION_T *)pNR_Table_tv006;

}

unsigned char fwif_color_GetDNR_tv006()
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		VIPprintf("~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}

	return VIP_system_info_structure_table->OSD_Info.OSD_NR_Mode;
}

void fwif_color_SetDNR_tv006(unsigned char level)
{
	SLR_VIP_TABLE *gVip_Table = NULL;
	CHIP_NOISE_REDUCTION_T *pNR_Table =NULL;
	unsigned int *PQA_TABLE = NULL;
	unsigned int *PQA_TABLE_OFFSET_TEMP = NULL;

	/*=== 20140421 CSFC for vip video fw infomation ====*/
	_system_setting_info *VIP_system_info_structure_table = NULL;
	UINT8 source=255,pqa_table_idx=0,pqa_input_idx=0;


	VIPprintf("fwif_color_SetDNR		%d\n", level);


	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		VIPprintf("~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	VIP_system_info_structure_table->OSD_Info.OSD_NR_Mode = level;
	/*====================================*/

	gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (gVip_Table == NULL) {
		VIPprintf("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	/*get pqa table index need check source first. because ap flow or table index will get incorrect table*/
	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);/* get vip source by input src and timing*/
	if (source >= VIP_QUALITY_SOURCE_NUM)
		source = 0;

	if(fwif_color_get_NR_Input_tv006()!= 12) //12 is webcam. it is from hal for web cam special case.
	{
	pqa_table_idx = gVip_Table->VIP_QUALITY_Extend3_Coef[source][VIP_QUALITY_FUNCTION_PQA_Table];
		pqa_input_idx = gVip_Table->VIP_QUALITY_Extend3_Coef[source][VIP_QUALITY_FUNCTION_PQA_Input_Table];
	}
	else
	{
		pqa_table_idx = 9;
		pqa_input_idx = 9;
	}


	scaler_set_PQA_table(pqa_table_idx);
	scaler_set_PQA_Input_table(pqa_input_idx);

	PQA_TABLE = &(gVip_Table->PQA_Table[0][0][0][0]);
	PQA_TABLE_OFFSET_TEMP = &(VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.OFFSET_TEMP[0]);

	fwif_color_PQA_Input_Item_Check(VIP_system_info_structure_table, PQA_TABLE, pqa_table_idx);

	pNR_Table = fwif_color_Get_NR_Table_tv006();
	if (pNR_Table == NULL) {
		VIPprintf("~get NR_Table_tv006 Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}


	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_General_ctrl.SNR_spatialenabley = pNR_Table->LPF_Y.Spatial_Enable_Y;
	/*gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Modified_LPF.SNR_modified_lpf_enable = pNR_Table->LPF_Y.Modified_LPF_enable;*/ /*remove from K2L*/
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Modified_LPF.SNR_modified_lpf_edge_gain = pNR_Table->LPF_Y.Gain;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Modified_LPF.SNR_modified_lpf_thd_lowbnd = pNR_Table->LPF_Y.Thd_LowBnd;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Modified_LPF.SNR_modified_lpf_thd_upbnd = pNR_Table->LPF_Y.Thd_UpBnd;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Modified_LPF.SNR_modified_lpf_thd_step = pNR_Table->LPF_Y.Thd_Step;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_Y.SNR_zoranfiltersizey = pNR_Table->LPF_Y.RZ_filter_size;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_Y.SNR_zoranweight2y = pNR_Table->LPF_Y.Weight2Y;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_Y.SNR_zoranweight3y = pNR_Table->LPF_Y.Weight3Y;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_Y.SNR_zoranweight4y = pNR_Table->LPF_Y.Weight4Y;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_Y.SNR_spatialthly = pNR_Table->LPF_Y.SpatialThlY;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_Y.SNR_spatialthlyx2 = pNR_Table->LPF_Y.SpatialThl2Y;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_Y.SNR_spatialthlyx4 = pNR_Table->LPF_Y.SpatialThl4Y;

	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_General_ctrl.SNR_spatialenablec = pNR_Table->LPF_C.Spatial_Enable_C;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_C.SNR_lpresultweightc = pNR_Table->LPF_C.LPResultWeightC;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_C.SNR_zoranfiltersizec = pNR_Table->LPF_C.RZ_filter_Size;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_C.SNR_zoranweight2c = pNR_Table->LPF_C.Weight2C;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_C.SNR_zoranweight3c = pNR_Table->LPF_C.Weight3C;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_C.SNR_zoranweight4c = pNR_Table->LPF_C.Weight4C;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_C.SNR_spatialthlc = pNR_Table->LPF_C.SpatialThlC;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_C.SNR_spatialthlcx2 = pNR_Table->LPF_C.SpatialThl2C;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_C.SNR_spatialthlcx4 = pNR_Table->LPF_C.SpatialThl4C;

	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_Y.SNR_weight1y = pNR_Table->BLENDING.Weight1Y;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Spatial_NR_Y.SNR_weight2y = pNR_Table->BLENDING.Weight2Y;

	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_step1 = pNR_Table->CurveMappingStep.Curve_step1;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_step2 = pNR_Table->CurveMappingStep.Curve_step2;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_step3 = pNR_Table->CurveMappingStep.Curve_step3;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_step4 = pNR_Table->CurveMappingStep.Curve_step4;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_step5 = pNR_Table->CurveMappingStep.Curve_step5;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_step6 = pNR_Table->CurveMappingStep.Curve_step6;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_step7 = pNR_Table->CurveMappingStep.Curve_step7;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_step8 = pNR_Table->CurveMappingStep.Curve_step8;

	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w1_0 = pNR_Table->CurveMappingWeight.Weight1_0;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w1_1 = pNR_Table->CurveMappingWeight.Weight1_1;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w1_2 = pNR_Table->CurveMappingWeight.Weight1_2;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w1_3 = pNR_Table->CurveMappingWeight.Weight1_3;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w1_4 = pNR_Table->CurveMappingWeight.Weight1_4;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w1_5 = pNR_Table->CurveMappingWeight.Weight1_5;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w1_6 = pNR_Table->CurveMappingWeight.Weight1_6;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w1_7 = pNR_Table->CurveMappingWeight.Weight1_7;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w1_8 = pNR_Table->CurveMappingWeight.Weight1_8;

	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w2_0 = pNR_Table->CurveMappingWeight.Weight2_0;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w2_1 = pNR_Table->CurveMappingWeight.Weight2_1;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w2_2 = pNR_Table->CurveMappingWeight.Weight2_2;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w2_3 = pNR_Table->CurveMappingWeight.Weight2_3;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w2_4 = pNR_Table->CurveMappingWeight.Weight2_4;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w2_5 = pNR_Table->CurveMappingWeight.Weight2_5;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w2_6 = pNR_Table->CurveMappingWeight.Weight2_6;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w2_7 = pNR_Table->CurveMappingWeight.Weight2_7;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_Curve_Mapping_Mode.SNR_curvemapping_w2_8 = pNR_Table->CurveMappingWeight.Weight2_8;



	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_DeRing.SNR_DeRing_Weight = pNR_Table->BLENDING.De_ring_Weight;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_DeRing.SNR_DeRing_Range = pNR_Table->BLENDING.Ring_Range;
	gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_SNR_TABLE.S_SNR_DeRing.SNR_DeRing_Gain = pNR_Table->BLENDING.Ring_gain;




	/* k3l */

	if(drv_memory_get_ip_DMA420_mode() == 2 )	//400
		gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_RTNR_TABLE.S_RTNR_General_ctrl.RTNR_c_enable = 0;
	else
		gVip_Table->Manual_NR_Table[pqa_table_idx][level].S_RTNR_TABLE.S_RTNR_General_ctrl.RTNR_c_enable = pNR_Table->TNR_C.C_enable;

	fwif_color_set_PQA_motion_threshold_TV006();

#if 0
	if (level < 4) {	/*Manual Mode*/

		VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.Run_Flag[I_DNR] = 0;
		/*WaitFor_DEN_STOP();*/
		fwif_color_RTNR_flow(&(gVip_Table->Manual_NR_Table[pqa_table_idx][level]));
		fwif_color_SNR_flow(&(gVip_Table->Manual_NR_Table[pqa_table_idx][level]));
	} else {	/*Auto Mode*/
		VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.Run_Flag[I_DNR] = 0;
		/*WaitFor_DEN_STOP();*/
		fwif_color_RTNR_flow(&(gVip_Table->Manual_NR_Table[pqa_table_idx][DRV_NR_AUTO]));
		fwif_color_SNR_flow(&(gVip_Table->Manual_NR_Table[pqa_table_idx][DRV_NR_AUTO]));

		drvif_color_PQ_Adaptive_offset_temp(PQA_TABLE, pqa_table_idx, I_DNR, PQA_TABLE_OFFSET_TEMP);
		/*fwif_color_regPQATableOffsetTemp(PQA_TABLE_OFFSET_TEMP);*/
		VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.Run_Flag[I_DNR] = 1;
	}
#else

	VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.Run_Flag[I_DNR] = 0;
	fwif_color_RTNR_flow(&(gVip_Table->Manual_NR_Table[pqa_table_idx][level]));
	fwif_color_SNR_flow(&(gVip_Table->Manual_NR_Table[pqa_table_idx][level]));
	drvif_color_PQ_Adaptive_offset_temp(PQA_TABLE, pqa_table_idx, I_DNR, PQA_TABLE_OFFSET_TEMP);
	VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.Run_Flag[I_DNR] = 1;



#endif
}

void fwif_color_Set_NR_Input_tv006(unsigned char input)
{
	bNr_Input = input;
}


unsigned char fwif_color_get_NR_Input_tv006(void)
{
	return bNr_Input;
}


void fwif_color_Set_MPEGNR_Table_tv006(CHIP_MPEG_NOISE_REDUCTION_T *ptr)
{
	if (ptr == NULL) {
		VIPprintf("fwif_color_Set_MPEGNR_Table_tv006 error\n");
		return;
	}
	pMPEGNR_Table_tv006 = ptr;
	VIPprintf(" == = Set_MPEGNR_Table_tv006 == = \n");

}
CHIP_MPEG_NOISE_REDUCTION_T *fwif_color_Get_MPEGNR_Table_tv006(void)
{
	if (pMPEGNR_Table_tv006 == NULL) {
		VIPprintf("pMPEGNR_Table_tv006 is NULL\n");
		return NULL;
	}
	return (CHIP_MPEG_NOISE_REDUCTION_T *)pMPEGNR_Table_tv006;

}

unsigned char fwif_color_MPEGDNR_tv006()
{
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		VIPprintf("~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return 0;
	}

	return VIP_system_info_structure_table->OSD_Info.OSD_MpegNR_Mode;
}

void fwif_color_Set_MPEGNR_tv006(unsigned char level)
{

	/*int ret;*/
	SLR_VIP_TABLE *gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();

	CHIP_MPEG_NOISE_REDUCTION_T *pMPEGNR_Table = fwif_color_Get_MPEGNR_Table_tv006();
	_system_setting_info *VIP_system_info_structure_table = NULL;
	unsigned int *PQA_TABLE = NULL;
	unsigned int *PQA_TABLE_OFFSET_TEMP = NULL;
	UINT8 source=255,pqa_table_idx=0,pqa_input_idx=0;

	if (gVip_Table == NULL) {
		VIPprintf("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	if (pMPEGNR_Table == NULL) {
		VIPprintf("~get pMPEGNR_Table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}



	/*=== 20140421 CSFC for vip video fw infomation ====*/
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		VIPprintf("~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	/*get pqa table index need check source first. because ap flow or table index will get incorrect table*/
	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);/* get vip source by input src and timing*/
	if (source >= VIP_QUALITY_SOURCE_NUM)
		source = 0;


	if(fwif_color_get_NR_Input_tv006()!= 12) //12 is webcam. it is from hal for webcam special case.
	{
	pqa_table_idx = gVip_Table->VIP_QUALITY_Extend3_Coef[source][VIP_QUALITY_FUNCTION_PQA_Table];
		pqa_input_idx = gVip_Table->VIP_QUALITY_Extend3_Coef[source][VIP_QUALITY_FUNCTION_PQA_Input_Table];
	}
	else
	{
		pqa_table_idx = 9;
		pqa_input_idx = 9;
	}

	scaler_set_PQA_table(pqa_table_idx);
	scaler_set_PQA_Input_table(pqa_input_idx);


	PQA_TABLE = &(gVip_Table->PQA_Table[0][0][0][0]);
	PQA_TABLE_OFFSET_TEMP = &(VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.OFFSET_TEMP[0]);

	if (pMPEGNR_Table->MPEG_LEVEL < 4) {
		DRV_NR_Item *pNR_ITEM = NULL;
		/*Manual Mode*/
		VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.Run_Flag[I_MPEGNR] = 0;
		/*WaitFor_DEN_STOP();*/
		pNR_ITEM = &(gVip_Table->Manual_NR_Table[pqa_table_idx][pMPEGNR_Table->MPEG_LEVEL]);
		/*drvif_color_MPEGNR_flow(&(gVip_Table.Manual_NR_Table[pqa_table][level]));*/


		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_edge_lpf_en = pMPEGNR_Table->MNR_T.Edge_LPF_enable;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquito_edgethd = pMPEGNR_Table->MNR_T.Edge_Theshold;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquito_edgethd_step = pMPEGNR_Table->MNR_T.Edge_Theshold_Step;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_farvar_faredge_refine_en = pMPEGNR_Table->MNR_T.Far_Var_farEdge_refine_Enable;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_far_var_gain = pMPEGNR_Table->MNR_T.Far_Var_Gain;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_far_var_offset = pMPEGNR_Table->MNR_T.Far_Var_offset;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_hdiff_frac_shift = pMPEGNR_Table->MNR_T.Hdiff_Frac_Shift;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_vardiff_refine_gain = pMPEGNR_Table->MNR_T.varDiff_refine_gain;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_vdiff_frac_shift = pMPEGNR_Table->MNR_T.Vdiff_Frac_Shift;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mnr_decay_en = pMPEGNR_Table->MNR_T.Decay_enable;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_hdecay_start = pMPEGNR_Table->MNR_T.Hdecay_Start;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_hdecay_step = pMPEGNR_Table->MNR_T.Hdecay_Step;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_vdecay_start = pMPEGNR_Table->MNR_T.Vdecay_Start;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_vdecay_step = pMPEGNR_Table->MNR_T.Vdecay_Step;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_weight = pMPEGNR_Table->MNR_T.MNR_Weight;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_blending_mode = pMPEGNR_Table->MNR_T.Blending_Mode;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.MNR_hdiff_frac_half_range = pMPEGNR_Table->MNR_T.Range;

		pNR_ITEM->S_SNR_TABLE.S_SNR_General_ctrl.SNR_mosquito_detect_en = pMPEGNR_Table->MNR_UI_T.MosquitoNR_Enable;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_nlevel_positive_offset = pMPEGNR_Table->MNR_UI_T.Positive_nLevel_Offset;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_nlevel_positive_shift = pMPEGNR_Table->MNR_UI_T.Positive_nLevel_Shift;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_nlevel_negative_offset = pMPEGNR_Table->MNR_UI_T.Negative_nLevel_Offset;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_nlevel_negative_shift = pMPEGNR_Table->MNR_UI_T.Negative_nLevel_Shift;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_edge_strength_gain = pMPEGNR_Table->MNR_UI_T.Edge_Strength_Gain;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_keep_edge_threshold = pMPEGNR_Table->MNR_UI_T.Threshold;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_keep_edge_threshold_step = pMPEGNR_Table->MNR_UI_T.Threshold_Step;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_keep_edge_shift = pMPEGNR_Table->MNR_UI_T.Shift;


		//pNR_ITEM->S_MPG_TABLE.S_MPEGNR_H.MPG_ResultWeight_H = pMPEGNR_Table->MPEGNR_UI_T.MpegResultWeight_H;
		//pNR_ITEM->S_MPG_TABLE.S_MPEGNR_H.MPG_DC_mode_filter = pMPEGNR_Table->MPEGNR_UI_T.DC_mode_filter;
		//pNR_ITEM->S_MPG_TABLE.S_MPEGNR_H.MPG_DC_Gain = pMPEGNR_Table->MPEGNR_UI_T.Mpg_DC_Gain;

		drvif_color_DRV_MPG_General_ctrl(&(pNR_ITEM->S_MPG_TABLE.S_MPEGNR_General_ctrl));
		drvif_color_DRV_MPG_H_tv006(&(pNR_ITEM->S_MPG_TABLE.S_MPEGNR_H), 1);
		drvif_color_DRV_MPG_V(&(pNR_ITEM->S_MPG_TABLE.S_MPEGNR_V));
		drvif_color_DRV_SNR_Mosquito_NR(&(pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR)); /*Add from set SNR due to LG requirement*/
		drvif_color_DRV_SNR_Mosquito_NR_En(pNR_ITEM->S_SNR_TABLE.S_SNR_General_ctrl.SNR_mosquito_detect_en);
	} else {
		DRV_NR_Item *pNR_ITEM = NULL;
		/*Auto Mode*/
		VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.Run_Flag[I_MPEGNR] = 0;
		/*WaitFor_DEN_STOP();*/
		pNR_ITEM = &(gVip_Table->Manual_NR_Table[pqa_table_idx][DRV_NR_AUTO]);
		/*drvif_color_MPEGNR_flow(&(gVip_Table.Manual_NR_Table[pqa_table][DRV_NR_AUTO]));*/

		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_edge_lpf_en = pMPEGNR_Table->MNR_T.Edge_LPF_enable;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquito_edgethd = pMPEGNR_Table->MNR_T.Edge_Theshold;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquito_edgethd_step = pMPEGNR_Table->MNR_T.Edge_Theshold_Step;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_farvar_faredge_refine_en = pMPEGNR_Table->MNR_T.Far_Var_farEdge_refine_Enable;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_far_var_gain = pMPEGNR_Table->MNR_T.Far_Var_Gain;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_far_var_offset = pMPEGNR_Table->MNR_T.Far_Var_offset;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_hdiff_frac_shift = pMPEGNR_Table->MNR_T.Hdiff_Frac_Shift;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_vardiff_refine_gain = pMPEGNR_Table->MNR_T.varDiff_refine_gain;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_vdiff_frac_shift = pMPEGNR_Table->MNR_T.Vdiff_Frac_Shift;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mnr_decay_en = pMPEGNR_Table->MNR_T.Decay_enable;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_hdecay_start = pMPEGNR_Table->MNR_T.Hdecay_Start;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_hdecay_step = pMPEGNR_Table->MNR_T.Hdecay_Step;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_vdecay_start = pMPEGNR_Table->MNR_T.Vdecay_Start;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_vdecay_step = pMPEGNR_Table->MNR_T.Vdecay_Step;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_weight = pMPEGNR_Table->MNR_T.MNR_Weight;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_blending_mode = pMPEGNR_Table->MNR_T.Blending_Mode;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.MNR_hdiff_frac_half_range = pMPEGNR_Table->MNR_T.Range;

		pNR_ITEM->S_SNR_TABLE.S_SNR_General_ctrl.SNR_mosquito_detect_en = pMPEGNR_Table->MNR_UI_T.MosquitoNR_Enable;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_nlevel_positive_offset = pMPEGNR_Table->MNR_UI_T.Positive_nLevel_Offset;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_nlevel_positive_shift = pMPEGNR_Table->MNR_UI_T.Positive_nLevel_Shift;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_nlevel_negative_offset = pMPEGNR_Table->MNR_UI_T.Negative_nLevel_Offset;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_nlevel_negative_shift = pMPEGNR_Table->MNR_UI_T.Negative_nLevel_Shift;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_mosquitonr_edge_strength_gain = pMPEGNR_Table->MNR_UI_T.Edge_Strength_Gain;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_keep_edge_threshold = pMPEGNR_Table->MNR_UI_T.Threshold;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_keep_edge_threshold_step = pMPEGNR_Table->MNR_UI_T.Threshold_Step;
		pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR.SNR_keep_edge_shift = pMPEGNR_Table->MNR_UI_T.Shift;


		//pNR_ITEM->S_MPG_TABLE.S_MPEGNR_H.MPG_ResultWeight_H = pMPEGNR_Table->MPEGNR_UI_T.MpegResultWeight_H;
		//pNR_ITEM->S_MPG_TABLE.S_MPEGNR_H.MPG_DC_mode_filter = pMPEGNR_Table->MPEGNR_UI_T.DC_mode_filter;
		//pNR_ITEM->S_MPG_TABLE.S_MPEGNR_H.MPG_DC_Gain = pMPEGNR_Table->MPEGNR_UI_T.Mpg_DC_Gain;

		drvif_color_DRV_MPG_General_ctrl(&(pNR_ITEM->S_MPG_TABLE.S_MPEGNR_General_ctrl));
		drvif_color_DRV_MPG_H_tv006(&(pNR_ITEM->S_MPG_TABLE.S_MPEGNR_H), 1);
		drvif_color_DRV_MPG_V(&(pNR_ITEM->S_MPG_TABLE.S_MPEGNR_V));
		drvif_color_DRV_SNR_Mosquito_NR(&(pNR_ITEM->S_SNR_TABLE.S_SNR_Mosquito_NR)); /*Add from set SNR due to LG requirement*/
		drvif_color_DRV_SNR_Mosquito_NR_En(pNR_ITEM->S_SNR_TABLE.S_SNR_General_ctrl.SNR_mosquito_detect_en);


		drvif_color_PQ_Adaptive_offset_temp(PQA_TABLE, pqa_table_idx, I_MPEGNR, PQA_TABLE_OFFSET_TEMP);
		/*fwif_color_regPQATableOffsetTemp(PQA_TABLE_OFFSET_TEMP);*/
		VIP_system_info_structure_table->PQ_Setting_Info.PQA_Setting_INFO.Run_Flag[I_MPEGNR] = 1;
}

VIP_system_info_structure_table->OSD_Info.OSD_MpegNR_Mode = pMPEGNR_Table->MPEG_LEVEL;
/*====================================*/


Scaler_set_picmode_init_value(PICMODE_INIT_MPEGNR, pMPEGNR_Table->MPEG_LEVEL);



}

void fwif_color_Set_MNR_Enable_Check_tv006(void)
{
	unsigned char MNR_En;
	CHIP_MPEG_NOISE_REDUCTION_T *pMPEGNR_Table = fwif_color_Get_MPEGNR_Table_tv006();

	if (pMPEGNR_Table == NULL)
		return;

	MNR_En = pMPEGNR_Table->MNR_UI_T.MosquitoNR_Enable;

	drvif_color_DRV_SNR_Mosquito_NR_En(MNR_En);
}

void fwif_color_set_ICM_table_driver_init_tv006(void)
{
	int i;
	unsigned short h_pillar[48] = {0x02, 0x04, 0x06, 0x07, 0x08, 0x0a, 0x0c, 0x0d, 0x0e, 0x10, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x19, 0x1a, 0x1b, 0x1c, 0x1e, 0x20, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x31, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e};
	unsigned short s_pillar[8] = {0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b};
	unsigned short i_pillar[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
	int si_global[12];
	RPC_ICM_Global_Ctrl *rpc_icm_global_ctrl = NULL;
	extern unsigned char g_cm_keep_Y;

	memset(si_global, 0, sizeof(si_global));

	drvif_color_icm_Set_global(0, si_global, si_global);
	drvif_color_icm_set_ctrl(0, 0, 0, g_cm_keep_Y);
	drvif_color_icm_set_uv_coring(0, 0);
	drvif_color_icm_set_pillar(h_pillar, s_pillar, i_pillar);

	rpc_icm_global_ctrl = fwif_color_GetICM_Global_Ctrl_Struct();
	if (NULL !=  rpc_icm_global_ctrl) {
		rpc_icm_global_ctrl->dHue = 0;
		for (i = 0; i < SATSEGMAX; i++) {
			rpc_icm_global_ctrl->dSatBySat[i] = 0;
		}
		for (i = 0; i < ITNSEGMAX; i++) {
			rpc_icm_global_ctrl->dItnByItn[i] = 0;
		}
	}

}

static unsigned short chip_hue_idx[62] = {
	0, 64, 128, 192, 256, 320, 384, 512, 640, 704, 768, 832, 896, 1024, 1152, 1216, 1280,
	1344, 1408, 1536, 1664, 1792, 1920, 2048, 2112, 2176, 2304, 2432, 2560, 2624, 2688, 2752,
	2816, 2880, 2944, 3072, 3200, 3328, 3456, 3584, 3712, 3776, 3840, 3968, 4096, 4224, 4352,
	4480, 4544, 4608, 4672, 4736, 4864, 4992, 5120, 5248, 5376, 5504, 5632, 5760, 5888, 6016
};

void fwif_color_set_ICM_table_driver_init_elem_tv006(COLORELEM_TAB_T *pIcm_tab_elem)
{
	int h, s, i, iVal;
	unsigned short sat_idx[12] = {
		0, 128, 256, 384, 512, 1024, 1536, 2048, 2560, 3072, 3584, 4096
	};

	if (NULL == pIcm_tab_elem)
		return;

	memset(pIcm_tab_elem, 0, sizeof(COLORELEM_TAB_T));

	for (i = 0; i < 9; i++) {
		iVal = i << 9;
		for (s = 0; s < 12; s++) {
			for (h = 0; h < 62; h++) {
				pIcm_tab_elem->elem[i][s][h].H = chip_hue_idx[h];
				pIcm_tab_elem->elem[i][s][h].S = sat_idx[s];
				pIcm_tab_elem->elem[i][s][h].I = iVal+ITN_SUBTRACT_CONST;
			}
		}
	}
}

unsigned char get_pillar_by_hue(unsigned short hue_idx)
{
	unsigned char hue_pillar = 0;
	int i;

	for(i = 0; i < 62; i++) {
		if (chip_hue_idx[i] == hue_idx)
			hue_pillar = i;
	}

	return hue_pillar;
}

unsigned short get_hue_by_pillar(unsigned char hue_pillar)
{
	if (hue_pillar > 61)
		return 0;

	return chip_hue_idx[hue_pillar];
}

unsigned char get_pillar_by_sat(unsigned short sat_idx)
{
	short sat_pillar;
	sat_idx = sat_idx>>7;
	if (sat_idx >= 4)
		sat_pillar = (sat_idx >> 2) + 3;
	else
		sat_pillar = sat_idx;

	return sat_pillar;
}

unsigned short get_sat_by_pillar(unsigned char sat_pillar)
{
	short sat_idx;
	if (sat_pillar >= 4)
		sat_idx = (sat_pillar - 3) << 9;
	else
		sat_idx = sat_pillar << 7;

	return sat_idx;
}


unsigned char get_pillar_by_itn(unsigned short itn_idx)
{
	return itn_idx>>9;
}

unsigned short get_itn_by_pillar(unsigned char itn_pillar)
{
	return itn_pillar<<9;
}

unsigned char calc_real_hue_region(UINT16 *hue_idx_in, UINT16 *hue_gain_in, CM_HUE_SECTION *pHue_section)
{
	int i, j;
	UINT8 hue_pillar[8] = {0};
	UINT16 hue_idx[8] = {0};
	UINT8 bound_num = 0;
	UINT8 r_flag = 0;

	if (NULL == hue_idx_in || NULL == hue_gain_in || NULL == pHue_section)
		return 0;

	memset(pHue_section, 0, sizeof(CM_HUE_SECTION));
	memcpy(hue_idx, hue_idx_in, sizeof(hue_idx));

	for (i = 0; i < 8; i++) {
		if (i > 0) {
			/*if (hue_idx_in[i] == hue_idx_in[i-1])
				break;
			else */if (hue_idx_in[i] < hue_idx_in[i-1] && !r_flag)
				r_flag = i;
		}
		bound_num = i;
		hue_pillar[i] = get_pillar_by_hue(hue_idx_in[i]);
	}

	if (r_flag) {
		int cnt = 0;

		for (i = 1; i < bound_num+1; i++) {
			/*VIPprintf("hue_pillar=%d\n", hue_pillar[i]);*/
			if (hue_pillar[i] < hue_pillar[0])
			{
				hue_pillar[i] += 62;
				hue_idx[i] += 6144;
			}
		}

		/*pHue_section->pillar_num = hue_pillar[bound_num]+1+62-hue_pillar[0];*/
		pHue_section->pillar_num = hue_pillar[bound_num]-hue_pillar[0]+1;
		/*VIPprintf("pHue_section->pillar_num = %d, bound_num = %d\n", pHue_section->pillar_num, bound_num);*/
		for (i = 0; i < pHue_section->pillar_num; i++) {
			pHue_section->rgn_pillar[i] = hue_pillar[0]+i;
			pHue_section->rgn_idx[i] = get_hue_by_pillar(pHue_section->rgn_pillar[i]%62);
			if (pHue_section->rgn_idx[i] < pHue_section->rgn_idx[0])
				pHue_section->rgn_idx[i] += 6144;
			/*VIPprintf("rgn_pillar = %d, rgn_idx = %d\n", pHue_section->rgn_pillar[i], pHue_section->rgn_idx[i]);*/
		}

		pHue_section->rgn_gain[cnt++] = hue_gain_in[0];
		for (i = 1; i < bound_num+1; i++) {
			for (j = 1; j < hue_pillar[i]-hue_pillar[i-1]+1; j++) {

				pHue_section->rgn_gain[cnt] = ((hue_idx[i]-pHue_section->rgn_idx[cnt])*hue_gain_in[i-1]+
					(pHue_section->rgn_idx[cnt]-hue_idx[i-1])*hue_gain_in[i])/(hue_idx[i]-hue_idx[i-1]);
				/*VIPprintf("i = %d, j = %d, pHue_section->rgn_gain[%d] = %d\n", i, j, cnt, pHue_section->rgn_gain[cnt]);*/
				cnt++;
			}
		}

		for (i = 0; i < pHue_section->pillar_num; i++) {
			pHue_section->rgn_pillar[i] = pHue_section->rgn_pillar[i]%62;
			pHue_section->rgn_idx[i] = pHue_section->rgn_idx[i]%6144;
		}

	} else {
		int cnt = 0;
		pHue_section->pillar_num = hue_pillar[bound_num]-hue_pillar[0]+1;
		/*VIPprintf("pHue_section->pillar_num = %d, bound_num = %d\n", pHue_section->pillar_num, bound_num);*/
		for (i = 0; i < pHue_section->pillar_num; i++)
		{
			pHue_section->rgn_pillar[i] = hue_pillar[0]+i;
			pHue_section->rgn_idx[i] = get_hue_by_pillar(pHue_section->rgn_pillar[i]);
			/*VIPprintf("rgn_pillar = %d, rgn_idx = %d\n", pHue_section->rgn_pillar[i], pHue_section->rgn_idx[i]);*/
		}

		pHue_section->rgn_gain[cnt++] = hue_gain_in[0];
		for (i = 1; i < bound_num+1; i++) {
			for (j = 1; j < hue_pillar[i]-hue_pillar[i-1]+1; j++) {

				pHue_section->rgn_gain[cnt] = ((hue_idx_in[i]-pHue_section->rgn_idx[cnt])*hue_gain_in[i-1]+
					(pHue_section->rgn_idx[cnt]-hue_idx_in[i-1])*hue_gain_in[i])/(hue_idx_in[i]-hue_idx_in[i-1]);
				/*VIPprintf("i = %d, j = %d, pHue_section->rgn_gain[%d] = %d\n", i, j, cnt, pHue_section->rgn_gain[cnt]);*/
				cnt++;
			}
		}
	}

	return 1;
}

unsigned char calc_real_sat_region(UINT16 *sat_idx_in, UINT16 *sat_gain_in, CM_SAT_SECTION *pSAT_section)
{
	int i, j;
	UINT8 sat_pillar[8] = {0};
	UINT8 bound_num = 0;
	UINT8 r_flag = 0;
	int cnt = 0;

	if (NULL == sat_idx_in || NULL == sat_gain_in || NULL == pSAT_section)
		return 0;

	memset(pSAT_section, 0, sizeof(CM_SAT_SECTION));

	for (i = 0; i < 8; i++) {
		if (i > 0) {
			/*if (sat_idx_in[i] == sat_idx_in[i-1])
				break;
			else */if (sat_idx_in[i] < sat_idx_in[i-1] && !r_flag)
				r_flag = i;
		}
		bound_num = i;
		sat_pillar[i] = get_pillar_by_sat(sat_idx_in[i]);
	}

	pSAT_section->pillar_num = sat_pillar[bound_num]-sat_pillar[0]+1;
	/*VIPprintf("pSAT_section->pillar_num = %d, bound_num = %d\n", pSAT_section->pillar_num, bound_num);*/
	for (i = 0; i < pSAT_section->pillar_num; i++)
	{
		pSAT_section->rgn_pillar[i] = sat_pillar[0]+i;
		pSAT_section->rgn_idx[i] = get_sat_by_pillar(pSAT_section->rgn_pillar[i]);
		/*VIPprintf("rgn_pillar = %d, rgn_idx = %d\n", pSAT_section->rgn_pillar[i], pSAT_section->rgn_idx[i]);*/
	}

	pSAT_section->rgn_gain[cnt++] = sat_gain_in[0];
	for (i = 1; i < bound_num+1; i++) {
		for (j = 1; j < sat_pillar[i]-sat_pillar[i-1]+1; j++) {

			pSAT_section->rgn_gain[cnt] = ((sat_idx_in[i]-pSAT_section->rgn_idx[cnt])*sat_gain_in[i-1]+
				(pSAT_section->rgn_idx[cnt]-sat_idx_in[i-1])*sat_gain_in[i])/(sat_idx_in[i]-sat_idx_in[i-1]);
			/*VIPprintf("i = %d, j = %d, pSAT_section->rgn_gain[%d] = %d\n", i, j, cnt, pSAT_section->rgn_gain[cnt]);*/
			cnt++;
		}
	}

	return 1;
}

unsigned char calc_real_itn_region(UINT16 *itn_idx_in, UINT16 *itn_gain_in, CM_ITN_SECTION *pITN_section)
{
	int i, j;
	UINT8 itn_pillar[8] = {0};
	UINT8 bound_num = 0;
	UINT8 r_flag = 0;
	int cnt = 0;

	if (NULL == itn_idx_in || NULL == itn_gain_in || NULL == pITN_section)
		return 0;

	memset(pITN_section, 0, sizeof(CM_ITN_SECTION));

	for (i = 0; i < 8; i++) {
		if (i > 0) {
			/*if (itn_idx_in[i] == itn_idx_in[i-1])
				break;
			else */if (itn_idx_in[i] < itn_idx_in[i-1] && !r_flag)
				r_flag = i;
		}
		bound_num = i;
		itn_pillar[i] = get_pillar_by_itn(itn_idx_in[i]);
	}

	pITN_section->pillar_num = itn_pillar[bound_num]-itn_pillar[0]+1;
	/*VIPprintf("pITN_section->pillar_num = %d, bound_num = %d\n", pITN_section->pillar_num, bound_num);*/
	for (i = 0; i < pITN_section->pillar_num; i++)
	{
		pITN_section->rgn_pillar[i] = itn_pillar[0]+i;
		pITN_section->rgn_idx[i] = get_itn_by_pillar(pITN_section->rgn_pillar[i]);
		/*VIPprintf("rgn_pillar = %d, rgn_idx = %d\n", pITN_section->rgn_pillar[i], pITN_section->rgn_idx[i]);*/
	}

	pITN_section->rgn_gain[cnt++] = itn_gain_in[0];
	for (i = 1; i < bound_num+1; i++) {
		for (j = 1; j < itn_pillar[i]-itn_pillar[i-1]+1; j++) {

			pITN_section->rgn_gain[cnt] = ((itn_idx_in[i]-pITN_section->rgn_idx[cnt])*itn_gain_in[i-1]+
				(pITN_section->rgn_idx[cnt]-itn_idx_in[i-1])*itn_gain_in[i])/(itn_idx_in[i]-itn_idx_in[i-1]);
			/*VIPprintf("i = %d, j = %d, pITN_section->rgn_gain[%d] = %d\n", i, j, cnt, pITN_section->rgn_gain[cnt]);*/
			cnt++;
		}
	}

	return 1;
}

unsigned char fwif_color_calc_ICM_gain_table_driver_tv006(CHIP_COLOR_REGION_TYPE_T *crRgn_in, CHIP_COLOR_CONTROL_T *crCtrl_in, COLORELEM_TAB_T *icmTab_in, COLORELEM_TAB_T *icmTab_out)
{
	int rgn, rgnctrl, i, h, s, iOffset, hOffset, sOffset, iP, hP, sP;
	int sum_rgn_gain, hue_rgn_gain, sat_rgn_gain, itn_rgn_gain;
	long long tmp64;
	CM_HUE_SECTION hue_section;
	CM_SAT_SECTION sat_section;
	CM_ITN_SECTION itn_section;
	unsigned short h_min, h_max, s_min, s_max, i_min, i_max;
	int h_min_ext, h_max_ext, h_mid;
	UINT16 *pIdx = NULL;
	UINT16 *pGain = NULL;
	static CHIP_COLOR_REGION_TYPE_T crRgn_in_tmp;

	if (NULL == crRgn_in || NULL == crCtrl_in || NULL == icmTab_out)
		return 0;

	memcpy(icmTab_out, icmTab_in, sizeof(COLORELEM_TAB_T));

	//check hue boundary
	memcpy(&crRgn_in_tmp, crRgn_in, sizeof(CHIP_COLOR_REGION_TYPE_T));
	crRgn_in = &crRgn_in_tmp;
	for (rgn = 0; rgn < CHIP_CM_COLOR_REGION_MAX; rgn++) {
		for (h = 0; h < CHIP_CM_TBLPOINT; h++) {
			if (crRgn_in->stColorRegion[rgn].hue_x[h] == 6144)
				crRgn_in->stColorRegion[rgn].hue_x[h] = 0;
		}
	}

	for (rgn = 0; rgn < CHIP_CM_COLOR_REGION_MAX; rgn++) {

		/*Remap CM Control index*/
		rgnctrl = rgn;

		if (!crRgn_in->stColorRegion[rgn].enable)
			continue;

		/*Calc Region*/
		pIdx = crRgn_in->stColorRegion[rgn].hue_x;
		pGain = crRgn_in->stColorRegion[rgn].hue_g;
		calc_real_hue_region(pIdx, pGain, &hue_section);
		pIdx = crRgn_in->stColorRegion[rgn].sat_x;
		pGain = crRgn_in->stColorRegion[rgn].sat_g;
		calc_real_sat_region(pIdx, pGain, &sat_section);
		pIdx = crRgn_in->stColorRegion[rgn].Int_x;
		pGain = crRgn_in->stColorRegion[rgn].Int_g;
		calc_real_itn_region(pIdx, pGain, &itn_section);

		/*Calc ColorGain*/
		hOffset = crCtrl_in->stColor[rgnctrl].stColorGain.stColorGainHue-128;
		sOffset = crCtrl_in->stColor[rgnctrl].stColorGain.stColorGainSat-128;
		iOffset = crCtrl_in->stColor[rgnctrl].stColorGain.stColorGainInt-128;
		hOffset = (hOffset<<8)*6144/360;//total need shift 4
		sOffset = (sOffset<<8)*4096/100;//total need shift 4
		iOffset = (iOffset<<8)*4096/100;//total need shift 4
		for (i = 0; i < itn_section.pillar_num; i++) {
			iP = itn_section.rgn_pillar[i];
			for (s = 0; s < sat_section.pillar_num; s++) {
				sP = sat_section.rgn_pillar[s];
				for (h = 0; h < hue_section.pillar_num; h++) {
					hP = hue_section.rgn_pillar[h];

					hue_rgn_gain = hue_section.rgn_gain[h]-128;
					sat_rgn_gain = sat_section.rgn_gain[s]-128;
					itn_rgn_gain = itn_section.rgn_gain[i]-128;
					sum_rgn_gain = abs(hue_rgn_gain*sat_rgn_gain*itn_rgn_gain);//total need shift 21

					tmp64 = crCtrl_in->stColor[rgnctrl].masterGain;
					tmp64 = tmp64*sum_rgn_gain;//total need shift 8+21 = 29
					/*apply offset*/
					icmTab_out->elem[iP][sP][hP].H += ((hue_rgn_gain<0)?(0-((tmp64*hOffset)>>37)):((tmp64*hOffset)>>37)); //shift 29+8 = 37
					icmTab_out->elem[iP][sP][hP].S += ((sat_rgn_gain<0)?(0-((tmp64*sOffset)>>37)):((tmp64*sOffset)>>37)); //shift 29+8 = 37
					icmTab_out->elem[iP][sP][hP].I += ((itn_rgn_gain<0)?(0-((tmp64*iOffset)>>37)):((tmp64*iOffset)>>37)); //shift 29+8 = 37
				}
			}
		}
	}

	/*do clamp*/
	for (rgn = 0; rgn < CHIP_CM_COLOR_REGION_MAX; rgn++) {

		/*Remap CM Control index*/
		rgnctrl = rgn;

		if (!crRgn_in->stColorRegion[rgn].enable)
			continue;

		/*Calc Region*/
		pIdx = crRgn_in->stColorRegion[rgn].hue_x;
		pGain = crRgn_in->stColorRegion[rgn].hue_g;
		calc_real_hue_region(pIdx, pGain, &hue_section);
		pIdx = crRgn_in->stColorRegion[rgn].sat_x;
		pGain = crRgn_in->stColorRegion[rgn].sat_g;
		calc_real_sat_region(pIdx, pGain, &sat_section);
		pIdx = crRgn_in->stColorRegion[rgn].Int_x;
		pGain = crRgn_in->stColorRegion[rgn].Int_g;
		calc_real_itn_region(pIdx, pGain, &itn_section);

		/*Set min, max*/
		h_min = hue_section.rgn_idx[0];
		h_max = (hue_section.pillar_num > 0)?hue_section.rgn_idx[hue_section.pillar_num-1]:h_min;
		s_min = sat_section.rgn_idx[0];
		s_max = (sat_section.pillar_num > 0)?sat_section.rgn_idx[sat_section.pillar_num-1]:s_min;
		i_min = itn_section.rgn_idx[0]+ITN_SUBTRACT_CONST;
		i_max = ((itn_section.pillar_num > 0)?itn_section.rgn_idx[itn_section.pillar_num-1]:i_min)+ITN_SUBTRACT_CONST;

		for (i = 0; i < itn_section.pillar_num; i++) {
			iP = itn_section.rgn_pillar[i];
			for (s = 0; s < sat_section.pillar_num; s++) {
				sP = sat_section.rgn_pillar[s];
				for (h = 0; h < hue_section.pillar_num; h++) {
					hP = hue_section.rgn_pillar[h];

					/*do clamp*/
					if (icmTab_out->elem[iP][sP][hP].S > s_max)
						icmTab_out->elem[iP][sP][hP].S = s_max;
					else if (icmTab_out->elem[iP][sP][hP].S < s_min)
						icmTab_out->elem[iP][sP][hP].S = s_min;

					if (icmTab_out->elem[iP][sP][hP].I > i_max)
						icmTab_out->elem[iP][sP][hP].I = i_max;
					else if (icmTab_out->elem[iP][sP][hP].I < i_min)
						icmTab_out->elem[iP][sP][hP].I = i_min;

					/*calc hue boundary*/
					if (h_min <= h_max) {
						if (icmTab_out->elem[iP][sP][hP].H > h_max)
							icmTab_out->elem[iP][sP][hP].H = h_max;
						else if (icmTab_out->elem[iP][sP][hP].H < h_min)
							icmTab_out->elem[iP][sP][hP].H = h_min;
					} else {
						h_min_ext = 0-(6144-h_min);
						h_max_ext = 6144+h_max;
						h_mid = (h_min+h_max)>>1;

						if (icmTab_out->elem[iP][sP][hP].H > h_max_ext)
							icmTab_out->elem[iP][sP][hP].H = h_max_ext;
						else if (icmTab_out->elem[iP][sP][hP].H < h_min_ext)
							icmTab_out->elem[iP][sP][hP].H = h_min_ext;
						else if (icmTab_out->elem[iP][sP][hP].H <= h_mid && icmTab_out->elem[iP][sP][hP].H > h_max)
							icmTab_out->elem[iP][sP][hP].H = h_max;
						else if (icmTab_out->elem[iP][sP][hP].H > h_mid && icmTab_out->elem[iP][sP][hP].H < h_min)
							icmTab_out->elem[iP][sP][hP].H = h_min;
					}
				}
			}
		}
	}

	//correct hue value
	for (i = 0; i < ITNSEGMAX; i++) {
		for (s = 0; s < SATSEGMAX; s++) {
			for (h = 0; h < HUESEGMAX; h++) {
				if (icmTab_out->elem[i][s][h].H < 0)
					icmTab_out->elem[i][s][h].H += 6144;
				icmTab_out->elem[i][s][h].H %= 6144;
			}
		}
	}

	return 1;
}





void fwif_color_set_ICM_Sat_Zero_Patch(COLORELEM_TAB_T *pIcm_tab_elem)
{
	int i, h;

	for (i = 0 ; i < ITNSEGMAX; i++)
		for (h = 0; h < HUESEGMAX; h++)
			pIcm_tab_elem->elem[i][0][h].S = 0;
}

void fwif_color_set_ICM_table_driver_tv006(COLORELEM_TAB_T *pIcm_tab_elem, unsigned char waiting)
{
	int h, si,i;

	if (NULL == pIcm_tab_elem)
		return;

	fwif_color_set_ICM_Sat_Zero_Patch(pIcm_tab_elem);
	if(waiting == TRUE && !drvif_scalerdisplay_get_force_bg_status() && Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE) {
		fwif_color_WaitFor_DEN_STOP_UZUDTG();
	}

	for (si = 0; si <12; si++){ //mac5p hue range is 1536 , should shift 2bit
		for (h = 0; h < 64; h++){
			for(i=0;i<12;i++){
				pIcm_tab_elem->elem[i][si][h].H >>=2;
			}
		}
	}

	drvif_color_icm_Write3DTable(pIcm_tab_elem->elem);
	drvif_color_Icm_Enable(1);



	for (si = 0; si <12; si++){ //mac5p hue range is 1536 , should shift 2bit
		for (h = 0; h < 64; h++){
			for(i=0;i<12;i++){
				pIcm_tab_elem->elem[i][si][h].H <<=2;
			}
		}
	}


}

unsigned char fwif_color_set_YUV2RGB_UV_Offset_tv006(unsigned char display, unsigned char enable, unsigned char mode, DRV_VIP_YUV2RGB_UV_Offset *pUVOffset)
{
	DRV_VIP_YUV2RGB_CSMatrix drv_vipCSMatrix_t;
	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	if (NULL == pUVOffset)
		return 0;

	if (mode > 3)
		mode = 3;

	if (display == SLR_MAIN_DISPLAY) {
		drv_vipCSMatrix_t.CTRL_ITEM.UVOffset_En = enable;
		drv_vipCSMatrix_t.CTRL_ITEM.UVOffset_Mode_Ctrl = mode;	/*0: AND 1:OR 2:Independent*/
		memcpy(&drv_vipCSMatrix_t.UV_Offset, pUVOffset, sizeof(DRV_VIP_YUV2RGB_UV_Offset));
		/* record to share mem*/
		VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.CTRL_ITEM.UVOffset_En = enable;
		VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.CTRL_ITEM.UVOffset_Mode_Ctrl = mode;
		memcpy(&(VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.UV_Offset), pUVOffset, sizeof(DRV_VIP_YUV2RGB_UV_Offset));

		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_UVOffset_ctrl, VIP_YUV2RGB_Y_Seg_Max, display, VIP_Table_Select_1);
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_UVOffset_Coef, VIP_YUV2RGB_Y_Seg_Max, display, VIP_Table_Select_1);
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_UVOffset_Index, VIP_YUV2RGB_Y_Seg_Max, display, VIP_Table_Select_1);
	} else {
		VIPprintf("~No Sub~ return\n");
	}

	return 1;
}

unsigned char fwif_color_RTK_PQ_demo_check_tv006(VPQ_SetPicCtrl_T *p_setPicCtrl)
{
	unsigned char buf[1] = {1};

	/*
	printk("\nfwif_color_RTK_PQ_demo_check_tv006:\n");
	printk("p_setPicCtrl->siVal[PIC_CTRL_Contrast] = %d\n", p_setPicCtrl->siVal[PIC_CTRL_Contrast]);
	printk("p_setPicCtrl->siVal[PIC_CTRL_Brightness] = %d\n", p_setPicCtrl->siVal[PIC_CTRL_Brightness]);
	printk("p_setPicCtrl->siVal[PIC_CTRL_Color] = %d\n", p_setPicCtrl->siVal[PIC_CTRL_Color]);
	printk("p_setPicCtrl->siVal[PIC_CTRL_Tint] = %d\n", p_setPicCtrl->siVal[PIC_CTRL_Tint]);
	printk("p_setPicCtrl->Gain_Val[PIC_CTRL_Contrast] = %d\n", p_setPicCtrl->Gain_Val[PIC_CTRL_Contrast]);
	printk("p_setPicCtrl->Gain_Val[PIC_CTRL_Brightness] = %d\n", p_setPicCtrl->Gain_Val[PIC_CTRL_Brightness]);
	printk("p_setPicCtrl->Gain_Val[PIC_CTRL_Color] = %d\n", p_setPicCtrl->Gain_Val[PIC_CTRL_Color]);
	printk("p_setPicCtrl->Gain_Val[PIC_CTRL_Tint] = %d\n", p_setPicCtrl->Gain_Val[PIC_CTRL_Tint]);
	*/

	if (p_setPicCtrl->siVal[PIC_CTRL_Contrast] == 99
		&& p_setPicCtrl->siVal[PIC_CTRL_Brightness] == 49
		&& p_setPicCtrl->siVal[PIC_CTRL_Tint] == 9)
	{
		rtd_printk(KERN_DEBUG, TAG_NAME, "\nfwif_color_RTK_PQ_demo_check_tv006  DEMO~~~~~\n");

		(fwif_color_get_demo_callback(DEMO_CALLBACKID_ON_OFF_SWITCH))((void *)buf);
		return TRUE;
	}
	return FALSE;

}

unsigned char fwif_color_get_Decide_YUV2RGB_TBL_Index_tv006(unsigned char src_idx, unsigned char display, unsigned char Input_Data_Mode)
{
	unsigned char ret_idx;

	switch (Input_Data_Mode) {
		case  YUV2RGB_INPUT_601_Limted:
		case  YUV2RGB_INPUT_601_Full:
			ret_idx = YUV2RGB_TBL_SELECT_601_Limted_235_240_to_255;
			break;
		case  YUV2RGB_INPUT_709_Limted:
		case  YUV2RGB_INPUT_709_Full:
			ret_idx = YUV2RGB_TBL_SELECT_709_Limted_235_240_to_255;
			break;
		case  YUV2RGB_INPUT_2020_NonConstantY:
			ret_idx = YUV2RGB_TBL_SELECT_2020_NonConstantY;
			break;
		case  YUV2RGB_INPUT_2020_ConstantY:
			ret_idx = YUV2RGB_TBL_SELECT_2020_ConstantY;
			break;
		default:
			ret_idx = YUV2RGB_TBL_SELECT_601_Limted_NO_Gain;
			break;
	}
	return ret_idx;
}

int fwif_color_set_Picture_Control_tv006(unsigned char display, VPQ_SetPicCtrl_T *p_setPicCtrl)
{
	int ret = 0;
	_system_setting_info *system_info_struct = NULL;

	system_info_struct = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (system_info_struct == NULL) {
		VIPprintf("~get shareMem | gvipTbl error return~\n");
		return -1;
	}

	/*remove special demo mode 20160129*/
	//if (fwif_color_RTK_PQ_demo_check_tv006(p_setPicCtrl))
	//	return -1;

	/* get osd and gain value into share mem for con bri color tint*/

	//fwif_color_CalCon_Bri_Color_Tint_Gain_tv006(display, p_setPicCtrl, system_info_struct);
	//ret = fwif_color_setCon_Bri_Color_Tint_tv006(p_setPicCtrl->wId, system_info_struct);

	if (display == SLR_MAIN_DISPLAY) {
		fwif_color_CalCon_Bri_Color_Tint_Gain_tv006(SLR_MAIN_DISPLAY, p_setPicCtrl, system_info_struct);
		ret = fwif_color_setCon_Bri_Color_Tint_tv006(SLR_MAIN_DISPLAY, system_info_struct);
		fwif_color_CalCon_Bri_Color_Tint_Gain_tv006(SLR_SUB_DISPLAY, p_setPicCtrl, system_info_struct);
		fwif_color_setCon_Bri_Color_Tint_tv006(SLR_SUB_DISPLAY, system_info_struct);
	} else if (display == SLR_SUB_DISPLAY) {
		fwif_color_CalCon_Bri_Color_Tint_Gain_tv006(SLR_SUB_DISPLAY, p_setPicCtrl, system_info_struct);
		fwif_color_setCon_Bri_Color_Tint_tv006(SLR_SUB_DISPLAY, system_info_struct);
	}

	return ret;
}

int fwif_color_setCon_Bri_Color_Tint_tv006(unsigned char display, _system_setting_info *system_info_struct)
{
	SLR_VIP_TABLE *gVip_Table = NULL;

	DRV_VIP_YUV2RGB_CSMatrix drv_vipCSMatrix_t = {0};
	unsigned char coef_level;
	unsigned char RGB_level;
	unsigned char tbl_select;
	unsigned char i, j, k; /*, Y_Clamp;*/
	/*unsigned short *table_idx[3][3];*/
	unsigned short table_idx[3][3][VIP_YUV2RGB_Y_Seg_Max];
	short satTmp[3][3], hueTmp[3][3], kTmp[3][3], kTmp1[3][3];
	unsigned short satCmps;
	short cmps = 0;
	short contrast, bri, color;
	short deg_tint;
	int aplColorGain;
	unsigned short con_gain_max, color_gain_max;
	/*VPQ_SAT_LUT_T *sat_LUT = NULL;*/ /* DSE function */
	VPQ_SAT_LUT_T sat_LUT, sat_gain, total_sat_gain;
	unsigned char Input_mode, YUV2RGB_TBL_Idx;
	int tbl_offset_R, tbl_offset_G, tbl_offset_B;

	unsigned char bt2020_Constant_En;
	short bt2020_k13, bt2020_k32;

	gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (system_info_struct == NULL || gVip_Table == NULL) {
		VIPprintf("~get shareMem | gvipTbl error return~\n");
		return -1;
	}

	memset(satTmp, 0, sizeof(satTmp));
	memset(hueTmp, 0, sizeof(hueTmp));
	memset(kTmp, 0, sizeof(kTmp));
	memset(kTmp1, 0, sizeof(kTmp1));

	coef_level = system_info_struct->using_YUV2RGB_Matrix_Info.CoefByY_CtrlItem_Level;
	RGB_level = system_info_struct->using_YUV2RGB_Matrix_Info.RGB_Offset_Level;
	tbl_select = system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_TBL_Select;

	if (coef_level >=  VIP_YUV2RGB_LEVEL_SELECT_MAX || RGB_level >=  VIP_YUV2RGB_LEVEL_SELECT_MAX || tbl_select >=  YUV2RGB_TBL_Num) {
		VIPprintf("~level or table select Error return, level = %d, table select = %d, %s->%d, %s~\n", coef_level, tbl_select, __FILE__, __LINE__, __FUNCTION__);
		return -1;
	}

	Input_mode = system_info_struct->using_YUV2RGB_Matrix_Info.Input_Data_Mode;
	YUV2RGB_TBL_Idx = fwif_color_get_Decide_YUV2RGB_TBL_Index_tv006(0, display, Input_mode);

	if (display == SLR_MAIN_DISPLAY) {
		/* contrast, brightness, tint, color gain get from share memory */
		contrast = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Contrast_Gain, 0);
		bri = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Brightness_Gain, 0);
		color = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Saturation_Gain, 0);
		deg_tint = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Hue_Gain, 0);

		if (OSD_Contrast_Compensation) {
			fwif_color_CalContrast_Compensation_tv006(display, contrast, system_info_struct);
			cmps = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Brightness_Cmps, 0);
			satCmps = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Saturation_Cmps, 0);
		} else {
			cmps = 0;
			satCmps = 128;
		}

		/* get DSE saturation Gain LUT */
		/*fwif_color_get_SaturationLUT_tv006(SLR_MAIN_DISPLAY, &sat_LUT);*/
		fwif_color_access_SaturationLUT_tv006(SLR_MAIN_DISPLAY, &sat_LUT, ACCESS_MODE_GET);

		/* for K13_2, K32_2*/
		if (system_info_struct->BT2020_CTRL.Enable_Flag == 1 && system_info_struct->BT2020_CTRL.Mode == BT2020_MODE_Constant)
			bt2020_Constant_En = 1;
		else
			bt2020_Constant_En = 0;

		VIPprintf("~tv006~,cmps=%d,satCmps=%d\n", cmps, satCmps);
		VIPprintf("~tv006_gain, con = %d, bri = %d, color = %d, tint = %d~\n", contrast, bri, color, deg_tint);
		VIPprintf("~sat_LUT[0]=%d, sat_LUT[5]=%d, sat_LUT[12]=%d, sat_LUT[16]=%d~\n", sat_LUT.uSaturationY[0], sat_LUT.uSaturationY[5], sat_LUT.uSaturationY[12], sat_LUT.uSaturationY[16]);
	} else {
		/* contrast, brightness, tint, color gain get from share memory */
		contrast = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Contrast_Gain_Sub, 0);
		bri = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Brightness_Gain_Sub, 0);
		color = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Saturation_Gain_Sub, 0);
		deg_tint = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Hue_Gain_Sub, 0);

		if (OSD_Contrast_Compensation) {
			fwif_color_CalContrast_Compensation_tv006(display, contrast, system_info_struct);
			cmps = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Brightness_Cmps_Sub, 0);
			satCmps = fwif_color_ChangeOneUINT16Endian(system_info_struct->OSD_Info.Saturation_Cmps_Sub, 0);
		} else {
			cmps = 0;
			satCmps = 128;
		}

		/* get DSE saturation Gain LUT */
		/*fwif_color_get_SaturationLUT_tv006(SLR_MAIN_DISPLAY, &sat_LUT);*/ /* No DSE for sub*/
		for (i = 0; i < VIP_YUV2RGB_Y_Seg_Max; i++) {
			sat_LUT.uSaturationY[i] = 128; /*0x80 = gain 1*/
		}

		/* for K13_2, K32_2*/
		if (system_info_struct->BT2020_CTRL.Enable_Flag_Sub == 1 && system_info_struct->BT2020_CTRL.Mode_Sub == BT2020_MODE_Constant)
			bt2020_Constant_En = 1;
		else
			bt2020_Constant_En = 0;

		VIPprintf("~sub,tv006~,cmps=%d,satCmps=%d\n", cmps, satCmps);
		VIPprintf("~sub,tv006_gain, con = %d, bri = %d, color = %d, tint = %d~\n", contrast, bri, color, deg_tint);
		/*VIPprintf("~sub,sat_LUT[0]=%d, sat_LUT[5]=%d, sat_LUT[12]=%d, sat_LUT[16]=%d~\n", sat_LUT.uSaturationY[0], sat_LUT.uSaturationY[5], sat_LUT.uSaturationY[12], sat_LUT.uSaturationY[16]);*/
	}

	/* no hue function while bt2020_Constant_En*/
	if (bt2020_Constant_En == 1)
		deg_tint = 0;
	/*Euler's formula*/
	hueTmp[0][0] = 1024;
	hueTmp[1][1] = CAdjustCosine(deg_tint);
	hueTmp[1][2] = CAdjustSine(deg_tint) * (-1);
	hueTmp[2][1] = CAdjustSine(deg_tint);
	hueTmp[2][2] = CAdjustCosine(deg_tint);

	/*restrict for sat, refernece to spec for k32.*/
	color = (color * satCmps) >> 7;
	for (i = 0; i < VIP_YUV2RGB_Y_Seg_Max; i++) {
		sat_gain.uSaturationY[i] = color;
	}
	fwif_color_access_Sat_Gain_tv006(display, &sat_gain, ACCESS_MODE_WRITE);

	/*color = (color > 128) ?  75 + (color*53 / 128) : color;*/
	satTmp[0][0] = 128;	/*128  = 1*/
	satTmp[1][1] = color;
	satTmp[2][2] = color;

	/*get vip table info for k coeff.*/	/* get table from pq misc, vip table is for coef gain*/
	/*table_idx[0][0] = &(gVip_Table->YUV2RGB_CSMatrix_Table[tbl_select].YUV2RGB_CSMatrix[tbl_select].COEF_By_Y.K11[0]);
	table_idx[0][1] = &(gVip_Table->YUV2RGB_CSMatrix_Table[tbl_select].YUV2RGB_CSMatrix[tbl_select].COEF_By_Y.K12[0]);
	table_idx[0][2] = &(gVip_Table->YUV2RGB_CSMatrix_Table[tbl_select].YUV2RGB_CSMatrix[tbl_select].COEF_By_Y.K13[0]);
	table_idx[1][0] = table_idx[0][0];
	table_idx[1][1] = &(gVip_Table->YUV2RGB_CSMatrix_Table[tbl_select].YUV2RGB_CSMatrix[tbl_select].COEF_By_Y.K22[0]);
	table_idx[1][2] = &(gVip_Table->YUV2RGB_CSMatrix_Table[tbl_select].YUV2RGB_CSMatrix[tbl_select].COEF_By_Y.K23[0]);
	table_idx[2][0] = table_idx[0][0];
	table_idx[2][1] = &(gVip_Table->YUV2RGB_CSMatrix_Table[tbl_select].YUV2RGB_CSMatrix[tbl_select].COEF_By_Y.K32[0]);
	table_idx[2][2] = &(gVip_Table->YUV2RGB_CSMatrix_Table[tbl_select].YUV2RGB_CSMatrix[tbl_select].COEF_By_Y.K33[0]);*/
	for (i = 0; i < VIP_YUV2RGB_Y_Seg_Max; i++) {
		table_idx[0][0][i] = tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_K11];
		table_idx[0][1][i] = tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_K12];
		table_idx[0][2][i] = tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_K13];
		table_idx[1][0][i] = tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_K11];
		table_idx[1][1][i] = tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_K22];
		table_idx[1][2][i] = tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_K23];
		table_idx[2][0][i] = tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_K11];
		table_idx[2][1][i] = tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_K32];
		table_idx[2][2][i] = tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_K33];
	}

	/*APL color gain*/
	if (0 == fwif_color_access_apl_color_gain_tv006(display, &aplColorGain, ACCESS_MODE_READ))
		color = color * aplColorGain / 100;

	/*matrix computation for contrast, sat and hue*/
	for (i = 0; i < VIP_YUV2RGB_Y_Seg_Max; i++) {
		con_gain_max = 0;
		color_gain_max = 0;

		/*DSE function, gain by saturation LUT*/
		satTmp[1][1] = (color * sat_LUT.uSaturationY[i]) >> 7;
		satTmp[2][2] = satTmp[1][1];
		VIPprintf("~DSE gain,%d,%d\n", satTmp[1][1], satTmp[2][2]);

		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				kTmp[j][k] = table_idx[j][k][i];
				/*bigger than 0x3FF  = >neg*/
				if (kTmp[j][k] > VIP_YUV2RGB_K_NEG_BND) {
					kTmp[j][k] = VIP_YUV2RGB_K_NEG_CHANGE(kTmp[j][k]);
					kTmp[j][k] = kTmp[j][k] * (-1);
				}
			}
		}

		/* get max coef for max color gain calculation*/
		for (j = 0; j < 3; j++) {
			for (k = 1; k < 3; k++) {
				if (kTmp[j][k] >= 0) {
					if (kTmp[j][k] > color_gain_max)
						color_gain_max = kTmp[j][k];
				} else {
					if ((kTmp[j][k] * (-1)) > color_gain_max)
						color_gain_max = (kTmp[j][k] * (-1));
				}
			}
		}
		con_gain_max = kTmp[0][0];
		VIPprintf("~max coef,%d,%d\n", con_gain_max, color_gain_max);

		/* max contrast gain and color gain calculation*/
		if (con_gain_max == 0)
			con_gain_max = 1;
		con_gain_max = (VIP_YUV2RGB_K_NEG_BND << 7) / con_gain_max;		/*(0x3FF/con_gain_max) << 7;*/	/* Max Gain : Kxx: S(11, 8) */

		if (color_gain_max == 0)
			color_gain_max = 1;
		color_gain_max = (VIP_YUV2RGB_K_NEG_BND << 7) / color_gain_max;	/*(0x3FF/color_gain_max) << 7;*/	/* Max Gain : Kxx: S(11, 8) */

		/* check gain by max gain*/
		if (contrast > con_gain_max)
			contrast = con_gain_max;
		if (satTmp[1][1] > color_gain_max) {
			satTmp[1][1] = color_gain_max;
			satTmp[2][2] = color_gain_max;
		}
		/* record final sat gain curve for tool, elieli*/
		total_sat_gain.uSaturationY[i] = satTmp[1][1];
		VIPprintf("~f_G,%d,%d,%d\n", contrast, satTmp[1][1], satTmp[2][2]);

		/*3x3 matrix multiply*/
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				kTmp1[j][k] = (kTmp[j][0] * hueTmp[0][k] + kTmp[j][1] * hueTmp[1][k] + kTmp[j][2] * hueTmp[2][k]) >> 10;

		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				kTmp[j][k] = (kTmp1[j][0] * satTmp[0][k] + kTmp1[j][1] * satTmp[1][k] + kTmp1[j][2] * satTmp[2][k]) >> 7;

		kTmp[0][0] = (kTmp[0][0] * contrast) >> 7;

		drv_vipCSMatrix_t.COEF_By_Y.K11[i] = kTmp[0][0];
		drv_vipCSMatrix_t.COEF_By_Y.K12[i] = kTmp[0][1];
		drv_vipCSMatrix_t.COEF_By_Y.K13[i] = kTmp[0][2];
		drv_vipCSMatrix_t.COEF_By_Y.K22[i] = kTmp[1][1];
		drv_vipCSMatrix_t.COEF_By_Y.K23[i] = kTmp[1][2];
		drv_vipCSMatrix_t.COEF_By_Y.K32[i] = kTmp[2][1];
		drv_vipCSMatrix_t.COEF_By_Y.K33[i] = kTmp[2][2];
	}

	/* bt2020_Constant_En,  for bt 2020 k13, k32*/
	if (bt2020_Constant_En == 1) {
		bt2020_k13 =  tYUV2RGB_COEF[Input_mode][tUV2RGB_COEF_K13_2];
		bt2020_k32 =  tYUV2RGB_COEF[Input_mode][tUV2RGB_COEF_K32_2];
		if (bt2020_k13 > VIP_YUV2RGB_K_NEG_BND) {
			bt2020_k13 = VIP_YUV2RGB_K_NEG_CHANGE(bt2020_k13);
			bt2020_k13 = bt2020_k13 * (-1);
		}
		if (bt2020_k32 > VIP_YUV2RGB_K_NEG_BND) {
			bt2020_k32 = VIP_YUV2RGB_K_NEG_CHANGE(bt2020_k32);
			bt2020_k32 = bt2020_k32 * (-1);
		}
		/* no hue function while bt 2020, only saturation*/
		bt2020_k13 = (bt2020_k13 * satTmp[1][1])>>7;
		bt2020_k32 = (bt2020_k32 * satTmp[1][1])>>7;
		/* driver for bt 2020*/
		drv_vipCSMatrix_t.COEF_By_Y.bt2020_K13= bt2020_k13;
		drv_vipCSMatrix_t.COEF_By_Y.bt2020_K32= bt2020_k32;
	}

	/*RGB offset setting for brightness*/
	/*Roffset, Goffset, Boffset: S(15,2)*//*bigger than 0x3FFF  = >neg*/
	tbl_offset_R = (tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_R_Offset] > VIP_YUV2RGB_OFFSET_NEG_BND) ? (VIP_YUV2RGB_OFFSET_NEG_CHANGE(tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_R_Offset])) : (tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_R_Offset]);
	tbl_offset_G = (tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_G_Offset] > VIP_YUV2RGB_OFFSET_NEG_BND) ? (VIP_YUV2RGB_OFFSET_NEG_CHANGE(tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_G_Offset])) : (tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_G_Offset]);
	tbl_offset_B = (tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_B_Offset] > VIP_YUV2RGB_OFFSET_NEG_BND) ? (VIP_YUV2RGB_OFFSET_NEG_CHANGE(tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_B_Offset])) : (tYUV2RGB_COEF[YUV2RGB_TBL_Idx][tUV2RGB_COEF_B_Offset]);
	/*drv_vipCSMatrix_t.RGB_Offset.R_offset = (((bri - 128) << 5) + (cmps << 4) + tbl_offset_R) & 0x7fff;
	drv_vipCSMatrix_t.RGB_Offset.G_offset = (((bri - 128) << 5) + (cmps << 4) + tbl_offset_G) & 0x7fff;
	drv_vipCSMatrix_t.RGB_Offset.B_offset = (((bri - 128) << 5) + (cmps << 4) + tbl_offset_B) & 0x7fff;*/
	/* remapping bri effect to more, elieli*/
	bri = bri - 128;
	bri = (bri * 150) >> 7;
	/* more bri effect for negative*/
	if (bri < 0)
		bri = (bri * 213) >> 7;

	drv_vipCSMatrix_t.RGB_Offset.R_offset = (bri << 5) + (cmps << 4) + tbl_offset_R;
	drv_vipCSMatrix_t.RGB_Offset.G_offset = (bri << 5) + (cmps << 4) + tbl_offset_G;
	drv_vipCSMatrix_t.RGB_Offset.B_offset = (bri << 5) + (cmps << 4) + tbl_offset_B;

	/*Clamp setting*/
	/*drv_vipCSMatrix_t.CTRL_ITEM.Y_Clamp = Y_Clamp;*/
	drv_vipCSMatrix_t.CTRL_ITEM.Y_Clamp = 0;

	/*Y_index Setting*/ /*add from K3L*/
	for (j = 0; j < VIP_YUV2RGB_Y_Seg_Max-1; j++)
		drv_vipCSMatrix_t.COEF_By_Y.Y_index[j] = sat_LUT.uSaturationX[j];

	if (display == SLR_MAIN_DISPLAY) {
		/* record final sat gain curve for tool*/
		fwif_color_access_Total_Sat_Gain_tv006(display, &total_sat_gain, ACCESS_MODE_WRITE);
		/*share memory setting*/
		memcpy(&system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.COEF_By_Y, &drv_vipCSMatrix_t.COEF_By_Y, sizeof(DRV_VIP_YUV2RGB_COEF_By_Y));
		memcpy(&system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.RGB_Offset, &drv_vipCSMatrix_t.RGB_Offset, sizeof(DRV_VIP_YUV2RGB_RGB_Offset));
		fwif_color_ChangeUINT16Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.COEF_By_Y.K11[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
		fwif_color_ChangeUINT16Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.COEF_By_Y.K12[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
		fwif_color_ChangeUINT16Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.COEF_By_Y.K13[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
		fwif_color_ChangeUINT16Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.COEF_By_Y.K22[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
		fwif_color_ChangeUINT16Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.COEF_By_Y.K23[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
		fwif_color_ChangeUINT16Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.COEF_By_Y.K32[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
		fwif_color_ChangeUINT16Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.COEF_By_Y.K33[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
		fwif_color_ChangeUINT32Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.RGB_Offset.R_offset), 1, 0);
		fwif_color_ChangeUINT32Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.RGB_Offset.G_offset), 1, 0);
		fwif_color_ChangeUINT32Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.RGB_Offset.B_offset), 1, 0);
		/* drv setting*/
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_Y_Clamp, VIP_YUV2RGB_Y_Seg_0, SLR_MAIN_DISPLAY, VIP_Table_Select_1);
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_Coef_Y_Only, VIP_YUV2RGB_Y_Seg_Max, SLR_MAIN_DISPLAY, VIP_Table_Select_1);
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_Coef_C_Only, VIP_YUV2RGB_Y_Seg_Max, SLR_MAIN_DISPLAY, VIP_Table_Select_1);
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_Offset_Only, VIP_YUV2RGB_Y_Seg_0, SLR_MAIN_DISPLAY, VIP_Table_Select_1);
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_CoefByY_Index, VIP_YUV2RGB_Y_Seg_Max, SLR_MAIN_DISPLAY, VIP_Table_Select_1);
		/* bt2020_Constant_En,  for bt 2020 k13, k32*/
		if (bt2020_Constant_En == 1) {
			/*drv setting*/
			drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_Coef_BT2020_Only, VIP_YUV2RGB_Y_Seg_0, SLR_MAIN_DISPLAY, VIP_Table_Select_1);
			/*memory setting*/
			fwif_color_ChangeUINT16Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.COEF_By_Y.bt2020_K13), 1, 0);
			fwif_color_ChangeUINT16Endian(&(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.COEF_By_Y.bt2020_K32), 1, 0);
		}
	}
	else {
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_Y_Clamp, VIP_YUV2RGB_Y_Seg_0, SLR_SUB_DISPLAY, VIP_Table_Select_2);
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_Coef_Y_Only, VIP_YUV2RGB_Y_Seg_0, SLR_SUB_DISPLAY, VIP_Table_Select_2);
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_Coef_C_Only, VIP_YUV2RGB_Y_Seg_0, SLR_SUB_DISPLAY, VIP_Table_Select_2);
		drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_Offset_Only, VIP_YUV2RGB_Y_Seg_0, SLR_SUB_DISPLAY, VIP_Table_Select_2);
		if (bt2020_Constant_En == 1)
			drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_Coef_BT2020_Only, VIP_YUV2RGB_Y_Seg_0, SLR_SUB_DISPLAY, VIP_Table_Select_2);
	}
	return 0;
}

#if 0
unsigned char fwif_OsdMapToRegValue_tv006(APP_Video_OsdItemType_t bOsdItem, VPQ_SetPicCtrl_T *p_setPicCtrl)
{
	unsigned int temp = 0;
	unsigned char startPoint, endPoint;
	unsigned char reg_point0 = 0;
	unsigned char reg_point50 = 0;
	unsigned char reg_point100 = 0;
	INT16 value;

	switch (bOsdItem) {
	case APP_VIDEO_OSD_ITEM_BRIGHTNESS:
		value = p_setPicCtrl->siVal[PIC_CTRL_Brightness];
		reg_point0 = p_setPicCtrl->setPicCtrl_Mapping.Index_0[PIC_CTRL_Brightness];
		reg_point50 = p_setPicCtrl->setPicCtrl_Mapping.Index_50[PIC_CTRL_Brightness];
		reg_point100 = p_setPicCtrl->setPicCtrl_Mapping.Index_100[PIC_CTRL_Brightness];
		break;
	case APP_VIDEO_OSD_ITEM_CONTRAST:
		value = p_setPicCtrl->siVal[PIC_CTRL_Contrast];
		reg_point0 = p_setPicCtrl->setPicCtrl_Mapping.Index_0[PIC_CTRL_Contrast];
		reg_point50 = p_setPicCtrl->setPicCtrl_Mapping.Index_50[PIC_CTRL_Contrast];
		reg_point100 = p_setPicCtrl->setPicCtrl_Mapping.Index_100[PIC_CTRL_Contrast];
		break;
	case APP_VIDEO_OSD_ITEM_SATURTUION:
		value = p_setPicCtrl->siVal[PIC_CTRL_Color];
		reg_point0 = p_setPicCtrl->setPicCtrl_Mapping.Index_0[PIC_CTRL_Color];
		reg_point50 = p_setPicCtrl->setPicCtrl_Mapping.Index_50[PIC_CTRL_Color];
		reg_point100 = p_setPicCtrl->setPicCtrl_Mapping.Index_100[PIC_CTRL_Color];
		break;
	case APP_VIDEO_OSD_ITEM_HUE:
		value = p_setPicCtrl->siVal[PIC_CTRL_Tint];
		reg_point0 = p_setPicCtrl->setPicCtrl_Mapping.Index_0[PIC_CTRL_Tint];
		reg_point50 = p_setPicCtrl->setPicCtrl_Mapping.Index_50[PIC_CTRL_Tint];
		reg_point100 = p_setPicCtrl->setPicCtrl_Mapping.Index_100[PIC_CTRL_Tint];
		break;
	/*case APP_VIDEO_OSD_ITEM_SHARPNESS:*/
	default:
		value = p_setPicCtrl->siVal[PIC_CTRL_Contrast];
		reg_point0 = p_setPicCtrl->setPicCtrl_Mapping.Index_0[PIC_CTRL_Contrast];
		reg_point50 = p_setPicCtrl->setPicCtrl_Mapping.Index_50[PIC_CTRL_Contrast];
		reg_point100 = p_setPicCtrl->setPicCtrl_Mapping.Index_100[PIC_CTRL_Contrast];
		break;
	}

	if (value < 50) {
		startPoint = reg_point0;
		endPoint = reg_point50;
	} else {
		startPoint = reg_point50;
		endPoint = reg_point100;
		value -=  50;
	}

	if (endPoint >= startPoint) {
		temp = (unsigned char)(startPoint + (endPoint - startPoint)*value/50);
	} else if (endPoint < startPoint) {
		temp = (unsigned char)(startPoint - (startPoint-endPoint)*value/50);
	}

	if (temp > 255)
		temp = 255;

	VIPprintf("mapping = %d, %d, %d, %d, %d, %d \n", bOsdItem, value, temp, reg_point0, reg_point50, reg_point100);

	return (unsigned char)temp;

}
#endif

void fwif_color_CalContrast_Compensation_tv006(unsigned char display, unsigned char Contrast_Gain, _system_setting_info *system_info_struct)
{
	short sat_cmps_tmp, bri_cmps_tmp;
	unsigned short sat_cmps_gain = 128, bri_cmps_gain = 128;

	if (system_info_struct == NULL) {
		VIPprintf("~table NULL TBL=%x,[%s:%d], Return\n~", (unsigned int)system_info_struct, __FILE__, __LINE__);
		return;
	}

	/* center is always at 128*/
	/*o-----------Saturation Compensation-------------o*/
 	/*matrix is 16~235/16~240 to 16~235, so sat_cmps_gain = 128.*/ /*y:16-236, C:16-240, (235-16)/(240-16) ~= 0.9777 ~= (125>>7)*/ /*change "sat_cmps_gain" to adjust compensation effect*/
	sat_cmps_tmp = (Contrast_Gain * sat_cmps_gain) >> 7;

	/*o-----------Brightness Compensation-------------o*/
	if ((fwif_color_ChangeOneUINT16Endian(system_info_struct->RGB2YUV_COEF_CSMatrix.Y_gain, 0) != 0x0100) ||
		(system_info_struct->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix.CTRL_ITEM.Y_Clamp == 1) ||
		(system_info_struct->HDMI_data_range == MODE_RAG_FULL) || (system_info_struct->HDMI_video_format == COLOR_RGB) ||
		(system_info_struct->Input_src_Type == _SRC_VGA))
		bri_cmps_tmp = 0;
	else {
		bri_cmps_tmp = 64 - ((64*Contrast_Gain)>>7); /* calculted in 10 bit*/
		bri_cmps_tmp = (bri_cmps_tmp*bri_cmps_gain)>>7; /*adjust compensation by bri_cmps_gain.*/
	}

	if (display == SLR_MAIN_DISPLAY) {
		system_info_struct->OSD_Info.Saturation_Cmps = fwif_color_ChangeOneUINT16Endian(sat_cmps_tmp, 0);
		system_info_struct->OSD_Info.Brightness_Cmps = fwif_color_ChangeOneUINT16Endian(bri_cmps_tmp, 0);
	} else {
		system_info_struct->OSD_Info.Saturation_Cmps_Sub = fwif_color_ChangeOneUINT16Endian(sat_cmps_tmp, 0);
		system_info_struct->OSD_Info.Brightness_Cmps_Sub = fwif_color_ChangeOneUINT16Endian(bri_cmps_tmp, 0);
	}

	VIPprintf("~ch=%d,Contrast_Gain=%d, Saturation_Cmps=%d,sat_cmps_tmp=%d, Brightness_Cmps=%d, bri_cmps_tmp=%d,\n~",
		display, Contrast_Gain, system_info_struct->OSD_Info.Saturation_Cmps, sat_cmps_tmp,
		system_info_struct->OSD_Info.Brightness_Cmps, bri_cmps_tmp);
}


int fwif_color_CalCon_Bri_Color_Tint_Gain_tv006(unsigned char display, VPQ_SetPicCtrl_T *p_setPicCtrl, _system_setting_info *system_info_struct)
{
	short contrast, bri, color;
	short deg_tint, tint;

	if (system_info_struct == NULL) {
		VIPprintf("~get shareMem | gvipTbl error return~\n");
		return -1;
	}

	if (display == SLR_MAIN_DISPLAY) {
		/* Record OSD value for contrast, brightness, hue, color*/
		system_info_struct->OSD_Info.OSD_Contrast = p_setPicCtrl->siVal[PIC_CTRL_Contrast];
		system_info_struct->OSD_Info.OSD_Brightness = p_setPicCtrl->siVal[PIC_CTRL_Brightness];
		system_info_struct->OSD_Info.OSD_Saturation = p_setPicCtrl->siVal[PIC_CTRL_Color];
		system_info_struct->OSD_Info.OSD_Hue = p_setPicCtrl->siVal[PIC_CTRL_Tint];

		/*cal mapping gain.*/
		contrast = p_setPicCtrl->Gain_Val[PIC_CTRL_Contrast];
		bri = p_setPicCtrl->Gain_Val[PIC_CTRL_Brightness];
		color = p_setPicCtrl->Gain_Val[PIC_CTRL_Color];
		tint = p_setPicCtrl->Gain_Val[PIC_CTRL_Tint];
		tint = tint - 128;
		if (tint >=  0)
			deg_tint = tint;
		else
			deg_tint = 360 - (tint * (-1));
		VIPprintf("~gain, con = %d, bri = %d, color = %d, tint = %d~\n", contrast, bri, color, deg_tint);

		/* Record gain value for contrast, brightness, hue, color*/
		system_info_struct->OSD_Info.Contrast_Gain = fwif_color_ChangeOneUINT16Endian(contrast, 0);
		system_info_struct->OSD_Info.Brightness_Gain = fwif_color_ChangeOneUINT16Endian(bri, 0);
		system_info_struct->OSD_Info.Saturation_Gain = fwif_color_ChangeOneUINT16Endian(color, 0);
		system_info_struct->OSD_Info.Hue_Gain = fwif_color_ChangeOneUINT16Endian(deg_tint, 0);

	} else {
		/* Record OSD value for contrast, brightness, hue, color*/
		system_info_struct->OSD_Info.OSD_Contrast_Sub= p_setPicCtrl->siVal[PIC_CTRL_Contrast];
		system_info_struct->OSD_Info.OSD_Brightness_Sub = p_setPicCtrl->siVal[PIC_CTRL_Brightness];
		system_info_struct->OSD_Info.OSD_Saturation_Sub = p_setPicCtrl->siVal[PIC_CTRL_Color];
		system_info_struct->OSD_Info.OSD_Hue_Sub = p_setPicCtrl->siVal[PIC_CTRL_Tint];

		/*cal mapping gain.*/
		contrast = p_setPicCtrl->Gain_Val[PIC_CTRL_Contrast];
		bri = p_setPicCtrl->Gain_Val[PIC_CTRL_Brightness];
		color = p_setPicCtrl->Gain_Val[PIC_CTRL_Color];
		tint = p_setPicCtrl->Gain_Val[PIC_CTRL_Tint];
		tint = tint - 128;
		if (tint >=  0)
			deg_tint = tint;
		else
			deg_tint = 360 - (tint * (-1));
		VIPprintf("~sub_gain, con = %d, bri = %d, color = %d, tint = %d~\n", contrast, bri, color, deg_tint);

		/* Record gain value for contrast, brightness, hue, color*/
		system_info_struct->OSD_Info.Contrast_Gain_Sub = fwif_color_ChangeOneUINT16Endian(contrast, 0);
		system_info_struct->OSD_Info.Brightness_Gain_Sub = fwif_color_ChangeOneUINT16Endian(bri, 0);
		system_info_struct->OSD_Info.Saturation_Gain_Sub = fwif_color_ChangeOneUINT16Endian(color, 0);
		system_info_struct->OSD_Info.Hue_Gain_Sub = fwif_color_ChangeOneUINT16Endian(deg_tint, 0);
	}
	return 0;
}

void fwif_color_set_YUV2RGB_tv006(unsigned char src_idx, unsigned char display, unsigned char which_table, unsigned char drvSkip_Flag_coefByY, unsigned char drvSkip_Flag_uvOffset)
{
	/*base default setting*/
	DRV_VIP_YUV2RGB_CSMatrix drv_vipCSMatrix_t;
	/*unsigned char i;*/
	SLR_VIP_TABLE *gVip_Table = NULL;
	UINT8 i;
	_system_setting_info *VIP_system_info_structure_table = NULL;
	unsigned char YUV2RGB_TBL_Idx;
	unsigned char Input_mode;

	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL)
		return;

	Input_mode = VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode;
	gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (gVip_Table == NULL) {
		VIPprintf("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	/*Coef and offset is set by OSD con, bri, hue,sat*/
	VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.RGB_Offset_Level = VIP_YUV2RGB_LEVEL_OFF;
	VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.UV_Offset_Level = VIP_YUV2RGB_LEVEL_OFF;
	VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.CoefByY_CtrlItem_Level = VIP_YUV2RGB_LEVEL_OFF;
	VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.YUV2RGB_TBL_Select = which_table;

	memcpy(&drv_vipCSMatrix_t, &(gVip_Table->YUV2RGB_CSMatrix_Table[which_table].YUV2RGB_CSMatrix[VIP_YUV2RGB_LEVEL_OFF]), sizeof(DRV_VIP_YUV2RGB_CSMatrix));

	YUV2RGB_TBL_Idx = fwif_color_get_Decide_YUV2RGB_TBL_Index_tv006(src_idx, display, Input_mode);

	drv_vipCSMatrix_t.CTRL_ITEM.CoefByY_En = 2; /*force Coef by Sat*/
	/* force main use tbl 1, sub use tbl 2 for TV006*/
	drv_vipCSMatrix_t.CTRL_ITEM.Table_Select_Main = 0;
	drv_vipCSMatrix_t.CTRL_ITEM.Table_Select_Sub = 1;

	drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_YUV2RGB_Base_Ctrl, VIP_YUV2RGB_Y_Seg_0, SLR_MAIN_DISPLAY, VIP_Table_Select_1);
	drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_CoefByY_ctrl, VIP_YUV2RGB_Y_Seg_0, SLR_MAIN_DISPLAY, VIP_Table_Select_1);

	/*TBL2 (Sub channel)*/
	drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_YUV2RGB_Base_Ctrl, VIP_YUV2RGB_Y_Seg_0, SLR_SUB_DISPLAY, VIP_Table_Select_2);

}

char fwif_color_set_DSE_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT)
{
	int ret;
	_system_setting_info *system_info_struct = NULL;

	system_info_struct = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (system_info_struct == NULL) {
		VIPprintf("~get shareMem | gvipTbl error return~\n");
		return -1;
	}

	if (display != SLR_MAIN_DISPLAY) {
		VIPprintf("~only main channel for DSE return~\n");
		return -1;
	}
	/* set sat gain into share mem*/
	/*ret = fwif_color_set_SaturationLUT_tv006(display, satLUT);*/
	ret = fwif_color_access_SaturationLUT_tv006(display, satLUT, ACCESS_MODE_SET);

	if (ret < 0)
		return ret;

	ret = fwif_color_setCon_Bri_Color_Tint_tv006(display, system_info_struct); /* only main channel*/

	return ret;
}

int fwif_color_update_YUV2RGB_CSC_tv006(unsigned char display)
{
	_system_setting_info *system_info_struct = NULL;
	system_info_struct = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	if (NULL == system_info_struct)
		return -1;

	return fwif_color_setCon_Bri_Color_Tint_tv006(display, system_info_struct);
}

#if 0 /* no more use because may confuse when code sync YUV2RGB matrix*/
char fwif_color_set_SaturationLUT_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT)
{
	unsigned char coef_level, tbl_select, i;
	DRV_VIP_YUV2RGB_COEF_By_Y *coef_TBL;
	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	SLR_VIP_TABLE *gVip_Table_shareMem = NULL;
	/*gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();*/
	gVip_Table_shareMem = fwif_color_GetShare_Memory_VIP_TABLE_Struct();

	if (display != SLR_MAIN_DISPLAY) {
		VIPprintf("~DSE No Sub~ return\n");
		return -1;
	}

	if (VIP_system_info_structure_table == NULL || gVip_Table_shareMem == NULL || satLUT == NULL) {
		VIPprintf("~get TBL NULL return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return -2;
	}

	coef_level = VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.CoefByY_CtrlItem_Level;
	tbl_select = VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.YUV2RGB_TBL_Select;

	coef_TBL = &(gVip_Table_shareMem->YUV2RGB_CSMatrix_Table[tbl_select].YUV2RGB_CSMatrix[coef_level].COEF_By_Y);

	for (i = 0; i < VIP_YUV2RGB_Y_Seg_Max; i++) {
		coef_TBL->K12[i] = fwif_color_ChangeOneUINT16Endian(satLUT->uSaturationY[i], 0);
		coef_TBL->K13[i] = fwif_color_ChangeOneUINT16Endian(satLUT->uSaturationY[i], 0);
		coef_TBL->K22[i] = fwif_color_ChangeOneUINT16Endian(satLUT->uSaturationY[i], 0);
		coef_TBL->K23[i] = fwif_color_ChangeOneUINT16Endian(satLUT->uSaturationY[i], 0);
		coef_TBL->K32[i] = fwif_color_ChangeOneUINT16Endian(satLUT->uSaturationY[i], 0);
		coef_TBL->K33[i] = fwif_color_ChangeOneUINT16Endian(satLUT->uSaturationY[i], 0);
	}
	return 0;
}

char fwif_color_get_SaturationLUT_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT)
{
	unsigned char coef_level, tbl_select, i;
	DRV_VIP_YUV2RGB_COEF_By_Y *coef_TBL;
	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	SLR_VIP_TABLE *gVip_Table_shareMem = NULL;
	/*gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();*/
	gVip_Table_shareMem = fwif_color_GetShare_Memory_VIP_TABLE_Struct();

	if (display != SLR_MAIN_DISPLAY) {
		VIPprintf("~DSE No Sub~ return\n");
		return -1;
	}

	if (VIP_system_info_structure_table == NULL || gVip_Table_shareMem == NULL || satLUT == NULL) {
		VIPprintf("~get TBL NULL return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return -2;
	}
	coef_level = VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.CoefByY_CtrlItem_Level;
	tbl_select = VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.YUV2RGB_TBL_Select;

	coef_TBL = &(gVip_Table_shareMem->YUV2RGB_CSMatrix_Table[tbl_select].YUV2RGB_CSMatrix[coef_level].COEF_By_Y);

	for (i = 0; i < VIP_YUV2RGB_Y_Seg_Max; i++) {
		satLUT->uSaturationY[i] = fwif_color_ChangeOneUINT16Endian(coef_TBL->K12[i], 0); /* all chroma coef(kxx) should be same for DSE, using k12*/
	}

	VIPprintf("~DSE_Get,%d, =%d~\n", coef_level, tbl_select);

	return 0;

}
#endif /* no more use because may confuse when code sync YUV2RGB matrix*/
char fwif_color_access_SaturationLUT_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT, ACCESS_MODE mode)
{
	static VPQ_SAT_LUT_T cur_sat_lut = {{0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80},
										{0xf, 0x1f, 0x2f, 0x3f, 0x4f, 0x5f, 0x6f, 0x7f, 0x8f, 0x9f, 0xaf, 0xbf, 0xcf, 0xdf, 0xef, 0xff}};

	if (display != SLR_MAIN_DISPLAY) {
		VIPprintf("~DSE No Sub~ return\n");
		return -1;
	}

	if (mode == ACCESS_MODE_SET) {
		memcpy(&cur_sat_lut, satLUT, sizeof(VPQ_SAT_LUT_T));
	} else if (mode == ACCESS_MODE_GET) {
		memcpy(satLUT, &cur_sat_lut, sizeof(VPQ_SAT_LUT_T));
	}

	return 0;
}


char fwif_color_access_Sat_Gain_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT, ACCESS_MODE mode)
{
	static VPQ_SAT_LUT_T sat_gain = {{0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80},
										{0xf, 0x1f, 0x2f, 0x3f, 0x4f, 0x5f, 0x6f, 0x7f, 0x8f, 0x9f, 0xaf, 0xbf, 0xcf, 0xdf, 0xef, 0xff}};

	if (display != SLR_MAIN_DISPLAY) {
		VIPprintf("~No Sub~ return\n");
		return -1;
	}

	if (mode == ACCESS_MODE_SET) {
		memcpy(&sat_gain, satLUT, sizeof(VPQ_SAT_LUT_T));
	} else if (mode == ACCESS_MODE_GET) {
		memcpy(satLUT, &sat_gain, sizeof(VPQ_SAT_LUT_T));
	}

	return 0;
}


char fwif_color_access_Total_Sat_Gain_tv006(unsigned char display, VPQ_SAT_LUT_T *satLUT, ACCESS_MODE mode)
{
	static VPQ_SAT_LUT_T total_sat_gain = {{0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80},
											{0xf, 0x1f, 0x2f, 0x3f, 0x4f, 0x5f, 0x6f, 0x7f, 0x8f, 0x9f, 0xaf, 0xbf, 0xcf, 0xdf, 0xef, 0xff}};

	if (display != SLR_MAIN_DISPLAY) {
		VIPprintf("~No Sub~ return\n");
		return -1;
	}

	if (mode == ACCESS_MODE_SET) {
		memcpy(&total_sat_gain, satLUT, sizeof(VPQ_SAT_LUT_T));
	} else if (mode == ACCESS_MODE_GET) {
		memcpy(satLUT, &total_sat_gain, sizeof(VPQ_SAT_LUT_T));
	}

	return 0;
}

char fwif_color_access_apl_color_gain_tv006(unsigned char display, int* pAplColorGain, ACCESS_MODE mode)
{
	static int stAPLColorGain = 100;

	if (display != SLR_MAIN_DISPLAY || pAplColorGain == NULL) {
		return -1;
	}

	if (mode == ACCESS_MODE_SET) {
		stAPLColorGain = *pAplColorGain;
	} else if (mode == ACCESS_MODE_GET) {
		*pAplColorGain = stAPLColorGain;
	}

	return 0;
}

void fwif_color_set_sharpness_table_TV006(CHIP_SHARPNESS_UI_T *ptCHIP_SHARPNESS_UI_T, CHIP_EDGE_ENHANCE_UI_T *ptCHIP_EDGE_ENHANCE_UI_T, CHIP_SR_UI_T *ptCHIP_SR_UI_T)
{
	unsigned short value, vip_src = 0;

	_RPC_system_setting_info *VIP_RPC_system_info_structure_table=(_RPC_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	_system_setting_info *VIP_system_info_structure_table=(_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	SLR_VIP_TABLE *gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (gVip_Table == NULL) {
		VIPprintf("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	if (NULL == ptCHIP_SHARPNESS_UI_T || NULL == ptCHIP_EDGE_ENHANCE_UI_T || NULL == ptCHIP_SR_UI_T)
		return;

	if (VIP_RPC_system_info_structure_table != NULL)
		vip_src = VIP_RPC_system_info_structure_table->VIP_source;

	{
	static DRV_Sharpness_Table sharp;
	DRV_Sharpness_LV2 sharpLV2;
	short EMFGainMap[7] = {-8, -4, -2, -1, 4, 8, 16};//mutiple 4

	/* Get from LG DB Part */
	/* Remapping CHIP_SEGMENTATION_T */
	sharp.TwoD_Peak_AdaptCtrl.Edge_Mode = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.edge_mode;
	sharp.TwoD_Peak_AdaptCtrl.Sobel_Mode = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.sobel_mode;
	sharp.TwoD_Peak_AdaptCtrl.Edgextrange = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.edgextrange;
	sharp.TwoD_Peak_AdaptCtrl.Sobel_Upbnd = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.sobel_upbnd;
	sharp.TwoD_Peak_AdaptCtrl.Sobel_Stepbit = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.sobel_stepbit;
	sharp.TwoD_Peak_AdaptCtrl.Zdiff_Upbnd = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.zdiff_upbnd;
	sharp.TwoD_Peak_AdaptCtrl.Zdiff_Stepbit = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.zdiff_stepbit;
	sharp.TwoD_Peak_AdaptCtrl.Zigsftbit_Reg = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.zigsftbit_reg;
	sharp.TwoD_Peak_AdaptCtrl.Tex_En = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.texture_enable;
	sharp.TwoD_Peak_AdaptCtrl.Tex_Upbnd = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.tex_upbnd;
	sharp.TwoD_Peak_AdaptCtrl.Tex_Stepbit = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.tex_stepbit;
	sharp.TwoD_Peak_AdaptCtrl.Actsftbit_Reg = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.actsftbit_reg;
	sharp.TwoD_Peak_AdaptCtrl.Lpf_Mode = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.lpf_mode;
	sharp.TwoD_Peak_AdaptCtrl.Lpf_Filter = ptCHIP_SHARPNESS_UI_T->stSharpness.stSegmentation.lpf_filter;

	/*Remapping CHIP_EDGE_CORING_MODE_T*/
	sharp.MK3_Table.EdgeCoring_En = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.edgeCoringEn;
	sharp.MK3_Table.EdgeCoring_Gain_En = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.edgeGainEn;
	sharp.MK3_Table.EdgeCoring_DeltaEdge_Ulevel = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.deltaEdgeUlevel;
	sharp.MK3_Table.EdgeCoring_Clip = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.edgeCoringClip;
	sharp.MK3_Table.EdgeCoring_Gain_Bound = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.edgeGainBound;
	sharp.MK3_Table.EdgeCoring_Ser_Range = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.edgeSerRange;
	sharp.MK3_Table.EdgeCoring_Bigedge_Ratio = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.bigEdgeRatio;
	sharp.MK3_Table.EdgeCoring_Smalledge_Ratio = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.smallEdgeRatio;
	sharp.MK3_Table.EdgeCoring_Deltaedge_Ratio = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.deltaEdgeRatio;
	sharp.MK3_Table.EdgeCoring_Smalledge_Ulevel = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.smallEdgeUlevel;
	sharp.MK3_Table.Edge_Delta_Ext_Range = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCoringMode.Edge_delta_ext_R;

	/*Remapping CHIP_Y_REMAPPING_T*/
	sharp.MK3_Table.LinearY_LB = ptCHIP_SHARPNESS_UI_T->stSharpness.stYRemapping.linearY_LB;
	sharp.MK3_Table.LinearY_UB = ptCHIP_SHARPNESS_UI_T->stSharpness.stYRemapping.linearY_UB;
	sharp.MK3_Table.LinearY_LM = ptCHIP_SHARPNESS_UI_T->stSharpness.stYRemapping.linearY_Lmode;
	sharp.MK3_Table.LinearY_UM = ptCHIP_SHARPNESS_UI_T->stSharpness.stYRemapping.linearY_Umode;


	/* Remapping CHIP_EDGE_HPF_T*/
	sharp.MK3_Table.Edge_Filter_Sel = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.edge_select_filter;
	sharp.MK3_Table.Edge_C00 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c0_0;
	sharp.MK3_Table.Edge_C10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c1_0;
	sharp.MK3_Table.Edge_C20 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c2_0;
	sharp.MK3_Table.Edge_C30 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c3_0;
	sharp.MK3_Table.Edge_C40 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c4_0;
	sharp.MK3_Table.Edge_C50 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c5_0;
	sharp.MK3_Table.Edge_C60 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c6_0;
	sharp.MK3_Table.Edge_C70 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c7_0;
	sharp.MK3_Table.Edge_C80 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c8_0;
	sharp.MK3_Table.Edge_C90 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c9_0;
	sharp.MK3_Table.Edge_C100 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c10_0;
	sharp.MK3_Table.Edge_C03 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c0_3;
	sharp.MK3_Table.Edge_C04 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c0_4;
	sharp.MK3_Table.Edge_C01 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c0_1;
	sharp.MK3_Table.Edge_C11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c1_1;
	sharp.MK3_Table.Edge_C21 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c2_1;
	sharp.MK3_Table.Edge_C31 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c3_1;
	sharp.MK3_Table.Edge_C41 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c4_1;
	sharp.MK3_Table.Edge_C51 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c5_1;
	sharp.MK3_Table.Edge_C02 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c0_2;
	sharp.MK3_Table.Edge_C12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c1_2;
	sharp.MK3_Table.Edge_C22 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c2_2;
	sharp.MK3_Table.Edge_C32 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c3_2;
	sharp.MK3_Table.Edge_C42 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c4_2;
	sharp.MK3_Table.Edge_C52 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c5_2;

	/* Remapping CHIP_EDGE_CURVEMAPPING_STEP_T and CHIP_EDGE_CURVEMAPPING_UI_T*/
	sharp.Edge_Pos_Curve.G0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g0;
	sharp.Edge_Pos_Curve.G1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g1;
	sharp.Edge_Pos_Curve.G2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g2;
	sharp.Edge_Pos_Curve.G3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g3;
	sharp.Edge_Pos_Curve.G4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g4;
	sharp.Edge_Pos_Curve.G5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g5;
	sharp.Edge_Pos_Curve.G6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g6;
	sharp.Edge_Pos_Curve.G7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g7;
	sharp.Edge_Pos_Curve.G8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g8;
	sharp.Edge_Pos_Curve.G9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g9;
	sharp.Edge_Pos_Curve.G10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g10;
	sharp.Edge_Pos_Curve.G11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g11;
	sharp.Edge_Pos_Curve.G12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g12;
	sharp.Edge_Pos_Curve.G13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g13;
	sharp.Edge_Pos_Curve.G14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.pos_g14;

	sharp.Edge_Pos_Curve.S1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s1;
	sharp.Edge_Pos_Curve.S2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s2;
	sharp.Edge_Pos_Curve.S3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s3;
	sharp.Edge_Pos_Curve.S4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s4;
	sharp.Edge_Pos_Curve.S5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s5;
	sharp.Edge_Pos_Curve.S6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s6;
	sharp.Edge_Pos_Curve.S7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s7;
	sharp.Edge_Pos_Curve.S8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s8;
	sharp.Edge_Pos_Curve.S9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s9;
	sharp.Edge_Pos_Curve.S10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s10;
	sharp.Edge_Pos_Curve.S11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s11;
	sharp.Edge_Pos_Curve.S12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s12;
	sharp.Edge_Pos_Curve.S13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s13;
	sharp.Edge_Pos_Curve.S14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.pos_s14;

	sharp.Edge_Neg_Curve.G0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g0;
	sharp.Edge_Neg_Curve.G1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g1;
	sharp.Edge_Neg_Curve.G2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g2;
	sharp.Edge_Neg_Curve.G3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g3;
	sharp.Edge_Neg_Curve.G4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g4;
	sharp.Edge_Neg_Curve.G5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g5;
	sharp.Edge_Neg_Curve.G6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g6;
	sharp.Edge_Neg_Curve.G7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g7;
	sharp.Edge_Neg_Curve.G8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g8;
	sharp.Edge_Neg_Curve.G9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g9;
	sharp.Edge_Neg_Curve.G10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g10;
	sharp.Edge_Neg_Curve.G11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g11;
	sharp.Edge_Neg_Curve.G12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g12;
	sharp.Edge_Neg_Curve.G13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g13;
	sharp.Edge_Neg_Curve.G14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.neg_g14;

	sharp.Edge_Neg_Curve.S1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s1;
	sharp.Edge_Neg_Curve.S2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s2;
	sharp.Edge_Neg_Curve.S3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s3;
	sharp.Edge_Neg_Curve.S4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s4;
	sharp.Edge_Neg_Curve.S5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s5;
	sharp.Edge_Neg_Curve.S6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s6;
	sharp.Edge_Neg_Curve.S7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s7;
	sharp.Edge_Neg_Curve.S8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s8;
	sharp.Edge_Neg_Curve.S9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s9;
	sharp.Edge_Neg_Curve.S10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s10;
	sharp.Edge_Neg_Curve.S11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s11;
	sharp.Edge_Neg_Curve.S12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s12;
	sharp.Edge_Neg_Curve.S13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s13;
	sharp.Edge_Neg_Curve.S14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingStep.neg_s14;
	sharp.Edge_Neg_Curve.enable = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.Edge_curve_en;

	sharp.Edge_Shp.Edg_D2_Shift_Bit = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.Edge_Shift;
	sharp.Edge_Shp.G_Neg2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.Gain_Neg2;
	sharp.Edge_Shp.G_Pos2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.Gain_Pos2;

	/* Remapping CHIP_TEXTURE_HPF_T*/
	sharp.MK3_Table.Tex_Filter_Sel = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.text_select_filter;
	sharp.MK3_Table.Text_C00 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c0_0;
	sharp.MK3_Table.Text_C10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c1_0;
	sharp.MK3_Table.Text_C20 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c2_0;
	sharp.MK3_Table.Text_C30 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c3_0;
	sharp.MK3_Table.Text_C40 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c4_0;
	sharp.MK3_Table.Text_C50 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c5_0;
	sharp.MK3_Table.Text_C60 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c6_0;
	sharp.MK3_Table.Text_C70 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c7_0;
	sharp.MK3_Table.Text_C80 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c8_0;
	sharp.MK3_Table.Text_C90 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c9_0;
	sharp.MK3_Table.Text_C100 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c10_0;
	sharp.MK3_Table.Text_C03 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c0_3;
	sharp.MK3_Table.Text_C04 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c0_4;

	sharp.MK3_Table.Text_C01 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c0_1;
	sharp.MK3_Table.Text_C11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c1_1;
	sharp.MK3_Table.Text_C21 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c2_1;
	sharp.MK3_Table.Text_C31 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c3_1;
	sharp.MK3_Table.Text_C41 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c4_1;
	sharp.MK3_Table.Text_C51 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c5_1;
	sharp.MK3_Table.Text_C02 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c0_2;
	sharp.MK3_Table.Text_C12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c1_2;
	sharp.MK3_Table.Text_C22 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c2_2;
	sharp.MK3_Table.Text_C32 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c3_2;
	sharp.MK3_Table.Text_C42 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c4_2;
	sharp.MK3_Table.Text_C52 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.coef_c5_2;

	sharp.Tex_Pos_Curve.G0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g0;
	sharp.Tex_Pos_Curve.G1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g1;
	sharp.Tex_Pos_Curve.G2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g2;
	sharp.Tex_Pos_Curve.G3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g3;
	sharp.Tex_Pos_Curve.G4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g4;
	sharp.Tex_Pos_Curve.G5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g5;
	sharp.Tex_Pos_Curve.G6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g6;
	sharp.Tex_Pos_Curve.G7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g7;
	sharp.Tex_Pos_Curve.G8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g8;
	sharp.Tex_Pos_Curve.G9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g9;
	sharp.Tex_Pos_Curve.G10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g10;
	sharp.Tex_Pos_Curve.G11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g11;
	sharp.Tex_Pos_Curve.G12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g12;
	sharp.Tex_Pos_Curve.G13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g13;
	sharp.Tex_Pos_Curve.G14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.pos_g14;

	sharp.Tex_Pos_Curve.S1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s1;
	sharp.Tex_Pos_Curve.S2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s2;
	sharp.Tex_Pos_Curve.S3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s3;
	sharp.Tex_Pos_Curve.S4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s4;
	sharp.Tex_Pos_Curve.S5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s5;
	sharp.Tex_Pos_Curve.S6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s6;
	sharp.Tex_Pos_Curve.S7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s7;
	sharp.Tex_Pos_Curve.S8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s8;
	sharp.Tex_Pos_Curve.S9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s9;
	sharp.Tex_Pos_Curve.S10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s10;
	sharp.Tex_Pos_Curve.S11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s11;
	sharp.Tex_Pos_Curve.S12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s12;
	sharp.Tex_Pos_Curve.S13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s13;
	sharp.Tex_Pos_Curve.S14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.pos_s14;

	sharp.Tex_Neg_Curve.G0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g0;
	sharp.Tex_Neg_Curve.G1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g1;
	sharp.Tex_Neg_Curve.G2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g2;
	sharp.Tex_Neg_Curve.G3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g3;
	sharp.Tex_Neg_Curve.G4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g4;
	sharp.Tex_Neg_Curve.G5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g5;
	sharp.Tex_Neg_Curve.G6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g6;
	sharp.Tex_Neg_Curve.G7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g7;
	sharp.Tex_Neg_Curve.G8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g8;
	sharp.Tex_Neg_Curve.G9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g9;
	sharp.Tex_Neg_Curve.G10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g10;
	sharp.Tex_Neg_Curve.G11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g11;
	sharp.Tex_Neg_Curve.G12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g12;
	sharp.Tex_Neg_Curve.G13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g13;
	sharp.Tex_Neg_Curve.G14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.neg_g14;

	sharp.Tex_Neg_Curve.S1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s1;
	sharp.Tex_Neg_Curve.S2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s2;
	sharp.Tex_Neg_Curve.S3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s3;
	sharp.Tex_Neg_Curve.S4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s4;
	sharp.Tex_Neg_Curve.S5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s5;
	sharp.Tex_Neg_Curve.S6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s6;
	sharp.Tex_Neg_Curve.S7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s7;
	sharp.Tex_Neg_Curve.S8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s8;
	sharp.Tex_Neg_Curve.S9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s9;
	sharp.Tex_Neg_Curve.S10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s10;
	sharp.Tex_Neg_Curve.S11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s11;
	sharp.Tex_Neg_Curve.S12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s12;
	sharp.Tex_Neg_Curve.S13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s13;
	sharp.Tex_Neg_Curve.S14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingStep.neg_s14;
	sharp.Tex_Neg_Curve.enable = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.enable;

	sharp.Texture_Shp.Edg_D2_Shift_Bit = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.Tex_Shift;
	sharp.Texture_Shp.G_Neg2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.Gain_Neg2;
	sharp.Texture_Shp.G_Pos2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.Gain_Pos2;

	sharp.MK3_Table.Slope_gain_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stSlopeGainMask.Slope_Gain_Enable;
	sharp.MK3_Table.dir = ptCHIP_SHARPNESS_UI_T->stSharpness.stSlopeGainMask.DIR;
	sharp.MK3_Table.FH = ptCHIP_SHARPNESS_UI_T->stSharpness.stSlopeGainMask.FH;
	sharp.MK3_Table.Gain_boundPos = ptCHIP_SHARPNESS_UI_T->stSharpness.stSlopeGainMask.Gain_boundPos;
	sharp.MK3_Table.Gain_boundNeg = ptCHIP_SHARPNESS_UI_T->stSharpness.stSlopeGainMask.Gain_boundNeg;
	sharp.MK3_Table.Gain_extendPos = ptCHIP_SHARPNESS_UI_T->stSharpness.stSlopeGainMask.Gain_extendPos;
	sharp.MK3_Table.Gain_extendNeg = ptCHIP_SHARPNESS_UI_T->stSharpness.stSlopeGainMask.Gain_extendNeg;

	sharp.MK3_Table.flat_enable = ptCHIP_SHARPNESS_UI_T->stSharpness.stSlopeGainMask.flat_enable;
	sharp.MK3_Table.flat_offset = ptCHIP_SHARPNESS_UI_T->stSharpness.stSlopeGainMask.flat_offset;
	sharp.MK3_Table.flat_gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stSlopeGainMask.flat_gain;

	sharp.Vertical.C0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalHPF.vpk_c0;
	sharp.Vertical.C1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalHPF.vpk_c1;
	sharp.Vertical.C2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalHPF.vpk_c2;
	sharp.Vertical.C3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalHPF.vpk_c3;
	sharp.Vertical.C4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalHPF.vpk_c4;

	sharp.V_Pos_Curve.G0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g0;
	sharp.V_Pos_Curve.G1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g1;
	sharp.V_Pos_Curve.G2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g2;
	sharp.V_Pos_Curve.G3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g3;
	sharp.V_Pos_Curve.G4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g4;
	sharp.V_Pos_Curve.G5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g5;
	sharp.V_Pos_Curve.G6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g6;
	sharp.V_Pos_Curve.G7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g7;
	sharp.V_Pos_Curve.G8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g8;
	sharp.V_Pos_Curve.G9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g9;
	sharp.V_Pos_Curve.G10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g10;
	sharp.V_Pos_Curve.G11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g11;
	sharp.V_Pos_Curve.G12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g12;
	sharp.V_Pos_Curve.G13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g13;
	sharp.V_Pos_Curve.G14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.pos_g14;

	sharp.V_Pos_Curve.S1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s1;
	sharp.V_Pos_Curve.S2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s2;
	sharp.V_Pos_Curve.S3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s3;
	sharp.V_Pos_Curve.S4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s4;
	sharp.V_Pos_Curve.S5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s5;
	sharp.V_Pos_Curve.S6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s6;
	sharp.V_Pos_Curve.S7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s7;
	sharp.V_Pos_Curve.S8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s8;
	sharp.V_Pos_Curve.S9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s9;
	sharp.V_Pos_Curve.S10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s10;
	sharp.V_Pos_Curve.S11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s11;
	sharp.V_Pos_Curve.S12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s12;
	sharp.V_Pos_Curve.S13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s13;
	sharp.V_Pos_Curve.S14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.pos_s14;

	sharp.V_Neg_Curve.G0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g0;
	sharp.V_Neg_Curve.G1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g1;
	sharp.V_Neg_Curve.G2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g2;
	sharp.V_Neg_Curve.G3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g3;
	sharp.V_Neg_Curve.G4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g4;
	sharp.V_Neg_Curve.G5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g5;
	sharp.V_Neg_Curve.G6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g6;
	sharp.V_Neg_Curve.G7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g7;
	sharp.V_Neg_Curve.G8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g8;
	sharp.V_Neg_Curve.G9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g9;
	sharp.V_Neg_Curve.G10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g10;
	sharp.V_Neg_Curve.G11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g11;
	sharp.V_Neg_Curve.G12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g12;
	sharp.V_Neg_Curve.G13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g13;
	sharp.V_Neg_Curve.G14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.neg_g14;

	sharp.V_Neg_Curve.S1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s1;
	sharp.V_Neg_Curve.S2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s2;
	sharp.V_Neg_Curve.S3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s3;
	sharp.V_Neg_Curve.S4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s4;
	sharp.V_Neg_Curve.S5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s5;
	sharp.V_Neg_Curve.S6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s6;
	sharp.V_Neg_Curve.S7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s7;
	sharp.V_Neg_Curve.S8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s8;
	sharp.V_Neg_Curve.S9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s9;
	sharp.V_Neg_Curve.S10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s10;
	sharp.V_Neg_Curve.S11 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s11;
	sharp.V_Neg_Curve.S12 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s12;
	sharp.V_Neg_Curve.S13 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s13;
	sharp.V_Neg_Curve.S14 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingStep.neg_s14;
	sharp.V_Neg_Curve.enable = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.enable;

	sharp.Vertical.V_Tex_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.v_tex_en;
	sharp.Vertical.V_Dering_En = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.v_dering_en;
	sharp.Vertical.G_Neg2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Gain_Neg2;
	sharp.Vertical.G_Pos2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Gain_Pos2;

	/*mkiii_en  --> mag2 no*/

	sharp.MK3_Table.Gain_By_Y_En = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.gain_by_y_en;
	sharp.MK3_Table.gain_by_y_v_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.gain_by_y_v_en;
	sharp.MK3_Table.gain_by_y_tex_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.gain_by_y_tex_en;
	sharp.MK3_Table.gain_by_y_edg_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.gain_by_y_edg_en;
	sharp.MK3_Table.Lpf_Weigh_En = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.lpf_weight_en;
	sharp.MK3_Table.lpf_weigh_edg_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.lpf_weight_edg_en;
	sharp.MK3_Table.lpf_weigh_tex_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.lpf_weight_tex_en;

	sharp.MK3_Table.MaxMin_Gain_En = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.max_min_gain_en;
	sharp.MK3_Table.max_min_gain_v_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.max_min_v_en;
	sharp.MK3_Table.max_min_gain_tex_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.max_min_tex_en;
	sharp.MK3_Table.max_min_gain_edg_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.max_min_edg_en;

	sharp.MK3_Table.lv_by_y_enable = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.lv_by_Y_enable;
	sharp.MK3_Table.lv_by_y_edg_enable = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.lv_by_y_edg_enable;
	sharp.MK3_Table.lv_by_y_v_edg_enable = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.lv_by_y_v_edg_enable;
	sharp.MK3_Table.lv_by_y_tex_enable = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.lv_by_y_tex_enable;
	sharp.MK3_Table.lv_by_y_v_enable = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.lv_by_y_v_enable;

	sharp.MK3_Table.Lpf2d_C0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.coef_c0;
	sharp.MK3_Table.Lpf2d_C1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.coef_c1;
	sharp.MK3_Table.Lpf2d_C2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.coef_c2;
	sharp.MK3_Table.Lpf2d_C3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.coef_c3;
	sharp.MK3_Table.Lpf2d_C4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.coef_c4;
	sharp.MK3_Table.Lpf2d_C5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.coef_c5;

	sharp.MK3_Table.MaxMin_Step_1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_s1;
	sharp.MK3_Table.MaxMin_Step_2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_s2;
	sharp.MK3_Table.MaxMin_Step_3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_s3;
	sharp.MK3_Table.MaxMin_Step_4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_s4;
	sharp.MK3_Table.MaxMin_Step_5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_s5;
	sharp.MK3_Table.MaxMin_Step_6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_s6;

	sharp.MK3_Table.MaxMin_Gain_0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_g0;
	sharp.MK3_Table.MaxMin_Gain_1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_g1;
	sharp.MK3_Table.MaxMin_Gain_2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_g2;
	sharp.MK3_Table.MaxMin_Gain_3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_g3;
	sharp.MK3_Table.MaxMin_Gain_4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_g4;
	sharp.MK3_Table.MaxMin_Gain_5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_g5;
	sharp.MK3_Table.MaxMin_Gain_6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.maxmin_g6;

	sharp.MK3_Table.Lpf_Step_1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_s1;
	sharp.MK3_Table.Lpf_Step_2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_s2;
	sharp.MK3_Table.Lpf_Step_3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_s3;
	sharp.MK3_Table.Lpf_Step_4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_s4;
	sharp.MK3_Table.Lpf_Step_5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_s5;
	sharp.MK3_Table.Lpf_Step_6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_s6;

	sharp.MK3_Table.Lpf_Weit_0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_g0;
	sharp.MK3_Table.Lpf_Weit_1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_g1;
	sharp.MK3_Table.Lpf_Weit_2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_g2;
	sharp.MK3_Table.Lpf_Weit_3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_g3;
	sharp.MK3_Table.Lpf_Weit_4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_g4;
	sharp.MK3_Table.Lpf_Weit_5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_g5;
	sharp.MK3_Table.Lpf_Weit_6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.blending_g6;

	sharp.MK3_Table.Gain_By_Y_Step_1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_s1;
	sharp.MK3_Table.Gain_By_Y_Step_2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_s2;
	sharp.MK3_Table.Gain_By_Y_Step_3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_s3;
	sharp.MK3_Table.Gain_By_Y_Step_4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_s4;
	sharp.MK3_Table.Gain_By_Y_Step_5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_s5;
	sharp.MK3_Table.Gain_By_Y_Step_6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_s6;

	sharp.MK3_Table.Gain_By_Y_Gain_0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_g0;
	sharp.MK3_Table.Gain_By_Y_Gain_1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_g1;
	sharp.MK3_Table.Gain_By_Y_Gain_2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_g2;
	sharp.MK3_Table.Gain_By_Y_Gain_3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_g3;
	sharp.MK3_Table.Gain_By_Y_Gain_4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_g4;
	sharp.MK3_Table.Gain_By_Y_Gain_5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_g5;
	sharp.MK3_Table.Gain_By_Y_Gain_6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stMKIII.y_g6;


	/* Edge Enhance Part */
	sharp.Edge_EMF_Table.EMF_En = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.emf_enable;
	sharp.Edge_EMF_Table.EMF_Shift = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.emf_shiftbit;
	sharp.Edge_EMF_Table.EMF_Range = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.emf_range;
	sharp.Edge_EMF_Table.EMF_EXT_neg = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.fix_extend_neg;
	sharp.Edge_EMF_Table.EMF_EXT_pos = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.fix_extend_pos;
	sharp.Edge_EMF_Table.Seg_0_x = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.seg0_x;
	sharp.Edge_EMF_Table.Seg_1_x = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.seg1_x;
	sharp.Edge_EMF_Table.Blend_wt = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.blend_wt;
	sharp.Edge_EMF_Table.Seg_0_Gain = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.gain0;
	sharp.Edge_EMF_Table.Seg_1_Gain = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.gain1;
	sharp.Edge_EMF_Table.Seg_2_Gain = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.gain2;
	sharp.Edge_EMF_Table.Seg_0_Offset = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stEdgeEMF.Offset0;
	/*Calc offset 1, 2*/
	if (sharp.Edge_EMF_Table.Seg_0_Gain > 6)
		sharp.Edge_EMF_Table.Seg_0_Gain = 6;
	if (sharp.Edge_EMF_Table.Seg_1_Gain > 6)
		sharp.Edge_EMF_Table.Seg_1_Gain = 6;
	sharp.Edge_EMF_Table.Seg_1_Offset = (EMFGainMap[sharp.Edge_EMF_Table.Seg_0_Gain]<<6) + sharp.Edge_EMF_Table.Seg_0_Offset;
	if (sharp.Edge_EMF_Table.Seg_1_Offset < 0)
		sharp.Edge_EMF_Table.Seg_1_Offset = 0;
	sharp.Edge_EMF_Table.Seg_2_Offset = (EMFGainMap[sharp.Edge_EMF_Table.Seg_1_Gain]<<6) + sharp.Edge_EMF_Table.Seg_1_Offset;
	if (sharp.Edge_EMF_Table.Seg_2_Offset < 0)
		sharp.Edge_EMF_Table.Seg_2_Offset = 0;

	sharp.Text_EMF_Table.EMF_En = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.emf_enable;
	sharp.Text_EMF_Table.EMF_Shift = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.emf_shiftbit;
	sharp.Text_EMF_Table.EMF_Range = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.emf_range;
	sharp.Text_EMF_Table.EMF_EXT_neg = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.fix_extend_neg;
	sharp.Text_EMF_Table.EMF_EXT_pos = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.fix_extend_pos;
	sharp.Text_EMF_Table.Seg_0_x = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.seg0_x;
	sharp.Text_EMF_Table.Seg_1_x = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.seg1_x;
	sharp.Text_EMF_Table.Blend_wt = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.blend_wt;
	sharp.Text_EMF_Table.Seg_0_Gain = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.gain0;
	sharp.Text_EMF_Table.Seg_1_Gain = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.gain1;
	sharp.Text_EMF_Table.Seg_2_Gain = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.gain2;
	sharp.Text_EMF_Table.Seg_0_Offset = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stTextureEMF.Offset0;
	/*Calc offset 1, 2*/
	if (sharp.Text_EMF_Table.Seg_0_Gain > 6)
		sharp.Text_EMF_Table.Seg_0_Gain = 6;
	if (sharp.Text_EMF_Table.Seg_1_Gain > 6)
		sharp.Text_EMF_Table.Seg_1_Gain = 6;
	sharp.Text_EMF_Table.Seg_1_Offset = (EMFGainMap[sharp.Text_EMF_Table.Seg_0_Gain]<<6) + sharp.Text_EMF_Table.Seg_0_Offset;
	if (sharp.Text_EMF_Table.Seg_1_Offset < 0)
		sharp.Text_EMF_Table.Seg_1_Offset = 0;
	sharp.Text_EMF_Table.Seg_2_Offset = (EMFGainMap[sharp.Text_EMF_Table.Seg_1_Gain]<<6) + sharp.Text_EMF_Table.Seg_1_Offset;
	if (sharp.Text_EMF_Table.Seg_2_Offset < 0)
		sharp.Text_EMF_Table.Seg_2_Offset = 0;

	sharp.Vertical.Vemf_En = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stVerticalEMF.vemf_en;
	sharp.Vertical.Vext_Reg = ptCHIP_EDGE_ENHANCE_UI_T->stEdgeEnhance.stVerticalEMF.vext_reg;

	/*SR*/
	sharp.SR_Control.Period = ptCHIP_SR_UI_T->Cur_Period;
	sharp.SR_Control.Gain = ptCHIP_SR_UI_T->Cur_Gain;
	sharp.SR_Control.Offset = ptCHIP_SR_UI_T->Cur_Offset;
	sharp.SR_Control.Ring_Gen_Gain = ptCHIP_SR_UI_T->Ring_Gen_Gain;
	sharp.SR_Control.Ring_Gen = ptCHIP_SR_UI_T->Ring_Gen_Type;
	sharp.SR_Control.HV_Max = ptCHIP_SR_UI_T->Filter_Type;
	sharp.SR_Control.Tex_Filter_Sel = ptCHIP_SR_UI_T->tex_filter_sel;
	sharp.SR_Control.Edg_Filter_Sel = ptCHIP_SR_UI_T->edge_filter_sel;

	sharp.SR_H9.C0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h9_c0;
	sharp.SR_H9.C1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h9_c1;
	sharp.SR_H9.C2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h9_c2;
	sharp.SR_H9.C3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h9_c3;
	sharp.SR_H9.C4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h9_c4;

	sharp.SR_H13.C0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h13_c0;
	sharp.SR_H13.C1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h13_c1;
	sharp.SR_H13.C2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h13_c2;
	sharp.SR_H13.C3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h13_c3;
	sharp.SR_H13.C4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h13_c4;
	sharp.SR_H13.C5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h13_c5;
	sharp.SR_H13.C6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h13_c6;

	sharp.SR_H21.C0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c0;
	sharp.SR_H21.C1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c1;
	sharp.SR_H21.C2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c2;
	sharp.SR_H21.C3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c3;
	sharp.SR_H21.C4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c4;
	sharp.SR_H21.C5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c5;
	sharp.SR_H21.C6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c6;
	sharp.SR_H21.C7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c7;
	sharp.SR_H21.C8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c8;
	sharp.SR_H21.C9 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c9;
	sharp.SR_H21.C10 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c10;

	sharp.SR_V9_1.C0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v91_c0;
	sharp.SR_V9_1.C1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v91_c1;
	sharp.SR_V9_1.C2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v91_c2;
	sharp.SR_V9_1.C3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v91_c3;
	sharp.SR_V9_1.C4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v91_c4;

	sharp.SR_V9_2.C0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v92_c0;
	sharp.SR_V9_2.C1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v92_c1;
	sharp.SR_V9_2.C2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v92_c2;
	sharp.SR_V9_2.C3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v92_c3;
	sharp.SR_V9_2.C4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v92_c4;

	sharp.SR_V9_3.C0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v93_c0;
	sharp.SR_V9_3.C1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v93_c1;
	sharp.SR_V9_3.C2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v93_c2;
	sharp.SR_V9_3.C3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v93_c3;
	sharp.SR_V9_3.C4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.v93_c4;

	sharp.SR_Ring_H11.C0 = ptCHIP_SR_UI_T->ring_h_c0;
	sharp.SR_Ring_H11.C1 = ptCHIP_SR_UI_T->ring_h_c1;
	sharp.SR_Ring_H11.C2 = ptCHIP_SR_UI_T->ring_h_c2;
	sharp.SR_Ring_H11.C3 = ptCHIP_SR_UI_T->ring_h_c3;
	sharp.SR_Ring_H11.C4 = ptCHIP_SR_UI_T->ring_h_c4;
	sharp.SR_Ring_H11.C5 = ptCHIP_SR_UI_T->ring_h_c5;

	sharp.SR_Ring_V9.C0 = ptCHIP_SR_UI_T->ring_v_c0;
	sharp.SR_Ring_V9.C1 = ptCHIP_SR_UI_T->ring_v_c1;
	sharp.SR_Ring_V9.C2 = ptCHIP_SR_UI_T->ring_v_c2;
	sharp.SR_Ring_V9.C3 = ptCHIP_SR_UI_T->ring_v_c3;
	sharp.SR_Ring_V9.C4 = ptCHIP_SR_UI_T->ring_v_c4;

	sharp.MK3_Table.Slope_gain_v_en =  ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalSlopeGainMask.Slope_Gain_V_Enable;
	sharp.MK3_Table.dir_v= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalSlopeGainMask.DIR;
	sharp.MK3_Table.Gain_boundPos_v= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalSlopeGainMask.Gain_boundPos;
	sharp.MK3_Table.Gain_boundNeg_v= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalSlopeGainMask.Gain_boundNeg;
	sharp.MK3_Table.Gain_extendPos_v= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalSlopeGainMask.Gain_extendPos;
	sharp.MK3_Table.Gain_extendNeg_v= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalSlopeGainMask.Gain_extendNeg;

	sharp.MK3_Table.flat_v_enable= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalSlopeGainMask.flat_v_enable;
	sharp.MK3_Table.flat_offset_v= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalSlopeGainMask.flat_offset_v;
	sharp.MK3_Table.flat_gain_v= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalSlopeGainMask.flat_gain_v;



	sharp.Vertical.enable_edge= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.V_Parameters_En;
	sharp.Vertical.G_Pos2_edge= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Edge_Gain_Pos2;
	sharp.Vertical.G_Neg2_edge= ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Edge_Gain_Neg2;


	#if 0 //mac5p no such feature
	sharp.SEGPK_ISE.ise_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stIse.ise_en;
	sharp.SEGPK_ISE.ise_step = ptCHIP_SHARPNESS_UI_T->stSharpness.stIse.ise_step;
	sharp.SEGPK_ISE.ise_scale = ptCHIP_SHARPNESS_UI_T->stSharpness.stIse.ise_scale;
	sharp.SEGPK_ISE.ise_ub = ptCHIP_SHARPNESS_UI_T->stSharpness.stIse.ise_ub;
	sharp.SEGPK_ISE.ise_h_st = ptCHIP_SHARPNESS_UI_T->stSharpness.stIse.ise_h_st;
	sharp.SEGPK_ISE.ise_h_end = ptCHIP_SHARPNESS_UI_T->stSharpness.stIse.ise_h_end;
	sharp.SEGPK_ISE.ise_v_st = ptCHIP_SHARPNESS_UI_T->stSharpness.stIse.ise_v_st;
	sharp.SEGPK_ISE.ise_v_end = ptCHIP_SHARPNESS_UI_T->stSharpness.stIse.ise_v_st;

	sharp.Texture_Flat_Shp.tex_flat_filter_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.tex_flat_filter_en;
	sharp.Texture_Flat_Shp.coef_c0_2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c0_2;
	sharp.Texture_Flat_Shp.coef_c0_1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c0_1;
	sharp.Texture_Flat_Shp.coef_c0_0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c0_0;
	sharp.Texture_Flat_Shp.coef_c1_0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c1_0;
	sharp.Texture_Flat_Shp.coef_c2_0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c2_0;
	sharp.Texture_Flat_Shp.coef_c3_0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c3_0;


	// check Texture_Flat coef
	{
		short tmp;
		tmp = (sharp.Texture_Flat_Shp.coef_c0_0 > 511)?(sharp.Texture_Flat_Shp.coef_c0_0-1024):sharp.Texture_Flat_Shp.coef_c0_0;
		tmp = tmp + (
			(SINT8)ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c0_2 +
			(SINT8)ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c0_1 +
			(SINT8)ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c1_0 +
			(SINT8)ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c2_0 +
			(SINT8)ptCHIP_SHARPNESS_UI_T->stSharpness.stFlatfilter.coef_c3_0)*2;
		if (tmp != 0)
			sharp.Texture_Flat_Shp.tex_flat_filter_en = 0;
	}
	#endif

	/* Get from VIP Table */
	value = Scaler_GetSharpnessTable();
	if (drvif_scaelr3d_decide_is_3D_display_mode() == 1)
		sharp.TwoD_Peak_AdaptCtrl.Peaking_Enable = 0;
	else
		sharp.TwoD_Peak_AdaptCtrl.Peaking_Enable = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Peaking_Enable;
	//sharp.TwoD_Peak_AdaptCtrl.Dering_En = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Dering_En;/*merlin2 removed*/
	sharp.TwoD_Peak_AdaptCtrl.Ring_Tune = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Ring_Tune;
	sharp.TwoD_Peak_AdaptCtrl.Ring_Gain = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Ring_Gain;
	sharp.TwoD_Peak_AdaptCtrl.Ring_Range = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Ring_Range;

	sharp.TwoD_Peak_AdaptCtrl.PkDlti_comsign = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl2.PkDlti_comsign;
	sharp.TwoD_Peak_AdaptCtrl.Hpf_Vpf_Maxmin_En = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Hpf_Vpf_Maxmin_En;/*magellan2*/
	sharp.TwoD_Peak_AdaptCtrl.Src_Sel = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Src_Sel;/*magellan2*/

	drvif_color_Get_Sharpness_lv2(&sharpLV2);
	sharp.Edge_Shp.LV2 = sharpLV2.Edge_LV2;/*gVip_Table->Ddomain_SHPTable[value].Edge_Shp_set.LV2;*/
	sharp.Texture_Shp.LV2 = sharpLV2.Texture_LV2;/*gVip_Table->Ddomain_SHPTable[value].Texture_Shp_set.LV2;*/ //merlin
	sharp.Vertical.LV2 = sharpLV2.Vertical_LV2;/*gVip_Table->Ddomain_SHPTable[value].Vertical.LV2;*/

	sharp.MK3_Table.Edge_Text_blend_en = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl2.Edg_Tex_Blending_Lpf_En;
	sharp.MK3_Table.Edge_Text_blend_filter = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl2.Edg_Tex_Blending_Lpf_Filter;

	/*Input Peaking*//*merlin2 removed*/
	/*
	sharp.Input_Peaking.Peaking_En = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.Peaking_En;
	sharp.Input_Peaking.PxlSel = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.PxlSel;
	sharp.Input_Peaking.C0 = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.C0;
	sharp.Input_Peaking.C1 = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.C1;
	sharp.Input_Peaking.C2 = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.C2;
	sharp.Input_Peaking.Gain_Blr = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.Gain_Blr;
	sharp.Input_Peaking.Gain_Pos = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.Gain_Pos;
	sharp.Input_Peaking.Gain_Neg = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.Gain_Neg;
	sharp.Input_Peaking.HV_Pos = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.HV_Pos;
	sharp.Input_Peaking.HV_Neg = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.HV_Neg;
	sharp.Input_Peaking.LV = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.LV;
	*/

	/*magellan2 start*/
	sharp.After_Filter.C0 = gVip_Table->Ddomain_SHPTable[value].After_Filter.C0;
	sharp.After_Filter.C1 = gVip_Table->Ddomain_SHPTable[value].After_Filter.C1;
	sharp.After_Filter.C2 = gVip_Table->Ddomain_SHPTable[value].After_Filter.C2;
	sharp.After_Filter.C3 = gVip_Table->Ddomain_SHPTable[value].After_Filter.C3;
	sharp.After_Filter.C4 = gVip_Table->Ddomain_SHPTable[value].After_Filter.C4;
	sharp.After_Filter.HPF_Gain = gVip_Table->Ddomain_SHPTable[value].After_Filter.HPF_Gain;
	sharp.After_Filter.Mode = gVip_Table->Ddomain_SHPTable[value].After_Filter.Mode;
	sharp.After_Filter.Enable = gVip_Table->Ddomain_SHPTable[value].After_Filter.Enable;
	/*magellan2 end*/

	sharp.TwoD_Peak_AdaptCtrl.Sobel_h= gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.sobelrange_h;//merlin
	sharp.TwoD_Peak_AdaptCtrl.Sobel_v= gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.sobelrange_v;//merlin
	sharp.TwoD_Peak_AdaptCtrl.Acts_offset= gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.acts_offset;//merlin
	sharp.TwoD_Peak_AdaptCtrl.Small_thl= gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.small_th1;//merlin
	sharp.TwoD_Peak_AdaptCtrl.Edgextrange_v= gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.edgextrange_v;//merlin

	sharp.Edge_SM.dirsm_rangh = gVip_Table->Ddomain_SHPTable[value].Edge_SM.dirsm_rangh;//merlin
	sharp.Edge_SM.dirsm_rangv= gVip_Table->Ddomain_SHPTable[value].Edge_SM.dirsm_rangv;//merlin
	sharp.Edge_SM.meandiff_rangeh= gVip_Table->Ddomain_SHPTable[value].Edge_SM.meandiff_rangeh;//merlin
	sharp.Edge_SM.meandiff_rangev= gVip_Table->Ddomain_SHPTable[value].Edge_SM.meandiff_rangev;//merlin
	sharp.Edge_SM.meandiff_shiftbit= gVip_Table->Ddomain_SHPTable[value].Edge_SM.meandiff_shiftbit;//merlin
	sharp.Edge_SM.meandiff_step= gVip_Table->Ddomain_SHPTable[value].Edge_SM.meandiff_step;//merlin
	sharp.Edge_SM.meandiff_lowbd= gVip_Table->Ddomain_SHPTable[value].Edge_SM.meandiff_lowbd;//merlin
	sharp.Edge_SM.edge_method_sel= gVip_Table->Ddomain_SHPTable[value].Edge_SM.edge_method_sel;//merlin
	sharp.Edge_SM.edgeindex_step= gVip_Table->Ddomain_SHPTable[value].Edge_SM.edgeindex_step;//merlin
	sharp.Edge_SM.edgeindex_lowbd= gVip_Table->Ddomain_SHPTable[value].Edge_SM.edgeindex_lowbd;//merlin

	// patch for small review window
	if (VIP_system_info_structure_table != NULL) {
		if (VIP_system_info_structure_table->Input_src_Type == _SRC_TV) {
			scaleup_dm_uzu_ctrl_RBUS dm_uzu_Ctrl_reg;
			scaleup_dm_uzu_scale_hor_factor_RBUS dm_uzu_Scale_Hor_Factor_REG;
			dm_uzu_Ctrl_reg.regValue = rtd_inl(SCALEUP_DM_UZU_Ctrl_reg);
			dm_uzu_Scale_Hor_Factor_REG.regValue = rtd_inl(SCALEUP_DM_UZU_Scale_Hor_Factor_reg);

			if ((dm_uzu_Ctrl_reg.h_zoom_en == 0 && dm_uzu_Ctrl_reg.v_zoom_en == 0) ||
				(dm_uzu_Ctrl_reg.h_zoom_en == 1 && dm_uzu_Scale_Hor_Factor_REG.hor_factor >= 862017)) {
				sharp.TwoD_Peak_AdaptCtrl.Peaking_Enable = 0;
			}
		}
	}

	drvif_color_Set_Sharpness_Table((DRV_Sharpness_Table *)&sharp);
	}

	{
	DRV_Sharpness_Level sharp_gain;

	sharp_gain.Edge_Level.G_Pos_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.Gain_Pos;
	sharp_gain.Edge_Level.G_Neg_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.Gain_Neg;
	sharp_gain.Edge_Level.HV_POS_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.Range_Pos;
	sharp_gain.Edge_Level.HV_NEG_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.Range_Neg;
	sharp_gain.Edge_Level.LV_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeCurveMappingUI.Coring;

	sharp_gain.Texture_Level.G_Pos_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.Gain_Pos;
	sharp_gain.Texture_Level.G_Neg_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.Gain_Neg;
	sharp_gain.Texture_Level.HV_POS_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.Range_Pos;
	sharp_gain.Texture_Level.HV_NEG_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.Range_Neg;
	sharp_gain.Texture_Level.LV_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureCurveMappingUI.Coring;

	sharp_gain.Vertical_Level.G_Pos_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Gain_Pos;
	sharp_gain.Vertical_Level.G_Neg_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Gain_Neg;
	sharp_gain.Vertical_Level.HV_POS_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Range_Pos;
	sharp_gain.Vertical_Level.HV_NEG_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Range_Neg;
	sharp_gain.Vertical_Level.LV_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Coring;

	sharp_gain.Vertical_Edge_Level.G_Pos_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Edge_Gain_Pos;
	sharp_gain.Vertical_Edge_Level.G_Neg_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Edge_Gain_Neg;
	sharp_gain.Vertical_Edge_Level.HV_POS_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Edge_Range_Pos;
	sharp_gain.Vertical_Edge_Level.HV_NEG_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Edge_Range_Neg;
	sharp_gain.Vertical_Edge_Level.LV_Gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalCurveMappingUI.Edge_Coring;

	drvif_color_set_Sharpness_level((DRV_Sharpness_Level *)&sharp_gain);
	}

	{
	short sumEdgeCoeff = 0;
	short sumEdgeLPF = 1<<ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.edge_lpf_shift;
	short sumSRCoeff = 0;
	DRV_Sharpness_Other_Ctrl sharp_other_ctrl;

	/* Remapping CHIP_EDGE_HPF_T*/
	sharp_other_ctrl.edgpk_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.edgpk_en;
	sharp_other_ctrl.edg_lpf_shift = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.edge_lpf_shift;
	/* Remapping CHIP_TEXTURE_HPF_T*/

	/* calc SR coeff */
	sumSRCoeff = ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c0 +
	((ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c1 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c2 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c3 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c4 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c5 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c6 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c7 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c8 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c9 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stCommonHPF.h21_c10)<<1);

	sharp_other_ctrl.texpk_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.texpk_en;
	if (sumSRCoeff != 0)
		sharp_other_ctrl.texpk_en = 0;
	sharp_other_ctrl.tex_lpf_shift = ptCHIP_SHARPNESS_UI_T->stSharpness.stTextureHPF.tex_lpf_shift;

	/* calc Edge coeff*/
	sumEdgeCoeff = ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c0_0 +
	(((ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c1_0 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c2_0 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c3_0 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c4_0 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c5_0 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c6_0 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c7_0 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c8_0 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c9_0 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c10_0 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c0_1 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c0_2 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c0_3 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c0_4)<<1) +
	((ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c1_1 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c2_1 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c3_1 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c4_1 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c5_1 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c1_2 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c2_2 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c3_2 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c4_2 +
	ptCHIP_SHARPNESS_UI_T->stSharpness.stEdgeHPF.coef_c5_2)<<2));

	if ((ptCHIP_SR_UI_T->edge_filter_sel == 0 && sumEdgeCoeff == 0) ||
		(ptCHIP_SR_UI_T->edge_filter_sel == 1 && sumEdgeCoeff == sumEdgeLPF)) {
		sharp_other_ctrl.segpk_mode = 2;
	} else
		sharp_other_ctrl.segpk_mode = 0;
	sharp_other_ctrl.enhance_mode = 2;
	sharp_other_ctrl.vpk_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stVerticalHPF.vpk_en;

	drvif_color_Set_Sharpness_Other_Table(&sharp_other_ctrl);
	}

	fwif_color_set_iDcti_dDcti_tv006(0, 0, &ptCHIP_SHARPNESS_UI_T->stSharpness.stCTI);

	fwif_color_set_Vdcti_tv006(gVip_Table->VIP_QUALITY_Coef[vip_src][VIP_QUALITY_FUNCTION_V_DCTi], &ptCHIP_SHARPNESS_UI_T->stSharpness.stCTI);
	fwif_color_set_dLti_tv006(gVip_Table->VIP_QUALITY_Coef[vip_src][VIP_QUALITY_FUNCTION_DLTi], &ptCHIP_SHARPNESS_UI_T->stSharpness.stHLTI,&ptCHIP_SHARPNESS_UI_T->stSharpness.stVLTI);
	fwif_color_set_MultiBand_Peaking_tv006(gVip_Table->VIP_QUALITY_Extend3_Coef[vip_src][VIP_QUALITY_FUNCTION_MB_Peaking], &ptCHIP_SHARPNESS_UI_T->stSharpness.stMultibandPeakingHPF, &ptCHIP_SHARPNESS_UI_T->stSharpness.stMultibandPeakingUI);

	#if 0
	DRV_TwoStepSU_SR_Ctrl1 TwoStepSU_SR_Ctrl1;
	DRV_TwoStepSU_SR_Ctrl2 TwoStepSU_SR_Ctrl2;
	DRV_TwoStepSU_SR_Ctrl3 TwoStepSU_SR_Ctrl3;

	TwoStepSU_SR_Ctrl1.maxmin_limit_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.Maxmin_Limit_En;
	TwoStepSU_SR_Ctrl1.maxmin_shift = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.Maxmin_Shift;
	TwoStepSU_SR_Ctrl1.var_thd = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.sr_var_thd;
	TwoStepSU_SR_Ctrl1.maxmin_mode = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.Maxmin_Mode;
	TwoStepSU_SR_Ctrl1.maxmin_range = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.Maxmin_Range;
	TwoStepSU_SR_Ctrl1.maxmin_thd = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.Maxmin_Thd;
	TwoStepSU_SR_Ctrl1.edge_range = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.Edge_Range;
	TwoStepSU_SR_Ctrl1.delta_gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.Delta_Gain;
	TwoStepSU_SR_Ctrl1.lpf_range = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.LPF_Range;
	TwoStepSU_SR_Ctrl3.lpf_range_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.lpf_range_en;

	TwoStepSU_SR_Ctrl3.lpf_range_thd = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.lpf_range_thd;
	TwoStepSU_SR_Ctrl3.lpf_range_gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.lpf_range_gain;
	TwoStepSU_SR_Ctrl3.lpf_range_step = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.lpf_range_step;
	TwoStepSU_SR_Ctrl2.lpf_gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.lpf_gain;
	TwoStepSU_SR_Ctrl3.lpf_edge_en= ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.lpf_edge_en;
	TwoStepSU_SR_Ctrl3.lpf_edge_thd = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.lpf_edge_thd;
	TwoStepSU_SR_Ctrl3.lpf_edge_gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.lpf_edge_gain;
	TwoStepSU_SR_Ctrl3.lpf_edge_step= ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.lpf_edge_step;
	TwoStepSU_SR_Ctrl3.bif_range_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_range_en;
	TwoStepSU_SR_Ctrl1.bif_thd0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_thd0;

	TwoStepSU_SR_Ctrl1.bif_thd1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_thd1;
	TwoStepSU_SR_Ctrl1.bif_thd2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_thd2;
	TwoStepSU_SR_Ctrl1.bif_thd3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_thd3;
	TwoStepSU_SR_Ctrl1.bif_thd4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_thd4;
	TwoStepSU_SR_Ctrl1.bif_thd5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_thd5;
	TwoStepSU_SR_Ctrl1.bif_thd6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_thd6;
	TwoStepSU_SR_Ctrl1.bif_thd7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_thd7;
	TwoStepSU_SR_Ctrl3.bif_range_thd0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_range_thd0;
	TwoStepSU_SR_Ctrl3.bif_range_thd1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_range_thd1;
	TwoStepSU_SR_Ctrl3.bif_range_gain0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_range_gain0;


	TwoStepSU_SR_Ctrl3.bif_range_gain1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_range_gain1;
	TwoStepSU_SR_Ctrl3.bif_range_step0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_range_step0;
	TwoStepSU_SR_Ctrl3.bif_range_step1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_range_step1;
	TwoStepSU_SR_Ctrl2.bif_gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_gain;
	TwoStepSU_SR_Ctrl3.bif_edge_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_edge_en;
	TwoStepSU_SR_Ctrl3.bif_edge_thd = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_edge_thd;
	TwoStepSU_SR_Ctrl3.bif_edge_gain = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_edge_gain;
	TwoStepSU_SR_Ctrl3.bif_edge_step = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.bif_edge_step;
	TwoStepSU_SR_Ctrl2.by_gain_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.by_gain_en;
	TwoStepSU_SR_Ctrl2.diffdir_cond_en = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.diffdir_cond_e;

	TwoStepSU_SR_Ctrl2.by_pgain0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.pgain0;
	TwoStepSU_SR_Ctrl2.by_pgain1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.pgain1;
	TwoStepSU_SR_Ctrl2.by_pgain2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.pgain2;
	TwoStepSU_SR_Ctrl2.by_pgain3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.pgain3;
	TwoStepSU_SR_Ctrl2.by_pgain4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.pgain4;
	TwoStepSU_SR_Ctrl2.by_pgain5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.pgain5;
	TwoStepSU_SR_Ctrl2.by_pgain6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.pgain6;
	TwoStepSU_SR_Ctrl2.by_pgain7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.pgain7;
	TwoStepSU_SR_Ctrl2.by_pgain8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.pgain8;
	TwoStepSU_SR_Ctrl2.by_ngain0 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.ngain0;


	TwoStepSU_SR_Ctrl2.by_ngain1 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.ngain1;
	TwoStepSU_SR_Ctrl2.by_ngain2 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.ngain2;
	TwoStepSU_SR_Ctrl2.by_ngain3 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.ngain3;
	TwoStepSU_SR_Ctrl2.by_ngain4 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.ngain4;
	TwoStepSU_SR_Ctrl2.by_ngain5 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.ngain5;
	TwoStepSU_SR_Ctrl2.by_ngain6 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.ngain6;
	TwoStepSU_SR_Ctrl2.by_ngain7 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.ngain7;
	TwoStepSU_SR_Ctrl2.by_ngain8 = ptCHIP_SHARPNESS_UI_T->stSharpness.stSecondSr.ngain8;

	drvif_color_twostep_scaleup_SR(&(TwoStepSU_SR_Ctrl1), &(TwoStepSU_SR_Ctrl2), &(TwoStepSU_SR_Ctrl3));
	#endif


}

void fwif_color_set_sharpness_table_init_TV006(unsigned char src_idx, unsigned char value)
{
	static DRV_Sharpness_Table sharp;
	_system_setting_info *VIP_system_info_structure_table=(_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	SLR_VIP_TABLE *gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (gVip_Table == NULL) {
		VIPprintf("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	if (value >= Sharp_table_num)
		value = 0;

	/* get para from register */
	drvif_color_Get_Sharpness_Table(&sharp);

	/* Get from VIP Table */
	if (drvif_scaelr3d_decide_is_3D_display_mode() == 1)
		sharp.TwoD_Peak_AdaptCtrl.Peaking_Enable = 0;
	else
		sharp.TwoD_Peak_AdaptCtrl.Peaking_Enable = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Peaking_Enable;

	//sharp.TwoD_Peak_AdaptCtrl.Dering_En = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Dering_En;/*merlin2 removed*/
	sharp.TwoD_Peak_AdaptCtrl.Ring_Tune = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Ring_Tune;
	sharp.TwoD_Peak_AdaptCtrl.Ring_Gain = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Ring_Gain;
	sharp.TwoD_Peak_AdaptCtrl.Ring_Range = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Ring_Range;

	sharp.TwoD_Peak_AdaptCtrl.PkDlti_comsign = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl2.PkDlti_comsign;
	sharp.TwoD_Peak_AdaptCtrl.Hpf_Vpf_Maxmin_En = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Hpf_Vpf_Maxmin_En;/*magellan2*/
	sharp.TwoD_Peak_AdaptCtrl.Src_Sel = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.Src_Sel;/*magellan2*/

	sharp.Edge_Shp.LV2 = gVip_Table->Ddomain_SHPTable[value].Edge_Shp_set.LV2;
	sharp.Texture_Shp.LV2 = gVip_Table->Ddomain_SHPTable[value].Texture_Shp_set.LV2;
	sharp.Vertical.LV2 = gVip_Table->Ddomain_SHPTable[value].Vertical.LV2;//merlin

	sharp.MK3_Table.Edge_Text_blend_en = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl2.Edg_Tex_Blending_Lpf_En;
	sharp.MK3_Table.Edge_Text_blend_filter = gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl2.Edg_Tex_Blending_Lpf_Filter;

	/*Input Peaking*//*merlin2 removed*/
	/*
	sharp.Input_Peaking.Peaking_En = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.Peaking_En;
	sharp.Input_Peaking.PxlSel = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.PxlSel;
	sharp.Input_Peaking.C0 = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.C0;
	sharp.Input_Peaking.C1 = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.C1;
	sharp.Input_Peaking.C2 = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.C2;
	sharp.Input_Peaking.Gain_Blr = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.Gain_Blr;
	sharp.Input_Peaking.Gain_Pos = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.Gain_Pos;
	sharp.Input_Peaking.Gain_Neg = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.Gain_Neg;
	sharp.Input_Peaking.HV_Pos = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.HV_Pos;
	sharp.Input_Peaking.HV_Neg = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.HV_Neg;
	sharp.Input_Peaking.LV = gVip_Table->Ddomain_SHPTable[value].Input_Peaking.LV;
	*/

	/*magellan2 start*/
	sharp.After_Filter.C0 = gVip_Table->Ddomain_SHPTable[value].After_Filter.C0;
	sharp.After_Filter.C1 = gVip_Table->Ddomain_SHPTable[value].After_Filter.C1;
	sharp.After_Filter.C2 = gVip_Table->Ddomain_SHPTable[value].After_Filter.C2;
	sharp.After_Filter.C3 = gVip_Table->Ddomain_SHPTable[value].After_Filter.C3;
	sharp.After_Filter.C4 = gVip_Table->Ddomain_SHPTable[value].After_Filter.C4;
	sharp.After_Filter.HPF_Gain = gVip_Table->Ddomain_SHPTable[value].After_Filter.HPF_Gain;
	sharp.After_Filter.Mode = gVip_Table->Ddomain_SHPTable[value].After_Filter.Mode;
	sharp.After_Filter.Enable = gVip_Table->Ddomain_SHPTable[value].After_Filter.Enable;
	/*magellan2 end*/

	sharp.TwoD_Peak_AdaptCtrl.Sobel_h= gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.sobelrange_h;//merlin
	sharp.TwoD_Peak_AdaptCtrl.Sobel_v= gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.sobelrange_v;//merlin
	sharp.TwoD_Peak_AdaptCtrl.Acts_offset= gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.acts_offset;//merlin
	sharp.TwoD_Peak_AdaptCtrl.Small_thl= gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.small_th1;//merlin
	sharp.TwoD_Peak_AdaptCtrl.Edgextrange_v= gVip_Table->Ddomain_SHPTable[value].TwoD_Peak_AdaptCtrl.edgextrange_v;//merlin

	sharp.Edge_SM.dirsm_rangh = gVip_Table->Ddomain_SHPTable[value].Edge_SM.dirsm_rangh;//merlin
	sharp.Edge_SM.dirsm_rangv= gVip_Table->Ddomain_SHPTable[value].Edge_SM.dirsm_rangv;//merlin
	sharp.Edge_SM.meandiff_rangeh= gVip_Table->Ddomain_SHPTable[value].Edge_SM.meandiff_rangeh;//merlin
	sharp.Edge_SM.meandiff_rangev= gVip_Table->Ddomain_SHPTable[value].Edge_SM.meandiff_rangev;//merlin
	sharp.Edge_SM.meandiff_shiftbit= gVip_Table->Ddomain_SHPTable[value].Edge_SM.meandiff_shiftbit;//merlin
	sharp.Edge_SM.meandiff_step= gVip_Table->Ddomain_SHPTable[value].Edge_SM.meandiff_step;//merlin
	sharp.Edge_SM.meandiff_lowbd= gVip_Table->Ddomain_SHPTable[value].Edge_SM.meandiff_lowbd;//merlin
	sharp.Edge_SM.edge_method_sel= gVip_Table->Ddomain_SHPTable[value].Edge_SM.edge_method_sel;//merlin
	sharp.Edge_SM.edgeindex_step= gVip_Table->Ddomain_SHPTable[value].Edge_SM.edgeindex_step;//merlin
	sharp.Edge_SM.edgeindex_lowbd= gVip_Table->Ddomain_SHPTable[value].Edge_SM.edgeindex_lowbd;//merlin

	// patch for small review window
	if (VIP_system_info_structure_table != NULL) {
		if(VIP_system_info_structure_table->Input_src_Type == _SRC_TV) {
			scaleup_dm_uzu_ctrl_RBUS dm_uzu_Ctrl_reg;
			scaleup_dm_uzu_scale_hor_factor_RBUS dm_uzu_Scale_Hor_Factor_REG;
			dm_uzu_Ctrl_reg.regValue = rtd_inl(SCALEUP_DM_UZU_Ctrl_reg);
			dm_uzu_Scale_Hor_Factor_REG.regValue = rtd_inl(SCALEUP_DM_UZU_Scale_Hor_Factor_reg);

			if ((dm_uzu_Ctrl_reg.h_zoom_en == 0 && dm_uzu_Ctrl_reg.v_zoom_en == 0) ||
				(dm_uzu_Ctrl_reg.h_zoom_en == 1 && dm_uzu_Scale_Hor_Factor_REG.hor_factor >= 862017)) {
				sharp.TwoD_Peak_AdaptCtrl.Peaking_Enable = 0;
			}
		}
	}

	drvif_color_Set_Sharpness_Table((DRV_Sharpness_Table *)&sharp);

	/*
	DRV_Sub_Sharpness_Table sub_sharp = {
		{1, 1, 1, },
		{100, -30, -20, 0, 0, 0, 0, 0, 0, 40, 40, 200, 200, 0, },
		{0, 0, 0, 0, 0, 0, 0, 0,}
	};
	drvif_color_Set_sub_Sharpness_Table((DRV_Sub_Sharpness_Table *)&sub_sharp);
	*/
}

unsigned char fwif_TwoParts_Linear_Interpolation(Sharpness_OSD_Remap_Curve *ptr, unsigned char value)
{


	unsigned char temp = 0;
	unsigned char startPoint, endPoint;
	/*
	unsigned char reg_point_bottom = 0;
	unsigned char reg_point_mid = 0;
	unsigned char reg_point_top = 0;
	*/

	if (value < ptr->Sharpness_OSD_mid) {
		startPoint = ptr->Sharpness_ChipValue_bottom;
		endPoint = ptr->Sharpness_ChipValue_mid;
		temp = (startPoint + (endPoint-startPoint)*value/(ptr->Sharpness_OSD_mid - ptr->Sharpness_OSD_bottom));

	} else {
		startPoint = ptr->Sharpness_ChipValue_mid;
		endPoint = ptr->Sharpness_ChipValue_top;
		value -= ptr->Sharpness_OSD_mid;
		temp = (startPoint + (endPoint-startPoint)*value/(ptr->Sharpness_OSD_top - ptr->Sharpness_OSD_mid));
	}

	if (temp > 255)
		temp = 255;

	return (unsigned char)temp;

}




void fwif_color_set_SharpnessFilterCoef_for_3D(CHIP_SHARPNESS_UI_T *CHIPShpTable, CHIP_SHARPNESS_UI_T *CHIPShpTable3DCorrection)
{


	CHIPShpTable->stSharpness.stEdgeHPF.coef_c0_0 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c0_0;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c1_0 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c1_0;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c2_0 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c2_0;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c3_0 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c3_0;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c4_0 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c4_0;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c5_0 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c5_0;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c0_1 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c0_1;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c1_1 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c1_1;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c2_1 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c2_1;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c3_1 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c3_1;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c4_1 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c4_1;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c5_1 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c5_1;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c0_2 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c0_2;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c1_2 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c1_2;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c2_2 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c2_2;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c3_2 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c3_2;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c4_2 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c4_2;
	CHIPShpTable->stSharpness.stEdgeHPF.coef_c5_2 = CHIPShpTable3DCorrection->stSharpness.stEdgeHPF.coef_c5_2;

	CHIPShpTable->stSharpness.stTextureHPF.coef_c0_0 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c0_0;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c1_0 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c1_0;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c2_0 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c2_0;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c3_0 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c3_0;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c4_0 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c4_0;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c5_0 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c5_0;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c0_1 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c0_1;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c1_1 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c1_1;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c2_1 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c2_1;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c3_1 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c3_1;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c4_1 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c4_1;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c5_1 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c5_1;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c0_2 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c0_2;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c1_2 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c1_2;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c2_2 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c2_2;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c3_2 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c3_2;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c4_2 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c4_2;
	CHIPShpTable->stSharpness.stTextureHPF.coef_c5_2 = CHIPShpTable3DCorrection->stSharpness.stTextureHPF.coef_c5_2;


}

unsigned char  fwif_color_set_dcc_Curve_Write_tv006(signed int *sAccLUT)
{
	//_clues *smartPic_clue = (_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
	_RPC_clues *RPC_smartPic_clue = (_RPC_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_SMARTPIC_CLUS);

	if (RPC_smartPic_clue == NULL) {
		VIPprintf("smartPic_clue NULL!!!");
		return FALSE;
	}

	if (sAccLUT == NULL) {
		VIPprintf("sAccLUT NULL!!!");
		return FALSE;
	}


	/*Monotonic Check*/
	if (Monotonic_Check) {
		int i=0;
		for (i=0; i<DCC_Curve_Node_MAX; i++) {
			*(sAccLUT+i) = *(sAccLUT+i)>>2; // Mac5p fix me : temporary shift 2 bits, need to modify webos code and VIP panel tables
			if ((*(sAccLUT+i)) > (*(sAccLUT+i+1))) {
				VIPprintf("[Warnning] [%s-%s-%d] [DCC Curve] Not monotonic!,index=%d,%d\n", __FILE__, __func__, __LINE__,i,i+1);
				break;
			}
		}
	}

	fwif_color_set_dcc_OnOff(0, DCC_ON_APPLY_AP_CURVE);

	//fwif_color_ChangeINT32Endian_Copy(sAccLUT, DCC_Curve_Node_MAX, smartPic_clue->Adapt_DCC_Info.S_RPC_DCC_LAYER_Array.Apply_Curve, 0);
	fwif_color_ChangeINT32Endian_Copy(sAccLUT, DCC_Curve_Node_MAX, RPC_smartPic_clue->RPC_Adapt_DCC_Info.Apply_Curve, 0);
	return TRUE;
}

unsigned char  fwif_color_set_bypass_dcc_Curve_Write_tv006(void)
{
	//_clues *smartPic_clue = (_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
	_RPC_clues *RPC_smartPic_clue = (_RPC_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_SMARTPIC_CLUS);
	signed int sAccLUT[DCC_Curve_Node_MAX];
	int i;

	if (RPC_smartPic_clue == NULL) {
		VIPprintf("smartPic_clue NULL!!!");
		return FALSE;
	}

	for (i = 0; i < DCC_Curve_Node_MAX-1; i++) {
		sAccLUT[i] = i<<5;
	}
	sAccLUT[DCC_Curve_Node_MAX-1] = 4095;

	fwif_color_set_dcc_OnOff(0, DCC_ON_APPLY_AP_CURVE);
	//fwif_color_ChangeINT32Endian_Copy(sAccLUT, DCC_Curve_Node_MAX, smartPic_clue->Adapt_DCC_Info.S_RPC_DCC_LAYER_Array.Apply_Curve, 0);
	fwif_color_ChangeINT32Endian_Copy(sAccLUT, DCC_Curve_Node_MAX, RPC_smartPic_clue->RPC_Adapt_DCC_Info.Apply_Curve, 0);
	return TRUE;
}

unsigned char fwif_color_set_dcc_FreshContrast_tv006(CHIP_DCC_T *ptr)
{
	if (!ptr) {
		VIPprintf("~fwif_color_set_dcc_FreshContrast_tv006 Table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return FALSE;
	}

	{
	UINT8 i = 0;
	int tmp, tmpValue, tmpDiff;
	static VIP_DCC_Chroma_Compensation_TABLE Chroma_Compensation_TABLE;

	Chroma_Compensation_TABLE.Chroma_Compensation_Ctrl.gain_en = ptr->stChromaGain.chroma_gain_en;
	Chroma_Compensation_TABLE.Chroma_Compensation_Ctrl.gain_mode = ptr->stChromaGain.chroma_gain_mode;
	Chroma_Compensation_TABLE.Chroma_Compensation_Ctrl.gain_lookup_mode = ptr->stChromaGain.chroma_gain_lookup_mode;
	Chroma_Compensation_TABLE.Chroma_Compensation_Ctrl.gain_base = ptr->stChromaGain.chroma_gain_base;
	Chroma_Compensation_TABLE.Chroma_Compensation_Ctrl.enh_mode_above_tab_sel = ptr->stChromaGain.chroma_enhance_above_tab_select_main;
	Chroma_Compensation_TABLE.Chroma_Compensation_Ctrl.enh_mode_below_tab_sel = ptr->stChromaGain.chroma_enhance_below_tab_select_main;
	Chroma_Compensation_TABLE.Chroma_Compensation_Ctrl.byY_mode_u_tab_sel = ptr->stChromaGain.saturation_byy_u_tab_select_main;
	Chroma_Compensation_TABLE.Chroma_Compensation_Ctrl.byY_mode_v_tab_sel = ptr->stChromaGain.saturation_byy_v_tab_select_main;

	for(i = 0; i < Chroma_Gain_Limit_Seg_MAX; i++) {
		Chroma_Compensation_TABLE.chroma_gain_limit[i] = ptr->stChromaGain.chroma_gain_limit_seg[i];
	}

	for(i = 0; i < (Chroma_Gain_Seg_MAX>>2); i++) {
		tmp = i<<2;
		tmpValue = ptr->stChromaGain.chroma_gain_tab0_seg[i];
		tmpDiff = ptr->stChromaGain.chroma_gain_tab0_seg[i+1]-tmpValue;
		Chroma_Compensation_TABLE.chroma_gain_t0[tmp] = tmpValue;
		Chroma_Compensation_TABLE.chroma_gain_t0[tmp+1] = tmpValue+(tmpDiff>>2);
		Chroma_Compensation_TABLE.chroma_gain_t0[tmp+2] = tmpValue+(tmpDiff>>1);
		Chroma_Compensation_TABLE.chroma_gain_t0[tmp+3] = tmpValue+tmpDiff-(tmpDiff>>2);
	}
	Chroma_Compensation_TABLE.chroma_gain_t0[Chroma_Gain_Seg_MAX-1] = ptr->stChromaGain.chroma_gain_tab0_seg[16];

	for(i = 0; i < (Chroma_Gain_Seg_MAX>>2); i++){
		tmp = i<<2;
		tmpValue = ptr->stChromaGain.chroma_gain_tab1_seg[i];
		tmpDiff = ptr->stChromaGain.chroma_gain_tab1_seg[i+1]-tmpValue;
		Chroma_Compensation_TABLE.chroma_gain_t1[tmp] = tmpValue;
		Chroma_Compensation_TABLE.chroma_gain_t1[tmp+1] = tmpValue+(tmpDiff>>2);
		Chroma_Compensation_TABLE.chroma_gain_t1[tmp+2] = tmpValue+(tmpDiff>>1);
		Chroma_Compensation_TABLE.chroma_gain_t1[tmp+3] = tmpValue+tmpDiff-(tmpDiff>>2);
	}
	Chroma_Compensation_TABLE.chroma_gain_t1[Chroma_Gain_Seg_MAX-1] = ptr->stChromaGain.chroma_gain_tab1_seg[16];

	drvif_color_set_dcc_chroma_compensation_Curve_Mode(_MAIN_DISPLAY, &Chroma_Compensation_TABLE);
	}

	{
	VIP_DCC_Color_Independent_Blending_Table Color_independent = {0};

	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Y_Center0 = ptr->stSkinTone.range.y0_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.U_Center0 = ptr->stSkinTone.range.u0_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.V_Center0 = ptr->stSkinTone.range.v0_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Y_Range0 = ptr->stSkinTone.range.y0_range;
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.U_Range0 = ptr->stSkinTone.range.u0_range;
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.V_Range0 = ptr->stSkinTone.range.v0_range;

	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Y_Center1 = ptr->stSkinTone.range.y1_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.U_Center1 = ptr->stSkinTone.range.u1_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.V_Center1 = ptr->stSkinTone.range.v1_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Y_Range1 = ptr->stSkinTone.range.y1_range;
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.U_Range1 = ptr->stSkinTone.range.u1_range;
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.V_Range1 = ptr->stSkinTone.range.v1_range;

	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Y_Center2 = ptr->stSkinTone.range.y2_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.U_Center2 = ptr->stSkinTone.range.u2_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.V_Center2 = ptr->stSkinTone.range.v2_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Y_Range2 = ptr->stSkinTone.range.y2_range;
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.U_Range2 = ptr->stSkinTone.range.u2_range;
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.V_Range2 = ptr->stSkinTone.range.v2_range;

	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Y_Center3 = ptr->stSkinTone.range.y3_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.U_Center3 = ptr->stSkinTone.range.u3_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.V_Center3 = ptr->stSkinTone.range.v3_center;
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Y_Range3 = ptr->stSkinTone.range.y3_range;
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.U_Range3 = ptr->stSkinTone.range.u3_range;
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.V_Range3 = ptr->stSkinTone.range.v3_range;

	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.region0_en = ptr->stSkinTone.value.D_DCC_SKIN_EN;
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_0 = ptr->stSkinTone.value.Y0_seg[0];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_1 = ptr->stSkinTone.value.Y0_seg[1];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_2 = ptr->stSkinTone.value.Y0_seg[2];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_3 = ptr->stSkinTone.value.Y0_seg[3];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_4 = ptr->stSkinTone.value.Y0_seg[4];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_5 = ptr->stSkinTone.value.Y0_seg[5];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_6 = ptr->stSkinTone.value.Y0_seg[6];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_7 = ptr->stSkinTone.value.Y0_seg[7];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_0_c = ptr->stSkinTone.value.C0_seg[0];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_1_c = ptr->stSkinTone.value.C0_seg[1];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_2_c = ptr->stSkinTone.value.C0_seg[2];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_3_c = ptr->stSkinTone.value.C0_seg[3];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_4_c = ptr->stSkinTone.value.C0_seg[4];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_5_c = ptr->stSkinTone.value.C0_seg[5];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_6_c = ptr->stSkinTone.value.C0_seg[6];
	Color_independent.S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_7_c = ptr->stSkinTone.value.C0_seg[7];

	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.region1_en = ptr->stSkinTone.value.D_DCC_SKIN_EN;
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_0 = ptr->stSkinTone.value.Y1_seg[0];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_1 = ptr->stSkinTone.value.Y1_seg[1];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_2 = ptr->stSkinTone.value.Y1_seg[2];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_3 = ptr->stSkinTone.value.Y1_seg[3];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_4 = ptr->stSkinTone.value.Y1_seg[4];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_5 = ptr->stSkinTone.value.Y1_seg[5];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_6 = ptr->stSkinTone.value.Y1_seg[6];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_7 = ptr->stSkinTone.value.Y1_seg[7];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_0_c = ptr->stSkinTone.value.C1_seg[0];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_1_c = ptr->stSkinTone.value.C1_seg[1];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_2_c = ptr->stSkinTone.value.C1_seg[2];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_3_c = ptr->stSkinTone.value.C1_seg[3];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_4_c = ptr->stSkinTone.value.C1_seg[4];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_5_c = ptr->stSkinTone.value.C1_seg[5];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_6_c = ptr->stSkinTone.value.C1_seg[6];
	Color_independent.S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_7_c = ptr->stSkinTone.value.C1_seg[7];

	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.region2_en = ptr->stSkinTone.value.D_DCC_SKIN_EN;
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_0 = ptr->stSkinTone.value.Y2_seg[0];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_1 = ptr->stSkinTone.value.Y2_seg[1];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_2 = ptr->stSkinTone.value.Y2_seg[2];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_3 = ptr->stSkinTone.value.Y2_seg[3];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_4 = ptr->stSkinTone.value.Y2_seg[4];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_5 = ptr->stSkinTone.value.Y2_seg[5];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_6 = ptr->stSkinTone.value.Y2_seg[6];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_7 = ptr->stSkinTone.value.Y2_seg[7];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_0_c = ptr->stSkinTone.value.C2_seg[0];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_1_c = ptr->stSkinTone.value.C2_seg[1];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_2_c = ptr->stSkinTone.value.C2_seg[2];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_3_c = ptr->stSkinTone.value.C2_seg[3];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_4_c = ptr->stSkinTone.value.C2_seg[4];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_5_c = ptr->stSkinTone.value.C2_seg[5];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_6_c = ptr->stSkinTone.value.C2_seg[6];
	Color_independent.S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_7_c = ptr->stSkinTone.value.C2_seg[7];

	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.region3_en = ptr->stSkinTone.value.D_DCC_SKIN_EN;
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_0 = ptr->stSkinTone.value.Y3_seg[0];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_1 = ptr->stSkinTone.value.Y3_seg[1];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_2 = ptr->stSkinTone.value.Y3_seg[2];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_3 = ptr->stSkinTone.value.Y3_seg[3];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_4 = ptr->stSkinTone.value.Y3_seg[4];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_5 = ptr->stSkinTone.value.Y3_seg[5];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_6 = ptr->stSkinTone.value.Y3_seg[6];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_7 = ptr->stSkinTone.value.Y3_seg[7];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_0_c = ptr->stSkinTone.value.C3_seg[0];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_1_c = ptr->stSkinTone.value.C3_seg[1];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_2_c = ptr->stSkinTone.value.C3_seg[2];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_3_c = ptr->stSkinTone.value.C3_seg[3];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_4_c = ptr->stSkinTone.value.C3_seg[4];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_5_c = ptr->stSkinTone.value.C3_seg[5];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_6_c = ptr->stSkinTone.value.C3_seg[6];
	Color_independent.S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_7_c = ptr->stSkinTone.value.C3_seg[7];

	drvif_color_set_dcc_Color_Independent(&Color_independent);
	}
	return TRUE;
}

void fwif_color_set_iDcti_dDcti_tv006(unsigned char i_dcti_val, unsigned char d_dcti_val, CHIP_CTI_T *set_cti_db)
{
	extern DRV_VipNewIDcti_Table gVipINewDcti_Table[DCTI_TABLE_LEVEL_MAX];
	extern DRV_VipNewDDcti_Table gVipDNewDcti_Table[DCTI_TABLE_LEVEL_MAX];
	static CHIP_CTI_T cti_db = {0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	static unsigned char i_dcti_val_real = 0;
	static unsigned char d_dcti_val_real = 0;
	_system_setting_info *VIP_system_info_structure_table = NULL;
	DRV_VipNewIDcti_Table i_dcti;
	DRV_VipNewDDcti_Table d_dcti;

	if (NULL != set_cti_db) {
		memcpy(&cti_db, set_cti_db, sizeof(CHIP_CTI_T));
	} else {
		StructColorDataType *pTable = NULL;
		unsigned char src_idx = 0;
		unsigned char display = 0;
		Scaler_Get_Display_info(&display, &src_idx);

		pTable = fwif_color_get_color_data(src_idx, 0);
		if (pTable == NULL)
			return;
		pTable->I_NEWDCTi = i_dcti_val;
		pTable->DCti = d_dcti_val;

		if (i_dcti_val >= DCTI_TABLE_LEVEL_MAX)
			i_dcti_val = 0;

		if (d_dcti_val >= DCTI_TABLE_LEVEL_MAX)
			d_dcti_val = 0;

		i_dcti_val_real = i_dcti_val;
		d_dcti_val_real = d_dcti_val;
	}

	memcpy(&i_dcti, &gVipINewDcti_Table[i_dcti_val_real], sizeof(DRV_VipNewIDcti_Table));
	memcpy(&d_dcti, &gVipDNewDcti_Table[d_dcti_val_real], sizeof(DRV_VipNewDDcti_Table));

	if (cti_db.i_dcti_enable != 0xff)
	{
		i_dcti.VipNewIDcti_ctl1.dcti_en = cti_db.i_dcti_enable;
		i_dcti.VipNewIDcti_ctl1.uvgain = cti_db.i_dcti_gain;
		i_dcti.VipNewIDcti_ctl1.dcti_mode = cti_db.i_dcti_mode;
		i_dcti.VipNewIDcti_ctl1.uvalign_en = cti_db.i_dcti_uv_align_enable;
		i_dcti.VipNewIDcti_ctl2.uvsync_en = cti_db.i_dcti_uv_sync_enable;
		i_dcti.VipNewIDcti_ctl1.maxlen = cti_db.i_dcti_Max_search_range;
		i_dcti.VipNewIDcti_ctl1.psmth = cti_db.i_dcti_Threshold_of_smooth;

		d_dcti.VipNewDDcti_ctl1.dcti_en = cti_db.d_dcti_enable;
		d_dcti.VipNewDDcti_ctl1.uvgain = cti_db.d_dcti_gain;
		d_dcti.VipNewDDcti_ctl1.dcti_mode = cti_db.d_dcti_mode;
		d_dcti.VipNewDDcti_ctl1.uvalign_en = cti_db.d_dcti_uv_align_enable;
		d_dcti.VipNewDDcti_ctl2.uvsync_en = cti_db.d_dcti_uv_sync_enable;
		d_dcti.VipNewDDcti_ctl1.maxlen = cti_db.d_dcti_Max_search_range;
		d_dcti.VipNewDDcti_ctl1.psmth = cti_db.d_dcti_Threshold_of_smooth;
	}

	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	VIP_system_info_structure_table->PQ_Setting_Info.I_D_Dcti_INFO.iDcti_table_select = i_dcti_val_real;
	VIP_system_info_structure_table->PQ_Setting_Info.I_D_Dcti_INFO.dDcti_table_select = d_dcti_val_real;

	drvif_color_inewdcti_table(&i_dcti);
	drvif_color_dnewdcti_table(&d_dcti);
}

void fwif_color_set_Vdcti_tv006(unsigned char v_dcti_val, CHIP_CTI_T *set_cti_db)
{
	extern DRV_D_vcti_t gVipVcti_Table[DCTI_TABLE_LEVEL_MAX];
	DRV_D_vcti_t drv_D_vcti_t;

	memcpy(&drv_D_vcti_t, &gVipVcti_Table[v_dcti_val], sizeof(DRV_D_vcti_t));

	if (set_cti_db == NULL)
		return;	/* quality handle, DB can't be overwrited */

	/*printk("vcti=%d,%d,%d,\n", set_cti_db->vcti_gain,  set_cti_db->vcti_type, set_cti_db->vcti_type3_thd);*/

	/*==========set from DB=============*/
	/* data check*/
	if ((set_cti_db->vcti_type <= 3) && (set_cti_db->vcti_gain <= 127) && (set_cti_db->vcti_type3_thd <= 63)) {
		drv_D_vcti_t.vcti_en = set_cti_db->vcti_enable;
		drv_D_vcti_t.vcti_select = set_cti_db->vcti_type;
		drv_D_vcti_t.vcti_gain = set_cti_db->vcti_gain;
		drv_D_vcti_t.vcti_type3_thd = set_cti_db->vcti_type3_thd;
	}
	/*==========set from DB END=============*/
	unsigned char old_db_read_level;
	scaleup_dm_uzu_db_ctrl_RBUS scaleup_dm_uzu_db_ctrl_reg;
	scaleup_dm_uzu_db_ctrl_reg.regValue = rtd_inl(SCALEUP_DM_UZU_DB_CTRL_reg);
	old_db_read_level = scaleup_dm_uzu_db_ctrl_reg.db_read_level;
	scaleup_dm_uzu_db_ctrl_reg.db_read_level = 0;
	rtd_outl(SCALEUP_DM_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_reg.regValue);

	if (SCALEUP_DM_UZU_Ctrl_get_v_zoom_en(rtd_inl(SCALEUP_DM_UZU_Ctrl_reg)) == 0 && !drvif_scalerdisplay_get_force_bg_status()/* && Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE*/) {
		scaleup_dm_uzu_db_ctrl_reg.db_read_level = old_db_read_level;
		rtd_outl(SCALEUP_DM_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_reg.regValue);
		return;
	}
	scaleup_dm_uzu_db_ctrl_reg.db_read_level = old_db_read_level;
	rtd_outl(SCALEUP_DM_UZU_DB_CTRL_reg, scaleup_dm_uzu_db_ctrl_reg.regValue);

	drvif_color_scaler_setds_vcti(_MAIN_DISPLAY,&drv_D_vcti_t);

}

void fwif_color_set_dLti_tv006(unsigned char d_lti_val, CHIP_HLTI_T *H_LTI_db,CHIP_VLTI_T *V_LTI_db)
{
	extern DRV_D_DLTI_Table D_DLTI_Table[D_DLTI_table_num];
	DRV_D_DLTI_Table drv_shp_Dlti = {0};
	static CHIP_HLTI_T store_HLTI_db = {0};
	static CHIP_VLTI_T store_VLTI_db = {0};

	UINT8 lti_gain;

	/*printk("fwif_color_set_dLti_tv006=%d\n",d_lti_val);*/

	if (d_lti_val >= sizeof(D_DLTI_Table)/sizeof(DRV_D_DLTI_Table)) {/* 255 = bypass*/
		drvif_color_Set_D_DLTI_Table(&drv_shp_Dlti);
		return;
	}

	memcpy(&drv_shp_Dlti, &D_DLTI_Table[d_lti_val], sizeof(DRV_D_DLTI_Table));

	if (H_LTI_db == NULL)
		//return;	/* quality handle, DB can't be overwrited */
		H_LTI_db = &store_HLTI_db;
	else
		memcpy(&store_HLTI_db, H_LTI_db, sizeof(CHIP_HLTI_T));

	if (V_LTI_db == NULL)
		//return;	/* quality handle, DB can't be overwrited */
		V_LTI_db = &store_VLTI_db;
	else
		memcpy(&store_VLTI_db, V_LTI_db, sizeof(CHIP_VLTI_T));


	drv_shp_Dlti.DLTI_Control.Dlti_en = 1; //this bit always Enable.

	/*==========set from DB H LTI=============*/


	drv_shp_Dlti.DLTI_H_1.dlti_h_en = H_LTI_db->d_LTI_enable;
	drv_shp_Dlti.DLTI_H_1.Can_shift = H_LTI_db->d_LTI_can_shift;
	drv_shp_Dlti.DLTI_H_1.maxlen =	H_LTI_db->d_LTI_maxlen;
	drv_shp_Dlti.DLTI_H_1.pnth = H_LTI_db->d_LTI_pnth;
	drv_shp_Dlti.DLTI_H_2.tn_blend_en = H_LTI_db->tn_blend_Enable;
	drv_shp_Dlti.DLTI_H_2.ffd2_en = H_LTI_db->ffd2_Enable;
	drv_shp_Dlti.DLTI_H_1.Data_sel = H_LTI_db->Data_sel;
	drv_shp_Dlti.DLTI_H_2.tn_blend_mode = H_LTI_db->tn_blend_mode;
	drv_shp_Dlti.DLTI_H_2.D1_CP_shift = H_LTI_db->D1_CP_Shift;
	drv_shp_Dlti.DLTI_H_2.DCP_th = H_LTI_db->DCP_th;
	drv_shp_Dlti.DLTI_H_2.flat_s_range = H_LTI_db->Flat_s_range;
	drv_shp_Dlti.DLTI_H_2.flat_score_thl = H_LTI_db->Flat_score_th1;
	drv_shp_Dlti.DLTI_H_1.Ffd1_th = H_LTI_db->Ffd1_th;
	drv_shp_Dlti.DLTI_H_1.Ffd1_ratio = H_LTI_db->Ffd1_ratio;

	drv_shp_Dlti.DLTI_H_2.Ffd2_range2R = H_LTI_db->Ffd2_range2R;
	drv_shp_Dlti.DLTI_H_2.Ffd2_range2L = H_LTI_db->Ffd2_range2L;
	drv_shp_Dlti.DLTI_H_2.Ffd2_ratio = H_LTI_db->Ffd2_ratio;
	drv_shp_Dlti.DLTI_H_OverEnhance.gain_pos = H_LTI_db->gain_pos;
	drv_shp_Dlti.DLTI_H_OverEnhance.offset_pos = H_LTI_db->offset_pos;
	drv_shp_Dlti.DLTI_H_OverEnhance.gain_neg = H_LTI_db->gain_neg;
	drv_shp_Dlti.DLTI_H_OverEnhance.offset_neg = H_LTI_db->offset_neg;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff0 = H_LTI_db->Tnoff0;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff1 = H_LTI_db->Tnoff1;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff2 = H_LTI_db->Tnoff2;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff3 = H_LTI_db->Tnoff3;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff4 = H_LTI_db->Tnoff4;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff5 = H_LTI_db->Tnoff5;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff6 = H_LTI_db->Tnoff6;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff7 = H_LTI_db->Tnoff7;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff8 = H_LTI_db->Tnoff8;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff9 = H_LTI_db->Tnoff9;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff10 = H_LTI_db->Tnoff10;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff11 = H_LTI_db->Tnoff11;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff12 = H_LTI_db->Tnoff12;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff13 = H_LTI_db->Tnoff13;
	drv_shp_Dlti.DLTI_H_Tnoff.Tnoff14 = H_LTI_db->Tnoff14;

	/*==========set from DB V LTI=============*/

	#if 0 // mac5p no Vertical DLTI

	drv_shp_Dlti.DLTI_V_1.dlti_v_en = V_LTI_db->d_LTI_enable;
	drv_shp_Dlti.DLTI_V_1.can_shift_v = V_LTI_db->Can_shift_v;
	drv_shp_Dlti.DLTI_V_1.maxlen_v =	V_LTI_db->maxlen_v;
	drv_shp_Dlti.DLTI_V_1.pnth_v= V_LTI_db->pnth_v;
	drv_shp_Dlti.DLTI_V_1.ffd1_th = V_LTI_db->ffd1_th_v;
	drv_shp_Dlti.DLTI_V_1.ffd1_ratio = V_LTI_db->ffd1_ratio_v;
	drv_shp_Dlti.DLTI_V_OverEnhance.gain_pos = V_LTI_db->gain_pos_v;
	drv_shp_Dlti.DLTI_V_OverEnhance.offset_pos = V_LTI_db->offset_pos_v;
	drv_shp_Dlti.DLTI_V_OverEnhance.gain_neg = V_LTI_db->gain_neg_v;
	drv_shp_Dlti.DLTI_V_OverEnhance.offset_neg = V_LTI_db->offset_neg_v;
	drv_shp_Dlti.DLTI_V_Tnoff.Tnoff0 = V_LTI_db->Tnoff0_v;
	drv_shp_Dlti.DLTI_V_Tnoff.Tnoff1 = V_LTI_db->Tnoff1_v;
	drv_shp_Dlti.DLTI_V_Tnoff.Tnoff2 = V_LTI_db->Tnoff2_v;
	drv_shp_Dlti.DLTI_V_Tnoff.Tnoff3 = V_LTI_db->Tnoff3_v;
	drv_shp_Dlti.DLTI_V_Tnoff.Tnoff4 = V_LTI_db->Tnoff4_v;
	drv_shp_Dlti.DLTI_V_Tnoff.Tnoff5 = V_LTI_db->Tnoff5_v;
	drv_shp_Dlti.DLTI_V_Tnoff.Tnoff6 = V_LTI_db->Tnoff6_v;
	#endif

#if 0

	/*printk("lti0=%d,%d,%d,%d,%d,gain=%d\n", D_DLTI_Table[1].DLTI_H_Tnoff.Tnoff10,D_DLTI_Table[1].DLTI_H_Tnoff.Tnoff11,  D_DLTI_Table[1].DLTI_H_Tnoff.Tnoff12, D_DLTI_Table[1].DLTI_H_Tnoff.Tnoff13,D_DLTI_Table[1].DLTI_H_Tnoff.Tnoff14,lti_gain);*/

	/*printk("lti2=%d,%d,%d,%d,%d\n", LTI_db->d_LTI_can_shift,LTI_db->d_LTI_pnth, LTI_db->d_LTI_maxlen,LTI_db->d_LTI_gain ,drv_shp_Dlti.curve5);*/

	/*==========set from DB=============*/
	/* data check for  H LTI */
	if ((H_LTI_db->h_lti.d_LTI_can_shift <= 3) && (H_LTI_db->h_lti.d_LTI_pnth <= 1023) && (H_LTI_db->h_lti.d_LTI_maxlen <= 7) && (H_LTI_db->d_LTI_gain <= 100))
		{
		drv_shp_Dlti.DLTI_Control.Dlti_en = H_LTI_db->d_LTI_enable;
		drv_shp_Dlti.DLTI_H_1.Can_shift = H_LTI_db->d_LTI_can_shift;
		drv_shp_Dlti.DLTI_H_1.maxlen = 	H_LTI_db->d_LTI_maxlen;
		drv_shp_Dlti.DLTI_H_1.pnth = H_LTI_db->d_LTI_pnth;
		//lti_gain = LTI_db->h_lti.d_LTI_gain;

		//printk("lti1=%d,%d,%d,%d,%d,gain=%d\n", drv_shp_Dlti.DLTI_H_Tnoff.Tnoff10,drv_shp_Dlti.DLTI_H_Tnoff.Tnoff11,  drv_shp_Dlti.DLTI_H_Tnoff.Tnoff12, drv_shp_Dlti.DLTI_H_Tnoff.Tnoff13,drv_shp_Dlti.DLTI_H_Tnoff.Tnoff14,lti_gain);
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff0 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff0 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff1 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff1 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff2 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff2 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff3 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff3 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff4 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff4 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff5 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff5 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff6 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff6 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff7 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff7 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff8 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff8 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff9 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff9 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff10 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff10 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff11 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff11 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff12 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff12 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff12 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff13 * lti_gain / 100;
		drv_shp_Dlti.DLTI_H_Tnoff.Tnoff14 = drv_shp_Dlti.DLTI_H_Tnoff.Tnoff14 * lti_gain / 100;

	}
	/*==========set from DB END=============*/

#endif

	//printk("lti2=%d,%d,%d,%d,%d,gain=%d\n", drv_shp_Dlti.DLTI_H_Tnoff.Tnoff10,drv_shp_Dlti.DLTI_H_Tnoff.Tnoff11,  drv_shp_Dlti.DLTI_H_Tnoff.Tnoff12, drv_shp_Dlti.DLTI_H_Tnoff.Tnoff13,drv_shp_Dlti.DLTI_H_Tnoff.Tnoff14,lti_gain);
	drvif_color_Set_D_DLTI_Table(&drv_shp_Dlti);

}

void fwif_color_set_MultiBand_Peaking_tv006(unsigned char multiBand_val, CHIP_MULTIBAND_PEAKING_HPF_T *mb_hpf, CHIP_MULTIBAND_PEAKING_UI_T* mb_UI)
{
	DRV_MBPK_Table MBPK;

	/* ==================get data from vip table======================*/
	UINT8 value = multiBand_val;
	SLR_VIP_TABLE *gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	short h_dc_check, v_dc_check;
	if (gVip_Table == NULL) {
		VIPprintf("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	if (value >= MBPK_table_num) {	/* bypass = 255*/
		MBPK.MBPK_Ctrl.mb_peaking_en = 0;
		value = 0;
	} else {
		MBPK.MBPK_Ctrl.mb_peaking_en = gVip_Table->Idomain_MBPKTable[value].MBPK_Ctrl.mb_peaking_en;
	}

	MBPK.MBPK_Ctrl.MB_Ver_Vfilter_data = gVip_Table->Idomain_MBPKTable[value].MBPK_Ctrl.MB_Ver_Vfilter_data;
	MBPK.MBPK_Ctrl.MB_H_En = gVip_Table->Idomain_MBPKTable[value].MBPK_Ctrl.MB_H_En;
	MBPK.MBPK_Ctrl.MB_V_En = gVip_Table->Idomain_MBPKTable[value].MBPK_Ctrl.MB_V_En;

	MBPK.MBPK_H_Coef.MB_Hor_Filter_C0 = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Coef.MB_Hor_Filter_C0;
	MBPK.MBPK_H_Coef.MB_Hor_Filter_C1 = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Coef.MB_Hor_Filter_C1;
	MBPK.MBPK_H_Coef.MB_Hor_Filter_C2 = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Coef.MB_Hor_Filter_C2;
	MBPK.MBPK_H_Coef.MB_Hor_Filter_C3 = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Coef.MB_Hor_Filter_C3;
	MBPK.MBPK_H_Coef.MB_Hor_Filter_C4 = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Coef.MB_Hor_Filter_C4;
	MBPK.MBPK_H_Coef.MB_Hor_Filter_C5 = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Coef.MB_Hor_Filter_C5;
	MBPK.MBPK_H_Coef.MB_Hor_Filter_C6 = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Coef.MB_Hor_Filter_C6;

	MBPK.MBPK_H_Table.MB_D2_shift_bit = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Table.MB_D2_shift_bit;
	MBPK.MBPK_H_Table.MB_Gain_Neg = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Table.MB_Gain_Neg;
	MBPK.MBPK_H_Table.MB_Gain_Neg2 = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Table.MB_Gain_Neg2;
	MBPK.MBPK_H_Table.MB_Gain_Pos = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Table.MB_Gain_Pos;
	MBPK.MBPK_H_Table.MB_Gain_Pos2 = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Table.MB_Gain_Pos2;
	MBPK.MBPK_H_Table.MB_HV_Neg = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Table.MB_HV_Neg;
	MBPK.MBPK_H_Table.MB_HV_Pos = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Table.MB_HV_Pos;
	MBPK.MBPK_H_Table.MB_LV = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Table.MB_LV;
	MBPK.MBPK_H_Table.MB_LV2 = gVip_Table->Idomain_MBPKTable[value].MBPK_H_Table.MB_LV2;

	MBPK.MBPK_V_Coef.MB_Ver_Filter_C0 = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Coef.MB_Ver_Filter_C0;
	MBPK.MBPK_V_Coef.MB_Ver_Filter_C1 = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Coef.MB_Ver_Filter_C1;
	MBPK.MBPK_V_Coef.MB_Ver_Filter_C2 = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Coef.MB_Ver_Filter_C2;

	MBPK.MBPK_V_Table.MB_D2_shift_bit_V = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Table.MB_D2_shift_bit_V;
	MBPK.MBPK_V_Table.MB_Gain_Neg2_V = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Table.MB_Gain_Neg2_V;
	MBPK.MBPK_V_Table.MB_Gain_Neg_V = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Table.MB_Gain_Neg_V;
	MBPK.MBPK_V_Table.MB_Gain_Pos2_V = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Table.MB_Gain_Pos2_V;
	MBPK.MBPK_V_Table.MB_Gain_Pos_V = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Table.MB_Gain_Pos_V;
	MBPK.MBPK_V_Table.MB_HV_Neg_V = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Table.MB_HV_Neg_V;
	MBPK.MBPK_V_Table.MB_HV_Pos_V = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Table.MB_HV_Pos_V;
	MBPK.MBPK_V_Table.MB_LV2_V = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Table.MB_LV2_V;
	MBPK.MBPK_V_Table.MB_LV_V = gVip_Table->Idomain_MBPKTable[value].MBPK_V_Table.MB_LV_V;

	/* ==================get data from vip table END======================*/

	if (mb_hpf == NULL || mb_UI == NULL)
		return;	/* quality handle, DB can't be overwrited */

	/*==========set from DB=============*/
	/* filter coeg dc check*/
	h_dc_check = mb_hpf->h_c0 + 2*mb_hpf->h_c1 + 2*mb_hpf->h_c2 + 2*mb_hpf->h_c3 + 2*mb_hpf->h_c4 + 2*mb_hpf->h_c5 + 2*mb_hpf->h_c6;
	v_dc_check = mb_hpf->v_c0 + 2*mb_hpf->v_c1 + 2*mb_hpf->v_c2;
	/*printk("MB=%d,%d,%d,%d,%d,%d,%d,,%d,%d,%d,%d\n", mb_hpf->h_c0,mb_hpf->h_c1,mb_hpf->h_c2,mb_hpf->h_c3,mb_hpf->h_c4,mb_hpf->h_c5,mb_hpf->h_c6
		,mb_hpf->v_c0,mb_hpf->v_c1,mb_hpf->v_c2);*/
	if ((h_dc_check == 0) && (v_dc_check == 0) && (mb_hpf->h_c0 != 0) && (mb_hpf->v_c0 != 0)) {
		MBPK.MBPK_Ctrl.mb_peaking_en = mb_hpf->mb_peaking_en;
		MBPK.MBPK_H_Coef.MB_Hor_Filter_C0 = mb_hpf->h_c0;
		MBPK.MBPK_H_Coef.MB_Hor_Filter_C1 = mb_hpf->h_c1;
		MBPK.MBPK_H_Coef.MB_Hor_Filter_C2 = mb_hpf->h_c2;
		MBPK.MBPK_H_Coef.MB_Hor_Filter_C3 = mb_hpf->h_c3;
		MBPK.MBPK_H_Coef.MB_Hor_Filter_C4 = mb_hpf->h_c4;
		MBPK.MBPK_H_Coef.MB_Hor_Filter_C5 = mb_hpf->h_c5;
		MBPK.MBPK_H_Coef.MB_Hor_Filter_C6 = mb_hpf->h_c6;
		MBPK.MBPK_V_Coef.MB_Ver_Filter_C0 = mb_hpf->v_c0;
		MBPK.MBPK_V_Coef.MB_Ver_Filter_C1 = mb_hpf->v_c1;
		MBPK.MBPK_V_Coef.MB_Ver_Filter_C2 = mb_hpf->v_c2;

		MBPK.MBPK_Ctrl.MB_H_En = mb_UI->mb_h_en;
		MBPK.MBPK_H_Table.MB_Gain_Pos = mb_UI->H_Gain_Pos;
		MBPK.MBPK_H_Table.MB_Gain_Neg = mb_UI->H_Gain_Neg;
		MBPK.MBPK_H_Table.MB_LV = mb_UI->H_Coring;
		MBPK.MBPK_H_Table.MB_Gain_Pos2 = mb_UI->H_Gain_Pos2;
		MBPK.MBPK_H_Table.MB_Gain_Neg2 = mb_UI->H_Gain_Neg2;
		MBPK.MBPK_H_Table.MB_HV_Neg = mb_UI->H_Range_Pos;
		MBPK.MBPK_H_Table.MB_HV_Pos = mb_UI->H_Range_Neg;
		MBPK.MBPK_H_Table.MB_D2_shift_bit = mb_UI->H_Edge_Shift;
		MBPK.MBPK_Ctrl.MB_V_En = mb_UI->mb_v_en;
		MBPK.MBPK_V_Table.MB_Gain_Pos_V = mb_UI->V_Gain_Pos;
		MBPK.MBPK_V_Table.MB_Gain_Neg_V = mb_UI->V_Gain_Neg;
		MBPK.MBPK_V_Table.MB_LV_V = mb_UI->V_Coring;
		MBPK.MBPK_V_Table.MB_Gain_Pos2_V = mb_UI->V_Gain_Pos2;
		MBPK.MBPK_V_Table.MB_Gain_Neg2_V = mb_UI->V_Gain_Neg2;
		MBPK.MBPK_V_Table.MB_HV_Pos_V = mb_UI->V_Range_Pos;
		MBPK.MBPK_V_Table.MB_HV_Neg_V = mb_UI->V_Range_Neg;
		MBPK.MBPK_V_Table.MB_D2_shift_bit_V = mb_UI->V_Edge_Shift;
	}
	/*==========set from DB END=============*/

	drvif_color_Set_MBPK_Table((DRV_MBPK_Table *)&MBPK);
}

void fwif_color_set_inv_gamma_encode_tv006(void)
{
	extern unsigned int final_GAMMA_R[512];
	extern unsigned int final_GAMMA_G[512];
	extern unsigned int final_GAMMA_B[512];

	drvif_color_Inv_Gamma_Curve_Write(final_GAMMA_R, GAMMA_CHANNEL_R);	/*R*/
	drvif_color_Inv_Gamma_Curve_Write(final_GAMMA_G, GAMMA_CHANNEL_G);	/*G*/
	drvif_color_Inv_Gamma_Curve_Write(final_GAMMA_B, GAMMA_CHANNEL_B);	/*B*/
}

void fwif_color_set_out_gamma_encode_tv006(void)
{
	extern unsigned int out_GAMMA_R[128];
	extern unsigned int out_GAMMA_G[128];
	extern unsigned int out_GAMMA_B[128];

	drvif_color_Out_Gamma_Curve_Write(out_GAMMA_R, GAMMA_CHANNEL_R);	/*R*/
	drvif_color_Out_Gamma_Curve_Write(out_GAMMA_G, GAMMA_CHANNEL_G);	/*G*/
	drvif_color_Out_Gamma_Curve_Write(out_GAMMA_B, GAMMA_CHANNEL_B);	/*B*/
}

void fwif_color_set_cds_table_tv006(unsigned char table_idx)
{
	SLR_VIP_TABLE *gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	DRV_CDS_Table CDS_Table = {0};
	StructColorDataType *pTable = NULL;
	unsigned char src_idx = 0;
	unsigned char display = 0;
	Scaler_Get_Display_info(&display, &src_idx);

	pTable = fwif_color_get_color_data(src_idx, 0);
	if (pTable == NULL)
		return;

	pTable->CDS_Table = table_idx;

	if (gVip_Table == NULL) {
		VIPprintf("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	if (table_idx < Sharp_table_num)	/* bypass = 255*/
	memcpy(&CDS_Table, &(gVip_Table->CDS_ini[table_idx]), sizeof(DRV_CDS_Table));

	CDS_Table.CDS_Global_Ctrl.cds_enable = 0;//due to basic sharpness is zero, only CDS effect will casue pq abnormal.

	drvif_color_set_cds_table((DRV_CDS_Table *) (&CDS_Table));
}

void fwif_color_set_DCC_Init_tv006(void)
{
	int i;
	signed int FreshContrastLUT[DCC_Curve_Node_MAX];

	for (i = 0; i < DCC_Curve_Node_MAX; i++)
		FreshContrastLUT[i] = i << 5;

	fwif_color_set_dcc_Curve_Write_tv006(FreshContrastLUT);
}
#if 0
unsigned char fwif_color_set_Gamut_3D_Lut_N9_to_N17_tv006(GAMUT_3D_LUT_9x9x9_T *pLut)
{
	GAMUT_3D_LUT_17x17x17_T *pLut_17_tmp = NULL;
	unsigned int *pLUT3D = NULL;
	int x, y, z, xp, yp, zp;
	int idx = -1;
	SLR_VIP_TABLE *gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();

	if (NULL == pLut)
		return FALSE;

	if (pLut->index >= LUT3D_TBL_Num)
		return FALSE;

	pLUT3D = gVip_Table->LUT_3D[pLut->index];

	pLut_17_tmp = (GAMUT_3D_LUT_17x17x17_T *)vip_malloc(sizeof(GAMUT_3D_LUT_17x17x17_T));
	if (pLut_17_tmp == NULL) {
		VIPprintf("%s malloc fail!!\n", __FUNCTION__);
		return FALSE;
	}

	/*interpolation r*/
	for (z = 0; z < 9; z++) {
		for (y = 0; y < 9; y++) {
			for (x = 0; x < 9; x++) {
				xp = x<<1; yp = y<<1; zp = z<<1;
				pLut_17_tmp->pt[xp][yp][zp].r_data = pLut->pt[x][y][z].r_data;
				pLut_17_tmp->pt[xp][yp][zp].g_data = pLut->pt[x][y][z].g_data;
				pLut_17_tmp->pt[xp][yp][zp].b_data = pLut->pt[x][y][z].b_data;
				if (x < 8) {
					pLut_17_tmp->pt[xp+1][yp][zp].r_data = (pLut->pt[x][y][z].r_data+pLut->pt[x+1][y][z].r_data)>>1;
					pLut_17_tmp->pt[xp+1][yp][zp].g_data = (pLut->pt[x][y][z].g_data+pLut->pt[x+1][y][z].g_data)>>1;
					pLut_17_tmp->pt[xp+1][yp][zp].b_data = (pLut->pt[x][y][z].b_data+pLut->pt[x+1][y][z].b_data)>>1;
				}
			}
		}
	}

	/*interpolation g*/
	for (z = 0; z < 9; z++) {
		for (xp = 0; xp < 17; xp++) {
			for (y = 0; y < 8; y++) {
				yp = y<<1; zp = z<<1;
				pLut_17_tmp->pt[xp][yp+1][zp].r_data = (pLut_17_tmp->pt[xp][yp][zp].r_data+pLut_17_tmp->pt[xp][yp+2][zp].r_data)>>1;
				pLut_17_tmp->pt[xp][yp+1][zp].g_data = (pLut_17_tmp->pt[xp][yp][zp].g_data+pLut_17_tmp->pt[xp][yp+2][zp].g_data)>>1;
				pLut_17_tmp->pt[xp][yp+1][zp].b_data = (pLut_17_tmp->pt[xp][yp][zp].b_data+pLut_17_tmp->pt[xp][yp+2][zp].b_data)>>1;
			}
		}
	}

	/*interpolation b*/
	for (xp = 0; xp < 17; xp++) {
		for (yp = 0; yp < 17; yp++) {
			for (z = 0; z < 8; z++) {
				zp = z<<1;
				pLut_17_tmp->pt[xp][yp][zp+1].r_data = (pLut_17_tmp->pt[xp][yp][zp].r_data+pLut_17_tmp->pt[xp][yp][zp+2].r_data)>>1;
				pLut_17_tmp->pt[xp][yp][zp+1].g_data = (pLut_17_tmp->pt[xp][yp][zp].g_data+pLut_17_tmp->pt[xp][yp][zp+2].g_data)>>1;
				pLut_17_tmp->pt[xp][yp][zp+1].b_data = (pLut_17_tmp->pt[xp][yp][zp].b_data+pLut_17_tmp->pt[xp][yp][zp+2].b_data)>>1;
			}
		}
	}

	for (zp = 0; zp < 17; zp++) {
		for (yp = 0; yp < 17; yp++) {
			for (xp = 0; xp < 17; xp++) {
				idx++;
				pLUT3D[idx<<1] = (pLut_17_tmp->pt[xp][yp][zp].r_data<<16)+pLut_17_tmp->pt[xp][yp][zp].g_data;
				pLUT3D[(idx<<1)+1] = pLut_17_tmp->pt[xp][yp][zp].b_data;
			}
		}
	}

	vip_free(pLut_17_tmp);
	return TRUE;
}
#endif

unsigned char fwif_color_set_Gamut_3D_Lut_buffer_tv006(GAMUT_3D_LUT_17x17x17_T *pLut)
{
	unsigned int *pLUT3D = NULL;
	int idx;
	SLR_VIP_TABLE *gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();

	if (NULL == pLut || NULL == gVip_Table)
		return FALSE;

	if (pLut->index >= LUT3D_TBL_Num)
		return FALSE;

	pLUT3D = gVip_Table->LUT_3D[pLut->index];

	for (idx = 0; idx < 4913; idx++) {
		//pLUT3D[idx<<1] = (pLut->pt[idx].r_data<<16)+pLut->pt[idx].g_data;
		//pLUT3D[(idx<<1)+1] = pLut->pt[idx].b_data;
		pLUT3D[(idx * 3)] = pLut->pt[idx].r_data;
		pLUT3D[(idx * 3) + 1] = pLut->pt[idx].g_data;
		pLUT3D[(idx * 3) + 2] = pLut->pt[idx].b_data;
	}

	return TRUE;
}

unsigned char fwif_color_set_Gamut_3D_Lut_ext_buffer_tv006(GAMUT_3D_LUT_17x17x17_T *pLut)
{
	unsigned int *pLUT3D = NULL;
	extern unsigned int LG_LUT_3D_EXTEND[LUT3D_EXTEND_TBL_Num][LUT3D_TBL_ITEM];
	int idx;

	if (NULL == pLut)
		return FALSE;

	pLUT3D = LG_LUT_3D_EXTEND[pLut->index-IDX_3DLUT_EXT_TABLE_START];

	for (idx = 0; idx < 4913; idx++) {
		pLUT3D[idx<<1] = (pLut->pt[idx].r_data<<16)+pLut->pt[idx].g_data;
		pLUT3D[(idx<<1)+1] = pLut->pt[idx].b_data;
	}

	return TRUE;
}

void fwif_color_set_color_temp_tv006(unsigned char enable, unsigned short Red_Con, unsigned short Green_Con, unsigned short Blue_Con,
	short Red_Bri, short Green_Bri, short Blue_Bri, unsigned char waitSync)
{
	if (waitSync)
		fwif_color_WaitFor_SYNC_START_UZUDTG();
	drvif_color_set_color_temp(enable, Red_Con, Green_Con, Blue_Con, Red_Bri, Green_Bri, Blue_Bri);
}

char fwif_color_set_bt2020_Handler_tv006(unsigned char display, unsigned char Enable_Flag, unsigned char bt2020_Mode)
{
	unsigned char InvGamma_TBL_Sel, CM_TBL_Select;
	unsigned short *invGammaTBL;
	DRV_VIP_YUV2RGB_CSMatrix drv_vipCSMatrix_t;

	_system_setting_info *VIP_system_info_structure_table = NULL;
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	memcpy(&drv_vipCSMatrix_t, &(VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix), sizeof(DRV_VIP_YUV2RGB_CSMatrix));
	fwif_color_ChangeUINT32Endian((unsigned int *) &(drv_vipCSMatrix_t.RGB_Offset), 3, 0);
	fwif_color_ChangeUINT16Endian(&(drv_vipCSMatrix_t.COEF_By_Y.K11[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
	fwif_color_ChangeUINT16Endian(&(drv_vipCSMatrix_t.COEF_By_Y.K12[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
	fwif_color_ChangeUINT16Endian(&(drv_vipCSMatrix_t.COEF_By_Y.K13[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
	fwif_color_ChangeUINT16Endian(&(drv_vipCSMatrix_t.COEF_By_Y.K22[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
	fwif_color_ChangeUINT16Endian(&(drv_vipCSMatrix_t.COEF_By_Y.K23[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
	fwif_color_ChangeUINT16Endian(&(drv_vipCSMatrix_t.COEF_By_Y.K32[0]), VIP_YUV2RGB_Y_Seg_Max, 0);
	fwif_color_ChangeUINT16Endian(&(drv_vipCSMatrix_t.COEF_By_Y.K33[0]), VIP_YUV2RGB_Y_Seg_Max, 0);

	if (display == SLR_MAIN_DISPLAY) {
		if (Enable_Flag == 1) {
			VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag = Enable_Flag;
			VIP_system_info_structure_table->BT2020_CTRL.Mode = bt2020_Mode;
		} else {
			VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag = 0;
			VIP_system_info_structure_table->BT2020_CTRL.Mode = BT2020_MODE_Max;
		}
	} else {
		VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag_Sub = 0;
		VIP_system_info_structure_table->BT2020_CTRL.Mode_Sub = BT2020_MODE_Max;
		VIPprintf("No Sub for bt 2020, return\n");
		return -1;
#if 0
		if (Enable_Flag == 1) {
			VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag_Sub = Enable_Flag;
			VIP_system_info_structure_table->BT2020_CTRL.Mode_Sub = bt2020_Mode;
			if (bt2020_Mode == BT2020_MODE_Non_Constant)
				VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode_Sub = YUV2RGB_INPUT_2020_NonConstantY;
			else
				VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode_Sub = YUV2RGB_INPUT_2020_ConstantY;
		} else {
			VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag_Sub = 0;
			VIP_system_info_structure_table->BT2020_CTRL.Mode_Sub = BT2020_MODE_Max;
			VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.Input_Data_Mode_Sub = YUV2RGB_INPUT_MODE_UNKNOW;/*determine by "Scaler_SetDataFormatHandler()"*/
		}
#endif
	}

	if (bt2020_Mode == BT2020_MODE_Constant && Enable_Flag == 1) {
		InvGamma_TBL_Sel = 1;
		invGammaTBL = &Power22InvGamma[0];
		CM_TBL_Select = 1;
		drv_vipCSMatrix_t.CTRL_ITEM.Bt2020_En_TBL1 = 1;
		drv_vipCSMatrix_t.CTRL_ITEM.CoefByY_En = 0;	/* refference to spec*/
		drv_vipCSMatrix_t.CTRL_ITEM.UVOffset_En = 0;	/* refference to spec*/
	} else {
		InvGamma_TBL_Sel = 0;
		invGammaTBL = &LinearInvGamma[0];
		CM_TBL_Select = 0;
		drv_vipCSMatrix_t.CTRL_ITEM.Bt2020_En_TBL1 = 0;
		drv_vipCSMatrix_t.CTRL_ITEM.CoefByY_En = 2; //force Coef by Sat for tv006
	}

	/*record to sh mem*/
	/*memcpy(&(VIP_system_info_structure_table->using_YUV2RGB_Matrix_Info.YUV2RGB_CSMatrix), &drv_vipCSMatrix_t, sizeof(DRV_VIP_YUV2RGB_CSMatrix));*/

	/* set RGB2YUV*/
	Scaler_SetDataFormatHandler();
	/* set Inv Gamma*/
	fwif_color_set_InvGamma(display, InvGamma_TBL_Sel, invGammaTBL, invGammaTBL, invGammaTBL);
	/* set Color Mapping Matrix*/
	fwif_color_set_color_mapping(0, CM_TBL_Select);
	/* set YUV2RGB*/
	/*fwif_color_setCon_Bri_Color_Tint_inYUV2RGB_from_OSD_Gain(0, display, VIP_system_info_structure_table);*/
	fwif_color_setCon_Bri_Color_Tint_tv006(display, VIP_system_info_structure_table);

	/* set Bt2020 Constant mode enable */
	drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_YUV2RGB_Base_Ctrl, VIP_YUV2RGB_Y_Seg_0, SLR_MAIN_DISPLAY, VIP_Table_Select_1);
	drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_CoefByY_ctrl, VIP_YUV2RGB_Y_Seg_0, SLR_MAIN_DISPLAY, VIP_Table_Select_1);
	drvif_color_setYUV2RGB_CSMatrix(&drv_vipCSMatrix_t, VIP_CSMatrix_UVOffset_ctrl, VIP_YUV2RGB_Y_Seg_0, SLR_MAIN_DISPLAY, VIP_Table_Select_1);
	return 0;
}


unsigned char fwif_color_vpq_stop_ioctl(VPQ_IOCTL_STOP_RUN id, ACCESS_MODE mode, unsigned char isStop)
{
	static unsigned char ioctl_stop[STOP_VPQ_IOC_MAX] = {0};

	if (mode == ACCESS_MODE_SET) {
		ioctl_stop[id] = isStop;
	}

	return ioctl_stop[id];
}

unsigned char fwif_color_get_LD_GetAPL_TV006(UINT16* BLValue)
{
	unsigned char ret = 1;
	if(BLValue == NULL) {
		VIPprintf(" [Warning] fw GetAPL is not correct, BLValue is NULL\n");
		ret = 0;
		return ret;
	}

	ret = drvif_color_get_LD_GetAPL_TV006(BLValue);
	return ret;
}

void fwif_color_SetDataFormatHandler_tv006(void)
{
	unsigned char en_422to444, InputSrcGetType, InputSrcGetFrom;
	unsigned short mode, channel;
	SCALER_DISP_CHANNEL display;
	unsigned char nMode = 0;
	_system_setting_info *system_info_struct = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	mode = Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR);
	display = (SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	channel = Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL);
	en_422to444 = (unsigned char)Scaler_DispGetStatus(display, SLR_DISP_422);
	InputSrcGetType = Scaler_InputSrcGetType(display);

	if (fwif_color_get_force_run_i3ddma_enable(display)) {
		fwif_color_vsc_to_scaler_src_mapping(Get_DisplayMode_Src(display), &InputSrcGetType, &InputSrcGetFrom);
		mode = fwif_color_get_cur_input_timing_mode(display);
	}

	if (!(vsc_get_adaptivestream_flag()))
		drvif_color_set422to444(channel, en_422to444);

	if (InputSrcGetType == _SRC_YPBPR) {
		if ((mode !=  _MODE_480I)
			&& (mode !=  _MODE_480P)
			&& (mode !=  _MODE_576I)
			&& (mode !=  _MODE_576P))
			nMode = 1;
	} else if ( InputSrcGetType == _SRC_VO || InputSrcGetType == _SRC_HDMI || InputSrcGetType == _SRC_DISPLAYPORT ) {
		if ((mode !=  _MODE_480I)
			&& (mode !=  _MODE_480P)
			&& (mode !=  _MODE_576I)
			&& (mode !=  _MODE_576P))
			nMode = 1;
	}

	fwif_color_colorspacergb2yuvtransfer(channel, InputSrcGetType, nMode, 1, 1);
	fwif_color_setCon_Bri_Color_Tint_tv006(0, system_info_struct);
}

#ifdef CONFIG_HDR_SDR_SEAMLESS
void fwif_color_SetDataFormatHandler_tv006_Seamless(unsigned char HDR_Mode)
{
	unsigned char InputSrcGetType = Scaler_InputSrcGetType(SLR_MAIN_DISPLAY);
	_system_setting_info *system_info_struct = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	fwif_color_colorspacergb2yuvtransfer_Seamless(HDR_Mode, InputSrcGetType, 0);
	fwif_color_setCon_Bri_Color_Tint_tv006(0, system_info_struct);
}
#endif

void fwif_color_3d_lut_init_tv006(void)
{
	int i;
	extern GAMUT_3D_LUT_17x17x17_T gVip_3DLut_TV006[IDX_3DLUT_MAX];

	for (i = 0; i < IDX_3DLUT_BIG_TABLE_MAX; i++) {
		fwif_color_set_Gamut_3D_Lut_buffer_tv006(&gVip_3DLut_TV006[i]);
	}

	for (i = IDX_3DLUT_EXT_TABLE_START; i < IDX_3DLUT_MAX; i++) {
		fwif_color_set_Gamut_3D_Lut_ext_buffer_tv006(&gVip_3DLut_TV006[i]);
	}
}

unsigned char fwif_color_3d_lut_access_index(ACCESS_MODE access, unsigned char setIdx)
{
	static unsigned char curIdx = 0;

	if (access == ACCESS_MODE_GET)
		return curIdx;
	else if (access == ACCESS_MODE_SET)
		curIdx = setIdx;

	return 0;
}

void fwif_color_set_cinema_mode_en(unsigned char bEn)
{
	bCinemaModeEn = bEn;

	return;
}

unsigned char fwif_color_get_cinema_mode_en(void)
{
	return bCinemaModeEn;
}

int fwif_color_set_dcc_force_write_flag_RPC(unsigned sendRPC, unsigned int force_write)
{
	int ret;

	fwif_color_ChangeUINT32Endian(&force_write, 1, 0);

	memcpy((unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SET_DCC_FORCE_UPDATE), &force_write, sizeof(unsigned int));

	if (!sendRPC)
		return 0;

	ret = Scaler_SendRPC(SCALERIOC_VIP_SET_DCC_FORCE_UPDATE, 0, 0);
	if (0 !=  ret) {
		VIPprintf("ret = %d, set SCALERIOC_VIP_SET_DCC_FORCE_UPDATE to driver fail !!!\n", ret);
	}

	return ret;
}

unsigned char od_table_tv006_store[OD_table_length];
unsigned int od_table_store_target[OD_table_length];
unsigned int od_delta_table[OD_table_length];

//tv006 DB trans to delta mode table
void fwif_color_od_table_tv006_convert(unsigned char *pTableIn, unsigned int *pTableOut)
{
	int x, y, xp, yp, yp2;
	unsigned char tmp[3][34];

	if (pTableIn == NULL || pTableOut == NULL)
		return;

	for (y = 0; y < 17; y++) {
		if (y == 0) {
			yp = 0;
			yp2 = 17;
			for (x = 0; x < 17; x++) {
				xp = x<<1;
				tmp[0][xp] = pTableIn[yp+x];
				tmp[2][xp] = pTableIn[yp2+x];
			}
			for (x = 1; x < 32; x+=2) {
				tmp[0][x] = (tmp[0][x-1]+tmp[0][x+1])>>1;
				tmp[2][x] = (tmp[2][x-1]+tmp[2][x+1])>>1;
			}
			for (x = 0; x < 33; x++) {
				tmp[1][x] = (tmp[0][x]+tmp[2][x])>>1;
			}
			tmp[0][33] = tmp[0][32];
			tmp[1][33] = tmp[1][32];
			tmp[2][33] = tmp[2][32];

			for (x = 0; x < 17; x++) {
				xp = x<<1;
				od_table_store_target[yp+x] =
					(tmp[0][xp]<<24)+
					(tmp[1][xp]<<16)+
					(tmp[0][xp+1]<<8)+
					tmp[1][xp+1];
			}

			memcpy(tmp[0], tmp[2], 34);
		} else if (y < 16) {
			yp = 17*y;
			yp2 = 17*(y+1);
			for (x = 0; x < 17; x++) {
				xp = x<<1;
				tmp[2][xp] = pTableIn[yp2+x];
			}
			for (x = 1; x < 32; x+=2) {
				tmp[2][x] = (tmp[2][x-1]+tmp[2][x+1])>>1;
			}
			for (x = 0; x < 33; x++) {
				tmp[1][x] = (tmp[0][x]+tmp[2][x])>>1;
			}
			tmp[1][33] = tmp[1][32];
			tmp[2][33] = tmp[2][32];

			for (x = 0; x < 17; x++) {
				xp = x<<1;
				od_table_store_target[yp+x] =
					(tmp[0][xp]<<24)+
					(tmp[1][xp]<<16)+
					(tmp[0][xp+1]<<8)+
					tmp[1][xp+1];
			}

			memcpy(tmp[0], tmp[2], 34);
		} else {
			yp = 17*y;
			memcpy(tmp[1], tmp[0], 34);
			for (x = 0; x < 17; x++) {
				xp = x<<1;
				od_table_store_target[yp+x] =
					(tmp[0][xp]<<24)+
					(tmp[1][xp]<<16)+
					(tmp[0][xp+1]<<8)+
					tmp[1][xp+1];
			}
		}
	}

	// trans target mode to delta mode
	/*
	fwif_color_od_table_tv006_transform(0, od_table_store_target, pTableOut);

	for (x = 0; x < 17; x++) {
		y = x*17;
		printk(KERN_EMERG "OD_table %x : %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",
				x, pTableOut[y+0], pTableOut[y+1], pTableOut[y+2], pTableOut[y+3], pTableOut[y+4], pTableOut[y+5],
				pTableOut[y+6], pTableOut[y+7], pTableOut[y+8], pTableOut[y+9], pTableOut[y+10], pTableOut[y+11],
				pTableOut[y+12], pTableOut[y+13], pTableOut[y+14], pTableOut[y+15], pTableOut[y+16]
			);
	}*/
	memcpy(pTableOut, od_table_store_target, sizeof(od_table_store_target));
}


// 33x33 to 33x33
// row first
// 160825 henry
void fwif_color_od_table_tv006_transform(bool transType, unsigned int *pTableIn, unsigned int *pTableOut)
{
	if (pTableIn == NULL || pTableOut == NULL)
		return;

#define targer2delta 0
#define delta2target 1

	int i, j;
	//short tmp[2][2] = {0};
	unsigned char tmp[2][2] = {0};
	unsigned char tmp_p[2][2] = {0}; // 2's complemnt

	for(i = 0; i < 17; i++)	{
		for(j = 0; j < 17; j++) {

			tmp[0][0] = pTableIn[i*17+j] >> 24;
			tmp[0][1] = (pTableIn[i*17+j] >> 16) & 0xFF;
			tmp[1][0] = (pTableIn[i*17+j] >> 8) & 0xFF;
			tmp[1][1] = (pTableIn[i*17+j]) & 0xFF;

			if(transType == targer2delta) {
				int j2 = j * 2;

				if (j == 15) {
					tmp_p[0][0] = tmp[0][0]-j2*8;
					tmp_p[0][1] = tmp[0][1]-j2*8;
					tmp_p[1][0] = tmp[0][0]-247;
					tmp_p[1][1] = tmp[0][1]-247;
				}
				else if(j == 16) {
					tmp_p[0][0] = tmp[0][0]-255;
					tmp_p[0][1] = tmp[0][1]-255;
					tmp_p[1][0] = tmp_p[0][0];
					tmp_p[1][1] = tmp_p[0][1];
				}
				else {
					//if(tmp[0][0]-j2*8 < 0)
					//	tmp_p[0][0] = ~(-(tmp[0][0]-j2*8));
					//else
						tmp_p[0][0] = tmp[0][0]-j2*8;

					//if(tmp[0][1]-j2*8 < 0)
					//	tmp_p[0][1] = ~(-(tmp[0][1]-j2*8));
					//else
						tmp_p[0][1] = tmp[0][1]-j2*8 ;

					//if(tmp[1][0]-(j2+1)*8 < 0)
						//tmp_p[1][0] = ~(-(tmp[1][0]-(j2+1)*8));
					//else
						tmp_p[1][0] = tmp[1][0]-(j2+1)*8;

					//if(tmp[1][1]-(j2+1)*8 < 0)
					//	tmp_p[1][1] = ~(-(tmp[1][1]-(j2+1)*8));
					//else
						tmp_p[1][1] = tmp[1][1]-(j2+1)*8;

				}
				pTableOut[i*17+j] = (tmp_p[0][0]<<24) +
									(tmp_p[0][1]<<16) +
									(tmp_p[0][0]<<8)  +
									 tmp_p[0][1];
			}



			else if(transType == delta2target) {

			}
		}
	}

}

// 17x17 to 17x17
// cur (col) first
// 170510 henry
void fwif_color_od_table_17x17_transform(bool transType, unsigned char *pTableIn, unsigned int *pTableOut)
{
	if (pTableIn == NULL || pTableOut == NULL)
		return;

#define targer2delta 0
#define delta2target 1

	int i, j;

	unsigned int tmp = 0, tmp_p = 0;

	for(i = 0; i < 17; i++)	{ // y: pre
		for(j = 0; j < 17; j++) { // x: cur

			tmp = pTableIn[i*17+j] & 0xFF;

			if(transType == targer2delta) {

				if(j == 16) {
					tmp_p = tmp - 255;
				}
				else {
					tmp_p = tmp - 16 * j;
				}

				pTableOut[i*17+j] = tmp_p;
			}
			else if(transType == delta2target) {
				// not implemented yet
			}
		}
	}

}


void fwif_color_od_table_restore(void)
{
	extern char od_table_mode_store;
	extern unsigned int od_table_store[OD_table_length];

	if (od_table_mode_store == 1) {// 0:target mode 1:delta mode -1:inverse mode
		fwif_color_od_table_tv006_transform(0, od_table_store, od_delta_table);
		drvif_color_od_table(od_delta_table, 0);// 0:delta mode 1:target mode(output mode)
	}
}





void fwif_color_set_Mplus_ModeChange_TV006(DISP_MLE_MODE_T mode_sel)
{


	/* -------------------------------------------
	b8028c00
	<0> DISP_HIGH_LUM1_MSE_ON	0x101101
	<1> DISP_HIGH_LUM2		0x102001
	<2> DISP_LOW_POWER1 		0x100001
	<3> DISP_MLE_MODE_OFF		default
	<4> DISP_HIGH_LUM1_MSE_OFF	0x101001
	<5> DISP_LOW_POWER2 		0x103001
	<6> DISP_LOW_POWER2_SC_OFF 	default

	------------------------------------------- */
	DRV_Mplus_ModeChange data;


	switch (mode_sel) {

	case DISP_HIGH_LUM1_MSE_ON :
		data.wpr_on = 1;
		data.opc_on = 0;
		data.wse_on = 1;
		data.type_sel = 0;
		data.mode_3d = 0;
		data.test_mode = 0;
		data.mode_sel = 1;
		break;

	case DISP_HIGH_LUM2 :
		data.wpr_on = 1;
		data.opc_on = 0;
		data.wse_on = 0;
		data.type_sel = 0;
		data.mode_3d = 0;
		data.test_mode = 0;
		data.mode_sel = 2;
		break;
	case DISP_LOW_POWER1 :
		data.wpr_on = 1;
		data.opc_on = 0;
		data.wse_on = 0;
		data.type_sel = 0;
		data.mode_3d = 0;
		data.test_mode = 0;
		data.mode_sel = 0;
		break;
	case DISP_MLE_MODE_OFF :
		data.wpr_on = 0;
		data.opc_on = 0;
		data.wse_on = 0;
		data.type_sel = 0;
		data.mode_3d = 0;
		data.test_mode = 0;
		data.mode_sel = 0;
		break;
	case DISP_HIGH_LUM1_MSE_OFF :
		data.wpr_on = 1;
		data.opc_on = 0;
		data.wse_on = 0;
		data.type_sel = 0;
		data.mode_3d = 0;
		data.test_mode = 0;
		data.mode_sel = 1;
		break;
	case  DISP_LOW_POWER2:
		data.wpr_on = 1;
		data.opc_on = 0;
		data.wse_on = 0;
		data.type_sel = 0;
		data.mode_3d = 0;
		data.test_mode = 0;
		data.mode_sel = 3;
		break;
	case DISP_LOW_POWER2_SC_OFF :
		data.wpr_on = 1;
		data.opc_on = 0;
		data.wse_on = 0;
		data.type_sel = 0;
		data.mode_3d = 0;
		data.test_mode = 0;
		data.mode_sel = 3;
		break;
	default :
		data.wpr_on = 0;
		data.opc_on = 0;
		data.wse_on = 0;
		data.type_sel = 0;
		data.mode_3d = 0;
		data.test_mode = 0;
		data.mode_sel = 0;
		break;
	}
	drvif_color_set_Mplus_ModeChange((DRV_Mplus_ModeChange *) &data);
}

//UINT32 pre_Eotf_table32[1025] = {0};
//UINT16 pre_Oetf_table16[1025] = {0};
//UINT8 Eotf_NOT_set = 0;
//UINT8 Oetf_NOT_set = 0;
UINT16 HDR_3DLUT_Compact[HDR_24x24x24_size*3] =  {0};
char fwif_color_set_DM_HDR_3dLUT_24x24x24_16_TV006(void *p)
{
#if 1	/* get hw issue with DMA, use sram in m5*/
	extern UINT16 HDR_3DLUT_Compact[HDR_24x24x24_size*3];
	extern struct semaphore VPQ_DM_3DLUT_Semaphore;

	PQ_HDR_3dLUT_16_PARAM *pParam = (PQ_HDR_3dLUT_16_PARAM *)p;
	unsigned char enable = pParam->c3dLUT_16_enable;
	unsigned short *pArray = pParam->a3dLUT_16_pArray;
	char ret = 0;

	down(&VPQ_DM_3DLUT_Semaphore);

	if (fwif_HDR_compare_3DLUT(p, NEW_24x24x24) != 1) {
		rtd_printk(KERN_INFO, TAG_NAME, "Rtice HDR 3D LUT same\n");
		ret = 1;
	}

	fwif_color_DM2_3D_LUT_BIT_Change(pArray, &HDR_3DLUT_Compact[0], NEW_24x24x24);
	drvif_Set_DM_HDR_3dLUT_24x24x24_16(enable, &HDR_3DLUT_Compact[0]);

	up(&VPQ_DM_3DLUT_Semaphore);
	return ret;

#else
	extern UINT16 HDR_3DLUT_Compact[HDR_24x24x24_size*3];
	extern struct semaphore VPQ_DM_3DLUT_Semaphore;

	PQ_HDR_3dLUT_16_PARAM *pParam = (PQ_HDR_3dLUT_16_PARAM *)p;
	unsigned char enable = pParam->c3dLUT_16_enable;
	unsigned short *pArray = pParam->a3dLUT_16_pArray;
	char ret = 0;

	down(&VPQ_DM_3DLUT_Semaphore);
	if (fwif_HDR_compare_3DLUT(p, NEW_24x24x24) != 1) {
		rtd_printk(KERN_INFO, TAG_NAME, "Rtice HDR 3D LUT same\n");
		ret = 1;
	} else {
		fwif_color_DM2_3D_LUT_BIT_Change(pArray, &HDR_3DLUT_Compact[0], NEW_24x24x24);
		ret = fwif_color_DM2_3D_24x24x24_LUT_Set_By_DMA(enable, &HDR_3DLUT_Compact[0]);
	}
	up(&VPQ_DM_3DLUT_Semaphore);
	return ret;
#endif
}

void fwif_color_set_DM2_EOTF_TV006(UINT32* EOTF_table32)
{
#if 1	/* get hw issue with DMA, use sram in m5*/
	drvif_DM2_EOTF_Enable(1, 1);
	drvif_DM2_Wait_DB_Apply();
	drvif_DM2_EOTF_Set(EOTF_table32, EOTF_table32, EOTF_table32);
#else
	drvif_DM2_EOTF_Enable(1, 1);
	fwif_color_DM2_EOTF_Set_By_DMA(EOTF_table32, EOTF_table32, EOTF_table32);
#endif
}

void fwif_color_set_DM2_OETF_TV006(UINT16* OETF_table16)
{
#if 1	/* get hw issue with DMA, use sram in m5*/
	drvif_DM2_OETF_Enable(1, 1);
	drvif_DM2_Wait_DB_Apply();
	drvif_DM2_OETF_Set(OETF_table16, OETF_table16, OETF_table16);
#else
	drvif_DM2_OETF_Enable(1, 1);
	fwif_color_DM2_OETF_Set_By_DMA(OETF_table16, OETF_table16, OETF_table16);
#endif
}

void hdr_resume()
{
	UINT16 i = 0;
	extern UINT8 pre_HDR_on;
	extern UINT8 pre_HDR_stauts;
	extern unsigned int lastCoef9;

	pre_HDR_on = 0;
	pre_HDR_stauts = 0xff;
	lastCoef9 = 0xffffffff;

#ifdef CONFIG_HDR_SDR_SEAMLESS

	drvif_DM2_OETF_Enable(1, 0);
	drvif_DM2_OETF_Set((unsigned short *)&OETF_LUT_HLG_DEFAULT, (unsigned short *)&OETF_LUT_HLG_DEFAULT, (unsigned short *)&OETF_LUT_HLG_DEFAULT);

	drvif_DM2_EOTF_Enable(1, 0);
	drvif_DM2_EOTF_Set((unsigned int*)&EOTF_LUT_HLG_DEFAULT, (unsigned int*)&EOTF_LUT_HLG_DEFAULT, (unsigned int*)&EOTF_LUT_HLG_DEFAULT);
#endif
}

void fwif_color_set_HDR_TV006()
{
#if 0	/* DMA table should  be ok, don't set again*/
	extern unsigned char g_HDR3DLUTForceWrite;
	if (g_HDR3DLUTForceWrite) {
		extern UINT16 pre_hdr_3dlut[24 * 24 * 24 * 3];
		extern struct semaphore VPQ_DM_3DLUT_Semaphore;
		down(&VPQ_DM_3DLUT_Semaphore);
		drvif_Set_DM_HDR_3dLUT_24x24x24_16(1, pre_hdr_3dlut, TRUE);
		up(&VPQ_DM_3DLUT_Semaphore);
		g_HDR3DLUTForceWrite = 0;
	}

#ifndef CONFIG_HDR_SDR_SEAMLESS

	if (Eotf_NOT_set) {

		drvif_DM2_EOTF_Enable(1, 1);
		drvif_DM2_EOTF_Set(pre_Eotf_table32, pre_Eotf_table32, pre_Eotf_table32);

		Eotf_NOT_set = 0;
	}
	if (Oetf_NOT_set) {
		drvif_DM2_OETF_Enable(1, 1);
		drvif_DM2_OETF_Set(pre_Oetf_table16, pre_Oetf_table16, pre_Oetf_table16);
		Oetf_NOT_set = 0;
	}

#else

	if(PQModeInfo_flag[0] == HAL_VPQ_HDR_MODE_HLG)
	{
		drvif_DM2_EOTF_Enable(1, 1);
		drvif_DM2_OETF_Enable(1, 1);
	}
	else if( PQModeInfo_flag[0] == HAL_VPQ_HDR_MODE_HDR10)
	{
		drvif_DM2_EOTF_Enable(1, 0);
		drvif_DM2_OETF_Enable(1, 0);
	}
#endif
#endif
}

UINT8 fwif_color_get_DM2_HDR_histogram_TV006(UINT32* HDR_info)
{
	drvif_DM2_HDR_RGB_max_Get(HDR_info);
	return drvif_DM2_HDR_histogram_Get(HDR_info + 3);
}

UINT8 fwif_color_get_DM_HDR10_enable_TV006()
{
	return drvif_DM_HDR10_enable_Get();
}


void fwif_color_set_LD_Backlight_Decision_Replace_TV006(KADP_LED_BACKLIGHT_DECISION *LED_DB_LUT_BACKLIGHT_DECISION, DRV_LD_Backlight_Decision *LD_Backlight_Decision)
{
	if (NULL == LED_DB_LUT_BACKLIGHT_DECISION || NULL == LD_Backlight_Decision)
		return;

	LD_Backlight_Decision->ld_maxgain = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_maxgain;
	LD_Backlight_Decision->ld_avegain = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_avegain;
	LD_Backlight_Decision->ld_histshiftbit = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_histshiftbit;
	LD_Backlight_Decision->ld_hist0gain = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_hist0gain;
	LD_Backlight_Decision->ld_hist1gain = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_hist1gain;
	LD_Backlight_Decision->ld_hist2gain = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_hist2gain;
	LD_Backlight_Decision->ld_hist3gain = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_hist3gain;
	LD_Backlight_Decision->ld_hist4gain = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_hist4gain;
	LD_Backlight_Decision->ld_hist5gain = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_hist5gain;
	LD_Backlight_Decision->ld_hist6gain = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_hist6gain;
	LD_Backlight_Decision->ld_hist7gain = LED_DB_LUT_BACKLIGHT_DECISION->hal_ld_hist7gain;

}

void fwif_color_set_LD_Spatial_Filter_Replace_TV006(KADP_LED_SPATIAL_FILTER *LED_DB_LUT_SPATIAL_FILTER, DRV_LD_Spatial_Filter *LD_Spatial_Filter)
{

	if (NULL == LED_DB_LUT_SPATIAL_FILTER || NULL == LD_Spatial_Filter)
		return;


	LD_Spatial_Filter->ld_spatialnewcoef00 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef00;
	LD_Spatial_Filter->ld_spatialnewcoef01 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef01;
	LD_Spatial_Filter->ld_spatialnewcoef02 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef02;
	LD_Spatial_Filter->ld_spatialnewcoef03 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef03;
	LD_Spatial_Filter->ld_spatialnewcoef04 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef04;
	LD_Spatial_Filter->ld_spatialnewcoef10 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef10;
	LD_Spatial_Filter->ld_spatialnewcoef11 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef11;
	LD_Spatial_Filter->ld_spatialnewcoef12 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef12;
	LD_Spatial_Filter->ld_spatialnewcoef13 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef13;
	LD_Spatial_Filter->ld_spatialnewcoef14 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef14;
	LD_Spatial_Filter->ld_spatialnewcoef05 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef05;
	LD_Spatial_Filter->ld_spatialnewcoef15 = LED_DB_LUT_SPATIAL_FILTER->hal_ld_spatialnewcoef15;

}

void fwif_color_set_LD_Temporal_Filter_Replace_TV006(KADP_LED_TEMPORAL_FILTER *LED_DB_LUT_TEMPORAL_FILTER, DRV_LD_Temporal_Filter *LD_Temporal_Filter)
{
	if (NULL == LED_DB_LUT_TEMPORAL_FILTER || NULL == LD_Temporal_Filter)
		return;
	LD_Temporal_Filter->ld_tmp_pos0thd = LED_DB_LUT_TEMPORAL_FILTER->hal_ld_tmp_pos0thd;
	LD_Temporal_Filter->ld_tmp_pos1thd = LED_DB_LUT_TEMPORAL_FILTER->hal_ld_tmp_pos1thd;
	LD_Temporal_Filter->ld_tmp_posmingain = LED_DB_LUT_TEMPORAL_FILTER->hal_ld_tmp_posmingain;
	LD_Temporal_Filter->ld_tmp_posmaxgain = LED_DB_LUT_TEMPORAL_FILTER->hal_ld_tmp_posmaxgain;
	LD_Temporal_Filter->ld_tmp_neg0thd = LED_DB_LUT_TEMPORAL_FILTER->hal_ld_tmp_neg0thd;
	LD_Temporal_Filter->ld_tmp_neg1thd = LED_DB_LUT_TEMPORAL_FILTER->hal_ld_tmp_neg1thd;
	LD_Temporal_Filter->ld_tmp_negmingain = LED_DB_LUT_TEMPORAL_FILTER->hal_ld_tmp_negmingain;
	LD_Temporal_Filter->ld_tmp_negmaxgain = LED_DB_LUT_TEMPORAL_FILTER->hal_ld_tmp_negmaxgain;
	LD_Temporal_Filter->ld_tmp_maxdiff = LED_DB_LUT_TEMPORAL_FILTER->hal_ld_tmp_maxdiff;
	LD_Temporal_Filter->ld_tmp_scenechangegain1 = LED_DB_LUT_TEMPORAL_FILTER->hal_ld_tmp_scenechangegain1;

}
void fwif_color_set_LD_Spatial_Remap_Replace_TV006(KADP_LED_REMAP_CURVE *LED_DB_LUT_REMAP_CURVE, DRV_LD_Spatial_Remap *LD_Spatial_Remap)
{
	if (NULL == LED_DB_LUT_REMAP_CURVE || NULL == LD_Spatial_Remap)
		return;


	LD_Spatial_Remap->ld_spatialremapen = LED_DB_LUT_REMAP_CURVE->hal_ld_spatialremapen;
	memcpy(&(LD_Spatial_Remap->ld_spatialremaptab), &(LED_DB_LUT_REMAP_CURVE->hal_ld_spatialremaptab),sizeof(unsigned short)*65);

}

void fwif_color_set_LD_Data_Compensation_NewMode_2DTable_Replace_TV006(KADP_LED_DATA_COMP *LED_DB_LUT_DATA_COMP, DRV_LD_Data_Compensation_NewMode_2DTable *LD_2DTable)
{
	if (NULL == LED_DB_LUT_DATA_COMP || NULL == LD_2DTable)
		return;

	memcpy(LD_2DTable->ld_comp_2Dtable, LED_DB_LUT_DATA_COMP->hal_ld_comp_2Dtable, sizeof(unsigned int)*17*17);

}



void fwif_color_set_LDSetDBLUT_TV006(KADP_LED_DB_LUT_T *LED_DB_LUT)
{
	if (NULL == LED_DB_LUT)
		return;

	int i = 0;
	unsigned char tbl_idx = 0;

	extern DRV_Local_Dimming_Table Local_Dimming_Table[LD_Table_NUM];
	extern DRV_LD_Data_Compensation_NewMode_2DTable LD_Data_Compensation_NewMode_2DTable[LD_Table_NUM];

	for (i=0;i<LD_Table_NUM;i++) {
		tbl_idx = LED_DB_LUT[i].LD_UI_Index;
		if (tbl_idx >= LD_Table_NUM) {
			break;
		} else {
			fwif_color_set_LD_Backlight_Decision_Replace_TV006(&LED_DB_LUT[tbl_idx].hal_backlight_decision, &Local_Dimming_Table[tbl_idx].LD_Backlight_Decision);
			fwif_color_set_LD_Spatial_Filter_Replace_TV006(&LED_DB_LUT[tbl_idx].hal_spatial_filter, &Local_Dimming_Table[tbl_idx].LD_Spatial_Filter);
			fwif_color_set_LD_Temporal_Filter_Replace_TV006(&LED_DB_LUT[tbl_idx].hal_temporal_filter, &Local_Dimming_Table[tbl_idx].LD_Temporal_Filter);
			fwif_color_set_LD_Spatial_Remap_Replace_TV006(&LED_DB_LUT[tbl_idx].hal_remap_curve, &Local_Dimming_Table[tbl_idx].LD_Spatial_Remap);
			fwif_color_set_LD_Data_Compensation_NewMode_2DTable_Replace_TV006(&LED_DB_LUT[tbl_idx].hal_data_comp_table, &LD_Data_Compensation_NewMode_2DTable[tbl_idx]);
		}
	}


}
void fwif_color_set_PQA_motion_threshold_TV006(void)
{
	unsigned int table_row = 0;
	unsigned char i = 0,j=0,y_ini=0,c_ini=0;
	StructColorDataType *pTable = NULL;
	SLR_VIP_TABLE *shareMem_VIP_Table = NULL;
	UINT8 source=255,pqa_table_idx=0;

	unsigned int PQA_reg_value=0,PQA_bitup_value=0,PQA_bitlow_value=0;
	CHIP_NOISE_REDUCTION_T *pNR_Table =NULL;
	static unsigned char cp_ini=0;
	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);/* get vip source by input src and timing*/
	if (source >= VIP_QUALITY_SOURCE_NUM)
		source = 0;


	pNR_Table = fwif_color_Get_NR_Table_tv006();

	shareMem_VIP_Table = fwif_color_GetShare_Memory_VIP_TABLE_Struct();

	if (pNR_Table == NULL || shareMem_VIP_Table == NULL)
		return;


	pqa_table_idx = shareMem_VIP_Table->VIP_QUALITY_Extend3_Coef[source][VIP_QUALITY_FUNCTION_PQA_Table];

	y_ini=0;
	c_ini=0;

	if(cp_ini==0)
	{
		memcpy(&Ori_PQA_Table,&shareMem_VIP_Table->PQA_Table,sizeof(Ori_PQA_Table));
		cp_ini=1;
	}
	for (table_row = 0; table_row < PQA_ITEM_MAX; table_row++)
	{


#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
		PQA_reg_value = shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row][PQA_reg];
		PQA_bitup_value = shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row][PQA_bitup];
		PQA_bitlow_value = shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row][PQA_bitlow];
#else
		PQA_reg_value = Scaler_ChangeUINT32Endian(shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row][PQA_reg]);
		PQA_bitup_value = Scaler_ChangeUINT32Endian(shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row][PQA_bitup]);
		PQA_bitlow_value = Scaler_ChangeUINT32Endian(shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row][PQA_bitlow]);
#endif

		if((PQA_reg_value == DI_IM_DI_RTNR_Y_16_TH12_TH14_reg)&&(PQA_bitup_value == 23)&&(PQA_bitlow_value == 16)&&(y_ini==0)){
			y_ini=1;
			for(i=0;i<15;i++){
				for(j=0;j<10;j++){
#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT

					if ( vpq_project_id == 0x00060000)
						shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j] =pNR_Table->TNR_Y.Mad[i][j];
					else
						shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j] =Ori_PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j];


#else
					if ( vpq_project_id == 0x00060000)
						shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j] =Scaler_ChangeUINT32Endian(pNR_Table->TNR_Y.Mad[i][j]);
					else
						shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j] =Scaler_ChangeUINT32Endian(Ori_PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j]);
#endif
				}
			}
		}

		if((PQA_reg_value == DI_IM_DI_RTNR_C_TH4_TH6_reg)&&(PQA_bitup_value == 23)&&(PQA_bitlow_value == 16)&&(c_ini==0)){
			c_ini=1;

			for(i=0;i<7;i++){
				for(j=0;j<10;j++){
					if ((table_row+i) < 255) {
#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT

					if ( vpq_project_id == 0x00060000)
						shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j] =pNR_Table->TNR_C.Mad[i][j];
					else
						shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j] =Ori_PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j];


#else
					if ( vpq_project_id == 0x00060000)
						shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j] =Scaler_ChangeUINT32Endian(pNR_Table->TNR_C.Mad[i][j]);
					else
						shareMem_VIP_Table->PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j] =Scaler_ChangeUINT32Endian(Ori_PQA_Table[pqa_table_idx][PQA_MODE_WRITE][table_row+i][PQA_L00+j]);
#endif
					}
				}
			}
		}
	}
}


#define DGA_InRangeMax 1024
#define DGA_OutRangeMax 4096
void fwif_color_set_output_gamma_4CHDGA_TV006 (UINT32 *pRedGammaTable, UINT32 * pGreenGammaTable, UINT32 * pBlueGammaTable, UINT32 * pWhiteGammaTable, UINT16 nTableSize)
{

	#if 0
	unsigned char fmt;
	VIP_Output_InvOutput_Gamma_CTRL_ITEM *prt_CTRL;

	if (value >= Output_InvOutput_Gamma_TBL_MAX) {
		drvif_color_set_output_gamma_format(0, 0, 0, 0);
		return;
	}

	prt_CTRL = &Output_InvOutput_Gamma[value].Output_InvOutput_Gamma_CTRL_ITEM;

	if (prt_CTRL->output_Gamma_En != 1) {
		drvif_color_set_output_gamma_format(0, 0, 0, 0);
		return;
	}

	fmt = drvif_color_Get_RGBW_Mode();

	if (prt_CTRL->output_Location == 1 && (fmt == 1 || fmt == 2))
		fmt = 1;
	else
		fmt = 0;

	#endif

	int i=0;
	int offset = 0;

	if (nTableSize == 256) {

		for (i=0;i<256;i++) {
			OutGamma_4CHDGA_R[i] =(unsigned short) ((*(pRedGammaTable+i) * DGA_OutRangeMax / DGA_InRangeMax));
			OutGamma_4CHDGA_G[i] =(unsigned short) ((*(pGreenGammaTable+i) * DGA_OutRangeMax / DGA_InRangeMax));
			OutGamma_4CHDGA_B[i] =(unsigned short) ((*(pBlueGammaTable+i) * DGA_OutRangeMax / DGA_InRangeMax));
			OutGamma_4CHDGA_W[i] =(unsigned short) ((*(pWhiteGammaTable+i) * DGA_OutRangeMax / DGA_InRangeMax));
		}
		OutGamma_4CHDGA_R[256] = 2*OutGamma_4CHDGA_R[255] - OutGamma_4CHDGA_R[254];
		OutGamma_4CHDGA_G[256] = 2*OutGamma_4CHDGA_G[255] - OutGamma_4CHDGA_G[254];
		OutGamma_4CHDGA_B[256] = 2*OutGamma_4CHDGA_B[255] - OutGamma_4CHDGA_B[254];
		OutGamma_4CHDGA_W[256] = 2*OutGamma_4CHDGA_W[255] - OutGamma_4CHDGA_W[254];

	} else if (nTableSize == 1024){

		for (i=0;i<256;i++) {
			offset = 4*i;
			OutGamma_4CHDGA_R[i] =(unsigned short) ((*(pRedGammaTable+offset) * DGA_OutRangeMax / DGA_InRangeMax));
			OutGamma_4CHDGA_G[i] =(unsigned short) ((*(pGreenGammaTable+offset) * DGA_OutRangeMax / DGA_InRangeMax));
			OutGamma_4CHDGA_B[i] =(unsigned short) ((*(pBlueGammaTable+offset) * DGA_OutRangeMax / DGA_InRangeMax));
			OutGamma_4CHDGA_W[i] =(unsigned short) ((*(pWhiteGammaTable+offset) * DGA_OutRangeMax / DGA_InRangeMax));
			printk("OutGamma_4CHDGA_R[%d]=%d\n", OutGamma_4CHDGA_R[i]);
		}

		OutGamma_4CHDGA_R[256] = (*(pRedGammaTable+1023) * DGA_OutRangeMax / DGA_InRangeMax)*4/3 - (*(pRedGammaTable+(DGA_OutRangeMax / DGA_InRangeMax)*255) * DGA_OutRangeMax / DGA_InRangeMax)/3;
		OutGamma_4CHDGA_G[256] = (*(pGreenGammaTable+1023) * DGA_OutRangeMax / DGA_InRangeMax)*4/3 - (*(pGreenGammaTable+(DGA_OutRangeMax / DGA_InRangeMax)*255) * DGA_OutRangeMax / DGA_InRangeMax)/3;
		OutGamma_4CHDGA_B[256] = (*(pBlueGammaTable+1023) * DGA_OutRangeMax / DGA_InRangeMax)*4/3 - (*(pBlueGammaTable+(DGA_OutRangeMax / DGA_InRangeMax)*255) * DGA_OutRangeMax / DGA_InRangeMax)/3;
		OutGamma_4CHDGA_W[256] = (*(pWhiteGammaTable+1023) * DGA_OutRangeMax / DGA_InRangeMax)*4/3 - (*(pWhiteGammaTable+(DGA_OutRangeMax / DGA_InRangeMax)*255) * DGA_OutRangeMax / DGA_InRangeMax)/3;



	} else {
		return ;
	}


	unsigned char output_Gamma_En;
	unsigned char output_Location;
	unsigned char fmt;

	output_Gamma_En = 1;
	fmt = 1; /*RGBW*/
	output_Location = 1;/*After RGBW*/

	fwif_color_out_gamma_encode_1ch(pRedGammaTable, OutGamma_4CHDGA_R);
	fwif_color_out_gamma_encode_1ch(pGreenGammaTable, OutGamma_4CHDGA_G);
	fwif_color_out_gamma_encode_1ch(pBlueGammaTable, OutGamma_4CHDGA_B);
	fwif_color_out_gamma_encode_1ch(pWhiteGammaTable, OutGamma_4CHDGA_W);


	fwif_color_out_gamma_control_front();

	drvif_color_Out_Gamma_Curve_Write(pRedGammaTable, GAMMA_CHANNEL_R);	/*R*/
	drvif_color_Out_Gamma_Curve_Write(pGreenGammaTable, GAMMA_CHANNEL_G);	/*G*/
	drvif_color_Out_Gamma_Curve_Write(pBlueGammaTable, GAMMA_CHANNEL_B);	/*B*/
	//drvif_color_Out_Gamma_Curve_Write(pWhiteGammaTable, GAMMA_CHANNEL_W);	/*W*/

	fwif_color_out_gamma_control_back();

	//drvif_color_set_output_gamma_format(output_Gamma_En, fmt, output_Location, 0);


}

void fwif_color_set_SetBOERGBWBypass_TV006(unsigned char BOE_EN)
{
	#ifdef MAC5_NO_RGBW
	VIP_RGBW_MODE RGBW_MODE;
	if(BOE_EN == true)
		RGBW_MODE = VIP_RGBW_MODE_DISABLE;
	else
		RGBW_MODE = VIP_RGBW_MODE_HIMAXBOE;

	fwif_color_safe_od_enable(0);/*protection*/
	fwif_color_WaitFor_DEN_STOP_MEMCDTG();
	drvif_color_set_RGBW_Curcuit(RGBW_MODE);
	fwif_color_safe_od_enable(1);/*protection*/
	#endif

}

void fwif_color_SetFrameGainLimit_TV006(unsigned short nFrameGainLimit)
{
	drvif_color_SetFrameGainLimit(nFrameGainLimit);

}
void fwif_color_GetFrameGainLimit_TV006 (unsigned short *nFrameGainLimit)
{
	drvif_color_GetFrameGainLimit(nFrameGainLimit);

}
void fwif_color_SetPixelGainLimit_TV006 (unsigned short nPixelGainLimit)
{
	drvif_color_SetPixelGainLimit(nPixelGainLimit);

}
void fwif_color_GetPixelGainLimit_TV006 (unsigned short *nPixelGainLimit)
{
	drvif_color_GetPixelGainLimit(nPixelGainLimit);

}



void fwif_color_set_LocalContrast_table_TV006(CHIP_LOCAL_CONTRAST_T *param)
{
	StructColorDataType *pTable = NULL;
	unsigned char src_idx= 0,TableIdx=0;
	unsigned char display = 0;
	SLR_VIP_TABLE *gVip_Table = NULL;
	_system_setting_info *VIP_system_info_structure_table = NULL;
	UINT8 source=255;
	DRV_LC_Global_Ctrl data = {0};
	DRV_LC_ToneMapping_Blend Blend;
	DRV_LC_ToneMapping_CurveSelect CurveSelect;
	extern DRV_Local_Contrast_Table Local_Contrast_Table[2];

	Scaler_Get_Display_info(&display, &src_idx);

	VIPprintf("fwif_color_SetDNR		%d\n", level);

	if(param==NULL){
		VIPprintf("~get CHIP_LOCAL_CONTRAST_T table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;

	}
	VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	if (VIP_system_info_structure_table == NULL) {
		VIPprintf("~get VIP_system_info_structure_table Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	/*====================================*/
	gVip_Table = fwif_colo_get_AP_vip_table_gVIP_Table();
	if (gVip_Table == NULL) {
		VIPprintf("~get vipTable Error return, %s->%d, %s~\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}

	/*get pqa table index need check source first. because ap flow or table index will get incorrect table*/
	source = fwif_vip_source_check(3, NOT_BY_DISPLAY);/* get vip source by input src and timing*/
	if (source >= VIP_QUALITY_SOURCE_NUM)
		source = 0;

	TableIdx =1; // lg fixed used table1;

	data.lc_local_sharp_en= Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_local_sharp_en;
	data.lc_tone_mapping_en= Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_tone_mapping_en;
	//data.lc_db_en = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_db_en;
	//data.lc_db_apply = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_db_apply;
	//data.lc_db_read_level = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_db_read_level;
	data.lc_3d_mode = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_3d_mode;
	//data.lc_blk_hnum = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_blk_hnum;
	//data.lc_blk_vnum = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_blk_vnum;
	data.lc_subblk_mode = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_subblk_mode;
	data.lc_gcon_mode = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_gcon_mode;
	data.lc_hist_mode = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_hist_mode;
	data.lc_tenable = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_tenable;
	data.lc_valid = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_valid;
	//data.lc_blk_hsize = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_blk_hsize;
	//data.lc_blk_vsize = Local_Contrast_Table[TableIdx].LC_Global_Ctrl.lc_blk_vsize;
	/* Control by LG DB */
	data.lc_tone_mapping_en = param->LC_Tone_Mapping_En;
	drvif_color_set_LC_Global_Ctrl((DRV_LC_Global_Ctrl*) &data);

	/* Control by LG DB */
	Blend.lc_tmap_slope_unit = param->LC_tmap_slope_unit;
	Blend.lc_tmap_blend_factor = param->LC_tmap_blend_factor;
	drvif_color_set_LC_ToneMapping_Blend((DRV_LC_ToneMapping_Blend*) &Blend);

	fwif_color_set_LC_Backlight_Decision(src_idx, TableIdx);
	fwif_color_set_LC_Spatial_Filter(src_idx, TableIdx);
	fwif_color_set_LC_Temporal_Filter(src_idx, TableIdx);
	fwif_color_set_LC_Backlight_Profile_Interpolation(src_idx, TableIdx);
	fwif_color_set_LC_Demo_Window(src_idx, TableIdx);
	fwif_color_set_LC_Shpnr_Gain1st(src_idx, TableIdx);
	fwif_color_set_LC_Shpnr_Gain2nd(src_idx, TableIdx);
	fwif_color_set_LC_Diff_Ctrl0(src_idx, TableIdx);

	/* Control by LG DB */

	fwif_color_set_LocalContrast_ToneMappingXY_SlopePoint_TV006(param);

	fwif_color_set_LC_Enable(src_idx, param->M_LC_Comp_En);

	/* set H/V block num, calculate*/
	fwif_color_set_LC_Global_Region_Num_Size(src_idx, TableIdx, LC_BLOCK_32x16);

	return;

}

void fwif_color_set_LocalContrast_ToneMappingXY_SlopePoint_TV006(CHIP_LOCAL_CONTRAST_T *param)
{
	static UINT32 delta_grid_X[3][32],delta_Y[256],slope[256];
	UINT8  grid_mode=0,i,j;
 	UINT32 TableIdx =1; //lg fixed table1
	DRV_LC_ToneMapping_Grid0 grid0;
	extern DRV_Local_Contrast_Table Local_Contrast_Table[2];
	DRV_LC_ToneMapping_Grid2 grid2;
	DRV_LC_ToneMapping_CurveSelect CurveSelect;
	lc_lc_tonemapping_blending_RBUS blending;


	blending.regValue = IoReg_Read32(LC_LC_ToneMapping_blending_reg);



	/* Control by LG DB */
	CurveSelect.lc_tmap_curve0_grid = param->LC_tmap_curve_Grid[0];
	CurveSelect.lc_tmap_curve1_grid = param->LC_tmap_curve_Grid[1];
	CurveSelect.lc_tmap_curve2_grid = param->LC_tmap_curve_Grid[2];
	CurveSelect.lc_tmap_curve3_grid = param->LC_tmap_curve_Grid[3];
	CurveSelect.lc_tmap_curve4_grid = param->LC_tmap_curve_Grid[4];
	CurveSelect.lc_tmap_curve5_grid = param->LC_tmap_curve_Grid[5];
	CurveSelect.lc_tmap_curve6_grid = param->LC_tmap_curve_Grid[6];
	CurveSelect.lc_tmap_curve7_grid = param->LC_tmap_curve_Grid[7];

	CurveSelect.lc_tmap_curve0_tone = param->LC_tmap_curve_tone[0];
	CurveSelect.lc_tmap_curve1_tone = param->LC_tmap_curve_tone[1];
	CurveSelect.lc_tmap_curve2_tone = param->LC_tmap_curve_tone[2];
	CurveSelect.lc_tmap_curve3_tone = param->LC_tmap_curve_tone[3];
	CurveSelect.lc_tmap_curve4_tone = param->LC_tmap_curve_tone[4];
	CurveSelect.lc_tmap_curve5_tone = param->LC_tmap_curve_tone[5];
	CurveSelect.lc_tmap_curve6_tone = param->LC_tmap_curve_tone[6];
	CurveSelect.lc_tmap_curve7_tone = param->LC_tmap_curve_tone[7];


	drvif_color_set_LC_ToneMapping_CurveSelect((DRV_LC_ToneMapping_CurveSelect*) &CurveSelect);


	grid0.lc_tmap_g0_th1 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th1;
	delta_grid_X[0][0]= grid0.lc_tmap_g0_th1;
	grid0.lc_tmap_g0_th2 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th2;
	delta_grid_X[0][1]= grid0.lc_tmap_g0_th2 -grid0.lc_tmap_g0_th1;
	grid0.lc_tmap_g0_th3 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th3;
	delta_grid_X[0][2]= grid0.lc_tmap_g0_th3 -grid0.lc_tmap_g0_th2;
	grid0.lc_tmap_g0_th4 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th4;
	delta_grid_X[0][3]= grid0.lc_tmap_g0_th4 -grid0.lc_tmap_g0_th3;
	grid0.lc_tmap_g0_th5 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th5;
	delta_grid_X[0][4]= grid0.lc_tmap_g0_th5 -grid0.lc_tmap_g0_th4;
	grid0.lc_tmap_g0_th6 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th6;
	delta_grid_X[0][5]= grid0.lc_tmap_g0_th6 -grid0.lc_tmap_g0_th5;
	grid0.lc_tmap_g0_th7 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th7;
	delta_grid_X[0][6]= grid0.lc_tmap_g0_th7 -grid0.lc_tmap_g0_th6;
	grid0.lc_tmap_g0_th8 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th8;
	delta_grid_X[0][7]= grid0.lc_tmap_g0_th8 -grid0.lc_tmap_g0_th7;
	grid0.lc_tmap_g0_th9 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th9;
	delta_grid_X[0][8]= grid0.lc_tmap_g0_th9 -grid0.lc_tmap_g0_th8;
	grid0.lc_tmap_g0_th10 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th10;
	delta_grid_X[0][9]= grid0.lc_tmap_g0_th10 -grid0.lc_tmap_g0_th9;
	grid0.lc_tmap_g0_th11 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th11;
	delta_grid_X[0][10]= grid0.lc_tmap_g0_th11 -grid0.lc_tmap_g0_th10;
	grid0.lc_tmap_g0_th12 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th12;
	delta_grid_X[0][11]= grid0.lc_tmap_g0_th12 -grid0.lc_tmap_g0_th11;
	grid0.lc_tmap_g0_th13 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th13;
	delta_grid_X[0][12]= grid0.lc_tmap_g0_th13 -grid0.lc_tmap_g0_th12;
	grid0.lc_tmap_g0_th14 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th14;
	delta_grid_X[0][13]= grid0.lc_tmap_g0_th14 -grid0.lc_tmap_g0_th13;
	grid0.lc_tmap_g0_th15 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th15;
	delta_grid_X[0][14]= grid0.lc_tmap_g0_th15 -grid0.lc_tmap_g0_th14;
	grid0.lc_tmap_g0_th16 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th16;
	delta_grid_X[0][15]= grid0.lc_tmap_g0_th16 -grid0.lc_tmap_g0_th15;
	grid0.lc_tmap_g0_th17 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th17;
	delta_grid_X[0][16]= grid0.lc_tmap_g0_th17 -grid0.lc_tmap_g0_th16;
	grid0.lc_tmap_g0_th18 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th18;
	delta_grid_X[0][17]= grid0.lc_tmap_g0_th18 -grid0.lc_tmap_g0_th17;
	grid0.lc_tmap_g0_th19 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th19;
	delta_grid_X[0][18]= grid0.lc_tmap_g0_th19 -grid0.lc_tmap_g0_th18;
	grid0.lc_tmap_g0_th20 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th20;
	delta_grid_X[0][19]= grid0.lc_tmap_g0_th20 -grid0.lc_tmap_g0_th19;
	grid0.lc_tmap_g0_th21 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th21;
	delta_grid_X[0][20]= grid0.lc_tmap_g0_th21 -grid0.lc_tmap_g0_th20;
	grid0.lc_tmap_g0_th22 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th22;
	delta_grid_X[0][21]= grid0.lc_tmap_g0_th22 -grid0.lc_tmap_g0_th21;
	grid0.lc_tmap_g0_th23 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th23;
	delta_grid_X[0][22]= grid0.lc_tmap_g0_th23 -grid0.lc_tmap_g0_th22;
	grid0.lc_tmap_g0_th24 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th24;
	delta_grid_X[0][23]= grid0.lc_tmap_g0_th24 -grid0.lc_tmap_g0_th23;
	grid0.lc_tmap_g0_th25 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th25;
	delta_grid_X[0][24]= grid0.lc_tmap_g0_th25 -grid0.lc_tmap_g0_th24;
	grid0.lc_tmap_g0_th26 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th26;
	delta_grid_X[0][25]= grid0.lc_tmap_g0_th26 -grid0.lc_tmap_g0_th25;
	grid0.lc_tmap_g0_th27 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th27;
	delta_grid_X[0][26]= grid0.lc_tmap_g0_th27 -grid0.lc_tmap_g0_th26;
	grid0.lc_tmap_g0_th28 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th28;
	delta_grid_X[0][27]= grid0.lc_tmap_g0_th28 -grid0.lc_tmap_g0_th27;
	grid0.lc_tmap_g0_th29 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th29;
	delta_grid_X[0][28]= grid0.lc_tmap_g0_th29 -grid0.lc_tmap_g0_th28;
	grid0.lc_tmap_g0_th30 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th30;
	delta_grid_X[0][29]= grid0.lc_tmap_g0_th30 -grid0.lc_tmap_g0_th29;
	grid0.lc_tmap_g0_th31 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid0.lc_tmap_g0_th31;
	delta_grid_X[0][30]= grid0.lc_tmap_g0_th31 -grid0.lc_tmap_g0_th30;

	delta_grid_X[0][31]= 4095 -grid0.lc_tmap_g0_th31;

	drvif_color_set_LC_ToneMapping_Grid0((DRV_LC_ToneMapping_Grid0*) &grid0);

	grid2.lc_tmap_g2_th1 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th1;
	delta_grid_X[2][0]= grid2.lc_tmap_g2_th1;
	grid2.lc_tmap_g2_th2 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th2;
	delta_grid_X[2][1]= grid2.lc_tmap_g2_th2-grid2.lc_tmap_g2_th1;
	grid2.lc_tmap_g2_th3 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th3;
	delta_grid_X[2][2]= grid2.lc_tmap_g2_th3-grid2.lc_tmap_g2_th2;
	grid2.lc_tmap_g2_th4 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th4;
	delta_grid_X[2][3]= grid2.lc_tmap_g2_th4-grid2.lc_tmap_g2_th3;
	grid2.lc_tmap_g2_th5 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th5;
	delta_grid_X[2][4]= grid2.lc_tmap_g2_th5-grid2.lc_tmap_g2_th4;
	grid2.lc_tmap_g2_th6 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th6;
	delta_grid_X[2][5]= grid2.lc_tmap_g2_th6-grid2.lc_tmap_g2_th5;
	grid2.lc_tmap_g2_th7 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th7;
	delta_grid_X[2][6]= grid2.lc_tmap_g2_th7-grid2.lc_tmap_g2_th6;
	grid2.lc_tmap_g2_th8 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th8;
	delta_grid_X[2][7]= grid2.lc_tmap_g2_th8-grid2.lc_tmap_g2_th7;
	grid2.lc_tmap_g2_th9 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th9;
	delta_grid_X[2][8]= grid2.lc_tmap_g2_th9-grid2.lc_tmap_g2_th8;
	grid2.lc_tmap_g2_th10 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th10;
	delta_grid_X[2][9]= grid2.lc_tmap_g2_th10-grid2.lc_tmap_g2_th9;
	grid2.lc_tmap_g2_th11 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th11;
	delta_grid_X[2][10]= grid2.lc_tmap_g2_th11-grid2.lc_tmap_g2_th10;
	grid2.lc_tmap_g2_th12 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th12;
	delta_grid_X[2][11]= grid2.lc_tmap_g2_th12-grid2.lc_tmap_g2_th11;
	grid2.lc_tmap_g2_th13 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th13;
	delta_grid_X[2][12]= grid2.lc_tmap_g2_th13-grid2.lc_tmap_g2_th12;
	grid2.lc_tmap_g2_th14 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th14;
	delta_grid_X[2][13]= grid2.lc_tmap_g2_th14-grid2.lc_tmap_g2_th13;
	grid2.lc_tmap_g2_th15 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th15;
	delta_grid_X[2][14]= grid2.lc_tmap_g2_th15-grid2.lc_tmap_g2_th14;
	grid2.lc_tmap_g2_th16 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th16;
	delta_grid_X[2][15]= grid2.lc_tmap_g2_th16-grid2.lc_tmap_g2_th15;
	grid2.lc_tmap_g2_th17 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th17;
	delta_grid_X[2][16]= grid2.lc_tmap_g2_th17-grid2.lc_tmap_g2_th16;
	grid2.lc_tmap_g2_th18 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th18;
	delta_grid_X[2][17]= grid2.lc_tmap_g2_th18-grid2.lc_tmap_g2_th17;
	grid2.lc_tmap_g2_th19 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th19;
	delta_grid_X[2][18]= grid2.lc_tmap_g2_th19-grid2.lc_tmap_g2_th18;
	grid2.lc_tmap_g2_th20 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th20;
	delta_grid_X[2][19]= grid2.lc_tmap_g2_th20-grid2.lc_tmap_g2_th19;
	grid2.lc_tmap_g2_th21 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th21;
	delta_grid_X[2][20]= grid2.lc_tmap_g2_th21-grid2.lc_tmap_g2_th20;
	grid2.lc_tmap_g2_th22 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th22;
	delta_grid_X[2][21]= grid2.lc_tmap_g2_th22-grid2.lc_tmap_g2_th21;
	grid2.lc_tmap_g2_th23 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th23;
	delta_grid_X[2][22]= grid2.lc_tmap_g2_th23-grid2.lc_tmap_g2_th22;
	grid2.lc_tmap_g2_th24 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th24;
	delta_grid_X[2][23]= grid2.lc_tmap_g2_th24-grid2.lc_tmap_g2_th23;
	grid2.lc_tmap_g2_th25 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th25;
	delta_grid_X[2][24]= grid2.lc_tmap_g2_th25-grid2.lc_tmap_g2_th24;
	grid2.lc_tmap_g2_th26 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th26;
	delta_grid_X[2][25]= grid2.lc_tmap_g2_th26-grid2.lc_tmap_g2_th25;
	grid2.lc_tmap_g2_th27 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th27;
	delta_grid_X[2][26]= grid2.lc_tmap_g2_th27-grid2.lc_tmap_g2_th26;
	grid2.lc_tmap_g2_th28 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th28;
	delta_grid_X[2][27]= grid2.lc_tmap_g2_th28-grid2.lc_tmap_g2_th27;
	grid2.lc_tmap_g2_th29 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th29;
	delta_grid_X[2][28]= grid2.lc_tmap_g2_th29-grid2.lc_tmap_g2_th28;
	grid2.lc_tmap_g2_th30 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th30;
	delta_grid_X[2][29]= grid2.lc_tmap_g2_th30-grid2.lc_tmap_g2_th29;
	grid2.lc_tmap_g2_th31 = Local_Contrast_Table[TableIdx].LC_ToneMapping_Grid2.lc_tmap_g2_th31;
	delta_grid_X[2][30]= grid2.lc_tmap_g2_th31-grid2.lc_tmap_g2_th30;
	delta_grid_X[2][31]= 4095-grid2.lc_tmap_g2_th31;

	drvif_color_set_LC_ToneMapping_Grid2((DRV_LC_ToneMapping_Grid2*) &grid2);

	for(i=0;i<32;i++)
	{
		if(i==31)
		{
			delta_grid_X[1][i] = 127;
		}
		else
		{

			delta_grid_X[1][i] = 128;
		}
	}

	for(j=0;j<8;j++)
	{
		for(i=0;i<32;i++)
		{
			if(i==31)
				delta_Y[i+(j*32)]= 4095-param->LC_ToneMappingSlopePont_Table[i+(j*32)];
			else
				delta_Y[i+(j*32)]= param->LC_ToneMappingSlopePont_Table[i+1+(j*32)]-param->LC_ToneMappingSlopePont_Table[i+(j*32)];
		}
	}

	for(j=0;j<8;j++)
	{
		if(j==0)
			grid_mode = CurveSelect.lc_tmap_curve0_grid;
		else if (j==1)
			grid_mode = CurveSelect.lc_tmap_curve1_grid;
		else if (j==2)
			grid_mode = CurveSelect.lc_tmap_curve2_grid;
		else if (j==3)
			grid_mode = CurveSelect.lc_tmap_curve3_grid;
		else if (j==4)
			grid_mode = CurveSelect.lc_tmap_curve4_grid;
		else if (j==5)
			grid_mode = CurveSelect.lc_tmap_curve5_grid;
		else if (j==6)
			grid_mode = CurveSelect.lc_tmap_curve6_grid;
		else if (j==7)
			grid_mode = CurveSelect.lc_tmap_curve7_grid;

		for(i=0;i<32;i++)
		{
			if(blending.lc_tmap_slope_unit==0){

				slope[i+(j*32)] = ((16*delta_Y[i+(j*32)]/delta_grid_X[grid_mode][i])<<16)|param->LC_ToneMappingSlopePont_Table[i+(j*32)];

			}else{

				slope[i+(j*32)] = ((32*delta_Y[i+(j*32)]/delta_grid_X[grid_mode][i])<<16)|param->LC_ToneMappingSlopePont_Table[i+(j*32)];

			}

			//printk("\n slope[%d] =%x \n",i,slope[i+(j*32)]);
			//printk("\n ori_slope[%d] =%x \n",i+(j*32),param->LC_ToneMappingSlopePont_Table[i+(j*32)]);
			//printk("\n delta_Y[%d]=%d ",i+(j*32),delta_Y[i+(j*32)]);

		}
	}


	/*for(i=0;i<32;i++)
	{
		printk("\n delta_x0[%d]=%d ",i,delta_grid_X[0][i]);
		printk("\n delta_x1[%d]=%d ",i,delta_grid_X[1][i]);
		printk("\n delta_x2[%d]=%d ",i,delta_grid_X[2][i]);

	}*/

	drvif_color_set_LC_ToneMappingSlopePoint((unsigned int *) &slope[0]);


}

#if 0/* juwen, move to "tc_hdr", elieli */
unsigned short temp_r[66] = {0};
unsigned short temp_g[66] = {0};
unsigned short temp_b[66] = {0};
void fwif_color_TC_Enable(UINT8 En)
{
	fwif_color_set_TC_Enable(0, 1);
	fwif_color_set_TC_Range_Adaptation(0, 0);
	fwif_color_set_TC_L_Compute(0, 0);
	fwif_color_set_TC_T_Compute(0, 0);
	fwif_color_set_TC_M_Compute(0, 0);
	fwif_color_set_TC_Write_D_LUT(0, 1, 2, 3);
	fwif_color_set_TC_Read_D_LUT(temp_r, temp_g, temp_b);

	fwif_color_set_TC_Write_P_LUT(0, 0);
	fwif_color_set_TC_Read_P_LUT(temp_r);
}
#endif

unsigned char  fwif_color_get_black_detection_info_tv006(VIP_BlackDetectionInfo* BlackDetectionInfo)
{

	static unsigned int cnt;
	_clues *smartPic_clue = (_clues *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_SMARTPIC_CLUS);
	unsigned short channel;
	if (smartPic_clue == NULL) {
		VIPprintf("smartPic_clue NULL!!!");
		return FALSE;
	}
	if (BlackDetectionInfo == NULL) {
		VIPprintf("BlackDetectionInfo NULL!!!");
		return FALSE;
	}


	VIP_BlackDetectionInfo tmp;
	memcpy(&(tmp), &(smartPic_clue->BlackDetectionInfo), sizeof(VIP_BlackDetectionInfo));



	fwif_color_ChangeUINT16Endian_Copy((unsigned short*)&(tmp.OriRegion.x), 1, (unsigned short*)&(BlackDetectionInfo->OriRegion.x),0);
	fwif_color_ChangeUINT16Endian_Copy((unsigned short*)&(tmp.OriRegion.y), 1, (unsigned short*)&(BlackDetectionInfo->OriRegion.y),0);
	fwif_color_ChangeUINT16Endian_Copy((unsigned short*)&(tmp.OriRegion.w), 1, (unsigned short*)&(BlackDetectionInfo->OriRegion.w),0);
	fwif_color_ChangeUINT16Endian_Copy((unsigned short*)&(tmp.OriRegion.h), 1, (unsigned short*)&(BlackDetectionInfo->OriRegion.h),0);


	fwif_color_ChangeUINT16Endian_Copy((unsigned short*)&(tmp.ActRegion.x), 1, (unsigned short*)&(BlackDetectionInfo->ActRegion.x),0);
	fwif_color_ChangeUINT16Endian_Copy((unsigned short*)&(tmp.ActRegion.y), 1, (unsigned short*)&(BlackDetectionInfo->ActRegion.y),0);
	fwif_color_ChangeUINT16Endian_Copy((unsigned short*)&(tmp.ActRegion.w), 1, (unsigned short*)&(BlackDetectionInfo->ActRegion.w),0);
	fwif_color_ChangeUINT16Endian_Copy((unsigned short*)&(tmp.ActRegion.h), 1, (unsigned short*)&(BlackDetectionInfo->ActRegion.h),0);




	cnt ++;

	if (tmp.DetectFlag == FALSE)
		return FALSE;

	return TRUE;
}
