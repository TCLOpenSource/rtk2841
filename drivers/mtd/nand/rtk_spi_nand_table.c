#include <linux/errno.h>
#include <linux/compat.h>
#include <linux/types.h>
#include <linux/bitops.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <asm/io.h>
#include <mtd/mtd-abi.h>
#include <linux/slab.h>
#include "rtk_spi_nand.h"
DEBUG_SET_LEVEL(DEBUG_LEVEL_INFO);


//for whole nand flash
static int RBA_PERCENT = 4;
//for bootcode area
static int I_BOOTCODE_RBA_PERCENT = 10;
//for kernel area
static int I_KERNEL_RBA_PERCENT = 2;
extern unsigned int g_sn_BootcodeSize;
extern int is_good_block(struct mtd_info *mtd,unsigned int phy_block);
void sn_set_log2phy_block(struct mtd_info *mtd,int log_block,int phy_block);
int sn_read_page_content(struct mtd_info *mtd,unsigned int page_no,u8 * buf,
 	unsigned int page_num, unsigned int magic_num,unsigned int skip_bad_page);
int sn_write_page_content(struct mtd_info *mtd,unsigned int page_no, u8 * buf,
 unsigned int page_num, unsigned int magic_num);

void sn_init_bbt_info(struct mtd_info *mtd)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;   
    uint64_t div_res = 0,result = 0;
	/*initialize BBT information*/
    mtd->u32RBApercentage    = this->RBA_PERCENT = RBA_PERCENT;		//default value 5%
    SN_INFO("[**Default**]RBA percentage: %d%%\n",this->RBA_PERCENT);
 
    div_res = this->device_size;
    do_div(div_res,this->block_size);
    result = div_res;
    result*=this->RBA_PERCENT;
    do_div(result,100);
    this->bbt_len = result; /*bbt_len=device_size*RBA_PERCENT(5%)*/

    if(mtd->u32RBApercentage)
        mtd->u32RBApercentage = this->RBA_PERCENT;
    SN_INFO("[%s]mtd->u32RBApercentage %d%%, bbt len = %d\n",__FUNCTION__,
			mtd->u32RBApercentage, this->bbt_len);  
}

void sn_init_ibt_info(struct mtd_info *mtd)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    uint64_t div_res = 0,result = 0;
    /*initialize bootcode RBA-->for bootcode buffer*/
    this->I_BOOTCODE_RBA_PERCENT = I_BOOTCODE_RBA_PERCENT;		//default value 10% of bootcode-area
    SN_INFO("[**Default**]IBT-RBA percentage of bootcode-area: %d%%\n", this->I_BOOTCODE_RBA_PERCENT); 
    div_res = g_sn_BootcodeSize;
    do_div(div_res,this->block_size);
    result = div_res;
    result*=this->I_BOOTCODE_RBA_PERCENT; /*bootcode_rba_size = I_BOOTCODE_RBA_PERCENT(10%)*bootcode_size*/
    do_div(result,100);
    this->I_BOOTCODE_RBA = result;
    SN_INFO("[%s]I_BOOTCODE_RBA_PERCENT %d%%, I_BOOTCODE_RBA = %d\n",\
		   __FUNCTION__,this->I_BOOTCODE_RBA_PERCENT, this->I_BOOTCODE_RBA); 

	/*initialize Kernel RBA-->for kernel buffer*/
    div_res = this->device_size;
    do_div(div_res,this->block_size);
    this->I_KERNEL_RBA_PERCENT   = I_KERNEL_RBA_PERCENT;		//default value 1%
    SN_INFO("[**Default**]IBT-RBA percentage of kernel-area: %d%%\n",this->I_KERNEL_RBA_PERCENT);
    result = div_res;
    result*=this->I_KERNEL_RBA_PERCENT; /*kerenl_rba_size = I_KERNEL_RBA_PERCENT(1%)*device_size*/
    do_div(result,100);
    this->I_KERNEL_RBA = result;
    SN_INFO("[%s]I_KERNEL_RBA_PERCENT %d%%, I_KERNEL_RBA = %d\n",\
		__FUNCTION__,this->I_KERNEL_RBA_PERCENT, this->I_KERNEL_RBA);

	/*initialize ibt scan block start and end -->use bbt len*/
    this->bootcode_start_phy_block = IBT_SCAN_START_BLOCK;
    this->bootcode_end_phy_block   = g_sn_BootcodeSize/this->block_size - this->I_BOOTCODE_RBA;
    this->kernel_start_phy_block   = g_sn_BootcodeSize/this->block_size;
    this->kernel_end_phy_block     = this->total_block_num -this->bbt_len -this->I_KERNEL_RBA;
	this->ibt_len   = this->total_block_num;
}

int sn_init_table_info(struct mtd_info *mtd)
{
	int ret = 0;
	/*init bbt information */
	sn_init_bbt_info(mtd);
	/*init ibt information -->use bbt length,so after bbt information*/
	sn_init_ibt_info(mtd);
	return ret;
}

int sn_read_table_content(struct mtd_info *mtd,unsigned int page_no, u8 *buf, 
		int buf_len, int tag)
{
    int ret = 0,page_num = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    u8 *temp_buf = NULL;
    page_num = (buf_len + this->page_size-1 )/this->page_size;
    temp_buf = kmalloc(page_num*this->page_size, GFP_KERNEL);
    if(temp_buf != NULL){
        if((ret = sn_read_page_content(mtd,page_no,temp_buf,page_num,tag,0)) == 0){
            memcpy(buf, temp_buf, buf_len);   
            SN_ERR("Read page %d page_num %d successful!\n",page_no,page_num); 
        }
        kfree(temp_buf);
    }else{
        SN_ERR("%s malloc size 0x%x fail! \n",__FUNCTION__,(page_num*this->page_size));
        ret = -1;
    }
    return ret;
}

int sn_write_table_content(struct mtd_info *mtd, unsigned int page_no, u8 *buf, 
	int buf_len, int tag)
{
    int ret = 0, page_num = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    u8 *temp_buf = NULL;
    page_num = (buf_len + this->page_size-1 )/this->page_size;
    temp_buf = kmalloc(page_num*this->page_size, GFP_KERNEL);
    
    if(temp_buf!= NULL){
    	  memset(temp_buf,0xFF,page_num*this->page_size);
    	  memcpy(temp_buf,buf, buf_len);
    	  if((ret = sn_write_page_content(mtd,page_no,temp_buf,page_num,tag)) == 0){
    	      SN_INFO("%s write page %d num %d successful!\n",__FUNCTION__,page_no,page_num);    
    	  }
    	  kfree(temp_buf);  
    }else{
        SN_ERR("%s malloc size fail 0x%x! \n",__FUNCTION__,(page_num*this->page_size));
        ret = -1;
    }
    return ret;
}

