#ifndef _K_GAL_H_
#define _K_GAL_H_
#include <stdbool.h>

#define SE_OLD 1 /*origin SE*/
#define SE_SE20 0 /*SE20 with stch bug*/
#define SE_SE20_EXT 0  /*compleleted SE20 and refine registers*/

#if SE_SE20 || SE_OLD
#define LUT8_WIDTH 1920
#define LUT8_HEIGHT 1080
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef UINT8
typedef	unsigned char           __UINT8;
#define UINT8 __UINT8
#endif

#ifndef UINT16
typedef	unsigned short	__UINT16;
#define UINT16 __UINT16
#endif

#ifndef SINT16
typedef	signed short	__SINT16;
#define SINT16 __SINT16
#endif

#ifndef UINT32
typedef	unsigned int	__UINT32;
#define UINT32 __UINT32
#endif

#ifndef SINT32
typedef signed int	__SINT32;
#define SINT32 __SINT32
#endif

#ifndef BOOLEAN
typedef	unsigned int	__BOOLEAN;
#define BOOLEAN __BOOLEAN
#endif

typedef enum
{
	KGAL_PIXEL_FORMAT_ARGB = 0,
	KGAL_PIXEL_FORMAT_LUT8,
	KGAL_PIXEL_FORMAT_ARGB1555,
	KGAL_PIXEL_FORMAT_RGB16,
	KGAL_PIXEL_FORMAT_ARGB4444,
	KGAL_PIXEL_FORMAT_A8,
	KGAL_PIXEL_FORMAT_RGB888,
	KGAL_PIXEL_FORMAT_FBC,
	KGAL_PIXEL_FORMAT_NV12,
	KGAL_PIXEL_FORMAT_YUY2,
	KGAL_PIXEL_FORMAT_NV16,
	KGAL_PIXEL_FORMAT_MAX
} KGAL_PIXEL_FORMAT_T;

typedef enum
{
	KGAL_BLEND_UNKNOWN           = 0,
	KGAL_BLEND_ZERO              = 1,
	KGAL_BLEND_ONE               = 2,
	KGAL_BLEND_SRCCOLOR          = 3,
	KGAL_BLEND_INVSRCCOLOR       = 4,
	KGAL_BLEND_SRCALPHA          = 5,
	KGAL_BLEND_INVSRCALPHA       = 6,
	KGAL_BLEND_DESTALPHA         = 7,
	KGAL_BLEND_INVDESTALPHA      = 8,
	KGAL_BLEND_DESTCOLOR         = 9,
	KGAL_BLEND_INVDESTCOLOR      = 10,
	KGAL_BLEND_SRCALPHASAT       = 11,
	KGAL_BLEND_CONSTALPHA	     = 12,
	KGAL_BLEND_MAX,
	KGAL_BLEND_MAX_MASK          = 0xffff,
} KGAL_BLEND_FUNCTION_T;


typedef struct
{
	KGAL_BLEND_FUNCTION_T    srcBlend;
	KGAL_BLEND_FUNCTION_T    dstBlend;
	UINT32                  dstColorkey;
} KGAL_DRAW_SETTINGS_T;


typedef struct
{
	UINT32  palette[128];
	UINT32  length;
	UINT32  startpale;
} KGAL_PALETTE_INFO_T;


typedef struct
{
	UINT32                  physicalAddress;
	UINT16                  pitch;
	UINT16                  bpp;
	UINT16                  width;
	UINT16                  height;
	KGAL_PIXEL_FORMAT_T  pixelFormat;
} KGAL_SURFACE_INFO_T;

typedef struct
{
	UINT16  x;
	UINT16  y;
	UINT16  w;
	UINT16  h;
} KGAL_RECT_T;


typedef struct
{
	UINT16  x1;
	UINT16  y1;
	UINT16  x2;
	UINT16  y2;
} KGAL_LINE_T;

typedef enum
{
	KGAL_OSD_ROTATE_NONE = 0,
	KGAL_OSD_ROTATE_90_DEGREE,
	KGAL_OSD_ROTATE_270_DEGREE,
} KGAL_OSD_ROTATE_TYPE_T;

typedef enum
{
	KGAL_NONE_MIRROR         =   0x00000000,
	KGAL_HORIZONTAL_MIRROR   =   0x00000001,
	KGAL_VERTICAL_MIRROR     =   0x00000010,
	KGAL_EPI_MIRROR          =   0x00000020,
	KGAL_ALL                 =   0x00000031
} KGAL_MIRROR_FLAGS_T;

typedef enum
{
	KGAL_DRAW_NOFX                   = 0x00000000,
	KGAL_DRAW_BLEND                  = 0x00000001,
	KGAL_DRAW_DST_COLORKEY           = 0x00000002,
	KGAL_DRAW_SRC_PREMULTIPLY        = 0x00000004,
	KGAL_DRAW_DST_PREMULTIPLY        = 0x00000008,
	KGAL_DRAW_DEMULTIPLY             = 0x00000010,
	KGAL_DRAW_XOR                    = 0x00000020,
	KGAL_DRAW_MAX
} KGAL_DRAW_FLAGS_T;


