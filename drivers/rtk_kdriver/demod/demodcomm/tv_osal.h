// TV Frontend OSAL Driver
//

#ifndef __TV_OSAL_H__
#define __TV_OSAL_H__

//#include "OSAL.h"
#include "rtk_tv_fe_types.h"

#ifdef __cplusplus
extern "C" {
#endif

void tv_osal_msleep_interruptible(unsigned long ms);
void tv_osal_msleep(unsigned long ms);
void tv_osal_usleep(unsigned long us);

unsigned long tv_osal_time(void);

void* tv_osal_malloc(unsigned long size);
void tv_osal_free(void *ptr);

typedef struct mutex   tv_mutex;


void tv_mutex_create(tv_mutex* p_mutex);
void tv_mutex_destroy(tv_mutex* p_mutex);
void tv_mutex_lock(tv_mutex* p_mutex);
void tv_mutex_unlock(tv_mutex* p_mutex);

#ifdef __cplusplus
}
#endif

#endif //__TV_OSAL_H__
