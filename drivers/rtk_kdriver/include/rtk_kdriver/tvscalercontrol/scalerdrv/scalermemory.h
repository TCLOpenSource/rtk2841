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

#ifndef _SCALER_MEMORY_H_
#define _SCALER_MEMORY_H_

/*============================ Module dependency  ===========================*/

//#include "rtd_types.h"

#define CONFIG_DDR_COL_BITS 9
#define CONFIG_DDR_BANK_BITS 2
#define CONFIG_DDR_ROW_BITS 12
#define CONFIG_DDR_DATA_BITS 16
#define CONFIG_MDOMAIN_BURST_SIZE 512
/*===================================  Types ================================*/
// DDR resources, Arbiter customers
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;

typedef enum {
	MEM_CH2_WR = 0,
	MEM_CH1_WR,
	MEM_SUB_RD,
	MEM_MAIN_RD,
	MEM_OSDY_RD,
	MEM_OSDX_RD,
	MEM_MCU_RW,
	MEM_DI_RD4,
	MEM_DI_RD3,
	MEM_DI_RD2,
	MEM_DI_RD1,
	MEM_DI_WR,
}eMemResource;

// Memory Index
typedef enum {
	MEMIDX_VDC=0x0,
	MEMIDX_TT,
	MEMIDX_JPEG,
	MEMIDX_DI,
	MEMIDX_MAIN,
	MEMIDX_MAIN_SEC,
	MEMIDX_MAIN_THIRD,
	MEMIDX_MAIN_FOURTH,
	MEMIDX_MAIN_FIFTH,
	MEMIDX_MAIN_SIXTH,
	MEMIDX_MAIN_SEVENTH,
	MEMIDX_MAIN_EIGHTH,
	MEMIDX_SUB,
	MEMIDX_SUB_SEC,
	MEMIDX_SUB_THIRD,
	MEMIDX_MAIN_2,
	MEMIDX_MAIN_2_SEC,
	MEMIDX_MAIN_2_THIRD,
	MEMIDX_DI_2,
	MEMIDX_ALL,
	MEMIDX_UNKNOW
}eMemIdx;

typedef enum
{
	MEMCAPTYPE_LINE = 0x00,
	MEMCAPTYPE_FRAME = 0x01
}eMemCapAccessType;

typedef enum {
	MEMALIGN_BANK0 = 0,
	MEMALIGN_BANK1,
	MEMALIGN_BANK2,
	MEMALIGN_BANK3,
	MEMALIGN_ANY,
} eMemAlignment;

#ifndef CONFIG_DARWIN_SCALER
typedef enum {
	MEM_BLOCK_USE_NORMAL=0,
	MEM_BLOCK_USE_OPTIMIZE,
	MEM_BLOCK_TOTAL_NUM,
} eMemBlockUsage;
#endif

typedef enum
{
	MEM_SWBUFFER_SWAP_ENABLE = 0,
	MEM_SWBUFFER_SWAP_DISABLE,
	MEM_SWBUFFER_SWAP_UPDATE_INFO,
}eMemCap_SwBufferSwapState;

typedef enum
{
	MEM_3D_SWBUFFER_SWAP_CONDITION_CHECK = 0,
	MEM_3D_SWBUFFER_SWAP_ENABLE,
	MEM_3D_SWBUFFER_SWAP_DISABLE,
	MEM_3D_SWBUFFER_SWAP_UPDATE_INFO,
}eMemCap_3D_Mode_SwBufferSwapState;

typedef enum _ZOOM_INPUT_INFO{
	//ZOOM_INPUT_MEM_ACT_HSTA,
	//ZOOM_INPUT_MEM_ACT_VSTA,
	ZOOM_INPUT_MEM_ACT_LEN,
	ZOOM_INPUT_MEM_ACT_WID,
	ZOOM_INPUT_CAP_LEN,
	ZOOM_INPUT_CAP_WID,
	ZOOM_INPUT_DISP_LEN,
	ZOOM_INPUT_DISP_WID,
	//ZOOM_INPUT_DISP_LEN_PRE,
	//ZOOM_INPUT_DISP_WID_PRE,
}ZOOM_INPUT_INFO;

