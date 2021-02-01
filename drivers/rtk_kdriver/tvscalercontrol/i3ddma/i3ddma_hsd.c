#include <linux/semaphore.h>
//#include <rbus/scaler/rbusI3DDMA_ScaleDownReg.h>
#include <rbus/h3ddma_hsd_reg.h>

#include <rbus/h3ddma_rgb2yuv_dither_4xxto4xx_reg.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>

#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/i3ddma/i3ddma.h>
#include <tvscalercontrol/i3ddma/i3ddma_uzd.h>


#ifdef RT_DEBUG
#define UltraZoom_Printf(format, args...) 		printf(format, ##args)
#else
#define UltraZoom_Printf(format, args...)
#endif


static unsigned short tRGB2YUV_COEF_709_RGB_0_255[] =
{
    // CCIR 709 RGB
#if 1 // for 0~255
    0x0131,  // m11[10:2] U(9,8)
    0x025c,  // m12   [20:13] U(8,8)
    0x0074,  // m13 [31:23] U(9,8)
#else // for 16~235
    0x0163,  // m11
    0x02bf,   // m12
    0x0087,  // m13
#endif
    0x03D5,   // m21 >> 2 0x01D5 up bits at AT Name: cychen2 , Date: 2010/3/25
    0x0357,   // m22 >> 1
    0x0080,   // m23 >> 2
    0x0080,   // m31 >> 2
    0x0795,   // m32 >> 2 0x0195  up bits at AT Name: cychen2 , Date: 2010/3/25
    0x03D7,   // m33 >> 1
    0x0000,    // Yo_even
    0x0000,    // Yo_odd
    0x0100,    // Y_gain
    0x0001,  // sel_RGB
    0x0000,  // sel_Yin_offset
    0x0001,  // sel_UV_out_offset
    0x0000,  // sel_UV_off
    0x0000,  // Matrix_bypass
    0x0001,  // Enable_Y_gain
};
#if 0//no used
static unsigned short tRGB2YUV_COEF_709_RGB_0_255_OSD_MIXER2[] =
{
    // CCIR 709 RGB

    0x0131,  //m11[10:2] U(9,8)
    0x0074,  // m12->m13
    0x025c,  // m13->m12
    0x03D5,   // m21
    0x0100,   // m22->m23
    0x01a8,   // m23->m22
    0x0080,   // m31
    0x07e8,   // m32->m33
    0x0328,   // m33->m32

    0x0000,    // Yo_even
    0x0000,    // Yo_odd
    0x0100,    // Y_gain
    0x0001,  // sel_RGB
    0x0000,  // sel_Yin_offset
    0x0001,  // sel_UV_out_offset
    0x0000,  // sel_UV_off
    0x0000,  // Matrix_bypass
    0x0001,  // Enable_Y_gain
};



static unsigned short tRGB2YUV_COEF_709_RGB_0_255_SUB_OSD_MIXER1[] =
{
    // CCIR 709 RGB
    0x0074,  // m11->m13
    0x0130,  // m12->m11
    0x025c,  // m13->m12
    0x0080,   // m21->m23
    0x03a8,   // m22->m21
    0x01a8,   // m23->m22
    0x03e8,   // m31->m33
    0x0080,   // m32->m31
    0x0328,   // m33->m32

    0x0000,    // Yo_even
    0x0000,    // Yo_odd
    0x0100,    // Y_gain
    0x0001,  // sel_RGB
    0x0000,  // sel_Yin_offset
    0x0001,  // sel_UV_out_offset
    0x0000,  // sel_UV_off
    0x0000,  // Matrix_bypass
    0x0001,  // Enable_Y_gain
};
#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

static  short tScale_Down_Coef_2tap[] = {
    0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,
    31,  95, 159, 223, 287, 351, 415, 479,
    543, 607, 671, 735, 799, 863, 927, 991,
};

static  short tScale_Down_Coef_Blur[] = {
    2,   3,   5,   7,  10,  15,  20,  28,  38,  49,  64,  81, 101, 124, 150, 178,
    209, 242, 277, 314, 351, 389, 426, 462, 496, 529, 556, 582, 602, 618, 629, 635,
};

static  short tScale_Down_Coef_Mid[] = {
    -2,  0,   1,   2,   5,   9,  15,  22,  32,  45,  60,  77,  98, 122, 149, 179,
    211, 245, 281, 318, 356, 394, 431, 468, 502, 533, 561, 586, 606, 620, 630, 636,
};

