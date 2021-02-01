/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		hdmiPhy.c
 *
 * author: 	Iron Man, Tony Stark
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include "hdmi_common.h"

#if MHL_SUPPORT
#include "mhl_driver.h"
#endif


/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/

#ifndef IRQ_HANDLED
#define IRQ_HANDLED  1
#define IRQ_NONE     0
#endif


#define CLOCK_TOLERANCE(port)		(phy_st[port].clk_tolerance)
#define CLK_DEBOUNCE_CNT		7       // Set 2, it will easy to set phy in background and influence others.
#define CLK_DEBOUNCE_SHORT_CNT		1       // to prevent Tx HDCP handshake too fast
#define NOCLK_DEBOUNCE_CNT		8       // count for confirm it's no clock, (QD980>5, has sudden no clock and clear scdc)
#define CLK_UNSTABLE_CNT		2       // count for clock unstable change

#define TMDS_CHAR_ERR_PERIOD		4
#define TMDS_CHAR_ERR_THREAD		8
#define TMDS_CHAR_ERR_MAX_LOOP	8	//TMDS_CHAR_ERR_PERIOD*2 is safe

#define TMDS_BIT_ERR_PERIOD		16
#define TMDS_BIT_ERR_THREAD		8
#define TMDS_BIT_ERR_MAX_LOOP		32	//TMDS_BIT_ERR_PERIOD*2 is safe

#define MAX_ERR_DETECT_TIMES	50

#define ManualZ0        			PHY_Z0
#define HDMI_EQ_LE_NOT_ZERO_ENABLE



//TMDS clock define
#define TMDS_6G		5688
#define TMDS_5G		4740
#define TMDS_4G		3792
#define TMDS_3G		2844
#define TMDS_1p5G	1422




#ifndef MAX
    #define MAX(a,b)                (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
    #define MIN(a,b)                (((a) < (b)) ? (a) : (b))
#endif




/**********************************************************************************************
*
*	Const Declarations
*
**********************************************************************************************/

typedef unsigned char UINT8;
//typedef char INT8;
typedef unsigned int UINT32;
typedef int INT32;
typedef unsigned short UINT16;
typedef short INT16;


//Fvco = (Fi*M*Prescalar*CMU_SEL_D4)/N
HDMI_PHY_PARAM_T hdmi_phy_param[] =
{
	//           M  pscaler KVCO  CS  Icp_D   CK_LDO DEMUX  PIX2_SEL CSEL  Kp1         Ki      EQ_gain  EQ_adj   vsel_LDO
	//              N   SEL_D4 EN_CAP Icp  RS    PI_DIV RATE_SEL ISEL  CDR_bias  Kp2        KD     EQ_bias    PR
	{2844,1422,  0x10,0x2,0x0,0x0,0x0,  0x0,0x3,0x9,0x1,0x4,  0x0,0x0,0x1,0x6,0x0,  0x2,0x2,0x0,(0x6<<2),0x0,  0x1,0x0,0x0,0x0,0x0,  0x0,0x0,0x3,0, "150M~300M full rate"},	   // 150~300 M For LG UD generator issue to change Kp 5=>6 , M/N => 20/2
	{1422,711,    0x10,0x1,0x0,0x0,0x0,  0x0,0x3,0x9,0x1,0x4,  0x0,0x1,0x2,0x1,0x0,  0x2,0x2,0x0,(0x8<<2),0x0,  0x0,0x0,0x0,0x0,0x0,  0x0,0x0,0x3,0, "75M~150M full rate+DS1"},	// 75~150 M
	{711, 355,     0x10,0x0,0x0,0x0,0x0,  0x0,0x3,0x9,0x1,0x4,  0x0,0x2,0x3,0x2,0x0,  0x2,0x2,0x0,(0x8<<2),0x0,  0x0,0x0,0x0,0x0,0x0,  0x0,0x0,0x3,0, "37.5M~75M full rate+DS2"},	//37.5~75M
	{355, 177,     0x24,0x0,0x0,0x0,0x0,  0x0,0x3,0xe,0x1,0x6,  0x0,0x3,0x3,0x2,0x0,  0x2,0x2,0x0,(0x8<<2),0x0,  0x0,0x0,0x0,0x0,0x0,  0x0,0x0,0x3,0, "18.75M~37.5M full rate+DS3"}, // 13.5M~ 37.5M
	{177, 120,     0x4c,0x0,0x0,0x0,0x0,  0x0,0x3,0xa,0x1,0x6,  0x0,0x4,0x3,0x2,0x0,  0x2,0x2,0x0,(0x8<<2),0x0,  0x0,0x0,0x0,0x0,0x0,  0x0,0x0,0x3,0, "13.5M~18.75M full rate+DS4"}, // 13.5M~ 37.5M
};


#define MHL_USE_ACDR 0
#if MHL_USE_ACDR

#if 0 //need to check
#define MHL_TABLE_SIZE 6
HDMI_PHY_PARAM_T  mhl_phy_param[MHL_TABLE_SIZE] = {
	{ 5860, 2854, 16, 0, 0, 1, 0x0, 0x3, 0x4, 0x2, 0x2, 0x1, (0x02<<2), 0x0, 0x1, 0x0, 0x0, 0x1, 0x3, 0x0, 0x0, 7, "300M~6000M half rate"},  // 301~600 M //from hdmi
	{ 2854, 2190, 36, 0, 1, 2, 0x1, 0x3, 0x5, 0x3, 0x2, 0x1, (0x06<<2), 0x0, 0x1, 0x0, 0x0, 0x1, 0x3, 0x0, 0x0, 6, "231M~300M full rate"},     // 231~300 M //mhl 2.0
	{ 2854, 2190, 36, 2, 0, 2, 0x1, 0x3, 0x4, 0x2, 0x4, 0x1, (0x03<<2), 0x4, 0x1, 0x0, 0x1, 0x1, 0x7, 0x0, 0x0, 7, "231M~300M full rate"},     // 231~300 M
	{ 2190, 1432, 26, 0, 1, 2, 0x1, 0x3, 0x7, 0x2, 0x2, 0x1, (0x07<<2), 0x0, 0x1, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0, 6, "151M~230M full rate"},	   // 151~230 M
	{ 1432,   768, 36, 1, 1, 3, 0x2, 0x3, 0x4, 0x2, 0x9, 0x1, (0x03<<2), 0x0, 0x0, 0x0, 0x1, 0x1, 0x7, 0x1, 0x0, 7, "81M~150M full rate+DS1"},	// 81~150 M //from hdmi
	{   768,   355, 56, 0, 2, 3, 0x2, 0x3, 0x6, 0x3, 0x9, 0x1, (0x0a<<2), 0x0, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x0, 6, "37.5M~80M full rate+DS2"},	//37.5~80M
};
#endif

#else

#if MHL3_ENABLE
HDMI_PHY_PARAM_T  mhl3_phy_param[] = {
	{5860,2844,	16,0,0x0,0,1,	0,0x4,7,0,0x2,	0x3,0,1,0x0,0,	0,0,0x1,(0x02<<2), 0x0,	0x1,0x0,0x0,0x1,0x2,	0x3,0x0,0x3,0x0, "300M~6000M half rate"},  //from hdmi 6G
	{2844,1422,	36,2,0x0,0,1,	0,0x4,7,0,0x2,	0x3,0,2,0x1,1,	0,0,0x1,(0x03<<2),0x4,	0x1,0x0,0x1,0x1,0x4,	0x7,0x0,0x3,0x0, "150M~300M full rate"},	   // 3G
	{1422,711,	36,1,0x0,0,1,	0,0x4,7,0,0x2,	0x3,1,3,0x2,1,	0,0,0x1,(0x03<<2), 0x0,	0x0,0x0,0x1,0x1,0x9,	0x7,0x1,0x3,0x0, "75M~150M full rate+DS1"},	// 1.5G

};
#endif


HDMI_PHY_PARAM_T  mhl_phy_pp_param[] = {

	{  711, 356,	0x24,0x0,0x1,0x0,0x0,	0x0,0x03,0x7,0x1,0x4, 	0x0,0x0,0x1,0x6,0x0,	0x2,0x2,0x0,(0x06<<2),0x0,	  0x1,0x0,0x0,0x0,0x0,	0x0,0x0,0x3,0x0,"75M~38M half rate"},
	{  356, 0, 	0x24,0x0,0x0,0x0,0x0,	0x0,0x03,0x9,0x1,0x6,	0x0,0x1,0x2,0x1,0x0,	0x2,0x2,0x0,(0x08<<2),0x0,	  0x0,0x0,0x0,0x0,0x0,	0x0,0x0,0x3,0x0,"37M~0M half rate"},
};

HDMI_PHY_PARAM_T  mhl_phy_param[] = {
	{  1090, 956,	 0x1a,0x0,0x1,0x0,0x1,	 0x0,0x03,0x6,0x1,0x4,	 0x0,0x0,0x1,0x6,0x0,	0x2,0x2,0x0,(0x8<<2),0x0,	0x1,0x0,0x0,0x0,0x0,	0x0,0x0,0x3,0x0,"115M~101M half rate"},
	{  956,   482,	 0x1a,0x0,0x1,0x0,0x0,	 0x0,0x03,0x6,0x1,0x4,	 0x0,0x0,0x1,0x6,0x0,	0x2,0x2,0x0,(0x6<<2),0x0,	0x1,0x0,0x0,0x0,0x0,	0x0,0x0,0x3,0x0,"100M~51M full rate"},
	{  482,   236,	 0x38,0x0,0x1,0x0,0x0,	 0x0,0x03,0xa,0x1,0x5,	 0x0,0x1,0x2,0x1,0x0,	0x2,0x2,0x0,(0x8<<2),0x0,	0x0,0x0,0x0,0x0,0x0,	0x0,0x0,0x3,0x0,"50M~25M full rate"},
	{  236,   0,	 0x74,0x0,0x1,0x0,0x0,	 0x0,0x03,0xa,0x1,0x6,	 0x0,0x2,0x3,0x2,0x0,	0x2,0x2,0x0,(0x8<<2),0x0,	0x0,0x0,0x0,0x0,0x0,	0x0,0x0,0x3,0x0,"24M~0M full rate"},
};


#endif

#if 0
DFE_INIT_T dfe_init[] = {

};


const unsigned int reg_ck1[HDMI_PORT_TOTAL_NUM] ={
	DFE_HDMI_RX_PHY_P0_CK1_reg,
	DFE_HDMI_RX_PHY_P1_CK1_reg,
	DFE_HDMI_RX_PHY_P2_CK1_reg};


const unsigned int reg_ck2[HDMI_PORT_TOTAL_NUM] ={
	DFE_HDMI_RX_PHY_P0_CK2_reg,
	DFE_HDMI_RX_PHY_P1_CK2_reg,
	DFE_HDMI_RX_PHY_P2_CK2_reg};

const unsigned int reg_rgb1[HDMI_PORT_TOTAL_NUM][3] ={
	{DFE_HDMI_RX_PHY_P0_R1_reg, DFE_HDMI_RX_PHY_P0_G1_reg, DFE_HDMI_RX_PHY_P0_B1_reg},
	{DFE_HDMI_RX_PHY_P1_R1_reg, DFE_HDMI_RX_PHY_P1_G1_reg, DFE_HDMI_RX_PHY_P1_B1_reg},
	{DFE_HDMI_RX_PHY_P2_R1_reg, DFE_HDMI_RX_PHY_P2_G1_reg, DFE_HDMI_RX_PHY_P2_B1_reg}};

const unsigned int reg_rgb2[HDMI_PORT_TOTAL_NUM][3] ={
	{DFE_HDMI_RX_PHY_P0_R2_reg, DFE_HDMI_RX_PHY_P0_G2_reg, DFE_HDMI_RX_PHY_P0_B2_reg},
	{DFE_HDMI_RX_PHY_P1_R2_reg, DFE_HDMI_RX_PHY_P1_G2_reg, DFE_HDMI_RX_PHY_P1_B2_reg},
	{DFE_HDMI_RX_PHY_P2_R2_reg, DFE_HDMI_RX_PHY_P2_G2_reg, DFE_HDMI_RX_PHY_P2_B2_reg}};

const unsigned int reg_rgb3[HDMI_PORT_TOTAL_NUM][3] ={
	{DFE_HDMI_RX_PHY_P0_R3_reg, DFE_HDMI_RX_PHY_P0_G3_reg, DFE_HDMI_RX_PHY_P0_B3_reg},
	{DFE_HDMI_RX_PHY_P1_R3_reg, DFE_HDMI_RX_PHY_P1_G3_reg, DFE_HDMI_RX_PHY_P1_B3_reg},
	{DFE_HDMI_RX_PHY_P2_R3_reg, DFE_HDMI_RX_PHY_P2_G3_reg, DFE_HDMI_RX_PHY_P2_B3_reg}};
#endif

const unsigned int reg_mod[HDMI_PHY_TOTAL_NUM] ={
	DFE_HDMI_RX_PHY_P0_REGD07_reg,
	DFE_HDMI_RX_PHY_P1_REGD27_reg,
	DFE_HDMI_RX_PHY_P2_REGD07_reg};


typedef enum {
	PHY_PROC_INIT,
	PHY_PROC_RECORD,
	PHY_PROC_CLOSE_ADP,


	PHY_PROC_RECOVER_6G_LONGCABLE,
	PHY_PROC_RECOVER_6G_LONGCABLE_RECORD,
	PHY_PROC_RECOVER_6G_LONGCABLE_CLOSE_ADP,

	PHY_PROC_RECOVER_MI,
	PHY_PROC_RECOVER_MID_BAND_LONGCABLE,
	PHY_PROC_DONE,
} HDMIRX_PHY_PROC_T;


typedef struct {
	unsigned char vth;
	unsigned char tap0;
	unsigned char tap0max;
	unsigned char tap0min;
	unsigned char tap1;
	unsigned char le;
	unsigned char lemax;
	unsigned char lemin;
	signed char tap2;
}HDMIRX_PHY_DFE_T;

typedef struct {
	unsigned int clk;
	unsigned int clk_pre;
	unsigned int clk_debounce_count;
	unsigned int clk_unstable_count;
	unsigned int noclk_debounce_count;
	unsigned int clk_tolerance;
	unsigned char clk_stable;

	unsigned char rxphy_40x;

	HDMIRX_PHY_PROC_T phy_proc_state;

	unsigned int char_err_loop;
	unsigned int char_err_occurred;
	unsigned char detect_6g_longcable;

	unsigned int bit_err_loop;
	unsigned int bit_err_occurred;

	unsigned int error_detect_count;
	HDMIRX_PHY_DFE_T dfe_t[3];

} HDMIRX_PHY_STRUCT_T;






/**********************************************************************************************
*
*	Variables
*
**********************************************************************************************/
unsigned int clock_bound_3g;
unsigned int clock_bound_1p5g;
unsigned int clock_bound_110m;
unsigned int clock_bound_45m;

HDMIRX_PHY_STRUCT_T phy_st[HDMI_PHY_TOTAL_NUM];

unsigned int phy_isr_en[HDMI_PHY_TOTAL_NUM];
unsigned char cur_error_detect_timestamp;



/**********************************************************************************************
*
*	Funtion Declarations
*
**********************************************************************************************/




unsigned char newbase_rxphy_measure(unsigned char port);
unsigned char newbase_rxphy_is_clock_stable(unsigned char port, unsigned int clk_tmp);
void newbase_rxphy_job(unsigned char p);




void lib_hdmi_wdg_rst(unsigned char port, unsigned char rst);
void lib_hdmi_afifo_enable(unsigned char nport, unsigned char enable);
void lib_hdmi_mac_reset(unsigned char port);
//void lib_hdmi_mac_release(unsigned char port);
void lib_hdmi_dfe_power(unsigned char port, unsigned char en);
void lib_hdmi_eq_bias_band_setting(unsigned char bport, unsigned int b);

void lib_hdmi_set_dfe(unsigned char nport, unsigned int b, unsigned char dfe_mode);
void lib_hdmi_set_dfe_mid_band(unsigned char nport, unsigned int b_clk, int dfe_mode);
void lib_hdmi_dfe_manual_set(unsigned char nport);
unsigned char lib_hdmi_dfe_tap0_fix(unsigned char nport);
void lib_hdmi_dfe_second_flow(unsigned char nport, unsigned int b_clk);
void lib_hdmi_load_le_max(unsigned char nport);
void lib_hdmi_dfe_examine_le_coef(unsigned char nport, unsigned int b_clk);
void lib_hdmi_set_dfe_close(unsigned char nport);
void lib_hdmi_dfe_record_enable(unsigned char nport, unsigned char onoff);
unsigned char lib_hdmi_dfe_is_record_enable(unsigned char nport);
void lib_hdmi_dfe_adaptation(unsigned char nport, unsigned char bgr, unsigned int adp_mask, unsigned char onoff);
void lib_hdmi_dfe_init_vth(unsigned char nport, unsigned char bgr, unsigned char value);
void lib_hdmi_dfe_init_tap0(unsigned char nport, unsigned char bgr, unsigned char value);
void lib_hdmi_dfe_init_tap1(unsigned char nport, unsigned char bgr, unsigned char value);
void lib_hdmi_dfe_init_tap2(unsigned char nport, unsigned char bgr, signed char value);
void lib_hdmi_dfe_init_le(unsigned char nport, unsigned char bgr, unsigned char value);
void lib_hdmi_dfe_load_in_adp(unsigned char nport, unsigned char bgr, unsigned int option);
unsigned char lib_hdmi_dfe_get_vth(unsigned char nport, unsigned char lane);
unsigned char lib_hdmi_dfe_get_tap0(unsigned char nport, unsigned char lane);
unsigned char lib_hdmi_dfe_get_tap0max(unsigned char nport, unsigned char lane);
unsigned char lib_hdmi_dfe_get_tap0min(unsigned char nport, unsigned char lane);
unsigned char lib_hdmi_dfe_get_tap1(unsigned char nport, unsigned char lane);
unsigned char lib_hdmi_dfe_get_tap1max(unsigned char nport, unsigned char lane);
unsigned char lib_hdmi_dfe_get_tap1min(unsigned char nport, unsigned char lane);
char lib_hdmi_dfe_get_tap2(unsigned char nport, unsigned char lane);
unsigned char lib_hdmi_dfe_get_le(unsigned char nport, unsigned char lane);
unsigned char lib_hdmi_dfe_get_lemax(unsigned char nport, unsigned char lane);
unsigned char lib_hdmi_dfe_get_lemin(unsigned char nport, unsigned char lane);





void lib_hdmi_cmu_pll_en(unsigned char nport, unsigned char enable);
void lib_hdmi_demux_ck_vcopll_rst(unsigned char nport, unsigned char rst);
void lib_hdmi_dfe_rst(unsigned char nport, unsigned char rst);
void lib_hdmi_cdr_rst(unsigned char nport, unsigned char rst);
void lib_hdmi_wdog(unsigned char nport);
void lib_hdmi_dfe_config_setting(unsigned char nport);
void lib_hdmi_set_mhl_phy_table(unsigned char bport, unsigned char mode);
void lib_hdmi_set_phy_table(unsigned char bport, HDMI_PHY_PARAM_T *phy_param);
void lib_hdmi_cco_band_config(unsigned char nport, unsigned int bclk);

unsigned char lib_hdmi_acdr_check_result(unsigned char nport);
unsigned char lib_hdmi_find_mhl_mode(unsigned int bvalue, unsigned char is_mhl_pp, unsigned char is_mhl3);
void lib_hdmi_acdr_config_setting(unsigned char nport, unsigned char enable, unsigned int b);
void lib_hdmi_fg_koffset_manual_adjust(unsigned char port, unsigned int r, unsigned int g, unsigned int b);
void lib_hdmi_fg_koffset_manual(unsigned char port);
void lib_hdmi_fg_koffset_auto(unsigned char port);
void lib_hdmi_fg_koffset_proc(unsigned char nport);
void lib_hdmi_fg_koffset_disable(unsigned char port);
void lib_hdmi_z0_calibration(void);

void lib_hdmi_char_err_rst(unsigned char nport, unsigned char rst);
void lib_hdmi_char_err_start(unsigned char nport, unsigned char conti_mode, unsigned char period);
unsigned char lib_hdmi_char_err_det_done(unsigned char nport);
unsigned char lib_hdmi_char_err_get_error(unsigned char nport, unsigned int *r_err, unsigned int *g_err, unsigned int *b_err);
void lib_hdmi_bit_err_start(unsigned char nport, unsigned char conti_mode, unsigned char period);
unsigned char lib_hdmi_bit_err_det_done(unsigned char nport);
unsigned char lib_hdmi_bit_err_get_error(unsigned char nport, unsigned int *r_err, unsigned int *g_err, unsigned int *b_err);
//void lib_hdmi_single_end(unsigned char nport, unsigned char channel, unsigned char p_off, unsigned char n_off);










#if 1 //only for jtest
void debug_hdmi_dfe_scan(unsigned char nport);
#endif






/**********************************************************************************************
*
*	Function Body
*
**********************************************************************************************/

void newbase_rxphy_isr_set(unsigned char port, unsigned char en)
{
	phy_isr_en[port] = en;
}

void newbase_rxphy_init_struct(unsigned char port)
{
	memset(&phy_st[port], 0, sizeof(HDMIRX_PHY_STRUCT_T));
}


int newbase_rxphy_isr(void)
{
	unsigned char i;

#if HDMI_INTERNAL_1K
	newbase_hdmi_control_pull_up_1k();
#endif

	if (hdmi_in(DEBUG_REG_ADDR)&DEBUG_29_BYPASS_PHY_ISR) {
		return IRQ_HANDLED;
	}

#if MHL_SUPPORT
	if (DETECT_MHL2_IN) {
		CBUS_TIMER_Handle_ISR();
		MHLCBUS_ISR();
	}
#endif

	for (i=0; i<HDMI_PHY_TOTAL_NUM; i++) {
		if (!phy_isr_en[i]) {
			continue;
		}

		if (newbase_rxphy_measure(i)) {
			newbase_rxphy_job(i);
		} else {
			newbase_hdmi_reset_video_state(i);
		}

		newbase_hdcp_handler(i);

		newbase_hdmi_check_connection_state(i);
#if HDMI2p0
		lib_hdmi2p0_scdc_update_flag(i);
#endif

	}

	return IRQ_HANDLED;

}

unsigned char newbase_rxphy_measure(unsigned char port)
{
unsigned int clk_tmp = 0;
unsigned char clk_stable_prev = phy_st[port].clk_stable;

	if (lib_hdmi_is_clk_ready(port)) {
		clk_tmp = lib_hdmi_get_clock(port);
#if HDMI2p0
		newbase_hdmi2p0_check_tmds_config(port); //check scdc flag
#endif
	}

	lib_hdmi_trigger_measure_start(port);

	if (clk_tmp > VALID_MIN_CLOCK) {
#if HDMI2p0
		//if ((newbase_hdmi2p0_get_clock40x_flag(port) || newbase_hdmi2p0_get_scramble_flag(port)) &&
		if ((newbase_hdmi2p0_get_clock40x_flag(port)) &&
			(clk_tmp < 1422 && clk_tmp > 699)) {	//It's possible for 40x only when clock=(3G~6G)/4 //WOSQRTK-9795
			clk_tmp <<= 2; 				 //HDMI2.0, change clock to clock*4
			phy_st[port].rxphy_40x = 1;
		}
#endif

#if MHL_SUPPORT && MHL3_ENABLE
		if (newbase_hdmi_get_is_mhl(port) && newbase_hdmi_get_is_mhl3(port)) {
			clk_tmp <<= (mhl3_get_link_rate()+1);
		}
#endif

		if (HDMI_ABS(clk_tmp, phy_st[port].clk_pre) < CLOCK_TOLERANCE(port)) {
			// ------------------------------------------
			// Get valid clock and close to previous clock
			// ------------------------------------------
			if (newbase_rxphy_is_clock_stable(port, clk_tmp)) {
				phy_st[port].clk_stable = 1;
				phy_st[port].clk = clk_tmp;
			}
			phy_st[port].clk_unstable_count = 0;
		}
		else if (phy_st[port].clk_unstable_count < CLK_UNSTABLE_CNT) {
			// ------------------------------------------
			// Get valid clock but different with previous clock, count for debouncing
			// ------------------------------------------
			phy_st[port].clk_unstable_count++;
			//HDMI_PRINTF("unstable clk=%d, pre=%d, cur=%d, cnt=%d\n", clk_tmp, phy_st[port].clk_pre, phy_st[port].clk, phy_st[port].clk_unstable_count);
		} else {
			// ------------------------------------------
			// Get valid clock but different with previous clock
			// ------------------------------------------
			phy_st[port].clk = 0;
			phy_st[port].clk_pre = clk_tmp;
			phy_st[port].clk_tolerance = MAX(clk_tmp>>7, 5);
			phy_st[port].clk_debounce_count = 0;
			phy_st[port].clk_unstable_count = 0;
			phy_st[port].clk_stable = 0;
			phy_st[port].phy_proc_state = PHY_PROC_INIT;
		}

		phy_st[port].noclk_debounce_count = 0;

	} else {

		if (phy_st[port].noclk_debounce_count < NOCLK_DEBOUNCE_CNT) {
			// ------------------------------------------
			// NO clock, and start debouncing
			// ------------------------------------------

			phy_st[port].noclk_debounce_count++;

		} else {
			// ------------------------------------------
			// NO clock, really!!  Then reset clk_info
			// ------------------------------------------

			if (phy_st[port].clk_pre) {
				phy_st[port].clk_pre = 0;
				phy_st[port].clk= 0;
				phy_st[port].clk_debounce_count= 0;
				phy_st[port].clk_unstable_count = 0;
				phy_st[port].clk_stable = 0;
				phy_st[port].phy_proc_state = PHY_PROC_INIT;
			}
#if HDMI2p0
			newbase_hdmi2p0_reset_scdc_toggle(port);
			if (phy_st[port].rxphy_40x) {
				// ------------------------------------------
				// NO clock, and reset clk_info and then reset SCDC
				// ------------------------------------------
				lib_hdmi2p0_reset_scdc(port);
				phy_st[port].rxphy_40x = 0;
			}
#endif
		}
	}


	lib_hdmi_trigger_measure_stop(port);
	

	if (clk_stable_prev != phy_st[port].clk_stable) {

#ifndef HDMI_COLOR_PRINT_EN
		HDMI_EMG("clk_stable[p%d] from %d to %d\n", port, clk_stable_prev, phy_st[port].clk_stable);
#else
		HDMI_EMG("%s" "clk_stable[p%d] from %d to %d\n" "%s",KCYN, port, clk_stable_prev, phy_st[port].clk_stable,KNRM);
#endif

#if HDMI_PHY_CLOCK_DYNAMIC_CNT_ENABLE
		if(NO_HDCP != newbase_hdcp_get_auth_mode(port))
			HDMI_EMG("[HDCP] (%x) start (%x)\n", newbase_hdcp_get_auth_mode(port), phy_st[port].clk_debounce_count);
#endif //#if HDMI_PHY_CLOCK_DYNAMIC_CNT_ENABLE

		lib_hdmi_misc_variable_initial(port);
	}

	if (phy_st[port].clk_stable) {
		return TRUE;
	} else {
		return FALSE;
	}

}

