#ifndef RTK_SPI_NAND_H
#define RTK_SPI_NAND_H
#include <base_types.h>
#include <asm/io.h>
#include <linux/mtd/mtd.h>
#include <asm-generic/errno.h>
#include <linux/compat.h>

#define CONFIG_SYS_MAX_SPI_NAND_DEVICE 1
#define INVAILD_BLOCK                  0xFFFFFFFF
//#define CONFIG_MTD_TABLE_TEST

typedef struct mtd_info spi_nand_info_t;
extern int spi_nand_curr_device;
extern spi_nand_info_t spi_nand_info[CONFIG_SYS_MAX_SPI_NAND_DEVICE];

//block state
#define BLOCK_BAD               0x00
#define BLOCK_HWSETTING         0x23
#define BLOCK_EMCU	            0x51    // tag for emcu firmware
#define BLOCK_EMCU_CERT	        0x50    // tag for emcu cert firmware
#define BLOCK_SYS_INFO          0x22 	// new tag for mac3
#define BLOCK_KEY_SIG		        0x24
#define BLOCK_AUXCODE           0x79    // was used for BLOCK_BOOTCODE
#define BLOCK_BOOTCODE          0x7A    // new tag for mac3
#define BLOCK_KBOOT             0x78
#define BLOCK_DATA              0x80
#define BLOCK_ENVPARAM_MAGICNO  0x81
#define BLOCK_FACTORY_SETTING   0x82
#define BLOCK_OTHER_DATA	      0xd0	// unknown data (user program into flash)
#define BLOCK_IBT		            0x11
#define BLOCK_BBT		            0xbb	// bad block table
#define BLOCK_CLEAN		          0xff	// block is empty
#define BLOCK_UNDETERMINE	      0x55	// block state is undetermined 
/* 
 * debug level,
 * if is DEBUG_LEVEL_DISABLE, no log is allowed output,
 * if is DEBUG_LEVEL_ERR, only ERR is allowed output,
 * if is DEBUG_LEVEL_INFO, ERR and INFO are allowed output,
 * if is DEBUG_LEVEL_DEBUG, all log are allowed output,
 */
enum debug_level {
    DEBUG_LEVEL_DISABLE = 0,
    DEBUG_LEVEL_ERR,
    DEBUG_LEVEL_INFO,
    DEBUG_LEVEL_DEBUG
};

#define PRINT               printk

#define DEBUG_SET_LEVEL(x)   static int sn_debug_level = x

#define SN_ERR(...)                                        \
do {                                                    \
    if (sn_debug_level >= DEBUG_LEVEL_ERR) {                     \
        PRINT(__VA_ARGS__);                             \
    }                                                   \
} while (0)

#define SN_INFO(...)                                       \
do {                                                    \
    if (sn_debug_level >= DEBUG_LEVEL_INFO) {                    \
        PRINT(__VA_ARGS__);                             \
    }                                                   \
} while (0)

#define SN_DEBUG(...)                                      \
do {                                                    \
    if (sn_debug_level >= DEBUG_LEVEL_DEBUG) {                   \
        PRINT(__VA_ARGS__);                             \
    }                                                   \
} while (0)


/*block-tag for bootcode-area & factory-area*/
static unsigned char Special_SPI_BlockTag[] = {
	BLOCK_CLEAN,
	BLOCK_OTHER_DATA,
	BLOCK_BBT,
	BLOCK_IBT,
	BLOCK_EMCU_CERT,
	BLOCK_EMCU,
	BLOCK_SYS_INFO,
	BLOCK_HWSETTING,
	BLOCK_KEY_SIG,
	BLOCK_AUXCODE,
	BLOCK_BOOTCODE,
	BLOCK_KBOOT,
	BLOCK_DATA,
	BLOCK_FACTORY_SETTING,
	BLOCK_ENVPARAM_MAGICNO,
	/*add your define tag*/
	BLOCK_UNDETERMINE
};

#define SPECIAL_SPI_BLOCK_TAG_N	(sizeof(Special_SPI_BlockTag)/sizeof(unsigned char))
#define BAD_TAG                0x00
#define IGR_TAG                0xFFFF
#define BBT_BLOCK_START        1
#define BBT_BAKCUP_BLOCK_START 2
#define	BB_INIT	               0xFFFE
#define	RB_INIT	               0xFFFD
#define	BBT_TAG	               0xBB
#define TAG_FACTORY_PARAM      0x82
typedef struct /*__attribute__ ((__packed__))*/{
    u16 bad_block;
    u16 remap_block;
}bbt_info_t;


