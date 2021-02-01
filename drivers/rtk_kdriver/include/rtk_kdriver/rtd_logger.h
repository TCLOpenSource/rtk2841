/*
    this file is used for rtd logbuf design
    there are total 5 logbuf:
    ACPU&ACPU2 / VCPU&VCPU2 / KCPU / SCPU-Kernel / SCPU-Hal
*/
#ifndef __RTD_LOGGER_H__
#define __RTD_LOGGER_H__

#include <linux/cdev.h>
#include <linux/semaphore.h>
#include "rtk_crt.h"

//#define MAX_READER_PER_LOGBUF 4 //max allowed reader at the same time for each rtd logbuf
#define FILE_MSG_TAG_LEN 256 //max msg header(ascii info) length
#define RTD_LOGBUF_DEV_MAJOR 286
#define RTD_LOGBUF_DEV_MINOR 0
#define RTD_LOGCAT_DEV_MAJOR 287
#define RTD_LOGCAT_DEV_MINOR 0
#define RTD_LOGBUF_PHY_START_ADDR 0x1ca00000
#define RTD_LOGBUF_LIMIT 0x600000
#define RTD_LOGBUF_PARAM_LIMIT 0x100000
#define RTD_LOGBUF_DEFAULT_LIMIT 0x80000
#define RTD_LOGBUF_DEFAULT_PARAM 0xe000
#define RTD_LOGBUF_VERSION 6
#define RTD_LOGBUF_MAGIC_1 0xBFBFBFBF
#define RTD_LOGBUF_MAGIC_2 0x20160724
#define RTD_LOGBUF_MAGIC_3 0x1234ABCD
#define RTD_LOGBUF_MAGIC_4 0xBFBFBFBF

#define RTD_LOGBUF_CMDLINE_OFFSET 0xe00
#define RTD_LOGBUF_CMDLINE_SIZE 0x200

typedef enum EnumLogbufType {
        ACPU1_BUF = 0,
        ACPU2_BUF,
        VCPU1_BUF,
        VCPU2_BUF,
        KCPU_BUF,
        KERNEL_BUF,
        HAL_BUF,
        MAX_LOGBUF_NUM
} EnumLogbufType;

typedef enum EnumPanicCpuType {
        ACPU1 = 0,
        ACPU2,
        VCPU1,
        VCPU2,
        KCPU,
        KERNEL,
        HAL,   
        NORMAL,
} EnumPanicCpuType;

typedef struct logbuf_global_status {
        volatile u64 nsec;      //time stamp
        volatile u32 magic_seg1;   //magic number Seg1 for logbuf
        volatile u32 magic_seg2;   //magic number Seg2 for logbuf
        volatile u32 magic_seg3;   //magic number Seg3 for logbuf
        volatile u32 magic_seg4;   //magic number Seg4 for logbuf
        volatile u32 rbcb_addr[MAX_LOGBUF_NUM];//logbuf ring_buffer_control_block phy address
        volatile u8 version;  //rtd logbuf sw version
        volatile u8 reserve_1;
        volatile u8 reserve_2;
        volatile u8 reserve_3;
} logbuf_global_status; //rtd logbuf global status

#ifdef CONFIG_64BIT
#define RTD_LOGBUF_RBCB_OFFSET_64 0x50
typedef struct kfifo
{
        u64 size;  /* the size of the allocated buffer */
        u64 in;    /* data is added at offset (in % size) */
        u64 out;   /* data is extracted from off. (out % size) */
        u64 out_cat;   /* data out pos for logcat */
        unsigned char *buffer;  /* the buffer holding the data */
}rtdlog_kfifo;

typedef struct logbuf_rbcb {
        u64 logbuf_phy_addr;
        u64 logbuf_len;
        u64 ddr_mutex;
        u64 drop_cnt; //counter of dropped logs
        u64 in_reset; //keep old value of kfifo->in to record the old log end offset
        rtdlog_kfifo fifo ; // logbuf size
} logbuf_rbcb;

