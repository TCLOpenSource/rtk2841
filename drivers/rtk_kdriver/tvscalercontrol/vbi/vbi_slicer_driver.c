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
//#include <mach/RPCDriver.h>
#include <rtk_kdriver/RPCDriver.h>//sunray
#include <linux/pageremap.h>
#include <uapi/linux/const.h>
#include <linux/mm.h>

#include <rbus/vbi_reg.h>
//#include <rbus/rbusVDTopReg.h>
#include <rbus/vdtop_reg.h>//sunray
#include <rbus/adc_reg.h>

#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/vbi/vbi_slicer_driver.h>
#include <scalercommon/scalerCommon.h>
#include <scalercommon/scalerDrvCommon.h>
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/vdc/video.h>


//#include <mach/RPCDriver.h>//sunray
#if 0
MVD_SUBTITLE_BUF	*cc_mvdSubBuf = NULL;
unsigned char		*cc_sDataVirAddr;
unsigned char ttx_slicer_fieldBuff     [PPR_FIELD_BUFF_PKT_NUM][TTX_SLICER_PACKET_SIZE];
unsigned char vps_slicer_fieldBuff     [VBI_VPS_BUF_LENGTH][VBI_VPS_FRAME_BYTES];
unsigned char cc_slicer_fieldBuff     [VBI_CC_BUF_LENGTH][VBI_CC_FRAME_BYTES];
#endif
unsigned short vbi_cc_lastpkt=0;
unsigned short vbi_ttx_lastpkt=0;
unsigned short vbi_vps_lastpkt=0;

VBI_DATA_STATUS vbi_slicer_status[VBI_TYPE_ALL];
unsigned short vbi_pal_wss;
unsigned int vbi_ntsc_wss;
unsigned int vbi_cgms_data;
unsigned char vbi_cc_buffer_need_set;
unsigned char vbi_tt_buffer_need_set;
unsigned char vbi_vps_buffer_need_set;
unsigned char vbi_init_done;
#define VPS_SLICER_LINE_FIELD_EVEN 0x66666636
extern struct semaphore *get_VBI_vps_semaphore(void);
unsigned short vbi_preWss;

#if 0
unsigned int vbi_status_get_size(VBI_TYPE_T type)
{
	unsigned int size=0;
	switch (type)
	{
		case VBI_PAL_TELETEXT:
		{
			size=vbi_ttx_lastpkt*TTX_SLICER_PACKET_SIZE;
			break;
		}
		case VBI_PAL_WSS:
		{
			size=1;
			break;
		}
		case VBI_PAL_VPS:
	 	{
			size=vbi_vps_lastpkt*VBI_VPS_FRAME_BYTES;
	 		break;
	 	}
		case VBI_NTSC_CC:
	 	{
			size=vbi_cc_lastpkt*VBI_CC_FRAME_BYTES;
	 		break;
	 	}
		case VBI_NTSC_WSS:
	 	{
	 		size=1;
			break;
	 	}
		default:
		{
			printk("vbi type is not correct:%d",type);
			break;
		}
	}
	return size;
}
void vbi_status_clear(VBI_TYPE_T type)
{
	switch (type)
	{
		case VBI_PAL_TELETEXT:
		{
			vbi_ttx_lastpkt=0;
			break;
		}
		case VBI_PAL_WSS:
		{
			break;
		}
		case VBI_PAL_VPS:
	 	{
			vbi_vps_lastpkt=0;
	 		break;
	 	}
		case VBI_NTSC_CC:
	 	{
			vbi_cc_lastpkt=0;
	 		break;
	 	}
		case VBI_NTSC_WSS:
	 	{
			break;
	 	}
		default:
		{
			printk("vbi type is not correct:%d",type);
			break;
		}
	}
	vbi_slicer_status[type]=VBI_DATA_COLLECTING;
}

unsigned char vbi_status_get_status(VBI_TYPE_T type)
{
	return vbi_slicer_status[type];
}

static unsigned short reverseInt16(unsigned short value)
{
    unsigned short b0 = (value & 0x00ff) << 8;
    unsigned short b1 = (value & 0xff00) >> 8;

    return (b0 | b1);
}

#define		INCR(x,y)			((x+y)%MVD_SUBTITLE_BUF_SIZE)
#define NTSC_FIELD_1			0xFC 		///< b'1111_1100' = NTSC line 21 field 1 closed-captions
#define NTSC_FIELD_2			0xFD 		///< b'1111_1101' = NTSC line 21 field 2 closed-captions

