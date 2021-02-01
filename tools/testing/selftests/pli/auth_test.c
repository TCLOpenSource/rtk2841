#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>

#define STR_LENGTH	32
typedef struct {
	unsigned long           size;
	unsigned long           flag;
	char			str[STR_LENGTH];
} mem_alloc_struct;

typedef struct {
	unsigned long           addr;
	unsigned long           size;
} mem_region_struct;

	#define AUTH_IOC_MAGIC	'k'

#define DEF_MEM_SIZE		0x10000000    //PLI cache/non-cache region size
#define DEF_MAP_SIZE		0x20000000    //DEF_MAP_ADDR + DEF_MAP_SIZE = rbus mapping start 

#define GFP_DCU1                        0x00000001
#define GFP_DCU2                        0x00000002
#define GFP_DCU1_FIRST		0x00000004
#define GFP_DCU2_FIRST		0x00000008

#define AUTH_IOCQ_MAP                    _IOW(AUTH_IOC_MAGIC, 1, AUTH_STR)
#define AUTH_IOCQ_ALLOC                  _IOW(AUTH_IOC_MAGIC, 2, mem_alloc_struct)
#define AUTH_IOCQ_FREE                   _IO(AUTH_IOC_MAGIC, 3)
#define AUTH_IOCQ_FREEALL                _IO(AUTH_IOC_MAGIC, 4)
#define AUTH_IOCQ_LISTALL                _IO(AUTH_IOC_MAGIC, 5)
#define AUTH_IOCS_FLUSHVIRT              _IOW(AUTH_IOC_MAGIC, 6, mem_region_struct)
#define AUTH_IOCS_FLUSHPHYS              _IOW(AUTH_IOC_MAGIC, 7, mem_region_struct)
#define AUTH_IOCQ_ALLOCAV                _IOW(AUTH_IOC_MAGIC, 8, mem_alloc_struct)
#define AUTH_IOCQ_FREEAV                 _IO(AUTH_IOC_MAGIC, 9)
#define AUTH_IOCH_DUMPMEM                _IO(AUTH_IOC_MAGIC, 10)
#define AUTH_IOCQ_DCUSIZE       		_IO(AUTH_IOC_MAGIC, 20)

/* Global variables for the attributes of caches */
unsigned long L1_lsize=0, L1_sets=0, L1_ways=0, L1_csize=0;
unsigned long L2_lsize=0, L2_sets=0, L2_ways=0, L2_csize=0;

	typedef	char AUTH_STR[20];

	const char *dvr_auth = "Realtek DVR";
	static int			fd = 0;
	int			start_addr = 0;

void cache_init()
{
#if 0

	unsigned long config1, config2;

	/* Read cache attributes */
	printf("[%s,%d] L1_lsize=%d, L1_sets=%d, L1_ways=%d, L1_csize=%08x\n", __FILE__, __LINE__,
		L1_lsize, L1_sets, L1_ways, L1_csize);
#endif
}

/* 0: success, 1: fail */
int	pli_init()
{
	if (fd != 0) {
		printf("[Warning]Pli has been init.\n");
		return 0;
	}

	if(!L1_lsize)
		cache_init();

    fflush(stdout);
    fd = open("/dev/auth", O_RDONLY);
    if (fd < 0) {
        printf("can't open device file...\n");
        return 1;
    }

    if (fcntl(fd, F_SETFD, 1) == -1) {
		printf("Pli fcntl F_SETFD errno=%d\n", errno);
		return 1;
	}

	start_addr = ioctl(fd, AUTH_IOCQ_MAP, dvr_auth);
    if (start_addr)
        return 0;
    else
        return 1;

}

int     pli_close()
{
	int ret;

	ret = close(fd);
	fd = 0;

	return ret;
}

void*   pli_allocContinuousMemorySpecific(size_t size, char** nonCachedAddr, unsigned long *phyAddr, int flag)
{
    #ifdef DEBUG_MODE
 	alloc_record *tmp;
	int cpu = size & CPU_MASK;
    #endif

    size &= 0x0fffffff;
	mem_alloc_struct alloc;
	char *ptr;
	char mstr[STR_LENGTH];

	memset(&alloc,0,sizeof(mem_alloc_struct));
	mstr[0] = '\0';
	if (flag == GFP_DCU1) sprintf(mstr, "%s", "DCU1");
	if (flag == GFP_DCU2) sprintf(mstr, "%s", "DCU2");
	#ifdef DEBUG_MODE
	if (cpu == AUDIO_FLAG) sprintf(mstr, "%s%s", mstr, ", AUDIO");
	if (cpu == VIDEO_FLAG) sprintf(mstr, "%s%s", mstr, ", VIDEO");
	#endif
	strncpy(alloc.str, mstr, STR_LENGTH);
	alloc.str[STR_LENGTH-1] = '\0';
	alloc.size = size;
	alloc.flag = flag;
	ptr = (char *)ioctl(fd, AUTH_IOCQ_ALLOC, &alloc);
	if (!ptr) {
		if (nonCachedAddr)
			*nonCachedAddr = 0;
		if (phyAddr)
			*phyAddr = 0;
	} else {
		if (nonCachedAddr)
			*nonCachedAddr = (char *)(ptr+DEF_MEM_SIZE);
		if (phyAddr)
			*phyAddr = *(unsigned long *)(ptr+DEF_MEM_SIZE);
	}

    #ifdef DEBUG_MODE
	if (ptr)
    {
        tmp = (alloc_record *)malloc(sizeof(alloc_record));
       	if (NULL == tmp) {
					printf("[%s:%d] alloc memory fail\n", __FILE__, __LINE__);
					return 0;
	 			}
        tmp->addr = (int)ptr;
        tmp->flag = cpu;
        tmp->requested_size = (int)size;
        tmp->allocated_size = (int)size;
        char str[32];
        str[0]='\0';
        if (flag == GFP_DCU1) sprintf(str, "%s", "DCU1");
        if (flag == GFP_DCU2) sprintf(str, "%s", "DCU2");
        if (cpu == AUDIO_FLAG) sprintf(str, "%s%s", str, ", AUDIO");
        if (cpu == VIDEO_FLAG) sprintf(str, "%s%s", str, ", VIDEO");
        strncpy(tmp->mesg, str, MESG_LENGTH);
        tmp->mesg[MESG_LENGTH-1] = '\0';
        pthread_mutex_lock(&record_mutex);
        tmp->next = record_pointer;
        record_pointer = tmp;
        total_size += tmp->requested_size;
        alloc_size += tmp->allocated_size;
        if (cpu == AUDIO_FLAG)
            alloc_size_a += tmp->allocated_size;
        else if (cpu == VIDEO_FLAG)
            alloc_size_v += tmp->allocated_size;
#ifdef ENABLE_DTV_PROXY
        else if (cpu == KCPU_FLAG)
            alloc_size_k += tmp->allocated_size;
#endif
        else
            alloc_size_s += tmp->allocated_size;
        pthread_mutex_unlock(&record_mutex);
    }
    #endif

	return ptr;
}

