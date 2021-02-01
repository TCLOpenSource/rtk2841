#include <linux/module.h>
#include <linux/string.h>
#include <linux/moduleparam.h>
#include <linux/types.h>    /* size_t         */
#include <linux/export.h>
#include <linux/cdev.h>
#include <linux/semaphore.h>

#include <mach/system.h>
#include <rbus/osdovl_reg.h>
#include <rbus/ppoverlay_reg.h>
#include <gal/rtk_gdma_driver.h>
//for WBSKTASKWBS-1768 : OSD Scale up issue
#define USE_OSD_SR_ZERO_POS 1
extern gdma_dev *gdma_devices;
extern int gdma_nr_devs;


/* for OSD shift function */
extern CONFIG_OSDSHIFT_STRUCT g_osdshift_ctrl;

/* ------------------------------------- */
/*           Super Resolution            */
/* ------------------------------------- */
void drv_superresolution_init(void)
{
	line_buffer_end_RBUS line_buffer_end_reg;
	osd_sr_1_gainmap_ctrl0_RBUS osd_sr1_gainmap_ctl0_reg;

	/*
	osd_sr switch
	*/
	line_buffer_end_reg.regValue = 0;
	line_buffer_end_reg.osdsr1_switch_to = GDMA_PLANE_OSD1;
	line_buffer_end_reg.osdsr2_switch_to = GDMA_PLANE_OSD3;
	rtd_outl(GDMA_line_buffer_end_reg, line_buffer_end_reg.regValue);


	/*
	coefficients
	*/ /* Yvonne:Maybe need to modify */
	/* rtd_outl( OSD_SR_HCOEFF_VADDR, 0x00043804 ); */
	/* rtd_outl( OSD_SR_VCOEFF_VADDR , 0x00043804 ); */

	/*
	reg_vc_sr_lpf_range_en=1;
	reg_vc_sr_lpf_range_step=3;
	reg_vc_sr_lpf_edge_en=1;
	reg_vc_sr_lpf_edge_step=0;
	*/
	osd_sr1_gainmap_ctl0_reg.regValue = rtd_inl(OSD_SR_1_GainMap_Ctrl0_reg);
	osd_sr1_gainmap_ctl0_reg.sr_lpf_range_en = 1;
	osd_sr1_gainmap_ctl0_reg.sr_lpf_range_step = 3;
	osd_sr1_gainmap_ctl0_reg.sr_lpf_edge_en = 1;
	osd_sr1_gainmap_ctl0_reg.sr_lpf_edge_step = 0;
	rtd_outl(OSD_SR_1_GainMap_Ctrl0_reg, osd_sr1_gainmap_ctl0_reg.regValue);
	rtd_outl(OSD_SR_2_GainMap_Ctrl0_reg, osd_sr1_gainmap_ctl0_reg.regValue);

}

void drv_superresolution_LPF_Gain(GDMA_DISPLAY_PLANE disPlane)
{
	uint32_t offset = 0;
	osd_sr_1_ctrl_RBUS osd_sr_ctrl_reg;
	osd_sr_1_gainy_ctrl0_RBUS osd_sr_gainy_ctrl0_reg;
	osd_sr_1_gainmap_ctrl0_RBUS osd_sr_gainmap_ctrl_reg;
	line_buffer_end_RBUS line_buffer_end_reg;
	*(u32 *)&line_buffer_end_reg = 0;

	*(unsigned int *)&line_buffer_end_reg = rtd_inl(GDMA_line_buffer_end_reg);
	line_buffer_end_reg.regValue = rtd_inl(GDMA_line_buffer_end_reg);
	if (line_buffer_end_reg.osdsr1_switch_to == disPlane)
		offset = 0x0;
	else if (line_buffer_end_reg.osdsr2_switch_to == disPlane)
		offset = 0x80;

	osd_sr_ctrl_reg.regValue = rtd_inl(OSD_SR_1_Ctrl_reg+offset);
	osd_sr_ctrl_reg.sr_maxmin_limit_en = 1;
	osd_sr_ctrl_reg.sr_maxmin_shift = 0x20;
	osd_sr_ctrl_reg.sr_var_thd = 0x20;
	rtd_outl(OSD_SR_1_Ctrl_reg+offset, osd_sr_ctrl_reg.regValue);

	osd_sr_gainy_ctrl0_reg.regValue = rtd_inl(OSD_SR_1_GainY_Ctrl0_reg+offset);
	osd_sr_gainy_ctrl0_reg.sr_lpf_gain = 0x1f;
	rtd_outl(OSD_SR_1_GainY_Ctrl0_reg+offset, osd_sr_gainy_ctrl0_reg.regValue);

	osd_sr_gainmap_ctrl_reg.regValue = rtd_inl(OSD_SR_1_GainMap_Ctrl0_reg+offset);
	osd_sr_gainmap_ctrl_reg.sr_lpf_edge_step = 0x0;
	osd_sr_gainmap_ctrl_reg.sr_lpf_range_en = 1;
	osd_sr_gainmap_ctrl_reg.sr_lpf_range_step = 1;
	osd_sr_gainmap_ctrl_reg.sr_lpf_range_thd = 0x8;
	rtd_outl(OSD_SR_1_GainMap_Ctrl0_reg+offset, osd_sr_gainmap_ctrl_reg.regValue);


}