unsigned int ccBuf_GetReadPoint(void)
{
 	return  cc_mvdSubBuf->rPtr;
}
unsigned int ccBuf_GetWritePoint(void)
{
    return cc_mvdSubBuf->wPtr;
}
unsigned int ccBuf_SetReadPoint(unsigned int readPtr)
{
    cc_mvdSubBuf->rPtr = readPtr;
    return 0;
}
unsigned int	ccBuf_GetOverflowFlag(void)
{
	return cc_mvdSubBuf->overflowFlag;
}
unsigned int	ccBuf_SetOverflowFlag(unsigned int overflow)
{
	return 	cc_mvdSubBuf->overflowFlag = overflow;
}
unsigned int ccBuf_GetBufferAddr(void)
{
	return (unsigned int)cc_sDataVirAddr;
}
unsigned int ccBuf_GetBufferSize(void)
{
  return MVD_SUBTITLE_BUF_SIZE;
}
unsigned int cc_getDataLen(void)
{
	unsigned int	wPtr = htonl(ccBuf_GetWritePoint());
	unsigned int	rPtr = htonl(ccBuf_GetReadPoint());

	if(wPtr >= rPtr)	// NOT ring over yet
		return (wPtr - rPtr - 1);		// change rPtr to stay in readed position
	else				// ring over!
		return (ccBuf_GetBufferSize() - rPtr - 1 + wPtr);		// change rPtr to stay in readed position
}
unsigned char cc_noDataReason(void)
{
	if(vbi_cc_lastpkt!=0)
	{
		vbi_slicer_status[VBI_NTSC_CC]=VBI_DATA_COLLECTED;
	}
	if(htonl(ccBuf_GetOverflowFlag())) {				// buffer overflow!
		ccBuf_SetReadPoint(htonl((htonl(ccBuf_GetWritePoint()) > 0) ? (htonl(ccBuf_GetWritePoint()) - 1) : (ccBuf_GetBufferSize() - 1)));
		ccBuf_SetOverflowFlag(htonl(0));	// clear overflow flag
		return	0;//DECODER_BUF_OVERFLOW;
	} else {
		return	0;//DECODER_NO_DATA;					// buffer starving
	}
}
#endif
unsigned int video_send_vbi_slicer_rpc(unsigned long para1, unsigned long para2)
{
//	unsigned char **vbi_buf = NULL;
 //   unsigned short *vbi_buf_idx = NULL;
//	unsigned char i=0;
	switch (para1)
	{
		case VBI_PAL_TELETEXT:
	 	{
		#if 0
			const unsigned char (*ptr)[][PPR_PTNGEN_PKT_LEN_BYTES];
			unsigned short start_idx, end_idx;

		    vbi_buf =(unsigned char**)Scaler_VbiTtxGetVirBufAddr(0);
		    if(vbi_buf == NULL) {printk("error! vbi_buf = null \n"); return FALSE;}
		    vbi_buf_idx = (unsigned short *)(((unsigned char *)vbi_buf) + (VBI_TTX_BUF_LENGTH*PPR_PTNGEN_PKT_LEN_BYTES));
		    if(vbi_buf_idx == NULL) {printk("error! vbi_buf_idx = null \n"); return FALSE;}

		    // Mark a processing area by recording current start index and end index
		    // because ISR will update them all the time.
		    start_idx = (*((unsigned short*) vbi_buf_idx));
		    end_idx   = reverseInt16(*(((unsigned short*) vbi_buf_idx)+1));
		//	printk("start:%d,end:%d\n",start_idx,end_idx);
		    while (1)
		    {
		    	if(vbi_slicer_status[VBI_PAL_TELETEXT]!=VBI_DATA_COLLECTING)
		    	{
		    		printk("don't handle ttx data\n");
		    		break;
		    	}
		        if ( start_idx == end_idx )
		            break;

		        if ( start_idx < end_idx )
		        {
		            ptr = (const unsigned char (*)[][PPR_PTNGEN_PKT_LEN_BYTES])(((unsigned char*) vbi_buf+ (start_idx*PPR_PTNGEN_PKT_LEN_BYTES)));
					for(i=0;i<(end_idx-start_idx);++i)
					{
						if(((*ptr)[i][0] == 0x00)&&((*ptr)[i][1] == 0xFF)&&((*ptr)[i][2] == 0xFF)&&((((*ptr)[i][3]>>1) &0x7F)== (unsigned char)(0x22>>1))&&((*ptr)[i][4] == TTX_SLICER_PACKET_SIZE))
						{ //valid ttx data
							memcpy(&(ttx_slicer_fieldBuff[vbi_ttx_lastpkt][0]), &((*ptr)[i][5]), TTX_SLICER_PACKET_SIZE);
							vbi_ttx_lastpkt+=1;
						}
					}
		            start_idx = end_idx;
		        }
		        else
		        {
		            ptr = (const unsigned char (*)[][PPR_PTNGEN_PKT_LEN_BYTES])(((unsigned char*) vbi_buf+ (start_idx*PPR_PTNGEN_PKT_LEN_BYTES)));
					for(i=0;i<(VBI_TTX_BUF_LENGTH-start_idx);++i)
					{
						if(((*ptr)[i][0] == 0x00)&&((*ptr)[i][1] == 0xFF)&&((*ptr)[i][2] == 0xFF)&&((((*ptr)[i][3]>>1) &0x7F)== (unsigned char)(0x22>>1))&&((*ptr)[i][4] == TTX_SLICER_PACKET_SIZE))
						{//valid ttx data
							memcpy(&(ttx_slicer_fieldBuff[vbi_ttx_lastpkt][0]), &((*ptr)[i][5]), TTX_SLICER_PACKET_SIZE);
							vbi_ttx_lastpkt+=1;
						}
					}
		            start_idx = 0;
		        }
		    }

		    // update global start index
		    *((unsigned short*) vbi_buf_idx) = start_idx;
			if(vbi_ttx_lastpkt!=0)
			{
				vbi_slicer_status[VBI_PAL_TELETEXT]=VBI_DATA_COLLECTED;
			}
		#endif
			break;
	 	}
		case VBI_PAL_WSS:
		{
			if(vbi_slicer_status[VBI_PAL_WSS]!=VBI_DATA_NON)
			{
				vbi_pal_wss=((unsigned short)para2)&0x3fff; //valid data is 14bit
				vbi_slicer_status[VBI_PAL_WSS]=VBI_DATA_COLLECTED;
				vbi_preWss = vbi_pal_wss;
				pr_notice("kernel recevie video vbi_pal_wss=%x\n",vbi_pal_wss);
			}
			break;
		}
		case VBI_PAL_VPS:
	 	{
		#if 0
			const unsigned char (*ptr)[][VBI_VPS_FRAME_BYTES];
			unsigned short start_idx, end_idx;

		    vbi_buf =(unsigned char**)Scaler_VbiVPSGetVirBufAddr(0);
		    if(vbi_buf == NULL) {printk("error! vbi_buf = null \n"); return FALSE;}
		    vbi_buf_idx = (unsigned short *)(((unsigned char *)vbi_buf) + (VBI_VPS_BUF_LENGTH*VBI_VPS_FRAME_BYTES));
		    if(vbi_buf_idx == NULL) {printk("error! vbi_buf_idx = null \n"); return FALSE;}
		    // Mark a processing area by recording current start index and end index
		    // because ISR will update them all the time.
		    start_idx = (*((unsigned short*) vbi_buf_idx));
		    end_idx   = reverseInt16(*(((unsigned short*) vbi_buf_idx)+1));
		//	printk("start:%d,end:%d\n",start_idx,end_idx);
		    while (1)
		    {
		    	if(vbi_slicer_status[VBI_PAL_VPS]!=VBI_DATA_COLLECTING)
		    	{
		    		printk("don't handle vps data\n");
		    		break;
		    	}
		        if ( start_idx == end_idx )
		            break;

		        if ( start_idx < end_idx )
		        {
		            ptr = (const unsigned char (*)[][VBI_VPS_FRAME_BYTES])(((unsigned char*) vbi_buf+ (start_idx*VBI_VPS_FRAME_BYTES)));
					memcpy(&(vps_slicer_fieldBuff[vbi_vps_lastpkt][0]), &((*ptr)[0][0]), (end_idx-start_idx)*VBI_VPS_FRAME_BYTES);
					vbi_vps_lastpkt+=(end_idx-start_idx);
		            start_idx = end_idx;
		        }
		        else
		        {
		            ptr = (const unsigned char (*)[][VBI_VPS_FRAME_BYTES])(((unsigned char*) vbi_buf+ (start_idx*VBI_VPS_FRAME_BYTES)));
					memcpy(&(vps_slicer_fieldBuff[vbi_vps_lastpkt][0]), &((*ptr)[0][0]), (VBI_VPS_BUF_LENGTH-start_idx)*VBI_VPS_FRAME_BYTES);
					vbi_vps_lastpkt+=(VBI_VPS_BUF_LENGTH-start_idx);
		            start_idx = 0;
		        }
		    }

		    // update global start index
		    *((unsigned short*) vbi_buf_idx) = start_idx;
			if(vbi_vps_lastpkt!=0)
			{
				vbi_slicer_status[VBI_PAL_VPS]=VBI_DATA_COLLECTED;
			}
		#endif
			break;
	 	}
		case VBI_NTSC_CC:
	 	{
		#if 0
			{
				unsigned int			rPtr;			// Subtitle Buffer read pointer kept by subtitle codec
				int			data_len = 0;	// Unsigned -> Signed when data_len reduce to 0 will error
				unsigned char			*pBuff = NULL;
				unsigned char			cc_count;
				unsigned char cc_field;
				pBuff =(unsigned char*)Scaler_VbiCcGetVirBufAddr(0);
				if(!pBuff)   {	return FALSE;	}

			_FindUserDataID:
				rPtr = INCR(htonl(ccBuf_GetReadPoint()), 0);		// forward read
				data_len = cc_getDataLen();			// calculate new coming data length in Subtitle Buffer
				if (data_len <= 1)
				{
					return cc_noDataReason();
				}

			//---- Go-on process next packet ----//
			_NextPackets:
				while(*(pBuff + rPtr) != 0x03) {
					if(*(pBuff + rPtr) == NTSC_FIELD_1 || *(pBuff + rPtr) == NTSC_FIELD_2){
						break;
					}

					if (data_len > 3) {
						rPtr = INCR(rPtr, 1);
						data_len --;
					} else {
						//	to avoid MVD to set overflow flag
						if (rPtr == htonl(ccBuf_GetWritePoint())) {
						//	STC_MESSAGE_DEBUG("Buffer Underflow , rPtr=[%x], wPtr=[%x]\n", rPtr, Get32_be(ccBuf_GetWritePoint()));
							rPtr = ((rPtr > 0) ? (rPtr - 1) : (ccBuf_GetBufferSize() - 1));
						}
						ccBuf_SetReadPoint(htonl(rPtr));		// update buffer read pointer

						return	cc_noDataReason();
					}
				}

				goto _ComputeData;

			_ComputeData:
				//----- cc header is found ---------------------//
				cc_count= 1;
				//----- cc data --------------------------------//
				if(data_len < cc_count * 3) {				// each ccData has 3 bytes including 'data_valid' and 'data_type'
				//	STC_MESSAGE_DEBUG("data_len[%d] < cc_count[%d] * 3\n", data_len, cc_count);
					return	cc_noDataReason();
				}
				else
				{
					for(i=0; i<cc_count; i++)
					{
						cc_field=*(unsigned char *)(pBuff + INCR(rPtr, 0));
						if(cc_field==NTSC_FIELD_1)
						{
							cc_slicer_fieldBuff[vbi_cc_lastpkt][2]=1;  //fix me:odd field
						}
						else
						{
							cc_slicer_fieldBuff[vbi_cc_lastpkt][2]=0;  //fix me:even field
						}
						cc_slicer_fieldBuff[vbi_cc_lastpkt][0]=*(unsigned char *)(pBuff + INCR(rPtr, 1));
						cc_slicer_fieldBuff[vbi_cc_lastpkt][1]=*(unsigned char *)(pBuff + INCR(rPtr, 2));
						vbi_cc_lastpkt++;
						rPtr = INCR(rPtr, 3);				// cc data size = 3 bytes
						data_len -= 3;
					}	// end of for (cc_count)
				}	// end of else
				ccBuf_SetReadPoint(htonl(rPtr));				// update buffer read pointer

				if (data_len > 1)
				{
					goto _NextPackets;
				}
				else
					goto _FindUserDataID;
			}
		#endif
	 		break;
	 	}
		case VBI_NTSC_WSS:
	 	{
	 		if(vbi_slicer_status[VBI_NTSC_WSS]!=VBI_DATA_NON)
			{
				vbi_ntsc_wss=((unsigned int)para2)&0xfffff; //valid data is 20bit
				vbi_slicer_status[VBI_NTSC_WSS]=VBI_DATA_COLLECTED;
			}
			break;
	 	}
		case VBI_CGMS:
	 	{
	 		if(vbi_slicer_status[VBI_CGMS]!=VBI_DATA_NON)
			{
				vbi_cgms_data=((unsigned int)para2)&0xfffff; //valid data is 20bit
				vbi_slicer_status[VBI_CGMS]=VBI_DATA_COLLECTED;
			}
			break;
	 	}
	}
 	return 0;
}

