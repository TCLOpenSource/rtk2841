/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for FILM related functions.
 *
 * @author 	$Author$
 * @date 	$Date$
 * @version 	$Revision$
 */

/**
 * @addtogroup film
 * @{
 */

/*============================ Module dependency  ===========================*/
#if CONFIG_FIRMWARE_IN_KERNEL
/*#include <unistd.h>			*/ /* 'close()'*/
/*#include <fcntl.h>			*/ /* 'open()'*/
/*#include <stdio.h>*/
/*#include <sys/ioctl.h>*/
#include <linux/string.h>
//#include <mach/io.h>

#include <rbus/sb2_reg.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/vip/vip_reg_def.h>
#include <tvscalercontrol/vip/color.h>
#include <tvscalercontrol/vip/dcc.h>
#include <tvscalercontrol/vip/peaking.h>
#include <scalercommon/scalerCommon.h>

/* oliver+*/
#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scaler/scalerlib.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>
#include <mach/rtk_log.h>
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

#include <unistd.h>			// 'close()'
#include <fcntl.h>			// 'open()'
#include <stdio.h>
#include <sys/ioctl.h>
#include <string.h>

#include <rbusVgipReg.h>
#include <Platform_Lib/TVScalerControl/vip/sb2_reg.h>
#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerStruct.h>
#include <Platform_Lib/TVScalerControl/vip/VIP_reg_def.h>
#include <Platform_Lib/TVScalerControl/vip/color.h>
#include <Platform_Lib/TVScalerControl/vip/dcc.h>
#include <Platform_Lib/TVScalerControl/vip/peaking.h>
#include <scaler/scalerCommon.h>

// oliver+
#include <scaler/scalerDrvCommon.h>
#include <Platform_Lib/TVScalerControl/scaler/scalerLib.h>
#endif

#if CONFIG_FIRMWARE_IN_KERNEL
#define VIPprintf(fmt, args...)	rtd_printk(KERN_DEBUG, TAG_NAME, fmt, ##args)//printk(KERN_DEBUG fmt, ##args)
#else
#define VIPprintf(fmt, args...)	printf(fmt, ##args)
#endif


/*===================================  Types ================================*/

/*================================== Variables ==============================*/


/*================================ Definitions ==============================*/
/*o------ User defined table ------o */ /* For Factory Mode range: 5~9 in VIP_video_performance.h*/

/*==================== registers setting for New DCC ====================*/

/*********************************************************************************/
/*o------ MicroCode for New Algorithm -------o*/
extern DRV_VipChromaCompensation_t g_Chroma_Compensation_Curve[8];

/*==========HDR============*/
extern unsigned char HDR_demo_flag;
extern unsigned int dcc_histogram_to_write[TableSeg_num_Max];
/*=========================*/



/*================================== Function ===============================*/

void drvif_color_dcc_on(unsigned char enable)
{
	color_d_vc_global_ctrl_RBUS d_vc_global_ctrl_Reg;
	d_vc_global_ctrl_Reg.regValue = rtd_inl(COLOR_D_VC_Global_CTRL_reg);

	if (enable == 0) {
		d_vc_global_ctrl_Reg.dcc_en = 0;/*dcc curve off*/
	} else {
		d_vc_global_ctrl_Reg.dcc_en = 1;/*dcc curve on*/
	}
	d_vc_global_ctrl_Reg.write_enable_1 = 1;
	//d_vc_global_ctrl_Reg.regValue = d_vc_global_ctrl_Reg.regValue | COLOR_D_VC_Global_CTRL_write_enable_1_mask;
	rtd_outl(COLOR_D_VC_Global_CTRL_reg, d_vc_global_ctrl_Reg.regValue);
}

unsigned char drvif_color_dcc_db_switch()
{
	short timecnt = 0;
	color_dcc_d_dcc_db_ctrl_RBUS color_dcc_d_dcc_db_ctrl_reg;
	color_dcc_d_dcc_ctrl_RBUS	 	color_dcc_d_dcc_ctrl_reg;

	color_dcc_sram_tab_ctl_0_RBUS	color_dcc_sram_tab_ctl_0_reg;  //new change for mac5

	color_dcc_d_dcc_db_ctrl_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_DB_CTRL_reg);
	color_dcc_d_dcc_ctrl_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_CTRL_reg);
	color_dcc_sram_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);

	/*step1 : set db apply*/
	color_dcc_d_dcc_db_ctrl_reg.db_apply = 1 ;
	rtd_outl(COLOR_DCC_D_DCC_DB_CTRL_reg, color_dcc_d_dcc_db_ctrl_reg.regValue);

	/*step2 : set DCC Table select*/
	color_dcc_d_dcc_ctrl_reg.main_table_sel = color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_sel;
	rtd_outl(COLOR_DCC_D_DCC_CTRL_reg, color_dcc_d_dcc_ctrl_reg.regValue);

	/*step3 : check db apply finish*/
	do {
		color_dcc_d_dcc_ctrl_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_CTRL_reg);
		timecnt++;
		} while (color_dcc_d_dcc_ctrl_reg.main_table_sel != color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_sel);

	/*if (color_dcc_d_dcc_ctrl_reg.main_table_sel == color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_sel)*/
		/*VIPprintf("Success!! %d\n", timecnt);*/

	return TRUE;

}

unsigned char drvif_color_dcc_Curve_Write(unsigned char display, unsigned char CurveSegNum, unsigned int *sAccLUT)
{
	unsigned char i = 0;
	short index;
	int timeout = 100000;

	unsigned short Base = 0, G0, G1;
	int distance;

	color_dcc_d_dcc_db_ctrl_RBUS color_dcc_d_dcc_db_ctrl_reg;
	color_d_vc_global_ctrl_RBUS		d_vc_global_ctrl_REG;
	/*o---- Identity Curve init coef---o*/
	G1 = G0 = 8;
	distance = G0 + G1;

	color_dcc_d_dcc_db_ctrl_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_DB_CTRL_reg);
	d_vc_global_ctrl_REG.regValue 		= rtd_inl(COLOR_D_VC_Global_CTRL_reg);


	if (display == SLR_MAIN_DISPLAY) {
		/* DCC Table Write*/
		/*Step 1: DCC Curve Table Write init*/
		color_dcc_sram_tab_ctl_0_RBUS	color_dcc_sram_tab_ctl_0_reg;
		color_dcc_sram_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_index = 0;
		color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 1;
		if (color_dcc_d_dcc_db_ctrl_reg.db_en == 1) {
			color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_sel = (color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_sel == 0) ? 1 : 0;
		} else {
			color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_sel = 0;
		}
		rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);

		/*VIPprintf("D_VSC =%d\n", IoReg_BusyCheckRegBit(PPOVERLAY_DTG_PENDING_STATUS_VADDR, _BIT0, 0x1FFFF));*/

		/*Step 2 : Star DCC Table Write*/
		index = -1;
		for (i = 0; i < CurveSegNum; i++) {
			/*Step 2.1 : check sram table ready to write*/
			do {
				timeout--;
				color_dcc_sram_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				/*VIPprintf(" timeout!!%d \n", timeout);*/
				if (timeout <= 0) {
					VIPprintf(" timeout!! DCC Init. Write DCC acc_ready Fault!!\n");
					/*break;*/
				}
				} while ((color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_ready != 1));

			/*VIPprintf(" timeout!!%d \n", timeout);*/
			/*Step 2.2 : check sram table ready status*/

			color_dcc_sram_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
			if (color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_ready != 1) {
				color_dcc_sram_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 0;
				rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);
				VIPprintf("DCC Init. Write DCC Init Table Fault!!\n");
				return FALSE;
			}
			Base = i * distance - 1;

			/*Step 2.3 : check write index for current index = now index*/
			index++;
			color_dcc_sram_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);

			if (index != color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_index_cur) {    /*cur = index*/
				color_dcc_sram_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 0;
				rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);
				return FALSE;
			}
			/*VIPprintf("sAccLUT[%d]=%x, %x\n", i, sAccLUT[i],((Base << 16) + (G0 << 8) + G1));*/
			VIPprintf("sAccLUT[%d]=%x\n", i, sAccLUT[i]);
			rtd_outl(COLOR_DCC_SRAM_TAB_PORT_reg, sAccLUT[i]);
			/*rtd_outl((COLOR_DCC_SRAM_TAB_PORT_reg), ((Base << 16) + (G0 << 8) + G1));*/
			timeout = 100000;
		}

		/*Step 3 : check write finish, and avoid other API access reg. at the same time.*/
		do {
			timeout--;
			color_dcc_sram_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
			/*VIPprintf("i =%d, timeout =%d, sram_tab_acc_ready =%d \n", i, timeout, color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_ready);*/
			if (timeout <= 0) {
				VIPprintf(" timeout!! DCC Init. Write DCC Init Table Fault!!\n");
				break;
			}
			} while ((color_dcc_sram_tab_ctl_0_reg.sram_tab_acc_ready != 1));

		/*Step 4 : diable DCC sram table RW_Sel*/
		color_dcc_sram_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_sram_tab_ctl_0_reg.sram_tab_rw_sel = 0;
		rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_sram_tab_ctl_0_reg.regValue);

		if (color_dcc_d_dcc_db_ctrl_reg.db_en == 1) {
			if (drvif_color_dcc_db_switch() != TRUE) {
				return FALSE;
			}
		}
	}

	return TRUE;

}


