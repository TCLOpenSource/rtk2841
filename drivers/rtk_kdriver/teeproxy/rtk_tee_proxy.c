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
#include <linux/string.h>
#include <linux/proc_fs.h>

#include <rtk_kdriver/rtk_tee_proxy.h>
#include <mach/rtk_platform.h>
#include <mach/system.h>
#include <rtk_kdriver/RPCDriver.h>
#include <linux/dma-mapping.h> /* dma_alloc_coherent */
#include <linux/pageremap.h>
#include <linux/kthread.h>
#include <linux/err.h> /* IS_ERR() PTR_ERR() */
#include <linux/delay.h>
#include <linux/time.h>
#include <linux/auth.h>
#include <linux/freezer.h>
#include <linux/wait.h>

static struct class *rtk_teeproxy_class = NULL;
static struct cdev rtk_teeproxy_cdev;
static struct platform_device *rtk_teeproxy_platform_devs = NULL;

static struct platform_driver rtk_teeproxy_device_driver = {
    .driver = {
        .name   	= RTK_TEE_PROXY_NAME,
        .bus    	= &platform_bus_type,
    },
};

int rtk_teeproxy_major = RTK_TEE_PROXY_MAJOR;
int rtk_teeproxy_minor = 0;

/* TEE status */
pid_t rtk_teeproxy_teemgr_pid = -1;

/* for record rtk_teeproxy alloc info */
static struct list_head rtk_teeproxy_alloc_head;
static DEFINE_SEMAPHORE(rtk_teeproxy_alloc_sem);
static unsigned int teeproxy_free_flow_check = 0 ;

/* for record recovery info */
static struct list_head rtk_teeproxy_recovery_head;
static DEFINE_SEMAPHORE(rtk_teeproxy_recovery_sem);
static DECLARE_WAIT_QUEUE_HEAD(rtk_teeproxy_recovery_wq);
static unsigned int recovery_list_change = 0;

static TEE_PROXY_RPC_MEM_STRUCT teeproxy_rpc_mem;

/* for recovery */
static struct task_struct *rtk_teeproxy_recovery_tsk = NULL;
static int data_recovery;
static int rtk_teeproxy_recovery_thread(void *arg);

/***************** debug log utility *****************/
#define TEE_PROXY_PR(level, format, ...) tee_pr_log(level, __LINE__, format, ##__VA_ARGS__)
#define TEE_PROXY_PR_NA(level, format, ...) tee_pr_log(level, -1, format, ##__VA_ARGS__)
static TEE_PROXY_LOG_LEVEL  rtk_teeproxy_log_level = TEE_LOG_NOTICE;

void tee_pr_log(TEE_PROXY_LOG_LEVEL level, int nLine, const char *pszFormat, ...)
{
    if (level <= rtk_teeproxy_log_level) {
        va_list args;
        size_t uStringSize = 0;
        char *pStringBuffer = NULL;
        int nPosition = snprintf(NULL, 0, "%s:%d ", RTK_TEE_PROXY_NAME, nLine);
        if(nLine == -1) {
            va_start(args, pszFormat);
            uStringSize += vsnprintf(NULL, 0, pszFormat, args);
            va_end(args);
            uStringSize += 1;

            pStringBuffer = (char *)kmalloc(uStringSize, GFP_KERNEL);

            if (pStringBuffer != NULL) {
                va_start(args, pszFormat);
                vsnprintf(pStringBuffer, uStringSize, pszFormat, args);
                va_end(args);

                pr_warning("%s", pStringBuffer);
            }
            kfree(pStringBuffer);

        } else {
            va_start(args, pszFormat);
            uStringSize += vsnprintf(NULL, 0, pszFormat, args);
            va_end(args);
            uStringSize += nPosition + 1;

            pStringBuffer = (char *)kmalloc(uStringSize, GFP_KERNEL);

            if (pStringBuffer != NULL) {

                nPosition = snprintf(pStringBuffer, uStringSize, "%s:%d ", RTK_TEE_PROXY_NAME, nLine);
                uStringSize -= nPosition;

                va_start(args, pszFormat);
                vsnprintf(pStringBuffer + nPosition, uStringSize, pszFormat, args);
                va_end(args);

                pr_warning("%s", pStringBuffer);
            }
            kfree(pStringBuffer);
        }
    }
    return;
}

void set_tee_log_level(TEE_PROXY_LOG_LEVEL level)
{
    TEE_PROXY_PR(TEE_LOG_NOTICE, "set log level from %d to %d\n", rtk_teeproxy_log_level, level);
    rtk_teeproxy_log_level = level;
    return;
}

/***************** debug log utility end *****************/

