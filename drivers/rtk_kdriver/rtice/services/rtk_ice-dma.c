#include "rtk_ice-dma.h"
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h> //kmalloc
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/moduleparam.h>
#include "rtk_ice-dma_define.h"
/****************************************ip's sub count*******************************************/
static unsigned int SubsCountOfIP[DMA_STATUS_MAX_IP] = {\
    TVSB2_MAX_SUB_IP,\
    TVSB1_MAX_SUB_IP,\
    SB1_MAX_SUB_IP,\
    SB2_MAX_SUB_IP,\
    SB3_MAX_SUB_IP,\
    VE_MAX_SUB_IP,\
    VE2_MAX_SUB_IP,\
    TVSB3_MAX_SUB_IP,\
    GPU_MAX_SUB_IP,\
    TVSB5_MAX_SUB_IP,\
    SE2_MAX_SUB_IP,\
    TVSB4_MAX_SUB_IP                                              
};
static CFIFODMAStatus g_DMAStatus = {DMA_STATUS_MAX_IP,NULL};
/*------------------------------------------------------------------
 * Func : init_dma_status
 *
 * Desc : init g_DMAStatus
 *
 * Parm : 
 *
 * Retn :
 *------------------------------------------------------------------*/
int init_dma_status(void)
{
    unsigned int i=0,j=0;
    g_DMAStatus._subCount = DMA_STATUS_MAX_IP;
    /*RTICE_DEBUG("[%s:%d]IP Count is%d\r\n",__func__,__LINE__,g_DMAStatus._subCount);*/
    //printk("[dma_status] init dma status\n");*/
    //malloc ips;
    g_DMAStatus._ips = (CFIFOIpStatus**)\
        kmalloc(sizeof(CFIFOIpStatus*)*g_DMAStatus._subCount,GFP_ATOMIC);
    for(i=0;i<g_DMAStatus._subCount;i++){
        //init ip
        CFIFOIpStatus * pip = (CFIFOIpStatus *)kmalloc(sizeof(CFIFOIpStatus),GFP_ATOMIC);
        /*RTICE_DEBUG("[%s:%d]create IP.it's id=%d\r\n",__func__,__LINE__,i);*/
        g_DMAStatus._ips[i] = pip;
        if(pip){
            pip->_id = i;
            pip->_subCount = SubsCountOfIP[i];
            pip->_isChoosen = false;
            if(SubsCountOfIP[i] == 0)
                continue;
            pip->_subIps = (CFIFOSubIpStatus**)\
                kmalloc(sizeof(CFIFOSubIpStatus*)*pip->_subCount,GFP_ATOMIC);
            /*RTICE_DEBUG("[%s:%d]IP id=%d, count=%d\r\n",__func__,__LINE__,i,pip->_subCount);*/
            //init sub ips
            for(j=0;j<pip->_subCount;j++){
                CFIFOSubIpStatus * subip = (CFIFOSubIpStatus*)kmalloc(sizeof(CFIFOSubIpStatus),\
                    GFP_ATOMIC);
                pip->_subIps[j] = subip;
                if(subip){
                    /*RTICE_DEBUG("[%s:%d]create sub IP.it's id=%d\r\n",__func__,__LINE__,j);*/
                    subip->_id = j;
                    subip->_isChoosen = false;
                    subip->_subCount = 0;
                    subip->_pDataHead = NULL;
                    if(i==DMA_STATUS_TVSB2){
                        if(j==TVSB2_SUB_IP_DI_W){
                            subip->_subCount = 2;
                            subip->_pDataHead = &tvsb2_diw_data_overflow;
                        }else if(j==TVSB2_SUB_IP_DI_R){
                            subip->_subCount = 2;
                            subip->_pDataHead = &tvsb2_dir_data_overflow;
                        }else if(j==TVSB2_SUB_IP_M_cap_W){
                            subip->_subCount = 2;
                            subip->_pDataHead = &tvsb2_m_cap_w_data_overflow;
                        }else if(j==TVSB2_SUB_IP_M_disp_R){
                            subip->_subCount = 2;
                            subip->_pDataHead = &tvsb2_m_disp_r_data_overflow;
                        }else if(j==TVSB2_SUB_IP_S_cap_W){
                            subip->_subCount = 2;
                            subip->_pDataHead = &tvsb2_s_cap_w_data_overflow;
                        }else if(j==TVSB2_SUB_IP_S_disp_R){
                            subip->_subCount = 2;
                            subip->_pDataHead = &tvsb2_s_disp_r_data_overflow;
                        }else if(j==TVSB2_SUB_IP_VO1_Y_R || j==TVSB2_SUB_IP_VO1_C_R){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb2_vo1_y_underflow;
                         }else if(j==TVSB2_SUB_IP_VO2_Y_R || j==TVSB2_SUB_IP_VO2_C_R){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb2_vo2_y_underflow;
                        }else if(j==TVSB2_SUB_IP_I3DDMA_W){
                            subip->_subCount = 2;
                            subip->_pDataHead = &tvsb2_i3ddma_overflow;
                        }else if(j==TVSB2_SUB_IP_DE_XC_W){
                            subip->_subCount = 4;
                            subip->_pDataHead = &tvsb2_de_xc_wdata_overflow;
                        }else if(j==TVSB2_SUB_IP_DE_XC_R){
                            subip->_subCount = 6;
                            subip->_pDataHead = &tvsb2_de_xc_rdata0_overflow;
                        }
#if 0
                        else if(j==TVSB2_SUB_IP_SNR_R){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb2_snr_r_underflow;
                        }
#endif
                        else{
                            RTICE_DEBUG("[%s:%d]sub ip is too much,id=%d\r\n",__func__,__LINE__,j);    
                        }
                    }
                    else if(i==DMA_STATUS_TVSB1){
                        if(j==TVSB1_SUB_IP_VD){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb1_vd_underflow;
                        }else if(j==TVSB1_SUB_IP_Audio1){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb1_audio_overflow;
                        }else if(j==TVSB1_SUB_IP_Audio2){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb1_audio2_overflow_0;
                        }else if(j==TVSB1_SUB_IP_VBI){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb1_vbi_overflow;
                        }else if(j==TVSB1_SUB_IP_TVE_VD){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb1_tve_vd_overflow;
                        }else if(j==TVSB1_SUB_IP_TVE_VBI){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb1_tve_vbi_overflow;
                        } else{}      
                    }
                    else if(i==DMA_STATUS_SB1){
                        if(j==SB1_SUB_IP_EMMC){
                            subip->_subCount = 1;
                            subip->_pDataHead = &sb1_emmc_overflow;
                        }else{}
                    }
                    else if(i==DMA_STATUS_SB2){
                        
                    }
                    else if(i==DMA_STATUS_SB3){
                        if(j==SB3_SUB_IP_MD){
                            subip->_subCount = 1;
                            subip->_pDataHead = &sb3_md_overflow;
                        }else{}
                    }
                    else if(i==DMA_STATUS_VE){
                        
                    }
                    else if(i==DMA_STATUS_VE2){
                        
                    }
                    else if(i==DMA_STATUS_TVSB3){
                        if(j==TVSB3_SUB_IP_OSD_OFF_1_5){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb3_osd_off1_5_underflow;
                        }else{}
                    }
                    else if(i==DMA_STATUS_TVSB5){
                        if(j==TVSB5_SUB_IP_OSD_PST){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb5_pst_underflow;
                        }else{}
                    }
                    else if(i==DMA_STATUS_TVSB4){
                        if(j==TVSB4_SUB_IP_OD_W){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb4_odw_overflow_0;
                        }else if(j==TVSB4_SUB_IP_OD_R){
                            subip->_subCount = 2;
                            subip->_pDataHead = &tvsb4_odr_underflow_0;
                        }
                        else if(j==TVSB4_SUB_IP_DC2H){
                            subip->_subCount = 2;
                            subip->_pDataHead = &tvsb4_dc2h_overflow;
                        }
                        else if(j==TVSB4_SUB_IP_SUBTITLE){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb4_subtitle_underflow;
                        }
                        else if(j==TVSB4_SUB_IP_OSD1_5){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb4_osd_1_5_underflow;
                        }
#if 0                        
                        else if(j==TVSB4_SUB_IP_Demura){
                            subip->_subCount = 1;
                            subip->_pDataHead = &tvsb4_demura_underflow;
                        }
#endif
                        else{}
                    }
#if 0                    
                    else if(i==DMA_STATUS_MEMC){
                        if(j==MEMC_SUB_IP_ME0){
                            subip->_subCount = 1;
                            subip->_pDataHead = &memc_me0_overflow;
                        }else if(j==MEMC_SUB_IP_ME4){
                            subip->_subCount = 1;
                            subip->_pDataHead = &memc_me4_overflow;
                        }else if(j==MEMC_SUB_IP_ME5){
                            subip->_subCount = 1;
                            subip->_pDataHead = &memc_me5_overflow;
                        }else if(j==MEMC_SUB_IP_ME8){
                            subip->_subCount = 1;
                            subip->_pDataHead = &memc_me8_overflow;
                        }else if(j==MEMC_SUB_IP_ME10){
                            subip->_subCount = 1;
                            subip->_pDataHead = &memc_me10_overflow;
                        }else if(j==MEMC_SUB_IP_ME12){
                            subip->_subCount = 1;
                            subip->_pDataHead = &memc_me12_overflow;
                        }else if(j==MEMC_SUB_IP_ME14){
                            subip->_subCount = 1;
                            subip->_pDataHead = &memc_me14_overflow;
                        }else{}
                    }
#endif                    
                    else{}
                    
                    /*RTICE_DEBUG("[%s:%d]sub IP id=%d,data cnt=%d\r\n",__func__,__LINE__,j,subip->_subCount);*/
                }
                else{
                    RTICE_DEBUG("[%s:%d]kmalloc failed\r\n",__func__,__LINE__);    
                }
            }
        }
    }
    /*RTICE_DEBUG("INIT Finish");*/
    return 0;    
}
/*------------------------------------------------------------------
 * Func : release_dma_status
 *
 * Desc : release memory
 *
 * Parm : 
 *
 * Retn :
 *------------------------------------------------------------------*/