void drvif_color_dcc_Curve_init(unsigned char display)
{

	unsigned char i = 0;
	unsigned short Base = 0, G0, G1;
	int index, timeout = 10;
	int DCCNum = TableSeg_num_Max;/*this is controlled by DCC segment*/
	int distance;

	_system_setting_info *VIP_system_info_structure_table = (_system_setting_info*)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);

	color_dcc_d_dcc_ctrl_RBUS	 	color_dcc_d_dcc_ctrl_reg;
	color_d_vc_global_ctrl_RBUS 	color_d_vc_global_ctrl_reg;
	color_dcc_d_dcc_db_ctrl_RBUS color_dcc_d_dcc_db_ctrl_reg;

	color_dcc_d_dcc_ctrl_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_CTRL_reg);
	color_d_vc_global_ctrl_reg.regValue = rtd_inl(COLOR_D_VC_Global_CTRL_reg);
	color_dcc_d_dcc_db_ctrl_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_DB_CTRL_reg);


	/*o---- Identity Curve init coef---o*/
	//G1 = G0 = 4096 / DCCNum / 2; //Merlin2 12bits
	G1 = G0 = 1024 / DCCNum / 2; //Mac5p 10bits
	distance = G0 + G1;

	/* initialize table of DCC Curve*/
	if (display == SLR_MAIN_DISPLAY) {
		color_dcc_sram_tab_ctl_0_RBUS  color_dcc_dcc_y_sram_tab_ctl_reg;

		/*o----Select Dcc Table and Segment num---o*/
		color_dcc_d_dcc_ctrl_reg.dcc_main_en = 1;
		color_dcc_d_dcc_ctrl_reg.main_table_sel = 0;
		color_dcc_d_dcc_ctrl_reg.main_table_segment = 0;
		rtd_outl(COLOR_DCC_D_DCC_CTRL_reg, color_dcc_d_dcc_ctrl_reg.regValue);

		/*o---DCC Curve Table init for Main channel---o*/
		color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_index = 0;
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 1;
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_sel = 0;
		rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);


		/*o---- Double Buffer Setting -----o*/
		color_dcc_d_dcc_db_ctrl_reg.db_en = 0;
		color_dcc_d_dcc_db_ctrl_reg.db_read_level = 0;
		rtd_outl(COLOR_DCC_D_DCC_DB_CTRL_reg, color_dcc_d_dcc_db_ctrl_reg.regValue);
		index = -1;
		for (i = 0; i < DCCNum; i++) {
			Base = i * distance - 1;
			do {
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				} while ((color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_ready != 1) && ((timeout--) > 0));

			if (timeout < 0) {
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
				rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
				VIPprintf("DCC Init. Write DCC Init Table Fault!!");
				return;
			}
			index++;
			if (index != color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_index_cur) {    /*cur = index*/
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
				rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
				return;
			}
			//rtd_outl((COLOR_DCC_SRAM_TAB_PORT_reg), ((Base << 20) + (G0 << 10) + G1)); //Merlin2 12bits
			rtd_outl((COLOR_DCC_SRAM_TAB_PORT_reg), ((Base << 16) + (G0 << 8) + G1)); //Mac5p 10bits
		}

		color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
		rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
	}

#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		color_dcc_sram_tab_ctl_0_RBUS   color_dcc_dcc_y_sram_tab_ctl_reg;

		/*o----Select Dcc Table and Segment num---o*/
		color_dcc_d_dcc_ctrl_reg.dcc_sub_mode_sel = 2; /* use sub_table_sel*/
		color_dcc_d_dcc_ctrl_reg.sub_table_sel = 0;
		color_dcc_d_dcc_ctrl_reg.sub_table_segment = 0;
		rtd_outl(COLOR_DCC_D_DCC_CTRL_reg, color_dcc_d_dcc_ctrl_reg.regValue);

		/*o---DCC Curve Table init for Sub channel---o*/
		color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_index = 0;
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 1;
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_sel = 2; /* SUB table1*/
		rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);


		/*o---- Double Buffer Setting -----o*/
		color_dcc_d_dcc_db_ctrl_reg.db_en = 0;
		color_dcc_d_dcc_db_ctrl_reg.db_read_level = 0;
		rtd_outl(COLOR_DCC_D_DCC_DB_CTRL_reg, color_dcc_d_dcc_db_ctrl_reg.regValue);
		index = -1;
		for (i = 0; i < DCCNum; i++) {
			Base = i * distance - 1;
			do {
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				} while ((color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_ready != 1) && ((timeout--) > 0));

			if (timeout < 0) {
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
				rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
				VIPprintf("DCC Init. Write DCC Init Table Fault!!");
				return;
			}
			index++;
			if (index != color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_index_cur) {     /*cur = index*/
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
				rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
				return;
			}
			if (VIP_system_info_structure_table->HDR_flag== 1) {
				rtd_outl((COLOR_DCC_SRAM_TAB_PORT_reg), dcc_histogram_to_write[i]);
			} else {
				rtd_outl((COLOR_DCC_SRAM_TAB_PORT_reg), ((Base << 20) + (G0 << 10) + G1));
			}
		}
		color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_DCC_Y_SRAM_TAB_CTL_reg);
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
		rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
	}
#endif

	color_d_vc_global_ctrl_reg.dcc_en = 1;
	color_d_vc_global_ctrl_reg.write_enable_1 = 1;

	#ifdef TV010_PQ_STYLE
		color_d_vc_global_ctrl_reg.icm_dcc_swap = 1 ;
		color_d_vc_global_ctrl_reg.write_enable_9 = 1;
	#endif

	scaler_rtd_outl(COLOR_D_VC_Global_CTRL_reg, color_d_vc_global_ctrl_reg.regValue);
}

void drvif_color_dcc_hist_on(unsigned char display, int status)
{
	if (display == SLR_MAIN_DISPLAY) {
	histogram_ich1_hist_in_cselect_RBUS hist_in_cselect_Reg;
	histogram_ich1_c0_hist_bound_RBUS ich1_hist_bound_Reg;

		hist_in_cselect_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_IN_CSELECT_reg);
		hist_in_cselect_Reg.ch1_his_enable_histog = status;
		rtd_outl(HISTOGRAM_ICH1_Hist_IN_CSELECT_reg, hist_in_cselect_Reg.regValue);

		ich1_hist_bound_Reg.regValue = rtd_inl(HISTOGRAM_ICH1_C0_Hist_Bound_reg);
		ich1_hist_bound_Reg.ch1_c0_lower_bound = 0;
		ich1_hist_bound_Reg.ch1_c0_upper_bound = 1023; //20150708 chance_qian
		rtd_outl(HISTOGRAM_ICH1_C0_Hist_Bound_reg, ich1_hist_bound_Reg.regValue);

	}
#ifdef CONFIG_DUAL_CHANNEL
#ifdef VIP_CONFIG_DUAL_CHANNEL // henry 161214
	else {
		histogram_ich2_hist_in_cselect_RBUS hist_in_cselect_Reg;
		histogram_ich2_c0_hist_bound_RBUS ich2_hist_bound_Reg;

		hist_in_cselect_Reg.regValue = rtd_inl(HISTOGRAM_ICH2_Hist_IN_CSELECT_reg);
		hist_in_cselect_Reg.ch2_his_enable_histog = status;
		rtd_outl(HISTOGRAM_ICH2_Hist_IN_CSELECT_reg, hist_in_cselect_Reg.regValue);

		ich2_hist_bound_Reg.regValue = rtd_inl(HISTOGRAM_ICH2_C0_Hist_Bound_reg);
		ich2_hist_bound_Reg.ch2_c0_lower_bound = 0;
		ich2_hist_bound_Reg.ch2_c0_upper_bound = 1023; //20150708 chance_qian
		rtd_outl(HISTOGRAM_ICH2_C0_Hist_Bound_reg, ich2_hist_bound_Reg.regValue);
	}
#endif
#endif
}




/*============================================================================*/
/*o---------------------------------------------------o*/
/*      DCC_setLevel*/
/*      ==> to set DCC level*/
/*      @param <DCC_level> { 0 ~ 15, default 2*/
/*                           0  : Disable DCC*/
/*                           1~4  : internal user define curve*/
/*                           5~9 :  user define curve by Tool  }*/
/*      @return {none}*/
/*o---------------------------------------------------o*/



void drvif_color_set_dcc_overlap_table(void)
{
#ifdef VIP_CONFIG_DUAL_CHANNEL
	unsigned char overlap;
	color_dcc_d_dcc_ctrl_RBUS d_dcc_ctrl_Reg;

	overlap = (IoReg_Read32(CON_BRI_DM_COLOR_RGB_CTRL_reg) & 0xf8000000) >> 27;

	/* select overlap table*/
	/*	d_dcc_ctrl_Reg.regValue = IoReg_Read32(DCC_D_DCC_CTRL_reg);  */ /* Erin tmp why not !?*/

	if (overlap == 0) {
		d_dcc_ctrl_Reg.dcc_overlay = 1;
		/*d_dcc_ctrl_Reg.dcc_sub_tab_sel = 2;  */ /* by pass temporarily because sub table fails*/
	} else {
		d_dcc_ctrl_Reg.dcc_overlay = 0;

	}
	IoReg_Write32(COLOR_DCC_D_DCC_CTRL_reg, d_dcc_ctrl_Reg.regValue);
#endif
}


