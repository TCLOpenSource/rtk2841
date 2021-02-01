#include <generated/autoconf.h>
#include <linux/init.h>
#include <linux/kernel.h>   /* MISC_DBG_PRINT() */
#include <linux/slab.h>     /* kmalloc() */
#include <linux/fs.h>           /* everything... */
#include <linux/errno.h>        /* error codes */
#include <linux/types.h>        /* size_t */
#include <linux/fcntl.h>        /* O_ACCMODE */
#include <linux/cdev.h>
#include <mach/system.h>
#include <linux/module.h>
#include <asm/uaccess.h>        /* copy_*_user */
#include <asm/io.h>
#include <linux/sched.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <rtd_logger.h>
#include <linux/mm.h>
#include <linux/string.h>       /* memcpy */
#include <mach/rtk_log.h>       /* rtd_printk */
#include <linux/kernel.h>
#include <mach/io.h>
#include <linux/miscdevice.h>
#include <generated/autoconf.h>
#include <linux/statfs.h>
#include <linux/syscalls.h>
#include <linux/console.h>

#if (defined(CONFIG_OPTEE) && !defined(CONFIG_CUSTOMER_TV006))
#include <linux/arm-smccc.h>

struct optee_rpc_param {
        u32     a0;
        u32     a1;
        u32     a2;
        u32     a3;
        u32     a4;
        u32     a5;
        u32     a6;
        u32     a7;
};
__attribute__((weak)) int optee_logbuf_setup_info_send(struct optee_rpc_param *p_rtc_set_info)
{
        return -1;
}
#endif

#define RTDLOG_TAG "RTDLOG" //rtd_printk tag string
//#define RTDLOG_AVCPU2


extern char *native_logbuf_addr;
bool is_setup_rtd_logbuf = false;           //save log to rtd logbuf when true only
bool is_save_early_log_done = false;           //printk save log to rtd logbuf when true only
unsigned long rtdlog_bufsize;
unsigned long rtdlog_param_size;

volatile u64 * gpRtdlogTimestamp;           //time stamp ptr
logbuf_rbcb * pRtdLogCB[MAX_LOGBUF_NUM] = {0};
#ifdef CONFIG_64BIT
logbuf_rbcb_32 * pRtdLogCB_32[MAX_LOGBUF_NUM] = {0};
#endif
static rtdlog_filter log_filter;
static rtdlog_filter cat_filter;
static rtdlog_dbg_info gDbgInfo;
static rtd_file_info gFileInfo;
void * gHistoryBuf = NULL;

static unsigned int rtd_keylog_pos = 0; // record keylog buffer offset
static unsigned int rtd_keylog_last_pos = 0; // record last boot buffer offset
unsigned char * rtd_keylog_addr = NULL;

static int hal_rtdlb_dmesg_en = 0;//vcpu2 rtd logbuf dmesg enable
static int kcpu_rtdlb_dmesg_en = 0;//vcpu1 rtd logbuf dmesg enable
static int acpu1_rtdlb_dmesg_en = 1;//acpu1 rtd logbuf dmesg enable
static int acpu2_rtdlb_dmesg_en = 1;//acpu2 rtd logbuf dmesg enable
static int vcpu1_rtdlb_dmesg_en = 1;//vcpu1 rtd logbuf dmesg enable
static int vcpu2_rtdlb_dmesg_en = 1;//vcpu2 rtd logbuf dmesg enable
static int rtdlog_file_en=0;//rtd log file write or not

static DEFINE_MUTEX(rtd_logfile_lock);  // AP copy & gzip handle rtd_logfile.log file at the same time

static DEFINE_MUTEX(save_acpu1_mutex);
static DEFINE_MUTEX(save_acpu2_mutex);
static DEFINE_MUTEX(save_vcpu1_mutex);
static DEFINE_MUTEX(save_vcpu2_mutex);
static DEFINE_MUTEX(save_kcpu_mutex);
static DEFINE_MUTEX(save_kernel_mutex);
static DEFINE_MUTEX(save_hal_mutex);
static DEFINE_MUTEX(logcat_mutex);
static DEFINE_MUTEX(read_loop_mutex);
static DEFINE_MUTEX(keylog_mutex);

struct mutex * log_save_mutex[MAX_LOGBUF_NUM]=
{
    &save_acpu1_mutex,
    &save_acpu2_mutex,
    &save_vcpu1_mutex,
    &save_vcpu2_mutex,
    &save_kcpu_mutex,
    &save_kernel_mutex,
    &save_hal_mutex
};

struct kfifo * array_fifo[MAX_LOGBUF_NUM]=
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};
//LIST_HEAD(rtdlog_out_list);
struct list_head rtdlog_out_list;

asmlinkage long sys_statfs64(const char __user *path, size_t sz, struct statfs64 __user *buf);
extern void save_early_log(void);   //move scpu kernel log from linux logbuf to rtd logbuf
int rtdlog_save_msg(EnumLogbufType type, const char * text, rtd_msg_header * header);
int rtdlogcat_node_init (void);
unsigned int write_logcat_data (EnumLogbufType type,char __user * buf);
void init_rtdlog_file_path(void);
int get_msg_header (EnumLogbufType type,rtd_msg_header* header,struct kfifo * pKfifo);


static int exec_user_cmd (const char * cmd)
{
    char* path_bash = "/bin/sh";
    char * argv_cmd[]= {path_bash,"-c",(char *)cmd,NULL};
    char * envp[] = {NULL};

    int ret = call_usermodehelper(path_bash, argv_cmd, envp, UMH_WAIT_PROC);
    if(ret < 0)
    {
        rtd_printk(KERN_ERR, RTDLOG_TAG, "cmd %s fail...ret=%d\n",cmd, ret);
    }
    else
    {
        //rtd_printk(KERN_INFO, RTDLOG_TAG, "cmd %s ok\n",cmd);
    }
    return ret;
}


/*------------------------------------------------------------------------------------------
----------------------------------------kfifo related code-------------------------------------
------------------------------------------------------------------------------------------*/
static inline __must_check unsigned int kfifo_size(struct kfifo *fifo)
{
    return fifo->size;
}

static inline unsigned int kfifo_out_len(struct kfifo *fifo)
{
    register unsigned int out;
    out = fifo->out;
    smp_rmb();
    return (fifo->in) - out;
}

static inline unsigned int kfifo_cat_len(struct kfifo *fifo)
{
    register unsigned int out_cat;
    out_cat = fifo->out_cat;
    smp_rmb();
    return (fifo->in) - out_cat;
}

static inline unsigned int kfifo_len(struct kfifo *fifo)
{
    unsigned int len_out;

    len_out = kfifo_out_len(fifo);

    return len_out;
}

static inline __must_check unsigned int kfifo_avail(struct kfifo *fifo)
{
    unsigned int out_len;//,cat_len,use_len;
    out_len = kfifo_len(fifo);
    return kfifo_size(fifo) - out_len;
}

static inline unsigned int __kfifo_off(struct kfifo *fifo, unsigned int off)
{
    return off & (fifo->size - 1);
}

static inline void kfifo_reset(struct kfifo *fifo)
{
    fifo->in = fifo->out = 0;
    fifo->out_cat = 0;
}

static inline void kfifo_drop(struct kfifo *fifo)
{
    fifo->out = fifo->in;
}

static inline void kfifo_cat_sync(struct kfifo *fifo)
{
    fifo->out_cat = fifo->out;
}

static void _kfifo_init(struct kfifo *fifo, void *buffer, unsigned int size)
{
    fifo->buffer = buffer;
    fifo->size = size;

    kfifo_reset(fifo);
}

void kfifo_init (struct kfifo *fifo, void *buffer, unsigned int size)
{
    /* size must be a power of 2 */
    BUG_ON(!is_power_of_2(size));
    _kfifo_init(fifo, buffer, size);
}

static inline void __kfifo_in_data (struct kfifo *fifo, const void *from, unsigned int len, unsigned int off)
{
    unsigned int l;

    /*
     * Ensure that we sample the fifo->out index -before- we
     * start putting bytes into the kfifo.
     */

    smp_mb();

    off = __kfifo_off(fifo, fifo->in + off);

    /* first put the data starting from fifo->in to buffer end */
    l = min((unsigned long)len, (unsigned long)(fifo->size - off));
    memcpy((unsigned char *)phys_to_virt((unsigned long)fifo->buffer) + off, from, l);

    /* then put the rest (if any) at the beginning of the buffer */
    memcpy((unsigned char *)phys_to_virt((unsigned long)fifo->buffer), from + l, len - l);
}

static inline void __kfifo_out_data(struct kfifo *fifo,void *to, unsigned int len, unsigned int off)
{
    unsigned int l;

    /*
     * Ensure that we sample the fifo->in index -before- we
     * start removing bytes from the kfifo.
     */

    smp_rmb();

    off = __kfifo_off(fifo, fifo->out + off);

    /* first get the data from fifo->out until the end of the buffer */
    l = min((unsigned long)len, (unsigned long)(fifo->size - off));
    memcpy(to, (unsigned char *)phys_to_virt((unsigned long)fifo->buffer) + off, l);

    /* then get the rest (if any) from the beginning of the buffer */
    memcpy(to + l, (unsigned char *)phys_to_virt((unsigned long)fifo->buffer), len - l);
}

static inline void __kfifo_vmem_out_data(struct kfifo *fifo,void *to, unsigned int len, unsigned int off)
{
    unsigned int l;

    /*
     * Ensure that we sample the fifo->in index -before- we
     * start removing bytes from the kfifo.
     */

    smp_rmb();

    off = __kfifo_off(fifo, fifo->out + off);

    /* first get the data from fifo->out until the end of the buffer */
    l = min((unsigned long)len, (unsigned long)(fifo->size - off));
    memcpy(to, (unsigned char *)(fifo->buffer) + off, l);

    /* then get the rest (if any) from the beginning of the buffer */
    memcpy(to + l, (unsigned char *)(fifo->buffer), len - l);
}

static inline void __kfifo_cat_out_data(struct kfifo *fifo,void *to, unsigned int len, unsigned int off)
{
    unsigned int l;

    /*
     * Ensure that we sample the fifo->in index -before- we
     * start removing bytes from the kfifo.
     */

    smp_rmb();

    off = __kfifo_off(fifo, fifo->out_cat + off);

    /* first get the data from fifo->out until the end of the buffer */
    l = min((unsigned long)len, (unsigned long)(fifo->size - off));
    memcpy(to, (unsigned char *)phys_to_virt((unsigned long)fifo->buffer) + off, l);

    /* then get the rest (if any) from the beginning of the buffer */
    memcpy(to + l, (unsigned char *)phys_to_virt((unsigned long)fifo->buffer), len - l);
}

static inline void __kfifo_add_in (struct kfifo *fifo,unsigned int off)
{
    smp_wmb();
    fifo->in += off;
}

static inline void __kfifo_add_out (struct kfifo *fifo,unsigned int off)
{
    smp_mb();
    fifo->out += off;
}

static inline void __kfifo_decrease_out (struct kfifo *fifo,unsigned int off)
{
    unsigned int offset;
    unsigned int fifo_avail = kfifo_avail(fifo);        //resverd len
    smp_mb();
    offset =  off < (fifo_avail-512)? off: (fifo_avail-512);    //avail -512
    fifo->out = fifo->out - offset;

}

static inline void __kfifo_set_out (struct kfifo *fifo,unsigned int value)
{
    smp_mb();
    fifo->out = value;
}

static inline void __kfifo_cat_add_out (struct kfifo *fifo,unsigned int off)
{
    smp_mb();
    fifo->out_cat += off;
}

static unsigned int kfifo_in(struct kfifo *fifo, const void *from, unsigned int len)
{
    len = min(kfifo_avail(fifo), len);

    __kfifo_in_data(fifo, from, len, 0);
    __kfifo_add_in(fifo, len);

    return len;
}

static __maybe_unused unsigned int kfifo_out(struct kfifo *fifo, void *to, unsigned int len)
{
    len = min(kfifo_len(fifo), len);

    __kfifo_out_data(fifo, to, len, 0);
    __kfifo_add_out(fifo, len);
    return len;
}

static unsigned int kfifo_cat_out(struct kfifo *fifo, void *to, unsigned int len)
{
    len = min(kfifo_cat_len(fifo), len);

    __kfifo_cat_out_data(fifo, to, len, 0);
    __kfifo_cat_add_out(fifo, len);
    return len;
}

static unsigned int kfifo_out_peek (struct kfifo *fifo, void *to, unsigned int len,unsigned offset)
{
    len = min(kfifo_len(fifo), len + offset);
    __kfifo_out_data(fifo, to, len, offset);
    return len;
}

static unsigned int kfifo_cat_out_peek (struct kfifo *fifo, void *to, unsigned int len,unsigned offset)
{
    len = min(kfifo_cat_len(fifo), len + offset);
    __kfifo_cat_out_data(fifo, to, len, offset);
    return len;
}

//-------------------control block related-------------------------------

u32 get_msghead_sum(rtd_msg_header * header)
{
        int i;
        u32 val = 0;

        val += header->cpu_core;
        val += header->cpu_type;
        val += header->len;
        val += header->level;
        val += header->module;
        val += header->pid;
        val += header->tid;
        val += header->text_len;
        val += (header->timestamp & 0xffffffff);
        val += (header->timestamp>>32)&0xffffffff;

        for(i = 0;i < sizeof(header->name);++i)
        {
                val += header->name[i];
        }

        return val;
}

static int check_msghead_sum(rtd_msg_header * header)
{
        u32 sum_store = header->check_sum;
        u32 sum_cacu = get_msghead_sum(header);

        if(sum_store == sum_cacu)
        {
                return 0;
        }

        return -1;
}

static int check_msghead_valid(rtd_msg_header * header)
{
        if((header->len > header->text_len)&&((header->len - header->text_len) == sizeof(rtd_msg_header)))
        {
                if(check_msghead_sum(header))
                {
                        goto check_fail;
                }
                else
                {
                        goto check_pass;
                }
        }

check_fail:
        return -1;
check_pass:
        return 0;
}

/*-----------------------------save key log ----------------------------*/
//void dump_ddr_range(char * msg,void * start,unsigned int len);
int rtdlog_save_keylog(const char * fmt, ...)
{
        va_list args;
        struct timeval log_time;
        struct mutex * mtx = &keylog_mutex;

        if((!is_setup_rtd_logbuf) || (rtd_keylog_addr == NULL) || (gpRtdlogTimestamp == NULL)){
                rtd_printk(KERN_ERR,RTDLOG_TAG,"Save keylog fail. is_setup_rtd_logbuf=%d, rtd_keylog_addr or gpRtdlogTimestamp is Null\n",is_setup_rtd_logbuf);
                return -1;
        }

        if(rtd_keylog_pos >= RTD_LOGBUF_KEYLOG_SIZE-1){ // keylog buffer full
                rtd_printk(KERN_ERR,RTDLOG_TAG,"Save keylog fail. keylog buffer is full\n");
                return -2;
        }

        log_time = ns_to_timeval((s64)(*gpRtdlogTimestamp));
        mutex_lock(mtx);
        // save time stamp
        snprintf((rtd_keylog_addr+rtd_keylog_pos), RTD_LOGBUF_KEYLOG_SIZE-rtd_keylog_pos-1 , "[%08d.%06d]", (int)log_time.tv_sec, (int)log_time.tv_usec);

        // save log
        va_start(args, fmt);
        rtd_keylog_pos = strlen(rtd_keylog_addr);
        if(rtd_keylog_pos < RTD_LOGBUF_KEYLOG_SIZE-1){
                vsnprintf((rtd_keylog_addr+rtd_keylog_pos), RTD_LOGBUF_KEYLOG_SIZE-rtd_keylog_pos-1, fmt, args);
        }
        va_end(args);

        // append \n after each log
        rtd_keylog_pos = strlen(rtd_keylog_addr);
        if((rtd_keylog_pos<RTD_LOGBUF_KEYLOG_SIZE) && (*(rtd_keylog_addr+rtd_keylog_pos-1)!='\n')){
                *(rtd_keylog_addr+rtd_keylog_pos) = '\n';
                rtd_keylog_pos = rtd_keylog_pos+1;
        }
        mutex_unlock(mtx);
        return 0;
}

void rtdlog_show_history_keylog(char * buf, int len)
{
        int ofs = 0;
        int tmp_ofs = 0;

        if(len > RTD_LOGBUF_KEYLOG_SIZE){
                len = RTD_LOGBUF_KEYLOG_SIZE;
        }

        printk(KERN_ERR "------dump history keylog start------\n");
        while(ofs < len){
                if(*(buf+ofs) == '\n'){
                        *(buf+ofs) = '\0';
                        printk(KERN_ERR "%s\n", buf+tmp_ofs);
                        *(buf+ofs) = '\n';
                        tmp_ofs = ofs+1;
                }
                ofs++;
        }
        printk(KERN_ERR "------dump history keylog end------\n");
}


int init_rtd_keylog_buf(void)
{
        struct mutex * mtx = &keylog_mutex;

        mutex_lock(mtx);
        rtd_keylog_pos = 0;
        rtd_keylog_last_pos = 0;
        rtd_keylog_addr = (unsigned char *)(phys_to_virt(RTD_LOGBUF_PHY_START_ADDR + RTD_LOGBUF_KEYLOG_OFFSET));
        rtd_printk(KERN_WARNING,RTDLOG_TAG,"keylog start addr : 0x%08x, size:0x%x\n", (RTD_LOGBUF_PHY_START_ADDR + RTD_LOGBUF_KEYLOG_OFFSET), RTD_LOGBUF_KEYLOG_SIZE);

        //dump_ddr_range("keylog before compare:", rtd_keylog_addr, 0x100);
        *(rtd_keylog_addr+RTD_LOGBUF_KEYLOG_SIZE-1) = '\0';     // for strlen
        if(strncmp(rtd_keylog_addr, RTD_KEYLOG_MAGIC, strlen(RTD_KEYLOG_MAGIC)) == 0){        // reset, backup history keylog pos.
                rtd_keylog_pos = strlen(rtd_keylog_addr);
                rtd_keylog_last_pos = rtd_keylog_pos;
        }

        // add this boot keylog magic string
        snprintf((rtd_keylog_addr+rtd_keylog_pos), RTD_LOGBUF_KEYLOG_SIZE-rtd_keylog_pos-1 , "%s", RTD_KEYLOG_MAGIC);
        rtd_keylog_pos = strlen(rtd_keylog_addr);
        mutex_unlock(mtx);
        return 0;
}

