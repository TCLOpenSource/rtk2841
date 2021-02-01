/******************************************************************************
 *
 *   Copyright(c) 2015. Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author kevin_wang@realtek.com
 *
 *****************************************************************************/
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/miscdevice.h>
#include <linux/kthread.h>
#include <linux/jiffies.h>
#include <linux/delay.h>
#include <linux/pageremap.h>
#include <linux/string.h>
#include <linux/freezer.h>
#ifdef CONFIG_LG_SNAPSHOT_BOOT
#include <linux/suspend.h>
#endif

#include <asm/uaccess.h>
#include <asm/cacheflush.h>

#include <mach/pcbMgr.h>
#include <mach/platform.h>

#include <base_types.h>
#include <rbus/tp_reg.h>
#include <rtk_cw_util.h>
#include <rtk_crt.h>

#include <tp/tp_dbg.h>
#include <tp/tp_def.h>
#include <tp/tp_drv_global.h>
#include <tp/tp_drv.h>
#include <tp/tp_ioctl.h>
#include <tp/tp_reg_ctrl.h>

/*****************************************

 inner function

******************************************/

#define TSP_PID(tsp)                          (((tsp[1] & 0x1F) <<8) +  (tsp[2]))

#define TPO_OUTPUT_EN(x)                      ((x>>21) & 0x3)
#define TPO_SRC(x)                            ((x>>16) & 0x3)

#define TP_SRC_INTERNAL_DEMOD_GET(x)          (x&0xf)
#define TP_SRC_EXTERNAL_TUNER0_GET(x)         ((x>>4)&0xf)
#define TP_SRC_EXTERNAL_TUNER1_GET(x)         ((x>>8)&0xf)
#define TP_SRC_EXTERNAL_CAM0_GET(x)           ((x>>12)&0xf)
#define TP_SRC_EXTERNAL_CAM1_GET(x)           ((x>>16)&0xf)


static unsigned long buff_check_timeout = 0;
static unsigned long tp_status_timeout = 0;

extern void rtk_inv_range(const void *virt_start, const void *virt_end);

//extern UINT8 tp_tpo_dbg_en;
extern bcas_info_t bcas;

int save_tp_reigster_value_ex(void);
int restore_tp_reigster_value_ex(void);


void _dump_tsp_buffer_data(TPK_TP_ENGINE_T tp_id,
                           UINT8* p_virt_start,
                           UINT8* p_virt_end,
                           UINT8 block_size,
                           UINT16 pid_filter)
{

        while(p_virt_start < p_virt_end) {
                int i;
                UINT8* pTSP = (block_size == 192) ? &p_virt_start[4] : p_virt_start;

                if ((pTSP[1] & 0x40) && (pid_filter == 0xFFFF || TSP_PID(pTSP) == pid_filter)) {
                        if (block_size == 192) {
                                TP_DBG_SIMPLE("[TP%d] TSP = [ %02x %02x %02x %02x][",
                                              tp_id, p_virt_start[0], p_virt_start[1], p_virt_start[2], p_virt_start[3]);
                        } else {
                                TP_DBG_SIMPLE("[TP%d] TSP = [", tp_id);
                        }

                        for (i = 0; i < 32; i++)
                                TP_DBG_SIMPLE("%02x", pTSP[i]);


                        TP_DBG_SIMPLE(" ... ]\n");
                }

                p_virt_start +=  block_size;

        }
}

static INT32 _dump_tp_ring_buffer(void *arg)
{
        UINT8 buf_idx[MAX_TP_COUNT] = {TP0_BUFFER_MASS_DATA,
                                       TP1_BUFFER_MASS_DATA,
                                       TP2_BUFFER_MASS_DATA,
                                       TP3_BUFFER_MASS_DATA
                                      };

        UINT8 start_code_buf_idx[MAX_TP_COUNT] = { TP0_START_CODE_PACK,
                                                   TP1_START_CODE_PACK,
                                                   0x00,
                                                   0x00
                                                 };
        UINT8 *wp_temp_phy;
        UINT8 *wp_temp_virtual;
        UADDRESS wp_update;
        struct timeval saved_time[MAX_TP_COUNT], new_time;
        UINT32 time_cnt;


        UINT32 i;
        INT32 result;
        TP_BUFFER_PARAM_T buf_param;
        void *virtBase, *virtLimit, *virtWP, *virtLastWP;
        wait_queue_head_t timeout_wq;
        init_waitqueue_head(&timeout_wq);

        current->flags &= ~PF_NOFREEZE;

        for( i = 0; i < MAX_TP_COUNT; i++) {
                pTp_drv->tp[i].lastWP = 0;
                pTp_drv->tp[i].old_wp = 0;
                pTp_drv->tp[i].now_startcode_parsing_address = 0;
                pTp_drv->tp[i].wp_update_by_startcode = 0;
                pTp_drv->tp[i].timeout_wp = 0;
                pTp_drv->tp[i].find_new_start_code = 0;
                do_gettimeofday(&pTp_drv->tp[i].saved_time);
        }

        while(!kthread_should_stop()) {
                for (i = 0; i < MAX_TP_COUNT; i++) {
                        _tp_lock();
                        if (pTp_drv->tp[i].Shared_RWPtr.inited == 1) {
                                pTp_drv->tp[i].monitor_pvr_rp = *(pTp_drv->tp[i].Shared_RWPtr.pRP);
                                pTp_drv->tp[i].monitor_pvr_wp = *(pTp_drv->tp[i].Shared_RWPtr.pWP);							
                                if(pTp_drv->tp[i].wp_update_by_startcode == 0) {
                                        pTp_drv->tp[i].wp_update_by_startcode = *pTp_drv->tp[i].Shared_RWPtr.pWP;
                                        pTp_drv->tp[i].timeout_wp = *pTp_drv->tp[i].Shared_RWPtr.pWP;
                                        do_gettimeofday(&saved_time[i]);
                                }

                                wp_update = 0;
                                if( pTp_drv->tp[i].useTPStartCodeSearch == 1 ) {
                                        result = Tp_Get_Buffer(start_code_buf_idx[i], &buf_param);
                                        if (result != TPK_SUCCESS) {
                                                TP_WARNING("get buffer status fail (tp_id=%u)\n", i);
                                        } else {
                                                if( (pTp_drv->tp[i].old_wp < buf_param.Base) || (pTp_drv->tp[i].old_wp > buf_param.Limit) ) {
                                                        TP_DBG("old_wp from 0x%x to 0x%x\n", pTp_drv->tp[i].old_wp, buf_param.Base);
                                                        pTp_drv->tp[i].old_wp = buf_param.Base;
                                                }

                                                pTp_drv->tp[i].find_new_start_code = 0;

                                                while( pTp_drv->tp[i].old_wp != buf_param.WP) {
                                                        wp_temp_virtual = (UINT8 *)(pTp_drv->tp[i].start_code_search_buffer.BaseVir + (pTp_drv->tp[i].old_wp - pTp_drv->tp[i].start_code_search_buffer.BasePhy));

                                                        if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_STARTCODE) ) {
                                                                if(pTp_drv->tp[i].show_startcode_info_cnt < 10) {
                                                                        UINT8 *mass_temp_phy;
                                                                        UINT8 *mass_temp_virtual;

                                                                        mass_temp_phy = wp_temp_virtual[0] << 24 | wp_temp_virtual[1] << 16 | wp_temp_virtual[2] << 8 | wp_temp_virtual[3];
                                                                        mass_temp_virtual = pTp_drv->tp[i].mass_buffer.BaseVir + (mass_temp_phy - pTp_drv->tp[i].mass_buffer.BasePhy);
                                                                        mass_temp_virtual = mass_temp_virtual + wp_temp_virtual[4] + 4;

                                                                        pTp_drv->tp[i].show_startcode_info_cnt++;

                                                                        TP_DBG_SIMPLE("[%d]stco_p=0x%08x stco_v=0x%08x mass_p=0x%08x mass_v=0x%08x ofset=0x%02x %02x%02x%02x => %02x%02x%02x%02x%02x%02x\n", pTp_drv->tp[i].show_startcode_info_cnt, pTp_drv->tp[i].old_wp, wp_temp_virtual, mass_temp_phy, mass_temp_virtual, wp_temp_virtual[4], wp_temp_virtual[5], wp_temp_virtual[6], wp_temp_virtual[7], mass_temp_virtual[0], mass_temp_virtual[1], mass_temp_virtual[2], mass_temp_virtual[3], mass_temp_virtual[4], mass_temp_virtual[5]);
                                                                }
                                                        }

                                                        pTp_drv->tp[i].old_wp = pTp_drv->tp[i].old_wp + 8;
                                                        if(pTp_drv->tp[i].old_wp == buf_param.Limit)
                                                                pTp_drv->tp[i].old_wp = buf_param.Base;

                                                        pTp_drv->tp[i].find_new_start_code = 1;
                                                }

                                                if(*pTp_drv->tp[i].Shared_RWPtr_start_code_search.pWP != buf_param.WP) {
                                                        *pTp_drv->tp[i].Shared_RWPtr_start_code_search.pWP = buf_param.WP;
                                                }
                                        }

                                        pTp_drv->tp[i].start_code_search_buffer.RP_Connect[START_CODE_PACK_BUFFER_RP] = *pTp_drv->tp[i].Shared_RWPtr_start_code_search.pRP;

                                        Tp_Update_Buffer_RP(i , start_code_buf_idx[i], &pTp_drv->tp[i].start_code_search_buffer);

                                        if(pTp_drv->tp[i].find_new_start_code == 1) {
                                                if(pTp_drv->tp[i].old_wp == buf_param.Base)
                                                        wp_temp_phy = (UINT8*)(buf_param.Limit - 8);
                                                else
                                                        wp_temp_phy = (UINT8*)(pTp_drv->tp[i].old_wp - 8);

                                                wp_temp_virtual = pTp_drv->tp[i].start_code_search_buffer.BaseVir + (wp_temp_phy - pTp_drv->tp[i].start_code_search_buffer.BasePhy);
                                                wp_update = (UADDRESS)(wp_temp_virtual[0] << 24 | wp_temp_virtual[1] << 16 | wp_temp_virtual[2] << 8 | wp_temp_virtual[3]);

                                                if(pTp_drv->tp[i].now_startcode_parsing_address == 0)
                                                        pTp_drv->tp[i].now_startcode_parsing_address = wp_update;

                                                if(pTp_drv->tp[i].now_startcode_parsing_address != wp_update) {
                                                        if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_STARTCODE) ) {
                                                                TP_BUFFER_PARAM_T buf_param_tpbuf;
                                                                Tp_Get_Buffer(buf_idx[i], &buf_param_tpbuf);
                                                                TP_DBG("TP%u: 0x%x pvr_wp=0x%x pvr_rp=0x%x tp_wp=0x%x tp_rp=0x%x\n", i, wp_update, *pTp_drv->tp[i].Shared_RWPtr.pWP, *pTp_drv->tp[i].Shared_RWPtr.pRP, buf_param_tpbuf.WP, buf_param_tpbuf.RP);
                                                                if( buf_param_tpbuf.WP > *(pTp_drv->tp[i].Shared_RWPtr.pWP) ) {
                                                                        if( (wp_update > *(pTp_drv->tp[i].Shared_RWPtr.pWP)) && wp_update < buf_param_tpbuf.WP) {
                                                                                //TP_DBG("update\n");
                                                                        } else {
                                                                                //TP_WARNING("no update\n");
                                                                        }
                                                                } else {
                                                                        if( ( (wp_update >  *(pTp_drv->tp[i].Shared_RWPtr.pWP)) && (wp_update < buf_param_tpbuf.Limit)) ||
                                                                            ( (wp_update > buf_param_tpbuf.Base) &&  (wp_update < buf_param_tpbuf.WP))) {
                                                                                ;
                                                                                //TP_DBG("update\n");
                                                                        } else {
                                                                                //TP_DBG("no update\n");
                                                                        }
                                                                }
                                                        }
                                                        pTp_drv->tp[i].wp_update_by_startcode = pTp_drv->tp[i].now_startcode_parsing_address;
                                                        pTp_drv->tp[i].timeout_wp = pTp_drv->tp[i].now_startcode_parsing_address;
                                                        if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_STARTCODE) ) {
                                                                TP_DBG("TP%u: new wp 0x%x\n", i, pTp_drv->tp[i].wp_update_by_startcode);
                                                        }
                                                }
                                                pTp_drv->tp[i].now_startcode_parsing_address = wp_update;
                                                do_gettimeofday(&saved_time[i]);
                                        }
                                }
                                /* update status */
                                result = Tp_Get_Buffer(buf_idx[i], &buf_param);
                                if (result != TPK_SUCCESS) {
                                        TP_WARNING("get buffer status fail (tp_id=%u)\n", i);
                                } else {
                                        if( pTp_drv->tp[i].useTPStartCodeSearch == 1 ) {
                                                if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_STARTCODE) ) {
                                                        //TP_DBG_SIMPLE("HW WP= 0x%x RP= 0x%x\n", buf_param.WP, buf_param.RP);
                                                }

                                                do_gettimeofday(&new_time);
                                                time_cnt = (new_time.tv_sec >= saved_time[i].tv_sec) ?
                                                           ((new_time.tv_sec - saved_time[i].tv_sec) * 1000) :
                                                           ((new_time.tv_sec + (0xffffffff - saved_time[i].tv_sec)) * 1000);
                                                time_cnt += ((new_time.tv_usec - saved_time[i].tv_usec) / 1000);

                                                if(time_cnt > 500) {
                                                        pTp_drv->tp[i].wp_update_by_startcode = pTp_drv->tp[i].timeout_wp;
                                                        saved_time[i] = new_time;
                                                        pTp_drv->tp[i].timeout_wp = buf_param.WP;
                                                        pTp_drv->tp[i].now_startcode_parsing_address = buf_param.WP;
                                                        TP_DBG("TP%u: timeout pvr update 0x%x 0x%x\n", i, pTp_drv->tp[i].wp_update_by_startcode, pTp_drv->tp[i].timeout_wp);
                                                }

                                                if( (pTp_drv->tp[i].wp_update_by_startcode >= buf_param.Base) && (pTp_drv->tp[i].wp_update_by_startcode <= buf_param.Limit))
                                                        buf_param.WP = pTp_drv->tp[i].wp_update_by_startcode;

                                                if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_STARTCODE)) {
                                                        //TP_DBG_SIMPLE("UpdateWP= 0x%x\n", buf_param.WP);
                                                }
                                                Tp_FlushPatternSearch(i);
                                        }

                                        *pTp_drv->tp[i].Shared_RWPtr.pWP = buf_param.WP;
                                }

                                pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP] = *pTp_drv->tp[i].Shared_RWPtr.pRP;

                                Tp_Update_Buffer_RP(i , buf_idx[i], &pTp_drv->tp[i].mass_buffer);


                                /* flush data */
                                if ((pTp_drv->tp[i].lastWP < buf_param.Base) || (pTp_drv->tp[i].lastWP > buf_param.Limit)) {
                                        pTp_drv->tp[i].lastWP = buf_param.Base;
                                }

                                if (buf_param.WP >= pTp_drv->tp[i].lastWP) {
                                        virtLastWP = Tp_Buf_Phy_to_Vir(i, TP_BUFFER_MASS_DATA, (UINT8 *)pTp_drv->tp[i].lastWP);
                                        virtWP     = Tp_Buf_Phy_to_Vir(i, TP_BUFFER_MASS_DATA, (UINT8 *)buf_param.WP);

                                        if ( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_PVR) ) {
                                                _dump_tsp_buffer_data(i, virtLastWP, virtWP, 192, dump_tp_pvr_buff_pid[i]);
                                        }
                                        rtk_inv_range(virtLastWP, virtWP);
                                } else {
                                        virtLastWP = Tp_Buf_Phy_to_Vir(i, TP_BUFFER_MASS_DATA, (UINT8 *)pTp_drv->tp[i].lastWP);
                                        virtLimit  = Tp_Buf_Phy_to_Vir(i, TP_BUFFER_MASS_DATA, (UINT8 *)buf_param.Limit);
                                        virtBase   = Tp_Buf_Phy_to_Vir(i, TP_BUFFER_MASS_DATA, (UINT8 *)buf_param.Base);
                                        virtWP     = Tp_Buf_Phy_to_Vir(i, TP_BUFFER_MASS_DATA, (UINT8 *)buf_param.WP);

                                        if ( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_PVR) ) {
                                                _dump_tsp_buffer_data(i, virtLastWP, virtLimit, 192, dump_tp_pvr_buff_pid[i]);
                                        }
                                        rtk_inv_range(virtLastWP, virtLimit);

                                        if ( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_PVR) ) {
                                                _dump_tsp_buffer_data(i, virtLastWP, virtLimit, 192, dump_tp_pvr_buff_pid[i]);
                                        }
                                        rtk_inv_range(virtBase, virtWP);
                                }

                                pTp_drv->tp[i].lastWP = buf_param.WP;
                        }

                        _tp_unlock();
                }

                if (freezing(current)) {
                        try_to_freeze();
                }

                /* interruptible_sleep_on_timeout(&timeout_wq, 10); */
                wait_event_interruptible_timeout(timeout_wq, 0, 10);
        }

        return 0;
}

char* GetTPOSrcStr(unsigned char src)
{
        switch(src) {
                case 0:
                        return "MEM";
                case 1:
                        return "TP0";
                case 2:
                        return "TP1";
                case 3:
                        return "TP2";
                default :
                        return "Unknown";
        }
}

/* this function is used to monitor tpo and tpp ring buffer status */
void check_tpp_ring_buffer(void)
{
        UADDRESS Base;
        UADDRESS Limit;
        UADDRESS RP;
        UADDRESS WP;
        unsigned long Cnt;
        unsigned long Drp;
        unsigned long tpo_frmcfg = READ_REG32(TP_TP_TF_OUT_FRMCFG_reg);

        if (buff_check_timeout == 0)
                buff_check_timeout = jiffies + HZ;

        if (jiffies < buff_check_timeout)
                return;

        if ( CHECK_LOG_BLOCK_MASK( TP_LOG_BLOCK_TPOUT) ) {
                TP_INFO("TPO FRMCFG=%08lx (OTU=%lx, SRC=%lx (%s))\n",
                        tpo_frmcfg,
                        TPO_OUTPUT_EN(tpo_frmcfg),
                        TPO_SRC(tpo_frmcfg),
                        GetTPOSrcStr(TPO_SRC(tpo_frmcfg)));
        }

        if (TPO_OUTPUT_EN(tpo_frmcfg) && TPO_SRC(tpo_frmcfg) == 0) {
                int i;

                for ( i = 0 ; i < 3; i++) {
                        if ( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_TPOUT) ) {

                                Cnt = READ_REG32(0xb8014518 + (i * 0x30));
                                Drp = READ_REG32(0xb801451C + (i * 0x30));

                                if (Cnt >= 0xFFFFFF || Drp >= 0xFFFF) {
                                        WRITE_REG32(0xb8014518 + (i * 0x30), 0);
                                        WRITE_REG32(0xb801451C + (i * 0x30), 0);
                                }

                                WRITE_REG32(TP_TP_P_RING_CTRL_reg, i);

                                Base  = READ_REG32(TP_TP_P_RING_BASE_reg);
                                RP    = READ_REG32(TP_TP_P_RING_RP_reg);
                                WP    = READ_REG32(TP_TP_P_RING_WP_reg);
                                Limit = READ_REG32(TP_TP_P_RING_LIMIT_reg);

                                TP_INFO("TPP_RING[%d]={%08lx, %08lx, %08lx, %08lx}, CNT=%06lx, Drp=%04lx, (Err=%lu)\n",
                                        i,
                                        Base,
                                        RP,
                                        WP,
                                        Limit,
                                        Cnt,
                                        Drp,
                                        pTp_drv->tpp[i].mass_buffer.buffer_err_cnt);
                        }

                        Tp_TPP_CheckRingBuffer();
                }
        }

        buff_check_timeout = jiffies + HZ;
}



/*****************************************

 function for driver base to init RHAL_TP

******************************************/
/*------------------------------------------------------------------
 * Func : RHAL_TPInit
 *
 * Desc : init TP MODULE
 *
 * Parm : tp_id : TP Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPInit(IN TPK_TP_ENGINE_T tp_id)
{
        INT32 ret;
        INT32 tpi;
        TPK_TP_INPUT_PARAM_T tpi_pol;

        tp_tp_tf0_p_cntl_RBUS tp_p_cntl_reg;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();



        _tp_lock();

        ret = Tp_init(tp_id);
        /*TPOut clk & tpout mode set ,init once*/
        Tp_TPO_Init(0);

        /* set tpi pol - mac5p internal demod only support falling */
        pTp_drv->tpi[TP_TPI_demod].clk_pol = 1;
        pTp_drv->tpi[TP_TPI_demod].sync_pol = 0;
        pTp_drv->tpi[TP_TPI_demod].val_pol = 0;
        Tp_SetInputPol(TP_TPI_demod, pTp_drv->tpi[TP_TPI_demod]);

        WRITE_REG32(TP_TP0_ERR_CNT_EN_reg, 0x000006ff);
        WRITE_REG32(TP_TP1_ERR_CNT_EN_reg, 0x000006ff);
        WRITE_REG32(TP_TP2_ERR_CNT_EN_reg, 0x000006ff);

        _tp_unlock();

        TP_TRACE("exit, id = %d, ret=%d\n", tp_id, ret);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_TPInit);



