/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2009
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: Jennifer $
 * @date 	$Date: 2017/03/16 14:30 $
 * @version 	$Revision: 0.1 $
 * @ingroup 	VIDEO_DECODER
 */

/**
 * @addtogroup vdc
 * @{
 */

/*================ Module dependency  =============== */
#define kernel_space_dumpdma

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/delay.h>
#ifdef kernel_space_dumpdma
#include <linux/fs.h>
#include <linux/kmod.h>
#include <linux/pageremap.h>
#include <linux/slab.h>
#endif

#include <uapi/linux/const.h>
#include <linux/mm.h>

//#include <tvscalercontrol/vdc/video.h>
//#include "tvscalercontrol/frontend/ifd_new.h"
//#include <tvscalercontrol/vdc/video_table.h>
//#include <tvscalercontrol/vdc/video_input.h>
//#include <tvscalercontrol/vdc/video_factory.h>
//#include <tvscalercontrol/vdc/yc_separation.h>
//#include <tvscalercontrol/vdc/yc_separation_table.h>
#include <tvscalercontrol/io/ioregdrv.h>
//#include <tvscalercontrol/scaler/scaleradc.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
//#include <tvscalercontrol/scaler/source.h>
//#include <tvscalercontrol/scaler/modeState.h>
//#include <tvscalercontrol/scaler/scalertimer.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>

#include <rbus/audio_reg.h>
#include "audio_hw_port.h"
#include "audio_hw_atv.h"
#include "audio_hw_aio.h"
#include "audio_hw_factory.h"

#define _SUCCESS		1
#define _FAIL			0
#define _ENABLE 			1
#define _DISABLE			0
#define _TRUE			1
#define _FALSE			0

#define __ALOG_SUBTAG "factory"

char *Audio_dma_name_table[]=
{
	"Audio_ADC_SIF_DATA",
	"Audio_BTSC_BB_DATA",	
	"Audio_A2_MAIN_DATA",
	"Audio_A2_SUB_DATA",
	"Audio_A2_PILOT_DATA",
	"Audio_NICAM_DEMOD_DATA",
	"IFD_SIF_DATA",
};


/*==================== Definitions ================ */
#define ScalerTimer_DelayXms(mSec)	Rt_Sleep(mSec)
#define rtdf_outl(offset, val)		IoReg_Write32(offset,val)
#define rtdf_inl(offset)			IoReg_Read32(offset)
#define rtdf_maskl(offset, andMask, orMask)	IoReg_Mask32(offset,andMask,orMask)
#define rtdf_setBits(offset, Mask) 			rtdf_outl(offset, (rtdf_inl(offset) |Mask))
#define rtdf_clearBits(offset, Mask) 		rtdf_outl(offset, ((rtdf_inl(offset) & ~(Mask))))

/*============= Local Functions' Phototype ============== */
#ifdef kernel_space_dumpdma
extern int get_usb_storage_mount_path_one(char *buf, size_t size);
#endif
void drvif_module_audio_factory_debug_get_dma_prefix(char* prefix)
{	
	uint8_t mode=0;
				
	audio_test_dma_control_register_RBUS test_dma_control_register_reg;
	test_dma_control_register_reg.regValue = rtdf_inl(AUDIO_Test_DMA_Control_Register_reg);

	switch(test_dma_control_register_reg.test_dma_in_sel)
	{
		case DMA_ADC_SIF_DATA:
			mode = 0;
			alog_info("[Audio] get DMA_ADC_SIF_DATA:%x\n",mode);
			break;
		case DMA_BTSC_BB_DATA:
			mode = 1;
			alog_info("[Audio] get DMA_BTSC_BB_DATA:%x\n",mode);
			break;
		case DMA_A2_MAIN_DATA:
			mode = 2;
			alog_info("[Audio] get DMA_A2_MAIN_DATA:%x\n",mode);			
			break;
		case DMA_A2_SUB_DATA:
			mode = 3;
			alog_info("[Audio] get DMA_A2_SUB_DATA:%x\n",mode);
			break;
		case DMA_A2_PILOT_DATA:
			mode = 4;
			alog_info("[Audio] get DMA_A2_PILOT_DATA:%x\n",mode);
			break;
		case DMA_NICAM_DEMOD_DATA:
			mode = 5;
			alog_info("[Audio] get DMA_NICAM_DEMOD_DATA:%x\n",mode);
			break;
		case DMA_IFD_SIF_DATA:
			mode = 6;
			alog_info("[Audio] get DMA_IFD_SIF_DATA:%x\n",mode);
			break;
			
	}
//	mode = drvif_module_vdc_factory_debug_get_dma_mode();
	strcpy(prefix, Audio_dma_name_table[mode]);
}

