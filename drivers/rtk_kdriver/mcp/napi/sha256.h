#ifndef __SHA256_H__
#define __SHA256_H__

#include <rtk_kdriver/rtk_mcp.h>


typedef struct {    
    mcp_buff*               tmp;
    unsigned long long      byte_count;
    unsigned char           hash[SHA256_DIGEST_SIZE];
}SHA256_CTX;

#endif // __SHA256_H__ 