int rtk_teeproxy_alloc(unsigned long arg)
{
    bool new_tee_alloc = true;
    bool copy_tee_alloc = true;
    struct ree_buf_info *buf_info, *buf_info_copy;
    unsigned int vir_addr;
    unsigned int phy_addr;
    TEE_ALLOC_MEM_STRUCT allocmem;
    int i = 0;
    bool alloc_multi_time = false;
    pid_t cur_ree_pid = task_tgid_nr(current);

    if (copy_from_user((void *)&allocmem, (const void __user *)arg, sizeof(TEE_ALLOC_MEM_STRUCT))) {
        TEE_PROXY_PR(TEE_LOG_ERROR, "rtk_teeproxy_alloc copy_from_user failed!\n");
        return 0;
    }

    #ifdef RTK_TEE_PROXY_FUNC_TEST
    cur_ree_pid = allocmem.ree_pid;
    #endif
    //check tee_pid and decide to add new ree_buf_info or add ree_pid only.
    if (allocmem.new_buf != 1) {
        down(&rtk_teeproxy_alloc_sem);
        list_for_each_entry(buf_info, &rtk_teeproxy_alloc_head, buffer_list)
        {
            if (buf_info->tee_type == allocmem.tee_type) {
                new_tee_alloc = false;
                for (i=0; i<buf_info->ref_cnt; i++) {
                    if (buf_info->ree_pid[i] == cur_ree_pid) {
                        TEE_PROXY_PR(TEE_LOG_ERROR, "Alloc exist for pid(%d, %d) multi times\n", cur_ree_pid, allocmem.tee_pid);
                        phy_addr = 0;
                        alloc_multi_time = true;
                        copy_tee_alloc = false;
                        break;
                    }
                }
                if(alloc_multi_time)
                    break;
                if (buf_info->tee_pid == allocmem.tee_pid) {
#if 0 // FIXME:
                    if (buf_info->ref_cnt >= MAX_REE_APP_NUM) {
                        TEE_PROXY_PR(TEE_LOG_ERROR, "Alloc for pid(%d, %d) cnt out of range %d\n", cur_ree_pid, allocmem.tee_pid, MAX_REE_APP_NUM);
                        phy_addr = 0;
                        copy_tee_alloc = false;
                        break;
                    }
#endif
                    buf_info->ree_pid[buf_info->ref_cnt] = cur_ree_pid;
                    buf_info->ref_cnt++;
                    phy_addr = buf_info->phy_addr;
                    copy_tee_alloc = false;
                    TEE_PROXY_PR(TEE_LOG_DEBUG, "Alloc buf_type(%d) exist (p:%x,v:%x) for pid(%d, %d)\n",
                            allocmem.tee_type, phy_addr, buf_info->vir_addr, cur_ree_pid, allocmem.tee_pid);
                    break;
                }
            }
        }
        if (copy_tee_alloc && !new_tee_alloc) {
            list_for_each_entry(buf_info, &rtk_teeproxy_alloc_head, buffer_list)
            {
                if (buf_info->tee_type == allocmem.tee_type) {
                    buf_info_copy = kmalloc(sizeof(struct ree_buf_info), GFP_KERNEL);
                    buf_info_copy->ree_pid[0] = cur_ree_pid;
                    buf_info_copy->tee_pid = allocmem.tee_pid;
                    buf_info_copy->ref_cnt = 1;
                    buf_info_copy->tee_type = allocmem.tee_type;
                    buf_info_copy->vir_addr = buf_info->vir_addr;
                    buf_info_copy->phy_addr = buf_info->phy_addr;
                    buf_info_copy->request_size = buf_info->request_size;
                    buf_info_copy->malloc_size = buf_info->malloc_size;
                    list_add(&buf_info_copy->buffer_list, &rtk_teeproxy_alloc_head);
                    phy_addr = buf_info_copy->phy_addr;
                    TEE_PROXY_PR(TEE_LOG_DEBUG, "Alloc buf_type(%d) copy (p:%x,v:%x) for pid(%d, %d)\n",
                            allocmem.tee_type, phy_addr, buf_info->vir_addr, cur_ree_pid, allocmem.tee_pid);
                    break;
                }
            }
        }
        up(&rtk_teeproxy_alloc_sem);
    }

    if (new_tee_alloc) {
        //add new ree_buf_info to list
        vir_addr = (unsigned int)dvr_malloc_specific(allocmem.size, GFP_DCU1);
        phy_addr = (unsigned int)dvr_to_phys((void *)vir_addr);
        if(allocmem.new_buf != 1)
            memset((void *)vir_addr, 0, allocmem.size);

        if (!phy_addr) {
            TEE_PROXY_PR(TEE_LOG_ERROR, "alloc memory fail\n");
            return 0;
        }

        if ((phy_addr & 0xe0000000) != 0)
            TEE_PROXY_PR(TEE_LOG_ERROR, "get memory not between 0 ~ 512 MB\n");

        buf_info = kmalloc(sizeof(struct ree_buf_info), GFP_KERNEL);
        buf_info->ree_pid[0] = cur_ree_pid;
        buf_info->tee_pid = allocmem.tee_pid;
        buf_info->ref_cnt = 1;
        buf_info->tee_type = allocmem.tee_type;
        buf_info->vir_addr = vir_addr;
        buf_info->phy_addr = phy_addr;
        buf_info->request_size = allocmem.size;
        buf_info->malloc_size = PAGE_ALIGN(allocmem.size);
        TEE_PROXY_PR(TEE_LOG_DEBUG, "Alloc buf_type(%d) new (p:%x,v:%x) for pid(%d, %d)\n",
                allocmem.tee_type, phy_addr, vir_addr, cur_ree_pid, allocmem.tee_pid);

        down(&rtk_teeproxy_alloc_sem);
        list_add(&buf_info->buffer_list, &rtk_teeproxy_alloc_head);
        up(&rtk_teeproxy_alloc_sem);
    }

    return phy_addr;
}

int rtk_teeproxy_free(unsigned int phy_addr, int ree_pid)
{
    unsigned int vir_addr = 0;
    unsigned int phy_addr_cnt = 0;
    struct ree_buf_info *buf_info;
    int i = 0, ree_pid_index = -1;
    pid_t cur_ree_pid;
    if(ree_pid != -1)
        cur_ree_pid = (pid_t)ree_pid;
    else
        cur_ree_pid = task_tgid_nr(current);

    #ifdef RTK_TEE_PROXY_FUNC_TEST
    ree_pid_index = 0;
    #endif
    down(&rtk_teeproxy_alloc_sem);
    list_for_each_entry(buf_info, &rtk_teeproxy_alloc_head, buffer_list)
    {
        if (buf_info->phy_addr == phy_addr) {
            phy_addr_cnt++;
        }
    }

    list_for_each_entry(buf_info, &rtk_teeproxy_alloc_head, buffer_list)
    {
        if (buf_info->phy_addr == phy_addr) {
            for (i=0; i<buf_info->ref_cnt; i++) {
                if (buf_info->ree_pid[i] == cur_ree_pid) {
                    ree_pid_index = i;
                    break;
                }
            }
            if (ree_pid_index != -1) {
                TEE_PROXY_PR(TEE_LOG_DEBUG, "free cnt(%d) ref(%d) (p:%x,v:%x) for pid(%d, %d)\n", phy_addr_cnt, buf_info->ref_cnt, phy_addr, buf_info->vir_addr, cur_ree_pid, buf_info->tee_pid);
                if (buf_info->ref_cnt == 1) {
                    vir_addr = buf_info->vir_addr;
                    list_del(&buf_info->buffer_list);
                    kfree(buf_info);
                    break;
                } else {
                    for (i=ree_pid_index; i<buf_info->ref_cnt; i++) {
                        buf_info->ree_pid[i] = buf_info->ree_pid[i+1];
                    }
                    buf_info->ref_cnt--;
                    break;
                }
            }
        }
    }
    up(&rtk_teeproxy_alloc_sem);

    if(vir_addr != 0 && phy_addr_cnt == 1)
        dvr_free((void *)vir_addr);
    return 0;
}

