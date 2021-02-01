#ifndef __RTK_CW_DEV_H__
#define __RTK_CW_DEV_H__
#include <base_types.h>
#include <rtk_kdriver/rtk_cw_util.h>
#define RTK_CMD_CW_RELEASE_CW                       0x801
#define RTK_CMD_CW_RQUEST_MULTI_CW                  0x802
#define RTK_CMD_CW_RELEASE_CW_BY_MODULE             0x803
#define RTK_CMD_CW_SET_CW                           0x804
#define RTK_CMD_CW_GET_CW                           0x805
#define RTK_CMD_CW_SET_NONSEQ_CW                    0x806
#define RTK_CMD_CW_GET_NONSEQ_CW                    0x807
#define RTK_CMD_CW_QUERY_FREE_CW                    0x808
#define RTK_CMD_CW_QUERY_USED_CW_BY_MODULE          0x809

#ifdef CONFIG_COMPAT
#define COMPAT_RTK_CMD_CW_RELEASE_CW                0x801
#define COMPAT_RTK_CMD_CW_RQUEST_MULTI_CW           0x802
#define COMPAT_RTK_CMD_CW_SET_CW                    0x804
#define COMPAT_RTK_CMD_CW_GET_CW                    0x805
#define COMPAT_RTK_CMD_CW_SET_NONSEQ_CW             0x806
#define COMPAT_RTK_CMD_CW_GET_NONSEQ_CW             0x807
#define COMPAT_RTK_CMD_CW_QUERY_FREE_CW             0x808
#define COMPAT_RTK_CMD_CW_QUERY_USED_CW_BY_MODULE   0x809
#endif

typedef struct {
    char module_name[CW_MODULE_NAME_LEN];
    unsigned int array_len;
    UINT8 *index_array;
    unsigned int data_len;
    UINT8 *data;
} RTK_CW_COMM_DATA;

#ifdef CONFIG_COMPAT
typedef struct {
    char module_name[CW_MODULE_NAME_LEN];
    unsigned int array_len;
    unsigned int index_array;
    unsigned int data_len;
    unsigned int data;
} COMPAT_RTK_CW_COMM_DATA;
#endif


#endif