void drvif_module_audio_factory_TestDMA_mode_select(AUDIO_TEST_DMA_MODE_SEL value)
{
//	unsigned char  i;
	audio_test_dma_control_register_RBUS	test_dma_control_register_reg;
	test_dma_control_register_reg.regValue = rtdf_inl(AUDIO_Test_DMA_Control_Register_reg);
	test_dma_control_register_reg.test_dma_in_sel= value; // no ring	
	rtdf_outl( AUDIO_Test_DMA_Control_Register_reg, test_dma_control_register_reg.regValue);
	alog_info("[Audio] Test DMA mode select = %d\n",value);
}


uint8_t drvif_module_get_audio_factory_TestDMA_mode_select(void)
{
	audio_test_dma_control_register_RBUS	test_dma_control_register_reg;
	test_dma_control_register_reg.regValue = rtdf_inl(AUDIO_Test_DMA_Control_Register_reg);
	alog_info("[Audio] Get test DMA in sel = %d\n",test_dma_control_register_reg.test_dma_in_sel);
	return test_dma_control_register_reg.test_dma_in_sel;

}

#define GFP_DCU1                        0x00000001
#ifdef kernel_space_dumpdma
unsigned int m_audio_pCasheStartAddr = 0;
//unsigned int m_audio_PhyStartAddr = 0;
unsigned int m_audio_pNonCacheStartAddr = 0;
#else
unsigned char *m_audio_pCasheStartAddr = NULL;
unsigned long m_audio_PhyStartAddr;
unsigned char *m_audio_pNonCacheStartAddr;
#endif

#define SLRLIB_PRINTF(format, args...)

#ifdef kernel_space_dumpdma
static int exe_remount_usb_storage(void)
{
	int ret = -1;
	char path[] = "/bin/mount";
	char *argv[] = {path, "-t", "vfat","-o","remount,rw","/dev/sda1","/mnt/usbmounts/sda1", NULL};

	char *envp[] = {NULL};

 	alog_info("EXE %s\n",__FUNCTION__);
	ret = call_usermodehelper(path, argv, envp, UMH_WAIT_PROC);
	if(ret < 0)
		alog_err("fail ret=%d\n", ret);

	return 0;
}

static int exe_chmod_to_high_permision(void)
{
	int ret = -1;
	char path[] = "/bin/chmod";
	char *argv[] = {path, "777", "/mnt/usbmounts/sda1/*", NULL};

	char *envp[] = {NULL};

	alog_info("EXE %s\n",__FUNCTION__);
	ret = call_usermodehelper(path, argv, envp, UMH_WAIT_PROC);
	if(ret < 0)
		alog_err("fail ret=%d\n", ret);

	return 0;
}

#if 0 //not used
static int exe_mkdir(void)
{
	int ret = -1;
	char path[] = "/bin/mkdir";
	char *argv[] = {path, "/tmp/test123", NULL};
	char *envp[] = {NULL};

	alog_info("EXE %s\n",__FUNCTION__);
	ret = call_usermodehelper(path, argv, envp, UMH_WAIT_PROC);
	if(ret < 0)
		alog_err("fail ret=%d\n", ret);

	return 0;
}
#endif
#endif //kernel_space_dumpdma