void rtk_teeproxy_user_alloc_summary(void)
{
    unsigned long sum_request, sum_malloc;
    struct ree_buf_info *buf_info;
    struct ree_buf_info *b;
    struct list_head pid_list = LIST_HEAD_INIT(pid_list);
    int i = 0;

    sum_malloc = sum_request = 0;

    down(&rtk_teeproxy_alloc_sem);
    TEE_PROXY_PR(TEE_LOG_NOTICE, "rtk_teeproxy_user_alloc_summary %d\n", teeproxy_free_flow_check);
    list_for_each_entry(buf_info, &rtk_teeproxy_alloc_head, buffer_list)
    {
        TEE_PROXY_PR(TEE_LOG_NOTICE, "ree_pid(\n");
        for (i=0; i<buf_info->ref_cnt; i++)
            TEE_PROXY_PR(TEE_LOG_NOTICE, "%d\n",(int)buf_info->ree_pid[i]);

        TEE_PROXY_PR(TEE_LOG_NOTICE, ") tee_pid(%d) : malloc %d, request %d, phy_addr 0x%x\n",
                (int)buf_info->tee_pid,
                (int)buf_info->malloc_size,
                (int)buf_info->request_size,
                buf_info->phy_addr);
        if (list_empty(&pid_list)) {
            b = kmalloc(sizeof(struct ree_buf_info), GFP_KERNEL);
            b->ree_pid[0] = buf_info->ree_pid[0];
            b->request_size = b->malloc_size = 0;
            list_add(&b->buffer_list, &pid_list);
        }

        for (i=0; i<buf_info->ref_cnt; i++) {
            int pid_exist = false;
            list_for_each_entry(b, &pid_list, buffer_list)
            {
                if (b->ree_pid[0] == buf_info->ree_pid[i]) {
                    pid_exist = true;
                    break;
                }
            }
            if (pid_exist == false) {
                b = kmalloc(sizeof(struct ree_buf_info), GFP_KERNEL);
                b->ree_pid[0] = buf_info->ree_pid[i];
                b->request_size = b->malloc_size = 0;
                list_add(&b->buffer_list, &pid_list);
            }
            b->request_size += buf_info->request_size;
            b->malloc_size += buf_info->malloc_size;
        }
        sum_request += buf_info->request_size;
        sum_malloc  += buf_info->malloc_size;
    }
    up(&rtk_teeproxy_alloc_sem);
    list_for_each_entry_safe(b, buf_info, &pid_list, buffer_list)
    {
        TEE_PROXY_PR(TEE_LOG_NOTICE, "pid(%d) : sum_malloc %d, sum_request %d\n",
                (int)b->ree_pid[0],
                (int)b->malloc_size,
                (int)b->request_size);
        list_del(&b->buffer_list);
        kfree(b);
    }

    TEE_PROXY_PR(TEE_LOG_NOTICE, "sum_malloc %ld, sum_request %ld\n", sum_malloc, sum_request);

    return;
}

/*
 * debug function which dumps all status
 */
void rtk_teeproxy_dump(void)
{
  /* dump user allocated memories */
  rtk_teeproxy_user_alloc_summary();

  /* dump TEE manager pid */
  TEE_PROXY_PR(TEE_LOG_NOTICE, "TEE manager: pid=%d\n", rtk_teeproxy_teemgr_pid);
}

