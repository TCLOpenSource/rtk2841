#ifndef __DC_MT_H__
#define __DC_MT_H__

#include <mach/rtk_log.h>
#include "rtk_dc_mt_config.h"

//#define DCMT_DCU2      1
//#define DCMT_AV2      1

extern int dcmt_log_setting;

#define DCMT_TAG "DCMT"
//#define ADDR_CONVERT_FAIL 0xFFFFFFFF
//#define ADDR_CONVERT_NO_MAPPING 0xFFFFFFFE
#define DCMT_ALIGN_SIZE 0x20

#define FRED_START "\033[1;31;40m"
#define FYELLOW_START "\033[1;33;40m"
#define FCOLOR_END "\033[0m"

/*bootcode param keywords*/
#define DCMT_ENV_MEM_SET        "dcmt_set="
#define DCMT_ENV_MEM_UNSET      "dcmt_unset="
#define DCMT_ENV_DBG_LOG        "dcmt_log="
#define DCMT_ENV_KEEP_GO        "dcmt_keepgo="
#define DCMT_ENV_DRIVER_DISABLE "dcmt_disable="

#define MODULE_ID(bridge, module)       ((bridge & 0xF)<<4 |(module & 0xf))
#define BRIDGE_ID(module)               ((module>>4) & 0xF)
#define SUB_MODULE_ID(module)           (module & 0xf)

typedef enum
{
        MEMORY_TYPE_NONE   = 0,
        MEMORY_TYPE_SERIAL = 1,
        MEMORY_TYPE_BLOCK  = 2,
        MEMORY_TYPE_SERIAL_BLOCK  = 3,
} MEMORY_TYPE;

typedef enum
{
        PROT_MODE_NONE = 0,
        PROT_MODE_RO   = 1,
        PROT_MODE_WO   = 2,
        PROT_MODE_RW   = 3,
        PROT_MODE_NUM
} PROT_MODE;

typedef enum
{
        MT_MODE_DISABLE  = 0,
        MT_MODE_MATCH_IN_RANGE = 1,
        MT_MODE_MISMATCH_IN_RANGE = 2,
        MT_MODE_MATCH_OUT_OF_RANGE = 3
} MT_MODE;

typedef enum
{
        MT_SYS1  = 0,
        MT_SYS2 = 1,
        MT_SYS3 = 2,
        MT_MAX = 3
} MT_SYS_ID;

typedef enum
{
        DC1_MODE = 0,
        DC2_MODE = 1,
        IB_1_1_MODE = 2,
        IB_1_2_MODE = 4,
        IB_2_1_MODE = 5,
} IB_MODE;

typedef enum
{
        DCMT_RANGE_START = 0,
        DCMT_RANGE_END,
} START_END;

/*
typedef struct {
        unsigned int addcmd_hi;
        unsigned int addcmd_lo;
        unsigned int addcmd_sa;
        unsigned int intr_enable;
        unsigned int intr_status;
} DC_MT_TRAP_INFO;
*/
#define MAX_MODULE_NAME_LEN     32

typedef struct
{
        unsigned char id;
        const char      name[MAX_MODULE_NAME_LEN];
} MODULE_INFO;

typedef struct
{
        char * key;
        unsigned char * table;
        int table_len;
} MODULE_SEARCH_TABLE;

typedef struct
{
        MEMORY_TYPE type;//s/b/sb
        unsigned long start;//start addr,force 32B align by hw
        unsigned long end;//end addr,force 32B align by hw
        unsigned char mode;//mode1/2/3
        unsigned char module_max;//user don't need care about this value, _dcmt_set_monitor() will init it.
        struct
        {
                unsigned char prot;//r/w/rw
                unsigned char module;//module_id
        } ip_entry[8];//mem0-3 can ony use 4 entry(entry[0]-entry[3]), mem4-7 use 8 entry.

} DC_MT_DESC;


typedef struct
{
        unsigned char   entry;
        DC_MT_DESC      desc;
} DC_MT_PARAMETER;

enum IB_SEQ_REGION
{
        SEQ_PHY = 0,
        SEQ_DC1,
        SEQ_DC2,
        SEQ_NUM
};

enum IB_SEQ_BOUND
{
        BOUND_0 = 0,
        BOUND_1,
        BOUND_2,
        BOUND_3,
        BOUND_NUM
};