/*------------------------------------------------------------------
 * Func : RHAL_TPUninit
 *
 * Desc : uninit TP MODULE
 *
 * Parm : id : TP Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPUninit(IN TPK_TP_ENGINE_T tp_id)
{
        INT32  ret;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        ret = Tp_uninit(tp_id);

        _tp_unlock();

        return ret;
}
EXPORT_SYMBOL(RHAL_TPUninit);

/*------------------------------------------------------------------
 * Func : RHAL_SetTPMode
 *
 * Desc : Set TS Input mode of TP MODULE
 *
 * Parm : id : TP Index
 *        param : TS Parameter
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_SetTPMode(
        IN TPK_TP_ENGINE_T          tp_id,
        IN TPK_TP_TS_PARAM_T        Param
)
{
        INT32 ret;
        TP_INPUT_INTERFACE_PARAM_T tp_input_if_param;

        TP_TRACE("Enter, tp_id=%d, serial=%u, pid_filter_en=%u\n", tp_id, Param.serial, Param.pid_filter_en);

        if (Param.ts_in_tsp_len > byte_204) {
                TP_WARNING("bad parameter, ts_in_tsp_len=%u\n", Param.ts_in_tsp_len);
                return TPK_BAD_PARAMETER;
        }

        _tp_lock();
        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                goto TP_ERROR;
        }

#if 0
        /* check if stream is started?? */
        if ((pTp_drv->tp[tp_id].tp_stream_status == TP_STREAM_START)
            && (pTp_drv->tp[tp_id].tp_param.ts_in_tsp_len != Param.ts_in_tsp_len)) {
                TP_WARNING("not allow to change tp mode if stream is running, id=%u\n", tp_id);
                ret = TPK_RESOURCE_CONFLICT;
                goto TP_ERROR;
        }
#endif
        /* 1. tp input from from pad */
        /* 1.1 set TP input interface */
        tp_input_if_param.serial      = Param.serial;
        tp_input_if_param.data_order  = Param.data_order;
        tp_input_if_param.datapin     = Param.datapin;
        tp_input_if_param.sync_byte   = Param.sync_byte;
        tp_input_if_param.packet_size = Param.ts_in_tsp_len;
        Tp_ENG_SetInputInterface(tp_id, tp_input_if_param);

        /* 1.2 Set TP input interface as two-bits mode */
        /* TP HW ignore serial/parallel, data_order, datapin when set two-bits mode */
        Tp_ENG_TwoBitsModeEnable(tp_id, Param.two_bits);

        /* 2. tp input from memory */
        /* add time stamp */
        /* TP will add 4 bytes debug info in the front of TSP */
        Tp_FRC_SetPrefix(tp_id, (Param.keep ? TP_FRC_KEPP : (Param.prefix_en ? 0 : 3)), 0);

        /* frame rate control */
        /* TP will check 4 bytes debug info in the front of TSP when file playback */
        Tp_FRC_Enable(tp_id, (Param.frc_en ? 1 : 0));

        if (Param.prefix_en) {
                pTp_drv->tp[tp_id].IsPktWithTimeStamp    = 1;
                pTp_drv->tp[tp_id].mass_buffer.bock_size = MASS_DATA_BUFFER_BLOCK_SIZE_WITH_TIME_STAMP;
        } else {
                pTp_drv->tp[tp_id].IsPktWithTimeStamp    = 0;
                pTp_drv->tp[tp_id].mass_buffer.bock_size = MASS_DATA_BUFFER_BLOCK_SIZE;
        }

        /* clr_tsp_scrmbl_bit should be used if scramble enabled */
        pTp_drv->tp[tp_id].tp_param        = Param;
        pTp_drv->tp[tp_id].tp_param.inited = 1;

        _tp_unlock();

        TP_TRACE("exit, tp_id=%d, serial=%u, pid_filter_en=%u\n",
                 tp_id, Param.serial, Param.pid_filter_en);

        return TPK_SUCCESS;

TP_ERROR:
        _tp_unlock();
        return ret;
}

EXPORT_SYMBOL(RHAL_SetTPMode);

/*------------------------------------------------------------------
 * Func : RHAL_SetInputSourcePol
 *
 * Desc : Set TP Source Pol
 *
 * Parm : [I] tpi : TP input source
 *                [I] pol : pol param
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/

INT32 RHAL_SetInputSourcePol(
        IN TPK_TPI_PIN_T        tpi,
        IN TPK_TP_INPUT_PARAM_T pol
)
{
        CHECK_MAX_TPI_COUNT(tpi);

        _tp_lock();

        Tp_SetInputPol(tpi, pol);

        _tp_unlock();

        TP_TRACE("Exit, tpi=%d, clk_pol=%d, sync_pol=%d, val_pol=%d\n",
                 tpi, pol.clk_pol, pol.sync_pol, pol.val_pol);

        return TPK_SUCCESS;
}
EXPORT_SYMBOL(RHAL_SetInputSourcePol);

/*------------------------------------------------------------------
 * Func : RHAL_SetTPRingBuffer
 *
 * Desc : Set TP Ring Buffer
 *
 * Parm : [I] id : TP Index
 *        [I] pPhyAddr : physical address
 *        [I] pVirAddr : virtual address
 *        [I] size     : size of ring buffer
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_SetTPRingBuffer(
        IN TPK_TP_ENGINE_T      tp_id,
        IN UINT8*               pPhyAddr,
        IN UINT8*               pVirAddr,
        IN UINT32               size
)
{
        tp_tp_threshold_RBUS threshold_reg;
        tp_tp_fullness_RBUS fullness_reg;
        UINT32  allignment_size;
        UINT8*  pPhyAddrLimit;
        UINT8*  pVirAddrLimit;
        UINT8   buf_idx = TP0_BUFFER_MASS_DATA;
        UADDRESS  info_pack_basePhy, info_pack_limitPhy;
        TP_BUFFER_PARAM_T buf_param;
        INT32 ret;

        TP_DBG("Enter, tp_id= %d, size=%u, pPhyAddr=%p, pVirAddr=%p\n", tp_id, size, pPhyAddr, pVirAddr);

        if ((pPhyAddr == NULL) ||
            (pVirAddr == NULL) ||
            (size < MINIMUM_TP_BUFFER_SIZE)) {
                TP_WARNING("bad parameter, pPhyAddr=%p, size=%u\n", pPhyAddr, size);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        ret = Tp_init(tp_id);

        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }
        _tp_unlock();

        info_pack_basePhy  = pTp_drv->tp[tp_id].info_pack_buffer.BasePhy;
        info_pack_limitPhy = pTp_drv->tp[tp_id].info_pack_buffer.LimitPhy;

        if ((pTp_drv->tp[tp_id].info_pack_buffer.inited != 1) ||
            (info_pack_basePhy == 0) ||
            (info_pack_limitPhy == 0) ) {
                TP_WARNING("TP%u bad parameter for info pack buffer (inited=%u,basePhy=0x%x,limitPhy=0x%x)\n",
                           tp_id, pTp_drv->tp[tp_id].info_pack_buffer.inited,
                           info_pack_basePhy, info_pack_limitPhy);
                return TPK_BAD_PARAMETER;
        }

        switch(tp_id) {
                case TP_TP0:
                        buf_idx = TP0_BUFFER_MASS_DATA;
                        break;
                case TP_TP1:
                        buf_idx = TP1_BUFFER_MASS_DATA;
                        break;
                case TP_TP2:
                        buf_idx = TP2_BUFFER_MASS_DATA;
                        break;
                case TP_TP3:
                        buf_idx = TP3_BUFFER_MASS_DATA;
                        break;
                default:
                        TP_WARNING("unsupported id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        /* /////////////////// */
        //
        /*   Note. we could also remap phycial address to uncashed memory for section using */
        /*      void *dvr_remap_cached_memory(unsigned long phys_addr, size_t size, const void *caller); */
        /*      void *dvr_remap_uncached_memory(unsigned long phys_addr, size_t size, const void *caller); */
        /*      void dvr_unmap_memory(void *cpu_addr, size_t size); */
        //
        /*      *uaddr = dvr_remap_uncached_memory(phys_addr, size, __builtin_return_address(0)); */
        //
        /* /////////////////// */

        /*  start to set buffer register */
        if (pTp_drv->tp[tp_id].IsPktWithTimeStamp == 1) {
                /* Allignment 376 bytes for length */
                allignment_size = (size / TP_BUFFER_WITH_FLOW_CTRL_ALIGNMENT) * TP_BUFFER_WITH_FLOW_CTRL_ALIGNMENT;
        } else {
                allignment_size = (size / TP_BUFFER_ALIGNMENT) * TP_BUFFER_ALIGNMENT;
        }

        pPhyAddrLimit = (UINT8*)((UADDRESS)pPhyAddr + allignment_size);
        pVirAddrLimit = (UINT8*)((UADDRESS)pVirAddr + allignment_size);

        /* set mass data buffer */
        buf_param.Base  = (UADDRESS)pPhyAddr;
        buf_param.Limit = (UADDRESS)pPhyAddrLimit;
        buf_param.RP    = (UADDRESS)pPhyAddr;
        buf_param.WP    = (UADDRESS)pPhyAddr;

        _tp_lock();

        /* check if stream is started?? */
        if (pTp_drv->tp[tp_id].tp_stream_status == TP_STREAM_START) {
                _tp_unlock();
                TP_WARNING("TP%u stream is running, pPhyAddr=%p, size=%u\n", tp_id, pPhyAddr, size);
                return TPK_RESOURCE_CONFLICT;
        }

        ret = Tp_Set_Buffer(buf_idx, buf_param, BUFFER_WRITE_MASK_NONE);

        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                return ret;
        }

        /* save to data structure */
        pTp_drv->tp[tp_id].mass_buffer.OriBufSize = size;
        pTp_drv->tp[tp_id].mass_buffer.BasePhy    = (UADDRESS)pPhyAddr;
        pTp_drv->tp[tp_id].mass_buffer.LimitPhy   = (UADDRESS)pPhyAddrLimit;
        pTp_drv->tp[tp_id].mass_buffer.BufSize    = allignment_size;
        pTp_drv->tp[tp_id].mass_buffer.BaseVir    = (UADDRESS)pVirAddr;
        pTp_drv->tp[tp_id].mass_buffer.LimitVir   = (UADDRESS)pVirAddrLimit;
        pTp_drv->tp[tp_id].mass_buffer.RP         = (UADDRESS)pPhyAddr;
        pTp_drv->tp[tp_id].mass_buffer.WP         = (UADDRESS)pPhyAddr;
        pTp_drv->tp[tp_id].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP] = (UADDRESS)pPhyAddr;
        pTp_drv->tp[tp_id].mass_buffer.RP_Connect[SECTION_BUFFER_RP]   = (UADDRESS)pPhyAddr;
        pTp_drv->tp[tp_id].mass_buffer.RP_Connect_cnt = MASS_DATA_BUFFER_RP_CONNECT;

        if (pTp_drv->tp[tp_id].IsPktWithTimeStamp == 0) {
                pTp_drv->tp[tp_id].mass_buffer.bock_size = MASS_DATA_BUFFER_BLOCK_SIZE;
        } else {
                pTp_drv->tp[tp_id].mass_buffer.bock_size = MASS_DATA_BUFFER_BLOCK_SIZE_WITH_TIME_STAMP;
        }

        pTp_drv->tp[tp_id].mass_buffer.inited = 1;

        /* set info pack buffer */
        switch(tp_id) {
                case TP_TP0:
                        buf_idx = TP0_BUFFER_INFO_PACK;
                        break;
                case TP_TP1:
                        buf_idx = TP1_BUFFER_INFO_PACK;
                        break;
                case TP_TP2:
                        buf_idx = TP2_BUFFER_INFO_PACK;
                        break;
                case TP_TP3:
                        buf_idx = TP3_BUFFER_INFO_PACK;
                        break;
                default:
                        _tp_unlock();
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        buf_param.Base  = info_pack_basePhy;
        buf_param.Limit = info_pack_limitPhy;
        buf_param.RP    = info_pack_basePhy;
        buf_param.WP    = info_pack_basePhy;

        ret = Tp_Set_Buffer(buf_idx, buf_param, BUFFER_WRITE_MASK_NONE);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                return ret;
        }

        /* set threshold and fullness again */
        threshold_reg.regValue  = 0;
        threshold_reg.threshold = TP_BUFFER_WITH_FLOW_CTRL_THRESHOLD;
        WRITE_REG32(TP_TP_THRESHOLD_reg, threshold_reg.regValue);

        fullness_reg.regValue = 0;
        fullness_reg.fullness = size - TP_BUFFER_WITH_FLOW_CTRL_THRESHOLD;
        WRITE_REG32(TP_TP_FULLNESS_reg, fullness_reg.regValue);

        pTp_drv->tp[tp_id].threshold = threshold_reg.regValue;
        pTp_drv->tp[tp_id].fullness  = fullness_reg.regValue;

        _tp_unlock();

        TP_TRACE("Exit, tp_id=%d, size=%u, pPhyAddr=%p, pVirAddr=%p\n",
                 tp_id, size, pPhyAddr, pVirAddr);

        return TPK_SUCCESS;
}
EXPORT_SYMBOL(RHAL_SetTPRingBuffer);

/*------------------------------------------------------------------
 * Func : RHAL_DumpTPRingBuffer
 *
 * Desc : Set TP Ring Buffer & address of rw pointer shared with the caller for dumping data
 *
 * Parm : [I] id : TP Index
 *        [I] enable     : enable or disable
 *        [I] pSharedRP : address of RP shared with the caller
 *        [I] pSharedWP : address of WP shared with the caller
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/

INT32 RHAL_DumpTPRingBuffer(IN TPK_TP_ENGINE_T tp_id,
                            IN UINT8 enable,
                            IN UINT8* pSharedRP,
                            IN UINT8* pSharedWP)
{
        struct task_struct *thread_dumpdata;
        UINT8 stopthread;
        UINT8 i;
        INT32 result;
        TP_BUFFER_PARAM_T buf_param;
        UINT8 buf_idx[MAX_TP_COUNT] = { TP0_BUFFER_MASS_DATA,
                                        TP1_BUFFER_MASS_DATA,
                                        TP2_BUFFER_MASS_DATA,
                                        TP3_BUFFER_MASS_DATA
                                      };

        UINT8 start_code_buf_idx[MAX_TP_COUNT] = { TP0_START_CODE_PACK,
                                                   TP1_START_CODE_PACK,
                                                   0x00,
                                                   0x00
                                                 };

        if((pSharedRP == NULL) || (pSharedWP == NULL)) {
                TP_WARNING("bad parameter,  pShareRP=%p,pShareWP=%p\n", pSharedRP, pSharedWP);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();
        result = Tp_init(tp_id);
        if(result != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", result);
                return result;
        }
        _tp_unlock();


        _tp_lock();
        if (enable) {
                /* create thread to udpate status of buffer pointer */
                if(pTp_drv->thread_dumpdata != NULL) {
                        TP_INFO("_dump_tp_ring_buffer thread is already existed\n");
                } else {
                        /* no need to pass parameter into thread function */
                        thread_dumpdata = kthread_run(_dump_tp_ring_buffer, NULL, "_dump_tp_ring_buffer");
                        if(!IS_ERR(thread_dumpdata)) {
                                pTp_drv->thread_dumpdata = thread_dumpdata;
                                pTp_drv->dumpdata_start  = 1;
                        } else {
                                _tp_unlock();
                                TP_WARNING("create _dump_tp_ring_buffer thread failed, error=%ld\n", PTR_ERR(thread_dumpdata));
                                return TPK_NOT_ENOUGH_RESOURCE;
                        }
                }

                /* set shared RW pointer of mass data buffer */
                pTp_drv->tp[tp_id].Shared_RWPtr.pRP = (UADDRESS *)pSharedRP;
                pTp_drv->tp[tp_id].Shared_RWPtr.pWP = (UADDRESS *)pSharedWP;

                result = Tp_Get_Buffer(buf_idx[tp_id], &buf_param);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("get buffer status fail (tp_id=%u)\n", tp_id);
                } else {
                        *pTp_drv->tp[tp_id].Shared_RWPtr.pWP = buf_param.WP;
                        *pTp_drv->tp[tp_id].Shared_RWPtr.pRP = buf_param.WP;
                        TP_DBG("Shared_RWPtr.pWP =0x%x RP=0x%x\n", buf_param.WP, buf_param.RP);
                }

                if( pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.inited == 1 ) {
                        if(Tp_is_SupportPatternSearch(tp_id) == TPK_SUCCESS) {
                                result = Tp_Get_Buffer(start_code_buf_idx[tp_id], &buf_param);
                                if(result != TPK_SUCCESS) {
                                        TP_WARNING("get buffer status fail (tp_id=%u)\n", tp_id);
                                } else {
                                        *pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.pWP = buf_param.WP;
                                        *pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.pRP = buf_param.WP;
                                        TP_DBG("TP%d: Shared_RWPtr_start_code_search.pWP =0x%x RP=0x%x\n", tp_id, buf_param.WP, buf_param.RP);
                                        Tp_SetPatternSearchEnable( tp_id, 1);
                                }
                        }
                }
                pTp_drv->tp[tp_id].Shared_RWPtr.inited = 1;
        } else {
                /* remove shared RW pointer of mass data buffer */
                pTp_drv->tp[tp_id].Shared_RWPtr.pRP    = NULL;
                pTp_drv->tp[tp_id].Shared_RWPtr.pWP    = NULL;
                pTp_drv->tp[tp_id].Shared_RWPtr.inited = 0;

                if(Tp_is_SupportPatternSearch(tp_id) == TPK_SUCCESS) {
                        pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.pWP = NULL;
                        pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.pRP = NULL;
                        Tp_SetPatternSearchEnable( tp_id, 0);
                        pTp_drv->tp[tp_id].useTPStartCodeSearch = 0;
                }

                /* set DUMP_BUFFER_RP to be invalid */
                pTp_drv->tp[tp_id].mass_buffer.RP_Connect[DUMP_BUFFER_RP] = INVALID_BUFFER;

                /* check if need to stop thread */
                stopthread = 1;
                for (i = 0; i < MAX_TP_COUNT; i++) {
                        if (pTp_drv->tp[i].Shared_RWPtr.inited == 1) {
                                stopthread = 0;
                                break;
                        }
                }

                /* stop thread */
                if (stopthread == 1) {
                        if(pTp_drv->thread_dumpdata == NULL) {
                                TP_INFO("_dump_tp_ring_buffer thread does not exist, just exit\n");
                        } else {
                                pTp_drv->dumpdata_start = 0;
                                _tp_unlock();
                                if(pTp_drv->thread_dumpdata) {
                                        /* it will wait until thread function exit */
                                        result = kthread_stop(pTp_drv->thread_dumpdata);
                                        if(result < 0) {
                                                TP_WARNING("call kthread_stop return error = %d", result);
                                                return TPK_FAIL;
                                        }
                                }
                                _tp_lock();
                                pTp_drv->thread_dumpdata = NULL;
                        }
                }
        }
        _tp_unlock();

        TP_INFO("exit, TP add RP for dumpdata, tp_id=%u, enable=%u, pSharedRP=%p, pSharedWP=%p \n",
                tp_id, enable, pSharedRP, pSharedWP);

        return TPK_SUCCESS;

}

EXPORT_SYMBOL(RHAL_DumpTPRingBuffer);