/*******************************************************************************************
 scan bi table(ibt/bbt/rbt) block region, get block status and free block count
 start: BI_BLOCK_START end:IBT_SCAN_START_BLOCK - 1 frist_boot = 1 means frist-time nand boot
 eg: first-time block 1~5 tag  all good block tag are 0xFF means frist boot
 run-time: log_block1-log_block2 tag:BBT log_block3-log_block4 tag:IBT 
*******************************************************************************************/
int sn_init_bi_table(struct mtd_info *mtd)
{
	int loop = 0,block_id = 0,page_id = 0, tag_count = 0;
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;   
	u_char *oob_buf = NULL;
	memset(this->g_oobbuf,0xFF,this->oob_size);
	oob_buf = this->g_oobbuf;
	/*init bi table block number and content*/
	this->bi_table_block_start = BBT_BLOCK_START;
	this->bi_table_block_num   = IBT_SCAN_START_BLOCK- BBT_BLOCK_START; 
	if((this->bi_table =  kmalloc(this->bi_table_block_num*sizeof(struct block_info),
			GFP_KERNEL)) ==  NULL){
		SN_ERR("%s line:%d malloc table block info error! \n",__FUNCTION__,__LINE__);
		return -1;
	}
	
	/*scan bi table block region,get  block information*/
	block_id = this->bi_table_block_start;
	for(loop = 0; loop < this->bi_table_block_num;loop++){
		this->bi_table[loop].phy_block = block_id;
		page_id = block_id*this->block_per_page;
		/*get bit table block tag content*/
		if(this->read_oob (mtd, page_id, oob_buf,this->oob_size) == 0){
			this->bi_table[loop].block_tag = oob_buf[this->bad_tag_offset];
		}else{
			this->bi_table[loop].block_tag = BAD_TAG; //error tag
		}

		/*exist BBT or IBT,first boot(not exist any BBT or IBT)*/
		if((this->bi_table[loop].block_tag == BBT_TAG)||
				(this->bi_table[loop].block_tag == IBT_TAG)){
			tag_count++;
		}
		block_id++;
		SN_DEBUG("%s loop %d block id %d block_tag 0x%x\n",__FUNCTION__,
			loop,this->bi_table[loop].phy_block,this->bi_table[loop].block_tag);
	}
	
	if(tag_count == 0){
		this->frist_boot = 1;
		SN_INFO("%s  is frist time boot \n",__FUNCTION__);
	}
	return 0;
}

void sn_update_bittable(struct mtd_info *mtd, int bitable_id, u16 block_tag)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
	if(bitable_id < this->bi_table_block_num){
		this->bi_table[bitable_id].block_tag = block_tag;
	}
}

/***********************************************************************************************************************
block_tag:find block tag eg:IBT_TAG BBT_TAG,0xFF
repeat_times: find block index eg: repeat_times = 0, find frist block tag repeat_times=1 find second block tag
***********************************************************************************************************************/
int sn_find_block_in_bitable(struct mtd_info *mtd, u_char block_tag,int repeat_times)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
	int bitable_id = this->bi_table_block_num, loop = 0, count = repeat_times + 1;
	for(loop = 0; loop < this->bi_table_block_num; loop++)
	{		
		if(this->bi_table[loop].block_tag == block_tag){
			count--;
			SN_DEBUG("%s find loop %d count %d tag 0x%x phy_block %d \n",__FUNCTION__,loop,count,block_tag,this->bi_table[loop].phy_block);
			if(count == 0){
				bitable_id = loop;
				SN_DEBUG("%s finally find bitable_id %d tag 0x%x phy_block %d \n",
					__FUNCTION__,bitable_id,block_tag,this->bi_table[bitable_id].phy_block);
				break;
			}
		}
	}
	return bitable_id;
}

void sn_construct_ibt_info(struct mtd_info *mtd,unsigned int start_block,
		unsigned int end_block,unsigned int limit_block)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    int log_block_id = 0,phy_block_id = start_block;
    SN_INFO("%s start_block %d end_block %d limit_block %d\n",
     	__FUNCTION__, start_block,end_block,limit_block);
    for(log_block_id = start_block; log_block_id<= end_block; log_block_id++ )
    {
        this->ibt_table[log_block_id].src_block = log_block_id;
        while(phy_block_id<limit_block)
        {
            if(is_good_block(mtd,phy_block_id) == 0){
                SN_DEBUG("%s log_block_id %d phy_block_id %d \n",__FUNCTION__,
					log_block_id,phy_block_id);
                break;
            }
            phy_block_id++;  
        }
        
        if(phy_block_id == limit_block){
            SN_ERR("%s waring!! not enough limit_block,log_block_id %d phy_block_id %d \n",
				__FUNCTION__,log_block_id,phy_block_id);
            break;
        }else{
            this->ibt_table[log_block_id].dst_block = phy_block_id; 
            phy_block_id++;
        } 
    }      
}

int sn_malloc_table(struct mtd_info *mtd,u_char tag)
{
	int ret = 0;
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
	/*init ibt table*/
	if(tag == IBT_TAG){
		if((this->ibt_table = kmalloc(sizeof(ibt_info_t)*this->ibt_len,
				GFP_KERNEL)) == NULL){
        	SN_ERR("%s: Error, no enough size 0x%x memory for IBT\n",__FUNCTION__,
				sizeof(ibt_info_t)*this->ibt_len);
        	ret = -1;
    	}
	}else if(tag == BBT_TAG){
		/*extend bbt length -->add IBT buffer to bbt buffer*/
    	SN_INFO("%s before bbt len %d  ibt kernel end log %d phy %d\n",__FUNCTION__,
    		this->bbt_len,this->kernel_end_phy_block,
        	this->ibt_table[this->kernel_end_phy_block].dst_block);
		if((this->ibt_table[this->kernel_end_phy_block].dst_block == DST_INIT)||
			(this->ibt_table[this->kernel_end_phy_block].dst_block > this->total_block_num)){
			this->bbt_len = this->bbt_len;
		}else{
			this->bbt_len = this->total_block_num - this->ibt_table[this->kernel_end_phy_block].dst_block -1;
		}
		SN_INFO("%s extend bbt len %d \n",__FUNCTION__,this->bbt_len);
		if((this->bbt_table = kmalloc(sizeof(bbt_info_t)*this->bbt_len,
				GFP_KERNEL)) == NULL){
        	SN_ERR("%s: Error, no enough memory size 0x%x for BBT\n",__FUNCTION__,
					sizeof(bbt_info_t)*this->bbt_len);
        	ret = -1;
    	}
	}
	return ret;
}

void sn_init_ibt_to_ram(struct mtd_info *mtd)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
	int loop = 0,ibt_scan_limit = 0;	
	for (loop = 0; loop < this->ibt_len; loop++)
	{
		this->ibt_table[loop].src_block = SRC_INIT;
      	this->ibt_table[loop].dst_block = DST_INIT;
	}

	/*create ibt for bootcode-area*/	
    SN_INFO("Starting create bootcode area IBT\n"); 
    sn_construct_ibt_info(mtd, this->bootcode_start_phy_block, this->bootcode_end_phy_block,
      this->kernel_start_phy_block);

    /*create ibt for kernel-area*/
    SN_INFO("Starting create kernel area IBT\n");
    ibt_scan_limit = this->total_block_num -this->bbt_len;
    sn_construct_ibt_info(mtd, this->kernel_start_phy_block, this->kernel_end_phy_block, 
		ibt_scan_limit);
}

/************************************************************************************************
   scan bbt block region
 start index = 0 -->find remap region last good block  index = 1-->find remap region last -1 good block
eg:bbt block region 960-1023, 1023: good block 1022: bad block 1021:good block 1020:bad block 1019:good block
index 0 -->1023 index 1-->1022 index 2 -->1019
************************************************************************************************/
void sn_init_bbt_to_ram(struct mtd_info *mtd)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
	int block_id = 0,rba_id = 0,start_block = 0;
	/*initialize bbt array*/ 
    start_block = this->total_block_num - this->bbt_len;   
    for(rba_id = 0; rba_id<this->bbt_len; rba_id++)
    {
        this->bbt_table[rba_id].bad_block   = BB_INIT;
        this->bbt_table[rba_id].remap_block = RB_INIT;
    }
	
    rba_id = 0;
    for(block_id = this->total_block_num -1; block_id >=start_block;block_id--)
    {
        if(is_good_block(mtd,block_id) == 0)
        {
            this->bbt_table[rba_id].remap_block = block_id;
            rba_id++;
        }
    }   
}

