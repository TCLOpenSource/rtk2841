/***********************************************************************************************
IBT(initial block table):
	 logical block map physical block skip bad block (exist from factory produce bad block)
	 create ibt to nand ,if the first time boot
	 build  ibt  to ram, by read from nand

BBT(bad block table):
	ibt logical map good physical block,run-time may be bad block, use bbt reamp region block instead bad block
	create or update bbt table to nand , if exist run-time ibt map good physical become bad block
	build bbt  to ram, by read form nand

RBT(run-time block table):
	bbt remap region not enough, use rbt 
	rbt collect the block(ibt map good physical become bad block) map to bad block
******************************************************************************************/
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rtk_nand.h>


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

#define DEBUG_SET_LEVEL(x)   static int nand_debug_level = x

#define NAND_ERR(...)                                        \
do {                                                    \
    if (nand_debug_level >= DEBUG_LEVEL_ERR) {                     \
        PRINT(__VA_ARGS__);                             \
    }                                                   \
} while (0)

#define NAND_INFO(...)                                       \
do {                                                    \
    if (nand_debug_level >= DEBUG_LEVEL_INFO) {                    \
        PRINT(__VA_ARGS__);                             \
    }                                                   \
} while (0)

#define NAND_DEBUG(...)                                      \
do {                                                    \
    if (nand_debug_level >= DEBUG_LEVEL_DEBUG) {                   \
        PRINT(__VA_ARGS__);                             \
    }                                                   \
} while (0)
DEBUG_SET_LEVEL(DEBUG_LEVEL_INFO);

extern int I_KERNEL_RBA_PERCENT ;
extern int RBA_PERCENT;
extern int I_BOOTCODE_RBA_PERCENT;
extern void mark_as_badblock(struct mtd_info *mtd,int bad_block);
extern int rtk_block_isbad(struct mtd_info *mtd, u16 chipnr, loff_t ofs);

int init_ibt_info(struct mtd_info *mtd)
{
	struct nand_chip *this = mtd->priv; 
	uint64_t div_res = 0,result = 0;
	/*initialize bootcode RBA-->for bootcode buffer*/
	this->I_BOOTCODE_RBA_PERCENT = I_BOOTCODE_RBA_PERCENT;		//default value 10% of bootcode-area 
	NAND_INFO("[**Default**]IBT-RBA percentage of bootcode-area: %d%%\n", this->I_BOOTCODE_RBA_PERCENT); 
 	div_res = this->bootcode_size;
	do_div(div_res,this->block_size);
 	result = div_res;
 	result*=this->I_BOOTCODE_RBA_PERCENT;
 	do_div(result,100);
	this->I_BOOTCODE_RBA = result;
	NAND_INFO("[%s]I_BOOTCODE_RBA_PERCENT %d%%, I_BOOTCODE_RBA = %d\n",\
		   __FUNCTION__,this->I_BOOTCODE_RBA_PERCENT, this->I_BOOTCODE_RBA); 

	this->ibt_len = this->block_num;
	if((this->ibt= kmalloc(sizeof(IB_t)*this->ibt_len, GFP_KERNEL)) ==  NULL){
		printk("%s: No enough memory ibt 0x%x \n",__FUNCTION__,sizeof(IB_t)*this->ibt_len);
		return -1;
	}
	return 0;
}

int init_bbt_info(struct mtd_info *mtd)
{
	struct nand_chip *this = mtd->priv; 
	uint64_t div_res = 0,result = 0;
	/*initialize Kernel RBA-->for kernel buffer*/
	div_res = this->device_size;
	do_div(div_res,this->block_size);
	this->I_KERNEL_RBA_PERCENT   = I_KERNEL_RBA_PERCENT;		//default value 2% device_size
	NAND_INFO("[**Default**]IBT-RBA percentage of kernel-area: %d%%\n",this->I_KERNEL_RBA_PERCENT);
	result = div_res;
 	result*=this->I_KERNEL_RBA_PERCENT;
 	do_div(result,100);
 	this->I_KERNEL_RBA = result;
	NAND_INFO("[%s]I_KERNEL_RBA_PERCENT %d%%, I_KERNEL_RBA = %d\n",\
		__FUNCTION__,this->I_KERNEL_RBA_PERCENT, this->I_KERNEL_RBA);

	/*initialize BBT information*/
	mtd->u32RBApercentage    = this->RBA_PERCENT = RBA_PERCENT;		//default value 4% device_size
	NAND_INFO("[**Default**]RBA percentage: %d%%\n",this->RBA_PERCENT);
 
	div_res = this->device_size;
	do_div(div_res,this->block_size);
	result = div_res;
	result*=this->RBA_PERCENT;
 	do_div(result,100);
	this->bbt_len = result;

	if(mtd->u32RBApercentage){
		mtd->u32RBApercentage = this->RBA_PERCENT;
	}
	
	if((this->bbt = kmalloc(sizeof(BB_t)*this->bbt_len, GFP_KERNEL)) ==  NULL){
		NAND_ERR("%s: Error, no enough memory for BBT\n",__FUNCTION__);
		return -1;
	}
	
	NAND_INFO("[%s]mtd->u32RBApercentage %d%%, bbt len = %d\n",__FUNCTION__,mtd->u32RBApercentage, this->bbt_len);   
	return 0;
}

int init_table_info(struct mtd_info *mtd)
{
	struct nand_chip *this = mtd->priv; 
	int block_pos = 0;
	if(init_ibt_info(mtd) <0){
		return -1;
	}
	
	if(init_bbt_info(mtd) <0){
		return -1;
	}

	/*init rbt */
	this->rbt =  NULL;
	this->use_rbt_num = 0;
	
	/*initialize ibt scan block start and end*/
	block_pos = (this->bootcode_size + this->block_size - 1)/this->block_size;
	this->bootcode_start_log_block = IBT_SCAN_START_BLOCK;
	this->bootcode_end_log_block   = block_pos - this->I_BOOTCODE_RBA;

	block_pos = (this->secstore_start + this->secstore_size + this->block_size - 1)/this->block_size;
	this->kernel_start_log_block   = block_pos;
	this->kernel_end_log_block     = this->block_num -this->bbt_len -this->I_KERNEL_RBA;
	NAND_DEBUG("%s bootcode_start_log_block %d bootcode_end_log_block %d kernel_start_log_block %d kernel_end_log_block %d\n",
		__FUNCTION__,this->bootcode_start_log_block,this->bootcode_end_log_block,
		this->kernel_start_log_block, this->kernel_end_log_block);
}

void dump_ibt(struct mtd_info *mtd)
{
	int ibt_id = 0,loop =0;
	struct nand_chip *this = mtd->priv; 
	printk("%s dump ibt table content len %d \n",__FUNCTION__,this->ibt_len); 
	for(ibt_id = IBT_SCAN_START_BLOCK; ibt_id < this->ibt_len; ibt_id++)
	{
		printk("[%d][0x%04x,0x%04x,0x%04x,0x%04x]\t",loop,this->ibt[ibt_id].src_die,this->ibt[ibt_id].src_block,
			this->ibt[ibt_id].dst_die,this->ibt[ibt_id].dst_block);
		loop++;
		if(loop%8 == 0){
			printk("\n");
		}    
	}  
	printk("\n");
}

void dump_bbt(struct mtd_info *mtd)
{
	int rba_id = 0,loop = 0;
	struct nand_chip *this = mtd->priv; 
	printk("%s table len %d current use bbt num %d free bbt num %d\n",__FUNCTION__,this->bbt_len,
		this->use_rba_num,this->free_rba_num);  
	for( rba_id = 0; rba_id<this->bbt_len; rba_id++)
	{
		printk("[%d] [%d, %u, %d, %u]\t",loop,this->bbt[rba_id].BB_die,this->bbt[rba_id].bad_block,
			this->bbt[rba_id].RB_die,this->bbt[rba_id].remap_block);
		loop++;
		if(loop%8 == 0){
			printk("\n");
		}
	}
	printk("\n");
}

