//===========================================================================
//o------ initial function ------o
//===========================================================================
#include <linux/kernel.h>
#include <linux/delay.h>

#include <rbus/vgip_reg.h>
#include <rbus/d_2d_to_3d_reg.h>
#include <scalercommon/scalerCommon.h>

//#include <Platform_Lib/panel/panelAPI.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
//#include <tvscalercontrol/scaler/scalerLib.h>
#include <tvscalercontrol/scalerdrv/conversion_2d_3d.h>
#include <tvscalercontrol/scalerdrv/scaler_2dcvt3d_ctrl.h>
#include <tvscalercontrol/panel/panelapi.h>


static bool autoAdjust_flag=FALSE;

void scalerDrv_2D_to_3D_Obj_initialize(void)	// turn off function in default
{
/*
#ifdef CONFIG_DARWIN_SCALER
	vgip_2d_to_3d_ctl2_RBUS reg_2d_to_3d_ctrl2;
	reg_2d_to_3d_ctrl2.regValue = IoReg_Read32(VGIP_2D_TO_3D_CTL2_reg);

	reg_2d_to_3d_ctrl2.vgip_2d3d_depth_gain = 0x3f;	// 63 (max)
	reg_2d_to_3d_ctrl2.vgip_2d3d_depth_cgain = 3;	// x1/4

	reg_2d_to_3d_ctrl2.vgip_2d3d_depth_lpf_c0 = 6;
	reg_2d_to_3d_ctrl2.vgip_2d3d_depth_lpf_c1 = 4;
	reg_2d_to_3d_ctrl2.vgip_2d3d_depth_lpf_c2 = 1;
	reg_2d_to_3d_ctrl2.vgip_2d3d_depth_lpf_en = 1;

	reg_2d_to_3d_ctrl2.vgip_2d3d_depth_frac_en = 1;	// Depth Fraction Mode Enable

	IoReg_Write32(VGIP_2D_TO_3D_CTL2_reg, reg_2d_to_3d_ctrl2.regValue);
#endif
*/


// Add for Macarthur, by Lydia

//Object 1 setting
	d_2d_to_3d_d_2d3d_object1_operation_RBUS reg_d_2d3d_object1_operation;
	d_2d_to_3d_d_2d3d_object1_depth1_RBUS reg_d_2d3d_object1_depth1;
	d_2d_to_3d_d_2d3d_object1_depth2_RBUS reg_d_2d3d_object1_depth2;
	d_2d_to_3d_d_2d3d_object2_operation_RBUS reg_d_2d3d_object2_operation;
	d_2d_to_3d_d_2d3d_object2_depth1_RBUS reg_d_2d3d_object2_depth1;
	d_2d_to_3d_d_2d3d_object2_depth2_RBUS reg_d_2d3d_object2_depth2;
	d_2d_to_3d_d_2d3d_object3_operation_RBUS reg_d_2d3d_object3_operation;
	d_2d_to_3d_d_2d3d_object3_depth1_RBUS reg_d_2d3d_object3_depth1;
	d_2d_to_3d_d_2d3d_object3_depth2_RBUS reg_d_2d3d_object3_depth2;

	reg_d_2d3d_object1_operation.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Object1_Operation_reg);
	reg_d_2d3d_object1_operation.object1_thd= 0xff;
	reg_d_2d3d_object1_operation.object1_offset= 0;
	reg_d_2d3d_object1_operation.object1_gain= 0x10;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Object1_Operation_reg, reg_d_2d3d_object1_operation.regValue);

	reg_d_2d3d_object1_depth1.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg);
	reg_d_2d3d_object1_depth1.object1_depth_dir= 0;
	//[crixus 20140721]remove in mac3~ reg_d_2d3d_object1_depth1.object1_depth_gain= 0x10;
	//[crixus 20140721]remove in mac3~reg_d_2d3d_object1_depth1.object1_depth_shift= 0x6;

	//set reference yuv
	reg_d_2d3d_object1_depth2.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_reg);

	reg_d_2d3d_object1_depth1.object1_depth_ref1= 0;
	reg_d_2d3d_object1_depth1.object1_depth_weight1= 0x1;
	reg_d_2d3d_object1_depth2.object1_depth_ref2= 0;
	reg_d_2d3d_object1_depth2.object1_depth_weight2= 0x1;
	reg_d_2d3d_object1_depth2.object1_depth_ref3= 0;
	reg_d_2d3d_object1_depth2.object1_depth_weight3= 0x1;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg, reg_d_2d3d_object1_depth1.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_reg, reg_d_2d3d_object1_depth2.regValue);


//Object 2 setting
	reg_d_2d3d_object2_operation.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Object2_Operation_reg);
	reg_d_2d3d_object2_operation.object2_thd= 0xff;
	reg_d_2d3d_object2_operation.object2_offset= 0;
	reg_d_2d3d_object2_operation.object2_gain= 0x10;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Object2_Operation_reg, reg_d_2d3d_object2_operation.regValue);


	reg_d_2d3d_object2_depth1.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg);
	reg_d_2d3d_object2_depth1.object2_depth_dir= 0;
	//[crixus 20140721]remove in mac3~reg_d_2d3d_object2_depth1.object2_depth_gain= 0x10;
	//[crixus 20140721]remove in mac3~reg_d_2d3d_object2_depth1.object2_depth_shift= 0x6;

	//set reference yuv
	reg_d_2d3d_object2_depth2.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_reg);
	reg_d_2d3d_object2_depth1.object2_depth_ref1= 0;
	reg_d_2d3d_object2_depth1.object2_depth_weight1= 0x1;
	reg_d_2d3d_object2_depth2.object2_depth_ref2= 0;
	reg_d_2d3d_object2_depth2.object2_depth_weight2= 0x1;
	reg_d_2d3d_object2_depth2.object2_depth_ref3= 0;
	reg_d_2d3d_object2_depth2.object2_depth_weight3= 0x1;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_reg, reg_d_2d3d_object2_depth1.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_reg, reg_d_2d3d_object2_depth2.regValue);

