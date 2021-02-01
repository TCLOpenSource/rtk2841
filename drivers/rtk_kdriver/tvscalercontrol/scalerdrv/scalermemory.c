/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for memory related functions.
 *
 * @author 	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	memory
 */

/**
 * @addtogroup memory
 * @{
 */

/*============================ Module dependency  ===========================*/

//#include <unistd.h>			// 'close()'
//#include <fcntl.h>			// 'open()'
//#include <stdio.h>
//#include <string.h>
//#include <sys/mman.h>
#include <linux/delay.h>
#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
#include <rtk_kdriver/RPCDriver.h>
#include <linux/pageremap.h>
#include <uapi/linux/const.h>
#include <linux/mm.h>
#include <linux/auth.h>
//#include <mach/io.h>
//#include "rtd_regs.h"
//#include "rtd_macro.h"
#include <rbus/mdomain_cap_reg.h>
#include <rbus/mdomain_disp_reg.h>
#include <rbus/di_reg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/mdomain_vi_main_reg.h>

//#include <rbus/scaler/rbustv-sb2-dcu1reg.h>
#include <rtk_kdriver/scalercommon/scalerCommon.h>
#include <tvscalercontrol/scalerdrv/scalerdisplay.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/io/ioregdrv.h>
//#include <tvscalercontrol/scaler/scalerstruct.h>
//#include <tvscalercontrol/scaler/modeState.h>
//#include <tvscalercontrol/scaler/scalerTimer.h>
//#include "tvscalercontrol/scaler/scalerLib.h"
//#include <tvscalercontrol/scaler/scalerColorLib.h>
#include <tvscalercontrol/vip/scalerColor.h>

#include <tvscalercontrol/scalerdrv/scalerclock.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/scaler/scalercolorlib.h>
//#include "tvscalercontrol/scalerDrv/scalerDisplay.h"
#include <tvscalercontrol/scalerdrv/mode.h>
#include <tvscalercontrol/scalerdrv/pipmp.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/scalerdrv/scalerip.h>
#include <tvscalercontrol/panel/panelapi.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
//#include "kernel/scaler/scalerDrv.h"	// kernel driver
#include "tvscalercontrol/vdc/video.h"
#include "tvscalercontrol/hdmirx/hdmifun.h"
//#include "Platform_Lib/panel/panelAPI.h"
//#include "tvscalercontrol/scaler/scalerAPI.h"
//#include "tvscalercontrol/scaler/state.h" //for drvif_memory_sw_buffer_swap_action()
#include <tvscalercontrol/scalerdrv/scaler_2dcvt3d_ctrl.h>
#include <tvscalercontrol/vip/di_ma.h>
#include <tvscalercontrol/i3ddma/i3ddma.h>
#include <tvscalercontrol/scalerdrv/framesync.h>

//#include <rbus/demura_reg.h>
#include <rbus/de_xcxl_reg.h>

#include <rpc/VideoRPC_System.h>
#include <rpc/VideoRPC_System_data.h>
#include <rbus/scaleup_reg.h>
#include <rbus/scaledown_reg.h>
#include <tvscalercontrol/scalerdrv/zoom_smoothtoggle_lib.h>
#include <tvscalercontrol/scalerdrv/scaler_hdr_ctrl.h>
#include <../tvscalercontrol/scaler_vscdev.h>
#include <mach/rtk_platform.h>
#include <mach/rtk_log.h>
#define TAG_NAME "VPQ_MEM"
#include <tvscalercontrol/scaler_vscdev.h>

#include <scalercommon/vipRPCCommon.h>

// for register dump
#include <tvscalercontrol/io/ioregdrv.h>
#undef rtd_outl
#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#undef rtd_inl
#define rtd_inl(x)     									IoReg_Read32(x)
#undef rtd_maskl
#define rtd_maskl(x, y, z)     							IoReg_Mask32(x,y,z)
#undef rtd_setbits
#define rtd_setbits(offset, Mask) rtd_outl(offset, (rtd_inl(offset) | Mask))
#undef rtd_clearbits
#define rtd_clearbits(offset, Mask) rtd_outl(offset, ((rtd_inl(offset) & ~(Mask))))

/*===================================  Types ================================*/
#ifdef USE_RTK_DEV_MEM
#define DEV_MEM     "/dev/rtkmem"
#else
#define DEV_MEM     "/dev/mem"
#endif

//#define CONFIG_DARWIN_SCALER
//#define CONFIG_MPIXEL_SHIFT
/*================================ Definitions ==============================*/
// DI bit number control (saving bandwidth)
#define DI_DMA_420_EN_START_BIT			30
#define DI_DMA_420_EN_MASK				(0x3 << DI_DMA_420_EN_START_BIT)
#define DI_DMA_LINESIZE_EVEN_START_BIT	12
#define DI_DMA_LINESIZE_EVEN_MASK			(0x7ff << DI_DMA_LINESIZE_EVEN_START_BIT)
#define DI_DMA_LINESIZE_ODD_START_BIT		0
#define DI_DMA_LINESIZE_ODD_MASK			(0x7ff << DI_DMA_LINESIZE_ODD_START_BIT)

//FBUS region
#define FBOUS_ADDRESS_LOW	0x1dc00000
#define FBOUS_ADDRESS_HIGH	0x20000000

#define Mag2_New_Flow // LearnRPG@20150430 new API for clear coding style


#ifdef BUILD_DEBUG_CONTROL
#define ScalerMemory_Printf(format, args...){\
	if( DebugMsg.scaler.scalerMemory ==1 )	pr_debug(format, ##args);\
}
#else
#ifdef CONFIG_SCALER_MEMORY_SHOW_MESSAGE_ENABLE
#define ScalerMemory_Printf pr_debug
#else
#define ScalerMemory_Printf(...)
#endif
#endif
/*================================== Variables ==============================*/


static StructMemBlock MemTag[MEMIDX_UNKNOW];	// memory tag information
static unsigned int	AllocStartAddr = 0x00000000;
static unsigned int	AllocEndAddr = _DDR_END_ADDR;
static unsigned int	AllocStartAddrBlock[MEM_BLOCK_TOTAL_NUM];
static unsigned int	AllocEndAddrBlock[MEM_BLOCK_TOTAL_NUM];
//static unsigned int scaler_mem_virtualuncacheAddr=0;
unsigned char	*m_pCacheStartAddr = NULL;
unsigned long 	m_PhyStartAddr;
unsigned int	mMallocSize = 0x2000000;//0x1800000;//24MB//0x2100000;//33MB
//BYTE			*m_pSubMCacheStartAddr = NULL;
//BYTE			*m_pVDCCacheStartAddr = NULL;


extern unsigned char flag_3d;
#ifdef CONFIG_I2RND_ENABLE
unsigned int total_line_size = 0;
extern unsigned char vsc_i2rnd_sub_stage;
#endif
// 3DDI memory usage control
static unsigned int bIpBtrMode=_DISABLE, bIpDma420Mode=_DISABLE;
static unsigned int MemDispStartAddr_3D [3];	//record memory disp start address for 3D
//frank@1023 add flag to indicate memory only DCU1 memory
//static bool m_only_dcu1=_FALSE;

static UINT8 enable_M_compression_main = 0;
static UINT8 enable_M_compression_sub = 0;
static UINT8 M_compression_bits = COMPRESSION_NONE_BITS;
static UINT32 M_fixed_virtual_memory_size = 0;
static UINT8 enable_M_GameMode = _DISABLE;
static UINT8 enable_M_GameMode_Dynamic = _DISABLE;

extern DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr; // debug scaler flag tracker

/*=================== Local Functions Phototype ==============*/

/*=================== Local Functions Phototype ==============*/
#ifndef Mag2_New_Flow
static void drv_memory_DMA420_config(unsigned char *bitNum);
#endif
extern unsigned char get_sub_OutputVencMode(void);




/*================================== Function ===============================*/

/*============================================================================*/
#if 0
/**
 * memory_clear_mem_tag
 * Clear the specific memory tag
 *
 * @param <Idx> { index of DDR memory space, see eMemIdx for details }
 * @return { none }
 *
 */
//void __init memory_clear_mem_tag(eMemIdx Idx)
void memory_clear_mem_tag(eMemIdx Idx)
{
	unsigned char i;

	switch (Idx) {
		case MEMIDX_ALL:	//clear free block information
			for (i = 0; i < MEMIDX_ALL; i++) {	// clear all tag information
				MemTag[i].StartAddr = _DUMMYADDR;	// clear all tags
				MemTag[i].Size = 0x00;		// clear all tags
				MemTag[i].Status = 0;
			}
			break;
		default:
			drvif_memory_free_block(Idx);
			MemTag[Idx].StartAddr = _DUMMYADDR;	//clear the specific tag
			MemTag[Idx].Size = 0x0000;		//clear the specific tag
			MemTag[Idx].Status = 0;
			break;
	}
}
#endif

/*=======================================================================*/
/**
 * drvif_memory_init
 * Init Memory control module. Collect the register, which should be insert only once.
 *
 * @param  { none }
 * @return { none }
 *
 * @Note
 * Mclk is separated into 32 phases
 */
//void __init drvif_memory_init(void)
void drvif_memory_init(void)
{
#ifdef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
	unsigned char i;
	for ( i=MEMIDX_VDC ; i<MEMIDX_ALL ; ++i ) {	// clear all tag information
		MemTag[i].Allocate_StartAddr = 0;
		MemTag[i].StartAddr = _DUMMYADDR;
		MemTag[i].Size = 0;
		MemTag[i].Status = UNDEFINED;
	}
#else

	unsigned int address=0;
	unsigned int size=0;
	//unsigned int  TotalSize;
	//unsigned char				*m_pNonCacheStartAddr;

	SCALERDRV_ALLOCBUFFER_INFO stAllocBufferInfo;
	if(!drvif_scaler_getValidMemInfo(&stAllocBufferInfo)){
		pr_debug("fail to get memory information\n");
		return;
	}

	AllocStartAddrBlock[MEM_BLOCK_USE_NORMAL] = stAllocBufferInfo.normal_mem_addr;
	AllocEndAddrBlock[MEM_BLOCK_USE_NORMAL] = AllocStartAddrBlock[MEM_BLOCK_USE_NORMAL] + stAllocBufferInfo.normal_mem_size;

	AllocStartAddrBlock[MEM_BLOCK_USE_OPTIMIZE] = stAllocBufferInfo.optimize_mem_addr;
	AllocEndAddrBlock[MEM_BLOCK_USE_OPTIMIZE] = AllocStartAddrBlock[MEM_BLOCK_USE_OPTIMIZE] + stAllocBufferInfo.optimize_mem_size;

	address = stAllocBufferInfo.normal_mem_addr;
	size = stAllocBufferInfo.normal_mem_size;

	AllocStartAddr = address;
	AllocEndAddr = AllocStartAddr  + size;

	drvif_memory_free_block(MEMIDX_ALL);

	//Disable channel1, channel2 field merge function
	IoReg_ClearBits(MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_ClearBits(MDOMAIN_CAP_Cap_In2_enable_reg, _BIT0);
#endif

	//frank@0121 Disable function display main,  down mask window, display sub, MP function
	//if(Scaler_Get_Keep_In_BootUp_Mode_flag()==FALSE)
		IoReg_ClearBits(MDOMAIN_DISP_Disp_main_enable_reg, _BIT0);
	IoReg_ClearBits(MDOMAIN_DISP_DDR_MainMaskCtrl_reg,_BIT0);

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_ClearBits(MDOMAIN_DISP_DDR_SubCtrl_reg, _BIT0);
	IoReg_ClearBits(MDOMAIN_DISP_DDR_SubMPMode_reg,_BIT0);
#endif

	drvif_memory_set_dbuffer_write();

#ifdef VBY_ONE_PANEL
	if((MemTag[MEMIDX_MAIN_THIRD].StartAddr!=NULL) && (MemTag[MEMIDX_MAIN_THIRD].StartAddr < AllocStartAddr))
		IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg, (MemTag[MEMIDX_MAIN_THIRD].StartAddr & 0x7ffffff0));
	else
		IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg, (AllocStartAddr & 0x7ffffff0));
#else
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,(AllocStartAddr & 0x7ffffff0));
#endif
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,(AllocEndAddr-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);

	//set cap sub boundary. 1  unit = 8 bytes
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
//for sub cap/disp use in DCU2
	IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr1_reg,(AllocStartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg,(AllocEndAddr-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
#endif
#endif
	pr_debug("Initial Memory is completed. \n");
}

void drvif_memory_release(void)
{
	unsigned char i;
	for ( i=MEMIDX_VDC ; i<MEMIDX_ALL ; ++i ) {	// clear all tag information
		if(drvif_memory_get_block_addr((eMemIdx)i)!=_DUMMYADDR)
			pr_debug("[ERROR]Idx:%d,Memory Not be release\n", i);
	}
	drvif_scaler_releaseValidMem();
	AllocStartAddr = 0;
	AllocEndAddr = _DDR_END_ADDR;
}

void drvif_memory_reallocate(void)
{
#ifdef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
	return;
#else
	unsigned int address=0;
	unsigned int size=0;
	SCALERDRV_ALLOCBUFFER_INFO stAllocBufferInfo;

#if 0
	if(!drvif_scaler_getValidMemInfo(&address, &size)){
		pr_debug("fail to get memory information\n");
		return;
	}
#else
	if(!drvif_scaler_getValidMemInfo(&stAllocBufferInfo)){
		pr_debug("fail to get memory information\n");
		return;
	}

	AllocStartAddrBlock[MEM_BLOCK_USE_NORMAL] = stAllocBufferInfo.normal_mem_addr;
	AllocEndAddrBlock[MEM_BLOCK_USE_NORMAL] = AllocStartAddrBlock[MEM_BLOCK_USE_NORMAL] + stAllocBufferInfo.normal_mem_size;

	AllocStartAddrBlock[MEM_BLOCK_USE_OPTIMIZE] = stAllocBufferInfo.optimize_mem_addr;
	AllocEndAddrBlock[MEM_BLOCK_USE_OPTIMIZE] = AllocStartAddrBlock[MEM_BLOCK_USE_OPTIMIZE] + stAllocBufferInfo.optimize_mem_size;

	address = stAllocBufferInfo.normal_mem_addr;
	size = stAllocBufferInfo.normal_mem_size;

#endif
	AllocStartAddr = address;
	AllocEndAddr = AllocStartAddr  + size;
#ifndef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
	//set capture upper boundary is end address -512 size,avoid capture fail address
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg, (AllocStartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,(AllocEndAddr-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);

	//set cap sub boundary. 1  unit = 8 bytes
#ifdef CONFIG_DUAL_CHANNEL
	IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr1_reg,(AllocStartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg,(AllocEndAddr-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
#endif
#endif
#endif//#ifdef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY

}



 int drvif_scaler_getValidMemInfo_fromVideo(SCALERDRV_ALLOCBUFFER_INFO *pAllocBufferInfo)
{
	int ret=0;
	unsigned int i = 0, ulAllocBufInfoItemCount = 0;
	unsigned int *pulTemp;
	SCALERDRV_ALLOCBUFFER_INFO stAllocBufferInfo;

	memset(pAllocBufferInfo, 0, sizeof(SCALERDRV_ALLOCBUFFER_INFO));
	memset(&stAllocBufferInfo, 0, sizeof(SCALERDRV_ALLOCBUFFER_INFO));
	// send RPC to request allocate buffer address
	if ((ret = Scaler_SendRPC(SCALERIOC_ALLOBUFFER,0,0)) < 0)
	{
		pr_debug( "[IDMA] ret=%d, get alloc buffer address failed!!!\n", ret );
		pAllocBufferInfo->normal_mem_addr = 0;
		pAllocBufferInfo->normal_mem_size = 0;
		pAllocBufferInfo->optimize_mem_addr = 0;
		pAllocBufferInfo->optimize_mem_size = 0;
	}else{
		// copy from RPC share memory
		memcpy(&stAllocBufferInfo, (unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_ALLOBUFFER), sizeof(SCALERDRV_ALLOCBUFFER_INFO));

		// change endian
		ulAllocBufInfoItemCount = sizeof(SCALERDRV_ALLOCBUFFER_INFO) / sizeof(unsigned int);
		pulTemp = (unsigned int *)&stAllocBufferInfo;
		for (i = 0; i < ulAllocBufInfoItemCount; i++)
		        pulTemp[i] = Scaler_ChangeUINT32Endian(pulTemp[i]);

		pAllocBufferInfo->normal_mem_addr = stAllocBufferInfo.normal_mem_addr;
		pAllocBufferInfo->normal_mem_size = stAllocBufferInfo.normal_mem_size;
		pAllocBufferInfo->optimize_mem_addr = stAllocBufferInfo.optimize_mem_addr;
		pAllocBufferInfo->optimize_mem_size = stAllocBufferInfo.optimize_mem_size; // reserve 8 bytes for FRC memory issue
	}

	pr_debug("[IDMA][RPC][Addr:%x][Size:%d KB]\n", pAllocBufferInfo->normal_mem_addr, pAllocBufferInfo->normal_mem_size >> 10);
	pr_debug("[IDMA][RPC][Addr_opt:%x][Size_opt:%d KB]\n", pAllocBufferInfo->optimize_mem_addr, pAllocBufferInfo->optimize_mem_size >> 10);

	return ret;
}



//#define nonCacheMem(a)	(a+DEF_MEM_SIZE)
unsigned char drvif_scaler_getValidMemInfo(SCALERDRV_ALLOCBUFFER_INFO *pAllocBufferInfo)
{
	//int ret;
	//unsigned int ulAllocBufInfoItemCount = 0;
	//unsigned int *pulTemp;
	//SCALERDRV_ALLOCBUFFER_INFO stAllocBufferInfo;
#ifdef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
	return FALSE;
#else
	unsigned char		*m_pNonCacheStartAddr;
	unsigned long 		m_PhyStartAddr;

	if (pAllocBufferInfo == NULL)
		return FALSE;

	pAllocBufferInfo->normal_mem_addr = 0;
	pAllocBufferInfo->normal_mem_size = 0;
	pAllocBufferInfo->optimize_mem_addr = 0;
	pAllocBufferInfo->optimize_mem_size = 0;

	if (pAllocBufferInfo->normal_mem_size == 0 || pAllocBufferInfo->optimize_mem_addr == 0) // if video fw doesn't give the valid memory address
	{
#if 0
		// alloc memory
		m_PhyStartAddr = pli_allocOverlappedMemory(mMallocSize);
		if(m_PhyStartAddr == 0){
			m_pCacheStartAddr = (BYTE *)pli_allocContinuousMemorySpecific(mMallocSize, (char**)&m_pNonCacheStartAddr, &m_PhyStartAddr, GFP_DCU1);
			if(m_pCacheStartAddr == NULL){
				pr_debug("[ERROR]Allocate DCU1 size=%x fail\n",mMallocSize);
				return FALSE;
			}
		}
#else
		m_pCacheStartAddr = dvr_malloc(mMallocSize);
		//m_PhyStartAddr = (unsigned int)virt_to_phys((void*)m_pCacheStartAddr);
		m_PhyStartAddr = (unsigned int)dvr_to_phys((void*)m_pCacheStartAddr);
		if(m_PhyStartAddr == 0){
				pr_debug("[ERROR]Allocate DCU1 size=%x fail\n",mMallocSize);
				return FALSE;
		}

#endif
		pAllocBufferInfo->normal_mem_addr = (unsigned int)m_PhyStartAddr;
		pAllocBufferInfo->normal_mem_size = mMallocSize;
		pAllocBufferInfo->optimize_mem_addr = (unsigned int)m_PhyStartAddr;
		pAllocBufferInfo->optimize_mem_size = mMallocSize;//0x1000000; // 16MB

		pr_debug("[SLR_MEMORY3][PLI][Cache:%x][Phy:%x][Size:%x]\n", (unsigned int)m_pCacheStartAddr, (unsigned int)m_PhyStartAddr, mMallocSize);
		pr_debug("[SLR_MEMORY3][PLI][Addr:%x][Size:%x]\n", pAllocBufferInfo->normal_mem_addr, pAllocBufferInfo->normal_mem_size);
		pr_debug("[SLR_MEMORY3][PLI][Addr_opt:%x][Size_opt:%x]\n", pAllocBufferInfo->optimize_mem_addr, pAllocBufferInfo->optimize_mem_size);
		pr_debug("[SLR_MEMORY3][PLI][nonCache:%x]\n", (unsigned int)m_pNonCacheStartAddr);
	}
	//scaler_mem_virtualuncacheAddr = nonCacheMem(pAllocBufferInfo->normal_mem_addr);

	return TRUE;
#endif
}

unsigned char drvif_scaler_releaseValidMem(void)
{
#ifdef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
	drvif_memory_free_block(MEMIDX_ALL);
#else
#if 0

	if(m_pCacheStartAddr == NULL){
		if(m_PhyStartAddr != 0){
			pli_freeOverlappedMemory(m_PhyStartAddr);
		}else{
			return FALSE;
		}
	}else{
		pli_freeContinuousMemory(m_pCacheStartAddr);
		m_pCacheStartAddr = NULL;
	}
#else
	if(m_pCacheStartAddr == NULL){
		return FALSE;
	}
	else
	{
		dvr_free((void *)m_pCacheStartAddr);
		m_pCacheStartAddr = NULL;
	}
#endif
#endif

	return TRUE;
}

#if 0
static unsigned int drv_memory_get_mem_remap_addr(unsigned int phyAddr, unsigned int length)
{
	int mem_fd;
	volatile void* pMem;
	unsigned int result = 0;
	if((mem_fd=open(DEV_MEM, O_RDWR)) < 0){
		pr_debug("Err: can't open DEV_MEM.\n");
		return 0;
	}

	pMem = mmap(0, length, PROT_READ|PROT_WRITE, MAP_SHARED, mem_fd, phyAddr);

	if(pMem == MAP_FAILED){
		pr_debug("Err: can't get the mmap adress pointer\n");
		close(mem_fd);
		return 0;
	}

	result = (unsigned int)pMem;
	close(mem_fd);
	return result;
}
#endif
#if 0
unsigned int get_scaler_memory_map_addr()
{
#if 1
	return drv_memory_get_mem_remap_addr(AllocStartAddr,  AllocEndAddr - AllocStartAddr);
#else
	return scaler_mem_virtualAddr;
#endif
}
#endif

unsigned char drvif_memory_switch_mem_block(eMemBlockUsage mem_block_usage)
{
	if (mem_block_usage >= MEM_BLOCK_TOTAL_NUM)
	{
		pr_debug("[SLR_MEMORY][unknown mem block][%x~%x]\n", AllocStartAddr, AllocEndAddr);
		return FALSE;
	}

	AllocStartAddr = AllocStartAddrBlock[mem_block_usage];
	AllocEndAddr = AllocEndAddrBlock[mem_block_usage];
#ifndef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
	//set cap main boundary. 1  unit = 8 bytes
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg, (AllocStartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,(AllocEndAddr-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);

	//set cap sub boundary. 1  unit = 8 bytes
#ifdef CONFIG_DUAL_CHANNEL
	IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr1_reg,(AllocStartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg,(AllocEndAddr-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
#endif
#endif

	pr_debug("[SLR_MEMORY][switch to mem block %d][%x~%x](%d MB)\n", mem_block_usage, AllocStartAddr, AllocEndAddr, (AllocEndAddr-AllocStartAddr)>>20);
	return TRUE;
}
#if 0
unsigned int get_scaler_memory_map_uncacheaddr()
{
	return scaler_mem_virtualuncacheAddr;
}
#endif


unsigned int get_scaler_memory_base_addr()
{
	return AllocStartAddr;

	}

unsigned int memory_get_line_size(unsigned int LineSize, unsigned char InputFormat, unsigned char BitNum)
{

	if(InputFormat){
		if(BitNum) {		// 4:4:4 format     10bit
			LineSize = drvif_memory_get_data_align(LineSize *30, 64);
			LineSize = (unsigned int)SHR(LineSize, 6);	// (pixels of per line * 30 / 64), unit: 64bits
			pr_debug("\n 444_10 bits !");
		} else {			// 4:4:4 format     8bit
			LineSize = drvif_memory_get_data_align(LineSize*24, 64);
			LineSize = (unsigned int)SHR(LineSize, 6);	// (pixels of per line * 24 / 64), unit: 64bits
			pr_debug("\n 444_8 bits !");
		}
	}else{
		if(BitNum) {		// 4:2:2 format     10bit
			LineSize = drvif_memory_get_data_align(LineSize*20, 64);
			LineSize = (unsigned int)SHR(LineSize, 6);	// (pixels of per line * 20 / 64), unit: 64bits
			pr_debug("\n 422_10 bits !");
		} else {			// 4:2:2 format     8bit
			LineSize = drvif_memory_get_data_align(LineSize*16, 64);
			LineSize = (unsigned int)SHR(LineSize, 6);	// (pixels of per line * 16 / 64), unit: 64bits
			pr_debug("\n 422_8 bits !");
		}
	}
	pr_debug("memory_get_line_size LineSize=%d\n",LineSize);
	return LineSize;
}


/*============================================================================*/
/**
 * memory_get_capture_size
 * Calculate the memory size of capture. The size is counted by 4:2:2/4:4:4 data format,
 * and frame-access/line access.
 *
 * @param <info> { disp-info structure }
 * @param <AccessType> { Access_Type  }
 * @param <TotalSize> { size of capture }
 * @return { none }
 *
 */
unsigned int memory_get_capture_size(unsigned char display, eMemCapAccessType AccessType)
{
	unsigned int TotalSize;
	unsigned char ddrbit;
	unsigned int capLen = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display, SLR_INPUT_CAP_LEN);
	unsigned int capWid = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_CAP_WID);
	unsigned char channel = Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_CHANNEL);

	pr_debug("10 bit:%d;;422cap:%d\n",(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT)),(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_422CAP)));

	ddrbit =  (channel ? 0 : ((Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT)) << 1 ))  | ( !Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_422CAP));
	TotalSize = memory_get_line_size(capWid, (ddrbit & _BIT0), ((ddrbit & _BIT1) >> 1));
#ifdef CONFIG_I2RND_ENABLE
	//i2rnd sub-cap to VO, line step has to be 2-align @Crixus 20160728
	total_line_size = TotalSize;
#endif
	TotalSize = drvif_memory_get_data_align(TotalSize, 0x04);	// it must be times of 4

	if (AccessType == MEMCAPTYPE_FRAME)
		TotalSize = TotalSize * capLen;	// multiple total_lines if frame-access
	//printk("[Memory-cap]:TotalSize=%x,capWid=%x,10Bit=%d,422=%d\n", TotalSize,capWid,Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT),Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_422CAP));
	pr_debug("[crixus]:TotalSize=%x,capWid=%x,capLen=%x,10Bit=%d,422=%d\n", TotalSize,capWid,capLen,Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT),Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_422CAP));
	return TotalSize;
}

unsigned int memory_get_capture_line_size_compression(unsigned char compression_bits)
{
	unsigned int TotalSize;
	unsigned int capLen = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_LEN);
	unsigned int capWid = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID);

	if((capWid % 32) != 0)
		capWid = capWid + (32 - (capWid % 32));

	TotalSize = drvif_memory_get_data_align((capWid * compression_bits), 64);// (pixels of per line * bits / 64), unit: 64bits
	TotalSize = (unsigned int)SHR(TotalSize, 6);

	//printk(KERN_EMERG"[crixus]memory_get_line_size LineSize=%d\n",TotalSize);

	//TotalSize = memory_get_line_size(capWid, (ddrbit & _BIT0), ((ddrbit & _BIT1) >> 1));
	//TotalSize = drvif_memory_get_data_align(TotalSize, 0x04);	// it must be times of 4
	//printk(KERN_EMERG"[crixus]:TotalSize=%x,capWid=%x,capLen=%x\n", TotalSize,capWid,capLen);
	return TotalSize;
}
#ifndef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
static void memory_check_enough(void)
{
	unsigned int i = 0, sum_size = 0;
	for(i = MEMIDX_VDC ; i<MEMIDX_ALL ; i++) {
		if(MemTag[i].StartAddr != _DUMMYADDR){
			if(i != MEMIDX_DI)	// DI use another memory area, skip check
				sum_size += MemTag[i].Size;
		}
	}

	if(sum_size > (AllocEndAddr-AllocStartAddr)){
		pr_debug("\n Scaler Memory Allocate ERROR!!(Overflow Memory Size),Start =%x,End=%x\n",AllocStartAddr,AllocEndAddr);
		for(i = MEMIDX_VDC ; i<MEMIDX_ALL ; i++) {
			pr_debug("Allocate Index %d, StartAddress = %x, Size=%d\n", i, MemTag[i].StartAddr, MemTag[i].Size);
		}
	}
}


/*============================================================================*/
/**
 * memory_set_mem_tag
 * Set start address and size of a specific memory tag
 *
 * @param <index> { index of memory tag }
 * @param <space> { size }
 * @return { none }
 *
 */
static void memory_set_mem_tag(eMemIdx Idx, unsigned int StartAddr, unsigned int Space)
{
	//unsigned char	*m_pNonCacheStartAddr;
	if(MemTag[Idx].Status == ALLOCATED_FROM_HIGH)
		MemTag[Idx].StartAddr = (StartAddr & ~((1 << _DDR_BITS) - 1));
	else
		MemTag[Idx].StartAddr = drvif_memory_get_data_align(StartAddr, (1 << _DDR_BITS));

	if(MEMIDX_DI == Idx){
		IoReg_Write32(DI_DI1_WRRD_BOUNDARYADDR1_VADDR, (MemTag[Idx].StartAddr & 0x7ffffff0));
#if 1
		//patch for DI/RTNR bug(overwrite 512Byte)
		IoReg_Write32(DI_DI1_WRRD_BOUNDARYADDR2_VADDR, (MemTag[Idx].StartAddr+Space-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
#else
		IoReg_Write32(DI_DI1_WRRD_BOUNDARYADDR2_VADDR, (MemTag[Idx].StartAddr+Space) & 0x7ffffff0);
#endif
	}
	MemTag[Idx].Size = Space;
	//Add below code to check memory allocate not enough check
	memory_check_enough();
}
#endif

/*============================================================================*/
/**
 * drvif_memory_free_block
 * Free memory of the specific tag and insert it to free block information
 *
 * @param <index> { index of DDR memory space, see eMemIdx for details }
 * @return { none }
 *
 */
void drvif_memory_free_block(eMemIdx Idx)
{

	unsigned char i;
#ifdef PLI_FAIL
	return;
#endif

#if 1 // do not free scaler mem for vo smooth toggle
	unsigned char display;
	if (Idx >= MEMIDX_SUB && Idx <= MEMIDX_SUB_THIRD) {
		display = SLR_SUB_DISPLAY;
	} else {
		display = SLR_MAIN_DISPLAY;
	}
	if((Scaler_InputSrcGetType(display) == _SRC_VO)&&(Get_vo_smoothtoggle_changeratio_flag(display)||Get_vo_smoothtoggle_timingchange_flag(display)))
	{
		pr_debug("[smooth toggle]do not free %d memory\n",Idx);
		return;
	}
#endif

#ifdef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
	if ( (Idx>=MEMIDX_VDC) && (Idx<MEMIDX_ALL) ) {
		if(Idx == MEMIDX_DI){
			// Close IP enable
			di_im_di_control_RBUS im_di_control_reg;
			im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
			im_di_control_reg.ip_enable= 0;
			im_di_control_reg.write_enable_8 = 1;
			IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);

			//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, 0);

#ifndef ENABLE_SMOOTH_TOGGLE_PR3D
			//IoReg_ClearBits(BUS_TV_SB2_DCU1_ARB_CR1_VADDR, _BIT0);
			// avoid DC_SYS2 client separate enable fail issue due to DI send zero write command to bus
			drv_memory_disable_di_write_req(TRUE);
#endif
		}else if(Idx == MEMIDX_MAIN){
			//disable main Mdomain cature
			IoReg_ClearBits(MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);
#if 0 //frank@0903 reduce scaler time
			//frank@0503 add below delay to confirm M capture have disable
			msleep(20);
#endif
		}else if(Idx == MEMIDX_SUB){
			//disable sub Mdomain cature
			//Crixus@20140722 - Mac3 no in2
			//IoReg_ClearBits(MDOMAIN_CAP_Cap_In2_enable_reg, _BIT0);
#if 0 //frank@0903 reduce scaler time
			//frank@0503 add below delay to confirm M capture have disable
			msleep(20);
#endif
		}

		if(MemTag[Idx].StartAddr != _DUMMYADDR){
			#if 0
			if((MemTag[Idx].StartAddr >= FBOUS_ADDRESS_LOW)&&(MemTag[Idx].StartAddr <= FBOUS_ADDRESS_HIGH)){//FBUS region
				if(MemTag[Idx].Allocate_StartAddr != 0)
					pli_freeOverlappedMemory(MemTag[Idx].Allocate_StartAddr);
			}else{
				if(MemTag[Idx].Allocate_StartAddr != 0)
					pli_freeContinuousMemory((BYTE *)MemTag[Idx].Allocate_StartAddr);
			}
			#else

			if(Idx == MEMIDX_DI){
//DI,RTNR use reserved memory, no need to free memory @Crixus 20170505
#ifndef CONFIG_MDOMAIN_RESERVED_MEMORY
					if(MemTag[Idx].Allocate_StartAddr != 0)
						free_overlapped_memory((unsigned long)MemTag[Idx].Allocate_StartAddr);
#endif
			}else{
				if((MemTag[Idx].Allocate_StartAddr != 0) && (MemTag[Idx].Allocate_VirAddr != 0))
					dvr_free((void *)MemTag[Idx].Allocate_VirAddr);
			}

			#endif
			pr_debug("[SCALER]FREE address %x\n",MemTag[Idx].Allocate_StartAddr);
			MemTag[Idx].Allocate_StartAddr = 0;
			MemTag[Idx].StartAddr = _DUMMYADDR;
			MemTag[Idx].Size = 0;
			MemTag[Idx].Status = UNDEFINED;
			MemTag[Idx].Allocate_VirAddr = 0;
		}
	} else if ( Idx == MEMIDX_ALL ) {
		for ( i=MEMIDX_VDC ; i<MEMIDX_ALL ; ++i ) {	// clear all tag information
			if(i == MEMIDX_DI){
				// Close IP enable
				di_im_di_control_RBUS im_di_control_reg;
				im_di_control_reg.regValue = IoReg_Read32(DI_IM_DI_CONTROL_reg);
				im_di_control_reg.ip_enable= 0;
				im_di_control_reg.write_enable_8 = 1;
				IoReg_Write32(DI_IM_DI_CONTROL_reg, im_di_control_reg.regValue);

				//IoReg_Mask32(DI_IM_DI_CONTROL_reg, ~_BIT28, 0);
#ifndef ENABLE_SMOOTH_TOGGLE_PR3D
				//IoReg_ClearBits(BUS_TV_SB2_DCU1_ARB_CR1_VADDR, _BIT0);
				// avoid DC_SYS2 client separate enable fail issue due to DI send zero write command to bus
				drv_memory_disable_di_write_req(TRUE);
#endif
			}else if(i == MEMIDX_MAIN){
				//disable main Mdomain cature
				IoReg_ClearBits(MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);
			}else if(i == MEMIDX_SUB){
				//disable sub Mdomain cature
				//Crixus@20140722 - Mac3 no in2
				//IoReg_ClearBits(MDOMAIN_CAP_Cap_In2_enable_reg, _BIT0);
			}

			if(MemTag[i].StartAddr != _DUMMYADDR){
				#if 0
				if((MemTag[Idx].StartAddr >= FBOUS_ADDRESS_LOW)&&(MemTag[Idx].StartAddr <= FBOUS_ADDRESS_HIGH)){//FBUS region
					if(MemTag[Idx].Allocate_StartAddr != 0)
						pli_freeOverlappedMemory(MemTag[Idx].Allocate_StartAddr);
				}else{
					if(MemTag[Idx].Allocate_StartAddr != 0)
						pli_freeContinuousMemory((BYTE *)MemTag[Idx].Allocate_StartAddr);
				}
				#else
				if((MemTag[i].Allocate_StartAddr != 0) && (MemTag[i].Allocate_VirAddr != 0))
					dvr_free((void *)MemTag[i].Allocate_VirAddr);
				#endif
				pr_debug("[SCALER]FREE address %x\n",MemTag[i].Allocate_StartAddr);
				MemTag[i].Allocate_StartAddr = 0;
				MemTag[i].StartAddr = _DUMMYADDR;
				MemTag[i].Size = 0;
				MemTag[i].Status = UNDEFINED;
				MemTag[i].Allocate_VirAddr = 0;
			}
		}
	}
#else
	if ( (Idx>=MEMIDX_VDC) && (Idx<MEMIDX_ALL) ) {
		MemTag[Idx].StartAddr = _DUMMYADDR;
		MemTag[Idx].Size = 0;
		MemTag[Idx].Status = UNDEFINED;
	} else if ( Idx == MEMIDX_ALL ) {
		for ( i=MEMIDX_VDC ; i<MEMIDX_ALL ; ++i ) {	// clear all tag information
			MemTag[i].StartAddr = _DUMMYADDR;
			MemTag[i].Size = 0;
			MemTag[i].Status = UNDEFINED;
		}
	}
#endif
}

/*============================================================================*/
/**
 * MemGetBlockAddr
 * Get start address of allocated memory
 *
 * @param <index> { index of DDR memory space, see eMemIdx for details }
 * @return { none }
 *
 */
unsigned int drvif_memory_get_block_addr(eMemIdx Idx)
{
	return MemTag[Idx].StartAddr;
}

/*============================================================================*/
/**
 * drvif_memory_get_block_size
 * Get size of allocated memory
 *
 * @param <index> { index of DDR memory space, see eMemIdx for details }
 * @return { block size }
 *
 */
unsigned int drvif_memory_get_block_size(eMemIdx Idx)
{
	return MemTag[Idx].Size;
}


unsigned int drvif_memory_get_mainblock_viraddr(void)
{
#if 0
	unsigned int virstaaddr = 0;
	unsigned int phystaaddr = 0;
	if(MemTag[MEMIDX_MAIN_THIRD].Allocate_VirAddr !=0) {
		virstaaddr = MemTag[MEMIDX_MAIN_THIRD].Allocate_VirAddr;
		phystaaddr = MemTag[MEMIDX_MAIN_THIRD].StartAddr;
	} else if (MemTag[MEMIDX_MAIN_SEC].Allocate_VirAddr !=0) {
		virstaaddr = MemTag[MEMIDX_MAIN_SEC].Allocate_VirAddr;
		phystaaddr = MemTag[MEMIDX_MAIN_SEC].StartAddr;
	} else if (MemTag[MEMIDX_MAIN].Allocate_VirAddr !=0) {
		virstaaddr = MemTag[MEMIDX_MAIN].Allocate_VirAddr;
		phystaaddr = MemTag[MEMIDX_MAIN].StartAddr;
	}

	return (virstaaddr + MemTag[MEMIDX_MAIN].StartAddr - phystaaddr);
#else
	return MemTag[MEMIDX_MAIN_THIRD].Allocate_VirAddr;
#endif
}

unsigned int drvif_memory_get_subblock_viraddr(void)
{
#if 0
	unsigned int virstaaddr = 0;
	unsigned int phystaaddr = 0;
	if(MemTag[MEMIDX_SUB_THIRD].Allocate_VirAddr !=0) {
		virstaaddr = MemTag[MEMIDX_SUB_THIRD].Allocate_VirAddr;
		phystaaddr = MemTag[MEMIDX_SUB_THIRD].StartAddr;
	} else if (MemTag[MEMIDX_SUB_SEC].Allocate_VirAddr !=0) {
		virstaaddr = MemTag[MEMIDX_SUB_SEC].Allocate_VirAddr;
		phystaaddr = MemTag[MEMIDX_SUB_SEC].StartAddr;
	} else if (MemTag[MEMIDX_SUB].Allocate_VirAddr !=0) {
		virstaaddr = MemTag[MEMIDX_SUB].Allocate_VirAddr;
		phystaaddr = MemTag[MEMIDX_SUB].StartAddr;
	}

	return (virstaaddr + MemTag[MEMIDX_SUB].StartAddr - phystaaddr);
#else
	return MemTag[MEMIDX_SUB_THIRD].Allocate_VirAddr;
#endif
}

/*============================================================================*/
/**
 * MemAlignBank
 * Memory alignment for DDR bank0
 *
 * @param <index> { index of DDR memory space, see eMemIdx for details }
 * @return { none }
 *
 */
unsigned int drvif_memory_alignbank(unsigned int StartAddr, unsigned char AlignBank, unsigned char Frm)
{
	unsigned int getValue;
	//ScalerMemory_Printf(" 1. Start Addr = %x in Memory_AlignBank\n",StartAddr);
	if(AlignBank < MEMALIGN_ANY){
		getValue = (StartAddr & ((1 << CONFIG_DDR_BANK_BITS) - 1) << (CONFIG_DDR_COL_BITS+1)) >> (CONFIG_DDR_COL_BITS+1);
		getValue = getValue % (1 << CONFIG_DDR_BANK_BITS);
		if(Frm == ALLOCATED_FROM_LOW) {
			getValue = (1 << CONFIG_DDR_BANK_BITS) - getValue + AlignBank;

			StartAddr += (getValue * (1 << (CONFIG_DDR_COL_BITS+1)));
			//ScalerMemory_Printf(" 2. L.Start Addr = %x getValue = %x in Memory_AlignBank\n",StartAddr,getValue);
		}
		else if(Frm == ALLOCATED_FROM_HIGH) {
			if(getValue > AlignBank)
				getValue -= AlignBank;
			else
				getValue = AlignBank - getValue;

			StartAddr -= (getValue * (1 << (CONFIG_DDR_COL_BITS+1)));
			//ScalerMemory_Printf(" 2. H.Start Addr = %x getValue = %x in Memory_AlignBank\n",StartAddr,getValue);
		}
	}

	return StartAddr;
}

//mac5p start to use query driver to get memory and address @Crixus 20170504
/*
	M-domain main 3-buffer, sub 2-buffer (15M) and DI (17M)
	=>total 32M
*/
unsigned int get_query_start_address(unsigned char idx){
	unsigned int addr = 0 ;
	unsigned int size = 0 ;
 	unsigned int buffer_size = 0;

	//if(Get_Live_zoom_mode() != LIVE_ZOOM_OFF )/*livezoom main m domain could not open compress mode*/
		//buffer_size = MDOMAIN_MAIN_BUFFER_SIZE_16BITS;
	//else
		buffer_size = MDOMAIN_MAIN_BUFFER_SIZE_16BITS;

 	size = (unsigned int)carvedout_buf_query(CARVEDOUT_SCALER_MDOMAIN, &addr) ;

 	printk(KERN_EMERG"[%s]reserved memory start addr = 0x%x, size = 0x%x, MDOMAIN_MAIN_BUFFER_SIZE = 0x%x\n", __FUNCTION__, addr, size, MDOMAIN_MAIN_BUFFER_SIZE);
	printk(KERN_EMERG"[%s]VIP_DI_1_BUFFER_SIZE = 0x%x, VIP_DI_2_BUFFER_SIZE = 0x%x, VIP_DMAto3DTable_BUFFER_SIZE = 0x%x\n", __FUNCTION__, VIP_DI_1_BUFFER_SIZE, VIP_DI_2_BUFFER_SIZE, VIP_DMAto3DTable_BUFFER_SIZE);

	//double check reserved include M-domain + DI size.
 	//if(size < (buffer_size * 5 + VIP_DI_1_BUFFER_SIZE + VIP_DI_2_BUFFER_SIZE + VIP_DMAto3DTable_BUFFER_SIZE)){
	if(size == 0){
		BUG();
 	}

	if(idx == QUERY_IDX_MDOMAIN_MAIN){
  		//do nothing
 	}
	/*else if(idx == QUERY_IDX_DI){
  		addr = addr + buffer_size * 3;
 	}*/
	else if(idx == QUERY_IDX_MDOMAIN_SUB){
  		addr = addr + buffer_size * 3 + VIP_DI_1_BUFFER_SIZE + VIP_DMAto3DTable_BUFFER_SIZE;
 	}
	/*else if(idx == QUERY_IDX_DI_2){
  		addr = addr + buffer_size * 5 + VIP_DI_1_BUFFER_SIZE + VIP_DMAto3DTable_BUFFER_SIZE;
 	} else if (idx == QUERY_IDX_VIP_DMAto3DTABLE) {
		addr = addr + buffer_size * 3 + VIP_DI_1_BUFFER_SIZE;
 	}*/

	printk(KERN_EMERG"[%s]idx = %d, addr = 0x%x\n", __FUNCTION__, idx, addr);
	return addr;
}

unsigned int drv_memory_get_VIP_query_start_address(unsigned char idx)
{
	unsigned int addr = 0, base_addr = 0 ;
	unsigned int size = 0 ;
	unsigned int buffer_size = 0;

	size = (unsigned int)carvedout_buf_query(CARVEDOUT_SCALER_VIP, &base_addr) ;

	if(size == 0){
		BUG();
 	}

	/* only DI */
	if (idx == VIP_QUERY_IDX_DI) {
		addr = base_addr;
	} else if (idx == VIP_QUERY_IDX_DI)  {
		addr = base_addr + VIP_DI_1_BUFFER_SIZE;
	} else if (idx == VIP_QUERY_IDX_DMA) {
		addr = base_addr + VIP_DI_1_BUFFER_SIZE + VIP_DI_2_BUFFER_SIZE;
	} else {
		addr = 0;
		rtd_printk(KERN_EMERG, TAG_NAME, "VIP query memory, index error, index=%d\n", idx);
	}

	rtd_printk(KERN_INFO, TAG_NAME, "VIP query memory, addr=%x, size=%d, index=%d\n", addr, size, idx);
	return addr;
}


/*============================================================================*/
/**
 * drvif_memory_alloc_block
 * allocate memory of the specific tag
 *
 * @param <index> { index of DDR memory space, see eMemIdx for details }
  * @param <space> { size of DDR memory space,uint:byte}
 * @return { start address of the allocated memory }
 *
 * @Note:
 *  You must drvif_memory_free_block to free block you allocated before calling this function to allocate memory space.
 *  It possible wrong operatoin if you don't observer the front.
 */
//extern unsigned char Get_zoom_smoothtoggle_changeratio_flag(void);
unsigned int drvif_memory_alloc_block(eMemIdx Idx, unsigned int space, unsigned char Align)
{
	unsigned int m_allocate_memory = 0;

#if 1 // do not allocate scaler mem again for vo smooth toggle
	unsigned char display;
	if (Idx >= MEMIDX_SUB && Idx <= MEMIDX_SUB_THIRD) {
		display = SLR_SUB_DISPLAY;
	} else {
		display = SLR_MAIN_DISPLAY;
	}
	if((Get_vo_smoothtoggle_changeratio_flag(display)||Get_vo_smoothtoggle_timingchange_flag(display)))
	{
		if(MemTag[Idx].StartAddr!=_DUMMYADDR)
		{
			pr_debug("[smooth toggle]do not alloc %d memory:%x\n",Idx,MemTag[Idx].StartAddr);
			return MemTag[Idx].StartAddr;
		}
		else
		{
			if(Idx==MEMIDX_MAIN_THIRD)
			{
				if((MemTag[MEMIDX_MAIN_SEC].StartAddr!=_DUMMYADDR)||(MemTag[MEMIDX_MAIN].StartAddr!=_DUMMYADDR))
				{
				     pr_debug("[smooth toggle]MEMIDX_MAIN_THIRD do not alloc memory\n");
				     return MemTag[Idx].StartAddr;
				}
			} else {
				if(!Get_vo_smoothtoggle_timingchange_flag(display)) {
					pr_debug("[change ratio smooth toggle]%d do not alloc memory:%x\n",Idx,MemTag[Idx].StartAddr);
					//memory protection @Crixus 20160101
					if((MemTag[Idx].StartAddr != 0x0) && (MemTag[Idx].StartAddr != 0xffffffff))
						return MemTag[Idx].StartAddr;
				}
		   }
		}
	}
#endif

#if 0
	if(Get_zoom_smoothtoggle_changeratio_flag())
	{// do not allocate DI mem again rika 20140829
		pr_info("_rk [MEM] Idx[%d]=%x\n", Idx, MemTag[Idx].StartAddr);
		return MemTag[Idx].StartAddr;
	}
#endif

//	static unsigned int dcu2_address = 0;
#ifndef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
	if(AllocStartAddr == 0)
		return _DUMMYADDR;
#endif
	//unsigned int StartAddr;
	if((Idx >= MEMIDX_VDC) && (Idx < MEMIDX_ALL)) {
#ifdef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY

			if(MEMIDX_MAIN_THIRD == Idx){
				space = space*3+CONFIG_MDOMAIN_BURST_SIZE;
			}else if(MEMIDX_MAIN_SEC == Idx){
				if(MemTag[MEMIDX_MAIN_THIRD].StartAddr != _DUMMYADDR){ //triple buffer case
					MemTag[Idx].Allocate_StartAddr = 0;
					MemTag[Idx].Size = space;
					MemTag[Idx].Status = MemTag[MEMIDX_MAIN_THIRD].Status;
					MemTag[Idx].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_THIRD].StartAddr+space, (1 << 5));
					MemTag[MEMIDX_MAIN_THIRD].Size -= space;
					pr_debug("[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);
					return MemTag[Idx].StartAddr;
				}else{ //double buffer case
					space = space*2+CONFIG_MDOMAIN_BURST_SIZE;
				}
			}else if(MEMIDX_MAIN == Idx){
				if(MemTag[MEMIDX_MAIN_THIRD].StartAddr != _DUMMYADDR){ //triple buffer case
					MemTag[Idx].Allocate_StartAddr = 0;
					MemTag[Idx].Size = space;
					MemTag[Idx].Status = MemTag[MEMIDX_MAIN_THIRD].Status;
					MemTag[Idx].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_THIRD].StartAddr+space*2, (1 << 5));
					MemTag[MEMIDX_MAIN_THIRD].Size -= space;
					pr_debug("[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);
					return MemTag[Idx].StartAddr;
				}else if(MemTag[MEMIDX_MAIN_SEC].StartAddr != _DUMMYADDR){//double buffer case
					MemTag[Idx].Allocate_StartAddr = 0;
					MemTag[Idx].Size = space;
					MemTag[Idx].Status = MemTag[MEMIDX_MAIN_SEC].Status;
					MemTag[Idx].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_SEC].StartAddr+space, (1 << 5));
					MemTag[MEMIDX_MAIN_SEC].Size -= space;
					pr_debug("[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);
					return MemTag[Idx].StartAddr;
				}else{
					space = space+CONFIG_MDOMAIN_BURST_SIZE;
				}
			}else if(MEMIDX_SUB_THIRD == Idx){
				space = space*3+CONFIG_MDOMAIN_BURST_SIZE;
			}else if(MEMIDX_SUB_SEC == Idx){
				if(MemTag[MEMIDX_SUB_THIRD].StartAddr != _DUMMYADDR){ //triple buffer case
					MemTag[Idx].Allocate_StartAddr = 0;
					MemTag[Idx].Size = space;
					MemTag[Idx].Status = MemTag[MEMIDX_SUB_THIRD].Status;
					MemTag[Idx].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_SUB_THIRD].StartAddr+space, (1 << 5));
					MemTag[MEMIDX_SUB_THIRD].Size -= space;
					pr_debug("[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);
					return MemTag[Idx].StartAddr;
				}else{ //double buffer case
					space = space*2+CONFIG_MDOMAIN_BURST_SIZE;
				}
			}else if(MEMIDX_SUB == Idx){
				if(MemTag[MEMIDX_SUB_THIRD].StartAddr != _DUMMYADDR){ //triple buffer case
					MemTag[Idx].Allocate_StartAddr = 0;
					MemTag[Idx].Size = space;
					MemTag[Idx].Status = MemTag[MEMIDX_SUB_THIRD].Status;
					MemTag[Idx].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_SUB_THIRD].StartAddr+space*2, (1 << 5));
					MemTag[MEMIDX_SUB_THIRD].Size -= space;
					pr_debug("[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);
					return MemTag[Idx].StartAddr;
				}else if(MemTag[MEMIDX_SUB_SEC].StartAddr != _DUMMYADDR){//double buffer case
					MemTag[Idx].Allocate_StartAddr = 0;
					MemTag[Idx].Size = space;
					MemTag[Idx].Status = MemTag[MEMIDX_SUB_SEC].Status;
					MemTag[Idx].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_SUB_SEC].StartAddr+space, (1 << 5));
					MemTag[MEMIDX_SUB_SEC].Size -= space;
					pr_debug("[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);
					return MemTag[Idx].StartAddr;
				}else{
					space = space+CONFIG_MDOMAIN_BURST_SIZE;
				}
			}

		if(MEMIDX_MAIN_2_THIRD == Idx){
			space = space*3+CONFIG_MDOMAIN_BURST_SIZE;
		}else if(MEMIDX_MAIN_2_SEC == Idx){
			if(MemTag[MEMIDX_MAIN_2_THIRD].StartAddr != _DUMMYADDR){ //triple buffer case
				MemTag[Idx].Allocate_StartAddr = 0;
				MemTag[Idx].Size = space;
				MemTag[Idx].Status = MemTag[MEMIDX_MAIN_2_THIRD].Status;
				MemTag[Idx].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_2_THIRD].StartAddr+space, (1 << 5));
				MemTag[MEMIDX_MAIN_2_THIRD].Size -= space;
				pr_debug("[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);
				return MemTag[Idx].StartAddr;
			}else{ //double buffer case
				space = space*2+CONFIG_MDOMAIN_BURST_SIZE;
			}
		}else if(MEMIDX_MAIN_2 == Idx){
			if(MemTag[MEMIDX_MAIN_2_THIRD].StartAddr != _DUMMYADDR){ //triple buffer case
				MemTag[Idx].Allocate_StartAddr = 0;
				MemTag[Idx].Size = space;
				MemTag[Idx].Status = MemTag[MEMIDX_MAIN_2_THIRD].Status;
				MemTag[Idx].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_2_THIRD].StartAddr+space*2, (1 << 5));
				MemTag[MEMIDX_MAIN_2_THIRD].Size -= space;
				pr_debug("[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);
				return MemTag[Idx].StartAddr;
			}else if(MemTag[MEMIDX_MAIN_SEC].StartAddr != _DUMMYADDR){//double buffer case
				MemTag[Idx].Allocate_StartAddr = 0;
				MemTag[Idx].Size = space;
				MemTag[Idx].Status = MemTag[MEMIDX_MAIN_SEC].Status;
				MemTag[Idx].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_SEC].StartAddr+space, (1 << 5));
				MemTag[MEMIDX_MAIN_SEC].Size -= space;
				pr_debug("[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);
				return MemTag[Idx].StartAddr;
			}else{
				space = space+CONFIG_MDOMAIN_BURST_SIZE;
			}
		}


		// Pli Fail
#ifdef PLI_FAIL
		if(Idx ==MEMIDX_MAIN || Idx ==MEMIDX_MAIN_SEC || Idx ==MEMIDX_MAIN_THIRD)
		{
			m_allocate_memory = 0x1d000000;
		}
		else if (Idx == MEMIDX_VDC)
		{
			m_allocate_memory = 0x1c000000;
		}
		else if (Idx == MEMIDX_DI)
		{
			m_allocate_memory = 0x1e000000;
		}
		else
		{
			pr_debug("Error, can't handle reserverd memory, mem Idx=%d\n", Idx);
		}
#else
		//m_allocate_memory = pli_allocOverlappedMemory(space + (1 << 5));
#endif
#if 0
		if(m_allocate_memory == 0){
			unsigned char				*m_pNonCacheStartAddr;
			pr_debug("Allocate RBUS index %d memory fail,allocate by pli\n",Idx);
			#if 0//qiang_zhou:fixme memory alloc
			m_pCacheStartAddr = (BYTE *)pli_allocContinuousMemorySpecific((space + (1 << 5)), (char**)&m_pNonCacheStartAddr, &m_PhyStartAddr, GFP_DCU1);
			#endif
			if(m_pCacheStartAddr == NULL){
				pr_debug("[ERROR]Allocate DCU1 size=%x fail\n",(space + (1 << 5)));
				return FALSE;
			}else{
				pr_debug("[SCALER]PLI Allocate address %x\n",m_PhyStartAddr);
				MemTag[Idx].Allocate_StartAddr = (unsigned int)m_pCacheStartAddr;
				MemTag[Idx].Size = space;
				MemTag[Idx].Status = ALLOCATED_FROM_PLI;
				MemTag[Idx].StartAddr = drvif_memory_get_data_align(m_PhyStartAddr, (1 << 5));
			}
		}else{
			pr_debug("[SCALER]Allocate address %x - %x\n",m_allocate_memory, (m_allocate_memory+space + (1 << 5)));
			MemTag[Idx].Allocate_StartAddr = m_allocate_memory;
			MemTag[Idx].Size = space;
			MemTag[Idx].Status = ALLOCATED_FROM_PLI;
			MemTag[Idx].StartAddr = drvif_memory_get_data_align(m_allocate_memory, (1 << 5));
		}
#else

		if(MEMIDX_DI == Idx){//DI, RTNR allocate memory by overlap memory @Crixus 20151122
#ifdef CONFIG_I2RND_ENABLE
			if(Scaler_I2rnd_get_enable() == _ENABLE){
				m_allocate_memory = drv_memory_get_VIP_query_start_address(VIP_QUERY_IDX_DI);;//in VO case, use reserved memory
				//printk(KERN_EMERG"[crixus]DI main memory address = %x\n", m_allocate_memory);
			}
			else{
#endif
				//change to use query driver @Crixus 20170505
				m_allocate_memory = drv_memory_get_VIP_query_start_address(VIP_QUERY_IDX_DI);
				//printk(KERN_EMERG"[crixus]DI non-i2rnd memory address = %x, space = %x\n", m_allocate_memory, space);
#ifdef CONFIG_I2RND_ENABLE
			}
#endif
		}
#ifdef CONFIG_I2RND_ENABLE
		else if(MEMIDX_DI_2 == Idx){
			m_allocate_memory = drv_memory_get_VIP_query_start_address(VIP_QUERY_IDX_DI_2);//DI_START_ADDRESS_KERNEL + DI_BUFFER_SIZE_VO;
			printk(KERN_EMERG"[crixus]DI sub memory address = %x\n", m_allocate_memory);

		}
#endif
		else{//M-domain allocate memory by DCU2
			m_pCacheStartAddr = (unsigned char *)dvr_malloc_specific((space + (1 << 5)), GFP_DCU2_FIRST);
			if(m_pCacheStartAddr == NULL){
				pr_notice("[ERROR]Allocate DCU1 size=%x fail\n",(space + (1 << 5)));
				BUG();//add kernel crash function when cma not enough
				return FALSE;
			}
			m_allocate_memory = (unsigned int)dvr_to_phys((void*)m_pCacheStartAddr);
		}

		pr_emerg("[SCALER]Allocate address %x - %x\n",m_allocate_memory, (m_allocate_memory+space + (1 << 5)));
		MemTag[Idx].Allocate_StartAddr = m_allocate_memory;
		MemTag[Idx].Size = space;
		MemTag[Idx].Status = ALLOCATED_FROM_PLI;
		MemTag[Idx].StartAddr = drvif_memory_get_data_align(m_allocate_memory, (1 << 5));
		MemTag[Idx].Allocate_VirAddr = (unsigned int)m_pCacheStartAddr;
#endif

		//printk(KERN_EMERG"[crixus]MemTag[Idx].StartAddr = %x\n", MemTag[Idx].StartAddr);
		//printk(KERN_EMERG"[crixus]DI_MULTIVIEW_ADDRESS_SUB = %x\n", DI_MULTIVIEW_ADDRESS_SUB);
		//printk(KERN_EMERG"[crixus](DI_MULTIVIEW_ADDRESS_SUB + space - CONFIG_MDOMAIN_BURST_SIZE) = %x\n", (DI_MULTIVIEW_ADDRESS_SUB + space - CONFIG_MDOMAIN_BURST_SIZE));
		//printk(KERN_EMERG"[crixus]space = %x\n", space);

		if(MEMIDX_DI == Idx){
			//IoReg_Write32(DI_DI1_WRRD_BoundaryAddr1_reg, (MemTag[Idx].StartAddr & 0x7ffffff0));	/* set boundary in boot ini and resume*/
			//patch for DI/RTNR bug(overwrite 512Byte)
			//IoReg_Write32(DI_DI1_WRRD_BoundaryAddr2_reg, ((MemTag[Idx].StartAddr+space-CONFIG_MDOMAIN_BURST_SIZE)) & 0x7ffffff0);
#ifdef CONFIG_I2RND_ENABLE
		}else if(MEMIDX_DI_2 == Idx){
			//IoReg_Write32(DI_DI1_WRRD_BoundaryAddr1_reg, (MemTag[MEMIDX_DI_2].StartAddr & 0x7ffffff0));
			//IoReg_Write32(DI_DI1_WRRD_BoundaryAddr2_reg, ((MemTag[MEMIDX_DI_2].StartAddr + space - CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0));
#endif
		}else if(MEMIDX_MAIN_THIRD == Idx){
			IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,(MemTag[MEMIDX_MAIN_THIRD].StartAddr & 0x7ffffff0));
			IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,(MemTag[MEMIDX_MAIN_THIRD].StartAddr+space-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
		}else if(MEMIDX_MAIN_SEC == Idx ){
			IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,(MemTag[MEMIDX_MAIN_SEC].StartAddr & 0x7ffffff0));
			IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,(MemTag[MEMIDX_MAIN_SEC].StartAddr+space-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
		}else if(MEMIDX_MAIN == Idx){
			IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,(MemTag[MEMIDX_MAIN].StartAddr & 0x7ffffff0));
			IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,(MemTag[MEMIDX_MAIN].StartAddr+space-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
		}else if(MEMIDX_SUB_THIRD == Idx){
			IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr1_reg,(MemTag[MEMIDX_SUB_THIRD].StartAddr & 0x7ffffff0));
			IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg,(MemTag[MEMIDX_SUB_THIRD].StartAddr+space-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
		}else if(MEMIDX_SUB_SEC == Idx){
			IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr1_reg,(MemTag[MEMIDX_SUB_SEC].StartAddr & 0x7ffffff0));
			IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg,(MemTag[MEMIDX_SUB_SEC].StartAddr+space-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
		}else if(MEMIDX_SUB == Idx){
			IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr1_reg,(MemTag[MEMIDX_SUB].StartAddr & 0x7ffffff0));
			IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg,(MemTag[MEMIDX_SUB].StartAddr+space-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
		}
#else
		if((MemTag[Idx].StartAddr != _DUMMYADDR) && (Idx != MEMIDX_VDC)) {
			if(space <= MemTag[Idx].Size) {
				return MemTag[Idx].StartAddr;
			} else {
				memory_set_mem_tag(Idx, _DUMMYADDR, 0);
				return _DUMMYADDR;
			}
		}
		space = drvif_memory_get_data_align(space, (1 << _DDR_BITS));
		switch(Idx) {
			case MEMIDX_VDC:
				if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) {
					MemTag[Idx].Status = ALLOCATED_FROM_LOW;
					memory_set_mem_tag(Idx, AllocStartAddr, space);
				} else {
					MemTag[Idx].Status = ALLOCATED_FROM_HIGH;
					memory_set_mem_tag(Idx, AllocEndAddr - space + 1, space);  // add a bank gap avoid Main sec Blk cover Bitmap
				}
				break;

			case MEMIDX_TT:
				if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) {
					MemTag[Idx].Status = ALLOCATED_FROM_LOW;
					if(MemTag[MEMIDX_VDC].Status == ALLOCATED_FROM_LOW) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_VDC].StartAddr + MemTag[MEMIDX_VDC].Size, space + (1 << _DDR_BITS));
					} else {
						memory_set_mem_tag(Idx, AllocStartAddr, space + (1 << _DDR_BITS));
					}
				} else {
					MemTag[Idx].Status = ALLOCATED_FROM_HIGH;
					if(MemTag[MEMIDX_VDC].Status ==  ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_VDC].StartAddr - space + 1, space);
					} else {
						memory_set_mem_tag(Idx, AllocEndAddr - space + 1, space);
					}
				}
				break;

			case MEMIDX_JPEG:
				if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) {
					MemTag[Idx].Status = ALLOCATED_FROM_LOW;
					memory_set_mem_tag(Idx, AllocStartAddr, space);
				} else {
					MemTag[Idx].Status = ALLOCATED_FROM_HIGH;
					memory_set_mem_tag(Idx, AllocEndAddr - space + 1, space);  // add a bank gap avoid Main sec Blk cover Bitmap
				}
				break;


			case MEMIDX_DI:
				if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) {
					MemTag[Idx].Status = ALLOCATED_FROM_LOW;

					if(MemTag[MEMIDX_TT].Status ==  ALLOCATED_FROM_LOW) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_TT].StartAddr + MemTag[MEMIDX_TT].Size, space + (1 << _DDR_BITS));
					}
					else if(MemTag[MEMIDX_VDC].Status ==  ALLOCATED_FROM_LOW) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_VDC].StartAddr + MemTag[MEMIDX_VDC].Size, space + (1 << _DDR_BITS));
					}
					else if(MemTag[MEMIDX_JPEG].Status == ALLOCATED_FROM_LOW) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_JPEG].StartAddr + MemTag[MEMIDX_JPEG].Size, space + (1 << _DDR_BITS));
					}
					else
					{
						memory_set_mem_tag(Idx, AllocStartAddr, space + (1 << _DDR_BITS));
					}
				} else {
					MemTag[Idx].Status = ALLOCATED_FROM_HIGH;
					if(MemTag[MEMIDX_TT].Status ==  ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_TT].StartAddr - space + 1, space);
					}else if(MemTag[MEMIDX_VDC].Status ==  ALLOCATED_FROM_HIGH) {
							//memory_set_mem_tag(Idx, MemTag[MEMIDX_VDC].StartAddr - MemTag[MEMIDX_VDC].Size + 1, space);
							//////////////////////////////////
							//By Gilbert(2008/9/23)
							///////////////////////////////////
							memory_set_mem_tag(Idx, MemTag[MEMIDX_VDC].StartAddr - space + 1, space);
					}else if  (MemTag[MEMIDX_JPEG].Status ==  ALLOCATED_FROM_HIGH) {
							memory_set_mem_tag(Idx, MemTag[MEMIDX_JPEG].StartAddr - space + 1, space);
					} else {
							pr_debug("[qiang_zhou debug]:MemTag[MEMIDX_DI].Status==%d\n",MemTag[MEMIDX_DI].Status);
							memory_set_mem_tag(Idx, AllocEndAddr - space + 1, space);
					}
				}
				break;

			case MEMIDX_MAIN:
				MemTag[Idx].Status = ALLOCATED_FROM_HIGH;
				if(MemTag[MEMIDX_MAIN_SEC].StartAddr != _DUMMYADDR) {
					if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) > 2048)
						&& (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 1200)&& !Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_422CAP)){	// 4k2k
						// [IDMA] IDMA capture buffer share memory with video decoder
						SCALERDRV_ALLOCBUFFER_INFO stAllocBufferInfo_idma;
						if(drvif_scaler_getValidMemInfo_fromVideo(&stAllocBufferInfo_idma) < 0){
							//unsigned char				*m_pNonCacheStartAddr;
							pr_debug("[IDMA_M domain] fail to get memory information\n");
							#if 0//qiang_zhou:fixme memory alloc
							m_pCacheStartAddr = (BYTE *)pli_allocContinuousMemorySpecific(space, (char**)&m_pNonCacheStartAddr, &m_PhyStartAddr, GFP_DCU1);
							#else
							m_pCacheStartAddr=dvr_malloc(space);
							//m_PhyStartAddr = (unsigned int)virt_to_phys((void*)m_pCacheStartAddr);
							m_PhyStartAddr = (unsigned int)dvr_to_phys((void*)m_pCacheStartAddr);
							#endif
							if(m_pCacheStartAddr == NULL){
								pr_debug("[ERROR]Allocate M domain DCU1 size=%x fail\n",mMallocSize);
								return FALSE;
							}else{
								//physical address
								MemTag[Idx].StartAddr = m_PhyStartAddr;
								MemTag[Idx].Size = space;
								pr_debug("[SLR_MEMORY5][PLI][Cache:%x][Phy:%x][Size:%x]\n", (unsigned int)m_pCacheStartAddr, (unsigned int)m_PhyStartAddr, space);

							}
						}else{
							MemTag[Idx].StartAddr = stAllocBufferInfo_idma.normal_mem_addr&0x7fffffff;
							MemTag[Idx].Size = space;
							pr_debug("[IDMA_M domain] get memory information OK,addr=%x\n",MemTag[Idx].StartAddr);
						}

						if(MemTag[Idx].StartAddr < AllocStartAddr){
							IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg, MemTag[Idx].StartAddr);
						}else if(MemTag[Idx].StartAddr > AllocEndAddr){
							IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,MemTag[Idx].StartAddr+space-CONFIG_MDOMAIN_BURST_SIZE);
						}
					}else{
					memory_set_mem_tag(Idx, MemTag[MEMIDX_MAIN_SEC].StartAddr  - space + 1, space);
					}
				} else {

					if(MemTag[MEMIDX_DI].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_DI].StartAddr - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					} else if(MemTag[MEMIDX_TT].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_TT].StartAddr  - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					} else if(MemTag[MEMIDX_VDC].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_VDC].StartAddr  - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					} else if(MemTag[MEMIDX_JPEG].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_JPEG].StartAddr  - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					} else {
						memory_set_mem_tag(Idx, AllocEndAddr - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					}
				}
				break;
			case MEMIDX_MAIN_SEC:
				MemTag[Idx].Status = ALLOCATED_FROM_HIGH;
				if(MemTag[MEMIDX_MAIN_THIRD].StartAddr != _DUMMYADDR) {
					memory_set_mem_tag(Idx, MemTag[MEMIDX_MAIN_THIRD].StartAddr - space + 1, space);  // add a bank gap avoid Main sec Blk cover Bitmap
				} else {
					if(MemTag[MEMIDX_DI].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_DI].StartAddr - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					}
					else if(MemTag[MEMIDX_TT].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_TT].StartAddr  - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					} else if(MemTag[MEMIDX_VDC].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_VDC].StartAddr  - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					} else if(MemTag[MEMIDX_JPEG].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_JPEG].StartAddr  - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					} else {
						memory_set_mem_tag(Idx, AllocEndAddr - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					}
				}
				break;


			case MEMIDX_MAIN_THIRD:
				MemTag[Idx].Status = ALLOCATED_FROM_HIGH;
				if(MemTag[MEMIDX_DI].Status == ALLOCATED_FROM_HIGH) {
					memory_set_mem_tag(Idx, MemTag[MEMIDX_DI].StartAddr - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
				} else {
					if(MemTag[MEMIDX_TT].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_TT].StartAddr  - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					} else if(MemTag[MEMIDX_VDC].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_VDC].StartAddr  - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					} else if(MemTag[MEMIDX_JPEG].Status == ALLOCATED_FROM_HIGH) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_JPEG].StartAddr  - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					} else {
						memory_set_mem_tag(Idx, AllocEndAddr - (space + (1 << _DDR_BITS)) + 1, (space + (1 << _DDR_BITS)));  // add a bank gap avoid Main sec Blk cover Bitmap
					}
				}
				break;


			case MEMIDX_SUB:
				MemTag[Idx].Status = ALLOCATED_FROM_LOW;
				if(MemTag[MEMIDX_DI].Status == ALLOCATED_FROM_LOW) {
					memory_set_mem_tag(Idx, MemTag[MEMIDX_DI].StartAddr + MemTag[MEMIDX_DI].Size, space);
				} else {
					if(MemTag[MEMIDX_TT].Status == ALLOCATED_FROM_LOW) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_TT].StartAddr + MemTag[MEMIDX_TT].Size, space);
					} else if(MemTag[MEMIDX_VDC].Status == ALLOCATED_FROM_LOW) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_VDC].StartAddr + MemTag[MEMIDX_VDC].Size, space);
					} else if(MemTag[MEMIDX_JPEG].Status == ALLOCATED_FROM_LOW) {
						memory_set_mem_tag(Idx, MemTag[MEMIDX_JPEG].StartAddr + MemTag[MEMIDX_JPEG].Size, space);
					} else {
						memory_set_mem_tag(Idx, AllocStartAddr, space);
					}
				}
				IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr1_reg,(MemTag[Idx].StartAddr & 0x7ffffff0));
				break;

			case MEMIDX_SUB_SEC:
				if(MemTag[MEMIDX_SUB].StartAddr != _DUMMYADDR) {
					MemTag[Idx].Status = ALLOCATED_FROM_LOW;
					memory_set_mem_tag(Idx, MemTag[MEMIDX_SUB].StartAddr + MemTag[MEMIDX_SUB].Size, space);
				} else
					memory_set_mem_tag(Idx, _DUMMYADDR, 0);
				IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg,(MemTag[Idx].StartAddr+MemTag[Idx].Size) & 0x7ffffff0);
				break;


			case MEMIDX_SUB_THIRD:
				if(MemTag[MEMIDX_SUB_SEC].StartAddr != _DUMMYADDR) {
					MemTag[Idx].Status = ALLOCATED_FROM_LOW;
					memory_set_mem_tag(Idx, MemTag[MEMIDX_SUB_SEC].StartAddr + MemTag[MEMIDX_SUB_SEC].Size, space);
				} else
					memory_set_mem_tag(Idx, _DUMMYADDR, 0);
				IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg,(MemTag[Idx].StartAddr+MemTag[Idx].Size) & 0x7ffffff0);
				break;
			default:
				return _DUMMYADDR;
		};
#endif
	}

	pr_debug("[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);

	if(MEMIDX_DI_2 == Idx){


		printk(KERN_EMERG"[MEM] Idx[%d]=%x(%d KB)\n", Idx, MemTag[Idx].StartAddr, space >> 10);
	}
	return MemTag[Idx].StartAddr;
}


/*============================================================================*/
/**
 * memory_check_capture_polarity_error
 * Check field polarity error bit. reset capture block if it is error.
 *
 * @param  { none }
 * @return { none }
 *
 */
void memory_check_capture_polarity_error(unsigned char channel)
{
	unsigned char Sts;

	//field polarity error check
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	Sts = IoReg_ReadWord0(channel ? MDOMAIN_CAP_DDR_In2Status_reg : MDOMAIN_CAP_DDR_In1Status_reg);
	if (Sts & _BIT4) {	//Field polarity Error bit
		IoReg_ClearBits(channel ? MDOMAIN_CAP_DDR_In2Status_reg : MDOMAIN_CAP_DDR_In1Status_reg, _BIT4);
	}
#else
	Sts = IoReg_ReadWord0(/*channel ? MDOMAIN_CAP_DDR_In2Status_reg : */MDOMAIN_CAP_DDR_In1Status_reg);
	if (Sts & _BIT4) {	//Field polarity Error bit
		IoReg_ClearBits(/*channel ? MDOMAIN_CAP_DDR_In2Status_reg : */MDOMAIN_CAP_DDR_In1Status_reg, _BIT4);
	}
#endif
}



/*============================================================================*/
/**
 * memory_division
 * A Mathematical division
 *
 * @param <Dividend> { Dividend }
 * @param <Divisor> { Divisor }
 * @param <Quotient> { Quotient }
 * @param <Remainder> { Remainder }
 * @return { none }
 *
 */
void memory_division(unsigned int Dividend, unsigned char Divisor, unsigned int* Quotient, unsigned char* Remainder)
{
	*Quotient = (unsigned int)Dividend / Divisor;
	*Remainder = (unsigned char)((unsigned int)Dividend - (unsigned int)(*Quotient) * Divisor);
}

/*============================================================================*/
/**
 * memory_set_capture_fifo
 * Set capture FIFO information
 *
 * @param <channel> { channel selection }
 * @param <Quotient> { Quotient }
 * @param <Remainder> { remainder }
 * @param <Waterlevel> { Waterlevel }
 * @return { none }
 *
 */
void memory_set_capture_fifo(unsigned char channel, unsigned int Quotient, unsigned char Remainder, unsigned char WaterLevel)
{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_Write32(channel ? MDOMAIN_CAP_DDR_In2WTLVL_reg :  MDOMAIN_CAP_DDR_In1WTLVL_Num_reg, ((WaterLevel>>1) << 16) | Quotient);
	IoReg_Write32(channel ? MDOMAIN_CAP_DDR_In2WrLen_Rem_reg :  MDOMAIN_CAP_DDR_In1WrLen_Rem_reg, (WaterLevel << 8) | Remainder);
#else
	IoReg_Write32(/*channel ? MDOMAIN_CAP_DDR_In2WTLVL_reg :  */MDOMAIN_CAP_DDR_In1WTLVL_Num_reg, ((WaterLevel>>1) << 16) | Quotient);
	IoReg_Write32(/*channel ? MDOMAIN_CAP_DDR_In2WrLen_Rem_reg :  */MDOMAIN_CAP_DDR_In1WrLen_Rem_reg, (WaterLevel << 8) | Remainder);
#endif
}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
/*============================================================================*/
/**
 * memory_set_capture_addr
 * Set capture address
 *
 * @param <channel> { channel selection }
 * @param <Addr1> { 1st capture memory  }
 * @param <Addr2> { 2nd capture memory  }
 * @param <Waterlevel> { Waterlevel }
 * @return { none }
 *
 */
static void memory_set_capture_addr(unsigned char channel, unsigned int Addr1, unsigned int Addr2)
{
	//Crixus@20140722 - Mac3 no in2
	IoReg_Write32(/*channel ? MDOMAIN_CAP_DDR_In2Addr_reg : */MDOMAIN_CAP_DDR_In1Addr_reg, (Addr1 & 0x7ffffff0));
	IoReg_Write32(/*channel ? MDOMAIN_CAP_DDR_In2_2ndAddr_reg : */MDOMAIN_CAP_DDR_In1_2ndAddr_reg, (Addr2 & 0x7ffffff0));
}

/*============================================================================*/
/**
 * memory_set_capture_for_mp
 * Set memory capture registers for multi-picture. It can be #1 or #2, based on
 * current info structure.
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 * @note
 * For the cases except multi-picture, please refer to MemSetCapture()
 */


static void memory_set_capture_for_mp(void)
{
	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
	StructMemBlock* pBlock1;
	StructMemBlock* pBlock2;
	unsigned short BankChk;
	unsigned short LineStep;
	unsigned short BlockStep;
	unsigned char i,LineRemain;

	unsigned int burstLen = _BURSTLENGTH2;

	//Crixus@20140722 - Mac3 no in2
	IoReg_ClearBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_Cap_In2_enable_reg : */MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);	// disable Capture
	//frank@0503 add below delay to confirm M capture have disable
	msleep(20);
	memory_check_capture_polarity_error(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)); //field polarity error check
	ScalerMemory_Printf("\n Set CaptureForMP !");
	TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEMCAPTYPE_LINE);		// calculate the memory size of capture
	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division
	Remainder = drvif_memory_get_data_align(Remainder, 4);	// multiple of 4

	if (Remainder == 0){	// remainder is not allowed to be zero
		Remainder = burstLen;
		Quotient -= 1;
	}
	memory_set_capture_fifo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), Quotient, Remainder, burstLen);	// set capture FIFO

	TotalSize = SHL(Quotient * burstLen + Remainder, 3); //unit conversion. 64bits to 8bits

	BankChk= TotalSize;	// one line size in DDR

	LineStep = drvif_memory_get_data_align(TotalSize, _DDR_BANK_SIZE);	// multiple of 0x100, for bank check

	Scaler_PipSetSubInfo(SLR_PIP_SUB_MPDISPLINESTEP,LineStep);
	IoReg_Write32(MDOMAIN_CAP_DDR_In2LineStep_reg, (LineStep + LineStep%2) << 3);//bit 3 need to be 0. rbus rule

	BlockStep = (unsigned char)(SHR(LineStep, 9));	// unit conversion. unit: bank, remove C(1) also
	BlockStep = BlockStep * Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN);	// get 1 block


	LineRemain = (Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN)) % 4;		// add avoid MP44 and MP22 input Line number not 4 factor
	if( LineRemain == 0 )
		LineRemain = 2;
	else if(LineRemain == 2)
		LineRemain = 0;

	if( BankChk > (_DDR_BANK_SIZE*2))		// MP 1 line occupy 3 banks
		BlockStep += 4;
	else if( BankChk > _DDR_BANK_SIZE)	// MP 1 line occupy 2 banks
		BlockStep += 2;
	else{								// MP 1 line occupy 1 bank

		if(Scaler_PipGetInfo(SLR_PIP_TYPE) == SUBTYPE_MP3X3)	// MP33 input Line number must be 4 factor
			BlockStep += 1;
		else
			BlockStep += LineRemain;
	}

	TotalSize = BlockStep;
	Scaler_PipSetSubInfo(SLR_PIP_SUB_MPDISPBLOCKSTEP,TotalSize);
	TotalSize = SHL(TotalSize, _DDR_BITS);  //unit conversion, unit: 32bits
	TotalSize = TotalSize * Scaler_PipGetSubInfo(SLR_PIP_SUB_MPCNT);	// multiple MP count
	TotalSize = drvif_memory_get_data_align(TotalSize, _DDR_BANK_SIZE); // space must be bank-alignment

	drvif_memory_free_block(MEMIDX_SUB);	// free block befor getting a new one
	drvif_memory_free_block(MEMIDX_SUB_SEC);	// free block befor getting a new one
	drvif_memory_alloc_block(MEMIDX_SUB, TotalSize+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//*2,because space unit is byte

	pBlock1 = &MemTag[MEMIDX_SUB];
	pBlock1->StartAddr = drvif_memory_get_data_align(pBlock1->StartAddr, _DDR_BANK_ADDR_ALIGNMENT); // MP start address must be alignment bank0
	pBlock1->StartAddr += (_DDR_BANK_ADDR_ALIGNMENT*4);

	MemTag[MEMIDX_SUB].StartAddr = pBlock1->StartAddr;

// for second block
	TotalSize = Scaler_PipGetSubInfo(SLR_PIP_SUB_MPDISPBLOCKSTEP) * Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN);


	drvif_memory_alloc_block(MEMIDX_SUB_SEC, TotalSize+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//*2,because space unit is byte

	pBlock2 = &MemTag[MEMIDX_SUB_SEC];
	pBlock2->StartAddr = drvif_memory_get_data_align(pBlock2->StartAddr, _DDR_BANK_ADDR_ALIGNMENT);// alignment bank0 address
	pBlock2->StartAddr +=  (_DDR_BANK_ADDR_ALIGNMENT*4);

	if(BankChk < _DDR_BANK_SIZE)		// 1 line occupy 1 bank
		pBlock2->StartAddr += (_DDR_BANK_SIZE * 6);	// second block start address alignment bank 3

	MemTag[MEMIDX_SUB_SEC].StartAddr = pBlock2->StartAddr;		// backup sub second block start address

	for (i=0; i<16; i++){
		if (AND(SHR(Scaler_PipGetSubInfo(SLR_PIP_SUB_MPHIIDX), i), 0x01))	// check each bit from LSB
			break;	// found a bit for current MP window
	}
	TotalSize = (((unsigned int)Scaler_PipGetSubInfo(SLR_PIP_SUB_MPDISPBLOCKSTEP) * i) << CONFIG_DDR_COL_BITS);	// Shift start address based on current MP window, update MSB & medium bytes
	memory_set_capture_addr(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), (pBlock1->StartAddr + TotalSize), pBlock2->StartAddr);  	// MP 1L7B need change Capture to MP3
	IoReg_WriteWord0(MDOMAIN_CAP_DDR_In2LineNum_reg, SCALER_OR(AND(Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN), 0x0FFF), 0x0000));
	IoReg_Write32(MDOMAIN_CAP_DDR_In2Ctrl_reg, _BIT0 | _BIT4);
	IoReg_Write32(MDOMAIN_CAP_DDR_In2Ctrl_reg , _BIT0 | _BIT4 | _BIT6);
}
#endif //CONFIG_DUAL_CHANNEL  // There are two channels


static void MemSetDisplayAddr(unsigned char display, unsigned int Addr1, unsigned int Addr2)
{
	unsigned int address = 0;

	if(display == SLR_MAIN_DISPLAY){
		//printk("Before %s %d IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg)=%x\n",__FUNCTION__,__LINE__,IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg));
		IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg, Addr1&0x7ffffff0);
		//printk("After %s %d IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg)=%x\n",__FUNCTION__,__LINE__,IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg));
		IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg, Addr2&0x7ffffff0);

		//update m_disp boundary the same as m_cap boundary @Crixus 20171227
		address = IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg);
		IoReg_Write32(MDOMAIN_DISP_DispMain_BoundaryAddr1_reg, address&0x7ffffff0);
		address = IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg);
		IoReg_Write32(MDOMAIN_DISP_DispMain_BoundaryAddr2_reg, address&0x7ffffff0);
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else{
		IoReg_Write32(MDOMAIN_DISP_DDR_SubAddr_reg, Addr1&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Sub2ndAddr_reg, Addr2&0x7ffffff0);

		//update m_disp boundary the same as m_cap boundary @Crixus 20171227
		address = IoReg_Read32(MDOMAIN_CAP_CapSub_BoundaryAddr1_reg);
		IoReg_Write32(MDOMAIN_DISP_DispSub_BoundaryAddr1_reg, address&0x7ffffff0);
		address = IoReg_Read32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg);
		IoReg_Write32(MDOMAIN_DISP_DispSub_BoundaryAddr2_reg, address&0x7ffffff0);
	}
#endif
}

/*============================================================================*/
/**
 * memory_get_display_size
 * Calculate the memory size of display. The size is counted by 4:2:2/4:4:4 data format,
 * and frame-access/line access.
 *
 * @param <info> { disp-info structure }
 * @param <AccessType> { Access_Type  }
 * @param <TotalSize> { size of capture }
 * @return { none }
 *
 */
unsigned int memory_get_display_size(unsigned char display)
{
	unsigned int TotalSize;
	unsigned char ddrbit;

	ddrbit =  (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_CHANNEL) ? 0 : (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT) << 1))  | ( !Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_422CAP));
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
	//if rotate 90 or 270, then using length to calculate the memory line size
#if 0
	if(Get_rotate_function() && (get_rotate_curState()==MAIN_ROTATE_INIT_VI) && ((Get_Rotate_Mode()==ROTATE_MODE_90)||(Get_Rotate_Mode()==ROTATE_MODE_270))){
		if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)==SLR_MAIN_DISPLAY){
			TotalSize = memory_get_line_size(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_MEM_ACT_LEN), (ddrbit & _BIT0), ((ddrbit & _BIT1) >> 1));
		}
	}
	else
#endif
#endif
		TotalSize = memory_get_line_size(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_MEM_ACT_WID), (ddrbit & _BIT0), ((ddrbit & _BIT1) >> 1));
	//printk("[Memory display]:TotalSize=%x\n", TotalSize);
	return TotalSize;
}


/*============================================================================*/
/**
 * memory_set_mp
 * Set multi-picture related registers. It can be called only in sub
 *
 * @param <info> { disp-info structure }
 * @return { none }
 * @note
 * It can be called in sub display
 *
 */
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
static void memory_set_mp(void)
{
	unsigned short TotalSize;
	unsigned short BankLimit;
	unsigned short EndColumn;
	unsigned char ucTemp8;
	unsigned short ucTemp16;

	ucTemp16 = PipMp_GetMpFlag((eSubType)Scaler_PipGetInfo(SLR_PIP_TYPE));	// get MP enable flag
	IoReg_WriteWord0(MDOMAIN_DISP_DDR_SubMPEn_reg, ucTemp16);

	ucTemp8 = AND(IoReg_ReadByte0(MDOMAIN_DISP_DDR_SubMPMode_reg), 0xF0);	// get high nibble, active MP window
	ucTemp8 = (ucTemp8 | _BIT3 | SHR(AND(Scaler_PipGetSubInfo(SLR_PIP_SUB_SUBHVCNT), 0x0C), 1) | _BIT0); // set MP mode
	IoReg_WriteByte0(MDOMAIN_DISP_DDR_SubMPMode_reg, ucTemp8);	// set MP mode

	IoReg_WriteWord0(MDOMAIN_DISP_DDR_SubMPLineNum_reg, Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN)); 	// set MP Line number

	//------------------Set the end column------------------
	TotalSize = memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));

#if(CONFIG_DDR_DATA_BITS == 16)
	ucTemp16 = TotalSize = SHL(TotalSize, 2);		// 64bit to 16 bits
#else
	ucTemp16 = TotalSize = SHL(TotalSize, 1);		// 64bit to 32 bits
#endif
	TotalSize = drvif_memory_get_data_align(TotalSize,4);

	if( TotalSize > (_DDR_BANK_SIZE*2) ){

		EndColumn = ucTemp16-(_DDR_BANK_SIZE*2) -1;
		BankLimit = 0x1800;

	}else if( TotalSize > _DDR_BANK_SIZE ){

		EndColumn = ucTemp16-_DDR_BANK_SIZE -1;
		BankLimit = 0x1400;

	}else{

		EndColumn = ucTemp16 -1;
		BankLimit = 0x1e00;

	}

	ucTemp16 = (BankLimit |EndColumn) ;

	IoReg_WriteWord0(MDOMAIN_DISP_DDR_SubBankLimitEndCol_reg, ucTemp16);
	drvif_memory_set_dbuffer_write();
}
#endif //CONFIG_DUAL_CHANNEL  // There are two channels


/*============================================================================*/
/**
 * memory_set_sub_for_mp
 * This function is used to set sub control register for Mp
 *
 * @param <info> { display-info struecture }
 * @param <Block_Step> { Block step }
 * @return { none }
 * @note
 * If any one of the Memory-sub registers is changed, it is necessary to write
 * P3_B6 register to validate the update.
 *
 */
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
static void memory_set_sub_for_mp(void)
{
	unsigned int burstLen = _BURSTLENGTH2;
	unsigned int fifoLen = _FIFOLENGTH2;
	unsigned int linestep;//need to be even
	unsigned int blockstep;//need to be even

	IoReg_ClearBits(MDOMAIN_DISP_DDR_SubCtrl_reg,_BIT0);
	drvif_memory_set_dbuffer_write();
	MemSetDisplayAddr(SLR_SUB_DISPLAY, drvif_memory_get_block_addr(MEMIDX_SUB), drvif_memory_get_block_addr(MEMIDX_SUB_SEC));
	//frank@0323 change waterlevel/2 for AT,because water level nit is 128 bits
	IoReg_Mask32(MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0xff800ff, ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) & 0x07FF) << 8) | (fifoLen-burstLen));

	if((Scaler_PipGetInfo(SLR_PIP_TYPE) >= SUBTYPE_MP4X4) && (Scaler_PipGetInfo(SLR_PIP_TYPE) <= SUBTYPE_MP1L7B)){ // for sub size can be divisible by 4 in case 1C12B, 4x4, 1L7B
		IoReg_WriteWord0(MDOMAIN_DISP_DDR_SubLineNum_reg, (Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN)<<2) & 0x0FFF);
	}
	else
		IoReg_WriteWord0(MDOMAIN_DISP_DDR_SubLineNum_reg, (_DISP_LEN & 0x0FFF));

	IoReg_Write32(MDOMAIN_DISP_DDR_SubRdNumLenRem_reg, 0xffff00ff |((burstLen & 0xff) << 8));
	linestep = Scaler_PipGetSubInfo(SLR_PIP_SUB_MPDISPBLOCKSTEP);
	linestep = (linestep % 2)? linestep + 1: linestep;
	IoReg_Write32(MDOMAIN_DISP_DDR_SubLineStep_reg, linestep << 3); //bit3 need to be 0. rbus rule
	blockstep = Scaler_PipGetSubInfo(SLR_PIP_SUB_MPDISPBLOCKSTEP);
	blockstep = (blockstep % 2)? blockstep + 1: blockstep;
	IoReg_Write32(MDOMAIN_DISP_DDR_SubBlkStep_reg, blockstep << 3); //bit3 need to be 0. rbus rule

	IoReg_SetBits(MDOMAIN_DISP_DDR_SubCtrl_reg, _BIT6);
	drvif_memory_set_dbuffer_write();
	memory_set_mp();
}
#endif //CONFIG_DUAL_CHANNEL  // There are two channels

/*============================================================================*/
/**
 * memory_set_sub_for_pip
 * This function is used to set sub control register for PIP
 *
 * @param <info> { display-info struecture }
 * @param <Block_Step> { Block step }
 * @return { none }
 * @note
 * If any one of the Memory-sub registers is changed, it is necessary to write
 * P3_B6 register to validate the update.
 *
 */
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
static void memory_set_sub_for_pip(void)
{
	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int fifoLen = _FIFOLENGTH2;
	unsigned int burstLen = _BURSTLENGTH2;
	unsigned int MemShiftAddr = 0;
	unsigned short droppixel = 0;

	if ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA) == 0) && (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) == 0) ) {
		//frank@0323 change waterlevel/2 for AT,because water level nit is 128 bits
		IoReg_Mask32(MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0xffc00000, ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) & 0x3FFF) << 8) | ((fifoLen - (burstLen>>1))>>1));
		TotalSize = memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));	// calculate the memory size of capture
	} else {
		MemGetBlockShiftAddr(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);
		TotalSize = memory_get_disp_line_size1(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) + droppixel);	// calculate the memory size of capture
		IoReg_Mask32(MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0xffc00000, (( ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) +droppixel) & 0x3FFF) << 8) | ((fifoLen - (burstLen>>1))>>1)));
		pr_debug("drop pixel=%d shift addr=%x\n",droppixel,MemShiftAddr);
	}

	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division

	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubRdNumLenRem_reg, 0x00000000, (Quotient << 16) | (burstLen << 8) | Remainder);

	TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEMCAPTYPE_LINE);
	/*TotalSize = Quotient * burstLen + Remainder;	// count one line, 64bits unit
	TotalSize = drvif_memory_get_data_align(TotalSize, 4);	// times of 4*/

	IoReg_Write32(MDOMAIN_DISP_DDR_SubLineStep_reg,  (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule

	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));

	MemSetDisplayAddr(SLR_SUB_DISPLAY, drvif_memory_get_block_addr(MEMIDX_SUB) + MemShiftAddr, drvif_memory_get_block_addr(MEMIDX_SUB_SEC) + MemShiftAddr);
#ifdef ENABLE_3_BUFFER_DELAY_MODE
	IoReg_Write32(MDOMAIN_DISP_DDR_Sub3rdAddr_reg, (drvif_memory_get_block_addr(MEMIDX_SUB_THIRD) + MemShiftAddr)&0x7ffffff0);
#endif

	IoReg_Write32(MDOMAIN_DISP_DDR_SubAddrDropBits_reg,droppixel);
	/*IoReg_Mask32(MDOMAIN_DISP_DDR_SubBlkStep_reg, 0xff000000, 0);
	IoReg_WriteWord0(MDOMAIN_DISP_DDR_SubMPEn_reg,0);
	IoReg_WriteByte0(MDOMAIN_DISP_DDR_SubMPMode_reg, _BIT3);*/
	IoReg_SetBits(MDOMAIN_DISP_DDR_SubCtrl_reg, _BIT6);

	drvif_memory_set_dbuffer_write();
}


#endif //CONFIG_DUAL_CHANNEL  // There are two channels



UINT32 MemGetDDRLineWidth1(UINT8 display,UINT32 width)
{
	UINT8 ddrbit;
	UINT32 TotalSize;

	ddrbit =  (display ? 0 : ((Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT)) << 1 ))  | ( !Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_422CAP));
	TotalSize = memory_get_line_size(width, (ddrbit & _BIT0), ((ddrbit & _BIT1) >> 1));
	TotalSize = drvif_memory_get_data_align(TotalSize, 0x04);	// it must be times of 4
	return TotalSize;

}

UINT32 memory_get_disp_line_size1(UINT8 display,UINT32 width)
{
	UINT32 TotalSize;
	UINT8 ddrbit;

	ddrbit =  (display ? 0 : (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT) << 1))  | ( !Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_422CAP));
	TotalSize = memory_get_line_size(width, (ddrbit & _BIT0), ((ddrbit & _BIT1) >> 1));
	return TotalSize;
}

void MemGetBlockShiftAddr(UINT8 display,UINT16 HOffset, UINT16 VOffset,UINT32 * StartAddr, UINT16 *DropAddr)
{
	UINT32 TotalSize;
//	UINT8 ddrbit;
//	UINT8 Q = 0;
	UINT8 ddrbit;
	UINT16 K, L,S;
	UINT16 m,n;
	UINT8 FIFOUnit = 64;
//	UINT16 Shift_FIFOUnit;
	UINT16 hFIFOUnit;
	UINT8 InputFormat;
	UINT8 BitNum;

	TotalSize = MemGetDDRLineWidth1(display,Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_CAP_WID));
	ddrbit =  (display ? 0 : ((Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT)) << 1 ))  | ( !Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_422CAP));
	InputFormat = (ddrbit & _BIT0);
	BitNum = (ddrbit & _BIT1) >> 1;

	if(InputFormat){
		if(BitNum) {		// 4:4:4 format     10bit
			K = 1920;
			L = (HOffset * 30) / K;
			S = (HOffset * 30 - L * K) / 30;

			m = HOffset * 30 / FIFOUnit;
			n = HOffset * 30 - m * FIFOUnit;

//			ScalerMemory_Printf("\n 444_10 bits !");
		} else {			// 4:4:4 format     8bit
			K = 384;
			L = HOffset * 24 / K;
			S = (HOffset * 24 - L * K) / 24; //pixel

			m = HOffset * 24 / FIFOUnit;
			n = HOffset * 24 - m * FIFOUnit;


		}
	}else{
		if(BitNum) {		// 4:2:2 format     10bit
			K = 640;
			L = HOffset * 20 / K;
			S = (HOffset * 20 - L * K) / 20;

			m = HOffset * 20 / FIFOUnit;
			n = HOffset * 20 - m * FIFOUnit;

		} else {			// 4:2:2 format     8bit
			K = 128;
			L = HOffset * 16 / K;
			S = (HOffset * 16 - L * K) / 16;

			m = HOffset * 16 / FIFOUnit;
			n = HOffset * 16 - m * FIFOUnit;
		}
	}
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
	if(Get_rotate_function() && (get_rotate_mode()==ROTATE_MODE_90) ){//block mode:8 bit
		K = 64;
		L = (HOffset * 8) / K;
		S = (HOffset * 8 - L * K) / 8;

		m = HOffset * 8 / FIFOUnit;
		n = HOffset * 8 - m * FIFOUnit;
		TotalSize = drvif_memory_get_data_align((Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_MEM_ACT_WID))*8, 64);
		TotalSize = (unsigned int)SHR(TotalSize, 6);	// (pixels of per line * 20 / 64), unit: 64bits
		TotalSize = drvif_memory_get_data_align(TotalSize, 0x04);
	}
#endif
	if (n != 0)
		m = m + 1;


	hFIFOUnit =  (L * K) / FIFOUnit;

//	Shift_FIFOUnit = m - hFIFOUnit;

	TotalSize = TotalSize * VOffset + hFIFOUnit;
	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	*StartAddr = TotalSize;
	*DropAddr = S;

//	return Shift_FIFOUnit;

}


#ifdef CONFIG_MPIXEL_SHIFT
void memory_v_shift(int v)
{
	unsigned int ucStartAddress;
	unsigned int ucStartAddress2;
	unsigned int TotalSize;
	ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN);
	ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC);
	TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEMCAPTYPE_LINE);		// calculate capture line size
	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	if (v >= 0)
	{
		TotalSize = TotalSize * v;
		ucStartAddress +=TotalSize;
		ucStartAddress2 +=TotalSize;
	}
	else
	{
		TotalSize = TotalSize * (-v);
		ucStartAddress -=TotalSize;
		ucStartAddress2 -=TotalSize;
	}

	pr_debug("%d %x %x \n",v , ucStartAddress,ucStartAddress2);

	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg, ucStartAddress&0x7ffffff0);
		//printk("After %s %d IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg)=%x\n",__FUNCTION__,__LINE__,IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg));
	IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg, ucStartAddress2&0x7ffffff0);
	IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT0);
}

void memory_black_buf_init(unsigned int framesize,unsigned int  upperPhyAddress)
{
	unsigned int ucStartAddress;
	unsigned int ucStartAddress2;
	unsigned int upperVirtualAddr;
	unsigned int lowerPhyAddress,lowerVirtualAddr;
	unsigned int *lowerCurAddr,*upperCurAddr;
	unsigned int TotalSize;
	unsigned int i = 0;
	//upperPhyAddress = drvif_memory_get_block_addr(MEMIDX_MAIN);
	TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEMCAPTYPE_LINE);		// calculate capture line size
	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits
	TotalSize = TotalSize * 32;

	pr_debug("address %x %x %d\n",upperPhyAddress,AllocStartAddr,get_scaler_memory_map_addr());

	upperVirtualAddr = get_scaler_memory_map_addr() + (upperPhyAddress - AllocStartAddr);

	lowerPhyAddress = upperPhyAddress + TotalSize + framesize;

	lowerVirtualAddr = get_scaler_memory_map_addr() + (lowerPhyAddress - AllocStartAddr);


	upperCurAddr  = (unsigned int*)upperVirtualAddr;
	lowerCurAddr  = (unsigned int*)lowerVirtualAddr;

	pr_debug("address %x %x\n",lowerPhyAddress,lowerVirtualAddr);

	for(i = 0 ; i < TotalSize ; i= i + 4)
	{

		*upperCurAddr = 0x80008000;
		*lowerCurAddr = 0x80008000;

		upperCurAddr++;
		lowerCurAddr++;
	}

}


#endif

/*============================================================================*/
/**
 * MemSetMain
 * This function is used to set Main control register
 *
 * @param <info> { display-info struecture }
 * @param <Block_Step> { Block step }
 * @return { none }
 * @note
 * If any one of the Memory-main registers is changed, it is necessary to write
 * P3_8B register to validate the update.
 *
 */
extern unsigned char Get_3d_type(void);

void memory_set_main_3D_setting(unsigned int LineStep)
{
	unsigned int TotalSize;

	mdomain_disp_ddr_mainblkstep_RBUS ddr_mainblkstep_reg;
	mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;

	//mdomain_disp_ddr_mainsubctrl_RBUS ddr_mainsubctrl_reg;
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()
		&& ((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_TOP_AND_BOTTOM)||(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING)))
	{

		TotalSize = LineStep * (Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE)>>1);//for overscan modify

		if (Get_PANEL_VFLIP_ENABLE()&&(Scaler_InputSrcGetMainChType() != _SRC_VO) )
			TotalSize=(~TotalSize)+1;

		Scaler_Disp3dSetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_BLKSTEP,TotalSize);
		ddr_mainblkstep_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainBlkStep_reg);
		pr_debug("[DBG][TaB] Step Line/Block1=[%x/%x->%x(%d)]\n", LineStep, ddr_mainblkstep_reg.main_block_step, TotalSize, Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE));
		ddr_mainblkstep_reg.main_block_step = TotalSize;

		// PR output enable
		ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
#ifndef CONFIG_DARWIN_SCALER
		ddr_mainctrl_reg.main_pr_our_merge_en = 1;
#endif
		ddr_mainctrl_reg.main_merge_en0 = 1;
		ddr_mainctrl_reg.main_double_en = 1;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg,IoReg_Read32(MDOMAIN_CAP_DDR_In1Addr_reg)&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg,IoReg_Read32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg)&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg,IoReg_Read32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg)&0x7ffffff0);
		pr_debug("\n@@PR TBFP[%d] merge enable\n", Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE));
	}
	else
	{
		ddr_mainblkstep_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainBlkStep_reg);
		//printk("[DBG][TaB] Step Line/Block1=[%x/%x->%x]\n", LineStep, ddr_mainblkstep_reg.main_block_step, TotalSize);
		ddr_mainblkstep_reg.main_block_step = 0;

		// PR output enable
		ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
#ifndef CONFIG_DARWIN_SCALER
		ddr_mainctrl_reg.main_pr_our_merge_en = 0;
#endif
		ddr_mainctrl_reg.main_merge_en0 = 0;
		ddr_mainctrl_reg.main_double_en = 0;
		//printk("\n@@PR SBS  merge enable\n");
	}
	ddr_mainblkstep_reg.main_block_step = (ddr_mainblkstep_reg.main_block_step % 2)? ddr_mainblkstep_reg.main_block_step + 1 : ddr_mainblkstep_reg.main_block_step;
	//bit 3 need to be 0. rbus rule
	IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, ddr_mainblkstep_reg.regValue);
	IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, ddr_mainctrl_reg.regValue);
//frank@0617 mark below code to speed up,below code will setting by memory_set_input_format
	drvif_memory_set_dbuffer_write();

	if(drvif_memory_set_dbuffer_write() == 0)
		pr_debug("\n*** ERR: M-disp write fail@%s, %x ***\n", __FUNCTION__, IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg));
	//else
	//	printk("\n@@DDR_MAINCTRL=%x\n",IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg));
}




// [SG] SG 3D in data FRC mode -- sequence frame 3D L-R output control
void memory_set_main_SG_3D_setting(unsigned int LineStep, unsigned int Addr1, unsigned int Addr2, unsigned int Addr3)
{
	unsigned int TotalSize;
	unsigned int rFrameOffset=0;
	//SCALER_DISP_CHANNEL display = (SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	//mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;

	if(drvif_scaler3d_decide_3d_SG_data_FRC()){
		TotalSize = LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN);
		rFrameOffset = TotalSize << 3;
		if(rFrameOffset != (drvif_memory_get_block_size(MEMIDX_MAIN) >> 1))
			pr_debug("[SG] BlkStep cap/blk=%x/%x@IDMA\n", rFrameOffset, drvif_memory_get_block_size(MEMIDX_MAIN) >> 1);

		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_1ST_Addr_reg, Addr1 + rFrameOffset);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_2ND_Addr_reg, Addr2 + rFrameOffset);
		//printk("[SG][3D][FRC] R.1st/2nd=%x/%x(L+%d KB)\n", Addr1 + rFrameOffset, Addr2 + rFrameOffset, rFrameOffset>>10);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_3RD_Addr_reg, Addr3 + rFrameOffset);
		pr_debug("[SG][2D3D][FRC] R.1st/2nd/3rd=%x/%x/%x\n", Addr1, Addr2, Addr3);
	}else if(drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() && drvif_scaelr3d_decide_is_3D_display_mode()){
		mdomain_disp_ddr_mainblkstep_RBUS ddr_mainblkstep_reg;

		// M-domain 3D format convert -- 2Dcvt3D mode
		if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_2D_CVT_3D){
			// L/R frame use the same frame
			rFrameOffset = 0;
		} // M-domain 3D format convert -- TaB 3D mode
		else if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_TOP_AND_BOTTOM || Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING){
			// R-frame start position = 1/2 capture buffer
			TotalSize = (LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN));
			Scaler_Disp3dSetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_BLKSTEP,TotalSize);

			ddr_mainblkstep_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainBlkStep_reg);
			pr_debug("[DBG][TaB2] Step Line/Block1=[%x/%x->%x(%d)]\n", LineStep, ddr_mainblkstep_reg.main_block_step, TotalSize, Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE));
			ddr_mainblkstep_reg.main_block_step = TotalSize;

			rFrameOffset = TotalSize << 3;
			if(rFrameOffset != (drvif_memory_get_block_size(MEMIDX_MAIN) >> 1))
				pr_debug("[SG] BlkStep cap/blk=%x/%x@TaB\n", rFrameOffset, drvif_memory_get_block_size(MEMIDX_MAIN) >> 1);

		} // M-domain 3D format convert -- SBS 3D mode
		else{
			// R-frame start position = capture buffer + 1/2 line width
			TotalSize = (LineStep  >> 1);
			Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_BLKSTEP,TotalSize);

			ddr_mainblkstep_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainBlkStep_reg);
			pr_debug("[DBG][SBS] Step Line/Block1=[%x/%x->%x(%d)]\n", LineStep, ddr_mainblkstep_reg.main_block_step, TotalSize, Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE));
			ddr_mainblkstep_reg.main_block_step = TotalSize;

			rFrameOffset = TotalSize << 3;
			if(rFrameOffset != (drvif_memory_get_block_size(MEMIDX_MAIN) >> 1))
				pr_debug("[SG] BlkStep cap/blk=%x/%x@SBS\n", rFrameOffset, drvif_memory_get_block_size(MEMIDX_MAIN) >> 1);
		}
		ddr_mainblkstep_reg.main_block_step = (ddr_mainblkstep_reg.main_block_step % 2)? ddr_mainblkstep_reg.main_block_step + 1 : ddr_mainblkstep_reg.main_block_step;
		//bit 3 need to be 0. rbus rule
		if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_2D_CVT_3D){
			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_1ST_Addr_reg, Addr1 + rFrameOffset);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_2ND_Addr_reg, Addr2 + rFrameOffset);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_3RD_Addr_reg, Addr3 + rFrameOffset);
			IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, ddr_mainblkstep_reg.regValue);
		}else{
			// non-IDMA SG 3D mode L/R order need do invert
			IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg,(Addr1 + rFrameOffset)&0x7ffffff0);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg,(Addr2 + rFrameOffset)&0x7ffffff0);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg,(Addr3 + rFrameOffset)&0x7ffffff0);

			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_1ST_Addr_reg, Addr1);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_2ND_Addr_reg, Addr2);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_3RD_Addr_reg, Addr3);

			IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, ddr_mainblkstep_reg.regValue);
		}

		pr_debug("[SG][2D3D][FRC] R.1st/2nd/3rd=%x/%x/%x\n", Addr1, Addr2, Addr3);
	}

	return;
}

void memory_set_main_3D_setting_dispchange(unsigned int LineStep)
{
	SCALER_DISP_CHANNEL display = SLR_SUB_DISPLAY;
	unsigned int TotalSize;

	mdomain_disp_ddr_mainblkstep_RBUS ddr_mainblkstep_reg;
	mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;

	//mdomain_disp_ddr_mainsubctrl_RBUS ddr_mainsubctrl_reg;
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()
		&& ((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_TOP_AND_BOTTOM)||(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING)))
	{

		TotalSize = LineStep * (Scaler_DispGetInputInfoByDisp(display, SLR_DISP_3D_MEM_LEN_PRE)>>1);//for overscan modify

		if (Get_PANEL_VFLIP_ENABLE()&&(Scaler_InputSrcGetMainChType() != _SRC_VO) )
			TotalSize=(~TotalSize)+1;

		Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_BLKSTEP,TotalSize);
		ddr_mainblkstep_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainBlkStep_reg);
		pr_debug("[DBG][TaB] Step Line/Block1=[%x/%x->%x(%d)]\n", LineStep, ddr_mainblkstep_reg.main_block_step, TotalSize, Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE));
		ddr_mainblkstep_reg.main_block_step = TotalSize;

		// PR output enable
		ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
#ifndef CONFIG_DARWIN_SCALER
		ddr_mainctrl_reg.main_pr_our_merge_en = 1;
#endif
		ddr_mainctrl_reg.main_merge_en0 = 1;
		ddr_mainctrl_reg.main_double_en = 1;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg,IoReg_Read32(MDOMAIN_CAP_DDR_In1Addr_reg)&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg,IoReg_Read32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg)&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg,IoReg_Read32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg)&0x7ffffff0);
		pr_debug("\n@@PR TBFP[%d] merge enable\n", Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE));
	}
	else
	{
		ddr_mainblkstep_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainBlkStep_reg);
		//printk("[DBG][TaB] Step Line/Block1=[%x/%x->%x]\n", LineStep, ddr_mainblkstep_reg.main_block_step, TotalSize);
		ddr_mainblkstep_reg.main_block_step = 0;
		// PR output enable
		ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
		ddr_mainctrl_reg.main_pr_our_merge_en = 0;
		ddr_mainctrl_reg.main_merge_en0 = 0;
		ddr_mainctrl_reg.main_double_en = 0;
		//printk("\n@@PR SBS  merge enable\n");
	}
	ddr_mainblkstep_reg.main_block_step = (ddr_mainblkstep_reg.main_block_step % 2)? ddr_mainblkstep_reg.main_block_step + 1 : ddr_mainblkstep_reg.main_block_step;
	//bit 3 need to be 0. rbus rule
	IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, ddr_mainblkstep_reg.regValue);
	IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, ddr_mainctrl_reg.regValue);

}




// [SG] SG 3D in data FRC mode -- sequence frame 3D L-R output control
void memory_set_main_SG_3D_setting_dispchange(unsigned int LineStep, unsigned int Addr1, unsigned int Addr2, unsigned int Addr3)
{
	unsigned int TotalSize;
	unsigned int rFrameOffset=0;
	//mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;

	if(drvif_scaler3d_decide_3d_SG_data_FRC()){
		TotalSize = LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN);
		rFrameOffset = TotalSize << 3;
		if(rFrameOffset != (drvif_memory_get_block_size(MEMIDX_MAIN) >> 1))
			pr_debug("[SG] BlkStep cap/blk=%x/%x@IDMA\n", rFrameOffset, drvif_memory_get_block_size(MEMIDX_MAIN) >> 1);

		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_1ST_Addr_reg, Addr1 + rFrameOffset);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_2ND_Addr_reg, Addr2 + rFrameOffset);
		//printk("[SG][3D][FRC] R.1st/2nd=%x/%x(L+%d KB)\n", Addr1 + rFrameOffset, Addr2 + rFrameOffset, rFrameOffset>>10);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_3RD_Addr_reg, Addr3 + rFrameOffset);
		pr_debug("[SG][2D3D][FRC] R.1st/2nd/3rd=%x/%x/%x\n", Addr1, Addr2, Addr3);
	}else if(drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() && drvif_scaelr3d_decide_is_3D_display_mode()){
		mdomain_disp_ddr_mainblkstep_RBUS ddr_mainblkstep_reg;

		// M-domain 3D format convert -- 2Dcvt3D mode
		if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_2D_CVT_3D){
			// L/R frame use the same frame
			rFrameOffset = 0;
		} // M-domain 3D format convert -- TaB 3D mode
		else if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_TOP_AND_BOTTOM || Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING){
			// R-frame start position = 1/2 capture buffer
			TotalSize = (LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN));
			Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_BLKSTEP,TotalSize);

			ddr_mainblkstep_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainBlkStep_reg);
			pr_debug("[DBG][TaB2] Step Line/Block1=[%x/%x->%x(%d)]\n", LineStep, ddr_mainblkstep_reg.main_block_step, TotalSize, Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE));
			ddr_mainblkstep_reg.main_block_step = TotalSize;

			rFrameOffset = TotalSize << 3;
			if(rFrameOffset != (drvif_memory_get_block_size(MEMIDX_MAIN) >> 1))
				pr_debug("[SG] BlkStep cap/blk=%x/%x@TaB\n", rFrameOffset, drvif_memory_get_block_size(MEMIDX_MAIN) >> 1);

		} // M-domain 3D format convert -- SBS 3D mode
		else{
			// R-frame start position = capture buffer + 1/2 line width
			TotalSize = (LineStep  >> 1);
			Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_BLKSTEP,TotalSize);

			ddr_mainblkstep_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainBlkStep_reg);
			pr_debug("[DBG][SBS] Step Line/Block1=[%x/%x->%x(%d)]\n", LineStep, ddr_mainblkstep_reg.main_block_step, TotalSize, Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE));
			ddr_mainblkstep_reg.main_block_step = TotalSize;

			rFrameOffset = TotalSize << 3;
			if(rFrameOffset != (drvif_memory_get_block_size(MEMIDX_MAIN) >> 1))
				pr_debug("[SG] BlkStep cap/blk=%x/%x@SBS\n", rFrameOffset, drvif_memory_get_block_size(MEMIDX_MAIN) >> 1);
		}
		ddr_mainblkstep_reg.main_block_step = (ddr_mainblkstep_reg.main_block_step % 2)? ddr_mainblkstep_reg.main_block_step + 1 : ddr_mainblkstep_reg.main_block_step;
		//bit 3 need to be 0. rbus rule
		if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_2D_CVT_3D){
			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_1ST_Addr_reg, Addr1 + rFrameOffset);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_2ND_Addr_reg, Addr2 + rFrameOffset);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_3RD_Addr_reg, Addr3 + rFrameOffset);
			IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, ddr_mainblkstep_reg.regValue);
		}else{
			// non-IDMA SG 3D mode L/R order need do invert
			IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg,(Addr1 + rFrameOffset)&0x7ffffff0);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg,(Addr2 + rFrameOffset)&0x7ffffff0);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg,(Addr3 + rFrameOffset)&0x7ffffff0);

			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_1ST_Addr_reg, Addr1);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_2ND_Addr_reg, Addr2);
			IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_3RD_Addr_reg, Addr3);

			IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, ddr_mainblkstep_reg.regValue);
		}

		pr_debug("[SG][2D3D][FRC] R.1st/2nd/3rd=%x/%x/%x\n", Addr1, Addr2, Addr3);
	}

	return;
}

#undef ABS
#define ABS(X)			((X)<0 ? (-X) : (X))
void memory_set_MainandSub_ShowONPR(void)
{
	//unsigned int TotalSize;
	//ddr_mainblkstep_RBUS ddr_mainblkstep_reg;
	mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;
	//Crixus@20140722 - Mac3 no in2
	//TotalSize = ABS(IoReg_Read32(MDOMAIN_CAP_DDR_In2Addr_reg) -IoReg_Read32(MDOMAIN_CAP_DDR_In1Addr_reg));
	//IoReg_Write32(MDOMAIN_DISP_DDR_MAINBLKSTEP_VADDR, TotalSize);

	// PR output enable
	ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
	ddr_mainctrl_reg.main_pr_our_merge_en = 1;
	ddr_mainctrl_reg.main_merge_en0 = 1;
	ddr_mainctrl_reg.main_double_en = 1;
	IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, ddr_mainctrl_reg.regValue);

	drvif_memory_set_dbuffer_write();
	if(drvif_memory_set_dbuffer_write() == 0)
		pr_debug("\n*** ERR: M-disp write fail@%s, %x ***\n", __FUNCTION__, IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg));
	else
		pr_debug("\n@@DDR_MAINCTRL=%x\n",IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg));

}

extern unsigned char Get_vscFilmMode(void);
extern void filmmode_videofw_config(unsigned int filmmode, unsigned int buf4addr);
static void memory_set_main(unsigned char bDouble)
{
	unsigned int TotalSize;
//	unsigned int  TotalSizeFrame=0;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int ucStartAddress;
	unsigned int ucStartAddress2=0;
	unsigned int ucStartAddress3=0;
	unsigned int LineStep;
	mdomain_disp_ddr_mainprevstart_RBUS ddr_mainprevstart_reg;
	unsigned int comp_width = 0;
	unsigned int fifoLen = _FIFOLENGTH;
	unsigned int burstLen = _BURSTLENGTH;
	//Update the fifo depth for each IC @Crixus 20170418
#ifdef MERLIN_FIFO_DEPTH
		//frank@0325 double the M domain burst length to avoid YUV444 peak BW not enough
		if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
			burstLen=0xf0;
		}
#endif
	#ifdef CONFIG_3D_ASPECT_RATIO
	UINT32 MemShiftAddr = 0;
	UINT16 droppixel = 0;
	#endif

	StructSrcRect m_dispwin;
	m_dispwin = Scaler_DispWindowGet();

	ddr_mainprevstart_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainPreVStart_reg);
	if((vsc_get_adaptivestream_flag()) ||(m_dispwin.srcy <= 100)) {
		ddr_mainprevstart_reg.main_pre_rd_v_start = 7;
	} else {
		ddr_mainprevstart_reg.main_pre_rd_v_start = (m_dispwin.srcy-10);
	}

	IoReg_Write32(MDOMAIN_DISP_DDR_MainPreVStart_reg, ddr_mainprevstart_reg.regValue);

	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddrDropBits_reg,0x0);

	IoReg_Mask32(MDOMAIN_DISP_DDR_MainLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));

#ifdef CONFIG_3D_ASPECT_RATIO
	pr_debug("mem act info %d %d %d %d\n",Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));

	if ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA) == 0) && (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) == 0) )
	{

		if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE)){
			comp_width = Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID);
			if((comp_width % 32) != 0)
				comp_width = comp_width + (32 - (comp_width % 32));
			IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, (((comp_width * dvrif_memory_get_compression_bits() / 32) & 0x0fFF) << 8) | ((fifoLen-(burstLen>>1))>>1));
			TotalSize = memory_get_capture_line_size_compression(dvrif_memory_get_compression_bits());
		}
		else{
			IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) & 0x0fFF) << 8) | ((fifoLen-(burstLen>>1))>>1));
		TotalSize = memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));	// calculate the memory size of capture
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
		if(Get_rotate_function()) {
			TotalSize = drvif_memory_get_data_align(Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID)*8, 64);
			TotalSize = (unsigned int)SHR(TotalSize, 6);	// (pixels of per line * 24 / 64), unit: 64bits
	}
#endif

	}

	}
	else
	{
		MemGetBlockShiftAddr(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);
	#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
		if(Get_rotate_function() && (get_rotate_mode()==(DIRECT_VO_FRAME_ORIENTATION)ROTATE_MODE_90) ) {
			TotalSize = drvif_memory_get_data_align((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) + droppixel)*8, 64);
			TotalSize = (unsigned int)SHR(TotalSize, 6);	// (pixels of per line * 24 / 64), unit: 64bits
		} else
	#endif
		TotalSize = memory_get_disp_line_size1(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) + droppixel);	// calculate the memory size of capture
		IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, (( ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) +droppixel) & 0x0fFF) << 8) | ((fifoLen-(burstLen>>1))>>1)));
		pr_debug("drop pixel=%d shift addr=%x\n",droppixel,MemShiftAddr);

	}
#if 0
	if(droppixel != 0){
		UINT32 drop_line = 0;
		drop_line = droppixel * Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN);
		drop_line = drop_line / (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) + droppixel) + 1;
		printk(KERN_EMERG"@@@@@@@@@@@@drop_line = %d\n",drop_line);
		IoReg_Mask32(MDOMAIN_DISP_DDR_MainLineNum_reg, 0xfffff000, ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN) - drop_line)& 0x0FFF));
	}
#endif

#else

	IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) & 0x0fFF) << 8) | ((fifoLen-(burstLen>>1))>>1));

	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE))
		TotalSize = memory_get_capture_line_size_compression(dvrif_memory_get_compression_bits());
	else
		TotalSize = memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));	// calculate the memory size of capture
#endif

	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division

	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Write32(MDOMAIN_DISP_DDR_MainRdNumLenRem_reg, (Quotient << 16) | (burstLen << 8) | Remainder);

	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE))
		TotalSize = memory_get_capture_line_size_compression(dvrif_memory_get_compression_bits());
	else
	TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEMCAPTYPE_LINE);		// calculate capture line size
#ifdef CONFIG_ENABLE_SE_ROTATE_M_DOMAIN_BLOCK_MODE
	if(Get_rotate_function()) {
		TotalSize = drvif_memory_get_data_align(Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID)*8, 64);
		TotalSize = (unsigned int)SHR(TotalSize, 6);	// (pixels of per line * 24 / 64), unit: 64bits
		TotalSize = drvif_memory_get_data_align(TotalSize, 0x04);
	}
#endif
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF))
		TotalSize=TotalSize>>1;

	LineStep = TotalSize;
	//printk(KERN_EMERG"Line Step=0x%x\n",LineStep);
	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	IoReg_Write32(MDOMAIN_DISP_DDR_MainLineStep_reg, (LineStep + LineStep%2) << 3);//bit 3 need to be 0. rbus rule

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()
		&& ((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_SIDE_BY_SIDE_HALF)||(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_TOP_AND_BOTTOM)||(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)))
	{
		unsigned char ddr_bit;
		unsigned int temp;
		ddr_bit=(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_CHANNEL) ? 0 : (Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_10BIT) << 1))  | ( !Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_422CAP));

		if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING || Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_TOP_AND_BOTTOM)
		{
			//[#0051720] MVC FP source (L-sync, double buffer control)
			if((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING) && (Scaler_InputSrcGetMainChType() == _SRC_VO))
			{
				MemShiftAddr=((2*Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE)-2*Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN))>>2)*LineStep;
			}
			else
			{
				MemShiftAddr=((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE)-Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN))>>2)*LineStep;
				if(get_3D_overscan_enable())
				{
					MemShiftAddr=(get_3D_overscan_input_vsta()>>1)*LineStep;
				}
			}
		}
		else
		{
			MemShiftAddr=((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE)-Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN))>>1)*LineStep;
			if(get_3D_overscan_enable())
			{
				MemShiftAddr=(get_3D_overscan_input_vsta())*LineStep;
			}
		}

		//printk("[3d]shift addr v=%x\n",MemShiftAddr);
		temp=memory_get_line_size(((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_WID_PRE)-Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID))>>1), (ddr_bit & _BIT0), ((ddr_bit & _BIT1) >> 1));
		if(get_3D_overscan_enable())
		{
			if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING || Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_TOP_AND_BOTTOM)
				temp=memory_get_line_size(get_3D_overscan_input_hsta(), (ddr_bit & _BIT0), ((ddr_bit & _BIT1) >> 1));
			else if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_SIDE_BY_SIDE_HALF)
				temp=memory_get_line_size(get_3D_overscan_input_hsta()>>1, (ddr_bit & _BIT0), ((ddr_bit & _BIT1) >> 1));
		}

		temp=drvif_memory_get_data_align(temp, 2);
		MemShiftAddr=MemShiftAddr+temp;
		//printk("[3d]shift addr h=%x\n",MemShiftAddr);
		MemShiftAddr=MemShiftAddr<<3;
		//printk("[3d]shift addr after <<3 =%x\n",MemShiftAddr);
	}

#if 0
	if(TRUE==get_delayframe_fuc())
	{
		ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN) + MemShiftAddr;
		if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) != SLR_3D_2D_ONLY))
		{
			MemDispStartAddr_3D[0]=ucStartAddress;
		}
		bDouble = FALSE;
	}
	else
#endif
	{
		ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN) + MemShiftAddr;

		ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + MemShiftAddr;

		if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) != SLR_3D_2D_ONLY))
		{
			MemDispStartAddr_3D[0]=ucStartAddress;
			MemDispStartAddr_3D[1]=ucStartAddress2;
		}

#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
		if(Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>650)
		{
			ucStartAddress3 = drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr;
			IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, ucStartAddress3&0x7ffffff0);
		}
		else if(_ENABLE == Scaler_Get_Enable_3Buffer_NewRuleCondition())
		{
			if(_TRUE == Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
				{
				ucStartAddress3 = drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr;
				IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, ucStartAddress3&0x7ffffff0);
			}
		}
#else //#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
		//M-3buf condition:
		// 1. [2D] M-capture frame rate > M-display frame rate
		// 2. [3D][SG] FRC in M-domain, M-display need repeat frame 2 times
		// 3. [3D][SG] SG 3D display timing FRC need enable triple buffer to avoid frame tear issue
		// 4. [3D][PR] PR to SG 3D display timing FRC need enable triple buffer to avoid frame tear issue
		if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>650)|| drvif_scaler3d_decide_3d_SG_data_FRC()
				|| ((drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() == TRUE) && drvif_scaelr3d_decide_is_3D_display_mode())
				|| (Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE() && drvif_scaelr3d_decide_is_3D_display_mode())
				|| (modestate_get_pr3d_in_fp_3d_mode() && ((Scaler_InputSrcGetMainChType() == _SRC_VO)|| (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) >= 310)))
				||Get_vscFilmMode())
		{
			ucStartAddress3 = drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr;
			IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, ucStartAddress3&0x7ffffff0);
			MemDispStartAddr_3D[2]=ucStartAddress3;
		}
#endif //#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
	}
#ifdef ENABLE_3_BUFFER_DELAY_MODE
	ucStartAddress3 = drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr;
	IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, ucStartAddress3&0x7ffffff0);
	MemDispStartAddr_3D[2]=ucStartAddress3;
#endif

	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddrDropBits_reg,droppixel);

	Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_DISPLAY_SIZE, memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)));

	MemSetDisplayAddr(SLR_MAIN_DISPLAY, ucStartAddress, ucStartAddress2);	// Main disaply not need set second block start address

	//printk("%s %d bDouble=%d\n",__FUNCTION__,__LINE__,bDouble);
	if(bDouble) {	// use double buffer
		//TotalSize = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) - drvif_memory_get_block_addr(MEMIDX_MAIN);
		//TotalSize = drvif_memory_get_data_align(TotalSize, _DDR_BANK_ADDR_ALIGNMENT);
		//TotalSize = SHR(TotalSize, _DDR_ROW_BITS); //row alignment and get the block step

		TotalSize = LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN);
		IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule
	}

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()){
		memory_set_main_3D_setting(LineStep);
	}// [SG] SG 3D in data FRC mode -- sequence frame 3D L-R output control
	else if(drvif_scaler3d_decide_3d_SG_data_FRC()|| (drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() && drvif_scaelr3d_decide_is_3D_display_mode())){
		memory_set_main_SG_3D_setting(LineStep, ucStartAddress, ucStartAddress2, ucStartAddress3);
	}
#if 0
	if((get_mainsubonpr_fuc()==TRUE)&&(get_MainSubonPR_curState()==MAINSUB_SHOWONPR_INIT_MAIN))
	{
		memory_set_MainandSub_ShowONPR();
	}
#endif
	Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_MAIN_ADDR, ucStartAddress);
	Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_MAIN_SEC_ADDR, ucStartAddress2);
	Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_MAIN_THIRD_ADDR, ucStartAddress3);

}


void zoom_memory_set_main(unsigned char bDouble,unsigned char buffernum)

{
	unsigned int TotalSize;
//	unsigned int  TotalSizeFrame=0;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int ucStartAddress;
	unsigned int ucStartAddress2;
	unsigned int LineStep;
	unsigned int fifoLen = _FIFOLENGTH;
	unsigned int burstLen = _BURSTLENGTH;
	StructSrcRect m_dispwin;
	mdomain_disp_ddr_mainprevstart_RBUS ddr_mainprevstart_reg;

	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
		burstLen=0xf0;
	}

	m_dispwin = Scaler_DispWindowGet();
	ddr_mainprevstart_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainPreVStart_reg);
	if(m_dispwin.srcy <= 100) {
		ddr_mainprevstart_reg.main_pre_rd_v_start = 7;
	} else {
		ddr_mainprevstart_reg.main_pre_rd_v_start = (m_dispwin.srcy-10);
	}
	IoReg_Write32(MDOMAIN_DISP_DDR_MainPreVStart_reg, ddr_mainprevstart_reg.regValue);

	//frank@0323 change waterlevel/2 for AT,because water level nit is 128 bits
	IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) & 0x0fFF) << 8) | ((fifoLen-(burstLen>>1))>>1));
	IoReg_Mask32(MDOMAIN_DISP_DDR_MainLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));


	TotalSize = memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));	// calculate the memory size of capture
	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division

	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Write32(MDOMAIN_DISP_DDR_MainRdNumLenRem_reg, (Quotient << 16) | (burstLen << 8) | Remainder);

	TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEMCAPTYPE_LINE);		// calculate capture line size
	LineStep = TotalSize;
	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits
	//LineStep = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	IoReg_Write32(MDOMAIN_DISP_DDR_MainLineStep_reg, (LineStep + LineStep%2) << 3);//bit 3 need to be 0. rbus rule

	ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
	ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
	MemSetDisplayAddr(SLR_MAIN_DISPLAY, ucStartAddress, ucStartAddress2);	// Main disaply not need set second block start address

	if (bDouble)
	{
		if (buffernum == 0)
		{
			ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
			ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
		}
		else
		{
			ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
			ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
		}
	}
	else
	{
		if (buffernum == 0)
		{
			ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN) +(Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
        	//ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + (info->MEM_ACT_HSTA) + (info->MEM_ACT_VSTA *TotalSize);
		}
		else
		{
		ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
        	//ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + (info->MEM_ACT_HSTA) + (info->MEM_ACT_VSTA *TotalSize);
		}
	}

	//printk("disp buffernum=%x, ucStartAddress=%x ucStartAddress2=%x\n",buffernum,ucStartAddress,ucStartAddress2);

	MemSetDisplayAddr(SLR_MAIN_DISPLAY, ucStartAddress, ucStartAddress2);	// Main disaply not need set second block start address

	if(bDouble) {	// use double buffer
		TotalSize = LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN);
		IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule
	}
}

void memory_set_input_format2(unsigned char display, unsigned char bDouble)
{
	unsigned int /* temp = 0, */ temp1 = 0;
	mdomain_disp_display_byte_channel_swap_RBUS display_byte_channel_swap_reg;
	if ( bDouble )
	{
		if (Get_PANEL_VFLIP_ENABLE())
		{
		if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_VFLIP3))
			temp1 =  _BIT7 | (display ? _BIT1 : 0) | _BIT6  ;
		else
				temp1 =  (display ? _BIT1 : 0) | _BIT6;
		}
		else
			temp1 =  (display ? _BIT1 : 0) | _BIT6;
	}
	else
		temp1 =  (display ? _BIT1 : 0) ;

	//add below code for GPU access YUV format ++
	display_byte_channel_swap_reg.regValue = IoReg_Read32(MDOMAIN_DISP_Display_byte_channel_swap_reg);
	if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)){
		//Crixus@20140722 - Mac3 no sub path
		//display_byte_channel_swap_reg.sub_2byte_swap = 1;
		//display_byte_channel_swap_reg.sub_4byte_swap = 1;
	}else{
		display_byte_channel_swap_reg.main_2byte_swap = 1;
		display_byte_channel_swap_reg.main_4byte_swap = 1;
	}
	IoReg_Write32(MDOMAIN_DISP_Display_byte_channel_swap_reg, display_byte_channel_swap_reg.regValue);
	//frank@03132013 add below code for GPU access YUV format --

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_Write32(display? MDOMAIN_DISP_DDR_SubCtrl_reg: MDOMAIN_DISP_DDR_MainCtrl_reg,  temp1);
	IoReg_Write32(display? MDOMAIN_DISP_Disp_sub_enable_reg: MDOMAIN_DISP_Disp_main_enable_reg,  _BIT0);
#else
	IoReg_Write32(/*display? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_DDR_MainCtrl_reg,  temp1);
	IoReg_Write32(/*display? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_Disp_main_enable_reg,  _BIT0);
#endif
	drvif_memory_set_dbuffer_write();
}


void zoom_set_input_format(unsigned char display, unsigned char bDouble)
{
	unsigned int/* temp = 0,*/ temp1 = 0;
	mdomain_disp_display_byte_channel_swap_RBUS display_byte_channel_swap_reg;
	if ( bDouble )
	{
		if (Get_PANEL_VFLIP_ENABLE())
		{
		if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_VFLIP3))
			temp1 =  _BIT7 | (display ? _BIT1 : 0) | _BIT6   ;
		else
				temp1 =  (display ? _BIT1 : 0) | _BIT6;
		}
		else
			temp1 =  (display ? _BIT1 : 0) | _BIT6;
	}
	else
		temp1 =  (display ? _BIT1 : 0) ;
	temp1 |= display ? 0 : (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT) ? _BIT16 : 0);
	if((display == SLR_MAIN_DISPLAY) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE)){
		temp1 |= _BIT17;
	}else{
		temp1 |= Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display, SLR_DISP_422CAP) ? 0 : _BIT17;
	}
	temp1 |=  _BIT19;

	// add below code for GPU access YUV format ++
	display_byte_channel_swap_reg.regValue = IoReg_Read32(MDOMAIN_DISP_Display_byte_channel_swap_reg);
	if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)){
		//Crixus@20140722 - Mac3 no sub path
		//display_byte_channel_swap_reg.sub_2byte_swap = 1;
		//display_byte_channel_swap_reg.sub_4byte_swap = 1;
	}else{
		display_byte_channel_swap_reg.main_2byte_swap = 1;
		display_byte_channel_swap_reg.main_4byte_swap = 1;
	}
	IoReg_Write32(MDOMAIN_DISP_Display_byte_channel_swap_reg, display_byte_channel_swap_reg.regValue);
	//frank@03132013 add below code for GPU access YUV format --

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_Write32(display? MDOMAIN_DISP_DDR_SubCtrl_reg: MDOMAIN_DISP_DDR_MainCtrl_reg,  temp1);
	IoReg_Write32(display? MDOMAIN_DISP_Disp_sub_enable_reg: MDOMAIN_DISP_Disp_main_enable_reg,  _BIT0);
#else
	IoReg_Write32(/*display? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_DDR_MainCtrl_reg,  temp1);
	IoReg_Write32(/*display? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_Disp_main_enable_reg,  _BIT0);
#endif
	// write data & set double buffer write enable
	if(display == SLR_MAIN_DISPLAY)
	{
//		IoReg_Write32(MDOMAIN_DDR_MAINSTATUS_VADDR , temp);
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg) | _BIT0);
	}
}

extern unsigned int mdomain_input_fast_flag;
void memory_set_input_format(unsigned char display, unsigned char bDouble)
{
	unsigned int /*temp = 0,*/ temp1 = 0;
	mdomain_disp_display_byte_channel_swap_RBUS display_byte_channel_swap_reg;

	mdomain_input_fast_flag = 0;
	if(Get_vscFilmMode()==TRUE)
	{
		temp1 =  (display ? _BIT1 : 0);
	}
	else
	{
		if ( bDouble )
		{
			if (Get_PANEL_VFLIP_ENABLE())
			{
			if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_VFLIP3))
				temp1 =  _BIT7 | (display ? _BIT1 : 0) | _BIT6   ;
			else
					temp1 =  (display ? _BIT1 : 0) | _BIT6;
			}
			else
				temp1 =  (display ? _BIT1 : 0) | _BIT6 ;
		}
		else
		{
			if (Get_PANEL_VFLIP_ENABLE()&&(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_VFLIP3)))
			{
				temp1 =  _BIT7 | (display ? _BIT1 : 0) ;
			}
			else
				temp1 =  (display ? _BIT1 : 0);
		}
		//M-3buf condition:
		// 1. [2D] M-capture frame rate > M-display frame rate
		// 2. [3D][SG] FRC in M-domain, M-display need repeat frame 2 times
		// 3. [3D][SG] SG 3D display free run need triple buffer to avoid frame tear
		// 4. [3D][PR] PR to SG 3D display timing FRC need enable triple buffer to avoid frame tear issue
		// 5. [3D][PR] frame packing video in PR 3D panel (TO BE FIXED)
		if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 650)
				|| drvif_scaler3d_decide_3d_SG_data_FRC()
				|| ((drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() == TRUE) && drvif_scaelr3d_decide_is_3D_display_mode())
				|| (Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE() && drvif_scaelr3d_decide_is_3D_display_mode())
				|| (modestate_get_pr3d_in_fp_3d_mode() && ((Scaler_InputSrcGetMainChType() == _SRC_VO)|| (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) >= 310))))
		{
			// Input source frame rate faster than display (main_frc_style = 1)
			// M-display IVS refer to front of VGIP signal (for HDMI FP 3D, IVS refer to the source v-sync)
			if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 650) && (Scaler_Get3DMode((SCALER_DISP_CHANNEL)display) == SLR_3DMODE_2D) && (display == SLR_MAIN_DISPLAY))
			{//Will add condition. only main can set for WOSQRTK-2978
				//temp1 |= _BIT3;
				mdomain_input_fast_flag = 1;
			}

			if(display == SLR_MAIN_DISPLAY)//frank@1007 solve VGA source M domain hang problem
				//set Mdomain display triple buffer
				temp1 |=_BIT7;

			// [3D][PR]  PR output merge triple buffer enable
			if(Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()){
				if((Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE) == SLR_3D_TOP_AND_BOTTOM)||(Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING))
					temp1 |=_BIT14;
			}
		}

		if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE())
			temp1=temp1|(IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg)&(_BIT5|_BIT13));// filed merge enable
	}
	temp1 |= display ? 0 : (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT) ? _BIT16 : 0);
	if((display == SLR_MAIN_DISPLAY) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE)){
		temp1 |= _BIT17;
	}else{
		temp1 |= Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display, SLR_DISP_422CAP) ? 0 : _BIT17;
	}
	temp1 |= (_BIT19);
	temp1 |= (drvif_scaler3d_decide_3d_SG_data_FRC()|| (drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() && drvif_scaelr3d_decide_is_3D_display_mode())? _BIT12: 0); // 3D frame sequence out enable
#ifdef ENABLE_3_BUFFER_DELAY_MODE
	temp1 |=_BIT7;//set Mdomain main display triple buffer
#endif

	//disp ctrl default setting
	temp1 |= (_BIT25 | _BIT28);

	//frank@03132013 add below code for GPU access YUV format ++
	display_byte_channel_swap_reg.regValue = IoReg_Read32(MDOMAIN_DISP_Display_byte_channel_swap_reg);
	if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)){
		if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),SLR_DISP_422CAP))
		{
			display_byte_channel_swap_reg.sub_1byte_swap = 0;
			display_byte_channel_swap_reg.sub_2byte_swap = 1;
			display_byte_channel_swap_reg.sub_4byte_swap = 1;
			display_byte_channel_swap_reg.sub_8byte_swap = 0;
		}
		else
		{
			display_byte_channel_swap_reg.sub_1byte_swap = 1;
			display_byte_channel_swap_reg.sub_2byte_swap = 1;
			display_byte_channel_swap_reg.sub_4byte_swap = 1;
			display_byte_channel_swap_reg.sub_8byte_swap = 0;
		}
	}else{
		if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),SLR_DISP_10BIT))
				{
					display_byte_channel_swap_reg.main_1byte_swap = 0;
					display_byte_channel_swap_reg.main_2byte_swap = 0;
					display_byte_channel_swap_reg.main_4byte_swap = 0;
					display_byte_channel_swap_reg.main_8byte_swap = 0;

				}
				else
				{
					if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),SLR_DISP_422CAP))
					{
						display_byte_channel_swap_reg.main_1byte_swap = 0;
						display_byte_channel_swap_reg.main_2byte_swap = 1;
						display_byte_channel_swap_reg.main_4byte_swap = 1;
						display_byte_channel_swap_reg.main_8byte_swap = 0;
					}
					else
					{
						display_byte_channel_swap_reg.main_1byte_swap = 1;
						display_byte_channel_swap_reg.main_2byte_swap = 1;
						display_byte_channel_swap_reg.main_4byte_swap = 1;
						display_byte_channel_swap_reg.main_8byte_swap = 0;
					}
				}

	}
	IoReg_Write32(MDOMAIN_DISP_Display_byte_channel_swap_reg, display_byte_channel_swap_reg.regValue);
	//frank@03132013 add below code for GPU access YUV format --
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_Write32(display? MDOMAIN_DISP_DDR_SubCtrl_reg: MDOMAIN_DISP_DDR_MainCtrl_reg,  temp1);
	IoReg_Write32(display? MDOMAIN_DISP_Disp_sub_enable_reg: MDOMAIN_DISP_Disp_main_enable_reg,  _BIT0);
#else
	IoReg_Write32(/*display? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_DDR_MainCtrl_reg,  temp1);
	IoReg_Write32(/*display? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_Disp_main_enable_reg,  _BIT0);
#endif
	// write data & set double buffer write enable
	if(display == SLR_MAIN_DISPLAY)
	{
		// write data & enable double buffer
		// due to mantis bug:10311, we have to write 3 times to enable double buffer register write
		//IoReg_Write32(MDOMAIN_DDR_MAINSTATUS_VADDR , temp);
		if(drvif_memory_set_dbuffer_write() == 0)
			pr_debug("\n*** ERR: M-disp write fail@%s.L%d, %x ***\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg));
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else {
		//IoReg_Write32(MDOMAIN_DDR_SUBSTATUS_VADDR, temp);
		if(drvif_memory_set_dbuffer_write() == 0)
			pr_debug("\n*** ERR: M-disp write fail@%s.L%d, %x ***\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg));
	}
#endif
}



static unsigned int memory_get_capture_max_size(unsigned char display, eMemCapAccessType AccessType)
{
	unsigned int TotalSize;
	unsigned char ddrbit;
	unsigned char dispInterlace = Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display, SLR_DISP_INTERLACE);

	ddrbit =  (Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_CHANNEL) ? 0 : ((Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT)) << 1 ))  | ( !Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_422CAP));

	TotalSize = memory_get_line_size((Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE) > _DISP_WID) ? _DISP_WID :  Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPH_ACT_WID_PRE), (ddrbit & _BIT0), ((ddrbit & _BIT1) >> 1));

	// it must be times of 4
	TotalSize = drvif_memory_get_data_align(TotalSize, 0x04);

	// multiple total_lines if frame-access
	if (AccessType == MEMCAPTYPE_FRAME) {
			if(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE) > _DISP_LEN)
				TotalSize *= _DISP_LEN;
			else
				TotalSize *= Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)display,SLR_INPUT_IPV_ACT_LEN_PRE);

			if(dispInterlace)
				TotalSize = TotalSize * 2;
	}

	return TotalSize;
}

#define REDUCE_DI_MEMORY_LIMIT_THRESHOLD 		720
/*============================================================================*/
/**
 * MemSetCapture
 * Set memory capture registers. It can be #1 or #2, based on current info structure
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 */
extern unsigned int memory_get_capture_line_size_compression(unsigned char compression_bits);


static void memory_set_capture(unsigned char bDouble, eMemCapAccessType Cap_type)
{
	unsigned int  TotalSize;
	unsigned int  TotalSize1 = 0;
//	unsigned int  TotalSizeFrame;
	unsigned int  nStartAddr=0;
	unsigned int  Quotient;
	unsigned char  Remainder;
	unsigned int blockstep;//need to be even
#ifdef CONFIG_MPIXEL_SHIFT
	unsigned int CapLineSize = 0;
#endif
	//unsigned int TotalSize2 = 0;
	unsigned int burstLen = (Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)?_BURSTLENGTH2: _BURSTLENGTH);
	//Update the fifo depth for each IC @Crixus 20170418
#ifdef MERLIN_FIFO_DEPTH
	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
		burstLen=0xf0;
	}
#endif

	// [2D3D] multiple of allocated buffer size in 2D3D conversion mode
	unsigned int multiOf2D3DBuf = 1;
	unsigned int VO_MAX_FRC_SIZE=MDOMAIN_MAIN_BUFFER_SIZE; //using fixed memory size @Crixus 20160810
	unsigned int buffer_size = 0;
	unsigned int cap_temp = 0;
//	unsigned char lineRepeatEnable = FALSE;
	mdomain_cap_capture_byte_swap_RBUS capture_byte_swap_reg;
	mdomain_cap_main_sdnr_cxxto64_RBUS mdomain_cap_main_sdnr_cxxto64_reg;
	mdomain_cap_sub_sdnr_cxxto64_RBUS mdomain_cap_sub_sdnr_cxxto64_reg;
	mdomain_cap_cap_reg_doublbuffer_RBUS cap_reg_doublbuffer_reg;

#if 0//frank@0903 reduce scaler time,move below code to
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_ClearBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg: MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask);	// disable Capture
	IoReg_ClearBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_Cap_In2_enable_reg : MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);	// disable Capture
#else
	IoReg_ClearBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask); // disable Capture
	IoReg_ClearBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0); // disable Capture
#endif
	//frank@0503 add below delay to confirm M capture have disable
	msleep(20);
#endif

	if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY){
		//disable M-cap double buffer - main @Crixus 20160126
		cap_reg_doublbuffer_reg.regValue = rtd_inl(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
		cap_reg_doublbuffer_reg.cap1_db_en = 0;
		rtd_outl(MDOMAIN_CAP_cap_reg_doublbuffer_reg,cap_reg_doublbuffer_reg.regValue);
	}
#ifdef CONFIG_DUAL_CHANNEL
	else{
		//disable M-cap double buffer - sub @Crixus 20160126
		cap_reg_doublbuffer_reg.regValue = rtd_inl(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
		cap_reg_doublbuffer_reg.cap2_db_en = 0;
		rtd_outl(MDOMAIN_CAP_cap_reg_doublbuffer_reg,cap_reg_doublbuffer_reg.regValue);
	}
#endif
	//field polarity error check
	memory_check_capture_polarity_error(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL));
#if 0
	//20130905qiang_zhou:added for video delay frames for bluetooth+
	if(TRUE==get_delayframe_fuc())
	{
		delay_framebuffer_free();
		bDouble = FALSE;//go single buffer, when vgip end isr switch capture buffer(more than three)
	}
	//20130905qiang_zhou:added for video delay frames for bluetooth-
#endif

#ifdef CONFIG_DUAL_CHANNEL  /*SDNR output bit and sort format, new add in magellan2 @Crixus 20150330*/
	if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) { /*main channel*/
		mdomain_cap_main_sdnr_cxxto64_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Main_SDNR_cxxto64_reg);
		mdomain_cap_main_sdnr_cxxto64_reg.sort_fmt = (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) || (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) ||(!Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_422CAP))));
		mdomain_cap_main_sdnr_cxxto64_reg.out_bit = Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT);
		IoReg_Write32(MDOMAIN_CAP_Main_SDNR_cxxto64_reg, mdomain_cap_main_sdnr_cxxto64_reg.regValue);
	} else {
		mdomain_cap_sub_sdnr_cxxto64_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Sub_SDNR_cxxto64_reg);
		mdomain_cap_sub_sdnr_cxxto64_reg.sub_sort_fmt = (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) || (!Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_422CAP)));
		mdomain_cap_sub_sdnr_cxxto64_reg.sub_out_bit = Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT);
		IoReg_Write32(MDOMAIN_CAP_Sub_SDNR_cxxto64_reg, mdomain_cap_sub_sdnr_cxxto64_reg.regValue);
	}
#else
	mdomain_cap_main_sdnr_cxxto64_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Main_SDNR_cxxto64_reg);
	mdomain_cap_main_sdnr_cxxto64_reg.sort_fmt =  (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) || (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) ||(!Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_422CAP))));
	mdomain_cap_main_sdnr_cxxto64_reg.out_bit = Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT);
	IoReg_Write32(MDOMAIN_CAP_Main_SDNR_cxxto64_reg, mdomain_cap_main_sdnr_cxxto64_reg.regValue);
#endif

	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE))
		TotalSize = memory_get_capture_line_size_compression(dvrif_memory_get_compression_bits());//compression test
	else
		TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Cap_type);		// calculate the memory size of capture

	if(drvif_scaler3d_decide_3d_SG_data_FRC()) // [SG] SG 3D in data FRC mode -- sequence frame 3D L-R output control
	{
			TotalSize=TotalSize<<1;
	}

	if(Cap_type == MEMCAPTYPE_LINE){
		//printk("[2D3D] Rpt/Multi[%d/x%d], LineWidth/Size[%d/%d]\n", lineRepeatEnable, multiOf2D3DBuf, TotalSize, TotalSize*multiOf2D3DBuf);
		TotalSize *= multiOf2D3DBuf;
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
#ifdef CONFIG_I2RND_ENABLE
		//i2rnd sub-cap to VO, line step has to be 2-align @Crixus 20160728
		if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == SLR_SUB_DISPLAY) && (Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_DETECT_SOURCE)){
			total_line_size = drvif_memory_get_data_align(total_line_size, 2);	//sub=>vo, vo is align-2, so the line step should be align-2
			IoReg_Write32(MDOMAIN_CAP_DDR_In2LineStep_reg, (total_line_size + total_line_size%2) << 3);//bit 3 need to be 0. rbus rule
		}
		else{
			IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineStep_reg: MDOMAIN_CAP_DDR_In1LineStep_reg, (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule
		}
#else
		IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineStep_reg: MDOMAIN_CAP_DDR_In1LineStep_reg, (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule
#endif
		blockstep = (TotalSize*Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_CAP_LEN));
		blockstep = (blockstep % 2)? blockstep + 1: blockstep;
		IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2BlkStep_reg: MDOMAIN_CAP_DDR_In1BlkStep_reg, blockstep << 3);//bit 3 need to be 0. rbus rule
#else
		blockstep = (TotalSize*Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_CAP_LEN));
		blockstep = (blockstep % 2)? blockstep + 1: blockstep;
		IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineStep_reg : */MDOMAIN_CAP_DDR_In1LineStep_reg , (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule
		IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2BlkStep_reg : */MDOMAIN_CAP_DDR_In1BlkStep_reg, blockstep << 3);//bit 3 need to be 0. rbus rule
#endif
	}else{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineStep_reg: MDOMAIN_CAP_DDR_In1LineStep_reg, 0);
#else
		IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineStep_reg : */MDOMAIN_CAP_DDR_In1LineStep_reg, 0);
#endif
	}

	// [2D3D] line repeat mode FIFO length control
	TotalSize /= multiOf2D3DBuf;

//-	ScalerMemory_Printf("Cap Act wid=%x, Cap Act len=%x\n", Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID), Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN));
//-	ScalerMemory_Printf("\n Calculate FIFO Size !");
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF))
	{
		memory_division(TotalSize>>1, burstLen, &Quotient, &Remainder);	// Do a division
		Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_BLKSTEP,TotalSize>>1);
	}
	else
		memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division

	//printk("[Memory]WL=%x,Q=%x,Rm=%x\n", burstLen,Quotient,Remainder);
	if(dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == FALSE){
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_3D_3DTYPE) != SLR_3D_2D_ONLY))
		Remainder = drvif_memory_get_data_align(Remainder, 2);	// multiple of 4
	else
		Remainder = drvif_memory_get_data_align(Remainder, 4);	// multiple of 4
	}

	if (Remainder == 0) {	// remainder is not allowed to be zero
		Remainder = burstLen;
		Quotient -= 1;
	}

	//printk(KERN_EMERG"[crixus][%s]TotalSize = %d, Quotient = %d, Remainder = %d\n", __FUNCTION__,TotalSize, Quotient, Remainder);

	memory_set_capture_fifo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), Quotient, Remainder, burstLen);	// set capture FIFO

	TotalSize = SHL(Quotient * burstLen + Remainder, 3); //unit conversion. 64bits to 8bits

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF))
		TotalSize=TotalSize<<1;

	// [2D3D] line repeat mode buffer size control
	TotalSize *= multiOf2D3DBuf;
	//Not to allocate the disp size @Crixus 20151230
	//TotalSize1 = memory_get_capture_max_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Cap_type);

	if(drvif_scaler3d_decide_3d_SG_data_FRC()) // [SG] SG 3D in data FRC mode -- sequence frame 3D L-R output control
	{
		TotalSize1=TotalSize1<<1;
	}

	TotalSize1 = SHL(TotalSize1, 3); //unit conversion. 64bits to 8bits

	TotalSize1 *= multiOf2D3DBuf;

	if(Cap_type == MEMCAPTYPE_LINE){
		TotalSize1 *=Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_IPV_ACT_LEN_PRE);
		TotalSize *=Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_CAP_LEN);

		if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() &&
			(Scaler_Disp3dGetInfo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_3D_3DTYPE)==SLR_3D_SIDE_BY_SIDE_HALF) &&
			Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_INTERLACE))
		{
			TotalSize=TotalSize<<1;
			TotalSize1=TotalSize1<<1;
		}
	}
	//printk("[3D]TotalSize_ori= %x,TotalSize1_ori= %x,INPUT_CAP_LEN=%x, SG_FRC=%d\n", TotalSize,TotalSize1
//		,Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_CAP_LEN), drvif_scaler3d_decide_3d_SG_data_FRC());
	#ifdef CONFIG_MPIXEL_SHIFT
	if(Cap_type == MEMCAPTYPE_FRAME)
	{
		CapLineSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),MEMCAPTYPE_LINE);
		CapLineSize = SHL(CapLineSize, 3); //unit conversion. 64bits to 8bits
		TotalSize2 = SHL(CapLineSize ,6);  //pixeel shift 32 line up and down
	}
	#endif

	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY)	 {
#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
		if(TotalSize1 > TotalSize){
			TotalSize1 = (TotalSize1 - TotalSize);
		} else {
			TotalSize1 = 0;
		}

#ifdef CONFIG_I2RND_ENABLE
		if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC)){
			printk(KERN_EMERG"[I2RND][%s]Enter cap2 memory allocate\n", __FUNCTION__);
			buffer_size = MDOMAIN_MULTIVIEW_BUFFER_SIZE;
		}
		else{
			if(Scaler_I2rnd_get_enable() == _ENABLE){
				//i2rnd_default_allocate_mcap1();
				buffer_size = MDOMAIN_MULTIVIEW_BUFFER_SIZE;
			}
			else{
#endif
#ifdef CONFIG_ALL_SOURCE_DATA_FS
				Scaler_memory_setting_through_CMA();
#else
				if(dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))==_ENABLE) {
					#if 0//marked by qiangzhou for mac5p main only have compress, except magnifier
					//RGB444 mode use 24bits @Crixus 20160902
					if ((Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422CAP) == FALSE) && (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) > 3000))
						buffer_size = MDOMAIN_MAIN_BUFFER_SIZE_24BITS;
					else
					#endif
						buffer_size = MDOMAIN_MAIN_BUFFER_SIZE_12BITS;
				} else {/*qiangzhou:gamemode and livezoom not open compress mode now,
						so borrow di&rtnr memory,so video should not enter di&rtnr in this case*/
					if(Get_Live_zoom_mode()== LIVE_ZOOM_SUB)/*magnifier*/
						buffer_size = MDOMAIN_MAIN_BUFFER_SIZE_16BITS;
					else
						buffer_size = MDOMAIN_MAIN_BUFFER_SIZE_16BITS;
				}

				//Just for reserved memory 88M testing FIX ME
				MemTag[MEMIDX_MAIN_THIRD].StartAddr = get_query_start_address(QUERY_IDX_MDOMAIN_MAIN);//MDOMAIN_START_ADDRESS_KERNEL;
				MemTag[MEMIDX_MAIN_SEC].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_THIRD].StartAddr+buffer_size, (1 << 5));
				MemTag[MEMIDX_MAIN].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_SEC].StartAddr+buffer_size, (1 << 5));

				//16 bytes alignment
				MemTag[MEMIDX_MAIN_THIRD].StartAddr = MemTag[MEMIDX_MAIN_THIRD].StartAddr & 0x7ffffff0;
				MemTag[MEMIDX_MAIN_SEC].StartAddr = MemTag[MEMIDX_MAIN_SEC].StartAddr & 0x7ffffff0;
				MemTag[MEMIDX_MAIN].StartAddr = MemTag[MEMIDX_MAIN].StartAddr & 0x7ffffff0;

				//update multi-buffer start address @Crixus 20160913
				if(drv_memory_Get_multibuffer_flag()){
					printk(KERN_EMERG"[crixus]M-domain Multi-buffer Enable!!!\n");
					drv_memory_capture_multibuffer_update_addr(buffer_size, MemTag[MEMIDX_MAIN].StartAddr);
				}

				//free virtual memory
				drvif_memory_free_fixed_virtual_memory();
				//set virtual memory size
				buffer_size = PAGE_ALIGN(buffer_size);
				drvif_memory_set_fixed_virtual_memory_size(buffer_size);
				MemTag[MEMIDX_MAIN_THIRD].Allocate_StartAddr = MemTag[MEMIDX_MAIN_THIRD].StartAddr;
				MemTag[MEMIDX_MAIN_THIRD].Size = buffer_size;
				MemTag[MEMIDX_MAIN_THIRD].Status = ALLOCATED_FROM_PLI;

				MemTag[MEMIDX_MAIN_SEC].Allocate_StartAddr = MemTag[MEMIDX_MAIN_SEC].StartAddr;
				MemTag[MEMIDX_MAIN_SEC].Size = buffer_size;
				MemTag[MEMIDX_MAIN_SEC].Status = ALLOCATED_FROM_PLI;
				MemTag[MEMIDX_MAIN_SEC].Allocate_VirAddr = 0;//not use

				MemTag[MEMIDX_MAIN].Allocate_StartAddr = MemTag[MEMIDX_MAIN].StartAddr;
				MemTag[MEMIDX_MAIN].Size = buffer_size;
				MemTag[MEMIDX_MAIN].Status = ALLOCATED_FROM_PLI;
				MemTag[MEMIDX_MAIN].Allocate_VirAddr = 0;//not use

				//virtual memory allocation	and just use one buffer
				drvif_memory_set_memtag_virtual_startaddr((unsigned int)dvr_remap_uncached_memory(drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD), buffer_size, __builtin_return_address(0)));

				//M-domain start address
				IoReg_Write32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg, (MemTag[MEMIDX_MAIN_THIRD].StartAddr & 0x7ffffff0));
				IoReg_Write32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg, (MemTag[MEMIDX_MAIN_SEC].StartAddr & 0x7ffffff0));
				IoReg_Write32(MDOMAIN_CAP_DDR_In1Addr_reg, (MemTag[MEMIDX_MAIN].StartAddr & 0x7ffffff0));




				//M-domain boundary
				//update multi-buffer boundary @Crixus 20160913
				if(drv_memory_Get_multibuffer_flag()){
					drv_memory_capture_multibuffer_update_boundary(drv_memory_Get_multibuffer_number(), buffer_size);
				}
				else{

					IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,(MemTag[MEMIDX_MAIN_THIRD].StartAddr & 0x7ffffff0));
					IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,(MemTag[MEMIDX_MAIN].StartAddr+buffer_size-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
				}

				if(drvif_memory_get_memtag_startaddr(MEMIDX_MAIN) == 0x0){
					printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN));
				 	printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_SEC) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_SEC));
				 	printk(KERN_EMERG"[%s][%d]drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD) = 0x%x\n", __FUNCTION__, __LINE__, drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD));
				 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1Addr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1Addr_reg));
				 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1_2ndAddr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg));
				 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_DDR_In1_3rdAddr_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg));
				 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_CapMain_BoundaryAddr1_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg));
				 	printk(KERN_EMERG"[%s][%d]MDOMAIN_CAP_CapMain_BoundaryAddr2_reg = 0x%x\n", __FUNCTION__, __LINE__, IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg));
				}
#endif
#ifdef CONFIG_I2RND_ENABLE
			}
		}
#endif
#else

#ifndef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
		IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,AllocStartAddr);
		IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,AllocEndAddr-CONFIG_MDOMAIN_BURST_SIZE);
#endif
		// set capture memory for main display
		drvif_memory_free_block(MEMIDX_MAIN);	// free block befor getting a new one
		drvif_memory_free_block(MEMIDX_MAIN_SEC);	// free block befor getting a new one

		if ((Get_PANEL_VFLIP_ENABLE() && Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3)))
		{
			if(!bDouble)
				drvif_memory_free_block(MEMIDX_MAIN_THIRD);
		}
		else
		{
				drvif_memory_free_block(MEMIDX_MAIN_THIRD);	// free block befor getting a new one
		}
#ifdef ENABLE_3_BUFFER_DELAY_MODE
	drvif_memory_free_block(MEMIDX_MAIN_THIRD);
#endif

		if((TotalSize1 > TotalSize)/* &&
			((Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR_4x3) &&
			(Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1C12B) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1L7B))*/)
		{
			// MacArthur memory size limit (max frame size allocate only for SD video: data FRC path)
			/*if(((Scaler_InputSrcGetMainChType() == _SRC_VO) && (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) > REDUCE_DI_MEMORY_LIMIT_THRESHOLD))
				//||(get_mainsubonpr_fuc()==TRUE)
				||(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && drvif_scaelr3d_decide_is_3D_display_mode()))
			{
				TotalSize1 = 0;
			}
			else if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Scaler_Get3DMode((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)) != SLR_3DMODE_2D))
				TotalSize1 = 0;
			else*/
			TotalSize1 = (TotalSize1 - TotalSize);
		} else {
			TotalSize1 = 0;
		}
		//printk("memory_get_capture_max_size:TotalSize1 == %d\n",TotalSize1);

		//if(TRUE!=get_delayframe_fuc())
		{
#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
			if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>650) && (Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)==_CHANNEL1))
			{
				nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_THIRD, TotalSize+TotalSize1+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//space unit is byte
				MemTag[MEMIDX_MAIN_THIRD].StartAddr = nStartAddr;
				IoReg_Write32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg, nStartAddr & 0x7ffffff0);
			}
			else if(_ENABLE == Scaler_Get_Enable_3Buffer_NewRuleCondition())
			{
				if(_TRUE == Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
				{
					nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_THIRD, TotalSize+TotalSize1+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//space unit is byte
					MemTag[MEMIDX_MAIN_THIRD].StartAddr = nStartAddr;
					IoReg_Write32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg, nStartAddr & 0x7ffffff0);
				}
			}
#else //#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
		//M-3buf condition:
		// 1. [2D] M-capture frame rate > M-display frame rate
		// 2. [3D][SG] FRC in M-domain, M-display need repeat frame 2 times
		// 3. [3D][SG] SG 3D display free run need triple buffer to avoid frame tear
		// 4. [3D][PR] PR to SG 3D display timing FRC need enable triple buffer to avoid frame tear issue
		// 5. [3D][PR] frame packing video in PR 3D panel (TO BE FIXED)
		// 6. [VIP]film mode
		if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>650)|| drvif_scaler3d_decide_3d_SG_data_FRC()
				|| ((drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() == TRUE) && drvif_scaelr3d_decide_is_3D_display_mode())
				|| (Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE() && drvif_scaelr3d_decide_is_3D_display_mode())
				|| (modestate_get_pr3d_in_fp_3d_mode() && ((Scaler_InputSrcGetMainChType() == _SRC_VO)|| (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) >= 310)))
				||Get_vscFilmMode())
		{
			if(Scaler_InputSrcGetMainChType() == _SRC_VO){
				nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_THIRD, VO_MAX_FRC_SIZE, MEMALIGN_ANY);//space unit is byte
			} else {
				nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_THIRD, TotalSize+TotalSize1+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//space unit is byte
			}
			MemTag[MEMIDX_MAIN_THIRD].StartAddr = nStartAddr;
			IoReg_Write32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg, nStartAddr & 0x7ffffff0);
		}
#endif //#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
		}
#ifdef ENABLE_3_BUFFER_DELAY_MODE
		if(nStartAddr == 0){
			if(Scaler_InputSrcGetMainChType() == _SRC_VO){
				nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_THIRD, VO_MAX_FRC_SIZE, MEMALIGN_ANY);//space unit is byte
			}else {
				nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_THIRD, TotalSize+TotalSize1+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//space unit is byte
			}
			MemTag[MEMIDX_MAIN_THIRD].StartAddr = nStartAddr;
			IoReg_Write32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg, nStartAddr & 0x7ffffff0);
		}
#endif

		//printk("###################main buffer TotalSize=%d;;TotalSize1=%d;;TotalSize2=%d\n",TotalSize,TotalSize1,TotalSize2);
		if(bDouble) {
			if(Scaler_InputSrcGetMainChType() == _SRC_VO){
				nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_SEC, VO_MAX_FRC_SIZE, MEMALIGN_ANY);//space unit is byte
			}else {
				nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_SEC, TotalSize+TotalSize1 +TotalSize2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//space unit is byte
			}
			#ifdef CONFIG_MPIXEL_SHIFT
			memory_black_buf_init(TotalSize,nStartAddr);
			if (TotalSize2 > 0)
				nStartAddr += CapLineSize * 32;
			#endif
			MemTag[MEMIDX_MAIN_SEC].StartAddr = nStartAddr;
			IoReg_Write32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg, nStartAddr & 0x7ffffff0);
		}
#if 0
		//20130905qiang_zhou:added for video delay frames for bluetooth+
		if(TRUE==get_delayframe_fuc())
		{
			unsigned int buffernumber = get_delayframe_number();//get delay frame need buffer numbers
			unsigned int delayframeCachedAddr = delay_framebuffer_alloc(buffernumber*(TotalSize+TotalSize1+TotalSize2));
			set_delayframe_buffersize(TotalSize+TotalSize1+TotalSize2);
			nStartAddr = delayframeCachedAddr;
			IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,delayframeCachedAddr);
			IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,delayframeCachedAddr+buffernumber*(TotalSize+TotalSize1+TotalSize2));
		}
		else
#endif
		{
			if(Scaler_InputSrcGetMainChType() == _SRC_VO){
				nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN, VO_MAX_FRC_SIZE, MEMALIGN_ANY);//space unit is byte
			}else {
				nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN, TotalSize+TotalSize1+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//because space unit is byte
			}
		}
		//20130905qiang_zhou:added for video delay frames for bluetooth-
		#ifdef CONFIG_MPIXEL_SHIFT
		memory_black_buf_init(TotalSize,nStartAddr);

		if (TotalSize2 > 0)
			nStartAddr += CapLineSize * 32;

		#endif

		MemTag[MEMIDX_MAIN].StartAddr = nStartAddr;

		IoReg_Write32(MDOMAIN_CAP_DDR_In1Addr_reg, nStartAddr & 0x7ffffff0);
		//printk("After %s--%d  IoReg_Read32(MDOMAIN_CAP_DDR_In1LineStep_reg)=%x\n",__FUNCTION__,__LINE__,IoReg_Read32(MDOMAIN_CAP_DDR_In1LineStep_reg));
#endif
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else {

		//if((Get_Live_zoom_mode() == LIVE_ZOOM_OFF )||
			//((Get_Live_zoom_mode() != LIVE_ZOOM_OFF )&&(Get_Magnifier_LiveZoom_Mode()==VSC_SUB_PURPOSE_MAGNIFIER))){

//sub use reserved memory on mac5p @Crixus 20170505
#ifdef CONFIG_MDOMAIN_RESERVED_MEMORY
			//sub use cap max size @Crixus 20151231
			buffer_size = MDOMAIN_SUB_BUFFER_SIZE;//for APVR and magnifier case

			//Just for reserved memory 88M testing FIX ME
			MemTag[MEMIDX_SUB_THIRD].StartAddr = get_query_start_address(QUERY_IDX_MDOMAIN_SUB);
			MemTag[MEMIDX_SUB_SEC].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_SUB_THIRD].StartAddr+buffer_size, (1 << 5));
			MemTag[MEMIDX_SUB].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_SUB_SEC].StartAddr+buffer_size, (1 << 5));

			//16 bytes alignment
			MemTag[MEMIDX_SUB_THIRD].StartAddr = MemTag[MEMIDX_SUB_THIRD].StartAddr & 0x7ffffff0;
			MemTag[MEMIDX_SUB_SEC].StartAddr = MemTag[MEMIDX_SUB_SEC].StartAddr & 0x7ffffff0;
			MemTag[MEMIDX_SUB].StartAddr = MemTag[MEMIDX_SUB].StartAddr & 0x7ffffff0;

			MemTag[MEMIDX_SUB_THIRD].Allocate_StartAddr = MemTag[MEMIDX_SUB_THIRD].StartAddr;
			MemTag[MEMIDX_SUB_THIRD].Size = buffer_size;
			MemTag[MEMIDX_SUB_THIRD].Status = ALLOCATED_FROM_PLI;
			MemTag[MEMIDX_SUB_THIRD].Allocate_VirAddr = 0;//not use

			MemTag[MEMIDX_SUB_SEC].Allocate_StartAddr = MemTag[MEMIDX_SUB_SEC].StartAddr;
			MemTag[MEMIDX_SUB_SEC].Size = buffer_size;
			MemTag[MEMIDX_SUB_SEC].Status = ALLOCATED_FROM_PLI;
			MemTag[MEMIDX_SUB_SEC].Allocate_VirAddr = 0;//not use

			MemTag[MEMIDX_SUB].Allocate_StartAddr = MemTag[MEMIDX_SUB].StartAddr;
			MemTag[MEMIDX_SUB].Size = buffer_size;
			MemTag[MEMIDX_SUB].Status = ALLOCATED_FROM_PLI;
			MemTag[MEMIDX_SUB].Allocate_VirAddr = 0;//not use

			//M-domain start address
			IoReg_Write32(MDOMAIN_CAP_DDR_In2_3rdAddr_reg, (MemTag[MEMIDX_SUB_THIRD].StartAddr & 0x7ffffff0));
			IoReg_Write32(MDOMAIN_CAP_DDR_In2_2ndAddr_reg, (MemTag[MEMIDX_SUB_SEC].StartAddr & 0x7ffffff0));
			IoReg_Write32(MDOMAIN_CAP_DDR_In2Addr_reg, (MemTag[MEMIDX_SUB].StartAddr & 0x7ffffff0));
			//M-domain boundary
			IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr1_reg,(MemTag[MEMIDX_SUB_THIRD].StartAddr & 0x7ffffff0));
			IoReg_Write32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg,(MemTag[MEMIDX_SUB].StartAddr+buffer_size) & 0x7ffffff0);
#else
		//}else {
	//-		ScalerMemory_Printf("\n Allocate Sub Disp Memory !\n");
			// set capture memory for sub display
			drvif_memory_free_block(MEMIDX_SUB);	// free block befor getting a new one
			drvif_memory_free_block(MEMIDX_SUB_SEC);	// free block befor getting a new one
			drvif_memory_free_block(MEMIDX_SUB_THIRD);	// free block befor getting a new one
			//sub use cap max size @Crixus 20151231
			buffer_size = MDOMAIN_SUB_BUFFER_SIZE;
		#ifdef ENABLE_3_BUFFER_DELAY_MODE
				//I2rnd mode s-cap use 2-buffer
				nStartAddr = drvif_memory_alloc_block(MEMIDX_SUB_THIRD, buffer_size, MEMALIGN_ANY);//space unit is byte
				MemTag[MEMIDX_SUB_THIRD].StartAddr = nStartAddr;
				IoReg_Write32(MDOMAIN_CAP_DDR_In2_3rdAddr_reg, nStartAddr & 0x7ffffff0);
			//}
		#endif

			if(bDouble)
			{
				IoReg_Write32(MDOMAIN_CAP_DDR_In2_2ndAddr_reg, drvif_memory_alloc_block(MEMIDX_SUB_SEC,buffer_size, MEMALIGN_ANY) & 0x7ffffff0);
			}

			IoReg_Write32(MDOMAIN_CAP_DDR_In2Addr_reg, drvif_memory_alloc_block(MEMIDX_SUB, buffer_size, MEMALIGN_ANY) & 0x7ffffff0);
			pr_debug("###################sub buffer TotalSize=%d;;\n", buffer_size);
	//-		ScalerMemory_Printf("Get allocated sub display addr1=%x, addr2=%x, size=%x\n", StartAddr, StartAddr1, TotalSize);
		//}
#endif
	}
#endif
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	if(drvif_scaler3d_decide_3d_SG_data_FRC()){ // [SG] SG 3D in data FRC mode -- sequence frame 3D L-R output control
		IoReg_Mask32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineNum_reg : MDOMAIN_CAP_DDR_In1LineNum_reg, 0xfffee000, (Cap_type<<16)|AND(2*Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN), 0x1FFF));
	} // [3D][PR] When PR SBS 3D mode IN1_SBS_VSD_EN=1, the line number = L+R
	else if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF)){
		IoReg_Mask32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineNum_reg : MDOMAIN_CAP_DDR_In1LineNum_reg, 0xfffee000, (Cap_type<<16)|AND(2*Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN), 0x1FFF));
	}else
		IoReg_Mask32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineNum_reg : MDOMAIN_CAP_DDR_In1LineNum_reg, 0xfffee000, (Cap_type<<16)|AND(Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN), 0x1FFF));
#else
	if(drvif_scaler3d_decide_3d_SG_data_FRC()){ // [SG] SG 3D in data FRC mode -- sequence frame 3D L-R output control
		IoReg_Mask32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineNum_reg : */MDOMAIN_CAP_DDR_In1LineNum_reg, 0xfffee000, (Cap_type<<16)|AND(2*Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN), 0x1FFF));
	} // [3D][PR] When PR SBS 3D mode IN1_SBS_VSD_EN=1, the line number = L+R
	else if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF)){
		IoReg_Mask32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineNum_reg : */MDOMAIN_CAP_DDR_In1LineNum_reg, 0xfffee000, (Cap_type<<16)|AND(2*Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN), 0x1FFF));
	}else
		IoReg_Mask32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineNum_reg : */MDOMAIN_CAP_DDR_In1LineNum_reg, 0xfffee000, (Cap_type<<16)|AND(Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN), 0x1FFF));
#endif
	//cap ctrl default setting
#ifdef CONFIG_I2RND_ENABLE
	if((Scaler_I2rnd_get_enable() == _ENABLE) && ((Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY)))
		cap_temp = cap_temp;
	else
#endif
		cap_temp = cap_temp | _BIT25 | _BIT28;

	if(Get_vscFilmMode()==TRUE)//go single hw buffer
	{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | cap_temp);
#else
		IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | cap_temp);
#endif
	}
	else
	{
		if (Get_PANEL_VFLIP_ENABLE())
		{
			if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3)
				|| (drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() == TRUE)|| drvif_scaler3d_decide_3d_SG_data_FRC())
			{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
				IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | (bDouble ? MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask : 0) | MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask | cap_temp);
#else
				IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | (bDouble ? MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask : 0) | MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask | cap_temp);
#endif
			}// [3D] PR to SG 3D panel, display timing FRC need enable triple buffer in VO source (vFlip in VO)
			else if(Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE() && drvif_scaelr3d_decide_is_3D_display_mode()){
				IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | (bDouble ? MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask : 0) | MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask | cap_temp);
			}else
			{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
				IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | (bDouble ? MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask : 0) | cap_temp);
#else
				IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | (bDouble ? MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask : 0) | cap_temp);
#endif
			}
		}
		else
		{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
			IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | (bDouble ? MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask : 0) | cap_temp);
#else
			IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | (bDouble ? MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask : 0) | cap_temp);
#endif

			//if(TRUE!=get_delayframe_fuc())
			{
#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
				if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ)>650) && (Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)==_CHANNEL1))
				{
					IoReg_SetBits(MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask);
				}
				else if(_ENABLE == Scaler_Get_Enable_3Buffer_NewRuleCondition())
				{
					if(_TRUE == Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
					{
						IoReg_SetBits(MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask);
					}
				}
#else //#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
			//M-3buf condition:
			// 1. [2D] M-capture frame rate > M-display frame rate
			// 2. [2Dcvt3D][SG] FRC in M-domain, M-display need repeat frame 2 times
			// 3. [3D][SG] SG 3D display free run need triple buffer to avoid frame tear
			// 4. [3D][PR] PR to SG 3D display timing FRC need enable triple buffer to avoid frame tear issue
			// 5. [3D][PR] frame packing video in PR 3D panel (TO BE FIXED)
			if((Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) > 650)|| drvif_scaler3d_decide_3d_SG_data_FRC()
					|| (drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() && drvif_scaelr3d_decide_is_3D_display_mode())
					|| (Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE() && drvif_scaelr3d_decide_is_3D_display_mode())
					|| (modestate_get_pr3d_in_fp_3d_mode() && ((Scaler_InputSrcGetMainChType() == _SRC_VO)|| (Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ) >= 310))))
			{
				IoReg_SetBits(MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask);
			}
#endif //#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
			}
		}
	}
#ifdef ENABLE_3_BUFFER_DELAY_MODE
	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY){
		IoReg_SetBits(MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask);
	}
#ifdef CONFIG_DUAL_CHANNEL
	else{
#ifdef CONFIG_I2RND_ENABLE
		if(Scaler_I2rnd_get_enable() == _ENABLE)
			IoReg_ClearBits(MDOMAIN_CAP_DDR_In2Ctrl_reg, _BIT8);
		else
#endif
			IoReg_SetBits(MDOMAIN_CAP_DDR_In2Ctrl_reg, _BIT8);
		//else
			//IoReg_ClearBits(MDOMAIN_CAP_DDR_In2Ctrl_reg, _BIT8);
	}
#endif
#endif
#ifdef CONFIG_I2RND_ENABLE
	//I2rnd enable M-cap2 block @Crixus 20160721
	if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC)){
		//unsigned int cap_setting = IoReg_Read32(MDOMAIN_CAP_DDR_In1Ctrl_reg);
		cap_temp = cap_temp | _BIT6 | _BIT8;
		IoReg_Write32(MDOMAIN_CAP_DDR_In1subCtrl_reg, cap_temp);
	}
#endif
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE())
	{
		mdomain_cap_capmain_sbs_vsd_cap_ctrl_RBUS capmain_sbs_vsd_cap_ctrl_reg;
		mdomain_cap_capmain_sbs_vsd_cap_offset_RBUS capmain_sbs_vsd_cap_offset_reg;
		mdomain_cap_ddr_in1ctrl_RBUS ddr_in1ctrl_reg;

		capmain_sbs_vsd_cap_ctrl_reg.regValue = IoReg_Read32(MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_reg);
		capmain_sbs_vsd_cap_offset_reg.regValue = IoReg_Read32(MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg);
		ddr_in1ctrl_reg.regValue = IoReg_Read32(MDOMAIN_CAP_DDR_In1Ctrl_reg);

		if(Scaler_Disp3dGetInfo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_3D_3DTYPE)==SLR_3D_SIDE_BY_SIDE_HALF)
		{
			capmain_sbs_vsd_cap_ctrl_reg.in1_sbs_vsd_en = 1;
			capmain_sbs_vsd_cap_offset_reg.in1_lr_offset = Scaler_Disp3dGetInfo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_3D_BLKSTEP);
		}
		else
		{
			capmain_sbs_vsd_cap_ctrl_reg.in1_sbs_vsd_en = 0;
			capmain_sbs_vsd_cap_offset_reg.in1_lr_offset = 0;
		}
		IoReg_Write32(MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_reg, capmain_sbs_vsd_cap_ctrl_reg.regValue);
		IoReg_Write32(MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg, capmain_sbs_vsd_cap_offset_reg.regValue);

		if((Scaler_Disp3dGetInfo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING) && ((Scaler_InputSrcGetMainChType()==_SRC_HDMI) || (Scaler_InputSrcGetMainChType()==_SRC_VO)))
			ddr_in1ctrl_reg.in1_rm_r_vs_en = 1;
		else
			ddr_in1ctrl_reg.in1_rm_r_vs_en = 0;
		ddr_in1ctrl_reg.in1_l_flag_inv = 0;
		IoReg_Write32(MDOMAIN_CAP_DDR_In1Ctrl_reg, ddr_in1ctrl_reg.regValue);
	}
#ifdef ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE // SG 3D PANEL SUPPORT ALL SOURCE 3D MODE
	else if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == FALSE)
		&& (Scaler_Disp3dGetInfo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING) && (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
	{
		mdomain_cap_ddr_in1ctrl_RBUS ddr_in1ctrl_reg;
		ddr_in1ctrl_reg.regValue = IoReg_Read32(MDOMAIN_CAP_DDR_In1Ctrl_reg);
		ddr_in1ctrl_reg.in1_rm_r_vs_en = 1;
		IoReg_Write32(MDOMAIN_CAP_DDR_In1Ctrl_reg, ddr_in1ctrl_reg.regValue);
	}
#endif
	//frank@03132013 add below code for GPU access YUV format ++
	capture_byte_swap_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Capture_byte_swap_reg);
	if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)){
		if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),SLR_DISP_422CAP))
		{
			capture_byte_swap_reg.in2_1byte_swap = 0;
			capture_byte_swap_reg.in2_2byte_swap = 1;
			capture_byte_swap_reg.in2_4byte_swap = 1;
			capture_byte_swap_reg.in2_8byte_swap = 0;
		}
		else
		{
			capture_byte_swap_reg.in2_1byte_swap = 1;
			capture_byte_swap_reg.in2_2byte_swap = 1;
			capture_byte_swap_reg.in2_4byte_swap = 1;
			capture_byte_swap_reg.in2_8byte_swap = 0;
		}
	}else{
		if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),SLR_DISP_10BIT))
		{
			capture_byte_swap_reg.in1_1byte_swap = 0;
			capture_byte_swap_reg.in1_2byte_swap = 0;
			capture_byte_swap_reg.in1_4byte_swap = 0;
			capture_byte_swap_reg.in1_8byte_swap = 0;

		}
		else
		{
			if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL),SLR_DISP_422CAP))
			{
				capture_byte_swap_reg.in1_1byte_swap = 0;
				capture_byte_swap_reg.in1_2byte_swap = 1;
				capture_byte_swap_reg.in1_4byte_swap = 1;
				capture_byte_swap_reg.in1_8byte_swap = 0;
			}
			else
			{
				capture_byte_swap_reg.in1_1byte_swap = 1;
				capture_byte_swap_reg.in1_2byte_swap = 1;
				capture_byte_swap_reg.in1_4byte_swap = 1;
				capture_byte_swap_reg.in1_8byte_swap = 0;
			}
		}
	}
	IoReg_Write32(MDOMAIN_CAP_Capture_byte_swap_reg, capture_byte_swap_reg.regValue);
	//frank@03132013 add below code for GPU access YUV format --
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_SetBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_Cap_In2_enable_reg : MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);
#else
	IoReg_SetBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);
#endif
	if (Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) {
		/*wclr cap buf done status*/
		mdomain_cap_cap_ddr_fifostatus_RBUS cap_ddr_fifostatus_reg;
		cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
		cap_ddr_fifostatus_reg.in1_cap_last_wr_flag = 1;
		IoReg_Write32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg, cap_ddr_fifostatus_reg.regValue);
	} else {
		mdomain_cap_cap_ddr_fifostatus_RBUS cap_ddr_fifostatus_reg;
		cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
		cap_ddr_fifostatus_reg.in2_cap_last_wr_flag = 1;
		IoReg_Write32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg, cap_ddr_fifostatus_reg.regValue);
	}
}

/*============================================================================*/
/**
 * MemSetCapture
 * Set memory capture registers. It can be #1 or #2, based on current info structure
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 */
void jpeg_memory_alloc_capture2(eMemCapAccessType Cap_type,eMemIdx idx)
{
	unsigned int  TotalSize;
	unsigned int  TotalSize1;
	unsigned int  nStartAddr;
	unsigned int  Quotient;
	unsigned char  Remainder;
	unsigned int burstLen = (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)?_BURSTLENGTH2: _BURSTLENGTH);

	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
		burstLen=0xf0;
	}

	TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Cap_type);		// calculate the memory size of capture
	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division
	Remainder = drvif_memory_get_data_align(Remainder, 4);	// multiple of 4
	if (Remainder == 0) {	// remainder is not allowed to be zero
		Remainder = burstLen;
		Quotient -= 1;
	}

	TotalSize = SHL(Quotient * burstLen + Remainder, 3); //unit conversion. 64bits to 8bits

	TotalSize1 = memory_get_capture_max_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Cap_type);

	TotalSize1 = SHL(TotalSize1, 3); //unit conversion. 64bits to 8bits

	if(Cap_type == MEMCAPTYPE_LINE){
		TotalSize1 *=Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_IPV_ACT_LEN_PRE);
		TotalSize *=Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_CAP_LEN);
	}


	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY)	 {
		// set capture memory for main display
		if((TotalSize1 > TotalSize) &&
			((Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR_4x3) &&
			(Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1C12B) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1L7B)))
			TotalSize1 = (TotalSize1 - TotalSize);
		else
			TotalSize1 = 0;


		nStartAddr = drvif_memory_alloc_block(idx, TotalSize+TotalSize1+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//space unit is byte
		//printk("[JPEG] %s MemTag[MEMIDX_SUB].StartAddr=%x\n",__FUNCTION__,nStartAddr);
	}
}
void jpeg_memory_free_capture2(void)
{
	drvif_memory_free_block(MEMIDX_SUB);
}

void zoom_memory_set_capture(unsigned char bDouble, eMemCapAccessType Cap_type, unsigned char buffernum)
{
	unsigned int  TotalSize;
	unsigned int  TotalSize1;
//	unsigned int  TotalSizeFrame;
	unsigned int  nStartAddr;
	unsigned int  Quotient;
	unsigned char  Remainder;
	unsigned int blockstep;//need to be even
	//unsigned int multiOf2D3DBuf = 1;
	mdomain_cap_capture_byte_swap_RBUS capture_byte_swap_reg;
	unsigned int burstLen = (Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)?_BURSTLENGTH2: _BURSTLENGTH);

	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
		burstLen=0xf0;
	}

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_ClearBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg: MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask);	// disable Capture
	IoReg_ClearBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_Cap_In2_enable_reg : MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);	// disable Capture
#else
	IoReg_ClearBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask); // disable Capture
	IoReg_ClearBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0); // disable Capture
#endif
	//frank@0503 add below delay to confirm M capture have disable
	msleep(20);

	//field polarity error check
	memory_check_capture_polarity_error(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL));


	TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Cap_type);		// calculate the memory size of capture
	if(Cap_type == MEMCAPTYPE_LINE){
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineStep_reg: MDOMAIN_CAP_DDR_In1LineStep_reg , (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule
		blockstep = (TotalSize*Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_CAP_LEN));
		blockstep = (blockstep % 2)? blockstep + 1: blockstep;
		IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2BlkStep_reg: MDOMAIN_CAP_DDR_In1BlkStep_reg, blockstep << 3);
#else
		IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineStep_reg : */MDOMAIN_CAP_DDR_In1LineStep_reg , (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule
		blockstep = (TotalSize*Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_CAP_LEN));
		blockstep = (blockstep % 2)? blockstep + 1: blockstep;
		IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2BlkStep_reg : */MDOMAIN_CAP_DDR_In1BlkStep_reg, blockstep << 3);
#endif

	}else{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineStep_reg: MDOMAIN_CAP_DDR_In1LineStep_reg, 0);
#else
		IoReg_Write32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineStep_reg : */MDOMAIN_CAP_DDR_In1LineStep_reg, 0);
#endif
	}
//-	ScalerMemory_Printf("Cap Act wid=%x, Cap Act len=%x\n", Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID), Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN));
//-	ScalerMemory_Printf("\n Calculate FIFO Size !");
	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division
	Remainder = drvif_memory_get_data_align(Remainder, 4);	// multiple of 4
	if (Remainder == 0) {	// remainder is not allowed to be zero
		Remainder = burstLen;
		Quotient -= 1;
	}
	pr_debug("[ZOOM][Memory]WL=%x,Q=%x,Rm=%x\n", burstLen,Quotient,Remainder);
	memory_set_capture_fifo(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), Quotient, Remainder, burstLen);	// set capture FIFO

	TotalSize = SHL(Quotient * burstLen + Remainder, 3); //unit conversion. 64bits to 8bits

	TotalSize1 = memory_get_capture_max_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Cap_type);

	TotalSize1 = SHL(TotalSize1, 3); //unit conversion. 64bits to 8bits

	if(Cap_type == MEMCAPTYPE_LINE){
		TotalSize1 *=Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_IPV_ACT_LEN_PRE);
		TotalSize *=Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_CAP_LEN);
	}

	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY)	 {
		if (buffernum)
			drvif_memory_free_block(MEMIDX_MAIN_SEC);	// free block befor getting a new one
		else
			drvif_memory_free_block(MEMIDX_MAIN);

		if((TotalSize1 > TotalSize) &&
			((Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR_4x3) &&
			(Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1C12B) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1L7B)))
			TotalSize1 = (TotalSize1 - TotalSize);
		else
		{
			pr_debug("TOTAL SIZE1 == 0\n");
			TotalSize1 = 0;
		}

		if(bDouble) {
			//nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_SEC, TotalSize+TotalSize1, MEMALIGN_ANY);//space unit is byte
			//MemTag[MEMIDX_MAIN_SEC].StartAddr = nStartAddr;
			//IoReg_Write32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg, nStartAddr & 0x7ffffff0);
		}


		if (buffernum)
			nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_SEC, TotalSize+TotalSize1+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//space unit is byte
		else
			nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN, TotalSize+TotalSize1+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//space unit is byte

		if (bDouble)
		{
			if (buffernum)
				MemTag[MEMIDX_MAIN_SEC].StartAddr = nStartAddr;
			else
				MemTag[MEMIDX_MAIN].StartAddr = nStartAddr;
			IoReg_Write32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg, nStartAddr & 0x7ffffff0);
		}
		else
		{

			if (buffernum)
				MemTag[MEMIDX_MAIN_SEC].StartAddr = nStartAddr;
			else
				MemTag[MEMIDX_MAIN].StartAddr = nStartAddr;

			IoReg_Write32(MDOMAIN_CAP_DDR_In1Addr_reg, nStartAddr & 0x7ffffff0);

			//printk("After %s--%d  IoReg_Read32(MDOMAIN_CAP_DDR_In1LineStep_reg)=%x\n",__FUNCTION__,__LINE__,IoReg_Read32(MDOMAIN_CAP_DDR_In1LineStep_reg));
		}
	}

	//frank@03132013 add below code for GPU access YUV format ++
	capture_byte_swap_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Capture_byte_swap_reg);
	if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)){
		//Crixus@20140722 - Mac3 no in2
		//capture_byte_swap_reg.in2_2byte_swap = 1;
		//capture_byte_swap_reg.in2_4byte_swap = 1;
	}else{
		capture_byte_swap_reg.in1_2byte_swap = 1;
		capture_byte_swap_reg.in1_4byte_swap = 1;
	}
	IoReg_Write32(MDOMAIN_CAP_Capture_byte_swap_reg, capture_byte_swap_reg.regValue);
	//frank@03132013 add below code for GPU access YUV format --

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_Mask32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineNum_reg: MDOMAIN_CAP_DDR_In1LineNum_reg, 0xfffee000, (Cap_type<<16)|AND(Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN), 0x1FFF));
	//IoReg_Write32(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | (bDouble ? MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask : 0));
	IoReg_SetBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)?MDOMAIN_CAP_DDR_In2Ctrl_reg:MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | (bDouble ? MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask : 0));
	IoReg_SetBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_Cap_In2_enable_reg: MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);
#else
	IoReg_Mask32(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2LineNum_reg : */MDOMAIN_CAP_DDR_In1LineNum_reg, 0xfffee000, (Cap_type<<16)|AND(Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN), 0x1FFF));
	IoReg_SetBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0 | (bDouble ? MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask : 0));
	IoReg_SetBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);
#endif


	//drvif_memory_3D_mode_sw_buffer_swap_action((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEM_3D_SWBUFFER_SWAP_UPDATE_INFO);
}

void memory_set_vflip_capture(unsigned char bVflip, eMemCapAccessType Cap_type)
{

	unsigned int  TotalSize;
	unsigned int  TotalSize1;
//	unsigned int  TotalSizeFrame;
	unsigned int  nStartAddr;
	unsigned int  Quotient;
	unsigned char  Remainder;
	//unsigned int multiOf2D3DBuf = 1;
	unsigned int burstLen = (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)?_BURSTLENGTH2: _BURSTLENGTH);
	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
		burstLen=0xf0;
	}

	TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Cap_type);		// calculate the memory size of capture


	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division
	Remainder = drvif_memory_get_data_align(Remainder, 4);	// multiple of 4
	if (Remainder == 0) {	// remainder is not allowed to be zero
		Remainder = burstLen;
		Quotient -= 1;
	}


	TotalSize = SHL(Quotient * burstLen + Remainder, 3); //unit conversion. 64bits to 8bits

	TotalSize1 = memory_get_capture_max_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), Cap_type);

	TotalSize1 = SHL(TotalSize1, 3); //unit conversion. 64bits to 8bits

	if(Cap_type == MEMCAPTYPE_LINE){
		TotalSize1 *=Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_IPV_ACT_LEN_PRE);
		TotalSize *=Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_CAP_LEN);
	}


		if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY)	 {

			drvif_memory_free_block(MEMIDX_MAIN_THIRD);	// free block befor getting a new one

			if((TotalSize1 > TotalSize) &&
				((Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR_4x3) &&
				(Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1C12B) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1L7B)))
				TotalSize1 = (TotalSize1 - TotalSize);
			else
				TotalSize1 = 0;

			if(bVflip) {
				nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_THIRD, TotalSize+TotalSize1+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);//space unit is byte
				MemTag[MEMIDX_MAIN_THIRD].StartAddr = nStartAddr;
				IoReg_Write32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg, nStartAddr & 0x7ffffff0);
			}

		}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
		else {
	//-		ScalerMemory_Printf("\n Allocate Sub Disp Memory !\n");
			// set capture memory for sub display
			drvif_memory_free_block(MEMIDX_SUB_THIRD);	// free block befor getting a new one

			if(bVflip)
				IoReg_Write32(MDOMAIN_CAP_DDR_In2_3rdAddr_reg, drvif_memory_alloc_block(MEMIDX_SUB_THIRD,TotalSize+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY) & 0x7ffffff0);
	//-		ScalerMemory_Printf("Get allocated sub display addr1=%x, addr2=%x, size=%x\n", StartAddr, StartAddr1, TotalSize);
		}
#endif

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_SetBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask);
#else
	IoReg_SetBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask);
#endif

}


//(original  block address / 8 ) + (line size *  (line number - 1) ) )*8
static unsigned int memory_cal_vflip_block_addr(unsigned int address, unsigned int linesize , unsigned int linenum)
{
	return ((address >> 3) + (linesize * (linenum - 1)) )<< 3;
}

static void MemSetDisplayVFLIPAddr(unsigned char display, unsigned int Addr1, unsigned int Addr2, unsigned int Addr3)
{
	unsigned int address = 0;

	if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY){
	//frank@0617 mark below code to speed up
	//	dvrif_memory_set_addr_check(SLR_MAIN_DISPLAY, _TRUE);
		IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg,Addr1&0x7ffffff0);
        	IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg,Addr2&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg,Addr3&0x7ffffff0);

		//update m_disp boundary the same as m_cap boundary @Crixus 20171227
		address = IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg);
		IoReg_Write32(MDOMAIN_DISP_DispMain_BoundaryAddr1_reg, address&0x7ffffff0);
		address = IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg);
		IoReg_Write32(MDOMAIN_DISP_DispMain_BoundaryAddr2_reg, address&0x7ffffff0);
	}
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else{
		IoReg_Write32(MDOMAIN_DISP_DDR_SubAddr_reg, Addr1&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Sub2ndAddr_reg, Addr2&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Sub3rdAddr_reg,Addr3&0x7ffffff0);

		//update m_disp boundary the same as m_cap boundary @Crixus 20171227
		address = IoReg_Read32(MDOMAIN_CAP_CapSub_BoundaryAddr1_reg);
		IoReg_Write32(MDOMAIN_DISP_DispSub_BoundaryAddr1_reg, address&0x7ffffff0);
		address = IoReg_Read32(MDOMAIN_CAP_CapSub_BoundaryAddr2_reg);
		IoReg_Write32(MDOMAIN_DISP_DispSub_BoundaryAddr2_reg, address&0x7ffffff0);
	}
#endif
}



static void memory_set_vflip_main(unsigned char bVflip)
{
	unsigned int TotalSize;
//	unsigned int  TotalSizeFrame=0;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int ucStartAddress;
	unsigned int ucStartAddress2;
        unsigned int ucStartAddress3 = 0;
	unsigned int LineStep;
	unsigned int fifoLen = (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)?_FIFOLENGTH2: _FIFOLENGTH);
	unsigned int burstLen = (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)?_BURSTLENGTH2: _BURSTLENGTH);
	UINT32 MemShiftAddr = 0;
	UINT16 droppixel = 0;
	StructSrcRect m_dispwin;
	mdomain_disp_ddr_mainprevstart_RBUS ddr_mainprevstart_reg;
	unsigned int  Align_LineStep;
	unsigned int comp_width = 0;
	//Update the fifo depth for each IC @Crixus 20170418
#ifdef MERLIN_FIFO_DEPTH
	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
		burstLen=0xf0;
	}
#endif
	m_dispwin = Scaler_DispWindowGet();
	ddr_mainprevstart_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainPreVStart_reg);
	if(m_dispwin.srcy <= 100) {
		ddr_mainprevstart_reg.main_pre_rd_v_start = 7;
	} else {
		ddr_mainprevstart_reg.main_pre_rd_v_start = (m_dispwin.srcy-10);
	}
	IoReg_Write32(MDOMAIN_DISP_DDR_MainPreVStart_reg, ddr_mainprevstart_reg.regValue);

	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddrDropBits_reg,0x0);
	//frank@0323 change waterlevel/2 for AT,because water level nit is 128 bits

	pr_debug("[vFlip] mem info %d %d %d %d\n",Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));

	if ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA) == 0) && (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) == 0) )
	{
		if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE)){
			comp_width = Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID);
			if((comp_width % 32) != 0)
				comp_width = comp_width + (32 - (comp_width % 32));
			IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, (((comp_width * dvrif_memory_get_compression_bits() / 32) & 0x0fFF) << 8) | ((fifoLen-(burstLen>>1))>>1));
			TotalSize = memory_get_capture_line_size_compression(dvrif_memory_get_compression_bits());
		}
		else{

			IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) & 0x0fFF) << 8) | ((fifoLen-(burstLen>>1))>>1));
			TotalSize = memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));	// calculate the memory size of capture
		}
	}
	else
	{
		MemGetBlockShiftAddr(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);
		TotalSize = memory_get_disp_line_size1(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) + droppixel);	// calculate the memory size of capture
		IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, (( ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) +droppixel) & 0x0fFF) << 8) | ((fifoLen-(burstLen>>1))>>1)));
		pr_debug("[vFlip] drop pixel=%d shift addr=%x\n",droppixel,MemShiftAddr);

	}

	pr_debug("[crixus][v-flip]TotalSize = %d\n", TotalSize);



        IoReg_Mask32(MDOMAIN_DISP_DDR_MainLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));
		memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division

	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Write32(MDOMAIN_DISP_DDR_MainRdNumLenRem_reg, (Quotient << 16) | (burstLen << 8) | Remainder);

	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE))
		TotalSize = memory_get_capture_line_size_compression(dvrif_memory_get_compression_bits());
	else
		TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEMCAPTYPE_LINE);		// calculate capture line size

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF))
		TotalSize=TotalSize>>1;

	LineStep = TotalSize;
	pr_debug("[vFlip]line step=0x%x\n",LineStep);

	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits
	Align_LineStep = LineStep;
	Align_LineStep = (Align_LineStep % 2) ? (Align_LineStep + 1) : Align_LineStep;

	printk(KERN_EMERG"[crixus][v-flip]Align_LineStep = 0x%x", (((~Align_LineStep) + 1) << 3));

    IoReg_Write32(MDOMAIN_DISP_DDR_MainLineStep_reg, ((~Align_LineStep) + 1) << 3);//bit 3 need to be 0. rbus rule

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()
		&& ((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_SIDE_BY_SIDE_HALF)||(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_TOP_AND_BOTTOM)||(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)))
	{
		unsigned char ddr_bit;
		unsigned int temp;
		ddr_bit=(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_CHANNEL) ? 0 : (Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_10BIT) << 1))  | ( !Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_422CAP));

		if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_TOP_AND_BOTTOM)
			MemShiftAddr=((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE)-Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN))<<1)*LineStep;
		else if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)
		{
			MemShiftAddr=((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE)-Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN))>>2)*3*LineStep;
		}
		else if(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE)==SLR_3D_SIDE_BY_SIDE_HALF)
			MemShiftAddr=((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE)-Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN))>>1)*LineStep;

		pr_debug("[3d]shift addr v=0x %x,len pre- len =%d \n",MemShiftAddr,Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_LEN_PRE)-Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));
		temp=memory_get_line_size(((Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_MEM_WID_PRE)-Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID))>>1), (ddr_bit & _BIT0), ((ddr_bit & _BIT1) >> 1));
		temp=drvif_memory_get_data_align(temp, 2);
		MemShiftAddr=MemShiftAddr+temp;
		//printk("[3d]shift addr h=%x\n",MemShiftAddr);
		MemShiftAddr=MemShiftAddr<<3;
		pr_debug("[3d][vFlip]shift addr after <<3 =%x\n",MemShiftAddr);
	}

	ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN) + MemShiftAddr;
	ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + MemShiftAddr;

	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddrDropBits_reg,droppixel);

	ucStartAddress3 = drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr;

	Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_DISPLAY_SIZE, memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY)));

	pr_debug("[vFlip]before address %x %x %x\n",ucStartAddress,ucStartAddress2, ucStartAddress3);
	ucStartAddress = memory_cal_vflip_block_addr(ucStartAddress, LineStep , Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));
	ucStartAddress2 = memory_cal_vflip_block_addr(ucStartAddress2, LineStep ,Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));
	ucStartAddress3 = memory_cal_vflip_block_addr(ucStartAddress3, LineStep , Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));
	pr_debug("[vFlip]after address %x %x %x\n",ucStartAddress,ucStartAddress2, ucStartAddress3);

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() /*&&(Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE))!=SLR_3D_2D_ONLY*/)
	{
		MemDispStartAddr_3D[0]=ucStartAddress;
		MemDispStartAddr_3D[1]=ucStartAddress2;
		MemDispStartAddr_3D[2]=ucStartAddress3;
	}

	MemSetDisplayVFLIPAddr(SLR_MAIN_DISPLAY, ucStartAddress,ucStartAddress2,ucStartAddress3);

	TotalSize = LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN);

	IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule

	pr_debug("[vFlip]block step %x\n", ((TotalSize + TotalSize%2) << 3));

	//printk("%s %d bDouble=%d\n",__FUNCTION__,__LINE__,bDouble);
	if(bVflip) {	// use double buffer
		TotalSize = LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN);
		IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule

	}

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE())
		memory_set_main_3D_setting(LineStep);

}



void zoom_memory_set_vflip_main(unsigned char bVflip,unsigned char buffernum)
{
	unsigned int TotalSize;
//	unsigned int  TotalSizeFrame=0;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int ucStartAddress;
	unsigned int ucStartAddress2=0;
	unsigned int ucStartAddress3 = 0;
	unsigned int LineStep;
	unsigned int fifoLen = _FIFOLENGTH;
	unsigned int burstLen = _BURSTLENGTH;
	StructSrcRect m_dispwin;
	mdomain_disp_ddr_mainprevstart_RBUS ddr_mainprevstart_reg;
	unsigned int Align_LineStep;

	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
		burstLen=0xf0;
	}

	m_dispwin = Scaler_DispWindowGet();
	ddr_mainprevstart_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainPreVStart_reg);
	if(m_dispwin.srcy <= 100) {
		ddr_mainprevstart_reg.main_pre_rd_v_start = 7;
	} else {
		ddr_mainprevstart_reg.main_pre_rd_v_start = (m_dispwin.srcy-10);
	}
	IoReg_Write32(MDOMAIN_DISP_DDR_MainPreVStart_reg, ddr_mainprevstart_reg.regValue);

	//frank@0323 change waterlevel/2 for AT,because water level nit is 128 bits
	IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) & 0x0FFF) << 8) | ((fifoLen-(burstLen>>1))>>1));
	IoReg_Mask32(MDOMAIN_DISP_DDR_MainLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));

	TotalSize = memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));	// calculate the memory size of capture
	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division


	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Write32(MDOMAIN_DISP_DDR_MainRdNumLenRem_reg, (Quotient << 16) | (burstLen << 8) | Remainder);

	TotalSize = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEMCAPTYPE_LINE);		// calculate capture line size
	LineStep = TotalSize;
	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits
	Align_LineStep = LineStep;
	Align_LineStep = (Align_LineStep % 2) ? (Align_LineStep + 1) : Align_LineStep;
	IoReg_Write32(MDOMAIN_DISP_DDR_MainLineStep_reg, ((~Align_LineStep) + 1) << 3);//bit 3 need to be 0. rbus rule

	if (bVflip)
	{
		if (buffernum == 0)
		{
			ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
			ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
		}
		else
		{
			ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
			ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
		}

		ucStartAddress = memory_cal_vflip_block_addr(ucStartAddress, LineStep , Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));
		ucStartAddress2 = memory_cal_vflip_block_addr(ucStartAddress2, LineStep ,Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));
		if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3)){
			ucStartAddress3 = drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
			ucStartAddress3 = memory_cal_vflip_block_addr(ucStartAddress3, LineStep , Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));
		}
	}
	else
	{
		if (buffernum == 0)
		{
			ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN) +(Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
		}
		else
		{
			ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA)) + (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA) *TotalSize);
		}

		ucStartAddress = memory_cal_vflip_block_addr(ucStartAddress, LineStep , Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));
	}


	if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
		MemSetDisplayVFLIPAddr(SLR_MAIN_DISPLAY, ucStartAddress,ucStartAddress2,ucStartAddress3);
	else
		MemSetDisplayAddr(SLR_MAIN_DISPLAY, ucStartAddress, ucStartAddress2);


	if(bVflip) {	// use double buffer
		TotalSize = LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN);

		IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule
	}


	//IoReg_SetBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_DISP_DDR_SubCtrl_reg : MDOMAIN_DISP_DDR_MainCtrl_reg, MDOMAIN_DISP_DDR_MainCtrl_main_v_flip_3buf_en_mask);

}

void memory_set_main_activewindow_change(void)
{
	UINT32 MemShiftAddr = 0;
	UINT16 droppixel = 0;
	unsigned int ucStartAddress=0;
	unsigned int ucStartAddress2=0;
	unsigned int ucStartAddress3=0;
	if (Get_PANEL_VFLIP_ENABLE() && Scaler_InputSrcGetMainChType() != _SRC_VO){// hdmi 1080i 2dcvt 3d, source will be hdmi , not vo source
		MemGetBlockShiftAddr(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);
		ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN) + MemShiftAddr;
		ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + MemShiftAddr;
		if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
			ucStartAddress3 = drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr;
		if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3)){
				IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg,ucStartAddress&0x7ffffff0);
		        IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg,ucStartAddress2&0x7ffffff0);
				IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg,ucStartAddress3&0x7ffffff0);
		}else{
				//printk("Before %s %d IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg)=%x\n",__FUNCTION__,__LINE__,IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg));
				IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg, ucStartAddress&0x7ffffff0);
				//printk("After %s %d IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg)=%x\n",__FUNCTION__,__LINE__,IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg));
				IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg, ucStartAddress2&0x7ffffff0);
		}
	}else{
		MemGetBlockShiftAddr(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);
		ucStartAddress = drvif_memory_get_block_addr(MEMIDX_MAIN) + MemShiftAddr;
		ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + MemShiftAddr;
		//printk("Before %s %d IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg)=%x\n",__FUNCTION__,__LINE__,IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg));
		IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg, ucStartAddress&0x7ffffff0);
		//printk("After %s %d IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg)=%x\n",__FUNCTION__,__LINE__,IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg));
		IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg, ucStartAddress2&0x7ffffff0);
	}
}


void memory_set_main_displaywindow_change(void)
{
	SCALER_DISP_CHANNEL display = SLR_MAIN_DISPLAY;
	unsigned int mainctrltemp = 0;
	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int ucStartAddress;
	unsigned int ucStartAddress2=0;
	unsigned int ucStartAddress3=0;
	unsigned int LineStep;
	unsigned int comp_width = 0;
	unsigned int fifoLen = _FIFOLENGTH;
	unsigned int burstLen = _BURSTLENGTH;
	UINT32 MemShiftAddr = 0;
	UINT16 droppixel = 0;
	StructSrcRect m_dispwin;
	mdomain_disp_ddr_mainprevstart_RBUS ddr_mainprevstart_reg;

	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
		burstLen=0xf0;
	}

	m_dispwin = Scaler_DispWindowGet();
	ddr_mainprevstart_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainPreVStart_reg);
	if(m_dispwin.srcy <= 100) {
		ddr_mainprevstart_reg.main_pre_rd_v_start = 7;
	} else {
		ddr_mainprevstart_reg.main_pre_rd_v_start = (m_dispwin.srcy-10);
	}
	IoReg_Write32(MDOMAIN_DISP_DDR_MainPreVStart_reg, ddr_mainprevstart_reg.regValue);

	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddrDropBits_reg,0x0);

	IoReg_Mask32(MDOMAIN_DISP_DDR_MainLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));

	if ((Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_MEM_ACT_HSTA) == 0) && (Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_MEM_ACT_VSTA) == 0) )
	{
		if((Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE)){
			comp_width = Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID);
			if((comp_width % 32) != 0)
				comp_width = comp_width + (comp_width % 32);
			IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, (((comp_width * dvrif_memory_get_compression_bits() / 32) & 0x0fFF) << 8) | ((fifoLen - (burstLen>>1))>>1));
			TotalSize = memory_get_capture_line_size_compression(dvrif_memory_get_compression_bits());
		} else {
			IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, ((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) & 0x0fFF) << 8) | ((fifoLen - (burstLen>>1))>>1));
			TotalSize = memory_get_display_size(display);	// calculate the memory size of capture
		}
	} else {
		MemGetBlockShiftAddr(display,Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);
		TotalSize = memory_get_disp_line_size1(display,Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_MEM_ACT_WID) + droppixel);	// calculate the memory size of capture
		IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, (( ((Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_MEM_ACT_WID) +droppixel) & 0x0fFF) << 8) | ((fifoLen - (burstLen>>1))>>1)));
		pr_debug("drop pixel=%d shift addr=%x\n",droppixel,MemShiftAddr);

	}


	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division

	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Write32(MDOMAIN_DISP_DDR_MainRdNumLenRem_reg, (Quotient << 16) | (burstLen << 8) | Remainder);

	if((Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE))
		TotalSize = memory_get_capture_line_size_compression(dvrif_memory_get_compression_bits());
	else
		TotalSize = memory_get_capture_size(display, MEMCAPTYPE_LINE);		// calculate capture line size
	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF))
		TotalSize=TotalSize>>1;

	LineStep = TotalSize;
	//printk("Line Step=0x%x\n",LineStep);
	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	IoReg_Write32(MDOMAIN_DISP_DDR_MainLineStep_reg, (LineStep + LineStep%2) << 3);//bit 3 need to be 0. rbus rule

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()
		&& ((Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE)==SLR_3D_SIDE_BY_SIDE_HALF)||(Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE)==SLR_3D_TOP_AND_BOTTOM)||(Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)))
	{
		unsigned char ddr_bit;
		unsigned int temp;
		ddr_bit=(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_CHANNEL) ? 0 : (Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_10BIT) << 1)) | ( !Scaler_DispGetStatus(SLR_MAIN_DISPLAY,SLR_DISP_422CAP));

		if(Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING || Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE)==SLR_3D_TOP_AND_BOTTOM)
		{
			//[#0051720] MVC FP source (L-sync, double buffer control)
			if((Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING) && (Scaler_InputSrcGetMainChType() == _SRC_VO))
			{
				MemShiftAddr=((2*Scaler_DispGetInputInfoByDisp(display, SLR_DISP_3D_MEM_LEN_PRE)-2*Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_MEM_ACT_LEN))>>2)*LineStep;
			}
			else
			{
				MemShiftAddr=((Scaler_DispGetInputInfoByDisp(display, SLR_DISP_3D_MEM_LEN_PRE)-Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_MEM_ACT_LEN))>>2)*LineStep;
				if(get_3D_overscan_enable())
				{
					MemShiftAddr=(get_3D_overscan_input_vsta()>>1)*LineStep;
				}
			}
		}
		else
		{
			MemShiftAddr=((Scaler_DispGetInputInfoByDisp(display, SLR_DISP_3D_MEM_LEN_PRE)-Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN))>>1)*LineStep;
			if(get_3D_overscan_enable())
			{
				MemShiftAddr=(get_3D_overscan_input_vsta())*LineStep;
			}
		}

		//printk("[3d]shift addr v=%x\n",MemShiftAddr);
		temp=memory_get_line_size(((Scaler_DispGetInputInfoByDisp(display, SLR_DISP_3D_MEM_WID_PRE) - Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID))>>1), (ddr_bit & _BIT0), ((ddr_bit & _BIT1) >> 1));
		if(get_3D_overscan_enable())
		{
			if(Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING || Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE)==SLR_3D_TOP_AND_BOTTOM)
				temp=memory_get_line_size(get_3D_overscan_input_hsta(), (ddr_bit & _BIT0), ((ddr_bit & _BIT1) >> 1));
			else if(Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE)==SLR_3D_SIDE_BY_SIDE_HALF)
				temp=memory_get_line_size(get_3D_overscan_input_hsta()>>1, (ddr_bit & _BIT0), ((ddr_bit & _BIT1) >> 1));
		}

		temp=drvif_memory_get_data_align(temp, 2);
		MemShiftAddr=MemShiftAddr+temp;
		//printk("[3d]shift addr h=%x\n",MemShiftAddr);
		MemShiftAddr=MemShiftAddr<<3;
		//printk("[3d]shift addr after <<3 =%x\n",MemShiftAddr);
	}

	ucStartAddress = (drvif_memory_get_block_addr(MEMIDX_MAIN) + MemShiftAddr) & 0x7ffffff0;

	ucStartAddress2 = (drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + MemShiftAddr) & 0x7ffffff0;

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() && (Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE) != SLR_3D_2D_ONLY))
	{
		MemDispStartAddr_3D[0]=ucStartAddress;
		MemDispStartAddr_3D[1]=ucStartAddress2;
	}

#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
	if(Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ)>650)
	{
		ucStartAddress3 = (drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr) & 0x7ffffff0;
		IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, ucStartAddress3&0x7ffffff0);
	}
	else if(_ENABLE == Scaler_Get_Enable_3Buffer_NewRuleCondition())
	{
		if(_TRUE == Scaler_DispGetStatus(display, SLR_DISP_VFLIP3))
		{
			ucStartAddress3 = (drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr) & 0x7ffffff0;
			IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, ucStartAddress3&0x7ffffff0);
		}
	}
#else //#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
#ifdef ENABLE_3_BUFFER_DELAY_MODE
	ucStartAddress3 = (drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr) & 0x7ffffff0;
	IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, ucStartAddress3&0x7ffffff0);
	MemDispStartAddr_3D[2]=ucStartAddress3;
#endif

	//M-3buf condition:
	// 1. [2D] M-capture frame rate > M-display frame rate
	// 2. [3D][SG] FRC in M-domain, M-display need repeat frame 2 times
	// 3. [3D][SG] SG 3D display timing FRC need enable triple buffer to avoid frame tear issue
	// 4. [3D][PR] PR to SG 3D display timing FRC need enable triple buffer to avoid frame tear issue
	if((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ)>650)|| drvif_scaler3d_decide_3d_SG_data_FRC()
			|| ((drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() == TRUE) && drvif_scaelr3d_decide_is_3D_display_mode())
			|| (Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE() && drvif_scaelr3d_decide_is_3D_display_mode())
			|| (modestate_get_pr3d_in_fp_3d_mode() && ((Scaler_InputSrcGetMainChType() == _SRC_VO)|| (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ) >= 310)))
			||Get_vscFilmMode())
	{
		ucStartAddress3 = (drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr) & 0x7ffffff0;
		IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, ucStartAddress3&0x7ffffff0);
		MemDispStartAddr_3D[2]=ucStartAddress3;
	}
#endif //#ifdef CONFIG_ENABLE_3BUFFER_NEW_RULE
	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddrDropBits_reg,droppixel);

	Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_DISPLAY_SIZE, memory_get_display_size(display));

	MemSetDisplayAddr(SLR_MAIN_DISPLAY, ucStartAddress, ucStartAddress2);
	if(TRUE) {	// use double buffer
		TotalSize = LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN);
		IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg, (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule
	}

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()){
		memory_set_main_3D_setting_dispchange(LineStep);
	}// [SG] SG 3D in data FRC mode -- sequence frame 3D L-R output control
	else if(drvif_scaler3d_decide_3d_SG_data_FRC()|| (drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() && drvif_scaelr3d_decide_is_3D_display_mode())){
		memory_set_main_SG_3D_setting_dispchange(LineStep, ucStartAddress, ucStartAddress2, ucStartAddress3);
	}

	Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_MAIN_ADDR, ucStartAddress);
	Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_MAIN_SEC_ADDR, ucStartAddress2);
	Scaler_Disp3dSetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_MAIN_THIRD_ADDR, ucStartAddress3);

	if (Get_PANEL_VFLIP_ENABLE())
	{
	if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_VFLIP3))
		mainctrltemp =  _BIT7 | (display ? _BIT1 : 0) | _BIT6   ;
	else
		mainctrltemp =  (display ? _BIT1 : 0) | _BIT6;
	}
	else
		mainctrltemp =  (display ? _BIT1 : 0) | _BIT6 ;

	mainctrltemp = mainctrltemp | _BIT25 | _BIT28;

	//M-3buf condition:
	// 1. [2D] M-capture frame rate > M-display frame rate
	// 2. [3D][SG] FRC in M-domain, M-display need repeat frame 2 times
	// 3. [3D][SG] SG 3D display free run need triple buffer to avoid frame tear
	// 4. [3D][PR] PR to SG 3D display timing FRC need enable triple buffer to avoid frame tear issue
	// 5. [3D][PR] frame packing video in PR 3D panel (TO BE FIXED)
	if((Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_V_FREQ) > 650)
			|| drvif_scaler3d_decide_3d_SG_data_FRC()
			|| ((drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() == TRUE) && drvif_scaelr3d_decide_is_3D_display_mode())
			|| (Get_PANEL_3D_PR_TO_SG_OUTPUT_FRC_ENABLE() && drvif_scaelr3d_decide_is_3D_display_mode())
			|| (modestate_get_pr3d_in_fp_3d_mode() && ((Scaler_InputSrcGetMainChType() == _SRC_VO)|| (Scaler_DispGetInputInfoByDisp(display,SLR_INPUT_V_FREQ) >= 310))))
	{
		// Input source frame rate faster than display (main_frc_style = 1)
		// M-display IVS refer to front of VGIP signal (for HDMI FP 3D, IVS refer to the source v-sync)
		if((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_V_FREQ) > 650) && (Scaler_Get3DMode((SCALER_DISP_CHANNEL)display) == SLR_3DMODE_2D))
			mainctrltemp |= _BIT3;

		if((display == SLR_MAIN_DISPLAY))//frank@1007 solve VGA source M domain hang problem
			//set Mdomain display triple buffer
			mainctrltemp |=_BIT7;

		// [3D][PR]  PR output merge triple buffer enable
		if(Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()){
			if((Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE) == SLR_3D_TOP_AND_BOTTOM)||(Scaler_Disp3dGetInfo(display, SLR_DISP_3D_3DTYPE) == SLR_3D_FRAME_PACKING))
				mainctrltemp |=_BIT14;
		}
	}
#ifdef ENABLE_3_BUFFER_DELAY_MODE
	if(drv_memory_get_game_mode() == _ENABLE){
		mainctrltemp = mainctrltemp & (~(_BIT6 | _BIT7));
	}
	else{
		mainctrltemp |=_BIT7;//set Mdomain display triple buffer
	}
	//mainctrltemp |=(_BIT7|_BIT3);//set Mdomain display triple buffer
#endif


	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE())
		mainctrltemp=mainctrltemp|(IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg)&(_BIT5|_BIT13));// filed merge enable

	mainctrltemp |= (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display,SLR_DISP_10BIT) ? _BIT16 : 0);
	if((display == SLR_MAIN_DISPLAY) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE)){
		mainctrltemp |= _BIT17;
	}else{
		mainctrltemp |= Scaler_DispGetStatus((SCALER_DISP_CHANNEL)display, SLR_DISP_422CAP) ? 0 : _BIT17;
	}
	mainctrltemp |= (_BIT19);
	mainctrltemp |= (drvif_scaler3d_decide_3d_SG_data_FRC()|| (drvif_scaler3d_decide_2d_cvt_3d_SG_frc_in_mDomain() && drvif_scaelr3d_decide_is_3D_display_mode())? _BIT12: 0); // 3D frame sequence out enable

	IoReg_Write32(/*display? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_DDR_MainCtrl_reg,  mainctrltemp);
	IoReg_Write32(/*display? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_Disp_main_enable_reg,  _BIT0);

}

extern StructSrcRect Scaler_SubDispWindowGet(void);
void memory_set_sub_displaywindow_change(unsigned char changetomain)
{
	SCALER_DISP_CHANNEL display = SLR_SUB_DISPLAY;
	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int fifoLen = _FIFOLENGTH2;
	unsigned int burstLen = _BURSTLENGTH2;
	unsigned int MemShiftAddr = 0;
	unsigned short droppixel = 0;
	unsigned int subctrltemp = 0;
	mdomain_disp_ddr_subprevstart_RBUS mdomain_disp_ddr_subprevstart_Reg;
	StructSrcRect s_dispwin;

	s_dispwin = Scaler_SubDispWindowGet();


	mdomain_disp_ddr_subprevstart_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_SubPreVStart_reg);
#if 1 //K3L Q8401 frame tear issue
		if(s_dispwin.srcy <= 100) {
			mdomain_disp_ddr_subprevstart_Reg.sub_pre_rd_v_start = Get_DISP_DEN_STA_VPOS()-7;
		} else {
			mdomain_disp_ddr_subprevstart_Reg.sub_pre_rd_v_start = (s_dispwin.srcy+Get_DISP_DEN_STA_VPOS()-4);
		}
#else
		mdomain_disp_ddr_subprevstart_Reg.sub_pre_rd_v_start = 7;
#endif
	IoReg_Write32(MDOMAIN_DISP_DDR_SubPreVStart_reg, mdomain_disp_ddr_subprevstart_Reg.regValue);

	/*if ((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA) == 0) && (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA) == 0) ) {
		//frank@0323 change waterlevel/2 for AT,because water level nit is 128 bits
		IoReg_Mask32(MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0xffc00000, ((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) & 0x3FFF) << 8) | (fifoLen - burstLen));
		if(changetomain)
			TotalSize = memory_get_display_size(SLR_MAIN_DISPLAY);
		else
			TotalSize = memory_get_display_size(display);	// calculate the memory size of capture
	} else */{
		if(changetomain)
			MemGetBlockShiftAddr(SLR_MAIN_DISPLAY, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);
		else
			MemGetBlockShiftAddr(display, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);
		TotalSize = memory_get_disp_line_size1(display, Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) + droppixel);	// calculate the memory size of capture
		IoReg_Mask32(MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0xffc00000, (( ((Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_WID) +droppixel) & 0x3FFF) << 8) | ((fifoLen - (burstLen>>1))>>1)));
	}

	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division

	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubRdNumLenRem_reg, 0x00000000, (Quotient << 16) | (burstLen << 8) | Remainder);

	if(changetomain)
		TotalSize = memory_get_capture_size(SLR_MAIN_DISPLAY, MEMCAPTYPE_LINE);
	else
		TotalSize = memory_get_capture_size(display, MEMCAPTYPE_LINE);
	/*TotalSize = Quotient * burstLen + Remainder; 	// count one line, 64bits unit
	TotalSize = drvif_memory_get_data_align(TotalSize, 4);	// times of 4*/

	IoReg_Write32(MDOMAIN_DISP_DDR_SubLineStep_reg,  (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule

	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));

	if(changetomain)
		MemSetDisplayAddr(SLR_SUB_DISPLAY, (drvif_memory_get_block_addr(MEMIDX_MAIN) + MemShiftAddr) & 0x7ffffff0, (drvif_memory_get_block_addr(MEMIDX_MAIN_SEC) + MemShiftAddr) & 0x7ffffff0);
	else
		MemSetDisplayAddr(SLR_SUB_DISPLAY, (drvif_memory_get_block_addr(MEMIDX_SUB) + MemShiftAddr) & 0x7ffffff0, (drvif_memory_get_block_addr(MEMIDX_SUB_SEC) + MemShiftAddr) & 0x7ffffff0);

#ifdef ENABLE_3_BUFFER_DELAY_MODE
	if(changetomain)
		IoReg_Write32(MDOMAIN_DISP_DDR_Sub3rdAddr_reg, (drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) + MemShiftAddr) & 0x7ffffff0);
	else
		IoReg_Write32(MDOMAIN_DISP_DDR_Sub3rdAddr_reg, (drvif_memory_get_block_addr(MEMIDX_SUB_THIRD) + MemShiftAddr) & 0x7ffffff0);
#endif

	IoReg_Write32(MDOMAIN_DISP_DDR_SubAddrDropBits_reg,droppixel);
	subctrltemp = IoReg_Read32 (MDOMAIN_DISP_DDR_SubCtrl_reg);//K3LG-370:for sub frame tear issue

	/*IoReg_Mask32(MDOMAIN_DISP_DDR_SubBlkStep_reg, 0xff000000, 0);
	IoReg_WriteWord0(MDOMAIN_DISP_DDR_SubMPEn_reg,0);
	IoReg_WriteByte0(MDOMAIN_DISP_DDR_SubMPMode_reg, _BIT3);*/
	subctrltemp = _BIT6;
	if(Get_Live_zoom_mode()== LIVE_ZOOM_SUB&&Get_Magnifier_LiveZoom_Mode()==1)
		subctrltemp |=_BIT1;
#ifdef ENABLE_3_BUFFER_DELAY_MODE
	subctrltemp |=_BIT7;//set Mdomain display triple buffer
#endif


	//if(!changetomain) //K3LG-370 marked
	//	subctrltemp |= (_BIT1);//K3LG-370 marked
	subctrltemp |= Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP) ? 0 : _BIT17;
	subctrltemp |= (_BIT19);
	//K3LG-370:for sub frame tear issue _BIT25,_BIT28
	subctrltemp |= (_BIT25);
	subctrltemp |= (_BIT28);
	IoReg_Write32(MDOMAIN_DISP_DDR_SubCtrl_reg, subctrltemp);

	/*added for magnifier flow will not run memory handler api*/
	if (MDOMAIN_DISP_DDR_SubCtrl_sub_use_main_block_mask&IoReg_Read32 (MDOMAIN_DISP_Disp_sub_enable_reg) ==0) {
		IoReg_Write32(MDOMAIN_DISP_Disp_sub_enable_reg, _BIT0);
		mdomain_disp_display_byte_channel_swap_RBUS display_byte_channel_swap_reg;
		display_byte_channel_swap_reg.regValue = IoReg_Read32(MDOMAIN_DISP_Display_byte_channel_swap_reg);
		display_byte_channel_swap_reg.sub_1byte_swap = 0;
		display_byte_channel_swap_reg.sub_2byte_swap = 1;
		display_byte_channel_swap_reg.sub_4byte_swap = 1;
		display_byte_channel_swap_reg.sub_8byte_swap = 0;
		IoReg_Write32(MDOMAIN_DISP_Display_byte_channel_swap_reg, display_byte_channel_swap_reg.regValue);
	}

	//drvif_memory_set_dbuffer_write();
}

#ifdef CONFIG_DUAL_CHANNEL // There are two channels
static void memory_set_sub_vflip_for_pip(void)
{

	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int ucStartAddress;
	unsigned int ucStartAddress2;
	unsigned int LineStep;
	unsigned int fifoLen = _FIFOLENGTH2;
	unsigned int burstLen = _BURSTLENGTH2;
	unsigned int Align_LineStep;

	//change waterlevel/2 for AT,because water level nit is 128 bits
	IoReg_Mask32(MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0xff800ff, ((Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID) & 0x07FF) << 8) | (fifoLen-burstLen));
	IoReg_Mask32(MDOMAIN_DISP_DDR_SubLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));


	ucStartAddress = drvif_memory_get_block_addr(MEMIDX_SUB);
	ucStartAddress2 = drvif_memory_get_block_addr(MEMIDX_SUB_SEC);

	TotalSize = memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));	// calculate the memory size of capture
	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division

	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubRdNumLenRem_reg, 0x00000000, (Quotient << 16) | (burstLen << 8) | Remainder);
	TotalSize = Quotient * burstLen + Remainder; 	// count one line, 64bits unit
	TotalSize = drvif_memory_get_data_align(TotalSize, 4);	// times of 4
	LineStep = TotalSize;
	Align_LineStep = LineStep;
	Align_LineStep = (Align_LineStep % 2) ? (Align_LineStep + 1) : Align_LineStep;
    IoReg_Write32(MDOMAIN_DISP_DDR_SubLineStep_reg, ((~Align_LineStep) + 1) << 3);//bit 3 need to be 0. rbus rule

	ucStartAddress = memory_cal_vflip_block_addr(ucStartAddress, LineStep , Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));
	ucStartAddress2 = memory_cal_vflip_block_addr(ucStartAddress2, LineStep , Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN));

	MemSetDisplayAddr(SLR_SUB_DISPLAY,ucStartAddress ,ucStartAddress2);

	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	IoReg_Write32(MDOMAIN_DISP_DDR_SubBlkStep_reg,  0);

	IoReg_WriteWord0(MDOMAIN_DISP_DDR_SubMPEn_reg,0);
	IoReg_WriteByte0(MDOMAIN_DISP_DDR_SubMPMode_reg, _BIT3);
	IoReg_SetBits(MDOMAIN_DISP_DDR_SubCtrl_reg, _BIT6);
	drvif_memory_set_dbuffer_write();

}
#endif //CONFIG_DUAL_CHANNEL  // There are two channels


unsigned int FilmModeCachaddr = (unsigned int)NULL;
unsigned int FilmModePhyadddr = (unsigned int)NULL;
extern bool rtk_hal_vsc_GetRGB444Mode(void);
extern unsigned char get_AVD_Input_Source(void);
/*============================================================================*/
/**
 * dvrif_memory_handler
 * This function is used to handler memory (page 3).
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 */
void dvrif_memory_handler(void)
{
	SCALER_DISP_CHANNEL display = (SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY);
	drvif_scaler_ddomain_switch_irq(_DISABLE);	// avoid to DSR to switch buffer when double bit not set

	if (display == SLR_MAIN_DISPLAY) {	// Main
		//Disable M-disp when reset M-domain=>To Fixed DTV change issue @ Crixus 20141126
		drv_memory_Main_Disp_Enable(FALSE);
#if 0
		//USER:LewisLee DATE:2012/08/20
		//to prevent 3D->2D mode, the the memory address error
		if(_ENABLE == Scaler_Get_Enable_3D_Mode_3Buffer_SW_Switch_Condition())
		{
			drvif_memory_3D_mode_sw_buffer_swap_action(SLR_MAIN_DISPLAY, MEM_3D_SWBUFFER_SWAP_DISABLE);
		}
#endif
		//drvif_memory_3D_mode_sw_buffer_swap_action(SLR_MAIN_DISPLAY, MEM_3D_SWBUFFER_SWAP_CONDITION_CHECK);

		if((Scaler_InputSrcGetMainChType() == _SRC_VO) && (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane()) == 1))	// yychao+ : use single buffer for JPEG source
			memory_set_capture(FALSE, MEMCAPTYPE_FRAME);	//  CSW 0961105 change single buffer to double to slove 1080i moving picture not smooth
		/*else if((Get_HDMI_SingleBuffer_GameMode()==TRUE) && (Scaler_InputSrcGetMainChType() == _SRC_HDMI))
		{
			memory_set_capture(FALSE, MEMCAPTYPE_FRAME);
		}*/
		else if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE()
			&& (Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) >= SLR_3D_FIELD_ALTERNATIVE) && (Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) <= SLR_3D_SIDE_BY_SIDE_HALF))
		{
			if (Get_PANEL_VFLIP_ENABLE())
		        {
	  			 if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
					memory_set_vflip_capture(TRUE,MEMCAPTYPE_FRAME);
			}
				memory_set_capture(TRUE, MEMCAPTYPE_LINE);
		} // [SG] For SBS SG 3D in disable IDMA 3D mode
		else if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == FALSE)
			&& (Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_3DTYPE) == SLR_3D_SIDE_BY_SIDE_HALF) && (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_SIDE_BY_SIDE_HALF) == TRUE))
		{
			if (Get_PANEL_VFLIP_ENABLE())
		        {
	  			 if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
					memory_set_vflip_capture(TRUE,MEMCAPTYPE_FRAME);
			}
			memory_set_capture(TRUE, MEMCAPTYPE_LINE);
		}
		else
		{
			/* No need to use bucause merlin2 always run 3-buffers.
			if (Get_PANEL_VFLIP_ENABLE())
			{
      				 if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3)){
					memory_set_vflip_capture(TRUE,MEMCAPTYPE_FRAME);
      				 }
			}
			*/
			if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE))
				memory_set_capture(TRUE, MEMCAPTYPE_LINE);
			else
				memory_set_capture(TRUE, MEMCAPTYPE_FRAME);	//  CSW 0961105 change single buffer to double to slove 1080i moving picture not smooth
		}

		if((Scaler_InputSrcGetMainChType() == _SRC_VO) && (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane()) == 1))	// yychao+ : use single buffer for JPEG source
			memory_set_main(FALSE);		//  CSW 0961105 change single buffer to double to slove 1080i moving picture not smooth
		/*else if((Get_HDMI_SingleBuffer_GameMode()==TRUE) && (Scaler_InputSrcGetMainChType() == _SRC_HDMI))
			memory_set_main(FALSE);*/
		else
		{
			if (Get_PANEL_VFLIP_ENABLE())
			{
				//VDEC source do v-flip on VO because data fs, other do on M-domain @Crixus 20171226
				if(Scaler_InputSrcGetMainChType() == _SRC_VO){
					memory_set_main(TRUE);
				}
				else{
					memory_set_vflip_main(TRUE);  //vflip 1st,2nd,3rd display
				}
			}
			else
			{
				//printk("c.....\n");
				memory_set_main(TRUE);		//  CSW 0961105 change single buffer to double to slove 1080i moving picture not smooth
			}
		}


        }
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	else {	//Sub enable
		if (Scaler_PipGetInfo(SLR_PIP_TYPE) <= SUBTYPE_PIPMLSR_4x3)
		{// Sub PIP
#ifdef CONFIG_I2RND_ENABLE
			//I2rnd sub cap=>VO have to run line mode to meet line step @Crixus 20160712
			if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_DETECT_SOURCE))
				memory_set_capture(TRUE, MEMCAPTYPE_LINE);
			else
#endif
				memory_set_capture(TRUE, MEMCAPTYPE_FRAME); // memory, capture part for other cases

			if (Get_PANEL_VFLIP_ENABLE())
			{
				if (Scaler_InputSrcGetMainChType() == _SRC_VO)
					memory_set_sub_for_pip();
				else
					memory_set_sub_vflip_for_pip();
			}
			else
			{
				memory_set_sub_for_pip();	// memory, sub display part
			}
		}
		else if (Scaler_PipGetInfo(SLR_PIP_TYPE) <= SUBTYPE_MP1L7B)
		{// Sub MP
			memory_set_capture_for_mp(); // memory, capture part for Multi Picture
			memory_set_sub_for_mp();
			/*ScalerTimer_ActiveTimerEvent(SLRTIMER_PIPMP, 1000, (SLRTIMER_CALLBACK)PipMp_RotateMp);*/
			Scaler_PipSetSubInfo(SLR_PIP_SUB_MPENABLE,1);
		}
		else
		{
#ifdef CONFIG_I2RND_ENABLE
			//I2rnd sub cap=>VO have to run line mode to meet line step @Crixus 20160712
			if((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_DETECT_SOURCE))
				memory_set_capture(TRUE, MEMCAPTYPE_LINE);
			else
#endif
				memory_set_capture(TRUE, MEMCAPTYPE_FRAME); // memory, capture part for other cases

			memory_set_sub_for_pip();	// memory, sub display part
		}
	}
#endif //CONFIG_DUAL_CHANNEL  // There are two channels
	//if(!((get_mainsubonpr_fuc()==TRUE)&&(get_MainSubonPR_curState()==MAINSUB_SHOWONPR_INIT_SUB)))
	{
		if((Scaler_InputSrcGetMainChType() == _SRC_VO) && (Scaler_VOFrom(Scaler_Get_CurVoInfo_plane()) == 1))	// yychao+ : use single buffer for JPEG source
			memory_set_input_format(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), FALSE);
		/*else if((Get_HDMI_SingleBuffer_GameMode()==TRUE) && (Scaler_InputSrcGetMainChType() == _SRC_HDMI))
			memory_set_input_format(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), FALSE);*/
		else{
			if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() &&
				Get_PANEL_VFLIP_ENABLE()&&
				(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))&&
				((Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)==SLR_3D_TOP_AND_BOTTOM )||
				(Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)))
			{
				memory_set_input_format(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), FALSE);
			}
			else
			{
#if 0
				if(TRUE==get_delayframe_fuc())
				{
					memory_set_input_format(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), FALSE);//display go single buffer when delay frame need
				}
				else
#endif
				{
					memory_set_input_format(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), TRUE);
				}
			}
		}
	}

	//compression & de-compression setting
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)) == TRUE)){
		dvrif_memory_comp_setting(TRUE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID), Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_LEN), dvrif_memory_get_compression_bits());
		IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT0);
	}else if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL2)
	{
		//to do: enable compress mode for sub path.
	}
	else{
		dvrif_memory_comp_setting(FALSE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID), Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_LEN), dvrif_memory_get_compression_bits());
		IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT0);
	}

	//update multi-buffer setting @Crixus 20160913
	if(drv_memory_Get_multibuffer_flag()){
		printk(KERN_EMERG"[crixus]drv_memory_Get_multibuffer_number() = %x\n", drv_memory_Get_multibuffer_number());
		drv_memory_capture_multibuffer_control(drv_memory_Get_multibuffer_number(), drv_memory_Get_multibuffer_number() - 1);
		drv_memory_display_multibuffer_control(drv_memory_Get_multibuffer_number(), drv_memory_Get_multibuffer_number() - 1);
	}

	if(Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE())
		drvif_memory_set_3D_LR_swap(Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_LR_SEQUENCE), Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)display, SLR_DISP_3D_3DTYPE));

	//drvif_memory_sw_buffer_swap_action((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEM_SWBUFFER_SWAP_ENABLE);
	//drvif_memory_3D_mode_sw_buffer_swap_action((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEM_3D_SWBUFFER_SWAP_ENABLE);
	if(TRUE==Get_vscFilmMode())
	{
		//because film mode need 4 buffers
		FilmModeCachaddr = (unsigned int)dvr_malloc(drvif_memory_get_block_size(MEMIDX_MAIN));
		//FilmModePhyadddr = (unsigned int)virt_to_phys((void*)FilmModeCachaddr);
		FilmModePhyadddr = (unsigned int)dvr_to_phys((void*)FilmModeCachaddr);
		filmmode_videofw_config(TRUE,FilmModePhyadddr);
	}

	//Game mode setting
	//Update the Game mode condition RGB444 @Crixus 20160222
	if (display == SLR_MAIN_DISPLAY) {
		if(Get_Factory_SelfDiagnosis_Mode()){
			//self-dianosis need signle buffer, rzhen@2016-09-01
			drv_memory_SingleBuffer_GameMode(_ENABLE);
		}else{

			if(drv_memory_get_game_mode()){
				drv_memory_SingleBuffer_GameMode(_ENABLE);
			#ifdef CONFIG_FORCE_RUN_I3DDMA
				if(drvif_i3ddma_triplebuf_flag())
					drv_I3ddmaVodma_SingleBuffer_GameMode(_DISABLE);
				else
					drv_I3ddmaVodma_SingleBuffer_GameMode(_ENABLE);
			#endif
			}
			else{
				drv_memory_SingleBuffer_GameMode(_DISABLE);
			#ifdef CONFIG_FORCE_RUN_I3DDMA
				drv_I3ddmaVodma_SingleBuffer_GameMode(_DISABLE);
			#endif
			}
		}

	#ifdef CONFIG_FORCE_RUN_I3DDMA
		/*qiangzhou:all i3ddma source go vodma timing sync i3ddma,all i3ddma source should setting iv2pv delay*/
		if(((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_ADC)
			|| (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
			||((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_AVD)  && (get_AVD_Input_Source() != _SRC_TV)))
			&&(!drvif_i3ddma_triplebuf_flag())){
			drv_I3ddmaVodma_GameMode_iv2pv_delay(TRUE);
		} else {
			drv_I3ddmaVodma_GameMode_iv2pv_delay(FALSE);
		}
	#endif
	}
}

void mdomain_handler_onlycap_i2run(void)
{
	mdomain_cap_capture_byte_swap_RBUS capture_byte_swap_reg;
	memory_set_capture(TRUE, MEMCAPTYPE_LINE);
	capture_byte_swap_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Capture_byte_swap_reg);
	capture_byte_swap_reg.in2_1byte_swap = 0;
	capture_byte_swap_reg.in2_2byte_swap = 0;
	capture_byte_swap_reg.in2_4byte_swap = 0;
	capture_byte_swap_reg.in2_8byte_swap = 1;
	IoReg_Write32(MDOMAIN_CAP_Capture_byte_swap_reg, capture_byte_swap_reg.regValue);
}

void mdomain_handler_onlycap(void)
{
	memory_set_capture(TRUE, MEMCAPTYPE_FRAME);
}

/*============================================================================*/
/**
 * drvif_memory_get_data_align
 * This function is used to do data alignment.
 *
 * @param <Value> { data needs alignment }
 * @param <unit> { unit of alignment }
 * @return { none }
 *
 */
unsigned int drvif_memory_get_data_align(unsigned int Value, unsigned int unit)
{
	unsigned int AlignVal;

	AlignVal = Value;
	unit -= 1;
	if (Value & unit)
		AlignVal = (Value & (~unit)) + unit + 1;
	return AlignVal;
}


// IP bit number control (saving bandwidth)
unsigned int drv_memory_get_ip_Btr_mode(void)
{
	return bIpBtrMode;
}


unsigned int drv_memory_get_ip_DMA420_mode(void)
{
	return bIpDma420Mode;
}


void drv_memory_set_ip_Btr_mode(unsigned int mode)
{
	bIpBtrMode = mode;
	return;
}


void drv_memory_set_ip_DMA420_mode(unsigned int mode)
{
	bIpDma420Mode = mode;
	return;
}

#ifndef Mag2_New_Flow
// DI bit number control (saving bandwidth)
static void drv_memory_DMA420_config(unsigned char *bitNum)
{
	UINT32 width, lineSize_odd, lineSize_even;

	if(!bitNum){
		pr_debug("ERR: NULL PTR@%s\n", __FUNCTION__);
		return;
	}

	// DI DMA 420 enable (saving bandwidth)
	if(drv_memory_get_ip_DMA420_mode() == SLR_DMA_420_mode){
		width = Scaler_DispGetInputInfo(SLR_INPUT_DI_WID);
		lineSize_even = (width * (*bitNum - ((fw_scalerip_get_DI_chroma_10bits())?10:8)));
		if((lineSize_even%64)==0)
			lineSize_even /=64;
		else
			lineSize_even = (lineSize_even+64)/64;
		lineSize_odd = (width * *bitNum);
		if((lineSize_odd%64)==0)
			lineSize_odd /=64;
		else
			lineSize_odd = (lineSize_odd+64)/64;

		pr_debug("[DI] DMA 420 Enable, bit/c-bit/line wid/even/odd[%d/%d/%d/%d/%d]\n", *bitNum, fw_scalerip_get_DI_chroma_10bits(),width, lineSize_even, lineSize_odd);
		IoReg_Mask32(DI_IM_DI_DMA_VADDR,
			~(DI_DMA_420_EN_MASK| DI_DMA_LINESIZE_EVEN_MASK| DI_DMA_LINESIZE_ODD_MASK),
			_BIT30| (lineSize_even << DI_DMA_LINESIZE_EVEN_START_BIT)| lineSize_odd);
		// update bit number
		//*bitNum -= 4;
	}
	else
		IoReg_ClearBits(DI_IM_DI_DMA_VADDR, _BIT30);

	return;
}
#endif
#if 0
static void drv_memory_set_ip_compress_bit(unsigned char bit_num)
{
#if 0	//Elsie 20131206: [FIXME] all of the registers below do not exist.
	dicmp_cmp_resolution_RBUS dicmp_cmp_resolution_reg;
	dicmp_comp_setting_RBUS dicmp_comp_setting_reg;
	dicmp_decmp_resolution_RBUS dicmp_decmp_resolution_reg;
	dicmp_decomp_setting_RBUS dicmp_decomp_setting_reg;
	dicmp_cmp_resolution_reg.regValue = 0;
	dicmp_cmp_resolution_reg.cmp_enable = 1;
	dicmp_cmp_resolution_reg.cmp_width = drvif_memory_get_data_align(Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID), 32)/32;
	dicmp_cmp_resolution_reg.cmp_height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
	dicmp_decmp_resolution_reg.regValue = 0;
	dicmp_decmp_resolution_reg.decmp_width = dicmp_cmp_resolution_reg.cmp_width;
	dicmp_decmp_resolution_reg.decmp_height = dicmp_cmp_resolution_reg.cmp_height;
	dicmp_comp_setting_reg.regValue = IoReg_Read32(DI_DICMP_COMP_SETTING_VADDR);
	dicmp_comp_setting_reg.cmp_rgb_yc_sel = 1;// Ycbcr
	dicmp_comp_setting_reg.cmp_channel_bits = !(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT));
	dicmp_comp_setting_reg.short_term_bits = bit_num;
	dicmp_comp_setting_reg.frame_bits = bit_num;
	dicmp_comp_setting_reg.max_pixel_bits = bit_num;
	dicmp_comp_setting_reg.cmp_a_ch_mark = 1; // a channel is not used
	dicmp_decomp_setting_reg.regValue = IoReg_Read32(DI_DICMP_DECOMP_SETTING_VADDR);
	dicmp_decomp_setting_reg.decmp_frame_bits = dicmp_comp_setting_reg.frame_bits;
	dicmp_decomp_setting_reg.decmp_channel_bits = dicmp_comp_setting_reg.cmp_channel_bits;
	dicmp_decomp_setting_reg.decmp_a_ch_mark = 1; // a channel is not used
	dicmp_decomp_setting_reg.decmp_rgb_yc_sel = 1; // Ycbcr
	dicmp_decomp_setting_reg.decmp_fl_mode = 1; //frame mode
	IoReg_Write32(DI_DICMP_COMP_SETTING_VADDR, dicmp_comp_setting_reg.regValue);
	IoReg_Write32(DI_DICMP_DECOMP_SETTING_VADDR, dicmp_decomp_setting_reg.regValue);
	IoReg_Write32(DI_DICMP_DECMP_RESOLUTION_VADDR, dicmp_decmp_resolution_reg.regValue);
	IoReg_Write32(DI_DICMP_CMP_RESOLUTION_VADDR, dicmp_cmp_resolution_reg.regValue);
#endif
}
#endif

/*============================================================================*/
/**
 * drv_memory_disable_di_write_req
 * Set DI DMA multi-request num
 *
 * @param <disableDiWr> {1: disable DI request, 0: enable DI request}
 * @return { none }
 * @note
 * disable DI request when 3DDI state change
 *
 */
void drv_memory_disable_di_write_req(unsigned char disableDiWr)
{
	di_di_dma_multi_req_num_RBUS di_dma_multi_req_num_reg;

	di_dma_multi_req_num_reg.regValue = IoReg_Read32(DI_DI_DMA_Multi_Req_Num_reg);
	di_dma_multi_req_num_reg.rdma_req_num = 3;//(enable? 3: 0);
	di_dma_multi_req_num_reg.wdma_req_num = (disableDiWr? 0: 2);
	IoReg_Write32(DI_DI_DMA_Multi_Req_Num_reg, di_dma_multi_req_num_reg.regValue);

	return;
}

/*============================================================================*/
/**
 * drv_memory_set_ip_fifo
 * Set IP (video process) memory FIFO registers according to its FIFO-type
 *
 * @param <info> { display-info struecture }
 * @param <bits> { 10bit => 1, 8bit => 0}
 * @param <access> { 5A => 1, 3A => 0, rtnr => 2}
 * @return { none }
 * @note
 * Field size(32 Bits) = [20 * h_size * v_size] / 64 * 2  for 3A
 * Field size(32 Bits) = [16 * h_size * v_size] / 64 * 2  for 5A
 *
 */
//#define ENABLE_DI_COMPRESS
void drv_memory_set_ip_fifo(unsigned char access)
{
#ifdef Mer2_MEMORY_ALLOC
	drv_memory_set_ip_fifo_Mer2(access);
	return;
#else
	typedef struct _MEMSET {
		unsigned int number;
		unsigned int length;
		unsigned int remain;
		unsigned int water_level;
	} MEMSET;
	//di_im_di_btr_control_RBUS BTR_Control_Reg;
	di_ddr_rdatdma_wtlennum_RBUS ddr_rdatdma_wtlennum;
	di_ddr_rinfdma_wtlennum_RBUS ddr_rinfdma_wtlennum;
	di_ddr_wdatdma_wtlennum_RBUS ddr_wdatdma_wtlennum;
	di_ddr_winfdma_wtlennum_RBUS ddr_winfdma_wtlennum;
	di_ddr_datdma_rm_RBUS ddr_datdma_rm;
	di_ddr_infdma_rm_RBUS ddr_infdma_rm;
	//di_di_dma_multi_req_num_RBUS di_dma_multi_req_num_reg;
	//ddr_vrfifo1wtlvllennum_RBUS ddr_vrfifowtlvllennum;
	//ddr_vwfifo1wtlvllennum_RBUS ddr_vwfifowtlvllennum;
	//ddr_vfifo1rdwrremainder_RBUS ddr_vfifordwrremainder;

	unsigned int	DI_Width = 0, DI_Height = 0, size_per_frame = 0;
	unsigned char	data_bitNum = 0, info_bitNum = 0, i = 0, DIAllocateBlock;
	unsigned int	data_value, info_value=0, MemStartAddr;
	MEMSET			data_r, data_w, info_r, info_w;

	UINT32 lineSize_odd_128, lineSize_even_128;
	unsigned char DI_SMD_enable = 0;

	unsigned char source=255;
	unsigned char newRTNR_onoff = 0;
	unsigned char m_rtnrcompress = 0;
	unsigned char DI_BTR_enable = 0;
	unsigned char DI_BTR_type = 0;
	unsigned int buffer_alloc = 0;
	unsigned int data_size = 0;
	unsigned int info_size = 0;

//fixme:vip
#if 1
	extern Scaler_DI_Coef_t Scaler_DI_Coef_table[VIP_QUALITY_SOURCE_NUM];
	source = fwif_vip_source_check(3, 0);
	if(source >= VIP_QUALITY_SOURCE_NUM)
	{
		pr_err("\r\n#####drv_memory_set_ip_fifo source nunber %d error####\r\n", source);
		source = VIP_QUALITY_SOURCE_NUM-1;
	}
	//frank@1018 add below code to solve scan tool warning
	newRTNR_onoff = (unsigned char)Scaler_DI_Coef_table[source].newRTNR_style;
	//DI_SMD_enable = Scaler_getDI_SMD_en(source);
	DI_SMD_enable = Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE);
		DI_BTR_enable = drv_memory_get_ip_Btr_mode();

	//BTR_Control_Reg.regValue = rtd_inl(DI_IM_DI_BTR_CONTROL_VADDR);
	//DI_BTR_type = BTR_Control_Reg.btr_solutiontype;
	DI_BTR_type = (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) < 960)?0:1;
#endif

		DI_Width = Scaler_DispGetInputInfo(SLR_INPUT_DI_WID);
		DI_Height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);

	pr_debug("\n DI Memory set FIFO !");
	pr_debug("\n Width:%d, Height:%d, DMA mode=%d", DI_Width, DI_Height, drv_memory_get_ip_DMA420_mode()?420:422);
	pr_debug("\n Data status Y=%d C=%d", fw_scalerip_get_DI_chroma_10bits()?10:8, fw_scalerip_get_DI_chroma_10bits()?10:8);
	pr_debug("\n Info status BTR=%d(type:%d) SMD=%d RTNR style=%d", DI_BTR_enable, DI_BTR_type, DI_SMD_enable, newRTNR_onoff);



	printk(KERN_EMERG"\n DI Memory set FIFO !");
	printk(KERN_EMERG"\n Width:%d, Height:%d, DMA mode=%d", DI_Width, DI_Height, drv_memory_get_ip_DMA420_mode()?420:422);
	printk(KERN_EMERG"\n Data status Y=%d C=%d", fw_scalerip_get_DI_chroma_10bits()?10:8, fw_scalerip_get_DI_chroma_10bits()?10:8);
	printk(KERN_EMERG"\n Info status BTR=%d(type:%d) SMD=%d RTNR style=%d", DI_BTR_enable, DI_BTR_type, DI_SMD_enable, newRTNR_onoff);





#ifdef Mag2_New_Flow
	data_bitNum = 16; // for YUV subsample 422 ( now only using 2 typr : 422 & 420	)
	info_bitNum = 0;

	// assign data bits
	if (fw_scalerip_get_DI_chroma_10bits())
		data_bitNum += 2;
	if (fw_scalerip_get_DI_chroma_10bits())
		data_bitNum += 2;

#ifdef ENABLE_DI_COMPRESS
	if ((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) > 2048)
		&& (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 1200)) {	// 4k2k
		drv_memory_set_ip_compress_bit(12);
		m_rtnrcompress = 1;
		data_bitNum = 12;
	}
#endif

	/*
		LearnRPG comment DI DMA how to use?
		from magellan/sirius/mac3
		FIFO length is 64bits, SD need 2(128bits), HD need 4(SD double), progressive need 6
		about READ(from DDR to FIFO) the best performance is using water_level+length = FIFO length
		about WRITE(from FIFO to DDR) must just MATCH, otherwise will have dummy data in FIFO
	*/
	// assign info bits
	if (access == SLR_DI_5A_mode) {
		pr_debug("\n 5A mode \n");
		printk(KERN_EMERG"\n 5A mode \n");

		info_bitNum += (DI_BTR_enable?(DI_BTR_type?4:8):0); // type A:8 bits, type B:4 bits

		DIAllocateBlock = 4;

		data_r.water_level = 68;
		data_r.length = 60;

		data_w.water_level = 60;
		data_w.length = 60;

		info_r.water_level = 32;
		info_r.length = 32;

		info_w.water_level = 32;
		info_w.length = 32;
	} else if (access == SLR_DI_3A_mode) {
		pr_debug("\n 3A mode \n");
		printk(KERN_EMERG"\n 3A mode \n");

		info_bitNum += (DI_BTR_enable?4:0); // type A:8 bits, type B:4 bits, 3A only type B
		info_bitNum += 4; // frame motion in 3A default need 4 bits

		DIAllocateBlock = 2;

		data_r.water_level = 196;
		data_r.length = 60;

		data_w.water_level = 60;
		data_w.length = 60;

		info_r.water_level = 32;
		info_r.length = 32;

		info_w.water_level = 32;
		info_w.length = 32;
	} else if (access == SLR_DI_progress_mode) {
		pr_debug("\n progress mode \n");

		printk(KERN_EMERG"\n progress mode \n");
		DIAllocateBlock = 2;

		//Waterlevel = 0x180 - length at PRTNR 2A case, but this value over 8bit(0xff), so give 0xff
		data_r.water_level = 0xff;
		data_r.length = 60;

		if (fwif_vip_increase_DI_water_lv())		//20150813 roger, change dat_len_r for 4k2k60p
			data_r.length = 96;

		data_w.water_level = 60;
		data_w.length = 60;

		info_r.water_level = 32;
		info_r.length = 32;

		info_w.water_level = 32;
		info_w.length = 32;
	} else {
		pr_debug("\n Error accept parameter in memory fifo \n");
		return;
	}

	if (DI_SMD_enable)
		info_bitNum += 6; //4; //merlin2 need more 2bit->4+2=6

	// if k temporal function is enabled, new rtnr need 2 bits, otherwise still 0, please refer scalerColor.cpp:fwif_color_set_RTNR_style_adjust()
	if (newRTNR_onoff == 3 || newRTNR_onoff == 4)
		info_bitNum += 2;

	pr_debug("\n Data BitNum=%d, Info BitNum=%d", data_bitNum, info_bitNum);
	printk(KERN_EMERG"\n Data BitNum=%d, Info BitNum=%d", data_bitNum, info_bitNum);

	// Calculate Data number/length/remain
	if (drv_memory_get_ip_DMA420_mode() == SLR_DMA_422_mode) { // 422 mode
		size_per_frame = DI_Width * DI_Height * data_bitNum;
		data_r.number = (int)(size_per_frame/128/data_r.length);
		data_r.remain = (size_per_frame - data_r.number*128*data_r.length + 127)/128;
		if (data_r.remain == 0 && data_r.number != 0) {
			data_r.number -= 1;
			data_r.remain = data_r.length;
		}

		data_w.number = (int)(size_per_frame/128/data_w.length);
		data_w.remain = (size_per_frame - data_w.number*128*data_w.length + 127)/128;
		if (data_w.remain == 0 && data_w.number != 0) {
			data_w.number -= 1;
			data_w.remain = data_w.length;
		}

		IoReg_ClearBits(DI_IM_DI_DMA_reg, _BIT31);
		IoReg_ClearBits(DI_IM_DI_DMA_reg, _BIT30);
	}
	else if (drv_memory_get_ip_DMA420_mode() == SLR_DMA_420_mode) { // 420 mode
		lineSize_even_128	= DI_Width * (data_bitNum - (fw_scalerip_get_DI_chroma_10bits()?10:8)); // only Y componet
		lineSize_odd_128	= DI_Width * data_bitNum; // Y and C componet

		// linesize unit 64
		if (lineSize_even_128%64 == 0)
			lineSize_even_128 /= 64;
		else
			lineSize_even_128 = (lineSize_even_128+64)/64;
		if (lineSize_odd_128%64 == 0)
			lineSize_odd_128 /= 64;
		else
			lineSize_odd_128 = (lineSize_odd_128+64)/64;

		// frame unit 128, so linesize must divide by 2
		//if (DI_Height%2 == 0)
		//	size_per_frame = ((lineSize_even_128 + lineSize_odd_128+1)/2)*(DI_Height/2);
		//else
			size_per_frame = ((lineSize_even_128+1)/2)*(DI_Height/2) + ((lineSize_odd_128+1)/2)*((DI_Height+1)/2);

		data_r.number = (int)(size_per_frame/data_r.length);
		data_r.remain = size_per_frame%data_r.length;
		if (data_r.remain == 0 && data_r.number != 0) {
			data_r.number -= 1;
			data_r.remain = data_r.length;
		}

		data_w.number = (int)(size_per_frame/data_w.length);
		data_w.remain = size_per_frame%data_w.length;
		if (data_w.remain == 0 && data_w.number != 0) {
			data_w.number -= 1;
			data_w.remain = data_w.length;
		}

		IoReg_Mask32(DI_IM_DI_DMA_reg,
			~(DI_DMA_420_EN_MASK| DI_DMA_LINESIZE_EVEN_MASK| DI_DMA_LINESIZE_ODD_MASK),
			_BIT30 | (lineSize_even_128 << DI_DMA_LINESIZE_EVEN_START_BIT) | lineSize_odd_128);

		pr_debug("\n 420 mode: linesize_even=%d, linesize_odd=%d", lineSize_even_128, lineSize_odd_128);
	}
	else { // 400 mode
		//size_per_frame = DI_Width * DI_Height * data_bitNum;
		size_per_frame = DI_Width * DI_Height * (data_bitNum - (fw_scalerip_get_DI_chroma_10bits()?10:8));
		data_r.number = (int)(size_per_frame/128/data_r.length);
		data_r.remain = (size_per_frame - data_r.number*128*data_r.length + 127)/128;
		if (data_r.remain == 0 && data_r.number != 0) {
			data_r.number -= 1;
			data_r.remain = data_r.length;
		}

		data_w.number = (int)(size_per_frame/128/data_w.length);
		data_w.remain = (size_per_frame - data_w.number*128*data_w.length + 127)/128;
		if (data_w.remain == 0 && data_w.number != 0) {
			data_w.number -= 1;
			data_w.remain = data_w.length;
		}
		IoReg_SetBits(DI_IM_DI_DMA_reg, _BIT31);
		IoReg_ClearBits(DI_IM_DI_DMA_reg, _BIT30);
	}
	IoReg_SetBits(DI_db_reg_ctl_reg, _BIT0);

	// Calculate Info number/length/remain
	size_per_frame = DI_Width * DI_Height * info_bitNum;
	if (DI_SMD_enable && access == SLR_DI_5A_mode) // Info image height must +1 for DMA setting when SMD enable in 5A case
		size_per_frame += DI_Width * 4;

	info_r.number = (int)(size_per_frame/128/info_r.length);
	info_r.remain = (size_per_frame - info_r.number*128*info_r.length + 127)/128;
	if (info_r.remain == 0 && info_r.number != 0) {
		info_r.number -= 1;
		info_r.remain = info_r.length;
	}

	info_w.number = (int)(size_per_frame/128/info_w.length);
	info_w.remain = (size_per_frame - info_w.number*128*info_w.length + 127)/128;
	if (info_w.remain == 0 && info_w.number != 0) {
		info_w.number -= 1;
		info_w.remain = info_w.length;
	}

	pr_debug("\n Data number = %d, length = %d, remain = %d, water_level = %d in setting DI Read FIFO", data_r.number, data_r.length, data_r.remain, data_r.water_level);
	pr_debug("\n Data number = %d, length = %d, remain = %d, water_level = %d in setting DI Write FIFO", data_w.number, data_w.length, data_w.remain, data_w.water_level);
	pr_debug("\n Info number = %d, length = %d, remain = %d, water_level = %d in setting DI Read FIFO", info_r.number, info_r.length, info_r.remain, info_r.water_level);
	pr_debug("\n Info number = %d, length = %d, remain = %d, water_level = %d in setting DI Write FIFO", info_w.number, info_w.length, info_w.remain, info_w.water_level);

	ddr_rdatdma_wtlennum.dat_water_r	= data_r.water_level;
	ddr_rdatdma_wtlennum.dat_len_r		= data_r.length;
	ddr_rdatdma_wtlennum.dat_num_r		= data_r.number;

	ddr_wdatdma_wtlennum.dat_water_w	= data_w.water_level;
	ddr_wdatdma_wtlennum.dat_len_w		= data_w.length;
	ddr_wdatdma_wtlennum.dat_num_w		= data_w.number;

	ddr_datdma_rm.dat_remain_r			= data_r.remain;
	ddr_datdma_rm.dat_remain_w			= data_w.remain;
	ddr_datdma_rm.rdma_remain_en		= 1;

	ddr_rinfdma_wtlennum.inf_water_r	= info_r.water_level;
	ddr_rinfdma_wtlennum.inf_len_r		= info_r.length;
	ddr_rinfdma_wtlennum.inf_num_r		= info_r.number;

	ddr_winfdma_wtlennum.inf_water_w	= info_w.water_level;
	ddr_winfdma_wtlennum.inf_len_w		= info_w.length;
	ddr_winfdma_wtlennum.inf_num_w		= info_w.number;;

	ddr_infdma_rm.inf_remain_r			= info_r.remain;
	ddr_infdma_rm.inf_remain_w			= info_w.remain;

	//remain and number both 0 will cause DMA error when 1080p switch to 576i DI will fliker eric_huang@realsil.com.cn
	if (info_r.number == 0 && info_r.remain == 0) {
		ddr_rinfdma_wtlennum.inf_num_r = 0x174;
		ddr_infdma_rm.inf_remain_r = 0x0b;
	}

	//remain and number both 0 will cause DMA error when 1080p switch to 576i DI will fliker eric_huang@realsil.com.cn
	if (info_w.number == 0 && info_w.remain == 0) {
		ddr_winfdma_wtlennum.inf_num_w = 0x174;
		ddr_infdma_rm.inf_remain_w = 0x0b;
	}

	IoReg_Write32(DI_DDR_RDATDMA_WTLENNUM_reg, ddr_rdatdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_WDATDMA_WTLENNUM_reg, ddr_wdatdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_RINFDMA_WTLENNUM_reg, ddr_rinfdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_WINFDMA_WTLENNUM_reg, ddr_winfdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_DATDMA_RM_reg, ddr_datdma_rm.regValue);
	IoReg_Write32(DI_DDR_INFDMA_RM_reg, ddr_infdma_rm.regValue);

	//frank@0514 change DI multi request to solve DI read underflow ++
	drv_memory_disable_di_write_req(FALSE);
	//frank@0514 change DI multi request to solve DI read underflow --
#else

//=======YUV subsample setting  ===========
	data_bitNum = 16; // for YUV subsample 422 ( now only using 2 typr : 422 & 420  )

	if (access == SLR_DI_5A_mode) {
		info_bitNum+= (drv_memory_get_ip_Btr_mode() == _ENABLE? 8: 0); // type A:8 bits, type B:4 bits, default is type A
	} else if (access == SLR_DI_3A_mode) {
		info_bitNum+= (drv_memory_get_ip_Btr_mode() == _ENABLE? 4: 0); // type A:8 bits, type B:4 bits, default is type A
	}

	// if k temporal function is enabled, new rtnr need 2 bits, otherwise still 0, please refer scalerColor.cpp:fwif_color_set_RTNR_style_adjust()
	if (newRTNR_onoff == 3 || newRTNR_onoff == 4) {
		info_bitNum +=2;
	}


	if(access == SLR_DI_5A_mode) {	// DI 5A
		pr_debug("\n 5A mode \n");
		//frank@0310 10bits mode
		if (fw_scalerip_get_DI_chroma_10bits()) {
			data_bitNum += 2;
		}
		//Elsie 20140117: DI chroma 10-bit needs additional memory space.
		if(fw_scalerip_get_DI_chroma_10bits())
			data_bitNum += 2;
		DIAllocateBlock = 4;
	} else if(access == SLR_DI_3A_mode){	// DI 3A
		pr_debug("\n 3A mode \n");
		//if(!drv_memory_get_ip_Btr_mode())//frank@0607 if enable BTR,info_num have add 8 bits
			info_bitNum += 4; // bitNum default + 4 in 3A mode
		if (fw_scalerip_get_DI_chroma_10bits()) {
			data_bitNum += 2;
		}
		//Elsie 20140117
		if(fw_scalerip_get_DI_chroma_10bits())
			data_bitNum += 2;

		DIAllocateBlock = 2;
	}else if(access == SLR_DI_progress_mode){
		pr_debug("\n progress mode \n");

		if (fw_scalerip_get_DI_chroma_10bits()) {
			data_bitNum += 2;
		}
		//Elsie 20140117
		if(fw_scalerip_get_DI_chroma_10bits())
			data_bitNum += 2;

	//	bitNum = bitNum;
		pr_debug("\n Data.bitNum=%x,info.bitNum=%x\n",data_bitNum,info_bitNum);

		DIAllocateBlock = 2;	//roll back to 18480. set 1.gde buffer will be writen by something and cause gde fail. josh@20090423
	} else {
		pr_debug("\n Error accept parameter in memory fifo \n");
		return;
	}

	//Elsie 20131210 sync from Mac2
	//if(DI_SMD_enable)
	//{
	//	printk("\n DI_SMD_enable \n");
	//	info_bitNum += 4;
	//}
	//Elsie 20140116: DO_SMD always on
	pr_debug("\n DI_SMD_enable \n");
	info_bitNum += 4;

#ifdef ENABLE_DI_COMPRESS
	if((Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) > 2048)
			&& (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 1200)){	// 4k2k
		drv_memory_set_ip_compress_bit(12);
		m_rtnrcompress = 1;
		data_bitNum = 12;
	}
#endif

	// [DI] DI DMA 420 config
	drv_memory_DMA420_config(&data_bitNum);

	//printk("\n=============\n");
	pr_debug("\n B.Width:%d, Height:%d, data bitNum=0x%x, info bitNum=0x%x, BTR/420=%d/%d\n",Scaler_DispGetInputInfo(SLR_INPUT_DI_WID), Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN), data_bitNum, info_bitNum, drv_memory_get_ip_Btr_mode(), drv_memory_get_ip_DMA420_mode());
	pr_debug("\n Y/C bits:%d/%d\n",fw_scalerip_get_DI_chroma_10bits(), fw_scalerip_get_DI_chroma_10bits());
	//sync code from Mac2. Start
	if(access == SLR_DI_5A_mode) {
		//frank@0725 change below water level to solve peak BW not enough from Fishtail
	//	ddr_rdatdma_wtlennum.dat_water_r = 0x20;// DI total FIFO = 256, 0x100, Read Watel = Total - length
		ddr_rdatdma_wtlennum.dat_water_r = 68;// DI total FIFO = 256, 0x100, Read Watel = Total - length
		ddr_rdatdma_wtlennum.dat_len_r= 60;   //Change only support max127 0x7F
		ddr_rinfdma_wtlennum.inf_water_r = 0x20;// DI total FIFO = 256, 0x100, Read Watel = Total - length
		ddr_rinfdma_wtlennum.inf_len_r = 0x20;   //Change only support max127 0x7F
		//DI Read Water Level, Length, Number, Remain
		data_value = (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*data_bitNum) >>12; //AT:(128*32);pacific:(64*32)
	       data_tmp = (((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*data_bitNum)-(data_value<<12)) + (128 - 1))>>7;//AT:128;pacific:64,force remain + 1 , if (remain / fifo size) != 0 , avoid to occur dirty line in last line of video [chengying  2010,4/16]
	       info_value = (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*info_bitNum) >>12; //AT:(128*32);pacific:(64*32)
	       info_tmp = (((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*info_bitNum)-(info_value<<12)) + (128 - 1))>>7;//AT:128;pacific:64,force remain + 1 , if (remain / fifo size) != 0 , avoid to occur dirty line in last line of video [chengying  2010,4/16]
	}else{
		//frank@0725 change below water level to solve peak BW not enough from Fishtail
		// if(access == SLR_DI_3A_mode)
		// 	ddr_rdatdma_wtlennum.dat_water_r = 0xe0;//0x20;// DI total FIFO = 128, 0x100, Read Watel = Total - length
		// else
		// 	ddr_rdatdma_wtlennum.dat_water_r = 0xff;

		//frank@0531 change below water level to solve peak BW not enough
		// sync from Sirius
		ddr_rdatdma_wtlennum.dat_water_r = 196;//0x60;//0x20;// DI total FIFO = 128, 0x100, Read Watel = Total - length
		ddr_rdatdma_wtlennum.dat_len_r= 60;   //Change only support max127 0x7F

		//ddr_rdatdma_wtlennum.dat_water_r = 0x60;//0x20;// DI total FIFO = 128, 0x100, Read Watel = Total - length
		// ddr_rdatdma_wtlennum.dat_len_r = 0x20;   //Change only support max127 0x7F
		ddr_rinfdma_wtlennum.inf_water_r = 0x20;// DI total FIFO = 128, 0x100, Read Watel = Total - length
		ddr_rinfdma_wtlennum.inf_len_r= 0x20;   //Change only support max127 0x7F
		//DI Read Water Level, Length, Number, Remain
		data_value = (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*data_bitNum) >>12; //AT:(128*32);pacific:(64*32)
	       data_tmp = (((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*data_bitNum)-(data_value<<12)) + (128 - 1))>>7;//AT:128;pacific:64,force remain + 1 , if (remain / fifo size) != 0 , avoid to occur dirty line in last line of video [chengying  2010,4/16]
	       info_value = (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*info_bitNum) >>12; //AT:(128*32);pacific:(64*32)
	       info_tmp = (((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*info_bitNum)-(info_value<<12)) + (128 - 1))>>7;//AT:128;pacific:64,force remain + 1 , if (remain / fifo size) != 0 , avoid to occur dirty line in last line of video [chengying  2010,4/16]
	}
	//sync code from Mac2. End
	if(drv_memory_get_ip_DMA420_mode()){
		lineSize_even_128 = (Scaler_DispGetInputInfo(SLR_INPUT_DI_WID) * (data_bitNum - ((fw_scalerip_get_DI_chroma_10bits())?10:8)));
		if((lineSize_even_128%128)==0)
			lineSize_even_128 /=128;
		else
			lineSize_even_128 = (lineSize_even_128+128)/128;

		lineSize_odd_128 = (Scaler_DispGetInputInfo(SLR_INPUT_DI_WID) * data_bitNum);
		if((lineSize_odd_128%128)==0)
			lineSize_odd_128 /=128;
		else
			lineSize_odd_128 = (lineSize_odd_128+128)/128;

		if (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)%2 == 0) {
			di420_width = (lineSize_odd_128 + lineSize_even_128)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)/2);
		} else {
			di420_width = lineSize_even_128*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)/2)+lineSize_odd_128*((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)+1)/2);
		}
		di420_value = di420_width>>5;
		di420_remain = (di420_width)%32;

		data_value = di420_value;
		data_tmp = di420_remain;
	}

	if(data_tmp == 0 && data_value!=0) { //remain can't be zero
		data_value -= 1;
		data_tmp = 60;//0x20;
	}

	if(info_tmp == 0 && info_value!=0) { //remain can't be zero
		info_value -= 1;
		info_tmp = 0x20;
	}

	pr_debug("\n Data value = %x, tmp = %x in setting DI Read FIFO \n", data_value, data_tmp);
	pr_debug("\n Info value = %x, tmp = %x in setting DI Read FIFO \n", info_value, info_tmp);


	ddr_rdatdma_wtlennum.dat_num_r=data_value;
	ddr_datdma_rm.dat_remain_r=data_tmp;
	ddr_datdma_rm.rdma_remain_en = 1;
	//remain and number both 0 will cause DMA error when 1080p switch to 576i DI will fliker eric_huang@realsil.com.cn
	if (info_value == 0 && info_tmp == 0) {
		ddr_rinfdma_wtlennum.inf_num_r=0x174;
		ddr_infdma_rm.inf_remain_r=0x0b;
	} else {
		ddr_rinfdma_wtlennum.inf_num_r=info_value;
		ddr_infdma_rm.inf_remain_r=info_tmp;
	}

	IoReg_Write32(DI_DDR_RDATDMA_WTLENNUM_reg, ddr_rdatdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_RINFDMA_WTLENNUM_reg, ddr_rinfdma_wtlennum.regValue);
	#if 1
	//sync code from Mac2. Start
	//DI Write Water Level, Length, Number, Remain
	data_value = (  Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*data_bitNum)>>12; //AT:(128*32);pacific(64*64)

	//force remain + 1 , if (remain / fifo size) != 0 , avoid to occur dirty line in last line of video [chengying  2010,4/16]
       data_tmp = ((( Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*data_bitNum)-(data_value<<12)) + (128 - 1)) >>7;//AT:128;pacific:64
	//DI Write Water Level, Length, Number, Remain
	info_value = (  Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*info_bitNum)>>12; //AT:(128*32);pacific(64*64)

	//force remain + 1 , if (remain / fifo size) != 0 , avoid to occur dirty line in last line of video [chengying  2010,4/16]
       info_tmp = ((( Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*info_bitNum)-(info_value<<12)) + (128 - 1)) >>7;//AT:128;pacific:64

	if(drv_memory_get_ip_DMA420_mode()){
		data_value = di420_value;
		data_tmp = di420_remain;
	}

        if(data_tmp == 0 && data_value!=0) { //remain can't be zero
           	data_value -= 1;
		data_tmp = 0x20;
       }

	if(info_tmp == 0 && info_value!=0) { //remain can't be zero
           	info_value -= 1;
		info_tmp = 0x20;
       }
	//sync code from Mac2. End
	#endif

	pr_debug(" Write data value = %x, tmp = %x in setting DI Write FIFO\n", data_value, data_tmp);
	pr_debug(" Info data value = %x, tmp = %x in setting DI Write FIFO\n", info_value, info_tmp);
	ddr_wdatdma_wtlennum.dat_num_w=data_value;
	ddr_datdma_rm.dat_remain_w=data_tmp;
	ddr_wdatdma_wtlennum.dat_water_w = 0x3c;
	ddr_wdatdma_wtlennum.dat_len_w = 0x3c;
	//remain and number both 0 will cause DMA error when 1080p switch to 576i DI will fliker eric_huang@realsil.com.cn
	if (info_value == 0 && info_tmp == 0) {
		ddr_winfdma_wtlennum.inf_num_w=0x174;
		ddr_infdma_rm.inf_remain_w=0x0b;
	} else {
		ddr_winfdma_wtlennum.inf_num_w=info_value;
		ddr_infdma_rm.inf_remain_w=info_tmp;
	}
	ddr_winfdma_wtlennum.inf_water_w = 0x20;
	ddr_winfdma_wtlennum.inf_len_w = 0x20;

	IoReg_Write32(DI_DDR_WDATDMA_WTLENNUM_reg, ddr_wdatdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_DATDMA_RM_reg, ddr_datdma_rm.regValue);
	IoReg_Write32(DI_DDR_WINFDMA_WTLENNUM_reg, ddr_winfdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_INFDMA_RM_reg, ddr_infdma_rm.regValue);

//frank@0514 change DI multi request to solve DI read underflow ++
	drv_memory_disable_di_write_req(FALSE);
//frank@0514 change DI multi request to solve DI read underflow --

#endif

//frank@1202 Change code to solve 1366x768 image fail problem

#if 1/*qiangzhou: added DI memory allocate with VGIP PRE info for max size start*/
#if(CONFIG_DDR_DATA_BITS == 16)
	/*if ((Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR_4x3) &&
		(Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1C12B) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1L7B)) {*/
		data_value = data_bitNum;
		info_value = info_bitNum;
		if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) > _DISP_WID){
			data_value *= _DISP_WID;
			info_value *= _DISP_WID;
		}else{
			data_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
			info_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
		}


		if(((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
			&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
			&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status()) {
			data_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
			info_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
		} else {
			data_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
			info_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
		}

		data_value = (data_value >> 3);//byte unit
		info_value = (info_value >> 3);//byte unit
//		value =(info->IPV_ACT_LEN_PRE *info->IPH_ACT_WID_PRE * bitNum)>>4;
	/*} else {
		data_value=(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*data_bitNum)>>3;	//byte unit
		info_value=(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*info_bitNum)>>3;	//byte unit
	}*/
#else
	data_value=(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)*Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*data_bitNum)>>3;	//byte unit
	info_value=(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)*Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*info_bitNum)>>3;	//byte unit
#endif

	if (drv_memory_get_ip_DMA420_mode()) {
		//sync code from Mac2. Start
		di_im_di_dma_RBUS im_di_dma;
		unsigned int di420_width;
		im_di_dma.regValue = IoReg_Read32(DI_IM_DI_DMA_reg);
		lineSize_even_128 = (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) * (data_bitNum - 8));
		if((lineSize_even_128%128)==0)
			lineSize_even_128 /=128;
		else
			lineSize_even_128 = (lineSize_even_128+128)/128;

		lineSize_odd_128 = (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) * data_bitNum);
		if((lineSize_odd_128%128)==0)
			lineSize_odd_128 /=128;
		else
			lineSize_odd_128 = (lineSize_odd_128+128)/128;

		if (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)%2 == 0) {
			di420_width = (lineSize_odd_128 + lineSize_even_128)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)/2);
		} else {
			di420_width = lineSize_even_128*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)/2)+lineSize_odd_128*((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)+1)/2);
		}
		data_value = di420_width<<4;
		//sync code from Mac2. End
	}
#endif/*qiangzhou: added DI memory allocate with VGIP PRE info for max size end*/

	drvif_memory_free_block(MEMIDX_DI);

	// Set 32 avoid to cover other block memroy ([[h * v * bitnum] / (64* 2) ]* 16
	data_value = drvif_memory_get_data_align(data_value, 32);
	info_value = drvif_memory_get_data_align(info_value, 32);
	//frank@0707 when 3D mode DI must allocate 2 X memory

#if 1//defined(ENABLE_DRIVER_I3DDMA)|| defined(ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE)
	//3D mode DI memory allocate x2: 3D frame sequence input video
	if(drvif_scaler3d_get_IDMA3dMode()
		|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
			&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
			&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())) {
		data_value *= 2;
		info_value *= 2;
	}
#endif

#if 1
	drv_memory_di_alloc_buffer_set(Scaler_InputSrcGetMainChType(),fw_scalerip_get_DI_chroma_10bits());
	buffer_alloc=drv_memory_di_alloc_buffer_get();
	data_size=drv_memory_di_data_size_get(access,Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE));
	info_size=drv_memory_di_info_size_get(access);
#ifdef CONFIG_I2RND_ENABLE
	//add I2rnd condition @Crixus 20160716
	if(!((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC))){
		//printk(KERN_EMERG"[%s][crixus]DI non-i2rnd memory allocation\n", __FUNCTION__);
#endif
		//define at makeconfig
		//patch for DI/RTNR bug(overwrite 512Byte)
		if(drvif_scaler3d_get_IDMA3dMode()
			|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
				&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
				&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())){

			if(access != 2){
				MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value * DIAllocateBlock+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
			}
			else{
#ifdef ENABLE_DI_COMPRESS
				if(m_rtnrcompress){//compress mode use 2 buffer
					MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value*2+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
				}
				else
#endif
				{
					MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
				}
			}
		} else {
			MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, buffer_alloc, MEMALIGN_ANY);
		}
		if(MemStartAddr == _DUMMYADDR){
			rtd_printk(KERN_EMERG , TAG_NAME, "set MEMIDX_DI  to size fail !!!\n");
		}
#ifdef CONFIG_I2RND_ENABLE
		//printk(KERN_EMERG"[%s][crixus]DI non-i2rnd MemStartAddr = %x\n", __FUNCTION__, MemStartAddr);

	}
	else{//I2rnd case - allocate DI 2 memory
		//printk(KERN_EMERG"[%s][crixus]DI i2rnd second memory allocation\n", __FUNCTION__);
		if(drvif_scaler3d_get_IDMA3dMode()
			|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
			&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
			&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())){
			if(access != 2){
				MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI_2, data_value * DIAllocateBlock+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
			}
			else{
#ifdef ENABLE_DI_COMPRESS
				if(m_rtnrcompress){//compress mode use 2 buffer
					MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI_2, data_value*2+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
				}
				else
#endif
				{
					MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI_2, data_value+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
				}
			}
		} else {
			MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI_2, buffer_alloc, MEMALIGN_ANY);
		}
		if(MemStartAddr == _DUMMYADDR){
			rtd_printk(KERN_EMERG , TAG_NAME, "set MEMIDX_DI_2  to size fail !!!\n");
		}
		//printk(KERN_EMERG"[%s][crixus]DI i2rnd MemStartAddr = %x\n", __FUNCTION__, MemStartAddr);
	}
#endif
#else
	if(access != 2)
		MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value * DIAllocateBlock+info_value*2, MEMALIGN_ANY);
	else{
		if(m_rtnrcompress)//compress mode use 2 buffer
			MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value*2+info_value*2, MEMALIGN_ANY);
		else
			MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value+info_value*2, MEMALIGN_ANY);
	}
#endif
	//ScalerMemory_Printf("Get ip addr = %x, size=%x\n", MemStartAddr, (data_value * DIAllocateBlock+info_value*2));

#if 1//defined(ENABLE_DRIVER_I3DDMA)|| defined(ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE)
	//3D mode DI memory allocate x2: 3D frame sequence input video
	if(drvif_scaler3d_get_IDMA3dMode()
		|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
			&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
			&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())) {
		data_value /= 2;
		info_value /= 2;
	}
#endif

#ifdef CONFIG_I2RND_ENABLE
	//add I2rnd condition @Crixus 20160716
	if(!((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC))){
		//printk(KERN_EMERG"[%s][crixus]DI non-i2rnd set start address\n", __FUNCTION__);
#endif
		if(drvif_scaler3d_get_IDMA3dMode()
				|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
					&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
					&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status()))
		{
			// Set start address for deinterlace
			for(i = 0; i < 4; i++) {
				pr_debug(" IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_DATMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				if((access != SLR_DI_progress_mode)|| m_rtnrcompress)
					MemStartAddr += data_value;//data_value;
			}

			if((access == SLR_DI_progress_mode)&&!m_rtnrcompress){
				MemStartAddr += data_value;
			}

			for(i = 0; i < 2; i++) {
				pr_debug(" Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_INFMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				if(access != SLR_DI_progress_mode)
					MemStartAddr += info_value;
			}
		}else {
			for(i = 0; i < 4; i++) {
				pr_debug(" IP address%x = %x\n", i, MemStartAddr);
				IoReg_Write32((DI_DI_DATMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );
				if((access != SLR_DI_progress_mode)|| m_rtnrcompress)
					MemStartAddr += data_size;//data_value;
			}
			if((access == SLR_DI_progress_mode)&&!m_rtnrcompress){
				MemStartAddr += data_size;
			}

			for(i = 0; i < 2; i++) {
				pr_debug(" Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_INFMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				if(access != SLR_DI_progress_mode)
					MemStartAddr += info_size;
			}
		}

#if 1//defined(ENABLE_DRIVER_I3DDMA)|| defined(ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE)
		if(drvif_scaler3d_get_IDMA3dMode()
			|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
				&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
				&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())) {
			for(i = 0; i < 4; i++) {
				pr_debug(" 3D IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_DATMemoryStartAdd1_3D_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				if((access != SLR_DI_progress_mode)|| m_rtnrcompress)
					MemStartAddr += data_value;
			}

			if((access == SLR_DI_progress_mode) && !m_rtnrcompress){
				MemStartAddr += data_value;
			}

			for(i = 0; i < 2; i++) {
				pr_debug(" 3D Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_INFMemoryStartAdd1_3D_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				if(access != SLR_DI_progress_mode)
					MemStartAddr += info_value;
			}
		}
#endif
#ifdef CONFIG_I2RND_ENABLE
	}
	else{//I2rnd case - set DI memory start address

		//printk(KERN_EMERG"[%s][crixus]DI i2rnd set start address\n", __FUNCTION__);
		if(drvif_scaler3d_get_IDMA3dMode()
				|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
					&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
					&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status()))
		{
			// Set start address for deinterlace
			for(i = 0; i < 4; i++) {
				pr_debug(" IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_I2R_DATMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				if((access != SLR_DI_progress_mode)|| m_rtnrcompress)
					MemStartAddr += data_value;//data_value;
			}

			if((access == SLR_DI_progress_mode)&&!m_rtnrcompress){
				MemStartAddr += data_value;
			}

			for(i = 0; i < 2; i++) {
				pr_debug(" Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_I2R_INFMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				if(access != SLR_DI_progress_mode)
					MemStartAddr += info_value;
			}
		}else {
			for(i = 0; i < 4; i++) {
				pr_debug(" IP address%x = %x\n", i, MemStartAddr);
				IoReg_Write32((DI_DI_I2R_DATMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );
				if((access != SLR_DI_progress_mode)|| m_rtnrcompress)
					MemStartAddr += data_size;//data_value;
			}
			if((access == SLR_DI_progress_mode)&&!m_rtnrcompress){
				MemStartAddr += data_size;
			}

			for(i = 0; i < 2; i++) {
				pr_debug(" Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_I2R_INFMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				if(access != SLR_DI_progress_mode)
					MemStartAddr += info_size;
			}
		}

#if 1//defined(ENABLE_DRIVER_I3DDMA)|| defined(ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE)
		if(drvif_scaler3d_get_IDMA3dMode()
			|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
				&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
				&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())) {
			for(i = 0; i < 4; i++) {
				pr_debug(" 3D IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_I2R_DATMemoryStartAdd1_3D_reg+ (i << 2)),	(MemStartAddr&0x7FFFFFFF) );

				if((access != SLR_DI_progress_mode)|| m_rtnrcompress)
					MemStartAddr += data_value;
			}

			if((access == SLR_DI_progress_mode) && !m_rtnrcompress){
				MemStartAddr += data_value;
			}

			for(i = 0; i < 2; i++) {
				pr_debug(" 3D Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_I2R_INFMemoryStartAdd1_3D_reg+ (i << 2)),	(MemStartAddr&0x7FFFFFFF) );

				if(access != SLR_DI_progress_mode)
					MemStartAddr += info_value;
			}
		}
#endif
	}
#endif

	return;
#endif
}


UINT32 drv_memory_di_pqc_get_dataSize(UINT16 height, UINT16 width, UINT8 access)
{

	printk("[DI] scalerMemory.cpp::drv_memory_di_pqc_get_dataSize() calling...\n");

	UINT32 data_value = 0, data_remain = 0;
	UINT8 data_bitNum = 0;

	di_ddr_rdatdma_wtlennum_RBUS rdatdma_wtlennum_reg;
	di_ddr_wdatdma_wtlennum_RBUS wdatdma_wtlennum_reg;
	di_ddr_datdma_rm_RBUS ddr_datdma_rm_reg;
	rdatdma_wtlennum_reg.regValue = IoReg_Read32(DI_DDR_RDATDMA_WTLENNUM_reg);
	wdatdma_wtlennum_reg.regValue = IoReg_Read32(DI_DDR_WDATDMA_WTLENNUM_reg);
	ddr_datdma_rm_reg.regValue = IoReg_Read32(DI_DDR_DATDMA_RM_reg);

	if (access == 0) // 3A mode
	{

	}
	else if (access == 1) // 5A mode
	{

	}
	else if (access == 2) // progressuve mode
	{
		ddr_datdma_rm_reg.rdma_remain_en = 0;
		//ddr_datdma_rm_reg.dat_remain_w = data_remain
	 	//ddr_datdma_rm_reg.dat_remain_r = data_remain


		data_value = (height * width * data_bitNum) >> 3;	//byte unit

		// defaule in PQ compression
		rdatdma_wtlennum_reg.dat_num_r = 0x2a2; // = data_value;
		rdatdma_wtlennum_reg.dat_len_r = 0x20; // = 60;
		wdatdma_wtlennum_reg.dat_num_w = 0x2a2; // = data_value;
		wdatdma_wtlennum_reg.dat_len_w = 0x20; // = 60;

		rdatdma_wtlennum_reg.dat_water_r = 256 - 32; // Read Watel = Total - length, p mode total = 256
		wdatdma_wtlennum_reg.dat_water_w = 0x20; // write Watel = length

		IoReg_Write32(DI_DDR_RDATDMA_WTLENNUM_reg, rdatdma_wtlennum_reg.regValue);
		IoReg_Write32(DI_DDR_WDATDMA_WTLENNUM_reg, wdatdma_wtlennum_reg.regValue);
		IoReg_Write32(DI_DDR_DATDMA_RM_reg, ddr_datdma_rm_reg.regValue);

		printk("drv_memory_di_pqc_get_dataSize(): progress_mode Data BbtNum = %x\n", data_bitNum);

	}

	printk("drv_memory_di_pqc_get_dataSize(): Data value = %x, remain = %x\n", data_value, data_remain);

	return data_value;
}
UINT32 drv_memory_di_pqc_get_infoSize(UINT16 height, UINT16 width, UINT8 access)
{
	printk("[DI] scalerMemory.cpp::drv_memory_di_pqc_get_infoSize() calling...\n");

	UINT32 info_value = 0, info_remain = 0;
	UINT8 info_bitNum = 0, newRTNR_onoff = 0, source = 255;

	di_ddr_rinfdma_wtlennum_RBUS rinfdma_wtlennum_reg;
	di_ddr_winfdma_wtlennum_RBUS winfdma_wtlennum_reg;
	di_ddr_infdma_rm_RBUS ddr_infdma_rm_reg;
	rinfdma_wtlennum_reg.regValue = IoReg_Read32(DI_DDR_RINFDMA_WTLENNUM_reg);
	winfdma_wtlennum_reg.regValue = IoReg_Read32(DI_DDR_WINFDMA_WTLENNUM_reg);
	ddr_infdma_rm_reg.regValue = IoReg_Read32(DI_DDR_INFDMA_RM_reg);

	extern Scaler_DI_Coef_t Scaler_DI_Coef_table[VIP_QUALITY_SOURCE_NUM];
	source = fwif_vip_source_check(3, 0);
	newRTNR_onoff = (unsigned char)Scaler_DI_Coef_table[source].newRTNR_style;

	printk("drv_memory_di_pqc_get_infoSize(): RTNR style = %x\n", newRTNR_onoff);

	// if rtnr k temporal function is enabled, new rtnr need 2 bits, otherwise still 0
	if (newRTNR_onoff == 3 || newRTNR_onoff == 4)
	{
		info_bitNum += 2;
	}

	if (access == 0)  // 3A mode
	{

	}
	else if(access == 1)  // 5A mode
	{

	}
	else if (access == 2)  // progressive mode
	{


		info_value = (height * width * info_bitNum) >> 3;	//byte unit

		//remain and number both 0 will cause DMA error when 1080p switch to 576i DI will fliker eric_huang@realsil.com.cn
		if(info_value == 0 && info_remain == 0)
		{
			// Default
			rinfdma_wtlennum_reg.inf_num_r = 0x2a2;
			ddr_infdma_rm_reg.inf_remain_r = 0x20;
			winfdma_wtlennum_reg.inf_num_w = 0x2a2;
			ddr_infdma_rm_reg.inf_remain_w = 0x20;
		}
		else
		{
			info_remain = 0x20;

			rinfdma_wtlennum_reg.inf_num_r = info_value;
			ddr_infdma_rm_reg.inf_remain_r = info_remain;
			winfdma_wtlennum_reg.inf_num_w = info_value;
			ddr_infdma_rm_reg.inf_remain_w = info_remain;
		}

		rinfdma_wtlennum_reg.inf_len_r = 0x20;
		rinfdma_wtlennum_reg.inf_water_r = 0x20;
		winfdma_wtlennum_reg.inf_len_w = 0x20;
		winfdma_wtlennum_reg.inf_water_w = 0x20;

		IoReg_Write32(DI_DDR_RINFDMA_WTLENNUM_reg, rinfdma_wtlennum_reg.regValue);
		IoReg_Write32(DI_DDR_WINFDMA_WTLENNUM_reg, winfdma_wtlennum_reg.regValue);
		IoReg_Write32(DI_DDR_INFDMA_RM_reg, ddr_infdma_rm_reg.regValue);

		printk("drv_memory_di_pqc_get_infoSize(): progress_mode info.bitNum=%x\n", info_bitNum);

	}

	printk("drv_memory_di_pqc_get_infoSize(): Info value = %x, remain = %x \n", info_value, info_remain);

	return info_value;
}
void drv_memory_di_pqc_set_startAddress(UINT32 data_value, UINT32 info_value, UINT8 access)
{
	printk("[DI] scalerMemory.cpp::drv_memory_di_pqc_set_startAddress() calling...\n");

	UINT32 MemStartAddr;
	UINT8 i;
	drvif_memory_free_block(MEMIDX_DI);

	data_value = drvif_memory_get_data_align(data_value, 128);
	info_value = drvif_memory_get_data_align(info_value, 128);

	MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value + info_value * 2, MEMALIGN_ANY);

	// Set start address for deinterlace
	for(i = 0; i < 2; i++)
	{
		printk(" Data IP address%x = %x\n", i, MemStartAddr);

		IoReg_Write32((DI_DI_DATMemoryStartAdd1_reg + (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

		if(access != 2) // 3A & 5A
			MemStartAddr += data_value;
	}

	MemStartAddr += data_value;

	for(i = 0; i < 2; i++)
	{
		printk(" Info IP address%x = %x\n", i, MemStartAddr);

		IoReg_Write32((DI_DI_INFMemoryStartAdd1_reg + (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

		if(access != 2) // 3A & 5A
			MemStartAddr += info_value;
	}

}

void drv_memory_di_pqc_setting(UINT16 height, UINT16 width, UINT8 bitsPerPixel, int dataColor, int dataFormat)
{
	// PQC enable
	di_di_pq_cmp_RBUS pq_cmp_reg;
	pq_cmp_reg.regValue = IoReg_Read32(DI_DI_PQ_CMP_reg);
	pq_cmp_reg.cmp_en = 1;
	pq_cmp_reg.cmp_width_div32 = width >> 5;
	pq_cmp_reg.cmp_height = height;
	IoReg_Write32(DI_DI_PQ_CMP_reg,pq_cmp_reg.regValue);

	di_di_pq_decmp_RBUS pq_decmp_reg;
	pq_decmp_reg.regValue = IoReg_Read32(DI_DI_PQ_DECMP_reg);
	pq_decmp_reg.decmp_en = 1;
	pq_decmp_reg.decmp_width_div32 = width >> 5;
	pq_decmp_reg.decmp_height = height;
	IoReg_Write32(DI_DI_PQ_DECMP_reg,pq_decmp_reg.regValue);

	// Saturation enable
	di_di_pq_decmp_sat_en_RBUS pq_decmp_sat_en_reg;
	pq_decmp_sat_en_reg.regValue = IoReg_Read32(DI_DI_PQ_DECMP_SAT_EN_reg);
	pq_decmp_sat_en_reg.saturation_en = 1;
	IoReg_Write32(DI_DI_PQ_DECMP_SAT_EN_reg,pq_decmp_sat_en_reg.regValue);

	// Compression ratio
	di_di_pq_cmp_bit_RBUS pq_cmp_bit_reg;
	pq_cmp_bit_reg.regValue = IoReg_Read32(DI_DI_PQ_CMP_BIT_reg);
	pq_cmp_bit_reg.frame_limit_bit = bitsPerPixel;
	IoReg_Write32(DI_DI_PQ_CMP_BIT_reg, pq_cmp_bit_reg.regValue);

	// cmp, decmp pair setting
	//
	// dataFormat = 0: 444
	//	 		  = 1: 422
	//	 		  = 2: 420 --> not support RGB compression
	//	 		  = 3: 400 --> not support RGB compression
	//
	// dataColor = 0: RGB Compression
	// 			 = 1: YUV Compression
	//
	di_di_pq_cmp_pair_RBUS pq_cmp_pair_reg;
	pq_cmp_pair_reg.regValue =  IoReg_Read32(DI_DI_PQ_CMP_PAIR_reg);
	pq_cmp_pair_reg.cmp_data_bit_width = 1;
	pq_cmp_pair_reg.cmp_data_color = dataColor;

	di_di_pq_decmp_pair_RBUS pq_decmp_pair_reg;
	pq_decmp_pair_reg.regValue = IoReg_Read32(DI_DI_PQ_DECMP_PAIR_reg);
	pq_decmp_pair_reg.decmp_data_bit_width = 1;
	pq_decmp_pair_reg.decmp_data_color = dataColor;

	if (dataColor == 0 && (dataFormat == 2 || dataFormat == 3))
	{
		printk("[DI] scalerMemory.cpp::input value conflict...\n");
		printk("420 or 400 doesn't support RGB compression");
		return;
	}
	else
	{
		pq_cmp_pair_reg.cmp_data_format = dataFormat;
		pq_decmp_pair_reg.decmp_data_format = dataFormat;
	}

	IoReg_Write32(DI_DI_PQ_CMP_PAIR_reg, pq_cmp_pair_reg.regValue);
	IoReg_Write32(DI_DI_PQ_DECMP_PAIR_reg, pq_decmp_pair_reg.regValue);

}

// 160616 added by henry (doesn't verify)
//
// === Argument Explanation ===
//
// height & width: 4K - 3840x2160, 2K - 1920x1080
//
// access = 0: 3A
//        = 1: 5A
//        = 2: Progressive
//
// bitsPerPixel: compression ratio
//
// dataColor = 0: RGB Compression
//			 = 1: YUV Compression
//
// dataFormat = 0: 444
//			  = 1: 422
//			  = 2: 420 --> not support RGB compression
//			  = 3: 400 --> not support RGB compression
//
// === Example of using OD PQ compression function ===
//
// Video Resolution  : 4K
// Video Format      : Progressive mode
// Compression Color : RGB
// Compression Format: 422
// compression Ratio : 6bits
//
// void drvif_color_di_pqc(3840, 2160, 2, 6, 0, 1)
//
// === Sub-Function Explantion ===
//
// data_value = UINT32 drv_memory_di_pqc_get_dataSize(height, width, access)
// info_value = UINT32 drv_memory_di_pqc_get_infoSize(height, width, access)
// drv_memory_di_pqc_set_startAddress(data_value, info_value, access)
// drv_memory_di_pqc_setting(height, width, bitsPerPixel, dataColor, dataFormat);
//
// === Revision History ====
// 160622 Support RTNR, progressive mode only
//
void drv_memory_di_pqc_main(UINT16 height, UINT16 width, UINT8 access, UINT8 bitsPerPixel, int dataColor, int dataFormat)
{
	printk("[DI] scalerMemory.cpp::drvif_color_di_pqc_main() calling...\n");

	UINT32	data_value, info_value;

	// Initial Setting
	if (access == 0) // 3A mode
	{

	}
	else if (access == 1) // 5A mode
	{

	}
	else if (access == 2) // progressive mode
	{
		di_im_di_rtnr_control_RBUS rtnr_ctrl_reg;

		rtnr_ctrl_reg.regValue = IoReg_Read32(DI_IM_DI_RTNR_CONTROL_reg);

		//-- 160616 henry: 1 only progressive mode
		rtnr_ctrl_reg.cp_rtnr_interlace_force2d_en = 0;
		rtnr_ctrl_reg.cp_rtnr_progressive = 1;

		//-- 160616 henry: 2 420 400 not support RGB444
		if (dataFormat == 2 || dataFormat == 3)
			rtnr_ctrl_reg.cp_rtnr_rgb444_enable = 0;

		IoReg_Write32(DI_IM_DI_RTNR_CONTROL_reg, rtnr_ctrl_reg.regValue);
	}
	else
		printk("[ERROR - drvif_color_di_pqc_main]: access input is invalid... \n");

	data_value = drv_memory_di_pqc_get_dataSize(height, width, access);

	info_value = drv_memory_di_pqc_get_infoSize(height, width, access);

	drv_memory_di_pqc_set_startAddress(data_value, info_value, access);

	drv_memory_di_pqc_setting(height, width, bitsPerPixel, dataColor, dataFormat);

	printk("[DI] scalerMemory.cpp::drv_memory_di_pqc_main() finished...\n");
}

void drvif_memory_set_fs_display_fifo(void)
{
	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
	mdomain_cap_capture_byte_swap_RBUS capture_byte_swap_reg;
	mdomain_disp_display_byte_channel_swap_RBUS display_byte_channel_swap_reg;
	unsigned int fifoLen = _FIFOLENGTH;
	unsigned int burstLen = _BURSTLENGTH;

	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
		burstLen=0xf0;
	}

	//add below code to clear data swap let data FS content correct
	display_byte_channel_swap_reg.regValue = IoReg_Read32(MDOMAIN_DISP_Display_byte_channel_swap_reg);
	display_byte_channel_swap_reg.main_2byte_swap = 0;
	display_byte_channel_swap_reg.main_4byte_swap = 0;
	display_byte_channel_swap_reg.main_1byte_swap = 0;
	display_byte_channel_swap_reg.main_8byte_swap = 0;
	IoReg_Write32(MDOMAIN_DISP_Display_byte_channel_swap_reg, display_byte_channel_swap_reg.regValue);

	capture_byte_swap_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Capture_byte_swap_reg);
	capture_byte_swap_reg.in1_2byte_swap = 0;
	capture_byte_swap_reg.in1_4byte_swap = 0;
	capture_byte_swap_reg.in1_1byte_swap = 0;
	capture_byte_swap_reg.in1_8byte_swap = 0;
	IoReg_Write32(MDOMAIN_CAP_Capture_byte_swap_reg, capture_byte_swap_reg.regValue);

	// Set default fifo length as pixel number avoid to framesync failure
	//frank@0323 change waterlevel/2 for AT,because water level nit is 128 bits
	IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, (64 << 8) | ((fifoLen-(burstLen>>1))>>1));
	IoReg_Mask32(MDOMAIN_DISP_DDR_MainLineNum_reg, 0xfffff000, 0);

	TotalSize = memory_get_display_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY));	// calculate the memory size of capture
	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division
	if(Remainder == 0) {	// remainder is not allowed to be zero
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Write32(MDOMAIN_DISP_DDR_MainRdNumLenRem_reg, (Quotient << 16) | (burstLen << 8) | Remainder);
	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddrDropBits_reg, 0);


	//compression & de-compression setting
/*	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && (dvrif_memory_compression_get_enable() == TRUE)){
		dvrif_memory_comp_setting(TRUE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID), Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_LEN), dvrif_memory_get_compression_bits());
		IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT0);
	}else{*/
		dvrif_memory_comp_setting(FALSE, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID), Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_LEN), dvrif_memory_get_compression_bits());
		IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT0);
	//}

}

/*============================================================================*/
/**
 * drvif_memory_rotate_mp
 * Set active MP and current address for MP rottion
 *
 * @param <MpIdx> {MP window to be active}
 * @return { none }
 * @note
 * It can be called in sub display
 *
 */
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
void drvif_memory_rotate_mp(unsigned short MpIdx)
{
	unsigned int  tmpValue;
	unsigned char  MpNum;

	for (MpNum=0; MpNum<16; MpNum++) {
		if (AND(SHR(MpIdx, MpNum), 0x01))	// check each bit from LSB
			break;	// found current Mp num
	}

	MpNum = MpNum%16;
	tmpValue = Scaler_PipGetSubInfo(SLR_PIP_SUB_MPDISPBLOCKSTEP);		// get block step
	tmpValue *= MpNum*_DDR_BANK_SIZE;					// calculate the offset from start address
	tmpValue += (MemTag[MEMIDX_SUB].StartAddr);		// plus start address, update MSB & Medium bytes

	IoReg_Write32(MDOMAIN_CAP_DDR_In2Addr_reg, (tmpValue << 1) & 0x7ffffff0);

	tmpValue = IoReg_ReadByte0(MDOMAIN_DISP_DDR_SubMPMode_reg);
	tmpValue = AND((unsigned char)tmpValue, 0x0F) + SHL(MpNum, 4);	// update active MP
	IoReg_WriteByte0(MDOMAIN_DISP_DDR_SubMPMode_reg, tmpValue);
	drvif_memory_set_dbuffer_write();
}

#endif //CONFIG_DUAL_CHANNEL  // There are two channels

/*============================================================================*/
/**
 * drvif_memory_set_dbuffer_write
 * Enable double buffer write-in.
 *
 * @param <display> { main/sub display }
 * @return { none }
 * @note
 * Memory main/sub display are double buffered, those registers willbe updated
 * at the edge of Vsync of display out.
 *
 */
//void drvif_memory_set_dbuffer_write(unsigned char display)
unsigned char drvif_memory_set_dbuffer_write(void)
{
	unsigned int tmp;
	// write data & enable double buffer
	// due to mantis bug:10311, we have to write 3 times to enable double buffer register write
	//tmp = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg) | _BIT0;
	//frank@0623 add sub display double buffer reg apply
	tmp = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg) | _BIT0 | _BIT16;
	IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg, tmp);
#if 0//frank@0903 reduce scaler flow time
	tmp = 0;
	while(IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg)&_BIT0){
		//Rt_Sleep(1);//frank@0509 change delay api to speed up
		msleep(1);
		if(++tmp>40)
			break;
	}

	return (tmp > 40? FALSE: TRUE);
#else
	return TRUE;
#endif
}

/**
 * memory_get_jpeg_display_size
 * Calculate the one line memory size of JPEG display.
 * The size is counted by 4:2:2/4:4:4 data format, and frame-access/line access.
 *
 * @param <info> { disp-info structure }
 * @return { line total size }
 */
static unsigned int memory_get_jpeg_display_size(StructJPEGDisplayInfo *jpeg_info)
{
	unsigned int TotalSize;
	unsigned char ddrbit;

	if ( jpeg_info == NULL ) {
		pr_debug("[memory_get_jpeg_display_size] jpeg_info cannot be NULL.\n");
		return 0;
	}
	ddrbit = (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_DISP_10BIT) << 1)  | ( !Scaler_DispGetStatus((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_DISP_422CAP));
	TotalSize = memory_get_line_size(jpeg_info->MemWid, (ddrbit & _BIT0), ((ddrbit & _BIT1) >> 1));

	return TotalSize;
}

#if 0
/**
 * memory_get_jpeg_display_size
 * Calculate the one line memory size of JPEG display.
 * The size is counted by 4:2:2/4:4:4 data format, and frame-access/line access.
 *
 * @param <info> { disp-info structure }
 * @return { line total size }
 */
static unsigned int memory_get_osd_display_size(SCALER_DISP_CHANNEL disp, StructJPEGDisplayInfo *jpeg_info)
{
	unsigned int TotalSize;
	unsigned int LineSize;
	//unsigned char ddrbit;

	if ( jpeg_info == NULL ) {
		printk("[memory_get_jpeg_display_size] jpeg_info cannot be NULL.\n");
		return 0;
	}
	//ddrbit = (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_DISP_10BIT) << 1)  | ( !Scaler_DispGetStatus((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_DISP_422CAP));
	LineSize = jpeg_info->MemWid;
	LineSize = drvif_memory_get_data_align(LineSize*32, 64);
	TotalSize = (unsigned int)SHR(LineSize, 6);

	return TotalSize;
}
#endif
/**
 * memory_get_jpeg_capture_size
 * Calculate the memory size of capture.
 * The size is counted by 4:2:2/4:4:4 data format, and frame-access/line access.
 *
 * @param	<jpeg_info>		{ jpeg_info structure }
 * @param	<AccessType>	{ Access_Type: frame or line }
 * @return					{ size of capture }
 */
static unsigned int memory_get_jpeg_capture_size(StructJPEGDisplayInfo *jpeg_info, eMemCapAccessType AccessType)
{
	unsigned int TotalSize;
	unsigned char ddrbit;

	if ( jpeg_info == NULL ) {
		pr_debug("[memory_get_jpeg_capture_size] jpeg_info cannot be NULL.\n");
		return 0;
	}

	ddrbit =  ((Scaler_DispGetStatus((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_DISP_10BIT)) << 1 )  | ( !Scaler_DispGetStatus((SCALER_DISP_CHANNEL)SLR_MAIN_DISPLAY,SLR_DISP_422CAP));
	TotalSize = memory_get_line_size(jpeg_info->MemWid, (ddrbit & _BIT0), ((ddrbit & _BIT1) >> 1));
	TotalSize = drvif_memory_get_data_align(TotalSize, 0x04);	// it must be times of 4

	if (AccessType == MEMCAPTYPE_FRAME)
		TotalSize = TotalSize * jpeg_info->MemLen; // multiple total_lines if frame-access

	return TotalSize;
}

/**
 * drvif_memory_set_jpeg_disp_mem
 * This function is used to set display memory for JPEG.
 *
 * @param	<jpeg_info>	{ pointer of JPEG display info, set NULL for disable }
 * @return				{ none }
 * @note
 * If any one of the Memory-main registers is changed, it is necessary to write
 * P3_8B register to validate the update.
 */
void drvif_memory_set_jpeg_disp_mem(StructJPEGDisplayInfo *jpeg_info)
{
	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int LineStep;
	unsigned int fifoLen = _FIFOLENGTH;
	unsigned int burstLen = _BURSTLENGTH;

	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if((Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1) && ( !Scaler_DispGetStatus(_CHANNEL1, SLR_DISP_422CAP))){
		burstLen=0xf0;
	}

	if ( jpeg_info == NULL ) {
		pr_debug("[drvif_memory_set_jpeg_disp_mem] jpeg_info cannot be NULL.\n");
		return;
	}

	// set width and length
	//frank@0323 change waterlevel/2 for AT,because water level nit is 128 bits
	IoReg_Mask32(MDOMAIN_DISP_DDR_MainNumWTL_reg, 0xfff00000, ((jpeg_info->MemWid & 0x0FFF) << 8) | ((fifoLen-(burstLen>>1))>>1));
	IoReg_Mask32(MDOMAIN_DISP_DDR_MainLineNum_reg, 0xfffff000, (jpeg_info->MemLen & 0x0FFF));

	// set DDR_MainRdNumLenRem
	TotalSize = memory_get_jpeg_display_size(jpeg_info); // calculate the memory size of capture
	memory_division(TotalSize, burstLen, &Quotient, &Remainder); // Do a division

	if ( Remainder == 0 ) { // remainder is not allowed to be zero
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Write32(MDOMAIN_DISP_DDR_MainRdNumLenRem_reg, (Quotient << 16) | (burstLen << 8) | Remainder);

	// set line step (64-bits)
	LineStep = memory_get_jpeg_capture_size(jpeg_info, MEMCAPTYPE_LINE);		// calculate capture line size
	IoReg_Mask32(MDOMAIN_DISP_DDR_MainLineStep_reg, 0xf0000000, (LineStep + LineStep%2)<<3);//bit 3 need to be 0. rbus rule

	// set memory address
//--	WaitFor_DEN_STOP();
	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg, (jpeg_info->MemAddr)&0x7ffffff0);
}

/*
void drvif_memory_set_osd_disp_mem(StructJPEGDisplayInfo *jpeg_info)
{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
//	unsigned int LineStep;
	unsigned int fifoLen = _FIFOLENGTH2;
	unsigned int burstLen = _BURSTLENGTH2;

	if ( jpeg_info == NULL ) {
		printk("[drvif_memory_set_jpeg_disp_mem] jpeg_info cannot be NULL.\n");
		return;
	}

	// set width and length
	//frank@0323 change waterlevel/2 for AT,because water level nit is 128 bits
	IoReg_Mask32(MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0xfff00000, ((jpeg_info->MemWid & 0x0FFF) << 8) | (fifoLen-burstLen));
	IoReg_Mask32(MDOMAIN_DISP_DDR_SubLineNum_reg, 0xfffff000, (jpeg_info->MemLen & 0x0FFF));

	// set DDR_MainRdNumLenRem
	TotalSize = memory_get_osd_display_size(SLR_SUB_DISPLAY, jpeg_info); // calculate the memory size of capture
	memory_division(TotalSize, burstLen, &Quotient, &Remainder); // Do a division

	if ( Remainder == 0 ) { // remainder is not allowed to be zero
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Write32(MDOMAIN_DISP_DDR_SubRdNumLenRem_reg, (Quotient << 16) | (burstLen << 8) | Remainder);
	TotalSize = Quotient * burstLen + Remainder; 	// count one line, 64bits unit
	TotalSize = drvif_memory_get_data_align(TotalSize, 4);	// times of 4
	IoReg_Write32(MDOMAIN_DISP_DDR_SubLineStep_reg,  (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule

	// set memory address
//--	WaitFor_DEN_STOP();
	IoReg_Write32(MDOMAIN_DISP_DDR_SubAddr_reg, jpeg_info->MemAddr);
	IoReg_Write32(MDOMAIN_DISP_DDR_SubBlkStep_reg, 0);
	IoReg_WriteWord0(MDOMAIN_DISP_DDR_SubMPEn_reg,0);
	IoReg_WriteByte0(MDOMAIN_DISP_DDR_SubMPMode_reg, _BIT3);
	IoReg_SetBits(MDOMAIN_DISP_DDR_SubCtrl_reg, _BIT6);
	drvif_memory_set_dbuffer_write();
#endif
}
*/
/*unsigned char drvif_memory_regAvPresetTable(unsigned short *ptr)
{
	if(!ptr)
		return FALSE;

	tAV_PRESET_TABLE = ptr;

	return TRUE;
}*/



void memory_set_adc_capture(unsigned int CapBuf_addr, unsigned int Hight,unsigned int width) // for 10 bit 4:4:4
{
	unsigned int  TotalSize;
//	unsigned int  TotalSize1;
//	unsigned int  TotalSizeFrame;
//	unsigned int  nStartAddr;
	unsigned int  Quotient;
	unsigned char  Remainder;
	unsigned int burstLen = _BURSTLENGTH;

	//frank@0325 double the M domain burst length to avoid 444 10 bits peak BW not enough
	if(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) == _CHANNEL1){
		burstLen=0xf0;
	}

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_ClearBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg: MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask);	// disable Capture
	IoReg_ClearBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_Cap_In2_enable_reg : MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);	// disable Capture
#else
	pr_debug("[TV]: %s:%s(%d) addr=0x%x W=%d H=%d\n",__FILE__,__func__,__LINE__,CapBuf_addr,width,Hight);
	IoReg_ClearBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask);	// disable Capture
	IoReg_ClearBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0);	// disable Capture
#endif
	//frank@0503 add below delay to confirm M capture have disable
	msleep(20);

	//field polarity error check
	memory_check_capture_polarity_error(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL));

	// calculate the memory size of capture
	TotalSize = memory_get_line_size(width, 1, 1);//10 bits,444
	TotalSize = drvif_memory_get_data_align(TotalSize, 0x04);

// it must be times of 4
	TotalSize = TotalSize *Hight;	// multiple total_lines if frame-access

	IoReg_Mask32(MDOMAIN_CAP_DDR_In1LineStep_reg, 0xff000000, 0);
	memory_division(TotalSize, burstLen, &Quotient, &Remainder);	// Do a division
	Remainder = drvif_memory_get_data_align(Remainder, 4);	// multiple of 4
	if (Remainder == 0) {	// remainder is not allowed to be zero
		Remainder = burstLen;
		Quotient -= 1;
	}

	memory_set_capture_fifo(_CHANNEL1, Quotient, Remainder, burstLen);	// set capture FIFO

	TotalSize = SHL(Quotient * burstLen + Remainder, 3); //unit conversion. 64bits to 8bits
	TotalSize = SHL(TotalSize, 3); //unit conversion. 64bits to 8bits

	// set capture memory for main display
#ifndef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,0x00000008);//Set lower boundary of DDR address
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,0x7ffffffc);//Set upper boundary of DDR address
#endif
	IoReg_Write32(MDOMAIN_CAP_DDR_In1Addr_reg, CapBuf_addr & 0x7ffffff0);
	pr_debug("[TV]: %s:%s(%d) write addr=0x%x\n",__FILE__,__func__,__LINE__,CapBuf_addr);
	IoReg_Mask32(MDOMAIN_CAP_DDR_In1LineNum_reg, 0xfffee000, (1<<16)|AND(Hight, 0x1FFF));
	IoReg_Write32(MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT0);//single buffer
	//IoReg_SetBits(MDOMAIN_CAP_Cap_In1_enable_reg, _BIT0); //Capture will enable after setting DMA mode
}

#if 0
void get_adc_dump_addr_size(unsigned int *PhyAddr, unsigned int *VirStartAddr,unsigned int *Size , unsigned int *Width, unsigned int* Height)
{

	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))
	{
		PhyAddr = (unsigned int*)MemTag[MEMIDX_SUB].StartAddr;
		*VirStartAddr = get_scaler_memory_map_addr() + (MemTag[MEMIDX_SUB].StartAddr - AllocStartAddr);
		#ifndef CONFIG_ADC_DMA
		*Size = MemTag[MEMIDX_SUB].Size;

		#endif
	}
	else
	{
		*PhyAddr = MemTag[MEMIDX_MAIN].StartAddr;
		*VirStartAddr = get_scaler_memory_map_addr() + (MemTag[MEMIDX_MAIN].StartAddr - AllocStartAddr);
		#ifndef CONFIG_ADC_DMA
		*Size = MemTag[MEMIDX_MAIN].Size;
		#endif
	}

	//printk("alloc start addr=%x %x\n",AllocStartAddr,MemTag[MEMIDX_MAIN].StartAddr);

	#ifndef CONFIG_ADC_DMA
	*Width = Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID);
	*Height = Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN);
	#else
	*Width = Scaler_DispGetInputInfo(SLR_INPUT_H_LEN);
	*Height = Scaler_DispGetInputInfo(SLR_INPUT_V_LEN) * DUMP_VSYNC; // 3 vsync
	*Size= (*Height) * (*Width) * 30 / 8;
	*Size = ((*Size) & 0xfffffffc); // align to 4
	#endif

	if (*Size >= (16 * 1024 * 1024)) // scaler memory 16M
		printk("Error !! memory size is not enough !!!\n");

}



void get_frc_buf_addr_size(unsigned int *PhyAddr, unsigned int *VirStartAddr,unsigned int *Size , unsigned int *Width, unsigned int* Height)
{

	int is_10bit = 0,is_422 = 0;
	if (Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY))
	{
		PhyAddr = (unsigned int*)MemTag[MEMIDX_SUB].StartAddr;
		*VirStartAddr = get_scaler_memory_map_addr() + (MemTag[MEMIDX_SUB].StartAddr - AllocStartAddr);
		*Size = MemTag[MEMIDX_SUB].Size;

	}
	else
	{
		*PhyAddr = MemTag[MEMIDX_MAIN].StartAddr;
		*VirStartAddr = get_scaler_memory_map_addr() + (MemTag[MEMIDX_MAIN].StartAddr - AllocStartAddr);
		*Size = MemTag[MEMIDX_MAIN].Size;

	}

	//printk("alloc start addr=%x %x\n",AllocStartAddr,MemTag[MEMIDX_MAIN].StartAddr);


	is_10bit = Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_10BIT);
	is_422 = Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_422CAP);

	if (is_422)
	{
		if(is_10bit == 0)  // 422 8bit
		{
			printk("@@@422 8bit...\n");
			*Width = drvif_memory_get_data_align(Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID),16);
		}
		else	 //422 10bit
		{
			printk("@@@not support 422 10bit...\n");
			*Width = Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID);
		}
	}
	else
	{
		if(is_10bit == 0) // 444 8bit
		{
			printk("@@@444 8bit...\n");
			*Width = drvif_memory_get_data_align(Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID),192);
		}
		else
		{
			printk("@@@not support 444 10bit...\n");
			*Width = Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID);
		}
	}

	*Height = Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN);

}


void dump_frc_rawdata_start(void)
{
	if (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC))
	{
		printk("ERROR !!  framesync mode, can't dump data\n");
		return;
	}

	WaitFor_IEN_STOP1();
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_SetBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT1);	// disable Capture
#else
	IoReg_SetBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT1);	// disable Capture
#endif
		//frank@0122 solve  sub ATV switch channel flick problem
//-- check		Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? IoReg_ClearBits(BUS_SB3_ARB_CR_VADDR, _BIT3) : IoReg_ClearBits(BUS_SB3_ARB_CR_VADDR, _BIT6);
		//--			ROS_EXIT_CRITICAL();
		//fwif_scaler_wait_for_event(0xb8028100, _BIT10);//<===WaitFor_DEN_STOP();
	WaitFor_DEN_STOP();
	//test for  switch TV channel have white image --
	drvif_scaler_vactive_end_irq(_DISABLE, Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)); // CSW+ 0970710 Close auto MA in freeze mode
	drvif_scaler_vactive_sta_irq(_DISABLE, Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)); // CSW+ 0970710 Close auto MA in freeze mode

}

void dump_frc_rawdata_release(void)
{
#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
	IoReg_ClearBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT1);
#else
	IoReg_ClearBits(/*Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : */MDOMAIN_CAP_DDR_In1Ctrl_reg, _BIT1);
#endif
	drvif_scaler_vactive_end_irq(_ENABLE, Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)); // CSW+ 0970710 Open auto MA in unfreeze mode
	drvif_scaler_vactive_sta_irq(_ENABLE, Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL)); // CSW+ 0970710 Open auto MA in unfreeze mode

}

void get_vdc_dump_addr(unsigned int *PhyAddr, unsigned int *VirStartAddr)
{

	*PhyAddr  = MemTag[MEMIDX_VDC].StartAddr;

	*VirStartAddr = get_scaler_memory_map_addr() + (MemTag[MEMIDX_VDC].StartAddr - AllocStartAddr);

	printk("dump addr = %x %x\n", *PhyAddr,*VirStartAddr);

}
#endif


#ifdef CONFIG_DUMP_MEMTAG
void drvif_memory_dump_MemTag(void)
{
	pr_debug("*****Dump MemTag*****\n");
	unsigned char i;
	for ( i=0 ; i<MEMIDX_ALL ; ++i ) {
		pr_debug("idx: %d, status:%d, start addr:%d, size:%d\n",
			i, MemTag[i].Status, MemTag[i].StartAddr, MemTag[i].Size);
	}
}
#endif

void drv_memory_set_3D_SBS_LR_swap(unsigned char lr_swap)
{

	unsigned int  TotalSize=Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_BLKSTEP);
	mdomain_cap_ddr_in1addr_RBUS ddr_in1addr_reg;
	mdomain_cap_ddr_in1_2ndaddr_RBUS ddr_in1_2ndaddr_reg;
	mdomain_cap_ddr_in1_3rdaddr_RBUS ddr_in1_3rdaddr_reg;
	mdomain_cap_capmain_sbs_vsd_cap_offset_RBUS capmain_sbs_vsd_cap_offset_reg;

	ddr_in1addr_reg.regValue = IoReg_Read32(MDOMAIN_CAP_DDR_In1Addr_reg);
	ddr_in1_2ndaddr_reg.regValue = IoReg_Read32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg);
	ddr_in1_3rdaddr_reg.regValue = IoReg_Read32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg);
	capmain_sbs_vsd_cap_offset_reg.regValue = IoReg_Read32(MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg);

	if(Get_PANEL_VFLIP_ENABLE() && Scaler_InputSrcGetMainChType() == _SRC_VO)
		lr_swap = !lr_swap;
	pr_debug("drv_memory_set_3D_SBS_LR_swap , lr swap=%d\n",lr_swap);
	if(lr_swap==_TRUE)
	{
		ddr_in1addr_reg.in1_wr_mem_start=(MemTag[MEMIDX_MAIN].StartAddr>>3)+TotalSize;
		ddr_in1_2ndaddr_reg.in1_sec_bl=(MemTag[MEMIDX_MAIN_SEC].StartAddr>>3)+TotalSize;
		if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
			ddr_in1_3rdaddr_reg.in1_third_bl=(MemTag[MEMIDX_MAIN_THIRD].StartAddr>>3)+TotalSize;
		pr_debug("[3D]SBS LR main_1=%x,second_1=%x,third_1=%x\n",ddr_in1addr_reg.in1_wr_mem_start,ddr_in1_2ndaddr_reg.in1_sec_bl,ddr_in1_3rdaddr_reg.in1_third_bl);
		TotalSize=(~TotalSize)+1;
		capmain_sbs_vsd_cap_offset_reg.in1_lr_offset=TotalSize;
	}
	else
	{
		ddr_in1addr_reg.in1_wr_mem_start=MemTag[MEMIDX_MAIN].StartAddr>>3;
		ddr_in1_2ndaddr_reg.in1_sec_bl=MemTag[MEMIDX_MAIN_SEC].StartAddr>>3;
		if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
			ddr_in1_3rdaddr_reg.in1_third_bl=MemTag[MEMIDX_MAIN_THIRD].StartAddr>>3;
		capmain_sbs_vsd_cap_offset_reg.in1_lr_offset=TotalSize;
	}
	WaitFor_DEN_STOP();
	IoReg_Write32(MDOMAIN_CAP_DDR_In1Addr_reg , ddr_in1addr_reg.regValue & 0x7ffffff0);
	IoReg_Write32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg , ddr_in1_2ndaddr_reg.regValue & 0x7ffffff0);
	if(Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
		IoReg_Write32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg , ddr_in1_3rdaddr_reg.regValue & 0x7ffffff0);
	IoReg_Write32(MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg, capmain_sbs_vsd_cap_offset_reg.regValue);

}

void drv_memory_set_3D_TB_or_FP_LR_swap(unsigned char lr_swap)
{
	unsigned int  TotalSize=Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_BLKSTEP);
	mdomain_disp_ddr_mainaddr_RBUS ddr_mainaddr_reg;
	mdomain_disp_ddr_main2ndaddr_RBUS ddr_main2ndaddr_reg;
	mdomain_disp_ddr_main3rdaddr_RBUS ddr_main3rdaddr_reg;
	mdomain_disp_ddr_mainblkstep_RBUS ddr_mainblkstep_reg;

	ddr_mainaddr_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainAddr_reg);
	ddr_main2ndaddr_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_Main2ndAddr_reg);
	ddr_main3rdaddr_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_Main3rdAddr_reg);
	ddr_mainblkstep_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainBlkStep_reg);

	if(lr_swap==_TRUE)
	{
		//printk("[13D]TT&B LR main_1=%x,second_1=%x,,third_1=%x,TotalSize=%x\n",ddr_mainaddr_reg.regValue,ddr_main2ndaddr_reg.regValue,ddr_main3rdaddr_reg.regValue,TotalSize);
		ddr_mainaddr_reg.main_read_addr=(MemDispStartAddr_3D[0]>>3)+TotalSize;
		ddr_main2ndaddr_reg.main_sec_block=(MemDispStartAddr_3D[1]>>3)+TotalSize;
		if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
			ddr_main3rdaddr_reg.main_third_block=(MemDispStartAddr_3D[2]>>3)+TotalSize;
		TotalSize=(~TotalSize)+1;
		ddr_mainblkstep_reg.main_block_step=TotalSize;
		//printk("[23D]TT&B LR main_1=%x,second_1=%x,,third_1=%x,TotalSize=%x\n",ddr_mainaddr_reg.regValue,ddr_main2ndaddr_reg.regValue,ddr_main3rdaddr_reg.regValue,TotalSize);
	}
	else
	{

		//printk("[33D]TT&B LR main_1=%x,second_1=%x,,third_1=%x,TotalSize=%x\n",ddr_mainaddr_reg.regValue,ddr_main2ndaddr_reg.regValue,ddr_main3rdaddr_reg.regValue,TotalSize);
		ddr_mainaddr_reg.main_read_addr=MemDispStartAddr_3D[0]>>3;
		ddr_main2ndaddr_reg.main_sec_block=MemDispStartAddr_3D[1]>>3;
		if (Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3))
			ddr_main3rdaddr_reg.main_third_block=MemDispStartAddr_3D[2]>>3;
		ddr_mainblkstep_reg.main_block_step=TotalSize;
		//printk("[43D]TT&B LR main_1=%x,second_1=%x,,third_1=%x,TotalSize=%x\n",ddr_mainaddr_reg.regValue,ddr_main2ndaddr_reg.regValue,ddr_main3rdaddr_reg.regValue,TotalSize);
	}
	pr_debug("[3D]TT&B LR main_1=%x,second_1=%x,,third_1=%x,TotalSize=%x\n",ddr_mainaddr_reg.regValue,ddr_main2ndaddr_reg.regValue,ddr_main3rdaddr_reg.regValue,TotalSize);
	WaitFor_DEN_STOP();
	IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg , ddr_mainaddr_reg.regValue&0x7ffffff0);

	IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg , ddr_main2ndaddr_reg.regValue&0x7ffffff0);

	if ((Get_PANEL_VFLIP_ENABLE() && Scaler_DispGetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_VFLIP3)))
		IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg , (ddr_main3rdaddr_reg.regValue)&0x7ffffff0);

	ddr_mainblkstep_reg.main_block_step = (ddr_mainblkstep_reg.main_block_step % 2)? ddr_mainblkstep_reg.main_block_step + 1 : ddr_mainblkstep_reg.main_block_step;
	//bit 3 need to be 0. rbus rule
	IoReg_Write32(MDOMAIN_DISP_DDR_MainBlkStep_reg , ddr_mainblkstep_reg.regValue);

#ifndef ENABLE_SMOOTH_TOGGLE_PR3D
	drvif_memory_set_dbuffer_write();
#endif
}

void drvif_memory_set_3D_LR_swap(unsigned char lr_swap,unsigned char type_3d)
{
	switch(type_3d)
	{
		case SLR_3D_SIDE_BY_SIDE_HALF:
			drv_memory_set_3D_SBS_LR_swap(lr_swap);
			break;
		case SLR_3D_TOP_AND_BOTTOM:
		case SLR_3D_FRAME_PACKING:
			drv_memory_set_3D_TB_or_FP_LR_swap(lr_swap);
			break;
		case SLR_3D_2D_CVT_3D:
			scaler_2Dcvt3D_LR_swap((bool)lr_swap);
			break;
		default:
			break;

	}
}



#ifdef ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE // SG 3D PANEL SUPPORT ALL SOURCE 3D MODE
void drvif_memory_set_3D_LR_swap_for_SG_frc_in_mDomain(unsigned char bInvMode)
{
	unsigned int Addr1 = Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_MAIN_ADDR);
	unsigned int Addr2 = Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_MAIN_SEC_ADDR);
	unsigned int Addr3= Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_MAIN_THIRD_ADDR);
	unsigned int rFrameOffset = (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_BLKSTEP) << 3);
	unsigned char ucLRseq;
	ucLRseq = Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_LR_SEQUENCE) ^ bInvMode;

	if(modestate_get_vo3d_in_framePacking_FRC_mode()){
		unsigned int LineStep, TotalSize;
		LineStep = memory_get_capture_size(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), MEMCAPTYPE_LINE);		// calculate capture line size
		TotalSize = LineStep * Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY,SLR_INPUT_MEM_ACT_LEN);
		rFrameOffset = TotalSize << 3;
	}

	// non-IDMA SG 3D mode L/R order need do invert
	if(ucLRseq == FALSE){
		IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg, (Addr1 + rFrameOffset)&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg, (Addr2 + rFrameOffset)&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, (Addr3 + rFrameOffset)&0x7ffffff0);

		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_1ST_Addr_reg, Addr1);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_2ND_Addr_reg, Addr2);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_3RD_Addr_reg, Addr3);
	}
	else{
		IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg, Addr1&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg, Addr2&0x7ffffff0);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, Addr3&0x7ffffff0);

		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_1ST_Addr_reg, Addr1 + rFrameOffset);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_2ND_Addr_reg, Addr2 + rFrameOffset);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main_R_3RD_Addr_reg, Addr3 + rFrameOffset);
	}

	drvif_memory_set_dbuffer_write();
	return;
}
#endif



void drvif_memory_set_MVC_FRC_LR_swap(unsigned char bInvMode)
{
	unsigned char ucLRseq;
	mdomain_cap_ddr_in1ctrl_RBUS ddr_in1ctrl_reg;
	ucLRseq = Scaler_Disp3dGetInfo(SLR_MAIN_DISPLAY, SLR_DISP_3D_LR_SEQUENCE);

	ddr_in1ctrl_reg.regValue = IoReg_Read32(MDOMAIN_CAP_DDR_In1Ctrl_reg);
	// bInvMode for MVC data FRC mode (bypass IDMA)
	ddr_in1ctrl_reg.in1_l_flag_inv = ucLRseq ^ bInvMode;
	IoReg_Write32(MDOMAIN_CAP_DDR_In1Ctrl_reg, ddr_in1ctrl_reg.regValue);

	pr_debug("[SG] MVC FRC L/R Swap=%d\n", ucLRseq);

	return;
}

//USER:LewisLee DATE:2012/08/23
//to maje sure have set correct setting
//to prevent M domain setting error with video FW
void dvrif_memory_set_frc_style(UINT8 Display, UINT8 ucEnable)
{
	mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;
//	ddr_mainsubctrl_RBUS ddr_mainsubctrl_reg;

	if(SLR_MAIN_DISPLAY == Display)
	{
		ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);

		if(_ENABLE == ucEnable)
		{
			if(_DISABLE == ddr_mainctrl_reg.main_frc_style)
			{
				ddr_mainctrl_reg.main_frc_style = _ENABLE;
				IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg , ddr_mainctrl_reg.regValue);

				drvif_memory_set_dbuffer_write();
				pr_debug("dvrif_memory_set_frc_style, set input fast than display\n");
			}
		}
		else// if(_DISABLE == ucEnable)
		{
			if(_ENABLE == ddr_mainctrl_reg.main_frc_style)
			{
				ddr_mainctrl_reg.main_frc_style = _DISABLE;
				IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg , ddr_mainctrl_reg.regValue);

				drvif_memory_set_dbuffer_write();
				pr_debug("dvrif_memory_set_frc_style, set input slower than display\n");
			}
		}
	}
}

#if 0
//USER:LewisLee DATE:2012/08/16
//for some case, we need switch buffer by SW
//to fix frame tear
void drvif_memory_3D_mode_sw_buffer_swap_action(SCALER_DISP_CHANNEL ucDisplay, eMemCap_3D_Mode_SwBufferSwapState state)
{
	mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;
	mdomain_cap_ddr_in1ctrl_RBUS ddr_in1ctrl_reg;

	switch(state)
	{
		case MEM_3D_SWBUFFER_SWAP_CONDITION_CHECK:
			Scaler_Set_Enable_3D_Mode_3Buffer_SW_Switch_Condition(ucDisplay, Scaler_InputSrcGetMainChType());
		break;

		case MEM_3D_SWBUFFER_SWAP_ENABLE:
			if(_DISABLE == Scaler_Get_Enable_3D_Mode_3Buffer_SW_Switch_Condition())
				return;

#ifdef CONFIG_DUAL_CHANNEL
			if(SLR_MAIN_DISPLAY == ucDisplay)
			{
				ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
				ddr_mainctrl_reg.main_frc_style = _ENABLE;
				IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, ddr_mainctrl_reg.regValue);
			}
			else// if(SLR_SUB_DISPLAY == ucDisplay)
			{
				IoReg_Mask32(MDOMAIN_DISP_DDR_SubCtrl_reg, ~_BIT3, _BIT3);
			}
#else //#ifdef CONFIG_DUAL_CHANNEL
			ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
			ddr_mainctrl_reg.main_frc_style = _ENABLE;
			IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, ddr_mainctrl_reg.regValue);
#endif //#ifdef CONFIG_DUAL_CHANNEL

			ddr_in1ctrl_reg.regValue = IoReg_Read32(MDOMAIN_CAP_DDR_In1Ctrl_reg);
			ddr_in1ctrl_reg.in1_v_flip_3buf_en = _DISABLE;
			ddr_in1ctrl_reg.in1_double_enable = _DISABLE;
			IoReg_Write32(MDOMAIN_CAP_DDR_In1Ctrl_reg, ddr_in1ctrl_reg.regValue);
		break;

		case MEM_3D_SWBUFFER_SWAP_DISABLE:
//			if(SLR_SUB_DISPLAY == ucDisplay)
//				return;

			if(_DISABLE == Scaler_Get_Enable_3D_Mode_3Buffer_SW_Switch_Condition())
				return;

#ifdef CONFIG_DUAL_CHANNEL
			if(SLR_MAIN_DISPLAY == ucDisplay)
			{
				dvrif_memory_set_frc_style(SLR_MAIN_DISPLAY, _DISABLE);
			}
			else// if(SLR_SUB_DISPLAY == ucDisplay)
			{
				IoReg_Mask32(MDOMAIN_DISP_DDR_SubCtrl_reg, ~_BIT3, 0);
			}
#else //#ifdef CONFIG_DUAL_CHANNEL
			dvrif_memory_set_frc_style(SLR_MAIN_DISPLAY, _DISABLE);
#endif //#ifdef CONFIG_DUAL_CHANNEL
		break;

		case MEM_3D_SWBUFFER_SWAP_UPDATE_INFO:
			if(_DISABLE == Scaler_Get_Enable_3D_Mode_3Buffer_SW_Switch_Condition())
				return;

			state_update_disp3d_info();
		break;

		default:
		break;
	}
}
#endif
//Will Add for smooth toggle.
unsigned int drvif_memory_get_memtag_startaddr(UINT8 index)
{
	return MemTag[index].StartAddr;

}

void drvif_memory_set_memtag_startaddr(unsigned int addr,UINT8 index)
{
	MemTag[index].StartAddr=addr;

}

unsigned int drvif_memory_get_memtag_virtual_startaddr(UINT8 index)
{
	return MemTag[index].Allocate_VirAddr;

}

unsigned int drvif_memory_get_3d_startaddr(UINT8 index)
{
	return MemDispStartAddr_3D[index];
}

void drvif_memory_set_3d_startaddr(unsigned int addr,UINT8 index)
{

	MemDispStartAddr_3D[index]=addr;
}

StructMemBlock* drvif_memory_get_MemTag_addr(UINT8 index)
{
	return &MemTag[index];
}

void drvif_memory_set_memtag_virtual_startaddr(unsigned int addr)
{
	MemTag[MEMIDX_MAIN_THIRD].Allocate_VirAddr = addr;

}

void drvif_memory_free_fixed_virtual_memory(void)
{
	if((drvif_memory_get_memtag_virtual_startaddr(MEMIDX_MAIN_THIRD) == 0) || (M_fixed_virtual_memory_size == 0)){
		pr_debug("fixed virtual address is NULL, not to free!!\n");
		return;
	}
	dvr_unmap_memory((void *)drvif_memory_get_memtag_virtual_startaddr(MEMIDX_MAIN_THIRD), M_fixed_virtual_memory_size);
}

void drvif_memory_allocate_fixed_virtual_memory(void)
{
	MemTag[MEMIDX_MAIN_THIRD].Allocate_VirAddr = (unsigned int)dvr_remap_cached_memory(MemTag[MEMIDX_MAIN_THIRD].StartAddr, M_fixed_virtual_memory_size, __builtin_return_address(0));
}

void drvif_memory_set_mtag_info(UINT32 buffer_size, UINT8 idx){
	MemTag[idx].Allocate_StartAddr = MemTag[idx].StartAddr;
	MemTag[idx].Size = buffer_size;
	MemTag[idx].Status = ALLOCATED_FROM_PLI;
	if((idx == MEMIDX_MAIN_SEC) || (idx == MEMIDX_MAIN))
		MemTag[idx].Allocate_VirAddr = 0;//not use
}

unsigned int drvif_memory_get_fixed_virtual_memory_size(void)
{
	return M_fixed_virtual_memory_size;
}

void drvif_memory_set_fixed_virtual_memory_size(unsigned int size)
{

	M_fixed_virtual_memory_size = size;
}




//Mac new adding block mode related driver
//Crixus@20140808
void drvif_memory_block_mode_enable(bool enable)
{
	if(enable == TRUE){
		IoReg_SetBits(MDOMAIN_DISP_DDR_Main_BM_DMA_reg, _BIT0);
		pr_debug("@@@@@Enable block mode@@@@@\n");
	}
	else{
		IoReg_ClearBits(MDOMAIN_DISP_DDR_Main_BM_DMA_reg, _BIT0);
		pr_debug("@@@@@Disable block mode & run sequence mode@@@@@\n");
	}
}

void drvif_memory_block_mode_set_YC_index(unsigned int Y_index, unsigned int C_index)
{
	mdomain_disp_ddr_main_bm_dma_picset_RBUS disp_ddr_main_bm_dma_picset_reg;
	disp_ddr_main_bm_dma_picset_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_Main_BM_DMA_PICSET_reg);

	disp_ddr_main_bm_dma_picset_reg.y_ads_set1 = Y_index;
	disp_ddr_main_bm_dma_picset_reg.c_ads_set1 = C_index;

	IoReg_Write32(MDOMAIN_DISP_DDR_Main_BM_DMA_PICSET_reg, disp_ddr_main_bm_dma_picset_reg.regValue);
}

//the initial point is (0,0)
void drvif_memory_block_set_Y_offset(unsigned int Y_V_offset, unsigned int Y_H_offset, unsigned int Y_H_shift)
{
	mdomain_disp_ddr_main_bm_h_offset_RBUS disp_ddr_main_bm_h_offset_reg;
	mdomain_disp_ddr_main_bm_v_offset_RBUS disp_ddr_main_bm_v_offset_reg;

	disp_ddr_main_bm_h_offset_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_Main_BM_H_OFFSET_reg);
	disp_ddr_main_bm_v_offset_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_Main_BM_V_OFFSET_reg);

	//horizontal offset - Y
	disp_ddr_main_bm_h_offset_reg.y_h_offset = Y_H_offset;
	disp_ddr_main_bm_h_offset_reg.y_h_shift = Y_H_shift;

	//vertiacl offset - Y
	disp_ddr_main_bm_v_offset_reg.y_v_offset = Y_V_offset;

	IoReg_Write32(MDOMAIN_DISP_DDR_Main_BM_H_OFFSET_reg, disp_ddr_main_bm_h_offset_reg.regValue);
	IoReg_Write32(MDOMAIN_DISP_DDR_Main_BM_V_OFFSET_reg, disp_ddr_main_bm_v_offset_reg.regValue);
}

void drvif_memory_block_set_C_offset(unsigned int C_V_offset, unsigned int C_H_offset)
{
	mdomain_disp_ddr_main_bm_h_offset_RBUS disp_ddr_main_bm_h_offset_reg;
	mdomain_disp_ddr_main_bm_v_offset_RBUS disp_ddr_main_bm_v_offset_reg;

	disp_ddr_main_bm_h_offset_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_Main_BM_H_OFFSET_reg);
	disp_ddr_main_bm_v_offset_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_Main_BM_V_OFFSET_reg);

	//horizontal offset - C
	disp_ddr_main_bm_h_offset_reg.c_h_offset = C_H_offset;

	//vertiacl offset - C
	disp_ddr_main_bm_v_offset_reg.c_v_offset = C_V_offset;

	IoReg_Write32(MDOMAIN_DISP_DDR_Main_BM_H_OFFSET_reg, disp_ddr_main_bm_h_offset_reg.regValue);
	IoReg_Write32(MDOMAIN_DISP_DDR_Main_BM_V_OFFSET_reg, disp_ddr_main_bm_v_offset_reg.regValue);
}

#if 0//for M-domain block mode read verify
//DCU index
#include "../../../common_macarthur3/include/dc_sys_reg.h"
#define PAGE_WIDTH_SHIFT        8
#define PAGE_WIDTH             (1 << PAGE_WIDTH_SHIFT)
#define DCU_WIDTH_SCALE(width) (((width) + (PAGE_WIDTH - 1)) >> PAGE_WIDTH_SHIFT)

//#define PAGE_SHIFT             (PAGE_WIDTH_SHIFT + gPage_Size + 3)

void VBM_SetDCU (int index, int width_scale, int init_page, int x_offset, int y_offset, unsigned int *DCU_data)
{
	//rt_printf5("setDCU i %d ws %d p %d xy %d %d\n", index, width_scale, init_page, x_offset, y_offset);

  	unsigned int t0 = DC_PICT_SET_pict_width_scale (width_scale) |DC_PICT_SET_pict_init_page   (init_page) ;

  	unsigned int t1 =
    	DC_PICT_SET_OFFSET_pict_set_num      (index)
  	| DC_PICT_SET_OFFSET_pict_set_offset_x (x_offset >> 4)
  	| DC_PICT_SET_OFFSET_pict_set_offset_y (y_offset >> 2) ;

  	if ( (int)DCU_data == DC_PICT_SET_reg )
  	{
    		//VP_GetSwMutex(MUTEX_ID_DCU);
    		*(volatile unsigned int *)DC_PICT_SET_reg        = t0 ;
    		*(volatile unsigned int *)DC_PICT_SET_OFFSET_reg = t1 ;
    		//VP_PutSwMutex(MUTEX_ID_DCU);
  	}
  	else
  	{
    		DCU_data[0] = t0 ;
    		DCU_data[1] = t1 ;
  	}
}

int  VBM_GetDCUInitDataSeq (unsigned short width, unsigned int *pMemory, int index, unsigned int *DCU_data, int x_offset, int y_offset)
{
	//VBM_MEMORY_CHECK
  	unsigned int PAGE_SHIFT;
  	unsigned int gPage_Size;

  	/* check alignment */
  	//if ( (int)pMemory & ROUND_UP_DCU_SIZE )
    	//VBM_RETURN (VBM_ERR_MEMORY_UNALIGNED)
    	gPage_Size = DC_SYS_MISC_get_page_size(*(volatile unsigned int *)DC_SYS_MISC_reg);
	PAGE_SHIFT = (PAGE_WIDTH_SHIFT + gPage_Size + 3);

  	if (x_offset & 7) printk("X offset: %d should align to 8-bytes in VBM_GetDCUInitDataSeq().\n", x_offset);
  	if (y_offset & 3) printk("Y offset: %d should align to 4-bytes in VBM_GetDCUInitDataSeq().\n", y_offset);

  	VBM_SetDCU (index, DCU_WIDTH_SCALE(width), ((int)pMemory & 0x3FFFFFFF) >> PAGE_SHIFT, x_offset, y_offset, DCU_data);

  	//VBM_RETURN (VBM_SUCCESS)
}
#endif

//Disable M-disp when reset M-domain=>To Fixed DTV change issue @ Crixus 20141126
void drv_memory_Main_Disp_Enable(bool enable){
	if(enable == TRUE){
		IoReg_Write32(/*display? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_Disp_main_enable_reg,  _BIT0);
	}
	else{
		IoReg_Write32(/*display? MDOMAIN_DISP_DDR_SubCtrl_reg : */MDOMAIN_DISP_Disp_main_enable_reg,  0x0);
	}
}

unsigned char dvrif_memory_compression_get_enable(unsigned char display)
{
	if(display == SLR_MAIN_DISPLAY)
		return enable_M_compression_main;
	else
		return enable_M_compression_sub;
}
void dvrif_memory_compression_set_enable(unsigned char display, unsigned char enable)
{
	if(display == SLR_MAIN_DISPLAY)
		enable_M_compression_main = enable;
	else
		enable_M_compression_sub = enable;
}

unsigned char dvrif_memory_get_compression_bits(void)
{
	return M_compression_bits;
}
void dvrif_memory_set_compression_bits(unsigned char comp_bits)
{
	M_compression_bits=comp_bits;
}

extern unsigned char get_livezoomode_forvideofw(void);
void drvif_memory_compression_rpc(void){

	M_DOMAIN_COMPRESSION_T *mdomain_compression;
	unsigned int ulCount = 0;
	int ret;

	mdomain_compression = (M_DOMAIN_COMPRESSION_T *)Scaler_GetShareMemVirAddr(SCALERIOC_SET_MDOMAIN_COMPRESSION_ENABLE);
	ulCount = sizeof(M_DOMAIN_COMPRESSION_T) / sizeof(unsigned int);

	mdomain_compression->bOnOff = dvrif_memory_compression_get_enable(SLR_MAIN_DISPLAY);
	mdomain_compression->compbit = dvrif_memory_get_compression_bits();
	mdomain_compression->GameMode = drv_memory_get_game_mode();
	mdomain_compression->RGB444Mode = rtk_hal_vsc_GetRGB444Mode();//(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_422CAP) == FALSE) ? TRUE : FALSE;
	mdomain_compression->LivezoomMode = get_livezoomode_forvideofw();

	//change endian
	mdomain_compression->bOnOff = htonl(mdomain_compression->bOnOff);
	mdomain_compression->compbit = htonl(mdomain_compression->compbit);
	mdomain_compression->GameMode = htonl(mdomain_compression->GameMode);
	mdomain_compression->RGB444Mode = htonl(mdomain_compression->RGB444Mode);
	mdomain_compression->LivezoomMode = htonl(mdomain_compression->LivezoomMode);

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_SET_MDOMAIN_COMPRESSION_ENABLE,0,0))){
		pr_debug("[MEMC]ret=%d, SCALERIOC_SET_MDOMAIN_COMPRESSION_ENABLE RPC fail !!!\n", ret);
	}
}

void dvrif_memory_comp_setting(UINT8 enable_compression, UINT16 comp_wid, UINT16 comp_len, UINT8 comp_ratio){
	mdomain_cap_main_cmp_resolution_RBUS mdomain_cap_main_cmp_resolution_reg;
	mdomain_cap_main_comp_setting_RBUS mdomain_cap_main_comp_setting_reg;
	mdomain_disp_dispm_decmp_resolution_RBUS mdomain_disp_dispm_decmp_resolution_reg;
	mdomain_disp_dispm_decomp_setting_RBUS mdomain_disp_dispm_decomp_setting_reg;

	pr_debug("[crixus]enable_compression = %d, comp_wid = %d, comp_len = %d, comp_ratio = %d\n",enable_compression, comp_wid, comp_len, comp_ratio);

	if(enable_compression == TRUE){

		if((comp_wid % 32) != 0){
			//drop bits
			IoReg_Write32(MDOMAIN_DISP_DDR_MainAddrDropBits_reg, (32 - (comp_wid % 32)));
			comp_wid = comp_wid + (32 - (comp_wid % 32));

		}

		//capture compression setting
		mdomain_cap_main_cmp_resolution_reg.regValue = IoReg_Read32(MDOMAIN_CAP_main_cmp_resolution_reg);

		mdomain_cap_main_cmp_resolution_reg.cmp_height = comp_len;//set length
		mdomain_cap_main_cmp_resolution_reg.cmp_width = comp_wid / 32;//set width

		//compression segment setting
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID) > 4096)
			mdomain_cap_main_cmp_resolution_reg.cmp_segment = SEGMENT_2;
		else
			mdomain_cap_main_cmp_resolution_reg.cmp_segment = SEGMENT_1;
		IoReg_Write32(MDOMAIN_CAP_main_cmp_resolution_reg, mdomain_cap_main_cmp_resolution_reg.regValue);


		mdomain_cap_main_comp_setting_reg.regValue = IoReg_Read32(MDOMAIN_CAP_main_comp_setting_reg);
		//compression bits setting
		mdomain_cap_main_comp_setting_reg.frame_bits = comp_ratio;
		//compression channel bits
		if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT) == TRUE)
			mdomain_cap_main_comp_setting_reg.cmp_channel_bits = 0;
		else
			mdomain_cap_main_comp_setting_reg.cmp_channel_bits = 1;

		if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_422CAP) == TRUE){
			mdomain_cap_main_comp_setting_reg.cmp_444to422_en = 1;
			mdomain_cap_main_comp_setting_reg.cmp_rgb_yc_sel = 1;
		}else{
			mdomain_cap_main_comp_setting_reg.cmp_444to422_en = 0;
			mdomain_cap_main_comp_setting_reg.cmp_rgb_yc_sel = 1;//currently no case rgb channel
		}

		IoReg_Write32(MDOMAIN_CAP_main_comp_setting_reg, mdomain_cap_main_comp_setting_reg.regValue);


		//display de-compression setting
		mdomain_disp_dispm_decmp_resolution_reg.regValue = IoReg_Read32(MDOMAIN_DISP_dispm_decmp_resolution_reg);
		mdomain_disp_dispm_decmp_resolution_reg.decmp_height = comp_len + 1;
		mdomain_disp_dispm_decmp_resolution_reg.decmp_width = comp_wid / 32;

		//de-compression segment setting
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_CAP_WID) > 4096)
			mdomain_disp_dispm_decmp_resolution_reg.decmp_segment = SEGMENT_2;
		else
			mdomain_disp_dispm_decmp_resolution_reg.decmp_segment = SEGMENT_1;

		IoReg_Write32(MDOMAIN_DISP_dispm_decmp_resolution_reg, mdomain_disp_dispm_decmp_resolution_reg.regValue);

		mdomain_disp_dispm_decomp_setting_reg.regValue = IoReg_Read32(MDOMAIN_DISP_dispm_decomp_setting_reg);
		//de-compression channel bits
		if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_10BIT) == TRUE)
			mdomain_disp_dispm_decomp_setting_reg.decmp_channel_bits = 0;
		else
			mdomain_disp_dispm_decomp_setting_reg.decmp_channel_bits = 1;
		//decompression YUV444 @Crixus 20160902
		if(Scaler_DispGetStatus(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL), SLR_DISP_422CAP) == TRUE){
			mdomain_disp_dispm_decomp_setting_reg.decmp_444to422_en = 1;
			mdomain_disp_dispm_decomp_setting_reg.decmp_rgb_yc_sel = 1;
		}else{
			mdomain_disp_dispm_decomp_setting_reg.decmp_444to422_en = 0;
			mdomain_disp_dispm_decomp_setting_reg.decmp_rgb_yc_sel = 1;
		}

		IoReg_Write32(MDOMAIN_DISP_dispm_decomp_setting_reg, mdomain_disp_dispm_decomp_setting_reg.regValue);

		//enable clock
		IoReg_SetBits(MDOMAIN_DISP_DDR_MainCtrl_reg, _BIT21);
		//enable compression & de-compression
		IoReg_SetBits(MDOMAIN_CAP_main_comp_setting_reg, _BIT20);
		IoReg_SetBits(MDOMAIN_DISP_DDR_MainCtrl_reg, _BIT20);

		//double buffer apply
		//frank@0718 move to outside to avoid smooth toggle apply
		//IoReg_SetBits(MDOMAIN_DISP_DDR_MainSubCtrl_reg, _BIT0);
	}
	else{
		//disable compression & de-compression
		IoReg_ClearBits(MDOMAIN_CAP_main_comp_setting_reg, _BIT20);
		IoReg_ClearBits(MDOMAIN_DISP_DDR_MainCtrl_reg, _BIT20);
		//disable clock
		IoReg_ClearBits(MDOMAIN_DISP_DDR_MainCtrl_reg, _BIT21);
	}
}
unsigned int di_buffer_alloc_size,di_buffer_size;
#define DI_422_10BIT_BUFFER_SIZE (3840 * 2160 * 20 / 8)
#define DI_420_10BIT_BUFFER_SIZE (3840 * 2160 * 15 / 8)
#define DI_422_8BIT_BUFFER_SIZE (3840 * 2160 * 16 / 8)
#define DI_420_8BIT_BUFFER_SIZE (3840 * 2160 * 12 / 8)

unsigned int drv_memory_di_alloc_buffer_get(void)
{
	return di_buffer_alloc_size;
}

void drv_memory_di_alloc_buffer_set(unsigned char source, unsigned char data_10bit)
{
	di_buffer_size = DI_422_10BIT_BUFFER_SIZE;
	di_buffer_alloc_size = di_buffer_size+512;

#if 0
	if (source == _SRC_VO) {
		di_buffer_alloc_size=DI_420_10BIT_BUFFER_SIZE+512;
		di_buffer_size=DI_420_10BIT_BUFFER_SIZE;
	} else {
		di_buffer_alloc_size=DI_422_10BIT_BUFFER_SIZE+512;
		di_buffer_size=DI_422_10BIT_BUFFER_SIZE;
	}
#endif
	return;
}
unsigned int drv_memory_di_buffer_get(void)
{
	return di_buffer_size;
}

unsigned int drv_memory_di_data_size_get(unsigned char access,unsigned int source_width)
{
	unsigned int buffer_size;
	if(access==SLR_DI_progress_mode) {
		buffer_size=di_buffer_size;
	} else {
		buffer_size=0x280000;	// (1920*1080/2)*20/8+n
	}
	return buffer_size;
}
unsigned int drv_memory_di_info_size_get(unsigned char access)
{
	unsigned int buffer_size;
	if(access==SLR_DI_progress_mode) {
		buffer_size=0;
	} else {
		buffer_size=0x200000;		// (1920*1080/2)*16/8+n
	}
	return buffer_size;
}

#ifdef Mer2_MEMORY_ALLOC
unsigned char DI_Compression_Bit_Num = 0;
char drv_memory_di_Set_Compression_Bit_Num(unsigned char Bit_Num)
{
	DI_Compression_Bit_Num = Bit_Num; /* 0 = disable compression mode*/
	return 0;
}

unsigned char drv_memory_di_Get_Compression_Bit_Num(void)
{
	return DI_Compression_Bit_Num;
}

char drv_memory_di_Compression_Config(unsigned char src_idx, unsigned char access, unsigned int DI_Width, unsigned int DI_Height)
{
	//unsigned char PQC_Mode;
	unsigned char PQC_Bit_Limit;
	unsigned char PQC_Data_Format;

	di_di_pq_cmp_RBUS di_di_pq_cmp_reg;
	di_di_pq_decmp_RBUS di_di_pq_decmp_reg;
	di_di_pq_cmp_pair_RBUS di_di_pq_cmp_pair_reg;
	di_di_pq_decmp_pair_RBUS di_di_pq_decmp_pair_reg;
	di_ddr_datdma_rm_RBUS di_ddr_datdma_rm_reg;
	di_di_pq_decmp_sat_en_RBUS di_di_pq_decmp_sat_en_reg;
	di_di_pq_cmp_bit_RBUS di_di_pq_cmp_bit_reg;

	di_im_di_dma_RBUS di_im_di_dma_reg;
	/* double buffer*/
	di_db_reg_ctl_RBUS di_db_reg_ctl_reg;

	di_di_pq_cmp_reg.regValue= IoReg_Read32(DI_DI_PQ_CMP_reg);
	di_di_pq_decmp_reg.regValue = IoReg_Read32(DI_DI_PQ_DECMP_reg);
	di_di_pq_cmp_pair_reg.regValue = IoReg_Read32(DI_DI_PQ_CMP_PAIR_reg);
	di_di_pq_decmp_pair_reg.regValue = IoReg_Read32(DI_DI_PQ_DECMP_PAIR_reg);
	di_ddr_datdma_rm_reg.regValue = IoReg_Read32(DI_DDR_DATDMA_RM_reg);
	di_di_pq_decmp_sat_en_reg.regValue = IoReg_Read32(DI_DI_PQ_DECMP_SAT_EN_reg);
	di_di_pq_cmp_bit_reg.regValue = IoReg_Read32(DI_DI_PQ_CMP_BIT_reg);
	di_db_reg_ctl_reg.regValue = IoReg_Read32(DI_db_reg_ctl_reg);

	/* compression only in p mode*/	/* 1080p and 4K*/
	if (access != SLR_DI_progress_mode || DI_Height<960) {
		di_di_pq_cmp_reg.cmp_en = 0;
		di_di_pq_decmp_reg.decmp_en = 0;
		IoReg_Write32(DI_DI_PQ_CMP_reg, di_di_pq_cmp_reg.regValue);
		IoReg_Write32(DI_DI_PQ_DECMP_reg, di_di_pq_decmp_reg.regValue);
		drv_memory_di_Set_Compression_Bit_Num(0);
		return 1;
	}

	PQC_Bit_Limit = get_current_driver_pattern(DRIVER_DIPQC_BIT_PATTERN);
	PQC_Data_Format = get_current_driver_pattern(DRIVER_RTNR_PATTERN);
	rtd_printk(KERN_INFO, TAG_NAME, "PQC Bit, PQC_Bit_Limit=%d, DMA mode=%d \n", PQC_Bit_Limit, PQC_Data_Format);

	/* rdma_remain_en = 0, in compression mode*/
	di_ddr_datdma_rm_reg.rdma_remain_en = 0;
	IoReg_Write32(DI_DDR_DATDMA_RM_reg, di_ddr_datdma_rm_reg.regValue);

	di_di_pq_cmp_reg.cmp_en = 1;
	di_di_pq_cmp_reg.cmp_height = DI_Height;
	di_di_pq_cmp_reg.cmp_width_div32 = DI_Width >> 5;

	di_di_pq_cmp_pair_reg.cmp_data_bit_width = 1;
	di_di_pq_cmp_pair_reg.cmp_data_color = 1;
	if (PQC_Data_Format == DI_RTNR_420)
		di_di_pq_cmp_pair_reg.cmp_data_format = 2;
	else if (PQC_Data_Format == DI_RTNR_400)
		di_di_pq_cmp_pair_reg.cmp_data_format = 3;
	else
		di_di_pq_cmp_pair_reg.cmp_data_format = 1;

	di_di_pq_cmp_bit_reg.frame_limit_bit = PQC_Bit_Limit;	/* compress to 10 bit */

	di_di_pq_decmp_reg.decmp_en = 1;
	di_di_pq_decmp_reg.decmp_height = DI_Height;
	di_di_pq_decmp_reg.decmp_width_div32 = DI_Width >> 5;

	di_di_pq_decmp_pair_reg.decmp_data_bit_width = 1;
	di_di_pq_decmp_pair_reg.decmp_data_color = 1;
	if (PQC_Data_Format == DI_RTNR_420)
		di_di_pq_decmp_pair_reg.decmp_data_format = 2;
	else if (PQC_Data_Format == DI_RTNR_400)
		di_di_pq_decmp_pair_reg.decmp_data_format = 3;
	else
		di_di_pq_decmp_pair_reg.decmp_data_format = 1;

	di_di_pq_decmp_sat_en_reg.saturation_en = 1;
	di_di_pq_decmp_sat_en_reg.saturation_type = 1;

	/* some special case setting*/
	if (di_di_pq_cmp_pair_reg.cmp_data_format == 2) {	/* cmp_data_format = 420*/
		di_im_di_dma_reg.regValue = IoReg_Read32(DI_IM_DI_DMA_reg);
		di_im_di_dma_reg.dma_420_en = 1;/* 420 */
		IoReg_Write32(DI_IM_DI_DMA_reg, di_im_di_dma_reg.regValue);

		/*IoReg_ClearBits(DI_IM_DI_DMA_reg, _BIT31);
		IoReg_SetBits(DI_IM_DI_DMA_reg, _BIT30);*/
	}

	IoReg_Write32(DI_DI_PQ_CMP_reg, di_di_pq_cmp_reg.regValue);
	IoReg_Write32(DI_DI_PQ_DECMP_reg, di_di_pq_decmp_reg.regValue);
	IoReg_Write32(DI_DI_PQ_CMP_PAIR_reg, di_di_pq_cmp_pair_reg.regValue);
	IoReg_Write32(DI_DI_PQ_DECMP_PAIR_reg, di_di_pq_decmp_pair_reg.regValue);
	IoReg_Write32(DI_DDR_DATDMA_RM_reg, di_ddr_datdma_rm_reg.regValue);
	IoReg_Write32(DI_DI_PQ_DECMP_SAT_EN_reg, di_di_pq_decmp_sat_en_reg.regValue);
	IoReg_Write32(DI_DI_PQ_CMP_BIT_reg, di_di_pq_cmp_bit_reg.regValue);

	/* double buffer?*/
	di_db_reg_ctl_reg.db_apply = 1;
	IoReg_Write32(DI_db_reg_ctl_reg, di_db_reg_ctl_reg.regValue);

	drv_memory_di_Set_Compression_Bit_Num(di_di_pq_cmp_bit_reg.frame_limit_bit);

	/*system_info->I_Height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
	system_info->I_Width = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);*/

	return 0;
}

unsigned int drv_memory_Get_di_data_size_Static(unsigned char src_idx, unsigned char isCompression, unsigned char access, unsigned int DI_Width, unsigned int DI_Height, unsigned char DI_MEM_IDX)
{
	unsigned int buffer_size;
	unsigned int  add_more = 0x10;
#if 1
	/*1080p and 4k is compression, other is non compression*/
	if (isCompression !=0 && access == SLR_DI_progress_mode) {	/* compression mode, */
		if (DI_Height <= 1200) {	/* 1080p case*/
			buffer_size = 0x279580 + add_more; /*data = 4.947998047 MB in 1080p,  2.4739990235 MB per buffer, 2 buffer allocation*/
		} else {
			buffer_size = 0x4F2280 + add_more; /*data  = 9.891845703 MB in 4K(HSD to 2K 2K), 4.9459228515 MB per buffer, 2 buffer allocation*/
		}
	} else if (access == SLR_DI_progress_mode) { /* p mode, non-compression */
		if (DI_Height <= 1200) {	/* memory only support to 720p, 1080p use PQC*/
			buffer_size = 0x278D00 + add_more; /*data  = 4.943847656/2 MB in 720p, 2 buffer allocation*/
		} else {
			buffer_size = 0x9E3400  + add_more; /*data  =  9.887695313 MB in 4K(HSD to 2K 2K), only 1 buffer allocation*/
		}
	} else if (access == SLR_DI_5A_mode) {	/* i mode, 5A */
		buffer_size = 0x170000 + add_more;  /*data  = 5.75 MB in 1080i, 1.4375 MB per frame, 4 frame allocation */
	} else {	/* i mode, 3A */
		buffer_size = 0x278D00 + add_more;	/* data  = 4.943847656 MB in 1080i, 2.471923828 MB per frame, */
	}

	if (DI_MEM_IDX == 1 && get_platform() == PLATFORM_KXLP) {	/*k3lp, sub for apvr, 576i is max*/
		buffer_size = 0xA8C00 + add_more;	/*data  = 2.63671875 MB in 576i 0.6591796875 MB per frame, 4 frame allocation, 27M */
	}

#else
	if (isCompression !=0 && access == SLR_DI_progress_mode) {	/* p mode*//* compression, 10bit */
		buffer_size = (DI_Width * DI_Height * 10 + DI_Width * 8 + 2048) >> 3;
	} else {
		buffer_size = (DI_Width * DI_Height * 20) >> 3;	/* Y10C10,422*/
	}
	buffer_size = buffer_size + add_more;
	/*printk(KERN_EMERG"\n DI mem, data_size=%d", buffer_size);*/
#endif
	return buffer_size;
}

unsigned int drv_memory_Get_di_alloc_buffer_Static(unsigned char src_idx, unsigned char isCompression, unsigned char access, unsigned int DI_Width, unsigned int DI_Height, unsigned char DI_MEM_IDX)
{
	unsigned int buffer_size;
	unsigned int  add_more = 0x100;
#if 0
	/* no RTNR_INFO memory, p mode same as compression*/
	if (access == SLR_DI_progress_mode) { /* p mode, non-compression */
		if (DI_Height <= 1200) {	/* 1080p case*/
			buffer_size = 0x4F2B00 + add_more; /* only data = 4.947998047 MB in 1080p + n bytes */
		} else {
			buffer_size = 0x13C8800 + add_more; /* only data = 19.78320313 MB in 4K  + n bytes */
		}
	} else {	/* i mode */
		buffer_size = 0x1400000; /*data+info = 8.404541016 MB in 1080i, de-xc only need 16.43 MB, get more size(20MB) for all 5A allocation*/
	}
#else

	if (get_platform() == PLATFORM_KXLP) {		/* KxLp*/
		/* K3lp total = 17Mb(total) for 13.5(DI in 1080i main) + 3.5(DI in 576i sub APVR)*/
		if (DI_MEM_IDX == 1) /* sub for APVR*/
			buffer_size = 0x380000;	/* 3.5Mb*/
		else
			buffer_size = 0xD00000;	/* 13Mb*/
	} else {		/* KxL*/
		/* k3lp total 82Mb(total) for 40.5(DI+MA_SNR+DeXc in 1080p main) + 40.5(DI+MA_SNR+DeXc in 1080p sub) + 1(Demura) */
		buffer_size = 0x2880000;	/*40.5Mb*/
	}

	#if 0
	if (DI_MEM_IDX == 1 && get_platform() == PLATFORM_KXLP)
		buffer_size = 0x2EAB80;	/*k3lp, sub for apvr, only 2.916870117 MB for DI+MA_SNR*/
	else
		buffer_size = 	0x27CD580;	/* 39.80212402 MB for DI/RTNR+MA_SNR+DeXC*/
	#endif
#endif

#if 0 /* for test*/
	buffer_size = 0x1400000;
#endif

	return buffer_size;
}


unsigned int drv_memory_Get_di_info_size_Static(unsigned char src_idx, unsigned char isCompression, unsigned char access, unsigned int DI_Width, unsigned int DI_Height, unsigned char DI_MEM_IDX)
{
	unsigned int buffer_size;
	unsigned int  add_more = 0x10;
#if 1
	/* no RTNR_INFO memory, p mode same as compression*/
	if (access == SLR_DI_progress_mode) { /* p mode */
		//if (DI_Height <= 1200) {	/* 1080p case*/
			buffer_size = 0 + add_more; /* info  = 0 MB in 1080p, only 1 buffer allocation*/
		//} else {
		//	buffer_size = 0 + add_more; /*info  = 0 MB in 4K, only 1 buffer allocation*/
		//}
	} else {	/* i mode */
		if (access == SLR_DI_5A_mode)
			buffer_size = 0x100000 + add_more; /* info  = 2 MB in 5A, 1 MB per frame,  2 frame allocation (no RTNR_INFO)*/
		else
			buffer_size = 0x17BB00 + add_more; /* info  = 2.966308594 MB in 1080i, 1.483154297 MB per frame,  2 frame allocation (no RTNR_INFO)*/
	}

	if (DI_MEM_IDX == 1 && get_platform() == PLATFORM_KXLP) {	/*k3lp, sub for apvr, 576i is max*/
		buffer_size = 0x65400 + add_more;	/*data  = 0.791015625 MB in 576i, 0.3955078125 MB per frame, 2 frame allocation, 27M (no RTNR_INFO) */
	}

#else
	/* no RTNR_INFO memory, p mode same as compression*/
	if (access == SLR_DI_progress_mode) { /* p mode */
		buffer_size = 0 + add_more;
	} else {	/* i mode */
		buffer_size = (DI_Width * DI_Height * 14) >> 3; /* BTR on + SMD2, 14 bit/pixel, 2 frame*/
		buffer_size = buffer_size + add_more;
	}
	/*printk(KERN_EMERG"\n DI mem, info_size=%d", buffer_size);*/
#endif
	return buffer_size;
}

unsigned int drv_memory_set_ip_fifo_Mer2(unsigned char access)
{
	typedef struct _MEMSET {
		unsigned int number;
		unsigned int length;
		unsigned int remain;
		unsigned int water_level;
	} MEMSET;
	//di_im_di_btr_control_RBUS BTR_Control_Reg;
	di_ddr_rdatdma_wtlennum_RBUS ddr_rdatdma_wtlennum;
	di_ddr_rinfdma_wtlennum_RBUS ddr_rinfdma_wtlennum;
	di_ddr_wdatdma_wtlennum_RBUS ddr_wdatdma_wtlennum;
	di_ddr_winfdma_wtlennum_RBUS ddr_winfdma_wtlennum;
	di_ddr_datdma_rm_RBUS ddr_datdma_rm;
	di_ddr_infdma_rm_RBUS ddr_infdma_rm;
	//di_di_dma_multi_req_num_RBUS di_dma_multi_req_num_reg;
	//ddr_vrfifo1wtlvllennum_RBUS ddr_vrfifowtlvllennum;
	//ddr_vwfifo1wtlvllennum_RBUS ddr_vwfifowtlvllennum;
	//ddr_vfifo1rdwrremainder_RBUS ddr_vfifordwrremainder;

	unsigned int	DI_Width = 0, DI_Height = 0, size_per_frame = 0;
	unsigned char	data_bitNum = 0, info_bitNum = 0, i = 0, DIAllocateBlock;
	unsigned int	data_value, info_value=0, MemStartAddr;
	MEMSET			data_r, data_w, info_r, info_w;

	UINT32 lineSize_odd_128, lineSize_even_128;
	unsigned char DI_SMD_enable = 0;

	unsigned char source=255;
	unsigned char newRTNR_onoff = 0;
	unsigned char m_rtnrcompress = 0;
	unsigned char DI_BTR_enable = 0;
	unsigned char DI_BTR_type = 0;
	unsigned int buffer_alloc = 0;
	unsigned int data_size = 0;
	unsigned int info_size = 0;
	unsigned char isCompression_Mode = 0;
	unsigned char  data_num, info_num;

//fixme:vip
#if 1
	extern Scaler_DI_Coef_t Scaler_DI_Coef_table[VIP_QUALITY_SOURCE_NUM];
	source = fwif_vip_source_check(3, 0);
	if(source >= VIP_QUALITY_SOURCE_NUM)
	{
		pr_err("\r\n#####drv_memory_set_ip_fifo source nunber %d error####\r\n", source);
		source = VIP_QUALITY_SOURCE_NUM-1;
	}
	//frank@1018 add below code to solve scan tool warning
	newRTNR_onoff = (unsigned char)Scaler_DI_Coef_table[source].newRTNR_style;
	//DI_SMD_enable = Scaler_getDI_SMD_en(source);
	DI_SMD_enable = Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE);
	DI_BTR_enable = drv_memory_get_ip_Btr_mode();

	//BTR_Control_Reg.regValue = rtd_inl(DI_IM_DI_BTR_CONTROL_VADDR);
	//DI_BTR_type = BTR_Control_Reg.btr_solutiontype;
	DI_BTR_type = (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID) < 960)?0:1;
#endif

	DI_Width = Scaler_DispGetInputInfo(SLR_INPUT_DI_WID);
	DI_Height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);

	pr_debug("\n DI Memory set FIFO !");
	pr_debug("\n Width:%d, Height:%d, DMA mode=%d", DI_Width, DI_Height, drv_memory_get_ip_DMA420_mode());
	pr_debug("\n Data status Y=%d C=%d", fw_scalerip_get_DI_chroma_10bits()?10:8, fw_scalerip_get_DI_chroma_10bits()?10:8);
	pr_debug("\n Info status BTR=%d(type:%d) SMD=%d RTNR style=%d", DI_BTR_enable, DI_BTR_type, DI_SMD_enable, newRTNR_onoff);

	rtd_printk(KERN_INFO, TAG_NAME, "\n DI Memory set FIFO !");
	rtd_printk(KERN_INFO, TAG_NAME, "\n Width:%d, Height:%d, DMA mode=%d", DI_Width, DI_Height, drv_memory_get_ip_DMA420_mode());
	rtd_printk(KERN_INFO, TAG_NAME, "\n Data status Y=%d C=%d", fw_scalerip_get_DI_chroma_10bits()?10:8, fw_scalerip_get_DI_chroma_10bits()?10:8);
	rtd_printk(KERN_INFO, TAG_NAME, "\n Info status BTR=%d(type:%d) SMD=%d RTNR style=%d", DI_BTR_enable, DI_BTR_type, DI_SMD_enable, newRTNR_onoff);

	data_bitNum = 16; // for YUV subsample 422 ( now only using 2 typr : 422 & 420	)
	info_bitNum = 0;

	/* new DI/RTNR compression for Mer2*/
	drv_memory_di_Compression_Config(source, access, DI_Width, DI_Height);
	isCompression_Mode = drv_memory_di_Get_Compression_Bit_Num();

	// assign data bits
	if (isCompression_Mode == 0) {
		if (fw_scalerip_get_DI_chroma_10bits())
			data_bitNum += 2;
		if (fw_scalerip_get_DI_chroma_10bits())
			data_bitNum += 2;
	} else {
		data_bitNum = isCompression_Mode;
	}
#ifdef ENABLE_DI_COMPRESS
	if (caler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN) > 1200) {	// 2k2k
		drv_memory_set_ip_compress_bit(12);
		m_rtnrcompress = 1;
		data_bitNum = 12;
	}
#endif

	/*
		LearnRPG comment DI DMA how to use?
		from magellan/sirius/mac3
		FIFO length is 64bits, SD need 2(128bits), HD need 4(SD double), progressive need 6
		about READ(from DDR to FIFO) the best performance is using water_level+length = FIFO length
		about WRITE(from FIFO to DDR) must just MATCH, otherwise will have dummy data in FIFO
	*/
	// assign info bits
	if (access == SLR_DI_5A_mode) {
		pr_debug("\n 5A mode \n");
		rtd_printk(KERN_INFO, TAG_NAME, "\n 5A mode \n");

		info_bitNum += (DI_BTR_enable?(DI_BTR_type?4:8):0); // type A:8 bits, type B:4 bits

		DIAllocateBlock = 4;

		data_r.water_level = 68;
		data_r.length = 60;

		data_w.water_level = 60;
		data_w.length = 60;

		info_r.water_level = 32;
		info_r.length = 32;

		info_w.water_level = 32;
		info_w.length = 32;

		data_num = 4;
		info_num = 2;		/* BTR = on*/

	} else if (access == SLR_DI_3A_mode) {
		pr_debug("\n 3A mode \n");
		printk(KERN_INFO"\n 3A mode \n");

		info_bitNum += (DI_BTR_enable?4:0); // type A:8 bits, type B:4 bits, 3A only type B
		info_bitNum += 4; // frame motion in 3A default need 4 bits

		DIAllocateBlock = 2;

		data_r.water_level = 196;
		data_r.length = 60;

		data_w.water_level = 60;
		data_w.length = 60;

		info_r.water_level = 32;
		info_r.length = 32;

		info_w.water_level = 32;
		info_w.length = 32;

		data_num = 2;
		info_num = 2;		/* BTR = on*/

	} else if (access == SLR_DI_progress_mode) {
		pr_debug("\n progress mode \n");

		rtd_printk(KERN_INFO, TAG_NAME, "\n progress mode \n");
		DIAllocateBlock = 2;

		//Waterlevel = 0x180 - length at PRTNR 2A case, but this value over 8bit(0xff), so give 0xff
		data_r.water_level = 0xff;
		data_r.length = 60;

		if (fwif_vip_increase_DI_water_lv())		//20150813 roger, change dat_len_r for 4k2k60p
			data_r.length = 96;

		data_w.water_level = 60;
		data_w.length = 60;

		info_r.water_level = 32;
		info_r.length = 32;

		info_w.water_level = 32;
		info_w.length = 32;

		if(isCompression_Mode == 0) {
			data_num = 2;
			info_num = 1;
			DIAllocateBlock = 2;
		} else {
			data_num = 2;
			info_num = 1;
			DIAllocateBlock = 2;
		}

	} else {
		pr_debug("\n Error accept parameter in memory fifo \n");
		return false;
	}

	if (DI_SMD_enable)
		info_bitNum += 4; //4; //fix me : mac5p only 4 bits

	// if k temporal function is enabled, new rtnr need 2 bits, otherwise still 0, please refer scalerColor.cpp:fwif_color_set_RTNR_style_adjust()
	/*Hawaiili 20170117 : Mac5p No newRTNR*/
	//if (newRTNR_onoff == 3 || newRTNR_onoff == 4)
	//		info_bitNum += 2;


	pr_debug("\n Data BitNum=%d, Info BitNum=%d", data_bitNum, info_bitNum);
	rtd_printk(KERN_INFO, TAG_NAME, "\n Data BitNum=%d, Info BitNum=%d", data_bitNum, info_bitNum);

	// Calculate Data number/length/remain
	if (drv_memory_get_ip_DMA420_mode() == SLR_DMA_422_mode) { // 422 mode
		size_per_frame = DI_Width * DI_Height * data_bitNum;
		data_r.number = (int)(size_per_frame/128/data_r.length);
		data_r.remain = (size_per_frame - data_r.number*128*data_r.length + 127)/128;
		if (data_r.remain == 0 && data_r.number != 0) {
			data_r.number -= 1;
			data_r.remain = data_r.length;
		}

		data_w.number = (int)(size_per_frame/128/data_w.length);
		data_w.remain = (size_per_frame - data_w.number*128*data_w.length + 127)/128;
		if (data_w.remain == 0 && data_w.number != 0) {
			data_w.number -= 1;
			data_w.remain = data_w.length;
		}

		IoReg_ClearBits(DI_IM_DI_DMA_reg, _BIT31);
		IoReg_ClearBits(DI_IM_DI_DMA_reg, _BIT30);
	}
	else if (drv_memory_get_ip_DMA420_mode() == SLR_DMA_420_mode) { // 420 mode
		lineSize_even_128	= DI_Width * (data_bitNum - (fw_scalerip_get_DI_chroma_10bits()?10:8)); // only Y componet
		lineSize_odd_128	= DI_Width * data_bitNum; // Y and C componet

		// linesize unit 64
		if (lineSize_even_128%64 == 0)
			lineSize_even_128 /= 64;
		else
			lineSize_even_128 = (lineSize_even_128+64)/64;
		if (lineSize_odd_128%64 == 0)
			lineSize_odd_128 /= 64;
		else
			lineSize_odd_128 = (lineSize_odd_128+64)/64;

		// frame unit 128, so linesize must divide by 2
		//if (DI_Height%2 == 0)
		//	size_per_frame = ((lineSize_even_128 + lineSize_odd_128+1)/2)*(DI_Height/2);
		//else
			size_per_frame = ((lineSize_even_128+1)/2)*(DI_Height/2) + ((lineSize_odd_128+1)/2)*((DI_Height+1)/2);

		data_r.number = (int)(size_per_frame/data_r.length);
		data_r.remain = size_per_frame%data_r.length;
		if (data_r.remain == 0 && data_r.number != 0) {
			data_r.number -= 1;
			data_r.remain = data_r.length;
		}

		data_w.number = (int)(size_per_frame/data_w.length);
		data_w.remain = size_per_frame%data_w.length;
		if (data_w.remain == 0 && data_w.number != 0) {
			data_w.number -= 1;
			data_w.remain = data_w.length;
		}

		IoReg_Mask32(DI_IM_DI_DMA_reg,
			~(DI_DMA_420_EN_MASK| DI_DMA_LINESIZE_EVEN_MASK| DI_DMA_LINESIZE_ODD_MASK),
			_BIT30 | (lineSize_even_128 << DI_DMA_LINESIZE_EVEN_START_BIT) | lineSize_odd_128);

		pr_debug("\n 420 mode: linesize_even=%d, linesize_odd=%d", lineSize_even_128, lineSize_odd_128);
	}
	else { // 400 mode
		//size_per_frame = DI_Width * DI_Height * data_bitNum;
		size_per_frame = DI_Width * DI_Height * (data_bitNum - (fw_scalerip_get_DI_chroma_10bits()?10:8));
		data_r.number = (int)(size_per_frame/128/data_r.length);
		data_r.remain = (size_per_frame - data_r.number*128*data_r.length + 127)/128;
		if (data_r.remain == 0 && data_r.number != 0) {
			data_r.number -= 1;
			data_r.remain = data_r.length;
		}

		data_w.number = (int)(size_per_frame/128/data_w.length);
		data_w.remain = (size_per_frame - data_w.number*128*data_w.length + 127)/128;
		if (data_w.remain == 0 && data_w.number != 0) {
			data_w.number -= 1;
			data_w.remain = data_w.length;
		}
		IoReg_SetBits(DI_IM_DI_DMA_reg, _BIT31);
		IoReg_ClearBits(DI_IM_DI_DMA_reg, _BIT30);
	}
	//IoReg_SetBits(DI_db_reg_ctl_reg, _BIT0);

	// Calculate Info number/length/remain
	size_per_frame = DI_Width * DI_Height * info_bitNum;
	if (DI_SMD_enable && access == SLR_DI_5A_mode) // Info image height must +1 for DMA setting when SMD enable in 5A case
		size_per_frame += DI_Width * info_bitNum;



	info_r.number = (int)(size_per_frame/128/info_r.length);
	info_r.remain = (size_per_frame - info_r.number*128*info_r.length + 127)/128;
	if (info_r.remain == 0 && info_r.number != 0) {
		info_r.number -= 1;
		info_r.remain = info_r.length;
	}

	info_w.number = (int)(size_per_frame/128/info_w.length);
	info_w.remain = (size_per_frame - info_w.number*128*info_w.length + 127)/128;
	if (info_w.remain == 0 && info_w.number != 0) {
		info_w.number -= 1;
		info_w.remain = info_w.length;
	}

	pr_debug("\n Data number = %d, length = %d, remain = %d, water_level = %d in setting DI Read FIFO", data_r.number, data_r.length, data_r.remain, data_r.water_level);
	pr_debug("\n Data number = %d, length = %d, remain = %d, water_level = %d in setting DI Write FIFO", data_w.number, data_w.length, data_w.remain, data_w.water_level);
	pr_debug("\n Info number = %d, length = %d, remain = %d, water_level = %d in setting DI Read FIFO", info_r.number, info_r.length, info_r.remain, info_r.water_level);
	pr_debug("\n Info number = %d, length = %d, remain = %d, water_level = %d in setting DI Write FIFO", info_w.number, info_w.length, info_w.remain, info_w.water_level);

	ddr_rdatdma_wtlennum.dat_water_r	= data_r.water_level;
	ddr_rdatdma_wtlennum.dat_len_r		= data_r.length;
	ddr_rdatdma_wtlennum.dat_num_r		= data_r.number;

	ddr_wdatdma_wtlennum.dat_water_w	= data_w.water_level;
	ddr_wdatdma_wtlennum.dat_len_w		= data_w.length;
	ddr_wdatdma_wtlennum.dat_num_w		= data_w.number;

	ddr_datdma_rm.dat_remain_r			= data_r.remain;
	ddr_datdma_rm.dat_remain_w			= data_w.remain;
	if (isCompression_Mode == 0)
		ddr_datdma_rm.rdma_remain_en		= 1;
	else
		ddr_datdma_rm.rdma_remain_en		= 0;

	ddr_rinfdma_wtlennum.inf_water_r	= info_r.water_level;
	ddr_rinfdma_wtlennum.inf_len_r		= info_r.length;
	ddr_rinfdma_wtlennum.inf_num_r		= info_r.number;

	ddr_winfdma_wtlennum.inf_water_w	= info_w.water_level;
	ddr_winfdma_wtlennum.inf_len_w		= info_w.length;
	ddr_winfdma_wtlennum.inf_num_w		= info_w.number;;

	ddr_infdma_rm.inf_remain_r			= info_r.remain;
	ddr_infdma_rm.inf_remain_w			= info_w.remain;

	//remain and number both 0 will cause DMA error when 1080p switch to 576i DI will fliker eric_huang@realsil.com.cn
	if (info_r.number == 0 && info_r.remain == 0) {
		ddr_rinfdma_wtlennum.inf_num_r = 0x174;
		ddr_infdma_rm.inf_remain_r = 0x0b;
	}

	//remain and number both 0 will cause DMA error when 1080p switch to 576i DI will fliker eric_huang@realsil.com.cn
	if (info_w.number == 0 && info_w.remain == 0) {
		ddr_winfdma_wtlennum.inf_num_w = 0x174;
		ddr_infdma_rm.inf_remain_w = 0x0b;
	}

	IoReg_Write32(DI_DDR_RDATDMA_WTLENNUM_reg, ddr_rdatdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_WDATDMA_WTLENNUM_reg, ddr_wdatdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_RINFDMA_WTLENNUM_reg, ddr_rinfdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_WINFDMA_WTLENNUM_reg, ddr_winfdma_wtlennum.regValue);
	IoReg_Write32(DI_DDR_DATDMA_RM_reg, ddr_datdma_rm.regValue);
	IoReg_Write32(DI_DDR_INFDMA_RM_reg, ddr_infdma_rm.regValue);

	IoReg_SetBits(DI_db_reg_ctl_reg, _BIT0);	/* HW do not clear this bit, alway turn on, setting will be apply while v_sync*/
	//frank@0514 change DI multi request to solve DI read underflow ++
	drv_memory_disable_di_write_req(FALSE);
	//frank@0514 change DI multi request to solve DI read underflow --

//frank@1202 Change code to solve 1366x768 image fail problem

#if 1/*qiangzhou: added DI memory allocate with VGIP PRE info for max size start*/
#if(CONFIG_DDR_DATA_BITS == 16)
	/*if ((Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_PIPMLSR_4x3) &&
		(Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1C12B) && (Scaler_PipGetInfo(SLR_PIP_TYPE) != SUBTYPE_MP1L7B)) {*/
		data_value = data_bitNum;
		info_value = info_bitNum;
		if(Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) > _DISP_WID){
			data_value *= _DISP_WID;
			info_value *= _DISP_WID;
		}else{
			data_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
			info_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE);
		}


		if(((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
			&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
			&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status()) {
			data_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
			info_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
		} else {
			data_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
			info_value *= Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE);
		}

		data_value = (data_value >> 3);//byte unit
		info_value = (info_value >> 3);//byte unit
//		value =(info->IPV_ACT_LEN_PRE *info->IPH_ACT_WID_PRE * bitNum)>>4;
	/*} else {
		data_value=(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*data_bitNum)>>3;	//byte unit
		info_value=(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN)*Scaler_DispGetInputInfo(SLR_INPUT_DI_WID)*info_bitNum)>>3;	//byte unit
	}*/
#else
	data_value=(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)*Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*data_bitNum)>>3;	//byte unit
	info_value=(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)*Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE)*info_bitNum)>>3;	//byte unit
#endif

	if (drv_memory_get_ip_DMA420_mode()) {
		//sync code from Mac2. Start
		di_im_di_dma_RBUS im_di_dma;
		unsigned int di420_width;
		im_di_dma.regValue = IoReg_Read32(DI_IM_DI_DMA_reg);
		lineSize_even_128 = (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) * (data_bitNum - 8));
		if((lineSize_even_128%128)==0)
			lineSize_even_128 /=128;
		else
			lineSize_even_128 = (lineSize_even_128+128)/128;

		lineSize_odd_128 = (Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID_PRE) * data_bitNum);
		if((lineSize_odd_128%128)==0)
			lineSize_odd_128 /=128;
		else
			lineSize_odd_128 = (lineSize_odd_128+128)/128;

		if (Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)%2 == 0) {
			di420_width = (lineSize_odd_128 + lineSize_even_128)*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)/2);
		} else {
			di420_width = lineSize_even_128*(Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)/2)+lineSize_odd_128*((Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN_PRE)+1)/2);
		}
		data_value = di420_width<<4;
		//sync code from Mac2. End
	}
#endif/*qiangzhou: added DI memory allocate with VGIP PRE info for max size end*/

	drvif_memory_free_block(MEMIDX_DI);

	// Set 32 avoid to cover other block memroy ([[h * v * bitnum] / (64* 2) ]* 16
	data_value = drvif_memory_get_data_align(data_value, 32);
	info_value = drvif_memory_get_data_align(info_value, 32);
	//frank@0707 when 3D mode DI must allocate 2 X memory

#if 1//defined(ENABLE_DRIVER_I3DDMA)|| defined(ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE)
	//3D mode DI memory allocate x2: 3D frame sequence input video
	if(drvif_scaler3d_get_IDMA3dMode()
		|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
			&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
			&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())) {
		data_value *= 2;
		info_value *= 2;
	}
#endif

#if 1
#ifdef CONFIG_I2RND_ENABLE
	//add I2rnd condition @Crixus 20160716
	if(!((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC))){
		//printk(KERN_EMERG"[%s][crixus]DI non-i2rnd memory allocation\n", __FUNCTION__);
#endif
		//define at makeconfig
		//patch for DI/RTNR bug(overwrite 512Byte)

		buffer_alloc = drv_memory_Get_di_alloc_buffer_Static(source, isCompression_Mode, access, DI_Width, DI_Height, 0);
		data_size = drv_memory_Get_di_data_size_Static(source, isCompression_Mode, access, DI_Width, DI_Height, 0);
		info_size = drv_memory_Get_di_info_size_Static(source, isCompression_Mode, access, DI_Width, DI_Height, 0);

		if(drvif_scaler3d_get_IDMA3dMode()
			|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
				&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
				&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())){

			if(access != 2){
				MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value * DIAllocateBlock+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
			}
			else{
#ifdef ENABLE_DI_COMPRESS
				if(m_rtnrcompress){//compress mode use 2 buffer
					MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value*2+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
				}
				else
#endif
				{
					MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
				}
			}
		} else {
			MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, buffer_alloc, MEMALIGN_ANY);
		}
		if(MemStartAddr == _DUMMYADDR){
			rtd_printk(KERN_EMERG , TAG_NAME, "set MEMIDX_DI  to size fail !!!\n");
		}
		rtd_printk(KERN_EMERG, TAG_NAME, "DI, mem_sta=%x,platform=%d\n", MemStartAddr, get_platform());

#ifdef CONFIG_I2RND_ENABLE
		//printk(KERN_EMERG"[%s][crixus]DI non-i2rnd MemStartAddr = %x\n", __FUNCTION__, MemStartAddr);

	}
	else{//I2rnd case - allocate DI 2 memory
		//printk(KERN_EMERG"[%s][crixus]DI i2rnd second memory allocation\n", __FUNCTION__);

		buffer_alloc = drv_memory_Get_di_alloc_buffer_Static(source, isCompression_Mode, access, DI_Width, DI_Height, 1);
		data_size = drv_memory_Get_di_data_size_Static(source, isCompression_Mode, access, DI_Width, DI_Height, 1);
		info_size = drv_memory_Get_di_info_size_Static(source, isCompression_Mode, access, DI_Width, DI_Height, 1);

		if(drvif_scaler3d_get_IDMA3dMode()
			|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
			&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
			&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())){
			if(access != 2){
				MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI_2, data_value * DIAllocateBlock+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
			}
			else{
#ifdef ENABLE_DI_COMPRESS
				if(m_rtnrcompress){//compress mode use 2 buffer
					MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI_2, data_value*2+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
				}
				else
#endif
				{
					MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI_2, data_value+info_value*2+CONFIG_MDOMAIN_BURST_SIZE, MEMALIGN_ANY);
				}
			}
		} else {
			MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI_2, buffer_alloc, MEMALIGN_ANY);
		}
		if(MemStartAddr == _DUMMYADDR){
			rtd_printk(KERN_EMERG , TAG_NAME, "set MEMIDX_DI_2  to size fail !!!\n");
		}


		//printk(KERN_EMERG"[%s][crixus]DI i2rnd MemStartAddr = %x\n", __FUNCTION__, MemStartAddr);
		rtd_printk(KERN_EMERG, TAG_NAME, "DI 2 DI 2, mem_sta=%x,platform=%d\n", MemStartAddr, get_platform());


	}
#endif
#else
	if(access != 2)
		MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value * DIAllocateBlock+info_value*2, MEMALIGN_ANY);
	else{
		if(m_rtnrcompress)//compress mode use 2 buffer
			MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value*2+info_value*2, MEMALIGN_ANY);
		else
			MemStartAddr = drvif_memory_alloc_block(MEMIDX_DI, data_value+info_value*2, MEMALIGN_ANY);
	}
#endif
	//ScalerMemory_Printf("Get ip addr = %x, size=%x\n", MemStartAddr, (data_value * DIAllocateBlock+info_value*2));
#if 0 /* for test*/
	MemStartAddr = drv_memory_I_De_XC_DMA_Config(MemStartAddr, 0, source);
	rtd_printk(KERN_EMERG, TAG_NAME, "De_xc_test,width=%d,heigth=%d,info_size=%d,data_size=%d,mem_end=%x\n", DI_Width, DI_Height, info_size, data_size,MemStartAddr);
	return;
#endif
#if 1//defined(ENABLE_DRIVER_I3DDMA)|| defined(ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE)
	//3D mode DI memory allocate x2: 3D frame sequence input video
	if(drvif_scaler3d_get_IDMA3dMode()
		|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
			&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
			&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())) {
		data_value /= 2;
		info_value /= 2;
	}
#endif

#ifdef CONFIG_I2RND_ENABLE
	//add I2rnd condition @Crixus 20160716
	if(!((Scaler_I2rnd_get_enable() == _ENABLE) && (vsc_i2rnd_sub_stage == I2RND_STAGE_MAIN_GET_RPC))){

		//printk(KERN_EMERG"[%s][crixus]DI non-i2rnd set start address\n", __FUNCTION__);
#endif
		if(drvif_scaler3d_get_IDMA3dMode()
				|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
					&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
					&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status()))
		{
			// Set start address for deinterlace
			for(i = 0; i < data_num; i++) {
				pr_debug(" IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_DATMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				/*if((access != SLR_DI_progress_mode)|| m_rtnrcompress)*/
					MemStartAddr += data_value;//data_value;
			}

			/*if((access == SLR_DI_progress_mode)&&!m_rtnrcompress){
				MemStartAddr += data_value;
			}*/

			for(i = 0; i < info_num; i++) {
				pr_debug(" Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_INFMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				/*if(access != SLR_DI_progress_mode)*/
					MemStartAddr += info_value;
			}
		}else {
			for(i = 0; i < data_num; i++) {
				pr_debug(" IP address%x = %x\n", i, MemStartAddr);
				IoReg_Write32((DI_DI_DATMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );
				/*if((access != SLR_DI_progress_mode)|| m_rtnrcompress)*/
					MemStartAddr += data_size;//data_value;
			}
			/*if((access == SLR_DI_progress_mode)&&!m_rtnrcompress){
				MemStartAddr += data_size;
			}*/

			for(i = 0; i < info_num; i++) {
				pr_debug(" Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_INFMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				/*if(access != SLR_DI_progress_mode)*/
					MemStartAddr += info_size;
			}
		}

#if 1//defined(ENABLE_DRIVER_I3DDMA)|| defined(ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE)
		if(drvif_scaler3d_get_IDMA3dMode()
			|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
				&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
				&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())) {
			for(i = 0; i < data_num; i++) {
				pr_debug(" 3D IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_DATMemoryStartAdd1_3D_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				/*if((access != SLR_DI_progress_mode)|| m_rtnrcompress)*/
					MemStartAddr += data_value;
			}

			/*if((access == SLR_DI_progress_mode) && !m_rtnrcompress){
				MemStartAddr += data_value;
			}*/

			for(i = 0; i < info_num; i++) {
				pr_debug(" 3D Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_INFMemoryStartAdd1_3D_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				/*if(access != SLR_DI_progress_mode)*/
					MemStartAddr += info_value;
			}
		}
#endif
		rtd_printk(KERN_EMERG, TAG_NAME, "DI,width=%d,heigth=%d,info_size=%d,data_size=%d,mem_end=%x\n", DI_Width, DI_Height, info_size, data_size,MemStartAddr);
		/*Hawaiili 20170117 : Mac5p No MASNR*/
		//MemStartAddr = drv_memory_MA_SNR_Config(access, MemStartAddr, 0);

		//hugh 20171212: Mac5p turn off de-xc for all source
		//MemStartAddr = drv_memory_I_De_XC_DMA_Config(MemStartAddr, 0, source);
		rtd_printk(KERN_EMERG, TAG_NAME, "DI, DI+MA_SNR+DeXCXL end=%x, compression=%d\n", MemStartAddr, isCompression_Mode);

#ifdef CONFIG_I2RND_ENABLE
	}
	else{//I2rnd case - set DI memory start address

		//printk(KERN_EMERG"[%s][crixus]DI i2rnd set start address\n", __FUNCTION__);
		if(drvif_scaler3d_get_IDMA3dMode()
				|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
					&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
					&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status()))
		{
			// Set start address for deinterlace
			for(i = 0; i < data_num; i++) {
				pr_debug(" IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_I2R_DATMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				/*if((access != SLR_DI_progress_mode)|| m_rtnrcompress)*/
					MemStartAddr += data_value;//data_value;
			}

			/*if((access == SLR_DI_progress_mode)&&!m_rtnrcompress){
				MemStartAddr += data_value;
			}*/

			for(i = 0; i < info_num; i++) {
				pr_debug(" Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_I2R_INFMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				/*if(access != SLR_DI_progress_mode)*/
					MemStartAddr += info_value;
			}
		}else {
			for(i = 0; i < data_num; i++) {
				pr_debug(" IP address%x = %x\n", i, MemStartAddr);
				IoReg_Write32((DI_DI_I2R_DATMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );
				if((access != SLR_DI_progress_mode)|| m_rtnrcompress)
					MemStartAddr += data_size;//data_value;
			}
			/*if((access == SLR_DI_progress_mode)&&!m_rtnrcompress){
				MemStartAddr += data_size;
			}*/

			for(i = 0; i < info_num; i++) {
				pr_debug(" Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_I2R_INFMemoryStartAdd1_reg+ (i << 2)),  (MemStartAddr&0x7FFFFFFF) );

				/*if(access != SLR_DI_progress_mode)*/
					MemStartAddr += info_size;
			}
		}

#if 1//defined(ENABLE_DRIVER_I3DDMA)|| defined(ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE)
		if(drvif_scaler3d_get_IDMA3dMode()
			|| (((Get_PANEL_3D_DISPLAY_SUPPORT_ENABLE() && (Get_PANEL_3D_LINE_ALTERNATIVE_SUPPORT_ENABLE() == TRUE)
				&& (Scaler_Disp3dGetInfo((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_DISP_3D_3DTYPE)==SLR_3D_FRAME_PACKING)) || (drvif_scaler3d_decide_3d_SG_Disable_IDMA(SLR_3D_FRAME_PACKING) == TRUE))
				&& drvif_scaler3d_decide_HDMI_framePacking_interlaced_status())) {
			for(i = 0; i < data_num; i++) {
				pr_debug(" 3D IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_I2R_DATMemoryStartAdd1_3D_reg+ (i << 2)),	(MemStartAddr&0x7FFFFFFF) );

				/*if((access != SLR_DI_progress_mode)|| m_rtnrcompress)*/
					MemStartAddr += data_value;
			}

			/*if((access == SLR_DI_progress_mode) && !m_rtnrcompress){
				MemStartAddr += data_value;
			}*/

			for(i = 0; i < info_num; i++) {
				pr_debug(" 3D Info IP address%x = %x\n", i, MemStartAddr);

				IoReg_Write32((DI_DI_I2R_INFMemoryStartAdd1_3D_reg+ (i << 2)),	(MemStartAddr&0x7FFFFFFF) );

				/*if(access != SLR_DI_progress_mode)*/
					MemStartAddr += info_value;
			}
		}
#endif
		rtd_printk(KERN_EMERG, TAG_NAME, "DI 2 DI 2,width=%d,heigth=%d,info_size=%d,data_size=%d,mem_end=%x\n", DI_Width, DI_Height, info_size, data_size,MemStartAddr);
		/*Hawaiili 20170117 : Mac5p No MASNR*/
		//MemStartAddr = drv_memory_MA_SNR_Config(access, MemStartAddr, 1);
		MemStartAddr = drv_memory_I_De_XC_DMA_Config(MemStartAddr, 1, source);
		rtd_printk(KERN_EMERG, TAG_NAME, "DI 2 DI 2, DI+MA_SNR+DeXCXL end=%x,compression=%d\n", MemStartAddr, isCompression_Mode);
	}
#endif

	return MemStartAddr;
}

void drv_memory_set_De_Mura(unsigned int memory_Addr_sta)
{
	/*demura_demura_dma_start_addr_RBUS demura_demura_dma_start_addr_reg;*/
	//remove on mac5p
	//IoReg_Write32(DEMURA_DEMURA_DMA_START_ADDR_reg, memory_Addr_sta);
}

char  drv_memory_I_De_XC_ON_OFF_Wait(unsigned char En)
{
	de_xcxl_de_xcxl_db_reg_ctl_RBUS de_xcxl_de_xcxl_db_reg_ctl_reg;

	IoReg_ClearBits(DE_XCXL_De_XCXL_CTRL_reg, DE_XCXL_De_XCXL_CTRL_dexc_en_mask);	/* turn off de-xc */
	IoReg_SetBits(DE_XCXL_DE_XCXL_db_reg_ctl_reg, DE_XCXL_DE_XCXL_db_reg_ctl_db_apply_mask);

	de_xcxl_de_xcxl_db_reg_ctl_reg.regValue = IoReg_Read32(DE_XCXL_DE_XCXL_db_reg_ctl_reg);
	while (de_xcxl_de_xcxl_db_reg_ctl_reg.db_apply == 1) {
		de_xcxl_de_xcxl_db_reg_ctl_reg.regValue = IoReg_Read32(DE_XCXL_DE_XCXL_db_reg_ctl_reg);
	}

	return TRUE;
}

extern int VBM_ReturnMemChunk(unsigned long buffer_addr, unsigned long buffer_size);
extern int VBM_BorrowMemChunk(unsigned long *buffer_addr, unsigned long *buffer_size, UINT32 reqSize);
extern unsigned long I3DDMA_GetMemChunkAddr(unsigned int size);
extern struct semaphore VPQ_DeXC_MEM_Semaphore;/*For Dexc MEM*/

unsigned int  drv_memory_I_De_XC_DMA_Memory_Get_From_VBM(unsigned char DI_MEM_IDX, unsigned int DI_Width, unsigned int DI_Height, unsigned char Force_Clr)
{
#if 0
	typedef enum _VIP_I_De_XC_MEM_BORROW_MODE{
		De_XC_MEM_UNKNOW = 0,
		De_XC_MEM_From_VBM_Directly,
		De_XC_MEM_From_I3D_DMA,	/* memory will release by itself in i3ddma*/
		I_De_XC_MEM_BORROW_MODE_Max,

	} VIP_I_De_XC_MEM_BORROW_MODE;

	typedef struct _VIP_I_De_XC_MEM {
		unsigned long phyaddr;
		/*unsigned int size;*/
		unsigned int getsize;
		unsigned char Borrow_Mode;

	} VIP_I_De_XC_MEM;

	static VIP_I_De_XC_MEM mem_ctrl[2] = {0};
#endif

	//_system_setting_info* system_info_structure_table = NULL;
	//system_info_structure_table = (_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_system_info_structure);
	_RPC_system_setting_info* RPC_system_info_structure_table = NULL;
	RPC_system_info_structure_table = (_RPC_system_setting_info *)Scaler_GetShareMemVirAddr(SCALERIOC_VIP_RPC_system_info_structure);
	if (RPC_system_info_structure_table == NULL) {
		rtd_printk(KERN_EMERG, TAG_NAME, "De-XC mem, RPC system info structure NULL !!!\n");
		return NULL;
	}

	VIP_I_De_XC_MEM *mem_ctrl[2];
	//mem_ctrl[0] = &system_info_structure_table->PQ_Setting_Info.DE_XCXL_Memory_CTRL[0];
	//mem_ctrl[1] = &system_info_structure_table->PQ_Setting_Info.DE_XCXL_Memory_CTRL[1];
	mem_ctrl[0] = &RPC_system_info_structure_table->DE_XCXL_Memory_CTRL[0];
	mem_ctrl[1] = &RPC_system_info_structure_table->DE_XCXL_Memory_CTRL[1];

	down(&VPQ_DeXC_MEM_Semaphore);


	unsigned char add_more = 0x10;
	unsigned int de_xc_size = 0x16FD280 + add_more;	/*Mac5p 22.98889065Mb*//*Mer2 0x20E0680 : 32.87658691 Mb*/
	unsigned int phyaddr = NULL;
	unsigned int getSize = 0;
	rtd_printk(KERN_EMERG, TAG_NAME, "De-XC mem from VBM function,idx=%d,DI_w=%d,DI_h=%d,F_clr=%d\n",  DI_MEM_IDX, DI_Width, DI_Height, Force_Clr);

	if (Force_Clr == 1) {
		if ((mem_ctrl[DI_MEM_IDX]->phyaddr != 0) && (mem_ctrl[DI_MEM_IDX]->Borrow_Mode == De_XC_MEM_From_VBM_Directly)) {
			pr_debug("[%s] call VBM_ReturnMemChunk\n",__FUNCTION__);
			rtd_printk(KERN_EMERG, TAG_NAME, "De-XC mem force clear, return memroy from VBM = %x\n", mem_ctrl[DI_MEM_IDX]->phyaddr);
			VBM_ReturnMemChunk(mem_ctrl[DI_MEM_IDX]->phyaddr, mem_ctrl[DI_MEM_IDX]->getsize);
		}
		mem_ctrl[DI_MEM_IDX]->phyaddr = NULL;
		mem_ctrl[DI_MEM_IDX]->getsize = NULL;
		mem_ctrl[DI_MEM_IDX]->Borrow_Mode = De_XC_MEM_UNKNOW;
		rtd_printk(KERN_EMERG, TAG_NAME, "De-XC mem force clear, mem tag reset\n");
	} else {
		if (DbgSclrFlgTkr.Main_Scaler_Stop_flag == FALSE) {	/* connection check. */
			if (mem_ctrl[DI_MEM_IDX]->phyaddr == 0) {
				phyaddr = (unsigned int)I3DDMA_GetMemChunkAddr(de_xc_size);
				if ( phyaddr != NULL) {
					mem_ctrl[DI_MEM_IDX]->phyaddr =  phyaddr;//(unsigned int)dvr_to_phys((void*)i3ddmaCtrl.cap_buffer[0].cache);
					mem_ctrl[DI_MEM_IDX]->getsize = de_xc_size;
					mem_ctrl[DI_MEM_IDX]->Borrow_Mode = De_XC_MEM_From_I3D_DMA;
					/*drv_memory_Set_I_De_XC_Mem_Ready_Flag(DI_MEM_IDX, 1);*/	/* num, len, water... is not ready*/
					rtd_printk(KERN_EMERG, TAG_NAME, "De-XC mem alloc from i3ddma\n");

				} else {
					pr_debug("[%s] call VBM_BorrowMemChunk\n",__FUNCTION__);
					if (VBM_BorrowMemChunk((unsigned long *)(&phyaddr), (unsigned long *)(&getSize), de_xc_size) != 0) {
						mem_ctrl[DI_MEM_IDX]->phyaddr = NULL;
						mem_ctrl[DI_MEM_IDX]->getsize = NULL;
						mem_ctrl[DI_MEM_IDX]->Borrow_Mode = De_XC_MEM_UNKNOW;
						rtd_printk(KERN_EMERG, TAG_NAME, "De-XC alloc idma video sequence memory failed\n");
					} else {
						if (getSize < de_xc_size) {
							mem_ctrl[DI_MEM_IDX]->phyaddr = NULL;
							mem_ctrl[DI_MEM_IDX]->getsize = NULL;
							mem_ctrl[DI_MEM_IDX]->Borrow_Mode = De_XC_MEM_UNKNOW;
							rtd_printk(KERN_EMERG, TAG_NAME, "De-XC Memory alloc is not enough, get_szie=%x,size=%x\n", getSize, de_xc_size);
						} else {
							mem_ctrl[DI_MEM_IDX]->phyaddr =  (unsigned int)phyaddr;//(unsigned int)dvr_to_phys((void*)i3ddmaCtrl.cap_buffer[0].cache);
							mem_ctrl[DI_MEM_IDX]->getsize = getSize;
							mem_ctrl[DI_MEM_IDX]->Borrow_Mode = De_XC_MEM_From_VBM_Directly;
							/*drv_memory_Set_I_De_XC_Mem_Ready_Flag(DI_MEM_IDX, 1);*/	/* num, len, water... is not ready*/
							rtd_printk(KERN_EMERG, TAG_NAME, "De-XC mem alloc from VBM Directly = %x\n", mem_ctrl[DI_MEM_IDX]->phyaddr);
						}
					}
				}
			} else {
				rtd_printk(KERN_EMERG, TAG_NAME, "De-XC mem already get from %d\n", mem_ctrl[DI_MEM_IDX]->Borrow_Mode);
			}
		} else {
			if ((mem_ctrl[DI_MEM_IDX]->phyaddr != 0) && (mem_ctrl[DI_MEM_IDX]->Borrow_Mode == De_XC_MEM_From_VBM_Directly)) {
				pr_debug("[%s] call VBM_ReturnMemChunk\n",__FUNCTION__);
				rtd_printk(KERN_EMERG, TAG_NAME, "De-XC mem disconnect, return memroy from VBM = %x\n", mem_ctrl[DI_MEM_IDX]->phyaddr);
				VBM_ReturnMemChunk(mem_ctrl[DI_MEM_IDX]->phyaddr, mem_ctrl[DI_MEM_IDX]->getsize);
			}
			mem_ctrl[DI_MEM_IDX]->phyaddr = NULL;
			mem_ctrl[DI_MEM_IDX]->getsize = NULL;
			mem_ctrl[DI_MEM_IDX]->Borrow_Mode = De_XC_MEM_UNKNOW;
			rtd_printk(KERN_EMERG, TAG_NAME, "De-XC Memory alloc, VSC has disconnected\n");
		}
	}

	if (mem_ctrl[DI_MEM_IDX]->phyaddr == NULL) {
		/*no memory get, turn off de-xc immediately*/
		IoReg_ClearBits(DE_XCXL_DE_XCXL_db_reg_ctl_reg, DE_XCXL_DE_XCXL_db_reg_ctl_db_en_mask);	/* turn off de-xc double buffer,  turn off de-xc immediately*/
		IoReg_ClearBits(DE_XCXL_De_XCXL_CTRL_reg, DE_XCXL_De_XCXL_CTRL_dexc_en_mask);	/* turn off de-xc */
		drv_memory_Set_I_De_XC_Mem_Ready_Flag(DI_MEM_IDX, 0);
	}

	up(&VPQ_DeXC_MEM_Semaphore);

	return (unsigned int)mem_ctrl[DI_MEM_IDX]->phyaddr;
}

unsigned int  drv_memory_I_De_XC_DMA_Config(unsigned int DI_phyAddr, unsigned char DI_MEM_IDX, unsigned char vip_src)
{
	typedef struct _VIP_I_De_XC_DMA {
	    unsigned short  dexc_height;
	    unsigned short  dexc_width;
	    unsigned char   dexc_pixel_bpp;
	    unsigned char   dexc_frame_format;
	    unsigned int    dexc_mem_start;
	    unsigned int    dexc_dat_msize;
	    unsigned int    dexc_inf_msize;
	    unsigned char   dexc_dat_water_r1;
	    unsigned char   dexc_dat_len_r1;
	    unsigned short  dexc_dat_num_r1;
	    unsigned char   dexc_dat_water_r2;
	    unsigned char   dexc_dat_len_r2;
	    unsigned short  dexc_dat_num_r2;
	    unsigned char   dexc_dat_water_w;
	    unsigned char   dexc_dat_len_w;
	    unsigned short  dexc_dat_num_w;
	    unsigned char   dexc_wdma_remain_en;
	    unsigned char   dexc_dat_remain_w;
	    unsigned char   dexc_rdma1_remain_en;
	    unsigned char   dexc_dat_remain_r1;
	    unsigned char   dexc_rdma2_remain_en;
	    unsigned char   dexc_dat_remain_r2;
	    unsigned char   dexc_inf_water_r;
	    unsigned char   dexc_inf_len_r;
	    unsigned short  dexc_inf_num_r;
	    unsigned char   dexc_inf_water_w;
	    unsigned char   dexc_inf_len_w;
	    unsigned short  dexc_inf_num_w;
	    unsigned char   dexc_inf_remain_w_en;
	    unsigned char   dexc_inf_remain_w;
	    unsigned char   dexc_inf_remain_r_en;
	    unsigned char   dexc_inf_remain_r;
	} VIP_I_De_XC_DMA;

	unsigned int DRAM_size;

	VIP_I_De_XC_DMA data;

	/*unsigned int phyAddr = NULL;*/
	unsigned int phyAddr = 0;
	unsigned int height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
	unsigned int width = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);
	unsigned char is422; // fixed to 444 for test
	unsigned char is8bit; // fixed to 10-bit for test

	UINT32 field_size, info_size, tot_size;
	UINT32 data_bit, info_bit;
	UINT32 mem_end = NULL;

	int yuv_size;
	int data_len;
	unsigned char isDTV_or_USB = 255, Vo_from_VDEC = 255, isAdaptivestream_flag = 255, is_usbPlayback = 0;

	if ((vip_src>=VIP_QUALITY_DTV_480I && vip_src<=VIP_QUALITY_PVR_4k2kP_60)) {

		Vo_from_VDEC = Scaler_VOFromVDEC(Scaler_Get_CurVoInfo_plane());
		isAdaptivestream_flag = vsc_get_adaptivestream_flag();

		if (Vo_from_VDEC == SOURCE_DIRECTVO) {
			if (isAdaptivestream_flag == 0) {
				isDTV_or_USB = 1;		/* USB */
				is_usbPlayback = 1;
			} else {
				isDTV_or_USB = 0;	/* CP */
				is_usbPlayback = 0;
			}
		} else {
			if (isAdaptivestream_flag == 0) {
				isDTV_or_USB = 1;	/* DTV */
				is_usbPlayback = 0;
			} else {
				isDTV_or_USB = 0;	/* CP */
				is_usbPlayback = 0;
			}
		}
	} else {
		isDTV_or_USB = 0;
		is_usbPlayback = 0;
	}

	/* Dram size check*/
	DRAM_size = get_memory_size(GFP_DCU1) + get_memory_size(GFP_DCU2);

	rtd_printk(KERN_EMERG, TAG_NAME, " DE-XCXL,heigth=%d,width=%d,DI_mem_idx=%d,vip_src=%d,Vo_from_VDEC=%d,isAdaptivestream_flag=%d,Mem_Layout=0x%x\n",
		height, width, DI_MEM_IDX, vip_src,Vo_from_VDEC,isAdaptivestream_flag,DRAM_size);

#if 1
	if(0)/*((vip_src>=VIP_QUALITY_HDMI_480I && vip_src<=VIP_QUALITY_HDMI_1080P) || (isDTV_or_USB == 1))*/{	/*tunr on in HDMI, usb, DTV*/
			if (height > 1200 || (DI_MEM_IDX == 1 /*&& get_platform() == PLATFORM_KXLP*/) || (DRAM_size <= 0x20000000))	{/* 4K case, s2, 512Mb(), turn off de-xcxl*/
				drv_memory_I_De_XC_DMA_Memory_Get_From_VBM(DI_MEM_IDX, 0, 0, 1);		/* force to release memory*/
				IoReg_ClearBits(DE_XCXL_De_XCXL_CTRL_reg, _BIT0);	/* turn off de-xc */
				IoReg_SetBits(DE_XCXL_DE_XCXL_db_reg_ctl_reg, _BIT0);	/* db apply */
				return NULL;
			} else {
				/*if (get_platform() == PLATFORM_KXL) {
					phyAddr = DI_phyAddr;
					rtd_printk(KERN_EMERG, TAG_NAME, "DE-XCXL, get memory from DI, memStaAddr=%x\n", phyAddr);
				} else*/ if (/*get_platform() == PLATFORM_KXLP && */DI_MEM_IDX == 0) {
					phyAddr = drv_memory_I_De_XC_DMA_Memory_Get_From_VBM(DI_MEM_IDX, width, height, 0);
					rtd_printk(KERN_EMERG, TAG_NAME, "DE-XCXL, get memory from VBM, memStaAddr=%x\n", phyAddr);
				} else {
					drv_memory_I_De_XC_DMA_Memory_Get_From_VBM(DI_MEM_IDX, 0, 0, 1);		/* force to release memory*/
					IoReg_ClearBits(DE_XCXL_De_XCXL_CTRL_reg, _BIT0);	/* turn off de-xc */
					IoReg_SetBits(DE_XCXL_DE_XCXL_db_reg_ctl_reg, _BIT0);	/* db apply */
					rtd_printk(KERN_EMERG, TAG_NAME, "DE-XCXL, Condition error\n");
					return NULL;
			}
		}
	} else {
		drv_memory_I_De_XC_DMA_Memory_Get_From_VBM(DI_MEM_IDX, 0, 0, 1);		/* force to release memory*/
		IoReg_ClearBits(DE_XCXL_De_XCXL_CTRL_reg, _BIT0);	/* turn off de-xc */
		IoReg_SetBits(DE_XCXL_DE_XCXL_db_reg_ctl_reg, _BIT0);	/* db apply */
		return NULL;
	}
#else	/* for test */
	phyAddr = DI_phyAddr;
	phyAddr = 0x2f598800;

	rtd_printk(KERN_EMERG, TAG_NAME, "DE-XCXL, Mem_sta test, Mem_sta from DI=%x,getSize=%x,%x\n", phyAddr);
#endif

	rtd_printk(KERN_EMERG, TAG_NAME, "DE-XCXL, Mem_sta=%x\n", phyAddr);
	//phyAddr = drv_memory_I_De_XC_DMA_Memory_Get_From_VBM(DI_MEM_IDX, 3840, 2160);

	if(phyAddr == NULL) {
		IoReg_ClearBits(DE_XCXL_De_XCXL_CTRL_reg, _BIT0);	/* turn off de-xc */
		IoReg_SetBits(DE_XCXL_DE_XCXL_db_reg_ctl_reg, _BIT0);	/* db apply */
		return NULL;
	}

	if( height > 540  || is_usbPlayback == 1)
		is422 = 1; // 422 for 1080p and usbplayback
	else
		is422 = 0;

	is8bit = 0; // fixed to 10-bit for test

	yuv_size = is422 ? 2 : 3;
	data_len = is8bit ? 8 : 10;
	data_bit = yuv_size * data_len;
	info_bit = 13;

	data.dexc_height = height;
	data.dexc_width = width;
	data.dexc_pixel_bpp = is8bit;
	data.dexc_frame_format = is422;

	// address calculation
	field_size = width * height * data_bit; // bit
	if( (field_size & 0x7F) > 0 )
		field_size = ( (field_size>>7)+1 ) << 4; // round up on 16-byte unit
	else
		field_size = field_size >> 3; // byte

	info_size = ((width+1)>>1) * height * info_bit; // bit
	if( (info_size & 0x7F) > 0 )
		info_size = ( (info_size>>7)+1 ) << 4; // round up on 16-byte unit
	else
		info_size = info_size >> 3; // byte

	tot_size = ( field_size*3 + info_size ) * 2;

	/*// test code for de_xcxl DMA settings, 20160722 jimmy
	if(phyAddr!=NULL)
		pli_free(phyAddr);

	// temp code for memory allocation
	phyAddr = pli_malloc( tot_size, GFP_DCU2_FIRST );*/

	/*info_size += info_size;*/
	/*field_size += 0x10;*/

	data.dexc_mem_start = phyAddr;
	data.dexc_dat_msize = field_size;
	data.dexc_inf_msize = info_size;

	// dma settings
	UINT32 bus_rw_bits = 128;
	UINT32 rw_num, num, remain, length;
	UINT32 total;

	// data dma
	length = 32;
	rw_num = width*height*data_bit;
	if( rw_num % bus_rw_bits > 0 )
		rw_num = rw_num / bus_rw_bits + 1;
	else
		rw_num = rw_num / bus_rw_bits;

	num = rw_num / length;
	remain= rw_num - (num*length);
	if( remain==0 )
	{
		remain = length;
		num--;
	}
	total = 128;

	data.dexc_dat_water_r1 = total-length;
	data.dexc_dat_len_r1 = length;
	data.dexc_dat_num_r1 = num;

	data.dexc_dat_water_r2 = total-length;
	data.dexc_dat_len_r2 = length;
	data.dexc_dat_num_r2 = num;

	data.dexc_dat_water_w = length;
	data.dexc_dat_len_w = length;
	data.dexc_dat_num_w = num;

	data.dexc_wdma_remain_en = 1;
	data.dexc_dat_remain_w = remain;
	data.dexc_rdma1_remain_en = 1;
	data.dexc_dat_remain_r1 = remain;
	data.dexc_rdma2_remain_en = 1;
	data.dexc_dat_remain_r2 = remain;

	// info dma
	length = 16;
	rw_num = width*height*info_bit/2;
	if( rw_num % bus_rw_bits > 0 )
		rw_num = rw_num / bus_rw_bits + 1;
	else
		rw_num = rw_num / bus_rw_bits;

	num = rw_num / length;
	remain= rw_num - (num*length);
	if( remain==0 )
	{
		remain = length;
		num--;
	}
	total = 32;

	data.dexc_inf_water_r = total-length;
	data.dexc_inf_len_r = length;
	data.dexc_inf_num_r = num;

	data.dexc_inf_water_w = length;
	data.dexc_inf_len_w = length;
	data.dexc_inf_num_w = num;

	data.dexc_inf_remain_w_en = 1;
	data.dexc_inf_remain_w = remain;
	data.dexc_inf_remain_r_en = 1;
	data.dexc_inf_remain_r = remain;

	mem_end = drv_memory_Set_I_De_XC_DMA( (void*)&data, DI_MEM_IDX);

	if (mem_end == NULL)
		drv_memory_Set_I_De_XC_Mem_Ready_Flag(DI_MEM_IDX, 0);
	else
		drv_memory_Set_I_De_XC_Mem_Ready_Flag(DI_MEM_IDX, 1);

	/*de-xc need a few frame for memory stable after enable, enable control @ scalerMemory*/
	Scaler_Set_I_De_XC_by_viptable();

	rtd_printk(KERN_EMERG, TAG_NAME, "DE-XCXL, idx=%d,mem sta=%x,mem end=%x, Ready Flag=%d\n",
		DI_MEM_IDX, phyAddr, mem_end, drv_memory_Get_I_De_XC_Mem_Ready_Flag(DI_MEM_IDX));

	return mem_end;
}

unsigned int drv_memory_Set_I_De_XC_DMA(void *dma_data, unsigned char DI_MEM_IDX)
{
	typedef struct _VIP_I_De_XC_DMA {
	    unsigned short  dexc_height;
	    unsigned short  dexc_width;
	    unsigned char   dexc_pixel_bpp;
	    unsigned char   dexc_frame_format;
	    unsigned int    dexc_mem_start;
	    unsigned int    dexc_dat_msize;
	    unsigned int    dexc_inf_msize;
	    unsigned char   dexc_dat_water_r1;
	    unsigned char   dexc_dat_len_r1;
	    unsigned short  dexc_dat_num_r1;
	    unsigned char   dexc_dat_water_r2;
	    unsigned char   dexc_dat_len_r2;
	    unsigned short  dexc_dat_num_r2;
	    unsigned char   dexc_dat_water_w;
	    unsigned char   dexc_dat_len_w;
	    unsigned short  dexc_dat_num_w;
	    unsigned char   dexc_wdma_remain_en;
	    unsigned char   dexc_dat_remain_w;
	    unsigned char   dexc_rdma1_remain_en;
	    unsigned char   dexc_dat_remain_r1;
	    unsigned char   dexc_rdma2_remain_en;
	    unsigned char   dexc_dat_remain_r2;
	    unsigned char   dexc_inf_water_r;
	    unsigned char   dexc_inf_len_r;
	    unsigned short  dexc_inf_num_r;
	    unsigned char   dexc_inf_water_w;
	    unsigned char   dexc_inf_len_w;
	    unsigned short  dexc_inf_num_w;
	    unsigned char   dexc_inf_remain_w_en;
	    unsigned char   dexc_inf_remain_w;
	    unsigned char   dexc_inf_remain_r_en;
	    unsigned char   dexc_inf_remain_r;
	} VIP_I_De_XC_DMA;

	UINT32 baseAddr;
	UINT32 nBaseAddr;
	UINT32 nFldSize;
	UINT32 nInfSize;
	UINT32 tmpAddr;
	UINT32 field_size, info_size, tot_size;
	UINT32 mem_end;
	UINT32 data_bit, info_bit;
	VIP_I_De_XC_DMA *ptr = (VIP_I_De_XC_DMA*) dma_data;

	/* db enable*/
	IoReg_SetBits(DE_XCXL_DE_XCXL_db_reg_ctl_reg, DE_XCXL_DE_XCXL_db_reg_ctl_db_en_mask);

	// frame format
	de_xcxl_frame_format_RBUS de_xcxl_frame_format_reg;
	de_xcxl_frame_format_reg.regValue = IoReg_Read32(DE_XCXL_Frame_format_reg);

	de_xcxl_frame_format_reg.height         = ptr->dexc_height;
	de_xcxl_frame_format_reg.width          = ptr->dexc_width;
	de_xcxl_frame_format_reg.pixel_bpp      = ptr->dexc_pixel_bpp;
	de_xcxl_frame_format_reg.frame_format   = ptr->dexc_frame_format;

	IoReg_Write32( DE_XCXL_Frame_format_reg, de_xcxl_frame_format_reg.regValue );

 	// address calculation
	baseAddr    = ptr->dexc_mem_start;
	field_size  = ptr->dexc_dat_msize;
	info_size   = ptr->dexc_inf_msize;
	//mem_end = baseAddr + field_size *6 + info_size *2;

	nBaseAddr = (baseAddr>>3)&0x1fffffff;
	nFldSize = (field_size>>3)&0x1fffffff; // 8-byte
	nInfSize = (info_size>>3)&0x1fffffff;

	//de_xcxl_datmemstartadd1_s0_RBUS 		de_xcxl_datmemstartadd1_s0_reg;
	de_xcxl_datmemstartadd2_s0_RBUS 		de_xcxl_datmemstartadd2_s0_reg;
	de_xcxl_datmemstartadd3_s0_RBUS 		de_xcxl_datmemstartadd3_s0_reg;
	de_xcxl_infmemstartadd_s0_RBUS		    de_xcxl_infmemstartadd_s0_reg;
	//de_xcxl_datmemstartadd1_odd_s0_RBUS 	de_xcxl_datmemstartadd1_odd_s0_reg;
	de_xcxl_datmemstartadd2_odd_s0_RBUS 	de_xcxl_datmemstartadd2_odd_s0_reg;
	de_xcxl_datmemstartadd3_odd_s0_RBUS 	de_xcxl_datmemstartadd3_odd_s0_reg;
	de_xcxl_infmemstartadd_odd_s0_RBUS	    de_xcxl_infmemstartadd_odd_s0_reg;

	//de_xcxl_datmemstartadd1_s1_RBUS 		de_xcxl_datmemstartadd1_s1_reg;
	de_xcxl_datmemstartadd2_s1_RBUS 		de_xcxl_datmemstartadd2_s1_reg;
	de_xcxl_datmemstartadd3_s1_RBUS 		de_xcxl_datmemstartadd3_s1_reg;
	de_xcxl_infmemstartadd_s1_RBUS		    de_xcxl_infmemstartadd_s1_reg;
	//de_xcxl_datmemstartadd1_odd_s1_RBUS 	de_xcxl_datmemstartadd1_odd_s1_reg;
	de_xcxl_datmemstartadd2_odd_s1_RBUS 	de_xcxl_datmemstartadd2_odd_s1_reg;
	de_xcxl_datmemstartadd3_odd_s1_RBUS 	de_xcxl_datmemstartadd3_odd_s1_reg;
	de_xcxl_infmemstartadd_odd_s1_RBUS	    de_xcxl_infmemstartadd_odd_s1_reg;

	de_xcxl_de_xcxl_db_reg_ctl_RBUS	de_xcxl_de_xcxl_db_reg_ctl_reg;

	//de_xcxl_datmemstartadd1_s0_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd1_S0_reg);
	de_xcxl_datmemstartadd2_s0_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd2_S0_reg);
	de_xcxl_datmemstartadd3_s0_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd3_S0_reg);
	de_xcxl_infmemstartadd_s0_reg.regValue = IoReg_Read32(DE_XCXL_INFMemStartAdd_S0_reg);
	//de_xcxl_datmemstartadd1_odd_s0_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd1_Odd_S0_reg);
	de_xcxl_datmemstartadd2_odd_s0_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd2_Odd_S0_reg);
	de_xcxl_datmemstartadd3_odd_s0_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd3_Odd_S0_reg);
	de_xcxl_infmemstartadd_odd_s0_reg.regValue = IoReg_Read32(DE_XCXL_INFMemStartAdd_Odd_S0_reg);

	//de_xcxl_datmemstartadd1_s1_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd1_S1_reg);
	de_xcxl_datmemstartadd2_s1_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd2_S1_reg);
	de_xcxl_datmemstartadd3_s1_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd3_S1_reg);
	de_xcxl_infmemstartadd_s1_reg.regValue = IoReg_Read32(DE_XCXL_INFMemStartAdd_S1_reg);
	//de_xcxl_datmemstartadd1_odd_s1_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd1_Odd_S1_reg);
	de_xcxl_datmemstartadd2_odd_s1_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd2_Odd_S1_reg);
	de_xcxl_datmemstartadd3_odd_s1_reg.regValue = IoReg_Read32(DE_XCXL_DATMemStartAdd3_Odd_S1_reg);
	de_xcxl_infmemstartadd_odd_s1_reg.regValue = IoReg_Read32(DE_XCXL_INFMemStartAdd_Odd_S1_reg);

	if (DI_MEM_IDX == 0) {
		tmpAddr = nBaseAddr;
		//de_xcxl_datmemstartadd1_s0_reg.s0_dat_mstart_86_58 = tmpAddr;
		//tmpAddr += nFldSize;
		de_xcxl_datmemstartadd2_s0_reg.s0_dat_mstart_57_29 = tmpAddr;
		tmpAddr += nFldSize;
		de_xcxl_datmemstartadd3_s0_reg.s0_dat_mstart_28_0 = tmpAddr;
		tmpAddr += nFldSize;
		de_xcxl_infmemstartadd_s0_reg.s0_inf_mstart = tmpAddr;
		tmpAddr += nInfSize;

		//de_xcxl_datmemstartadd1_odd_s0_reg.s0_dat_mstart_odd_86_58 = tmpAddr;
		//tmpAddr += nFldSize;
		de_xcxl_datmemstartadd2_odd_s0_reg.s0_dat_mstart_odd_57_29 = tmpAddr;
		tmpAddr += nFldSize;
		de_xcxl_datmemstartadd3_odd_s0_reg.s0_dat_mstart_odd_28_0 = tmpAddr;
		tmpAddr += nFldSize;
		de_xcxl_infmemstartadd_odd_s0_reg.s0_inf_mstart_odd = tmpAddr;
		tmpAddr += nInfSize;

		//IoReg_Write32( DE_XCXL_DATMemStartAdd1_S0_reg, de_xcxl_datmemstartadd1_s0_reg.regValue );
		IoReg_Write32( DE_XCXL_DATMemStartAdd2_S0_reg, de_xcxl_datmemstartadd2_s0_reg.regValue );
		IoReg_Write32( DE_XCXL_DATMemStartAdd3_S0_reg, de_xcxl_datmemstartadd3_s0_reg.regValue );
		IoReg_Write32( DE_XCXL_INFMemStartAdd_S0_reg, de_xcxl_infmemstartadd_s0_reg.regValue );
		//IoReg_Write32( DE_XCXL_DATMemStartAdd1_Odd_S0_reg, de_xcxl_datmemstartadd1_odd_s0_reg.regValue );
		IoReg_Write32( DE_XCXL_DATMemStartAdd2_Odd_S0_reg, de_xcxl_datmemstartadd2_odd_s0_reg.regValue );
		IoReg_Write32( DE_XCXL_DATMemStartAdd3_Odd_S0_reg, de_xcxl_datmemstartadd3_odd_s0_reg.regValue );
		IoReg_Write32( DE_XCXL_INFMemStartAdd_Odd_S0_reg, de_xcxl_infmemstartadd_odd_s0_reg.regValue );
	} else {
		tmpAddr = nBaseAddr;
		//de_xcxl_datmemstartadd1_s1_reg.s1_dat_mstart_86_58 = tmpAddr;
		//tmpAddr += nFldSize;
		de_xcxl_datmemstartadd2_s1_reg.s1_dat_mstart_57_29 = tmpAddr;
		tmpAddr += nFldSize;
		de_xcxl_datmemstartadd3_s1_reg.s1_dat_mstart_28_0 = tmpAddr;
		tmpAddr += nFldSize;
		de_xcxl_infmemstartadd_s1_reg.s1_inf_mstart = tmpAddr;
		tmpAddr += nInfSize;

		//de_xcxl_datmemstartadd1_odd_s1_reg.s1_dat_mstart_odd_86_58 = tmpAddr;
		//tmpAddr += nFldSize;
		de_xcxl_datmemstartadd2_odd_s1_reg.s1_dat_mstart_odd_57_29 = tmpAddr;
		tmpAddr += nFldSize;
		de_xcxl_datmemstartadd3_odd_s1_reg.s1_dat_mstart_odd_28_0 = tmpAddr;
		tmpAddr += nFldSize;
		de_xcxl_infmemstartadd_odd_s1_reg.s1_inf_mstart_odd = tmpAddr;
		tmpAddr += nInfSize;

		//IoReg_Write32( DE_XCXL_DATMemStartAdd1_S1_reg, de_xcxl_datmemstartadd1_s1_reg.regValue );
		IoReg_Write32( DE_XCXL_DATMemStartAdd2_S1_reg, de_xcxl_datmemstartadd2_s1_reg.regValue );
		IoReg_Write32( DE_XCXL_DATMemStartAdd3_S1_reg, de_xcxl_datmemstartadd3_s1_reg.regValue );
		IoReg_Write32( DE_XCXL_INFMemStartAdd_S1_reg, de_xcxl_infmemstartadd_s1_reg.regValue );
		//IoReg_Write32( DE_XCXL_DATMemStartAdd1_Odd_S1_reg, de_xcxl_datmemstartadd1_odd_s1_reg.regValue );
		IoReg_Write32( DE_XCXL_DATMemStartAdd2_Odd_S1_reg, de_xcxl_datmemstartadd2_odd_s1_reg.regValue );
		IoReg_Write32( DE_XCXL_DATMemStartAdd3_Odd_S1_reg, de_xcxl_datmemstartadd3_odd_s1_reg.regValue );
		IoReg_Write32( DE_XCXL_INFMemStartAdd_Odd_S1_reg, de_xcxl_infmemstartadd_odd_s1_reg.regValue );
	}
	// boundary address
	de_xcxl_wrrd_bndaddr1_RBUS de_xcxl_wrrd_bndaddr1_reg;
	de_xcxl_wrrd_bndaddr2_RBUS de_xcxl_wrrd_bndaddr2_reg;

	de_xcxl_wrrd_bndaddr1_reg.regValue = IoReg_Read32(DE_XCXL_WRRD_BndAddr1_reg);
	de_xcxl_wrrd_bndaddr2_reg.regValue = IoReg_Read32(DE_XCXL_WRRD_BndAddr2_reg);

	de_xcxl_wrrd_bndaddr1_reg.dexcxl_wrrd_downlimit_adr = nBaseAddr;
	de_xcxl_wrrd_bndaddr2_reg.dexcxl_wrrd_uplimit_adr = tmpAddr;

	IoReg_Write32( DE_XCXL_WRRD_BndAddr1_reg, de_xcxl_wrrd_bndaddr1_reg.regValue );
	IoReg_Write32( DE_XCXL_WRRD_BndAddr2_reg, de_xcxl_wrrd_bndaddr2_reg.regValue );

	// dma settings
	de_xcxl_rdatdma_set1_RBUS de_xcxl_rdatdma_set1_reg;
	de_xcxl_rdatdma_set1_reg.regValue = IoReg_Read32(DE_XCXL_RDATDMA_Set1_reg);
	de_xcxl_rdatdma_set1_reg.dat_water_r1   = ptr->dexc_dat_water_r1;
	de_xcxl_rdatdma_set1_reg.dat_len_r1     = ptr->dexc_dat_len_r1;
	de_xcxl_rdatdma_set1_reg.dat_num_r1     = ptr->dexc_dat_num_r1;
	IoReg_Write32( DE_XCXL_RDATDMA_Set1_reg, de_xcxl_rdatdma_set1_reg.regValue );

	de_xcxl_rdatdma_set2_RBUS de_xcxl_rdatdma_set2_reg;
	de_xcxl_rdatdma_set2_reg.regValue = IoReg_Read32(DE_XCXL_RDATDMA_Set2_reg);
	de_xcxl_rdatdma_set2_reg.dat_water_r2   = ptr->dexc_dat_water_r2;
	de_xcxl_rdatdma_set2_reg.dat_len_r2     = ptr->dexc_dat_len_r2;
	de_xcxl_rdatdma_set2_reg.dat_num_r2     = ptr->dexc_dat_num_r2;
	IoReg_Write32( DE_XCXL_RDATDMA_Set2_reg, de_xcxl_rdatdma_set2_reg.regValue );

	de_xcxl_wdatdma_set_RBUS de_xcxl_wdatdma_set_reg;
	de_xcxl_wdatdma_set_reg.regValue = IoReg_Read32(DE_XCXL_WDATDMA_Set_reg);
	de_xcxl_wdatdma_set_reg.dat_water_w     = ptr->dexc_dat_water_w;
	de_xcxl_wdatdma_set_reg.dat_len_w       = ptr->dexc_dat_len_w;
	de_xcxl_wdatdma_set_reg.dat_num_w       = ptr->dexc_dat_num_w;
	IoReg_Write32( DE_XCXL_WDATDMA_Set_reg, de_xcxl_wdatdma_set_reg.regValue );

	de_xcxl_datdma_rm_set_RBUS de_xcxl_datdma_rm_set_reg;
	de_xcxl_datdma_rm_set_reg.regValue = IoReg_Read32(DE_XCXL_DATDMA_RM_Set_reg);
	de_xcxl_datdma_rm_set_reg.wdma_remain_en    = ptr->dexc_wdma_remain_en;
	de_xcxl_datdma_rm_set_reg.dat_remain_w      = ptr->dexc_dat_remain_w;
	de_xcxl_datdma_rm_set_reg.rdma1_remain_en   = ptr->dexc_rdma1_remain_en;
	de_xcxl_datdma_rm_set_reg.dat_remain_r1     = ptr->dexc_dat_remain_r1;
	de_xcxl_datdma_rm_set_reg.rdma2_remain_en   = ptr->dexc_rdma2_remain_en;
	de_xcxl_datdma_rm_set_reg.dat_remain_r2     = ptr->dexc_dat_remain_r2;
	IoReg_Write32( DE_XCXL_DATDMA_RM_Set_reg, de_xcxl_datdma_rm_set_reg.regValue );

	de_xcxl_rinfdma_set_RBUS de_xcxl_rinfdma_set_reg;
	de_xcxl_rinfdma_set_reg.regValue = IoReg_Read32(DE_XCXL_RINFDMA_Set_reg);
	de_xcxl_rinfdma_set_reg.inf_water_r = ptr->dexc_inf_water_r;
	de_xcxl_rinfdma_set_reg.inf_len_r   = ptr->dexc_inf_len_r;
	de_xcxl_rinfdma_set_reg.inf_num_r   = ptr->dexc_inf_num_r;
	IoReg_Write32( DE_XCXL_RINFDMA_Set_reg, de_xcxl_rinfdma_set_reg.regValue );

	de_xcxl_winfdma_set_RBUS de_xcxl_winfdma_set_reg;
	de_xcxl_winfdma_set_reg.regValue = IoReg_Read32(DE_XCXL_WINFDMA_Set_reg);
	de_xcxl_winfdma_set_reg.inf_water_w = ptr->dexc_inf_water_w;
	de_xcxl_winfdma_set_reg.inf_len_w   = ptr->dexc_inf_len_w;
	de_xcxl_winfdma_set_reg.inf_num_w   = ptr->dexc_inf_num_w;
	IoReg_Write32( DE_XCXL_WINFDMA_Set_reg, de_xcxl_winfdma_set_reg.regValue );

	de_xcxl_infdma_rm_set_RBUS de_xcxl_infdma_rm_set_reg;
	de_xcxl_infdma_rm_set_reg.regValue = IoReg_Read32(DE_XCXL_INFDMA_RM_Set_reg);
	de_xcxl_infdma_rm_set_reg.inf_remain_w_en   = ptr->dexc_inf_remain_w_en;
	de_xcxl_infdma_rm_set_reg.inf_remain_w      = ptr->dexc_inf_remain_w;
	de_xcxl_infdma_rm_set_reg.inf_remain_r_en   = ptr->dexc_inf_remain_r_en;
	de_xcxl_infdma_rm_set_reg.inf_remain_r      = ptr->dexc_inf_remain_r;
	IoReg_Write32( DE_XCXL_INFDMA_RM_Set_reg, de_xcxl_infdma_rm_set_reg.regValue );

	de_xcxl_dma_multi_req_set_RBUS	de_xcxl_dma_multi_req_set_reg;
	de_xcxl_dma_multi_req_set_reg.regValue = IoReg_Read32(DE_XCXL_DMA_Multi_Req_Set_reg);
	de_xcxl_dma_multi_req_set_reg.rdma_req_num = 8;
	de_xcxl_dma_multi_req_set_reg.wdma_req_num = 8;
	IoReg_Write32( DE_XCXL_DMA_Multi_Req_Set_reg, de_xcxl_dma_multi_req_set_reg.regValue );

	de_xcxl_de_xcxl_db_reg_ctl_reg.regValue = IoReg_Read32(DE_XCXL_DE_XCXL_db_reg_ctl_reg);
	de_xcxl_de_xcxl_db_reg_ctl_reg.db_apply = 1;
	IoReg_Write32( DE_XCXL_DE_XCXL_db_reg_ctl_reg, de_xcxl_de_xcxl_db_reg_ctl_reg.regValue );

	mem_end = tmpAddr<<3;

	return mem_end;
}

unsigned char I_De_XC_Mem_Ready_Flag[2] = {0};
unsigned char drv_memory_Set_I_De_XC_Mem_Ready_Flag(unsigned char MEM_IDX, unsigned char Flag)
{
	if (MEM_IDX>=2)
		return 255;
	I_De_XC_Mem_Ready_Flag[MEM_IDX] = Flag;
	return 0;
}

unsigned char drv_memory_Get_I_De_XC_Mem_Ready_Flag(unsigned char MEM_IDX)
{
	if (MEM_IDX>=2)
		return 255;
	return I_De_XC_Mem_Ready_Flag[MEM_IDX];
}

unsigned int drv_memory_MA_SNR_Config(unsigned char access ,unsigned int phyAddr, unsigned char DI_MEM_IDX)
{
	/* DI part. */
	#if 0	//to do: spec change 20161203
	di_mvf_watmemorystart_s0_add0_RBUS di_mvf_watmemorystart_s0_add0_reg;
	di_mvf_watmemorystart_s0_add1_RBUS di_mvf_watmemorystart_s0_add1_reg;
	di_mvf_watmemorystart_s0_add2_RBUS di_mvf_watmemorystart_s0_add2_reg;
	di_mvf_watmemorystart_s1add0_RBUS di_mvf_watmemorystart_s1_add0_reg;
	di_mvf_watmemorystart_s1_add1_RBUS di_mvf_watmemorystart_s1_add1_reg;
	di_mvf_watmemorystart_s1_add2_RBUS di_mvf_watmemorystart_s1_add2_reg;
	di_mvf_ddr_wdma_wtlennum_RBUS di_mvf_ddr_wdma_wtlennum_reg;
	di_mvf_ddr_wdatdma_rm_RBUS di_mvf_ddr_wdatdma_rm_reg;
	#endif
	di_db_reg_ctl_RBUS di_db_reg_ctl_reg;

	/* SNR part*/
	#if 0	//to do: spec change 20161203
	iedge_smooth_mvf_dma_dat_format_RBUS iedge_smooth_mvf_dma_dat_format_reg;
	iedge_smooth_mvf_datmemorystart_s0_add0_RBUS iedge_smooth_mvf_datmemorystart_s0_add0_reg;
	iedge_smooth_mvf_datmemorystart_s0_add1_RBUS iedge_smooth_mvf_datmemorystart_s0_add1_reg;
	iedge_smooth_mvf_datmemorystart_s0_add2_RBUS iedge_smooth_mvf_datmemorystart_s0_add2_reg;
	iedge_smooth_mvf_datmemorystart_s1add0_RBUS iedge_smooth_mvf_datmemorystart_s1_add0_reg;
	iedge_smooth_mvf_datmemorystart_s1_add1_RBUS iedge_smooth_mvf_datmemorystart_s1_add1_reg;
	iedge_smooth_mvf_datmemorystart_s1_add2_RBUS iedge_smooth_mvf_datmemorystart_s1_add2_reg;
	iedge_smooth_mvf_ddr_dma_wtlennum_RBUS iedge_smooth_mvf_ddr_dma_wtlennum_reg;
	iedge_smooth_mvf_ddr_datdma_rm_RBUS iedge_smooth_mvf_ddr_datdma_rm_reg;
	#endif
	iedge_smooth_edsm_db_ctrl_RBUS iedge_smooth_edsm_db_ctrl_reg;

	unsigned int height = Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN);
	unsigned int width = Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID);
	unsigned int pixel_total = height * width;
	unsigned short water, len, remain, num;
	unsigned int mem0, mem1, mem2, mem_end;
	unsigned int buffer;

	/* DI part. */
	#if 0	//to do: spec change 20161203
	di_mvf_watmemorystart_s0_add0_reg.regValue = IoReg_Read32(DI_MVF_WATMemoryStart_S0_Add0_reg);
	di_mvf_watmemorystart_s0_add1_reg.regValue = IoReg_Read32(DI_MVF_WATMemoryStart_S0_Add1_reg);
	di_mvf_watmemorystart_s0_add2_reg.regValue = IoReg_Read32(DI_MVF_WATMemoryStart_S0_Add2_reg);
	di_mvf_watmemorystart_s1_add0_reg.regValue = IoReg_Read32(DI_MVF_WATMemoryStart_S1Add0_reg);
	di_mvf_watmemorystart_s1_add1_reg.regValue = IoReg_Read32(DI_MVF_WATMemoryStart_S1_Add1_reg);
	di_mvf_watmemorystart_s1_add2_reg.regValue = IoReg_Read32(DI_MVF_WATMemoryStart_S1_Add2_reg);
	di_mvf_ddr_wdma_wtlennum_reg.regValue = IoReg_Read32(DI_MVF_DDR_WDMA_WTLENNUM_reg);
	di_mvf_ddr_wdatdma_rm_reg.regValue = IoReg_Read32(DI_MVF_DDR_WDATDMA_RM_reg);
	#endif

	/* SNR part*/
	#if 0	//to do: spec change 20161203
	iedge_smooth_mvf_dma_dat_format_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_MVF_DMA_Dat_format_reg);
	iedge_smooth_mvf_datmemorystart_s0_add0_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_MVF_DATMemoryStart_S0_Add0_reg);
	iedge_smooth_mvf_datmemorystart_s0_add1_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_MVF_DATMemoryStart_S0_Add1_reg);
	iedge_smooth_mvf_datmemorystart_s0_add2_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_MVF_DATMemoryStart_S0_Add2_reg);
	iedge_smooth_mvf_datmemorystart_s1_add0_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_MVF_DATMemoryStart_S1Add0_reg);
	iedge_smooth_mvf_datmemorystart_s1_add1_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_MVF_DATMemoryStart_S1_Add1_reg);
	iedge_smooth_mvf_datmemorystart_s1_add2_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_MVF_DATMemoryStart_S1_Add2_reg);
	iedge_smooth_mvf_ddr_dma_wtlennum_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_MVF_DDR_DMA_WTLENNUM_reg);
	iedge_smooth_mvf_ddr_datdma_rm_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_MVF_DDR_DATDMA_RM_reg);
	#endif

	buffer = drv_memory_Get_MA_SNR_Info_Size_Static(access, width, height, DI_MEM_IDX);
	mem0 = (phyAddr);
	mem1 = (phyAddr + buffer);
	mem2 = (phyAddr + buffer * 2);
	mem_end = phyAddr + buffer * 3;

	water = 16;	/*DI FIFO is 32, use 16*/
	len = 16;		/*DI FIFO is 32, use 16*/
	num = (pixel_total>>6) / len;	/* number*lenth+remain = pixel number*2/128, 128b per num */
	remain = (pixel_total>>6) - len * num;
	if (remain == 0) { /* remain can't be 0*/
		num -= 1;
		remain = len;
	}

	/* DI part. */
	#if 0	//to do: spec change 20161203
	di_mvf_ddr_wdma_wtlennum_reg.mvf_inf_len_w = len;
	di_mvf_ddr_wdma_wtlennum_reg.mvf_inf_water_w = water;
	di_mvf_ddr_wdma_wtlennum_reg.mvf_inf_num_w = num;
	di_mvf_ddr_wdatdma_rm_reg.mvf_inf_remain_w = remain;
	rtd_printk(KERN_EMERG, TAG_NAME, "MA-SNR,water=%d, len=%d,num=%d,remain=%d\n", water, len ,num ,remain);

	if (DI_MEM_IDX == 0) {
		di_mvf_watmemorystart_s0_add0_reg.s0_mstart_86_58 = mem0>>3;	/* bit 0~2 is reserved*/
		di_mvf_watmemorystart_s0_add1_reg.s0_mstart_57_29 = mem1>>3;	/* bit 0~2 is reserved*/
		di_mvf_watmemorystart_s0_add2_reg.s0_mstart_28_0 = mem2>>3;	/* bit 0~2 is reserved*/
	} else {
		di_mvf_watmemorystart_s1_add0_reg.s1_mstart_86_58 = mem0>>3;	/* bit 0~2 is reserved*/
		di_mvf_watmemorystart_s1_add1_reg.s1_mstart_57_29 = mem1>>3;	/* bit 0~2 is reserved*/
		di_mvf_watmemorystart_s1_add2_reg.s1_mstart_28_0 = mem2>>3;	/* bit 0~2 is reserved*/
	}
	rtd_printk(KERN_EMERG, TAG_NAME,"MA-SNR,phyAddr0=%x, phyAddr1=%x,phyAddr2=%x,mem_end=%x,data_size=%d\n", mem0, mem1, mem2,mem_end,buffer);
	#endif

	/* SNR part*/
	/* same as DI part ? */
	#if 0	//to do: spec change 20161203
	iedge_smooth_mvf_ddr_dma_wtlennum_reg.dat_len = len;
	iedge_smooth_mvf_ddr_dma_wtlennum_reg.dat_water = water;
	iedge_smooth_mvf_ddr_dma_wtlennum_reg.dat_num = num;
	iedge_smooth_mvf_ddr_datdma_rm_reg.dat_remain = remain;
	iedge_smooth_mvf_ddr_datdma_rm_reg.dma_remain_en = 1;

	iedge_smooth_mvf_dma_dat_format_reg.mvf_progressive = (access == SLR_DI_progress_mode)?1:0;
	iedge_smooth_mvf_dma_dat_format_reg.delay_frame_num = (access == SLR_DI_5A_mode)?2:1;
	iedge_smooth_mvf_dma_dat_format_reg.mvf_height = height;
	iedge_smooth_mvf_dma_dat_format_reg.mvf_width = width;

	if (DI_MEM_IDX == 0) {
		iedge_smooth_mvf_datmemorystart_s0_add0_reg.s0_mstart_86_58= mem0>>3;	/* bit 0~2 is reserved*/
		iedge_smooth_mvf_datmemorystart_s0_add1_reg.s0_mstart_57_29 = mem1>>3;	/* bit 0~2 is reserved*/
		iedge_smooth_mvf_datmemorystart_s0_add2_reg.s0_mstart_28_0 = mem2>>3;	/* bit 0~2 is reserved*/
	} else {
		iedge_smooth_mvf_datmemorystart_s1_add0_reg.s1_mstart_86_58= mem0>>3;	/* bit 0~2 is reserved*/
		iedge_smooth_mvf_datmemorystart_s1_add1_reg.s1_mstart_57_29 = mem1>>3;	/* bit 0~2 is reserved*/
		iedge_smooth_mvf_datmemorystart_s1_add2_reg.s1_mstart_28_0 = mem2>>3;	/* bit 0~2 is reserved*/
	}
	rtd_printk(KERN_EMERG, TAG_NAME, "MA-SNR,access=%d, heigth=%d,width=%d, DI_mem_idx=%d\n", access, height, width, DI_MEM_IDX);
	#endif

	/* DI part. */
	#if 0	//to do: spec change 20161203
	IoReg_Write32(DI_MVF_DDR_WDMA_WTLENNUM_reg, di_mvf_ddr_wdma_wtlennum_reg.regValue);
	IoReg_Write32(DI_MVF_DDR_WDATDMA_RM_reg, di_mvf_ddr_wdatdma_rm_reg.regValue );

	if (DI_MEM_IDX == 0) {
		IoReg_Write32(DI_MVF_WATMemoryStart_S0_Add0_reg, di_mvf_watmemorystart_s0_add0_reg.regValue);
		IoReg_Write32(DI_MVF_WATMemoryStart_S0_Add1_reg, di_mvf_watmemorystart_s0_add1_reg.regValue);
		IoReg_Write32(DI_MVF_WATMemoryStart_S0_Add2_reg, di_mvf_watmemorystart_s0_add2_reg.regValue);
	} else {
		IoReg_Write32(DI_MVF_WATMemoryStart_S1Add0_reg, di_mvf_watmemorystart_s1_add0_reg.regValue);
		IoReg_Write32(DI_MVF_WATMemoryStart_S1_Add1_reg, di_mvf_watmemorystart_s1_add1_reg.regValue);
		IoReg_Write32(DI_MVF_WATMemoryStart_S1_Add2_reg, di_mvf_watmemorystart_s1_add2_reg.regValue);
	}
	#endif
	/* SNR part*/
	#if 0	//to do: spec change 20161203
	IoReg_Write32(IEDGE_SMOOTH_MVF_DMA_Dat_format_reg, iedge_smooth_mvf_dma_dat_format_reg.regValue);
	IoReg_Write32(IEDGE_SMOOTH_MVF_DDR_DMA_WTLENNUM_reg, iedge_smooth_mvf_ddr_dma_wtlennum_reg.regValue);
	IoReg_Write32(IEDGE_SMOOTH_MVF_DDR_DATDMA_RM_reg, iedge_smooth_mvf_ddr_datdma_rm_reg.regValue);
	#endif

	#if 0	//to do: spec change 20161203
	if (DI_MEM_IDX == 0) {
		IoReg_Write32(IEDGE_SMOOTH_MVF_DATMemoryStart_S0_Add0_reg, iedge_smooth_mvf_datmemorystart_s0_add0_reg.regValue);
		IoReg_Write32(IEDGE_SMOOTH_MVF_DATMemoryStart_S0_Add1_reg, iedge_smooth_mvf_datmemorystart_s0_add1_reg.regValue );
		IoReg_Write32(IEDGE_SMOOTH_MVF_DATMemoryStart_S0_Add2_reg, iedge_smooth_mvf_datmemorystart_s0_add2_reg.regValue);
	} else {
		IoReg_Write32(IEDGE_SMOOTH_MVF_DATMemoryStart_S1Add0_reg, iedge_smooth_mvf_datmemorystart_s1_add0_reg.regValue );
		IoReg_Write32(IEDGE_SMOOTH_MVF_DATMemoryStart_S1_Add1_reg, iedge_smooth_mvf_datmemorystart_s1_add1_reg.regValue);
		IoReg_Write32(IEDGE_SMOOTH_MVF_DATMemoryStart_S1_Add2_reg, iedge_smooth_mvf_datmemorystart_s1_add2_reg.regValue);
	}
	#endif

	/* double buffer*/
	di_db_reg_ctl_reg.regValue = IoReg_Read32(DI_db_reg_ctl_reg);
	di_db_reg_ctl_reg.db_apply = 1;
	IoReg_Write32(DI_db_reg_ctl_reg, di_db_reg_ctl_reg.regValue);

	iedge_smooth_edsm_db_ctrl_reg.regValue = IoReg_Read32(IEDGE_SMOOTH_EDSM_DB_CTRL_reg);
	iedge_smooth_edsm_db_ctrl_reg.edsm_db_apply = 1;
	IoReg_Write32(IEDGE_SMOOTH_EDSM_DB_CTRL_reg, iedge_smooth_edsm_db_ctrl_reg.regValue);

	return mem_end;
}

unsigned int  drv_memory_Get_MA_SNR_Info_Size_Static(unsigned char access, unsigned int I_Width, unsigned int I_Height, unsigned char DI_MEM_IDX)
{
	unsigned int buffer_size;
	unsigned int  add_more = 0x10;
#if 1
	if (I_Height <= 1200) {	/* 1080p case*/
		buffer_size = 0x7E900 + add_more; /*info = 1.483154297 MB in 1080p, 0.49438476567 MB per frame, 3 buffer allocation*/
	} else {
		buffer_size = 0x1FA400  + add_more; /*info  = 5.932617188 MB in 4K, 1.97753906267 MB per frame, 3 buffer allocation*/
	}

	if (DI_MEM_IDX == 1 && get_platform() == PLATFORM_KXLP)
		buffer_size = 0x10E00 + add_more;		/* info  = 0.197753906 Mb in 576i,  0.0659179687 Mb per frame , 3 buffer allocation, 27M*/

#else
	buffer_size = (I_Width * I_Height * 2) >> 3;
	buffer_size = buffer_size + add_more;
#endif
	return buffer_size;
}

#endif

void drv_memory_wait_cap_last_write_done(unsigned char display, unsigned char wait_frame){
	mdomain_cap_cap_ddr_fifostatus_RBUS cap_ddr_fifostatus_reg;
	unsigned int count;
	unsigned char pre_cap_idx;

	if(display == SLR_MAIN_DISPLAY){
		do{
			count = 40;
			pre_cap_idx = MDOMAIN_CAP_DDR_In1Status_get_in1_block_select(IoReg_Read32(MDOMAIN_CAP_DDR_In1Status_reg));
            		printk(KERN_NOTICE"M domain main done-0, cap pre idx = %d\n", pre_cap_idx);

			/*check memory cap down*/
                	cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
                	while(!(cap_ddr_fifostatus_reg.in1_cap_last_wr_flag) && --count){
                   		cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
                    	msleep(1);//no busy delay
                	}

            		printk(KERN_NOTICE"M domain main done-1, cap new idx = %d\n", MDOMAIN_CAP_DDR_In1Status_get_in1_block_select(IoReg_Read32(MDOMAIN_CAP_DDR_In1Status_reg)));

			if(count == 0)
                		printk(KERN_ERR"M domain main timeout-1 !\n");

            		// [KTASKWBS-5316] wait M-capture write done if capure block index == 0
            		if(MDOMAIN_CAP_DDR_In1Status_get_in1_block_select(IoReg_Read32(MDOMAIN_CAP_DDR_In1Status_reg)) == pre_cap_idx)
            		{
                		count = 40;
                		/*check memory cap down*/
                		cap_ddr_fifostatus_reg.in1_cap_last_wr_flag = 1;
                		IoReg_Write32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg, cap_ddr_fifostatus_reg.regValue);

                		cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
                		while(!(cap_ddr_fifostatus_reg.in1_cap_last_wr_flag) && --count){
                    		cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
                    		msleep(1);//no busy delay
                		}
                		printk(KERN_NOTICE"M domain main done-2(check again), cap new idx = %d\n", MDOMAIN_CAP_DDR_In1Status_get_in1_block_select(IoReg_Read32(MDOMAIN_CAP_DDR_In1Status_reg)));
                		if(count == 0)
                    		printk(KERN_ERR"M domain main timeout-2 !\n");
            		}
			wait_frame--;

			//if wait_frame > 0, clear again
			if(wait_frame > 0){
				cap_ddr_fifostatus_reg.in1_cap_last_wr_flag = 1;
                		IoReg_Write32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg, cap_ddr_fifostatus_reg.regValue);
			}
		}while(wait_frame != 0);
	}
	else{
		do{
			count = 40;
			pre_cap_idx = MDOMAIN_CAP_DDR_In2Status_get_in2_block_select(IoReg_Read32(MDOMAIN_CAP_DDR_In2Status_reg));

					/*check memory cap down*/
                	cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
                	while(!(cap_ddr_fifostatus_reg.in2_cap_last_wr_flag) && --count){
                   		cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
                    	msleep(1);//no busy delay
                	}

            		if(count == 0)
                		printk(KERN_ERR"M domain sub timeout1 !\n");

            		// [KTASKWBS-5316] wait M-capture write done if capure block index == 0
            		if(MDOMAIN_CAP_DDR_In2Status_get_in2_block_select(IoReg_Read32(MDOMAIN_CAP_DDR_In2Status_reg)) == pre_cap_idx)
            		{
                		count = 40;
                		/*check memory cap down*/
                		cap_ddr_fifostatus_reg.in2_cap_last_wr_flag = 1;
                		IoReg_Write32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg, cap_ddr_fifostatus_reg.regValue);

                		cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
                		while(!(cap_ddr_fifostatus_reg.in2_cap_last_wr_flag) && --count){
                    		cap_ddr_fifostatus_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg);
                    		msleep(1);//no busy delay
                		}

                		if(count == 0)
                    		printk(KERN_ERR"M domain sub timeout2 !\n");
            		}
			wait_frame--;
		}while(wait_frame != 0);
	}
}

void drv_memory_wait_mdom_vi_last_write_done(unsigned char display, unsigned char wait_frame){
	unsigned int count;
	mdomain_vi_main_intst_RBUS vi_intst_reg; //MDOM_VI_INTST_reg

	if(display == SLR_MAIN_DISPLAY){
		do{
			count = 40;

			/*check memory cap down*/
            vi_intst_reg.regValue = rtd_inl(MDOMAIN_VI_MAIN_INTST_reg);
        	while(!(vi_intst_reg.video_in_last_wr_y_flag && vi_intst_reg.video_in_last_wr_c_flag) && --count){
           		vi_intst_reg.regValue = rtd_inl(MDOMAIN_VI_MAIN_INTST_reg);
            	msleep(1);//no busy delay
        	}

			if(count == 0)
        		printk(KERN_ERR"M domain vi main timeout-1 !\n");

    		count = 40;
    		/*check memory cap down*/
    		vi_intst_reg.video_in_last_wr_y_flag = 1;
        	vi_intst_reg.video_in_last_wr_c_flag = 1;
            rtd_outl(MDOMAIN_VI_MAIN_INTST_reg, vi_intst_reg.regValue);

    		vi_intst_reg.regValue = rtd_inl(MDOMAIN_VI_MAIN_INTST_reg);
    		while(!(vi_intst_reg.video_in_last_wr_y_flag && vi_intst_reg.video_in_last_wr_c_flag) && --count){
       		vi_intst_reg.regValue = rtd_inl(MDOMAIN_VI_MAIN_INTST_reg);
        	msleep(1);//no busy delay


        	if(count == 0)
            	printk(KERN_ERR"M domain vi main timeout-2 !\n");
    		}
			wait_frame--;

			//if wait_frame > 0, clear again
			if(wait_frame > 0){
				vi_intst_reg.video_in_last_wr_y_flag = 1;
        		vi_intst_reg.video_in_last_wr_c_flag = 1;
                rtd_outl(MDOMAIN_VI_MAIN_INTST_reg, vi_intst_reg.regValue);
			}
		}while(wait_frame != 0);
	}
	else{
	}
}

//==============Gamd mode==============//
#define GAME_MODE_FRAME_SYNC 0
#define GAME_MODE_NEW_FLL 1

extern unsigned char Get_Factory_SelfDiagnosis_Mode(void);
extern unsigned char get_AVD_Input_Source(void);
void drv_memory_set_game_mode_dynamic(unsigned char enable){
	enable_M_GameMode_Dynamic = enable;
}

unsigned char drv_memory_get_game_mode_dynamic_flag(void){
	return enable_M_GameMode_Dynamic;
}

unsigned char drv_memory_get_game_mode_dynamic(void){
	/*livezoom and magnifier not support single buffer mode*/
	//if((Get_LivezoomOffMainForceBG() == TRUE) || (Get_Live_zoom_mode()!=LIVE_ZOOM_OFF)) {
		//return FALSE;
	//}

	/*livezoom and magnifier not support single buffer mode*/
	//if(Get_Live_zoom_mode()!=LIVE_ZOOM_OFF) {
	//	return FALSE;
	//}

	/*factory self diagnosis grab pixel from third buffer,so not support single buffer mode*/
	if(Get_Factory_SelfDiagnosis_Mode()) {
		return FALSE;
	}

	/*Only support HDMI and Component and av*/
	if(!((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_ADC)
		|| (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
		||((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_AVD)  && (get_AVD_Input_Source() != _SRC_TV))))
		return FALSE;

	return enable_M_GameMode_Dynamic;
}

void drv_memory_set_game_mode(unsigned char enable)
{
	enable_M_GameMode = enable;
}

//only get game mode flag, no need to check input source & conditions.
unsigned char drv_memory_get_game_mode_flag(void)
{
	return enable_M_GameMode;
}

unsigned char drv_memory_get_game_mode(void){
	/*livezoom and magnifier not support single buffer mode*/
	if(/*(Get_LivezoomOffMainForceBG() == TRUE) ||*/ (Get_Live_zoom_mode()!=LIVE_ZOOM_OFF)) {
		return FALSE;
	}

	/*factory self diagnosis grab pixel from third buffer,so not support single buffer mode*/
	if(Get_Factory_SelfDiagnosis_Mode()) {
		return FALSE;
	}
	/*Only support HDMI and Component and AV*/
	if(!((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_ADC)
		|| (Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
		||((Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_AVD)  && (get_AVD_Input_Source() != _SRC_TV))))
		return FALSE;

	return enable_M_GameMode;
}

unsigned char drv_memory_get_game_mode_iv2dv_slow_enable(void){
	/*Always use iv2dv slow tuning flow*/
	if(Get_DISPLAY_PANEL_OLED_TYPE()== TRUE)
		return TRUE;

	return TRUE;
}

void drv_memory_SingleBuffer_GameMode(unsigned char enable){
	mdomain_cap_ddr_in1ctrl_RBUS mdomain_cap_ddr_in1ctrl_Reg;
	mdomain_disp_ddr_mainctrl_RBUS mdomain_disp_ddr_mainctrl_Reg;

	mdomain_cap_ddr_in1ctrl_Reg.regValue = IoReg_Read32(MDOMAIN_CAP_DDR_In1Ctrl_reg);
	mdomain_disp_ddr_mainctrl_Reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
	if(enable == TRUE){
		//change to signal buffer
		//IoReg_ClearBits(MDOMAIN_CAP_DDR_In1Ctrl_reg,  MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask|MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask);
		//IoReg_ClearBits(MDOMAIN_DISP_DDR_MainCtrl_reg,MDOMAIN_DISP_DDR_MainCtrl_main_double_en_mask|MDOMAIN_DISP_DDR_MainCtrl_main_v_flip_3buf_en_mask);
		mdomain_cap_ddr_in1ctrl_Reg.in1_v_flip_3buf_en = 0;
		mdomain_cap_ddr_in1ctrl_Reg.in1_double_enable = 0;
		mdomain_cap_ddr_in1ctrl_Reg.in1_single_buffer_select = 2;

		mdomain_disp_ddr_mainctrl_Reg.main_v_flip_3buf_en = 0;
		mdomain_disp_ddr_mainctrl_Reg.main_double_en = 0;
		mdomain_disp_ddr_mainctrl_Reg.main_single_buffer_select = 2;

	}
	else{
		//triple buffer
		//IoReg_SetBits(MDOMAIN_CAP_DDR_In1Ctrl_reg,  MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask|MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask);
		//IoReg_SetBits(MDOMAIN_DISP_DDR_MainCtrl_reg, MDOMAIN_DISP_DDR_MainCtrl_main_double_en_mask|MDOMAIN_DISP_DDR_MainCtrl_main_v_flip_3buf_en_mask);
		mdomain_cap_ddr_in1ctrl_Reg.in1_v_flip_3buf_en = 1;
		mdomain_cap_ddr_in1ctrl_Reg.in1_double_enable = 1;
		mdomain_cap_ddr_in1ctrl_Reg.in1_single_buffer_select = 0;

		mdomain_disp_ddr_mainctrl_Reg.main_v_flip_3buf_en = 1;
		mdomain_disp_ddr_mainctrl_Reg.main_double_en = 1;
		mdomain_disp_ddr_mainctrl_Reg.main_single_buffer_select = 0;
	}
	IoReg_Write32(MDOMAIN_CAP_DDR_In1Ctrl_reg, mdomain_cap_ddr_in1ctrl_Reg.regValue);
	IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, mdomain_disp_ddr_mainctrl_Reg.regValue);
	pr_debug("[Game Mode]M-domain game mode done enable=%d!!\n",enable);
}

void drv_game_mode_disp_smooth_variable_setting(UINT8 disp_type)
{
	ppoverlay_dispd_stage1_sm_ctrl_RBUS dispd_stage1_sm_ctrl_reg;
	ppoverlay_dispd_smooth_toggle1_RBUS dispd_smooth_toggle1_reg;

	pr_debug("[Game Mode]scaler_disp_smooth_variable_setting\n");
#if 0
	dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
	dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 1;
	IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);

	drivf_scaler_reset_freerun();
	dispd_smooth_toggle1_reg.dispd_stage1_smooth_toggle_apply=1;
	IoReg_Write32(PPOVERLAY_dispd_smooth_toggle1_reg, dispd_smooth_toggle1_reg.regValue);
	//modestate_set_fractional_framesync();
	fw_scaler_dtg_double_buffer_apply();

	dispd_stage1_sm_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dispd_stage1_sm_ctrl_reg);
	dispd_stage1_sm_ctrl_reg.dispd_stage1_smooth_toggle_protect = 0;
	IoReg_Write32(PPOVERLAY_dispd_stage1_sm_ctrl_reg, dispd_stage1_sm_ctrl_reg.regValue);
#endif
	if(disp_type == GAME_MODE_FRAME_SYNC){
		if(Get_DISPLAY_PANEL_OLED_TYPE()==TRUE)
			modestate_set_fll_running_flag(_DISABLE);
		else{
			modestate_set_fll_running_flag(_DISABLE);//Need to disable FLL flag first.
			drvif_scaler_set_display_mode(DISPLAY_MODE_FRAME_SYNC);
		}
	}else{
		modestate_set_fll_running_flag(_ENABLE);
	}

	fw_scaler_dtg_double_buffer_apply();
}

static unsigned int id2dv_delay_target = 0;
extern DEBUG_SCALER_VSC_STRUCT DbgSclrFlgTkr; //extern char run_iv2dv_slow_tuning_flag;//Run iv2dv slow tuning flag

void drv_run_GameMode_iv2dv_slow_tuning(void)
{
	ppoverlay_fs_iv_dv_fine_tuning5_RBUS fs_iv_dv_fine_tuning5_reg;
	ppoverlay_display_timing_ctrl1_RBUS display_timing_ctrl1_reg;
	UINT32 id2dv_delay = 0;
	UINT32 timeout = 10;

	if(id2dv_delay_target > 1){

		display_timing_ctrl1_reg.regValue = IoReg_Read32(PPOVERLAY_Display_Timing_CTRL1_reg);
		if(display_timing_ctrl1_reg.disp_frc_fsync==0){
			pr_notice("[Game Mode]fsync is not ready\n");
			return;
		}

		fs_iv_dv_fine_tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);
		id2dv_delay = fs_iv_dv_fine_tuning5_reg.iv2dv_line;

		if(id2dv_delay == 1)
			id2dv_delay=0;

		if(id2dv_delay < id2dv_delay_target){
			id2dv_delay += 16;
			IoReg_SetBits(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg,_BIT2);
			fs_iv_dv_fine_tuning5_reg.iv2dv_line = id2dv_delay;
			fs_iv_dv_fine_tuning5_reg.iv2dv_line_2 = id2dv_delay;
			IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, fs_iv_dv_fine_tuning5_reg.regValue);
			IoReg_SetBits(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg,_BIT0);
			while((IoReg_Read32(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg)&_BIT0)&&--timeout){
				msleep(10);
			}
			IoReg_ClearBits(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg,_BIT2);
			pr_notice("[Game Mode] iv2dv line = %x\n", IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg));
			return;
		}

	}
	DbgSclrFlgTkr.run_iv2dv_slow_tuning_flag = FALSE;
}

extern int Get_GamemodeSaveI3ddmaGetcurMode(void);
void drv_GameMode_iv2dv_delay(unsigned char enable){
	ppoverlay_fs_iv_dv_fine_tuning5_RBUS fs_iv_dv_fine_tuning5_reg;
	ppoverlay_iv2dv_double_buffer_ctrl_RBUS ppoverlay_iv2dv_double_buffer_ctrl_reg;
	UINT32 id2dv_delay = 0;
	UINT32 timeout;
	unsigned long flags;//for spin_lock_irqsave
	//printk("[pool test]enable:%d,CurMode:%d,modeIdx:%d\n",enable,Scaler_DispGetInputInfo(SLR_INPUT_MODE_CURR),Get_GamemodeSaveI3ddmaGetcurMode());
	//fwif_color_safe_od_enable(0);
	if(enable == _ENABLE){
		//ivdv delay decision
		switch (Get_GamemodeSaveI3ddmaGetcurMode()) {
			case _MODE_480I: //for 720*240 also use this index
				id2dv_delay = 0xc0;
				break;
			case _MODE_640x350_70HZ:			// Mode 00:
			case _MODE_640x350_85HZ:				// Mode 01:
			case _MODE_640x400_56HZ:				// Mode 02:
			case _MODE_640x400_70HZ:				// Mode 03:
			case _MODE_640x400_85HZ:				// Mode 04:
			case _MODE_720x400_50HZ:				// Mode 05:
			case _MODE_720x400_70HZ:				// Mode 06:
			case _MODE_720x400_85HZ:				// Mode 07:
			case _MODE_720x480_60HZ:				// Mode 08:
			case _MODE_640x480_50HZ:				// Mode 09:
			case _MODE_640x480_60HZ:				// Mode 10:
			case _MODE_640x480_67HZ:				// Mode 11:
			case _MODE_640x480_70HZ:				// Mode 12:
			case _MODE_640x480_72HZ:				// Mode 13:
			case _MODE_640x480_75HZ:				// Mode 14:
			case _MODE_640x480_85HZ:				// Mode 15:
			case _MODE_800x600_50HZ:				// Mode 16:
			case _MODE_800x600_56HZ:				// Mode 17:
			case _MODE_800x600_60HZ:				// Mode 18:
			case _MODE_800x600_72HZ:				// Mode 19:
			case _MODE_800x600_75HZ:				// Mode 20:
			case _MODE_800x600_85HZ:				// Mode 21:
			case _MODE_832x624_75HZ:				// Mode 22:
			case _MODE_1024x768_50HZ:				// Mode 23:
			case _MODE_1024x768_60HZ:				// Mode 24:
			case _MODE_1024x768_66HZ:				// Mode 25:
			case _MODE_1024x768_70HZ:				// Mode 26:
			case _MODE_1024x768_75HZ:				// Mode 27:
			case _MODE_1024x768_85HZ:				// Mode 28:
			case _MODE_1152x864_60HZ:				// Mode 29:
			case _MODE_1152x864_75HZ:				// Mode 30:
			case _MODE_1152x870_75HZ:				// Mode 31:
			case _MODE_1152x900_66HZ:				// Mode 32:
			case _MODE_1280x720_50HZ:				// Mode 33:
			case _MODE_1280x720_60HZ:				// Mode 34:
			case _MODE_1280x720_60HZ_RB:			// Mode 35:
			case _MODE_1280x720_85HZ:				// Mode 36:
			case _MODE_VGA_480P:					// Mode 84: RGB 480p
			case _MODE_VGA_576P:					// Mode 85: RGB 576p
			case _MODE_VGA_720P50:					// Mode 86: RGB 720px50Hz
			case _MODE_VGA_720P60:					// Mode 87: RGB 720px60Hz
			case _MODE_480P:
			case _MODE_576I:
			case _MODE_576P:
			case _MODE_720P50:
			case _MODE_720P60:
                     case _MODE_1024x576_60HZ:
				id2dv_delay = 0x100;
				break;
			case _MODE_VGA_1080I25:				// Mode 88: RGB 1080ix50Hz
			case _MODE_VGA_1080I30:				// Mode 89: RGB 1080ix60Hz
			case _MODE_1080I25:// Mode 100: YPbPr 1920x1080ix50HZ (802R)
			case _MODE_1080I30:// Mode 101: YPbPr 1920x1080ix60HZ (802R)
			case _MODE_VGA_480I://for pc 1440*480@60 1440*240p
			case _MODE_VGA_576I://for pc 1440*576i@50 1440*288p
				id2dv_delay = 0x180;
				break;
			case _MODE_1280x768_50HZ:				// Mode 37:
			case _MODE_1280x768_60HZ:				// Mode 38:
			case _MODE_1280x768_60HZ_RB:			// Mode 39:
			case _MODE_1280x768_75HZ:				// Mode 40:
			case _MODE_1280x768_85HZ:				// Mode 41:
			case _MODE_1280x800_60HZ:				// Mode 42:
			case _MODE_1280x800_60HZ_RB:			// Mode 43:
			case _MODE_1280x800_75HZ:				// Mode 44:
			case _MODE_1280x960_50HZ:				// Mode 45:
			case _MODE_1280x960_60HZ:				// Mode 46:
			case _MODE_1280x960_75HZ:				// Mode 47:
			case _MODE_1280x960_85HZ:				// Mode 48:
			case _MODE_1280x1024_50HZ:			// Mode 49:
			case _MODE_1280x1024_60HZ:			// Mode 50:
			case _MODE_1280x1024_60HZ_RB:			// Mode 51:
			case _MODE_1280x1024_72HZ:			// Mode 52:
			case _MODE_1280x1024_75HZ:			// Mode 53:
			case _MODE_1280x1024_85HZ:			// Mode 54:
			case _MODE_1360x768_60HZ:				// Mode 55:
			case _MODE_1360x768_60HZ_RB:		// Mode 56:
			case _MODE_1366x768_60HZ:				// Mode 57:	//VGA1366x768@60
			case _MODE_1400x1050_50HZ:			// Mode 58:
			case _MODE_1400x1050_60RHZ:			// Mode 59:(Reduced Blanking)
			case _MODE_1400x1050_60HZ:			// Mode 60:
			case _MODE_1400x1050_75HZ:			// Mode 61:
			case _MODE_1440x900_60HZ:				// Mode 62:
			case _MODE_1440x900_60RHZ:			// Mode 63:(Reduced Blanking)
			case _MODE_1440x900_75HZ:				// Mode 64:
			case _MODE_1440x900_85HZ:				// Mode 65:
			case _MODE_1600x1200_50HZ:			// Mode 66:
			case _MODE_1600x1200_60HZ:			// Mode 67:
			case _MODE_1600x1200_65HZ:			// Mode 68:
			case _MODE_1600x1200_70HZ:			// Mode 69:
			case _MODE_1600x1200_75HZ:			// Mode 70:
			case _MODE_1600x1200_85HZ:			// Mode 71:
			case _MODE_1680x1050_50HZ:			// Mode 72:
			case _MODE_1680x1050_60HZ:			// Mode 73:
			case _MODE_1680x1050_60RHZ:			// Mode 74:(Reduced Blanking)
			case _MODE_1680x1050_75HZ:			// Mode 75:
			case _MODE_1680x1050_85HZ:			// Mode 76:
			case _MODE_1920x1080_50HZ:			// Mode 77:
			case _MODE_1920x1080_60HZ:			// Mode 78:
			case _MODE_1920x1080_60HZ_138:	// Mode 79:(Reduced Blanking)
			case _MODE_1920x1080_60HZ_148:		// Mode 80:(Reduced Blanking)
			case _MODE_1920x1080_75HZ:			// Mode 81:
			case _MODE_1080P50:
			case _MODE_1080P60:
			case _MODE_1080P23:
			case _MODE_1080P24:
			case _MODE_1080P25:
			case _MODE_1080P29:
			case _MODE_1080P30:
			case _MODE_VGA_1080P50:  				// Mode 90: VGA 1920x1080ix50HZ (802R) //CSW+ 0971001
			case _MODE_VGA_1080P60:	 			// Mode 91: VGA 1920x1080ix60HZ (802R) //CSW+ 0971001
			case _MODE_1920x1080_60Hz_173MAC:
				id2dv_delay = 0x1c0;
				break;
			//for 4k2k
			case _MODE_4k2kP24:
			case _MODE_4k2kP25:
			case _MODE_4k2kP30:
			case _MODE_4k2kP60:
			case _MODE_4k2kP50:
			case _MODE_NEW://for 4096*2160@50
				id2dv_delay = 0x2e0;
				/*if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)>=2160)
					id2dv_delay = 0x2e0;
				else if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)>=768)
					&&(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)<2160))
					id2dv_delay = 0x3c0;
				else if((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)>=600)
					&&(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)<760))
					id2dv_delay = 0x380;
				else if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_IPV_ACT_LEN_PRE)<570)
					id2dv_delay = 0x300;*/
				break;
			default:
				id2dv_delay = 1;//default setting
				break;
		}
	}
	else{
		//iv2dv delay
		id2dv_delay = 1;//default setting
	}

	if (id2dv_delay > Scaler_DispGetInputInfo(SLR_INPUT_V_LEN))
		id2dv_delay = Scaler_DispGetInputInfo(SLR_INPUT_V_LEN) - Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_STA_PRE);

	ppoverlay_iv2dv_double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg);
	ppoverlay_iv2dv_double_buffer_ctrl_reg.iv2dv_db_en = 1;
	IoReg_Write32(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg, ppoverlay_iv2dv_double_buffer_ctrl_reg.regValue);

	if(drv_memory_get_game_mode_iv2dv_slow_enable() == TRUE){

		if(id2dv_delay != 1){
			id2dv_delay_target = id2dv_delay;
			DbgSclrFlgTkr.run_iv2dv_slow_tuning_flag = TRUE;
		}else{
			timeout=10;
			down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
			spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
			IoReg_SetBits(PPOVERLAY_Double_Buffer_CTRL_reg,_BIT2|_BIT0);
			spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
			up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
			drivf_scaler_reset_freerun();
			while((IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg)&_BIT0)&&--timeout){
				msleep(10);
			}
			down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
			spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
			IoReg_ClearBits(PPOVERLAY_Double_Buffer_CTRL_reg,_BIT2);
			spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
			up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
			IoReg_ClearBits(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg,_BIT2);
			id2dv_delay_target = 1;
			DbgSclrFlgTkr.run_iv2dv_slow_tuning_flag = FALSE;

			//iv2dv delay
			fs_iv_dv_fine_tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);
			fs_iv_dv_fine_tuning5_reg.iv2dv_line = id2dv_delay;
			fs_iv_dv_fine_tuning5_reg.iv2dv_line_2 = id2dv_delay;
			rtd_outl(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, fs_iv_dv_fine_tuning5_reg.regValue);
		}
		pr_notice("[Game Mode] iv2dv delay = %x\n", id2dv_delay);
	}else{

		//iv2dv delay
		fs_iv_dv_fine_tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);
		fs_iv_dv_fine_tuning5_reg.iv2dv_line = id2dv_delay;
		fs_iv_dv_fine_tuning5_reg.iv2dv_line_2 = id2dv_delay;
		rtd_outl(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, fs_iv_dv_fine_tuning5_reg.regValue);
		pr_debug("[Game Mode] iv2dv delay = %x\n", id2dv_delay);
	}
	ppoverlay_iv2dv_double_buffer_ctrl_reg.iv2dv_db_apply = 1;
	IoReg_Write32(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg, ppoverlay_iv2dv_double_buffer_ctrl_reg.regValue);
	timeout = 0x3fffff;
	ppoverlay_iv2dv_double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg);
	while((ppoverlay_iv2dv_double_buffer_ctrl_reg.iv2dv_db_apply) && (--timeout)){
		ppoverlay_iv2dv_double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg);
	}
	ppoverlay_iv2dv_double_buffer_ctrl_reg.iv2dv_db_apply = 1;
	IoReg_Write32(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg, ppoverlay_iv2dv_double_buffer_ctrl_reg.regValue);
	timeout = 0x3fffff;
	ppoverlay_iv2dv_double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg);
	while((ppoverlay_iv2dv_double_buffer_ctrl_reg.iv2dv_db_apply) && (--timeout)){
		ppoverlay_iv2dv_double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg);
	}
	ppoverlay_iv2dv_double_buffer_ctrl_reg.iv2dv_db_en = 0;
	IoReg_Write32(PPOVERLAY_iv2dv_Double_Buffer_CTRL_reg, ppoverlay_iv2dv_double_buffer_ctrl_reg.regValue);
	//fwif_color_safe_od_enable(1);

#ifdef CONFIG_I2RND_ENABLE
	ppoverlay_dctl_iv2dv_ihs_ctrl_RBUS ppoverlay_dctl_iv2dv_ihs_ctrl_reg;

	if(Scaler_I2rnd_get_enable()==TRUE){
		ppoverlay_dctl_iv2dv_ihs_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dctl_iv2dv_ihs_ctrl_reg);
		ppoverlay_dctl_iv2dv_ihs_ctrl_reg.iv2dv_ih_slf_width = Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_H_LEN);
		ppoverlay_dctl_iv2dv_ihs_ctrl_reg.iv2dv_ih_slf_gen_en = 1;
		IoReg_Write32(PPOVERLAY_dctl_iv2dv_ihs_ctrl_reg, ppoverlay_dctl_iv2dv_ihs_ctrl_reg.regValue);
	}else{
		ppoverlay_dctl_iv2dv_ihs_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_dctl_iv2dv_ihs_ctrl_reg);
		ppoverlay_dctl_iv2dv_ihs_ctrl_reg.iv2dv_ih_slf_gen_en = 0;
		IoReg_Write32(PPOVERLAY_dctl_iv2dv_ihs_ctrl_reg, ppoverlay_dctl_iv2dv_ihs_ctrl_reg.regValue);
	}
#endif

}


void drv_memory_SingleBuffer_GameMode_Dynamic(unsigned char enable){
	unsigned int timeout = 0x3ffff;
#if 0
	mdomain_cap_cap_reg_doublbuffer_RBUS cap_reg_doublbuffer_reg;
	mdomain_disp_ddr_mainsubctrl_RBUS ddr_mainsubctrl_reg;
//	display_timing_ctrl1_RBUS display_timing_ctrl1_reg;

	scaleup_dm_uzu_ctrl_RBUS dm_uzu_Ctrl_reg;
	scaledown_ich1_uzd_ctrl0_RBUS ich1_uzd_Ctrl0_REG;

	UINT8 cap_db_en = 0;
	UINT8 disp_db_en = 0;
#endif
	mdomain_disp_ddr_mainctrl_RBUS ddr_mainctrl_reg;
	ppoverlay_double_buffer_ctrl_RBUS double_buffer_ctrl_reg;
	UINT8 display_dtg_db_en = 0;
	unsigned long flags;//for spin_lock_irqsave

	/*livezoom and magnifier not support single buffer mode*/
	if(/*(Get_LivezoomOffMainForceBG() == TRUE) || */(Get_Live_zoom_mode()!=LIVE_ZOOM_OFF)) {
		return;
	}

	/*factory self diagnosis grab pixel from third buffer,so not support single buffer mode*/
	if(Get_Factory_SelfDiagnosis_Mode()) {
		return;
	}

	if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_FRAMESYNC)){
		pr_debug("[Game Mode]Data frame sync do not set game mode!!\n");
#ifdef CONFIG_ALL_SOURCE_DATA_FS		
		drvif_framesync_gatting_do();
		drvif_framesync_gatting(_DISABLE);
		drvif_framesync_gatting(_ENABLE);
#endif		
		return;
	}

	ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
	if(vbe_disp_get_adaptivestream_fs_mode() && (ddr_mainctrl_reg.main_source_sel == 0x3)){
		pr_debug("[Game Mode]Adaptive stream & Data frame sync case do not set game mode!!\n");
		return;
	}

	/*transfer board always free run timing*/
	if(Get_DISPLAY_PANEL_TYPE() == P_VBY1_TO_HDMI)
		return;
#if 0
	//enable M-cap double buffer
	cap_reg_doublbuffer_reg.regValue = rtd_inl(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
	cap_db_en = cap_reg_doublbuffer_reg.cap1_db_en;
	cap_reg_doublbuffer_reg.cap1_db_en = 1;
	rtd_outl(MDOMAIN_CAP_cap_reg_doublbuffer_reg,cap_reg_doublbuffer_reg.regValue);

	//enable M-disp double buffer
	ddr_mainsubctrl_reg.regValue = rtd_inl(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
	disp_db_en = ddr_mainsubctrl_reg.disp1_double_enable;
	ddr_mainsubctrl_reg.disp1_double_enable = 1;
	rtd_outl(MDOMAIN_DISP_DDR_MainSubCtrl_reg,ddr_mainsubctrl_reg.regValue);
#endif
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	//enable display double buffer.
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	display_dtg_db_en = double_buffer_ctrl_reg.dreg_dbuf_en;
	double_buffer_ctrl_reg.dreg_dbuf_en = 1;
	rtd_outl(PPOVERLAY_Double_Buffer_CTRL_reg,double_buffer_ctrl_reg.regValue);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//ublock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	if(enable == TRUE){
#if 0
		//UZU color format - compression disable
		dm_uzu_Ctrl_reg.regValue = rtd_inl(SCALEUP_DM_UZU_Ctrl_reg);
		dm_uzu_Ctrl_reg.in_fmt_conv = !(Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC)) && Scaler_DispGetStatus(_MAIN_DISPLAY, SLR_DISP_422CAP);
		rtd_outl(SCALEUP_DM_UZU_Ctrl_reg, dm_uzu_Ctrl_reg.regValue);
		//UZD color format - compression disable
		ich1_uzd_Ctrl0_REG.regValue = IoReg_Read32(SCALEDOWN_ICH1_UZD_Ctrl0_reg);
		ich1_uzd_Ctrl0_REG.sort_fmt = (Scaler_DispGetInputInfo(SLR_INPUT_FRAMESYNC) || (((dvrif_memory_compression_get_enable() == TRUE))||!(Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_422CAP))));
		IoReg_Write32(SCALEDOWN_ICH1_UZD_Ctrl0_reg, ich1_uzd_Ctrl0_REG.regValue);
#endif
		fwif_color_safe_od_enable(0);
		drv_game_mode_disp_smooth_variable_setting(GAME_MODE_FRAME_SYNC);
		drv_GameMode_iv2dv_delay(_ENABLE);
		fwif_color_safe_od_enable(1);
#if 0
		//apply
		double_buffer_ctrl_reg.dreg_dbuf_set = 1;
		rtd_outl(PPOVERLAY_Double_Buffer_CTRL_reg,double_buffer_ctrl_reg.regValue);
		while((double_buffer_ctrl_reg.dreg_dbuf_set == 1) && (timeout--)){
			double_buffer_ctrl_reg.regValue =rtd_inl(PPOVERLAY_Double_Buffer_CTRL_reg);
		}

		timeout = 0x3ffff;

		//first change M-disp.
		IoReg_ClearBits(MDOMAIN_DISP_DDR_MainCtrl_reg, MDOMAIN_DISP_DDR_MainCtrl_main_double_en_mask|MDOMAIN_DISP_DDR_MainCtrl_main_v_flip_3buf_en_mask);
		ddr_mainsubctrl_reg.disp1_double_apply = 1;
		rtd_outl(MDOMAIN_DISP_DDR_MainSubCtrl_reg,ddr_mainsubctrl_reg.regValue);
		while((ddr_mainsubctrl_reg.disp1_double_apply == 1) && (timeout--)){
			ddr_mainsubctrl_reg.regValue =rtd_inl(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		}

		timeout = 0x3ffff;

		//change M-cap
		IoReg_ClearBits(MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask|MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask);
		cap_reg_doublbuffer_reg.cap1_db_apply = 1;
		rtd_outl(MDOMAIN_CAP_cap_reg_doublbuffer_reg,cap_reg_doublbuffer_reg.regValue);
		while((cap_reg_doublbuffer_reg.cap1_db_apply == 1) && (timeout--)){
			cap_reg_doublbuffer_reg.regValue = rtd_inl(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
		}
#endif
		pr_debug("[Game Mode]M-domain game mode enable!!\n");
	}
	else{
#if 0
		//UZU color format - compression enable
		dm_uzu_Ctrl_reg.regValue = rtd_inl(SCALEUP_DM_UZU_Ctrl_reg);
		dm_uzu_Ctrl_reg.in_fmt_conv = 0;
		rtd_outl(SCALEUP_DM_UZU_Ctrl_reg, dm_uzu_Ctrl_reg.regValue);

		//UZD color format - compression enable
		ich1_uzd_Ctrl0_REG.regValue = IoReg_Read32(SCALEDOWN_ICH1_UZD_Ctrl0_reg);
		ich1_uzd_Ctrl0_REG.sort_fmt = 1;
		IoReg_Write32(SCALEDOWN_ICH1_UZD_Ctrl0_reg, ich1_uzd_Ctrl0_REG.regValue);

		//first set M-cap to triple buffer
		IoReg_SetBits(MDOMAIN_CAP_DDR_In1Ctrl_reg, MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask|MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask);
		cap_reg_doublbuffer_reg.cap1_db_apply = 1;
		rtd_outl(MDOMAIN_CAP_cap_reg_doublbuffer_reg,cap_reg_doublbuffer_reg.regValue);
		while((cap_reg_doublbuffer_reg.cap1_db_apply == 1) && (timeout--)){
			cap_reg_doublbuffer_reg.regValue = rtd_inl(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
		}

		msleep(100);//wait M-cap write latest 2 frame.
		timeout = 0x3ffff;

		//change M-disp.
		IoReg_SetBits(MDOMAIN_DISP_DDR_MainCtrl_reg, MDOMAIN_DISP_DDR_MainCtrl_main_double_en_mask|MDOMAIN_DISP_DDR_MainCtrl_main_v_flip_3buf_en_mask);
		ddr_mainsubctrl_reg.disp1_double_apply = 1;
		rtd_outl(MDOMAIN_DISP_DDR_MainSubCtrl_reg,ddr_mainsubctrl_reg.regValue);
		while((ddr_mainsubctrl_reg.disp1_double_apply == 1) && (timeout--)){
			ddr_mainsubctrl_reg.regValue =rtd_inl(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		}
#endif
		if(Get_DISPLAY_PANEL_OLED_TYPE()== TRUE){
			msleep(100);//wait M-cap write latest 2 frame.
		}
		drivf_scaler_reset_freerun();
		drv_GameMode_iv2dv_delay(_DISABLE);
		drv_game_mode_disp_smooth_variable_setting(GAME_MODE_NEW_FLL);

		timeout = 0x3ffff;
		//apply
		down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		double_buffer_ctrl_reg.dreg_dbuf_set = 1;
		rtd_outl(PPOVERLAY_Double_Buffer_CTRL_reg,double_buffer_ctrl_reg.regValue);
		spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
		up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
		while((double_buffer_ctrl_reg.dreg_dbuf_set == 1) && (timeout--)){
			double_buffer_ctrl_reg.regValue =rtd_inl(PPOVERLAY_Double_Buffer_CTRL_reg);
		}
		pr_debug("[Game Mode]M-domain game mode disable!!\n");
	}

	//resume D-domain double buffer setting
	//enable display double buffer.
	down(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
	spin_lock_irqsave(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//lock double buffer spinlock
	double_buffer_ctrl_reg.regValue = IoReg_Read32(PPOVERLAY_Double_Buffer_CTRL_reg);
	double_buffer_ctrl_reg.dreg_dbuf_en = display_dtg_db_en;
	rtd_outl(PPOVERLAY_Double_Buffer_CTRL_reg,double_buffer_ctrl_reg.regValue);
	spin_unlock_irqrestore(get_DBreg_spinlock(SLR_MAIN_DISPLAY), flags);//unlock double buffer spinlock
	up(get_forcebg_semaphore());/*semaphore must added for not effect mute function when setting b8028300*/
#if 0
	//resume M-cap double buffer setting
	cap_reg_doublbuffer_reg.regValue = rtd_inl(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
	if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_SEARCH) {
		cap_reg_doublbuffer_reg.cap1_db_en = 0;
	} else {
		cap_reg_doublbuffer_reg.cap1_db_en = cap_db_en;
	}
	rtd_outl(MDOMAIN_CAP_cap_reg_doublbuffer_reg, cap_reg_doublbuffer_reg.regValue);
	//resume M-disp double buffer setting
	ddr_mainsubctrl_reg.regValue = rtd_inl(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
	ddr_mainsubctrl_reg.disp1_double_enable = disp_db_en;
	rtd_outl(MDOMAIN_DISP_DDR_MainSubCtrl_reg, ddr_mainsubctrl_reg.regValue);
#endif
}

/*======================M-domain Multi-Buffer Controlling=====================*/
static UINT8 Mdomain_multibuffer_enable = false;
static UINT8 Mdomain_multibuffer_number = 0;

void drv_memory_Set_multibuffer_flag(UINT8 enable){
	Mdomain_multibuffer_enable = enable;
}

UINT8 drv_memory_Get_multibuffer_flag(void){
	return Mdomain_multibuffer_enable;
}

void drv_memory_Set_multibuffer_number(UINT8 number){
	Mdomain_multibuffer_number = number;
}

UINT8 drv_memory_Get_multibuffer_number(void){
	return Mdomain_multibuffer_number;
}

void drv_memory_capture_multibuffer_update_addr(unsigned int buffer_size, unsigned int start_addr){
	//update forth buffer
	if(drv_memory_Get_multibuffer_number() > 3){
		//printk(KERN_EMERG"[crixus]buffer_size = %x\n", buffer_size);

		MemTag[MEMIDX_MAIN_FOURTH].StartAddr = drvif_memory_get_data_align(start_addr + buffer_size, (1 << 5));
		//16 bytes alignment
		MemTag[MEMIDX_MAIN_FOURTH].StartAddr = MemTag[MEMIDX_MAIN_FOURTH].StartAddr & 0x7ffffff0;
		MemTag[MEMIDX_MAIN_FOURTH].Allocate_StartAddr = MemTag[MEMIDX_MAIN_FOURTH].StartAddr;
		MemTag[MEMIDX_MAIN_FOURTH].Size = buffer_size;
		MemTag[MEMIDX_MAIN_FOURTH].Status = ALLOCATED_FROM_PLI;
		//update start address
		IoReg_Write32(MDOMAIN_CAP_capm_forth_buf_addr_reg, MemTag[MEMIDX_MAIN_FOURTH].StartAddr);
		IoReg_Write32(MDOMAIN_DISP_main_forth_buf_addr_reg, MemTag[MEMIDX_MAIN_FOURTH].StartAddr);

		printk(KERN_EMERG"[crixus]MemTag[MEMIDX_MAIN_FOURTH].StartAddr = %x\n", MemTag[MEMIDX_MAIN_FOURTH].StartAddr);
	}

	//update fifth buffer
	if(drv_memory_Get_multibuffer_number() > 4){
		MemTag[MEMIDX_MAIN_FIFTH].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_FOURTH].StartAddr + buffer_size, (1 << 5));
		//16 bytes alignment
		MemTag[MEMIDX_MAIN_FIFTH].StartAddr = MemTag[MEMIDX_MAIN_FIFTH].StartAddr & 0x7ffffff0;
		MemTag[MEMIDX_MAIN_FIFTH].Allocate_StartAddr = MemTag[MEMIDX_MAIN_FIFTH].StartAddr;
		MemTag[MEMIDX_MAIN_FIFTH].Size = buffer_size;
		MemTag[MEMIDX_MAIN_FIFTH].Status = ALLOCATED_FROM_PLI;
		//update start address
		IoReg_Write32(MDOMAIN_CAP_capm_fifth_buf_addr_reg, MemTag[MEMIDX_MAIN_FIFTH].StartAddr);
		IoReg_Write32(MDOMAIN_DISP_main_fifth_buf_addr_reg, MemTag[MEMIDX_MAIN_FIFTH].StartAddr);

		printk(KERN_EMERG"[crixus]MemTag[MEMIDX_MAIN_FIFTH].StartAddr = %x\n", MemTag[MEMIDX_MAIN_FIFTH].StartAddr);
	}

	//update sixth buffer
	if(drv_memory_Get_multibuffer_number() > 5){
		MemTag[MEMIDX_MAIN_SIXTH].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_FIFTH].StartAddr + buffer_size, (1 << 5));
		//16 bytes alignment
		MemTag[MEMIDX_MAIN_SIXTH].StartAddr = MemTag[MEMIDX_MAIN_SIXTH].StartAddr & 0x7ffffff0;
		MemTag[MEMIDX_MAIN_SIXTH].Allocate_StartAddr = MemTag[MEMIDX_MAIN_SIXTH].StartAddr;
		MemTag[MEMIDX_MAIN_SIXTH].Size = buffer_size;
		MemTag[MEMIDX_MAIN_SIXTH].Status = ALLOCATED_FROM_PLI;
		//update start address
		IoReg_Write32(MDOMAIN_CAP_capm_sixth_buf_addr_reg, MemTag[MEMIDX_MAIN_SIXTH].StartAddr);
		IoReg_Write32(MDOMAIN_DISP_main_sixth_buf_addr_reg, MemTag[MEMIDX_MAIN_SIXTH].StartAddr);

		printk(KERN_EMERG"[crixus]MemTag[MEMIDX_MAIN_SIXTH].StartAddr = %x\n", MemTag[MEMIDX_MAIN_SIXTH].StartAddr);
	}

	//update seventh buffer
	if(drv_memory_Get_multibuffer_number() > 6){
		MemTag[MEMIDX_MAIN_SEVENTH].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_SIXTH].StartAddr + buffer_size, (1 << 5));
		//16 bytes alignment
		MemTag[MEMIDX_MAIN_SEVENTH].StartAddr = MemTag[MEMIDX_MAIN_SEVENTH].StartAddr & 0x7ffffff0;
		MemTag[MEMIDX_MAIN_SEVENTH].Allocate_StartAddr = MemTag[MEMIDX_MAIN_SEVENTH].StartAddr;
		MemTag[MEMIDX_MAIN_SEVENTH].Size = buffer_size;
		MemTag[MEMIDX_MAIN_SEVENTH].Status = ALLOCATED_FROM_PLI;
		//update start address
		IoReg_Write32(MDOMAIN_CAP_capm_seventh_buf_addr_reg, MemTag[MEMIDX_MAIN_SEVENTH].StartAddr);
		IoReg_Write32(MDOMAIN_DISP_main_seventh_buf_addr_reg, MemTag[MEMIDX_MAIN_SEVENTH].StartAddr);

		printk(KERN_EMERG"[crixus]MemTag[MEMIDX_MAIN_SEVENTH].StartAddr = %x\n", MemTag[MEMIDX_MAIN_SEVENTH].StartAddr);
	}

	//update eighth buffer
	if(drv_memory_Get_multibuffer_number() > 7){
		MemTag[MEMIDX_MAIN_EIGHTH].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_SEVENTH].StartAddr + buffer_size, (1 << 5));
		//16 bytes alignment
		MemTag[MEMIDX_MAIN_EIGHTH].StartAddr = MemTag[MEMIDX_MAIN_EIGHTH].StartAddr & 0x7ffffff0;
		MemTag[MEMIDX_MAIN_EIGHTH].Allocate_StartAddr = MemTag[MEMIDX_MAIN_EIGHTH].StartAddr;
		MemTag[MEMIDX_MAIN_EIGHTH].Size = buffer_size;
		MemTag[MEMIDX_MAIN_EIGHTH].Status = ALLOCATED_FROM_PLI;
		//update start address
		IoReg_Write32(MDOMAIN_CAP_capm_eightth_buf_addr_reg, MemTag[MEMIDX_MAIN_EIGHTH].StartAddr);
		IoReg_Write32(MDOMAIN_DISP_main_eightth_buf_addr_reg, MemTag[MEMIDX_MAIN_EIGHTH].StartAddr);

		printk(KERN_EMERG"[crixus]MemTag[MEMIDX_MAIN_EIGHTH].StartAddr = %x\n", MemTag[MEMIDX_MAIN_EIGHTH].StartAddr);
	}
}

void drv_memory_capture_multibuffer_update_boundary(unsigned char buf_num, unsigned int buffer_size){
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,(MemTag[MEMIDX_MAIN_THIRD].StartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,(MemTag[MEMIDX_MAIN + (buf_num - 1)].StartAddr+buffer_size-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
}

void drv_memory_capture_multibuffer_control(unsigned char buf_num, unsigned char disp2cap_distance){
	mdomain_cap_ddr_in1ctrl_RBUS ddr_in1ctrl_reg;
	mdomain_cap_ddr_in2ctrl_RBUS ddr_in2ctrl_reg;

	//printk(KERN_EMERG"[crixus]buf_num = %x\n", buf_num);
	//printk(KERN_EMERG"[crixus]disp2cap_distance = %x\n", disp2cap_distance);

	if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY){
		ddr_in1ctrl_reg.regValue = IoReg_Read32(MDOMAIN_CAP_DDR_In1Ctrl_reg);
		ddr_in1ctrl_reg.in1_bufnum = buf_num - 1;
		ddr_in1ctrl_reg.in1_disp2cap_distance = disp2cap_distance; //if FRC style is faster mode, HW will use this distance
		IoReg_Write32(MDOMAIN_CAP_DDR_In1Ctrl_reg, ddr_in1ctrl_reg.regValue);
	}
	else if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY){
		ddr_in2ctrl_reg.regValue = IoReg_Read32(MDOMAIN_CAP_DDR_In2Ctrl_reg);
		ddr_in2ctrl_reg.in2_bufnum = buf_num - 1;
		ddr_in2ctrl_reg.in2_disp2cap_distance = disp2cap_distance; //if FRC style is faster mode, HW will use this distance
		IoReg_Write32(MDOMAIN_CAP_DDR_In2Ctrl_reg, ddr_in2ctrl_reg.regValue);

	}
}

void drv_memory_capture_multibuffer_address(unsigned int buf4_addr, unsigned int buf5_addr,unsigned int buf6_addr,unsigned int buf7_addr,unsigned int buf8_addr){
	if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY){
		IoReg_Write32(MDOMAIN_CAP_capm_forth_buf_addr_reg, buf4_addr);
		IoReg_Write32(MDOMAIN_CAP_capm_fifth_buf_addr_reg, buf5_addr);
		IoReg_Write32(MDOMAIN_CAP_capm_sixth_buf_addr_reg, buf6_addr);
		IoReg_Write32(MDOMAIN_CAP_capm_seventh_buf_addr_reg, buf7_addr);
		IoReg_Write32(MDOMAIN_CAP_capm_eightth_buf_addr_reg, buf8_addr);
	}
	else if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY){
		IoReg_Write32(MDOMAIN_CAP_caps_forth_buf_addr_reg, buf4_addr);
		IoReg_Write32(MDOMAIN_CAP_caps_fifth_buf_addr_reg, buf5_addr);
		IoReg_Write32(MDOMAIN_CAP_caps_sixth_buf_addr_reg, buf6_addr);
		IoReg_Write32(MDOMAIN_CAP_caps_seventh_buf_addr_reg, buf7_addr);
		IoReg_Write32(MDOMAIN_CAP_caps_eightth_buf_addr_reg, buf8_addr);
	}
}

void drv_memory_display_multibuffer_control(unsigned char buf_num, unsigned char cap2disp_distance){
	mdomain_disp_ddr_mainctrl_RBUS mdomain_disp_ddr_mainctrl_reg;
	mdomain_disp_ddr_subctrl_RBUS mdomain_disp_ddr_subctrl_reg;

	if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY){
		mdomain_disp_ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
		mdomain_disp_ddr_mainctrl_reg.main_bufnum= buf_num - 1;
		mdomain_disp_ddr_mainctrl_reg.main_cap2disp_distance = cap2disp_distance; //if FRC style is slow mode, HW will use this distance
		IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg, mdomain_disp_ddr_mainctrl_reg.regValue);
	}
	else if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY){
		mdomain_disp_ddr_subctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_SubCtrl_reg);
		mdomain_disp_ddr_subctrl_reg.sub_bufnum= buf_num - 1;
		mdomain_disp_ddr_subctrl_reg.sub_cap2disp_distance = cap2disp_distance; //if FRC style is slow mode, HW will use this distance
		IoReg_Write32(MDOMAIN_DISP_DDR_SubCtrl_reg, mdomain_disp_ddr_subctrl_reg.regValue);

	}

}

void drv_memory_display_multibuffer_address(unsigned int buf4_addr, unsigned int buf5_addr,unsigned int buf6_addr,unsigned int buf7_addr,unsigned int buf8_addr){
	if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_MAIN_DISPLAY){
		IoReg_Write32(MDOMAIN_DISP_main_forth_buf_addr_reg, buf4_addr);
		IoReg_Write32(MDOMAIN_DISP_main_fifth_buf_addr_reg, buf5_addr);
		IoReg_Write32(MDOMAIN_DISP_main_sixth_buf_addr_reg, buf6_addr);
		IoReg_Write32(MDOMAIN_DISP_main_seventh_buf_addr_reg, buf7_addr);
		IoReg_Write32(MDOMAIN_DISP_main_eightth_buf_addr_reg, buf8_addr);
	}
	else if(Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY) == SLR_SUB_DISPLAY){
		IoReg_Write32(MDOMAIN_DISP_sub_forth_buf_addr_reg, buf4_addr);
		IoReg_Write32(MDOMAIN_DISP_sub_fifth_buf_addr_reg, buf5_addr);
		IoReg_Write32(MDOMAIN_DISP_sub_sixth_buf_addr_reg, buf6_addr);
		IoReg_Write32(MDOMAIN_DISP_sub_seventh_buf_addr_reg, buf7_addr);
		IoReg_Write32(MDOMAIN_DISP_sub_eightth_buf_addr_reg, buf8_addr);
	}
}

void drv_memory_display_set_input_fast(void){
	mdomain_disp_ddr_mainctrl_RBUS mdomain_disp_ddr_mainctrl_reg;
	mdomain_disp_ddr_mainsubctrl_RBUS mdomain_disp_ddr_mainsubctrl_reg;

	mdomain_disp_ddr_mainctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainCtrl_reg);
	mdomain_disp_ddr_mainctrl_reg.main_frc_style = 1;
	IoReg_Write32(MDOMAIN_DISP_DDR_MainCtrl_reg,  mdomain_disp_ddr_mainctrl_reg.regValue);

	mdomain_disp_ddr_mainsubctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
	mdomain_disp_ddr_mainsubctrl_reg.disp1_double_apply = 1;
	IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg,  mdomain_disp_ddr_mainsubctrl_reg.regValue);

	//wait apply
	//while(mdomain_disp_ddr_mainsubctrl_reg.disp1_double_apply && cnt){
	//	mdomain_disp_ddr_mainsubctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
	//}

}

/*======================M-domain I2RND M-cap2 Controlling=====================*/
static void memory_set_capture_i2rnd_sdisp(unsigned char cap_type)
{
	unsigned int TotalSize;
	unsigned int Quotient;
	unsigned char Remainder;
	unsigned int fifoLen = _FIFOLENGTH2;
	unsigned int burstLen = _BURSTLENGTH2;
	unsigned int MemShiftAddr = 0;
	unsigned short droppixel = 0;
	unsigned int display = SLR_SUB_DISPLAY;
	unsigned int subctrltemp = 0;
	//mdomain_disp_display_byte_channel_swap_RBUS display_byte_channel_swap_reg;
	mdomain_cap_capture_byte_swap_RBUS capture_byte_swap_reg;
#if 0
	printk(KERN_EMERG"SLR_INPUT_CHANNEL = %d\n", Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL));
	printk(KERN_EMERG"IPV_ACT_LEN = 0x%x, IPH_ACT_WID = 0x%x\n", Scaler_DispGetInputInfo(SLR_INPUT_IPV_ACT_LEN), Scaler_DispGetInputInfo(SLR_INPUT_IPH_ACT_WID));
	printk(KERN_EMERG"SLR_INPUT_DI_WID = 0x%x(%d)\n",Scaler_DispGetInputInfo(SLR_INPUT_DI_WID),Scaler_DispGetInputInfo(SLR_INPUT_DI_WID));
	printk(KERN_EMERG"SLR_INPUT_CAP_LEN = 0x%x, SLR_INPUT_CAP_WID = 0x%x\n", Scaler_DispGetInputInfo(SLR_INPUT_CAP_LEN), Scaler_DispGetInputInfo(SLR_INPUT_CAP_WID));
	printk(KERN_EMERG"MEM_ACT_LEN = 0x%x, MEM_ACT_WID = 0x%x\n", Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_LEN), Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_WID));
	printk(KERN_EMERG"SLR_INPUT_MEM_ACT_VSTA = %d, SLR_INPUT_MEM_ACT_HSTA = %d\n", Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_VSTA), Scaler_DispGetInputInfo(SLR_INPUT_MEM_ACT_HSTA));
	printk(KERN_EMERG"SLR_INPUT_DISP_LEN = 0x%x, SLR_INPUT_DISP_WID = 0x%x\n", Scaler_DispGetInputInfo(SLR_INPUT_DISP_LEN), Scaler_DispGetInputInfo(SLR_INPUT_DISP_WID));
	printk(KERN_EMERG"SLR_INPUT_V_FREQ = 0x%x\n", Scaler_DispGetInputInfo(SLR_INPUT_V_FREQ));
#endif
	MemGetBlockShiftAddr(SLR_MAIN_DISPLAY, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MEM_ACT_HSTA),Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MEM_ACT_VSTA), &MemShiftAddr, &droppixel);


	//FIXME test
	TotalSize = memory_get_disp_line_size1(SLR_MAIN_DISPLAY, Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MEM_ACT_WID) + droppixel);	// calculate the memory size of capture
	IoReg_Mask32(MDOMAIN_DISP_DDR_SubPixNumWTL_reg, 0xffc00000, (( ((Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_MEM_ACT_WID) +droppixel) & 0x3FFF) << 8) | ((fifoLen - (burstLen>>1))>>1)));
	// Do a division
	memory_division(TotalSize, burstLen, &Quotient, &Remainder);
	// remainder is not allowed to be zero
	if (Remainder == 0) {
		Remainder = burstLen;
		Quotient -= 1;
	}

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubRdNumLenRem_reg, 0x00000000, (Quotient << 16) | (burstLen << 8) | Remainder);

	TotalSize = memory_get_capture_size(SLR_MAIN_DISPLAY, MEMCAPTYPE_LINE);
	IoReg_Write32(MDOMAIN_DISP_DDR_SubLineStep_reg,  (TotalSize + TotalSize%2) << 3);//bit 3 need to be 0. rbus rule
	TotalSize = SHL(TotalSize, 3); // unit conversion from 64bits to 8bits

	IoReg_Mask32(MDOMAIN_DISP_DDR_SubLineNum_reg, 0xfffff000, (Scaler_DispGetInputInfoByDisp(display, SLR_INPUT_MEM_ACT_LEN) & 0x0FFF));
	IoReg_Write32(MDOMAIN_DISP_DDR_SubAddr_reg, (MemTag[MEMIDX_MAIN_2].StartAddr + MemShiftAddr)&0x7ffffff0);
	IoReg_Write32(MDOMAIN_DISP_DDR_Sub2ndAddr_reg, (MemTag[MEMIDX_MAIN_2_SEC].StartAddr + MemShiftAddr)&0x7ffffff0);

	//MemSetDisplayAddr(SLR_SUB_DISPLAY, drvif_memory_get_block_addr(MEMIDX_MAIN_2) + MemShiftAddr, drvif_memory_get_block_addr(MEMIDX_MAIN_2_SEC) + MemShiftAddr);
#ifdef ENABLE_3_BUFFER_DELAY_MODE
	IoReg_Write32(MDOMAIN_DISP_DDR_Sub3rdAddr_reg, (MemTag[MEMIDX_MAIN_2_THIRD].StartAddr + MemShiftAddr)&0x7ffffff0);
#endif

	IoReg_Write32(MDOMAIN_DISP_DDR_SubAddrDropBits_reg,droppixel);

	subctrltemp = _BIT6;
#ifdef ENABLE_3_BUFFER_DELAY_MODE
	subctrltemp |=_BIT7 | _BIT25 | _BIT28;//set Mdomain display triple buffer
#endif
	subctrltemp |= Scaler_DispGetStatus(SLR_SUB_DISPLAY, SLR_DISP_422CAP) ? 0 : _BIT17;
	subctrltemp |= (_BIT19);
	IoReg_Write32(MDOMAIN_DISP_DDR_SubCtrl_reg, subctrltemp);
#if 0
	//S-disp byte swap
	display_byte_channel_swap_reg.regValue = IoReg_Read32(MDOMAIN_DISP_Display_byte_channel_swap_reg);
	display_byte_channel_swap_reg.sub_1byte_swap = 0;
	display_byte_channel_swap_reg.sub_2byte_swap = 0;
	display_byte_channel_swap_reg.sub_4byte_swap = 0;
	display_byte_channel_swap_reg.sub_8byte_swap = 1;
	IoReg_Write32(MDOMAIN_DISP_Display_byte_channel_swap_reg, display_byte_channel_swap_reg.regValue);
#endif

	//sub-cap byte swap
	capture_byte_swap_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Capture_byte_swap_reg);
	capture_byte_swap_reg.in2_1byte_swap = 0;
	capture_byte_swap_reg.in2_2byte_swap = 0;
	capture_byte_swap_reg.in2_4byte_swap = 0;
	capture_byte_swap_reg.in2_8byte_swap = 1;
	IoReg_Write32(MDOMAIN_CAP_Capture_byte_swap_reg, capture_byte_swap_reg.regValue);

	drvif_memory_set_dbuffer_write();
}
extern void magnifier_color_ultrazoom_config_scaling_up(unsigned char display);
void mdomain_handler_i2rnd_mcap_apvr(void)
{
	dvrif_memory_compression_set_enable(SLR_MAIN_DISPLAY, FALSE);
	memory_set_capture(TRUE, MEMCAPTYPE_FRAME);
	//disable compression & de-compression
	IoReg_ClearBits(MDOMAIN_CAP_main_comp_setting_reg, _BIT20);
#ifdef CONFIG_I2RND_ENABLE
	mdomain_cap_capture_byte_swap_RBUS capture_byte_swap_reg;
	Scaler_I2rnd_set_display(I2RND_MAIN_S0_TABLE);
	capture_byte_swap_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Capture_byte_swap_reg);
	capture_byte_swap_reg.in2_1byte_swap = 0;
	capture_byte_swap_reg.in2_2byte_swap = 0;
	capture_byte_swap_reg.in2_4byte_swap = 0;
	capture_byte_swap_reg.in2_8byte_swap = 1;
	IoReg_Write32(MDOMAIN_CAP_Capture_byte_swap_reg, capture_byte_swap_reg.regValue);
	Scaler_I2rnd_set_display(I2RND_SUB_S1_TABLE);
	capture_byte_swap_reg.regValue = IoReg_Read32(MDOMAIN_CAP_Capture_byte_swap_reg);
	capture_byte_swap_reg.in2_1byte_swap = 0;
	capture_byte_swap_reg.in2_2byte_swap = 0;
	capture_byte_swap_reg.in2_4byte_swap = 0;
	capture_byte_swap_reg.in2_8byte_swap = 1;
	IoReg_Write32(MDOMAIN_CAP_Capture_byte_swap_reg, capture_byte_swap_reg.regValue);
#endif

	printk(KERN_EMERG"#################[%s][%d]Done!!@@@@@@@@@@@@@@@@@\n", __FUNCTION__, __LINE__);
}

void mdomain_handler_i2rnd_mcap_sdisp(void)
{
	//M-cap to S-disp only support line mode
	memory_set_capture(TRUE, MEMCAPTYPE_LINE);
	//set sub disp
	memory_set_capture_i2rnd_sdisp(MEMCAPTYPE_LINE);
	printk(KERN_EMERG"[I2RND]#################[%s][%d]Done!!@@@@@@@@@@@@@@@@@\n", __FUNCTION__, __LINE__);
}

void i2rnd_default_allocate_mcap1(void){
	unsigned int buffer_size = MDOMAIN_MULTIVIEW_BUFFER_SIZE;
	//unsigned int  nStartAddr = 0;

	//allocate memory for M-cap2
	//Just for reserved memory 88M testing FIX ME
	MemTag[MEMIDX_MAIN_THIRD].StartAddr = get_query_start_address(QUERY_IDX_MDOMAIN_MAIN);//MDOMAIN_START_ADDRESS_KERNEL;
	MemTag[MEMIDX_MAIN_SEC].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_THIRD].StartAddr+buffer_size, (1 << 5));
	MemTag[MEMIDX_MAIN].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_SEC].StartAddr+buffer_size, (1 << 5));

	//16 bytes alignment
	MemTag[MEMIDX_MAIN_THIRD].StartAddr = MemTag[MEMIDX_MAIN_THIRD].StartAddr & 0x7ffffff0;
	MemTag[MEMIDX_MAIN_SEC].StartAddr = MemTag[MEMIDX_MAIN_SEC].StartAddr & 0x7ffffff0;
	MemTag[MEMIDX_MAIN].StartAddr = MemTag[MEMIDX_MAIN].StartAddr & 0x7ffffff0;

	//free virtual memory
	drvif_memory_free_fixed_virtual_memory();
	//set virtual memory size
	buffer_size = PAGE_ALIGN(buffer_size);
	drvif_memory_set_fixed_virtual_memory_size(buffer_size);

	MemTag[MEMIDX_MAIN_THIRD].Allocate_StartAddr = MemTag[MEMIDX_MAIN_THIRD].StartAddr;
	MemTag[MEMIDX_MAIN_THIRD].Size = buffer_size;
	MemTag[MEMIDX_MAIN_THIRD].Status = ALLOCATED_FROM_PLI;

	MemTag[MEMIDX_MAIN_SEC].Allocate_StartAddr = MemTag[MEMIDX_MAIN_SEC].StartAddr;
	MemTag[MEMIDX_MAIN_SEC].Size = buffer_size;
	MemTag[MEMIDX_MAIN_SEC].Status = ALLOCATED_FROM_PLI;
	MemTag[MEMIDX_MAIN_SEC].Allocate_VirAddr = 0;//not use

	MemTag[MEMIDX_MAIN].Allocate_StartAddr = MemTag[MEMIDX_MAIN].StartAddr;
	MemTag[MEMIDX_MAIN].Size = buffer_size;
	MemTag[MEMIDX_MAIN].Status = ALLOCATED_FROM_PLI;
	MemTag[MEMIDX_MAIN].Allocate_VirAddr = 0;//not use

	//virtual memory allocation	and just use one buffer
	drvif_memory_set_memtag_virtual_startaddr((unsigned int)dvr_remap_uncached_memory(drvif_memory_get_memtag_startaddr(MEMIDX_MAIN_THIRD), buffer_size, __builtin_return_address(0)));

	//M-domain start address
	IoReg_Write32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg, (MemTag[MEMIDX_MAIN_THIRD].StartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg, (MemTag[MEMIDX_MAIN_SEC].StartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_DDR_In1Addr_reg, (MemTag[MEMIDX_MAIN].StartAddr & 0x7ffffff0));
	//M-domain boundary
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,(MemTag[MEMIDX_MAIN_THIRD].StartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,(MemTag[MEMIDX_MAIN].StartAddr+buffer_size-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
}

void i2rnd_default_allocate_mcap2(void){
	unsigned int buffer_size = MDOMAIN_MULTIVIEW_BUFFER_SIZE;
	unsigned int  nStartAddr = 0;
#if 0
	//allocate memory for M-cap2
	nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_2_THIRD, buffer_size, MEMALIGN_ANY);//space unit is byte
	MemTag[MEMIDX_MAIN_2_THIRD].StartAddr = nStartAddr;
	nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_2_SEC, buffer_size, MEMALIGN_ANY);//space unit is byte
	MemTag[MEMIDX_MAIN_2_SEC].StartAddr = nStartAddr;
	nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_2, buffer_size, MEMALIGN_ANY);//space unit is byte
	MemTag[MEMIDX_MAIN_2].StartAddr = nStartAddr;
#else
	MemTag[MEMIDX_MAIN_2_THIRD].StartAddr = get_query_start_address(QUERY_IDX_MDOMAIN_MAIN) + MDOMAIN_SUB_BUFFER_SIZE * 3;
	MemTag[MEMIDX_MAIN_2_SEC].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_2_THIRD].StartAddr+buffer_size, (1 << 5));
	MemTag[MEMIDX_MAIN_2].StartAddr = drvif_memory_get_data_align(MemTag[MEMIDX_MAIN_2_SEC].StartAddr+buffer_size, (1 << 5));
#endif
	//M-domain start address
	IoReg_Write32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg, (MemTag[MEMIDX_MAIN_2_THIRD].StartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg, (MemTag[MEMIDX_MAIN_2_SEC].StartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_DDR_In1Addr_reg, (MemTag[MEMIDX_MAIN_2].StartAddr & 0x7ffffff0));
	//M-domain boundary
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg,(MemTag[MEMIDX_MAIN_2_THIRD].StartAddr & 0x7ffffff0));
	IoReg_Write32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg,(MemTag[MEMIDX_MAIN_2].StartAddr+buffer_size-CONFIG_MDOMAIN_BURST_SIZE) & 0x7ffffff0);
}

void i2rnd_default_allocate_DI1(void){
	unsigned int default_buffer_size = 0x280000;
	unsigned int default_info_size = 0x200000;
	unsigned int di_address = 0;

	di_address = drv_memory_get_VIP_query_start_address(VIP_QUERY_IDX_DI);

	//start address setting
	IoReg_Write32(DI_DI_DATMemoryStartAdd1_reg, (di_address & 0x7ffffff0));
	IoReg_Write32(DI_DI_DATMemoryStartAdd2_reg, ((di_address + default_buffer_size) & 0x7ffffff0));
	IoReg_Write32(DI_DI_DATMemoryStartAdd3_reg, ((di_address + default_buffer_size * 2) & 0x7ffffff0));
	IoReg_Write32(DI_DI_DATMemoryStartAdd4_reg, ((di_address + default_buffer_size * 3) & 0x7ffffff0));
	IoReg_Write32(DI_DI_INFMemoryStartAdd1_reg, ((di_address + default_buffer_size * 4) & 0x7ffffff0));
	IoReg_Write32(DI_DI_INFMemoryStartAdd2_reg, ((di_address + default_buffer_size * 4 + default_info_size) & 0x7ffffff0));

	//boundary setting
	//IoReg_Write32(DI_DI1_WRRD_BoundaryAddr1_reg, (di_address & 0x7ffffff0));	/* set boudary in boot ini and resume*/
	//IoReg_Write32(DI_DI1_WRRD_BoundaryAddr2_reg, ((di_address + default_buffer_size * 4 + default_info_size * 2) & 0x7ffffff0));
}

void i2rnd_default_allocate_DI2(void){
	unsigned int default_buffer_size = 0x280000;
	unsigned int default_info_size = 0x200000;
	unsigned int di_address = 0;

	//DI 2 size need to add DI 1 size
	di_address = drv_memory_get_VIP_query_start_address(VIP_QUERY_IDX_DI_2);

	//start address setting
	IoReg_Write32(DI_DI_I2R_DATMemoryStartAdd1_reg, (di_address & 0x7ffffff0));
	IoReg_Write32(DI_DI_I2R_DATMemoryStartAdd2_reg, ((di_address + default_buffer_size) & 0x7ffffff0));
	IoReg_Write32(DI_DI_I2R_DATMemoryStartAdd3_reg, ((di_address + default_buffer_size * 2) & 0x7ffffff0));
	IoReg_Write32(DI_DI_I2R_DATMemoryStartAdd4_reg, ((di_address + default_buffer_size * 3) & 0x7ffffff0));
	IoReg_Write32(DI_DI_I2R_INFMemoryStartAdd1_reg, ((di_address + default_buffer_size * 4) & 0x7ffffff0));
	IoReg_Write32(DI_DI_I2R_INFMemoryStartAdd2_reg, ((di_address + default_buffer_size * 4 + default_info_size) & 0x7ffffff0));

	//boundary setting
	//IoReg_Write32(DI_DI1_WRRD_BoundaryAddr1_reg, (di_address & 0x7ffffff0));	/* set boudary in boot ini and resume*/
	//IoReg_Write32(DI_DI1_WRRD_BoundaryAddr2_reg, ((di_address + default_buffer_size * 4 + default_info_size * 2) & 0x7ffffff0));

}

void i2rnd_get_mcap2_address(unsigned int *addr1, unsigned int *addr2, unsigned int *addr3)
{

	*addr1 = MemTag[MEMIDX_MAIN_2].StartAddr;
	*addr2 = MemTag[MEMIDX_MAIN_2_SEC].StartAddr;
	*addr3 = MemTag[MEMIDX_MAIN_2_THIRD].StartAddr;

}

void Scaler_memory_setting_through_CMA(void)
{
	unsigned int buffer_size = 0;
	unsigned int nStartAddr = 0;
	if (drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD) == _DUMMYADDR) {
		mdomain_cap_cap_reg_doublbuffer_RBUS cap_reg_doublbuffer_reg;
		mdomain_disp_ddr_mainsubctrl_RBUS ddr_mainsubctrl_reg;
		unsigned int timeout = 0x3ffff;
		if(dvrif_memory_compression_get_enable(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL))==_ENABLE) {
			buffer_size = MDOMAIN_MAIN_BUFFER_SIZE_10BITS;
		} else if(TRUE == Get_rotate_function()) {
			buffer_size = MDOMAIN_MAIN_BUFFER_SIZE_24BITS;
		} else {
			buffer_size = MDOMAIN_MAIN_BUFFER_SIZE_16BITS;
		}
		//thrid memory
		nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_THIRD, buffer_size, MEMALIGN_ANY);
		MemTag[MEMIDX_MAIN_THIRD].StartAddr = nStartAddr;
		IoReg_Write32(MDOMAIN_CAP_DDR_In1_3rdAddr_reg, nStartAddr & 0x7ffffff0);
		
		//second memory
		nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN_SEC, buffer_size, MEMALIGN_ANY);
		MemTag[MEMIDX_MAIN_SEC].StartAddr = nStartAddr;
		IoReg_Write32(MDOMAIN_CAP_DDR_In1_2ndAddr_reg, nStartAddr & 0x7ffffff0);
		
		//first memory
		nStartAddr = drvif_memory_alloc_block(MEMIDX_MAIN, buffer_size, MEMALIGN_ANY);
		MemTag[MEMIDX_MAIN].StartAddr = nStartAddr;
		IoReg_Write32(MDOMAIN_CAP_DDR_In1Addr_reg, nStartAddr & 0x7ffffff0);
		
		//apply M-cap double buffer
		cap_reg_doublbuffer_reg.regValue = IoReg_Read32(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
		cap_reg_doublbuffer_reg.cap1_db_apply = 1;
		IoReg_Write32(MDOMAIN_CAP_cap_reg_doublbuffer_reg,cap_reg_doublbuffer_reg.regValue);		
		while(timeout) {
			cap_reg_doublbuffer_reg.regValue = IoReg_Read32(MDOMAIN_CAP_cap_reg_doublbuffer_reg);
			if ((cap_reg_doublbuffer_reg.cap1_db_en == 0) || (cap_reg_doublbuffer_reg.cap1_db_apply==0)) {
				break;
			}
			timeout--;
		}
		timeout = 0x3ffff;
		nStartAddr = drvif_memory_get_block_addr(MEMIDX_MAIN_THIRD);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main3rdAddr_reg, nStartAddr&0x7ffffff0);
		nStartAddr = drvif_memory_get_block_addr(MEMIDX_MAIN_SEC);
		IoReg_Write32(MDOMAIN_DISP_DDR_Main2ndAddr_reg, nStartAddr&0x7ffffff0);
		nStartAddr = drvif_memory_get_block_addr(MEMIDX_MAIN);
		IoReg_Write32(MDOMAIN_DISP_DDR_MainAddr_reg, nStartAddr&0x7ffffff0);
		nStartAddr = IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr1_reg);
		IoReg_Write32(MDOMAIN_DISP_DispMain_BoundaryAddr1_reg, nStartAddr&0x7ffffff0);
		nStartAddr = IoReg_Read32(MDOMAIN_CAP_CapMain_BoundaryAddr2_reg);
		IoReg_Write32(MDOMAIN_DISP_DispMain_BoundaryAddr2_reg, nStartAddr&0x7ffffff0);
		//apply M-dis double buffer
		ddr_mainsubctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
		ddr_mainsubctrl_reg.disp1_double_apply = 1;
		IoReg_Write32(MDOMAIN_DISP_DDR_MainSubCtrl_reg,ddr_mainsubctrl_reg.regValue);
		while(timeout) {
			ddr_mainsubctrl_reg.regValue = IoReg_Read32(MDOMAIN_DISP_DDR_MainSubCtrl_reg);
			if ((ddr_mainsubctrl_reg.disp1_double_enable== 0) || (ddr_mainsubctrl_reg.disp1_double_apply==0)) {
				break;
			}
			timeout--;
		}
	}
}
/*======================== End of File =======================================*/
/**
 *
 * @}
 */

