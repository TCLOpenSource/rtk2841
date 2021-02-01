#include <tvscalercontrol/io/ioregdrv.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/vgip_reg.h>
#include <rbus/sub_vgip_reg.h>
#include <mach/system.h>
#include <rbus/timer_reg.h>
#include "rtd_types.h"
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/scalerdrv/scaler_pst.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
#include <linux/kernel.h>
#include <linux/semaphore.h>
#define __bswap_constant_32(x) \
  ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
   (((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))


#define __bswap_32(x) __bswap_constant_32 (x)

///////////////////////////////////////////////
// For Read / Write Registers
///////////////////////////////////////////////
#ifdef CONFIG_I2RND_ENABLE
//extern unsigned char Scaler_I2rnd_get_enable(void);
//extern unsigned char Scaler_I2rnd_get_display(void);
#endif
//unsigned int Scaler_IP_register_get_cur_addr(unsigned int addr,unsigned char display);

#if 1//def CONFIG_DUMP_REGISTER
extern int  register_dump_check_counter(void);
extern unsigned int Get_dump_function(void);
extern void register_dump_data_to_buffer(DUMP_REGISTER_INFO dump_register_info);
extern unsigned int read_flag;
//extern unsigned int register_sta1;
//extern unsigned int register_end1;
//extern unsigned int register_sta2;
//extern unsigned int register_end2;
unsigned int register_sta[16];
unsigned int register_end[16];
unsigned int bForceDumpFlag=0;
unsigned int pre_reg_pts = 0;
unsigned int pre_reg_scnt = 0;
unsigned int pre_reg_vgip_line_cnt = 0;
unsigned int pre_reg_uzudtg_line_cnt = 0;
unsigned int pre_reg_memcdtg_line_cnt = 0;
unsigned int pre_reg_addr = 0;
unsigned int pre_reg_val = 0;
unsigned int pre_reg_rw_flag = 0;
unsigned int reg_iteration = 0;
#endif
unsigned int IoReg_Read32 (unsigned int addr) {
#ifdef CONFIG_I2RND_ENABLE
	if (Scaler_I2rnd_get_enable()) {
		unsigned int curr_addr = Scaler_i2rnd_IP_register_get_cur_read_addr(addr, Scaler_I2rnd_get_display());
		unsigned int value = 0;
		unsigned int tmp_addr = 0;
		if(curr_addr){
			curr_addr += 4;
			value = *(volatile unsigned int *)(curr_addr);
			curr_addr-=4;
			tmp_addr = *(volatile unsigned int *)(curr_addr);
			//printk(KERN_EMERG"i2rnd_buffer read: %x,%x, %x\n",addr, value, tmp_addr);

			if((value == 0) && (tmp_addr == 0)){
				return (*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr));
			}else{
				curr_addr += 4;
				value =  __bswap_32(*(volatile unsigned int *)(curr_addr));
				//printk(KERN_EMERG"i2rnd_buffer read (after swap): %x,%x\n",addr,value);
				return value;
			}
		}else{
			return (*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr));
		}
	}else{
#endif
#ifdef CONFIG_DUMP_REGISTER
		ppoverlay_main_display_control_rsv_RBUS main_display_control_rsv_reg;
		main_display_control_rsv_reg.regValue=*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR( PPOVERLAY_Main_Display_Control_RSV_reg);
		bForceDumpFlag = (*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8022288) & _BIT18);

		if(Get_dump_function()
			/*&& (main_display_control_rsv_reg.m_force_bg ==0)*/
#if 1 // TEST -- [KTASKWBS-6583] disable dump when CRC error > 20
			&& ((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8022288) & _BIT17) == 0)
#endif
			&&(
#if 0 // TEST -- [KTASKWBS-6583] register dump during smooth toggle setting flow
			(bForceDumpFlag)||
#endif
			((addr >= register_sta[0] && addr <=  register_end[0])
			||(addr >= register_sta[1] && addr <=  register_end[1])
			||(addr >= register_sta[2] && addr <=  register_end[2])
			||(addr >= register_sta[3] && addr <=  register_end[3])
			||(addr >= register_sta[4] && addr <=  register_end[4])
			||(addr >= register_sta[5] && addr <=  register_end[5])
			||(addr >= register_sta[6] && addr <=  register_end[6])
			||(addr >= register_sta[7] && addr <=  register_end[7])
			||(addr >= register_sta[8] && addr <=  register_end[8])
			||(addr >= register_sta[9] && addr <=  register_end[9])
			||(addr >= register_sta[10] && addr <=	register_end[10])
			||(addr >= register_sta[11] && addr <=	register_end[11])
			||(addr >= register_sta[12] && addr <=	register_end[12])
			||(addr >= register_sta[13] && addr <=	register_end[13])
			||(addr >= register_sta[14] && addr <=	register_end[14])
			||(addr >= register_sta[15] && addr <=	register_end[15]))
			)){
			if(!read_flag){
			DUMP_REGISTER_INFO dump_register_info;
			dump_register_info.rw_flag = 2;
			dump_register_info.register_counter= register_dump_check_counter();
			dump_register_info.registeraddr=addr;
			dump_register_info.value=(*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr));
			//pr_emerg("[tjw]register_counter=%d\n",dump_register_info.register_counter);
			 register_dump_data_to_buffer(dump_register_info);
			}
		}
#endif
		return (*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr));
#ifdef CONFIG_I2RND_ENABLE
	}
#endif
}

