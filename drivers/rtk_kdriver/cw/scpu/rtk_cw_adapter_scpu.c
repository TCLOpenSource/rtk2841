#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <base_types.h>
#include <rbus/sb2_reg.h>
#include <mach/io.h>
#include "rtk_cw_reg.h"
#include "../rtk_cw_dbg.h"
#include "rtk_cw_adapter_scpu.h"
#include <rtk_kdriver/rtk_semaphore.h>


extern bool set_cw_dbg_en;
extern bool get_cw_dbg_en;

/*******************READ/WRITE CW HW**************************/
/*-----------------------------------------------------------------------------
* Func : _Set_CW
*
* Desc : write data to a cw
*
* Parm :
*
* Retn :
*-----------------------------------------------------------------------------*/
static void cw_hw_semaphore_try_lock(void)
{
	int ret = 0;
//    while (!*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_6_reg)) {
    ret = rtd_hwsem_trylock(SEMA_HW_SEM_6_SCPU_2) ;
    while ( ret != 1 ) {	
        CW_DBG("wait SB2_HD_SEM_NEW_6_reg ready\n");
        udelay(10);
	ret = rtd_hwsem_trylock(SEMA_HW_SEM_6_SCPU_2);
    }
}

static void cw_hw_semaphore_unlock(void)
{
    //*(unsigned int volatile *)GET_MAPPED_RBUS_ADDR(SB2_HD_SEM_NEW_6_reg) = 0;
    rtd_hwsem_unlock(SEMA_HW_SEM_6_SCPU_2);
}

static INT32 _Set_CW(UINT8 cw_index,  UINT32 *data)
{
    cw_key_ctrl_RBUS cw_key_ctrl;

    cw_hw_semaphore_try_lock();
    /*data[0]Ϊhigh. data[1]Ϊlow */
    WRITE_REG32(CW_KEY_INFO_VADDR, data[0]);
    WRITE_REG32(CW_KEY_INFO_VADDR + 4, data[1]);

    cw_key_ctrl.regValue = 0;
    cw_key_ctrl.idx = cw_index;
    cw_key_ctrl.r_w = 1;
    WRITE_REG32(CW_KEY_CTRL_VADDR, cw_key_ctrl.regValue);

    WRITE_REG32(CW_KEY_INFO_VADDR , 0);
    WRITE_REG32(CW_KEY_INFO_VADDR + 4, 0);
    cw_hw_semaphore_unlock();

    CW_DBG("Set CW (id=%u) = %08x %08x\n", cw_index, data[0], data[1]);

    return 0;
}


/*-----------------------------------------------------------------------------
* Func : _Get_CW
*
* Desc : get data from a cw
*
* Parm :
*
* Retn :
*-----------------------------------------------------------------------------*/

static INT32 _Get_CW(UINT8  cw_index, UINT32 *data)
{
    cw_key_ctrl_RBUS cw_key_ctrl;

    cw_hw_semaphore_try_lock();
    WRITE_REG32(CW_KEY_INFO_VADDR , 0);
    WRITE_REG32(CW_KEY_INFO_VADDR + 4, 0);

    cw_key_ctrl.regValue = 0;
    cw_key_ctrl.idx = cw_index;
    cw_key_ctrl.r_w = 0;
    WRITE_REG32(CW_KEY_CTRL_VADDR, cw_key_ctrl.regValue);

    /*data[0]Ϊhigh. data[1]Ϊlow */
    data[0] = READ_REG32(CW_KEY_INFO_VADDR);
    data[1] = READ_REG32(CW_KEY_INFO_VADDR + 4);
    cw_hw_semaphore_unlock();

    CW_DBG("Get CW (id=%u) = %08x %08x\n", cw_index, data[0], data[1]);

    return 0;
}

