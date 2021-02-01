/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2014
  * All rights reserved.
  * ========================================================================*/
  /*================= File Description =======================================*/
  /**
   * @file
   *  This file is for HDR TC related functions.
   *
   * @author  $Author$
   * @date	  $Date$
   * @version	  $Revision$
   */


  /*============================ Module dependency	===========================*/

#if CONFIG_FIRMWARE_IN_KERNEL
#include <linux/string.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <linux/kernel.h>
#include <tvscalercontrol/vip/tc_hdr.h>
#include <tvscalercontrol/vip/tc_math.h>//juwen, merlin3, tc//juwen, 170216, TCv1.3.0_computeMetaData
#include <tvscalercontrol/scaler/vipinclude.h> // for typedef that used in VIP_reg_def.h
#include <tvscalercontrol/vip/vip_reg_def.h>
//#include <rbus/rbusTCReg.h>
#include <rbus/tc_reg.h>

#else
#include <unistd.h>		// 'close()'
#include <fcntl.h>			// 'open()'
#include <stdio.h>
#include <sys/ioctl.h>

#include <Platform_Lib/TVScalerControl/io/ioRegDrv.h>
#include <Platform_Lib/TVScalerControl/vip/tc_hdr.h>
#include <Platform_Lib/TVScalerControl/vip/VIP_reg_def.h>


#endif

#if CONFIG_FIRMWARE_IN_KERNEL
#define VIPprintf(fmt, args...)	pr_debug(fmt, ##args)//printk(KERN_DEBUG fmt, ##args)
#else
#define VIPprintf(fmt, args...)	printf(fmt, ##args)
#endif

#define TC_ABS(x) ((x >= 0) ? x : -(x))

unsigned int TCHDR_COEF_C_LUT_TBL_ReadReg[TCHDR_COEF_C_LUT_TBL_SIZE];
unsigned int TCHDR_COEF_I_LUT_TBL_ReadReg[TCHDR_COEF_I_LUT_TBL_SIZE];
unsigned int TCHDR_COEF_S_LUT_TBL_ReadReg[TCHDR_COEF_S_LUT_TBL_SIZE];
unsigned int TCHDR_COEF_P_LUT_TBL_ReadReg[TCHDR_COEF_P_LUT_TBL_SIZE];
unsigned int TCHDR_COEF_D_LUT_RED_TBL_ReadReg[TCHDR_COEF_D_LUT_RED_TBL_SIZE];
unsigned int TCHDR_COEF_D_LUT_GREEN_TBL_ReadReg[TCHDR_COEF_D_LUT_GREEN_TBL_SIZE];
unsigned int TCHDR_COEF_D_LUT_BLUE_TBL_ReadReg[TCHDR_COEF_D_LUT_BLUE_TBL_SIZE];


#define TC_HDR_Debug 0

static DRV_TC_HDR_CTRL TC_HDR_CTRL= {0};

DRV_TC_HDR_CTRL* drvif_fwif_color_Get_TC_CTRL(void)
{
	return &TC_HDR_CTRL;
}

void decode_TC_Read_LUTs_regValue(unsigned int *p_regArray, unsigned short *p_C_LUT_coff)//(input, output)
{
	unsigned char i, ii;


	ii = 0;

	for(i=0; i<33 ; i++)
	{
		p_C_LUT_coff[ii]   = p_regArray[i] >> 16;
		ii++;
		p_C_LUT_coff[ii]= p_regArray[i] & 0xFFFF;
		ii++;
	}

}


/* Function Description : This function is for TC enable*/
void drvif_color_set_TC_Enable(unsigned char enable)
{

	tc_tchdr_enable_RBUS tc_tchdr_enable;
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);

	tc_tchdr_enable.tc_enable= enable;

	#ifdef SLD_Debug
	VIPprintf("tchdr_valid = %d\n",tc_tchdr_enable.tc_enable);
	#endif

	IoReg_Write32(TC_TChdr_enable_reg, tc_tchdr_enable.regValue);

}

#if 1//juwen,1215,debug
void drvif_color_set_TC_swap_vgip_vyu2yuv(void)
{

	vgip_vgip_chn1_misc_RBUS vgip_chn1_misc;
	vgip_chn1_misc.regValue = IoReg_Read32(VGIP_VGIP_CHN1_MISC_reg);

	vgip_chn1_misc.ch1_v2_v3_swap= 1;
	vgip_chn1_misc.ch1_v1_v2_swap= 1;

	IoReg_Write32(VGIP_VGIP_CHN1_MISC_reg, vgip_chn1_misc.regValue);
}
#endif

void drvif_color_set_TC_certification_Enable(unsigned char certification_enable,unsigned char certification_bitout)
{

	tc_tchdr_enable_RBUS tc_tchdr_certification_enable;
	tc_tchdr_certification_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);

	tc_tchdr_certification_enable.certification_enable= certification_enable;
	tc_tchdr_certification_enable.tc_certification_bitout= certification_bitout;


	IoReg_Write32(TC_TChdr_enable_reg, tc_tchdr_certification_enable.regValue);

}


/*range adaptation*/
void drvif_color_set_TC_Range_Adaptation(DRV_TCHDR_RangeAdaption *ptr)
{

	tc_tchdr_range_adaptation_ctrl0_RBUS tc_tchdr_range_adaptation_ctrl0;
	tc_tchdr_range_adaptation_ctrl1_RBUS tc_tchdr_range_adaptation_ctrl1;
	tc_tchdr_range_adaptation_ctrl2_RBUS tc_tchdr_range_adaptation_ctrl2;
	tc_tchdr_range_adaptation_ctrl0.regValue = IoReg_Read32(TC_TChdr_Range_Adaptation_Ctrl0_reg);
	tc_tchdr_range_adaptation_ctrl1.regValue = IoReg_Read32(TC_TChdr_Range_Adaptation_Ctrl1_reg);
	tc_tchdr_range_adaptation_ctrl2.regValue = IoReg_Read32(TC_TChdr_Range_Adaptation_Ctrl2_reg);

	tc_tchdr_range_adaptation_ctrl0.footroom_int= ptr->tchdr_footroom_int;
	tc_tchdr_range_adaptation_ctrl1.l_headroom_int= ptr->tchdr_l_headroom_int;
	tc_tchdr_range_adaptation_ctrl1.c_headroom_int= ptr->tchdr_c_headroom_int;
	tc_tchdr_range_adaptation_ctrl2.inv_y_limited_range_ratio_int= ptr->tchdr_inv_y_limited_range_ratio_int;
	tc_tchdr_range_adaptation_ctrl2.inv_chroma_limited_range_ratio_int= ptr->tchdr_inv_chroma_limited_range_ratio_int;


	IoReg_Write32(TC_TChdr_Range_Adaptation_Ctrl0_reg, tc_tchdr_range_adaptation_ctrl0.regValue);
	IoReg_Write32(TC_TChdr_Range_Adaptation_Ctrl1_reg, tc_tchdr_range_adaptation_ctrl1.regValue);
	IoReg_Write32(TC_TChdr_Range_Adaptation_Ctrl2_reg, tc_tchdr_range_adaptation_ctrl2.regValue);

}


/*L Compute*/
void drvif_color_set_TC_L_Compute(DRV_TCHDR_l_compute *ptr)
{

	tc_tchdr_l_compute_RBUS tc_tchdr_l_compute;
	tc_tchdr_l_compute.regValue = IoReg_Read32(TC_TChdr_L_Compute_reg);

	tc_tchdr_l_compute.alpha_a= ptr->tchdr_alpha_a;
	tc_tchdr_l_compute.alpha_b= ptr->tchdr_alpha_b;


	IoReg_Write32(TC_TChdr_L_Compute_reg, tc_tchdr_l_compute.regValue);

}

/*T Compute*/
void drvif_color_set_TC_T_Compute(DRV_TCHDR_T_compute *ptr)
{
	unsigned int tmp_oct0;
	unsigned int tmp_oct1;
	unsigned int tmp_oct2;

	tc_tchdr_t_compute0_RBUS tc_tchdr_t_compute0;
	tc_tchdr_t_compute1_RBUS tc_tchdr_t_compute1;

	tc_tchdr_t_compute0.regValue = IoReg_Read32(TC_TChdr_T_Compute0_reg);
	tc_tchdr_t_compute1.regValue = IoReg_Read32(TC_TChdr_T_Compute1_reg);


//sign -> unsign
	tmp_oct0 = ( ptr->tchdr_oct0 >= 0) ?
					ptr->tchdr_oct0 :
					ptr->tchdr_oct0 +1024;

	tmp_oct1 = ( ptr->tchdr_oct1 >= 0) ?
					ptr->tchdr_oct1 :
					ptr->tchdr_oct1 +1024;

	tmp_oct2 = ( ptr->tchdr_oct2 >= 0) ?
					ptr->tchdr_oct2 :
					ptr->tchdr_oct2 +1024;

	tc_tchdr_t_compute0.oct0= tmp_oct0;
	tc_tchdr_t_compute0.oct1= tmp_oct1;
	tc_tchdr_t_compute1.oct2= tmp_oct2;


	IoReg_Write32(TC_TChdr_T_Compute0_reg, tc_tchdr_t_compute0.regValue);
	IoReg_Write32(TC_TChdr_T_Compute1_reg, tc_tchdr_t_compute1.regValue);

}

/*M Compute*/
void drvif_color_set_TC_M_Compute(DRV_TCHDR_M_compute *ptr)
{
	unsigned int tmp_oct3;
	unsigned int tmp_oct4;
	unsigned int tmp_oct5;
	unsigned int tmp_oct6;


	tc_tchdr_m_compute0_RBUS tc_tchdr_m_compute0;
	tc_tchdr_m_compute1_RBUS tc_tchdr_m_compute1;

	tc_tchdr_m_compute0.regValue = IoReg_Read32(TC_TChdr_M_Compute0_reg);
	tc_tchdr_m_compute1.regValue = IoReg_Read32(TC_TChdr_M_Compute1_reg);


//sign -> unsign
	tmp_oct3 = ( ptr->tchdr_oct3 >= 0) ?
					ptr->tchdr_oct3 :
					ptr->tchdr_oct3 +1024;

	tmp_oct4 = ( ptr->tchdr_oct4 >= 0) ?
					ptr->tchdr_oct4 :
					ptr->tchdr_oct4 +1024;

	tmp_oct5 = ( ptr->tchdr_oct5 >= 0) ?
					ptr->tchdr_oct5 :
					ptr->tchdr_oct5 +1024;

	tmp_oct6 = ( ptr->tchdr_oct6 >= 0) ?
					ptr->tchdr_oct6 :
					ptr->tchdr_oct6 +1024;

	tc_tchdr_m_compute0.oct3= tmp_oct3;
	tc_tchdr_m_compute0.oct4= tmp_oct4;
	tc_tchdr_m_compute1.oct5= tmp_oct5;
	tc_tchdr_m_compute1.oct6= tmp_oct6;

	IoReg_Write32(TC_TChdr_M_Compute0_reg, tc_tchdr_m_compute0.regValue);
	IoReg_Write32(TC_TChdr_M_Compute1_reg, tc_tchdr_m_compute1.regValue);

}


void drvif_color_set_TC_Write_C_LUT(unsigned short *ptr)
{
	unsigned char status;
	unsigned char i=0;
	unsigned short cnt;
	//unsigned char tmp_c_lut_rw_addr=0;

	tc_tchdr_c_lut_ctrl0_RBUS tc_tchdr_c_lut_ctrl0;
	tc_tchdr_c_lut_ctrl1_RBUS tc_tchdr_c_lut_ctrl1;
	tc_tchdr_c_lut_wr_data_RBUS tc_tchdr_c_lut_wr_data;
	tc_tchdr_enable_RBUS tc_tchdr_enable;

	//tc_tchdr_c_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL0_reg);
	//tc_tchdr_c_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL1_reg);
	tc_tchdr_c_lut_wr_data.regValue = IoReg_Read32(TC_TChdr_C_LUT_WR_DATA_reg);

//1.
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);


	tc_tchdr_c_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL0_reg);
	tc_tchdr_c_lut_ctrl0.c_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_C_LUT_CTRL0_reg,tc_tchdr_c_lut_ctrl0.regValue);

	tc_tchdr_c_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL0_reg);
	tc_tchdr_c_lut_ctrl0.c_lut_rw_sel = 1;
	IoReg_Write32(TC_TChdr_C_LUT_CTRL0_reg,tc_tchdr_c_lut_ctrl0.regValue);


 	for(i=0;i<33;i++){
	// while(tmp_c_lut_rw_addr < 32){
	//2.
		tc_tchdr_c_lut_wr_data.c_wr_lut_data0 = *ptr++;
		tc_tchdr_c_lut_wr_data.c_wr_lut_data1 = *ptr++;
		IoReg_Write32(TC_TChdr_C_LUT_WR_DATA_reg,tc_tchdr_c_lut_wr_data.regValue);

	    tc_tchdr_c_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL1_reg);
		tc_tchdr_c_lut_ctrl1.c_lut_write_en = 1;
		IoReg_Write32(TC_TChdr_C_LUT_CTRL1_reg,tc_tchdr_c_lut_ctrl1.regValue);

	    tc_tchdr_c_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL1_reg);
		tc_tchdr_c_lut_ctrl1.c_lut_read_en = 0;
		IoReg_Write32(TC_TChdr_C_LUT_CTRL1_reg,tc_tchdr_c_lut_ctrl1.regValue);

	//3.
		status = 1;
		cnt = 10000;
		while( (cnt--) && status) { /*wait for finishing writing*/
			tc_tchdr_c_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL1_reg);
			status = tc_tchdr_c_lut_ctrl1.c_lut_write_en;
		}
		if (status == 1) {
			VIPprintf(" TC_C_LUT write error, return\n");
			return;
		}
		if ( tc_tchdr_c_lut_ctrl1.c_lut_rw_addr != i + 1) {
			VIPprintf(" TC_C_LUT write error : c_lut_rw_addr, return\n");
			return;
		}

		//tc_tchdr_c_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL1_reg);
		// tmp_c_lut_rw_addr = tc_tchdr_c_lut_ctrl1.c_lut_rw_addr;


	}//end for

//4
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);

	tc_tchdr_c_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL0_reg);
	tc_tchdr_c_lut_ctrl0.c_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_C_LUT_CTRL0_reg,tc_tchdr_c_lut_ctrl0.regValue);

}

/*C LUT Read*/
void drvif_color_set_TC_Read_C_LUT(unsigned int *read_reg_ptr)
{
	unsigned char status_read_en;
	unsigned char i=0;
	unsigned short cnt;

	tc_tchdr_c_lut_ctrl0_RBUS tc_tchdr_c_lut_ctrl0;
	tc_tchdr_c_lut_ctrl1_RBUS tc_tchdr_c_lut_ctrl1;
	//tc_tchdr_c_lut_wr_data_RBUS tc_tchdr_c_lut_wr_data;
	tc_tchdr_enable_RBUS tc_tchdr_enable;

	//tc_tchdr_c_lut_wr_data.regValue = IoReg_Read32(TC_TChdr_C_LUT_WR_DATA_reg);

//1.
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);


	tc_tchdr_c_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL0_reg);
	tc_tchdr_c_lut_ctrl0.c_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_C_LUT_CTRL0_reg,tc_tchdr_c_lut_ctrl0.regValue);

	tc_tchdr_c_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL0_reg);
	tc_tchdr_c_lut_ctrl0.c_lut_rw_sel = 2;
	IoReg_Write32(TC_TChdr_C_LUT_CTRL0_reg,tc_tchdr_c_lut_ctrl0.regValue);



 	for(i=0;i<33;i++){
//2
		tc_tchdr_c_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL1_reg);
		tc_tchdr_c_lut_ctrl1.c_lut_write_en = 0;
		IoReg_Write32(TC_TChdr_C_LUT_CTRL1_reg,tc_tchdr_c_lut_ctrl1.regValue);

		tc_tchdr_c_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL1_reg);
		tc_tchdr_c_lut_ctrl1.c_lut_read_en = 1;
		IoReg_Write32(TC_TChdr_C_LUT_CTRL1_reg,tc_tchdr_c_lut_ctrl1.regValue);


//3.
		status_read_en = 1;
		cnt = 10000;
		while( (cnt--) && status_read_en) { /*wait for finishing writing*/
			tc_tchdr_c_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL1_reg);
			status_read_en = tc_tchdr_c_lut_ctrl1.c_lut_read_en;
		}

		if (status_read_en == 1) {
			VIPprintf(" TC_C_LUT read error, return\n");
			return;
		}
		if ( tc_tchdr_c_lut_ctrl1.c_lut_rw_addr != i + 1) {
			VIPprintf(" TC_C_LUT write error : c_lut_rw_addr, return\n");
			return;
		}

		read_reg_ptr[i] = IoReg_Read32(TC_TChdr_C_LUT_RD_DATA_reg);

	}//end for

//4
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);

	tc_tchdr_c_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_C_LUT_CTRL0_reg);
	tc_tchdr_c_lut_ctrl0.c_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_C_LUT_CTRL0_reg,tc_tchdr_c_lut_ctrl0.regValue);

}