void IoReg_Write32 (unsigned int addr, unsigned int value) {
#ifdef CONFIG_I2RND_ENABLE
	if (Scaler_I2rnd_get_enable() && (Scaler_I2rnd_get_display() != 0)) {
		unsigned int curr_addr = Scaler_i2rnd_IP_register_get_cur_write_addr(addr, Scaler_I2rnd_get_display());
		if (curr_addr) {
			unsigned int tmp_addr =((addr>>2)&0x000fffff)|0x80000000;
			//printk(KERN_EMERG"i2rnd_buffer write(%d): %x,%x,%x\n",Scaler_I2rnd_get_display(), addr,value,curr_addr);
			curr_addr +=4;
			*(volatile unsigned int *)(curr_addr) = __bswap_32(value);
			curr_addr-=4;
			*(volatile unsigned int *)(curr_addr) = __bswap_32(tmp_addr);
			//	curr_addr+=8;
		} else {
		#ifdef CONFIG_PST_ENABLE
			if (Scaler_I2rnd_get_enable() &&(Scaler_I2rnd_get_display() ==I2RND_MAIN_S0_TABLE) && Scaler_main_md_pst_get_enable()) {
				unsigned int curr_md_addr = Scaler_PST_IP_register_get_cur_write_addr(addr,SLR_MAIN_DISPLAY);
				if (curr_md_addr) {
					unsigned int tmp_md_addr =((addr>>2)&0x000fffff)|0x80000000;
					//printk(KERN_EMERG"pst_buffer write: %x->%x,%x->%x\n",addr,value,curr_md_addr,tmp_md_addr);
					curr_md_addr +=4;
					*(volatile unsigned int *)(curr_md_addr) = __bswap_32(value);
					curr_md_addr-=4;
					*(volatile unsigned int *)(curr_md_addr) = __bswap_32(tmp_md_addr);		
				}  else {
					(*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr) = value);
				} 
			} else {
		#endif
				(*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr) = value);
		#ifdef CONFIG_PST_ENABLE
			}
		#endif
		}
	} else {
#endif
		(*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(addr) = value);
#ifdef CONFIG_I2RND_ENABLE
	}
#endif

#ifdef CONFIG_DUMP_REGISTER	//Eric@0609 fix me
	ppoverlay_main_display_control_rsv_RBUS main_display_control_rsv_reg;
	main_display_control_rsv_reg.regValue=*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR( PPOVERLAY_Main_Display_Control_RSV_reg);
    bForceDumpFlag = (*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8022288) & _BIT18);

	if(Get_dump_function()
		/*&& (main_display_control_rsv_reg.m_force_bg ==0)*/
#if 1 // TEST -- [KTASKWBS-6583] disable dump when CRC error > 20
        && ((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8022288) & _BIT17) == 0)
#endif
		&&(
#if 0 // TEST -- [KTASKWBS-6583] register dump during smooth toggle setting flow
        (bForceDumpFlag)||
#endif
		((addr >= register_sta[0] && addr <=  register_end[0])
		||(addr >= register_sta[1] && addr <=  register_end[1])
		||(addr >= register_sta[2] && addr <=  register_end[2])
		||(addr >= register_sta[3] && addr <=  register_end[3])
		||(addr >= register_sta[4] && addr <=  register_end[4])
		||(addr >= register_sta[5] && addr <=  register_end[5])
		||(addr >= register_sta[6] && addr <=  register_end[6])
		||(addr >= register_sta[7] && addr <=  register_end[7])
		||(addr >= register_sta[8] && addr <=  register_end[8])
		||(addr >= register_sta[9] && addr <=  register_end[9])
		||(addr >= register_sta[10] && addr <=  register_end[10])
		||(addr >= register_sta[11] && addr <=  register_end[11])
		||(addr >= register_sta[12] && addr <=  register_end[12])
		||(addr >= register_sta[13] && addr <=  register_end[13])
		||(addr >= register_sta[14] && addr <=  register_end[14])
		||(addr >= register_sta[15] && addr <=  register_end[15]))
        )){
		if(!read_flag){
		DUMP_REGISTER_INFO dump_register_info;
		dump_register_info.rw_flag = 1;
		dump_register_info.register_counter= register_dump_check_counter();
		dump_register_info.pts = ((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(TIMER_VCPU_CLK90K_LO_reg)));
		dump_register_info.vgip_line_cnt=(((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8022234))&0xFFF000)>>12);
		dump_register_info.uzudtg_line_cnt=(((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8028258))&0x1FFF0000)>>16);
		dump_register_info.memcdtg_line_cnt=((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8028258))&0x1FFF);
		dump_register_info.registeraddr=addr;
		dump_register_info.value=value;
		//pr_emerg("[tjw]register_counter=%d\n",dump_register_info.register_counter);
		 register_dump_data_to_buffer(dump_register_info);
		}
	}
#endif

}

void IoReg_Mask32(unsigned int addr, unsigned int andMask, unsigned int orMask) {
	IoReg_Write32(addr, ((IoReg_Read32(addr) & (andMask)) | (orMask)));
}

void IoReg_SetBits(unsigned int addr, unsigned int Mask) {
	IoReg_Write32(addr, (IoReg_Read32(addr) | Mask));
}

void  IoReg_ClearBits(unsigned int addr, unsigned int Mask) {
	IoReg_Write32(addr, ((IoReg_Read32(addr) & ~(Mask))));
}

unsigned char IoReg_ReadByte0(unsigned int addr) {
	return (IoReg_Read32(addr) & 0x000000ff);
}

