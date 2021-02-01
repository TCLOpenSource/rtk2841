#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/dma-mapping.h>
#include <asm/cacheflush.h>
#include <mach/iomap.h>
#include <mach/io.h>
#include "rtk_spi_nand.h"
#include "rtk_spi_nand_base.h"

#define CONFIG_SPI_NAND_USE_GPO_CS

#define REG8_READ(register)          rtd_inb(register)
#define REG32_READ(register)          rtd_inl(register)
#define REG8_WRITE(register, value)   rtd_outb(register, value)
#define REG32_WRITE(register, value)  rtd_outl(register, value)
#define REG32_MASK(register, andMask, orMask)  rtd_outl(register, ((rtd_inl(register) & (andMask)) | (orMask)))

#define BYTE(d,n)		(((d) >> ((n) << 3)) & 0xFF)
#define SWAPEND32(d)	((BYTE(d,0) << 24) | (BYTE(d,1) << 16) | (BYTE(d,2) << 8) | (BYTE(d,3) << 0))
#define _SPI_NAND_CTRL
DEBUG_SET_LEVEL(DEBUG_LEVEL_INFO);

#ifdef CONFIG_MTD_TABLE_TEST
int set_erase_fail = 0;
int set_write_fail = 0;
int set_read_fail = 0;
#endif
int wait_device_ready(int wait_delay);

void dump_byte(char *buf, int buf_size)
{
    int loop = 0;
    SN_ERR("buf 0x%x size 0x%x", buf, buf_size);
    for(loop = 0; loop < buf_size; loop++)
    {
        if(loop%16 == 0)
        {
            SN_ERR("\n%08xh:",loop); 
        }
        SN_ERR(" %02x",*buf);
        buf++;
    }
    SN_ERR("\n");	   
}

void dump_reg(unsigned int base_reg, unsigned int reg_num)
{
    int loop = 0;
    SN_ERR("base register 0x%x number %d",base_reg,reg_num);  
    for(loop = 0; loop < reg_num; loop++)
    {
        if(loop%4 == 0)
        {
            SN_ERR("\n%08xh:",(base_reg+loop*4));
        }
        SN_ERR(" %08x",REG32_READ(base_reg+4*loop));  
    }
    SN_ERR("\n");	
}

void dump_sn_reg(int str)
{
    int reg_addr = SFC_REG_BASE;
    SN_ERR("%s *******begin********** \n",__FUNCTION__);  
    dump_reg(reg_addr,8);
    reg_addr = SF_32MB_EN;
    dump_reg(reg_addr,2);
    if(str == 0){  //suspend resume not access
       SN_ERR("%s *******MD register********** \n",__FUNCTION__); 
       reg_addr = MD_REG_BASE + 0x88;
       dump_reg(reg_addr,4);
    }
    SN_ERR("%s *******pin mux********** \n",__FUNCTION__);  
    reg_addr = 0xb80008ac;
    dump_reg(reg_addr,2);
    SN_ERR("%s ******end************ \n",__FUNCTION__); 
}

void set_spi_cs_gpio(void)
{
#ifdef	CONFIG_SPI_NAND_USE_GPO_CS
	/*SPI_CS_N = 0xF to GPIO*/
	REG32_MASK(0xb80008b0, 0xffff0fff, (0xF << 12));
	REG32_MASK(0xb80008ac, 0x0fffffff, (0xF << 28));
	/*GPIO169 to GPO*/
	REG32_MASK(0xb801bd14, 0xffffFDff, (0x1 << 9));
	/*GPO169 to high*/
	REG32_MASK(0xb801bd2c, 0xffffFDff, (0x1 << 9));
	/*GPO169 to low*/
	REG32_MASK(0xb801bd2c, 0xffffFDff, (0x0 << 9));
#endif
}

void sfc_reset(void)
{	
    UINT8 tmp = 0;
	set_spi_cs_gpio();
    /*send reset command*/
    REG32_WRITE(SFC_OPCODE,CMD_RESET&CMD_MASK);
    /*data  address disable*/
    REG32_WRITE(SFC_CTL,0x00000000);    /* dataen = 0 adren = 0, dmycnt = 0 */
    tmp = REG8_READ(SPI_NAND_BASE_ADDR);
    /*wait reset ok*/
    if (wait_device_ready(SFC_DELAY)!=0) 
    {
        SN_ERR("%s device not ready \n",__FUNCTION__);
    }
}

#ifdef _SPI_NAND_CTRL
void set_spi_n_address(unsigned int addr_cnt, unsigned int addr)
{
    REG32_WRITE(SPI_NAND_0,((addr_cnt&ADR_CNT_MASK)<<ADR_CNT_OFFSET)|(0x1<<ADRCNT_EN_OFFSET)|(addr&ADDR_MASK));
}