//Object 3 setting
	reg_d_2d3d_object3_operation.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Object3_Operation_reg);
	reg_d_2d3d_object3_operation.object3_thd= 0xff;
	reg_d_2d3d_object3_operation.object3_offset= 0;
	reg_d_2d3d_object3_operation.object3_gain= 0x10;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Object3_Operation_reg, reg_d_2d3d_object3_operation.regValue);



	reg_d_2d3d_object3_depth1.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_reg);
	reg_d_2d3d_object3_depth1.object3_depth_dir= 0;
	//[crixus 20140721]remove in mac3~reg_d_2d3d_object3_depth1.object3_depth_gain= 0x10;
	//[crixus 20140721]remove in mac3~reg_d_2d3d_object3_depth1.object3_depth_shift= 0x6;

	//set reference yuv

	reg_d_2d3d_object3_depth2.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_reg);
	reg_d_2d3d_object3_depth1.object3_depth_ref1 = 0;
	reg_d_2d3d_object3_depth1.object3_depth_weight1 = 0x1;
	reg_d_2d3d_object3_depth2.object3_depth_ref2 = 0;
	reg_d_2d3d_object3_depth2.object3_depth_weight2 = 0x1;
	reg_d_2d3d_object3_depth2.object3_depth_ref3 = 0;
	reg_d_2d3d_object3_depth2.object3_depth_weight3 = 0x1;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_reg, reg_d_2d3d_object3_depth1.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_reg, reg_d_2d3d_object3_depth2.regValue);


}


void scalerDrv_2D_to_3D_Obj_set_en(bool level)	// 2D to 3D function on or off
{
}


void scalerDrv_2D_to_3D_Obj_set_frame_mode(UINT8 level)	// no shift: 0 , shift left:1 , right:2, shift both:3(defult),     2D3D on /off
{



}

void scalerDrv_2D_to_3D_Obj_set_lpf_setting(bool level,UINT8 c0,UINT8 c1,UINT8 c2)	// low pass filter , enable & coefficients
{
}


void scalerDrv_2D_to_3D_Obj_set_frac_en(bool level){	// using fraction hole filling

}


void scalerDrv_2D_to_3D_Obj_set_rendering_mode_setting(UINT8 level)	// rendering mode
{
}

void scalerDrv_2D_to_3D_Obj_set_depth_gain(UINT8 level)	// depth gain
{
}


void scalerDrv_2D_to_3D_set_Obj_cgain(UINT8 level)	// weighting of chroma
{
}





bool scalerDrv_2D_to_3D_Obj_get_frame_mode(void)	// shift left or right
{
	return 0;
}

void scalerDrv_2D_to_3D_Obj_get_lpf_setting(bool *level,UINT8 *c0,UINT8 *c1,UINT8 *c2)	// low pass filter , enable & coefficients
{
	return;
}


bool scalerDrv_2D_to_3D_Obj_get_frac_en(void)	// using fraction hole filling
{
	return 0;
}



UINT8 scalerDrv_2D_to_3D_Obj_get_rendering_mode_setting(void)	// rendering mode
{
	return 0;
}

UINT8 scalerDrv_2D_to_3D_Obj_get_depth_gain(void)	// depth gain
{
	return 0;
}


UINT8 scalerDrv_2D_to_3D_get_Obj_cgain(void)	// weighting of chroma
{
#ifdef CONFIG_DARWIN_SCALER
	vgip_2d_to_3d_ctl2_RBUS reg_2d_to_3d_ctrl2;
	reg_2d_to_3d_ctrl2.regValue = IoReg_Read32(VGIP_2D_TO_3D_CTL2_reg);
	return reg_2d_to_3d_ctrl2.vgip_2d3d_depth_cgain;
#else
	return 0;
#endif
}


void drv_2D_to_3D_Set_Auto_Adjust(bool autoMode)
{
	autoAdjust_flag = autoMode;
	return;
}


bool drv_2D_to_3D_Get_Auto_Adjust(void)
{
	return autoAdjust_flag;
}


static unsigned int cur2Dcvt3D_Strength = DISP_2DCVT3D_3D_STRENGTH_DEFAULT_VALUE;	// 0~10
static char cur2Dcvt3D_Depth = DISP_2DCVT3D_3D_DEPTH_DEFAULT_VALUE;	// -6 ~+6

unsigned int Scaler_Get2DCvt3D_Strength(void)
{
	//printf("[DBG][2D3D] get strength=%d\n", cur2Dcvt3D_Strength);
	return cur2Dcvt3D_Strength;

}

char Scaler_Get2DCvt3D_Depth(void)
{
	return cur2Dcvt3D_Depth;
}

void Scaler_Set2DCvt3D_Strength(unsigned int value)
{
	if (Get_PANEL_SCALER_2D_3D_CVT_HWSHIFT_ENABLE())
	{
		value = (value > DISP_2DCVT3D_3D_STRENGTH_MAX_VALUE? DISP_2DCVT3D_3D_STRENGTH_MAX_VALUE:value);
		//frank@1017 mark code to solve scan tool fail
		//(value <  0? 0: value));
		cur2Dcvt3D_Strength = value;

		pr_debug("[2D3D] set strength=%d\n", value);
		drv_2D_to_3D_shifter(cur2Dcvt3D_Strength, Scaler_Get2DCvt3D_Depth());
	}
}

void Scaler_Set2DCvt3D_Depth(char value)
{
	if (Get_PANEL_SCALER_2D_3D_CVT_HWSHIFT_ENABLE())
	{

		value = (value > DISP_2DCVT3D_3D_DEPTH_MAX_VALUE? DISP_2DCVT3D_3D_DEPTH_MAX_VALUE:
			(value < -DISP_2DCVT3D_3D_DEPTH_MAX_VALUE? -DISP_2DCVT3D_3D_DEPTH_MAX_VALUE: value));

	       cur2Dcvt3D_Depth=DISP_2DCVT3D_3D_DEPTH_MAX_VALUE-value;//JunnyModify20130529

		pr_debug("[2D3D] Scaler_Set2DCvt3D_Depth ,set depth=%d,value=%d \n", cur2Dcvt3D_Depth,value);

		if(Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE) == SLR_3D_2D_CVT_3D)
			drv_2D_to_3D_H_shift(cur2Dcvt3D_Depth);
	}
	return;
}

//Add for Macarthur, by Lydia

int scalerDrv_2D_to_3D_Obj_get_en(void)	// 2D to 3D object function on or off
{
	int selection;
	int obj1=0,obj2=0,obj3=0;

	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_control;
	reg_d_2d3d_control.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);

	obj1=reg_d_2d3d_control.object1_depth_en;
	obj2=reg_d_2d3d_control.object2_depth_en;
	obj3=reg_d_2d3d_control.object3_depth_en;

	selection=obj1 + (obj2<<1) + (obj3<<2);

	return selection;
}