unsigned char IoReg_ReadByte1(unsigned int addr) {
	return ((IoReg_Read32(addr) & 0x0000ff00) >> 8);
}

unsigned char IoReg_ReadByte2(unsigned int addr) {
	return ((IoReg_Read32(addr) & 0x00ff0000) >> 16);
}

unsigned char IoReg_ReadByte3(unsigned int addr) {
	return ((IoReg_Read32(addr) & 0xff000000) >> 24);
}

unsigned short IoReg_ReadWord0(unsigned int addr) {
	return (IoReg_Read32(addr) & 0x0000ffff);
}

unsigned short IoReg_ReadWord1(unsigned int addr) {
	return ((IoReg_Read32(addr) & 0xffff0000) >> 16);
}

void IoReg_WriteByte0(unsigned int addr, unsigned char val) {
	IoReg_Write32(addr, (IoReg_Read32(addr) & 0xffffff00) | (val & 0x000000ff));
}

void IoReg_WriteByte1(unsigned int addr, unsigned char val) {
	IoReg_Write32(addr, (IoReg_Read32(addr) & 0xffff00ff) | ((val & 0x000000ff) << 8));
}

void IoReg_WriteByte2(unsigned int addr, unsigned char val) {
	IoReg_Write32(addr, (IoReg_Read32(addr) & 0xff00ffff) | ((val & 0x000000ff) << 16));
}

void IoReg_WriteByte3(unsigned int addr, unsigned char val) {
	IoReg_Write32(addr, (IoReg_Read32(addr) & 0x00ffffff) | ((val & 0x000000ff) << 24));
}

void IoReg_WriteWord0(unsigned int addr, unsigned short val) {
	IoReg_Write32(addr, (IoReg_Read32(addr) & 0xffff0000) | (val & 0x0000ffff));
}

void IoReg_WriteWord1(unsigned int addr, unsigned short val) {
	IoReg_Write32(addr, (IoReg_Read32(addr)  & 0x0000ffff) | ((val & 0x0000ffff) << 16));
}


unsigned char IoReg_BusyCheckRegBit(unsigned int addr, unsigned int value, unsigned int timeoutcnt)
{
	//frank@0614 add below code to solve mantis36663 bug,system cpu clear VCPU ISR bit let EPC
	if((addr == PPOVERLAY_DTG_pending_status_reg)&&((IoReg_Read32(addr)&(_BIT0|_BIT1))>0)){
		;
	}else if((addr == VGIP_VGIP_CHN1_STATUS_reg)&&((value&(_BIT24|_BIT25))>0)){
		;
#ifdef CONFIG_DUAL_CHANNEL
	}
	else if((addr == SUB_VGIP_VGIP_CHN2_STATUS_reg)&&((value&(_BIT24|_BIT25))>0)){
		;
#endif
	}else{
		if((addr == VGIP_VGIP_CHN1_STATUS_reg)
#ifdef CONFIG_DUAL_CHANNEL
			|| (addr == SUB_VGIP_VGIP_CHN2_STATUS_reg)
#endif
			){
			//IoReg_SetBits(addr, value);
			IoReg_Write32(addr, ((IoReg_Read32(addr)&~(_BIT24|_BIT25)) | value));
			IoReg_ClearBits(addr, value|_BIT24|_BIT25);
		}else if(addr == PPOVERLAY_DTG_pending_status_reg){
			//IoReg_SetBits(addr, value);
			IoReg_Write32(addr, ((IoReg_Read32(addr)&~(_BIT0|_BIT1)) | value));
			IoReg_ClearBits(addr, value|_BIT0|_BIT1);
		}else{
			IoReg_SetBits(addr, value);
			IoReg_ClearBits(addr, value);
		}
	}

	do {
		if(IoReg_Read32(addr) & value) {
			return TRUE;
		}
	} while(timeoutcnt-- != 0);

	return FALSE;
}

unsigned char IoReg_BusyCheckRegInverseBit(unsigned int addr, unsigned int value, unsigned int timeoutcnt)
{
	//frank@0614 add below code to solve mantis36663 bug,system cpu clear VCPU ISR bit let EPC
	if((addr == PPOVERLAY_DTG_pending_status_reg)&&((IoReg_Read32(addr)&(_BIT0|_BIT1))>0)){
		;
	}else if((addr == VGIP_VGIP_CHN1_STATUS_reg)&&((value&(_BIT24|_BIT25))>0)){
		;
#ifdef CONFIG_DUAL_CHANNEL
	}else if((addr == SUB_VGIP_VGIP_CHN2_STATUS_reg)&&((value&(_BIT24|_BIT25))>0)){
		;
#endif
	}else{
		if((addr == VGIP_VGIP_CHN1_STATUS_reg)
#ifdef CONFIG_DUAL_CHANNEL
			|| (addr == SUB_VGIP_VGIP_CHN2_STATUS_reg)
#endif
			){
			//IoReg_SetBits(addr, value);
			IoReg_Write32(addr, ((IoReg_Read32(addr)&~(_BIT24|_BIT25) )| value));
			IoReg_ClearBits(addr, value|_BIT24|_BIT25);
		}else if(addr == PPOVERLAY_DTG_pending_status_reg){
			//IoReg_SetBits(addr, value);
			IoReg_Write32(addr, ((IoReg_Read32(addr)&~(_BIT0|_BIT1)) | value));
			IoReg_ClearBits(addr, value|_BIT0|_BIT1);
		}else{
			IoReg_SetBits(addr, value);
			IoReg_ClearBits(addr, value);
		}
	}

	do {
		if(!(IoReg_Read32(addr) & value)) {
			return TRUE;
		}
	} while(timeoutcnt-- != 0);

	return FALSE;
}

