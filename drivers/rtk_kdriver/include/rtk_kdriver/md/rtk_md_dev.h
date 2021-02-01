#ifndef __RTK_MD_DEV_H__
#define __RTK_MD_DEV_H__
#include <linux/types.h>

#ifndef MD_MAJOR
#define MD_MAJOR        0
#endif
#ifndef MD_MINOR
#define MD_MINOR        0
#endif

#define MD_IOC_MAGIC  'k'
#define MD_IOC_READ_INST_COUNT _IOR(MD_IOC_MAGIC, 15, int)
#define MD_IOC_WRITE_ISSUE_CMD _IOW(MD_IOC_MAGIC, 16, int)
#define MD_IOC_READ_ISSUED_INST_COUNT _IOR(MD_IOC_MAGIC, 17, int)
#define MD_IOC_COPY_PAGES       _IOW(MD_IOC_MAGIC, 18, struct copy_pages_cmd)
#define MD_IOC_WAIT_FOR_COMPLETE _IO(MD_IOC_MAGIC, 19)
#define MD_IOC_WRITE_EX_CMD     _IOW(MD_IOC_MAGIC, 20, struct write_cmd)
#define MD_IOC_DO_MEMCPY_TRANSACTION    _IOW(MD_IOC_MAGIC, 21, int)
#define MD_IOC_DO_ABILITY_PROBE _IOR(MD_IOC_MAGIC, 22, int)


struct copy_pages_cmd {
    /* 0: memcpy, 1: memset */
    unsigned int op;
    unsigned int phys_dst;
    unsigned int phys_src;
    unsigned int length;
};

struct write_cmd {
    unsigned int virt_dst;
    unsigned int virt_src;
    unsigned int length;
};

typedef struct _MD_MEMCPY_TRANSACTION {
    unsigned int dst;
    unsigned int src;
    unsigned int len;
    /*bit0: input_sel  bit1: move_dir*/
    unsigned int flags;
} MD_MEMCPY_TRANSACTION;

#endif
