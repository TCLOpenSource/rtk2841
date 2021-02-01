#include <linux/delay.h>
#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/platform_device.h>
#include <linux/mtd/mtd.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
#include <rtk_kdriver/RPCDriver.h>
#include <mach/system.h>
#include <mach/timex.h>
#include <linux/pageremap.h>
#include <uapi/linux/const.h>
#include <linux/mm.h>
#include <linux/dma-mapping.h>/*DMA*/

#include <rbus/pst_i2rnd_reg.h>
#include <rbus/mdomain_disp_reg.h>
#include <rbus/scaleup_reg.h>
#include <rbus/ppoverlay_reg.h>

#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <scalercommon/scalerDrvCommon.h>
#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>

#include <tvscalercontrol/scalerdrv/scaler_pst.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
#include <tvscalercontrol/scalerdrv/scalermemory.h>
#include <tvscalercontrol/vip/ultrazoom.h>
#include "tvscalercontrol/scalerdrv/scalerdisplay.h"
#include <tvscalercontrol/scalerdrv/zoom_smoothtoggle.h>
#include "../tvscalercontrol/scaler_vscdev.h"

//temp add 

/***********************************REGISTER RANGE*****************************************************/
//mdisplay  0xb8027300 - 0xB80274F8
#define MAIN_MDISP_START_REGISTER					MDOMAIN_DISP_DDR_MainPreVStart_reg
#define MAIN_MDISP_END_REGISTER					MDOMAIN_DISP_Display_byte_channel_swap_reg
#define MAIN_MDISP_REGISTER_NUM					((MAIN_MDISP_END_REGISTER -MAIN_MDISP_START_REGISTER + 4)/4)
#define MAIN_MDISP_register_range(addr)				(((addr>=MAIN_MDISP_START_REGISTER) &&(addr <=MAIN_MDISP_END_REGISTER)) ? 1: 0 )
#define MAIN_MDISP_DDR_range(addr)					((((addr>=MAIN_MDISP_START_REGISTER) &&(addr <=MDOMAIN_DISP_Disp_main_enable_reg)) \
												|| (addr==MDOMAIN_DISP_DDR_Main_BM_DMA_reg) \
												|| ((addr>=MDOMAIN_DISP_dispm_decmp_resolution_reg)&&(addr<=MDOMAIN_DISP_dispm_trunc_color_4_reg)) \
												|| ((addr>=MDOMAIN_DISP_DispMain_BoundaryAddr1_reg) &&(addr <=MDOMAIN_DISP_DispMain_BoundaryAddr2_reg)) \
												|| ((addr>=MDOMAIN_DISP_DDR_Main_R_1ST_Addr_reg) &&(addr <=MDOMAIN_DISP_DDR_Main_R_3RD_Addr_reg)) \
												|| ((addr>=MDOMAIN_DISP_DISPM_RM_reg) &&(addr <=MDOMAIN_DISP_Display_byte_channel_swap_reg))) ? 1: 0 )

//uzu  0xb8027300 - 0xB80274F8
#define MAIN_UZU_START_REGISTER				SCALEUP_D_UZU_Globle_Ctrl_reg
#define MAIN_UZU_END_REGISTER					SCALEUP_COEF_TABLE_CTL_3_reg
#define MAIN_UZU_REGISTER_NUM					((MAIN_UZU_END_REGISTER -MAIN_UZU_START_REGISTER + 4)/4)
#define MAIN_UZU_register_range(addr)				(((addr>=MAIN_UZU_START_REGISTER) &&(addr <=MAIN_UZU_END_REGISTER)) ? 1: 0 )
#define MAIN_UZU_DDR_range(addr)					((((addr>=MAIN_UZU_START_REGISTER) &&(addr <=SCALEUP_DM_UZU_Peaking_Gain_reg)) \
												|| (addr==SCALEUP_DM_UZUMAIN_H_PARTIAL_DROP_reg)  || (addr==SCALEUP_DM_UZUMAIN_Adapt8tap_reg) \
												|| ((addr>=SCALEUP_DM_UZU_V6CTRL_reg) &&(addr <=SCALEUP_DM_UZU_Initial_Value_left_reg)) \
												|| ((addr>=SCALEUP_DM_DIR_UZU_Ctrl_reg) &&(addr <=SCALEUP_DM_DIR_UZU_AngleCheck_reg))) ? 1: 0 )


