/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		hdmiMs.c
 *
 * author: 	The God of Thunder, Thor
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include "hdmi_common.h"




/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/
#define ANALOG_MODE_MEASUREMENT      0
#define DIGITAL_MODE_MEASUREMENT     1
#define MEASURE_FROM_TMDS_CLOCK 0          // 0: PIXEL CLOCK  1:TMDS CLOCK
//#define TM_TB_SIZE		4
#define TM_TB_SIZE		10


/**********************************************************************************************
*
*	Const Declarations
*
**********************************************************************************************/
const HDMI_ACTIVE_SPACE_TABLE_T hdmi_active_space_table[] = {
	{ "1080P FramePacking",  1, 1920,  1080*2 + 45, 1080, 45, 0 },
	{ "720P FramePacking",  1, 1280,  720*2 + 30, 720, 30, 0 },
	{ "480P FramePacking",  1, 720,  480*2 + 45, 480, 45, 0 },
	{ "576P FramePacking",  1, 720,  576*2 + 49, 576, 49, 0 },
	{ "1080I FramePacking",  0, 1920,  540*4 + 22 + 23*2, 540, 23, 22 },
	{ "576I FramePacking",  0, 720,  288*4 + 32 + 21*2, 288, 21, 32 },
	{ "480I FramePacking",  0, 720,  240*4 + 22 + 23*2, 240, 23, 22 },
	{ NULL,  1, 1920,  520, 40, 0 },
};

#if 1
const HDMI_TIMING_TABLE_T tm_table[TM_TB_SIZE] = {
	{4096, 2160, 15, 10},	// 4k2K
	{3840, 2160, 15, 10},	// 4k2K
	{1920, 1080, 10, 5},	// 1080P
	{1920, 540, 5, 3},		// 1080i
	{1280, 720, 5, 5},		// 720P
	{720, 576, 3, 3},		// 576P
	{640, 480, 3, 3},		// 480P
	{720, 480, 3, 3},		// 480P
	{720, 288, 3, 3},		// 576i
	{720, 240, 3, 3},		// 480i
};
#else //#if 1
const HDMI_TIMING_TABLE_T tm_table[TM_TB_SIZE] = {
	{4096, 2160, 15, 10},
	{3840, 2160, 15, 10},
	{1920, 1080, 10, 5},
	{1280, 720, 5, 5}
};
#endif //#if 1

/**********************************************************************************************
*
*	Variables
*
**********************************************************************************************/
unsigned char no_polarity_inverse_flag = FALSE;//allow vgip to set h v polarity inverse or not




/**********************************************************************************************
*
*	Funtion Declarations
*
**********************************************************************************************/

unsigned char lib_hdmims_measure(HDMI_TIMING_T *tm);
unsigned char lib_hdmims_offline_measure(HDMI_TIMING_T *tm);
unsigned char lib_hdmims_offms_start(void);
unsigned char lib_hdmims_online1_measure(HDMI_TIMING_T *tm);
unsigned char lib_hdmims_onms1_start(void);
unsigned char lib_hdmims_online3_measure(HDMI_TIMING_T *tm);
unsigned char lib_hdmims_onms3_start(void);
unsigned char lib_hdmims_calc_freq(HDMI_TIMING_T *tm);
unsigned char lib_hdmi_skiptiming_condition(HDMI_TIMING_T *timing);






/**********************************************************************************************
*
*	Function Body
*
**********************************************************************************************/



void set_no_polarity_inverse(unsigned char TorF)
{//allow vgip to set h v polarity inverse or not
	no_polarity_inverse_flag = TorF;
}


unsigned char newbase_hdmims_measure_video(HDMI_TIMING_T *tm)
{
	unsigned char ms_done = 0;
	HDMI_TIMING_T tm_cmp;
	memcpy(&tm_cmp, tm, sizeof(HDMI_TIMING_T));

	down(get_offline_semaphore());
	ms_done = lib_hdmims_measure(tm);
	up(get_offline_semaphore());

	if (!ms_done)			return FALSE;
	if (tm->h_act_len > tm->h_total)	return FALSE;
	if (tm->v_act_len > tm->v_total)	return FALSE;
	if (tm->h_act_len < 300)		return FALSE;
	if (tm->v_act_len < 240)		return FALSE;
	if(TRUE == lib_hdmi_skiptiming_condition(tm))		return FALSE;

	down(get_offline_semaphore());
	ms_done = lib_hdmims_measure(&tm_cmp);
	up(get_offline_semaphore());

	if (!ms_done)					return FALSE;
	if (tm->h_total != tm_cmp.h_total)			return FALSE;
	if (HDMI_ABS(tm->v_total, tm_cmp.v_total) > 5)	return FALSE;
	if (tm->h_act_len != tm_cmp.h_act_len)		return FALSE;
	if (tm->v_act_len != tm_cmp.v_act_len)		return FALSE;
	if (HDMI_ABS(tm->h_freq, tm_cmp.h_freq) > 5)	return FALSE;
	if (HDMI_ABS(tm->v_freq, tm_cmp.v_freq) > 5)	return FALSE;
	
#ifdef CONFIG_CUSTOMER_TV030
	#if( !HDMI2p0)
	if((tm_cmp.h_act_len >=3840) ||(tm_cmp.v_act_len>=2160))
		{		
		HDMI_PRINTF("[OFMS] \r\n lzqmsg===>not support!! (%d x %d)\n",tm_cmp.h_act_len,tm_cmp.v_act_len);
		return FALSE;
		}
	#endif
#endif
	return TRUE;
}





unsigned char lib_hdmims_active_correction(unsigned int *h_active, unsigned int *v_active)
{
	unsigned char i;
	for (i=0; i<TM_TB_SIZE; i++) {
		if (HDMI_ABS(*h_active, tm_table[i].h_act) < tm_table[i].h_tol &&
			HDMI_ABS(*v_active, tm_table[i].v_act) < tm_table[i].v_tol) {

			if (*h_active != tm_table[i].h_act || *v_active != tm_table[i].v_act) {
				HDMI_EMG("[HDMI][OFMS] Corrected H/V=(%d,%d) to (%d,%d)\n",
					*h_active, *v_active, tm_table[i].h_act, tm_table[i].v_act);
			}
			*h_active = tm_table[i].h_act;
			*v_active = tm_table[i].v_act;
			return 1;
		}
	}

	if ((*h_active)%10 == 9) {
		(*h_active)++;
	} else if (*h_active%10 == 1) {
		(*h_active)--;
	}

	if ((*v_active)%10 == 9) {
		(*v_active)++;
	} else if (*v_active%10 == 1) {
		(*v_active)--;
	}

	return 0;
}



unsigned char lib_hdmims_measure(HDMI_TIMING_T *tm)
{
	unsigned char ret;
	ret = lib_hdmims_offline_measure(tm);
	if (!ret)
		return FALSE;

	return lib_hdmims_calc_freq(tm);

}