typedef enum _ZOOM_DISP_STATUS{
	ZOOM_DISP_THRIP 			= _BIT0,
	ZOOM_DISP_422 				= _BIT1,
	ZOOM_DISP_10BIT			= _BIT2,
	ZOOM_DISP_422CAP			= _BIT3,
	ZOOM_DISP_FSYNC		= _BIT4,
	ZOOM_DISP_VUZD 			= _BIT5,
	ZOOM_DISP_FSYNC_VUZD		= _BIT4|_BIT5,
	ZOOM_DISP_COMP				= _BIT6,
	ZOOM_DISP_FREEZE			= _BIT7,
	ZOOM_DISP_INTERLACE	= _BIT8,
	ZOOM_DISP_SHOW				= _BIT9,
	ZOOM_DISP_RTNR				= _BIT10,
	ZOOM_DISP_MA3A				= _BIT11,
	ZOOM_DISP_VFLIP3			= _BIT13,
	ZOOM_DISP_SIZE				= _BIT14,
	ZOOM_DISP_FIRST			= _BIT15,
} ZOOM_DISP_STATUS;

// Structure of memory tag
typedef enum {
	UNDEFINED = 0,
	ALLOCATED_FROM_LOW = 1,
	ALLOCATED_FROM_HIGH = 2,
	ALLOCATED_FROM_PLI = 3,
} MemBlockStatus;

//compression segment
typedef enum {
	SEGMENT_1 = 0,
	SEGMENT_2 = 1,
	SEGMENT_4 = 2,
	SEGMENT_8 = 3,
} MemCompression;

//compression bits
typedef enum {
	COMPRESSION_10_BITS = 10,
	COMPRESSION_11_BITS = 11,
	COMPRESSION_12_BITS = 12,
	COMPRESSION_13_BITS = 13,
	COMPRESSION_14_BITS = 14,
	COMPRESSION_15_BITS = 15,
	COMPRESSION_16_BITS = 16,
	COMPRESSION_17_BITS = 17,
	COMPRESSION_18_BITS = 18,
	COMPRESSION_19_BITS = 19,
	COMPRESSION_20_BITS = 20,
	COMPRESSION_21_BITS = 21,
	COMPRESSION_22_BITS = 22,
	COMPRESSION_23_BITS = 23,
	COMPRESSION_24_BITS = 24,
	COMPRESSION_25_BITS = 25,
	COMPRESSION_26_BITS = 26,
	COMPRESSION_27_BITS = 27,
	COMPRESSION_28_BITS = 28,
	COMPRESSION_29_BITS = 29,
	COMPRESSION_NONE_BITS = 30,
}MemCompression_Bits;

typedef enum _SLR_DMA_mode{
	SLR_DMA_422_mode 			= 0,
	SLR_DMA_420_mode 			= 1,
	SLR_DMA_400_mode 			= 2,
} SLR_DMA_mode;

typedef struct _MemoryBlock
{
#ifdef CONFIG_DYNAMIC_ALLOCATION_SCALER_MEMORY
	unsigned int Allocate_StartAddr;
	unsigned int Allocate_VirAddr;
#endif
	MemBlockStatus Status;		// 0: undefined, 1: allocated from low, 2: allocated from high
	unsigned int StartAddr;
	unsigned int Size;
}StructMemBlock;

typedef struct{
	UINT32 bOnOff;
	UINT32 compbit;
	UINT32 GameMode;
	UINT32 RGB444Mode;
	UINT32 LivezoomMode;
}M_DOMAIN_COMPRESSION_T;

//mac5p start to use query driver to get memory and address @Crixus 20170504
typedef enum {
	QUERY_IDX_MDOMAIN_MAIN = 0,
	QUERY_IDX_MDOMAIN_SUB,
	QUERY_IDX_MAX,
} MEMORY_QUERY_IDX;

typedef enum {
	VIP_QUERY_IDX_DI = 0,
	VIP_QUERY_IDX_DI_2,
	VIP_QUERY_IDX_DMA,
	VIP_QUERY_IDX_MAX,
} VIP_MEMORY_QUERY_IDX;


/*================================ Definitions ==============================*/
#define _DUMMYADDR					0xFFFFFFFF
#define _DDR_BANK_ADDR_ALIGNMENT	 (1 << (CONFIG_DDR_COL_BITS + CONFIG_DDR_BANK_BITS))		// a ROW start address
#define _DDR_BANK_SIZE					(1<< CONFIG_DDR_COL_BITS)
#define _DDR_BITS						CONFIG_DDR_COL_BITS
#define _DDR_ROW_BITS					CONFIG_DDR_COL_BITS + CONFIG_DDR_BANK_BITS
#define _DDR_END_ADDR					((1 << (CONFIG_DDR_COL_BITS + CONFIG_DDR_BANK_BITS + CONFIG_DDR_ROW_BITS))	- 1)