void clr_spi_n_address(void)
{
    REG32_WRITE(SPI_NAND_0,0);
}
#endif

void set_spi_nand_pin_mux()
{
	/*set spi nand clock 500/(5+1)=83.3*/
	REG32_WRITE(0xb801A808,0x5);

	/*set delay time*/
	REG32_WRITE(SFC_POS_LATCH,0x4);
	/*SPI_HOLD [15:12] = 0x2*/
	REG32_MASK(0xb80008ac, 0xffff0fff, (2 << 12));

	/* SPI_WP[7:4] = 0x2*/
	REG32_MASK(0xb80008ac, 0xffffff0f, (2 << 4));
	
	/*SPI_DO [31:28] = 0x2*/
	REG32_MASK(0xb80008b0, 0x0fffffff, (2 << 28));

	/*SPI_CLK[23:20] = 0x2*/
	REG32_MASK(0xb80008b0, 0xff0fffff, (2 << 20));
#ifdef	CONFIG_SPI_NAND_USE_GPO_CS	
	/*SPI_CS_N = 0xF to GPIO*/
	REG32_MASK(0xb80008b0, 0xffff0fff, (2 << 12));
#endif
	
	/*SPI_DI[7:4] = 0x2*/
	REG32_MASK(0xb80008b0, 0xffffff0f, (2 << 4));
}

void rtk_spi_nand_read_id(struct mtd_info *mtd,unsigned int *id)
{
    unsigned int spi_address = 0;
	set_spi_cs_gpio();
    /*set read id command(0x9f)*/
    REG32_WRITE(SFC_OPCODE,CMD_READ_ID&CMD_MASK);
    /*set address,data enable*/  
    REG32_WRITE(SFC_CTL,(1<<DATEN_OFFSET)|(1<<ADREN_OFFSET)); 
    /*set address bit[0:7]*/
    set_spi_n_address(SPI_ADDR_CNT_1, 0x00);
    spi_address = SPI_NAND_BASE_ADDR;

    //sync();
    udelay(SFC_DELAY);

    /*read data content*/
    *id = REG32_READ(spi_address);
    *id= SWAPEND32(*id);

    SN_INFO("%s %d get spi-nandflash id 0x%x \n",__FUNCTION__,__LINE__,*id);
}

void sfc_get_feature(unsigned char address, unsigned char *data)
{
    unsigned int spi_address = 0;
	set_spi_cs_gpio();
    /*set get feature command(0xF)*/
    REG32_WRITE(SFC_OPCODE,CMD_GET_FEATURE&CMD_MASK);
    /*set address,data enable*/  
    REG32_WRITE(SFC_CTL,(1<<DATEN_OFFSET)|(1<<ADREN_OFFSET)); /* dataen = 1, adren = 1, dmycnt = 0 */
    udelay(SFC_READ_DELAY);

    /*set address bit[0:7]*/
    set_spi_n_address(SPI_ADDR_CNT_1, 0);
    spi_address = SPI_NAND_BASE_ADDR + address;

    //sync();
    udelay(SFC_READ_DELAY);
    
    /*get data content*/
    *data = REG8_READ(spi_address);
    SN_DEBUG("%s address 0x%x spi_address 0x%x data 0x%x \n",__FUNCTION__,address,spi_address,*data);

    clr_spi_n_address();
}

void sfc_set_feature(unsigned char address, unsigned char data)
{
    unsigned int spi_address = 0;
    UINT8 tmp = 0;
	set_spi_cs_gpio();
    /*set feature command(0x1f)*/
    REG32_WRITE(SFC_OPCODE,CMD_SET_FEATURE&CMD_MASK);

    /*set address,data enable*/ 
    REG32_WRITE(SFC_CTL,(1<<DATEN_OFFSET)|(1<<ADREN_OFFSET)); /* dataen = 1, adren = 1, dmycnt = 0 */
    udelay(SFC_DELAY);
	
    /*set address bit[0:7]*/
    set_spi_n_address(SPI_ADDR_CNT_1, 0);
    spi_address = SPI_NAND_BASE_ADDR  + address;
    tmp = REG8_READ(spi_address);
    //sync();
    udelay(SFC_DELAY);

    /*send data*/
    REG8_WRITE(spi_address,data);

    clr_spi_n_address();
}

