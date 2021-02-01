
#include "kadp_hal_gal.h"


int kHAL_GAL_CreateSurface(UINT16 width, UINT16 height, KADP_HAL_GAL_PIXEL_FORMAT_T pixelFormat,
KADP_HAL_GAL_SURFACE_INFO_T *pSurfaceInfo);

int kHAL_GAL_DestroySurface(KADP_HAL_GAL_SURFACE_INFO_T *pSurfaceInfo);

int kHAL_GAL_GetGraphicMemInfo(KDRV_GAL_GRAPHICS_MEM_T *pRTGraphicMemInfo);



int kRtHAL_GAL_InitSurfaceAll(void);


int kRtHAL_GAL_DestroySurfaceAll(void);