void dump_rbt(struct mtd_info *mtd)
{
	int loop = 0,rbt_id = 0;
	struct nand_chip *this = mtd->priv; 
	printk("%s table len %d current use rbt num %d \n",__FUNCTION__,this->rbt_len,this->use_rbt_num);
	if(this->rbt != NULL){
		for(rbt_id = 0; rbt_id <this->rbt_len; rbt_id++)
		{
			printk("[%d] [%d, %u, %d, %u]\t",loop,this->rbt[rbt_id].src_die,this->rbt[rbt_id].bad_block,
				this->rbt[rbt_id].dst_die,this->rbt[rbt_id].collect_block);
			loop++;
			if(loop%8 == 0){
				printk("\n");
			}
		}
		printk("\n");
	}
}

/*******************************************************************************************
 scan table(ibt/bbt/rbt) block region, get block status and free block count
 start: BI_BLOCK_START end:IBT_SCAN_START_BLOCK - 1 frist_boot = 1 means frist-time nand boot
 eg: first-time block 1~5 tag  all good block tag are 0xFF means frist boot
 run-time: log_block1-log_block2 tag:BBT log_block3-log_block4 tag:IBT 
*******************************************************************************************/
int init_bi_table(struct mtd_info *mtd)
{
	int loop = 0,block_id = 0,chipnr = 0,page = 0, tag_count = 0;
	struct nand_chip *this = mtd->priv;
	u_char *oob_buf = NULL;
	memset(this->g_oobbuf,0xFF,this->oob_size);
	oob_buf = this->g_oobbuf;
	
	this->bi_table_block_num = IBT_SCAN_START_BLOCK - BI_BLOCK_START; 
	if((this->bi_table =  kmalloc(this->bi_table_block_num*sizeof(struct block_info),GFP_KERNEL)) ==  NULL){
		NAND_ERR("%s line:%d malloc table block info error! \n",__FUNCTION__,__LINE__);
		return -1;
	}
	
	this->active_chip = chipnr;	
	block_id = BI_BLOCK_START;
	for(loop = 0; loop < this->bi_table_block_num;loop++){
		this->bi_table[loop].phy_block = block_id;
		page = block_id*this->ppb;
		if(this->read_oob (mtd, chipnr, page, this->oob_size, oob_buf) == 0){
			this->bi_table[loop].block_tag = oob_buf[0];
		}else{
			this->bi_table[loop].block_tag = BAD_BLOCK; //error tag
		}
		if((this->bi_table[loop].block_tag == BBT_TAG)||(this->bi_table[loop].block_tag == IBT_TAG)){
			tag_count++;
		}
		block_id++;
		NAND_DEBUG("%s loop %d block id %d block_tag 0x%x\n",__FUNCTION__,
			loop,this->bi_table[loop].phy_block,this->bi_table[loop].block_tag);
	}
	
	if(tag_count == 0){
		this->frist_boot = 1;
		NAND_INFO("%s nand is frist time boot \n",__FUNCTION__);
	}
	return 0;
}

void update_bittable(struct mtd_info *mtd, int bitable_id, u16 block_tag)
{
	struct nand_chip *this = mtd->priv;
	this->bi_table[bitable_id].block_tag = block_tag;
}

int find_block_in_bitable(struct mtd_info *mtd, u_char block_tag,int index)
{
	struct nand_chip *this = mtd->priv;
	int bitable_id = this->bi_table_block_num, loop = 0, count = index + 1;
	for(loop = 0; loop < this->bi_table_block_num; loop++)
	{		
		if(this->bi_table[loop].block_tag == block_tag){
			count--;
			NAND_DEBUG("%s find loop %d count %d tag 0x%x phy_block %d \n",__FUNCTION__,loop,count,block_tag,this->bi_table[loop].phy_block);
			if(count == 0){
				bitable_id = loop;
				NAND_DEBUG("%s finally find bitable_id %d tag 0x%x phy_block %d \n",__FUNCTION__,bitable_id,block_tag,this->bi_table[bitable_id].phy_block);
				break;
			}
		}
	}
	
	return bitable_id;
}

int check_buffer_empty(u_char *buff, int buf_size)
{
	int ret = 0,loop = 0;
	for(loop = 0; loop < buf_size; loop++)
	{
		if(buff[loop]!= 0xFF){
			ret = -1;
			break;
		}
	}
	return ret;
}

int write_page_content(struct mtd_info *mtd,unsigned int page_no,u_char * buf,
 	unsigned int page_num, u_char tag)
{
	int ret = 0, page_id = 0,write_page_num = 0, block_addr = 0,chipnr = 0,block_id = 0,block_num = 0;
	struct nand_chip *this = mtd->priv;
	u_char *oob_buf = NULL;

	this->active_chip = chipnr;
	block_num   = (page_num + this->ppb - 1)/this->ppb;
	NAND_DEBUG("%s page_no %d page_num %d tag 0x%x block_num %d\n",__FUNCTION__, 
		page_no,page_num,tag,block_num);
	
	for(block_id = 0; block_id < block_num; block_id++)
	{
		/*earse block*/
		block_addr  = page_no/this->ppb;
		NAND_DEBUG("%s erase block %d  \n",__FUNCTION__, block_addr);
		if((ret = this->erase_block(mtd,chipnr,block_addr*this->ppb)) == 0){  
			/*write page content*/
			write_page_num =  page_num >= this->ppb?this->ppb:page_num;
			NAND_DEBUG("%s write page_no %d write_page_num %d \n",__FUNCTION__, page_no,write_page_num);
			for(page_id = 0; page_id < write_page_num; page_id++)
			{
				memset(this->g_oobbuf,0xFF,this->oob_size);	
				if(0xFF != tag){
					this->g_oobbuf[0]= tag;
					oob_buf = this->g_oobbuf;
				}
				if(check_buffer_empty(buf,this->page_size)== 0){
					NAND_DEBUG("%s skip page %d page_id %d write buffer\n",__FUNCTION__,(page_no+page_id),page_id);
					buf += this->page_size;
				}else{
					if((ret = this->write_ecc_page(mtd, this->active_chip,(page_no+page_id),buf, oob_buf,0)) == 0){
						buf += this->page_size;
					}else{
						ret = -1;
						NAND_ERR("%s line:%d write page %d error  \n",__FUNCTION__,__LINE__,(page_no+page_id));
						break;
					}
				}
			}
		}else{
			NAND_ERR("%s line:%d erase block error %d !\n",__FUNCTION__, __LINE__,block_addr);
		}
		
		if(ret != 0){
			break;
		}else{
			page_no = page_no + write_page_num;
			page_num = page_num - write_page_num;
		}
	}
	return ret;
}

int write_table_content(struct mtd_info *mtd, unsigned int page_no, u_char *buf, int buf_len, u_char tag)
{
	int ret = 0, page_num = 0;
	struct nand_chip *this = mtd->priv;
	u_char *temp_buf = NULL;
	page_num = (buf_len + this->page_size-1 )/this->page_size;
	temp_buf = kmalloc(page_num*this->page_size, GFP_KERNEL);
    
	if(temp_buf!= NULL){
		memset(temp_buf,0xFF,page_num*this->page_size);
		memcpy(temp_buf,buf, buf_len);
		if((ret = write_page_content(mtd,page_no,temp_buf,page_num,tag)) == 0){
			NAND_INFO("%s write page %d num %d successful! \n",__FUNCTION__,page_no,page_num);    
		}
		kfree(temp_buf);  
	}else{
		NAND_ERR("%s line:%d malloc size fail 0x%x! \n",__FUNCTION__,__LINE__,(page_num*this->page_size));
		ret = -1;
	}
	return ret;
}