#define IBT_BLOCK_START        3
#define IBT_BAKCUP_BLOCK_START 4
#define IBT_TAG		       0x11
#define	SRC_INIT	       0xFFFE
#define	DST_INIT	       0xFFFD
#define SN_IBT_BLOCK_NUM	2
#define SN_BBT_BLOCK_NUM  2
typedef struct /*__attribute__ ((__packed__))*/{
    u16 src_block;
    u16 dst_block;
}ibt_info_t;

#define RBT_INIT    0xFFFFFFFF
typedef struct 
{
   int bad_phy_block;
   int remap_log_block;
}rbt_info_t;

struct block_info
{
	u16 phy_block; 
	u16 block_tag;
};
#define IBT_SCAN_START_BLOCK         6 //start from sysinfo start block
#ifdef CONFIG_MTD_TABLE_TEST
#define READ_RETRY_COUNT	1
#else
#define READ_RETRY_COUNT	3
#endif
#define DEF_SYS_PARAM_BOOTCODE_SIZE  0x1400000
#define DEF_SYS_PARAM_FACTORY_SIZE   0x800000

typedef enum {
	CACHE_1X,
	CACHE_2X,
	CACHE_4X,
	CACHE_4X_IO,
} cache_mode;


typedef struct /*__attribute__ ((__packed__))*/{
    unsigned int    id;
    unsigned int    pageSize;
    unsigned int    blockSize;
    unsigned short  oobSize;
    unsigned long long	 size;	//nand total size
    unsigned int    bad_position;
    unsigned int	row_addr_mask;
    unsigned int	bad_tag_offset;
    unsigned int	magic_tag_offset;
	cache_mode      support_cache_mode;
	unsigned int    cache_bit_offset;
    char            *name;
} spi_nand_device_type_t;


typedef struct{
	// identify & revision info
	unsigned char	identifier[8];		    /* byte   0 ~ 7  */	/* identifier */
	unsigned int	revision;		        /* byte   8 ~ 11 */	/* revision */

	// flash info
	unsigned char	manufacturer_id[8];	/* byte  12 ~ 19 */	/* manufacturer id */
	unsigned char   flash_name[20];		    /* byte  20 ~ 39 */	/* flash name */
	unsigned int	flash_size0;			/* byte  40 ~ 43 */	/* flash size 0~31 */
	unsigned int	flash_size1;			/* byte  44 ~ 47 */	/* flash size 32~63 */
	unsigned int	data_per_page;			/* byte  48 ~ 51 */	/* page size */
	unsigned int	oob_per_page;			/* byte  52 ~ 55 */	/* spare size */
	unsigned int	page_per_block;			/* byte  56 ~ 59 */	/* page per block */
	unsigned int	block_per_die;			/* byte  60 ~ 63 */	/* block per die */

	// tag position info
	unsigned int	bb_tag_offset;			/* byte  64 ~ 67 */	/* bad block tag offset */
	unsigned int	special_tag_offset;		/* byte  68 ~ 71 */	/* special block tag offset; eg: hwsetting-0x23 */
	unsigned int	initial_bb_pos;			/* byte  72 ~ 75 */	/* initial bad block tag position*/

	// address mask info
	unsigned int	ra_block_mask;			/* byte  76 ~ 79 */	/* row address <block sector> mask value */
	unsigned int	ra_page_mask;			/* byte  80 ~ 83 */	/* row address <page sector> mask value */
	unsigned int	ca_mask;				/* byte  84 ~ 87 */	/* column address mask value */

	// use plane or not
	unsigned char	use_plane;				/* byte  88 */		/* use plane or not */
	unsigned char	reserved_0[3];			/* byte  89 ~ 91 */	/* reserved*/

	// bbt info sector
	unsigned int	number_of_bbt;		    /* byte  92 ~ 95 */	/* number of bbt */
	unsigned int	bbt_start_block;	    /* byte  96 ~ 99 */	/* bbt start block */
	unsigned int	bbt_end_block;		    /* byte  100 ~ 103 */	/* bbt end block */
	unsigned int	number_of_rsv_block;	/* byte  104 ~ 107 */	/* number of reserved block */
	unsigned int	rsv_start_block;	    /* byte  108 ~ 111 */	/* reserved start block */
	unsigned int	rsv_end_block;		    /* byte  112 ~ 115 */	/* reserved end block */

	// ibt info sector
	unsigned int	number_of_ibt;			/* byte  116 ~ 119 */	/* number of ibt */
	unsigned int	ibt_start_block;		/* byte  120 ~ 123 */	/* ibt start block*/
	unsigned int	ibt_end_block;			/* byte  124 ~ 127 */	/* ibt end block*/
	unsigned char	ibt_buffer_percent[32];	/* byte  128 ~ 159 */	/* ibt buffer percent, can support 32 partition*/

	//cache  mode support
	unsigned int	support_cache_mode; 	/* byte  160 ~ 163 */	/* cache mode*/
	unsigned int	cache_bit_offset;		/* byte  164 ~ 167 */	/*cache bit offset*/
	
	// resvered for future feature
	unsigned char	reserved_1[56]; 		/* byte  168 ~ 223 */	/* reserverd for future feature*/


	//checksum
	unsigned char   checksum[32];		    /* byte 224 ~ 255 */
} __attribute__((packed)) t_spi_nand_profile;