#ifdef	DEBUG_MODE
void    pli_freeContinuousMemoryMesgSpecific(char *str, void *ptr)
#else
void    pli_freeContinuousMemorySpecific(void *ptr)
#endif
{
	int tmp = (int)ptr;


	if ((tmp >= start_addr) && (tmp < start_addr+DEF_MEM_SIZE)) {

#ifdef KERNEL_2_6_34
	} else if ((tmp >= start_addr+DEF_MEM_SIZE) && (tmp < start_addr+DEF_MEM_SIZE*2)) {
		tmp = tmp-DEF_MEM_SIZE;
#else
	} else if ((tmp >= start_addr+DEF_MEM_SIZE*2) && (tmp < start_addr+DEF_MEM_SIZE*3)) {
		tmp = tmp-DEF_MEM_SIZE*2;
#endif
	} else {
		void *array[10];
		size_t size;

		printf("error in pli_freeContinuousMemory()...\n");

		size = backtrace(array, 10);
		backtrace_symbols_fd(array, size, STDERR_FILENO);
		return;
	}

#ifdef PLI_MEM_DEBUG_INFO
        printf("[PLI_free][CACHE]:address:0x%.8x\n",ptr);
#endif
#ifdef USE_MEM_CACHE
	int i;
	for ( i=0; i< MEM_CACHE_SIZE; i++){
	  //printf("cached ptr[%d] = 0x%x, size = %d\n",i,(unsigned int) pli_gcache[i].virAddress, pli_gcache[i].size);
	  if (pli_cache[i].virAddress == (void*) tmp){ // always free cached address
		if (pli_cache[i].size < 0) {
			printf("FATAL::free the same pli memory twice...\n");
			//abort();
		}
		else {
		  pli_cache[i].size = - pli_cache[i].size;
		}
//	        printf("free [%d] address 0x%x, size = %d to Cache\n", i, (int)(pli_cache[i].virAddress), pli_cache[i].size);
		return;
	  }
	}
	//printf("Cannot find 0x%x in Cache when freeing pli cache!!!!!!!!!!!!!!\n", (unsigned int) ptr);
#endif

#ifdef	DEBUG_MODE
        if (!removeRecord((int)tmp)) {
                printf("error in removeRecord: %s...\n", str);
		//assert(0);
        }
#endif

#ifdef USE_COMPACT_MEMORY
	if (PliMemMgr_FreeDivxSubtitle(ptr) == true)
		return;
	if (PliMemMgr_FreeCompSubtitle(ptr) == true)
		return;
#endif
	ioctl(fd, AUTH_IOCQ_FREE, tmp);



}

int main(int argc, char* argv[])
{
	int arg = 0, arg1 = 0;

	if (argc <= 1) {
		printf("please set arguments, 1:alloc, 2:free, 3:access\n");
		return 0;
	}

	arg = atoi(argv[1]);
	if (argc > 2) {
		printf("argc=%d\n", argc);
		arg1 = atoi(argv[2]);
	}

	if (pli_init()) {
		printf("error pli_init\n");
		return 0;
	}

	if (arg == 1) {
		printf("alloc\n");
		char *CachedAddr, *nonCachedAddr;
		unsigned long phyAddr;
		CachedAddr = pli_allocContinuousMemorySpecific(4*1024*1024, &nonCachedAddr, &phyAddr, GFP_DCU1);
		printf("CachedAddr=%x, nonCachedAddr=%x, phy=%lx\n", CachedAddr, nonCachedAddr, phyAddr);

#if 1
		if (arg1 == 5) {
			printf("access\n");
			memset(CachedAddr, 0x5a5a5a5a, sizeof(int) * 4);
//			*(int *)nonCachedAddr = 0x5a5a5a5a;
//			*((int *)nonCachedAddr+1) = 0xdeadbeef;
//			*((int *)nonCachedAddr+2) = 0xcafedead;
//			*((int *)nonCachedAddr+3) = 0x6b6b6b6b;
		}
#endif

                printf("sleep 6 secs ...\n");
                sleep(6);

                pli_freeContinuousMemorySpecific((void *)CachedAddr);

	}

	if (arg == 2) {
		printf("free nothing\n");
	}

	if (arg == 3) {
		printf("access nothing\n");
	}

	pli_close();

	return 0;
}