int reset_rtd_keylog_buf(void)
{
        char * keylog_tmp_buf = NULL;  // store this boot keylog after init
        int ret = 0;
        int new_keylog_len; // this boot keylog len
        struct mutex * mtx = &keylog_mutex;

        mutex_lock(mtx);
        new_keylog_len = strlen(rtd_keylog_addr)-rtd_keylog_last_pos;
        if((new_keylog_len -strlen(RTD_KEYLOG_MAGIC))<= 0){        // this boot keylog len except magic string
                ret = 1;
                goto reset;
        }

        keylog_tmp_buf = kmalloc(new_keylog_len+1, GFP_KERNEL);
        if(keylog_tmp_buf == NULL){
                rtd_printk(KERN_ERR,RTDLOG_TAG,"kmalloc fail!![%s]\n", __FUNCTION__);
                ret = -1;
                goto reset;
        }
        memset(keylog_tmp_buf, 0, new_keylog_len+1);
        // backup this boot keylog
        memcpy(keylog_tmp_buf, rtd_keylog_addr+rtd_keylog_last_pos, new_keylog_len);    // backup this boot keylog to malloc buffer
        memset(rtd_keylog_addr+rtd_keylog_last_pos,0,new_keylog_len); // clear this boot keylog. for dump history keylog
        // show history keylog
        rtdlog_show_history_keylog(rtd_keylog_addr, strlen(rtd_keylog_addr));
        // save this boot keylog
        memset(rtd_keylog_addr, 0, RTD_LOGBUF_KEYLOG_SIZE);     // clear buffer
        snprintf(rtd_keylog_addr, RTD_LOGBUF_KEYLOG_SIZE-1 , "%s", keylog_tmp_buf);     // save keylog to buffer

        goto RET;

reset:
        // reset keylog buffer
        memset(rtd_keylog_addr+rtd_keylog_last_pos, 0, 1); // clear magic string. for dump history keylog
        rtdlog_show_history_keylog(rtd_keylog_addr, strlen(rtd_keylog_addr));    //show history keylog
        memset(rtd_keylog_addr, 0, RTD_LOGBUF_KEYLOG_SIZE);
        snprintf(rtd_keylog_addr, RTD_LOGBUF_KEYLOG_SIZE-1 , "%s", RTD_KEYLOG_MAGIC);

RET:
        rtd_keylog_last_pos = 0;
        rtd_keylog_pos = strlen(rtd_keylog_addr);
        mutex_unlock(mtx);

        // free tmp buf
        if(keylog_tmp_buf){
                kfree(keylog_tmp_buf);
                keylog_tmp_buf = NULL;
        }
        return ret;

}

/*------------------------------------------------------------------------------------------
----------------------------------------logbuf init related-------------------------------------
------------------------------------------------------------------------------------------*/
#define RTD_LOGBUF_DEFLAUT_DIR "/tmp/var/log/"
#define RTD_INTEGRATION_LOG_FILE_NAME "rtd_logfile.log" //rtd log file name
#define LOG_FILE_BACKUP_NAME_NAME "rtd_logfile.log.gz"
#define RTD_REBOOT_DATA_FILE_NAME "rtd_prelogbuf.bin"
#define RTD_REBOOT_LOG_FILE_NAME  "rtd_prelogbuf.log"
#define LOG_DUMP_FILE_NAME "rtd_logbuf.bin"
#define RTD_ACPU1_FILE_NAME "rtd_acpu1.log"
#define RTD_ACPU2_FILE_NAME "rtd_acpu2.log"
#define RTD_VCPU1_FILE_NAME "rtd_vcpu1.log"
#define RTD_VCPU2_FILE_NAME "rtd_vcpu2.log"

#define LOG_FILE_MAX_SIZE 0x2000000 //32M
#define LOG_FILE_MAX_SIZE_BIG 0x2000000 //32M
#define LOG_FILE_MAX_SIZE_SMALL 0x400000 //8M
#define FW_LOG_MAX_SIZE_BIG 0X400000       // 4M
#define FW_LOG_MAX_SIZE_SMALL 0x100000        // 1M

#define RTD_HEADER_BIT  1       //header bit enable
#define RTD_WRAP_BIT  2 //wrap bit enable
#define RTD_SIZE_BIT 4  //size bit enable
#define RTD_ENABLE_BIT  8       //enable bit enable

#define RTD_LOGFILE_OFFSET 28
#define RTD_LOGFILE_AVLOG_OFFSET 1      //rtd_logfile.log contain A/V log bit offset
#define RTD_FWFILE_OFFSET 4
#define RTD_HEADER_OFFSET 0     //header bit offset
#define RTD_WRAP_OFFSET 1       //wrap bit offset
#define RTD_SIZE_OFFSET 2       //size bit offset
#define RTD_ENABLE_OFFSET 3     //enable bit offset

#define LOGBUF_DIR_MAX_SIZE  256
#define K 1024

static char  logbuf_dir[LOGBUF_DIR_MAX_SIZE] = RTD_LOGBUF_DEFLAUT_DIR;
static unsigned long bootcode_args;
static unsigned long bootcode_args_logfile;
static unsigned long bootcode_args_logfile_enable = 0;
static unsigned long bootcode_args_total_filesize;
static int bootcode_args_total_filesize_enable = 0;

static void catfilter_setup(void)
{
        //memset(&cat_filter, 0, sizeof(cat_filter));

        cat_filter.buf_cat = 0;
        //cat_filter.buf_mask = 0;
        //ACPU1 BUF
        cat_filter.sub_mask[ACPU1_BUF].core_mask = 0x0;
        cat_filter.sub_mask[ACPU1_BUF].level = 7;
        cat_filter.sub_mask[ACPU1_BUF].module_mask = 0xFFFFFFFF;
        //ACPU2 BUF
        cat_filter.sub_mask[ACPU2_BUF].core_mask = 0x0;
        cat_filter.sub_mask[ACPU2_BUF].level = 7;
        cat_filter.sub_mask[ACPU2_BUF].module_mask = 0xFFFFFFFF;
        //VCPU BUF
        cat_filter.sub_mask[VCPU1_BUF].core_mask = 0x0;
        cat_filter.sub_mask[VCPU1_BUF].level = 4;
        cat_filter.sub_mask[VCPU1_BUF].module_mask = 0xFFFFFFFF;
        //VCPU2 BUF
        cat_filter.sub_mask[VCPU2_BUF].core_mask = 0x0;
        cat_filter.sub_mask[VCPU2_BUF].level = 4;
        cat_filter.sub_mask[VCPU2_BUF].module_mask = 0xFFFFFFFF;
        //KCPU BUF
        cat_filter.sub_mask[KCPU_BUF].core_mask = 0x0;
        cat_filter.sub_mask[KCPU_BUF].level = 7;
        cat_filter.sub_mask[KCPU_BUF].module_mask = 0xFFFFFFFF;
        //KERNEL BUF
        cat_filter.sub_mask[KERNEL_BUF].core_mask = 0x0;
        cat_filter.sub_mask[KERNEL_BUF].level = 7;
        cat_filter.sub_mask[KERNEL_BUF].module_mask = 0xFFFFFFFF;
        //HAL BUF
        cat_filter.sub_mask[HAL_BUF].core_mask = 0x0;
        cat_filter.sub_mask[HAL_BUF].level = 5;
        cat_filter.sub_mask[HAL_BUF].module_mask = 0xFFFFFFFF;
}

#define RTD_MAX_CORE 4
static int check_log_filter(EnumLogbufType type, u8 level, u8 core, u32 module)
{
        int ret = 0;

        if((1 << type)&log_filter.buf_mask) {
                if(level <= log_filter.level_mask){
                        ret = 0;
                }else{
                        ret = -1;
                }
        } else {
                if(level > log_filter.sub_mask[type].level) {
                        ret = -1;
                }else if((~(log_filter.sub_mask[type].module_mask)) & module) {
                        ret = -1;
                }else if(core < RTD_MAX_CORE){
                        if(log_filter.sub_mask[type].core_mask & (1 << core)) {
                                ret = -1;
                        }
                }
        }

        return ret;
}

static int check_cat_filter(EnumLogbufType type, u8 level, u8 core, u32 module)
{
        int ret = 0;

        if((1 << type)&cat_filter.buf_mask) {
                ret = -1;
        } else {
                if(level > cat_filter.sub_mask[type].level) {
                        ret = -1;
                } else if(cat_filter.sub_mask[type].core_mask & (1 << core)) {
                        ret = -1;
                } else if((~(cat_filter.sub_mask[type].module_mask)) & module) {
                        ret = -1;
                }
        }

        return ret;
}

static int check_version_and_magic(logbuf_global_status * status)
{
        if(status->version != RTD_LOGBUF_VERSION){
                rtd_printk(KERN_ERR,RTDLOG_TAG,"rtd logbuf version mismatch. global version:%d, kernel version:%d",status->version,RTD_LOGBUF_VERSION);
                return -1;
        }
        if((status->magic_seg1 != RTD_LOGBUF_MAGIC_1)||
                (status->magic_seg2 != RTD_LOGBUF_MAGIC_2)||
                (status->magic_seg3 != RTD_LOGBUF_MAGIC_3)||
                (status->magic_seg4 != RTD_LOGBUF_MAGIC_4))
        {
                rtd_printk(KERN_ERR,RTDLOG_TAG,"rtd logbuf magic mismatch. global magic:%08x-%08x-%08x-%08x, kernel magic:%08x-%08x-%08x-%08x",
                status->magic_seg1,status->magic_seg2,status->magic_seg3,status->magic_seg4,
                RTD_LOGBUF_MAGIC_1,RTD_LOGBUF_MAGIC_2,RTD_LOGBUF_MAGIC_3,RTD_LOGBUF_MAGIC_4);
                return -1;
        }

        return 0;
}

static int check_bufsize(logbuf_global_status * status)
{
#ifdef CONFIG_64BIT
        logbuf_rbcb * pRbcb = (phys_to_virt(status->rbcb_addr[MAX_LOGBUF_NUM-1] + RTD_LOGBUF_RBCB_OFFSET_64));
#else
        logbuf_rbcb * pRbcb = (phys_to_virt(status->rbcb_addr[MAX_LOGBUF_NUM-1]));
#endif
        rtdlog_kfifo *fifo = &(pRbcb->fifo);
        unsigned long bufsize_rbcb;

        bufsize_rbcb = (unsigned long)(fifo->buffer+fifo->size - RTD_LOGBUF_PHY_START_ADDR);

        if(bufsize_rbcb != rtdlog_bufsize){
                rtd_printk(KERN_ERR,RTDLOG_TAG,"pRbcb->fifo.buffer:%p,fifo.size:%lx\n", fifo->buffer, (unsigned long)fifo->size);
                rtd_printk(KERN_ERR,RTDLOG_TAG,"rtd logbuf bufsize mismatch. global bufsize:%lx, cmdline bufsize:%lx\n",bufsize_rbcb,rtdlog_bufsize);
                return -1;
        }else{
                //rtd_printk(KERN_ERR,RTDLOG_TAG,"buf size check OK!global bufsize:%x, cmdline bufsize:%x\n", bufsize_rbcb, rtdlog_bufsize);
                return 0;
        }
}

void update_rtdlog_timestamp(void)
{
        if(is_setup_rtd_logbuf)
        {
                *gpRtdlogTimestamp = local_clock();
        }
}

static void init_rtd_buffer(logbuf_global_status * status)
{
        unsigned long * native_logbuf_saver;
        int i;

        //init rtd log buf
        gpRtdlogTimestamp = &(status->nsec);

        //init rbcb info and sema_addr
        for(i = 0; i < MAX_LOGBUF_NUM; ++i) {
#ifdef CONFIG_64BIT
                pRtdLogCB_32[i] = phys_to_virt(status->rbcb_addr[i]);
                pRtdLogCB[i] = phys_to_virt(status->rbcb_addr[i] + RTD_LOGBUF_RBCB_OFFSET_64);
#else
                pRtdLogCB[i] = phys_to_virt(status->rbcb_addr[i]);
#endif  // #ifdef CONFIG_64BIT
                array_fifo[i] = &(pRtdLogCB[i]->fifo);
                //dump kfifo
                rtd_printk(KERN_WARNING,RTDLOG_TAG,"KFIFO[%d]_INIT:buf(%08lx),size(%08lx),in(%08lx),out(%08lx)\n",
                        i,(unsigned long)(array_fifo[i]->buffer),(unsigned long)(array_fifo[i]->size), (unsigned long)(array_fifo[i]->in),(unsigned long)(array_fifo[i]->out));
        }

        //write native log buf addr in param area
        native_logbuf_saver = (unsigned long *)phys_to_virt(RTD_LOGBUF_PHY_START_ADDR+RTD_LOGBUF_DEFAULT_PARAM-8);
        *native_logbuf_saver = (unsigned long)(native_logbuf_addr - PAGE_OFFSET);
        rtd_printk(KERN_WARNING,RTDLOG_TAG,"native logbuf addr : 0x%08lx, CONFIG_PAGE_OFFSET : 0x%08lx\n",(unsigned long)native_logbuf_addr,PAGE_OFFSET);
}
#if 0
static int __init parse_rtdlog_boot_param(char *str)
{
        unsigned long val;

        if (kstrtoul(str, 16, &val)) {
        	//rtd_printk(KERN_ERR,RTDLOG_TAG,"invalid bootcode_args parameter '%s'\n", str);
        	return -1;
        }
        bootcode_args = val;
	//rtd_printk(KERN_ERR,RTDLOG_TAG,"setting bootcode_args to 0x%08x(from logswi=%s)\n", bootcode_args,str);

        if(bootcode_args & (1<<ARG_VALID))
        {
                if(bootcode_args & (1<<ARG_MSG_A1_EN))
                {
                        acpu1_rtdlb_dmesg_en = 1;
                }
                else
                {
                        acpu1_rtdlb_dmesg_en = 0;
                }

                if(bootcode_args & (1<<ARG_MSG_A2_EN))
                {
                        acpu2_rtdlb_dmesg_en = 1;
                }
                else
                {
                        acpu2_rtdlb_dmesg_en = 0;
                }

                if(bootcode_args & (1<<ARG_MSG_V1_EN))
                {
                        vcpu1_rtdlb_dmesg_en = 1;
                }
                else
                {
                        vcpu1_rtdlb_dmesg_en = 0;
                }

                if(bootcode_args & (1<<ARG_MSG_V2_EN))
                {
                        vcpu2_rtdlb_dmesg_en = 1;
                }
                else
                {
                        vcpu2_rtdlb_dmesg_en = 0;
                }

                if(bootcode_args & (1<<ARG_MSG_K_EN))
                {
                        kcpu_rtdlb_dmesg_en = 1;
                }
                else
                {
                        kcpu_rtdlb_dmesg_en = 0;
                }

                if(bootcode_args & (1<<ARG_MSG_HAL_EN))
                {
                        hal_rtdlb_dmesg_en = 1;
                }
                else
                {
                        hal_rtdlb_dmesg_en = 0;
                }

                rtdlog_file_en = (bootcode_args & (1<<ARG_LOG_FILE_EN)) >> ARG_LOG_FILE_EN;

                log_filter.buf_mask = ~(u8)((bootcode_args>>8)&0x7f);
        }

        //rtd_printk(KERN_INFO, RTDLOG_TAG,"parse bootcode args finish!\n");

        return 0;
}
__setup("logswi=", parse_rtdlog_boot_param);
#endif
static void sleep_sec(int sec)
{
        int i=0;

        for(i=0; i<sec; i++){
                msleep(1000);
        }
}

static int rtd_create_logdir_path(void)
{
        int err = sys_mkdir(logbuf_dir, 0644);
        if(err < 0){
                rtd_printk( KERN_WARNING, RTDLOG_TAG, "Try to create %s Failed, err=%d\n", logbuf_dir, err);
        }
        return err;
}

static void rtd_check_logdir_path(void)
{
        int ret;
        int i;

        for(i=0;i<3;i++){
                ret = sys_access((const char __user *) logbuf_dir, 0);
                if(ret ==0){
                        break;
                }
                msleep(2000);
                rtd_printk( KERN_WARNING, RTDLOG_TAG, "access rtd_logfile ret=%d\n", ret);
        }
        if(ret !=0){
                ret = rtd_create_logdir_path();
                if(ret < 0){
                        memset(logbuf_dir,0,LOGBUF_DIR_MAX_SIZE);
                        sprintf(logbuf_dir,"%s","/tmp/");
                }
        }
        rtd_printk( KERN_WARNING, RTDLOG_TAG, "log path=%s\n", logbuf_dir);
}

void rtd_save_previous_logfile(char * file_full_path)
{
        int ret =0;
        char * envp[] = {NULL};
        char path_gzip[] = "/system/bin/gzip";
        char * argv_gzip[] = {path_gzip,file_full_path, NULL};

        ret = sys_access((const char __user *) file_full_path, 0);

        if(ret==0){        //exit last_time_logfile
                //tar bkup file, use gzip compress
                ret = call_usermodehelper(path_gzip, argv_gzip, envp, UMH_WAIT_PROC);
                if(ret < 0) {
                        rtd_printk( KERN_WARNING, RTDLOG_TAG, "gzip previous log fail...ret=%d\n",ret );
                } else {
                        rtd_printk( KERN_WARNING, RTDLOG_TAG, "gzip previous log ok\n");
                }
        }
}