/*I LUT Read*/
void drvif_color_set_TC_Read_I_LUT(unsigned int *read_reg_ptr)
{
	unsigned char status_read_en;
	unsigned char i=0;
	unsigned short cnt;

	tc_tchdr_i_lut_ctrl0_RBUS tc_tchdr_i_lut_ctrl0;
	tc_tchdr_i_lut_ctrl1_RBUS tc_tchdr_i_lut_ctrl1;
	//tc_tchdr_i_lut_wr_data_RBUS tc_tchdr_i_lut_wr_data;
	tc_tchdr_enable_RBUS tc_tchdr_enable;

	//tc_tchdr_i_lut_wr_data.regValue = IoReg_Read32(TC_TChdr_I_LUT_WR_DATA_reg);

//1.
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);


	tc_tchdr_i_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL0_reg);
	tc_tchdr_i_lut_ctrl0.i_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_I_LUT_CTRL0_reg,tc_tchdr_i_lut_ctrl0.regValue);

	tc_tchdr_i_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL0_reg);
	tc_tchdr_i_lut_ctrl0.i_lut_rw_sel = 2;
	IoReg_Write32(TC_TChdr_I_LUT_CTRL0_reg,tc_tchdr_i_lut_ctrl0.regValue);



 	for(i=0;i<33;i++){
//2
	tc_tchdr_i_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL1_reg);
	tc_tchdr_i_lut_ctrl1.i_lut_write_en = 0;
	IoReg_Write32(TC_TChdr_I_LUT_CTRL1_reg,tc_tchdr_i_lut_ctrl1.regValue);

	tc_tchdr_i_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL1_reg);
	tc_tchdr_i_lut_ctrl1.i_lut_read_en = 1;
	IoReg_Write32(TC_TChdr_I_LUT_CTRL1_reg,tc_tchdr_i_lut_ctrl1.regValue);


//3.
		status_read_en = 1;
		cnt = 10000;
		while( (cnt--) && status_read_en) { /*wait for finishing writing*/
			tc_tchdr_i_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL1_reg);
			status_read_en = tc_tchdr_i_lut_ctrl1.i_lut_read_en;
		}

		if (status_read_en == 1) {
			VIPprintf(" TC_I_LUT read error, return\n");
			return;
		}
		if ( tc_tchdr_i_lut_ctrl1.i_lut_rw_addr != i + 1) {
			VIPprintf(" TC_I_LUT write error : i_lut_rw_addr, return\n");
			return;
		}

		read_reg_ptr[i] = IoReg_Read32(TC_TChdr_I_LUT_RD_DATA_reg);

	}//end for

//4
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);

	tc_tchdr_i_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL0_reg);
	tc_tchdr_i_lut_ctrl0.i_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_I_LUT_CTRL0_reg,tc_tchdr_i_lut_ctrl0.regValue);

}


/*I LUT*/
void drvif_color_set_TC_Write_I_LUT(unsigned short *ptr)
{
	unsigned char status;
	unsigned char i=0;
	unsigned short cnt;

	//unsigned char tmp_i_lut_rw_addr=0;

	tc_tchdr_i_lut_ctrl0_RBUS tc_tchdr_i_lut_ctrl0;
	tc_tchdr_i_lut_ctrl1_RBUS tc_tchdr_i_lut_ctrl1;
	tc_tchdr_i_lut_wr_data_RBUS tc_tchdr_i_lut_wr_data;
	tc_tchdr_enable_RBUS tc_tchdr_enable;

	//tc_tchdr_i_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL0_reg);
	//tc_tchdr_i_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL1_reg);
	tc_tchdr_i_lut_wr_data.regValue = IoReg_Read32(TC_TChdr_I_LUT_WR_DATA_reg);

//1.
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);


	tc_tchdr_i_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL0_reg);
	tc_tchdr_i_lut_ctrl0.i_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_I_LUT_CTRL0_reg,tc_tchdr_i_lut_ctrl0.regValue);

	tc_tchdr_i_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL0_reg);
	tc_tchdr_i_lut_ctrl0.i_lut_rw_sel = 1;
	IoReg_Write32(TC_TChdr_I_LUT_CTRL0_reg,tc_tchdr_i_lut_ctrl0.regValue);


 	for(i=0;i<33;i++){
	// while(tmp_i_lut_rw_addr < 32){
	//2.
		tc_tchdr_i_lut_wr_data.i_wr_lut_data0 = *ptr++;
		tc_tchdr_i_lut_wr_data.i_wr_lut_data1 = *ptr++;
		IoReg_Write32(TC_TChdr_I_LUT_WR_DATA_reg,tc_tchdr_i_lut_wr_data.regValue);

                tc_tchdr_i_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL1_reg);
		tc_tchdr_i_lut_ctrl1.i_lut_write_en = 1;
		IoReg_Write32(TC_TChdr_I_LUT_CTRL1_reg,tc_tchdr_i_lut_ctrl1.regValue);

                tc_tchdr_i_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL1_reg);
		tc_tchdr_i_lut_ctrl1.i_lut_read_en = 0;
		IoReg_Write32(TC_TChdr_I_LUT_CTRL1_reg,tc_tchdr_i_lut_ctrl1.regValue);

	//3.
		status = 1;
		cnt = 10000;
		while( (cnt--) && status) { /*wait for finishing writing*/
			tc_tchdr_i_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL1_reg);
			status = tc_tchdr_i_lut_ctrl1.i_lut_write_en;
		}
		if (status == 1) {
			VIPprintf(" TC_I_LUT write error, return\n");
			return;
		}
		if ( tc_tchdr_i_lut_ctrl1.i_lut_rw_addr != i + 1) {
			VIPprintf(" TC_I_LUT write error : i_lut_rw_addr, return\n");
			return;
		}

		//tc_tchdr_i_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL1_reg);
		// tmp_i_lut_rw_addr = tc_tchdr_i_lut_ctrl1.c_lut_rw_addr;


	}//end for

//4
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);

        tc_tchdr_i_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_I_LUT_CTRL0_reg);
	tc_tchdr_i_lut_ctrl0.i_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_I_LUT_CTRL0_reg,tc_tchdr_i_lut_ctrl0.regValue);

}


/*S LUT*/
void drvif_color_set_TC_Write_S_LUT(unsigned short *ptr)
{
	unsigned char status;
	unsigned char i=0;
	unsigned short cnt;

	//unsigned char tmp_s_lut_rw_addr=0;

	tc_tchdr_s_lut_ctrl0_RBUS tc_tchdr_s_lut_ctrl0;
	tc_tchdr_s_lut_ctrl1_RBUS tc_tchdr_s_lut_ctrl1;
	tc_tchdr_s_lut_wr_data_RBUS tc_tchdr_s_lut_wr_data;
	tc_tchdr_enable_RBUS tc_tchdr_enable;

	//tc_tchdr_s_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL0_reg);
	//tc_tchdr_s_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL1_reg);
	tc_tchdr_s_lut_wr_data.regValue = IoReg_Read32(TC_TChdr_S_LUT_WR_DATA_reg);

//1.
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);


        tc_tchdr_s_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL0_reg);
	tc_tchdr_s_lut_ctrl0.s_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_S_LUT_CTRL0_reg,tc_tchdr_s_lut_ctrl0.regValue);


        tc_tchdr_s_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL0_reg);
	tc_tchdr_s_lut_ctrl0.s_lut_rw_sel = 1;
	IoReg_Write32(TC_TChdr_S_LUT_CTRL0_reg,tc_tchdr_s_lut_ctrl0.regValue);


 	for(i=0;i<33;i++){
	// while(tmp_s_lut_rw_addr < 32){
	//2.
		tc_tchdr_s_lut_wr_data.s_wr_lut_data0 = *ptr++;
		tc_tchdr_s_lut_wr_data.s_wr_lut_data1 = *ptr++;
		IoReg_Write32(TC_TChdr_S_LUT_WR_DATA_reg,tc_tchdr_s_lut_wr_data.regValue);

                tc_tchdr_s_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL1_reg);
		tc_tchdr_s_lut_ctrl1.s_lut_write_en = 1;
		IoReg_Write32(TC_TChdr_S_LUT_CTRL1_reg,tc_tchdr_s_lut_ctrl1.regValue);

                tc_tchdr_s_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL1_reg);
		tc_tchdr_s_lut_ctrl1.s_lut_read_en = 0;
		IoReg_Write32(TC_TChdr_S_LUT_CTRL1_reg,tc_tchdr_s_lut_ctrl1.regValue);

	//3.
		status = 1;
		cnt = 10000;
		while( (cnt--) && status) { /*wait for finishing writing*/
			tc_tchdr_s_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL1_reg);
			status = tc_tchdr_s_lut_ctrl1.s_lut_write_en;
		}
		if (status == 1) {
			VIPprintf(" TC_S_LUT write error, return\n");
			return;
		}
		if ( tc_tchdr_s_lut_ctrl1.s_lut_rw_addr != i + 1) {
			VIPprintf(" TC_S_LUT write error : s_lut_rw_addr, return\n");
			return;
		}

		//tc_tchdr_s_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL1_reg);
		// tmp_s_lut_rw_addr = tc_tchdr_s_lut_ctrl1.c_lut_rw_addr;


	}//end for

//4
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);

        tc_tchdr_s_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL0_reg);
	tc_tchdr_s_lut_ctrl0.s_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_S_LUT_CTRL0_reg,tc_tchdr_s_lut_ctrl0.regValue);

}


/*S LUT Read*/
void drvif_color_set_TC_Read_S_LUT(unsigned int *read_reg_ptr)
{
	unsigned char status_read_en;
	unsigned char i=0;
	unsigned short cnt;

	tc_tchdr_s_lut_ctrl0_RBUS tc_tchdr_s_lut_ctrl0;
	tc_tchdr_s_lut_ctrl1_RBUS tc_tchdr_s_lut_ctrl1;
	//tc_tchdr_s_lut_wr_data_RBUS tc_tchdr_s_lut_wr_data;
	tc_tchdr_enable_RBUS tc_tchdr_enable;

	//tc_tchdr_s_lut_wr_data.regValue = IoReg_Read32(TC_TChdr_S_LUT_WR_DATA_reg);

//1.
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);


	tc_tchdr_s_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL0_reg);
	tc_tchdr_s_lut_ctrl0.s_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_S_LUT_CTRL0_reg,tc_tchdr_s_lut_ctrl0.regValue);

	tc_tchdr_s_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL0_reg);
	tc_tchdr_s_lut_ctrl0.s_lut_rw_sel = 2;
	IoReg_Write32(TC_TChdr_S_LUT_CTRL0_reg,tc_tchdr_s_lut_ctrl0.regValue);



 	for(i=0;i<33;i++){
//2
	tc_tchdr_s_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL1_reg);
	tc_tchdr_s_lut_ctrl1.s_lut_write_en = 0;
	IoReg_Write32(TC_TChdr_S_LUT_CTRL1_reg,tc_tchdr_s_lut_ctrl1.regValue);

	tc_tchdr_s_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL1_reg);
	tc_tchdr_s_lut_ctrl1.s_lut_read_en = 1;
	IoReg_Write32(TC_TChdr_S_LUT_CTRL1_reg,tc_tchdr_s_lut_ctrl1.regValue);


//3.
		status_read_en = 1;
		cnt = 10000;
		while( (cnt--) && status_read_en) { /*wait for finishing writing*/
			tc_tchdr_s_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL1_reg);
			status_read_en = tc_tchdr_s_lut_ctrl1.s_lut_read_en;
		}

		if (status_read_en == 1) {
			VIPprintf(" TC_S_LUT read error, return\n");
			return;
		}
		if ( tc_tchdr_s_lut_ctrl1.s_lut_rw_addr != i + 1) {
			VIPprintf(" TC_S_LUT write error : s_lut_rw_addr, return\n");
			return;
		}

		read_reg_ptr[i] = IoReg_Read32(TC_TChdr_S_LUT_RD_DATA_reg);

	}//end for

//4
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);

	tc_tchdr_s_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_S_LUT_CTRL0_reg);
	tc_tchdr_s_lut_ctrl0.s_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_S_LUT_CTRL0_reg,tc_tchdr_s_lut_ctrl0.regValue);

}


/*P LUT*/
char drvif_color_set_TC_Write_P_LUT(unsigned short *ptr)
{
	unsigned char status;
	unsigned char status_acc_ready;
	unsigned char status_write_enable;
	unsigned char i=0;
	unsigned short cnt;

	/*bool select_tbl_flag;*/

	//unsigned char tmp_s_lut_rw_addr=0;

//define structure variable
	tc_tchdr_p_lut_ctrl0_RBUS tc_tchdr_p_lut_ctrl0;
	tc_tchdr_p_lut_ctrl1_RBUS tc_tchdr_p_lut_ctrl1;
	tc_tchdr_p_lut_ctrl2_RBUS tc_tchdr_p_lut_ctrl2;//Read only
	tc_tchdr_p_lut_ctrl3_RBUS tc_tchdr_p_lut_ctrl3;//Read only
	tc_tchdr_p_lut_wr_data_RBUS tc_tchdr_p_lut_wr_data;




//read register value from HW
	tc_tchdr_p_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL0_reg);
	tc_tchdr_p_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL1_reg);
	tc_tchdr_p_lut_wr_data.regValue = IoReg_Read32(TC_TChdr_P_LUT_WR_DATA_reg);

//decide which table to write
/*	select_tbl_flag = tc_tchdr_p_lut_ctrl0.p_lut_acc_sel;
	if(select_tbl_flag){
		select_tbl_flag = 0;
	}
	else{
		select_tbl_flag = 1;
	}
*/


//1.
	tc_tchdr_p_lut_ctrl0.p_lut_rw_sel = 1;
	IoReg_Write32(TC_TChdr_P_LUT_CTRL0_reg,tc_tchdr_p_lut_ctrl0.regValue);

	/*tc_tchdr_p_lut_ctrl0.p_lut_acc_sel = select_tbl_flag;
	IoReg_Write32(TC_TChdr_P_LUT_CTRL0_reg,tc_tchdr_p_lut_ctrl0.regValue);*/


//2.
	status_acc_ready = 0;
	cnt =10000;
	while( (cnt--) && (status_acc_ready!=1)) { /*wait for finishing writing*/
		tc_tchdr_p_lut_ctrl2.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL2_reg);
		status_acc_ready = tc_tchdr_p_lut_ctrl2.p_lut_acc_ready;
	}
	if (status_acc_ready == 0) {
		VIPprintf(" TC_P_LUT write error, return\n");
		return -1;
	}



 	for(i=0;i<33;i++){
	// while(tmp_s_lut_rw_addr < 32){
	//3.
		tc_tchdr_p_lut_wr_data.p_wr_lut_data0 = *ptr++;
		tc_tchdr_p_lut_wr_data.p_wr_lut_data1 = *ptr++;
		IoReg_Write32(TC_TChdr_P_LUT_WR_DATA_reg,tc_tchdr_p_lut_wr_data.regValue);

		tc_tchdr_p_lut_ctrl1.p_lut_write_en = 1;
		IoReg_Write32(TC_TChdr_P_LUT_CTRL1_reg,tc_tchdr_p_lut_ctrl1.regValue);
	//4.
	//???????????????cnt要設多�??????????????????????????????????????????
	status_write_enable =1;
	cnt = 10000;
	while( (cnt--) && status_write_enable) { /*wait for finishing writing*/
		tc_tchdr_p_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL1_reg);
		status_write_enable = tc_tchdr_p_lut_ctrl1.p_lut_write_en;
	}
	if (status_write_enable == 1) {
		VIPprintf(" TC_P_LUT write error, return\n");
		return -2;
	}


	tc_tchdr_p_lut_ctrl2.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL2_reg);
	if ( tc_tchdr_p_lut_ctrl2.p_lut_rw_addr != i + 1) {
		VIPprintf(" TC_P_LUT write error : p_lut_rw_addr, return\n");
		return -3;
	}
}//end for
//5
	tc_tchdr_p_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL0_reg);
	tc_tchdr_p_lut_ctrl0.p_lut_rw_sel = 0;
	/* change table for next writting*/
	tc_tchdr_p_lut_ctrl0.p_lut_acc_sel = ~tc_tchdr_p_lut_ctrl0.p_lut_acc_sel;
	IoReg_Write32(TC_TChdr_P_LUT_CTRL0_reg,tc_tchdr_p_lut_ctrl0.regValue);

	return 0;

}

/*P LUT Read*/
char drvif_color_set_TC_Read_P_LUT(unsigned int *read_reg_ptr)
{
	unsigned char status_read_enable;
	unsigned char status_acc_ready;
	unsigned char i=0;
	unsigned short cnt;

	tc_tchdr_p_lut_ctrl0_RBUS tc_tchdr_p_lut_ctrl0;
	tc_tchdr_p_lut_ctrl1_RBUS tc_tchdr_p_lut_ctrl1;
	tc_tchdr_p_lut_ctrl2_RBUS tc_tchdr_p_lut_ctrl2;
	tc_tchdr_p_lut_rd_data_RBUS tc_tchdr_p_lut_rd_data;

//1.
	tc_tchdr_p_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL0_reg);
	tc_tchdr_p_lut_ctrl0.p_lut_rw_sel = 2;
	IoReg_Write32(TC_TChdr_P_LUT_CTRL0_reg,tc_tchdr_p_lut_ctrl0.regValue);