/*-----------------------------------------------------------------------------
* Func : _Set_CW
*
* Desc : write data to a cw
*
* Parm :
*
* Retn :
*-----------------------------------------------------------------------------*/
static INT32 Set_CW(UINT8 cw_index,  UINT8 *content, int len)
{
    UINT32 data[2] = {0, 0};
    UINT8 buf[TPK_CW_LENGTH] = {0};
    int i = 0;
    memset(buf, 0, TPK_CW_LENGTH);
    if(len != TPK_CW_LENGTH) {
        _Get_CW(cw_index,  data);
        memcpy(buf, &data[1], TPK_CW_LENGTH / 2);
        memcpy(buf + TPK_CW_LENGTH / 2, &data[0], TPK_CW_LENGTH / 2);
    }

    for(i = 0; i < len && i < TPK_CW_LENGTH; i++)
        buf[i] = content[i];
    data[0] = *((UINT32 *)(buf + 4));
    data[1] = *((UINT32 *)buf);
    _Set_CW(cw_index,  data);
    return 0;
}

/*-----------------------------------------------------------------------------
* Func : Get_CW
*
* Desc : get data from a cw
*
* Parm :
*
* Retn :
*-----------------------------------------------------------------------------*/

static INT32 Get_CW(UINT8  cw_index, UINT8 *content, int len)
{
    UINT32 data[2] = {0, 0};
    UINT8 buf[TPK_CW_LENGTH];
    int i = 0;
    _Get_CW(cw_index,  data);
    memcpy(buf, &data[1], TPK_CW_LENGTH / 2);
    memcpy(buf + TPK_CW_LENGTH / 2, &data[0], TPK_CW_LENGTH / 2);
    for(i = 0; i < len && i < TPK_CW_LENGTH; i++) {
        content[i] = buf[i];
    }
    return 0;
}


static int single_cpu_request_cw_array(RTK_CW_MANAGER *p_this,
                                       char *module_name, UINT8 *index_array, int len)
{
    int i = 0;
    RTK_CW_KEY_REGION *cw_node = NULL;
    struct list_head *plist = NULL;
    unsigned long flags;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;

    if (module_name == NULL || index_array == NULL || len <= 0 || len > CW_AREA_LEN)
        return -1;

    CW_DBG("module[%s] send a request for multi cws: ", module_name);
    for(i = 0; i < len; i++) {
        CW_DBG("[%d] ", index_array[i]);
        if(index_array[i] < 0 || index_array[i] >= CW_AREA_LEN)
            return -1;
    }
    CW_DBG("\n");


    WRITE_LOCK(key_mm->cw_mm_lock, flags);
    list_for_each(plist, &key_mm->cw_key_region_list) {
        RTK_CW_KEY_REGION *tmp = list_entry(plist, RTK_CW_KEY_REGION, node);
        if (strcmp(tmp->module_name, module_name) == 0) {
            cw_node = tmp;
            break;
        }
    }

    for(i = 0; i < len; i++) {
        if (test_bit(index_array[i], key_mm->cw_map)) {
            if(cw_node == NULL || !test_bit(index_array[i], cw_node->map)) {
                CW_WARNING("module[%s] request a cw[%d] which has been occupied by other module\n", module_name, index_array[i]);
                goto MULTI_REQUEST_FAILED;
            }
        }
    }
    if (cw_node == NULL) {
        cw_node = (RTK_CW_KEY_REGION *)kmalloc(sizeof(RTK_CW_KEY_REGION), GFP_ALLOCK_FLAG);
        if (cw_node == NULL) {
            CW_WARNING("try to allocate memory failed for module[%s]\n", module_name);
            goto MULTI_REQUEST_FAILED;
        }
        memset(cw_node, 0, sizeof(RTK_CW_KEY_REGION));
        strncpy(cw_node->module_name, module_name, CW_MODULE_NAME_LEN);
        list_add(&cw_node->node, &key_mm->cw_key_region_list);
    }
    for(i = 0; i < len; i++) {
        if (!test_bit(index_array[i], cw_node->map)) {
            cw_node->cw_use++;
            set_bit(index_array[i], key_mm->cw_map);
            set_bit(index_array[i], cw_node->map);
            CW_DBG("module[%s] request a cw[%d] sucess\n", module_name, index_array[i]);
        }
    }
    WRITE_UNLOCK(key_mm->cw_mm_lock, flags);
    return 0;

MULTI_REQUEST_FAILED:
    WRITE_UNLOCK(key_mm->cw_mm_lock, flags);
    return -1;

}