void drvif_color_set_dcc_Color_Independent(VIP_DCC_Color_Independent_Blending_Table *ptr)
{
	UINT32 Segment0_0 = 0, Segment0_1 = 0, Segment1_0 = 0, Segment1_1 = 0, Segment2_0 = 0, Segment2_1 = 0, Segment3_0 = 0, Segment3_1 = 0;
	UINT32 Segment0_0_c = 0, Segment0_1_c = 0, Segment1_0_c = 0, Segment1_1_c = 0, Segment2_0_c = 0, Segment2_1_c = 0, Segment3_0_c = 0, Segment3_1_c = 0; //20150708 chance_qian

	color_dcc_d_dcc_skin_tone_en_RBUS d_dcc_skin_tone_en_reg;


	color_dcc_d_dcc_skin_tone_yuv_center_0_RBUS d_dcc_skin_tone_yuv_center_0_reg;
	color_dcc_d_dcc_skin_tone_yuv_range_0_RBUS d_dcc_skin_tone_yuv_range_0_reg;

	color_dcc_d_dcc_skin_tone_segment0_0_RBUS d_dcc_skin_tone_segment0_0_reg;
	color_dcc_d_dcc_skin_tone_segment0_1_RBUS d_dcc_skin_tone_segment0_1_reg;
	color_dcc_d_dcc_skin_tone_segment_c0_0_RBUS d_dcc_skin_tone_segment_c0_0_reg; //20150708 chance_qian
	color_dcc_d_dcc_skin_tone_segment_c0_1_RBUS d_dcc_skin_tone_segment_c0_1_reg; //20150708 chance_qian

	color_dcc_d_dcc_skin_tone_yuv_center_1_RBUS d_dcc_skin_tone_yuv_center_1_reg;
	color_dcc_d_dcc_skin_tone_yuv_range_1_RBUS d_dcc_skin_tone_yuv_range_1_reg;
	color_dcc_d_dcc_skin_tone_segment1_0_RBUS d_dcc_skin_tone_segment1_0_reg;
	color_dcc_d_dcc_skin_tone_segment1_1_RBUS d_dcc_skin_tone_segment1_1_reg;
	color_dcc_d_dcc_skin_tone_segment_c1_0_RBUS d_dcc_skin_tone_segment_c1_0_reg; //20150708 chance_qian
	color_dcc_d_dcc_skin_tone_segment_c1_1_RBUS d_dcc_skin_tone_segment_c1_1_reg; //20150708 chance_qian

	color_dcc_d_dcc_skin_tone_yuv_center_2_RBUS d_dcc_skin_tone_yuv_center_2_reg;
	color_dcc_d_dcc_skin_tone_yuv_range_2_RBUS d_dcc_skin_tone_yuv_range_2_reg;
	color_dcc_d_dcc_skin_tone_segment2_0_RBUS d_dcc_skin_tone_segment2_0_reg;
	color_dcc_d_dcc_skin_tone_segment2_1_RBUS d_dcc_skin_tone_segment2_1_reg;
	color_dcc_d_dcc_skin_tone_segment_c2_0_RBUS d_dcc_skin_tone_segment_c2_0_reg; //20150708 chance_qian
	color_dcc_d_dcc_skin_tone_segment_c2_1_RBUS d_dcc_skin_tone_segment_c2_1_reg; //20150708 chance_qian

	color_dcc_d_dcc_skin_tone_yuv_center_3_RBUS d_dcc_skin_tone_yuv_center_3_reg;
	color_dcc_d_dcc_skin_tone_yuv_range_3_RBUS d_dcc_skin_tone_yuv_range_3_reg;
	color_dcc_d_dcc_skin_tone_segment3_0_RBUS d_dcc_skin_tone_segment3_0_reg;
	color_dcc_d_dcc_skin_tone_segment3_1_RBUS d_dcc_skin_tone_segment3_1_reg;
	color_dcc_d_dcc_skin_tone_segment_c3_0_RBUS d_dcc_skin_tone_segment_c3_0_reg; //20150708 chance_qian
	color_dcc_d_dcc_skin_tone_segment_c3_1_RBUS d_dcc_skin_tone_segment_c3_1_reg; //20150708 chance_qian

	d_dcc_skin_tone_en_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_EN_reg);

	d_dcc_skin_tone_yuv_center_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_reg);
	d_dcc_skin_tone_yuv_range_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_reg);
	d_dcc_skin_tone_segment0_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_reg);
	d_dcc_skin_tone_segment0_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_reg);
	d_dcc_skin_tone_segment_c0_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_reg); //20150708 chance_qian
	d_dcc_skin_tone_segment_c0_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_reg); //20150708 chance_qian

	d_dcc_skin_tone_yuv_center_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_reg);
	d_dcc_skin_tone_yuv_range_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_reg);
	d_dcc_skin_tone_segment1_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_reg);
	d_dcc_skin_tone_segment1_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_reg);
	d_dcc_skin_tone_segment_c1_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_reg); //20150708 chance_qian
	d_dcc_skin_tone_segment_c1_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_reg); //20150708 chance_qian

	d_dcc_skin_tone_yuv_center_2_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_reg);
	d_dcc_skin_tone_yuv_range_2_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_reg);
	d_dcc_skin_tone_segment2_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_reg);
	d_dcc_skin_tone_segment2_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_reg);
	d_dcc_skin_tone_segment_c2_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_reg); //20150708 chance_qian
	d_dcc_skin_tone_segment_c2_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_reg); //20150708 chance_qian

	d_dcc_skin_tone_yuv_center_3_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_reg);
	d_dcc_skin_tone_yuv_range_3_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_reg);
	d_dcc_skin_tone_segment3_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_reg);
	d_dcc_skin_tone_segment3_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_reg);
	d_dcc_skin_tone_segment_c3_0_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_reg); //20150708 chance_qian
	d_dcc_skin_tone_segment_c3_1_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_reg); //20150708 chance_qian

	d_dcc_skin_tone_en_reg.y_blending_en = ptr->S_DCC_Skin_Tone_Settings.y_blending_en;// 1;
	d_dcc_skin_tone_en_reg.y_blending_mode = ptr->S_DCC_Skin_Tone_Settings.y_blending_mode;// 1;

	/*VIPprintf("en =%d, mode =%d\n",*(DCC_skin_tone_TABLE+1*8+0),*(DCC_skin_tone_TABLE+1*8+1));*/
	/*VIPprintf("y_center =%d, u_center =%d, v_center =%d\n",*(DCC_skin_tone_TABLE+1*8+2),*(DCC_skin_tone_TABLE+1*8+3),*(DCC_skin_tone_TABLE+1*8+4));*/
	/*VIPprintf("y_range =%d, u_range =%d, v_range =%d\n",*(DCC_skin_tone_TABLE+1*8+5),*(DCC_skin_tone_TABLE+1*8+6),*(DCC_skin_tone_TABLE+1*8+7));*/

	d_dcc_skin_tone_en_reg.y_blending_reg0_en =							ptr->S_DCC_Skin_Tone_Y_Region0_Coef.region0_en;
	d_dcc_skin_tone_yuv_center_0_reg.y_blending_0_y_center = 				       ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Y_Center0;
	d_dcc_skin_tone_yuv_center_0_reg.y_blending_0_u_center =				ptr->S_DCC_Skin_Tone_Y_Region0_Coef.U_Center0;
	d_dcc_skin_tone_yuv_center_0_reg.y_blending_0_v_center =				ptr->S_DCC_Skin_Tone_Y_Region0_Coef.V_Center0;
	d_dcc_skin_tone_yuv_range_0_reg.y_blending_0_y_range =					ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Y_Range0;
	d_dcc_skin_tone_yuv_range_0_reg.y_blending_0_u_range =					ptr->S_DCC_Skin_Tone_Y_Region0_Coef.U_Range0;
	d_dcc_skin_tone_yuv_range_0_reg.y_blending_0_v_range =					ptr->S_DCC_Skin_Tone_Y_Region0_Coef.V_Range0;

	Segment0_0 = ((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_0) << 24)+
				((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_1) << 16) +
				((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_2) << 8) +
				((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_3));
	Segment0_1 = ((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_4) << 24)+
				((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_5) << 16) +
				((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_6) << 8) +
				((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_7));

	d_dcc_skin_tone_segment0_0_reg.regValue = Segment0_0;
	d_dcc_skin_tone_segment0_1_reg.regValue = Segment0_1;

	Segment0_0_c = ((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_0_c) << 24)+	//20150708 chance_qian
				   ((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_1_c) << 16) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_2_c) << 8) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_3_c));
	Segment0_1_c = ((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_4_c) << 24)+
				   ((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_5_c) << 16) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_6_c) << 8) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region0_Coef.Segment0_7_c));

	d_dcc_skin_tone_segment_c0_0_reg.regValue = Segment0_0_c; //20150708 chance_qian
	d_dcc_skin_tone_segment_c0_1_reg.regValue = Segment0_1_c; //20150708 chance_qian

	d_dcc_skin_tone_en_reg.y_blending_reg1_en =							ptr->S_DCC_Skin_Tone_Y_Region1_Coef.region1_en;
	d_dcc_skin_tone_yuv_center_1_reg.y_blending_1_y_center = 				       ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Y_Center1;
	d_dcc_skin_tone_yuv_center_1_reg.y_blending_1_u_center =				ptr->S_DCC_Skin_Tone_Y_Region1_Coef.U_Center1;
	d_dcc_skin_tone_yuv_center_1_reg.y_blending_1_v_center =				ptr->S_DCC_Skin_Tone_Y_Region1_Coef.V_Center1;
	d_dcc_skin_tone_yuv_range_1_reg.y_blending_1_y_range =					ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Y_Range1;
	d_dcc_skin_tone_yuv_range_1_reg.y_blending_1_u_range =					ptr->S_DCC_Skin_Tone_Y_Region1_Coef.U_Range1;
	d_dcc_skin_tone_yuv_range_1_reg.y_blending_1_v_range =					ptr->S_DCC_Skin_Tone_Y_Region1_Coef.V_Range1;

	Segment1_0 = ((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_0) << 24)+
				((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_1) << 16) +
				((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_2) << 8) +
				((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_3));
	Segment1_1 = ((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_4) << 24)+
				((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_5) << 16) +
				((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_6) << 8) +
				((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_7));

	d_dcc_skin_tone_segment1_0_reg.regValue = Segment1_0;
	d_dcc_skin_tone_segment1_1_reg.regValue = Segment1_1;

	Segment1_0_c = ((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_0_c) << 24)+	//20150708 chance_qian
				   ((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_1_c) << 16) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_2_c) << 8) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_3_c));
	Segment1_1_c = ((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_4_c) << 24)+
				   ((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_5_c) << 16) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_6_c) << 8) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region1_Coef.Segment1_7_c));

	d_dcc_skin_tone_segment_c1_0_reg.regValue = Segment1_0_c; //20150708 chance_qian
	d_dcc_skin_tone_segment_c1_1_reg.regValue = Segment1_1_c; //20150708 chance_qian

	d_dcc_skin_tone_en_reg.y_blending_reg2_en =							ptr->S_DCC_Skin_Tone_Y_Region2_Coef.region2_en;
	d_dcc_skin_tone_yuv_center_2_reg.y_blending_2_y_center = 				ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Y_Center2;
	d_dcc_skin_tone_yuv_center_2_reg.y_blending_2_u_center =				ptr->S_DCC_Skin_Tone_Y_Region2_Coef.U_Center2;
	d_dcc_skin_tone_yuv_center_2_reg.y_blending_2_v_center =				ptr->S_DCC_Skin_Tone_Y_Region2_Coef.V_Center2;
	d_dcc_skin_tone_yuv_range_2_reg.y_blending_2_y_range =					ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Y_Range2;
	d_dcc_skin_tone_yuv_range_2_reg.y_blending_2_u_range =					ptr->S_DCC_Skin_Tone_Y_Region2_Coef.U_Range2;
	d_dcc_skin_tone_yuv_range_2_reg.y_blending_2_v_range =					ptr->S_DCC_Skin_Tone_Y_Region2_Coef.V_Range2;

	Segment2_0 = ((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_0) << 24)+
				((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_1) << 16) +
				((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_2) << 8) +
				((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_3));
	Segment2_1 = ((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_4) << 24)+
				((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_5) << 16) +
				((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_6) << 8) +
				((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_7));

	d_dcc_skin_tone_segment2_0_reg.regValue = Segment2_0;
	d_dcc_skin_tone_segment2_1_reg.regValue = Segment2_1;

	Segment2_0_c = ((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_0_c) << 24)+	//20150708 chance_qian
				   ((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_1_c) << 16) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_2_c) << 8) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_3_c));
	Segment2_1_c = ((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_4_c) << 24)+
				   ((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_5_c) << 16) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_6_c) << 8) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region2_Coef.Segment2_7_c));

	d_dcc_skin_tone_segment_c2_0_reg.regValue = Segment2_0_c; //20150708 chance_qian
	d_dcc_skin_tone_segment_c2_1_reg.regValue = Segment2_1_c; //20150708 chance_qian

	d_dcc_skin_tone_en_reg.y_blending_reg3_en =							ptr->S_DCC_Skin_Tone_Y_Region3_Coef.region3_en;
	d_dcc_skin_tone_yuv_center_3_reg.y_blending_3_y_center = 				ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Y_Center3;
	d_dcc_skin_tone_yuv_center_3_reg.y_blending_3_u_center =				ptr->S_DCC_Skin_Tone_Y_Region3_Coef.U_Center3;
	d_dcc_skin_tone_yuv_center_3_reg.y_blending_3_v_center =				ptr->S_DCC_Skin_Tone_Y_Region3_Coef.V_Center3;
	d_dcc_skin_tone_yuv_range_3_reg.y_blending_3_y_range =					ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Y_Range3;
	d_dcc_skin_tone_yuv_range_3_reg.y_blending_3_u_range =					ptr->S_DCC_Skin_Tone_Y_Region3_Coef.U_Range3;
	d_dcc_skin_tone_yuv_range_3_reg.y_blending_3_v_range =					ptr->S_DCC_Skin_Tone_Y_Region3_Coef.V_Range3;

	Segment3_0 = ((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_0) << 24)+
				((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_1) << 16) +
				((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_2) << 8) +
				((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_3));
	Segment3_1 = ((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_4) << 24)+
				((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_5) << 16) +
				((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_6) << 8) +
				((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_7));

	d_dcc_skin_tone_segment3_0_reg.regValue = Segment3_0;
	d_dcc_skin_tone_segment3_1_reg.regValue = Segment3_1;

	Segment3_0_c = ((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_0_c) << 24)+	//20150708 chance_qian
				   ((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_1_c) << 16) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_2_c) << 8) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_3_c));
	Segment3_1_c = ((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_4_c) << 24)+
				   ((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_5_c) << 16) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_6_c) << 8) +
				   ((ptr->S_DCC_Skin_Tone_Y_Region3_Coef.Segment3_7_c));

	d_dcc_skin_tone_segment_c3_0_reg.regValue = Segment3_0_c; //20150708 chance_qian
	d_dcc_skin_tone_segment_c3_1_reg.regValue = Segment3_1_c; //20150708 chance_qian

	/*VIPprintf("2.en =%d, mode =%d\n", d_dcc_skin_tone_en_reg.y_blending_en, d_dcc_skin_tone_en_reg.y_blending_mode);*/
	/*VIPprintf("2.y_center =%d, u_center =%d, v_center =%d\n", d_dcc_skin_tone_yuv_center_reg.y_blending_y_center , d_dcc_skin_tone_yuv_center_reg.y_blending_u_center, d_dcc_skin_tone_yuv_center_reg.y_blending_v_center);*/
	/*VIPprintf("2.y_range =%d, u_range =%d, v_range =%d\n", d_dcc_skin_tone_yuv_range_reg.y_blending_y_range, d_dcc_skin_tone_yuv_range_reg.y_blending_u_range, d_dcc_skin_tone_yuv_range_reg.y_blending_v_range);*/


	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_EN_reg, d_dcc_skin_tone_en_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_0_reg, d_dcc_skin_tone_yuv_center_0_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_0_reg, d_dcc_skin_tone_yuv_range_0_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_0_reg, d_dcc_skin_tone_segment0_0_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT0_1_reg, d_dcc_skin_tone_segment0_1_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_0_reg, d_dcc_skin_tone_segment_c0_0_reg.regValue); //20150708 chance_qian
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C0_1_reg, d_dcc_skin_tone_segment_c0_1_reg.regValue); //20150708 chance_qian

	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_1_reg, d_dcc_skin_tone_yuv_center_1_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_1_reg, d_dcc_skin_tone_yuv_range_1_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_0_reg, d_dcc_skin_tone_segment1_0_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT1_1_reg, d_dcc_skin_tone_segment1_1_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_0_reg, d_dcc_skin_tone_segment_c1_0_reg.regValue); //20150708 chance_qian
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C1_1_reg, d_dcc_skin_tone_segment_c1_1_reg.regValue); //20150708 chance_qian

	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_2_reg, d_dcc_skin_tone_yuv_center_2_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_2_reg, d_dcc_skin_tone_yuv_range_2_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_0_reg, d_dcc_skin_tone_segment2_0_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT2_1_reg, d_dcc_skin_tone_segment2_1_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_0_reg, d_dcc_skin_tone_segment_c2_0_reg.regValue); //20150708 chance_qian
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C2_1_reg, d_dcc_skin_tone_segment_c2_1_reg.regValue); //20150708 chance_qian

	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_CENTER_3_reg, d_dcc_skin_tone_yuv_center_3_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_YUV_RANGE_3_reg, d_dcc_skin_tone_yuv_range_3_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_0_reg, d_dcc_skin_tone_segment3_0_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT3_1_reg, d_dcc_skin_tone_segment3_1_reg.regValue);
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_0_reg, d_dcc_skin_tone_segment_c3_0_reg.regValue); //20150708 chance_qian
	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_SEGMENT_C3_1_reg, d_dcc_skin_tone_segment_c3_1_reg.regValue); //20150708 chance_qian


	drvif_color_set_dcc_Skin_Tone_User_Curve(&(ptr->S_DCC_Skin_Tone_User_Curve));

}