/*******************************************************************************************
 create  ibt/bbt table content to nand ¡ê?frist time need block number is write ok
*******************************************************************************************/
int create_block_table_to_sn(struct mtd_info *mtd,u_char tag)
{
	int ret = 0,loop = 0, page_no = 0,table_size = 0,block_num = 0,bitable_id = 0;
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
	u_char * table_content =  NULL;
	/* init table content to ram*/
	if(tag == IBT_TAG){
		sn_init_ibt_to_ram(mtd);
		block_num     = SN_IBT_BLOCK_NUM;
		table_content = (u_char *)this->ibt_table;
		table_size    = sizeof(ibt_info_t)*this->ibt_len;
	}else if(tag == BBT_TAG){
		sn_init_bbt_to_ram(mtd);
		block_num     = SN_BBT_BLOCK_NUM;
		table_content = (u_char *)this->bbt_table;
		table_size    = sizeof(bbt_info_t)*this->bbt_len;
	}
	
	while(loop < block_num)
	{
		/*find first free block in the bi block range  to write*/
		bitable_id = sn_find_block_in_bitable(mtd,0xFF,0);
		if(bitable_id >= this->bi_table_block_num){
			SN_ERR("%s %d not enough block tag 0x%x in the bitable!\n",
					__FUNCTION__,__LINE__,tag);
			return -1;
		}

		SN_INFO("%s bitable_id %d block %d tag 0x%x in table!\n", __FUNCTION__,
			bitable_id, this->bi_table[bitable_id].phy_block,tag);
		/*write table content to nand*/
		page_no = this->bi_table[bitable_id].phy_block*this->block_per_page;
		/*update bi table information*/
		if(sn_write_table_content(mtd, page_no, table_content, table_size, tag)<0){
			sn_update_bittable(mtd, bitable_id, BAD_TAG);
		}else{
			sn_update_bittable(mtd, bitable_id, tag);
			loop++;
		}
	}
	return ret;	
}

int sn_recovery_bitable(struct mtd_info *mtd,int page_no,int repeat_times,
		u_char tag,int table_size)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
	u_char *table_buf = NULL,cur_tag = tag;
	int ret = 0,loop = 0, bitable_id = 0,re_page_no = 0;
  	if((table_buf = kmalloc(table_size, GFP_KERNEL)) == NULL){
  		SN_ERR("%s %d malloc buf size 0x%x error!\n",__FUNCTION__,__LINE__,table_size);
  		return -1; 
  	}

	/*read recovery buffer content*/
	memset(table_buf,0xFF,table_size);
  	if((ret = sn_read_table_content(mtd,page_no,table_buf,table_size,tag))< 0){
		kfree(table_buf);
		return ret;
	}

	/*recovery the before block --> block read error, erase block maybe ok*/
	for(loop = 0; loop < this->bi_table_block_num;loop++)
	{
  		/*frist use the pre page no*/
  		bitable_id = sn_find_block_in_bitable(mtd,cur_tag,repeat_times);
  		if(bitable_id < this->bi_table_block_num){
  			re_page_no = this->bi_table[bitable_id].phy_block*this->block_per_page;
			/*skip read ok page*/
			if(re_page_no == page_no){
				continue;
			}
  			if(sn_write_table_content(mtd, re_page_no, table_buf, table_size, tag) == 0){
				SN_INFO("%s recovery page %d tag 0x%x successful!\n",__FUNCTION__,
					re_page_no,tag);
				sn_update_bittable(mtd,bitable_id,tag);
				break;
			}else{
				/*write pre_page no fail,use first free block*/
				if(cur_tag != 0xFF){
					cur_tag = 0xFF;/*eg:write fail use=0x11, ,next use free block repeat time=0*/
					repeat_times = 0;
				}else{
					repeat_times++; /*find next free block*/
				}
				sn_update_bittable(mtd,bitable_id,BAD_TAG);
			}
  		}else{
  			SN_INFO("%s not free block to recovery! \n",__FUNCTION__);
			break;
  		}
  	}
  				
  	if(table_buf != NULL){
  		kfree(table_buf);
  	}
	return 0;
}

/*******************************************************************************************
 load table ibt/bbt/rbt table from spi nand:  every table block num >=2
   block index  0 -->read ok just return, read fail goto block index 1
   block index  1 -->read ok,first recovery block index 0,erase and write content, recovery ok,return
   			if recovery block index 0 fail, find free block and write content, and return
*******************************************************************************************/
int load_block_table_from_sn(struct mtd_info *mtd,u_char tag, int is_rbt)
{
	int ret = 0,loop = 0,bitable_id = 0,page_no = 0,repeat_times = 0,table_size = 0;
	int table_block_num = 0,offset_page = 0;
	u_char *table_content = NULL;
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
	
	if(tag == IBT_TAG){
		table_block_num  = SN_IBT_BLOCK_NUM;
		table_content = (u_char *)this->ibt_table;
		table_size    = sizeof(ibt_info_t)*this->ibt_len;
	}else if(tag == BBT_TAG){
		table_block_num = SN_BBT_BLOCK_NUM;
		if(is_rbt == 1){
			table_content = (u_char *)this->rbt_table;
			table_size = this->rbt_len*sizeof(rbt_info_t);
		}else{
			table_content = (u_char *)this->bbt_table;
			table_size = this->bbt_len*sizeof(bbt_info_t);
		}
		offset_page = (sizeof(bbt_info_t)*this->bbt_len + this->page_size-1 )/this->page_size;
	}

	for(loop = 0; loop < table_block_num; loop++)
	{
		/*get table tag block id eg: ibt block id*/
		bitable_id = sn_find_block_in_bitable(mtd,tag,repeat_times);
		if(bitable_id >= this->bi_table_block_num){
			SN_ERR("%s %d not find tag 0x%x in bi table\n", __FUNCTION__,__LINE__,tag);
			ret = -1;
			break;
		}

		/*get table page no*/
		page_no = this->bi_table[bitable_id].phy_block*this->block_per_page;
		if(is_rbt == 1){
  			page_no = page_no + offset_page;
 		}
  	
		/*read page content from spi nand*/
		if((ret = sn_read_table_content(mtd,page_no,table_content,table_size,tag))== 0){
  			break; 			 /*read tag ok break*/
  		}else{
			repeat_times++;  /*read errro, for next tag block*/
  		}
	}
  
	if((ret != 0)&&(is_rbt == 1)){
		/*case:bbt have no free block, but not use rbt table,so rbt load block fail*/
		ret = 1;
	}else if((ret == 0)&&(repeat_times > 0)&&(tag == BBT_TAG)){	
		/*recovery bbt content->ibt read-only,so not need recovery*/
  		SN_INFO("%s %d enter recovery mode! \n",__FUNCTION__,__LINE__);	
  		table_size  = offset_page*this->page_size + this->rbt_len*sizeof(rbt_info_t);
		if(sn_recovery_bitable(mtd,page_no,repeat_times -1,tag,table_size) < 0){
			SN_INFO("%s %d recovery fail!\n",__FUNCTION__,__LINE__);
		}
	}
	return ret;  
}

void sn_get_free_rab_num(struct mtd_info *mtd)
{
    int free_num = 0,rba_id = 0,use_bbt_num = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    for(rba_id = 0; rba_id < this->bbt_len; rba_id++)
    {
    	if(this->bbt_table[rba_id].remap_block != RB_INIT){
			if(this->bbt_table[rba_id].bad_block == BB_INIT){
				free_num++;
			}else{
				use_bbt_num++;
			}
		}
    }

	if(use_bbt_num == 0){
		SN_INFO("Congratulation!! No BBs in this Spi_Nand. \n");
	}
	this->use_rba_num = use_bbt_num;
    this->cur_rba_num = free_num;
}

int init_sn_block_table(struct mtd_info *mtd,u_char tag)
{
	int ret = 0;
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
	/*malloc table*/
	if((ret = sn_malloc_table(mtd,tag)) < 0){
		return ret;
	}
	
	if(this->frist_boot == 1){
		ret = create_block_table_to_sn(mtd,tag);
	}else{
		ret = load_block_table_from_sn(mtd,tag,0);
	}
	
	if((ret == 0)&&(tag == BBT_TAG)){
		sn_get_free_rab_num(mtd);
	}
	return ret;
}