//2.
	status_acc_ready = 0;
	cnt =10000;
	while( (cnt--) && (status_acc_ready!=1)	) { /*wait for finishing writing*/
		tc_tchdr_p_lut_ctrl2.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL2_reg);
		status_acc_ready = tc_tchdr_p_lut_ctrl2.p_lut_acc_ready;
	}
	if (status_acc_ready != 1) {
		VIPprintf(" TC_P_LUT read error. (Can not access!), return\n");
		return -1;
	}


for(i=0; i<33 ; i++){
//3.
	tc_tchdr_p_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL1_reg);
	tc_tchdr_p_lut_ctrl1.p_lut_read_en = 1;
	IoReg_Write32(TC_TChdr_P_LUT_CTRL1_reg,tc_tchdr_p_lut_ctrl1.regValue);

//4.
	status_read_enable =1;
	cnt = 10000;
	while( (cnt--) && status_read_enable) { /*wait for read enable = 0*/
		tc_tchdr_p_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL1_reg);
		status_read_enable = tc_tchdr_p_lut_ctrl1.p_lut_read_en;
	}
	if (status_read_enable == 1) {
		VIPprintf(" TC_P_LUT read error, return\n");
		return -2;
	}


	tc_tchdr_p_lut_ctrl2.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL2_reg);
	if ( tc_tchdr_p_lut_ctrl2.p_lut_rw_addr != i + 1) {
		VIPprintf(" TC_P_LUT write error : p_lut_rw_addr, return\n");
		return -3;
	}

		read_reg_ptr[i] = IoReg_Read32(TC_TChdr_P_LUT_RD_DATA_reg);


}//end for

//5.
	tc_tchdr_p_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_P_LUT_CTRL0_reg);
	tc_tchdr_p_lut_ctrl0.p_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_P_LUT_CTRL0_reg,tc_tchdr_p_lut_ctrl0.regValue);

	return 0;
}

void drvif_color_set_TC_D_LUT_Step_Threshold(DRV_TCHDR_D_lut_step_thl *ptr)
{

	tc_tchdr_d_lut_step_RBUS tc_tchdr_d_lut_step;
	tc_tchdr_d_lut_threshold0_RBUS tc_tchdr_d_lut_threshold0;
	tc_tchdr_d_lut_threshold1_RBUS tc_tchdr_d_lut_threshold1;

	tc_tchdr_d_lut_step.regValue 	   = IoReg_Read32(TC_TChdr_D_LUT_STEP_reg);
	tc_tchdr_d_lut_threshold0.regValue = IoReg_Read32(TC_TChdr_D_LUT_THRESHOLD0_reg);
	tc_tchdr_d_lut_threshold1.regValue = IoReg_Read32(TC_TChdr_D_LUT_THRESHOLD1_reg);


	tc_tchdr_d_lut_step.dlut_step0= ptr->tchdr_dlut_step0;
	tc_tchdr_d_lut_step.dlut_step1= ptr->tchdr_dlut_step1;
	tc_tchdr_d_lut_step.dlut_step2= ptr->tchdr_dlut_step2;
	tc_tchdr_d_lut_step.dlut_step3= ptr->tchdr_dlut_step3;

	tc_tchdr_d_lut_threshold0.dlut_threshold0 = ptr->tchdr_dlut_threshold0;
	tc_tchdr_d_lut_threshold0.dlut_threshold1 = ptr->tchdr_dlut_threshold1;
	tc_tchdr_d_lut_threshold1.dlut_threshold2 = ptr->tchdr_dlut_threshold2;


	IoReg_Write32(TC_TChdr_D_LUT_STEP_reg, tc_tchdr_d_lut_step.regValue);
	IoReg_Write32(TC_TChdr_D_LUT_THRESHOLD0_reg, tc_tchdr_d_lut_threshold0.regValue);
	IoReg_Write32(TC_TChdr_D_LUT_THRESHOLD1_reg, tc_tchdr_d_lut_threshold1.regValue);

}



/*D LUT Read*/
void drvif_color_set_TC_Read_D_LUT(unsigned int *read_reg_ptr_R, unsigned int *read_reg_ptr_G, unsigned int *read_reg_ptr_B)
{
	unsigned char status_read_en;
	unsigned char i=0;
	unsigned short cnt;

	tc_tchdr_d_lut_ctrl0_RBUS tc_tchdr_d_lut_ctrl0;
	tc_tchdr_d_lut_ctrl1_RBUS tc_tchdr_d_lut_ctrl1;
	//tc_tchdr_d_lut_wr_data_RBUS tc_tchdr_d_lut_wr_data;
	tc_tchdr_enable_RBUS tc_tchdr_enable;

	//tc_tchdr_d_lut_wr_data.regValue = IoReg_Read32(TC_TChdr_D_LUT_WR_DATA_reg);

//1.
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);


	tc_tchdr_d_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL0_reg);
	tc_tchdr_d_lut_ctrl0.d_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_D_LUT_CTRL0_reg,tc_tchdr_d_lut_ctrl0.regValue);

	tc_tchdr_d_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL0_reg);
	tc_tchdr_d_lut_ctrl0.d_lut_rw_sel = 2;
	IoReg_Write32(TC_TChdr_D_LUT_CTRL0_reg,tc_tchdr_d_lut_ctrl0.regValue);



 	for(i=0;i<33;i++){
//2
	tc_tchdr_d_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL1_reg);
	tc_tchdr_d_lut_ctrl1.d_lut_write_en = 0;
	IoReg_Write32(TC_TChdr_D_LUT_CTRL1_reg,tc_tchdr_d_lut_ctrl1.regValue);

	tc_tchdr_d_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL1_reg);
	tc_tchdr_d_lut_ctrl1.d_lut_read_en = 1;
	IoReg_Write32(TC_TChdr_D_LUT_CTRL1_reg,tc_tchdr_d_lut_ctrl1.regValue);


//3.
		status_read_en = 1;
		cnt = 10000;
		while( (cnt--) && status_read_en) { /*wait for finishing writing*/
			tc_tchdr_d_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL1_reg);
			status_read_en = tc_tchdr_d_lut_ctrl1.d_lut_read_en;
		}

		if (status_read_en == 1) {
			VIPprintf(" TC_D_LUT read error, return\n");
			return;
		}
		if ( tc_tchdr_d_lut_ctrl1.d_lut_rw_addr != i + 1) {
			VIPprintf(" TC_D_LUT write error : d_lut_rw_addr, return\n");
			return;
		}

		read_reg_ptr_R[i] = IoReg_Read32(TC_TChdr_D_LUT_RD_DATA0_reg);
		read_reg_ptr_G[i] = IoReg_Read32(TC_TChdr_D_LUT_RD_DATA1_reg);
		read_reg_ptr_B[i] = IoReg_Read32(TC_TChdr_D_LUT_RD_DATA2_reg);

	}//end for

//4
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);

	tc_tchdr_d_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL0_reg);
	tc_tchdr_d_lut_ctrl0.d_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_D_LUT_CTRL0_reg,tc_tchdr_d_lut_ctrl0.regValue);

}


/*D LUT Write*/
void drvif_color_set_TC_Write_D_LUT(unsigned short *ptr_R, unsigned short *ptr_G, unsigned short *ptr_B)
{
	unsigned char status;
	unsigned char i=0;
	unsigned short cnt;

	//unsigned char tmp_d_lut_rw_addr=0;

	tc_tchdr_d_lut_ctrl0_RBUS tc_tchdr_d_lut_ctrl0;
	tc_tchdr_d_lut_ctrl1_RBUS tc_tchdr_d_lut_ctrl1;
	tc_tchdr_d_lut_wr_data0_RBUS tc_tchdr_d_lut_wr_data0;
	tc_tchdr_d_lut_wr_data1_RBUS tc_tchdr_d_lut_wr_data1;
	tc_tchdr_d_lut_wr_data2_RBUS tc_tchdr_d_lut_wr_data2;
	tc_tchdr_enable_RBUS tc_tchdr_enable;

	tc_tchdr_d_lut_wr_data0.regValue = IoReg_Read32(TC_TChdr_D_LUT_WR_DATA0_reg);
	tc_tchdr_d_lut_wr_data1.regValue = IoReg_Read32(TC_TChdr_D_LUT_WR_DATA1_reg);
	tc_tchdr_d_lut_wr_data2.regValue = IoReg_Read32(TC_TChdr_D_LUT_WR_DATA2_reg);

//1.
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);


    tc_tchdr_d_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL0_reg);
	tc_tchdr_d_lut_ctrl0.d_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_D_LUT_CTRL0_reg,tc_tchdr_d_lut_ctrl0.regValue);


    tc_tchdr_d_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL0_reg);
	tc_tchdr_d_lut_ctrl0.d_lut_rw_sel = 1;
	IoReg_Write32(TC_TChdr_D_LUT_CTRL0_reg,tc_tchdr_d_lut_ctrl0.regValue);


 	for(i=0;i<33;i++){
	// while(tmp_d_lut_rw_addr < 32){
	//2.
		tc_tchdr_d_lut_wr_data0.d_wr_lut_data0 = *ptr_R++;
		tc_tchdr_d_lut_wr_data0.d_wr_lut_data1 = *ptr_R++;
		IoReg_Write32(TC_TChdr_D_LUT_WR_DATA0_reg,tc_tchdr_d_lut_wr_data0.regValue);
		tc_tchdr_d_lut_wr_data1.d_wr_lut_data2 = *ptr_G++;
		tc_tchdr_d_lut_wr_data1.d_wr_lut_data3 = *ptr_G++;
		IoReg_Write32(TC_TChdr_D_LUT_WR_DATA1_reg,tc_tchdr_d_lut_wr_data1.regValue);
		tc_tchdr_d_lut_wr_data2.d_wr_lut_data4 = *ptr_B++;
		tc_tchdr_d_lut_wr_data2.d_wr_lut_data5 = *ptr_B++;
		IoReg_Write32(TC_TChdr_D_LUT_WR_DATA2_reg,tc_tchdr_d_lut_wr_data2.regValue);

        tc_tchdr_d_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL1_reg);
		tc_tchdr_d_lut_ctrl1.d_lut_write_en = 1;
		IoReg_Write32(TC_TChdr_D_LUT_CTRL1_reg,tc_tchdr_d_lut_ctrl1.regValue);

        tc_tchdr_d_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL1_reg);
		tc_tchdr_d_lut_ctrl1.d_lut_read_en = 0;
		IoReg_Write32(TC_TChdr_D_LUT_CTRL1_reg,tc_tchdr_d_lut_ctrl1.regValue);

	//3.
		status = 1;
		cnt = 10000;
		while( (cnt--) && status) { /*wait for finishing writing*/
			tc_tchdr_d_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL1_reg);
			status = tc_tchdr_d_lut_ctrl1.d_lut_write_en;
		}
		if (status == 1) {
			VIPprintf(" TC_S_LUT write error, return\n");
			return;
		}
		if ( tc_tchdr_d_lut_ctrl1.d_lut_rw_addr != i + 1) {
			VIPprintf(" TC_S_LUT write error : d_lut_rw_addr, return\n");
			return;
		}

		//tc_tchdr_d_lut_ctrl1.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL1_reg);
		// tmp_d_lut_rw_addr = tc_tchdr_d_lut_ctrl1.c_lut_rw_addr;


	}//end for

//4
	tc_tchdr_enable.regValue = IoReg_Read32(TC_TChdr_enable_reg);
	tc_tchdr_enable.tc_enable = 1;
	IoReg_Write32(TC_TChdr_enable_reg,tc_tchdr_enable.regValue);

    tc_tchdr_d_lut_ctrl0.regValue = IoReg_Read32(TC_TChdr_D_LUT_CTRL0_reg);
	tc_tchdr_d_lut_ctrl0.d_lut_rw_sel = 0;
	IoReg_Write32(TC_TChdr_D_LUT_CTRL0_reg,tc_tchdr_d_lut_ctrl0.regValue);

}

#if 1//juwen, merlin3, tc

void drvif_fwif_color_set_TC_Enable(unsigned char src_idx, bool enable)
{
	drvif_color_set_TC_Enable(enable);
	drvif_color_set_TC_swap_vgip_vyu2yuv();//juwen,1215,debug
}


void drvif_fwif_color_set_TC_Read_C_LUT(unsigned short *c_lut_coef_read_ptr)
{
	//if (IoReg_Read32(0xb802e4f4) & 0x1)
		drvif_color_set_TC_Read_C_LUT(TCHDR_COEF_C_LUT_TBL_ReadReg);
	//if (IoReg_Read32(0xb802e4f4) & 0x2)
		decode_TC_Read_LUTs_regValue(TCHDR_COEF_C_LUT_TBL_ReadReg, c_lut_coef_read_ptr);//(input, output)

}


void drvif_fwif_color_set_TC_Read_I_LUT(unsigned short *i_lut_coef_read_ptr)
{

	drvif_color_set_TC_Read_I_LUT(TCHDR_COEF_I_LUT_TBL_ReadReg);
	decode_TC_Read_LUTs_regValue(TCHDR_COEF_I_LUT_TBL_ReadReg, i_lut_coef_read_ptr);//(input, output)

}

void drvif_fwif_color_set_TC_Read_S_LUT(unsigned short *s_lut_coef_read_ptr)
{

	drvif_color_set_TC_Read_S_LUT(TCHDR_COEF_S_LUT_TBL_ReadReg);
	decode_TC_Read_LUTs_regValue(TCHDR_COEF_S_LUT_TBL_ReadReg, s_lut_coef_read_ptr);//(input, output)

}

void drvif_fwif_color_set_TC_Read_P_LUT(unsigned short *p_lut_coef_read_ptr)
{

	drvif_color_set_TC_Read_P_LUT(TCHDR_COEF_P_LUT_TBL_ReadReg);
	decode_TC_Read_LUTs_regValue(TCHDR_COEF_P_LUT_TBL_ReadReg, p_lut_coef_read_ptr);//(input, output)

}

/*
NOTE : juwen, 20160629
In C model : R/G/B use the same D_LUT table <=> set D_lut_Red_idx = D_lut_Green_idx =D_lut_Blue_idx

However, in the following API we read R/G/B D_LUT table separate.
*/
void drvif_fwif_color_set_TC_Read_D_LUT(unsigned short *d_lut_red_coef_read_ptr,unsigned short *d_lut_green_coef_read_ptr,unsigned short *d_lut_blue_coef_read_ptr)
{
	drvif_color_set_TC_Read_D_LUT(TCHDR_COEF_D_LUT_RED_TBL_ReadReg, TCHDR_COEF_D_LUT_GREEN_TBL_ReadReg, TCHDR_COEF_D_LUT_BLUE_TBL_ReadReg);
	decode_TC_Read_LUTs_regValue(TCHDR_COEF_D_LUT_RED_TBL_ReadReg, d_lut_red_coef_read_ptr);//(input, output)
	decode_TC_Read_LUTs_regValue(TCHDR_COEF_D_LUT_GREEN_TBL_ReadReg, d_lut_green_coef_read_ptr);//(input, output)
	decode_TC_Read_LUTs_regValue(TCHDR_COEF_D_LUT_BLUE_TBL_ReadReg, d_lut_blue_coef_read_ptr);//(input, output)
}





void drvif_fwif_color_set_TC_v130_Range_Adaptation(unsigned char src_idx, unsigned char TableIdx)
{

	DRV_TCHDR_RangeAdaption data;
	extern DRV_TCHDR_Table TCHDR_Table[5];

	data.tchdr_footroom_int= TCHDR_Table[TableIdx].TCHDR_RangeAdaption.tchdr_footroom_int;
	data.tchdr_l_headroom_int= TCHDR_Table[TableIdx].TCHDR_RangeAdaption.tchdr_l_headroom_int;
	data.tchdr_c_headroom_int= TCHDR_Table[TableIdx].TCHDR_RangeAdaption.tchdr_c_headroom_int;
	data.tchdr_inv_y_limited_range_ratio_int= TCHDR_Table[TableIdx].TCHDR_RangeAdaption.tchdr_inv_y_limited_range_ratio_int;
	data.tchdr_inv_chroma_limited_range_ratio_int= TCHDR_Table[TableIdx].TCHDR_RangeAdaption.tchdr_inv_chroma_limited_range_ratio_int;

	drvif_color_set_TC_Range_Adaptation( (DRV_TCHDR_RangeAdaption*) &data);
}