#if 0
///////////////////////////////////////////////
// For Read / Write SRAM
///////////////////////////////////////////////

unsigned int IoReg_SramRead32 (unsigned int addr) {
	return (*(volatile unsigned int *)( xSramPhysical2Virtual(addr)));
}

void IoReg_SramWrite32 (unsigned int addr, unsigned int value) {
	*(volatile unsigned int *)(xSramPhysical2Virtual(addr)) = (value);
}

void IoReg_SramMask32(unsigned int addr, unsigned int andMask, unsigned int orMask) {
	IoReg_SramWrite32(addr, ((IoReg_SramRead32(addr) & (andMask)) | (orMask)));
}

void IoReg_SramSetBits(unsigned int addr, unsigned int Mask) {
	IoReg_SramWrite32(addr, (IoReg_SramRead32(addr) | Mask));
}

void  IoReg_SramClearBits(unsigned int addr, unsigned int Mask) {
	IoReg_SramWrite32(addr, ((IoReg_SramRead32(addr) & ~(Mask))));
}

unsigned char IoReg_SramReadByte0(unsigned int addr) {
	return (IoReg_SramRead32(addr) & 0x000000ff);
}

unsigned char IoReg_SramReadByte1(unsigned int addr) {
	return ((IoReg_SramRead32(addr) & 0x0000ff00) >> 8);
}

unsigned char IoReg_SramReadByte2(unsigned int addr) {
	return ((IoReg_SramRead32(addr) & 0x00ff0000) >> 16);
}

unsigned char IoReg_SramReadByte3(unsigned int addr) {
	return ((IoReg_SramRead32(addr) & 0xff000000) >> 24);
}

unsigned short IoReg_SramReadWord0(unsigned int addr) {
	return (IoReg_SramRead32(addr) & 0x0000ffff);
}

unsigned short IoReg_SramReadWord1(unsigned int addr) {
	return ((IoReg_SramRead32(addr) & 0xffff0000) >> 16);
}

void IoReg_SramWriteByte0(unsigned int addr, unsigned char val) {
	IoReg_SramWrite32(addr, (IoReg_SramRead32(addr) & 0xffffff00) | (val & 0x000000ff));
}

void IoReg_SramWriteByte1(unsigned int addr, unsigned char val) {
	IoReg_SramWrite32(addr, (IoReg_SramRead32(addr) & 0xffff00ff) | ((val & 0x000000ff) << 8));
}

void IoReg_SramWriteByte2(unsigned int addr, unsigned char val) {
	IoReg_SramWrite32(addr, (IoReg_SramRead32(addr) & 0xff00ffff) | ((val & 0x000000ff) << 16));
}

void IoReg_SramWriteByte3(unsigned int addr, unsigned char val) {
	IoReg_SramWrite32(addr, (IoReg_SramRead32(addr) & 0x00ffffff) | ((val & 0x000000ff) << 24));
}

void IoReg_SramWriteWord0(unsigned int addr, unsigned short val) {
	IoReg_SramWrite32(addr, (IoReg_SramRead32(addr) & 0xffff0000) | (val & 0x0000ffff));
}

void IoReg_SramWriteWord1(unsigned int addr, unsigned short val) {
	IoReg_SramWrite32(addr, (IoReg_SramRead32(addr)  & 0x0000ffff) | ((val & 0x0000ffff) << 16));
}
///////////////////////////////
#endif


#if defined(TEST_PLAY_FILE)
//only for debugging
static RMP_Player* player = NULL;
void StopFile()
{
	if (player == NULL)
		return;
	player->Stop(player);
	player->UnloadMedia(player);

}
int PlayFile(char* f_name)
	{

	md_open();

	AVP_Open(); //must do this!
	AVP_Playback_init();	//memory resource


	AIO_PATH_CFG	path_cfg;
		Audio_AioInit(NULL, NULL, NULL);

		path_cfg.id = AIO_PATH_ID_PB;
		path_cfg.src[0] = AIO_PATH_SRC_FILE;
		path_cfg.src[1] = AIO_PATH_SRC_UNKNOWN;
		path_cfg.src[2] = AIO_PATH_SRC_UNKNOWN;
		path_cfg.src[3] = AIO_PATH_SRC_UNKNOWN;

		Audio_AioSetPathSrc(&path_cfg);
		Audio_HwpSetVolume(APP_CH_ID_L|APP_CH_ID_R, -100);

		SLR_TV_CHANNEL_INFO info;
		int vo_idx  = 1;
		info.mode = SLR_DTV_MODE;
		info.atvVideoStd = SLR_ATV_VIDEO_AUTO;
		//_SRC_VO, _SRC_OBJ_VO
		///Scaler_ChangeMainSource(vo_idx, &info, SLR_RATIO_AUTO);


	  //#define APPLAY_RE_INIT_PLAYER_EVERY_TIME


	  //RMP_ERRCODE rmp_err;
	  if(player == NULL &&  RMP_Player_New(&player) != RMP_ERR_OK) {
		  assert(0);
	  }


		unsigned char	unsigned charExitLoop = FALSE;
		INT32 key = -1 ;
		long cur_rate = 256;

		char mediapath[256];

		printf("Refresh DDR refresh rate\n");
		IoReg_Write32(0xb8008828, (IoReg_Read32(0xb8008828) & ~0x3f00)| 0x00001a00);
			if( strncmp(f_name, "http://",7)  != 0 )  {
				snprintf(mediapath, 256-1, "file://%s", f_name);
			}
			else {
				//just copy
				snprintf(mediapath, 256-1, "%s", f_name);
			}



			printf("st load %s\n", mediapath);
			printf("orgFname:%s\n", f_name);


	#ifdef APPLAY_RE_INIT_PLAYER_EVERY_TIME
			if (player == NULL) {
				if( RMP_Player_New(&player) != RMP_ERR_OK) {
					assert(0);
				}

				player->RegisterEvent(player, RMP_EVENT_TYPE_PB_FLOW, player, playback_ctrl_cbf);
			}

	#endif//APPLAY_RE_INIT_PLAYER_EVERY_TIME

		RMP_LOADMEDIA_PARAM media_param;
		//NAVMEDIAINFO	mediaInfo;

		RMP_ERRCODE retval;
		//mediapath is prefix with "file://" or "http://",....
			retval =	player->LoadMedia(player, mediapath, &media_param, PLAYBACK_TYPE_NORMAL);
		Scaler_ForceBg(SLR_MAIN_DISPLAY, SLR_FORCE_BG_SYSTEM, FALSE);
		if( retval == RMP_ERR_OK ) {
			if( player->Play(player) != RMP_ERR_OK) {
				//play fail(ex: no prog in ts file)
				printf("play %s fail\n", mediapath);
				exit(-1);
			}
		}
		else {
			printf("load media %s fail:\n", mediapath);
			NAVLOADFAILURE	*pFailure = &media_param.retFailure;
			printf("res: mType:%d vType:%d(%d) aType:%d\n", pFailure->reason,
					pFailure->mediaType, pFailure->videoType,
					pFailure->fourCC,
					pFailure->audioType);



			exit(-1);
		}

	}