void drvif_color_set_dcc_Chroma_enhance(void)
{
	//chroma table
	color_dcc_dcc_ctrl_chroma_gain_RBUS			color_dcc_dcc_ctrl_chroma_gain_reg;
	color_dcc_dcc_ctrl_chroma_gain_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg);
	color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_tab0_seg0 = 0;
	color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_tab1_seg0 = 0;
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg, color_dcc_dcc_ctrl_chroma_gain_reg.regValue);

	color_dcc_dcc_ctrl_chroma_gain_tab0_0_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_1_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_2_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_3_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_4_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_5_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_6_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_7_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_8_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_9_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_10_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_11_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_12_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_13_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_14_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab0_15_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg;

	color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_reg);

	color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.chroma_gain_tab0_seg1 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.chroma_gain_tab0_seg2 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.chroma_gain_tab0_seg3 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.chroma_gain_tab0_seg4 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.chroma_gain_tab0_seg5 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.chroma_gain_tab0_seg6 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.chroma_gain_tab0_seg7 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.chroma_gain_tab0_seg8 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.chroma_gain_tab0_seg9 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.chroma_gain_tab0_seg10 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.chroma_gain_tab0_seg11 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.chroma_gain_tab0_seg12 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.chroma_gain_tab0_seg13 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.chroma_gain_tab0_seg14 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.chroma_gain_tab0_seg15 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.chroma_gain_tab0_seg16 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.chroma_gain_tab0_seg17 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.chroma_gain_tab0_seg18 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.chroma_gain_tab0_seg19 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.chroma_gain_tab0_seg20 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.chroma_gain_tab0_seg21 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.chroma_gain_tab0_seg22 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.chroma_gain_tab0_seg23 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.chroma_gain_tab0_seg24 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.chroma_gain_tab0_seg25 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.chroma_gain_tab0_seg26 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.chroma_gain_tab0_seg27 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.chroma_gain_tab0_seg28 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.chroma_gain_tab0_seg29 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.chroma_gain_tab0_seg30 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.chroma_gain_tab0_seg31 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.chroma_gain_tab0_seg32 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.chroma_gain_tab0_seg33 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.chroma_gain_tab0_seg34 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.chroma_gain_tab0_seg35 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.chroma_gain_tab0_seg36 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.chroma_gain_tab0_seg37 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.chroma_gain_tab0_seg38 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.chroma_gain_tab0_seg39 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.chroma_gain_tab0_seg40 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.chroma_gain_tab0_seg41 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.chroma_gain_tab0_seg42 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.chroma_gain_tab0_seg43 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.chroma_gain_tab0_seg44 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.chroma_gain_tab0_seg45 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.chroma_gain_tab0_seg46 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.chroma_gain_tab0_seg47 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.chroma_gain_tab0_seg48 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.chroma_gain_tab0_seg49 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.chroma_gain_tab0_seg50 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.chroma_gain_tab0_seg51 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.chroma_gain_tab0_seg52 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.chroma_gain_tab0_seg53 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.chroma_gain_tab0_seg54 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.chroma_gain_tab0_seg55 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.chroma_gain_tab0_seg56 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.chroma_gain_tab0_seg57 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.chroma_gain_tab0_seg58 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.chroma_gain_tab0_seg59 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.chroma_gain_tab0_seg60 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.chroma_gain_tab0_seg61 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.chroma_gain_tab0_seg62 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.chroma_gain_tab0_seg63 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.chroma_gain_tab0_seg64 = 0;

	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.regValue);

	color_dcc_dcc_ctrl_chroma_gain_tab1_0_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_1_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_2_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_3_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_4_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_5_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_6_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_7_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_8_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_9_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_10_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_11_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_12_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_13_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_14_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg;
	color_dcc_dcc_ctrl_chroma_gain_tab1_15_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg;

	color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_reg);
	color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_reg);

	color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.chroma_gain_tab1_seg1 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.chroma_gain_tab1_seg2 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.chroma_gain_tab1_seg3 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.chroma_gain_tab1_seg4 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.chroma_gain_tab1_seg5 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.chroma_gain_tab1_seg6 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.chroma_gain_tab1_seg7 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.chroma_gain_tab1_seg8 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.chroma_gain_tab1_seg9 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.chroma_gain_tab1_seg10 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.chroma_gain_tab1_seg11 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.chroma_gain_tab1_seg12 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.chroma_gain_tab1_seg13 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.chroma_gain_tab1_seg14 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.chroma_gain_tab1_seg15 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.chroma_gain_tab1_seg16 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.chroma_gain_tab1_seg17 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.chroma_gain_tab1_seg18 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.chroma_gain_tab1_seg19 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.chroma_gain_tab1_seg20 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.chroma_gain_tab1_seg21 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.chroma_gain_tab1_seg22 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.chroma_gain_tab1_seg23 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.chroma_gain_tab1_seg24 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.chroma_gain_tab1_seg25 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.chroma_gain_tab1_seg26 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.chroma_gain_tab1_seg27 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.chroma_gain_tab1_seg28 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.chroma_gain_tab1_seg29 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.chroma_gain_tab1_seg30 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.chroma_gain_tab1_seg31 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.chroma_gain_tab1_seg32 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.chroma_gain_tab1_seg33 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.chroma_gain_tab1_seg34 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.chroma_gain_tab1_seg35 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.chroma_gain_tab1_seg36 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.chroma_gain_tab1_seg37 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.chroma_gain_tab1_seg38 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.chroma_gain_tab1_seg39 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.chroma_gain_tab1_seg40 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.chroma_gain_tab1_seg41 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.chroma_gain_tab1_seg42 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.chroma_gain_tab1_seg43 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.chroma_gain_tab1_seg44 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.chroma_gain_tab1_seg45 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.chroma_gain_tab1_seg46 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.chroma_gain_tab1_seg47 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.chroma_gain_tab1_seg48 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.chroma_gain_tab1_seg49 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.chroma_gain_tab1_seg50 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.chroma_gain_tab1_seg51 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.chroma_gain_tab1_seg52 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.chroma_gain_tab1_seg53 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.chroma_gain_tab1_seg54 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.chroma_gain_tab1_seg55 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.chroma_gain_tab1_seg56 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.chroma_gain_tab1_seg57 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.chroma_gain_tab1_seg58 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.chroma_gain_tab1_seg59 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.chroma_gain_tab1_seg60 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.chroma_gain_tab1_seg61 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.chroma_gain_tab1_seg62 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.chroma_gain_tab1_seg63 = 0;
	color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.chroma_gain_tab1_seg64 = 0;

	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.regValue);
	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.regValue);
}