/*************************************************************************************************
 scan ibt block region:  src_block: logical block dst_block:physical block
 eg: scan log block: 8-10 phy block:8 good block 9 bad block 10-11 good block log block 9 phy block 10
****************************************************************************************************/
void construct_ibt_info(struct mtd_info *mtd,unsigned int start_log_block,
		unsigned int end_log_block,unsigned int limit_phy_block)
{
	int log_block_id = 0,phy_block_id = start_log_block;
	struct nand_chip *this = mtd->priv;
	this->active_chip = 0;
	NAND_INFO("%s start_log_block %d end_log_block %d limit_phy_block %d\n",
     __FUNCTION__, start_log_block,end_log_block,limit_phy_block);

	for(log_block_id = start_log_block; log_block_id<= end_log_block; log_block_id++)
	{
		this->ibt[log_block_id].src_block = log_block_id;
		while(phy_block_id<limit_phy_block)
		{
			if(rtk_block_isbad(mtd,this->active_chip,phy_block_id*this->block_size) == 0){
				NAND_DEBUG("%s log_block_id %d phy_block_id %d \n",__FUNCTION__,log_block_id,phy_block_id);
				break;
			}
			phy_block_id++;  
    	}

		if(phy_block_id == limit_phy_block){
			NAND_ERR("%s waring!! not enough limit_block,log_block_id %d phy_block_id %d \n",__FUNCTION__,log_block_id,phy_block_id);
			break;
		}else{
			this->ibt[log_block_id].src_die   = this->active_chip;
			this->ibt[log_block_id].dst_die	  = this->active_chip;
			this->ibt[log_block_id].dst_block = phy_block_id; 
			
			phy_block_id++;
    	} 
  	}      
}

void init_ibt_to_ram(struct mtd_info *mtd)
{
	int loop = 0,ibt_scan_limit = 0;
	struct nand_chip *this = mtd->priv;

	for (loop = 0; loop < this->ibt_len; loop++)
	{
		this->ibt[loop].src_die   = SRC_DIE_INIT;
		this->ibt[loop].src_block = SRC_INIT;
		this->ibt[loop].dst_die   = DST_DIE_INIT;
		this->ibt[loop].dst_block = DST_INIT;
	}
  
	/*create ibt for bootcode-area*/	
	NAND_DEBUG("Starting create bootcode area IBT start block: %d end block %d\n",
		this->bootcode_start_log_block,this->bootcode_end_log_block); 
	construct_ibt_info(mtd, this->bootcode_start_log_block, this->bootcode_end_log_block,
      this->kernel_start_log_block);

	/*create ibt for kernel-area*/
	NAND_DEBUG("Starting create kernel area IBT start block %d end block %d \n",
	this->kernel_start_log_block,this->kernel_end_log_block);
	ibt_scan_limit = this->block_num -this->bbt_len;
 	construct_ibt_info(mtd, this->kernel_start_log_block, this->kernel_end_log_block, ibt_scan_limit);
}

/*******************************************************************************************
 scan bbt block region: 
 start index = 0 -->find remap region last good block  index = 1-->find remap region last -1 good block
eg: block region 960-1023, 1023: good block 1022: bad block 1021:good block 1020:bad block 1019:good block
index 0 -->1023 index 1-->1021 index 2 -->1019
*******************************************************************************************/
void init_bbt_to_ram(struct mtd_info *mtd)
{
	int block_id = 0,loop = 0,start_block = 0;
	struct nand_chip *this = mtd->priv;
	start_block = this->block_num - this->bbt_len;
	this->active_chip = 0;
  
	/*initialize bbt array*/
	for(loop = 0; loop <this->bbt_len; loop++)
	{
		this->bbt[loop].BB_die      = BB_DIE_INIT;
		this->bbt[loop].bad_block   = BB_INIT;
		this->bbt[loop].RB_die      = RB_DIE_INIT;
		this->bbt[loop].remap_block = RB_INIT;
	}

	/*add good block to bbt*/
	loop = 0;
	for(block_id = this->block_num -1; block_id >=start_block;block_id--)
	{
		if(rtk_block_isbad(mtd,this->active_chip,block_id*this->block_size) == 0){
			this->bbt[loop].RB_die      = this->active_chip;
			this->bbt[loop].remap_block = block_id;
 			loop++;
		}
	}      
	RTK_FLUSH_CACHE((unsigned long)this->bbt, sizeof(BB_t)*this->bbt_len);
}

/*******************************************************************************************
 create  ibt/bbt table content to nand £¬frist time need block number is write ok
*******************************************************************************************/
int create_table_to_nand(struct mtd_info *mtd,u_char tag)
{
	int loop = 0, page_no = 0,table_size = 0,block_num = 0,bitable_id = 0;
	struct nand_chip *this = mtd->priv;
	u_char * table_content =  NULL;
	/* init table content to ram*/
	if(tag == IBT_TAG){
		init_ibt_to_ram(mtd);
		block_num     = IBT_BLOCK_NUM;
		table_content = (u_char *)this->ibt;
		table_size    = sizeof(IB_t)*this->ibt_len;
	}else if(tag == BBT_TAG){
		init_bbt_to_ram(mtd);
		block_num     = BBT_BLOCK_NUM;
		table_content = (u_char *)this->bbt;
		table_size    = sizeof(BB_t)*this->bbt_len;
	}
	
	for(loop = 0; loop < block_num;loop++)
	{
		/*find first free block in the bi table to write*/
		bitable_id = find_block_in_bitable(mtd,0xFF,0);
		NAND_INFO("%s bitable_id %d in table!\n", __FUNCTION__,bitable_id);
		if(bitable_id >= this->bi_table_block_num){
			NAND_ERR("%s not enough block tag 0x%x in the bitable!\n", __FUNCTION__,tag);
			return -1;
		}
		
		/*write table content to nand*/
		page_no = this->bi_table[bitable_id].phy_block*this->ppb;
		/*update bi table information*/
		if(write_table_content(mtd, page_no, table_content, table_size, tag)<0){
			update_bittable(mtd, bitable_id, BAD_BLOCK);
		}else{
			update_bittable(mtd, bitable_id, tag);
		}
	}
	return 0;	
}

int read_page_content(struct mtd_info *mtd,unsigned int page_no,u_char * buf,
 unsigned int page_num, u_char tag)
{
	int ret = 0, page_id = 0, chipnr = 0;
	struct nand_chip *this = mtd->priv;
	this->active_chip = chipnr;
	NAND_DEBUG("%s page_no %d page_num %d tag 0x%x\n",__FUNCTION__,page_no,page_num,tag);
 	for(page_id = 0; page_id < page_num; page_id++)
	{
		memset(this->g_oobbuf,0xFF,this->oob_size);
		memset(this->g_databuf,0xFF,this->page_size);
		if((ret = this->read_ecc_page(mtd,this->active_chip,(page_no+page_id), this->g_databuf, this->g_oobbuf)) == 0){
			if(0xFF != tag){
				if(this->g_oobbuf[0] != tag){
					ret = -1;
					NAND_ERR("%s line:%d read page %d read_tag 0x%x ok_tag 0x%x\n",__FUNCTION__,__LINE__,
						(page_no+page_id),this->g_oobbuf[0],tag); 
					break;
				}
			}
			memcpy(buf+page_id*this->page_size, this->g_databuf, this->page_size);
		}else{
			ret = -1;
			NAND_ERR("%s line:%d read page %d error\n",__FUNCTION__,__LINE__,(page_no+page_id));	
  			break;
		}
	}
	return ret;
}

int read_table_content(struct mtd_info *mtd,unsigned int page_no, u_char *buf, int buf_len, int tag)
{
	int ret = 0,page_num = 0;
	struct nand_chip *this = mtd->priv;
	u_char *temp_buf = NULL;
	page_num = (buf_len + this->page_size-1 )/this->page_size;
	temp_buf = kmalloc(page_num*this->page_size, GFP_KERNEL);

	if(temp_buf != NULL){
		if((ret = read_page_content(mtd,page_no,temp_buf,page_num,tag)) == 0){
			memcpy(buf, temp_buf, buf_len);   
			NAND_INFO("Read page %d page_num %d successful!\n",page_no,page_num); 
		}
		kfree(temp_buf);
	}else{
		NAND_ERR("%s line:%d malloc size 0x%x fail! \n",__FUNCTION__,__LINE__,(page_num*this->page_size));
		ret = -1;
	}
	return ret;
}