#endif // TEST_PLAY_FILE

#if 1 //def CONFIG_DUMP_REGISTER
#define REGISTER_DUMP_PATH "/tmp/registers_dump.raw"
#define REGISTER_DUMP_BUFFER_SIZE 4096//1024*1024
#include <linux/fs.h>
#include <asm/uaccess.h>
unsigned int dump_register_function = 0;
unsigned int read_flag=0;
//unsigned int dr_buf_addr=0;
unsigned int dump_bufSize=0;
unsigned int dump_bufStar=0;
unsigned int dump_pRdptr=0;
unsigned int dump_pWdptr=0;
static unsigned int vir_addr=0;
//unsigned int register_sta1=0;
//unsigned int register_end1=0;
//unsigned int register_sta2=0;
//unsigned int register_end2=0;
extern void Set_dump_function(unsigned int enable);
#if 1
static struct file* file_open(const char* path, int flags, int rights) {
	struct file* filp = NULL;
	mm_segment_t oldfs;
	int err = 0;

	oldfs = get_fs();
	set_fs(get_ds());
	filp = filp_open(path, flags, rights);
	set_fs(oldfs);
	if(IS_ERR(filp)) {
		err = PTR_ERR(filp);
		return NULL;
	}
	return filp;
}

static void file_close(struct file* file) {
	filp_close(file, NULL);
}

static int file_read(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size) {
	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());

	ret = vfs_read(file, data, size, &offset);

	set_fs(oldfs);
	return ret;
}

static int file_write(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size) {
	mm_segment_t oldfs;
	int ret;

	oldfs = get_fs();
	set_fs(get_ds());

	ret = vfs_write(file, data, size, &offset);

	set_fs(oldfs);
	return ret;
}

