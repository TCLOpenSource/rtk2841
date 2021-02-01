#ifndef __TP_DRV_SECTION_H__
#define __TP_DRV_SECTION_H__

#include <base_types.h>



#ifndef TRUE
#define TRUE            1
#endif

#ifndef FALSE
#define FALSE           0
#endif

#ifndef NULL
#define NULL            ((void *)0)
#endif

#define SEC_FILTER_BUFFER_NUM       (128)
#define SEC_FILTER_BUFFER_EACH_SIZE (4096)
#define SEC_FILTER_BUFFER_SIZE      (SEC_FILTER_BUFFER_EACH_SIZE*SEC_FILTER_BUFFER_NUM)

typedef struct {
        BOOL      bOccupied;
        BOOL      bCompleted;
        UADDRESS    u32VirAddr;
        UADDRESS    u32PhyAddr;
        UINT32    u32Size;
        void*     pContext;      /* ((tp_id << 8) | secfIndex) to release buffer */
        TPK_SEC_DATA_T SecData;
} stSecMap;

typedef struct {
        UINT8       aSecBuf[SEC_FILTER_BUFFER_EACH_SIZE * SEC_FILTER_BUFFER_NUM];
        stSecMap    SecMap[SEC_FILTER_BUFFER_NUM];
        UINT32      u32SecBufCnt;
} stSecBufData;

INT32 TPVerify_CreateSectionBuffer(void);
INT32 TPVerify_ReleaseSectionBuffer(void);
INT32 TPVerify_GetSectionData(OUT BOOL* pbIsNew, OUT TPK_SEC_DATA_T* pSec, OUT void* pBuf, OUT UINT32* pHandleID);
INT32 TPVerify_AddSectionFilter(IN UINT8 tp_id, IN  TPK_SEC_FILTER_PARAM_T Param, IN void* file_handle, OUT void** ppSec_handle);

long  TPVerify_ioctl(struct file* file, unsigned int cmd, unsigned long arg);

void TPVerify_ModuleTest(char *pattern_path);

#endif /* __TP_DRV_SECTION_H__ */

