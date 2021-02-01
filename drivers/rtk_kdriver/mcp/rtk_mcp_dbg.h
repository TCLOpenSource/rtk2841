#ifndef __MCP_DBG__
#define __MCP_DBG__
#include <mach/rtk_log.h>
#define TAG_NAME "MCP"
/************************************************************************
 *  rtk log define
 ************************************************************************/
#if 1
#define mcp_debug(fmt, args...)\
        rtd_printk( KERN_DEBUG , TAG_NAME, fmt , ## args)
#define mcp_info(fmt, args...)\
	    rtd_printk( KERN_INFO , TAG_NAME, fmt , ## args)
#else
#define mcp_debug(fmt, args...)
#define mcp_info(fmt, args...)
#endif

#define mcp_notice(fmt, args...)\
		rtd_printk( KERN_NOTICE , TAG_NAME, fmt , ## args)
#define mcp_warning(fmt, args...)\
		rtd_printk( KERN_WARNING , TAG_NAME, fmt , ## args)
#define mcp_err(fmt, args...)\
		rtd_printk( KERN_ERR , TAG_NAME, fmt , ## args)

#endif //__MCP_DBG__