//juwen, merlin3, tc
//static void drvif_fwif_color_set_TC_v130_Compute_muA_muB(SL_HDR1_metadata *sl_hdr1_metadata, unsigned short *muA, unsigned short *muB)
void drvif_fwif_color_set_TC_v130_Compute_muA_muB(SL_HDR1_metadata *sl_hdr1_metadata, unsigned short *muA, unsigned short *muB)
{
    static unsigned short muA_709[16] =  { 0, 1966, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8191 };
    static unsigned short muA_2020[16] = { 0, 1966, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8191 };
    static unsigned short muB_709[16] =  { 0, 6554, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7952 };
    static unsigned short muB_2020[16] = { 0, 6554, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7244 };
    //int *muA_tmp;
    //int *muB_tmp;

    int i, valNu = 0;

    if (!sl_hdr1_metadata->payloadMode) {
        // valNu, muA and muB compute : 13 bits by construction
        if (sl_hdr1_metadata->u.variables.saturationGainNumVal > 2) {
          for (i = 1; i < sl_hdr1_metadata->u.variables.saturationGainNumVal - 1; i++){
              valNu = 2 * valNu + (sl_hdr1_metadata->u.variables.saturationGainX[i] % 2);
              sl_hdr1_metadata->u.variables.saturationGainX[i] = sl_hdr1_metadata->u.variables.saturationGainX[i] - (sl_hdr1_metadata->u.variables.saturationGainX[i] % 2);
          }
        }
        else
          valNu = 1;

		if(valNu >= 16)
		{
			VIPprintf("Error: muA_709/muA_2020/muB_709/muB_2020 of size 16 use index value greater than 16\n");
			/*juwen, 170614, review, id=153177, 153174, 153176, 153181*/
			return;
		}

        if (!sl_hdr1_metadata->sdrPicColourSpace) {
          *muA = muA_709[valNu];
          *muB = muB_709[valNu];
        }
        else {
          *muA = muA_2020[valNu];
          *muB = muB_2020[valNu];
        }
    }
    else {

      *muA = sl_hdr1_metadata->u.tables.chromaToLumaInjectionMuA;
      *muB = sl_hdr1_metadata->u.tables.chromaToLumaInjectionMuB;


    }
}




void drvif_fwif_color_set_TC_v130_L_Compute(unsigned short *muA, unsigned short *muB)
{

	DRV_TCHDR_l_compute data;

	data.tchdr_alpha_a= *muA;
	data.tchdr_alpha_b= *muB;

	drvif_color_set_TC_L_Compute( (DRV_TCHDR_l_compute*) &data);
}



void drvif_fwif_color_set_TC_v130_T_Compute(signed short  *OCT)
{

	DRV_TCHDR_T_compute data;

	data.tchdr_oct0= OCT[0];
	data.tchdr_oct1= OCT[1];
	data.tchdr_oct2= OCT[2];

	drvif_color_set_TC_T_Compute( (DRV_TCHDR_T_compute*) &data);
}



void drvif_fwif_color_set_TC_v130_M_Compute(signed short  *OCT)
{

	DRV_TCHDR_M_compute data;

	data.tchdr_oct3= OCT[3];
	data.tchdr_oct4= OCT[4];
	data.tchdr_oct5= OCT[5];
	data.tchdr_oct6= OCT[6];

	drvif_color_set_TC_M_Compute( (DRV_TCHDR_M_compute*) &data);
}

void drvif_fwif_color_set_TC_v130_Write_C_LUT(unsigned short *C_LUT)
{
	drvif_color_set_TC_Write_C_LUT(C_LUT);
}


void drvif_fwif_color_set_TC_v130_Write_P_LUT(unsigned short *P_LUT)
{
	drvif_color_set_TC_Write_P_LUT(P_LUT);
}


/**
 * @brief Filling method for the D_LUT depending on the screen Gamma characteristic
 *
 * @param curve[in] :
 * @param PeakLuminance[in] :
 * @param D_LUT[out] :
 * @param D_LUT_THRESHOLD[out] :
 * @param D_LUT_STEP[out] :
 *
 * @return Void
 *
*/



/**
 * @brief Filling method for the D_LUT depending on the screen Gamma characteristic
 *
 * @param curve[in] :
 * @param PeakLuminance[in] :
 * @param D_LUT[out] :
 * @param D_LUT_THRESHOLD[out] :
 * @param D_LUT_STEP[out] :
 *
 * @return Void
*/

//Fill_D_LUT(proc_mode, display_OETF, display_Brightness, D_LUT, D_LUT_THRESHOLD, D_LUT_STEP);
void drvif_fwif_color_set_TC_v130_Fill_D_LUT(int proc_mode, int curve, int MaxTargetDisplayLum, unsigned short *D_LUT, unsigned short *D_LUT_THRESHOLD, unsigned short *D_LUT_STEP)
{

	DRV_TCHDR_D_lut_step_thl data;

	extern DRV_TCHDR_v130_D_Table_settings TCHDR_v130_D_Table_settings[NUM_D_LUT_DEFAULT];

	int TableIdx = 0;/*juwen, 170614, review, id=153180*/

	switch (curve) {
	    case BT1886:
	      if (proc_mode == SDR2MDR) {
		  TableIdx = 0;
	      }
	      else {
		  TableIdx = 1;
	      }
	      break;
	    case PQ:
	      if (proc_mode == SDR2MDR) {
	        switch (MaxTargetDisplayLum)
	        {
	          case 100:  TableIdx = 2;   break;
	          case 150:  TableIdx = 3;   break;
	          case 200:  TableIdx = 4;   break;
	          case 250:  TableIdx = 5;   break;
	          case 300:  TableIdx = 6;   break;
	          case 350:  TableIdx = 7;   break;
	          case 400:  TableIdx = 8;   break;
	          case 450:  TableIdx = 9;   break;
	          case 500:  TableIdx = 10;   break;
	          case 550:  TableIdx = 11;   break;
	          case 600:  TableIdx = 12;   break;
	          case 650:  TableIdx = 13;   break;
	          case 700:  TableIdx = 14;   break;
	          case 750:  TableIdx = 15;   break;
	          case 800:  TableIdx = 16;   break;
	          case 850:  TableIdx = 17;   break;
	          case 900:  TableIdx = 18;   break;
	          case 950:  TableIdx = 19;   break;
	          case 1000: TableIdx = 20;  break;
	          case 1050: TableIdx = 21;  break;
	          case 1100: TableIdx = 22;  break;
	          case 1150: TableIdx = 23;  break;
	          case 1200: TableIdx = 24;  break;
	          case 1250: TableIdx = 25;  break;
	          case 1300: TableIdx = 26;  break;
	          case 1350: TableIdx = 27;  break;
	          case 1400: TableIdx = 28;  break;
	          case 1450: TableIdx = 29;  break;
	          case 1500: TableIdx = 30;  break;
	          case 1550: TableIdx = 31;  break;
	          case 1600: TableIdx = 32;  break;
	          case 1650: TableIdx = 33;  break;
	          case 1700: TableIdx = 34;  break;
	          case 1750: TableIdx = 35;  break;
	          case 1800: TableIdx = 36;  break;
	          case 1850: TableIdx = 37;  break;
	          case 1900: TableIdx = 38;  break;
	          case 1950: TableIdx = 39;  break;
	          case 2000: TableIdx = 40;  break;
	          default:
	            //fprintf(stderr, "Can only handle peak luminance from 100 to 2000 nits\n");
		     VIPprintf("TC : Fill_D_LUT : Can only handle peak luminance from 100 to 2000 nits\n !!!\n");

	            break;
	        }
	      }
	      else {
			TableIdx = 41;
	      }
	      break;
	    case BT709:
	      if (proc_mode == SDR2MDR) {
			TableIdx = 42;
	      }
	      break;
	    case ARIB:
	      if (proc_mode == SDR2MDR) {
			TableIdx = 43;
	      }
	      break;
	    default:
	      //fprintf(stderr, "curve not handled\n");
		VIPprintf("TC : Fill_D_LUT : curve not handled\n !!!\n");
	      return;
  }

	memcpy(D_LUT, &(TCHDR_v130_D_Table_settings[TableIdx].TCHDR_v130_COEF_D_Lut),sizeof(unsigned short)*65);
	memcpy(D_LUT_STEP, &(TCHDR_v130_D_Table_settings[TableIdx].TCHDR_v130_D_lut_step),sizeof(unsigned short)*4);
	memcpy(D_LUT_THRESHOLD, &(TCHDR_v130_D_Table_settings[TableIdx].TCHDR_v130_D_lut_thl),sizeof(unsigned short)*3);

}


void drvif_fwif_color_set_TC_v130_Write_D_LUT(unsigned short *D_LUT)
{
        drvif_color_set_TC_Write_D_LUT(D_LUT, D_LUT, D_LUT);//juwen, note : in C model R/G/B use the same D_LUT
}



void drvif_fwif_color_set_TC_v130_D_LUT_Step_Threshold(unsigned short *D_LUT_THRESHOLD, unsigned short *D_LUT_STEP)
{

	DRV_TCHDR_D_lut_step_thl data;


	data.tchdr_dlut_step0= D_LUT_STEP[0];
	data.tchdr_dlut_step1= D_LUT_STEP[1];
	data.tchdr_dlut_step2= D_LUT_STEP[2];
	data.tchdr_dlut_step3= D_LUT_STEP[3];

	data.tchdr_dlut_threshold0= D_LUT_THRESHOLD[0];
	data.tchdr_dlut_threshold1= D_LUT_THRESHOLD[1];
	data.tchdr_dlut_threshold2= D_LUT_THRESHOLD[2];

	drvif_color_set_TC_D_LUT_Step_Threshold( (DRV_TCHDR_D_lut_step_thl*) &data);
}


void drvif_fwif_color_set_TC_v130_Write_I_LUT(unsigned char src_idx,unsigned char I_lut_idx)
{

	extern DRV_TCHDR_COEF_I_lut TCHDR_COEF_I_LUT_TBL;

	unsigned short *i_lut_coef_ptr = &(TCHDR_COEF_I_LUT_TBL.TCHDR_COEF_I_Lut[I_lut_idx][0]);
	drvif_color_set_TC_Write_I_LUT(i_lut_coef_ptr);
}





void drvif_fwif_color_set_TC_v130_Write_S_LUT(unsigned char src_idx,unsigned char S_lut_idx)
{
	extern DRV_TCHDR_COEF_S_lut TCHDR_COEF_S_LUT_TBL;

	unsigned short *s_lut_coef_ptr = &(TCHDR_COEF_S_LUT_TBL.TCHDR_COEF_S_Lut[S_lut_idx][0]);
	drvif_color_set_TC_Write_S_LUT(s_lut_coef_ptr);
}


#if 1//juwen, drvif_fwif_color_set_TC_v130_Compute_C_LUT and its sub function
static int apply_pq(int L_in)
{
  enum { L_REF = (10000 << SHIFT) };
  enum { LOG2_SFI_W32F15 = 22713 };
  enum { M1 = 10440 };
  enum { M2 = 5167104 };
  enum { C1 = 54784 };
  enum { C2 = 1235456 };
  enum { C3 = 1224704 };
  int res, num, den, is_lsb_set;

  /* pow(L, m1) */
  res = sfi_w32f15_div(L_in << 1, L_REF);
  res = sfi_w32f15_log(res) - LOG2_SFI_W32F15;
  res = sfi_w32f15_mult(res, M1);
  is_lsb_set = res & 0x1;
  res >>= 1;
  res = sfi_w32f15_exp(res);
  res <<= 1;
  if (is_lsb_set)
    res += (res + (1 << 15)) >> 16;
  /* c1 + c2 * pow(L, m1) */
  num = sfi_w32f15_mult(C2, res);
  ++num;
  num >>= 1;
  num += C1;
  /* 1 + c3 * pow(L, m1) */
  den = sfi_w32f15_mult(C3, res);
  ++den;
  den >>= 1;
  den += ONE;
  /* pow((c1 + c2 * pow(L, m1)) / (1 + c3 * pow(L, m1)), m2)  */
  res = sfi_w32f15_div(num << 1, den);
  res = sfi_w32f15_log(res) - LOG2_SFI_W32F15;
  res = sfi_w32f15_mult(res, M2);
  is_lsb_set = res & 0x1;
  res >>= 1;
  res = sfi_w32f15_exp(res);
  res <<= 1;
  if (is_lsb_set)
    res += (res + (1 << 15)) >> 16;

  return res;
}








/**
 * @brief Compute the C_LUT (called once per frame)
 *
 * @param mode : "PRIME over SDR" or "PRIME over HDR"
 * @param sl_hdr1_metadata[in] : current metadata
 * @param TargetDisplayLuminance : display brightness
 * @param C_LUT[out] : pointer to the computed C_LUT
 *
 * @return void
*/
void drvif_fwif_color_set_TC_v130_Compute_C_LUT(int proc_mode, SL_HDR1_metadata *sl_hdr1_metadata, int TargetDisplayLuminance, unsigned short *C_LUT)
{
  unsigned short C_REF_LUT[65] = { 2047, 1236, 577, 414, 300, 245, 200, 173, 153, 135, 122, 111, 102, 94, 87, 82, 76, 72, 68, 64, 61, 58, 55, 53, 51, 49, 47, 45, 44, 42, 41, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 30, 29, 28, 28, 27, 27, 26, 25, 25, 24, 24, 23, 23, 23, 22, 22, 21, 21, 21, 20, 20, 20, 19, 19 }; // 14b
  static unsigned short C_REF_LUT_INV[64] = { 4096, 2048, 1365, 1024, 819, 683, 585, 512, 455, 410, 372, 341, 315, 293, 273, 256, 241, 228, 216, 205, 195, 186, 178, 171, 164, 158, 152, 146, 141, 137, 132, 128, 124, 120, 117, 114, 111, 108, 105, 102, 100, 98, 95, 93, 91, 89, 87, 85, 84, 82, 80, 79, 77, 76, 74, 73, 72, 71, 69, 68, 67, 66, 65, 64 }; // 16b
  static unsigned short C_REF_LUT_GAMMA_INV[64] = { 12, 32, 56, 84, 115, 149, 185, 223, 263, 305, 348, 393, 440, 488, 537, 588, 640, 694, 748, 804, 861, 919, 978, 1038, 1099, 1161, 1224, 1287, 1352, 1418, 1485, 1552, 1620, 1690, 1760, 1830, 1902, 1974, 2047, 2121, 2196, 2271, 2347, 2424, 2502, 2580, 2659, 2738, 2818, 2899, 2981, 3063, 3146, 3229, 3313, 3398, 3483, 3569, 3655, 3742, 3830, 3918, 4007, 4096 }; // 22b
  int xl, xs, xt, c, i, j, j_last, sg_size, sg_x[8], sg_y[8], idx[8], sgf[65], betaP[65];

  if (proc_mode == HDR2MDR) {
    xl = apply_pq(sl_hdr1_metadata->hdrMasterDisplayMaxLuminance << SHIFT);
    xs = apply_pq(100 << SHIFT);
    xt = apply_pq(TargetDisplayLuminance << SHIFT);
    c = ONE - (((xt - xs) << SHIFT) + ((xl - xs) >> 1)) / (xl - xs);
    for (i = 1; i < 65; i++) {
      betaP[i] = C_REF_LUT_INV[i - 1] + ((c * C_REF_LUT_GAMMA_INV[i - 1] + (1 << (SHIFT + 5))) >> (SHIFT + 6));
      C_REF_LUT[i] = Max((betaP[i] + 1) >> 1, 1);
    }
  }

  if (!sl_hdr1_metadata->payloadMode) {
    if (sl_hdr1_metadata->u.variables.saturationGainNumVal > 0)
      sg_size = sl_hdr1_metadata->u.variables.saturationGainNumVal;
    else
      sg_size = 0;

    if (sl_hdr1_metadata->u.variables.saturationGainX[0] != 0 || sg_size == 0) {
      sg_size += 1;
      sg_x[0] = 0;
      sg_y[0] = 64;
      i = 0;
    }
    else {
      sg_x[0] = sl_hdr1_metadata->u.variables.saturationGainX[0];
      sg_y[0] = sl_hdr1_metadata->u.variables.saturationGainY[0];
      i = 1;
    }

    j = 1;
    while (i < sl_hdr1_metadata->u.variables.saturationGainNumVal) {
      sg_x[j] = sl_hdr1_metadata->u.variables.saturationGainX[i];
      sg_y[j] = sl_hdr1_metadata->u.variables.saturationGainY[i];
      i++;
      j++;
    }

    if (sg_x[sg_size - 1] != 255) {
      sg_size += 1;
      sg_x[sg_size - 1] = 255;
      sg_y[sg_size - 1] = 64;
    }

    for (i = 0; i < sg_size; i++) {
      sg_x[i] = sg_x[i] - (sg_x[i] % 2);
      idx[i] = (sg_x[i] + 2) >> 2; // 6b
    }

    j_last = idx[0];
    sgf[0] = sg_y[0] << 8; // 8b + 8b (precision) = 16b

    for (i = 1; i < sg_size; i++) {
      for (j = j_last+1; j <= idx[i]; j++) {
        // 6b * 8b * 8b (precision) / 6b = 16b
        sgf[j] = sgf[j_last] + ((((j - j_last) * (sg_y[i] - sg_y[i - 1])) << 8) + ((idx[i] - j_last) >> 1)) / (idx[i] - j_last);
      }
      j_last = idx[i];
    }

    C_LUT[0] = 2047;
    for (i = 1; i < 65; i++) {
      betaP[i] = (sgf[i] * ONE / C_REF_LUT[i]); // 6b + 2b (1 << 16 instead of 1 << 14) remaining integrated in 1 << 30 during inversion
      betaP[i] = ((1 << 30) + (betaP[i] >> 1)) / betaP[i]; // 30b = 14b (C_LUT quantization) + 8b (previous compute) + 8b (precision)
      C_LUT[i] = Min(betaP[i], (1 << 11) - 1);
    }
  }
  else {
    for (i = 0; i < 32; i++) {
      for (j = 0; j < 2; j++) {
        C_LUT[2 * i + j] = ((2 - j) * sl_hdr1_metadata->u.tables.colourCorrectionY[i] + j * sl_hdr1_metadata->u.tables.colourCorrectionY[i+1] + 1) >> 1;
      }
    }
    C_LUT[64] = sl_hdr1_metadata->u.tables.colourCorrectionY[32];
  }
}