//mtg  0xb8027300 - 0xB80274F8
#define MAIN_DTG_START_REGISTER				PPOVERLAY_Display_Timing_CTRL1_reg
#define MAIN_DTG_END_REGISTER					PPOVERLAY_MAIN_Active_V_Start_End_reg
#define MAIN_DTG_REGISTER_NUM					((MAIN_DTG_END_REGISTER -MAIN_DTG_START_REGISTER + 4)/4)
#define MAIN_DTG_register_range(addr)				(((addr>=MAIN_DTG_START_REGISTER) &&(addr <=MAIN_DTG_END_REGISTER)) ? 1: 0 )
#define MAIN_DTG_DDR_range(addr)					((((addr>=PPOVERLAY_DH_DEN_Start_End_reg) &&(addr <=PPOVERLAY_MAIN_Active_V_Start_End_reg))) ? 1: 0 )

/*================================== PST COMMAND==============================*/
#define PST_I_M_REGISTER_NUMBER 500
#define PST_I_S_REGISTER_NUMBER 500
#define PST_DISPM_REGISTER_NUMBER (MAIN_MDISP_REGISTER_NUM + MAIN_UZU_REGISTER_NUM + MAIN_DTG_REGISTER_NUM)
#define PST_DISPS_REGISTER_NUMBER 500
#define PST_GDMA_REGISTER_NUMBER 500
#define PST_DISPM_BLOCK_SIZE ((PST_DISPM_REGISTER_NUMBER + ((PST_DISPM_REGISTER_NUMBER%2) ? 1 : 0)) / 2 * 16) //queue size(total block size) = (regisrer num/2) * 128bits = (regisrer num/2) * 16bytes

#define PST_DMA_LENGTH 16
#define PST_DMA_WATERLEVEL 96

#define PST_REGISTER_DDR_SIZE  8
#define REGISTER_VALUE_SIZE  4

#define PST_ENABLE_ADDR_SIZE 4
#define PST_WRITE_CMD_ADDR_SIZE 4
#define PST_READ_CMD_ADDR_SIZE 4
#define PST_INFO_SIZE (PST_ENABLE_ADDR_SIZE + PST_WRITE_CMD_ADDR_SIZE + PST_READ_CMD_ADDR_SIZE)
//PST

/*================================== Variables ==============================*/
static PST_START_ADDR pst_st_addr;
static PST_STEP_SIZE pst_step_size;
//static PST_CMD_BUF pst_cmd_buf;
PST_DISPM_SCPU_VIR_START_ADDR pst_dispm_scpu_vir_addr;
static unsigned int pst_queue_size = 0;

#ifdef CONFIG_PST_ENABLE

/***********************************PST FUNCTION*****************************************************/
_PST_MODE_T drvif_scaler_pst_get_mode(void)
{
	return pst_st_addr.pst_mode ;
}
unsigned char Scaler_main_md_pst_get_enable(void)
{
	if (pst_dispm_scpu_vir_addr.pst_enable_vir_addr) {
		return (*(volatile unsigned char *)(pst_dispm_scpu_vir_addr.pst_enable_vir_addr));
	} else {
		return 0;
	}
}
void Scaler_main_md_pst_set_enable(unsigned char enable)
{
	if (pst_dispm_scpu_vir_addr.pst_enable_vir_addr) {
		*(volatile unsigned char *)(pst_dispm_scpu_vir_addr.pst_enable_vir_addr) = enable;
	}
}

