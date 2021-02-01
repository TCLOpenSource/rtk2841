/******************************************************************************
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author yping@realtek.com
 *
 *****************************************************************************/
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/jiffies.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <asm/cacheflush.h>

#include <linux/module.h>
#include <linux/pageremap.h>
#include <linux/string.h>
#ifdef CONFIG_LG_SNAPSHOT_BOOT
#include <linux/suspend.h>
#endif
#include <base_types.h>

#include <rbus/tp_reg.h>

#include <tp/tp_dbg.h>
#include <tp/tp_def.h>

#include <tp/tp_drv.h>
#include <tp/tp_ioctl.h>
#include <tp/tp_drv_global.h>
#include <tp/tp_reg_ctrl.h>
#include <tp/tp_drv_verify.h>

#define TP_REG_BASE         TP_TP_TF0_CNTL_reg
#define TP_REG_LIMIT        TP_TP_DEBUG_reg

TP_REG_RW_T Reg_rw_Parm;

/* for TP APIs */
TP_IOC_BASIC_T param_basic;
TP_IOC_SET_TP_MODE_T param_set_tp_mode;
TP_IOC_GET_TP_MODE_T param_get_tp_mode;
TP_IOC_SET_TP_RING_BUFF_T param_tp_set_buf;
TP_IOC_GET_TP_BUF_STATUS_T param_tp_buf_status;
TP_IOC_TP_STREAM_CONTROL_T param_strm_ctrl;
TP_IOC_TP_READ_DATA_T param_read_data;
TP_IOC_TP_RELEASE_DATA_T param_tp_rel_data;
TP_IOC_TP_SOURCE_T param_tp_src;
TP_IOC_TP_SET_RAW_MODE_T param_tp_raw_mode;
TP_IOC_TP_SYNC_REPLACE_T param_tp_sync_replace;

/* TPOUT APIs */
TP_IOC_TPOUT_MODE_T param_set_tpout_mode;
TP_IOC_TPOUT_MODE_T param_get_tpout_mode;
TP_IOC_TPOUT_DATA_SOURCE_T param_tpout_src;
TP_IOC_TPOUT_STREAM_CONTROL_T param_tpout_strm_ctrl;
TP_IOC_GET_TPOUT_STATUS_T param_tpout_status;
TP_IOC_SET_TPOUT_CLK_T param_tpout_clk;

/* MTP APIs */
TP_IOC_SET_MTP_BUFF_T param_mtp_set_buff;
TP_IOC_WRITE_MTP_BUFF_T param_mtp_wrt_buff;
TP_IOC_GET_MTP_BUF_STATUS_T param_mtp_buff_status;
TP_IOC_MTP_STREAM_CONTROL_T param_mtp_strm_ctrl;
TP_IOC_GET_TP_STATUS_T param_tp_status;
TP_IOC_GET_MTP_STATUS_T param_mtp_status;
TP_IOC_MTP_FLUSH_T param_mtp_flush;

/* FRC APIs */
TP_IOC_FRC_ENABLE_T param_frc_enable;
TP_IOC_FRC_SET_RATE_T param_frc_rate;
TP_IOC_FRC_SET_PREFIX_T param_frc_prefix;


/* PID filter */
TP_IOC_ADD_PID_FILTER_T param_pid_add_filter;
TP_IOC_REMOVE_PID_FILTER_T param_pid_rmv_filter;
TP_IOC_REMOVE_ALL_PID_T param_pid_rmv_all;
TP_IOC_GET_PID_STATUS_T param_pid_get_staus;

/*  Section filter */
TP_IOC_ADD_SECTION_FILTER_T param_sec_add_filter;
TP_IOC_REMOVE_SECTION_FILTER_T param_sec_rmv_filter;
TP_IOC_REMOVE_ALL_SECTION_T param_sec_rmv_all;
TP_IOC_GET_SECTION_STATUS_T param_sec_get_staus;
TP_IOC_GET_SECTION_DATA_T param_sec_get_data;
TP_IOC_SET_PIDEN_T param_set_piden;


/* PCR tracking */
TP_IOC_PCR_TRACKING_EN_T param_pcr_track_en;
TP_IOC_GET_PCR_TRACKING_T param_pcr_track_get;
TP_IOC_RESET_PCR_TRACKING_T param_pcr_track_rst;

/* Descrambler APIs */
TP_IOC_DESCRAMBLE_ALGORITHM_T param_dsc_alg;
TP_IOC_SET_CW_T param_set_cw;
TP_IOC_DESCRAMBLE_CONTROL_T param_dsc_ctrl;
TP_IOC_SET_ENCRYPTION_T param_encryption;

/* Start Code APIs */
TP_IOC_STARTCODE_ENABLE_T param_sc_enable;
TP_IOC_STARTCODE_SET_PID_T param_sc_set_pid;
TP_IOC_BASIC_T param_sc_flush;
TP_IOC_STARTCODE_SET_BUFFER_T param_sc_set_buf;
TP_IOC_STARTCODE_READ_INFO_T param_sc_read;
TP_IOC_STARTCODE_RELEASE_INFO_T param_sc_relase;

/* CI PLUS APIs */

TP_IOC_TPP_MODE_T param_set_mode;
TP_IOC_TPP_MODE_T param_get_mode;
TP_IOC_TPP_SET_PIDEN_T param_tpp_set_piden;
TP_IOC_TPP_STREAM_CONTROL_T param_tpp_strm_ctrl;
TP_IOC_GET_TPP_BUF_STATUS_T param_tpp_buff_status;
TP_IOC_TPP_BASIC_T param_tpp_flush;
TP_IOC_SET_TPP_SYNC_REPLACE_T param_tpp_sync_replace;

/*  for debug info */
TP_IOC_TRACK_ERR_PACKET_T param_track_err_pkt;
TPK_HARDWARE_INFO_T param_hardware_info;
TPK_DUMP_REG_INFO_T param_dump_reg_info;

/*------------------------------------------------------------------
 *    COMMON APIS
 *------------------------------------------------------------------*/

unsigned long pli_to_kernel_ex(unsigned long addr)
{
        struct vm_area_struct* vm_area = find_vma(current->mm, (unsigned long) addr);
        unsigned long pfn;
        unsigned long virt_addr;

        if (vm_area == NULL || follow_pfn(vm_area, (unsigned long) addr, &pfn))
                return 0;

        virt_addr = __phys_to_virt(__pfn_to_phys(pfn)) + (((unsigned long)addr) % PAGE_SIZE);

        return virt_addr;
}


int tp_reg_rw(TP_REG_RW_T* pReg_rw)
{
        unsigned long reg_offset, i;

        /* check length */
        if (pReg_rw->Len > TP_REG_RW_SIZE) {
                TP_WARNING("Length over limitation (Len = %u, unit: 4 Bytes)\n", pReg_rw->Len);
                return -EFAULT;
        }

        /* get register offset */
        if (pReg_rw->bRegOffset)
                reg_offset = TP_REG_BASE + pReg_rw->Reg;
        else
                reg_offset = pReg_rw->Reg;

        /* check if it is over reg range */
        if ((reg_offset < TP_REG_BASE) || ((reg_offset + (pReg_rw->Len * 4)) > TP_REG_LIMIT)) {
                TP_WARNING("reg_offset over limitation (reg_offset=0x%lx, Len*4=%u, BASE=0x%x, LIMIT=0x%x)\n",
                           reg_offset, pReg_rw->Len, TP_REG_BASE, TP_REG_LIMIT );
                return -EFAULT;
        }

        /* check if it is read or write operation */
        if (pReg_rw->bRead) {
                for (i = 0; i < pReg_rw->Len; i++)
                        pReg_rw->Data[i] = READ_REG32(reg_offset + (i * 4));
        } else {
                for ( i = 0; i < pReg_rw->Len; i++)
                        WRITE_REG32(reg_offset + (i * 4), pReg_rw->Data[i]);
        }

        return 0;
}

/*------------------------------------------------------------------
 *    SECTION APIS
 *------------------------------------------------------------------*/
static struct mutex    mutex;
static stSecBufData* pSecbufdata = NULL;
static stSecBufData* pSecbufdata_nonchched = NULL;

INT32 TPVerify_CreateSectionBuffer(void)
{
        INT32 result = 0;
        UINT32 i;
#ifdef CONFIG_LG_SNAPSHOT_BOOT
        UADDRESS sec_buf_phy = 0;
#endif

        /* pSecbufdata = (stSecBufData*)dvr_malloc(sizeof(stSecBufData)); */
        pSecbufdata = (stSecBufData*)dvr_malloc_uncached_specific(sizeof(stSecBufData), GFP_DCU2_FIRST, (void **) & pSecbufdata_nonchched);

        if (NULL != pSecbufdata) {
#ifdef CONFIG_LG_SNAPSHOT_BOOT
                /* check phy secBuff */
                sec_buf_phy = dvr_to_phys((void*)pSecbufdata);
                if ( sec_buf_phy == 0 ) {
                        TP_WARNING( "error, virt addr to phy addr fail\n" );
                        return TPK_NOT_ENOUGH_RESOURCE;
                }
                register_cma_forbidden_region(__phys_to_pfn(sec_buf_phy), sizeof(stSecBufData));
#endif

                memset((void*)pSecbufdata, 0, sizeof(stSecBufData));
                for (i = 0; i < SEC_FILTER_BUFFER_NUM; i++) {
                        pSecbufdata->SecMap[i].u32VirAddr = (UADDRESS)pSecbufdata->aSecBuf + SEC_FILTER_BUFFER_EACH_SIZE * i;
                }
        } else {
                result = -1;
        }


        return result;
}

INT32 TPVerify_ReleaseSectionBuffer(void)
{
        INT32 result = 0;

        dvr_free(pSecbufdata);
        pSecbufdata = NULL;

        return result;
}

INT32 _GetFreeSectionBuffer(IN BOOL bIsGet, IN void* pContext, IN UINT32 u32Index, OUT UADDRESS* pu32VirAddr)
{
        INT32 result = -1;
        UINT32 i;
        if (bIsGet) {
                if ((pSecbufdata->u32SecBufCnt >= SEC_FILTER_BUFFER_NUM) || (pu32VirAddr == NULL)) {
                        result = -1 ;
                } else {
                        for (i = 0; i < SEC_FILTER_BUFFER_NUM; i++) {
                                if (!pSecbufdata->SecMap[i].bOccupied) {
                                        pSecbufdata->SecMap[i].bOccupied  = TRUE;
                                        pSecbufdata->SecMap[i].bCompleted = FALSE;
                                        pSecbufdata->SecMap[i].u32Size    = 0;
                                        pSecbufdata->SecMap[i].pContext   = pContext;
                                        pSecbufdata->u32SecBufCnt++;

                                        *pu32VirAddr = pSecbufdata->SecMap[i].u32VirAddr;
                                        result = i;
                                        break;
                                }
                        }
                }
        } else {
                if ((u32Index >= SEC_FILTER_BUFFER_NUM) || (!pSecbufdata->SecMap[u32Index].bOccupied)) {
                        result = -1;
                } else {
                        pSecbufdata->SecMap[u32Index].bOccupied = FALSE;
                        pSecbufdata->u32SecBufCnt--;
                }
        }
        return result;
}


INT32 _SectionBufRequest (void* pContext, UINT8** ppBuf, UINT16 size)
{
        return _GetFreeSectionBuffer(TRUE, pContext, 0, (UADDRESS*)ppBuf);
}