void drv_2D_to_3D_en_shiftmode(EN_SHIFTMODE_TYPE level)	// no shift: 0 , shift left:1 , right:2, shift both:3(defult),     2D3D on /off
{

	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_control;
	d_2d_to_3d_d_2d3d_db_control_RBUS d_2d3d_double_buffer_control_reg;
	reg_d_2d3d_control.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);

	switch(level)
		{
			case SHIFTMODE_NO:
				reg_d_2d3d_control.l_frame_shift_en = 0;
				reg_d_2d3d_control.r_frame_shift_en = 0;
				break;
			case SHIFTMODE_L:
				reg_d_2d3d_control.l_frame_shift_en = 1;
				reg_d_2d3d_control.r_frame_shift_en = 0;
				break;
			case SHIFTMODE_R:
				reg_d_2d3d_control.r_frame_shift_en = 0;
				reg_d_2d3d_control.r_frame_shift_en = 1;
				break;
			case SHIFTMODE_L_R:
				reg_d_2d3d_control.l_frame_shift_en = 1;
				reg_d_2d3d_control.r_frame_shift_en = 1;
				break;
			default:
				break;
		}

	IoReg_Write32(D_2D_TO_3D_D_2D3D_Control_reg, reg_d_2d3d_control.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Control_reg, reg_d_2d3d_control.regValue);

	// apply register double buffer
	d_2d3d_double_buffer_control_reg.regValue =IoReg_Read32(D_2D_TO_3D_D_2D3D_Db_Control_reg);
	if(d_2d3d_double_buffer_control_reg.db_en){
		d_2d3d_double_buffer_control_reg.db_read_level = 0;
		d_2d3d_double_buffer_control_reg.db_apply = 1;
		IoReg_Write32(D_2D_TO_3D_D_2D3D_Db_Control_reg, d_2d3d_double_buffer_control_reg.regValue);
	}

	return;
}

void drv_2D_to_3D_Initialize(void)
{
	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_control;
	d_2d_to_3d_d_2d3d_db_control_RBUS d_2d3d_double_buffer_control_reg;
	d_2d_to_3d_d_2d3d_shifter_RBUS reg_d_2d3d_shifter;
	d_2d_to_3d_d_2d3d_b_border_RBUS reg_d_2d3d_b_border;//default:disable
	d_2d_to_3d_d_2d3d_depth_fil_RBUS reg_d_2d3d_depth_fil;//default:disable
	d_2d_to_3d_d_2d3d_hole_fill_RBUS reg_d_2d3d_hole_fill;//defult: type 0
	d_2d_to_3d_d_2d3d_output_fil_y_RBUS reg_d_2d3d_output_fil_y;//default:disable
	d_2d_to_3d_d_2d3d_output_fil_c_RBUS reg_d_2d3d_output_fil_c;//default:disable

	d_2d3d_double_buffer_control_reg.regValue =IoReg_Read32(D_2D_TO_3D_D_2D3D_Db_Control_reg);
	d_2d3d_double_buffer_control_reg.db_en = 0;//disable 2d cvt 3d double buffer
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Db_Control_reg, d_2d3d_double_buffer_control_reg.regValue);

	reg_d_2d3d_control.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);
	reg_d_2d3d_control.output_format = Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE();
	reg_d_2d3d_control.d_2d3d_depth_frac_en = 1;
	reg_d_2d3d_control.l_flag_inv = 0;
	reg_d_2d3d_control.tilt_depth_en = 0;
	reg_d_2d3d_control.object1_depth_en = 0;
	reg_d_2d3d_control.object2_depth_en =0;
	reg_d_2d3d_control.object3_depth_en =0;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Control_reg, reg_d_2d3d_control.regValue);

	reg_d_2d3d_shifter.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_SHIFTER_reg);
	reg_d_2d3d_shifter.shifter_thd = 0x1c;
	reg_d_2d3d_shifter.shifter_offset = 0;
	reg_d_2d3d_shifter.shifter_gain = 0x10;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_SHIFTER_reg, reg_d_2d3d_shifter.regValue);

	reg_d_2d3d_b_border.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_B_BORDER_reg);
	reg_d_2d3d_b_border.border_en = 0;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_B_BORDER_reg, reg_d_2d3d_b_border.regValue);

	reg_d_2d3d_depth_fil.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_DEPTH_FIL_reg);
	reg_d_2d3d_depth_fil.d_2d3d_depth_lpf_en = 0;
	reg_d_2d3d_depth_fil.d_2d3d_depth_lpf_c0 = 6;
	reg_d_2d3d_depth_fil.d_2d3d_depth_lpf_c1 = 4;
	reg_d_2d3d_depth_fil.d_2d3d_depth_lpf_c2 = 1;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_DEPTH_FIL_reg, reg_d_2d3d_depth_fil.regValue);

	reg_d_2d3d_hole_fill.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_HOLE_FILL_reg);
	reg_d_2d3d_hole_fill.hole_fil_sel= 0;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_HOLE_FILL_reg, reg_d_2d3d_hole_fill.regValue);

	reg_d_2d3d_output_fil_y.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_reg);
	reg_d_2d3d_output_fil_y.d_2d3d_output_lpf_y_en= 0;
	reg_d_2d3d_output_fil_y.d_2d3d_output_y_lpf_c0 = 6;
	reg_d_2d3d_output_fil_y.d_2d3d_output_y_lpf_c1 = 4;
	reg_d_2d3d_output_fil_y.d_2d3d_output_y_lpf_c2 = 1;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_reg, reg_d_2d3d_output_fil_y.regValue);

	reg_d_2d3d_output_fil_c.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_reg);
	reg_d_2d3d_output_fil_c.d_2d3d_output_lpf_c_en = 0;
	reg_d_2d3d_output_fil_c.d_2d3d_output_c_lpf_c0 = 6;
	reg_d_2d3d_output_fil_c.d_2d3d_output_c_lpf_c1 = 4;
	reg_d_2d3d_output_fil_c.d_2d3d_output_c_lpf_c2 = 1;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_reg, reg_d_2d3d_output_fil_c.regValue);


}

void drv_2D_to_3D_set_frac_en(bool setting)	// depth fraction mode enable
{
	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_control;
	reg_d_2d3d_control.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);

	reg_d_2d3d_control.d_2d3d_depth_frac_en = setting;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Control_reg, reg_d_2d3d_control.regValue);
}



unsigned int drv_2D_to_3D_get_tilt_depth_en(void)	//Get enable Tilt depth calculation
{
	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_control;
	reg_d_2d3d_control.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);

	return reg_d_2d3d_control.tilt_depth_en;
}