int wait_device_ready(int wait_delay)
{
    int ret = 0, retry = 0;
    UINT8 spi_1byte_data = 0;
    do {
        udelay(wait_delay); 
        sfc_get_feature(GET_STATUS_ADDR, &spi_1byte_data);
    } while ((spi_1byte_data & STA_OIP_MASK)&&(++retry < STATUS_TIMEOUT));

    if (retry == STATUS_TIMEOUT) 
    {
        SN_ERR("%s wait timet out spi_1byte_data 0x%x\n",__FUNCTION__,spi_1byte_data);
        ret = -1;
    }
    return ret;
}

int check_ecc(void)
{
    int ret = 0;
    UINT8 data = 0;
    sfc_get_feature(GET_STATUS_ADDR, &data);
    switch ((data>>STA_ECCS0_OFFSET)& STA_ECC_MASK) {
        case ECC_RESERVED:
        //bit error & corrected (for GD)
            break;
        case ECC_ERR:
         //bit error & NOT corrected
            ret = -1;
            break;
        case ECC_CORRECT:
        //bit error & corrected
            break;
        case ECC_NO_ERROR:
        //no bit error
            break;
        default:
        //impossible;
            ret = -1;
    }
    return ret;
}

int sfc_read_page_to_cache_b(const unsigned int block_addr,const unsigned int page_addr)
{
    int ret = 0;
    unsigned int spi_address = 0;
    UINT8 tmp = 0;
	set_spi_cs_gpio();
    /*set read page command(0x13)*/
    REG32_WRITE(SFC_OPCODE,CMD_READ_PAGE&CMD_MASK);
   
    /*set address enable*/
    REG32_WRITE(SFC_CTL,1<<ADREN_OFFSET); /* dataen = 0, adren = 1, dmycnt = 0 */

    /*set 24bit row address-->24 bit row address page address[0:5] block address[6:23] */
    set_spi_n_address(SPI_ADDR_CNT_3, 0);
    spi_address = SPI_NAND_BASE_ADDR+((block_addr&BLOCK_MASK)<<BLOCK_OFFSET)+(page_addr&SPI_PAGE_MASK);

	/*send read page command,addess*/
	tmp = REG8_READ(spi_address);
    SN_DEBUG("%s block_addr %d page_addr %d spi_address 0x%x %d\n",
    __FUNCTION__,block_addr,page_addr,spi_address, REG8_READ(spi_address));
	//dump_sn_reg(0);

    clr_spi_n_address();
    
    /*wait device ready*/
    if ((ret = wait_device_ready(SFC_READ_DELAY))== 0)
    {
        /*check ecc */
        if ((ret = check_ecc()) < 0) 
        {
            SN_ERR("%s ecc error block_addr %d page_addr %d \n",__FUNCTION__,block_addr,page_addr);
        }
    }
    return ret;  
}

void sfc_set_read_cache_cmd(cache_mode read_cache_mode)
{
    int cache_cmd = 0;
    switch(read_cache_mode)
	{
        case CACHE_1X:
            cache_cmd = CMD_READ_CACHE&CMD_MASK;
			break;
        case CACHE_2X:
            cache_cmd = (CMD_READ_2XCACHE&CMD_MASK)|(DUAL_READ<<DUAL_QUAD_MODE_OFFSET);
            break;
        case CACHE_4X:
            cache_cmd = (CMD_READ_4XCACHE&CMD_MASK)|(QUAD_READ<<DUAL_QUAD_MODE_OFFSET);
            break;
        case CACHE_4X_IO:
            cache_cmd = (CMD_READ_4XCACHE_IO&CMD_MASK)|(QUAD_READ_IO<<DUAL_QUAD_MODE_OFFSET);
            break;
        default:
            cache_cmd = CMD_READ_CACHE&CMD_MASK;
            break;
	}

	REG32_WRITE(SFC_OPCODE,cache_cmd);
}