/*------------------------------------------------------------------
 * Func : RHAL_TPFlushBuffer
 *
 * Desc : Flush TP Ring Buffer
 *
 * Parm : [I] id : TP Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPFlushBuffer(TPK_TP_ENGINE_T tp_id)
{
        INT32 ret;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();

                TP_WARNING("Call Tp_init() fail (%d)\n", ret);

                return ret;
        }

        ret = Tp_flush_Buf(tp_id, 1, (BUF_SEL_MASS_DATA | BUF_SEL_INFO_PACK));

        _tp_unlock();

        TP_TRACE("exit, tp_id=%d\n", tp_id);

        return ret;
}

EXPORT_SYMBOL(RHAL_TPFlushBuffer);



/*------------------------------------------------------------------
 * Func : RHAL_GetTPBufferStatus
 *
 * Desc : Get TP Ring Buffer Status
 *
 * Parm : id       : TP Index
 *        pBufferSize : buffer size
 *        pDataSize   : data size
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_GetTPBufferStatus(
        IN TPK_TP_ENGINE_T        tp_id,
        OUT UINT32*               pBufferSize,
        OUT UINT32*               pDataSize
)
{
        TP_BUFFER_PARAM_T buf_param;
        UINT8 buf_idx;
        INT32 ret;

        /* check parameter */
        if ((pBufferSize == NULL) || (pDataSize == NULL)) {
                TP_WARNING("bad parameter, pBufferSize=%p, pDataSize=%p\n", pBufferSize, pDataSize);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        switch(tp_id) {
                case TP_TP0:
                        buf_idx = TP0_BUFFER_MASS_DATA;
                        break;
                case TP_TP1:
                        buf_idx = TP1_BUFFER_MASS_DATA;
                        break;
                case TP_TP2:
                        buf_idx = TP2_BUFFER_MASS_DATA;
                        break;
                case TP_TP3:
                        buf_idx = TP3_BUFFER_MASS_DATA;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        /* get buffer status from reg */
        Tp_Get_Buffer(buf_idx, &buf_param);

        if ((buf_param.Base == _ZERO) ||
            (buf_param.Limit == _ZERO) ||
            (buf_param.Base >= buf_param.Limit)) {
                _tp_unlock();

                TP_WARNING("buffer status error, base=0x%x, limit=0x%x\n", buf_param.Base, buf_param.Limit);
                return TPK_NOT_INIT;
        }

        *pBufferSize = buf_param.Limit - buf_param.Base;
        *pDataSize   = (buf_param.WP >= buf_param.RP) ?
                       (buf_param.WP - buf_param.RP) :
                       (*pBufferSize - (buf_param.RP - buf_param.WP));

        _tp_unlock();

        TP_TRACE("exit, TP%u, BufferSize=%u, DataSize=%u\n", tp_id, *pBufferSize, *pDataSize);

        return TPK_SUCCESS;
}
EXPORT_SYMBOL(RHAL_GetTPBufferStatus);



/*------------------------------------------------------------------
 * Func : RHAL_TPStreamControl
 *
 * Desc : Get TP Ring Buffer Status
 *
 * Parm : [I] id   : TP Index
 *        [I] ctrl : buffer size
 *
 *            TP_STREAM_START: Start Steaming
 *            TP_STREAM_STOP : Stop Streaming
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPStreamControl(
        TPK_TP_ENGINE_T                tp_id,
        TPK_TP_STREAM_CTRL_T            ctrl
)
{
        tp_tp_tf0_cntl_RBUS tp_cntl;
        tp_tp_tf0_frmcfg_RBUS tp_frm;
        TPK_PID_REG_PARAM_T pid_reg;
        UINT16 pid_idx, i, start_stream_cnt = 0;
        UINT8 ddr_buf_idx;
        UINT8 info_buf_idx;
        INT32 ret;
        REGADDR fram_reg_addr;

        tp_mask_print_emerg( TP_LOG_BLOCK_ALL, TP_LOG_LEVEL_WARNING, "RHAL_TPStreamControl Enter, tp_id=%d, ctrl=%u\n", tp_id, ctrl);

        if ((ctrl != TP_STREAM_START) && (ctrl != TP_STREAM_STOP)) {
                TP_WARNING("bad parameter, ctrl=%u\n", ctrl);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        switch(tp_id) {
                case TP_TP0:
                        pid_idx       = TP0_FIRST_PID_FILTER_IDX;
                        ddr_buf_idx   = TP0_BUFFER_MASS_DATA;
                        info_buf_idx  = TP0_BUFFER_INFO_PACK;
                        fram_reg_addr = TP_TP_TF0_FRMCFG_reg;
                        break;
                case TP_TP1:
                        pid_idx       = TP1_FIRST_PID_FILTER_IDX;
                        ddr_buf_idx   = TP1_BUFFER_MASS_DATA;
                        info_buf_idx  = TP1_BUFFER_INFO_PACK;
                        fram_reg_addr = TP_TP_TF1_FRMCFG_reg;
                        break;
                case TP_TP2:
                        pid_idx       = TP2_FIRST_PID_FILTER_IDX;
                        ddr_buf_idx   = TP2_BUFFER_MASS_DATA;
                        info_buf_idx  = TP2_BUFFER_INFO_PACK;
                        fram_reg_addr = TP_TP_TF2_FRMCFG_reg;
                        break;
                case TP_TP3:
                        pid_idx       = TP3_FIRST_PID_FILTER_IDX;
                        ddr_buf_idx   = TP3_BUFFER_MASS_DATA;
                        info_buf_idx  = TP3_BUFFER_INFO_PACK;
                        fram_reg_addr = TP_TP_TF3_FRMCFG_reg;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        if ((pTp_drv->tp[tp_id].mass_buffer.inited == 0) ||
            (pTp_drv->tp[tp_id].info_pack_buffer.inited == 0)) {
                _tp_unlock();

                TP_WARNING("buffer not init, tp_id=%u, mass_buffer.inited=%u, info_pack_buffer.inited=%u\n",
                           tp_id,
                           pTp_drv->tp[tp_id].mass_buffer.inited,
                           pTp_drv->tp[tp_id].info_pack_buffer.inited);

                return TPK_NOT_INIT;
        }

        TP_DBG("TP%d: change stream status from %d to %d\n\n", tp_id, pTp_drv->tp[tp_id].tp_stream_status, ctrl);
        switch(ctrl) {
                case TP_STREAM_START:
                        if (pTp_drv->tp[tp_id].tp_stream_status == TP_STREAM_STOP) {
                                /* start stream sequence */
                                /* check if PID filter enabled, if not, force to set PID filter -> ring buffer mapping */
                                tp_cntl.regValue = 0;

                                if (pTp_drv->tp[tp_id].tp_param.pid_filter_en == 0) {
                                        /* disable pid filter */
                                        tp_cntl.pid_en = 1;   /* set select bit =1 */
                                        Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, 0);

                                        /* set ddr buffer to mass data buf_idx, other parameter won't change */
                                        Tp_GetPidParam(pid_idx, &pid_reg);
                                        pid_reg.ddr_q = ddr_buf_idx;
                                        Tp_SetPidParam(pid_idx, pid_reg);
                                } else {
                                        /* enable pid filter */
                                        tp_cntl.pid_en = 1;
                                        Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, 1);
                                }

                                TP_INFO("TP%u, pid_filter_en=%u\n", tp_id, pTp_drv->tp[tp_id].tp_param.pid_filter_en);

                                /* flush ring buffer */
                                ret = Tp_flush_Buf(tp_id, 1, (BUF_SEL_MASS_DATA | BUF_SEL_INFO_PACK));
                                if (ret != TPK_SUCCESS) {
                                        _tp_unlock();
                                        return ret;
                                }

                                /* frame enable =0 */
                                tp_frm.regValue = READ_REG32(fram_reg_addr);
                                tp_frm.frm_en   = 0;
                                WRITE_REG32(fram_reg_addr, tp_frm.regValue);

                                /* clean counter */
                                ret = Tp_ResetCounter(tp_id);
                                if (ret != TPK_SUCCESS) {
                                        _tp_unlock();
                                        return ret;
                                }

                                /* reset framer */
                                /* ret=Tp_rst(id); */
                                if (ret != TPK_SUCCESS) {
                                        _tp_unlock();
                                        return ret;
                                }

                                pTp_drv->tp[tp_id].IsMassBufferFull             = 0;
                                pTp_drv->tp_pid[tp_id].tp_mass_data_release_cnt = 0;
                                /* framer enble =1 */
                                tp_frm.frm_en = 1;
                                WRITE_REG32(fram_reg_addr, tp_frm.regValue);
                                pTp_drv->tp[tp_id].tp_stream_status = TP_STREAM_START;

                                ret = section_assemble_thread_start_stop(1);
                                if( ret != TPK_SUCCESS )
                                        TP_WARNING("section assemble thread start fail.\n");
#if 1
                                ret = tp_dbg_thread_start_stop(1);
                                if( ret != TPK_SUCCESS )
                                        TP_WARNING("TP debug thread start fail.\n");
#endif

                        }

                        break;
                case TP_STREAM_STOP:
                        if (pTp_drv->tp[tp_id].tp_stream_status == TP_STREAM_START) {
                                pTp_drv->tp[tp_id].tp_stream_status = TP_STREAM_STOP;

                                pTp_drv->tp[tp_id].tp_pkt_cnt.pkt = 0;
                                pTp_drv->tp[tp_id].tp_pkt_cnt.droppedPkt = 0;
                                pTp_drv->tp[tp_id].tp_pkt_cnt.errorPkt = 0;
                                for( i = 0; i < MAX_TP_COUNT; i++) {
                                        if (pTp_drv->tp[i].tp_stream_status == TP_STREAM_START)
                                                start_stream_cnt++;
                                }

                                if (start_stream_cnt == 0) {
                                        ret = section_assemble_thread_start_stop(0);
                                        if( ret != TPK_SUCCESS )
                                                TP_WARNING("section assemble thread stop fail.\n");
#if 1
                                        ret = tp_dbg_thread_start_stop(0);
                                        if( ret != TPK_SUCCESS )
                                                TP_WARNING("TP debug thread stop fail.\n");
#endif
                                }

                                /* frame enable =0 */
                                tp_frm.regValue = READ_REG32(fram_reg_addr);
                                tp_frm.frm_en   = 0;
                                WRITE_REG32(fram_reg_addr, tp_frm.regValue);

                                /* reset framer */
                                /* ret=Tp_rst(id); */

                                if (ret != TPK_SUCCESS) {
                                        _tp_unlock();
                                        return ret;
                                }

                                /* flush ring buffer */
                                ret = Tp_flush_Buf(tp_id, 1, (BUF_SEL_MASS_DATA | BUF_SEL_INFO_PACK));
                                if (ret != TPK_SUCCESS) {
                                        _tp_unlock();
                                        return ret;
                                }
                        }

                        break;
        }

        _tp_unlock();

        TP_TRACE("exit, tp_id=%d, ctrl=%u\n", tp_id, ctrl);
        tp_mask_print_emerg( TP_LOG_BLOCK_ALL, TP_LOG_LEVEL_WARNING, "RHAL_TPStreamControl exit, tp_id=%d, ctrl=%u\n", tp_id, ctrl);
        return TPK_SUCCESS;
}
EXPORT_SYMBOL(RHAL_TPStreamControl);


/*------------------------------------------------------------------
 * Func : RHAL_TPReadData
 *
 * Desc : Read Data form TP
 *
 * Parm : [I] id : TP Index
 *        [O] ppReadPhyPtr : start address of Data
 *        [O] pContinueReadSize : data size
 *        [I] Threshold : threshold of read data
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPReadData(
        TPK_TP_ENGINE_T       tp_id,
        UINT8**               ppReadPhyPtr,
        UINT32*               pContinueReadSize,
        UINT32                Threshold)
{
        INT32 ret;

        CHECK_MAX_TP_COUNT(tp_id);

        _tp_lock();

        ret = Tp_init(tp_id);

        check_tpp_ring_buffer();   /* here is used to monitor tpo and tpp ring buffer status */

        if (ret != TPK_SUCCESS) {
                _tp_unlock();

                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        ret = TP_ReadData(tp_id, ppReadPhyPtr, pContinueReadSize, Threshold, TP_BUFFER_MASS_DATA);

        _tp_unlock();

        if ((ret == TPK_SUCCESS) || (ret == TPK_BUFFER_FULL) || (ret == TPK_BUFFER_UNDER_THRESHOLD)) {
                if (*pContinueReadSize) {
                        TP_VERBOSE("Get TP%u data return=%d (len=%u, ptr=%p)\n",
                                   tp_id, ret, *pContinueReadSize, *ppReadPhyPtr);
                }
        }

        return ret;
}
EXPORT_SYMBOL(RHAL_TPReadData);

/*------------------------------------------------------------------
 * Func : RHAL_TPReleaseData
 *
 * Desc : Release Data
 *
 * Parm : [I] id : TP Index
 *        [I] pReadPhyPtr : Start address to be released
 *        [I] Size : number of bytes to be released
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPReleaseData(
        TPK_TP_ENGINE_T        tp_id,
        UINT8*                 pReadPhyPtr,
        UINT32                 Size
)
{
        INT32 ret;

        CHECK_MAX_TP_COUNT(tp_id);

        _tp_lock();

        ret = Tp_init(tp_id);

        if (ret != TPK_SUCCESS) {
                _tp_unlock();

                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        /* record ts */
        if (rec_fd[tp_id] && Size) {
                unsigned char* pucReadPtr;
                mm_segment_t old_fs;

                /* int write_count; */
                pucReadPtr = Tp_Buf_Phy_to_Vir(tp_id, TP_BUFFER_MASS_DATA, pReadPhyPtr);
                old_fs = get_fs();
                set_fs(KERNEL_DS);
                /* write_count = vfs_write(rec_fd,pucReadPtr,Size,&rec_fd->f_pos); */
                vfs_write(rec_fd[tp_id], pucReadPtr, Size, &rec_fd[tp_id]->f_pos);
                set_fs(old_fs);
        }

        ret = TP_ReleaseData(tp_id, pReadPhyPtr, Size, TP_BUFFER_MASS_DATA);

        if (ret == TPK_SUCCESS) {
                pTp_drv->tp_pid[tp_id].tp_mass_data_release_cnt += Size;

                TP_VERBOSE("release TP%u data success (len=%u, ptr=%p)\n", tp_id, Size, pReadPhyPtr);
        }

        _tp_unlock();

        return ret;
}

EXPORT_SYMBOL(RHAL_TPReleaseData);


/*------------------------------------------------------------------
 * Func : RHAL_SetTPSource
 *
 * Desc : Set Data Source
 *
 * Parm : [I] id : TP Index
 *        [I] tp_src : TP src
 *        [I] casType : ci
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_SetTPSource(TPK_TP_ENGINE_T   tp_id,
                       TPK_TP_SOURCE_T   tp_src,
                       TPK_CAS_TYPE_T    casType)
{
        INT32 ret;
        REGADDR tp_cntl_reg;
        tp_tp_tf0_cntl_RBUS tp_cntl;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                goto TP_ERROR;
        }

        /* check if stream is started, report warning log */
#if 0
        if (pTp_drv->tp[tp_id].tp_stream_status == TP_STREAM_START) {
                TP_WARNING("not allow to change source if TP stream is running, id=%u\n", tp_id);
        }
#endif

        if ((tp_src != MTP) && (pTp_drv->mtp[tp_id].mtp_connect_type == MTP_TO_TP) &&
            (pTp_drv->mtp[tp_id].mtp_stream_status == MTP_STREAM_START)) {
                TP_WARNING("not allow to change source if MTP stream is running, mtp_id=%u\n", tp_id);
                ret = TPK_RESOURCE_CONFLICT;
                goto TP_ERROR;
        }

        switch(tp_id) {
                case TP_TP0:
                        tp_cntl_reg = TP_TP_TF0_CNTL_reg;
                        break;
                case TP_TP1:
                        tp_cntl_reg = TP_TP_TF1_CNTL_reg;
                        break;
                case TP_TP2:
                        tp_cntl_reg = TP_TP_TF2_CNTL_reg;
                        break;
                case TP_TP3:
                        tp_cntl_reg = TP_TP_TF3_CNTL_reg;
                        break;
                default:
                        TP_WARNING("unsupported id=%d\n", tp_id);
                        ret = TPK_BAD_PARAMETER;
                        goto TP_ERROR;
        }

        tp_cntl.regValue = 0;
        tp_cntl.regValue = READ_REG32(tp_cntl_reg);

        switch(tp_src) {
                case TS_SRC_0:
                        Tp_SetMemoryMode(tp_id, 0);

                        tp_cntl.regValue = 0;
                        tp_cntl.regValue = READ_REG32(tp_cntl_reg);

                        if(TPK_WITH_CAS == casType) {
                                tp_cntl.ci_mode   = 1;
                                tp_cntl.src_sel_h = 0;
                                tp_cntl.src_sel_l = 1;
                        } else {
                                tp_cntl.ci_mode   = 0;
                                tp_cntl.src_sel_h = 0;
                                tp_cntl.src_sel_l = 0;
                        }

                        Tp_Write_Data_Reg_Write(tp_cntl_reg, tp_cntl.regValue);
                        break;

                case TS_SRC_1:
                        Tp_SetMemoryMode(tp_id, 0);
                        tp_cntl.regValue = 0;
                        tp_cntl.regValue = READ_REG32(tp_cntl_reg);

                        if(TPK_WITH_CAS == casType) {
                                tp_cntl.ci_mode   = 1;
                                tp_cntl.src_sel_h = 0;
                                tp_cntl.src_sel_l = 1;
                        } else {
                                tp_cntl.ci_mode   = 0;
                                tp_cntl.src_sel_h = 0;
                                tp_cntl.src_sel_l = 1;
                        }

                        Tp_Write_Data_Reg_Write(tp_cntl_reg, tp_cntl.regValue);
                        break;

                case TS_SRC_2:
                        Tp_SetMemoryMode(tp_id, 0);
                        tp_cntl.regValue = 0;
                        tp_cntl.regValue = READ_REG32(tp_cntl_reg);

                        if(TPK_WITH_CAS == casType) {
                                tp_cntl.ci_mode   = 1;
                                tp_cntl.src_sel_h = 0;
                                tp_cntl.src_sel_l = 1;
                        } else {
                                tp_cntl.ci_mode   = 0;
                                tp_cntl.src_sel_h = 1;
                                tp_cntl.src_sel_l = 0;
                        }

                        Tp_Write_Data_Reg_Write(tp_cntl_reg, tp_cntl.regValue);

                        break;


                case Internal_Demod:
                        Tp_SetMemoryMode(tp_id, 0);
                        tp_cntl.regValue = 0;
                        tp_cntl.regValue = READ_REG32(tp_cntl_reg);

                        if(TPK_WITH_CAS == casType) {
#ifdef CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT
                                pTp_drv->need_to_change_input_source[tp_id] = 1;
                                tp_cntl.ci_mode   = 0;
                                tp_cntl.src_sel_h = 1;
                                tp_cntl.src_sel_l = 1;
#else
                                tp_cntl.ci_mode   = 1;
                                tp_cntl.src_sel_h = 0;
                                tp_cntl.src_sel_l = 1;
#endif
                        } else {
                                tp_cntl.ci_mode   = 0;
                                tp_cntl.src_sel_h = 1;
                                tp_cntl.src_sel_l = 1;
#ifdef CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT
                                pTp_drv->need_to_change_input_source[tp_id] = 0;
#endif
                        }

                        Tp_Write_Data_Reg_Write(tp_cntl_reg, tp_cntl.regValue);
                        break;

                case MTP:
                        /* set to memory to memory mode */
                        if(TPK_WITH_CAS == casType) {
                                Tp_SetMemoryMode(tp_id, 0);
                        } else {
                                Tp_SetMemoryMode(tp_id, 1);
                        }

                        tp_cntl.regValue = 0;
                        tp_cntl.regValue = READ_REG32(tp_cntl_reg);
                        if(TPK_WITH_CAS == casType) {
                                tp_cntl.ci_mode   = 1;
                                tp_cntl.src_sel_h = 0;
                                tp_cntl.src_sel_l = 1;
                        } else {
                                tp_cntl.ci_mode = 0;
                        }

                        Tp_Write_Data_Reg_Write(tp_cntl_reg, tp_cntl.regValue);

                        break;

                default:
                        TP_WARNING("unsupported tp_src=%d\n", tp_src);
                        ret = TPK_BAD_PARAMETER;
                        goto TP_ERROR;
        }

        pTp_drv->tp[tp_id].tp_src = tp_src;
        if(tp_src == MTP)
                pTp_drv->mtp[tp_id].mtp_connect_type = MTP_TO_TP;
        else if(pTp_drv->mtp[tp_id].mtp_connect_type == MTP_TO_TP)
                pTp_drv->mtp[tp_id].mtp_connect_type = MTP_NOT_CONNECT;

        _tp_unlock();

        TP_TRACE("exit, tp_id=%d, casType=%u, tp_src=%u\n",
                 tp_id, casType, pTp_drv->tp[tp_id].tp_src);

        return TPK_SUCCESS;

TP_ERROR:
        _tp_unlock();
        return ret;

}
EXPORT_SYMBOL(RHAL_SetTPSource);


/*------------------------------------------------------------------
 * Func : RHAL_SetTPOUTMode
 *
 * Desc : Set TP Out mode
 *
 * Parm : [I] tpout_id : TP out Index
 *        [I] Param : TS Output Parameter
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPOUTSetMode(
        UINT8                  tpout_id,
        TPK_TPOUT_TS_PARAM_T   Param)
{
        tp_tp_tf_out_frmcfg_RBUS tp_out_frmcfg;
        tp_tp_out_ctrl_RBUS tp_out_ctrl;

        /* check parameter */
        CHECK_MAX_TPOUT_COUNT(tpout_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        if (pTp_drv->tpout[tpout_id].tpout_stream_status == TPOUT_STREAM_START) {
                _tp_unlock();
                TP_WARNING("error, tpout%d stream is started, can not change parameter\n", tpout_id);
                return TPK_RESOURCE_CONFLICT;
        }

        Tp_TPO_SetMode(tpout_id, Param);

        _tp_unlock();

        TP_TRACE("exit, RHAL_SetTPOUTMode TPOUT%u in_serial=%u, in_clk_pol=%u, out_serial=%u, out_clk_pol=%u\n",
                 tpout_id, Param.in_serial, Param.in_clk_pol,
                 Param.out_serial, Param.out_clk_pol);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_TPOUTSetMode);

/*------------------------------------------------------------------
 * Func : RHAL_GetTPOUTMode
 *
 * Desc : Get TP Out mode
 *
 * Parm : [I] tpout_id : TP out Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPOUTGetMode(
        UINT8                  tpout_id,
        TPK_TPOUT_TS_PARAM_T   *pParam)
{
        tp_tp_tf_out_frmcfg_RBUS tp_out_frmcfg;
        tp_tp_out_ctrl_RBUS tp_out_ctrl;

        /* check parameter */
        CHECK_MAX_TPOUT_COUNT(tpout_id);
        CHECK_TP_STRUCTURE();

        if ((pParam == NULL)) {
                TP_WARNING("bad parameter, pParam=%p\n", pParam);
                return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        Tp_TPO_GetMode(tpout_id, pParam);

        _tp_unlock();

        TP_TRACE("exit, RHAL_GetTPOUTMode TPOUT%u in_serial=%u, in_clk_pol=%u, out_serial=%u, out_clk_pol=%u\n",
                 tpout_id, pParam->in_serial, pParam->in_clk_pol,
                 pParam->out_serial, pParam->out_clk_pol);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_TPOUTGetMode);