void drv_2D_to_3D_set_tilt_depth_en(bool setting)	// Enable Tilt depth calculation
{
	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_control;
	reg_d_2d3d_control.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);
	WaitFor_DEN_STOP();
	reg_d_2d3d_control.tilt_depth_en = setting;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Control_reg, reg_d_2d3d_control.regValue);

	//initialize
	if(setting ==1)
	{
		d_2d_to_3d_d_2d3d_tilt_operation_RBUS reg_d_2d3d_tilt_operation;
		d_2d_to_3d_d_2d3d_tilt_depth_RBUS reg_d_2d3d_tilt_depth;

		reg_d_2d3d_tilt_operation.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Tilt_Operation_reg);
		reg_d_2d3d_tilt_operation.tilt_thd = 0xff;
		reg_d_2d3d_tilt_operation.tilt_offset = 0;
		reg_d_2d3d_tilt_operation.tilt_gain = 0x10;//16
		WaitFor_DEN_STOP();
		IoReg_Write32(D_2D_TO_3D_D_2D3D_Tilt_Operation_reg, reg_d_2d3d_tilt_operation.regValue);

		reg_d_2d3d_tilt_depth.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg);
		reg_d_2d3d_tilt_depth.tilt_depth_step = 0x70;//112
		reg_d_2d3d_tilt_depth.initial_depth = 0;
		IoReg_Write32(D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg, reg_d_2d3d_tilt_depth.regValue);
	}

}

// Enable Object depth calculation,
//8case(0~7)
//000:all disable,    001:obj1,            010:obj2,            100:obj3,
//011:obj1&obj2,    101:obj1&obj3,    110:obj2&obj3,   111:obj1&obj2&obj3
//obj1 default: refY=0, refU=128, refV=128 (same as Darwin Object setting),dir=0
//obj2 default: refY=64, refU=192, refV=0 (blue),dir=0
//obj3 default: refY=190, refU=100, refV=140 (skin),dir=-1
void drv_2D_to_3D_set_object_depth_en(int selection)//0~7
{
	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_control;
	d_2d_to_3d_d_2d3d_object1_depth1_RBUS reg_d_2d3d_object1_depth1;
	d_2d_to_3d_d_2d3d_object1_depth2_RBUS reg_d_2d3d_object1_depth2;
	d_2d_to_3d_d_2d3d_object2_depth1_RBUS reg_d_2d3d_object2_depth1;
	d_2d_to_3d_d_2d3d_object2_depth2_RBUS reg_d_2d3d_object2_depth2;
	d_2d_to_3d_d_2d3d_object3_depth1_RBUS reg_d_2d3d_object3_depth1;
	d_2d_to_3d_d_2d3d_object3_depth2_RBUS reg_d_2d3d_object3_depth2;

	reg_d_2d3d_control.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);
	reg_d_2d3d_object1_depth1.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg);
	reg_d_2d3d_object1_depth2.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_reg);
	reg_d_2d3d_object2_depth1.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_reg);
	reg_d_2d3d_object2_depth2.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_reg);
	reg_d_2d3d_object3_depth1.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_reg);
	reg_d_2d3d_object3_depth2.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_reg);


	switch(selection)
	{
		case 0:
			reg_d_2d3d_control.object1_depth_en = 0;
			reg_d_2d3d_control.object2_depth_en = 0;
			reg_d_2d3d_control.object3_depth_en = 0;
			break;
		case 1:
			reg_d_2d3d_control.object1_depth_en = 1;
			reg_d_2d3d_control.object2_depth_en = 0;
			reg_d_2d3d_control.object3_depth_en = 0;
			reg_d_2d3d_object1_depth1.object1_depth_ref1=0;//y=0
			reg_d_2d3d_object1_depth2.object1_depth_ref2=0x80;//u=128
			reg_d_2d3d_object1_depth2.object1_depth_ref3=0x80;//v=128
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object1_depth1.object1_depth_gain=16;
			reg_d_2d3d_object1_depth1.object1_depth_dir=0;

			break;
		case 2:
			reg_d_2d3d_control.object1_depth_en = 0;
			reg_d_2d3d_control.object2_depth_en = 1;
			reg_d_2d3d_control.object3_depth_en = 0;
			reg_d_2d3d_object2_depth1.object2_depth_ref1=64;
			reg_d_2d3d_object2_depth2.object2_depth_ref2=192;
			reg_d_2d3d_object2_depth2.object2_depth_ref3=0;
			reg_d_2d3d_object2_depth1.object2_depth_dir=0;
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object2_depth1.object2_depth_gain=16;
			break;
		case 3:
			reg_d_2d3d_control.object1_depth_en = 1;
			reg_d_2d3d_control.object2_depth_en = 1;
			reg_d_2d3d_control.object3_depth_en = 0;
			reg_d_2d3d_object1_depth1.object1_depth_ref1=0;//y=0
			reg_d_2d3d_object1_depth2.object1_depth_ref2=0x80;//u=128
			reg_d_2d3d_object1_depth2.object1_depth_ref3=0x80;//v=128
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object1_depth1.object1_depth_gain=16;
			reg_d_2d3d_object1_depth1.object1_depth_dir=0;
			reg_d_2d3d_object2_depth1.object2_depth_ref1=64;
			reg_d_2d3d_object2_depth2.object2_depth_ref2=192;
			reg_d_2d3d_object2_depth2.object2_depth_ref3=0;
			reg_d_2d3d_object2_depth1.object2_depth_dir=0;
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object2_depth1.object2_depth_gain=16;
			break;
		case 4:
			reg_d_2d3d_control.object1_depth_en = 0;
			reg_d_2d3d_control.object2_depth_en = 0;
			reg_d_2d3d_control.object3_depth_en = 1;
			reg_d_2d3d_object3_depth1.object3_depth_ref1=190;
			reg_d_2d3d_object3_depth2.object3_depth_ref2=100;
			reg_d_2d3d_object3_depth2.object3_depth_ref3=140;
			reg_d_2d3d_object3_depth1.object3_depth_dir=1;
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object3_depth1.object3_depth_gain=16;
			break;
		case 5:
			reg_d_2d3d_control.object1_depth_en = 1;
			reg_d_2d3d_control.object2_depth_en = 0;
			reg_d_2d3d_control.object3_depth_en = 1;
			reg_d_2d3d_object1_depth1.object1_depth_ref1=0;//y=0
			reg_d_2d3d_object1_depth2.object1_depth_ref2=0x80;//u=128
			reg_d_2d3d_object1_depth2.object1_depth_ref3=0x80;//v=128
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object1_depth1.object1_depth_gain=16;
			reg_d_2d3d_object1_depth1.object1_depth_dir=0;
			reg_d_2d3d_object3_depth1.object3_depth_ref1=190;
			reg_d_2d3d_object3_depth2.object3_depth_ref2=100;
			reg_d_2d3d_object3_depth2.object3_depth_ref3=140;
			reg_d_2d3d_object3_depth1.object3_depth_dir=1;
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object3_depth1.object3_depth_gain=16;
			break;
		case 6:
			reg_d_2d3d_control.object1_depth_en = 0;
			reg_d_2d3d_control.object2_depth_en = 1;
			reg_d_2d3d_control.object3_depth_en = 1;
			reg_d_2d3d_object2_depth1.object2_depth_ref1=64;
			reg_d_2d3d_object2_depth2.object2_depth_ref2=192;
			reg_d_2d3d_object2_depth2.object2_depth_ref3=0;
			reg_d_2d3d_object2_depth1.object2_depth_dir=0;
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object2_depth1.object2_depth_gain=16;
			reg_d_2d3d_object3_depth1.object3_depth_ref1=190;
			reg_d_2d3d_object3_depth2.object3_depth_ref2=100;
			reg_d_2d3d_object3_depth2.object3_depth_ref3=140;
			reg_d_2d3d_object3_depth1.object3_depth_dir=1;
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object3_depth1.object3_depth_gain=16;
			break;
		case 7:
			reg_d_2d3d_control.object1_depth_en = 1;
			reg_d_2d3d_control.object2_depth_en = 1;
			reg_d_2d3d_control.object3_depth_en = 1;
			reg_d_2d3d_object1_depth1.object1_depth_ref1=0;//y=0
			reg_d_2d3d_object1_depth2.object1_depth_ref2=0x80;//u=128
			reg_d_2d3d_object1_depth2.object1_depth_ref3=0x80;//v=128
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object1_depth1.object1_depth_gain=16;
			reg_d_2d3d_object1_depth1.object1_depth_dir=0;
			reg_d_2d3d_object2_depth1.object2_depth_ref1=64;
			reg_d_2d3d_object2_depth2.object2_depth_ref2=192;
			reg_d_2d3d_object2_depth2.object2_depth_ref3=0;
			reg_d_2d3d_object2_depth1.object2_depth_dir=0;
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object2_depth1.object2_depth_gain=16;
			reg_d_2d3d_object3_depth1.object3_depth_ref1=190;
			reg_d_2d3d_object3_depth2.object3_depth_ref2=100;
			reg_d_2d3d_object3_depth2.object3_depth_ref3=140;
			reg_d_2d3d_object3_depth1.object3_depth_dir=1;
			//[crixus 20140721]remove in mac3~reg_d_2d3d_object3_depth1.object3_depth_gain=16;
			break;
		default:
			break;


	}


	IoReg_Write32(D_2D_TO_3D_D_2D3D_Control_reg, reg_d_2d3d_control.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_reg, reg_d_2d3d_object1_depth1.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_reg, reg_d_2d3d_object1_depth2.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_reg, reg_d_2d3d_object2_depth1.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_reg, reg_d_2d3d_object2_depth2.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_reg, reg_d_2d3d_object3_depth1.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_reg, reg_d_2d3d_object3_depth2.regValue);

}