#define SPI_NAND_PROFILE_IDENTIFIER	       "REALTEK."		// same as nand solution
#define SPI_NAND_PROFILE_CHECKSUM_SIZE     224

#define GD5F1GQ4UAYIG   0xc8f1c8f1   //0xc8f1c8f1 0xf1c8f1c8
#define GD5F2GQ4UAYIG   0xc8f2c8f2   //0xc8f2c8f2 0xf1c8f1c8
#define GD5F1GQ4UBYIG   0xc8d1c8d1
#define GD5F2GQ4UBYIG   0xc8d2c8d2
#define MT29F1G01AAADD  0x2c122c12
#define AFD01GWS		0xDDA0DDA0
#define AFD02GWS		0xDDA1DDA1
#define HYF1GQ4UAACAR_C	0xC831C831
#define HYF1GQ4UAACAR	0xC151C151   //0xC151C151
#define A5U12A21ASC     0xc8207f7f   //0x7f7f20c8 0xc8207f7f
#define F50L1G41A       0xc8217f7f   //0x7f7f21c8 0xc8217f7f
#define W25N01GVZE1G 	0xefaa2100
#define MX35LF1GE4AB    0xc212c212
#define TC58CVG0S3HAI	0x98c298c2
#define TC58CVG1S3HAI   0x98c298c2
#define TC58CVG2S3HAI   0x98cb98cb
#define EM73C044SNB		0xd511d511		

#define INITIAL_BB_POS_FIRST	0x0	// in the first page of initial bad block

static const spi_nand_device_type_t spi_nand_device[] =
{
    {GD5F1GQ4UAYIG,        2048, 64*2048, 64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_1X,0,"GD5F1GQ4UAYIG" } , 
    {GD5F2GQ4UAYIG,        2048, 64*2048, 64,0x10000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_1X,0,"GD5F2GQ4UAYIG" } , 
    {GD5F1GQ4UBYIG,        2048, 64*2048, 64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_4X_IO,0,"GD5F1GQ4UBYIG" } , 
    {MT29F1G01AAADD,       2048, 64*2048, 64,0x10000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_1X,0,"MT29F1G01AAADD" } ,
    {AFD01GWS,             2048, 64*2048, 64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_1X,0,"AFD01GWS"    } ,     
    {AFD02GWS,             2048, 64*2048, 64,0x10000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_1X,0,"AFD02GWS"    } ,         
    {HYF1GQ4UAACAR_C, 	   2048, 128*2048,64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_1X,0,"HYF1GQ4UAACAR-C"} ,	   
    {HYF1GQ4UAACAR, 	   2048, 64*2048, 64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_1X,0,"HYF1GQ4UAACAR"} ,
    {A5U12A21ASC,          2048, 64*2048, 64,0x04000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_4X,0,"A5U12A21ASC" } , 
    {F50L1G41A,            2048, 64*2048, 64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x808,CACHE_4X,0xF,"F50L1G41A" } , 
    {W25N01GVZE1G ,        2048, 64*2048, 64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_4X_IO,0,"W25N01GVZE1G" } ,
    {MX35LF1GE4AB ,        2048, 64*2048, 64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_2X,0,"MX35LF1GE4AB" } ,
    {TC58CVG0S3HAI ,       2048, 64*2048, 64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_4X,1,"TC58CVG0S3HAI" } ,
    {TC58CVG1S3HAI ,       2048, 64*2048, 64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_4X,1,"TC58CVG1S3HAI" } ,
    {TC58CVG2S3HAI,        2048, 64*2048, 64,0x10000000, INITIAL_BB_POS_FIRST, 0x7ff,0x800,0x800,CACHE_4X,1,"TC58CVG2S3HAI" } ,
    {GD5F2GQ4UBYIG,        2048, 64*2048, 64,0x10000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_4X_IO,0,"GD5F2GQ4UBYIG" } , 
    {EM73C044SNB,          2048, 64*2048, 64,0x08000000, INITIAL_BB_POS_FIRST, 0x3ff,0x800,0x800,CACHE_4X,0,"EM73C044SNB" } , 
}; 

