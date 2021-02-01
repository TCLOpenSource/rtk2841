
#ifndef _RTK_PLATFORM_H
#define _RTK_PLATFORM_H

#include <linux/pageremap.h>

#define _MB_ 1024*1024

/**
 *  --- Default memory layout start ---
 */
#define VIDEO_RINGBUFFER_START         0x1b200000
#define VIDEO_RINGBUFFER_SIZE			0x1000000
#define VIDEO_RINGBUFFER_SIZE_K2L_ONLY 		 0x1800000

#ifdef CONFIG_REALTEK_LOGBUF
#define CONST_LOGBUF_MEM_ADDR_START (0x1ca00000)
#define CONST_LOGBUF_MEM_SIZE (512*1024) // 512KB
#endif

#ifdef CONFIG_CUSTOMER_TV006	//for GAL reserve mem, 4MB align
extern const int GAL_MEM_SIZE;
extern const int GAL_MEM_ADDR_START;
#else
#define GAL_MEM_SIZE 0
#define GAL_MEM_ADDR_START 0
#endif

#ifdef CONFIG_REALTEK_2K_MODEL_ENABLED
#define VBM_START_ADDRESS_KERNEL       0x20000000  // + 1c00000 (+  28 MB)
#define MDOMAIN_START_ADDRESS_KERNEL   0x21c00000  // + 0
#define VIP_START_ADDRESS_KERNEL       0x21c00000  // + 0800000 (+   8 MB)
#define OD_START_ADDRESS_KERNEL        0x22400000
#else
#ifdef CONFIG_VIDEO_LOSSY_COMP_50P
#define VBM_START_ADDRESS_KERNEL       0x20000000  // + 5800000 (+  88 MB)
#define MDOMAIN_START_ADDRESS_KERNEL   0x25800000  // + 1a00000 (+  26 MB)
#define VIP_START_ADDRESS_KERNEL       0x27200000  // + 0e00000 (+  14 MB)
#define OD_START_ADDRESS_KERNEL        0x28000000
#else
#define VBM_START_ADDRESS_KERNEL       0x20000000  // + 8000000 (+ 128 MB)
#define MDOMAIN_START_ADDRESS_KERNEL   0x28000000  // + 1a00000 (+  26 MB)
#define VIP_START_ADDRESS_KERNEL       0x29a00000  // + 0e00000 (+  14 MB)
#define OD_START_ADDRESS_KERNEL        0x2a800000
#endif
#endif


#define VDEC_BUFFER_START (VBM_START_ADDRESS_KERNEL)
#ifdef CONFIG_REALTEK_2K_MODEL_ENABLED
#define VDEC_BUFFER_SIZE 28*1024*1024  // 28 MB VBM (50% lossy compression + compression header)
#else
#ifdef CONFIG_VIDEO_LOSSY_COMP_50P
#define VDEC_BUFFER_SIZE 88*1024*1024  // 80 MB VBM (50% lossy compression) + 8 MB compression header
#else
#define VDEC_BUFFER_SIZE 128*1024*1024  // 120 MB VBM (default 75% lossy compression) + 8 MB compression header
#endif
#endif

#ifdef VBM_START_ADDRESS_KERNEL
#if (VBM_START_ADDRESS_KERNEL != VDEC_BUFFER_START)
#error "VBM size doesn't match for kernel & drivers!"
#endif
#else
#error "No define VBM_START_ADDRESS_KERNEL"
#endif

#define SCALER_MEMC_START (0)
#define SCALER_MEMC_SIZE (0)

#define SCALER_MDOMAIN_START (VDEC_BUFFER_START + VDEC_BUFFER_SIZE)
#ifdef CONFIG_REALTEK_2K_MODEL_ENABLED
#define SCALER_MDOMAIN_SIZE (0) // frame sync mode, and no memory need for M-Domain
#else
#define SCALER_MDOMAIN_SIZE (26*1024*1024) // 26MB(M-Domain), HW needs
#endif

#if (MDOMAIN_START_ADDRESS_KERNEL != SCALER_MDOMAIN_START)
#error "Scaler M-domain size doesn't match for kernel & drivers!"
#endif