//Update the fifo depth for each IC @Crixus 20170418
#if 0/* merlin */
#define MERLIN_FIFO_DEPTH
#define _BURSTLENGTH 	(0x80) 	// 0xf0 (240) for Magellan2 HDMI 4k2k60
#define _BURSTLENGTH2 	(0x78) 	// 0x78 (120) for sub-channel
#define _FIFOLENGTH 	(0x200) // FIFO len= 0x200 in Magellan2 //main path FIFO
#define _FIFOLENGTH2 	(0x80) 	//sub path FIFO
#else/* mac */
#define MAC_FIFO_DEPTH
#define _BURSTLENGTH 	(0x80)	//burst length = 64
#define _BURSTLENGTH2 	(0x78) 	// 0x78 (120) for sub-channel
#define _FIFOLENGTH 	(0x100)	//fifo length = 256 for mac5p
#define _FIFOLENGTH2 	(0x80) 	//sub path FIFO
#endif

#if 1//mac3 no in2
#define FrcFreeze()	IoReg_SetBits(MDOMAIN_CAP_DDR_In1Ctrl_reg,_BIT1);
#define FrcDeFreeze()	IoReg_ClearBits(MDOMAIN_CAP_DDR_In1Ctrl_reg,_BIT1);
#else
#define FrcFreeze()	IoReg_SetBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg,_BIT1);
#define FrcDeFreeze()	IoReg_ClearBits(Scaler_DispGetInputInfo(SLR_INPUT_CHANNEL) ? MDOMAIN_CAP_DDR_In2Ctrl_reg : MDOMAIN_CAP_DDR_In1Ctrl_reg,_BIT1);
#endif
#define Mer2_MEMORY_ALLOC
/*================================== Variables ==============================*/
/*================================== Function ===============================*/
/*============================================================================*/
/**
 * drvif_memory_free_block
 * Free memory of the specific tag and insert it to free block information
 *
 * @param <index> { index of DDR memory space, see eMemIdx for details }
 * @return { none }
 *
 */
void drvif_memory_free_block(eMemIdx Idx);

/*============================================================================*/
/**
 * MemGetBlockAddr
 * Get start address of allocated memory
 *
 * @param <index> { index of DDR memory space, see eMemIdx for details }
 * @return { none }
 *
 */
unsigned int drvif_memory_get_block_addr(eMemIdx Idx);

/*============================================================================*/
/**
 * drvif_memory_get_block_size
 * Get size of allocated memory
 *
 * @param <index> { index of DDR memory space, see eMemIdx for details }
 * @return { block size }
 *
 */
unsigned int drvif_memory_get_block_size(eMemIdx Idx);


/*============================================================================*/
/**
 * drvif_memory_alloc_block
 * allocate memory of the specific tag
 *
 * @param <index> { index of DDR memory space, see eMemIdx for details }
 * @return { start address of the allocated memory }
 *
 * @Note:
 *  You must drvif_memory_free_block to free block you allocated before calling this function to allocate memory space.
 *  It possible wrong operatoin if you don't observer the front.
 */
unsigned int drvif_memory_alloc_block(eMemIdx Idx, unsigned int space, unsigned char Align);


/*============================================================================*/
/**
 * MemAlignBank
 * Memory alignment for DDR bank0
 *
 * @param <index> { index of DDR memory space, see eMemIdx for details }
 * @return { none }
 *
 */
unsigned int drvif_memory_alignbank(unsigned int StartAddr, unsigned char AlignBank, unsigned char Frm);


/*============================================================================*/
/**
 * dvrif_memory_handler
 * This function is used to handler memory (page 3).
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 */
void dvrif_memory_handler(void);

/*============================================================================*/
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
void drvif_memory_init(void);

//Release Scaler have allocated memory
void drvif_memory_release(void);
//get scaler memory base physical address
unsigned int get_scaler_memory_base_addr(void);
//Reallocate Scaler d memory
void drvif_memory_reallocate(void);
unsigned char drvif_memory_switch_mem_block(eMemBlockUsage mem_block_usage);
unsigned char drvif_scaler_getValidMemInfo(SCALERDRV_ALLOCBUFFER_INFO *pAllocBufferInfo);
int drvif_scaler_getValidMemInfo_fromVideo(SCALERDRV_ALLOCBUFFER_INFO *pAllocBufferInfo);
unsigned char drvif_scaler_releaseValidMem(void);
unsigned int get_scaler_memory_map_addr(void);
unsigned int get_scaler_memory_map_uncacheaddr(void);

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
void drv_memory_disable_di_write_req(unsigned char disableDiWr);