int release_dma_status(void)
{
    unsigned int i=0,j=0;
    CFIFOIpStatus * pip = NULL;
    CFIFOSubIpStatus * subip=NULL;
    struct CFIFODataInfo * pd = NULL,*pnxt=NULL;
    for(i=0;i<g_DMAStatus._subCount;i++){
        //ip
        pip = g_DMAStatus._ips[i];
        if(pip){
            //subips
            for(j=0;j<pip->_subCount;j++){
                subip = pip->_subIps[j];
                if(subip){
                    pd = subip->_pDataHead;
                    while(pd != NULL){
                        pnxt = pd->next;
                        kfree(pd);
                        pd = NULL;
                        pd = pnxt;
                    }
                    kfree(subip);
                }
            }
            kfree(pip);
        }
     }
    kfree(g_DMAStatus._ips);
    RTICE_DEBUG("[%s:%d]Release Finish\r\n",__func__,__LINE__);
    return 0;
}
/*------------------------------------------------------------------
 * Func : parse_dma_status
 *
 * Desc : parse command, and set ip,subIP,data is selected
 *
 * Parm : 
 *
 * Retn :
 *------------------------------------------------------------------*/
int parse_dma_status(unsigned char *cmd_data,unsigned int cmd_len)
{
    unsigned int i=0,j=0;
    unsigned int ipId=0,subIpId=0,dataId = 0;
    CFIFOIpStatus * pip = NULL;
    CFIFOSubIpStatus * psub = NULL;
    struct CFIFODataInfo * pd = NULL;
    bool isFind = false;
    /*RTICE_DEBUG("[%s:%d]parse_dma_status\r\n",__func__,__LINE__);*/
    RTICE_CMD_DEBUG(cmd_data, cmd_len, "command_data=");
    if(cmd_len % 3)
        return -RTICE_DMA_STATUS_INVALID_CMD_LEN;
    
    if(cmd_len == 3 && cmd_data[0] == 0xff && cmd_data[1] == 0xff &&cmd_data[2] == 0xff)
    {
        for(i=0;i<DMA_STATUS_MAX_IP;i++){
            pip = g_DMAStatus._ips[i];
            if(pip != NULL){
                pip->_isChoosen = true;
                /*RTICE_DEBUG("[%s:%d]Choose IP=%d\r\n",__func__,__LINE__,pip->_id);*/
                for(j=0;j<SubsCountOfIP[i];j++){
                    psub = pip->_subIps[j];
                    if(psub != NULL){
                        psub->_isChoosen = true;
                        /*RTICE_DEBUG("\t[%s:%d]Choose Sub IP=%d\r\n",__func__,__LINE__,psub->_id);*/
                        pd = psub->_pDataHead;
                        while(pd != NULL){
                            pd->_isChoosen = true;
                            /*RTICE_DEBUG("\t\t[%s:%d]Choose Sub IP=%d\r\n",__func__,__LINE__,pd->_id);*/
                            pd = pd->next;
                        }
                    }
                }
            }
        }
        return 0;
    }
    while(i<cmd_len){
        //get ip id
        ipId = (unsigned int)cmd_data[i++];
        /*RTICE_DEBUG("[%s:%d]Finding IP id=%d\r\n",__func__,__LINE__,ipId);*/
        if(ipId >= g_DMAStatus._subCount)
            return -RTICE_DMA_STATUS_INVALID_IP_ID;
        //get IP
        pip = g_DMAStatus._ips[ipId];
        if(pip != NULL){
            if(pip->_id != ipId){
                RTICE_DEBUG("[%s:%d]IP id=%d is not match\r\n",__func__,__LINE__,ipId);
                return -RTICE_DMA_STATUS_INIT_IP_ORDER_ERROR;
            }
            //set ip is choosn one
            pip->_isChoosen = true;
            /*RTICE_DEBUG("[%s:%d]Choose IP=%d\r\n",__func__,__LINE__,pip->_id);*/
            subIpId = (unsigned int)cmd_data[i++];
            if(subIpId >= pip->_subCount)
                return -RTICE_DMA_STATUS_INVALID_SUB_IP_ID;
            //get sub ip
            psub = pip->_subIps[subIpId];
            if(psub != NULL){
                //set sub ip is choosn one
                psub->_isChoosen = true;
                /*RTICE_DEBUG("\t[%s:%d]Choose Sub IP=%d\r\n",__func__,__LINE__,psub->_id);*/
                //get data
                dataId = (unsigned int)cmd_data[i++];
                pd = psub->_pDataHead;
                isFind = false;
                while(pd!= NULL){
                    //set data is choosn
                    /*if(dataId == 0xff)
                        pd->_isChoosen = true;    
                    else */if(pd->_id == dataId){
                        pd->_isChoosen = true;
                        /*RTICE_DEBUG("\t\t[%s:%d]Choose data=%d\r\n",__func__,__LINE__,pd->_id);*/
                        isFind = true;
                        break;
                    }else{}
                    pd = pd->next;
                }
                if(!isFind){
                    RTICE_DEBUG("[%s:%d]data id=%d is not find\r\n",__func__,__LINE__,dataId);
                    return -RTICE_DMA_STATUS_INVALID_DATA_ID;
                }
            }else{
                RTICE_DEBUG("[%s:%d]Sub IP id=%d is not find\r\n",__func__,__LINE__,subIpId);
                return -RTICE_DMA_STATUS_INVALID_SUB_IP_ID;    
            }
            
        }
        else{
            RTICE_DEBUG("[%s:%d]IP id=%d is not find\r\n",__func__,__LINE__,ipId);
            return -RTICE_DMA_STATUS_INVALID_IP_ID;
        }
    }
    return 0;
}
/*------------------------------------------------------------------
 * Func : update_dma_status
 *
 * Desc : read data from register
 *
 * Parm : 
 *
 * Retn :
 *------------------------------------------------------------------*/