void init_vbi_rpc(void)
{
	if (!vbi_init_done) {
#ifdef CONFIG_RTK_KDRV_RPC
		register_kernel_rpc(RPC_VCPU_ID_0x101_VBI,(FUNC_PTR)video_send_vbi_slicer_rpc);
#endif
		vbi_init_done=1;
	}
}

static unsigned long m_subtitlePhyAddr = 0;
static unsigned long m_ttxBufPhyAddr = 0;
static unsigned char vbicc_status[2] = {FALSE, FALSE}; // index= 0: av/sv/atv, 1: ypbpr ; value = FALSE: stop, TRUE: play
static unsigned long m_vpsBufPhyAddr = 0;

#if 0
static unsigned int m_subtitleCachedAddr = 0;
static unsigned int m_subtitleNonCachedAddr = 0;
static unsigned int m_ttxBufCachedAddr = 0;
static unsigned int m_ttxBufNonCachedAddr = 0;
static unsigned int m_vpsBufCachedAddr = 0;
static unsigned int m_vpsBufNonCachedAddr = 0;

unsigned int Scaler_share_vbimem(VBI_TYPE_T vbi_status)
{
	if(vbi_status==VBI_NTSC_CC)
	{
		m_subtitleCachedAddr = (unsigned int)dvr_malloc_uncached((sizeof(MVD_SUBTITLE_BUF) + (sizeof(unsigned char) * MVD_SUBTITLE_BUF_SIZE)),(void**)&m_subtitleNonCachedAddr);
		//m_subtitlePhyAddr = (unsigned int)virt_to_phys((void*)m_subtitleCachedAddr);
		m_subtitlePhyAddr = (unsigned int)dvr_to_phys((void*)m_subtitleCachedAddr);
		printk("ccphyaddr=%lx\n",m_subtitlePhyAddr);
	}
	else if(vbi_status==VBI_PAL_TELETEXT)
	{
		m_ttxBufCachedAddr = (unsigned int)dvr_malloc_uncached((sizeof(unsigned char) * (VBI_TTX_BUF_LENGTH*PPR_PTNGEN_PKT_LEN_BYTES + 4)),(void**)&m_ttxBufNonCachedAddr);
		//m_ttxBufPhyAddr = (unsigned int)virt_to_phys((void*)m_ttxBufCachedAddr);
		m_ttxBufPhyAddr = (unsigned int)dvr_to_phys((void*)m_ttxBufCachedAddr);
		printk("ttxphyaddr=%lx\n",m_ttxBufPhyAddr);
	}
	else if(vbi_status==VBI_PAL_VPS)
	{
		m_vpsBufCachedAddr = (unsigned int)dvr_malloc_uncached((sizeof(unsigned char) * (VBI_VPS_BUF_LENGTH*VBI_VPS_FRAME_BYTES + 4)),(void**)&m_vpsBufNonCachedAddr);
		//m_vpsBufPhyAddr = (unsigned int)virt_to_phys((void*)m_vpsBufCachedAddr);
		m_vpsBufPhyAddr = (unsigned int)dvr_to_phys((void*)m_vpsBufCachedAddr);
		printk("vpsphyaddr=%lx\n",m_vpsBufPhyAddr);
	}
	return true;
}
unsigned int Scaler_VbiVPSGetVirBufAddr(unsigned char bCached)
{
	if (bCached)
		return m_vpsBufCachedAddr;
	else
		return m_vpsBufNonCachedAddr;
}
unsigned int Scaler_VbiCcGetVirBufAddr(unsigned char bCached)
{
	if (bCached)
		return m_subtitleCachedAddr;
	else
		return m_subtitleNonCachedAddr;
}
unsigned int Scaler_VbiTtxGetVirBufAddr(unsigned char bCached)
{
	if (bCached)
		return m_ttxBufCachedAddr;
	else
		return m_ttxBufNonCachedAddr;
}
#endif
void Scaler_VbiVPSSetPhyBufAddr(unsigned long addr)
{
	m_vpsBufPhyAddr=addr;
}

unsigned int Scaler_VbiVPSGetPhyBufAddr(void)
{
	return m_vpsBufPhyAddr;
}
void Scaler_VbiCcSetPhyBufAddr(unsigned long addr)
{
	m_subtitlePhyAddr=addr;
}

unsigned int Scaler_VbiCcGetPhyBufAddr(void)
{
	return m_subtitlePhyAddr;
}
void Scaler_VbiTtxSetPhyBufAddr(unsigned long addr)
{
	m_ttxBufPhyAddr=addr;
}

unsigned int Scaler_VbiTtxGetPhyBufAddr(void)
{
	return m_ttxBufPhyAddr;
}
void Scaler_VbiVPSSetBuf(unsigned int* buf_addr)
{
	if(vbi_vps_buffer_need_set==0){
		int ret = 0;
		unsigned int *pulTemp = NULL;

		pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VBIVPSSETBUF);

		// copy to RPC share memory
		memcpy(pulTemp, buf_addr, sizeof(unsigned int));

		pulTemp[0] = htonl(pulTemp[0]);

		if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBIVPSSETBUF,0,0)))
		{
			pr_debug( "ret=%d, set buffer address for VBI VPS fail !!!\n", ret );
			return;

		}
		vbi_vps_buffer_need_set=1;
	}
}

void Scaler_VbiTtxSetBuf(unsigned int* buf_addr)
{
	if(vbi_tt_buffer_need_set==0) {
		int ret = 0;
		unsigned int *pulTemp = NULL;

		pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VBITTXSETBUF);

		// copy to RPC share memory
		memcpy(pulTemp, buf_addr, sizeof(unsigned int));

		pulTemp[0] = htonl(pulTemp[0]);

		if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBITTXSETBUF,0,0)))
		{
			pr_debug( "ret=%d, set buffer address for VBI TTx fail !!!\n", ret );
			return;

		}
		vbi_tt_buffer_need_set=1;
	}
}
unsigned char	ttx_setShareBuf(void)
{
	unsigned int vbiBuffer;

	vbiBuffer = Scaler_VbiTtxGetPhyBufAddr();

	pr_emerg("vbiBuffer : %x \n", (unsigned int) vbiBuffer);

	Scaler_VbiTtxSetBuf(&vbiBuffer);

	return 0;
}