static int single_cpu_release_cw_by_module(RTK_CW_MANAGER *p_this, char *module_name)
{
    RTK_CW_KEY_REGION *cw_node = NULL;
    struct list_head *plist = NULL;
    unsigned long flags;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    if (module_name == NULL)
        return -1;

    CW_DBG("module[%s] send a release for its cws:\n", module_name);


    WRITE_LOCK(key_mm->cw_mm_lock, flags);
    list_for_each(plist, &key_mm->cw_key_region_list) {
        RTK_CW_KEY_REGION *tmp = list_entry(plist, RTK_CW_KEY_REGION, node);
        if (strcmp(tmp->module_name, module_name) == 0) {
            cw_node = tmp;
            break;
        }
    }
    if (cw_node != NULL) {
        int i = 0;
        for(i = 0; i < CW_AREA_LEN; i++) {
            if (test_bit(i, cw_node->map)) {
                clear_bit(i, key_mm->cw_map);
                clear_bit(i, cw_node->map);
                cw_node->cw_use--;
                CW_DBG("module[%s] release cw[%d] sucess\n", module_name, i);
            }
        }
        list_del(&cw_node->node);
        kfree(cw_node);
        cw_node = NULL;
    }
    WRITE_UNLOCK(key_mm->cw_mm_lock, flags);
    return 0;

}

static int single_cpu_release_cw(RTK_CW_MANAGER *p_this,
                                 char *module_name, UINT8 cw_index)
{
    RTK_CW_KEY_REGION *cw_node = NULL;
    struct list_head *plist = NULL;
    unsigned long flags;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    if(module_name == NULL || cw_index < 0 || cw_index >= CW_AREA_LEN)
        return -1;
    WRITE_LOCK(key_mm->cw_mm_lock, flags);
    list_for_each(plist, &key_mm->cw_key_region_list) {
        RTK_CW_KEY_REGION *tmp = list_entry(plist, RTK_CW_KEY_REGION, node);
        if (strcmp(tmp->module_name, module_name) == 0) {
            cw_node = tmp;
            break;
        }
    }

    CW_DBG("module[%s] send a release for cw[%d]\n", module_name, cw_index);

    if (test_bit(cw_index, key_mm->cw_map)) {
        if (cw_node != NULL && test_bit(cw_index, cw_node->map)) {
            clear_bit(cw_index, key_mm->cw_map);
            clear_bit(cw_index, cw_node->map);
            cw_node->cw_use--;
            CW_DBG("module[%s] release cw[%d] sucess\n", module_name, cw_index);
            if(cw_node->cw_use == 0) {
                list_del(&(cw_node->node));
                kfree(cw_node);
                cw_node = 0;
            }
        } else {
            CW_WARNING("module[%s] try to release a cw[%d] which was allocated to other module\n", module_name, cw_index);
            goto RELEASE_FAILED;
        }
    } else {
        CW_WARNING("module[%s] try to release a cw[%d] which has never been allocated\n", module_name, cw_index);
        goto RELEASE_FAILED;
    }
    WRITE_UNLOCK(key_mm->cw_mm_lock, flags);
    return 0;

RELEASE_FAILED:
    WRITE_UNLOCK(key_mm->cw_mm_lock, flags);
    return -1;

}


static int _single_cpu_cw_set_cw(RTK_CW_KEY_REGION_MM *key_mm,
                                 char *module_name, UINT8 cw_index, UINT8 *content, int len)
{
    RTK_CW_KEY_REGION *cw_node = NULL;
    int ret = 0;
    struct list_head *plist = NULL;
    unsigned long flags;
    if (module_name == NULL || cw_index < 0 || cw_index >= CW_AREA_LEN
        || content == NULL || len < 0)
        return -1;

    READ_LOCK(key_mm->cw_mm_lock, flags);

    list_for_each(plist, &key_mm->cw_key_region_list) {
        RTK_CW_KEY_REGION *tmp = list_entry(plist, RTK_CW_KEY_REGION, node);
        if (strcmp(tmp->module_name, module_name) == 0) {
            cw_node = tmp;
            break;
        }
    }

    if (test_bit(cw_index, key_mm->cw_map) && cw_node != NULL && test_bit(cw_index, cw_node->map)) {
        Set_CW(cw_index, content, len);
        if (set_cw_dbg_en) {
            int i = 0;
            char buf[64] = {0};
            snprintf(buf + strlen(buf), 64 - strlen(buf), "%s set cw[%d] = 0x", module_name, cw_index);
            for(i = len; i > 0; i--) {
                snprintf(buf + strlen(buf), 64 - strlen(buf), "%02x", content[i - 1]);
            }
            CW_INFO("%s\n", buf);
        }
        ret = 0;
    } else {
        if (set_cw_dbg_en) {
            char buf[64] = {0};
            snprintf(buf + strlen(buf), 64 - strlen(buf), "%s set cw[%d] fail", module_name, cw_index);
            CW_INFO("%s\n", buf);
            dump_stack();
        }
        ret = -1;
    }

    READ_UNLOCK(key_mm->cw_mm_lock, flags);
    return ret;
}


