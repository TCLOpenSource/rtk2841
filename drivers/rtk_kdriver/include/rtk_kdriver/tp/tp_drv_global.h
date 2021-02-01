#ifndef __TP_DRV_GLOBAL_H__
#define __TP_DRV_GLOBAL_H__

#include <linux/mutex.h>

#include <tp/tp_def.h>
#include <tp/tp_drv_api.h>
#include <tp/tp_drv_lock.h>

/* locker */
#if 0
extern struct mutex rhal_tp_mutex;
extern struct mutex tp_buf_mutex;
#else
static DEFINE_MUTEX(rhal_tp_mutex);
static DEFINE_MUTEX(tp_buf_mutex);
#endif

extern struct mutex tp_mutexlocklist_mutex;

#define _tp_mutexlocklist_lock()        mutex_lock(&tp_mutexlocklist_mutex)
#define _tp_mutexlocklist_unlock()        mutex_unlock(&tp_mutexlocklist_mutex)

#define _tp_lock() \
        mutex_lock(&rhal_tp_mutex); \
        //Tp_Locker_SetLockFunction("_tp_lock", __FUNCTION__)

#define _tp_unlock() \
        mutex_unlock(&rhal_tp_mutex); \
        //Tp_Locker_ClearLockFunction("_tp_lock", __FUNCTION__)


#define _tp_buf_lock() \
        mutex_lock(&tp_buf_mutex); \
        //Tp_Locker_SetLockFunction("_tp_buf_lock", __FUNCTION__)

#define _tp_buf_unlock() \
        mutex_unlock(&tp_buf_mutex); \
        //Tp_Locker_ClearLockFunction("_tp_buf_lock", __FUNCTION__)

/* define value */
#define LOG_DISPLAY_TIME_MS    3000

/* TP driver structure */
typedef struct {
        UINT8 hardware_reseted;

        /* saved allocated memory pointer */
        void *info_pack_buf_cached;
        UINT8 *section_data_buf_of_pid_filter;

        void *start_code_pack_buf_cached;

        /* tpi setting */
        TPK_TP_INPUT_PARAM_T tpi[MAX_TPI_COUNT];

        /* tp status */
        TPK_TP_STATUS_T tp[MAX_TP_COUNT];

        /* tpp status */
        TPK_TPP_STATUS_T tpp[MAX_TP_P_COUNT];

        /* ring buffer status */
        struct task_struct *thread_dumpdata;
        UINT8 dumpdata_start;

        /* pid status (base on tp_id) */
        TPK_TP_PID_STATUS_T tp_pid[MAX_TP_COUNT];

        /* section status */
        TPK_SEC_FILTER_STATUS_T sec[MAX_SEC_COUNT];
        struct task_struct *sec_assemble;
        UINT8 sec_asm_start;

        struct task_struct *tp_dbg_t;
        UINT8 tp_dbg_t_start;
        /* tp out status */
        TPK_TPOUT_STATUS_T tpout[MAX_TPOUT_COUNT];

        /* mtp status */
        TPK_MTP_STATUS_T mtp[MAX_MTP_MODULE_SUPPORT];

        /* ts port status */
        TPK_TP_SOURCE_T src_to_ts_port[MAX_TS_COUNT];
        TPK_ALGO_KEYSEL_T pid_desc[MAX_KEY_COUNT];

        int hw_reset;
        UINT8 tp_irq_enable;
        char proc_read_message[PROC_READ_BUFFER_SIZE];
#ifdef CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT
        UINT8 need_to_change_input_source[MAX_TP_COUNT];
        UINT32 tp_input_monitor_virt_addr;
        UINT32 tp_input_monitor_phys_addr;
#endif
} TP_DRV_T;

extern TP_DRV_T* pTp_drv;
extern UINT32 logStatusFlag[MAX_TP_COUNT];
extern TP_DRV_MUTEXLOCK_T* pTp_MutexLockList;
extern UINT32 debug_log_interval_ms;
extern UINT32 status_log_interval_ms;
extern UINT8 tp_log_onoff;
//extern UINT8 verbos_log_en;
//extern UINT8 info_log_en;
//extern UINT8 warning_log_en;
//extern UINT8 tp_cnt_log_en;
//extern UINT8 pcr_log_en;
//extern UINT8 buffer_log_en;
//extern UINT8 pid_log_en;
//extern UINT8 sec_log_en;
//extern UINT8 sec_deliver_log_en;
//extern UINT8 pid_filter_en;
//extern UINT16 sec_deliver_max_data_cnt;
//extern UINT8 tp_src_log_en;
//extern UINT8 tp_func_trace_en;
//extern UINT8 startcode_log_en;
//extern UINT8 mtp_log_en;
extern struct   file *rec_fd[MAX_TP_COUNT];
extern UINT8 tp_file_path[MAX_TP_COUNT][256];
extern struct   file *rec_mtp_fd;
extern UINT32   rec_mtp_id;
//extern UINT8  dump_tp_pvr_buff_en;
extern UINT16 dump_tp_pvr_buff_pid[MAX_TP_COUNT];
extern INT32 tp_tpoclk_dbg_en;
extern UINT8 tp_tpoclk_dbg_div;