void xDumpAudioRawData(unsigned int Length)
{
#if 1
//	unsigned int PhyStartAddr = 0;
	unsigned int iSize = 0;//, Width = 0, Height = 0;
	unsigned char *iStartAddr = 0;
	uint32_t * ptr = 0;
//	int iFileNum;
#ifdef kernel_space_dumpdma	
	struct file *pFile;
	loff_t offset = 0;
	ssize_t rc = 0;
	char *buf;
	size_t size = 256;

	buf = kzalloc(size, GFP_KERNEL);
	get_usb_storage_mount_path_one(buf, size);
#endif //kernel_space_dumpdma

	IoReg_SetBits(0xb8027220, _BIT1);  // cap1 freeze enable

	iStartAddr = (unsigned char *)m_audio_pNonCacheStartAddr;
	ptr = (uint32_t*) iStartAddr;

	alog_info("%x %x %x %x\n", *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3));

	iSize = Length;

	if (iStartAddr != 0 && iSize != 0) {
		char sFilePath[128], sFileName[32];
		drvif_module_audio_factory_debug_get_dma_prefix(&sFileName[0]);
		alog_info("file name: %s\n", sFileName);
#ifdef kernel_space_dumpdma
		exe_remount_usb_storage();
		exe_chmod_to_high_permision();
		snprintf(sFilePath, 128, "%s/%s%s%s", buf, "DMA_", sFileName, ".bin"); //Dump to USB
		//snprintf(sFilePath, 128, "%s/%s%s%s", "/tmp/usb/sda/sda1", "DMA_", sFileName, ".bin"); //Dump to USB
#else //kernel_space_dumpdma
		system("setprop persist.sampling_profiler 1");
	#if 1//------USB----------
		system("mount -t vfat -o remount,rw /dev/sda1 /mnt/usbmounts/sda1");
		sprintk(sFilePath, "%s", "chmod 777 /mnt/usbmounts/sda1/*");
		sprintk(sFilePath, "%s/%s%s%s", "/mnt/usbmounts/sda1", "DMA_", sFileName, ".bin"); //Dump to USB
	#else//------NFS----------//
		system("mount -t nfs -o tcp,nolock 172.21.15.135:/home/RTDOMAIN/jenniferchang/nfs/ /nfs");
		sprintk(sFilePath, "%s/%s%s%s", "/nfs", "VdDma_", sFileName, ".bin"); //Dump to NFS
	#endif
#endif //kernel_space_dumpdma
		alog_info("%s\n", sFilePath);

#ifdef kernel_space_dumpdma
	pFile = filp_open(sFilePath,O_CREAT |O_RDWR,0600);

	if(IS_ERR(pFile)) {
		alog_err("file open fail...\n");
		snprintf(sFilePath, 128, "%s/%s%s%s", "/mnt/usbmounts/sda1", "DMA_", sFileName, ".bin"); //Dump to USB
		alog_info("%s\n", sFilePath);
		pFile = filp_open(sFilePath,O_CREAT |O_RDWR,0600);
		if(IS_ERR(pFile)) {
			alog_err("file222222  open fail...\n");
			snprintf(sFilePath, 128, "%s/%s%s%s", "/mnt/media_rw/sda1", "DMA_", sFileName, ".bin"); //Dump to USB
			alog_info("%s\n", sFilePath);
			pFile = filp_open(sFilePath,O_CREAT |O_RDWR,0600);
			if(IS_ERR(pFile)) {
				alog_err("file33333  open fail...\n");
			}
		}
	}
	else {

	}
#else
	FILE *pFile = fopen(sFilePath, "w");
	if (pFile == NULL) {
		alog_err("file open fail...\n");
	} else { //frank@1017 change below code to solve scan tool warning
		iFileNum = fileno(pFile);
	}
#endif //kernel_space_dumpdma

	if (pFile) {
		unsigned int iCnt = 0, iBufIdx = 0;
		unsigned int *iCurAddr = (unsigned int*)iStartAddr;
		unsigned int bufArray[128];
		unsigned int iBuf = 0;
		while (iCnt < iSize) {
//			alog_info(".");
			iBuf = *iCurAddr;
			bufArray[iBufIdx] = iBuf;
			iBufIdx ++;
			if (iBufIdx >= 128) {
				#ifdef kernel_space_dumpdma
				rc = kernel_write(pFile, (const char *)bufArray, 128 * 4, offset);
				offset += rc;
				#else
				fwrite(bufArray, 128 * 4, 1, pFile);
				#endif //kernel_space_dumpdma
				iBufIdx = 0;
			}

			iCnt += 4;
			iCurAddr += 1; //move pointer 4byte
			//alog_info("iSize=%x\n",iCnt);
		}
		//alog_info("\n");
		// last
		if (iBufIdx > 0) {
			#ifdef kernel_space_dumpdma
			kernel_write(pFile, (const char *)bufArray, iBufIdx * 4, offset);
			#else
			fwrite(bufArray, iBufIdx * 4, 1, pFile);
			#endif //kernel_space_dumpdma
			iBufIdx = 0;
		}
		//alog_info(".\n");

		#ifndef kernel_space_dumpdma
		if (0 != fflush(pFile))
			alog_err("Flash to file fail\n");
		#endif //kernel_space_dumpdma

		// Sync to device
		#ifndef kernel_space_dumpdma
		if (0 != fsync(iFileNum)) {
			alog_err("fsync fail\n");
			if (fdatasync(iFileNum) == -1) {
				alog_err("fdatasync error!!\n");
			}			
		}
		#endif //kernel_space_dumpdma

		#ifdef kernel_space_dumpdma
		filp_close(pFile, NULL);
		#else
		fclose(pFile);
		#endif //kernel_space_dumpdma
		alog_info("write to file %s, size = %d\n", sFilePath, iSize);
		} else {
			alog_err("write file Error!\n");
		}
	}

	IoReg_ClearBits(0xb8027220, _BIT1); // cap1 freeze disable