void drvif_color_set_dcc_chroma_compensation_Init(unsigned char display)
{
	color_dcc_dcc_ctrl_chroma_gain_RBUS color_dcc_dcc_ctrl_chroma_gain_reg;
	color_dcc_dcc_ctrl_chroma_gain_reg.regValue = rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg);

	if (display == SLR_MAIN_DISPLAY) {
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_en = 1;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_enhance_above_tab_select_main = 0;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_enhance_below_tab_select_main = 1;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_base = 3;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_lookup_mode = 1;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_mode = 0;
	}
#ifdef VIP_CONFIG_DUAL_CHANNEL
	else {
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_en_sub = 1;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_enhance_above_tab_select_sub = 0;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_enhance_below_tab_select_sub = 1;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_base_sub = 3;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_lookup_mode_sub = 1;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_mode_sub = 0;
	}
#endif
	rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg, color_dcc_dcc_ctrl_chroma_gain_reg.regValue);
}


void drvif_color_set_dcc_chroma_compensation_Curve_Mode(unsigned char display, VIP_DCC_Chroma_Compensation_TABLE *table)
{
	if (!table) {
		VIPprintf(":::ERROR: DCC table is NULL!:::\n");
		return;
	}

	if (display == SLR_MAIN_DISPLAY) {

		/*chroma limit*/
		color_dcc_dcc_chroma_gain_limit_0_RBUS	color_dcc_dcc_chroma_gain_limit_0_reg;
		color_dcc_dcc_chroma_gain_limit_1_RBUS	color_dcc_dcc_chroma_gain_limit_1_reg;

		color_dcc_dcc_chroma_gain_limit_0_reg.regValue = rtd_inl(COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_reg);
		color_dcc_dcc_chroma_gain_limit_1_reg.regValue = rtd_inl(COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_reg);

		color_dcc_dcc_chroma_gain_limit_0_reg.chroma_gain_limit_en = table->Chroma_Compensation_Ctrl.gain_limit_en;
		color_dcc_dcc_chroma_gain_limit_0_reg.chroma_gain_limit_seg0 = table->chroma_gain_limit[0] - 1;
		color_dcc_dcc_chroma_gain_limit_0_reg.chroma_gain_limit_seg1 = table->chroma_gain_limit[1] - 1;
		color_dcc_dcc_chroma_gain_limit_0_reg.chroma_gain_limit_seg2 = table->chroma_gain_limit[2] - 1;
		color_dcc_dcc_chroma_gain_limit_0_reg.chroma_gain_limit_seg3 = table->chroma_gain_limit[3] - 1;
		color_dcc_dcc_chroma_gain_limit_1_reg.chroma_gain_limit_seg4 = table->chroma_gain_limit[4] - 1;
		color_dcc_dcc_chroma_gain_limit_1_reg.chroma_gain_limit_seg5 = table->chroma_gain_limit[5] - 1;
		color_dcc_dcc_chroma_gain_limit_1_reg.chroma_gain_limit_seg6 = table->chroma_gain_limit[6] - 1;
		color_dcc_dcc_chroma_gain_limit_1_reg.chroma_gain_limit_seg7 = table->chroma_gain_limit[7] - 1;

		scaler_rtd_outl(COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_0_reg, color_dcc_dcc_chroma_gain_limit_0_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_1_reg, color_dcc_dcc_chroma_gain_limit_1_reg.regValue);

		/*chroma table*/
		{
		color_dcc_dcc_ctrl_chroma_gain_RBUS 		color_dcc_dcc_ctrl_chroma_gain_reg;
		color_dcc_dcc_ctrl_chroma_gain_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg);
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_tab0_seg0 = table->chroma_gain_t0[0];
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_tab1_seg0 = table->chroma_gain_t1[0];
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_en = table->Chroma_Compensation_Ctrl.gain_en;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_mode = table->Chroma_Compensation_Ctrl.gain_mode;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_lookup_mode = table->Chroma_Compensation_Ctrl.gain_lookup_mode;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_gain_base = table->Chroma_Compensation_Ctrl.gain_base;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_enhance_above_tab_select_main = table->Chroma_Compensation_Ctrl.enh_mode_above_tab_sel;
		color_dcc_dcc_ctrl_chroma_gain_reg.chroma_enhance_below_tab_select_main = table->Chroma_Compensation_Ctrl.enh_mode_below_tab_sel;
		color_dcc_dcc_ctrl_chroma_gain_reg.saturation_byy_u_tab_select_main = table->Chroma_Compensation_Ctrl.byY_mode_u_tab_sel;
		color_dcc_dcc_ctrl_chroma_gain_reg.saturation_byy_v_tab_select_main = table->Chroma_Compensation_Ctrl.byY_mode_v_tab_sel;
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_reg, color_dcc_dcc_ctrl_chroma_gain_reg.regValue);
		}

		/*chroma table*/
		{
		color_dcc_dcc_ctrl_chroma_gain_tab0_0_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_1_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_2_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_3_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_4_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_5_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_6_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_7_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_8_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_9_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_10_RBUS color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_11_RBUS color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_12_RBUS color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_13_RBUS color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_14_RBUS color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab0_15_RBUS color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg;

		color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_reg);

		color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.chroma_gain_tab0_seg1 = table->chroma_gain_t0[1];
		color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.chroma_gain_tab0_seg2 = table->chroma_gain_t0[2];
		color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.chroma_gain_tab0_seg3 = table->chroma_gain_t0[3];
		color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.chroma_gain_tab0_seg4 = table->chroma_gain_t0[4];
		color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.chroma_gain_tab0_seg5 = table->chroma_gain_t0[5];
		color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.chroma_gain_tab0_seg6 = table->chroma_gain_t0[6];
		color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.chroma_gain_tab0_seg7 = table->chroma_gain_t0[7];
		color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.chroma_gain_tab0_seg8 = table->chroma_gain_t0[8];
		color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.chroma_gain_tab0_seg9 = table->chroma_gain_t0[9];
		color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.chroma_gain_tab0_seg10 = table->chroma_gain_t0[10];
		color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.chroma_gain_tab0_seg11 = table->chroma_gain_t0[11];
		color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.chroma_gain_tab0_seg12 = table->chroma_gain_t0[12];
		color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.chroma_gain_tab0_seg13 = table->chroma_gain_t0[13];
		color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.chroma_gain_tab0_seg14 = table->chroma_gain_t0[14];
		color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.chroma_gain_tab0_seg15 = table->chroma_gain_t0[15];
		color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.chroma_gain_tab0_seg16 = table->chroma_gain_t0[16];
		color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.chroma_gain_tab0_seg17 = table->chroma_gain_t0[17];
		color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.chroma_gain_tab0_seg18 = table->chroma_gain_t0[18];
		color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.chroma_gain_tab0_seg19 = table->chroma_gain_t0[19];
		color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.chroma_gain_tab0_seg20 = table->chroma_gain_t0[20];
		color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.chroma_gain_tab0_seg21 = table->chroma_gain_t0[21];
		color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.chroma_gain_tab0_seg22 = table->chroma_gain_t0[22];
		color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.chroma_gain_tab0_seg23 = table->chroma_gain_t0[23];
		color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.chroma_gain_tab0_seg24 = table->chroma_gain_t0[24];
		color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.chroma_gain_tab0_seg25 = table->chroma_gain_t0[25];
		color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.chroma_gain_tab0_seg26 = table->chroma_gain_t0[26];
		color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.chroma_gain_tab0_seg27 = table->chroma_gain_t0[27];
		color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.chroma_gain_tab0_seg28 = table->chroma_gain_t0[28];
		color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.chroma_gain_tab0_seg29 = table->chroma_gain_t0[29];
		color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.chroma_gain_tab0_seg30 = table->chroma_gain_t0[30];
		color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.chroma_gain_tab0_seg31 = table->chroma_gain_t0[31];
		color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.chroma_gain_tab0_seg32 = table->chroma_gain_t0[32];
		color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.chroma_gain_tab0_seg33 = table->chroma_gain_t0[33];
		color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.chroma_gain_tab0_seg34 = table->chroma_gain_t0[34];
		color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.chroma_gain_tab0_seg35 = table->chroma_gain_t0[35];
		color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.chroma_gain_tab0_seg36 = table->chroma_gain_t0[36];
		color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.chroma_gain_tab0_seg37 = table->chroma_gain_t0[37];
		color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.chroma_gain_tab0_seg38 = table->chroma_gain_t0[38];
		color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.chroma_gain_tab0_seg39 = table->chroma_gain_t0[39];
		color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.chroma_gain_tab0_seg40 = table->chroma_gain_t0[40];
		color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.chroma_gain_tab0_seg41 = table->chroma_gain_t0[41];
		color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.chroma_gain_tab0_seg42 = table->chroma_gain_t0[42];
		color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.chroma_gain_tab0_seg43 = table->chroma_gain_t0[43];
		color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.chroma_gain_tab0_seg44 = table->chroma_gain_t0[44];
		color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.chroma_gain_tab0_seg45 = table->chroma_gain_t0[45];
		color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.chroma_gain_tab0_seg46 = table->chroma_gain_t0[46];
		color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.chroma_gain_tab0_seg47 = table->chroma_gain_t0[47];
		color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.chroma_gain_tab0_seg48 = table->chroma_gain_t0[48];
		color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.chroma_gain_tab0_seg49 = table->chroma_gain_t0[49];
		color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.chroma_gain_tab0_seg50 = table->chroma_gain_t0[50];
		color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.chroma_gain_tab0_seg51 = table->chroma_gain_t0[51];
		color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.chroma_gain_tab0_seg52 = table->chroma_gain_t0[52];
		color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.chroma_gain_tab0_seg53 = table->chroma_gain_t0[53];
		color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.chroma_gain_tab0_seg54 = table->chroma_gain_t0[54];
		color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.chroma_gain_tab0_seg55 = table->chroma_gain_t0[55];
		color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.chroma_gain_tab0_seg56 = table->chroma_gain_t0[56];
		color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.chroma_gain_tab0_seg57 = table->chroma_gain_t0[57];
		color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.chroma_gain_tab0_seg58 = table->chroma_gain_t0[58];
		color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.chroma_gain_tab0_seg59 = table->chroma_gain_t0[59];
		color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.chroma_gain_tab0_seg60 = table->chroma_gain_t0[60];
		color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.chroma_gain_tab0_seg61 = table->chroma_gain_t0[61];
		color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.chroma_gain_tab0_seg62 = table->chroma_gain_t0[62];
		color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.chroma_gain_tab0_seg63 = table->chroma_gain_t0[63];
		color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.chroma_gain_tab0_seg64 = table->chroma_gain_t0[64];

		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_0_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_0_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_1_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_1_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_2_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_2_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_3_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_3_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_4_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_4_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_5_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_5_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_6_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_6_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_7_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_7_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_8_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_8_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_9_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_9_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_10_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_10_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_11_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_11_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_12_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_12_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_13_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_13_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_14_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_14_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB0_15_reg, color_dcc_dcc_ctrl_chroma_gain_tab0_15_reg.regValue);

		color_dcc_dcc_ctrl_chroma_gain_tab1_0_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_1_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_2_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_3_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_4_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_5_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_6_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_7_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_8_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_9_RBUS	color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_10_RBUS color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_11_RBUS color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_12_RBUS color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_13_RBUS color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_14_RBUS color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg;
		color_dcc_dcc_ctrl_chroma_gain_tab1_15_RBUS color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg;

		color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_reg);
		color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.regValue=rtd_inl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_reg);

		color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.chroma_gain_tab1_seg1 = table->chroma_gain_t1[1];
		color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.chroma_gain_tab1_seg2 = table->chroma_gain_t1[2];
		color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.chroma_gain_tab1_seg3 = table->chroma_gain_t1[3];
		color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.chroma_gain_tab1_seg4 = table->chroma_gain_t1[4];
		color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.chroma_gain_tab1_seg5 = table->chroma_gain_t1[5];
		color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.chroma_gain_tab1_seg6 = table->chroma_gain_t1[6];
		color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.chroma_gain_tab1_seg7 = table->chroma_gain_t1[7];
		color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.chroma_gain_tab1_seg8 = table->chroma_gain_t1[8];
		color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.chroma_gain_tab1_seg9 = table->chroma_gain_t1[9];
		color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.chroma_gain_tab1_seg10 = table->chroma_gain_t1[10];
		color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.chroma_gain_tab1_seg11 = table->chroma_gain_t1[11];
		color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.chroma_gain_tab1_seg12 = table->chroma_gain_t1[12];
		color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.chroma_gain_tab1_seg13 = table->chroma_gain_t1[13];
		color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.chroma_gain_tab1_seg14 = table->chroma_gain_t1[14];
		color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.chroma_gain_tab1_seg15 = table->chroma_gain_t1[15];
		color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.chroma_gain_tab1_seg16 = table->chroma_gain_t1[16];
		color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.chroma_gain_tab1_seg17 = table->chroma_gain_t1[17];
		color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.chroma_gain_tab1_seg18 = table->chroma_gain_t1[18];
		color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.chroma_gain_tab1_seg19 = table->chroma_gain_t1[19];
		color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.chroma_gain_tab1_seg20 = table->chroma_gain_t1[20];
		color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.chroma_gain_tab1_seg21 = table->chroma_gain_t1[21];
		color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.chroma_gain_tab1_seg22 = table->chroma_gain_t1[22];
		color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.chroma_gain_tab1_seg23 = table->chroma_gain_t1[23];
		color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.chroma_gain_tab1_seg24 = table->chroma_gain_t1[24];
		color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.chroma_gain_tab1_seg25 = table->chroma_gain_t1[25];
		color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.chroma_gain_tab1_seg26 = table->chroma_gain_t1[26];
		color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.chroma_gain_tab1_seg27 = table->chroma_gain_t1[27];
		color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.chroma_gain_tab1_seg28 = table->chroma_gain_t1[28];
		color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.chroma_gain_tab1_seg29 = table->chroma_gain_t1[29];
		color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.chroma_gain_tab1_seg30 = table->chroma_gain_t1[30];
		color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.chroma_gain_tab1_seg31 = table->chroma_gain_t1[31];
		color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.chroma_gain_tab1_seg32 = table->chroma_gain_t1[32];
		color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.chroma_gain_tab1_seg33 = table->chroma_gain_t1[33];
		color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.chroma_gain_tab1_seg34 = table->chroma_gain_t1[34];
		color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.chroma_gain_tab1_seg35 = table->chroma_gain_t1[35];
		color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.chroma_gain_tab1_seg36 = table->chroma_gain_t1[36];
		color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.chroma_gain_tab1_seg37 = table->chroma_gain_t1[37];
		color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.chroma_gain_tab1_seg38 = table->chroma_gain_t1[38];
		color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.chroma_gain_tab1_seg39 = table->chroma_gain_t1[39];
		color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.chroma_gain_tab1_seg40 = table->chroma_gain_t1[40];
		color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.chroma_gain_tab1_seg41 = table->chroma_gain_t1[41];
		color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.chroma_gain_tab1_seg42 = table->chroma_gain_t1[42];
		color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.chroma_gain_tab1_seg43 = table->chroma_gain_t1[43];
		color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.chroma_gain_tab1_seg44 = table->chroma_gain_t1[44];
		color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.chroma_gain_tab1_seg45 = table->chroma_gain_t1[45];
		color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.chroma_gain_tab1_seg46 = table->chroma_gain_t1[46];
		color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.chroma_gain_tab1_seg47 = table->chroma_gain_t1[47];
		color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.chroma_gain_tab1_seg48 = table->chroma_gain_t1[48];
		color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.chroma_gain_tab1_seg49 = table->chroma_gain_t1[49];
		color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.chroma_gain_tab1_seg50 = table->chroma_gain_t1[50];
		color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.chroma_gain_tab1_seg51 = table->chroma_gain_t1[51];
		color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.chroma_gain_tab1_seg52 = table->chroma_gain_t1[52];
		color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.chroma_gain_tab1_seg53 = table->chroma_gain_t1[53];
		color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.chroma_gain_tab1_seg54 = table->chroma_gain_t1[54];
		color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.chroma_gain_tab1_seg55 = table->chroma_gain_t1[55];
		color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.chroma_gain_tab1_seg56 = table->chroma_gain_t1[56];
		color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.chroma_gain_tab1_seg57 = table->chroma_gain_t1[57];
		color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.chroma_gain_tab1_seg58 = table->chroma_gain_t1[58];
		color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.chroma_gain_tab1_seg59 = table->chroma_gain_t1[59];
		color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.chroma_gain_tab1_seg60 = table->chroma_gain_t1[60];
		color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.chroma_gain_tab1_seg61 = table->chroma_gain_t1[61];
		color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.chroma_gain_tab1_seg62 = table->chroma_gain_t1[62];
		color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.chroma_gain_tab1_seg63 = table->chroma_gain_t1[63];
		color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.chroma_gain_tab1_seg64 = table->chroma_gain_t1[64];

		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_0_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_0_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_1_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_1_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_2_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_2_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_3_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_3_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_4_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_4_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_5_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_5_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_6_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_6_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_7_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_7_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_8_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_8_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_9_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_9_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_10_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_10_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_11_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_11_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_12_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_12_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_13_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_13_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_14_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_14_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CTRL_CHROMA_GAIN_TAB1_15_reg, color_dcc_dcc_ctrl_chroma_gain_tab1_15_reg.regValue);
		}
	}
