//#include <linux/kernel.h>   /* DBG_PRINT()    */
#include <linux/string.h>
#include <linux/mm.h>
#include <linux/pagemap.h>
#include <linux/pageremap.h>
#include <linux/dma-mapping.h>
#include <linux/fs.h>           /* everything... */
#include <linux/errno.h>        /* error codes */
#include <linux/err.h>

#include <linux/sched.h>
#include <mach/platform.h>

static DEFINE_MUTEX(gSURFACE_MGR_LOCK);
static DEFINE_MUTEX(gSURFACE_ALLOC_LOCK);


#include <gal/rtk_kadp_gdma_hal_gal_driver.h>
#include <gal/rtk_kadp_hal_gal_surface.h>

#define FBC_ON      1
#define FBC_OFF     0
static int  fbcOnOff = FBC_OFF;

#undef FBC_1920x1092_GAL_PATCH	   //patch fbc enable to 1920x1092


#if 1
#define GAL_USE_RESERVE_MEM 1

#else
#define GAL_USE_DVR_MEM 1

#endif//

#ifdef GAL_USE_RESERVE_MEM
//#include "drivers/staging/android/ion/ion.h"
#include "ion.h"

//add by fox for gfx std
#define GFX_SPECIAL_SIZE (256*256)
#define GFX_NUM_MAX (200)
#define GFX_CURSOR_SIZE (4*1024*1024)
typedef struct {
	unsigned int width;
	unsigned int height;
	unsigned int phyAddr;
	unsigned int virtAddr;
	unsigned int to_phyAddr;
	unsigned int to_virtAddr;
	unsigned int size;
} RtgfxRecord;

extern struct ion_device *rtk_ion_device;

static struct ion_client* gHAL_ION_CLIENT=NULL;

extern int GAL_MEM_ADDR_START;
extern  int GAL_MEM_SIZE;
RtgfxRecord gfx_data[GFX_NUM_MAX];
unsigned int total_size=0;
unsigned int total_index=0;

#endif//

unsigned int GAL_ALLOC_SIZE = 0;

#if 0/* no used */
static unsigned int GAL_SURFACE_COUNT = 0;
#endif


typedef enum {
	RT_HAL_GAL_ERR_OK = KADP_OK,
	RT_HAL_GAL_ERR_BAD = (-1000),
	RT_HAL_GAL_ERR_MEM,
	RT_HAL_GAL_ERR_INDEX,
	RT_HAL_GAL_ERR_MATCH, //surface not match real
} RT_HAL_GAL_ERROR;

#if 0
#define RT_HAL_GAL_ERR (-1000)
#define RT_HAL_GAL_ERR_MEM (-1001)
#define RT_HAL_GAL_ERR_INDEX (-1002)
#endif//0



typedef struct {
	unsigned int width;     //for double check
	unsigned int height;
	unsigned int index;
	unsigned int phyAddr;
	unsigned int virAddr;
	void*           addr_handle;
	unsigned int size;

	unsigned char valid;
	unsigned char padding[3];//red-zone ?

//int*  privateData[0];
	KADP_HAL_GAL_SURFACE_INFO_T privateData;
} RtSurface;



#define gSURFACE_MAX  (320)	// 20150522 LG max index usage is 143


static unsigned int gSURFACE_INDEX = 1;

static RtSurface gSURFACE_LIST[gSURFACE_MAX];


static RtSurface* xRtSurfaceMgr_AllocSurfaceIndex(void);
static void xRtSurfaceMgr_FreeSurfaceIndex(RtSurface*);

//static RtSurface* xRtSurfaceMgr_GetSurfaceIndex(unsigned int surface_index);
static int xRtSurfaceMgr_FreeVendorSurface_noLock(KADP_HAL_GAL_SURFACE_INFO_T *pSurfaceInfo);


static void* xAllocMem(int size, void **handle);
static int xFreeSurfaceMem(RtSurface* rt_suf);


// FIXME: follow umd FBDC defintion
//#define KERNEL_FIX_HW_BRN_44474
//#define KERNEL_RGX_FEATURE_FB_CDC_32x2
#define KERNEL_RGX_FEATURE_FBCDC_MEMALLOC  		1
#define KERNEL_RGX_FEATURE_FBCDC_ALGORITHM 		2
#define FBC_THUMBNAIL_REDUCE_RATE 		5

typedef enum _KERNEL_FB_COMPRESSION
{
	KERNEL_FB_COMPRESSION_NONE,
	KERNEL_FB_COMPRESSION_DIRECT_8x8,
	KERNEL_FB_COMPRESSION_DIRECT_16x4,
	KERNEL_FB_COMPRESSION_DIRECT_32x2,
	KERNEL_FB_COMPRESSION_INDIRECT_8x8,
	KERNEL_FB_COMPRESSION_INDIRECT_16x4,
	KERNEL_FB_COMPRESSION_INDIRECT_4TILE_8x8,
	KERNEL_FB_COMPRESSION_INDIRECT_4TILE_16x4
} KERNEL_FB_COMPRESSION;