/***************** rpc driver export func *****************/
void rtk_teeproxy_free_by_process(unsigned long process_id)
{
    struct ree_buf_info *buf_info, *tmp_buf_info;
    struct rpc_buf_info *b, *tmp_b;
    struct task_struct *task;
    int i;
    int pid_new;
    pid_t tmp_ree_pid, tmp_tee_pid;
    struct list_head ree_pid_list = LIST_HEAD_INIT(ree_pid_list);
    struct list_head dead_pid_list = LIST_HEAD_INIT(dead_pid_list);
    unsigned long return_value;
    int ret = 0;

    if (!teeproxy_rpc_mem.vir_addr) {
        TEE_PROXY_PR(TEE_LOG_ERROR, "rtk_teeproxy no rpc param memory\n");
        return;
    }

    down(&rtk_teeproxy_alloc_sem);
    teeproxy_free_flow_check = 1 ;
    list_for_each_entry_safe(buf_info, tmp_buf_info,
            &rtk_teeproxy_alloc_head, buffer_list)
    {
        //check ree_pid
        for (i=0; i<buf_info->ref_cnt; i++) {
            if (buf_info->ree_pid[i] == process_id) {
                //check ree_pid
                tmp_ree_pid = buf_info->ree_pid[i];
                tmp_tee_pid = buf_info->tee_pid;
                pid_new = true;

                if (list_empty(&ree_pid_list)) {
                    b = kmalloc(sizeof(struct rpc_buf_info), GFP_KERNEL);
                    b->ree_pid = tmp_ree_pid;
                    b->tee_pid = tmp_tee_pid;
                    list_add(&b->buffer_list, &ree_pid_list);
                } else {
                    list_for_each_entry(b, &ree_pid_list, buffer_list)
                    {
                        if (b->tee_pid == tmp_tee_pid) {
                            pid_new = false;
                            break;
                        }
                    }
                    if (pid_new == true) {
                        b = kmalloc(sizeof(struct rpc_buf_info),
                                GFP_KERNEL);
                        b->ree_pid = tmp_ree_pid;
                        b->tee_pid = tmp_tee_pid;
                        list_add(&b->buffer_list, &ree_pid_list);
                    }
                }

                if (pid_new == true) {
                    TEE_PROXY_RPC_PARAM_STRUCT *rpc_param = NULL;
                    teeproxy_free_flow_check = 2;
                    rpc_param = (TEE_PROXY_RPC_PARAM_STRUCT*)teeproxy_rpc_mem.vir_addr;
                    rpc_param->ree_pid = tmp_ree_pid;
                    rpc_param->tee_pid = tmp_tee_pid;
                    dmac_flush_range(teeproxy_rpc_mem.vir_addr, teeproxy_rpc_mem.vir_addr + sizeof(TEE_PROXY_RPC_PARAM_STRUCT));
                    outer_flush_range(teeproxy_rpc_mem.phy_addr, teeproxy_rpc_mem.phy_addr + sizeof(TEE_PROXY_RPC_PARAM_STRUCT));

                    TEE_PROXY_PR(TEE_LOG_WARN, "[+] rtk_teeproxy send RPC for recovery(%d, %d)\n", rpc_param->ree_pid, rpc_param->tee_pid);
                    if ((ret = send_rpc_command(RPC_KCPU, RPC_SCPU_ID_0x500_teestub_resource_recovery, (unsigned int)teeproxy_rpc_mem.phy_addr, 0, &return_value))) {
                        TEE_PROXY_PR(TEE_LOG_ERROR, "rtk_teeproxy handle kill: RPC_KCPU fail %d\n", ret);
                        continue;
                    }
                    TEE_PROXY_PR(TEE_LOG_WARN, "[-] rtk_teeproxy send RPC for recovery\n");

                    teeproxy_free_flow_check = 3;

                    TEE_PROXY_PR(TEE_LOG_DEBUG, "recovery free %d (p:%x,v:%x) process_id:%d for pid(%d, %d)\n", buf_info->ref_cnt, buf_info->phy_addr, buf_info->vir_addr, process_id, tmp_ree_pid, tmp_tee_pid);
                }
            }
            else {
                task = pid_task(find_vpid(buf_info->ree_pid[i]), PIDTYPE_PID);
                #ifdef RTK_TEE_PROXY_FUNC_TEST
                if(0)
                #else
                if(task == NULL)
                #endif
                {
                    tmp_ree_pid = buf_info->ree_pid[i];
                    tmp_tee_pid = buf_info->tee_pid;
                    pid_new = true;
                    //record ree_pid and tee_pid
                    if (list_empty(&dead_pid_list)) {
                        b = kmalloc(sizeof(struct rpc_buf_info), GFP_KERNEL);
                        b->ree_pid = tmp_ree_pid;
                        b->tee_pid = tmp_tee_pid;
                        list_add(&b->buffer_list, &dead_pid_list);
                    } else {
                        list_for_each_entry(b, &dead_pid_list, buffer_list)
                        {
                            if (b->ree_pid == tmp_ree_pid && b->tee_pid == tmp_tee_pid) {
                                pid_new = false;
                                break;
                            }
                        }
                        if (pid_new == true) {
                            b = kmalloc(sizeof(struct rpc_buf_info),
                                    GFP_KERNEL);
                            b->ree_pid = tmp_ree_pid;
                            b->tee_pid = tmp_tee_pid;
                            list_add(&b->buffer_list, &dead_pid_list);
                        }
                    }

                    if (pid_new == true) {
                        TEE_PROXY_RPC_PARAM_STRUCT *rpc_param = NULL;
                        teeproxy_free_flow_check = 5;
                        rpc_param = (TEE_PROXY_RPC_PARAM_STRUCT*)teeproxy_rpc_mem.vir_addr;
                        rpc_param->ree_pid = tmp_ree_pid;
                        rpc_param->tee_pid = tmp_tee_pid;
                        dmac_flush_range(teeproxy_rpc_mem.vir_addr, teeproxy_rpc_mem.vir_addr + sizeof(TEE_PROXY_RPC_PARAM_STRUCT));
                        outer_flush_range(teeproxy_rpc_mem.phy_addr, teeproxy_rpc_mem.phy_addr + sizeof(TEE_PROXY_RPC_PARAM_STRUCT));

                        TEE_PROXY_PR(TEE_LOG_WARN, "[+] rtk_teeproxy send RPC for dead(%d, %d)\n", rpc_param->ree_pid, rpc_param->tee_pid);
                        if ((ret = send_rpc_command(RPC_KCPU, RPC_SCPU_ID_0x500_teestub_resource_recovery, (unsigned int)teeproxy_rpc_mem.phy_addr, 0, &return_value))) {
                            TEE_PROXY_PR(TEE_LOG_ERROR, "rtk_teeproxy handle null task: RPC_KCPU fail %d\n", ret);
                            continue;
                        }
                        TEE_PROXY_PR(TEE_LOG_WARN, "[-] rtk_teeproxy send RPC for dead\n");

                        teeproxy_free_flow_check = 6;

                        TEE_PROXY_PR(TEE_LOG_DEBUG, "dead free %d (p:%x,v:%x) for pid(%d, %d)\n", buf_info->ref_cnt, buf_info->phy_addr, buf_info->vir_addr, tmp_ree_pid, tmp_tee_pid);
                    }
                }
            }
        }
    }
    up(&rtk_teeproxy_alloc_sem);

    teeproxy_free_flow_check = 8;
    //free ree_pid_list
    list_for_each_entry_safe(b, tmp_b, &ree_pid_list, buffer_list)
    {
        list_del(&b->buffer_list);
        kfree(b);
    }

    //free dead_pid_list
    list_for_each_entry_safe(b, tmp_b, &dead_pid_list, buffer_list)
    {
        list_del(&b->buffer_list);
        kfree(b);
    }
    teeproxy_free_flow_check = 0;

    return;
}