#define SCALER_VIP_START (SCALER_MDOMAIN_START + SCALER_MDOMAIN_SIZE)
#ifdef CONFIG_REALTEK_2K_MODEL_ENABLED
#define SCALER_VIP_SIZE (8*1024*1024) // 2K model 420 mode
#else
#define SCALER_VIP_SIZE (14*1024*1024) // 14MB(DI/RTNR), HW needs
#endif

#if (VIP_START_ADDRESS_KERNEL != SCALER_VIP_START)
#error "Scaler VIP size doesn't match for kernel & drivers!"
#endif

/*
   OD calculation:
   3840 x 2160 x 10bits x 2frame = 20736000 bytes
   20736000 + 512 + 64 = 20736576 bytes (alignment)
 */
#define SCALER_OD_ENABLE 0
#define SCALER_OD_ENABLE_CARVED_OUT 1
#define SCALER_OD_START (SCALER_VIP_START + SCALER_VIP_SIZE)
#if SCALER_OD_ENABLE_CARVED_OUT
#define SCALER_OD_SIZE  4*1024*1024
#else
#define SCALER_OD_SIZE  0*1024*1024
#endif

//fixme: why can't enable this compile check in arm64?
#ifndef CONFIG_ARM64
#ifdef OD_START_ADDRESS_KERNEL
#if (OD_START_ADDRESS_KERNEL != SCALER_OD_START)
#error "Scaler OD size doesn't match for kernel & drivers!"
#endif
#else
#error "No define OD_START_ADDRESS_KERNEL"
#endif
#endif

#define SCLAER_MODULE_START SCALER_MDOMAIN_START
#define SCALER_MODULE_SIZE (SCALER_MDOMAIN_SIZE + SCALER_VIP_SIZE + SCALER_OD_SIZE) // must be 4MB page block alignment

#if (SCALER_MODULE_SIZE & 0x3FFFFF) // 4MB align
#error "Scaler module size didn't follow 4MB alignment"
#endif

#define DEMUX_TP_BUFFER_START (SCLAER_MODULE_START + SCALER_MODULE_SIZE)
#ifdef CONFIG_RTK_KDRV_DEMUX
#define DEMUX_TP_BUFFER_SIZE 0*_MB_  // must be 4MB page block alignment
#else
#define DEMUX_TP_BUFFER_SIZE 0
#endif

#define GPU_MEM_SIZE 128*1024*1024    // for 1GB AndroidTV

#define RTK_GPU_FW_SIZE (512*1024)

/* static reserved for drivers, which allocate from cma region original */
#define CMA_HIGH_RESERVED_SIZE        (GPU_MEM_SIZE)               // reserved for high memory

/**
 *  --- Default memory layout end ---
 */


/**
 *  --- China 512MB memory layout start ---
 */
#define CHINA_512MB_VIDEO_RINGBUFFER_START         0x1b200000
#define CHINA_512MB_VIDEO_RINGBUFFER_SIZE			0x1000000
#define CHINA_512MB_VIDEO_RINGBUFFER_SIZE_K2L_ONLY 		 0x1800000

#ifdef CONFIG_REALTEK_LOGBUF
#define CHINA_512MB_CONST_LOGBUF_MEM_ADDR_START (0x1ca00000)
#define CHINA_512MB_CONST_LOGBUF_MEM_SIZE (512*1024)    //-- Need to lower down to 512KB
#endif

#ifdef CONFIG_CUSTOMER_TV006	//for GAL reserve mem, 4MB align
extern const int CHINA_512MB_GAL_MEM_SIZE;
extern const int CHINA_512MB_GAL_MEM_ADDR_START;
#else
#define CHINA_512MB_GAL_MEM_SIZE 0
#define CHINA_512MB_GAL_MEM_ADDR_START 0
#endif

#define CHINA_512MB_VBM_START_ADDRESS_KERNEL       0x10000000  // + 5800000 (+ 88M)
#define CHINA_512MB_MDOMAIN_START_ADDRESS_KERNEL   0x15800000  // + 0a00000 (+ 10M)
#define CHINA_512MB_VIP_START_ADDRESS_KERNEL       0x16200000  // + 0e00000 (+ 14M)
#define CHINA_512MB_OD_START_ADDRESS_KERNEL        0x17000000

