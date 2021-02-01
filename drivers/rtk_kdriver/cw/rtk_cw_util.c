#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <base_types.h>
#include <linux/atomic.h>
#include <rbus/sb2_reg.h>
#include <mach/io.h>
#include <rtk_kdriver/rtk_cw_util.h>

#define GET_GLOBAL_DATA_REF()   atomic_inc_return(&g_cw_global_data.register_limit)
#define PUT_GLOBAL_DATA_REF()   atomic_dec(&g_cw_global_data.register_limit)

#define GET_CW_MANAGER_REF()    atomic_inc_return(&g_cw_global_data.refcount)
#define PUT_CW_MANAGER_REF()    atomic_dec(&g_cw_global_data.refcount)

#define WAIT_CW_MANAGER_FREE() { \
                while(atomic_read(&g_cw_global_data.refcount) > 0) \
                        msleep(1); \
                }

static RTK_CW_GLOBAL_DATA g_cw_global_data = {
    .register_limit = ATOMIC_INIT(0),
    .refcount = ATOMIC_INIT(0),
    .cw_manager = NULL
};


static RTK_CW_MANAGER * get_cw_manager(void)
{
    if(GET_CW_MANAGER_REF() > 1) {
        if(g_cw_global_data.cw_manager)
            return g_cw_global_data.cw_manager;
    }
    PUT_CW_MANAGER_REF();
    return NULL;
}


static void release_cw_manager(void)
{
    PUT_CW_MANAGER_REF();
}


/*-----------------------------------------------------------------------------
* Func : rtk_cw_request_cw
*
* Desc : request a cw
*
* Parm : cw_index:the id of cw which should be less then CW_AREA_LEN
*
* Retn : 0:sucess; -1:fail.
*-----------------------------------------------------------------------------*/
int rtk_cw_request_cw(char *module_name, UINT8 cw_index)
{
    int ret = -1;
    UINT8 index_array[1] = {cw_index};
    RTK_CW_MANAGER *cw_manager = NULL;
    if(module_name == NULL || cw_index >= CW_AREA_LEN)
        return ret;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->request_cws)
            ret = cw_manager->request_cws(cw_manager, module_name, index_array, 1);
        release_cw_manager();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_request_cw);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_request_cw_array
*
* Desc : request multi cws
*
* Parm : index_array:the id array of cws requestd.
*
* Retn : 0:sucess; -1:fail.
*-----------------------------------------------------------------------------*/
int rtk_cw_request_cw_array(char *module_name, UINT8 *index_array, int len)
{
    int i = 0;
    int ret = -1;
    RTK_CW_MANAGER *cw_manager = NULL;
    if(module_name == NULL || len > CW_AREA_LEN)
        return ret;
    for(i = 0; i < len; i++)
        if(index_array[i] >= CW_AREA_LEN)
            return ret;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->request_cws)
            ret = cw_manager->request_cws(cw_manager, module_name, index_array, len);
        release_cw_manager();
    }
    return ret;

}
EXPORT_SYMBOL(rtk_cw_request_cw_array);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_request_multi_cws
*
* Desc : request multi cws
*
* Parm : index_array:the id array of cws requestd.
*
* Retn : 0:sucess; -1:fail.
*-----------------------------------------------------------------------------*/
int rtk_cw_request_multi_cws(char *module_name, UINT8 start_index, int len)
{
    int ret = -1;
    UINT8 index_array[CW_AREA_LEN] = {0};
    int i = 0;
    RTK_CW_MANAGER *cw_manager = NULL;
    if(start_index < 0 || start_index >= CW_AREA_LEN || len <= 0
       || len > CW_AREA_LEN || (start_index + len) >=  CW_AREA_LEN)
        return ret;
    for(i = 0; i < len; i++, start_index++) {
        index_array[i] = start_index;
    }
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->request_cws)
            ret = cw_manager->request_cws(cw_manager, module_name, index_array, len);
        release_cw_manager();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_request_multi_cws);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_release_cw_by_module
