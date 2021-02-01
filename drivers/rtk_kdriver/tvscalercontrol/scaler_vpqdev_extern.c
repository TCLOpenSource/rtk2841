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
#include <tvscalercontrol/scaler/scalercolorlib_tv001.h>
#include <tvscalercontrol/scaler/scalercolorlib_tv002.h>
#include <tvscalercontrol/vip/scalerColor.h>
//#include <tvscalercontrol/vip/scalerColor_tv010.h>
#include <tvscalercontrol/vip/viptable.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include <tvscalercontrol/scaler_vpqmemcdev.h>
#include "scaler_vpqdev_extern.h"
#include "scaler_vscdev.h"
#include <tvscalercontrol/vip/pq_rpc.h>
//#include <mach/RPCDriver.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/vip/gibi_od.h>

#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/scalerdrv/scalerip.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/i3ddma/i3ddma_drv.h>
#include <tvscalercontrol/avd/avdctrl.h>
//#include <rbus/rbus_DesignSpec_MISC_GPIOReg.h>
#include <mach/rtk_log.h>
#include <tvscalercontrol/scalerdrv/zoom_smoothtoggle.h>


#define TAG_NAME "VPQEX"

#define malloc(size)        kmalloc(size, GFP_KERNEL)
#define free(addr)          kfree(addr)

static dev_t vpqex_devno;/*vpq device number*/
static struct cdev vpqex_cdev;
unsigned int vpqex_project_id = 0x00060000;
static unsigned char PQ_Dev_Extern_Status = PQ_DEV_EXTERN_NOTHING;
extern struct semaphore ICM_Semaphore;
extern DRV_film_mode film_mode;
unsigned char g_tv002_demo_fun_flag = 0;
unsigned char g_pq_bypass_lv = 255;
extern unsigned char g_picmode_Cinema;
extern unsigned char scalerVIP_access_tv002_style_demo_flag(unsigned char access_mode, unsigned char *pFlag);
extern unsigned char g_srgbForceUpdate2;
extern DRV_film_table_t film_table;
unsigned char cur_src = 0;
extern void fw_scalerip_set_di_size_change_hw_detect(unsigned char enable);
unsigned char GainOffsetWithGamma=0;
unsigned char LAST_GainOffsetWithGamma=0;
unsigned char GammaBlendingFlag=0;
unsigned char ColorSpaceMode=0;
//unsigned char GammaBlendOETF=0;

int vpqex_open(struct inode *inode, struct file *filp)
{
	printk("vpqex_open %d\n", __LINE__);
	return 0;
}

ssize_t  vpqex_read(struct file *filep, char *buffer, size_t count, loff_t *offp)
{
	return 0;
}

ssize_t vpqex_write(struct file *filep, const char *buffer, size_t count, loff_t *offp)
{
	return 0;
}

int vpqex_release(struct inode *inode, struct file *filep)
{
	printk("vpqex_release %d\n", __LINE__);
	return 0;
}

#ifdef CONFIG_PM
static int vpqex_suspend(struct device *p_dev)
{
	return 0;
}

static int vpqex_resume(struct device *p_dev)
{
	fw_scalerip_set_di_size_change_hw_detect(TRUE);
	return 0;
}
#endif

void vpqex_boot_init(void)
{
	fw_scalerip_set_di_size_change_hw_detect(TRUE);
}

bool vpqex_skip_middle_ware_picmode_data(unsigned int cmd)
{
	switch(cmd) {
		case VPQ_EXTERN_IOC_SET_PIC_MODE_DATA:
		case VPQ_EXTERN_IOC_SET_PIC_MODE_DATA_defaultPictureModeSet:
		case VPQ_EXTERN_IOC_SET_PIC_MODE_DATA_DolbyHDRPictureModeSet:
		case VPQ_EXTERN_IOC_SET_StructColorDataType:
		case VPQ_EXTERN_IOC_SET_StructColorDataType_defaultSDColorData:
		case VPQ_EXTERN_IOC_SET_StructColorDataType_defaultHDColorData:
		case VPQ_EXTERN_IOC_SET_COLOR_TEMP_DATA:
		case VPQ_EXTERN_IOC_SET_COLOR_TEMP_DATA_defColorTempSet:
		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType:
		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_defaultColorFacMode:
		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_AvColorFacMode:
		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_YppColorFacMode:
		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_VgaColorFacMode:
		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_HdmiColorFacMode:
		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_HdmiSDColorFacMode:
			return true;
	}
	return false;
}