#ifdef VIP_CONFIG_DUAL_CHANNEL
	else {
		/*chroma limit*/
		color_dcc_dcc_chroma_gain_limit_sub_0_RBUS	color_dcc_dcc_chroma_gain_limit_sub_0_reg;
		color_dcc_dcc_chroma_gain_limit_sub_1_RBUS	color_dcc_dcc_chroma_gain_limit_sub_1_reg;

		color_dcc_dcc_chroma_gain_limit_sub_0_reg.regValue = rtd_inl(COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_SUB_0_reg);
		color_dcc_dcc_chroma_gain_limit_sub_1_reg.regValue = rtd_inl(COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_SUB_1_reg);

		color_dcc_dcc_chroma_gain_limit_sub_0_reg.chroma_gain_limit_en_sub = table->Chroma_Compensation_Ctrl.gain_limit_en;
		color_dcc_dcc_chroma_gain_limit_sub_0_reg.chroma_gain_limit_seg0_sub = table->chroma_gain_limit[0] - 1;
		color_dcc_dcc_chroma_gain_limit_sub_0_reg.chroma_gain_limit_seg1_sub = table->chroma_gain_limit[1] - 1;
		color_dcc_dcc_chroma_gain_limit_sub_0_reg.chroma_gain_limit_seg2_sub = table->chroma_gain_limit[2] - 1;
		color_dcc_dcc_chroma_gain_limit_sub_0_reg.chroma_gain_limit_seg3_sub = table->chroma_gain_limit[3] - 1;
		color_dcc_dcc_chroma_gain_limit_sub_1_reg.chroma_gain_limit_seg4_sub = table->chroma_gain_limit[4] - 1;
		color_dcc_dcc_chroma_gain_limit_sub_1_reg.chroma_gain_limit_seg5_sub = table->chroma_gain_limit[5] - 1;
		color_dcc_dcc_chroma_gain_limit_sub_1_reg.chroma_gain_limit_seg6_sub = table->chroma_gain_limit[6] - 1;
		color_dcc_dcc_chroma_gain_limit_sub_1_reg.chroma_gain_limit_seg7_sub = table->chroma_gain_limit[7] - 1;


		scaler_rtd_outl(COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_SUB_0_reg, color_dcc_dcc_chroma_gain_limit_sub_0_reg.regValue);
		scaler_rtd_outl(COLOR_DCC_DCC_CHROMA_GAIN_LIMIT_SUB_1_reg, color_dcc_dcc_chroma_gain_limit_sub_1_reg.regValue);
	}