void sfc_read_cache_to_mem_md(cache_mode read_cache_mode,
	unsigned int block_addr,UINT8 *dst,UINT32 offset,UINT32 len)
{
    UINT32 spi_address  = 0;
	set_spi_cs_gpio();

    spi_address = SPI_NAND_BASE_ADDR+offset; 

    // flush cache before DMA
    //dma_addr_databuf = dma_map_single(NULL, (u8 *)dst, (size_t)len, DMA_FROM_DEVICE);	//flush_dcache_all();
    dmac_flush_range(dst, dst+len);
    outer_flush_range(virt_to_phys(dst), virt_to_phys(dst+len));
    /*set read cache command*/
	set_spi_cs_gpio();
    sfc_set_read_cache_cmd(CACHE_2X);
	
    /*set address,data enable and dummy data = 1*/
    REG32_WRITE(SFC_CTL,(1<<DATEN_OFFSET)|(1<<ADREN_OFFSET)|((1&DMYCNT_MASK)<<DMYCNT_OFFSET));  /* dataen = 1, adren = 1, dmycnt = 1 */
    /*enable spi nandflash and set bit[0:15]-->cloumn address page */
    set_spi_n_address(SPI_ADDR_CNT_2, 0); // address don't care, use MD address

    udelay(SFC_READ_DELAY);

    /*set ddr address*/
    REG32_WRITE(MD_FDMA_DDR_SADDR,virt_to_phys(dst));//(UINT32)PHYS(dst);
    /*set spi nandflash addess*/
    REG32_WRITE(MD_FDMA_FL_SADDR,(UINT32)(spi_address - SPI_NAND_BASE_ADDR)) ;
	
    /*set dma mode  fixBYTE_512_XFER_LEN -->DMA_XFER_LEN */
    REG32_WRITE(MD_FDMA_CTRL2,((FOWAD_MAP<<FMAP_MODE_OFFSET)|(DMA_XFER_LEN<<FDMA_XFER_OFFSET)) | (len & DMA_ADDR_MASK)); /*don't swap (bit28:0)*/
	
    /*set dma start*/
    REG32_WRITE(MD_FDMA_CTRL1,(1<<FDMA_GO_OFFSET)|(1<<WRITE_EN_OFFSET));  // go
    while ((REG32_READ(MD_FDMA_CTRL1) & FDMA_GO_MASK) != 0);
   
    clr_spi_n_address();

}

void sfc_read_cache_to_mem_cpu_sec(unsigned int block_addr,UINT8 *dst,
	unsigned int offset,unsigned int len)
{
    UINT32 spi_address = 0,loop = 0,spi_data = 0;
    UINT32 *dst_data = (UINT32 *)dst;
	set_spi_cs_gpio();
    /*send read cache command(0x3)*/
    REG32_WRITE(SFC_OPCODE,CMD_READ_CACHE&CMD_MASK);

    /*set data,address enable and dummy byte = 1*/
    REG32_WRITE(SFC_CTL,(1<<DATEN_OFFSET)|(1<<ADREN_OFFSET)|((1&DMYCNT_MASK)<<DMYCNT_OFFSET)) ; /* dataen = 1, adren = 1, dmycnt = 1 */
    /*enable spi nandflash and set bit[0:15],column addrss 16bit*/
    set_spi_n_address(SPI_ADDR_CNT_2, 0);

    /*read cache data*/
    if(len < 4)
    {
        spi_address = SPI_NAND_BASE_ADDR +offset;
        *dst = REG8_READ(spi_address);
        udelay(SFC_READ_DELAY);
    }
    else
    {
        for (loop = 0; loop< (len/4); loop++) 
        {
            spi_address = SPI_NAND_BASE_ADDR + loop*4+offset;
            spi_data    = REG32_READ(spi_address);
#ifdef _LITTLE_ENDIAN
            spi_data = SWAPEND32(spi_data);
#endif  

        SN_DEBUG("%s spi_address 0x%x spi_data 0x%x loop %d \n",
            __FUNCTION__,spi_address,spi_data,loop);

            dst_data[loop] = spi_data;
        }
    }
    clr_spi_n_address();
}

void sfc_read_cache_to_mem_cpu(unsigned int block_addr,UINT8 *dst,
	unsigned int offset,unsigned int len)
{
#ifdef	CONFIG_SPI_NAND_USE_GPO_CS
	int loop = 0;
	for (loop = 0; loop< (len/4); loop++) 
    {
    	sfc_read_cache_to_mem_cpu_sec(block_addr,dst+4*loop,offset+4*loop,4);
    }
#else
	sfc_read_cache_to_mem_cpu_sec(block_addr,dst,offset,len);
#endif
}

extern int rtk_sn_str_debug;
int rtk_spi_read_ecc_page(struct mtd_info *mtd, unsigned int page, u_char *data_buf, u_char *oob_buf)
{
    int ret = 0;
    unsigned int block_addr = 0;
    struct spi_nand_chip *this=(struct spi_nand_chip *)mtd->priv;
    block_addr = page/this->block_per_page;

#ifdef CONFIG_MTD_TABLE_TEST
    if(set_read_fail == 1){
        set_read_fail = 0;
        SN_ERR("%s set page %d block %d read fail ecc error case! \n",
				__FUNCTION__,page,block_addr);
        return -1;
    }
#endif

    /*read to cache*/
    if((ret = sfc_read_page_to_cache_b(block_addr,page)) == 0)
    {
        /*read cache to memeroy*/
        sfc_read_cache_to_mem_md(this->support_cache_mode,block_addr,
        	data_buf,0,this->page_size);
        if(oob_buf != NULL)
        {
            sfc_read_cache_to_mem_cpu(block_addr,oob_buf,this->page_size,
					this->oob_size);
        }
    }
    else
    {
        SN_ERR("%s page %d read error!\n",__FUNCTION__,page);
    }
    return ret;
}

