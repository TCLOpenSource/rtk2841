/******************************************************************************
 *
 *   Realtek TeeProxy driver
 *
 *   Copyright(c) 2016 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author
 *
 *****************************************************************************/


#ifndef _LINUX_RTK_TEE_PROXY_H_
#define _LINUX_RTK_TEE_PROXY_H_

#include <linux/ioctl.h> /* needed for the _IOW etc stuff used later */
#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/list.h>

//#define RTK_TEE_PROXY_FUNC_TEST

#ifndef RTK_TEE_PROXY_MAJOR
#define RTK_TEE_PROXY_MAJOR 0 /* dynamic major by default */
#endif

#define REE_FLAG_SUCCESS    (0x10000000)
#define S_OK        ((REE_FLAG_SUCCESS) | (0x00000000))
#define S_FALSE     ((REE_FLAG_SUCCESS) | (0x00000001))

#define RTK_TEE_PROXY_NAME		"rtkteeproxy"
#define MAX_REE_APP_NUM  8

typedef enum _TEE_PROXY_LOG_LEVEL {
    TEE_LOG_EMESG = 0,
    TEE_LOG_ALERT,
    TEE_LOG_CRIT,
    TEE_LOG_ERROR,
    TEE_LOG_WARN,
    TEE_LOG_NOTICE,
    TEE_LOG_INFO,
    TEE_LOG_DEBUG,
    TEE_LOG_TRACE,
    TEE_LOG_MAX
} TEE_PROXY_LOG_LEVEL;

typedef enum _TEE_BUF_TYPE {
	TEE_TYPE_NONE = 0,
	TEE_TYPE_PR2_POLLING,
	TEE_TYPE_PR2_RPC,
	TEE_TYPE_PR3_POLLING,
	TEE_TYPE_PR3_RPC,
	TEE_TYPE_WIDEVINE,
	TEE_TYPE_DRM,
	TEE_TYPE_SSTORE,
	TEE_TYPE_SKB,
    TEE_TYPE_SHARE_MEMORY,//need not to notify KCPU in kill func
	TEE_TYPE_MAX
} TEE_BUF_TYPE;

/* Record memory use*/
typedef struct ree_buf_info {
	struct list_head buffer_list;

	pid_t         ree_pid[MAX_REE_APP_NUM];
	pid_t         tee_pid;
    unsigned int  ref_cnt;
    TEE_BUF_TYPE  tee_type;

	unsigned int vir_addr; 	//virtual address
	unsigned int phy_addr; 	//physical address
	unsigned long request_size;     //request size
	unsigned long malloc_size;      //malloc size
} _ree_buf_info;

/* Record pid for recovery*/
typedef struct ree_recovery_info {
	struct list_head buffer_list;
	pid_t         ree_pid;
} _ree_recovery_info;

/* Record phy addr for recovery*/
typedef struct ree_recovery_addr {
	struct list_head buffer_list;
	unsigned int phy_addr; 	//physical address
} _ree_recovery_addr;

/* Record pid for rpc use*/
typedef struct rpc_buf_info {
	struct list_head buffer_list;
	pid_t         ree_pid;
	pid_t         tee_pid;
} _rpc_buf_info;

/* Record rpc shared mem addr*/
typedef struct _TEE_PROXY_RPC_MEM_STRUCT {
    unsigned int mem_addr;
    unsigned int phy_addr;
    unsigned int vir_addr;
} TEE_PROXY_RPC_MEM_STRUCT;

/* Record rpc param mem */
typedef struct _TEE_PROXY_RPC_PARAM_STRUCT {
	pid_t         ree_pid;
	pid_t         tee_pid;
} TEE_PROXY_RPC_PARAM_STRUCT;

typedef struct _TEE_ALLOC_MEM_STRUCT {
    pid_t tee_pid;
    unsigned int  new_buf;
    TEE_BUF_TYPE  tee_type;
    unsigned int size;
} TEE_ALLOC_MEM_STRUCT;

/* Use 't' as magic number */
#define TEE_PROXY_IOC_MAGIC  't'
#define TEE_PROXY_IOC_INIT       _IO  (TEE_PROXY_IOC_MAGIC, 1)
#define TEE_PROXY_IOC_DEINIT     _IO  (TEE_PROXY_IOC_MAGIC, 2)
#define TEE_PROXY_IOC_ALLOC      _IOW (TEE_PROXY_IOC_MAGIC, 3, TEE_ALLOC_MEM_STRUCT *)
#define TEE_PROXY_IOC_FREE       _IOW (TEE_PROXY_IOC_MAGIC, 4, int)
#define TEE_PROXY_IOC_KILL       _IOW (TEE_PROXY_IOC_MAGIC, 5, int)
#define TEE_PROXY_IOC_TEEMGR_PID _IOR (TEE_PROXY_IOC_MAGIC, 6, pid_t)

unsigned long rtk_teeproxy_free_user_mem(unsigned long para1);

/* end of _LINUX_RTK_TEE_PROXY_H_ */
#endif