int get_free_rbt_len(struct mtd_info *mtd)
{
    int use_rbt_len = 0, rbt_id = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    for(rbt_id = 0; rbt_id < this->rbt_len; rbt_id++)
    {
        if((this->rbt_table[rbt_id].remap_log_block == RBT_INIT)
        &&(this->rbt_table[rbt_id].bad_phy_block != RBT_INIT)){
            use_rbt_len++;
        }
    }
    return use_rbt_len;
}

int sn_init_rbt(struct mtd_info *mtd)
{
	int ret  = 0,rbt_table_size = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
	this->rbt_table = NULL;
	/*rbt exit must cur rba num = 0*/
	if(this->cur_rba_num != 0){
		return ret;
	}
	
    this->rbt_len   = this->bbt_len;  //max rbt_len = bbt_len
    rbt_table_size  = sizeof(rbt_info_t)*this->rbt_len;
    if((this->rbt_table = kmalloc(rbt_table_size, GFP_KERNEL)) == NULL){
        SN_ERR("%s: Error, no enough memory for RBT table \n",__FUNCTION__);
        return -1;
    }

	/*get rbt content from spi nand */
	ret = load_block_table_from_sn(mtd,BBT_TAG,1);
	if(ret == 1){ /*bbt have no free block(rba num = 0), but not use rbt table*/
		SN_INFO("no exist rbt table \n");
		kfree(this->rbt_table);
		this->rbt_table = NULL;
	}else if(ret < 0){
		return ret;
	}

	/*get current rbt number*/
	if(ret == 0){
		this->cur_rbt_num = get_free_rbt_len(mtd);
    } 
	return ret;
}

int sn_init_log2phy_table(struct mtd_info *mtd)
{
    int ret = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;  
    this->log2phy_len   = this->total_block_num - this->bbt_len; 
    this->log2phy_table = kmalloc(sizeof(int)*this->log2phy_len, GFP_KERNEL);
    if (!this->log2phy_table){
        SN_ERR("%s: Error, no enough memory for log2phy table\n",__FUNCTION__);
        ret = -1;
    }else{
        memset(this->log2phy_table,INVAILD_BLOCK,sizeof(int)*this->log2phy_len);
    }
    return ret;
}

int sn_init_table(struct mtd_info *mtd)
{
    int ret  = 0;  
	/*initialize common table information*/
    if((ret = sn_init_table_info(mtd)) < 0){
		return ret;
	}

	/*initialize bi table */
	if((ret = sn_init_bi_table(mtd)) < 0){
		return ret;
	}
	
    /*initialize ibt table*/
	if((ret = init_sn_block_table(mtd,IBT_TAG)) < 0){
		return ret;
	}

	/*initialize bbt table-->bbt table use ibt table content */
	if((ret = init_sn_block_table(mtd,BBT_TAG)) < 0){
		return ret;
	}

	/*initialize rbt table*/
	if((ret = sn_init_rbt(mtd)) < 0){
		return ret;
	}

	/*initialize logical to physcial table*/
	ret = sn_init_log2phy_table(mtd);
    return ret;
}

int sn_init_bbt_table(struct mtd_info *mtd)
{
	int ret = 0;
	ret = load_block_table_from_sn(mtd,BBT_TAG,0);
	return ret;
}

void sn_de_init_table(struct mtd_info *mtd)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    if(this->ibt_table != NULL){
        kfree(this->ibt_table);
    }

    if(this->bbt_table != NULL){
        kfree(this->bbt_table);
    }
	
    if(this->rbt_table != NULL){
        kfree(this->rbt_table);
    }
	
    if(this->log2phy_table != NULL){
        kfree(this->log2phy_table);
    }
}

void dump_sn_bi_table(struct mtd_info *mtd)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
	int loop = 0,bi_id = 0;
	printk("%s table len %d  \n",__FUNCTION__,this->bi_table_block_num);
	for(bi_id = 0; bi_id <this->bi_table_block_num; bi_id++)
	{
		printk("[%d] [%d,0x%x]\t",
			loop,this->bi_table[bi_id].phy_block,this->bi_table[bi_id].block_tag);
		loop++;
		if(loop%8 == 0){
			printk("\n");
		}
	}
	printk("\n");
}

void dump_sn_ibt(struct mtd_info *mtd)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    int ibt_id = 0,loop =0;
    printk("%s dump ibt table content len %d \n",__FUNCTION__,this->ibt_len); 
    for(ibt_id = IBT_SCAN_START_BLOCK; ibt_id < this->ibt_len; ibt_id++)
    {
        printk("[0x%04x, 0x%02x]\t",
        this->ibt_table[ibt_id].src_block,this->ibt_table[ibt_id].dst_block);
        loop++;
        if(loop%8 == 0){
            printk("\n");
        }    
    }  
    printk("\n");
}

void dump_sn_bbt(struct mtd_info *mtd)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    int rba_id = 0,loop = 0;
    printk("%s table len %d current bbt num %d use bbt num %d \n",__FUNCTION__,
		this->bbt_len,this->cur_rba_num,this->use_rba_num);  
    for( rba_id = 0; rba_id<this->bbt_len; rba_id++)
    {
        printk("[0x%04x, 0x%02x]\t",
        this->bbt_table[rba_id].bad_block,this->bbt_table[rba_id].remap_block);
        loop++;
        if(loop%8 == 0){
            printk("\n");
        }
    }
    printk("\n");
}

void dump_sn_rbt(struct mtd_info *mtd)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    int loop = 0,rbt_id = 0;
    printk("%s table len %d current free rbt num %d \n",__FUNCTION__,
			this->rbt_len,this->cur_rbt_num);
    if(this->rbt_table != NULL){
        for(rbt_id = 0; rbt_id <this->rbt_len; rbt_id++)
        {
            printk("[0x%02x,0x%04x]\t",this->rbt_table[rbt_id].remap_log_block,
				this->rbt_table[rbt_id].bad_phy_block);
            loop++;
            if(loop%8 == 0){
                printk("\n");
            }
        }
        printk("\n");
    }
}

void dump_sn_log2phy_talbe(struct mtd_info *mtd)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    int log_block_id = 0,loop = 0;
    printk("%s log2phy table len %d \n",__FUNCTION__,this->log2phy_len);
    for(log_block_id = 0; log_block_id< this->log2phy_len; log_block_id++)
    {
        printk("[0x%04x, 0x%02x]\t",log_block_id,this->log2phy_table[log_block_id]);
        loop++;
        if(loop%8 == 0){
            printk("\n");
        }       
    }
    printk("\n");
}

/***********************************************************************************
 collect block from bbt region block ,bad block remap > 1,bad block appear times > 1
 eg:  800  -->1023	 800-->1020
	 800-->1022		 find block 1023 to collect , 800-->1023 800-->1022 ,collect 1023 ok 800-->1022
	 800-->1021		 collect block 1023 fail , 800-->1022  800-->1021 ,
	 800-->1020		 collect 1022, 800-->1021 fail, go next
**********************************************************************************/
int sn_find_bbt_collect_block(struct mtd_info *mtd,int rba_start, int * cur_rba)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    int log_block = 0,collect_phy_block = INVAILD_BLOCK,rba_id = 0,sec_id =0;
    for(rba_id = rba_start; rba_id < this->bbt_len; rba_id++)
    {
    	  if(this->bbt_table[rba_id].bad_block != BB_INIT){
    	      log_block = this->bbt_table[rba_id].bad_block;
    	      for(sec_id = rba_id+1;sec_id< this->bbt_len; sec_id++)
    	      {
    	      	  /*get first remap > 1 bad block*/
    	          if(this->bbt_table[sec_id].bad_block == log_block){
                      *cur_rba   = rba_id; /*get current collect index*/
                      collect_phy_block = this->bbt_table[rba_id].remap_block;
                      SN_INFO("%s cur_rba %d collect_phy_block %d\n",
					  		__FUNCTION__,rba_id,collect_phy_block);
                      break;
    	          }
    	      }
    	  }
    	  if(collect_phy_block != INVAILD_BLOCK){
    	      break;
    	  }
    }
    return collect_phy_block;
}