int rtd_creat_rtdfile(char *file_path, struct file ** file_fd, EnumLogbufType type)
{
        int retry_cnt = 0;

        if(!file_path){
                *(file_fd)=NULL;
                return -1;
        }

file_open:
        if(type == MAX_LOGBUF_NUM){
                *(file_fd) = filp_open(file_path, O_RDWR | O_APPEND | O_CREAT | O_TRUNC, 0644);
        }else{
                *(file_fd) = filp_open(file_path, O_RDWR | O_CREAT, 0644);
        }
        if (IS_ERR(gFileInfo.logfile_fd))
        {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "retry opening file %s(%lu,0x%08lx)\n", file_path, (unsigned long)*(file_fd), (unsigned long)*(file_fd));
                gFileInfo.logfile_fd = NULL;
                msleep(2000);
                retry_cnt++;
                if(retry_cnt < 3)
                {
                        goto file_open;
                }
                else
                {
                        retry_cnt = 0;
                }
        }
        else
        {
                //rtd_printk(KERN_INFO, RTDLOG_TAG, "opening file %s OK(%d,0x%08x)!\n", file_path, (int)*(file_fd), (unsigned int)*(file_fd));
                return 0;
        }
        return -1;

}
int rtd_init_logfile_path(void)
{
        int i = 0;
        char log_file_path[LOGBUF_DIR_MAX_SIZE] = {0};
        char *fw_file_path[MAX_LOGBUF_NUM]; //logfile path
        char * fw_filename[MAX_LOGBUF_NUM] =
        {
                RTD_ACPU1_FILE_NAME,
                RTD_ACPU2_FILE_NAME,
                RTD_VCPU1_FILE_NAME,
                RTD_VCPU2_FILE_NAME,
                NULL,
                NULL,
                NULL
        };
        int logbuf_dir_len = strlen(logbuf_dir);

        //logfile
        memset(log_file_path, 0, LOGBUF_DIR_MAX_SIZE);
        snprintf(log_file_path,LOGBUF_DIR_MAX_SIZE-strlen(RTD_INTEGRATION_LOG_FILE_NAME),"%s%s",logbuf_dir,RTD_INTEGRATION_LOG_FILE_NAME);
        //rtd_printk(KERN_INFO, RTDLOG_TAG, "file path=%s\n",log_file_path);
        rtd_save_previous_logfile(log_file_path);       //save previous rtd_logfile.log

        if(rtd_creat_rtdfile(log_file_path, &(gFileInfo.logfile_fd),MAX_LOGBUF_NUM)){
                return -1;              //create fail
        }

        //fw log file
        for(i=0; i<MAX_LOGBUF_NUM; i++){
#ifndef RTDLOG_AVCPU2
                if((i==ACPU2_BUF) || (i==VCPU2_BUF)){
                        continue;
                }
#endif
                if(fw_filename[i] == NULL){
                        continue;
                }

                fw_file_path[i] = kmalloc(logbuf_dir_len + strlen(fw_filename[i]) + 1, GFP_KERNEL);     // 1: for '\0'
                if(fw_file_path[i] == NULL){
                        rtd_printk(KERN_ERR, RTDLOG_TAG, "kmalloc %s fail\n",fw_filename[i]);
                        return -1;
                }
                memset(fw_file_path[i], 0, logbuf_dir_len + strlen(fw_filename[i]) + 1);
                sprintf(fw_file_path[i], "%s%s", logbuf_dir, fw_filename[i]);
                //rtd_printk(KERN_ERR, RTDLOG_TAG, "file path=%s\n",fw_file_path[i]);
                rtd_save_previous_logfile(fw_file_path[i]);     //save previous fw file
                if(rtd_creat_rtdfile(fw_file_path[i], &(gFileInfo.fwfile_fd[i]),i)){
                        return -1;
                }

                kfree(fw_file_path[i]);
        }
        return 0;
}

#ifdef CONFIG_RTK_USBDUMP_ENABLE
int rtk_get_usb_path(char *buf);

static void rtd_parse_usb_path(void)
{
        char buf[LOGBUF_DIR_MAX_SIZE] = {0};

        memset(logbuf_dir,0,LOGBUF_DIR_MAX_SIZE);
        while(rtk_get_usb_path(buf)){
                sleep_sec(5);
                rtd_printk(KERN_WARNING,RTDLOG_TAG,"wait for usb mount\n");
        }
        snprintf(logbuf_dir,LOGBUF_DIR_MAX_SIZE-1, "%s%s", buf,"/");
        rtd_printk(KERN_ERR,RTDLOG_TAG,"usb_path=%s \n",logbuf_dir);
}
#else
static void rtd_parse_usb_path(void)
{
        while(1){
                sleep_sec(5);
                rtd_printk(KERN_WARNING,RTDLOG_TAG,"usbdump function closed\n");
        }
}
#endif

int rtk_get_log_path(char *buf)
{
        if(strlen(logbuf_dir)==0){
                return -1;
        }
        memcpy(buf,logbuf_dir,sizeof(logbuf_dir)-1);
        return 0;
}
#if 0
static int __init parse_rtdlog_boot_param_logdir(char *str)
{
        int str_len = strlen(str);

        if(str_len >= LOGBUF_DIR_MAX_SIZE){
                rtd_printk( KERN_WARNING, RTDLOG_TAG, "\n\n======[ERR]bootcode_arg logdir len %d beyong %d!!!======\n\n", str_len, LOGBUF_DIR_MAX_SIZE);
                return -1;
        }
        memset(logbuf_dir,0,LOGBUF_DIR_MAX_SIZE);
        strcat(logbuf_dir,str);
        logbuf_dir[LOGBUF_DIR_MAX_SIZE-1] = 0;
        return 0;
}
__setup("logdir=", parse_rtdlog_boot_param_logdir);
#endif
/*------------------------bootcode argment logfile init relate------------*/

typedef struct FwFilesizeBoot{
        unsigned long filesize;
        bool set;
}FwFilesizeBoot;

static FwFilesizeBoot bootcode_args_fw_filesize[MAX_LOGBUF_NUM];

#if 0
static int rtdlog_get_boot_param_filesize(EnumLogbufType type, char *str)
{
        unsigned long val;

        if (kstrtoul(str, 16, &val)) {
                rtd_printk(KERN_ERR,RTDLOG_TAG,"invalid bootcode_args parameter '%s'\n", str);
                return -1;
        }
        if(type == MAX_LOGBUF_NUM){
                bootcode_args_total_filesize_enable = 1;
                bootcode_args_total_filesize = val;
        }else{
                bootcode_args_fw_filesize[type].filesize = val;
                bootcode_args_fw_filesize[type].set = 1;
        }
        return 0;
}

static int __init parse_rtdlog_boot_param_total_filesize(char *str)
{
        return rtdlog_get_boot_param_filesize(MAX_LOGBUF_NUM, str);
}
__setup("total_filesize=", parse_rtdlog_boot_param_total_filesize);

static int __init parse_rtdlog_boot_param_a1_filesize(char *str)
{
        return rtdlog_get_boot_param_filesize(ACPU1_BUF, str);
}
__setup("a1_filesize=", parse_rtdlog_boot_param_a1_filesize);

static int __init parse_rtdlog_boot_param_a2_filesize(char *str)
{
        return rtdlog_get_boot_param_filesize(ACPU2_BUF, str);
}
__setup("a2_filesize=", parse_rtdlog_boot_param_a2_filesize);


static int __init parse_rtdlog_boot_param_v1_filesize(char *str)
{
        return rtdlog_get_boot_param_filesize(VCPU1_BUF, str);
}
__setup("v1_filesize=", parse_rtdlog_boot_param_v1_filesize);

static int __init parse_rtdlog_boot_param_v2_filesize(char *str)
{
        return rtdlog_get_boot_param_filesize(VCPU2_BUF, str);
}
__setup("v2_filesize=", parse_rtdlog_boot_param_v2_filesize);
#endif

int rtd_is_tmp_dir(void)
{
        return strncmp("/tmp/",logbuf_dir,strlen("/tmp/"));
}

void rtd_init_filesize_default(unsigned long dir_size)
{
        int i;

        gFileInfo.logfile_max_size = ((dir_size -0x400000)*5)/10;

        for(i=0; i<MAX_LOGBUF_NUM; i++)
        {
                gFileInfo.fwfile_max_size[i]= FW_LOG_MAX_SIZE_SMALL;
                rtd_printk(KERN_ERR, RTDLOG_TAG, "fwfile[%d]=0x%lx\n",i, gFileInfo.fwfile_max_size[i]);
        }
}

int get_root_dir(char *str_path, char *str_root)
{
        char *find = NULL;

        if(*(str_path) != '/')
        {
                return -1;
        }

        find = strchr(str_path+1,'/');
        if(find == NULL){
                return -1;
        }

        strncpy(str_root,str_path,find-str_path);
        //rtd_printk(KERN_ERR, RTDLOG_TAG,"root_dir =%s\n",str_root);
        return 0;
}

unsigned long get_direction_free_size (void)
{
        struct statfs64 st;
        //long ret;
        unsigned int free_size=0;
        char  root_dir[LOGBUF_DIR_MAX_SIZE] = {0};
        mm_segment_t fs = get_fs();

        memset(root_dir, 0, LOGBUF_DIR_MAX_SIZE);
        get_root_dir(logbuf_dir, root_dir);

        set_fs(KERNEL_DS);
        if (sys_statfs64(root_dir, sizeof(st),&st)==0 )
        {
            free_size=st.f_bsize*st.f_bfree;
            rtd_printk( KERN_ERR, RTDLOG_TAG, "%s %d  get logfile dir's size (%s) \e[1;32mOK\e[0m\n\n\n\n\n",__func__,__LINE__,root_dir);
        }
        else
        {
            rtd_printk( KERN_ERR, RTDLOG_TAG, "%s %d  get logfile dir's size (%s) \e[1;31merror\e[0m\n\n\n\n\n",__func__,__LINE__,root_dir);
        }

        set_fs(fs);

        return free_size;
}
static void rtd_init_fw_filesize(unsigned long * fw_logfile_sum, unsigned long dir_size)
{
        int i;

        for(i=0; i<MAX_LOGBUF_NUM; i++)
        {
                if(gFileInfo.fwfile_fd[i] == NULL)
                        continue;

                gFileInfo.fwfile_max_size[i]= FW_LOG_MAX_SIZE_SMALL;       //default 1M

                if(bootcode_args_fw_filesize[i].set){
                        gFileInfo.fwfile_max_size[i] = bootcode_args_fw_filesize[i].filesize;
                }

                rtd_printk(KERN_INFO, RTDLOG_TAG, "fw[%d] filesize=%luk\n", i, gFileInfo.fwfile_max_size[i]/K);
                (*fw_logfile_sum) = (*fw_logfile_sum) + gFileInfo.fwfile_max_size[i];
        }
}
static void rtd_init_logfile_filesize(unsigned long dir_size)
{
        //char  root_dir[LOGBUF_DIR_MAX_SIZE] = {0};

         if(bootcode_args_total_filesize_enable == 1){        //boot arg set
                gFileInfo.logfile_max_size = bootcode_args_total_filesize;
                //rtd_printk(KERN_ERR, RTDLOG_TAG, "rtd_logfile.log set_value=%dK\n", bootcode_args_total_filesize/K);
         }else{
                if(dir_size > 0x400000){
                        gFileInfo.logfile_max_size = ((dir_size -0x400000)*5)/10;
                        rtd_printk(KERN_INFO, RTDLOG_TAG, "rtd_logfile.log dir_caculate_value=%luk,dirctory size=%luK\n", gFileInfo.logfile_max_size/K, dir_size/K);
                }else{
                        rtd_printk(KERN_WARNING, RTDLOG_TAG, "[warning]dirctory free size less 4M, size is=0x%lx\n", gFileInfo.logfile_max_size);
                        gFileInfo.logfile_max_size = LOG_FILE_MAX_SIZE_SMALL;
                }

                if(gFileInfo.logfile_max_size > LOG_FILE_MAX_SIZE){     // beyond  rtd_logfile.log max size
                        rtd_printk(KERN_WARNING, RTDLOG_TAG, "rtd_logfile.log caculate filesize(0x%lx) > max size(0x%x)\n", gFileInfo.logfile_max_size, LOG_FILE_MAX_SIZE);
                        gFileInfo.logfile_max_size = LOG_FILE_MAX_SIZE;
                }
        }
        rtd_printk(KERN_INFO, RTDLOG_TAG, "rtd_logfile filesize is %luK\n", gFileInfo.logfile_max_size/K);


}
static void rtd_init_filesize(void)
{
        unsigned long dir_size = 0;
        unsigned long fw_logfile_sum = 0;

        rtd_init_fw_filesize(&fw_logfile_sum, dir_size);
        //rtd_printk(KERN_ERR, RTDLOG_TAG,"fw_logfile_sum=%dK\n",fw_logfile_sum/K);

        dir_size = get_direction_free_size();   //get direction size
        rtd_init_logfile_filesize(dir_size);

        if(fw_logfile_sum + gFileInfo.logfile_max_size > dir_size){     //all logfile sum beyongd tmp filesize
                rtd_printk(KERN_WARNING, RTDLOG_TAG, "rtd_logfile filesize(%luK) + fw filesize sum(%luk) > dirctory filesize(%luK)\n", gFileInfo.logfile_max_size/K, fw_logfile_sum/K, dir_size/K);
                //rtd_init_filesize_default(dir_size);    //default setting
        }

}

void rtd_init_logfile_param(void)
{
        //unsigned int logfile_size;

        gFileInfo.logfile_param = 0;
        #if 0
        logfile_size = get_direction_free_size("/tmp");
        if(rtd_is_tmp_dir()==0){//logbuf_dir is /tmp/***
                gFileInfo.logfile_max_size = ((logfile_size -0x400000)*5)/10;
                rtd_printk(KERN_INFO, RTDLOG_TAG, "rtd_logfile(tmp_dir) size=0x%x\n", gFileInfo.logfile_max_size);
        }else{
                if(bootcode_args_logfile & (1 << (RTD_LOGFILE_OFFSET + RTD_SIZE_OFFSET))){           //size
                        gFileInfo.logfile_max_size = LOG_FILE_MAX_SIZE_BIG;
                }else{
                        gFileInfo.logfile_max_size = LOG_FILE_MAX_SIZE_SMALL;
                }
                rtd_printk(KERN_INFO, RTDLOG_TAG, "rtd_logfile(not tmp_dir) size=0x%x\n",gFileInfo.logfile_max_size);
        }
        #endif
        if(bootcode_args_logfile & (1 << (RTD_LOGFILE_OFFSET + RTD_HEADER_OFFSET))){    //header
                gFileInfo.logfile_param |= RTD_HEADER_BIT;
        }

}
void rtd_init_fwlog_param(void)
{
        int i=0;

        for(i=0; i<MAX_LOGBUF_NUM; i++)
        {
                //init all file header&wrap&enable
                gFileInfo.fwfile_param[i] = 0;
                if(bootcode_args_logfile & (1 << (i*RTD_FWFILE_OFFSET + RTD_HEADER_OFFSET))){
                        gFileInfo.fwfile_param[i] |= RTD_HEADER_BIT;   //header,bit:0
                }
                if(bootcode_args_logfile & (1 << (i*RTD_FWFILE_OFFSET+RTD_WRAP_OFFSET))){
                        gFileInfo.fwfile_param[i] |= RTD_WRAP_BIT;   //wrap,bit:1
                }
                #if 0
                if(bootcode_args_logfile & (1 << (i*RTD_FWFILE_OFFSET + RTD_SIZE_OFFSET ))){   //size,bit:2
                        gFileInfo.fwfile_max_size[i]= FW_LOG_MAX_SIZE_BIG;

                }else{
                        gFileInfo.fwfile_max_size[i]= FW_LOG_MAX_SIZE_SMALL;
                }
                #endif
                if(bootcode_args_logfile & (1 << (i*RTD_FWFILE_OFFSET+RTD_ENABLE_OFFSET ))){
                        gFileInfo.fwfile_param[i] |= RTD_ENABLE_BIT;   //enable,bit:3
                }
        }

}
/*
ret 1:rtd_logfile.log with avlog;
ret 0:rtd_logfile.log without avlog
*/
static int rtd_contain_avlog(EnumLogbufType type)
{
        int ret =1;
        int logfile_arg_enable  = bootcode_args_logfile & (1<<(RTD_LOGFILE_OFFSET + RTD_LOGFILE_AVLOG_OFFSET));

        if((!logfile_arg_enable) &&(type <=VCPU2_BUF)){
                ret = 0;
        }

        return ret;
}
/*
logfile_head_and_wrap:
bit0:header
bit1:wrap
bit2:size
bit3:enable
*/
void rtd_init_rtdlog_arg (void)
{
        //int i = 0;
        if(!bootcode_args_logfile_enable){
                bootcode_args_logfile = 0x9000aaaa;       // 9:enable argument. rtd_logfile.log header=1, a:A/V file enable=1,size=0,wrap=1,header=0
        }
        //rtd_printk(KERN_INFO, RTDLOG_TAG, "bootcode_args_logfile=0x%x\n", bootcode_args_logfile);

        rtd_init_filesize();
        //rtd_logfile.log(no enable and wrap)
        rtd_init_logfile_param();
        //fw log file
        rtd_init_fwlog_param();
}
#if 0
static int __init parse_rtdlog_boot_param_logfile (char *str)
{
        unsigned long val;
        //int i;

        if (kstrtoul(str, 16, &val)) {
        	//rtd_printk(KERN_ERR,RTDLOG_TAG,"invalid bootcode_args parameter '%s'\n", str);
        	return -1;
        }

        bootcode_args_logfile = val;
        if(bootcode_args_logfile & (1<<(RTD_LOGFILE_OFFSET + RTD_ENABLE_OFFSET)))       //enable bit
                bootcode_args_logfile_enable = 1;
        return 0;
}
__setup("logfile=", parse_rtdlog_boot_param_logfile);
#endif