/*============================================================================*/
/**
 * drv_memory_set_ip_fifo
 * Set IP (video process) memory FIFO registers according to its FIFO-type
 *
 * @param <info> { display-info struecture }
 * @param <access> { 5A => 1, 3A => 0}
 * @return { none }
 * @note
 *
 */
void drv_memory_set_ip_fifo(unsigned char access);


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
unsigned int drvif_memory_get_data_align(unsigned int Value, unsigned int Unit);


/*============================================================================*/
/**
 * drvif_memory_bandwidth_check
 * Check DDR bandwidth used in the present situation
 *
 * @param <display> {Display for Main or Sub}
 * @return { none }
 *
 */
unsigned int drvif_memory_bandwidth_check(unsigned char display);

void drvif_memory_set_fs_display_fifo(void);

#ifdef CONFIG_DUAL_CHANNEL  // There are two channels
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
void drvif_memory_rotate_mp(unsigned short MpIdx);

void drvif_memory_initMp(void);
#endif


unsigned char drvif_memory_set_dbuffer_write(void);
void Memory_SetCapture_AfterFreeze(unsigned char bDouble);
//unsigned char drvif_memory_regAvPresetTable(unsigned short *ptr);
void memory_check_capture_polarity_error(unsigned char channel);
unsigned int memory_get_line_size(unsigned int LineSize, unsigned char InputFormat, unsigned char BitNum);
void memory_division(unsigned int Dividend, unsigned char Divisor, unsigned int* Quotient, unsigned char* Remainder);
void memory_set_capture_fifo(unsigned char channel, unsigned int Quotient, unsigned char Remainder, unsigned char WaterLevel);
void memory_set_input_format(unsigned char display, unsigned char bDouble);
void memory_set_input_format2(unsigned char display, unsigned char bDouble);
#ifdef CONFIG_DUMP_MEMTAG
void drvif_memory_dump_MemTag(void);
#endif

void zoom_memory_set_capture(unsigned char bDouble, eMemCapAccessType Cap_type, unsigned char buffernum);
void zoom_memory_set_main(unsigned char bDouble,unsigned char buffernum);
void zoom_set_input_format(unsigned char display, unsigned char bDouble);
void memory_set_main_activewindow_change(void);
void memory_set_main_displaywindow_change(void);
void memory_set_sub_displaywindow_change(unsigned char changetomain);


void jpeg_memory_alloc_capture2(eMemCapAccessType Cap_type,eMemIdx idx);
void jpeg_memory_free_capture2(void);
/*void drvif_memory_set_osd_disp_mem(StructJPEGDisplayInfo *jpeg_info);*/

void memory_set_adc_capture(unsigned int CapBuf_addr, unsigned int Hight,unsigned int width);
void get_adc_dump_addr_size(unsigned int *PhyAddr, unsigned int *VirStartAddr,unsigned int *Size , unsigned int *Width, unsigned int* Height);
void get_frc_buf_addr_size(unsigned int *PhyAddr, unsigned int *VirStartAddr,unsigned int *Size , unsigned int *Width, unsigned int* Height);
void dump_frc_rawdata_start(void);
void dump_frc_rawdata_release(void);

void get_vdc_dump_addr(unsigned int *PhyAddr, unsigned int *VirStartAddr);
void drv_memory_set_ip_fifo_for_2Dcvt3D(unsigned char access);
void memory_set_capture_for_2Dcvt3D(void);
void memory_set_vflip_capture(unsigned char bVflip, eMemCapAccessType Cap_type);
void zoom_memory_set_vflip_main(unsigned char bVflip,unsigned char buffernum);
unsigned int memory_get_capture_size(unsigned char display, eMemCapAccessType AccessType);

//void memory_3ddma_control_OSD(void);
//void memory_3ddma_control(void);
//void memory_3ddma_disable(void);
//void memory_3ddma_LRSWAP(void);