/*******************************************************************************************
 load table ibt/bbt table from nand:  every table block num >=2
   block index  0 -->read ok just return, read fail goto block index 1
   block index  1 -->read ok,first recovery block index 0,erase and write content, recovery ok,return
   			if recovery block index 0 fail, find free block and write content, and return
*******************************************************************************************/
int load_table_from_nand(struct mtd_info *mtd,u_char tag, int is_rbt)
{
	int ret = 0,loop = 0,bitable_id = 0,page_no = 0,index = 0,table_size = 0;
	int pre_bitable_id = 0,table_block_num = 0,offset_page = 0;
	u_char *table_content = NULL, *tmp_buf = NULL;
	struct nand_chip *this = mtd->priv;
	
	if(tag == IBT_TAG){
		table_block_num = IBT_BLOCK_NUM;
		table_content   = (u_char *)this->ibt;
		table_size      = this->ibt_len*sizeof(IB_t);
	}else if(tag == BBT_TAG){
		table_block_num = BBT_BLOCK_NUM;
		if(is_rbt == 1){
			table_content = (u_char *)this->rbt;
			table_size = this->rbt_len*sizeof(RB_t);
		}else{
			table_content = (u_char *)this->bbt;
			table_size = this->bbt_len*sizeof(BB_t);
		}
		offset_page = (sizeof(BB_t)*this->bbt_len + this->page_size-1 )/this->page_size;
	}

	for(loop = 0; loop < table_block_num; loop++)
	{
		/*get table tag block id eg: ibt block id*/
		bitable_id = find_block_in_bitable(mtd,tag,index);
		if(bitable_id >= this->bi_table_block_num){
			NAND_ERR("%s not find tag 0x%x in bi table\n", __FUNCTION__,tag);
			return -1;
		}
		
		page_no = this->bi_table[bitable_id].phy_block*this->ppb;
		if(is_rbt == 1){
  			page_no = page_no + offset_page;
 		}
  	
		/*read page content from nand*/
		if((ret = read_table_content(mtd,page_no,table_content,table_size,tag))== 0)
 		{
			if(index != 0){
  				/*cur index read content ok,pre index read fail,recovery pre-index*/
  				NAND_INFO("%s enter recovery mode read page %d ok! \n",__FUNCTION__,page_no);
  				
  				/*read bbt and rbt table content*/
  				if(tag == BBT_TAG){
  					table_size  = offset_page*this->page_size + this->rbt_len*sizeof(RB_t);
  					if((tmp_buf = kmalloc(table_size, GFP_KERNEL)) == NULL){
  						NAND_ERR("%s line:%d malloc buf size 0x%x error!\n",__FUNCTION__,__LINE__,table_size);
  						return 0; //cur index return ok
  					}else{
  						memset(tmp_buf,0xFF,table_size);
  						if((ret = read_table_content(mtd,page_no,tmp_buf,table_size,tag)) == 0){
  							table_content = tmp_buf;
  						}
  					}
  				}
				
  				/*recovery the before block --> block read error, erase block maybe ok*/
				page_no = this->bi_table[pre_bitable_id].phy_block*this->ppb;
  				if(ret == 0){
  					if(write_table_content(mtd, page_no, table_content, table_size, tag)<0){
  						/*find the next free block to recovery table content*/
  						bitable_id = find_block_in_bitable(mtd,0xFF,0);
  						if(bitable_id < this->bi_table_block_num){
  							page_no = this->bi_table[bitable_id].phy_block*this->ppb;
  							write_table_content(mtd, page_no, table_content, table_size, tag);
  						}else{
  							NAND_INFO("%s not free block to recovery tag 0x%x \n",__FUNCTION__,tag);
  						}
  					}
  				
  					if(tmp_buf != NULL){
  						kfree(tmp_buf);
  					}
  				}
				ret = 0;
  			}
  			break; /*read tag ok break*/
  		}else{
			pre_bitable_id = bitable_id;
			index++;  /*read next tag block*/
  		}
	}
	
	if(tmp_buf != NULL){
		kfree(tmp_buf);
	}
	return ret;  
}

void get_rba_block_info(struct mtd_info *mtd)
{
	int rba_id = 0,free_rba_num = 0, use_rba_num = 0;
	struct nand_chip *this = mtd->priv;
	for(rba_id = 0; rba_id < this->bbt_len; rba_id++)
	{
 		if(this->bbt[rba_id].remap_block != RB_INIT)
		{
			if(this->bbt[rba_id].bad_block == BB_INIT){
				free_rba_num++;
			}else{
				use_rba_num++;
			}      
		}
	}

	this->use_rba_num  = use_rba_num;
	this->free_rba_num = free_rba_num;
	if(this->use_rba_num  == 0){
		NAND_INFO("Congratulation!! No BBs in this Nand. \n");
	}
}

int init_nand_table(struct mtd_info *mtd,u_char tag)
{
	int ret = 0;
	struct nand_chip *this = mtd->priv;
	if(this->frist_boot == 1){
		ret = create_table_to_nand(mtd,tag);
	}else{
		ret = load_table_from_nand(mtd,tag,0);
	}
	
	if((ret == 0)&&(tag == BBT_TAG)){
		get_rba_block_info(mtd);
	}
	return ret;
}

void get_free_rbt_num(struct mtd_info *mtd)
{
	int use_rbt_num = 0, rbt_id = 0;
	struct nand_chip *this = mtd->priv;
	for(rbt_id = 0; rbt_id < this->rbt_len; rbt_id++)
	{
 		if((this->rbt[rbt_id].bad_block != RBB_INIT)
      	&&(this->rbt[rbt_id].collect_block != RCB_INIT)){
			use_rbt_num++;
		}
	}
	this->use_rbt_num = use_rbt_num;
	NAND_INFO("%s use rbt use_rbt_num %d \n",__FUNCTION__,this->use_rbt_num);
}

int init_rbt_table(struct mtd_info *mtd)
{
	int ret  = 0,rbt_table_size = 0;
	struct nand_chip *this = mtd->priv;
	this->rbt_len   = this->bbt_len;  //max rbt_len = bbt_len
	rbt_table_size  = sizeof(RB_t)*this->rbt_len;
	if((this->rbt = kmalloc(rbt_table_size, GFP_KERNEL)) == NULL){
		NAND_ERR("%s: line:%d Error, no enough memory for RBT table \n",__FUNCTION__,__LINE__);
		return -1;
	}

	memset(this->rbt, 0xFF, rbt_table_size); 
	if((ret = load_table_from_nand(mtd,BBT_TAG,1))<0){
		return ret;
	}  

	/*get current rbt number*/
	if(ret == 0){
		get_free_rbt_num(mtd);
	} 
	
	return ret;
}

int init_log2phy_table(struct mtd_info *mtd)
{
	int block_id = 0;
	struct nand_chip *this = mtd->priv;
	if((this->log2phy_table = kmalloc(this->block_num*sizeof(int), GFP_KERNEL)) == NULL){
		NAND_ERR("%s line:%d malloc log2phy table error!\n",__FUNCTION__,__LINE__);
		return -1;
	}
	for(block_id = 0; block_id < this->block_num; block_id++)
	{
		this->log2phy_table[block_id] = INVALID_BLOCK_ID;
	}
	return 0;
}

int init_table(struct mtd_info *mtd)
{
	int ret = 0;
	struct nand_chip *this = mtd->priv;
	
	/*init common information*/
	if((ret = init_table_info(mtd)) <0){
		return ret;
	}
	
	/*init table block information*/
	if((ret = init_bi_table(mtd))<0){
		return ret;
	}

	/*init bbt information*/
	if((ret = init_nand_table(mtd,BBT_TAG))<0){
		NAND_ERR("%s load BBT error! \n",__FUNCTION__);
		return ret;
	}
	
	/*init ibt information*/
	if((ret = init_nand_table(mtd,IBT_TAG))<0){
		NAND_ERR("%s load IBT error! \n",__FUNCTION__);
		return ret;
	}
	
	/*init rbt information -->not exist free block in bbt*/
	if(this->free_rba_num == 0){
		ret = init_rbt_table(mtd);
	}
	
	/*init log2phy table*/
	ret = init_log2phy_table(mtd);
	return ret;
}

