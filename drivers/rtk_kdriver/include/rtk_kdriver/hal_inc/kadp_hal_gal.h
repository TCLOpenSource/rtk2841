#ifndef _KADP_GAL_H_
#define _KADP_GAL_H_

/************************************************************************
 *  Include files
 ************************************************************************/
#include "kadp_hal_common.h"


/************************************************************************
 *  Definitions
 ************************************************************************/

#define MAX_PALETTE_SIZE 256
#define MAX_FRAMEBUFFER_NUMBER 3
#define CURSOR_TO_FRAMEBUFFER_INDEX 2 //0,1,2
#define MAX_SURFACE_IN_FRAMEBUFFER_NUMBER 4
#define MAX_SURFACE_INFO_NUMBER 10

#define MAX_DEST_WIDTH 4096
#define MIN_DEST_WIDTH 0
#define MAX_DEST_HEIGHT 4096
#define MIN_DEST_HEIGHT 0

#define HAL_GAL_IMGDEC_OK       KADP_OK
#define HAL_GAL_IMGDEC_BUSY     KADP_ERROR
#define HAL_GAL_IMGDEC_ERROR    KADP_ERROR	


//hal copy and rename

typedef enum
{
    KADP_HAL_GAL_PIXEL_FORMAT_ARGB = 0,  /**< 32 bit ARGB (4 byte, alpha 8\@24, red 8\@16, green 8\@8, blue 8\@0) */
    KADP_HAL_GAL_PIXEL_FORMAT_LUT8,      /**< 8 bit LUT (8 bit color and alpha lookup from palette) */
    KADP_HAL_GAL_PIXEL_FORMAT_ARGB1555,  /**< 16 bit ARGB (2 byte, alpha 1\@15, red 5\@10, green 5\@5, blue 5\@0) */
    KADP_HAL_GAL_PIXEL_FORMAT_RGB16,     /**< 16 bit RGB (2 byte, red 5\@11, green 6\@5, blue 5\@0) */
    KADP_HAL_GAL_PIXEL_FORMAT_ARGB4444,  /**< 16 bit ARGB (2 byte, alpha 4\@12, red 4\@8, green 4\@4, blue 4\@0) */
    KADP_HAL_GAL_PIXEL_FORMAT_A8,        /**< 8 bit A (1 byte, alpha 8\@0) */
    KADP_HAL_GAL_PIXEL_FORMAT_FBC,    
    KADP_GAL_PIXEL_FORMAT_MAX        /**< Maximum number of HAL_GAL_PIXEL_FORMAT_T */
} KADP_HAL_GAL_PIXEL_FORMAT_T;



typedef struct
{
    UINT32  palette[256]; /**< palette array */
    UINT32  length;       /**< size of palette (max: 256) */
} KADP_HAL_GAL_PALETTE_INFO_T;

typedef struct
{
    UINT32  palette[256]; /**< palette array */
    UINT32  length;       /**< size of palette (max: 256) */
    UINT32  physicalAddress;  /**< physical address of surface */
    UINT32  used;
} KADP_HAL_GAL_SUR_LINK_PALETTE_INFO_T;

typedef struct
{
    UINT32                  offset;             /**< bytes offset from the start of graphic memory */
    UINT32                  physicalAddress;  /**< physical address of surface */
    UINT16                  pitch;              /**< pitch: length of horizontal line */
    UINT16                  bpp;                /**< bits per pixel */
    UINT16                  width;              /**< width of surface */
    UINT16                  height;             /**< height of surface */
    KADP_HAL_GAL_PIXEL_FORMAT_T  pixelFormat;        /**< pixel format of surface */
    KADP_HAL_GAL_PALETTE_INFO_T  paletteInfo;        /**< palette information, this field is used when the surface's pixel format is based on indexed color. */
    UINT32                  property;           /**< reserved for future use */
    UINT32                  vendorData;         /**< reserved for chip vendor */
} KADP_HAL_GAL_SURFACE_INFO_T;


typedef struct
{
    UINT32  gfxMemTotalSize;
    UINT32  allocatedMemTotalSize;
    UINT32  freeMemTotalSize;
    UINT32  largestFreeMemSize;
} KADP_HAL_GAL_GRAPHIC_MEM_INFO_T;


typedef struct
{
    UINT16  x;  /**< x cordinate of its top-letf point */
    UINT16  y;  /**< y cordinate of its top-left point */
    UINT16  w;  /**< width of it */
    UINT16  h;  /**< height of it */
} KADP_HAL_GAL_RECT_T;


typedef struct
{
    UINT16  x1; /**< x cordinate of its top-letf point1 */
    UINT16  y1; /**< y cordinate of its top-left point1 */
    UINT16  x2; /**< x cordinate of its top-letf point2 */
    UINT16  y2; /**< y cordinate of its top-left point2 */
} KADP_HAL_GAL_LINE_T;


typedef struct
{
    SINT16 x;
    SINT16 y;
} KADP_HAL_GAL_POSITION_T;