// IP bit number control (saving bandwidth)
unsigned int drv_memory_get_ip_Btr_mode(void);
unsigned int drv_memory_get_ip_DMA420_mode(void);
void drv_memory_set_ip_Btr_mode(unsigned int mode);
void drv_memory_set_ip_DMA420_mode(unsigned int mode);
void drvif_memory_set_3D_LR_swap(unsigned char lr_swap, unsigned char type_3d);
#ifdef ENABLE_SG_3D_SUPPORT_ALL_SOURCE_3D_MODE // SG 3D PANEL SUPPORT ALL SOURCE 3D MODE
void drvif_memory_set_3D_LR_swap_for_SG_frc_in_mDomain(unsigned char bInvMode);
#endif
void drvif_memory_set_MVC_FRC_LR_swap(unsigned char bInvMode);
unsigned char drvif_memory_sw_buffer_swap_Enable(SCALER_DISP_CHANNEL ucDisplay);
//void drvif_memory_sw_buffer_swap_action(SCALER_DISP_CHANNEL ucDisplay, eMemCap_SwBufferSwapState state);
//void dvrif_memory_set_addr_check(UINT8 Display, UINT8 uc3Buffer);
void dvrif_memory_set_frc_style(unsigned char Display, unsigned char ucEnable);
UINT32 MemGetDDRLineWidth1(UINT8 display,UINT32 width);
UINT32 memory_get_disp_line_size1(UINT8 display,UINT32 width);
void MemGetBlockShiftAddr(UINT8 display,UINT16 HOffset, UINT16 VOffset,UINT32 * StartAddr, UINT16 *DropAddr);


unsigned int drvif_memory_get_3d_startaddr(unsigned char index);
void drvif_memory_set_3d_startaddr(unsigned int addr,unsigned char index);
unsigned int drvif_memory_get_memtag_startaddr(unsigned char index);
void drvif_memory_set_memtag_startaddr(unsigned int addr,unsigned char index);
StructMemBlock* drvif_memory_get_MemTag_addr(unsigned char index);

void memory_set_main_SG_3D_setting(unsigned int LineStep, unsigned int Addr1, unsigned int Addr2, unsigned int Addr3);
void memory_set_MainandSub_ShowONPR(void);

//Mac new adding block mode related driver
//Crixus@20140808
void drvif_memory_block_mode_enable(bool enable);
void drvif_memory_block_mode_set_YC_index(unsigned int Y_index, unsigned int C_index);
void drvif_memory_block_set_Y_offset(unsigned int Y_V_offset, unsigned int Y_H_offset, unsigned int Y_H_shift);
void drvif_memory_block_set_C_offset(unsigned int C_V_offset, unsigned int C_H_offset);
void drv_memory_Main_Disp_Enable(bool enable);

unsigned char dvrif_memory_compression_get_enable(unsigned char display);
void dvrif_memory_compression_set_enable(unsigned char display, unsigned char enable);
unsigned char dvrif_memory_get_compression_bits(void);
void dvrif_memory_set_compression_bits(unsigned char comp_bits);
void dvrif_memory_comp_setting(UINT8 enable_compression, UINT16 comp_wid, UINT16 comp_len, UINT8 comp_ratio);
void mdomain_handler_onlycap_i2run(void);
void mdomain_handler_onlycap(void);
void drvif_memory_compression_rpc(void);