typedef enum _KERNEL_IMG_MEMLAYOUT_
{
	KERNEL_IMG_MEMLAYOUT_STRIDED,			/**< Resource is strided, one row at a time */
    	KERNEL_IMG_MEMLAYOUT_TWIDDLED,			/**< Resource is 2D twiddled, classic style */
    	KERNEL_IMG_MEMLAYOUT_3DTWIDDLED,       	/**< Resource is 3D twiddled, classic style */
	KERNEL_IMG_MEMLAYOUT_TILED,				/**< Resource is tiled, tiling config specified elsewhere. */
	KERNEL_IMG_MEMLAYOUT_PAGETILED,			/**< Resource is pagetiled */
} KERNEL_IMG_MEMLAYOUT;

#define __GFX_ALIGN(val, align) (((val) + ((align) - 1)) & ~((align) - 1))
#define __4KPAGE  0x1000

unsigned int KERNEL_GetFBCHeaderSize(unsigned int ui32NumTiles, unsigned int ui32Algo)
{
	unsigned int	ui32HeaderSize;

	if (ui32Algo == 1)
	{
		/* 32-bits header (V1) */
		ui32HeaderSize = (ui32NumTiles + 31) / 32;
	}
	else if (ui32Algo == 2)
	{
		/* 8-bits header (V2) */
		ui32HeaderSize = (ui32NumTiles + 127) / 128;
	}
	else if (ui32Algo == 3)
	{
		/* 4-bits header (V3) */
		ui32HeaderSize = (ui32NumTiles + 255) / 256;
	}
	else
	{
		return 0;
	}

	return ui32HeaderSize * 128;
}

unsigned char KERNEL_GetFBCSurfaceHeaderDataSize2D( KERNEL_FB_COMPRESSION eFBMode,
																  unsigned int				ui32NumTiles,
																  unsigned int*			pui32HeaderSize,
																  unsigned int*			pui32DataSize)
{
	unsigned int		ui32HeaderSize;
	unsigned int		ui32DataSize;

#if defined(KERNEL_FIX_HW_BRN_44474)
	ui32HeaderSize = KERNEL_GetFBCHeaderSize(ui32NumTiles, 1);
#else
 	ui32HeaderSize = KERNEL_GetFBCHeaderSize(ui32NumTiles, KERNEL_RGX_FEATURE_FBCDC_ALGORITHM);  // fixme: might to add in...
 #endif

	*pui32HeaderSize = ui32HeaderSize;

	if (ui32HeaderSize == 0)
	{
		*pui32DataSize = 0;
		return 0;
	}


	switch (eFBMode)
	{
		case KERNEL_FB_COMPRESSION_DIRECT_8x8:
		{
			ui32DataSize = ui32NumTiles * 2;
			break;
		}
		case KERNEL_FB_COMPRESSION_DIRECT_16x4:
		{
			ui32DataSize = ui32NumTiles * 2;
			break;
		}
#if defined(KERNEL_RGX_FEATURE_FB_CDC_32x2)
		case KERNEL_FB_COMPRESSION_DIRECT_32x2:
		{
			ui32DataSize = ui32NumTiles * 2;
			break;
		}
#endif
		default:
		{
			*pui32HeaderSize = 0;
			*pui32DataSize = 0;
			return 0;
		}
	}

	/*
	 * Units of above calculations are 128bytes.
	 */
	*pui32DataSize = ui32DataSize * 128;

	return 1;
}