static  short tScale_Down_Coef_Sharp[] = {
    -2,   0,   1,   3,   6,  10,  15,  22,  32,  43,  58,  75,  95, 119, 145, 174,
    206, 240, 276, 314, 353, 391, 430, 467, 503, 536, 565, 590, 612, 628, 639, 646,
};


static  short *tScaleDown_COEF_TAB[] =
{
    tScale_Down_Coef_Blur,     tScale_Down_Coef_Mid,     tScale_Down_Coef_Sharp,     tScale_Down_Coef_2tap
};


void I3DDMA_color_colorspacergb2yuvtransfer(DISPD_CAP_SRC idmaDispD_in_sel)
{
	unsigned short *table_index = 0;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_ctrl_RBUS  i3ddma_rgb2yuv_ctrl_reg;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m11_m12_RBUS tab2_M11_M12_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m13_m21_RBUS tab2_M13_M21_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m22_m23_RBUS tab2_M22_M23_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m31_m32_RBUS tab2_M31_M32_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_m33_ygain_RBUS tab2_M33_YGain_REG;
	h3ddma_rgb2yuv_dither_4xxto4xx_hdmi_rgb2yuv_tab1_yo_RBUS tab2_Yo_REG;
	unsigned long flags;//for spin_lock_irqsave

	//display_timing_ctrl2_RBUS display_timing_ctrl2_reg;
	ppoverlay_display_timing_ctrl2_RBUS display_timing_ctrl2_reg;

	if((IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT2)>>2)
	{
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);
		// IDMA VGIP DispD input source select
		display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
		display_timing_ctrl2_reg.d2i3ddma_src_sel = idmaDispD_in_sel;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_reg.regValue);
		IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg, _BIT2);
		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	}
	else
	{
		// IDMA VGIP DispD input source select
		display_timing_ctrl2_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg);
		display_timing_ctrl2_reg.d2i3ddma_src_sel = idmaDispD_in_sel;
		IoReg_Write32(PPOVERLAY_Display_Timing_CTRL2_reg, display_timing_ctrl2_reg.regValue);
	}
	pr_debug("PPOVERLAY_Display_Timing_CTRL2_reg = %x\n", IoReg_Read32(PPOVERLAY_Display_Timing_CTRL2_reg));

	switch(idmaDispD_in_sel)
	{
	    case CAP_SRC_SUBTITLE:
	        //table_index = tRGB2YUV_COEF_709_RGB_0_255_SUB_OSD_MIXER1;
	        table_index = tRGB2YUV_COEF_709_RGB_0_255;
	        break;
	    case CAP_SRC_OSD:
	    case CAP_SRC_DITHER:
	        //table_index = tRGB2YUV_COEF_709_RGB_0_255_OSD_MIXER2;
	        table_index = tRGB2YUV_COEF_709_RGB_0_255;
	        break;
	    default:
	        table_index = tRGB2YUV_COEF_709_RGB_0_255;
	        break;
	}

	//main  all tab-1
	tab2_M11_M12_REG.m11 = table_index [_RGB2YUV_m11];
	tab2_M11_M12_REG.m12 = table_index [_RGB2YUV_m12];
	//printf("i3ddma_rgb2yuv_tab1_m1_reg.regValue = %x\n", i3ddma_rgb2yuv_tab1_m1_reg.regValue);
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M11_M12_reg, tab2_M11_M12_REG.regValue);

	tab2_M13_M21_REG.m13 = table_index [_RGB2YUV_m13];
	tab2_M13_M21_REG.m21 = table_index [_RGB2YUV_m21];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M13_M21_reg, tab2_M13_M21_REG.regValue);

	tab2_M22_M23_REG.m22 = table_index [_RGB2YUV_m22];
	tab2_M22_M23_REG.m23 = table_index [_RGB2YUV_m23];
	//printf("i3ddma_rgb2yuv_tab1_m2_reg.regValue = %x\n", i3ddma_rgb2yuv_tab1_m2_reg.regValue);
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M22_M23_reg, tab2_M22_M23_REG.regValue);

	tab2_M31_M32_REG.m31 = table_index [_RGB2YUV_m31];
	tab2_M31_M32_REG.m32 = table_index [_RGB2YUV_m32];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M31_M32_reg, tab2_M31_M32_REG.regValue);

	tab2_M33_YGain_REG.m33 = table_index [_RGB2YUV_m33];
	tab2_M33_YGain_REG.y_gain= table_index [_RGB2YUV_Y_gain];
	//printf("i3ddma_rgb2yuv_tab1_m3_reg.regValue = %x\n", i3ddma_rgb2yuv_tab1_m3_reg.regValue);
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_M33_YGain_reg, tab2_M33_YGain_REG.regValue);

	tab2_Yo_REG.yo_odd= table_index [_RGB2YUV_Yo_odd];
	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_TAB1_Yo_reg, tab2_Yo_REG.regValue);

	i3ddma_rgb2yuv_ctrl_reg.regValue = IoReg_Read32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg);

	i3ddma_rgb2yuv_ctrl_reg.sel_rgb= table_index [_RGB2YUV_sel_RGB];
	i3ddma_rgb2yuv_ctrl_reg.set_r_in_offset= table_index [_RGB2YUV_set_Yin_offset];
	i3ddma_rgb2yuv_ctrl_reg.set_uv_out_offset= table_index [_RGB2YUV_set_UV_out_offset];
	i3ddma_rgb2yuv_ctrl_reg.sel_uv_off= table_index [_RGB2YUV_sel_UV_off];
	i3ddma_rgb2yuv_ctrl_reg.matrix_bypass= table_index [_RGB2YUV_Matrix_bypass];
	i3ddma_rgb2yuv_ctrl_reg.sel_y_gain= table_index [_RGB2YUV_Enable_Y_gain];

	//i3ddma_rgb2yuv_ctrl_reg.idmaDispD_in_sel = idmaDispD_in_sel;
	if(idmaDispD_in_sel == CAP_SRC_UZU)
		i3ddma_rgb2yuv_ctrl_reg.en_rgb2yuv = 0;
	else
		i3ddma_rgb2yuv_ctrl_reg.en_rgb2yuv = 1;

	printf("[IVI] rgb2yuv=%d\n", i3ddma_rgb2yuv_ctrl_reg.en_rgb2yuv);

	IoReg_Write32(H3DDMA_RGB2YUV_DITHER_4XXTO4XX_HDMI_RGB2YUV_CTRL_reg, i3ddma_rgb2yuv_ctrl_reg.regValue);

	return;
}



