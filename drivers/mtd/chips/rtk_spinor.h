#include <mach/iomap.h>
#include <mach/io.h>

//#define CONFIG_MTD_SFC_PRINTK_DEBUG
#ifdef CONFIG_MTD_SFC_PRINTK_DEBUG
#define SPI_NOR_TEST
#define SFC_MSG_DEBUG(fmt, args...) printk("[SFC_LOG][DEBUG] " fmt, ## args)
#else
#define SFC_MSG_DEBUG(fmt, args...)     /* empty macro */
#endif

#define CONFIG_MTD_SFC_PRINTK_INFO
#ifdef CONFIG_MTD_SFC_PRINTK_INFO
#define SFC_MSG_INFO(fmt, args...) printk(KERN_INFO "[SFC_LOG][INFO] " fmt, ## args)
#else
#define SFC_MSG_INFO(fmt, args...)     /* empty macro */
#endif
#define SFC_MSG_ERR(fmt, args...) printk(KERN_ERR "[SFC_LOG][ERROR] " fmt, ## args)

#define EMPTY_VALUE                0
/*********************************************************
*
* spinor_info_t define
*
**********************************************************/
// device id
#define	MX_25L12835D_128Mbit		0xc22018//	0x1820c2
#define MX_25L6406E_64Mbit          0xc22017

#define WINBOND_W32Q64_64Mbit		0xef4017
#define WINBOND_W25Q128FV_128Mbit	0xef4018

#define GD25Q64C_64Mbit             0xc84017
#define GD25Q128C_128Mbit		    0xc84018
#define F25L64QA_64Mbit             0x8c4117

typedef enum
{
    eMODE_READ_NORMAL = 0,
    eMODE_READ_NORMAL_FAST,
    eMODE_READ_DUAL_FAST,
    eMODE_READ_QUAD_FAST 
} read_mode;

typedef enum
{
    eMODE_WRITE_NORMAL = 0,
    eMODE_WRITE_QUAD_FAST 
} write_mode;

// QUAD MODE   RDSR(read status reg)   WRSR(write status reg)
#define CMD_QUAD_RDSR1            0x05
#define CMD_QUAD_RDSR2            0x35
#define CMD_QUAD_RDSR3            0x15
#define CMD_QUAD_WRSR1            0X01
#define CMD_QUAD_WRSR2            0X31
#define CMD_QUAD_WRSR3            0X11
#define BIT7                        0x80
#define BIT6                        0x40
#define BIT5                        0x20
#define BIT4                        0x10
#define BIT3                        0x08
#define BIT2                        0x04
#define BIT1                        0x02
#define BIT0                        0x01

// spinor_info_t->erase_capacity
#define ERASE_4K           0x01
#define ERASE_32K          0x02
#define ERASE_64K          0x04
#define ERASE_256K         0x08

#define ERASE_SZIE_64K  0x10000
#define ERASE_SZIE_32K  0x8000
#define ERASE_SZIE_4K   0x1000

typedef struct 
{
    unsigned int    id ;
    unsigned char   erase_capacity;
    unsigned int    min_erase_size;
    unsigned char   page_program ;
    unsigned int    size;
    unsigned char   *string;
    read_mode       read_mode;
    write_mode      write_mode;

    // Quad Enabel
    unsigned char   cmd_quad_rdsr;
    unsigned char   cmd_quad_wrsr;
    unsigned char   cmd_quad_bit;
} spinor_info_t;

