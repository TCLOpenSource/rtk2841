/******************************************************************************
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author yping@realtek.com
 *
 *****************************************************************************/

#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/jiffies.h>
#include <linux/delay.h>
#include <linux/pageremap.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/string.h>

#include <rbus/tp_reg.h>

#include <base_types.h>
#include <tp/tp_def.h>
#include <tp/tp_dbg.h>
#include <tp/tp_ioctl.h>
#include <tp/tp_drv_api.h>
#include <tp/tp_drv.h>
#include <tp/tp_reg_ctrl.h>
#include <tp/tp_drv_global.h>
#include <tp/tp_drv_verify.h>


TP_DRV_T* pTp_drv = NULL;
TP_DRV_MUTEXLOCK_T* pTp_MutexLockList = NULL;
UINT32 logStatusFlag[MAX_TP_COUNT] = {TP_STATUS_LOG_FLAG_NONE, TP_STATUS_LOG_FLAG_NONE, TP_STATUS_LOG_FLAG_NONE, TP_STATUS_LOG_FLAG_NONE};

#if 0
DEFINE_MUTEX(rhal_tp_mutex);
DEFINE_MUTEX(tp_buf_mutex);
#endif

DEFINE_MUTEX(tp_mutexlocklist_mutex);

/* parameters for debug */
struct proc_dir_entry * tp_proc_dir = NULL;
struct proc_dir_entry * tp_proc_entry = NULL;

struct proc_dir_entry * tp_proc_entry_monitor = NULL;
struct proc_dir_entry * tp_proc_entry_regdump = NULL;
struct proc_dir_entry * tp_proc_entry_pidList = NULL;
struct proc_dir_entry * tp_proc_entry_mutex = NULL;

unsigned long tp_dbg_log_level_mask = TP_LOG_LEVEL_ERR | TP_LOG_LEVEL_WARNING | TP_LOG_LEVEL_DEBUG;
unsigned long tp_dbg_log_block_mask = TP_LOG_BLOCK_ALWAYS;

UINT32 debug_log_interval_ms = LOG_DISPLAY_TIME_MS;
UINT32 status_log_interval_ms = 1000;
UINT8 tp_log_onoff = 1;
//UINT8 verbos_log_en = 0;
//UINT8 info_log_en = 0;
//UINT8 warning_log_en = 1;
//UINT8 tp_cnt_log_en = 0;
//UINT8 pcr_log_en = 0;
//UINT8 buffer_log_en = 0;
//UINT8 pid_log_en = 0;
//UINT8 sec_log_en = 0;
//UINT8 sec_deliver_log_en = 0;
//UINT16 sec_deliver_max_data_cnt = 16;
//UINT8 tp_src_log_en = 0;
//UINT8 tp_func_trace_en = 0;
//UINT8 tp_tpo_dbg_en = 0;
INT32 tp_tpoclk_dbg_en = 0;
UINT8 tp_tpoclk_dbg_div = 0x25;
//UINT8 startcode_log_en = 0;
//UINT8 mtp_log_en = 0;
struct  file *rec_fd[MAX_TP_COUNT] = {NULL, NULL, NULL};
UINT8 tp_file_path[MAX_TP_COUNT][256];
struct  file *rec_mtp_fd = NULL;
UINT32  rec_mtp_id;
//UINT8   dump_tp_pvr_buff_en = 0;
UINT16  dump_tp_pvr_buff_pid[MAX_TP_COUNT] = {0xffff, 0xffff, 0xffff, 0xffff};


static const char* cmd_str[TP_PROC_COUNT] = {
        TP_PROC_PARAM_PRESET_ALLOFF,
        TP_PROC_PARAM_PRESET_BASIC,
        TP_PROC_PARAM_PRESET_NIGHTRUN,
        TP_PROC_PARAM_LOG_ONOFF,
        TP_PROC_PARAM_DBG_LOG_TIME,
        TP_PROC_PARAM_VERBOSE_LOG_EN,
        TP_PROC_PARAM_INFO_LOG_EN,
        TP_PROC_PARAM_WARNING_LOG_EN,
        TP_PROC_PARAM_TRACE_LOG_EN,
        TP_PROC_PARAM_TP_COUNT,
        TP_PROC_PARAM_PCR,
        TP_PROC_PARAM_BUFFER,
        TP_PROC_PARAM_PID_STATUS,
        TP_PROC_PARAM_SEC_STAUTS,
        TP_PROC_PARAM_SEC_DELIVER,
        TP_PROC_PARAM_PID_EN,
        TP_PROC_PARAM_TP_SRC,
        TP_PROC_PARAM_RECORD_TS_EN,
        TP_PROC_PARAM_RECORD_TS_MTP_EN,
        TP_PROC_PARAM_TPO_DBG_EN,
        TP_PROC_PARAM_TPOCLK_DBG_EN,
        TP_PROC_PARAM_DUMP_TP_PVR_BUFF_EN,
        TP_PROC_PARAM_DUMP_TP_PVR_BUFF_PID,
        TP_PROC_PARAM_DUMP_PID_LIST,
        TP_PROC_PARAM_RESET,
        TP_PROC_PARAM_STARTCODE_LOG_EN,
        TP_PROC_PARAM_MTP_LOG_EN,
        TP_PROC_PARAM_FR_EN,
        TP_PROC_PARAM_MUTEX_DEBUG,
        TP_PROC_PARAM_RUN_VERIFY_TEST
};

/****************************************/

#define isnumber(c)      (c>=0x30 && c<=0x39)
#define isalphabet(c)    (c>=0x41 && c<=0x5A) || (c>=0x61 && c<=0x7A)
#define isalnum(c)       (isnumber(c) || isalphabet(c))

/***************************************************************************
  ------------------- Proc FS  --------------------
 ****************************************************************************/
#if 0
static UINT8* __find_next_str(UINT8* str)
{
        char* end = str + strlen(str);

        while(str < (UINT8*)end) {
                if (isalnum(*str)) /* is alphabet or number */
                        return str;
                str++;
        }

        return NULL;
}
#endif

static int tp_proc_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
        UINT8 str[128];
        UINT8 rec_file[256];
        UINT8 rec_mtp_file[256];
        UINT32 i;
        UINT8 *cmd = str;
        INT32 input_data, input_data2, enable, temp_data;
        INT32 verify_test_itme;
        UINT8 pid_filter_en = 1, tp_id;
        UINT32 u32_tp_id = 0;
        UINT32 pid_number = 0;
        tp_tp_tf0_cntl_RBUS tp_cntl;
        UINT16 pid_idx;
        UINT8 ddr_buf_idx;
        TPK_PID_REG_PARAM_T pid_reg;
        struct  file *tmp_fd = NULL;
        UINT32 n, j;

        /* check parameter */
        if(buf == NULL) {
                TP_ERROR("buf=%p\n", buf);
                return -EFAULT;
        }

        if (count > 128) { /* procfs write and read has PAGE_SIZE limit */
                TP_WARNING("command too long, set length to 128 Byte\n");
                count = 128;
        }

        if (copy_from_user(str, buf, count)) {
                TP_ERROR("copy_from_user failed! (buf=%p, count=%u)\n", buf, count);
                return -EFAULT;
        }

        str[count - 1] = '\0';