#define TMPMUL	(16)
/*============================================================================*/
/**
 * CScalerSetScaleDown
 * This function is used to set scaling-down registers, including main and sub display.
 *
 * @param <info> { display-info struecture }
 * @return { none }
 * @note
 * It can be linear or non-linear either, based on the non-linear flag condition:
 */
void I3DDMA_ultrazoom_set_scale_down(SIZE* in_Size, SIZE* out_Size, unsigned char panorama)
{
    unsigned char SDRatio;
    unsigned char SDFilter=0;
    unsigned int tmp_data;
    short *coef_pt;
    unsigned char i;
    unsigned int nFactor;
    unsigned char Hini, Vini;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    h3ddma_hsd_i3ddma_vsd_ctrl0_RBUS			       i3ddma_vsd_ctrl0_reg;
    h3ddma_hsd_i3ddma_hsd_ctrl0_RBUS				i3ddma_hsd_ctrl0_reg;
    h3ddma_hsd_i3ddma_hsd_scale_hor_factor_RBUS	i3ddma_hsd_scale_hor_factor_reg;
    h3ddma_hsd_i3ddma_vsd_scale_ver_factor_RBUS   	i3ddma_vsd_Scale_Ver_Factor_reg;
    h3ddma_hsd_i3ddma_hsd_hor_segment_RBUS		i3ddma_hsd_hor_segment_reg;
    h3ddma_hsd_i3ddma_hsd_hor_delta1_RBUS			i3ddma_hsd_hor_delta1_reg;
    h3ddma_hsd_i3ddma_hsd_initial_value_RBUS		i3ddma_hsd_initial_value_reg;
    h3ddma_hsd_i3ddma_vsd_initial_value_RBUS		i3ddma_vsd_initial_value_reg;

    i3ddma_vsd_ctrl0_reg.regValue		= IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg);
    i3ddma_hsd_ctrl0_reg.regValue		= IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg);
    i3ddma_hsd_scale_hor_factor_reg.regValue	= IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg);
    i3ddma_vsd_Scale_Ver_Factor_reg.regValue = IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg);
    i3ddma_hsd_hor_segment_reg.regValue = IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg);
    i3ddma_hsd_hor_delta1_reg.regValue	= IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg);
    i3ddma_hsd_initial_value_reg.regValue	= IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg);
    i3ddma_vsd_initial_value_reg.regValue = IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg);


    //o============ H scale-down=============o
    if (in_Size->nWidth > out_Size->nWidth) {
        // o-------calculate scaledown ratio to select one of different bandwith filters.--------o
        if ( out_Size->nWidth == 0 ) {
            UltraZoom_Printf("output width = 0 !!!\n");
            SDRatio = 0;
        } else {
            SDRatio = (in_Size->nWidth*TMPMUL) / out_Size->nWidth;
        }

        //UltraZoom_Printf("CSW SDRatio number=%d\n",SDRatio);

        if(SDRatio <= ((TMPMUL*3)/2))	//<1.5 sharp, wider bw
            SDFilter = 2;
        else if(SDRatio <= (TMPMUL*2) && SDRatio > ((TMPMUL*3)/2) )	// Mid
            SDFilter = 1;
        else		// blurest, narrow bw
            SDFilter = 0;

        //o---------------- fill coefficients into access port--------------------o
        coef_pt = tScaleDown_COEF_TAB[SDFilter];

        i3ddma_hsd_ctrl0_reg.h_y_table_sel = 0;	// TAB1
        i3ddma_hsd_ctrl0_reg.h_c_table_sel = 0;	// TAB1

        for (i=0; i<16; i++)
        {
            tmp_data = ((unsigned int)(*coef_pt++)<<16);
            tmp_data += (unsigned int)(*coef_pt++);
            IoReg_Write32(H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab1_C0_reg+ i*4, tmp_data);
        }
    }

	//o============ V scale-down=============o
	if (in_Size->nLength > out_Size->nLength) {
		// o-------calculate scaledown ratio to select one of different bandwith filters.--------o

		 //jeffrey 961231
		if ( out_Size->nLength == 0 ) {
			SDRatio = 0;
		} else {
			SDRatio = (in_Size->nLength*TMPMUL) / out_Size->nLength;
		}

		//UltraZoom_Printf("CSW SDRatio number=%d\n",SDRatio);

		if(SDRatio <= ((TMPMUL*3)/2))	//<1.5 sharp, wider bw
			SDFilter = 2;
		else if(SDRatio <= (TMPMUL*2) && SDRatio > ((TMPMUL*3)/2) )	// Mid
			SDFilter = 1;
		else		// blurest, narrow bw
			SDFilter = 0;

		//o---------------- fill coefficients into access port--------------------o
		coef_pt = tScaleDown_COEF_TAB[SDFilter];

		i3ddma_vsd_ctrl0_reg.v_y_table_sel = 1;	// TAB2
		i3ddma_vsd_ctrl0_reg.v_c_table_sel = 1;	// TAB2

		for (i=0; i<16; i++)
		{
			tmp_data = ((unsigned int)(*coef_pt++)<<16);
			tmp_data += (unsigned int)(*coef_pt++);
			IoReg_Write32(H3DDMA_HSD_I3DDMA_UZD_FIR_Coef_Tab2_C0_reg+ i*4, tmp_data);
		}

	}


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	if (in_Size->nWidth > out_Size->nWidth) {    // H scale-down
		Hini = 0x80;//0xff;//0x78;
		i3ddma_hsd_initial_value_reg.hor_ini = Hini;
		{
			//frank@0108 add for code exception
			if ( out_Size->nWidth == 0 ) {
				printf("output width = 0 !!!\n");
				nFactor = 0;
			} else if(in_Size->nWidth>4095){
				//nFactor = (unsigned int)((((in_Size->nWidth-1)<<19) / (out_Size->nWidth-1))<<1);
				nFactor = (unsigned int)((((in_Size->nWidth)<<19) / (out_Size->nWidth))<<1);
			} else if(in_Size->nWidth>2047){
				//nFactor = (unsigned int)(((in_Size->nWidth-1)<<20) / (out_Size->nWidth-1));
				nFactor = (unsigned int)(((in_Size->nWidth)<<20) / (out_Size->nWidth));
			} else {
				nFactor = (unsigned int)((in_Size->nWidth<<21)) / (out_Size->nWidth);
				nFactor = SHR(nFactor + 1, 1); //rounding
			}
		}

		i3ddma_hsd_scale_hor_factor_reg.hor_fac = nFactor;
	}else {
		i3ddma_hsd_scale_hor_factor_reg.hor_fac = 0x100000;
	}
	i3ddma_hsd_hor_segment_reg.nl_seg2 = out_Size->nWidth;

	if (in_Size->nLength > out_Size->nLength) {    // V scale-down
//			ich2_uzd_Ctrl0_REG.buffer_mode = 0x02;
		Vini = 0xff;//0x78;
		i3ddma_vsd_initial_value_reg.ver_ini = Vini;
		//nFactor = (unsigned int)((ptInSize->nLength << 20) - (Vini<<12)) / (ptOutSize->nLength - 1);
		//frank@0108 add for code exception
		if ( out_Size->nLength == 0 ) {
			printf("output length = 0 !!!\n");
			nFactor = 0;
		} else {
			//nFactor = (unsigned int)((in_Size->nLength << 21)) / (out_Size->nLength);
			//modify the calculation for V-scale down @Crixus 20160804
			nFactor = (unsigned int)((in_Size->nLength * 1024 * 1024)) / (out_Size->nLength);
		}
		//nFactor = SHR(nFactor+1, 1); //rounding
		i3ddma_vsd_Scale_Ver_Factor_reg.ver_fac = nFactor;
	}else{
//			ich2_uzd_Ctrl0_REG.buffer_mode = 0;
		i3ddma_vsd_Scale_Ver_Factor_reg.ver_fac = 0x100000;
	}