static int single_cpu_set_continous_cws(RTK_CW_MANAGER *p_this, char *module_name, UINT8 start_index, UINT8 *content, int len)
{
    int count = 0;
    int i = 0;
    int ret = -1;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    if(module_name == NULL || start_index < 0 || start_index >= CW_AREA_LEN
       || content == NULL || len <= 0)
        return ret;
    count = (len - 1) / TPK_CW_LENGTH + 1;
    if(start_index + count > CW_AREA_LEN)
        return -1;
    for(i = 0; i < count; i++) {
        int tmp_len = 0;
        if(i < count - 1)
            tmp_len = TPK_CW_LENGTH;
        else
            tmp_len = len - i * TPK_CW_LENGTH;
        ret = _single_cpu_cw_set_cw(key_mm, module_name, start_index, content, tmp_len);
        if(ret != 0)
            break;
        start_index++;
        content += tmp_len;
    }
    return ret;
}

static int single_cpu_set_uncontinous_cws(RTK_CW_MANAGER *p_this, char *module_name, UINT8 *index_array, int arr_len, UINT8 *content, int len)
{
    int count = 0;
    int i = 0;
    int ret = -1;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    if(module_name == NULL || index_array == NULL
       || arr_len <= 0 || content == NULL || len <= 0)
        return ret;
    count = (len - 1) / TPK_CW_LENGTH + 1;
    for(i = 0; i < count && i < arr_len; i++) {
        int tmp_len = 0;
        if(i < count - 1)
            tmp_len = TPK_CW_LENGTH;
        else
            tmp_len = len - i * TPK_CW_LENGTH;
        ret = _single_cpu_cw_set_cw(key_mm, module_name, index_array[i], content, tmp_len);
        if(ret != 0)
            break;
        content += tmp_len;
    }
    return ret;
}


static int _single_cpu_get_cw(RTK_CW_KEY_REGION_MM *key_mm, char *module_name, UINT8 cw_index, UINT8 *content, int len)
{
    RTK_CW_KEY_REGION *cw_node = NULL;
    int ret = 0;
    struct list_head *plist = NULL;
    unsigned long flags;
    if(module_name == NULL || cw_index < 0 || cw_index >= CW_AREA_LEN
       || content == NULL || len < 0)
        return -1;

    READ_LOCK(key_mm->cw_mm_lock, flags);

    list_for_each(plist, &key_mm->cw_key_region_list) {
        RTK_CW_KEY_REGION *tmp = list_entry(plist, RTK_CW_KEY_REGION, node);
        if(strcmp(tmp->module_name, module_name) == 0) {
            cw_node = tmp;
            break;
        }
    }

    if(test_bit(cw_index, key_mm->cw_map) && cw_node != NULL && test_bit(cw_index, cw_node->map)) {
        Get_CW(cw_index, content, len);
        if (get_cw_dbg_en) {
            int i = 0;
            char buf[64] = {0};
            snprintf(buf + strlen(buf), 64 - strlen(buf), "%s get cw[%d], content =0x", module_name, cw_index);
            for(i = len; i > 0; i--) {
                snprintf(buf + strlen(buf), 64 - strlen(buf), "%02x", content[i - 1]);
            }
            CW_INFO("%s\n", buf);
        }
        ret = 0;
    } else {
        if (get_cw_dbg_en) {
            char buf[64] = {0};
            snprintf(buf + strlen(buf), 64 - strlen(buf),  "%s get cw[%d] fail", module_name, cw_index);
            CW_INFO("%s\n", buf);
        }
        ret = -1;
    }
    READ_UNLOCK(key_mm->cw_mm_lock, flags);
    return ret;
}