/*------------------------------------------------------------------
 * Func : RHAL_TPOUTSetDataSource
 *
 * Desc : Set TP Out Data source
 *
 * Parm : [I] tpout_id : TP out Index
 *        [I] tpout_src : tp output source
 *                [I] remux_param : tpp remux parameter
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/

INT32 RHAL_TPOUTSetDataSource(
        UINT8              tpout_id,
        TPK_TPOUT_SOURCE_T tpout_src,
        TPK_TPOUT_REMUX_PARAM_T *remux_param
)
{
        TPK_TP_SOURCE_T src_type;
        tp_tp_tf0_p_cntl_RBUS    tp_p_cntl_reg;
        tp_tp_tf0_p_frmcfg_RBUS  tp_p_frmcfg_reg;
        INT32 ret;

        CHECK_MAX_TPOUT_COUNT(tpout_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        if (pTp_drv->tpout[tpout_id].tpout_stream_status == TPOUT_STREAM_START) {
                Tp_TPO_StreamControl(tpout_id, TPOUT_STREAM_STOP);
        }

        if(tpout_src == TPK_TPP_TO_TPOUT) {

                if(remux_param == NULL) {
                        _tp_unlock();
                        TP_WARNING("RHAL_TPOUTSetDataSource remux_param is null, tpout_id=%u\n", tpout_id);
                        return TPK_BAD_PARAMETER;
                }
                TPK_TPP_ENGINE_T tp_p_id = remux_param->tpp_id;

                ret = Tp_TPP_Init(tp_p_id);
                if(ret != TPK_SUCCESS) {
                        _tp_unlock();
                        TP_INFO("exit, TPOUT%u tp_p_id=%u, init  fail\n", tpout_id, tp_p_id);
                        return ret;
                }
                Tp_TPP_CheckRingBuffer();

                /* tp' frame disable */
                Tp_TPP_GetFrmReg(tp_p_id, &tp_p_frmcfg_reg.regValue);
                tp_p_frmcfg_reg.frm_en = 0;
                Tp_TPP_SetFrmReg(tp_p_id, tp_p_frmcfg_reg.regValue);
                /* disable tp' */
                if (remux_param->tpp_src == TS_UNMAPPING) {
                        Tp_TPP_SetSyncReplace(tp_p_id, 0x47);
                        Tp_ENG_SetSyncReplace(tp_p_id, 0x47);
                        pTp_drv->tpout[tpout_id].tpout_remux[tp_p_id].output_sync_byte = 0x47;
                        pTp_drv->tpout[tpout_id].tpout_remux[tp_p_id].tpp_src          = TS_UNMAPPING;
                        pTp_drv->tpout[tpout_id].tpout_remux[tp_p_id].is_connected     = 0;
                        _tp_unlock();

                        TP_INFO("exit, TPOUT%u stops to set to tp_p_id=%u, remux_src=%u, output_sync_byte=%u\n",
                                tpout_id,
                                tp_p_id,
                                pTp_drv->tpout[tpout_id].tpout_remux[tp_p_id].tpp_src,
                                pTp_drv->tpout[tpout_id].tpout_remux[tp_p_id].output_sync_byte);

                        return TPK_SUCCESS;
                }
                /* set tpp source */
                Tp_TPP_SetDataSource(tp_p_id, remux_param->tpp_src);

                /* sync byte */
                Tp_ENG_SetSyncReplace((TPK_TP_ENGINE_T)tp_p_id, 0x47);
                Tp_TPP_SetSyncReplace(tp_p_id, remux_param->output_sync_byte);

                Tp_TPP_ResetCounter(tp_p_id);
                Tp_TPP_FlushBuf(tp_p_id);

                /* tp' frame enable */
                tp_p_frmcfg_reg.frm_en = 1;
                Tp_TPP_SetFrmReg(tp_p_id, tp_p_frmcfg_reg.regValue);

                /* pTp_drv->tpout[tpout_id].tpout_remux[]. = tpout_src; */
                pTp_drv->tpout[tpout_id].tpout_remux[tp_p_id].is_connected     = 1;
                pTp_drv->tpout[tpout_id].tpout_remux[tp_p_id].tpp_src        = remux_param->tpp_src;
                pTp_drv->tpout[tpout_id].tpout_remux[tp_p_id].output_sync_byte = remux_param->output_sync_byte;

                /* set tpo source to mtp */
                Tp_TPO_SetDataSource(MTP);  /* CI+1.4 path, demod -> TPP -> TPO */

        } else {
                switch(tpout_src) {
                        case TPK_IN_DEMOD_TO_TPOUT:
                                src_type = Internal_Demod;
                                break;
                        case TPK_TP_MTP_TO_TPOUT:
                                src_type = MTP;
                                break;
                        case TPK_TPI0_TO_TPOUT:
                                src_type = TS_SRC_0;
                                break;
                        case TPK_TPI1_TO_TPOUT:
                                src_type = TS_SRC_1;
                                break;
                        case TPK_TPI2_TO_TPOUT:
                                src_type = TS_SRC_2;
                                break;
                        default:
                                _tp_unlock();
                                TP_WARNING("bad parameter (tpout_id=%u, tpout_src=%u)\n", tpout_id, tpout_src);
                                return TPK_BAD_PARAMETER;
                }

                /* set MTP to "not connect mode" */
                if ((tpout_src != TPK_TP_MTP_TO_TPOUT) && (pTp_drv->mtp[0].mtp_connect_type == MTP_TO_TPOUT)) {
                        pTp_drv->mtp[0].mtp_connect_type = MTP_NOT_CONNECT;
                }
                /* tpo bypass internal demod, set tpo input param,same as demod output param */
                if (tpout_src == TPK_IN_DEMOD_TO_TPOUT) {
                        TPK_TPOUT_TS_PARAM_T tpo_param;
                        Tp_TPO_GetMode(tpout_id, &tpo_param);
                        tpo_param.in_clk_pol = pTp_drv->tpi[TP_TPI_demod].clk_pol;
                        tpo_param.in_sync_pol = pTp_drv->tpi[TP_TPI_demod].sync_pol;
                        tpo_param.in_val_pol = pTp_drv->tpi[TP_TPI_demod].val_pol;
                        Tp_TPO_SetMode(tpout_id, tpo_param);
                }

                Tp_TPO_SetDataSource(src_type);

        }

        //save tpout source
        pTp_drv->tpout[tpout_id].tpout_src = tpout_src;

        if (pTp_drv->tpout[tpout_id].tpout_stream_status == TPOUT_STREAM_START) {
                Tp_TPO_StreamControl(tpout_id, TPOUT_STREAM_START);
        }

        _tp_unlock();

        TP_TRACE("exit, TPOUT%u set to tpout_src(%u)\n", tpout_id, pTp_drv->tpout[tpout_id].tpout_src);
        return TPK_SUCCESS;
}
EXPORT_SYMBOL(RHAL_TPOUTSetDataSource);


/*------------------------------------------------------------------
 * Func : RHAL_TPOUTStreamControl
 *
 * Desc : TP Out control
 *
 * Parm : [I] tpout_id : TP out Index
 *        [I] ctrl     : TP out countrl
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPOUTStreamControl(
        UINT8                   tpout_id,
        TPK_TPOUT_STREAM_CTRL_T ctrl
)
{
        CHECK_MAX_TPOUT_COUNT(tpout_id);

        CHECK_TP_STRUCTURE();

        tp_mask_print_emerg( TP_LOG_BLOCK_ALL, TP_LOG_LEVEL_WARNING, "RHAL_TPOUTStreamControl Enter, tpout_id=%d, ctrl=%u\n", tpout_id, ctrl);

        if ((ctrl != TPOUT_STREAM_START) && (ctrl != TPOUT_STREAM_STOP)) {
                TP_WARNING("ctrl=%u\n", ctrl);
                return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        if (pTp_drv->tpout[tpout_id].tpout_stream_status == ctrl) {
                _tp_unlock();
                return TPK_SUCCESS;
        }
        Tp_TPO_StreamControl(tpout_id, ctrl);

        pTp_drv->tpout[tpout_id].tpout_stream_status = ctrl;

        _tp_unlock();

        tp_mask_print_emerg( TP_LOG_BLOCK_ALL, TP_LOG_LEVEL_WARNING, "RHAL_TPOUTStreamControl exit, tpout_id=%d, ctrl=%u\n", tpout_id, ctrl);
        TP_TRACE("exit, TPOUT%u ctrl=%u\n", tpout_id, ctrl);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_TPOUTStreamControl);


/*------------------------------------------------------------------
 * Func : RHAL_TPOUTClockSpeed
 *
 * Desc : Set TP Out Clock Speed
 *
 * Parm : [I] tpout_id : TP out Index
 *        [I] pre_div     : TP clock pre div
 *        [I] post_div    : TP clock post div
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPOUTClockSpeed(
        UINT8                   tpout_id,
        UINT32                  pre_div,
        UINT32                  post_div
)
{
        CHECK_MAX_TPOUT_COUNT(tpout_id);

        CHECK_TP_STRUCTURE();

        _tp_lock();

        Tp_TPO_SetClkDiv(pre_div, post_div);

        _tp_unlock();

        TP_TRACE("exit, TPOUT%u pre_div=%u post_div=%u\n", tpout_id, pre_div, post_div);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_TPOUTClockSpeed);


/*------------------------------------------------------------------
 * Func : RHAL_SetMTPBuffer
 *
 * Desc : Set MTP Buffer
 *
 * Parm : [I] mtp_id   : MTP Index
 *        [I] pPhyAddr : start address of MTP buffer
 *        [I] size     : size of MTP burrer
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_SetMTPBuffer(
        TPK_TP_MTP_T      mtp_id,
        UINT8*            pPhyAddr,
        UINT8*            pVirAddr,
        UINT32            size)
{
        TPK_MTP_BUF_T *pMtpBufParam;

        REGADDR m2m_limit_reg;
        REGADDR m2m_base_reg;
        REGADDR m2m_rp_reg;
        REGADDR m2m_wp_reg;

        UINT8 is_mtp_running = 0;

        switch (mtp_id) {
                case TP_TP0_MTP:
                        m2m_limit_reg = TP_TP0_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP0_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP0_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP0_M2M_RING_WP_reg;
                        break;
                case TP_TP1_MTP:
                        m2m_limit_reg = TP_TP1_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP1_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP1_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP1_M2M_RING_WP_reg;
                        break;
                case TP_TP2_MTP:
                        m2m_limit_reg = TP_TP2_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP2_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP2_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP2_M2M_RING_WP_reg;
                        break;
                case TP_TP3_MTP:
                        m2m_limit_reg = TP_TP3_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP3_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP3_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP3_M2M_RING_WP_reg;
                        break;
                case TP_TPP0_MTP:
                        m2m_limit_reg = TP_TP0_P_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP0_P_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP0_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP0_P_M2M_RING_WP_reg;
                        break;
                case TP_TPP1_MTP:
                        m2m_limit_reg = TP_TP1_P_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP1_P_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP1_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP1_P_M2M_RING_WP_reg;
                        break;
                case TP_TPP2_MTP:
                        m2m_limit_reg = TP_TP2_P_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP2_P_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP2_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP2_P_M2M_RING_WP_reg;
                        break;
                default:
                        TP_WARNING("bad parameter (mtp_id=%u)\n", mtp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        CHECK_MTP_ID(mtp_id);
        CHECK_TP_STRUCTURE();

        if ((pPhyAddr == NULL) && (pVirAddr == NULL) && (size == 0)) {
                TP_WARNING("MTP%d: Bad parameter to set MTP buffer!(pPhyAddr=%p, size=%u\n", mtp_id, pPhyAddr, size);
                pTp_drv->mtp[mtp_id].valid = 0;
                return TPK_SUCCESS;
        }

        if(pPhyAddr == (UINT8*)pTp_drv->mtp[mtp_id].mtp_buf_param.BasePhy && (UINT8*)pTp_drv->mtp[mtp_id].mtp_buf_param.BaseVir == pVirAddr && pTp_drv->mtp[mtp_id].mtp_buf_param.BufSize == size && pTp_drv->mtp[mtp_id].valid == 1) {
                TP_WARNING("MTP:%d: buffer is the same, not need to set again pPhyAddr=0x%p pVirAddr=0x%p size=0x%x\n", mtp_id, pPhyAddr, pVirAddr, size);
                return TPK_SUCCESS;
        }

        TP_DBG("MTP%d: pPhyAddr=0x%p pVirAddr=0x%p size=0x%x\n", mtp_id, pPhyAddr, pVirAddr, size);

        _tp_lock();

        if (pTp_drv->mtp[mtp_id].mtp_stream_status == MTP_STREAM_START) {
                TP_WARNING("MTP%d: stream is running now, set mtp buffer\n", mtp_id);
                is_mtp_running = 1;
        }

        if(is_mtp_running == 1)
                TP_MTPStreamControl(mtp_id, MTP_STREAM_STOP);

        /* save data into structure */
        pTp_drv->mtp[mtp_id].mtp_buf_param.BasePhy  = (UADDRESS)pPhyAddr;
        pTp_drv->mtp[mtp_id].mtp_buf_param.BaseVir  = (UADDRESS)pVirAddr;
        pTp_drv->mtp[mtp_id].mtp_buf_param.BufSize  = size;
        pTp_drv->mtp[mtp_id].mtp_buf_param.LimitPhy = (UADDRESS)pPhyAddr + size;
        pTp_drv->mtp[mtp_id].mtp_buf_param.RP       = (UADDRESS)pPhyAddr;
        pTp_drv->mtp[mtp_id].mtp_buf_param.WP       = (UADDRESS)pPhyAddr;
        pTp_drv->mtp[mtp_id].mtp_buf_param.inited   = 1;
        pTp_drv->mtp[mtp_id].valid = 1;

        /* set m2m memory dma parameter */
        pMtpBufParam = &pTp_drv->mtp[mtp_id].mtp_buf_param;
        WRITE_REG32(m2m_limit_reg, pMtpBufParam->LimitPhy);
        WRITE_REG32(m2m_base_reg, pMtpBufParam->BasePhy);

        pMtpBufParam->RP = pMtpBufParam->WP = pMtpBufParam->BasePhy;
        WRITE_REG32(m2m_rp_reg, pMtpBufParam->RP);
        WRITE_REG32(m2m_wp_reg, pMtpBufParam->WP);

        /* set a reasonable value to MTP0 to avoid MTP0 invalid read while in_go=1 -> in_go=0 */
        if (pTp_drv->mtp[0].valid == 0) {
                WRITE_REG32(TP_TP0_M2M_RING_LIMIT_reg, pMtpBufParam->LimitPhy);
                WRITE_REG32(TP_TP0_M2M_RING_BASE_reg, pMtpBufParam->BasePhy);
                WRITE_REG32(TP_TP0_M2M_RING_RP_reg, pMtpBufParam->RP);
                WRITE_REG32(TP_TP0_M2M_RING_WP_reg, pMtpBufParam->WP);
        }

        if(is_mtp_running == 1)
                TP_MTPStreamControl(mtp_id, MTP_STREAM_START);

        _tp_unlock();

        TP_TRACE("exit, MTP%d: pPhyAddr=%p, size=%u\n", mtp_id, pPhyAddr, size);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_SetMTPBuffer);



/*------------------------------------------------------------------
 * Func : RHAL_MTPStreamControl
 *
 * Desc : MTP Streaming Control
 *
 * Parm : [I] mtp_id : MTP Index
 *        [I] ctrl   : MTP control
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_MTPStreamControl(
        TPK_TP_MTP_T          mtp_id,
        TPK_MTP_STREAM_CTRL_T ctrl)
{

#if 0
        UINT8 i;

        for (i = 0; i < MAX_TP_COUNT; i++) {
                if (pTp_drv->tp[i].tp_src == MTP) {
                        break;
                }
        }
#endif

        INT32 ret;

        CHECK_MTP_ID(mtp_id);
        CHECK_TP_STRUCTURE();

        if ((ctrl != MTP_STREAM_START) && (ctrl != MTP_STREAM_STOP)) {
                TP_WARNING("bad parameter of %s mtp_id = %u, ctrl = %u\n", __func__, mtp_id, ctrl);
                return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        CHECK_MTP_BUF_VALID(mtp_id);

        if (pTp_drv->mtp[mtp_id].mtp_stream_status == ctrl) {
                _tp_unlock();

                TP_WARNING("MTP%d: stream start already\n", mtp_id);

                return TPK_SUCCESS;
        }

        ret = TP_MTPStreamControl(mtp_id, ctrl);

        _tp_unlock();

        TP_DBG("MTP%d: stream status = %u ret=%d\n", mtp_id, ctrl, ret);
        if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_MTP) ) {
                TP_DBG("MTP%d: stream status = %u ret=%d\n", mtp_id, ctrl, ret);
        }
        return ret;
}

EXPORT_SYMBOL(RHAL_MTPStreamControl);



/*------------------------------------------------------------------
 * Func : RHAL_WriteMTPBuffer
 *
 * Desc : Write MTP Buffer
 *
 * Parm : [I] mtp_id : MTP Index
 *        [I] pPhyWP : Write pointer
 *        [I] ContinueWrite : Continuout Write pointer
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_WriteMTPBuffer(
        TPK_TP_MTP_T        mtp_id,
        UINT8*              pPhyWP,
        UINT32              ContinueWrite)
{
        TPK_MTP_BUF_T *pBuf_param;
        UADDRESS new_wp;
        int i;
        UINT32 now_timestamp;
        UINT8 *p_now_timestamp;
        TP_BUFFER_PARAM_T ring_buf;
        unsigned char* pucWritePtr1;

        REGADDR m2m_rp_reg;
        REGADDR m2m_wp_reg;
#if 0
        UINT8 i;

        for (i = 0; i < MAX_TP_COUNT; i++) {
                if (pTp_drv->tp[i].tp_src == MTP) {
                        break;
                }
        }
#endif

        switch (mtp_id) {
                case TP_TP0_MTP:
                        m2m_rp_reg    = TP_TP0_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP0_M2M_RING_WP_reg;
                        break;
                case TP_TP1_MTP:
                        m2m_rp_reg    = TP_TP1_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP1_M2M_RING_WP_reg;
                        break;
                case TP_TP2_MTP:
                        m2m_rp_reg    = TP_TP2_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP2_M2M_RING_WP_reg;
                        break;
                case TP_TP3_MTP:
                        m2m_rp_reg    = TP_TP3_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP3_M2M_RING_WP_reg;
                        break;
                case TP_TPP0_MTP:
                        m2m_rp_reg    = TP_TP0_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP0_P_M2M_RING_WP_reg;
                        break;
                case TP_TPP1_MTP:
                        m2m_rp_reg    = TP_TP1_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP1_P_M2M_RING_WP_reg;
                        break;
                case TP_TPP2_MTP:
                        m2m_rp_reg    = TP_TP2_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP2_P_M2M_RING_WP_reg;
                        break;
                default:
                        TP_WARNING("bad parameter (mtp_id=%u)\n", mtp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        CHECK_MTP_ID(mtp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        new_wp = (UADDRESS)pPhyWP + ContinueWrite;
        pBuf_param = &pTp_drv->mtp[mtp_id].mtp_buf_param;

        if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_MTP) ) {
                Tp_Get_MTP_Buffer(mtp_id, &ring_buf);
                pucWritePtr1 = (unsigned char*)(pBuf_param->BaseVir + ((UADDRESS)ring_buf.RP - pBuf_param->BasePhy));
                TP_DBG_SIMPLE("MTP%d: %02x%02x%02x%02x pPhyWP=0x%x v=0x%x p=0x%x\n", mtp_id, pucWritePtr1[0], pucWritePtr1[1], pucWritePtr1[2], pucWritePtr1[3], pPhyWP, pucWritePtr1, ring_buf.RP);
        }

        CHECK_MTP_BUF_VALID(mtp_id);

        if(pTp_drv->mtp[mtp_id].mtp_stream_status != MTP_STREAM_START) {
                _tp_unlock();
                TP_WARNING("MTP%d: stream did not start yet\n", mtp_id);
                return TPK_NOT_SET;
        }

        pBuf_param->RP = READ_REG32(m2m_rp_reg);

        if (((UADDRESS)pPhyWP < pBuf_param->BasePhy) ||
            ((UADDRESS)pPhyWP >= pBuf_param->LimitPhy)) {
                _tp_unlock();

                TP_WARNING("MTP%d: invalid wp %p - out of boundrary (0x%x ~ 0x%x) \n",
                           mtp_id, pPhyWP, pBuf_param->BasePhy, pBuf_param->LimitPhy);

                return TPK_DATA_OUT_OF_RANGE;
        }

        if ((UADDRESS)pPhyWP != pBuf_param->WP) {
                _tp_unlock();

                TP_WARNING("MTP%d: wp not sync (input wp=%p / wp rec=0x%x)\n",
                           mtp_id, pPhyWP, pBuf_param->WP);

                return TPK_RESOURCE_CONFLICT;
        }

        if ((new_wp < pBuf_param->BasePhy) ||
            (new_wp > pBuf_param->LimitPhy)) {
                _tp_unlock();

                TP_WARNING("MTP%d: new wp 0x%08x - out of boundrary (0x%x ~ 0x%x) \n",
                           mtp_id, new_wp, pBuf_param->BasePhy, pBuf_param->LimitPhy);

                return TPK_DATA_OUT_OF_RANGE;
        }

        if (new_wp == pBuf_param->LimitPhy)
                new_wp = pBuf_param->BasePhy;

        /* MTP for TP */
        if ((mtp_id >= TP_TP0_MTP) && (mtp_id <= TP_TP3_MTP) && (pTp_drv->tp[mtp_id].tp_param.ts_in_tsp_len == byte_192)) {
                unsigned char* pucWritePtr;

                pucWritePtr = (unsigned char*)(pBuf_param->BaseVir + ((UADDRESS)pPhyWP - pBuf_param->BasePhy));

#ifndef TP_VERIFY_ENABLE

                for(i = 0; i < ContinueWrite; i = i + 192) {
                        p_now_timestamp = (UINT8*)&now_timestamp;
                        p_now_timestamp[0] = pucWritePtr[3 + i];
                        p_now_timestamp[1] = pucWritePtr[2 + i];
                        p_now_timestamp[2] = pucWritePtr[1 + i];
                        p_now_timestamp[3] = pucWritePtr[0 + i];

                        if(pTp_drv->mtp[mtp_id].first_tsp == 1) {
                                pTp_drv->mtp[mtp_id].last_timestamp = now_timestamp;
                                pTp_drv->mtp[mtp_id].first_tsp = 0;
                        }

                        if( now_timestamp < pTp_drv->mtp[mtp_id].last_timestamp) {
                                // timestamp max value => 4294967100(0xFFFFFF3C)    timestamp max value div 300 => 14316557(0xDA740D)
                                if( (pTp_drv->mtp[mtp_id].last_timestamp - now_timestamp) >= 0xDA0000) {
                                        pTp_drv->mtp[mtp_id].timestmp_offset = pTp_drv->mtp[mtp_id].timestmp_offset + 14316557;
                                        TP_DBG("MTP%d: timestamp wrap around new=0x%x old=0x%x\n", mtp_id, now_timestamp, pTp_drv->mtp[mtp_id].last_timestamp);
                                } else {
                                        if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_MTP) ) {
                                                TP_DBG("MTP%d: timestamp wrap around new=0x%x old=0x%x, diff value is small, not need to add offset\n", mtp_id, now_timestamp, pTp_drv->mtp[mtp_id].last_timestamp);
                                        }
                                }
                        }
                        pTp_drv->mtp[mtp_id].last_timestamp = now_timestamp;
                        now_timestamp = now_timestamp + pTp_drv->mtp[mtp_id].timestmp_offset;
                        pucWritePtr[3 + i] = p_now_timestamp[0];
                        pucWritePtr[2 + i] = p_now_timestamp[1];
                        pucWritePtr[1 + i] = p_now_timestamp[2];
                        pucWritePtr[0 + i] = p_now_timestamp[3];
                }