/****************************************************************************************
collect bbt block:     bbt not have free block
eg: before bbt         after bbt        1)find first remap > 1 block  bbt item   -->800-->1023 800-->1021
    800   1023         800   1021       2)collect bbt item remap block             -->collect 1023 
    801   1022         801   1022       3)update bbt item:                       -->from 800-->1023 to 800-->1021 
    800  1021         ..........       		4) update bbt 
    ..........         	 850   989           a. after  800->1021 bbt item,move forward
    850   989          860   990           b.add BB_INIT-->1023 to the last of vaild bbt item 
    860   990          BB_INIT 1023        c. update cur_bbt_num 
***************************************************************************************/
void sn_update_mem_bbt(struct mtd_info *mtd,int cur_rba,int remap_block)
{
    int rba_id = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    SN_DEBUG("%s cur_rba %d remap_block %d\n",__FUNCTION__,cur_rba,remap_block);
    for( rba_id = cur_rba; rba_id< this->bbt_len - 1; rba_id++)
    {
        if((this->bbt_table[rba_id].bad_block != BB_INIT)&&
			(this->bbt_table[rba_id+1].bad_block != BB_INIT)){
            this->bbt_table[rba_id].bad_block   = this->bbt_table[rba_id+1].bad_block;
            this->bbt_table[rba_id].remap_block = this->bbt_table[rba_id+1].remap_block;    
        }else{
            break;
        }
    }
    this->bbt_table[rba_id].bad_block   = BB_INIT;
    this->bbt_table[rba_id].remap_block = remap_block;
    this->cur_rba_num++;  //add current rba number
    this->use_rba_num--;  //desc current rba number
}

int sn_collect_bbt_free_block(struct mtd_info *mtd)
{
    int rba_id = 0,cur_rba = INVAILD_BLOCK,collect_phy_block = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    while(rba_id < this->bbt_len)
    {
        /*find collect physical block in the bbt */
        collect_phy_block = sn_find_bbt_collect_block(mtd,rba_id,&cur_rba);
        if(collect_phy_block != INVAILD_BLOCK){
            /*erase block*/
            if(this->erase_block(mtd,collect_phy_block) == 0){
                /*add collect block in the memory bbt*/
                sn_update_mem_bbt(mtd,cur_rba,collect_phy_block);
                break;
            }else{   /*collect fail-->find next rab block*/
                rba_id = cur_rba + 1;    
            }
        }else{
            SN_ERR("%s Can't Find any free block to collect !\n",__FUNCTION__);
			dump_sn_bbt(mtd);
            cur_rba = INVAILD_BLOCK;
            break;
        }
    }
    return cur_rba;
}

int sn_get_remap_block(struct mtd_info *mtd,int bad_log_block)
{
    int remap_phy_block = INVAILD_BLOCK,rba_id = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    for( rba_id = 0; rba_id< this->bbt_len; rba_id++)
    {
        if((this->bbt_table[rba_id].bad_block == BB_INIT)&&
			(this->bbt_table[rba_id].remap_block != RB_INIT)){
            /*update bad block information,and get remap block*/
            this->bbt_table[rba_id].bad_block   = bad_log_block;
            remap_phy_block =  this->bbt_table[rba_id].remap_block;
            this->cur_rba_num--;  //decrease current rba number
            this->use_rba_num++;  //add use rba number
            SN_INFO("%s rba_id %d bad_log_block %d remap_phy_block %d cur_rba_num %d"
				" use rba num %d\n",__FUNCTION__,rba_id,bad_log_block,remap_phy_block,
                this->cur_rba_num,this->use_rba_num);
            break;    
        }
    }
    
    if(remap_phy_block == INVAILD_BLOCK){
        SN_ERR("%s Can't find free block\n",__FUNCTION__);
    }
    return remap_phy_block;
}

/****************************************************************************
write bbt block number  to spi nand
  bi table not exist BBT tag --> use free block
  bi table exist BBT table  case1: exist one tag case2: exist two tag
      	case 1: update exist tag block and get free block to write(exist write fail, use free block)
      	case 2: update exist two tag block  to write
*****************************************************************************/
int update_bbt_to_sn(struct mtd_info *mtd,u_char * buf, int buf_len)
{
	int ret = 0, repeat_times = 0,bitable_id = 0, page_no = 0;
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
	while(repeat_times < SN_BBT_BLOCK_NUM)
	{
		/*find bbt block*/
		bitable_id = sn_find_block_in_bitable(mtd,BBT_TAG,repeat_times);
		if(bitable_id >= this->bi_table_block_num){
			SN_INFO("%s %d not find block tag 0x%x use free block!\n",
					__FUNCTION__,__LINE__,BBT_TAG);
			/*find first free block in the bi table -->index write num*/
			bitable_id = sn_find_block_in_bitable(mtd,0xFF,0);
			if(bitable_id >= this->bi_table_block_num){
				SN_ERR("%s %d not find block free block!! \n", __FUNCTION__,__LINE__);
				break; 
			}
		}

		/*write table content to spi_nand*/
		page_no = this->bi_table[bitable_id].phy_block*this->block_per_page;
		if(sn_write_table_content(mtd, page_no, buf, buf_len, BBT_TAG)<0){
			sn_update_bittable(mtd, bitable_id, BAD_TAG);
		}else{
			sn_update_bittable(mtd, bitable_id, BBT_TAG);
			repeat_times++; //update index
		}
	}
	return ret;
}

int sn_update_bbt_content(struct mtd_info *mtd,int bad_log_block)
{
    int remap_phy_block = 0;
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    /*get remap block and update bad block map information */
    remap_phy_block = sn_get_remap_block(mtd,bad_log_block);
	  
    /*write bbt content to spi_nand*/
    if(remap_phy_block != INVAILD_BLOCK){
		update_bbt_to_sn(mtd,(u8 *)this->bbt_table, sizeof(bbt_info_t)*this->bbt_len);
    }
    return remap_phy_block;
}