unsigned char lib_hdmims_offline_measure(HDMI_TIMING_T *tm)
{
	hdmiport_mask(OFFMS_SP_MS3Ctrl_reg,
		~(OFFMS_SP_MS3Ctrl_off_meas_source_mask | OFFMS_SP_MS3Ctrl_off_clk_sel_mask
		| OFFMS_SP_MS3Ctrl_off_meas_to_sel_mask | OFFMS_SP_MS3Ctrl_off_sycms_mode_mask
		| OFFMS_SP_MS3Ctrl_off_popup_meas_mask | OFFMS_SP_MS3Ctrl_off_start_ms_mask),
		OFFMS_SP_MS3Ctrl_off_meas_source(8) | OFFMS_SP_MS3Ctrl_off_clk_sel(1)
		| OFFMS_SP_MS3Ctrl_off_meas_to_sel(1) | OFFMS_SP_MS3Ctrl_off_sycms_mode(ANALOG_MODE_MEASUREMENT)
		|OFFMS_SP_MS3Ctrl_get_off_popup_meas(0)|OFFMS_SP_MS3Ctrl_get_off_start_ms(0));

	if (!lib_hdmims_offms_start()) {
		HDMI_EMG("[HDMI][OFMS] Hdmi_OffLineMeasure is not finish.\n");
		return FALSE;
	}

	tm->h_total = OFFMS_SP_MS3Rst1_get_off_hs_period_out_h12b(hdmi_in(OFFMS_SP_MS3Rst1_reg))+1;
	tm->v_total = OFFMS_SP_MS3Rst0_get_off_vs_period_out(hdmi_in(OFFMS_SP_MS3Rst0_reg))+1;
	tm->h_act_sta = OFFMS_MES_RESULT_HSTA_END_get_off_hx_sta(hdmi_in(OFFMS_MES_RESULT_HSTA_END_reg));
	tm->v_act_sta = OFFMS_MES_RESULT_VSTA_END_get_off_vx_sta(hdmi_in(OFFMS_MES_RESULT_VSTA_END_reg));
	tm->h_act_len = OFFMS_MES_RESULT_HSTA_END_get_off_hx_end(hdmi_in(OFFMS_MES_RESULT_HSTA_END_reg))-tm->h_act_sta;
	tm->v_act_len = OFFMS_MES_RESULT_VSTA_END_get_off_vx_end(hdmi_in(OFFMS_MES_RESULT_VSTA_END_reg))-tm->v_act_sta+1;
	tm->polarity = (OFFMS_SP_MS3Stus_get_off_vs_pol_out(hdmi_in(OFFMS_SP_MS3Stus_reg))<<1)|
			OFFMS_SP_MS3Stus_get_off_hs_pol_out(hdmi_in(OFFMS_SP_MS3Stus_reg));

	tm->h_act_sta -= 4;
	tm->v_act_sta -= 2;

	tm->IVSyncPulseCount = OFFMS_SP_MS3Rst2_get_off_vs_high_out(hdmi_in(OFFMS_SP_MS3Rst2_reg))+1;

#if MEASURE_FROM_TMDS_CLOCK
	if (tm->pixel_repeat > 0) {
		tm->h_act_sta /= (tm->pixel_repeat+1);
		tm->h_total /= (tm->pixel_repeat+1);
		tm->h_act_len /= (tm->pixel_repeat+1);
	}
#endif


#if HDMI2p0
	if (COLOR_YUV420 == tm->colorspace) {
		tm->h_act_sta <<= 1;
		tm->h_total <<= 1;
		tm->h_act_len <<= 1;
	}
#endif



#if MEASURE_FROM_TMDS_CLOCK

	if (HDMI_COLOR_DEPTH_10B == tm->colordepth) {
		// value / 1.25
		tm->h_act_sta = ((tm->h_act_sta*4)+3)/5;
		tm->h_total = ((tm->h_total*4)+3)/5;
		tm->h_act_len = ((tm->h_act_len*4)+3)/5;

	} else if (HDMI_COLOR_DEPTH_12B == tm->colordepth) {
		// value / 1.5
		tm->h_act_sta = ((tm->h_act_sta*2)+2)/3;
		tm->h_total = ((tm->h_total*2)+2)/3;
		tm->h_act_len = ((tm->h_act_len*2)+2)/3;

	} else if (HDMI_COLOR_DEPTH_16B == tm->colordepth) {
		// value / 2
		tm->h_act_sta = tm->h_act_sta>>1;
		tm->h_total = tm->h_total>>1;
		tm->h_act_len = tm->h_act_len>>1;

	}
#endif


	lib_hdmims_active_correction(&(tm->h_act_len), &(tm->v_act_len));

	HDMI_PRINTF("[OFMS] IHTotal: %d\n", tm->h_total);
	HDMI_PRINTF("[OFMS] IVTotal: %d\n", tm->v_total);
	HDMI_PRINTF("[OFMS] IHAct: %d\n", tm->h_act_len);
	HDMI_PRINTF("[OFMS] IVAct: %d\n", tm->v_act_len);
	HDMI_PRINTF("[OFMS] IHStr: %d\n", tm->h_act_sta);
	HDMI_PRINTF("[OFMS] IVStr: %d\n", tm->v_act_sta);

	return TRUE;

}

unsigned char lib_hdmims_offms_start(void)
{
	unsigned int t1;
	offms_sp_ms3ctrl_RBUS ofms_ms3ctrl_reg;

	ofms_ms3ctrl_reg.regValue = hdmi_in(OFFMS_SP_MS3Ctrl_reg);

	ofms_ms3ctrl_reg.off_start_ms = 1;
	hdmi_out(OFFMS_SP_MS3Ctrl_reg, ofms_ms3ctrl_reg.regValue);

	t1 = 100;
	do {
		t1 --;
		ofms_ms3ctrl_reg.regValue = hdmi_in(OFFMS_SP_MS3Ctrl_reg);
		if ( !ofms_ms3ctrl_reg.off_start_ms )  break;
		msleep(2);//Minchay@20151029-m speed up performence
	} while (t1 > 0);

#ifdef HDMI_OFFLINE_MEASURE_FIX
	if (t1 == 0) {
		HDMI_EMG("[Warning][OFMS] POP not finish \n");
	}
#else //#ifdef HDMI_OFFLINE_MEASURE_FIX
	if ( t1==0 ) return FALSE;
#endif //#ifdef HDMI_OFFLINE_MEASURE_FIX

	ofms_ms3ctrl_reg.off_popup_meas = 1;
	hdmi_out(OFFMS_SP_MS3Ctrl_reg, ofms_ms3ctrl_reg.regValue);

	t1 = 100;
	do {
		t1 --;
		ofms_ms3ctrl_reg.regValue = hdmi_in(OFFMS_SP_MS3Ctrl_reg);
		if ( !ofms_ms3ctrl_reg.off_popup_meas )  break;
		msleep(2);//Minchay@20151029-m speed up performence
	} while (t1 > 0);

	if (t1 == 0) return FALSE;

	return TRUE;
}