void drv_2D_to_3D_set_depth_filter(bool setting,UINT8 c0,UINT8 c1,UINT8 c2)	// depth low pass filter , enable & coefficients
{

	d_2d_to_3d_d_2d3d_depth_fil_RBUS reg_d_2d3d_depth_fil;
	reg_d_2d3d_depth_fil.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_DEPTH_FIL_reg);

	reg_d_2d3d_depth_fil.d_2d3d_depth_lpf_en = setting;
	reg_d_2d3d_depth_fil.d_2d3d_depth_lpf_c0 = c0;
	reg_d_2d3d_depth_fil.d_2d3d_depth_lpf_c1 = c1;
	reg_d_2d3d_depth_fil.d_2d3d_depth_lpf_c2 = c2;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_DEPTH_FIL_reg, reg_d_2d3d_depth_fil.regValue);
}

void drv_2D_to_3D_set_hole_fill_type(UINT8 type)	// depth low pass filter , enable & coefficients
{
	d_2d_to_3d_d_2d3d_hole_fill_RBUS reg_d_2d3d_hole_fill;
	reg_d_2d3d_hole_fill.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_HOLE_FILL_reg);

	reg_d_2d3d_hole_fill.hole_fil_sel= type;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_HOLE_FILL_reg, reg_d_2d3d_hole_fill.regValue);
}

void drv_2D_to_3D_set_output_filter_y(bool setting,UINT8 c0,UINT8 c1,UINT8 c2)	// y output low pass filter , enable & coefficients
{
	d_2d_to_3d_d_2d3d_output_fil_y_RBUS reg_d_2d3d_output_fil_y;
	reg_d_2d3d_output_fil_y.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_reg);

	reg_d_2d3d_output_fil_y.d_2d3d_output_lpf_y_en= setting;
	reg_d_2d3d_output_fil_y.d_2d3d_output_y_lpf_c0 = c0;
	reg_d_2d3d_output_fil_y.d_2d3d_output_y_lpf_c1 = c1;
	reg_d_2d3d_output_fil_y.d_2d3d_output_y_lpf_c2 = c2;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_reg, reg_d_2d3d_output_fil_y.regValue);
}