*
* Desc : request cws by module name
*
* Parm : index_array:the id array of cws requestd.
*
* Retn : 0:sucess; -1:fail.
*-----------------------------------------------------------------------------*/
int rtk_cw_release_cw_by_module(char *module_name)
{
    int ret = -1;
    RTK_CW_MANAGER *cw_manager = NULL;
    if (module_name == NULL)
        return ret;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->release_cws_by_module)
            ret = cw_manager->release_cws_by_module(cw_manager, module_name);
        release_cw_manager();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_release_cw_by_module);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_release_cw
*
* Desc : release a cw area
*
* Parm : cw_index:the id of cw which should be less then CW_AREA_LEN
*
* Retn : 0:sucess; -1:fail.
*-----------------------------------------------------------------------------*/
int rtk_cw_release_cw(char *module_name, UINT8 cw_index)
{
    int ret = -1;
    RTK_CW_MANAGER *cw_manager = NULL;
    if (module_name == NULL || cw_index < 0 || cw_index >= CW_AREA_LEN)
        return ret;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->release_cw)
            ret = cw_manager->release_cw(cw_manager, module_name, cw_index);
        release_cw_manager();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_release_cw);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_set_cw
*
* Desc : request a continue cw areas
*
* Parm : cw_index:the id of cw which should be less then CW_AREA_LEN
*
* Retn : 0:sucess; -1:fail.
*-----------------------------------------------------------------------------*/
int rtk_cw_set_cw(char *module_name, UINT8 start_index, UINT8 *content, int len)
{
    int ret = -1;
    RTK_CW_MANAGER *cw_manager = NULL;
    if(module_name == NULL || start_index < 0 ||
       start_index >= CW_AREA_LEN || content == NULL || len <= 0)
        return ret;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->set_continous_cws)
            ret = cw_manager->set_continous_cws(cw_manager, module_name, start_index, content, len);
        release_cw_manager();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_set_cw);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_set_nonseq_cw
*
* Desc : request a continue cw areas
*
* Parm : cw_index:the id of cw which should be less then CW_AREA_LEN
*
* Retn : 0:sucess; -1:fail.
*-----------------------------------------------------------------------------*/
int rtk_cw_set_nonseq_cw(char *module_name, UINT8 *index_array, int arr_len, UINT8 *content, int len)
{
    int ret = -1;
    RTK_CW_MANAGER *cw_manager = NULL;
    if(module_name == NULL || index_array == NULL
       || arr_len <= 0 || content == NULL || len <= 0)
        return ret;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->set_uncontinous_cws)
            ret = cw_manager->set_uncontinous_cws(cw_manager, module_name, index_array, arr_len, content, len);
        release_cw_manager();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_set_nonseq_cw);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_get_cw
*
* Desc : request a single or multi cws
*
* Parm : cw_index:the id of cw which should be less then CW_AREA_LEN
*
* Retn : 0:sucess; -1:fail.
*-----------------------------------------------------------------------------*/
int rtk_cw_get_cw(char *module_name, UINT8 start_index, UINT8 *content, int len)
{
    int ret = -1;
    RTK_CW_MANAGER *cw_manager = NULL;
    if(module_name == NULL || start_index < 0 || start_index >= CW_AREA_LEN
       || content == NULL || len <= 0)
        return ret;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->get_continous_cws)
            ret = cw_manager->get_continous_cws(cw_manager, module_name, start_index, content, len);
        release_cw_manager();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_get_cw);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_get_nonseq_cw
*
* Desc : request a single or multi cws
*
* Parm : cw_index:the id of cw which should be less then CW_AREA_LEN
*
* Retn : 0:sucess; -1:fail.
*-----------------------------------------------------------------------------*/
int rtk_cw_get_nonseq_cw(char *module_name, UINT8 *index_array, int arr_len, UINT8 *content, int len)
{
    int ret = -1;
    RTK_CW_MANAGER *cw_manager = NULL;
    if(module_name == NULL || index_array == NULL
       || arr_len <= 0 || content == NULL || len <= 0)
        return ret;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->get_uncontinous_cws)
            ret = cw_manager->get_uncontinous_cws(cw_manager, module_name, index_array, arr_len, content,  len);
        release_cw_manager();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_get_nonseq_cw);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_query_used_cw_by_module