void de_init_table(struct mtd_info *mtd)
{
	struct nand_chip *this = mtd->priv; 
	if(this->bi_table != NULL){
		kfree(this->bi_table);
	}
	if(this->ibt != NULL){
		kfree(this->ibt);
	}

	if(this->bbt != NULL){
		kfree(this->bbt);
	}
	
	if(this->rbt != NULL){
		kfree(this->rbt);
	}
	
	if(this->log2phy_table != NULL){
		kfree(this->log2phy_table);
	}
}


/*************************************************************************************************************************
 find the first no-map logical block nearest cur logical block , scan from start no-map  logical block to cur logical block
eg: cur-logblock = 8   first no map block:5  from 5 to 8, map(5,5) (6,6) (7,7) (8,8)  no exist bad block
     cur-logblock = 11  exist map 5-8 first no map block:from 9 to 11,  map (9,9) (10,11) (11,12) exist bad block 10     
*******************************************************************************************************************************/
int get_phyblock_from_bootcode_table(struct mtd_info *mtd,int logblock)
{
	int phy_block_id = INVALID_BLOCK_ID,log_block_id = 0;
	struct nand_chip *this = mtd->priv;
	this->active_chip  = 0;
 
 	/*find first map block  nearest current logical block */
	log_block_id = logblock > this->bootcode_start_log_block ?(logblock -1):logblock;
	while(log_block_id >= this->bootcode_start_log_block)
	{
		if(this->log2phy_table[log_block_id]!= INVALID_BLOCK_ID){
			phy_block_id = this->log2phy_table[log_block_id];
			break;
		}
		log_block_id--;
	}

	NAND_DEBUG("%s find first log_block_id %d phy_block_id %d \n",__FUNCTION__,log_block_id,phy_block_id);
	if(phy_block_id == INVALID_BLOCK_ID){ 
		/*no any logical block map physical block in log2phy table */
		phy_block_id = this->bootcode_start_log_block;
		log_block_id = this->bootcode_start_log_block;
	}else{
		/*frist unmap logical and physical block*/
		log_block_id++; 
		phy_block_id++;
	}

	while(log_block_id <= logblock) 
	{
		while(phy_block_id < this->kernel_start_log_block)
		{
			if(rtk_block_isbad(mtd,this->active_chip,phy_block_id*this->block_size) == 0){
				NAND_DEBUG("%s log_block_id %d phy_block_id %d \n",__FUNCTION__,log_block_id,phy_block_id);
				break;
			}
			phy_block_id++;  
		}
        
		if(phy_block_id == this->kernel_start_log_block){
			NAND_ERR("%s can't remap log_block_id %d log_block %d phy_block_id %d \n",__FUNCTION__,
				log_block_id,logblock,phy_block_id);
			phy_block_id = INVALID_BLOCK_ID;
			break;
		}
		
		this->log2phy_table[log_block_id] = phy_block_id; 
		phy_block_id++; 
		log_block_id++;
	}

	phy_block_id = this->log2phy_table[logblock];
	NAND_DEBUG("%s finally remap log_block %d phy_block %d \n",__FUNCTION__,logblock,phy_block_id);
	return phy_block_id;
}

/*************************************************************************************************************************
SECURE STORE map from begin to end
*******************************************************************************************************************************/
int get_phyblock_from_secstore(struct mtd_info *mtd,int logblock)
{
	int phy_block_id = INVALID_BLOCK_ID,search_phy_block = 0,limt_block = 0;
	struct nand_chip *this = mtd->priv;
	this->active_chip  = 0;
	search_phy_block = this->log2phy_table[logblock - 1];
	if(search_phy_block == INVALID_BLOCK_ID){
		search_phy_block = logblock;
	}
	limt_block = (this->secstore_start + this->secstore_size)/this->block_size;
	NAND_DEBUG("%s log_block_id %d search_phy_block %d limt_block %d \n",__FUNCTION__,logblock,search_phy_block,limt_block);
	while(search_phy_block < limt_block)
	{
		if(rtk_block_isbad(mtd,	this->active_chip,search_phy_block*this->block_size) == 0){
			NAND_DEBUG("%s log_block_id %d phy_block_id %d \n",__FUNCTION__,logblock,search_phy_block);
			this->log2phy_table[logblock] = search_phy_block;
			break;
		}
		search_phy_block++;  
	}
			
	phy_block_id = this->log2phy_table[logblock];
	NAND_DEBUG("%s finally remap log_block %d phy_block %d \n",__FUNCTION__,logblock,phy_block_id);
	return phy_block_id;
}

int get_phyblock_form_ibt(struct mtd_info *mtd,int logblock)
{
	struct nand_chip *this = mtd->priv;
	return this->ibt[logblock].dst_block;
}

/*******************************************************************************************
check badblock exist bbt region exist: return remap block not exist:return badblock
   find last remap block--> bad block may remap>1 bbt region block
eg: 		800   1024         801-->1023 1023-->1022 1022-->980
		801   1023         bad block 801-->final remap physical 980
		1023  1022 
		.........   ......        
		1022  980          
*******************************************************************************************/
int get_phyblock_from_bbt(struct mtd_info *mtd,int badblock)
{
	int loop = 0, phyblock = badblock, chipnr_remap = 0;
	struct nand_chip *this = mtd->priv;
	for(loop = 0; loop < this->bbt_len; loop++)
	{
		if((this->bbt[loop].bad_block != BB_INIT)&&(this->bbt[loop].remap_block != RB_INIT)){
			if(this->active_chip== this->bbt[loop].BB_die && phyblock == this->bbt[loop].bad_block){
				phyblock = this->bbt[loop].remap_block;
				if(this->bbt[loop].BB_die != this->bbt[loop].RB_die){
					this->active_chip = chipnr_remap = this->bbt[loop].RB_die;
					this->select_chip(mtd, chipnr_remap);
				}
				NAND_INFO("BBT item%d(%d,%d,%d,%d)\n",loop,this->bbt[loop].BB_die,this->bbt[loop].bad_block,
					this->bbt[loop].RB_die,this->bbt[loop].remap_block);
			}
		}else{
			break;
		}
	}
	return phyblock;
}

/*************************************************************************************
check badblock exist rbt region exist: return collect block not exist:return badblock
    bad block remap only one collect block
eg:  800   700
	801   523
	810   522 
	.........   bad block 800 use physcial block 700
*************************************************************************************/
int get_phyblock_from_rbt(struct mtd_info *mtd,int badblock)
{
	int loop = 0, chipnr_remap = 0,phyblock = badblock;
	struct nand_chip *this = mtd->priv;
	for(loop = 0; loop < this->rbt_len; loop++)
	{
		/*not inculde this->rbt[loop].bad_block != RRB_INIT because erase collect block maybe fail*/
		if(this->rbt[loop].collect_block != RCB_INIT){ 
			if(this->active_chip== this->rbt[loop].src_die && phyblock == this->rbt[loop].bad_block){
				phyblock = this->rbt[loop].collect_block;
				if(this->rbt[loop].src_die != this->rbt[loop].dst_die){
					this->active_chip = chipnr_remap = this->rbt[loop].dst_die;
					this->select_chip(mtd, chipnr_remap);
				}
				NAND_INFO("RBT item%d:(%d,%d,%d,%d)\n",loop,this->rbt[loop].src_die,this->rbt[loop].bad_block,
					this->rbt[loop].dst_die,this->rbt[loop].collect_block);
				break; /*rbt differnt bbt, rbt not exist badblock remap > 1*/
			}
		}else{
			break;
		}
	}
	return phyblock;
}

/***********************************************************************************************
 1. get physical block from ibt-->this frist-time(factory mode) boot 
 2. get physical block from bbt--> ibt get physcial block maybe badblock,use bbt remap block
 3. get physcial block from rbt-->bbt not exist remap block, use rbt collect block
*************************************************************************************************/
int get_phyblock_from_kernel_table(struct mtd_info *mtd,int logblock)
{
	int phyblock = logblock,bad_block = 0;
	struct nand_chip *this = mtd->priv;
	/*get physical block from ibt*/
	phyblock = get_phyblock_form_ibt(mtd,logblock);
	
	/*get physical block from  bbt*/
	if(this->use_rba_num != 0){
		bad_block = phyblock;
		phyblock = get_phyblock_from_bbt(mtd,bad_block);
		NAND_DEBUG("%s use_rbt_num  %d\n",__FUNCTION__,this->use_rbt_num );
		/*get physcial block from rbt*/
		if((this->use_rbt_num != 0)&&(this->rbt != NULL)){
			phyblock = get_phyblock_from_rbt(mtd,bad_block);
		}
	}
	NAND_DEBUG("%s logblock %d phyblock %d\n",__FUNCTION__,logblock,phyblock);
	return phyblock;
}

