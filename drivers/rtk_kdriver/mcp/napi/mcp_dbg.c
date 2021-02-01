#include <linux/kernel.h>
#include "mcp/rtk_mcp_dbg.h"


/*---------------------------------------------------------------------- 
 * Func : _dump_data 
 *
 * Desc : dump data in memory
 *
 * Parm : data : start address of data
 *        len  : length of data
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/ 
void mcp_dump_data(unsigned char* data, unsigned int len)
{
    int i;               
        
    for (i=0; i<len; i++)
    {
        if ((i & 0xF)==0)
            mcp_debug("\n %04x | ", i);
        mcp_debug("%02x ", data[i]);
    }    
}