//implement export funciton.
//called by rpc driver when ree application had been killed.
unsigned long rtk_teeproxy_free_user_mem(unsigned long para1)
{
    struct ree_recovery_info *buf_info;
    bool exist_pid = false;
    bool need_notify_k = true;
    unsigned int tmp_phy_addr;
    int tmp_ree_pid;

//alaric.add.begin
//for check whether pid in alloc list when free called
    int i;
    bool is_in_alloc = false;
    struct ree_buf_info *b;
    down(&rtk_teeproxy_alloc_sem);
    list_for_each_entry(b, &rtk_teeproxy_alloc_head, buffer_list)
    {
        for (i=0; i< b->ref_cnt; i++) {
            if (b->ree_pid[i] == para1) {
                if(b->tee_type == TEE_TYPE_SHARE_MEMORY){
                    need_notify_k = false;
                    tmp_phy_addr = b->phy_addr;
                    tmp_ree_pid = para1;
                }
                is_in_alloc = true;
                break;
            }
        }
        if(is_in_alloc)
            break;
    }
    up(&rtk_teeproxy_alloc_sem);
    if(!is_in_alloc) {
        TEE_PROXY_PR(TEE_LOG_INFO, "rtk_teeproxy_free_user_mem(%d) not in the alloc list\n", para1);
        return 0;
    }

    if(!need_notify_k && is_in_alloc){
        TEE_PROXY_PR(TEE_LOG_DEBUG, "rtk_teeproxy_free_user_mem(%d) this tee_type(TEE_TYPE_SHARE_MEMORY) need't notify kcpu\n", para1);
        TEE_PROXY_PR(TEE_LOG_DEBUG, "[+]rtk_teeproxy_free_user_mem(%d) Free the ree_ap memory\n");
// FIXME:
        if (b->tee_type != TEE_TYPE_SHARE_MEMORY) {
            rtk_teeproxy_free(tmp_phy_addr, tmp_ree_pid);
        } else {
            TEE_PROXY_PR(TEE_LOG_ERROR, "rtk_teeproxy ### no need to Free ###\n");
        }
        TEE_PROXY_PR(TEE_LOG_DEBUG, "[-]rtk_teeproxy_free_user_mem(%d) Free the ree_ap memory\n");
        return 0;
    }
//alaric.add.end

    TEE_PROXY_PR(TEE_LOG_NOTICE, "[+] rtk_teeproxy_free_user_mem(%d)\n", para1);
    //rtk_teeproxy_free_by_process(para1);
    down(&rtk_teeproxy_recovery_sem);
    list_for_each_entry(buf_info, &rtk_teeproxy_recovery_head, buffer_list)
    {
        if (buf_info->ree_pid == para1) {
            TEE_PROXY_PR(TEE_LOG_WARN, " exist_pid (%d)\n", para1);
            exist_pid = true;
            break;
        }
    }
    up(&rtk_teeproxy_recovery_sem);

    if (exist_pid) {
        TEE_PROXY_PR(TEE_LOG_WARN, "receive exist pid %lx\n", para1);
        return 0;
    }

    buf_info = kmalloc(sizeof(struct ree_recovery_info), GFP_KERNEL);
    buf_info->ree_pid = para1;

    down(&rtk_teeproxy_recovery_sem);
    list_add(&buf_info->buffer_list, &rtk_teeproxy_recovery_head);
    up(&rtk_teeproxy_recovery_sem);

    recovery_list_change = 1;
    wake_up(&rtk_teeproxy_recovery_wq);

    TEE_PROXY_PR(TEE_LOG_NOTICE, "[-] rtk_teeproxy_free_user_mem(%d)\n", para1);
    return 0;
}

EXPORT_SYMBOL(rtk_teeproxy_free_user_mem);

static int rtk_teeproxy_recovery_thread(void *arg)
{
    struct ree_recovery_info *buf_info;
    struct ree_recovery_info *tmp_buf_info;
    for (;;) {
        if (kthread_should_stop())
            break;

        //check recovery info list
        down(&rtk_teeproxy_recovery_sem);
        list_for_each_entry_safe(buf_info, tmp_buf_info, &rtk_teeproxy_recovery_head, buffer_list)
        {
            rtk_teeproxy_free_by_process(buf_info->ree_pid);
            list_del(&buf_info->buffer_list);
            kfree(buf_info);
        }
        up(&rtk_teeproxy_recovery_sem);

        TEE_PROXY_PR(TEE_LOG_DEBUG, "rtk_teeproxy_recovery_thread wait begin\n");
        wait_event_interruptible(rtk_teeproxy_recovery_wq, recovery_list_change);
        recovery_list_change = 0;
        TEE_PROXY_PR(TEE_LOG_DEBUG, "rtk_teeproxy_recovery_thread wait end\n");
        msleep(100);
    }
    TEE_PROXY_PR(TEE_LOG_DEBUG, "rtk_teeproxy_recovery_thread break\n");
    return 0;
}

void rtk_teeproxy_free_by_pid(int ree_pid, int tee_pid)
{
    struct ree_buf_info *buf_info;
    int i;
    struct ree_recovery_addr *b, *tmp_b;
    struct list_head ree_addr_list = LIST_HEAD_INIT(ree_addr_list);  //ree_recovery_addr
    down(&rtk_teeproxy_alloc_sem);
    list_for_each_entry(buf_info, &rtk_teeproxy_alloc_head, buffer_list)
    {
        for (i=0; i<buf_info->ref_cnt; i++) {
            if (buf_info->ree_pid[i] == ree_pid && buf_info->tee_pid == tee_pid) {
                b = kmalloc(sizeof(struct ree_recovery_addr), GFP_KERNEL);
                b->phy_addr = buf_info->phy_addr;
                list_add(&b->buffer_list, &ree_addr_list);
                TEE_PROXY_PR(TEE_LOG_DEBUG, "get_phyaddr_%x by_pid %d:%d\n", b->phy_addr, ree_pid, tee_pid);
                break;
            }
        }
    }
    up(&rtk_teeproxy_alloc_sem);

    list_for_each_entry_safe(b, tmp_b, &ree_addr_list, buffer_list)
    {
        rtk_teeproxy_free(b->phy_addr, ree_pid);
        TEE_PROXY_PR(TEE_LOG_DEBUG, "self free_phyaddr_%x by_pid %d:%d\n", b->phy_addr, ree_pid, tee_pid);
        list_del(&b->buffer_list);
        kfree(b);
    }

    return;
}