INT32 _SectionBufFree (UINT32 u32Index)
{
        return _GetFreeSectionBuffer(FALSE, NULL, u32Index, NULL);
}


void _SectionBufComplete (void* pContext, TPK_SEC_DATA_T* pSec)
{
        pSecbufdata->SecMap[pSec->buf_idx].SecData    = *pSec;
        pSecbufdata->SecMap[pSec->buf_idx].u32Size    = pSec->len;
        pSecbufdata->SecMap[pSec->buf_idx].bCompleted = TRUE;
        pSecbufdata->SecMap[pSec->buf_idx].pContext = pContext;
}

INT32 TPVerify_GetSectionData(OUT BOOL* pbIsNew, OUT TPK_SEC_DATA_T* pSec, OUT void* pBuf, OUT UINT32* pHandleID)
{
        INT32 result = 0;
        UINT32 i;

        *pbIsNew = FALSE;

        for (i = 0; i < SEC_FILTER_BUFFER_NUM; i++) {
                if (pSecbufdata->SecMap[i].bOccupied && pSecbufdata->SecMap[i].bCompleted) {

                        *pbIsNew = TRUE;
                        *pHandleID = (UINT32)pSecbufdata->SecMap[i].pContext;
                        *pSec = pSecbufdata->SecMap[i].SecData;
                        memcpy(pBuf, (void*)pSecbufdata->SecMap[i].u32VirAddr, pSecbufdata->SecMap[i].u32Size);
                        _SectionBufFree(i);

                        break;
                }
        }

        return result;
}





INT32 TPVerify_AddSectionFilter(IN UINT8 tp_id, IN  TPK_SEC_FILTER_PARAM_T Param, IN void* file_handle, OUT void** ppSec_handle)
{
        Param.Request_buf = _SectionBufRequest;
        Param.Complete    = _SectionBufComplete;

        return RHAL_AddSectionFilter(tp_id, Param, file_handle, ppSec_handle);
}
/*------------------------------------------------------------------
 *    TP Start Code APIS
 *------------------------------------------------------------------*/

INT32 TPVerify_ReadStartCodeInfo(IN UINT8 tp_id, IN UINT8** ppReadPhyPtr, IN UINT32* pContinueReadSize)
{
        TP_BUFFER_PARAM_T buf_param;
        INT32 result, full_stataus = 0;


        UINT8 buf_idx    = TP0_START_CODE_PACK;
        UINT8 rp_idx    = START_CODE_PACK_BUFFER_RP;
        TPK_TP_BUF_T *pBuf    = &pTp_drv->tp[tp_id].start_code_search_buffer;
        INT32 block_size = START_CODE_PACK_BUFFER_BLOCK_SIZE;



        /* get buffer register */
        result = Tp_Get_Buffer(buf_idx, &buf_param);
        if (result != TPK_SUCCESS) {
                TP_WARNING("get buffer status fail (tp_id=%u)\n", tp_id);
                return result;
        }
        /* replace RP with mess data RP */
        buf_param.RP = pBuf->RP_Connect[rp_idx];
        *ppReadPhyPtr = (UINT8*)pBuf->RP_Connect[rp_idx];
        /* calucate length */
        *pContinueReadSize = GET_BUFF_DATA_SIZE(buf_param);   /* no Wrap */

        //TP_DBG("TP%d start code buffer :Base=%08x,RP=%08x,WP=%08x,Limit=%08x,*pContinueReadSize=%d\n",tp_id,buf_param.Base,buf_param.RP,buf_param.WP,buf_param.Limit,*pContinueReadSize);

        /* check if buffer full, flush buffer */
        result = Tp_Get_Buffer_Full_status(buf_idx, &full_stataus);
        if (result != TPK_SUCCESS) {
                TP_WARNING("get TP%u buffer full status fail (result=%d)\n", tp_id, result);
                return result;
        }
        if (full_stataus)
                return  TPK_BUFFER_FULL;

        return result;

}


INT32 TPVerify_ReleaseStartCodeInfo( TPK_TP_ENGINE_T tp_id, UINT8* pReadPhyPtr, UINT32 Size)
{
        TP_BUFFER_PARAM_T buf_param;
        INT32 result = 0;
        UINT32 Offset;

        UINT8 buf_idx    = TP0_START_CODE_PACK;
        UINT8 rp_idx    = START_CODE_PACK_BUFFER_RP;
        TPK_TP_BUF_T *pBuf    = &pTp_drv->tp[tp_id].start_code_search_buffer;
        INT32 block_size = START_CODE_PACK_BUFFER_BLOCK_SIZE;

        /* get buffer status */
        result = Tp_Get_Buffer(buf_idx, &buf_param);
        if (result != TPK_SUCCESS) {
                TP_WARNING("get buffer status fail (tp_id=%u)\n", tp_id);
                return result;
        }

        /* update to rp record */
        Offset = (UINT32)pReadPhyPtr;
        Offset += Size;
        if (Offset >= buf_param.Limit) {
                Offset = (Offset - buf_param.Limit) + buf_param.Base;
        }
        pBuf->RP_Connect[rp_idx] = Offset;

        /* check if need to update buffer rp reg */
        Tp_Update_Buffer_RP(tp_id , buf_idx, pBuf);

        return TPK_SUCCESS;


}


/*------------------------------------------------------------------
 *    Dump TP registers
 *------------------------------------------------------------------*/