typedef enum DCID
{
        DCID_1 = 0,
#if 0
        DCID_2,
#endif
        DC_NUM
} DCID;

enum DCMT_INTR_ROUT
{
        DCMT_INTR_ROUT_SCPU = 0,
        DCMT_INTR_ROUT_ACPU1,
        DCMT_INTR_ROUT_VCPU1,
        DCMT_INTR_ROUT_KCPU
};

enum DCMT_INTR_MODE
{
        DCMT_INTR_MODE_SILIENCE = 0,
        DCMT_INTR_MODE_SIMPLE = 1,
        DCMT_INTR_MODE_PRINT = 2,
        DCMT_INTR_MODE_PANIC = 3,
        DCMT_INTR_MODE_INVALID
};

enum DCMT_DFT_MEM
{
        DCMT_DFT_MEM_OVERRANGE = 0,
        DCMT_DFT_MEM_KCPU,
        DCMT_DFT_MEM_GPU1,
        DCMT_DFT_MEM_GPU2,
        DCMT_DFT_MEM_ACPU,
        DCMT_DFT_MEM_VCPU,
        DCMT_DFT_MEM_KERNEL,
        DCMT_DFT_MEM_AV_EXCEPTION,
        DCMT_DFT_MEM_KASAN = DC_MT_ENTRY_COUNT-1
};

enum DCMT_RANGE_SYNC
{
        DCMT_RANGE_SYNC_A_START = 0,
        DCMT_RANGE_SYNC_A_END,
        DCMT_RANGE_SYNC_V_START,
        DCMT_RANGE_SYNC_V_END,
        DCMT_RANGE_SYNC_K_START,
        DCMT_RANGE_SYNC_K_END,
        DCMT_RANGE_SYNC_SECURE_START,
        DCMT_RANGE_SYNC_SECURE_END,
        DCMT_RANGE_SYNC_NUM
};

enum DCMT_LOG_FLAG
{
       DCMT_LOG_INIT = (1<<0), //init log
       DCMT_LOG_SET  = (1<<1),//set/unset log
       DCMT_LOG_ISR  = (1<<2),//interrupt log
       DCMT_LOG_ERR  = (1<<3),//error log
       DCMT_LOG_CMD  = (1<<4),//command log
       DCMT_LOG_UTIP = (1<<5),//user tip log
       DCMT_LOG_ADDR = (1<<6),//IB <-> DC addr change log
       DCMT_LOG_DBG  = (1<<7),//misc debug log
};

#define PROC_PARAM_CNTL          0
#define PROC_PARAM_MODULES       1
#define PROC_PARAM_STAT          2
#define PROC_PARAM_LOG           3
#define INT_CTRL_SCPU_reg 0xb8000290
#define DC_INIT_SCPU_ROUTING_EN (BIT(11))

#define INT_CTRL_VCPU_reg 0xb8000294
#define DC_INIT_VCPU_ROUTING_EN (BIT(11))

#define INT_CTRL_ACPU_reg 0xb8000298
#define DC_INIT_ACPU_ROUTING_EN (BIT(11))

#define INT_CTRL_KCPU_reg 0xb800029C
#define DC_INIT_KCPU_ROUTING_EN (BIT(11))

#define DCMT_DDR_SIZE_1_5_G 0x60000000
#define DCMT_DDR_SIZE_768_M 0x30000000

typedef struct dcmt_addr_desc
{
        unsigned int int_offset; //intr pend bit offset
        unsigned int int_mask; //intr basic mask
        /*setting addr*/
        unsigned int misc_addr;
        unsigned int type_addr;
        unsigned int saddr_addr;
        unsigned int eaddr_addr;
        unsigned int mode_addr;
        unsigned int table0_addr;//module
        unsigned int table1_addr;//module for mtex
        unsigned int hi0_addr;//rw
        unsigned int hi1_addr;//rw for mtex
        unsigned int int_en_addr;
        unsigned int int_en_sys2_addr;
        unsigned int int_en_sys3_addr;
        unsigned int sys2_mux_addr;
        unsigned int sys3_mux_addr;
        unsigned int intr_routing_addr;
        /*status addr*/
        unsigned int int_status_addr;
        unsigned int int_status_sys2_addr;
        unsigned int int_status_sys3_addr;
        //hi0_addr : already decalred above
        unsigned int lo_addr;
        unsigned int sa_addr;
        unsigned int hi0_sys2_addr;
        unsigned int lo_sys2_addr;
        unsigned int sa_sys2_addr;
        unsigned int hi0_sys3_addr;
        unsigned int lo_sys3_addr;
        unsigned int sa_sys3_addr;
} dcmt_addr_desc;