TP_EXTERN INT32 create_tp_controller(void);
TP_EXTERN void release_tp_controller(void);

#define CHECK_TP_STRUCTURE()    \
{ \
        if(pTp_drv == NULL) \
        { \
                TP_WARNING("tp structure not init, pTp_drv=%p\n", pTp_drv); \
                return TPK_NOT_INIT; \
        } \
}

#define CHECK_TP_STRUCTURE_RT_VOID()    \
{ \
        if(pTp_drv == NULL) \
        { \
                TP_WARNING("tp structure not init, pTp_drv=%p\n", pTp_drv); \
                return; \
        } \
}

#define CHECK_TP_STRUCTURE_RT_NULL()    \
{ \
        if(pTp_drv == NULL) \
        { \
                TP_WARNING("tp structure not init, pTp_drv=%p\n", pTp_drv); \
                return NULL; \
        } \
}

#define TP_PROC_DIR                        "rhal_tp"
#define TP_PROC_ENTRY                      "dbg"
#define TP_PROC_ENTRY_MONITOR              "monitor"
#define TP_PROC_ENTRY_REGDUMP              "regdump"
#define TP_PROC_ENTRY_PIDLIST              "pidlist"
#define TP_PROC_ENTRY_MUTEX                "mutex"

#define TP_PROC_PARAM_PRESET_ALLOFF         "preset_off"                /*  a preset for log off */
#define TP_PROC_PARAM_PRESET_BASIC          "preset_basic"              /*  a preset for basic log */
#define TP_PROC_PARAM_PRESET_NIGHTRUN       "preset_nightrun"           /*  a preset for night run */
#define TP_PROC_PARAM_LOG_ONOFF             "log_onoff="                /*  enable & disable display TP log (0: disable display; 1: enable display) */
#define TP_PROC_PARAM_DBG_LOG_TIME          "log_interval="             /*  set debug log display interval (ms) */
#define TP_PROC_PARAM_VERBOSE_LOG_EN        "log_verbose="              /*  open & close log for VERBOSE (0: disable; 1: enable) */
#define TP_PROC_PARAM_INFO_LOG_EN           "log_info="                 /*  open & close log for INFO (0: disable; 1: enable) */
#define TP_PROC_PARAM_WARNING_LOG_EN        "log_warning="              /*  open & close log for WARNING (0: disable; 1: enable) */
#define TP_PROC_PARAM_TRACE_LOG_EN          "log_trace="                /*  open & close log for TRACE (0: disable; 1: enable) */
#define TP_PROC_PARAM_TP_COUNT              "log_tp_cnt="               /*  open & close log for TP counter/error counter/drop counter (0: disable; 1: enable) */
#define TP_PROC_PARAM_PCR                   "log_pcr="                  /*  open & close log for PCR (0: disable; 1: enable) */
#define TP_PROC_PARAM_BUFFER                "log_buffer="               /*  open & close log for buffer status & flow rate (0: disable; 1: enable) */
#define TP_PROC_PARAM_PID_STATUS            "log_pid_list="             /*  open & close log for PID filter list  (0: disable; 1: display at add/remove; 2: display at add/remove and every time interval) */
#define TP_PROC_PARAM_SEC_STAUTS            "log_sec_list="             /*  open & close log for Section filter list (0: disable; 1: display at add/remove; 2: display at add/remove and every time interval) */
#define TP_PROC_PARAM_SEC_DELIVER           "log_sec_deliver="          /*  open & close log for Section deliver log (0: disable; 1: display deliver length; 2: display data content) */
#define TP_PROC_PARAM_PID_EN                "log_pid_en="               /*  Force to enable/disable PID filter (0: disable; 1: enable) */
#define TP_PROC_PARAM_TP_SRC                "log_tp_src="               /*  open & close log for TP & TPOUT source (0: disable; 1: display at every time interval) */
#define TP_PROC_PARAM_RECORD_TS_EN          "record_ts_en="             /*  start & stop record ts from TP ring buffer (0: stop record; 1: start record) */
#define TP_PROC_PARAM_RECORD_TS_MTP_EN      "record_ts_mtp_en="         /*  start & stop record ts from MTP ring buffer (0: stop record; 1: start record) */
#define TP_PROC_PARAM_TPO_DBG_EN            "tpo_dbg_en="               /*  Enable TPO Debug (0: disable; 1: display at every time interval) */
#define TP_PROC_PARAM_TPOCLK_DBG_EN         "tpoclk_dbg_en="            /*  Enable TPO CLK DEBUG(0: disable; 1: enable)*/
#define TP_PROC_PARAM_DUMP_TP_PVR_BUFF_EN   "dump_tp_pvr_buff_en="      /*  Print TP PVR buffer */
#define TP_PROC_PARAM_DUMP_TP_PVR_BUFF_PID  "dump_tp_pvr_buff_pid="     /*  Print TP PVR buffer */
#define TP_PROC_PARAM_DUMP_PID_LIST         "dump_pid_filter_list"      /*  dump pid filter list */
#define TP_PROC_PARAM_RESET                 "hw_reset"                  /*  reset */
#define TP_PROC_PARAM_STARTCODE_LOG_EN      "log_startcode="            /*  open & close log for startcode (0: disable; 1: enable) */
#define TP_PROC_PARAM_MTP_LOG_EN            "log_mtp="                  /*  open & close log for mtp (0: disable; 1: enable) */
#define TP_PROC_PARAM_FR_EN                 "fr_en="                    /*  Enable and Disable Frame Rate Control */
#define TP_PROC_PARAM_MUTEX_DEBUG           "tp_mutex_debug"            /*  dump tp mutex info */
#define TP_PROC_PARAM_RUN_VERIFY_TEST       "run_verify_test="          /*  run verify test */