#endif//juwen, drvif_fwif_color_set_TC_v130_Compute_C_LUT and its sub function

#if 1//juwen, drvif_fwif_color_set_TC_v130_Compute_P_LUT and its subfunction
static int Kappa[201] = {
       0,  56809,  65536,  70857,  74718,  77757,  80268,  82408,
   84274,  85929,  87417,  88769,  90007,  91150,  92211,  93201,
   94130,  95004,  95830,  96613,  97356,  98065,  98741,  99389,
  100009, 100605, 101179, 101731, 102263, 102778, 103276, 103757,
  104224, 104677, 105116, 105543, 105959, 106363, 106757, 107141,
  107515, 107881, 108237, 108586, 108926, 109260, 109586, 109905,
  110218, 110524, 110824, 111119, 111407, 111691, 111969, 112243,
  112511, 112775, 113034, 113289, 113540, 113787, 114029, 114268,
  114504, 114735, 114964, 115189, 115410, 115629, 115844, 116056,
  116266, 116472, 116676, 116877, 117076, 117272, 117466, 117657,
  117845, 118032, 118216, 118398, 118578, 118756, 118931, 119105,
  119277, 119447, 119615, 119781, 119945, 120108, 120269, 120428,
  120586, 120742, 120896, 121049, 121201, 121351, 121499, 121646,
  121792, 121936, 122079, 122221, 122361, 122500, 122638, 122774,
  122910, 123044, 123177, 123309, 123440, 123569, 123698, 123825,
  123952, 124077, 124201, 124325, 124447, 124569, 124689, 124809,
  124927, 125045, 125162, 125278, 125393, 125507, 125620, 125733,
  125845, 125956, 126066, 126175, 126284, 126391, 126498, 126605,
  126710, 126815, 126919, 127023, 127126, 127228, 127329, 127430,
  127530, 127629, 127728, 127826, 127924, 128021, 128117, 128213,
  128308, 128402, 128496, 128590, 128683, 128775, 128867, 128958,
  129048, 129139, 129228, 129317, 129406, 129494, 129581, 129668,
  129755, 129841, 129927, 130012, 130097, 130181, 130264, 130348,
  130431, 130513, 130595, 130676, 130758, 130838, 130919, 130998,
  131078, 131157, 131235, 131314, 131391, 131469, 131546, 131623,
  131699
};


static int apply_oetf(int x, int L)
{
  enum { EOTFRHO = (33 << SHIFT) };
  enum { L_REF = (10000 << SHIFT) };
  enum { LOG2_SFI_W32F15 = 22713 };
  enum { ONE_OVER_GAMMA = 27307 };
  int rho_minus1, res, num, den, is_lsb_set;

  /* rho(L) - 1 = (eotfrho - 1) * pow(L / Lref, 1/gamma) */
  rho_minus1 = EOTFRHO - ONE;
  res = sfi_w32f15_div(L << 1, L_REF);
  res = sfi_w32f15_log(res) - LOG2_SFI_W32F15;
  res = sfi_w32f15_mult(res, ONE_OVER_GAMMA);
  is_lsb_set = res & 0x1;
  res >>= 1;
  res = sfi_w32f15_exp(res);
  res <<= 1;
  if (is_lsb_set)
    res += (res + (1 << 15)) >> 16;
  rho_minus1 = sfi_w32f15_mult(rho_minus1, res);
  ++rho_minus1;
  rho_minus1 >>= 1;
  /* (rho(L) - 1) * pow(x, 1/gamma) */
  res = sfi_w32f15_log(x) - LOG2_SFI_W32F15;
  res = sfi_w32f15_mult(res, ONE_OVER_GAMMA);
  is_lsb_set = res & 0x1;
  res >>= 1;
  res = sfi_w32f15_exp(res);
  res <<= 1;
  if (is_lsb_set)
    res += (res + (1 << 15)) >> 16;
  res = sfi_w32f15_mult(rho_minus1, res);
  ++res;
  res >>= 1;
  /* (rho(L) - 1) * pow(x, 1/gamma) + 1 */
  res += ONE;
  /* log((rho(L) - 1) * pow(x, 1/gamma) + 1) / log(rho(L)) */
  num = (sfi_w32f15_log(res) - LOG2_SFI_W32F15) << 1;
  den = (sfi_w32f15_log(rho_minus1 + ONE) - LOG2_SFI_W32F15) << 1;
  res = sfi_w32f15_div(num << 1, den);

  return res;
}

/******************************************************************************
 * P-LUT SDR2HDR reconstruction
 ******************************************************************************/

/*
  Perceptual Uniform from Gamma
*/

extern int GammatoOETF[65];

/*
  Inverse Custom Curve
*/

static void invinterpolate_initialize(SL_HDR1_metadata *sl_hdr1_metadata, int *icc_x, int *icc_y, int *icc_size)
{
  int i, j;

  *icc_size = sl_hdr1_metadata->u.variables.tmOutputFineTuningNumVal;
  icc_x[0] = 0;
  icc_y[0] = 0;
  if (*icc_size > 0 && sl_hdr1_metadata->u.variables.tmOutputFineTuningX[0] == 0 && sl_hdr1_metadata->u.variables.tmOutputFineTuningY[0] == 0)
    i = 1;
  else {
    *icc_size += 1;
    i = 0;
  }

  if (sl_hdr1_metadata->u.variables.tmOutputFineTuningNumVal > 0 && sl_hdr1_metadata->u.variables.tmOutputFineTuningX[sl_hdr1_metadata->u.variables.tmOutputFineTuningNumVal - 1] == 255 && sl_hdr1_metadata->u.variables.tmOutputFineTuningY[sl_hdr1_metadata->u.variables.tmOutputFineTuningNumVal - 1] == 255);
  else
    *icc_size += 1;
  icc_x[*icc_size - 1] = ONE;
  icc_y[*icc_size - 1] = ONE;

  j = 1;
  while (j < *icc_size - 1) {
    icc_x[j] = sl_hdr1_metadata->u.variables.tmOutputFineTuningY[i] * 257 + (sl_hdr1_metadata->u.variables.tmOutputFineTuningY[i] & 128 ? 1 : 0);
    icc_y[j] = sl_hdr1_metadata->u.variables.tmOutputFineTuningX[i] * 257 + (sl_hdr1_metadata->u.variables.tmOutputFineTuningX[i] & 128 ? 1 : 0);
    i++;
    j++;
  }
}

static int invinterpolate(int pu, int *icc_x, int *icc_y, int icc_size)
{
  int y = pu, i = 0, delta_x, delta_y, x_tmp, y_tmp;

  if (icc_size > 2) {
    while (pu >= icc_x[i] && i < icc_size - 1)
      ++i;

    delta_x = icc_x[i] - icc_x[i - 1];
    delta_y = icc_y[i] - icc_y[i - 1];
    x_tmp = pu - icc_x[i - 1];
    y_tmp = icc_y[i - 1];

    y = Min((x_tmp * delta_y + (delta_x >> 1)) / delta_x + y_tmp, ONE);
  }

  return y;
}

/*
  Inverse ParaBoLa
*/

static void invparabola_initialize(SL_HDR1_metadata *sl_hdr1_metadata, int *ipbl_base_gain, int *ipbl_hgc, int *ipbl_one_div_a, int *ipbl_one_div_a_shift, int *ipbl_min_b_div_2a, int *ipbl_lb_b2_min_4ac_rb_div_4a2, int *ipbl_lb_b2_min_4ac_rb_div_4a2_shift, int *ipbl_ylow, int *ipbl_yhigh)
{
  unsigned char Lhdr_idx = sl_hdr1_metadata->hdrMasterDisplayMaxLuminance / 50;
  int kappa = Kappa[Lhdr_idx];
  int base_gain, hgc, midadj;
  int pa = 0, pb = 0, pc4 = 0, sh, xmid, xlow, xhigh, ylow, yhigh, den;
  int tmp, num, precision, prec1, prec2, prec3, prec4, prec5, prec6, prec7, sh1, sh2;

  base_gain = (sfi_w32f15_mult(kappa << (SHIFT - 4), HALF + ((sl_hdr1_metadata->u.variables.shadowGain * 257 + 1) >> 1)) + (1 << (SHIFT - 4))) >> (SHIFT - 3);
  hgc = (sl_hdr1_metadata->u.variables.highlightGain * 257 + 1) >> 1;
  midadj = sl_hdr1_metadata->u.variables.midToneWidthAdjFactor * 257 + (sl_hdr1_metadata->u.variables.midToneWidthAdjFactor & 128 ? 1 : 0);

  if (midadj) {
    /* pa = -0.5 * (base_gain - hgc) / midadj */
    precision = 6;
    pa = base_gain - hgc;
    if (TC_ABS(pa) < 1 << 17) ++precision;
    if (TC_ABS(pa) < 1 << 16) ++precision;
    if (TC_ABS(pa) < 1 << 15) ++precision;
    if (midadj > 1 << 9)  ++precision;
    if (midadj > 1 << 10) ++precision;
    if (midadj > 1 << 11) ++precision;
    if (midadj > 1 << 12) ++precision;
    if (midadj > 1 << 13) ++precision;
    if (midadj > 1 << 14) ++precision;
    if (midadj > 1 << 15) ++precision;
    pa = sfi_w32f15_div(pa << precision, midadj);
    pa = -(pa >> precision);

    /* pb = (1 - hgc) / midadj + (base_gain + hgc) / 2 */
    precision = 5;
    pb = ONE - hgc;
    if (TC_ABS(pb) < 1 << 15) ++precision;
    if (TC_ABS(pb) < 1 << 14) ++precision;
    if (midadj > 1 << 9)  ++precision;
    if (midadj > 1 << 10) ++precision;
    if (midadj > 1 << 11) ++precision;
    if (midadj > 1 << 12) ++precision;
    if (midadj > 1 << 13) ++precision;
    if (midadj > 1 << 14) ++precision;
    if (midadj > 1 << 15) ++precision;
    pb = sfi_w32f15_div(pb << (2 + precision), midadj);
    pb += (base_gain + hgc) << precision;
    pb = (pb + (1 << precision)) >> (1 + precision);

    /* pc4 (actually 4 * pc) = -4 * SQR((base_gain - hgc) * midadj - 2 * (1 - hgc)) / (8 * (base_gain - hgc) * midadj) */
    den = base_gain - hgc;
    precision = 13;
    den = sfi_w32f15_mult(den, midadj << precision);
    if (den == 0)
      pc4 = INT32_MIN;
    else {
      num = den;
      num -= (ONE - hgc) << (2 + precision);
      tmp = sfi_w32f15_div(num, den);
      num = sfi_w32f15_mult(num >> 9, tmp);
      num >>= (2 - 9 + precision);
      pc4 = -num;
    }
  }

  /* xlow  = (1 - hgc) / (base_gain - hgc) - midadj / 2 */
  /* xhigh = (1 - hgc) / (base_gain - hgc) + midadj / 2 */
  precision = 6;
  xmid = ONE - hgc;
  den = base_gain - hgc;
  if (den == 0)
    xmid = INT32_MAX;
  else
    xmid = sfi_w32f15_div((xmid << (1 + precision)), den);
  xmid = xmid >> precision;
  xlow = xmid - ((midadj + 1) >> 1);
  xhigh = xmid + ((midadj + 1) >> 1);

  /* ylow  = base_gain * xlow        */
  /* yhigh = hgc * xhigh + (1 - hgc) */
  yhigh = base_gain;
  yhigh = sfi_w32f15_mult(yhigh, xlow);
  ylow = (yhigh + 1) >> 1;
  xlow = hgc;
  xlow = sfi_w32f15_mult(xlow, xhigh);
  yhigh = (xlow + 1) >> 1;
  yhigh += ONE - hgc;
  yhigh = Min(yhigh, ONE);

  *ipbl_base_gain = base_gain;
  *ipbl_hgc = hgc;
  *ipbl_one_div_a = 0;
  *ipbl_one_div_a_shift = 0;
  *ipbl_min_b_div_2a = 0;
  *ipbl_lb_b2_min_4ac_rb_div_4a2 = 0;
  *ipbl_lb_b2_min_4ac_rb_div_4a2_shift = 0;
  *ipbl_ylow = ylow;
  *ipbl_yhigh = yhigh;

  if (!pa)
    return;

  /* ((b/2)^2 / a - c) / a = (b^2 - 4 * a * c) / (4 * a^2) */
  /* pa is always less than or equal to zero         */
  /* pb is always greater than to zero               */
  /* pc is always less than to zero                  */
  prec1 = msb32((unsigned int)TC_ABS(pb));
  prec3 = 8 - (prec1 - 15);
  tmp = (prec3 > 0) ? (pb << TC_ABS(prec3)) : (pb >> TC_ABS(prec3));
  // b * b
  tmp = sfi_w32f15_mult(tmp, tmp);
  if (prec3 < 0) {
    num = pb & ((1 << TC_ABS(prec3)) - 1);
    num = (2 * pb + num) * num;
  }
  else
    num = 0;
  tmp += num >> (15 + 2 * TC_ABS(prec3));
  prec4 = Max(16 - msb32((unsigned int)TC_ABS(pa)), 0);
  // b * b / a
  tmp = sfi_w32f15_div(tmp >> prec4, pa);
  prec5 = 2 * prec3 + 1;
  prec5 -= prec4 + 1;
  prec7 = 31 - msb32((unsigned int)TC_ABS(tmp));
  // b * b / a - 4 * c
  if (prec5 > 0)
    tmp -= (pc4 << TC_ABS(prec5));
  else {
    if (prec7 >= TC_ABS(prec5)) {
      tmp = (tmp << TC_ABS(prec5)) - pc4;
      prec5 = 0;
    }
    else
      tmp -= (pc4 >> TC_ABS(prec5));
  }
  prec2 = msb32((unsigned int)TC_ABS(pa));
  prec6 = 31 - msb32((unsigned int)TC_ABS(tmp)) - ((16 - prec2) > 0 ? 16 - prec2 : 0);
  // (b * b / a - 4 * c) / a
  if (prec6 > 0)
    tmp = sfi_w32f15_div((tmp<<TC_ABS(prec6)), pa);
  else
    tmp = sfi_w32f15_div((tmp>>TC_ABS(prec6)), pa);
  sh = 0; // shift
  while (tmp >> sh >= 1 << 23) {
    sh += 2;
  }
  *ipbl_lb_b2_min_4ac_rb_div_4a2 = tmp >> sh;
  *ipbl_lb_b2_min_4ac_rb_div_4a2_shift = prec5 + (prec6 - 1) + 2 - sh;

  precision = 3;
  tmp = -pb;
  tmp = sfi_w32f15_div(tmp << precision, pa);
  *ipbl_min_b_div_2a = (tmp + (1 << (precision - 1))) >> precision;

  tmp = pa;
  sh1 = sh2 = 0;
  while (TC_ABS(pa) << sh1 <= ONE)
    ++sh1;
  tmp = sfi_w32f15_div(1 << 30, pa << sh1);
  while (-tmp >> sh2 >= 1 << 23)
    ++sh2;
  if (sh2 > 0)
    *ipbl_one_div_a = (tmp - (1 << (sh2 - 1))) >> sh2;
  else
    *ipbl_one_div_a = tmp;
  *ipbl_one_div_a_shift = 13 - sh1 - sh2;
}

static int invparabola(int icc, int ipbl_base_gain, int ipbl_hgc, int ipbl_one_div_a, int ipbl_one_div_a_shift, int ipbl_min_b_div_2a, int ipbl_lb_b2_min_4ac_rb_div_4a2, int ipbl_lb_b2_min_4ac_rb_div_4a2_shift, int ipbl_ylow, int ipbl_yhigh)
{
  int perceptualpbl, sh1, sh2;

  if (icc >= ipbl_yhigh) {
    /* perceptualpbl = (icc + hgc - 1) / hgc */
    perceptualpbl = (icc + ipbl_hgc - ONE) << (SHIFT - 2);
    if (!perceptualpbl) {
      if (!ipbl_hgc) {
        perceptualpbl = ONE;
      }
    }
    else {
      if (ipbl_hgc) {
        perceptualpbl /= ipbl_hgc;
        perceptualpbl <<= 2;
      }
    }
  }
  else if (icc <= ipbl_ylow) {
    /* perceptualpbl = icc / base_gain */
    perceptualpbl =  icc << (SHIFT - 2);
    perceptualpbl /= (ipbl_base_gain + 2) >> 2;
  }
  else {
    /* perceptualpbl = (-pb + sqrt(pb * pb - 4 * pa * (pc - icc))) / (2 * pa) */
    sh1 = ipbl_lb_b2_min_4ac_rb_div_4a2_shift;
    sh2 = ipbl_one_div_a_shift;
    perceptualpbl = ipbl_lb_b2_min_4ac_rb_div_4a2;
    if (sh2 - sh1 > 0)
      perceptualpbl <<= TC_ABS(sh2 - sh1);
    else
      perceptualpbl >>= TC_ABS(sh2 - sh1);
    perceptualpbl += sfi_w32f15_mult(ipbl_one_div_a, icc) >> 1;

    if (perceptualpbl > 0) {
      if (sh2 & 0x1) {
        /* sh2 odd -> make even before entering sqrt16() */
        perceptualpbl >>= 1;
        --sh2;
      }

      sh1 = 0;
      if (perceptualpbl != 0) {
        while (((unsigned int)perceptualpbl << sh1) < (1 << 30)) {
          ++sh1;
          ++sh1;
        }
        perceptualpbl <<= sh1;
      }

      perceptualpbl = (int)sqrt16(perceptualpbl);

      /* Correct result of sqrt16() */
      sh1 += sh2 - SHIFT;
      sh1 = sh1 >> 1;
      perceptualpbl = (sh1 > 0) ? perceptualpbl >> TC_ABS(sh1) : perceptualpbl << TC_ABS(sh1);
    }
    else
      perceptualpbl = 0;

    perceptualpbl = ipbl_min_b_div_2a - perceptualpbl;
  }

  perceptualpbl = CLAMP(perceptualpbl, 0, ONE);

  return perceptualpbl;
}