#endif

}


void drvif_color_set_dcc_Luma_offset(unsigned char display, UINT8 offset_level)
{
	color_dcc_dcc_ctrl_luma_RBUS color_dcc_dcc_ctrl_luma_Reg;
	color_dcc_dcc_ctrl_luma_Reg.regValue = rtd_inl(COLOR_DCC_DCC_CTRL_LUMA_reg);

	if (display == SLR_MAIN_DISPLAY) {
		color_dcc_dcc_ctrl_luma_Reg.luma_offset_main = offset_level;
	}
#ifdef VIP_CONFIG_DUAL_CHANNEL
	else {
		color_dcc_dcc_ctrl_luma_Reg.luma_offset_sub = offset_level;
	}
#endif

	scaler_rtd_outl(COLOR_DCC_DCC_CTRL_LUMA_reg, color_dcc_dcc_ctrl_luma_Reg.regValue);

}

void drvif_color_get_dcc_current_curve(UINT32 *pCurveNode, UINT32 nodenum, unsigned char display)
{
	UINT32 dcc_decode[129] = {0};

	/*for ( i = 0; i < 16; i++ )
	{
		if (i < 8)
		{
			dcc_decode_temp = rtd_inl(COLOR_DCC_DM_INTERP_DATA_00_reg+i*4);
		}
		else
		{
			dcc_decode_temp = rtd_inl(COLOR_DCC_DM_INTERP_DATA_40_reg+(i-8)*4);
		}

		dcc_decode[(i << 1)] = ((dcc_decode_temp & 0xffff0000)>>16);
		dcc_decode[(i << 1)+1] = ((dcc_decode_temp & 0x0000ff00)>>8)+dcc_decode[(i << 1)];
		dcc_decode[(i << 1)+2] = ((dcc_decode_temp & 0x000000ff)>>0)+dcc_decode[(i << 1)+1];
	}*/

	int i, index;
	int timeout = 10;
	/*int DCCNum = 64;*/ /*this is controled by DCC segment*/
	int DCCNum = nodenum >> 1;

	color_dcc_sram_tab_ctl_0_RBUS	              color_dcc_sram_tab_ctl_0_reg;
	color_dcc_sram_tab_ctl_0_RBUS 		       color_dcc_dcc_y_sram_tab_ctl_reg;
	color_dcc_sram_tab_port_RBUS 	              color_dcc_sram_tab_port_reg;
	color_dcc_sram_tab_port_RBUS     	       color_dcc_dcc_y_sram_tab_port_reg;

	memset(pCurveNode, 0, sizeof(UINT32)*nodenum);

	if (display == SLR_MAIN_DISPLAY) {

		color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_index = 0;
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 2;
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_sel = 0; /* main table 1*/
		rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);

		index = -1;
		for (i = 0; i < DCCNum; i++) {
			do {
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				} while ((color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_ready != 1) && ((timeout--) > 0));

			if (timeout < 0) {
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
				rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
				VIPprintf("drvif_color_get_dcc_current_curve Failed!!");
				return;
			}
			index++;
			if (index != color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_index_cur) {
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
				rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
				return;
			}

			color_dcc_dcc_y_sram_tab_port_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_PORT_reg);

			dcc_decode[(i << 1)] = color_dcc_dcc_y_sram_tab_port_reg.sram_tab_base;
			dcc_decode[(i << 1) + 1] = color_dcc_dcc_y_sram_tab_port_reg.sram_tab_g0 + dcc_decode[(i << 1)];
			dcc_decode[(i << 1) + 2] = color_dcc_dcc_y_sram_tab_port_reg.sram_tab_g1 + dcc_decode[(i << 1) + 1];

		}

		color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
		rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);

	}