unsigned char newbase_rxphy_is_clock_stable(unsigned char port, unsigned int clk_tmp)
{
// return 1: means clock is stable

#if HDMI_PHY_CLOCK_DYNAMIC_CNT_ENABLE
	if (phy_st[port].clk_debounce_count >= CLK_DEBOUNCE_SHORT_CNT) {
		if(NO_HDCP == newbase_hdcp_get_auth_mode(port)) {
			//original case
			if (phy_st[port].clk_debounce_count >= CLK_DEBOUNCE_CNT) {
				return 1;
			} else {
				phy_st[port].clk_debounce_count++;
			}
		} else {
			//HDCP handshake too early, we reduce stable clock debounce
			return 1;
		}
	} else {
		phy_st[port].clk_debounce_count++;
	}
#else //#if HDMI_PHY_CLOCK_DYNAMIC_CNT_ENABLE
	if (phy_st[port].clk_debounce_count >= CLK_DEBOUNCE_CNT) {
		return 1;
	} else {
		phy_st[port].clk_debounce_count++;
	}
#endif //#if HDMI_PHY_CLOCK_DYNAMIC_CNT_ENABLE

	return 0;
}

void newbase_rxphy_job(unsigned char p)
{
	switch (phy_st[p].phy_proc_state) {
	case PHY_PROC_INIT:

#if MHL_SUPPORT && MHL3_ENABLE
		if (newbase_hdmi_get_is_mhl(p) && newbase_hdmi_get_is_mhl3(p)) {
			if (!mhl3_is_get_link_rate())
				return;
		}
#endif

		newbase_hdmi_set_phy(p, phy_st[p].clk);

		newbase_hdmi_reset_meas_counter(p);
//		newbase_hdmi2p0_inc_scdc_toggle(p);

		if (phy_st[p].clk <= clock_bound_45m) {
			phy_st[p].phy_proc_state= PHY_PROC_CLOSE_ADP;
		} else {
			phy_st[p].phy_proc_state= PHY_PROC_RECORD;
		}
		break;
	case PHY_PROC_RECORD:
		if (newbase_hdmi_dfe_record(p, phy_st[p].clk)) {
			phy_st[p].phy_proc_state = PHY_PROC_CLOSE_ADP;
			// go to PHY_PROC_CLOSE_ADP without taking a break;
		} else {
			break;
		}
	case PHY_PROC_CLOSE_ADP:
		if (newbase_hdmi_dfe_close(p, phy_st[p].clk, PHY_PROC_CLOSE_ADP)) {
#if HDMI2p0
			newbase_hdmi2p0_detect_config(p);
#endif
			phy_st[p].phy_proc_state = PHY_PROC_DONE;

#if BIST_DFE_SCAN
			if ((hdmi_in(DBG_FW_ADDR) & DBG_30_DFE_SCAN_TEST) && (phy_st[p].clk > clock_bound_45m)) {
				debug_hdmi_dfe_scan(p);
			}
#endif
		}
		break;
	case PHY_PROC_DONE:

		break;




	/**********************************************************************/
	//
	//	Belowing are for recovery flow in check_mode stage.
	//
	/**********************************************************************/
	case PHY_PROC_RECOVER_6G_LONGCABLE:
		newbase_hdmi_dfe_hi_speed(p, phy_st[p].clk);
		phy_st[p].phy_proc_state = PHY_PROC_RECOVER_6G_LONGCABLE_RECORD;
		break;
	case PHY_PROC_RECOVER_6G_LONGCABLE_RECORD:
		if (newbase_hdmi_dfe_record(p, phy_st[p].clk)) {
			phy_st[p].phy_proc_state = PHY_PROC_RECOVER_6G_LONGCABLE_CLOSE_ADP;
			// go to PHY_PROC_RECOVER_HI_CLOSE_ADP;
		} else {
			break;
		}
	case PHY_PROC_RECOVER_6G_LONGCABLE_CLOSE_ADP:
		newbase_hdmi_dfe_close(p, phy_st[p].clk, PHY_PROC_RECOVER_6G_LONGCABLE_CLOSE_ADP);
		phy_st[p].phy_proc_state = PHY_PROC_DONE;
		break;


	case PHY_PROC_RECOVER_MI:
		newbase_hdmi_dfe_mi_speed(p, phy_st[p].clk);
		phy_st[p].phy_proc_state = PHY_PROC_RECORD;
		break;

	case PHY_PROC_RECOVER_MID_BAND_LONGCABLE:
		newbasse_hdmi_dfe_mid_adapthve(p, phy_st[p].clk);
		phy_st[p].phy_proc_state = PHY_PROC_DONE;
		break;


	default:
		phy_st[p].phy_proc_state = PHY_PROC_INIT;
		break;
	}

}

void newbase_rxphy_force_clear_clk_st(unsigned char port)
{
	// case 1: clk=1080p50->1080p60, timing changed, but clock is the same, then force to re-set phy
	// case 2: clk=4k2kp60->1080p60, timing changed, but clock is the same, then force to re-set phy (also need to clear SCDC)
	//
#if BIST_DFE_SCAN
	if (hdmi_in(DBG_FW_ADDR) & DBG_30_DFE_SCAN_TEST) return;
#endif
	newbase_rxphy_init_struct(port);
}

unsigned int newbase_rxphy_get_clk(unsigned char port)
{
	return phy_st[port].clk;
}

unsigned char newbase_rxphy_is_clk_stable(unsigned char port)
{
	return phy_st[port].clk_stable;
}

unsigned char newbase_rxphy_get_setphy_done(unsigned char port)
{
	return (phy_st[port].phy_proc_state == PHY_PROC_DONE);
}

void newbase_rxphy_reset_setphy_proc(unsigned char port)
{
	phy_st[port].phy_proc_state = PHY_PROC_INIT;
	HDMI_PRINTF("%s(%d)\n", __func__, port);
}

void newbase_hdmi_dfe_recovery_6g_long_cable(unsigned char port)
{
	phy_st[port].phy_proc_state = PHY_PROC_RECOVER_6G_LONGCABLE;
}

void newbase_hdmi_dfe_recovery_mi_speed(unsigned char port)
{
	phy_st[port].phy_proc_state = PHY_PROC_RECOVER_MI;
}


void newbase_hdmi_dfe_recovery_midband_long_cable(unsigned char port)
{
	HDMI_PRINTF("%s(%d)\n", __func__, port);
	phy_st[port].phy_proc_state = PHY_PROC_RECOVER_MID_BAND_LONGCABLE;

}


void newbase_hdmi_set_phy(unsigned char port, unsigned int b)
{
	unsigned char mode, hdcp_hail_hydra;
	bool b_mode_found = 0;
	HDMI_PHY_PARAM_T *p_phy_table;
	unsigned char tb_size = 0;

#ifndef HDMI_COLOR_PRINT_EN
	HDMI_EMG("%s start[p%d]=%d\n", __func__, port, b);
#else
	HDMI_EMG("%s" "%s start[p%d]=%d\n" "%s",KYEL, __func__, port, b,KNRM);
#endif

	if (b == 0) return;

	hdcp_hail_hydra = lib_hdmi_hdcp14_is_onoff(port);
	lib_hdmi_hdcp14_enable(port, 0);
	lib_hdmi_mac_reset(port);

	lib_hdmi_cdr_rst(port, 1);
	lib_hdmi_demux_ck_vcopll_rst(port, 1);
	lib_hdmi_wdg_rst(port, 1);
	lib_hdmi_cmu_pll_en(port, 0);

	lib_hdmi_eq_bias_band_setting(port, b);
	lib_hdmi_cco_band_config(port, b);

#if MHL_SUPPORT
	if (lib_mhl_port_is_turn_on(port)) {
	#if MHL3_ENABLE
		if (lib_mhl_port_is_mhl3(port)) {
			p_phy_table = mhl3_phy_param;
			tb_size = sizeof(mhl3_phy_param)/sizeof(HDMI_PHY_PARAM_T);
	} else
	#endif
		if (lib_mhl_port_is_ppmode(port)) {
			p_phy_table = mhl_phy_pp_param;
			tb_size = sizeof(mhl_phy_pp_param)/sizeof(HDMI_PHY_PARAM_T);
		} else {
			p_phy_table = mhl_phy_param;
			tb_size = sizeof(mhl_phy_param)/sizeof(HDMI_PHY_PARAM_T);
		}
	} else
#endif
	{
		p_phy_table = hdmi_phy_param;
		tb_size = sizeof(hdmi_phy_param)/sizeof(HDMI_PHY_PARAM_T);
	}

	HDMI_PRINTF("phy table size=%d\n", tb_size);
	for (mode=0; mode<tb_size; mode++) {
		if (p_phy_table[mode].b_upper > b && p_phy_table[mode].b_lower <= b) {
			lib_hdmi_set_phy_table(port, &p_phy_table[mode]);
	                        b_mode_found = 1;
	                        break;
		}
	}

	if (!b_mode_found) {
	        HDMI_EMG("Not Found in PhyMode (b=%d)\n", b);
	#if HDCP2_2
		if (hdcp_hail_hydra) {
			lib_hdmi_hdcp14_enable(port, 1);
		}
	#else
		lib_hdmi_hdcp14_enable(port, 1);
	#endif

	        return;
	}

	lib_hdmi_wdg_rst(port, 0);

	lib_hdmi_wdog(port);
	udelay(5);

	lib_hdmi_cmu_pll_en(port, 1);
	udelay(1);

	lib_hdmi_demux_ck_vcopll_rst(port, 0);
	udelay(1);

	lib_hdmi_cdr_rst(port, 0);
	udelay(1);

	lib_hdmi_dfe_config_setting(port);

#if MHL_SUPPORT && MHL3_ENABLE
	lib_hdmi_acdr_config_setting(port, (lib_mhl_port_is_turn_on(port) && lib_mhl_port_is_mhl3(port)), b);
#endif

	//need to check: DFE_Single_End_reset();
	lib_hdmi_fg_koffset_disable(port);

	if (b > clock_bound_110m) {
		lib_hdmi_set_dfe(port, b, 3);
	} else if ((b > clock_bound_45m) && (b < clock_bound_110m)) {
		lib_hdmi_set_dfe_mid_band(port, b, 2);
	} else {
		lib_hdmi_dfe_manual_set(port);
	}

#if HDCP2_2
	if (hdcp_hail_hydra) {
		lib_hdmi_hdcp14_enable(port, 1);
	}
#else
	lib_hdmi_hdcp14_enable(port, 1);
#endif

	udelay(1);
	lib_hdmi_mac_release(port);

}

unsigned char newbase_hdmi_dfe_record(unsigned char nport, unsigned int clk)
{
	if (lib_hdmi_dfe_is_record_enable(nport)) {
		lib_hdmi_dfe_record_enable(nport, 0);
		return TRUE; // stop recocrding
	} else {
		lib_hdmi_dfe_record_enable(nport, 1);
		return FALSE; // start recoding min/max
	}
}

unsigned char newbase_hdmi_dfe_close(unsigned char nport, unsigned int clk, unsigned char phy_state)
{
	unsigned char lane;

	lib_hdmi_set_dfe_close(nport);

#if MHL_SUPPORT
	if (!newbase_hdmi_get_is_mhl(nport))
#endif
	{
		switch (phy_state) {
		case PHY_PROC_CLOSE_ADP:
			if (clk > 2900) { // > 3G
				lib_hdmi_load_le_max(nport);
			} else {
				lib_hdmi_dfe_examine_le_coef(nport, clk);
			}
			break;
		case PHY_PROC_RECOVER_6G_LONGCABLE_CLOSE_ADP:
			newbase_hdmi_dfe_6g_long_cable_patch(nport);
			break;
		default:
			break;
		}

	}

	for (lane=0; lane<3; lane++) {
		phy_st[nport].dfe_t[lane].tap0max = lib_hdmi_dfe_get_tap0max(nport, lane);
		phy_st[nport].dfe_t[lane].tap0min = lib_hdmi_dfe_get_tap0min(nport, lane);
		phy_st[nport].dfe_t[lane].vth = lib_hdmi_dfe_get_vth(nport, lane);
		phy_st[nport].dfe_t[lane].tap0 = lib_hdmi_dfe_get_tap0(nport, lane);
		phy_st[nport].dfe_t[lane].tap1 = lib_hdmi_dfe_get_tap1(nport, lane);
		phy_st[nport].dfe_t[lane].tap2 = lib_hdmi_dfe_get_tap2(nport, lane);
		phy_st[nport].dfe_t[lane].le = lib_hdmi_dfe_get_le(nport, lane);
		phy_st[nport].dfe_t[lane].lemax = lib_hdmi_dfe_get_lemax(nport, lane);
		phy_st[nport].dfe_t[lane].lemin = lib_hdmi_dfe_get_lemin(nport, lane);
	}

	newbase_hdmi_dump_dfe_para(nport);

	//lib_hdmi_dfe_power(nport, 0);

	return TRUE;
}

void newbase_hdmi_dfe_hi_speed(unsigned char nport, unsigned int b_clk)
{
	HDMI_PRINTF("%s\n", __func__);

	lib_hdmi_dfe_power(nport, 1);

	// ENABLE  VTH & TAP0
	lib_hdmi_dfe_init_vth(nport, (LN_R|LN_G|LN_B), 0x03);
	lib_hdmi_dfe_init_tap0(nport, (LN_R|LN_G|LN_B), 0x14);

	lib_hdmi_dfe_adaptation(nport, (LN_R|LN_G|LN_B),
		(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth), 1);
	//hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth),(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth));
	//hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth),(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth));
	//hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth),(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth));

	lib_hdmi_dfe_second_flow(nport, b_clk);

	lib_hdmi_dfe_init_tap1(nport, (LN_R|LN_G|LN_B), 0x0c);
	lib_hdmi_dfe_init_tap2(nport, (LN_R|LN_G|LN_B), 0x00);
	lib_hdmi_dfe_init_le(nport, (LN_R|LN_G|LN_B), 0x08);

	if (b_clk > 2700) {  // 3G need tap2 but below not need
		lib_hdmi_dfe_adaptation(nport, (LN_R|LN_G|LN_B),
			(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE|REG_dfe_adapt_en_lane0_TAP2), 1);
		//hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE|REG_dfe_adapt_en_lane0_TAP2),(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE|REG_dfe_adapt_en_lane0_TAP2));
		//hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE|REG_dfe_adapt_en_lane1_TAP2),(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE|REG_dfe_adapt_en_lane1_TAP2));
		//hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE|REG_dfe_adapt_en_lane2_TAP2),(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE|REG_dfe_adapt_en_lane2_TAP2));
	} else {
		lib_hdmi_dfe_adaptation(nport, (LN_R|LN_G|LN_B),
			(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE), 1);
		//hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE|REG_dfe_adapt_en_lane0_TAP2),(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE));
		//hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE|REG_dfe_adapt_en_lane1_TAP2),(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE));
		//hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE|REG_dfe_adapt_en_lane2_TAP2),(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE));
	}

}

void newbase_hdmi_dfe_6g_long_cable_patch(unsigned char nport)
{
	signed char tap2;
	unsigned char lemax;

	tap2 = lib_hdmi_dfe_get_tap2(nport, 1);
	lib_hdmi_dfe_init_tap2(nport, LN_G, MIN(tap2+6, 10));

	lemax = lib_hdmi_dfe_get_lemax(nport, 1);
	lemax += lib_hdmi_dfe_get_tap1max(nport, 1);
	lib_hdmi_dfe_init_tap1(nport, LN_G, MIN(lemax+4, 63));

	HDMI_EMG("%s end\n", __func__);
}

void newbase_hdmi_dfe_mi_speed(unsigned char nport, unsigned int b_clk)
{
	HDMI_PRINTF("%s\n", __func__);

	lib_hdmi_dfe_power(nport, 1);

	lib_hdmi_dfe_adaptation(nport, (LN_R|LN_G|LN_B),
		(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE|REG_dfe_adapt_en_lane0_TAP2), 1);
	//hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE|REG_dfe_adapt_en_lane0_TAP2),(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE|REG_dfe_adapt_en_lane0_TAP2));
	//hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE|REG_dfe_adapt_en_lane1_TAP2),(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE|REG_dfe_adapt_en_lane1_TAP2));
	//hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE|REG_dfe_adapt_en_lane2_TAP2),(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE|REG_dfe_adapt_en_lane2_TAP2));
}


void newbasse_hdmi_dfe_mid_adapthve(unsigned char nport, unsigned int b_clk)
{
	unsigned char le0;

//	HDMI_PRINTF("%s\n", __func__);
	le0 = lib_hdmi_dfe_get_le(nport,0);

	if (le0 >= 8)
		return;
//	le1 = lib_hdmi_dfe_get_le(nport,1);
//	le2 = lib_hdmi_dfe_get_le(nport,2);

	lib_hdmi_dfe_init_le(nport, (LN_R|LN_G|LN_B), (le0 + 2));

	HDMI_PRINTF("DFE LE=%x\n", (le0 + 2));

}



#ifdef TMDS_ERR_DET_SHORT_PERIOD

void newbase_hdmi_open_err_detect(unsigned char port)
{
	phy_st[port].error_detect_count = 0;

}


unsigned char newbase_hdmi_err_detect_stop(unsigned char port)
{
	if (phy_st[port].error_detect_count > MAX_ERR_DETECT_TIMES)
		return 1;
	else
	{
		++phy_st[port].error_detect_count;
		return 0;
	}

}

#endif

unsigned char newbase_hdmi_char_err_detection(unsigned char port)
{
	unsigned int r_err = 0, g_err = 0, b_err = 0;

#if TMDS_ERR_DET_SHORT_PERIOD
	if (newbase_hdmi_err_detect_stop(port))
		return 0;
#endif

	if (phy_st[port].char_err_loop == 0) {
		lib_hdmi_char_err_start(port, 0, TMDS_CHAR_ERR_PERIOD);
		phy_st[port].char_err_loop++;

	} else {
		if (lib_hdmi_char_err_get_error(port, &r_err, &g_err, &b_err)) {
			phy_st[port].char_err_loop = 0;
			phy_st[port].detect_6g_longcable = 0;

			if ((g_err > TMDS_CHAR_ERR_THREAD) && (r_err < 10) && (b_err < 10) && ((phy_st[port].dfe_t[1].le+phy_st[port].dfe_t[1].tap1)>10)) {
				phy_st[port].detect_6g_longcable = 1;
			}

			if ((r_err > TMDS_CHAR_ERR_THREAD) || (g_err > TMDS_CHAR_ERR_THREAD) || (b_err > TMDS_CHAR_ERR_THREAD)) {
				// Do something to save the world
				HDMI_EMG("[CHAR_ERR](%d, %d, %d)\n", r_err, g_err, b_err);
			}
			return 1;
		}

		if (phy_st[port].char_err_loop > TMDS_CHAR_ERR_MAX_LOOP) {
			phy_st[port].char_err_loop = 0;
			phy_st[port].detect_6g_longcable = 0;

			HDMI_EMG("[CHAR_ERR] Life is too short.\n");
		} else {
			phy_st[port].char_err_loop++;
		}

	}
#if 0
	if (phy_st[port].char_err_loop == 0) {
		lib_hdmi_char_err_start(port, 0, TMDS_CHAR_ERR_MAX_LOOP);
		phy_st[port].char_err_loop++;

	} else if (phy_st[port].char_err_loop > TMDS_CHAR_ERR_MAX_LOOP) {
		phy_st[port].char_err_loop = 0;
		phy_st[port].detect_6g_longcable = 0;

		if (lib_hdmi_char_err_get_error(port, &r_err, &g_err, &b_err)) {

			if ((g_err > TMDS_CHAR_ERR_THREAD) && (r_err < 10) && (b_err < 10) && ((phy_st[port].dfe_t[1].le+phy_st[port].dfe_t[1].tap1)>10)) {
				phy_st[port].detect_6g_longcable = 1;
			}

			if ((r_err > TMDS_CHAR_ERR_THREAD) || (g_err > TMDS_CHAR_ERR_THREAD) || (b_err > TMDS_CHAR_ERR_THREAD)) {
				// Do something to save the world
				HDMI_PRINTF("[CHAR_ERR](%d, %d, %d)\n", r_err, g_err, b_err);
			}
			return 1;
		}

	} else {
		phy_st[port].char_err_loop++;
	}
#endif
	return 0;

}

unsigned char newbase_hdmi_bit_err_detection(unsigned char port)
{
	unsigned int r_err = 0, g_err = 0, b_err = 0;

#if TMDS_ERR_DET_SHORT_PERIOD
	if (newbase_hdmi_err_detect_stop(port))
		return 0;
#endif

	if (phy_st[port].bit_err_loop == 0) {
		lib_hdmi_bit_err_start(port, 0, TMDS_BIT_ERR_PERIOD);
		phy_st[port].bit_err_loop++;

	} else {
		if (lib_hdmi_bit_err_get_error(port, &r_err, &g_err, &b_err)) {
			phy_st[port].bit_err_loop = 0;

			if ((r_err > TMDS_BIT_ERR_THREAD) || (g_err > TMDS_BIT_ERR_THREAD) || (b_err > TMDS_BIT_ERR_THREAD)) {
				// Do something to save the world
				HDMI_EMG("[BIT_ERR](%d, %d, %d)\n", r_err, g_err, b_err);
				return 1;
			}

			//HDMI_EMG("[BIT_ERR](%d, %d, %d)\n", r_err, g_err, b_err);
			return 0;

		}

		if (phy_st[port].bit_err_loop > TMDS_BIT_ERR_MAX_LOOP) {
			phy_st[port].bit_err_loop = 0;

			HDMI_EMG("[BIT_ERR] Life is too short.\n");
		} else {
			phy_st[port].bit_err_loop++;
		}

	}
#if 0
	if (phy_st[port].bit_err_loop == 0) {
		lib_hdmi_bit_err_start(port, 0, TMDS_BIT_ERR_MAX_LOOP);
		phy_st[port].bit_err_loop++;

	} else if (phy_st[port].bit_err_loop > TMDS_BIT_ERR_MAX_LOOP) {
		phy_st[port].bit_err_loop = 0;

		if (lib_hdmi_bit_err_get_error(port, &r_err, &g_err, &b_err)) {

			if ((r_err > TMDS_BIT_ERR_THREAD) || (g_err > TMDS_BIT_ERR_THREAD) || (b_err > TMDS_BIT_ERR_THREAD)) {
				// Do something to save the world
				HDMI_PRINTF("[BIT_ERR](%d, %d, %d)\n", r_err, g_err, b_err);
			}
			return 1;
		}

	} else {
		phy_st[port].bit_err_loop++;
	}
#endif
	return 0;

}

unsigned char newbase_hdmi_is_long_cable(unsigned char port)
{
	return phy_st[port].detect_6g_longcable;
}

void newbase_hdmi_dump_dfe_para(unsigned char nport)
{
	unsigned char lane;
	for (lane=0; lane<3; lane++) {
		HDMI_EMG("********************Lane%d******************\n", lane);
		HDMI_EMG("[DFE] Lane%d Vth=0x%x\n", lane, phy_st[nport].dfe_t[lane].vth);
		HDMI_EMG("[DFE] Lane%d Tap0=0x%x, max=0x%02x, min=0x%02x\n",
			lane, phy_st[nport].dfe_t[lane].tap0, phy_st[nport].dfe_t[lane].tap0max, phy_st[nport].dfe_t[lane].tap0min);

		HDMI_EMG("[DFE] Lane%d Tap1=0x%02x, Tap2=%+d\n",
			lane, phy_st[nport].dfe_t[lane].tap1, phy_st[nport].dfe_t[lane].tap2);

		HDMI_EMG("[DFE] Lane%d LE=0x%02x, max=0x%02x, min=0x%02x\n",
			lane, phy_st[nport].dfe_t[lane].le, phy_st[nport].dfe_t[lane].lemax, phy_st[nport].dfe_t[lane].lemin);
	}
}

void lib_hdmi_trigger_measurement(unsigned char port)
{

	hdmiport_mask(reg_mod[port], ~DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask, 0);
	hdmiport_mask(reg_mod[port], ~DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask, DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask);
	hdmi_out(reg_mod[port]+(1<<2), DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_md_ok_mask);

}

void lib_hdmi_trigger_measure_start(unsigned char port)
{
	hdmiport_mask(reg_mod[port], ~DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask, 0);

	//hdmi_out(DFE_HDMI_RX_PHY_REGD57_reg+(port<<3), DFE_HDMI_RX_PHY_REGD57_p0_ck_md_ok_mask);
}