#endif

                dmac_flush_range(pucWritePtr, pucWritePtr + ContinueWrite);
                outer_flush_range((UADDRESS)pPhyWP, (UADDRESS)pPhyWP + ContinueWrite);

#if 0
                for(i = 0; i < ContinueWrite; i = i + 192) {
                        if(pucWritePtr[5 + i] == 0x40 && pucWritePtr[6 + i] == 0x65) {
                                now_timestamp = pucWritePtr[0 + i] << 24 | pucWritePtr[1 + i] << 16 | pucWritePtr[2 + i] << 8 | pucWritePtr[3 + i];
                                TP_DBG("%02x%02x%02x%02x\n", pucWritePtr[0 + i], pucWritePtr[1 + i], pucWritePtr[2 + i], pucWritePtr[3 + i]);
                        }
                }
#endif
        }/* MTP for TPP */
        else {
                unsigned char* pucWritePtr;
                pucWritePtr = (unsigned char*)(pBuf_param->BaseVir + ((UINT32)pPhyWP - pBuf_param->BasePhy));
                dmac_flush_range(pucWritePtr, pucWritePtr + ContinueWrite);
                outer_flush_range(pPhyWP, pPhyWP + ContinueWrite);
        }

        /* record ts */
        if (rec_mtp_fd && ContinueWrite) {
                unsigned char* pucWritePtr;
                mm_segment_t old_fs;

                pucWritePtr = (unsigned char*)(pBuf_param->BaseVir + ((UADDRESS)pPhyWP - pBuf_param->BasePhy));
                old_fs = get_fs();
                set_fs(KERNEL_DS);
                rtk_inv_range((void *)pucWritePtr, (void *)((UADDRESS)pucWritePtr + ContinueWrite));
                vfs_write(rec_mtp_fd, pucWritePtr, ContinueWrite, &rec_mtp_fd->f_pos);
                set_fs(old_fs);
        }


        if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_MTP) ) {
                TP_DBG_SIMPLE("MTP%d: ->%02x%02x%02x%02x pPhyWP=0x%x v=0x%x p=0x%x\n", mtp_id, pucWritePtr1[0], pucWritePtr1[1], pucWritePtr1[2], pucWritePtr1[3], pPhyWP, pucWritePtr1, ring_buf.RP);
        }
        WRITE_REG32(m2m_wp_reg, new_wp);

        pBuf_param->WP = new_wp;

        pTp_drv->mtp[mtp_id].mtp_write_data_cnt += ContinueWrite;

        _tp_unlock();

        TP_TRACE("MTP%d: pPhyWP = %p, Len=%u\n", mtp_id, pPhyWP, ContinueWrite);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_WriteMTPBuffer);



/*------------------------------------------------------------------
 * Func : RHAL_GetMTPBufferStatus
 *
 * Desc : Get MTP Buffer Status
 *
 * Parm : [I] mtp_id : MTP Index
 *        [O] ppWritePhyPtr : write able physical address
 *        [O] pContinueWriteSize : size of writeable region
 *        [O] pWritableSize : size of total writeable region
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_GetMTPBufferStatus(
        TPK_TP_MTP_T      mtp_id,
        UINT8**           ppWritePhyPtr,
        UINT32*           pContinueWriteSize,
        UINT32*           pWritableSize)
{
        UINT32 block_size;
        TPK_MTP_BUF_T *pBuf_param;

        REGADDR m2m_rp_reg;
#if 0
        UINT8 i;

        for (i = 0; i < MAX_TP_COUNT; i++) {
                if (pTp_drv->tp[i].tp_src == MTP) {
                        break;
                }
        }
#endif
        if (pTp_drv->tp[mtp_id].tp_param.ts_in_tsp_len == byte_192 )
                block_size = 192*2;
        else
                block_size = 188*2;

        switch (mtp_id) {
                case TP_TP0_MTP:
                        m2m_rp_reg = TP_TP0_M2M_RING_RP_reg;
                        break;
                case TP_TP1_MTP:
                        m2m_rp_reg = TP_TP1_M2M_RING_RP_reg;
                        break;
                case TP_TP2_MTP:
                        m2m_rp_reg = TP_TP2_M2M_RING_RP_reg;
                        break;
                case TP_TP3_MTP:
                        m2m_rp_reg = TP_TP3_M2M_RING_RP_reg;
                        break;
                case TP_TPP0_MTP:
                        m2m_rp_reg = TP_TP0_P_M2M_RING_RP_reg;
                        break;
                case TP_TPP1_MTP:
                        m2m_rp_reg = TP_TP1_P_M2M_RING_RP_reg;
                        break;
                case TP_TPP2_MTP:
                        m2m_rp_reg = TP_TP2_P_M2M_RING_RP_reg;
                        break;
                default:
                        TP_WARNING("bad parameter of %s (mtp_id=%d)\n", __func__, mtp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        CHECK_MTP_ID(mtp_id);
        CHECK_TP_STRUCTURE();

        if ((ppWritePhyPtr == NULL) || (pContinueWriteSize == NULL) || (pWritableSize == NULL)) {
                TP_WARNING("MTP%d: ppWritePhyPtr = %p, pContinueWriteSize = %p, pWritableSize = %p\n",
                           mtp_id, ppWritePhyPtr, pContinueWriteSize, pWritableSize);
                return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        pBuf_param = &pTp_drv->mtp[mtp_id].mtp_buf_param;

        CHECK_MTP_BUF_VALID(mtp_id);

        if(pTp_drv->mtp[mtp_id].mtp_stream_status != MTP_STREAM_START) {
                *pContinueWriteSize = 0;
                *pWritableSize      = 0;
                _tp_unlock();
                return TPK_SUCCESS;
        }

        pBuf_param->RP = READ_REG32(m2m_rp_reg);

        *ppWritePhyPtr = (UINT8*)pBuf_param->WP;

        if (pBuf_param->WP >= pBuf_param->RP) {
                *pContinueWriteSize = pBuf_param->LimitPhy - pBuf_param->WP;

                /* make sure that more than 376 bytes left */
                if ((pBuf_param->RP - pBuf_param->BasePhy) < block_size)
                        *pContinueWriteSize = (*pContinueWriteSize > block_size) ? *pContinueWriteSize - block_size : 0;

                if ((pBuf_param->RP - pBuf_param->BasePhy) < block_size) {
                        *pWritableSize = *pContinueWriteSize;
                } else {
                        *pWritableSize = *pContinueWriteSize + (pBuf_param->RP - pBuf_param->BasePhy - block_size);
                }

        } else {
                *pContinueWriteSize = pBuf_param->RP - pBuf_param->WP;

                /* make sure that more than 376 bytes left */
                *pContinueWriteSize = (*pContinueWriteSize > block_size) ? *pContinueWriteSize - block_size : 0;

                *pWritableSize = *pContinueWriteSize;
        }
        _tp_unlock();

        TP_TRACE("MTP%d: pWritePhyPtr = %p, ContinueWriteSize=%u\n",
                 mtp_id, *ppWritePhyPtr, *pContinueWriteSize);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_GetMTPBufferStatus);



/*------------------------------------------------------------------
 * Func : RHAL_MTPFlushBuffer
 *
 * Desc :
 *
 * Parm : [I] id : TP Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_MTPFlushBuffer(IN TPK_TP_MTP_T mtp_id, IN MTP_BUFF_FLUSH_MODE_T mode)
{
        TPK_MTP_BUF_T *pBuf_param;
        tp_tp0_m2m_ring_ctrl_RBUS m2m_ctrl;

        REGADDR m2m_ctrl_reg;
        REGADDR m2m_rp_reg;
        REGADDR m2m_wp_reg;
#if 0
        UINT8 i;

        for (i = 0; i < MAX_TP_COUNT; i++) {
                if (pTp_drv->tp[i].tp_src == MTP) {
                        break;
                }
        }
#endif

        switch (mtp_id) {
                case TP_TP0_MTP:
                        m2m_ctrl_reg  = TP_TP0_M2M_RING_CTRL_reg;
                        m2m_rp_reg    = TP_TP0_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP0_M2M_RING_WP_reg;
                        break;
                case TP_TP1_MTP:
                        m2m_ctrl_reg  = TP_TP1_M2M_RING_CTRL_reg;
                        m2m_rp_reg    = TP_TP1_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP1_M2M_RING_WP_reg;
                        break;
                case TP_TP2_MTP:
                        m2m_ctrl_reg  = TP_TP2_M2M_RING_CTRL_reg;
                        m2m_rp_reg    = TP_TP2_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP2_M2M_RING_WP_reg;
                        break;
                case TP_TP3_MTP:
                        m2m_ctrl_reg  = TP_TP3_M2M_RING_CTRL_reg;
                        m2m_rp_reg    = TP_TP3_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP3_M2M_RING_WP_reg;
                        break;
                case TP_TPP0_MTP:
                        m2m_ctrl_reg  = TP_TP0_P_M2M_RING_CTRL_reg;
                        m2m_rp_reg    = TP_TP0_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP0_P_M2M_RING_WP_reg;
                        break;
                case TP_TPP1_MTP:
                        m2m_ctrl_reg  = TP_TP1_P_M2M_RING_CTRL_reg;
                        m2m_rp_reg    = TP_TP1_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP1_P_M2M_RING_WP_reg;
                        break;
                case TP_TPP2_MTP:
                        m2m_ctrl_reg  = TP_TP2_P_M2M_RING_CTRL_reg;
                        m2m_rp_reg    = TP_TP2_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP2_P_M2M_RING_WP_reg;
                        break;
                default:
                        TP_WARNING("bad parameter (mtp_id=%u)\n", mtp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        CHECK_MTP_ID(mtp_id);
        CHECK_TP_STRUCTURE();

        if ((mode != MTP_BUFF_FLUSH_TO_BASE) &&
            (mode != MTP_BUFF_FLUSH_TO_RP) &&
            (mode != MTP_BUFF_FLUSH_TO_WP)) {
                TP_WARNING("MTP%d: mode=%u\n", mtp_id, mode);
                return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        pBuf_param     = &pTp_drv->mtp[mtp_id].mtp_buf_param;
        pBuf_param->RP = READ_REG32(m2m_rp_reg);

        CHECK_MTP_BUF_VALID(mtp_id);

        if (pTp_drv->mtp[mtp_id].mtp_stream_status == MTP_STREAM_START) {
                /* stop MM buffer first */
                m2m_ctrl.regValue   = 0;
                m2m_ctrl.in_go      = 1;
                m2m_ctrl.write_data = 0;
                WRITE_REG32(m2m_ctrl_reg, m2m_ctrl.regValue);
        }

        udelay(100); // must wait over 1us then write rp ,wp because we set in_go in mtp.

        switch(mode) {
                case MTP_BUFF_FLUSH_TO_BASE:
                        pBuf_param->RP = pBuf_param->BasePhy;
                        WRITE_REG32(m2m_rp_reg, pBuf_param->RP);

                        pBuf_param->WP = pBuf_param->BasePhy;
                        WRITE_REG32(m2m_wp_reg, pBuf_param->WP);
                        break;

                case MTP_BUFF_FLUSH_TO_RP:
                        pBuf_param->WP = pBuf_param->RP;
                        WRITE_REG32(m2m_wp_reg, pBuf_param->WP);
                        break;

                case MTP_BUFF_FLUSH_TO_WP:
                        pBuf_param->RP = pBuf_param->WP;
                        WRITE_REG32(m2m_rp_reg, pBuf_param->RP);
                        break;
        }

        if (pTp_drv->mtp[mtp_id].mtp_stream_status == MTP_STREAM_START) {
                /* start MM buffer again */
                m2m_ctrl.regValue   = 0;
                m2m_ctrl.in_go      = 1;
                m2m_ctrl.write_data = 1;
                WRITE_REG32(m2m_ctrl_reg, m2m_ctrl.regValue);
        }

        udelay(10); // must wait over 1us then write rp ,wp because we set in_go in mtp.

        _tp_unlock();

        TP_TRACE("MTP%d: mode = %u\n", mtp_id, mode);
        if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_MTP) ) {
                TP_DBG("MTP_ID[%u] mode = %u\n", mtp_id, mode);
        }

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_MTPFlushBuffer);

/*------------------------------------------------------------------
 * Func : RHAL_MTPFrameControl
 *
 * Desc :
 *
 * Parm : [I] id : TP Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_MTPFrameControl(IN TPK_TP_MTP_T mtp_id, IN UINT8 enable)
{
        INT32 ret = TPK_SUCCESS;

        UINT8  bock_size;

        REGADDR m2m_ctrl_reg;
        REGADDR tp_m2m_ring_rp_reg;

        tp_fr_ctrl_RBUS fr_ctrl;
        tp_tp0_m2m_ring_ctrl_RBUS m2m_ctrl;

        TP_BUFFER_PARAM_T mtp_buff;


        TP_TRACE("Enter, mtp_id=%d, enable=%u\n", mtp_id, enable);
        tp_mask_print_emerg( TP_LOG_BLOCK_ALL, TP_LOG_LEVEL_WARNING, "RHAL_MTPFrameControl Enter, mtp_id=%d, enable=%u\n", mtp_id, enable);

        CHECK_MTP_ID(mtp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        ret = Tp_init(mtp_id);

        if (ret != TPK_SUCCESS) {
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                _tp_unlock();
                return ret;
        }

#if 0
        if(pTp_drv->mtp[mtp_id].mtp_stream_status == MTP_STREAM_START && enable == 1) {
                _tp_unlock();
                return TPK_SUCCESS;
        }
#endif  //  #if 0

        switch (mtp_id) {
                case TP_TP0_MTP:
                        m2m_ctrl_reg  = TP_TP0_M2M_RING_CTRL_reg;
                        tp_m2m_ring_rp_reg = TP_TP0_M2M_RING_RP_reg;
                        break;
                case TP_TP1_MTP:
                        m2m_ctrl_reg  = TP_TP1_M2M_RING_CTRL_reg;
                        tp_m2m_ring_rp_reg = TP_TP1_M2M_RING_RP_reg;
                        break;
                case TP_TP2_MTP:
                        m2m_ctrl_reg  = TP_TP2_M2M_RING_CTRL_reg;
                        tp_m2m_ring_rp_reg = TP_TP2_M2M_RING_RP_reg;
                        break;
                case TP_TP3_MTP:
                        m2m_ctrl_reg  = TP_TP3_M2M_RING_CTRL_reg;
                        tp_m2m_ring_rp_reg = TP_TP3_M2M_RING_RP_reg;
                        break;
                default:
                        TP_WARNING("bad parameter (mtp_id=%u)\n", mtp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        if(pTp_drv->mtp[mtp_id].mtp_stream_status == MTP_STREAM_START && enable == 1) {
                m2m_ctrl.regValue = 0;
                m2m_ctrl.in_go    = 0;
                Tp_Write_Data_Reg_Write(m2m_ctrl_reg, m2m_ctrl.regValue);
        }

        /* frame rate control */
        /* TP will check 4 bytes debug info in the front of TSP when file playback */
        switch(mtp_id) {
                case TP_TP0_MTP:
                        fr_ctrl.regValue = READ_REG32(TP_FR_CTRL_reg);
                        fr_ctrl.tp0_en   = enable ? 1 : 0;
                        WRITE_REG32(TP_FR_CTRL_reg, fr_ctrl.regValue);
                        break;

                case TP_TP1_MTP:
                        fr_ctrl.regValue = READ_REG32(TP_FR_CTRL_reg);
                        fr_ctrl.tp1_en   = enable ? 1 : 0;
                        WRITE_REG32(TP_FR_CTRL_reg, fr_ctrl.regValue);
                        break;

                case TP_TP2_MTP:
                        fr_ctrl.regValue = READ_REG32(TP_FR_CTRL_reg);
                        fr_ctrl.tp2_en   = enable ? 1 : 0;
                        WRITE_REG32(TP_FR_CTRL_reg, fr_ctrl.regValue);
                        break;

                case TP_TP3_MTP:
                        fr_ctrl.regValue = READ_REG32(TP_FR_CTRL_reg);
                        fr_ctrl.tp3_en   = enable ? 1 : 0;
                        WRITE_REG32(TP_FR_CTRL_reg, fr_ctrl.regValue);
                        break;

                default:
                        TP_WARNING("unsupported mtp_id=%d\n", mtp_id);
                        ret = TPK_BAD_PARAMETER;
        }

        if(pTp_drv->mtp[mtp_id].mtp_stream_status == MTP_STREAM_START && enable == 1) {
                /* check mtp buffer alignment */
                /* RP will shift from timestamp to sync byte, need to realign, otherwise in_go fail */
                if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_MTP) ) {
                        TPK_MTP_BUF_T *pBuf_param;
                        unsigned char* pucWritePtr1;
                        TP_BUFFER_PARAM_T ring_buf;
                        pBuf_param = &pTp_drv->mtp[mtp_id].mtp_buf_param;
                        Tp_Get_MTP_Buffer(mtp_id, &ring_buf);
                        pucWritePtr1 = (unsigned char*)(pBuf_param->BaseVir + ((UADDRESS)ring_buf.RP - pBuf_param->BasePhy));
                        TP_DBG_SIMPLE("MTP%d: start v=0x%x p_rp=0x%x p_wp=0x%x\n", mtp_id, pucWritePtr1, ring_buf.RP, ring_buf.WP);
                }
                bock_size = pTp_drv->tp[mtp_id].mass_buffer.bock_size;
                Tp_Get_MTP_Buffer(mtp_id, &mtp_buff);
                if ( (mtp_buff.RP - mtp_buff.Base) % bock_size ) {
                        TP_WARNING("MTP%d: RP is not alignem(RP=%p, Base=%p), realigned to RP=%p, block_size=%d\n",
                                   mtp_id, (void*)mtp_buff.RP, (void*)mtp_buff.Base, (void*)(mtp_buff.RP - ((mtp_buff.RP - mtp_buff.Base) % bock_size)), bock_size);
                        WRITE_REG32(tp_m2m_ring_rp_reg, (mtp_buff.RP - ((mtp_buff.RP - mtp_buff.Base) % bock_size)));
                }

                m2m_ctrl.regValue = 0;
                m2m_ctrl.in_go    = 1;
                Tp_Write_Data_Reg_Write(m2m_ctrl_reg, m2m_ctrl.regValue);
        }
        _tp_unlock();

        TP_TRACE("exit, MTP%d: enable=%u\n", mtp_id, enable);
        tp_mask_print_emerg( TP_LOG_BLOCK_ALL, TP_LOG_LEVEL_WARNING, "RHAL_MTPFrameControl Exit, mtp_id=%d, enable=%u\n", mtp_id, enable);
        if( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_MTP) ) {
                TP_DBG("exit, MTP%d: enable=%u\n", mtp_id, enable);
        }

        return ret;
}

EXPORT_SYMBOL(RHAL_MTPFrameControl);