unsigned char Scaler_pst_main_md_get_read_cmd_num(void)
{
	if (pst_dispm_scpu_vir_addr.pst_dispm_read_cmd_vir_addr) {
		return (*(volatile unsigned char *)(pst_dispm_scpu_vir_addr.pst_dispm_read_cmd_vir_addr));
	} else {
		return 0;
	}
}
void Scaler_pst_main_md_set_read_cmd_num(unsigned char enable)
{
	if (pst_dispm_scpu_vir_addr.pst_dispm_read_cmd_vir_addr) {
		*(volatile unsigned char *)(pst_dispm_scpu_vir_addr.pst_dispm_read_cmd_vir_addr) = enable;
	}
}
unsigned char Scaler_pst_main_md_get_write_cmd_num(void)
{
	if (pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr) {
		return (*(volatile unsigned char *)(pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr));
	} else {
		return 0;
	}
}
void Scaler_pst_main_md_set_write_cmd_num(void)
{
	if (pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr) {
#if 1
		unsigned char cmd_num = (*(volatile unsigned char *)(pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr));		
	//	unsigned int curr_pst_md_write_buffer_addr=Scaler_pst_cmd_buffer_write_offset_addr(pst_dispm_vcpu_vir_addr.s0_mdisp_st_vir_addr);
		if ((cmd_num + 1 )> PST_CMD_NUMBER) {
			cmd_num = 0;
		} else {
			cmd_num = cmd_num + 1;
		}
	//	ROSPrintfInternal("pst md write cmd_num=%d\n",cmd_num);
		*(volatile unsigned char *)(pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr) = cmd_num;
#else
		*(volatile unsigned char *)(pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr) = 0;
#endif
	//	memcpy((unsigned char *)Scaler_pst_cmd_buffer_write_offset_addr(pst_dispm_vcpu_vir_addr.s0_mdisp_st_vir_addr), (unsigned char *)curr_pst_md_write_buffer_addr, sizeof(unsigned char) *  pst_buffer_addr.dispm_cmd_buffer_size);
	}
}
void Scaler_pst_main_md_write_default_cmd_num(void)
{
	if (pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr) {
		*(volatile unsigned char *)(pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr) = 0;
	}
}
unsigned int Scaler_pst_cmd_buffer_write_offset_addr(unsigned int addr)
{
	unsigned int curr_addr= 0;
	if (pst_st_addr.pst_mode  == _MAIN_MD) {
		curr_addr = addr + Scaler_pst_main_md_get_write_cmd_num() * pst_st_addr.dispm_cmd_buffer_size;
	}
	return curr_addr;
}
unsigned int Scaler_pst_cmd_buffer_read_offset_addr(unsigned int addr)
{
	unsigned int curr_addr= 0;
	if (pst_st_addr.pst_mode  == _MAIN_MD) {
		curr_addr = addr + Scaler_pst_main_md_get_read_cmd_num() * pst_st_addr.dispm_cmd_buffer_size;
	}
	return curr_addr;
}
void drvif_scaler_pst_initial(_PST_MODE_T mode)
{
	//unsigned int block_mode = 0;
	//share memory allocation
	unsigned int cache_addr;
	unsigned int blk_size_mod = 0;
	unsigned int pst_blk_size = 0;
	unsigned int pst_allocate_size = 0;

	//align total queue size
	pst_blk_size = PST_DISPM_BLOCK_SIZE;
	blk_size_mod = pst_blk_size % (PST_DMA_LENGTH*8);//No remain so need align length size length*64bits
	if(blk_size_mod != 0){
		pst_blk_size = pst_blk_size + ((PST_DMA_LENGTH*8) - blk_size_mod);
	}

	pst_queue_size = pst_blk_size*(PST_CMD_NUMBER+1);
	pst_allocate_size =pst_queue_size+PST_INFO_SIZE;
	printk(KERN_EMERG"[%s]pst_blk_size=%d,pst_queue_size=%d,pst_allocate_size=%d\n",__FUNCTION__,pst_blk_size,pst_queue_size,pst_allocate_size);
	if (mode == _MAIN_MD) {
		if (pst_st_addr.dispm_st_addr == 0) {
			cache_addr= (unsigned int)dvr_malloc_uncached_specific(pst_allocate_size, GFP_DCU1_FIRST, (void*) & (pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr));
			pst_st_addr.dispm_st_addr = (unsigned int)dvr_to_phys((void*)cache_addr);
			pst_st_addr.pst_enable_addr = pst_st_addr.dispm_st_addr + pst_queue_size;
			pst_st_addr.write_dispm_cmd_num_addr = pst_st_addr.pst_enable_addr + PST_ENABLE_ADDR_SIZE;
			pst_st_addr.read_dispm_cmd_num_addr = pst_st_addr.write_dispm_cmd_num_addr + PST_WRITE_CMD_ADDR_SIZE;
		}
		if (pst_st_addr.dispm_st_addr == 0) {
			pr_debug("[PST]malloc pst buffer fail .......................................\n");
			pr_debug("[PST]dispm_st_addr = %x\n", pst_st_addr.dispm_st_addr);
			return;
		} else {
			memset((unsigned char *)pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr, 0, sizeof(unsigned char) * pst_allocate_size);
		}
		pst_st_addr.dispm_cmd_buffer_size = pst_blk_size;
		pst_st_addr.pst_mode = _MAIN_MD;
		printk(KERN_EMERG"[%s][pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr=%x,pst_st_addr.dispm_st_addr=%x\n",__FUNCTION__, pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr,pst_st_addr.dispm_st_addr);
		printk(KERN_EMERG"[%s][pst_st_addr.pst_enable_addr=%x,pst_st_addr.pst_mode=%d\n",__FUNCTION__, pst_st_addr.pst_enable_addr,pst_st_addr.pst_mode );
		Scaler_pst_setbuffer(_MAIN_MD);		
	} else if (mode == _SUB_MD) {
		if (pst_st_addr.disps_st_addr == 0) {
		//	pst_st_addr.disps_st_addr =  (unsigned int)dvr_malloc_uncached_specific(pst_allocate_size, GFP_DCU1_FIRST, (void*) & (pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr));
		}
		if (pst_st_addr.disps_st_addr == 0) {
			pr_debug("[PST]malloc pst buffer fail .......................................\n");
			pr_debug("[PST]disps_st_addr = %x\n", pst_st_addr.disps_st_addr);
			return;
		}
	} else if (mode == _MAIN_VO_IMD) {
	#ifdef CONFIG_I2RND_ENABLE
		if (!Scaler_I2rnd_get_enable())
	#endif
		{
			if (pst_st_addr.i_m_st_addr == 0) {
		//		pst_st_addr.i_m_st_addr =  (unsigned int)dvr_malloc_uncached_specific(pst_allocate_size, GFP_DCU1_FIRST, (void*) & (pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr));
			}
		}
		if (pst_st_addr.dispm_st_addr == 0) {
		//	pst_st_addr.dispm_st_addr =  (unsigned int)dvr_malloc_uncached_specific(pst_allocate_size, GFP_DCU1_FIRST, (void*) & (pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr));
		}
		if ((pst_st_addr.dispm_st_addr == 0) ||(pst_st_addr.i_m_st_addr == 0)) {
			pr_debug("[PST]malloc pst buffer fail .......................................\n");
			pr_debug("[PST]i_m_st_addr = %x\n", pst_st_addr.i_m_st_addr);
			pr_debug("[PST]dispm_st_addr = %x\n", pst_st_addr.dispm_st_addr);
			return;
		}
		pst_st_addr.pst_mode = _MAIN_VO_IMD;
	} else if (mode == _SUB_VO_IMD) {
		if (pst_st_addr.i_s_st_addr == 0) {
		//	pst_st_addr.i_s_st_addr =  (unsigned int)dvr_malloc_uncached_specific(pst_allocate_size, GFP_DCU1_FIRST, (void*) & (pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr));
		}
		if (pst_st_addr.disps_st_addr == 0) {
		//	pst_st_addr.disps_st_addr =  (unsigned int)dvr_malloc_uncached_specific(pst_allocate_size, GFP_DCU1_FIRST, (void*) & (pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr));
		}
		if ((pst_st_addr.disps_st_addr == 0) ||(pst_st_addr.i_s_st_addr == 0)) {
			pr_debug("[PST]malloc pst buffer fail .......................................\n");
			pr_debug("[PST]i_s_st_addr = %x\n", pst_st_addr.i_s_st_addr);
			pr_debug("[PST]disps_st_addr = %x\n", pst_st_addr.disps_st_addr);
			return;
		}
		pst_st_addr.pst_mode = _SUB_VO_IMD;
	} else {
		if (pst_st_addr.gdma_st_addr == 0) {
		//	pst_st_addr.gdma_st_addr =  (unsigned int)dvr_malloc_uncached_specific(pst_allocate_size, GFP_DCU1_FIRST, (void*) & (pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr));
		}
		if (pst_st_addr.gdma_st_addr == 0) {
			pr_debug("[PST]malloc pst buffer fail .......................................\n");
			pr_debug("[PST]gdma_st_addr = %x\n", pst_st_addr.gdma_st_addr);
			return;
		}
		pst_st_addr.pst_mode = _DEFAULT_OFF;
	}
	//PST dma setting
	drvif_scaler_pst_dma_setting(PST_CMD_NUMBER, pst_blk_size, mode);

}
void drvif_scaler_pst_uninitial(_PST_MODE_T mode)
 {
 	//disable pst
	drvif_scaler_pst_top_ctrl(_DISABLE, mode);
	
 //free memory
	if (mode == _MAIN_MD) {
		Scaler_main_md_pst_set_enable(_DISABLE);
		return;//FIX ME,below code will crash
		if((pst_st_addr.dispm_st_addr != 0) && (pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr != 0)){			
 			dvr_free((void *)pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr);
 			pst_st_addr.dispm_st_addr = 0;
			pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr = 0;
			pst_dispm_scpu_vir_addr.pst_enable_vir_addr = 0;
			pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr = 0;
			pst_dispm_scpu_vir_addr.pst_dispm_read_cmd_vir_addr = 0;
 		}
	}	
 	pst_st_addr.pst_mode = _DEFAULT_OFF;
}
void drvif_scaler_pst_top_ctrl(bool enable, _PST_MODE_T mode)
{
	pst_i2rnd_top_ctrl_RBUS   top_ctrl;
	top_ctrl.regValue = rtd_inl(PST_I2RND_TOP_CTRL_reg);
	if (enable) {
		if (mode == _MAIN_MD) {
			top_ctrl.dispm_pst_en = 1;
		} else if (mode == _MAIN_VO_IMD) {
		#ifdef CONFIG_I2RND_ENABLE
			if (Scaler_I2rnd_get_enable()) {
				top_ctrl.i_main_pst_en = 0;
			} else
		#endif
			{
				top_ctrl.i_main_pst_en = 1;
			}
			top_ctrl.dispm_pst_en = 1;
		}  else if (mode == _SUB_MD) {
		//	top_ctrl.disps_pst_en = 1;
		}  else if (mode == _SUB_VO_IMD) {
		//	top_ctrl.i_sub_pst_en = 1;
		//	top_ctrl.disps_pst_en = 1;
		}  else {
			top_ctrl.gdma_pst_en = 1;
		} 
	} else {
		top_ctrl.i_main_pst_en = 0;
	//	top_ctrl.i_sub_pst_en = 0;
		top_ctrl.dispm_pst_en = 0;
	//	top_ctrl.disps_pst_en = 0;
		top_ctrl.gdma_pst_en = 0;
	}
	IoReg_Write32(PST_I2RND_TOP_CTRL_reg, top_ctrl.regValue);
}
#if 0
void drvif_scaler_pst_step_size(unsigned int blk_size,_PST_MODE_T mode)
{
    /////  block size = (DMA.num*128/8)*N
    pst_step_size.i_m_blk_size = blk_size;
    pst_step_size.i_s_blk_size = blk_size;
    pst_step_size.dispm_blk_size = blk_size;
    pst_step_size.disps_blk_size = blk_size;
    pst_step_size.gdma_blk_size = blk_size;
}
#endif
void drvif_scaler_pst_dma_setting(unsigned int cmd_num, unsigned int blk_size,_PST_MODE_T mode)
{

	/*
	block size = 592 * 8 = 4736 bits
	Queue buffer number = cmd_num = 16
	DMA length = 16

	1. register number = (4736 / 128 * 2) * 16 = 1184
	2. total block size = 4736 * 16 = 75776 bits = (1184 / 2) * 128bits
	3. DMA number = (block size / DMA length) / 64   (unit. 64bits)
	                       = (4736 / 16) / 64
	                       = 4
	*/
	pst_i2rnd_dma_buf_num_RBUS dma_buf_num;
    	pst_i2rnd_dma_ctrl_RBUS	dma_ctrl;
	pst_i2rnd_dma_num2_RBUS dma_num2;
	pst_i2rnd_dma_num3_RBUS	dma_num3;
	pst_i2rnd_dma_num4_RBUS	dma_num4;

	//cmd number
	dma_buf_num.regValue = rtd_inl(PST_I2RND_DMA_BUF_NUM_reg);
	dma_buf_num.dma_buffer_num = cmd_num;
	IoReg_Write32(PST_I2RND_DMA_BUF_NUM_reg, dma_buf_num.regValue);

	///////////////////////////////////////////
	// WATER/NUM/LENGTH
	///////////////////////////////////////////
	dma_ctrl.regValue = rtd_inl(PST_I2RND_DMA_CTRL_reg);
	dma_ctrl.dma_wtlvl = PST_DMA_WATERLEVEL;
	dma_ctrl.dma_len = PST_DMA_LENGTH;
	IoReg_Write32(PST_I2RND_DMA_CTRL_reg, dma_ctrl.regValue);

	//start address
	if (mode == _MAIN_MD) {
		pst_step_size.dispm_blk_size = blk_size;
		IoReg_Write32(PST_I2RND_DMA_ADDR6_reg, pst_st_addr.dispm_st_addr);
		IoReg_Write32(PST_I2RND_DMA_STEP6_reg, pst_step_size.dispm_blk_size);

		dma_num3.regValue = rtd_inl(PST_I2RND_DMA_NUM3_reg);
		dma_num3.dma_num_pst_dispm = pst_step_size.dispm_blk_size/8/dma_ctrl.dma_len;
    		IoReg_Write32(PST_I2RND_DMA_NUM3_reg, dma_num3.regValue);

	} else if (mode == _MAIN_VO_IMD) {
		pst_step_size.i_m_blk_size = blk_size;
		pst_step_size.dispm_blk_size = blk_size;
		#ifdef CONFIG_I2RND_ENABLE
		if (!Scaler_I2rnd_get_enable())
		#endif
		{
			IoReg_Write32(PST_I2RND_DMA_ADDR4_reg, pst_st_addr.i_m_st_addr);
			IoReg_Write32(PST_I2RND_DMA_STEP4_reg, pst_step_size.i_m_blk_size);
		//dma number
			dma_num2.regValue = rtd_inl(PST_I2RND_DMA_NUM2_reg);
			dma_num2.dma_num_pst_i_main = pst_step_size.i_m_blk_size/8/dma_ctrl.dma_len;
			IoReg_Write32(PST_I2RND_DMA_NUM2_reg, dma_num2.regValue);			
		}
		IoReg_Write32(PST_I2RND_DMA_ADDR6_reg, pst_st_addr.dispm_st_addr);
		IoReg_Write32(PST_I2RND_DMA_STEP6_reg, pst_step_size.dispm_blk_size);

		dma_num3.regValue = rtd_inl(PST_I2RND_DMA_NUM3_reg);
		dma_num3.dma_num_pst_dispm = pst_step_size.dispm_blk_size/8/dma_ctrl.dma_len;
    		IoReg_Write32(PST_I2RND_DMA_NUM3_reg, dma_num3.regValue);

	} else if (mode == _SUB_MD) {
		pst_step_size.disps_blk_size = blk_size;
#if 0//no sub
		IoReg_Write32(PST_I2RND_DMA_ADDR7_reg, pst_st_addr.disps_st_addr);
		IoReg_Write32(PST_I2RND_DMA_STEP7_reg, pst_step_size.disps_blk_size);

		dma_num3.regValue = rtd_inl(PST_I2RND_DMA_NUM3_reg);
		dma_num3.dma_num_pst_disps = pst_step_size.disps_blk_size/8/dma_ctrl.dma_len;
		IoReg_Write32(PST_I2RND_DMA_NUM3_reg, dma_num3.regValue);
#endif
	} else if (mode == _SUB_VO_IMD) {
		pst_step_size.i_s_blk_size = blk_size;
		pst_step_size.disps_blk_size = blk_size;
	#if 0	 
		IoReg_Write32(PST_I2RND_DMA_ADDR5_reg, pst_st_addr.i_s_st_addr);
		IoReg_Write32(PST_I2RND_DMA_STEP5_reg, pst_step_size.i_s_blk_size);
		IoReg_Write32(PST_I2RND_DMA_ADDR7_reg, pst_st_addr.disps_st_addr);
		IoReg_Write32(PST_I2RND_DMA_STEP7_reg, pst_step_size.disps_blk_size);

		  //dma number
		dma_num2.regValue = rtd_inl(PST_I2RND_DMA_NUM2_reg);
		dma_num2.dma_num_pst_i_sub = pst_step_size.i_s_blk_size/8/dma_ctrl.dma_len;
		IoReg_Write32(PST_I2RND_DMA_NUM2_reg, dma_num2.regValue);

		dma_num3.regValue = rtd_inl(PST_I2RND_DMA_NUM3_reg);
		dma_num3.dma_num_pst_disps = pst_step_size.disps_blk_size/8/dma_ctrl.dma_len;
		IoReg_Write32(PST_I2RND_DMA_NUM3_reg, dma_num3.regValue);
	#endif
	} else {
		pst_step_size.gdma_blk_size = blk_size;  
		IoReg_Write32(PST_I2RND_DMA_ADDR8_reg, pst_st_addr.gdma_st_addr);
		IoReg_Write32(PST_I2RND_DMA_STEP8_reg, pst_step_size.gdma_blk_size);

		dma_num4.regValue = rtd_inl(PST_I2RND_DMA_NUM4_reg);
		dma_num4.dma_num_pst_gdma = pst_step_size.gdma_blk_size/8/dma_ctrl.dma_len;
		IoReg_Write32(PST_I2RND_DMA_NUM4_reg, dma_num4.regValue);
	} 
#if 0
    ////////////////////////////////////////
    //  update current status
    ////////////////////////////////////////
    pst_st_addr.i_m_cur_addr = pst_st_addr.i_m_st_addr;
    pst_st_addr.i_s_cur_addr = pst_st_addr.i_s_st_addr;
//    pst_st_addr.dispm_cur_addr = pst_st_addr.dispm_st_addr;
    pst_st_addr.disps_cur_addr = pst_st_addr.disps_st_addr;
    pst_st_addr.gdma_cur_addr = pst_st_addr.gdma_st_addr;

    pst_cmd_buf.i_m_cur_cmd = 0;
    pst_cmd_buf.i_s_cur_cmd = 0;
    pst_cmd_buf.dispm_cur_cmd = 0;
    pst_cmd_buf.disps_cur_cmd = 0;
    pst_cmd_buf.gdma_cur_cmd = 0;
#endif
}