*
* Desc : query used cw area
*
* Parm : bitArray:the len should be BITMAP_LEN.
*
* Retn : -1:fail, other:the coutn of free cw
*-----------------------------------------------------------------------------*/

int rtk_cw_query_used_cw_by_module(char *module_name, UINT8 *index_array, int len)
{
    int ret = -1;
    RTK_CW_MANAGER *cw_manager = NULL;
    if (module_name == NULL || index_array == NULL || len <= 0)
        return ret;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->query_used_cws_by_module)
            ret = cw_manager->query_used_cws_by_module(cw_manager, module_name, index_array, len);
        release_cw_manager();
    }

    return ret;
}
EXPORT_SYMBOL(rtk_cw_query_used_cw_by_module);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_query_free_cw
*
* Desc : query free cw area
*
* Parm : bitArray:the len should be BITMAP_LEN.
*
* Retn : -1:failed, other:the coutn of free cws
*-----------------------------------------------------------------------------*/

int rtk_cw_query_free_cw(UINT8 *free_index_array, int len)
{
    int ret = -1;
    RTK_CW_MANAGER *cw_manager = NULL;
    if (free_index_array == NULL || len <= 0)
        return ret;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->query_free_cws)
            ret = cw_manager->query_free_cws(cw_manager, free_index_array, len);
        release_cw_manager();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_query_free_cw);

/*-----------------------------------------------------------------------------
* Func : rtk_cw_dump_cw_status
*
* Desc : dump the use circustance of cw area
*
* Parm : module_name : the module name of module to request; cw_index:the index of cw.
*
* Retn : OTP words
*-----------------------------------------------------------------------------*/
int rtk_cw_dump_cw_status(char *buf)
{
    int ret = -1;
    RTK_CW_MANAGER *cw_manager = NULL;
    if(buf == NULL)
        return 0;
    cw_manager = get_cw_manager();
    if(cw_manager) {
        if(cw_manager->dump_cws_status)
            ret = cw_manager->dump_cws_status(cw_manager, buf);
        release_cw_manager();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_dump_cw_status);


/*-----------------------------------------------------------------------------
* Func : rtk_cw_register_cw_manager:: only allow to register for only one module
*
* Desc : regiter cw manager
*
* Parm :
*
* Retn : 0, sucess; else failed
*-----------------------------------------------------------------------------*/
int rtk_cw_register_cw_manager(RTK_CW_MANAGER *cw_manager)
{
    int ret = -1;
    if(cw_manager == NULL)
        return ret;
    if(GET_GLOBAL_DATA_REF() == 1) {
        if(cw_manager->init)
            ret = cw_manager->init(cw_manager);
        if(ret != 0) {
            PUT_GLOBAL_DATA_REF();
        } else {
            g_cw_global_data.cw_manager = cw_manager;
            GET_CW_MANAGER_REF();
        }
    } else {
        PUT_GLOBAL_DATA_REF();
    }
    return ret;
}
EXPORT_SYMBOL(rtk_cw_register_cw_manager);


/*-----------------------------------------------------------------------------
* Func : rtk_cw_unregister_cw_manager:: only allow to unregister for first
*
* Desc : unregiter cw manager
*
* Parm :
*
* Retn :
*-----------------------------------------------------------------------------*/
int rtk_cw_unregister_cw_manager(RTK_CW_MANAGER *cw_manager)
{
    if(cw_manager == NULL)
        return -1;
    if(g_cw_global_data.cw_manager == cw_manager) {
        PUT_CW_MANAGER_REF();
        WAIT_CW_MANAGER_FREE();
        g_cw_global_data.cw_manager = NULL;
        PUT_GLOBAL_DATA_REF();
        if(cw_manager->deinit)
            cw_manager->deinit(cw_manager);
    }
    return 0;

}
EXPORT_SYMBOL(rtk_cw_unregister_cw_manager);

