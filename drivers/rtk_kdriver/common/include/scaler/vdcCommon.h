/***************************************************************************
                          vdcCommon.h  -  description
                             -------------------
    begin                : 2011/2/17
    copyright           : (C) 2011 by olivershih
    email                : olivershih@realtek.com
 ***************************************************************************/

#ifndef _COMMON_VDC_H__
#define _COMMON_VDC_H__

enum VDC_MODE {
	VDC_MODE_NTSC = 0x00,
	VDC_MODE_PALM = 0x01,
	VDC_MODE_NTSC50 = 0x02,
	VDC_MODE_PALN = 0x03,
	VDC_MODE_NTSC443 = 0x04,
	VDC_MODE_PAL60 = 0x05,
	VDC_MODE_PALI = 0x06,
	VDC_MODE_SECAM = 0x07,
	VDC_MODE_AUTO = 0x08,

	VDC_MODE_ERROR = 0x0d,
	VDC_MODE_CLEAN = 0x0e,
	VDC_MODE_NO_SIGNAL = 0x0f,
};


typedef enum _GET_VIDEO_MODE_METHOD {
	VDC_SET = 0,
	VDC_DETECT = 1,
} GET_VIDEO_MODE_METHOD;

#endif