//Register::D_2D3D_OUTPUT_FIL_C
void drv_2D_to_3D_set_output_filter_c(bool setting,UINT8 c0,UINT8 c1,UINT8 c2)	// c output low pass filter , enable & coefficients
{
	d_2d_to_3d_d_2d3d_output_fil_c_RBUS reg_d_2d3d_output_fil_c;
	reg_d_2d3d_output_fil_c.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_reg);

	reg_d_2d3d_output_fil_c.d_2d3d_output_lpf_c_en = setting;
	reg_d_2d3d_output_fil_c.d_2d3d_output_c_lpf_c0 = c0;
	reg_d_2d3d_output_fil_c.d_2d3d_output_c_lpf_c1 = c1;
	reg_d_2d3d_output_fil_c.d_2d3d_output_c_lpf_c2 = c2;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_reg, reg_d_2d3d_output_fil_c.regValue);
}
void drv_2D_to_3D_set_tilt_depth(bool enable,int step)	// Enable Tilt depth calculation
{
	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_control;
	d_2d_to_3d_d_2d3d_db_control_RBUS d_2d3d_double_buffer_control_reg;
	reg_d_2d3d_control.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);
	WaitFor_DEN_STOP();
	reg_d_2d3d_control.tilt_depth_en = enable;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Control_reg, reg_d_2d3d_control.regValue);

	//initialize
	if(enable ==1)
	{
		d_2d_to_3d_d_2d3d_tilt_operation_RBUS reg_d_2d3d_tilt_operation;
		d_2d_to_3d_d_2d3d_tilt_depth_RBUS reg_d_2d3d_tilt_depth;

		reg_d_2d3d_tilt_operation.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Tilt_Operation_reg);
		reg_d_2d3d_tilt_operation.tilt_thd = 0xff;
		reg_d_2d3d_tilt_operation.tilt_offset = 0;
		reg_d_2d3d_tilt_operation.tilt_gain = 0x10;//16
		WaitFor_DEN_STOP();
		IoReg_Write32(D_2D_TO_3D_D_2D3D_Tilt_Operation_reg, reg_d_2d3d_tilt_operation.regValue);

		reg_d_2d3d_tilt_depth.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg);
		reg_d_2d3d_tilt_depth.tilt_depth_step = step;//112
		reg_d_2d3d_tilt_depth.initial_depth = 0;
		IoReg_Write32(D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg, reg_d_2d3d_tilt_depth.regValue);
	}

	// apply register double buffer
	d_2d3d_double_buffer_control_reg.regValue =IoReg_Read32(D_2D_TO_3D_D_2D3D_Db_Control_reg);
	if(d_2d3d_double_buffer_control_reg.db_en){
		d_2d3d_double_buffer_control_reg.db_read_level = 0;
		d_2d3d_double_buffer_control_reg.db_apply = 1;
		IoReg_Write32(D_2D_TO_3D_D_2D3D_Db_Control_reg, d_2d3d_double_buffer_control_reg.regValue);
	}

	return;
}
void drv_2D_to_3D_H_shift(int focal_pos) //strength:static , focal: 0~32 ,for TV15_1_3D
{
	int gain,offset,flag=0;
	d_2d_to_3d_d_2d3d_shifter_RBUS reg_d_2d3d_shifter;
	d_2d_to_3d_d_2d3d_db_control_RBUS d_2d3d_double_buffer_control_reg;
	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_ctrl;

	reg_d_2d3d_shifter.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_SHIFTER_reg);

	reg_d_2d3d_ctrl.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);

	reg_d_2d3d_shifter.shifter_thd = 0x1c;

	if(focal_pos==12)
		offset=0;
	else if(focal_pos<12)  //0-12 ,0-140
	{
		flag=1;
		offset = (12-focal_pos)*11+8;
	}
	else if(focal_pos>12)  //12-32, 0-140
	{
		flag=0;
		if(focal_pos==16)
			offset = 56;
		else if(focal_pos<16)
			offset = (focal_pos-12)*14+4;
		else if(focal_pos>16)
			offset = (focal_pos-12)*4+60;

	}

	reg_d_2d3d_ctrl.l_flag_inv = flag;
	gain = 50;
	reg_d_2d3d_ctrl.l_frame_shift_en = 1;
	reg_d_2d3d_ctrl.r_frame_shift_en = 1;
	pr_debug("[2D3DH_shift]reg_d_2d3d_ctrl.r_frame_shift_en=%d,l_frame_shift_en=%d,gain=%d,offset=%d\n",reg_d_2d3d_ctrl.r_frame_shift_en,reg_d_2d3d_ctrl.l_frame_shift_en,gain,offset);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Control_reg, reg_d_2d3d_ctrl.regValue);

	reg_d_2d3d_shifter.shifter_offset = offset;
	reg_d_2d3d_shifter.shifter_gain = gain;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_SHIFTER_reg, reg_d_2d3d_shifter.regValue);

	// apply register double buffer
	d_2d3d_double_buffer_control_reg.regValue =IoReg_Read32(D_2D_TO_3D_D_2D3D_Db_Control_reg);
	if(d_2d3d_double_buffer_control_reg.db_en){
		d_2d3d_double_buffer_control_reg.db_read_level = 0;
		d_2d3d_double_buffer_control_reg.db_apply = 1;
		IoReg_Write32(D_2D_TO_3D_D_2D3D_Db_Control_reg, d_2d3d_double_buffer_control_reg.regValue);
	}

	pr_debug("[2D3D][DBG] en/rdLvl=%d/%d, %x\n", d_2d3d_double_buffer_control_reg.db_en, d_2d3d_double_buffer_control_reg.db_read_level, IoReg_Read32(D_2D_TO_3D_D_2D3D_Db_Control_reg));
}


void drv_2D_to_3D_H_shift_no_border(int focal_pos) //strength:static , focal: 0~32
{
   	int gain,offset,flag=0;
	d_2d_to_3d_d_2d3d_shifter_RBUS reg_d_2d3d_shifter;
	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_ctrl;
	d_2d_to_3d_d_2d3d_tilt_depth_RBUS reg_d_2d3d_tilt_depth;
	d_2d_to_3d_d_2d3d_boundary_scaling_RBUS reg_d_2d3d_boundary_scaling;
	d_2d_to_3d_d_2d3d_db_control_RBUS d_2d3d_double_buffer_control_reg;
	reg_d_2d3d_shifter.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_SHIFTER_reg);

	reg_d_2d3d_ctrl.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);

	reg_d_2d3d_tilt_depth.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg);

	reg_d_2d3d_boundary_scaling.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_boundary_scaling_reg);

	d_2d3d_double_buffer_control_reg.regValue =IoReg_Read32(D_2D_TO_3D_D_2D3D_Db_Control_reg);

	reg_d_2d3d_shifter.shifter_thd = 0x1c;

//JunnyModify20130718  for skyworth 299x  0 ~140
//==>
       if(focal_pos>32)// 0~32
	   	focal_pos=32;
	 else if(focal_pos<0)
	 	focal_pos=0;

	flag=0;
	if(focal_pos==15)
	{
		offset = 0;
	}
	else if(focal_pos<15)
	{
		flag=0;
		offset = (15 - focal_pos)*9+8;
       }
	else// if(focal_pos>15)
	{
	       flag=1;
		offset = (focal_pos - 15)*9+8;
	}