INT32 TPVerify_DumpTPRegister(OUT TPK_DUMP_REG_INFO_T *dump_reg_info)
{
        UINT8 tp_id, key_idx, buf_idx;

        REGADDR tp_tf_cntl_addr, tp_tf_frmcfg_addr, tp_tf_int_addr, tp_tf_int_en_addr, tp_tf_cnt_addr, tp_tf_drop_addr, tp_tf_err_addr;
        REGADDR tp_pcr_ctl_addr, tp_tp_des_cntl_addr;

        REGADDR tp_m2m_ring_limit_addr, tp_m2m_ring_base_addr, tp_m2m_ring_rp_addr, tp_m2m_ring_wp_addr, tp_m2m_ring_ctrl_addr;
        REGADDR tp_p_m2m_ring_limit_addr, tp_p_m2m_ring_base_addr, tp_p_m2m_ring_rp_addr, tp_p_m2m_ring_wp_addr, tp_p_m2m_ring_ctrl_addr;
        REGADDR tp_p_tf_cntl_addr, tp_p_tf_frmcfg_addr, tp_p_tf_int_addr, tp_p_tf_int_en_addr, tp_p_tf_cnt_addr, tp_p_tf_drop_addr;
        tp_tp_ring_ctrl_RBUS       tp_ring_ctrl_reg;
        tp_tp_p_ring_ctrl_RBUS     tp_p_ring_ctrl_reg;
        tp_tp_key_ctrl_RBUS        tp_key_ctrl_reg;

        if(dump_reg_info == NULL)
                return TPK_BAD_PARAMETER;

        for (tp_id = 0; tp_id < MAX_TP_COUNT; tp_id++) {

                switch (tp_id) {
                        case TP_TP0: {
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF0_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF0_FRMCFG_reg;
                                tp_tf_int_addr           = TP_TP_TF0_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF0_INT_EN_reg;
                                tp_tf_cnt_addr                   = TP_TP_TF0_CNT_reg;
                                tp_tf_drop_addr                  = TP_TP_TF0_DRP_CNT_reg;
                                tp_tf_err_addr                   = TP_TP_TF0_ERR_CNT_reg;
                                /* pcr */
                                tp_pcr_ctl_addr          = TP_TP0_PCR_CTL_reg;
                                /* descrambler */
                                tp_tp_des_cntl_addr      = TP_TP_TP0_DES_CNTL_reg;
                                /* tp mtp */
                                tp_m2m_ring_limit_addr   = TP_TP0_M2M_RING_LIMIT_reg;
                                tp_m2m_ring_base_addr    = TP_TP0_M2M_RING_BASE_reg;
                                tp_m2m_ring_rp_addr      = TP_TP0_M2M_RING_RP_reg;
                                tp_m2m_ring_wp_addr      = TP_TP0_M2M_RING_WP_reg;
                                tp_m2m_ring_ctrl_addr    = TP_TP0_M2M_RING_CTRL_reg;
                                /* tpp mtp */
                                tp_p_m2m_ring_limit_addr = TP_TP0_P_M2M_RING_LIMIT_reg;
                                tp_p_m2m_ring_base_addr  = TP_TP0_P_M2M_RING_BASE_reg;
                                tp_p_m2m_ring_rp_addr    = TP_TP0_P_M2M_RING_RP_reg;
                                tp_p_m2m_ring_wp_addr    = TP_TP0_P_M2M_RING_WP_reg;
                                tp_p_m2m_ring_ctrl_addr  = TP_TP0_P_M2M_RING_CTRL_reg;
                                /* tpp */
                                tp_p_tf_cntl_addr        = TP_TP_TF0_P_CNTL_reg;
                                tp_p_tf_frmcfg_addr      = TP_TP_TF0_P_FRMCFG_reg;
                                tp_p_tf_int_addr         = TP_TP_TF0_P_INT_reg;
                                tp_p_tf_int_en_addr      = TP_TP_TF0_P_INT_EN_reg;
                                tp_p_tf_cnt_addr         = TP_TP_TF0_P_CNT_reg;
                                tp_p_tf_drop_addr        = TP_TP_TF0_P_DRP_CNT_reg;

                                break;
                        }
                        case TP_TP1: {
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF1_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF1_FRMCFG_reg;
                                tp_tf_int_addr           = TP_TP_TF1_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF1_INT_EN_reg;
                                tp_tf_cnt_addr                   = TP_TP_TF1_CNT_reg;
                                tp_tf_drop_addr                  = TP_TP_TF1_DRP_CNT_reg;
                                tp_tf_err_addr                   = TP_TP_TF1_ERR_CNT_reg;
                                /* pcr */
                                tp_pcr_ctl_addr          = TP_TP1_PCR_CTL_reg;
                                /* descrambler */
                                tp_tp_des_cntl_addr      = TP_TP_TP1_DES_CNTL_reg;
                                /* tp mtp */
                                tp_m2m_ring_limit_addr   = TP_TP1_M2M_RING_LIMIT_reg;
                                tp_m2m_ring_base_addr    = TP_TP1_M2M_RING_BASE_reg;
                                tp_m2m_ring_rp_addr      = TP_TP1_M2M_RING_RP_reg;
                                tp_m2m_ring_wp_addr      = TP_TP1_M2M_RING_WP_reg;
                                tp_m2m_ring_ctrl_addr    = TP_TP1_M2M_RING_CTRL_reg;
                                /* tpp mtp */
                                tp_p_m2m_ring_limit_addr = TP_TP1_P_M2M_RING_LIMIT_reg;
                                tp_p_m2m_ring_base_addr  = TP_TP1_P_M2M_RING_BASE_reg;
                                tp_p_m2m_ring_rp_addr    = TP_TP1_P_M2M_RING_RP_reg;
                                tp_p_m2m_ring_wp_addr    = TP_TP1_P_M2M_RING_WP_reg;
                                tp_p_m2m_ring_ctrl_addr  = TP_TP1_P_M2M_RING_CTRL_reg;
                                /* tpp */
                                tp_p_tf_cntl_addr        = TP_TP_TF1_P_CNTL_reg;
                                tp_p_tf_frmcfg_addr      = TP_TP_TF1_P_FRMCFG_reg;
                                tp_p_tf_int_addr         = TP_TP_TF1_P_INT_reg;
                                tp_p_tf_int_en_addr      = TP_TP_TF1_P_INT_EN_reg;
                                tp_p_tf_cnt_addr         = TP_TP_TF1_P_CNT_reg;
                                tp_p_tf_drop_addr        = TP_TP_TF1_P_DRP_CNT_reg;

                                break;
                        }
                        case TP_TP2: {
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF2_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF2_FRMCFG_reg;
                                tp_tf_int_addr           = TP_TP_TF2_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF2_INT_EN_reg;
                                tp_tf_cnt_addr                   = TP_TP_TF2_CNT_reg;
                                tp_tf_drop_addr                  = TP_TP_TF2_DRP_CNT_reg;
                                tp_tf_err_addr                   = TP_TP_TF2_ERR_CNT_reg;
                                /* pcr */
                                tp_pcr_ctl_addr          = TP_TP2_PCR_CTL_reg;
                                /* descrambler */
                                tp_tp_des_cntl_addr      = TP_TP_TP2_DES_CNTL_reg;
                                /* tp mtp */
                                tp_m2m_ring_limit_addr   = TP_TP2_M2M_RING_LIMIT_reg;
                                tp_m2m_ring_base_addr    = TP_TP2_M2M_RING_BASE_reg;
                                tp_m2m_ring_rp_addr      = TP_TP2_M2M_RING_RP_reg;
                                tp_m2m_ring_wp_addr      = TP_TP2_M2M_RING_WP_reg;
                                tp_m2m_ring_ctrl_addr    = TP_TP2_M2M_RING_CTRL_reg;
                                /* tpp mtp */
                                tp_p_m2m_ring_limit_addr = TP_TP2_P_M2M_RING_LIMIT_reg;
                                tp_p_m2m_ring_base_addr  = TP_TP2_P_M2M_RING_BASE_reg;
                                tp_p_m2m_ring_rp_addr    = TP_TP2_P_M2M_RING_RP_reg;
                                tp_p_m2m_ring_wp_addr    = TP_TP2_P_M2M_RING_WP_reg;
                                tp_p_m2m_ring_ctrl_addr  = TP_TP2_P_M2M_RING_CTRL_reg;
                                /* tpp */
                                tp_p_tf_cntl_addr        = TP_TP_TF2_P_CNTL_reg;
                                tp_p_tf_frmcfg_addr      = TP_TP_TF2_P_FRMCFG_reg;
                                tp_p_tf_int_addr         = TP_TP_TF2_P_INT_reg;
                                tp_p_tf_int_en_addr      = TP_TP_TF2_P_INT_EN_reg;
                                tp_p_tf_cnt_addr         = TP_TP_TF2_P_CNT_reg;
                                tp_p_tf_drop_addr        = TP_TP_TF2_P_DRP_CNT_reg;

                                break;
                        }
                        case TP_TP3: {
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF3_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF3_FRMCFG_reg;
                                tp_tf_int_addr           = TP_TP_TF3_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF3_INT_EN_reg;
                                tp_tf_cnt_addr                   = TP_TP_TF3_CNT_reg;
                                tp_tf_drop_addr                  = TP_TP_TF3_DRP_CNT_reg;
                                tp_tf_err_addr                   = TP_TP_TF3_ERR_CNT_reg;
                                /* pcr */
                                tp_pcr_ctl_addr          = TP_TP3_PCR_CTL_reg;
                                /* TP3 do not support descrambler */
                                /* tp mtp */
                                tp_m2m_ring_limit_addr   = TP_TP3_M2M_RING_LIMIT_reg;
                                tp_m2m_ring_base_addr    = TP_TP3_M2M_RING_BASE_reg;
                                tp_m2m_ring_rp_addr      = TP_TP3_M2M_RING_RP_reg;
                                tp_m2m_ring_wp_addr      = TP_TP3_M2M_RING_WP_reg;
                                tp_m2m_ring_ctrl_addr    = TP_TP3_M2M_RING_CTRL_reg;
                                /* there is no tpp3 mtp */
                                /* three is no tpp */
                                break;
                        }
                        default:
                                break;
                }
                /* tp */
                dump_reg_info->tp_tf_cntl_reg[tp_id]   = READ_REG32(tp_tf_cntl_addr);
                dump_reg_info->tp_tf_frmcfg_reg[tp_id] = READ_REG32(tp_tf_frmcfg_addr);
                dump_reg_info->tp_tf_int_reg[tp_id]    = READ_REG32(tp_tf_int_addr);
                dump_reg_info->tp_tf_int_en_reg[tp_id] = READ_REG32(tp_tf_int_en_addr);
                dump_reg_info->tp_tf_cnt_reg[tp_id]    = READ_REG32(tp_tf_cnt_addr);
                dump_reg_info->tp_tf_drop_reg[tp_id] = READ_REG32(tp_tf_drop_addr);
                dump_reg_info->tp_tf_err_reg[tp_id] = READ_REG32(tp_tf_err_addr);

                /* pcr */
                dump_reg_info->tp_pcr_ctl_reg[tp_id] = READ_REG32(tp_pcr_ctl_addr);

                /* tp mtp */
                dump_reg_info->tp_m2m_ring_limit_reg[tp_id] = READ_REG32(tp_m2m_ring_limit_addr);
                dump_reg_info->tp_m2m_ring_base_reg[tp_id]  = READ_REG32(tp_m2m_ring_base_addr);
                dump_reg_info->tp_m2m_ring_rp_reg[tp_id]    = READ_REG32(tp_m2m_ring_rp_addr);
                dump_reg_info->tp_m2m_ring_wp_reg[tp_id]    = READ_REG32(tp_m2m_ring_wp_addr);
                dump_reg_info->tp_m2m_ring_ctrl_reg[tp_id]  = READ_REG32(tp_m2m_ring_ctrl_addr);


                if ( tp_id != TP_TP3 ) {
                        /* des & tdes */
                        dump_reg_info->tp_tp_des_cntl_reg[tp_id] = READ_REG32(tp_tp_des_cntl_addr);

                        /* tpp mtp */
                        dump_reg_info->tp_p_m2m_ring_limit_reg[tp_id] = READ_REG32(tp_p_m2m_ring_limit_addr);
                        dump_reg_info->tp_p_m2m_ring_base_reg[tp_id]  = READ_REG32(tp_p_m2m_ring_base_addr);
                        dump_reg_info->tp_p_m2m_ring_rp_reg[tp_id]   = READ_REG32(tp_p_m2m_ring_rp_addr);
                        dump_reg_info->tp_p_m2m_ring_wp_reg[tp_id]    = READ_REG32(tp_p_m2m_ring_wp_addr);
                        dump_reg_info->tp_p_m2m_ring_ctrl_reg[tp_id]  = READ_REG32(tp_p_m2m_ring_ctrl_addr);

                        /* tpp */
                        dump_reg_info->tp_tf_p_cntl_reg[tp_id]   = READ_REG32(tp_p_tf_cntl_addr);
                        dump_reg_info->tp_tf_p_frmcfg_reg[tp_id] = READ_REG32(tp_p_tf_frmcfg_addr);
                        dump_reg_info->tp_tf_p_int_reg[tp_id]    = READ_REG32(tp_p_tf_int_addr);
                        dump_reg_info->tp_tf_p_int_en_reg[tp_id] = READ_REG32(tp_p_tf_int_en_addr);
                        dump_reg_info->tp_tf_p_cnt_reg[tp_id]    = READ_REG32(tp_p_tf_cnt_addr);
                        dump_reg_info->tp_tf_p_drop_reg[tp_id] = READ_REG32(tp_p_tf_drop_addr);
                }
        }
        /* tpout */
        dump_reg_info->tp_tf_out_frmcfg_reg = READ_REG32(TP_TP_TF_OUT_FRMCFG_reg);
        dump_reg_info->tp_out_ctrl_reg      = READ_REG32(TP_TP_OUT_CTRL_reg);

        /* sync replace */
        dump_reg_info->tp_sync_rplace_reg   = READ_REG32(TP_TP_SYNC_RPLACE_reg);
        /* des & tdes */
        for (key_idx = 0; key_idx < MAX_KEY_COUNT; key_idx++) {
                tp_key_ctrl_reg.regValue = 0;
                tp_key_ctrl_reg.idx      = key_idx;
                WRITE_REG32(TP_TP_KEY_CTRL_reg, tp_key_ctrl_reg.regValue);

                dump_reg_info->tp_key_info_reg[key_idx]  = READ_REG32(TP_TP_KEY_INFO_0_reg);
                dump_reg_info->tp_key_info2_reg[key_idx] = READ_REG32(TP_TP_KEY_INFO_1_reg);
        }
        /* tp ddr ring buffer */

        for (buf_idx = 0; buf_idx < MAX_TP_BUFFER_COUNT; buf_idx++) {
                tp_ring_ctrl_reg.regValue = 0;
                tp_ring_ctrl_reg.idx      = buf_idx;
                WRITE_REG32(TP_TP_RING_CTRL_reg, tp_ring_ctrl_reg.regValue);

                dump_reg_info->tp_ring_limit_reg[buf_idx] = READ_REG32(TP_TP_RING_LIMIT_reg);
                dump_reg_info->tp_ring_base_reg[buf_idx]  = READ_REG32(TP_TP_RING_BASE_reg);
                dump_reg_info->tp_ring_rp_reg[buf_idx]    = READ_REG32(TP_TP_RING_RP_reg);
                dump_reg_info->tp_ring_wp_reg[buf_idx]    = READ_REG32(TP_TP_RING_WP_reg);
        }

        /* tp_p ring buffer */


        for (buf_idx = 0; buf_idx < MAX_TPP_BUFFER_COUNT; buf_idx++) {
                tp_p_ring_ctrl_reg.regValue = 0;
                tp_p_ring_ctrl_reg.idx          = buf_idx;
                WRITE_REG32(TP_TP_P_RING_CTRL_reg, tp_p_ring_ctrl_reg.regValue);

                /* clean tp_p ring buff data*/
                dump_reg_info->tp_p_ring_limit_reg[buf_idx] = READ_REG32(TP_TP_P_RING_LIMIT_reg);
                dump_reg_info->tp_p_ring_base_reg[buf_idx]  = READ_REG32(TP_TP_P_RING_BASE_reg);
                dump_reg_info->tp_p_ring_rp_reg[buf_idx]          = READ_REG32(TP_TP_P_RING_BASE_reg);
                dump_reg_info->tp_p_ring_wp_reg[buf_idx]          = READ_REG32(TP_TP_P_RING_BASE_reg);

        }
        /* tp_p sync replace */
        dump_reg_info->tp_p_sync_rplace_reg = READ_REG32(TP_TP_P_SYNC_RPLACE_reg);

        /* frame rate control */
        dump_reg_info->prefix_ctrl_reg  = READ_REG32(TP_PREFIX_CTRL_reg);
        dump_reg_info->prefix_data1_reg = READ_REG32(TP_PREFIX_DATA1_reg);
        dump_reg_info->prefix_data2_reg = READ_REG32(TP_PREFIX_DATA2_reg);
        dump_reg_info->prefix_data3_reg = READ_REG32(TP_PREFIX_DATA3_reg);
        dump_reg_info->fr_ctrl_reg      = READ_REG32(TP_FR_CTRL_reg);

        /* start code search */
        dump_reg_info->start_code_tp0_reg      = READ_REG32(TP_START_CODE_TP0_reg);
        dump_reg_info->start_code_tp1_reg      = READ_REG32(TP_START_CODE_TP1_reg);
        dump_reg_info->start_code_ctrl_tp0_reg = READ_REG32(TP_START_CODE_CTRL_TP0_reg);
        dump_reg_info->start_code_ctrl_tp1_reg = READ_REG32(TP_START_CODE_CTRL_TP1_reg);

        /* TPO CLK */
        dump_reg_info->tpout_clk_reg  = READ_REG32(SYS_REG_SYS_CLKSEL_reg);
        return TPK_SUCCESS;

}