void KERNEL_GetFBCSurfacePhysicalDim2D(KERNEL_FB_COMPRESSION		eFBMode,
										 unsigned int					ui32Width,
										 unsigned int					ui32Height,
										 unsigned int					ui32BitDepth,
										 KERNEL_IMG_MEMLAYOUT		eMemLayout,
										 unsigned int*					pui32PhysicalWidth,
										 unsigned int*					pui32PhysicalHeight)
{
	/*
	 * For FBC, round up to FBC tile size.
	 */
	switch (eFBMode)
	{
		case KERNEL_FB_COMPRESSION_DIRECT_8x8:
		case KERNEL_FB_COMPRESSION_INDIRECT_8x8:
		case KERNEL_FB_COMPRESSION_INDIRECT_4TILE_8x8:
		{
			if(eMemLayout == KERNEL_IMG_MEMLAYOUT_TWIDDLED)
			{
				switch(ui32BitDepth)
				{
				case 8:		/* 16x16 */
					ui32Width = (ui32Width + 15) & ~15;
					ui32Height = (ui32Height + 15) & ~15;
					break;
				case 16: 	/* 8x16*/
					ui32Width = (ui32Width + 7) & ~7;
					ui32Height = (ui32Height + 15) & ~15;
					break;
				default: 	/* 8x8 */
					ui32Width = (ui32Width + 7) & ~7;
					ui32Height = (ui32Height + 7) & ~7;
					break;
				}
			}
			else if(eMemLayout == KERNEL_IMG_MEMLAYOUT_STRIDED)
			{
				switch(ui32BitDepth)
				{
				case 8:		/* 32x8 */
					ui32Width = (ui32Width + 31) & ~31;
					break;
				case 16:	/* 16x8 */
					ui32Width = (ui32Width + 15) & ~15;
					break;
				default:	/* 8x8 */
					ui32Width = (ui32Width + 7) & ~7;
					break;
				}

				ui32Height = (ui32Height + 7) & ~7;
			}

			break;
		}
		case KERNEL_FB_COMPRESSION_DIRECT_16x4:
		case KERNEL_FB_COMPRESSION_INDIRECT_16x4:
		case KERNEL_FB_COMPRESSION_INDIRECT_4TILE_16x4:
		{
			/* Only stride is required */
			switch(ui32BitDepth)
			{
			case 8:		/* 64x4 */
				ui32Width = (ui32Width + 63) & ~63;
				break;
			case 16:	/* 32x4 */
				ui32Width = (ui32Width + 31) & ~31;
				break;
			default:	/* 16x4 */
				ui32Width = (ui32Width + 15) & ~15;
				break;
			}

			ui32Height = (ui32Height + 3) & ~3;
			break;
		}
#if defined(KERNEL_RGX_FEATURE_FB_CDC_32x2)
		case KERNEL_FB_COMPRESSION_DIRECT_32x2:
		{
			/* only stride is required and bpp>=24, 32x2 */
			ui32Width = (ui32Width + 31) & ~31;
			ui32Height = (ui32Height + 1) & ~1;
			break;
		}
#endif
		default:
		case KERNEL_FB_COMPRESSION_NONE:
		{
			break;
		}
	}

	*pui32PhysicalWidth = ui32Width;
	*pui32PhysicalHeight = ui32Height;
}


unsigned char KERNEL_GetFBCSurfaceSize2D( KERNEL_FB_COMPRESSION 	eFBMode,
									  unsigned int				ui32PhysicalWidth,
									  unsigned int				ui32PhysicalHeight,
									  unsigned int				ui32BitDepth,
									  unsigned int*			pui32TotalSize,
									  unsigned int*			pui32NumTiles,
									  unsigned int*			pui32NextMapOffset)
{
	unsigned int		ui32NumTiles;
	unsigned int		ui32HeaderSize;
	unsigned int		ui32DataSize;
	unsigned int		ui32TileMultiplier;

	/*
	 * Set multiplier (X4 so we can do 1/4 multiply)
	 */
	if (ui32BitDepth <= 8)
	{
		ui32TileMultiplier = 1;
	}
	else if (ui32BitDepth <= 16)
	{
		ui32TileMultiplier = 2;
	}
	else if (ui32BitDepth <= 32)
	{
		ui32TileMultiplier = 1*4;
	}
	else if (ui32BitDepth <= 64)
	{
		ui32TileMultiplier = 2*4;
	}
	else
	{
		ui32TileMultiplier = 4*4;
	}

	switch (eFBMode)
	{
		case  KERNEL_FB_COMPRESSION_DIRECT_8x8:
		{
			ui32NumTiles = ui32PhysicalWidth / 8;
			ui32NumTiles *= ui32PhysicalHeight / 8;
			ui32NumTiles *= ui32TileMultiplier;
			ui32NumTiles /= 4;
			if (ui32NumTiles == 0)
				ui32NumTiles = 1;
			break;
		}
		case  KERNEL_FB_COMPRESSION_DIRECT_16x4:
		{
			ui32NumTiles = ui32PhysicalWidth / 16;
			ui32NumTiles *= ui32PhysicalHeight / 4;
			ui32NumTiles *= ui32TileMultiplier;
			ui32NumTiles /= 4;
			if (ui32NumTiles == 0)
				ui32NumTiles = 1;
			break;
		}
#if defined(KERNEL_RGX_FEATURE_FB_CDC_32x2)
		case  KERNEL_FB_COMPRESSION_DIRECT_32x2:
		{
			ui32NumTiles = ui32PhysicalWidth / 32;
			ui32NumTiles *= ui32PhysicalHeight / 2;
			ui32NumTiles *= ui32TileMultiplier;
			ui32NumTiles /= 2;
			if (ui32NumTiles == 0)
				ui32NumTiles = 1;
			break;
		}
#endif
		case  KERNEL_FB_COMPRESSION_INDIRECT_8x8:
		{
			ui32NumTiles = ui32PhysicalWidth / 8;
			ui32NumTiles *= ui32PhysicalHeight / 8;
			ui32NumTiles *= ui32TileMultiplier;
			ui32NumTiles /= 4;
			if (ui32NumTiles == 0)
				ui32NumTiles = 1;
			break;
		}
		case  KERNEL_FB_COMPRESSION_INDIRECT_16x4:
		{
			ui32NumTiles = ui32PhysicalWidth / 16;
			ui32NumTiles *= ui32PhysicalHeight / 4;
			ui32NumTiles *= ui32TileMultiplier;
			ui32NumTiles /= 4;
			if (ui32NumTiles == 0)
				ui32NumTiles = 1;
			break;
		}
		case  KERNEL_FB_COMPRESSION_INDIRECT_4TILE_8x8:
		{
			ui32NumTiles = ui32PhysicalWidth / 16;
			ui32NumTiles *= ui32PhysicalHeight / 4;
			ui32NumTiles *= ui32TileMultiplier;
			ui32NumTiles /= 4;
			if (ui32NumTiles == 0)
				ui32NumTiles = 1;
			break;
		}
		case  KERNEL_FB_COMPRESSION_INDIRECT_4TILE_16x4:
		{
			ui32NumTiles = ui32PhysicalWidth / 16;
			ui32NumTiles *= ui32PhysicalHeight / 4;
			ui32NumTiles *= ui32TileMultiplier;
			ui32NumTiles /= 4;
			if (ui32NumTiles == 0)
				ui32NumTiles = 1;
			break;
		}
		default:
		{
			*pui32TotalSize = 0;
			*pui32NumTiles = 0;
			return 0;
		}
	}

	KERNEL_GetFBCSurfaceHeaderDataSize2D(eFBMode, ui32NumTiles, &ui32HeaderSize, &ui32DataSize);

	*pui32TotalSize = ui32HeaderSize + ui32DataSize;
	*pui32NumTiles = ui32NumTiles;

	/*
	 * Map offset is aligned to 128 bytes.
	 * Offset to next surface is defined by the header size of the MEMALLOC,
	 * not the ALGORITHM. This is because although the data/header sizes inside
	 * the allocation are defined by ALGORITHM, the addressing per surface of a texture
	 * is defined using the MEMALLOC sizes - i.e. there is a gap after the header/data
	 * equal to the difference between the two header sizes.
	 */
#if (KERNEL_RGX_FEATURE_FBCDC_MEMALLOC == KERNEL_RGX_FEATURE_FBCDC_ALGORITHM)
	*pui32NextMapOffset = (*pui32TotalSize + 127) & ~127;
#else
	ui32HeaderSize = KERNEL_GetFBCHeaderSize(ui32NumTiles, KERNEL_RGX_FEATURE_FBCDC_MEMALLOC);
	*pui32NextMapOffset = (ui32HeaderSize + ui32DataSize + 127) & ~127;
#endif

	return 1;
}