void drv_superresolution_LPF_Gain_Disable(GDMA_DISPLAY_PLANE disPlane)
{
	uint32_t offset = 0;
	osd_sr_1_ctrl_RBUS osd_sr_ctrl_reg;
	osd_sr_1_gainy_ctrl0_RBUS osd_sr_gainy_ctrl0_reg;
	osd_sr_1_gainmap_ctrl0_RBUS osd_sr_gainmap_ctrl_reg;
	line_buffer_end_RBUS line_buffer_end_reg;
	*(u32 *)&line_buffer_end_reg = 0;

	*(unsigned int *)&line_buffer_end_reg = rtd_inl(GDMA_line_buffer_end_reg);
	line_buffer_end_reg.regValue = rtd_inl(GDMA_line_buffer_end_reg);
	if (line_buffer_end_reg.osdsr1_switch_to == disPlane)
		offset = 0x0;
	else if (line_buffer_end_reg.osdsr2_switch_to == disPlane)
		offset = 0x80;

	osd_sr_ctrl_reg.regValue = rtd_inl(OSD_SR_1_Ctrl_reg+offset);
	osd_sr_ctrl_reg.sr_maxmin_limit_en = 1;
	osd_sr_ctrl_reg.sr_maxmin_shift = 0x0;
	osd_sr_ctrl_reg.sr_var_thd = 0x40;
	rtd_outl(OSD_SR_1_Ctrl_reg+offset, osd_sr_ctrl_reg.regValue);

	osd_sr_gainy_ctrl0_reg.regValue = rtd_inl(OSD_SR_1_GainY_Ctrl0_reg+offset);
	osd_sr_gainy_ctrl0_reg.sr_lpf_gain = 0x0;
	rtd_outl(OSD_SR_1_GainY_Ctrl0_reg+offset, osd_sr_gainy_ctrl0_reg.regValue);

	osd_sr_gainmap_ctrl_reg.regValue = rtd_inl(OSD_SR_1_GainMap_Ctrl0_reg+offset);
	osd_sr_gainmap_ctrl_reg.sr_lpf_edge_step = 0x3;
	osd_sr_gainmap_ctrl_reg.sr_lpf_range_en = 0;
	osd_sr_gainmap_ctrl_reg.sr_lpf_range_step = 0;
	osd_sr_gainmap_ctrl_reg.sr_lpf_range_thd = 0x0;
	rtd_outl(OSD_SR_1_GainMap_Ctrl0_reg+offset, osd_sr_gainmap_ctrl_reg.regValue);

}


void drv_superresolution_ch_switch(GDMA_DISPLAY_PLANE src, OSD_SR_CH_SEL dest)
{
	line_buffer_end_RBUS line_buffer_end_reg;

	line_buffer_end_reg.regValue = rtd_inl(GDMA_line_buffer_end_reg);

	if (dest == OSD1_SR)
		line_buffer_end_reg.osdsr1_switch_to = src;
	else if (dest == OSD2_SR)
		line_buffer_end_reg.osdsr2_switch_to = src;
	rtd_outl(GDMA_line_buffer_end_reg, line_buffer_end_reg.regValue);
}


/* ------------------------------------- */
/*           Super Resolution            */
/* ------------------------------------- */
void drv_scaleup_init(void)
{
	osd_sr_1_scaleup_ctrl0_RBUS osd_sr1_scaleup_ctrl0_reg;

	osd_sr1_scaleup_ctrl0_reg.regValue = rtd_inl(OSD_SR_1_Scaleup_Ctrl0_reg);
	osd_sr1_scaleup_ctrl0_reg.v_zoom_en = 0;
	osd_sr1_scaleup_ctrl0_reg.ver_ini = 0xff;
	osd_sr1_scaleup_ctrl0_reg.ver_factor = 0;

	rtd_outl(OSD_SR_1_Scaleup_Ctrl0_reg, osd_sr1_scaleup_ctrl0_reg.regValue);
	rtd_outl(OSD_SR_2_Scaleup_Ctrl0_reg, osd_sr1_scaleup_ctrl0_reg.regValue);
}