/*
1.send RPC the cmd queue buffer info from SCPU to VCPU
2.record I2run S0,S1 Queue each IP start register setting start point in SCPU
*/
unsigned char	Scaler_pst_setbuffer(_PST_MODE_T  mode)
{
	unsigned int *pulTemp = NULL;
	unsigned int i=0, ulItemCount = 0;
	PST_START_ADDR pst_addr_info={0};
	if (mode == _MAIN_MD) {
		if (pst_st_addr.dispm_st_addr ==0) {
			pr_debug(" pst  _MAIN_MD not alloc memroy\n");
			return 0;
		}
		pst_addr_info.dispm_st_addr		= pst_st_addr.dispm_st_addr;
		pst_addr_info.write_dispm_cmd_num_addr	= pst_st_addr.write_dispm_cmd_num_addr;
		pst_addr_info.read_dispm_cmd_num_addr			=  pst_st_addr.read_dispm_cmd_num_addr;
		pst_addr_info.dispm_cur_addr		= pst_st_addr.dispm_st_addr;
	}
	pst_addr_info.pst_enable_addr	= pst_st_addr.pst_enable_addr;
	pst_addr_info.pst_mode			= mode;
	pst_addr_info.dispm_cmd_buffer_size = pst_st_addr.dispm_cmd_buffer_size;
	
	pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_PST_SET_BUFFER);
	ulItemCount = sizeof(PST_START_ADDR) /  sizeof(unsigned int);
	if (pulTemp) {
		memcpy(pulTemp, &pst_addr_info, sizeof(PST_START_ADDR));
		for (i = 0; i < ulItemCount; i++)
				pulTemp[i] = htonl(pulTemp[i]);

		if (0 != Scaler_SendRPC(SCALERIOC_PST_SET_BUFFER,0,0))
		{
			printk(KERN_EMERG"set buffer address for pst fail !!!\n");
			return 0;

		}
	}

	if (mode == _MAIN_MD) {
		pst_dispm_scpu_vir_addr.s0_uzu_st_vir_addr			= pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr	+ MAIN_MDISP_REGISTER_NUM * PST_REGISTER_DDR_SIZE;
		pst_dispm_scpu_vir_addr.s0_dtg_st_vir_addr			= pst_dispm_scpu_vir_addr.s0_uzu_st_vir_addr		+ MAIN_UZU_REGISTER_NUM * PST_REGISTER_DDR_SIZE;
		pst_dispm_scpu_vir_addr.pst_enable_vir_addr			= pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr 	+ pst_queue_size;
		pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr			= pst_dispm_scpu_vir_addr.pst_enable_vir_addr 	+ PST_ENABLE_ADDR_SIZE;
		pst_dispm_scpu_vir_addr.pst_dispm_read_cmd_vir_addr			= pst_dispm_scpu_vir_addr.pst_dispm_write_cmd_vir_addr 	+ PST_WRITE_CMD_ADDR_SIZE;

		printk(KERN_EMERG"pst_md_end_addr=%x\n",pst_st_addr.dispm_st_addr + pst_queue_size);
		printk(KERN_EMERG"[pst_dispm_scpu_vir_addr]s0_uzu_st_vir_addr=%x,s0_dtg_st_vir_addr=%x,pst_enable_vir_addr=%x",pst_dispm_scpu_vir_addr.s0_uzu_st_vir_addr,pst_dispm_scpu_vir_addr.s0_dtg_st_vir_addr,pst_dispm_scpu_vir_addr.pst_enable_vir_addr);
	}
	return 0;
}