#if 1
        TP_DBG_SIMPLE("proc data: %s\n", str);
#endif

        /* get command string */
        for( i = 0; i < TP_PROC_COUNT; i++) {
                if (strncmp(str, cmd_str[i], strlen(cmd_str[i])) == 0) {
                        TP_DBG_SIMPLE("TP debug command: %s\n", cmd_str[i]);
                        break;
                }
        }

        /* command out of range check */
        if ( i >= TP_PROC_COUNT ) {
                TP_ERROR("Cannot find your command: \"%s\"\n", str);
                return -EINVAL;

        } else {
                /* get parameter */
                cmd += strlen(cmd_str[i]);
                if (sscanf(cmd, "%d", &input_data) < 1) {
                        TP_DBG_SIMPLE("sscanf get more data failed (%s) - there is no more parameter.\n", cmd);
                        //return -EFAULT;
                } else {
                        TP_DBG_SIMPLE("input data=%d\n", input_data);
                }
        }

        switch(i) {
                case TP_PROC_PRESET_ALLOFF: {
                        debug_log_interval_ms = LOG_DISPLAY_TIME_MS;
                        tp_log_onoff = 0;

                        CLEAR_LOG_LEVEL_MASK(TP_LOG_LEVEL_VERBOSE);
                        CLEAR_LOG_LEVEL_MASK(TP_LOG_LEVEL_INFO);
                        CLEAR_LOG_LEVEL_MASK(TP_LOG_LEVEL_WARNING);

                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_CNT);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_PCR);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_BUFFER);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_PID);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_SECTION);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_FRAMER);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_FUNCTIN_CALLER);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_TPOUT);

                        TP_DBG_SIMPLE("Turn Off all TP logs\n");

                        break;
                }
                case TP_PROC_PRESET_BASIC: {
                        debug_log_interval_ms = LOG_DISPLAY_TIME_MS;
                        tp_log_onoff = 1;

                        CLEAR_LOG_LEVEL_MASK(TP_LOG_LEVEL_VERBOSE);
                        CLEAR_LOG_LEVEL_MASK(TP_LOG_LEVEL_INFO);
                        SET_LOG_LEVEL_MASK(TP_LOG_LEVEL_WARNING);

                        SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_CNT);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_PCR);
                        SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_BUFFER);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_PID);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_SECTION);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_FRAMER);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_FUNCTIN_CALLER);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_TPOUT);

                        TP_DBG_SIMPLE("Enable TP Preset Basic log\n");

                        break;
                }
                case TP_PROC_PRESET_NIGHTRUN: {
                        debug_log_interval_ms = LOG_DISPLAY_TIME_MS;
                        tp_log_onoff = 1;

                        CLEAR_LOG_LEVEL_MASK(TP_LOG_LEVEL_VERBOSE);
                        CLEAR_LOG_LEVEL_MASK(TP_LOG_LEVEL_INFO);
                        SET_LOG_LEVEL_MASK(TP_LOG_LEVEL_WARNING);

                        SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_CNT);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_PCR);
                        SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_BUFFER);
                        SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_PID);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_SECTION);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_FRAMER);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_FUNCTIN_CALLER);
                        CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_TPOUT);

                        TP_DBG_SIMPLE("Enable TP Preset Night Run log\n");

                        break;
                }
                case TP_PROC_LOG_ONOFF: {
                        tp_log_onoff = (UINT32)input_data;

                        if ( input_data == 1 ) {
                                TP_DBG_SIMPLE("Enable TP log\n");
                        } else {
                                TP_DBG_SIMPLE("Disable TP log\n");
                        }

                        break;
                }
                case TP_PROC_DBG_LOG_TIME: {
                        TP_DBG_SIMPLE("Original TP debug log interval time :%d(ms)\n", input_data);

                        debug_log_interval_ms = (UINT32)input_data;

                        TP_DBG_SIMPLE("Set TP debug log interval time to %d(ms)\n", input_data);
                        break;
                }
                case TP_PROC_VERBOSE_LOG_EN: {
                        if(input_data == 1) {
                                SET_LOG_LEVEL_MASK(TP_LOG_LEVEL_VERBOSE);
                        } else {
                                CLEAR_LOG_LEVEL_MASK(TP_LOG_LEVEL_VERBOSE);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP verbos log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP verbos log\n");

                        break;
                }
                case TP_PROC_INFO_LOG_EN: {
                        if(input_data == 1) {
                                SET_LOG_LEVEL_MASK(TP_LOG_LEVEL_INFO);
                        } else {
                                CLEAR_LOG_LEVEL_MASK(TP_LOG_LEVEL_INFO);
                        }

                        if ( input_data == 1 ) {
                                TP_DBG_SIMPLE("Enable TP info log\n");
                        } else {
                                TP_DBG_SIMPLE("Disable TP info log\n");
                        }

                        break;
                }
                case TP_PROC_WARNING_LOG_EN: {
                        if(input_data == 1) {
                                SET_LOG_LEVEL_MASK(TP_LOG_LEVEL_WARNING);
                        } else {
                                CLEAR_LOG_LEVEL_MASK(TP_LOG_LEVEL_WARNING);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP warning log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP warning log\n");

                        break;
                }
                case TP_PROC_TRACE_LOG_EN: {
                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_FUNCTIN_CALLER);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_FUNCTIN_CALLER);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP function trace log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP function trace log\n");

                        break;
                }
                case TP_PROC_TP_COUNT: {

                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_CNT);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_CNT);
                        }


                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP packet count log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP packet count log\n");

                        break;
                }
                case TP_PROC_PCR: {
                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_PCR);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_PCR);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP PCR log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP PCR log\n");

                        break;
                }
                case TP_PROC_BUFFER: {
                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_BUFFER);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_BUFFER);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP buffer log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP buffer log\n");

                        break;
                }
                case TP_PROC_PID_STATUS: {
                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_PID);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_PID);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP pid status log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP pid status log\n");

                        break;
                }
                case TP_PROC_SEC_STAUTS: {
                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_SECTION);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_SECTION);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP section status log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP section status log\n");

                        break;
                }
                case TP_PROC_SEC_DELIVER: {
#if 0
                        sec_deliver_log_en = (UINT8)input_data;

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP section deliver log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP section deliver log\n");

                        if(sec_deliver_log_en > 1) {
                                cmd = __find_next_str(cmd);
                                if(cmd != NULL) {
                                        if (sscanf(cmd, "%d", &input_data) < 1) {
                                                TP_WARNING("sscanf get data failed (%s)\n", cmd);
                                                return -EFAULT;
                                        } else {
                                                TP_DBG_SIMPLE("deliver max data count=%d\n", input_data);
                                        }
                                        sec_deliver_max_data_cnt = (UINT16)input_data;
                                }
                        }
#endif
                        break;
                }
                case TP_PROC_PID_EN: {
                        tp_id = (UINT8)input_data;
#if 0
                        cmd = __find_next_str(cmd);
                        if(cmd != NULL) {
                                if (sscanf(cmd, "%d", &input_data) < 1) {
                                        TP_WARNING("sscanf get data failed (%s)\n", cmd);
                                        return -EFAULT;
                                } else {
                                        TP_INFO("input data2=%d\n", input_data);
                                }
                                pid_filter_en = (UINT16)input_data;
                        }
#endif
                        if (sscanf(cmd, "%d %d", &input_data, &input_data2) < 1) {
                                TP_WARNING("sscanf get data failed (%s)\n", cmd);
                                return -EFAULT;
                        } else {
                                TP_INFO("input data2=%d\n", input_data2);
                        }
                        pid_filter_en = (UINT16)input_data2;

                        if(pid_filter_en) {
                                /* enable pid filter */
                                tp_cntl.pid_en = 1;
                                _tp_lock();
                                Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, 1);
                                _tp_unlock();
                                TP_DBG_SIMPLE("Enable TP%d pid filter\n", tp_id);
                        } else {
                                if(tp_id == 0) {
                                        pid_idx = TP0_FIRST_PID_FILTER_IDX;
                                        ddr_buf_idx = TP0_BUFFER_MASS_DATA;
                                } else if(tp_id == 1) {
                                        pid_idx = TP1_FIRST_PID_FILTER_IDX;
                                        ddr_buf_idx = TP1_BUFFER_MASS_DATA;
                                } else {
                                        pid_idx = TP2_FIRST_PID_FILTER_IDX;
                                        ddr_buf_idx = TP2_BUFFER_MASS_DATA;
                                }

                                _tp_lock();
                                /* set ddr buffer to mass data buf_idx, other parameter won't change */
                                Tp_GetPidParam(pid_idx, &pid_reg);
                                pid_reg.ddr_q = ddr_buf_idx;
                                Tp_SetPidParam(pid_idx, pid_reg);

                                /* disable pid filter */
                                tp_cntl.pid_en = 1;   /* set select bit=1 */
                                Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, 0);
                                _tp_unlock();

                                TP_DBG_SIMPLE("Disable TP%d pid filter\n", tp_id);

                        }
                        break;
                }
                case TP_PROC_TP_SRC: {
                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_FRAMER);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_FRAMER);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP source log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP source log\n");

                        break;
                }
                case TP_PROC_RECORD_TS_EN: {
                        //cmd +=strlen(cmd_str[i]);
                        if (sscanf(cmd, "%d tp=%u tspath=%256s", &enable, &u32_tp_id, rec_file) < 1) {
                                TP_ERROR("sscanf get data failed (%s)\n", cmd);
                                return -EFAULT;
                        } else {
                                TP_DBG_SIMPLE("record_ts_en=%d ,rec_tp_id=%d ,ts_record file=%s\n", enable, u32_tp_id, rec_file);
                                if(enable) {
                                        if(rec_fd[u32_tp_id]) {
                                                for ( n = 0; n < MAX_TP_COUNT; n++) {
                                                        if (0 == strncmp(rec_file, tp_file_path[n], strlen(tp_file_path[n])))
                                                                break;
                                                }

                                                if(n < MAX_TP_COUNT) {
                                                        TP_ERROR("File path is same, %s\n", rec_file);
                                                        return -EEXIST;
                                                }

                                                TP_DBG_SIMPLE("TS Record Stopped\n");
                                                filp_close(rec_fd[u32_tp_id], NULL);
                                                rec_fd[u32_tp_id] = NULL;
                                                memset(tp_file_path[u32_tp_id], 0, sizeof(tp_file_path[u32_tp_id]));
                                        }

                                        tmp_fd = filp_open(rec_file, O_RDWR | O_CREAT | O_TRUNC, 0);
                                        if(IS_ERR(tmp_fd)) {
                                                TP_ERROR("Start Rec TS failed, open %s failed\n", rec_file);
                                        } else {
                                                for (n = 0; n < MAX_TP_COUNT; n++) {
                                                        if (0 == strncmp(rec_file, tp_file_path[n], strlen(rec_file)))
                                                                break;
                                                }

                                                if(n < MAX_TP_COUNT) {
                                                        TP_WARNING("File path is same, %s\n", rec_file);
                                                } else {
                                                        TP_DBG_SIMPLE("Start Rec TS to - %s,rec_fd=%p\n", rec_file, tmp_fd);
                                                        memcpy(tp_file_path[u32_tp_id], rec_file, strlen(rec_file));
                                                        rec_fd[u32_tp_id] = tmp_fd;
                                                }
                                        }
                                } else {
                                        if(rec_fd[u32_tp_id]) {
                                                TP_DBG_SIMPLE("TS Record Stopped\n");
                                                filp_close(rec_fd[u32_tp_id], NULL);
                                                rec_fd[u32_tp_id] = NULL;
                                                memset(tp_file_path[u32_tp_id], 0, sizeof(tp_file_path[u32_tp_id]));
                                        }
                                }
                        }

                        break;
                }
                case TP_PROC_RECORD_TS_MTP_EN: {
                        if (sscanf(cmd, "%d mtp=%u tspath=%256s", &enable, &rec_mtp_id, rec_mtp_file) < 1) {
                                TP_WARNING("sscanf get data failed (%s)\n", cmd);
                                return -EFAULT;
                        } else {
                                TP_DBG_SIMPLE("record_ts_mtp_en=%d, rec_mtp_id=%d, ts_mtp_record_file=%s\n", enable, rec_mtp_id, rec_mtp_file);
                                if(enable) {
                                        if(rec_mtp_fd) {
                                                TP_DBG_SIMPLE("MTP fd exit, MTP TS Record Stopping...\n");
                                                filp_close(rec_mtp_fd, NULL);
                                                rec_mtp_fd = NULL;
                                        }
                                        rec_mtp_fd = filp_open(rec_mtp_file, O_RDWR | O_CREAT | O_TRUNC, 0);

                                        if(rec_mtp_fd)
                                                TP_DBG_SIMPLE("Start Rec MTP TS to - %s, rec_mtp_fd=%p\n", rec_mtp_file, rec_mtp_fd);
                                        else
                                                TP_DBG_SIMPLE("Start Rec MTP TS failed, open %s failed\n", rec_mtp_file);
                                } else {
                                        if(rec_mtp_fd) {
                                                TP_DBG_SIMPLE("MTP TS Record Stopped\n");
                                                filp_close(rec_mtp_fd, NULL);
                                                rec_mtp_fd = NULL;
                                        }
                                }
                        }

                        break;
                }
                case TP_PROC_TPO_DBG_EN: {
                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_TPOUT);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_TPOUT);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TPO debug log\n");
                        else
                                TP_DBG_SIMPLE("Disable TPO debug log\n");

                        break;
                }
                case TP_PROC_TPOCLK_DBG_EN: {
                        int pre_div = 0, post_div = 0, tp_tpoclk_dbg_en_tmp = 0;

                        if (sscanf(cmd, "%d pre_div=%d post_div=%d", &tp_tpoclk_dbg_en, &pre_div, &post_div) < 1) {
                                TP_ERROR("sscanf get data failed (%s)\n", cmd);
                                return -EFAULT;
                        } else {
                                tp_tpoclk_dbg_en = (UINT8)tp_tpoclk_dbg_en_tmp;
                                tp_tpoclk_dbg_div = post_div << 4 | pre_div;
                                TP_WARNING("tp_tpoclk_dbg_en=%d,tp_tpoclk_dbg_div = %x\n", tp_tpoclk_dbg_en, tp_tpoclk_dbg_div);
                        }
                        break;
                }
                case TP_PROC_DUMP_TP_PVR_BUFF_EN: {
                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_PVR);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_PVR);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable dump tp PVR buff log\n");
                        else
                                TP_DBG_SIMPLE("Disable dump tp PVR buff log\n");

                        break;
                }
                case TP_PROC_DUMP_TP_PVR_BUFF_PID: {
                        TP_DBG_SIMPLE("cmd = %s\n", cmd);

                        if (sscanf(cmd, "%d, %x,%d", &u32_tp_id, &pid_number, &temp_data) < 2 || pid_number > 0xffff) {
                                TP_WARNING("get dump pvr pid setting failed - invalid parameter (%s)(%d)(%x)(%d)\n", cmd, u32_tp_id, pid_number, temp_data );
                                return -EFAULT;
                        }

                        /* for K3, only support PVR on TP0 & TP1 */
                        if ( u32_tp_id >= 2 ) {
                                TP_WARNING("get dump pvr pid setting failed - invalid parameter of TP number %d, only support PVR(K3*) on TP0 & TP1\n", u32_tp_id);
                                return -EFAULT;
                        }

                        dump_tp_pvr_buff_pid[u32_tp_id] = (UINT16)(pid_number & 0xffff);

                        if ( pid_number == 0xffff ) {
                                TP_DBG_SIMPLE("Set dump TP%d PVR buffer all pid data.\n", u32_tp_id);
                        } else {
                                TP_DBG_SIMPLE("Set dump TP%d PVR buffer Pid.\n", u32_tp_id);
                        }

                        if ( !CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_PVR) )
                                TP_DBG_SIMPLE("But you do not enable PVR buff log\n");

                        break;
                }
                case TP_PROC_DUMP_PID_LIST: {
                        _tp_lock();
                        TP_DBG_SIMPLE("\n");
                        TP_DBG_SIMPLE("=================================================================================================================================\n");

                        for ( j = 0 ; j < MAX_TP_COUNT ; j++ ) {
                                Tp_Cmd_Dump_PID_filter_Status(j, NULL);
                        }
                        TP_DBG_SIMPLE("=================================================================================================================================\n");
                        _tp_unlock();
                        break;
                }
                case TP_PROC_RESET: {
                        TP_DBG_SIMPLE("Do TP HW Reset!\n");

                        RHAL_SetTPHardwareReset(1);

                        break;
                }
                case TP_PROC_STARTCODE_LOG_EN: {
                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_STARTCODE);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_STARTCODE);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP start code log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP start code log\n");

                        break;
                }
                case TP_PROC_MTP_LOG_EN: {
                        if(input_data == 1) {
                                SET_LOG_BLOCK_MASK(TP_LOG_BLOCK_MTP);
                        } else {
                                CLEAR_LOG_BLOCK_MASK(TP_LOG_BLOCK_MTP);
                        }

                        if ( input_data == 1 )
                                TP_DBG_SIMPLE("Enable TP MTP log\n");
                        else
                                TP_DBG_SIMPLE("Disable TP MTP log\n");

                        break;
                }
                case TP_PROC_FR_EN: {
                        if (sscanf(cmd, "%d %d", &enable, &u32_tp_id) < 1) {
                                TP_ERROR("sscanf get data failed (%s)\n", cmd);
                                return -EFAULT;
                        } else {
                                RHAL_MTPFrameControl(u32_tp_id, enable);
                                TP_DBG_SIMPLE("fr_en=%d ,tp=%d\n", enable, u32_tp_id);
                        }
                        break;
                }

                case TP_PROC_MUTEX_DEBUG: {
                        UINT32 numOfMutex = 0, numOfFun = 0;
                        struct list_head * ilist = NULL, * jlist = NULL;

                        _tp_mutexlocklist_lock();

                        TP_DBG_SIMPLE("--------------------[TP Mutex Debug]--------------------\n");

                        if (pTp_MutexLockList) {
                                list_for_each(ilist, &pTp_MutexLockList->list) {
                                        TP_DRV_MUTEXLOCK_T* tmp = list_entry(ilist, TP_DRV_MUTEXLOCK_T, list);
                                        if (tmp->funCallStackHead) {
                                                TP_DBG_SIMPLE("========[mutex_%u][%s]========\n", numOfMutex, tmp->name);

                                                numOfFun = 0;
                                                list_for_each(jlist, &tmp->funCallStackHead->funName_list) {
                                                        TP_DRV_MUTEXFUNNAME_T* tmpFun = list_entry(jlist, TP_DRV_MUTEXFUNNAME_T, funName_list);
                                                        if (numOfFun < TP_MUTEX_DBG_NUM_FUN_CALL) {
                                                                TP_DBG_SIMPLE("[%u][%s][%d]\n", numOfFun, tmpFun->funName, tmpFun->lock);
                                                        } else {
                                                                TP_ERROR("The fun call stack is more than %d\n", TP_MUTEX_DBG_NUM_FUN_CALL);
                                                                break;
                                                        }
                                                        numOfFun++;
                                                }
                                        }
                                        numOfMutex++;
                                }
                                TP_DBG_SIMPLE("Total number of Mutex in TP driver: %u\n", numOfMutex);
                        } else
                                TP_ERROR("There is no mutex lock in TP driver.\n");

                        TP_DBG_SIMPLE("--------------------[TP Mutex Debug]--------------------\n");
                        _tp_mutexlocklist_unlock();
                        break;
                }

                case TP_PROC_RUN_VERIFY_TEST: {
                        if (sscanf(cmd, "%d %256s", &verify_test_itme, rec_file) < 1) {
                                TP_ERROR("sscanf get data failed (%s)\n", cmd);
                                return -EFAULT;
                        }
                        if(verify_test_itme == 1)
                                TPVerify_ModuleTest(rec_file);
                        break;
                }

                default: {
                        TP_ERROR("unsupport proc command=%s\n", str);
                        return -EINVAL;
                }
        }

        return count;

}