void lib_hdmi_trigger_measure_stop(unsigned char port)
{

	hdmiport_mask(reg_mod[port],
		~DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask,
		DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask);
}

unsigned char lib_hdmi_is_clk_ready(unsigned char port)
{
#if MHL_SUPPORT && MHL3_ENABLE
	if (hdmi_in(DBG_FW_ADDR)&DBG_01_MHL3_ON) {
		return TRUE;
	}
#endif

#if CK_MD_AUTO
	unsigned char i;
	hdmi_out(reg_mod[port]+(1<<2), DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_md_ok_mask);
	for (i=0; i<10; i++) {
		if (DFE_HDMI_RX_PHY_P0_REGD08_get_p0_ck_md_ok(hdmi_in(reg_mod[port]+(1<<2)))) {
			return TRUE;
		}
		udelay(10);
	}

	return FALSE;

#else
	hdmi_out(reg_mod[port]+(1<<2), DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_md_ok_mask);
	udelay(20);
	if (DFE_HDMI_RX_PHY_P0_REGD08_get_p0_ck_md_ok(hdmi_in(reg_mod[port]+(1<<2)))) {
		return TRUE;
	} else {
		return FALSE;
	}
#endif

}

#if CK_MD_AUTO
void lib_hdmi_ck_md_reset(unsigned char port)
{
	hdmiport_mask(reg_mod[port], ~DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask, 0);
	udelay(10);
	hdmiport_mask(reg_mod[port], ~DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask, DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask);

}

void lib_hdmi_ck_md_set(unsigned char port)
{
	hdmi_out(reg_mod[port]+(1<<2), DFE_HDMI_RX_PHY_P0_REGD08_p0_ck_md_ok_mask);
}

void lib_hdmi_ck_md_auto(unsigned char port, unsigned char auto_mode)
{
	hdmiport_mask(reg_mod[port], ~DFE_HDMI_RX_PHY_P0_REGD07_p0_ck_md_rstb_mask, 0);
	hdmiport_mask(reg_mod[port],
		~DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_auto_mask,
		DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_auto(auto_mode));
}
#endif

unsigned int lib_hdmi_get_clock(unsigned char port)
{
#if MHL_SUPPORT && MHL3_ENABLE
	if (hdmi_in(DBG_FW_ADDR)&DBG_01_MHL3_ON) {
		return 710;
	}
#endif

	return DFE_HDMI_RX_PHY_P0_REGD08_get_p0_ck_md_count(hdmi_in(reg_mod[port]+(1<<2)));

}

void lib_hdmi_phy_init(void)
{
	unsigned char nport;

	//enable bandgap power
	hdmiport_mask(DFE_HDMI_RX_PHY_BG_reg,~DFE_HDMI_RX_PHY_BG_reg_bg_pow_mask,DFE_HDMI_RX_PHY_BG_reg_bg_pow_mask);

	hdmiport_mask(DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg, ~(TOP_IN_REG_IBHN_TUNE), _BIT20);
	hdmiport_mask(DFE_HDMI_RX_PHY_P2_TOP_IN_reg, ~(TOP_IN_REG_IBHN_TUNE), _BIT20);

	for (nport=0; nport<HDMI_PHY_TOTAL_NUM; nport++) {
		if (nport < 2)
			hdmiport_mask(DFE_HDMI_RX_PHY_P0P1_TOP_IN_reg, ~(TOP_IN_CK_TX_0<<nport), (TOP_IN_CK_TX_0<<nport));
		else
			hdmiport_mask(DFE_HDMI_RX_PHY_P2_TOP_IN_reg, ~(TOP_IN_CK_TX_0<<nport), (TOP_IN_CK_TX_0<<nport));
		//default hdmi mode (other :MHL3.0 mode )
		lib_hdmi_ck_md_ref_sel(nport, 0);//HDMI mode
		lib_hdmi_fg_koffset_manual_adjust(nport, 0x10, 0x10, 0x10);
	}

	lib_hdmi_z0_calibration();

	for (nport=0; nport<HDMI_PHY_TOTAL_NUM; nport++) {
		lib_hdmi_mhl_z300_sel(nport, 0, 0);
		MHL_Z100k_Switch(nport, 0);
// no acdr
//		hdmiport_mask(reg_acdr2[i],
//			~(_BIT10|_BIT9|_BIT8),
//			(_BIT9));


		// close hysteresis
		hdmiport_mask(RX_PHY_CK1_reg,
			~(DFE_HDMI_RX_PHY_P0_CK1_reg_p0_ck_1_mask|p0_ck_2_CMU_CKIN_SEL|p0_ck2_2_ACDR_CBUS_REF|p0_ck2_2_MD_HYSTERESIS_SEL|p0_CK_2_CKD2S_EN0),
			(p0_ck_2_CMU_CKIN_SEL|p0_ck2_2_ACDR_CBUS_REF|p0_CK_2_CKD2S_EN0|p0_ck_1_port_bias|p0_ck_1_CKAFE_POW));
		hdmiport_mask(RX_PHY_CK2_reg,
			~(P0_ck_8_LDO_EN_mask),
			(P0_ck_8_LDO_EN_mask));	// QC: when ac on, need this for hdcp auth, otherwise no clock in MSHG-800


		//hdmiport_mask(DFE_HDMI_RX_PHY_LDO_reg, ~(DFE_HDMI_RX_PHY_LDO_reg_p0_ldo_pow_mask), (0));

		hdmiport_mask(RX_PHY_B2_reg, ~P0_b_DEMUX_BBPD_RSTB, P0_b_DEMUX_BBPD_RSTB);
		hdmiport_mask(RX_PHY_G2_reg, ~P0_b_DEMUX_BBPD_RSTB, P0_b_DEMUX_BBPD_RSTB);
		hdmiport_mask(RX_PHY_R2_reg, ~P0_b_DEMUX_BBPD_RSTB, P0_b_DEMUX_BBPD_RSTB);

#if CK_MD_AUTO
		lib_hdmi_ck_md_auto(nport, 1);
		lib_hdmi_ck_md_reset(nport);
#endif

	}

}

void lib_hdmi_z0_set(unsigned char port, unsigned char lane, unsigned char enable)
{

unsigned int bmask = 0;

const unsigned int reg_z0pow[HDMI_PHY_TOTAL_NUM] = {
	DFE_HDMI_RX_PHY_P0P1_Z0POW_reg,
	DFE_HDMI_RX_PHY_P0P1_Z0POW_reg,
	DFE_HDMI_RX_PHY_P2_Z0POW_reg
};

	if (port < 2) {
		if (lane&LN_CK) {
			bmask |= DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_ck(1<<port);

		}
		if (lane&LN_B) {
			bmask |= DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_b(1<<port)|DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_pow(1<<port);
		}
		if (lane&LN_G) {
			bmask |= DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_g(1<<port)|DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_pow(1<<port);
		}
		if (lane&LN_R) {
			bmask |= DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z0pow_r(1<<port)|DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_pow(1<<port);
		}
		if (!bmask) {
			return;
		}
	} else {

		if (lane&LN_CK) {
			bmask |= DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z0pow_ck(1<<port);
		}
		if (lane&LN_B) {
			bmask |= DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z0pow_b(1<<port)|DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z300_pow(1<<port);
		}
		if (lane&LN_G) {
			bmask |= DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z0pow_g(1<<port)|DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z300_pow(1<<port);
		}
		if (lane&LN_R) {
			bmask |= DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z0pow_r(1<<port)|DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z300_pow(1<<port);
		}
		if (!bmask) {
			return;
		}
	}

	hdmi_mask(reg_z0pow[port], ~bmask, enable?bmask:0);

}

void lib_hdmi_mhl_z300_sel(unsigned char port, unsigned char is_mhl, unsigned char is_mhl3)
{

	if (port < 2) {

		if (is_mhl && !is_mhl3) {
			hdmiport_mask(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_sel((1<<port))), 0);
		} else {
			hdmiport_mask(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_sel((1<<port))), DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_sel((1<<port)));
		}
		hdmiport_mask(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_pow_mask), (DFE_HDMI_RX_PHY_P0P1_Z0POW_reg_z0_z300_pow_mask));

	} else {

		if (is_mhl && !is_mhl3) {
			hdmiport_mask(DFE_HDMI_RX_PHY_P2_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z300_sel((1<<port))), 0);
		} else {
			hdmiport_mask(DFE_HDMI_RX_PHY_P2_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z300_sel((1<<port))), DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z300_sel((1<<port)));
		}
		hdmiport_mask(DFE_HDMI_RX_PHY_P2_Z0POW_reg, ~(DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z300_pow_mask), (DFE_HDMI_RX_PHY_P2_Z0POW_reg_z0_z300_pow_mask));

	}

}

void lib_hdmi_ck_md_ref_sel(unsigned char nport, unsigned char is_mhl3)
{
	if (nport >= HDMI_PHY_TOTAL_NUM) {
		return;
	}

	hdmiport_mask(RX_PHY_CK1_reg, ~p0_ck_2_CK_MD_REF_SEL, (is_mhl3)?0:p0_ck_2_CK_MD_REF_SEL);
}





void lib_hdmi_wdg_rst(unsigned char nport, unsigned char rst)
{
	if (nport >= HDMI_PHY_TOTAL_NUM) {
		return;
	}

	if (rst) {
		hdmiport_mask(RX_PHY_CK3_reg, ~(P0_ck_9_CMU_PFD_RSTB|_BIT3|P0_ck_9_CMU_WDRST|_BIT1), (_BIT3|P0_ck_9_CMU_WDRST));	//PFD_RSTB  reset
	} else {
		hdmiport_mask(RX_PHY_CK3_reg, ~(P0_ck_9_CMU_PFD_RSTB|_BIT3|P0_ck_9_CMU_WDRST|_BIT1), (P0_ck_9_CMU_PFD_RSTB|_BIT1));  //release, normal
	}
}


void lib_hdmi_afifo_enable(unsigned char nport, unsigned char enable)
{
	if (enable) {
		hdmiport_mask(HDMI_CH_CR_reg,~(HDMI_CH_CR_r_ch_afifo_en_mask|HDMI_CH_CR_g_ch_afifo_en_mask|HDMI_CH_CR_b_ch_afifo_en_mask),(HDMI_CH_CR_r_ch_afifo_en_mask|HDMI_CH_CR_g_ch_afifo_en_mask|HDMI_CH_CR_b_ch_afifo_en_mask));
	} else {
		hdmiport_mask(HDMI_CH_CR_reg,~(HDMI_CH_CR_r_ch_afifo_en_mask|HDMI_CH_CR_g_ch_afifo_en_mask|HDMI_CH_CR_b_ch_afifo_en_mask),0);
	}
}

void lib_hdmi_mac_reset(unsigned char nport)
{
	hdmiport_mask(HDMI_TMDS_DPC_SET0_reg, ~(HDMI_TMDS_DPC_SET0_dpc_en_mask), 0);
	lib_hdmi_afifo_enable(nport, 0);
	hdmiport_mask(HDMI_TMDS_PWDCTL_reg, ~(HDMI_TMDS_PWDCTL_ebip_mask|HDMI_TMDS_PWDCTL_egip_mask|HDMI_TMDS_PWDCTL_erip_mask|HDMI_TMDS_PWDCTL_ecc_mask),0);                         //disable TMDS input
	hdmiport_mask(HDMI_TMDS_Z0CC_reg, ~HDMI_TMDS_Z0CC_hde_mask, 0);                            //HDMI&DVI function disable
}

void lib_hdmi_mac_release(unsigned char nport)
{
	hdmiport_mask(HDMI_TMDS_Z0CC_reg,~HDMI_TMDS_Z0CC_hde_mask,HDMI_TMDS_Z0CC_hde(1));

	hdmiport_mask(HDMI_TMDS_PWDCTL_reg,
		~(HDMI_TMDS_PWDCTL_ebip_mask|HDMI_TMDS_PWDCTL_egip_mask|HDMI_TMDS_PWDCTL_erip_mask|HDMI_TMDS_PWDCTL_ecc_mask),
		(HDMI_TMDS_PWDCTL_ebip(1)|HDMI_TMDS_PWDCTL_egip(1)|HDMI_TMDS_PWDCTL_erip(1)|HDMI_TMDS_PWDCTL_ecc(1)));    //enable TMDS input

	lib_hdmi_afifo_enable(nport, 1);
	hdmiport_mask(HDMI_TMDS_DPC_SET0_reg,~(HDMI_TMDS_DPC_SET0_dpc_en_mask),HDMI_TMDS_DPC_SET0_dpc_en_mask);
}

void lib_hdmi_dfe_power(unsigned char nport, unsigned char en)
{
	if (nport >= HDMI_PHY_TOTAL_NUM) {
		return;
	}

	hdmiport_mask(RX_PHY_R3_reg, ~(P0_b_9_DFE_ADAPTION_POW_EN|P0_b_9_DFE_TAP_EN), (DFE_HDMI_RX_PHY_P0_DFE_ADAPTION_EN((en!=0))|DFE_HDMI_RX_PHY_P0_b_tap_en(0x3)));
	hdmiport_mask(RX_PHY_G3_reg, ~(P0_b_9_DFE_ADAPTION_POW_EN|P0_b_9_DFE_TAP_EN), (DFE_HDMI_RX_PHY_P0_DFE_ADAPTION_EN((en!=0))|DFE_HDMI_RX_PHY_P0_b_tap_en(0x3)));
	hdmiport_mask(RX_PHY_B3_reg, ~(P0_b_9_DFE_ADAPTION_POW_EN|P0_b_9_DFE_TAP_EN), (DFE_HDMI_RX_PHY_P0_DFE_ADAPTION_EN((en!=0))|DFE_HDMI_RX_PHY_P0_b_tap_en(0x3)));

}

void lib_hdmi_eq_set_clock_boundary(unsigned char port)
{
#if MHL_SUPPORT
        if (newbase_hdmi_get_is_mhl(port) && !newbase_hdmi_get_is_mhl3(port)) {
                if (newbase_hdmi_get_is_mhl_ppmode(port)) {  // pp mode
                        clock_bound_3g = TMDS_3G/4;
                        clock_bound_1p5g = TMDS_1p5G/4;
                        clock_bound_45m = 107; //=430/4
                        clock_bound_110m = 260;
                } else {
                        clock_bound_3g = TMDS_3G/3;
                        clock_bound_1p5g = TMDS_1p5G/3;
                        clock_bound_45m = 143; //=430/3
                        clock_bound_110m = 347;
                }
        } else
#endif
        {
                clock_bound_3g = TMDS_3G;
                clock_bound_1p5g = TMDS_1p5G;
                clock_bound_45m = 430;
                clock_bound_110m = 1042;
        }

        //HDMI_PRINTF("clock_bound_3g=%d\n", clock_bound_3g);

}

void lib_hdmi_eq_bias_band_setting(unsigned char nport, unsigned int b)
{
	lib_hdmi_eq_set_clock_boundary(nport);

	hdmiport_mask(RX_PHY_B2_reg, ~P0_b_6_TAP0_LE_ISO, P0_b_6_TAP0_LE_ISO);
	hdmiport_mask(RX_PHY_G2_reg, ~P0_b_6_TAP0_LE_ISO, P0_b_6_TAP0_LE_ISO);
	hdmiport_mask(RX_PHY_R2_reg, ~P0_b_6_TAP0_LE_ISO, P0_b_6_TAP0_LE_ISO);


	 if (b > clock_bound_1p5g)        { //3//   3G ~1.5G  MBR
		hdmiport_mask(RX_PHY_B2_reg,~(P0_b_7_LEQ_ISEL|P0_b_6_TAP0_HBR|P0_b_5_DA_LANE_ISEL|P0_b_5_LEQ_CURRENT_ADJ|P0_b_5_TAP0_CURRENT_ADJ),(P0_b_7_LEQ_ISEL_200uA|P0_b_6_TAP0_HBR|P0_b_5_DA_LANE_ISEL_100uA | P0_b_5_LEQ_CURRENT_ADJ_1X|P0_b_5_TAP0_CURRENT_ADJ_1X));		//tap0
		hdmiport_mask(RX_PHY_G2_reg,~(P0_g_7_LEQ_ISEL|P0_g_6_TAP0_HBR|P0_g_5_DA_LANE_ISEL |P0_g_5_LEQ_CURRENT_ADJ|P0_g_5_TAP0_CURRENT_ADJ),(P0_g_7_LEQ_ISEL_200uA|P0_g_6_TAP0_HBR|P0_g_5_DA_LANE_ISEL_100uA |P0_g_5_LEQ_CURRENT_ADJ_1X | P0_g_5_TAP0_CURRENT_ADJ_1X));		//tap0
		hdmiport_mask(RX_PHY_R2_reg,~(P0_r_7_LEQ_ISEL| P0_r_6_TAP0_HBR|P0_r_5_DA_LANE_ISEL |P0_r_5_LEQ_CURRENT_ADJ|P0_r_5_TAP0_CURRENT_ADJ) ,(P0_r_7_LEQ_ISEL_200uA|P0_r_6_TAP0_HBR|P0_r_5_DA_LANE_ISEL_100uA | P0_r_5_LEQ_CURRENT_ADJ_1X | P0_r_5_TAP0_CURRENT_ADJ_1X));		//tap0

		hdmiport_mask(RX_PHY_B3_reg,~(P0_b_11_ACDR_RATE_SEL_HALF_RATE|P0_b_10_DFE_SUMAMP_ISEL_mask|P0_b_10_DFE_PREAMP_ISEL_mask|P0_b_10_DFE_SUMAMP_LP_MANUALOFF),(P0_b_11_ACDR_RATE_SEL_HALF_RATE|P0_b_10_DFE_SUMAMP_ISEL_400uA|P0_b_10_DFE_PREAMP_ISEL_400uA));
		hdmiport_mask(RX_PHY_G3_reg,~(P0_g_11_ACDR_RATE_SEL_HALF_RATE|P0_g_10_DFE_SUMAMP_ISEL_mask|P0_g_10_DFE_PREAMP_ISEL_mask|P0_g_10_DFE_SUMAMP_LP_MANUALOFF),(P0_g_11_ACDR_RATE_SEL_HALF_RATE|P0_g_10_DFE_SUMAMP_ISEL_400uA|P0_g_10_DFE_PREAMP_ISEL_400uA));
		hdmiport_mask(RX_PHY_R3_reg,~(P0_r_11_ACDR_RATE_SEL_HALF_RATE|P0_r_10_DFE_SUMAMP_ISEL_mask|P0_r_10_DFE_PREAMP_ISEL_mask|P0_r_10_DFE_SUMAMP_LP_MANUALOFF),(P0_r_11_ACDR_RATE_SEL_HALF_RATE|P0_r_10_DFE_SUMAMP_ISEL_400uA|P0_r_10_DFE_PREAMP_ISEL_400uA));


		//LEQ_BIT_RATE    Mac5: CLK_PIX2_RATE_SEL reserved but we still set
		hdmiport_mask(RX_PHY_B1_reg, ~(P1_b_2_LEQ_BIT_RATE_mask|P0_b_CLK_PIX2_RATE_SEL), (P1_b_2_LEQ_BIT_RATE_MBR|P0_b_CLK_PIX2_RATE_SEL));
		hdmiport_mask(RX_PHY_G1_reg, ~(P1_g_2_LEQ_BIT_RATE_mask|P0_g_CLK_PIX2_RATE_SEL), (P1_g_2_LEQ_BIT_RATE_MBR|P0_g_CLK_PIX2_RATE_SEL));
		hdmiport_mask(RX_PHY_R1_reg, ~(P1_r_2_LEQ_BIT_RATE_mask|P0_r_CLK_PIX2_RATE_SEL), (P1_r_2_LEQ_BIT_RATE_MBR|P0_r_CLK_PIX2_RATE_SEL));


		//PI_SEL  & pr bypass
		hdmiport_mask(RX_PHY_B2_reg,~(P1_b_8_BY_PASS_PR),0);
		hdmiport_mask(RX_PHY_G2_reg,~(P1_g_8_BY_PASS_PR),0);
		hdmiport_mask(RX_PHY_R2_reg,~(P1_r_8_BY_PASS_PR),0);


	} else { // under 1.5G  LBR

		hdmiport_mask(RX_PHY_B2_reg,~(P0_b_7_LEQ_ISEL|P0_b_6_TAP0_HBR|P0_b_5_DA_LANE_ISEL| P0_b_5_LEQ_CURRENT_ADJ|P0_b_5_TAP0_CURRENT_ADJ),(P0_b_7_LEQ_ISEL_100uA | P0_b_6_TAP0_HBR | P0_b_5_DA_LANE_ISEL_100uA |P0_b_5_LEQ_CURRENT_ADJ_1X|P0_b_5_TAP0_CURRENT_ADJ_1X));		//tap0
		hdmiport_mask(RX_PHY_G2_reg,~(P0_g_7_LEQ_ISEL|P0_g_6_TAP0_HBR|P0_g_5_DA_LANE_ISEL| P0_g_5_LEQ_CURRENT_ADJ|P0_g_5_TAP0_CURRENT_ADJ),(P0_g_7_LEQ_ISEL_100uA | P0_g_6_TAP0_HBR |P0_g_5_DA_LANE_ISEL_100uA| P0_g_5_LEQ_CURRENT_ADJ_1X|P0_g_5_TAP0_CURRENT_ADJ_1X));		//tap0
		hdmiport_mask(RX_PHY_R2_reg,~(P0_r_7_LEQ_ISEL|P0_r_6_TAP0_HBR|P0_r_5_DA_LANE_ISEL| P0_r_5_LEQ_CURRENT_ADJ|P0_r_5_TAP0_CURRENT_ADJ),  (P0_r_7_LEQ_ISEL_100uA | P0_r_6_TAP0_HBR  | P0_r_5_DA_LANE_ISEL_100uA|P0_r_5_LEQ_CURRENT_ADJ_1X|P0_r_5_TAP0_CURRENT_ADJ_1X));		//tap0

		hdmiport_mask(RX_PHY_B3_reg,~(P0_b_11_ACDR_RATE_SEL_HALF_RATE|P0_b_10_DFE_SUMAMP_ISEL_mask|P0_b_10_DFE_PREAMP_ISEL_mask|P0_b_10_DFE_SUMAMP_LP_MANUALOFF),(P0_b_11_ACDR_RATE_SEL_HALF_RATE|P0_b_10_DFE_SUMAMP_ISEL_400uA|P0_b_10_DFE_PREAMP_ISEL_400uA));
		hdmiport_mask(RX_PHY_G3_reg,~(P0_g_11_ACDR_RATE_SEL_HALF_RATE|P0_g_10_DFE_SUMAMP_ISEL_mask|P0_g_10_DFE_PREAMP_ISEL_mask|P0_g_10_DFE_SUMAMP_LP_MANUALOFF),(P0_g_11_ACDR_RATE_SEL_HALF_RATE|P0_g_10_DFE_SUMAMP_ISEL_400uA|P0_g_10_DFE_PREAMP_ISEL_400uA));
		hdmiport_mask(RX_PHY_R3_reg,~(P0_r_11_ACDR_RATE_SEL_HALF_RATE|P0_r_10_DFE_SUMAMP_ISEL_mask|P0_r_10_DFE_PREAMP_ISEL_mask|P0_r_10_DFE_SUMAMP_LP_MANUALOFF),(P0_r_11_ACDR_RATE_SEL_HALF_RATE|P0_r_10_DFE_SUMAMP_ISEL_400uA|P0_r_10_DFE_PREAMP_ISEL_400uA));

		//LEQ_BIT_RATE,  Mac5: CLK_PIX2_RATE_SEL reserved but we still set
		hdmiport_mask(RX_PHY_B1_reg, ~(P0_b_2_LEQ_BIT_RATE_mask|P0_b_CLK_PIX2_RATE_SEL), (P1_b_2_LEQ_BIT_RATE_LBR| P0_b_CLK_PIX2_RATE_SEL));
		hdmiport_mask(RX_PHY_G1_reg, ~(P0_g_2_LEQ_BIT_RATE_mask|P0_g_CLK_PIX2_RATE_SEL), (P1_b_2_LEQ_BIT_RATE_LBR |P0_g_CLK_PIX2_RATE_SEL));
		hdmiport_mask(RX_PHY_R1_reg, ~(P0_r_2_LEQ_BIT_RATE_mask|P0_r_CLK_PIX2_RATE_SEL), (P1_r_2_LEQ_BIT_RATE_LBR | P0_r_CLK_PIX2_RATE_SEL));


		//DA_LANE_ISEL  & pr bypass
		hdmiport_mask(RX_PHY_B2_reg,~(P1_b_8_BY_PASS_PR), 0);
		hdmiport_mask(RX_PHY_G2_reg,~(P1_g_8_BY_PASS_PR), 0);
		hdmiport_mask(RX_PHY_R2_reg,~(P1_r_8_BY_PASS_PR), 0);

	}

}