static void rtd_show_boot_param(logbuf_cmdline * boot_param)
{
        rtd_printk( KERN_ERR, RTDLOG_TAG, "Boot param:\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "logdir: %s\n", boot_param->logdir);
        rtd_printk( KERN_ERR, RTDLOG_TAG,  "%s: 0x%08x   %s: 0x%08x   %s: 0x%-8x\n",
                "logswi",boot_param->logswi, "logfile",boot_param->logfile, "totalfile_size",boot_param->filesize.total_file);
        rtd_printk( KERN_ERR, RTDLOG_TAG,  "%-10s   %-8s   %-8s   %-8s   %-8s   %-8s   %-8s   %-8s\n"," ","ACPU1","ACPU2","VCPU1","VCPU2","KCPU","S-KER","HAL");
        rtd_printk( KERN_ERR, RTDLOG_TAG,  "%-10s 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x\n",
                "module",boot_param->log_filter.sub_mask[ACPU1_BUF].module_mask,boot_param->log_filter.sub_mask[ACPU2_BUF].module_mask,
                boot_param->log_filter.sub_mask[VCPU1_BUF].module_mask,boot_param->log_filter.sub_mask[VCPU2_BUF].module_mask,
                boot_param->log_filter.sub_mask[KCPU_BUF].module_mask,boot_param->log_filter.sub_mask[KERNEL_BUF].module_mask,
                boot_param->log_filter.sub_mask[HAL_BUF].module_mask);
        rtd_printk( KERN_ERR, RTDLOG_TAG,  "%-10s   %-8d   %-8d   %-8d   %-8d   %-8d   %-8d   %-8d\n",
                "level",boot_param->log_filter.sub_mask[ACPU1_BUF].level,boot_param->log_filter.sub_mask[ACPU2_BUF].level,
                boot_param->log_filter.sub_mask[VCPU1_BUF].level,boot_param->log_filter.sub_mask[VCPU2_BUF].level,
                boot_param->log_filter.sub_mask[KCPU_BUF].level,boot_param->log_filter.sub_mask[KERNEL_BUF].level,
                boot_param->log_filter.sub_mask[HAL_BUF].level);
        rtd_printk( KERN_ERR, RTDLOG_TAG,  "%-10s 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x\n",
                "core_mask",boot_param->log_filter.sub_mask[ACPU1_BUF].core_mask,boot_param->log_filter.sub_mask[ACPU2_BUF].core_mask,
                boot_param->log_filter.sub_mask[VCPU1_BUF].core_mask,boot_param->log_filter.sub_mask[VCPU2_BUF].core_mask,
                boot_param->log_filter.sub_mask[KCPU_BUF].core_mask,boot_param->log_filter.sub_mask[KERNEL_BUF].core_mask,
                boot_param->log_filter.sub_mask[HAL_BUF].core_mask);
        rtd_printk( KERN_ERR, RTDLOG_TAG,  "%-10s 0x%-8x 0x%-8x 0x%-8x 0x%-8x   %-8s   %-8s   %-8s\n",
                "filesize",boot_param->filesize.acpu1_file,boot_param->filesize.acpu2_file,boot_param->filesize.vcpu1_file,
                boot_param->filesize.vcpu2_file,"-","-","-");
}

static int rtd_check_magic_number(logbuf_cmdline * boot_param)
{
        if((boot_param->magic_seg1 != RTD_LOGBUF_MAGIC_1)||
                (boot_param->magic_seg2 != RTD_LOGBUF_MAGIC_2)||
                (boot_param->magic_seg3 != RTD_LOGBUF_MAGIC_3)||
                (boot_param->magic_seg4 != RTD_LOGBUF_MAGIC_4))
        {
                rtd_printk(KERN_ERR,RTDLOG_TAG,"rtd logbuf param magic mismatch. global magic:%08x-%08x-%08x-%08x, kernel magic:%08x-%08x-%08x-%08x",
                        boot_param->magic_seg1,boot_param->magic_seg2,boot_param->magic_seg3,boot_param->magic_seg4,
                        RTD_LOGBUF_MAGIC_1,RTD_LOGBUF_MAGIC_2,RTD_LOGBUF_MAGIC_3,RTD_LOGBUF_MAGIC_4);
                return -1;
        }

        return 0;
}


/* logswi */
static int rtd_get_param_logswi(logbuf_cmdline * boot_param)
{
        bootcode_args = boot_param->logswi;

        if(bootcode_args & (1<<ARG_VALID))
        {
                if(bootcode_args & (1<<ARG_MSG_A1_EN))
                {
                        acpu1_rtdlb_dmesg_en = 1;
                }
                else
                {
                        acpu1_rtdlb_dmesg_en = 0;
                }

                if(bootcode_args & (1<<ARG_MSG_A2_EN))
                {
                        acpu2_rtdlb_dmesg_en = 1;
                }
                else
                {
                        acpu2_rtdlb_dmesg_en = 0;
                }

                if(bootcode_args & (1<<ARG_MSG_V1_EN))
                {
                        vcpu1_rtdlb_dmesg_en = 1;
                }
                else
                {
                        vcpu1_rtdlb_dmesg_en = 0;
                }

                if(bootcode_args & (1<<ARG_MSG_V2_EN))
                {
                        vcpu2_rtdlb_dmesg_en = 1;
                }
                else
                {
                        vcpu2_rtdlb_dmesg_en = 0;
                }

                if(bootcode_args & (1<<ARG_MSG_K_EN))
                {
                        kcpu_rtdlb_dmesg_en = 1;
                }
                else
                {
                        kcpu_rtdlb_dmesg_en = 0;
                }

                if(bootcode_args & (1<<ARG_MSG_HAL_EN))
                {
                        hal_rtdlb_dmesg_en = 1;
                }
                else
                {
                        hal_rtdlb_dmesg_en = 0;
                }

                rtdlog_file_en = (bootcode_args & (1<<ARG_LOG_FILE_EN)) >> ARG_LOG_FILE_EN;

                log_filter.buf_mask = ~(u8)((bootcode_args>>8)&0x7f);
        }

        //rtd_printk(KERN_INFO, RTDLOG_TAG,"parse bootcode args finish!\n");

        return 0;
}

/* logswi */
static int rtd_get_param_logfile(logbuf_cmdline * boot_param)
{
        bootcode_args_logfile = boot_param->logfile;


        if(bootcode_args_logfile & (1<<(RTD_LOGFILE_OFFSET + RTD_ENABLE_OFFSET)))       //enable bit
                bootcode_args_logfile_enable = 1;
        return 0;

}

static int rtd_get_param_logdir(logbuf_cmdline * boot_param)
{
        memset(logbuf_dir,0,LOGBUF_DIR_MAX_SIZE);

        snprintf(logbuf_dir, LOGBUF_DIR_MAX_SIZE-1, boot_param->logdir);

        return 0;
}

static int rtd_get_param_filesize(logbuf_cmdline * boot_param)
{
        bootcode_args_total_filesize = boot_param->filesize.total_file;
        if(bootcode_args_total_filesize != 0){
                bootcode_args_total_filesize_enable = 1;
        }
        bootcode_args_fw_filesize[ACPU1_BUF].filesize = boot_param->filesize.acpu1_file;
        if(bootcode_args_fw_filesize[ACPU1_BUF].filesize != 0){
                bootcode_args_fw_filesize[ACPU1_BUF].set = 1;
        }
        bootcode_args_fw_filesize[ACPU2_BUF].filesize = boot_param->filesize.acpu2_file;
        if(bootcode_args_fw_filesize[ACPU2_BUF].filesize != 0){
                bootcode_args_fw_filesize[ACPU2_BUF].set = 1;
        }
        bootcode_args_fw_filesize[VCPU1_BUF].filesize = boot_param->filesize.vcpu1_file;
        if(bootcode_args_fw_filesize[VCPU1_BUF].filesize != 0){
                bootcode_args_fw_filesize[VCPU1_BUF].set = 1;
        }
        bootcode_args_fw_filesize[VCPU2_BUF].filesize = boot_param->filesize.vcpu2_file;
        if(bootcode_args_fw_filesize[VCPU2_BUF].filesize != 0){
                bootcode_args_fw_filesize[VCPU2_BUF].set = 1;
        }

        return 0;
}

static int rtd_get_param_logfilter(logbuf_cmdline * boot_param)
{
        memcpy(&log_filter, &(boot_param->log_filter), sizeof(rtdlog_filter));
        return 0;
}

static int rtd_get_boot_param(logbuf_cmdline * boot_param)
{
        if(rtd_check_magic_number(boot_param) < 0){
                return -1;
        }
        /*show*/
        rtd_show_boot_param(boot_param);
        /*get param*/
        rtd_get_param_logswi(boot_param);
        rtd_get_param_logfile(boot_param);
        rtd_get_param_logdir(boot_param);
        rtd_get_param_filesize(boot_param);
        rtd_get_param_logfilter(boot_param);

        return 0;
}

static int rtd_init_filepath(void)
{
        //logdir use USB path
        if(strcmp(logbuf_dir,"USB")==0){
                rtd_parse_usb_path();
        }
        rtd_check_logdir_path();
        if(rtd_init_logfile_path())    //init file path
        {
                return -1;
        }
        return 0;
}
/*
** setup rtd logbuf
*/
void rtdlog_setup(void)
{
        logbuf_global_status * global_status;
        logbuf_cmdline * boot_param = (logbuf_cmdline *)(phys_to_virt(RTD_LOGBUF_PHY_START_ADDR + RTD_LOGBUF_CMDLINE_OFFSET));
#if (defined(CONFIG_OPTEE) && !defined(CONFIG_CUSTOMER_TV006))
        struct optee_rpc_param rtc_set_info;
#endif

        global_status = (logbuf_global_status *)(phys_to_virt(RTD_LOGBUF_PHY_START_ADDR));
        boot_param = (logbuf_cmdline *)(phys_to_virt(RTD_LOGBUF_PHY_START_ADDR + RTD_LOGBUF_CMDLINE_OFFSET));

        if(check_version_and_magic(global_status)){
                return;
        }
        /* init logswi, logifle, logdir,  logfilter*/
        if(rtd_get_boot_param(boot_param)){
                return;
        }
        if(check_bufsize(global_status)){
                return;
        }

#if (defined(CONFIG_OPTEE) && !defined(CONFIG_CUSTOMER_TV006))
        optee_logbuf_setup_info_send(&rtc_set_info);
#endif

        init_rtd_buffer(global_status);

        //setup filter
        //logfilter_setup();
        catfilter_setup();

        //now rtd logbuf can be used
        is_setup_rtd_logbuf = true;

        save_early_log();       //parse&save early log in linux logbuf before now time
        is_save_early_log_done = true;

        // init keylog buffer
        init_rtd_keylog_buf();

        return;
}

static int rtd_logbuf_init(void)
{
        rtdlog_setup();

        if(!is_setup_rtd_logbuf){
                rtd_printk( KERN_ERR, RTDLOG_TAG, "rtd logbuf setup fail !!!\n");
                return -1;
        }

        if(rtd_init_filepath())
        {
                return -1;
        }
        rtd_init_rtdlog_arg();     //init logfile argument:enable, size, wrap, header
        return 0;
}

/*------------------------------------------------------------------------------------------
--------------------------------------logbuf write data related------------------------------------
------------------------------------------------------------------------------------------*/
#define ACPU1_TAG "ACPU1"
#define ACPU2_TAG "ACPU2"
#define VCPU1_TAG "VCPU1"
#define VCPU2_TAG "VCPU2"
#define KCPU_TAG "KCPU1"
#define HAL_TAG "S-HAL"

#define READ_THREAD_FORCE_SLEEP_LIMIT 20000 //unit:us, 100ms
#define READ_THREAD_FORCE_SLEEP_SPAN 80 //unit:ms, 400ms
#define RTD_BUFSIZE_512 512

static loff_t g_pos=0;
static unsigned char msg_tmp_buf[RTD_BUFSIZE_512];

static void dump_ddr_range(char * msg,void * start,unsigned int len)
{
    char buf[RTD_BUFSIZE_512];
    int i = 0,j = 0;
    unsigned char * tmp = start;

    printk(KERN_ERR"%s\n",msg);
    for(i = 0;i < len;++i)
    {
            if((i % 16 == 0)&&(i != 0))
            {
                buf[511] = 0;
                printk(KERN_ERR"%lx: %s\n",(unsigned long)(tmp-16),buf);
                j = 0;
            }
            if(j < sizeof(buf))
            {
                snprintf(&buf[j], RTD_BUFSIZE_512 - j," %02x", *tmp);
            }
            j += 3;
            tmp++;
    }

    if(i % 16 != 0)
    {
        buf[511] = 0;
        printk(KERN_ERR"%lx: %s\n",(unsigned long)(tmp-16),buf);
    }
}

int g_wait_ap=0;
int g_gzip_file = 0;
static int rtd_backup_log (loff_t size)
{
    int ret = -1;
    char buffer[LOGBUF_DIR_MAX_SIZE];
    char* gzip_cmd,* log_file_path ;

    memset(buffer, 0, LOGBUF_DIR_MAX_SIZE);
    snprintf(buffer,LOGBUF_DIR_MAX_SIZE, "gzip %s%s",logbuf_dir,RTD_INTEGRATION_LOG_FILE_NAME);

    //close file
    filp_close(gFileInfo.logfile_fd, NULL);

    msleep(g_wait_ap);      //wait AP copy
    rtd_printk( KERN_INFO, RTDLOG_TAG, "gzip sleep =%dms\n",g_wait_ap);

    mutex_lock(&rtd_logfile_lock);
    //rtd_printk( KERN_INFO, RTDLOG_TAG, "gzip lock\n");
    gzip_cmd=buffer;
    ret =exec_user_cmd(gzip_cmd);//tar bkup file, use gzip compress
    g_gzip_file = 1;
    //rtd_printk( KERN_INFO, RTDLOG_TAG, "gzip unlock\n");
    mutex_unlock(&rtd_logfile_lock);

    //create file
    memset(buffer, 0, LOGBUF_DIR_MAX_SIZE);
    snprintf(buffer,LOGBUF_DIR_MAX_SIZE, "%s%s",logbuf_dir,RTD_INTEGRATION_LOG_FILE_NAME);
    log_file_path=buffer;
    ret = rtd_creat_rtdfile(log_file_path, &(gFileInfo.logfile_fd),MAX_LOGBUF_NUM);
    return ret;
}


static int rtd_buffer_to_fwfile(char * text, int len,struct file * save_file,loff_t *ppos)
{
        int i = 0;
        int ret_len = 0;
        loff_t tmp_ppos = 0;

        for(i=0; i<MAX_LOGBUF_NUM; i++){
                if(gFileInfo.fwfile_fd[i] == NULL)
                        continue;

                if(save_file == gFileInfo.fwfile_fd[i]){

                        if(!(gFileInfo.fwfile_param[i] & RTD_ENABLE_BIT)){
                                return 0;
                        }
                        if(ppos == NULL)
                        {
                                ppos = &tmp_ppos;
                        }

                        if(*ppos >=gFileInfo.fwfile_max_size[i])
                        {
                                if(gFileInfo.fwfile_param[i] & RTD_WRAP_BIT){
                                        //vfs_write(save_file, "\n---end---\n", 11, ppos);
                                        *ppos = 0;
                                        ret_len = vfs_write(save_file, text, len, ppos);
                                }
                        }else{
                                ret_len = vfs_write(save_file, text, len, ppos);
                        }
                        return ret_len;
                }

        }
        return -1;

}
/*
** put text to file
*/
static int rtd_buffer_to_file(char * text, int len,struct file * save_file,loff_t *ppos)
{
        ssize_t ret_len;
        loff_t tmp_pos = 0;
        loff_t tmp_ppos = 0;

        if((len < 0) || (text == NULL) ||(save_file == NULL))
                return -1;

        //rtd_logfile.log
        if(save_file == gFileInfo.logfile_fd){
                if(!rtdlog_file_en){
                        return len;
                }

                ret_len = vfs_write(save_file, text, len, &tmp_pos);

                gDbgInfo.total_write_cnt++;

                if(ret_len != len) {
                        gDbgInfo.vfs_write_fail_cnt++;
                }

                if(tmp_pos >= gFileInfo.logfile_max_size) {
                        //rtd_printk( KERN_NOTICE, RTDLOG_TAG, "move log to backup file!\n");
                        rtd_backup_log(tmp_pos);
                }
                return ret_len;
        }

        //fw file
        if((ret_len=rtd_buffer_to_fwfile(text, len, save_file, ppos)) != -1){
                return ret_len;
        }

        // other file
        if(ppos == NULL)
        {
                ppos = &tmp_ppos;
        }
        ret_len = vfs_write(save_file, text, len, ppos);
        return ret_len;
}

static int rtd_write_fw_bin(EnumLogbufType type,char * text, int len)
{
        static loff_t fw_pos[MAX_LOGBUF_NUM];

        if((type>=MAX_LOGBUF_NUM) || (text==NULL)){
                return -1;
        }

        if(!gFileInfo.fwfile_fd[type]){
                return -2;
        }

        return rtd_buffer_to_file(text, len, gFileInfo.fwfile_fd[type], &fw_pos[type]);
}

/*
offset: offset of bootcode_arg logfile. rtd_logfile.log(8)/a.log(0,1)/v.log(2,3)

*/
int rtd_select_log_header (EnumLogbufType offset, rtd_msg_header * header, char *msg_tag, int pos)
{
        int len = 0;
        bool header_prama = 0;
        char *cpu_type_str[MAX_LOGBUF_NUM] = {
                "ACPU1",
                "ACPU2",
                "VCPU1",
                "VCPU2",
                "KCPU1",
                "S-KER",
                "S-HAL"
        };
        struct timeval log_time = ns_to_timeval((s64)header->timestamp);

        if((offset>MAX_LOGBUF_NUM) || (header == NULL) || (msg_tag == NULL)){
                return -1;
        }

        if(MAX_LOGBUF_NUM ==offset){
                header_prama = gFileInfo.logfile_param & RTD_HEADER_BIT;
        }else{
                header_prama = gFileInfo.fwfile_param[offset] & RTD_HEADER_BIT;
        }

        if(header_prama){//select simplfy(0) or detail log_tag(1)

                len = snprintf(msg_tag+pos, FILE_MSG_TAG_LEN - pos, "<%d>[%08d.%06d](%5s:",
                                header->level,
                                (int)log_time.tv_sec,//(u32)(header->timestamp>>32),
                                (int)log_time.tv_usec,//(u32)(header->timestamp&0xffffffff),
                                (char *)(cpu_type_str[header->cpu_type]));
                pos += len;

                if(header->cpu_core != 0xff) {
                        len = snprintf(msg_tag+pos, FILE_MSG_TAG_LEN - pos, "%d)",
                                       header->cpu_core);
                        pos += len;
                } else {
                        len = snprintf(msg_tag+pos, FILE_MSG_TAG_LEN - pos, "?)");
                        pos += len;
                }

                len = snprintf(msg_tag+pos, FILE_MSG_TAG_LEN - pos, "#%-15s#",
                header->name);
                pos += len;

                len = snprintf(msg_tag+pos, FILE_MSG_TAG_LEN - pos, "[%08x]: ",
                header->module);
                pos += len;

        }
        else{

                len = snprintf(msg_tag+pos, FILE_MSG_TAG_LEN - pos, "[%08d.%06d](%5s):",
                                (int)log_time.tv_sec,//(u32)(header->timestamp>>32),
                                (int)log_time.tv_usec,//(u32)(header->timestamp&0xffffffff),
                                (char *)(cpu_type_str[header->cpu_type]));
                pos += len;
        }
        return pos;


}

/*
** parse msg header to text
*/
static int output_logfile_msg_head(EnumLogbufType type,rtd_msg_header * header,struct file * save_file, int contain_avlog, char *wstat)
{
        char msg_tag[FILE_MSG_TAG_LEN] = {0};
        int pos = 0;

        if((type >= MAX_LOGBUF_NUM) || (wstat == NULL)){
                return -1;
        }
        if((!wstat[type]) && contain_avlog){
                pos = rtd_select_log_header(MAX_LOGBUF_NUM, header, msg_tag, pos);
                msg_tag[FILE_MSG_TAG_LEN - 1] = 0;
                rtd_buffer_to_file(msg_tag, pos,save_file,NULL);
        }
        return 0;
}
/*
** parse msg header to text
*/
static int output_fw_msg_head(EnumLogbufType type,rtd_msg_header * header)
{
        char msg_tag[FILE_MSG_TAG_LEN] = {0};
        int pos = 0;

        if(type >= MAX_LOGBUF_NUM){
                return -1;
        }

        pos = rtd_select_log_header(type, header, msg_tag, pos);
        msg_tag[FILE_MSG_TAG_LEN - 1] = 0;
        rtd_write_fw_bin(type,msg_tag, pos);

        return 0;
}

/*
** insert log drop tips
*/
static int output_logdrop_tip(EnumLogbufType type,unsigned int cnt)
{
        unsigned char tmp[64] = {0};
        char *cpu_type_str[MAX_LOGBUF_NUM] = {
                "[A1]",
                "[A2]",
                "[V1]",
                "[V2]",
                "[K]",
                "[Ker]",
                "[Hal]"
        };

        if(type >= MAX_LOGBUF_NUM){
                snprintf(tmp,sizeof(tmp),"********[output_logdrop_tip] Unknown type:%d.********\n", type);
        }else{
                snprintf(tmp,sizeof(tmp),"********type:%s drop %d logs here********\n", cpu_type_str[type],cnt);
        }
        tmp[sizeof(tmp)-1] = '\0';
        rtd_buffer_to_file(tmp,strlen(tmp),gFileInfo.logfile_fd,NULL);

        return 0;
}


static unsigned long cat_msg_head_process(EnumLogbufType type, char __user * buf)
{
        unsigned int copy_ret;

        char *cpu_type_str[MAX_LOGBUF_NUM] = {
                "[ACPU1] : ",
                "[ACPU2] : ",
                "[VCPU1] : ",
                "[VCPU2] : ",
                "[KCPU1] : ",
                "[S-KER] : ",
                "[S-HAL] : "
        };

        copy_ret = copy_to_user(buf,cpu_type_str[type],strlen(cpu_type_str[type]));

        return (strlen(cpu_type_str[type]) - copy_ret);
}

static unsigned int cat_msg_end_process(EnumLogbufType type, char * buf, unsigned int offset)
{
        unsigned int ret_len = 0;

        if(type == KERNEL_BUF)
        {
                buf[offset] = '\n';
                ret_len = 1;
        }

        return ret_len;
}

void insert_first_boot_tip(void)
{
        char * first_msg = "********[TIP] platform start********\n";
        rtd_buffer_to_file(first_msg,strlen(first_msg),gFileInfo.logfile_fd,NULL);
}

void insert_msg_err_tip(EnumLogbufType type)
{
        char* tip_msg = "********[TIP] msg error,sync kfifo out offset******** ";
        char type_msg[128];
        snprintf(type_msg,sizeof(type_msg),"type:%d\n",type);
        rtd_buffer_to_file(tip_msg,strlen(tip_msg),gFileInfo.logfile_fd,NULL);
        rtd_buffer_to_file(type_msg,strlen(type_msg),gFileInfo.logfile_fd,NULL);
}
void record_reboot_data(void)
{
        struct file *history_log_file = NULL;
        loff_t pos = 0;
        ssize_t ret_len;
        char history_log_name[LOGBUF_DIR_MAX_SIZE] = {0};
        unsigned char * addr = 0;
        int i = 0;
        mm_segment_t old_fs;

        old_fs = get_fs();
        set_fs(KERNEL_DS);

        rtd_printk( KERN_WARNING, RTDLOG_TAG, "begin to write log data\n\n\n\n");
#if 0
        if(((bootcode_args & ((unsigned long)1<<ARG_VALID)) == 0)||((bootcode_args & ((unsigned long)1<<ARG_REBOOT_LOG_EN)) == 0))
        {
                //rtd_printk( KERN_ERR, RTDLOG_TAG, "skip reboot log data...\n");
                return;
        }
#endif
        memset(history_log_name, 0, LOGBUF_DIR_MAX_SIZE);
        //sprintf(history_log_name,"%s%s",logbuf_dir,RTD_REBOOT_DATA_FILE_NAME);
        snprintf(history_log_name,LOGBUF_DIR_MAX_SIZE-strlen(RTD_REBOOT_DATA_FILE_NAME),"%s%s",logbuf_dir,RTD_REBOOT_DATA_FILE_NAME);
        //rtd_printk(KERN_INFO, RTDLOG_TAG, "file path=%s\n",history_log_name);

        rtd_save_previous_logfile(history_log_name);      //save last time pre_log.bin
        history_log_file = filp_open(history_log_name, O_RDWR | O_CREAT, 0644);
        if (IS_ERR(history_log_file))
        {
            rtd_printk( KERN_ERR, RTDLOG_TAG, "error occured while opening file %s(%ld,0x%08lx), exiting...\n", history_log_name, (long)history_log_file, (unsigned long)history_log_file);
            goto RET;
        }

        for(i = 0;i < MAX_LOGBUF_NUM;++i)
        {
                if(array_fifo[i]->out != 0)
                {
                        break;
                }
        }
        if(i >= MAX_LOGBUF_NUM)
        {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "no reboot log data...\n");
                goto RET;
        }

        addr = phys_to_virt(RTD_LOGBUF_PHY_START_ADDR);
        //copy logbuf data to log file
        pos = 0;
        ret_len = vfs_write(history_log_file, addr, rtdlog_bufsize, &pos);
        rtd_printk( KERN_ERR, RTDLOG_TAG, "vfs_write logbuf param_pre ret 0x%08x(%d),pos at 0x%08x\n",(unsigned int)ret_len,(unsigned int)ret_len,(unsigned int)pos);
        //copy logbuf param again(to avoid param too old for the log data)
        pos = 0;
        ret_len = vfs_write(history_log_file, addr, rtdlog_param_size, &pos);
        rtd_printk( KERN_ERR, RTDLOG_TAG, "vfs_write logbuf param_aft ret 0x%08x(%d),pos at 0x%08x\n",(unsigned int)ret_len,(unsigned int)ret_len,(unsigned int)pos);

        filp_close(history_log_file, NULL);
RET:
        set_fs(old_fs);
        return;
}
//get_msg_header retval
////1:PASS ; -1:VERIFY FAIL ; 0:EMPTY
int get_msg_header (EnumLogbufType type,rtd_msg_header* header,struct kfifo * pKfifo)
{
    struct kfifo * fifo;

    fifo = (pKfifo == NULL) ? array_fifo[type]: pKfifo;
    if (kfifo_len(fifo)> sizeof(rtd_msg_header))
    {
        kfifo_out_peek(fifo,header,sizeof(rtd_msg_header),0);

        if(check_msghead_valid(header))//if fail
        {
                kfifo_drop(fifo);
                gDbgInfo.log_reset_cnt[type]++;
                rtd_printk( KERN_ERR, RTDLOG_TAG, "type[%d] check msg header fail!\n",type);

                dump_ddr_range("dump header ddr",(void *)header,sizeof(rtd_msg_header));
                return -1;
        }
        else
        {
                return 1;
        }
    }

    return 0;
}

