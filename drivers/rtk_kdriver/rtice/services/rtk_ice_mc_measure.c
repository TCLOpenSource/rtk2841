#include "rtk_ice_mc_measure.h"
#include <linux/kthread.h>
#include <linux/slab.h> //kmalloc
#include <linux/delay.h>
#include <mach/io.h>
#include <rbus/dc_phy_reg.h>

#define MC_RECORD_NUMBER 8
#define MC_MEASURE_PATCH_NUMERATOR 3
#define MC_MEASURE_PATCH_DENOMINATOR 4
static DECLARE_WAIT_QUEUE_HEAD (rtice_mc_wait_main);

static CMcMeasure g_McMeasure = {NULL,NULL,
    false,//f_stop_thread
    false,//is_running
    0, //error_code
    MC_MEASURE_QUERY_CURRENT,
    false,//has extend command
    0x0//mc measure threshold
};
//static unsigned int gMeasureCount=0;
//#define MC_READ_DATA(x,y) (((y)==MC_MEASURE_QUERY_CURRENT)?(x)->mc1_read:(x)->max_mc1_read)
static unsigned int mc_address(unsigned int addr,ENUM_MC_CATEGORY mc)
{
    if (mc == MC_CATEGORY_MC1){
		addr = addr & 0xffff0fff;
		addr = addr | 0x00008000;
	}
	else if (mc == MC_CATEGORY_MC2){
		addr = addr & 0xffff0fff;
		addr = addr | 0x00004000;
	}
	return addr;
}

