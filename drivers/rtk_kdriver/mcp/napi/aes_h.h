#ifndef __AES_H__H__
#define __AES_H__H__

#include <rtk_kdriver/rtk_mcp.h>
#include "mcp/rtk_mcp_buff.h"

typedef struct {
    mcp_buff*            	tmp;
    unsigned long long  	byte_count;
    unsigned char        	hash[16];
}AES_H_CTX;

#endif // __AES_H__H__