typedef struct kfifo_32
{
        unsigned int buffer;  /* the buffer holding the data */
        unsigned int size;  /* the size of the allocated buffer */
        unsigned int in;    /* data is added at offset (in % size) */
        unsigned int out;   /* data is extracted from off. (out % size) */
        unsigned int out_cat;   /* data out pos for logcat */
}rtdlog_kfifo_32;

typedef struct logbuf_rbcb_32 {
        u32 logbuf_phy_addr; //write size
        u32 logbuf_len; //logbuf phy address
        u32 ddr_mutex; //reserved mutex seg
        u32 drop_cnt; //counter of dropped logs
        u32 in_reset; //keep old value of kfifo->in to record the old log end offset
        rtdlog_kfifo_32 fifo ;// logbuf size
} logbuf_rbcb_32;

#else   // #ifdef CONFIG_64BIT

typedef struct kfifo
{
        unsigned char *buffer;  /* the buffer holding the data */
        unsigned int size;  /* the size of the allocated buffer */
        unsigned int in;    /* data is added at offset (in % size) */
        unsigned int out;   /* data is extracted from off. (out % size) */
        unsigned int out_cat;   /* data out pos for logcat */
}rtdlog_kfifo;

typedef struct logbuf_rbcb {
        u32 logbuf_phy_addr; //write size
        u32 logbuf_len; //logbuf phy address
        u32 ddr_mutex; //reserved mutex seg
        u32 drop_cnt; //counter of dropped logs
        u32 in_reset; //keep old value of kfifo->in to record the old log end offset
        rtdlog_kfifo fifo ;// logbuf size
} logbuf_rbcb;

#endif  // #ifdef CONFIG_64BIT

typedef struct logbuf_thread_param {
    u32 id;
} logbuf_thread_param;

typedef struct rtd_msg_header {
        u64 timestamp;     //timestamp in nanoseconds
        u32 len;           //length of entire record
        u32 pid;           //thread pid
        u32 tid;           //thread tid
        u32 module;        //module bit/ID
        u32 text_len;      //length of text buffer
        u32 check_sum;
        u8 name[16];       //task/process name
        u8 level;          //log level
        u8 cpu_type;       //cpu type : same as rtd logbuf type
        u8 cpu_core;       //cpu core id
        u8 reserve0;
} rtd_msg_header __attribute__((aligned (4))); //msg header for each log in rtd logbuf

typedef struct rtd_logbuf_para {
        u32 rbcb_vaddr;         //rbcb virtual address
        u32 logbuf_vaddr;       //logbuf virtual address
        u32 logbuf_len;         //logbuf size
} rtd_logbuf_para;          //logbuf param for the read-thread

struct rtdlog_dev {
        struct semaphore sem;     /* mutual exclusion semaphore     */
        struct cdev cdev;   /* Char device structure          */
};//rtd logbuf device node

typedef struct rtd_logbuf_hal_info {
        u8 level;       //log level
        u8 core;        //cpu core id
        u8 reserve1;
        u8 reserve2;
        u32 module;     //module bit/ID
} rtd_logbuf_hal_info;  //info come from hal log which append before hal log text

typedef struct rtdlog_outer {
        EnumLogbufType type;    //logbuf type
        rtd_msg_header header;  //msg header
        struct list_head list;  //list structure
        u32 text_vaddr;         //text offset in rtd logbuf
} rtdlog_outer;//rtd logbuf out node(all log in rtd logbuf will pop to this node by read-thread)

typedef struct filter_cpu {
        u32 module_mask;    //module bit mask: 1-mask 0-nonmask
        u8 level;           //level: log level <= this level will put into file
        u8 core_mask;       //core bit mask: 1-mask 0-nonmask
        u8 reserve1;
        u8 reserve2;
} filter_cpu;   //filter for each logbuf type