static int read_client(CMcClient* pmc,ENUM_MC_CATEGORY mc)
{
    unsigned int curRecordNum = 0,value=0x0,timeout_cnt=0,client_id=0;
    unsigned int read_cnt=0,write_cnt=0,tmp_cnt=0;
    unsigned int valid_read_number=0,valid_write_number=0;
    unsigned int i=0,i_1=0;
    int nret = 0;
    if(pmc == NULL)
        return -RTICE_MC_MEASURE_INVALID_PARAM;
    if(mc == MC_CATEGORY_ALL_MC){
        nret |= read_client(pmc, MC_CATEGORY_MC1);
        nret |= read_client(pmc, MC_CATEGORY_MC2);
        return nret;
    }
    RTICE_DEBUG("Bus_id=%d,client_Id=%d mc=%d-->\r\n",pmc->bus_id,pmc->client_id,(int)mc);
    
#ifdef CONTINUOUS_MODE    
    // query Current Recording SRAM number. And This record's count is reading by hw,
    // So we can get record index[0,i-1][i+2,7]'s count
    value = rtd_inl(DC_PHY_CLIENT_MEAS_4_reg);
    curRecordNum  = DC_PHY_CLIENT_MEAS_4_get_current_accessing_sram(value);
    RTICE_DEBUG("0xb8008E0C=0x%x curRecordNum=%d\r\n",value,curRecordNum);
#else
    value = 1;
    // enable mc measure
    rtd_outl(mc_address(DC_PHY_CLIENT_MEAS_0_reg, mc),value);
    while(1){
        if(g_McMeasure.f_stop_thread)
            return 0;
        if(rtd_inl(mc_address(DC_PHY_CLIENT_MEAS_0_reg, mc)) ==0){// wait record done
		msleep(10);
            	break;
	}
        timeout_cnt++;
        if(timeout_cnt > 0x80000000){
            RTICE_DEBUG("[%s:%d]read bus[%d], client[%d] time out.\r\n", __func__,__LINE__,\
                pmc->bus_id,pmc->client_id);
            return -RTICE_MC_MEASURE_TIME_OUT;
        }
	msleep(10);
    }
#endif
    for(i=0;i<8;i++){
#ifdef CONTINUOUS_MODE        
        i_1 = (curRecordNum+1)%8;
        if(i==curRecordNum || i == i_1)
            continue;
#endif        
        //write record number and client id
        value = 0;
        //set record num
        value =  DC_PHY_CLIENT_MEAS_1_meas_sram_num(i);
        //set client id
        client_id = ((pmc->bus_id& 0xf) << 4) | pmc->client_id;
        value = value | DC_PHY_CLIENT_MEAS_1_meas_sram_address(client_id);
        rtd_outl(mc_address(DC_PHY_CLIENT_MEAS_1_reg,mc),value);
        RTICE_DEBUG("\trecord_num=0x%x,client_id=0x%x 0xB8008E00=0x%x:",i,client_id,value);
        // read client's read count
        tmp_cnt = rtd_inl(mc_address(DC_PHY_CLIENT_MEAS_2_reg,mc));
        if(tmp_cnt != 0){
            read_cnt += tmp_cnt;
            valid_read_number++;
            RTICE_DEBUG("read_cnt=%u:",tmp_cnt);
        }
        //read client's write count
        tmp_cnt = rtd_inl(mc_address(DC_PHY_CLIENT_MEAS_3_reg,mc));
        if(tmp_cnt != 0){
            write_cnt += tmp_cnt;
            valid_write_number++;
            RTICE_DEBUG("write_cnt=%u ",tmp_cnt);
        }
        RTICE_DEBUG("\r\n");
    }
    if(valid_read_number)
        read_cnt /= valid_read_number;
    else
        read_cnt = 0;
    if(valid_write_number)
        write_cnt /= valid_write_number;
    else
        write_cnt = 0;
    
   RTICE_DEBUG("read=%u, write =%u.\r\n",read_cnt,write_cnt);
    if(mc == MC_CATEGORY_MC1){
        pmc->measure_number[0] = read_cnt;
        pmc->measure_number[1] = write_cnt;
        for(i=0;i<2;i++){
            if(pmc->measure_number[i] > pmc->max_measure_number[i]){
                pmc->max_measure_number[i] = pmc->measure_number[i]; 
                pmc->max_measure_count[i] = pmc->measure_count+1;
            }
        }
    }else if(mc == MC_CATEGORY_MC2){
        pmc->measure_number[2] = read_cnt;
        pmc->measure_number[3] = write_cnt;
        for(i=2;i<4;i++){
            if(pmc->measure_number[i] > pmc->max_measure_number[i]){
                pmc->max_measure_number[i] = pmc->measure_number[i]; 
                pmc->max_measure_count[i] = pmc->measure_count+1;
            }
        }
    }
    return 0;
}
static int mc_measure_thread(void * data)
{
    CMcClient * pclient = NULL;
    int i=0;
    CMcMeasure * pmc = (CMcMeasure*)data;
    if(pmc == NULL)
        return -RTICE_MC_MEASURE_INVALID_PARAM;
    RTICE_DEBUG("[%s:%d]start mc_measure_thread\r\n", __func__,__LINE__);
    pmc->f_is_running = true;
    wake_up(&rtice_mc_wait_main);
#ifdef CONTINUOUS_MODE    
    rtd_outl(DC_PHY_CLIENT_MEAS_0_reg, 0x3);
#endif
    while(1){ 
        pclient = pmc->_phead;
        while(pclient != NULL){
            pmc->error_code = read_client(pclient,pclient->mc_category);
            if(pmc->error_code)
                break;
            else{
                pclient->measure_count++;
                for(i=0;i<MC_MEASURE_ITEM_COUNT;i++){
                    pclient->prev_measure_number[i] = pclient->measure_number[i];
                }
            }
            RTICE_DEBUG("[%s:%d]bus_%d_client_%d_count %d \r\n", __func__,__LINE__,\
            pclient->bus_id,pclient->client_id,pclient->measure_count);
            pclient = pclient->_pnext;
            if(pmc->f_stop_thread || kthread_should_stop())
                break;
            //msleep(1);
        }
        //gMeasureCount++;
        if(pmc->f_stop_thread || kthread_should_stop())
            break;
        if(pmc->error_code)
            break;
        if(pmc->f_stop_thread || kthread_should_stop())
            break;
        msleep(1);
    }
    pmc->f_is_running = false;    
    wake_up(&rtice_mc_wait_main);
    RTICE_DEBUG("[%s:%d]mc_measure_thread stoped\r\n", __func__,__LINE__);
    return 0;
}
int init_client_list(unsigned char * cmd_data,unsigned long cmd_len)
{    
    CMcClient *p = NULL, *dummy = NULL;
    unsigned long i = 0,j=0;
    unsigned char busId = 0;
    RTICE_DEBUG("[%s:%d]init_client_list.\r\n", __func__,__LINE__);
    clear_client_list();
    /*if(cmd_len % 3) does not need for new command
        return -RTICE_MC_MEASURE_CMD_LEN_ERROR;*/
    p = g_McMeasure._phead;
    g_McMeasure.hasExtendCommand = false;
    g_McMeasure.mc_threshold = 0x0;
    while(i<cmd_len){
        busId = cmd_data[i];
        if(busId & 0x80){//it is extend command count
            RTICE_DEBUG("[%s:%d]parse extend command,i=%d, cmd_len=%d \r\n", __func__,__LINE__,i,cmd_len);
            busId = busId & 0x7f;
            //get mc measure threshold
            i++;
            if(i+4 > cmd_len)
                return -RTICE_MC_MEASURE_CMD_LEN_ERROR;
            RTICE_DEBUG("[%s:%d]parse extend command\r\n", __func__,__LINE__);
            for(j=0;j<4;j++){
                g_McMeasure.mc_threshold |= (cmd_data[i+j]<<(8*(3-j)));
            }
            i+=4;
            RTICE_DEBUG("[%s:%d]mc_threshold=%d, i=%d.\r\n", __func__,__LINE__,g_McMeasure.mc_threshold,i);
        }else{
            // create new CMcClient and init 
            if(p == NULL){
                p = (CMcClient*)kmalloc(sizeof(CMcClient),GFP_ATOMIC);
            }
            p->bus_id = cmd_data[i];//bus id
            i++;
            p->client_id = cmd_data[i];//client id
            i++;
            p->mc_category = (ENUM_MC_CATEGORY)cmd_data[i];
            i++;

            memset(&*p->measure_number,0,MC_MEASURE_ITEM_COUNT*sizeof(UINT32));
            memset(&*p->prev_measure_number,0,MC_MEASURE_ITEM_COUNT*sizeof(UINT32));
            memset(&*p->max_measure_number,0,MC_MEASURE_ITEM_COUNT*sizeof(UINT32));
            memset(&*p->max_measure_count,0,MC_MEASURE_ITEM_COUNT*sizeof(UINT32));
            p->measure_count = 0;
            p->_pprev = dummy;
            p->_pnext = NULL;
            RTICE_DEBUG("[%s:%d]find bus[%d], client[%d], type[%d].\r\n", __func__,__LINE__,\
                p->bus_id,p->client_id,p->mc_category);
            // set head
            if(g_McMeasure._phead == NULL)
                g_McMeasure._phead = p;
            // set prev CMcClient's _pnext is current
            if(dummy)
                dummy->_pnext = p;
            dummy = p;
            p = p->_pnext;
        }
    }
    return 0;
}