//RET VAL:
// 1:PASS ; -1:VERIFY FAIL; 0:EMPTY
int get_catmsg_header (EnumLogbufType type,rtd_msg_header* header)
{
    struct kfifo * fifo=array_fifo[type];
    if (kfifo_cat_len(fifo) > sizeof(rtd_msg_header))
    {
        kfifo_cat_out_peek(fifo,header,sizeof(rtd_msg_header),0);

        if(check_msghead_valid(header))//if fail
        {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "type[%d] check logcat msg header fail!\n",type);
                dump_ddr_range("dump header ddr",(void *)header,sizeof(rtd_msg_header));
                return -1;
        }
        else
        {
                return 1;
        }
    }
    else
    {
        //rtd_printk( KERN_ERR, RTDLOG_TAG, "FAIL:[%s](%d)...\n",__FUNCTION__,__LINE__);
    }

    return 0;
}

static int rtd_write_logfile(rtd_msg_header * header,unsigned char * buffer, int contain_avlog)
{
        int ret_len = header->text_len;

        if((header==NULL) || (buffer==NULL) ){
                return -1;
        }

        if(contain_avlog){
                ret_len = rtd_buffer_to_file(buffer+sizeof(rtd_msg_header), header->text_len,gFileInfo.logfile_fd,&g_pos);
        }
        return ret_len;
}

/*use printk to put log into dmesg*/
static void log_to_dmesg(EnumLogbufType type,char *ptr)
{
        switch(type)
        {
                case ACPU1_BUF:
                        if(acpu1_rtdlb_dmesg_en)
                        {
                                rtd_printk(KERN_ERR,ACPU1_TAG,"%s",ptr);
                        }
                break;
                case ACPU2_BUF:
                        if(acpu2_rtdlb_dmesg_en)
                        {
                                rtd_printk(KERN_ERR,ACPU2_TAG,"%s",ptr);
                        }
                break;
                case VCPU1_BUF:
                        if(vcpu1_rtdlb_dmesg_en)
                        {
                                rtd_printk(KERN_ERR,VCPU1_TAG,"%s",ptr);
                        }
                break;
                case VCPU2_BUF:
                        if(vcpu2_rtdlb_dmesg_en)
                        {
                                rtd_printk(KERN_ERR,VCPU2_TAG,"%s",ptr);
                        }
                break;
                case KCPU_BUF:
                        if(kcpu_rtdlb_dmesg_en)
                        {
                                rtd_printk(KERN_ERR,KCPU_TAG,"%s",ptr);
                        }
                break;
                case HAL_BUF:
                        if(hal_rtdlb_dmesg_en)
                        {
                                rtd_printk(KERN_ERR,HAL_TAG,"%s",ptr);
                        }
                break;

                default:
                break;
        }

        return;
}

void skip_msg_data (EnumLogbufType type,rtd_msg_header* header,struct kfifo * pKfifo)
{
    struct kfifo * fifo;

    fifo = (pKfifo == NULL) ? array_fifo[type]: pKfifo;
    if (kfifo_len(fifo)< header->len)
    {
        return ;
    }

    __kfifo_add_out(fifo, header->len);

    return ;
}

void skip_catmsg_data (EnumLogbufType type,rtd_msg_header* header)
{
    struct kfifo * fifo=array_fifo[type];

    if (kfifo_cat_len(fifo)< header->len)
    {
        return ;
    }

    __kfifo_cat_add_out(fifo, header->len);

    return ;
}

void write_msg_data (EnumLogbufType type,rtd_msg_header* header,struct kfifo * pKfifo)
{
    ssize_t ret_len;
    unsigned int out_len;
    struct kfifo * fifo;
    unsigned char * buffer;
    static unsigned char wstat[MAX_LOGBUF_NUM] = {0,0,0,0,0,0,0};//use this to against vfs_write() return 0
    int contain_av_log = rtd_contain_avlog(type);     //rtd_logfile.log contain A/V log

    if(type >= MAX_LOGBUF_NUM){
        return;
    }

    fifo = (pKfifo == NULL) ? array_fifo[type]: pKfifo;
    if (kfifo_len(fifo)< header->len)
    {
        return ;
    }

    if(header->len < sizeof(msg_tmp_buf))
    {
        buffer = msg_tmp_buf;
        memset(buffer,0,sizeof(msg_tmp_buf));
    }
    else
    {
        buffer = kmalloc(header->len,GFP_KERNEL);
        if (buffer == NULL){
            return ;
        }
        memset(buffer,0,header->len);
    }

    //kfifo_out(fifo,buffer,min(header->len,sizeof(buffer)));
    out_len = kfifo_out_peek(fifo,buffer,header->len,0); //copy out data

    if(gDbgInfo.drop_log_cnt[type] != pRtdLogCB[type]->drop_cnt)
    {
        output_logdrop_tip(type,pRtdLogCB[type]->drop_cnt - gDbgInfo.drop_log_cnt[type]);
        gDbgInfo.drop_log_cnt[type] = pRtdLogCB[type]->drop_cnt;
    }

    //write log_header to file-system
    output_logfile_msg_head(type, header, gFileInfo.logfile_fd, contain_av_log, wstat);
    output_fw_msg_head(type,header);

    //write log to file-system
    ret_len =  rtd_write_logfile(header, buffer, contain_av_log);
    rtd_write_fw_bin(type,buffer+sizeof(rtd_msg_header), header->text_len);

    /*************debug vfs_write start*************/
    if((ret_len != header->text_len)&&(ret_len >= 0)) //add ret_len >= 0,so remount ro fs will not print debug log crazily
    {
        rtd_printk(KERN_ERR,RTDLOG_TAG,"vfs_write ret:%d,file:%lx,buffer:%lx,%lx,header:%lx,len:%lx,pos:%llx\n",
                (unsigned int)ret_len,
                (unsigned long)gFileInfo.logfile_fd,
                (unsigned long)buffer,
                (unsigned long)buffer+sizeof(rtd_msg_header),
                (unsigned long)header,
                (unsigned long)header->text_len,
                g_pos);
        dump_ddr_range("dump header",header,sizeof(rtd_msg_header));
        dump_ddr_range("dump buffer",buffer,header->len);
        //panic("\n\nRTD LOGBUF vfs_write failed!\n\n");
    }
    /*************debug vfs_write  end *************/

    if((buffer[header->len - 1] != '\n')&&(!wstat[type]))
    {
        if(rtdlog_file_en && contain_av_log){
                rtd_buffer_to_file("\n", 1, gFileInfo.logfile_fd,NULL); //add '\n' for kernel log
        }
        rtd_write_fw_bin(type,"\n", 1);
    }


    if(ret_len == header->text_len)
    {
        log_to_dmesg(type,buffer+sizeof(rtd_msg_header));
        wstat[type] = 0;//write log ok
        __kfifo_add_out(fifo, out_len);//if write success,move out offset to next msg
    }
    else if(ret_len >= 0) //add ret_len >= 0,so remount ro fs will not print debug log crazily
    {
        wstat[type]++;//write log fail
        if(wstat[type] >= 10)
        {
            wstat[type] = 0;
            dump_ddr_range("skip 1 msg,dump header",header,sizeof(rtd_msg_header));
            output_logdrop_tip(type,1);
            __kfifo_add_out(fifo, out_len);//drop this msg
        }
    }else{      // ret < 0
        __kfifo_add_out(fifo, out_len);//drop this msg
    }

    //check len
    if (ret_len!= header->text_len)
    {
        gDbgInfo.vfs_write_fail_cnt++;
    }
    else
    {
        gDbgInfo.total_write_len += ret_len;
        gDbgInfo.total_write_cnt++;
    }

    if((buffer != msg_tmp_buf)&&(buffer != NULL))//free malloced buffer
    {
        kfree(buffer);
    }

    return ;
}

unsigned int write_catmsg_data (EnumLogbufType type,rtd_msg_header* header,char __user * buf)
{
    struct kfifo * fifo = array_fifo[type];
    unsigned int len,ret_len,offset,eoff;
    static char buffer[2048];

    if (kfifo_cat_len(fifo) < header->len)
    {
        rtd_printk( KERN_ERR, RTDLOG_TAG, "FAIL:[%s](%d)...\n",__FUNCTION__,__LINE__);
        return 0;
    }

    memset(buffer,0,sizeof(buffer));
    //kfifo_out(fifo,buffer,min(header->len,sizeof(buffer)));
    len = kfifo_cat_out(fifo, buffer, header->len);
    if(len >= sizeof(buffer))
    {
        len = sizeof(buffer) - 1;
    }

    eoff = cat_msg_end_process(type,buffer,len);
    //rtd_printk( KERN_ERR, RTDLOG_TAG, "kfifo_cat_out len:%d\n",len);

    //write log to file-system
    offset = cat_msg_head_process(type,buf);
    ret_len = copy_to_user(buf+offset, (void *)buffer+sizeof(rtd_msg_header), sizeof(buffer)-sizeof(rtd_msg_header));
    if(!ret_len)//if success,get real copy len
    {
        ret_len = len;
    }

    ret_len += eoff;
    ret_len += offset;

    //kfree(buffer);
    return ret_len;
}

int write_data (EnumLogbufType type,struct kfifo * pKfifo)
{
    rtd_msg_header header;
    int ret=0;

    int header_check = get_msg_header(type,&header,pKfifo);
    if (header_check == 1)
    {
        if(check_log_filter(type,header.level,header.cpu_core,header.module))
        {
                skip_msg_data(type,&header,pKfifo);
        }
        else
        {
                write_msg_data(type,&header,pKfifo);
                gDbgInfo.file_log_len[type] += header.text_len;
                gDbgInfo.file_log_cnt[type]++;
        }

        gDbgInfo.read_log_len[type] += header.text_len;
        gDbgInfo.read_log_cnt[type]++;

        ret =1;
        goto RET;
    }
    else if(header_check == -1)
    {
        //rtd_printk( KERN_ERR, RTDLOG_TAG, "insert miss log msg for type:%d\n",type);
        insert_msg_err_tip(type);
    }

RET:
        return ret;
}