void lib_hdmi_set_dfe(unsigned char nport, unsigned int b, unsigned char dfe_mode)
{
	HDMI_PRINTF("%s\n", __func__);

	lib_hdmi_dfe_power(nport, 1);

	hdmiport_mask(DFE_REG_DFE_MODE_reg,
		~(DFE_REG_DFE_MODE_adapt_mode_mask|DFE_REG_DFE_MODE_edge_det_mode_mask|
		DFE_REG_DFE_MODE_transition_only_mask|DFE_REG_DFE_MODE_tap1_delay_mask|
		DFE_REG_DFE_MODE_tap24_delay_mask|DFE_REG_DFE_MODE_le_delay_mask|
		DFE_REG_DFE_MODE_servo_delay_mask|DFE_REG_DFE_MODE_gray_en_mask|
		DFE_REG_DFE_MODE_dfe_adapt_rstb_mask|
		DFE_REG_DFE_MODE_tap0_notrans_mask),
		(DFE_REG_DFE_MODE_adapt_mode(dfe_mode)|DFE_REG_DFE_MODE_edge_det_mode(0)|
		DFE_REG_DFE_MODE_transition_only_mask|DFE_REG_DFE_MODE_tap1_delay(1)|
		DFE_REG_DFE_MODE_tap24_delay(1)|DFE_REG_DFE_MODE_le_delay(1)|
		DFE_REG_DFE_MODE_servo_delay(1)|DFE_REG_DFE_MODE_gray_en_mask|
		DFE_REG_DFE_MODE_tap0_notrans_mask));  //mac5- DFE_REG_DFE_MODE_servo_notrans_mask

	hdmiport_mask(DFE_REG_DFE_EN_L0_reg,
		~(DFE_REG_DFE_EN_L0_clk_inv_lane0_mask|DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2_mask|DFE_REG_DFE_EN_L2_rl_det_en_lane2_mask|DFE_REG_DFE_EN_L0_rl_det_mode_lane0_mask |DFE_REG_DFE_EN_L2_rl_threshold_lane2_mask|DFE_REG_DFE_EN_L2_dfe_adapt_en_lane2_mask|DFE_REG_DFE_EN_L2_le_min_lane2_mask|DFE_REG_DFE_EN_L2_le_init_lane2_mask|DFE_REG_DFE_EN_L2_tap4_init_lane2_mask),
		(DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2(2))|DFE_REG_DFE_EN_L2_rl_det_mode_lane2(1) |DFE_REG_DFE_EN_L2_rl_threshold_lane2(1)|DFE_REG_DFE_EN_L2_le_min_lane2(0x18)|DFE_REG_DFE_EN_L2_le_init_lane2(0x8));
	hdmiport_mask(DFE_REG_DFE_EN_L1_reg,
		~(DFE_REG_DFE_EN_L1_clk_inv_lane1_mask|DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2_mask|DFE_REG_DFE_EN_L2_rl_det_en_lane2_mask|DFE_REG_DFE_EN_L1_rl_det_mode_lane1_mask | DFE_REG_DFE_EN_L2_rl_threshold_lane2_mask|DFE_REG_DFE_EN_L2_dfe_adapt_en_lane2_mask|DFE_REG_DFE_EN_L2_le_min_lane2_mask|DFE_REG_DFE_EN_L2_le_init_lane2_mask|DFE_REG_DFE_EN_L2_tap4_init_lane2_mask),
		(DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2(2))|DFE_REG_DFE_EN_L2_rl_det_mode_lane2(1) |DFE_REG_DFE_EN_L2_rl_threshold_lane2(1)|DFE_REG_DFE_EN_L2_le_min_lane2(0x18)|DFE_REG_DFE_EN_L2_le_init_lane2(0x8));
	hdmiport_mask(DFE_REG_DFE_EN_L2_reg,
		~(DFE_REG_DFE_EN_L2_clk_inv_lane2_mask|DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2_mask|DFE_REG_DFE_EN_L2_rl_det_en_lane2_mask|DFE_REG_DFE_EN_L2_rl_det_mode_lane2_mask | DFE_REG_DFE_EN_L2_rl_threshold_lane2_mask|DFE_REG_DFE_EN_L2_dfe_adapt_en_lane2_mask|DFE_REG_DFE_EN_L2_le_min_lane2_mask|DFE_REG_DFE_EN_L2_le_init_lane2_mask|DFE_REG_DFE_EN_L2_tap4_init_lane2_mask),
		(DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2(2))|DFE_REG_DFE_EN_L2_rl_det_mode_lane2(1) |DFE_REG_DFE_EN_L2_rl_threshold_lane2(1)|DFE_REG_DFE_EN_L2_le_min_lane2(0x18)|DFE_REG_DFE_EN_L2_le_init_lane2(0x8));


	hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,
		~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask|DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask|DFE_REG_DFE_INIT0_L0_vth_init_lane0_mask),
		(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(0xc)|DFE_REG_DFE_INIT0_L0_tap0_init_lane0(0x14)|DFE_REG_DFE_INIT0_L0_vth_init_lane0(0x3)));
	hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,
		~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask|DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask|DFE_REG_DFE_INIT0_L0_vth_init_lane0_mask),
		(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(0xc)|DFE_REG_DFE_INIT0_L0_tap0_init_lane0(0x14)|DFE_REG_DFE_INIT0_L0_vth_init_lane0(0x3)));
	hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,
		~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask|DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask|DFE_REG_DFE_INIT0_L0_vth_init_lane0_mask),
		(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(0xc)|DFE_REG_DFE_INIT0_L0_tap0_init_lane0(0x14)|DFE_REG_DFE_INIT0_L0_vth_init_lane0(0x3)));

	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg, ~DFE_REG_DFE_INIT1_L0_servo_init_lane0_mask, DFE_REG_DFE_INIT1_L0_servo_init_lane0(0xf));
	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg, ~DFE_REG_DFE_INIT1_L0_servo_init_lane0_mask, DFE_REG_DFE_INIT1_L0_servo_init_lane0(0xf));
	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg, ~DFE_REG_DFE_INIT1_L0_servo_init_lane0_mask, DFE_REG_DFE_INIT1_L0_servo_init_lane0(0xf));

	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(DFE_REG_DFE_INIT1_L0_init1_rev1_lane0_mask),(_BIT19|_BIT21|_BIT23));
	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(DFE_REG_DFE_INIT1_L0_init1_rev1_lane0_mask),(_BIT19|_BIT21|_BIT23));
	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(DFE_REG_DFE_INIT1_L0_init1_rev1_lane0_mask),(_BIT19|_BIT21|_BIT23));

	//load initial data
	hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask);
	hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask);
	hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask);

	udelay(1);

	hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),0);
	hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),0);
	hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),0);


	//adapt reset release
	hdmiport_mask(DFE_REG_DFE_MODE_reg,~(DFE_REG_DFE_MODE_dfe_adapt_rstb_mask),DFE_REG_DFE_MODE_dfe_adapt_rstb_mask);
	//set run length = 4
	hdmiport_mask(DFE_REG_DFE_GAIN_reg,~(DFE_REG_DFE_GAIN_trans_rlength_mask),DFE_REG_DFE_GAIN_trans_rlength(2));

	//set tap tap1 tap2 max min value
	if (b < 2844 && b > 1420) {   //  3G ~1.5G
		hdmiport_mask(DFE_REG_DFE_LIMIT0_reg,
			~(DFE_REG_DFE_LIMIT0_tap1_min_mask|DFE_REG_DFE_LIMIT0_tap2_max_mask|DFE_REG_DFE_LIMIT0_tap2_min_mask),
			(DFE_REG_DFE_LIMIT0_tap1_min(0x10)|DFE_REG_DFE_LIMIT0_tap2_max(0x0a)|DFE_REG_DFE_LIMIT0_tap2_min(0x5)));
		hdmiport_mask(DFE_REG_DFE_LIMIT2_reg, ~(DFE_REG_DFE_LIMIT2_tap0_max_mask), (DFE_REG_DFE_LIMIT2_tap0_max(0x24)));
	} else {
		hdmiport_mask(DFE_REG_DFE_LIMIT0_reg,
			~(DFE_REG_DFE_LIMIT0_tap1_min_mask|DFE_REG_DFE_LIMIT0_tap2_max_mask|DFE_REG_DFE_LIMIT0_tap2_min_mask),
// LCB6			(DFE_REG_DFE_LIMIT0_tap1_min(0x35)|DFE_REG_DFE_LIMIT0_tap2_max(0x0a)|DFE_REG_DFE_LIMIT0_tap2_min(0x5)));
			(DFE_REG_DFE_LIMIT0_tap1_min(0x35)|DFE_REG_DFE_LIMIT0_tap2_max(0x0a)|DFE_REG_DFE_LIMIT0_tap2_min(0x0)));
		hdmiport_mask(DFE_REG_DFE_LIMIT2_reg,~(DFE_REG_DFE_LIMIT2_tap0_max_mask),(DFE_REG_DFE_LIMIT2_tap0_max(0x24)));
	}

	//Vth_min=0,Vth_max=0x7,Vth_th=0,Tap0_th=0
	hdmiport_mask(DFE_REG_DFE_LIMIT1_reg,~(DFE_REG_DFE_LIMIT1_vth_min_mask|DFE_REG_DFE_LIMIT1_vth_max_mask|DFE_REG_DFE_LIMIT1_vth_threshold_mask|DFE_REG_DFE_LIMIT1_tap0_threshold_mask|DFE_REG_DFE_LIMIT1_tap0_adjust_mask|DFE_REG_DFE_LIMIT1_tap1_trans_mask),(DFE_REG_DFE_LIMIT1_vth_min(0)|DFE_REG_DFE_LIMIT1_vth_max(0x7)|DFE_REG_DFE_LIMIT1_tap0_adjust(0x02)|DFE_REG_DFE_LIMIT1_tap1_trans_mask));

	// ENABLE  VTH & TAP0
	hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth),(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth));
	hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth),(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth));
	hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth),(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth));

	udelay(1);

#if 0 //MHL_SUPPORT
	if (!lib_mhl_port_is_turn_on(nport))
#endif
	{
		lib_hdmi_dfe_second_flow(nport, b);
		lib_hdmi_fg_koffset_proc(nport);
	}


	if (b > 2700) {  // 3G need tap2 but below not need
		hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE|REG_dfe_adapt_en_lane0_TAP2),(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE|REG_dfe_adapt_en_lane0_TAP2));
		hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE|REG_dfe_adapt_en_lane1_TAP2),(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE|REG_dfe_adapt_en_lane1_TAP2));
		hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE|REG_dfe_adapt_en_lane2_TAP2),(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE|REG_dfe_adapt_en_lane2_TAP2));
	} else {
		hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE|REG_dfe_adapt_en_lane0_TAP2),(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE));
		hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE|REG_dfe_adapt_en_lane1_TAP2),(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE));
		hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE|REG_dfe_adapt_en_lane2_TAP2),(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE));
	}

}

void lib_hdmi_set_dfe_mid_band(unsigned char nport, unsigned int b_clk, int dfe_mode)
{
	HDMI_PRINTF("%s\n", __func__);

	lib_hdmi_dfe_power(nport, 1);

	hdmiport_mask(DFE_REG_DFE_MODE_reg,
		~(DFE_REG_DFE_MODE_adapt_mode_mask|DFE_REG_DFE_MODE_edge_det_mode_mask|
		DFE_REG_DFE_MODE_transition_only_mask|DFE_REG_DFE_MODE_tap1_delay_mask|
		DFE_REG_DFE_MODE_tap24_delay_mask|DFE_REG_DFE_MODE_le_delay_mask|
		DFE_REG_DFE_MODE_servo_delay_mask|DFE_REG_DFE_MODE_gray_en_mask|
		DFE_REG_DFE_MODE_dfe_adapt_rstb_mask|
		DFE_REG_DFE_MODE_tap0_notrans_mask),
		(DFE_REG_DFE_MODE_adapt_mode(dfe_mode)|DFE_REG_DFE_MODE_edge_det_mode(0)|
		DFE_REG_DFE_MODE_transition_only_mask|DFE_REG_DFE_MODE_tap1_delay(1)|
		DFE_REG_DFE_MODE_tap24_delay(1)|DFE_REG_DFE_MODE_le_delay(1)|
		DFE_REG_DFE_MODE_servo_delay(1)|DFE_REG_DFE_MODE_gray_en_mask|
		DFE_REG_DFE_MODE_tap0_notrans_mask));  //mac5- DFE_REG_DFE_MODE_servo_notrans_mask

	hdmiport_mask(DFE_REG_DFE_EN_L0_reg,
		~(DFE_REG_DFE_EN_L0_clk_inv_lane0_mask|DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2_mask|DFE_REG_DFE_EN_L2_rl_det_en_lane2_mask|DFE_REG_DFE_EN_L2_rl_threshold_lane2_mask|DFE_REG_DFE_EN_L2_dfe_adapt_en_lane2_mask|DFE_REG_DFE_EN_L2_le_min_lane2_mask|DFE_REG_DFE_EN_L2_le_init_lane2_mask),
		(DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2(2))|DFE_REG_DFE_EN_L2_rl_threshold_lane2(1)|DFE_REG_DFE_EN_L2_le_min_lane2(0x18)|DFE_REG_DFE_EN_L2_le_init_lane2(0x2));
	hdmiport_mask(DFE_REG_DFE_EN_L1_reg,
		~(DFE_REG_DFE_EN_L1_clk_inv_lane1_mask|DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2_mask|DFE_REG_DFE_EN_L2_rl_det_en_lane2_mask|DFE_REG_DFE_EN_L2_rl_threshold_lane2_mask|DFE_REG_DFE_EN_L2_dfe_adapt_en_lane2_mask|DFE_REG_DFE_EN_L2_le_min_lane2_mask|DFE_REG_DFE_EN_L2_le_init_lane2_mask),
		(DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2(2))|DFE_REG_DFE_EN_L2_rl_threshold_lane2(1)|DFE_REG_DFE_EN_L2_le_min_lane2(0x18)|DFE_REG_DFE_EN_L2_le_init_lane2(0x2));
	hdmiport_mask(DFE_REG_DFE_EN_L2_reg,
		~(DFE_REG_DFE_EN_L2_clk_inv_lane2_mask|DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2_mask|DFE_REG_DFE_EN_L2_rl_det_en_lane2_mask|DFE_REG_DFE_EN_L2_rl_threshold_lane2_mask|DFE_REG_DFE_EN_L2_dfe_adapt_en_lane2_mask|DFE_REG_DFE_EN_L2_le_min_lane2_mask|DFE_REG_DFE_EN_L2_le_init_lane2_mask),
		(DFE_REG_DFE_EN_L2_timer_ctrl_en_lane2_mask|DFE_REG_DFE_EN_L2_reduce_adapt_gain_lane2(2))|DFE_REG_DFE_EN_L2_rl_threshold_lane2(1)|DFE_REG_DFE_EN_L2_le_min_lane2(0x18)|DFE_REG_DFE_EN_L2_le_init_lane2(0x2));

	hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,
		~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask|DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask|DFE_REG_DFE_INIT0_L0_vth_init_lane0_mask),
		(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(0x0)|DFE_REG_DFE_INIT0_L0_tap0_init_lane0(0x14)|DFE_REG_DFE_INIT0_L0_vth_init_lane0(0x3)));
	hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,
		~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask|DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask|DFE_REG_DFE_INIT0_L0_vth_init_lane0_mask),
		(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(0x0)|DFE_REG_DFE_INIT0_L0_tap0_init_lane0(0x14)|DFE_REG_DFE_INIT0_L0_vth_init_lane0(0x3)));
	hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,
		~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask|DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask|DFE_REG_DFE_INIT0_L0_vth_init_lane0_mask),
		(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(0x0)|DFE_REG_DFE_INIT0_L0_tap0_init_lane0(0x14)|DFE_REG_DFE_INIT0_L0_vth_init_lane0(0x3)));

	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(DFE_REG_DFE_INIT1_L0_servo_init_lane0_mask), (DFE_REG_DFE_INIT1_L0_servo_init_lane0(0xf)));
	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(DFE_REG_DFE_INIT1_L0_servo_init_lane0_mask), (DFE_REG_DFE_INIT1_L0_servo_init_lane0(0xf)));
	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(DFE_REG_DFE_INIT1_L0_servo_init_lane0_mask), (DFE_REG_DFE_INIT1_L0_servo_init_lane0(0xf)));

	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(DFE_REG_DFE_INIT1_L0_init1_rev1_lane0_mask),(_BIT19|_BIT21|_BIT23));
	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(DFE_REG_DFE_INIT1_L0_init1_rev1_lane0_mask),(_BIT19|_BIT21|_BIT23));
	//mac5- hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(DFE_REG_DFE_INIT1_L0_init1_rev1_lane0_mask),(_BIT19|_BIT21|_BIT23));


	//load initial data
	hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask);
	hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask);
	hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask);
	udelay(1);
	hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),0);
	hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),0);
	hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask),0);


	//adapt reset release
	hdmiport_mask(DFE_REG_DFE_MODE_reg,~(DFE_REG_DFE_MODE_dfe_adapt_rstb_mask),DFE_REG_DFE_MODE_dfe_adapt_rstb_mask);
	//set run length = 4
	hdmiport_mask(DFE_REG_DFE_GAIN_reg,~(DFE_REG_DFE_GAIN_trans_rlength_mask),DFE_REG_DFE_GAIN_trans_rlength(2));

	//set tap tap1 tap2 max min value
	hdmiport_mask(DFE_REG_DFE_LIMIT0_reg,
		~(DFE_REG_DFE_LIMIT0_tap1_min_mask|DFE_REG_DFE_LIMIT0_tap2_max_mask|DFE_REG_DFE_LIMIT0_tap2_min_mask),
		(DFE_REG_DFE_LIMIT0_tap1_min(0x35)|DFE_REG_DFE_LIMIT0_tap2_max(0x0a)|DFE_REG_DFE_LIMIT0_tap2_min(0x5)));
	hdmiport_mask(DFE_REG_DFE_LIMIT2_reg, ~(DFE_REG_DFE_LIMIT2_tap0_max_mask), (DFE_REG_DFE_LIMIT2_tap0_max(0x24)));

	//Vth_min=0,Vth_max=0x7,Vth_th=0,Tap0_th=0
	hdmiport_mask(DFE_REG_DFE_LIMIT1_reg,~(DFE_REG_DFE_LIMIT1_vth_min_mask|DFE_REG_DFE_LIMIT1_vth_max_mask|DFE_REG_DFE_LIMIT1_vth_threshold_mask|DFE_REG_DFE_LIMIT1_tap0_threshold_mask|DFE_REG_DFE_LIMIT1_tap0_adjust_mask|DFE_REG_DFE_LIMIT1_tap1_trans_mask),(DFE_REG_DFE_LIMIT1_vth_min(0)|DFE_REG_DFE_LIMIT1_vth_max(0x7)|DFE_REG_DFE_LIMIT1_tap0_adjust(0x02)|DFE_REG_DFE_LIMIT1_tap1_trans_mask));

	// ENABLE  VTH & TAP0
	hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth),(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth));
	hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth),(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth));
	hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth),(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth));

	udelay(1);

	lib_hdmi_dfe_second_flow(nport, b_clk);
	lib_hdmi_fg_koffset_proc(nport);

	// ENABLE  VTH & TAP0
	hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth),(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth));
	hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth),(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth));
	hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth),(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth));

	//        //ENABLE TAP1 & LE
	//        hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_LE),(REG_dfe_adapt_en_lane0_TAP1));
	//        hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_LE),(REG_dfe_adapt_en_lane1_TAP1));
	//        hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_LE),(REG_dfe_adapt_en_lane2_TAP1));

}

void lib_hdmi_dfe_manual_set(unsigned char nport)
{
	HDMI_PRINTF("%s\n", __func__);

	lib_hdmi_dfe_rst(nport, 0);

	//disable dfe
	hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~DFE_REG_DFE_EN_L0_dfe_adapt_en_lane0_mask,0);
	hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~DFE_REG_DFE_EN_L1_dfe_adapt_en_lane1_mask,0);
	hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~DFE_REG_DFE_EN_L2_dfe_adapt_en_lane2_mask,0);

	hdmiport_mask(DFE_REG_DFE_MODE_reg,~DFE_REG_DFE_MODE_adapt_mode_mask,DFE_REG_DFE_MODE_adapt_mode(3));	//adaptive mode sel


	hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~DFE_REG_DFE_EN_L0_le_min_lane0_mask,DFE_REG_DFE_EN_L0_le_min_lane0(0xf));	//lane0 LE coefficient min		//0x18
	hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~DFE_REG_DFE_EN_L1_le_min_lane1_mask,DFE_REG_DFE_EN_L1_le_min_lane1(0xf));	//lane1 LE coefficient min		//0x18
	hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~DFE_REG_DFE_EN_L2_le_min_lane2_mask,DFE_REG_DFE_EN_L2_le_min_lane2(0xf));	//lane2 LE coefficient min		//0x18
	hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,~DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask,DFE_REG_DFE_INIT0_L0_tap1_init_lane0(3));	//lane0 tap1 initial
	hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,~DFE_REG_DFE_INIT0_L1_tap1_init_lane1_mask,DFE_REG_DFE_INIT0_L1_tap1_init_lane1(3));	//lane1 tap1 initial
	hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,~DFE_REG_DFE_INIT0_L2_tap1_init_lane2_mask,DFE_REG_DFE_INIT0_L2_tap1_init_lane2(3));	//lane2 tap1 initial

	hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,~DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask,DFE_REG_DFE_INIT0_L0_tap0_init_lane0(0x14));	//lane0 tap0 initial	//0xc
	hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,~DFE_REG_DFE_INIT0_L1_tap0_init_lane1_mask,DFE_REG_DFE_INIT0_L1_tap0_init_lane1(0x14));	//lane1 tap0 initial	//0xc
	hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,~DFE_REG_DFE_INIT0_L2_tap0_init_lane2_mask,DFE_REG_DFE_INIT0_L2_tap0_init_lane2(0x14));	//lane2 tap0 initial	//0xc



	hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask,DFE_REG_DFE_INIT1_L0_load_in_init_lane0(3));		//lane0  initial load
	hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~DFE_REG_DFE_INIT1_L1_load_in_init_lane1_mask,DFE_REG_DFE_INIT1_L1_load_in_init_lane1(3));		//lane1  initial load
	hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~DFE_REG_DFE_INIT1_L2_load_in_init_lane2_mask,DFE_REG_DFE_INIT1_L2_load_in_init_lane2(3));		//lane2  initial load
	udelay(1);	//10000
	hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~DFE_REG_DFE_INIT1_L0_load_in_init_lane0_mask,0);		//lane0  initial load
	hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~DFE_REG_DFE_INIT1_L1_load_in_init_lane1_mask,0);		//lane1  initial load
	hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~DFE_REG_DFE_INIT1_L2_load_in_init_lane2_mask,0);		//lane2  initial load

	lib_hdmi_fg_koffset_proc(nport);

}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
unsigned char lib_hdmi_dfe_tap0_fix(unsigned char nport)
{
	unsigned char i, tap0max[3], tap0[3];
	unsigned char tap0_max_of_3, tap0_min_of_3;

	//read Tap0 max
	for (i=0; i<3; i++) {
		tap0max[i] = lib_hdmi_dfe_get_tap0max(nport, i);
		tap0[i] = lib_hdmi_dfe_get_tap0(nport, i);
	}

	if ((tap0max[0] > 2) && (tap0max[1] > 2) && (tap0max[2] > 2)) {
		return FALSE;
	}
	tap0_max_of_3 = MAX(tap0[0], MAX(tap0[1], tap0[2]));
	tap0_min_of_3 = MIN(tap0[0], MIN(tap0[1], tap0[2]));

	if ((tap0_max_of_3 - tap0_min_of_3) < 8) {
		return FALSE;
	}

	HDMI_EMG("%s\n", __func__);
	lib_hdmi_dfe_init_vth(nport, (LN_R|LN_G|LN_B), 0x03);
	lib_hdmi_dfe_init_tap0(nport, (LN_R|LN_G|LN_B), 0x14);


#if 1
//#ifdef PLAN_B
	udelay(100);
	hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth), (REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth));
	hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth), (REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth));
	hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth), (REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth));
	udelay(500);
	hdmiport_mask(DFE_REG_DFE_READBACK_reg,~DFE_REG_DFE_READBACK_record_limit_en_mask,DFE_REG_DFE_READBACK_record_limit_en(1));
	udelay(500);
	hdmiport_mask(DFE_REG_DFE_READBACK_reg,~DFE_REG_DFE_READBACK_record_limit_en_mask,DFE_REG_DFE_READBACK_record_limit_en(0));
	hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth),0);
	hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth),0);
	hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth),0);
#endif

	return TRUE;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void lib_hdmi_dfe_second_flow(unsigned char nport, unsigned int b_clk)
{
unsigned char i, tap0max[3];

	udelay(100);
	hdmiport_mask(DFE_REG_DFE_READBACK_reg,~DFE_REG_DFE_READBACK_record_limit_en_mask,DFE_REG_DFE_READBACK_record_limit_en(1));
	udelay(500);
	hdmiport_mask(DFE_REG_DFE_READBACK_reg,~DFE_REG_DFE_READBACK_record_limit_en_mask,DFE_REG_DFE_READBACK_record_limit_en(0));
	lib_hdmi_dfe_adaptation(nport, (LN_R|LN_G|LN_B),
		(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth), 0);
	//hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth),0);
	//hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth),0);
	//hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth),0);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	if (b_clk > 5000) {
		lib_hdmi_dfe_tap0_fix(nport);
	}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	//read Tap0 max
	for (i=0; i<3; i++) {
		tap0max[i] = lib_hdmi_dfe_get_tap0max(nport, i);
		tap0max[i] = (tap0max[i]>2)?(tap0max[i]-2):0;
	}

	// LOAD TAP0 max -1  & Vth 4
	hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,~(DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask|DFE_REG_DFE_INIT0_L0_vth_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap0_init_lane0(tap0max[0]))|DFE_REG_DFE_INIT0_L0_vth_init_lane0(0x3));
	hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,~(DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask|DFE_REG_DFE_INIT0_L0_vth_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap0_init_lane0(tap0max[1]))|DFE_REG_DFE_INIT0_L0_vth_init_lane0(0x3));
	hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,~(DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask|DFE_REG_DFE_INIT0_L0_vth_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap0_init_lane0(tap0max[2]))|DFE_REG_DFE_INIT0_L0_vth_init_lane0(0x3));

	//load initial data
	hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(LOAD_IN_INIT_TAP0|LOAD_IN_INIT_VTH),(LOAD_IN_INIT_TAP0|LOAD_IN_INIT_VTH));
	hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(LOAD_IN_INIT_TAP0|LOAD_IN_INIT_VTH),(LOAD_IN_INIT_TAP0|LOAD_IN_INIT_VTH));
	hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(LOAD_IN_INIT_TAP0|LOAD_IN_INIT_VTH),(LOAD_IN_INIT_TAP0|LOAD_IN_INIT_VTH));
	udelay(1);

	hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(LOAD_IN_INIT_TAP0|LOAD_IN_INIT_VTH),0);
	hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(LOAD_IN_INIT_TAP0|LOAD_IN_INIT_VTH),0);
	hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(LOAD_IN_INIT_TAP0|LOAD_IN_INIT_VTH),0);

}