int clear_client_list(void)
{
    CMcClient *p = g_McMeasure._phead;
    CMcClient * ptmp = NULL;
    RTICE_DEBUG("[%s:%d]Enter mc measure.\r\n", __func__,__LINE__);
    while(p != NULL){
        ptmp = p->_pnext;
        kfree(p);
        p = ptmp;
    }
    g_McMeasure._phead = NULL;
    return 0;
}

int enter_mc_measure(void)
{
    int nres = 0;
    exit_mc_masure();
    //gMeasureCount = 0;
    g_McMeasure.p_thread = kthread_run(mc_measure_thread,&g_McMeasure,"mc_measure_thread");
    nres = wait_event_timeout(rtice_mc_wait_main,(g_McMeasure.f_is_running == true),100);
    if(!nres){
        RTICE_DEBUG("[%s:%d]Failed start mc_measure_thread.\r\n", __func__,__LINE__);
        return -RTICE_MC_MEASURE_CREATE_THREAD;
    }
    //RTICE_DEBUG("[%s:%d]Success start mc_measure_thread (0x%08x).\r\n", __func__,__LINE__,\
    //    g_McMeasure.p_thread);
    return 0;
}

int exit_mc_masure(void)
{
    if(g_McMeasure.f_is_running){
        RTICE_DEBUG("[%s:%d]set f_stop_thread is true.\r\n", __func__,__LINE__);
        g_McMeasure.f_stop_thread = true;
        int nres = wait_event_timeout(rtice_mc_wait_main,(g_McMeasure.f_is_running == false),100);
        if(!nres){
            RTICE_DEBUG("[%s:%d]Failed stop mc_measure_thread.\r\n", __func__,__LINE__);
            return -RTICE_MC_MEASURE_CREATE_THREAD;
        }
    }
    RTICE_DEBUG("[%s:%d]stoping mc_measure_thread (0x%08x).\r\n", __func__,__LINE__,\
        g_McMeasure.p_thread);
    if(g_McMeasure.p_thread && !IS_ERR(g_McMeasure.p_thread))
		kthread_stop(g_McMeasure.p_thread);    
    RTICE_DEBUG("[%s:%d]stop mc_measure_thread (0x%08x).\r\n", __func__,__LINE__,\
        g_McMeasure.p_thread);
    g_McMeasure.p_thread = NULL;
    g_McMeasure.f_stop_thread = false;
    return 0;
}