int rtk_spi_read_oob(struct mtd_info *mtd, unsigned int page, u_char *data_buf, int len)
{
    int ret = 0;
    unsigned int block_addr = 0;
    struct spi_nand_chip *this=(struct spi_nand_chip *)mtd->priv;
    /*read to cache*/
    block_addr = page/this->block_per_page;
    if((ret = sfc_read_page_to_cache_b(block_addr,page)) == 0)
    {
        /*read cache to memeroy*/
        sfc_read_cache_to_mem_cpu(block_addr,data_buf,this->page_size,len);
    }
    return ret;
}

static int sfc_write_enable(void)
{
    int ret = 0,retry = 0;
    UINT8 spi_1byte_data = 0,tmp = 0;

    do{
		set_spi_cs_gpio();
        /*set write enable command(0x6)*/
        REG32_WRITE(SFC_OPCODE,CMD_WRITE_ENABLE&CMD_MASK);
		    
        /*data address disable*/
        REG32_WRITE(SFC_CTL,0x00000000); /* dataen = 0, adren = 0, dmycnt = 0 */
        udelay(SFC_WRITE_DELAY);
		    
        /*send write enable command*/
        tmp = REG8_READ(SPI_NAND_BASE_ADDR);
        udelay(SFC_WRITE_DELAY);

        /*get write enable status  */
        sfc_get_feature(GET_STATUS_ADDR, &spi_1byte_data);
    }while (((spi_1byte_data&STA_WEL_MASK)== 0)&& (++retry < STATUS_TIMEOUT));

    if (retry == STATUS_TIMEOUT) 
    {
        SN_ERR("%s: timeout set feature: status 0x%x fail. using time out! \n", __FUNCTION__,spi_1byte_data);
        dump_sn_reg(0);
        sfc_reset();  
        //ret = -1;
    }
    return ret;
}

int sfc_set_function(unsigned char address, unsigned char data,unsigned char mask)
{
	int ret = 0;
	UINT8 spi_1byte_data = 0;
	/*write enable*/
	if((ret = sfc_write_enable()) == 0)
	{
		/*set feature*/
		sfc_set_feature(address,data);
		/*wait device ready*/
		if((ret = wait_device_ready(SFC_DELAY)) == 0)
		{
			/*get feature status*/
			sfc_get_feature(address, &spi_1byte_data);
			if((spi_1byte_data&mask) != data) 
			{
				SN_ERR("\%s: set feature: status 0x%x fail.\n", __FUNCTION__,spi_1byte_data);
				ret = - 1;
			}
		}
	}
	return ret;
}

int sfc_unlock_flash(void)
{
    int ret = 0;
    ret = sfc_set_function(GET_BLOCKLOCK_ADDR,0x00,0);
    return ret;
}

int sfc_set_cachemode(struct mtd_info *mtd)
{
    int ret = 0;
    struct spi_nand_chip *this=(struct spi_nand_chip *)mtd->priv;
    UINT8 spi_1byte_data = 0,cache_data = 0;
    SN_DEBUG("\%s: set sfc_get_feature: status 0x%x .cache_bit_offset 0x%x\n", __FUNCTION__,
		this->support_cache_mode,this->cache_bit_offset);
    if((this->support_cache_mode != CACHE_1X)&&(this->cache_bit_offset != 0xF))//emst not need set
    {
        /*get cache status */
        sfc_get_feature(GET_B0_ADDR, &spi_1byte_data);
	 SN_DEBUG("\%s: set sfc_get_feature: status 0x%x .\n", __FUNCTION__,spi_1byte_data);
        /*default close cache mode -->set cache mode*/
        if((spi_1byte_data&(1<<this->cache_bit_offset))== 0)
        {
            cache_data = (spi_1byte_data|(1<<this->cache_bit_offset));
            ret = sfc_set_function(GET_B0_ADDR,cache_data,cache_data);
        }
    }
    return ret;
}