void Scaler_VbiTtInit(void)
{
	VBI_IOCTL_PARAM param = {VBI_MODE_TELETEXT, 1};
	unsigned int *pulTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	sys_reg_int_ctrl_vcpu_RBUS crt_int_ctrl_vcpu;

	pr_debug("=========== Scaler_TestTtx_SlicerData ====================\n");

	ttx_setShareBuf(); //set share memory to video cpu
	if (SYS_REG_INT_CTRL_VCPU_get_vbi_int_vcpu_routing_en(IoReg_Read32(SYS_REG_INT_CTRL_VCPU_reg)) == 0) {
		crt_int_ctrl_vcpu.regValue = 0;//open vbi routing to avoid vbi interrupt not handle
		crt_int_ctrl_vcpu.vbi_int_vcpu_routing_en = 1 ;
		crt_int_ctrl_vcpu.write_data = 1;
		IoReg_Write32(SYS_REG_INT_CTRL_VCPU_reg, crt_int_ctrl_vcpu.regValue);
	}
#ifdef VBI_TTX_NEW_DMA_ENABLE
	if (SYS_REG_INT_CTRL_VCPU_get_vdec_int_vcpu_routing_en(IoReg_Read32(SYS_REG_INT_CTRL_VCPU_reg)) == 0) {
		crt_int_ctrl_vcpu.regValue = 0;//open vd routing to avoid vbi interrupt not handle
		crt_int_ctrl_vcpu.vdec_int_vcpu_routing_en = 1 ;
		crt_int_ctrl_vcpu.write_data = 1;
		IoReg_Write32(SYS_REG_INT_CTRL_VCPU_reg, crt_int_ctrl_vcpu.regValue);
	}
#endif
	pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VBI_ENABLE);
	ulCount = sizeof(VBI_IOCTL_PARAM) / sizeof(unsigned int);

	// copy to RPC share memory
	memcpy(pulTemp, &param, sizeof(VBI_IOCTL_PARAM));

	for (i = 0; i < ulCount; i++)
		pulTemp[i] = htonl(pulTemp[i]);

	{
		int ret;
		if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBI_ENABLE,0,0)))
		{
			pr_debug("ret=%d, init VBI TT fail !!!\n", ret);
		}
	}
	vbi_slicer_status[VBI_PAL_TELETEXT]=VBI_DATA_COLLECTING;
	vbi_slicer_status[VBI_PAL_WSS]=VBI_DATA_COLLECTING;
	down(get_VBI_vps_semaphore());
	if (vbi_slicer_status[VBI_PAL_VPS] ==VBI_DATA_NON) {//ttx driver setting
		up(get_VBI_vps_semaphore());
		vdcf_outl(VBI_TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_reg, 0x66666666); // line 13,14,15,16
		vdcf_outl(VBI_TT_VBI_NOISY_CTRL4_reg, 0x808000a0);
		vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg, 0x00004600);
	} else {
		up(get_VBI_vps_semaphore());
	}
	
}


void Scaler_VbiTtDeinit(void)
{
#if 0
	VBI_IOCTL_PARAM param = {VBI_MODE_TELETEXT, 0};
	unsigned int *pulTemp = NULL;
	unsigned int ulCount = 0, i = 0;

	pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VBI_ENABLE);
	ulCount = sizeof(VBI_IOCTL_PARAM) / sizeof(unsigned int);

	// copy to RPC share memory
	memcpy(pulTemp, &param, sizeof(VBI_IOCTL_PARAM));

	for (i = 0; i < ulCount; i++)
		pulTemp[i] = htonl(pulTemp[i]);

	{
		int ret;
		if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBI_ENABLE,0,0)))
		{
			pr_debug("ret=%d, Deinit VBI TT fail !!!\n", ret);
		}
	}
#endif

#if 0//VBI_TTX_NEW_DMA_ENABLE
	unsigned int time_out=0xffffff;
	while (vdcf_inl(VBI_VBIPPR_POWER_CTRL_reg) & VBI_VBIPPR_POWER_CTRL_vbi_tt_dma_en_mask) {
		time_out--;
		if (time_out == 0) {
			pr_emerg("[vbi]ttx_unit wait dma off timeout\n");
			break;
		}
	}
#endif
	Scaler_vbi_ttx_interrupt_set(0);

	vbi_slicer_status[VBI_PAL_TELETEXT]=VBI_DATA_NON;
	vbi_slicer_status[VBI_PAL_WSS]=VBI_DATA_NON;
	vbi_pal_wss = 0;
	Scaler_reset_vbi_wss();
}

void Scaler_VbiCcInit(void) // 0: from av/sv/atv, 1: from ypbpr
{
	VBI_IOCTL_PARAM param = {VBI_MODE_CC, 1};
	unsigned int *pulTemp = NULL;
	unsigned int ulCount = 0, i = 0;
	unsigned int vbiBuffer;
	sys_reg_int_ctrl_vcpu_RBUS crt_int_ctrl_vcpu;
	vbi_vbi_dump_int_RBUS vbi_dump_int_reg;
	vbi_dump_int_reg.regValue=vdcf_inl(VBI_VBI_DUMP_int_reg);
	if (vbi_dump_int_reg.vbi_dump_irq_en) {	
		vbi_dump_int_reg.vbi_dump_irq_en=0;  //ttx dma interrupt
		vdcf_outl(VBI_VBI_DUMP_int_reg,vbi_dump_int_reg.regValue);
	}
	if (SYS_REG_INT_CTRL_VCPU_get_vbi_int_vcpu_routing_en(IoReg_Read32(SYS_REG_INT_CTRL_VCPU_reg)) == 0) {
		crt_int_ctrl_vcpu.regValue = 0;//open vbi routing to avoid vbi interrupt not handle
		crt_int_ctrl_vcpu.vbi_int_vcpu_routing_en = 1 ;
		crt_int_ctrl_vcpu.write_data = 1;
		IoReg_Write32(SYS_REG_INT_CTRL_VCPU_reg, crt_int_ctrl_vcpu.regValue);
	}
#if 0
	cc_mvdSubBuf = (MVD_SUBTITLE_BUF*)(Scaler_VbiCcGetVirBufAddr(0) + (sizeof(unsigned char) * MVD_SUBTITLE_BUF_SIZE));
	memset(cc_mvdSubBuf, 0, sizeof(MVD_SUBTITLE_BUF));
	cc_sDataVirAddr = (unsigned char*)Scaler_VbiCcGetVirBufAddr(0);
	memset(cc_sDataVirAddr, 0, sizeof(unsigned char) * MVD_SUBTITLE_BUF_SIZE);
	cc_mvdSubBuf->sData = htonl(Scaler_VbiCcGetPhyBufAddr());
#endif
	vbiBuffer=(Scaler_VbiCcGetPhyBufAddr()+(sizeof(unsigned char) * MVD_SUBTITLE_BUF_SIZE));//get_PhyAddr((UINT32) cc_mvdSubBuf);
	Scaler_VbiCcSetBuf(&vbiBuffer);

	pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VBI_ENABLE);
	ulCount = sizeof(VBI_IOCTL_PARAM) / sizeof(unsigned int);
	// copy to RPC share memory
	memcpy(pulTemp, &param, sizeof(VBI_IOCTL_PARAM));

	for (i = 0; i < ulCount; i++)
		pulTemp[i] = htonl(pulTemp[i]);

	{
		int ret;
		if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBI_ENABLE,0,0)))
		{
			pr_debug("ret=%d, init VBI CC fail !!!\n", ret);
			//return;

		}
	}
	vbi_slicer_status[VBI_NTSC_CC]=VBI_DATA_COLLECTING;
	vbi_slicer_status[VBI_NTSC_WSS]=VBI_DATA_COLLECTING;

}