typedef enum
{
	KGAL_BLIT_NOFX                   = 0x00000000,
	KGAL_BLIT_BLEND_ALPHACHANNEL     = 0x00000001,
	KGAL_BLIT_BLEND_COLORALPHA       = 0x00000002,
	KGAL_BLIT_COLORIZE               = 0x00000004,
	KGAL_BLIT_SRC_COLORKEY           = 0x00000008,
	KGAL_BLIT_DST_COLORKEY           = 0x00000010,
	KGAL_BLIT_SRC_PREMULTIPLY        = 0x00000020,
	KGAL_BLIT_DST_PREMULTIPLY        = 0x00000040,
	KGAL_BLIT_DEMULTIPLY             = 0x00000080,
	KGAL_BLIT_DEINTERLACE            = 0x00000100,
	KGAL_BLIT_SRC_PREMULTCOLOR       = 0x00000200,
	KGAL_BLIT_XOR                    = 0x00000400,
	KGAL_BLIT_INDEX_TRANSLATION      = 0x00000800,
	KGAL_BLIT_ROTATE90               = 0x00001000,
	KGAL_BLIT_ROTATE180              = 0x00002000,
	KGAL_BLIT_ROTATE270              = 0x00004000,
	KGAL_BLIT_COLORKEY_PROTECT       = 0x00010000,
	KGAL_BLIT_SRC_MASK_ALPHA         = 0x00100000,
	KGAL_BLIT_SRC_MASK_COLOR         = 0x00200000,
	KGAL_BLIT_VERTICAL_MIRROR        = 0x00400000,
	KGAL_BLIT_HORIZONTAL_MIRROR      = 0x00800000,
	KGAL_BLIT_BLEND_ALPHACHANNEL_BCM   = 0x01000000,
	KGAL_BLIT_BLEND_ALPHACHANNEL_COLORALPHA_BCM  = 0x02000000,
	KGAL_BLIT_BLEND_ALPHACHANNEL_COLORIZE_BCM    = 0x04000000,
	KGAL_BLIT_OUTPUT_ALPHA_CONST     = 0x80000000,
	KGAL_BLIT_MAX,
	KGAL_BLIT_MAX_MASK               = 0xffffffff,
} KGAL_BLIT_FLAGS_T;

typedef enum {
	KGAL_SURFACE_MASK_NONE      = 0x00000000,
	KGAL_SURFACE_MASK_STENCIL   = 0x00000001,
	KGAL_SURFACE_MASK_ALL       = 0x00000001,
} KGAL_SURFACE_MASK_FLAGS_T;


typedef struct
{
	UINT32                      offset;
	UINT16                      x;
	UINT16                      y;
	KGAL_SURFACE_MASK_FLAGS_T    flags;
} KGAL_SOURCE_MASK_T;

typedef struct
{
	KGAL_BLEND_FUNCTION_T    srcBlend;
	KGAL_BLEND_FUNCTION_T    dstBlend;
	UINT32                  alpha;
	UINT32                  color;
	UINT32                  srcColorkey;
	UINT32                  dstColorkey;
	KGAL_SOURCE_MASK_T       srcMask;
} KGAL_BLIT_SETTINGS_T;


typedef struct
{
	KGAL_SURFACE_INFO_T   Surface;
	KGAL_PALETTE_INFO_T   palette;
}KGAL_PALETTE_SURFACE_INFO_T;

bool KGAL_GetSurfacePalette(KGAL_PALETTE_SURFACE_INFO_T *local_palette);
bool KGAL_SetSurfacePalette(KGAL_PALETTE_SURFACE_INFO_T *local_palette);
bool KGAL_Blit(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface, UINT16 dx, UINT16 dy, KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings);
bool KGAL_StretchBlit(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pDstRect, KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings);
bool KGAL_FillRectangle(KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pDstRect, UINT32 color, KGAL_DRAW_FLAGS_T* pDrawFlags, KGAL_DRAW_SETTINGS_T* pDrawSettings);
bool KGAL_DrawRectangle(KGAL_SURFACE_INFO_T* pDstSurface, KGAL_RECT_T* pDstRect, UINT32 color, KGAL_DRAW_FLAGS_T* pDrawFlags, KGAL_DRAW_SETTINGS_T* pDrawSettings);
bool KGAL_DrawLine(KGAL_SURFACE_INFO_T* pDSurface, KGAL_LINE_T* pDstLine, UINT32 color, KGAL_DRAW_FLAGS_T* pDrawFlags, KGAL_DRAW_SETTINGS_T* pDrawSettings);
bool KGAL_FormatConv(KGAL_SURFACE_INFO_T* pSrcSurface, KGAL_RECT_T* pSrcRect, KGAL_SURFACE_INFO_T* pDstSurface, UINT16 dx, UINT16 dy, KGAL_BLIT_FLAGS_T* pBlitFlags, KGAL_BLIT_SETTINGS_T* pBlitSettings);

#endif
