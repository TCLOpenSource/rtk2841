/************************************************************************
 *
 *  sfc_reg.h
 *
 *  Defines for Sirius SFC registers
 *
 ************************************************************************/

#ifndef RTK_SPI_NAND_BASE_H
#define RTK_SPI_NAND_BASE_H

/************************************************************************
 *  Definition
 ************************************************************************/
#define SFC_REG_BASE		0xb801a800  //0xb801a800
#define SAVE_SN_REGNUM		10


#define MD_PP_DATA_SIZE_SHIFT	8	/* 256 bytes */
#define MD_PP_DATA_SIZE		(1 << MD_PP_DATA_SIZE_SHIFT)

#define SFC_OPCODE		    (SFC_REG_BASE + 0x00)
#define SFC_CTL			      (SFC_REG_BASE + 0x04)
#define SFC_SCK			      (SFC_REG_BASE + 0x08)
#define SFC_CE			      (SFC_REG_BASE + 0x0c)
#define SFC_WP			      (SFC_REG_BASE + 0x10)
#define SFC_POS_LATCH		  (SFC_REG_BASE + 0x14)
#define SFC_WAIT_WR		    (SFC_REG_BASE + 0x18)
#define SFC_EN_WR		      (SFC_REG_BASE + 0x1c)

#define SF_32MB_EN	     	(SFC_REG_BASE + 0x28)

#define SPI_NAND_0		    (SFC_REG_BASE + 0x2c)

#define SPI_ADDR_CNT_1		  0	
#define SPI_ADDR_CNT_2		  1
#define SPI_ADDR_CNT_3		  2

#define MD_REG_BASE           0xb800b000


#define MD_FDMA_DDR_SADDR     (MD_REG_BASE + 0x88)
#define MD_FDMA_FL_SADDR      (MD_REG_BASE + 0x8c)
#define MD_FDMA_CTRL2         (MD_REG_BASE + 0x90)
#define MD_FDMA_CTRL1         (MD_REG_BASE + 0x94)

#define MD_KFDMA_DDR_SADDR    (MD_REG_BASE + 0x180)
#define MD_KFDMA_FL_SADDR     (MD_REG_BASE + 0x184)
#define MD_KFDMA_CTRL2        (MD_REG_BASE + 0x188)
#define MD_KFDMA_CTRL1        (MD_REG_BASE + 0x18c)

// System Bridge II
#define SB2_WRAPPER_CTRL	((volatile unsigned int *)0xb801a018)

// Move Data Engine
//#define MD_FDMA_DDR_SADDR	((volatile unsigned int *)0xb800b088)
//#define MD_FDMA_FL_SADDR	((volatile unsigned int *)0xb800b08c)
//#define MD_FDMA_CTRL2		((volatile unsigned int *)0xb800b090)
//#define MD_FDMA_CTRL1		((volatile unsigned int *)0xb800b094)

#define CMD_MASK             0xFF
#define CMD_RESET            0xFF
#define CMD_SET_FEATURE      0x1F
#define CMD_GET_FEATURE      0x0F
#define CMD_READ_ID          0x9F
#define CMD_READ_PAGE        0x13
#define CMD_READ_CACHE       0x03
#define CMD_READ_2XCACHE     0x3B
#define CMD_READ_4XCACHE     0x6B
#define CMD_READ_4XCACHE_IO  0xEB
#define CMD_WRITE_ENABLE     0x06
#define CMD_ERASE            0xd8
#define CMD_PROGRAM_LOAD     0x84
#define CMD_PROGRAM_4XLOAD	 		0x32
#define CMD_PROGRAM_4XLOAD_IO 		0x72
#define CMD_PROGRAM_RANDOM			0x34
#define CMD_PROGRAM_EXECUTE  0x10

