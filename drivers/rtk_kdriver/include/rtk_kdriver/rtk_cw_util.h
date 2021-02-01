#ifndef __RTK_CW_UTIL_H__
#define __RTK_CW_UTIL_H__
#include <asm/types.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/atomic.h>
/***********************Structs define and interfaces define***********************/
#define CW_MODULE_NAME_LEN 26
#define CW_AREA_LEN 128
#define BITMAP_LEN  BITS_TO_LONGS(CW_AREA_LEN)
typedef struct _RTK_CW_MANAGER RTK_CW_MANAGER;
struct _RTK_CW_MANAGER {
    void *private;
    int (*init)(RTK_CW_MANAGER *p_this);
    int (*deinit)(RTK_CW_MANAGER *p_this);
    int (*request_cws)(RTK_CW_MANAGER *p_this, char *module_name, UINT8 *index_array, int len);
    int (*release_cw)(RTK_CW_MANAGER *p_this, char *module_name, UINT8 cw_index);
    int (*release_cws_by_module)(RTK_CW_MANAGER *p_this, char *module_name);
    int (*set_continous_cws)(RTK_CW_MANAGER *p_this,
                             char *module_name, UINT8 start_index, UINT8 *content, int len);
    int (*get_continous_cws)(RTK_CW_MANAGER *p_this, char *module_name,
                             UINT8 start_index, UINT8 *content, int len);
    int (*set_uncontinous_cws)(RTK_CW_MANAGER *p_this, char *module_name,
                               UINT8 *index_array, int arr_len, UINT8 *content, int len);
    int (*get_uncontinous_cws)(RTK_CW_MANAGER *p_this, char *module_name,
                               UINT8 *index_array, int arr_len, UINT8 *content, int len);
    int (*query_free_cws)(RTK_CW_MANAGER *p_this, UINT8 *free_index_array, int len);
    int (*query_used_cws_by_module)(RTK_CW_MANAGER *p_this, char *module_name,
                                    UINT8 *index_array, int len);
    int (*dump_cws_status)(RTK_CW_MANAGER *p_this, char *buf);
};

typedef struct _RTK_CW_GLOBAL_DATA {
    atomic_t register_limit;
    atomic_t refcount;
    RTK_CW_MANAGER *cw_manager;
} RTK_CW_GLOBAL_DATA;

int rtk_cw_request_cw(char *module_name, UINT8 cw_index);
int rtk_cw_request_cw_array(char *module_name, UINT8 *index_array, int len);
int rtk_cw_request_multi_cws(char *module_name, UINT8 start_index, int len);
int rtk_cw_release_cw(char *module_name, UINT8 cw_index);
int rtk_cw_release_cw_by_module(char *module_name);
int rtk_cw_set_cw(char *module_name, UINT8 start_index, UINT8 *content, int len);
int rtk_cw_get_cw(char *module_name, UINT8 start_index, UINT8 *content, int len);
int rtk_cw_set_nonseq_cw(char *module_name,
                         UINT8 *index_array, int arr_len, UINT8 *content, int len);
int rtk_cw_get_nonseq_cw(char *module_name,
                         UINT8 *index_array, int arr_len, UINT8 *content, int len);
int rtk_cw_query_free_cw(UINT8 *free_index_array, int len);
int rtk_cw_query_used_cw_by_module(char *module_name, UINT8 *index_array, int len);
int rtk_cw_dump_cw_status(char *buf);



extern int rtk_cw_register_cw_manager(RTK_CW_MANAGER *cw_manager);
extern int rtk_cw_unregister_cw_manager(RTK_CW_MANAGER *cw_manager);

#endif