typedef struct rtdlog_filter {
        filter_cpu sub_mask[MAX_LOGBUF_NUM];    //filter for each logbuf type
        unsigned char buf_cat;        //a1,a2,v1,v2,ker,hal bit-value: 1-read thread skip 0-normal
        unsigned char buf_mask;        //a1,a2,v1,v2,ker,hal bit-value : 1-mask 0-nonmask
        unsigned char level_mask;   //level_warning: log level <= this level,ignore buf_mask ,put into file
        unsigned char reserve2;     // control hal log show on console (log level <= level_hal), 
} rtdlog_filter;

typedef enum LOGBUF_FILTER_OPERA {
        LOG_ON,         //set logbuf filter
        LOG_OFF,        //unset logbuf filter
        LOG_DBG,        //dump dbg info
        LOG_HELP,        //show help info
        LOG_BLOCK,       //block/unblock read thread
        LOG_CONVERT,     //convert reboot log
        LOG_DUMP,        //dump logbuf.bin
        LOG_DMSG_ON,    //control print log to dmesg
        LOG_DMSG_OFF,   //control print log to dmesg
        LOG_CAT_ON,      //set cat filter
        LOG_CAT_OFF,     //unset cat filter
        LOG_FILE_TOGGLE, //toggle log file write
        LOG_FILE_UNMASK_LEVEL, // log level <= this level,ignore buf_mask ,put into file/console
} LOGBUF_FILTER_OPERA;//rtd logbuf debug node operation

typedef struct rtdlog_sysnode_param {
        LOGBUF_FILTER_OPERA opera; //operation
        u8 buf_idx[MAX_LOGBUF_NUM];//rtd lobbuf type array,value for each element : 1-valid_param 0-invalid_param
        u8 core_modify;             //core modify flag
        u8 core_mask;               //core bit mask
        u8 level_modify;            //level modify flag
        u8 level;                   //log level
        u8 module_modify;           //module modify flag
        u32 module_mask;            //module bit mask
        u8 masklevel;                   //log level
        u8 masklevel_modify;            //level modify flag
} rtdlog_sysnode_param;//rtd logbuf debug node param

typedef struct rtd_file_info
{
        //rtd_logfile.log
        struct file * logfile_fd;
        unsigned long logfile_max_size;
        unsigned char logfile_param;// rtd_logfile.log param:enable bit 3, wrap bit 1, header bit 0
        
        //fw.log
        struct file *fwfile_fd[MAX_LOGBUF_NUM];       //a1/a2/v1/v2////      
        unsigned long fwfile_max_size[MAX_LOGBUF_NUM];  //fw file max size
        unsigned char fwfile_param[MAX_LOGBUF_NUM];    //fw file param:enable bit 3, wrap bit 1, header bit 0
}rtd_file_info;

typedef struct rtdlog_dbg_info {
        //save msg to buf
        u32 save_log_len[MAX_LOGBUF_NUM];
        u32 save_log_cnt[MAX_LOGBUF_NUM];
        //read msg from buf
        u32 read_log_cnt[MAX_LOGBUF_NUM];
        u32 read_log_len[MAX_LOGBUF_NUM];
        //save to file
        u32 total_write_cnt;
        u32 total_write_len;
        u32 log_wrap_cnt;
        //file log
        u32 file_log_cnt[MAX_LOGBUF_NUM];
        u32 file_log_len[MAX_LOGBUF_NUM];
        //abnormal data
        u32 drop_log_cnt[MAX_LOGBUF_NUM];
        u32 log_reset_cnt[MAX_LOGBUF_NUM];
        u32 vfs_write_fail_cnt;
} rtdlog_dbg_info;

typedef struct logbuf_filesize{
        unsigned int total_file;
        unsigned int acpu1_file;
        unsigned int acpu2_file;
        unsigned int vcpu1_file;
        unsigned int vcpu2_file;
        unsigned int reserve1;
        unsigned int reserve2;
        unsigned int reserve3;
}logbuf_filesize;