static int single_cpu_get_continous_cws(RTK_CW_MANAGER *p_this, char *module_name, UINT8 start_index, UINT8 *content, int len)
{
    int count = 0;
    int i = 0;
    int ret = -1;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    if(module_name == NULL || start_index < 0 || start_index >= CW_AREA_LEN
       || content == NULL || len <= 0)
        return ret;
    count = (len - 1) / TPK_CW_LENGTH + 1;
    if(start_index + count > CW_AREA_LEN)
        return ret;
    for(i = 0; i < count; i++) {
        int tmp_len = 0;
        if(i < count - 1)
            tmp_len = TPK_CW_LENGTH;
        else
            tmp_len = len - i * TPK_CW_LENGTH;
        ret = _single_cpu_get_cw(key_mm, module_name, start_index, content, tmp_len);
        if(ret != 0)
            break;
        start_index++;
        content += tmp_len;
    }
    return ret;
}


static int single_cpu_get_uncontinous_cws(RTK_CW_MANAGER *p_this, char *module_name, UINT8 *index_array, int arr_len, UINT8 *content, int len)
{
    int count = 0;
    int i = 0;
    int ret = -1;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    if(module_name == NULL || index_array == NULL
       || arr_len <= 0 || content == NULL || len <= 0)
        return ret;
    count = (len - 1) / TPK_CW_LENGTH + 1;
    for(i = 0; i < count && i < arr_len; i++) {
        int tmp_len = 0;
        if(i < count - 1)
            tmp_len = TPK_CW_LENGTH;
        else
            tmp_len = len - i * TPK_CW_LENGTH;
        ret = _single_cpu_get_cw(key_mm, module_name, index_array[i], content, tmp_len);
        if(ret != 0)
            break;
        content += tmp_len;
    }
    return ret;
}


static int single_cpu_query_used_cws_by_module(RTK_CW_MANAGER *p_this, char *module_name, UINT8 *index_array, int len)
{
    int i = 0;
    int count = 0;
    RTK_CW_KEY_REGION *cw_node = NULL;
    struct list_head *plist = NULL;
    unsigned long flags;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    if (module_name == NULL || index_array == NULL || len <= 0)
        return -1;
    memset(index_array, 0, len);

    READ_LOCK(key_mm->cw_mm_lock, flags);
    list_for_each(plist, &key_mm->cw_key_region_list) {
        RTK_CW_KEY_REGION *tmp = list_entry(plist, RTK_CW_KEY_REGION, node);
        if (strcmp(tmp->module_name, module_name) == 0) {
            cw_node = tmp;
            break;
        }
    }
    if(cw_node != NULL) {
        for(i = 0; i < CW_AREA_LEN && count < len; i++) {
            if(test_bit(i, cw_node->map)) {
                index_array[count++] = i;
            }

        }
    }
    READ_UNLOCK(key_mm->cw_mm_lock, flags);
    return count;
}



static int single_cpu_query_free_cws(RTK_CW_MANAGER *p_this, UINT8 *free_index_array, int len)
{
    int i = 0;
    int count = 0;
    unsigned long flags;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    if (free_index_array == NULL || len <= 0)
        return -1;
    memset(free_index_array, 0, len);

    READ_LOCK(key_mm->cw_mm_lock, flags);
    for(i = 0; i < CW_AREA_LEN && count < len; i++) {
        if(!test_bit(i, key_mm->cw_map)) {
            free_index_array[count++] = i;
        }

    }
    READ_UNLOCK(key_mm->cw_mm_lock, flags);
    return count;
}