int drv_scaleup(uint8_t enable, GDMA_DISPLAY_PLANE disPlane)
{
	gdma_dev *gdma = &gdma_devices[0];
	line_buffer_end_RBUS line_buffer_end_reg;
	unsigned int offset = 0;
	GDMA_PIC_DATA *curPic;
	GDMA_REG_CONTENT *pReg = NULL;

	curPic = gdma->pic[disPlane] + gdma->curPic[disPlane];
	pReg = &curPic->reg_content;

	*(unsigned int *)&line_buffer_end_reg = rtd_inl(GDMA_line_buffer_end_reg);
	line_buffer_end_reg.regValue = rtd_inl(GDMA_line_buffer_end_reg);
	if (line_buffer_end_reg.osdsr1_switch_to == disPlane)
		offset = 0x0;
	else if (line_buffer_end_reg.osdsr2_switch_to == disPlane)
		offset = 0x80;
	else {
		DBG_SR_PRINT(KERN_EMERG"%s, No match with OSDSRx_switch_to to OSD%d !! \n", __FUNCTION__, disPlane) ;
		return GDMA_SUCCESS;
	}


	DBG_SR_PRINT(KERN_EMERG"%s, line_buffer_end_reg=0x%x\n", __FUNCTION__, line_buffer_end_reg.regValue) ;

	if (enable) {
		rtd_outl(OSD_SR_1_Scaleup_Ctrl0_reg+offset, pReg->osd_sr_scaleup_ctrl0_reg.regValue);
		rtd_outl(OSD_SR_1_Scaleup_Ctrl1_reg+offset, pReg->osd_sr_scaleup_ctrl1_reg.regValue);
		rtd_outl(OSD_SR_1_V_Location_Ctrl_reg+offset, pReg->osd_sr_v_location_ctrl_reg.regValue);
		rtd_outl(OSD_SR_1_H_Location_Ctrl_reg+offset, pReg->osd_sr_h_location_ctrl_reg.regValue);

		/* enhance OSD sharpness by designer suggestion */
		rtd_outl(OSD_SR_1_Ctrl_reg+offset, pReg->osd_sr_ctrl_reg.regValue);
		rtd_outl(OSD_SR_1_GainY_Ctrl0_reg+offset, pReg->osd_sr_gainy_ctrl0_reg.regValue);
		rtd_outl(OSD_SR_1_GainMap_Ctrl0_reg+offset, pReg->osd_sr_gainmap_ctrl_reg.regValue);

		if ((pReg->osd_sr_scaleup_ctrl1_reg.h_zoom_en != 0) || (pReg->osd_sr_scaleup_ctrl0_reg.v_zoom_en != 0))
			fwif_color_set_scaleosd_sharpness_driver(0, 1);
		else
			fwif_color_set_scaleosd_sharpness_driver(0, 0);

		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_Scaleup_Ctrl0_reg[0x%x]        0x%x\n", OSD_SR_1_Scaleup_Ctrl0_reg+offset, rtd_inl(OSD_SR_1_Scaleup_Ctrl0_reg+offset)) ;
		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_Scaleup_Ctrl1_reg[0x%x]        0x%x\n", OSD_SR_1_Scaleup_Ctrl1_reg+offset, rtd_inl(OSD_SR_1_Scaleup_Ctrl1_reg+offset)) ;
		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_V_Location_Ctrl_reg[0x%x]        0x%x\n", OSD_SR_1_V_Location_Ctrl_reg+offset, rtd_inl(OSD_SR_1_V_Location_Ctrl_reg+offset)) ;
		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_H_Location_Ctrl_reg[0x%x]        0x%x\n", OSD_SR_1_H_Location_Ctrl_reg+offset, rtd_inl(OSD_SR_1_H_Location_Ctrl_reg+offset)) ;
	} else {
		/*  OSD_SR 1/2/3 disable */
		rtd_outl(OSD_SR_1_Scaleup_Ctrl0_reg+offset, pReg->osd_sr_scaleup_ctrl0_reg.regValue);
		rtd_outl(OSD_SR_1_Scaleup_Ctrl1_reg+offset, pReg->osd_sr_scaleup_ctrl1_reg.regValue);
		rtd_outl(OSD_SR_1_V_Location_Ctrl_reg+offset, pReg->osd_sr_v_location_ctrl_reg.regValue);
		rtd_outl(OSD_SR_1_H_Location_Ctrl_reg+offset, pReg->osd_sr_h_location_ctrl_reg.regValue);

		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_Scaleup_Ctrl0_reg[0x%x]        0x%x\n", OSD_SR_1_Scaleup_Ctrl0_reg+offset, rtd_inl(OSD_SR_1_Scaleup_Ctrl0_reg+offset)) ;
		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_Scaleup_Ctrl1_reg[0x%x]        0x%x\n", OSD_SR_1_Scaleup_Ctrl1_reg+offset, rtd_inl(OSD_SR_1_Scaleup_Ctrl1_reg+offset)) ;
		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_V_Location_Ctrl_reg[0x%x]		 0x%x\n", OSD_SR_1_V_Location_Ctrl_reg+offset, rtd_inl(OSD_SR_1_V_Location_Ctrl_reg+offset)) ;
		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_H_Location_Ctrl_reg[0x%x]		 0x%x\n", OSD_SR_1_H_Location_Ctrl_reg+offset, rtd_inl(OSD_SR_1_H_Location_Ctrl_reg+offset)) ;
	}


	return GDMA_SUCCESS;
}