void sfc_set_write_cache_cmd(cache_mode read_cache_mode)
{
    unsigned int cache_cmd = 0,random_cmd = 0;
	set_spi_cs_gpio();
    switch(read_cache_mode)
	{
        case CACHE_1X:
		case CACHE_2X:
            cache_cmd = CMD_PROGRAM_LOAD&CMD_MASK;
			break;
        case CACHE_4X:
            cache_cmd = (CMD_PROGRAM_4XLOAD&CMD_MASK)|(QUAD_WRITE<<DUAL_QUAD_MODE_OFFSET);
			random_cmd = (CMD_PROGRAM_RANDOM&CMD_MASK)|(QUAD_WRITE<<DUAL_QUAD_MODE_OFFSET);
			break;
        case CACHE_4X_IO:
            cache_cmd = (CMD_PROGRAM_4XLOAD_IO&CMD_MASK)|(QUAD_WRITE_IO<<DUAL_QUAD_MODE_OFFSET);
			random_cmd = (CMD_PROGRAM_RANDOM&CMD_MASK)|(QUAD_WRITE_IO<<DUAL_QUAD_MODE_OFFSET);
			break;
        default:
            cache_cmd = CMD_PROGRAM_LOAD&CMD_MASK;
            break;
	}
	REG32_WRITE(SFC_OPCODE,cache_cmd);
	
	/*address, data enable*/
    REG32_WRITE(SFC_CTL,(1<<DATEN_OFFSET)|(1<<ADREN_OFFSET)) ; /* dataen = 1, adren = 1, dmycnt = 0 */
    /*enable spi nandflash and set bit[0:15],column addrss 16bit*/
    set_spi_n_address(SPI_ADDR_CNT_2, 0);
    udelay(SFC_DELAY);

	if((read_cache_mode == CACHE_4X)||(read_cache_mode == CACHE_4X_IO)){
		REG8_WRITE(SPI_NAND_BASE_ADDR,0x12345678);
        udelay(SFC_WRITE_DELAY);
		
		set_spi_cs_gpio();
		REG32_WRITE(SFC_OPCODE,random_cmd);
		/*address and data enable*/
    	REG32_WRITE(SFC_CTL,(1<<DATEN_OFFSET)|(1<<ADREN_OFFSET)) ; /* dataen = 1, adren = 1, dmycnt = 0 */
    	/*enable spi nandflash and set bit[0:15],column addrss 16bit*/
    	set_spi_n_address(SPI_ADDR_CNT_2, 0);
		udelay(SFC_WRITE_DELAY);
	}
}
static void sfc_cpu_write_mem2cache_sec(const UINT8 *buf,
	unsigned int offset,unsigned int len)
{
    UINT32 spi_data = 0, spi_address = 0,loop = 0;
	set_spi_cs_gpio();
    /*send program load command*/
    REG32_WRITE(SFC_OPCODE,CMD_PROGRAM_LOAD&CMD_MASK);


    /*address and data enable*/
    REG32_WRITE(SFC_CTL,(1<<DATEN_OFFSET)|(1<<ADREN_OFFSET)) ; /* dataen = 1, adren = 1, dmycnt = 0 */

    /*enable spi nandflash and set bit[0:15],column addrss 16bit*/
    set_spi_n_address(SPI_ADDR_CNT_2, 0);
    udelay(SFC_WRITE_DELAY);

    /*send data to cache*/
    if(len < 4)
    {
        spi_address = SPI_NAND_BASE_ADDR +offset;
        REG8_WRITE(spi_address,*buf);
        udelay(SFC_WRITE_DELAY);
    }
    else
    {
        for(loop = 0; loop< (len/4); loop++) 
        {
            spi_address = SPI_NAND_BASE_ADDR + loop*4+offset;
#ifdef _LITTLE_ENDIAN
            spi_data = SWAPEND32(*(UINT32*)buf);
#else
            spi_data = *(UINT32*)buf;
#endif  
            REG32_WRITE(spi_address,spi_data);
            buf += 4;
            udelay(SFC_WRITE_DELAY);
        }
    }
	clr_spi_n_address();
}

static void sfc_cpu_write_mem2cache(const UINT8 *buf,
	unsigned int offset,unsigned int len)
{
#ifdef	CONFIG_SPI_NAND_USE_GPO_CS
	int loop = 0;
	for (loop = 0; loop<(len/4); loop++) 
    {
    	sfc_cpu_write_mem2cache_sec(buf+4*loop,offset+4*loop,4);
    }
#else
	sfc_cpu_write_mem2cache_sec(buf,offset,len);
#endif
}