static int single_cpu_dump_cws_status(RTK_CW_MANAGER *p_this, char *buf)
{
    struct list_head *plist = NULL;
    unsigned long flags;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    if(buf == NULL)
        return 0;
    buf[0] = 0;
    sprintf(buf + strlen(buf), "%s", "******The state of the CW space******\n");
    READ_LOCK(key_mm->cw_mm_lock, flags);
    if (!list_empty(&key_mm->cw_key_region_list)) {
        int i = 0;
        sprintf(buf + strlen(buf), "[%s]: ", "ALL");
        for(i = 0; i < CW_AREA_LEN; i++) {
            if(test_bit(i, key_mm->cw_map)) {
                sprintf(buf + strlen(buf), "%d ", i);
            }
        }
        sprintf(buf + strlen(buf), "%s", "\n");
    }
    list_for_each(plist, &key_mm->cw_key_region_list) {
        int i = 0;
        RTK_CW_KEY_REGION *tmp = list_entry(plist, RTK_CW_KEY_REGION, node);
        sprintf(buf + strlen(buf), "[%s]: ", tmp->module_name);
        for(i = 0; i < CW_AREA_LEN; i++) {
            if(test_bit(i, tmp->map)) {
                sprintf(buf + strlen(buf), "%d ", i);
            }
        }
        sprintf(buf + strlen(buf), "%s", "\n");

    }
    READ_UNLOCK(key_mm->cw_mm_lock, flags);
    return strlen(buf);
}



static int single_cpu_cw_init(RTK_CW_MANAGER *p_this)
{
    RTK_CW_KEY_REGION_MM *key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    INIT_LOCK(key_mm->cw_mm_lock);
    INIT_LIST_HEAD(&key_mm->cw_key_region_list);
    memset(key_mm->cw_map, 0, sizeof(unsigned long) * BITMAP_LEN);
    return 0;
}

static int single_cpu_cw_deinit(RTK_CW_MANAGER *p_this)
{
    struct list_head *cur_node = NULL;
    struct list_head *prev_node = NULL;
    unsigned long flags;
    RTK_CW_KEY_REGION_MM *key_mm = NULL;
    if(p_this == NULL || p_this->private == NULL)
        return -1;
    key_mm = (RTK_CW_KEY_REGION_MM *)p_this->private;
    WRITE_LOCK(key_mm->cw_mm_lock, flags);
    list_for_each_safe(cur_node, prev_node, &key_mm->cw_key_region_list) {
        RTK_CW_KEY_REGION *tmp_struct = NULL;
        list_del(cur_node);
        tmp_struct = list_entry(cur_node, RTK_CW_KEY_REGION, node);
        kfree(tmp_struct);
    }
    WRITE_UNLOCK(key_mm->cw_mm_lock, flags);
    return 0;
}

static RTK_CW_KEY_REGION_MM cw_key_mm;

RTK_CW_MANAGER  single_cpu_cw_manager = {
    .private = &cw_key_mm,
    .init = single_cpu_cw_init,
    .deinit = single_cpu_cw_deinit,
    .request_cws = single_cpu_request_cw_array,
    .release_cws_by_module = single_cpu_release_cw_by_module,
    .release_cw = single_cpu_release_cw,
    .set_continous_cws = single_cpu_set_continous_cws,
    .set_uncontinous_cws = single_cpu_set_uncontinous_cws,
    .get_continous_cws = single_cpu_get_continous_cws,
    .get_uncontinous_cws = single_cpu_get_uncontinous_cws,
    .query_free_cws = single_cpu_query_free_cws,
    .query_used_cws_by_module = single_cpu_query_used_cws_by_module,
    .dump_cws_status = single_cpu_dump_cws_status,
};



/*-----------------------------------------------------------------------------
* Func : rtk_cw_module_init
*
* Desc : init modeule
*
* Parm :
*
* Retn : 0:sucess; -1:faile.
*-----------------------------------------------------------------------------*/

static int __init rtk_single_cpu_cw_module_init(void)
{
    rtk_cw_register_cw_manager(&single_cpu_cw_manager);
    CW_INFO("CW module init sucessed\n");
    return 0;
}

/*-----------------------------------------------------------------------------
* Func : rtk_cw_module_exit
*
* Desc : exit modeule
*
* Parm :
*
* Retn :
*-----------------------------------------------------------------------------*/

static void __exit rtk_single_cpu_cw_module_exit(void)
{
    rtk_cw_unregister_cw_manager(&single_cpu_cw_manager);
}

subsys_initcall(rtk_single_cpu_cw_module_init);
module_exit(rtk_single_cpu_cw_module_exit);
MODULE_AUTHOR("liangliang song, Realtek Semiconductor");
MODULE_LICENSE("GPL");