unsigned char lib_hdmims_online1_measure(HDMI_TIMING_T *tm)
{
unsigned int hact = 0, vact = 0;
	hdmiport_mask(ONMS_onms1_ctrl_reg,
		~(ONMS_onms1_ctrl_on1_vtotal_of_th_mask | ONMS_onms1_ctrl_on1_ms_src_sel_mask
		| ONMS_onms1_ctrl_on1_meas_to_sel_mask | ONMS_onms1_ctrl_on1_sycms_clk_mask|
		ONMS_onms1_ctrl_on1_ms_conti_mask|ONMS_onms1_ctrl_on1_start_ms_mask),
		ONMS_onms1_ctrl_on1_vtotal_of_th(1) | ONMS_onms1_ctrl_on1_ms_src_sel(1)
		| ONMS_onms1_ctrl_on1_meas_to_sel(1) | ONMS_onms1_ctrl_on1_sycms_clk(1)
		|ONMS_onms1_ctrl_on1_ms_conti(0)|ONMS_onms1_ctrl_on1_start_ms(0));

	if (!lib_hdmims_onms1_start()) {
		HDMI_EMG("[ONMS1] OnLineMeasure is not finish.\n");
		return FALSE;
	}

	hact = ONMS_onms1_hact_get_on1_hact(hdmi_in(ONMS_onms1_hact_reg));
	vact = ONMS_onms1_vs_period_get_on1_vtotalde(hdmi_in(ONMS_onms1_vs_period_reg));
	HDMI_PRINTF("[ONMS1] IHTotal: %d\n", ONMS_onms1_hs_period_get_on1_htotal_h12b(hdmi_in(ONMS_onms1_hs_period_reg)));
	HDMI_PRINTF("[ONMS1] IVTotal: %d\n", ONMS_onms1_vs_period_get_on1_vtotal(hdmi_in(ONMS_onms1_vs_period_reg)));
	HDMI_PRINTF("[ONMS1] IHAct: %d\n", hact);
	HDMI_PRINTF("[ONMS1] IVAct: %d\n", vact);

	return TRUE;

}

unsigned char lib_hdmims_onms1_start(void)
{
	unsigned int t1;

	hdmi_mask(ONMS_onms1_ctrl_reg, ~ONMS_onms1_ctrl_on1_start_ms_mask, ONMS_onms1_ctrl_on1_start_ms_mask);

	t1 = 100;
	do {
		t1 --;
		if (!ONMS_onms1_ctrl_get_on1_start_ms(hdmi_in(ONMS_onms1_ctrl_reg))) break;
		msleep(2);
	} while (t1 > 0);

#if 1
	if (t1 == 0) {
		HDMI_EMG("[Warning][ONMS1] meas is not finish \n");
	}
#else
	if ( t1==0 ) return FALSE;
#endif

	hdmi_mask(ONMS_onms1_ctrl_reg, ~ONMS_onms1_ctrl_on1_popup_meas_mask, ONMS_onms1_ctrl_on1_popup_meas_mask);

	t1 = 100;
	do {
		t1 --;
		if (!ONMS_onms1_ctrl_get_on1_popup_meas(hdmi_in(ONMS_onms1_ctrl_reg))) break;
		msleep(2);
	} while (t1 > 0);

	if (t1 == 0) return FALSE;

	return TRUE;
}


unsigned char lib_hdmims_online3_measure(HDMI_TIMING_T *tm)
{
unsigned int hact = 0, vact = 0;
	hdmiport_mask(ONMS_onms3_ctrl_reg,
		~(ONMS_onms3_ctrl_on3_vtotal_of_th_mask | ONMS_onms3_ctrl_on3_ms_src_sel_mask
		| ONMS_onms3_ctrl_on3_meas_to_sel_mask | ONMS_onms3_ctrl_on3_sycms_clk_mask|
		ONMS_onms3_ctrl_on3_ms_conti_mask|ONMS_onms3_ctrl_on3_start_ms_mask),
		ONMS_onms3_ctrl_on3_vtotal_of_th(1) | ONMS_onms3_ctrl_on3_ms_src_sel(1)
		| ONMS_onms3_ctrl_on3_meas_to_sel(1) | ONMS_onms3_ctrl_on3_sycms_clk(1)
		|ONMS_onms3_ctrl_on3_ms_conti(0)|ONMS_onms3_ctrl_on3_start_ms(0));

	if (!lib_hdmims_onms3_start()) {
		HDMI_EMG("[ONMS3] OnLineMeasure is not finish.\n");
		return FALSE;
	}

	hact = ONMS_onms3_hact_get_on3_hact(hdmi_in(ONMS_onms3_hact_reg));
	vact = ONMS_onms3_vs_period_get_on3_vtotalde(hdmi_in(ONMS_onms3_vs_period_reg));
	HDMI_PRINTF("[ONMS3] IHTotal: %d\n", ONMS_onms3_hs_period_get_on3_htotal_h12b(hdmi_in(ONMS_onms3_hs_period_reg)));
	HDMI_PRINTF("[ONMS3] IVTotal: %d\n", ONMS_onms3_vs_period_get_on3_vtotal(hdmi_in(ONMS_onms3_vs_period_reg)));
	HDMI_PRINTF("[ONMS3] IHAct: %d\n", hact);
	HDMI_PRINTF("[ONMS3] IVAct: %d\n", vact);

	return TRUE;

}

unsigned char lib_hdmims_onms3_start(void)
{
	unsigned int t1;

	hdmi_mask(ONMS_onms3_ctrl_reg, ~ONMS_onms3_ctrl_on3_start_ms_mask, ONMS_onms3_ctrl_on3_start_ms_mask);

	t1 = 100;
	do {
		t1 --;
		if (!ONMS_onms3_ctrl_get_on3_start_ms(hdmi_in(ONMS_onms3_ctrl_reg))) break;
		msleep(2);
	} while (t1 > 0);

#if 1
	if (t1 == 0) {
		HDMI_EMG("[Warning][ONMS3] meas is not finish \n");
	}
#else
	if ( t1==0 ) return FALSE;
#endif

	hdmi_mask(ONMS_onms3_ctrl_reg, ~ONMS_onms3_ctrl_on3_popup_meas_mask, ONMS_onms3_ctrl_on3_popup_meas_mask);

	t1 = 100;
	do {
		t1 --;
		if (!ONMS_onms3_ctrl_get_on3_popup_meas(hdmi_in(ONMS_onms3_ctrl_reg))) break;
		msleep(2);
	} while (t1 > 0);

	if (t1 == 0) return FALSE;

	return TRUE;
}

unsigned char lib_hdmims_calc_freq(HDMI_TIMING_T *tm)
{
	unsigned int Q, D;

	if (tm->tmds_clk_b < 100 || tm->v_total < 100) {
		tm->h_freq = 0;
		tm->v_freq = 0;
		return FALSE;
	}


	//FVCO = Fin * m / n
	//Fin = TMDS clock = pixel clock * SN/SM   --> pixel clock = Fin * SM / SN
	//pixel clock = (b * 27 / 256) * SM/SN
	//pixel clock / b = 27 * SM/(SN*256) = Q
	//pixel clock = b * Q = Q'
	//total pixel = htotal * vtotal * frame rate
	//pixel clock / htotal /100 =  hfeq (10khz) = vtotal * vfreq /100
	//hreq(10khz) = Q'/D/100
	//vfeq =hfeq * 10 / vtotal

	//code calculation
	//Q1= (Q + D/2)/D = Q/D + 1/2 (round)
	//hfreq = Q1/100 + 1/2 = Q/D * 1/100 + 1/200 + 1/2 = Q/D /100 + 3/200(what's mean?)
	
	D = (tm->pixel_repeat+1) * tm->h_total;
	Q = ((27000000UL * dpll_ratio[tm->colordepth].RatioM)) / (dpll_ratio[tm->colordepth].RatioN * 256);

#if MHL_SUPPORT
	if (tm->is_mhl && tm->is_mhl_pp) {
		Q = (tm->tmds_clk_b * Q *2);
		HDMI_PRINTF("MHL PP mode measure !!!\n");
	} else
#endif
	{
		Q = (tm->tmds_clk_b * Q);
	}

	Q =   ((Q + (D >> 1)) / D);

	tm->h_freq = (Q + 50) / 100;
	tm->v_freq = (Q * 10 + (tm->v_total>> 1)) / tm->v_total;

#if HDMI2p0
	if (tm->colorspace == COLOR_YUV420) {
		tm->v_freq <<= 1;
	}
#endif

	HDMI_PRINTF("[OFMS] IHFreq: %d\n", tm->h_freq);
	HDMI_PRINTF("[OFMS] IVFreq: %d\n", tm->v_freq);

	return TRUE;
}