typedef enum
{
    KADP_HAL_GAL_STEREOSCOPE_2D_TO_3D = 0,
    KADP_HAL_GAL_STEREOSCOPE_S3D,
    KADP_HAL_GAL_STEREOSCOPE_LAST
}KADP_HAL_GAL_STEREOSCOPE_TYPE_T;


typedef enum
{
    KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_NOFX       =   0x00000000, /**< None */
    KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_VIEWRECT   =   0x00000001, /**< viewRect region on the framebuffer */
    KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_DISPRECT   =   0x00000010, /**< dispRect region on the framebuffer */
    KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_STEREOSCOPE=   0x00000020, /**< Stereoscope on, off */
    KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_ALL        =   0x00000031, /**< dispRect region on the framebuffer */
} KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_FLAGS_T;


typedef struct
{
	KADP_HAL_GAL_RECT_T viewRect;    /**< viewRect region on the framebuffer */
	KADP_HAL_GAL_RECT_T dispRect;    /**< dispRect region on the framebuffer */
	unsigned char bStereoscope;
	KADP_HAL_GAL_STEREOSCOPE_TYPE_T stereoscopeType; /**< This enumeration describes flags for stereoscope mode setting */
} KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_EXTENDED_INFO_T;

typedef struct
{
    KADP_HAL_GAL_RECT_T  viewRect;   /**< viewRect region on the framebuffer */
    KADP_HAL_GAL_RECT_T  dispRect;   /**< dispRect region on the framebuffer */
} KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_INFO_T;

typedef struct
{
    UINT32  fbHWControllerIndex;
    BOOLEAN bVisibility;
} KADP_HAL_GAL_FRAMEBUFFER_VISIBILITY_INFO_T;

typedef enum
{
    KADP_HAL_GAL_CURSOR_HOTSPOT_LEFTTOP          =   0x00000000, /**< None */
    KADP_HAL_GAL_CURSOR_HOTSPOT_USERSETTING      =   0x00000001, /**< viewRect region on the framebuffer */
    KADP_HAL_GAL_CURSOR_HOTSPOT_LAST             =   0x00000010, /**< dispRect region on the framebuffer */
} KADP_HAL_GAL_CURSOR_HOTSPOT_TYPES_T;


typedef struct
{
    KADP_HAL_GAL_POSITION_T  position;
    UINT32              panelWidth;
    UINT32              panelHeight;
    UINT32              width;
    UINT32              height;
    KADP_HAL_GAL_CURSOR_HOTSPOT_TYPES_T  hotspot;
    KADP_HAL_GAL_POSITION_T  cursorGapPosition;
} KADP_HAL_GAL_CURSOR_PROPERTY_INFO_T;

typedef enum
{
    KADP_HAL_GAL_PIXEL_FORMAT_ARGB_EX                =   0x00000000, /**< 32 bit ARGB (4 byte, alpha 8\@24, red 8\@16, green 8\@8, blue 8\@0) */
    KADP_HAL_GAL_PIXEL_FORMAT_YUV_EX             =   0x00000001, /**< YUV */
    KADP_HAL_GAL_PIXEL_FORMAT_MAX_EX             =   0x00000010, /**< Maximum number of HAL_GAL_PIXEL_FORMAT_EX_T */
} KADP_HAL_GAL_PIXEL_FORMAT_EX_T;

typedef enum
{
    KADP_HAL_GAL_OSD_ROTATE_NONE = 0,
    KADP_HAL_GAL_OSD_ROTATE_90_DEGREE,
    KADP_HAL_GAL_OSD_ROTATE_270_DEGREE,
} KADP_HAL_GAL_OSD_ROTATE_TYPE_T;

typedef enum
{
    KADP_HAL_GAL_NONE_MIRROR         =   0x00000000, /**< Not uses mirror mode */
    KADP_HAL_GAL_HORIZONTAL_MIRROR   =   0x00000001, /**< Flip horizontally (y position is not changed */
    KADP_HAL_GAL_VERTICAL_MIRROR     =   0x00000010, /**< Flip vertically (x position is not changed */
    KADP_HAL_GAL_EPI_MIRROR          =   0x00000020, /**< determine whether use EPI panel or not  */
    KADP_HAL_GAL_ALL                 =   0x00000031  /**< All */
} KADP_HAL_GAL_MIRROR_FLAGS_T;


//hal copy and rename end


//rhal copy and rename

typedef struct
{
    UINT32  gfxMemTotalSize;
    unsigned int  allocatedMemTotalSize;
    unsigned int  freeMemTotalSize;
    unsigned int  largestFreeMemSize;
	unsigned int	 physicalAddrOfBase;
} KADP_RHAL_GAL_GRAPHIC_MEM_INFO_T;


typedef struct
{
	KADP_HAL_GAL_SURFACE_INFO_T   Surface;
	KADP_HAL_GAL_PALETTE_INFO_T   palette;
}KADP_RHAL_GAL_PALETTE_SURFACE_INFO_T;