/*
  Inverse Black & White Stretch
*/

static void invbwstretch_initialize(SL_HDR1_metadata *sl_hdr1_metadata, int *ibws_black_stretch, int *ibws_white_stretch)
{
  *ibws_black_stretch = (sl_hdr1_metadata->u.variables.tmInputSignalBlackLevelOffset * 257 + 4) >> 3;
  *ibws_white_stretch = (sl_hdr1_metadata->u.variables.tmInputSignalWhiteLevelOffset * 257 + 1) >> 1;
}

static int invbwstretch(int ipbl, int ibws_black_stretch, int ibws_white_stretch)
{
  unsigned int perceptualstretched;

  perceptualstretched = (ONE - ibws_white_stretch - ibws_black_stretch) >> 1;
  perceptualstretched *= ipbl;
  perceptualstretched = (perceptualstretched + (HALF >> 1)) >> (SHIFT - 1);
  perceptualstretched += ibws_black_stretch;

  perceptualstretched = CLAMP(perceptualstretched, 0, ONE);

  return perceptualstretched;
}

/*
  Inverse Black Gain Limiter
*/

static int invbglimiter_alpha[201] = {
      0, 42287, 36656, 33903, 32151, 30894, 29928, 29151,
  28506, 27956, 27481, 27062, 26690, 26355, 26052, 25775,
  25521, 25286, 25068, 24865, 24675, 24497, 24329, 24171,
  24021, 23878, 23743, 23614, 23491, 23373, 23261, 23153,
  23049, 22949, 22853, 22761, 22672, 22586, 22502, 22422,
  22344, 22268, 22195, 22123, 22054, 21987, 21921, 21858,
  21796, 21735, 21676, 21619, 21563, 21508, 21455, 21403,
  21351, 21302, 21253, 21205, 21158, 21112, 21067, 21023,
  20980, 20938, 20896, 20855, 20815, 20776, 20737, 20699,
  20662, 20625, 20589, 20554, 20519, 20485, 20451, 20418,
  20385, 20353, 20321, 20290, 20259, 20229, 20199, 20169,
  20140, 20112, 20083, 20056, 20028, 20001, 19974, 19948,
  19922, 19896, 19871, 19845, 19821, 19796, 19772, 19748,
  19724, 19701, 19678, 19655, 19633, 19610, 19588, 19567,
  19545, 19524, 19503, 19482, 19461, 19441, 19421, 19401,
  19381, 19361, 19342, 19323, 19304, 19285, 19266, 19248,
  19229, 19211, 19193, 19176, 19158, 19141, 19123, 19106,
  19089, 19072, 19056, 19039, 19023, 19007, 18991, 18975,
  18959, 18943, 18928, 18912, 18897, 18882, 18867, 18852,
  18837, 18822, 18808, 18793, 18779, 18765, 18751, 18737,
  18723, 18709, 18695, 18682, 18668, 18655, 18642, 18628,
  18615, 18602, 18589, 18577, 18564, 18551, 18539, 18526,
  18514, 18502, 18489, 18477, 18465, 18453, 18442, 18430,
  18418, 18406, 18395, 18383, 18372, 18361, 18349, 18338,
  18327, 18316, 18305, 18294, 18283, 18273, 18262, 18251,
  18241
};

static void invbglimiter_initialize(SL_HDR1_metadata *sl_hdr1_metadata, int *ibgl_alpha, int *ibgl_is_bypassed)
{
  unsigned char Lhdr_idx = sl_hdr1_metadata->hdrMasterDisplayMaxLuminance / 50;

  *ibgl_alpha = invbglimiter_alpha[Lhdr_idx];
  *ibgl_is_bypassed = (sl_hdr1_metadata->u.variables.tmInputSignalBlackLevelOffset == 0) ? 1 : 0;
}

static int invbglimiter(int pu, int ibws, int ibgl_is_bypassed, int ibgl_alpha)
{
  enum { IMPL_SHIFT = 14 };
  enum { IMPL_HALF = 1 << (IMPL_SHIFT - 1) };
  unsigned int glim = ibws;

  if (ibgl_is_bypassed == 0) {
    glim = pu * ibgl_alpha;
    glim += IMPL_HALF;
    glim >>= IMPL_SHIFT;
    glim = Min((int)glim, ibws);
  }

  glim = CLAMP(glim, 0, ONE - 1);

  return glim;
}

/*
  EOTF and Sqrt
*/

extern unsigned short EOTFtoSqrt_alpha[200];
extern int EOTFtoSqrt_quadrint_50(int x_in);
extern int EOTFtoSqrt_quadrint_100(int x_in);
extern int EOTFtoSqrt_quadrint_400(int x_in);
extern int EOTFtoSqrt_quadrint_700(int x_in);
extern int EOTFtoSqrt_quadrint_1000(int x_in);
extern int EOTFtoSqrt_quadrint_2000(int x_in);
extern int EOTFtoSqrt_quadrint_4000(int x_in);
extern int EOTFtoSqrt_quadrint_10000(int x_in);
static int (*EOTFtoSqrt_quadrint_low)(int x_in);
static int (*EOTFtoSqrt_quadrint_high)(int x_in);

static void EOTFtoSqrt_initialize(SL_HDR1_metadata *sl_hdr1_metadata, int TargetDisplayLuminance, unsigned short *sqrtY_alpha)
{
  unsigned char Ldisplay_idx = TargetDisplayLuminance / 50;

  *sqrtY_alpha = EOTFtoSqrt_alpha[Ldisplay_idx - 1];

  if (Ldisplay_idx <= 2) {
    EOTFtoSqrt_quadrint_low = EOTFtoSqrt_quadrint_50;
    EOTFtoSqrt_quadrint_high = EOTFtoSqrt_quadrint_100;
  }
  else if (Ldisplay_idx <= 8) {
    EOTFtoSqrt_quadrint_low = EOTFtoSqrt_quadrint_100;
    EOTFtoSqrt_quadrint_high = EOTFtoSqrt_quadrint_400;
  }
  else if (Ldisplay_idx <= 14) {
    EOTFtoSqrt_quadrint_low = EOTFtoSqrt_quadrint_400;
    EOTFtoSqrt_quadrint_high = EOTFtoSqrt_quadrint_700;
  }
  else if (Ldisplay_idx <= 20) {
    EOTFtoSqrt_quadrint_low = EOTFtoSqrt_quadrint_700;
    EOTFtoSqrt_quadrint_high = EOTFtoSqrt_quadrint_1000;
  }
  else if (Ldisplay_idx <= 40) {
    EOTFtoSqrt_quadrint_low = EOTFtoSqrt_quadrint_1000;
    EOTFtoSqrt_quadrint_high = EOTFtoSqrt_quadrint_2000;
  }
  else if (Ldisplay_idx <= 80) {
    EOTFtoSqrt_quadrint_low = EOTFtoSqrt_quadrint_2000;
    EOTFtoSqrt_quadrint_high = EOTFtoSqrt_quadrint_4000;
  }
  else {
    EOTFtoSqrt_quadrint_low = EOTFtoSqrt_quadrint_4000;
    EOTFtoSqrt_quadrint_high = EOTFtoSqrt_quadrint_10000;
  }
}

static int EOTFtoSqrt(int ibgl, unsigned short sqrtY_alpha)
{
  enum { IMPL_SHIFT = 12 };
  enum { IMPL_ONE = (1 << IMPL_SHIFT) };
  int ylow, yhigh, sqrtY;

  ylow = EOTFtoSqrt_quadrint_low(ibgl);
  yhigh = EOTFtoSqrt_quadrint_high(ibgl);

  sqrtY = (sqrtY_alpha * yhigh + (IMPL_ONE - sqrtY_alpha) * ylow + (1 << (IMPL_SHIFT + 2))) >> (IMPL_SHIFT + 3);
  sqrtY = CLAMP(sqrtY, 0, (1 << 13) - 1);

  return sqrtY;
}

/******************************************************************************
 * P-LUT HDR2MDR reconstruction
 ******************************************************************************/

/*
  Perceptual Uniform from ST2084
*/

extern unsigned short ST2084toOETF_max_e_brightness_input_table[201];
extern unsigned short ST2084toOETF_alpha_low_table[201];
extern unsigned short ST2084toOETF_alpha_mid_table[201];
extern unsigned short ST2084toOETF_alpha_high_table[201];
extern int ST2084toOETF_quadrint_100(int x_in);
extern int ST2084toOETF_quadrint_150(int x_in);
extern int ST2084toOETF_quadrint_300(int x_in);
extern int ST2084toOETF_quadrint_600(int x_in);
extern int ST2084toOETF_quadrint_1000(int x_in);
extern int ST2084toOETF_quadrint_3000(int x_in);
extern int ST2084toOETF_quadrint_6000(int x_in);
extern int ST2084toOETF_quadrint_10000(int x_in);
static int (*ST2084toOETF_quadrint_low)(int x_in);
static int (*ST2084toOETF_quadrint_high)(int x_in);

void ST2084toOETF_initialize(SL_HDR1_metadata *sl_hdr1_metadata, unsigned short *pu_max_e_brightness_input, unsigned short *pu_alpha_low, unsigned short *pu_alpha_mid, unsigned short *pu_alpha_high, int *pu_lower_idx, int *pu_upper_idx)
{
  enum { NUMBER_OF_INTERVALS = 7 };
  unsigned char Lhdr_idx = sl_hdr1_metadata->hdrMasterDisplayMaxLuminance / 50;
  int interval_lower_table_[NUMBER_OF_INTERVALS] = { 29, 29, 29, 29, 22, 18, 14 };
  int interval_upper_table_[NUMBER_OF_INTERVALS] = { 39, 39, 39, 39, 33, 27, 23 };

  *pu_max_e_brightness_input = ST2084toOETF_max_e_brightness_input_table[Lhdr_idx];
  *pu_alpha_low = ST2084toOETF_alpha_low_table[Lhdr_idx];
  *pu_alpha_mid = ST2084toOETF_alpha_mid_table[Lhdr_idx];
  *pu_alpha_high = ST2084toOETF_alpha_high_table[Lhdr_idx];

  if (Lhdr_idx > 6000/50) {
    ST2084toOETF_quadrint_high = ST2084toOETF_quadrint_10000;
    ST2084toOETF_quadrint_low = ST2084toOETF_quadrint_6000;
    *pu_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 1] << (SHIFT - 6);
    *pu_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 1] << (SHIFT - 6);
  }
  else if (Lhdr_idx > 3000/50) {
    ST2084toOETF_quadrint_high = ST2084toOETF_quadrint_6000;
    ST2084toOETF_quadrint_low = ST2084toOETF_quadrint_3000;
    *pu_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 2] << (SHIFT - 6);
    *pu_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 2] << (SHIFT - 6);
  }
  else if (Lhdr_idx > 1000/50) {
    ST2084toOETF_quadrint_high = ST2084toOETF_quadrint_3000;
    ST2084toOETF_quadrint_low = ST2084toOETF_quadrint_1000;
    *pu_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 3] << (SHIFT - 6);
    *pu_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 3] << (SHIFT - 6);
  }
  else if (Lhdr_idx > 600/50) {
    ST2084toOETF_quadrint_high = ST2084toOETF_quadrint_1000;
    ST2084toOETF_quadrint_low = ST2084toOETF_quadrint_600;
    *pu_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 4] << (SHIFT - 6);
    *pu_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 4] << (SHIFT - 6);
  }
  else if (Lhdr_idx > 300/50) {
    ST2084toOETF_quadrint_high = ST2084toOETF_quadrint_600;
    ST2084toOETF_quadrint_low = ST2084toOETF_quadrint_300;
    *pu_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 5] << (SHIFT - 6);
    *pu_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 5] << (SHIFT - 6);
  }
  else if (Lhdr_idx > 150/50) {
    ST2084toOETF_quadrint_high = ST2084toOETF_quadrint_300;
    ST2084toOETF_quadrint_low = ST2084toOETF_quadrint_150;
    *pu_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 6] << (SHIFT - 6);
    *pu_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 6] << (SHIFT - 6);
  }
  else {
    ST2084toOETF_quadrint_high = ST2084toOETF_quadrint_150;
    ST2084toOETF_quadrint_low = ST2084toOETF_quadrint_100;
    *pu_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 7] << (SHIFT - 6);
    *pu_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 7] << (SHIFT - 6);
  }
}

int ST2084toOETF(int i, unsigned short pu_max_e_brightness_input, unsigned short pu_alpha_low, unsigned short pu_alpha_mid, unsigned short pu_alpha_high, int pu_lower_idx, int pu_upper_idx)
{
  enum { IMPL_SHIFT = 14 };
  enum { IMPL_ONE = (1 << IMPL_SHIFT) };
  enum { IMPL_HALF = 1 << (IMPL_SHIFT - 1) };
  int x, ylow, yhigh, pu;

  x = (i * pu_max_e_brightness_input) >> (6 + IMPL_SHIFT - SHIFT);
  if (x >= (1 << SHIFT))
    return (1 << SHIFT) - 1;

  ylow = ST2084toOETF_quadrint_low(x);
  yhigh = ST2084toOETF_quadrint_high(x);

  if (x < pu_lower_idx)
    pu = pu_alpha_low * ylow + (IMPL_ONE - pu_alpha_low) * yhigh;
  else if (x < pu_upper_idx)
    pu = pu_alpha_mid * ylow + (IMPL_ONE - pu_alpha_mid) * yhigh;
  else
    pu = pu_alpha_high * ylow + (IMPL_ONE - pu_alpha_high) * yhigh;

  pu = (pu + (x << IMPL_SHIFT) + IMPL_HALF) >> IMPL_SHIFT;

  pu = CLAMP(pu, 0, ONE);

  return pu;
}

/*
  Black & white Stretch
*/

static void bwstretch_initialize(SL_HDR1_metadata *sl_hdr1_metadata, int TargetDisplayLuminance, int *bws_black_stretch, int *bws_white_stretch)
{
  unsigned char Lhdr_idx = sl_hdr1_metadata->hdrMasterDisplayMaxLuminance / 50;
  int kappa = Kappa[Lhdr_idx], lambda, lambdakappa, scale_hor;

  *bws_black_stretch = (sl_hdr1_metadata->u.variables.tmInputSignalBlackLevelOffset * 257 + 4) >> 3;
  *bws_white_stretch = (sl_hdr1_metadata->u.variables.tmInputSignalWhiteLevelOffset * 257 + 1) >> 1;

  if (TargetDisplayLuminance != sdrDisplayLuminance) {
    lambda = sfi_w32f15_div((sl_hdr1_metadata->hdrMasterDisplayMaxLuminance << SHIFT) << 1, TargetDisplayLuminance << SHIFT);
    lambda = apply_oetf(lambda, TargetDisplayLuminance << SHIFT);
    lambdakappa = sfi_w32f15_mult(kappa, lambda);
    scale_hor = sfi_w32f15_div(((lambdakappa - (kappa << 1)) << 1), lambdakappa - (lambda << 1));
    scale_hor = Max(scale_hor, 0);
    *bws_black_stretch = (*bws_black_stretch * scale_hor + HALF) >> SHIFT;
    *bws_white_stretch = (sfi_w32f15_mult(*bws_white_stretch, scale_hor) + 1) >> 1;
  }
}

static int bwstretch(int pu, int bws_black_stretch, int bws_white_stretch)
{
  int perceptualstretched = pu;

  perceptualstretched -= bws_black_stretch;
  perceptualstretched <<= (SHIFT - 1);
  perceptualstretched /= (ONE - bws_white_stretch - bws_black_stretch) >> 1;

  perceptualstretched = CLAMP(perceptualstretched, 0, ONE);

  return perceptualstretched;
}

/*
  ParaBoLa
*/

