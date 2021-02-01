#ifndef __RTK_MCP_DEV_H__
#define __RTK_MCP_DEV_H__
#include <rtk_kdriver/rtk_mcp.h>

#define MCP_IOCTL_DO_COMMAND    0x70000001
#define MCP_IOCTL_TEST_AES_H    0x71000001

typedef struct 
{
    unsigned int     	p_desc;
    unsigned int 		n_desc;
}compat_mcp_desc_set;

typedef struct 
{
    mcp_desc*     	    p_desc;
    unsigned int 		n_desc;
}mcp_desc_set;

#endif