int update_dma_status(void)
{
    unsigned int i=0,j=0;
    CFIFOIpStatus * pip = NULL;
    CFIFOSubIpStatus * psub = NULL;
    struct CFIFODataInfo * pd = NULL;
    /*RTICE_DEBUG("[%s:%d]update_dma_status\r\n",__func__,__LINE__);*/
    for(i=0;i<g_DMAStatus._subCount;i++){
        pip = g_DMAStatus._ips[i];
        if(pip != NULL && pip->_isChoosen){
            /*RTICE_DEBUG("[%s:%d]update ip=%d\r\n",__func__,__LINE__,pip->_id);*/
            for(j=0;j<SubsCountOfIP[i];j++){
                psub = pip->_subIps[j];
                if(psub != NULL && psub->_isChoosen){
                    /*RTICE_DEBUG("\t[%s:%d]update sub ip=%d\r\n",__func__,__LINE__,psub->_id);*/
                    pd = psub->_pDataHead;
                    while(pd != NULL){
                        /*RTICE_DEBUG("\t\t\t[%s:%d]Finding data=%d, Choosen=%d\r\n",__func__,__LINE__,pd->_id,pd->_isChoosen);*/
                        if(pd->_isChoosen){
                            pd->_value = pd->UpdateFunction();
                            /*RTICE_DEBUG("\t\t[%s:%d]ip=%d,sub_ip=%d,data=%d,value=%d\r\n",__func__,__LINE__,i,j,pd->_id,pd->_value);*/
                        }
                        pd = pd->next;
                    }
                }else if(psub == NULL){
                    RTICE_DEBUG("\t[%s:%d]None sub ip=%d\r\n",__func__,__LINE__,j);    
                }else if(!psub->_isChoosen){
                    RTICE_DEBUG("\t[%s:%d]sub ip=%d is not choosn\r\n",__func__,__LINE__,psub->_id);    
                }
            }
        }
        else if(pip == NULL){
            RTICE_DEBUG("[%s:%d]None ip=%d\r\n",__func__,__LINE__,i);     
        }
    }
    return 0;    
}
/*------------------------------------------------------------------
 * Func : out_dma_status
 *
 * Desc : output dma status to buf
 *
 * Parm : 
 *
 * Retn :
 *------------------------------------------------------------------*/