void Scaler_VbiCcDeinit(void) // 0: from av/sv/atv, 1: from ypbpr
{
#if 0
	VBI_IOCTL_PARAM param = {VBI_MODE_CC, 0};
	unsigned int *pulTemp = NULL;
	unsigned int ulCount = 0, i = 0;


/*fix me	if (Scaler_GetDev() == -1) {
		printf("open /dev/scaler fail, cannot deinit VBI CC\n");
		return;
	}

	if ((ret = ioctl(Scaler_GetDev(), SCALERIOC_VBI_ENABLE, &param)) < 0) {
		printf("ret=%d, deinit VBI CC fail !!!\n", ret);
		return;
	}*/

	pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VBI_ENABLE);
	ulCount = sizeof(VBI_IOCTL_PARAM) / sizeof(unsigned int);
	// copy to RPC share memory
	memcpy(pulTemp, &param, sizeof(VBI_IOCTL_PARAM));

	for (i = 0; i < ulCount; i++)
		pulTemp[i] =htonl(pulTemp[i]);

	{
		int ret;
		if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBI_ENABLE,0,0)))
		{
			pr_debug("ret=%d, init VBI CC fail !!!\n", ret);
			//return;

		}
	}
#else
	vbi_tt_vbi_data_status_RBUS vbi_data_status_reg;//sunray
	vbi_data_status_reg.regValue=vdcf_inl(VBI_TT_VBI_DATA_STATUS_reg);
	vbi_data_status_reg.tt_cc_int_en=0;  //ttx dma interrupt
	vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg,vbi_data_status_reg.regValue);
#endif
	vbi_slicer_status[VBI_NTSC_CC]=VBI_DATA_NON;
	vbi_slicer_status[VBI_NTSC_WSS]=VBI_DATA_NON;
}
void Scaler_VbiCcStop(unsigned char from) // 0: from av/sv/atv, 1: from ypbpr
{
	int ret;

	vbicc_status[from] = FALSE;

	if ( (vbicc_status[0]==FALSE) && (vbicc_status[1]==FALSE) ) {
	if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBICCSTOP,0,1)))
	{
		pr_debug("ret=%d, stop VBI CC fail !!!\n", ret);
		return;
	}

	}
}

void Scaler_VbiCcPlay(unsigned char from) // 0: from av/sv/atv, 1: from ypbpr
{
	int ret;

	vbicc_status[from] = TRUE;

	// copy to RPC share memory
	memcpy( (unsigned char*)Scaler_GetShareMemVirAddr(SCALERIOC_VBICCPLAY), &from, sizeof(unsigned char));

	if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBICCPLAY,0,0)))
	{
		pr_debug("ret=%d, play VBI CC fail !!!\n", ret);
		return;
	}
}

void Scaler_VbiCcSetBuf(unsigned int* buf_addr)
{
	if(vbi_cc_buffer_need_set==0){
		int ret = 0;
		unsigned int *pulTemp = NULL;

		pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VBICCSETBUF);

		// copy to RPC share memory
		memcpy(pulTemp, buf_addr, sizeof(unsigned int));

		pulTemp[0] = htonl(pulTemp[0]);

		if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBICCSETBUF,0,0)))
		{
			pr_debug( "ret=%d, set buffer address for VBI CC fail !!!\n", ret );
			return;

		}
		vbi_cc_buffer_need_set=1;
	}
}

unsigned short Scaler_VbiGet_576I_WSS(void)
{
#if 1
	if(vbi_slicer_status[VBI_PAL_WSS]==VBI_DATA_COLLECTED)
	{
		return vbi_pal_wss;
	}
	else
	{
		return 0;
	}
#else
    return vbi_pal_wss;
#endif
}
extern unsigned char wss_pal_just_get_connect(void);
unsigned int Scaler_VbiGet_480I_WSS(void)
{
#if 0
	if(vbi_slicer_status[VBI_NTSC_WSS]==VBI_DATA_COLLECTED)
	{
		return vbi_ntsc_wss;
	}
	else
	{
		return 0;
	}
#else
	unsigned int data=0;
	unsigned int wss_data=0;
	data=Scaler_VbiGet_cgms();
	//bit12-13 is cgms-a
	//bit10-11 is aps
	wss_data=((((data>>10)&0x03)<<8)|(((data>>12)&0x03)<<6)|((data>>18)&0x03));
	return wss_data;
#endif
}
bool  Scaler_VbiTtSetGetProperty(TTX_VBI_IOCTL_PARAM *param)
{
	int ret;

    unsigned int *pulTemp = NULL;
    unsigned int ulCount = 0, i = 0;

    pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VBITT_FUNCTION);
    ulCount = sizeof(TTX_VBI_IOCTL_PARAM) / sizeof(unsigned int);

    for(i = 0; i < ulCount; i++)
        ((unsigned int *)param)[i] = htonl(((unsigned int *)param)[i]);

    // copy to RPC share memory
    memcpy(pulTemp, param, sizeof(TTX_VBI_IOCTL_PARAM));

    {
        if(0 != (ret = Scaler_SendRPC(SCALERIOC_VBITT_FUNCTION,0,0)))
        {
            pr_debug("ret=%d, Set VBI TT Function fail !!!\n", ret);
            return FALSE;
        }
        else
        {
            memcpy(param, pulTemp, sizeof(TTX_VBI_IOCTL_PARAM));

            for(i = 0; i < ulCount; i++)
                ((unsigned int *)param)[i] = htonl(((unsigned int *)param)[i]);
        }
    }

    return TRUE;
}

void Scaler_vbi_vps_init(void)
{
#if 0
	TTX_VBI_IOCTL_PARAM param;
	param.data = 0;param.mode = 0;
	param.mode = VBI_SET_VPS_TRIAL_START;
	Scaler_VbiTtSetGetProperty(&param);
#else
	unsigned int vbiBuffer = 0;
	vbiBuffer = Scaler_VbiVPSGetPhyBufAddr();
	pr_debug("vbivpsBuffer : %x \n", (unsigned int) vbiBuffer);
	Scaler_VbiVPSSetBuf(&vbiBuffer);
	down(get_VBI_vps_semaphore());
	vbi_slicer_status[VBI_PAL_VPS]=VBI_DATA_COLLECTING;
	up(get_VBI_vps_semaphore());
	vbi_vbi_dump_int_RBUS vbi_dump_int_reg;//sunray
	vbi_dump_int_reg.regValue=vdcf_inl(VBI_VBI_DUMP_int_reg);
	// use line 16 to decode VPS
	vdcf_outl(VBI_TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_reg, 0x66666633); // line 13,14,15,16
	vdcf_maskl(VBI_TT_VBI_NOISY_CTRL4_reg, ~VBI_TT_VBI_NOISY_CTRL4_tt_vbi_out_hcount_en_vps_mask, 0);
	vdcf_maskl(VBI_TT_VBI_DATA_STATUS_reg, 0xeff0ffff , _BIT28);
#endif
}

void Scaler_vbi_vps_uninit(void)
{
	vbi_tt_vbi_data_status_RBUS vbi_data_status_reg;//sunray
	vbi_data_status_reg.regValue=vdcf_inl(VBI_TT_VBI_DATA_STATUS_reg);
	vbi_data_status_reg.tt_vps_int_en=0;  //vps line interrupt
	vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg,vbi_data_status_reg.regValue);
	vdcf_outl(VBI_TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_reg, 0x66666666); // line 13,14,15,16
	down(get_VBI_vps_semaphore());
	vbi_slicer_status[VBI_PAL_VPS]=VBI_DATA_NON;
	up(get_VBI_vps_semaphore());
}

void Scaler_vbi_cgms_init(CGMS_SOURCE source)
{
	sys_reg_int_ctrl_vcpu_RBUS crt_int_ctrl_vcpu;
	vbi_vbi_dump_int_RBUS vbi_dump_int_reg;
#if 0
	VBI_CGMS_PARAM param = {source, 1};
	unsigned int *pulTemp = NULL;
	unsigned int ulCount = 0, i = 0;

	pr_debug("=========== Scaler_vbi_cgms_init:%d ====================\n",source);

	pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VBICGMSENABLE);
	ulCount = sizeof(VBI_CGMS_PARAM) / sizeof(unsigned int);

	// copy to RPC share memory
	memcpy(pulTemp, &param, sizeof(VBI_CGMS_PARAM));

	for (i = 0; i < ulCount; i++)
		pulTemp[i] = htonl(pulTemp[i]);

	{
		int ret;
		if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBICGMSENABLE,0,0)))
		{
			pr_debug("ret=%d, init VBI CGMS fail !!!\n", ret);
		}
	}
	vbi_slicer_status[VBI_CGMS]=VBI_DATA_COLLECTING;