#define CHINA_512MB_VDEC_BUFFER_START (CHINA_512MB_VBM_START_ADDRESS_KERNEL)
#define CHINA_512MB_VDEC_BUFFER_SIZE 88*1024*1024 // 80 MB VBM (50% lossy compression) + 8 MB compression header

#ifdef CHINA_512MB_VBM_START_ADDRESS_KERNEL
#if (CHINA_512MB_VBM_START_ADDRESS_KERNEL != CHINA_512MB_VDEC_BUFFER_START)
#error "China 512MB VBM size doesn't match for kernel & drivers!"
#endif
#else
#error "No define CHINA_512MB_VBM_START_ADDRESS_KERNEL"
#endif

#define CHINA_512MB_SCALER_MEMC_START (CHINA_512MB_VDEC_BUFFER_START + CHINA_512MB_VDEC_BUFFER_SIZE)
#define CHINA_512MB_SCALER_MEMC_SIZE (0)

#define CHINA_512MB_SCALER_MDOMAIN_START (CHINA_512MB_SCALER_MEMC_START + CHINA_512MB_SCALER_MEMC_SIZE)
#define CHINA_512MB_SCALER_MDOMAIN_SIZE (10*1024*1024) // 10MB(M-Domain), HW needs

#if (CHINA_512MB_MDOMAIN_START_ADDRESS_KERNEL != CHINA_512MB_SCALER_MDOMAIN_START)
#error "China 512MB Scaler M-domain size doesn't match for kernel & drivers!"
#endif

#define CHINA_512MB_SCALER_VIP_START (CHINA_512MB_SCALER_MDOMAIN_START + CHINA_512MB_SCALER_MDOMAIN_SIZE)
#define CHINA_512MB_SCALER_VIP_SIZE (14*1024*1024) // 14MB(DI/RTNR+DMA to 3D table), HW needs

#if (CHINA_512MB_VIP_START_ADDRESS_KERNEL != CHINA_512MB_SCALER_VIP_START)
#error "China 512MB Scaler VIP size doesn't match for kernel & drivers!"
#endif

/*
   OD calculation:
   3840 x 2160 x 10bits x 2frame = 20736000 bytes
   20736000 + 512 + 64 = 20736576 bytes (alignment)
 */
#define CHINA_512MB_SCALER_OD_ENABLE 0
#define CHINA_512MB_SCALER_OD_ENABLE_CARVED_OUT 1
#define CHINA_512MB_SCALER_OD_START (CHINA_512MB_SCALER_VIP_START + CHINA_512MB_SCALER_VIP_SIZE)
#if CHINA_512MB_SCALER_OD_ENABLE_CARVED_OUT
#define CHINA_512MB_SCALER_OD_SIZE  4*1024*1024
#else
#define CHINA_512MB_SCALER_OD_SIZE  0*1024*1024
#endif

//fixme: why can't enable this compile check in arm64?
#ifndef CONFIG_ARM64
#ifdef CHINA_512MB_OD_START_ADDRESS_KERNEL
#if (CHINA_512MB_OD_START_ADDRESS_KERNEL != CHINA_512MB_SCALER_OD_START)
#error "China 512MB Scaler OD size doesn't match for kernel & drivers!"
#endif
#else
#error "No define CHINA_512MB_OD_START_ADDRESS_KERNEL"
#endif
#endif

#define CHINA_512MB_SCLAER_MODULE_START CHINA_512MB_SCALER_MEMC_START
#define CHINA_512MB_SCALER_MODULE_SIZE (CHINA_512MB_SCALER_MEMC_SIZE + CHINA_512MB_SCALER_MDOMAIN_SIZE + CHINA_512MB_SCALER_VIP_SIZE + CHINA_512MB_SCALER_OD_SIZE) // must be 4MB page block alignment

#if (CHINA_512MB_SCALER_MODULE_SIZE & 0x3FFFFF) // 4MB align
#error "Scaler module size didn't follow 4MB alignment"
#endif

#define CHINA_512MB_DEMUX_TP_BUFFER_START (CHINA_512MB_SCLAER_MODULE_START + CHINA_512MB_SCALER_MODULE_SIZE)
#ifdef CONFIG_RTK_KDRV_DEMUX
#define CHINA_512MB_DEMUX_TP_BUFFER_SIZE 0*_MB_  // must be 4MB page block alignment    // 512MB co-buffer with VBM
#else
#define CHINA_512MB_DEMUX_TP_BUFFER_SIZE 0
#endif