void* xAllocMem(int size, void **handle)
{
	void* ret_addr = NULL;

	mutex_lock(&gSURFACE_ALLOC_LOCK);

#ifdef GAL_USE_DVR_MEM
	ret_addr = dvr_malloc_specific(size , GFP_DCU1 );


#elif defined(GAL_USE_RESERVE_MEM)
	{
#if 1
		struct ion_handle *tmp_handle;
		unsigned int flags;
		int ret;
		ion_phys_addr_t phy_addr;
		size_t phy_size;


		*handle = NULL;

// flags = ION_FLAG_CACHED | ION_FLAG_CACHED_NEEDS_SYNC; // ??
		flags = ION_FLAG_CACHED;

//align 0 seems ok
//tmp_handle = ion_alloc(gHAL_ION_CLIENT, size, 4096,  ION_HEAP_TYPE_CARVEOUT, flags);
		tmp_handle = ion_alloc(gHAL_ION_CLIENT, size, 0,  ION_HEAP_CARVEOUT_MASK, flags);



		if ( IS_ERR(tmp_handle) ) {
			pr_debug(KERN_WARNING " GAL %s fail 0x%x(0x%x)  size:%d\n", __FUNCTION__,  (unsigned int)PTR_ERR(tmp_handle),  (unsigned int)tmp_handle, size);
			goto ERR_RET;
		}

		ret = ion_phys(gHAL_ION_CLIENT, tmp_handle, &phy_addr, &phy_size);
		if(likely (ret == 0 ) ) { //caverout phys() always return 0~
			if( unlikely(phy_size != size) ) {
				/*
				  pr_debug(KERN_DEBUG " %s warning physSize:%d(%d) handle:0x%x\n", __FUNCTION__, phy_size, size,  (unsigned int)tmp_handle);
				*/

			}

			*handle = tmp_handle;


			ret_addr = (void*) phy_addr;//use phy addr
		} else {

			pr_debug(KERN_WARNING " GAL %s toPhys fail %d handle:0x%x\n", __FUNCTION__, ret, (unsigned int)handle);
		}



#endif//

	}
#else
#error "aaa"
#endif//


	GAL_ALLOC_SIZE += size;

	mutex_unlock(&gSURFACE_ALLOC_LOCK);

	return ret_addr;


ERR_RET:

	mutex_unlock(&gSURFACE_ALLOC_LOCK);

	return NULL;
}

