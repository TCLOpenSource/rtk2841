#ifndef __TP_DRV_LOCK_H__
#define __TP_DRV_LOCK_H__

#include "base_types.h"

#define TP_MUTEX_NAME_LEN 16
#define TP_FUN_NAME_LEN   30
#define TP_MUTEX_DBG_NUM_FUN_CALL 10


/* strcut to record all mutex lock in TP driver */
typedef struct {
        char funName[TP_FUN_NAME_LEN];
        bool lock;      /* lock:1, unlock:0 */
        struct list_head funName_list;
} TP_DRV_MUTEXFUNNAME_T;

typedef struct {
        char name[TP_MUTEX_NAME_LEN];
        TP_DRV_MUTEXFUNNAME_T* funCallStackHead;
        struct list_head list;
} TP_DRV_MUTEXLOCK_T;


#if 1
INT32 Tp_Locker_SetLockFunction(char myMutexName[TP_MUTEX_NAME_LEN], const char * myFunName);
INT32 Tp_Locker_ClearLockFunction(char myMutexName[TP_MUTEX_NAME_LEN], const char * myFunName);

#endif

#endif      /* __TP_DRV_LOCK_H__ */