/******************************

         PID filter

*******************************/
/*------------------------------------------------------------------
 * Func : RHAL_AddPIDFilter
 *
 * Desc : Add a PID Filter
 *
 * Parm : [I] id  : TP Index
 *        [I] PIDParam : which PID to be removed
 *        [I] file_handle : handle of PID
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_AddPIDFilter(
        TPK_TP_ENGINE_T         tp_id,
        TPK_PID_FILTER_PARAM_T  PIDParm,
        void                   *file_handle)
{
        INT32 ret;

        TP_TRACE("enter, tp_id= %d, PID=0x%x, descram_en=%u, keysel=%u, file_handle =%p\n",
                 tp_id, PIDParm.PID, PIDParm.DescrambleEn, PIDParm.valid, file_handle);

        CHECK_MAX_TP_COUNT(tp_id);

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }


        ret = Tp_AddPIDFilter(tp_id, PIDParm, file_handle);

        _tp_unlock();

        TP_TRACE("exit, tp_id= %d, PID=0x%x, descram_en=%u, keysel=%u, file_handle =%p, ret=%d\n",
                 tp_id, PIDParm.PID, PIDParm.DescrambleEn, PIDParm.valid, file_handle, ret);

        return ret;
}

EXPORT_SYMBOL(RHAL_AddPIDFilter);



/*------------------------------------------------------------------
 * Func : RHAL_RemovePIDFilter
 *
 * Desc : Remove a PID Filter
 *
 * Parm : [I] id  : TP Index
 *        [I] PID : which PID to be removed
 *        [I] file_handle : handle of PID
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_RemovePIDFilter(
        TPK_TP_ENGINE_T    tp_id,
        UINT16             PID,
        void*              file_handle)
{
        INT32 ret;

        CHECK_MAX_TP_COUNT(tp_id);

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();

                TP_WARNING("Call Tp_init() fail (%d)\n", ret);

                return ret;
        }

        ret = Tp_RemovePIDFilter(tp_id, PID, file_handle);

        _tp_unlock();

        TP_TRACE("exit, tp_id= %d, PID=0x%x, file_handle=%p\n",
                 tp_id, PID, file_handle);

        return ret;
}

EXPORT_SYMBOL(RHAL_RemovePIDFilter);



/*------------------------------------------------------------------
 * Func : RHAL_RemoveAllPIDFilters
 *
 * Desc : Remove all PID Filters
 *
 * Parm : [I] id : TP Index
 *        [I] file_handle : file handle of PID filter
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_RemoveAllPIDFilters(
        TPK_TP_ENGINE_T     tp_id,
        void*               file_handle
)
{
        UINT16 i;
        UINT16 j;
        UINT16 max_pid_cnt;
        INT32 ret;

        TP_TRACE("enter, tp_id=%d, file_handle =%p\n", tp_id, file_handle);

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        ret = Tp_Get_MaxPID_Cnt(tp_id, &max_pid_cnt);
        if (ret != TPK_SUCCESS) {
                TP_WARNING("call Tp_Get_MaxPID_Cnt return error\n");
                return ret;
        }

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        /* force to remove all pid filters without any condition */
        if (file_handle == REGARDLESS_OF_FILE_HANDLE) {
                _tp_unlock();

                /* remove all section filter first */
                RHAL_RemoveAllSectionFilters(tp_id, REGARDLESS_OF_FILE_HANDLE);

                _tp_lock();

                for(i = 0; i < max_pid_cnt; i++) {
                        ret = Tp_Remove_PID(tp_id, i);
                        if (ret != TPK_SUCCESS) {
                                TP_WARNING("remove PID register setting error\n");
                                goto PID_ERROR;
                        }

                        pTp_drv->tp_pid[tp_id].pid_file_handle_cnt[i] = 0;
                }

                memset(pTp_drv->tp_pid[tp_id].file_handle, 0, sizeof(void*)*MAX_PID_PER_TP * MAX_FILE_HANDLE_REC);

                /* it will also disable PCR tracking */
                pTp_drv->tp_pid[tp_id].pcr.enable = 0;

                TP_INFO("TP%u force to remove all pid filter recardless of file_handle\n", tp_id);
                goto PID_SUCCESS;
        }

        /* remove pid filter depends on file handle */
        for( i = 0; i < max_pid_cnt; i++) {
                /* check file handle on each pid filter */
                for( j = 0; j < MAX_FILE_HANDLE_REC; j++) {
                        if (pTp_drv->tp_pid[tp_id].file_handle[i][j] == file_handle)
                                break;
                }

                if (j < MAX_FILE_HANDLE_REC) {
                        pTp_drv->tp_pid[tp_id].file_handle[i][j] = NULL;
                        pTp_drv->tp_pid[tp_id].pid_file_handle_cnt[i]--;

                        /* remove PID register */
                        if (pTp_drv->tp_pid[tp_id].pid_file_handle_cnt[i] == 0) {
                                ret = Tp_Remove_PID(tp_id, i);
                                if (ret != TPK_SUCCESS) {
                                        TP_WARNING("remove PID register setting error\n");
                                        goto PID_ERROR;
                                }
                        }
                }
        }

PID_SUCCESS:

        _tp_unlock();

        TP_TRACE("exit, id = %d, file_handle =%p\n", tp_id, file_handle);

        return TPK_SUCCESS;

PID_ERROR:

        _tp_unlock();

        return ret;
}

EXPORT_SYMBOL(RHAL_RemoveAllPIDFilters);



/*------------------------------------------------------------------
 * Func : RHAL_GetPIDFilterStatus
 *
 * Desc : PID Filter status
 *
 * Parm : [I] id : TP Index
 *        [I] PID_Buf_Cnt : PID Buffer Count
 *        [O] pPIDParm  : PID Filter output
 *        [O] pPIDLen   : number of PID
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_GetPIDFilterStatus(
        TPK_TP_ENGINE_T         tp_id,
        UINT16                  PID_Buf_Cnt,
        TPK_PID_FILTER_PARAM_T *pPIDParm,
        UINT16                 *pPIDLen
)
{
        UINT16 i;
        UINT16 max_pid_cnt;
        UINT16 PIDParm_idx = 0;
        INT32 ret;

        if ((PID_Buf_Cnt == 0) ||
            (pPIDParm == NULL) ||
            (pPIDLen == NULL)) {
                TP_WARNING("bad parameter, id=%u, PID_Buf_Cnt=%u, pPIDParm=%p, pPIDLen=%p\n",
                           tp_id, PID_Buf_Cnt, pPIDParm, pPIDLen);

                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        ret = Tp_Get_MaxPID_Cnt(tp_id, &max_pid_cnt);
        if (ret != TPK_SUCCESS) {
                TP_WARNING("call Tp_Get_MaxPID_Cnt return error\n");
                return ret;
        }

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        /* only collect valid PID filter info */
        for(i = 0; i < max_pid_cnt; i++) {
                if ((pTp_drv->tp_pid[tp_id].pid_api_setting[i].valid) &&
                    (PIDParm_idx < PID_Buf_Cnt)) {
                        pPIDParm[PIDParm_idx] = pTp_drv->tp_pid[tp_id].pid_api_setting[i];
                        PIDParm_idx++;
                }
        }

        _tp_unlock();

        *pPIDLen = PIDParm_idx;

        TP_TRACE("return %u valid PID filter\n", PIDParm_idx);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_GetPIDFilterStatus);

/*------------------------------------------------------------------
 * Func : RHAL_EnablePIDFilter
 *
 * Desc : Set TP PID filter On/Off
 *
 * Parm : [I] id : TP ID
 *              [I] on : Enable PID filter or not
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/

INT32 RHAL_EnablePIDFilter(
        IN TPK_TP_ENGINE_T   tp_id,
        IN UINT8             on
)
{
        INT32 ret;
        tp_tp_tf0_cntl_RBUS tp_cntl;

        TP_TRACE("enter, tp_id=%u, on=%u\n", tp_id, on);

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        if (on) {
                tp_cntl.pid_en = 1; /* set select bit = 1 */
                Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, 1);
        } else {
                tp_cntl.pid_en = 1; /* set select bit =1 */
                Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, 0);

        }
        pTp_drv->tp[tp_id].tp_param.pid_filter_en = on;
        _tp_unlock();


        TP_TRACE("exit, tp_id= %u, on = %u\n", tp_id, on);

        return ret;

}

EXPORT_SYMBOL(RHAL_EnablePIDFilter);


/******************************

         Section filter

*******************************/
/*------------------------------------------------------------------
 * Func : RHAL_AddSectionFilter
 *
 * Desc : Add a section filter
 *
 * Parm : [I] id : TP Index
 *        [I] Param : Section filter parameter
 *        [I] pFileHandle : File handle
 *        [O] ppSecHandle : Section handle output
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_AddSectionFilter(
        TPK_TP_ENGINE_T          tp_id,
        TPK_SEC_FILTER_PARAM_T   Param,
        void                    *pFileHandle,
        void                   **ppSecHandle)
{
        INT32 ret;

        CHECK_MAX_TP_COUNT(tp_id);

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();

                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        /* _Dump_SectionFilter_Status(&Param); */

        ret = Tp_AddSecFilter(tp_id, Param, pFileHandle, ppSecHandle);

#if 0
        /*  hack for test */
        ret = Tp_PCRTrackingEnable(id, 1, 0x7d1, TP_LOCAL_90KHz);
#endif

        _tp_unlock();

        TP_TRACE("exit, TP%u, PID=0x%x, pSecHandle=%p, ret=%d\n",
                 tp_id, Param.PID, *ppSecHandle, ret);

        return ret;
}

EXPORT_SYMBOL(RHAL_AddSectionFilter);



/*------------------------------------------------------------------
 * Func : RHAL_RemoveSectionFilter
 *
 * Desc : Remove Section Filter
 *
 * Parm : [I] id          : TP Index
 *        [I] pSecHandle : Section handle
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_RemoveSectionFilter(
        TPK_TP_ENGINE_T     tp_id,
        void*               pSecHandle
)
{
        INT32 ret;

        CHECK_MAX_TP_COUNT(tp_id);

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();

                TP_WARNING("Call Tp_init() fail (%d)\n", ret);

                return ret;
        }

        ret = Tp_RemoveSectionFilter(tp_id, pSecHandle);

        _tp_unlock();

        TP_TRACE("exit, TP%u, pSecHandle=%p, ret=%d\n", tp_id, pSecHandle, ret);

        return ret;
}

EXPORT_SYMBOL(RHAL_RemoveSectionFilter);



/*------------------------------------------------------------------
 * Func : RHAL_RemoveAllSectionFilters
 *
 * Desc :
 *
 * Parm : [I] id : TP Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32  RHAL_RemoveAllSectionFilters(IN TPK_TP_ENGINE_T tp_id, IN void* file_handle)
{
        UINT16 i;
        INT32 ret;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();

                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        for( i = 0; i < MAX_SEC_COUNT; i++) {
                if (file_handle == REGARDLESS_OF_FILE_HANDLE) {
                        if ((pTp_drv->sec[i].valid) &&
                            (pTp_drv->sec[i].tp_id == tp_id)) {
                                ret = Tp_RemoveSectionFilter(tp_id, (void*)(&pTp_drv->sec[i]));
                                if (ret != TPK_SUCCESS) {
                                        TP_WARNING("remove section filter failed, id=%u, sec_idx=%u, file_handle=%p\n",
                                                   tp_id, i, file_handle);
                                        goto SEC_ERROR;
                                }
                        }
                } else {
                        if ((pTp_drv->sec[i].valid) &&
                            (pTp_drv->sec[i].tp_id == tp_id) &&
                            (pTp_drv->sec[i].file_handle == file_handle)) {
                                ret = Tp_RemoveSectionFilter(tp_id, (void*)(&pTp_drv->sec[i]));
                                if (ret != TPK_SUCCESS) {
                                        TP_WARNING("remove section filter failed, id=%u, sec_idx=%u, file_handle=%p\n",
                                                   tp_id, i, file_handle);
                                        goto SEC_ERROR;
                                }
                        }
                }
        }

        _tp_unlock();

        TP_TRACE("exit, TP%u, file_handle=%p\n", tp_id, file_handle);

        return TPK_SUCCESS;

SEC_ERROR:
        _tp_unlock();

        return ret;
}

EXPORT_SYMBOL(RHAL_RemoveAllSectionFilters);



/*------------------------------------------------------------------
 * Func : RHAL_GetSectionFilterStatus
 *
 * Desc : Get Section Filter Status
 *
 * Parm : [I] id : TP Index
 *        [I] Sec_Buf_cnt :
 *        [O] pSecStatus
 *        [O] usSecLen
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_GetSectionFilterStatus(
        TPK_TP_ENGINE_T              tp_id,
        UINT16                       Sec_Buf_cnt,
        TPK_SEC_FILTER_STATUS_T     *pSecStatus,
        UINT16                      *usSecLen
)
{
        UINT16 SecParm_idx = 0;
        UINT16 i;
        INT32 ret;

        if ((pSecStatus == NULL) || (Sec_Buf_cnt == 0)) {
                TP_WARNING("bad parameter, Sec_Buf_cnt=%u, pSecStatus=%p,usSecLen=%p\n",
                           Sec_Buf_cnt, pSecStatus, usSecLen);

                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        /* only collect valid section filter info */
        for( i = 0; i < MAX_SEC_COUNT; i++) {
                if ((pTp_drv->sec[i].valid) &&
                    (pTp_drv->sec[i].tp_id == tp_id) &&
                    (SecParm_idx < Sec_Buf_cnt)) {
                        pSecStatus[SecParm_idx] = pTp_drv->sec[i];
                        SecParm_idx++;
                }
        }

        _tp_unlock();

        *usSecLen = SecParm_idx;

        TP_TRACE("return %u valid Section filter\n", SecParm_idx);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_GetSectionFilterStatus);



/******************************

        PCR tracking

*******************************/