unsigned int write_logcat_data (EnumLogbufType type,char __user * buf)
{
    rtd_msg_header header;
    unsigned int ret_len = 0;
    int header_check = 0;

    header_check = get_catmsg_header(type,&header);
    if (header_check == 1)
    {
        if(check_cat_filter(type,header.level,header.cpu_core,header.module))
        {
                skip_catmsg_data(type,&header);
                ret_len = 0;
        }
        else
        {
                ret_len = write_catmsg_data(type,&header,buf);
        }
    }
    else if(header_check == -1)
    {
        mutex_lock(&logcat_mutex);
        kfifo_cat_sync(array_fifo[type]);
        mutex_unlock(&logcat_mutex);
    }

    return ret_len;
}

static void rtd_end_free(void)
{
        filp_close(gFileInfo.logfile_fd, NULL);
        gFileInfo.logfile_fd = NULL;

        if(gHistoryBuf)
        {
                vfree(gHistoryBuf);
                gHistoryBuf = NULL;
        }
}
static void rtd_force_sleep(u64 *last_start_time)
{
        u64 now_time = *gpRtdlogTimestamp;
        if(now_time - (*last_start_time) > READ_THREAD_FORCE_SLEEP_LIMIT)
        {
            msleep(READ_THREAD_FORCE_SLEEP_SPAN);
            *last_start_time = *gpRtdlogTimestamp;
        }
}

static void sync_param_region(int num)
{

#ifdef CONFIG_64BIT
        if((num >= ACPU1_BUF) && (num <= KCPU_BUF)){
                pRtdLogCB[num]->ddr_mutex = (u64)(pRtdLogCB_32[num]->ddr_mutex);
                pRtdLogCB[num]->drop_cnt = (u64)(pRtdLogCB_32[num]->drop_cnt);
                pRtdLogCB[num]->in_reset = (u64)(pRtdLogCB_32[num]->in_reset);

                // sync 'in' to 64bit
                array_fifo[num]->in = (u64)(pRtdLogCB_32[num]->fifo.in);
                //sync 'out' back to 32bit
                pRtdLogCB_32[num]->fifo.out = (u32)(array_fifo[num]->out);
                pRtdLogCB_32[num]->fifo.out_cat = array_fifo[num]->out_cat;
        }else if((num>=KERNEL_BUF) && (num < MAX_LOGBUF_NUM)){
                pRtdLogCB_32[num]->ddr_mutex = (u32)(pRtdLogCB[num]->ddr_mutex);
                pRtdLogCB_32[num]->drop_cnt= (u32)(pRtdLogCB[num]->drop_cnt);
                pRtdLogCB_32[num]->in_reset= (u32)(pRtdLogCB[num]->in_reset);

                pRtdLogCB_32[num]->fifo.in = (u32)(array_fifo[num]->in);
                pRtdLogCB_32[num]->fifo.out= (u32)(array_fifo[num]->out);
                pRtdLogCB_32[num]->fifo.out_cat= (u32)(array_fifo[num]->out_cat);
        }else{
                return;
        }
#endif
}

static int rtd_write_data_to_file(void)
{
        //read data,if empty sleep
        int sleep_flag = 0;
        int i;
        struct mutex * mtx = &read_loop_mutex;
        mm_segment_t old_fs;
        //init fs
        old_fs = get_fs();
        set_fs(KERNEL_DS);

        mutex_lock(mtx);
        for(i = 0;i < MAX_LOGBUF_NUM;++i)
        {
#ifndef RTDLOG_AVCPU2
        if((i==ACPU2_BUF) || (i==VCPU2_BUF)){
                continue;
        }
#endif
            sync_param_region(i);
            sleep_flag |= write_data(i,NULL);
        }
        mutex_unlock(mtx);
        set_fs(old_fs);

        return sleep_flag;
}

int thread_logbuf_reader(void* p)
{
    int sleep_flag;
    static u64 last_start_time = 0;

    if(rtd_logbuf_init()){
        return -1;
    }
    record_reboot_data();

    reset_rtd_keylog_buf();

    // KWarning: checked ok by muye_wang
    for(;;)
    {
        rtd_force_sleep(&last_start_time); //force sleep
        sleep_flag = rtd_write_data_to_file();

        if(!sleep_flag)
        {
            msleep(READ_THREAD_FORCE_SLEEP_SPAN);
            last_start_time = *gpRtdlogTimestamp;
        }
    }
    rtd_end_free();
    return 0;
}

int rtdlog_save_msg (EnumLogbufType type, const char * text, rtd_msg_header * header)
{
    struct kfifo * fifo=array_fifo[type];
    //struct mutex * mtx=log_save_mutex[type];

    if(!is_setup_rtd_logbuf)
    {
        return -1;
    }

    if((type == HAL_BUF)||(type == KERNEL_BUF))
    {
        if(check_log_filter(type,header->level,header->cpu_core,header->module))
        {
            return 0;
        }
    }

    //mutex_lock(mtx);
    if (kfifo_avail(fifo) > (header->len))
    {
        header->check_sum = get_msghead_sum(header);
        kfifo_in(fifo,header,sizeof(rtd_msg_header));
        kfifo_in(fifo,text,header->text_len);
        gDbgInfo.save_log_len[type] += header->text_len;
        gDbgInfo.save_log_cnt[type]++;
    }
    else
    {
        pRtdLogCB[type]->drop_cnt++;
    }
    //mutex_unlock(mtx);

    return 0;
}
EXPORT_SYMBOL(rtdlog_save_msg);

void rtd_logbuf_save_log( int level, const char *text, u16 text_len)
{
        rtd_msg_header tmp_header;

        if(is_save_early_log_done==0){
        //if(is_setup_rtd_logbuf==0){
                return;
        }

        /*rtdlog buf msg*/
        tmp_header.cpu_type = (u8)KERNEL_BUF;
        tmp_header.cpu_core = smp_processor_id();
        tmp_header.module = 0;
        tmp_header.pid = task_tgid_nr(current);
        tmp_header.tid = task_pid_nr(current);
        tmp_header.timestamp = *gpRtdlogTimestamp;
        tmp_header.level = level;
        tmp_header.text_len = text_len;
        tmp_header.len = sizeof(tmp_header) + text_len;

        memset(tmp_header.name,'#',sizeof(tmp_header.name));
        memcpy(tmp_header.name,current->comm,sizeof(tmp_header.name));
        tmp_header.name[sizeof(tmp_header.name)-1] = '\0';

        rtdlog_save_msg(KERNEL_BUF,text, &tmp_header);

}
EXPORT_SYMBOL(rtd_logbuf_save_log);

#define RTD_BUFSIZE_NUM  4
/*__setup parse bootcode_arg late than setup_arch
        get bufsize should parse cmdline*/
void rtdlog_parse_bufsize(char * str)
{
        unsigned long default_value[RTD_BUFSIZE_NUM]={
                0x80000,
                0x100000,
                0x200000,
                0x400000
        };
        char *sub_str[RTD_BUFSIZE_NUM]={
                "bufsize=80000",
                "bufsize=100000",
                "bufsize=200000",
                "bufsize=400000"
        };
        int i;

        for(i=0; i<RTD_BUFSIZE_NUM; i++){
                if(strstr(str, sub_str[i])!= NULL){
                        //rtdlog_bufsize = default_value[i];
                        rtdlog_bufsize = RTD_LOGBUF_DEFAULT_LIMIT << i ;
                        rtdlog_param_size = RTD_LOGBUF_DEFAULT_PARAM << i ;
                        //printk("get bufsize=%x, rtdlog_param_size=%x\n",rtdlog_bufsize, rtdlog_param_size);
                        return;
                }
        }
        rtdlog_bufsize = default_value[0];
}
EXPORT_SYMBOL(rtdlog_parse_bufsize);

unsigned long rtdlog_get_buffer_size(void)
{
        return rtdlog_bufsize;
}
EXPORT_SYMBOL(rtdlog_get_buffer_size);
/*------------------------------------------------------------------------------------------
--------------------------------debug node operation cmd related---------------------------------
------------------------------------------------------------------------------------------*/
/*
** parse rtdlog debug node operation cmd
*/
static int parse_rtdlog_sysnode_opera(char * buf, rtdlog_sysnode_param * param)
{
        if(buf == NULL) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "NULL point in %s\n", __FUNCTION__);
                return -1;
        }
        //get set on/off
        if(strcmp(buf, "set") == 0) {
                param->opera = LOG_ON;
        } else if(strcmp(buf, "unset") == 0) {
                param->opera = LOG_OFF;
        } else if(strcmp(buf, "dbg") == 0) {
                param->opera = LOG_DBG;
        } else if(strcmp(buf, "help") == 0) {
                param->opera = LOG_HELP;
        } else if(strcmp(buf, "block") == 0) {
                param->opera = LOG_BLOCK;
        } else if(strcmp(buf, "convert") == 0) {
                param->opera = LOG_CONVERT;
        } else if(strcmp(buf, "dump") == 0) {
                param->opera = LOG_DUMP;
        } else if(strcmp(buf, "msgon") == 0) {
                param->opera = LOG_DMSG_ON;
        } else if(strcmp(buf, "msgoff") == 0) {
                param->opera = LOG_DMSG_OFF;
        } else if(strcmp(buf, "cat") == 0) {
                param->opera = LOG_CAT_ON;
        } else if(strcmp(buf, "uncat") == 0) {
                param->opera = LOG_CAT_OFF;
        } else if(strcmp(buf, "file") == 0) {
                param->opera = LOG_FILE_TOGGLE;
        } else if(strcmp(buf, "unmask") == 0) {
                param->opera = LOG_FILE_UNMASK_LEVEL;
        } else {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "unknow operation:%s\n", buf);
                return -1;
        }

        return 0;
}

/*
** sblit string to array by a char
*/
static int split_str(char * str, char split_flag, char out_str[][16], int max_cnt)
{
        int num = 0;
        int i;
        int start;
        int end;
        if((str == NULL) || (out_str == NULL)) {
                return -1;
        }
        //get strings
        for(start = 0, end = 0; str[end] != '\0'; ++end) {
                if(str[end] == split_flag) {
                        if(start < end) { // if any char between start-end range;
                                for(i = 0; start < end; start++, i++) { // copy string
                                        out_str[num][i] = str[start];
                                }
                                start = end + 1; //ignore the split str;
                                num++;
                                if(num >= max_cnt) {
                                        return num;
                                }
                        } else {
                                start = end + 1; //ignore the split str;
                        }
                }
        }
        //get last string
        if(start < end) { // if any char between start-end range;
                for(i = 0; start < end; start++, i++) {
                        out_str[num][i] = str[start];
                }
                num++;
        }

        return num;
}

/*
** parse param to get buffer type id
*/
static int get_buftype_id(char * buf)
{
        int return_id = -1;

        if(buf == NULL) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "NULL point in %s\n", __FUNCTION__);
                return -1;
        }

        if ((strcmp(buf, "all") == 0)||(strcmp(buf, "ALL") == 0)) {
                return_id = MAX_LOGBUF_NUM;
        } else if ((strcmp(buf, "acpu1") == 0)||(strcmp(buf, "ACPU1") == 0)) {
                return_id = ACPU1_BUF;
        } else if ((strcmp(buf, "acpu2") == 0)||(strcmp(buf, "ACPU2") == 0)) {
                return_id = ACPU2_BUF;
        } else if ((strcmp(buf, "vcpu1") == 0)||(strcmp(buf, "VCPU1") == 0)) {
                return_id = VCPU1_BUF;
        } else if ((strcmp(buf, "vcpu2") == 0)||(strcmp(buf, "VCPU2") == 0)) {
                return_id = VCPU2_BUF;
        } else if ((strcmp(buf, "kcpu1") == 0)||(strcmp(buf, "KCPU1") == 0)) {
                return_id = KCPU_BUF;
        } else if ((strcmp(buf, "s-ker") == 0)||(strcmp(buf, "S-KER") == 0)) {
                return_id = KERNEL_BUF;
        } else if ((strcmp(buf, "s-hal") == 0)||(strcmp(buf, "S-HAL") == 0)) {
                return_id = HAL_BUF;
        } else {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "invalid buf type - %s\n", buf);
                return -1;
        }

        return return_id;
}

/*
** parse rtdlog debug node buffer type cmd
*/
static int parse_rtdlog_sysnode_buf(char * buf, rtdlog_sysnode_param * param)
{
        int i, j;
        char buf_str[MAX_LOGBUF_NUM][16] = {{0}};
        int buf_num;
        int buf_id;

        if(buf == NULL) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "NULL point in %s\n", __FUNCTION__);
                return -1;
        }

        buf_num = split_str(buf, ',', buf_str, MAX_LOGBUF_NUM);
        for(i = 0; i < buf_num; ++i) {
                buf_str[i][15] = '\0';
                buf_id = get_buftype_id(&buf_str[i][0]);
                if(buf_id < 0) {
                        return -1;
                }

                if(buf_id == MAX_LOGBUF_NUM) {
                        for(j = 0; j < MAX_LOGBUF_NUM; ++j) {
                                param->buf_idx[j] = 1;
                        }
                        break;
                } else {
                        param->buf_idx[buf_id] = 1;
                }
        }

        return 0;
}

/*
** parse rtdlog debug node option cmd
*/
static int parse_rtdlog_sysnode_option(char * buf, rtdlog_sysnode_param * param)
{
        //int i, j;
        char split_buf[2][16] = {{0}};
        int split_num;

        if(buf == NULL) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "NULL point in %s\n", __FUNCTION__);
                return -1;
        }

        if(buf[0] == 0) {
                return 0;
        }

        split_num = split_str(buf, ':', split_buf, 2);
        if(split_num != 2) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "unknown option field:%s\n", buf);
                return -1;
        }

        if(strcmp(&split_buf[0][0], "core") == 0) {
                if(sscanf(&split_buf[1][0], "%hhu", &param->core_mask) < 1) {
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "parse core mask fail\n");
                        return -1;
                }
                param->core_modify = 1;
        } else if(strcmp(&split_buf[0][0], "mod") == 0) {
                if(sscanf(&split_buf[1][0], "%x", &param->module_mask) < 1) {
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "parse module mask fail\n");
                        return -1;
                }
                param->module_modify = 1;
        } else if(strcmp(&split_buf[0][0], "lv") == 0) {
                if(sscanf(&split_buf[1][0], "%hhu", &param->level) < 1) {
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "parse level range fail\n");
                        return -1;
                }
                param->level_modify = 1;
        }

        return 0;
}

/*
** parse rtdlog debug mask level
*/
static int parse_rtdlog_mask_level(char * buf, rtdlog_sysnode_param * param)
{
        if(sscanf(buf, "%hhu", &param->masklevel) < 1) {
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "parse level range fail\n");
                        return -1;
        }
        param->masklevel_modify = 1;
        //rtd_printk( KERN_ERR, RTDLOG_TAG, "current mask_level=%d\n",param->masklevel);
        return 0;
}

/*
** parse rtdlog debug node cmdline
*/
static int parse_rtdlog_sysnode_cmdline(const char * buf, rtdlog_sysnode_param * param)
{
        char set_field[8] = {0};
        char buf_field[64] = {0};
        char op1_filed[16] = {0};
        char op2_filed[16] = {0};
        char op3_filed[16] = {0};
        int ret = 0;

        if(buf == NULL) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "NULL point in %s\n", __FUNCTION__);
                return -1;
        }

        //get options
        if (sscanf(buf, "%7s %63s %15s %15s %15s", set_field, buf_field, op1_filed, op2_filed, op3_filed) < 1) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "get cmdline fail!\n");
                return -1;
        }

        if(parse_rtdlog_sysnode_opera(set_field, param)) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "get operation fail!\n");
                return -1;
        }

        switch(param->opera) {
                case LOG_ON:
                case LOG_CAT_ON:
                        if(parse_rtdlog_sysnode_buf(buf_field, param)) {
                                rtd_printk( KERN_ERR, RTDLOG_TAG, "get buf type fail!\n");
                                return -1;
                        }
                        ret = 0;
                        ret |= parse_rtdlog_sysnode_option(op1_filed, param);
                        ret |= parse_rtdlog_sysnode_option(op2_filed, param);
                        ret |= parse_rtdlog_sysnode_option(op3_filed, param);
                        if(ret != 0) {
                                return -1;
                        }
                        break;

                case LOG_OFF:
                case LOG_CAT_OFF:
                case LOG_DBG:
                        if(parse_rtdlog_sysnode_buf(buf_field, param)) {
                                rtd_printk( KERN_ERR, RTDLOG_TAG, "get buf type fail!\n");
                                return -1;
                        }
                        break;

                case LOG_BLOCK: //no param need
                case LOG_HELP:
                case LOG_CONVERT:
                case LOG_DUMP:
                case LOG_FILE_TOGGLE:
                        break;

                case LOG_DMSG_ON:
                case LOG_DMSG_OFF:
                        if(parse_rtdlog_sysnode_buf(buf_field, param)) {
                                rtd_printk( KERN_ERR, RTDLOG_TAG, "get buf type fail!\n");
                                return -1;
                        }
                        break;
                case LOG_FILE_UNMASK_LEVEL:
                        parse_rtdlog_mask_level(buf_field, param);
                        break;
                        //
                default:
                        break;
        }

        return 0;
}