int drv_PreScale(uint8_t enable, VO_RECTANGLE srcWin, VO_RECTANGLE dispWin,
		GDMA_DISPLAY_PLANE disPlane, struct gdma_receive_work *ptr_work)
{
	gdma_dev *gdma = &gdma_devices[0];
	line_buffer_end_RBUS line_buffer_end_reg;
	osd_sr_1_scaleup_ctrl0_RBUS osd_sr_scaleup_ctrl0_reg;
	osd_sr_1_scaleup_ctrl1_RBUS osd_sr_scaleup_ctrl1_reg;
	osd_sr_1_h_location_ctrl_RBUS osd_sr_h_location_ctrl_reg;
	osd_sr_1_v_location_ctrl_RBUS osd_sr_v_location_ctrl_reg;
	osd_sr_osd_bypass_3_location_ctrl_RBUS osd_bypass_location_ctrl_reg;
	osd_sr_1_ctrl_RBUS osd_sr_ctrl_reg;
	osd_sr_1_gainy_ctrl0_RBUS osd_sr_gainy_ctrl0_reg;
	osd_sr_1_gainmap_ctrl0_RBUS osd_sr_gainmap_ctrl_reg;
	unsigned int ver_factor = 0;
	unsigned int hor_factor = 0;
	unsigned int offset = 0, bypass_flag = 0;
	GDMA_PIC_DATA *curPic;
	GDMA_REG_CONTENT *pReg = NULL;

	curPic = gdma->pic[disPlane] + ptr_work->picQwr;
	pReg = &curPic->reg_content;

	*(unsigned int *)&line_buffer_end_reg = rtd_inl(GDMA_line_buffer_end_reg);
	line_buffer_end_reg.regValue = rtd_inl(GDMA_line_buffer_end_reg);
	if (line_buffer_end_reg.osdsr1_switch_to == disPlane)
		offset = 0x0;
	else if (line_buffer_end_reg.osdsr2_switch_to == disPlane)
		offset = 0x80;

	DBG_SR_PRINT(KERN_EMERG"%s, line_buffer_end_reg=0x%x\n", __FUNCTION__, line_buffer_end_reg.regValue);

	if (bypass_flag == 0) {
		/* disable LPF and set back to default value when scaling function is NOT enable */
		osd_sr_ctrl_reg.regValue = rtd_inl(OSD_SR_1_Ctrl_reg+offset);
		osd_sr_ctrl_reg.sr_maxmin_limit_en = 1;
		osd_sr_ctrl_reg.sr_maxmin_shift = 0x0;
		osd_sr_ctrl_reg.sr_var_thd = 0x40;
		pReg->osd_sr_ctrl_reg.regValue = osd_sr_ctrl_reg.regValue;

		osd_sr_gainy_ctrl0_reg.regValue = rtd_inl(OSD_SR_1_GainY_Ctrl0_reg+offset);
		osd_sr_gainy_ctrl0_reg.sr_lpf_gain = 0x0;
		pReg->osd_sr_gainy_ctrl0_reg.regValue = osd_sr_gainy_ctrl0_reg.regValue;

		osd_sr_gainmap_ctrl_reg.regValue = rtd_inl(OSD_SR_1_GainMap_Ctrl0_reg+offset);
		osd_sr_gainmap_ctrl_reg.sr_lpf_edge_step = 0x3;
		osd_sr_gainmap_ctrl_reg.sr_lpf_range_en = 0;
		osd_sr_gainmap_ctrl_reg.sr_lpf_range_step = 0;
		osd_sr_gainmap_ctrl_reg.sr_lpf_range_thd = 0x0;
		pReg->osd_sr_gainmap_ctrl_reg.regValue = osd_sr_gainmap_ctrl_reg.regValue;
	}

	if (enable && (bypass_flag == 0)) {
		osd_sr_scaleup_ctrl0_reg.v_zoom_en = 0;
#if USE_OSD_SR_ZERO_POS
		if (g_osdshift_ctrl.shift_v_enable && disPlane == (GDMA_DISPLAY_PLANE)g_osdshift_ctrl.plane)
		{
			if (g_osdshift_ctrl.v_shift_pixel > 0)	// shift down
			{
				osd_sr_scaleup_ctrl0_reg.ver_ini = 0xff;
			}else	// shift up
			{
				if ( g_osdshift_ctrl.para_v_K)
					osd_sr_scaleup_ctrl0_reg.ver_ini = 0x7f;
				else
			osd_sr_scaleup_ctrl0_reg.ver_ini = 0xff;
			}
		}else
			osd_sr_scaleup_ctrl0_reg.ver_ini = 0xff;

#else
		osd_sr_scaleup_ctrl0_reg.ver_ini = 0;
#endif
		osd_sr_scaleup_ctrl0_reg.ver_factor = 0;
		pReg->osd_sr_scaleup_ctrl0_reg.regValue = osd_sr_scaleup_ctrl0_reg.regValue;

		osd_sr_scaleup_ctrl1_reg.h_zoom_en = 0;
#if USE_OSD_SR_ZERO_POS
		if (g_osdshift_ctrl.shift_h_enable && disPlane == (GDMA_DISPLAY_PLANE)g_osdshift_ctrl.plane)
		{
			if (g_osdshift_ctrl.h_shift_pixel > 0)	// shift right
			{
				osd_sr_scaleup_ctrl1_reg.hor_ini = 0xff;
			}else	// shift left
			{
				if ( g_osdshift_ctrl.para_h_K)
					osd_sr_scaleup_ctrl1_reg.hor_ini = 0x7f;
				else
					osd_sr_scaleup_ctrl1_reg.hor_ini = 0xff;
			}
		}
		else
		osd_sr_scaleup_ctrl1_reg.hor_ini = 0xff;
#else
		osd_sr_scaleup_ctrl1_reg.hor_ini = 0;
#endif
		osd_sr_scaleup_ctrl1_reg.hor_factor = 0;
		pReg->osd_sr_scaleup_ctrl1_reg.regValue = osd_sr_scaleup_ctrl1_reg.regValue;


		if (g_osdshift_ctrl.shift_v_enable && disPlane == (GDMA_DISPLAY_PLANE)g_osdshift_ctrl.plane){
			osd_sr_v_location_ctrl_reg.osd_height = dispWin.height-abs(g_osdshift_ctrl.v_shift_pixel);
			dispWin.height -= abs(g_osdshift_ctrl.v_shift_pixel);
			if ((g_osdshift_ctrl.v_shift_pixel > 0)) {
				// shift down
				osd_sr_v_location_ctrl_reg.osd_v_sta = dispWin.y+g_osdshift_ctrl.v_shift_pixel;
			} else {
		osd_sr_v_location_ctrl_reg.osd_v_sta = dispWin.y;
			}
		} else if (g_osdshift_ctrl.shift_v_enable && disPlane == GDMA_PLANE_OSD3) {
		osd_sr_v_location_ctrl_reg.osd_height = dispWin.height;
			if ((g_osdshift_ctrl.v_shift_pixel > 0)) {
				// shift down
				//osd_sr_v_location_ctrl_reg.osd_v_sta = dispWin.y+g_osdshift_ctrl.v_shift_pixel;
				osd_sr_v_location_ctrl_reg.osd_v_sta = dispWin.y;
			} else {
				osd_sr_v_location_ctrl_reg.osd_v_sta = dispWin.y;
			}
		}else{
			osd_sr_v_location_ctrl_reg.osd_height = dispWin.height;
			osd_sr_v_location_ctrl_reg.osd_v_sta = dispWin.y;
		}
		pReg->osd_sr_v_location_ctrl_reg.regValue = osd_sr_v_location_ctrl_reg.regValue;



		if (g_osdshift_ctrl.shift_h_enable && disPlane == (GDMA_DISPLAY_PLANE)g_osdshift_ctrl.plane){
			osd_sr_h_location_ctrl_reg.osd_width = dispWin.width-abs(g_osdshift_ctrl.h_shift_pixel);
			dispWin.width -= abs(g_osdshift_ctrl.h_shift_pixel);

			if(g_osdshift_ctrl.h_shift_pixel > 0) {
				// shift right
				osd_sr_h_location_ctrl_reg.osd_h_sta = dispWin.x+g_osdshift_ctrl.h_shift_pixel;
				//osd_sr_h_location_ctrl_reg.osd_h_sta = dispWin.x;
			}else{
				osd_sr_h_location_ctrl_reg.osd_h_sta = dispWin.x;
			}
		} else if (g_osdshift_ctrl.shift_h_enable && disPlane == GDMA_PLANE_OSD3) {
			osd_sr_h_location_ctrl_reg.osd_width = dispWin.width;
			if(g_osdshift_ctrl.h_shift_pixel > 0) {
				// shift right
				//osd_sr_h_location_ctrl_reg.osd_h_sta = dispWin.x+g_osdshift_ctrl.h_shift_pixel;
				osd_sr_h_location_ctrl_reg.osd_h_sta = dispWin.x;
			}else{
				osd_sr_h_location_ctrl_reg.osd_h_sta = dispWin.x;
			}

		}else {
			osd_sr_h_location_ctrl_reg.osd_width = dispWin.width;
			osd_sr_h_location_ctrl_reg.osd_h_sta = dispWin.x;
		}
		pReg->osd_sr_h_location_ctrl_reg.regValue = osd_sr_h_location_ctrl_reg.regValue;

		/*
		OSD_H_STA+OSD_WIDTH , OSD_V_STA+OSD_HEIGHT < video range
		input_width >=16
		*/
		if (srcWin.width == 0 || srcWin.height == 0 || dispWin.width == 0 || dispWin.height == 0) {
			pr_debug("GDMA division by :srcWin.width = %d,srcWin.height=%d\n", srcWin.width, srcWin.height) ;
			pr_debug("GDMA division by :dispWin.width = %d,dispWin.height=%d\n", dispWin.width, dispWin.height) ;
		}
		DBG_SR_PRINT("%s:srcWin.width = %d,srcWin.height=%d\n", __FUNCTION__, srcWin.width, srcWin.height) ;
		DBG_SR_PRINT("%s:dispWin.width = %d,dispWin.height=%d\n", __FUNCTION__, dispWin.width, dispWin.height) ;

		/* online mode : h_front_porch >= 16, v_back_porch >= 16 */
		if ((((dispWin.x+dispWin.width) > (gdma->dispWin[disPlane].width+1)) ||
			 ((dispWin.y+dispWin.height) > (gdma->dispWin[disPlane].height+1)))) {
			/* Under flow */

			pr_debug("%s:dispWin.x = %d,dispWin.y=%d\n", __FUNCTION__, dispWin.x, dispWin.y) ;
			pr_debug("%s:dispWin.width = %d,dispWin.height=%d\n", __FUNCTION__, dispWin.width, dispWin.height) ;
			pr_debug("%s:gdma->dispWin[%d].width = %d,gdma->dispWin[%d].height=%d\n", __FUNCTION__,
				   disPlane, gdma->dispWin[disPlane].width, disPlane, gdma->dispWin[disPlane].height) ;

			pr_debug("%s:data underflow\n", __FUNCTION__) ;
			return -1;
		//} else if ((srcWin.width != dispWin.width) && ((srcWin.width < 16) || (srcWin.height < 4))) {
		//	pr_debug("%s:srcWin.width = %d [>=16], srcWin.height = %d [>=4] \n", __FUNCTION__, srcWin.width, srcWin.height) ;
		//	return -1;
		} else {

			hor_factor = (srcWin.width<<20)/dispWin.width;
			ver_factor = (srcWin.height<<20)/dispWin.height;

			DBG_SR_PRINT(KERN_EMERG"%s hor_factor=0x%x,ver_factor=0x%x\n", __FUNCTION__, hor_factor, ver_factor) ;

			if ((srcWin.height < dispWin.height) && (ver_factor)) { /*  no scaling down */
				osd_sr_scaleup_ctrl0_reg.v_zoom_en = 1;
#if USE_OSD_SR_ZERO_POS
				osd_sr_scaleup_ctrl0_reg.ver_ini = 0xff;
#else
				osd_sr_scaleup_ctrl0_reg.ver_ini = srcWin.y;
#endif
				osd_sr_scaleup_ctrl0_reg.ver_factor = ver_factor;

#if 0			/* OSR_SR auto mode */
				if (srcWin.width <= 2560)
					osd_sr_scaleup_ctrl0_reg.ver_tap_num = 1;
				else if (srcWin.width <= 5120)
					osd_sr_scaleup_ctrl0_reg.ver_tap_num = 2;
				if (osd_sr_scaleup_ctrl0_reg.v_zoom_en == 0)
					osd_sr_scaleup_ctrl0_reg.ver_tap_num = 3;
#endif
				pReg->osd_sr_scaleup_ctrl0_reg.regValue = osd_sr_scaleup_ctrl0_reg.regValue;

				pReg->osd_sr_scaleup_ctrl0_reg.regValue = osd_sr_scaleup_ctrl0_reg.regValue;
			}

			if ((srcWin.width < dispWin.width) && (hor_factor)) { /*  no scaling down */
				osd_sr_scaleup_ctrl1_reg.h_zoom_en = 1;
#if USE_OSD_SR_ZERO_POS
				osd_sr_scaleup_ctrl1_reg.hor_ini = 0xff;
#else
				osd_sr_scaleup_ctrl1_reg.hor_ini = srcWin.x;
#endif
				osd_sr_scaleup_ctrl1_reg.hor_factor = hor_factor;
				pReg->osd_sr_scaleup_ctrl1_reg.regValue = osd_sr_scaleup_ctrl1_reg.regValue;
			}

			/* enhance OSD sharpness by designer suggestion */
			if (osd_sr_scaleup_ctrl0_reg.v_zoom_en || osd_sr_scaleup_ctrl1_reg.h_zoom_en) {
				osd_sr_ctrl_reg.sr_maxmin_limit_en = 1;
				osd_sr_ctrl_reg.sr_maxmin_shift = 0x20;
				osd_sr_ctrl_reg.sr_var_thd = 0x20;
				pReg->osd_sr_ctrl_reg.regValue = osd_sr_ctrl_reg.regValue;

				osd_sr_gainy_ctrl0_reg.sr_lpf_gain = 0x1f;
				pReg->osd_sr_gainy_ctrl0_reg.regValue = osd_sr_gainy_ctrl0_reg.regValue;

				osd_sr_gainmap_ctrl_reg.sr_lpf_edge_step = 0x0;
				osd_sr_gainmap_ctrl_reg.sr_lpf_range_en = 1;
				osd_sr_gainmap_ctrl_reg.sr_lpf_range_step = 1;
				osd_sr_gainmap_ctrl_reg.sr_lpf_range_thd = 0x8;
				pReg->osd_sr_gainmap_ctrl_reg.regValue = osd_sr_gainmap_ctrl_reg.regValue;
			}
		}
		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_Scaleup_Ctrl0_reg[0x%x]        0x%x\n", OSD_SR_1_Scaleup_Ctrl0_reg+offset, pReg->osd_sr_scaleup_ctrl0_reg.regValue) ;
		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_Scaleup_Ctrl1_reg[0x%x]        0x%x\n", OSD_SR_1_Scaleup_Ctrl1_reg+offset, pReg->osd_sr_scaleup_ctrl1_reg.regValue) ;
		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_V_Location_Ctrl_reg[0x%x]        0x%x\n", OSD_SR_1_V_Location_Ctrl_reg+offset, pReg->osd_sr_v_location_ctrl_reg.regValue) ;
		DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_H_Location_Ctrl_reg[0x%x]        0x%x\n", OSD_SR_1_H_Location_Ctrl_reg+offset, pReg->osd_sr_h_location_ctrl_reg.regValue) ;
	} else {
		/*  OSD_SR 4/5 bypass */
		if (bypass_flag == 1) {
			osd_bypass_location_ctrl_reg.osd_h_sta = dispWin.x;
			osd_bypass_location_ctrl_reg.osd_v_sta = dispWin.y;
			pReg->osd_bypass_location_ctrl_reg.regValue = osd_bypass_location_ctrl_reg.regValue;
		}
		/*  OSD_SR 1/2/3 disable */
		else {
			osd_sr_scaleup_ctrl0_reg.v_zoom_en = 0;
			osd_sr_scaleup_ctrl0_reg.ver_ini = 0x00;
			osd_sr_scaleup_ctrl0_reg.ver_factor = 0;
			pReg->osd_sr_scaleup_ctrl0_reg.regValue = osd_sr_scaleup_ctrl0_reg.regValue;

			osd_sr_scaleup_ctrl1_reg.h_zoom_en = 0;
			osd_sr_scaleup_ctrl1_reg.hor_ini = 0;
			osd_sr_scaleup_ctrl1_reg.hor_factor = 0;
			pReg->osd_sr_scaleup_ctrl1_reg.regValue = osd_sr_scaleup_ctrl1_reg.regValue;
			DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_Scaleup_Ctrl0_reg[0x%x]        0x%x\n", OSD_SR_1_Scaleup_Ctrl0_reg+offset, pReg->osd_sr_scaleup_ctrl0_reg.regValue) ;
			DBG_SR_PRINT(KERN_EMERG"OSD_SR_X_Scaleup_Ctrl1_reg[0x%x]        0x%x\n", OSD_SR_1_Scaleup_Ctrl1_reg+offset, pReg->osd_sr_scaleup_ctrl1_reg.regValue) ;

			osd_sr_v_location_ctrl_reg.osd_v_sta = dispWin.y;
			osd_sr_v_location_ctrl_reg.osd_height = dispWin.height;
			pReg->osd_sr_v_location_ctrl_reg.regValue = osd_sr_v_location_ctrl_reg.regValue;

			osd_sr_h_location_ctrl_reg.osd_h_sta = dispWin.x;
			osd_sr_h_location_ctrl_reg.osd_width = dispWin.width;
			pReg->osd_sr_h_location_ctrl_reg.regValue = osd_sr_h_location_ctrl_reg.regValue;
		}
	}


	return GDMA_SUCCESS;
}