typedef enum {
    FL_READY,
    FL_READING,
    FL_WRITING,
    FL_ERASING,
    FL_SYNCING,
    FL_CACHEDPRG,
    FL_PM_SUSPENDED,
}spi_nand_state_t;

#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE

#define HW_SEM_REG	(0xB801A638)

static inline void rtk_sn_spin_lock(void)
{	
    while(1) {
        if (rtd_inl(HW_SEM_REG) == 0){
        } else {
            break;
        }
    }	
}

static inline void rtk_sn_spin_unlock(void)
{	
    rtd_outl(HW_SEM_REG,0);
}

#endif

static inline unsigned int swap_endian(unsigned int input)
{
    unsigned int output;
    output = (input & 0xff000000)>>24|
			 (input & 0x00ff0000)>>8|
			 (input & 0x0000ff00)<<8|
			 (input & 0x000000ff)<<24;
	
    return output;
}

static inline int generic_ffs(int x)
{
	int r = 1;
	if (!x)
		return 0;
	if (!(x & 0xffff)) {
		x >>= 16;
		r += 16;
	}
	if (!(x & 0xff)) {
		x >>= 8;
		r += 8;
	}
	if (!(x & 0xf)) {
		x >>= 4;
		r += 4;
	}
	if (!(x & 3)) {
		x >>= 2;
		r += 2;
	}
	if (!(x & 1)) {
		x >>= 1;
		r += 1;
	}
	return r;
}

struct spi_nand_chip {
	void (*read_id) (struct mtd_info *mtd, unsigned int *id);
	int (*read_ecc_page) (struct mtd_info *mtd, unsigned int page, u_char *data, u_char *oob_buf);
	int (*read_oob) (struct mtd_info *mtd, unsigned int page, u_char *buf,int len);
	int (*write_ecc_page) (struct mtd_info *mtd, unsigned int page, const u_char *data,const u_char *oob_buf);						
	int (*write_oob) (struct mtd_info *mtd, unsigned int page, const u_char *buf,int len);
	int (*erase_block) (struct mtd_info *mtd, unsigned  int block_addr);
	int (*is_good_block)(struct mtd_info *mtd, unsigned int block_addr);
	void (*sync) (struct mtd_info *mtd);
	void (*suspend) (struct mtd_info *mtd);
	void (*resume) (struct mtd_info *mtd);

    uint64_t       device_size;
    unsigned int   id;
    unsigned int   block_size;  
    unsigned int   page_size;
    int            oob_size;
    int            block_shift;
    int            page_shift;
    int            oob_shift;
    int            total_block_num;
    int            total_page_num;
    int            block_per_page;
    int            pagemask;
    int            bad_tag_offset;
	int            magic_tag_offset;
    cache_mode     support_cache_mode;
    unsigned int   cache_bit_offset;
 

    unsigned int   RBA_PERCENT;
    unsigned int   RBA;
    unsigned int   I_KERNEL_RBA_PERCENT;
    unsigned int   I_KERNEL_RBA;
    unsigned int   I_BOOTCODE_RBA_PERCENT;
    unsigned int   I_BOOTCODE_RBA; 
	
    int            bbt_len;
    bbt_info_t     *bbt_table;
    int            cur_rba_num;
	int 		   use_rba_num;

    int            ibt_len;
    ibt_info_t     *ibt_table;

    int            bootcode_start_phy_block;
    int            bootcode_end_phy_block;
    int            kernel_start_phy_block;
    int            kernel_end_phy_block;
    int            kernel_rba_end_log_block;

	rbt_info_t *   rbt_table;
    int            rbt_len;
    int            cur_rbt_num;
    int            log2phy_len;
    int            *log2phy_table;
	
	struct block_info * bi_table;
	int 			bi_table_block_start;
	int 			bi_table_block_num; 
	int 			frist_boot;

    int            *sn_reg_arry;
    
    u_char 		     *g_databuf;
    u_char		     *g_oobbuf;
    spinlock_t		 chip_lock;
    wait_queue_head_t wq;	
    spi_nand_state_t	state;
};


#define MTDSIZE	(sizeof (struct mtd_info) + sizeof (struct spi_nand_chip))
#endif