/*
** dump help info for rtdlog debug node
*/
static void rtdlog_help_info(void)
{
        rtd_printk( KERN_ERR, RTDLOG_TAG, "rtdlog cmd usage:\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "1)set buf_1,buf_2,... core:-- mod:-------- lv:--\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: modify the log filter setting\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t buf:all,acpu1,acpu2,vcpu1,vcpu2,kcpu1,s-ker,s-hal\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t core:core mask by bit\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t mod:module mask by bit\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t lv:log level(including the setting level will output to log-file)\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo \"set acpu1,kcpu1 core:0 mod:0 lv:5\" > /sys/realtek_boards/rtdlog\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "2)unset buf_1,buf_2,... \n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: prevent the log which come from specified logbuf to input in log-file\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo \"unset acpu1,kcpu1 \" > /sys/realtek_boards/rtdlog\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "3)dbg buf_1,buf_2,... \n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: show debug info\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo \"dbg acpu1,kcpu1 \" > /sys/realtek_boards/rtdlog\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "4)block \n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: block/unblock RtdLogReader Thread\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo block > /sys/realtek_boards/rtdlog\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "5)logcat \n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: cat log in rtd logbuf\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: cat /dev/rtd-logger\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "6)dump \n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: dump log-data to logbuf.bin\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo dump > /dev/rtd-logger\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "7)msgon buf_1,buf_2,... \n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: kernel will print other fw log\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo avon acpu1,vcpu1 > /dev/rtd-logger\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "8)msgoff buf_1,buf_2,... \n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: kernel will not print other fw log\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo avon acpu1,vcpu1 > /dev/rtd-logger\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "9)cat buf_1,buf_2,... core:-- mod:-------- lv:--\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: set the log-cat filter setting\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo \"cat acpu1,kcpu1 core:0 mod:0 lv:5\" > /sys/realtek_boards/rtdlog\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "10)uncat buf_1,buf_2,... \n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: unset the log-cat filter setting\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo \"uncat acpu1,kcpu1 \" > /sys/realtek_boards/rtdlog\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "11)file \n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: toggle log-file write enable/disable\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo file > /sys/realtek_boards/rtdlog\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "12)unmask level \n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t note: loglevel <= this level,ignore buf_mask ,put into file/display\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t exp: echo unmask 3 > /sys/realtek_boards/rtdlog\n");
}

/*
** set/modify log filter
*/
static void rtdlog_filter_logon(rtdlog_sysnode_param * param)
{
        int i;
        for(i = 0; i < MAX_LOGBUF_NUM; ++i) {
                //enable log output
                if(param->buf_idx[i]) {
                        log_filter.buf_mask &= ~(1 << i);
                        if(param->core_modify) {
                                log_filter.sub_mask[i].core_mask = param->core_mask;
                        }
                        if(param->module_modify) {
                                log_filter.sub_mask[i].module_mask = param->module_mask;
                        }
                        if(param->level_modify) {
                                log_filter.sub_mask[i].level = param->level;
                        }
                }
        }
}

/*
** unset buffer types in log filter
*/
static void rtdlog_filter_logoff(rtdlog_sysnode_param * param)
{
        int i;
        for(i = 0; i < MAX_LOGBUF_NUM; ++i) {
                //diable log output
                if(param->buf_idx[i]) {
                        log_filter.buf_mask |= (1 << i);
                }
        }
}

/*
** set/modify log filter
*/
static void rtdlog_filter_caton(rtdlog_sysnode_param * param)
{
        int i;
        for(i = 0; i < MAX_LOGBUF_NUM; ++i) {
                //enable log output
                if(param->buf_idx[i]) {
                        cat_filter.buf_mask &= ~(1 << i);
                        if(param->core_modify) {
                                cat_filter.sub_mask[i].core_mask = param->core_mask;
                        }
                        if(param->module_modify) {
                                cat_filter.sub_mask[i].module_mask = param->module_mask;
                        }
                        if(param->level_modify) {
                                cat_filter.sub_mask[i].level = param->level;
                        }
                }
        }
}

/*
** unset buffer types in log filter
*/
static void rtdlog_filter_catoff(rtdlog_sysnode_param * param)
{
        int i;
        for(i = 0; i < MAX_LOGBUF_NUM; ++i) {
                //diable log output
                if(param->buf_idx[i]) {
                        cat_filter.buf_mask |= (1 << i);
                }
        }
}

/*
** dump rtdlog debug info
*/
static void rtdlog_filter_logdbg(rtdlog_sysnode_param * param)
{
        int i;
        char *type_string[MAX_LOGBUF_NUM] = {
                "ACPU1",
                "ACPU2",
                "VCPU1",
                "VCPU2",
                "KCPU1",
                "S-KER",
                "S-HAL",
        };

        rtd_printk( KERN_ERR, RTDLOG_TAG, "===============RTDLOG DBG STATUS===============\n");
        rtd_printk( KERN_ERR, RTDLOG_TAG, "buf_mask(a1:%d a2:%d v1:%d v2:%d k:%d s-ker:%d s-hal:%d) file_en:%d\n",
                (log_filter.buf_mask&(1<<ACPU1_BUF))>>ACPU1_BUF,
                (log_filter.buf_mask&(1<<ACPU2_BUF))>>ACPU2_BUF,
                (log_filter.buf_mask&(1<<VCPU1_BUF))>>VCPU1_BUF,
                (log_filter.buf_mask&(1<<VCPU2_BUF))>>VCPU2_BUF,
                (log_filter.buf_mask&(1<<KCPU_BUF))>>KCPU_BUF,
                (log_filter.buf_mask&(1<<KERNEL_BUF))>>KERNEL_BUF,
                (log_filter.buf_mask&(1<<HAL_BUF))>>HAL_BUF,
                rtdlog_file_en);
        rtd_printk( KERN_ERR, RTDLOG_TAG, "logswi:%08lx logfile:%08lx logdir=%s\n", bootcode_args, bootcode_args_logfile, logbuf_dir);
        rtd_printk( KERN_ERR, RTDLOG_TAG, "filesize(total_file:0x%lx a1:0x%lx a2:0x%lx v1:0x%lx v2:0x%lx)\n",
                gFileInfo.logfile_max_size, gFileInfo.fwfile_max_size[ACPU1_BUF], gFileInfo.fwfile_max_size[ACPU2_BUF], gFileInfo.fwfile_max_size[VCPU1_BUF], gFileInfo.fwfile_max_size[VCPU2_BUF]);
        for(i = 0; i < MAX_LOGBUF_NUM; ++i)
        {
                if(param->buf_idx[i])
                {
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "---%6s---\n",type_string[i]);
                        rtd_printk( KERN_ERR, RTDLOG_TAG,
                                "<log-file>(en:%s  level:%02x  core:%02x  module:%08x)\n",
                                log_filter.buf_mask & (1 << i) ? "disabled" : "enabled",
                                log_filter.sub_mask[i].level,
                                log_filter.sub_mask[i].core_mask,
                                log_filter.sub_mask[i].module_mask);
                        rtd_printk( KERN_ERR, RTDLOG_TAG,
                                "<log-cat >(en:%s  level:%02x  core:%02x  module:%08x)\n",
                                cat_filter.buf_mask & (1 << i) ? "disabled" : "enabled",
                                cat_filter.sub_mask[i].level,
                                cat_filter.sub_mask[i].core_mask,
                                cat_filter.sub_mask[i].module_mask);
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t save(cnt %08x,len %08x) read(cnt %08x,len %08x) file(cnt %08x,len %08x)\n",
                                gDbgInfo.save_log_cnt[i],gDbgInfo.save_log_len[i],
                                gDbgInfo.read_log_cnt[i],gDbgInfo.read_log_len[i],
                                gDbgInfo.file_log_cnt[i],gDbgInfo.file_log_len[i]);
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t abnormal cnt(drop %08lx,reset %08x)\n",
                                (unsigned long)(pRtdLogCB[i]->drop_cnt),gDbgInfo.log_reset_cnt[i]);
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "\t kfifo(buf %08lx,size %08lx,in %08lx,out %08lx,avail %08x,cat %08lx)\n",
                                (unsigned long)(pRtdLogCB[i]->fifo.buffer), (unsigned long)(pRtdLogCB[i]->fifo.size),
                                (unsigned long)(pRtdLogCB[i]->fifo.in),(unsigned long)(pRtdLogCB[i]->fifo.out),
                                kfifo_avail(array_fifo[i]),
                                (unsigned long)(pRtdLogCB[i]->fifo.out_cat));
                }
        }

        rtd_printk( KERN_ERR, RTDLOG_TAG, "DMESG STATUS A1:%d, A2:%d, V1:%d, V2:%d K:%d HAL:%d\n",
                acpu1_rtdlb_dmesg_en,
                acpu2_rtdlb_dmesg_en,
                vcpu1_rtdlb_dmesg_en,
                vcpu2_rtdlb_dmesg_en,
                kcpu_rtdlb_dmesg_en,
                hal_rtdlb_dmesg_en);

        rtd_printk( KERN_ERR, RTDLOG_TAG, "log file(cnt %08x,len %08x,wrap %08x,fail cnt %08x)\n",
                gDbgInfo.total_write_cnt,gDbgInfo.total_write_len,
                gDbgInfo.log_wrap_cnt,gDbgInfo.vfs_write_fail_cnt);

}

static void rtdlog_filter_logblock(rtdlog_sysnode_param * param)
{
        static int toggle_flag = 0;
        struct mutex * mtx = &read_loop_mutex;

        if(toggle_flag)
        {
                mutex_unlock(mtx);
                toggle_flag = 0;
                rtd_printk( KERN_ERR, RTDLOG_TAG, "RtdLogReader is released...\n");
        }
        else
        {
                mutex_lock(mtx);
                toggle_flag = 1;
                rtd_printk( KERN_ERR, RTDLOG_TAG, "RtdLogReader is blocked...\n");
        }

}

static void dump_log_data(void)
{
        int data_size = rtdlog_bufsize - rtdlog_param_size;
        int param_size = rtdlog_param_size;
        int write_len;
        loff_t pos = 0;
        char * pParam = phys_to_virt(RTD_LOGBUF_PHY_START_ADDR);
        char * pData = pParam+rtdlog_param_size;
        //int is_err = -1;
        mm_segment_t old_fs = get_fs();
        char dump_log_path[LOGBUF_DIR_MAX_SIZE] = {0};
        struct file * log_file = NULL;

        memset(dump_log_path, 0, LOGBUF_DIR_MAX_SIZE);
        snprintf(dump_log_path, LOGBUF_DIR_MAX_SIZE-strlen(LOG_DUMP_FILE_NAME), "%s%s",logbuf_dir,LOG_DUMP_FILE_NAME);
        //rtd_printk(KERN_INFO, RTDLOG_TAG, "file path=%s\n",dump_log_path);

        log_file = filp_open(dump_log_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
        //check files
        if(IS_ERR(log_file))
        {
                rtd_printk(KERN_ERR,RTDLOG_TAG,"filp_open files failedlog:%lu(0x%lx))\n",
                                (unsigned long)log_file,(unsigned long)log_file);
                goto release;
        }

        //init fs
        old_fs = get_fs();
        set_fs(KERNEL_DS);

        //for loop dump 5M data.bin
        pos = param_size;
        write_len = vfs_write(log_file, pData, data_size, &pos);

        if(write_len != data_size)
        {
                rtd_printk(KERN_ERR,RTDLOG_TAG,"[%s]vfs_write data ret 0x%x,expected 0x%x!\n",__FUNCTION__,write_len,data_size);
                goto release;
        }

        //dump 1M param.bin
        pos = 0;
        log_file->f_pos = pos;
        write_len = vfs_write(log_file, pParam, param_size, &pos);
        if(write_len != param_size)
        {
                rtd_printk(KERN_ERR,RTDLOG_TAG,"[%s]vfs_write param ret 0x%x,expected 0x%x!\n",__FUNCTION__,write_len,param_size);
                goto release;
        }

release:

        set_fs(old_fs);

        if(!IS_ERR(log_file))
        {
                filp_close(log_file, NULL);
        }
        //close file
        return;
}

static void rtd_dmsg_set(rtdlog_sysnode_param * param,int val)
{
        int i;

        for(i = 0;i < MAX_LOGBUF_NUM;++i)
        {
                if(!(param->buf_idx[i]))
                {
                        continue;
                }

                switch(i)
                {
                case ACPU1_BUF:
                        acpu1_rtdlb_dmesg_en = val;
                        break;
                case ACPU2_BUF:
                        acpu2_rtdlb_dmesg_en = val;
                        break;
                case VCPU1_BUF:
                        vcpu1_rtdlb_dmesg_en = val;
                        break;
                case VCPU2_BUF:
                        vcpu2_rtdlb_dmesg_en = val;
                        break;
                case KCPU_BUF:
                        kcpu_rtdlb_dmesg_en = val;
                        break;
                case HAL_BUF:
                        hal_rtdlb_dmesg_en = val;
                        break;
                default:
                        break;
                }
        }
}

static void rtd_logfile_toggle(void)
{
        if(rtdlog_file_en)
        {
                rtdlog_file_en = 0;
        }
        else
        {
                rtdlog_file_en = 1;
        }
}
static void rtd_logfile_set_masklevel(rtdlog_sysnode_param * param)
{
        if(param->masklevel_modify) {
                log_filter.level_mask = param->masklevel;
        }
        rtd_printk(KERN_ERR, RTDLOG_TAG, "current unmask level=%d\n",log_filter.level_mask);
}

static int rtdlog_implement_param(rtdlog_sysnode_param * param)
{
        if(param == NULL) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "NULL point in %s\n", __FUNCTION__);
                return -1;
        }

        //check operation
        switch(param->opera) {
                case LOG_ON:
                        rtdlog_filter_logon(param);
                        break;
                case LOG_OFF:
                        rtdlog_filter_logoff(param);
                        break;
                case LOG_DBG:
                        rtdlog_filter_logdbg(param);
                        break;
                case LOG_HELP:
                        rtdlog_help_info();
                        break;
                case LOG_BLOCK:
                        rtdlog_filter_logblock(param);
                        break;
                case LOG_CONVERT:
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "convert function is CLOSED\n");
                        //convert_reboot_log(gFileInfo.prelogbuf_bin_path,gFileInfo.prelogbuf_log_path,1);
                        break;
                case LOG_DUMP:
                        dump_log_data();
                        break;
                case LOG_DMSG_ON:
                        rtd_dmsg_set(param,1);
                        break;
                case LOG_DMSG_OFF:
                        rtd_dmsg_set(param,0);
                        break;
                case LOG_CAT_ON:
                        rtdlog_filter_caton(param);
                        break;
                case LOG_CAT_OFF:
                        rtdlog_filter_catoff(param);
                        break;
                case LOG_FILE_TOGGLE:
                        rtd_logfile_toggle();
                        break;
                case LOG_FILE_UNMASK_LEVEL:
                        rtd_logfile_set_masklevel(param);
                        break;

                default:
                        break;
        }

        return 0;
}

/*
echo "set buf_1,buf_2,... core:%x mod:%x lv:%x" > /sys/realtek_boards/rtdlog
    buf:all,abuf,vbuf,kbuf,skbuf,shbuf

echo "unset buf_1,buf_2,..." > /sys/realtek_boards/rtdlog

cat /sys/realtek_boards/rtdlog
*/
void rtdlog_set (const char *buffer)
{
        rtdlog_sysnode_param filter_param;

        rtd_printk( KERN_WARNING, RTDLOG_TAG, "%s called\n", __FUNCTION__);
        memset(&filter_param, 0, sizeof(rtdlog_sysnode_param));
        if(parse_rtdlog_sysnode_cmdline(buffer, &filter_param)) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "parse cmd fail!\n");
                goto Fail;
        }

        if(rtdlog_implement_param(&filter_param)) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "implement param fail!\n");
                goto Fail;
        }

        return;

Fail:
        rtd_printk( KERN_ERR, RTDLOG_TAG, "rtdlog cmd set error!\n");
        return;
}
EXPORT_SYMBOL(rtdlog_set);

void rtdlog_get (char * buf)
{
        return;
}
EXPORT_SYMBOL(rtdlog_get);

/*------------------------------------------------------------------------------------------
--------------------------------------dump avk panic log related------------------------------------
------------------------------------------------------------------------------------------*/

EnumPanicCpuType g_rtdlog_panic_cpu_type = NORMAL;

void rtdlog_crash_enable_dmesg(EnumLogbufType type)
{
        switch(type){
                case ACPU1_BUF:
                        acpu1_rtdlb_dmesg_en = 1;//acpu1 rtd logbuf dmesg enable
                        break;
                case ACPU2_BUF:
                        acpu2_rtdlb_dmesg_en = 1;//acpu2 rtd logbuf dmesg enable
                        break;
                case VCPU1_BUF:
                        vcpu1_rtdlb_dmesg_en = 1;//vcpu1 rtd logbuf dmesg enable
                        break;
                case VCPU2_BUF:
                         vcpu2_rtdlb_dmesg_en = 1;//vcpu2 rtd logbuf dmesg enable
                         break;
                case KCPU_BUF:
                        kcpu_rtdlb_dmesg_en = 1;
                        break;
                default:
                        break;
        }

}
int get_msg_header_avk_epc (EnumLogbufType type,rtd_msg_header* header,struct kfifo * pKfifo)
{
    struct kfifo * fifo;

    fifo = (pKfifo == NULL) ? array_fifo[type]: pKfifo;

    if (kfifo_len(fifo)> sizeof(rtd_msg_header))
    {
        kfifo_out_peek(fifo,header,sizeof(rtd_msg_header),0);

        if(check_msghead_valid(header)) // if fail
        {
                printk("\nKfifo out=%d, Kfifo in=%d\n",(unsigned int)pKfifo->out,  (unsigned int)pKfifo->in);
                kfifo_drop(fifo);
                gDbgInfo.log_reset_cnt[type]++;
                rtd_printk( KERN_ERR, RTDLOG_TAG, "type[%d] check msg header fail!\n",type);
                return -1;
        }
        else
        {
                return 1;
        }
    }

    return 0;
}

int rtdlog_find_header(struct kfifo * fifo, EnumLogbufType type)
{
        unsigned int offset=0;
        unsigned int find_pos = 0;
        //unsigned char * base = fifo->buffer;
        //unsigned int head_pos = 0;
        //rtd_msg_header tmp;
        //rtd_msg_header * pHeader = &tmp;
        unsigned int fifo_back_len = 12000;
        char * tmp_addr = NULL;

        if(type == ACPU2_BUF)
                fifo_back_len = 8000;
        else if(type == ACPU1_BUF)
                fifo_back_len = 30000;
        if(fifo->out < fifo_back_len){
                fifo_back_len = fifo->out;
        }
        __kfifo_decrease_out(fifo,fifo_back_len);       //kfifo out run back
        find_pos = fifo->out;

        offset = find_pos%fifo->size;
        tmp_addr = phys_to_virt((unsigned long)fifo->buffer) + offset;

        while(find_pos != (fifo->in)){
                if(check_msghead_valid((rtd_msg_header *)tmp_addr)){
                        find_pos++;
                        tmp_addr++;
                }else{
                        __kfifo_set_out(fifo,find_pos);
                        return 0;
                }
        }
        return -1;
}