typedef enum {
        TP_PROC_PRESET_ALLOFF,           /* a preset for log off */
        TP_PROC_PRESET_BASIC,            /* a preset for basic log */
        TP_PROC_PRESET_NIGHTRUN,         /* a preset for night run */
        TP_PROC_LOG_ONOFF,               /* enable & disable display TP log (0: disable display; 1: enable display) */
        TP_PROC_DBG_LOG_TIME,            /* set debug log display interval (ms) */
        TP_PROC_VERBOSE_LOG_EN,          /* open & close log for VERBOSE (0: disable; 1: enable) */
        TP_PROC_INFO_LOG_EN,             /* open & close log for INFO (0: disable; 1: enable) */
        TP_PROC_WARNING_LOG_EN,          /* open & close log for WARNING (0: disable; 1: enable) */
        TP_PROC_TRACE_LOG_EN,            /* open & close log for TRACE (0: disable; 1: enable) */
        TP_PROC_TP_COUNT,                /* open & close log for TP counter/error counter/drop counter (0: disable; 1: enable) */
        TP_PROC_PCR,                     /* open & close log for PCR (0: disable; 1: enable) */
        TP_PROC_BUFFER,                  /* open & close log for buffer status & flow rate (0: disable; 1: enable) */
        TP_PROC_PID_STATUS,              /* open & close log for PID filter list  (0: disable; 1: display at add/remove; 2: display every time interval) */
        TP_PROC_SEC_STAUTS,              /* open & close log for Section filter list (0: disable; 1: display at add/remove; 2: display at add/remove and every time interval) */
        TP_PROC_SEC_DELIVER,             /* open & close log for Section deliver log (0: disable; 1: display deliver length; 2: display data content) */
        TP_PROC_PID_EN,                  /* Force to enable/disable PID filter (0: disable; 1: enable) */
        TP_PROC_TP_SRC,                  /* open & close log for TP & TPOUT source (0: disable; 1: display at source change; 2: display at add/remove and every time interval) */
        TP_PROC_RECORD_TS_EN,            /* start & stop record ts from TP ring buffer (0: stop record; 1: start record) */
        TP_PROC_RECORD_TS_MTP_EN,        /* start & stop record ts from MTP ring buffer (0: stop record; 1: start record) */
        TP_PROC_TPO_DBG_EN,              /* Enable TPO Debug (0: disable; 1: display at every time interval) */
        TP_PROC_TPOCLK_DBG_EN,           /* Enable TPO CLK DEBUG(0: disable; 1: enable)*/
        TP_PROC_DUMP_TP_PVR_BUFF_EN,     /* Dump TP PVR buffer (0: disable; 1 : enabled) */
        TP_PROC_DUMP_TP_PVR_BUFF_PID,    /* PID of Dump TP PVR buffer (0xFFFF: any PID, others: only dump TSP with specified PID */
        TP_PROC_DUMP_PID_LIST,           /* dump pid filter list */
        TP_PROC_RESET,                   /* reset */
        TP_PROC_STARTCODE_LOG_EN,        /* open & close log for startcode (0: disable; 1: enable) */
        TP_PROC_MTP_LOG_EN,              /* open & close log for mtp (0: disable; 1: enable) */
        TP_PROC_FR_EN,                   /* Enable and Disable Frame Rate Control */
        TP_PROC_MUTEX_DEBUG,             /* dump mutex lcok debug info */
        TP_PROC_RUN_VERIFY_TEST,         /* Run TP Verify Test */
        TP_PROC_COUNT,                   /* max number */

} TP_PROC_CMD;

#endif      /* __TP_DRV_GLOBAL_H__ */