//	ich2_uzd_Ctrl0_REG.output_fmt = 1;
//	CLR_422_Fr_SD();

	IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg, i3ddma_vsd_ctrl0_reg.regValue);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg, i3ddma_hsd_ctrl0_reg.regValue);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Scale_Hor_Factor_reg, i3ddma_hsd_scale_hor_factor_reg.regValue);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Scale_Ver_Factor_reg, i3ddma_vsd_Scale_Ver_Factor_reg.regValue);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Hor_Segment_reg, i3ddma_hsd_hor_segment_reg.regValue);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Hor_Delta1_reg, i3ddma_hsd_hor_delta1_reg.regValue);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Initial_Value_reg, i3ddma_vsd_initial_value_reg.regValue);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Initial_Value_reg, i3ddma_hsd_initial_value_reg.regValue);

	return;
}



void I3DDMA_ultrazoom_config_scaling_down(SIZE* in_Size, SIZE* out_Size, unsigned char panorama)
{
	// Scale down setup for Channel1
	h3ddma_hsd_i3ddma_hsd_ctrl0_RBUS i3ddma_hsd_ctrl0_reg;
	h3ddma_hsd_i3ddma_vsd_ctrl0_RBUS i3ddma_vsd_ctrl0_reg;


	i3ddma_hsd_ctrl0_reg.regValue = IoReg_Read32(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg);
	i3ddma_hsd_ctrl0_reg.h_zoom_en = (in_Size->nWidth > out_Size->nWidth);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_HSD_Ctrl0_reg, i3ddma_hsd_ctrl0_reg.regValue);

	i3ddma_vsd_ctrl0_reg.regValue = IoReg_Read32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg);
	i3ddma_vsd_ctrl0_reg.v_zoom_en = (in_Size->nLength > out_Size->nLength);
	if(i3ddma_vsd_ctrl0_reg.v_zoom_en)
		i3ddma_vsd_ctrl0_reg.buffer_mode = 2;//do V-scale down have to use v-scale down buffer mode.
	else
		i3ddma_vsd_ctrl0_reg.buffer_mode = Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_FSYNC_VUZD);
	i3ddma_vsd_ctrl0_reg.sort_fmt = (Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_422CAP) ? 0 : 1);
	i3ddma_vsd_ctrl0_reg.video_comp_en = (Scaler_DispGetStatus(SLR_SUB_DISPLAY,SLR_DISP_COMP) ? 1 : 0 );
	i3ddma_vsd_ctrl0_reg.truncationctrl = (Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_10BIT)? 0: 1);
	IoReg_Write32(H3DDMA_HSD_I3DDMA_VSD_Ctrl0_reg, i3ddma_vsd_ctrl0_reg.regValue);

	I3DDMA_ultrazoom_set_scale_down(in_Size, out_Size, panorama);

	return;
}