int osd_sr_init_module(void)
{
#if 0   /*  no db_ctrl in magellan2 */
	osd_sr_db_ctrl_RBUS osd_sr_db_ctrl_reg;
	osd_sr_db_ctrl_reg.regValue = rtd_inl(OSD_SR_DB_CTRL_VADDR);
	osd_sr_db_ctrl_reg.db_en = 1;
	osd_sr_db_ctrl_reg.db_apply = 0;
	rtd_outl(OSD_SR_DB_CTRL_VADDR, osd_sr_db_ctrl_reg.regValue);
#endif

	drv_superresolution_init();
	drv_scaleup_init();

	return GDMA_SUCCESS;
}

void osd_sr_cleanup_module(void)
{
#if 0   /*  no db_ctrl in magellan2 */
	osd_sr_db_ctrl_RBUS osd_sr_db_ctrl_reg;
	osd_sr_db_ctrl_reg.regValue = rtd_inl(OSD_SR_DB_CTRL_VADDR);
	osd_sr_db_ctrl_reg.db_en = 1;
	osd_sr_db_ctrl_reg.db_apply = 0;
	rtd_outl(OSD_SR_DB_CTRL_VADDR, osd_sr_db_ctrl_reg.regValue);
#endif

	drv_superresolution_init();
	drv_scaleup_init();

}