long vpqex_ioctl(struct file *file, unsigned int cmd,  unsigned long arg)
{
	int ret = 0, i, j;
	static unsigned int argsmemcLD = 1;

//	if (vpqex_ioctl_get_stop_run(cmd))
//		return 0;

//	if (vpqex_project_id != 0x00060000) {
//		if (VPQ_EXTERN_IOC_INIT == cmd) {
//			vpqex_project_id = 0x00060000;
//			vpqex_boot_init();
//		} else {
//			return -1;
//		}
//	}

//	printk("vpqex_ioctl %d\n", __LINE__);

	if (VPQ_EXTERN_IOC_INIT == cmd) {
		vpqex_project_id = 0x00010000;
		Scaler_color_Set_HDR_AutoRun(TRUE);
		return 0;
	} else if (VPQ_EXTERN_IOC_UNINIT == cmd) {
		PQ_Dev_Extern_Status = PQ_DEV_EXTERN_UNINIT;
		return 0;
	} else if (VPQ_EXTERN_IOC_OPEN == cmd || VPQ_EXTERN_IOC_CLOSE == cmd) {
		return 0;
	}

//	if (PQ_Dev_Extern_Status != PQ_DEV_EXTERN_INIT_DONE)
//		return -1;

//	printk("vpqex_ioctl %d\n", __LINE__);

	if (fwif_color_get_pq_demo_flag_rpc())
		return 0;

#ifndef SEND_VIP_MIDDLE_WARE_PIC_MODE_DATA
	if (vpqex_skip_middle_ware_picmode_data(cmd))
		return 0;
#endif

	switch (cmd) {
	/*
	case VPQ_EXTERN_IOC_INIT:
		if (PQ_DEV_EXTERN_UNINIT == PQ_Dev_Extern_Status || PQ_DEV_EXTERN_NOTHING == PQ_Dev_Extern_Status) {
			fwif_color_inv_gamma_control_back(SLR_MAIN_DISPLAY, 1);
			fwif_color_gamma_control_back(SLR_MAIN_DISPLAY, 1);
			PQ_Dev_Extern_Status = PQ_DEV_EXTERN_INIT_DONE;
		} else
			return -1;
		break;

	case VPQ_EXTERN_IOC_UNINIT:
		if (PQ_DEV_EXTERN_CLOSE == PQ_Dev_Extern_Status || PQ_DEV_EXTERN_INIT_DONE == PQ_Dev_Extern_Status) {
			PQ_Dev_Extern_Status = PQ_DEV_EXTERN_UNINIT;
		} else
			return -1;
		break;

	case VPQ_EXTERN_IOC_OPEN:
		if (PQ_DEV_EXTERN_CLOSE == PQ_Dev_Extern_Status || PQ_DEV_EXTERN_INIT_DONE == PQ_Dev_Extern_Status) {
			PQ_Dev_Extern_Status = PQ_DEV_EXTERN_OPEN_DONE;
		} else
			return -1;
		break;

	case VPQ_EXTERN_IOC_CLOSE:
		if (PQ_DEV_EXTERN_OPEN_DONE == PQ_Dev_Extern_Status) {
			PQ_Dev_Extern_Status = PQ_DEV_EXTERN_CLOSE;
		} else
			 return -1;
		break;
	*/

/************************************************************************
 *  TV010 External variables
 ************************************************************************/
 		case VPQ_EXTERN_IOC_REGISTER_NEW_VIPTABLE:
		{
			ret = xRegisterTable();
			if (ret) {
				ret = 0;
				printk("viptable xRegisterTable success\n");
			}
			else {
				ret = -1;
				printk("viptable xRegisterTable fail\n");
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_VGA_ADCGainOffset:
		{
			extern ADCGainOffset m_vgaGainOffset;
			if (copy_from_user(&m_vgaGainOffset, (int __user *)arg, sizeof(ADCGainOffset))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_VGA_ADCGainOffset fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_VGA_ADCGainOffset success\n");
				ret = 0;
				#if 1
				printk("m_vgaGainOffset={\n");
				printk("%x %x %x ", m_vgaGainOffset.Gain_R, m_vgaGainOffset.Gain_G, m_vgaGainOffset.Gain_B);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_YPBPR_ADCGainOffset:
		{
			extern ADCGainOffset m_yPbPrGainOffsetData[SR_MAX_YPBPR_GAINOFFSET_MODE] ;
			if (copy_from_user(&m_yPbPrGainOffsetData, (int __user *)arg, sizeof(m_yPbPrGainOffsetData))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_YPBPR_ADCGainOffset fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_YPBPR_ADCGainOffset success, sizeof(m_yPbPrGainOffsetData)=%d\n", sizeof(m_yPbPrGainOffsetData));
				ret = 0;
				#if 1
				printk("m_yPbPrGainOffsetData[16]={\n");
				for (i=0; i<SR_MAX_YPBPR_GAINOFFSET_MODE; i++) {
					//for (j=0; j<VIP_QUALITY_FUNCTION_TOTAL_CHECK; j++) {
						printk("%x %x %x ", m_yPbPrGainOffsetData[i].Gain_R, m_yPbPrGainOffsetData[i].Gain_G, m_yPbPrGainOffsetData[i].Gain_B);
					//}
					printk("\n");
				}
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_SLR_VIP_TABLE_CUSTOM_TV001:
		{
			extern void* m_pVipTableCustom; /* SLR_VIP_TABLE_CUSTOM_TV001  */

			if (copy_from_user((SLR_VIP_TABLE_CUSTOM_TV001*)m_pVipTableCustom, (int __user *)arg, sizeof(SLR_VIP_TABLE_CUSTOM_TV001))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_SLR_VIP_TABLE_CUSTOM_TV001 fail\n");
				ret = -1;
				break;
			} else {
				SLR_VIP_TABLE_CUSTOM_TV001* tmp_pVipTableCustom = (SLR_VIP_TABLE_CUSTOM_TV001*)m_pVipTableCustom;
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_SLR_VIP_TABLE_CUSTOM_TV001 success\n");
				ret = 0;
				#if 1
				printk("m_pVipTableCustom->InitParam[16]={\n");
				for (i=0; i<16; i++) {
					//for (j=0; j<VIP_QUALITY_FUNCTION_TOTAL_CHECK; j++) {
						printk("%x ", tmp_pVipTableCustom->InitParam[i]);
					//}
					//printk("\n");
				}
				printk("} end\n");

				printk("m_pVipTableCustom->DCR_TABLE[][][]={\n");
				for (i=0; i<DCR_TABLE_ROW_NUM; i++) {
					for (j=0; j<DCR_TABLE_COL_NUM; j++) {
						printk("%x ", tmp_pVipTableCustom->DCR_TABLE[New_DCR_TABLE_NUM-1][i][j]);
					}
					printk("\n");
				}
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_SLR_VIP_TABLE:
		{
			printk("%s %d\n", __FUNCTION__, __LINE__);

			extern SLR_VIP_TABLE* m_pVipTable;
			extern DRV_Local_Contrast_Table Local_Contrast_Table[LC_Table_NUM];
			extern unsigned int LC_Backlight_Profile_Interpolation_table[LC_Table_NUM][LC_H_and_V][LC_Backlight_Profile_Interpolation_table_num];
			extern unsigned int LC_ToneMappingSlopePoint_Table[LC_Table_ToneM_NUM][LC_Curve_ToneM_PointSlope];
			#if 0
				printk("original m_defaultVipTable.VIP_QUALITY_Coef[][]={\n");
				for (i=0; i<3; i++) {
					for (j=0; j<VIP_QUALITY_FUNCTION_TOTAL_CHECK; j++) {
						printk("%x ", m_defaultVipTable.VIP_QUALITY_Coef[i][j]);
					}
					printk("\n");
				}
				printk("} end\n");

				printk("m_defaultVipTable.DrvSetting_Skip_Flag[]={\n");
				for (i=0; i<DrvSetting_Skip_Flag_item_Max; i++) {
					//for (j=0; j<VIP_QUALITY_FUNCTION_TOTAL_CHECK; j++) {
						printk("%x ", m_defaultVipTable.DrvSetting_Skip_Flag[i]);
					//}
					//printk("\n");
				}
				printk("} end\n");
			#endif
			if (copy_from_user(m_pVipTable, (int __user *)arg, sizeof(SLR_VIP_TABLE))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy SLR_VIP_TABLE fail\n");
				printk("%s %d\n", __FUNCTION__, __LINE__);

				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy SLR_VIP_TABLE success\n");
				printk("%s %d\n", __FUNCTION__, __LINE__);
				ret = 0;


				#if 1
				printk("m_pVipTable->VIP_QUALITY_Coef[][]={\n");
				for (i=0; i<3; i++) {
					for (j=0; j<VIP_QUALITY_Coef_MAX; j++) {
						printk("%x ", m_pVipTable->VIP_QUALITY_Coef[i][j]);
					}
					printk("\n");
				}
				printk("} end\n");

				printk("m_pVipTable->DrvSetting_Skip_Flag[]={\n");
				for (i=0; i<DrvSetting_Skip_Flag_item_Max; i++) {
					//for (j=0; j<VIP_QUALITY_FUNCTION_TOTAL_CHECK; j++) {
						printk("%x ", m_pVipTable->DrvSetting_Skip_Flag[i]);
					//}
					//printk("\n");
				}
				printk("} end\n");
				#endif

				//write value to pq_misc_table
				memcpy(&Local_Contrast_Table, &m_pVipTable->Local_Contrast_Table, sizeof(DRV_Local_Contrast_Table) * LC_Table_NUM);
				memcpy(&LC_Backlight_Profile_Interpolation_table, &m_pVipTable->LC_Backlight_Profile_Interpolation_table, sizeof(unsigned int) * LC_Table_NUM*LC_H_and_V*LC_Backlight_Profile_Interpolation_table_num);
				memcpy(&LC_ToneMappingSlopePoint_Table, &m_pVipTable->LC_ToneMappingSlopePoint_Table, sizeof(unsigned int) * LC_Table_ToneM_NUM*LC_Curve_ToneM_PointSlope);
			}
		}
		printk("%s %d\n", __FUNCTION__, __LINE__);
		break;

		case VPQ_EXTERN_IOC_SET_PIC_MODE_DATA:
		{
			extern PIC_MODE_DATA*  m_picModeTable;
			if (copy_from_user(m_picModeTable, (int __user *)arg, sizeof(PIC_MODE_DATA))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_PIC_MODE_DATA fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_PIC_MODE_DATA success\n");
				ret = 0;
				#if 1
				printk("m_picModeTable={\n");
				printk("%x %x %x \n", m_picModeTable->picMode[PICTURE_MODE_USER].Brightness, m_picModeTable->picMode[PICTURE_MODE_USER].Contrast, m_picModeTable->picMode[PICTURE_MODE_USER].Saturation);
				printk("%x %x %x \n", m_picModeTable->picMode[PICTURE_MODE_VIVID].Brightness, m_picModeTable->picMode[PICTURE_MODE_VIVID].Contrast, m_picModeTable->picMode[PICTURE_MODE_VIVID].Saturation);
				printk("%x %x %x \n", m_picModeTable->picMode[PICTURE_MODE_STD].Brightness, m_picModeTable->picMode[PICTURE_MODE_STD].Contrast, m_picModeTable->picMode[PICTURE_MODE_STD].Saturation);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_PIC_MODE_DATA_defaultPictureModeSet:
		{
			extern SLR_PICTURE_MODE_DATA  m_defaultPictureModeSet[];
			if (copy_from_user(&m_defaultPictureModeSet, (int __user *)arg, sizeof(SLR_PICTURE_MODE_DATA)*7)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_PIC_MODE_DATA_defaultPictureModeSet fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_PIC_MODE_DATA_defaultPictureModeSet success\n");
				ret = 0;
				#if 1
				printk("m_defaultPictureModeSet={\n");
				printk("%x %x %x \n", m_defaultPictureModeSet[PICTURE_MODE_USER].Brightness, m_defaultPictureModeSet[PICTURE_MODE_USER].Contrast, m_defaultPictureModeSet[PICTURE_MODE_USER].Saturation);
				printk("%x %x %x \n", m_defaultPictureModeSet[PICTURE_MODE_VIVID].Brightness, m_defaultPictureModeSet[PICTURE_MODE_VIVID].Contrast, m_defaultPictureModeSet[PICTURE_MODE_VIVID].Saturation);
				printk("%x %x %x \n", m_defaultPictureModeSet[PICTURE_MODE_GAME].Brightness, m_defaultPictureModeSet[PICTURE_MODE_GAME].Contrast, m_defaultPictureModeSet[PICTURE_MODE_GAME].Saturation);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_PIC_MODE_DATA_DolbyHDRPictureModeSet:
		{
			extern SLR_PICTURE_MODE_DATA  m_DolbyHDRPictureModeSet[];
			if (copy_from_user(&m_DolbyHDRPictureModeSet, (int __user *)arg, sizeof(SLR_PICTURE_MODE_DATA)*7)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_PIC_MODE_DATA_DolbyHDRPictureModeSet fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_PIC_MODE_DATA_DolbyHDRPictureModeSet success\n");
				ret = 0;
				#if 1
				printk("m_DolbyHDRPictureModeSet={\n");
				printk("%x %x %x \n", m_DolbyHDRPictureModeSet[PICTURE_MODE_USER].Brightness, m_DolbyHDRPictureModeSet[PICTURE_MODE_USER].Contrast, m_DolbyHDRPictureModeSet[PICTURE_MODE_USER].Saturation);
				printk("%x %x %x \n", m_DolbyHDRPictureModeSet[PICTURE_MODE_VIVID].Brightness, m_DolbyHDRPictureModeSet[PICTURE_MODE_VIVID].Contrast, m_DolbyHDRPictureModeSet[PICTURE_MODE_VIVID].Saturation);
				printk("%x %x %x \n", m_DolbyHDRPictureModeSet[PICTURE_MODE_STD].Brightness, m_DolbyHDRPictureModeSet[PICTURE_MODE_STD].Contrast, m_DolbyHDRPictureModeSet[PICTURE_MODE_STD].Saturation);
				printk("} end\n");
				#endif
			}
		}
		break;




		case VPQ_EXTERN_IOC_SET_StructColorDataType:
		{
			extern StructColorDataType*  m_colorDataTable;
			if (copy_from_user(m_colorDataTable, (int __user *)arg, sizeof(StructColorDataType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataType fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataType success\n");
				ret = 0;
				#if 1
				printk("m_colorDataTable={\n");
				printk("%x %x %x ", m_colorDataTable->MBPeaking, m_colorDataTable->Intensity, m_colorDataTable->Gamma);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_StructColorDataType_defaultSDColorData:
		{
			extern StructColorDataType  m_defaultSDColorData;
			if (copy_from_user(&m_defaultSDColorData, (int __user *)arg, sizeof(StructColorDataType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataType_defaultSDColorData fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataType_defaultSDColorData success\n");
				ret = 0;
				#if 1
				printk("m_defaultSDColorData={\n");
				printk("%x %x %x ", m_defaultSDColorData.MBPeaking, m_defaultSDColorData.Intensity, m_defaultSDColorData.Gamma);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_StructColorDataType_defaultHDColorData:
		{
			extern StructColorDataType  m_defaultHDColorData;
			if (copy_from_user(&m_defaultHDColorData, (int __user *)arg, sizeof(StructColorDataType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataType_defaultHDColorData fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataType_defaultHDColorData success\n");
				ret = 0;
				#if 1
				printk("m_defaultHDColorData={\n");
				printk("%x %x %x ", m_defaultHDColorData.MBPeaking, m_defaultHDColorData.Intensity, m_defaultHDColorData.Gamma);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_COLOR_TEMP_DATA:
		{
			extern COLOR_TEMP_DATA*  m_colorTempData;
			if (copy_from_user(m_colorTempData, (int __user *)arg, sizeof(COLOR_TEMP_DATA))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_COLOR_TEMP_DATA fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_COLOR_TEMP_DATA success\n");
				ret = 0;
				#if 1
				printk("m_colorTempData={\n");
				printk("%x %x %x \n", m_colorTempData->colorTempData[SLR_COLORTEMP_USER].R_val, m_colorTempData->colorTempData[SLR_COLORTEMP_USER].G_val, m_colorTempData->colorTempData[SLR_COLORTEMP_USER].B_val);
				printk("%x %x %x \n", m_colorTempData->colorTempData[SLR_COLORTEMP_NORMAL].R_val, m_colorTempData->colorTempData[SLR_COLORTEMP_NORMAL].G_val, m_colorTempData->colorTempData[SLR_COLORTEMP_NORMAL].B_val);
				printk("%x %x %x \n", m_colorTempData->colorTempData[SLR_COLORTEMP_WARMER].R_val, m_colorTempData->colorTempData[SLR_COLORTEMP_WARMER].G_val, m_colorTempData->colorTempData[SLR_COLORTEMP_WARMER].B_val);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_COLOR_TEMP_DATA_defColorTempSet:
		{
			extern SLR_COLORTEMP_DATA  m_defColorTempSet[];
			if (copy_from_user(&m_defColorTempSet, (int __user *)arg, sizeof(SLR_COLORTEMP_DATA)*SLR_COLORTEMP_MAX_NUM)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_COLOR_TEMP_DATA_defColorTempSet fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_COLOR_TEMP_DATA_defColorTempSet success\n");
				ret = 0;
				#if 1
				printk("m_defColorTempSet={\n");
				printk("%x %x %x \n", m_defColorTempSet[SLR_COLORTEMP_USER].R_val, m_defColorTempSet[SLR_COLORTEMP_USER].G_val, m_defColorTempSet[SLR_COLORTEMP_USER].B_val);
				printk("%x %x %x \n", m_defColorTempSet[SLR_COLORTEMP_NORMAL].R_val, m_defColorTempSet[SLR_COLORTEMP_NORMAL].G_val, m_defColorTempSet[SLR_COLORTEMP_NORMAL].B_val);
				printk("%x %x %x \n", m_defColorTempSet[SLR_COLORTEMP_WARMER].R_val, m_defColorTempSet[SLR_COLORTEMP_WARMER].G_val, m_defColorTempSet[SLR_COLORTEMP_WARMER].B_val);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType:
		{
			extern StructColorDataFacModeType* m_colorFacModeTable;
			if (copy_from_user(m_colorFacModeTable, (int __user *)arg, sizeof(StructColorDataFacModeType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType success\n");
				ret = 0;
				#if 1
				printk("m_colorFacModeTable={\n");
				printk("%x %x %x ", m_colorFacModeTable->Brightness_0, m_colorFacModeTable->Brightness_50, m_colorFacModeTable->Brightness_100);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_defaultColorFacMode:
		{
			extern StructColorDataFacModeType m_defaultColorFacMode;
			if (copy_from_user(&m_defaultColorFacMode, (int __user *)arg, sizeof(StructColorDataFacModeType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_defaultColorFacMode fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_defaultColorFacMode success\n");
				ret = 0;
				#if 1
				printk("m_defaultColorFacMode={\n");
				printk("%x %x %x ", m_defaultColorFacMode.Brightness_0, m_defaultColorFacMode.Brightness_50, m_defaultColorFacMode.Brightness_100);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_AvColorFacMode:
		{
			extern StructColorDataFacModeType m_AvColorFacMode;
			if (copy_from_user(&m_AvColorFacMode, (int __user *)arg, sizeof(StructColorDataFacModeType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_AvColorFacMode fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_AvColorFacMode success\n");
				ret = 0;
				#if 1
				printk("m_AvColorFacMode={\n");
				printk("%x %x %x ", m_AvColorFacMode.Brightness_0, m_AvColorFacMode.Brightness_50, m_AvColorFacMode.Brightness_100);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_YppColorFacMode:
		{
			extern StructColorDataFacModeType m_YppColorFacMode;
			if (copy_from_user(&m_YppColorFacMode, (int __user *)arg, sizeof(StructColorDataFacModeType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_YppColorFacMode fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_YppColorFacMode success\n");
				ret = 0;
				#if 1
				printk("m_YppColorFacMode={\n");
				printk("%x %x %x ", m_YppColorFacMode.Brightness_0, m_YppColorFacMode.Brightness_50, m_YppColorFacMode.Brightness_100);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_VgaColorFacMode:
		{
			extern StructColorDataFacModeType m_VgaColorFacMode;
			if (copy_from_user(&m_VgaColorFacMode, (int __user *)arg, sizeof(StructColorDataFacModeType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_VgaColorFacMode fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_VgaColorFacMode success\n");
				ret = 0;
				#if 1
				printk("m_VgaColorFacMode={\n");
				printk("%x %x %x ", m_VgaColorFacMode.Brightness_0, m_VgaColorFacMode.Brightness_50, m_VgaColorFacMode.Brightness_100);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_HdmiColorFacMode:
		{
			extern StructColorDataFacModeType m_HdmiColorFacMode;
			if (copy_from_user(&m_HdmiColorFacMode, (int __user *)arg, sizeof(StructColorDataFacModeType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_HdmiColorFacMode fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_HdmiColorFacMode success\n");
				ret = 0;
				#if 1
				printk("m_HdmiColorFacMode={\n");
				printk("%x %x %x ", m_HdmiColorFacMode.Brightness_0, m_HdmiColorFacMode.Brightness_50, m_HdmiColorFacMode.Brightness_100);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_HdmiSDColorFacMode:
		{
			extern StructColorDataFacModeType m_HdmiSDColorFacMode;
			if (copy_from_user(&m_HdmiSDColorFacMode, (int __user *)arg, sizeof(StructColorDataFacModeType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_HdmiSDColorFacMode fail\n");
				ret = -1;
				break;
			} else {
				rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacModeType_HdmiSDColorFacMode success\n");
				ret = 0;
				#if 1
				printk("m_HdmiSDColorFacMode={\n");
				printk("%x %x %x ", m_HdmiSDColorFacMode.Brightness_0, m_HdmiSDColorFacMode.Brightness_50, m_HdmiSDColorFacMode.Brightness_100);
				printk("} end\n");
				#endif
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_CUR_SRC_FMT:
		{
			printk("VPQ_EXTERN_IOC_GET_CUR_SRC_FMT\n");
			UINT32 srcfmt = 0;
			srcfmt = Scaler_InputSrcFormat(Scaler_color_get_pq_src_idx());
			if (copy_to_user((void __user *)arg, (void *)&srcfmt, sizeof(UINT32))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_CUR_SRC_FMT2 fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_GET_VIP_SRC_TIMING:
		{
			//printk("VPQ_EXTERN_IOC_GET_VIP_SRC_TIMING\n");
			unsigned int vipsource = 0;
			vipsource = fwif_vip_source_check(3, NOT_BY_DISPLAY);
			if (copy_to_user((void __user *)arg, (void *)&vipsource, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_VIP_SRC_TIMING fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_SET_StructColorDataFacMode_EXTERN:
		{
			extern unsigned char g_bUseMiddleWareOSDmap; //for Driver Base MiddleWare OSD map
			extern StructColorDataFacModeType g_curColorFacTableEx; //for Driver Base MiddleWare OSD map

			if (copy_from_user(&g_curColorFacTableEx, (void __user *)arg, sizeof(StructColorDataFacModeType))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacMode_EXTERN fail\n");
				ret = -1;
				break;
			} else {
				//rtd_printk(KERN_DEBUG, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_SET_StructColorDataFacMode_EXTERN success\n");
				g_bUseMiddleWareOSDmap = 1;
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_VIP_SRC_RESYNC:
		{
			unsigned int vip_src_resync = 0;
			vip_src_resync = Scaler_Get_VIP_src_resync_flag();
			if (copy_to_user((void __user *)arg, (void *)&vip_src_resync, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_VIP_SRC_RESYNC fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_VIP_SRC_RESYNC:
		{
			Scaler_Set_PicMode_VIP_src(fwif_vip_source_check(3, NOT_BY_DISPLAY));
		}
		break;

		case VPQ_EXTERN_IOC_SET_VIP_SET_VIP_HANDLER_RESET:
		{
			rtd_printk(KERN_INFO, TAG_NAME, "VPQ_EXTERN_IOC_SET_VIP_SET_VIP_HANDLER_RESET\n");
			ret = Scaler_Set_VIP_HANDLER_RESET();
			if (ret) {
				ret = 0;
				printk("Scaler_Set_VIP_HANDLER_RESET success\n");
			}
			else {
				ret = -1;
				printk("Scaler_Set_VIP_HANDLER_RESET fail\n");
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_BRIGHTNESS:
		{
			#ifndef  CONFIG_CUSTOMER_TV030
			printk("VPQ_EXTERN_IOC_GET_BRIGHTNESS\n");
			#endif
			unsigned int brightness = 0;
			brightness = (unsigned int)Scaler_GetBrightness();
			if (copy_to_user((void __user *)arg, (void *)&brightness, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_BRIGHTNESS fail\n");
				ret = -1;
			} else
				ret = 0;

		}
		break;
		case VPQ_EXTERN_IOC_SET_BRIGHTNESS:
		{
						#ifndef  CONFIG_CUSTOMER_TV030
						printk("VPQ_EXTERN_IOC_SET_BRIGHTNESS\n");
						#endif
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {
				ret = -1;
			} else {
				ret = 0;
				Scaler_SetBrightness((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_CONTRAST:
		{	
			#ifndef  CONFIG_CUSTOMER_TV030
			printk("VPQ_EXTERN_IOC_GET_CONTRAST\n");
			#endif
			unsigned int contrast = 0;
			contrast = (unsigned int)Scaler_GetContrast();
			if (copy_to_user((void __user *)arg, (void *)&contrast, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_CONTRAST fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;
		case VPQ_EXTERN_IOC_SET_CONTRAST:
		{
						#ifndef  CONFIG_CUSTOMER_TV030
						printk(KERN_DEBUG "VPQ_EXTERN_IOC_SET_CONTRAST\n");
						#endif
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetContrast((unsigned char)args);
			}
			#ifndef  CONFIG_CUSTOMER_TV030
			printk(KERN_DEBUG "VPQ_EXTERN_IOC_SET_CONTRAST = %d\n",args);
			#endif
		}
		break;
		case VPQ_EXTERN_IOC_GET_SATURATION:
		{
									#ifndef  CONFIG_CUSTOMER_TV030
									printk("VPQ_EXTERN_IOC_GET_SATURATION\n");
									#endif
			unsigned int saturation = 0;
			saturation = (unsigned int)Scaler_GetSaturation();
			if (copy_to_user((void __user *)arg, (void *)&saturation, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_SATURATION fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;
		case VPQ_EXTERN_IOC_SET_SATURATION:
		{
			#ifndef  CONFIG_CUSTOMER_TV030
				printk("VPQ_EXTERN_IOC_SET_SATURATION\n");
			#endif
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetSaturation((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_HUE:
		{						

			#ifndef  CONFIG_CUSTOMER_TV030
			printk("VPQ_EXTERN_IOC_GET_HUE\n");
			#endif
			unsigned int hue = 0;
			hue = (unsigned int)Scaler_GetHue();
			if (copy_to_user((void __user *)arg, (void *)&hue, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_HUE fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_SET_HUE:
		{
			#ifndef  CONFIG_CUSTOMER_TV030
			printk("VPQ_EXTERN_IOC_SET_HUE\n");
			#endif
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetHue((unsigned char)args);
			}
		}
		break;
		
		case VPQ_EXTERN_IOC_SET_OSDPIC_FLAG_TV030://flag
		{
			RTK_VIP_Flag pFlag;
			SCALER_DISPLAY_DATA sdp_data;
			if (copy_from_user(&pFlag,  (int __user *)arg,sizeof(RTK_VIP_Flag))) {
				printk("[kernel]set VPQ_EXTERN_IOC_SET_OSDPIC_FLAG_TV030 fail\n");
				ret = -1;
			} else {

				sdp_data.h_sta = pFlag.flag_2;
				sdp_data.h_end = pFlag.flag_3;
				sdp_data.v_sta = pFlag.flag_4;
				sdp_data.v_end = pFlag.flag_5;
				Scaler_Set_Partten4AutoGamma_mute(pFlag.flag_0,pFlag.flag_1,&sdp_data);

				LAST_GainOffsetWithGamma = GainOffsetWithGamma;
				//yuan::add for test
				if(pFlag.flag_6==1)//rgb gain :enable
				{
					GainOffsetWithGamma=0;
				}
				else{
					GainOffsetWithGamma=1;
				}
				//printk("yuan,[falg]GainOffsetWithGamma=%d\n",GainOffsetWithGamma);
				
				ret = 0;
			}
		}
		break;
		
		case VPQ_EXTERN_IOC_GET_NR:
		{
			#ifndef  CONFIG_CUSTOMER_TV030
			printk("VPQ_EXTERN_IOC_GET_NR\n");
			#endif
			unsigned int nr = 0;
			nr = (unsigned int)Scaler_GetDNR();
			if (copy_to_user((void __user *)arg, (void *)&nr, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_NR fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;
		case VPQ_EXTERN_IOC_SET_NR:
		{
			#ifndef  CONFIG_CUSTOMER_TV030
			printk("VPQ_EXTERN_IOC_SET_NR\n");
			#endif
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetDNR((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_SHARPNESS:
		{
			#ifndef  CONFIG_CUSTOMER_TV030
			printk("VPQ_EXTERN_IOC_GET_SHARPNESS\n");
			#endif
			unsigned int sharpness = 0;
			sharpness = (unsigned int)Scaler_GetSharpness();
			if (copy_to_user((void __user *)arg, (void *)&sharpness, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_SHARPNESS fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;
		case VPQ_EXTERN_IOC_SET_SHARPNESS_EXTERN:
		{
			printk("VPQ_EXTERN_IOC_SET_SHARPNESS_EXTERN\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetSharpness((unsigned char)args);
				Scaler_SetCDSTable_by_Sharpness((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_DE_BLOCKING:
		{
			printk("VPQ_EXTERN_IOC_GET_DE_BLOCKING\n");
			TV010_LEVEL_E dbLevel = 0;
			dbLevel = (TV010_LEVEL_E)Scaler_GetMPEGNR();
			if (copy_to_user((void __user *)arg, (void *)&dbLevel, sizeof(TV010_LEVEL_E))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_DE_BLOCKING fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;
		case VPQ_EXTERN_IOC_SET_DE_BLOCKING:
		{
			printk("VPQ_EXTERN_IOC_SET_DE_BLOCKING\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetMPEGNR((unsigned char)args,0);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_DE_RINGING:
		{
			printk("VPQ_EXTERN_IOC_GET_DE_RINGING\n");
			TV010_LEVEL_E drLevel = 0;

			if (Scaler_GetDeRinging_level(&drLevel) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetDeRinging_level fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&drLevel, sizeof(TV010_LEVEL_E))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_DE_RINGING fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_DE_RINGING:
		{
			printk("VPQ_EXTERN_IOC_SET_DE_RINGING\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetDeRinging_level((TV010_LEVEL_E)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_COLOR_TEMP:
		{
			printk("VPQ_EXTERN_IOC_GET_COLOR_TEMP\n");
			TV010_COLORTEMP_E colorTemp = 0;

			if (Scaler_GetColorTemp_level_type(&colorTemp) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetColorTemp_level_type fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&colorTemp, sizeof(TV010_COLORTEMP_E))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_COLOR_TEMP fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_COLOR_TEMP_EXTERN:
		{
			printk(KERN_EMERG "VPQ_EXTERN_IOC_SET_COLOR_TEMP_EXTERN\n");
			TV010_COLOR_TEMP_DATA_S args;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(TV010_COLOR_TEMP_DATA_S))) {

				ret = -1;
			} else {
					Scaler_SetColorTempData((TV010_COLOR_TEMP_DATA_S*) &args);

					//printk("yuan,[color temp]\n");	
					//printk("yuan,GainOffsetWithGamma=%d\n",GainOffsetWithGamma);	

					if(GainOffsetWithGamma==1){
					con_bri_dm_color_rgb_ctrl_RBUS	dm_color_rgb_ctrl_REG;
					dm_color_rgb_ctrl_REG.regValue =  IoReg_Read32(CON_BRI_DM_COLOR_RGB_CTRL_reg);
					dm_color_rgb_ctrl_REG.m_con_en = 0;
					dm_color_rgb_ctrl_REG.m_bri_en = 0;
					IoReg_Write32(CON_BRI_DM_COLOR_RGB_CTRL_reg, dm_color_rgb_ctrl_REG.regValue);
					fwif_color_set_gamma_Magic();
				}else{
					if(LAST_GainOffsetWithGamma == 0)
						fwif_color_set_gamma_Magic();
					
					con_bri_dm_color_rgb_ctrl_RBUS	dm_color_rgb_ctrl_REG;
					dm_color_rgb_ctrl_REG.regValue =  IoReg_Read32(CON_BRI_DM_COLOR_RGB_CTRL_reg);
					dm_color_rgb_ctrl_REG.m_con_en = 1;
					dm_color_rgb_ctrl_REG.m_bri_en = 1;
					IoReg_Write32(CON_BRI_DM_COLOR_RGB_CTRL_reg, dm_color_rgb_ctrl_REG.regValue);
				}
				ret = 0;					
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_COLOR_GAIN:
		{
			printk("VPQ_EXTERN_IOC_GET_COLOR_GAIN\n");
			TV010_LEVEL_E colorGain = 0;

			if (Scaler_GetColorGainLevel(&colorGain) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetColorGainLevel fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&colorGain, sizeof(TV010_LEVEL_E))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_COLOR_GAIN fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_COLOR_GAIN_EXTERN:
		{
			printk("VPQ_EXTERN_IOC_SET_COLOR_GAIN_EXTERN\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				//Scaler_SetColorGainLevel(args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_FLESH_TONE:
		{
			printk("VPQ_EXTERN_IOC_GET_FLESH_TONE\n");
			TV010_LEVEL_E fleshtone = 0;

			if (Scaler_GetFleshToneLevel(&fleshtone) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetFleshToneLevel fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&fleshtone, sizeof(TV010_LEVEL_E))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_FLESH_TONE fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_FLESH_TONE:
		{
			printk("VPQ_EXTERN_IOC_SET_FLESH_TONE\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				//Scaler_SetFleshToneLevel((TV010_LEVEL_E)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_BACKLIGHT:
		{
			printk("VPQ_EXTERN_IOC_GET_BACKLIGHT\n");
			unsigned int backlight = 0;
			backlight = (unsigned int)Scaler_GetBacklight();
			if (copy_to_user((void __user *)arg, (void *)&backlight, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_BACKLIGHT fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;
		case VPQ_EXTERN_IOC_SET_BACKLIGHT:
		{
			printk(KERN_NOTICE "VPQ_EXTERN_IOC_SET_BACKLIGHT\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetBackLight((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_PANEL_BL:
		{
			printk("VPQ_EXTERN_IOC_SET_PANEL_BL\n");
		}
		break;
		case VPQ_EXTERN_IOC_GET_GAMMA_NUM:
		{
			printk("VPQ_EXTERN_IOC_GET_GAMMA_NUM\n");
			unsigned int number = 0;

			if (Scaler_GetGammaNum(&number) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetGammaNum fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&number, sizeof(unsigned int))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_GAMMA_NUM fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_GAMMA:
		{
			printk("VPQ_EXTERN_IOC_SET_GAMMA\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetGamma((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_PQ_MODULE:
		{
			printk("VPQ_EXTERN_IOC_GET_PQ_MODULE\n");
			RTK_PQModule_T PQModule_T;
			if (copy_from_user(&PQModule_T,  (int __user *)arg,sizeof(RTK_PQModule_T))) {

				ret = -1;
			} else {
				ret = 0;
				if (Scaler_GetPQModule((TV010_PQ_MODULE_E) PQModule_T.PQModule,(unsigned char *) &PQModule_T.onOff) == FALSE) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetPQModule fail\n");
					ret = -1;
				} else {
					if (copy_to_user((void __user *)arg, (void *)&PQModule_T, sizeof(RTK_PQModule_T))) {
						rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_MODULE fail\n");
						ret = -1;
					} else
						ret = 0;
				}
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_PQ_MODULE:
		{
			printk("VPQ_EXTERN_IOC_SET_PQ_MODULE\n");
			RTK_PQModule_T PQModule_T;
			//unsigned int args = 0;
			if (copy_from_user(&PQModule_T,  (int __user *)arg,sizeof(RTK_PQModule_T))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetPQModule((TV010_PQ_MODULE_E) PQModule_T.PQModule,(unsigned char)PQModule_T.onOff);
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_DEMO:
		{
			printk("VPQ_EXTERN_IOC_SET_DEMO\n");
			RTK_DEMO_MODE_T DEMO_MODE_T;
			//unsigned int args = 0;
			if (copy_from_user(&DEMO_MODE_T,  (int __user *)arg,sizeof(RTK_DEMO_MODE_T))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetDemoMode((TV010_DEMO_MODE_E) DEMO_MODE_T.DEMO_MODE,(unsigned char)DEMO_MODE_T.onOff);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_DEBUG_MODE:
		{
			printk("VPQ_EXTERN_IOC_GET_DEBUG_MODE\n");
		}
		break;
		case VPQ_EXTERN_IOC_SET_DEBUG_MODE:
		{
			printk("VPQ_EXTERN_IOC_SET_DEBUG_MODE\n");
		}
		break;
		case VPQ_EXTERN_IOC_GET_HISTOGRAM:
		{

			UINT32 HistoData_bin[TV006_VPQ_chrm_bin];

			if (fwif_color_get_HistoData_Countbins(TV006_VPQ_chrm_bin, &(HistoData_bin[0])) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_Countbins fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&HistoData_bin[0], sizeof(HistoData_bin))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_Countbins fail\n");
					ret = -1;
				} else
					ret = 0;
			}

		}
		break;
		case VPQ_EXTERN_IOC_GET_SR_LEVEL:
		{
			printk("VPQ_EXTERN_IOC_GET_SR_LEVEL\n");
			TV010_LEVEL_E srLevel = 0;

			if (Scaler_GetSRLevel(&srLevel) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetSRLevel fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&srLevel, sizeof(TV010_LEVEL_E))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_SR_LEVEL fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_SR_LEVEL:
		{
			printk("VPQ_EXTERN_IOC_SET_SR_LEVEL\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetSRLevel((TV010_DEMOLEVEL_E)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_BLACK_PATTERN_OUTPUT:
		{
			printk("VPQ_EXTERN_IOC_SET_BLACK_PATTERN_OUTPUT\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetBlackPatternOutput((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_WHITE_PATTERN_OUTPUT:
		{
			printk("VPQ_EXTERN_IOC_SET_WHITE_PATTERN_OUTPUT\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetWhitePatternOutput((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_OD_LEVEL:
		{
			printk("VPQ_EXTERN_IOC_GET_OD_LEVEL\n");
			unsigned int level = 0;

			if (Scaler_GetODLevel(&level) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetODLevel fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&level, sizeof(unsigned int))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_OD_LEVEL fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_OD_READ_ENABLE:
		{
			printk("VPQ_EXTERN_IOC_SET_OD_READ_ENABLE\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetODReadEnable((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_SRC_HDR_INFO:
		{
			printk("VPQ_EXTERN_IOC_GET_SRC_HDR_INFO\n");
			unsigned int GammaType = 0;

			if (Scaler_GetSrcHdrInfo(&GammaType) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetSrcHdrInfo fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&GammaType, sizeof(unsigned int))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_SRC_HDR_INFO fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_SDR2HDR:
		{
			printk("VPQ_EXTERN_IOC_GET_SDR2HDR\n");
			unsigned char onoff = 0;

			if (Scaler_GetSDR2HDR(&onoff) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetSDR2HDR fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&onoff, sizeof(unsigned char))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_SDR2HDR fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_SDR2HDR:
		{
			printk("VPQ_EXTERN_IOC_SET_SDR2HDR\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetSDR2HDR((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_HDR_TYPE:
		{
			//printk("VPQ_EXTERN_IOC_GET_HDR_TYPE\n");
			TV010_HDR_TYPE_E HdrType = 0;

			if (Scaler_GetHdrType(&HdrType) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetHdrType fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&HdrType, sizeof(unsigned int))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_HDR_TYPE fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_DCI_TYPE:
		{
			printk("VPQ_EXTERN_IOC_SET_DCI_TYPE\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetDCC_Table((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_DOLBY_HDR_PIC_MODE:
		{
			printk("VPQ_EXTERN_IOC_GET_DOLBY_HDR_PIC_MODE\n");
		}
		break;
		case VPQ_EXTERN_IOC_SET_DOLBY_HDR_PIC_MODE:
		{
			printk("VPQ_EXTERN_IOC_SET_DOLBY_HDR_PIC_MODE\n");
		}
		break;


		case VPQ_EXTERN_IOC_GET_HDR10_ENABLE:
		{
			printk("VPQ_EXTERN_IOC_GET_HDR10_ENABLE\n");
			unsigned char bEnable = 0;

			if (Scaler_GetHdr10Enable(&bEnable) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetHdr10Enable fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&bEnable, sizeof(unsigned char))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_HDR10_ENABLE fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_HDR10_ENABLE:
		{
			printk("VPQ_EXTERN_IOC_SET_HDR10_ENABLE\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetHdr10Enable((unsigned char)args);
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_DOLBYHDR_ENABLE:
		{
			printk("VPQ_EXTERN_IOC_GET_HDR10_ENABLE\n");
			unsigned char bEnable = 0;

			if (Scaler_GetDOLBYHDREnable(&bEnable) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetDOLBYHDREnable fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&bEnable, sizeof(unsigned char))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_DOLBYHDR_ENABLE fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_DOLBYHDR_ENABLE:
		{
			printk("VPQ_EXTERN_IOC_SET_DOLBYHDR_ENABLE\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetDOLBYHDREnable((unsigned char)args);
			}
		}
		break;


		case VPQ_EXTERN_IOC_SET_DREAM_PANEL_LOG_ENABLE:
		{
			printk("VPQ_EXTERN_IOC_SET_DREAM_PANEL_LOG_ENABLE\n");
		}
		break;
		case VPQ_EXTERN_IOC_GET_DREAM_PANEL_BACKLIGHT:
		{
			printk("VPQ_EXTERN_IOC_GET_DREAM_PANEL_BACKLIGHT\n");
		}
		break;
		case VPQ_EXTERN_IOC_SET_DREAM_PANEL_BACKLIGHT:
		{
			printk("VPQ_EXTERN_IOC_SET_DREAM_PANEL_BACKLIGHT\n");
		}
		break;
		case VPQ_EXTERN_IOC_GET_DCC_MODE:
		{
			unsigned int dcc_mode = 0;
			dcc_mode = (unsigned int)Scaler_GetDCC_Mode();
			if (copy_to_user((void __user *)arg, (void *)&dcc_mode, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_DCC_MODE fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;
		case VPQ_EXTERN_IOC_SET_DCC_MODE:
		{
			unsigned int dcc_mode = 0;
			if (copy_from_user(&dcc_mode,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				Scaler_SetDCC_Mode(dcc_mode&0xff);
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_ICM_TBL_IDX:
		{
			unsigned int icm_table_idx = 0;
			icm_table_idx = Scaler_GetICMTable();
			if (copy_to_user((void __user *)arg, (void *)&icm_table_idx, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_ICM_TBL_IDX fail\n");
				ret = -1;
			} else
				ret = 0;

		}
		break;
		case VPQ_EXTERN_IOC_SET_ICM_TBL_IDX:
		{
			unsigned int icm_table_idx = 0;
			if (copy_from_user(&icm_table_idx,  (int __user *)arg,sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_ICM_TBL_IDX fail\n");
				ret = -1;
			} else {
				Scaler_SetICMTable(icm_table_idx&0xff);
				ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_FILM_MODE:
		{
			unsigned int film_mode_enable;
			film_mode_enable = film_mode.film_status?1:0;
			if (copy_to_user((void __user *)arg, (void *)&film_mode_enable, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_FILM_MODE fail\n");
				ret = -1;
			} else
				ret = 0;

		}
		break;
		case VPQ_EXTERN_IOC_SET_FILM_MODE:
		{
			unsigned int film_mode_enable = 0;
			if (copy_from_user(&film_mode_enable,  (int __user *)arg,sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_FILM_MODE fail\n");
				ret = -1;
			} else {
				film_mode.film_status = film_mode_enable?28:0;
				down(get_DI_semaphore());
				drvif_module_film_mode((DRV_film_mode *) &film_mode);
				up(get_DI_semaphore());
				ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_GET_HDMI_CSC_DATA_RANGE_MODE:
		{
			HDMI_CSC_DATA_RANGE_MODE_T range_mode = Scaler_GetHDMI_CSC_DataRange_Mode();
			if (copy_to_user((void __user *)arg, (void *)&range_mode, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_HDMI_CSC_DATA_RANGE_MODE fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;
		case VPQ_EXTERN_IOC_SET_HDMI_CSC_DATA_RANGE_MODE:
		{
			unsigned int range_mode = 0;
			if (copy_from_user(&range_mode,  (int __user *)arg,sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_FILM_MODE fail\n");
				ret = -1;
			} else {
				Scaler_SetHDMI_CSC_DataRange_Mode((HDMI_CSC_DATA_RANGE_MODE_T)range_mode);
				Scaler_SetDataFormatHandler();
				ret = 0;
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_HDR_FORCE_MODE:
		{
			unsigned int hdr_force_mode = 0;
			if (copy_from_user(&hdr_force_mode,  (int __user *)arg,sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_HDR_FORCE_MODE fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_CINEMA_PIC_MODE:
		{
			unsigned int cinema_pic_mode = 0;
			if (copy_from_user(&cinema_pic_mode,  (int __user *)arg,sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_CINEMA_PIC_MODE fail\n");
				ret = -1;
			} else {
				Scaler_Set_CinemaMode_PQ(cinema_pic_mode);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_PQ_BYPASS_LV:
		{
			unsigned int pq_bypass_lv = 0;
			if (copy_from_user(&pq_bypass_lv,  (int __user *)arg,sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_PQ_BYPASS_LV fail\n");
				ret = -1;
			} else {
				g_pq_bypass_lv = pq_bypass_lv;
				if (pq_bypass_lv < VIP_PQ_ByPass_TBL_Max)
					Scaler_color_Set_PQ_ByPass_Lv(pq_bypass_lv);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_PQ_SOURCE_TYPE:
		{
			unsigned int pq_source_from_ap = 0;
			if (copy_from_user(&pq_source_from_ap,  (int __user *)arg,sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_PQ_BYPASS_LV fail\n");
				ret = -1;
			} else {
				fwif_color_set_PQ_SOURCE_TYPE_From_AP((unsigned char)pq_source_from_ap);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_ENGMENU:
		{
			printk("VPQ_EXTERN_IOC_GET_PQ_Engineer_menu\n");
			HAL_VPQ_ENG_STRUCT* ENGMENU = NULL;
			ENGMENU = Scaler_Get_ENGMENU();
			if (copy_to_user((void __user *)arg, (void *)ENGMENU, sizeof(HAL_VPQ_ENG_STRUCT))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_Engineer_menu fail\n");
				ret = -1;
			} else
				ret = 0;

		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_ENGMENU_size:
		{
			printk("VPQ_EXTERN_IOC_GET_PQ_Engineer_menu_size\n");
			HAL_VPQ_ENG_SIZE* ENGMENU_size = NULL;
			ENGMENU_size = Scaler_Get_ENGMENU_size();
			if (copy_to_user((void __user *)arg, (void *)ENGMENU_size, sizeof(HAL_VPQ_ENG_SIZE))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_Engineer_menu_size fail\n");
				ret = -1;
			} else
				ret = 0;

		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_ENGMENU_item:
		{
			printk("VPQ_EXTERN_IOC_GET_PQ_Engineer_menu\n");
			HAL_VPQ_ENG_STRUCT* ENGMENU = NULL;
			ENGMENU = Scaler_Get_ENGMENU();
			if (copy_to_user((void __user *)arg, (ENGMENU->item), sizeof(HAL_VPQ_ENG_ITEM_STRUCT)*HAL_VPQ_ENG_ITEM_MAX_NUM)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_Engineer_menu fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_ENGMENU_ID:
		{
			printk("VPQ_EXTERN_IOC_GET_PQ_Engineer_menu\n");
			HAL_VPQ_ENG_STRUCT* ENGMENU = NULL;
			ENGMENU = Scaler_Get_ENGMENU();
			if (copy_to_user((void __user *)arg, (ENGMENU->ID), sizeof(HAL_VPQ_ENG_ID_STRUCT)*HAL_VPQ_ENG_ID_MAX_NUM)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_Engineer_menu fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_ENG_ID:
		{
			HAL_VPQ_ENG_ID ENG_ID;
			if (copy_from_user(&ENG_ID,  (int __user *)arg,sizeof(HAL_VPQ_ENG_ID))) {
				ret = -1;
			} else {
				ret = 0;
				ENG_ID.ID_value= Scaler_Get_ENGMENU_ID((unsigned int)ENG_ID.ID);
			}
			printk("VPQ_EXTERN_IOC_GET_PQ_ENG_ID\n");
			if (copy_to_user((void __user *)arg, (void *)(&ENG_ID), sizeof(HAL_VPQ_ENG_ID))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_ENG_ID fail\n");
				ret = -1;
			} else
				ret = 0;

		}
		break;

		case VPQ_EXTERN_IOC_SET_PQ_ENG_ID:
		{
			HAL_VPQ_ENG_ID ENG_ID;
			if (copy_from_user(&ENG_ID,  (int __user *)arg,sizeof(HAL_VPQ_ENG_ID))) {
				ret = -1;
			} else {
				ret = 0;
				Scaler_Set_ENGMENU_ID(ENG_ID.ID, ENG_ID.ID_value);
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_ENG_TWOLAYER_MENU_item:
		{
			printk("VPQ_EXTERN_IOC_GET_PQ_Engineer_TWOLAYER_menu\n");
			HAL_VPQ_ENG_TWOLAYER_STRUCT* ENG_TWOLAYER_MENU = NULL;
			ENG_TWOLAYER_MENU = Scaler_Get_ENG_TWOLAYER_MENU();
			if (copy_to_user((void __user *)arg, (ENG_TWOLAYER_MENU->item), sizeof(HAL_VPQ_ENG_ITEM_TWOLAYER_STRUCT)*HAL_VPQ_ENG_ITEM_MAX_NUM)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_Engineer_menu fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_ENG_TWOLAYER_MENU_ID:
		{
			printk("VPQ_EXTERN_IOC_GET_PQ_Engineer_TWOLAYER_menu\n");
			HAL_VPQ_ENG_TWOLAYER_STRUCT* ENG_TWOLAYER_MENU = NULL;
			ENG_TWOLAYER_MENU = Scaler_Get_ENG_TWOLAYER_MENU();
			if (copy_to_user((void __user *)arg, (ENG_TWOLAYER_MENU->ID), sizeof(HAL_VPQ_ENG_ID_STRUCT)*HAL_VPQ_ENG_ID_MAX_NUM)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_Engineer_TWOLAYER_menu fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_ENG_TWOLAYER_ID:
		{
			HAL_VPQ_ENG_TWOLAYER_ID ENG_TWOLAYER_ID;
			if (copy_from_user(&ENG_TWOLAYER_ID,  (int __user *)arg,sizeof(HAL_VPQ_ENG_TWOLAYER_ID))) {
				ret = -1;
			} else {
				ret = 0;
				ENG_TWOLAYER_ID.ID_value= Scaler_Get_ENG_TWOLAYER_MENU_ID((unsigned int)ENG_TWOLAYER_ID.ITEM,(unsigned int)ENG_TWOLAYER_ID.ID);
			}
			printk("VPQ_EXTERN_IOC_GET_PQ_TWOLAYER_ENG_ID\n");
			if (copy_to_user((void __user *)arg, (void *)(&ENG_TWOLAYER_ID), sizeof(HAL_VPQ_ENG_TWOLAYER_ID))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_ENG_TWOLAYER_ID fail\n");
				ret = -1;
			} else
				ret = 0;

		}
		break;

		case VPQ_EXTERN_IOC_SET_PQ_ENG_TWOLAYER_ID:
		{
			HAL_VPQ_ENG_TWOLAYER_ID ENG_TWOLAYER_ID;
			if (copy_from_user(&ENG_TWOLAYER_ID,  (int __user *)arg,sizeof(HAL_VPQ_ENG_TWOLAYER_ID))) {
				ret = -1;
			} else {
				ret = 0;
				Scaler_Set_ENG_TWOLAYER_MENU_ID(ENG_TWOLAYER_ID.ITEM,ENG_TWOLAYER_ID.ID, ENG_TWOLAYER_ID.ID_value);
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_DEBUG_BUFF_8:
		{
			printk("VPQ_EXTERN_IOC_GET_PQ_DEBUG_BUFF_8\n");
			_system_setting_info *VIP_system_info_structure_table = NULL;
			VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
			if (copy_to_user((void __user *)arg, (VIP_system_info_structure_table->Debug_Buff_8), sizeof(char)*Debug_Buff_Num)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_DEBUG_BUFF_8 fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_DEBUG_BUFF_16:
		{
			printk("VPQ_EXTERN_IOC_GET_PQ_DEBUG_BUFF_16\n");
			_system_setting_info *VIP_system_info_structure_table = NULL;
			VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
			if (copy_to_user((void __user *)arg, (VIP_system_info_structure_table->Debug_Buff_16), sizeof(short)*Debug_Buff_Num)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_DEBUG_BUFF_16 fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_GET_PQ_DEBUG_BUFF_32:
		{
			printk("VPQ_EXTERN_IOC_GET_PQ_DEBUG_BUFF_32\n");
			_system_setting_info *VIP_system_info_structure_table = NULL;
			VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
			if (copy_to_user((void __user *)arg, (VIP_system_info_structure_table->Debug_Buff_32), sizeof(int)*Debug_Buff_Num)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PQ_DEBUG_BUFF_32 fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_SET_PQ_DEBUG_BUFF_8:
		{
			_system_setting_info *VIP_system_info_structure_table = NULL;
			VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
			printk("VPQ_EXTERN_IOC_SET_PQ_DEBUG_BUFF_8\n");
			if (copy_from_user(&VIP_system_info_structure_table->Debug_Buff_8,  (int __user *)arg,sizeof(char)*Debug_Buff_Num)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_PQ_DEBUG_BUFF_8 fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_PQ_DEBUG_BUFF_16:
		{
			_system_setting_info *VIP_system_info_structure_table = NULL;
			VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
			printk("VPQ_EXTERN_IOC_SET_PQ_DEBUG_BUFF_16\n");
			if (copy_from_user(&VIP_system_info_structure_table->Debug_Buff_16,  (int __user *)arg,sizeof(short)*Debug_Buff_Num)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_PQ_DEBUG_BUFF_16 fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_PQ_DEBUG_BUFF_32:
		{
			_system_setting_info *VIP_system_info_structure_table = NULL;
			VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
			printk("VPQ_EXTERN_IOC_SET_PQ_DEBUG_BUFF_32\n");

			if (copy_from_user(&VIP_system_info_structure_table->Debug_Buff_32,  (int __user *)arg,sizeof(int)*Debug_Buff_Num)) {
				rtd_printk(KERN_ERR, TAG_NAME, "in kernel VPQ_EXTERN_IOC_SET_PQ_DEBUG_BUFF_32 fail\n");
				ret = -1;

			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_EXT_FUN_EN:
		{
			unsigned int iEn;
			if (copy_from_user(&iEn,  (void __user *)arg,sizeof(unsigned int))) {
				ret = -1;
			} else {
				g_tv002_demo_fun_flag = iEn&0xff;
				scalerVIP_access_tv002_style_demo_flag(1, &g_tv002_demo_fun_flag);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_BLE:
		{
			int level;
			if (copy_from_user(&level,  (void __user *)arg,sizeof(int))) {
				ret = -1;
			} else {
				Scaler_set_BLE(level&0xff);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_SGAMMA:
		{
			int level;
			if (copy_from_user(&level,  (void __user *)arg,sizeof(int))) {
				ret = -1;
			} else {
				Scaler_set_sGamma(level&0xff);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_MAGIC_GAMMA:
		{
			VIP_MAGIC_GAMMA_Curve_Driver_Data data;
			extern VIP_MAGIC_GAMMA_Curve_Driver_Data g_MagicGammaDriverDataSave;

			if (copy_from_user(&data,  (void __user *)arg,sizeof(VIP_MAGIC_GAMMA_Curve_Driver_Data))) {
				ret = -1;
			} else {
				memcpy(&g_MagicGammaDriverDataSave, &data, sizeof(VIP_MAGIC_GAMMA_Curve_Driver_Data));
				fwif_color_set_gamma_from_MagicGamma_MiddleWare();
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_TV002_SR:
		{
			RTK_TV002_SR_T data;
			data.mode = Scaler_get_Clarity_RealityCreation();
			data.value = Scaler_get_Clarity_Resolution();
			if (copy_to_user((void __user *)arg, (void *)&data, sizeof(RTK_TV002_SR_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_TV002_SR fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_SR:
		{
			RTK_TV002_SR_T data;
			if (copy_from_user(&data,  (void __user *)arg,sizeof(RTK_TV002_SR_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_SR fail\n");
				ret = -1;
			} else {
				Scaler_set_Clarity_RealityCreation(data.mode);
				Scaler_set_Clarity_Resolution(data.value);
				fwif_color_set_clarity_resolution();
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_TV002_LIVE_COLOUR:
		{
			unsigned int live_colour = Scaler_get_LiveColor();
			if (copy_to_user((void __user *)arg, (void *)&live_colour, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_TV002_LIVE_COLOUR fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_LIVE_COLOUR:
		{
			unsigned int live_colour;
			if (copy_from_user(&live_colour,  (void __user *)arg,sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_LIVE_COLOUR fail\n");
				ret = -1;
			} else {
				Scaler_set_LiveColor(live_colour);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_TV002_MASTERED_4K:
		{
			unsigned int mastered_4k = Scaler_get_Clarity_Mastered4K();
			if (copy_to_user((void __user *)arg, (void *)&mastered_4k, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_TV002_MASTERED_4K fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_MASTERED_4K:
		{
			unsigned int mastered_4k;
			if (copy_from_user(&mastered_4k, (void __user *)arg, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_MASTERED_4K fail\n");
				ret = -1;
			} else {
				Scaler_set_Clarity_Mastered4K(mastered_4k);
				fwif_color_set_mastered_4k();
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_PROJECT_STYLE:
		{
			unsigned char TV002_PROJECT_STYLE;
			if (copy_from_user(&TV002_PROJECT_STYLE, (void __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_PROJECT_STYLE fail\n");
				ret = -1;
			} else {
				Scaler_access_Project_TV002_Style(1, TV002_PROJECT_STYLE);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_DBC_POWER_SAVING_MODE:
		{
			unsigned char TV002_DBC_POWER_SAVING_MODE;
			if (copy_from_user(&TV002_DBC_POWER_SAVING_MODE, (void __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_DBC_POWER_SAVING_MODE fail\n");
				ret = -1;
			} else {
				Scaler_set_DBC_POWER_Saving_Mode_TV002(TV002_DBC_POWER_SAVING_MODE);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_DBC_UI_BACKLIGHT:
		{
			unsigned char TV002_DBC_UI_BACKLIGHT;
			if (copy_from_user(&TV002_DBC_UI_BACKLIGHT, (void __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_DBC_UI_BACKLIGHT fail\n");
				ret = -1;
			} else {
				Scaler_set_DBC_UI_blacklight_Value_TV002(TV002_DBC_UI_BACKLIGHT);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_TV002_DBC_BACKLIGHT:
		{
			unsigned char TV002_DBC_BACKLIGHT = Scaler_get_DBC_blacklight_Value_TV002();
			if (copy_to_user((void __user *)arg, (void *)&TV002_DBC_BACKLIGHT, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_TV002_DBC_BACKLIGHT fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_UI_PICTURE_MODE:
		{
			unsigned char TV002_UI_PICTURE_MODE;
			if (copy_from_user(&TV002_UI_PICTURE_MODE, (void __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_UI_PICTURE_MODE fail\n");
				ret = -1;
			} else {
				Scaler_set_UI_Picture_Mode_TV002(TV002_UI_PICTURE_MODE);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_Black_Level:
		{
			unsigned char setVal;
			if (copy_from_user(&setVal, (void __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_Black_Level fail\n");
				ret = -1;
			} else {
				Scaler_Get_Set_Black_Level_TV002(setVal, 1);
				ret = 0;
			}

		}
		break;

		case VPQ_EXTERN_IOC_GET_TV002_Black_Level:
		{
			unsigned char getVal = Scaler_Get_Set_Black_Level_TV002(0, 0);
			if (copy_to_user((void __user *)arg, (void *)&getVal, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_TV002_Black_Level fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_Reality_Creation:
		{
			unsigned char setVal;
			if (copy_from_user(&setVal, (void __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_Reality_Creation fail\n");
				ret = -1;
			} else {
				Scaler_Get_Set_Reality_Creation_TV002(setVal, 1);
				ret = 0;
			}

		}
		break;

		case VPQ_EXTERN_IOC_GET_TV002_Reality_Creation:
		{
			unsigned char getVal = Scaler_Get_Set_Reality_Creation_TV002(0, 0);
			if (copy_to_user((void __user *)arg, (void *)&getVal, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_TV002_Black_Level fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_Resolution:
		{
			unsigned char setVal;
			if (copy_from_user(&setVal, (void __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_Resolution fail\n");
				ret = -1;
			} else {
				Scaler_Get_Set_Resolution_TV002(setVal, 1);
				ret = 0;
			}

		}
		break;

		case VPQ_EXTERN_IOC_GET_TV002_Resolution:
		{
			unsigned char getVal = Scaler_Get_Set_Resolution_TV002(0, 0);
			if (copy_to_user((void __user *)arg, (void *)&getVal, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_TV002_Black_Level fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_Black_Corrector:
		{
			unsigned char setVal;
			if (copy_from_user(&setVal, (void __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_Black_Corrector fail\n");
				ret = -1;
			} else {
				Scaler_Get_Set_Black_Corrector_TV002(setVal, 1);
				ret = 0;
			}

		}
		break;

		case VPQ_EXTERN_IOC_GET_TV002_Black_Corrector:
		{
			unsigned char getVal = Scaler_Get_Set_Black_Corrector_TV002(0, 0);
			if (copy_to_user((void __user *)arg, (void *)&getVal, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_TV002_Black_Level fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_Black_Adjust:
		{
			unsigned char setVal;
			if (copy_from_user(&setVal, (void __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_Black_Adjust fail\n");
				ret = -1;
			} else {
				Scaler_Get_Set_Black_Adjust_TV002(setVal, 1);
				ret = 0;
			}

		}
		break;

		case VPQ_EXTERN_IOC_GET_TV002_Black_Adjust:
		{
			unsigned char getVal = Scaler_Get_Set_Black_Adjust_TV002(0, 0);
			if (copy_to_user((void __user *)arg, (void *)&getVal, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_TV002_Black_Level fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_TV002_LED_Motion_Mode:
		{
			unsigned char setVal;
			if (copy_from_user(&setVal, (void __user *)arg, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_TV002_LED_Motion_Mode fail\n");
				ret = -1;
			} else {
				Scaler_Get_Set_LED_Motion_Mode_TV002(setVal, 1);
				ret = 0;
			}

		}
		break;

		case VPQ_EXTERN_IOC_GET_TV002_LED_Motion_Mode:
		{
			unsigned char getVal = Scaler_Get_Set_LED_Motion_Mode_TV002(0, 0);
			if (copy_to_user((void __user *)arg, (void *)&getVal, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_TV002_Black_Level fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_PQ_SETGAMMA_TABLESIZE:
		{
			static RTK_TableSize_Gamma Gamma;
			if (copy_from_user(&Gamma,  (int __user *)arg,sizeof(RTK_TableSize_Gamma))) {
				ret = -1;
			} else {
				//printk("yuan,[OSD]SETGAMMA\n");			
				fwif_color_gamma_encode_TableSize(&Gamma);				
				fwif_color_set_gamma_Magic();
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_MAGICGAMMA_TV030:
		{
			//unsigned char i=0;
			RTK_TV030_MagicGamma MagicGamma;
			//printk("yuan,[OSD]MAGICGAMMA\n");			

			if (copy_from_user(&MagicGamma,  (int __user *)arg,sizeof(RTK_TV030_MagicGamma))) {
				ret = -1;
			} else {
				//for(i=0;i<12;i++){
				//printk("yuan,G[%d]=%d\n",i,MagicGamma.MagicGammaG[i]);
				//}
				//printk("yuan,[12points]ColorSpaceMode=%d\n",ColorSpaceMode);				
				fwif_color_set_12pointsData(&MagicGamma);		
				fwif_color_set_gamma_Magic();

				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_PQ_VDPQ_MEMORY_ENABLE:
		{
			printk("VPQ_EXTERN_IOC_SET_PQ_VDPQ_MEMORY_ENABLE\n");

			unsigned int args = 0;
			if ( copy_from_user(&args, (int __user *)arg, sizeof(unsigned int) ) ) {
				ret = -1;
			} else {
				if(AVD_vpq_mem_ctrl((unsigned char)args) > 0)
					ret = 0;
				else
					ret = -1;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_GDBC_MODE:
		{
			printk(KERN_DEBUG "VPQ_EXTERN_IOC_PQ_CMD_GET_GDBC_MODE\n");

			unsigned int dcr_mode = 0;
			dcr_mode = (unsigned int)Scaler_GetDcrMode();
			//printk(KERN_DEBUG "get dcr_mode = %d\n",dcr_mode);
			if (copy_to_user((void __user *)arg, (void *)&dcr_mode, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_DCC_MODE fail\n");
				ret = -1;
			} else
				ret = 0;

		}
		break;

		case VPQ_EXTERN_IOC_SET_GDBC_MODE:
		{
			printk(KERN_DEBUG "VPQ_EXTERN_IOC_PQ_CMD_SET_GDBC_MODE\n");

			unsigned int dcr_mode = 0;
			if (copy_from_user(&dcr_mode,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				ret = 0;
				printk(KERN_EMERG "set dcr_mode = %d\n",dcr_mode);
				Scaler_SetDcrMode(dcr_mode&0xff);
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_GDBC_DCR_BACKLIGHT:
		{
			printk(KERN_DEBUG "VPQ_EXTERN_IOC_GET_GDBC_DCR_BACKLIGHT\n");
			unsigned int DCR_backlight = 0;
			DCR_backlight = (unsigned int)Scaler_Get_DCR_Backlight();
			//printk(KERN_DEBUG "set DCR_backlight = %d\n",DCR_backlight);
			if (copy_to_user((void __user *)arg, (void *)&DCR_backlight, sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_GDBC_DCR_BACKLIGHT fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_Sync_PQ_table_bin_ENABLE:
		{
			rtd_printk(KERN_INFO, TAG_NAME, "VPQ_EXTERN_IOC_Sync_PQ_table_bin_ENABLE\n");
			unsigned int args = 0;
			if 	(copy_from_user((void *)&args, (const void __user *)arg, sizeof(unsigned char)))
			{
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_Sync_PQ_table_bin_ENABLE fail\n");
				ret = -1;
			} else {
				ret = 0;
				Scaler_Set_PQ_table_bin_En((unsigned char)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_GAMMA_LEVEL:
		{
			rtd_printk(KERN_INFO, TAG_NAME, "VPQ_EXTERN_IOC_SET_GAMMA_LEVEL\n");
			unsigned int level = 0;
			if (copy_from_user(&level,  (int __user *)arg,sizeof(unsigned int))) {
				ret = -1;
			} else {
				ret = 0;
				Scaler_Set_Gamma_level(level);
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_COLOR_TEMP_LEVEL:
		{
			rtd_printk(KERN_INFO, TAG_NAME, "VPQ_EXTERN_IOC_SET_COLOR_TEMP_LEVEL\n");
			unsigned int level = 0;
			if (copy_from_user(&level,  (int __user *)arg,sizeof(unsigned int))) {
				rtd_printk(KERN_EMERG, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_COLOR_TEMP_LEVEL fail\n");
				ret = -1;
			} else {
				ret = 0;
				scaler_set_color_temp_level(level);
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_LC_BLK_HVNUM_TV030:
		{
			//printk("VPQ_EXTERN_IOC_GET_LC_BLK_HVNUM_TV030\n");
			LC_BLK_Num_Size LC_pData;
			
			LC_pData.nBlk_Hnum=Scaler_Get_LC_blk_hnum();
			LC_pData.nBlk_Vnum=Scaler_Get_LC_blk_vnum();

			if (copy_to_user((void __user *)arg, (void *)&LC_pData, sizeof(LC_BLK_Num_Size))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_LC_BLK_HVNUM_TV030 fail\n");
				ret = -1;
			} else
				ret = 0;

		}
		break;

		case VPQ_EXTERN_IOC_GET_HDR_PicInfo_TV030:
		{
			//printk("VPQ_EXTERN_IOC_GET_HDR_PicInfo_TV030\n");
			if (fwif_color_get_DM_HDR10_enable_TV030() == 0) {
				//printk("1.HDR_PicInfo_TV030\n");
				ret = -1;
				break;
			}
			UINT32 HDR_info_bin[131] = {0};

			if (fwif_color_get_DM2_HDR_histogram_TV030(HDR_info_bin) == 0) {
				//printk("2.HDR_PicInfo_TV030\n");
				ret = -1;
			} else {
				if (copy_to_user(arg, HDR_info_bin, 131 * 4)) {
				//printk("3.HDR_PicInfo_TV030\n");
					ret = -1;
				} else
					ret = 0;
			}
			break;
		}

		case VPQ_EXTERN_IOC_SET_SPLIT_DEMO_TV030:
		{
			bool bOnOff;
			//printk("yuan,VPQ_EXTERN_IOC_SET_SPLIT_DEMO_TV030=%d\n",bOnOff);

			if (copy_from_user(&bOnOff, (int __user *)arg, sizeof(bool))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_SPLIT_DEMO_TV030 fail\n");
				ret = -1;
			} else {
				if (bOnOff == TRUE)
					Scaler_SetMagicPicture(SLR_MAGIC_STILLDEMO);
				else
					Scaler_SetMagicPicture(SLR_MAGIC_OFF);
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_LD_Enable_TV030:
		{
			unsigned char bEnable = Scaler_Get_LD_Enable();
			//printk("VPQ_EXTERN_IOC_GET_LD_Enable_TV030=%d\n",bEnable);

			if (copy_to_user((void __user *)arg, (void *)&bEnable, sizeof(unsigned char))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_LD_Enable_TV030 fail\n");
				ret = -1;
			} else
				ret = 0;
		
		}
		break;
		
		case VPQ_EXTERN_IOC_SET_COLORMATRIXSRGB_TV030:
		{
			RTK_COLOR_GAMUT_T ColorMatrixSRGB;
			short sRGBMatrix[3][3];
			extern short BT2020_sRGB_APPLY[3][3];			
			extern short DCI_P3_RGB_APPLY[3][3];
			extern short CCIR_709_sRGB_APPLY[3][3];

			
			if (copy_from_user(&ColorMatrixSRGB,  (int __user *)arg,sizeof(RTK_COLOR_GAMUT_T))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_COLORMATRIXSRGB_TV030 fail\n");
				ret = -1;
			} else {
		//rtd_printk(KERN_ERR, TAG_NAME, "yuan,VPQ_IOC_SET_COLORMATRIXSRGB=%d\n",ColorMatrixSRGB.mode);
		//rtd_printk(KERN_ERR, TAG_NAME, "ColorMatrixSRGB.gamutmatrix_00 = %d\n", ColorMatrixSRGB.gamutmatrix_00);
		
			switch(ColorMatrixSRGB.mode){
				
			case 0://BT2020	==>  CCIR 709		
					CCIR_709_sRGB_APPLY[0][0] = ColorMatrixSRGB.gamutmatrix_00;
					CCIR_709_sRGB_APPLY[0][1] = ColorMatrixSRGB.gamutmatrix_01;
					CCIR_709_sRGB_APPLY[0][2] = ColorMatrixSRGB.gamutmatrix_02;
					CCIR_709_sRGB_APPLY[1][0] = ColorMatrixSRGB.gamutmatrix_10;
					CCIR_709_sRGB_APPLY[1][1] = ColorMatrixSRGB.gamutmatrix_11;
					CCIR_709_sRGB_APPLY[1][2] = ColorMatrixSRGB.gamutmatrix_12;
					CCIR_709_sRGB_APPLY[2][0] = ColorMatrixSRGB.gamutmatrix_20;
					CCIR_709_sRGB_APPLY[2][1] = ColorMatrixSRGB.gamutmatrix_21;
					CCIR_709_sRGB_APPLY[2][2] = ColorMatrixSRGB.gamutmatrix_22;

					break;
					
			case 1://DCI_P3   ==>  BT2020
					BT2020_sRGB_APPLY[0][0] = ColorMatrixSRGB.gamutmatrix_00;
					BT2020_sRGB_APPLY[0][1] = ColorMatrixSRGB.gamutmatrix_01;
					BT2020_sRGB_APPLY[0][2] = ColorMatrixSRGB.gamutmatrix_02;
					BT2020_sRGB_APPLY[1][0] = ColorMatrixSRGB.gamutmatrix_10;
					BT2020_sRGB_APPLY[1][1] = ColorMatrixSRGB.gamutmatrix_11;
					BT2020_sRGB_APPLY[1][2] = ColorMatrixSRGB.gamutmatrix_12;
					BT2020_sRGB_APPLY[2][0] = ColorMatrixSRGB.gamutmatrix_20;
					BT2020_sRGB_APPLY[2][1] = ColorMatrixSRGB.gamutmatrix_21;
					BT2020_sRGB_APPLY[2][2] = ColorMatrixSRGB.gamutmatrix_22;
					
					break;
				
			case 2://CCIR 709  ==>  DCI_P3
					DCI_P3_RGB_APPLY[0][0] = ColorMatrixSRGB.gamutmatrix_00;
					DCI_P3_RGB_APPLY[0][1] = ColorMatrixSRGB.gamutmatrix_01;
					DCI_P3_RGB_APPLY[0][2] = ColorMatrixSRGB.gamutmatrix_02;
					DCI_P3_RGB_APPLY[1][0] = ColorMatrixSRGB.gamutmatrix_10;
					DCI_P3_RGB_APPLY[1][1] = ColorMatrixSRGB.gamutmatrix_11;
					DCI_P3_RGB_APPLY[1][2] = ColorMatrixSRGB.gamutmatrix_12;
					DCI_P3_RGB_APPLY[2][0] = ColorMatrixSRGB.gamutmatrix_20;
					DCI_P3_RGB_APPLY[2][1] = ColorMatrixSRGB.gamutmatrix_21;
					DCI_P3_RGB_APPLY[2][2] = ColorMatrixSRGB.gamutmatrix_22;
					
					break;

			default:
			
				break;

			}	
          	 g_srgbForceUpdate2 = 0;
			}
		}
		break;
				
		case VPQ_EXTERN_IOC_SET_LOWDELAY_MODE_TV030:
		{
			bool bOnOff;

			if (copy_from_user(&bOnOff, (int __user *)arg, sizeof(bool))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_LOWDELAY_MODE_TV030 fail\n");
				ret = -1;
			} else {
				if (bOnOff == TRUE)
					Scaler_SetMagicPicture(SLR_MAGIC_STILLDEMO);
				else
					Scaler_SetMagicPicture(SLR_MAGIC_OFF);
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_HistoData_APL_TV030:
		{
			unsigned int DC_APL = 0;

			if (fwif_color_get_HistoData_APL(&DC_APL) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_APL fail\n");
				ret = -1;
			} else {
				if (drvif_color_get_WB_pattern_on())
					DC_APL = 940;
				if (copy_to_user((void __user *)arg, (void *)&DC_APL, sizeof(unsigned int))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_APL fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_HistoData_Min_TV030:
		{
			signed int DC_min = 0;

			if (fwif_color_get_HistoData_Min(&DC_min) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_Min fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&DC_min, sizeof(signed int))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_Min fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_HistoData_Max_TV030:
		{
			signed int DC_max = 0;

			if (fwif_color_get_HistoData_Max(&DC_max) == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel fwif_color_get_HistoData_Max fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&DC_max, sizeof(signed int))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_IOC_GET_HistoData_Max fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_PARTTENFORAUTOGAMMA_TV030:
		{
			//rtd_printk(KERN_EMERG, TAG_NAME,"VPQ_EXTERN_IOC_SET_PARTTENFORAUTOGAMMA_TV030\n");
			INTERNAL_PARTTEN pData;
				
			if (copy_from_user(&pData,  (void __user *)arg,sizeof(INTERNAL_PARTTEN))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_PARTTENFORAUTOGAMMA_TV030 fail\n");
				ret = -1;
			} else {
				Scaler_Set_Partten4AutoGamma(pData.enable,pData.r_Val,pData.g_Val,pData.b_Val);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_PIXELINFO_TV030:
			{
			//printk("Ioc VPQ_EXTERN_IOC_GET_PIXELINFO_TV030!!!!!!!!\n");
			VPQ_SCREEN_PIXEL_INFO_TV030 pixelInfo;
			if (copy_from_user(&pixelInfo, (int __user *)arg, sizeof(VPQ_SCREEN_PIXEL_INFO_TV030))) {
			rtd_printk(KERN_ERR, TAG_NAME, "kernel copy VPQ_EXTERN_IOC_GET_PIXELINFO_TV030 fail\n");
			ret = -1;
			} else {
			ret = 0;
			Scaler_Get_ScreenPixel_info(&pixelInfo);
			if (copy_to_user((void __user *)arg, (void *)&pixelInfo, sizeof(VPQ_SCREEN_PIXEL_INFO_TV030))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_PIXELINFO_TV030 scaler_get_screen_pixel_info fail\n");
				ret = -1;
			} else
				ret = 0;
			}
		
		}
		break;
		
	case VPQ_EXTERN_IOC_SET_FILM_TABLE_TV030:
		{
			unsigned int film_mode_enable = 0;
			if (copy_from_user(&film_mode_enable,  (int __user *)arg,sizeof(unsigned int))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_FILM_TABLE_TV030 fail\n");
				ret = -1;
			} else {
				film_mode.film_status = film_mode_enable?28:0;
				down(get_DI_semaphore());
				drvif_module_film_mode((DRV_film_mode *) &film_mode);
				up(get_DI_semaphore());
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_DYNAMIC_RANGE_TV030:
		{
			unsigned char DolbyMode = 0;
			unsigned char HdrMode = 0;
			
			if(cur_src == 0)
			{
				DolbyMode = fwif_vip_DolbyHDR_check(SLR_MAIN_DISPLAY, _SRC_HDMI);
				HdrMode = fwif_vip_HDR10_check(SLR_MAIN_DISPLAY, _SRC_HDMI);
			} else if(cur_src == 1){
				DolbyMode = fwif_vip_DolbyHDR_check(SLR_MAIN_DISPLAY, _SRC_VO);
				HdrMode = fwif_vip_HDR10_check(SLR_MAIN_DISPLAY, _SRC_VO);
			}

			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_STATE) == _MODE_STATE_ACTIVE){
				if(DolbyMode != 0){
					if (copy_to_user((void __user *)arg, (void *)&DolbyMode, sizeof(unsigned char))){
						rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_DYNAMIC_RANGE_TV030 fail\n");
						ret = -1;
					}else{
					    ret = 0;
					}
				}else if(HdrMode == 0 || HdrMode == 2 || HdrMode == 3){
					if (copy_to_user((void __user *)arg, (void *)&HdrMode, sizeof(unsigned char))) {
						rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_DYNAMIC_RANGE_TV030 fail\n");
						ret = -1;
					}else{
                        ret = 0;
                    }
				}else{
					ret = -1;
				}
			}else{
				ret =-1;
			}
		}
		break;


		case VPQ_EXTERN_IOC_SET_DYNAMIC_RANGE_CUR_SRC_TV030:
		{
			if (copy_from_user((void *)&cur_src, (const void __user *)arg, sizeof(unsigned char))){
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_DYNAMIC_RANGE_CUR_SRC_TV030 fail\n");
				ret = -1;
			} else {
				//rtd_printk(KERN_ERR, TAG_NAME,"hzf=cur_src = %d", cur_src);
				ret = 0;
			}
		}
		break;

	        case VPQ_EXTERN_IOC_SET_HDMI_MODE_TYPE_TV030:
	        {
	            unsigned char hdmi_mode;
	            if (copy_from_user((void *)&hdmi_mode, (const void __user *)arg, sizeof(unsigned char))){
	                rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_HDMI_MODE_TYPE_TV030 fail\n");
	                ret = -1;
	            } else {
	                //rtd_printk(KERN_ERR, TAG_NAME,"set_hdmi_mode_type = %d", hdmi_mode);
	                Scaler_Set_hdmi_provider_type(hdmi_mode);
	                ret = 0;
	            }
	        }
	        break;

		case VPQ_EXTERN_IOC_SET_COLORSPACE://HSI
		{
			//printk("[Kernel]VPQ_EXTERN_IOC_SET_COLORSPACE\n");
			_system_setting_info *VIP_system_info_structure_table = NULL;
			VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
			static unsigned char pre_colorspaceisNative=0;
			RTK_VPQ_COLORSPACE_INDEX ColoSpace_T;
			extern RTK_VPQ_COLORSPACE_INDEX ColoSpace_Index;
			
			if (copy_from_user(&ColoSpace_T,  (int __user *)arg,sizeof(RTK_VPQ_COLORSPACE_INDEX))) {
				ret = -1;
			} else {
			
				ColorSpaceMode = ColoSpace_T.mode;
				if(pre_colorspaceisNative==1)
					g_srgbForceUpdate2=1;

				printk("yuan,SET_COLORSPACE=%d\n",ColoSpace_T.mode);
				//printk("yuan,HDR_flag=%d\n",VIP_system_info_structure_table ->HDR_flag);
				//printk("yuan,pre_colorspaceisNative=%d,g_srgbForceUpdate2=%d\n",pre_colorspaceisNative,g_srgbForceUpdate2);

				
				if(VIP_system_info_structure_table ->HDR_flag==0){
				if(ColoSpace_T.mode==0){//Color Space Mode=Auto
					drvif_color_D_3dLUT_Enable(0);
					fwif_color_set_sRGBMatrix();
				}
				else if(ColoSpace_T.mode==1){//Color Space Mode=Native
					drvif_color_D_3dLUT_Enable(0);
					IoReg_ClearBits(0xb802c000,_BIT0);//disable sRGB;//Scaler_Set_ColorSpace_InvGamma_sRGB_OFF();//Scaler_Set_ColorSpace_InvGamma_sRGB(0);					
				}
				else if(ColoSpace_T.mode==2){//Color Space Mode=Custom
					Scaler_Set_ColorSpace_D_3dlutTBL(&ColoSpace_T);
					memcpy(&ColoSpace_Index,&ColoSpace_T,sizeof(RTK_VPQ_COLORSPACE_INDEX));
					drvif_color_D_3dLUT_Enable(1);
					fwif_color_set_sRGBMatrix();
				}
				}
				else{
					printk("HDR no need to run ColorSpace flow\n");
					drvif_color_D_3dLUT_Enable(0);
					fwif_color_set_sRGBMatrix();
					ColorSpaceMode=0;
				}
				fwif_color_set_gamma_Magic();
				if(ColorSpaceMode==1)//Color Space Mode=Native
					pre_colorspaceisNative=1;
				else
					pre_colorspaceisNative=0;
				
				g_srgbForceUpdate2 = 0;
				printk("yuan,pre_Native=%d,g_srgbForceUpdate2=%d\n",pre_colorspaceisNative,g_srgbForceUpdate2);
				
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_HIGHLIGHTWINDOW_FORDEMO:
		{
			
			RTK_DEMO_MODE_T DEMO_MODE_T;
			//unsigned int args = 0;
			if (copy_from_user(&DEMO_MODE_T,  (int __user *)arg,sizeof(RTK_DEMO_MODE_T))) {
 
				ret = -1;
			} else {
				
				//printk("[zjl]VPQ_EXTERN_IOC_SET_DEMO DEMO_MODE_T.DEMO_MODE[%u] DEMO_MODE_T.onOff(%d)  \n",DEMO_MODE_T.DEMO_MODE,DEMO_MODE_T.onOff);
				Scaler_SetLight_Window_forDemo((Light_Window_forDemo_E)DEMO_MODE_T.DEMO_MODE,(unsigned char)DEMO_MODE_T.onOff);
				ret = 0;
			}
			
		}
		break;
		
		case VPQ_EXTERN_IOC_SET_PANORAMA_TYPE:
		{
			//printk("VPQ_EXTERN_IOC_SET_PANORAMA_TYPE\n");
			unsigned int args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				
				//drvif_color_ultrazoom_config_scaling_up(Scaler_DispCheckRatio(SLR_RATIO_PANORAMA));
				drvif_color_ultrazoom_config_scaling_up((TV030_RATIO_TYPE_E)args);
				imd_smooth_main_double_buffer_apply(ZOOM_UZU);
				//Scaler_SetPanoramaType((TV030_RATIO_TYPE_E)args);
				ret = 0;
			}
			//rtd_printk(KERN_ERR, TAG_NAME, "=======VPQ_EXTERN_IOC_SET_PANORAMA_TYPE ret= %d args=%d \n", ret,args);
		}
		break;
		
		case VPQ_EXTERN_IOC_SET_BRIGHTNESS_LUT_OETF:
		{
			//printk("VPQ_EXTERN_IOC_SET_BRIGHTNESS_LUT_OETF\n");
			RTK_BRIGHTNESS_LUT_OETF BRIGHTNESS_LUT_T;
			extern UINT16 OETF_LUT_R[1025];
			//extern UINT16 OETF_LUT_G[1025];

			if (copy_from_user(&BRIGHTNESS_LUT_T,  (int __user *)arg,sizeof(RTK_BRIGHTNESS_LUT_OETF))) {
				ret = -1;
			} else {

				//printk("db408,yuan,un16_length=%d\n",BRIGHTNESS_LUT_T.un16_length);
				if(BRIGHTNESS_LUT_T.un16_length==256){
					Scaler_SetBrightness_LUT_OETF(OETF_LUT_R,&BRIGHTNESS_LUT_T);
					fwif_color_rtice_DM2_OETF_Check(OETF_LUT_R,OETF_LUT_R,OETF_LUT_R);
				}
				else if(BRIGHTNESS_LUT_T.un16_length==1024){
				//GammaBlendOETF=1;
				Scaler_SetOETF2Gamma(&BRIGHTNESS_LUT_T);
				fwif_color_set_gamma_Magic();
				}

				ret = 0;
			}
		}
		break;


		case VPQ_EXTERN_IOC_GET_MEMCLD_ENABLE_TV030:
		{
			unsigned char bEnable = 0;
			bEnable =Scaler_GetLocalContrastEnable();
			if (Scaler_GetLocalContrastEnable() == FALSE) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel Scaler_GetLocalContrastEnable fail\n");
				ret = -1;
			} else {
				if (copy_to_user((void __user *)arg, (void *)&bEnable, sizeof(unsigned char))) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_MEMCLD_ENABLE_TV030 fail\n");
					ret = -1;
				} else
					ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_MEMCLD_ENABLE_TV030:
		{
			unsigned int args = 0;

			if (copy_from_user(&args,  (int __user *)arg,sizeof(unsigned int))) {

				ret = -1;
			} else {
				Scaler_SetLocalContrastEnable((unsigned char)args);
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_GET_LC_Blight_dat:
		{
			unsigned int *buf;
			unsigned int size;
			_RPC_system_setting_info *VIP_RPC_system_info_structure_table=NULL;
			VIP_RPC_system_info_structure_table = (_RPC_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
			//if(Scaler_color_get_System_Info(VIP_RPC_system_info_structure_table) == true){
			if(VIP_RPC_system_info_structure_table != NULL){
				size = (unsigned int)((VIP_RPC_system_info_structure_table->Local_Contrast_Ctrl.nBlk_Hnum+1)*(VIP_RPC_system_info_structure_table->Local_Contrast_Ctrl.nBlk_Vnum+1));
				buf = (unsigned int *)dvr_malloc_specific(size * sizeof(unsigned int), GFP_DCU2_FIRST);
				Scaler_color_get_LC_Blight_dat(buf);
				if (copy_to_user((void __user *)arg, (void *)buf, sizeof(unsigned int)*size)) {
					rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_LC_Blight_dat fail\n");
					ret = -1;
				} else
					ret = 0;
				dvr_free((void *)buf);
			}else{
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_LC_Blight_dat fail\n");
				ret = -1;
			}
		}
		break;


		case VPQ_EXTERN_IOC_GET_LC_Blight_size:
		{
			_RPC_system_setting_info *VIP_RPC_system_info_structure_table=NULL;
			unsigned int size[2] = {0};
			VIP_RPC_system_info_structure_table = (_RPC_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
			size[0] = (VIP_RPC_system_info_structure_table->Local_Contrast_Ctrl.nBlk_Hnum+1);
			size[1] = (VIP_RPC_system_info_structure_table->Local_Contrast_Ctrl.nBlk_Vnum+1);
			if (copy_to_user((void __user *)arg, (void *)size, sizeof(unsigned int)*2)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_LC_Blight_size fail\n");
				ret = -1;
			} else
				ret = 0;
		}
		break;

		case VPQ_EXTERN_IOC_GET_LC_HISTOGRAM_TV030:
		{
			unsigned int  plc_out[16];
			Scaler_color_get_LC_His_dat(&plc_out[0]);	
			if (copy_to_user((void __user *)arg, (void *)&plc_out[0], sizeof(plc_out) )) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_GET_LC_HISTOGRAM_TV030 fail\n");
				ret = -1;
			} else
				ret = 0;

		}
		break;

		case VPQ_EXTERN_IOC_SET_RGBWTOSRGBMATRIX:
		{
			printk("[Kernel]VPQ_EXTERN_IOC_SET_RGBWTOSRGBMATRIX\n");
			unsigned char i,j;
			extern short BT709Target_sRGB_APPLY[3][3];			
			extern short BT2020Target_sRGB_APPLY[3][3];
			extern short DCIP3Target_sRGB_APPLY[3][3];
			RTK_VPQ_sRGB_Matrix sRGB_T;
			_system_setting_info *VIP_system_info_structure_table = NULL;
			VIP_system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

			if (copy_from_user(&sRGB_T,  (int __user *)arg,sizeof(RTK_VPQ_sRGB_Matrix))) {
				ret = -1;
			} else {
				#if 0//for debug
				for(i=0;i<3;i++){
			       	 for(j=0;j<3;j++)
						printk("BT709Target[%d][%d]=%d\n",i,j,sRGB_T.BT709Target[i][j]);   	
					}
				for(i=0;i<3;i++){
			       	 for(j=0;j<3;j++)
						printk("sRGB_T->BT2020Target[%d][%d]=%d\n",i,j,sRGB_T.BT2020Target[i][j]);   	
					}
				for(i=0;i<3;i++){
			       	 for(j=0;j<3;j++)
						printk("sRGB_T->DCIP3Target[%d][%d]=%d\n",i,j,sRGB_T.DCIP3Target[i][j]);   	
					}
				#endif
				//-----------------------------------------------------------------------------
				for(i=0;i<3;i++){
			       	 for(j=0;j<3;j++)
						BT709Target_sRGB_APPLY[i][j]=sRGB_T.BT709Target[i][j];   	
					}
				for(i=0;i<3;i++){
			       	 for(j=0;j<3;j++)
						BT2020Target_sRGB_APPLY[i][j]=sRGB_T.BT2020Target[i][j];   	
					}
				for(i=0;i<3;i++){
			       	 for(j=0;j<3;j++)
						DCIP3Target_sRGB_APPLY[i][j]=sRGB_T.DCIP3Target[i][j];   	
					}

		//printk("yuan,[vpq]BT2020=%d\n",VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag);

		if(VIP_system_info_structure_table->BT2020_CTRL.Enable_Flag == 1){
				//set sRGB matrix
				fwif_sRGB_SetMatrix(SLR_MAIN_DISPLAY, BT2020Target_sRGB_APPLY, 1);
		}
		else{
				fwif_sRGB_SetMatrix(SLR_MAIN_DISPLAY, BT709Target_sRGB_APPLY, 1);
		}
				
          	 g_srgbForceUpdate2 = 0;

				
				ret = 0;
			}
		}
		break;

		case VPQ_EXTERN_IOC_SET_LC_HISBIN_TV030:
		{
			//LC histogram only 7 bin
			//printk("[Kernel]VPQ_EXTERN_IOC_SET_LC_HISBIN_TV030\n");
			ret = 0;

		}
		break;
		
		case VPQ_EXTERN_IOC_SET_PICTUREMODE_TV030:
		{
			printk("VPQ_EXTERN_IOC_SET_PICTUREMODE_TV030\n");
			RTK_VPQ_MODE_TYPE_TV030 args = 0;
			if (copy_from_user(&args,  (int __user *)arg,sizeof(RTK_VPQ_MODE_TYPE_TV030))) {

				ret = -1;
			} else {
			ret = 0;
				printk("yuan,PICTUREMODE=%d\n",args);				
				Scaler_Set_PictureMode_PQsetting((RTK_VPQ_MODE_TYPE_TV030)args);
			}
		}
		break;
		case VPQ_EXTERN_IOC_SET_BRIGHTNESS_OSDLAYER_TV030:
		{
			//printk("[Kernel]VPQ_EXTERN_IOC_SET_BRIGHTNESS_OSDLAYER_TV030\n");
			ret = 0;

		}
		break;

		case VPQ_EXTERN_IOC_SET_CONTRAST_OSDLAYER_TV030:
		{
			//printk("[Kernel]VPQ_EXTERN_IOC_SET_CONTRAST_OSDLAYER_TV030\n");
			ret = 0;

		}
		break;

		case VPQ_EXTERN_IOC_INIT_DDOMAIN3DLUT_GAMMA_TABLE:
		{
			extern UINT8 DDomain3DLUT_Gamma_control[5][3];
			if (copy_to_user((void __user *)arg, (void *)&(DDomain3DLUT_Gamma_control[0][0]), sizeof(UINT8) * 15)) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_INIT_DDOMAIN3DLUT_GAMMA_TABLE fail\n");
				ret = -1;
			} else {
				ret = 0;
			}
		
		}
		break;
		case VPQ_EXTERN_IOC_SET_DDOMAIN3DLUT_GAMMA:
		{
			UINT8 i_tmp = 0;
			if (copy_to_user((void __user *)arg, (void *)&i_tmp, sizeof(UINT8))) {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_DDOMAIN3DLUT_GAMMA fail\n");
				ret = -1;
			} else {
				rtd_printk(KERN_ERR, TAG_NAME, "kernel VPQ_EXTERN_IOC_SET_DDOMAIN3DLUT_GAMMA get %d\n", i_tmp);
				Scaler_color_set_DDomain3DLUT_gamma_by_colorspace(i_tmp);
				ret = 0;
			}
		
		}
		break;
	default:
		rtd_printk(KERN_DEBUG, TAG_NAME, "kernel IO command %d not found!\n", cmd);
		printk("VPQ_EXTERN_IOC cmd=0x%x unknown\n", cmd);
		return -1;
			;
	}
	return ret;/*Success*/

}

struct file_operations vpqex_fops = {
	.owner = THIS_MODULE,
	.open = vpqex_open,
	.release = vpqex_release,
	.read  = vpqex_read,
	.write = vpqex_write,
	.unlocked_ioctl = vpqex_ioctl,
};

#ifdef CONFIG_PM
static const struct dev_pm_ops vpqex_pm_ops =
{
        .suspend    = vpqex_suspend,
        .resume     = vpqex_resume,
#ifdef CONFIG_HIBERNATION
	.freeze 	= vpqex_suspend,
	.thaw		= vpqex_resume,
	.poweroff	= vpqex_suspend,
	.restore	= vpqex_resume,
#endif

};
#endif // CONFIG_PM

static struct class *vpqex_class = NULL;
static struct platform_device *vpqex_platform_devs = NULL;
static struct platform_driver vpqex_platform_driver = {
	.driver = {
		.name = VPQ_EXTERN_DEVICE_NAME,
		.bus = &platform_bus_type,
#ifdef CONFIG_PM
		.pm = &vpqex_pm_ops,
#endif
    },
} ;

static char *vpqex_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

int vpqex_major   = 0;
int vpqex_minor   = 0 ;
int vpqex_nr_devs = 1;

int vpqex_module_init(void)
{
	printk("vpqex_module_init %d\n", __LINE__);

	int result;
	dev_t devno = 0;//vbe device number
	result = alloc_chrdev_region(&vpqex_devno, vpqex_minor, vpqex_nr_devs, VPQ_EXTERN_DEVICE_NAME);
	vpqex_major = MAJOR(vpqex_devno);
	if (result != 0) {
		rtd_printk(KERN_ERR, TAG_NAME, "Cannot allocate VPQEX device number\n");
		printk("vpqex_module_init %d\n", __LINE__);
		return result;
	}

	printk("vpqex_module_init %d\n", __LINE__);

	printk("VPQEX_DEVICE init module major number = %d\n", vpqex_major);
	//vpqex_devno = MKDEV(vpqex_major, vpqex_minor);

	vpqex_class = class_create(THIS_MODULE, VPQ_EXTERN_DEVICE_NAME);
	if (IS_ERR(vpqex_class)) {
		rtd_printk(KERN_ERR, TAG_NAME, "scalevpqex: can not create class...\n");
		printk("vpqex_module_init %d\n", __LINE__);
		result = PTR_ERR(vpqex_class);
		goto fail_class_create;
	}

	vpqex_class->devnode = vpqex_devnode;

	vpqex_platform_devs = platform_device_register_simple(VPQ_EXTERN_DEVICE_NAME, -1, NULL, 0);
	if (platform_driver_register(&vpqex_platform_driver) != 0) {
		rtd_printk(KERN_ERR, TAG_NAME, "scalevpqex: can not register platform driver...\n");
		printk("vpqex_module_init %d\n", __LINE__);
		result = -ENOMEM;
		goto fail_platform_driver_register;
	}

	cdev_init(&vpqex_cdev, &vpqex_fops);
	vpqex_cdev.owner = THIS_MODULE;
   	vpqex_cdev.ops = &vpqex_fops;
	result = cdev_add(&vpqex_cdev, vpqex_devno, 1);
	if (result < 0) {
		rtd_printk(KERN_ERR, TAG_NAME, "scalevpqex: can not add character device...\n");
		printk("vpqex_module_init %d\n", __LINE__);
		goto fail_cdev_init;
	}

	device_create(vpqex_class, NULL, vpqex_devno, NULL, VPQ_EXTERN_DEVICE_NAME);

//	sema_init(&VPQ_EXTERN_Semaphore, 1);
	sema_init(&ICM_Semaphore,1);

	vpqex_boot_init();

	printk("vpqex_module_init %d\n", __LINE__);
	return 0;/*Success*/

fail_cdev_init:
	platform_driver_unregister(&vpqex_platform_driver);
fail_platform_driver_register:
	platform_device_unregister(vpqex_platform_devs);
	vpqex_platform_devs = NULL;
	class_destroy(vpqex_class);
fail_class_create:
	vpqex_class = NULL;
	unregister_chrdev_region(vpqex_devno, 1);
	printk("vpqex_module_init %d\n", __LINE__);
	return result;

}



void __exit vpqex_module_exit(void)
{
	printk("vpqex_module_exit\n");

	if (vpqex_platform_devs == NULL)
		BUG();

	device_destroy(vpqex_class, vpqex_devno);
	cdev_del(&vpqex_cdev);

	platform_driver_unregister(&vpqex_platform_driver);
	platform_device_unregister(vpqex_platform_devs);
	vpqex_platform_devs = NULL;

	class_destroy(vpqex_class);
	vpqex_class = NULL;

	unregister_chrdev_region(vpqex_devno, 1);
}

module_init(vpqex_module_init);
module_exit(vpqex_module_exit);