#ifdef VIP_CONFIG_DUAL_CHANNEL
	else {
		color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_index = 0;
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 2;
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_sel = 2; /* sub table 1*/
		rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);

		index = -1;
		for (i = 0; i < DCCNum; i++) {
			do {
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				} while ((color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_ready != 1) && ((timeout--) > 0));

			if (timeout < 0) {
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
				rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
				VIPprintf("drvif_color_get_dcc_current_curve Failed!!");
				return;
			}

			index++;
			if (index != color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_acc_index_cur) {     /*cur = index*/
				color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
				color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
				rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
				return;
			}

			color_dcc_dcc_y_sram_tab_port_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_PORT_reg);

			dcc_decode[(i << 1)] = color_dcc_dcc_y_sram_tab_port_reg.sram_tab_base;
			dcc_decode[(i << 1) + 1] = color_dcc_dcc_y_sram_tab_port_reg.sram_tab_g0 + dcc_decode[(i << 1)];
			dcc_decode[(i << 1) + 2] = color_dcc_dcc_y_sram_tab_port_reg.sram_tab_g1 + dcc_decode[(i << 1) + 1];

		}

		color_dcc_dcc_y_sram_tab_ctl_reg.regValue = rtd_inl(COLOR_DCC_SRAM_TAB_CTL_0_reg);
		color_dcc_dcc_y_sram_tab_ctl_reg.sram_tab_rw_sel = 0;
		rtd_outl(COLOR_DCC_SRAM_TAB_CTL_0_reg, color_dcc_dcc_y_sram_tab_ctl_reg.regValue);
	}
#endif

	memcpy(pCurveNode, dcc_decode, sizeof(UINT32)*(nodenum > 129 ? 129 : nodenum));
}

void drvif_color_DCC_ctrl_YUV2RGB(unsigned char data_format_sel, unsigned char data_range_sel)
{
	color_dcc_d_dcc_skin_tone_en_RBUS d_dcc_skin_tone_en_reg;

	d_dcc_skin_tone_en_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_SKIN_TONE_EN_reg);

//	d_dcc_skin_tone_en_reg.data_format_sel = data_format_sel;// mac5 dcc remove, no exist
//	d_dcc_skin_tone_en_reg.data_range_sel = data_range_sel;// mac5 dcc remove, no exist

	rtd_outl(COLOR_DCC_D_DCC_SKIN_TONE_EN_reg, d_dcc_skin_tone_en_reg.regValue);
}

// 20170818 add by robin: add skin tone user curve
void drvif_color_set_dcc_Skin_Tone_User_Curve(Color_Independent_USER_CURVE *ptr)
{
	unsigned char i = 0;
	int index, timeout = 10;
	int DCCNum = TableSeg_num_Max;/*this is controlled by DCC segment*/

	/* initialize table of DCC Curve*/
	color_dcc_d_dcc_ctrl_RBUS	 	color_dcc_d_dcc_ctrl_reg;
	color_dcc_d_dcc_ctrl_reg.regValue = rtd_inl(COLOR_DCC_D_DCC_CTRL_reg);
	DCCNum = DCCNum >> color_dcc_d_dcc_ctrl_reg.main_table_segment;

	// 20170926 robin for user curve table
	/*o---DCC User Curve Table init for Main channel---o*/
	color_dcc_sram_user_tab_ctl_0_RBUS color_dcc_sram_user_tab_ctl_0_reg;
	color_dcc_sram_user_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_USER_TAB_CTL_0_reg);
	color_dcc_sram_user_tab_ctl_0_reg.sram_user_tab_acc_index = 0;
	color_dcc_sram_user_tab_ctl_0_reg.sram_user_tab_rw_sel      = 1;
	color_dcc_sram_user_tab_ctl_0_reg.sram_user_tab_acc_sel    = 0;
	rtd_outl(COLOR_DCC_SRAM_USER_TAB_CTL_0_reg, color_dcc_sram_user_tab_ctl_0_reg.regValue);		

	/*o---- Double Buffer Setting -----o*/
	color_dcc_d_dcc_db_ctrl_RBUS color_dcc_d_dcc_db_ctrl_reg;
	color_dcc_d_dcc_db_ctrl_reg.regValue       = rtd_inl(COLOR_DCC_D_DCC_DB_CTRL_reg);
	color_dcc_d_dcc_db_ctrl_reg.db_en           = 0;
	color_dcc_d_dcc_db_ctrl_reg.db_read_level = 0;
	rtd_outl(COLOR_DCC_D_DCC_DB_CTRL_reg, color_dcc_d_dcc_db_ctrl_reg.regValue);

	color_dcc_sram_user_tab_port_RBUS color_dcc_sram_user_tab_port_reg;
	index = -1;
	for (i = 0; i < DCCNum; i++)
	{
		do
		{
			color_dcc_sram_user_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_USER_TAB_CTL_0_reg);
		} while ((color_dcc_sram_user_tab_ctl_0_reg.sram_user_tab_acc_ready != 1) && ((timeout--) > 0));

		if (timeout < 0)
		{
			color_dcc_sram_user_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_USER_TAB_CTL_0_reg);
			color_dcc_sram_user_tab_ctl_0_reg.sram_user_tab_rw_sel = 0;
			rtd_outl(COLOR_DCC_SRAM_USER_TAB_CTL_0_reg, color_dcc_sram_user_tab_ctl_0_reg.regValue);
			VIPprintf("DCC Init. Write DCC User Init Table Fault!!");
			return;
		}
		index++;
		if (index != color_dcc_sram_user_tab_ctl_0_reg.sram_user_tab_acc_index_cur)    /*cur != index*/
		{
			color_dcc_sram_user_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_USER_TAB_CTL_0_reg);
			color_dcc_sram_user_tab_ctl_0_reg.sram_user_tab_rw_sel = 0;
			rtd_outl(COLOR_DCC_SRAM_USER_TAB_CTL_0_reg, color_dcc_sram_user_tab_ctl_0_reg.regValue);
			return;
		}

		int base = ptr->skin_tone_user_curve_table[2*index];
		if ((index == 0) && (base < 0))
			base += (DataRange_MAX+1);
		if ((index == (DCCNum-1)) && (base > DataRange_MAX))
			base -= (DataRange_MAX+1);
		
		color_dcc_sram_user_tab_port_reg.sram_user_tab_base = base;
		color_dcc_sram_user_tab_port_reg.sram_user_tab_g0 = ptr->skin_tone_user_curve_table[2*index+1] - ptr->skin_tone_user_curve_table[2*index];
		color_dcc_sram_user_tab_port_reg.sram_user_tab_g1 = index == (DCCNum-1) ? DataRange_MAX - ptr->skin_tone_user_curve_table[2*index+1] :
																			ptr->skin_tone_user_curve_table[2*index+2] - ptr->skin_tone_user_curve_table[2*index+1];

		rtd_outl(COLOR_DCC_SRAM_USER_TAB_PORT_reg, color_dcc_sram_user_tab_port_reg.regValue); //Mac5p 10bits
	}

	color_dcc_sram_user_tab_ctl_0_reg.regValue = rtd_inl(COLOR_DCC_SRAM_USER_TAB_CTL_0_reg);
	color_dcc_sram_user_tab_ctl_0_reg.sram_user_tab_rw_sel = 0;
	rtd_outl(COLOR_DCC_SRAM_USER_TAB_CTL_0_reg, color_dcc_sram_user_tab_ctl_0_reg.regValue);
}