/*------------------------------------------------------------------
 * Func : RHAL_PCRTrackingEnable
 *
 * Desc : Enable PCR tracking
 *
 * Parm : [I] id      : TP Index
 *        [I] on      : 0 : disable, others : enable
 *        [I] PID     : value of PCR PID
 *        [I] clk_src : clock source of STC
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_PCRTrackingEnable(
        TPK_TP_ENGINE_T   tp_id,
        UINT8             on,
        UINT16            PID,
        TPK_PCR_CLK_SRC_T clk_src
)
{
        INT32 ret;

        TP_TRACE("enter, tp_id=%d, On=%u, PID=0x%x, clk_src=%u\n",
                 tp_id, on, PID, clk_src);

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        ret = Tp_PCRTrackingEnable(tp_id, on, PID, clk_src);

        _tp_unlock();

        TP_TRACE("exit, id = %d, on=%u, PID=0x%x, clk_src=%u, ret=%d\n",
                 tp_id, on, PID, clk_src, ret);

        return ret;
}

EXPORT_SYMBOL(RHAL_PCRTrackingEnable);



/*------------------------------------------------------------------
 * Func : RHAL_GetPCRTrackingStatus
 *
 * Desc : Get PCR Tracking Status
 *
 * Parm : [I] id       : TP Index
 *        [O] pPCR     : last PCR
 *        [O] pSTC     : last STC
 *        [O] pPCRBase : PCR base
 *        [O] pSTCBase : STC base
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_GetPCRTrackingStatus(
        TPK_TP_ENGINE_T     tp_id,
        UINT64*                 pPCR,
        OUT  UINT64*            pSTC,
        OUT  UINT64*            pPCRBase,
        OUT  UINT64*            pSTCBase
)
{
        INT32 ret;

        if ((pPCR == NULL) ||
            (pSTC == NULL) ||
            (pPCRBase == NULL) ||
            (pSTCBase == NULL)) {
                TP_WARNING("bad parameter, pPCR=%p, pSTC=%p,pPCRBase=%p,pSTCBase=%p\n",
                           pPCR , pSTC, pPCRBase, pSTCBase);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        ret = Tp_init(tp_id);
        if (ret != TPK_SUCCESS) {
                _tp_unlock();
                TP_WARNING("Call Tp_init() fail (%d)\n", ret);
                return ret;
        }

        ret = Tp_GetPCRTrackingStatus(tp_id, pPCR, pSTC, pPCRBase, pSTCBase);

        _tp_unlock();

        return ret;
}

EXPORT_SYMBOL(RHAL_GetPCRTrackingStatus);



/*------------------------------------------------------------------
 * Func : RHAL_ResetPCRTrackingStatus
 *
 * Desc : Reset PCR Tracking Status
 *
 * Parm : [I] id : TP Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_ResetPCRTrackingStatus(TPK_TP_ENGINE_T tp_id)
{
        INT32 ret;

        CHECK_MAX_TP_COUNT(tp_id);

        _tp_lock();

        ret = Tp_ResetPCRStatus(tp_id);

        _tp_unlock();

        return ret;
}

EXPORT_SYMBOL(RHAL_ResetPCRTrackingStatus);



/******************************

         Descrambler APIs

*******************************/
/*------------------------------------------------------------------
 * Func : RHAL_SetDescrambleAlgorithm
 *
 * Desc : Set TP's Descramble Algorithm
 *
 * Parm : [I] id   : TP Index
 *        [I] algo : Descamble algorithm
 *
 *            TPK_DESCRAMBLE_ALGO_DES_ECB_CLEAR : DES_ECB
 *            TPK_DESCRAMBLE_ALGO_TDES_ECB_CLEAR : TDES ECB
 *            ...
 *
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_SetDescrambleAlgorithm(
        TPK_TP_ENGINE_T                tp_id,
        TPK_DESCRAMBLE_ALGORITHM_T     algo
)
{
        tp_tp_tp0_des_cntl_RBUS des_ctrl;
        REGADDR tp_des_cntl_reg;
        static bool cw_init = false;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        if (algo.round > 256) {
                TP_WARNING("TP%u multi2 round(%u) over 256, not support\n",
                           tp_id, algo.round);
                return TPK_BAD_PARAMETER;
        }

        /* TP3 do not support descramble */
        switch(tp_id) {
                case TP_TP0:
                        tp_des_cntl_reg = TP_TP_TP0_DES_CNTL_reg;
                        break;
                case TP_TP1:
                        tp_des_cntl_reg = TP_TP_TP1_DES_CNTL_reg;
                        break;
                case TP_TP2:
                        tp_des_cntl_reg = TP_TP_TP2_DES_CNTL_reg;
                        break;
                default:
                        TP_WARNING("unsupported descrambler tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }


        des_ctrl.regValue = 0;
        des_ctrl.map_11   = DES_CNTL_MAP_ODD;
        des_ctrl.map_10   = DES_CNTL_MAP_EVEN;
        des_ctrl.map_01   = DES_CNTL_MAP_ODD;

        switch(algo.algo) {
                case TPK_DESCRAMBLE_ALGO_DES_ECB_CLEAR:
                        TP_INFO("TP%u Descramble Algorithm = DES ECB KEEP CLEAR\n", tp_id);
                        des_ctrl.mode     = DES_CNTL_MODE_DES;
                        des_ctrl.des_mode = DES_CNTL_DESMODE_ECB;
                        des_ctrl.ofb_mode = DES_CNTL_OFB_KEEP_CLEAR;

                        break;
                case TPK_DESCRAMBLE_ALGO_TDES_ECB_CLEAR:
                        TP_INFO("TP%u Descramble Algorithm = TDES ECB KEEP CLEAR\n", tp_id);
                        des_ctrl.mode     = DES_CNTL_MODE_TDES;
                        des_ctrl.des_mode = DES_CNTL_DESMODE_ECB;
                        des_ctrl.ofb_mode = DES_CNTL_OFB_DEFAULT;

                        break;
                case TPK_DESCRAMBLE_ALGO_TDES_CBC_OFB:
                        TP_INFO("TP%u Descramble Algorithm = TDES CBC OFB\n", tp_id);
                        des_ctrl.mode     = DES_CNTL_MODE_TDES;
                        des_ctrl.des_mode = DES_CNTL_DESMODE_CBC;
                        des_ctrl.ofb_mode = DES_CNTL_OFB_OFB;

                        break;
                case TPK_DESCRAMBLE_ALGO_CSA:
                        TP_INFO("TP%u Descramble Algorithm = CSA\n", tp_id);
                        des_ctrl.mode     = DES_CNTL_MODE_CSA;
                        des_ctrl.csa_mode = DES_CNTL_CSA_MODE_1;

                        break;
                case TPK_DESCRAMBLE_ALGO_CSA2:
                        TP_INFO("TP%u Descramble Algorithm = CSA2\n", tp_id);
                        des_ctrl.mode     = DES_CNTL_MODE_CSA;
                        des_ctrl.csa_mode = DES_CNTL_CSA_MODE_2;

                        break;
                case TPK_DESCRAMBLE_ALGO_CSA_RAW:
                        TP_INFO("TP%u Descramble Algorithm = CSA RAW\n", tp_id);
                        des_ctrl.mode     = DES_CNTL_MODE_CSA;
                        des_ctrl.csa_mode = DES_CNTL_CSA_MODE_ORIGINAL;

                        break;

                case TPK_DESCRAMBLE_ALGO_MULTI2:
                        TP_INFO("TP%u Descramble Algorithm = MULTI2 , Round=%u\n", tp_id, algo.round);
                        des_ctrl.ofb_mode	 = DES_CNTL_OFB_KEEP_CLEAR;
                        des_ctrl.mode		 = DES_CNTL_MODE_MULTI2;
                        des_ctrl.des_mode	 = DES_CNTL_DESMODE_CBC;
                        des_ctrl.multi2_mode = DES_CNTL_MULTI2_ALIGN63;
                        des_ctrl.round		 = algo.round - 1;						
                        break;

                case TPK_DESCRAMBLE_ALGO_MULTI2_OFB:
                        TP_INFO("TP%u Descramble Algorithm = MULTI2 OFB, Round=%u\n", tp_id, algo.round);
                        des_ctrl.ofb_mode    = DES_CNTL_OFB_DEFAULT;
                        des_ctrl.mode        = DES_CNTL_MODE_MULTI2;
                        des_ctrl.des_mode    = DES_CNTL_DESMODE_CBC;
                        des_ctrl.multi2_mode = DES_CNTL_MULTI2_ALIGN63;
                        des_ctrl.round       = algo.round - 1;

                        break;

                case TPK_DESCRAMBLE_ALGO_MULTI2_CBC:
                        TP_INFO("TP%u Descramble Algorithm = MULTI2 CBC, Round=%u\n", tp_id, algo.round);
                        des_ctrl.ofb_mode	 = DES_CNTL_OFB_DEFAULT;
                        des_ctrl.mode		 = DES_CNTL_MODE_MULTI2;
                        des_ctrl.des_mode	 = DES_CNTL_DESMODE_CBC;
                        des_ctrl.multi2_mode = DES_CNTL_MULTI2_ALIGN63;
                        des_ctrl.round		 = algo.round - 1;				
                        break;

                case TPK_DESCRAMBLE_ALGO_AES_128_CBC_CLEAR:
                        TP_INFO("TP%u Descramble Algorithm = AES 128 CBC KEEP CLEAR\n", tp_id);
                        des_ctrl.ofb_mode = DES_CNTL_OFB_KEEP_CLEAR;
                        des_ctrl.mode     = DES_CNTL_MODE_AES128_CBC;
                        des_ctrl.des_mode = DES_CNTL_DESMODE_CBC;

                        break;
                case TPK_DESCRAMBLE_ALGO_AES_128_ECB_CLEAR:
                        TP_INFO("TP%u Descramble Algorithm = AES 128 ECB KEEP CLEAR\n", tp_id);
                        des_ctrl.ofb_mode = DES_CNTL_OFB_KEEP_CLEAR;
                        des_ctrl.mode     = DES_CNTL_MODE_AES128_CBC;
                        des_ctrl.des_mode = DES_CNTL_DESMODE_ECB;

                        break;
                case TPK_DESCRAMBLE_ALGO_AES_RCBC_CS_CLEAR:
                        TP_INFO("TP%u Descramble Algorithm = AES RCBC CS KEEP CLEAR\n", tp_id);
                        des_ctrl.mode = DES_CNTL_MODE_AES128_RCBC_CS;
                        break;

                case TPK_DESCRAMBLE_ALGO_AES_128_CBC_OFB:
                case TPK_DESCRAMBLE_ALGO_AES_128_CBC_OFB_ATIS:
                        TP_INFO("TP%u Descramble Algorithm = AES 128 CBC OFB\n", tp_id);
                        des_ctrl.ofb_mode = DES_CNTL_OFB_OFB;
                        des_ctrl.mode     = DES_CNTL_MODE_AES128_CBC;
                        des_ctrl.des_mode = DES_CNTL_DESMODE_CBC;

                        break;

                case TPK_DESCRAMBLE_ALGO_CAM_ECB_CLEAR:
                        TP_INFO("TP%u Descramble Algorithm = CAM ECB KEEP CLEAR\n", tp_id);
                        des_ctrl.ofb_mode = DES_CNTL_OFB_KEEP_CLEAR;
                        des_ctrl.mode     = DES_CNTL_MODE_CAM;
                        des_ctrl.des_mode = DES_CNTL_DESMODE_ECB;
                        break;

                case TPK_DESCRAMBLE_ALGO_CAM_CBC_CLEAR:
                        TP_INFO("TP%u Descramble Algorithm = CAM ECB KEEP CLEAR\n", tp_id);
                        des_ctrl.ofb_mode = DES_CNTL_OFB_KEEP_CLEAR;
                        des_ctrl.mode     = DES_CNTL_MODE_CAM;
                        des_ctrl.des_mode = DES_CNTL_DESMODE_CBC;
                        break;

                case TPK_DESCRAMBLE_ALGO_CAM_CBC_OFB:
                        TP_INFO("TP%u Descramble Algorithm = CAM ECB KEEP CLEAR\n", tp_id);
                        des_ctrl.ofb_mode = DES_CNTL_OFB_OFB;
                        des_ctrl.mode     = DES_CNTL_MODE_CAM;
                        des_ctrl.des_mode = DES_CNTL_DESMODE_CBC;
                        break;
                default:
                        TP_WARNING("TP%u Set Descrambler Failed - Unsupported Descramble Algorithm %u\n",
                                   tp_id, algo.algo);
                        return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        WRITE_REG32(tp_des_cntl_reg, des_ctrl.regValue);

        pTp_drv->tp[tp_id].desc = algo;

        _tp_unlock();


        /* static bool cw_init = false; */
        if(!cw_init) {
                TP_DBG(" Request CW for TP !!! \n");
                rtk_cw_request_multi_cws("TP", 0, 48);
                cw_init = true;
        } else {
                TP_DBG("  CW has already requested!!! \n");
        }

        TP_TRACE("exit, TP%u, algo=%u, round=%u\n", tp_id, algo.algo, algo.round);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_SetDescrambleAlgorithm);


INT32  RHAL_SetPIDDescrambleAlgorithm(UINT8 key_sel, TPK_DESCRAMBLE_ALGORITHM_T     desc)
{
        pTp_drv->pid_desc[key_sel].desc = desc;
        return TPK_SUCCESS;

}
EXPORT_SYMBOL(RHAL_SetPIDDescrambleAlgorithm);

INT32 RHAL_FreePIDDescrambleAlgorithm(void)
{
        int i;
        for(i = 0; i < MAX_KEY_COUNT; i++) {
                pTp_drv->pid_desc[i].desc.algo = TPK_DESCRAMBLE_ALGO_NONE;
                pTp_drv->pid_desc[i].desc.round = 0;
        }
        return TPK_SUCCESS;
}
EXPORT_SYMBOL(RHAL_FreePIDDescrambleAlgorithm);


/*------------------------------------------------------------------
 * Func : RHAL_SetCW
 *
 * Desc : Set CW (Control Word)
 *
 * Parm : [I] id      : TP Index
 *        [I] key_set : key set index
 *            [I] key_id  : which key index
 *
 *                TP_SETCW_KEYID_EVEN_KEY
 *                TP_SETCW_KEYID_ODD_KEY
 *                TP_SETCW_KEYID_MULTI2_SYS_KEY : System Key (Multi2)
 *
 *            [I] Key     : key  value
 *            [I] IV      : Initial vector
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_SetCW(
        TPK_TP_ENGINE_T tp_id,
        UINT8           key_set,
        UINT8           key_id,
        UINT8           Key[TPK_MAX_KEY_LENGTH],
        UINT8           IV[TPK_MAX_IV_LENGTH])
{
        UINT8 ofst;
        UINT8 IV_clr[TPK_MAX_IV_LENGTH];
        TPK_DESCRAMBLE_ALGORITHM_T realalgo;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_MAX_KEY_COUNT(key_set);
        CHECK_TP_STRUCTURE();

        if( pTp_drv->tp[tp_id].desc.algo != 0)
                realalgo = pTp_drv->tp[tp_id].desc;
        else if(pTp_drv->pid_desc[key_set].desc.algo != 0)
                realalgo = pTp_drv->pid_desc[key_set].desc;

        if (key_id > TP_SETCW_KEYID_ODD_KEY) {
                if ((realalgo.algo != TPK_DESCRAMBLE_ALGO_MULTI2_OFB) ||
                    (key_id != TP_SETCW_KEYID_MULTI2_SYS_KEY)) {
                        TP_WARNING("TP%u key_id(%u) not support (desc.algo = %u)\n",
                                   tp_id, key_id, realalgo.algo);

                        return TPK_BAD_PARAMETER;
                }
        }

        if ((Key == NULL) || (IV == NULL)) {
                TP_WARNING("key=%p, IV=%p\n", Key, IV);
                return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        switch (realalgo.algo) {
                case TPK_DESCRAMBLE_ALGO_DES_ECB_CLEAR:
                        TP_SetCW(tp_id, key_set, (key_id) ? 2 : 0, BYTES_TO_LONG(&Key[0], 3), BYTES_TO_LONG(&Key[3], 4));

                        break;
                case TPK_DESCRAMBLE_ALGO_TDES_ECB_CLEAR:
                case TPK_DESCRAMBLE_ALGO_TDES_CBC_OFB:
                        ofst = (key_id) ? 4 : 0;
                        TP_SetCW(tp_id, key_set, ofst++, BYTES_TO_LONG(&Key[14], 3), BYTES_TO_LONG(&Key[17], 4));
                        TP_SetCW(tp_id, key_set, ofst++, BYTES_TO_LONG(&Key[ 7], 3), BYTES_TO_LONG(&Key[10], 4));
                        TP_SetCW(tp_id, key_set, ofst++, BYTES_TO_LONG(&Key[ 0], 3), BYTES_TO_LONG(&Key[ 3], 4));

                        if (realalgo.algo == TPK_DESCRAMBLE_ALGO_TDES_CBC_OFB)
                                TP_SetCW(tp_id, key_set, ofst, BYTES_TO_LONG(&IV[0], 4), BYTES_TO_LONG(&IV[4], 4));
                        else
                                TP_SetCW(tp_id, key_set, ofst, 0, 0);

                        break;
                case TPK_DESCRAMBLE_ALGO_CSA:           /* CSA Mode : used by DVB-C CA */
                case TPK_DESCRAMBLE_ALGO_CSA2:          /* CSA Mode : used by DVB-C CA */
                case TPK_DESCRAMBLE_ALGO_CSA_RAW:
                        TP_SetCW(tp_id, key_set, (key_id) ? 1 : 0, BYTES_TO_LONG(&Key[0], 4), BYTES_TO_LONG(&Key[4], 4));

                        break;
                case TPK_DESCRAMBLE_ALGO_MULTI2:
                case TPK_DESCRAMBLE_ALGO_MULTI2_CBC:
                case TPK_DESCRAMBLE_ALGO_MULTI2_OFB:
                        if (key_id == TP_SETCW_KEYID_MULTI2_SYS_KEY) {
                                /* system key (256 bits) */
                                TP_SetCW(tp_id, key_set, 4, BYTES_TO_LONG(&Key[0], 4),  BYTES_TO_LONG(&Key[ 4], 4));
                                TP_SetCW(tp_id, key_set, 5, BYTES_TO_LONG(&Key[8], 4),  BYTES_TO_LONG(&Key[12], 4));
                                TP_SetCW(tp_id, key_set, 6, BYTES_TO_LONG(&Key[16], 4), BYTES_TO_LONG(&Key[20], 4));
                                TP_SetCW(tp_id, key_set, 7, BYTES_TO_LONG(&Key[24], 4), BYTES_TO_LONG(&Key[28], 4));
                        } else {
                                /* even/odd key (64 bits) */
                                ofst = (key_id) ? 2 : 0;
                                TP_SetCW(tp_id, key_set, ofst++, BYTES_TO_LONG(&Key[0], 4), BYTES_TO_LONG(&Key[ 4], 4));
                                TP_SetCW(tp_id, key_set, ofst,   BYTES_TO_LONG(&IV[0], 4), BYTES_TO_LONG(&IV[4], 4));
                        }

                        break;
                case TPK_DESCRAMBLE_ALGO_AES_128_CBC_OFB_ATIS:
                        ofst = (key_id) ? 4 : 0;

                        memset(IV_clr, 0, TPK_MAX_IV_LENGTH);
                        TP_SetCW(tp_id, key_set, ofst++, BYTES_TO_LONG(&Key[0], 4), BYTES_TO_LONG(&Key[ 4], 4));
                        TP_SetCW(tp_id, key_set, ofst++, BYTES_TO_LONG(&Key[8], 4), BYTES_TO_LONG(&Key[12], 4));
                        TP_SetCW(tp_id, key_set, ofst++, BYTES_TO_LONG(&IV_clr[0], 4), BYTES_TO_LONG(&IV_clr[ 4], 4));
                        TP_SetCW(tp_id, key_set, ofst,   BYTES_TO_LONG(&IV_clr[8], 4), BYTES_TO_LONG(&IV_clr[12], 4));

                        break;
                case TPK_DESCRAMBLE_ALGO_AES_128_CBC_CLEAR:
                case TPK_DESCRAMBLE_ALGO_AES_128_CBC_OFB:
                case TPK_DESCRAMBLE_ALGO_AES_RCBC_CS_CLEAR:
                case TPK_DESCRAMBLE_ALGO_AES_128_ECB_CLEAR:
                case TPK_DESCRAMBLE_ALGO_CAM_ECB_CLEAR:
                case TPK_DESCRAMBLE_ALGO_CAM_CBC_CLEAR:
                case TPK_DESCRAMBLE_ALGO_CAM_CBC_OFB:
                        ofst = (key_id) ? 4 : 0;
                        TP_SetCW(tp_id, key_set, ofst++, BYTES_TO_LONG(&Key[0], 4), BYTES_TO_LONG(&Key[ 4], 4));
                        TP_SetCW(tp_id, key_set, ofst++, BYTES_TO_LONG(&Key[8], 4), BYTES_TO_LONG(&Key[12], 4));
                        TP_SetCW(tp_id, key_set, ofst++, BYTES_TO_LONG(&IV[0], 4), BYTES_TO_LONG(&IV[ 4], 4));
                        TP_SetCW(tp_id, key_set, ofst,   BYTES_TO_LONG(&IV[8], 4), BYTES_TO_LONG(&IV[12], 4));

                        break;
                default:
                        _tp_unlock();

                        TP_WARNING("TP%u descrambler algorithm (%u) not support\n",
                                   tp_id, realalgo.algo);
                        return TPK_NOT_SET;
        }

        _tp_unlock();

        TP_TRACE("exit, TP%u, key_set=%u, key_id=%u\n", tp_id, key_set, key_id);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_SetCW);



/*------------------------------------------------------------------
 * Func : RHAL_DescrambleControl
 *
 * Desc : Set Descramble Mode
 *
 * Parm : [I] id : TP Index
 *        [I] mode : Descramble mode
 *
 *            TPK_NO_DESCRAMBLE
 *            TPK_TSP_LEVEL_DESCRAMBLE
 *            TPK_PES_LEVEL_DESCRAMBLE
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_DescrambleControl(
        IN TPK_TP_ENGINE_T       tp_id,
        IN TPK_DESCRAMBLE_MODE_T mode
)
{
        tp_tp_tf0_cntl_RBUS tp_cntl;
        REGADDR tp_cntl_reg;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        /* TP3 do not support descramble */
        switch(tp_id) {
                case TP_TP0:
                        tp_cntl_reg = TP_TP_TF0_CNTL_reg;
                        break;

                case TP_TP1:
                        tp_cntl_reg = TP_TP_TF1_CNTL_reg;
                        break;

                case TP_TP2:
                        tp_cntl_reg = TP_TP_TF2_CNTL_reg;
                        break;

                default:
                        TP_WARNING("unsupported descrambler id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        tp_cntl.regValue   = 0;
        tp_cntl.regValue   = READ_REG32(tp_cntl_reg);
        tp_cntl.write_data = 0;

        switch(mode) {
                case TPK_TSP_LEVEL_DESCRAMBLE:
                case TPK_PES_LEVEL_DESCRAMBLE:
                        /* if (pTp_drv->tp[tp_id].desc.algo == TPK_DESCRAMBLE_ALGO_NONE) {
                                 _tp_unlock();
                                 TP_WARNING("TP%u Start descrambler failed - no descramble algorithm specified\n", tp_id);
                                 return TPK_NOT_INIT;
                         }
                         */

                        if (pTp_drv->tp[tp_id].tp_param.pid_filter_en == 0) {
                                TP_WARNING("TP%u descrambler can not work without PID filter, please enable PID filter\n", tp_id);
                        }

                        if (mode == TPK_TSP_LEVEL_DESCRAMBLE) {
                                tp_cntl.pes_en = 0;
                                tp_cntl.psc_en = 0;
                                tp_cntl.de_en  = 1;
                                tp_cntl.tsc_en = 1;
                        } else {
                                tp_cntl.pes_en = 1;
                                tp_cntl.psc_en = 1;
                                tp_cntl.de_en  = 0;
                                tp_cntl.tsc_en = 0;
                        }
                        break;

                case TPK_NO_DESCRAMBLE:
                        tp_cntl.pes_en = 0;
                        tp_cntl.psc_en = 0;
                        tp_cntl.de_en  = 0;
                        tp_cntl.tsc_en = 0;

                        break;

                default:
                        _tp_unlock();
                        TP_WARNING("TP%u unsupport descramble mode (%u)\n", tp_id,
                                   mode);
                        return TPK_BAD_PARAMETER;
        }

        if(tp_cntl.de_en == 0 ) {
                Tp_Update_PIDFilter_predes( tp_id,      0);
        }

        Tp_Write_Data_Reg_Write(tp_cntl_reg, tp_cntl.regValue);

        if(tp_cntl.de_en == 1 ) {
                Tp_Update_PIDFilter_predes( tp_id,      1);
        }

        pTp_drv->tp[tp_id].desc_mode = mode;

        _tp_unlock();

        TP_TRACE("exit, TP%u, mode = %u\n", tp_id, mode);
        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_DescrambleControl);



/***********************************

         debug message

************************************/

/*------------------------------------------------------------------
 * Func : RHAL_TrackErrorPacket
 *
 * Desc : Get TP's packet status
 *
 * Parm : [I] id         : TP index
 *        [O] p_err_pkt  : number of error packet
 *        [O] p_rcv_pkt  : number of received packet
 *        [O] p_drop_pkt : number of dropped packet
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TrackErrorPacket(
        TPK_TP_ENGINE_T    tp_id,
        UINT32            *p_err_pkt,
        UINT32            *p_rcv_pkt,
        UINT32            *p_drop_pkt
)
{
        INT32 ret;
        TPK_TP_PKT_CNT_T tp_pkt_status;

        CHECK_MAX_TP_COUNT(tp_id);

        _tp_lock();

        ret = Tp_TrackErrorPacket(tp_id, &tp_pkt_status.pkt, &tp_pkt_status.droppedPkt, &tp_pkt_status.errorPkt);

        _tp_unlock();

        /* only copy sizeof(UINT32) to demux, because the difference type of packet, demux is UINT32, TP is UINT64 */
        memcpy(p_rcv_pkt, &tp_pkt_status.pkt, sizeof(UINT32));
        memcpy(p_drop_pkt, &tp_pkt_status.droppedPkt, sizeof(UINT32));
        memcpy(p_err_pkt, &tp_pkt_status.errorPkt, sizeof(UINT32));

        return ret;
}

EXPORT_SYMBOL(RHAL_TrackErrorPacket);



/***********************************

 hardware info and status for AP

************************************/