#if HDMI_MEASURE_I3DDMA_SMART_FIT
void lib_hdmims_set_vgip_clk_enable(HDMI_SMT_PATH vgip_ch)
{
	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_reg;
	sub_vgip_vgip_chn2_ctrl_RBUS sub_vgip_vgip_chn2_ctrl_reg;
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_dma_vgip_ctrl_reg;

	switch(vgip_ch)
	{
		case HDMI_SMT_PATH_MAIN_VGIP:
			// Disable SRC_Clock_Enbale bit
			vgip_vgip_chn1_ctrl_reg.regValue = hdmi_in(VGIP_VGIP_CHN1_CTRL_reg);
			vgip_vgip_chn1_ctrl_reg.ch1_in_clk_en = _DISABLE; // clear previous setting
			hdmi_out(VGIP_VGIP_CHN1_CTRL_reg, vgip_vgip_chn1_ctrl_reg.regValue);

			// 2nd determine the input source
			vgip_vgip_chn1_ctrl_reg.regValue = hdmi_in(VGIP_VGIP_CHN1_CTRL_reg);
			vgip_vgip_chn1_ctrl_reg.ch1_in_sel = 0; //HDMI
			vgip_vgip_chn1_ctrl_reg.ch1_digital_mode = 1; //digital mode
			hdmi_out(VGIP_VGIP_CHN1_CTRL_reg, vgip_vgip_chn1_ctrl_reg.regValue);

			// 3rd enable SRC_Clock_Enbale bit
			vgip_vgip_chn1_ctrl_reg.regValue = hdmi_in(VGIP_VGIP_CHN1_CTRL_reg);
			vgip_vgip_chn1_ctrl_reg.ch1_in_clk_en = _ENABLE; //enable clock
			hdmi_out(VGIP_VGIP_CHN1_CTRL_reg, vgip_vgip_chn1_ctrl_reg.regValue);

			vgip_vgip_chn1_ctrl_reg.regValue = hdmi_in(VGIP_VGIP_CHN1_CTRL_reg);
			vgip_vgip_chn1_ctrl_reg.ch1_ivrun = _ENABLE; //Input VGIP run enable
			hdmi_out(VGIP_VGIP_CHN1_CTRL_reg, vgip_vgip_chn1_ctrl_reg.regValue);

			HDMI_PRINTF("[HDMI] measure use VGIP1\n");
		break;

		case HDMI_SMT_PATH_SUB_VGIP:
			// Disable SRC_Clock_Enbale bit
			sub_vgip_vgip_chn2_ctrl_reg.regValue = hdmi_in(SUB_VGIP_VGIP_CHN2_CTRL_reg);
			sub_vgip_vgip_chn2_ctrl_reg.ch2_in_clk_en = _DISABLE;
			hdmi_out(SUB_VGIP_VGIP_CHN2_CTRL_reg, sub_vgip_vgip_chn2_ctrl_reg.regValue);

			// 2nd determine the input source
			sub_vgip_vgip_chn2_ctrl_reg.regValue = hdmi_in(SUB_VGIP_VGIP_CHN2_CTRL_reg);
			sub_vgip_vgip_chn2_ctrl_reg.ch2_in_sel = 0; //HDMI
			sub_vgip_vgip_chn2_ctrl_reg.ch2_digital_mode = 1; //digital mode
			hdmi_out(SUB_VGIP_VGIP_CHN2_CTRL_reg, sub_vgip_vgip_chn2_ctrl_reg.regValue);

			// 3rd enable SRC_Clock_Enbale bit
			sub_vgip_vgip_chn2_ctrl_reg.regValue = hdmi_in(SUB_VGIP_VGIP_CHN2_CTRL_reg);
			sub_vgip_vgip_chn2_ctrl_reg.ch2_in_clk_en = _ENABLE;
			hdmi_out(SUB_VGIP_VGIP_CHN2_CTRL_reg, sub_vgip_vgip_chn2_ctrl_reg.regValue);

			sub_vgip_vgip_chn2_ctrl_reg.regValue = hdmi_in(SUB_VGIP_VGIP_CHN2_CTRL_reg);
			sub_vgip_vgip_chn2_ctrl_reg.ch2_ivrun = _ENABLE; //Input VGIP run enable
			hdmi_out(SUB_VGIP_VGIP_CHN2_CTRL_reg, sub_vgip_vgip_chn2_ctrl_reg.regValue);

			HDMI_PRINTF("[HDMI] measure use VGIP2\n");
		break;

		case HDMI_SMT_PATH_DMA_VGIP:
			// Disable SRC_Clock_Enbale bit
			dma_vgip_dma_vgip_ctrl_reg.regValue = hdmi_in(DMA_VGIP_DMA_VGIP_CTRL_reg);
			dma_vgip_dma_vgip_ctrl_reg.dma_in_clk_en = _DISABLE;
			hdmi_out(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_dma_vgip_ctrl_reg.regValue);

			// 2nd determine the input source
			dma_vgip_dma_vgip_ctrl_reg.regValue = hdmi_in(DMA_VGIP_DMA_VGIP_CTRL_reg);
			dma_vgip_dma_vgip_ctrl_reg.dma_in_sel = 0; //HDMI
			dma_vgip_dma_vgip_ctrl_reg.dma_digital_mode = 1; //digital mode
			hdmi_out(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_dma_vgip_ctrl_reg.regValue);

			// 3rd enable SRC_Clock_Enbale bit
			dma_vgip_dma_vgip_ctrl_reg.regValue = hdmi_in(DMA_VGIP_DMA_VGIP_CTRL_reg);
			dma_vgip_dma_vgip_ctrl_reg.dma_in_clk_en = _ENABLE;
			hdmi_out(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_dma_vgip_ctrl_reg.regValue);

			dma_vgip_dma_vgip_ctrl_reg.regValue = hdmi_in(DMA_VGIP_DMA_VGIP_CTRL_reg);
			dma_vgip_dma_vgip_ctrl_reg.dma_ivrun = _ENABLE; //Input VGIP run enable
			hdmi_out(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_dma_vgip_ctrl_reg.regValue);

			HDMI_PRINTF("[HDMI] measure use DMA-VGIP\n");
		break;

		default:
			HDMI_EMG("[HDMI] measure VGIP Err=%d\n", vgip_ch);
		break;
	}
}
#else //#if HDMI_MEASURE_I3DDMA_SMART_FIT
void lib_hdmims_set_vgip_clk_enable(unsigned char vgip_ch)
{

	if (0 == vgip_ch) { //vgip 1
		// Disable SRC_Clock_Enbale bit
		hdmiport_mask(VGIP_VGIP_CHN1_CTRL_reg, ~(VGIP_VGIP_CHN1_CTRL_ch1_in_clk_en_mask), 0); // clear previous setting
		// 2nd determine the input source
		hdmiport_mask(VGIP_VGIP_CHN1_CTRL_reg, ~(VGIP_VGIP_CHN1_CTRL_ch1_in_sel_mask|VGIP_VGIP_CHN1_CTRL_ch1_digital_mode_mask), VGIP_VGIP_CHN1_CTRL_ch1_digital_mode_mask); //set analog mode
		// 3rd enable SRC_Clock_Enbale bit
		hdmiport_mask(VGIP_VGIP_CHN1_CTRL_reg, ~(VGIP_VGIP_CHN1_CTRL_ch1_in_clk_en_mask), VGIP_VGIP_CHN1_CTRL_ch1_in_clk_en_mask); // enable clock
		hdmiport_mask(VGIP_VGIP_CHN1_CTRL_reg, ~(VGIP_VGIP_CHN1_CTRL_ch1_ivrun_mask), VGIP_VGIP_CHN1_CTRL_ch1_ivrun_mask); // enable clock
		HDMI_PRINTF("[HDMI] measure use VGIP1\n");

	} else {	// if ( _CHANNEL2 == channel )
		// Disable SRC_Clock_Enbale bit
		hdmiport_mask(SUB_VGIP_VGIP_CHN2_CTRL_reg,~(SUB_VGIP_VGIP_CHN2_CTRL_ch2_in_clk_en_mask),0);
		// 2nd determine the input source
		hdmiport_mask(SUB_VGIP_VGIP_CHN2_CTRL_reg, ~(SUB_VGIP_VGIP_CHN2_CTRL_ch2_in_sel_mask|SUB_VGIP_VGIP_CHN2_CTRL_ch2_digital_mode_mask),SUB_VGIP_VGIP_CHN2_CTRL_ch2_digital_mode_mask);
		// 3rd enable SRC_Clock_Enbale bit
		hdmiport_mask(SUB_VGIP_VGIP_CHN2_CTRL_reg,~(SUB_VGIP_VGIP_CHN2_CTRL_ch2_in_clk_en_mask),SUB_VGIP_VGIP_CHN2_CTRL_ch2_in_clk_en_mask);
		hdmiport_mask(SUB_VGIP_VGIP_CHN2_CTRL_reg,~(SUB_VGIP_VGIP_CHN2_CTRL_ch2_ivrun_mask),SUB_VGIP_VGIP_CHN2_CTRL_ch2_ivrun_mask);
		HDMI_PRINTF("[HDMI] measure use VGIP2\n");
	}

}
#endif //#if HDMI_MEASURE_I3DDMA_SMART_FIT