//////////////////////////////////////////////////////////////////
// APIs
//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// Debug
//////////////////////////////////////////////////////////////////
#define DCMT_LOG(flag, level, fmt, args...) \
        do { \
                if((flag) & dcmt_log_setting) \
                { \
                        rtd_printk(level, DCMT_TAG, fmt, ## args); \
                } \
        }while(0) \


#define DC_MT_DBG_ENABLE 0
#ifdef DC_MT_DBG_ENABLE
#define DC_MT_DBG(fmt, args...)     rtd_printk(KERN_DEBUG, DCMT_TAG, " DBG, " fmt, ## args)
#else
#define DC_MT_DBG(fmt, args...)
#endif

#if 1
#define DC_MT_INFO(fmt, args...)    rtd_printk(KERN_INFO, DCMT_TAG, fmt, ## args)
#define DC_MT_WARNING(fmt, args...) rtd_printk(KERN_WARNING, DCMT_TAG, fmt, ## args)
#define DC_MT_ERR(fmt, args...)     rtd_printk(KERN_ERR, DCMT_TAG, fmt, ## args)
#define DC_MT_NOTICE(fmt,args...) rtd_printk(KERN_NOTICE, DCMT_TAG, fmt, ## args)
#else
#define DC_MT_INFO(fmt, args...)
#define DC_MT_WARNING(fmt, args...)
#define DC_MT_ERR(fmt, args...)
#define DC_MT_NOTICE(fmt,args...)
#endif

//////////////////////////////////////////////////////////////////
// DCMT call back function
//////////////////////////////////////////////////////////////////
typedef struct dcmt_trap_info
{
        unsigned long trash_addr;
        int module_id;
        int rw_type; //0:read 1:write
        int isTraped;
} dcmt_trap_info;

#ifdef CONFIG_RTK_KDRV_DC_MEMORY_TRASH_DETCTER
#include <linux/notifier.h>

extern struct atomic_notifier_head dcmt_notifier_list;
extern struct atomic_notifier_head dcmt_notifier_list_cat;

int get_dcmt_trap_info(dcmt_trap_info * info);
int isDcmtTrap(char * module_name);
int dcmt_set_monitor_auto(DC_MT_DESC * pDesc);
int dcmt_set_monitor(unsigned int entry, DC_MT_DESC * pDesc);
void dcmt_clear_monitor(unsigned int entry);

#define DCMT_DEBUG_INFO_DECLARE(name,func)  \
        static int DCMT_notifier_##name (struct notifier_block *this, unsigned long ev, void *ptr)  \
        {  \
                func();    \
                return NOTIFY_OK;     \
        } \
        static struct notifier_block DCMT_##name = {    \
            .notifier_call = DCMT_notifier_##name ,    \
        };      \
                \
        static int DCMT_notifier_cat_##name (struct notifier_block *this, unsigned long ev, void *ptr)\
        {       \
                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t\t%s\n",#name);    \
                return NOTIFY_OK;     \
        }       \
        static struct notifier_block DCMT_cat_##name = {    \
                .notifier_call = DCMT_notifier_cat_##name ,    \
        }

//rtd_printk(KERN_ERR, "%s\n",tmp);

#define DCMT_DEBUG_INFO_REGISTER(name,func)  atomic_notifier_chain_register(&dcmt_notifier_list, &DCMT_##name );\
        atomic_notifier_chain_register(&dcmt_notifier_list_cat, &DCMT_cat_##name )
#define DCMT_DEBUG_INFO_UNREGISTER(name,func)  atomic_notifier_chain_unregister(&dcmt_notifier_list, &DCMT_##name );\
        atomic_notifier_chain_unregister(&dcmt_notifier_list_cat, &DCMT_cat_##name )
#else

#define DCMT_DEBUG_INFO_DECLARE(name,func)
#define DCMT_DEBUG_INFO_REGISTER(name,func)
#define DCMT_DEBUG_INFO_UNREGISTER(name,func)

static inline int get_dcmt_trap_info(dcmt_trap_info * info)
{
        return 0;
}

static inline int isDcmtTrap(char * module_name)
{
        return 0;
}

#endif

#endif  //__DC_MT_H__