#define DUAL_READ             1
#define DUAL_READ_IO          2
#define DUAL_WRITE            3
#define DUAL_WRITE_IO         4
#define QUAD_READ             5
#define QUAD_READ_IO          6
#define QUAD_WRITE            7
#define QUAD_WRITE_IO         8
#define DUAL_QUAD_MODE_OFFSET 9
#define DATEN_OFFSET          4
#define ADREN_OFFSET          3
#define DMYCNT_OFFSET         0
#define DMYCNT_MASK           0x7


#define ADRCNT_EN_OFFSET      25
#define ADDR_MASK             0x1FFFFFF
#define ADR_CNT_OFFSET        26
#define ADR_DMA_LEN           0x3
#define ADR_CNT_MASK          0x3



#define GET_BLOCKLOCK_ADDR    0xA0
#define GET_B0_ADDR           0xB0
#define GET_STATUS_ADDR       0xC0
#define STA_OIP_OFFSET        0
#define STA_OIP_MASK          0x1
#define STA_WEL_OFFSET        1
#define STA_WEL_MASK          0x2
#define STA_EFAIL_OFFSET      2
#define STA_EFAIL_MASK        0x4
#define STA_PFAIL_OFFSET      3
#define STA_PFAIL_MASK        0x8
#define STA_ECCS0_OFFSET      4
#define STA_ECCS1_OFFSET      5
#define STA_ECC_MASK          0x3
#define ECC_NO_ERROR          0x0
#define ECC_CORRECT           0x1
#define ECC_ERR               0x2
#define ECC_RESERVED          0x3
#define STA_OTP_OFFSET        6
#define STA_OTP_MASK          0x40
#define GET_BLOCKLOCK_ADDR    0xA0
#define BP0_LOCK_OFFSET       3   
#define BP0_LOCK_MASK         0x08
#define BP1_LOCK_OFFSET       4
#define BP1_LOCK_MASK         0x10
#define BP2_LOCK_OFFSET       5
#define BP2_LOCK_MASK         0x20
#define ALL_LOCK              0x38


#define BLOCK_MASK            0x7FF
#define BLOCK_OFFSET          6
#define SPI_PAGE_MASK         0x3F
#define FDMA_DIR_OFFSET       25
#define FDMA_XFER_OFFSET      26
#define FDMA_XFER_MASK        0x3
#define DMA_XFER_LEN          0x3
#define BYTE_512_XFER_LEN     0x2
#define BYTE_256_XFER_LEN	  0x1

#define FMAP_MODE_OFFSET      29
#define FOWAD_MAP             1
#define DMA_ADDR_MASK         0x1ffffff

#define FDMA_GO_OFFSET        0
#define FDMA_GO_MASK          0x1
#define WRITE_EN_OFFSET       1

#define SPI_NAND_BASE_ADDR	0xb8200000	/* SPI-NAND flash address (0xbfc00000 may be in ROM region) */

#define STATUS_TIMEOUT      100
#define SFC_DELAY           100
#define SFC_ERASE_DELAY     50 
#define SFC_WRITE_DELAY		10
#define SFC_READ_DELAY      1


void set_spi_nand_pin_mux(void);
void sfc_reset(void);
int sfc_unlock_flash(void);
int sfc_set_cachemode(struct mtd_info *mtd);
void rtk_spi_nand_read_id(struct mtd_info *mtd,unsigned int *id);
int rtk_spi_read_ecc_page(struct mtd_info *mtd, unsigned int page, u_char *data_buf, u_char *oob_buf);
int rtk_spi_read_oob(struct mtd_info *mtd, unsigned int page, u_char *data_buf, int len);
int rtk_spi_write_ecc_page (struct mtd_info *mtd, unsigned int page,
			const u_char *data_buf, const  u_char *oob_buf);
int rtk_spi_write_oob(struct mtd_info *mtd, unsigned int page,const u_char *buf,int len);
int rtk_spi_erase_block(struct mtd_info *mtd,unsigned int block);
void dump_sn_reg(int str);
void suspend_sn_register(struct mtd_info *mtd);
void resume_sn_register(struct mtd_info *mtd);



#endif /* #ifndef RTK_SPI_NAND_BASE_H */