#if HDMI_MEASURE_I3DDMA_SMART_FIT
unsigned char lib_hdmims_get_hvstart(HDMI_TIMING_T *tm, unsigned char vsc_ch)
{
// pre-condition:
//
// 0xb800d098[3] = 1

	int timeoutcnt;
	HDMI_SMT_PATH vgip_ch = HDMI_SMT_PATH_MAIN_VGIP;
	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_reg;
	sub_vgip_vgip_chn2_ctrl_RBUS sub_vgip_vgip_chn2_ctrl_reg;
#ifdef CONFIG_FORCE_RUN_I3DDMA
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_dma_vgip_ctrl_reg;
#endif
	vgip_vgip_chn1_act_hsta_width_RBUS vgip_vgip_chn1_act_hsta_width_reg;
	vgip_vgip_chn1_act_vsta_length_RBUS vgip_vgip_chn1_act_vsta_length_reg;
	sub_vgip_vgip_chn2_act_hsta_width_RBUS sub_vgip_vgip_chn2_act_hsta_width_reg;
	sub_vgip_vgip_chn2_act_vsta_length_RBUS sub_vgip_vgip_chn2_act_vsta_length_reg;
	dma_vgip_dma_vgip_act_hsta_width_RBUS dma_vgip_dma_vgip_act_hsta_width_reg;
	dma_vgip_dma_vgip_act_vsta_length_RBUS dma_vgip_dma_vgip_act_vsta_length_reg;

	vgip_vgip_chn1_ctrl_reg.regValue = hdmi_in(VGIP_VGIP_CHN1_CTRL_reg);
	sub_vgip_vgip_chn2_ctrl_reg.regValue = hdmi_in(SUB_VGIP_VGIP_CHN2_CTRL_reg);

	if(SLR_MAIN_DISPLAY == vsc_ch)
	{
#ifdef CONFIG_FORCE_RUN_I3DDMA
		dma_vgip_dma_vgip_ctrl_reg.regValue = hdmi_in(DMA_VGIP_DMA_VGIP_CTRL_reg);

		if(no_polarity_inverse_flag)
		{
			dma_vgip_dma_vgip_ctrl_reg.dma_vs_inv = 0;
			dma_vgip_dma_vgip_ctrl_reg.dma_hs_inv = 0;
		}
		else //if(_FALSE == no_polarity_inverse_flag)
		{
			if ((tm->polarity>>1)&0x01)
				dma_vgip_dma_vgip_ctrl_reg.dma_vs_inv = 0;
			else
				dma_vgip_dma_vgip_ctrl_reg.dma_vs_inv = 1;

			if ((tm->polarity)&0x01)
				dma_vgip_dma_vgip_ctrl_reg.dma_hs_inv = 0;
			else
				dma_vgip_dma_vgip_ctrl_reg.dma_hs_inv = 1;
		}

		vgip_ch = HDMI_SMT_PATH_DMA_VGIP;
		hdmi_out(DMA_VGIP_DMA_VGIP_CTRL_reg, dma_vgip_dma_vgip_ctrl_reg.regValue);
#else //#ifdef CONFIG_FORCE_RUN_I3DDMA

		if(no_polarity_inverse_flag)
		{
			vgip_vgip_chn1_ctrl_reg.ch1_vs_inv = 0;
			vgip_vgip_chn1_ctrl_reg.ch1_hs_inv = 0;
		}
		else// if(_FALSE == no_polarity_inverse_flag)
		{
			if ((tm->polarity>>1)&0x01)
				vgip_vgip_chn1_ctrl_reg.ch1_vs_inv = 0;
			else
				vgip_vgip_chn1_ctrl_reg.ch1_vs_inv = 1;

			if ((tm->polarity)&0x01)
				vgip_vgip_chn1_ctrl_reg.ch1_hs_inv = 0;
			else
				vgip_vgip_chn1_ctrl_reg.ch1_hs_inv = 1;
		}

		vgip_ch = HDMI_SMT_PATH_MAIN_VGIP;
		hdmi_out(VGIP_VGIP_CHN1_CTRL_reg, vgip_vgip_chn1_ctrl_reg.regValue);
#endif //#ifdef CONFIG_FORCE_RUN_I3DDMA
	}
	else if(SLR_SUB_DISPLAY == vsc_ch)
	{
		if(no_polarity_inverse_flag)
		{
			sub_vgip_vgip_chn2_ctrl_reg.ch2_vs_inv = 0;
			sub_vgip_vgip_chn2_ctrl_reg.ch2_hs_inv = 0;
		}
		else //if(_FALSE == no_polarity_inverse_flag)
		{
			if ((tm->polarity>>1)&0x01)
				sub_vgip_vgip_chn2_ctrl_reg.ch2_vs_inv = 0;
			else
				sub_vgip_vgip_chn2_ctrl_reg.ch2_vs_inv = 1;

			if ((tm->polarity)&0x01)
				sub_vgip_vgip_chn2_ctrl_reg.ch2_hs_inv = 0;
			else
				sub_vgip_vgip_chn2_ctrl_reg.ch2_hs_inv = 1;
		}

		vgip_ch = HDMI_SMT_PATH_SUB_VGIP;
		hdmi_out(SUB_VGIP_VGIP_CHN2_CTRL_reg, sub_vgip_vgip_chn2_ctrl_reg.regValue);
	}
	else
	{
		HDMI_EMG("NOT valid HDMI VGIP path!!\n");
		return FALSE;
	}

	SCALERDRV_WAIT_VS();//willychou add for polarity change

	lib_hdmims_set_vgip_clk_enable(vgip_ch);

#ifdef CONFIG_FORCE_RUN_I3DDMA
	// setup VGIP capture for smartfit measure
	if(HDMI_SMT_PATH_DMA_VGIP == vgip_ch)
	{
		dma_vgip_dma_vgip_act_hsta_width_reg.regValue = hdmi_in(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg);
		dma_vgip_dma_vgip_act_hsta_width_reg.dma_ih_act_sta = 0;
		dma_vgip_dma_vgip_act_hsta_width_reg.dma_ih_act_wid = 300;
		hdmi_out(DMA_VGIP_DMA_VGIP_ACT_HSTA_Width_reg, sub_vgip_vgip_chn2_act_hsta_width_reg.regValue);

		dma_vgip_dma_vgip_act_vsta_length_reg.regValue = hdmi_in(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg);
		dma_vgip_dma_vgip_act_vsta_length_reg.dma_iv_act_sta = 0;
		dma_vgip_dma_vgip_act_vsta_length_reg.dma_iv_act_len = 120;
		hdmi_out(DMA_VGIP_DMA_VGIP_ACT_VSTA_Length_reg, dma_vgip_dma_vgip_act_vsta_length_reg.regValue);
	}
#else //#ifdef CONFIG_FORCE_RUN_I3DDMA
	// setup VGIP capture for smartfit measure
	if(HDMI_SMT_PATH_MAIN_VGIP == vgip_ch)
	{
		vgip_vgip_chn1_act_hsta_width_reg.regValue = hdmi_in(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg);
		vgip_vgip_chn1_act_hsta_width_reg.ch1_ih_act_sta = 0;
		vgip_vgip_chn1_act_hsta_width_reg.ch1_ih_act_wid = 300;
		hdmi_out(VGIP_VGIP_CHN1_ACT_HSTA_Width_reg, vgip_vgip_chn1_act_hsta_width_reg.regValue);

		vgip_vgip_chn1_act_vsta_length_reg.regValue = hdmi_in(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg);
		vgip_vgip_chn1_act_vsta_length_reg.ch1_iv_act_sta = 0;
		vgip_vgip_chn1_act_vsta_length_reg.ch1_iv_act_len = 120;
		hdmi_out(VGIP_VGIP_CHN1_ACT_VSTA_Length_reg, vgip_vgip_chn1_act_vsta_length_reg.regValue);
	}
#endif //#ifdef CONFIG_FORCE_RUN_I3DDMA

	else if(HDMI_SMT_PATH_SUB_VGIP == vgip_ch)
	{
		sub_vgip_vgip_chn2_act_hsta_width_reg.regValue = hdmi_in(SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_reg);
		sub_vgip_vgip_chn2_act_hsta_width_reg.ch2_ih_act_sta = 0;
		sub_vgip_vgip_chn2_act_hsta_width_reg.ch2_ih_act_wid = 300;
		hdmi_out(SUB_VGIP_VGIP_CHN2_ACT_HSTA_Width_reg, sub_vgip_vgip_chn2_act_hsta_width_reg.regValue);

		sub_vgip_vgip_chn2_act_vsta_length_reg.regValue = hdmi_in(SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_reg);
		sub_vgip_vgip_chn2_act_vsta_length_reg.ch2_iv_act_sta = 0;
		sub_vgip_vgip_chn2_act_vsta_length_reg.ch2_iv_act_sta = 120;
		hdmi_out(SUB_VGIP_VGIP_CHN2_ACT_VSTA_Length_reg, sub_vgip_vgip_chn2_act_vsta_length_reg.regValue);
	}
	else
	{
		HDMI_EMG("NOT valid HDMI VGIP path!!\n");
		return _FALSE;
	}

	//disable smart fit
	hdmi_out(GET_SFT_AUTO_ADJ_VADDR(), 0x0);
	hdmi_out(GET_SFT_AUTO_ADJ_VADDR(), SMARTFIT_AUTO_ADJ_m_vgen_en_mask);

	// disable smartfit auto field selection
	hdmiport_mask(GET_SFT_AUTO_FIELD_VADDR(), ~(SMARTFIT_AUTO_FIELD_odd_sel_en_mask|SMARTFIT_AUTO_FIELD_odd_sel_mask), 0);
	hdmiport_mask(GET_SFT_AUTO_FIELD_VADDR(), ~(SMARTFIT_AUTO_FIELD_adj_source_mask), SMARTFIT_AUTO_FIELD_adj_source(vgip_ch));
	hdmiport_mask(GET_SFT_AUTO_FIELD_VADDR(), ~(SMARTFIT_AUTO_FIELD_smartfit_src_sel_mask), SMARTFIT_AUTO_FIELD_smartfit_src_sel_mask);//forg mango big ball

	// set Smartfit larger active region
	hdmi_out(GET_SFT_AUTO_H_BOUNDARY_VADDR(), SMARTFIT_AUTO_H_BOUNDARY_hb_sta(0) |  SMARTFIT_AUTO_H_BOUNDARY_hb_end(5000));
	hdmi_out(GET_SFT_AUTO_V_BOUNDARY_VADDR(), SMARTFIT_AUTO_V_BOUNDARY_vb_sta(0) | SMARTFIT_AUTO_V_BOUNDARY_vb_end(3000));

	hdmiport_mask(GET_SFT_AUTO_ADJ_VADDR(), ~(SMARTFIT_AUTO_ADJ_now_af_mask), SMARTFIT_AUTO_ADJ_now_af_mask);  //20140923 fix : AC on 1st measure will fail

	timeoutcnt = 30; // 3d need more time?!
	do {
		timeoutcnt --;
		if (!SMARTFIT_AUTO_ADJ_get_now_af(hdmi_in(GET_SFT_AUTO_ADJ_VADDR())))
			break;
		msleep(5);
	} while (timeoutcnt > 0);

	if (0 == timeoutcnt) {
		HDMI_EMG("[SFT][ERR] %s is not finish.\n", __func__);
		hdmi_out(GET_SFT_AUTO_FIELD_VADDR(), 0x0);
		return FALSE;
	}

	tm->v_act_sta = ((hdmi_in(GET_SFT_AUTO_RESULT_VSTA_END_VADDR()) >> 16) & 0xFFF)-1;
	tm->h_act_sta = ((hdmi_in(GET_SFT_AUTO_RESULT_HSTA_END_VADDR()) >> 16) & 0xFFF)-3;

	if (tm->is_interlace) {
		if ((tm->v_total & 0x01)) {	//  ODD field
			tm->v_act_sta--;
		}
	}

	hdmi_out(GET_SFT_AUTO_FIELD_VADDR() , 0x0);

	HDMI_PRINTF("[SFT] IHStr: %d\n", tm->h_act_sta);
	HDMI_PRINTF("[SFT] IVStr: %d\n", tm->v_act_sta);

	return TRUE;
}
#else //#if HDMI_MEASURE_I3DDMA_SMART_FIT
unsigned char lib_hdmims_get_hvstart(HDMI_TIMING_T *tm, unsigned char vsc_ch)
{
// pre-condition:
//
// 0xb800d098[3] = 1

	int timeoutcnt;
	unsigned char vgip_ch = 0; //need to check: Hdmi_GetVGIPChannel();
	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_reg;
	sub_vgip_vgip_chn2_ctrl_RBUS sub_vgip_vgip_chn2_ctrl_reg;

#if 1
	vgip_vgip_chn1_ctrl_reg.regValue = hdmi_in(VGIP_VGIP_CHN1_CTRL_reg);
	sub_vgip_vgip_chn2_ctrl_reg.regValue = hdmi_in(SUB_VGIP_VGIP_CHN2_CTRL_reg);

	if(0 == vgip_vgip_chn1_ctrl_reg.ch1_in_sel)
	{
		if(no_polarity_inverse_flag)
		{
			vgip_vgip_chn1_ctrl_reg.ch1_vs_inv = 0;
			vgip_vgip_chn1_ctrl_reg.ch1_hs_inv = 0;
		}
		else// if(_FALSE == no_polarity_inverse_flag)
		{
			if ((tm->polarity>>1)&0x01)
				vgip_vgip_chn1_ctrl_reg.ch1_vs_inv = 0;
			else
				vgip_vgip_chn1_ctrl_reg.ch1_vs_inv = 1;

			if ((tm->polarity)&0x01)
				vgip_vgip_chn1_ctrl_reg.ch1_hs_inv = 0;
			else
				vgip_vgip_chn1_ctrl_reg.ch1_hs_inv = 1;
		}
		vgip_ch = 0;

		hdmi_out(VGIP_VGIP_CHN1_CTRL_reg, vgip_vgip_chn1_ctrl_reg.regValue);
	}
	else if(0 == sub_vgip_vgip_chn2_ctrl_reg.ch2_in_sel)
	{
		if(no_polarity_inverse_flag)
		{
			sub_vgip_vgip_chn2_ctrl_reg.ch2_vs_inv = 0;
			sub_vgip_vgip_chn2_ctrl_reg.ch2_hs_inv = 0;
		}
		else //if(_FALSE == no_polarity_inverse_flag)
		{
			if ((tm->polarity>>1)&0x01)
				sub_vgip_vgip_chn2_ctrl_reg.ch2_vs_inv = 0;
			else
				sub_vgip_vgip_chn2_ctrl_reg.ch2_vs_inv = 1;

			if ((tm->polarity)&0x01)
				sub_vgip_vgip_chn2_ctrl_reg.ch2_hs_inv = 0;
			else
				sub_vgip_vgip_chn2_ctrl_reg.ch2_hs_inv = 1;
		}

		vgip_ch = 1;
		hdmi_out(SUB_VGIP_VGIP_CHN2_CTRL_reg, sub_vgip_vgip_chn2_ctrl_reg.regValue);
	}
	else {
		HDMI_EMG("NOT valid HDMI VGIP path!!\n");
		return FALSE;
	}
#else //#if 1
	if (((tm->polarity>>1)&0x01) || no_polarity_inverse_flag)   hdmiport_mask(GET_VGIP_CHNx_CTRL_ADDR(), ~(VGIP_VGIP_CHN1_CTRL_ch1_vs_inv_mask), 0);
	else                       hdmiport_mask(GET_VGIP_CHNx_CTRL_ADDR(), ~(VGIP_VGIP_CHN1_CTRL_ch1_vs_inv_mask), VGIP_VGIP_CHN1_CTRL_ch1_vs_inv_mask);

	if (((tm->polarity)&0x01) || no_polarity_inverse_flag)    hdmiport_mask(GET_VGIP_CHNx_CTRL_ADDR(), ~(VGIP_VGIP_CHN1_CTRL_ch1_hs_inv_mask), 0);
	else                        hdmiport_mask(GET_VGIP_CHNx_CTRL_ADDR(), ~(VGIP_VGIP_CHN1_CTRL_ch1_hs_inv_mask), VGIP_VGIP_CHN1_CTRL_ch1_hs_inv_mask);
#endif //#if 1

	SCALERDRV_WAIT_VS();//willychou add for polarity change

	lib_hdmims_set_vgip_clk_enable(vgip_ch);

	// setup VGIP capture for smartfit measure
	hdmi_out(GET_VGIP_CHNx_V_CAP_ADDR(), (0 << 16) | (120));
	hdmi_out(GET_VGIP_CHNx_H_CAP_ADDR(), (0 << 16) | (300));

	//disable smart fit
	hdmi_out(GET_SFT_AUTO_ADJ_VADDR(), 0x0);
	hdmi_out(GET_SFT_AUTO_ADJ_VADDR(), SMARTFIT_AUTO_ADJ_m_vgen_en_mask);

	// disable smartfit auto field selection
	hdmiport_mask(GET_SFT_AUTO_FIELD_VADDR(), ~(SMARTFIT_AUTO_FIELD_odd_sel_en_mask|SMARTFIT_AUTO_FIELD_odd_sel_mask), 0);
	hdmiport_mask(GET_SFT_AUTO_FIELD_VADDR(), ~(SMARTFIT_AUTO_FIELD_adj_source_mask), SMARTFIT_AUTO_FIELD_adj_source(vgip_ch));
	hdmiport_mask(GET_SFT_AUTO_FIELD_VADDR(), ~(SMARTFIT_AUTO_FIELD_smartfit_src_sel_mask), SMARTFIT_AUTO_FIELD_smartfit_src_sel_mask);//forg mango big ball

	// set Smartfit larger active region
	hdmi_out(GET_SFT_AUTO_H_BOUNDARY_VADDR(), SMARTFIT_AUTO_H_BOUNDARY_hb_sta(0) |  SMARTFIT_AUTO_H_BOUNDARY_hb_end(5000));
	hdmi_out(GET_SFT_AUTO_V_BOUNDARY_VADDR(), SMARTFIT_AUTO_V_BOUNDARY_vb_sta(0) | SMARTFIT_AUTO_V_BOUNDARY_vb_end(3000));

	hdmiport_mask(GET_SFT_AUTO_ADJ_VADDR(), ~(SMARTFIT_AUTO_ADJ_now_af_mask), SMARTFIT_AUTO_ADJ_now_af_mask);  //20140923 fix : AC on 1st measure will fail

	timeoutcnt = 30; // 3d need more time?!
	do {
		timeoutcnt --;
		if (!SMARTFIT_AUTO_ADJ_get_now_af(hdmi_in(GET_SFT_AUTO_ADJ_VADDR())))
			break;
		msleep(5);
	} while (timeoutcnt > 0);

	if (0 == timeoutcnt) {
		HDMI_EMG("[SFT][ERR] %s is not finish.\n", __func__);
		hdmi_out(GET_SFT_AUTO_FIELD_VADDR(), 0x0);
		return FALSE;
	}

	tm->v_act_sta = ((hdmi_in(GET_SFT_AUTO_RESULT_VSTA_END_VADDR()) >> 16) & 0xFFF)-1;
	tm->h_act_sta = ((hdmi_in(GET_SFT_AUTO_RESULT_HSTA_END_VADDR()) >> 16) & 0xFFF)-3;

	if (tm->is_interlace) {
		if ((tm->v_total & 0x01)) {	//  ODD field
			tm->v_act_sta--;
		}
	}

	hdmi_out(GET_SFT_AUTO_FIELD_VADDR() , 0x0);

	HDMI_PRINTF("[SFT] IHStr: %d\n", tm->h_act_sta);
	HDMI_PRINTF("[SFT] IVStr: %d\n", tm->v_act_sta);

	return TRUE;
}
#endif //#if HDMI_MEASURE_I3DDMA_SMART_FIT