/*------------------------------------------------------------------
 *    TP IOCTL APIS
 *------------------------------------------------------------------*/

long TPVerify_ioctl(struct file* file, unsigned int cmd, unsigned long arg)
{
        /* TP_DRV_T* p_this = (TP_DRV_T*) file->private_data; */
        int ret = -EFAULT;              /* 0:success */

        switch (cmd) {

                        /* TP APIs */
                case TP_IOC_INIT:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_basic, (void __user *)arg, sizeof(TP_IOC_BASIC_T))) {
                                TP_WARNING("TP_IOC_INIT, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPInit(param_basic.tp_id);
                        break;

                case TP_IOC_UNINIT:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_basic, (void __user *)arg, sizeof(TP_IOC_BASIC_T))) {
                                TP_WARNING("TP_IOC_UNINIT, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPUninit(param_basic.tp_id);
                        break;

                case TP_IOC_SET_TP_MODE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_set_tp_mode, (void __user *)arg, sizeof(TP_IOC_SET_TP_MODE_T))) {
                                TP_WARNING("TP_IOC_SET_TP_MODE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_SetTPMode(param_set_tp_mode.tp_id, param_set_tp_mode.Param);
                        break;

                case TP_IOC_GET_TP_MODE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_get_tp_mode, (void __user *)arg, sizeof(TP_IOC_GET_TP_MODE_T))) {
                                TP_WARNING("TP_IOC_GET_TP_MODE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }
                        TPK_TP_STATUS_T tp_status;

                        ret = RHAL_GetTpStatus(param_get_tp_mode.tp_id, &tp_status);
                        param_get_tp_mode.Param = tp_status.tp_param;

                        //TP_WARNING("\n@@@@  TP_IOC_GET_TP_MODE Param  serial= %d, data_order= %d, datapin= %d, sync_pol= %d ,val_pol= %d,clk_pol= %d,sync_byte=%d,ts_in_tsp_len=%d @@@@\n",param_tp_mode.Param.serial,param_tp_mode.Param.data_order,param_tp_mode.Param.datapin,param_tp_mode.Param.sync_pol,param_tp_mode.Param.val_pol,param_tp_mode.Param.clk_pol,param_tp_mode.Param.sync_byte,param_tp_mode.Param.ts_in_tsp_len);

                        if (copy_to_user((void __user *)arg, &param_get_tp_mode, sizeof(TP_IOC_GET_TP_MODE_T))) {
                                TP_WARNING("TP_IOC_GET_TP_MODE, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                case TP_IOC_GET_TP_STATUS:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tp_status, (void __user *)arg, sizeof(TP_IOC_GET_TP_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_TP_STATUS, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetTpStatus(param_tp_status.tp_id, &param_tp_status.tp_status);

                        if (copy_to_user((void __user *)arg, &param_tp_status, sizeof(TP_IOC_GET_TP_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_TP_STATUS, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                case TP_IOC_SET_TP_SOURCE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tp_src, (void __user *)arg, sizeof(TP_IOC_TP_SOURCE_T))) {
                                TP_WARNING("TP_IOC_SET_TP_DATA_SOURCE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_SetTPSource(param_tp_src.tp_id, param_tp_src.tp_src, param_tp_src.casType);
                        break;

                case TP_IOC_FLUSH_BUFF:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_basic, (void __user *)arg, sizeof(TP_IOC_BASIC_T))) {
                                TP_WARNING("TP_IOC_FLUSH_BUFF, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPFlushBuffer(param_basic.tp_id);
                        break;

                case TP_IOC_SET_TP_RING_BUFF:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tp_set_buf, (void __user *)arg, sizeof(TP_IOC_SET_TP_RING_BUFF_T))) {
                                TP_WARNING("TP_IOC_SET_TP_RING_BUFF, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_SetTPRingBuffer(param_tp_set_buf.tp_id, param_tp_set_buf.pPhyAddr, (UINT8*)pli_to_kernel_ex((unsigned long)param_tp_set_buf.pVirAddr), param_tp_set_buf.size);
                        break;

                case TP_IOC_GET_TP_BUF_STATUS:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tp_buf_status, (void __user *)arg, sizeof(TP_IOC_GET_TP_BUF_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_TP_BUF_STATUS, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetTPBufferStatus(param_tp_buf_status.tp_id, &param_tp_buf_status.BufferSize, &param_tp_buf_status.DataSize);

                        if (copy_to_user((void __user *)arg, &param_tp_buf_status, sizeof(TP_IOC_GET_TP_BUF_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_TP_BUF_STATUS, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                case TP_IOC_TP_STREAM_CONTROL:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_strm_ctrl, (void __user *)arg, sizeof(TP_IOC_TP_STREAM_CONTROL_T))) {
                                TP_WARNING("TP_IOC_TP_STREAM_CONTROL, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPStreamControl(param_strm_ctrl.tp_id, param_strm_ctrl.ctrl);
                        break;

                case TP_IOC_TP_READ_DATA:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_read_data, (void __user *)arg, sizeof(TP_IOC_TP_READ_DATA_T))) {
                                TP_WARNING("TP_IOC_TP_READ_DATA, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPReadData(param_read_data.tp_id, &param_read_data.pReadPhyPtr,
                                              &param_read_data.ContinueReadSize, param_read_data.Threshold);

                        if (copy_to_user((void __user *)arg, &param_read_data, sizeof(TP_IOC_TP_READ_DATA_T))) {
                                TP_WARNING("TP_IOC_TP_READ_DATA, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                case TP_IOC_TP_RELEASE_DATA:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tp_rel_data, (void __user *)arg, sizeof(TP_IOC_TP_RELEASE_DATA_T))) {
                                TP_WARNING("TP_IOC_TP_RELEASE_DATA, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPReleaseData(param_tp_rel_data.tp_id, param_tp_rel_data.pReadPhyPtr, param_tp_rel_data.Size);
                        break;
                case TP_IOC_TP_SET_RAW_MODE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tp_raw_mode, (void __user *)arg, sizeof(TP_IOC_TP_SET_RAW_MODE_T))) {
                                TP_WARNING("TP_IOC_TP_SET_RAW_MODE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = Tp_ENG_RawModeEnable(param_tp_raw_mode.tp_id, param_tp_raw_mode.enable);
                        break;
                case TP_IOC_TP_SYNC_REPLACE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tp_sync_replace, (void __user *)arg, sizeof(TP_IOC_TP_SYNC_REPLACE_T))) {
                                TP_WARNING("TP_IOC_TP_SYNC_REPLACE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = Tp_ENG_SetSyncReplace(param_tp_sync_replace.tp_id, param_tp_sync_replace.sync_replace);
                        break;

                        /* TPOUT APIs */
                case TP_IOC_SET_TPOUT_MODE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_set_tpout_mode, (void __user *)arg, sizeof(TP_IOC_TPOUT_MODE_T))) {
                                TP_WARNING("TP_IOC_SET_TPOUT_MODE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPOUTSetMode(param_set_tpout_mode.tpout_id, param_set_tpout_mode.Param);
                        break;
                case TP_IOC_GET_TPOUT_MODE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_get_tpout_mode, (void __user *)arg, sizeof(TP_IOC_TPOUT_MODE_T))) {
                                TP_WARNING("TP_IOC_GET_TPOUT_MODE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPOUTGetMode(param_get_tpout_mode.tpout_id, &param_get_tpout_mode.Param);
                        if (copy_to_user((void __user *)arg, &param_get_tpout_mode, sizeof(TP_IOC_TPOUT_MODE_T))) {
                                TP_WARNING("TP_IOC_GET_TPOUT_MODE, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                case TP_IOC_SET_TPOUT_DATA_SOURCE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tpout_src, (void __user *)arg, sizeof(TP_IOC_TPOUT_DATA_SOURCE_T))) {
                                TP_WARNING("TP_IOC_SET_TPOUT_DATA_SOURCE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPOUTSetDataSource(param_tpout_src.tpout_id, param_tpout_src.tpout_src, param_tpout_src.remux_param);
                        break;

                case TP_IOC_TPOUT_STREAM_CONTROL:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tpout_strm_ctrl, (void __user *)arg, sizeof(TP_IOC_TPOUT_STREAM_CONTROL_T))) {
                                TP_WARNING("TP_IOC_TPOUT_STREAM_CONTROL, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPOUTStreamControl(param_tpout_strm_ctrl.tpout_id, param_tpout_strm_ctrl.ctrl);
                        break;

                case TP_IOC_GET_TPOUT_STATUS:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tpout_status, (void __user *)arg, sizeof(TP_IOC_GET_TPOUT_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_TPOUT_STATUS, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetTpoutStatus(param_tpout_status.tpout_id, &param_tpout_status.tpout_status);

                        if (copy_to_user((void __user *)arg, &param_tpout_status, sizeof(TP_IOC_GET_TPOUT_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_TPOUT_STATUS, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                case TP_IOC_SET_TPOUT_CLK:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tpout_clk, (void __user *)arg, sizeof(TP_IOC_SET_TPOUT_CLK_T))) {
                                TP_WARNING("TP_IOC_SET_TPOUT_CLK, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPOUTClockSpeed(param_tpout_clk.tpout_id, param_tpout_clk.pre_div, param_tpout_clk.post_div);
                        break;


                        /* MTP APIs */
                case TP_IOC_SET_MTP_BUFF:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_mtp_set_buff, (void __user *)arg, sizeof(TP_IOC_SET_MTP_BUFF_T))) {
                                TP_WARNING("TP_IOC_SET_MTP_BUFF, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_SetMTPBuffer(param_mtp_set_buff.mtp_id, param_mtp_set_buff.pPhyAddr,
                                                (UINT8*)pli_to_kernel_ex((unsigned long)param_mtp_set_buff.pVirAddr), param_mtp_set_buff.size);
                        break;

                case TP_IOC_WRITE_MTP_BUFF:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_mtp_wrt_buff, (void __user *)arg, sizeof(TP_IOC_WRITE_MTP_BUFF_T))) {
                                TP_WARNING("TP_IOC_WRITE_MTP_BUFF, copy parameter from user space failed\n");
                                return -EFAULT;
                        }
                        ret = RHAL_WriteMTPBuffer(param_mtp_wrt_buff.mtp_id, param_mtp_wrt_buff.pPhyWP, param_mtp_wrt_buff.ContinueWrite);
                        break;

                case TP_IOC_GET_MTP_BUF_STATUS:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_mtp_buff_status, (void __user *)arg, sizeof(TP_IOC_GET_MTP_BUF_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_MTP_BUF_STATUS, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetMTPBufferStatus(param_mtp_buff_status.mtp_id, &param_mtp_buff_status.pWritePtr,
                                                      &param_mtp_buff_status.ContinueWriteSize, &param_mtp_buff_status.WritableSize);

                        if (copy_to_user((void __user *)arg, &param_mtp_buff_status, sizeof(TP_IOC_GET_MTP_BUF_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_MTP_BUF_STATUS, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                case TP_IOC_MTP_STREAM_CONTROL:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_mtp_strm_ctrl, (void __user *)arg, sizeof(TP_IOC_MTP_STREAM_CONTROL_T))) {
                                TP_WARNING("TP_IOC_MTP_STREAM_CONTROL, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_MTPStreamControl(param_mtp_strm_ctrl.mtp_id, param_mtp_strm_ctrl.ctrl);
                        break;

                case TP_IOC_GET_MTP_STATUS:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_mtp_status, (void __user *)arg, sizeof(TP_IOC_GET_MTP_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_MTP_STATUS, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetMtpStatus(param_mtp_status.mtp_id, &param_mtp_status.mtp_status);

                        if (copy_to_user((void __user *)arg, &param_mtp_status, sizeof(TP_IOC_GET_MTP_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_MTP_STATUS, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                case TP_IOC_FLUSH_MTP:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_mtp_flush, (void __user *)arg, sizeof(TP_IOC_MTP_FLUSH_T))) {
                                TP_WARNING("TP_IOC_FLUSH_MTP, copy parameter from user space failed\n");
                                return -EFAULT;
                        }
                        ret = RHAL_MTPFlushBuffer(param_mtp_flush.mtp_id, param_mtp_flush.mode);
                        break;

                        /* FRC APIs */
                case TP_IOC_FRC_ENABLE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_frc_enable, (void __user *)arg, sizeof(TP_IOC_FRC_ENABLE_T))) {
                                TP_WARNING("TP_IOC_FRC_ENABLE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }
                        ret = Tp_FRC_Enable(param_frc_enable.tp_id, param_frc_enable.enable);
                        break;

                case TP_IOC_FRC_SET_RATE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_frc_rate, (void __user *)arg, sizeof(TP_IOC_FRC_SET_RATE_T))) {
                                TP_WARNING("TP_IOC_FRC_SET_RATE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = Tp_FRC_SetRate(param_frc_rate.tp_id, param_frc_rate.rate);
                        break;
                case TP_IOC_FRC_SET_PREFIX:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_frc_prefix, (void __user *)arg, sizeof(TP_IOC_FRC_SET_PREFIX_T))) {
                                TP_WARNING("TP_IOC_FRC_SET_PREFIX, copy parameter from user space failed\n");
                                return -EFAULT;
                        }
                        ret = Tp_FRC_SetPrefix(param_frc_prefix.tp_id, param_frc_prefix.prefix_sel, param_frc_prefix.meta_data);
                        break;
                        /* PID filter */
                case TP_IOC_ADD_PID_FILTER:
                        /*  copy parameter from user space */
                        if (copy_from_user(&param_pid_add_filter, (void __user *)arg, sizeof(TP_IOC_ADD_PID_FILTER_T))) {
                                TP_WARNING("TP_IOC_ADD_PID_FILTER, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_AddPIDFilter(param_pid_add_filter.tp_id, param_pid_add_filter.PIDParm, (void *)file);
                        break;

                case TP_IOC_REMOVE_PID_FILTER:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_pid_rmv_filter, (void __user *)arg, sizeof(TP_IOC_REMOVE_PID_FILTER_T))) {
                                TP_WARNING("TP_IOC_REMOVE_PID_FILTER, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_RemovePIDFilter(param_pid_rmv_filter.tp_id, param_pid_rmv_filter.PID, (void *)file);
                        break;

                case TP_IOC_REMOVE_ALL_PID:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_pid_rmv_all, (void __user *)arg, sizeof(TP_IOC_REMOVE_ALL_PID_T))) {
                                TP_WARNING("TP_IOC_REMOVE_ALL_PID, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_RemoveAllPIDFilters(param_pid_rmv_all.tp_id, (void *)file);
                        break;

                case TP_IOC_GET_PID_STATUS:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_pid_get_staus, (void __user *)arg, sizeof(TP_IOC_GET_PID_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_PID_STATUS, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetPIDFilterStatus(param_pid_get_staus.tp_id, param_pid_get_staus.PID_Buf_Cnt,
                                                      &param_pid_get_staus.PIDParm[0], &param_pid_get_staus.PIDLen);

                        if (copy_to_user((void __user *)arg, &param_pid_get_staus, sizeof(TP_IOC_GET_PID_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_PID_STATUS, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;
                case TP_IOC_SET_PIDEN:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_set_piden, (void __user *)arg, sizeof(TP_IOC_SET_PIDEN_T))) {
                                TP_WARNING("TP_IOC_SET_PIDEN, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_EnablePIDFilter(param_set_piden.tp_id, param_set_piden.pid_en);

                        break;

                        /* Section filter */
                case TP_IOC_ADD_SECTION_FILTER:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_sec_add_filter, (void __user *)arg, sizeof(TP_IOC_ADD_SECTION_FILTER_T))) {
                                TP_WARNING("TP_IOC_ADD_SECTION_FILTER, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = TPVerify_AddSectionFilter(param_sec_add_filter.tp_id, param_sec_add_filter.Param,
                                                        (void *)file, &param_sec_add_filter.pSec_handle);

                        if (copy_to_user((void __user *)arg, &param_sec_add_filter, sizeof(TP_IOC_ADD_SECTION_FILTER_T))) {
                                TP_WARNING("TP_IOC_ADD_SECTION_FILTER, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;


                case TP_IOC_REMOVE_SECTION_FILTER:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_sec_rmv_filter, (void __user *)arg, sizeof(TP_IOC_REMOVE_SECTION_FILTER_T))) {
                                TP_WARNING("TP_IOC_REMOVE_SECTION_FILTER, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_RemoveSectionFilter(param_sec_rmv_filter.tp_id, param_sec_rmv_filter.pSec_handle);
                        break;

                case TP_IOC_REMOVE_ALL_SECTION:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_sec_rmv_all, (void __user *)arg, sizeof(TP_IOC_REMOVE_ALL_SECTION_T))) {
                                TP_WARNING("TP_IOC_REMOVE_ALL_SECTION, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_RemoveAllSectionFilters(param_sec_rmv_all.tp_id, (void *)file);
                        break;

                case TP_IOC_GET_SECTION_STATUS:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_sec_get_staus, (void __user *)arg, sizeof(TP_IOC_GET_SECTION_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_SECTION_STATUS, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetSectionFilterStatus(param_sec_get_staus.tp_id, param_sec_get_staus.Sec_Buf_cnt,
                                                          &param_sec_get_staus.SecStatus[0], &param_sec_get_staus.usSecLen);

                        if (copy_to_user((void __user *)arg, &param_sec_get_staus, sizeof(TP_IOC_GET_SECTION_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_SECTION_STATUS, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;
                case TP_IOC_GET_SECTION_DATA:
                        /* copy parameter from user space */
                        /* if (copy_from_user(&param_sec_get_data, (void __user *)arg, sizeof(TP_IOC_GET_SECTION_DATA_T))) */
                        /* { */
                        /* TP_WARNING("TP_IOC_GET_SECTION_DATA, copy parameter from user space failed\n"); */
                        /* return -EFAULT; */
                        /* } */

                        ret = TPVerify_GetSectionData(&param_sec_get_data.bIsNew, &param_sec_get_data.Sec, &param_sec_get_data.aBuf, &param_sec_get_data.handleId);

                        if (copy_to_user((void __user *)arg, &param_sec_get_data, sizeof(TP_IOC_GET_SECTION_DATA_T))) {
                                TP_WARNING("TP_IOC_GET_SECTION_DATA, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                        /* PCR tracking */
                case TP_IOC_PCR_TRACKING_EN:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_pcr_track_en, (void __user *)arg, sizeof(TP_IOC_PCR_TRACKING_EN_T))) {
                                TP_WARNING("TP_IOC_PCR_TRACKING_EN, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_PCRTrackingEnable(param_pcr_track_en.tp_id, param_pcr_track_en.On,
                                                     param_pcr_track_en.PID, param_pcr_track_en.clk_src);
                        break;

                case TP_IOC_GET_PCR_TRACKING:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_pcr_track_get, (void __user *)arg, sizeof(TP_IOC_GET_PCR_TRACKING_T))) {
                                TP_WARNING("TP_IOC_GET_PCR_TRACKING, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetPCRTrackingStatus(param_pcr_track_get.tp_id, &param_pcr_track_get.PCR,
                                                        &param_pcr_track_get.STC, &param_pcr_track_get.PCRBase,
                                                        &param_pcr_track_get.STCBase);

                        if (copy_to_user((void __user *)arg, &param_pcr_track_get, sizeof(TP_IOC_GET_PCR_TRACKING_T))) {
                                TP_WARNING("TP_IOC_GET_PCR_TRACKING, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                case TP_IOC_RESET_PCR_TRACKING:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_pcr_track_rst, (void __user *)arg, sizeof(TP_IOC_RESET_PCR_TRACKING_T))) {
                                TP_WARNING("TP_IOC_RESET_PCR_TRACKING, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_ResetPCRTrackingStatus(param_pcr_track_rst.tp_id);
                        break;

                        /* Descrambler APIs */
                case TP_IOC_DESCRAMBLE_ALGORITHM:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_dsc_alg, (void __user *)arg, sizeof(TP_IOC_DESCRAMBLE_ALGORITHM_T))) {
                                TP_WARNING("TP_IOC_DESCRAMBLE_ALGORITHM, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_SetDescrambleAlgorithm(param_dsc_alg.tp_id, param_dsc_alg.algo);
                        break;

                case TP_IOC_SET_CW:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_set_cw, (void __user *)arg, sizeof(TP_IOC_SET_CW_T))) {
                                TP_WARNING("TP_IOC_SET_CW, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_SetCW(param_set_cw.tp_id, param_set_cw.key_set, param_set_cw.key_id,
                                         param_set_cw.Key, param_set_cw.IV);
                        break;

                case TP_IOC_DESCRAMBLE_CONTROL:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_dsc_ctrl, (void __user *)arg, sizeof(TP_IOC_DESCRAMBLE_CONTROL_T))) {
                                TP_WARNING("TP_IOC_DESCRAMBLE_CONTROL, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_DescrambleControl(param_dsc_ctrl.tp_id, param_dsc_ctrl.mode);
                        break;

                case TP_IOC_SET_ENCRYPTION:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_encryption, (void __user *)arg, sizeof(TP_IOC_SET_ENCRYPTION_T))) {
                                TP_WARNING("TP_IOC_SET_ENCRYPTION, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = Tp_SetPIDEncryption(param_encryption.tp_id, param_encryption.PID, param_encryption.keytype);

                        break;
                        /* Start Code APIs */
                case TP_IOC_STARTCODE_ENABLE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_sc_enable, (void __user *)arg, sizeof(TP_IOC_STARTCODE_ENABLE_T))) {
                                TP_WARNING("TP_IOC_STARTCODE_ENABLE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = Tp_SetPatternSearchEnable(param_sc_enable.tp_id, param_sc_enable.enable);

                        break;

                case TP_IOC_STARTCODE_SET_PID:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_sc_set_pid, (void __user *)arg, sizeof(TP_IOC_STARTCODE_SET_PID_T))) {
                                TP_WARNING("TP_IOC_STARTCODE_SET_PID, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_SetTPPatternSearchPID(param_sc_set_pid.tp_id, param_sc_set_pid.PID);

                        break;
                case TP_IOC_STARTCODE_SET_BUFFER:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_sc_set_buf, (void __user *)arg, sizeof(TP_IOC_STARTCODE_SET_BUFFER_T))) {
                                TP_WARNING("TP_IOC_SET_ENCRYPTION, copy parameter from user space failed\n");
                                return -EFAULT;
                        }
                        //TP_DBG("TP_IOC_SET_ENCRYPTION  tp_id=%d, PID=%x ,keytype=%d \n", param_sc_set_buf.tp_id, param_sc_set_buf.PID);

                        UINT8* pVirAddr = (UINT8*)pli_to_kernel_ex((unsigned long)param_sc_set_buf.pVirAddr);

                        ret = RHAL_SetTPPatternSearchInfoBuffer(param_sc_set_buf.tp_id, param_sc_set_buf.pPhyAddr, pVirAddr , param_sc_set_buf.size, pVirAddr, pVirAddr);



                        break;
                case TP_IOC_STARTCODE_FLUSH:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_sc_flush, (void __user *)arg, sizeof(TP_IOC_BASIC_T))) {
                                TP_WARNING("TP_IOC_STARTCODE_FLUSH, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = Tp_FlushPatternSearch(param_sc_flush.tp_id);

                        break;
                case TP_IOC_STARTCODE_READ_INFO:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_sc_read, (void __user *)arg, sizeof(TP_IOC_STARTCODE_READ_INFO_T))) {
                                TP_WARNING("TP_IOC_STARTCODE_READ_INFO, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = TPVerify_ReadStartCodeInfo(param_sc_read.tp_id, &param_sc_read.pReadPhyPtr, &param_sc_read.ContinueReadSize);

                        if (copy_to_user((void __user *)arg, &param_sc_read, sizeof(TP_IOC_STARTCODE_READ_INFO_T))) {
                                TP_WARNING("TP_IOC_STARTCODE_READ_INFO, copy parameter to user space failed\n");
                                return -EFAULT;
                        }

                        break;
                case TP_IOC_STARTCODE_RELEASE_INFO:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_sc_relase, (void __user *)arg, sizeof(TP_IOC_STARTCODE_RELEASE_INFO_T))) {
                                TP_WARNING("TP_IOC_STARTCODE_RELEASE_INFO, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = TPVerify_ReleaseStartCodeInfo(param_sc_relase.tp_id, param_sc_relase.pReadPhyPtr, param_sc_relase.Size);

                        break;

                        /* CI PLUS APIs */

                case TP_IOC_TPP_SET_MODE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_set_mode, (void __user *)arg, sizeof(TP_IOC_TPP_MODE_T))) {
                                TP_WARNING("TP_IOC_TPP_SET_MODE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_SetTPPMode(param_set_mode.tp_p_id, param_set_mode.param);

                        break;
                case TP_IOC_TPP_GET_MODE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_get_mode, (void __user *)arg, sizeof(TP_IOC_TPP_MODE_T))) {
                                TP_WARNING("TP_IOC_TPP_GET_MODE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetTPPMode(param_get_mode.tp_p_id, &param_get_mode.param);
                        if (copy_to_user((void __user *)arg, &param_get_mode, sizeof(TP_IOC_TPP_MODE_T))) {
                                TP_WARNING("TP_IOC_TPP_GET_MODE, copy parameter to user space failed\n");
                                return -EFAULT;
                        }

                        break;

                case TP_IOC_TPP_SET_PIDEN:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tpp_set_piden, (void __user *)arg, sizeof(TP_IOC_TPP_SET_PIDEN_T))) {
                                TP_WARNING("TP_IOC_TPP_SET_PIDEN, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_EnableTPPPIDFilter(param_tpp_set_piden.tp_p_id, param_tpp_set_piden.pid_en);

                        break;
                case TP_IOC_TPP_STREAM_CONTROL:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tpp_strm_ctrl, (void __user *)arg, sizeof(TP_IOC_TPP_STREAM_CONTROL_T))) {
                                TP_WARNING("TP_IOC_TPP_STREAM_CONTROL, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPPStreamControl(param_tpp_strm_ctrl.tp_p_id, param_tpp_strm_ctrl.ctrl);

                        break;
                case TP_IOC_GET_TPP_BUF_STATUS:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tpp_buff_status, (void __user *)arg, sizeof(TP_IOC_GET_TPP_BUF_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_TPP_BUF_STATUS, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetTPPBufferStatus(param_tpp_buff_status.tp_p_id, &param_tpp_buff_status.BufferSize, &param_tpp_buff_status.DataSize);

                        if (copy_to_user((void __user *)arg, &param_tpp_buff_status, sizeof(TP_IOC_GET_TPP_BUF_STATUS_T))) {
                                TP_WARNING("TP_IOC_GET_TPP_BUF_STATUS, copy parameter to user space failed\n");
                                return -EFAULT;
                        }

                        break;
                case TP_IOC_TPP_RINGBUFF_FLUSH:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tpp_flush, (void __user *)arg, sizeof(TP_IOC_TPP_BASIC_T))) {
                                TP_WARNING("TP_IOC_TPP_FLUSH, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TPPFlushBuffer(param_tpp_flush.tp_p_id);

                        break;
                case TP_IOC_SET_TPP_SYNC_REPLACE:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_tpp_sync_replace, (void __user *)arg, sizeof(TP_IOC_SET_TPP_SYNC_REPLACE_T))) {
                                TP_WARNING("TP_IOC_SET_TPP_SYNC_REPLACE, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = Tp_TPP_SetSyncReplace(param_tpp_sync_replace.tp_p_id, param_tpp_sync_replace.sync_replace);

                        break;

                        /* get debug message */
                case TP_IOC_TRACK_ERR_PACKET:
                        /* copy parameter from user space */
                        if (copy_from_user(&param_track_err_pkt, (void __user *)arg, sizeof(TP_IOC_TRACK_ERR_PACKET_T))) {
                                TP_WARNING("TP_IOC_TRACK_ERR_PACKET, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_TrackErrorPacket(param_track_err_pkt.tp_id, &param_track_err_pkt.ErrPkt,
                                                    &param_track_err_pkt.RevPkt, &param_track_err_pkt.DropPkt);

                        if (copy_to_user((void __user *)arg, &param_track_err_pkt, sizeof(TP_IOC_TRACK_ERR_PACKET_T))) {
                                TP_WARNING("TP_IOC_TRACK_ERR_PACKET, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;

                case TP_IOC_GET_HARDWARE_INFO:
                        /*  copy parameter from user space */
                        if (copy_from_user(&param_hardware_info, (void __user *)arg, sizeof(TPK_HARDWARE_INFO_T))) {
                                TP_WARNING("TP_IOC_GET_HARDWARE_INFO, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = RHAL_GetHardwareInfo(&param_hardware_info);

                        if (copy_to_user((void __user *)arg, &param_hardware_info, sizeof(TPK_HARDWARE_INFO_T))) {
                                TP_WARNING("TP_IOC_GET_HARDWARE_INFO, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;
                case TP_IOC_READ_WRITE_REG:
                        /* copy parameter from user space */
                        if (copy_from_user(&Reg_rw_Parm, (void __user *)arg, sizeof(TP_REG_RW_T))) {
                                TP_WARNING("TP_IOC_READ_WRITE_REG, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = tp_reg_rw(&Reg_rw_Parm);
                        if (copy_to_user((void __user *)arg, &Reg_rw_Parm, sizeof(TP_REG_RW_T))) {
                                TP_WARNING("TP_IOC_READ_WRITE_REG, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;
                case TP_IOC_DUMP_REG_INFO:
                        /*  copy parameter from user space */
                        if (copy_from_user(&param_dump_reg_info, (void __user *)arg, sizeof(TPK_DUMP_REG_INFO_T))) {
                                TP_WARNING("TP_IOC_DUMP_REG_INFO, copy parameter from user space failed\n");
                                return -EFAULT;
                        }

                        ret = TPVerify_DumpTPRegister(&param_dump_reg_info);

                        if (copy_to_user((void __user *)arg, &param_dump_reg_info, sizeof(TPK_DUMP_REG_INFO_T))) {
                                TP_WARNING("TP_IOC_DUMP_REG_INFO, copy parameter to user space failed\n");
                                return -EFAULT;
                        }
                        break;


                default:
                        TP_WARNING("invalid command - 0x%x\n", cmd);
                        return -ENOTTY;
        }

        return (long)ret;
}

//#define BINOUT_SAVETO_FILE

typedef struct {
        TPK_DESCRAMBLE_MODE_T         Mode;                   // Descramble Mode
        TPK_DESCRAMBLE_ALGORITHM_ID_T AlgoId;                 // Descramble Algorithm
        unsigned int                  Round;                  // Round for Multi2 only
        unsigned char                 nPID;                   // Number of PIDs
        unsigned short                PIDs[16];               // Number of PID
        unsigned char                 Key[3][64];             // Scramble Key
        unsigned char                 IV[2][16];              // Scramble IV
        char*                         InputFilePath;          // File Path of the input pattern
        char*                         OutputFilePath;          // File Path of the input pattern
        char*                         RefenceFilePath;        // File Path of the output pattern
        char*                         Name;
} DESCRAMBLER_TEST_ITEM;


DESCRAMBLER_TEST_ITEM DescTest_Des_Ecb_TerminateInClear = {
        TPK_TSP_LEVEL_DESCRAMBLE,          // mode
        TPK_DESCRAMBLE_ALGO_DES_ECB_CLEAR, // Algo
        0,                                 // Round
        4,                                 // nPID
        {0, 16, 18, 19},                   // PIDs
        {
                {0xfe, 0xe5, 0xc0, 0x2f, 0x84, 0x9a, 0x3e},     // even Key
                {0x1c, 0x7b, 0x67, 0x58, 0xa7, 0xd1, 0x07},     // odd Key
                {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}      // system key (multi2 only)
        },
        {
                {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},     // even iv
                {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},     // odd iv
        },
        "test_stream/BinIn/des_ecb_tsp1_enc.ts",    // File Path of the input pattern
        "test_stream/BinOut/des_ecb_tsp1_dec.ts",
        "test_stream/BinRef/tsp1_ref.ts",
        "56 bits DES ECB (for CI+) Terminate in Clear"
};


DESCRAMBLER_TEST_ITEM DescTest_TDES_ECB = {
        TPK_TSP_LEVEL_DESCRAMBLE,           // mode
        TPK_DESCRAMBLE_ALGO_TDES_ECB_CLEAR, // Algo
        0,                                  // Round
        4,                                  // nPID
        {0, 16, 18, 19},                    // PIDs
        {

                {
                        0xfe, 0xe5, 0xc0, 0x2f, 0x84, 0x9a, 0x3e,
                        0x32, 0xd4, 0xda, 0x74, 0x02, 0xb4, 0xec,
                        0xa6, 0x1c, 0x7b, 0x67, 0x58, 0xa7, 0xd1
                },     // even Key

                {
                        0x24, 0x45, 0xc6, 0x07, 0x3a, 0x31, 0x4a,
                        0xea, 0x1c, 0x7b, 0x67, 0x58, 0xa7, 0xd1,
                        0x07, 0x32, 0xd4, 0xda, 0x74, 0x02, 0xb4
                },     // odd  key

                {0x00}
        },
        {
                {0x00},     // even iv
                {0x00},     // odd iv
        },
        "test_stream/BinIn/tdes_ecb_tsp1_enc.ts",    // File Path of the input pattern
        "test_stream/BinOut/tdes_ecb_tsp1_dec.ts",
        "test_stream/BinRef/tsp1_ref.ts",
        "TDES_ECB descramble test"
};


DESCRAMBLER_TEST_ITEM DescTest_TDES_CBC = {
        TPK_TSP_LEVEL_DESCRAMBLE,         // mode
        TPK_DESCRAMBLE_ALGO_TDES_CBC_OFB, // Algo
        0,                                // Round
        4,                                // nPID
        {0, 16, 18, 19},                  // PIDs
        {

                {
                        0xfe, 0xe5, 0xc0, 0x2f, 0x84, 0x9a, 0x3e,
                        0x32, 0xd4, 0xda, 0x74, 0x02, 0xb4, 0xec,
                        0xa6, 0x1c, 0x7b, 0x67, 0x58, 0xa7, 0xd1
                },     // even Key

                {
                        0x24, 0x45, 0xc6, 0x07, 0x3a, 0x31, 0x4a,
                        0xea, 0x1c, 0x7b, 0x67, 0x58, 0xa7, 0xd1,
                        0x07, 0x32, 0xd4, 0xda, 0x74, 0x02, 0xb4
                },     // odd  key

                {0x00}
        },
        {
                {0x32, 0xd4, 0xda, 0x74, 0x02, 0xb4, 0xec, 0xa6},     // even iv
                {0x24, 0x45, 0xc6, 0x07, 0x3a, 0x31, 0x4a, 0xea},     // odd iv
        },
        "test_stream/BinIn/tdes_cbc_tsp1_enc.ts",    // File Path of the input pattern
        "test_stream/BinOut/tdes_cbc_tsp1_dec.ts",
        "test_stream/BinRef/tsp1_ref.ts",
        "TDES CBC descramble test"
};


DESCRAMBLER_TEST_ITEM DescTest_AES_CBC_KeepClear = {
        TPK_TSP_LEVEL_DESCRAMBLE,              // mode
        TPK_DESCRAMBLE_ALGO_AES_128_CBC_CLEAR, // Algo
        0,                                     // Round
        4,                                     // nPID
        {0, 16, 18, 19},                       // PIDs
        {

                {
                        0xfe, 0xe5, 0xc0, 0x2f, 0x84, 0x9a, 0x3e, 0x0d,
                        0x32, 0xd4, 0xda, 0x74, 0x02, 0xb4, 0xec, 0xa6
                },     // even Key
                {
                        0x1c, 0x7b, 0x67, 0x58, 0xa7, 0xd1, 0x07, 0xc2,
                        0x24, 0x45, 0xc6, 0x07, 0x3a, 0x31, 0x4a, 0xea
                },     // odd  key
                {0x00}
        },
        {
                {
                        0x04, 0xe1, 0x7c, 0x76, 0x5e, 0x76, 0x68, 0xbb,
                        0xf2, 0x31, 0x98, 0x6c, 0x38, 0x29, 0xbe, 0x9f
                },     // even iv
                {
                        0x04, 0xe1, 0x7c, 0x76, 0x5e, 0x76, 0x68, 0xbb,
                        0xf2, 0x31, 0x98, 0x6c, 0x38, 0x29, 0xbe, 0x9f
                },     // iv iv
        },
        "test_stream/BinIn/aes_cbc_tsp1_enc.ts",    // File Path of the input pattern
        "test_stream/BinOut/aes_cbc_tsp1_dec.ts",
        "test_stream/BinRef/tsp1_ref.ts",
        "AES CBC (Keep Clear) descramble test"
};



DESCRAMBLER_TEST_ITEM DescTest_AES_CBC_OFB = {
        TPK_TSP_LEVEL_DESCRAMBLE,            // mode
        TPK_DESCRAMBLE_ALGO_AES_128_CBC_OFB, // Algo
        0,                                   // Round
        4,                                   // nPID
        {0, 16, 18, 19},                     // PIDs
        {

                {
                        0xfe, 0xe5, 0xc0, 0x2f, 0x84, 0x9a, 0x3e, 0x0d,
                        0x32, 0xd4, 0xda, 0x74, 0x02, 0xb4, 0xec, 0xa6
                },     // even Key
                {
                        0x1c, 0x7b, 0x67, 0x58, 0xa7, 0xd1, 0x07, 0xc2,
                        0x24, 0x45, 0xc6, 0x07, 0x3a, 0x31, 0x4a, 0xea
                },     // odd  key
                {0x00}
        },
        {
                {
                        0x04, 0xe1, 0x7c, 0x76, 0x5e, 0x76, 0x68, 0xbb,
                        0xf2, 0x31, 0x98, 0x6c, 0x38, 0x29, 0xbe, 0x9f
                },     // even iv
                {
                        0x04, 0xe1, 0x7c, 0x76, 0x5e, 0x76, 0x68, 0xbb,
                        0xf2, 0x31, 0x98, 0x6c, 0x38, 0x29, 0xbe, 0x9f
                },     // iv iv
        },
        "test_stream/BinIn/aes_cbc_cts_tsp1_enc.ts",    // File Path of the input pattern
        "test_stream/BinOut/aes_cbc_cts_tsp1_dec.ts",
        "test_stream/BinRef/tsp1_ref.ts",
        "AES CBC (OFB) descramble test"
};


DESCRAMBLER_TEST_ITEM DescTest_CSA2 = {
        TPK_TSP_LEVEL_DESCRAMBLE,    // mode
        TPK_DESCRAMBLE_ALGO_CSA_RAW, // Algo
        0,                           // Round
        5,                           // nPID
        {0, 17, 312, 4384, 4386},    // PIDs
        {
                {0xbe, 0x2b, 0x15, 0xfe, 0xff, 0x0c, 0x61, 0x6c},     // even Key
                {0x83, 0xb4, 0xa2, 0xd9, 0x9f, 0x4a, 0xee, 0xd7},     // odd Key
                {0x00}      // system key (multi2 only)
        },
        {
                {0x00},     // even iv
                {0x00},     // odd iv
        },
        "test_stream/BinIn/csa_enc.ts",    // File Path of the input pattern
        "test_stream/BinOut/csa_dec.ts",
        "test_stream/BinRef/csa_ref.ts",
        "CSA2 Descramble test"
};



DESCRAMBLER_TEST_ITEM DescTest_Multi2 = {
        TPK_TSP_LEVEL_DESCRAMBLE,       // mode
        TPK_DESCRAMBLE_ALGO_MULTI2_OFB, // Algo
        128,                            // Round
        4,                              // nPID
        {0, 16, 18, 19},                // PIDs
        {

                {0xa5, 0x5c, 0xc6, 0xb5, 0x98, 0x72, 0x42, 0xff},     // even Key

                {0x4c, 0x7b, 0xef, 0x02, 0x97, 0xf7, 0xbb, 0x78},     // odd  key

                {
                        0x36, 0x31, 0x04, 0x66, 0x4b, 0x17, 0xea, 0x5c,
                        0x32, 0xdf, 0x9c, 0xf5, 0xc4, 0xc3, 0x6c, 0x1b,
                        0xec, 0x99, 0x39, 0x21, 0x68, 0x9d, 0x4b, 0xb7,
                        0xb7, 0x4e, 0x40, 0x84, 0x0d, 0x2e, 0x7d, 0x98
                }      // system key (multi2 only)
        },
        {
                {0xfe, 0x27, 0x19, 0x99, 0x19, 0x69, 0x09, 0x11},     // even iv
                {0xfe, 0x27, 0x19, 0x99, 0x19, 0x69, 0x09, 0x11},     // odd iv
        },
        "test_stream/BinIn/multi2_tsp1_enc.ts",    // File Path of the input pattern
        "test_stream/BinOut/multi2_tsp1_dec.ts",
        "test_stream/BinRef/multi2_tsp1_ref.ts",
        "Multi2 Descramble test"
};

DESCRAMBLER_TEST_ITEM* g_desc_test_list[] = {
        &DescTest_Des_Ecb_TerminateInClear,
        &DescTest_TDES_ECB,
        &DescTest_TDES_CBC,
        &DescTest_AES_CBC_KeepClear,
        &DescTest_AES_CBC_OFB,
        &DescTest_CSA2,
        &DescTest_Multi2,
};

typedef enum {
        TEST_SUCCESSED = 0,
        TEST_FAILED = -1,
} FUNC_TEST_STATUS;

//#define BIN_IN_FILE "test_stream/BinIn/des_ecb_tsp1_enc.ts"
//#define BIN_REF_FILE "test_stream/BinRef/tsp1_ref.ts"
//#define BIN_OUT_FILE "test_stream/BinOut/tsp1_ref.ts"

#define TS_RING_BUFFER_SIZE       (188 * 1024 * 50)
#define BIN_REF_BUFFER_SIZE       (188 * 1000)


#define MAX_DTV_FRONTEND_NUM        (2)
#define MAX_DESC_TEST_NUMBER    (sizeof(g_desc_test_list) / sizeof(DESCRAMBLER_TEST_ITEM*))

int TPVerify_RunDescTestEx2(IN TPK_TP_ENGINE_T tp_id, DESCRAMBLER_TEST_ITEM* pTest, char* pattern_path)
{
        UINT32 pbuff_phy = 0;
        UINT8 *pbuff;
        UINT8 *pbuff_noncache;
        TPK_TP_STATUS_T tpStatus;
        TPK_PID_FILTER_PARAM_T  PIDParm;
        TPK_DESCRAMBLE_ALGORITHM_T alg;
        UINT8 pid_index;
        UINT16 i;
        UINT8 *mtp_buffer_physical;
        UINT8 *mtp_buffer_virtual;
        UINT32 mtp_pContinueWriteSize;
        UINT32 mtp_pWritableSize;
        UINT32 TpBufferSize;
        UINT32 TpDataSize;
        UINT8 *tp_buffer;
        UINT32 tp_pContinueReadSize;
        UINT32 mtp_write_data_index;
        unsigned char  *RefIn_tmp = NULL;
        UINT8 *tp_buffer_base_phy;
        UINT8 *tp_buffer_base_virtual;
        UINT8 *mtp_buffer_base_phy;
        UINT8 *mtp_buffer_base_virtual;
        UINT8 filepath[256];


        UINT8 *tp_buffer_virtual;

        mm_segment_t old_fs;
        struct file *BinInfile = NULL;
        struct file *BinReffile = NULL;
#ifdef BINOUT_SAVETO_FILE
        struct file *BinOutfile = NULL;
#endif

        int err = 0;
        int ret = -1;

        RHAL_TPInit(tp_id);

        sprintf(filepath, "%s%s", pattern_path, pTest->InputFilePath);
        BinInfile = filp_open(filepath, O_RDONLY, 0);
        TP_DBG_SIMPLE("BinInfile=0x%x\n", BinInfile);
        if (IS_ERR(BinInfile)) {
                TP_ERROR("error occured while opening file %s\n", filepath);
                return -1;
        }

        sprintf(filepath, "%s%s", pattern_path, pTest->RefenceFilePath);
        BinReffile = filp_open(filepath, O_RDONLY, 0);
        TP_DBG_SIMPLE("BinReffile=0x%x\n", BinReffile);
        if (IS_ERR(BinReffile)) {
                TP_ERROR("error occured while opening file %s\n", filepath);
                return -1;
        }
#ifdef BINOUT_SAVETO_FILE
        sprintf(filepath, "%s%s", pattern_path, pTest->OutputFilePath);
        BinOutfile = filp_open(filepath, O_RDWR | O_CREAT | O_TRUNC, 0777);
        TP_DBG_SIMPLE("BinOutfile=0x%x\n", BinOutfile);
        if (IS_ERR(BinOutfile)) {
                TP_ERROR("error occured while opening file %s\n", filepath);
                return -1;
        }
#endif

        RefIn_tmp =  kmalloc(BIN_REF_BUFFER_SIZE, GFP_KERNEL);
        if(RefIn_tmp == NULL) {
                TP_ERROR("can not malloc memory for ref file\n");
                return -1;
        }

        pbuff = (UINT8 **)dvr_malloc_uncached_specific(TS_RING_BUFFER_SIZE * 2, GFP_DCU1_FIRST, (void **)&pbuff_noncache);

        if (NULL != pbuff) {
                /* check phy secBuff */
                pbuff_phy = dvr_to_phys((void*)pbuff);
                if ( pbuff_phy == 0 ) {
                        TP_ERROR( "error, virt addr to phy addr fail\n" );
                        return TPK_NOT_ENOUGH_RESOURCE;
                }
#ifdef CONFIG_LG_SNAPSHOT_BOOT
                register_cma_forbidden_region(__phys_to_pfn(pbuff_phy), TS_RING_BUFFER_SIZE * 2);
#endif
                //memset((void*)pbuff, 0, TS_RING_BUFFER_SIZE * 2);
                memset((void*)pbuff_noncache, 0, TS_RING_BUFFER_SIZE * 2);

                RHAL_SetTPRingBuffer(tp_id, pbuff_phy, pbuff, TS_RING_BUFFER_SIZE);
                RHAL_SetMTPBuffer(tp_id, pbuff_phy + TS_RING_BUFFER_SIZE, pbuff + TS_RING_BUFFER_SIZE, TS_RING_BUFFER_SIZE);
                RHAL_MTPFlushBuffer(tp_id, MTP_BUFF_FLUSH_TO_BASE);
                RHAL_GetTpStatus(tp_id, &tpStatus);

                tpStatus.tp_param.sync_byte                             = 0x47 ;
                tpStatus.tp_param.ts_in_tsp_len                         = byte_188 ;
                tpStatus.tp_param.clr_tsp_scrmbl_bit            = 0x1 ;
                tpStatus.tp_param.pid_filter_en                         = 0x1 ;
                RHAL_SetTPMode(tp_id, tpStatus.tp_param);
                RHAL_SetTPSource(tp_id, MTP , TPK_WITHOUT_CAS);

                alg.algo = pTest->AlgoId;
                if (alg.algo == TPK_DESCRAMBLE_ALGO_MULTI2_OFB)
                        alg.round = pTest->Round;
                else
                        alg.round = 0;
                RHAL_SetDescrambleAlgorithm(tp_id, alg);
                RHAL_DescrambleControl(tp_id, pTest->Mode);

                RHAL_SetCW(tp_id, 0, TP_SETCW_KEYID_EVEN_KEY, pTest->Key[0], pTest->IV[0]);
                RHAL_SetCW(tp_id, 0, TP_SETCW_KEYID_ODD_KEY, pTest->Key[1], pTest->IV[1]);
                if (alg.algo == TPK_DESCRAMBLE_ALGO_MULTI2_OFB)
                        RHAL_SetCW(tp_id, 0, TP_SETCW_KEYID_MULTI2_SYS_KEY, pTest->Key[2], pTest->IV[0]);

                for(pid_index = 0; pid_index < pTest->nPID; pid_index++) {
                        PIDParm.DescrambleEn = 1;
                        PIDParm.KeySel           = 0;
                        PIDParm.PID              = pTest->PIDs[pid_index];
                        PIDParm.valid            = 1;
                        RHAL_AddPIDFilter(tp_id, PIDParm, 0xabc);
                }

                RHAL_TPStreamControl(tp_id, TP_STREAM_START);
                RHAL_MTPStreamControl(tp_id, MTP_STREAM_START);
                RHAL_GetMTPBufferStatus(tp_id, &mtp_buffer_physical, &mtp_pContinueWriteSize, &mtp_pWritableSize);

                mtp_buffer_virtual = (mtp_buffer_physical - pTp_drv->mtp[tp_id].mtp_buf_param.BasePhy) + pTp_drv->mtp[tp_id].mtp_buf_param.BaseVir;

                if (mtp_pContinueWriteSize > BIN_REF_BUFFER_SIZE)
                        mtp_pContinueWriteSize = BIN_REF_BUFFER_SIZE;

                old_fs = get_fs();
                set_fs(KERNEL_DS);
                vfs_read(BinReffile, RefIn_tmp, mtp_pContinueWriteSize, &BinReffile->f_pos);
                vfs_read(BinInfile, mtp_buffer_virtual, mtp_pContinueWriteSize, &BinInfile->f_pos);
                set_fs(old_fs);

                dmac_flush_range(mtp_buffer_virtual, mtp_buffer_virtual + mtp_pContinueWriteSize);
                outer_flush_range(mtp_buffer_physical, mtp_buffer_physical + mtp_pContinueWriteSize);

                RHAL_WriteMTPBuffer(tp_id, mtp_buffer_physical, mtp_pContinueWriteSize);

                RHAL_GetTPBufferStatus(tp_id, &TpBufferSize, &TpDataSize);

                for (i = 0; i < 6000; i++) {
                        if (RHAL_TPReadData(tp_id, &tp_buffer, &tp_pContinueReadSize, mtp_pContinueWriteSize) == TPK_SUCCESS)
                                break;
                }

                if(i >= 6000) {
                        TP_ERROR("ERROR!! Can not get data , over %d times\n", i);
                        err++;
                }

                tp_buffer_virtual = (tp_buffer - pTp_drv->tp[tp_id].mass_buffer.BasePhy) + pTp_drv->tp[tp_id].mass_buffer.BaseVir;

                dmac_flush_range(tp_buffer_virtual, tp_buffer_virtual + tp_pContinueReadSize);
                outer_flush_range(tp_buffer, tp_buffer + tp_pContinueReadSize);

#ifdef BINOUT_SAVETO_FILE
                old_fs = get_fs();
                set_fs(KERNEL_DS);
                vfs_write(BinOutfile, tp_buffer_virtual, tp_pContinueReadSize, &BinOutfile->f_pos);
                set_fs(old_fs);
#endif
                RHAL_TPReleaseData(tp_id, tp_buffer, tp_pContinueReadSize);

                if (memcmp(tp_buffer_virtual, RefIn_tmp, tp_pContinueReadSize)) {
                        err++;
                        TP_DBG_SIMPLE("X");
                        sprintf(pTp_drv->proc_read_message, "Test: NG\n");
                } else {
                        TP_DBG_SIMPLE("O");
                        sprintf(pTp_drv->proc_read_message, "Test: OK\n");
                }

                ret = (err) ? -1 : 0;

                if (ret < 0) {
                        TP_ERROR("\nRun Descramble Test - %s failed - data mismatch (proced_bytes=%d)\n", pTest->Name, tp_pContinueReadSize);
                } else {
                        TP_DBG_SIMPLE("\nRun Descramble Test - %s successed (proced_bytes=%d)\n", pTest->Name, tp_pContinueReadSize);
                }

                RHAL_MTPStreamControl(tp_id, MTP_STREAM_STOP);
                RHAL_TPStreamControl(tp_id, TP_STREAM_STOP);

                dvr_free(pbuff);

                filp_close(BinInfile, NULL);
                BinInfile = NULL;
                filp_close(BinReffile, NULL);
                BinReffile = NULL;
#ifdef BINOUT_SAVETO_FILE
                filp_close(BinOutfile, NULL);
                BinOutfile = NULL;
#endif
                if(RefIn_tmp != NULL) {
                        kfree(RefIn_tmp);
                        RefIn_tmp = NULL;
                }
        }
        return ret;
}

int TPVerify_FunctionalTestInit(void)
{
        return (MAX_DESC_TEST_NUMBER * MAX_DTV_FRONTEND_NUM);
        //return (MAX_DESC_TEST_NUMBER);
}


int TPVerify_FunctionalTestUninit(void)
{
        return 0;
}

int TPVerify_FunctionalTest(
        int                 test_id,
        FUNC_TEST_STATUS*   pStatus,
        char*               pattern_path
)
{
        int tp_id = test_id / MAX_DESC_TEST_NUMBER;
        int err = 0;

        if (test_id >= MAX_DESC_TEST_NUMBER * MAX_DTV_FRONTEND_NUM)
                return -1;

        TP_DBG_SIMPLE("\n\n");
        TP_DBG_SIMPLE("===============================================================================\n");
        TP_DBG_SIMPLE("= Run TP->CP Descramble Test [%d/%d] \n", test_id, MAX_DESC_TEST_NUMBER * MAX_DTV_FRONTEND_NUM - 1);
        TP_DBG_SIMPLE("===============================================================================\n");
        TP_DBG_SIMPLE("= TPID = %d, Algo=%s \n", tp_id, g_desc_test_list[test_id % MAX_DESC_TEST_NUMBER]->Name);
        TP_DBG_SIMPLE("===============================================================================\n");

        if (TPVerify_RunDescTestEx2(tp_id, g_desc_test_list[test_id % MAX_DESC_TEST_NUMBER], pattern_path) == 0) {
                *pStatus = TEST_SUCCESSED;
                TP_DBG_SIMPLE(">> Test[%d] Result : PASS\n", test_id);
        } else {
                *pStatus = TEST_FAILED;
                TP_DBG_SIMPLE(">> Test[%d] Result : FAILED\n", test_id);
        }
        TP_DBG_SIMPLE("===============================================================================\n");
        return 0;
}


void TPVerify_ModuleTest(char *pattern_path)
{
        int i;
        int test_cnt = TPVerify_FunctionalTestInit();
        FUNC_TEST_STATUS Status;
        int bRet = true;

        for ( i = 0; i < test_cnt; i++) {
                if (TPVerify_FunctionalTest(i, &Status, pattern_path) != 0) {
                        TP_DBG_SIMPLE("DTVTunerControlFunctionalTest(%d) not successfully performed!!\n", i);
                        TP_DBG_SIMPLE("DTVTunerControlFunctionalTest(%d) not successfully performed!!\n", i);
                        TP_DBG_SIMPLE("DTVTunerControlFunctionalTest(%d) not successfully performed!!\n", i);
                        continue;
                }

                if (Status != TEST_SUCCESSED) {
                        TP_DBG_SIMPLE("run_dtv_tuner_control_test %d failed\n", i);
                        bRet = false;
                        break ;
                } else {
                        bRet = true;
                }
        }

        TPVerify_FunctionalTestUninit();
}