void lib_hdmi_load_le_max(unsigned char nport)
{
unsigned char lemax[3];

	HDMI_PRINTF("%s\n", __func__);

	//read LE max
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_limit_sel_mask, DFE_REG_DFE_READBACK_limit_sel(LIMIT_LE_MAX));

	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(0));
	lemax[0] = (DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg)));

	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(1));
	lemax[1] = (DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg)));

 	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(2));
	lemax[2] = (DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg)));

	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_limit_sel_mask, DFE_REG_DFE_READBACK_limit_sel(LIMIT_TAP1_MAX));

	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(0));
	lemax[0] += (DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg)));

	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(1));
	lemax[1] += (DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg)));

 	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(2));
	lemax[2] += (DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg)));

	// LOAD LE max
	hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(lemax[0])));
	hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(lemax[1])));
	hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(lemax[2])));

	//load initial data
	hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(LOAD_IN_INIT_TAP1),(LOAD_IN_INIT_TAP1));
	hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(LOAD_IN_INIT_TAP1),(LOAD_IN_INIT_TAP1));
	hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(LOAD_IN_INIT_TAP1),(LOAD_IN_INIT_TAP1));
	udelay(1);
	hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(LOAD_IN_INIT_TAP1),0);
	hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(LOAD_IN_INIT_TAP1),0);
	hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(LOAD_IN_INIT_TAP1),0);

}

void lib_hdmi_dfe_examine_le_coef(unsigned char nport, unsigned int b_clk)
{
unsigned char max_tap0, min_tap0;
//unsigned char  bLan0_LE,bLan1_LE,bLan2_LE;

	//HDMI_PRINTF("%s\n", __func__);
	//pr_err ("%s(%d)-TAP0(0=%d, 1=%d, 2=%d)\n", __func__,nport , lib_hdmi_dfe_get_tap0(nport, 0), lib_hdmi_dfe_get_tap0(nport, 1), lib_hdmi_dfe_get_tap0(nport, 2));

	max_tap0 = MAX(lib_hdmi_dfe_get_tap0(nport, 0), MAX(lib_hdmi_dfe_get_tap0(nport, 1), lib_hdmi_dfe_get_tap0(nport, 2)));
	min_tap0 = MIN(lib_hdmi_dfe_get_tap0(nport, 0), MIN(lib_hdmi_dfe_get_tap0(nport, 1), lib_hdmi_dfe_get_tap0(nport, 2)));
	HDMI_PRINTF ("%s(%d)-(max=%d, min=%d, b_clk=%d)\n",  __func__, nport ,max_tap0, min_tap0, b_clk);

	if ( (max_tap0-min_tap0 > 10) && ((b_clk > 2000) && (b_clk <2200)) ) {
		if(lib_hdmi_dfe_get_le(nport, 0) < 1){
			hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(0x1)));
			udelay(1);
			hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(LOAD_IN_INIT_TAP1),(LOAD_IN_INIT_TAP1));
			udelay(1);
			hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(LOAD_IN_INIT_TAP1),0);
			HDMI_EMG("[RELE_L0] LE reload 0x1\n");
		}

		if(lib_hdmi_dfe_get_le(nport, 1) < 1){
			hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(0x1)));
			udelay(1);
			hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(LOAD_IN_INIT_TAP1),(LOAD_IN_INIT_TAP1));
			udelay(1);
			hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(LOAD_IN_INIT_TAP1),0);
			HDMI_EMG("[RELE_L1] LE reload 0x1\n");
		}

		if(lib_hdmi_dfe_get_le(nport, 2) < 4){
			hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(0x6)));
			udelay(1);
			hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(LOAD_IN_INIT_TAP1),(LOAD_IN_INIT_TAP1));
			udelay(1);
			hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(LOAD_IN_INIT_TAP1),0);
			HDMI_EMG("[RELE_L2] LE reload 0x6\n");
		}
	}

#ifdef HDMI_EQ_LE_NOT_ZERO_ENABLE
	#if 0	//ZINWELL ZIN-101T STB, Timing 1080p60, LE=0 CRC unstable with 2m general cable
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_coef_sel_mask, DFE_REG_DFE_READBACK_coef_sel(COEF_LE));

	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(0));
	bLan0_LE = DFE_REG_DFE_READBACK_get_coef_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(1));
	bLan1_LE = DFE_REG_DFE_READBACK_get_coef_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(2));
	bLan2_LE = DFE_REG_DFE_READBACK_get_coef_data(hdmi_in(DFE_REG_DFE_READBACK_reg));


	if (bLan0_LE < 1) {
		HDMI_PRINTF("[DFE open] lan0 LE=0x%x < 1\n", bLan0_LE);
		bLan0_LE = 1;
		hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(bLan0_LE)));
		udelay(1);	//10000
		hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(load_in_init_lane0_tap1),(load_in_init_lane0_tap1));
		udelay(1);	//10000
		hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg,~(load_in_init_lane0_tap1),0);
	}

	if (bLan1_LE < 1) {
		HDMI_PRINTF("[DFE open] lan1 LE=0x%x < 1\n", bLan1_LE);
		bLan1_LE = 1;
		hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(bLan1_LE)));
		udelay(1);	//10000
		hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(load_in_init_lane0_tap1),(load_in_init_lane0_tap1));
		udelay(1);	//10000
		hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg,~(load_in_init_lane0_tap1),0);
	}

	if (bLan2_LE < 1) {
		HDMI_PRINTF("[DFE open] lan2 LE=0x%x < 1\n", bLan2_LE);
		bLan2_LE = 1;
		hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask),(DFE_REG_DFE_INIT0_L0_tap1_init_lane0(bLan2_LE)));
		udelay(1);	//10000
		hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(load_in_init_lane0_tap1),(load_in_init_lane0_tap1));
		udelay(1);	//10000
		hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg,~(load_in_init_lane0_tap1),0);
	}
	#endif
	//HDMI_PRINTF("[DFE open] bLan0_LE=0x%x, bLan1_LE=0x%x, bLan2_LE=0x%x\n", bLan0_LE, bLan1_LE, bLan2_LE);

#endif //#ifdef HDMI_EQ_LE_NOT_ZERO_ENABLE
}

void lib_hdmi_set_dfe_close(unsigned char nport)
{
	hdmiport_mask(DFE_REG_DFE_EN_L0_reg,~(REG_dfe_adapt_en_lane0_TAP0|REG_dfe_adapt_en_lane0_Vth|REG_dfe_adapt_en_lane0_TAP1|REG_dfe_adapt_en_lane0_TAP2|REG_dfe_adapt_en_lane0_LE),0);
	hdmiport_mask(DFE_REG_DFE_EN_L1_reg,~(REG_dfe_adapt_en_lane1_TAP0|REG_dfe_adapt_en_lane1_Vth|REG_dfe_adapt_en_lane1_TAP1|REG_dfe_adapt_en_lane1_TAP2|REG_dfe_adapt_en_lane1_LE),0);
	hdmiport_mask(DFE_REG_DFE_EN_L2_reg,~(REG_dfe_adapt_en_lane2_TAP0|REG_dfe_adapt_en_lane2_Vth|REG_dfe_adapt_en_lane2_TAP1|REG_dfe_adapt_en_lane2_TAP2|REG_dfe_adapt_en_lane2_LE),0);

	hdmiport_mask(DFE_REG_DFE_READBACK_reg,~DFE_REG_DFE_READBACK_record_limit_en_mask,DFE_REG_DFE_READBACK_record_limit_en(0));		//limit value record
}

void lib_hdmi_dfe_record_enable(unsigned char nport, unsigned char onoff)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_record_limit_en_mask, DFE_REG_DFE_READBACK_record_limit_en(onoff));
}

unsigned char lib_hdmi_dfe_is_record_enable(unsigned char nport)
{
	return DFE_REG_DFE_READBACK_get_record_limit_en(hdmi_in(DFE_REG_DFE_READBACK_reg));
}

void lib_hdmi_dfe_adaptation(unsigned char nport, unsigned char bgr, unsigned int adp_mask, unsigned char onoff)
{
	if (bgr&LN_R) {
		hdmiport_mask(DFE_REG_DFE_EN_L2_reg, ~(adp_mask), (onoff)?(adp_mask):0);
	}
	if (bgr&LN_G) {
		hdmiport_mask(DFE_REG_DFE_EN_L1_reg, ~(adp_mask), (onoff)?(adp_mask):0);
	}
	if (bgr&LN_B) {
		hdmiport_mask(DFE_REG_DFE_EN_L0_reg, ~(adp_mask), (onoff)?(adp_mask):0);
	}
}

void lib_hdmi_dfe_init_vth(unsigned char nport, unsigned char bgr, unsigned char value)
{
	if (bgr&LN_R) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,
			~(DFE_REG_DFE_INIT0_L2_vth_init_lane2_mask), (DFE_REG_DFE_INIT0_L2_vth_init_lane2(value)));
	}
	if (bgr&LN_G) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,
			~(DFE_REG_DFE_INIT0_L1_vth_init_lane1_mask), (DFE_REG_DFE_INIT0_L2_vth_init_lane2(value)));
	}
	if (bgr&LN_B) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,
			~(DFE_REG_DFE_INIT0_L0_vth_init_lane0_mask), (DFE_REG_DFE_INIT0_L0_vth_init_lane0(value)));
	}

	lib_hdmi_dfe_load_in_adp(nport, bgr, LOAD_IN_INIT_VTH);
}

void lib_hdmi_dfe_init_tap0(unsigned char nport, unsigned char bgr, unsigned char value)
{
	if (bgr&LN_R) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,
			~(DFE_REG_DFE_INIT0_L2_tap0_init_lane2_mask), (DFE_REG_DFE_INIT0_L2_tap0_init_lane2(value)));
	}
	if (bgr&LN_G) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,
			~(DFE_REG_DFE_INIT0_L1_tap0_init_lane1_mask), (DFE_REG_DFE_INIT0_L1_tap0_init_lane1(value)));
	}
	if (bgr&LN_B) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,
			~(DFE_REG_DFE_INIT0_L0_tap0_init_lane0_mask), (DFE_REG_DFE_INIT0_L0_tap0_init_lane0(value)));
	}

	lib_hdmi_dfe_load_in_adp(nport, bgr, LOAD_IN_INIT_TAP0);
}

void lib_hdmi_dfe_init_tap1(unsigned char nport, unsigned char bgr, unsigned char value)
{
	if (bgr&LN_R) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,
			~(DFE_REG_DFE_INIT0_L2_tap1_init_lane2_mask), (DFE_REG_DFE_INIT0_L2_tap1_init_lane2(value)));
	}
	if (bgr&LN_G) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,
			~(DFE_REG_DFE_INIT0_L1_tap1_init_lane1_mask), (DFE_REG_DFE_INIT0_L1_tap1_init_lane1(value)));
	}
	if (bgr&LN_B) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,
			~(DFE_REG_DFE_INIT0_L0_tap1_init_lane0_mask), (DFE_REG_DFE_INIT0_L0_tap1_init_lane0(value)));
	}

	lib_hdmi_dfe_load_in_adp(nport, bgr, LOAD_IN_INIT_TAP1);
}

void lib_hdmi_dfe_init_tap2(unsigned char nport, unsigned char bgr, signed char value)
{
	if (value < 0) {
		value = 0x20|((-value)&0x1f);
	} else {
		value = (value&0x1f);
	}
	if (bgr&LN_R) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L2_reg,
			~(DFE_REG_DFE_INIT0_L2_tap2_init_lane2_mask), (DFE_REG_DFE_INIT0_L2_tap2_init_lane2(value)));
	}
	if (bgr&LN_G) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L1_reg,
			~(DFE_REG_DFE_INIT0_L1_tap2_init_lane1_mask), (DFE_REG_DFE_INIT0_L1_tap2_init_lane1(value)));
	}
	if (bgr&LN_B) {
		hdmiport_mask(DFE_REG_DFE_INIT0_L0_reg,
			~(DFE_REG_DFE_INIT0_L0_tap2_init_lane0_mask), (DFE_REG_DFE_INIT0_L0_tap2_init_lane0(value)));
	}

	lib_hdmi_dfe_load_in_adp(nport, bgr, LOAD_IN_INIT_TAP2);
}

void lib_hdmi_dfe_init_le(unsigned char nport, unsigned char bgr, unsigned char value)
{
	if (bgr&LN_R) {
		hdmiport_mask(DFE_REG_DFE_EN_L2_reg,
			~(DFE_REG_DFE_EN_L2_le_init_lane2_mask), (DFE_REG_DFE_EN_L2_le_init_lane2(value)));
	}
	if (bgr&LN_G) {
		hdmiport_mask(DFE_REG_DFE_EN_L1_reg,
			~(DFE_REG_DFE_EN_L1_le_init_lane1_mask), (DFE_REG_DFE_EN_L1_le_init_lane1(value)));
	}
	if (bgr&LN_B) {
		hdmiport_mask(DFE_REG_DFE_EN_L0_reg,
			~(DFE_REG_DFE_EN_L0_le_init_lane0_mask), (DFE_REG_DFE_EN_L0_le_init_lane0(value)));
	}

	lib_hdmi_dfe_load_in_adp(nport, bgr, LOAD_IN_INIT_LE);
}

void lib_hdmi_dfe_load_in_adp(unsigned char nport, unsigned char bgr, unsigned int option)
{
	if (bgr&LN_R) {
		hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg, ~(option), (option));
	}
	if (bgr&LN_G) {
		hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg, ~(option), (option));
	}
	if (bgr&LN_B) {
		hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg, ~(option), (option));
	}

	udelay(1);

	if (bgr&LN_R) {
		hdmiport_mask(DFE_REG_DFE_INIT1_L2_reg, ~(option), 0);
	}
	if (bgr&LN_G) {
		hdmiport_mask(DFE_REG_DFE_INIT1_L1_reg, ~(option), 0);
	}
	if (bgr&LN_B) {
		hdmiport_mask(DFE_REG_DFE_INIT1_L0_reg, ~(option), 0);
	}
}

unsigned char lib_hdmi_dfe_get_vth(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_coef_sel_mask, DFE_REG_DFE_READBACK_coef_sel(COEF_VTH));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return DFE_REG_DFE_READBACK_get_coef_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
}

unsigned char lib_hdmi_dfe_get_tap0(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_coef_sel_mask, DFE_REG_DFE_READBACK_coef_sel(COEF_TAP0));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return DFE_REG_DFE_READBACK_get_coef_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
}

unsigned char lib_hdmi_dfe_get_tap0max(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_limit_sel_mask, DFE_REG_DFE_READBACK_limit_sel(LIMIT_TAP0_MAX));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
}

unsigned char lib_hdmi_dfe_get_tap0min(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_limit_sel_mask, DFE_REG_DFE_READBACK_limit_sel(LIMIT_TAP0_MIN));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
}

unsigned char lib_hdmi_dfe_get_tap1(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_coef_sel_mask, DFE_REG_DFE_READBACK_coef_sel(COEF_TAP1));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return DFE_REG_DFE_READBACK_get_coef_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
}

unsigned char lib_hdmi_dfe_get_tap1max(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_limit_sel_mask, DFE_REG_DFE_READBACK_limit_sel(LIMIT_TAP1_MAX));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
}

unsigned char lib_hdmi_dfe_get_tap1min(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_limit_sel_mask, DFE_REG_DFE_READBACK_limit_sel(LIMIT_TAP1_MIN));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
}

char lib_hdmi_dfe_get_tap2(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_coef_sel_mask, DFE_REG_DFE_READBACK_coef_sel(COEF_TAP2));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return get_TAP2_coef_sign(hdmi_in(DFE_REG_DFE_READBACK_reg))? \
			-get_TAP2_coef(DFE_REG_DFE_READBACK_get_coef_data(hdmi_in(DFE_REG_DFE_READBACK_reg))):
			get_TAP2_coef(DFE_REG_DFE_READBACK_get_coef_data(hdmi_in(DFE_REG_DFE_READBACK_reg)));
}

unsigned char lib_hdmi_dfe_get_le(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_coef_sel_mask, DFE_REG_DFE_READBACK_coef_sel(COEF_LE));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return DFE_REG_DFE_READBACK_get_coef_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
}

unsigned char lib_hdmi_dfe_get_lemax(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_limit_sel_mask, DFE_REG_DFE_READBACK_limit_sel(LIMIT_LE_MAX));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
}

unsigned char lib_hdmi_dfe_get_lemin(unsigned char nport, unsigned char lane)
{
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_limit_sel_mask, DFE_REG_DFE_READBACK_limit_sel(LIMIT_LE_MIN));
	hdmiport_mask(DFE_REG_DFE_READBACK_reg, ~DFE_REG_DFE_READBACK_lane_sel_mask, DFE_REG_DFE_READBACK_lane_sel(lane));
	return DFE_REG_DFE_READBACK_get_limit_data(hdmi_in(DFE_REG_DFE_READBACK_reg));
}



void lib_hdmi_cmu_pll_en(unsigned char nport, unsigned char enable)
{

const unsigned int reg_cmu_en[HDMI_PHY_TOTAL_NUM] = {DFE_HDMI_RX_PHY_P0_ENABLE_reg,
			DFE_HDMI_RX_PHY_P1_ENABLE_reg,
			DFE_HDMI_RX_PHY_P2_ENABLE_reg};

const unsigned int bit_mask[HDMI_PHY_TOTAL_NUM] = {DFE_HDMI_RX_PHY_P0_ENABLE_reg_p0_en_cmu_mask,
			DFE_HDMI_RX_PHY_P1_ENABLE_reg_p1_en_cmu_mask,
			DFE_HDMI_RX_PHY_P2_ENABLE_reg_p2_en_cmu_mask};


	if (nport >= HDMI_RX_PORT_MAX_NUM)
		return;

	hdmiport_mask(reg_cmu_en[nport], ~bit_mask[nport], enable?bit_mask[nport]:0);

}


void lib_hdmi_demux_ck_vcopll_rst(unsigned char nport, unsigned char rst)
{

// rst = 1: reset
// rst = 0: normal working operation
const unsigned int reg_phy_reset[HDMI_PHY_TOTAL_NUM] = {
		DFE_HDMI_RX_PHY_P0_RST_reg,
		DFE_HDMI_RX_PHY_P1_RST_reg,
		DFE_HDMI_RX_PHY_P2_RST_reg
		};

const unsigned int rgb_demux[HDMI_PHY_TOTAL_NUM] = {
		(DFE_HDMI_RX_PHY_P0_RST_p0_r_demux_rstb_mask|DFE_HDMI_RX_PHY_P0_RST_p0_g_demux_rstb_mask|DFE_HDMI_RX_PHY_P0_RST_p0_b_demux_rstb_mask),
		(DFE_HDMI_RX_PHY_P1_RST_p1_r_demux_rstb_mask|DFE_HDMI_RX_PHY_P1_RST_p1_g_demux_rstb_mask|DFE_HDMI_RX_PHY_P1_RST_p1_b_demux_rstb_mask),
		(DFE_HDMI_RX_PHY_P2_RST_p2_r_demux_rstb_mask|DFE_HDMI_RX_PHY_P2_RST_p2_g_demux_rstb_mask|DFE_HDMI_RX_PHY_P2_RST_p2_b_demux_rstb_mask)
		};
#if defined(RDC_SINGLE_LANE)
const unsigned int b_demux[HDMI_PHY_TOTAL_NUM] = {
		(DFE_HDMI_RX_PHY_P0_RST_p0_b_demux_rstb_mask),
		(DFE_HDMI_RX_PHY_P1_RST_p1_b_demux_rstb_mask),
		(DFE_HDMI_RX_PHY_P2_RST_p2_b_demux_rstb_mask)
		};
#endif

	if (nport >= HDMI_PHY_TOTAL_NUM)
		return;

	if (rst) {
		lib_hdmi_dfe_rst(nport, 1);
		hdmiport_mask(reg_phy_reset[nport], ~rgb_demux[nport], 0);
	} else {
#if defined(RDC_SINGLE_LANE)
		hdmiport_mask(reg_phy_reset[nport], ~rgb_demux[nport], b_demux[nport]);
#else
		hdmiport_mask(reg_phy_reset[nport], ~rgb_demux[nport], rgb_demux[nport]);
#endif
		lib_hdmi_dfe_rst(nport, 0);
	}

}


void lib_hdmi_dfe_rst(unsigned char nport, unsigned char rst)
{
// rst = 1: reset
// rst = 0: normal working operation
	if (nport >= HDMI_PHY_TOTAL_NUM)
		return;

	hdmiport_mask(HDMI_HDMI_CTS_FIFO_CTL_reg, ~HDMI_HDMI_CTS_FIFO_CTL_dfe_rstn_n_mask, rst?0:HDMI_HDMI_CTS_FIFO_CTL_dfe_rstn_n_mask);

}

void lib_hdmi_cdr_rst(unsigned char nport, unsigned char rst)
{

// rst = 1: reset
// rst = 0: normal working operation
const unsigned int rst_reg[HDMI_PHY_TOTAL_NUM] = {
	DFE_HDMI_RX_PHY_P0_REGD00_reg,
	DFE_HDMI_RX_PHY_P1_REGD20_reg,
	DFE_HDMI_RX_PHY_P2_REGD00_reg};

const unsigned int dig_bit[HDMI_PHY_TOTAL_NUM] = {

	(DFE_HDMI_RX_PHY_P0_REGD00_p0_r_dig_rst_n_mask|DFE_HDMI_RX_PHY_P0_REGD00_p0_g_dig_rst_n_mask|DFE_HDMI_RX_PHY_P0_REGD00_p0_b_dig_rst_n_mask),
	(DFE_HDMI_RX_PHY_P1_REGD20_p1_r_dig_rst_n_mask|DFE_HDMI_RX_PHY_P1_REGD20_p1_g_dig_rst_n_mask|DFE_HDMI_RX_PHY_P1_REGD20_p1_b_dig_rst_n_mask),
	(DFE_HDMI_RX_PHY_P2_REGD00_p2_r_dig_rst_n_mask|DFE_HDMI_RX_PHY_P2_REGD00_p2_g_dig_rst_n_mask|DFE_HDMI_RX_PHY_P2_REGD00_p2_b_dig_rst_n_mask)};

const unsigned int cdr_bit[HDMI_PHY_TOTAL_NUM] = {

	(DFE_HDMI_RX_PHY_P0_REGD00_p0_r_cdr_rst_n_mask|DFE_HDMI_RX_PHY_P0_REGD00_p0_g_cdr_rst_n_mask|DFE_HDMI_RX_PHY_P0_REGD00_p0_b_cdr_rst_n_mask),
	(DFE_HDMI_RX_PHY_P1_REGD20_p1_r_cdr_rst_n_mask|DFE_HDMI_RX_PHY_P1_REGD20_p1_g_cdr_rst_n_mask|DFE_HDMI_RX_PHY_P1_REGD20_p1_b_cdr_rst_n_mask),
	(DFE_HDMI_RX_PHY_P2_REGD00_p2_r_cdr_rst_n_mask|DFE_HDMI_RX_PHY_P2_REGD00_p2_g_cdr_rst_n_mask|DFE_HDMI_RX_PHY_P2_REGD00_p2_b_cdr_rst_n_mask)};


	if (nport >= HDMI_PHY_TOTAL_NUM)
		return;

	if (rst) {
		hdmiport_mask(rst_reg[nport], ~dig_bit[nport], 0);
		hdmiport_mask(rst_reg[nport], ~cdr_bit[nport], 0);
	} else {
		hdmiport_mask(rst_reg[nport], ~(dig_bit[nport]|cdr_bit[nport]), (dig_bit[nport]|cdr_bit[nport]));
	}

}

void lib_hdmi_wdog(unsigned char nport)
{

const unsigned int reg_cmu0[HDMI_PHY_TOTAL_NUM] = {
	DFE_HDMI_RX_PHY_P0_REGD05_reg,
	DFE_HDMI_RX_PHY_P1_REGD25_reg,
	DFE_HDMI_RX_PHY_P2_REGD05_reg};

const unsigned int reg_cmu1[HDMI_PHY_TOTAL_NUM] = {
	DFE_HDMI_RX_PHY_P0_REGD06_reg,
	DFE_HDMI_RX_PHY_P1_REGD26_reg,
	DFE_HDMI_RX_PHY_P2_REGD06_reg};

	if (nport >= HDMI_PHY_TOTAL_NUM)
		return;

	hdmi_out(reg_cmu0[nport], 0xE4E84505);
	hdmiport_mask(reg_cmu1[nport], ~(DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_wd_sdm_en_mask),0);
	udelay(5);
	hdmiport_mask(reg_cmu1[nport], ~(DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_wd_sdm_en_mask), DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_wd_sdm_en_mask);	//adams modify, 20160130	//Load CMU M code

}