static void parabola_initialize(SL_HDR1_metadata *sl_hdr1_metadata, int TargetDisplayLuminance, int *pbl_base_gain, int *pbl_hgc, int *pbl_pa, int *pbl_pb, int *pbl_pc4, int *pbl_xlow, int *pbl_xhigh)
{
  enum { PRECISION1 = 3 };
  enum { PRECISION2 = 7 };
  unsigned char Lhdr_idx = sl_hdr1_metadata->hdrMasterDisplayMaxLuminance / 50;
  int kappa = Kappa[Lhdr_idx], lambda, MIDX, MIDY, SGC4, HGC4, MIDADJ2;
  int base_gain, hgc, midadj;
  int pa = 0, pb = 0, pc4 = 0, sh, xmid, xlow, xhigh, den;
  int tmp, num, precision, scale;

  base_gain = (sfi_w32f15_mult(kappa << (SHIFT - 4), HALF + ((sl_hdr1_metadata->u.variables.shadowGain*257 + 1) >> 1)) + (1 << (SHIFT - 4))) >> (SHIFT - 3 - PRECISION1);
  hgc = (sl_hdr1_metadata->u.variables.highlightGain * 257 + (sl_hdr1_metadata->u.variables.highlightGain & 128 ? 1 : 0)) << (PRECISION1 - 1);
  midadj = sl_hdr1_metadata->u.variables.midToneWidthAdjFactor * 257 + (sl_hdr1_metadata->u.variables.midToneWidthAdjFactor & 128 ? 1 : 0);

  if (TargetDisplayLuminance != sdrDisplayLuminance) {
    lambda = sfi_w32f15_div((sl_hdr1_metadata->hdrMasterDisplayMaxLuminance << SHIFT) << 1, TargetDisplayLuminance << SHIFT);
    lambda = apply_oetf(lambda, TargetDisplayLuminance << SHIFT);
    num = sfi_w32f15_div((lambda - ONE) << 1, lambda + ONE);
    den = sfi_w32f15_div((kappa - ONE) << 1, kappa + ONE);
    scale = sfi_w32f15_div(num << 1, den);
    num = (ONE << PRECISION1) - hgc;
    den = base_gain - hgc;
    if (den == 0) {
      if (num == 0)
        xmid = ONE << PRECISION2;
      else
        xmid = (num >= 0) ? INT32_MAX : INT32_MIN;
    }
    else
      xmid = sfi_w32f15_div((num << (1 + PRECISION2)), den);
    num = base_gain + (ONE << PRECISION1);
    den = base_gain - (ONE << PRECISION1);
    den = sfi_w32f15_mult(den, ONE - scale) + (ONE << (2 + PRECISION1));
    SGC4 = sfi_w32f15_div((num << (1 + 1 + 1 + 2)), den);
    SGC4 -= (ONE << 2);
    base_gain = (SGC4 + 2) >> 2;

    MIDX = (sfi_w32f15_mult(den - (ONE << (2 + PRECISION1)), xmid) >> 3) + (xmid << PRECISION1);
    MIDY = (sfi_w32f15_mult(num, xmid) >> 1) - MIDX;
    if (MIDX == (ONE << PRECISION2))
      HGC4 = 0;
    else
      HGC4 = Max(sfi_w32f15_div((MIDY - (ONE << (PRECISION1 + PRECISION2))) <<3, MIDX - (ONE << (PRECISION1 + PRECISION2))), 0);
    HGC4 = Min(HGC4, 8 * ONE);
    hgc = (HGC4 + 2) >> 2;

    if (TargetDisplayLuminance == sl_hdr1_metadata->hdrMasterDisplayMaxLuminance)
      midadj = 0;
    else {
      MIDADJ2 = apply_oetf(TC_ABS(scale), sl_hdr1_metadata->hdrMasterDisplayMaxLuminance << SHIFT);
      MIDADJ2 = sfi_w32f15_mult(midadj, MIDADJ2);
      midadj = (MIDADJ2 + 1) >> 1;
    }
  }
  else {
    base_gain = base_gain >> PRECISION1;
    hgc = hgc >> PRECISION1;
  }

  if (midadj) {
    precision = 5;
    /* pa = -0.5 * (base_gain - hgc) / midadj */
    pa = base_gain - hgc;
    if (TC_ABS(pa) < (1 << 17)) ++precision;
    if (TC_ABS(pa) < (1 << 16)) ++precision;
    if (TC_ABS(pa) < (1 << 15)) ++precision;
    if (midadj > (1 << 9))  ++precision;
    if (midadj > (1 << 10)) ++precision;
    if (midadj > (1 << 11)) ++precision;
    if (midadj > (1 << 12)) ++precision;
    if (midadj > (1 << 13)) ++precision;
    if (midadj > (1 << 14)) ++precision;
    if (midadj > (1 << 15)) ++precision;
    pa = sfi_w32f15_div(pa << precision, midadj);
    pa = -(pa >> precision);

    /* pb = (1 - hgc) / midadj + (base_gain + hgc) / 2 */
    precision = 5;
    pb = ONE - hgc;
    if (TC_ABS(pb) >= (1 << 16)) --precision;
    if (TC_ABS(pb) < (1 << 15)) ++precision;
    if (midadj > (1 << 9))  ++precision;
    if (midadj > (1 << 10)) ++precision;
    if (midadj > (1 << 11)) ++precision;
    if (midadj > (1 << 12)) ++precision;
    if (midadj > (1 << 13)) ++precision;
    if (midadj > (1 << 14)) ++precision;
    if (midadj > (1 << 15)) ++precision;
    if (precision == 13 && base_gain + hgc >= (1 << 17)) --precision;
    pb = sfi_w32f15_div(pb << (2 + precision), midadj);
    pb += (base_gain + hgc) << precision;
    pb = (pb + (1 << precision)) >> (1 + precision);

    /* pc4 (actually 4 * pc) = -4 * SQR((base_gain - hgc) * midadj - 2 * (1 - hgc)) / (8 * (base_gain - hgc) * midadj) */
    den = base_gain - hgc;
    precision = 13 + 16 - Min(msb32(TC_ABS(ONE - hgc)), 16);
    precision = Min(15 - (msb32(TC_ABS(den)) + msb32(midadj) - 30), precision);
    den = sfi_w32f15_mult(den << (precision >> 1), midadj << ((precision + 1) >> 1));
    if (den == 0)
      pc4 = INT32_MIN;
    else {
      num = den;
      num -= (ONE - hgc) << (2 + precision);
      tmp = sfi_w32f15_div(num, den);
      sh = Max((msb32(TC_ABS(tmp)) + msb32(TC_ABS(num)) - 30) - 16, 0);
      num = sfi_w32f15_mult(num >> sh, tmp);
      pc4 = -(num >> (2 - sh + precision));
    }
  }

  /* xlow  = (1 - hgc) / (base_gain - hgc) - midadj / 2 */
  /* xhigh = (1 - hgc) / (base_gain - hgc) + midadj / 2 */
  precision = 3;
  xmid = ONE - hgc;
  den = base_gain - hgc;
  if (den == 0)
    xmid = INT32_MAX;
  else
    xmid = sfi_w32f15_div ((xmid << (1+precision)), den);
  xmid = xmid >> precision;
  xlow = xmid - ((midadj + 1) >> 1);
  xhigh = xmid + ((midadj + 1) >> 1);

  *pbl_base_gain = base_gain;
  *pbl_hgc = hgc;
  *pbl_pa = pa;
  *pbl_pb = pb;
  *pbl_pc4 = pc4;
  *pbl_xlow = xlow;
  *pbl_xhigh = xhigh;
}

static int parabola(int bws, int pbl_base_gain, int pbl_hgc, int pbl_pa, int pbl_pb, int pbl_pc4, int pbl_xlow, int pbl_xhigh)
{
  int perceptualpbl;

  if (bws <= pbl_xlow) {
    /* perceptualpbl = bws * base_gain */
    perceptualpbl = (sfi_w32f15_mult(bws, pbl_base_gain) + 1) >> 1;
  }
  else if (bws >= pbl_xhigh) {
    /* perceptualpbl = bws * hgc + (1 - hgc) */
    perceptualpbl = sfi_w32f15_mult(bws, pbl_hgc);
    perceptualpbl += (ONE - pbl_hgc) << 1;
    perceptualpbl >>= 1;
  }
  else {
    /* perceptualpbl = (pa * bws + pb) * bws + pc */
    perceptualpbl = sfi_w32f15_mult(bws, pbl_pa);
    perceptualpbl += (pbl_pb << 1);
    perceptualpbl = sfi_w32f15_mult(perceptualpbl, bws);
    perceptualpbl += pbl_pc4;
    perceptualpbl >>= 2;
  }

  perceptualpbl = CLAMP(perceptualpbl, 0, ONE);

  return perceptualpbl;
}

/*
  Custom Curve
*/

static void interpolate_initialize(SL_HDR1_metadata *sl_hdr1_metadata, int TargetDisplayLuminance, int *cc_x, int *cc_y, int *cc_size)
{
  int i, j;
  unsigned char Lhdr_idx = sl_hdr1_metadata->hdrMasterDisplayMaxLuminance / 50;
  int ipbl_base_gain, ipbl_hgc, ipbl_one_div_a, ipbl_one_div_a_shift, ipbl_min_b_div_2a, ipbl_lb_b2_min_4ac_rb_div_4a2, ipbl_lb_b2_min_4ac_rb_div_4a2_shift, ipbl_ylow, ipbl_yhigh;
  int ibws_black_stretch, ibws_white_stretch;
  int bws_black_stretch, bws_white_stretch;
  int pbl_base_gain, pbl_hgc, pbl_pa, pbl_pb, pbl_pc4, pbl_xlow, pbl_xhigh;
  int ipbl, ibws, bws, pbl, kappa = Kappa[Lhdr_idx], lambda, scale_ver;

  *cc_size = sl_hdr1_metadata->u.variables.tmOutputFineTuningNumVal;
  cc_x[0] = 0;
  cc_y[0] = 0;
  if (sl_hdr1_metadata->u.variables.tmOutputFineTuningNumVal > 0 && sl_hdr1_metadata->u.variables.tmOutputFineTuningX[0] == 0 && sl_hdr1_metadata->u.variables.tmOutputFineTuningY[0] == 0)
    i = 1;
  else {
    *cc_size += 1;
    i = 0;
  }

  if (sl_hdr1_metadata->u.variables.tmOutputFineTuningNumVal > 0 && sl_hdr1_metadata->u.variables.tmOutputFineTuningX[sl_hdr1_metadata->u.variables.tmOutputFineTuningNumVal - 1] == 255 && sl_hdr1_metadata->u.variables.tmOutputFineTuningY[sl_hdr1_metadata->u.variables.tmOutputFineTuningNumVal - 1] == 255);
  else
    *cc_size += 1;
  cc_x[*cc_size - 1] = ONE;
  cc_y[*cc_size - 1] = ONE;

  if (TargetDisplayLuminance != sdrDisplayLuminance && *cc_size > 2) {
    lambda = sfi_w32f15_div((sl_hdr1_metadata->hdrMasterDisplayMaxLuminance << SHIFT) << 1, TargetDisplayLuminance << SHIFT);
    lambda = apply_oetf(lambda, TargetDisplayLuminance << SHIFT);
    scale_ver = sfi_w32f15_div((ONE - lambda) << 1, ONE - kappa);
    scale_ver = Max(scale_ver, 0);

    invparabola_initialize(sl_hdr1_metadata, &ipbl_base_gain, &ipbl_hgc, &ipbl_one_div_a, &ipbl_one_div_a_shift, &ipbl_min_b_div_2a, &ipbl_lb_b2_min_4ac_rb_div_4a2, &ipbl_lb_b2_min_4ac_rb_div_4a2_shift, &ipbl_ylow, &ipbl_yhigh);
    invbwstretch_initialize(sl_hdr1_metadata, &ibws_black_stretch, &ibws_white_stretch);
    bwstretch_initialize(sl_hdr1_metadata, TargetDisplayLuminance, &bws_black_stretch, &bws_white_stretch);
    parabola_initialize(sl_hdr1_metadata, TargetDisplayLuminance, &pbl_base_gain, &pbl_hgc, &pbl_pa, &pbl_pb, &pbl_pc4, &pbl_xlow, &pbl_xhigh);
  }

  j = 1;
  while (j < *cc_size - 1) {
    cc_x[j] = sl_hdr1_metadata->u.variables.tmOutputFineTuningX[i] * 257 + (sl_hdr1_metadata->u.variables.tmOutputFineTuningX[i] & 128 ? 1 : 0);
    cc_y[j] = sl_hdr1_metadata->u.variables.tmOutputFineTuningY[i] * 257 + (sl_hdr1_metadata->u.variables.tmOutputFineTuningY[i] & 128 ? 1 : 0);
    if (TargetDisplayLuminance != sdrDisplayLuminance) {
      ipbl = invparabola(cc_x[j], ipbl_base_gain, ipbl_hgc, ipbl_one_div_a, ipbl_one_div_a_shift, ipbl_min_b_div_2a, ipbl_lb_b2_min_4ac_rb_div_4a2, ipbl_lb_b2_min_4ac_rb_div_4a2_shift, ipbl_ylow, ipbl_yhigh);
      ibws = invbwstretch(ipbl, ibws_black_stretch, ibws_white_stretch);
      bws = bwstretch(ibws, bws_black_stretch, bws_white_stretch);
      pbl = parabola(bws, pbl_base_gain, pbl_hgc, pbl_pa, pbl_pb, pbl_pc4, pbl_xlow, pbl_xhigh);
      cc_y[j] = CLAMP(((sfi_w32f15_mult(cc_y[j] - cc_x[j], scale_ver) + (pbl << 1)) + 1) >> 1, 0, ONE);
      cc_x[j] = pbl;
    }
    i++;
    j++;
  }
}

static int interpolate(int pbl, int *icc_x, int *icc_y, int icc_size)
{
  int y = pbl, i = 0, delta_x, delta_y, x_tmp, y_tmp;

  if (icc_size > 2) {
    while (pbl >= icc_x[i] && i < icc_size - 1)
      ++i;

    delta_x = icc_x[i] - icc_x[i - 1];
    delta_y = icc_y[i] - icc_y[i - 1];
    x_tmp = pbl - icc_x[i - 1];
    y_tmp = icc_y[i - 1];

    y = Min((x_tmp * delta_y + (delta_x >> 1)) / delta_x + y_tmp, ONE);
  }

  return y;
}

/*
  Black Gain Limiter
*/

static int bglimiter_alpha[201] =
{
      2207,      6348,      7323,      7918,      8349,      8689,      8969,      9208,
      9417,      9602,      9768,      9919,     10058,     10185,     10304,     10415,
     10518,     10616,     10708,     10796,     10879,     10958,     11034,     11106,
     11175,     11242,     11306,     11368,     11427,     11485,     11540,     11594,
     11646,     11697,     11746,     11794,     11840,     11885,     11929,     11972,
     12014,     12055,     12095,     12134,     12172,     12209,     12245,     12281,
     12316,     12350,     12384,     12417,     12449,     12481,     12512,     12542,
     12572,     12602,     12631,     12659,     12687,     12715,     12742,     12769,
     12795,     12821,     12846,     12871,     12896,     12921,     12945,     12968,
     12992,     13015,     13038,     13060,     13082,     13104,     13126,     13147,
     13168,     13189,     13210,     13230,     13250,     13270,     13290,     13309,
     13328,     13347,     13366,     13385,     13403,     13421,     13439,     13457,
     13475,     13492,     13509,     13526,     13543,     13560,     13577,     13593,
     13609,     13625,     13641,     13657,     13673,     13688,     13704,     13719,
     13734,     13749,     13764,     13779,     13793,     13808,     13822,     13837,
     13851,     13865,     13879,     13892,     13906,     13920,     13933,     13946,
     13960,     13973,     13986,     13999,     14012,     14024,     14037,     14050,
     14062,     14075,     14087,     14099,     14111,     14123,     14135,     14147,
     14159,     14171,     14182,     14194,     14205,     14217,     14228,     14239,
     14250,     14262,     14273,     14284,     14294,     14305,     14316,     14327,
     14337,     14348,     14358,     14369,     14379,     14390,     14400,     14410,
     14420,     14430,     14440,     14450,     14460,     14470,     14480,     14489,
     14499,     14509,     14518,     14528,     14537,     14547,     14556,     14565,
     14575,     14584,     14593,     14602,     14611,     14620,     14629,     14638,
     14647,     14656,     14665,     14673,     14682,     14691,     14699,     14708,
     14716
};

static void bglimiter_initialize(SL_HDR1_metadata *sl_hdr1_metadata, int *bgl_alpha, int *bgl_is_bypassed)
{
  unsigned char Lhdr_idx = sl_hdr1_metadata->hdrMasterDisplayMaxLuminance / 50;

  *bgl_alpha = bglimiter_alpha[Lhdr_idx];
  *bgl_is_bypassed = (sl_hdr1_metadata->u.variables.tmInputSignalBlackLevelOffset == 0) ? 1 : 0;
}

static int bglimiter(int pu, int cc, int bgl_is_bypassed, int bgl_alpha)
{
  enum { IMPL_SHIFT = 14 };
  enum { IMPL_HALF = 1 << (IMPL_SHIFT - 1) };
  int glim = cc;

  if (bgl_is_bypassed == 0) {
    glim = pu * bgl_alpha;
    glim += IMPL_HALF;
    glim >>= IMPL_SHIFT;
    glim = Max(glim, cc);
  }

  glim = CLAMP(glim, 0, ONE - 1);

  return glim;
}

/*
  EOTF and PQ
*/