int sn_get_free_bbt_block(struct mtd_info *mtd,int bad_log_block)
{
    int remap_phy_block = 0,cur_rba = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
  
    /*enough free block in the bbt*/
    if(this->cur_rba_num < 1){
        /*not enough block-->collect free block from bbt*/
        cur_rba = sn_collect_bbt_free_block(mtd);        
    }    
    
    if(cur_rba != INVAILD_BLOCK){
        /*update bbt content*/
        remap_phy_block = sn_update_bbt_content(mtd,bad_log_block);
    
        /*set log2phy block information table*/
        sn_set_log2phy_block(mtd,bad_log_block,remap_phy_block);
    }else{
        SN_ERR("%s can't find any block in the bbt table! \n",__FUNCTION__);
        remap_phy_block = INVAILD_BLOCK;
    }
    return remap_phy_block;
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
int sn_construct_rbt_info(struct mtd_info *mtd)
{
    int ret = 0,id = 0,loop = 0,find_flag = 0,bad_log_block = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    this->rbt_len   = this->bbt_len; //collect bbt len
    int tmp_block[this->rbt_len];
    this->rbt_table = kmalloc(sizeof(rbt_info_t)*this->rbt_len, GFP_KERNEL);
    if (this->rbt_table == NULL){
        SN_ERR("%s: Error, no enough memory for RBT\n",__FUNCTION__);
        return -1;
    }

    /*init rbt table*/
    for(loop = 0; loop < this->rbt_len; loop++)
    {
        this->rbt_table[loop].bad_phy_block    = RBT_INIT;
        this->rbt_table[loop].remap_log_block  = RBT_INIT;
        tmp_block[loop] = RBT_INIT;
    }

    for(id = 0; id < this->bbt_len;id++)
    {
        bad_log_block = this->bbt_table[id].bad_block;
        find_flag = 0;
        if((this->bbt_table[id].remap_block != RB_INIT)&&(bad_log_block != BB_INIT)){   
            /*find bbt  have the same bad_block item*/
            for(loop = 0; loop < this->rbt_len; loop++)
            {  
                if(tmp_block[loop] == RBT_INIT){
                    break;
                }else{
                    /*eg. bbt[0].bad_block = bbt[3].bad_block,so we don't use bbt[3].bad_block*/
                    if(bad_log_block == this->rbt_table[loop].remap_log_block){
                        SN_DEBUG("loop %d find bad_log_block %d\n",loop,bad_log_block);
                        find_flag = 1;
                        break;
                    }    
                }
            }

            /*not find the same bad_block item in the bbt table,add to rbt table*/
            if(find_flag == 0){
                tmp_block[loop] = bad_log_block;
                this->rbt_table[loop].bad_phy_block = this->ibt_table[bad_log_block].dst_block; //use first time ibt block
                this->cur_rbt_num++; //add cur free rbt num
	            SN_DEBUG("loop %d not find bad_log_block %d phy %d \n",loop,bad_log_block,
					this->ibt_table[bad_log_block].dst_block);
            }
        }
    }
	dump_sn_rbt(mtd);
    return ret;
}

int sn_find_rbt_collect_block(struct mtd_info *mtd,int rbt_start, int *cur_rbt)
{
    int collect_phy_block = 0,loop = rbt_start;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    while(loop < this->rbt_len)
    {
       /*find frist rbt use block*/
       if(this->rbt_table[loop].remap_log_block == RBT_INIT){
            collect_phy_block = this->rbt_table[loop].bad_phy_block;
            *cur_rbt  = loop;
            break;
       }
       loop++;
    }

    if(loop >= this->rbt_len){
        collect_phy_block = INVAILD_BLOCK;
    }
    SN_INFO("%s collect_phy_block %d rbt_start %d cur_rbt %d\n",
        __FUNCTION__,collect_phy_block,rbt_start,*cur_rbt);
    return collect_phy_block;
}

u8 * sn_get_rbt_table_buf(struct mtd_info *mtd, int *table_buf_size)
{
    u8*table_buf = NULL,*tmp_buf = NULL;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    int buf_len = 0;
    buf_len = ((sizeof(bbt_info_t)*this->bbt_len + this->page_size-1 )/this->page_size)*this->page_size;
	buf_len += ((sizeof(rbt_info_t)*this->rbt_len + this->page_size-1 )/this->page_size)*this->page_size;

    table_buf = kmalloc(buf_len, GFP_KERNEL);
    if(table_buf != NULL){
        tmp_buf = table_buf;
        memcpy(tmp_buf,this->bbt_table, sizeof(bbt_info_t)*this->bbt_len);
        tmp_buf += ((sizeof(bbt_info_t)*this->bbt_len + this->page_size-1 )/this->page_size)*this->page_size;
        memcpy(tmp_buf,this->rbt_table, sizeof(rbt_info_t)*this->rbt_len);
        *table_buf_size = buf_len;
    }else{
        SN_ERR("%s malloc size 0x%x fail! \n",__FUNCTION__,buf_len);
    }
    return table_buf;
}

int sn_update_rbt_content(struct mtd_info *mtd,int rbt_id,int bad_log_block)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    int ret = 0,buf_len = 0;
    u8 *rbt_table_buf = NULL;
    /*update content to memory*/
    this->rbt_table[rbt_id].remap_log_block = bad_log_block;
    this->cur_rbt_num--;  //reduce current rbt number

    /*update content to spi flash*/
    rbt_table_buf = sn_get_rbt_table_buf(mtd,&buf_len);
    if(rbt_table_buf != NULL){
		update_bbt_to_sn(mtd,rbt_table_buf,buf_len);
        kfree(rbt_table_buf);
    }else{
        ret =  -1;
        SN_ERR("%s malloc buf 0x%x error!\n",__FUNCTION__,buf_len);
    }
    return ret;
}

int sn_get_free_rbt_block(struct mtd_info *mtd,int bad_log_block)
{
    int ret = 0,collect_phy_block = 0,rbt_id = 0,rbt_start = 0,cur_rbt = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;

	/*rbt table not exist , build rbt table*/
    if(this->rbt_table == NULL){
        ret = sn_construct_rbt_info(mtd);
    }

    if(ret == 0){
        while(rbt_id < this->rbt_len)
        {
            /*find collect physical block in the rbt table */
            collect_phy_block = sn_find_rbt_collect_block(mtd,rbt_start,&cur_rbt);
            if(collect_phy_block != INVAILD_BLOCK){
                /*erase block*/
                if(this->erase_block(mtd,collect_phy_block) == 0){
                    if(sn_update_rbt_content(mtd,cur_rbt,bad_log_block) == 0){
                       /*set log2phy block information table*/
                       sn_set_log2phy_block(mtd,bad_log_block,collect_phy_block);
                       break;
                    }
                }else{
                    rbt_start = cur_rbt + 1;
                    collect_phy_block = INVAILD_BLOCK;
                }
            }else{
                SN_INFO("%s Can't Find any free block in rbt table to collect! \n",__FUNCTION__);
                collect_phy_block = INVAILD_BLOCK;
                break;
            }
            rbt_id++;
        }
		dump_sn_rbt(mtd);
    }
    return collect_phy_block;    
}

int sn_get_free_block(struct mtd_info *mtd,int bad_log_block)
{
    int remap_phy_block = 0;
    /*get free block from bbt table*/
    if((remap_phy_block = sn_get_free_bbt_block(mtd,bad_log_block)) == INVAILD_BLOCK){
        /*get free block form rbt table*/
       remap_phy_block =  sn_get_free_rbt_block(mtd,bad_log_block);
    }
    return remap_phy_block;
}

void sn_set_log2phy_block(struct mtd_info *mtd,int log_block,int phy_block)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
	if(log_block <= this->log2phy_len){
		this->log2phy_table[log_block] = phy_block;
	}   
}

void sn_build_bootcode_log2phy_table(struct mtd_info *mtd)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
	int log_block_id = 0;
	/*rebuild bootcode ibt from memory*/
	sn_construct_ibt_info(mtd,this->bootcode_start_phy_block,this->bootcode_end_phy_block,
		this->kernel_start_phy_block);
	for(log_block_id = this->bootcode_start_phy_block; 
			log_block_id < this->bootcode_end_phy_block; log_block_id++)
	{
		this->log2phy_table[log_block_id] = this->ibt_table[log_block_id].dst_block;
	}	
}

int sn_get_bootcode_log2phy_block(struct mtd_info *mtd,int log_block)
{
    int phy_block_id = 0,log_block_id = log_block;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    /*find first map block*/
    while(log_block_id > 0)
    {
        if(this->log2phy_table[log_block_id]!= INVAILD_BLOCK) {
            phy_block_id = this->log2phy_table[log_block_id];
            break;
        }
        log_block_id--;
    }

    /*no map block exist -->start begin*/
	if(phy_block_id == 0){ 
        phy_block_id = this->bootcode_start_phy_block;
        log_block_id = this->bootcode_start_phy_block;
    }else{
		/*frist no-map logical and physical block*/
		log_block_id++; 
		phy_block_id++;
	}

    while(log_block_id <= log_block) 
    {
        while(phy_block_id < this->kernel_start_phy_block)
        {
            if(is_good_block(mtd,phy_block_id) == 0){
                SN_DEBUG("%s log_block_id %d phy_block_id %d \n",__FUNCTION__,
					log_block_id,phy_block_id);
                break;
            }
            phy_block_id++;  
        }
        
        if(phy_block_id == this->kernel_start_phy_block){
            phy_block_id = INVAILD_BLOCK;
            break;
        }else{
            this->log2phy_table[log_block_id] = phy_block_id; 
            phy_block_id++;
        } 
        log_block_id++;
    }
    phy_block_id = this->log2phy_table[log_block];
    SN_DEBUG("%s log_block %d phy_block%d \n",__FUNCTION__,log_block,phy_block_id);
    return phy_block_id;
}