void lib_hdmi_dfe_config_setting(unsigned char nport)
{


#if 1  // no FLD regs
		lib_hdmi_mac_afifo_enable(nport);
#else
        UINT32 waddr1 = 0, waddr2 = 0, waddr3 = 0, waddr4 = 0, waddr5 = 0, waddr6 = 0;

        if (nport == HDMI_PORT0) {
                waddr1 = DFE_HDMI_RX_PHY_REGD28_reg;
                waddr2 = DFE_HDMI_RX_PHY_REGD29_reg;
                waddr3 = DFE_HDMI_RX_PHY_REGD30_reg;
                waddr4 = DFE_HDMI_RX_PHY_REGD31_reg;
                waddr5 = DFE_HDMI_RX_PHY_REGD32_reg;
                waddr6 = DFE_HDMI_RX_PHY_REGD33_reg;
        } else if (nport == HDMI_PORT1) {
                waddr1 = DFE_HDMI_RX_PHY_REGD35_reg;
                waddr2 = DFE_HDMI_RX_PHY_REGD36_reg;
                waddr3 = DFE_HDMI_RX_PHY_REGD37_reg;
                waddr4 = DFE_HDMI_RX_PHY_REGD38_reg;
                waddr5 = DFE_HDMI_RX_PHY_REGD39_reg;
                waddr6 = DFE_HDMI_RX_PHY_REGD40_reg;
        } else if (nport == HDMI_PORT2) {
                waddr1 = DFE_HDMI_RX_PHY_REGD42_reg;
                waddr2 = DFE_HDMI_RX_PHY_REGD43_reg;
                waddr3 = DFE_HDMI_RX_PHY_REGD44_reg;
                waddr4 = DFE_HDMI_RX_PHY_REGD45_reg;
                waddr5 = DFE_HDMI_RX_PHY_REGD46_reg;
                waddr6 = DFE_HDMI_RX_PHY_REGD47_reg;
        } else {
        	return;
        }

        hdmiport_mask(waddr1,~(DFE_HDMI_RX_PHY_REGD28_reg_p0_auto_mode_mask|DFE_HDMI_RX_PHY_REGD28_reg_p0_adp_en_manual_mask|DFE_HDMI_RX_PHY_REGD28_reg_p0_adp_time_mask|DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_time_mask|DFE_HDMI_RX_PHY_REGD28_reg_p0_calib_late_mask|DFE_HDMI_RX_PHY_REGD28_reg_p0_vco_coarse_mask|DFE_HDMI_RX_PHY_REGD28_reg_p0_divide_num_mask|DFE_HDMI_RX_PHY_REGD28_reg_p0_init_time_mask),(DFE_HDMI_RX_PHY_REGD28_reg_p0_adp_en_manual_mask|_BIT25|_BIT20|_BIT18|_BIT16|_BIT15|_BIT9|_BIT7|_BIT1));
// need to check
//        if (GET_ISMHL() && mhl_is_ver3x() && mode == 0) {
//                hdmiport_mask(waddr2, ~(DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit_mask|DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit_mask), (DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit(0x456)|DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit(0x442)));
//                hdmiport_mask(waddr3,~(DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp_mask|DFE_HDMI_RX_PHY_REGD30_reg_p0_calib_reset_sel_mask),(DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp(0x4433A)|DFE_HDMI_RX_PHY_REGD30_reg_p0_calib_reset_sel_mask));
//        } else {
                hdmiport_mask(waddr2,~(DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit_mask|DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit_mask), (DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit(0x462)|DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit(0x44e)));
                hdmiport_mask(waddr3,~(DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp_mask|DFE_HDMI_RX_PHY_REGD30_reg_p0_calib_reset_sel_mask),(DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp(0x44332)|DFE_HDMI_RX_PHY_REGD30_reg_p0_calib_reset_sel_mask));
//        }

        hdmiport_mask(waddr4,~(DFE_HDMI_RX_PHY_REGD31_reg_p0_cp_time_mask|DFE_HDMI_RX_PHY_REGD31_reg_p0_timer_4_mask),(DFE_HDMI_RX_PHY_REGD31_reg_p0_cp_time(4)|DFE_HDMI_RX_PHY_REGD31_reg_p0_timer_4(2)));
        hdmiport_mask(waddr5,~(DFE_HDMI_RX_PHY_REGD32_reg_p0_timer_5_mask|DFE_HDMI_RX_PHY_REGD32_reg_p0_timer_6_mask),DFE_HDMI_RX_PHY_REGD32_reg_p0_timer_6(7));
        hdmiport_mask(waddr6,~(DFE_HDMI_RX_PHY_REGD33_reg_p0_rxidle_bypass_mask|DFE_HDMI_RX_PHY_REGD33_reg_p0_slope_band_mask|DFE_HDMI_RX_PHY_REGD33_reg_p0_old_mode_mask|_BIT15),(DFE_HDMI_RX_PHY_REGD33_reg_p0_rxidle_bypass_mask|DFE_HDMI_RX_PHY_REGD33_reg_p0_slope_band(8)|_BIT15));

        lib_hdmi_mac_afifo_enable(nport);
#endif

}



#if 0
#if MHL_SUPPORT

void lib_hdmi_set_mhl_phy_table(unsigned char bport, unsigned char mode)
{
        unsigned int wReg1, wReg2, wCk1Reg, wCk2Reg, ck_md_sel;
        unsigned int  B2Reg, G2REG, R2REG;
        HDMI_PHY_PARAM_T *p_phy_table;

	if (bport == 0) {
		wReg1 = DFE_HDMI_RX_PHY_REGD21_reg;
		wReg2 = DFE_HDMI_RX_PHY_REGD0_reg;
		wCk1Reg = DFE_HDMI_RX_PHY_P0_CK1_reg;
		B2Reg = DFE_HDMI_RX_PHY_P0_B2_reg;
		G2REG = DFE_HDMI_RX_PHY_P0_G2_reg;
		R2REG = DFE_HDMI_RX_PHY_P0_R2_reg;
		wCk2Reg = DFE_HDMI_RX_PHY_P0_CK2_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_REGD56_reg;
	} else if (bport == 1) {
		wReg1 = DFE_HDMI_RX_PHY_REGD23_reg;
		wReg2 = DFE_HDMI_RX_PHY_REGD5_reg;
		wCk1Reg = DFE_HDMI_RX_PHY_P1_CK1_reg;
		B2Reg = DFE_HDMI_RX_PHY_P1_B2_reg;
		G2REG = DFE_HDMI_RX_PHY_P1_G2_reg;
		R2REG = DFE_HDMI_RX_PHY_P1_R2_reg;
		wCk2Reg = DFE_HDMI_RX_PHY_P1_CK2_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_REGD58_reg;
	} else if (bport == 2) {
		wReg1 = DFE_HDMI_RX_PHY_REGD25_reg;
		wReg2 = DFE_HDMI_RX_PHY_REGD10_reg;
		wCk1Reg = DFE_HDMI_RX_PHY_P2_CK1_reg;
		B2Reg = DFE_HDMI_RX_PHY_P2_B2_reg;
		G2REG = DFE_HDMI_RX_PHY_P2_G2_reg;
		R2REG = DFE_HDMI_RX_PHY_P2_R2_reg;
		wCk2Reg = DFE_HDMI_RX_PHY_P2_CK2_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_REGD60_reg;
	} else {
		return;
	}


	if (newbase_hdmi_get_is_mhl_ppmode(bport)) {
#if MHL_USE_ACDR
		p_phy_table = mhl_phy_param;
#else
		p_phy_table = mhl_phy_pp_param;
#endif
		hdmiport_mask(ck_md_sel, ~DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_sel_mask, DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_sel(3));
		hdmiport_mask(wCk2Reg, ~P0_ck_6_CMU_BIG_KVCO_mask, P0_ck_6_CMU_BIG_KVCO_mask); //MHL setting suggested by Garran
		/*HDMI_PRINTF("[MHL] MHL_Set_Phy_Table(pp mode or mhl3)");*/
	} else {
		p_phy_table = mhl_phy_param;
		hdmiport_mask(ck_md_sel, ~DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_sel_mask, DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_sel(2));
		hdmiport_mask(wCk2Reg, ~P0_ck_6_CMU_BIG_KVCO_mask, 0); //MHL setting suggested by Garran
		/*HDMI_PRINTF("[MHL] MHL_Set_Phy_Table(24bit mode)");*/
	}

        //port 0 1  2
        //CMU setting
        // /*set M & N & PI_DIV & DEMUX   */
        //M
        hdmiport_mask(wReg1, ~DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code_mask, p_phy_table[mode].M_code<<DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code_shift);		//M code set
        //N code
        hdmiport_mask(wCk1Reg, ~(p0_ck_3_CMU_N_code|p0_ck_3_CMU_PREDIVN), p_phy_table[mode].N_code<<18);		//N code set
	 hdmiport_mask(wCk1Reg, ~(p0_ck_3_CMU_SEL_D4), p_phy_table[mode].SEL_D4<<16);	//SEL_D4


        //PI_DIV
        hdmiport_mask(B2Reg, ~P0_b_8_PR_RATE_SEL, p_phy_table[mode].PI_DIV<<26);		//PI_DIV code set
        hdmiport_mask(G2REG, ~P0_b_8_PR_RATE_SEL, p_phy_table[mode].PI_DIV<<26);		//PI_DIV code set
        hdmiport_mask(R2REG, ~P0_b_8_PR_RATE_SEL, p_phy_table[mode].PI_DIV<<26);		//PI_DIV code set
        //DEMUX
	hdmiport_mask(B2Reg, ~(P0_b_8_DEMUX|P0_b_7_PI_ISEL), (p_phy_table[mode].DEMUX<<29)|(p_phy_table[mode].PI_ISEL<<16));
	hdmiport_mask(G2REG, ~(P0_b_8_DEMUX|P0_b_7_PI_ISEL), (p_phy_table[mode].DEMUX<<29)|(p_phy_table[mode].PI_ISEL<<16));		//DEMUX code set
	hdmiport_mask(R2REG, ~(P0_b_8_DEMUX|P0_b_7_PI_ISEL), (p_phy_table[mode].DEMUX<<29)|(p_phy_table[mode].PI_ISEL<<16));		//DEMUX code set

        // LDO enable,CMU VCO select
        //need check when different freq
	hdmiport_mask(wCk2Reg,
		~(P0_ck_5_CMU_SEL_R1_mask|P0_ck_5_CMU_SEL_PUMP_DB_mask|
		P0_ck_5_CMU_SEL_PUMP_I_mask|P0_ck_6_CMU_SEL_CS_mask|P0_ck_6_CMU_EN_CAP_mask|
		P0_ck_6_CMU_BIG_KVCO_mask|P0_ck_7_CMU_BYPASS_PI_mask|
		P0_ck_8_CMU_BPPSR_mask|P0_ck_8_LDO_EN_mask|
		P0_ck_8_VSEL_LDO_A_mask),
		((p_phy_table[mode].CK_RS<<0)|(p_phy_table[mode].Icp_DUL<<3)|
		(p_phy_table[mode].CK_Icp<<4)|(p_phy_table[mode].CK_CS<<8)|p_phy_table[mode].EN_CAP<<12|
		P0_ck_6_CMU_BIG_KVCO_mask|P0_ck_7_CMU_BYPASS_PI_mask|
		DFE_HDMI_RX_PHY_P0_CMU_BPPSR(p_phy_table[mode].pscaler)|P0_ck_8_LDO_EN_mask|
		P0_ck_8_VSEL_LDO_A_mask));
        // KP set
	hdmiport_mask(wReg2,
		~(DFE_HDMI_RX_PHY_REGD0_reg_p0_kp_mask|DFE_HDMI_RX_PHY_REGD0_reg_p0_ki_mask|DFE_HDMI_RX_PHY_REGD0_reg_p0_bypass_sdm_int_mask|DFE_HDMI_RX_PHY_REGD5_reg_p1_rate_sel_mask),
		DFE_HDMI_RX_PHY_REGD0_reg_p0_kp(p_phy_table[mode].CDR_KP)|
		DFE_HDMI_RX_PHY_REGD0_reg_p0_ki(p_phy_table[mode].CDR_KI)|
		DFE_HDMI_RX_PHY_REGD0_reg_p0_bypass_sdm_int_mask|
		DFE_HDMI_RX_PHY_REGD5_reg_p1_rate_sel(p_phy_table[mode].RATE_SEL));

   //     hdmiport_mask(wCk2Reg, ~_BIT24, 0); //MHL setting suggested by Edward

}

#endif


void lib_hdmi_set_phy_table(unsigned char bport, unsigned char mode)
{


#ifdef MAC5P
unsigned int wReg1, wReg2, wCk1Reg, wCk2Reg, ck_md_sel;
unsigned int B2Reg, G2REG, R2REG;
//unsigned int m_code;

	if (bport == HDMI_PORT0) {
		wReg1 = DFE_HDMI_RX_PHY_P0_REGD06_reg;
		wReg2 = DFE_HDMI_RX_PHY_P0_REGD00_reg;
		wCk1Reg = DFE_HDMI_RX_PHY_P0_CK1_reg;
		B2Reg = DFE_HDMI_RX_PHY_P0_B2_reg;
		G2REG = DFE_HDMI_RX_PHY_P0_G2_reg;
		R2REG = DFE_HDMI_RX_PHY_P0_R2_reg;
		wCk2Reg = DFE_HDMI_RX_PHY_P0_CK2_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_P0_REGD07_reg;
	} else if (bport == HDMI_PORT1) {
		wReg1 = DFE_HDMI_RX_PHY_P1_REGD26_reg;
		wReg2 = DFE_HDMI_RX_PHY_P1_REGD20_reg;
		wCk1Reg = DFE_HDMI_RX_PHY_P1_CK1_reg;
		B2Reg = DFE_HDMI_RX_PHY_P1_B2_reg;
		G2REG = DFE_HDMI_RX_PHY_P1_G2_reg;
		R2REG = DFE_HDMI_RX_PHY_P1_R2_reg;
		wCk2Reg = DFE_HDMI_RX_PHY_P1_CK2_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_P1_REGD27_reg;
	} else if (bport == HDMI_PORT2) {
		wReg1 = DFE_HDMI_RX_PHY_P2_REGD06_reg;
		wReg2 = DFE_HDMI_RX_PHY_P2_REGD00_reg;
		wCk1Reg = DFE_HDMI_RX_PHY_P2_CK1_reg;
		B2Reg = DFE_HDMI_RX_PHY_P2_B2_reg;
		G2REG = DFE_HDMI_RX_PHY_P2_G2_reg;
		R2REG = DFE_HDMI_RX_PHY_P2_R2_reg;
		wCk2Reg = DFE_HDMI_RX_PHY_P2_CK2_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_P2_REGD07_reg;
	} else {
		return;
	}

	//CMU setting
	// /*set M & N & PI_DIV & DEMUX   */
	//M
	//if (bclk < 190) {  // only for 13.5M
	//	m_code = hdmi_phy_param[mode].M_code+4;
	//	m_code <<= 1;
	//	m_code -= 4;
	//	hdmiport_mask(wReg1, ~DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code_mask, m_code<<DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code_shift);		//M code set
	//} else {
		hdmiport_mask(wReg1, ~DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_n_code_mask, hdmi_phy_param[mode].M_code<<DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_n_code_shift);		//M code set
	//}
	//N code
	hdmiport_mask(wCk1Reg, ~(p0_ck_3_CMU_N_code|p0_ck_3_CMU_PREDIVN), hdmi_phy_param[mode].N_code<<18);		//N code set
	hdmiport_mask(wCk1Reg, ~(p0_ck_3_CMU_SEL_D4), hdmi_phy_param[mode].SEL_D4<<16);


	//PI_DIV
	hdmiport_mask(B2Reg, ~P0_b_8_PR_RATE_SEL, hdmi_phy_param[mode].PI_DIV<<26);		//PI_DIV code set
	hdmiport_mask(G2REG, ~P0_b_8_PR_RATE_SEL, hdmi_phy_param[mode].PI_DIV<<26);		//PI_DIV code set
	hdmiport_mask(R2REG, ~P0_b_8_PR_RATE_SEL, hdmi_phy_param[mode].PI_DIV<<26);		//PI_DIV code set
	//DEMUX
	hdmiport_mask(B2Reg, ~(P0_b_8_DEMUX|P0_b_7_PI_ISEL), (hdmi_phy_param[mode].DEMUX<<29)|(hdmi_phy_param[mode].PI_ISEL<<16));
	hdmiport_mask(G2REG, ~(P0_b_8_DEMUX|P0_b_7_PI_ISEL), (hdmi_phy_param[mode].DEMUX<<29)|(hdmi_phy_param[mode].PI_ISEL<<16));		//DEMUX code set
	hdmiport_mask(R2REG, ~(P0_b_8_DEMUX|P0_b_7_PI_ISEL), (hdmi_phy_param[mode].DEMUX<<29)|(hdmi_phy_param[mode].PI_ISEL<<16));		//DEMUX code set

	hdmiport_mask(wCk2Reg,
		~(P0_ck_5_CMU_SEL_R1_mask|P0_ck_5_CMU_SEL_PUMP_DB_mask|
		P0_ck_5_CMU_SEL_PUMP_I_mask|P0_ck_6_CMU_SEL_CS_mask|
		P0_ck_6_CMU_BIG_KVCO_mask|P0_ck_7_CMU_BYPASS_PI_mask|
		P0_ck_8_CMU_BPPSR_mask|P0_ck_8_LDO_EN_mask|
		P0_ck_8_VSEL_LDO_A_mask),
		((hdmi_phy_param[mode].CK_RS<<0)|(hdmi_phy_param[mode].Icp_DUL<<3)|
		(hdmi_phy_param[mode].CK_Icp<<4)|(hdmi_phy_param[mode].CK_CS<<8)|
		(phy_param->CMU_KVCO<<13)|P0_ck_7_CMU_BYPASS_PI_mask|
		DFE_HDMI_RX_PHY_P0_CMU_BPPSR(hdmi_phy_param[mode].pscaler)|P0_ck_8_LDO_EN_mask|
		P0_ck_8_VSEL_LDO_A_mask));

	hdmiport_mask(wReg2,
		~(DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_rate_sel_mask|
		DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_kp_mask|
		DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_ki_mask|
		DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_bypass_sdm_int_mask),
		(DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_rate_sel(hdmi_phy_param[mode].RATE_SEL)|
		(hdmi_phy_param[mode].CDR_KP<<DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_kp_shift)|
		(hdmi_phy_param[mode].CDR_KI<<DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_ki_shift)|
		DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_bypass_sdm_int_mask));

	hdmiport_mask(ck_md_sel, ~DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_sel_mask, DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_sel(0));

#else
unsigned int wReg1, wReg2, wCk1Reg, wCk2Reg, ck_md_sel;
unsigned int B2Reg, G2REG, R2REG;
//unsigned int m_code;

	if (bport == HDMI_PORT0) {
		wReg1 = DFE_HDMI_RX_PHY_REGD21_reg;
		wReg2 = DFE_HDMI_RX_PHY_REGD0_reg;
		wCk1Reg = DFE_HDMI_RX_PHY_P0_CK1_reg;
		B2Reg = DFE_HDMI_RX_PHY_P0_B2_reg;
		G2REG = DFE_HDMI_RX_PHY_P0_G2_reg;
		R2REG = DFE_HDMI_RX_PHY_P0_R2_reg;
		wCk2Reg = DFE_HDMI_RX_PHY_P0_CK2_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_REGD56_reg;
	} else if (bport == HDMI_PORT1) {
		wReg1 = DFE_HDMI_RX_PHY_REGD23_reg;
		wReg2 = DFE_HDMI_RX_PHY_REGD5_reg;
		wCk1Reg = DFE_HDMI_RX_PHY_P1_CK1_reg;
		B2Reg = DFE_HDMI_RX_PHY_P1_B2_reg;
		G2REG = DFE_HDMI_RX_PHY_P1_G2_reg;
		R2REG = DFE_HDMI_RX_PHY_P1_R2_reg;
		wCk2Reg = DFE_HDMI_RX_PHY_P1_CK2_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_REGD58_reg;
	} else if (bport == HDMI_PORT2) {
		wReg1 = DFE_HDMI_RX_PHY_REGD25_reg;
		wReg2 = DFE_HDMI_RX_PHY_REGD10_reg;
		wCk1Reg = DFE_HDMI_RX_PHY_P2_CK1_reg;
		B2Reg = DFE_HDMI_RX_PHY_P2_B2_reg;
		G2REG = DFE_HDMI_RX_PHY_P2_G2_reg;
		R2REG = DFE_HDMI_RX_PHY_P2_R2_reg;
		wCk2Reg = DFE_HDMI_RX_PHY_P2_CK2_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_REGD60_reg;
	} else {
		return;
	}

	//CMU setting
	// /*set M & N & PI_DIV & DEMUX   */
	//M
	//if (bclk < 190) {  // only for 13.5M
	//	m_code = hdmi_phy_param[mode].M_code+4;
	//	m_code <<= 1;
	//	m_code -= 4;
	//	hdmiport_mask(wReg1, ~DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code_mask, m_code<<DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code_shift);		//M code set
	//} else {
		hdmiport_mask(wReg1, ~DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code_mask, hdmi_phy_param[mode].M_code<<DFE_HDMI_RX_PHY_REGD21_reg_p0_n_code_shift);		//M code set
	//}
	//N code
	hdmiport_mask(wCk1Reg, ~(p0_ck_3_CMU_N_code|p0_ck_3_CMU_PREDIVN), hdmi_phy_param[mode].N_code<<18);		//N code set
	hdmiport_mask(wCk1Reg, ~(p0_ck_3_CMU_SEL_D4), hdmi_phy_param[mode].SEL_D4<<16);


	//PI_DIV
	hdmiport_mask(B2Reg, ~P0_b_8_PR_RATE_SEL, hdmi_phy_param[mode].PI_DIV<<26);		//PI_DIV code set
	hdmiport_mask(G2REG, ~P0_b_8_PR_RATE_SEL, hdmi_phy_param[mode].PI_DIV<<26);		//PI_DIV code set
	hdmiport_mask(R2REG, ~P0_b_8_PR_RATE_SEL, hdmi_phy_param[mode].PI_DIV<<26);		//PI_DIV code set
	//DEMUX
	hdmiport_mask(B2Reg, ~(P0_b_8_DEMUX|P0_b_7_PI_ISEL), (hdmi_phy_param[mode].DEMUX<<29)|(hdmi_phy_param[mode].PI_ISEL<<16));
	hdmiport_mask(G2REG, ~(P0_b_8_DEMUX|P0_b_7_PI_ISEL), (hdmi_phy_param[mode].DEMUX<<29)|(hdmi_phy_param[mode].PI_ISEL<<16));		//DEMUX code set
	hdmiport_mask(R2REG, ~(P0_b_8_DEMUX|P0_b_7_PI_ISEL), (hdmi_phy_param[mode].DEMUX<<29)|(hdmi_phy_param[mode].PI_ISEL<<16));		//DEMUX code set

	hdmiport_mask(wCk2Reg,
		~(P0_ck_5_CMU_SEL_R1_mask|P0_ck_5_CMU_SEL_PUMP_DB_mask|
		P0_ck_5_CMU_SEL_PUMP_I_mask|P0_ck_6_CMU_SEL_CS_mask|
		P0_ck_6_CMU_BIG_KVCO_mask|P0_ck_7_CMU_BYPASS_PI_mask|
		P0_ck_8_CMU_BPPSR_mask|P0_ck_8_LDO_EN_mask|
		P0_ck_8_VSEL_LDO_A_mask),
		((hdmi_phy_param[mode].CK_RS<<0)|(hdmi_phy_param[mode].Icp_DUL<<3)|
		(hdmi_phy_param[mode].CK_Icp<<4)|(hdmi_phy_param[mode].CK_CS<<8)|
		(hdmi_phy_param[mode].CMU_KVCO<<13)|P0_ck_7_CMU_BYPASS_PI_mask|
		DFE_HDMI_RX_PHY_P0_CMU_BPPSR(hdmi_phy_param[mode].pscaler)|P0_ck_8_LDO_EN_mask|
		P0_ck_8_VSEL_LDO_A_mask));

	hdmiport_mask(wReg2,
		~(DFE_HDMI_RX_PHY_REGD5_reg_p1_rate_sel_mask|
		DFE_HDMI_RX_PHY_REGD0_reg_p0_kp_mask|
		DFE_HDMI_RX_PHY_REGD0_reg_p0_ki_mask|
		DFE_HDMI_RX_PHY_REGD0_reg_p0_bypass_sdm_int_mask),
		(DFE_HDMI_RX_PHY_REGD5_reg_p1_rate_sel(hdmi_phy_param[mode].RATE_SEL)|
		(hdmi_phy_param[mode].CDR_KP<<DFE_HDMI_RX_PHY_REGD0_reg_p0_kp_shift)|
		(hdmi_phy_param[mode].CDR_KI<<DFE_HDMI_RX_PHY_REGD0_reg_p0_ki_shift)|
		DFE_HDMI_RX_PHY_REGD0_reg_p0_bypass_sdm_int_mask));

	hdmiport_mask(ck_md_sel, ~DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_sel_mask, DFE_HDMI_RX_PHY_REGD56_reg_p0_ck_md_sel(0));
#endif
}
#endif


