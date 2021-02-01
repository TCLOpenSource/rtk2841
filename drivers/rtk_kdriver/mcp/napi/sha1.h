#ifndef __SHA1_H__
#define __SHA1_H__

#include <rtk_kdriver/rtk_mcp.h>

typedef struct {    
    mcp_buff*               tmp;
    unsigned long long      byte_count;
    unsigned char           hash[20];
}SHA1_CTX;

#endif // __SHA1_H__ 