static pid_t rtk_teeproxy_get_teemgr_pid(void)
{
  if (rtk_teeproxy_teemgr_pid < 0) {
    // Ask TEE Manager PID if not available
    unsigned long ret = 0;

    TEE_PROXY_PR(TEE_LOG_NOTICE, "asking TEE manager pid\n");

    if (send_rpc_command(RPC_KCPU, RPC_SCPU_ID_0x504_teestub_get_teemgr_pid,
                         0, 0, &ret)) {
      return rtk_teeproxy_teemgr_pid;
    }

    // Update to local if it's valid
    if (ret > 0) {
      rtk_teeproxy_teemgr_pid = ret;
    }
  }
  return rtk_teeproxy_teemgr_pid;
}

int handle_reeapp_freemem_thread_fn(void *data)
{
   struct _TEE_PROXY_RPC_PARAM_STRUCT *ree_rpc;
   ree_rpc = (TEE_PROXY_RPC_PARAM_STRUCT *)data;
   rtk_teeproxy_free_by_pid(ree_rpc->ree_pid, ree_rpc->tee_pid);
   kfree(ree_rpc);
   return 0;
}

//RPC handler function
unsigned long rtk_teeproxy_reeapp_freememory(unsigned long para1, unsigned long para2)
{
    struct _TEE_PROXY_RPC_PARAM_STRUCT *ree_rpc;
    ree_rpc = (TEE_PROXY_RPC_PARAM_STRUCT *) kmalloc(sizeof(struct _TEE_PROXY_RPC_PARAM_STRUCT), GFP_KERNEL);
    ree_rpc->ree_pid = (pid_t)para1;
    ree_rpc->tee_pid = (pid_t)para2;
    TEE_PROXY_PR(TEE_LOG_DEBUG, "RPC rtk_teeproxy_reeapp_freememory recived pid(%d, %d)\n", ree_rpc->ree_pid, ree_rpc->tee_pid);

#if 1
    // asynchronous method: create kthread to handle reeapp free memory
    static struct task_struct *thread_ree;
    thread_ree = kthread_create(handle_reeapp_freemem_thread_fn, ree_rpc, "reeapp_freememe_task");
    if (thread_ree) {
        pr_debug(KERN_DEBUG "run signal reeapp task\n");
        wake_up_process(thread_ree);
    }
#else
    // synchronous method
    //free ree app memory
    rtk_teeproxy_free_by_pid(ree_rpc->ree_pid, ree_rpc->tee_pid);
#endif
    return 0;
}

/**
 * RPC handler: RPC_KCPU_ID_0x503_teeproxy_notify_teemgr_pid
 */
unsigned long rtk_teeproxy_notify_teemgr_pid(unsigned long para1, unsigned long para2)
{
    TEE_PROXY_PR(TEE_LOG_DEBUG, "RPC:rtk_teeproxy_notify_teemgr_pid received!\n");

    rtk_teeproxy_teemgr_pid = (pid_t) para1;

    TEE_PROXY_PR(TEE_LOG_DEBUG, "rtk_teeproxy_notify_teemgr_pid:recived pid : %d\n",
        rtk_teeproxy_teemgr_pid);

    return 0;
}

/***************** rpc driver export func end *****************/
long rtk_teeproxy_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    int ret = 0;

    TEE_PROXY_PR(TEE_LOG_WARN, "rtk_teeproxy: receive ioctl(cmd:0x%08x, arg:0x%08x)\n", cmd, (unsigned int)arg);
    switch (cmd) {
        case TEE_PROXY_IOC_INIT:
            {
                TEE_PROXY_PR(TEE_LOG_DEBUG, "TEE_PROXY_IOC_INIT\n");
                break;
            }

        case TEE_PROXY_IOC_DEINIT:
            {
                TEE_PROXY_PR(TEE_LOG_DEBUG, "TEE_PROXY_IOC_DEINIT\n");
                break;
            }

        case TEE_PROXY_IOC_KILL:
            {
                TEE_PROXY_PR(TEE_LOG_WARN, "TEE_PROXY_IOC_KILL\n");
                #ifdef RTK_TEE_PROXY_FUNC_TEST
                rtk_teeproxy_free_user_mem(arg);
                #endif
                break;
            }

        case TEE_PROXY_IOC_ALLOC:
            {
                TEE_PROXY_PR(TEE_LOG_WARN, "TEE_PROXY_IOC_ALLOC\n");
                ret = rtk_teeproxy_alloc(arg);
                break;
            }

        case TEE_PROXY_IOC_FREE:
            {
                TEE_PROXY_PR(TEE_LOG_WARN, "TEE_PROXY_IOC_FREE\n");
                ret = rtk_teeproxy_free(arg, -1);
                break;
            }

        case TEE_PROXY_IOC_TEEMGR_PID:
            {
              pid_t pid = rtk_teeproxy_get_teemgr_pid();
              if (copy_to_user((void __user *) arg, (void *) &pid, sizeof(pid_t))) {
                  ret = -EFAULT;
              }
            }
            break;
        default:
            {
                TEE_PROXY_PR(TEE_LOG_WARN, "rtk_teeproxy: unknown ioctl(0x%08x)\n", cmd);
                break;
            }
    };

    return ret;
}

int rtk_teeproxy_open(struct inode *inode, struct file *filp)
{
    return 0 ;
}

int rtk_teeproxy_release(struct inode *inode, struct file *filp)
{
    return 0 ;
}