/***********************************************************************************************
bootcode area:  read/write skip bad block
kernel area:       use ibt/bbt/rbt  
*************************************************************************************************/
int get_phyblock_from_table(struct mtd_info *mtd,int logblock)
{
	int phyblock = logblock,start_log_block = 0;
	struct nand_chip *this = mtd->priv;
	start_log_block = this->secstore_start/this->block_size;
	if((logblock >=this->bootcode_start_log_block)&&(logblock <= this->bootcode_end_log_block)){
		phyblock = get_phyblock_from_bootcode_table(mtd,logblock);
	}else if((logblock >= start_log_block)&&(logblock < this->kernel_start_log_block)){
		phyblock = get_phyblock_from_secstore(mtd,logblock);
	}else if((logblock >=this->kernel_start_log_block)&&(logblock <=this->kernel_end_log_block)){
		phyblock = get_phyblock_from_kernel_table(mtd,logblock);
	}else{
		NAND_INFO("%s use default block log:%d phy:%d \n",__FUNCTION__,logblock,phyblock);
	}
	NAND_DEBUG("%s use  block log:%d phy:%d \n",__FUNCTION__,logblock,phyblock);
	return phyblock;
}

int get_phyblock(struct mtd_info *mtd,int logblock)
{
	int phyblock = 0;
	struct nand_chip *this = mtd->priv;
	phyblock = this->log2phy_table[logblock];
	/*phyblock not exist find*/
	if(phyblock == INVALID_BLOCK_ID){
		NAND_DEBUG("%s logblock %d need remap! \n",__FUNCTION__,logblock);
		phyblock = get_phyblock_from_table(mtd,logblock);
		this->log2phy_table[logblock] = phyblock;
	}
	return phyblock;		
}

void set_phyblock(struct mtd_info *mtd,int logblock,int phyblock)
{
	struct nand_chip *this = mtd->priv;
	this->log2phy_table[logblock] = phyblock;
}

/****************************************************************************************************************************
collect bbt block:     bbt not have free block
eg: before bbt         after bbt        1)find first remap > 1 block  bbt item   -->800-->1023 1023-->1021
    800   1023         800   1021       2)collect bbt item remap block             -->collect 1023 
    801   1022         801   1022       3)update bbt item:                       -->from 800-->1023 to 800-->1021 
    1023  1021         ..........       4) update bbt 
    ..........         850   989           a. after 1023-->1021 bbt item,move forward
    850   989          860   990           b.add BB_INIT-->1023 to the last of vaild bbt item 
    860   990          BB_INIT 1023        c. update cur_bbt_num free_bbt_num
*****************************************************************************************************************************/
void update_bbt_to_ram(struct mtd_info *mtd,int collect_id,int dst_die,int remap_block)
{
	int loop = 0;
	struct nand_chip *this = mtd->priv;
	for(loop = collect_id; loop < this->bbt_len-1; loop++)
	{
		if((this->bbt[loop+1].bad_block != BB_INIT)&&(this->bbt[loop+1].remap_block != RB_INIT)){
			this->bbt[loop].BB_die       =  this->bbt[loop+1].BB_die;
			this->bbt[loop].bad_block    =  this->bbt[loop+1].bad_block;
			this->bbt[loop].RB_die 		 =  this->bbt[loop+1].RB_die;
			this->bbt[loop].remap_block  =  this->bbt[loop+1].remap_block;
		}else{
			break;
		}
	}
	this->bbt[loop].BB_die       =  BB_DIE_INIT;
	this->bbt[loop].bad_block    =  BB_INIT;
	this->bbt[loop].RB_die  	 =  dst_die;
	this->bbt[loop].remap_block  =  remap_block;
	this->use_rba_num--;    /*reduce use remap block*/
	this->free_rba_num++;   /*add free block*/
}


/***********************************************************************************************
collect block:
eg:  800-->1023        find block 1023 to collect , 800-->1023 1023-->1022 ,collect 1023 ok return
	1023-->1022          collect block 1023 fail , 1023-->1022  1022-->1021 ,collect 1022, ok return
	1022-->1021          fail, go next
	....................
*************************************************************************************************/
int collect_block_from_bbt(struct mtd_info *mtd)
{
	int loop = 0, loop_in = 0,chipnr = 0,collect_block = INVALID_BLOCK_ID;
	struct nand_chip *this = mtd->priv;
	for(loop = 0; loop < this->bbt_len; loop++)
	{
		if((this->bbt[loop].bad_block != BB_INIT)&&(this->bbt[loop].remap_block != RB_INIT)){
			/*get collect block -->first bbt item remap block == find bbt item bad block*/
			for(loop_in = loop + 1; loop_in < this->bbt_len; loop_in++)
			{
				if(this->bbt[loop_in].bad_block == this->bbt[loop].remap_block){
					collect_block = this->bbt[loop].remap_block;
					chipnr        = this->bbt[loop_in].BB_die;
					NAND_INFO("%s loop:%d  loop_in:%d block %d find to collect!\n",
						__FUNCTION__,loop,loop_in,collect_block);
					break;
				}
			}
			
			/*collect successful update bbt in ram*/
			if(collect_block != INVALID_BLOCK_ID){
				if(this->erase_block(mtd, chipnr, collect_block*this->ppb) == 0){
					this->bbt[loop].remap_block = this->bbt[loop_in].remap_block;
					update_bbt_to_ram(mtd,loop_in,this->bbt[loop].BB_die,collect_block);
					NAND_INFO("%s collect block %d succceful!\n",__FUNCTION__,collect_block);
					dump_bbt(mtd);
					break;
				}
			}
		}else{
			break;
		}
	}
	return collect_block;
}

/*******************************************************************************************************************
write bbt block number  to nand
  bi table not exist BBT tag --> use free block
  bi table exist BBT table  case1: exist one tag case2: exist two tag
      	case 1: update exist tag block and get free block to write(exist write fail, use free block)
      	case 2: update exist two tag block  to write
********************************************************************************************************************/
int update_bbt_region_to_nand(struct mtd_info *mtd,u_char * buf, int buf_len)
{
	int ret = 0, index = 0,bitable_id = 0, page_no = 0;
	struct nand_chip *this = mtd->priv;
	while(index < BBT_BLOCK_NUM)
	{
		/*find bbt block*/
		bitable_id = find_block_in_bitable(mtd,BBT_TAG,index);
		if(bitable_id >= this->bi_table_block_num){
			NAND_INFO("%s not find block tag 0x%x \n", __FUNCTION__,BBT_TAG);
			/*find first free block in the bi table -->index write num*/
			bitable_id = find_block_in_bitable(mtd,0xFF,0);
			if(bitable_id >= this->bi_table_block_num){
				NAND_ERR("%s not find block free block \n", __FUNCTION__);
				break; 
			}
		}

		/*write table content to nand*/
		page_no = this->bi_table[bitable_id].phy_block*this->ppb;
		if(write_table_content(mtd, page_no, buf, buf_len, BBT_TAG)<0){
			update_bittable(mtd, bitable_id, BAD_BLOCK);
		}else{
			update_bittable(mtd, bitable_id, BBT_TAG);
			index++; //update index
		}
	}
	return ret;
}