#define CHINA_512MB_RTK_GPU_FW_SIZE (512*1024)

/**
 *  --- China 512MB memory layout end ---
 */


// Force reserving KCPU carved-out memory, even kernel config CONFIG_REALTEK_SECURE is disabled
#define FORCE_RESERVE_KCPU_MEM


typedef enum {
	/* address 512MB before */
	CARVEDOUT_BOOTCODE = 0,
	CARVEDOUT_DEMOD,        // device
	CARVEDOUT_AV_DMEM,
#if defined(CONFIG_REALTEK_SECURE) || defined(FORCE_RESERVE_KCPU_MEM)
	CARVEDOUT_K_BOOT,
	CARVEDOUT_K_OS,
#endif
	CARVEDOUT_MAP_RBUS,
#ifdef CONFIG_REALTEK_SECURE_DDK
	CARVEDOUT_GPU_FW,
#endif
	CARVEDOUT_AV_OS,
#if defined(CONFIG_REALTEK_RPC) ||defined(CONFIG_RTK_KDRV_RPC)
	CARVEDOUT_MAP_RPC,
#endif
	CARVEDOUT_VDEC_RINGBUF, // device
#ifdef CONFIG_REALTEK_LOGBUF
	CARVEDOUT_LOGBUF,
#endif
	CARVEDOUT_ROMCODE,
#ifdef CONFIG_PSTORE
	CARVEDOUT_RAMOOPS,
#endif

	/* device */
#ifdef CONFIG_CUSTOMER_TV006
	CARVEDOUT_GAL,
#endif
#ifdef CONFIG_LG_SNAPSHOT_BOOT
	CARVEDOUT_SNAPSHOT,
#endif
	CARVEDOUT_SCALER,
	CARVEDOUT_SCALER_MEMC,
	CARVEDOUT_SCALER_MDOMAIN,
	CARVEDOUT_SCALER_VIP,
	CARVEDOUT_SCALER_OD,
	CARVEDOUT_VDEC_VBM,
	CARVEDOUT_TP,

	/* for desired cma size calculation */
	CARVEDOUT_CMA_LOW,
	CARVEDOUT_CMA_HIGH,

#ifdef CONFIG_ZONE_ZRAM
	CARVEDOUT_ZONE_ZRAM,
#endif

	/* array end number */
	CARVEDOUT_NUM,

	/* for reserved size in highmem */
	CARVEDOUT_HIGH_START = CARVEDOUT_SCALER_MDOMAIN,
	CARVEDOUT_HIGH_END = CARVEDOUT_TP

} carvedout_buf_t;

typedef enum {
	CARVEDOUT_NO_FALLBACK = 0,
	CARVEDOUT_FALLBACK_TO_CMA,
	CARVEDOUT_FALLBACK_TO_VBM
} carvedout_fallback_type_t;

typedef enum {
	MM_LAYOUT_DEFAULT = 0,
	MM_LAYOUT_CHINA512MB,

	MM_LAYOUT_CARVEDOUT_NUM
} mm_layout_index_t;

extern unsigned long carvedout_buf[MM_LAYOUT_CARVEDOUT_NUM][CARVEDOUT_NUM][2];

enum PLAFTORM_TYPE
{
	PLATFORM_K2LP	= 0,
	PLATFORM_K3LP	= 0,
	PLATFORM_K2L	= 1,
	PLATFORM_K3L	= 1,
	PLATFORM_OTHER
};

#define PLATFORM_KXLP	PLATFORM_K3LP
#define PLATFORM_KXL	PLATFORM_K3L

enum PLAFTORM_TYPE get_platform (void);
unsigned long get_uart_clock(void);

unsigned int get_memory_layout_index(void);
unsigned long carvedout_buf_query(carvedout_buf_t what, void **addr);
unsigned long carvedout_buf_query_range(carvedout_buf_t idx_start, carvedout_buf_t idx_end, void **start, void **end);
unsigned int carvedout_fallback_query(carvedout_buf_t what);

#endif //_RTK_PLATFORM_H