int xFreeSurfaceMem(RtSurface* rt_surf)
{

	mutex_lock(&gSURFACE_ALLOC_LOCK);

#ifdef GAL_USE_RESERVE_MEM
	ion_free(gHAL_ION_CLIENT, (struct ion_handle *) rt_surf->addr_handle );
	GAL_ALLOC_SIZE -= rt_surf->size;

	if( unlikely( (int)GAL_ALLOC_SIZE < 0 ) ) {
		pr_debug(KERN_WARNING " GAL err!! size <0 handle:0x%x\n", (unsigned int) rt_surf->addr_handle);
	}
	rt_surf->addr_handle = NULL;

#elif defined(GAL_USE_DVR_MEM)
	dvr_free( (void *)rt_surf->virAddr );

#endif//




	mutex_unlock(&gSURFACE_ALLOC_LOCK);

	return 0;
}




RtSurface* xRtSurfaceMgr_AllocSurfaceIndex(void)
{
	unsigned int i=0;
	RtSurface* rt_surf = NULL;
	RtSurface* ret_surf = NULL;

	mutex_lock(&gSURFACE_MGR_LOCK);

	for( ; i< gSURFACE_MAX; i++) {
		rt_surf = &(gSURFACE_LIST[i]);

		if( rt_surf->valid == 0 ) {
			memset(rt_surf, 0, sizeof(RtSurface) );

			if( gSURFACE_INDEX == 0) //skip 0
				++gSURFACE_INDEX;

			rt_surf->index = gSURFACE_INDEX++;

			rt_surf->valid = 1;

			ret_surf = rt_surf;
			goto AllocSurfaceIndexEnd;
		}
	}

AllocSurfaceIndexEnd:

	mutex_unlock(&gSURFACE_MGR_LOCK);


	if( ret_surf == NULL) {
		DBG_GAL_PRINT_ERR("[GAL] %s out of index total:%d %d memSize:%d\n", __FUNCTION__, gSURFACE_MAX, gSURFACE_INDEX,  GAL_ALLOC_SIZE);

	}

	return ret_surf;
}

void xRtSurfaceMgr_FreeSurfaceIndex(RtSurface* rt_surf)
{

	mutex_lock(&gSURFACE_MGR_LOCK);

//memset(rt_surf, 0, sizeof(RtSurface) );
	rt_surf->valid = 0;

	mutex_unlock(&gSURFACE_MGR_LOCK);
}


int xRtSurfaceMgr_FreeVendorSurface_noLock(KADP_HAL_GAL_SURFACE_INFO_T *pSurfaceInfo)
{
	unsigned int i=0;
	RtSurface* rt_surf = NULL;
	int error = RT_HAL_GAL_ERR_BAD;


//mutex_lock(&gSURFACE_MGR_LOCK);

	for( ; i< gSURFACE_MAX; i++) {
		rt_surf = &(gSURFACE_LIST[i]);


		if( rt_surf->index == pSurfaceInfo->vendorData ) {

			break;
		} else {
			rt_surf = NULL;
		}
	}


	if( rt_surf == NULL) {

		DBG_GAL_PRINT_ERR("[GAL]%s fail !! surfIdx:%u (%d %d)\n", __FUNCTION__, pSurfaceInfo->vendorData,
						  pSurfaceInfo->width, pSurfaceInfo->height);

		error =  RT_HAL_GAL_ERR_INDEX;
		goto err_end;
	}

//double confrm w,h
	if( rt_surf->width != pSurfaceInfo->width || (rt_surf->height != pSurfaceInfo->height) ||
		rt_surf->phyAddr != pSurfaceInfo->physicalAddress) {

		DBG_GAL_PRINT_ERR("[GAL]%s fail !! surfIdx:%u (%u %u)--%u %u) 0x%x 0x%x\n", __FUNCTION__, pSurfaceInfo->vendorData,
						  pSurfaceInfo->width, pSurfaceInfo->height, rt_surf->width, rt_surf->height, rt_surf->phyAddr,
						  pSurfaceInfo->physicalAddress);
		error =  RT_HAL_GAL_ERR_MATCH;
		goto err_end;
	}


//free mem
	if ( rt_surf->phyAddr == 0 )
		BUG();

//xFreeMem( (void *)rt_surf->virAddr );
	xFreeSurfaceMem(rt_surf);

	rt_surf->valid = 0;


//mutex_unlock(&gSURFACE_MGR_LOCK);
	return RT_HAL_GAL_ERR_OK;

err_end:
//mutex_unlock(&gSURFACE_MGR_LOCK);

	return error;
}