static int file_sync(struct file* file) {
	vfs_fsync(file, 0);
	return 0;
}
void register_dump_data_to_file(void)
{
	if(read_flag)
	{
		//down(&VT_Semaphore);
		DUMP_REGISTER_INFO *rd_ptr=NULL;
		struct file* filp = NULL;
		unsigned char *ptr = NULL;
		unsigned int buf_size=107;
		char tmp_buf[buf_size];
		unsigned int i=0;

		filp = file_open(REGISTER_DUMP_PATH, O_RDWR | O_CREAT, 0);
		rd_ptr=(DUMP_REGISTER_INFO *)dump_pRdptr;
		pr_emerg( "\n\n\n\n *****************  register_dump_data_to_file start  *********************\n\n\n\n");
		if (filp == NULL) {
			pr_emerg("file open fail\n");
			return;
		}
		else if(rd_ptr==NULL)
		{
			pr_emerg( "rd_ptr=NUlL");
			return;
		}

		while(dump_pRdptr<dump_pWdptr)
		{
		memset(tmp_buf,0x0,buf_size);
		//snprintf(tmp_buf, 64, "\/dev\/pts\/%d", tty_num);
		snprintf(tmp_buf, buf_size, "[%08x]scnt=0x%08x,vline_cnt=%04d,uline_cnt=%04d,mline_cnt=%04d,addr=0x%08x,val=0x%08x\n",rd_ptr->pts, rd_ptr->register_counter,rd_ptr->vgip_line_cnt,rd_ptr->uzudtg_line_cnt,rd_ptr->memcdtg_line_cnt,rd_ptr->registeraddr,rd_ptr->value);
		//pr_emerg("[tjw]%s",tmp_buf);
		ptr=&tmp_buf[0];
		if (ptr == NULL) {
			pr_emerg("ptr == NULL\n");
			return;
		}
		//pr_emerg( "\n\n\n\n *****************  register_dump_data_to_file start  ******%x***************\n\n\n\n",registeradr);
		//unsigned long outfileOffset = i*64;
		file_write(filp, i*buf_size, ptr, buf_size);
		rd_ptr++;
		i++;
		dump_pRdptr=(unsigned int)rd_ptr;
		}
		file_sync(filp);
		file_close(filp);
		//dump_pWdptr=dump_bufStar;
		read_flag=0;
		//Set_dump_function(0);
		dvr_free((void *)vir_addr);
		//up(&VT_Semaphore);
		pr_emerg( "\n\n\n\n *****************  register_dump_data_to_file end  *********************\n\n\n\n");
		return;
	}
}
#endif
void register_dump_data_to_buffer(DUMP_REGISTER_INFO dump_register_info)
{
	unsigned int wr_ptr = dump_pWdptr;
	//unsigned int rd_ptr =dump_pRdptr;
	//unsigned int rd_ptr=dump_pWdptr;
	//DUMP_REGISTER_INFO *register_ino=NULL;
	char *ptr=NULL;
	//unsigned int buf_end_addr;
	unsigned int remained_size;
	unsigned int length;
	ptr= (unsigned char *)&dump_register_info;
	//pr_emerg("[1]dump_pWdptr=%x,dump_pRdptr=%x\n",dump_pWdptr,dump_pRdptr);
	remained_size=dump_bufStar+dump_bufSize-wr_ptr-1;
	length=sizeof(DUMP_REGISTER_INFO);

#if 1 // dump log directory
    static unsigned int last_value=0;
    if((dump_register_info.registeraddr != 0xb802508c)|| (dump_register_info.value != last_value)){
		if(dump_register_info.rw_flag == 2){
			if((dump_register_info.registeraddr == pre_reg_addr) && (dump_register_info.value == pre_reg_val) && (dump_register_info.rw_flag) == pre_reg_rw_flag){
				reg_iteration++;
			}
			else{
				if(reg_iteration > 0)
					printk("[DUMP.S] [0x%08x] scnt=0x%08x,vline_cnt=0x%08x,uline_cnt=0x%08x,mline_cnt=0x%08x,addr=0x%08x,val=0x%08x,rw=0x%x, iteration=0x%x\n",
			            pre_reg_pts, dump_register_info.register_counter,pre_reg_vgip_line_cnt,pre_reg_uzudtg_line_cnt,pre_reg_memcdtg_line_cnt,
			           pre_reg_addr,pre_reg_val,pre_reg_rw_flag,reg_iteration);
				reg_iteration = 0;
				dump_register_info.pts = ((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(TIMER_VCPU_CLK90K_LO_reg)));
				dump_register_info.vgip_line_cnt=(((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8022234))&0xFFF000)>>12);
				dump_register_info.uzudtg_line_cnt=(((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8028258))&0x1FFF0000)>>16);
				dump_register_info.memcdtg_line_cnt=((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8028258))&0x1FFF);
				printk("[DUMP.S] [0x%08x] scnt=0x%08x,vline_cnt=0x%08x,uline_cnt=0x%08x,mline_cnt=0x%08x,addr=0x%08x,val=0x%08x,rw=0x%x, iteration=0x%x\n",
		            dump_register_info.pts, dump_register_info.register_counter,
		            dump_register_info.vgip_line_cnt,dump_register_info.uzudtg_line_cnt,dump_register_info.memcdtg_line_cnt,
		            dump_register_info.registeraddr,dump_register_info.value,dump_register_info.rw_flag,reg_iteration);
			}
			pre_reg_pts = ((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(TIMER_VCPU_CLK90K_LO_reg)));
			pre_reg_scnt = dump_register_info.register_counter;
			pre_reg_vgip_line_cnt = (((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8022234))&0xFFF000)>>12);
			pre_reg_uzudtg_line_cnt = (((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8028258))&0x1FFF0000)>>16);
			pre_reg_memcdtg_line_cnt = ((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8028258))&0x1FFF);
			pre_reg_addr = dump_register_info.registeraddr;
			pre_reg_val = dump_register_info.value;
			pre_reg_rw_flag = dump_register_info.rw_flag;
		}
		else{
			if((dump_register_info.registeraddr == pre_reg_addr) && (dump_register_info.value == pre_reg_val) && (dump_register_info.rw_flag == pre_reg_rw_flag)){
				reg_iteration++;
			}
			else{
				if(reg_iteration > 0)
					printk("[DUMP.S] [0x%08x] scnt=0x%08x,vline_cnt=0x%08x,uline_cnt=0x%08x,mline_cnt=0x%08x,addr=0x%08x,val=0x%08x,rw=0x%x, iteration=0x%x\n",
			            pre_reg_pts,pre_reg_scnt,pre_reg_vgip_line_cnt,pre_reg_uzudtg_line_cnt,pre_reg_memcdtg_line_cnt,
			           pre_reg_addr,pre_reg_val,pre_reg_rw_flag,reg_iteration);
				reg_iteration = 0;
				dump_register_info.pts = ((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(TIMER_VCPU_CLK90K_LO_reg)));
				dump_register_info.vgip_line_cnt=(((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8022234))&0xFFF000)>>12);
				dump_register_info.uzudtg_line_cnt=(((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8028258))&0x1FFF0000)>>16);
				dump_register_info.memcdtg_line_cnt=((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8028258))&0x1FFF);
				printk("[DUMP.S] [0x%08x] scnt=0x%08x,vline_cnt=0x%08x,uline_cnt=0x%08x,mline_cnt=0x%08x,addr=0x%08x,val=0x%08x,rw=0x%x, iteration=0x%x\n",
		            dump_register_info.pts, dump_register_info.register_counter,
		            dump_register_info.vgip_line_cnt,dump_register_info.uzudtg_line_cnt,dump_register_info.memcdtg_line_cnt,
		            dump_register_info.registeraddr,dump_register_info.value,dump_register_info.rw_flag,reg_iteration);
			}
			pre_reg_pts = ((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(TIMER_VCPU_CLK90K_LO_reg)));
			pre_reg_scnt = dump_register_info.register_counter;
			pre_reg_vgip_line_cnt = (((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8022234))&0xFFF000)>>12);
			pre_reg_uzudtg_line_cnt = (((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8028258))&0x1FFF0000)>>16);
			pre_reg_memcdtg_line_cnt = ((*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(0xb8028258))&0x1FFF);
			pre_reg_addr = dump_register_info.registeraddr;
			pre_reg_val = dump_register_info.value;
			pre_reg_rw_flag = dump_register_info.rw_flag;
		}
        if(dump_register_info.registeraddr == 0xb802508c)
            last_value = dump_register_info.value;
    }
