/******************************************************************************
 *
 *   Realtek Video driver
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author FengYi Lu mail:a0945150@realtek.com
 *
 *****************************************************************************/


#ifndef _LINUX_RTKVDEC_H_
#define _LINUX_RTKVDEC_H_

#include <linux/ioctl.h> /* needed for the _IOW etc stuff used later */
#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/list.h>

#ifndef RTKVDEC_MAJOR
#define RTKVDEC_MAJOR 0 /* dynamic major by default */
#endif

#define RTKVDEC_SUSPEND           100
#define RTKVDEC_RESUME            101
#define RTKVDEC_RESET_PREPARE     102
#define RTKVDEC_RESET_DONE        103

#define DUMP_MEMORY_SIZE 1024*1024
#define DUMP_GET_MAX_SZIE 512*1024
#define DUMP_ES_SIZE 16*1024*1024

#define RTKVDEC_DCU1 0x0
#define RTKVDEC_DCU1_FIRST 0x1
#define RTKVDEC_DCU2 0x2
#define RTKVDEC_DCU2_FIRST 0x3
#define RTKVDEC_VCREATE_ALLOC 0x4
#define RTKVDEC_ENCODER_ALLOC 0x5
#define RTKVDEC_VEPROT_ALLOC 0x7

#define RTKVDEC_PROC_DIR		"rtkvdec"
#define RTKVDEC_PROC_ENTRY      	"statistics"
#define RTKVDEC_MAX_CMD_LENGTH 256

#define RTKVDEC_MAX_SVPMEM_NUM 4
#define RTKVDEC_SVPMEM_SIZE_4M 0x400000
#define RTKVDEC_SVPMEM_SIZE_8M 0x800000
#define RTKVDEC_SVPMEM_SIZE_12M 0xc00000
#define RTKVDEC_SVPMEM_SIZE_16M 0x1000000

#define RTKVDEC_MAX_VBM_MEM_NUM 5

#define RTKVDEC_MAX_IBBUF_NUM 2
#define RTKVDEC_IBBUF_SIZE 0x40000

/* Record memory use*/
typedef struct buffer_info {
	struct list_head buffer_list;
	unsigned long vir_addr; 	//virtual address
	unsigned long phy_addr; 	//physical address
	unsigned long request_size;     //request size
	unsigned long malloc_size;      //kernel malloc size
	pid_t         task_pid;
} buffer_info_t;

typedef struct memory_info {
	struct list_head memory_list;
	unsigned long dcu;      	//allocate from dcu
	unsigned long phy_addr; 	//physical address
	unsigned long request_size;     //request size
	unsigned long malloc_size;      //kernel malloc size
	pid_t         task_pid;
} memory_info_t;

/* IOCTL return structure */
typedef struct ret_info {
	unsigned long private_info[16];
} ret_info_t;
/*
 *=====================================================
 * include video struct
 *=====================================================
 */

/* TVE board type */
enum TVE_BOARD_TYPE {
	TVE_BOARD_CLASSIC_TYPE,
	TVE_BOARD_EXTERNAL_SCART_TYPE,
	TVE_BOARD_AVHDD_TYPE,
	TVE_BOARD_CUSTOM_1_TYPE,
	TVE_BOARD_CUSTOM_2_TYPE,
	TVE_BOARD_CUSTOM_3_TYPE,
	TVE_BOARD_CUSTOM_4_TYPE,
	TVE_BOARD_CUSTOM_5_TYPE,
	TVE_BOARD_CUSTOM_6_TYPE,
	TVE_BOARD_CUSTOM_7_TYPE,
	TVE_BOARD_CUSTOM_8_TYPE,
	TVE_BOARD_CUSTOM_9_TYPE
} ;
typedef enum TVE_BOARD_TYPE TVE_BOARD_TYPE;

struct VIDEO_INIT_DATA {
	enum TVE_BOARD_TYPE boardType ;
};
typedef struct VIDEO_INIT_DATA VIDEO_INIT_DATA;

typedef struct {
	int filterType ;
	int handle ;
	int dst_filterType ;
	int dst_handle ;
} VDEC_FLOW_CMD_T ;

typedef enum {
	SET_BS_RB = 0,  	/* Init bitstream  ring buffer */
	SET_CMD_RB,     	/* Init Inband CMD ring buffer */
	SET_CC_RB,      	/* Init CC         ring buffer */
	SET_REFCLOCK,   	/* Set refClock */
	SET_DECODEMODE, 	/* Set Decode Mode */
	SET_SPEED       	/* Set Speed */
} VDEC_SET_T;

typedef struct {
	VDEC_SET_T      eType ;
	int     	Data ;
	int     	Handle ;
} VDEC_SET_CMD_T ;


struct VIDEO_RPC_DEBUG_MEMORY {
	long videoFirmwareVersion ;
} ;
typedef struct VIDEO_RPC_DEBUG_MEMORY VIDEO_RPC_DEBUG_MEMORY;

typedef struct DEBUG_BUFFER_HEADER {
	unsigned long magic;
	unsigned long size;
	unsigned long rd;
	unsigned long wr;
} DEBUG_BUFFER_HEADER;