static int tp_proc_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
        int len = strlen(pTp_drv->proc_read_message);
        if(copy_to_user(buf, pTp_drv->proc_read_message, len)) {
                TP_WARNING("Copy proc data to user space failed\n");
                return 0;
        }

        if (*ppos == 0)
                *ppos += len;
        else
                len = 0;
        return len;
}

int tp_proc_read_monitor(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
        char *str;
        int len;
        TPK_TP_ENGINE_T tp_id;
        TPK_TPP_ENGINE_T tpp_id;
        tp_tp_tf_out_frmcfg_RBUS tp_tf_out_frmcfg_data;
        UINT32 pre_div, post_div, tp_out_speed;
        tp_tp_tf0_p_cntl_RBUS tpp_tf_cntl_data;
        tp_tp_tf0_p_frmcfg_RBUS tpp_tf_frm_data;
        tp_tp_tf0_cntl_RBUS tp_tf_cntl_data;
        tp_tp_tf0_frmcfg_RBUS tp_tf_frm_data;
        UINT64 pErrPkt, pRevPkt, pDropPkt;
        TP_BUFFER_PARAM_T buffer_param;
        UINT8 fr_status, keep, prefix_sel;
        unsigned char *tp_source_name[] = {"TPI_0", "TPI_1", "TPI_2", "InternalDemod"};
        unsigned char *tp_out_source_name[] = {"memory", "TPI_0", "TPI_1", "TPI_2"};
        //unsigned char *clk_latch_name[] = {"rising", "falling"};
        unsigned char *mode_name[] = {"non-MTP", "MTP"};

        if (*ppos != 0) {
                TP_WARNING("*ppos!=0 just exit\n");
                return 0;
        }

        //TP_DBG("tp_proc_read_monitor Enter 01 *ppos=0x%llx count=0x%x\n", *ppos, count);

        len = 0;
        str = kmalloc(65536, GFP_KERNEL);
        if (str) {
                memset(str, 0, 65536);

                for(tp_id = TP_TP0; tp_id < MAX_TP_COUNT; tp_id++) {
                        len = sprintf(str, "%s--------------- TP%d ---------------\n", str, tp_id);

                        Tp_GetTpCtrlReg(tp_id, (UINT32*)&tp_tf_cntl_data);
                        Tp_GetTpFrmReg(tp_id, (UINT32*)&tp_tf_frm_data);

                        pRevPkt = pTp_drv->tp[tp_id].tp_pkt_cnt.pkt;
                        pDropPkt = pTp_drv->tp[tp_id].tp_pkt_cnt.droppedPkt;
                        pErrPkt = pTp_drv->tp[tp_id].tp_pkt_cnt.errorPkt;

                        len = sprintf(str, "%sfrm_en=%d mode=%s tp_src=%s pid_en=%d serial=%d ci=%d de_en=%d cnt=%llx drop=%llx Err=%llx\n", str, tp_tf_frm_data.frm_en, mode_name[tp_tf_cntl_data.mode], tp_source_name[tp_tf_cntl_data.src_sel_h << 1 | tp_tf_cntl_data.src_sel_l], tp_tf_cntl_data.pid_en, tp_tf_frm_data.serial, tp_tf_cntl_data.ci_mode, tp_tf_cntl_data.de_en, pRevPkt, pDropPkt, pErrPkt);

                        Tp_Get_MTPFrameControlStatus(tp_id, &fr_status);
                        Tp_Get_PrefixStatus(tp_id, &keep, &prefix_sel);

                        if(tp_id == TP_TP0) {
                                Tp_Get_Buffer(TP0_BUFFER_MASS_DATA, &buffer_param);
                                len = sprintf(str, "%s[TS_DATA] B=0x%08x L=0x%08x R=0x%08x W=0x%08x RR =%dKB/s RP((demux)%08x/(tp_sec)%08x/(pvr)%08x)\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP, pTp_drv->tp_pid[tp_id].ringrate_KB, pTp_drv->tp[tp_id].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[tp_id].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[tp_id].mass_buffer.RP_Connect[DUMP_BUFFER_RP]);
                                Tp_Get_Buffer(TP0_BUFFER_INFO_PACK, &buffer_param);
                                len = sprintf(str, "%s[INFO]    B=0x%08x L=0x%08x R=0x%08x W=0x%08x\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP);
                                Tp_Get_Buffer(TP0_START_CODE_PACK, &buffer_param);
                                len = sprintf(str, "%s[START]   B=0x%08x L=0x%08x R=0x%08x W=0x%08x\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP);
                                Tp_Get_MTP_Buffer(TP_TP0_MTP, &buffer_param);
                                len = sprintf(str, "%s[MTP]     B=0x%08x L=0x%08x R=0x%08x W=0x%08x inited=%d FR=%d keep=%d prefix_sel=%d\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP, pTp_drv->mtp[tp_id].mtp_buf_param.inited, fr_status, keep, prefix_sel);
                        }

                        if(tp_id == TP_TP1) {
                                Tp_Get_Buffer(TP1_BUFFER_MASS_DATA, &buffer_param);
                                len = sprintf(str, "%s[TS_DATA] B=0x%08x L=0x%08x R=0x%08x W=0x%08x RR =%dKB/s RP((demux)%08x/(tp_sec)%08x/(pvr)%08x)\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP, pTp_drv->tp_pid[tp_id].ringrate_KB, pTp_drv->tp[tp_id].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[tp_id].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[tp_id].mass_buffer.RP_Connect[DUMP_BUFFER_RP]);
                                Tp_Get_Buffer(TP1_BUFFER_INFO_PACK, &buffer_param);
                                len = sprintf(str, "%s[INFO]    B=0x%08x L=0x%08x R=0x%08x W=0x%08x\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP);
                                Tp_Get_Buffer(TP1_START_CODE_PACK, &buffer_param);
                                len = sprintf(str, "%s[START]   B=0x%08x L=0x%08x R=0x%08x W=0x%08x\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP);
                                Tp_Get_MTP_Buffer(TP_TP1_MTP, &buffer_param);
                                len = sprintf(str, "%s[MTP]     B=0x%08x L=0x%08x R=0x%08x W=0x%08x inited=%d FR=%d keep=%d prefix_sel=%d\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP, pTp_drv->mtp[tp_id].mtp_buf_param.inited, fr_status, keep, prefix_sel);
                        }

                        if(tp_id == TP_TP2) {
                                Tp_Get_Buffer(TP2_BUFFER_MASS_DATA, &buffer_param);
                                len = sprintf(str, "%s[TS_DATA] B=0x%08x L=0x%08x R=0x%08x W=0x%08x RR =%dKB/s RP((demux)%08x/(tp_sec)%08x/(pvr)%08x)\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP, pTp_drv->tp_pid[tp_id].ringrate_KB, pTp_drv->tp[tp_id].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[tp_id].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[tp_id].mass_buffer.RP_Connect[DUMP_BUFFER_RP]);
                                Tp_Get_Buffer(TP2_BUFFER_INFO_PACK, &buffer_param);
                                len = sprintf(str, "%s[INFO]    B=0x%08x L=0x%08x R=0x%08x W=0x%08x\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP);
                                Tp_Get_MTP_Buffer(TP_TP2_MTP, &buffer_param);
                                len = sprintf(str, "%s[MTP]     B=0x%08x L=0x%08x R=0x%08x W=0x%08x inited=%d FR=%d keep=%d prefix_sel=%d\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP, pTp_drv->mtp[tp_id].mtp_buf_param.inited, fr_status, keep, prefix_sel);
                        }

                        if(tp_id == TP_TP3) {
                                Tp_Get_Buffer(TP3_BUFFER_MASS_DATA, &buffer_param);
                                len = sprintf(str, "%s[TS_DATA] B=0x%08x L=0x%08x R=0x%08x W=0x%08x RR =%dKB/s RP((demux)%08x/(tp_sec)%08x/(pvr)%08x)\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP, pTp_drv->tp_pid[tp_id].ringrate_KB, pTp_drv->tp[tp_id].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[tp_id].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[tp_id].mass_buffer.RP_Connect[DUMP_BUFFER_RP]);
                                Tp_Get_Buffer(TP3_BUFFER_INFO_PACK, &buffer_param);
                                len = sprintf(str, "%s[INFO]    B=0x%08x L=0x%08x R=0x%08x W=0x%08x\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP);
                                Tp_Get_MTP_Buffer(TP_TP3_MTP, &buffer_param);
                                len = sprintf(str, "%s[MTP]     B=0x%08x L=0x%08x R=0x%08x W=0x%08x inited=%d FR=%d keep=%d prefix_sel=%d\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP, pTp_drv->mtp[tp_id].mtp_buf_param.inited, fr_status, keep, prefix_sel);
                        }
                }

                for(tpp_id = TP_TPP0; tpp_id < MAX_TP_P_COUNT; tpp_id++) {
                        pRevPkt = pTp_drv->tpp[tpp_id].tpp_pkt_cnt.pkt;
                        pDropPkt = pTp_drv->tpp[tpp_id].tpp_pkt_cnt.droppedPkt;

                        len = sprintf(str, "%s--------------- TPP%d ---------------\n", str, tpp_id);

                        Tp_TPP_GetCtrlReg(tpp_id, (UINT32*)&tpp_tf_cntl_data);
                        Tp_TPP_GetFrmReg(tpp_id, (UINT32*)&tpp_tf_frm_data);
                        len = sprintf(str, "%sfrm_en=%d mode=%s tp_src=%s pid_en=%d serial=%d ci=%d de_en=%d cnt=%llx drop=%llx\n", str, tpp_tf_frm_data.frm_en, mode_name[tpp_tf_cntl_data.mode], tp_source_name[tpp_tf_cntl_data.src_sel_h << 1 | tpp_tf_cntl_data.src_sel_l], tpp_tf_cntl_data.pid_en, tpp_tf_frm_data.serial, tpp_tf_cntl_data.ci_mode, tpp_tf_cntl_data.de_en, pRevPkt, pDropPkt);

                        Tpp_Get_Buffer(tpp_id, &buffer_param);
                        len = sprintf(str, "%s[TS_DATA] B=0x%08x L=0x%08x R=0x%08x W=0x%08x\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP);

                        Tp_Get_MTP_Buffer((TPK_TP_MTP_T)tpp_id, &buffer_param);
                        len = sprintf(str, "%s[MTP]     B=0x%08x L=0x%08x R=0x%08x W=0x%08x\n", str, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP);
                }

                len = sprintf(str, "%s--------------- TPOut ---------------\n", str);
                Tp_TPO_GetClkDiv(&pre_div, &post_div);
                tp_tf_out_frmcfg_data.regValue = READ_REG32(TP_TP_TF_OUT_FRMCFG_reg);
                tp_out_speed = (TP_SPEED_MHZ * 100 / (pre_div + 2) / (post_div + 2));
                len = sprintf(str, "%sdata_src=%s in_tpp_out_en=%d in_tp_out_en=%d pre_div=%d post_div=%d speed=%d.%dMhz\n", str, tp_out_source_name[tp_tf_out_frmcfg_data.data_src], tp_tf_out_frmcfg_data.in_tpp_out_en, tp_tf_out_frmcfg_data.in_tp_out_en, pre_div, post_div, tp_out_speed / 100, tp_out_speed % 100);

                {
                        UINT32 tp_pcra_h, tp_pcra, tp_pcrb_h, tp_pcrb;

                        tp_pcra_h  = READ_REG32(TP_TP_PCRA_90K_CNT_HIGH_reg);
                        tp_pcra    = READ_REG32(TP_TP_PCRA_90K_CNT_reg);
                        tp_pcrb_h  = READ_REG32(TP_TP_PCRB_90K_CNT_HIGH_reg);
                        tp_pcrb    = READ_REG32(TP_TP_PCRB_90K_CNT_reg);

                        len = sprintf(str, "%s--------------- PCR ---------------\n", str);
                        len = sprintf(str, "%sTP_PCRA=0x%x/0x%x TP_PCRB=0x%x/0x%x\n",
                                      str, tp_pcra_h, tp_pcra, tp_pcrb_h, tp_pcrb);
                }

                len = strlen(str);

                if(count > len) {
                        if(copy_to_user(buf, str, len)) {
                                TP_WARNING("Copy proc data to user space failed\n");
                                kfree(str);
                                return 0;
                        }

                        if (*ppos == 0)
                                *ppos += len;
                        else
                                len = 0;
                } else {
                        len = 0;
                }

                kfree(str);
        }
        //TP_DBG("tp_proc_read_monitor Exit 06 *ppos=0x%llx count=0x%x len=0x%x\n", *ppos, count, len);
        return len;
}

char *regdump_result;
unsigned long regdump_offset = 0;

int tp_proc_read_regdump(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
        int len;

        if (*ppos == 0) {
                regdump_result = kmalloc(65536, GFP_KERNEL);
                if(regdump_result) {
                        memset(regdump_result, 0, 65536);
                        RHAL_DumpTPRegister(regdump_result);
                        regdump_offset = 0;
                } else {
                        regdump_result = NULL;
                        regdump_offset = 0;
                        TP_ERROR("Fail to malloc in tp_proc_read_regdump\n");
                        return 0;
                }
        }

        len = strlen(regdump_result);

        if( (len - regdump_offset) > count)
                len = count;
        else
                len = len - regdump_offset;

        if(copy_to_user(buf, regdump_result + regdump_offset , len)) {
                kfree(regdump_result);
                regdump_result = NULL;
                regdump_offset = 0;
                return 0;
        }

        *ppos += len;
        regdump_offset = regdump_offset + len;

        if(len == 0) {
                kfree(regdump_result);
                regdump_result = NULL;
                regdump_offset = 0;
        }

        //TP_DBG("tp_proc_read_monitor Exit *ppos=0x%llx count=0x%x len=0x%x\n", *ppos, count, len);
        return len;
}

int tp_proc_read_pidList(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
        char *str;
        int len, i;

        if (*ppos != 0) {
                TP_WARNING("*ppos!=0 just exit\n");
                return 0;
        }

        //TP_DBG("tp_proc_read_monitor Enter 01 *ppos=0x%llx count=0x%x\n", *ppos, count);

        len = 0;
        str = kmalloc(65536, GFP_KERNEL);
        if (str) {
                memset(str, 0, 65536);

                for ( i = 0 ; i < MAX_TP_COUNT ; i++ ) {
                        Tp_Cmd_Dump_PID_filter_Status(i, str);
                }

#if 0
                sprintf(str, "%s----------------------------------------------------------------------------------------------------------------------------\n", str);
                sprintf(str, "%sSection Filter\n", str);
                for ( i = 0; i < MAX_SEC_COUNT; i++) {
                        Tp_Cmd_Dump_Section_filter_Status(str, i);
                }
#endif
                len = strlen(str);

                if(count > len) {
                        if(copy_to_user(buf, str, len)) {
                                TP_WARNING("Copy proc data to user space failed\n");
                                kfree(str);
                                return 0;
                        }

                        if (*ppos == 0)
                                *ppos += len;
                        else
                                len = 0;
                } else {
                        len = 0;
                }

                kfree(str);
                //TP_DBG("tp_proc_read_monitor Exit 06 *ppos=0x%llx count=0x%x len=0x%x\n", *ppos, count, len);
        }
        return len;
}

int tp_proc_read_mutex(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
        char *str;
        int len;
        UINT32 numOfMutex = 0, numOfFun = 0;
        struct list_head * ilist = NULL, * jlist = NULL;

        if (*ppos != 0) {
                TP_WARNING("*ppos!=0 just exit\n");
                return 0;
        }

        //TP_DBG("tp_proc_read_monitor Enter 01 *ppos=0x%llx count=0x%x\n", *ppos, count);

        len = 0;
        str = kmalloc(65536, GFP_KERNEL);
        if (str) {
                memset(str, 0, 65536);

                _tp_mutexlocklist_lock();

                sprintf(str, "%s--------------------[TP Mutex Debug]--------------------\n", str);

                if (pTp_MutexLockList) {
                        list_for_each(ilist, &pTp_MutexLockList->list) {
                                TP_DRV_MUTEXLOCK_T* tmp = list_entry(ilist, TP_DRV_MUTEXLOCK_T, list);
                                if (tmp->funCallStackHead) {
                                        sprintf(str, "%s========[mutex_%u][%s]========\n", str, numOfMutex, tmp->name);

                                        numOfFun = 0;
                                        list_for_each(jlist, &tmp->funCallStackHead->funName_list) {
                                                TP_DRV_MUTEXFUNNAME_T* tmpFun = list_entry(jlist, TP_DRV_MUTEXFUNNAME_T, funName_list);
                                                if (numOfFun < TP_MUTEX_DBG_NUM_FUN_CALL) {
                                                        sprintf(str, "%s[%u][%s][%d]\n", str, numOfFun, tmpFun->funName, tmpFun->lock);
                                                } else {
                                                        TP_ERROR("The fun call stack is more than %d\n", TP_MUTEX_DBG_NUM_FUN_CALL);
                                                        break;
                                                }
                                                numOfFun++;
                                        }
                                }
                                numOfMutex++;
                        }
                        sprintf(str, "%sTotal number of Mutex in TP driver: %u\n", str, numOfMutex);
                } else
                        TP_ERROR("There is no mutex lock in TP driver.\n");

                sprintf(str, "%s--------------------[TP Mutex Debug]--------------------\n", str);
                _tp_mutexlocklist_unlock();
                len = strlen(str);

                if(count > len) {
                        if(copy_to_user(buf, str, len)) {
                                TP_WARNING("Copy proc data to user space failed\n");
                                kfree(str);
                                return 0;
                        }

                        if (*ppos == 0)
                                *ppos += len;
                        else
                                len = 0;
                } else {
                        len = 0;
                }

                kfree(str);
        }
        //TP_DBG("tp_proc_read_monitor Exit 06 *ppos=0x%llx count=0x%x len=0x%x\n", *ppos, count, len);
        return len;
}


/***************************************************************************
  ------------------- TP driver init & un-init  --------------------
 ****************************************************************************/
static const struct file_operations tp_proc_fops = {
        .owner = THIS_MODULE,
        .write  = tp_proc_write,
        .read  = tp_proc_read,
};

static const struct file_operations tp_proc_fops_monitor = {
        .owner = THIS_MODULE,
        .write  = tp_proc_write,
        .read  = tp_proc_read_monitor,
};

static const struct file_operations tp_proc_fops_regdump = {
        .owner = THIS_MODULE,
        .write  = tp_proc_write,
        .read  = tp_proc_read_regdump,
};

static const struct file_operations tp_proc_fops_pidList = {
        .owner = THIS_MODULE,
        .write  = tp_proc_write,
        .read  = tp_proc_read_pidList,
};

static const struct file_operations tp_proc_fops_mutex = {
        .owner = THIS_MODULE,
        .write  = tp_proc_write,
        .read  = tp_proc_read_mutex,
};

INT32 create_tp_controller(void)
{
        TP_DRV_T* p_this = NULL;
        void *info_pack_buf = NULL;
        UADDRESS info_pack_buf_phy = 0;
        void *info_pack_buf_cached = NULL;
        UINT32 i, j, pid_cnt;
        UINT8 *section_data_buf;

        if(pTp_drv != NULL)
                return TPK_SUCCESS;

        p_this = (TP_DRV_T*)kmalloc(sizeof(TP_DRV_T), GFP_KERNEL);
        if (p_this) {
                memset(p_this, 0, sizeof(TP_DRV_T));

                /* allocate buffer for info pack */
                info_pack_buf_cached = dvr_malloc_uncached( TP_INFO_PACK_BUFFER_SIZE * MAX_TP_COUNT, &info_pack_buf );
                if ( ( info_pack_buf == NULL ) || ( info_pack_buf_cached == NULL ) ) {
                        TP_WARNING( "can not allocate memory for TP info pack (size=%d)\n", ( TP_INFO_PACK_BUFFER_SIZE * MAX_TP_COUNT ) );
                        kfree( p_this );
                        return TPK_FAIL;
                }

                p_this->info_pack_buf_cached = info_pack_buf_cached;
                info_pack_buf_phy = dvr_to_phys( info_pack_buf_cached ) ;    /* translate pack buffer from virtual & cached to phys */
                if ( info_pack_buf_phy == 0 ) {
                        TP_WARNING( "error, allocate info pack buffer fail, buffer size = %u \n", TP_INFO_PACK_BUFFER_SIZE * MAX_TP_COUNT );
                        kfree( p_this );
                        return TPK_NOT_ENOUGH_RESOURCE;
                }


                /* allocate buffer for section data (4k bytes for each pid filter) */
                section_data_buf = (UINT8*)kmalloc( SECTION_BUFFER_SIZE * MAX_PID_FILTER_COUNT, GFP_KERNEL);
                if ( section_data_buf == NULL ) {
                        TP_WARNING( "can not allocate memory for section buffer for PID filter (size=%d)\n", ( SECTION_BUFFER_SIZE * MAX_PID_FILTER_COUNT ) );
                        dvr_free( info_pack_buf_cached );
                        kfree( p_this );
                        return TPK_FAIL;
                }
                p_this->section_data_buf_of_pid_filter = section_data_buf;

                for( i = 0; i < MAX_TP_COUNT; i++) {
                        /* init info pack buffer */
                        p_this->tp[i].info_pack_buffer.BufSize = TP_INFO_PACK_BUFFER_SIZE;
                        p_this->tp[i].info_pack_buffer.BaseVir = (UADDRESS)(info_pack_buf + (TP_INFO_PACK_BUFFER_SIZE * i));
                        p_this->tp[i].info_pack_buffer.LimitVir = (UADDRESS)(info_pack_buf + (TP_INFO_PACK_BUFFER_SIZE * (i + 1)));
                        p_this->tp[i].info_pack_buffer.BasePhy = (info_pack_buf_phy + (TP_INFO_PACK_BUFFER_SIZE * i));
                        p_this->tp[i].info_pack_buffer.LimitPhy = (info_pack_buf_phy + (TP_INFO_PACK_BUFFER_SIZE * (i + 1)));
                        p_this->tp[i].info_pack_buffer.RP = p_this->tp[i].info_pack_buffer.BasePhy;
                        p_this->tp[i].info_pack_buffer.WP = p_this->tp[i].info_pack_buffer.BasePhy;
                        p_this->tp[i].info_pack_buffer.RP_Connect_cnt = INFO_PACK_BUFFER_RP_CONNECT;
                        p_this->tp[i].info_pack_buffer.RP_Connect[INFO_PACK_BUFFER_RP] = p_this->tp[i].info_pack_buffer.BasePhy;
                        p_this->tp[i].info_pack_buffer.bock_size = INFO_PACK_BUFFER_BLOCK_SIZE;
                        p_this->tp[i].info_pack_buffer.inited = 1;

                        switch(i) {
                                case TP_TP0:
                                        pid_cnt = TP0_PID_FILTER_COUNT;
                                        break;
                                case TP_TP1:
                                        pid_cnt = TP1_PID_FILTER_COUNT;
                                        break;
                                case TP_TP2:
                                        pid_cnt = TP2_PID_FILTER_COUNT;
                                        break;
                                case TP_TP3:
                                        pid_cnt = TP3_PID_FILTER_COUNT;
                                        break;
                                default:
                                        TP_WARNING("define MAX_TP_COUNT counter error (%u)\n", MAX_TP_COUNT);
                                        pid_cnt = 0;
                                        break;
                        }

                        /* init section buffer for each pid filter */
                        for( j = 0; j < pid_cnt; j++) {
                                p_this->tp_pid[i].pid_sec[j].pSec_buf = section_data_buf;
                                section_data_buf = section_data_buf + SECTION_BUFFER_SIZE;
                        }
                }

                pTp_drv = p_this;

#ifdef CONFIG_PROC_FS
                /* add proc entry */
                if((tp_proc_dir == NULL) && (tp_proc_entry == NULL) && (tp_proc_entry_monitor == NULL) && (tp_proc_entry_regdump == NULL) && (tp_proc_entry_pidList == NULL) && (tp_proc_entry_mutex == NULL)) {
                        tp_proc_dir = proc_mkdir(TP_PROC_DIR , NULL);

                        if (tp_proc_dir == NULL) {
                                TP_INFO("create rhal_tp dir proc entry (%s) failed\n", TP_PROC_DIR);
                        } else {
                                tp_proc_entry = proc_create(TP_PROC_ENTRY, 0666, tp_proc_dir, &tp_proc_fops);
                                if(tp_proc_entry == NULL) {
                                        TP_WARNING("failed to get proc entry for %s/%s \n", TP_PROC_DIR, TP_PROC_ENTRY);
                                }

                                tp_proc_entry_monitor = proc_create(TP_PROC_ENTRY_MONITOR, 0666, tp_proc_dir, &tp_proc_fops_monitor);
                                if(tp_proc_entry_monitor == NULL) {
                                        TP_WARNING("failed to get proc entry for %s/%s \n", TP_PROC_DIR, TP_PROC_ENTRY_MONITOR);
                                }

                                tp_proc_entry_regdump = proc_create(TP_PROC_ENTRY_REGDUMP, 0666, tp_proc_dir, &tp_proc_fops_regdump);
                                if(tp_proc_entry_regdump == NULL) {
                                        TP_WARNING("failed to get proc entry for %s/%s \n", TP_PROC_DIR, TP_PROC_ENTRY_REGDUMP);
                                }

                                tp_proc_entry_pidList = proc_create(TP_PROC_ENTRY_PIDLIST, 0666, tp_proc_dir, &tp_proc_fops_pidList);
                                if(tp_proc_entry_pidList == NULL) {
                                        TP_WARNING("failed to get proc entry for %s/%s \n", TP_PROC_DIR, TP_PROC_ENTRY_PIDLIST);
                                }

                                tp_proc_entry_mutex = proc_create(TP_PROC_ENTRY_MUTEX, 0666, tp_proc_dir, &tp_proc_fops_mutex);
                                if(tp_proc_entry_mutex == NULL) {
                                        TP_WARNING("failed to get proc entry for %s/%s \n", TP_PROC_DIR, TP_PROC_ENTRY_MUTEX);
                                }
                        }
                }
#else
                TP_WARNING("This module requests the kernel to support procfs,need set CONFIG_PROC_FS configure Y\n");
#endif

                return TPK_SUCCESS;
        } else {
                TP_WARNING("can not allocate memory for TP_DRV_T (structure size=%d)\n", sizeof(TP_DRV_T));
                return TPK_FAIL;
        }

}

void release_tp_controller(void)
{
        if (pTp_drv) {
#ifdef CONFIG_PROC_FS
                proc_remove(tp_proc_entry_mutex);
                tp_proc_entry_mutex = NULL;

                proc_remove(tp_proc_entry_pidList);
                tp_proc_entry_pidList = NULL;

                proc_remove(tp_proc_entry_regdump);
                tp_proc_entry_regdump = NULL;

                proc_remove(tp_proc_entry_monitor);
                tp_proc_entry_monitor = NULL;

                proc_remove(tp_proc_entry);
                tp_proc_entry = NULL;

                proc_remove(tp_proc_dir);
                tp_proc_dir = NULL;
#endif
                /* just in case, stop section thread */
                section_assemble_thread_start_stop(0);

                /* free info pack buffer */
                if(pTp_drv->info_pack_buf_cached != NULL) {
                        dvr_free((const void *)pTp_drv->info_pack_buf_cached);
                        pTp_drv->info_pack_buf_cached = NULL;
                }

                /* free section buffer of PID filter */
                if(pTp_drv->section_data_buf_of_pid_filter != NULL) {
                        kfree((const void *)pTp_drv->section_data_buf_of_pid_filter);
                        pTp_drv->section_data_buf_of_pid_filter = NULL;
                }

                kfree(pTp_drv);
                pTp_drv = NULL;
        }
}
EXPORT_SYMBOL(create_tp_controller);



