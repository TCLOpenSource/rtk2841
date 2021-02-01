#ifndef _CONVERSION_2D_3D_H
#define _CONVERSION_2D_3D_H

//#include "rtd_types.h"
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;

// no shift: 0 , shift left:1 , right:2, shift both:3(defult),     2D3D on /off
typedef enum _EN_SHIFTMODE_TYPE{
	SHIFTMODE_NO,
	SHIFTMODE_L,
	SHIFTMODE_R,
	SHIFTMODE_L_R
}EN_SHIFTMODE_TYPE;


void scalerDrv_2D_to_3D_Obj_initialize(void);	// turn off function in default
void scalerDrv_2D_to_3D_Obj_set_en(bool level);
void scalerDrv_2D_to_3D_Obj_set_frame_mode(UINT8 level);
void scalerDrv_2D_to_3D_Obj_set_lpf_setting(bool level,UINT8 c0,UINT8 c1,UINT8 c2);
void scalerDrv_2D_to_3D_Obj_set_frac_en(bool level);
void scalerDrv_2D_to_3D_Obj_set_rendering_mode_setting(UINT8 level);
void scalerDrv_2D_to_3D_Obj_set_depth_gain(UINT8 level);
void scalerDrv_2D_to_3D_set_Obj_cgain(UINT8 level);

void drv_2D_to_3D_Set_Auto_Adjust(bool autoMode);
bool drv_2D_to_3D_Get_Auto_Adjust(void);

int scalerDrv_2D_to_3D_Obj_get_en(void);	// 2D to 3D function on or off
bool scalerDrv_2D_to_3D_Obj_get_frame_mode(void);	// shift left or right
void scalerDrv_2D_to_3D_Obj_get_lpf_setting(bool *level,UINT8 *c0,UINT8 *c1,UINT8 *c2);	// low pass filter , enable & coefficients
bool scalerDrv_2D_to_3D_Obj_get_frac_en(void);	// using fraction hole filling
UINT8 scalerDrv_2D_to_3D_Obj_get_rendering_mode_setting(void);	// rendering mode
UINT8 scalerDrv_2D_to_3D_Obj_get_depth_gain(void);	// depth gain
UINT8 scalerDrv_2D_to_3D_get_Obj_cgain(void);	// weighting of chroma
UINT8 scalerDrv_2D_to_3D_get_Obj_cgain(void);

// add for Macarthur , Lydia
void drv_2D_to_3D_en_shiftmode(EN_SHIFTMODE_TYPE level);
void drv_2D_to_3D_Initialize(void);
void drv_2D_to_3D_set_frac_en(bool setting);
void drv_2D_to_3D_set_tilt_depth_en(bool setting);
unsigned int drv_2D_to_3D_get_tilt_depth_en(void);
void drv_2D_to_3D_set_object_depth_en(int selection);
void drv_2D_to_3D_set_depth_filter(bool setting,UINT8 c0,UINT8 c1,UINT8 c2);
void drv_2D_to_3D_set_hole_fill_type(UINT8 type);
void drv_2D_to_3D_set_output_filter_y(bool setting,UINT8 c0,UINT8 c1,UINT8 c2);
void drv_2D_to_3D_set_output_filter_c(bool setting,UINT8 c0,UINT8 c1,UINT8 c2);
void drv_2D_to_3D_shifter(int strength, int focal_pos);
void drv_2D_to_3D_LR_swap(bool lr_swap);
void drv_2D_to_3D_set_tilt_depth(bool enable,int step);	
void drv_2D_to_3D_H_shift(int focal_pos); //strength:static , focal: 0~32 ,for TV15_1_3D
void drv_2D_to_3D_H_shift_no_border(int focal_pos); //strength:static , focal: 0~32 

//#if defined(BUILD_TV035_1)
void drv_2D_to_3D_shifter_gain(unsigned char shift_gain);
void drv_2D_to_3D_shifter_offset(unsigned char shift_offset);
//#endif

#endif // #ifdef _CONVERSION_2D_3D_H