#define LOGBUF_DIR_LEN 64
typedef struct logbuf_cmdline{
        volatile unsigned int magic_seg1;   //magic number Seg1 for logbuf
        volatile unsigned int magic_seg2;   //magic number Seg2 for logbuf
        volatile unsigned int magic_seg3;   //magic number Seg3 for logbuf
        volatile unsigned int magic_seg4;   //magic number Seg4 for logbuf
        unsigned int logswi;
        unsigned int logfile;
        unsigned int reserve1;
        unsigned int reserve2;
        unsigned char logdir[LOGBUF_DIR_LEN];
        logbuf_filesize filesize;
        rtdlog_filter log_filter;
}logbuf_cmdline;

//bootcode param
typedef enum RTDLOG_BOOT_ARG
{
        //Byte0 dmsg & log-file
        ARG_MSG_A1_EN=0,     //dmesg with a1 or not
        ARG_MSG_A2_EN,
        ARG_MSG_V1_EN,
        ARG_MSG_V2_EN,
        ARG_MSG_K_EN,
        ARG_MSG_HAL_EN,
        ARG_LOG_FILE_EN,    //log file write or not
        ARG_REBOOT_LOG_EN, //generate reboot log or not
        //Byte1 log-filter
        ARG_LFILT_A1_EN, //log-filter enable a1 or not
        ARG_LFILT_A2_EN,
        ARG_LFILT_V1_EN,
        ARG_LFILT_V2_EN,
        ARG_LFILT_K_EN,
        ARG_LFILT_SKER_EN,
        ARG_LFILT_SHAL_EN,
        ARG_LFILT_RESERVE0,
        //Byte2 reserve
        ARG_LOG_EMMC_EN, //log in emmc or not
        //Byte3 reserve
        ARG_VALID = 31,    //last bit,is boot_arg invalid or not
}RTDLOG_BOOT_ARG;

int rtdlog_save_msg(EnumLogbufType type, const char * text, rtd_msg_header * header);
void rtdlog_kfifo_init (void);

/**********************keylog related**************************/
#if defined(CONFIG_REALTEK_LOGBUF)

#define RTD_LOGBUF_KEYLOG_OFFSET 0x2000        // save key log. buffer start address 0x1ca0_2000
#define RTD_LOGBUF_KEYLOG_SIZE 0X1000         // key log buffer SIZE 4k
#define RTD_KEYLOG_MAGIC "\n/****History Log Cut Line****/\n"
int rtdlog_save_keylog(const char * fmt, ...);

#define rtd_save_keylog(level, tag, fmt,args ...)        \
        do{\
                rtd_printk(level, tag, fmt, ## args);\
                rtdlog_save_keylog(fmt, ## args);\
        }while(0)

#else   // #if defined(CONFIG_REALTEK_LOGBUF)

#define rtd_save_keylog(level, tag, fmt, args...)   rtd_printk(level, tag, fmt,## args)

#endif  // #if defined(CONFIG_REALTEK_LOGBUF)

/**********************dump a/v/k log related**************************/
struct rtd_logger_work_struct {
        struct work_struct work;
        unsigned int param;
};

#if defined (CONFIG_REALTEK_LOGBUF)
extern struct workqueue_struct *p_dumpqueue;
extern EnumPanicCpuType g_rtdlog_panic_cpu_type;
extern struct rtd_logger_work_struct DumpWork;
extern void rtdlog_watchdog_dump_work(EnumLogbufType type);

#define set_rtdlog_panic_cpu_type(cpu)  do { g_rtdlog_panic_cpu_type = (cpu); } while(0)

#else
#define set_rtdlog_panic_cpu_type(cpu) do {} while(0)
#endif  //#if defined (CONFIG_REALTEK_LOGBUF)

#endif /*__RTD_LOGGER_H__*/