void rtdlog_crash_dump(EnumLogbufType type)
{
        struct kfifo * pKfifo = NULL;
        rtd_msg_header header;
        unsigned int out_len, out_tmp_pos;
        int header_check = 0;
        unsigned char * buffer;
        unsigned int log_max_len = 35000;
        unsigned int log_tmp_len = 0;
        struct timeval log_time;
        struct mutex * mtx = &read_loop_mutex;
        char *cpu_type_str[MAX_LOGBUF_NUM] = {
                "ACPU1",
                "ACPU2",
                "VCPU1",
                "VCPU2",
                "KCPU1",
                "S-KER",
                "S-HAL"
        };

        if(type > KCPU_BUF || (!is_setup_rtd_logbuf)){
                return;
        }
        printk("\n\n\n\n\n\n------kernel panic  trigger dump [%s] logbuf START------\n\n",cpu_type_str[type]);
        mutex_lock(mtx);        // forbidden read thread verify kfifo.out
        pKfifo = array_fifo[type];
        //decreas fifo->out value & find first header addr
        printk("before decrease Kfifo out=%d, Kfifo in=%d\n",(unsigned int)(pKfifo->out), (unsigned int)(pKfifo->in));
        if(rtdlog_find_header(pKfifo, type)<0){
                if(pKfifo->in == 0){
                        goto RET;
                }
                printk("find header fail\n");
                printk("pKfifo->out=%ud, pKfifo->in=%ud\n",(unsigned int)(pKfifo->out), (unsigned int)(pKfifo->in));
                goto RET;
        }
        out_tmp_pos = pKfifo->out;
        printk("after decrease Kfifo out=%d, Kfifo in=%d\n",(unsigned int)(pKfifo->out), (unsigned int)(pKfifo->in));

        while((pKfifo->out) != (pKfifo->in)){
                //get msg header
                header_check = get_msg_header_avk_epc(type,&header,pKfifo);
                if (header_check == 1){
                        if(header.len < sizeof(msg_tmp_buf)){
                                buffer = msg_tmp_buf;
                                memset(buffer,0,sizeof(msg_tmp_buf));
                        }else{
                                buffer = kmalloc(header.len,GFP_KERNEL);
                                if (buffer==NULL)
                                        goto RET ;

                                memset(buffer,0,header.len);
                        }
                        log_time = ns_to_timeval((s64)header.timestamp);
                        out_len = kfifo_out_peek(pKfifo,buffer,header.len,0);
                        //print log
                        printk(KERN_ERR "[%s] [%08d.%06d] %s",cpu_type_str[type], (int)log_time.tv_sec, (int)log_time.tv_usec, buffer+sizeof(rtd_msg_header));
                        __kfifo_add_out(pKfifo, out_len);            //if write success,move out offset to next msg
                        if((buffer != msg_tmp_buf)&&(buffer != NULL))//free malloced buffer
                        {
                                kfree(buffer);
                        }

                        log_tmp_len = log_tmp_len + out_len;
                        if(log_tmp_len > log_max_len){  //beyond log length
                                break;
                        }

                }
                else{
                        printk("Kfifo out=%d, Kfifo in=%d\n",(unsigned int)(pKfifo->out), (unsigned int)(pKfifo->in));
                        break;
                }
        }
        __kfifo_set_out(pKfifo, out_tmp_pos);

RET:
        printk("\n\n------dump [%s] logbuf FINISH------!!!\n\n\n\n\n",cpu_type_str[type]);
        mutex_unlock(mtx);
        return;
}

#if 0
static int rtdlog_panic(struct notifier_block *this, unsigned long ev, void *ptr)
{

        if(g_rtdlog_panic_cpu_type<5){
                rtdlog_crash_dump(g_rtdlog_panic_cpu_type);
        }
        return NOTIFY_DONE;
}
#endif

struct workqueue_struct *p_dumpqueue = NULL;
struct rtd_logger_work_struct DumpWork_a1;
struct rtd_logger_work_struct DumpWork_a2;
struct rtd_logger_work_struct DumpWork_v1;
struct rtd_logger_work_struct DumpWork_v2;
struct rtd_logger_work_struct DumpWork_k;

void rtdlog_watchdog_dump_work(EnumLogbufType type)
{
        switch(type){
                case ACPU1_BUF:
                        DumpWork_a1.param= type;
                        queue_work(p_dumpqueue, &DumpWork_a1.work);
                        break;

                case ACPU2_BUF:
                        DumpWork_a2.param= type;
                        queue_work(p_dumpqueue, &DumpWork_a2.work);
                        break;

                case VCPU1_BUF:
                        DumpWork_v1.param= type;
                        queue_work(p_dumpqueue, &DumpWork_v1.work);
                        break;

                case VCPU2_BUF:
                        DumpWork_v2.param= type;
                        queue_work(p_dumpqueue, &DumpWork_v2.work);
                        break;

                 case KCPU_BUF:
                        DumpWork_k.param= type;
                        queue_work(p_dumpqueue, &DumpWork_k.work);
                        break;

                default:
                        break;
        }
}

void rtdlog_watchdog_dump(struct work_struct *work)
{
        struct rtd_logger_work_struct * watchdog_work = (struct rtd_logger_work_struct *)work;

        console_flush_on_panic();       //dump native logbuf to console
        rtdlog_crash_dump(watchdog_work->param);
}

static int rtdlog_panic(struct notifier_block *this, unsigned long ev, void *ptr)
{
        int rtdlog_panic_cpu_type = ACPU1_BUF;

        if(!is_setup_rtd_logbuf)        //panic before logbuf set
        {
                return NOTIFY_DONE;
        }

        for(rtdlog_panic_cpu_type = 0;rtdlog_panic_cpu_type<=KCPU_BUF;rtdlog_panic_cpu_type++){
                console_flush_on_panic();       //dump native logbuf to console
                rtdlog_crash_dump(rtdlog_panic_cpu_type);
        }
        rtdlog_show_history_keylog(rtd_keylog_addr, RTD_LOGBUF_KEYLOG_SIZE);

        return NOTIFY_DONE;
}

static struct notifier_block rtdlog_panic_block = {
	.notifier_call = rtdlog_panic,
};

static int __init check_cpu_stall_init(void)
{
	atomic_notifier_chain_register(&panic_notifier_list, &rtdlog_panic_block);
	return 0;
}

early_initcall(check_cpu_stall_init);

/*------------------------------------------------------------------------------------------
--------------------------------------hal device node related------------------------------------
------------------------------------------------------------------------------------------*/

int rtdlog_major = RTD_LOGBUF_DEV_MAJOR;    //rtdlog device node major
int rtdlog_minor = RTD_LOGBUF_DEV_MINOR;    //rtdlog device node minor
static struct class *rtdlog_class;
static struct rtdlog_dev *rtdlog_drv_dev;               /* allocated in rtdlog_init_module */

#ifdef CONFIG_PM
static int rtdlog_pm_suspend(
        struct platform_device *dev,
        pm_message_t state
)
{
        return 0;
}
static int rtdlog_pm_resume(
        struct platform_device *dev
)
{
        return 0;
}


static struct platform_device *rtdlog_platform_devs;

static struct platform_driver rtdlog_device_driver = {
        .suspend    = rtdlog_pm_suspend,
        .resume     = rtdlog_pm_resume,
        .driver = {
                .name       = "rtd_logger",
                .bus        = &platform_bus_type,
        } ,
} ;
#endif

int rtdlog_open(
        struct inode*           inode,
        struct file*            filp
)
{
        struct rtdlog_dev *pdev; /* device information */

        pdev = container_of(inode->i_cdev, struct rtdlog_dev, cdev);
        filp->private_data = pdev; /* for other methods */

        //rtd_printk( KERN_WARNING, RTDLOG_TAG, "rtdlog device open\n");
        return 0;
}

int rtdlog_release(
        struct inode*           inode,
        struct file*            filp
)
{
        filp->private_data = NULL;

        //rtd_printk( KERN_WARNING, RTDLOG_TAG, "rtdlog device release\n");
        return 0;
}

#define RTDLOG_DEV_MAGIC  'k'
#define RTDLOG_IOC_LOCK_CMD _IOWR(RTDLOG_DEV_MAGIC, 0, int )
#define RTDLOG_IOC_UNLOCK_CMD _IOWR(RTDLOG_DEV_MAGIC, 1, int )
#define RTDLOG_IOC_LOGPATH_CMD _IOWR(RTDLOG_DEV_MAGIC,2, unsigned long )
#define RTDLOG_IOC_KERNEL_SLEEP _IOWR(RTDLOG_DEV_MAGIC, 3, unsigned long )

long rtdlog_ioctl(
        struct file             *filp,
        unsigned int            cmd,
        unsigned long           arg)
{
        char buf[LOGBUF_DIR_MAX_SIZE]={0};
        //int value = 0;

        switch(cmd){
                case RTDLOG_IOC_LOCK_CMD:
                        //rtd_printk( KERN_ERR, RTDLOG_TAG, "lock\n");
                        mutex_lock(&rtd_logfile_lock);
                        break;

                case RTDLOG_IOC_UNLOCK_CMD:
                        //rtd_printk( KERN_ERR, RTDLOG_TAG, "unlock\n");
                        mutex_unlock(&rtd_logfile_lock);
                        break;

                case RTDLOG_IOC_LOGPATH_CMD:
                        if (copy_from_user(buf, (unsigned char *)arg,LOGBUF_DIR_MAX_SIZE)){
                                rtd_printk( KERN_ERR, RTDLOG_TAG, "RTDLOG_IOC_LOGPATH_CMD copy_from_user error\n");
                        }
                        memcpy(buf, logbuf_dir, LOGBUF_DIR_MAX_SIZE);
                        if(copy_to_user((void __user *)arg, (void *)buf, LOGBUF_DIR_MAX_SIZE)){
                                rtd_printk( KERN_ERR, RTDLOG_TAG, "RTDLOG_IOC_LOGPATH_CMD copy_to_user error\n");
                        }
                        break;
                 case RTDLOG_IOC_KERNEL_SLEEP:
                        g_wait_ap = arg;
                        //rtd_printk( KERN_ERR, RTDLOG_TAG, "g_wait_ap =%d\n",g_wait_ap);
                        break;
                default:
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "wrong ioctrol cmd\n");
        }

        return 0;
}

ssize_t rtdlog_read(struct file * filp, char __user * buf, size_t count,loff_t * f_pos)
{
        int i = 0;
        static int j = 0;
        ssize_t len = 0;
        static int need_sync = 1;

        if(need_sync)
        {
                for(i = 0;i < MAX_LOGBUF_NUM;i++)
                {
                        mutex_lock(&logcat_mutex);
                        kfifo_cat_sync(array_fifo[i]);
                        mutex_unlock(&logcat_mutex);
                }
                need_sync = 0;
        }

        while(1)
        {
                j %= MAX_LOGBUF_NUM;
                len = write_logcat_data(j,buf);
                ++j;

                if(len > 0)
                {
                        break;
                }

                if (signal_pending(current))
                {
                        need_sync = 1;
                        break;
                }

        }

        return len;
}

ssize_t rtdlog_write(struct file * filp, const char __user * buf, size_t count, loff_t * f_pos)
{
        u32 info_size = sizeof(rtd_logbuf_hal_info);
        u32 text_len;
        const char * text;
        rtd_msg_header tmp_header;
        rtd_logbuf_hal_info info;
        char databuf[RTD_BUFSIZE_512] = {0};
        unsigned long copy_ret;
        struct mutex * mtx=log_save_mutex[HAL_BUF];

        if(is_setup_rtd_logbuf) {
                if(count < info_size) {
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "%s : lost hal head info!\n", __FUNCTION__);
                        return 0;
                }

                if(count > RTD_BUFSIZE_512) {
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "%s : hal log length:%d > 512!\n", __FUNCTION__, (unsigned int)count);
                        return 0;
                }
                //parse buffer info.
                copy_ret = copy_from_user(databuf, buf, count);

                if(copy_ret)
                {
                        rtd_printk( KERN_ERR, RTDLOG_TAG, "error : copy_from_user return 0x%x,drop 1 msg\n",(unsigned int)copy_ret);
                        return 0;
                }

                //level,text_len,cpu_core,text
                memcpy(&info, databuf, info_size);

                /*****special process for hal buffer,because hal log is too much*****
                ***** we will block the log into hal buffer,if not match filter *****
                ********************************************************************/

                text_len = count - info_size;
                text = databuf + info_size;

                //save log
                tmp_header.cpu_type = (u8)HAL_BUF;
                tmp_header.cpu_core = info.core;
                tmp_header.pid = task_tgid_nr(current);
                tmp_header.tid = task_pid_nr(current);
                tmp_header.timestamp = *gpRtdlogTimestamp;
                tmp_header.level = info.level;
                tmp_header.module = info.module;
                tmp_header.text_len = text_len;
                tmp_header.len = sizeof(tmp_header) + text_len;

                memset(tmp_header.name,'#',sizeof(tmp_header.name));
                memcpy(tmp_header.name,current->comm,sizeof(tmp_header.name));
                tmp_header.name[sizeof(tmp_header.name)-1] = '\0';

                mutex_lock(mtx);
                rtdlog_save_msg(HAL_BUF, text, &tmp_header);
                mutex_unlock(mtx);
        } else {
                //rtd_printk( KERN_ERR, RTDLOG_TAG, "rtd_log buf is not setup yet...\n");
                return 0;
        }

        return tmp_header.len;
}

struct file_operations rtdlog_fops = {
        .owner          = THIS_MODULE,
        .unlocked_ioctl = rtdlog_ioctl,
        .open           = rtdlog_open,
        .release        = rtdlog_release,
        .read           = rtdlog_read,
        .write          = rtdlog_write,
};

static int __init rtdlog_init_module(void)
{
        int result;
        dev_t dev = 0;

        /*
         * Get a range of minor numbers to work with, asking for a dynamic
         * major unless directed otherwise at load time.
         */

        rtd_printk( KERN_WARNING, RTDLOG_TAG, " ***************** rtdlog init module ********************* \n");
        if (rtdlog_major) {
                dev = MKDEV(rtdlog_major, rtdlog_minor);
                result = register_chrdev_region(dev, 1, "rtd-logger");
        } else {
                result = alloc_chrdev_region(&dev, rtdlog_minor, 1, "rtd-logger");
                rtdlog_major = MAJOR(dev);
        }
        if (result < 0) {
                rtd_printk( KERN_ERR, RTDLOG_TAG, "rtdlog: can't get major %d\n", rtdlog_major);
                return result;
        }

        rtd_printk( KERN_WARNING, RTDLOG_TAG, "rtdlog:get result:%d,get dev:0x%08x,major:%d\n", result, dev, rtdlog_major);

        rtdlog_class = class_create(THIS_MODULE, "rtd-logger");
        if (IS_ERR(rtdlog_class))
                return PTR_ERR(rtdlog_class);

        device_create(rtdlog_class, NULL, dev, NULL, "rtd-logger");

        /*
         * allocate the devices
         */
        rtdlog_drv_dev = kmalloc(sizeof(struct rtdlog_dev), GFP_KERNEL);
        if (!rtdlog_drv_dev) {
                device_destroy(rtdlog_class, dev);
                result = -ENOMEM;
                goto fail;  /* Make this more graceful */
        }
        memset(rtdlog_drv_dev, 0, sizeof(struct rtdlog_dev));

        //initialize device structure
        sema_init(&rtdlog_drv_dev->sem, 1);
        cdev_init(&rtdlog_drv_dev->cdev, &rtdlog_fops);
        rtdlog_drv_dev->cdev.owner = THIS_MODULE;
        rtdlog_drv_dev->cdev.ops = &rtdlog_fops;
        result = cdev_add(&rtdlog_drv_dev->cdev, dev, 1);
        /* Fail gracefully if need be */
        if (result) {
                device_destroy(rtdlog_class, dev);
                kfree(rtdlog_drv_dev);
                rtd_printk( KERN_ERR, RTDLOG_TAG, "Error %d adding cdev rtdlog", result);
                goto fail;
        }

#ifdef CONFIG_PM
        rtdlog_platform_devs = platform_device_register_simple("rtd-logger", -1, NULL, 0);

        if(platform_driver_register(&rtdlog_device_driver) != 0) {
                device_destroy(rtdlog_class, dev);
                cdev_del(&rtdlog_drv_dev->cdev);
                kfree(rtdlog_drv_dev);
                rtdlog_platform_devs = NULL;
                goto fail;  /* Make this more graceful */
        }
#endif  //CONFIG_PM

        /************init work quene for watchdog dump log**************/
        p_dumpqueue = create_workqueue("rtdlog dump queue");
        //p_dumpqueue = create_singlethread_workqueue("rtdlog dump queue");
        if(!p_dumpqueue){
                rtd_printk( KERN_ERR, RTDLOG_TAG, "Error create dump queue worker fail!!!\n");
                goto fail;
        }

        INIT_WORK(&DumpWork_a1.work, rtdlog_watchdog_dump);
        INIT_WORK(&DumpWork_a2.work, rtdlog_watchdog_dump);
        INIT_WORK(&DumpWork_v1.work, rtdlog_watchdog_dump);
        INIT_WORK(&DumpWork_v2.work, rtdlog_watchdog_dump);
        INIT_WORK(&DumpWork_k.work, rtdlog_watchdog_dump);

        return 0; /* succeed */

fail:
        return result;
}

static void __exit rtdlog_cleanup_module(void)
{
        int i = 0;
        dev_t dev = MKDEV(rtdlog_major, rtdlog_minor);

        rtd_printk( KERN_WARNING, RTDLOG_TAG, "rtdlog clean module\n");

        /* Get rid of our char dev entries */
        if (rtdlog_drv_dev) {
                device_destroy(rtdlog_class, dev);
                cdev_del(&rtdlog_drv_dev[i].cdev);
                kfree(rtdlog_drv_dev);
#ifdef CONFIG_PM
                platform_device_unregister(rtdlog_platform_devs);
#endif
        }

        unregister_chrdev_region(dev, 1);
}

module_init(rtdlog_init_module);
module_exit(rtdlog_cleanup_module);