/*------------------------------------------------------------------
 * Func : RHAL_GetHardwareInfo
 *
 * Desc : Get hardware info
 *
 * Parm : [O] pTpHardwareInfo : output buffer of TP hardware status
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_GetHardwareInfo(TPK_HARDWARE_INFO_T *pTpHardwareInfo)
{
        UINT32 tp_hardware_info_max_size = MAX_TP_MODULE_SUPPORT;
        TPK_TP_ENGINE_T i;

        TP_TRACE("Enter\n");

        if (pTpHardwareInfo == NULL) {
                TP_WARNING("bad parameter, pTpHardwareInfo=%p\n", pTpHardwareInfo);
                return TPK_BAD_PARAMETER;
        }

        if (tp_hardware_info_max_size < MAX_TP_COUNT) {
                TP_WARNING("tp_hardware_info_max_size (%u) is smaller than MAX_TP_COUNT (%u)\n",
                           tp_hardware_info_max_size, MAX_TP_COUNT);

                return TPK_RESOURCE_CONFLICT;
        }

        pTpHardwareInfo->chip_version    = CHIP_VERSION;
        pTpHardwareInfo->tp_num          = MAX_TP_COUNT;
        pTpHardwareInfo->tpout_num       = MAX_TPOUT_COUNT;
        pTpHardwareInfo->mtp_num         = MAX_MTP_COUNT;
        pTpHardwareInfo->descrambler_num = MAX_KEY_COUNT;

        for( i = 0; i < MAX_TP_COUNT; i++) {
                if (i == TP_TP0) {
                        pTpHardwareInfo->tp_hareware_info[i].pid_filter_num = TP0_PID_FILTER_COUNT;
                        pTpHardwareInfo->tp_hareware_info[i].sec_filter_num = TP0_SEC_FILTER_COUNT;
                } else if (i == TP_TP1) {
                        pTpHardwareInfo->tp_hareware_info[i].pid_filter_num = TP1_PID_FILTER_COUNT;
                        pTpHardwareInfo->tp_hareware_info[i].sec_filter_num = TP1_SEC_FILTER_COUNT;
                } else if (i == TP_TP2) {
                        pTpHardwareInfo->tp_hareware_info[i].pid_filter_num = TP2_PID_FILTER_COUNT;
                        pTpHardwareInfo->tp_hareware_info[i].sec_filter_num = TP2_SEC_FILTER_COUNT;
                } else if (i == TP_TP3) {
                        pTpHardwareInfo->tp_hareware_info[i].pid_filter_num = TP3_PID_FILTER_COUNT;
                        pTpHardwareInfo->tp_hareware_info[i].sec_filter_num = TP3_SEC_FILTER_COUNT;
                } else {
                        break;
                }
        }

        TP_TRACE("exit, chip_version=%u, tp_num=%u, tpout_num=%u, mtp_num=%u\n",
                 pTpHardwareInfo->chip_version,
                 pTpHardwareInfo->tp_num,
                 pTpHardwareInfo->tpout_num,
                 pTpHardwareInfo->mtp_num);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_GetHardwareInfo);


/*------------------------------------------------------------------
 * Func : RHAL_GetTpStatus
 *
 * Desc :
 *
 * Parm : [I] id : TP Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_GetTpStatus(IN TPK_TP_ENGINE_T tp_id, OUT TPK_TP_STATUS_T *pTpStatus)
{

        if (jiffies >= tp_status_timeout) {
                TP_TRACE("Enter, id = %u\n", tp_id);
        }

        if ((pTpStatus == NULL)) {
                TP_WARNING("bad parameter, pTpStatus=%p\n", pTpStatus);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        memcpy(pTpStatus, &pTp_drv->tp[tp_id], sizeof(TPK_TP_STATUS_T));

        _tp_unlock();

        if (jiffies >= tp_status_timeout) {
                TP_TRACE("exit, tp_id=%u\n", tp_id);
                tp_status_timeout = jiffies + HZ;
        }

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_GetTpStatus);



/*------------------------------------------------------------------
 * Func : RHAL_GetMtpStatus
 *
 * Desc : Get Status of MTP engine
 *
 * Parm : [I] mtp_id     : Index of MTP engine
 *        [O] pMtpStatus : status of MTP
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_GetMtpStatus(
        UINT8                     mtp_id,
        TPK_MTP_STATUS_T         *pMtpStatus
)
{
        TP_TRACE("Enter, mtp_id = %d\n", mtp_id);

        if (pMtpStatus == NULL) {
                TP_WARNING("bad parameter pMtpStatus=%p\n", pMtpStatus);

                return TPK_BAD_PARAMETER;
        }

        CHECK_MTP_ID(mtp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        memcpy(pMtpStatus, &pTp_drv->mtp[mtp_id], sizeof(TPK_MTP_STATUS_T));

        _tp_unlock();

        TP_TRACE("exit, mtp_id = %u\n", mtp_id);
        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_GetMtpStatus);



/*------------------------------------------------------------------
 * Func : RHAL_GetTpoutStatus
 *
 * Desc : Get Status of TP Out module
 *
 * Parm : [I] tpout_id : Index of TP Out module
 *        [O] pTpoutStatus : TP output status output buffer
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_GetTpoutStatus(
        UINT8                tpout_id,
        TPK_TPOUT_STATUS_T*  pTpoutStatus
)
{
        TP_TRACE("Enter, id = %u\n", tpout_id);

        if ((tpout_id >= MAX_TPOUT_COUNT) || (pTpoutStatus == NULL)) {
                TP_WARNING("bad parameter, tpout_id=%u, pTpoutStatus=%p\n",
                           tpout_id, pTpoutStatus);

                return TPK_BAD_PARAMETER;
        }

        CHECK_TP_STRUCTURE();

        _tp_lock();

        memcpy(pTpoutStatus, &pTp_drv->tpout[tpout_id], sizeof(TPK_TPOUT_STATUS_T));

        _tp_unlock();

        TP_TRACE("exit, tpout_id=%u\n", tpout_id);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_GetTpoutStatus);


TPK_TP_SOURCE_T TpSrc_MapFromPCBToTP(TP_SRC_TYPE_T tpSrcPcb)
{
        TPK_TP_SOURCE_T tpSrc;

        switch(tpSrcPcb) {
                case TP_SRC_0:
                        tpSrc = TS_SRC_0;
                        break;
                case TP_SRC_1:
                        tpSrc = TS_SRC_1;
                        break;
                case TP_SRC_2:
                        tpSrc = TS_SRC_2;
                        break;
                case TP_SRC_3:
                        tpSrc = TS_SRC_3;
                        break;
                case TP_SRC_INTERNAL:
                        tpSrc = Internal_Demod;
                        break;
                case TP_SRC_UNUSED:
                        tpSrc = TS_UNMAPPING;
                        break;
                default:
                        tpSrc = TS_UNMAPPING;
                        break;
        }
        return tpSrc;
}
EXPORT_SYMBOL(TpSrc_MapFromPCBToTP);

INT32 RHAL_GetTPSource(TPK_INPUT_PORT_T portType)
{

        unsigned long long info = 0;
        TPK_TP_SOURCE_T tp_src;

        switch(portType) {
                case TPK_PORT_IN_DEMOD0:
                case TPK_PORT_IN_DEMOD1:
                        tp_src = Internal_Demod;
                        break;
                case TPK_PORT_EXT_INPUT0: {
                        if (pcb_mgr_get_enum_info_byname("TP_SRC", &info) == 0) {
                                tp_src = TpSrc_MapFromPCBToTP((TP_SRC_TYPE_T)TP_SRC_EXTERNAL_CAM0_GET(info));
                        } else {
                                tp_src = TS_SRC_0;
                        }
                        break;
                }
                case TPK_PORT_EXT_INPUT1: {
                        if (pcb_mgr_get_enum_info_byname("TP_SRC", &info) == 0) {
                                tp_src = TpSrc_MapFromPCBToTP((TP_SRC_TYPE_T)TP_SRC_EXTERNAL_TUNER1_GET(info));
                        } else {
                                tp_src = TS_SRC_2;
                        }
                        break;
                }
                case TPK_PORT_FROM_MEM: {
                        tp_src = MTP;
                        break;
                }
                default: {
                        tp_src = TS_UNMAPPING;
                        break;
                }
        }

        return tp_src;
}
EXPORT_SYMBOL(RHAL_GetTPSource);

INT32 RHAL_TPDbgRecTSData(IN TPK_TP_ENGINE_T tp_id, IN UINT8 enable, IN UINT8* path)
{
        struct  file *tmp_fd = NULL;
        UINT8 n;

        if ( ((enable) && (path == NULL)) ) {
                TP_WARNING("bad parameter, path=%s\n", path);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        if(enable) {
                if(rec_fd[tp_id]) {
                        for ( n = 0; n < MAX_TP_COUNT; n++) {
                                if (0 == strncmp(path, tp_file_path[n], strlen(tp_file_path[n])))
                                        break;
                        }

                        if(n < MAX_TP_COUNT) {
                                TP_WARNING("File path is same, %s\n", path);
                                return TPK_SUCCESS;
                        }

                        TP_INFO("TS Record Stopped\n");
                        filp_close(rec_fd[tp_id], NULL);
                        rec_fd[tp_id] = NULL;
                        memset(tp_file_path[tp_id], 0, sizeof(tp_file_path[tp_id]));
                }

                tmp_fd = filp_open(path, O_RDWR | O_CREAT | O_TRUNC, 0);
                if(IS_ERR(tmp_fd)) {
                        TP_WARNING("Start Rec TS failed, open %s failed\n", path);
                        return TPK_BAD_PARAMETER;
                } else {

                        for ( n = 0; n < MAX_TP_COUNT; n++) {
                                if (0 == strncmp(path, tp_file_path[n], strlen(path)))
                                        break;
                        }

                        if(n < MAX_TP_COUNT) {
                                TP_WARNING("File path is same, %s\n", path);
                                return TPK_BAD_PARAMETER;
                        } else {
                                TP_INFO("Start Rec TS to - %s,rec_fd=%p\n", path, tmp_fd);
                                memcpy(tp_file_path[tp_id], path, strlen(path));
                                rec_fd[tp_id] = tmp_fd;
                        }
                }
        } else {
                if(rec_fd[tp_id]) {
                        TP_INFO("TS Record Stopped\n");
                        filp_close(rec_fd[tp_id], NULL);
                        rec_fd[tp_id] = NULL;
                        memset(tp_file_path[tp_id], 0, sizeof(tp_file_path[tp_id]));
                }
        }

        return TPK_SUCCESS;
}
EXPORT_SYMBOL(RHAL_TPDbgRecTSData);




/*------------------------------------------------------------------
 * Func : RHAL_SetTPHardwareReset
 *
 * Desc : Set TP Hardware Reset
 *
 * Parm : [I] restore_value : restore value or not
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_SetTPHardwareReset(
        UINT8              restore_value
)
{

        RBus_UInt32 regValue_409c;
        RBus_UInt32 regValue_40a0;
        RBus_UInt32 regValue_40a4;
        RBus_UInt32 regValue_40a8;
        RBus_UInt32 regValue_40ac;
        RBus_UInt32 regValue_40b0;
        RBus_UInt32 regValue_40b4;
        RBus_UInt32 regValue_40b8;
        RBus_UInt32 regValue_40bc;
        RBus_UInt32 regValue_40c0;
        RBus_UInt32 regValue_40c4;

        tp_tp_tf0_frmcfg_RBUS tp_frm;

        CHECK_TP_STRUCTURE();

        _tp_lock();

        TP_DBG_SIMPLE( "TPHardwareReset\n");

        pTp_drv->hw_reset = 1;

        tp_frm.regValue    = READ_REG32(TP_TP_TF0_FRMCFG_reg);
        tp_frm.frm_en      = 0;
        WRITE_REG32(TP_TP_TF0_FRMCFG_reg, tp_frm.regValue);

        save_tp_reigster_value_ex();

        CRT_CLK_OnOff(TP, CLK_OFF, NULL);

        udelay(10);

        CRT_CLK_OnOff(TP, CLK_ON, NULL);

        restore_tp_reigster_value_ex();

        tp_frm.regValue    = READ_REG32(TP_TP_TF0_FRMCFG_reg);
        tp_frm.frm_en      = 1;
        WRITE_REG32(TP_TP_TF0_FRMCFG_reg, tp_frm.regValue);

        pTp_drv->hw_reset = 0;

        _tp_unlock();

        TP_TRACE("exit, restore_value %u\n", restore_value);
        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_SetTPHardwareReset);


/*------------------------------------------------------------------
 * Func : RHAL_SetTPPatternSearchInfoBuffer
 *
 * Desc : Set Start Code Search Buffer
 *
 * Parm : [I] tp_id : TP Index
 *        [I] pPhyAddr : physical address
 *        [I] pVirAddr : virtual address
 *        [I] size     : size of ring buffer
 *        [I] pSharedRP : address of RP shared with the caller
 *        [I] pSharedWP : address of WP shared with the caller
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_SetTPPatternSearchInfoBuffer(UINT8 tp_id, UINT8* pPhyAddr, UINT8* pVirAddr, UINT32 size, UINT8* pSharedRP, UINT8* pSharedWP)
{
        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        if( Tp_is_SupportPatternSearch(tp_id) == TPK_NOT_SUPPORT )
                return TPK_BAD_PARAMETER;

        _tp_lock();

        Tp_SetPatternSearchInfoBuffer(tp_id, pPhyAddr, pVirAddr, size, pSharedRP, pSharedWP);

        _tp_unlock();

        TP_TRACE("exit, tp_id=%d pPhyAddr=0x%x pVirAddr=0x%x size=%d pSharedRP=0x%x pSharedWP=0x%x\n", tp_id, pPhyAddr, pVirAddr, size, pSharedRP, pSharedWP);
        return TPK_SUCCESS;
}
EXPORT_SYMBOL(RHAL_SetTPPatternSearchInfoBuffer);


/*------------------------------------------------------------------
 * Func : RHAL_SetTPPatternSearchPID
 *
 * Desc : Set Start Code PID Number
 *
 * Parm : [I] tp_id : TP Index
 *        [I] PID     : value of Start Code Search PID
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_SetTPPatternSearchPID(UINT8 tp_id, UINT16 PID)
{
        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        if( Tp_is_SupportPatternSearch(tp_id) == TPK_NOT_SUPPORT )
                return TPK_BAD_PARAMETER;

        _tp_lock();

        Tp_SetPatternSearchPID(tp_id, PID);

        _tp_unlock();

        TP_TRACE("exit, tp_id=%d PID=0x%x\n", tp_id, PID);
        return TPK_SUCCESS;
}
EXPORT_SYMBOL(RHAL_SetTPPatternSearchPID);

/*------------------------------------------------------------------
 * Func : RHAL_DumpTPRegister
 *
 * Desc : Dump the TP Register to file
 *
 * Parm : None
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_DumpTPRegister(char *str)
{
        _tp_lock();

        Tp_DumpTPRegister(str);

        _tp_unlock();
        return TPK_SUCCESS;
}
EXPORT_SYMBOL(RHAL_DumpTPRegister);


/******************************

         TPP

*******************************/
/*------------------------------------------------------------------
 * Func : RHAL_SetTPPMode
 *
 * Desc : Set TS Input mode of TP MODULE
 *
 * Parm : id : TPP Index
 *    param : TS Parameter
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_SetTPPMode(
        IN TPK_TPP_ENGINE_T    tpp_id,
        IN TPK_TPP_TS_PARAM_T  Param
)
{
        INT32 ret;

        tp_tp_tf0_p_frmcfg_RBUS tp_p_frmcfg_reg;
        tp_tp_tf0_p_cntl_RBUS tp_p_cntl;

        TP_TRACE("Enter, tpp_id=%d, serial=%u, pid_filter_en=%u\n", tpp_id, Param.serial, Param.pid_filter_en);

        if (Param.ts_in_tsp_len > byte_204) {
                TP_WARNING("bad parameter, ts_in_tsp_len=%u\n", Param.ts_in_tsp_len);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_P_COUNT(tpp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        Tp_TPP_GetFrmReg(tpp_id, &tp_p_frmcfg_reg.regValue);
        tp_p_frmcfg_reg.serial = Param.serial;
        tp_p_frmcfg_reg.data_order = Param.data_order;
        tp_p_frmcfg_reg.datapin = Param.datapin;
        tp_p_frmcfg_reg.packet_size = Param.ts_in_tsp_len;
        tp_p_frmcfg_reg.sync_byte = Param.sync_byte;
        Tp_TPP_SetFrmReg(tpp_id, tp_p_frmcfg_reg.regValue);

        pTp_drv->tpp[tpp_id].tpp_param = Param;

        _tp_unlock();

        TP_TRACE("exit, tp_id=%d, serial=%u, pid_filter_en=%u\n",
                 tpp_id, Param.serial, Param.pid_filter_en);


        return ret;
}

EXPORT_SYMBOL(RHAL_SetTPPMode);

INT32 RHAL_GetTPPMode(
        IN TPK_TPP_ENGINE_T    tpp_id,
        OUT TPK_TPP_TS_PARAM_T  *pParam
)
{
        INT32 ret;
        tp_tp_tf0_p_frmcfg_RBUS tp_p_frmcfg_reg;

        TP_TRACE("Enter, tpp_id=%d\n", tpp_id);

        if (pParam == NULL) {
                TP_WARNING("bad parameter pParam=%p\n", pParam);

                return TPK_BAD_PARAMETER;
        }
        CHECK_MAX_TP_P_COUNT(tpp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        Tp_TPP_GetFrmReg(tpp_id, &tp_p_frmcfg_reg.regValue);

        pParam->serial = tp_p_frmcfg_reg.serial;
        pParam->data_order = tp_p_frmcfg_reg.data_order;
        pParam->datapin = tp_p_frmcfg_reg.datapin;
        pParam->ts_in_tsp_len = tp_p_frmcfg_reg.packet_size;
        pParam->sync_byte = tp_p_frmcfg_reg.sync_byte;

        _tp_unlock();

        TP_TRACE("exit, tp_id=%d, serial=%u, ts_in_tsp_len=%u\n",
                 tpp_id, pParam->serial, pParam->ts_in_tsp_len);


        return ret;

}
EXPORT_SYMBOL(RHAL_GetTPPMode);

/*------------------------------------------------------------------
 * Func : RHAL_EnableTPPPIDFilter
 *
 * Desc : Set TPP PID filter On/Off
 *
 * Parm : [I] id : TPP ID
 *        [I] on : Enable TPP PID filter or not
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/

INT32 RHAL_EnableTPPPIDFilter(
        IN TPK_TPP_ENGINE_T   tpp_id,
        IN UINT8             on
)
{
        INT32 ret;
        tp_tp_tf0_p_cntl_RBUS tpp_cntl;

        TP_TRACE("enter, tpp_id=%u, on=%u\n", tpp_id, on);

        CHECK_MAX_TP_P_COUNT(tpp_id);
        CHECK_TP_STRUCTURE();

        _tp_lock();

        tpp_cntl.pid_en = 1; /* set select bit = 1 */

        Tp_TPP_SetCtrlReg(tpp_id, tpp_cntl.regValue, on);

        _tp_unlock();


        TP_TRACE("exit, tpp_id= %u, on = %u\n", tpp_id, on);

        return ret;

}

EXPORT_SYMBOL(RHAL_EnableTPPPIDFilter);

/*------------------------------------------------------------------
 * Func : RHAL_TPPStreamControl
 *
 * Desc : TPP Streaming Control
 *
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPPStreamControl(
        TPK_TPP_ENGINE_T tpp_id,
        TPK_TPP_STREAM_CTRL_T ctrl)
{

        UADDRESS tp_p_frmcfg_addr;
        UADDRESS m2m_ctrl_addr;
        tp_tp_tf0_p_frmcfg_RBUS tp_p_frmcfg_reg;
        tp_tp0_m2m_ring_ctrl_RBUS m2m_ctrl_reg;

        CHECK_MAX_TPP_COUNT(tpp_id);
        CHECK_TP_STRUCTURE();

        if ((ctrl != TPP_STREAM_START) && (ctrl != TPP_STREAM_STOP)) {
                TP_WARNING("bad parameter mtp_id = %u, ctrl = %u\n", tpp_id, ctrl);
                return TPK_BAD_PARAMETER;
        }

        switch (tpp_id) {
                case TP_TPP0:
                        tp_p_frmcfg_addr = TP_TP_TF0_P_FRMCFG_reg;
                        m2m_ctrl_addr     = TP_TP0_P_M2M_RING_CTRL_reg;
                        break;
                case TP_TPP1:
                        tp_p_frmcfg_addr = TP_TP_TF1_P_FRMCFG_reg;
                        m2m_ctrl_addr     = TP_TP1_P_M2M_RING_CTRL_reg;
                        break;
                case TP_TPP2:
                        tp_p_frmcfg_addr = TP_TP_TF2_P_FRMCFG_reg;
                        m2m_ctrl_addr     = TP_TP2_P_M2M_RING_CTRL_reg;
                        break;
                default:
                        TP_WARNING("unsupported tpp_id=%d\n", tpp_id);
                        return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        tp_p_frmcfg_reg.regValue = READ_REG32(tp_p_frmcfg_addr);
        m2m_ctrl_reg.regValue = READ_REG32(m2m_ctrl_addr);

        if (ctrl == TPP_STREAM_START) {
                tp_p_frmcfg_reg.frm_en = 1;
                m2m_ctrl_reg.go = 1;

                if (pTp_drv->tpp[tpp_id].tpp_src == MTP)
                        m2m_ctrl_reg.in_go = 1;
                else
                        m2m_ctrl_reg.in_go = 0;
        } else {
                tp_p_frmcfg_reg.frm_en = 0;
                m2m_ctrl_reg.go = 0;
                if (pTp_drv->tpp[tpp_id].tpp_src == MTP)
                        m2m_ctrl_reg.in_go = 0;
        }
        WRITE_REG32(tp_p_frmcfg_addr, tp_p_frmcfg_reg.regValue);
        Tp_Write_Data_Reg_Write(m2m_ctrl_addr, m2m_ctrl_reg.regValue);

        _tp_unlock();

        TP_WARNING("tpp_id[%u] stream status = %u \n", tpp_id, ctrl);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_TPPStreamControl);

/*------------------------------------------------------------------
 * Func : RHAL_GetTPPBufferStatus
 *
 * Desc : Get TPP Buffer Status
 *
 * Parm :
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_GetTPPBufferStatus(
        IN  TPK_TPP_ENGINE_T  tpp_id,
        OUT UINT32*           pBufferSize,
        OUT UINT32*           pDataSize)
{
        UADDRESS Base;
        UADDRESS Limit;
        UADDRESS RP;
        UADDRESS WP;
        tp_tp_p_ring_ctrl_RBUS tp_p_ring_ctrl_reg;

        CHECK_MAX_TPP_COUNT(tpp_id);


        if ((pBufferSize == NULL) || (pDataSize == NULL) ) {
                TP_WARNING("tpp_id[%u] pBufferSize = %p, pDataSize = %p\n",
                           tpp_id, pBufferSize, pDataSize);
                return TPK_BAD_PARAMETER;
        }

        _tp_lock();

        tp_p_ring_ctrl_reg.regValue = 0;
        tp_p_ring_ctrl_reg.idx = tpp_id;
        tp_p_ring_ctrl_reg.r_w = 0; /* read */
        WRITE_REG32(TP_TP_P_RING_CTRL_reg, tp_p_ring_ctrl_reg.regValue);

        Base  = READ_REG32(TP_TP_P_RING_BASE_reg);
        RP    = READ_REG32(TP_TP_P_RING_RP_reg);
        WP    = READ_REG32(TP_TP_P_RING_WP_reg);
        Limit = READ_REG32(TP_TP_P_RING_LIMIT_reg);

        *pBufferSize = Limit - Base;
        *pDataSize = (WP >= RP) ?
                     (WP - RP) :
                     (*pBufferSize - (RP - WP));
        _tp_unlock();

        TP_TRACE("tpp_id[%u] pBufferSize=%u, pDataSize=%u\n",
                 tpp_id, *pBufferSize, *pDataSize);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_GetTPPBufferStatus);

/*------------------------------------------------------------------
 * Func : RHAL_TPPFlushBuffer
 *
 * Desc :
 *
 * Parm : [I] id : TPP Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_TPPFlushBuffer(IN TPK_TPP_ENGINE_T tpp_id)
{
        UINT8 bFrm_en = 0;
        tp_tp_tf0_p_frmcfg_RBUS tp_p_frmcfg_reg;
        tp_tp0_m2m_ring_ctrl_RBUS m2m_ctrl;
        tp_tp_p_ring_ctrl_RBUS tp_p_ring_ctrl_reg;
        UADDRESS Base, Limit;


        CHECK_MAX_TPP_COUNT(tpp_id);

        _tp_lock();

        Tp_TPP_GetFrmReg(tpp_id, &tp_p_frmcfg_reg.regValue);

        bFrm_en = tp_p_frmcfg_reg.frm_en;

        /*stop tpp frame first*/
        if (tp_p_frmcfg_reg.frm_en) {
                tp_p_frmcfg_reg.frm_en = 0;
                Tp_TPP_SetFrmReg(tpp_id, tp_p_frmcfg_reg.regValue);
        }

        /*read ring buffer*/
        tp_p_ring_ctrl_reg.regValue = 0;
        tp_p_ring_ctrl_reg.idx = tpp_id;
        tp_p_ring_ctrl_reg.r_w = 0; /* read */
        WRITE_REG32(TP_TP_P_RING_CTRL_reg, tp_p_ring_ctrl_reg.regValue);

        Base  = READ_REG32(TP_TP_P_RING_BASE_reg);
        Limit = READ_REG32(TP_TP_P_RING_LIMIT_reg);

        /*write ring buffer*/
        WRITE_REG32(TP_TP_P_RING_LIMIT_reg, Limit);
        WRITE_REG32(TP_TP_P_RING_BASE_reg, Base);
        WRITE_REG32(TP_TP_P_RING_RP_reg, Base);
        WRITE_REG32(TP_TP_P_RING_WP_reg, Base);

        tp_p_ring_ctrl_reg.regValue = 0;
        tp_p_ring_ctrl_reg.idx = tpp_id;
        tp_p_ring_ctrl_reg.r_w = 1; /* write */
        WRITE_REG32(TP_TP_P_RING_CTRL_reg, tp_p_ring_ctrl_reg.regValue);

        /*if start,set start last*/
        if (bFrm_en) {
                tp_p_frmcfg_reg.frm_en = 1;
                Tp_TPP_SetFrmReg(tpp_id, tp_p_frmcfg_reg.regValue);
        }

        _tp_unlock();

        TP_TRACE("MTP_ID[%tpp_id] mode = flush \n", tpp_id);

        return TPK_SUCCESS;
}

EXPORT_SYMBOL(RHAL_TPPFlushBuffer);

/*------------------------------------------------------------------
 * Func : RHAL_DisplayTPFramerInformation
 *
 * Desc :
 *
 * Parm : [I] id : TP Index
 *
 * Retn : TPK_SUCCESS
 *------------------------------------------------------------------*/
INT32 RHAL_DisplayTPFramerInformation(TPK_TP_ENGINE_T tp_id)
{
        TP_DisplayTPFramerInformation(tp_id);
}
EXPORT_SYMBOL(RHAL_DisplayTPFramerInformation);
