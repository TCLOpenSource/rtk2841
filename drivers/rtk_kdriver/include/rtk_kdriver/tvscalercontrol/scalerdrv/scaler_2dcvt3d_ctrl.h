#ifndef _SCALER_2DCVT3D_CTRL_
#define _SCALER_2DCVT3D_CTRL_
#include <scalercommon/scalerCommon.h>



/*
*********************************************************************************************************
*							enum & Data structure define
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*							Define & Macro
*********************************************************************************************************
*/

#ifdef TV15_1_3D     //  strength:  , focal: 0~32(deep)
// 2D cvt 3D depth change range control
#define DISP_2DCVT3D_ZOOM_OUT_MAX		30
#define DISP_2DCVT3D_ZOOM_IN_MAX			24

#define DISP_2DCVT3D_3D_DEPTH_MAX_VALUE	  32
#define DISP_2DCVT3D_3D_STRENGTH_MAX_VALUE	32

#define DISP_2DCVT3D_3D_DEPTH_DEFAULT_VALUE	 16
#define DISP_2DCVT3D_3D_STRENGTH_DEFAULT_VALUE   16

#define DISP_2DCVT3D_3D_OSD_DEP_OFFSET	1
#define DISP_2DCVT3D_3D_OSD_DEP_DEFAULT	7

// 3D depth change range control
#define DISP_3D_ZOOM_OUT_MAX			15
#define DISP_3D_ZOOM_IN_MAX			12

// 2d cvt 3d deep effect
#define HORIZONTAL_SHIFT				1
#define HORIZONTAL_SHIFT_NO_BORDER	0
#define HORIZONTAL_SHIFT_Center		12

#else
// 2D cvt 3D depth change range control
#define DISP_2DCVT3D_ZOOM_OUT_MAX		30
#define DISP_2DCVT3D_ZOOM_IN_MAX			24
#define DISP_2DCVT3D_3D_DEPTH_MAX_VALUE	  15 //6
#define DISP_2DCVT3D_3D_STRENGTH_MAX_VALUE	15//10

#define DISP_2DCVT3D_3D_DEPTH_DEFAULT_VALUE	 7 //0
#define DISP_2DCVT3D_3D_STRENGTH_DEFAULT_VALUE   7 //	4
#define DISP_2DCVT3D_3D_OSD_DEP_OFFSET	1
#define DISP_2DCVT3D_3D_OSD_DEP_DEFAULT	7

// 3D depth change range control
#define DISP_3D_ZOOM_OUT_MAX			15
#define DISP_3D_ZOOM_IN_MAX			12


#define HORIZONTAL_SHIFT				0
#define HORIZONTAL_SHIFT_NO_BORDER	1
#endif







/*
*********************************************************************************************************
*							Function Prototype
*********************************************************************************************************
*/

unsigned char scaler_2Dcvt3D_get_userStatus(void);
void scaler_2Dcvt3D_set_tilt_enable(unsigned char enableFlag);
unsigned char scaler_2Dcvt3D_get_tilt_enable(void);
void scaler_2Dcvt3D_set_tilt_depth(unsigned char enableFlag);
void scaler_2Dcvt3D_set_userEnableStatus(unsigned char userEnableFlag);
void scaler_2Dcvt3D_set_shifter(unsigned int Strength,unsigned int Depth);
void scaler_2Dcvt3D_set_hactStaShift(StructDisplayInfo* info, char shiftCount);
unsigned char scaler_2Dcvt3D_get_shiftDirection(void);
void scaler_2Dcvt3D_set_shiftDirection(bool shiftWay);
int scaler_2Dcvt3D_init(void);
void scaler_2Dcvt3D_LR_swap(bool lr_swap);
#endif