void rtk_teeproxy_help(void)
{
    TEE_PROXY_PR(TEE_LOG_NOTICE, " echo h > /dev/rtkteeproxy                      ## print debug help\n");
    TEE_PROXY_PR(TEE_LOG_NOTICE, " echo u > /dev/rtkteeproxy                      ## show usr memory usage\n");
    TEE_PROXY_PR(TEE_LOG_NOTICE, " echo lev x > /dev/rtkteeproxy                  ## set log level\n");
    TEE_PROXY_PR(TEE_LOG_NOTICE, " echo tee@ enable_protect > /dev/rtkteeproxy    ## enable mem protection\n");
    TEE_PROXY_PR(TEE_LOG_NOTICE, " echo tee@ disable_protect > /dev/rtkteeproxy   ## disable mem protection\n");
    TEE_PROXY_PR(TEE_LOG_NOTICE, " echo tee@ xxx yyy > /dev/rtkteeproxy           ## set TA log level (ex: sstore 256)\n");
}

void rtkteeproxy_send_string(const char *pattern, int length)
{
	unsigned long ret = S_OK;
	unsigned long vir_addr;
	unsigned long phy_addr;
	char *command = NULL;

	vir_addr = (unsigned long)dvr_malloc_uncached_specific(length+1, GFP_DCU1, (void **)&command);
	if (!vir_addr) {
		TEE_PROXY_PR(TEE_LOG_ERROR, "[%s %d]alloc string memory fail\n",__FUNCTION__,__LINE__);
		return;
	}
	phy_addr = (unsigned long)dvr_to_phys((void *)vir_addr);
	memset((void *)command, '\0', length+1);
	memcpy((void *)command, (void *)pattern, length);

	TEE_PROXY_PR(TEE_LOG_DEBUG, "rtkteeproxy: debug string(%s), length(%d)\n", command, length);
	
	if (send_rpc_command(RPC_KCPU, RPC_SCPU_ID_0x502_teestub_debug_command, phy_addr, length, &ret))
		TEE_PROXY_PR(TEE_LOG_ERROR, "rtkteeproxy: debug string(%s) fail %d\n", pattern, (int)ret);

	dvr_free((void *)vir_addr);
	return;
}

ssize_t rtk_teeproxy_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
    long ret = count;
    char cmd_buf[100] = {0};

    TEE_PROXY_PR(TEE_LOG_DEBUG, "count=%d, buf=0x%08lx\n", count, (long)buf);

    if (count >= 100)
        return -EFAULT;

    if (copy_from_user(cmd_buf, buf, count)) {
        ret = -EFAULT;
    }

    if ((cmd_buf[0] == 'u') && (count == 2)) {
        TEE_PROXY_PR(TEE_LOG_NOTICE, "== rtk_teeproxy show usr memory usage ==\n");
        rtk_teeproxy_user_alloc_summary();
        TEE_PROXY_PR(TEE_LOG_NOTICE, "=========================================\n");

    } else if ((cmd_buf[0] == 'd') && (count == 2)) {
        TEE_PROXY_PR(TEE_LOG_NOTICE, "== rtk_teeproxy =========================\n");
        rtk_teeproxy_dump();
        TEE_PROXY_PR(TEE_LOG_NOTICE, "=========================================\n");

    } else if ((cmd_buf[0] == 'h') && (count == 2)) {
        TEE_PROXY_PR(TEE_LOG_NOTICE, "== rtk_teeproxy help usage: ==\n");
        rtk_teeproxy_help();
        TEE_PROXY_PR(TEE_LOG_NOTICE, "==============================\n");
    } else if ((cmd_buf[0] == 'l') && (cmd_buf[1] == 'e') && (cmd_buf[2] == 'v')
            && (count == 6)) {
        TEE_PROXY_PR(TEE_LOG_WARN, "== rtk_teeproxy log level: ==\n");
        if((cmd_buf[4] & 0x0F) <= 9)
            set_tee_log_level(cmd_buf[4] & 0x0F);
        TEE_PROXY_PR(TEE_LOG_NOTICE, "==============================\n");
    } else if (count > 5 &&
        (cmd_buf[0] == 't') && (cmd_buf[1] == 'e') && (cmd_buf[2] == 'e') &&
        (cmd_buf[3] == '@') && (cmd_buf[4] == ' ')) {
        TEE_PROXY_PR(TEE_LOG_NOTICE, "== rtkreeproxy: send debug string: %s=============\n",cmd_buf + 9);
        rtkteeproxy_send_string(&cmd_buf[5], count - 5 - 1/* remove \n */);
        TEE_PROXY_PR(TEE_LOG_NOTICE, "=======================================\n");
    } else {
        TEE_PROXY_PR(TEE_LOG_NOTICE, "%s\n", cmd_buf);
    }

    return ret;
}

struct file_operations rtk_teeproxy_fops = {
    .owner  		= THIS_MODULE,
    .unlocked_ioctl 	= rtk_teeproxy_ioctl,
    .write  		= rtk_teeproxy_write,
    .open   		= rtk_teeproxy_open,
    .release		= rtk_teeproxy_release,
};

static char *rtk_teeproxy_devnode(struct device *dev, mode_t *mode)
{
    *mode = 0666;
    return NULL;
}