typedef struct
{
	UINT16 width;
	UINT16 height;
	KADP_HAL_GAL_PIXEL_FORMAT_T pixelFormat;
	KADP_HAL_GAL_SURFACE_INFO_T surfaceInfo;
} KADP_RHAL_GAL_SURFACE_HANDLING_T;

typedef struct
{
	
   KADP_HAL_GAL_GRAPHIC_MEM_INFO_T memInfo;
   UINT32 physicalAddrOfBase;
    /**< whether the FBC (Frame Buffer Compression) is supported, or not (if supported, then this value is TRUE otherwise FALSE.) */
   UINT8 bFBCSupported;
} KADP_RHAL_GAL_GRAPHICS_MEM_T;


typedef struct
{
	KADP_HAL_GAL_SURFACE_INFO_T   Surface;
	UINT32 fbHWControllerIndex;
}KADP_RHAL_GAL_SURFACE_FRAMEBUFFER_INFO_T;


typedef struct
{
	KADP_HAL_GAL_SURFACE_INFO_T   Surface;
	UINT32 fbHWControllerIndex;
    KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_FLAGS_T flag;
    KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_EXTENDED_INFO_T extend_info;
}KADP_RHAL_GAL_SURFACE_FRAMEBUFFER_PROPERTY_FLAG_INFO_T;

typedef struct
{
	UINT32 fbHWControllerIndex;
    KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_FLAGS_T flag;
    KADP_HAL_GAL_FRAMEBUFFER_PROPERTY_INFO_T info;
}KADP_RHAL_GAL_FRAMEBUFFER_PROPERTY_FLAG_INFO_T;

typedef struct
{
	KADP_HAL_GAL_FRAMEBUFFER_VISIBILITY_INFO_T list[MAX_FRAMEBUFFER_NUMBER];
	UINT32 changedFbNum;
}KADP_RHAL_GAL_FRAMEBUFFER_VISIBILITY_LIST_INFO_T;


typedef struct
{
    UINT32 fbHWControllerIndex;
    BOOLEAN bVsync;
}KADP_RHAL_GAL_FRAMEBUFFER_VSYNC_INFO_T;

typedef struct
{
    UINT32 fbHWControllerIndex;
    KADP_HAL_GAL_CURSOR_PROPERTY_INFO_T CursorProperty;
}KADP_RHAL_GAL_FRAMEBUFFER_CURSORPROPERTY_INFO_T;

typedef struct
{
    UINT32 fbHWControllerIndex;
	unsigned char bStereoscope;
	KADP_HAL_GAL_STEREOSCOPE_TYPE_T stereoscopeType;
}KADP_RHAL_GAL_FRAMEBUFFER_STEREOSCOPE_T;


typedef struct
{
    UINT32 fbHWControllerIndex;
	KADP_HAL_GAL_PIXEL_FORMAT_EX_T pixelFormat;
}KADP_RHAL_GAL_FRAMEBUFFER_PIXELFORMAT_T;


typedef struct
{
	KADP_HAL_GAL_SURFACE_INFO_T pSurfaceList[MAX_SURFACE_INFO_NUMBER];
	UINT32 NumOfSurface;
}KADP_RHAL_GAL_FRAMEBUFFER_LIST_T;

typedef struct
{
    UINT32 fbHWControllerIndex;
	BOOLEAN bVisibility;
}KADP_RHAL_GAL_FRAMEBUFFER_VISIBILITY_T;

typedef struct {
	KADP_HAL_GAL_PIXEL_FORMAT_T pixelFormat;
    UINT16  maxWidth;           /**< window's max width */
    UINT16  maxHeight;          /**< window's max height */
    unsigned char bStereoscope;
    KADP_HAL_GAL_STEREOSCOPE_TYPE_T stereoscopeType; /**< This enumeration describes flags for stereoscope mode setting */
    BOOLEAN bVisibility;
    BOOLEAN bVsync;
	UINT32 palette_used_index;/* 0 --> no use 1--> used index table 1, ...*/
	UINT32 used_mouse;
    KADP_HAL_GAL_RECT_T  viewRect;   /**< viewRect region on the framebuffer */
    KADP_HAL_GAL_RECT_T  dispRect;   /**< dispRect region on the framebuffer */
	KADP_HAL_GAL_SURFACE_INFO_T pSurfaceList[MAX_SURFACE_IN_FRAMEBUFFER_NUMBER];
} KADP_RHAL_GAL_GLOBE_FRAMEBUFFER_INFO_T;

typedef struct {
	KADP_HAL_GAL_CURSOR_PROPERTY_INFO_T    cursor_info;
	KADP_HAL_GAL_OSD_ROTATE_TYPE_T         rorate_type;
	KADP_RHAL_GAL_GLOBE_FRAMEBUFFER_INFO_T gFrameBuffer_data[MAX_FRAMEBUFFER_NUMBER];
}KADP_RHAL_GAL_GLOBE_GAL_INFO_T;

//rhal copy and rename end























#endif  /* _KADP_GAL_H_ */