#else
	vbi_dump_int_reg.regValue=vdcf_inl(VBI_VBI_DUMP_int_reg);
	if (vbi_dump_int_reg.vbi_dump_irq_en) {	
		vbi_dump_int_reg.vbi_dump_irq_en=0;  //ttx dma interrupt
		vdcf_outl(VBI_VBI_DUMP_int_reg,vbi_dump_int_reg.regValue);
	}
	if (SYS_REG_INT_CTRL_VCPU_get_vbi_int_vcpu_routing_en(IoReg_Read32(SYS_REG_INT_CTRL_VCPU_reg)) == 0) {
		crt_int_ctrl_vcpu.regValue = 0;//open vbi routing to avoid vbi interrupt not handle
		crt_int_ctrl_vcpu.vbi_int_vcpu_routing_en = 1 ;
		crt_int_ctrl_vcpu.write_data = 1;
		IoReg_Write32(SYS_REG_INT_CTRL_VCPU_reg, crt_int_ctrl_vcpu.regValue);
	}
	vdcf_maskl(SYS_REG_SYS_CLKSEL_reg, ~SYS_REG_SYS_CLKSEL_vbis0_yppsel_mask, 0);
	vdcf_maskl(ADC_ADC_CLKGEN_RGB_Capture_reg, ~ADC_ADC_CLKGEN_RGB_Capture_vbi_clkx2_sel_mask, 0);// reset vbi clk to default (x1
	vdcf_outl(VBI_VBISL0_reg, 0x00000000); // ADC source from Video Decode, no inverse field (Atlantic modify bit 28~31 as reserved)
	vdcf_outl(VBI_VBI_VOUNT_SHIFT_reg, 0x00000000);
	vdcf_outl(VBI_CGMS_C0_reg, 0x07006413); // for interlace
	vdcf_outl(VBI_CGMS_C1_reg, 0x000E0115); // active line	14
	vdcf_outl(VBI_CGMS_C5_reg, 0x0038403c); // for	480i
	vdcf_outl(VBI_CGMS_C3_reg, 0x0100001e); // bit 24  auto  period
#endif
}

void Scaler_vbi_cgms_Uninit(CGMS_SOURCE source)
{
#if 0
	VBI_CGMS_PARAM param = {source,0};
	unsigned int *pulTemp = NULL;
	unsigned int ulCount = 0, i = 0;

	pulTemp = (unsigned int*)Scaler_GetShareMemVirAddr(SCALERIOC_VBICGMSENABLE);
	ulCount = sizeof(VBI_CGMS_PARAM) / sizeof(unsigned int);
	// copy to RPC share memory
	memcpy(pulTemp, &param, sizeof(VBI_CGMS_PARAM));

	for (i = 0; i < ulCount; i++)
		pulTemp[i] =htonl(pulTemp[i]);

	{
		int ret;
		if (0 != (ret = Scaler_SendRPC(SCALERIOC_VBICGMSENABLE,0,0)))
		{
			pr_debug("ret=%d, uninit VBI CGMS fail !!!\n", ret);
			//return;

		}
	}
#else
#if 0
	vbi_cgms_c4_RBUS vbi_cgms_c4_reg;//sunray
	vbi_cgms_c4_reg.regValue=vdcf_inl(VBI_CGMS_C4_reg);
	vbi_cgms_c4_reg.vbisl16_cgms_int_en=0;
	vdcf_outl(VBI_CGMS_C4_reg,vbi_cgms_c4_reg.regValue);
#endif
#endif
	vbi_slicer_status[VBI_CGMS]=VBI_DATA_NON;
	vbi_cgms_data = 0;
}

unsigned int Scaler_VbiGet_cgms(void)
{
#if 0
	if(vbi_slicer_status[VBI_CGMS]==VBI_DATA_COLLECTED)
	{
		return vbi_cgms_data;
	}
	else
	{
		return 0;
	}
#else
	return vbi_cgms_data;
#endif
}
void Scaler_vbi_ttx_interrupt_set(unsigned char enable)
{
	vdtop_irq_mask1_RBUS vdtop_irq_mask1_reg;
	vdtop_irq_mask2_RBUS vdtop_irq_mask2_reg;
	vbi_vbi_dump_int_RBUS vbi_dump_int_reg;
	sys_reg_int_ctrl_vcpu_RBUS crt_int_ctrl_vcpu;
	if (enable) {
		vbi_dump_int_reg.regValue=vdcf_inl(VBI_VBI_DUMP_int_reg);
		vbi_dump_int_reg.vbi_dump_irq_en=1;  //ttx dma interrupt
		vdcf_outl(VBI_VBI_DUMP_int_reg,vbi_dump_int_reg.regValue);
		crt_int_ctrl_vcpu.regValue = 0;//open vbi routing to avoid vbi interrupt not handle
		crt_int_ctrl_vcpu.vbi_int_vcpu_routing_en = 1 ;
		crt_int_ctrl_vcpu.write_data = 1;
		IoReg_Write32(SYS_REG_INT_CTRL_VCPU_reg, crt_int_ctrl_vcpu.regValue);
#ifdef VBI_TTX_NEW_DMA_ENABLE
		vdtop_irq_mask1_reg.regValue = vdcf_inl(VDTOP_IRQ_MASK1_reg);
		vdtop_irq_mask1_reg.vd_irq_en = 1;
		vdcf_outl(VDTOP_IRQ_MASK1_reg,vdtop_irq_mask1_reg.regValue);
		vdtop_irq_mask2_reg.regValue = vdcf_inl(VDTOP_IRQ_MASK2_reg);
		vdtop_irq_mask2_reg.field_irq_en = 1;
		vdcf_outl(VDTOP_IRQ_MASK2_reg,vdtop_irq_mask2_reg.regValue);
		crt_int_ctrl_vcpu.regValue = 0;//open vd routing to avoid vbi interrupt not handle
		crt_int_ctrl_vcpu.vdec_int_vcpu_routing_en = 1 ;
		crt_int_ctrl_vcpu.write_data = 1;
		IoReg_Write32(SYS_REG_INT_CTRL_VCPU_reg, crt_int_ctrl_vcpu.regValue);
#endif
	} else {
#ifdef VBI_TTX_NEW_DMA_ENABLE
		vdtop_irq_mask1_reg.regValue = vdcf_inl(VDTOP_IRQ_MASK1_reg);
		vdtop_irq_mask1_reg.vd_irq_en = 0;
		vdcf_outl(VDTOP_IRQ_MASK1_reg,vdtop_irq_mask1_reg.regValue);
		vdtop_irq_mask2_reg.regValue = vdcf_inl(VDTOP_IRQ_MASK2_reg);
		vdtop_irq_mask2_reg.field_irq_en = 0;
		vdcf_outl(VDTOP_IRQ_MASK2_reg,vdtop_irq_mask2_reg.regValue);
		crt_int_ctrl_vcpu.regValue = 0;//close vd routing to avoid vbi interrupt not handle
		crt_int_ctrl_vcpu.vdec_int_vcpu_routing_en = 1 ;
		crt_int_ctrl_vcpu.write_data = 0;
		IoReg_Write32(SYS_REG_INT_CTRL_VCPU_reg, crt_int_ctrl_vcpu.regValue);
#endif
		crt_int_ctrl_vcpu.regValue = 0;//close vbi routing to avoid vbi interrupt not handle
		crt_int_ctrl_vcpu.vbi_int_vcpu_routing_en = 1 ;
		crt_int_ctrl_vcpu.write_data = 0;
		IoReg_Write32(SYS_REG_INT_CTRL_VCPU_reg, crt_int_ctrl_vcpu.regValue);	
		vdcf_outl(VBI_VBIPPR_POWER_CTRL_reg,vdcf_inl(VBI_VBIPPR_POWER_CTRL_reg) &(~VBI_VBIPPR_POWER_CTRL_vbi_tt_dma_en_mask));		
	}
}
void Scaler_tt_init_enable(void)
{
	vbi_slicer_status[VBI_PAL_TELETEXT]=VBI_DATA_COLLECTING;
	vbi_slicer_status[VBI_PAL_WSS]=VBI_DATA_COLLECTING;
	down(get_VBI_vps_semaphore());
	if (vbi_slicer_status[VBI_PAL_VPS] ==VBI_DATA_NON) {//ttx driver setting
		up(get_VBI_vps_semaphore());
		vdcf_outl(VBI_TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_reg, 0x66666666); // line 13,14,15,16
		vdcf_outl(VBI_TT_VBI_NOISY_CTRL4_reg, 0x808000a0);
		vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg, 0x00004600);
	} else {
		up(get_VBI_vps_semaphore());
	}
	Scaler_vbi_ttx_interrupt_set(1);
}
#if 0
void Scaler_vps_init_enable(void)
{
	vbi_tt_vbi_data_status_RBUS vbi_data_status_reg;//sunray
	vbi_data_status_reg.regValue=vdcf_inl(VBI_TT_VBI_DATA_STATUS_reg);
	vbi_data_status_reg.tt_vps_int_en=1;  //vps line interrupt
	vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg,vbi_data_status_reg.regValue);
	if (vdcf_inl(VBI_VBI_VOUNT_SHIFT_reg)) {
		if (vdcf_inl(VBI_TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_reg)!=VPS_SLICER_LINE_FIELD_EVEN) {
			vdcf_outl(VBI_TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_17_20_reg, VPS_SLICER_LINE_FIELD_EVEN); // line 17,18,19,20
		//VBI_rtd_clearbits(VBI_TT_VBI_NOISY_CTRL4_reg,_BIT31);
		}
	} else {//mantis 73651
		if (vdcf_inl(VBI_TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_reg)!=0x36666666) {
			vdcf_outl(VBI_TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_13_16_reg, 0x36666666); // line 17,18,19,20
		//VBI_rtd_clearbits(VBI_TT_VBI_NOISY_CTRL4_reg,_BIT31);
		}
	}
	vbi_slicer_status[VBI_PAL_VPS]=VBI_DATA_COLLECTING;
}
#endif
void Scaler_cc_init_enable(void)
{
	vbi_tt_vbi_data_status_RBUS vbi_data_status_reg;//sunray
	vbi_data_status_reg.regValue=vdcf_inl(VBI_TT_VBI_DATA_STATUS_reg);
	vbi_data_status_reg.tt_cc_int_en=1;  //ttx dma interrupt
	vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg,vbi_data_status_reg.regValue);
	vbi_slicer_status[VBI_NTSC_CC]=VBI_DATA_COLLECTING;
	vbi_slicer_status[VBI_NTSC_WSS]=VBI_DATA_COLLECTING;
}