unsigned int drvif_memory_get_mainblock_viraddr(void);
unsigned int drvif_memory_get_subblock_viraddr(void);
unsigned int drv_memory_di_data_size_get(unsigned char access,unsigned int source_width);
unsigned int drv_memory_di_alloc_buffer_get(void);
void drv_memory_di_alloc_buffer_set(unsigned char source,unsigned char data_10bit);
unsigned int drv_memory_di_info_size_get(unsigned char access);
unsigned int drv_memory_di_buffer_get(void);
#ifdef Mer2_MEMORY_ALLOC
char drv_memory_di_Set_Compression_Bit_Num(unsigned char Bit_Num);
unsigned char drv_memory_di_Get_Compression_Bit_Num(void);
char drv_memory_di_Compression_Config(unsigned char src_idx, unsigned char access, unsigned int DI_Width, unsigned int DI_Height);
unsigned int drv_memory_Get_di_data_size_Static(unsigned char src_idx, unsigned char isCompression, unsigned char access, unsigned int DI_Width, unsigned int DI_Height, unsigned char DI_MEM_IDX);
unsigned int drv_memory_Get_di_alloc_buffer_Static(unsigned char src_idx, unsigned char isCompression, unsigned char access, unsigned int DI_Width, unsigned int DI_Height, unsigned char DI_MEM_IDX);
unsigned int drv_memory_Get_di_info_size_Static(unsigned char src_idx, unsigned char isCompression, unsigned char access, unsigned int DI_Width, unsigned int DI_Height, unsigned char DI_MEM_IDX);
unsigned int drv_memory_set_ip_fifo_Mer2(unsigned char access);
void drv_memory_set_De_Mura(unsigned int memory_Addr_sta);
char  drv_memory_I_De_XC_ON_OFF_Wait(unsigned char En);
unsigned int  drv_memory_I_De_XC_DMA_Memory_Get_From_VBM(unsigned char DI_MEM_IDX, unsigned int DI_Width, unsigned int DI_Height, unsigned char Force_Clr);
unsigned int  drv_memory_I_De_XC_DMA_Config(unsigned int DI_phyAddr, unsigned char DI_MEM_IDX, unsigned char vip_src);
unsigned int drv_memory_Set_I_De_XC_DMA(void *dma_data, unsigned char DI_MEM_IDX);
unsigned char drv_memory_Set_I_De_XC_Mem_Ready_Flag(unsigned char MEM_IDX, unsigned char Flag);
unsigned char drv_memory_Get_I_De_XC_Mem_Ready_Flag(unsigned char MEM_IDX);
unsigned int  drv_memory_MA_SNR_Config(unsigned char access ,unsigned int phyAddr, unsigned char DI_MEM_IDX);
unsigned int  drv_memory_Get_MA_SNR_Info_Size_Static(unsigned char access, unsigned int I_Width, unsigned int I_Height, unsigned char DI_MEM_IDX);
#endif
unsigned int drvif_memory_get_memtag_virtual_startaddr(UINT8 index);
void drvif_memory_free_fixed_virtual_memory(void);
void drvif_memory_set_fixed_virtual_memory_size(unsigned int size);
unsigned int drvif_memory_get_fixed_virtual_memory_size(void);
void drvif_memory_set_memtag_virtual_startaddr(unsigned int addr);
void drvif_memory_set_mtag_info(UINT32 buffer_size, UINT8 idx);
void drvif_memory_allocate_fixed_virtual_memory(void);
void drv_memory_set_game_mode(unsigned char enable);
unsigned char drv_memory_get_game_mode(void);
unsigned char drv_memory_get_game_mode_flag(void);
void drv_memory_set_game_mode_dynamic(unsigned char enable);
unsigned char drv_memory_get_game_mode_dynamic(void);
unsigned char drv_memory_get_game_mode_dynamic_flag(void);
void drv_memory_SingleBuffer_GameMode(unsigned char enable);
void drv_memory_SingleBuffer_GameMode_Dynamic(unsigned char enable);
void drv_GameMode_iv2dv_delay(unsigned char enable);
void drv_memory_capture_multibuffer_control(unsigned char buf_num, unsigned char disp2cap_distance);
void drv_memory_capture_multibuffer_address(unsigned int buf4_addr, unsigned int buf5_addr,unsigned int buf6_addr,unsigned int buf7_addr,unsigned int buf8_addr);
void drv_memory_display_multibuffer_control(unsigned char buf_num, unsigned char cap2disp_distance);
void drv_memory_display_multibuffer_address(unsigned int buf4_addr, unsigned int buf5_addr,unsigned int buf6_addr,unsigned int buf7_addr,unsigned int buf8_addr);
void mdomain_handler_i2rnd_mcap_apvr(void);
void mdomain_handler_i2rnd_mcap_sdisp(void);
void i2rnd_default_allocate_mcap1(void);
void i2rnd_default_allocate_mcap2(void);
void i2rnd_default_allocate_DI1(void);
void i2rnd_default_allocate_DI2(void);
void i2rnd_get_mcap2_address(unsigned int *addr1, unsigned int *addr2, unsigned int *addr3);
void drv_memory_Set_multibuffer_flag(UINT8 enable);
UINT8 drv_memory_Get_multibuffer_flag(void);
void drv_memory_Set_multibuffer_number(UINT8 number);
UINT8 drv_memory_Get_multibuffer_number(void);
void drv_memory_capture_multibuffer_update_addr(unsigned int buffer_size, unsigned int start_addr);
void drv_memory_capture_multibuffer_update_boundary(unsigned char buf_num, unsigned int buffer_size);
void drv_memory_wait_cap_last_write_done(unsigned char display, unsigned char wait_frame);
unsigned char drv_memory_get_game_mode_iv2dv_slow_enable(void);
void Scaler_memory_setting_through_CMA(void);
void drv_memory_wait_mdom_vi_last_write_done(unsigned char display, unsigned char wait_frame);
#endif //#ifndef _SCALER_MEMORY_H_

/*======================== End of File =======================================*/
/**
*
* @}
*/