static const spinor_info_t s_device[] = 
{
     // id                      256 64 32 4                    erase_size    size       string                       read_mode              write_mode
    {MX_25L12835D_128Mbit,       ERASE_4K|ERASE_64K,           0x1000,    1, 0x1000000, "MX_25L12835D_128Mbit",      eMODE_READ_QUAD_FAST,    eMODE_WRITE_NORMAL, CMD_QUAD_RDSR1, CMD_QUAD_WRSR1, BIT6},
    {MX_25L6406E_64Mbit,         ERASE_4K|ERASE_64K ,          ERASE_SZIE_4K,    1, 0x800000,  "MX_25L6406E_64Mbit",        eMODE_READ_DUAL_FAST,    eMODE_WRITE_NORMAL,  EMPTY_VALUE,    EMPTY_VALUE,    EMPTY_VALUE},

    {WINBOND_W32Q64_64Mbit,      ERASE_4K|ERASE_32K|ERASE_64K, 0x1000,    1, 0x800000, "WINBOND_W32Q64_64Mbit", eMODE_READ_QUAD_FAST,    eMODE_WRITE_NORMAL, CMD_QUAD_RDSR2, CMD_QUAD_WRSR1, BIT1},
    {WINBOND_W25Q128FV_128Mbit,  ERASE_4K|ERASE_32K|ERASE_64K, 0x1000,    1, 0x1000000, "WINBOND_W25Q128FV_128Mbit", eMODE_READ_QUAD_FAST,    eMODE_WRITE_NORMAL, CMD_QUAD_RDSR2, CMD_QUAD_WRSR2, BIT1},

    {GD25Q64C_64Mbit,            ERASE_4K|ERASE_32K|ERASE_64K, ERASE_SZIE_4K,    1, 0x800000, "GD25Q64C_64Mbit",     eMODE_READ_QUAD_FAST,    eMODE_WRITE_NORMAL, CMD_QUAD_RDSR2, CMD_QUAD_WRSR2, BIT1} ,
    {GD25Q128C_128Mbit,          ERASE_4K|ERASE_32K|ERASE_64K, 0x1000,    1, 0x1000000, "GD25Q128C_128Mbit",         eMODE_READ_QUAD_FAST,    eMODE_WRITE_NORMAL, CMD_QUAD_RDSR2, CMD_QUAD_WRSR2, BIT1},

    {F25L64QA_64Mbit,            ERASE_4K|ERASE_32K|ERASE_64K,   0x1000,    1, 0x800000, "F25L64QA_64Mbit",         eMODE_READ_QUAD_FAST,    eMODE_WRITE_NORMAL, CMD_QUAD_RDSR1, CMD_QUAD_WRSR1, BIT6} ,

} ; 

#define DEV_SIZE_S	(sizeof(s_device)/sizeof(spinor_info_t))

/*********************************************************
*
* spinor_chip_t define
*
**********************************************************/


typedef struct {
    struct mtd_info *mtd_info;
    spinor_info_t *spinor_info;
    struct semaphore spinor_sem;
    int * spi_reg_array; 
    void (*read_id)(unsigned int *id);
    void (*read_bytes)(struct mtd_info* mtd, loff_t from, size_t len, size_t *retlen, const u_char *buf);
    int (*erase_flash)(struct mtd_info* mtd, loff_t from, size_t len);
    int (*write_bytes)(struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char  *buf); 
    void (*read_md)(struct mtd_info* mtd, loff_t from, size_t len, size_t *retlen, const u_char *buf);
    int (*write_md)(struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char  *buf); 
    void (*switch_read_mode)(spinor_info_t *spinor_info);
    int (*verify_after_write)(struct mtd_info* mtd, unsigned char * to_verify, size_t len_verify, unsigned char *buf_verify);
    int (*unlock_flash)(struct mtd_info* mtd);
    int (*get_lock_status)(struct mtd_info* mtd, const char *buf, unsigned int max_size);
    int (*suspend)(struct mtd_info* mtd);
    int (*resume)(struct mtd_info* mtd);
}spinor_chip_t;

#define MTDSIZE	(sizeof (struct mtd_info) + sizeof (spinor_chip_t))
#define FOUR_BYTES_MASK   0x3
#define WRITE_BYTES_MASK  0xf
#define MD_PP_DATA_SIZE_SHIFT	8	/* 256 bytes */
#define MD_PP_DATA_SIZE		    (1 << MD_PP_DATA_SIZE_SHIFT)

int sfc_probe(struct mtd_info *mtd_info);