int kHAL_GAL_CreateSurface(UINT16 width, UINT16 height, KADP_HAL_GAL_PIXEL_FORMAT_T pixelFormat,
						   KADP_HAL_GAL_SURFACE_INFO_T *pSurfaceInfo)
{
	unsigned int size=0;
	int error = RT_HAL_GAL_ERR_BAD;
	void* dvr_addr= NULL;
	int bpp = 0;
	RtSurface* rt_surf = NULL;
	KADP_HAL_GAL_SURFACE_INFO_T* gal_surf= NULL;
	void* addr_handle = NULL;
	int tmp_pitch=0;
	UINT16 height_tmp = 0;

	switch(pixelFormat) {
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB: /**< 32 bit ARGB (4 byte, alpha 8\@24, red 8\@16, green 8\@8, blue 8\@0) */
			bpp = 32;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_FBC:
			bpp = 32;
			break;
		case KADP_HAL_GAL_PIXEL_FORMAT_LUT8:    /**< 8 bit LUT (8 bit color and alpha lookup from palette) */
		case KADP_HAL_GAL_PIXEL_FORMAT_A8:              /**< 8 bit A (1 byte, alpha 8\@0) */
			bpp = 8;
			break;

		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB1555:        /**< 16 bit ARGB (2 byte, alpha 1\@15, red 5\@10, green 5\@5, blue 5\@0) */
		case KADP_HAL_GAL_PIXEL_FORMAT_RGB16:   /**< 16 bit RGB (2 byte, red 5\@11, green 6\@5, blue 5\@0) */
		case KADP_HAL_GAL_PIXEL_FORMAT_ARGB4444:        /**< 16 bit ARGB (2 byte, alpha 4\@12, red 4\@8, green 4\@4, blue 4\@0) */

			bpp = 16;
			break;

		default:
			DBG_GAL_PRINT_WARN("[GAL] invalid pixel format:0x%x\n", pixelFormat);

			break;
	}

	//printk(KERN_ERR " \n [GAL calvin][kHAL_GAL_CreateSurface 1] [fmt=%x][w=%d,h=%d, bpp=%d]\n", pixelFormat, width, height, bpp);
      if(pixelFormat == KADP_HAL_GAL_PIXEL_FORMAT_FBC) //fixme: for test FBDC and use KADP_HAL_GAL_PIXEL_FORMAT_ARGB1555 as temporary
	{
			unsigned int ui32TotalSize = 0, ui32TotalSizeAlign4K = 0;
			unsigned int ui32NumTiles = 0;
			unsigned int ui32NextMapOffset = 0;
			unsigned int ui32PhysicalWidth=0, ui32PhysicalHeight=0;
			unsigned int ui32TotalthumbnailSizeAlign4K;

			if(pixelFormat == KADP_HAL_GAL_PIXEL_FORMAT_FBC)  //fixme: msut remove after KADP_HAL_GAL_PIXEL_FORMAT_FBDC ready
		      		bpp = 32;

#ifdef FBC_1920x1092_GAL_PATCH
			if(width == 1920 && height == 1080)
			{
				height_tmp = 1092;
			}
			else
#endif
			{
				height_tmp = height;
			}

			KERNEL_GetFBCSurfacePhysicalDim2D(KERNEL_FB_COMPRESSION_DIRECT_16x4,
					                                            (unsigned int)width,
					                                            (unsigned int)height_tmp,
					                                            (unsigned int)bpp,
					                                            KERNEL_IMG_MEMLAYOUT_STRIDED,
					                                            &ui32PhysicalWidth,
					                                            &ui32PhysicalHeight);

			if(!KERNEL_GetFBCSurfaceSize2D(KERNEL_FB_COMPRESSION_DIRECT_16x4,
						ui32PhysicalWidth,
						ui32PhysicalHeight,
						(unsigned int)bpp,
						&ui32TotalSize,
						&ui32NumTiles,
						&ui32NextMapOffset))
			{
				DBG_GAL_PRINT_WARN(KERN_ERR "\n [GAL calvin] kHAL_GAL_CreateSurface: GetFBCSurfaceSize2D() failed \n");
			}

			tmp_pitch 			= ui32PhysicalWidth*(bpp>>3);
			ui32TotalSizeAlign4K 	= __GFX_ALIGN(ui32TotalSize, __4KPAGE);
			size 					= ui32TotalSizeAlign4K;

			 /* add memory size for thumbnail sync with FBC */
		       ui32TotalthumbnailSizeAlign4K = (width/FBC_THUMBNAIL_REDUCE_RATE)*(height/FBC_THUMBNAIL_REDUCE_RATE)*(bpp>>3);
			 size += __GFX_ALIGN(ui32TotalthumbnailSizeAlign4K, __4KPAGE);

			//printk(KERN_ERR " \n [GAL][FBDC] size=%x, pitch=%x, ui32TotalSize=%x:%x\n", size, tmp_pitch, ui32TotalSize,ui32TotalSizeAlign4K);

			//if(pixelFormat == KADP_HAL_GAL_PIXEL_FORMAT_FBC) //fixme: msut remove after KADP_HAL_GAL_PIXEL_FORMAT_FBDC ready
			//	bpp = 16;

	}
	else
	{
		tmp_pitch = width*(bpp>>3);  //no-FBDC path
		size = tmp_pitch*height;
	}

	rt_surf = xRtSurfaceMgr_AllocSurfaceIndex();

	if(rt_surf == NULL) {
		error = RT_HAL_GAL_ERR_INDEX;
		goto ERR_RT_HAL_GAL_CreateSurface;
	}

	dvr_addr = xAllocMem(size, &addr_handle);

	if( dvr_addr == NULL) {
		DBG_GAL_PRINT_ERR("kGAL_CreateSurfacefail (%d %d) %d\n", width, height, pixelFormat);
		error = RT_HAL_GAL_ERR_MEM;
		goto ERR_RT_HAL_GAL_CreateSurface;
	}


	gal_surf = &(rt_surf->privateData);

	rt_surf->width = width;
	rt_surf->height = height;
	rt_surf->size = size;
	rt_surf->addr_handle = addr_handle;


#ifdef GAL_USE_RESERVE_MEM
	rt_surf->virAddr = (unsigned int)phys_to_virt((unsigned int)dvr_addr);
	rt_surf->phyAddr = (unsigned int)dvr_addr;

	gal_surf->offset = rt_surf->phyAddr - GAL_MEM_ADDR_START;

#else
	rt_surf->virAddr = (unsigned int)dvr_addr;
	rt_surf->phyAddr =(unsigned int)dvr_to_phys(dvr_addr);

	gal_surf->offset = 0; //invalid

#endif

	gal_surf->physicalAddress = rt_surf->phyAddr;

//kjw test todo ???. need aligh pitch ??
	gal_surf->pitch = tmp_pitch;

	gal_surf->bpp = bpp;
	gal_surf->width = rt_surf->width;
	gal_surf->height = rt_surf->height;
	gal_surf->pixelFormat = pixelFormat;
//gal_surf->paletteInfo = ;
	gal_surf->property = 0;
	gal_surf->vendorData = rt_surf->index;



#if 0
	memset( rt_surf->virAddr, 0x0, size);
	dma_map_single(NULL, (void *)rt_surf->virAddr, size, DMA_TO_DEVICE);
	dma_unmap_single(NULL, (dma_addr_t)rt_surf->virAddr, size, DMA_TO_DEVICE);
#endif//
	if(pSurfaceInfo != NULL)
		memcpy(pSurfaceInfo,gal_surf,sizeof(KADP_HAL_GAL_SURFACE_INFO_T));

	//add by fox for gfx std
	//pr_debug("try to record gfx memory width=%d height=%d\n",width,height );
	if((width*height) <  GFX_SPECIAL_SIZE && total_index < GFX_NUM_MAX && total_size < GFX_CURSOR_SIZE)
	{
		  gfx_data[total_index].phyAddr = gal_surf->physicalAddress;
		  gfx_data[total_index].virtAddr = (unsigned int)phys_to_virt(gal_surf->physicalAddress);
		  gfx_data[total_index].width = gal_surf->width;
		  gfx_data[total_index].height = gal_surf->height;
		  gfx_data[total_index].size = size;
		  gfx_data[total_index].to_phyAddr = 0;
		  gfx_data[total_index].to_virtAddr = 0;
		  total_index++;
		  total_size += size;
		  //pr_debug("record gfx memory width=%d height=%d gal_surf->physicalAddress=%x total_size=%d\n",width,height,gal_surf->physicalAddress,total_size);
	}

	return RT_HAL_GAL_ERR_OK;

ERR_RT_HAL_GAL_CreateSurface:



	if(dvr_addr ) {
//xFreeMem( (void *)rt_surf->virAddr );
		xFreeSurfaceMem(rt_surf);
//rt_surf->virAddr = NULL;
		rt_surf->virAddr = 0;
	}

//put at last line
	if( rt_surf ) { // free index
		xRtSurfaceMgr_FreeSurfaceIndex(rt_surf);
	}

	DBG_GAL_PRINT_WARN(KERN_ERR " \n [GAL][kHAL_GAL_CreateSurface] [fmt=%x][w=%d,h=%d, bpp=%d][err=%x]\n", pixelFormat, width, height, bpp,error);
	return error;
}