static void sfc_md_write_mem2cache_sec(cache_mode read_cache_mode,unsigned int block_addr,
	const UINT8 *buf,UINT32 offset,UINT32 len)
{
    UINT32 spi_address  = 0;
    spi_address = SPI_NAND_BASE_ADDR + offset; 

    /*set program load command*/
	sfc_set_write_cache_cmd(CACHE_1X); //read_cache_mode CACHE_1X

    //REG32_WRITE(SFC_OPCODE,CMD_PROGRAM_LOAD&CMD_MASK);
    dmac_flush_range(buf, buf+len);
    outer_flush_range(virt_to_phys(buf), virt_to_phys(buf+len));
    /*set dma address*/
    REG32_WRITE(MD_FDMA_DDR_SADDR,virt_to_phys(buf)); //(UINT32)PHYS(buf);
    /*set spi nandflash address*/
    REG32_WRITE(MD_FDMA_FL_SADDR,(UINT32)(spi_address - SPI_NAND_BASE_ADDR));
	                 
    /*set dma mode fix DMA_XFER_LEN-->BYTE_512_XFER_LEN*/
    REG32_WRITE(MD_FDMA_CTRL2, ((FOWAD_MAP<<FMAP_MODE_OFFSET)|(BYTE_512_XFER_LEN<<FDMA_XFER_OFFSET)|(1<<FDMA_DIR_OFFSET)) 
	         | (len & DMA_ADDR_MASK));
	
    //sync();
    //flush_dcache_all(); //sys_dcache_flush((unsigned long)src, len);
    
    /*set dma start*/
    REG32_WRITE(MD_FDMA_CTRL1,(1<<FDMA_GO_OFFSET)|(1<<WRITE_EN_OFFSET));  // go
    while ((REG32_READ(MD_FDMA_CTRL1) & FDMA_GO_MASK) != 0);
    //dump_sn_reg(0);
    clr_spi_n_address();
}

void sfc_md_write_mem2cache(cache_mode read_cache_mode,unsigned int block_addr,
	const UINT8 *buf,UINT32 len)
{
#ifdef	CONFIG_SPI_NAND_USE_GPO_CS
	int loop = 0;
	for (loop = 0; loop< (len/256); loop++) 
    {
    	sfc_md_write_mem2cache_sec(read_cache_mode,
			block_addr,buf+256*loop,256*loop,256);
    }
#else
	sfc_md_write_mem2cache_sec(read_cache_mode,block_addr,buf,0,len);
#endif
}

static int sfc_program_execute(const UINT32 block, const UINT32 page)
{
    int ret = 0;
    UINT32 spi_address = 0;
    UINT8 spi_1byte_data = 0,tmp = 0;
	set_spi_cs_gpio();
    /*set program execute command(0x10)*/
    REG32_WRITE(SFC_OPCODE,CMD_PROGRAM_EXECUTE&CMD_MASK);
    /*set address enable*/
    REG32_WRITE(SFC_CTL,(1<<ADREN_OFFSET)) ; /* dataen = 0, adren = 1, dmycnt = 0 */

    /*enable spi nand and set bit[0:24]-->16bit row address page address[0:5] block address[6:15] */
    set_spi_n_address(SPI_ADDR_CNT_3, 0);
    udelay(SFC_WRITE_DELAY);
    
    /*send address*/
    spi_address = SPI_NAND_BASE_ADDR + ((block & BLOCK_MASK) << 6)+(page & SPI_PAGE_MASK); 
    tmp = REG8_READ(spi_address); //NOTICE-->need do this-->or write fail
    clr_spi_n_address();

    /*wait device  ready*/
    if ((ret = wait_device_ready(SFC_WRITE_DELAY))== 0)
    {
        /*get program status*/
        sfc_get_feature(GET_STATUS_ADDR,&spi_1byte_data);
        if (spi_1byte_data&STA_PFAIL_MASK) 
        {
            ret = -1;
            SN_ERR("%s program fail: block %d page %d status %x\n", __FUNCTION__,block, page,spi_1byte_data);
        }
    }
    return ret;
}

int rtk_spi_write_ecc_page (struct mtd_info *mtd, unsigned int page,
			const u_char *data_buf, const  u_char *oob_buf)
{
    int ret = 0;
    unsigned int block_addr = 0;
    struct spi_nand_chip *this=(struct spi_nand_chip *)mtd->priv;
    block_addr = page/this->block_per_page;
#ifdef CONFIG_MTD_TABLE_TEST
    if(set_write_fail != 0){
        SN_ERR("%s:set page %d block %d write_fail_flag %d error mode!!\n",
				__FUNCTION__, page,block_addr,set_write_fail);
        set_write_fail = set_write_fail > 0 ?(set_write_fail -1):0;
	    return -1;
    }
#endif

    /*write enable*/
    if((ret = sfc_write_enable()) == 0)
    {
        /*write data to cache*/
        sfc_md_write_mem2cache(this->support_cache_mode,block_addr,data_buf,this->page_size);
        if(oob_buf != NULL)
        {
            /*write bad block tag*/
            sfc_cpu_write_mem2cache(oob_buf,this->page_size+this->bad_tag_offset,1);
            /*write magic tag*/
            oob_buf += this->magic_tag_offset;
            sfc_cpu_write_mem2cache(oob_buf,this->page_size+this->magic_tag_offset,4);
        }
        
        /*write cahce to spi nand*/
        ret = sfc_program_execute(block_addr,page);
    }
    return ret;
}

