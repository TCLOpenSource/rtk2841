#ifndef __RTK_RCP_DBG_H__
#define __RTK_RCP_DBG_H__

#include <mach/rtk_log.h>

#define RCP_DEBUG(fmt, args...)             rtd_printk(KERN_DEBUG , "RCP", fmt , ## args)
#define RCP_INFO(fmt, args...)                rtd_printk(KERN_INFO , "RCP", fmt , ## args)
#define RCP_NOTICE(fmt, args...)            rtd_printk(KERN_NOTICE , "RCP", fmt , ## args)
#define RCP_WARNING(fmt, args...)         rtd_printk(KERN_WARNING , "RCP", fmt , ## args)
#define RCP_ERR(fmt, args...)                  rtd_printk(KERN_ERR , "RCP", fmt , ## args)

void  rtk_rcp_dump_mem(unsigned char* data, unsigned int len);
#define rtk_rcp_dump_data_with_text(data, len ,fmt, args...)\
do {\
                RCP_DEBUG(fmt, ## args);\
                rtk_rcp_dump_mem(data, len);\
}while(0)


#endif