int out_dma_status(unsigned char *response_data,unsigned int response_buff_size)
{
    unsigned int i=0,j=0;
    CFIFOIpStatus * pip = NULL;
    CFIFOSubIpStatus * psub = NULL;
    struct CFIFODataInfo * pd = NULL;
    unsigned int len = 0;
    unsigned int subIPCnt=0,subIPCntId=0;
    unsigned int dataCnt=0,dataCntId=0;
    for(i=0;i<DMA_STATUS_MAX_IP;i++){
        pip = g_DMAStatus._ips[i];
        if(pip != NULL && pip->_isChoosen){
            pip->_isChoosen = false;
            //out ip id
            response_data[len++] = pip->_id;
            /*RTICE_DEBUG("[%s:%d]out ip=%d\r\n",__func__,__LINE__,pip->_id);*/
            subIPCntId = len++;//jump one byte,The byte is saved sub ip count
            subIPCnt = 0;
            for(j=0;j<SubsCountOfIP[i];j++){
                psub = pip->_subIps[j];
                if(psub != NULL && psub->_isChoosen){
                    psub->_isChoosen = false;
                    subIPCnt++;
                    //out sub ip id
                    response_data[len++] = psub->_id;
                    /*RTICE_DEBUG("[%s:%d]out sub ip=%d\r\n",__func__,__LINE__,psub->_id);*/
                    dataCntId = len++;//jump one byte,The byte is saved data count
                    dataCnt = 0;
                    pd = psub->_pDataHead;
                    while(pd != NULL){
                        if(pd->_isChoosen){
                            pd->_isChoosen = false;
                            //out data id
                            response_data[len++] = pd->_id;
                            //out data value
                            response_data[len++] = ((pd->_value >> 24) & 0xff);
                            response_data[len++] = ((pd->_value >> 16) & 0xff);
                            response_data[len++] = ((pd->_value >> 8) & 0xff);
                            response_data[len++] = ((pd->_value >> 0) & 0xff);
                            dataCnt++;
                            /*RTICE_DEBUG("[%s:%d]ip=%d,sub ip=%d,data(%d)=%d, now len is %d\r\n",__func__,__LINE__,i,j,pd->_id,pd->_value,len);*/
                        }
                        pd = pd->next;
                    }
                    //set data count
                    response_data[dataCntId] = dataCnt;
                    /*RTICE_DEBUG("[%s:%d]out data cnt=%d\r\n",__func__,__LINE__,dataCnt);*/
                }
            }
            //set sub ip count
            response_data[subIPCntId] = subIPCnt;
            /*RTICE_DEBUG("[%s:%d]out sub ip cnt=%d\r\n",__func__,__LINE__,subIPCnt);*/
        }
        /*if(len >= response_buff_size){
            RTICE_DEBUG("[%s:%d]RTICE_DMA_STATUS_OUT_LENGTH_OVERFLOW:len=%d,response_buff_size=%d\r\n",\
                __func__,__LINE__,len,response_buff_size);
            return -RTICE_DMA_STATUS_OUT_LENGTH_OVERFLOW;
        }*/
    }
    /*RTICE_DEBUG("[%s:%d]total len is %d\r\n",__func__,__LINE__,len);*/
    /*RTICE_CMD_DEBUG(response_data,len,"response_data=");*/
    return len;
}
/*------------------------------------------------------------------
 * Func : rtice_dma_status_command_probe
 *
 * Desc : proc dma status command
 *
 * Parm : opcode
 *
 * Retn :
 *------------------------------------------------------------------*/