int rtk_spi_write_oob(struct mtd_info *mtd, unsigned int page,const u_char *buf,int len)
{
    int ret = 0;
    unsigned int block_addr = 0;
    struct spi_nand_chip *this=(struct spi_nand_chip *)mtd->priv;
    block_addr = page/this->block_per_page;

    /*write enable*/
    if((ret = sfc_write_enable()) == 0)
    {
        /*write data to cache*/
        sfc_cpu_write_mem2cache(buf,this->page_size+this->bad_tag_offset,1);
        buf += this->magic_tag_offset;
        sfc_cpu_write_mem2cache(buf,this->page_size+this->magic_tag_offset,4);
        /*write cahce to spi nand*/
        ret = sfc_program_execute(block_addr,page);
    }
    return ret;
}

int sfc_erase_block(unsigned int block_addr)
{
    int ret = 0;
    UINT32  spi_address = 0;
    UINT8   spi_1byte_data = 0,tmp  = 0;

    /*write enable*/
    if((ret = sfc_write_enable()) == 0)
    {
        spi_address = SPI_NAND_BASE_ADDR + ((block_addr & BLOCK_MASK) << BLOCK_OFFSET); 
#ifdef _LITTLE_ENDIAN
        spi_address = spi_address^0x3;
#endif
        set_spi_cs_gpio();
        /*set erase command*/ 
        REG32_WRITE(SFC_OPCODE,CMD_ERASE&CMD_MASK);
        
        /*address enable*/
        REG32_WRITE(SFC_CTL,(1<<ADREN_OFFSET)); /* dataen = 0, adren = 1, dmycnt = 0 */
        udelay(SFC_WRITE_DELAY);
        
        /*send erase address [0:23] */
        set_spi_n_address(SPI_ADDR_CNT_3, 0);
        tmp = REG8_READ(spi_address);
        
        /*wait device ready*/
        if ((ret = wait_device_ready(SFC_ERASE_DELAY))== 0)
        {
            /*get erase status*/
            sfc_get_feature(GET_STATUS_ADDR,&spi_1byte_data);
            if (spi_1byte_data&STA_EFAIL_MASK) 
            {
                ret = -1;
                SN_ERR("%s erase block %d fail: status %x\n", __FUNCTION__,block_addr, spi_1byte_data);
            }
        }
        else
        {
            SN_ERR("%s erase block %d fail! \n",__FUNCTION__,block_addr);
            dump_sn_reg(0);
        }
    }
    return ret;
}

int rtk_spi_erase_block(struct mtd_info *mtd,unsigned int block)
{
    int ret = 0;
#ifdef CONFIG_MTD_TABLE_TEST
    if(set_erase_fail != 0){
        SN_ERR("%s: set block %d erase fail!!\n", __FUNCTION__, block);
        set_erase_fail = 0;
        return -1;
    }
#endif
    ret = sfc_erase_block(block);
    return ret;
}

void suspend_sn_register(struct mtd_info *mtd)
{
    int loop = 0;
    struct spi_nand_chip *this=(struct spi_nand_chip *)mtd->priv;
    if(this->sn_reg_arry == NULL){
        this->sn_reg_arry = kmalloc(sizeof(int)*(SAVE_SN_REGNUM), GFP_KERNEL);
    }
    
    if(this->sn_reg_arry ==  NULL){
        SN_ERR("%s malloc sn regsiter error !\n",__FUNCTION__);
        return;
    }
	
    for(loop = 0; loop < (SAVE_SN_REGNUM -2); loop++){
        this->sn_reg_arry[loop] = REG32_READ(SFC_REG_BASE + loop*4);
    }
    this->sn_reg_arry[loop] = REG32_READ(SF_32MB_EN);
    loop ++;
    this->sn_reg_arry[loop] = REG32_READ(SPI_NAND_0);
}


void resume_sn_register(struct mtd_info *mtd)
{
    int loop = 0;
    struct spi_nand_chip *this=(struct spi_nand_chip *)mtd->priv;
    for(loop = 0; loop < (SAVE_SN_REGNUM -2); loop++){
        REG32_WRITE(SFC_REG_BASE + loop*4,this->sn_reg_arry[loop]);
    }

    REG32_WRITE(SF_32MB_EN, this->sn_reg_arry[loop]);
    loop ++;
    REG32_WRITE(SPI_NAND_0, this->sn_reg_arry[loop]);
}
