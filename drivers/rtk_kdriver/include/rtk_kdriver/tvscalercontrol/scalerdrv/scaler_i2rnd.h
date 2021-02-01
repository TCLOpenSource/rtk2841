/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for scaler clock related functions.
 *
 * @author 	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	clock
 */

/**
 * @addtogroup clock
 * @{
 */

#ifndef _SCALER_I2RND_H_
#define _SCALER_I2RND_H_

#ifdef __cplusplus
extern "C" {
#endif

/*============================ Module dependency  ===========================*/

/*===================================  Types ================================*/

/*================================== Variables ==============================*/

/*================================ Definitions ==============================*/
////////////////////////
/*B05 I2RND_REGISTER_NUMBER */
#define I2RND_B05_CMD_NUMBER 0 //hw setting + 1
#define I2RND_B05_DMA_LENGTH 16
#define I2RND_B05_DMA_WATERLEVEL 96
#define I2RND_b05_REGISTER_NUMBER (17*17*40+5)
#define I2RND_b05_BLOCK_SIZE ((I2RND_b05_REGISTER_NUMBER + ((I2RND_b05_REGISTER_NUMBER%2) ? 1 : 0)) / 2 * 16) //queue size(total block size) = (regisrer num/2) * 128bits = (regisrer num/2) * 16bytes


#define I2RND_CMD_NUMBER 3 //hw setting + 1
//I2RND
typedef struct _I2RND_STEP_SIZE {
    unsigned int	s0_vo_blk_size;
    unsigned int	s1_vo_blk_size;
} I2RND_STEP_SIZE;

typedef struct _I2RND_PST_CMD_BUF {
    unsigned int	s0_vo_cur_cmd;
    unsigned int	s1_vo_cur_cmd;
} I2RND_CMD_BUF;

typedef struct _I2RND_SCPU_VIR_START_ADDR {
	unsigned int    s0_vo_st_vir_addr; //0xb8005000 - 0xb8005288
	unsigned int	s0_sensio_st_vir_addr; //0xb806b900 -  0xb806b9fc
	unsigned int    s0_vgip_st_vir_addr;//b8028022200 - b80222e0
	unsigned int	s0_Dither_st_vir_addr;//b8022600 -b8022668
	unsigned int	s0_techcolor_st_vir_addr;//b8028022800 - b8022884
	unsigned int	s0_rgb2yuv_st_vir_addr;// 0xb8023000, b8023008~b802301c,0xb8023038
	unsigned int	s0_pkcri_st_vir_addr;//0xb8023100- 0xb8023108
	unsigned int	s0_idlti_st_vir_addr;//b8023170-b8023180
	unsigned int	s0_dcti_st_vir_addr;//0xb80231d4- 0xb80231f8
	unsigned int	s0_histogram_st_vir_addr;//0xb802_3200  ~ 0xb802_3338
	unsigned int	s0_profile1_st_vir_addr;//0xb802_3400  ~ 0xb802_34FF
	unsigned int	s0_dfliter_st_vir_addr;//-0xb8023500 - 0xb8023504
	unsigned int	s0_ringfilter_st_vir_addr;//-0xb8023580 - 0xb8023590
	unsigned int	s0_dihsd_st_vir_addr;//0xb8023600 - 0xb80236b8
	unsigned int	s0_profile2_st_vir_addr;//0xb802_3700  ~ 0xb802_37e0
	unsigned int	s0_mpegnr_st_vir_addr;//0xb8023820 -0xb80238fc
	unsigned int	s0_dexcxl_st_vir_addr; //0xb8023900 - 0xb80239e4
	unsigned int	s0_multibamk_st_vir_addr;//0xb802_3c00  ~ 0xb802_3c40
	unsigned int	s0_di_st_vir_addr;//b8024000-b8024bf4
	unsigned int	s0_nr1_st_vir_addr;//b8025000-b80250ff
	unsigned int	s0_iedgesmooth_st_vir_addr;//b8025100-b80251ec
	unsigned int    s0_uzd_st_vir_addr;//b8025204-b802537c
	unsigned int	s0_nr2_st_vir_addr;//b8025500-b8025594
	unsigned int	s0_decontour_st_vir_addr;//0xb8025700 - 0xb802575c
	unsigned int	s0_bist_st_vir_addr;//b8025f00-b8025fff
	unsigned int    s0_mcap_st_vir_addr;//0xb8027200 - 0xb802722c;b802726c~b8027280;b80272c8~b80272cc;b80272e0~b80272ec;
	unsigned int	s0_vi_mcap_st_vir_addr;//b8027000~b802707c

	unsigned int    s1_vo_st_vir_addr; //0xb8005000 - 0xb8005288
	unsigned int	s1_sensio_st_vir_addr; //0xb806b900 -  0xb806b9fc
	unsigned int    s1_vgip_st_vir_addr;//b8028022200 - b80222e0
	unsigned int	s1_Dither_st_vir_addr;//b8022600 -b8022668
	unsigned int	s1_techcolor_st_vir_addr;//b8028022800 - b8022884
	unsigned int	s1_rgb2yuv_st_vir_addr;// 0xb8023000, b8023008~b802301c,0xb8023038
	unsigned int	s1_pkcri_st_vir_addr;//0xb8023100- 0xb8023108
	unsigned int	s1_idlti_st_vir_addr;//b8023170-b8023180
	unsigned int	s1_dcti_st_vir_addr;//0xb80231d4- 0xb80231f8
	unsigned int	s1_histogram_st_vir_addr;//0xb802_3200  ~ 0xb802_3338
	unsigned int	s1_profile1_st_vir_addr;//0xb802_3400  ~ 0xb802_34FF
	unsigned int	s1_dfliter_st_vir_addr;//-0xb8023500 - 0xb8023504
	unsigned int	s1_ringfilter_st_vir_addr;//-0xb8023580 - 0xb8023590
	unsigned int	s1_dihsd_st_vir_addr;//0xb8023600 - 0xb80236b8
	unsigned int	s1_profile2_st_vir_addr;//0xb802_3700  ~ 0xb802_37e0
	unsigned int	s1_mpegnr_st_vir_addr;//0xb8023820 -0xb80238fc
	unsigned int	s1_dexcxl_st_vir_addr; //0xb8023900 - 0xb80239e4
	unsigned int	s1_multibamk_st_vir_addr;//0xb802_3c00  ~ 0xb802_3c40
	unsigned int	s1_di_st_vir_addr;//b8024000-b8024bf4
	unsigned int	s1_nr1_st_vir_addr;//b8025000-b80250ff
	unsigned int	s1_iedgesmooth_st_vir_addr;//b8025100-b80251ec
	unsigned int    s1_uzd_st_vir_addr;//b8025204-b802537c
	unsigned int	s1_nr2_st_vir_addr;//b8025500-b8025594
	unsigned int	s1_decontour_st_vir_addr;//0xb8025700 - 0xb802575c
	unsigned int	s1_bist_st_vir_addr;//b8025f00-b8025fff
	unsigned int    s1_mcap_st_vir_addr;//0xb8027200 - 0xb802722c;b802726c~b8027280;b80272c8~b80272cc;b80272e0~b80272ec;
	unsigned int	s1_vi_mcap_st_vir_addr;//b8027000~b802707c

	unsigned int	i2rnd_enable_vir_addr;//in2rnd enable flag
	unsigned int	i2rnd_write_cmd_vir_addr;
	unsigned int	i2rnd_read_cmd_vir_addr;
	unsigned int	i2rnd_pst_pnt_counter_vir_addr;
}I2RND_SCPU_VIR_START_ADDR;


typedef enum{
	_1_MAIN_0_SUB = 0,
	_1_MAIN_1_SUB,
	_1_MAIN_2_SUB,
	TIMING_MODE_MAX,
}_I2RND_TIMING_MODE_T;


/*================================== Function ===============================*/
void drvif_scaler_i2rnd_vodma1_flag_fifo_prepare(void);
void drvif_scaler_i2rnd_vodma_setting(unsigned char display, unsigned char input_src);
void drvif_scaler_i2rnd_step_size(unsigned int blk_size);
void drvif_scaler_i2rnd_dma_setting(unsigned int cmd_num, unsigned int blk_size);
void drvif_scaler_i2rnd_initial(void);
void drvif_scaler_i2rnd_uninitial(void);
void drvif_scaler_i2rnd_top_ctrl(bool i2rnd_en);
void Scaler_I2rnd_handler(void);

unsigned char Scaler_I2rnd_get_enable(void);
void Scaler_I2rnd_set_enable(unsigned char enable);
unsigned char	Scaler_i2rnd_setbuffer(void);
unsigned int Scaler_i2rnd_IP_register_get_cur_write_addr(unsigned int addr,unsigned char display);
unsigned int Scaler_i2rnd_IP_register_get_cur_read_addr(unsigned int addr,unsigned char display);
unsigned char Scaler_I2rnd_get_display(void);
void Scaler_I2rnd_set_display(unsigned char display);
void i2rnd_default_register_setting(void);
void i2rnd_group3_s0_to_s1_register_sync(void);
void i2rnd_group3_s1_to_s0_register_sync(void);
unsigned char Scaler_I2rnd_get_di_done(void);
void Scaler_I2rnd_set_di_done(unsigned char enable);
void i2rnd_di_control_reg_change_valid_index(unsigned char enable, unsigned char display);
void i2rnd_di_size_toggle(void);
unsigned int Scaler_i2rnd_send_apvr_info(void);
void i2rnd_send_table_idx(unsigned char index);
void Scaler_i2rnd_set_write_point(void);
unsigned char Scaler_i2rnd_get_write_point(void);
unsigned char Scaler_i2rnd_get_read_point(void);
void Scaler_i2rnd_buffer_copy(void);
void Scaler_I2rnd_set_write_cmd_num(void);
void Scaler_i2rnd_write_default_cmd_num(void);
void drvif_scaler_i2rnd_change_fw_mode(void);
unsigned int get_i2rnd_pst_write_pnt_counter(void);
void set_i2rnd_pst_write_pnt_counter(unsigned int cnt);
void Scaler_I2rnd_set_read_cmd_num(unsigned char enable);
/////b05
void drvif_scaler_i2rnd_b05_dma_setting(unsigned int cmd_num, unsigned int blk_size);
void drvif_scaler_i2rnd_b05_vodma_setting(unsigned char display);
void drvif_scaler_i2rnd_b05_initial(void);
void vo_b05_outl(unsigned int addr, unsigned int value);
unsigned char Scaler_I2rnd_b05_get_enable(void);
void Scaler_I2rnd_b05_handler(void);
void drvif_scaler_i2rnd_b05_top_ctrl(bool i2rnd_en);
void vo_b05_debug(void);
void set_b05_var(void);
void Scaler_I2rnd_b05_set_enable(unsigned char enable);
void i2rnd_b05_default_register_setting(void);
void drvif_scaler_i2rnd_b05_uninitial(void);
void Scaler_i2rnd_b05_buffer_copy(void);

#ifdef __cplusplus
}
#endif

#endif // #ifndef _SCALER_H_
/*======================== End of File =======================================*/
/**
*
* @}
*/