void lib_hdmi_set_phy_table(unsigned char nport, HDMI_PHY_PARAM_T *phy_param)
{
unsigned int wReg1, wReg2, ck_md_sel;

	if (nport == HDMI_RX_PORT_IDX_0) {
		wReg1 = DFE_HDMI_RX_PHY_P0_REGD06_reg;
		wReg2 = DFE_HDMI_RX_PHY_P0_REGD00_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_P0_REGD07_reg;
	} else if (nport == HDMI_RX_PORT_IDX_1) {
		wReg1 = DFE_HDMI_RX_PHY_P1_REGD26_reg;
		wReg2 = DFE_HDMI_RX_PHY_P1_REGD20_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_P1_REGD27_reg;
	} else if (nport == HDMI_RX_PORT_IDX_2) {
		wReg1 = DFE_HDMI_RX_PHY_P2_REGD06_reg;
		wReg2 = DFE_HDMI_RX_PHY_P2_REGD00_reg;
		ck_md_sel = DFE_HDMI_RX_PHY_P2_REGD07_reg;
	} else {
		return;
	}

	hdmiport_mask(wReg1, ~DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_n_code_mask, (phy_param->M_code)<<DFE_HDMI_RX_PHY_P0_REGD06_reg_p0_n_code_shift);		//M code set

	//N code
	hdmiport_mask(RX_PHY_CK1_reg, ~(p0_ck_3_CMU_N_code|p0_ck_3_CMU_PREDIVN), (phy_param->N_code)<<18);		//N code set
	hdmiport_mask(RX_PHY_CK1_reg, ~(p0_ck_3_CMU_SEL_D4), (phy_param->SEL_D4)<<16);


	//PI_DIV
	hdmiport_mask(RX_PHY_B2_reg, ~P0_b_8_PR_RATE_SEL, (phy_param->PI_DIV)<<26);		//PI_DIV code set
	hdmiport_mask(RX_PHY_G2_reg, ~P0_b_8_PR_RATE_SEL, (phy_param->PI_DIV)<<26);		//PI_DIV code set
	hdmiport_mask(RX_PHY_R2_reg, ~P0_b_8_PR_RATE_SEL, (phy_param->PI_DIV)<<26);		//PI_DIV code set
	//DEMUX
	hdmiport_mask(RX_PHY_B2_reg, ~(P0_b_8_DEMUX), (phy_param->DEMUX)<<29);
	hdmiport_mask(RX_PHY_G2_reg, ~(P0_b_8_DEMUX), (phy_param->DEMUX)<<29);		//DEMUX code set
	hdmiport_mask(RX_PHY_R2_reg, ~(P0_b_8_DEMUX), (phy_param->DEMUX)<<29);		//DEMUX code set

	hdmiport_mask(RX_PHY_B3_reg, ~(P0_r_12_PI_CURRENT), (phy_param->PI_CURRENT)<<28);
	hdmiport_mask(RX_PHY_B3_reg, ~(P0_r_12_PI_CURRENT),  (phy_param->PI_CURRENT)<<28);	
	hdmiport_mask(RX_PHY_B3_reg, ~(P0_r_12_PI_CURRENT),  (phy_param->PI_CURRENT)<<28);


	hdmiport_mask(RX_PHY_CK2_reg,
		~(P0_ck_5_CMU_SEL_R1_mask|P0_ck_5_CMU_SEL_PUMP_DB_mask|
		P0_ck_5_CMU_SEL_PUMP_I_mask|P0_ck_6_CMU_SEL_CS_mask|
		P0_ck_6_CMU_BIG_KVCO_mask|P0_ck_7_CMU_BYPASS_PI_mask|
		P0_ck_8_CMU_SEL_CP_mask | P0_ck_8_CMU_BPPSR_mask|P0_ck_8_LDO_EN_mask|
		P0_ck_8_VSEL_LDO_A_mask),
		((phy_param->CK_RS<<0)|(phy_param->Icp_DUL<<3)|
		(phy_param->CK_Icp<<4)|(phy_param->CK_CS<<8)|
		(phy_param->CMU_KVCO<<13)|P0_ck_7_CMU_BYPASS_PI_mask|
		(phy_param->CMU_SEL_CP << 20) |DFE_HDMI_RX_PHY_P0_CMU_BPPSR(phy_param->pscaler)|
		DFE_HDMI_RX_PHY_P0_LDO_EN(1)|DFE_HDMI_RX_PHY_P0_VSEL_LDO(0x4)));

	hdmiport_mask(wReg2,
		~(DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_rate_sel_mask|
		DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_kp_mask|
		DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_ki_mask|
		DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_bypass_sdm_int_mask),
		(DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_rate_sel(phy_param->RATE_SEL)|
		(phy_param->CDR_KP<<DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_kp_shift)|
		(phy_param->CDR_KI<<DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_ki_shift)|
		DFE_HDMI_RX_PHY_P0_REGD00_reg_p0_bypass_sdm_int_mask));


	hdmiport_mask(ck_md_sel, ~DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_sel_mask, DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_sel(0));

#if MHL_SUPPORT
	if (lib_mhl_port_is_turn_on(nport)) {
		if (lib_mhl_port_is_ppmode(nport)) {
			hdmiport_mask(ck_md_sel, ~DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_sel_mask, DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_sel(3));
		} else {
			hdmiport_mask(ck_md_sel, ~DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_sel_mask, DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_sel(2));
		}
	} else
#endif
	{
		hdmiport_mask(ck_md_sel, ~DFE_HDMI_RX_PHY_P0_REGD07_reg_p0_ck_md_sel_mask, DFE_HDMI_RX_PHY_P0_REGD07_get_reg_p0_ck_md_sel(0));
	}

}



void lib_hdmi_cco_band_config(unsigned char nport, unsigned int bclk)
{
/*
2.5G~3.0G    4740
2.0G~2.5G    3792
1.5G~2.0G    2844
*/
	#define HDMI_HIGH_BOUND 4740
	#define HDMI_MID_BOUND 3792
	#define HDMI_LOW_BOUND 2844

	#define MHL_HIGH_BOUND 1580               //4740/3
	#define MHL_MID_BOUND 1264			 //3792/3
	#define MHL_LOW_BOUND 	948			//2844/3

#if 0
const unsigned int reg_cmu1[HDMI_PORT_TOTAL_NUM] = {
	DFE_HDMI_RX_PHY_REGD21_reg,
	DFE_HDMI_RX_PHY_REGD23_reg,
	DFE_HDMI_RX_PHY_REGD25_reg,
	DFE_HDMI_RX_PHY_REGD27_reg
};

	unsigned int fvco;

	m = DFE_HDMI_RX_PHY_REGD21_get_reg_p0_n_code(rtd_inl(reg_cmu1[nport]))+4;
	pscr = DFE_HDMI_RX_PHY_P0_get_CMU_BPPSR(rtd_inl(reg_ck2[nport]))+1;  //0:/2; 1:/2
	cmu_sel_d4 = DFE_HDMI_RX_PHY_P0_get_CMU_SEL_D4(rtd_inl(reg_ck1[nport])); //p0_ck_3_CMU_SEL_D4
#endif

	unsigned char cco_band = 4;
	unsigned char pi_sel = 3;
	unsigned char cmu_cap = 1;
	unsigned int clk_multiple = bclk;
	unsigned int hvalue,mvalue,lvalue;
	hvalue = HDMI_HIGH_BOUND;
	lvalue = HDMI_LOW_BOUND;
	mvalue = HDMI_MID_BOUND;


	if (bclk == 0) return;

#if MHL_SUPPORT
	if (lib_mhl_port_is_turn_on(nport)) {
	if (!lib_mhl_port_is_ppmode(nport)) {
		hvalue = MHL_HIGH_BOUND;
		lvalue = MHL_LOW_BOUND;
		mvalue = MHL_MID_BOUND;
	}
	}
#endif
	

	while (clk_multiple < lvalue) {
		clk_multiple <<= 1;
	}

	if (clk_multiple >= hvalue) {
		cco_band = 4;
	} else if (clk_multiple >= mvalue) {
		cco_band = 6;
	} else if (clk_multiple >= lvalue) {
		cco_band = 0;
	} else {
		cco_band = 4;
	}


	if (clk_multiple < mvalue) 
		pi_sel = 3;
	 else 
		pi_sel = 2;
	
	
	if (clk_multiple > hvalue) 
		cmu_cap = 0;
	else 
		cmu_cap = 1;


#if MHL_SUPPORT
	if (lib_mhl_port_is_turn_on(nport)) {   //mhl special case for 3G~3.45G
		if ((bclk >= lvalue) && (bclk < mvalue))
			cco_band = 7;
	}
#endif

	hdmiport_mask(RX_PHY_B3_reg, ~(P0_b_12_PI_CSEL), DFE_HDMI_RX_PHY_P0_DFE_PI_CSEL(pi_sel));
	hdmiport_mask(RX_PHY_B3_reg, ~(P0_b_12_PI_CSEL), DFE_HDMI_RX_PHY_P0_DFE_PI_CSEL(pi_sel));		
	hdmiport_mask(RX_PHY_B3_reg, ~(P0_b_12_PI_CSEL), DFE_HDMI_RX_PHY_P0_DFE_PI_CSEL(pi_sel));

	hdmiport_mask(RX_PHY_B2_reg, ~(P0_b_7_PI_ISEL), DFE_HDMI_RX_PHY_P0_DFE_PI_ISEL(pi_sel));
	hdmiport_mask(RX_PHY_G2_reg, ~(P0_b_7_PI_ISEL), DFE_HDMI_RX_PHY_P0_DFE_PI_ISEL(pi_sel));		
	hdmiport_mask(RX_PHY_R2_reg, ~(P0_b_7_PI_ISEL), DFE_HDMI_RX_PHY_P0_DFE_PI_ISEL(pi_sel));


	hdmiport_mask(RX_PHY_CK2_reg, ~(P0_ck_6_CMU_EN_CAP_mask), DFE_HDMI_RX_PHY_P0_CMU_EN_CAP(cmu_cap));
	

	hdmiport_mask(RX_PHY_CK2_reg, ~(P0_ck_8_CCO_BAND_SEL_mask), DFE_HDMI_RX_PHY_P0_CCO_BAND_SEL(cco_band));

}


unsigned char lib_hdmi_acdr_check_result(unsigned char nport)
{
#if 0 //Mac5p no acdr
const unsigned int reg_fld6[] = { // regdb88
	DFE_HDMI_RX_PHY_REGD34_reg,
};

	if (nport > 0) {
		HDMI_EMG("[ERROR] ONLY SUPPORT PORT0, (port=%d)\n", nport);
		return FALSE;
	}

	HDMI_PRINTF("[HDMI] ACDR (fld_st=%x, cp_en=%d, coarse_fsm=0x%x) ==> ",
		DFE_HDMI_RX_PHY_REGD34_get_p0_fld_st_reg(hdmi_in(reg_fld6[nport])),
		DFE_HDMI_RX_PHY_REGD34_get_p0_cp_en_fsm_reg(hdmi_in(reg_fld6[nport])),
		DFE_HDMI_RX_PHY_REGD34_get_p0_coarse_fsm_reg(hdmi_in(reg_fld6[nport])));

	if (DFE_HDMI_RX_PHY_REGD34_get_p0_fld_st_reg(hdmi_in(reg_fld6[nport])) == 0x5) {
		HDMI_PRINTF("OK\n");
		return TRUE;
	} else {
		HDMI_EMG("FAIL (due to fld_st)\n");
		return FALSE;
	}
#endif
	return FALSE;
}

#if MHL_SUPPORT
unsigned char lib_hdmi_find_mhl_mode(unsigned int bvalue, unsigned char is_mhl_pp, unsigned char is_mhl3)
{
unsigned int data_rate = 0;

	if (is_mhl3) {
		data_rate = bvalue;
	} else if (is_mhl_pp) {
		data_rate = bvalue<<2;
	} else {
		data_rate = bvalue*3;
	}

	if (data_rate > 2854) { // 6G
		return 0;
	} else if (data_rate > 2190) { // 3G
		if (is_mhl3) {
			return 2;
		} else {
		return 1;
		}
	} else if (data_rate > 1432) { // 2.25G
		return 3;
	} else if (data_rate > 768) { // 1.5G
		return 4;
	} else {	// 750M
		return 5;
	}

}
#endif

void lib_hdmi_acdr_config_setting(unsigned char nport, unsigned char enable, unsigned int b)
{

#if 0 // MAC5P no acdr
const HDMI_ACDR_T acdr_table[5] = {
		{5860, 2854,   0x456, 0x442, 0x0a, 0x3, 0x1, 1, 1},  // 6
		{2854, 2190,   0x230, 0x21c, 0x0a, 0x4, 0x1, 0, 0},  // 3 //mhl3
		{2190, 1432,   0x343, 0x32f, 0x0a, 0x4, 0x1, 0, 0},  // 2.25
		{1432,   768,   0x230, 0x21c, 0x0a, 0x5, 0x1, 0, 0},  // 1.5
		{  768,   355,   0x230, 0x21c, 0x0a, 0x5, 0x1, 0, 0},  // 0.75
};

const unsigned int reg_wdog[] = {
	DFE_HDMI_RX_PHY_REGD20_reg,
};
const unsigned int reg_fld0[] = {
	DFE_HDMI_RX_PHY_REGD28_reg,
};
const unsigned int reg_fld1[] = {
	DFE_HDMI_RX_PHY_REGD29_reg,
};
const unsigned int reg_fld2[] = {
	DFE_HDMI_RX_PHY_REGD30_reg,
};
const unsigned int reg_fld5[] = {
	DFE_HDMI_RX_PHY_REGD33_reg,
};
const unsigned int reg_fld6[] = {
	DFE_HDMI_RX_PHY_REGD34_reg,
};
const unsigned int reg_st_m_value_b[] = {
	DFE_HDMI_RX_PHY_REGD75_reg,
};
const unsigned int reg_acdr1[] = {
	DFE_HDMI_RX_PHY_P0_ACDR1_reg,
};
const unsigned int reg_acdr2[] = {
	DFE_HDMI_RX_PHY_P0_ACDR2_reg,
};

	const unsigned int reg_PI_M_MODE_B[4]= {_BIT28, _BIT20, _BIT12, _BIT4};
	unsigned char i, mode;
	volatile unsigned int val = 0;


	if (nport > 0) {
		HDMI_EMG("[ERROR] ONLY SUPPORT PORT0, (port=%d)\n", nport);
		return;
	}


	hdmi_mask(DFE_HDMI_RX_PHY_RST_reg, ~(DFE_HDMI_RX_PHY_RST_reg_p0_acdr_rstb_fsm_mask<<nport), 0);
	hdmi_mask(reg_acdr1[nport], ~(p0_REG_ACDR_CKFLD_EN|p0_REG_ACDR_EN|p0_REG_ACDR_TOP_EN), 0);

	if (enable) {
		for (mode=0; mode<5; mode++) {
			if (acdr_table[mode].b_upper > b && acdr_table[mode].b_lower <= b) {
				break;
			}
		}
		if (mode > 4) {
			HDMI_EMG("[ERROR] can not find acdr table(b=%d)\n", b);
			return;
		}
		HDMI_PRINTF("ACDR table=%d\n", mode);


		hdmi_mask(reg_fld1[nport], ~(DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit_mask|DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit_mask), (DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit(acdr_table[mode].lock_up_limit)|DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit(acdr_table[mode].lock_dn_limit)));
		hdmi_mask(reg_fld2[nport], ~(DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp_mask), (DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp(0xAAAA0|acdr_table[mode].cdr_bw_icp)));
		hdmi_mask(reg_acdr1[nport], ~(p0_REG_ACDR_VCOGAIN|p0_REG_ACDR_LFRS_SEL|p0_REG_ACDR_HR_PD),
			(acdr_table[mode].vcogain<<20)|(acdr_table[mode].lfrs_sel<<13)|(acdr_table[mode].hr_pd<<4));
		hdmi_mask(reg_rgb3[nport][2], ~(P0_b_11_ACDR_RATE_SEL_HALF_RATE), (acdr_table[mode].rate_sel<<16));

		hdmi_mask(reg_acdr1[nport], ~(p0_REG_ACDR_CPCVM_EN|p0_REG_ACDR_CKFLD_EN), (p0_REG_ACDR_CKFLD_EN));
		hdmi_out(reg_acdr2[nport], 0x0000DB8A); /* directly from Edward, spec is not define [15:14][7] */
		hdmi_mask(reg_fld0[nport], ~DFE_HDMI_RX_PHY_REGD28_reg_p0_auto_mode_mask, DFE_HDMI_RX_PHY_REGD28_reg_p0_auto_mode_mask);   /* auto mode k band*/
		hdmi_mask(reg_fld5[nport], ~DFE_HDMI_RX_PHY_REGD33_reg_p0_old_mode_mask, DFE_HDMI_RX_PHY_REGD33_reg_p0_old_mode_mask);

		hdmi_mask(reg_wdog[nport], ~DFE_HDMI_RX_PHY_REGD20_reg_p0_acdr_l0_en_mask, DFE_HDMI_RX_PHY_REGD20_reg_p0_acdr_l0_en_mask);
		hdmi_mask(reg_ck1[nport], ~(p0_ck_2_CMU_CKIN_SEL|p0_CMU_CKOUT_SEL), (0xC<<12)|p0_CMU_CKOUT_SEL);
		hdmi_mask(reg_rgb2[nport][2], ~P0_b_8_BY_PASS_PR, P0_b_8_BY_PASS_PR);
		//hdmi_mask(g2, ~ACDR_CLK_SEL, 0);
		//hdmi_mask(r2, ~ACDR_CLK_SEL, 0);
		hdmi_mask(DFE_HDMI_RX_PHY_REGD64_reg, ~reg_PI_M_MODE_B[nport], reg_PI_M_MODE_B[nport]);

		hdmi_out(reg_st_m_value_b[nport], 0xFF000000);

		hdmi_mask(reg_rgb1[nport][2], ~P0_b_DEMUX_BBPD_RSTB, P0_b_DEMUX_BBPD_RSTB);
		hdmi_mask(reg_rgb1[nport][1], ~P0_g_DEMUX_BBPD_RSTB, P0_g_DEMUX_BBPD_RSTB);
		hdmi_mask(reg_rgb1[nport][0], ~P0_r_DEMUX_BBPD_RSTB, P0_r_DEMUX_BBPD_RSTB);

		for (i = 0; i < 5; i++) {
			hdmi_mask(reg_acdr1[nport], ~p0_REG_ACDR_TOP_EN, p0_REG_ACDR_TOP_EN);
			hdmi_mask(reg_acdr1[nport], ~p0_REG_ACDR_EN, p0_REG_ACDR_EN);
			hdmi_mask(DFE_HDMI_RX_PHY_RST_reg, ~(DFE_HDMI_RX_PHY_RST_reg_p0_acdr_rstb_fsm_mask<<nport), (DFE_HDMI_RX_PHY_RST_reg_p0_acdr_rstb_fsm_mask<<nport));

			msleep(1); /*need delay for DFE*/

			if (lib_hdmi_acdr_check_result(nport)) {
				break;
			}

			val = hdmi_in(reg_fld6[nport]);

			if ((DFE_HDMI_RX_PHY_REGD34_get_p0_cp_en_fsm_reg(val) == 0) && (DFE_HDMI_RX_PHY_REGD34_get_p0_coarse_fsm_reg(val) == 0x7f)) {
				hdmi_mask(reg_acdr1[nport], ~p0_REG_ACDR_VCO_TUNER, 2<<22);
			} else if ((DFE_HDMI_RX_PHY_REGD34_get_p0_cp_en_fsm_reg(val) == 0) && (DFE_HDMI_RX_PHY_REGD34_get_p0_coarse_fsm_reg(val) == 0)) {
				hdmi_mask(reg_acdr1[nport], ~p0_REG_ACDR_VCO_TUNER, 1<<22);
			} else {
				hdmi_mask(reg_acdr1[nport], ~p0_REG_ACDR_VCO_TUNER, 0<<22);
			}

			hdmi_mask(reg_acdr1[nport], ~p0_REG_ACDR_TOP_EN, 0);
			hdmi_mask(reg_acdr1[nport], ~p0_REG_ACDR_EN, 0);
			hdmi_mask(DFE_HDMI_RX_PHY_RST_reg, ~(DFE_HDMI_RX_PHY_RST_reg_p0_acdr_rstb_fsm_mask<<nport), 0);

			msleep(1);
		}

	} else {
		hdmi_mask(reg_fld1[nport],~(DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit_mask|DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit_mask), (DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_up_limit(0x462)|DFE_HDMI_RX_PHY_REGD29_reg_p0_lock_dn_limit(0x44e)));
		hdmi_mask(reg_fld2[nport], ~(DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp_mask), (DFE_HDMI_RX_PHY_REGD30_reg_p0_cdr_cp(0x44332)));
		hdmi_mask(reg_acdr1[nport], ~(p0_REG_ACDR_VCOGAIN|p0_REG_ACDR_LFRS_SEL|p0_REG_ACDR_HR_PD),
			(1<<20)|(4<<13)|p0_REG_ACDR_HR_PD);
		hdmi_mask(reg_rgb3[nport][2], ~(P0_b_11_ACDR_RATE_SEL_HALF_RATE), (P0_b_11_ACDR_RATE_SEL_HALF_RATE));

		hdmi_mask(reg_fld0[nport], ~DFE_HDMI_RX_PHY_REGD28_reg_p0_auto_mode_mask, 0);   /* auto mode k band*/
		hdmi_mask(reg_fld5[nport], ~DFE_HDMI_RX_PHY_REGD33_reg_p0_old_mode_mask, 0);
		hdmi_mask(reg_wdog[nport], ~DFE_HDMI_RX_PHY_REGD20_reg_p0_acdr_l0_en_mask, 0);
		hdmi_mask(reg_ck1[nport], ~(p0_ck_2_CMU_CKIN_SEL|p0_CMU_CKOUT_SEL), (0xE<<12));
		hdmi_mask(reg_rgb2[nport][2], ~P0_b_8_BY_PASS_PR, 0);
		hdmi_mask(DFE_HDMI_RX_PHY_REGD64_reg, ~reg_PI_M_MODE_B[nport], 0);

		hdmi_out(reg_st_m_value_b[nport], 0);

		hdmi_mask(reg_rgb1[nport][2], ~P0_b_DEMUX_BBPD_RSTB, 0);
		hdmi_mask(reg_rgb1[nport][1], ~P0_g_DEMUX_BBPD_RSTB, 0);
		hdmi_mask(reg_rgb1[nport][0], ~P0_r_DEMUX_BBPD_RSTB, 0);

	}
#endif

}

void lib_hdmi_fg_koffset_manual_adjust(unsigned char nport, unsigned int r, unsigned int g, unsigned int b)
{
	if (nport >= HDMI_PHY_TOTAL_NUM) {
		return;
	}

	hdmiport_mask(RX_PHY_B1_reg, ~(P0_b_1_FORE_KOFF_ADJR), r<<16);
	hdmiport_mask(RX_PHY_G1_reg, ~(P0_b_1_FORE_KOFF_ADJR), g<<16);
	hdmiport_mask(RX_PHY_R1_reg, ~(P0_b_1_FORE_KOFF_ADJR), b<<16);

	hdmiport_mask(RX_PHY_B1_reg, ~(P0_b_3_FORE_EN_FORE_KOFF),P0_b_3_FORE_EN_FORE_KOFF);
	hdmiport_mask(RX_PHY_G1_reg, ~(P0_b_3_FORE_EN_FORE_KOFF),P0_b_3_FORE_EN_FORE_KOFF);
	hdmiport_mask(RX_PHY_R1_reg, ~(P0_b_3_FORE_EN_FORE_KOFF),P0_b_3_FORE_EN_FORE_KOFF);
	
}

void lib_hdmi_fg_koffset_manual(unsigned char nport)
{
	if (nport >= HDMI_PHY_TOTAL_NUM) {
		return;
	}

  	hdmi_mask(RX_PHY_B1_reg, ~(P0_r_4_FORE_KOFF_AUTOK), 0);
  	hdmi_mask(RX_PHY_G1_reg, ~(P0_g_4_FORE_KOFF_AUTOK), 0);
	hdmi_mask(RX_PHY_R1_reg, ~(P0_b_4_FORE_KOFF_AUTOK), 0);
}