void sn_update_log2phy_use_bbt(struct mtd_info *mtd, int log_block_id)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    int rba_id = 0,rba_len = this->bbt_len - this->cur_rba_num; /*current use rba num*/
	/*no use bbt*/
	if(this->use_rba_num == 0){
		return;
	}
	
    while(rba_id < rba_len)
    {
        if (this->bbt_table[rba_id].remap_block!= RB_INIT)
        {
            /*get last logical bad block,logical bad block may remap more than one phycial remap block*/
            if(log_block_id == this->bbt_table[rba_id].bad_block){
                this->log2phy_table[log_block_id] = this->bbt_table[rba_id].remap_block;        
            }
        }else{
            break;
        }
        rba_id++;
    } 
	SN_INFO("%s log:%d phy:%d rba_id:%d rba_len %d\n",__FUNCTION__,
		log_block_id,this->log2phy_table[log_block_id],rba_id,rba_len);
}

void sn_update_log2phy_use_rbt(struct mtd_info *mtd, int log_block_id)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    int rbt_id = 0,use_rbt_num = this->rbt_len - this->cur_rbt_num;
	/*not exist rbt table*/
	if((this->cur_rba_num != 0)||(this->rbt_table == NULL)){
		return;
	}
	
    while(rbt_id < use_rbt_num)
    {
        if (this->rbt_table[rbt_id].remap_log_block != RBT_INIT)
        {
            /*get last logical bad block,logical bad block may remap more than one phycial remap block*/
            if(log_block_id == this->rbt_table[rbt_id].remap_log_block){
                this->log2phy_table[log_block_id] = this->rbt_table[rbt_id].bad_phy_block;        
            }
        }else{
            break;
        }
        rbt_id++;
    } 
    SN_INFO("%s log:%d phy:%d rbt_id:%d use_rbt_num %d \n",__FUNCTION__,
        log_block_id,this->log2phy_table[log_block_id],rbt_id,use_rbt_num);
}

int sn_get_kernel_log2phy_block(struct mtd_info *mtd,int log_block)
{
    int phy_block = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
	/*update map inforamtion in ibt */
	this->log2phy_table[log_block] = this->ibt_table[log_block].dst_block;

	/*update map information in bbt */
	sn_update_log2phy_use_bbt(mtd,log_block);
	
	/*update map information in rbt */
	sn_update_log2phy_use_rbt(mtd,log_block);
    phy_block = this->log2phy_table[log_block];
    SN_DEBUG("%s log_block %d phy_block %d \n",__FUNCTION__,log_block,phy_block);
    return phy_block;
}

int sn_get_log2phy_block(struct mtd_info *mtd,int log_block)
{
    int phy_block = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    phy_block = this->log2phy_table[log_block];

    /*phy block exist-->no exist-->map it*/
    if(phy_block == INVAILD_BLOCK){
        if((log_block >= this->bootcode_start_phy_block)
	        &&(log_block <= this->bootcode_end_phy_block)){
            phy_block = sn_get_bootcode_log2phy_block(mtd,log_block);
        }

        if((log_block >= this->kernel_start_phy_block)&&
            (log_block <= this->kernel_end_phy_block)) {
            phy_block = sn_get_kernel_log2phy_block(mtd,log_block);
        }
    }
    
    /*not map-->phy_block = log_block */
    if(phy_block == INVAILD_BLOCK){
        phy_block = log_block;
    }
    SN_DEBUG("%s log_block %d phy_block %d \n", __FUNCTION__,log_block,phy_block);
    return phy_block;
}

int sn_get_log2phy_page(struct mtd_info *mtd,int log_page)
{
    int phy_page = 0,log_block = 0,page_offset = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    log_block   = log_page/this->block_per_page;
    page_offset = log_page%this->block_per_page;
    phy_page    = sn_get_log2phy_block(mtd,log_block)*this->block_per_page+page_offset;
    return phy_page;
}

void sn_mark_as_badblock(struct mtd_info *mtd,int phy_bad_block)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    this->erase_block(mtd, phy_bad_block);
	memset(this->g_oobbuf,0xFF,this->oob_size);
	memset(this->g_databuf,0xFF,this->page_size);
    this->g_oobbuf[this->bad_tag_offset] = BAD_TAG;
	this->write_ecc_page(mtd,phy_bad_block*this->block_per_page,this->g_databuf,
			this->g_oobbuf); /*not use write oob*/
}

int sn_remap_erase_fail_block(struct mtd_info *mtd,int log_block,int bad_block)
{
    int ret = 0,phy_block = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    /*mark as bad block*/
	sn_mark_as_badblock(mtd,bad_block);
        	  
    /*get block from bbt table*/
    while(1)
    {
        phy_block = sn_get_free_block(mtd,log_block);
        if((phy_block > this->total_block_num)||(phy_block == INVAILD_BLOCK)){
            SN_ERR("%s log block %d get remap failed\n",__FUNCTION__, log_block);
            ret = -1; 
        }
        break;
    }
	SN_INFO("%s log block %d bad block %d remap block %d \n",
		__FUNCTION__,log_block,bad_block,phy_block);
    return ret;
}

int sn_read_page_content(struct mtd_info *mtd,unsigned int page_no,u8 * buf,
 	unsigned int page_num, unsigned int magic_num,unsigned int skip_bad_page)
{
    int ret = 0, page_id = 0,retry_count = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    for(page_id = 0; page_id < page_num; page_id++)
    {
        memset(this->g_oobbuf,0xFF,this->oob_size);
		memset(this->g_databuf,0xFF,this->page_size);
    	for(retry_count = 0;retry_count < READ_RETRY_COUNT;retry_count++)
        {
            if((ret = this->read_ecc_page(mtd,(page_no+page_id), this->g_databuf, 
				this->g_oobbuf)) == 0){
                if((IGR_TAG != magic_num) &&
					(this->g_oobbuf[this->magic_tag_offset] != magic_num)){
                        ret = -1;
                        SN_ERR("%s read page %d tag 0x%x error!\n",__FUNCTION__,
						    (page_no+page_id),this->g_oobbuf[0]); 
                }
                memcpy(buf+page_id*this->page_size,this->g_databuf, this->page_size);
            }else{
                SN_INFO("%s read page %d retry times %d !\n",
						__FUNCTION__,(page_no+page_id),retry_count);
            }
        }
		if(ret < 0){
			SN_ERR("%s %d read page %d error skip_bad_page %d!\n",
				__FUNCTION__,__LINE__,(page_no+page_id),skip_bad_page);	
			if( skip_bad_page == 0){
				break;
			}else{
				ret = 0; /*skip bad block , ret alway 0*/
			}
		}
    }

	if(ret == 0){
		SN_INFO("%s read page %d num %d tag 0x%x succesful!\n", __FUNCTION__,
			page_no,page_num,magic_num);
	}
    return ret;
}

int sn_write_page_content(struct mtd_info *mtd,unsigned int page_no, u8 * buf,
 unsigned int page_num, unsigned int magic_num)
{
    int ret = 0, page_id = 0, block_addr = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    block_addr = page_no/this->block_per_page;
    memset(this->g_oobbuf,0xFF,this->oob_size);
    u_char *oob_buf = NULL;
    if(IGR_TAG != magic_num){
        this->g_oobbuf[this->magic_tag_offset]= magic_num;
        oob_buf = this->g_oobbuf;
    }
    
    /*erase block*/
    if((ret = this->erase_block(mtd,block_addr)) == 0){  
        /*write block content*/
        for(page_id = 0; page_id < page_num; page_id++)
        {
            if((ret = this->write_ecc_page(mtd,(page_no+page_id),buf,oob_buf)) == 0){
                buf += this->page_size;
            }else{
                ret = -1;
                SN_ERR("%s write page %d error\n",__FUNCTION__,(page_no+page_id));
                break;
            }
        }
    }
    return ret;
}

