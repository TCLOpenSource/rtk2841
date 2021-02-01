#ifndef _RTK_VDEC_INTERNAL_H_
#define _RTK_VDEC_INTERNAL_H_

#define RTKVDEC_DUMMY_VBM_SIZE 0xB801A61C

#define RTKVDEC_MAX_VMM_MEM_NUM 3
#define S_OK    	0x10000000
#define S_FAIL  	0x10000000
#define FILE_NAME_SIZE 50

#define RTKVDEC_MAX_VEPROT_MEM_NUM 10
#define RTKVDEC_VEPROT_BLOCK_SIZE 0x80000

typedef struct _tagRingBufferHeader {
	unsigned long magic;   /*Magic number*/
	unsigned long beginAddr;
	unsigned long size;
	unsigned long bufferID;  /* RINGBUFFER_TYPE, choose a type from RINGBUFFER_TYPE*/

	unsigned long  writePtr;
	unsigned long  numOfReadPtr;
	unsigned long  reserve2;  /*Reserve for Red Zone*/
	unsigned long  reserve3;  /*Reserve for Red Zone*/

	unsigned long readPtr[4];

	long          fileOffset ;
	long          requestedFileOffset ;
	long          fileSize ;

	long          bSeekable ;  /* Can't be sought if data is streamed by HTTP */

} RINGBUFFER_HEADER ;

typedef struct VDEC_VEPROT_MEM_LIST {
       unsigned int mask;
       unsigned long addr ;
       unsigned int size ;
} VDEC_VEPROT_MEM_LIST;

typedef struct VDEC_DBG_STRUCT {
	unsigned char file_name[FILE_NAME_SIZE];    /* debug log file place & name */
	unsigned int  mem_size; 	/* debug memory size */
	unsigned char enable ;
} VDEC_DBG_STRUCT;

struct file *file_open(const char *path, int flags, int rights)
{
	struct file *filp = NULL;
	mm_segment_t oldfs;
	int err = 0;

	oldfs = get_fs();
	set_fs(get_ds());

	filp = filp_open(path, flags, rights);
	set_fs(oldfs);

	if (IS_ERR(filp)) {
		err = PTR_ERR(filp);
		return NULL;
	}

	return filp;
}

void file_close(struct file *file)
{
	filp_close(file, NULL);
}

int file_read(struct file *file, unsigned long long offset, unsigned char *data, unsigned int size)
{
	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());

	ret = vfs_read(file, data, size, &offset);
	set_fs(oldfs);

	return ret;
}

int file_write(struct file *file, unsigned long long offset, unsigned char *data, unsigned int size)
{
	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());
	ret = vfs_write(file, data, size, &offset);
	set_fs(oldfs);

	return ret;
}

int file_sync(struct file *file)
{
	vfs_fsync(file, 0);
	return 0;
}

void rtkvdec_user_alloc_query(RINGBUFFER_HEADER *, unsigned int, unsigned int, unsigned long) ;

#endif