int get_mc_measure(unsigned char * out_buf,unsigned int buf_size,ENUM_MC_MEASURE_QUERY query)
{
    CMcClient * p = NULL;
    unsigned int i=0,j=0,t32=0,count=0;
    UINT8* presData = out_buf;
    if(out_buf == NULL || g_McMeasure._phead == NULL)
        return -RTICE_MC_MEASURE_INVALID_PARAM;
    p = g_McMeasure._phead;
    while(p != NULL){// && i < buf_size){
        if(query == MC_MEASURE_QUERY_CURRENT){
            t32 = p->measure_count;
            /*RTICE_DEBUG("[%s:%d]bus_%d_client_%d_count[%d]\r\n", __func__,__LINE__,\
            p->bus_id,p->client_id,t32);*/
            LTB4(t32 , presData[0], presData[1], presData[2],presData[3]); 
            presData += 4;
            i+=4;    
        }
        if(p->mc_category == MC_CATEGORY_MC1 || p->mc_category == MC_CATEGORY_ALL_MC){
            for(j=0;j<2;j++){
                if(query == MC_MEASURE_QUERY_MAX){//output count
                    t32 = p->max_measure_count[j];
                    LTB4(t32 , presData[0], presData[1], presData[2],presData[3]); 
                    presData += 4;
                    i+=4;
                }  
                t32  = (query == MC_MEASURE_QUERY_CURRENT)?p->prev_measure_number[j]:\
                    ((query == MC_MEASURE_QUERY_MAX)?p->max_measure_number[j]:0);
    		    LTB4(t32 , presData[0], presData[1], presData[2],presData[3]); 
                presData += 4;
                i+=4;
            }
            
        }
        if(p->mc_category == MC_CATEGORY_MC2 || p->mc_category == MC_CATEGORY_ALL_MC){
            for(j=2;j<4;j++){
                if(query == MC_MEASURE_QUERY_MAX){//output count
                    t32 = p->max_measure_count[j];
                    LTB4(t32 , presData[0], presData[1], presData[2],presData[3]); 
                    presData += 4;
                    i+=4;
                }  
                t32  = (query == MC_MEASURE_QUERY_CURRENT)?p->prev_measure_number[j]:\
                    ((query == MC_MEASURE_QUERY_MAX)?p->max_measure_number[j]:0);
    		    LTB4(t32 , presData[0], presData[1], presData[2],presData[3]); 
                presData += 4;
                i+=4;
            }
            
        }
        RTICE_DEBUG("[GET_MC]bus=%d,client=%d,read=%d,write=%d.\r\n",p->bus_id,p->client_id,p->measure_number[0],p->measure_number[1]);
        p = p->_pnext;
    }
    /*if(i>=buf_size && p != NULL)
        return RTICE_MC_MEASURE_OUT_BUF_SIZE_SMALL;*/
    return i;
}