typedef struct VDEC_FRAMEINFO_STRUCT {
	pid_t pid ;
	unsigned int frame_dropped ;
	unsigned int frame_displaying ;
	unsigned int frame_matched ;
	unsigned int frame_freerun ;
} VDEC_FRAMEINFO_STRUCT;

typedef struct VDEC_FRAMEINFO_LIST {
	VDEC_FRAMEINFO_STRUCT frame_info ;
	struct list_head buffer_list;
} VDEC_FRAMEINFO_LIST;

typedef struct VDEC_SVPMEM_STRUCT {
	pid_t pid ;
	unsigned int addr ;
	unsigned int size ;
} VDEC_SVPMEM_STRUCT;

typedef struct VDEC_SVPMEM_LIST {
	pid_t pid ;
	unsigned int used;
	unsigned int addr ;
	unsigned int size ;
	unsigned int protected;
	unsigned int used_8M ;
	unsigned int used_12M ;
	unsigned int used_16M ;
	unsigned int is_prot ;
} VDEC_SVPMEM_LIST;

typedef struct VDEC_DVR_MALLOC_STRUCT {
	unsigned long Memory;
	unsigned long PhyAddr ;
	unsigned long VirtAddr ;
} VDEC_DVR_MALLOC_STRUCT;

typedef struct VDEC_SHARE_MEM_STRUCT {
	unsigned int isr[10];
	unsigned int isr_done[10] ;
	unsigned int epc[10] ;
	unsigned int now ;
	unsigned int isr_vector[10];
	unsigned int isr_in_time[10];
	unsigned int isr_out_time[10];
	unsigned int show_ct_no_crash;
	unsigned int video_is_crash;
} VDEC_SHARE_MEM_STRUCT;

typedef struct VDEC_VBM_MEM_LIST {
	unsigned int used;
	unsigned long addr ;
	unsigned int size ;
} VDEC_VBM_MEM_LIST;

typedef enum {
	VDEC_SVP_BUF = 0,
	VDEC_INBAND_BUF
} VDEC_COBUF_TYPE;

/* Use 'v' as magic number */
#define VDEC_IOC_MAGIC  'v'
#define VDEC_IOC_INIT       _IO  (VDEC_IOC_MAGIC, 1)
#define VDEC_IOC_DEINIT     _IO  (VDEC_IOC_MAGIC, 2)
#define VDEC_IOC_OPEN       _IOWR(VDEC_IOC_MAGIC, 3, int)
#define VDEC_IOC_CLOSE      _IOW (VDEC_IOC_MAGIC, 4, int)
#define VDEC_IOC_PLAY       _IOW (VDEC_IOC_MAGIC, 5, int)
#define VDEC_IOC_PAUSE      _IOW (VDEC_IOC_MAGIC, 6, int)
#define VDEC_IOC_FLUSH      _IOW (VDEC_IOC_MAGIC, 7, int)
#define VDEC_IOC_STOP       _IOW (VDEC_IOC_MAGIC, 8, int)
#define VDEC_IOC_CONNECT    _IOW (VDEC_IOC_MAGIC, 9, int)
#define VDEC_IOC_SET        _IOW (VDEC_IOC_MAGIC,10, int)
#define VDEC_IOC_GET        _IOR (VDEC_IOC_MAGIC,11, int)
#define VDEC_IOC_ENVDBG     _IOW (VDEC_IOC_MAGIC,12, VDEC_DBG_STRUCT)
#define VDEC_IOC_DISVDBG    _IO  (VDEC_IOC_MAGIC,13)
#define VDEC_IOC_FRAMEINFO  _IOW (VDEC_IOC_MAGIC,14, VDEC_FRAMEINFO_STRUCT *)
#define VDEC_IOC_ALLOCSVPM  _IOWR(VDEC_IOC_MAGIC,15, VDEC_SVPMEM_STRUCT *)
#define VDEC_IOC_FREESVPM   _IOW (VDEC_IOC_MAGIC,16, VDEC_SVPMEM_STRUCT *)
#define VDEC_IOC_ALLOC      _IOW (VDEC_IOC_MAGIC,17, int)
#define VDEC_IOC_FREE       _IOW (VDEC_IOC_MAGIC,18, int)
#define VDEC_IOC_HALLOG     _IOW (VDEC_IOC_MAGIC,19, int)
#define VDEC_IOC_ALLOC_IBBUF  _IOWR(VDEC_IOC_MAGIC,20, VDEC_SVPMEM_STRUCT *)
#define VDEC_IOC_FREE_IBBUF   _IOW (VDEC_IOC_MAGIC,21, VDEC_SVPMEM_STRUCT *)
#define VDEC_IOC_QVCDONE    _IO  (VDEC_IOC_MAGIC,22)
#define VDEC_IOC_ALLOCSVPMP _IOWR(VDEC_IOC_MAGIC,24, VDEC_SVPMEM_STRUCT *)

void rtkvdec_vtm_state(void) ;
void rtkvdec_send_sharedmemory(void) ;
void rtkvdec_show_sharedmemory(void) ;
int rtkvdec_cobuffer_alloc(VDEC_COBUF_TYPE type, int port) ;
int rtkvdec_cobuffer_free (VDEC_COBUF_TYPE type, unsigned int phy_addr) ;
//void rtkvdec_DCMTCallbackFunction(void);

/* end of _LINUX_RTKVDEC_H_ */
#endif