/*************************************************************************
  eg: if 523 and 560 is run-time bad block
  before  		BB_INIT   1023  after ---> 523      1023  
    			BB_INIT   1022          		560      1022
    			..........              		       .......... 
    			BB_INIT   989           		BB_INIT   989        
    			BB_INIT   990           		BB_INIT   990 
**************************************************************************/
int get_freeblock_from_bbt(struct mtd_info *mtd,int badblock)
{
	int freeblock = INVALID_BLOCK_ID, loop = 0,collect_block = 0,chipnr = 0,chipnr_remap = 0;
	struct nand_chip *this = mtd->priv;
	this->active_chip = chipnr;
	dump_bbt(mtd);
	/*enough bbt block -->not enough collect block*/
	if(this->free_rba_num == 0){
		NAND_INFO("%s use bbt block number %d is full,use GC \n",__FUNCTION__,this->use_rba_num);
		collect_block = collect_block_from_bbt(mtd);
	}
	
	if(collect_block == INVALID_BLOCK_ID){
		return freeblock;
	}
	
	for(loop = 0; loop < this->bbt_len; loop++)
	{
		if((this->bbt[loop].bad_block == BB_INIT)&&(this->bbt[loop].remap_block != RB_INIT)){
			this->bbt[loop].BB_die    = chipnr;
			this->bbt[loop].bad_block = badblock;
			freeblock = this->bbt[loop].remap_block;
			this->bbt[loop].RB_die    = chipnr_remap;
			this->use_rba_num++;
			this->free_rba_num--;
			NAND_DEBUG("bbt item%d(%d,%d,%d,%d)\n",loop,this->bbt[loop].BB_die,this->bbt[loop].bad_block,
				this->bbt[loop].RB_die,freeblock);
			break;
		}
	}
	
	if((loop < this->bbt_len)&&(freeblock != INVALID_BLOCK_ID)){
		update_bbt_region_to_nand(mtd,(u_char *)this->bbt,(sizeof(BB_t)*this->bbt_len));
	}
	
	return freeblock;
}

/*************************************************************************
   before bbt table   init rbt table          collect block --> bbt bad block region
    800   1023         RCB_INIT   800     not use bbt region block
    801   1022         RCB_INIT   801    
    808   1021         RCB_INIT   808
    ..........        	 ..........
    850   989          RCB_INIT   850
    860   990          RCB_INIT   860
**************************************************************************/	
int build_rbt_content(struct mtd_info *mtd)
{
	int loop = 0, rbt_limt_block = 0, rbt_id = 0;
	struct nand_chip *this = mtd->priv;
	rbt_limt_block = this->block_num - this->bbt_len;
	this->rbt_len = this->bbt_len;
	if(this->rbt == NULL){
		if ((this->rbt = kmalloc(sizeof(RB_t)*this->rbt_len, GFP_KERNEL)) == NULL){
			NAND_ERR("%s: line:%d Error, no enough memory for RBT table \n",__FUNCTION__,__LINE__);
			return -1;
		}else{
			memset(this->rbt, 0xFF, sizeof(RB_t)*this->rbt_len);
		}
	}
	
	for(loop = 0; loop < this->rbt_len; loop++)
	{
		this->rbt[loop].src_die        =  BB_DIE_INIT;
		this->rbt[loop].bad_block      =  RBB_INIT;
		this->rbt[loop].dst_die 	   =  BB_DIE_INIT;
		this->rbt[loop].collect_block  =  RCB_INIT;
	}
	
	for(loop = 0; loop < this->bbt_len; loop++)
	{
		if((this->bbt[loop].remap_block!= RB_INIT)&&(this->bbt[loop].bad_block < rbt_limt_block)){
			this->rbt[loop].dst_die         = this->bbt[loop].BB_die;
			this->rbt[rbt_id].collect_block = this->bbt[loop].bad_block;
			rbt_id++;
		}
	}
	dump_rbt(mtd);
	return 0;
}


int update_rbt_to_nand(struct mtd_info *mtd)
{
	struct nand_chip *this = mtd->priv;
	u8*table_buf = NULL,*tmp_buf = NULL;
	int buf_len = 0;
	buf_len = ((sizeof(BB_t)*this->bbt_len + this->page_size-1 )/this->page_size)*this->page_size;
	buf_len += ((sizeof(RB_t)*this->rbt_len + this->page_size-1 )/this->page_size)*this->page_size;
	
	if((table_buf = kmalloc(buf_len, GFP_KERNEL)) != NULL){
		memset(table_buf,0xFF,buf_len);
		tmp_buf = table_buf;
		memcpy(tmp_buf,this->bbt, sizeof(BB_t)*this->bbt_len);
 		tmp_buf += (( sizeof(BB_t)*this->bbt_len + this->page_size-1 )/this->page_size)*this->page_size;
		memcpy(tmp_buf,this->rbt, sizeof(RB_t)*this->rbt_len);
	}else{
		NAND_ERR("%s line:%d malloc size 0x%x fail! \n",__FUNCTION__,__LINE__,buf_len);
		return -1;
	}
	update_bbt_region_to_nand(mtd,table_buf,buf_len);
	kfree(table_buf);
	return 0;
	
}

int get_freeblock_from_rbt(struct mtd_info *mtd,int badblock)
{
	int freeblock = INVALID_BLOCK_ID,loop = 0,chipnr = 0,chipnr_collect = 0;
	struct nand_chip *this = mtd->priv;
	if(this->rbt == NULL){
		if(build_rbt_content(mtd) < 0){
			return freeblock;
		}
	}
	
	for(loop = 0; loop < this->rbt_len; loop++)
	{
		if((this->rbt[loop].bad_block == RBB_INIT)&&(this->rbt[loop].collect_block != RCB_INIT)){
			if(this->erase_block(mtd, chipnr, this->rbt[loop].collect_block*this->ppb) == 0){
				this->rbt[loop].src_die   =  chipnr;
				this->rbt[loop].bad_block =  badblock;
				this->rbt[loop].dst_die   =  chipnr_collect;
				freeblock = this->rbt[loop].collect_block;
				this->use_rbt_num++;
				NAND_INFO("rbt item%d(%d,%d,%d,%d)\n",loop,this->rbt[loop].src_die,this->rbt[loop].bad_block,
					this->rbt[loop].dst_die,freeblock);
				break;
			}
		}
	}
	
	
	if((loop < this->rbt_len)&&(freeblock != INVALID_BLOCK_ID)){
		update_rbt_to_nand(mtd);
	}

	dump_rbt(mtd);
	
	return freeblock;
}

int get_secstore_free_block(struct mtd_info *mtd,int badblock)
{
	struct nand_chip *this = mtd->priv; 
	int freeblock = INVALID_BLOCK_ID,block_id = 0,secstore_end_block = 0;
	this->active_chip = 0;
	/*find next good block*/
	secstore_end_block   = (this->secstore_start + this->secstore_size + this->block_size - 1)/this->block_size;//bondery
	for(block_id = badblock + 1; block_id < secstore_end_block;block_id++)
	{
		if(rtk_block_isbad(mtd,this->active_chip,block_id*this->block_size) == 0){
			NAND_DEBUG("%s badblock %d block_id %d \n",__FUNCTION__,badblock,block_id);
			freeblock = block_id;
			break;
		}
	}
	return freeblock;
}

int get_kernel_free_block(struct mtd_info *mtd,int badblock)
{
	int freeblock = INVALID_BLOCK_ID;
	/*get free block from bbt*/
	if((freeblock = get_freeblock_from_bbt(mtd,badblock))== INVALID_BLOCK_ID){
		/*get free block from rbt*/
		NAND_INFO("%s not free bbt to collect, using rbt! \n",__FUNCTION__);
		freeblock  = get_freeblock_from_rbt(mtd,badblock);
	}
	return freeblock;
}

int get_freeblock(struct mtd_info *mtd,int badblock)
{
	struct nand_chip *this = mtd->priv;
	int freeblock = INVALID_BLOCK_ID,secstore_start_block = 0,secstore_end_block = 0;
	int kernel_start_block = 0;
	secstore_start_block = (this->secstore_start + this->block_size - 1)/this->block_size;
	secstore_end_block   = (this->secstore_start + this->secstore_size + this->block_size - 1)/this->block_size;//bondery
	kernel_start_block   = (this->secstore_start + this->secstore_size + this->block_size - 1)/this->block_size;
	NAND_DEBUG("%s secstore_start_block %d secstore_end_block %d kernel_start_block %d \n",
		__FUNCTION__,secstore_start_block,secstore_end_block,kernel_start_block);
	if((badblock >= secstore_start_block)&&(badblock < secstore_end_block)){
		freeblock = get_secstore_free_block(mtd,badblock);
	}else if((badblock >= kernel_start_block)&&(badblock < this->block_num )){
		freeblock = get_kernel_free_block(mtd,badblock);
	}
	return freeblock;
}