//<==

	// 2Dcvt3D depth invert for CMI Millet3 V500 4k2k panel
	if(Get_PANEL_TYPE_IS_MILLET3_4K2K_SERIES())
		flag = !flag;

	gain = 50;
	reg_d_2d3d_ctrl.l_flag_inv = flag;
	reg_d_2d3d_ctrl.l_frame_shift_en = 1;
	reg_d_2d3d_ctrl.r_frame_shift_en = 1;
	reg_d_2d3d_ctrl.tilt_depth_en = 1;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Control_reg, reg_d_2d3d_ctrl.regValue);

	reg_d_2d3d_shifter.shifter_offset = 0;
	reg_d_2d3d_shifter.shifter_gain = gain;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_SHIFTER_reg, reg_d_2d3d_shifter.regValue);

	reg_d_2d3d_tilt_depth.initial_depth = offset;
	reg_d_2d3d_tilt_depth.tilt_depth_step = 0;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_TILT_DEPTH_reg, reg_d_2d3d_tilt_depth.regValue);

	reg_d_2d3d_boundary_scaling.dbs_en = 1;
	reg_d_2d3d_boundary_scaling.dbs_seg_num = 1;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_boundary_scaling_reg, reg_d_2d3d_boundary_scaling.regValue);

	// apply register double buffer
	if(d_2d3d_double_buffer_control_reg.db_en){
		d_2d3d_double_buffer_control_reg.db_read_level = 0;
		d_2d3d_double_buffer_control_reg.db_apply = 1;
		IoReg_Write32(D_2D_TO_3D_D_2D3D_Db_Control_reg, d_2d3d_double_buffer_control_reg.regValue);
	}

	pr_debug("[2D3D] No Border, flag=%d,offset=%d\n", flag,offset);
}


void drv_2D_to_3D_shifter(int strength, int focal_pos) // strength: 0~15 , focal: 0~15
{
    	int gain,offset;
	d_2d_to_3d_d_2d3d_shifter_RBUS reg_d_2d3d_shifter;
	reg_d_2d3d_shifter.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_SHIFTER_reg);

	reg_d_2d3d_shifter.shifter_thd = 0x1c;

	if(strength==0)//default=8
		gain=0;
	else
		gain = 30+strength*2;

	offset=(focal_pos)*7;//default=8

	reg_d_2d3d_shifter.shifter_offset = offset;
	reg_d_2d3d_shifter.shifter_gain = gain;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_SHIFTER_reg, reg_d_2d3d_shifter.regValue);
	//printk("[DBG] Strength/depth=%d/%d\n", strength, focal_pos);

}

void drv_2D_to_3D_LR_swap(bool lr_swap)
{
	d_2d_to_3d_d_2d3d_control_RBUS reg_d_2d3d_control;
	reg_d_2d3d_control.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_Control_reg);

	if(lr_swap==_FALSE)
		reg_d_2d3d_control.l_flag_inv=0;
	else
		reg_d_2d3d_control.l_flag_inv=1;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_Control_reg, reg_d_2d3d_control.regValue);
}
#if 0
int ceil(float num) {
    int inum = (int)num;
    if (num == (float)inum) {
        return inum;
    }
    return inum + 1;
}
#endif
#if 0 // for Magellan only
void drv_2D_to_3D_histo_depth_en(bool enable)
{
	int Width, Height;

	Width = Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID);
	Height = Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN);

	d_2d3d_histo_ctrl0_RBUS reg_d_2d3d_histo_control;
	reg_d_2d3d_histo_control.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_HISTO_CTRL0_reg);

	d_2d3d_histo_su_ctrl0_RBUS reg_d_2d3d_histo_su_control0;
	reg_d_2d3d_histo_su_control0.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_reg);

	d_2d3d_histo_su_ctrl2_RBUS reg_d_2d3d_histo_su_control2;
	reg_d_2d3d_histo_su_control2.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_reg);

	if(enable==0)
		reg_d_2d3d_histo_control.histo_en=0;
	else
		reg_d_2d3d_histo_control.histo_en=1;

	reg_d_2d3d_histo_control.h_grid_size=ceil(Width/32);
	reg_d_2d3d_histo_control.v_grid_size=ceil(Height/16);
	reg_d_2d3d_histo_su_control0.su_en=1;
	reg_d_2d3d_histo_su_control0.su_hfactor=(2<<20)/Width*32;
	reg_d_2d3d_histo_su_control2.su_vfactor=(2<<20)/Height*16;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_HISTO_CTRL0_reg,reg_d_2d3d_histo_control.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL0_reg,reg_d_2d3d_histo_su_control0.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_HISTO_SU_CTRL2_reg,reg_d_2d3d_histo_su_control2.regValue);

}