int kHAL_GAL_DestroySurface(KADP_HAL_GAL_SURFACE_INFO_T *pSurfaceInfo)
{
//      RtSurface* rt_surf = NULL;
	int error = RT_HAL_GAL_ERR_BAD;

	mutex_lock(&gSURFACE_MGR_LOCK);

//lock in FreeSurface
	error = xRtSurfaceMgr_FreeVendorSurface_noLock(pSurfaceInfo);

	mutex_unlock(&gSURFACE_MGR_LOCK);

	return error;

}


int kHAL_GAL_GetGraphicMemInfo( KDRV_GAL_GRAPHICS_MEM_T* pRTGraphicMemInfo)
{

	pRTGraphicMemInfo->memInfo.gfxMemTotalSize = GAL_MEM_SIZE;
	pRTGraphicMemInfo->memInfo.allocatedMemTotalSize = GAL_ALLOC_SIZE;
	pRTGraphicMemInfo->memInfo.freeMemTotalSize =   GAL_MEM_SIZE - GAL_ALLOC_SIZE;
	pRTGraphicMemInfo->physicalAddrOfBase= GAL_MEM_ADDR_START;

	if(fbcOnOff)
		pRTGraphicMemInfo->bFBCSupported = TRUE;
	else
	   	pRTGraphicMemInfo->bFBCSupported = FALSE;



	{
//pRTGraphicMemInfo->memInfo.largestFreeMemSize =
		int ret;
		int i=0;
		RtSurface* rt_surf=NULL;
		ion_phys_addr_t phy_addr=0xFFFFFFF1;
		size_t len;


		mutex_lock(&gSURFACE_MGR_LOCK);

		for(i=0; i < gSURFACE_MAX; ++i) {
			rt_surf = &(gSURFACE_LIST[i]);

			if( rt_surf->valid ) {
				break;
			}
		}

		if( rt_surf->valid  && gHAL_ION_CLIENT != NULL) {

			ret = ion_phys(gHAL_ION_CLIENT, (struct ion_handle *)rt_surf->addr_handle, &phy_addr, &len);
			if( unlikely(ret != 0) )
				pr_debug("ERR %s %d\n", __FUNCTION__, __LINE__);

			pRTGraphicMemInfo->memInfo.largestFreeMemSize = len;
		} else {
//assume no surface allocated.
			pRTGraphicMemInfo->memInfo.largestFreeMemSize = GAL_MEM_SIZE;
		}

		mutex_unlock(&gSURFACE_MGR_LOCK);


	}
	return 0;
}