static int rtk_teeproxy_init(void)
{
    int result;
    dev_t dev = 0;

    TEE_PROXY_PR(TEE_LOG_NOTICE, "******  rtk_teeproxy init module  ******\n");
    if (rtk_teeproxy_major) {
        dev = MKDEV(rtk_teeproxy_major, rtk_teeproxy_minor);
        result = register_chrdev_region(dev, 1, RTK_TEE_PROXY_NAME);
    } else {
        result = alloc_chrdev_region(&dev, rtk_teeproxy_minor, 1, RTK_TEE_PROXY_NAME);
        rtk_teeproxy_major = MAJOR(dev);
    }

    if (result < 0) {
        TEE_PROXY_PR(TEE_LOG_ERROR, "rtk_teeproxy: can not get chrdev region...\n");
        return result;
    }

    TEE_PROXY_PR(TEE_LOG_DEBUG, "rtk_teeproxy init module major number = %d\n", rtk_teeproxy_major);

    rtk_teeproxy_class = class_create(THIS_MODULE, RTK_TEE_PROXY_NAME);
    if (IS_ERR(rtk_teeproxy_class)) {
        TEE_PROXY_PR(TEE_LOG_ERROR, "rtk_teeproxy: can not create class...\n");
        result = PTR_ERR(rtk_teeproxy_class);
        goto fail_class_create;
    }

    rtk_teeproxy_class->devnode = rtk_teeproxy_devnode;

    rtk_teeproxy_platform_devs = platform_device_register_simple(RTK_TEE_PROXY_NAME, -1, NULL, 0);
    if (platform_driver_register(&rtk_teeproxy_device_driver) != 0) {
        TEE_PROXY_PR(TEE_LOG_ERROR, "rtk_teeproxy: can not register platform driver...\n");
        result = -EINVAL;
        goto fail_platform_driver_register;
    }

    cdev_init(&rtk_teeproxy_cdev, &rtk_teeproxy_fops);
    rtk_teeproxy_cdev.owner = THIS_MODULE;
    rtk_teeproxy_cdev.ops = &rtk_teeproxy_fops;
    result = cdev_add(&rtk_teeproxy_cdev, dev, 1);
    if (result < 0) {
        TEE_PROXY_PR(TEE_LOG_ERROR, "rtk_teeproxy: can not add character device...\n");
        goto fail_cdev_init;
    }
    device_create(rtk_teeproxy_class, NULL, dev, NULL, RTK_TEE_PROXY_NAME);

    INIT_LIST_HEAD(&rtk_teeproxy_alloc_head);
    INIT_LIST_HEAD(&rtk_teeproxy_recovery_head);

    //allocate teeproxy_rpc_mem
    teeproxy_rpc_mem.vir_addr = (unsigned long)dvr_malloc_uncached_specific(sizeof(TEE_PROXY_RPC_PARAM_STRUCT), GFP_DCU1, (void**)(&teeproxy_rpc_mem.mem_addr));
    if (!teeproxy_rpc_mem.vir_addr) {
        TEE_PROXY_PR(TEE_LOG_ERROR, "rtk_teeproxy_init alloc rpc memory fail\n");
    } else {
        teeproxy_rpc_mem.phy_addr = (unsigned long)dvr_to_phys((void *)(teeproxy_rpc_mem.vir_addr));
        memset((void *)(teeproxy_rpc_mem.mem_addr), '\0', sizeof(TEE_PROXY_RPC_PARAM_STRUCT));
        TEE_PROXY_PR(TEE_LOG_NOTICE, "rtk_teeproxy: sharedmemory v %x m %x p %x\n", teeproxy_rpc_mem.vir_addr, teeproxy_rpc_mem.mem_addr, teeproxy_rpc_mem.phy_addr);
    }

    //set rpc handle
    if (register_kernel_rpc(RPC_KCPU_ID_0x501_teeproxy_reeapp_freemomery,
        (FUNC_PTR) rtk_teeproxy_reeapp_freememory) == 1) {
        TEE_PROXY_PR(TEE_LOG_NOTICE,"Register teestub_teeapp_callback failed!\n");
    }

    if (register_kernel_rpc(RPC_KCPU_ID_0x503_teeproxy_notify_teemgr_pid,
        (FUNC_PTR) rtk_teeproxy_notify_teemgr_pid) == 1) {
        TEE_PROXY_PR(TEE_LOG_NOTICE,"Register notify_teemgr_pid failed!\n");
    }

    //create kthread
    init_waitqueue_head(&rtk_teeproxy_recovery_wq);
    rtk_teeproxy_recovery_tsk = kthread_create(rtk_teeproxy_recovery_thread, &data_recovery, "rtk_teeproxy_recovery_thread");
    if (IS_ERR(rtk_teeproxy_recovery_tsk)) {
        result = PTR_ERR(rtk_teeproxy_recovery_tsk);
        rtk_teeproxy_recovery_tsk = NULL;
        goto fail_cdev_init;
    }
    wake_up_process(rtk_teeproxy_recovery_tsk);

    //set debug level
    set_tee_log_level(TEE_LOG_NOTICE);

    return 0;

fail_cdev_init:
    platform_driver_unregister(&rtk_teeproxy_device_driver);
fail_platform_driver_register:
    platform_device_unregister(rtk_teeproxy_platform_devs);
    rtk_teeproxy_platform_devs = NULL;
    class_destroy(rtk_teeproxy_class);
fail_class_create:
    rtk_teeproxy_class = NULL;
    unregister_chrdev_region(dev, 1);
    return result;
}

static void rtk_teeproxy_exit(void)
{
    dev_t dev ;
    int ret = 0;

    //free teeproxy_rpc_mem
    if(teeproxy_rpc_mem.vir_addr)
        dvr_free((void *)teeproxy_rpc_mem.vir_addr);

    ret = kthread_stop(rtk_teeproxy_recovery_tsk);
    if (!ret)
        TEE_PROXY_PR(TEE_LOG_DEBUG, "rtk teeproxy recovery thread stopped\n");
    recovery_list_change = 1;
    wake_up(&rtk_teeproxy_recovery_wq);

    dev = MKDEV(rtk_teeproxy_major, rtk_teeproxy_minor);

    /* if ((rtk_teeproxy_platform_devs == NULL) || (class_destroy == NULL)) ?? */
    if ((rtk_teeproxy_platform_devs == NULL) || (rtk_teeproxy_class == NULL))
        BUG();

    device_destroy(rtk_teeproxy_class, dev);
    cdev_del(&rtk_teeproxy_cdev);

    platform_driver_unregister(&rtk_teeproxy_device_driver);
    platform_device_unregister(rtk_teeproxy_platform_devs);
    rtk_teeproxy_platform_devs = NULL;

    class_destroy(rtk_teeproxy_class);
    rtk_teeproxy_class = NULL;

    unregister_chrdev_region(dev, 1);
}

late_initcall(rtk_teeproxy_init);
module_exit(rtk_teeproxy_exit);