/** @brief configure OSD location by x,y coordinate and disable H/V_zoom for offline compress process
*   @param disPlane OSD1~5 display plane
*   @param x		x coordinate
*   @param y		y coordinate
*   @return GDMA_SUCCESS
*/
int osd_sr_configLocation(GDMA_DISPLAY_PLANE disPlane, int x, int y)
{
#if 0
	unsigned int offset = 0;
	line_buffer_end_RBUS line_buffer_end_reg;
	osd_sr_1_h_location_ctrl_RBUS osd_sr_h_location;
	osd_sr_1_v_location_ctrl_RBUS osd_sr_v_location;
	osd_sr_osd_bypass_4_location_ctrl_RBUS osd_sr_bypass_location;
	osd_sr_1_scaleup_ctrl0_RBUS osd_sr_scaleup_ctrl0_reg;
	osd_sr_1_scaleup_ctrl1_RBUS osd_sr_scaleup_ctrl1_reg;

	*(unsigned int *)&line_buffer_end_reg = rtd_inl(GDMA_line_buffer_end_reg);
	line_buffer_end_reg.regValue = rtd_inl(GDMA_line_buffer_end_reg);
	if (line_buffer_end_reg.osdsr1_switch_to == disPlane)
		offset = 0x0;
	else if (line_buffer_end_reg.osdsr2_switch_to == disPlane)
		offset = 0x80;

	/*  OSD_SR1/2/3 */
	osd_sr_scaleup_ctrl0_reg.regValue = 0;
	osd_sr_scaleup_ctrl1_reg.regValue = 0;
	osd_sr_h_location.regValue = rtd_inl(OSD_SR_1_H_Location_Ctrl_reg+offset);
	osd_sr_v_location.regValue = rtd_inl(OSD_SR_1_V_Location_Ctrl_reg+offset);
	osd_sr_h_location.osd_h_sta = x;
	osd_sr_v_location.osd_v_sta = y;
	rtd_outl(OSD_SR_1_Scaleup_Ctrl0_reg+offset, osd_sr_scaleup_ctrl0_reg.regValue);
	rtd_outl(OSD_SR_1_Scaleup_Ctrl1_reg+offset, osd_sr_scaleup_ctrl1_reg.regValue);
	rtd_outl(OSD_SR_1_V_Location_Ctrl_reg+offset, osd_sr_v_location.regValue);
	rtd_outl(OSD_SR_1_H_Location_Ctrl_reg+offset, osd_sr_h_location.regValue);
#endif
	return GDMA_SUCCESS ;
}

