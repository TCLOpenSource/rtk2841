#ifndef OSD_DUMP_AGENT
#define OSD_DUMP_AGENT
//#include "dolbyvisionEDR_export.h"

typedef enum
{
	DVMEM_FREE=0,
	DVMEM_NEED_DUMP,
	DVMEM_BUSY_DUMP,
	DVMEM_DONE_DUMP,
	DVMEM_WAIT_DUMP,
	DVMEM_ERROR
}OSD_DMEM_STATUS;

typedef struct OSD_DUMP_MEM_INFO_T{
	unsigned int dst_phyaddr;
	unsigned char* viraddr;
	OSD_DMEM_STATUS status;
	char fname[128];
	char fnamebase[128];
	unsigned int x;
	unsigned int y;
	unsigned int w;
	unsigned int h;
	unsigned int pitch;
	unsigned int src_phyaddr;
	unsigned int fmt;
} osd_dmem_info;

typedef struct OSD_DUMP_POOL_INFO_T{
	unsigned int pool_size; /*aka surface, how manay surface that we need*/
	unsigned int x;
	unsigned int y;
	unsigned int w;
	unsigned int h;
	unsigned int pitch;
	char fnamebase[128];
	OSD_DMEM_STATUS status;
} osd_dmem_pool_info;


int osd_deme_write_file(osd_dmem_info* p);
int osd_deme_cpy(osd_dmem_info* src);
int osd_deme_stch_cpy(osd_dmem_info* src,osd_dmem_info* dst);
#endif