void drv_2D_to_3D_histo_depth_temporal_ctrl(int level)//0:disbale, 1~7:enable, temporal condition strength
{

	d_2d3d_histo_temp_0_RBUS reg_d_2d3d_histo_temp0;
	reg_d_2d3d_histo_temp0.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_reg);

	d_2d3d_histo_temp_1_RBUS reg_d_2d3d_histo_temp1;
	reg_d_2d3d_histo_temp1.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_reg);

	d_2d3d_histo_iir_RBUS reg_d_2d3d_histo_iir;
	reg_d_2d3d_histo_iir.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_HISTO_IIR_reg);


	if(level==0)
	{
		reg_d_2d3d_histo_temp0.temporal_1_en=0;
		reg_d_2d3d_histo_temp0.temporal_2_en=0;
		reg_d_2d3d_histo_temp1.temporal_3_en=0;
		reg_d_2d3d_histo_iir.iir_en=0;

	}
	else
	{
		reg_d_2d3d_histo_temp0.temporal_1_en=1;
		reg_d_2d3d_histo_temp0.temporal_2_en=1;
		reg_d_2d3d_histo_temp1.temporal_3_en=1;
		reg_d_2d3d_histo_iir.iir_en=1;

		switch(level)
		{
			case 1:
				reg_d_2d3d_histo_temp0.temporal_1_th_l=0;
				reg_d_2d3d_histo_temp0.temporal_1_th_s=0;
				reg_d_2d3d_histo_temp0.temporal_2_th_l=0;
				reg_d_2d3d_histo_temp0.temporal_2_th_s=0;
				reg_d_2d3d_histo_temp1.temporal_3_th_l=0;
				reg_d_2d3d_histo_temp1.temporal_3_th_s=0;
				break;
			case 2:
				reg_d_2d3d_histo_temp0.temporal_1_th_l=1;
				reg_d_2d3d_histo_temp0.temporal_1_th_s=1;
				reg_d_2d3d_histo_temp0.temporal_2_th_l=1;
				reg_d_2d3d_histo_temp0.temporal_2_th_s=1;
				reg_d_2d3d_histo_temp1.temporal_3_th_l=1;
				reg_d_2d3d_histo_temp1.temporal_3_th_s=1;
				break;
			case 3:
				reg_d_2d3d_histo_temp0.temporal_1_th_l=2;
				reg_d_2d3d_histo_temp0.temporal_1_th_s=2;
				reg_d_2d3d_histo_temp0.temporal_2_th_l=2;
				reg_d_2d3d_histo_temp0.temporal_2_th_s=2;
				reg_d_2d3d_histo_temp1.temporal_3_th_l=2;
				reg_d_2d3d_histo_temp1.temporal_3_th_s=2;
				break;
			case 4:
				reg_d_2d3d_histo_temp0.temporal_1_th_l=3;
				reg_d_2d3d_histo_temp0.temporal_1_th_s=3;
				reg_d_2d3d_histo_temp0.temporal_2_th_l=3;
				reg_d_2d3d_histo_temp0.temporal_2_th_s=3;
				reg_d_2d3d_histo_temp1.temporal_3_th_l=3;
				reg_d_2d3d_histo_temp1.temporal_3_th_s=3;
				break;
			case 5:
				reg_d_2d3d_histo_temp0.temporal_1_th_l=4;
				reg_d_2d3d_histo_temp0.temporal_1_th_s=4;
				reg_d_2d3d_histo_temp0.temporal_2_th_l=4;
				reg_d_2d3d_histo_temp0.temporal_2_th_s=4;
				reg_d_2d3d_histo_temp1.temporal_3_th_l=4;
				reg_d_2d3d_histo_temp1.temporal_3_th_s=4;
				break;
			case 6:
				reg_d_2d3d_histo_temp0.temporal_1_th_l=5;
				reg_d_2d3d_histo_temp0.temporal_1_th_s=5;
				reg_d_2d3d_histo_temp0.temporal_2_th_l=5;
				reg_d_2d3d_histo_temp0.temporal_2_th_s=5;
				reg_d_2d3d_histo_temp1.temporal_3_th_l=5;
				reg_d_2d3d_histo_temp1.temporal_3_th_s=5;
				break;
			case 7:
				reg_d_2d3d_histo_temp0.temporal_1_th_l=6;
				reg_d_2d3d_histo_temp0.temporal_1_th_s=6;
				reg_d_2d3d_histo_temp0.temporal_2_th_l=6;
				reg_d_2d3d_histo_temp0.temporal_2_th_s=6;
				reg_d_2d3d_histo_temp1.temporal_3_th_l=6;
				reg_d_2d3d_histo_temp1.temporal_3_th_s=6;
				break;
			default:
				break;

		}
	}

	IoReg_Write32(D_2D_TO_3D_D_2D3D_HISTO_TEMP_0_reg,reg_d_2d3d_histo_temp0.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_HISTO_TEMP_1_reg,reg_d_2d3d_histo_temp1.regValue);
	IoReg_Write32(D_2D_TO_3D_D_2D3D_HISTO_IIR_reg,reg_d_2d3d_histo_iir.regValue);
}
#endif // for Magellan only

void drv_2D_to_3D_depth_boundary_scaling_en(bool enable)
{
	d_2d_to_3d_d_2d3d_boundary_scaling_RBUS reg_d_2d3d_boundary_scaling;
	d_2d_to_3d_d_2d3d_db_control_RBUS d_2d3d_double_buffer_control_reg;
	reg_d_2d3d_boundary_scaling.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_boundary_scaling_reg);

	if(enable==0)
		reg_d_2d3d_boundary_scaling.dbs_en=0;
	else
		reg_d_2d3d_boundary_scaling.dbs_en=1;

	IoReg_Write32(D_2D_TO_3D_D_2D3D_boundary_scaling_reg,reg_d_2d3d_boundary_scaling.regValue);

	// apply register double buffer
	d_2d3d_double_buffer_control_reg.regValue =IoReg_Read32(D_2D_TO_3D_D_2D3D_Db_Control_reg);
	if(d_2d3d_double_buffer_control_reg.db_en){
		d_2d3d_double_buffer_control_reg.db_read_level = 0;
		d_2d3d_double_buffer_control_reg.db_apply = 1;
		IoReg_Write32(D_2D_TO_3D_D_2D3D_Db_Control_reg, d_2d3d_double_buffer_control_reg.regValue);
	}
}

void drv_2D_to_3D_set_depth_boundary_scaling(int seg_num)
{
	d_2d_to_3d_d_2d3d_boundary_scaling_RBUS reg_d_2d3d_boundary_scaling;
	reg_d_2d3d_boundary_scaling.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_boundary_scaling_reg);

	if(seg_num<4)
		reg_d_2d3d_boundary_scaling.dbs_seg_num=seg_num;


	IoReg_Write32(D_2D_TO_3D_D_2D3D_boundary_scaling_reg,reg_d_2d3d_boundary_scaling.regValue);

}


unsigned int drv_2D_to_3D_get_depth_boundary_scaling(void)
{
	d_2d_to_3d_d_2d3d_boundary_scaling_RBUS reg_d_2d3d_boundary_scaling;
	reg_d_2d3d_boundary_scaling.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_boundary_scaling_reg);

	return reg_d_2d3d_boundary_scaling.dbs_seg_num;
}

//#ifdef BUILD_TV035_1
void drv_2D_to_3D_shifter_gain(unsigned char shift_gain)
{
	d_2d_to_3d_d_2d3d_shifter_RBUS reg_d_2d3d_shifter;
	reg_d_2d3d_shifter.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_SHIFTER_reg);

	reg_d_2d3d_shifter.shifter_gain = shift_gain;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_SHIFTER_reg, reg_d_2d3d_shifter.regValue);
}

void drv_2D_to_3D_shifter_offset(unsigned char shift_offset)
{
	d_2d_to_3d_d_2d3d_shifter_RBUS reg_d_2d3d_shifter;
	reg_d_2d3d_shifter.regValue = IoReg_Read32(D_2D_TO_3D_D_2D3D_SHIFTER_reg);

	reg_d_2d3d_shifter.shifter_offset = shift_offset;
	IoReg_Write32(D_2D_TO_3D_D_2D3D_SHIFTER_reg, reg_d_2d3d_shifter.regValue);
}
//#endif