int kRtHAL_GAL_InitSurfaceAll(void)
{
//check destroy first !!
//locked in kRtHAL_GAL_DestroySurfaceAll
	kRtHAL_GAL_DestroySurfaceAll();

#ifdef GAL_USE_RESERVE_MEM
	{

		char debug_name[64];
		mutex_lock(&gSURFACE_MGR_LOCK);
		snprintf(debug_name, 64, "gal_%u", task_pid_nr( current->group_leader) );
		gHAL_ION_CLIENT = ion_client_create(rtk_ion_device, debug_name);

		mutex_unlock(&gSURFACE_MGR_LOCK);
	}
#endif//

	return 0;
}



int kRtHAL_GAL_DestroySurfaceAll(void)
{
	int i;
	RtSurface* rt_surf;

	mutex_lock(&gSURFACE_MGR_LOCK);

	for(i=0; i < gSURFACE_MAX; ++i) {
		rt_surf = &(gSURFACE_LIST[i]);

		if( rt_surf->valid ) {
			DBG_GAL_PRINT_ERR("GAL deInit warn:surface not free. surfIdx:%d (%d %d)\n", rt_surf->index, rt_surf->width, rt_surf->height );

//xFreeMem( (void *)rt_surf->virAddr );
			xFreeSurfaceMem(rt_surf);
		}
	}

	memset(gSURFACE_LIST, 0, sizeof(RtSurface)*gSURFACE_MAX );


#ifdef GAL_USE_RESERVE_MEM

	if( gHAL_ION_CLIENT != NULL) {
		ion_client_destroy(gHAL_ION_CLIENT);
		gHAL_ION_CLIENT = NULL;
	}

#endif//


	mutex_unlock(&gSURFACE_MGR_LOCK);


	return 0;


}

static int __init early_parse__gal_fbc(char *str)
{
#if 0
	const char * str_ON="on";
	const char * str_OFF="off";

	if (strncmp(str_OFF,str,strlen(str_OFF))==0) {
		fbcOnOff = FBC_OFF;
		//pr_info("FBC_OFF\n")
	} else if (strncmp(str_ON,str,strlen(str_ON))==0) {
		fbcOnOff = FBC_ON;
		//pr_info("FBC_ON\n");
	} else {
		fbcOnOff = FBC_ON;
		//pr_err("using default value = FBC_ON [%s]\n",str);
	}

	if(get_ic_version() == VERSION_A) {
		fbcOnOff = FBC_OFF;
	}
#endif
	fbcOnOff = FBC_OFF;
	return 0;
}

early_param("fbc", early_parse__gal_fbc);