int erase_remap_block(struct mtd_info *mtd,int logblock,int bad_block)
{
	int ret = 0,phy_block = 0;
	struct nand_chip *this = mtd->priv; 

	/*mark as bad block*/
	mark_as_badblock(mtd,bad_block);
        	  
	while(1)
	{
		/*get block from  table*/
		phy_block = get_freeblock(mtd,bad_block); 
 		if(phy_block > this->block_num){
			NAND_ERR("%s log block %d get remap failed! \n",__FUNCTION__, bad_block);
			ret = -1; 
		}
		NAND_INFO("%s successful log_block %d remap %d !\n",__FUNCTION__,logblock,phy_block);
		/*update log to phy table*/
		set_phyblock(mtd,logblock,phy_block); 
		break;
	}
	return ret;
}

/*******************************************************************************************************************
   if page_offset > 0  a. read page_offset content   eg: page_offset = 3, need read 0-3 page content from block
    
*********************************************************************************************************************/
int remap_write_block_content(struct mtd_info *mtd,int log_block,int page,const u_char * page_content)
{
	int ret = 0,org_page_start = 0,page_offset = 0,phy_block = 0,phy_page = 0,bad_block = 0;
	struct nand_chip *this = mtd->priv;
	u_char * buf_content = NULL;
	page_offset = page%this->ppb;
    NAND_INFO("%s:read log_block %d page %d  number %d !\n",__FUNCTION__,log_block,page,page_offset+1);
	/*get orgial page block content*/
	if(page_offset > 0){
		if((buf_content = kmalloc(this->page_size*(page_offset+1), GFP_KERNEL )) == NULL){
			NAND_ERR("%s: line %d malloc buf size 0x%x failed!\n",__FUNCTION__,__LINE__,(this->page_size*(page_offset+1)));
			return -1;
		}else{
			org_page_start = (page/this->ppb)*this->ppb;
			memset(buf_content,0xFF,this->page_size*(page_offset+1)); //note write page 3 fail, read 3 page
			/*eg: write page offset 3 fail-->read page 0-2, need 3 page,index start 0*/
			if((ret = read_page_content(mtd,org_page_start,buf_content,page_offset,0xFF))!=0){
				NAND_ERR("%s line:%d read page %d number %d failed!\n",__FUNCTION__,__LINE__,org_page_start,page_offset+1);
				kfree(buf_content);
			}else{
				memcpy(buf_content+page_offset*this->page_size,page_content,this->page_size);
			}
		}   
	}
	
	/*mark as bad block*/
	bad_block = page/this->ppb;
	mark_as_badblock(mtd,bad_block);

	/*copy data to remap block*/
	while(1)
	{
		/*get remap physical block from bbt or rbt table*/
		phy_block = get_freeblock(mtd,bad_block); 
		if(phy_block > this->block_num){
			NAND_ERR("%s bad block %d get remap failed! \n",__FUNCTION__, bad_block);
			ret = -1;
			break;
		}
            
		/*write block content to block*/
		phy_page = phy_block*this->ppb;
		if(ret == 0){
			if(page_offset > 0){
				if((ret = write_page_content(mtd,phy_page,buf_content,(page_offset + 1),0xFF)) != 0){
					NAND_ERR("%sline:%d write page %d number %d failed!\n",__FUNCTION__,__LINE__,phy_page,(page_offset+1));
				}
			}else{
				if((ret = write_page_content(mtd,phy_page,page_content,1,0xFF)) != 0){
					NAND_ERR("%s line:%d write page %d failed!\n",__FUNCTION__,__LINE__,phy_page); 
				}
			}
		}else{
			/*read pre-page fail use only -->only update phyical to logical block*/
			ret = 0; 
			page_offset = 0;
		}

		if((ret == 0)){
			if(page_offset > 0){
				kfree(buf_content);
			}
			NAND_INFO("%s successful log_block %d remap %d !\n",__FUNCTION__,log_block,phy_block);
			/*update physical to logical block */
			set_phyblock(mtd,log_block,phy_block);    
			break;     
		}
	}  

	return ret;
}

int remap_read_block_content(struct mtd_info *mtd,int log_block,int page)
{
	int ret = 0,org_page_start = 0,page_num = 0,phy_block = 0,phy_page = 0,bad_block = 0;
	struct nand_chip *this = mtd->priv;
	u_char * buf_content = NULL,*tmp_bbt = NULL, *tmp_rbt = NULL;
	page_num = this->ppb;//page%this->ppb + 1;
    
	/*get orgial page block content*/
	if((buf_content = kmalloc(this->page_size*page_num, GFP_KERNEL )) == NULL){
		NAND_ERR("%s line:%d malloc buf size 0x%x failed!\n",__FUNCTION__,__LINE__,(this->page_size*page_num));
		return -1;
	}else{
		memset(buf_content,0xFF,this->page_size*page_num);
		org_page_start = (page/this->ppb)*this->ppb;
		if((ret = read_page_content(mtd,org_page_start,buf_content,page_num,0xFF))!=0){
			NAND_ERR("%s line:%d read page %d  number %d failed!\n",__FUNCTION__,__LINE__,org_page_start,page_num);
			kfree(buf_content);
			return -1;
		}   
	}
	
	/*copy bbt rbt content to tmp buffer*/
	if((tmp_bbt = (u_char *)kmalloc(sizeof(BB_t)*this->bbt_len,GFP_KERNEL)) == NULL){
		printk("%s line:%d malloc bbt error\n",__FUNCTION__,__LINE__);
		goto end;
	}
	memcpy(tmp_bbt,(u_char *)this->bbt,sizeof(BB_t)*this->bbt_len);
	
	if((tmp_rbt = (u_char *)kmalloc(sizeof(RB_t)*this->rbt_len,GFP_KERNEL)) == NULL){
		printk("%s line:%d malloc rbt error\n",__FUNCTION__,__LINE__);
		goto end;
	}
	memcpy(tmp_rbt,(u_char *)this->rbt,sizeof(RB_t)*this->rbt_len);
	
	bad_block = page/this->ppb;

	/*copy data to remap block*/
	while(1)
	{
		/*get remap physical block from bbt or rbt table*/
		phy_block = get_freeblock(mtd,bad_block); 
		if(phy_block > this->block_num){
			NAND_ERR("%s log block %d get remap failed\n",__FUNCTION__, bad_block);
			ret = -1;
			break;
		}
            
		/*write block content to block*/
		phy_page  = phy_block*this->ppb;
		if((ret = write_page_content(mtd,phy_page,buf_content,page_num,0xFF)) != 0){
			NAND_ERR("%s line:%d write page %d number %d failed!\n",__FUNCTION__,__LINE__,phy_page,page_num);
		}else{
			NAND_INFO("%s successful log_block %d remap %d !\n",__FUNCTION__,log_block,phy_block);
			/*update physical to logical block */
			set_phyblock(mtd,log_block,phy_block);    
			break;     
		}
	}  
	
	if(ret == 0){
		mark_as_badblock(mtd,bad_block);
	}else{
		/*recovery fail, use current ecc warning page*/
		memcpy((u_char *)this->bbt,tmp_bbt,sizeof(BB_t)*this->bbt_len);
		memcpy((u_char *)this->rbt,tmp_rbt,sizeof(RB_t)*this->rbt_len);
		update_rbt_to_nand(mtd);
	}

end:
	if(buf_content != NULL){
		kfree(buf_content);
	}
	if(tmp_bbt != NULL){
		kfree(tmp_bbt);
	}
	if(tmp_rbt != NULL){
		kfree(tmp_rbt);
	}
	return ret;
}

int rtk_nand_reload_bbt(struct mtd_info *mtd)
{
	int ret = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	
	ret = load_table_from_nand(mtd,BBT_TAG,0);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif	
	return ret;
}