#endif
}

// Clayton
// 16MBytes = 0x01000000(Length)
static StructMemBlock MemTag[MEMIDX_UNKNOW];	// memory tag information
uint32_t drvif_module_audio_factory_TestDMA_Enable(unsigned int Length)
{
	//unsigned int Data[2];
	uint32_t nAddr;
	uint32_t DMA_Start_Addr = 0;
	uint32_t DMA_Stop_Addr = 0;
	unsigned char i;
	audio_hw_process_control_RBUS	hw_process_control;
	//audio_test_dma_start_address_RBUS test_dma_start_address_reg;
	audio_test_dma_stop_address_RBUS test_dma_stop_address_reg;
	audio_test_mode_select_RBUS	test_mode_select_reg;
	audio_test_dma_control_register_RBUS	test_dma_control_register_reg;
	audio_sif_agc_status_RBUS sif_agc_status;
	audio_test_cur_address_RBUS	test_cur_address;

	// Disable Audio fw path
	rtdf_outl(AUDIO_TSADMA_CSR_reg,0x0);	// Disable PB DMA

  	hw_process_control.regValue = AIO_ReadRegister(AUDIO_HW_Process_Control_reg);
  	hw_process_control.basic_premium_sel = 0;//change audio path from DMA to HW path
  	AIO_WriteRegister(AUDIO_HW_Process_Control_reg, hw_process_control.regValue);

	rtdf_outl(AUDIO_ADMA_CSR_reg,0x30);	// Disable TS DMA

	IoReg_SetBits(0xb8027220, _BIT1);	// cap1 freeze enable

#if 0
	drvif_memory_free_block(MEMIDX_ALL);
#else
	for ( i=MEMIDX_VDC ; i<MEMIDX_ALL ; ++i ) { // clear all tag information
		MemTag[i].StartAddr = _DUMMYADDR;
		MemTag[i].Size = 0;
		MemTag[i].Status = UNDEFINED;
		}
#endif
	alog_info("release all memory !!\n");

#ifdef kernel_space_dumpdma
	m_audio_pCasheStartAddr = (unsigned int)dvr_malloc_uncached_specific(Length, GFP_DCU2_FIRST,(void **)&m_audio_pNonCacheStartAddr);
	if(m_audio_pCasheStartAddr == 0)	{
		alog_info("%s.%d\n", __FUNCTION__, __LINE__);
		alog_info("alloc idma sequence memory failed[%x]\n", m_audio_pCasheStartAddr);
		return FALSE;
	}
	nAddr = (unsigned int)dvr_to_phys((void *)m_audio_pCasheStartAddr);
	alog_info("cache:0x%x,noncache:0x%x,phy:0x%x\n",m_audio_pCasheStartAddr,m_audio_pNonCacheStartAddr,nAddr);
#else
	#if 0
	m_vd_pCasheStartAddr = (BYTE *)pli_allocContinuousMemorySpecific(m_vd_MallocSize, (char**)&m_vd_pNonCacheStartAddr, &m_vd_PhyStartAddr, GFP_DCU1);
	if (m_vd_pCasheStartAddr == NULL) {
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[VDC] release all memory !!\n");
		return _FAIL;
	} else {
		//physical address
		nAddr = (unsigned int)m_vd_PhyStartAddr;
		VDC_DEBUG_MSG(VDC_MSG_FACT,"[SLR_MEMORY][PLI][Cache:%x][Phy:%x][Size:%x]\n", (unsigned int)m_vd_pCasheStartAddr, (unsigned int)m_vd_PhyStartAddr, m_vd_MallocSize);
	}
	#else
	nAddr = drvif_memory_alloc_block(MEMIDX_VDC, Length, MEMALIGN_ANY) ;
	#endif
#endif

	DMA_Start_Addr = (nAddr) & 0xffffffc0;
	
	alog_info("re-alloc block !!\n");

	alog_info("Audio mem0 start = %x \n",DMA_Start_Addr);
	rtdf_outl(AUDIO_Test_DMA_Start_Address_reg,(uint32_t)DMA_Start_Addr);

	DMA_Stop_Addr = DMA_Start_Addr + ((Length>>5)<<5);

	alog_info("Audio mem0 stop = %x \n",DMA_Stop_Addr);
	rtdf_outl(AUDIO_Test_DMA_Stop_Address_reg,DMA_Stop_Addr);
	alog_info("start addr = 0x%x, length = 0x%x(32bytes), stop_Addr= 0x%x\n",DMA_Start_Addr,(Length>>5)<<5,DMA_Stop_Addr);

	// test mode
	test_mode_select_reg.regValue= rtdf_inl(AUDIO_Test_Mode_select_reg);
	test_mode_select_reg.dma_sel= 1;// test mode
	rtdf_outl(AUDIO_Test_Mode_select_reg,test_mode_select_reg.regValue);
	alog_info("DMA select = 0x%x\n",test_mode_select_reg.dma_sel);

	test_dma_control_register_reg.regValue = rtdf_inl(AUDIO_Test_DMA_Control_Register_reg);
	test_dma_control_register_reg.test_dma_en = 1;
	test_dma_control_register_reg.test_dma_rw_mode= 0; // write
	test_dma_control_register_reg.test_dma_ring= 0; // no ring	
	rtdf_outl(AUDIO_Test_DMA_Control_Register_reg, test_dma_control_register_reg.regValue);

	alog_info("[66e0] %08X %08X %08X %08X %08X\n", rtdf_inl(0xb80066e0), rtdf_inl(0xb80066e4) , rtdf_inl(0xb80066e8), rtdf_inl(0xb80066ec), rtdf_inl(0xb80066f0));

/*====== Test DMA writing ===*/
// Clayton, for debug
// [start]
	sif_agc_status.regValue = rtdf_inl(AUDIO_sif_agc_status_reg);
	if(sif_agc_status.ovf== 1)
	alog_info("[Dump DMA function] SIF overflow, sif_agc_status= %x\n", sif_agc_status.regValue );
// [end]

	//while(test_cur_address.test_dma_cur_addr != (endaddress & (0xFFFFF << 7) ) )	// P' [26:7] instead of P [24:5]
	test_cur_address.regValue = rtdf_inl(AUDIO_Test_Cur_Address_reg);
	test_dma_stop_address_reg.regValue = rtdf_inl(AUDIO_Test_DMA_Stop_Address_reg);
	while(test_cur_address.test_dma_cur_addr!= test_dma_stop_address_reg.test_dma_stop_addr)
	{
			alog_debug("[Dump DMA function] curr_Address %x\n", test_cur_address.regValue);
			test_cur_address.regValue = rtdf_inl(AUDIO_Test_Cur_Address_reg);

			test_dma_stop_address_reg.regValue = rtdf_inl(AUDIO_Test_DMA_Stop_Address_reg);
			alog_debug("[Dump DMA function] stop_Address %x\n", test_dma_stop_address_reg.regValue);						
	}	
	alog_info("[Dump DMA function] curr_Address %x done\n", test_cur_address.regValue);

	if( ((i = rtdf_inl(AUDIO_Test_DMA_Control_Register_reg))  & 0x3) != 0)
	{
		alog_info("[Dump DMA function] dma overflow=====Dump DMA Fail!!!!!!!!!\n");
	}
	else
	{
		alog_info("[Dump DMA function] dma ok\n");
		
	}

/*===========================*/

// test dma disable
	test_mode_select_reg.regValue= rtdf_inl(AUDIO_Test_Mode_select_reg);
	test_mode_select_reg.dma_sel= 0;// test mode
	rtdf_outl(AUDIO_Test_Mode_select_reg,test_mode_select_reg.regValue);

	test_dma_control_register_reg.regValue = rtdf_inl(AUDIO_Test_DMA_Control_Register_reg);
	test_dma_control_register_reg.test_dma_en = 0;
	rtdf_outl(AUDIO_Test_DMA_Control_Register_reg, test_dma_control_register_reg.regValue);

	alog_info("\nTest DMA Disable~~\n");

	//memcpy(m_audio_pCasheStartAddr, m_audio_dmaStartAddr, Length);

	xDumpAudioRawData(Length);

	return (0xa0000000|DMA_Start_Addr);	// return print address
}
//=====================================================================================
int audio_hw_dbg_EXECUTE(const int cmd_index, char **cmd_pointer)
{
	static const char *delim = ",";
	int dump_sif_en = -1, sif_data_sel = -1;
	char *token = NULL;

	switch (cmd_index) {
	case AUDIO_HW_DBG_CMD_DUMP_SIF:
	{
		/* Parse the value right after the character '=' */
		if (*cmd_pointer == NULL) {
			alog_err("dump sif command is incorrect.\n");
			return -1;
		}

		token = strsep(cmd_pointer, delim);
		if (token == NULL || kstrtoint(token, 0, &dump_sif_en) != 0) {
			alog_err("failed to parse the dump sif enable flag.\n");
			return -1;
		}

		token = strsep(cmd_pointer, delim);
		if (token == NULL || kstrtoint(token, 0, &sif_data_sel) != 0) {
			alog_err("failed to parse the sif data select flag.\n");
			return -1;
		}	

		alog_info("dump_sif_en = %d\n", dump_sif_en);
		alog_info("sif_data_sel = %d\n", sif_data_sel);

		if(dump_sif_en < 0 || dump_sif_en > 1)
		{
			alog_err("over the range of sif data enable flag.\n");
			return -1;
		}

		if(sif_data_sel < DMA_ADC_SIF_DATA || sif_data_sel > DMA_IFD_SIF_DATA)
		{
			alog_err("over the range of sif data select flag.\n");
			return -1;
		}

		if(dump_sif_en)
		{
			alog_info("start dump sif data\n");
			drvif_module_audio_factory_TestDMA_mode_select((AUDIO_TEST_DMA_MODE_SEL)sif_data_sel);
			drvif_module_audio_factory_TestDMA_Enable(0x00800000);
		}		
		break;
	}
	default:
		alog_err("unknown command.\n");
		return -1;
	}	

	return 0;
}