void Scaler_vbi_cgms_init_enable(void)
{
	vbi_cgms_c4_RBUS vbi_cgms_c4_reg;//sunray
	vbi_cgms_c4_reg.regValue=vdcf_inl(VBI_CGMS_C4_reg);
	vbi_cgms_c4_reg.vbisl16_cgms_int_en=1;
	vdcf_outl(VBI_CGMS_C4_reg,vbi_cgms_c4_reg.regValue);
//	vbi_slicer_status[VBI_CGMS]=VBI_DATA_COLLECTING;
}

void palwss_data_send(void)
{
	unsigned int regData;
	unsigned short wssData = 0;
	unsigned char cnt=2;
	unsigned short vbi_wss_change_flag=0;
	while(cnt){
		regData = vdcf_inl(VBI_TT_VBI_CCWSS_DATA_reg);
		wssData = ((regData>>8)&0xff00)|(regData>>24&0xff);
		if (wssData != vbi_preWss)
		{
			vbi_preWss = wssData;
			vbi_wss_change_flag = 1;
		} else {
			if ((vbi_pal_wss!=vbi_preWss) &&(vbi_wss_change_flag == 1)) {
				vbi_pal_wss=vbi_preWss;
				vbi_slicer_status[VBI_PAL_WSS]=VBI_DATA_COLLECTED;
				pr_notice("kernelvbi_pal_wss=%x\n",vbi_pal_wss);
				break;
			}
		}
		cnt--;
		if(cnt!=0) {
			msleep(10);
		}
	}
}

void vbi_just_576i_wss_init(void)
{
	sys_reg_int_ctrl_vcpu_RBUS crt_int_ctrl_vcpu;
	vbi_vbi_dump_int_RBUS vbi_dump_int_reg;
	vbi_dump_int_reg.regValue=vdcf_inl(VBI_VBI_DUMP_int_reg);
	if (vbi_dump_int_reg.vbi_dump_irq_en) {	
		vbi_dump_int_reg.vbi_dump_irq_en=0;  //ttx dma interrupt
		vdcf_outl(VBI_VBI_DUMP_int_reg,vbi_dump_int_reg.regValue);
	}
	if (SYS_REG_INT_CTRL_VCPU_get_vbi_int_vcpu_routing_en(IoReg_Read32(SYS_REG_INT_CTRL_VCPU_reg)) == 0) {
		crt_int_ctrl_vcpu.regValue = 0;//open vbi routing to avoid vbi interrupt not handle
		crt_int_ctrl_vcpu.vbi_int_vcpu_routing_en = 1 ;
		crt_int_ctrl_vcpu.write_data = 1;
		IoReg_Write32(SYS_REG_INT_CTRL_VCPU_reg, crt_int_ctrl_vcpu.regValue);
	}
	if ( vdcf_inl(VDTOP_VSYNC_TIME_CONST_reg) & _BIT7) {//sunray
		vdcf_outl(VBI_VBISL0_reg, 0x00000060);
	} else {
		vdcf_outl(VBI_VBISL0_reg, 0x00000040);
	}
	vdcf_outl(VBI_TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_reg, 0x00cc0000);
	vdcf_outl(VBI_VBI_VOUNT_SHIFT_reg,0x00000000);
	vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg, 0x00004600);
	vdcf_outl(VBI_TT_VBI_NOISY_CTRL1_reg, 0x1150a023);
	vdcf_outl(VBI_TT_VBI_NOISY_CTRL2_reg, 0x80800099);
	vdcf_outl(VBI_TT_VBI_NOISY_CTRL4_reg, 0x808000a0);
	vdcf_outl(VBI_TT_VBI_CO_CH_CTRL_reg, 0x00000000);	//force compensation off
	vdcf_outl(VBI_TT_VBI_STATUS1_reg, 0x800e01bb);
	vdcf_outl(VBI_TT_VBI_Control_Register_reg, 0x5a5a2713);
	if((vdcf_inl(VDTOP_LUMA_AGC_VALUE_reg) & 0xff) == 0x82)		//d gain 0.6//sunray
		vdcf_outl(VBI_TT_VBI_CLAMPAGC_CTRL_reg,0x86403c14);
	else
		vdcf_outl(VBI_TT_VBI_CLAMPAGC_CTRL_reg,0x83c03c0c);
	vdcf_outl(VBI_TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_reg, 0x00004444);//loop filter gain kp = 0x4
	vdcf_outl(VBI_TT_VBI_NOISY_CTRL_reg, 0x0f023110);	// bit 20 = 0 : disable the 2nd fix slicer level method
	vdcf_outl(VBI_TT_VBI_DTO_FRAME_START_reg, 0xbe6fb4a8);//20120425 kist modify,0x78->0x6f(TT frame start)
	vdcf_outl(VBI_TT_VBI_DTO_REGISTER2_reg, 0x15991599);
	vdcf_outl(VBI_TT_VBI_NOISY_CTRL5_reg, 0x00000000);
	vdcf_outl(VBI_TT_VBI_WSS_VPS_VOTE_reg, vdcf_inl(VBI_TT_VBI_WSS_VPS_VOTE_reg) &(~VBI_TT_VBI_WSS_VPS_VOTE_wss_data_sel_mask));
	vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg,vdcf_inl(VBI_TT_VBI_DATA_STATUS_reg) | VBI_TT_VBI_DATA_STATUS_tt_wss_int_en_mask); //open interrupt
	vbi_slicer_status[VBI_PAL_WSS]=VBI_DATA_COLLECTING;
}