unsigned int Scaler_PST_IP_register_get_cur_write_addr(unsigned int addr,unsigned char display)
{
	unsigned int cur_addr =0;
	unsigned int register_offset_addr =0;
	_PST_MODE_T mode = drvif_scaler_pst_get_mode();
	if (display == SLR_MAIN_DISPLAY) {
		if (mode == _MAIN_MD) {
			if (MAIN_MDISP_register_range(addr)) {
				if (MAIN_MDISP_DDR_range(addr)) {
					if (pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr) {
						register_offset_addr = ((addr-MAIN_MDISP_START_REGISTER) /REGISTER_VALUE_SIZE) *PST_REGISTER_DDR_SIZE;
						cur_addr =  Scaler_pst_cmd_buffer_write_offset_addr(pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr) + register_offset_addr;
					}
				}
			} else if (MAIN_UZU_register_range(addr)) {
				if (MAIN_UZU_DDR_range(addr)) {
					if (pst_dispm_scpu_vir_addr.s0_uzu_st_vir_addr) {
						register_offset_addr = ((addr-MAIN_UZU_START_REGISTER) /REGISTER_VALUE_SIZE) *PST_REGISTER_DDR_SIZE;
						cur_addr =  Scaler_pst_cmd_buffer_write_offset_addr(pst_dispm_scpu_vir_addr.s0_uzu_st_vir_addr) + register_offset_addr;
					}
				}
			}  else if (MAIN_DTG_register_range(addr)) {
				if (MAIN_DTG_DDR_range(addr)) {
					if (pst_dispm_scpu_vir_addr.s0_dtg_st_vir_addr) {
						register_offset_addr = ((addr-MAIN_DTG_START_REGISTER) /REGISTER_VALUE_SIZE) *PST_REGISTER_DDR_SIZE;
						cur_addr =  Scaler_pst_cmd_buffer_write_offset_addr(pst_dispm_scpu_vir_addr.s0_dtg_st_vir_addr) + register_offset_addr;
					}
				}
			}
		}
	}
	return cur_addr;
}