/** @brief check OSD_SR channel HW on/off status
 *  @param OSD plane
 *  @return 1: OSD_SRx on; 0: OSD_SRx off
*/
int osd_sr_check_onoff_status(GDMA_DISPLAY_PLANE disPlane)
{
	line_buffer_end_RBUS line_buffer_end_reg;
	unsigned int offset = 0, bypass_flag = 0;

	*(unsigned int *)&line_buffer_end_reg = rtd_inl(GDMA_line_buffer_end_reg);
	line_buffer_end_reg.regValue = rtd_inl(GDMA_line_buffer_end_reg);
	if (line_buffer_end_reg.osdsr1_switch_to == disPlane)
		offset = 0x0;
	else if (line_buffer_end_reg.osdsr2_switch_to == disPlane)
		offset = 0x80;

	if (bypass_flag)
		return 0;

	if (OSD_SR_1_Scaleup_Ctrl0_get_v_zoom_en(rtd_inl(OSD_SR_1_Scaleup_Ctrl0_reg+offset)))
		return 1;

	if (OSD_SR_1_Scaleup_Ctrl1_get_h_zoom_en(rtd_inl(OSD_SR_1_Scaleup_Ctrl1_reg+offset)))
		return 1;

	return 0;
}


EXPORT_SYMBOL(osd_sr_cleanup_module);
EXPORT_SYMBOL(drv_superresolution_LPF_Gain);
EXPORT_SYMBOL(osd_sr_init_module);
EXPORT_SYMBOL(drv_scaleup);
EXPORT_SYMBOL(drv_superresolution_ch_switch);
EXPORT_SYMBOL(osd_sr_configLocation);
EXPORT_SYMBOL(osd_sr_check_onoff_status);