void vbi_just_576i_wss_uninit(void)
{
	vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg,vdcf_inl(VBI_TT_VBI_DATA_STATUS_reg) &(~VBI_TT_VBI_DATA_STATUS_tt_wss_int_en_mask));//close interrupt
	vbi_slicer_status[VBI_PAL_WSS]=VBI_DATA_NON;
	vbi_pal_wss = 0;
	Scaler_reset_vbi_wss();
}

void vbi_576i_wss_under_cc_init(void)
{
	sys_reg_int_ctrl_vcpu_RBUS crt_int_ctrl_vcpu;
	vbi_vbi_dump_int_RBUS vbi_dump_int_reg;
	vbi_dump_int_reg.regValue=vdcf_inl(VBI_VBI_DUMP_int_reg);
	if (vbi_dump_int_reg.vbi_dump_irq_en) { 
		vbi_dump_int_reg.vbi_dump_irq_en=0;  //ttx dma interrupt
		vdcf_outl(VBI_VBI_DUMP_int_reg,vbi_dump_int_reg.regValue);
	}
	if (SYS_REG_INT_CTRL_VCPU_get_vbi_int_vcpu_routing_en(IoReg_Read32(SYS_REG_INT_CTRL_VCPU_reg)) == 0) {
		crt_int_ctrl_vcpu.regValue = 0;//open vbi routing to avoid vbi interrupt not handle
		crt_int_ctrl_vcpu.vbi_int_vcpu_routing_en = 1 ;
		crt_int_ctrl_vcpu.write_data = 1;
		rtd_outl(SYS_REG_INT_CTRL_VCPU_reg, crt_int_ctrl_vcpu.regValue);
	}

	if ( vdcf_inl(VDTOP_VSYNC_TIME_CONST_reg) & _BIT7) {//sunray
		vdcf_outl(VBI_VBISL0_reg, 0x00000060); 
	} else {
		vdcf_outl(VBI_VBISL0_reg, 0x00000040);
	}
	vdcf_outl(VBI_TT_VBI_DATA_TYPE_CONFIG_REG_FOR_LINE_21_24_reg, 0x00cc0011); 
	vdcf_outl(VBI_VBI_VOUNT_SHIFT_reg,0x00000000);
	//vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg, 0x00004600);
	vdcf_outl(VBI_TT_VBI_NOISY_CTRL1_reg, 0x1150a023);
	vdcf_outl(VBI_TT_VBI_NOISY_CTRL2_reg, 0x80800099);
	vdcf_outl(VBI_TT_VBI_NOISY_CTRL4_reg, 0x808000a0);
	vdcf_outl(VBI_TT_VBI_CO_CH_CTRL_reg, 0x000000a0);	//force compensation off  
	vdcf_outl(VBI_TT_VBI_STATUS1_reg, 0x800e01bb);
	if((vdcf_inl(VDTOP_LUMA_AGC_VALUE_reg) & 0xff) == 0x82)		//d gain 0.6//sunray
		vdcf_outl(VBI_TT_VBI_CLAMPAGC_CTRL_reg,0x86403c14);
	else
		vdcf_outl(VBI_TT_VBI_CLAMPAGC_CTRL_reg,0x83c03c0c);
	vdcf_outl(VBI_TT_VBI_LOOP_FILTER_I_GAIN_REGISTER_reg, 0x00004444);//loop filter gain kp = 0x4   
	vdcf_outl(VBI_TT_VBI_NOISY_CTRL_reg, 0x0f023110);	// bit 20 = 0 : disable the 2nd fix slicer level method
	vdcf_outl(VBI_TT_VBI_DTO_FRAME_START_reg, 0xbe6fb4a8);//20120425 kist modify,0x78->0x6f(TT frame start)
	vdcf_outl(VBI_TT_VBI_DTO_REGISTER2_reg, 0x15991599);
	vdcf_outl(VBI_TT_VBI_NOISY_CTRL5_reg, 0x00000000);
	vdcf_outl(VBI_TT_VBI_WSS_VPS_VOTE_reg,0x100f2d11);//reset for clear CC path setting  
	vdcf_outl(VBI_TT_VBI_DATA_STATUS_reg,vdcf_inl(VBI_TT_VBI_DATA_STATUS_reg) | VBI_TT_VBI_DATA_STATUS_tt_wss_int_en_mask); //open interrupt
	vbi_slicer_status[VBI_PAL_WSS]=VBI_DATA_COLLECTING;
}

void wss_data_clear(void)
{
	vbi_pal_wss = 0;
}
void wss_data_receive(void)
{
	unsigned int regData;
	if (vdcf_inl(VBI_TT_VBI_DATA_STATUS_reg) & VBI_TT_VBI_DATA_STATUS_tt_wss_rdy_mask) {
		regData = vdcf_inl(VBI_TT_VBI_CCWSS_DATA_reg);
		vbi_pal_wss = ((regData>>8)&0xff00)|(regData>>24&0xff);
		vdcf_maskl(VBI_TT_VBI_DATA_STATUS_reg,  ~(VBI_TT_VBI_DATA_STATUS_tt_wss_rdy_mask|VBI_TT_VBI_DATA_STATUS_tt_vps_rdy_mask|VBI_TT_VBI_DATA_STATUS_tt_cc_rdy_mask|VBI_TT_VBI_DATA_STATUS_tt_tt_rdy_mask), VBI_TT_VBI_DATA_STATUS_tt_wss_rdy_mask);
		pr_debug("vbi_pal_wss=%x\n",vbi_pal_wss);
	} else {
		wss_data_clear();
	}
}
void cgms_data_clear(void)
{
	vbi_cgms_data = 0;
}
void cgms_data_receive(void)
{
	unsigned int regData;
	if (vdcf_inl(VBI_CGMS_C4_reg) & VBI_CGMS_C4_cgms_c4_cgms_vld_mask) {
		regData = vdcf_inl(VBI_CGMS_C4_reg);
		vbi_cgms_data =regData&0xfffff;
		vdcf_maskl(VBI_CGMS_C4_reg,  ~(VBI_CGMS_C4_cgms_c4_cgms_vld_mask), VBI_CGMS_C4_cgms_c4_cgms_vld_mask);
		pr_debug("vbi_cgms_data=%x\n",vbi_cgms_data);
	} else {
		cgms_data_clear();
	}
}

void Scaler_vbi_data_to_video(VBI_TYPE_T vbi_type, unsigned int data)
{
	unsigned int *pulTemp;
	unsigned int i = 0, ulItemCount = 0;
	VBI_UPDATE_DATA_INFO *vbi_info_pkg = NULL;
	VBI_UPDATE_DATA_INFO update_info;
	vbi_info_pkg = (VBI_UPDATE_DATA_INFO *)Scaler_GetShareMemVirAddr(SCALERIOC_VBI_SHAREMEMORY_DATA);
	if (vbi_info_pkg) {
		memcpy(&update_info,vbi_info_pkg, sizeof(VBI_UPDATE_DATA_INFO));
		ulItemCount = sizeof(VBI_UPDATE_DATA_INFO) /  sizeof(UINT32);
		pulTemp = (unsigned int *)&update_info;
		for (i = 0; i < ulItemCount; i++)
			pulTemp[i] = Scaler_ChangeUINT32Endian(pulTemp[i]);
		update_info.vbi_data[vbi_type] = data;
		update_info.vbi_valid[vbi_type] = 1;
		for (i = 0; i < ulItemCount; i++)
			pulTemp[i] = Scaler_ChangeUINT32Endian(pulTemp[i]);
		memcpy(vbi_info_pkg,&update_info, sizeof(VBI_UPDATE_DATA_INFO));
	}
}

void Scaler_reset_vbi_wss(void)
{
	vbi_slicer_status[VBI_PAL_WSS]=VBI_DATA_COLLECTING;
	Scaler_vbi_data_to_video(VBI_PAL_WSS, 0);
}

unsigned char Scaler_vbi_ttx_signal(void)
{
	TTX_VBI_IOCTL_PARAM param;
	param.data = 0xff;
	param.mode = VBI_GET_SIGNAL;
	Scaler_VbiTtSetGetProperty(&param);
	if (param.data!=0xff) {
		return param.data;
	} else {
		return 0;
	}
}