int rtice_dma_status_command_probe(unsigned char op_code)
{
	return (GET_OP_CODE_COMMAND(op_code) <= 3) ? 1 : 0;
}
/*------------------------------------------------------------------
 * Func : rtice_dma_status_command_handler
 *
 * Desc : proc dma status command
 *
 * Parm : cmd_data : command data
 *        cmd_len  : command data len
 *        rdata  : response data
 *
 * Retn :  < 0    : error
 *         others : length of response data
 *------------------------------------------------------------------*/
int rtice_dma_status_command_handler(
			      unsigned char opcode, unsigned char *cmd_data,
			      unsigned int cmd_len,
			      unsigned char *response_data,
			      unsigned int response_buff_size )
{
    //parse cmd
    int ret = 0;
    //printk(KERN_NOTICE "[%s:%d].\r\n", __func__,__LINE__);
    RTICE_CMD_DEBUG(cmd_data, cmd_len, "command_data=");
    switch(opcode){
    case RTICE_IOMEM_CMD_GET_DMA_STATUS:
    	ret = parse_dma_status(cmd_data, cmd_len);
        if(ret == 0){
            ret = update_dma_status();
            if(ret == 0)
                ret = out_dma_status(response_data, response_buff_size);
            else{
                
            }
        }else{

        }
    break;
    case RTICE_IOMEM_CMD_ENTER_MC_MEASURE:
        RTICE_DEBUG("[%s:%d]Enter mc measure.\r\n", __func__,__LINE__);
        ret = init_client_list(cmd_data, cmd_len);
        if(ret == 0){
            RTICE_DEBUG("[%s:%d]Enter mc measure.\r\n", __func__,__LINE__);
        	ret = enter_mc_measure();
        }
    break;
    case RTICE_IOMEM_CMD_GET_MC_MEASURE:
        RTICE_DEBUG("[%s:%d]get_mc_measure.\r\n", __func__,__LINE__);
        ret = get_mc_measure(response_data, response_buff_size, \
            (ENUM_MC_MEASURE_QUERY)cmd_data[0]);
    break;
    case RTICE_IOMEM_CMD_EXIT_MC_MEASURE:
        RTICE_DEBUG("[%s:%d]exit_mc_masure.\r\n", __func__,__LINE__);
    	ret = exit_mc_masure();
        ret = clear_client_list();
    break;
    default:
        break;
    }
	return ret;
}
rtice_command_handler_t dma_status_cmd_handler = \
{
	RTICE_CMD_GROUP_ID_DMA_STATUS,
	rtice_dma_status_command_probe,
	rtice_dma_status_command_handler
};
/*------------------------------------------------------------------
 * Func : rtice_dma_status_tool_init
 *
 * Desc : register rtice dma status tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/

static int __init rtice_dma_status_tool_init(void)
{
    rtice_register_command_handler(&dma_status_cmd_handler,\
		sizeof(dma_status_cmd_handler) / sizeof(rtice_command_handler_t));
    printk("rtice_register_command_handler() has been executed for DMA_STATUS.\n");
	return init_dma_status();
}



/*------------------------------------------------------------------
 * Func : rtice_dma_status_tool_exit
 *
 * Desc : exit rtice dma status tool
 *
 * Parm : N/A
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static void __exit rtice_dma_status_tool_exit(void)
{
    rtice_unregister_command_handler(&dma_status_cmd_handler,\
		sizeof(dma_status_cmd_handler) / sizeof(rtice_command_handler_t));
    printk("rtice_unregister_command_handler() has been executed for DMA_STATUS.\n");
    release_dma_status();
}
module_init(rtice_dma_status_tool_init);
module_exit(rtice_dma_status_tool_exit);