int init_bad_phyblock_array(int **bad_phyblock_aray, int arry_len)
{
    if((*bad_phyblock_aray = kmalloc(arry_len*sizeof(int),GFP_KERNEL)) == NULL){
        SN_ERR("%s:malloc buf size 0x%x failed!\n",__FUNCTION__,
				arry_len*sizeof(int));
        return -1;
    }
    memset(*bad_phyblock_aray,INVAILD_BLOCK,arry_len*sizeof(int));
    return 0;
}

int find_bad_phyblock_exist(int *bad_phyblock_aray, int arry_len, int bad_phyblock)
{
    int ret = 0,loop = 0;
    for(loop = 0; loop < arry_len; loop++)
    {
        if(bad_phyblock_aray[loop] == bad_phyblock){
            SN_INFO("%s find bad block exist %d loop %d \n",
				__FUNCTION__,bad_phyblock,loop);
            ret = 1;
            break;
        }
    }
	return ret;
}

int sn_write_fail_page(struct mtd_info *mtd,int log_block,
	u_char * page_content,int page_num)
{
	struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
	int ret = 0,phy_block = 0,phy_page = 0,bad_phyblock_id = 0;
	int *bad_phyblock_aray = NULL;
	
	while(1)
	{
         /*get remap physical block from bbt or rbt */
		 phy_block = sn_get_free_block(mtd,log_block); 
		 /*phy block is invalid or collect phy block exist(collect block times>1)-->collect block erase ok write fail,collect phy block reuse*/
		 if((phy_block > this->total_block_num)||(phy_block == INVAILD_BLOCK)
		   ||(find_bad_phyblock_exist(bad_phyblock_aray,bad_phyblock_id,phy_block)==1)) {
			 SN_ERR("%s log block %d phy_block %d(0x%x) get remap failed!\n",
				 __FUNCTION__,log_block,phy_block,phy_block);
			 ret = -1;
			 break;
		 }
		 
		 /*write page content to remap block -->start page_offset=0*/
		 phy_page  = phy_block*this->block_per_page;
		 if((ret = sn_write_page_content(mtd,phy_page,page_content,
		 		page_num,IGR_TAG)) == 0){
		     SN_INFO("%s successful log_block %d remap block %d phy page %d num %d!\n",
			 	__FUNCTION__,log_block,phy_block,phy_page,page_num);	  
			 break;    
		 }else{
		 	  /*init bad physical block array*/
			 if(bad_phyblock_id == 0){
				 if((ret = init_bad_phyblock_array(&bad_phyblock_aray,this->bbt_len))< 0){
					 break;
				 }	 
			 }
			 /*add bad phy block to bad physical block array*/
			 bad_phyblock_aray[bad_phyblock_id] = phy_block;
			 bad_phyblock_id++;
		 }
    }	
	
	if(bad_phyblock_aray != NULL){
        kfree(bad_phyblock_aray);
    }
	return ret;
}

int sn_remap_write_fail_page(struct mtd_info *mtd,int log_block,int fail_page,
	const u_char * page_content)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    int ret = 0,fail_phy_block = 0,page_offset = 0,fail_page_start = 0;
    unsigned char * buf_content = NULL;
    page_offset   = fail_page%this->block_per_page;
	SN_INFO("%s log block %d fail page %d page_offset %d \n",
		__FUNCTION__,log_block,fail_page,page_offset);
    
    /*get  original page offset content*/
    if(page_offset > 0){
		/*note write page 3 fail, read 3 page, total page num 4*/
        if((buf_content = kmalloc(this->page_size*(page_offset+1),GFP_KERNEL)) == NULL){
            SN_ERR("%s:malloc buf size 0x%x failed!\n",__FUNCTION__,
					(this->page_size*(page_offset+1)));
            ret = -1;
        }else{
            fail_page_start = (fail_page/this->block_per_page)*this->block_per_page;	
            memset(buf_content,0xFF,this->page_size*(page_offset+1)); 
			/*eg: write page offset 3 fail-->read page 0-2, need 3 page*/
            if((ret = sn_read_page_content(mtd,fail_page_start,buf_content,
					page_offset,IGR_TAG,0)) !=0){
                SN_ERR("%s:read page %d  number %d failed!\n",__FUNCTION__,
						fail_page_start,page_offset);
            }else{
            	SN_INFO("%s fail_page %d page_offset %d \n",__FUNCTION__,fail_page,page_offset);
                memcpy(buf_content+page_offset*this->page_size,page_content,this->page_size);
            }
        }   
    }else{
    	buf_content = (u_char *)page_content;
    }
   
    /*mark write fail block as bad block*/
    fail_phy_block = fail_page/this->block_per_page;
    sn_mark_as_badblock(mtd,fail_phy_block);

	if(ret == 0){
		ret = sn_write_fail_page(mtd,log_block,buf_content,page_offset+1);
	}

	if((page_offset!= 0)&&(buf_content != NULL)){
		kfree(buf_content);
	}
	  
    return ret;
}

int sn_remap_read_fail_page(struct mtd_info *mtd,int log_block,int fail_page)
{
    int ret = 0,fail_page_start = 0,page_num = 0,read_fail_block = 0,buf_len = 0;
	u_char * buf_content = NULL,*tmp_buf = NULL,*tmp_bbt = NULL, *tmp_rbt = NULL;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    page_num = this->block_per_page;

    SN_INFO("%s %d fail_page %d log_block %d remap\n",__FUNCTION__,__LINE__,
			fail_page,log_block);
	/*get fail page block content*/
    if((buf_content = kmalloc(this->page_size*page_num, GFP_KERNEL )) == NULL){
		SN_ERR("%s line:%d malloc buf size 0x%x failed!\n",__FUNCTION__,__LINE__,
				(this->page_size*page_num));
        return -1;
    }else{
        memset(buf_content,0xFF,this->page_size*page_num);
        fail_page_start = (fail_page/this->block_per_page)*this->block_per_page;
		if((ret = sn_read_page_content(mtd,fail_page_start,buf_content,page_num,
				IGR_TAG,1))<0){
			goto end;
		}
	}

	/*copy bbt rbt content to tmp buffer*/
	if(this->rbt_table != NULL){
		buf_len = sizeof(bbt_info_t)*this->bbt_len+sizeof(rbt_info_t)*this->rbt_len;
	}else{
		buf_len = sizeof(bbt_info_t)*this->bbt_len;
	}

	if((tmp_buf = (u_char *)kmalloc(buf_len,GFP_KERNEL)) ==  NULL){
		ret = -1;
		goto end;
	}
	tmp_bbt = tmp_buf;
	memcpy(tmp_bbt,(u_char *)this->bbt_table,sizeof(bbt_info_t)*this->bbt_len);

	if(this->rbt_table != NULL){
		tmp_rbt = tmp_buf + sizeof(bbt_info_t)*this->bbt_len;
		memcpy(tmp_rbt,(u_char *)this->rbt_table,sizeof(rbt_info_t)*this->rbt_len);
	}
	
	read_fail_block = fail_page/this->block_per_page;
	if(ret == 0){
		ret = sn_write_fail_page(mtd,log_block,buf_content,page_num);
	}

	if(ret == 0){
        sn_mark_as_badblock(mtd,read_fail_block);
	}else{
		/*recovery fail, use current ecc warning page*/
		memcpy((u_char *)this->bbt_table,tmp_bbt,sizeof(bbt_info_t)*this->bbt_len);
		if(this->rbt_table != NULL){
			memcpy((u_char *)this->rbt_table,tmp_rbt,sizeof(rbt_info_t)*this->rbt_len);
		}
		update_bbt_to_sn(mtd,tmp_buf,buf_len);
	}

end:
	if(buf_content != NULL){
		kfree(buf_content);
	}
	if(tmp_buf != NULL){
		kfree(tmp_buf);
	}
    return ret;
}

