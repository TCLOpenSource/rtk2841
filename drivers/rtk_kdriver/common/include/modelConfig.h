#ifndef __MODELCONFIG_H
#define __MODELCONFIG_H

#include "rtd_types.h"

#ifndef BUF_WIDTH	///< width of pixel buf output
#define BUF_WIDTH		1920
#endif

#ifndef BUF_HEIGHT
#define BUF_HEIGHT		1200
#endif

/**
 * Pixel Buffer ordering
 */
enum {
	PIXEL_Y,
	PIXEL_CB,
	PIXEL_CR,

	PIXEL_COMPONENTS,			///< Pixel component to compose a pixel value

	_Y = PIXEL_Y,
	_CR = PIXEL_CR,
	_CB = PIXEL_CB,

	_PIXEL_BITS = 10,

	PIXEL_MAX = ((1<<_PIXEL_BITS)-1),
	PIXEL_Y_MAX = PIXEL_MAX,
	PIXEL_CR_MAX = PIXEL_MAX,
	PIXEL_CB_MAX = PIXEL_MAX,

};

/**
 * Video window descriptor
 */
typedef struct {
	INT16	hsta;	///< Horizontal Start address in total timing coordinate
	INT16	vsta;	///< Vertiical Start address in total timing coordinate
	UINT16	width;	///< Width in pixel
	UINT16	len;		///< Lines
}VIDEO_WIN;

#endif //__MODELCONFIG_H