extern unsigned short EOTFtoPQ_max_e_brightness_output_table[201];
extern unsigned short EOTFtoPQ_alpha_low_table[201];
extern unsigned short EOTFtoPQ_alpha_mid_table[201];
extern unsigned short EOTFtoPQ_alpha_high_table[201];
extern int EOTFtoPQ_quadrint_0(int x_in);
extern int EOTFtoPQ_quadrint_50(int x_in);
extern int EOTFtoPQ_quadrint_100(int x_in);
extern int EOTFtoPQ_quadrint_150(int x_in);
extern int EOTFtoPQ_quadrint_300(int x_in);
extern int EOTFtoPQ_quadrint_600(int x_in);
extern int EOTFtoPQ_quadrint_1000(int x_in);
extern int EOTFtoPQ_quadrint_3000(int x_in);
extern int EOTFtoPQ_quadrint_6000(int x_in);
extern int EOTFtoPQ_quadrint_10000(int x_in);
static int (*EOTFtoPQ_quadrint_low)(int x_in);
static int (*EOTFtoPQ_quadrint_high)(int x_in);

static void EOTFtoPQ_initialize(SL_HDR1_metadata *sl_hdr1_metadata, int TargetDisplayLuminance, unsigned short *pqY_max_e_brightness_output, unsigned short *pqY_alpha_low, unsigned short *pqY_alpha_mid, unsigned short *pqY_alpha_high, int *pqY_lower_idx, int *pqY_upper_idx)
{
  enum { NUMBER_OF_INTERVALS = 9 };
  int interval_lower_table_[NUMBER_OF_INTERVALS] = { 29, 29, 29, 29, 22, 18, 14, 13, 13 };
  int interval_upper_table_[NUMBER_OF_INTERVALS] = { 39, 39, 39, 39, 33, 27, 23, 23, 23 };
  unsigned char Ldisplay_idx = TargetDisplayLuminance / 50;

  *pqY_max_e_brightness_output = EOTFtoPQ_max_e_brightness_output_table[Ldisplay_idx];
  *pqY_alpha_low = EOTFtoPQ_alpha_low_table[Ldisplay_idx];
  *pqY_alpha_mid = EOTFtoPQ_alpha_mid_table[Ldisplay_idx];
  *pqY_alpha_high = EOTFtoPQ_alpha_high_table[Ldisplay_idx];

  if (Ldisplay_idx > 6000/50) {
    EOTFtoPQ_quadrint_high = EOTFtoPQ_quadrint_10000;
    EOTFtoPQ_quadrint_low = EOTFtoPQ_quadrint_6000;
    *pqY_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 1] << (SHIFT - 6);
    *pqY_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 1] << (SHIFT - 6);
  }
  else if (Ldisplay_idx > 3000/50) {
    EOTFtoPQ_quadrint_high = EOTFtoPQ_quadrint_6000;
    EOTFtoPQ_quadrint_low = EOTFtoPQ_quadrint_3000;
    *pqY_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 2] << (SHIFT - 6);
    *pqY_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 2] << (SHIFT - 6);
  }
  else if (Ldisplay_idx > 1000/50) {
    EOTFtoPQ_quadrint_high = EOTFtoPQ_quadrint_3000;
    EOTFtoPQ_quadrint_low = EOTFtoPQ_quadrint_1000;
    *pqY_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 3] << (SHIFT - 6);
    *pqY_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 3] << (SHIFT - 6);
  }
  else if (Ldisplay_idx > 600/50) {
    EOTFtoPQ_quadrint_high = EOTFtoPQ_quadrint_1000;
    EOTFtoPQ_quadrint_low = EOTFtoPQ_quadrint_600;
    *pqY_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 4] << (SHIFT - 6);
    *pqY_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 4] << (SHIFT - 6);
  }
  else if (Ldisplay_idx > 300/50) {
    EOTFtoPQ_quadrint_high = EOTFtoPQ_quadrint_600;
    EOTFtoPQ_quadrint_low = EOTFtoPQ_quadrint_300;
    *pqY_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 5] << (SHIFT - 6);
    *pqY_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 5] << (SHIFT - 6);
  }
  else if (Ldisplay_idx > 150/50) {
    EOTFtoPQ_quadrint_high = EOTFtoPQ_quadrint_300;
    EOTFtoPQ_quadrint_low = EOTFtoPQ_quadrint_150;
    *pqY_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 6] << (SHIFT - 6);
    *pqY_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 6] << (SHIFT - 6);
  }
  else if (Ldisplay_idx > 100/50) {
    EOTFtoPQ_quadrint_high = EOTFtoPQ_quadrint_150;
    EOTFtoPQ_quadrint_low = EOTFtoPQ_quadrint_100;
    *pqY_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 7] << (SHIFT - 6);
    *pqY_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 7] << (SHIFT - 6);
  }
  else if (Ldisplay_idx > 50/50) {
    EOTFtoPQ_quadrint_high = EOTFtoPQ_quadrint_100;
    EOTFtoPQ_quadrint_low = EOTFtoPQ_quadrint_50;
    *pqY_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 8] << (SHIFT - 6);
    *pqY_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 8] << (SHIFT - 6);
  }
  else {
    EOTFtoPQ_quadrint_high = EOTFtoPQ_quadrint_50;
    EOTFtoPQ_quadrint_low = EOTFtoPQ_quadrint_0;
    *pqY_lower_idx = interval_lower_table_[NUMBER_OF_INTERVALS - 9] << (SHIFT - 6);
    *pqY_upper_idx = interval_upper_table_[NUMBER_OF_INTERVALS - 9] << (SHIFT - 6);
  }
}

int EOTFtoPQ(int bgl, unsigned short pqY_max_e_brightness_output, unsigned short pqY_alpha_low, unsigned short pqY_alpha_mid, unsigned short pqY_alpha_high, int pqY_lower_idx, int pqY_upper_idx)
{
  enum { IMPL_SHIFT = 14 };
  enum { IMPL_ONE = (1 << IMPL_SHIFT) };
  int ylow, yhigh, pqY;

  ylow = EOTFtoPQ_quadrint_low(bgl);
  yhigh = EOTFtoPQ_quadrint_high(bgl);

  if (bgl < pqY_lower_idx)
    pqY = pqY_alpha_low * ylow + (IMPL_ONE - pqY_alpha_low) * yhigh;
  else if (bgl < pqY_upper_idx)
    pqY = pqY_alpha_mid * ylow + (IMPL_ONE - pqY_alpha_mid) * yhigh;
  else
    pqY = pqY_alpha_high * ylow + (IMPL_ONE - pqY_alpha_high) * yhigh;

  pqY = (pqY + bgl * pqY_max_e_brightness_output + (1 << SHIFT)) >> (SHIFT + 1);
  pqY = CLAMP(pqY, 0, (1 << 13) - 1);

  return pqY;
}

/**
 * @brief Compute the P_LUT (called once per frame)
 *
 * @param mode : "PRIME over SDR" or "PRIME over HDR"
 * @param sl_hdr1_metadata[in] : current metadata
 * @param TargetDisplayLuminance : display brightness
 * @param P_LUT[out] : pointer to the computed P_LUT
 *
 * @return void
*/



void drvif_fwif_color_set_TC_v130_Compute_P_LUT(int proc_mode, SL_HDR1_metadata *sl_hdr1_metadata, int TargetDisplayLuminance, unsigned short *P_LUT)
{
  int i, j, pu;
  // SDR2HDR parameters
  int icc_x[12], icc_y[12], icc_size;
  int ipbl_base_gain, ipbl_hgc, ipbl_one_div_a, ipbl_one_div_a_shift, ipbl_min_b_div_2a, ipbl_lb_b2_min_4ac_rb_div_4a2, ipbl_lb_b2_min_4ac_rb_div_4a2_shift, ipbl_ylow, ipbl_yhigh;
  int ibws_black_stretch, ibws_white_stretch;
  int ibgl_is_bypassed, ibgl_alpha;
  unsigned short sqrtY_alpha;
  int icc, ipbl, ibws;
  // HDR2MDR parameters
  unsigned short pu_max_e_brightness_input, pu_alpha_low, pu_alpha_mid, pu_alpha_high;
  int pu_lower_idx, pu_upper_idx;
  int bws_black_stretch, bws_white_stretch;
  int pbl_base_gain, pbl_hgc, pbl_pa, pbl_pb, pbl_pc4, pbl_xlow, pbl_xhigh;
  int cc_x[12], cc_y[12], cc_size;
  int bgl_alpha, bgl_is_bypassed;
  unsigned short pqY_max_e_brightness_output, pqY_alpha_low, pqY_alpha_mid, pqY_alpha_high;
  int pqY_lower_idx, pqY_upper_idx;
  int bws, pbl, cc;

  if (!sl_hdr1_metadata->payloadMode) { // payloadMode = 0 (Parameter-based)
    if (proc_mode == SDR2MDR) { // SDR2MDR (VUI transfer_characteristics = ITU-R BT.709)
      invinterpolate_initialize(sl_hdr1_metadata, icc_x, icc_y, &icc_size);
      invparabola_initialize(sl_hdr1_metadata, &ipbl_base_gain, &ipbl_hgc, &ipbl_one_div_a, &ipbl_one_div_a_shift, &ipbl_min_b_div_2a, &ipbl_lb_b2_min_4ac_rb_div_4a2, &ipbl_lb_b2_min_4ac_rb_div_4a2_shift, &ipbl_ylow, &ipbl_yhigh);
      invbwstretch_initialize(sl_hdr1_metadata, &ibws_black_stretch, &ibws_white_stretch);
      invbglimiter_initialize(sl_hdr1_metadata, &ibgl_alpha, &ibgl_is_bypassed);

      for (i = 0; i < 65; ++i) {
        /* Perceptual Uniform from Gamma */
        pu = GammatoOETF[i];

        /* Inverse Custom Curve */
        icc = invinterpolate(pu, icc_x, icc_y, icc_size);

        /* Inverse ParaBoLa */
        ipbl = invparabola(icc, ipbl_base_gain, ipbl_hgc, ipbl_one_div_a, ipbl_one_div_a_shift, ipbl_min_b_div_2a, ipbl_lb_b2_min_4ac_rb_div_4a2, ipbl_lb_b2_min_4ac_rb_div_4a2_shift, ipbl_ylow, ipbl_yhigh);

        /* Inverse Black & White Stretch */
        ibws = invbwstretch(ipbl, ibws_black_stretch, ibws_white_stretch);

        /* Inverse Black Gain Limiter */
        P_LUT[i] = invbglimiter(pu, ibws, ibgl_is_bypassed, ibgl_alpha);
      }
    }
    else { // HDR2MDR (VUI transfer_characteristics = SMPTE ST-2084)
      ST2084toOETF_initialize(sl_hdr1_metadata, &pu_max_e_brightness_input, &pu_alpha_low, &pu_alpha_mid, &pu_alpha_high, &pu_lower_idx, &pu_upper_idx);

      for (i = 0; i < 65; ++i) {
        /* Perceptual Uniform from ST2084 */
        P_LUT[i] = ST2084toOETF(i, pu_max_e_brightness_input, pu_alpha_low, pu_alpha_mid, pu_alpha_high, pu_lower_idx, pu_upper_idx);
      }
    }

    if (proc_mode == HDR2MDR || // HDR2MDR (VUI transfer_characteristics = SMPTE ST-2084)
        TargetDisplayLuminance != sl_hdr1_metadata->hdrMasterDisplayMaxLuminance) { // SDR2MDR (VUI transfer_characteristics = ITU-R BT.709)
      bwstretch_initialize(sl_hdr1_metadata, TargetDisplayLuminance, &bws_black_stretch, &bws_white_stretch);
      parabola_initialize(sl_hdr1_metadata, TargetDisplayLuminance, &pbl_base_gain, &pbl_hgc, &pbl_pa, &pbl_pb, &pbl_pc4, &pbl_xlow, &pbl_xhigh);
      interpolate_initialize(sl_hdr1_metadata, TargetDisplayLuminance, cc_x, cc_y, &cc_size);
      bglimiter_initialize(sl_hdr1_metadata, &bgl_alpha, &bgl_is_bypassed);

      for (i = 0; i < 65; ++i) {
        /* Perceptual Uniform */
        pu = P_LUT[i];

        /* Black & white Stretch */
        bws = bwstretch(pu, bws_black_stretch, bws_white_stretch);

        /* ParaBoLa */
        pbl = parabola(bws, pbl_base_gain, pbl_hgc, pbl_pa, pbl_pb, pbl_pc4, pbl_xlow, pbl_xhigh);

        /* Custom Curve */
        cc = interpolate(pbl, cc_x, cc_y, cc_size);

        /* Black Gain Limiter */
        P_LUT[i] = bglimiter(pu, cc, bgl_is_bypassed, bgl_alpha);
      }
    }

    if (proc_mode == SDR2MDR) { // SDR2MDR (VUI transfer_characteristics = ITU-R BT.709)
      EOTFtoSqrt_initialize(sl_hdr1_metadata, TargetDisplayLuminance, &sqrtY_alpha);

      for (i = 0; i < 65; ++i) {
        /* EOTF and Sqrt */
        P_LUT[i] = EOTFtoSqrt(P_LUT[i], sqrtY_alpha);
      }
    }
    else { // HDR2MDR (VUI transfer_characteristics = SMPTE ST-2084)
      EOTFtoPQ_initialize(sl_hdr1_metadata, TargetDisplayLuminance, &pqY_max_e_brightness_output, &pqY_alpha_low, &pqY_alpha_mid, &pqY_alpha_high, &pqY_lower_idx, &pqY_upper_idx);

      for (i = 0; i < 65; ++i) {
        /* EOTF and PQ */
        P_LUT[i] = EOTFtoPQ(P_LUT[i], pqY_max_e_brightness_output, pqY_alpha_low, pqY_alpha_mid, pqY_alpha_high, pqY_lower_idx, pqY_upper_idx);
      }
    }
  }
  else { // payloadMode = 1 (Table-based)
    if ((proc_mode == SDR2MDR && TargetDisplayLuminance != sl_hdr1_metadata->hdrMasterDisplayMaxLuminance) ||
        (proc_mode == HDR2MDR && TargetDisplayLuminance != sdrDisplayLuminance)) {
      VIPprintf("Display Adaptation can't work with this payloadMode\n");
      return;
    }
    else {
      for (i = 0; i < 32; i++) {
        for (j = 0; j < 2; j++) {
          P_LUT[2 * i + j] = ((2 - j) * sl_hdr1_metadata->u.tables.luminanceMappingY[i] + j * sl_hdr1_metadata->u.tables.luminanceMappingY[i+1] + 1) >> 1;
        }
      }
      P_LUT[64] = sl_hdr1_metadata->u.tables.luminanceMappingY[32];
    }
  }
}
#endif//juwen, drvif_fwif_color_set_TC_v130_Compute_P_LUT and its subfunction



void drvif_fwif_color_set_TC_v130_HW_setting_call_Each_Frame(
	//struct sl_hdr1_metadata *sl_hdr1_metadata,
	unsigned short *muA,
	unsigned short *muB,
	signed short  *OCT,
	unsigned short *C_LUT,
	unsigned short *P_LUT,
	unsigned short *D_LUT,
	unsigned short *D_LUT_THRESHOLD,
	unsigned short *D_LUT_STEP,
 	int yuv_range,
      int      *p_RGB2YUV_i     // Input, pointer to p_RGB2YUV_i matrix
)
{
	drvif_fwif_color_set_TC_v130_Write_P_LUT(P_LUT);
	drvif_fwif_color_set_TC_v130_L_Compute(muA, muB);
	drvif_fwif_color_set_TC_v130_Write_C_LUT(C_LUT);
	drvif_fwif_color_set_TC_v130_Write_D_LUT(D_LUT);
	drvif_fwif_color_set_TC_v130_D_LUT_Step_Threshold(D_LUT_THRESHOLD, D_LUT_STEP);
	drvif_fwif_color_set_TC_v130_T_Compute(OCT);
	drvif_fwif_color_set_TC_v130_M_Compute(OCT);

}


void drvif_fwif_color_set_TC_v130_HW_setting_init(
	//struct sl_hdr1_metadata *sl_hdr1_metadata,
	unsigned short *muA,
	unsigned short *muB,
	signed short  *OCT,
	unsigned short *C_LUT,
	unsigned short *P_LUT,
	unsigned short *D_LUT,
	unsigned short *D_LUT_THRESHOLD,
	unsigned short *D_LUT_STEP,
 	int yuv_range,
      int      *p_RGB2YUV_i     // Input, pointer to p_RGB2YUV_i matrix
)
{

	//fwif_color_set_TC_Enable(0, 1);
	drvif_fwif_color_set_TC_v130_Range_Adaptation(0,yuv_range);
	drvif_fwif_color_set_TC_v130_Write_I_LUT(0, 0);
	drvif_fwif_color_set_TC_v130_Write_S_LUT(0, 0);
//juwen,1215,for first frame : deiver of P_LUT call 2 times to write 2 SRAM!!!!
	drvif_fwif_color_set_TC_v130_Write_P_LUT(P_LUT);
	drvif_fwif_color_set_TC_v130_Write_P_LUT(P_LUT);

	drvif_fwif_color_set_TC_v130_L_Compute(muA, muB);
	drvif_fwif_color_set_TC_v130_Write_C_LUT(C_LUT);
	drvif_fwif_color_set_TC_v130_Write_D_LUT(D_LUT);
	drvif_fwif_color_set_TC_v130_D_LUT_Step_Threshold(D_LUT_THRESHOLD, D_LUT_STEP);
	drvif_fwif_color_set_TC_v130_T_Compute(OCT);
	drvif_fwif_color_set_TC_v130_M_Compute(OCT);

}

#endif//juwen, merlin3, tc