#else	
	if(length<remained_size)
	{
		memcpy((unsigned char *)wr_ptr,ptr,length);
		wr_ptr+=length;
		//register_ino=(DUMP_REGISTER_INFO *)rd_ptr;
	}
	else
	{
		//read_flag=1;
		// IoReg_ClearBits(VGIP_VGIP_CHN1_STATUS_reg,_BIT17);
		//pr_emerg("memory over,dump stop");
		 (*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(VGIP_VGIP_CHN1_STATUS_reg) =(IoReg_Read32(VGIP_VGIP_CHN1_STATUS_reg)&~(1<<17)));
#if 0
		memcpy((unsigned char *)dump_bufStar,ptr,length);
		wr_ptr=dump_bufStar+length;
		register_ino=(DUMP_REGISTER_INFO *)dump_bufStar;
#endif
	}
#endif
    
	//pr_emerg("scounter=%08x,vgip_line_cnt=%08x,registeraddr=%08x,value=%08x\n",register_ino->register_counter,register_ino->vgip_line_cnt,register_ino->registeraddr,register_ino->value);
	 dump_pWdptr=wr_ptr;
}

void Set_dump_function(unsigned int enable)
{
	dump_register_function=enable;
}
unsigned int Get_dump_function(void)
{
	return dump_register_function;
}
int register_dump_check_counter(void)
{
	unsigned int *dr_info_ptk =NULL;
	unsigned int counter;
	unsigned int tmp_counter;
	dr_info_ptk = (unsigned int  *)Scaler_GetShareMemVirAddr(SCALERIOC_DUMP_REGISTER_COUNTER);
	if(dr_info_ptk==NULL)
		pr_emerg("dr_info_ptk=NULL\n");
	if (dr_info_ptk) {
		//memcpy(&tmp_counter, (unsigned char *)dr_info_ptk, sizeof(unsigned int));
		tmp_counter=*dr_info_ptk;
		tmp_counter = Scaler_ChangeUINT32Endian(tmp_counter);

		counter=tmp_counter;
		tmp_counter++;

		tmp_counter = Scaler_ChangeUINT32Endian(tmp_counter);
		//memcpy(&tmp_counter, (unsigned char *)dr_info_ptk, sizeof(unsigned int));
		*dr_info_ptk = tmp_counter;
	}
	else{
		return 0;
	}

	return counter;
}
void test_register_dump_counter(void)
{
	unsigned int *dr_info_ptk =NULL;
	unsigned int counter;

	dr_info_ptk= (unsigned int  *)Scaler_GetShareMemVirAddr(SCALERIOC_DUMP_REGISTER_COUNTER);

	if(dr_info_ptk){
		counter=*dr_info_ptk;
		counter = Scaler_ChangeUINT32Endian(counter);
		pr_emerg("counter=%x\n",counter);
	}
	return;
}
void register_dump_send_info(VIDEO_RPC_DUMP_REGISTER dr_rpc_date)
{
	//VIDEO_RPC_DUMP_REGISTER dr_data;
	unsigned int *pulDataTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	int ret = 0;

	pulDataTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_DUMP_REGISTER_INFO);
	ulCount = sizeof(VIDEO_RPC_DUMP_REGISTER) / sizeof(unsigned int);
	// copy to RPC share memory
	memcpy(pulDataTemp, &dr_rpc_date, sizeof(VIDEO_RPC_DUMP_REGISTER));
	if(pulDataTemp==NULL){
		pr_emerg("[tjw]pulDataTemp==NULL!!!\n");
		return;
	}
	for (i = 0; i < ulCount; i++)
		pulDataTemp[i] = htonl(pulDataTemp[i]);
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_DUMP_REGISTER_INFO,0,0)))
	{
		pr_emerg("ret=%d, SCALERIOC_DUMP_REGISTER_INFO to driver fail !!!\n", ret);
	}
}
void register_dump_test(void)
{
	unsigned int *dr_info_ptk =NULL;
	unsigned int vir_addr_noncache;
	VIDEO_RPC_DUMP_REGISTER dr_rpc_date;
	//pr_emerg("register_dump_test !!!\n");
	if(IoReg_Read32(VGIP_VGIP_CHN1_STATUS_reg)&(1<<17)){
		if(Get_dump_function()==0){

		vir_addr = (unsigned int)dvr_malloc_uncached_specific(REGISTER_DUMP_BUFFER_SIZE*sizeof(unsigned char), GFP_DCU1, (void **)&vir_addr_noncache);
		if(0==vir_addr)
			return;
		//memset((unsigned char *)vir_addr_noncache, 0, REGISTER_DUMP_BUFFER_SIZE*sizeof(unsigned char));

		dr_info_ptk = (unsigned int  *)Scaler_GetShareMemVirAddr(SCALERIOC_DUMP_REGISTER_COUNTER);
		if (dr_info_ptk==NULL) {
			pr_emerg("dr_info_ptk=NULL\n");
			return;
		}
		*dr_info_ptk=0;
		dump_bufStar=vir_addr_noncache;
		dump_bufSize=REGISTER_DUMP_BUFFER_SIZE;
		dump_pRdptr=vir_addr_noncache;
		dump_pWdptr=vir_addr_noncache;

		/*dr_rpc_date.register_sta1=register_sta1;
		dr_rpc_date.register_end1=register_end1;
		dr_rpc_date.register_sta2=register_sta2;
		dr_rpc_date.register_end2=register_end2;*/

		memcpy(dr_rpc_date.register_sta, register_sta, sizeof(register_sta));
		memcpy(dr_rpc_date.register_end, register_end, sizeof(register_end));
		dr_rpc_date.cmd=1;
		register_dump_send_info(dr_rpc_date);
		Set_dump_function(1);
		//pr_emerg("register_dump_test rpc done !!!\n");
		}
	}
	else{
		if(Get_dump_function()==1){
		//pr_emerg("register_dump_test stop !!!\n");
		Set_dump_function(0);

	   /*register_sta1=0;
		register_end1=0;
		register_sta2=0;
		register_end2=0;*/

		memset(register_sta, 0, sizeof(register_sta));
		memset(register_end, 0, sizeof(register_end));

		/*dr_rpc_date.register_sta1=0;
		dr_rpc_date.register_end1=0;
		dr_rpc_date.register_sta2=0;
		dr_rpc_date.register_end2=0;*/
		memcpy(dr_rpc_date.register_sta, register_sta, sizeof(register_sta));
		memcpy(dr_rpc_date.register_end, register_end, sizeof(register_end));
		dr_rpc_date.cmd=0;
		register_dump_send_info(dr_rpc_date);
		//dvr_free((void *)vir_addr);
		read_flag=1;
		//pr_emerg("register_dump_test rpc done !!!\n");
		}
	}
}
#if 1
//#define DUMP "dump"
//#define DUMP_ERR(fmt, args...) rtd_printk(KERN_DEBUG, DUMP, fmt, ## args)
// echo "set1 0xB802502c-0xB802503c" > /sys/realtek_boards/reg_dump
// echo start > /sys/realtek_boards/reg_dump
// echo stop > /sys/realtek_boards/reg_dump
void reg_dump_set (const char *buffer)
{
	unsigned int tmp_register_sta;
	unsigned int tmp_register_end;
	unsigned int set_id;

	if (strncmp(buffer,"clear",strlen("clear"))==0)
		{

		memset(register_sta, 0, sizeof(register_sta));
		memset(register_end, 0, sizeof(register_end));
			pr_emerg("\nregister_dump clear\n");
		return;
		}

	if (strncmp(buffer,"start",strlen("start"))==0)
		{
			pr_emerg("\nregister_dump start\n");
		//Set_dump_function(1);
		IoReg_SetBits(VGIP_VGIP_CHN1_STATUS_reg,_BIT17);
		return;
		}

	if (strncmp(buffer,"stop",strlen("stop"))==0)
		{
			pr_emerg("\nregister_dump stop\n");
		//Set_dump_function(0);
		IoReg_ClearBits(VGIP_VGIP_CHN1_STATUS_reg,_BIT17);
		return;
		}

	if (sscanf(buffer, "set%d %x-%x",&set_id,&tmp_register_sta,&tmp_register_end)<1)
	{
			//DUMP_ERR("register dump set failed, invalid argument - %s\n", buffer);
			goto Fail;
	}
	 pr_emerg("\nset%d register_sta=%x,register_end=%x\n",set_id,tmp_register_sta,tmp_register_end);
	 if(set_id>=0 && set_id<=15)
	 {
		register_sta[set_id]=tmp_register_sta;
		register_end[set_id]=tmp_register_end;
		pr_emerg("\nregister_sta[%d]=%x,register_end[%d]=%x\n",set_id,register_sta[set_id],set_id,register_end[set_id]);
	 }
	return;
#if 0
	 if(1==set_id)
	 {
		register_sta1=tmp_register_sta;
		register_end1=tmp_register_end;
		pr_emerg("\nregister_sta1=%x,register_end1=%x\n",register_sta1,register_end1);
	 }
	 else if(2==set_id)
	 {
		register_sta2=tmp_register_sta;
		register_end2=tmp_register_end;
		pr_emerg("\nregister_sta2=%x,register_end2=%x\n",register_sta2,register_end2);
	 }
	return;
#endif
Fail:
    pr_emerg("%s fail.  %s\n\n\n",__func__,buffer);

    pr_emerg("\e[1;32m reg_dump related commands as follow\e[0m: (set no must between 1 and 4)\n");
    pr_emerg("echo clear > /sys/realtek_boards/reg_dump\n\n\n");
    pr_emerg("echo \"set 0x00cd2d00-0x00cd2d40\" > /sys/realtek_boards/reg_dump\n");
    pr_emerg("echo start > /sys/realtek_boards/reg_dump\n\n\n");
    pr_emerg("echo stop > /sys/realtek_boards/reg_dump\n\n\n");
    return ;
}
#endif
#endif

