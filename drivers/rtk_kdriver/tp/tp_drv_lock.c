/******************************************************************************
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author eva.lin@realtek.com
 *
 *****************************************************************************/
#include <linux/list.h>
#include <linux/slab.h>


#include <tp/tp_drv_lock.h>
#include <tp/tp_drv_global.h>
#include <tp/tp_dbg.h>


INT32 Tp_Locker_SetLockFunction(char myMutexName[TP_MUTEX_NAME_LEN], const char * myFunName)
{
        struct list_head * ilist = NULL;
        TP_DRV_MUTEXLOCK_T * p_this = NULL;
        TP_DRV_MUTEXLOCK_T * p_node = NULL;
        TP_DRV_MUTEXFUNNAME_T* p_funCallStack_this = NULL;

        _tp_mutexlocklist_lock();

        // eva debug
        if ( strcmp(myMutexName, "_tp_lock") == 0 && strcmp(myFunName, "Tp_Get_Buffer") == 0) {
                TP_ERROR("HI EVA\n");
                BUG();
                //dump_stack();
        }

        /* allocate new node for this mutex */
        p_this = (TP_DRV_MUTEXLOCK_T*)kmalloc(sizeof(TP_DRV_MUTEXLOCK_T), GFP_KERNEL);
        p_funCallStack_this = (TP_DRV_MUTEXFUNNAME_T*)kmalloc(sizeof(TP_DRV_MUTEXFUNNAME_T), GFP_KERNEL);
        if (p_this && p_funCallStack_this) {
                memset(p_this, 0, sizeof(TP_DRV_MUTEXLOCK_T));
                memset(p_funCallStack_this, 0, sizeof(TP_DRV_MUTEXFUNNAME_T));

                INIT_LIST_HEAD(&p_this->list);
                INIT_LIST_HEAD(&p_funCallStack_this->funName_list);

                strncpy(p_this->name, myMutexName, TP_MUTEX_NAME_LEN);
                strncpy(p_funCallStack_this->funName, myFunName, TP_FUN_NAME_LEN);
                p_funCallStack_this->lock = 1;
        } else {
                if (!p_this)
                        TP_ERROR("Can not allocate memory for TP_DRV_MUTEXLOCK_T (structure size=%d)\n", sizeof(TP_DRV_MUTEXLOCK_T));
                if (!p_funCallStack_this)
                        TP_ERROR("Can not allocate memory for TP_DRV_MUTEXFUNNAME_T (structure size=%d)\n", sizeof(TP_DRV_MUTEXFUNNAME_T));

                if (p_this)
                        kfree(p_this);
                if (p_funCallStack_this)
                        kfree(p_funCallStack_this);

                _tp_mutexlocklist_unlock();
                return -1;
        }

        if ( pTp_MutexLockList == NULL ) {
                pTp_MutexLockList = p_this;
                pTp_MutexLockList->funCallStackHead = p_funCallStack_this;
        } else {
                /* find mutex node */
                ilist = NULL;
                list_for_each(ilist, &pTp_MutexLockList->list) {
                        TP_DRV_MUTEXLOCK_T* tmp = list_entry(ilist, TP_DRV_MUTEXLOCK_T, list);
                        if (strcmp(tmp->name, myMutexName) == 0) {
                                p_node = tmp;
                                break;
                        }
                }

                /* could not find the mutex in mutex lock list */
                if (p_node == NULL) {
                        p_this->funCallStackHead = p_funCallStack_this;
                        list_add(&p_this->list, &pTp_MutexLockList->list);

                        //TP_WARNING("New a mutex node\n");
                } else {
                        UINT32 cnt_fn_call_stack = 0;
                        TP_DRV_MUTEXFUNNAME_T* tmpFun = NULL;

                        /* no need, so free it */
                        kfree(p_this);
                        p_this = NULL;

                        /* count the fun call stack in this mutex node */
                        ilist = NULL;
                        list_for_each(ilist, &p_node->funCallStackHead->funName_list) {
                                tmpFun = list_entry(ilist, TP_DRV_MUTEXFUNNAME_T, funName_list);
                                cnt_fn_call_stack++;
                        }

                        if (cnt_fn_call_stack > TP_MUTEX_DBG_NUM_FUN_CALL) {
                                TP_ERROR("The func call stack is more than %d(%u)\n", TP_MUTEX_DBG_NUM_FUN_CALL, cnt_fn_call_stack);

                                list_del(&tmpFun->funName_list);
                                kfree(tmpFun);

                                _tp_mutexlocklist_unlock();
                                // KWarning: checked ok by thomas_chou@realtek.com
                                return -1;
                        } else if (cnt_fn_call_stack == TP_MUTEX_DBG_NUM_FUN_CALL ) {
                                ilist = NULL;
                                //TP_DRV_MUTEXFUNNAME_T * lastFun = list_last_entry(ilist, TP_DRV_MUTEXFUNNAME_T, funName_list);
                                //list_del(&lastFun->funName_list);
                                //kfree(lastFun);

                                list_del(&tmpFun->funName_list);
                                kfree(tmpFun);
                        } else {
                                //TP_WARNING("New a fun call node\n");
                        }

                        list_add(&p_funCallStack_this->funName_list, &p_node->funCallStackHead->funName_list);
                        // TP_WARNING("Add node, %s %s\n", p_node->name, p_funCallStack_this->funName);
                }
        }

        _tp_mutexlocklist_unlock();
        // KWarning: checked ok by thomas_chou@realtek.com
        return 0;
}

INT32 Tp_Locker_ClearLockFunction(char myMutexName[TP_MUTEX_NAME_LEN], const char * myFunName)
{
        struct list_head *ilist = NULL;
        TP_DRV_MUTEXLOCK_T* p_node = NULL;

        _tp_mutexlocklist_lock();

        /* find mutex node */
        list_for_each(ilist, &pTp_MutexLockList->list) {
                TP_DRV_MUTEXLOCK_T* tmp = list_entry(ilist, TP_DRV_MUTEXLOCK_T, list);
                if (strcmp(tmp->name, myMutexName) == 0) {
                        p_node = tmp;
                        break;
                }
        }

        /* could not find the mutex */
        if (p_node == NULL) {
                TP_ERROR("Could not found the node of %s %s\n", myMutexName, myFunName);
                _tp_mutexlocklist_unlock();
                return -1;
        } else {
                if (p_node->funCallStackHead != NULL) {
                        ilist = NULL;

                        list_for_each(ilist, &p_node->funCallStackHead->funName_list) {
                                TP_DRV_MUTEXFUNNAME_T* tmpFun = list_entry(ilist, TP_DRV_MUTEXFUNNAME_T, funName_list);
                                if (strcmp(tmpFun->funName, myFunName) == 0 && tmpFun->lock == 1) {
                                        tmpFun->lock = 0;
                                        break;
                                }
                        }
                        _tp_mutexlocklist_unlock();
                        return 0;
                } else {
                        TP_ERROR("funCallStackHead is null\n");
                        _tp_mutexlocklist_unlock();
                        return -1;
                }

        }

}