void Scaler_pst_set_write_point(_PST_MODE_T  mode)
{
	if (mode == _MAIN_MD) {	
		pst_i2rnd_dma_wrt_pnt2_RBUS wrt_pnt2_reg;
		wrt_pnt2_reg.regValue = rtd_inl(PST_I2RND_DMA_WRT_PNT2_reg);	
		wrt_pnt2_reg.pst_dispm_write_pnt = Scaler_pst_main_md_get_write_cmd_num();
		rtd_outl(PST_I2RND_DMA_WRT_PNT2_reg, wrt_pnt2_reg.regValue);
	}
}
unsigned char Scaler_pst_get_write_point(_PST_MODE_T  mode)
{
	if (mode == _MAIN_MD) {	
		pst_i2rnd_dma_wrt_pnt2_RBUS wrt_pnt2_reg;
		wrt_pnt2_reg.regValue = rtd_inl(PST_I2RND_DMA_WRT_PNT2_reg);	
		return wrt_pnt2_reg.pst_dispm_write_pnt ;
	} else {
		return 0;
	}
}
unsigned char Scaler_pst_get_read_point(_PST_MODE_T mode)
{
	if (mode == _MAIN_MD) {
		pst_i2rnd_dma_read_pnt2_RBUS read_pnt2_reg;
		read_pnt2_reg.regValue = rtd_inl(PST_I2RND_DMA_READ_PNT2_reg);	
		return read_pnt2_reg.pst_dispm_read_pnt;
	} else {
		return 0;
	}
}

void Scaler_pst_buffer_copy(_PST_MODE_T mode)
{
	unsigned char i=0;
	for (i=1;i<(PST_CMD_NUMBER+1);i++) {
		if (mode == _MAIN_MD) {
			unsigned int curr_pst_md_write_buffer_addr=pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr+i* pst_st_addr.dispm_cmd_buffer_size;
			memcpy((unsigned char *)curr_pst_md_write_buffer_addr, (unsigned char *)pst_dispm_scpu_vir_addr.s0_mdisp_st_vir_addr, sizeof(unsigned char) *  pst_st_addr.dispm_cmd_buffer_size);
		}
	}
}
#endif

/*======================== End of File =======================================*/
/**
*
* @}
*/