//USER:LewisLee DATE:2015/11/09
//Fix error timing let picture abnormal
unsigned char lib_hdmi_skiptiming_condition(HDMI_TIMING_T *timing)
{
	//WOSQRTK-9205, HDD Player, APPLE TV
	// 1832x540 progressive NG,
	if(HDMI_ABS(timing->h_act_len, 1832) < 10)
	{
		if(HDMI_ABS(timing->v_act_len, 540) < 10)
		{
			if(0 == timing->is_interlace)
			{
				HDMI_PRINTF("SkipTiming h_act_len=%d, v_act_len=%d, v_total=%d, h_total=%d\n", timing->h_act_len, timing->v_act_len, timing->v_total, timing->h_total);
				return TRUE;
			}
		}
	}

	//WOSQRTK-9205, HDD Player, APPLE TV
	// 1280x716 NG
	if(HDMI_ABS(timing->h_act_len, 1280) < 5)
	{
		if(HDMI_ABS(timing->v_act_len, 716) < 2)
		{
			if(HDMI_ABS(timing->v_freq, 501) < 2)
			{
				HDMI_PRINTF("SkipTiming h_act_len=%d, v_act_len=%d, v_total=%d, h_total=%d\n", timing->h_act_len, timing->v_act_len, timing->v_total, timing->h_total);
				return TRUE;
			}
		}
	}

	//WOSQRTK-9205, HDD Player, APPLE TV
	// 1360x766x60 / 1360x760x60 1360x477x60 / 1360x764x60 NG
	if(HDMI_ABS(timing->h_act_len, 1360) < 5)
	{
		if(timing->v_act_len <= 766)
		{
			if(HDMI_ABS(timing->v_freq, 600) < 2)
			{
				HDMI_PRINTF("SkipTiming h_act_len=%d, v_act_len=%d, v_total=%d, h_total=%d\n", timing->h_act_len, timing->v_act_len, timing->v_total, timing->h_total);
				return TRUE;
			}
		}
	}

	//WOSQRTK-9306, [40000] Radeon R9 390 OC D5 8GB Tri-X NITRO - SAPPHIRE
	// 2016x2160x57.7Hz progressive NG,
	// if DVI=> HDMI, it will have 1984x2160x57.7 Hz
	if(HDMI_ABS(timing->v_act_len, 2160) < 10)
	{
		if(timing->h_act_len <= 3200)
		{
			HDMI_PRINTF("SkipTiming h_act_len=%d, v_act_len=%d, v_total=%d, h_total=%d\n", timing->h_act_len, timing->v_act_len, timing->v_total, timing->h_total);
			return TRUE;
		}
	}

/*
	if(HDMI_ABS(timing->h_act_len, 1082) < 10)
	{
		if(HDMI_ABS(timing->v_act_len, 499) < 10)
		{
			//BH9520, 1082x499 error timing
			HDMI_PRINTF("SkipTiming h_act_len=%d, v_act_len=%d, v_total=%d, h_total=%d\n", timing->h_act_len, timing->v_act_len, timing->v_total, timing->h_total);
			return TRUE;
		}
	}
*/
/*
	if(HDMI_ABS(timing->v_act_len, 1080) < 10)
	{
		if(timing->h_act_len < 800)
		{
			// MSPG 7100 / 7600, change timing too fast, have short time 760x1080 error timing
			HDMI_PRINTF("SkipTiming h_act_len=%d, v_act_len=%d, v_total=%d, h_total=%d\n", timing->h_act_len, timing->v_act_len, timing->v_total, timing->h_total);
			return TRUE;
		}
	}
*/
/*
	//USER:LewisLee DATE:2016/05/24
	//move from Hdmi_OffLineMeasure()
	if (timing->v_act_len == 1080)
	{
		//cloud modify for 1910 problem
		if ((timing->h_act_len > 1905 && timing->h_act_len < 1919) || (timing->h_act_len > 1921 && timing->h_act_len < 1935))
		{
			if(HDMI_ABS(timing->h_act_len, 1920) <= 5)
			{
				if(ucSkip_1080P_Cnt < 2 )
				{
					HDMI_PRINTF("SkipTiming I, H=%d, V=%d, cnt=%d\n", timing->h_act_len, timing->v_act_len, ucSkip_1080P_Cnt);
					ucSkip_1080P_Cnt++;
					return TRUE;
				}
			}
			else// if(HDMI_ABS(timing->h_act_len, 1920) > 5)
			{
				ucSkip_1080P_Cnt = 0;
				HDMI_PRINTF("SkipTiming II, H=%d, V=%d, cnt=%d\n", timing->h_act_len, timing->v_act_len, ucSkip_1080P_Cnt);
				return TRUE;
			}
		}
	}
*/
/*
	//blu-ray player, bd-c6900
	if(timing->h_act_len <= timing->v_act_len)
	{
		HDMI_PRINTF("Abnormal Timing h_act_len=%d, v_act_len=%d, v_total=%d, h_total=%d\n", timing->h_act_len, timing->v_act_len, timing->v_total, timing->h_total);

		if(timing->h_act_len <= 600)
		{
			HDMI_PRINTF("SkipTiming\n");
			return TRUE;
		}

		//Minchay@21060117#WOSQRTK-5224 Invalid Format - 960*2160 issue
		if((timing->v_act_len >= 2150)&& (timing->v_act_len <= 2170))
		{//v:2160
			if(timing->h_act_len <= 1500)
			{//h <= 1500
				HDMI_PRINTF("SkipTiming\n");
				return TRUE;
			}
		}
	}
*/
	return FALSE;
}