void lib_hdmi_fg_koffset_auto(unsigned char nport)
{
#define FORE_KOFF_RANGE  0  // range maybe 0  1  2   3
	UINT8 i, k_cnt;
	volatile u_int32_t koff_r_result ;
	volatile u_int32_t  koff_g_result;
	volatile u_int32_t  koff_b_result;


	// initial circuit power
	hdmi_mask(RX_PHY_B1_reg, ~(P0_b_3_FORE_EN_FORE_KOFF|P0_b_4_FORE_KOFF_AUTOK|P0_b_4_FORE_POW_FORE_KOFF),(P0_b_3_FORE_EN_FORE_KOFF|P0_b_4_FORE_KOFF_AUTOK));
	hdmi_mask(RX_PHY_G1_reg, ~(P0_b_3_FORE_EN_FORE_KOFF|P0_b_4_FORE_KOFF_AUTOK|P0_b_4_FORE_POW_FORE_KOFF),(P0_b_3_FORE_EN_FORE_KOFF|P0_b_4_FORE_KOFF_AUTOK));
	hdmi_mask(RX_PHY_R1_reg, ~(P0_b_3_FORE_EN_FORE_KOFF|P0_b_4_FORE_KOFF_AUTOK|P0_b_4_FORE_POW_FORE_KOFF),(P0_b_3_FORE_EN_FORE_KOFF|P0_b_4_FORE_KOFF_AUTOK));
	// cut input off
	hdmi_mask(RX_PHY_B1_reg, ~(P0_b_1_inputoff),P0_b_1_inputoff);
	hdmi_mask(RX_PHY_G1_reg, ~(P0_b_1_inputoff),P0_b_1_inputoff);
	hdmi_mask(RX_PHY_R1_reg, ~(P0_b_1_inputoff),P0_b_1_inputoff);


	//for b lane
	for (i=0; i<FORE_KOFF_RANGE+1; i++) {
		hdmi_mask(RX_PHY_B1_reg, ~(P0_b_4_FORE_POW_FORE_KOFF),0);

		//set k off range
		hdmi_mask(RX_PHY_B1_reg, ~(P0_b_1_FORE_KOFF_RANGE),i<<21);

		// start cal
		hdmi_mask(RX_PHY_B1_reg, ~(P0_b_4_FORE_POW_FORE_KOFF),P0_b_4_FORE_POW_FORE_KOFF);

		//wait finish cal
		k_cnt = 100;
		while (!((hdmi_in(RX_PHY_B4_reg))&DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koffok_mask) && --k_cnt) {
			udelay(10);
		}

		if (!k_cnt) {
			HDMI_EMG("[ERROR] %s: func err(B)\n", __func__);
		}

		koff_b_result = DFE_HDMI_RX_PHY_P0_B4_get_reg_p0_b_koff_sel(hdmi_in(RX_PHY_B4_reg));

		if (!(hdmi_in(RX_PHY_B4_reg) & DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koff_bound_mask)) {
			//HDMI_PRINTF("[HDMI] R channel foreground K Off result   %x  range =%x \n",koff_b_result,i);
			break;
		} else {
			HDMI_EMG("[ERROR] %s: out of B range\n", __func__);
		}
	}


	//for g lane
	for (i=0; i<FORE_KOFF_RANGE+1; i++) {
		hdmi_mask(RX_PHY_G1_reg, ~(P0_b_4_FORE_POW_FORE_KOFF),0);

		//set k off range
		hdmi_mask(RX_PHY_G1_reg, ~(P0_b_1_FORE_KOFF_RANGE),i<<21);

		// start cal
		hdmi_mask(RX_PHY_G1_reg, ~(P0_b_4_FORE_POW_FORE_KOFF),P0_b_4_FORE_POW_FORE_KOFF);

		//wait finish cal
		k_cnt = 100;
		while (!((hdmi_in(RX_PHY_G4_reg))&DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koffok_mask) && --k_cnt) {
			udelay(10);
		}

		if (!k_cnt) {
			HDMI_EMG("[ERROR] %s: func err(G)\n", __func__);
		}

		koff_g_result = DFE_HDMI_RX_PHY_P0_B4_get_reg_p0_b_koff_sel(hdmi_in(RX_PHY_G4_reg));

		if (!(hdmi_in(RX_PHY_G4_reg) & DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koff_bound_mask)) {
			break;
		} else {
			HDMI_EMG("[ERROR] %s: out of G range\n", __func__);
		}
	}


	//for r lane
	for (i=0; i<FORE_KOFF_RANGE+1; i++) {
		hdmi_mask(RX_PHY_R1_reg, ~(P0_b_4_FORE_POW_FORE_KOFF),0);

		//set k off range
		hdmi_mask(RX_PHY_R1_reg, ~(P0_b_1_FORE_KOFF_RANGE),i<<21);

		// start cal
		hdmi_mask(RX_PHY_R1_reg, ~(P0_b_4_FORE_POW_FORE_KOFF),P0_b_4_FORE_POW_FORE_KOFF);

		//wait finish cal
		k_cnt = 100;
		while(!((hdmi_in(RX_PHY_R4_reg))&DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koffok_mask) && --k_cnt) {
			udelay(10);
		}

		if (!k_cnt) {
			HDMI_EMG("[ERROR] %s: func err(R)\n", __func__);
		}

		koff_r_result = DFE_HDMI_RX_PHY_P0_B4_get_reg_p0_b_koff_sel(hdmi_in(RX_PHY_R4_reg));

		if (!(hdmi_in(RX_PHY_R4_reg) & DFE_HDMI_RX_PHY_P0_B4_reg_p0_b_koff_bound_mask)) {
			break;
		} else {
			HDMI_EMG("[ERROR] %s: out of R range\n", __func__);
		}
	}

	// cut input on
	hdmi_mask(RX_PHY_B1_reg, ~(P0_b_1_inputoff),0);
	hdmi_mask(RX_PHY_G1_reg, ~(P0_b_1_inputoff),0);
	hdmi_mask(RX_PHY_R1_reg, ~(P0_b_1_inputoff),0);

	HDMI_PRINTF("FG KOFFSET(b,g,r)=(%d,%d,%d)\n", koff_b_result,koff_g_result,koff_r_result);

}

void lib_hdmi_fg_koffset_proc(unsigned char nport)
{
#if 0 // MHL_SUPPORT
	if ((nport==MHL_CHANNEL) && CBUS_PMM_CBUS_PHY_4_get_en_cbus_rx(hdmi_in(CBUS_PMM_CBUS_PHY_4_reg)))
	{
		lib_hdmi_fg_koffset_manual_adjust(nport, 0x10, 0x10, 0x10);
		lib_hdmi_fg_koffset_manual(nport);
	}
	else
#endif
	{
		lib_hdmi_fg_koffset_auto(nport);
		lib_hdmi_cdr_rst(nport, 1);
		udelay(5);
		lib_hdmi_cdr_rst(nport, 0);
		udelay(50);
	}
}

void lib_hdmi_fg_koffset_disable(unsigned char nport)
{
	hdmi_mask(RX_PHY_B1_reg, ~(P0_b_3_FORE_EN_FORE_KOFF|P0_b_4_FORE_POW_FORE_KOFF|P0_b_4_FORE_KOFF_AUTOK), 0);
	hdmi_mask(RX_PHY_G1_reg, ~(P0_b_3_FORE_EN_FORE_KOFF|P0_b_4_FORE_POW_FORE_KOFF|P0_b_4_FORE_KOFF_AUTOK), 0);
	hdmi_mask(RX_PHY_R1_reg, ~(P0_b_3_FORE_EN_FORE_KOFF|P0_b_4_FORE_POW_FORE_KOFF|P0_b_4_FORE_KOFF_AUTOK), 0);

}


//port0_z0=b803814c[4:0]   port0_done=b803814c[5]
//port1_z0=b803814c[10:6]  port1_done=b803814c[11]
//port2_z0=b803814c[16:12] port2_done=b803814c[17]

// OTP field name : double_HDMI_Z0
// OTP bit : [3313:3296]: 18bits
// Rbus addr : 0x1803819C[17:0]
//port0_z0=b803819c[4:0]   done0_done=b803819c[5]
//port1_z0=b803819c[10:6]  done1_done=b803819c[11]
//port2_z0=b803819c[16:12] done2_done=b803819c[17]

void lib_hdmi_z0_calibration(void)
{
	 #define Z0_DIFF_ERR		0x0
	 #define Z0_OTP_ALL_PORT_DONE		(_BIT5|_BIT11|_BIT17)

	 unsigned char z0_0, z0_1,z0_2;    //z0 for 3 port
	 unsigned char z0_low_bound_0,z0_low_bound_1,z0_low_bound_2;     //  85 -- 100 -- 115  +-15%
	 unsigned char z0_high_bound_0,z0_high_bound_1, z0_high_bound_2;   //high boundary z0 for 3 port
	 unsigned char ext_trace_z0_0,  ext_trace_z0_1, ext_trace_z0_2;  //external z0 for 3 port
	 unsigned char soc_z0 = PHY_Z0;
	 unsigned char target_z0_0, target_z0_1,target_z0_2;     // target_z0 = soc_z0 + pcb_trace_z0  (target z0 for 3 port)
	 unsigned long long val = 0;   	 
	 
        unsigned char z0_otp_done;
        unsigned int z0_otp_value;

	ext_trace_z0_0 = ext_trace_z0_1 = ext_trace_z0_2 = 0x5 - Z0_DIFF_ERR;  // 1 step 1.5 ohm  5.4 ohm = 4 step

	if ((rtd_inl(EFUSE_DATAO_83_reg) & (Z0_OTP_ALL_PORT_DONE)) == Z0_OTP_ALL_PORT_DONE) {
		z0_otp_done = 0x7;
		z0_otp_value = rtd_inl(EFUSE_DATAO_83_reg);
	} else if ((rtd_inl(EFUSE_DATAO_103_reg) & Z0_OTP_ALL_PORT_DONE) == Z0_OTP_ALL_PORT_DONE) {
		z0_otp_done = 0x7;
		z0_otp_value = rtd_inl(EFUSE_DATAO_103_reg);
	}
	else {
		z0_otp_done = 0;
		z0_otp_value = 0;
	}	


	HDMI_PRINTF("z0_otp_done=%x, z0_otp_value=%x\n",z0_otp_done, z0_otp_value);
 	 

	  if (pcb_mgr_get_enum_info_byname("HDMI_EXT_Z0_CFG", &val)==0) {
		ext_trace_z0_0 = (val & 0x000000FF)- Z0_DIFF_ERR;
		ext_trace_z0_1 = ((val & 0x0000FF00) >> 8) - Z0_DIFF_ERR;
		ext_trace_z0_2 = ((val & 0x00FF0000) >> 16) - Z0_DIFF_ERR;
	  } else {
			HDMI_PRINTF("NOT GET  EXTERNAL PCB TRACE Z0\n");
	  }
	  

	HDMI_PRINTF("soc_z0=%x  p0_ext_trace_z0=%x  p1_ext_trace_z0=%x  p2_ext_trace_z0=%x\n",soc_z0, ext_trace_z0_0,ext_trace_z0_1,ext_trace_z0_2);
	
	 target_z0_0 = soc_z0 + ext_trace_z0_0;
	 target_z0_1 = soc_z0 + ext_trace_z0_1;
	 target_z0_2 = soc_z0 + ext_trace_z0_2;
	 
	 z0_high_bound_0 = target_z0_0 + 10;
	 z0_high_bound_1 = target_z0_1 + 10;
	 z0_high_bound_2 = target_z0_2 + 10;
	 

	 if (target_z0_0 > 6)
	 	z0_low_bound_0 = target_z0_0 - 6;
	 else {
		z0_low_bound_0 = 0;
	 }

	 if (target_z0_1 > 6)
	 	z0_low_bound_1 = target_z0_1 - 6;
	 else {
		z0_low_bound_1 = 0;
	 }
	 

	 if (target_z0_2 > 6)
	 	z0_low_bound_2 = target_z0_2 - 6;
	 else {
		z0_low_bound_2 = 0;
	 }


	HDMI_PRINTF("Z0 OTP done_bit=%x value=%x\n",z0_otp_done,z0_otp_value);

	
	
        if (z0_otp_done & 0x1) {
                z0_0 = z0_otp_value & 0x0000001F;
		  z0_0 = z0_0 + ext_trace_z0_0;
		  if ((z0_0 < z0_low_bound_0) || (z0_0 > z0_high_bound_0)) {
		        z0_0 = target_z0_0;
			 HDMI_PRINTF("port0 z0 otp over boundary\n");
		  }
        }
        else
                z0_0 = target_z0_0;

        if (z0_otp_done & 0x2) {
                z0_1 = (z0_otp_value & 0x000007C0) >> 6;
		  z0_1 = z0_1 + ext_trace_z0_1;
		  if ((z0_1 < z0_low_bound_1) || (z0_1 > z0_high_bound_1)) {
			 z0_1 = target_z0_1;
			 HDMI_PRINTF("port1 z0 otp over boundary\n");
		  }
        }
        else
                z0_1 = target_z0_1;

        if (z0_otp_done & 0x4) {
                z0_2 = (z0_otp_value & 0x0001F000) >> 12;
		  z0_2 = z0_2 + ext_trace_z0_2;
		  if ((z0_2 < z0_low_bound_2) || (z0_2 > z0_high_bound_2)) {
			  z0_2 = target_z0_2;
			   HDMI_PRINTF("port2 z0 otp over boundary\n");
		  }
        }
        else
                z0_2 = target_z0_2;


	HDMI_PRINTF("z0_0=%x z0_1=%x z0_2=%x\n",z0_0,z0_1,z0_2);


	//mac5 none hdmiport_mask(DFE_HDMI_RX_PHY_Z0K_reg, ~(DFE_HDMI_RX_PHY_Z0K_reg_z0_z0pow_mask|DFE_HDMI_RX_PHY_Z0K_reg_z0_stune_mask), 0);
	hdmiport_mask(DFE_HDMI_RX_PHY_P0_Z0K_reg, ~(DFE_HDMI_RX_PHY_P0_Z0K_reg_z0_adjr_0_mask), DFE_HDMI_RX_PHY_P0_Z0K_reg_z0_adjr_0(z0_0));
	hdmiport_mask(DFE_HDMI_RX_PHY_P1_Z0K_reg, ~(DFE_HDMI_RX_PHY_P1_Z0K_reg_z0_adjr_1_mask), DFE_HDMI_RX_PHY_P1_Z0K_reg_z0_adjr_1(z0_1));
	hdmiport_mask(DFE_HDMI_RX_PHY_P2_Z0K_reg, ~(DFE_HDMI_RX_PHY_P2_Z0K_reg_z0_adjr_2_mask), DFE_HDMI_RX_PHY_P2_Z0K_reg_z0_adjr_2(z0_2));


}


void lib_hdmi_char_err_rst(unsigned char nport, unsigned char rst)
{
	if (rst) {
		hdmiport_mask(HDMI_CERCR_reg, ~(HDMI_CERCR_en_mask), 0);
		hdmiport_mask(HDMI_CERCR_reg,
			~(HDMI_CERCR_reset_err_det_mask|HDMI_CERCR_reset_mask),
			(HDMI_CERCR_reset_err_det_mask|HDMI_CERCR_reset_mask));
	} else {
		hdmiport_mask(HDMI_CERCR_reg,
			~(HDMI_CERCR_valid_reset_mask|HDMI_CERCR_reset_err_det_mask|HDMI_CERCR_reset_mask),
			0);
	}
}

void lib_hdmi_char_err_start(unsigned char nport, unsigned char conti_mode, unsigned char period)
{
	hdmiport_mask(HDMI_CERCR_reg, ~(HDMI_CERCR_en_mask), 0);

	hdmiport_mask(HDMI_CERCR_reg,~(HDMI_CERCR_ch_locked_reset_mask|HDMI_CERCR_reset_mask), (HDMI_CERCR_ch_locked_reset_mask|HDMI_CERCR_reset_mask));
	hdmiport_mask(HDMI_CERCR_reg,~(HDMI_CERCR_reset_err_det_mask|HDMI_CERCR_keep_err_det_mask),(HDMI_CERCR_reset_err_det_mask|HDMI_CERCR_keep_err_det_mask));

	hdmiport_mask(HDMI_CERCR_reg,~(HDMI_CERCR_period_mask|HDMI_CERCR_mode_mask), HDMI_CERCR_period(period)|HDMI_CERCR_mode(conti_mode));

	hdmiport_mask(HDMI_CERCR_reg,~(HDMI_CERCR_ch_locked_reset_mask|HDMI_CERCR_reset_mask),0);
	hdmiport_mask(HDMI_CERCR_reg,~(HDMI_CERCR_reset_err_det_mask|HDMI_CERCR_keep_err_det_mask),0);

	hdmiport_mask(HDMI_CERCR_reg,~(HDMI_CERCR_refer_implem_mask), HDMI_CERCR_refer_implem_mask);

	hdmiport_mask(HDMI_CERCR_reg, ~(HDMI_CERCR_en_mask), HDMI_CERCR_en_mask);
}

unsigned char lib_hdmi_char_err_det_done(unsigned char nport)
{
	return (!HDMI_CERCR_get_en(hdmi_in(HDMI_CERCR_reg)));
}

unsigned char lib_hdmi_char_err_get_error(unsigned char nport, unsigned int *r_err, unsigned int *g_err, unsigned int *b_err)
{
	if (HDMI_CERCR_get_en(hdmi_in(HDMI_CERCR_reg)) &&
		(!HDMI_CERCR_get_ch0_over_max_err_num(hdmi_in(HDMI_CERCR_reg)) &&
		!HDMI_CERCR_get_ch1_over_max_err_num(hdmi_in(HDMI_CERCR_reg)) &&
		!HDMI_CERCR_get_ch2_over_max_err_num(hdmi_in(HDMI_CERCR_reg)))) {
		return 0;	//not yet finish counting
	}

	*b_err = HDMI_CERSR0_get_err_cnt0_video(hdmi_in(HDMI_CERSR0_reg));
	*g_err = HDMI_CERSR0_get_err_cnt1_video(hdmi_in(HDMI_CERSR0_reg));
	*r_err = HDMI_CERSR1_get_err_cnt2_video(hdmi_in(HDMI_CERSR1_reg));

	return 1;
}

void lib_hdmi_bit_err_start(unsigned char nport, unsigned char conti_mode, unsigned char period)
{
	hdmiport_mask(HDMI_VIDEO_BIT_ERR_DET_reg, ~HDMI_VIDEO_BIT_ERR_DET_en_mask, 0); // disable
	hdmiport_mask(HDMI_VIDEO_BIT_ERR_DET_reg, ~HDMI_VIDEO_BIT_ERR_DET_reset_mask, HDMI_VIDEO_BIT_ERR_DET_reset_mask); //reset cnt

	hdmiport_mask(HDMI_VIDEO_BIT_ERR_DET_reg, ~HDMI_VIDEO_BIT_ERR_DET_mode_mask, HDMI_VIDEO_BIT_ERR_DET_mode(conti_mode));
	hdmiport_mask(HDMI_VIDEO_BIT_ERR_DET_reg, ~HDMI_VIDEO_BIT_ERR_DET_period_mask, HDMI_VIDEO_BIT_ERR_DET_period(period));
	hdmiport_mask(HDMI_VIDEO_BIT_ERR_DET_reg, ~HDMI_VIDEO_BIT_ERR_DET_thd_mask, HDMI_VIDEO_BIT_ERR_DET_thd(1)); //thd

	hdmiport_mask(HDMI_VIDEO_BIT_ERR_DET_reg, ~HDMI_VIDEO_BIT_ERR_DET_reset_mask, 0);

	hdmiport_mask(HDMI_VIDEO_BIT_ERR_STATUS_B_reg, 	//wclr_out
	              ~(HDMI_VIDEO_BIT_ERR_STATUS_B_no_dis_reset_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_thd_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_of_b_mask),
	              (HDMI_VIDEO_BIT_ERR_STATUS_B_no_dis_reset_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_thd_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_of_b_mask));

	hdmiport_mask(HDMI_VIDEO_BIT_ERR_STATUS_G_reg, 	//wclr_out
	              ~(HDMI_VIDEO_BIT_ERR_STATUS_B_no_dis_reset_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_thd_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_of_b_mask),
	              (HDMI_VIDEO_BIT_ERR_STATUS_B_no_dis_reset_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_thd_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_of_b_mask));

	hdmiport_mask(HDMI_VIDEO_BIT_ERR_STATUS_R_reg, 	//wclr_out
	              ~(HDMI_VIDEO_BIT_ERR_STATUS_B_no_dis_reset_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_thd_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_of_b_mask),
	              (HDMI_VIDEO_BIT_ERR_STATUS_B_no_dis_reset_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_thd_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_b_mask|HDMI_VIDEO_BIT_ERR_STATUS_B_bit_err_cnt_of_b_mask));

	hdmiport_mask(HDMI_VIDEO_BIT_ERR_DET_reg, ~HDMI_VIDEO_BIT_ERR_DET_en_mask, HDMI_VIDEO_BIT_ERR_DET_en_mask);
}

unsigned char lib_hdmi_bit_err_det_done(unsigned char nport)
{
	return (!HDMI_VIDEO_BIT_ERR_DET_get_en(hdmi_in(HDMI_VIDEO_BIT_ERR_DET_reg)));
}

unsigned char lib_hdmi_bit_err_get_error(unsigned char nport, unsigned int *r_err, unsigned int *g_err, unsigned int *b_err)
{
	if (HDMI_VIDEO_BIT_ERR_DET_get_en(hdmi_in(HDMI_VIDEO_BIT_ERR_DET_reg))) {
		return 0;	//not yet finish counting
	}

	*r_err = HDMI_VIDEO_BIT_ERR_STATUS_R_get_bit_err_cnt_r(hdmi_in(HDMI_VIDEO_BIT_ERR_STATUS_R_reg));
	*g_err = HDMI_VIDEO_BIT_ERR_STATUS_G_get_bit_err_cnt_g(hdmi_in(HDMI_VIDEO_BIT_ERR_STATUS_G_reg));
	*b_err = HDMI_VIDEO_BIT_ERR_STATUS_B_get_bit_err_cnt_b(hdmi_in(HDMI_VIDEO_BIT_ERR_STATUS_B_reg));

	return 1;
}

#if 0
void lib_hdmi_single_end(unsigned char nport, unsigned char channel, unsigned char p_off, unsigned char n_off)
{
// channel = 0(R), 1(G), 2(B)
	hdmiport_mask(reg_rgb1[nport][channel], ~(P0_b_1_inputoff_p), p_off<<2);
	hdmiport_mask(reg_rgb1[nport][channel], ~(P0_b_1_inputoff_n), n_off<<2);
}
#endif


#if BIST_DFE_SCAN
//--------------------------------------------------------------------------
//
//	Debug Functions, not release.
//
//--------------------------------------------------------------------------
void debug_hdmi_dfe_scan(unsigned char nport)
{
	signed char dfe_arg;
	unsigned int bit_r_err, bit_g_err, bit_b_err, ch_r_err, ch_g_err, ch_b_err;

//	hdmi_mask(DEBUG_REG_ADDR, ~DEBUG_29_BYPASS_PHY_ISR, DEBUG_29_BYPASS_PHY_ISR);
	hdmi_mask(DEBUG_REG_ADDR, ~DEBUG_28_BYPASS_DETECT, DEBUG_28_BYPASS_DETECT);
	hdmi_mask(DEBUG_REG_ADDR, ~DEBUG_27_BYPASS_CHECK, DEBUG_27_BYPASS_CHECK);


	for (dfe_arg=0; dfe_arg<0x24; dfe_arg++) {
		lib_hdmi_dfe_init_tap0(nport, (LN_R|LN_G|LN_B), dfe_arg);
		//lib_hdmi_dfe_init_tap1(nport, (LN_R|LN_G|LN_B), dfe_arg);
		//lib_hdmi_dfe_init_tap2(nport, (LN_R|LN_G|LN_B), dfe_arg);
		udelay(100);

		lib_hdmi_bit_err_start(nport, 0, 10);
		lib_hdmi_char_err_start(nport, 0, 10);

		while (!lib_hdmi_bit_err_get_error(nport, &bit_r_err, &bit_g_err, &bit_b_err)) {
			msleep(20);
		}
		while (!lib_hdmi_char_err_get_error(nport, &ch_r_err, &ch_g_err, &ch_b_err)) {
			msleep(20);
		}

		HDMI_EMG("tap0=%02d, [CH](%05d, %05d, %05d); [BIT](%05d, %05d, %05d)\n",
			dfe_arg, ch_r_err, ch_g_err, ch_b_err, bit_r_err, bit_g_err, bit_b_err);
	}

	lib_hdmi_dfe_init_tap0(nport, (LN_B), phy_st[nport].dfe_t[0].tap0);
	lib_hdmi_dfe_init_tap0(nport, (LN_G), phy_st[nport].dfe_t[1].tap0);
	lib_hdmi_dfe_init_tap0(nport, (LN_R), phy_st[nport].dfe_t[2].tap0);

	for (dfe_arg=0; dfe_arg<60; dfe_arg++) {
		//lib_hdmi_dfe_init_tap0(nport, (LN_R|LN_G|LN_B), dfe_arg);
		lib_hdmi_dfe_init_tap1(nport, (LN_R|LN_G|LN_B), dfe_arg);
		//lib_hdmi_dfe_init_tap2(nport, (LN_R|LN_G|LN_B), dfe_arg);
		udelay(100);

		lib_hdmi_bit_err_start(nport, 0, 10);
		lib_hdmi_char_err_start(nport, 0, 10);

		while (!lib_hdmi_bit_err_get_error(nport, &bit_r_err, &bit_g_err, &bit_b_err)) {
			msleep(20);
		}
		while (!lib_hdmi_char_err_get_error(nport, &ch_r_err, &ch_g_err, &ch_b_err)) {
			msleep(20);
		}

		HDMI_EMG("le=%02d, [CH](%05d, %05d, %05d); [BIT](%05d, %05d, %05d)\n",
			dfe_arg, ch_r_err, ch_g_err, ch_b_err, bit_r_err, bit_g_err, bit_b_err);
	}

	lib_hdmi_dfe_init_tap1(nport, (LN_B), phy_st[nport].dfe_t[0].tap1+phy_st[nport].dfe_t[0].le);
	lib_hdmi_dfe_init_tap1(nport, (LN_G), phy_st[nport].dfe_t[1].tap1+phy_st[nport].dfe_t[1].le);
	lib_hdmi_dfe_init_tap1(nport, (LN_R), phy_st[nport].dfe_t[2].tap1+phy_st[nport].dfe_t[2].le);





	for (dfe_arg=-15; dfe_arg<15; dfe_arg++) {
		//lib_hdmi_dfe_init_tap0(nport, (LN_R|LN_G|LN_B), dfe_arg);
		//lib_hdmi_dfe_init_tap1(nport, (LN_R|LN_G|LN_B), dfe_arg);
		lib_hdmi_dfe_init_tap2(nport, (LN_R|LN_G|LN_B), dfe_arg);
		udelay(100);

		lib_hdmi_bit_err_start(nport, 0, 10);
		lib_hdmi_char_err_start(nport, 0, 10);

		while (!lib_hdmi_bit_err_get_error(nport, &bit_r_err, &bit_g_err, &bit_b_err)) {
			msleep(20);
		}
		while (!lib_hdmi_char_err_get_error(nport, &ch_r_err, &ch_g_err, &ch_b_err)) {
			msleep(20);
		}

		HDMI_EMG("tap2=%02d, [CH](%05d, %05d, %05d); [BIT](%05d, %05d, %05d)\n",
			dfe_arg, ch_r_err, ch_g_err, ch_b_err, bit_r_err, bit_g_err, bit_b_err);
	}

	lib_hdmi_dfe_init_tap2(nport, (LN_B), phy_st[nport].dfe_t[0].tap2);
	lib_hdmi_dfe_init_tap2(nport, (LN_G), phy_st[nport].dfe_t[1].tap2);
	lib_hdmi_dfe_init_tap2(nport, (LN_R), phy_st[nport].dfe_t[2].tap2);



//	hdmi_mask(DEBUG_REG_ADDR, ~DEBUG_29_BYPASS_PHY_ISR, 0);
	hdmi_mask(DEBUG_REG_ADDR, ~DEBUG_28_BYPASS_DETECT, 0);
	hdmi_mask(DEBUG_REG_ADDR, ~DEBUG_27_BYPASS_CHECK, 0);

}
#endif
