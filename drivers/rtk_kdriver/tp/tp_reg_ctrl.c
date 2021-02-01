/******************************************************************************
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author yping@realtek.com
 *
 *****************************************************************************/

#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/wait.h>
#include <linux/time.h>
#include <linux/freezer.h>
#include <linux/pageremap.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#ifdef CONFIG_LG_SNAPSHOT_BOOT
#include <linux/suspend.h>
#endif

#include <rbus/sys_reg_reg.h>
#include <rbus/timer_reg.h>
#include <rbus/tp_reg.h>

#include <mach/irqs.h>

#include <base_types.h>
#include <rtk_crt.h>
#include <rtk_cw_util.h>

#include <tp/tp_dbg.h>
#include <tp/tp_drv_global.h>
#include <tp/tp_reg_ctrl.h>

// #include <tp/tp_drv.h>

/* mutex for pid filter seeting */
static DEFINE_MUTEX(tp_pid_mutex);
#define _tp_pid_lock() \
        mutex_lock(&tp_pid_mutex); \
        //Tp_Locker_SetLockFunction("_tp_pid_lock", __FUNCTION__)

#define _tp_pid_unlock() \
        mutex_unlock(&tp_pid_mutex); \
        //Tp_Locker_ClearLockFunction("_tp_pid_lock", __FUNCTION__)

static UINT32 crc_table[256] = {
        0x00000000, 0x04c11db7, 0x09823b6e, 0x0d4326d9, 0x130476dc, 0x17c56b6b,
        0x1a864db2, 0x1e475005, 0x2608edb8, 0x22c9f00f, 0x2f8ad6d6, 0x2b4bcb61,
        0x350c9b64, 0x31cd86d3, 0x3c8ea00a, 0x384fbdbd, 0x4c11db70, 0x48d0c6c7,
        0x4593e01e, 0x4152fda9, 0x5f15adac, 0x5bd4b01b, 0x569796c2, 0x52568b75,
        0x6a1936c8, 0x6ed82b7f, 0x639b0da6, 0x675a1011, 0x791d4014, 0x7ddc5da3,
        0x709f7b7a, 0x745e66cd, 0x9823b6e0, 0x9ce2ab57, 0x91a18d8e, 0x95609039,
        0x8b27c03c, 0x8fe6dd8b, 0x82a5fb52, 0x8664e6e5, 0xbe2b5b58, 0xbaea46ef,
        0xb7a96036, 0xb3687d81, 0xad2f2d84, 0xa9ee3033, 0xa4ad16ea, 0xa06c0b5d,
        0xd4326d90, 0xd0f37027, 0xddb056fe, 0xd9714b49, 0xc7361b4c, 0xc3f706fb,
        0xceb42022, 0xca753d95, 0xf23a8028, 0xf6fb9d9f, 0xfbb8bb46, 0xff79a6f1,
        0xe13ef6f4, 0xe5ffeb43, 0xe8bccd9a, 0xec7dd02d, 0x34867077, 0x30476dc0,
        0x3d044b19, 0x39c556ae, 0x278206ab, 0x23431b1c, 0x2e003dc5, 0x2ac12072,
        0x128e9dcf, 0x164f8078, 0x1b0ca6a1, 0x1fcdbb16, 0x018aeb13, 0x054bf6a4,
        0x0808d07d, 0x0cc9cdca, 0x7897ab07, 0x7c56b6b0, 0x71159069, 0x75d48dde,
        0x6b93dddb, 0x6f52c06c, 0x6211e6b5, 0x66d0fb02, 0x5e9f46bf, 0x5a5e5b08,
        0x571d7dd1, 0x53dc6066, 0x4d9b3063, 0x495a2dd4, 0x44190b0d, 0x40d816ba,
        0xaca5c697, 0xa864db20, 0xa527fdf9, 0xa1e6e04e, 0xbfa1b04b, 0xbb60adfc,
        0xb6238b25, 0xb2e29692, 0x8aad2b2f, 0x8e6c3698, 0x832f1041, 0x87ee0df6,
        0x99a95df3, 0x9d684044, 0x902b669d, 0x94ea7b2a, 0xe0b41de7, 0xe4750050,
        0xe9362689, 0xedf73b3e, 0xf3b06b3b, 0xf771768c, 0xfa325055, 0xfef34de2,
        0xc6bcf05f, 0xc27dede8, 0xcf3ecb31, 0xcbffd686, 0xd5b88683, 0xd1799b34,
        0xdc3abded, 0xd8fba05a, 0x690ce0ee, 0x6dcdfd59, 0x608edb80, 0x644fc637,
        0x7a089632, 0x7ec98b85, 0x738aad5c, 0x774bb0eb, 0x4f040d56, 0x4bc510e1,
        0x46863638, 0x42472b8f, 0x5c007b8a, 0x58c1663d, 0x558240e4, 0x51435d53,
        0x251d3b9e, 0x21dc2629, 0x2c9f00f0, 0x285e1d47, 0x36194d42, 0x32d850f5,
        0x3f9b762c, 0x3b5a6b9b, 0x0315d626, 0x07d4cb91, 0x0a97ed48, 0x0e56f0ff,
        0x1011a0fa, 0x14d0bd4d, 0x19939b94, 0x1d528623, 0xf12f560e, 0xf5ee4bb9,
        0xf8ad6d60, 0xfc6c70d7, 0xe22b20d2, 0xe6ea3d65, 0xeba91bbc, 0xef68060b,
        0xd727bbb6, 0xd3e6a601, 0xdea580d8, 0xda649d6f, 0xc423cd6a, 0xc0e2d0dd,
        0xcda1f604, 0xc960ebb3, 0xbd3e8d7e, 0xb9ff90c9, 0xb4bcb610, 0xb07daba7,
        0xae3afba2, 0xaafbe615, 0xa7b8c0cc, 0xa379dd7b, 0x9b3660c6, 0x9ff77d71,
        0x92b45ba8, 0x9675461f, 0x8832161a, 0x8cf30bad, 0x81b02d74, 0x857130c3,
        0x5d8a9099, 0x594b8d2e, 0x5408abf7, 0x50c9b640, 0x4e8ee645, 0x4a4ffbf2,
        0x470cdd2b, 0x43cdc09c, 0x7b827d21, 0x7f436096, 0x7200464f, 0x76c15bf8,
        0x68860bfd, 0x6c47164a, 0x61043093, 0x65c52d24, 0x119b4be9, 0x155a565e,
        0x18197087, 0x1cd86d30, 0x029f3d35, 0x065e2082, 0x0b1d065b, 0x0fdc1bec,
        0x3793a651, 0x3352bbe6, 0x3e119d3f, 0x3ad08088, 0x2497d08d, 0x2056cd3a,
        0x2d15ebe3, 0x29d4f654, 0xc5a92679, 0xc1683bce, 0xcc2b1d17, 0xc8ea00a0,
        0xd6ad50a5, 0xd26c4d12, 0xdf2f6bcb, 0xdbee767c, 0xe3a1cbc1, 0xe760d676,
        0xea23f0af, 0xeee2ed18, 0xf0a5bd1d, 0xf464a0aa, 0xf9278673, 0xfde69bc4,
        0x89b8fd09, 0x8d79e0be, 0x803ac667, 0x84fbdbd0, 0x9abc8bd5, 0x9e7d9662,
        0x933eb0bb, 0x97ffad0c, 0xafb010b1, 0xab710d06, 0xa6322bdf, 0xa2f33668,
        0xbcb4666d, 0xb8757bda, 0xb5365d03, 0xb1f740b4
};


/*************************

    inner function

**************************/
UINT32 DoCRC32(UINT8 *data, UINT32 len)
{
        UINT32 crc = 0xffffffff, i;
        UINT8 *p = data;

        for(i = 0; i < len; i++)
                crc = (crc << 8) ^ crc_table[((crc >> 24) ^ * (p++)) & 0xff];

        return crc;
}

INT32 MaskMemCmp(UINT8* pData1, UINT8* pData2, UINT8* pMask , UINT16 Len)
{
        UINT16 i;
        for (i = 0; i < Len; i++) {
                if (*pMask && ((*pData1 ^ *pData2) & *pMask))
                        return -1;

                pData1++;
                pData2++;
                pMask++;
        }

        return 0;
}

UINT32 BYTES_TO_LONG(UINT8* pData, UINT8 Len)
{
        UINT32 l = 0;
        UINT8 i;
        if (Len > 4) {
                Len = 4;
        }

        for( i = 0; i < Len; i++) {
                l <<= 8;
                l += pData[i];
        }
        return l;
}

void dump_mem(UINT8* pData, UINT16 Len)
{
        UINT16 i;
        for ( i = 0; i < Len; i++) {
                TP_DBG_SIMPLE( "%02x ", pData[i]);
                if((i % 16) == 15)
                        TP_DBG_SIMPLE( "\n");
        }
        TP_DBG_SIMPLE( "\n");
}

INT32 _PID_Filter_Update_Check(IN TPK_TP_ENGINE_T tp_id,
                               IN TPK_PID_FILTER_PARAM_T PIDParm,
                               OUT UINT16 *pPid_idx,
                               OUT UINT16 *pPid_idx_reg,
                               OUT UINT8 *pUpdate_flag,
                               OUT UINT16 *pMax_pid_cnt,
                               OUT UINT8 *pDdr_q,
                               OUT UINT8 *pInfo_q)
{
        UINT16 i;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE()

        switch(tp_id) {
                case TP_TP0:
                        *pMax_pid_cnt = TP0_PID_FILTER_COUNT;
                        *pDdr_q       = TP0_BUFFER_MASS_DATA;
                        *pInfo_q      = TP0_BUFFER_INFO_PACK;
                        break;
                case TP_TP1:
                        *pMax_pid_cnt = TP1_PID_FILTER_COUNT;
                        *pDdr_q       = TP1_BUFFER_MASS_DATA;
                        *pInfo_q      = TP1_BUFFER_INFO_PACK;
                        break;
                case TP_TP2:
                        *pMax_pid_cnt = TP2_PID_FILTER_COUNT;
                        *pDdr_q       = TP2_BUFFER_MASS_DATA;
                        *pInfo_q      = TP2_BUFFER_INFO_PACK;
                        break;
                case TP_TP3:
                        *pMax_pid_cnt = TP3_PID_FILTER_COUNT;
                        *pDdr_q       = TP3_BUFFER_MASS_DATA;
                        *pInfo_q      = TP3_BUFFER_INFO_PACK;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        if(*pMax_pid_cnt > MAX_PID_PER_TP) {
                TP_WARNING("TP%u define error, max_pid_cnt (%u) is more than MAX_PID_PER_TP (%u)\n",
                           tp_id, *pMax_pid_cnt, MAX_PID_PER_TP);
                return TPK_RESOURCE_CONFLICT;
        }

        /* check PID filter process case:(1)no update(2)update param(3)add new PID filter */
        *pUpdate_flag = PID_ADD;
        for (i = 0; i < *pMax_pid_cnt; i++) {
                if((pTp_drv->tp_pid[tp_id].pid_api_setting[i].valid == 1) &&
                    (pTp_drv->tp_pid[tp_id].pid_api_setting[i].PID == PIDParm.PID)) {
                        if((pTp_drv->tp_pid[tp_id].pid_api_setting[i].DescrambleEn == PIDParm.DescrambleEn) &&
                            (pTp_drv->tp_pid[tp_id].pid_api_setting[i].KeySel == PIDParm.KeySel)) {
                                *pUpdate_flag = PID_NO_UPDATE;
                                break;
                        } else {
                                *pUpdate_flag = PID_UPDATE_PARAM;
                                break;
                        }
                }
        }

        /*  if add a new PID filter, check PID filter index to add */
        if(*pUpdate_flag == PID_ADD) {
                /*  find empty PID filter index to add */
                for ( i = 0; i < *pMax_pid_cnt; i++) {
                        if(pTp_drv->tp_pid[tp_id].pid_api_setting[i].valid == 0) {
                                break;
                        }
                }
                if(i >= *pMax_pid_cnt) {
                        TP_WARNING("TP%u can not find empty PID filter to add (max_pid_cnt=%u)\n", tp_id, *pMax_pid_cnt);
                        return TPK_NOT_ENOUGH_RESOURCE;
                }
        }

        *pPid_idx = i;
        switch(tp_id) {
                case TP_TP0:
                        *pPid_idx_reg = *pPid_idx;
                        break;
                case TP_TP1:
                        *pPid_idx_reg = *pPid_idx + TP0_PID_FILTER_COUNT;
                        break;
                case TP_TP2:
                        *pPid_idx_reg = *pPid_idx + TP0_PID_FILTER_COUNT + TP1_PID_FILTER_COUNT;
                        break;
                case TP_TP3:
                        *pPid_idx_reg = *pPid_idx + TP0_PID_FILTER_COUNT + TP1_PID_FILTER_COUNT + TP2_PID_FILTER_COUNT;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        if(*pPid_idx_reg >= MAX_PID_FILTER_COUNT) {
                TP_WARNING("TP%u PID filter idx error (pid_idx_reg=%u)\n", tp_id, *pPid_idx_reg);
                return TPK_NOT_ENOUGH_RESOURCE;
        }
        return TPK_SUCCESS;
}


/*************************

    basic function

**************************/
void Tp_Write_Data_Reg_Write(REGADDR reg, UINT32 data)
{
        data |= _BIT0;
        WRITE_REG32(reg, data);
        WRITE_REG32(reg, ~data);
}

INT32 Tp_SetTpCtrlReg(TPK_TP_ENGINE_T tp_id, UINT32 bit_sel, UINT8 data)
{
        UINT32 tp_tf_cntl_reg;

        CHECK_MAX_TP_COUNT(tp_id);

        if(data)
                bit_sel |= _BIT0;
        else
                bit_sel &= ~_BIT0;

        switch(tp_id) {
                case TP_TP0:
                        tp_tf_cntl_reg = TP_TP_TF0_CNTL_reg;
                        break;
                case TP_TP1:
                        tp_tf_cntl_reg = TP_TP_TF1_CNTL_reg;
                        break;
                case TP_TP2:
                        tp_tf_cntl_reg = TP_TP_TF2_CNTL_reg;
                        break;
                case TP_TP3:
                        tp_tf_cntl_reg = TP_TP_TF3_CNTL_reg;
                        break;
                default:
                        TP_WARNING("tp_id=%u not support\n", tp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        WRITE_REG32(tp_tf_cntl_reg, bit_sel);

        return TPK_SUCCESS;
}

INT32 Tp_GetTpCtrlReg(TPK_TP_ENGINE_T tp_id, UINT32 *data)
{
        REGADDR tp_tf_cntl_reg;

        CHECK_MAX_TP_COUNT(tp_id);

        switch(tp_id) {
                case TP_TP0:
                        tp_tf_cntl_reg = TP_TP_TF0_CNTL_reg;
                        break;
                case TP_TP1:
                        tp_tf_cntl_reg = TP_TP_TF1_CNTL_reg;
                        break;
                case TP_TP2:
                        tp_tf_cntl_reg = TP_TP_TF2_CNTL_reg;
                        break;
                case TP_TP3:
                        tp_tf_cntl_reg = TP_TP_TF3_CNTL_reg;
                        break;
                default:
                        TP_WARNING("tp_id=%u not support\n", tp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        *data = READ_REG32(tp_tf_cntl_reg);

        return TPK_SUCCESS;
}

INT32 Tp_GetTpFrmReg(TPK_TP_ENGINE_T tp_id, UINT32 *data)
{
        REGADDR tp_tf_frm_reg;

        CHECK_MAX_TP_COUNT(tp_id);

        switch(tp_id) {
                case TP_TP0:
                        tp_tf_frm_reg = TP_TP_TF0_FRMCFG_reg;
                        break;
                case TP_TP1:
                        tp_tf_frm_reg = TP_TP_TF1_FRMCFG_reg;
                        break;
                case TP_TP2:
                        tp_tf_frm_reg = TP_TP_TF2_FRMCFG_reg;
                        break;
                case TP_TP3:
                        tp_tf_frm_reg = TP_TP_TF3_FRMCFG_reg;
                        break;
                default:
                        TP_WARNING("tp_id=%u not support\n", tp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        *data = READ_REG32(tp_tf_frm_reg);

        return TPK_SUCCESS;
}



/*************************

    init function

**************************/
void Tp_Rst_Ring_Buffer_Avail(void)
{
        tp_tp_ring_avail_int_en_RBUS ring_avail_int_en_reg;
        tp_tp_ring_avail_int_RBUS ring_avail_int_reg;

        ring_avail_int_reg.regValue   = 0xffffffff;
        ring_avail_int_reg.res1       = _ZERO;
        ring_avail_int_reg.write_data = _ZERO;
        WRITE_REG32(TP_TP_RING_AVAIL_INT_0_reg, ring_avail_int_reg.regValue);
        WRITE_REG32(TP_TP_RING_AVAIL_INT_1_reg, ring_avail_int_reg.regValue);

        ring_avail_int_en_reg.regValue   = 0xffffffff;
        ring_avail_int_en_reg.res1       = _ZERO;
        ring_avail_int_en_reg.write_data = _ZERO;
        WRITE_REG32(TP_TP_RING_AVAIL_INT_EN_0_reg, ring_avail_int_en_reg.regValue);
        WRITE_REG32(TP_TP_RING_AVAIL_INT_EN_1_reg, ring_avail_int_en_reg.regValue);
}

void Tp_Rst_Ring_Buffer_Full(void)
{
        tp_tp_ring_full_int_en_RBUS ring_full_int_en_reg;
        tp_tp_ring_full_int_RBUS ring_full_int_reg;

        ring_full_int_reg.regValue   = 0xffffffff;
        ring_full_int_reg.res1       = _ZERO;
        ring_full_int_reg.write_data = _ZERO;
        WRITE_REG32(TP_TP_RING_FULL_INT_0_reg, ring_full_int_reg.regValue);
        WRITE_REG32(TP_TP_RING_FULL_INT_1_reg, ring_full_int_reg.regValue);

        ring_full_int_en_reg.regValue   = 0xffffffff;
        ring_full_int_en_reg.res1       = _ZERO;
        ring_full_int_en_reg.write_data = _ZERO;
        WRITE_REG32(TP_TP_RING_FULL_INT_EN_0_reg, ring_full_int_en_reg.regValue);
        WRITE_REG32(TP_TP_RING_FULL_INT_EN_0_reg, ring_full_int_en_reg.regValue);

}
void Tp_Clean_Ring_Buffer_Reg(void)
{
        UINT8 i;
        tp_tp_ring_ctrl_RBUS ring_ctrl_reg;


        /* init threadhole and fullness reg */
        WRITE_REG32(TP_TP_THRESHOLD_reg, TP_BUFFER_WITH_FLOW_CTRL_THRESHOLD);
        WRITE_REG32(TP_TP_FULLNESS_reg, TP_BUFFER_WITH_FLOW_CTRL_THRESHOLD);

        /* clear limit/base/rp/wp reg */
        for(i = 0; i < MAX_TP_BUFFER_COUNT; i++) {
                if(i != 2) { // Because start code search will check ring buffer 2 status, so ring buffer 2 can't set to Zero
                        WRITE_REG32(TP_TP_RING_LIMIT_reg, _ZERO);
                        WRITE_REG32(TP_TP_RING_BASE_reg, _ZERO);
                        WRITE_REG32(TP_TP_RING_RP_reg, _ZERO);
                        WRITE_REG32(TP_TP_RING_WP_reg, _ZERO);

                } else {
                        WRITE_REG32(TP_TP_RING_LIMIT_reg, 0xFF000000);
                        WRITE_REG32(TP_TP_RING_BASE_reg, 0xF0000000);
                        WRITE_REG32(TP_TP_RING_RP_reg, 0xF0000000);
                        WRITE_REG32(TP_TP_RING_WP_reg, 0xF0000000);

                }
                ring_ctrl_reg.regValue = 0;
                ring_ctrl_reg.wm       = 0;
                ring_ctrl_reg.r_w      = 1;    /* write operation */
                ring_ctrl_reg.idx      = i;
                WRITE_REG32(TP_TP_RING_CTRL_reg, ring_ctrl_reg.regValue);
        }

        /* clean interrupt enable and status */
        Tp_Rst_Ring_Buffer_Full();
        Tp_Rst_Ring_Buffer_Avail();

}

void Tp_Clean_PID_Filter_Reg(void)
{
        UINT32 i;
        tp_tp_pid_ctrl_RBUS pid_ctrl_reg;

        for( i = 0; i < MAX_PID_FILTER_COUNT; i++) {
                WRITE_REG32(TP_TP_PID_DATA_reg, _ZERO);
                WRITE_REG32(TP_TP_PID_DATA2_reg, _ZERO);

                pid_ctrl_reg.regValue = 0;
                pid_ctrl_reg.r_w      = 1;    /* write operation */
                pid_ctrl_reg.idx      = i;
                WRITE_REG32(TP_TP_PID_CTRL_reg, pid_ctrl_reg.regValue);
        }
}

void Tp_Clean_Section_Filter_Reg(void)
{
        UINT32 i;
        tp_tp_sec_ctrl_RBUS sec_ctrl_reg;

        for(i = 0; i < MAX_SEC_COUNT; i++) {
                WRITE_REG32(TP_TP_SEC_DATA0_reg, _ZERO);
                WRITE_REG32(TP_TP_SEC_DATA1_reg, _ZERO);
                WRITE_REG32(TP_TP_SEC_DATA2_reg, _ZERO);
                WRITE_REG32(TP_TP_SEC_DATA3_reg, _ZERO);
                WRITE_REG32(TP_TP_SEC_DATA4_reg, _ZERO);
                WRITE_REG32(TP_TP_SEC_DATA5_reg, _ZERO);
                WRITE_REG32(TP_TP_SEC_DATA6_reg, _ZERO);
                WRITE_REG32(TP_TP_SEC_DATA7_reg, _ZERO);
                WRITE_REG32(TP_TP_SEC_DATA8_reg, _ZERO);
                WRITE_REG32(TP_TP_SEC_DATA9_reg, _ZERO);

                sec_ctrl_reg.regValue = 0;
                sec_ctrl_reg.r_w      = 1;    /* write operation */
                sec_ctrl_reg.idx      = i;
                WRITE_REG32(TP_TP_SEC_CTRL_reg, sec_ctrl_reg.regValue);
        }
}

void Tp_Clean_Packet_Count_Reg(void)
{
        TPK_TP_ENGINE_T tp_id;
        REGADDR tp_cnt_reg;
        REGADDR tp_drp_cnt_reg;
        REGADDR tp_err_cnt_reg;

        for( tp_id = TP_TP0; tp_id < MAX_TP_COUNT; tp_id++ ) {
                switch(tp_id) {
                        case TP_TP0:
                                tp_cnt_reg     = TP_TP_TF0_CNT_reg;
                                tp_drp_cnt_reg = TP_TP_TF0_DRP_CNT_reg;
                                tp_err_cnt_reg = TP_TP_TF0_ERR_CNT_reg;
                                break;
                        case TP_TP1:
                                tp_cnt_reg     = TP_TP_TF1_CNT_reg;
                                tp_drp_cnt_reg = TP_TP_TF1_DRP_CNT_reg;
                                tp_err_cnt_reg = TP_TP_TF1_ERR_CNT_reg;
                                break;
                        case TP_TP2:
                                tp_cnt_reg     = TP_TP_TF2_CNT_reg;
                                tp_drp_cnt_reg = TP_TP_TF2_DRP_CNT_reg;
                                tp_err_cnt_reg = TP_TP_TF2_ERR_CNT_reg;
                                break;
                        case TP_TP3:
                                tp_cnt_reg     = TP_TP_TF3_CNT_reg;
                                tp_drp_cnt_reg = TP_TP_TF3_DRP_CNT_reg;
                                tp_err_cnt_reg = TP_TP_TF3_ERR_CNT_reg;
                                break;
                        default:
                                TP_WARNING("unsupported tp_id=%d\n", tp_id);
                                /* return TPK_BAD_PARAMETER; */
                }

                WRITE_REG32(tp_cnt_reg, _ZERO);
                WRITE_REG32(tp_drp_cnt_reg, _ZERO);
                WRITE_REG32(tp_err_cnt_reg, _ZERO);

        }
}

void Tp_GlobalHardwareReset(void)
{
        tp_tp_pid_part_RBUS pid_part_reg;
        tp_tp_dmy_a_RBUS tp_dmy_a_reg;

        if(pTp_drv->hardware_reseted == 0) {
                TP_INFO("enable TP clock\n");
                /* enable TP clock & reset */
                CRT_CLK_OnOff(TP, CLK_ON, NULL);

                /* Set PID Paration */
                /* WRITE_REG32(TP_PID_PART_reg, TP0_PID_FILTER_COUNT); */
                pid_part_reg.regValue = 0;
                pid_part_reg.partition1 = TP0_PID_FILTER_COUNT;
                pid_part_reg.partition2 = TP0_PID_FILTER_COUNT + TP1_PID_FILTER_COUNT;
                pid_part_reg.partition3 = TP0_PID_FILTER_COUNT + TP1_PID_FILTER_COUNT + TP2_PID_FILTER_COUNT;
                WRITE_REG32(TP_TP_PID_PART_reg,  pid_part_reg.regValue);

                /* Initial Value of CRC */
                WRITE_REG32(TP_TP_CRC_INIT_reg, 0xFFFFFFFF);

                /* init all SRAM based reg (buffer, PID filter, section filter) */
                Tp_Clean_Ring_Buffer_Reg();
                Tp_Clean_PID_Filter_Reg();
                Tp_Clean_Section_Filter_Reg();

                /* reset packet count */
                Tp_Clean_Packet_Count_Reg();

                /* init DMY_A */
                /* set TPO clk to no gate - BIT29 */
                /* disable function to protect pid table race condition - BIT3 */
                tp_dmy_a_reg.regValue = 0;
                tp_dmy_a_reg.regValue = READ_REG32(TP_TP_DMY_A_reg);
                //WRITE_REG32(TP_DMY_A_reg,tp_dmy_a_reg.regValue | _BIT29 | _BIT3);
                WRITE_REG32(TP_TP_DMY_A_reg, tp_dmy_a_reg.regValue | _BIT3);

                /* init frame rate control clk */
                WRITE_REG32(TP_TP_MISC_27M_CFG_reg, READ_REG32(TP_TP_MISC_27M_CFG_reg) | TP_TP_MISC_27M_CFG_fr_enable_mask);

                pTp_drv->hardware_reseted = 1;
        }

}

INT32 Tp_rst(TPK_TP_ENGINE_T tp_id)
{
        tp_tp_tf0_cntl_RBUS tp_cntl;
        REGADDR tp_cntl_reg;

        CHECK_MAX_TP_COUNT(tp_id);

        tp_cntl.regValue   = 0;
        tp_cntl.rst_en     = 1;
        Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, 1);
        ndelay(110);

        Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, 0);

        return TPK_SUCCESS;
}

#ifdef TP_PCR_USE_IRQ
static irqreturn_t tp_isr(int this_irq, void *dev_id)
{
        tp_tp_pcr_latch_RBUS pcr_latch;
        RBus_UInt32 regValue;
        UINT8 i;
        UINT8 try_cnt = 0;
        REGADDR tp_tf_int_addr;

        for(i = 0; i < MAX_TP_COUNT; i++) {
                switch (i) {
                        case TP_TP0: {
                                /* tp */
                                tp_tf_int_addr           = TP_TP_TF0_INT_reg;
                                break;
                        }
                        case TP_TP1: {
                                /* tp */
                                tp_tf_int_addr           = TP_TP_TF1_INT_reg;
                                break;
                        }
                        case TP_TP2: {
                                /* tp */
                                tp_tf_int_addr           = TP_TP_TF2_INT_reg;
                                break;
                        }
                        case TP_TP3: {
                                /* tp */
                                tp_tf_int_addr           = TP_TP_TF3_INT_reg;
                                break;
                        }
                        default:
                                break;
                }

                regValue = READ_REG32(tp_tf_int_addr);

                if(TP_TP_TF3_INT_get_adf_pcr_in(regValue)) {
                        pcr_latch.regValue = 0;
                        pcr_latch.latch_ena = 1;
                        switch(i) {
                                case TP_TP0:
                                        pcr_latch.latch_sel = 0;
                                        break;
                                case TP_TP1:
                                        pcr_latch.latch_sel = 1;
                                        break;
                                case TP_TP2:
                                        pcr_latch.latch_sel = 2;
                                        break;
                                case TP_TP3:
                                        pcr_latch.latch_sel = 3;
                                        break;
                                default:
                                        //TP_WARNING("invalid TP Index %u.\n", i);
                                        return IRQ_NONE;
                        }
                        WRITE_REG32(TP_TP_PCR_LATCH_reg, pcr_latch.regValue);

                        while(TP_TP_PCR_LATCH_get_latch_ena(READ_REG32(TP_TP_PCR_LATCH_reg)) && try_cnt++ < 10) {
                                udelay(10);     /* busy wait */
                        }

                        if(TP_TP_PCR_LATCH_get_latch_ena(READ_REG32(TP_TP_PCR_LATCH_reg))) {
                                //TP_WARNING("TP%u Update PCR failed, wait PCR latch timeout.\n", i);
                                return IRQ_NONE;
                        }

                        pTp_drv->tp[i].stc_from_isr = (((UINT64)READ_REG32(TP_TP_PCR_SYSTEM_1_reg)) << 32) + (UINT64)READ_REG32(TP_TP_PCR_SYSTEM_0_reg);
                        pTp_drv->tp[i].pcr_from_isr = (UINT64)READ_REG32(TP_TP_PCR_BASE_reg);

                        if (TP_TP_PCR_EXT_get_pcr_base_hi(READ_REG32(TP_TP_PCR_EXT_reg))) {
                                pTp_drv->tp[i].pcr_from_isr |= ((UINT64) 0x1) << 32;
                        }

                        pTp_drv->tp_pid[i].pcr.pcr_irq_cnt++;
                        WRITE_REG32(tp_tf_int_addr, INT_ADF_PCR_IN);
                }
        }

        return IRQ_HANDLED;
}
#endif

INT32 Tp_init(TPK_TP_ENGINE_T tp_id)
{
        tp_tp_tf0_cntl_RBUS tp_cntl;
        tp_tp_tf0_frmcfg_RBUS tp_frm;
        tp_tp_tf0_int_RBUS tp0_int;
        tp_tp_tf0_int_en_RBUS tp0_int_en;
        tp_tp_sync_rplace_RBUS tp_sync_rplace_reg;

        INT32 result;
        UINT8 info_buf_idx;
        REGADDR tp_cntl_reg, tp_frmcfg_reg, tp_tf_int_reg, tp_tf_int_en_reg;
        TP_BUFFER_PARAM_T info_buf_param;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        if(pTp_drv->tp[tp_id].Inited) {
                /* TP_WARNING("TP%d already inited\n",tp_id); */
                return TPK_SUCCESS;
        }

        /* global reset tp & init tp global register */
        Tp_GlobalHardwareReset();

        /* reset TP framer state machine */
        result = Tp_rst(tp_id);
        if( result != TPK_SUCCESS ) {
                TP_WARNING("Tp_rst() return error (%d)\n", result);
                return result;
        }

        tp_sync_rplace_reg.regValue = READ_REG32(TP_TP_SYNC_RPLACE_reg);

        switch(tp_id) {
                case TP_TP0:
                        tp_cntl_reg      = TP_TP_TF0_CNTL_reg;
                        tp_frmcfg_reg    = TP_TP_TF0_FRMCFG_reg;
                        tp_tf_int_reg    = TP_TP_TF0_INT_reg;
                        tp_tf_int_en_reg = TP_TP_TF0_INT_EN_reg;
                        info_buf_idx     = TP0_BUFFER_INFO_PACK;

                        tp_sync_rplace_reg.tp0 = 0x47;

                        break;
                case TP_TP1:
                        tp_cntl_reg      = TP_TP_TF1_CNTL_reg;
                        tp_frmcfg_reg    = TP_TP_TF1_FRMCFG_reg;
                        tp_tf_int_reg    = TP_TP_TF1_INT_reg;
                        tp_tf_int_en_reg = TP_TP_TF1_INT_EN_reg;
                        info_buf_idx     = TP1_BUFFER_INFO_PACK;

                        tp_sync_rplace_reg.tp1 = 0x47;

                        break;
                case TP_TP2:
                        tp_cntl_reg      = TP_TP_TF2_CNTL_reg;
                        tp_frmcfg_reg    = TP_TP_TF2_FRMCFG_reg;
                        tp_tf_int_reg    = TP_TP_TF2_INT_reg;
                        tp_tf_int_en_reg = TP_TP_TF2_INT_EN_reg;
                        info_buf_idx     = TP2_BUFFER_INFO_PACK;

                        tp_sync_rplace_reg.tp2 = 0x47;

                        break;
                case TP_TP3:
                        tp_cntl_reg      = TP_TP_TF3_CNTL_reg;
                        tp_frmcfg_reg    = TP_TP_TF3_FRMCFG_reg;
                        tp_tf_int_reg    = TP_TP_TF3_INT_reg;
                        tp_tf_int_en_reg = TP_TP_TF3_INT_EN_reg;
                        info_buf_idx     = TP3_BUFFER_INFO_PACK;

                        tp_sync_rplace_reg.tp3 = 0x47;

                        break;

                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;

        }

        /* init control reg */
        tp_cntl.regValue      = 0;
        tp_cntl.null_en       = 1;
        tp_cntl.sync_en       = 1;
        tp_cntl.trerr_en      = 1;
        tp_cntl.tb            = 1;
        tp_cntl.tp_err_fix_en = 1;
        tp_cntl.buf_rdy_ctl   = 1;
        //tp_cntl.dir_dma       = 1;
        Tp_Write_Data_Reg_Write(tp_cntl_reg, tp_cntl.regValue);

        /* init frame reg */
        tp_frm.regValue       = 0;
        tp_frm.sync_byte      = 0x47;
        tp_frm.dropno         = 1;
        tp_frm.lockno         = 1;
        tp_frm.serial         = 1;
        WRITE_REG32(tp_frmcfg_reg, tp_frm.regValue);

        /* clear int status and disable int */
        tp0_int.regValue      = 0;
        WRITE_REG32(tp_tf_int_reg, tp0_int.regValue);
#ifdef TP_PCR_USE_IRQ
        tp0_int_en.regValue   = TP_TP_TF3_INT_adf_pcr_in_mask | TP_TP_TF3_INT_write_data_mask; // Enable adf_pcr_in_en
#else
        tp0_int_en.regValue   = 0;
#endif
        WRITE_REG32(tp_tf_int_en_reg, tp0_int_en.regValue);

        /* set default vaule of sync byte replacement*/
        WRITE_REG32(TP_TP_SYNC_RPLACE_reg, tp_sync_rplace_reg.regValue);

        /* update status */
        pTp_drv->tp[tp_id].Inited           = 1;
        pTp_drv->tp[tp_id].tp_src           = TS_UNMAPPING;
        pTp_drv->tp[tp_id].tp_stream_status = TP_STREAM_STOP;
        pTp_drv->tp[tp_id].tp_param.inited  = 0;
        pTp_drv->tpout[0].tpout_src = TPK_TPOUT_UNMAPPING;
        /* init info pack buffer */
        info_buf_param.Base  = pTp_drv->tp[tp_id].info_pack_buffer.BasePhy;
        info_buf_param.RP    = pTp_drv->tp[tp_id].info_pack_buffer.BasePhy;
        info_buf_param.WP    = pTp_drv->tp[tp_id].info_pack_buffer.BasePhy;
        info_buf_param.Limit = pTp_drv->tp[tp_id].info_pack_buffer.LimitPhy;
        result = Tp_Set_Buffer(info_buf_idx, info_buf_param, BUFFER_WRITE_MASK_NONE);
        if( result != TPK_SUCCESS ) {
                TP_WARNING("TP%u init info buffer error (%d)\n", tp_id, result);
                return result;
        }

#ifdef TP_PCR_USE_IRQ
        if(pTp_drv->tp_irq_enable == 0) {
                if (request_irq(IRQ_TP, tp_isr, IRQF_SHARED, "REALTEK_TP", (void *)pTp_drv) < 0) {
                        TP_WARNING("request_irq Fail on TP%d\n", tp_id);
                } else {
                        TP_WARNING("request_irq Success on TP%d\n", tp_id);
                        pTp_drv->tp_irq_enable = 1;
                }
        }
#endif

        return TPK_SUCCESS;
}

INT32 Tp_uninit(TPK_TP_ENGINE_T tp_id)
{
        INT32 result;
        UINT8 i;
        UINT8 uninit_all;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        if(pTp_drv->tp[tp_id].Inited == 0) {
                TP_WARNING("TP%d did not init yet\n", tp_id);
                return TPK_SUCCESS;
        }

        result = Tp_rst(tp_id);
        if( result == TPK_SUCCESS ) {
                pTp_drv->tp[tp_id].Inited           = 0;
                pTp_drv->tp[tp_id].tp_src           = TS_UNMAPPING;
                pTp_drv->tp[tp_id].tp_stream_status = TP_STREAM_STOP;
                pTp_drv->tp[tp_id].tp_param.inited  = 0;
        }

        uninit_all = 1;
        for ( i = 0; i < MAX_TP_COUNT; i++ ) {
                if (pTp_drv->tp[i].Inited == 1) {
                        TP_INFO("try to disable TP clock.... TP%u is still in inited state\n", i);
                        uninit_all = 0;
                        break;
                }
        }

        if (uninit_all == 1) {
                if(pTp_drv->tp_irq_enable == 1) {
                        free_irq(IRQ_TP, (void *)pTp_drv);
                        pTp_drv->tp_irq_enable = 0;
                        TP_DBG("free_irq on TP%d\n", tp_id);
                }

                TP_INFO("disable TP clock\n");
                /* disable tp clock */
                CRT_CLK_OnOff(TP, CLK_OFF, NULL);
                pTp_drv->hardware_reseted = 0;

                for ( i = 0; i < MAX_TPOUT_COUNT; i++ ) {
                        if ( pTp_drv->tpout[i].mass_buffer.inited == 1 &&
                             pTp_drv->tpout[i].mass_buffer.BaseVir != 0) {
                                dvr_free((void *)pTp_drv->tpout[i].mass_buffer.BaseVir);
                        }
                }
        }

        return result;
}

INT32 Tp_ResetCounter(TPK_TP_ENGINE_T tp_id)
{
        TPK_TP_PKT_CNT_T *ppkt_cnt;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        switch(tp_id) {
                case TP_TP0:
                        WRITE_REG32(TP_TP_TF0_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF0_DRP_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF0_ERR_CNT_reg, _ZERO);

                        break;
                case TP_TP1:
                        WRITE_REG32(TP_TP_TF1_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF1_DRP_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF1_ERR_CNT_reg, _ZERO);

                        break;
                case TP_TP2:
                        WRITE_REG32(TP_TP_TF2_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF2_DRP_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF2_ERR_CNT_reg, _ZERO);

                        break;
                case TP_TP3:
                        WRITE_REG32(TP_TP_TF3_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF3_DRP_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF3_ERR_CNT_reg, _ZERO);

                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }


        ppkt_cnt = &pTp_drv->tp[tp_id].tp_pkt_cnt;
        ppkt_cnt->pkt = 0;
        ppkt_cnt->droppedPkt = 0;
        ppkt_cnt->errorPkt = 0;

        return TPK_SUCCESS;
}



/*************************

    TP setting function

**************************/
// Set the input pin polarity
INT32 Tp_SetInputPol(TPK_TPI_PIN_T tpi, TPK_TP_INPUT_PARAM_T pol)
{
        tp_tp_in_pol_RBUS tp_in_pol_reg;

        tp_in_pol_reg.regValue = READ_REG32(TP_TP_IN_POL_reg);
        switch(tpi) {
                case TP_TPI0:
                        tp_in_pol_reg.tpi_0_clk_pol = pol.clk_pol;
                        tp_in_pol_reg.tpi_0_sync_pol = pol.sync_pol;
                        tp_in_pol_reg.tpi_0_val_pol = pol.val_pol;
                        break;
                case TP_TPI1:
                        tp_in_pol_reg.tpi_1_clk_pol = pol.clk_pol;
                        tp_in_pol_reg.tpi_1_sync_pol = pol.sync_pol;
                        tp_in_pol_reg.tpi_1_val_pol = pol.val_pol;
                        break;
                case TP_TPI2:
                        tp_in_pol_reg.tpi_2_clk_pol = pol.clk_pol;
                        tp_in_pol_reg.tpi_2_sync_pol = pol.sync_pol;
                        tp_in_pol_reg.tpi_2_val_pol = pol.val_pol;
                        break;
                case TP_TPI_demod:
                        tp_in_pol_reg.tpi_demod_clk_pol = pol.clk_pol;
                        tp_in_pol_reg.tpi_demod_sync_pol = pol.sync_pol;
                        tp_in_pol_reg.tpi_demod_val_pol = pol.val_pol;
                        break;
                default:
                        TP_WARNING("unsupported tpi=%d\n", tpi);
                        break;
        }

        pTp_drv->tpi[tpi]  = pol;

        WRITE_REG32(TP_TP_IN_POL_reg, tp_in_pol_reg.regValue);
        return TPK_SUCCESS;
}


INT32 Tp_TPO_Init(UINT8 tpout_id)
{
        TPK_TPOUT_TS_PARAM_T TPOParam;

        if(pTp_drv->tpout[tpout_id].Inited) {
                return TPK_SUCCESS;
        }
        /* output_clk_div_en :1800_0114[4] (TPO clock enable) */
        CRT_CLK_OnOff(TPOUT, CLK_ON, NULL);

        /* set TPO clk = 9Mhz */
        Tp_TPO_SetClkDiv(0x2, 0x5);

        /* TPO Clock Gate Disabled, Sync Duarity = 8 bits */
        memset(&TPOParam, 0, sizeof(TPOParam));
        TPOParam.sync_dur = 1;
        Tp_TPO_SetMode(0, TPOParam);
        pTp_drv->tpout[tpout_id].Inited = 1;

        return TPK_SUCCESS;
}


/*********************************

       TPO clock api

********************************/
/* -----------------------------------------------------------
 In addition, in CI+1.4 mode, we can select output clock rate
 by register output_clk_div_sel which can be set from 0 to 63.

 Note¡G
    clock rate = 250 Mhz /  ((reg_tp_pre_div+2) *(reg_tp_post_div+2))
    that is, minimum clock rate =  62.5 Mhz
    reg_tp_post_div : 1800_0204[11:8]
    reg_tp_pre_div : 1800_0204[7:4]
    output_clk_div_en :1800_0114[4] (TPO clock enable)
------------------------------------------------------------ */
/*------------------------------------------------------------------
 * Func : Tp_TPO_GetClkRate
 *
 * Desc : get TPO clock
 *
 * Parm : OUT: tpo_clk_rate(Mhz)(not float)
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
INT32 Tp_TPO_GetClkRate( INT32 * tpo_clk_rate )
{
        /* clock rate = 250 Mhz / ((reg_tp_pre_div+2) * (reg_tp_post_div+2)) */
        *tpo_clk_rate = 250;
        *tpo_clk_rate /= ((INT32)(SYS_REG_SYS_CLKSEL_get_tp_pre_div(READ_REG32(SYS_REG_SYS_CLKSEL_reg))) + 2);
        *tpo_clk_rate /= ((INT32)(SYS_REG_SYS_CLKSEL_get_tp_post_div(READ_REG32(SYS_REG_SYS_CLKSEL_reg))) + 2);
        return TPK_SUCCESS;
}

/*------------------------------------------------------------------
 * Func : Tp_TPO_SetClkDiv
 *
 * Desc : set clock rate by pre_div and post_div
 *
 * Parm : pre_div : precdiv
 *        post_div  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
INT32 Tp_TPO_SetClkDiv( UINT32 pre_div, UINT32 post_div )
{
        UINT32 reg_sys_clksel;
        UINT32 ori_pre_div, ori_post_div;
        /* clock rate = 250 Mhz / ((reg_tp_pre_div+2) *(reg_tp_post_div + 2)) */

        /*for TPO CLK Debug*/
        if(tp_tpoclk_dbg_en) {
                pre_div  = tp_tpoclk_dbg_div & 0x0F;
                post_div = (tp_tpoclk_dbg_div >> 4) & 0x0F;
        }
        /* original value */
        reg_sys_clksel = READ_REG32(SYS_REG_SYS_CLKSEL_reg);

        ori_pre_div = (reg_sys_clksel & SYS_REG_SYS_CLKSEL_tp_pre_div_mask) >> SYS_REG_SYS_CLKSEL_tp_pre_div_shift;
        ori_post_div = (reg_sys_clksel & SYS_REG_SYS_CLKSEL_tp_post_div_mask) >> SYS_REG_SYS_CLKSEL_tp_post_div_shift;

        if( (ori_pre_div == pre_div) && (ori_post_div == post_div)) {
                TP_DBG("TP Out clk is the same, pre_div=%d post_div=%d\n", pre_div, post_div);
                return TPK_SUCCESS;
        }

        /* clear pre_div */
        reg_sys_clksel &= (~SYS_REG_SYS_CLKSEL_tp_pre_div_mask);
        /* clear post_div */
        reg_sys_clksel &= (~SYS_REG_SYS_CLKSEL_tp_post_div_mask);
        /* set pre_div */
        reg_sys_clksel |= SYS_REG_SYS_CLKSEL_tp_pre_div(pre_div);
        /* set post_div */
        reg_sys_clksel |= SYS_REG_SYS_CLKSEL_tp_post_div(post_div);
        /* write to clock select register */
        WRITE_REG32(SYS_REG_SYS_CLKSEL_reg, reg_sys_clksel);

        TP_DBG("TP Out clk  ori_pre_div=%d ori_post_div=%d pre_div=%d post_div=%d\n", ori_pre_div, ori_post_div, pre_div, post_div);
        return TPK_SUCCESS;
}

INT32 Tp_TPO_GetClkDiv(UINT32 *pre_div, UINT32 *post_div)
{
        UINT32 reg_sys_clksel = READ_REG32(SYS_REG_SYS_CLKSEL_reg);

        *pre_div = (reg_sys_clksel & SYS_REG_SYS_CLKSEL_tp_pre_div_mask) >> SYS_REG_SYS_CLKSEL_tp_pre_div_shift;
        *post_div = (reg_sys_clksel & SYS_REG_SYS_CLKSEL_tp_post_div_mask) >> SYS_REG_SYS_CLKSEL_tp_post_div_shift;
        return TPK_SUCCESS;
}

INT32 Tp_TPO_SetMode(UINT8 tpout_id, TPK_TPOUT_TS_PARAM_T Param)
{
        tp_tp_tf_out_frmcfg_RBUS tp_out_frmcfg;
        tp_tp_out_ctrl_RBUS tp_out_ctrl;

        /* set ts in parameter */
        tp_out_frmcfg.regValue          = READ_REG32(TP_TP_TF_OUT_FRMCFG_reg);
        tp_out_frmcfg.in_serial         = Param.in_serial;
        tp_out_frmcfg.in_data_order     = Param.in_data_order;
        tp_out_frmcfg.in_sync_pol       = Param.in_sync_pol;
        tp_out_frmcfg.in_val_pol        = Param.in_val_pol;
        tp_out_frmcfg.in_clk_pol        = Param.in_clk_pol;

        /* set ts out parameter */
        tp_out_frmcfg.out_serial     = Param.out_serial;
        tp_out_frmcfg.out_data_order = Param.out_data_order;
        tp_out_frmcfg.out_sync_pol   = Param.out_sync_pol;
        tp_out_frmcfg.out_val_pol    = Param.out_val_pol;
        tp_out_frmcfg.out_clk_pol    = Param.out_clk_pol;

        WRITE_REG32(TP_TP_TF_OUT_FRMCFG_reg, tp_out_frmcfg.regValue);

        /* set ts out sync_dur */
        tp_out_ctrl.regValue             = READ_REG32(TP_TP_OUT_CTRL_reg);
        tp_out_ctrl.sync_dur             = Param.sync_dur;
        tp_out_ctrl.ck_gate              = 0;
        WRITE_REG32(TP_TP_OUT_CTRL_reg, tp_out_ctrl.regValue);

        return TPK_SUCCESS;
}

INT32 Tp_TPO_GetMode(UINT8 tpout_id, TPK_TPOUT_TS_PARAM_T *pParam)
{
        tp_tp_tf_out_frmcfg_RBUS tp_out_frmcfg;
        tp_tp_out_ctrl_RBUS tp_out_ctrl;

        tp_out_frmcfg.regValue          = READ_REG32(TP_TP_TF_OUT_FRMCFG_reg);
        pParam->in_serial                       = tp_out_frmcfg.in_serial;
        pParam->in_data_order           = tp_out_frmcfg.in_data_order;
        pParam->in_sync_pol             = tp_out_frmcfg.in_sync_pol;
        pParam->in_val_pol                      = tp_out_frmcfg.in_val_pol;
        pParam->in_clk_pol                      = tp_out_frmcfg.in_clk_pol;

        pParam->out_serial                      = tp_out_frmcfg.out_serial;
        pParam->out_data_order          = tp_out_frmcfg.out_data_order;
        pParam->out_sync_pol            = tp_out_frmcfg.out_sync_pol;
        pParam->out_val_pol                     = tp_out_frmcfg.out_val_pol;
        pParam->out_clk_pol             = tp_out_frmcfg.out_clk_pol;

        tp_out_ctrl.regValue            = READ_REG32(TP_TP_OUT_CTRL_reg);
        pParam->sync_dur                        = tp_out_ctrl.sync_dur;

        return TPK_SUCCESS;
}

INT32 Tp_TPO_SetDataSource(TPK_TP_SOURCE_T src_type)
{
        /**
         TPOUT data from memory               :0xx
         TPOUT data bypass from TPI0 pin in   :100
         TPOUT data bypass from TPI1 pin in   :101
         TPOUT data bypass from TPI2 pin in   :110
         TPOUT data bypass from Internal Demod:111
         **/
        tp_tp_tf_out_frmcfg_RBUS tp_out_frmcfg_reg;

        tp_out_frmcfg_reg.regValue = READ_REG32(TP_TP_TF_OUT_FRMCFG_reg);

        switch(src_type) {
                case MTP:
                        tp_out_frmcfg_reg.data_src = _ZERO;
                        break;
                case Internal_Demod:
                        tp_out_frmcfg_reg.data_src = _BIT0 | _BIT1 | _BIT2;
                        break;
                case TS_SRC_0:
                        tp_out_frmcfg_reg.data_src = _BIT2;
                        break;
                case TS_SRC_1:
                        tp_out_frmcfg_reg.data_src = _BIT0 | _BIT2;
                        break;
                case TS_SRC_2:
                        tp_out_frmcfg_reg.data_src = _BIT1 | _BIT2;
                        break;
                default:
                        TP_WARNING("unsupported TPO source type=%d\n", src_type);
        }
        WRITE_REG32(TP_TP_TF_OUT_FRMCFG_reg, tp_out_frmcfg_reg.regValue);
        return TPK_SUCCESS;
}

INT32 Tp_TPO_StreamControl( UINT8 tpout_id, TPK_TPOUT_STREAM_CTRL_T ctrl)
{
        tp_tp_tf_out_frmcfg_RBUS tp_out_reg;
        tp_tp0_m2m_ring_ctrl_RBUS m2m_ctrl;
        TPK_TPP_ENGINE_T i;

        tp_out_reg.regValue = READ_REG32(TP_TP_TF_OUT_FRMCFG_reg);

        if (ctrl == TPOUT_STREAM_START) {

                if (pTp_drv->tpout[tpout_id].tpout_src == TPK_TP_MTP_TO_TPOUT) { /* TPO from MTP0 */
                        m2m_ctrl.regValue = 0;
                        m2m_ctrl.go   = 1;
                        m2m_ctrl.in_go   = 0;
                        Tp_Write_Data_Reg_Write(TP_TP0_M2M_RING_CTRL_reg, m2m_ctrl.regValue);
                } else if(pTp_drv->tpout[tpout_id].tpout_src == TPK_TPP_TO_TPOUT) { /* TPO from TPP */
                        for(i = TP_TPP0; i < MAX_TP_P_COUNT; i++) {
                                Tp_TPP_FlushBuf(i);
                                Tp_TPP_TPOutControl(i, 1);
                        }
                        Tp_TPP_CheckRingBuffer();
                }

                tp_out_reg.in_tp_rst = 1;
                WRITE_REG32(TP_TP_TF_OUT_FRMCFG_reg, tp_out_reg.regValue);
                udelay(100);

                tp_out_reg.in_tp_rst = 0;
                WRITE_REG32(TP_TP_TF_OUT_FRMCFG_reg, tp_out_reg.regValue);
                udelay(100);

                /* start TP OUT streaming */

                if (pTp_drv->tpout[tpout_id].tpout_src == TPK_TPP_TO_TPOUT)/* TPO from TPP */
                        tp_out_reg.in_tpp_out_en = 1;
                else
                        tp_out_reg.in_tp_out_en = 1;
                WRITE_REG32(TP_TP_TF_OUT_FRMCFG_reg, tp_out_reg.regValue);

#ifdef CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT
                TP_TPInput_Monitor_Init(TPINPUT_MONITOR_TPID);
#endif

        } else {

                if (pTp_drv->tpout[tpout_id].tpout_src == TPK_TP_MTP_TO_TPOUT) { /* TPO from MTP0 */
                        m2m_ctrl.regValue = 0;
                        m2m_ctrl.go   = 0;
                        Tp_Write_Data_Reg_Write(TP_TP0_M2M_RING_CTRL_reg, m2m_ctrl.regValue);
                } else if(pTp_drv->tpout[tpout_id].tpout_src == TPK_TPP_TO_TPOUT) { /* TPO from TPP */
                        for(i = TP_TPP0; i < MAX_TP_P_COUNT; i++) {
                                Tp_TPP_TPOutControl(i, 0);
                        }
                        Tp_TPP_CheckRingBuffer();       // check buffer status
                }

                udelay(10);

                /* stop TP OUT streaming */
                if (pTp_drv->tpout[tpout_id].tpout_src == TPK_TPP_TO_TPOUT)/* TPO from TPP */
                        tp_out_reg.in_tpp_out_en = 0;
                else
                        tp_out_reg.in_tp_out_en = 0;
                WRITE_REG32(TP_TP_TF_OUT_FRMCFG_reg, tp_out_reg.regValue);
#ifdef CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT
                TP_TPInput_Monitor_Uninit(TPINPUT_MONITOR_TPID);
#endif
        }
        return TPK_SUCCESS;
}



/*************************

    ring buffer control

**************************/
UINT8* Tp_Buf_Vir_to_Phy(TPK_TP_ENGINE_T tp_id, UINT8 buffer_flag, UINT8* pVirAddr)
{
        TPK_TP_BUF_T *pBuf_status;

        CHECK_MAX_TP_COUNT_RT_NULL(tp_id);
        CHECK_TP_STRUCTURE_RT_NULL();

        if((buffer_flag == TP_BUFFER_MASS_DATA) ||
            (buffer_flag == TP_BUFFER_SECTION)) {
                /* this buffer is set by upper layer */
                pBuf_status = &pTp_drv->tp[tp_id].mass_buffer;
        } else {
                /* this buffer is init by driver */
                pBuf_status = &pTp_drv->tp[tp_id].info_pack_buffer;
        }

        if(pBuf_status->inited == 0) {
                TP_WARNING("TP%u buffer not init (buffer_flag=%u)\n", tp_id, buffer_flag);
                return NULL;
        }

        if(((UADDRESS)pVirAddr < pBuf_status->BaseVir) ||
            ((UADDRESS)pVirAddr > pBuf_status->LimitVir)) {
                TP_WARNING("TP%u buffer over range (buffer_flag=%u, base=0x%x, limit=0x%x, pAddr=%p)\n",
                           tp_id, buffer_flag, pBuf_status->BaseVir, pBuf_status->LimitVir , pVirAddr);
                return NULL;
        }

        return (UINT8*)(pBuf_status->BasePhy + ((UADDRESS)pVirAddr - pBuf_status->BaseVir));
}

UINT8* Tp_Buf_Phy_to_Vir(TPK_TP_ENGINE_T tp_id, UINT8 buffer_flag, UINT8* pPhyAddr)
{
        TPK_TP_BUF_T *pBuf_status;

        CHECK_MAX_TP_COUNT_RT_NULL(tp_id);
        CHECK_TP_STRUCTURE_RT_NULL();

        if((buffer_flag == TP_BUFFER_MASS_DATA) ||
            (buffer_flag == TP_BUFFER_SECTION)) {
                /*  this buffer is set by upper layer */
                pBuf_status = &pTp_drv->tp[tp_id].mass_buffer;
        } else {
                /*  this buffer is init by driver */
                pBuf_status = &pTp_drv->tp[tp_id].info_pack_buffer;
        }

        if(pBuf_status->inited == 0) {
                TP_WARNING("TP%u buffer not init (buffer_flag=%u)\n", tp_id, buffer_flag);
                return NULL;
        }

        if(((UADDRESS)pPhyAddr < pBuf_status->BasePhy) ||
            ((UADDRESS)pPhyAddr > pBuf_status->LimitPhy)) {
                TP_WARNING("TP%u buffer over range (buffer_flag=%u, base=0x%x, limit=0x%x, pAddr=%p)\n",
                           tp_id, buffer_flag, pBuf_status->BasePhy, pBuf_status->LimitPhy, pPhyAddr);
                return NULL;
        }

        return (UINT8*)(pBuf_status->BaseVir + ((UADDRESS)pPhyAddr - pBuf_status->BasePhy));

}


INT32 Tp_Set_Buffer(UINT8 buf_idx, TP_BUFFER_PARAM_T param, UINT8 write_mask)
{
        tp_tp_ring_ctrl_RBUS buf_ctrl_reg;
        tp_tp_ring_limit_RBUS buf_limit_reg;
        tp_tp_ring_base_RBUS buf_base_reg;
        tp_tp_ring_wp_RBUS buf_wp_reg;
        tp_tp_ring_rp_RBUS buf_rp_reg;
        UADDRESS pPhyBase;
        UADDRESS pPhyLimit;


        CHECK_MAX_BUFFER_COUNT(buf_idx);

        pPhyBase  = param.Base;
        pPhyLimit = param.Limit;
        buf_wp_reg.regValue = (RBus_UInt32)param.WP;
        buf_rp_reg.regValue = (RBus_UInt32)param.RP;

        /* prepare limit reg data */
        buf_limit_reg.regValue = pPhyLimit;
        buf_limit_reg.res1     = 0;

        /* buf_limit_reg.res2=0; */
        if(buf_limit_reg.ring_limit == 0) {
                TP_WARNING("bad parameter, buf_idx=%u, PhyBase=0x%x, size=%u, PhyLimit=0x%x\n",
                           buf_idx, pPhyBase, (pPhyLimit - pPhyBase), pPhyLimit);
                return TPK_BAD_PARAMETER;
        }

        /*  prepare base reg data */
        buf_base_reg.regValue = pPhyBase;
        buf_base_reg.res1     = 0;
        /* buf_base_reg.res2=0; */
        if(buf_limit_reg.ring_limit == 0) {
                TP_WARNING("bad parameter, buf_idx=%u,PhyBase=0x%x,size=%u,PhyLimit=0x%x\n",
                           buf_idx, pPhyBase, (pPhyLimit - pPhyBase), pPhyLimit);
                return TPK_BAD_PARAMETER;

        }
        _tp_buf_lock();
        /*  write reg */
        WRITE_REG32(TP_TP_RING_LIMIT_reg, buf_limit_reg.regValue);
        WRITE_REG32(TP_TP_RING_BASE_reg, buf_base_reg.regValue);
        WRITE_REG32(TP_TP_RING_RP_reg, buf_rp_reg.regValue);
        WRITE_REG32(TP_TP_RING_WP_reg, buf_wp_reg.regValue);

        buf_ctrl_reg.regValue = 0;
        buf_ctrl_reg.wm       = write_mask;
        buf_ctrl_reg.r_w      = 1;
        buf_ctrl_reg.idx      = buf_idx;

        /*  write ctrl reg */
        WRITE_REG32(TP_TP_RING_CTRL_reg, buf_ctrl_reg.regValue);
        _tp_buf_unlock();
        return TPK_SUCCESS;
}

INT32 Tp_Get_Buffer(UINT8 buf_idx, TP_BUFFER_PARAM_T* param)
{
        tp_tp_ring_ctrl_RBUS buf_ctrl_reg;

        /*  check parameter */
        CHECK_MAX_BUFFER_COUNT(buf_idx);

        _tp_buf_lock();
        /*  write ctrl reg (get data from memory) */
        buf_ctrl_reg.regValue = 0;
        buf_ctrl_reg.wm       = 0;
        buf_ctrl_reg.r_w      = 0;
        buf_ctrl_reg.idx      = buf_idx;
        WRITE_REG32(TP_TP_RING_CTRL_reg, buf_ctrl_reg.regValue);

        /*  read reg */
        param->Limit = READ_REG32(TP_TP_RING_LIMIT_reg);
        param->Base  = READ_REG32(TP_TP_RING_BASE_reg);
        param->RP    = READ_REG32(TP_TP_RING_RP_reg);
        param->WP    = READ_REG32(TP_TP_RING_WP_reg);

        _tp_buf_unlock();
        return TPK_SUCCESS;
}

INT32 Tpp_Get_Buffer(UINT8 buf_idx, TP_BUFFER_PARAM_T* param)
{
        tp_tp_p_ring_ctrl_RBUS buf_ctrl_reg;

        /*  check parameter */
        CHECK_TPP_MAX_BUFFER_COUNT(buf_idx);

        _tp_buf_lock();
        /*  write ctrl reg (get data from memory) */
        buf_ctrl_reg.regValue = 0;
        buf_ctrl_reg.wm       = 0;
        buf_ctrl_reg.r_w      = 0;
        buf_ctrl_reg.idx      = buf_idx;
        WRITE_REG32(TP_TP_P_RING_CTRL_reg, buf_ctrl_reg.regValue);

        /*  read reg */
        param->Limit = READ_REG32(TP_TP_P_RING_LIMIT_reg);
        param->Base  = READ_REG32(TP_TP_P_RING_BASE_reg);
        param->RP    = READ_REG32(TP_TP_P_RING_RP_reg);
        param->WP    = READ_REG32(TP_TP_P_RING_WP_reg);

        _tp_buf_unlock();
        return TPK_SUCCESS;
}

INT32 Tp_Set_Buffer_Avail_status(UINT8 buf_idx, UINT8 data)
{
        tp_tp_ring_avail_int_RBUS reg;

        /*  check parameter */
        CHECK_MAX_BUFFER_COUNT(buf_idx);

        reg.regValue = 0;
        switch(buf_idx & 0xf) {
                case 0:
                        reg.ring_avail_0  = 1;
                        break;
                case 1:
                        reg.ring_avail_1  = 1;
                        break;
                case 2:
                        reg.ring_avail_2  = 1;
                        break;
                case 3:
                        reg.ring_avail_3  = 1;
                        break;
                case 4:
                        reg.ring_avail_4  = 1;
                        break;
                case 5:
                        reg.ring_avail_5  = 1;
                        break;
                case 6:
                        reg.ring_avail_6  = 1;
                        break;
                case 7:
                        reg.ring_avail_7  = 1;
                        break;
                case 8:
                        reg.ring_avail_8  = 1;
                        break;
                case 9:
                        reg.ring_avail_9  = 1;
                        break;
                case 10:
                        reg.ring_avail_10 = 1;
                        break;
                case 11:
                        reg.ring_avail_11 = 1;
                        break;
                case 12:
                        reg.ring_avail_12 = 1;
                        break;
                case 13:
                        reg.ring_avail_13 = 1;
                        break;
                case 14:
                        reg.ring_avail_14 = 1;
                        break;
                case 15:
                        reg.ring_avail_15 = 1;
                        break;
                default:
                        break;
        }

        reg.write_data = data;
        if(buf_idx & 0xf0) {
                WRITE_REG32(TP_TP_RING_AVAIL_INT_1_reg, reg.regValue);
        } else {
                WRITE_REG32(TP_TP_RING_AVAIL_INT_0_reg, reg.regValue);
        }

        return TPK_SUCCESS;
}

INT32 Tp_Set_Buffer_Full_status(UINT8 buf_idx, UINT8 data)
{
        tp_tp_ring_full_int_RBUS reg;

        /*  check parameter */
        CHECK_MAX_BUFFER_COUNT(buf_idx);

        reg.regValue = 0;
        switch(buf_idx & 0xf) {
                case 0:
                        reg.ring_full_0  = 1;
                        break;
                case 1:
                        reg.ring_full_1  = 1;
                        break;
                case 2:
                        reg.ring_full_2  = 1;
                        break;
                case 3:
                        reg.ring_full_3  = 1;
                        break;
                case 4:
                        reg.ring_full_4  = 1;
                        break;
                case 5:
                        reg.ring_full_5  = 1;
                        break;
                case 6:
                        reg.ring_full_6  = 1;
                        break;
                case 7:
                        reg.ring_full_7  = 1;
                        break;
                case 8:
                        reg.ring_full_8  = 1;
                        break;
                case 9:
                        reg.ring_full_9  = 1;
                        break;
                case 10:
                        reg.ring_full_10 = 1;
                        break;
                case 11:
                        reg.ring_full_11 = 1;
                        break;
                case 12:
                        reg.ring_full_12 = 1;
                        break;
                case 13:
                        reg.ring_full_13 = 1;
                        break;
                case 14:
                        reg.ring_full_14 = 1;
                        break;
                case 15:
                        reg.ring_full_15 = 1;
                        break;
                default:
                        break;
        }

        reg.write_data = data;
        if(buf_idx & 0xf0) {
                WRITE_REG32(TP_TP_RING_FULL_INT_1_reg, reg.regValue);
        } else {
                WRITE_REG32(TP_TP_RING_FULL_INT_0_reg, reg.regValue);
        }

        return TPK_SUCCESS;
}


INT32 Tp_Get_Buffer_Full_status(UINT8 buf_idx, UINT8* data)
{
        tp_tp_ring_full_int_RBUS reg;

        /*  check parameter */
        CHECK_MAX_BUFFER_COUNT(buf_idx);

        if(buf_idx & 0xf0) {
                reg.regValue = READ_REG32(TP_TP_RING_FULL_INT_1_reg);
        } else {
                reg.regValue = READ_REG32(TP_TP_RING_FULL_INT_0_reg);
        }

        switch(buf_idx & 0xf) {
                case 0:
                        *data = reg.ring_full_0;
                        break;
                case 1:
                        *data = reg.ring_full_1;
                        break;
                case 2:
                        *data = reg.ring_full_2;
                        break;
                case 3:
                        *data = reg.ring_full_3;
                        break;
                case 4:
                        *data = reg.ring_full_4;
                        break;
                case 5:
                        *data = reg.ring_full_5;
                        break;
                case 6:
                        *data = reg.ring_full_6;
                        break;
                case 7:
                        *data = reg.ring_full_7;
                        break;
                case 8:
                        *data = reg.ring_full_8;
                        break;
                case 9:
                        *data = reg.ring_full_9;
                        break;
                case 10:
                        *data = reg.ring_full_10;
                        break;
                case 11:
                        *data = reg.ring_full_11;
                        break;
                case 12:
                        *data = reg.ring_full_12;
                        break;
                case 13:
                        *data = reg.ring_full_13;
                        break;
                case 14:
                        *data = reg.ring_full_14;
                        break;
                case 15:
                        *data = reg.ring_full_15;
                        break;
                default:
                        break;
        }


        return TPK_SUCCESS;
}

INT32 Tp_Set_Buffer_Avail_int_En(UINT8 buf_idx, UINT8 Enable)
{
        tp_tp_ring_avail_int_en_RBUS reg;

        /*  check parameter */
        CHECK_MAX_BUFFER_COUNT(buf_idx);

        reg.regValue = 0;
        switch(buf_idx & 0xf) {
                case 0:
                        reg.ring_avail_0_en  = 1;
                        break;
                case 1:
                        reg.ring_avail_1_en  = 1;
                        break;
                case 2:
                        reg.ring_avail_2_en  = 1;
                        break;
                case 3:
                        reg.ring_avail_3_en  = 1;
                        break;
                case 4:
                        reg.ring_avail_4_en  = 1;
                        break;
                case 5:
                        reg.ring_avail_5_en  = 1;
                        break;
                case 6:
                        reg.ring_avail_6_en  = 1;
                        break;
                case 7:
                        reg.ring_avail_7_en  = 1;
                        break;
                case 8:
                        reg.ring_avail_8_en  = 1;
                        break;
                case 9:
                        reg.ring_avail_9_en  = 1;
                        break;
                case 10:
                        reg.ring_avail_10_en = 1;
                        break;
                case 11:
                        reg.ring_avail_11_en = 1;
                        break;
                case 12:
                        reg.ring_avail_12_en = 1;
                        break;
                case 13:
                        reg.ring_avail_13_en = 1;
                        break;
                case 14:
                        reg.ring_avail_14_en = 1;
                        break;
                case 15:
                        reg.ring_avail_15_en = 1;
                        break;
                default:
                        break;
        }

        reg.write_data = Enable;
        if(buf_idx & 0xf0) {
                WRITE_REG32(TP_TP_RING_AVAIL_INT_EN_1_reg, reg.regValue);
        } else {
                WRITE_REG32(TP_TP_RING_AVAIL_INT_EN_0_reg, reg.regValue);
        }

        return TPK_SUCCESS;
}


INT32 Tp_Set_Buffer_Full_int_En(UINT8 buf_idx, UINT8 Enable)
{
        tp_tp_ring_full_int_en_RBUS reg;

        /*  check parameter */
        CHECK_MAX_BUFFER_COUNT(buf_idx);

        reg.regValue = 0;
        switch(buf_idx & 0xf) {
                case 0:
                        reg.ring_full_0_en  = 1;
                        break;
                case 1:
                        reg.ring_full_1_en  = 1;
                        break;
                case 2:
                        reg.ring_full_2_en  = 1;
                        break;
                case 3:
                        reg.ring_full_3_en  = 1;
                        break;
                case 4:
                        reg.ring_full_4_en  = 1;
                        break;
                case 5:
                        reg.ring_full_5_en  = 1;
                        break;
                case 6:
                        reg.ring_full_6_en  = 1;
                        break;
                case 7:
                        reg.ring_full_7_en  = 1;
                        break;
                case 8:
                        reg.ring_full_8_en  = 1;
                        break;
                case 9:
                        reg.ring_full_9_en  = 1;
                        break;
                case 10:
                        reg.ring_full_10_en = 1;
                        break;
                case 11:
                        reg.ring_full_11_en = 1;
                        break;
                case 12:
                        reg.ring_full_12_en = 1;
                        break;
                case 13:
                        reg.ring_full_13_en = 1;
                        break;
                case 14:
                        reg.ring_full_14_en = 1;
                        break;
                case 15:
                        reg.ring_full_15_en = 1;
                        break;
                default:
                        break;
        }

        reg.write_data = Enable;
        if(buf_idx & 0xf0) {
                WRITE_REG32(TP_TP_RING_FULL_INT_EN_1_reg, reg.regValue);
        } else {
                WRITE_REG32(TP_TP_RING_FULL_INT_EN_0_reg, reg.regValue);
        }

        return TPK_SUCCESS;
}

INT32 Tp_flush_Buf(TPK_TP_ENGINE_T tp_id, UINT8 stop_stream_before_flush, UINT32 buffer_sel)
{
        INT32 result;
        REGADDR fram_reg_addr;
        UINT8 fram_en_save;
        UINT8 buf_idx_mass_data;
        UINT8 buf_idx_info_pack;
        TP_BUFFER_PARAM_T buf_param_mass_data;
        TP_BUFFER_PARAM_T buf_param_info_pack;
        tp_tp_tf0_frmcfg_RBUS tp_frm;

        /*  check parameter */
        CHECK_MAX_TP_COUNT(tp_id);

        if(pTp_drv->tp[tp_id].mass_buffer.inited != 1) {
                TP_WARNING("buffer not init, tp_id=%u\n", tp_id);
                return TPK_NOT_INIT;
        }

        /*  set rp=wp=base for mass data buffer & info pack buffer */
        switch(tp_id) {
                case TP_TP0:
                        buf_idx_mass_data = TP0_BUFFER_MASS_DATA;
                        buf_idx_info_pack = TP0_BUFFER_INFO_PACK;
                        fram_reg_addr     = TP_TP_TF0_FRMCFG_reg;
                        break;
                case TP_TP1:
                        buf_idx_mass_data = TP1_BUFFER_MASS_DATA;
                        buf_idx_info_pack = TP1_BUFFER_INFO_PACK;
                        fram_reg_addr     = TP_TP_TF1_FRMCFG_reg;
                        break;
                case TP_TP2:
                        buf_idx_mass_data = TP2_BUFFER_MASS_DATA;
                        buf_idx_info_pack = TP2_BUFFER_INFO_PACK;
                        fram_reg_addr     = TP_TP_TF2_FRMCFG_reg;
                        break;
                case TP_TP3:
                        buf_idx_mass_data = TP3_BUFFER_MASS_DATA;
                        buf_idx_info_pack = TP3_BUFFER_INFO_PACK;
                        fram_reg_addr     = TP_TP_TF3_FRMCFG_reg;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        if(stop_stream_before_flush) {
                /*  stop streaming */
                tp_frm.regValue = READ_REG32(fram_reg_addr);
                fram_en_save    = tp_frm.frm_en;
                if(fram_en_save) {
                        tp_frm.frm_en = 0;
                        WRITE_REG32(fram_reg_addr, tp_frm.regValue);
                }
        }

        if(buffer_sel & BUF_SEL_MASS_DATA) {
                /*  flush mass data buffer */
                result = Tp_Get_Buffer(buf_idx_mass_data, &buf_param_mass_data);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("get mass data buffer data error, tp_id=%u\n", tp_id);
                        return result;
                }
                buf_param_mass_data.RP = buf_param_mass_data.WP = buf_param_mass_data.Base;
                result = Tp_Set_Buffer(buf_idx_mass_data, buf_param_mass_data, (BUFFER_WRITE_MASK_LIMIT | BUFFER_WRITE_MASK_BASE));
                if(result != TPK_SUCCESS) {
                        TP_WARNING("set mass data buffer data error, tp_id=%u\n", tp_id);
                        return result;
                }

                /*  clear full and avail int status */
                Tp_Set_Buffer_Avail_status(buf_idx_mass_data, _ZERO);
                Tp_Set_Buffer_Full_status(buf_idx_mass_data, _ZERO);
                /*  clear rp/wp record */
                pTp_drv->tp[tp_id].mass_buffer.RP                              = buf_param_mass_data.Base;
                pTp_drv->tp[tp_id].mass_buffer.WP                              = buf_param_mass_data.Base;
                pTp_drv->tp[tp_id].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP] = buf_param_mass_data.Base;
                pTp_drv->tp[tp_id].mass_buffer.RP_Connect[SECTION_BUFFER_RP]   = buf_param_mass_data.Base;

                if ( (pTp_drv->tp[tp_id].Shared_RWPtr.inited == 1) &&
                     (pTp_drv->tp[tp_id].Shared_RWPtr.pRP != NULL) &&
                     (pTp_drv->tp[tp_id].Shared_RWPtr.pWP != NULL)) {
                        UADDRESS flushtoAddr = *pTp_drv->tp[tp_id].Shared_RWPtr.pRP;

                        buf_param_mass_data.RP = flushtoAddr;
                        buf_param_mass_data.WP = flushtoAddr;
                        result = Tp_Set_Buffer(buf_idx_mass_data, buf_param_mass_data,  (BUFFER_WRITE_MASK_LIMIT | BUFFER_WRITE_MASK_BASE));
                        if(result != TPK_SUCCESS) {
                                TP_WARNING("set mass data buffer data error, tp_id=%u\n", tp_id);
                                return result;
                        }

                        *pTp_drv->tp[tp_id].Shared_RWPtr.pWP = flushtoAddr;

                        pTp_drv->tp[tp_id].mass_buffer.RP                              = flushtoAddr;
                        pTp_drv->tp[tp_id].mass_buffer.WP                              = flushtoAddr;
                        pTp_drv->tp[tp_id].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP] = flushtoAddr;
                        pTp_drv->tp[tp_id].mass_buffer.RP_Connect[SECTION_BUFFER_RP]   = flushtoAddr;
                        pTp_drv->tp[tp_id].mass_buffer.RP_Connect[DUMP_BUFFER_RP]      = flushtoAddr;

                        Tp_SetPatternSearchEnable(tp_id, 0);
                        pTp_drv->tp[tp_id].lastWP = 0;
                        pTp_drv->tp[tp_id].old_wp = 0;
                        pTp_drv->tp[tp_id].now_startcode_parsing_address = 0;
                        pTp_drv->tp[tp_id].wp_update_by_startcode = 0;
                        pTp_drv->tp[tp_id].timeout_wp = 0;
                        pTp_drv->tp[tp_id].find_new_start_code = 0;
                        Tp_SetPatternSearchEnable(tp_id, 1);

                        TP_DBG("tp_id=%u flushtoAddr=0x%x\n", tp_id, flushtoAddr);
                }
        }

        if(buffer_sel & BUF_SEL_INFO_PACK) {
                /*  flush info pack buffer */
                result = Tp_Get_Buffer(buf_idx_info_pack, &buf_param_info_pack);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("get info pack buffer data error, tp_id=%u\n", tp_id);
                        return result;
                }

                if(stop_stream_before_flush) {
                        buf_param_info_pack.RP = buf_param_info_pack.Base;
                        buf_param_info_pack.WP = buf_param_info_pack.Base;
                        result = Tp_Set_Buffer(buf_idx_info_pack, buf_param_info_pack, (BUFFER_WRITE_MASK_LIMIT | BUFFER_WRITE_MASK_BASE));
                } else {
                        /*  if did not stop streaming, this is more saved flush way. Only move rp to flush buffer */
                        buf_param_info_pack.RP = buf_param_info_pack.WP;
                        result = Tp_Set_Buffer(buf_idx_info_pack, buf_param_info_pack, (BUFFER_WRITE_MASK_LIMIT | BUFFER_WRITE_MASK_BASE | BUFFER_WRITE_MASK_WP));
                }

                if(result != TPK_SUCCESS) {
                        TP_WARNING("set info pack buffer data error, tp_id=%u\n", tp_id);
                        return result;
                }

                /*  clear full and avail int status */
                Tp_Set_Buffer_Avail_status(buf_idx_info_pack, _ZERO);
                Tp_Set_Buffer_Full_status(buf_idx_info_pack, _ZERO);
                /*  clear rp/wp record */
                if(stop_stream_before_flush) {
                        pTp_drv->tp[tp_id].info_pack_buffer.RP                              = buf_param_info_pack.Base;
                        pTp_drv->tp[tp_id].info_pack_buffer.WP                              = buf_param_info_pack.Base;
                        pTp_drv->tp[tp_id].info_pack_buffer.RP_Connect[INFO_PACK_BUFFER_RP] = buf_param_info_pack.Base;
                } else {
                        pTp_drv->tp[tp_id].info_pack_buffer.RP                              = buf_param_info_pack.WP;
                        pTp_drv->tp[tp_id].info_pack_buffer.RP_Connect[INFO_PACK_BUFFER_RP] = buf_param_info_pack.WP;

                }
        }

        /* flush TP buffer */
        if( (buffer_sel & BUF_SEL_MASS_DATA) && (buffer_sel & BUF_SEL_INFO_PACK) ) {
                pTp_drv->tp[tp_id].buffer_flush_flag = 1;
        }

        if(stop_stream_before_flush) {
                /*  framer enble =1 */
                if(fram_en_save) {
                        tp_frm.frm_en = 1;
                        WRITE_REG32(fram_reg_addr, tp_frm.regValue);
                }
        }
        return TPK_SUCCESS;

}

INT32 Tp_flush_Buf_RP(TPK_TP_ENGINE_T tp_id, UINT32 rp_sel, RP_FLUSH_MODE_T mode)
{
        INT32 result;
        TP_BUFFER_PARAM_T buf_param;
        UINT8 buf_idx;
        UINT8 rp_idx;
        UADDRESS flush_ptr;
        TPK_TP_BUF_T *pBuf_status;

        /*  check parameter */
        CHECK_MAX_TP_COUNT(tp_id);

        if(pTp_drv->tp[tp_id].mass_buffer.inited != 1) {
                TP_WARNING("buffer not init, tp_id=%u\n", tp_id);
                return TPK_NOT_INIT;
        }

        /*  set rp=wp=base for mass data buffer & info pack buffer */
        switch(tp_id) {
                case TP_TP0:
                        if( (rp_sel == TP_BUFFER_MASS_DATA) ||
                            (rp_sel == TP_BUFFER_SECTION)) {
                                buf_idx     = TP0_BUFFER_MASS_DATA;
                                rp_idx      = (rp_sel == TP_BUFFER_MASS_DATA) ? MASS_DATA_BUFFER_RP : SECTION_BUFFER_RP;
                                pBuf_status = &pTp_drv->tp[tp_id].mass_buffer;
                        } else {
                                buf_idx     = TP0_BUFFER_INFO_PACK;
                                rp_idx      = INFO_PACK_BUFFER_RP;
                                pBuf_status = &pTp_drv->tp[tp_id].info_pack_buffer;
                        }
                        break;
                case TP_TP1:
                        if( (rp_sel == TP_BUFFER_MASS_DATA) ||
                            (rp_sel == TP_BUFFER_SECTION)) {
                                buf_idx     = TP1_BUFFER_MASS_DATA;
                                rp_idx      = (rp_sel == TP_BUFFER_MASS_DATA) ? MASS_DATA_BUFFER_RP : SECTION_BUFFER_RP;
                                pBuf_status = &pTp_drv->tp[tp_id].mass_buffer;
                        } else {
                                buf_idx     = TP1_BUFFER_INFO_PACK;
                                rp_idx      = INFO_PACK_BUFFER_RP;
                                pBuf_status = &pTp_drv->tp[tp_id].info_pack_buffer;
                        }
                        break;
                case TP_TP2:
                        if( (rp_sel == TP_BUFFER_MASS_DATA) ||
                            (rp_sel == TP_BUFFER_SECTION)) {
                                buf_idx     = TP2_BUFFER_MASS_DATA;
                                rp_idx      = (rp_sel == TP_BUFFER_MASS_DATA) ? MASS_DATA_BUFFER_RP : SECTION_BUFFER_RP;
                                pBuf_status = &pTp_drv->tp[tp_id].mass_buffer;
                        } else {
                                buf_idx     = TP2_BUFFER_INFO_PACK;
                                rp_idx      = INFO_PACK_BUFFER_RP;
                                pBuf_status = &pTp_drv->tp[tp_id].info_pack_buffer;
                        }
                        break;
                case TP_TP3:
                        if( (rp_sel == TP_BUFFER_MASS_DATA) ||
                            (rp_sel == TP_BUFFER_SECTION)) {
                                buf_idx     = TP3_BUFFER_MASS_DATA;
                                rp_idx      = (rp_sel == TP_BUFFER_MASS_DATA) ? MASS_DATA_BUFFER_RP : SECTION_BUFFER_RP;
                                pBuf_status = &pTp_drv->tp[tp_id].mass_buffer;
                        } else {
                                buf_idx     = TP3_BUFFER_INFO_PACK;
                                rp_idx      = INFO_PACK_BUFFER_RP;
                                pBuf_status = &pTp_drv->tp[tp_id].info_pack_buffer;
                        }
                        break;
                default:
                        TP_WARNING("bad parameter, tp_id=%u\n", tp_id);
                        return TPK_BAD_PARAMETER;

        }

        /*  flush mass data buffer */
        result = Tp_Get_Buffer(buf_idx, &buf_param);
        if(result != TPK_SUCCESS) {
                TP_WARNING("get mass data buffer data error, tp_id=%u\n", tp_id);
                return result;
        }

        if(mode == RP_FLUSH_TO_WP)
                flush_ptr = buf_param.WP;
        else
                flush_ptr = buf_param.Base;

        /*  clear rp/wp record */
        pBuf_status->RP_Connect[rp_idx] = flush_ptr;

#if 0
        /*  clear full and avail int status */
        Tp_Set_Buffer_Avail_status(buf_idx, _ZERO);
        Tp_Set_Buffer_Full_status(buf_idx, _ZERO);
#endif

        return TPK_SUCCESS;

}

UINT32 Tp_Check_WP_Alignment(UINT8 buf_idx, UINT32 block_size)
{
        TP_BUFFER_PARAM_T buf_param;

        CHECK_MAX_BUFFER_COUNT(buf_idx);

        Tp_Get_Buffer(buf_idx, &buf_param);

        return ((buf_param.WP - buf_param.Base) % block_size);
}

void Tp_Update_Buffer_RP(TPK_TP_ENGINE_T tp_id, UINT8 buf_idx, TPK_TP_BUF_T *pBuf_status)
{
        TP_BUFFER_PARAM_T Param;
        UINT32 max_remain = 0, i = 0;
        UINT32 remain;
        UADDRESS RP_tmp;

        CHECK_MAX_TP_COUNT_RT_VOID(tp_id);
        CHECK_MAX_BUFFER_COUNT_RT_VOID(buf_idx);

        Tp_Get_Buffer(buf_idx, &Param);

        for (i = 0; i < pBuf_status->RP_Connect_cnt; i++) {
                RP_tmp = pBuf_status->RP_Connect[i];

                if ((RP_tmp != INVALID_BUFFER) &&
                    (RP_tmp >= Param.Base) &&
                    (RP_tmp < Param.Limit) ) {
                        /* Wrap ?? */ /* no Wrap */
                        remain = (RP_tmp > Param.WP) ? ((Param.Limit - RP_tmp) + (Param.WP - Param.Base)) : (Param.WP - RP_tmp) ;

                        if (remain >= max_remain) {
                                max_remain = remain;
                                Param.RP   = RP_tmp;
                        }
                }
        }

        Tp_Set_Buffer(buf_idx, Param, (BUFFER_WRITE_MASK_LIMIT | BUFFER_WRITE_MASK_BASE | BUFFER_WRITE_MASK_WP));

#if 0
        Tp_Set_Buffer_Full_status(buf_idx, 0);
        Tp_Set_Buffer_Avail_status(buf_idx, 0);
#endif
}


INT32 TP_ReadData(TPK_TP_ENGINE_T tp_id, UINT8** ppReadPhyPtr, UINT32* pContinueReadSize,
                  UINT32 Threshold, UINT8 buffer_flag)
{
        TP_BUFFER_PARAM_T buf_param;
        INT32 result, block_size, buf_cnt_tmp;
        UINT8 buf_idx = 0, full_stataus;
        UINT8 rp_idx;
        TPK_TP_BUF_T *pBuf;
        UINT8 *pFirst_byte_vir;
        tp_tp_tf0_cntl_RBUS tp_ctrl;
        tp_tp_tf0_frmcfg_RBUS tp_frm;
        REGADDR fram_reg_addr;
#ifdef CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT
        UINT8 check_tpout_status;
#endif

        /*  check parameter */
        if((ppReadPhyPtr == NULL) || (pContinueReadSize == NULL)) {
                TP_WARNING("bad parameter, ppReadPhyPtr=%p, pContinueReadSize=%p\n",
                           ppReadPhyPtr, pContinueReadSize);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        if ( buffer_flag == TP_BUFFER_SECTION || buffer_flag == TP0_BUFFER_INFO_PACK ) {
                pTp_drv->tp[tp_id].buffer_flush_flag = 0;
        }

#ifdef CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT
	for(check_tpout_status=0;check_tpout_status<MAX_TPOUT_COUNT; check_tpout_status++)
	{
		if( (pTp_drv->tpout[check_tpout_status].tpout_stream_status == TPOUT_STREAM_START) && (buffer_flag == TP_BUFFER_SECTION) )
		{
			UINT32 tp_cnt_reg;
			UINT8 check_tp_connect_status;
			UINT8 need_to_change_TP_source = 0;

			switch(TPINPUT_MONITOR_TPID)
			{
				case TP_TP0:
					tp_cnt_reg     = TP_TP_TF0_CNT_reg;
					break;
				case TP_TP1:
					tp_cnt_reg     = TP_TP_TF1_CNT_reg;
					break;
				case TP_TP2:
					tp_cnt_reg     = TP_TP_TF2_CNT_reg;
					break;
				case TP_TP3:
					tp_cnt_reg     = TP_TP_TF3_CNT_reg;
					break;
				default:
					break;
			}

			if(pTp_drv->tpout[check_tpout_status].tpout_src == TPK_TPP_TO_TPOUT)
			{
				for(check_tp_connect_status=0; check_tp_connect_status<MAX_TP_COUNT;check_tp_connect_status++)
				{
					if(pTp_drv->tpout[check_tpout_status].tpout_remux[check_tp_connect_status].is_connected==1)
					{
						if(READ_REG32(tp_cnt_reg)!=0 && (pTp_drv->need_to_change_input_source[check_tp_connect_status]==1))
						{
							need_to_change_TP_source = 1;
						}
					}
				}
			}
			else
			{
				if(pTp_drv->tpout[check_tpout_status].tpout_stream_status == TPOUT_STREAM_START)
				{
					if(READ_REG32(tp_cnt_reg)!=0 && (pTp_drv->need_to_change_input_source[tp_id]==1))
					{
						need_to_change_TP_source = 1;
						check_tp_connect_status = tp_id;
					}
				}
			}

			if(need_to_change_TP_source == 1)
			{
				tp_tp_tf0_cntl_RBUS tp_cntl;
				UINT32 tp_cntl_reg;

				switch(check_tp_connect_status)
				{
					case TP_TP0:
						tp_cntl_reg     = TP_TP_TF0_CNTL_reg;
						break;
					case TP_TP1:
						tp_cntl_reg     = TP_TP_TF1_CNTL_reg;
						break;
					case TP_TP2:
						tp_cntl_reg     = TP_TP_TF2_CNTL_reg;
						break;
					case TP_TP3:
						tp_cntl_reg     = TP_TP_TF3_CNTL_reg;
						break;
					default:
						tp_cntl_reg     = TP_TP_TF0_CNTL_reg;
						break;
				}

				tp_cntl.regValue = 0;
				tp_cntl.regValue = READ_REG32(tp_cntl_reg);

				tp_cntl.src_sel_h = 0;
				tp_cntl.src_sel_l = 1;

				Tp_Write_Data_Reg_Write(tp_cntl_reg, tp_cntl.regValue);
				pTp_drv->need_to_change_input_source[check_tp_connect_status] = 0;

				TP_WARNING("Change TP%d source to %d!\n", check_tp_connect_status, (READ_REG32(tp_cntl_reg) & (TP_TP_TF0_CNTL_src_sel_h_mask | TP_TP_TF0_CNTL_src_sel_l_mask)) > TP_TP_TF0_CNTL_src_sel_l_shift);
				TP_TPInput_Monitor_Uninit(TPINPUT_MONITOR_TPID);
			}
			WRITE_REG32(tp_cnt_reg, 0);
		}
	}
#endif

        switch(tp_id) {
                case TP_TP0:
                        if( buffer_flag == TP_BUFFER_MASS_DATA ) {
                                buf_idx    = TP0_BUFFER_MASS_DATA;
                                rp_idx     = MASS_DATA_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else if( buffer_flag == TP_BUFFER_SECTION ) {
                                buf_idx    = TP0_BUFFER_SECTION_DATA;
                                rp_idx     = SECTION_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else { /* (buffer_flag == TP_BUFFER_INFO_PACK) */
                                buf_idx    = TP0_BUFFER_INFO_PACK;
                                rp_idx     = INFO_PACK_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].info_pack_buffer;
                                block_size = INFO_PACK_BUFFER_BLOCK_SIZE;
                        }

                        fram_reg_addr = TP_TP_TF0_FRMCFG_reg;
                        break;
                case TP_TP1:
                        if( buffer_flag == TP_BUFFER_MASS_DATA ) {
                                buf_idx    = TP1_BUFFER_MASS_DATA;
                                rp_idx     = MASS_DATA_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else if( buffer_flag == TP_BUFFER_SECTION) {
                                buf_idx    = TP1_BUFFER_SECTION_DATA;
                                rp_idx     = SECTION_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else { /* (buffer_flag == TP_BUFFER_INFO_PACK) */
                                buf_idx    = TP1_BUFFER_INFO_PACK;
                                rp_idx     = INFO_PACK_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].info_pack_buffer;
                                block_size = INFO_PACK_BUFFER_BLOCK_SIZE;
                        }
                        fram_reg_addr = TP_TP_TF1_FRMCFG_reg;
                        break;
                case TP_TP2:
                        if( buffer_flag == TP_BUFFER_MASS_DATA ) {
                                buf_idx    = TP2_BUFFER_MASS_DATA;
                                rp_idx     = MASS_DATA_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else if( buffer_flag == TP_BUFFER_SECTION) {
                                buf_idx    = TP2_BUFFER_SECTION_DATA;
                                rp_idx     = SECTION_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else { /* (buffer_flag == TP_BUFFER_INFO_PACK) */
                                buf_idx    = TP2_BUFFER_INFO_PACK;
                                rp_idx     = INFO_PACK_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].info_pack_buffer;
                                block_size = INFO_PACK_BUFFER_BLOCK_SIZE;
                        }
                        fram_reg_addr = TP_TP_TF2_FRMCFG_reg;
                        break;
                case TP_TP3:
                        if( buffer_flag == TP_BUFFER_MASS_DATA ) {
                                buf_idx    = TP3_BUFFER_MASS_DATA;
                                rp_idx     = MASS_DATA_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else if( buffer_flag == TP_BUFFER_SECTION) {
                                buf_idx    = TP3_BUFFER_SECTION_DATA;
                                rp_idx     = SECTION_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else { /* (buffer_flag == TP_BUFFER_INFO_PACK) */
                                buf_idx    = TP3_BUFFER_INFO_PACK;
                                rp_idx     = INFO_PACK_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].info_pack_buffer;
                                block_size = INFO_PACK_BUFFER_BLOCK_SIZE;
                        }
                        fram_reg_addr = TP_TP_TF3_FRMCFG_reg;
                        break;
                default:
                        TP_WARNING("bad parameter, tp_id=%u\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        if((pBuf->inited == 0) ||
            (pTp_drv->tp[tp_id].tp_stream_status != TP_STREAM_START)) {
                TP_WARNING("buffer not init, tp_id=%u, pBuf->inited=%u, buffer_flag=%u, tp_stream_status=%u\n",
                           tp_id,
                           pBuf->inited,
                           buffer_flag,
                           pTp_drv->tp[tp_id].tp_stream_status);
                return TPK_NOT_INIT;
        }


        /* get buffer register */
        result = Tp_Get_Buffer(buf_idx, &buf_param);
        if(result != TPK_SUCCESS) {
                TP_WARNING("TP%d get buffer status fail(buf_idx=%u)!\n", tp_id, buf_idx);
                return result;
        }

        if( (buffer_flag != TP_BUFFER_INFO_PACK) &&
            (pTp_drv->tp[tp_id].IsMassBufferFull) ) {
                buf_cnt_tmp = GET_BUFF_DATA_ALL_SIZE(buf_param);

                if(buf_cnt_tmp < ( GET_BUFF_SIZE(buf_param) / 10)) {
                        TP_WARNING("TP%u mass data buffer(buffer_flag=%d, buf_idx=%d) empty detected, RESTART streaming\n", tp_id, buffer_flag, buf_idx);
#if 0
                        if(pTp_drv->tp[tp_id].tp_src != MTP) {
                                /* reset framer */
                                Tp_rst(tp_id);

                                /* flush buffer and clean full/alive status */
                                Tp_flush_Buf(tp_id, 0, (BUF_SEL_MASS_DATA | BUF_SEL_INFO_PACK));
                        } else {
                                /* clear full and avail int status */
                                Tp_Set_Buffer_Avail_status(buf_idx, _ZERO);
                                Tp_Set_Buffer_Full_status(buf_idx, _ZERO);
                        }
#endif
                        /* clear full and avail int status */
                        Tp_Set_Buffer_Avail_status(buf_idx, _ZERO);
                        Tp_Set_Buffer_Full_status(buf_idx, _ZERO);

                        /* frame enable = 1 */
                        Tp_ENG_FrameEnable(tp_id, 1);

                        pTp_drv->tp[tp_id].IsMassBufferFull = 0;
                }
                Tp_Update_Buffer_RP(tp_id ,buf_idx,pBuf);
        }


        /* replace RP with mess data RP */
        buf_param.RP  = pBuf->RP_Connect[rp_idx];
        *ppReadPhyPtr = (UINT8*)pBuf->RP_Connect[rp_idx];


        /* check limit and base */
        if((buf_param.Base == 0) || (buf_param.Limit == 0)) {
                TP_WARNING("buffer not init!(tp_id=%u, buf_idx=%d, Base=0x%x, Limit=0x%x)\n",
                           tp_id, buf_idx, buf_param.Base, buf_param.Limit);
                return TPK_NOT_INIT;
        }

        /* check aligment for WP */
        if((buf_param.WP - buf_param.Base) % block_size) {
                TP_WARNING("WP error, not alignment (tp_id=%u, Base=0x%x, Limit=0x%x, WP=0x%x, block_size=%d, buf_flag=%u, buf_idx=%d)\n",
                           tp_id, buf_param.Base, buf_param.Limit, buf_param.WP, block_size, buffer_flag, buf_idx);

                /* flush buffer */
                Tp_flush_Buf(tp_id, 1, (BUF_SEL_MASS_DATA | BUF_SEL_INFO_PACK));
                return TPK_BUFFER_UNALIGNMENT;
        }

        /* calucate length */
        *pContinueReadSize = GET_BUFF_DATA_SIZE(buf_param);     /* no Wrap */

        if( ((buffer_flag == TP_BUFFER_MASS_DATA) || (buffer_flag == TP_BUFFER_SECTION )) &&
            (*pContinueReadSize != 0) ) {
                /* check if first data is not 0x47 */
                pFirst_byte_vir = Tp_Buf_Phy_to_Vir(tp_id, buffer_flag, *ppReadPhyPtr);
                if(pFirst_byte_vir == NULL) {
                        TP_WARNING("TP%u get TSP start virtual pointer error, buf_flag=%u, buf_idx=%d\n", tp_id, buffer_flag, buf_idx);
                        return TPK_NOT_INIT;
                }

                if (pTp_drv->tp[tp_id].IsPktWithTimeStamp == 1) {
                        pFirst_byte_vir = pFirst_byte_vir + TIME_STAMP_PADDING;
                }
                Tp_GetTpCtrlReg(tp_id, &tp_ctrl);
                if (pFirst_byte_vir[0] != 0x47 && !tp_ctrl.dir_dma) {
                        TP_WARNING("TP%u first byte != 0x47 (buf_flag=%u, buf_idx=%u, rp_idx=%u, base=0x%x, limit=0x%x, rp=0x%x, wp=0x%x, data= 0x%x 0x%x 0x%x 0x%x)\n",
                                   tp_id,
                                   buffer_flag, buf_idx, rp_idx,
                                   buf_param.Base, buf_param.Limit, buf_param.RP, buf_param.WP,
                                   pFirst_byte_vir[0], pFirst_byte_vir[1], pFirst_byte_vir[2], pFirst_byte_vir[3]);
                }
        }

        /* check aligment for length */
        if((*pContinueReadSize) % block_size) {
                TP_WARNING("mass data length error, not alignment (tp_id=%u,Base=0x%x,Limit=0x%x,WP=0x%x, MASS_DATA_RP=0x%x)\n",
                           tp_id, buf_param.Base, buf_param.Limit , buf_param.WP, buf_param.RP);

                /* flush buffer */
                /* Tp_flush_Buf(tp_id,1,(BUF_SEL_MASS_DATA | BUF_SEL_INFO_PACK)); */
                return TPK_BUFFER_UNALIGNMENT;
        }

        /* check if buffer full, flush buffer */
        result = Tp_Get_Buffer_Full_status(buf_idx, &full_stataus);
        if(result != TPK_SUCCESS) {
                TP_WARNING("get TP%u buffer full status fail (result=%d)\n", tp_id, result);
                return result;
        }

        if(full_stataus) {
                //Tp_Get_Buffer(buf_idx, &buf_param);

                if(pTp_drv->tp[tp_id].tp_src != MTP) {
                        if (!TP_HAS_FLAG(logStatusFlag[tp_id], TP_STATUS_LOG_FLAG_MASSBUFFFULL)) {

                                TP_WARNING("TP%u buffer full detect (buf_flag=%u, buf_idx=%u, threshold=%u, rp=0x%x(0x%x/0x%x/0x%x), wp=0x%x, base=0x%x, limit=0x%x, real_sz=%u, rt_sz=%u)\n",
                                           tp_id, buffer_flag, buf_idx,
                                           READ_REG32(TP_TP_THRESHOLD_reg),
                                           buf_param.RP,
                                           pBuf->RP_Connect[0], pBuf->RP_Connect[1], pBuf->RP_Connect[2],
                                           buf_param.WP, buf_param.Base, buf_param.Limit,
                                           GET_BUFF_DATA_ALL_SIZE(buf_param),
                                           *pContinueReadSize);
                                TP_SET_FLAG(logStatusFlag[tp_id], TP_STATUS_LOG_FLAG_MASSBUFFFULL);
                        }
                }

                /*  flush info pack buffer only if buffer full detected. */
                /*  Mass data buffer will be released by upper api */
                if(buffer_flag == TP_BUFFER_INFO_PACK) {
                        Tp_flush_Buf(tp_id, 0, BUF_SEL_INFO_PACK);
                } else {
                        if (!pTp_drv->tp[tp_id].IsMassBufferFull) {
                                TP_WARNING("TP%u mass data buffer(buffer_flag=%d, buf_idx=%d) full detected, STOP streaming\n", tp_id, buffer_flag, buf_idx);
                                /*  frame enable =0 */
                                tp_frm.regValue = READ_REG32(fram_reg_addr);
                                tp_frm.frm_en   = 0;
                                WRITE_REG32(fram_reg_addr, tp_frm.regValue);

                                /*  reset framer */
                                Tp_rst(tp_id);
                                pTp_drv->tp[tp_id].IsMassBufferFull = 1;
                        }
                }

                return  TPK_BUFFER_FULL;
        } else {
                if(pTp_drv->tp[tp_id].tp_src != MTP &&
                    buffer_flag == TP_BUFFER_MASS_DATA &&
                    !(pTp_drv->tp[tp_id].IsMassBufferFull) &&
                    TP_HAS_FLAG(logStatusFlag[tp_id], TP_STATUS_LOG_FLAG_MASSBUFFFULL)) {
                        TP_WARNING("TP%u mass buffer normally!(buf_flag=%u, buf_idx=%u, threshold=%u, rp=0x%x(0x%x/0x%x/0x%x), wp=0x%x, base=0x%x, limit=0x%x, real_sz=%u, rt_sz=%u)\n",
                                   tp_id, buffer_flag, buf_idx,
                                   READ_REG32(TP_TP_THRESHOLD_reg),
                                   buf_param.RP,
                                   pBuf->RP_Connect[0], pBuf->RP_Connect[1], pBuf->RP_Connect[2],
                                   buf_param.WP, buf_param.Base, buf_param.Limit,
                                   GET_BUFF_DATA_ALL_SIZE(buf_param),
                                   *pContinueReadSize);
                        TP_CLEAR_FLAG(logStatusFlag[tp_id], TP_STATUS_LOG_FLAG_MASSBUFFFULL);
                }
        }

        /*  check if length is less than threshold */
        if ( ( *pContinueReadSize >= Threshold ) || ( buf_param.RP > buf_param.WP) )
                result = TPK_SUCCESS;
        else if ( *pContinueReadSize == 0 )
                result = TPK_BUFFER_EMPTY;
        else
                result = TPK_BUFFER_UNDER_THRESHOLD;
        if(result != TPK_SUCCESS) {
                TP_VERBOSE("buffer length(%u) is less than threshold(%u)\n", *pContinueReadSize, Threshold);
        }

        return result;
}



INT32 TP_ReleaseData( TPK_TP_ENGINE_T tp_id, UINT8* pReadPhyPtr, UINT32 Size, UINT8 buffer_flag)
{
        TP_BUFFER_PARAM_T buf_param;
        INT32 result = 0, block_size;
        UINT32 Offset;
        UINT8 buf_idx = 0;
        UINT8 rp_idx;
        TPK_TP_BUF_T *pBuf;
        UINT32 buff_data_size = 0;

        /*  check parameter */
        if(Size == 0) {
                /*  do nothing if size is 0 */
                return TPK_SUCCESS;
        }

        if((pReadPhyPtr == NULL)) {
                TP_WARNING("bad parameter, pReadPhyPtr=%p\n", pReadPhyPtr);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        switch(tp_id) {
                case TP_TP0:
                        if(buffer_flag == TP_BUFFER_MASS_DATA) {
                                buf_idx    = TP0_BUFFER_MASS_DATA;
                                rp_idx     = MASS_DATA_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else if(buffer_flag == TP_BUFFER_SECTION) {
                                buf_idx    = TP0_BUFFER_MASS_DATA;
                                rp_idx     = SECTION_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else { /* (buffer_flag == TP_BUFFER_INFO_PACK) */
                                buf_idx    = TP0_BUFFER_INFO_PACK;
                                rp_idx     = INFO_PACK_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].info_pack_buffer;
                                block_size = INFO_PACK_BUFFER_BLOCK_SIZE;
                        }
                        break;
                case TP_TP1:
                        if(buffer_flag == TP_BUFFER_MASS_DATA) {
                                buf_idx    = TP1_BUFFER_MASS_DATA;
                                rp_idx     = MASS_DATA_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else if(buffer_flag == TP_BUFFER_SECTION) {
                                buf_idx    = TP1_BUFFER_SECTION_DATA;
                                rp_idx     = SECTION_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else { /* (buffer_flag == TP_BUFFER_INFO_PACK) */
                                buf_idx    = TP1_BUFFER_INFO_PACK;
                                rp_idx     = INFO_PACK_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].info_pack_buffer;
                                block_size = INFO_PACK_BUFFER_BLOCK_SIZE;
                        }
                        break;
                case TP_TP2:
                        if(buffer_flag == TP_BUFFER_MASS_DATA) {
                                buf_idx    = TP2_BUFFER_MASS_DATA;
                                rp_idx     = MASS_DATA_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else if(buffer_flag == TP_BUFFER_SECTION) {
                                buf_idx    = TP2_BUFFER_SECTION_DATA;
                                rp_idx     = SECTION_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else { /* (buffer_flag == TP_BUFFER_INFO_PACK) */
                                buf_idx    = TP2_BUFFER_INFO_PACK;
                                rp_idx     = INFO_PACK_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].info_pack_buffer;
                                block_size = INFO_PACK_BUFFER_BLOCK_SIZE;
                        }
                        break;
                case TP_TP3:
                        if(buffer_flag == TP_BUFFER_MASS_DATA) {
                                buf_idx    = TP3_BUFFER_MASS_DATA;
                                rp_idx     = MASS_DATA_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else if(buffer_flag == TP_BUFFER_SECTION) {
                                buf_idx    = TP3_BUFFER_SECTION_DATA;
                                rp_idx     = SECTION_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].mass_buffer;
                                block_size = pTp_drv->tp[tp_id].mass_buffer.bock_size;
                        } else { /* (buffer_flag == TP_BUFFER_INFO_PACK) */
                                buf_idx    = TP3_BUFFER_INFO_PACK;
                                rp_idx     = INFO_PACK_BUFFER_RP;
                                pBuf       = &pTp_drv->tp[tp_id].info_pack_buffer;
                                block_size = INFO_PACK_BUFFER_BLOCK_SIZE;
                        }
                        break;
                default:
                        TP_WARNING("bad parameter, tp_id=%u\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }


        if((pBuf->inited == 0) || (pTp_drv->tp[tp_id].tp_stream_status != TP_STREAM_START)) {
                TP_WARNING("buffer not init, tp_id=%u, pBuf->inited=%u, buffer_flag=%u, tp_stream_status=%u\n",
                           tp_id,
                           pBuf->inited,
                           buffer_flag,
                           pTp_drv->tp[tp_id].tp_stream_status);
                return TPK_NOT_INIT;
        }

        /* check if pReadPhyPtr is same as driver buffer rp saving */
        if((UADDRESS)pReadPhyPtr != pBuf->RP_Connect[rp_idx]) {
                TP_WARNING("release buff(rp_rdx=%d, buf_idx=%d) data pointer(%p) is not equal to the driver saved RP(0x%x), do nothing \n",
                           rp_idx, buf_idx, pReadPhyPtr, pBuf->RP_Connect[rp_idx]);
                return TPK_BAD_PARAMETER;
        }

        /* check if length alignment (188 bytes or 8 bytes) */
        if(Size % block_size) {
                TP_WARNING("TP%u released size of buffer (flag=%u) is %u bytes not alignment(block_size=%u)\n",
                           tp_id, buffer_flag, Size, block_size);
                return TPK_BUFFER_UNALIGNMENT;
        }

        /* get buffer status */
        result = Tp_Get_Buffer(buf_idx, &buf_param);
        if(result != TPK_SUCCESS) {
                TP_WARNING("get buffer status fail (tp_id=%u)\n", tp_id);
                return result;
        }

        buff_data_size = GET_BUFF_DATA_ALL_SIZE(buf_param);
        if( Size > buff_data_size ) {
                TP_WARNING("TP%d release buffer(buf_idx=%d) size(%u) is large than actual buffer size(%u), (%p/%p) (%p/%p/%p/%p)!\n",
                           tp_id, buf_idx, Size, buff_data_size, pReadPhyPtr, pBuf->RP_Connect[rp_idx], buf_param.Base, buf_param.RP, buf_param.WP, buf_param.Limit);
        }
        /* demux did not flush, could release  */
        if ( (buffer_flag == TP_BUFFER_SECTION || buffer_flag == TP_BUFFER_INFO_PACK) &&
             pTp_drv->tp[tp_id].buffer_flush_flag ) {
                if ( (pTp_drv->tp[tp_id].Shared_RWPtr.inited == 1) &&
                     (pTp_drv->tp[tp_id].Shared_RWPtr.pRP != NULL) &&
                     (pTp_drv->tp[tp_id].Shared_RWPtr.pWP != NULL) ) {
                        TP_WARNING("TP%u buffer be flushed in PVR recording mode %p\n", pBuf->RP_Connect[rp_idx] );
                }
                TP_WARNING("TP%u buffer be flushed, release RP to base! buf_idx=%u buf_flag=%u\n",
                           tp_id, buf_idx, buffer_flag );
                pBuf->RP_Connect[rp_idx] = buf_param.Base;
        } else {
                /* update to rp record */
                Offset = (UINT32)pReadPhyPtr;
                Offset += Size;
                if (Offset >= buf_param.Limit) {
                        Offset = (Offset - buf_param.Limit) + buf_param.Base;
                }
                pBuf->RP_Connect[rp_idx] = Offset;
        }


        /*  check if need to update buffer rp reg */
        Tp_Update_Buffer_RP(tp_id , buf_idx, pBuf);

        return TPK_SUCCESS;

}


/******************************

          MTP control

******************************/
INT32 Tp_SetMemoryMode(TPK_TP_ENGINE_T tp_id, UINT8 Mem_mode_en)
{
        tp_tp_tf0_frmcfg_RBUS tp_frm;
        tp_tp_tf0_cntl_RBUS tp_cntl;
        REGADDR tp_cntl_reg, tp_frmcfg_reg;

        /*  check parameter */
        CHECK_MAX_TP_COUNT(tp_id);

        switch(tp_id) {
                case TP_TP0:
                        tp_cntl_reg   = TP_TP_TF0_CNTL_reg;
                        tp_frmcfg_reg = TP_TP_TF0_FRMCFG_reg;

                        break;
                case TP_TP1:
                        tp_cntl_reg   = TP_TP_TF1_CNTL_reg;
                        tp_frmcfg_reg = TP_TP_TF1_FRMCFG_reg;

                        break;
                case TP_TP2:
                        tp_cntl_reg   = TP_TP_TF2_CNTL_reg;
                        tp_frmcfg_reg = TP_TP_TF2_FRMCFG_reg;

                        break;
                case TP_TP3:
                        tp_cntl_reg   = TP_TP_TF3_CNTL_reg;
                        tp_frmcfg_reg = TP_TP_TF3_FRMCFG_reg;

                        break;
                default:
                        TP_WARNING("bas parameter for tp_id=%u\n", tp_id);
                        break;
        }

        /* set TP ctrl */
        tp_cntl.regValue = READ_REG32(tp_cntl_reg);
        tp_cntl.mode     = (Mem_mode_en) ? 1 : 0;
        Tp_Write_Data_Reg_Write(tp_cntl_reg, tp_cntl.regValue);

        /* set TP frame reg */
        tp_frm.regValue = READ_REG32(tp_frmcfg_reg);
        tp_frm.lockno   = (Mem_mode_en) ? 1 : 3;   /* check 0x47 x 3 for TSP header lock */
        WRITE_REG32(tp_frmcfg_reg, tp_frm.regValue);

        return TPK_SUCCESS;

}

INT32 Tp_Get_MTP_Buffer(TPK_TP_MTP_T mtp_id, TP_BUFFER_PARAM_T* param)
{
        REGADDR tp_m2m_ring_limit_reg;
        REGADDR tp_m2m_ring_base_reg;
        REGADDR tp_m2m_ring_rp_reg;
        REGADDR tp_m2m_ring_wp_reg;

        /*  check parameter */
        CHECK_MTP_ID(mtp_id);

        switch (mtp_id) {
                case TP_TP0_MTP:
                        tp_m2m_ring_limit_reg = TP_TP0_M2M_RING_LIMIT_reg;
                        tp_m2m_ring_base_reg  = TP_TP0_M2M_RING_BASE_reg;
                        tp_m2m_ring_rp_reg    = TP_TP0_M2M_RING_RP_reg;
                        tp_m2m_ring_wp_reg    = TP_TP0_M2M_RING_WP_reg;

                        break;
                case TP_TP1_MTP:
                        tp_m2m_ring_limit_reg = TP_TP1_M2M_RING_LIMIT_reg;
                        tp_m2m_ring_base_reg  = TP_TP1_M2M_RING_BASE_reg;
                        tp_m2m_ring_rp_reg    = TP_TP1_M2M_RING_RP_reg;
                        tp_m2m_ring_wp_reg    = TP_TP1_M2M_RING_WP_reg;

                        break;
                case TP_TP2_MTP:
                        tp_m2m_ring_limit_reg = TP_TP2_M2M_RING_LIMIT_reg;
                        tp_m2m_ring_base_reg  = TP_TP2_M2M_RING_BASE_reg;
                        tp_m2m_ring_rp_reg    = TP_TP2_M2M_RING_RP_reg;
                        tp_m2m_ring_wp_reg    = TP_TP2_M2M_RING_WP_reg;

                        break;
                case TP_TP3_MTP:
                        tp_m2m_ring_limit_reg = TP_TP3_M2M_RING_LIMIT_reg;
                        tp_m2m_ring_base_reg  = TP_TP3_M2M_RING_BASE_reg;
                        tp_m2m_ring_rp_reg    = TP_TP3_M2M_RING_RP_reg;
                        tp_m2m_ring_wp_reg    = TP_TP3_M2M_RING_WP_reg;

                        break;
                case TP_TPP0_MTP:
                        tp_m2m_ring_limit_reg = TP_TP0_P_M2M_RING_LIMIT_reg;
                        tp_m2m_ring_base_reg  = TP_TP0_P_M2M_RING_BASE_reg;
                        tp_m2m_ring_rp_reg    = TP_TP0_P_M2M_RING_RP_reg;
                        tp_m2m_ring_wp_reg    = TP_TP0_P_M2M_RING_WP_reg;

                        break;
                case TP_TPP1_MTP:
                        tp_m2m_ring_limit_reg = TP_TP1_P_M2M_RING_LIMIT_reg;
                        tp_m2m_ring_base_reg  = TP_TP1_P_M2M_RING_BASE_reg;
                        tp_m2m_ring_rp_reg    = TP_TP1_P_M2M_RING_RP_reg;
                        tp_m2m_ring_wp_reg    = TP_TP1_P_M2M_RING_WP_reg;

                        break;
                case TP_TPP2_MTP:
                        tp_m2m_ring_limit_reg = TP_TP2_P_M2M_RING_LIMIT_reg;
                        tp_m2m_ring_base_reg  = TP_TP2_P_M2M_RING_BASE_reg;
                        tp_m2m_ring_rp_reg    = TP_TP2_P_M2M_RING_RP_reg;
                        tp_m2m_ring_wp_reg    = TP_TP2_P_M2M_RING_WP_reg;

                        break;
                default:
                        TP_WARNING("bad parameter of mtp_id=%u\n", mtp_id);
                        _tp_buf_unlock();
                        return TPK_BAD_PARAMETER;
                        break;
        }

        _tp_buf_lock();
        /*  read reg */
        param->Limit = READ_REG32(tp_m2m_ring_limit_reg);
        param->Base  = READ_REG32(tp_m2m_ring_base_reg);
        param->RP    = READ_REG32(tp_m2m_ring_rp_reg);
        param->WP    = READ_REG32(tp_m2m_ring_wp_reg);
        _tp_buf_unlock();

        return TPK_SUCCESS;
}



INT32 Tp_SetPidAlgorithm(UINT16 pid_idx, TPK_DESCRAMBLE_ALGORITHM_T desc, UINT16 PID)
{
        tp_tp_pid_data3_RBUS pid_data3, pid_data3_check;
        tp_tp_pid_ctrl_RBUS pid_ctrl_reg, pid_ctrl_reg_check;
        int count_retry = 0;
        static bool cw_init = false;
        if(!cw_init) {
                TP_DBG(" Request CW for TP !!! \n");
                rtk_cw_request_multi_cws("TP", 0, 48);
                cw_init = true;
                udelay(1000);
        }

        pid_data3.regValue = 0;
        pid_data3.map_11 = DES_CNTL_MAP_ODD;
        pid_data3.map_10 = DES_CNTL_MAP_EVEN;
        pid_data3.map_01 = DES_CNTL_MAP_ODD;

        switch(desc.algo) {
                case TPK_DESCRAMBLE_ALGO_DES_ECB_CLEAR:

                        TP_INFO("pid_index:%u Descramble Algorithm = DES ECB KEEP CLEAR\n", PID);
                        pid_data3.mode = DES_CNTL_MODE_DES;
                        pid_data3.des_mode = DES_CNTL_DESMODE_ECB;
                        pid_data3.ofb_mode = DES_CNTL_OFB_KEEP_CLEAR;
                        break;

                case TPK_DESCRAMBLE_ALGO_TDES_ECB_CLEAR:

                        TP_INFO("pid:%u Descramble Algorithm = TDES ECB KEEP CLEAR\n", PID);
                        pid_data3.mode = DES_CNTL_MODE_TDES;
                        pid_data3.des_mode = DES_CNTL_DESMODE_ECB;
                        pid_data3.ofb_mode = DES_CNTL_OFB_DEFAULT;
                        break;

                case TPK_DESCRAMBLE_ALGO_TDES_CBC_OFB:

                        TP_INFO("pid:%u Descramble Algorithm = TDES CBC OFB\n", PID);
                        pid_data3.mode = DES_CNTL_MODE_TDES;
                        pid_data3.des_mode = DES_CNTL_DESMODE_CBC;
                        pid_data3.ofb_mode = DES_CNTL_OFB_OFB;
                        break;

                case TPK_DESCRAMBLE_ALGO_CSA:

                        TP_INFO("pid:%u Descramble Algorithm = CSA\n", PID);
                        pid_data3.mode = DES_CNTL_MODE_CSA;
                        pid_data3.csa_mode = DES_CNTL_CSA_MODE_1;
                        break;

                case TPK_DESCRAMBLE_ALGO_CSA2:

                        TP_INFO("pid:%u Descramble Algorithm = CSA2\n", PID);
                        pid_data3.mode = DES_CNTL_MODE_CSA;
                        pid_data3.csa_mode = DES_CNTL_CSA_MODE_2;
                        break;

                case TPK_DESCRAMBLE_ALGO_CSA_RAW:

                        TP_INFO("pid:%u Descramble Algorithm = CSA RAW\n", PID);
                        pid_data3.mode = DES_CNTL_MODE_CSA;
                        pid_data3.csa_mode = DES_CNTL_CSA_MODE_ORIGINAL;
                        break;

                case TPK_DESCRAMBLE_ALGO_MULTI2_OFB:

                        TP_INFO("pid:%u Descramble Algorithm = MULTI2 OFB, Round=%u\n", PID, desc.round);
                        pid_data3.ofb_mode = DES_CNTL_OFB_DEFAULT;
                        pid_data3.mode = DES_CNTL_MODE_MULTI2;
                        pid_data3.des_mode = DES_CNTL_DESMODE_CBC;
                        pid_data3.multi2_mode = DES_CNTL_MULTI2_ALIGN63;
                        pid_data3.round = desc.round - 1;
                        break;

                case TPK_DESCRAMBLE_ALGO_AES_128_CBC_CLEAR:

                        TP_INFO("pid:%u Descramble Algorithm = AES 128 CBC KEEP CLEAR\n", PID);
                        pid_data3.ofb_mode = DES_CNTL_OFB_KEEP_CLEAR;
                        pid_data3.mode = DES_CNTL_MODE_AES128_CBC;
                        pid_data3.des_mode = DES_CNTL_DESMODE_CBC;
                        break;

                case TPK_DESCRAMBLE_ALGO_AES_RCBC_CS_CLEAR:

                        TP_INFO("pid:%u Descramble Algorithm = AES RCBC CS KEEP CLEAR\n", PID);
                        pid_data3.mode = DES_CNTL_MODE_AES128_RCBC_CS;
                        break;

                case TPK_DESCRAMBLE_ALGO_AES_128_CBC_OFB:
                case TPK_DESCRAMBLE_ALGO_AES_128_CBC_OFB_ATIS:

                        TP_INFO("pid:%u Descramble Algorithm = AES 128 CBC OFB\n", PID);
                        pid_data3.ofb_mode = DES_CNTL_OFB_OFB;
                        pid_data3.mode = DES_CNTL_MODE_AES128_CBC;
                        pid_data3.des_mode = DES_CNTL_DESMODE_CBC;
                        break;

                default:
                        TP_WARNING("pid:%u Set Descrambler Failed - Unsupported Descramble Algorithm %u\n", PID, desc.algo);
                        return TPK_BAD_PARAMETER;
                        ;

        }
        WRITE_REG32(TP_TP_PID_DATA3_reg, pid_data3.regValue);
        pid_ctrl_reg.regValue = 0;
        pid_ctrl_reg.r_w = 1;
        pid_ctrl_reg.idx = pid_idx;
        do {
                if ( count_retry != 0 ) {
                        if (pid_data3.regValue != pid_data3_check.regValue) {
                                TP_DBG( "2 Write pid parameter not completed. pid_idx=%d, pid_data3=0x%x, pid_data3_check=0x%x \n" ,
                                        pid_idx, pid_data3.regValue, pid_data3_check.regValue);
                                WRITE_REG32(TP_TP_PID_DATA3_reg, pid_data3.regValue);
                        }

                }

                /* write register data */
                WRITE_REG32(TP_TP_PID_CTRL_reg, pid_ctrl_reg.regValue);
                udelay(100);
                /* read register to check */
                pid_ctrl_reg_check.regValue = pid_ctrl_reg.regValue;
                pid_ctrl_reg_check.r_w = 0; /* read */
                WRITE_REG32(TP_TP_PID_CTRL_reg, pid_ctrl_reg_check.regValue);
                /* read TP PID Data3 */
                pid_data3_check.regValue = READ_REG32(TP_TP_PID_DATA3_reg);

                count_retry++;
                if(count_retry > 10000)
                        break;
        } while(pid_data3.regValue != pid_data3_check.regValue );

        return TPK_SUCCESS;

}


/*******************************

       pid filter control

*******************************/
INT32 Tp_SetPidParam(UINT16 pid_idx, TPK_PID_REG_PARAM_T Param)
{
        tp_tp_pid_ctrl_RBUS pid_ctrl_reg, pid_ctrl_reg_check;
        tp_tp_pid_data_RBUS pid_data, pid_data_check;
        tp_tp_pid_data2_RBUS pid_data2, pid_data2_check;
        int count_retry = 0;

        CHECK_MAX_PID_FILTER_COUNT(pid_idx);

        _tp_pid_lock();
        /*  set TP_PID_DATA */
        pid_data.regValue = 0;
        pid_data.si_en    = Param.si_en;
        pid_data.pid_ini  = 1;
        pid_data.ai_en    = Param.ai_en;
        pid_data.ti_en    = Param.ti_en;
        pid_data.sec_idx  = Param.sec_idx;
        pid_data.sec_en   = Param.sec_en;
        pid_data.ddr_q    = Param.ddr_q;
        pid_data.v        = Param.v;
        pid_data.pid      = Param.pid;
        WRITE_REG32(TP_TP_PID_DATA_reg, pid_data.regValue);

        /*  set TP_DATA2 */
        pid_data2.regValue = 0;
        pid_data2.ddr_q_en = 1; /* always set DDRQ enable */
        pid_data2.cc_en    = Param.cc_en;
        pid_data2.local_des_en = Param.local_des_en;
        pid_data2.pid_des_disable = Param.pid_descramble_disable;
        if(Param.sec_en) {
                pid_data2.info_q  = Param.info_q;
                pid_data2.key     = Param.key;
                pid_data2.pre_des = Param.pre_des;
        } else {
                pid_data2.info_q = Param.info_q;
                pid_data2.key    = Param.key;
        }

        pid_data2.encrypt_tsc_en = Param.encrypt_tsc_en;
        pid_data2.encryption_key = Param.encryption_key;
        pid_data2.encryption_en = Param.encryption_en;

        WRITE_REG32(TP_TP_PID_DATA2_reg, pid_data2.regValue);

        /*  write pid reg data */
        pid_ctrl_reg.regValue = 0;
        pid_ctrl_reg.r_w      = 1;
        pid_ctrl_reg.idx      = pid_idx;

        /* write regiter and  check regiter write value is ok or not */
        count_retry = 0;
        do {
                if ( count_retry != 0 ) {
                        if ( pid_data_check.regValue != pid_data.regValue ) {
                                TP_DBG( "1 Write pid parameter not completed. pid_idx=%d, pid_data=0x%x, pid_data_check=0x%x \n" ,
                                        pid_idx, pid_data.regValue, pid_data_check.regValue);
                                WRITE_REG32(TP_TP_PID_DATA_reg, pid_data.regValue);
                        }

                        if (pid_data2.regValue != pid_data2_check.regValue) {
                                TP_DBG( "2 Write pid parameter not completed. pid_idx=%d, pid_data2=0x%x, pid_data2_check=0x%x \n" ,
                                        pid_idx, pid_data2.regValue, pid_data2_check.regValue);
                                WRITE_REG32(TP_TP_PID_DATA2_reg, pid_data2.regValue);
                        }

                }

                /* write register data */
                WRITE_REG32(TP_TP_PID_CTRL_reg, pid_ctrl_reg.regValue);
                udelay(100);
                /* read register to check */
                pid_ctrl_reg_check.regValue = pid_ctrl_reg.regValue;
                pid_ctrl_reg_check.r_w      = 0; /* read */
                WRITE_REG32(TP_TP_PID_CTRL_reg, pid_ctrl_reg_check.regValue);
                /* read TP PID Data */
                pid_data_check.regValue = READ_REG32(TP_TP_PID_DATA_reg);
                /* read TP PID Data2 */
                pid_data2_check.regValue = READ_REG32(TP_TP_PID_DATA2_reg);

                count_retry++;
                if(count_retry > 10000)
                        break;
        } while( pid_data_check.regValue != pid_data.regValue ||
                 pid_data2.regValue != pid_data2_check.regValue );

        /* resotre the vaild to pid_data */
        pid_data.v = Param.v;
        WRITE_REG32(TP_TP_PID_DATA_reg, pid_data.regValue);
        WRITE_REG32(TP_TP_PID_CTRL_reg, pid_ctrl_reg.regValue);

        _tp_pid_unlock();

        return TPK_SUCCESS;
}

INT32 Tp_GetPidParam(UINT16 pid_idx, TPK_PID_REG_PARAM_T* pParam)
{
        tp_tp_pid_ctrl_RBUS pid_ctrl_reg;
        tp_tp_pid_data_RBUS pid_data;
        tp_tp_pid_data2_RBUS pid_data2;

        CHECK_MAX_PID_FILTER_COUNT(pid_idx);

        _tp_pid_lock();
        /*  read pid reg data */
        pid_ctrl_reg.regValue = 0;
        pid_ctrl_reg.r_w      = 0;
        pid_ctrl_reg.idx      = pid_idx;
        WRITE_REG32(TP_TP_PID_CTRL_reg, pid_ctrl_reg.regValue);

        /*  get param */
        pid_data.regValue = READ_REG32(TP_TP_PID_DATA_reg);
        pParam->v         = pid_data.v;
        pParam->si_en     = pid_data.si_en;
        pParam->ai_en     = pid_data.ai_en;
        pParam->ti_en     = pid_data.ti_en;
        pParam->sec_idx   = pid_data.sec_idx;
        pParam->sec_en    = pid_data.sec_en;
        pParam->pid       = pid_data.pid;
        pParam->ddr_q     = pid_data.ddr_q;

        pid_data2.regValue = READ_REG32(TP_TP_PID_DATA2_reg);
        pParam->cc_en      = pid_data2.cc_en;
        pParam->key        = pid_data2.key;
        pParam->info_q     = pid_data2.info_q;
        pParam->pre_des    = pid_data2.pre_des;
        pParam->local_des_en = pid_data2.local_des_en;
        pParam->encrypt_tsc_en    = pid_data2.encrypt_tsc_en;
        pParam->encryption_key    = pid_data2.encryption_key;
        pParam->encryption_en    = pid_data2.encryption_en;
        _tp_pid_unlock();

        return TPK_SUCCESS;
}

INT32 Tp_SetSecParam(UINT16 sec_idx, TPK_SEC_REG_T sec_reg)
{
        UINT32 Data[9] = {
                BYTE_TO_LONG(sec_reg.PosVal[0], sec_reg.PosVal[3], sec_reg.PosVal[4], sec_reg.PosVal[5]),
                BYTE_TO_LONG(sec_reg.PosVal[6], sec_reg.PosVal[7], sec_reg.PosVal[8], sec_reg.PosVal[9]),
                BYTE_TO_LONG(sec_reg.PosMsk[0], sec_reg.PosMsk[3], sec_reg.PosMsk[4], sec_reg.PosMsk[5]),
                BYTE_TO_LONG(sec_reg.PosMsk[6], sec_reg.PosMsk[7], sec_reg.PosMsk[8], sec_reg.PosMsk[9]),
                0,
                BYTE_TO_LONG(sec_reg.NegVal[0], sec_reg.NegVal[3], sec_reg.NegVal[4], sec_reg.NegVal[5]),
                BYTE_TO_LONG(sec_reg.NegVal[6], sec_reg.NegVal[7], sec_reg.NegVal[8], sec_reg.NegVal[9]),
                BYTE_TO_LONG(sec_reg.NegMsk[0], sec_reg.NegMsk[3], sec_reg.NegMsk[4], sec_reg.NegMsk[5]),
                BYTE_TO_LONG(sec_reg.NegMsk[6], sec_reg.NegMsk[7], sec_reg.NegMsk[8], sec_reg.NegMsk[9]),
        };
        UINT16 i;
        tp_tp_sec_data4_RBUS sec_data4;
        tp_tp_sec_data9_RBUS sec_data9;
        tp_tp_sec_ctrl_RBUS sec_ctrl;

        /* check parameter */
        CHECK_MAX_SEC_FILTER_COUNT(sec_idx);
        CHECK_TP_STRUCTURE();


        /* check if positive filter exists or not */
        pTp_drv->sec[sec_idx].positive_filter_en = 0;
        for ( i = 0; i < 10; i++) {
                if (sec_reg.PosMsk[i]) {
                        pTp_drv->sec[sec_idx].positive_filter_en = 1;
                        break;
                }
        }

        /* check if negative filter exists or not */
        pTp_drv->sec[sec_idx].negative_filter_en = 0;
        for ( i = 0; i < 10; i++) {
                if (sec_reg.NegMsk[i]) {
                        pTp_drv->sec[sec_idx].negative_filter_en = 1;
                        break;
                }
        }

        WRITE_REG32(TP_TP_SEC_DATA0_reg, Data[0]);
        WRITE_REG32(TP_TP_SEC_DATA1_reg, Data[1]);
        WRITE_REG32(TP_TP_SEC_DATA2_reg, Data[2]);
        WRITE_REG32(TP_TP_SEC_DATA3_reg, Data[3]);
        WRITE_REG32(TP_TP_SEC_DATA5_reg, Data[5]);
        WRITE_REG32(TP_TP_SEC_DATA6_reg, Data[6]);
        WRITE_REG32(TP_TP_SEC_DATA7_reg, Data[7]);
        WRITE_REG32(TP_TP_SEC_DATA8_reg, Data[8]);

        sec_data9.regValue   = 0;
        sec_data9.filter_sel = TP_SEC_DATA9_FILTER_SEL_PATTERN_A;

        if((pTp_drv->sec[sec_idx].positive_filter_en) && (pTp_drv->sec[sec_idx].negative_filter_en))
                sec_data9.filter_sel = TP_SEC_DATA9_FILTER_SEL_PATTERN_AB;
        else if(pTp_drv->sec[sec_idx].positive_filter_en)
                sec_data9.filter_sel = TP_SEC_DATA9_FILTER_SEL_PATTERN_A;
        else if(pTp_drv->sec[sec_idx].negative_filter_en)
                sec_data9.filter_sel = TP_SEC_DATA9_FILTER_SEL_PATTERN_B;

        sec_data9.neg_sp_filter = sec_reg.NegVal[1] >> 6;
        sec_data9.neg_sp_mask   = sec_reg.NegMsk[1] >> 6;
        WRITE_REG32(TP_TP_SEC_DATA9_reg, sec_data9.regValue);

        sec_data4.regValue  = 0;
        sec_data4.sp_filter = sec_reg.PosVal[1] >> 6;
        sec_data4.sp_mask   = sec_reg.PosMsk[1] >> 6;
        sec_data4.crc_en    = sec_reg.crc_en;
        sec_data4.p_d       = sec_reg.p_d;
        sec_data4.p_n       = sec_reg.p_n;
        sec_data4.last      = sec_reg.last;
        sec_data4.next_sec  = sec_reg.next_sec;
        WRITE_REG32(TP_TP_SEC_DATA4_reg, sec_data4.regValue);

        sec_ctrl.regValue = 0;
        sec_ctrl.r_w      = 1;
        sec_ctrl.idx      = sec_idx;
        WRITE_REG32(TP_TP_SEC_CTRL_reg, sec_ctrl.regValue);

        return TPK_SUCCESS;
}

INT32 Tp_Remove_PID(TPK_TP_ENGINE_T tp_id, UINT16 pid_idx)
{
        TPK_PID_REG_PARAM_T pid_reg;
        INT32 result = TPK_SUCCESS;
        UINT16 pid_idx_reg;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();
        CHECK_MAX_PID_FILTER_COUNT(pid_idx);
        CHECK_MAX_PID_PER_FILTER_COUNT(pid_idx);

        switch(tp_id) {
                case TP_TP0:
                        pid_idx_reg = pid_idx;
                        break;
                case TP_TP1:
                        pid_idx_reg = pid_idx + TP0_PID_FILTER_COUNT;
                        break;
                case TP_TP2:
                        pid_idx_reg = pid_idx + TP0_PID_FILTER_COUNT + TP1_PID_FILTER_COUNT;
                        break;
                case TP_TP3:
                        pid_idx_reg = pid_idx + TP0_PID_FILTER_COUNT + TP1_PID_FILTER_COUNT + TP2_PID_FILTER_COUNT;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        result = TPK_BAD_PARAMETER;
                        return result;
        }

        if(pTp_drv->tp_pid[tp_id].pid_api_setting[pid_idx].valid) {
                /*  update PID filter reg */
                result = Tp_GetPidParam(pid_idx_reg, &pid_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("get pid reg error (pid_idx=%u)\n", pid_idx_reg);
                        return result;
                }

                pid_reg.v      = 0;
                pid_reg.sec_en = 0;

                result = Tp_SetPidParam(pid_idx_reg, pid_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("set pid reg error (pid_idx=%u)\n", pid_idx_reg);
                        return result;
                }


                /*  update PID filter api setting */
                pTp_drv->tp_pid[tp_id].pid_api_setting[pid_idx].valid = 0;

                TP_INFO("TP%u remove PID filter (PID=0x%x, pid_idx=%u)\n",
                        tp_id, pTp_drv->tp_pid[tp_id].pid_api_setting[pid_idx].PID, pid_idx);
        }
        return result;
}

INT32 Tp_AddPIDFilter( TPK_TP_ENGINE_T tp_id, TPK_PID_FILTER_PARAM_T PIDParm, void* file_handle)
{
        UINT16 max_pid_cnt, i, pid_idx, pid_idx_reg;
        UINT8 update_flag, ddr_q, info_q;
        TPK_PID_REG_PARAM_T pid_reg;
        INT32 result;

        /*  check parameter */
        if(((PIDParm.KeySel >= MAX_KEY_COUNT) && (PIDParm.DescrambleEn) ) ||
            (PIDParm.PID >= MAX_PID_VALUE)) {
                TP_WARNING("bad parameter, PID=0x%x, KeySel=%u\n",
                           PIDParm.PID, PIDParm.KeySel);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        if(PIDParm.KeySel >= MAX_KEY_COUNT) {
                PIDParm.KeySel = 0;
        }
        /* check PID filter process case:(1)no update(2)update param(3)add new PID filter */
        result = _PID_Filter_Update_Check(tp_id, PIDParm,
                                          &pid_idx, &pid_idx_reg,
                                          &update_flag, &max_pid_cnt,
                                          &ddr_q, &info_q);
        if(result != TPK_SUCCESS)

        {
                TP_WARNING("_PID_Filter_Update_Check error (result=%d)\n", result);
                goto PID_ERROR;
        }

        /*  if need to update pid filter param or add new pid filter */
        if(update_flag != PID_NO_UPDATE) {
                result = Tp_GetPidParam(pid_idx_reg, &pid_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("get pid reg error\n");
                        goto PID_ERROR;
                }

                if(update_flag == PID_UPDATE_PARAM) {
                        /*  2. update pid filter param */
                        pid_reg.key                    = PIDParm.KeySel;
                        pid_reg.pid_descramble_disable = PIDParm.DescrambleEn ? 0 : 1;
                } else {
                        /*  3. Add pid filter */
                        pid_reg.key                    = PIDParm.KeySel;
                        pid_reg.pid_descramble_disable = PIDParm.DescrambleEn ? 0 : 1;
                        pid_reg.v                      = 1;
                        pid_reg.pid                    = PIDParm.PID;
                        pid_reg.ddr_q                  = ddr_q;
                        pid_reg.info_q                 = info_q;

                        /*  do not open section filter in this stage */
                        pid_reg.sec_en = 0;
                        pid_reg.si_en  = 0;
                }

                if( pTp_drv->tp[tp_id].desc.algo == TPK_DESCRAMBLE_ALGO_NONE)
                        pid_reg.local_des_en = 1;
                else
                        pid_reg.local_des_en = 0;

                if(PIDParm.DescrambleEn && pTp_drv->pid_desc[PIDParm.KeySel].desc.algo && !pTp_drv->tp[tp_id].desc.algo)
                        Tp_SetPidAlgorithm(pid_idx_reg, pTp_drv->pid_desc[PIDParm.KeySel].desc, PIDParm.PID);

                result = Tp_SetPidParam(pid_idx_reg, pid_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("set pid reg error\n");
                        goto PID_ERROR;
                }


                /*  save PID api setting */
                pTp_drv->tp_pid[tp_id].pid_api_setting[pid_idx]       = PIDParm;
                pTp_drv->tp_pid[tp_id].pid_api_setting[pid_idx].valid = 1;

                if(update_flag == PID_UPDATE_PARAM) {
                        TP_INFO("TP%u update PID(0x%x) parameter into PID filter reg idx=%u\n",
                                tp_id, PIDParm.PID, pid_idx_reg);
                } else {
                        TP_INFO("TP%u set PID(0x%x) into PID filter reg idx=%u\n",
                                tp_id, PIDParm.PID, pid_idx_reg);
                }

        }

        /* check file handle exist or not, if exist, just return. */
        /* if not exist, add this file handle */
        for( i = 0; i < MAX_FILE_HANDLE_REC; i++) {
                if(pTp_drv->tp_pid[tp_id].file_handle[pid_idx][i] == file_handle) {
                        TP_INFO("PID filter already exist, do nothing and exit(tp_id=%u, pid=%u, file_handle=%p)\n",
                                tp_id, PIDParm.PID, file_handle);

                        goto PID_SUCCESS;
                }
        }

        /* if file handle does not exist,  save this file handle */
        /* check if is there an empty file handle space */
        for( i = 0; i < MAX_FILE_HANDLE_REC; i++) {
                if(pTp_drv->tp_pid[tp_id].file_handle[pid_idx][i] == NULL) {
                        pTp_drv->tp_pid[tp_id].file_handle[pid_idx][i] = file_handle;
                        pTp_drv->tp_pid[tp_id].pid_file_handle_cnt[pid_idx]++;
                        TP_INFO("update file_handle (tp_id=%u, pid=%u, file_handle=%p)\n",
                                tp_id, PIDParm.PID, file_handle);
                        goto PID_SUCCESS;
                }
        }

        /*  no space to save file handle */
        TP_WARNING("no space to save file_handle(tp_id=%u, pid=%u, file_handle=%p, file_handle_cnt=%u)\n",
                   tp_id, PIDParm.PID, file_handle, i);
        result = TPK_NOT_ENOUGH_RESOURCE;
        goto PID_ERROR;

PID_SUCCESS:
        if(tp_log_onoff && CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_PID)) {
                for( i = 0; i < max_pid_cnt; i++)
                        Tp_Dump_PID_filter_Status(tp_id, i);
        }

        return TPK_SUCCESS;

PID_ERROR:
        return result;

}


INT32 Tp_RemovePIDFilter( TPK_TP_ENGINE_T tp_id, UINT16 PID, void* file_handle)
{
        UINT16 i, j, max_pid_cnt;
        TPK_PID_FILTER_PARAM_T *pPid_setting;
        INT32 result;
        UINT8 file_handle_cnt;

        /*  check parameter */
        if(PID >= MAX_PID_VALUE) {
                TP_INFO("bad parameter, PID=%u\n", PID);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        result = Tp_Get_MaxPID_Cnt(tp_id, &max_pid_cnt);
        if(result != TPK_SUCCESS) {
                TP_WARNING("call Tp_Get_MaxPID_Cnt return error\n");
                return result;
        }

        for( i = 0; i < max_pid_cnt; i++) {
                pPid_setting = &pTp_drv->tp_pid[tp_id].pid_api_setting[i];

                /* check PID valid and PID value */
                if((pPid_setting->valid == 1) &&
                    (pPid_setting->PID == PID)) {
                        /* check file handle */
                        for( j = 0; j < MAX_FILE_HANDLE_REC; j++) {
                                if(pTp_drv->tp_pid[tp_id].file_handle[i][j] == file_handle) {
                                        break;
                                }
                        }

                        /* PID match, but file handle not match, just exit */
                        if(j >= MAX_FILE_HANDLE_REC) {
                                TP_INFO("PID (0x%x) matched, but not match file handle(%p), do nothing and exit\n",
                                        pPid_setting->PID, file_handle);
                                goto PID_SUCCESS;
                        }

                        /*  PID match and file handle match, remove file handle, and if there is no file handle, remove PID filter */
                        file_handle_cnt = pTp_drv->tp_pid[tp_id].pid_file_handle_cnt[i];
                        file_handle_cnt--;
                        /*  remove pid filter */
                        if(file_handle_cnt == 0) {
                                result = Tp_Remove_PID(tp_id, i);
                                if(result != TPK_SUCCESS) {
                                        TP_WARNING("remove PID register setting error\n");
                                        goto PID_ERROR;
                                }
                                TP_INFO("TP%u remove PID filter ok (PID=0x%x, pid_idx=%u)\n", tp_id, PID, i);
                        }
                        /*  remove file handle */
                        pTp_drv->tp_pid[tp_id].file_handle[i][j] = NULL;
                        pTp_drv->tp_pid[tp_id].pid_file_handle_cnt[i]--;

                }
        }

PID_SUCCESS:
        if(tp_log_onoff && CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_PID)) {
                for( i = 0; i < max_pid_cnt; i++) {
                        Tp_Dump_PID_filter_Status(tp_id, i);
                }
        }
        return TPK_SUCCESS;

PID_ERROR:
        return result;
}

INT32 Tp_Get_MaxPID_Cnt(TPK_TP_ENGINE_T tp_id, UINT16 *pMax_PID_Cnt)
{
        CHECK_MAX_TP_COUNT(tp_id);

        switch(tp_id) {
                case TP_TP0:
                        *pMax_PID_Cnt = TP0_PID_FILTER_COUNT;
                        break;
                case TP_TP1:
                        *pMax_PID_Cnt = TP1_PID_FILTER_COUNT;
                        break;
                case TP_TP2:
                        *pMax_PID_Cnt = TP2_PID_FILTER_COUNT;
                        break;
                case TP_TP3:
                        *pMax_PID_Cnt = TP3_PID_FILTER_COUNT;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        if(*pMax_PID_Cnt > MAX_PID_PER_TP) {
                TP_WARNING("TP%u define error, max_pid_cnt (%u) is more than MAX_PID_PER_TP (%u)\n",
                           tp_id, *pMax_PID_Cnt, MAX_PID_PER_TP);
                return TPK_NOT_ENOUGH_RESOURCE;
        }

        return TPK_SUCCESS;
}

INT32 Tp_GetPID_info(TPK_TP_ENGINE_T tp_id, UINT8 pid_idx_reg, UINT16 *PID, UINT8 *pPid_idx)
{
        INT32 pid_filter_count;

        if(pid_idx_reg >= MAX_PID_FILTER_COUNT) {
                TP_WARNING("unsupported pid_idx_reg=%u\n", pid_idx_reg);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        switch(tp_id) {
                case TP_TP0:
                        *pPid_idx        = pid_idx_reg;
                        pid_filter_count = TP0_PID_FILTER_COUNT;

                        break;
                case TP_TP1:
                        *pPid_idx        = pid_idx_reg - TP0_PID_FILTER_COUNT;
                        pid_filter_count = TP1_PID_FILTER_COUNT;

                        break;
                case TP_TP2:
                        *pPid_idx        = pid_idx_reg - TP0_PID_FILTER_COUNT - TP1_PID_FILTER_COUNT;
                        pid_filter_count = TP2_PID_FILTER_COUNT;

                        break;
                case TP_TP3:
                        *pPid_idx        = pid_idx_reg - TP0_PID_FILTER_COUNT - TP1_PID_FILTER_COUNT - TP2_PID_FILTER_COUNT;
                        pid_filter_count = TP3_PID_FILTER_COUNT;

                        break;
                default:
                        TP_WARNING("unsupported tp_id=%u\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        if(*pPid_idx >= pid_filter_count) {
                TP_WARNING("unsupported pid_idx_reg=%u ,tp_id=%d\n", pid_idx_reg, tp_id);
                return TPK_BAD_PARAMETER;
        }

        if(pTp_drv->tp_pid[tp_id].pid_api_setting[*pPid_idx].valid == 0) {
                TP_WARNING("TP%u, pid_idx=%u not init yet\n", tp_id, *pPid_idx);
                return TPK_NOT_INIT;
        }

        *PID = pTp_drv->tp_pid[tp_id].pid_api_setting[*pPid_idx].PID;

        return TPK_SUCCESS;
}

INT32 Tp_GetPID_info_for_InfoPack(TPK_TP_ENGINE_T tp_id, UINT8 pid_idx_reg, UINT16 *PID, UINT8 *pPid_idx)
{
        INT32 pid_filter_count;


        if(pid_idx_reg >= MAX_PID_FILTER_COUNT) {
                TP_WARNING("unsupported pid_idx_reg=%u\n", pid_idx_reg);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        switch(tp_id) {
                case TP_TP0:
                        *pPid_idx        = pid_idx_reg;
                        pid_filter_count = TP0_PID_FILTER_COUNT;

                        break;
                case TP_TP1:
                        *pPid_idx        = pid_idx_reg - TP0_PID_FILTER_COUNT;
                        pid_filter_count = TP1_PID_FILTER_COUNT;

                        break;
                case TP_TP2:
                        *pPid_idx        = pid_idx_reg - TP0_PID_FILTER_COUNT - TP1_PID_FILTER_COUNT;
                        pid_filter_count = TP2_PID_FILTER_COUNT;

                        break;
                case TP_TP3:
                        *pPid_idx        = pid_idx_reg - TP0_PID_FILTER_COUNT - TP1_PID_FILTER_COUNT - TP2_PID_FILTER_COUNT;
                        pid_filter_count = TP3_PID_FILTER_COUNT;

                        break;
                default:
                        TP_WARNING("unsupported tp_id=%u\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        if(*pPid_idx >= pid_filter_count) {
                TP_WARNING("unsupported pid_idx_reg=%u ,tp_id=%d\n", pid_idx_reg, tp_id);
                return TPK_BAD_PARAMETER;
        }

#if 0 /* Sometimes PID are added/removed very often. And SEC_INFO_T.PID are not used. So disable checking */
        if(pTp_drv->tp_pid[tp_id].pid_api_setting[*pPid_idx].valid == 0) {
                TP_WARNING("TP%u, pid_idx=%u not init yet\n", tp_id, *pPid_idx);
                return TPK_NOT_INIT;
        }
#endif

        *PID = pTp_drv->tp_pid[tp_id].pid_api_setting[*pPid_idx].PID;

        return TPK_SUCCESS;
}

INT32 Tp_GetSecParam(UINT16 sec_idx, TPK_SEC_REG_T* sec_reg)
{
        UINT32 Data[10];
        tp_tp_sec_ctrl_RBUS sec_ctrl;
        tp_tp_sec_data4_RBUS sec_data4;
        tp_tp_sec_data9_RBUS sec_data9;

        /* check parameter */
        CHECK_MAX_SEC_FILTER_COUNT(sec_idx);
        CHECK_TP_STRUCTURE();

        sec_ctrl.regValue = 0;
        sec_ctrl.r_w      = 0;
        sec_ctrl.idx      = sec_idx;
        WRITE_REG32(TP_TP_SEC_CTRL_reg, sec_ctrl.regValue);

        Data[0] = READ_REG32(TP_TP_SEC_DATA0_reg);
        Data[1] = READ_REG32(TP_TP_SEC_DATA1_reg);
        Data[2] = READ_REG32(TP_TP_SEC_DATA2_reg);
        Data[3] = READ_REG32(TP_TP_SEC_DATA3_reg);
        Data[4] = READ_REG32(TP_TP_SEC_DATA4_reg);
        Data[5] = READ_REG32(TP_TP_SEC_DATA5_reg);
        Data[6] = READ_REG32(TP_TP_SEC_DATA6_reg);
        Data[7] = READ_REG32(TP_TP_SEC_DATA7_reg);
        Data[8] = READ_REG32(TP_TP_SEC_DATA8_reg);
        Data[9] = READ_REG32(TP_TP_SEC_DATA9_reg);

        sec_data4.regValue = Data[4];
        sec_data9.regValue = Data[9];

        sec_reg->PID       = pTp_drv->sec[sec_idx].sec_reg.PID;
        sec_reg->crc_en    = sec_data4.crc_en;
        sec_reg->p_d       = sec_data4.p_d;
        sec_reg->p_n       = sec_data4.p_n;
        sec_reg->last      = sec_data4.last;
        sec_reg->next_sec  = sec_data4.next_sec;

        sec_reg->PosVal[0] = BYTE3(Data[0]);
        sec_reg->PosVal[1] = sec_data4.sp_filter << 6;
        sec_reg->PosVal[2] = 0x00;
        sec_reg->PosVal[3] = BYTE2(Data[0]);
        sec_reg->PosVal[4] = BYTE1(Data[0]);
        sec_reg->PosVal[5] = BYTE0(Data[0]);
        sec_reg->PosVal[6] = BYTE3(Data[1]);
        sec_reg->PosVal[7] = BYTE2(Data[1]);
        sec_reg->PosVal[8] = BYTE1(Data[1]);
        sec_reg->PosVal[9] = BYTE0(Data[1]);

        sec_reg->PosMsk[0] = BYTE3(Data[2]);
        sec_reg->PosMsk[1] = sec_data4.sp_mask << 6;
        sec_reg->PosMsk[2] = 0x00;
        sec_reg->PosMsk[3] = BYTE2(Data[2]);
        sec_reg->PosMsk[4] = BYTE1(Data[2]);
        sec_reg->PosMsk[5] = BYTE0(Data[2]);
        sec_reg->PosMsk[6] = BYTE3(Data[3]);
        sec_reg->PosMsk[7] = BYTE2(Data[3]);
        sec_reg->PosMsk[8] = BYTE1(Data[3]);
        sec_reg->PosMsk[9] = BYTE0(Data[3]);


        sec_reg->NegVal[0] = BYTE3(Data[5]);
        sec_reg->NegVal[1] = sec_data9.neg_sp_filter << 6;
        sec_reg->NegVal[2] = 0x00;
        sec_reg->NegVal[3] = BYTE2(Data[5]);
        sec_reg->NegVal[4] = BYTE1(Data[5]);
        sec_reg->NegVal[5] = BYTE0(Data[5]);
        sec_reg->NegVal[6] = BYTE3(Data[6]);
        sec_reg->NegVal[7] = BYTE2(Data[6]);
        sec_reg->NegVal[8] = BYTE1(Data[6]);
        sec_reg->NegVal[9] = BYTE0(Data[6]);

        sec_reg->NegMsk[0]  = BYTE3(Data[7]);
        sec_reg->NegMsk[1]  = sec_data9.neg_sp_mask << 6;
        sec_reg->NegMsk[2]  = 0x00;
        sec_reg->NegMsk[3]  = BYTE2(Data[7]);
        sec_reg->NegMsk[4]  = BYTE1(Data[7]);
        sec_reg->NegMsk[5]  = BYTE0(Data[7]);
        sec_reg->NegMsk[6]  = BYTE3(Data[8]);
        sec_reg->NegMsk[7]  = BYTE2(Data[8]);
        sec_reg->NegMsk[8]  = BYTE1(Data[8]);
        sec_reg->NegMsk[9]  = BYTE0(Data[8]);

        return TPK_SUCCESS;

}


INT32 Tp_Dump_PID_filter_Status(TPK_TP_ENGINE_T tp_id, UINT16 pid_idx)
{
        TPK_PID_REG_PARAM_T Param;
        UINT16 pid_idx_reg;
        INT32 result;

        CHECK_MAX_TP_COUNT(tp_id);

        switch(tp_id) {
                case TP_TP0:
                        pid_idx_reg = TP0_FIRST_PID_FILTER_IDX + pid_idx;
                        break;
                case TP_TP1:
                        pid_idx_reg = TP1_FIRST_PID_FILTER_IDX + pid_idx;
                        break;
                case TP_TP2:
                        pid_idx_reg = TP2_FIRST_PID_FILTER_IDX + pid_idx;
                        break;
                case TP_TP3:
                        pid_idx_reg = TP3_FIRST_PID_FILTER_IDX + pid_idx;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        result = Tp_GetPidParam(pid_idx_reg, &Param);
        if(Param.v) {
                TP_DBG("TP%u, pid_idx=%u, v=%u, pid=0x%x, sec_en=%u, sec_idx=%u, ddr_q=%u, info_q=%u, key=%u\n",
                       tp_id, pid_idx, Param.v, Param.pid, Param.sec_en, Param.sec_idx, Param.ddr_q, Param.info_q, Param.key);
        }
        return result;
}

INT32 Tp_Cmd_Dump_PID_filter_Status(TPK_TP_ENGINE_T tp_id, char *buffer)
{
        TPK_PID_REG_PARAM_T Param;
        UINT16 pid_idx_reg;
        INT32 result;
        UINT32 i, cur_pid_filter_count, pid_filter_count = 0;

        CHECK_MAX_TP_COUNT(tp_id);

        TP_DBG_SIMPLE("<TP%d pid filter Streamming=%d>\n", tp_id, pTp_drv->tp[tp_id].tp_stream_status);
        if(buffer != NULL) {
                sprintf(buffer, "%s<TP%d pid filter Streamming=%d>\n", buffer, tp_id, pTp_drv->tp[tp_id].tp_stream_status);
        }

        memset(&Param, 0, sizeof(Param));

        switch(tp_id) {
                case TP_TP0:
                        cur_pid_filter_count = TP0_PID_FILTER_COUNT;
                        break;
                case TP_TP1:
                        cur_pid_filter_count = TP1_PID_FILTER_COUNT;
                        break;
                case TP_TP2:
                        cur_pid_filter_count = TP2_PID_FILTER_COUNT;
                        break;
                case TP_TP3:
                        cur_pid_filter_count = TP3_PID_FILTER_COUNT;
                        break;
                default:
                        /* set default to tp0 */
                        cur_pid_filter_count = TP0_PID_FILTER_COUNT;
                        break;
        }

        for ( i = 0; i < cur_pid_filter_count; i++) {
                switch(tp_id) {
                        case TP_TP0:
                                pid_idx_reg = TP0_FIRST_PID_FILTER_IDX + i;
                                break;
                        case TP_TP1:
                                pid_idx_reg = TP1_FIRST_PID_FILTER_IDX + i;
                                break;
                        case TP_TP2:
                                pid_idx_reg = TP2_FIRST_PID_FILTER_IDX + i;
                                break;
                        case TP_TP3:
                                pid_idx_reg = TP3_FIRST_PID_FILTER_IDX + i;
                                break;
                        default:
                                TP_WARNING("unsupported tp_id=%d\n", tp_id);
                                return TPK_BAD_PARAMETER;
                }

                result = Tp_GetPidParam(pid_idx_reg, &Param);
                if ( Param.v )
                        pid_filter_count++;

                if(Param.v) {
                        TP_DBG_SIMPLE("pid_idx=%02u, pid=%04d(0x%04x), sec_en=%u, sec_idx=%02u, ddr_q=%u, info_q=%u, key=%u\n",
                                      pid_idx_reg, Param.pid, Param.pid, Param.sec_en, Param.sec_idx, Param.ddr_q, Param.info_q, Param.key);
                        if(buffer != NULL) {
                                sprintf(buffer, "%spid_idx=%02u, pid=%04d(0x%04x), sec_en=%u, sec_idx=%02u, ddr_q=%u, info_q=%u, key=%u\n",
                                        buffer, pid_idx_reg, Param.pid, Param.pid, Param.sec_en, Param.sec_idx, Param.ddr_q, Param.info_q, Param.key);

                                if( Param.sec_en == 1) {
                                        TPK_SEC_REG_T Param_section;
                                        UINT32 sec_idx = Param.sec_idx;

                                        do {
                                                Param_section = Tp_Cmd_Dump_Section_filter_Status(buffer, sec_idx);
                                                sec_idx = Param_section.next_sec;
                                        } while(Param_section.last == 0);
                                }
                        }
                }
        }
        TP_DBG_SIMPLE("amount:%d\n", pid_filter_count);
        TP_DBG_SIMPLE("----------------------------------------------------------------------------------------------------------------------------\n");
        if(buffer != NULL) {
                sprintf(buffer, "%samount:%d\n", buffer, pid_filter_count);
                sprintf(buffer, "%s----------------------------------------------------------------------------------------------------------------------------\n", buffer);
        }

        return TPK_SUCCESS;
}

TPK_SEC_REG_T Tp_Cmd_Dump_Section_filter_Status(char *buffer, UINT32 sec_idx)
{
        TPK_SEC_REG_T Param;
        INT32 result;

        memset(&Param, 0, sizeof(Param));

        if(buffer == NULL) {
                TP_WARNING("Error!! Tp_Cmd_Dump_Section_filter_Status buffer==NULL\n");
                return Param;
        }

        memset(&Param, 0, sizeof(Param));

        result = Tp_GetSecParam(sec_idx, &Param);

        sprintf(buffer, "%s   sec_idx=%03u pid=0x%04x P{%02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X} N{%02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X %02X,%02X} crc_en=%d p_d=%d p_n=%d last=%d next=%d\n",
                buffer, sec_idx, Param.PID, Param.PosVal[0], Param.PosMsk[0], Param.PosVal[1], Param.PosMsk[1], Param.PosVal[2], Param.PosMsk[2], Param.PosVal[3], Param.PosMsk[3], Param.PosVal[4], Param.PosMsk[4], Param.PosVal[5], Param.PosMsk[5], Param.PosVal[6], Param.PosMsk[6], Param.PosVal[7], Param.PosMsk[7], Param.PosVal[8], Param.PosMsk[8], Param.PosVal[9], Param.PosMsk[9],
                Param.NegVal[0], Param.NegMsk[0], Param.NegVal[1], Param.NegMsk[1], Param.NegVal[2], Param.NegMsk[2], Param.NegVal[3], Param.NegMsk[3], Param.NegVal[4], Param.NegMsk[4], Param.NegVal[5], Param.NegMsk[5], Param.NegVal[6], Param.NegMsk[6], Param.NegVal[7], Param.NegMsk[7], Param.NegVal[8], Param.NegMsk[8], Param.NegVal[9], Param.NegMsk[9], Param.crc_en, Param.p_d, Param.p_n, Param.last, Param.next_sec);

        return Param;
}


/********************************

     section filter control

********************************/
INT32 Tp_Get_MaxSec_Cnt(TPK_TP_ENGINE_T tp_id, UINT16 *pMax_Sec_Cnt)
{
        CHECK_MAX_TP_COUNT(tp_id);

        switch(tp_id) {
                case TP_TP0:
                        *pMax_Sec_Cnt = TP0_SEC_FILTER_COUNT;
                        break;
                case TP_TP1:
                        *pMax_Sec_Cnt = TP1_SEC_FILTER_COUNT;
                        break;
                case TP_TP2:
                        *pMax_Sec_Cnt = TP2_SEC_FILTER_COUNT;
                        break;
                case TP_TP3:
                        *pMax_Sec_Cnt = TP3_SEC_FILTER_COUNT;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }
        return TPK_SUCCESS;

}

INT32 Tp_Get_Valid_Pid_Cnt(TPK_TP_ENGINE_T tp_id, BOOL check_sec_filter)
{
        TPK_PID_REG_PARAM_T Param;
        UINT16 pid_idx_reg, max_pid_cnt;
        INT32 i, count_pid_sec = 0, count_sec = 0;

        CHECK_MAX_TP_COUNT(tp_id);

        switch(tp_id) {
                case TP_TP0:
                        pid_idx_reg = TP0_FIRST_PID_FILTER_IDX;
                        max_pid_cnt = TP0_PID_FILTER_COUNT;
                        break;
                case TP_TP1:
                        pid_idx_reg = TP1_FIRST_PID_FILTER_IDX;
                        max_pid_cnt = TP1_PID_FILTER_COUNT;
                        break;
                case TP_TP2:
                        pid_idx_reg = TP2_FIRST_PID_FILTER_IDX;
                        max_pid_cnt = TP2_PID_FILTER_COUNT;
                        break;
                case TP_TP3:
                        pid_idx_reg = TP3_FIRST_PID_FILTER_IDX;
                        max_pid_cnt = TP3_PID_FILTER_COUNT;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        for( i = 0; i < max_pid_cnt; i++ ) {
                Tp_GetPidParam(pid_idx_reg + i, &Param);
                if(Param.v) {
                        count_pid_sec++;
                        if ( Param.sec_en ) {
                                count_sec++;
                        }

                }
        }

        if ( check_sec_filter )
                return count_pid_sec;
        else
                return count_pid_sec - count_sec;
}

INT32 Tp_GetPID_FirstSecFilter(TPK_TP_ENGINE_T tp_id, UINT16 PID, UINT16 *pSec_idx)
{
        UINT16 i, max_sec_cnt;
        INT32 result;

        /* check parameter */
        if((PID >= MAX_PID_VALUE) || (pSec_idx == NULL)) {
                TP_WARNING("bad parameter, PID=%u, pSec_idx=%p\n",
                           PID, pSec_idx);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        result = Tp_Get_MaxSec_Cnt(tp_id, &max_sec_cnt);
        if(result != TPK_SUCCESS) {
                TP_WARNING("call Tp_Get_MaxSec_Cnt return error\n");
                return result;
        }

        /*  check if this PID already link section filter behind */
        for( i = 0; i < max_sec_cnt; i++) {
                if((pTp_drv->sec[i].valid) &&
                    (pTp_drv->sec[i].tp_id == tp_id) &&
                    (pTp_drv->sec[i].sec_api_setting.PID == PID) &&
                    (pTp_drv->sec[i].first_in_pid)) {
                        break;
                }
        }

        if( i < max_sec_cnt) {
                *pSec_idx = i;
                return TPK_SUCCESS;
        } else {
                return TPK_NOT_SET;
        }

}
INT32 Tp_GetPID_LastSecFilter(TPK_TP_ENGINE_T tp_id, UINT16 PID, UINT16 *pSec_idx)
{
        UINT16 i, max_sec_cnt;
        INT32 result;

        /* check parameter */
        if((PID >= MAX_PID_VALUE) || (pSec_idx == NULL)) {
                TP_WARNING("bad parameter, PID=%u, pSec_idx=%p\n",
                           PID, pSec_idx);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        result = Tp_Get_MaxSec_Cnt(tp_id, &max_sec_cnt);
        if(result != TPK_SUCCESS) {
                TP_WARNING("call Tp_Get_MaxSec_Cnt return error\n");
                return result;
        }

        /* check if this PID already link section filter behind */
        for( i = 0; i < max_sec_cnt; i++) {
                if((pTp_drv->sec[i].valid) &&
                    (pTp_drv->sec[i].tp_id == tp_id) &&
                    (pTp_drv->sec[i].sec_api_setting.PID == PID) &&
                    (pTp_drv->sec[i].sec_reg.last)) {
                        break;
                }
        }

        if( i < max_sec_cnt) {
                *pSec_idx = i;
                return TPK_SUCCESS;
        } else {
                return TPK_NOT_SET;
        }

}


INT32 Tp_Dump_Section_List(TPK_TP_ENGINE_T tp_id, UINT16 pid_idx)
{
        UINT16 i, sec_idx;
        TPK_SEC_REG_T sec_reg;
        INT32 result;
        UINT8 last = 0;

        /* check parameter */
        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        /* dump pid filter status first */
        result = Tp_Dump_PID_filter_Status(tp_id, pid_idx);
        if(result != TPK_SUCCESS) {
                TP_WARNING("TP%u pid_idx=%u dump PID filter status failed\n", tp_id, pid_idx);
                return result;
        }
        TP_DBG("TP%u, tp_sec_cnt=%u, pid_sec_cnt=%u\n",
               tp_id,
               pTp_drv->tp_pid[tp_id].tp_sec_cnt,
               pTp_drv->tp_pid[tp_id].pid_sec[pid_idx].pid_sec_cnt);

        /* find first section filter of TP/PID */
        for( i = 0; i < MAX_SEC_COUNT; i++) {
                if((pTp_drv->sec[i].valid) &&
                    (pTp_drv->sec[i].tp_id == tp_id) &&
                    (pTp_drv->sec[i].pid_idx == pid_idx) &&
                    (pTp_drv->sec[i].first_in_pid)) {
                        break;
                }
        }
        if( i >= MAX_SEC_COUNT) {
                TP_DBG("TP%u pid_idx=%u can not find matched section index\n", tp_id, pid_idx);
                return TPK_SUCCESS;
        }
        sec_idx = i;

        while(last == 0) {
                /* get section filter parameter from register */
                result = Tp_GetSecParam(sec_idx, &sec_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("TP%u pid_idx=%u sec_idx=%u can not get correct section reg setting\n",
                                   tp_id, pid_idx, sec_idx);
                        break;
                }

                /* print section filter status */
                TP_DBG("SEC[%u] : PID=0x%x, PosVal:", sec_idx, sec_reg.PID);
                for ( i = 0; i < sizeof(sec_reg.PosVal); i++) {
                        TP_DBG_SIMPLE("{0x%x,0x%x} ", sec_reg.PosVal[i], sec_reg.PosMsk[i]);
                }
                TP_DBG_SIMPLE("\n");

                TP_DBG("SEC[%u] : PID=0x%x, NegVal:", sec_idx, sec_reg.PID);
                for ( i = 0; i < sizeof(sec_reg.PosVal); i++) {
                        TP_DBG_SIMPLE("{0x%x,0x%x} ", sec_reg.NegVal[i], sec_reg.NegMsk[i]);
                }
                TP_DBG_SIMPLE(" next:%u, last:%u\n", sec_reg.next_sec, sec_reg.last);

                sec_idx = (UINT16)sec_reg.next_sec;
                last    = sec_reg.last;
        }

        return TPK_SUCCESS;
}


INT32 Tp_AddSecFilter( TPK_TP_ENGINE_T tp_id, TPK_SEC_FILTER_PARAM_T Param, void* file_handle, void** ppSec_handle)
{
        UINT16 i, max_pid_cnt, max_sec_cnt, pid_last_sec_idx, pid_idx, pid_idx_reg;
        INT32 result;
        TPK_PID_FILTER_PARAM_T pid_api_setting;
        TPK_SEC_REG_T *pSec_reg, *pLast_Sec_reg;
        UINT8 pid_update_flag, pid_ddr_buf_idx, pid_info_buf_idx;
        TPK_PID_REG_PARAM_T pid_reg;
        REGADDR tp_tf_cntl_addr;
        tp_tp_tf0_cntl_RBUS tp_tf_cntl_reg;

        /* check parameter */
        if((ppSec_handle == NULL) ||
            (Param.PID >= MAX_PID_VALUE) ||
            (Param.Request_buf == NULL) ||
            (Param.Complete == NULL)) {
                TP_WARNING("bad parameter, ppSec_handle=%p, Param.PID=0x%x, Param.Request_buf=%p, Param.Complete=%p\n",
                           ppSec_handle, Param.PID, Param.Request_buf, Param.Complete);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        result = Tp_Get_MaxPID_Cnt(tp_id, &max_pid_cnt);
        if(result != TPK_SUCCESS) {
                TP_WARNING("call Tp_Get_MaxPID_Cnt return error\n");
                return result;
        }

        result = Tp_Get_MaxSec_Cnt(tp_id, &max_sec_cnt);
        if(result != TPK_SUCCESS) {
                TP_WARNING("call Tp_Get_MaxSec_Cnt return error\n");
                return result;
        }

        /* check if section filter count reach the limit of each tp */
        if(pTp_drv->tp_pid[tp_id].tp_sec_cnt >= max_sec_cnt) {
                TP_WARNING("section filter count(%u) of TP%u reach the limit, can not allocat section filter\n",
                           pTp_drv->tp_pid[tp_id].tp_sec_cnt, tp_id);

                result = TPK_NOT_ENOUGH_RESOURCE;
                goto SEC_ERROR;
        }

        /* add pid filter, check if there is pid filter exist */
        memset(&pid_api_setting, 0, sizeof(pid_api_setting));

        pid_api_setting.DescrambleEn = 0;
        pid_api_setting.KeySel       = 0;
        pid_api_setting.PID          = Param.PID;
        for( i = 0; i < max_pid_cnt; i++) {
                if((pTp_drv->tp_pid[tp_id].pid_api_setting[i].valid) &&
                    (pTp_drv->tp_pid[tp_id].pid_api_setting[i].PID == Param.PID)) {
                        /* check if section filter count reach the limit of pid filter */
                        if(pTp_drv->tp_pid[tp_id].pid_sec[i].pid_sec_cnt >= MAX_SEC_PER_PID) {
                                TP_WARNING("section filter count(%u) of TP%u PID[0x%x] reach the limit, can not allocat section filter\n",
                                           pTp_drv->tp_pid[tp_id].pid_sec[i].pid_sec_cnt, tp_id, pTp_drv->tp_pid[tp_id].pid_api_setting[i].PID);
                                result = TPK_NOT_ENOUGH_RESOURCE;
                                goto SEC_ERROR;
                        }
                        pid_api_setting.DescrambleEn = pTp_drv->tp_pid[tp_id].pid_api_setting[i].DescrambleEn;
                        pid_api_setting.KeySel       = pTp_drv->tp_pid[tp_id].pid_api_setting[i].KeySel;
                        break;
                }
        }
        result = Tp_AddPIDFilter(tp_id, pid_api_setting, (void *)SEC_FILTER_FILE_HANDLE);
        if(result != TPK_SUCCESS) {
                TP_WARNING("call Tp_AddPIDFilter() failed (%d)\n", result);
                goto SEC_ERROR;
        }

        /* add section filter */
        for( i = 0; i < MAX_SEC_COUNT; i++) {
                if(pTp_drv->sec[i].valid == 0) {
                        pTp_drv->sec[i].sec_idx     = i;
                        pTp_drv->sec[i].tp_id       = tp_id;
                        memcpy(&pTp_drv->sec[i].sec_api_setting, &Param, sizeof(TPK_SEC_FILTER_PARAM_T));
                        pTp_drv->sec[i].file_handle = file_handle;
                        pSec_reg                    = &pTp_drv->sec[i].sec_reg;

                        pSec_reg->PID = Param.PID;
                        memcpy(pSec_reg->PosVal, Param.PosVal, 10);
                        memcpy(pSec_reg->PosMsk, Param.PosMsk, 10);
                        memcpy(pSec_reg->NegVal, Param.NegVal, 10);
                        memcpy(pSec_reg->NegMsk, Param.NegMsk, 10);
                        pSec_reg->crc_en = 1;
                        pSec_reg->p_d    = 0;
                        pSec_reg->p_n    = 0;

                        /* if it is toggle mode, do not mask mask byte[0] bit0 */
                        if(Param.toggle_mode_en) {
                                pTp_drv->sec[i].toggle_rec = 0xFF;
                                pSec_reg->PosMsk[0] &= 0xFE;
                                pSec_reg->NegMsk[0] &= 0xFE;
                        }

                        /* get pid filter parameter */
                        result = _PID_Filter_Update_Check(tp_id, pid_api_setting, &pid_idx, &pid_idx_reg,
                                                          &pid_update_flag, &max_pid_cnt, &pid_ddr_buf_idx,
                                                          &pid_info_buf_idx);
                        if((result != TPK_SUCCESS) || (pid_update_flag != PID_NO_UPDATE)) {
                                TP_WARNING("call _PID_Filter_Update_Check return error (%d) or pid_update_flag error(%u)\n",
                                           result, pid_update_flag);
                                goto SEC_ERROR;
                        }
                        pTp_drv->sec[i].pid_idx     = pid_idx;
                        pTp_drv->sec[i].pid_idx_reg = pid_idx_reg;


                        result = Tp_GetPID_LastSecFilter(tp_id, Param.PID, &pid_last_sec_idx);
                        if(result == TPK_NOT_SET) {
                                /* there is no section filter linked behind this PID filter, link this section filter into PID filter */
                                pTp_drv->sec[i].first_in_pid = 1;

                                /* update section filter param */
                                pSec_reg->last     = 1;
                                pSec_reg->next_sec = 0;
                                result             = Tp_SetSecParam(i, *pSec_reg);
                                if(result != TPK_SUCCESS) {
                                        TP_WARNING("call Tp_SetSecParam() failed (%d)\n", result);
                                        goto SEC_ERROR;
                                }

                                /* update pid filter param */
                                result = Tp_GetPidParam(pid_idx_reg, &pid_reg);
                                if(result != TPK_SUCCESS) {
                                        TP_WARNING("call Tp_GetPidParam return error (result=%d, pid_idx_reg=%u)\n",
                                                   result, pid_idx_reg);
                                        goto SEC_ERROR;
                                }
                                pid_reg.sec_idx = i;
                                pid_reg.si_en   = 1;
                                pid_reg.sec_en  = 1;

                                switch (tp_id) {
                                        case TP_TP0:
                                                tp_tf_cntl_addr = TP_TP_TF0_CNTL_reg;
                                                break;
                                        case TP_TP1:
                                                tp_tf_cntl_addr = TP_TP_TF1_CNTL_reg;
                                                break;
                                        case TP_TP2:
                                                tp_tf_cntl_addr = TP_TP_TF2_CNTL_reg;
                                                break;
                                        case TP_TP3:
                                                tp_tf_cntl_addr = TP_TP_TF3_CNTL_reg;
                                                break;
                                        default:

                                                break;
                                }

                                tp_tf_cntl_reg.regValue = READ_REG32(tp_tf_cntl_addr);

                                if(tp_tf_cntl_reg.de_en == 1) {
                                        pid_reg.pre_des = 1;
                                } else {
                                        pid_reg.pre_des = 0;
                                }

                                result = Tp_SetPidParam(pid_idx_reg, pid_reg);
                                if(result != TPK_SUCCESS) {
                                        TP_WARNING("call Tp_SetPidParam return error (result=%d, pid_idx_reg=%u)\n",
                                                   result, pid_idx_reg);
                                        goto SEC_ERROR;
                                }

                        } else if(result == TPK_SUCCESS) {
                                /* there is section filter linked behind this PID filter, link this section filter into last sec filter */
                                /* update section filter param ("new" last section filter) */
                                pSec_reg->last     = 1;
                                pSec_reg->next_sec = 0;
                                result = Tp_SetSecParam(i, *pSec_reg);
                                if(result != TPK_SUCCESS) {
                                        TP_WARNING("call Tp_SetSecParam() failed (%d)\n", result);
                                        goto SEC_ERROR;
                                }

                                /* update section filter param ("old" last section filter) */
                                pLast_Sec_reg           = &pTp_drv->sec[pid_last_sec_idx].sec_reg;
                                pLast_Sec_reg->last     = 0;
                                pLast_Sec_reg->next_sec = i;
                                result = Tp_SetSecParam(pid_last_sec_idx, *pLast_Sec_reg);
                                if(result != TPK_SUCCESS) {
                                        TP_WARNING("call Tp_SetSecParam() failed (%d)\n", result);
                                        goto SEC_ERROR;
                                }

                                pTp_drv->sec[i].first_in_pid = 0;
                                pTp_drv->sec[i].last_sec_idx = pid_last_sec_idx;
                        } else {
                                TP_WARNING("call Tp_GetPID_LastSecFilter() failed (%d)\n", result);
                                goto SEC_ERROR;
                        }

                        pTp_drv->sec[i].sec_deliver_cnt = 0;
                        pTp_drv->sec[i].valid           = 1;
                        *ppSec_handle = (void*)(&pTp_drv->sec[i]);
                        TP_INFO("TP%u add section filter success, pid_idx=%u, pid_idx_reg=%u, sec_idx=%u, sec_handle=%p\n",
                                tp_id, pid_idx, pid_idx_reg, i, &pTp_drv->sec[i]);

                        pTp_drv->tp_pid[tp_id].tp_sec_cnt++;
                        pTp_drv->tp_pid[tp_id].pid_sec[pid_idx].pid_sec_cnt++;

                        /* add a section successfully, */
                        pTp_drv->tp[tp_id].mass_buffer.RP_Connect_cnt = MASS_DATA_BUFFER_RP_CONNECT;

                        break;
                }
        }

        if( i >= MAX_SEC_COUNT) {
                TP_WARNING("TP%u can not find empty section filter to add\n", tp_id);
                result = TPK_NOT_ENOUGH_RESOURCE;
                goto SEC_ERROR;
        }

        TP_INFO("Add sec_filter: PID=0x%x, crc=%u, one=%u, toggle=%u \n",
                Param.PID, Param.crc_en, Param.one_shoot, Param.toggle_mode_en);

        if(tp_log_onoff && CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_SECTION)) {
                /* display section filter content */
                TP_VERBOSE("Pol:");
                for ( i = 0; i < 10; i++) {
                        TP_VERBOSE("{0x%x,0x%x} ", Param.PosVal[i], Param.PosMsk[i]);
                }
                TP_VERBOSE("\n");
                TP_VERBOSE("Nag:");
                for ( i = 0; i < 10; i++) {
                        TP_VERBOSE("{0x%x,0x%x} ", Param.NegVal[i], Param.NegMsk[i]);
                }
                TP_VERBOSE("\n");

                Tp_Dump_Section_List(tp_id, pid_idx);
        }

        return TPK_SUCCESS;

SEC_ERROR:
        return result;

}

INT32 Tp_RemoveSectionFilter(TPK_TP_ENGINE_T tp_id, void* pSec_handle)
{
        INT32 result;
        UINT16 i, sec_idx, last_sec_idx, next_sec_idx = 0;
        TPK_SEC_FILTER_STATUS_T *pSec, *pSec_next, *pSec_last;
        TPK_PID_REG_PARAM_T pid_reg;

        /* check parameter */
        if(pSec_handle == NULL) {
                TP_WARNING("bad parameter, pSec_handle=%p\n", pSec_handle);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        for(i = 0; i < MAX_SEC_COUNT; i++) {
                if((void*)&pTp_drv->sec[i] == pSec_handle)
                        break;
        }
        if(i >= MAX_SEC_COUNT) {
                TP_WARNING("can not match section handle, tp_id=%u, pSec_handle=%p\n",
                           tp_id, pSec_handle);
                return TPK_BAD_PARAMETER;
        }
        sec_idx = i;
        pSec = (TPK_SEC_FILTER_STATUS_T *)pSec_handle;

        if(tp_id != pSec->tp_id) {
                TP_WARNING("tp_id is not equal to pSec->tp_id, tp_id=%u, pSec->tp_id=%u\n",
                           tp_id, pSec->tp_id);
                return TPK_BAD_PARAMETER;
        }

        if(pSec->valid == 0) {
                TP_WARNING("section filter handle does not init yet, tp_id=%u, pSec_handle=%p, sec_idx=%u\n",
                           tp_id, pSec_handle, sec_idx);
                result = TPK_NOT_SET;
                goto SEC_ERROR;
        }

        if((pSec->first_in_pid) && (pSec->sec_reg.last)) {
                /* case 1: first sec=1 and last sec=1 */
                /* disable section filter function of PID filter and remove PID filter */
                /* update pid filter param */
                result = Tp_GetPidParam(pSec->pid_idx_reg, &pid_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("call Tp_GetPidParam return error (result=%d, pid_idx_reg=%u)\n",
                                   result, pSec->pid_idx_reg);
                        goto SEC_ERROR;
                }
                pid_reg.si_en  = 0;
                pid_reg.sec_en = 0;

                result = Tp_SetPidParam(pSec->pid_idx_reg, pid_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("call Tp_SetPidParam return error (result=%d, pid_idx_reg=%u)\n",
                                   result, pSec->pid_idx_reg);
                        goto SEC_ERROR;
                }

                /* remove PID filter */
                result = Tp_RemovePIDFilter(tp_id, pSec->sec_reg.PID, SEC_FILTER_FILE_HANDLE);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("call Tp_RemovePIDFilter return error (result=%d, pid=0x%x)\n",
                                   result, pSec->sec_reg.PID);
                        goto SEC_ERROR;
                }
                TP_INFO("TP%u remove section filter, case 1, pid_idx=%u, pid_idx_reg=%u, PID=0x%x, sec_idx=%u\n",
                        tp_id, pSec->pid_idx, pSec->pid_idx_reg, pSec->sec_reg.PID, sec_idx);
        } else if((pSec->first_in_pid) && (pSec->sec_reg.last == 0)) {
                /* case 2: first sec =1 and last sec =0 */
                /* set first section filter to second section filter */
                next_sec_idx = pSec->sec_reg.next_sec;
                if(pTp_drv->sec[next_sec_idx].valid != 1) {
                        TP_WARNING("second section filter (idx=%u) of PID(0x%x) is not valid \n",
                                   next_sec_idx, pSec->sec_reg.PID);
                        result = TPK_RESOURCE_CONFLICT;
                        goto SEC_ERROR;
                }

                result = Tp_GetPidParam(pSec->pid_idx_reg, &pid_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("call Tp_GetPidParam return error (result=%d, pid_idx_reg=%u)\n",
                                   result, pSec->pid_idx_reg);
                        goto SEC_ERROR;
                }
                pid_reg.sec_idx = next_sec_idx;

                result = Tp_SetPidParam(pSec->pid_idx_reg, pid_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("call Tp_SetPidParam return error (result=%d, pid_idx_reg=%u)\n",
                                   result, pSec->pid_idx_reg);
                        goto SEC_ERROR;
                }

                pTp_drv->sec[next_sec_idx].first_in_pid = 1;
                TP_INFO("TP%u remove section filter, case 2, pid_idx=%u, pid_idx_reg=%u, PID=0x%x, sec_idx=%u\n",
                        tp_id, pSec->pid_idx, pSec->pid_idx_reg, pSec->sec_reg.PID, sec_idx);

        } else if((pSec->first_in_pid == 0) && (pSec->sec_reg.last == 0)) {
                /* case 3: first sec=0 and last sec=0 */
                /* link last section filter with next section filter */
                next_sec_idx = pSec->sec_reg.next_sec;
                if(pTp_drv->sec[next_sec_idx].valid != 1) {
                        TP_WARNING("second section filter (idx=%u) of PID(0x%x) is not valid \n",
                                   next_sec_idx, pSec->sec_reg.PID);
                        result = TPK_RESOURCE_CONFLICT;
                        goto SEC_ERROR;
                }
                last_sec_idx = pSec->last_sec_idx;
                if(pTp_drv->sec[last_sec_idx].valid != 1) {
                        TP_WARNING("second section filter (idx=%u) of PID(0x%x) is not valid \n",
                                   next_sec_idx, pSec->sec_reg.PID);
                        result = TPK_RESOURCE_CONFLICT;
                        goto SEC_ERROR;
                }
                pSec_last = &pTp_drv->sec[last_sec_idx];
                pSec_next = &pTp_drv->sec[next_sec_idx];

                pSec_last->sec_reg.next_sec = next_sec_idx;

                result = Tp_SetSecParam(last_sec_idx, pSec_last->sec_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("call Tp_SetSecParam() failed (%d)\n", result);
                        goto SEC_ERROR;
                }

                pSec_next->last_sec_idx = last_sec_idx;
                TP_INFO("TP%u remove section filter, case 3, pid_idx=%u, pid_idx_reg=%u, PID=0x%x, sec_idx=%u\n",
                        tp_id, pSec->pid_idx, pSec->pid_idx_reg, pSec->sec_reg.PID, sec_idx);
        } else {
                /* case 4: first sec=0 and last sec=1 */
                last_sec_idx = pSec->last_sec_idx;
                if(pTp_drv->sec[last_sec_idx].valid != 1) {
                        TP_WARNING("second section filter (idx=%u) of PID(0x%x) is not valid \n",
                                   next_sec_idx, pSec->sec_reg.PID);
                        result = TPK_RESOURCE_CONFLICT;
                        goto SEC_ERROR;
                }
                pSec_last                   = &pTp_drv->sec[last_sec_idx];
                pSec_last->sec_reg.last     = 1;
                pSec_last->sec_reg.next_sec = 0;
                result = Tp_SetSecParam(last_sec_idx, pSec_last->sec_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("call Tp_SetSecParam() failed (%d)\n", result);
                        goto SEC_ERROR;
                }
                TP_INFO("TP%u remove section filter, case 4, pid_idx=%u, pid_idx_reg=%u, PID=0x%x, sec_idx=%u\n",
                        tp_id, pSec->pid_idx, pSec->pid_idx_reg, pSec->sec_reg.PID, sec_idx);

        }

        pSec->valid = 0;
        pTp_drv->tp_pid[tp_id].pid_sec[pSec->pid_idx].pid_sec_cnt--;
        /* if there is no section filter link behind of TP, no need to check RP for section data */
        pTp_drv->tp_pid[tp_id].tp_sec_cnt--;

        if(pTp_drv->tp_pid[tp_id].tp_sec_cnt) {
                pTp_drv->tp[tp_id].mass_buffer.RP_Connect_cnt = MASS_DATA_BUFFER_RP_CONNECT;
        } else {
                pTp_drv->tp[tp_id].mass_buffer.RP_Connect_cnt = MASS_DATA_BUFFER_RP_CONNECT; /* -1; */
                /* section filter all removed, flush info pack buffer to clean left content */
                Tp_flush_Buf(tp_id, 0, BUF_SEL_INFO_PACK);

        }

        if(tp_log_onoff && CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_SECTION)) {
                Tp_Dump_Section_List(tp_id, pSec->pid_idx);
        }

        return TPK_SUCCESS;

SEC_ERROR:
        return result;

}

INT32 _find_PID_Filter_Idx(TPK_TP_ENGINE_T tp_id, UINT16 PID, UINT16* pPid_idx)
{
        UINT16 i, pid_max_cnt;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        switch(tp_id) {
                case TP_TP0:
                        pid_max_cnt = TP0_PID_FILTER_COUNT;
                        break;
                case TP_TP1:
                        pid_max_cnt = TP1_PID_FILTER_COUNT;
                        break;
                case TP_TP2:
                        pid_max_cnt = TP2_PID_FILTER_COUNT;
                        break;
                case TP_TP3:
                        pid_max_cnt = TP2_PID_FILTER_COUNT;
                        break;
                default:
                        return TPK_BAD_PARAMETER;
        }
        for( i = 0; i < pid_max_cnt; i++) {
                if((pTp_drv->tp_pid[tp_id].pid_api_setting[i].valid) &&
                    (pTp_drv->tp_pid[tp_id].pid_api_setting[i].PID == PID))
                        break;
        }

        if(i > pid_max_cnt)
                return TPK_NOT_SET;

        *pPid_idx = i;
        return TPK_SUCCESS;
}

INT32 Tp_IsValidPhyAddr(TPK_TP_ENGINE_T tp_id, UADDRESS PhyAddr, UINT8 buffer_flag)
{
        UADDRESS BufferBasePhy;
        UADDRESS BufferLimitPhy;
        TPK_TP_BUF_T* pBuf_status;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        if((buffer_flag == TP_BUFFER_MASS_DATA) ||
            (buffer_flag == TP_BUFFER_SECTION))
                pBuf_status = &pTp_drv->tp[tp_id].mass_buffer;
        else
                pBuf_status = &pTp_drv->tp[tp_id].info_pack_buffer;

        if(pBuf_status->inited == 0) {
                TP_WARNING("buffer structure not init, tp_id=%u, buffer_flag=%u\n", tp_id, buffer_flag);
                return TPK_NOT_INIT;
        }

        BufferBasePhy  = pBuf_status->BasePhy;
        BufferLimitPhy = pBuf_status->LimitPhy;

        if ((PhyAddr < BufferBasePhy) ||
            (PhyAddr >= BufferLimitPhy)) {
                TP_WARNING("data pointer (0x%x) is out of buffer range (base: 0x%x, limit: 0x%x), tp_id=%u, buffer_flag=%u\n",
                           PhyAddr, BufferBasePhy , BufferLimitPhy, tp_id, buffer_flag);
                return TPK_DATA_OUT_OF_RANGE;
        }

        return TPK_SUCCESS;
}

INT32 TP_GetTSPStart(TPK_TP_ENGINE_T tp_id, UADDRESS PhyAddr, UADDRESS* pTsp_hdr_phy, UADDRESS* pTsp_hdr_vir )
{
        UADDRESS BufferBasePhy;
        UADDRESS BufferLimitPhy;
        TPK_TP_BUF_T* pBuf_status;
        UINT8 *buf;

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        pBuf_status = &pTp_drv->tp[tp_id].mass_buffer;

        if(pBuf_status->inited == 0) {
                TP_WARNING("buffer structure not init, tp_id=%u\n", tp_id);
                return TPK_NOT_INIT;
        }

        BufferBasePhy  = pBuf_status->BasePhy;
        BufferLimitPhy = pBuf_status->LimitPhy;


        if ((PhyAddr < BufferBasePhy) ||
            (PhyAddr >= BufferLimitPhy) ||
            (BufferBasePhy == 0) ||
            (BufferLimitPhy == 0) ||
            (pBuf_status->BufSize == 0) ) {
                TP_WARNING("\n");
                return TPK_NOT_INIT;
        }

        *pTsp_hdr_phy = PhyAddr - ((PhyAddr - BufferBasePhy) % pTp_drv->tp[tp_id].mass_buffer.bock_size);
        *pTsp_hdr_vir = (UADDRESS)Tp_Buf_Phy_to_Vir(tp_id, TP_BUFFER_MASS_DATA, (UINT8*) * pTsp_hdr_phy);
        if(*pTsp_hdr_vir == 0) {
                TP_WARNING("TP%u get TSP header virtual pointer error\n", tp_id);
                return TPK_NOT_INIT;
        }

        buf = (UINT8 *)(*pTsp_hdr_vir);
        if (pTp_drv->tp[tp_id].IsPktWithTimeStamp == 1) {
                buf  = buf + TIME_STAMP_PADDING;
        }

        if(buf[0] != 0x47) {
                TP_WARNING("TP%u get TSP header virtual pointer != 0x47, tsp header = 0x%x\n", tp_id, buf[0]);
        }

        return TPK_SUCCESS;
}

//UINT64 STC_infopack;
//UINT64 PCR_infopack;

INT32 Tp_ParseInfoPack(TPK_TP_ENGINE_T tp_id, UINT8* pData, SEC_INFO_T* pInfo) /* pData is virtual memory */
{
        INT32 result;

        /* check parameter */
        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        /* parsing section info pack */
        pInfo->format = FORMAT_UNKNOWN_INFO;

        if ((pData[0]& SEC_INFO_PACK_SEL) == SEC_INFO_PACK) {
                /* SEC_INFO */
                /* get PID entry */
                pInfo->pid_idx_reg = ((pData[6] & 0x3) << 5) + (pData[7] >> 3);
                result = Tp_GetPID_info_for_InfoPack(tp_id, pInfo->pid_idx_reg, &pInfo->PID, &pInfo->pid_idx);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("TP%d call Tp_GetPID_info_for_InfoPack return error (%d)\n", tp_id, result);
                        return result;
                }

                pInfo->format     = FORMAT_SEC_INFO_V2;
                pInfo->pointer_phy = (pData[0] & 0x3F);
                pInfo->pointer_phy = (pInfo->pointer_phy << 8) + pData[1];
                pInfo->pointer_phy = (pInfo->pointer_phy << 8) + pData[2];
                pInfo->pointer_phy = (pInfo->pointer_phy << 8) + pData[3];
                pInfo->pointer_phy = (pInfo->pointer_phy << 2) + (pData[4] >> 6);

                pInfo->section_length = ((pData[4] & 0x3f) << 2) + (pData[5] >> 6);
                pInfo->tail_status    = (pData[5] & 0x3c) >> 2;
                pInfo->match_id       = ((pData[5] & 0x3) << 6) + (pData[6] >> 2);
                pInfo->header_status  = pData[7] & 0x7;

                tp_mask_print_emerg(TP_LOG_BLOCK_SECTION, TP_LOG_LEVEL_DEBUG, "TP%d: Get SEC_INFO = %02x %02x %02x %02x_%02x %02x %02x %02x (ptr=0x%x,len=%u,t=0x%x,id=%u,h=0x%x,pid=0x%x)\n",
                                    tp_id,
                                    pData[0], pData[1], pData[2], pData[3], pData[4], pData[5], pData[6], pData[7],
                                    pInfo->pointer_phy,
                                    pInfo->section_length,
                                    pInfo->tail_status,
                                    pInfo->match_id,
                                    pInfo->header_status,
                                    pInfo->PID);

        }
#if 0
        else if((pData[0]& SEC_INFO_PACK_SEL) == AF0_INFO_PACK) {
                //TP_WARNING("AF0 Info Pack = %02x %02x %02x %02x_%02x %02x %02x %02x\n",       pData[0], pData[1], pData[2], pData[3], pData[4], pData[5], pData[6], pData[7]);
                STC_infopack = pData[0] << 56 | pData[1] << 48 | pData[2] << 40 | pData[3] << 32 | pData[4] << 24 | pData[5] << 16 | pData[6] << 8 | pData[7];
                return TPK_NOT_SUPPORT;
        } else if((pData[0]& SEC_INFO_PACK_SEL) == AF1_INFO_PACK) {
                UINT8* pointer_vir;
                UINT8* pointer_phy;
                pointer_phy = pData[4] << 24 | pData[5] << 16 | pData[6] << 8 | pData[7];
                pointer_vir = Tp_Buf_Phy_to_Vir(tp_id, TP_BUFFER_MASS_DATA, pointer_phy);
                if(pointer_vir[0]& _BIT4) {
                        //TP_WARNING("AF1 Info Pack = %02x %02x %02x %02x_%02x %02x %02x %02x\n", pData[0], pData[1], pData[2], pData[3], pData[4], pData[5], pData[6], pData[7]);
                        //TP_WARNING("AF Data %02x %02x %02x %02x %02x %02x %02x %02x\n", pointer_vir[0], pointer_vir[1], pointer_vir[2], pointer_vir[3], pointer_vir[4], pointer_vir[5], pointer_vir[6], pointer_vir[7]);
                        PCR_infopack = (pointer_vir[1] << 24) | (pointer_vir[2] << 16) | (pointer_vir[3] << 8) | pointer_vir[4];
                        PCR_infopack = PCR_infopack << 1;
                        PCR_infopack = PCR_infopack | (pointer_vir[5] & 0x01);
                        TP_WARNING("STC=%llu PCR=(0x%x)%llu\n", STC_infopack, PCR_infopack, PCR_infopack);
                }
                return TPK_NOT_SUPPORT;
        }
#endif
        else {
                TP_WARNING("TP%d: Unknown Section Info Pack = %02x %02x %02x %02x_%02x %02x %02x %02x\n",
                           tp_id, pData[0], pData[1], pData[2], pData[3], pData[4], pData[5], pData[6], pData[7]);
                return TPK_NOT_SUPPORT;
        }

        /* check pointer is valid or not */
        result = Tp_IsValidPhyAddr(tp_id, pInfo->pointer_phy, TP_BUFFER_SECTION);
        if(result != TPK_SUCCESS) {
                TP_WARNING("TP%d call Tp_IsValidPhyAddr return error (%d)\n", tp_id, result);
                return result;
        }

        pInfo->pointer_vir = (UADDRESS)Tp_Buf_Phy_to_Vir(tp_id, TP_BUFFER_MASS_DATA, (UINT8*)pInfo->pointer_phy);
        if(pInfo->pointer_vir == 0) {
                TP_WARNING("TP%u Get sub section start virtual pointer error\n", tp_id);
                return TPK_NOT_INIT;
        }

        result = TP_GetTSPStart(tp_id, pInfo->pointer_phy, &pInfo->tsp_hdr_phy, &pInfo->tsp_hdr_vir);

        return result;
}

INT32 Tp_DeliverSectionData(
        TPK_TP_ENGINE_T tp_id,
        UINT16 pid_idx,
        unsigned char crc_err
)
{
        UINT16 i, SecLen, max_pid_cnt = 0;
        INT32 result, get_buf_idx;
        TPK_TP_PID_SEC_PARAM_T *pPid_sec;
        UINT8 *pData, *pDeliver_Sec_buf = NULL;
        TPK_PID_FILTER_PARAM_T *pPid_param;
        TPK_SEC_FILTER_STATUS_T *pSec;
        TPK_SEC_DATA_T sec_data;

        /* check parameter */
        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_MAX_PID_FILTER_COUNT(pid_idx);
        CHECK_TP_STRUCTURE();

        result = Tp_Get_MaxPID_Cnt(tp_id, &max_pid_cnt);
        if(result != TPK_SUCCESS) {
                TP_WARNING("call Tp_Get_MaxPID_Cnt return error\n");
                return result;
        }

        if(pid_idx >= max_pid_cnt) {
                TP_WARNING("pid_idx error (tp_id=%u, pid_idx=%u)\n", tp_id, pid_idx);
                return TPK_RESOURCE_CONFLICT;
        }

        pPid_sec = &pTp_drv->tp_pid[tp_id].pid_sec[pid_idx];
        pData    = pPid_sec->pSec_buf;
        if ((pPid_sec->sec_data_cnt == 0) || (pData == NULL)) {
                TP_WARNING("sec_data_cnt=%u, pSec_buf=%p\n", pPid_sec->sec_data_cnt, pData);
                return TPK_NOT_INIT;
        }

        /* check if section data length is equal to section buffer data counter */
        SecLen = ((pData[1] << 8) + pData[2]) & 0xFFF;
        if ((SecLen + 3) != pPid_sec->sec_data_cnt) {
                if(pTp_drv->tp[tp_id].errPktDiff < 20) {
                        TP_WARNING_DEBUG_LEVEL("error : section length mismatch (%02x %02x %02x), sec_data_cnt=%u (should be %u), TP%u, pid_idx=%u ,PID=0x%x\n",
                                               pData[0], pData[1], pData[2], pPid_sec->sec_data_cnt, SecLen,
                                               tp_id,
                                               pid_idx,
                                               pTp_drv->tp_pid[tp_id].pid_api_setting[pid_idx].PID);
                        result = TPK_SECTION_DATA_ERROR;
                        goto SECTION_ERROR;
                }
        }

        /* PAT/CAT/PMT need     check section_syntax_indicator to discard error data*/
        switch(pData[0]) {
                case 0x00:        /* PAT */
                case 0x01:        /* CAT */
                case 0x02:        /* PMT */
                        //case 0x42:    /* SDT (Actual stream)  from ARIB B25 */
                        //case 0x46:    /* SDT (SDT (Other stream)) from ARIB B25 */
                        if ((pData[1] & 0x80) == 0) {
                                TP_WARNING("error : TP%d section syntax indicator of table id %02x should not be 0 (%02x %02x %02x), %d (%d)\n",
                                           tp_id, pData[0], pData[0], pData[1], pData[2], pPid_sec->sec_data_cnt, SecLen);
                                return -1;
                        }
        }

        pPid_param = &pTp_drv->tp_pid[tp_id].pid_api_setting[pid_idx];
        /* if it is non-generic section and clear crc_err status */
        if ((pData[1] & 0x80) == 0 && crc_err) {
                if(!(pData[0] == 0x70 || pData[0] == 0x73 || pData[0] >= 0x80)) { /* TDT TOT section_syntax_indicator=0  , user private maybe section_syntax_indicator=0*/
                        TP_WARNING_DEBUG_LEVEL("Non generic section (%02x %02x %02x ...), ignore CRC check(tp_id=%u, pid_idx=%u, PID=0x%x)\n",
                                               pData[0], pData[1], pData[2], tp_id, pid_idx, pPid_param->PID);
                }
                crc_err = 0;
        }

        if (crc_err == SEC_NO_CRC_CHECK) {
                TP_WARNING("Section without hw CRC check, use SW CRC to instead(tp_id=%u, pid_idx=%u, PID=0x%x)\n",
                           tp_id, pid_idx, pPid_param->PID);
                crc_err = DoCRC32(pData, pPid_sec->sec_data_cnt) ? 1 : 0;
        }

        if (crc_err) {
                if(pTp_drv->tp[tp_id].errPktDiff < 20) {
                        TP_WARNING_DEBUG_LEVEL("DeliverSectionData tp_id=%u PID=0x%x With CRC error\n",
                                               tp_id, pPid_param->PID);
                }
        }

        /* check every section filter and deliver it to caller */
        for( i = 0; i < MAX_SEC_COUNT; i++) {
                pSec = &pTp_drv->sec[i];
                if((pSec->valid) &&
                    (pSec->sec_api_setting.PID == pPid_param->PID) &&
                    (pSec->tp_id == tp_id) &&
                    (pSec->sec_api_setting.Complete != NULL) &&
                    (pSec->sec_api_setting.Request_buf != NULL)) {
                        if((pSec->sec_api_setting.one_shoot) && (pSec->sec_deliver_cnt)) {
                                /* this section filter set to one shoot and already delivered */
                                continue;
                        }

                        if((pSec->sec_api_setting.crc_en) && (crc_err)) {
                                /* upper layer ask to mask CRC error section */
                                continue;
                        }

                        /* check first byte toggle mode */
                        if((pSec->sec_api_setting.toggle_mode_en) &&
                            (pSec->toggle_rec != 0xFF) &&
                            (((pSec->toggle_rec + 1) & 0x1) != (pData[0] & 0x1))) {
                                TP_VERBOSE("TP%u, PID[0x%x], toggle bit not match, data[0]=0x%x, last toggle bit=0x%x\n",
                                           tp_id, pPid_param->PID, pData[0], pSec->toggle_rec);
                                continue;
                        }

                        /* double check section positive filter, this operation is must */
                        /* because if there are several section filters linked in same PID filter, */
                        /* hardware did not tell which section filter is matched */
                        if (MaskMemCmp(pData, pSec->sec_api_setting.PosVal, pSec->sec_api_setting.PosMsk, 10) != 0) {
                                TP_VERBOSE("SEC[%d] DeliverSectionData failed, check Postive mask failed (tp_id=%u, PID=0x%x)\n",
                                           i, tp_id, pPid_param->PID);
                                continue;
                        }

                        /* double check section negative filter, this operation is must */
                        /* because if there are several section filters linked in same PID filter, */
                        /* hardware did not tell which section filter is matched */
                        if ((pSec->negative_filter_en) &&
                            (MaskMemCmp(pData, pSec->sec_api_setting.NegVal, pSec->sec_api_setting.NegMsk, 10) == 0)) {
                                TP_VERBOSE("SEC[%d] DeliverSectionData failed, check Negative mask failed (tp_id=%u, PID=0x%x)\n",
                                           i, tp_id, pPid_param->PID);
                                continue;
                        }

                        /* call Request_buf to get section deliver buffer */
                        get_buf_idx = pSec->sec_api_setting.Request_buf(pSec->sec_api_setting.pContext, &pDeliver_Sec_buf, pPid_sec->sec_data_cnt);
                        if((get_buf_idx < 0) || (pDeliver_Sec_buf == NULL)) {
                                UINT32 time_cnt;
                                struct timeval new_time;
                                static UINT8 first = 1;
                                static struct timeval saved_time;

                                if (first) {
                                        TP_WARNING("SEC[%d] get section deliver buffer failed, skip to deliver this section(tp_id=%u, PID=0x%x)\n",
                                                   i, tp_id, pPid_param->PID);

                                        do_gettimeofday(&saved_time);
                                        first = 0;
                                }

                                do_gettimeofday(&new_time);

                                /* get time counter in m-second */
                                time_cnt = (new_time.tv_sec >= saved_time.tv_sec) ?
                                           ((new_time.tv_sec - saved_time.tv_sec) * 1000) :
                                           ((new_time.tv_sec + (0xffffffff - saved_time.tv_sec)) * 1000);
                                time_cnt += ((new_time.tv_usec - saved_time.tv_usec) / 1000);

                                if(time_cnt >= debug_log_interval_ms) {
                                        TP_WARNING("SEC[%d] get section deliver buffer failed, skip to deliver this section(tp_id=%u, PID=0x%x)\n",
                                                   i, tp_id, pPid_param->PID);

                                        saved_time = new_time;
                                }

                                continue;
                        }
                        memcpy(pDeliver_Sec_buf, pData, ( __kernel_size_t)pPid_sec->sec_data_cnt);

                        /* call Complete function to deliver section data */
                        sec_data.pid     = pPid_param->PID;
                        sec_data.p_data  = pDeliver_Sec_buf;
                        sec_data.buf_idx = get_buf_idx;
                        sec_data.len     = pPid_sec->sec_data_cnt;
                        sec_data.crc_err = crc_err;

                        pSec->sec_api_setting.Complete(pSec->sec_api_setting.pContext, &sec_data);
                        pSec->sec_deliver_cnt++;

                        if(pSec->sec_api_setting.toggle_mode_en)
                                pSec->toggle_rec = pData[0] & 0x1;

#if 0
                        if(tp_log_onoff && sec_deliver_log_en) {
                                TP_DBG("TP%u PID=0x%x deliver section data success (len=%u,crc_err=%u)\n",
                                       tp_id, pPid_param->PID, pPid_sec->sec_data_cnt, crc_err);
                                if(sec_deliver_log_en > 1) {
                                        dump_sec_len = (sec_deliver_max_data_cnt > pPid_sec->sec_data_cnt) ?
                                                       pPid_sec->sec_data_cnt : sec_deliver_max_data_cnt;
                                        dump_mem(pData, dump_sec_len);
                                }
                        }
#endif
                }
        }

        pPid_sec->sec_data_cnt   = 0;
        pPid_sec->sec_expect_len = 0;
        return TPK_SUCCESS;

SECTION_ERROR:

        /* pPid_sec->sec_data_cnt=0; */
        /* pPid_sec->sec_expect_len=0; */
        return result;

}

void Tp_Section_assemble(TPK_TP_ENGINE_T tp_id)
{
        INT32 result, result1, deliver_sec_result;
        UINT8 *pRingBufPhy, *pRingBuf, *pInfoBufPhy, *pInfoBuf;
        UINT32 RingBufCnt, InfoBufCnt;
        UINT32 Ring_process_cnt, Info_process_cnt;
        SEC_INFO_T sec_info;
        TPK_TP_PID_SEC_PARAM_T *pPid_Sec;
        UINT8 *buf;

        CHECK_MAX_TP_COUNT_RT_VOID(tp_id);
        CHECK_TP_STRUCTURE_RT_VOID();

        /* if there is no section filter or section assemble thread is stopped, exit this function */
        if((pTp_drv->sec_asm_start == 0) || (pTp_drv->tp[tp_id].tp_stream_status != TP_STREAM_START))
                return;

        _tp_lock();
        /* 1. get section data */
        result = TP_ReadData(tp_id, &pRingBufPhy, &RingBufCnt, pTp_drv->tp[tp_id].mass_buffer.bock_size, TP_BUFFER_SECTION);

        /* 2. get info pack data */
        result1 = TP_ReadData(tp_id, &pInfoBufPhy, &InfoBufCnt, INFO_PACK_BUFFER_BLOCK_SIZE, TP_BUFFER_INFO_PACK);
        _tp_unlock();

        /* if((result == TPK_SUCCESS) && (result1 != TPK_SUCCESS)) */
        if( CHECK_RD_BUF_STATUS(result) && CHECK_RD_BUF_STATUS_ERR(result1)) {
                /* release section buffer if can not get info pack buffer, this is normal case */
                TP_VERBOSE("TP%u get info buffer fail, release section buffer and exit (sec_rt=%d,info_rt=%d)\n", tp_id, result, result1);

                _tp_lock();
                TP_ReleaseData(tp_id, pRingBufPhy, RingBufCnt, TP_BUFFER_SECTION);
                _tp_unlock();
                return;
        }
        /* else if((result1 == TPK_SUCCESS) && (result != TPK_SUCCESS)) */
        else if( CHECK_RD_BUF_STATUS_ERR(result) && CHECK_RD_BUF_STATUS(result1)) {
                if ( result == TPK_BUFFER_EMPTY )
                        ; /* do nothing */
                else {
                        /* release info buffer if can not get section buffer, this is unnormal case */
                        TP_WARNING("TP%u get section buffer fail (%d), release info buffer and exit (info_addr=%p, len=%u) (sec_rt=%d,info_rt=%d)\n",
                                   tp_id, result, pInfoBufPhy, InfoBufCnt, result, result1);

                        _tp_lock();
                        TP_ReleaseData(tp_id, pInfoBufPhy, InfoBufCnt, TP_BUFFER_INFO_PACK);
                        _tp_unlock();
                }
                return;
        }
        /* else if((result != TPK_SUCCESS) && (result1 != TPK_SUCCESS)) */
        else if( CHECK_RD_BUF_STATUS_ERR(result) && CHECK_RD_BUF_STATUS_ERR(result1)) {
                /* get nothing from section and info buffer, it is normal case */
                TP_VERBOSE("TP%u get section & info buffer fail, just exit (sec_rt=%d,info_rt=%d)\n",
                           tp_id, result, result1);
                return;
        }

        /* 3. translate phy addr to virtual addr */
        pRingBuf = Tp_Buf_Phy_to_Vir(tp_id, TP_BUFFER_SECTION, pRingBufPhy);
        if(pRingBuf == NULL) {
                TP_WARNING("TP%u translate phycal section addr to virtual failed\n", tp_id);

                _tp_lock();
                TP_ReleaseData(tp_id, pRingBufPhy, RingBufCnt, TP_BUFFER_SECTION);
                TP_ReleaseData(tp_id, pInfoBufPhy, InfoBufCnt, TP_BUFFER_INFO_PACK);
                _tp_unlock();
                return;
        }

        pInfoBuf = Tp_Buf_Phy_to_Vir(tp_id, TP_BUFFER_INFO_PACK, pInfoBufPhy);
        if(pInfoBuf == NULL) {
                TP_WARNING("TP%u translate phycal info pack addr to virtual failed\n", tp_id);

                _tp_lock();
                TP_ReleaseData(tp_id, pRingBufPhy, RingBufCnt, TP_BUFFER_SECTION);
                TP_ReleaseData(tp_id, pInfoBufPhy, InfoBufCnt, TP_BUFFER_INFO_PACK);
                _tp_unlock();
                return;
        }

        /* parsing every info pack */
        Ring_process_cnt = 0;
        for(Info_process_cnt = 0 ; Info_process_cnt < InfoBufCnt; Info_process_cnt += INFO_PACK_BUFFER_BLOCK_SIZE) {
                if(pTp_drv->sec_asm_start == 0) {
                        Info_process_cnt = InfoBufCnt;
                        Ring_process_cnt = RingBufCnt;
                        break;
                }

                /* if parse info pack error, skip this info pack */
                result = Tp_ParseInfoPack(tp_id, (pInfoBuf + Info_process_cnt), &sec_info);
                if(result == TPK_NOT_SUPPORT) {
                        continue;
                } else if(result != TPK_SUCCESS) {
                        /* something wrong, skip this section data and info pack data */
                        TP_WARNING("TP%u call Tp_ParseInfoPack failed\n", tp_id);
                        Info_process_cnt = InfoBufCnt;
                        Ring_process_cnt = RingBufCnt;
                        break;
                }

                /* if info buffer over section buffer range, skip parsing and release all section data */
                /* and release info buffer which has been processed (but not include this time) */
                if((sec_info.pointer_phy <  ((UADDRESS)pRingBufPhy + Ring_process_cnt)) ||
                    (sec_info.pointer_phy >= ((UADDRESS)pRingBufPhy + RingBufCnt)) ||
                    (sec_info.tsp_hdr_phy <  ((UADDRESS)pRingBufPhy + Ring_process_cnt)) ||
                    (sec_info.tsp_hdr_phy >= ((UADDRESS)pRingBufPhy + RingBufCnt))) {
                        Ring_process_cnt = RingBufCnt;
                        break;
                }

                pPid_Sec = &pTp_drv->tp_pid[tp_id].pid_sec[sec_info.pid_idx];

                /* section filter may be removed before we parsing this info pack, just skip this info pack */
                if(pPid_Sec->pid_sec_cnt == 0) {
                        TP_INFO("There is no section filter attahed in this pid filter, just skip this info pack(tp_id=%u, pid_idx=%u, PID=0x%x)\n",
                                tp_id, sec_info.pid_idx, sec_info.PID);
                        Ring_process_cnt = sec_info.tsp_hdr_phy - (UADDRESS)pRingBufPhy;
                        continue;
                }
                /* there maybe something wrong, because pPid_Sec->pSec_buf is NULL point */
                if(pPid_Sec->pSec_buf == NULL) {
                        TP_WARNING("Section buffer not init yet !! just skip this info pack(tp_id=%u, pid_idx=%u, PID=0x%x)\n",
                                   tp_id, sec_info.pid_idx, sec_info.PID);
                        Ring_process_cnt = sec_info.tsp_hdr_phy - (UADDRESS)pRingBufPhy;
                        continue;
                }

                if(sec_info.header_status) {
                        /* if there is still data left in the section buffer of PID, just clean it */
                        /* this may happend if section filter or pid filter is removed and added frequently. */
                        if((pPid_Sec->sec_data_cnt) || (pPid_Sec->sec_expect_len)) {
                                RESET_SECTION_ASSEMBLE_BUF(pPid_Sec);
                                if(pTp_drv->tp[tp_id].errPktDiff < 20) {
                                        TP_WARNING_DEBUG_LEVEL("incomplete section data detected, ignore it(tp_id=%u, pid_idx=%u, PID=0x%x)\n",
                                                               tp_id, sec_info.pid_idx, sec_info.PID);
                                }
                        }

                        /* this section hdr can not pass section filter, just skip this info pack */
                        if(sec_info.header_status & HEADER_STATUS_NOT_PASS_SECTION_FILTERING) {
                                Ring_process_cnt = sec_info.tsp_hdr_phy - (UADDRESS)pRingBufPhy;
                                continue;
                        }
                } else {
                        /* if collected section length is more than 4096 bytes, reset section buffer and skip this section info */
                        if((pPid_Sec->sec_data_cnt + (UINT16)sec_info.section_length) > SECTION_BUFFER_SIZE) {
                                if(pTp_drv->tp[tp_id].errPktDiff < 20) {
                                        TP_WARNING("section data collect error, data length is more than 4096 bytes (len=%u, tp_id=%u, pid_idx=%u, PID=0x%x)\n",
                                                   (pPid_Sec->sec_data_cnt + (UINT16)sec_info.section_length), tp_id, sec_info.pid_idx, sec_info.PID );
                                }
                                RESET_SECTION_ASSEMBLE_BUF(pPid_Sec);
                                Ring_process_cnt = sec_info.tsp_hdr_phy - (UADDRESS)pRingBufPhy;
                                continue;
                        }
                }

                /* copy data into section buffer of PID filter */
                /* (for "case 1: hdr=1, tail=1" and "case 2: hdr=1, tail=0") */
                /* (for "case 3: hdr=0, tail=0" and "case 4: hdr=0, tail=1") */
                memcpy((UINT8*)(pPid_Sec->pSec_buf + pPid_Sec->sec_data_cnt), (UINT8*)sec_info.pointer_vir, sec_info.section_length);
                pPid_Sec->sec_data_cnt += (UINT16)sec_info.section_length;
                if(pPid_Sec->sec_expect_len == 0) {
                        pPid_Sec->sec_expect_len = (pPid_Sec->sec_data_cnt >= 3) ?
                                                   ((((pPid_Sec->pSec_buf[1] << 8) + pPid_Sec->pSec_buf[2]) & 0xFFF) + 3) : 0 ;
                }

                /* if this sec_info is tail, just deliver it */
                if(sec_info.tail_status) {
                        /* case 1: hdr=1, tail=1 */
                        /* case 4: hdr=0, tail=1 */
                        if((sec_info.tail_status & TAIL_STATUS_TEI_ERR) ) {
                                /* TEI error, ignore it */
                                TP_WARNING_DEBUG_LEVEL("TP%u PID=0x%x, pid_idx=%u, skip deliver sec data in TEI packet\n",
                                                       tp_id, sec_info.PID, sec_info.pid_idx);
                        } else {
                                if((sec_info.tail_status & TAIL_STATUS_CRC_STATUS) == TAIL_STATUS_CRC_STATUS_SECTION_TRUNCATED) {
                                        TP_WARNING_DEBUG_LEVEL("TP%u PID=0x%x, pid_idx=%u, skip deliver truncated sec data\n",
                                                               tp_id, sec_info.PID, sec_info.pid_idx);
                                } else {
                                        _tp_lock();
                                        /* if tail status != TAIL_STATUS_END_SEEN, there is CRC error */
                                        deliver_sec_result = Tp_DeliverSectionData(tp_id,
                                                             sec_info.pid_idx,
                                                             ((sec_info.tail_status & TAIL_STATUS_CRC_STATUS) != TAIL_STATUS_CRC_STATUS_NO_ERR) ? SEC_CRC_ERR : SEC_CRC_CORRECT);
                                        _tp_unlock();
                                        if(deliver_sec_result != TPK_SUCCESS) {
                                                buf = (UINT8*)sec_info.pointer_vir;
                                                TP_WARNING_DEBUG_LEVEL("TP%u PID=0x%x, pid_idx=%u, deliver section failed, hdr=0x%x, tail=0x%x, sec_cnt=%u, sec_sub_cnt=%u, sec_buf:{%x %x %x}, sec_sub_buf:{%x %x %x},sec_sub_point:0x%x,C/N:%x/%x\n",
                                                                       tp_id, sec_info.PID, sec_info.pid_idx,
                                                                       sec_info.header_status, sec_info.tail_status,
                                                                       pPid_Sec->sec_data_cnt, sec_info.section_length,
                                                                       pPid_Sec->pSec_buf[0], pPid_Sec->pSec_buf[1], pPid_Sec->pSec_buf[2],
                                                                       buf[0], buf[1], buf[2], sec_info.pointer_phy,
                                                                       Info_process_cnt / INFO_PACK_BUFFER_BLOCK_SIZE, InfoBufCnt / INFO_PACK_BUFFER_BLOCK_SIZE
                                                                      );
#if 0
                                                buf = (UINT8*)sec_info.tsp_hdr_vir;
                                                TP_WARNING("TSP : {%x %x %x %x %x %x}, tsp_phy=0x%x, tsp_vir=0x%x, pointer_phy=0x%x, pointer_vir=0x%x\n",
                                                           buf[0], buf[1], buf[2], buf[3], buf[4], buf[5],
                                                           sec_info.tsp_hdr_phy, sec_info.tsp_hdr_vir,
                                                           sec_info.pointer_phy, sec_info.pointer_vir);
#endif
                                        }
                                }
                        }
                        RESET_SECTION_ASSEMBLE_BUF(pPid_Sec);
                }

                /* if sec_data_cnt >=sec_expect_len, caculate CRC by software and deliver section by software */
                if((pPid_Sec->sec_data_cnt >= pPid_Sec->sec_expect_len) &&
                    (pPid_Sec->sec_expect_len != 0)) {
                        TP_WARNING("sec_data(%u) is more than sec_expect(%u), maybe hardware error, deliver section(tp_id=%u, pid_idx=%u, PID=0x%x)\n",
                                   pPid_Sec->sec_data_cnt, pPid_Sec->sec_expect_len, tp_id, sec_info.pid_idx, sec_info.PID);

                        _tp_lock();
                        deliver_sec_result = Tp_DeliverSectionData(tp_id, sec_info.pid_idx,     SEC_NO_CRC_CHECK);
                        _tp_unlock();
                        RESET_SECTION_ASSEMBLE_BUF(pPid_Sec);
                }

                Ring_process_cnt = sec_info.tsp_hdr_phy - (UADDRESS)pRingBufPhy;
        }

        if((Info_process_cnt > InfoBufCnt) || (Ring_process_cnt > RingBufCnt)) {
                TP_WARNING("released buffer size too big (Info_process_cnt=%u, Ring_process_cnt=%u)\n",
                           Info_process_cnt, Ring_process_cnt);
                Info_process_cnt = InfoBufCnt;
                Ring_process_cnt = RingBufCnt;
        }

        _tp_lock();
        TP_ReleaseData(tp_id, pInfoBufPhy, Info_process_cnt, TP_BUFFER_INFO_PACK);
        TP_ReleaseData(tp_id, pRingBufPhy, Ring_process_cnt, TP_BUFFER_SECTION);
        _tp_unlock();

}

#if 0
static void TP_SetThreadSchedulingRealTimePriority(int priority)
{
        struct sched_param param = { .sched_priority = priority };
        sched_setscheduler(current, SCHED_FIFO, &param);
}
#endif

#if 0
static INT32 section_assemble_thread(void* arg)
{
        UINT8 i, ring_buf_idx, info_buf_idx, startcode_buf_idx;
        TP_BUFFER_PARAM_T ring_buf, info_buf, startcode_buf;
        UINT32 ring_buf_cnt, ring_buf_sz, info_buf_cnt, info_buf_sz, startcode_buf_cnt, startcode_buf_sz;
        wait_queue_head_t timeout_wq;
        UINT32 time_cnt, time_cnt_2;
        UINT64 pkt = 0, dropPkt = 0, errPkt = 0, pktDiff = 0, dropPktDiff = 0, errPktDiff = 0, errPktDiff_1s = 0, pktDiff_1s = 0, dropPktDiff_1s = 0;
        UINT64 lastPkt[MAX_TP_COUNT], lastDropPkt[MAX_TP_COUNT], lastErrPkt[MAX_TP_COUNT];
        UINT32 valid_pid_filter_count = 0;
        BOOL valid_pid_filter_count_log_flag[MAX_TP_COUNT] = {0, 0, 0, 0}, pktdrpcnt_no_inc_logflag[MAX_TP_COUNT] = {0, 0, 0, 0}, errcnt_inc_logflag[MAX_TP_COUNT] = {0, 0, 0, 0};
        BOOL tp_live_noflowrate_print_flag[MAX_TP_COUNT] = {0, 0, 0, 0}, tp_low_rate_print_flag[MAX_TP_COUNT] = {0, 0, 0, 0}, tp_buff_usage_print_flag[MAX_TP_COUNT] = {0, 0, 0, 0};
        UINT32 tp_live_flowrate;
        UINT32 tp_tf_int_reg_addr, tp_tf_cntl_reg_addr;
        tp_tp_tf0_int_RBUS tp_tf_int_reg;
        tp_tp_tf0_cntl_RBUS tp_tf_cntl_reg;

        struct timeval saved_time, saved_time_2, new_time;

        //TP_SetThreadSchedulingRealTimePriority(99);
        /* init value */
        for ( i = 0; i < MAX_TP_COUNT; i++) {
                lastPkt[i]     = 0;
                lastDropPkt[i] = 0;
                lastErrPkt[i]  = 0;
        }
        pktDiff_dbg.pkt = 0;
        pktDiff_dbg.droppedPkt = 0;
        pktDiff_dbg.errorPkt = 0;

        TP_INFO("enter section assemble thread\n");

        do_gettimeofday(&saved_time);
        memcpy(&saved_time_2, &saved_time, sizeof(struct timeval));
        init_waitqueue_head(&timeout_wq);

        current->flags &= ~PF_NOFREEZE;

        while(!kthread_should_stop()) {
                do_gettimeofday(&new_time);

                for( i = 0; i < MAX_TP_COUNT; i++) {

                        /* update PCR tracking status */
                        _tp_lock();
                        Tp_UpdatePCRTrackingStatus(i);
                        _tp_unlock();

                        Tp_Section_assemble(i);

                        /* get time counter in m-second(10^3) for debug_log_interval_ms */
                        time_cnt = (new_time.tv_sec >= saved_time.tv_sec) ?
                                   ((new_time.tv_sec - saved_time.tv_sec) * 1000) :
                                   ((new_time.tv_sec + (0xffffffff - saved_time.tv_sec)) * 1000);
                        time_cnt += ((new_time.tv_usec - saved_time.tv_usec) / 1000);
                        /* get time counter in m-second(10^3) for immediate log */
                        time_cnt_2 = (new_time.tv_sec >= saved_time_2.tv_sec) ?
                                     ((new_time.tv_sec - saved_time_2.tv_sec) * 1000) :
                                     ((new_time.tv_sec + (0xffffffff - saved_time_2.tv_sec)) * 1000);
                        time_cnt_2 += ((new_time.tv_usec - saved_time_2.tv_usec) / 1000);

                        /* TP HW reset in overflow and busy */
                        if(time_cnt >= debug_log_interval_ms) {
                                switch(i) {
                                        case TP_TP0:
                                                tp_tf_int_reg_addr  = TP_TP_TF0_INT_reg;
                                                tp_tf_cntl_reg_addr = TP_TP_TF0_CNTL_reg;
                                                break;
                                        case TP_TP1:
                                                tp_tf_int_reg_addr = TP_TP_TF1_INT_reg;
                                                tp_tf_cntl_reg_addr = TP_TP_TF1_CNTL_reg;
                                                break;
                                        case TP_TP2:
                                                tp_tf_int_reg_addr = TP_TP_TF2_INT_reg;
                                                tp_tf_cntl_reg_addr = TP_TP_TF2_CNTL_reg;
                                                break;
                                        case TP_TP3:
                                                tp_tf_int_reg_addr = TP_TP_TF3_INT_reg;
                                                tp_tf_cntl_reg_addr = TP_TP_TF3_CNTL_reg;
                                                break;
                                        default:
                                                tp_tf_int_reg_addr = TP_TP_TF0_INT_reg;
                                                tp_tf_cntl_reg_addr = TP_TP_TF0_CNTL_reg;
                                                break;
                                }

                                tp_tf_int_reg.regValue  = READ_REG32(tp_tf_int_reg_addr);
                                tp_tf_cntl_reg.regValue = READ_REG32(tp_tf_cntl_reg_addr);
                                if(tp_tf_int_reg.overflow == 1 && tp_tf_cntl_reg.busy == 1) {
                                        RHAL_SetTPHardwareReset(1);
                                }
                        }

                        if (time_cnt_2 >= status_log_interval_ms && (pTp_drv->tp[i].tp_stream_status == TP_STREAM_START)) {
                                pkt     = 0;
                                dropPkt = 0;
                                errPkt  = 0;

                                Tp_TrackErrorPacket(i, &pkt, &dropPkt, &errPkt);

                                pktDiff_1s     = pkt - lastPkt[i];
                                dropPktDiff_1s = dropPkt - lastDropPkt[i];
                                errPktDiff_1s  = errPkt - lastErrPkt[i];

                                pktDiff     += pktDiff_1s;
                                dropPktDiff += dropPktDiff_1s;
                                errPktDiff  += errPktDiff_1s;

                                lastPkt[i]     = pkt;
                                lastDropPkt[i] = dropPkt;
                                lastErrPkt[i]  = errPkt;
                        }

                        /* log printing with print time interval */
                        if( tp_log_onoff && (time_cnt >= debug_log_interval_ms) && (pTp_drv->tp[i].tp_stream_status == TP_STREAM_START) ) {
                                /* 1. display TP count packet */
                                valid_pid_filter_count = Tp_Get_Valid_Pid_Cnt(i, 1);
                                /* have pid and sec filter */
                                if(valid_pid_filter_count > 0) {
                                        if (valid_pid_filter_count_log_flag[i]) {
                                                TP_DBG_SIMPLE("TP%u have valid pid or section filter!\n", i);
                                                valid_pid_filter_count_log_flag[i] = 0;
                                        }
                                        /* 1.1 display TP packet/drop/error count in abnormal case */
                                        /* case1: when error counter increase 10/s up, */
                                        /* case2: when nothing is increased for "packet" counter and "drop" counter */
                                        /* TP driver should print this info in kernel side */
                                        if(errPktDiff >= 20) {
                                                if ( errcnt_inc_logflag[i] == 0 ) {
                                                        TP_DBG_SIMPLE( "Warning, TP%u error count increase! If cause broken screen, please check Demod status! pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n",
                                                                       i, pkt, pktDiff, dropPkt, dropPktDiff, errPkt, errPktDiff, (pktDiff - dropPktDiff));
                                                        errcnt_inc_logflag[i] = 1;
                                                }
                                        } else {
                                                if(errcnt_inc_logflag[i]) {
                                                        TP_DBG_SIMPLE("TP%u error count normally! pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n",
                                                                      i, pkt, pktDiff, dropPkt, dropPktDiff, errPkt, errPktDiff, (pktDiff - dropPktDiff));
                                                        errcnt_inc_logflag[i] = 0;
                                                }
                                        }

                                        if( pktDiff == 0 && dropPktDiff == 0) {
                                                if ( pktdrpcnt_no_inc_logflag[i] == 0 ) {
                                                        TP_DBG_SIMPLE( "Warning, TP%u pkt and drop cnt no increase - pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n",
                                                                       i, pkt, pktDiff, dropPkt, dropPktDiff, errPkt, errPktDiff, (pktDiff - dropPktDiff));
                                                        pktdrpcnt_no_inc_logflag[i] = 1;
                                                }
                                        } else {
                                                if(pktdrpcnt_no_inc_logflag[i]) {
                                                        TP_DBG_SIMPLE("TP%u packet and drop cnt normally! pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n",
                                                                      i, pkt, pktDiff, dropPkt, dropPktDiff, errPkt, errPktDiff, (pktDiff - dropPktDiff));
                                                        pktdrpcnt_no_inc_logflag[i] = 0;
                                                }
                                        }

                                        /* 1.2 display TP count packet print regularly */
                                        tp_mask_print_emerg( TP_LOG_BLOCK_CNT, TP_LOG_LEVEL_DEBUG, "TP%u, pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n", i, pkt, pktDiff, dropPkt, dropPktDiff, errPkt, errPktDiff, (pktDiff - dropPktDiff));
                                } else if (valid_pid_filter_count == 0 ) {
                                        if ( valid_pid_filter_count_log_flag[i] == 0 ) {
                                                TP_WARNING("TP%u No valid pid & section filter!\n", i);
                                                valid_pid_filter_count_log_flag[i] = 1;
                                        }
                                } else {
                                        TP_ERROR("Unknow pid filter count: %d\n", valid_pid_filter_count);
                                }

                                /* 2. display buffer status */
                                /* 2.1 display MTP buffer status */
                                if (pTp_drv->mtp[i].mtp_stream_status == MTP_STREAM_START) {
                                        _tp_lock();
                                        Tp_Get_MTP_Buffer(i, &ring_buf);
                                        _tp_unlock();

                                        ring_buf_cnt = (ring_buf.WP >= ring_buf.RP) ?
                                                       (ring_buf.WP - ring_buf.RP) :
                                                       ((ring_buf.Limit - ring_buf.RP) + (ring_buf.WP - ring_buf.Base));
                                        ring_buf_sz = ring_buf.Limit - ring_buf.Base;

                                        TP_DBG_SIMPLE("TP%u_MTP : ring_rate=%u KB/s, ring=%u/%u (R=0x%x, W=0x%x, B=0x%x, L=0x%x)\n",
                                                      i ,
                                                      (pTp_drv->mtp[i].mtp_write_data_cnt / time_cnt),
                                                      ring_buf_cnt, ring_buf_sz,
                                                      ring_buf.RP, ring_buf.WP, ring_buf.Base, ring_buf.Limit);

                                        pTp_drv->mtp[i].mtp_write_data_cnt = 0;
                                }

                                /* 2.2 display TP buffer status */
                                /* 2.2.1 print mass & info buffer status by enable buffer log */

                                {
                                        switch(i) {
                                                case TP_TP0:
                                                        ring_buf_idx = TP0_BUFFER_MASS_DATA;
                                                        info_buf_idx = TP0_BUFFER_INFO_PACK;
                                                        startcode_buf_idx = TP0_START_CODE_PACK;
                                                        break;
                                                case TP_TP1:
                                                        ring_buf_idx = TP1_BUFFER_MASS_DATA;
                                                        info_buf_idx = TP1_BUFFER_INFO_PACK;
                                                        startcode_buf_idx = TP1_START_CODE_PACK;
                                                        break;
                                                case TP_TP2:
                                                        ring_buf_idx = TP2_BUFFER_MASS_DATA;
                                                        info_buf_idx = TP2_BUFFER_INFO_PACK;
                                                        break;
                                                case TP_TP3:
                                                        ring_buf_idx = TP3_BUFFER_MASS_DATA;
                                                        info_buf_idx = TP3_BUFFER_INFO_PACK;
                                                        break;
                                                default:
                                                        ring_buf_idx = TP0_BUFFER_MASS_DATA;
                                                        info_buf_idx = TP0_BUFFER_INFO_PACK;
                                                        break;
                                        }

                                        _tp_lock();
                                        Tp_Get_Buffer(ring_buf_idx, &ring_buf);
                                        Tp_Get_Buffer(info_buf_idx, &info_buf);

                                        if(Tp_is_SupportPatternSearch(i) == TPK_SUCCESS)
                                                Tp_Get_Buffer(startcode_buf_idx, &startcode_buf);
                                        else
                                                startcode_buf.Base = startcode_buf.Limit = startcode_buf.RP = startcode_buf.WP = 0;
                                        _tp_unlock();

                                        ring_buf_cnt = (ring_buf.WP >= ring_buf.RP) ?
                                                       (ring_buf.WP - ring_buf.RP) :
                                                       ((ring_buf.Limit - ring_buf.RP) + (ring_buf.WP - ring_buf.Base));
                                        ring_buf_sz = ring_buf.Limit - ring_buf.Base;

                                        info_buf_cnt = (info_buf.WP >= info_buf.RP) ?
                                                       (info_buf.WP - info_buf.RP) :
                                                       ((info_buf.Limit - info_buf.RP) + (info_buf.WP - info_buf.Base));
                                        info_buf_sz = info_buf.Limit - info_buf.Base;

                                        startcode_buf_cnt = (startcode_buf.WP >= startcode_buf.RP) ?
                                                            (startcode_buf.WP - startcode_buf.RP) :
                                                            ((startcode_buf.Limit - startcode_buf.RP) + (startcode_buf.WP - startcode_buf.Base));
                                        startcode_buf_sz = startcode_buf.Limit - startcode_buf.Base;

                                        tp_live_flowrate = (UINT32)((pktDiff - dropPktDiff) * pTp_drv->tp[i].mass_buffer.bock_size);
                                        pTp_drv->tp_pid[i].ringrate_KB = pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt;

                                        if ( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_BUFFER) ) {
                                                if ( tp_live_flowrate / time_cnt == 0 ) {
                                                        TP_DBG_SIMPLE("TP%u: LR=%uKB/s(%u/%u), RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                      i, (tp_live_flowrate / time_cnt), tp_live_flowrate, time_cnt,
                                                                      (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt),
                                                                      ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt / 1000));
                                                } else {
                                                        TP_DBG_SIMPLE("TP%u: LR=%uKB/s, RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                      i, (tp_live_flowrate / time_cnt), (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt),
                                                                      ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt / 1000));
                                                }

                                                TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);
                                        }


                                        pTp_drv->tp_pid[i].tp_mass_data_release_cnt = 0;
                                        pTp_drv->tp_pid[i].pcr.pcr_irq_cnt = 0;
                                }

                                /* 2.2.2 print pattern buffer status */
                                if ( startcode_buf_sz && pTp_drv->tp[i].Shared_RWPtr.inited ) {
                                        UADDRESS *pattern_rp_virtual;
                                        UADDRESS *pattern_wp_virtual;
                                        UADDRESS *mass_phy_of_pattern_rp;
                                        UADDRESS *mass_phy_of_pattern_wp;

                                        pattern_rp_virtual = (UADDRESS *)(pTp_drv->tp[i].start_code_search_buffer.BaseVir + (startcode_buf.RP - pTp_drv->tp[i].start_code_search_buffer.BasePhy));
                                        pattern_wp_virtual = (UADDRESS *)(pTp_drv->tp[i].start_code_search_buffer.BaseVir + (startcode_buf.WP - pTp_drv->tp[i].start_code_search_buffer.BasePhy));

                                        if(pattern_wp_virtual == (UADDRESS *)(pTp_drv->tp[i].start_code_search_buffer.BaseVir))
                                                pattern_wp_virtual = (UADDRESS *)pTp_drv->tp[i].start_code_search_buffer.LimitVir;
                                        pattern_wp_virtual = pattern_wp_virtual - 8;

                                        mass_phy_of_pattern_rp = (UADDRESS *)(pattern_rp_virtual[0] << 24 | pattern_rp_virtual[1] << 16 | pattern_rp_virtual[2] << 8 | pattern_rp_virtual[3]);
                                        mass_phy_of_pattern_wp = (UADDRESS *)(pattern_wp_virtual[0] << 24 | pattern_wp_virtual[1] << 16 | pattern_wp_virtual[2] << 8 | pattern_wp_virtual[3]);

                                        TP_DBG_SIMPLE("TP%u: pattern=%u/%u (%x(%x)/%x(%x)/%x/%x) pvr=%x/%x\n",
                                                      i ,
                                                      startcode_buf_cnt, startcode_buf_sz,
                                                      startcode_buf.RP, mass_phy_of_pattern_rp, startcode_buf.WP, mass_phy_of_pattern_wp, startcode_buf.Base, startcode_buf.Limit,
                                                      (UINT32)*pTp_drv->tp[i].Shared_RWPtr.pRP, (UINT32)*pTp_drv->tp[i].Shared_RWPtr.pWP);
                                }


#if 0
                                /* 3. display PID filter list */
                                if(tp_log_onoff && (pid_log_en == 2)) {
                                        switch(i) {
                                                case TP_TP0:
                                                        max_pid_cnt = TP0_PID_FILTER_COUNT;
                                                        break;
                                                case TP_TP1:
                                                        max_pid_cnt = TP1_PID_FILTER_COUNT;
                                                        break;
                                                case TP_TP2:
                                                        max_pid_cnt = TP2_PID_FILTER_COUNT;
                                                        break;
                                                case TP_TP3:
                                                        max_pid_cnt = TP3_PID_FILTER_COUNT;
                                                        break;
                                                default:
                                                        max_pid_cnt = TP0_PID_FILTER_COUNT;
                                                        break;
                                        }

                                        _tp_lock();
                                        for( j = 0; j < max_pid_cnt; j++) {
                                                Tp_Dump_PID_filter_Status(i, j);
                                        }
                                        _tp_unlock();
                                }
#endif

                                /* 4. display tp src */
                                tp_mask_print_emerg( TP_LOG_BLOCK_FRAMER, TP_LOG_LEVEL_DEBUG, "TP%u, tp_src=%d, tpout_src=%d\n",
                                                     i,
                                                     pTp_drv->tp[i].tp_src,
                                                     pTp_drv->tpout[0].tpout_src);
                        }

                        /* log printing with print time interval 1s */
                        if( (time_cnt_2 >= status_log_interval_ms) && pTp_drv->tp[i].tp_stream_status == TP_STREAM_START ) {
                                if ( !CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_BUFFER) && (i != TP_TP3) ) {
                                        /* display TP buffer status */
                                        switch(i) {
                                                case TP_TP0:
                                                        ring_buf_idx = TP0_BUFFER_MASS_DATA;
                                                        info_buf_idx = TP0_BUFFER_INFO_PACK;
                                                        startcode_buf_idx = TP0_START_CODE_PACK;
                                                        break;
                                                case TP_TP1:
                                                        ring_buf_idx = TP1_BUFFER_MASS_DATA;
                                                        info_buf_idx = TP1_BUFFER_INFO_PACK;
                                                        startcode_buf_idx = TP1_START_CODE_PACK;
                                                        break;
                                                case TP_TP2:
                                                        ring_buf_idx = TP2_BUFFER_MASS_DATA;
                                                        info_buf_idx = TP2_BUFFER_INFO_PACK;
                                                        break;
                                                case TP_TP3:
                                                        ring_buf_idx = TP3_BUFFER_MASS_DATA;
                                                        info_buf_idx = TP3_BUFFER_INFO_PACK;
                                                        break;
                                                default:
                                                        ring_buf_idx = TP0_BUFFER_MASS_DATA;
                                                        info_buf_idx = TP0_BUFFER_INFO_PACK;
                                                        break;
                                        }

                                        _tp_lock();
                                        Tp_Get_Buffer(ring_buf_idx, &ring_buf);
                                        Tp_Get_Buffer(info_buf_idx, &info_buf);

                                        if(Tp_is_SupportPatternSearch(i) == TPK_SUCCESS)
                                                Tp_Get_Buffer(startcode_buf_idx, &startcode_buf);
                                        else
                                                startcode_buf.Base = startcode_buf.Limit = startcode_buf.RP = startcode_buf.WP = 0;
                                        _tp_unlock();

                                        ring_buf_cnt = (ring_buf.WP >= ring_buf.RP) ?
                                                       (ring_buf.WP - ring_buf.RP) :
                                                       ((ring_buf.Limit - ring_buf.RP) + (ring_buf.WP - ring_buf.Base));
                                        ring_buf_sz = ring_buf.Limit - ring_buf.Base;

                                        info_buf_cnt = (info_buf.WP >= info_buf.RP) ?
                                                       (info_buf.WP - info_buf.RP) :
                                                       ((info_buf.Limit - info_buf.RP) + (info_buf.WP - info_buf.Base));
                                        info_buf_sz = info_buf.Limit - info_buf.Base;

                                        startcode_buf_cnt = (startcode_buf.WP >= startcode_buf.RP) ?
                                                            (startcode_buf.WP - startcode_buf.RP) :
                                                            ((startcode_buf.Limit - startcode_buf.RP) + (startcode_buf.WP - startcode_buf.Base));
                                        startcode_buf_sz = startcode_buf.Limit - startcode_buf.Base;

                                        tp_live_flowrate = (pktDiff_1s - dropPktDiff_1s) * pTp_drv->tp[i].mass_buffer.bock_size;

                                        if ( tp_live_flowrate == 0 ) {
                                                if ( tp_live_noflowrate_print_flag[i] == 0 ) {
                                                        TP_DBG_SIMPLE("Warning, TP%u no live rate!\n", i);
                                                        TP_DBG_SIMPLE("TP%u: LR=%uKB/s(%u/%u), RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                      i, (tp_live_flowrate / time_cnt_2), tp_live_flowrate, time_cnt_2, (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_2),
                                                                      ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_2 / 1000));
                                                        TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);
                                                }
                                                tp_live_noflowrate_print_flag[i] = 1;
                                        } else {
                                                /* 2.2 no live rate to have live rate */
                                                if ( tp_live_noflowrate_print_flag[i] == 1 ) {
                                                        TP_DBG_SIMPLE("TP%u have live rate!\n", i);
                                                        TP_DBG_SIMPLE("TP%u: LR=%uKB/s(%u/%u), RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                      i,
                                                                      (tp_live_flowrate / time_cnt_2), tp_live_flowrate, time_cnt_2, (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_2),
                                                                      ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_2 / 1000));
                                                        TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);
                                                        tp_live_noflowrate_print_flag[i] = 0;
                                                }
                                                /* 2.3 low live buffer rate or buffer usage is larger than 90% */
                                                else if ( tp_live_flowrate != 0 ) {
                                                        if ( ( Tp_Get_Valid_Pid_Cnt(i, 1) && Tp_Get_Valid_Pid_Cnt(i, 0) == 0 ) &&
                                                             tp_low_rate_print_flag[i] == 0  ) {
                                                                if ((tp_live_flowrate / time_cnt_2) <= 10 ) {
                                                                        TP_DBG_SIMPLE("Warning, TP%u only sec filter!\n", i);
                                                                        TP_DBG_SIMPLE("Warning, TP%u low live rate!\n", i);
                                                                        TP_DBG_SIMPLE("TP%u: LR=%uKB/s(%u/%u), RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                                      i, (tp_live_flowrate / time_cnt_2), tp_live_flowrate, time_cnt_2, (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_2),
                                                                                      ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                                        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_2 / 1000));
                                                                        TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);
                                                                        tp_low_rate_print_flag[i] = 1;
                                                                }
                                                        } else if ( tp_low_rate_print_flag[i] == 0 && (tp_live_flowrate / time_cnt_2) <= 100 ) {
                                                                TP_DBG_SIMPLE("Warning, TP%u low live rate!\n", i);
                                                                TP_DBG_SIMPLE("TP%u: LR=%uKB/s(%u/%u), RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                              i, (tp_live_flowrate / time_cnt_2), tp_live_flowrate, time_cnt_2, (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_2),
                                                                              ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                                tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_2 / 1000));
                                                                TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);
                                                                tp_low_rate_print_flag[i] = 1;
                                                        } else {
                                                                if ( tp_low_rate_print_flag[i] ) {
                                                                        TP_DBG_SIMPLE("TP%u live rate normally!\n", i);
                                                                        TP_DBG_SIMPLE("TP%u: LR=%uKB/s, RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                                      i, (tp_live_flowrate / time_cnt_2), (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_2),
                                                                                      ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                                        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_2 / 1000));
                                                                        TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);
                                                                        tp_low_rate_print_flag[i] = 0;
                                                                }

                                                        }

                                                        if ( tp_buff_usage_print_flag[i] == 0 && ring_buf_cnt >= (ring_buf_sz / 10 * 9)) {
                                                                TP_DBG_SIMPLE("Warning, TP%u buffer usage is larger than 90 percentage!\n", i);
                                                                TP_DBG_SIMPLE("TP%u: LR=%uKB/s, RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                              i, (tp_live_flowrate / time_cnt_2), (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_2),
                                                                              ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                                tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_2 / 1000));
                                                                TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);
                                                                tp_buff_usage_print_flag[i] = 1;
                                                        } else
                                                                tp_buff_usage_print_flag[i] = 0;
                                                }
                                        }

                                        pTp_drv->tp_pid[i].tp_mass_data_release_cnt = 0;
                                        pTp_drv->tp_pid[i].pcr.pcr_irq_cnt = 0;

                                }
                        }
                }

                if(time_cnt >= debug_log_interval_ms) {
                        saved_time = new_time;

                        /* reset pkt diff per interval */
                        pktDiff = 0;
                        dropPktDiff = 0;
                        errPktDiff = 0;
                }

                if ( time_cnt_2 >= status_log_interval_ms ) {
                        memcpy(&saved_time_2, &new_time, sizeof(struct timeval));
                }


                if (freezing(current)) {
                        try_to_freeze();
                }

                /* interruptible_sleep_on_timeout(&timeout_wq, SECTION_ASM_TIMEOUT); */
                wait_event_interruptible_timeout(timeout_wq, 0, SECTION_ASM_TIMEOUT);
        }

        TP_INFO("exit section assemble thread exit\n");

        return 0;
}
#else

static INT32 section_assemble_thread(void* arg)
{
        UINT8 i;
        wait_queue_head_t timeout_wq;
        UINT32 time_cnt, time_cnt_2;
        UINT32 tp_tf_int_reg_addr, tp_tf_cntl_reg_addr;
        tp_tp_tf0_int_RBUS tp_tf_int_reg;
        tp_tp_tf0_cntl_RBUS tp_tf_cntl_reg;

        struct timeval saved_time, new_time;

        TP_INFO("enter section assemble thread\n");

        do_gettimeofday(&saved_time);
        init_waitqueue_head(&timeout_wq);

        set_freezable();

        while(!kthread_should_stop()) {
                do_gettimeofday(&new_time);

                for( i = 0; i < MAX_TP_COUNT; i++) {

                        /* update PCR tracking status */
                        _tp_lock();
                        Tp_UpdatePCRTrackingStatus(i);
                        _tp_unlock();

                        Tp_Section_assemble(i);

                        /* get time counter in m-second(10^3) for debug_log_interval_ms */
                        TP_GET_TIME_CNT(time_cnt, new_time, saved_time);

                        /* TP HW reset in overflow and busy */
                        if(time_cnt >= debug_log_interval_ms) {
                                switch(i) {
                                        case TP_TP0:
                                                tp_tf_int_reg_addr  = TP_TP_TF0_INT_reg;
                                                tp_tf_cntl_reg_addr = TP_TP_TF0_CNTL_reg;
                                                break;
                                        case TP_TP1:
                                                tp_tf_int_reg_addr = TP_TP_TF1_INT_reg;
                                                tp_tf_cntl_reg_addr = TP_TP_TF1_CNTL_reg;
                                                break;
                                        case TP_TP2:
                                                tp_tf_int_reg_addr = TP_TP_TF2_INT_reg;
                                                tp_tf_cntl_reg_addr = TP_TP_TF2_CNTL_reg;
                                                break;
                                        case TP_TP3:
                                                tp_tf_int_reg_addr = TP_TP_TF3_INT_reg;
                                                tp_tf_cntl_reg_addr = TP_TP_TF3_CNTL_reg;
                                                break;
                                        default:
                                                tp_tf_int_reg_addr = TP_TP_TF0_INT_reg;
                                                tp_tf_cntl_reg_addr = TP_TP_TF0_CNTL_reg;
                                                break;
                                }

                                tp_tf_int_reg.regValue  = READ_REG32(tp_tf_int_reg_addr);
                                tp_tf_cntl_reg.regValue = READ_REG32(tp_tf_cntl_reg_addr);
                                if(tp_tf_int_reg.overflow == 1 && tp_tf_cntl_reg.busy == 1) {
                                        RHAL_SetTPHardwareReset(1);
                                }
                        }
                }

                if(time_cnt >= debug_log_interval_ms) {
                        saved_time = new_time;
                }

                if (freezing(current)) {
                        try_to_freeze();
                }

                /* interruptible_sleep_on_timeout(&timeout_wq, SECTION_ASM_TIMEOUT); */
                wait_event_interruptible_timeout(timeout_wq, 0, SECTION_ASM_TIMEOUT);
        }

        TP_INFO("exit section assemble thread exit\n");

        return 0;
}
#endif

static INT32 tp_dbg_thread(void* arg)
{
        UINT8 i, ring_buf_idx, info_buf_idx, startcode_buf_idx;
        TP_BUFFER_PARAM_T ring_buf, info_buf, startcode_buf;
        UINT32 ring_buf_cnt, ring_buf_sz, info_buf_cnt, info_buf_sz, startcode_buf_cnt, startcode_buf_sz;
        wait_queue_head_t timeout_wq;
        UINT32 time_cnt_dbg, time_cnt_status;

        TPK_TP_PKT_CNT_T tmpPkt;
        TPK_TP_PKT_CNT_T pktDiff_dbg;
        TPK_TP_PKT_CNT_T pktDiff_status;
        TPK_TP_PKT_CNT_T lastPktCnt[MAX_TP_COUNT];
        UINT32 valid_pid_filter_count = 0;
        UINT32 tp_live_flowrate;

        struct timeval saved_time_dbg, saved_time_status, new_time;

        TP_INFO("enter TP debug thread\n");

        /* init */
        for ( i = 0; i < MAX_TP_COUNT; i++) {
                lastPktCnt[i].pkt = 0;
                lastPktCnt[i].droppedPkt = 0;
                lastPktCnt[i].errorPkt = 0;
        }
        pktDiff_dbg.pkt = 0;
        pktDiff_dbg.droppedPkt = 0;
        pktDiff_dbg.errorPkt = 0;

        do_gettimeofday(&saved_time_dbg);
        memcpy(&saved_time_status, &saved_time_dbg, sizeof(struct timeval));
        init_waitqueue_head(&timeout_wq);

        set_freezable();

        while(!kthread_should_stop()) {
                do_gettimeofday(&new_time);

                /* get time counter in m-second(10^3) for debug_log_interval_ms */
                TP_GET_TIME_CNT(time_cnt_dbg, new_time, saved_time_dbg);
                /* get time counter in m-second(10^3) for immediate log */
                TP_GET_TIME_CNT(time_cnt_status, new_time, saved_time_status);

                for( i = 0; i < MAX_TP_COUNT && pTp_drv->tp[i].tp_stream_status == TP_STREAM_START; i++) {

                        switch(i) {
                                case TP_TP0:
                                        ring_buf_idx = TP0_BUFFER_MASS_DATA;
                                        info_buf_idx = TP0_BUFFER_INFO_PACK;
                                        startcode_buf_idx = TP0_START_CODE_PACK;
                                        break;
                                case TP_TP1:
                                        ring_buf_idx = TP1_BUFFER_MASS_DATA;
                                        info_buf_idx = TP1_BUFFER_INFO_PACK;
                                        startcode_buf_idx = TP1_START_CODE_PACK;
                                        break;
                                case TP_TP2:
                                        ring_buf_idx = TP2_BUFFER_MASS_DATA;
                                        info_buf_idx = TP2_BUFFER_INFO_PACK;
                                        break;
                                case TP_TP3:
                                        ring_buf_idx = TP3_BUFFER_MASS_DATA;
                                        info_buf_idx = TP3_BUFFER_INFO_PACK;
                                        break;
                                default:
                                        ring_buf_idx = TP0_BUFFER_MASS_DATA;
                                        info_buf_idx = TP0_BUFFER_INFO_PACK;
                                        break;
                        }


                        if (time_cnt_status >= status_log_interval_ms) {
                                /* get TP papcket count */
                                tmpPkt.pkt        = 0;
                                tmpPkt.droppedPkt = 0;
                                tmpPkt.errorPkt   = 0;

                                if ( pTp_drv->tp[i].tp_pkt_cnt.pkt == 0 &&
                                     pTp_drv->tp[i].tp_pkt_cnt.droppedPkt == 0 &&
                                     pTp_drv->tp[i].tp_pkt_cnt.errorPkt == 0 ) {
                                        lastPktCnt[i].pkt = 0;
                                        lastPktCnt[i].droppedPkt = 0;
                                        lastPktCnt[i].errorPkt = 0;

                                        pktDiff_dbg.pkt = 0;
                                        pktDiff_dbg.droppedPkt = 0;
                                        pktDiff_dbg.errorPkt = 0;
                                }

                                _tp_lock();
                                Tp_TrackErrorPacket(i, &tmpPkt.pkt, &tmpPkt.droppedPkt, &tmpPkt.errorPkt);
                                _tp_unlock();

                                pktDiff_status.pkt        = tmpPkt.pkt - lastPktCnt[i].pkt;
                                pktDiff_status.droppedPkt = tmpPkt.droppedPkt - lastPktCnt[i].droppedPkt;
                                pktDiff_status.errorPkt   = tmpPkt.errorPkt - lastPktCnt[i].errorPkt;

                                pktDiff_dbg.pkt        += pktDiff_status.pkt;
                                pktDiff_dbg.droppedPkt += pktDiff_status.droppedPkt;
                                pktDiff_dbg.errorPkt   += pktDiff_status.errorPkt;

                                lastPktCnt[i].pkt        = tmpPkt.pkt;
                                lastPktCnt[i].droppedPkt = tmpPkt.droppedPkt;
                                lastPktCnt[i].errorPkt   = tmpPkt.errorPkt;

#if 0 // for debug
                                TP_DBG_SIMPLE( "TP%u tmpPkt=%llu/%llu/%llu pktDiff_status=%llu/%llu/%llu pktDiff_dbg=%llu/%llu/%llu\n",
                                               i, tmpPkt.pkt, tmpPkt.droppedPkt, tmpPkt.errorPkt,
                                               pktDiff_status.pkt, pktDiff_status.droppedPkt, pktDiff_status.errorPkt,
                                               pktDiff_dbg.pkt, pktDiff_dbg.droppedPkt, pktDiff_dbg.errorPkt);
#endif

                        }

                        /* log printing with print time interval */
                        if( tp_log_onoff && (time_cnt_dbg >= debug_log_interval_ms)) {
                                _tp_lock();
                                /* 1. display TP count packet */
                                valid_pid_filter_count = Tp_Get_Valid_Pid_Cnt(i, 1);
                                _tp_unlock();
                                /* have pid and sec filter */
                                if(valid_pid_filter_count > 0) {

                                        if (TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_PIDFILTER)) {
                                                TP_DBG_SIMPLE("TP%u have valid pid or section filter!\n", i);
                                                TP_CLEAR_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_PIDFILTER);
                                        }

                                        /* 1.1 display TP packet/drop/error count in abnormal case */
                                        /* case1: when error counter increase 10/s up */
                                        if(pktDiff_dbg.errorPkt >= 20) {
                                                if ( !TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_ERR_CNT) ) {
                                                        TP_DBG_SIMPLE( "Warning, TP%u error count increase! If cause broken screen, please check Demod status! pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n",
                                                                       i, tmpPkt.pkt, pktDiff_dbg.pkt, tmpPkt.droppedPkt, pktDiff_dbg.droppedPkt, tmpPkt.errorPkt, pktDiff_dbg.errorPkt, (pktDiff_dbg.pkt - pktDiff_dbg.droppedPkt));
                                                        TP_SET_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_ERR_CNT);

                                                }
                                        } else {
                                                if( TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_ERR_CNT) ) {
                                                        TP_DBG_SIMPLE("TP%u error count normally! pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n",
                                                                      i, tmpPkt.pkt, pktDiff_dbg.pkt, tmpPkt.droppedPkt, pktDiff_dbg.droppedPkt, tmpPkt.errorPkt, pktDiff_dbg.errorPkt, (pktDiff_dbg.pkt - pktDiff_dbg.droppedPkt));
                                                        TP_CLEAR_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_ERR_CNT);
                                                }
                                        }
                                        /* case2: when on packet data detect */
                                        if( pktDiff_dbg.pkt == 0 ) {
                                                if ( !TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_PKT_CNT) ) {
                                                        TP_DBG_SIMPLE( "Warning, TP%u pkt cnt no increase - pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n",
                                                                       i, tmpPkt.pkt, pktDiff_dbg.pkt, tmpPkt.droppedPkt, pktDiff_dbg.droppedPkt, tmpPkt.errorPkt, pktDiff_dbg.errorPkt, (pktDiff_dbg.pkt - pktDiff_dbg.droppedPkt));
                                                        TP_SET_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_PKT_CNT);
                                                }
                                        } else {
                                                if( TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_PKT_CNT) ) {
                                                        TP_DBG_SIMPLE("TP%u packet cnt normally! pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n",
                                                                      i, tmpPkt.pkt, pktDiff_dbg.pkt, tmpPkt.droppedPkt, pktDiff_dbg.droppedPkt, tmpPkt.errorPkt, pktDiff_dbg.errorPkt, (pktDiff_dbg.pkt - pktDiff_dbg.droppedPkt));
                                                        TP_CLEAR_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_PKT_CNT);
                                                }
                                        }

                                        /* case3: rev cnt too small */
                                        if( pktDiff_dbg.pkt != 0 ) {
                                                if( (pktDiff_dbg.pkt >= pktDiff_dbg.droppedPkt) && ((pktDiff_dbg.pkt - pktDiff_dbg.droppedPkt) < 20 )) {
                                                        if ( !TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_REV_CNT) ) {
                                                                TP_DBG_SIMPLE( "Warning, TP%u rev cnt abnormal - pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n",
                                                                               i, tmpPkt.pkt, pktDiff_dbg.pkt, tmpPkt.droppedPkt, pktDiff_dbg.droppedPkt, tmpPkt.errorPkt, pktDiff_dbg.errorPkt, (pktDiff_dbg.pkt - pktDiff_dbg.droppedPkt));
                                                                Tp_Cmd_Dump_PID_filter_Status(i, NULL);
                                                                TP_SET_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_REV_CNT);
                                                        }
                                                } else {
                                                        if( TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_REV_CNT) ) {
                                                                TP_DBG_SIMPLE("TP%u rev cnt normally! pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n",
                                                                              i, tmpPkt.pkt, pktDiff_dbg.pkt, tmpPkt.droppedPkt, pktDiff_dbg.droppedPkt, tmpPkt.errorPkt, pktDiff_dbg.errorPkt, (pktDiff_dbg.pkt - pktDiff_dbg.droppedPkt));
                                                                TP_CLEAR_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_REV_CNT);
                                                        }
                                                }
                                        }

                                        /* 1.2 display TP count packet print regularly */
                                        tp_mask_print_emerg( TP_LOG_BLOCK_CNT, TP_LOG_LEVEL_DEBUG, "TP%u, pkt=%llu(diff=%llu), drop=%llu(diff=%llu), err=%llu(diff=%llu), rev=%llu\n", i, tmpPkt.pkt, pktDiff_dbg.pkt, tmpPkt.droppedPkt, pktDiff_dbg.droppedPkt, tmpPkt.errorPkt, pktDiff_dbg.errorPkt, (pktDiff_dbg.pkt - pktDiff_dbg.droppedPkt));
                                } else if ( valid_pid_filter_count == 0 ) {
                                        if ( !(logStatusFlag[i]&TP_STATUS_LOG_FLAG_PIDFILTER)) {
                                                TP_WARNING("TP%u No valid pid & section filter!\n", i);
                                                TP_SET_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_PIDFILTER);
                                        }
                                } else {
                                        TP_ERROR("Unknow pid filter count: %d\n", valid_pid_filter_count);
                                }

                                /* 2. display buffer status */
                                /* 2.1 display MTP buffer status */
                                if (pTp_drv->mtp[i].mtp_stream_status == MTP_STREAM_START) {
                                        _tp_lock();
                                        Tp_Get_MTP_Buffer(i, &ring_buf);

                                        ring_buf_sz = GET_BUFF_SIZE(ring_buf);
                                        ring_buf_cnt = GET_BUFF_DATA_ALL_SIZE(ring_buf);

                                        TP_DBG_SIMPLE("TP%u_MTP : ring_rate=%u KB/s, ring=%u/%u (R=0x%x, W=0x%x, B=0x%x, L=0x%x)\n",
                                                      i ,
                                                      (pTp_drv->mtp[i].mtp_write_data_cnt / time_cnt_dbg),
                                                      ring_buf_cnt, ring_buf_sz,
                                                      ring_buf.RP, ring_buf.WP, ring_buf.Base, ring_buf.Limit);

                                        pTp_drv->mtp[i].mtp_write_data_cnt = 0;
                                        _tp_unlock();
                                }

                                /* 2.2 display TP buffer status */
                                /* 2.2.1 print mass & info buffer status by enable buffer log */

                                {
                                        _tp_lock();
                                        Tp_Get_Buffer(ring_buf_idx, &ring_buf);
                                        Tp_Get_Buffer(info_buf_idx, &info_buf);

                                        if(Tp_is_SupportPatternSearch(i) == TPK_SUCCESS)
                                                Tp_Get_Buffer(startcode_buf_idx, &startcode_buf);
                                        else
                                                startcode_buf.Base = startcode_buf.Limit = startcode_buf.RP = startcode_buf.WP = 0;

                                        ring_buf_cnt = GET_BUFF_DATA_ALL_SIZE(ring_buf);
                                        ring_buf_sz = GET_BUFF_SIZE(ring_buf);

                                        info_buf_cnt = GET_BUFF_DATA_ALL_SIZE(info_buf);
                                        info_buf_sz = GET_BUFF_SIZE(info_buf);

                                        startcode_buf_cnt = GET_BUFF_DATA_ALL_SIZE(startcode_buf);
                                        startcode_buf_sz = GET_BUFF_SIZE(startcode_buf);

                                        tp_live_flowrate = (UINT32)((pktDiff_dbg.pkt - pktDiff_dbg.droppedPkt) * pTp_drv->tp[i].mass_buffer.bock_size);
                                        pTp_drv->tp_pid[i].ringrate_KB = pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_dbg;

                                        if ( CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_BUFFER) ) {
                                                TP_DBG_SIMPLE("TP%u: LR=%uKB/s(%u/%u), RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                              i, (tp_live_flowrate / time_cnt_dbg), tp_live_flowrate, time_cnt_dbg,
                                                              (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_dbg),
                                                              ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_dbg / 1000));
                                                TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);
                                        }

                                        pTp_drv->tp_pid[i].tp_mass_data_release_cnt = 0;
                                        pTp_drv->tp_pid[i].pcr.pcr_irq_cnt = 0;
                                        _tp_unlock();
                                }

                                /* 2.2.2 print pattern buffer status */
                                if ( startcode_buf_sz && pTp_drv->tp[i].Shared_RWPtr.inited ) {
                                        unsigned char *pattern_rp_virtual;
                                        unsigned char *pattern_wp_virtual;
                                        UADDRESS *mass_phy_of_pattern_rp;
                                        UADDRESS *mass_phy_of_pattern_wp;

                                        pattern_rp_virtual = (unsigned char *)(pTp_drv->tp[i].start_code_search_buffer.BaseVir + (startcode_buf.RP - pTp_drv->tp[i].start_code_search_buffer.BasePhy));
                                        pattern_wp_virtual = (unsigned char *)(pTp_drv->tp[i].start_code_search_buffer.BaseVir + (startcode_buf.WP - pTp_drv->tp[i].start_code_search_buffer.BasePhy));

                                        if(pattern_wp_virtual == (unsigned char *)(pTp_drv->tp[i].start_code_search_buffer.BaseVir))
                                                pattern_wp_virtual = (unsigned char *)pTp_drv->tp[i].start_code_search_buffer.LimitVir;
                                        pattern_wp_virtual = pattern_wp_virtual - 8;

                                        mass_phy_of_pattern_rp = (UADDRESS *)(pattern_rp_virtual[0] << 24 | pattern_rp_virtual[1] << 16 | pattern_rp_virtual[2] << 8 | pattern_rp_virtual[3]);
                                        mass_phy_of_pattern_wp = (UADDRESS *)(pattern_wp_virtual[0] << 24 | pattern_wp_virtual[1] << 16 | pattern_wp_virtual[2] << 8 | pattern_wp_virtual[3]);

                                        TP_DBG_SIMPLE("TP%u: pattern=%u/%u (%x(%x)/%x(%x)/%x/%x) pvr=%x/%x\n",
                                                      i ,
                                                      startcode_buf_cnt, startcode_buf_sz,
                                                      startcode_buf.RP, mass_phy_of_pattern_rp, startcode_buf.WP, mass_phy_of_pattern_wp, startcode_buf.Base, startcode_buf.Limit,
                                                      pTp_drv->tp[i].monitor_pvr_rp, pTp_drv->tp[i].monitor_pvr_wp);
                                }

                                /* 4. display tp src */
                                tp_mask_print_emerg( TP_LOG_BLOCK_FRAMER, TP_LOG_LEVEL_DEBUG, "TP%u, tp_src=%d, tpout_src=%d\n",
                                                     i,
                                                     pTp_drv->tp[i].tp_src,
                                                     pTp_drv->tpout[0].tpout_src);
                        }

                        /* log printing with print time interval 1s */
                        if( (time_cnt_status >= status_log_interval_ms)) {

                                if ( !CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_BUFFER) && (i != TP_TP3) ) {
                                        /* display TP buffer status */
                                        _tp_lock();
                                        Tp_Get_Buffer(ring_buf_idx, &ring_buf);
                                        Tp_Get_Buffer(info_buf_idx, &info_buf);

                                        if(Tp_is_SupportPatternSearch(i) == TPK_SUCCESS)
                                                Tp_Get_Buffer(startcode_buf_idx, &startcode_buf);
                                        else
                                                startcode_buf_sz = startcode_buf_cnt = 0;
                                        _tp_unlock();

                                        ring_buf_cnt = GET_BUFF_DATA_ALL_SIZE(ring_buf);
                                        ring_buf_sz = GET_BUFF_SIZE(ring_buf);

                                        info_buf_cnt = GET_BUFF_DATA_ALL_SIZE(info_buf);
                                        info_buf_sz = GET_BUFF_SIZE(info_buf);

                                        startcode_buf_cnt = GET_BUFF_DATA_ALL_SIZE(startcode_buf);
                                        startcode_buf_sz = GET_BUFF_SIZE(startcode_buf);

                                        tp_live_flowrate = (pktDiff_status.pkt - pktDiff_status.droppedPkt) * pTp_drv->tp[i].mass_buffer.bock_size;

                                        if ( tp_live_flowrate == 0 && pktDiff_status.pkt != 0) {
                                                if ( !TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_NO_LIVERATE)) {
                                                        TP_DBG_SIMPLE("Warning, TP%u no live rate!\n", i);
                                                        TP_DBG_SIMPLE("TP%u: LR=%uKB/s(%u/%u), RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                      i, (tp_live_flowrate / time_cnt_status), tp_live_flowrate, time_cnt_status, (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_status),
                                                                      ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_status / 1000));
                                                        TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);
                                                        TP_SET_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_NO_LIVERATE);
                                                }
                                        } else {
                                                /* 2.2 no live rate -> have live rate */
                                                if ( TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_NO_LIVERATE) && pktDiff_status.pkt != 0 ) {
                                                        TP_DBG_SIMPLE("TP%u have live rate!\n", i);
                                                        TP_DBG_SIMPLE("TP%u: LR=%uKB/s(%u/%u), RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                      i,
                                                                      (tp_live_flowrate / time_cnt_status), tp_live_flowrate, time_cnt_status, (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_status),
                                                                      ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_status / 1000));
                                                        TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);
                                                        TP_CLEAR_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_NO_LIVERATE);
                                                }

                                                /* 2.3 low live buffer rate or buffer usage is larger than 90% */
                                                if ( (pktDiff_status.pkt != 0 && pktDiff_status.pkt >= pktDiff_status.droppedPkt)) {
                                                        /* low live rate */
                                                        if((tp_live_flowrate / time_cnt_status) <= 100) {
                                                                if(!TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_LOW_LIVERATE)) {
                                                                        /* low live rate in channel scan case */
                                                                        if ( ((tp_live_flowrate / time_cnt_status) <= 10 ) &&
                                                                             (Tp_Get_Valid_Pid_Cnt(i, 1) && Tp_Get_Valid_Pid_Cnt(i, 0) == 0)) {
                                                                                TP_DBG_SIMPLE("Warning, TP%u only sec filter!\n", i);
                                                                        }

                                                                        TP_DBG_SIMPLE("Warning, TP%u low live rate!\n", i);
                                                                        TP_DBG_SIMPLE("TP%u: LR=%uKB/s(%u/%u), RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                                      i, (tp_live_flowrate / time_cnt_status), tp_live_flowrate, time_cnt_status, (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_status),
                                                                                      ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                                        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_status / 1000));
                                                                        TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);

                                                                        TP_SET_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_LOW_LIVERATE);
                                                                }
                                                        } else {
                                                                if ( TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_LOW_LIVERATE) ) {
                                                                        TP_DBG_SIMPLE("TP%u live rate normally!\n", i);
                                                                        TP_DBG_SIMPLE("TP%u: LR=%uKB/s, RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                                      i, (tp_live_flowrate / time_cnt_status), (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_status),
                                                                                      ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                                        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_status / 1000));
                                                                        TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);

                                                                        TP_CLEAR_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_LOW_LIVERATE);
                                                                }
                                                        }

                                                        /* buff usage large than 90% */
                                                        if ( !TP_HAS_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_BUFFUSAGE) && ring_buf_cnt >= (ring_buf_sz / 10 * 9)) {
                                                                TP_DBG_SIMPLE("Warning, TP%u buffer usage is larger than 90%%!\n", i);
                                                                TP_DBG_SIMPLE("TP%u: LR=%uKB/s, RR=%uKB/s ring=%u/%u(R=0x%x(%x/%x/%x) W=0x%x B=0x%x L=0x%x)\n",
                                                                              i, (tp_live_flowrate / time_cnt_status), (pTp_drv->tp_pid[i].tp_mass_data_release_cnt / time_cnt_status),
                                                                              ring_buf_cnt, ring_buf_sz, ring_buf.RP, pTp_drv->tp[i].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[i].mass_buffer.RP_Connect[DUMP_BUFFER_RP], ring_buf.WP, ring_buf.Base, ring_buf.Limit);
                                                                tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u: pcr_cnt=%d\n", i, pTp_drv->tp_pid[i].pcr.pcr_irq_cnt / (time_cnt_status / 1000));
                                                                TP_DBG_SIMPLE("TP%u: info=%u/%u(R=0x%x W=0x%x B=0x%x L=0x%x)\n", i, info_buf_cnt, info_buf_sz, info_buf.RP, info_buf.WP, info_buf.Base, info_buf.Limit);

                                                                TP_SET_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_BUFFUSAGE);
                                                        } else {
                                                                TP_SET_FLAG(logStatusFlag[i], TP_STATUS_LOG_FLAG_BUFFUSAGE);
                                                        }

                                                }
                                        }
                                        _tp_lock();
                                        pTp_drv->tp_pid[i].tp_mass_data_release_cnt = 0;
                                        pTp_drv->tp_pid[i].pcr.pcr_irq_cnt = 0;
                                        _tp_unlock();

                                }
                        }
                }

                if(time_cnt_dbg >= debug_log_interval_ms) {
                        //saved_time_dbg = new_time;
                        memcpy(&saved_time_dbg, &new_time, sizeof(struct timeval));

                        /* reset pkt diff per interval */
                        pktDiff_dbg.pkt = 0;
                        pktDiff_dbg.droppedPkt = 0;
                        pktDiff_dbg.errorPkt = 0;
                }

                if ( time_cnt_status >= status_log_interval_ms ) {
                        memcpy(&saved_time_status, &new_time, sizeof(struct timeval));
                }


                if (freezing(current)) {
                        try_to_freeze();
                }

                wait_event_interruptible_timeout(timeout_wq, 0, TP_DBG_TIMEOUT);
        }

        TP_INFO("exit TP debug thread exit\n");

        return 0;
}


INT32 section_assemble_thread_start_stop(UINT8 thread_en)
{
        struct task_struct *sec_assemble;
        INT32 result;

        if(thread_en) {
                if(pTp_drv->sec_assemble != NULL) {
                        TP_INFO("Section assemble thread is already existed\n");
                        return TPK_SUCCESS;
                }

                sec_assemble = kthread_run(section_assemble_thread, NULL, "tp_section_asm");    /* no need to pass parameter into thread function */
                if(!IS_ERR(sec_assemble)) {
                        pTp_drv->sec_assemble = sec_assemble;
                } else {
                        TP_WARNING("create section assemble thread failed, error=%ld\n", PTR_ERR(sec_assemble));
                        return TPK_NOT_ENOUGH_RESOURCE;
                }
                pTp_drv->sec_asm_start = 1;
        } else {
                if(pTp_drv->sec_assemble == NULL) {
                        TP_INFO("Section assemble thread does not exist, just exit\n");
                        return TPK_SUCCESS;
                }

                pTp_drv->sec_asm_start = 0;
                if(pTp_drv->sec_assemble) {
                        /* it will wait until thread function exit */
                        result = kthread_stop(pTp_drv->sec_assemble);
                }
                if(result < 0) {
                        TP_WARNING("call kthread_stop return error = %d", result);
                }
                pTp_drv->sec_assemble = NULL;
        }
        return TPK_SUCCESS;

}

INT32 tp_dbg_thread_start_stop(UINT8 enable)
{
        struct task_struct *tp_dbg_t;
        INT32 ret;

        if(enable) {
                if(pTp_drv->tp_dbg_t != NULL) {
                        TP_INFO("TP debug thread is already existed\n");
                        return TPK_SUCCESS;
                }

                tp_dbg_t = kthread_run(tp_dbg_thread, NULL, "tp_dbg");    /* no need to pass parameter into thread function */
                if(!IS_ERR(tp_dbg_t)) {
                        pTp_drv->tp_dbg_t = tp_dbg_t;
                } else {
                        TP_WARNING("create tp debug thread failed, error=%ld\n", PTR_ERR(tp_dbg_t));
                        return TPK_NOT_ENOUGH_RESOURCE;
                }
                pTp_drv->tp_dbg_t_start = 1;
        } else {
                if(pTp_drv->tp_dbg_t == NULL) {
                        TP_INFO("TP debug thread does not exist, just exit\n");
                        return TPK_SUCCESS;
                }

                pTp_drv->tp_dbg_t_start = 0;
                if(pTp_drv->tp_dbg_t) {
                        /* it will wait until thread function exit */
                        ret = kthread_stop(pTp_drv->tp_dbg_t);
                }
                if(ret < 0) {
                        TP_WARNING("call kthread_stop return error = %d", ret);
                }
                pTp_drv->tp_dbg_t = NULL;
        }
        return TPK_SUCCESS;

}


/*********************************

       PCR tracking control

********************************/
INT32 Tp_ResetPCRStatus(TPK_TP_ENGINE_T tp_id)
{
        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        pTp_drv->tp_pid[tp_id].pcr.Base_Valid = 0;
        pTp_drv->tp_pid[tp_id].pcr.LastPCR    = 0;
        pTp_drv->tp_pid[tp_id].pcr.LastSTC    = 0;
        pTp_drv->tp_pid[tp_id].pcr.PCRBase    = 0;
        pTp_drv->tp_pid[tp_id].pcr.STCBase    = 0;

        return TPK_SUCCESS;
}

INT32 Tp_PCRTrackingEnable(TPK_TP_ENGINE_T tp_id , UINT8 On, UINT16 PID, TPK_PCR_CLK_SRC_T clk_src)
{
        UINT16 i, max_pid_cnt, pid_idx, pid_idx_reg = 0;
        INT32 result;
        TPK_PID_FILTER_PARAM_T pid_api_setting;
        UINT8 pid_update_flag, pid_ddr_buf_idx, pid_info_buf_idx;
        REGADDR tp_pcr_ctrl_reg;
        tp_tp0_pcr_ctl_RBUS tp0_pcr_ctrl;
        tp_tp_tf0_cntl_RBUS tp0_cntl;

        /* check parameter */
        if(On && clk_src >= TPK_PCR_CLK_SRC_NUM) {
                TP_INFO("bad parameter, PID=0x%x, clk_src=%u ,On=%d\n", PID, clk_src, On);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        TP_INFO("TP%u, this PID (0x%x) pcr.On=%d\n", tp_id, PID, On);
        result = Tp_Get_MaxPID_Cnt(tp_id, &max_pid_cnt);
        if(result != TPK_SUCCESS) {
                TP_WARNING("call Tp_Get_MaxPID_Cnt return error\n");
                return result;
        }

        switch(tp_id) {
                case TP_TP0:
                        tp_pcr_ctrl_reg = TP_TP0_PCR_CTL_reg;
                        break;
                case TP_TP1:
                        tp_pcr_ctrl_reg = TP_TP1_PCR_CTL_reg;
                        break;
                case TP_TP2:
                        tp_pcr_ctrl_reg = TP_TP2_PCR_CTL_reg;
                        break;
                case TP_TP3:
                        tp_pcr_ctrl_reg = TP_TP3_PCR_CTL_reg;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        if(clk_src == CLK_SRC_NO_CHANGE) {
                clk_src =  pTp_drv->tp_pid[tp_id].pcr.clk_src;
        }

        if(On && (PID >= MAX_PID_VALUE) ) {
                /* change clk_src here */
                /* set PCR tracking register mode */
                tp0_pcr_ctrl.regValue = READ_REG32(tp_pcr_ctrl_reg);
                tp0_pcr_ctrl.stc_sel  = (clk_src == MISC_90KHz) ? 0 : 1;
                WRITE_REG32(tp_pcr_ctrl_reg, tp0_pcr_ctrl.regValue);

                if (clk_src != MISC_90KHz) {
                        tp0_pcr_ctrl.regValue = READ_REG32(tp_pcr_ctrl_reg);
                        if (clk_src == TP_PCRA_LOCAL_90KHz) {
                                tp0_pcr_ctrl.local_pcr_sel = 0;
                        }
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
                        else if (clk_src == TP_PCRB_LOCAL_90KHz) {
                                tp0_pcr_ctrl.local_pcr_sel = 1;
                        }
#endif
                        else {
                                TP_WARNING("bad parameter, tp_id=%u, PID=0x%x, clk_src=%u\n", tp_id, PID, clk_src);
                        }
                        WRITE_REG32(tp_pcr_ctrl_reg, tp0_pcr_ctrl.regValue);
                }
                pTp_drv->tp_pid[tp_id].pcr.clk_src = clk_src;
                result = Tp_ResetPCRStatus(tp_id);
                return TPK_SUCCESS;
        }

        if(On) {
                /* if this PID already set to PCR tracking, remove last PID filter */
                TP_INFO("TP%u, this PID (0x%x) pcr.enable=%d\n", tp_id, PID, pTp_drv->tp_pid[tp_id].pcr.enable);
                if(pTp_drv->tp_pid[tp_id].pcr.enable) {
                        TP_INFO("TP%u, this PID (0x%x) PCR tracking!!!!!pcr.PID=%x\n",
                                tp_id, PID, pTp_drv->tp_pid[tp_id].pcr.PID );
                        if(pTp_drv->tp_pid[tp_id].pcr.PID == PID) {
                                if(pTp_drv->tp_pid[tp_id].pcr.clk_src == clk_src) {
                                        TP_INFO("TP%u, this PID (0x%x) already set to PCR tracking\n", tp_id, PID);
                                } else {
                                        /* change clk_src here */
                                        /* set PCR tracking register mode */
                                        tp0_pcr_ctrl.regValue = READ_REG32(tp_pcr_ctrl_reg);
                                        tp0_pcr_ctrl.stc_sel  = (clk_src == MISC_90KHz) ? 0 : 1;
                                        WRITE_REG32(tp_pcr_ctrl_reg, tp0_pcr_ctrl.regValue);

                                        if (clk_src != MISC_90KHz) {
                                                tp0_pcr_ctrl.regValue = READ_REG32(tp_pcr_ctrl_reg);
                                                if (clk_src == TP_PCRA_LOCAL_90KHz) {
                                                        tp0_pcr_ctrl.local_pcr_sel = 0;
                                                }
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
                                                else if (clk_src == TP_PCRB_LOCAL_90KHz) {
                                                        tp0_pcr_ctrl.local_pcr_sel = 1;
                                                }
#endif
                                                else {
                                                        TP_WARNING("bad parameter, tp_id=%u, PID=0x%x, clk_src=%u\n",
                                                                   tp_id, PID, clk_src);
                                                }
                                                WRITE_REG32(tp_pcr_ctrl_reg, tp0_pcr_ctrl.regValue);
                                        }
                                        pTp_drv->tp_pid[tp_id].pcr.clk_src      = clk_src;
                                        pTp_drv->tp_pid[tp_id].pcr.ClkSrcChange = 1;
                                        Tp_ResetPCRStatus(tp_id);

                                        TP_DBG("TP%u, this PID (0x%x) already set to PCR tracking, clk_src change to %u\n",
                                               tp_id, PID, clk_src);

                                }

                                return TPK_SUCCESS;
                        }

                        result = Tp_RemovePIDFilter(tp_id, pTp_drv->tp_pid[tp_id].pcr.PID, PCR_TRACKING_FILE_HANDLE);
                        if(result != TPK_SUCCESS) {
                                TP_WARNING("TP%u remove PID filter failed (result=%d)\n", tp_id, result);
                                return result;
                        }
                        pTp_drv->tp_pid[tp_id].pcr.enable = 0;
                }

                /* add pid filter for PCR tracking. */
                /* if this pid filter exist already, */
                /* call add pid filter again with PCR_TRACKING_FILE_HANDLE */
                memset(&pid_api_setting, 0, sizeof(pid_api_setting));
                pid_api_setting.DescrambleEn = 0;
                pid_api_setting.KeySel       = 0;
                pid_api_setting.PID          = PID;
                for(i = 0; i < max_pid_cnt; i++) {
                        if((pTp_drv->tp_pid[tp_id].pid_api_setting[i].valid) &&
                            (pTp_drv->tp_pid[tp_id].pid_api_setting[i].PID == PID)) {
                                pid_api_setting.DescrambleEn = pTp_drv->tp_pid[tp_id].pid_api_setting[i].DescrambleEn;
                                pid_api_setting.KeySel       = pTp_drv->tp_pid[tp_id].pid_api_setting[i].KeySel;
                                break;
                        }
                }
                result = Tp_AddPIDFilter(tp_id, pid_api_setting, PCR_TRACKING_FILE_HANDLE);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("TP%u call Tp_AddPIDFilter() failed (%d)\n", tp_id, result);
                        return result;
                }

                /* get pid_idx_reg */
                result = _PID_Filter_Update_Check(tp_id, pid_api_setting,
                                                  &pid_idx, &pid_idx_reg,
                                                  &pid_update_flag, &max_pid_cnt,
                                                  &pid_ddr_buf_idx, &pid_info_buf_idx);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("TP%u call _PID_Filter_Update_Check() failed (%d)\n", tp_id, result);
                        return result;
                }

                /* set tb to 90KHz */
                tp0_cntl.regValue = 0;
                tp0_cntl.tb       = 1;
                Tp_SetTpCtrlReg(tp_id, tp0_cntl.regValue, 1);

                /* set PCR tracking register mode */
                tp0_pcr_ctrl.regValue = READ_REG32(tp_pcr_ctrl_reg);
                tp0_pcr_ctrl.stc_sel  = (clk_src == MISC_90KHz) ? 0 : 1;
                WRITE_REG32(tp_pcr_ctrl_reg, tp0_pcr_ctrl.regValue);

                tp0_pcr_ctrl.regValue = READ_REG32(tp_pcr_ctrl_reg);
                tp0_pcr_ctrl.extra_func_ena = 1;
                tp0_pcr_ctrl.extra_pid_addr = pid_idx_reg;
                WRITE_REG32(tp_pcr_ctrl_reg, tp0_pcr_ctrl.regValue);

                if (clk_src != MISC_90KHz) {
                        tp0_pcr_ctrl.regValue = READ_REG32(tp_pcr_ctrl_reg);
                        if (clk_src == TP_PCRA_LOCAL_90KHz) {
                                tp0_pcr_ctrl.local_pcr_sel = 0;
                        }
#ifdef CONFIG_RTK_KDRV_MULTI_TP_CLOCK
                        else if (clk_src == TP_PCRB_LOCAL_90KHz) {
                                tp0_pcr_ctrl.local_pcr_sel = 1;
                        }
#endif
                        else {
                                TP_WARNING("bad parameter, tp_id=%u, PID=0x%x, clk_src=%u\n", tp_id, PID, clk_src);
                        }
                        WRITE_REG32(tp_pcr_ctrl_reg, tp0_pcr_ctrl.regValue);
                }
        } else {
                if(pTp_drv->tp_pid[tp_id].pcr.enable) {
                        /* remove pid filter if PCR tracking disable */
                        result = Tp_RemovePIDFilter(tp_id, pTp_drv->tp_pid[tp_id].pcr.PID, PCR_TRACKING_FILE_HANDLE);
                        if(result != TPK_SUCCESS) {
                                TP_WARNING("TP%u remove PCR PID filter failed (result=%d)\n", tp_id, result);
                                return result;
                        }
                }
        }

#if 0
        if(tp_id == 0) {
                tp0_pcr_ctrl.extra_func_ena = On ? 1 : 0;
                tp0_pcr_ctrl.extra_pid_addr = pid_idx_reg;
        }
        WRITE_REG32(TP0_PCR_CTL_reg, tp0_pcr_ctrl.regValue);

        if(tp_id == 1) {
                tp1_pcr_ctrl.regValue = 0;
                tp1_pcr_ctrl.extra_func_ena = On ? 1 : 0;
                tp1_pcr_ctrl.extra_pid_addr = pid_idx_reg;
                WRITE_REG32(TP1_PCR_CTL_reg, tp1_pcr_ctrl.regValue);
        }

        if(tp_id == 2) {
                tp2_pcr_ctrl.regValue = 0;
                tp2_pcr_ctrl.extra_func_ena = On ? 1 : 0;
                tp2_pcr_ctrl.extra_pid_addr = pid_idx_reg;
                WRITE_REG32(TP2_PCR_CTL_reg, tp2_pcr_ctrl.regValue);
        }
#endif

        pTp_drv->tp_pid[tp_id].pcr.enable  = On ? 1 : 0;
        pTp_drv->tp_pid[tp_id].pcr.clk_src = clk_src;

        if(On) {
                pTp_drv->tp_pid[tp_id].pcr.PID = PID;
        } else {
                pTp_drv->tp_pid[tp_id].pcr.PID = 0xffff;
        }

        result = Tp_ResetPCRStatus(tp_id);
        return result;
}

INT32 Tp_UpdatePCRTrackingStatus(TPK_TP_ENGINE_T tp_id)
{
        UINT64 PCR;
        UINT64 STC;
        UADDRESS ptrlo;
        UADDRESS ptrhi;
        INT64 misc_value;
        INT64 pcra_value;
        INT64 pcrb_value;
        INT64 stc_diff_value;
        INT64 temp_pcr_diff;
        INT64 temp_stc_diff;
        UINT8 try_cnt = 0;
        tp_tp_pcr_latch_RBUS pcr_latch;

        /* check parameter */
        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        /* check if PCR tracking enable or not */
        if(pTp_drv->tp_pid[tp_id].pcr.enable == 0) {
                return TPK_NOT_SET;
        }

#ifdef TP_PCR_USE_IRQ
        STC = pTp_drv->tp[tp_id].stc_from_isr;
        PCR = pTp_drv->tp[tp_id].pcr_from_isr;
#else
        WRITE_REG32(TP_TP_PCR_BASE_reg, 0);
        WRITE_REG32(TP_TP_PCR_EXT_reg, 0);
        WRITE_REG32(TP_TP_PCR_SYSTEM_0_reg, 0);
        WRITE_REG32(TP_TP_PCR_SYSTEM_1_reg, 0);

        pcr_latch.regValue  = 0;
        pcr_latch.latch_ena = 1;
        switch(tp_id) {
                case TP_TP0:
                        pcr_latch.latch_sel = 0;
                        break;
                case TP_TP1:
                        pcr_latch.latch_sel = 1;
                        break;
                case TP_TP2:
                        pcr_latch.latch_sel = 2;
                        break;
                case TP_TP3:
                        pcr_latch.latch_sel = 3;
                        break;
                default:
                        TP_WARNING("invalid TP Index %u.\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }
        WRITE_REG32(TP_TP_PCR_LATCH_reg, pcr_latch.regValue);

        while(TP_TP_PCR_LATCH_get_latch_ena(READ_REG32(TP_TP_PCR_LATCH_reg)) && try_cnt++ < 10) {
                udelay(10);     /* busy wait */
        }

        if (TP_TP_PCR_LATCH_get_latch_ena(READ_REG32(TP_TP_PCR_LATCH_reg))) {
                TP_WARNING("TP%u Update PCR failed, wait PCR latch timeout.\n", tp_id);
                return TPK_TIMEOUT;
        }

        STC = (((UINT64)READ_REG32(TP_TP_PCR_SYSTEM_1_reg)) << 32) + (UINT64)READ_REG32(TP_TP_PCR_SYSTEM_0_reg);
        PCR = (UINT64)READ_REG32(TP_TP_PCR_BASE_reg);

        if (TP_TP_PCR_EXT_get_pcr_base_hi(READ_REG32(TP_TP_PCR_EXT_reg))) {
                PCR |= ((UINT64) 0x1) << 32;
        }
#endif
        if( (STC == pTp_drv->tp_pid[tp_id].pcr.old_stc) &&
            (PCR == pTp_drv->tp_pid[tp_id].pcr.old_pcr) ) {
                pTp_drv->tp_pid[tp_id].pcr.pcr_stc_same_count++;
                if(pTp_drv->tp_pid[tp_id].pcr.pcr_stc_same_count > 100) {
                        pTp_drv->tp_pid[tp_id].pcr.pcr_stc_same_count = 0;
                }
                return TPK_SUCCESS;
        }

        if(pTp_drv->tp_pid[tp_id].pcr.old_pcr == PCR) {
                return TPK_SUCCESS;
        }

        temp_pcr_diff = PCR - pTp_drv->tp_pid[tp_id].pcr.old_pcr;
        temp_stc_diff = STC - pTp_drv->tp_pid[tp_id].pcr.old_stc;

        tp_mask_print_emerg( TP_LOG_BLOCK_PCR, TP_LOG_LEVEL_DEBUG, "TP%u %lld\n", tp_id, temp_pcr_diff - temp_stc_diff);

        pTp_drv->tp_pid[tp_id].pcr.pcr_stc_same_count = 0;
        pTp_drv->tp_pid[tp_id].pcr.old_stc            = STC;
        pTp_drv->tp_pid[tp_id].pcr.old_pcr            = PCR;

#if 0
        if (STC > tp_osal_get_pts()) {
                TP_PID_WARNING("Update PCR failed, invalid STC(%llx) > PTS(%llx), ignore it.\n", STC, tp_osal_get_pts());
                ret = NEPTUNE_TP_FUNCTION_FAIL;
                goto end_proc;
        }
#endif

        pTp_drv->tp_pid[tp_id].pcr.LastPCR = PCR;
        pTp_drv->tp_pid[tp_id].pcr.LastSTC = STC;

        if(pTp_drv->tp_pid[tp_id].pcr.Base_Valid == 0) {
                /* TP misc 90K */
                WRITE_REG32(TP_TP_MISC_27M_CTRL_reg, TP_TP_MISC_27M_CTRL_latch_mask);
                ptrlo = READ_REG32(TP_TP_MISC_27M_CNT_reg);
                ptrhi = READ_REG32(TP_TP_MISC_27M_CNT_HIGH_reg);
                misc_value = ptrlo | (((UINT64)ptrhi) << 32);
                /* TP PCRA */
                ptrlo = READ_REG32(TP_TP_PCRA_90K_CNT_reg);
                ptrhi = READ_REG32(TP_TP_PCRA_90K_CNT_HIGH_reg);
                pcra_value = ptrlo | (((UINT64)ptrhi) << 32);
                /* TP PCRB */
                ptrlo = READ_REG32(TP_TP_PCRB_90K_CNT_reg);
                ptrhi = READ_REG32(TP_TP_PCRB_90K_CNT_HIGH_reg);
                pcrb_value = ptrlo | (((UINT64)ptrhi) << 32);

                tp_mask_print_emerg( TP_LOG_BLOCK_ALL, TP_LOG_LEVEL_DEBUG, "TP%u clk_src=%d misc=%llu pcra=%llu	pcrb=%llu PID=0x%x, PCR=%llu STC=%llu PCRBase=%llu STCBase=%llu\n",
                                     tp_id, pTp_drv->tp_pid[tp_id].pcr.clk_src, misc_value, pcra_value, pcrb_value,
                                     pTp_drv->tp_pid[tp_id].pcr.PID,
                                     pTp_drv->tp_pid[tp_id].pcr.LastPCR,
                                     pTp_drv->tp_pid[tp_id].pcr.LastSTC,
                                     pTp_drv->tp_pid[tp_id].pcr.PCRBase,
                                     pTp_drv->tp_pid[tp_id].pcr.STCBase);

                if(pTp_drv->tp_pid[tp_id].pcr.clk_src == MISC_90KHz)
                        stc_diff_value = STC - misc_value;
                else if(pTp_drv->tp_pid[tp_id].pcr.clk_src == TP_PCRA_LOCAL_90KHz)
                        stc_diff_value = STC - pcra_value;
                else
                        stc_diff_value = STC - pcrb_value;

                if( (stc_diff_value < STC_PCR_TOLERANCE) && (stc_diff_value > (-STC_PCR_TOLERANCE)) ) {
                        pTp_drv->tp_pid[tp_id].pcr.PCRBase      = PCR;
                        pTp_drv->tp_pid[tp_id].pcr.STCBase      = STC;
                        pTp_drv->tp_pid[tp_id].pcr.Base_Valid   = 1;
                        pTp_drv->tp_pid[tp_id].pcr.ClkSrcChange = 0;
                } else {
                        TP_DBG("TP%u stc diff =%lld \n", tp_id, stc_diff_value);
                }
        }

        if(tp_log_onoff && CHECK_LOG_BLOCK_MASK(TP_LOG_BLOCK_PCR)) {
                if (jiffies >= pTp_drv->tp_pid[tp_id].pcr.update_pcr_status_timeout) {
                        ptrlo = READ_REG32(TIMER_SCPU_CLK90K_LO_reg);
                        ptrhi = READ_REG32(TIMER_SCPU_CLK90K_HI_reg);
                        misc_value = ptrlo | (((UINT64)ptrhi) << 32);

                        ptrlo = READ_REG32(TP_TP_PCRA_90K_CNT_reg);
                        ptrhi = READ_REG32(TP_TP_PCRA_90K_CNT_HIGH_reg);
                        pcra_value = ptrlo | (((UINT64)ptrhi) << 32);

                        ptrlo = READ_REG32(TP_TP_PCRB_90K_CNT_reg);
                        ptrhi = READ_REG32(TP_TP_PCRB_90K_CNT_HIGH_reg);
                        pcrb_value = ptrlo | (((UINT64)ptrhi) << 32);

                        TP_DBG("TP%u clk_src=%d misc=%llu pcra=%llu  pcrb=%llu PID=0x%x, PCR=%llu STC=%llu PCRBase=%llu STCBase=%llu\n",
                               tp_id, pTp_drv->tp_pid[tp_id].pcr.clk_src, misc_value, pcra_value, pcrb_value,
                               pTp_drv->tp_pid[tp_id].pcr.PID,
                               pTp_drv->tp_pid[tp_id].pcr.LastPCR,
                               pTp_drv->tp_pid[tp_id].pcr.LastSTC,
                               pTp_drv->tp_pid[tp_id].pcr.PCRBase,
                               pTp_drv->tp_pid[tp_id].pcr.STCBase);
                        pTp_drv->tp_pid[tp_id].pcr.update_pcr_status_timeout = jiffies + HZ;
                }
        }
        return TPK_SUCCESS;
}

INT32 Tp_GetPCRTrackingStatus(TPK_TP_ENGINE_T tp_id,
                              UINT64* pPCR,
                              UINT64* pSTC,
                              UINT64* pPCRBase,
                              UINT64* pSTCBase)
{
        TPK_PCR_TRACKING_STATUS_T *pPCR_Status;

        /* check parameter */
        if((pPCR == NULL) ||
            (pSTC == NULL) ||
            (pPCRBase == NULL) ||
            (pSTCBase == NULL)) {
                TP_WARNING("bad parameter, pPCR=%p, pSTC=%p,pPCRBase=%p,pSTCBase=%p\n",
                           pPCR, pSTC, pPCRBase, pSTCBase);
                return TPK_BAD_PARAMETER;
        }
        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        pPCR_Status = &pTp_drv->tp_pid[tp_id].pcr;
        if((pPCR_Status->enable) && (pPCR_Status->Base_Valid)) {
                *pPCR     = pPCR_Status->LastPCR;
                *pSTC     = pPCR_Status->LastSTC;
                *pPCRBase = pPCR_Status->PCRBase;
                *pSTCBase = pPCR_Status->STCBase;
        } else {
                *pPCR     = 0;
                *pSTC     = 0;
                *pPCRBase = 0;
                *pSTCBase = 0;
        }

        if(pTp_drv->tp_pid[tp_id].pcr.ClkSrcChange == 1)
                return TPK_NOT_ENOUGH_RESOURCE;
        else
                return TPK_SUCCESS;
}

/*********************************

       Descramble API

********************************/
INT32 TP_SetCW(
        TPK_TP_ENGINE_T     tp_id,
        UINT8     id,
        UINT8     ofst,
        UINT32    cw_h,
        UINT32    cw_l
)
{
        unsigned char *cwHStrTmp = (unsigned char *)&cw_h;
        unsigned char *cwLStrTmp = (unsigned char *)&cw_l;
        unsigned char cwHStr[5];
        unsigned char cwLStr[5];

        unsigned char cwStr[9];

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_MAX_KEY_COUNT(id);

        id *= TPK_CW_LENGTH;
        id += ofst;

        memcpy(cwHStr, cwHStrTmp, 4);
        memcpy(cwLStr, cwLStrTmp, 4);

        memcpy(cwStr, cwLStr, 4);
        memcpy(cwStr + 4, cwHStr, 4);

        rtk_cw_set_cw("TP", id, cwStr, 8);

        TP_TRACE("TP%u Set CW (offset=%u, id=%u) cw_h= %08x cw_l=%08x  cw=%02x%02x%02x%02x%02x%02x%02x%02x\n",
                 tp_id, ofst, id, cw_h, cw_l,
                 cwStr[0], cwStr[1], cwStr[2], cwStr[3], cwStr[4], cwStr[5], cwStr[6], cwStr[7]);

        return TPK_SUCCESS;
}

INT32 Tp_TrackErrorPacket( TPK_TP_ENGINE_T tp_id, UINT64 *pPkt, UINT64 *pDropPkt, UINT64 *pErrPkt)
{
        UINT32 tp_cnt_reg;
        UINT32 tp_drp_cnt_reg;
        UINT32 tp_err_cnt_reg;

        TPK_TP_PKT_CNT_T *ppkt_cnt;

        /* check parameter */
        if((pPkt == NULL) ||
            (pDropPkt == NULL) ||
            (pErrPkt == NULL)) {
                TP_WARNING("bad parameter, pPkt=%p, pDropPkt=%p, pErrPkt=%p\n",
                           pPkt, pDropPkt, pErrPkt);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TP_COUNT(tp_id);
        CHECK_TP_STRUCTURE();

        switch(tp_id) {
                case TP_TP0:
                        tp_cnt_reg     = TP_TP_TF0_CNT_reg;
                        tp_drp_cnt_reg = TP_TP_TF0_DRP_CNT_reg;
                        tp_err_cnt_reg = TP_TP_TF0_ERR_CNT_reg;
                        break;
                case TP_TP1:
                        tp_cnt_reg     = TP_TP_TF1_CNT_reg;
                        tp_drp_cnt_reg = TP_TP_TF1_DRP_CNT_reg;
                        tp_err_cnt_reg = TP_TP_TF1_ERR_CNT_reg;
                        break;
                case TP_TP2:
                        tp_cnt_reg     = TP_TP_TF2_CNT_reg;
                        tp_drp_cnt_reg = TP_TP_TF2_DRP_CNT_reg;
                        tp_err_cnt_reg = TP_TP_TF2_ERR_CNT_reg;
                        break;
                case TP_TP3:
                        tp_cnt_reg     = TP_TP_TF3_CNT_reg;
                        tp_drp_cnt_reg = TP_TP_TF3_DRP_CNT_reg;
                        tp_err_cnt_reg = TP_TP_TF3_ERR_CNT_reg;
                        break;
                default:
                        TP_WARNING("unsupported tp_id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        ppkt_cnt = &pTp_drv->tp[tp_id].tp_pkt_cnt;

        ppkt_cnt->pkt        += READ_REG32(tp_cnt_reg);
        WRITE_REG32(tp_cnt_reg, _ZERO);
        ppkt_cnt->droppedPkt += READ_REG32(tp_drp_cnt_reg);
        WRITE_REG32(tp_drp_cnt_reg, _ZERO);
        ppkt_cnt->errorPkt   += READ_REG32(tp_err_cnt_reg);
        WRITE_REG32(tp_err_cnt_reg, _ZERO);

        *pPkt     = ppkt_cnt->pkt;
        *pDropPkt = ppkt_cnt->droppedPkt;
        *pErrPkt  = ppkt_cnt->errorPkt;

        return TPK_SUCCESS;
}

INT32 Tpp_TrackErrorPacket( TPK_TPP_ENGINE_T tpp_id, UINT64 *pPkt, UINT64 *pDropPkt)
{

        UINT32 tpp_cnt_reg;
        UINT32 tpp_drp_cnt_reg;

        TPK_TPP_PKT_CNT_T *ppkt_cnt;

        /* check parameter */
        if((pPkt == NULL) ||
            (pDropPkt == NULL) ) {
                TP_WARNING("bad parameter, pPkt=%p, pDropPkt=%p\n",
                           pPkt, pDropPkt);
                return TPK_BAD_PARAMETER;
        }

        CHECK_MAX_TPP_COUNT(tpp_id);
        CHECK_TP_STRUCTURE();

        switch(tpp_id) {
                case TP_TPP0:
                        tpp_cnt_reg     = TP_TP_TF0_P_CNT_reg;
                        tpp_drp_cnt_reg = TP_TP_TF0_P_DRP_CNT_reg;
                        break;
                case TP_TPP1:
                        tpp_cnt_reg     = TP_TP_TF1_P_CNT_reg;
                        tpp_drp_cnt_reg = TP_TP_TF1_P_DRP_CNT_reg;
                        break;
                case TP_TPP2:
                        tpp_cnt_reg     = TP_TP_TF2_P_CNT_reg;
                        tpp_drp_cnt_reg = TP_TP_TF2_P_DRP_CNT_reg;
                        break;
                default:
                        TP_WARNING("unsupported tpp_id=%d\n", tpp_id);
                        return TPK_BAD_PARAMETER;
        }

        ppkt_cnt = &pTp_drv->tpp[tpp_id].tpp_pkt_cnt;

        ppkt_cnt->pkt         += READ_REG32(tpp_cnt_reg);
        ppkt_cnt->droppedPkt  += READ_REG32(tpp_drp_cnt_reg);

        WRITE_REG32(tpp_cnt_reg, _ZERO);
        WRITE_REG32(tpp_drp_cnt_reg, _ZERO);

        *pPkt     = ppkt_cnt->pkt;
        *pDropPkt = ppkt_cnt->droppedPkt;

        return TPK_SUCCESS;
}



INT32 Tp_Update_PIDFilter_predes( TPK_TP_ENGINE_T tp_id,  UINT8 predes_value)
{
        UINT32 pid_cnt;
        INT32 result = TPK_BAD_PARAMETER;
        UINT16 i, pid_idx_reg = 0;
        TPK_PID_REG_PARAM_T pid_reg;

        CHECK_MAX_TP_COUNT(tp_id);

        switch(tp_id) {
                case TP_TP0:
                        pid_cnt = TP0_PID_FILTER_COUNT;
                        break;
                case TP_TP1:
                        pid_cnt = TP1_PID_FILTER_COUNT;
                        break;
                case TP_TP2:
                        pid_cnt = TP2_PID_FILTER_COUNT;
                        break;
                case TP_TP3:
                        pid_cnt = TP2_PID_FILTER_COUNT;
                        break;
                default:
                        TP_WARNING("define MAX_TP_COUNT counter error (%u)\n", MAX_TP_COUNT);
                        pid_cnt = 0;
                        break;
        }

        for( i = 0; i < pid_cnt; i++) {

                switch(tp_id) {
                        case TP_TP0:
                                pid_idx_reg = i;
                                break;
                        case TP_TP1:
                                pid_idx_reg = i + TP0_PID_FILTER_COUNT;
                                break;
                        case TP_TP2:
                                pid_idx_reg = i + TP0_PID_FILTER_COUNT + TP1_PID_FILTER_COUNT;
                                break;
                        case TP_TP3:
                                pid_idx_reg = i + TP0_PID_FILTER_COUNT + TP1_PID_FILTER_COUNT + TP2_PID_FILTER_COUNT;
                                break;
                        default:
                                TP_WARNING("unsupported tp_id=%d\n", tp_id);
                                goto PID_ERROR;
                }

                result = Tp_GetPidParam(pid_idx_reg, &pid_reg);
                if(result != TPK_SUCCESS) {
                        TP_WARNING("get pid reg error\n");
                        goto PID_ERROR;
                }

                if( (pid_reg.v == 1) && (pid_reg.sec_en == 1)) {
                        pid_reg.pre_des = predes_value;
                        result = Tp_SetPidParam(pid_idx_reg, pid_reg);
                        if(result != TPK_SUCCESS) {
                                TP_WARNING("set pid reg error\n");
                                goto PID_ERROR;
                        }
                }
        }

PID_ERROR:
        return result;
}

INT32 Tp_is_SupportPatternSearch( TPK_TP_ENGINE_T tp_id )
{
        if( tp_id == TP_TP0 )
                return TPK_SUCCESS;
        if( tp_id == TP_TP1 )
                return TPK_SUCCESS;
        return TPK_NOT_SUPPORT;
}

INT32 Tp_SetPatternSearchInfoBuffer( TPK_TP_ENGINE_T tp_id, UINT8* pPhyAddr, UINT8* pVirAddr, UINT32 size, UINT8* pSharedRP, UINT8* pSharedWP)
{
        UINT8 buf_idx;
        INT32 ret;
        TP_BUFFER_PARAM_T buf_param;

        pTp_drv->tp[tp_id].start_code_search_buffer.BufSize   = size;
        pTp_drv->tp[tp_id].start_code_search_buffer.BaseVir   = (UADDRESS)pVirAddr;
        pTp_drv->tp[tp_id].start_code_search_buffer.LimitVir  = (UADDRESS)(pVirAddr + size);
        pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy   = (UADDRESS)pPhyAddr;
        pTp_drv->tp[tp_id].start_code_search_buffer.LimitPhy  = (UADDRESS)(pPhyAddr + size);
        pTp_drv->tp[tp_id].start_code_search_buffer.RP        = (UADDRESS)pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy;
        pTp_drv->tp[tp_id].start_code_search_buffer.WP        = (UADDRESS)pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy;
        pTp_drv->tp[tp_id].start_code_search_buffer.RP_Connect_cnt = START_CODE_PACK_BUFFER_RP_CONNECT;
        pTp_drv->tp[tp_id].start_code_search_buffer.RP_Connect[START_CODE_PACK_BUFFER_RP] = pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy;
        pTp_drv->tp[tp_id].start_code_search_buffer.bock_size = START_CODE_PACK_BUFFER_BLOCK_SIZE;
        pTp_drv->tp[tp_id].start_code_search_buffer.inited    = 1;

        pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.pRP    = (UADDRESS*)pSharedRP;
        pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.pWP    = (UADDRESS*)pSharedWP;
        pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.inited = 1;

        switch(tp_id) {
                case TP_TP0:
                        buf_idx = TP0_START_CODE_PACK;
                        break;
                case TP_TP1:
                        buf_idx = TP1_START_CODE_PACK;
                        break;
                default:
                        TP_WARNING("unsupported id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        buf_param.Base  = pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy;
        buf_param.Limit = pTp_drv->tp[tp_id].start_code_search_buffer.LimitPhy;
        buf_param.RP    = pTp_drv->tp[tp_id].start_code_search_buffer.RP;
        buf_param.WP    = pTp_drv->tp[tp_id].start_code_search_buffer.WP;

        ret = Tp_Set_Buffer(buf_idx, buf_param, BUFFER_WRITE_MASK_NONE);
        return TPK_SUCCESS;
}

INT32 Tp_SetPatternSearchPID( TPK_TP_ENGINE_T tp_id, UINT16 PID)
{
        REGADDR tp_start_code_ctrl_vaddr_reg;
        tp_start_code_ctrl_tp0_RBUS tp_start_code_ctrl;
        UINT8 buf_idx;

        switch(tp_id) {
                case TP_TP0:
                        tp_start_code_ctrl_vaddr_reg = TP_START_CODE_CTRL_TP0_reg;
                        break;

                case TP_TP1:
                        tp_start_code_ctrl_vaddr_reg = TP_START_CODE_CTRL_TP1_reg;
                        break;

                default:
                        TP_WARNING("unsupported PatternSearch id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        switch(tp_id) {
                case TP_TP0:
                        buf_idx = TP0_START_CODE_PACK;
                        break;
                case TP_TP1:
                        buf_idx = TP1_START_CODE_PACK;
                        break;
                default:
                        TP_WARNING("unsupported id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        tp_start_code_ctrl.regValue = READ_REG32(tp_start_code_ctrl_vaddr_reg);
        tp_start_code_ctrl.info_q   = buf_idx;
        tp_start_code_ctrl.pid      = PID;
        WRITE_REG32(tp_start_code_ctrl_vaddr_reg, tp_start_code_ctrl.regValue);

        pTp_drv->tp[tp_id].useTPStartCodeSearch = 1;


        return TPK_SUCCESS;
}

INT32 Tp_SetPatternSearchEnable( TPK_TP_ENGINE_T tp_id, UINT8 enable_value )
{
        tp_start_code_tp0_RBUS tp_start_code;
        tp_start_code_ctrl_tp0_RBUS tp_start_code_ctrl;
        REGADDR tp_start_code_vaddr_reg;
        REGADDR tp_start_code_ctrl_vaddr_reg;
        TP_BUFFER_PARAM_T buf_param;
        UINT8 buf_idx;

        switch (tp_id) {
                case TP_TP0:
                        tp_start_code_vaddr_reg      = TP_START_CODE_TP0_reg;
                        tp_start_code_ctrl_vaddr_reg = TP_START_CODE_CTRL_TP0_reg;
                        buf_idx = TP0_START_CODE_PACK;
                        break;

                case TP_TP1:
                        tp_start_code_vaddr_reg      = TP_START_CODE_TP1_reg;
                        tp_start_code_ctrl_vaddr_reg = TP_START_CODE_CTRL_TP1_reg;
                        buf_idx = TP1_START_CODE_PACK;
                        break;

                default:
                        TP_WARNING("unsupported PatternSearch id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        pTp_drv->tp[tp_id].show_startcode_info_cnt = 0;

        tp_start_code_ctrl.regValue = READ_REG32(tp_start_code_ctrl_vaddr_reg);
        tp_start_code.regValue = READ_REG32(tp_start_code_vaddr_reg);

        //start code fifo clear
        if (tp_start_code_ctrl.fifo_cnt > 0) {
                tp_start_code.en = 1;
                WRITE_REG32(tp_start_code_vaddr_reg, tp_start_code.regValue);

                tp_start_code.regValue = READ_REG32(tp_start_code_vaddr_reg);
                tp_start_code.dma_flush = 1;
                WRITE_REG32(tp_start_code_vaddr_reg, tp_start_code.regValue);
                udelay(1);
                //for test
                tp_start_code.regValue = READ_REG32(tp_start_code_vaddr_reg);
                TP_DBG("tp=%d  start code flush finished ,check dma_flush =%d\n", tp_id, tp_start_code.dma_flush);
        }

        if (enable_value == 1) {
                //start code buffer clear
                buf_param.Base  = pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy;
                buf_param.Limit = pTp_drv->tp[tp_id].start_code_search_buffer.LimitPhy;
                buf_param.RP    = pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy;
                buf_param.WP    = pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy;

                Tp_Set_Buffer(buf_idx, buf_param, BUFFER_WRITE_MASK_NONE);
                *pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.pRP = buf_param.WP;
                *pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.pWP = buf_param.WP;

                //sw reset start code
                tp_start_code.en = 0;
                WRITE_REG32(tp_start_code_vaddr_reg, tp_start_code.regValue);

                tp_start_code_ctrl.regValue = READ_REG32(tp_start_code_ctrl_vaddr_reg);
                tp_start_code_ctrl.sw_rst = 1;
                WRITE_REG32(tp_start_code_ctrl_vaddr_reg, tp_start_code_ctrl.regValue);
                udelay(1);
                tp_start_code_ctrl.sw_rst = 0;
                WRITE_REG32(tp_start_code_ctrl_vaddr_reg, tp_start_code_ctrl.regValue);
                udelay(10);

        }



#if 0
        if (enable_value == 1) {
                UINT32 retry_count = 0;

#if 1
                tp_start_code.regValue = READ_REG32(tp_start_code_vaddr_reg);
                tp_start_code.en = 1;
                WRITE_REG32(tp_start_code_vaddr_reg, tp_start_code.regValue);
                udelay(1);

                tp_start_code.regValue = READ_REG32(tp_start_code_vaddr_reg);
                tp_start_code.dma_flush = 1;
                WRITE_REG32(tp_start_code_vaddr_reg, tp_start_code.regValue);
                udelay(1);

                do {
                        tp_start_code.regValue = READ_REG32(tp_start_code_vaddr_reg);
                        msleep(1);
                        retry_count++;
                        if (retry_count >= 5) {
                                TP_WARNING("tp=%d flush start code DMA data time out\n", tp_id);
                                break;
                        }

                } while (tp_start_code.dma_flush == 1);
#endif
                tp_start_code.regValue = READ_REG32(tp_start_code_vaddr_reg);
                tp_start_code.en = 0;
                WRITE_REG32(tp_start_code_vaddr_reg, tp_start_code.regValue);
                udelay(10);

#if 1
                TP_DBG("tp=%d flush start code DMA data retry_count=%d\n", tp_id, retry_count);

                buf_param.Base  = pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy;
                buf_param.Limit = pTp_drv->tp[tp_id].start_code_search_buffer.LimitPhy;
                buf_param.RP    = pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy;
                buf_param.WP    = pTp_drv->tp[tp_id].start_code_search_buffer.BasePhy;

                Tp_Set_Buffer(buf_idx, buf_param, BUFFER_WRITE_MASK_NONE);
                *pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.pRP = buf_param.WP;
                *pTp_drv->tp[tp_id].Shared_RWPtr_start_code_search.pWP = buf_param.WP;
#endif

                tp_start_code_ctrl_vaddr.regValue = READ_REG32(tp_start_code_ctrl_vaddr_reg);
                tp_start_code_ctrl_vaddr.sw_rst = 0;
                WRITE_REG32(tp_start_code_ctrl_vaddr_reg, tp_start_code_ctrl_vaddr.regValue);
                udelay(10);
                tp_start_code_ctrl_vaddr.sw_rst = 1;
                WRITE_REG32(tp_start_code_ctrl_vaddr_reg, tp_start_code_ctrl_vaddr.regValue);
                udelay(1);
                tp_start_code_ctrl_vaddr.sw_rst = 0;
                WRITE_REG32(tp_start_code_ctrl_vaddr_reg, tp_start_code_ctrl_vaddr.regValue);
                udelay(10);
        } else {
                tp_start_code.regValue = READ_REG32(tp_start_code_vaddr_reg);
                tp_start_code.dma_flush = 1;
                WRITE_REG32(tp_start_code_vaddr_reg, tp_start_code.regValue);
                udelay(1);

                pTp_drv->tp[tp_id].start_code_search_buffer.inited        = 0;
                //pTp_drv->tp[tp_id].useTPStartCodeSearch =0;
        }
#endif

        tp_start_code.regValue  = READ_REG32(tp_start_code_vaddr_reg);
        tp_start_code.req_level = 8;
        tp_start_code.dma_flush = 0;
        tp_start_code.pattern   = 0x000001;
        tp_start_code.en        = enable_value;
        WRITE_REG32(tp_start_code_vaddr_reg, tp_start_code.regValue);

        TP_DBG("Tp_SetPatternSearchEnable tp_id=%d enable_value=%d\n", tp_id, enable_value);

        return TPK_SUCCESS;
}


/* enable:1, sdisable:0 MTP frame rate control*/
INT32 Tp_FRC_Enable( TPK_TP_ENGINE_T tp_id, BOOL enable )
{

        tp_fr_ctrl_RBUS fr_ctrl;

        fr_ctrl.regValue = READ_REG32(TP_FR_CTRL_reg);

        switch(tp_id) {
                case TP_TP0:
                        fr_ctrl.tp0_en = enable;
                        break;
                case TP_TP1:
                        fr_ctrl.tp1_en = enable;
                        break;
                case TP_TP2:
                        fr_ctrl.tp2_en = enable;
                        break;
                case TP_TP3:
                        fr_ctrl.tp3_en = enable;
                        break;
                default:
                        TP_WARNING("bad parameter - tp_id:%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        WRITE_REG32(TP_FR_CTRL_reg, fr_ctrl.regValue);

        return TPK_SUCCESS;
}

/* set the rate of FRC */
INT32 Tp_FRC_SetRate( TPK_TP_ENGINE_T tp_id, TPK_FRC_RATE_T rate )
{

        tp_fr_ctrl_RBUS fr_ctrl;

        fr_ctrl.regValue = READ_REG32(TP_FR_CTRL_reg);

        switch(tp_id) {
                case TP_TP0:
                        fr_ctrl.tp0_rate = rate;
                        break;
                case TP_TP1:
                        fr_ctrl.tp1_rate = rate;
                        break;
                case TP_TP2:
                        fr_ctrl.tp2_rate = rate;
                        break;
                case TP_TP3:
                        fr_ctrl.tp3_rate = rate;
                        break;
                default:
                        TP_WARNING("bad parameter - tp_id:%d, rate:%d\n", tp_id, rate);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        WRITE_REG32(TP_FR_CTRL_reg, fr_ctrl.regValue);

        return TPK_SUCCESS;
}

/*
 * Set the prefix in front of the incoming 188B TSP and
 * set the FRC reference CLK.
 */
INT32 Tp_FRC_SetPrefix( TPK_TP_ENGINE_T tp_id, TPK_FRC_PREFIX_T prefix_sel, UINT32 meta_data)
{
        /* TODO: Modify this function in Mac6 */

        tp_prefix_ctrl_RBUS prefix_ctrl;

        prefix_ctrl.regValue = READ_REG32(TP_PREFIX_CTRL_reg);

        switch(tp_id) {
                case TP_TP0:
                        if ( prefix_sel == TP_FRC_KEPP )
                                prefix_ctrl.tp0_keep = 1;
                        else
                        {
                                prefix_ctrl.tp0_keep = 0;
                                prefix_ctrl.tp0_sel  = prefix_sel;
                        }
                        break;
                case TP_TP1:
                        if ( prefix_sel == TP_FRC_KEPP )
                                prefix_ctrl.tp1_keep = 1;
                        else
                        {
                                prefix_ctrl.tp1_keep = 0;
                                prefix_ctrl.tp1_sel = prefix_sel;
                        }
                        break;
                case TP_TP2:
                        if ( prefix_sel == TP_FRC_KEPP )
                                prefix_ctrl.tp2_keep = 1;
                        else
                        {
                                prefix_ctrl.tp2_keep = 0;
                                prefix_ctrl.tp2_sel = prefix_sel;
                        }
                        break;
                case TP_TP3:
                        if ( prefix_sel == TP_FRC_KEPP )
                                prefix_ctrl.tp3_keep = 1;
                        else
                        {
                                prefix_ctrl.tp3_keep = 0;
                                prefix_ctrl.tp3_sel = prefix_sel;
                        }
                        break;
                default:
                        TP_WARNING("bad parameter - tp_id:%d, prefix_sel:%d\n", tp_id, prefix_sel);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        if (prefix_sel == TP_FRC_META_DATA && meta_data) {
                WRITE_REG32(TP_PREFIX_DATA1_reg, meta_data);
        }
        TP_WARNING("prefix_sel=%d ,prefix_ctrl.regValue:%08x\n", prefix_sel, prefix_ctrl.regValue);
        WRITE_REG32(TP_PREFIX_CTRL_reg, prefix_ctrl.regValue);

        WRITE_REG32(TP_PREFIX_CTRL_reg, prefix_ctrl.regValue);

        return TPK_SUCCESS;
}

/* enabe/disable TP engine */
INT32 Tp_ENG_FrameEnable( TPK_TP_ENGINE_T tp_id, BOOL enable )
{
        REGADDR fram_reg;
        tp_tp_tf0_frmcfg_RBUS tp_frmcfg;

        switch(tp_id) {
                case TP_TP0:
                        fram_reg = TP_TP_TF0_FRMCFG_reg;
                        break;
                case TP_TP1:
                        fram_reg = TP_TP_TF1_FRMCFG_reg;
                        break;
                case TP_TP2:
                        fram_reg = TP_TP_TF2_FRMCFG_reg;
                        break;
                case TP_TP3:
                        fram_reg = TP_TP_TF3_FRMCFG_reg;
                        break;
                default:
                        TP_WARNING("bad parameter - tp_id:%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        tp_frmcfg.regValue = READ_REG32(fram_reg);
        tp_frmcfg.frm_en = enable;
        WRITE_REG32(fram_reg, tp_frmcfg.regValue);

        return TPK_SUCCESS;
}

/* Set TP Eng InputInterface serial/parallel */
INT32 Tp_ENG_SetInputInterface( TPK_TP_ENGINE_T tp_id, TP_INPUT_INTERFACE_PARAM_T tp_if_param )
{
        REGADDR fram_reg;
        tp_tp_tf0_frmcfg_RBUS tp_frmcfg;

        switch(tp_id) {
                case TP_TP0:
                        fram_reg = TP_TP_TF0_FRMCFG_reg;
                        break;
                case TP_TP1:
                        fram_reg = TP_TP_TF1_FRMCFG_reg;
                        break;
                case TP_TP2:
                        fram_reg = TP_TP_TF2_FRMCFG_reg;
                        break;
                case TP_TP3:
                        fram_reg = TP_TP_TF3_FRMCFG_reg;
                        break;
                default:
                        TP_WARNING("bad parameter - tp_id:%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        tp_frmcfg.regValue    = READ_REG32(fram_reg);
        tp_frmcfg.serial      = tp_if_param.serial;
        tp_frmcfg.data_order  = tp_if_param.data_order;
        tp_frmcfg.datapin     = tp_if_param.datapin;
        tp_frmcfg.sync_byte   = tp_if_param.sync_byte;
        tp_frmcfg.packet_size = tp_if_param.packet_size;
        WRITE_REG32(fram_reg, tp_frmcfg.regValue);

        return TPK_SUCCESS;

}

INT32 Tp_ENG_TwoBitsModeEnable( TPK_TP_ENGINE_T tp_id, BOOL enable )
{
        tp_tp_tf0_cntl_RBUS tp_cntl;

        /* set two bit to default setting, all 0*/
        tp_cntl.regValue = 0;
        tp_cntl.two_bit_reverse = 1;
        tp_cntl.two_bit_sel_h = 1;
        tp_cntl.two_bit_sel_l = 1;
        Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, 0);

        tp_cntl.regValue = 0;
        tp_cntl.two_bit = 1;
        Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, enable ? 1 : 0);

        return TPK_SUCCESS;
}

INT32 Tp_ENG_RawModeEnable( TPK_TP_ENGINE_T tp_id, BOOL enable)
{
        tp_tp_tf0_cntl_RBUS tp_cntl;


        tp_cntl.regValue = 0;
        tp_cntl.dir_dma = 1;
        Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, enable ? 1 : 0);

        /*clear buf_rdy_ctl & pid_en in raw mode*/

        tp_cntl.regValue = 0;
        tp_cntl.pid_en = 1;
        tp_cntl.buf_rdy_ctl = 1;

        tp_cntl.tp_err_fix_en = 1;
        tp_cntl.null_en = 1;
        tp_cntl.trerr_en = 1;
        tp_cntl.sync_en = 1;
        Tp_SetTpCtrlReg(tp_id, tp_cntl.regValue, enable ? 0 : 1);

        return TPK_SUCCESS;
}

INT32 Tp_ENG_SetSyncReplace( TPK_TP_ENGINE_T tp_id, UINT8 sync_byte )
{
        tp_tp_sync_rplace_RBUS sync_rplace;

        sync_rplace.regValue = READ_REG32(TP_TP_SYNC_RPLACE_reg);

        switch (tp_id) {
                case TP_TP0:
                        sync_rplace.tp0 = sync_byte;
                        break;
                case TP_TP1:
                        sync_rplace.tp1 = sync_byte;
                        break;
                case TP_TP2:
                        sync_rplace.tp2 = sync_byte;
                        break;
                case TP_TP3:
                        sync_rplace.tp3 = sync_byte;
                        break;
                default:
                        TP_WARNING("bad parameter - tp_id:%d, sync_byte:%d\n", tp_id, sync_byte);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        WRITE_REG32(TP_TP_SYNC_RPLACE_reg, sync_rplace.regValue);

        return TPK_SUCCESS;
}


TP_REGISTER const tp_register_pid_filter[] = { {"TP_PID_CTRL ", TP_TP_PID_CTRL_reg},
        {"TP_PID_DATA ", TP_TP_PID_DATA_reg},
        {"TP_PID_DATA2", TP_TP_PID_DATA2_reg},
        {"TP_PID_DATA3", TP_TP_PID_DATA3_reg}
};

TP_REGISTER const tp_register_sec_filter[] = { {"TP_SEC_CTRL ", TP_TP_SEC_CTRL_reg},
        {"TP_SEC_DATA0", TP_TP_SEC_DATA0_reg},
        {"TP_SEC_DATA1", TP_TP_SEC_DATA1_reg},
        {"TP_SEC_DATA2", TP_TP_SEC_DATA2_reg},
        {"TP_SEC_DATA3", TP_TP_SEC_DATA3_reg},
        {"TP_SEC_DATA4", TP_TP_SEC_DATA4_reg},
        {"TP_SEC_DATA5", TP_TP_SEC_DATA5_reg},
        {"TP_SEC_DATA6", TP_TP_SEC_DATA6_reg},
        {"TP_SEC_DATA7", TP_TP_SEC_DATA7_reg},
        {"TP_SEC_DATA8", TP_TP_SEC_DATA8_reg},
        {"TP_SEC_DATA9", TP_TP_SEC_DATA9_reg}
};

TP_REGISTER const tp_register_key_info[] = { {"TP_KEY_CTRL ", TP_TP_KEY_CTRL_reg},
        {"TP_KEY_INFO ", TP_TP_KEY_INFO_0_reg}
};

TP_REGISTER const tp_register_tp_ring[] = { {"TP_RING_CTRL ", TP_TP_RING_CTRL_reg},
        {"TP_RING_LIMIT", TP_TP_RING_LIMIT_reg},
        {"TP_RING_BASE ", TP_TP_RING_BASE_reg},
        {"TP_RING_RP   ", TP_TP_RING_RP_reg},
        {"TP_RING_WP   ", TP_TP_RING_WP_reg}
};

TP_REGISTER const tp_register_tpp_ring[] = { {"TP_P_RING_CTRL ", TP_TP_P_RING_CTRL_reg},
        {"TP_P_RING_LIMIT", TP_TP_P_RING_LIMIT_reg},
        {"TP_P_RING_BASE ", TP_TP_P_RING_BASE_reg},
        {"TP_P_RING_RP   ", TP_TP_P_RING_RP_reg},
        {"TP_P_RING_WP   ", TP_TP_P_RING_WP_reg}
};

TP_REGISTER const tp_register_list[] = {
        {"TP_TF0_CNTL           ", TP_TP_TF0_CNTL_reg},
        {"TP_TF0_STRM_ID_0      ", TP_TP_TF0_STRM_ID_0_reg},
        {"TP_TF0_STRM_ID_1      ", TP_TP_TF0_STRM_ID_1_reg},
        {"TP_TF0_STRM_ID_2      ", TP_TP_TF0_STRM_ID_2_reg},
        {"TP_TF0_STRM_ID_3      ", TP_TP_TF0_STRM_ID_3_reg},
        {"TP_TF0_STRM_VAL       ", TP_TP_TF0_STRM_VAL_reg},
        {"TP_TF0_CNT            ", TP_TP_TF0_CNT_reg},
        {"TP_TF0_DRP_CNT        ", TP_TP_TF0_DRP_CNT_reg},
        {"TP_TF0_ERR_CNT        ", TP_TP_TF0_ERR_CNT_reg},
        {"TP_TF0_FRMCFG         ", TP_TP_TF0_FRMCFG_reg},
        {"TP_TF0_INT            ", TP_TP_TF0_INT_reg},
        {"TP_TF0_INT_EN         ", TP_TP_TF0_INT_EN_reg},
        {"TP_TF1_CNTL           ", TP_TP_TF1_CNTL_reg},
        {"TP_TF1_STRM_ID_0      ", TP_TP_TF1_STRM_ID_0_reg},
        {"TP_TF1_STRM_ID_1      ", TP_TP_TF1_STRM_ID_1_reg},
        {"TP_TF1_STRM_ID_2      ", TP_TP_TF1_STRM_ID_2_reg},
        {"TP_TF1_STRM_ID_3      ", TP_TP_TF1_STRM_ID_3_reg},
        {"TP_TF1_STRM_VAL       ", TP_TP_TF1_STRM_VAL_reg},
        {"TP_TF1_CNT            ", TP_TP_TF1_CNT_reg},
        {"TP_TF1_DRP_CNT        ", TP_TP_TF1_DRP_CNT_reg},
        {"TP_TF1_ERR_CNT        ", TP_TP_TF1_ERR_CNT_reg},
        {"TP_TF1_FRMCFG         ", TP_TP_TF1_FRMCFG_reg},
        {"TP_TF1_INT            ", TP_TP_TF1_INT_reg},
        {"TP_TF1_INT_EN         ", TP_TP_TF1_INT_EN_reg},
        {"TP_TF2_CNTL           ", TP_TP_TF2_CNTL_reg},
        {"TP_TF2_STRM_ID_0      ", TP_TP_TF2_STRM_ID_0_reg},
        {"TP_TF2_STRM_ID_1      ", TP_TP_TF2_STRM_ID_1_reg},
        {"TP_TF2_STRM_ID_2      ", TP_TP_TF2_STRM_ID_2_reg},
        {"TP_TF2_STRM_ID_3      ", TP_TP_TF2_STRM_ID_3_reg},
        {"TP_TF2_STRM_VAL       ", TP_TP_TF2_STRM_VAL_reg},
        {"TP_TF2_CNT            ", TP_TP_TF2_CNT_reg},
        {"TP_TF2_DRP_CNT        ", TP_TP_TF2_DRP_CNT_reg},
        {"TP_TF2_ERR_CNT        ", TP_TP_TF2_ERR_CNT_reg},
        {"TP_TF2_FRMCFG         ", TP_TP_TF2_FRMCFG_reg},
        {"TP_TF2_INT            ", TP_TP_TF2_INT_reg},
        {"TP_TF2_INT_EN         ", TP_TP_TF2_INT_EN_reg},
        {"TP_TF_OUT_FRMCFG      ", TP_TP_TF_OUT_FRMCFG_reg},
        {"TP_OUT_CTRL           ", TP_TP_OUT_CTRL_reg},
        {"TP_PCRA_90K_CNT_HIGH  ", TP_TP_PCRA_90K_CNT_HIGH_reg},
        {"TP_PCRA_90K_CNT       ", TP_TP_PCRA_90K_CNT_reg},
        {"TP_PCRB_90K_CNT_HIGH  ", TP_TP_PCRB_90K_CNT_HIGH_reg},
        {"TP_PCRB_90K_CNT       ", TP_TP_PCRB_90K_CNT_reg},
        {"TP0_PCR_CTL           ", TP_TP0_PCR_CTL_reg},
        {"TP1_PCR_CTL           ", TP_TP1_PCR_CTL_reg},
        {"TP2_PCR_CTL           ", TP_TP2_PCR_CTL_reg},
        {"TP_PCR_LATCH          ", TP_TP_PCR_LATCH_reg},
        {"TP_PCR_BASE           ", TP_TP_PCR_BASE_reg},
        {"TP_PCR_EXT            ", TP_TP_PCR_EXT_reg},
        {"TP_PCR_SYSTEM_0       ", TP_TP_PCR_SYSTEM_0_reg},
        {"TP_PCR_SYSTEM_1       ", TP_TP_PCR_SYSTEM_1_reg},
        {"TP_SYNC_RPLACE        ", TP_TP_SYNC_RPLACE_reg},
        {"TP_PID_PART           ", TP_TP_PID_PART_reg},
        {"TP_TP0_DES_CNTL       ", TP_TP_TP0_DES_CNTL_reg},
        {"TP_TP1_DES_CNTL       ", TP_TP_TP1_DES_CNTL_reg},
        {"TP_TP2_DES_CNTL       ", TP_TP_TP2_DES_CNTL_reg},
        {"TP_CRC_INIT           ", TP_TP_CRC_INIT_reg},
        {"TP_THRESHOLD          ", TP_TP_THRESHOLD_reg},
        {"TP_FULLNESS           ", TP_TP_FULLNESS_reg},
        {"TP_RING_AVAIL_INT_0   ", TP_TP_RING_AVAIL_INT_0_reg},
        {"TP_RING_AVAIL_INT_1   ", TP_TP_RING_AVAIL_INT_1_reg},
        {"TP_RING_FULL_INT_0    ", TP_TP_RING_FULL_INT_0_reg},
        {"TP_RING_FULL_INT_1    ", TP_TP_RING_FULL_INT_1_reg},
        {"TP_RING_AVAIL_INT_EN_0", TP_TP_RING_AVAIL_INT_EN_0_reg},
        {"TP_RING_AVAIL_INT_EN_1", TP_TP_RING_AVAIL_INT_EN_1_reg},
        {"TP_RING_FULL_INT_EN_0 ", TP_TP_RING_FULL_INT_EN_0_reg},
        {"TP_RING_FULL_INT_EN_1 ", TP_TP_RING_FULL_INT_EN_1_reg},
        {"TP_SYNC_POS           ", TP_TP_SYNC_POS_reg},
        {"TP_DMY_A              ", TP_TP_DMY_A_reg},
        {"TP_DMY_B              ", TP_TP_DMY_B_reg},
        {"BIST_MODE             ", TP_TP_BIST_MODE_reg},
        {"BIST_DONE             ", TP_tp_bist_done_reg},
        {"BIST_FAIL_GROUP       ", TP_tp_bist_fail_group_reg},
        {"BIST_FAIL             ", TP_tp_bist_fail_reg},
        {"DRF_MODE              ", TP_TP_DRF_MODE_reg},
        {"DRF_RESUME            ", TP_tp_drf_resume_reg},
        {"DRF_DONE              ", TP_tp_drf_done_reg},
        {"DRF_PAUSE             ", TP_tp_drf_pause_reg},
        {"DRF_FAIL_GROUP        ", TP_tp_drf_fail_group_reg},
        {"DRF_FAIL              ", TP_tp_drf_fail_reg},
        {"BIST_DVSE             ", TP_tp_bist_dvse_reg},
        {"BIST_DVS_0            ", TP_tp_bist_dvs_0_reg},
        {"BIST_DVS_1            ", TP_tp_bist_dvs_1_reg},
        {"TP_DEBUG              ", TP_TP_DEBUG_reg},
        {"TP0_M2M_RING_LIMIT    ", TP_TP0_M2M_RING_LIMIT_reg},
        {"TP0_M2M_RING_BASE     ", TP_TP0_M2M_RING_BASE_reg},
        {"TP0_M2M_RING_RP       ", TP_TP0_M2M_RING_RP_reg},
        {"TP0_M2M_RING_WP       ", TP_TP0_M2M_RING_WP_reg},
        {"TP0_M2M_RING_CTRL     ", TP_TP0_M2M_RING_CTRL_reg},
        {"TP1_M2M_RING_LIMIT    ", TP_TP1_M2M_RING_LIMIT_reg},
        {"TP1_M2M_RING_BASE     ", TP_TP1_M2M_RING_BASE_reg},
        {"TP1_M2M_RING_RP       ", TP_TP1_M2M_RING_RP_reg},
        {"TP1_M2M_RING_WP       ", TP_TP1_M2M_RING_WP_reg},
        {"TP1_M2M_RING_CTRL     ", TP_TP1_M2M_RING_CTRL_reg},
        {"TP2_M2M_RING_LIMIT    ", TP_TP2_M2M_RING_LIMIT_reg},
        {"TP2_M2M_RING_BASE     ", TP_TP2_M2M_RING_BASE_reg},
        {"TP2_M2M_RING_RP       ", TP_TP2_M2M_RING_RP_reg},
        {"TP2_M2M_RING_WP       ", TP_TP2_M2M_RING_WP_reg},
        {"TP2_M2M_RING_CTRL     ", TP_TP2_M2M_RING_CTRL_reg},
        {"TP0_P_M2M_RING_LIMIT  ", TP_TP0_P_M2M_RING_LIMIT_reg},
        {"TP0_P_M2M_RING_BASE   ", TP_TP0_P_M2M_RING_BASE_reg},
        {"TP0_P_M2M_RING_RP     ", TP_TP0_P_M2M_RING_RP_reg},
        {"TP0_P_M2M_RING_WP     ", TP_TP0_P_M2M_RING_WP_reg},
        {"TP0_P_M2M_RING_CTRL   ", TP_TP0_P_M2M_RING_CTRL_reg},
        {"TP1_P_M2M_RING_LIMIT  ", TP_TP1_P_M2M_RING_LIMIT_reg},
        {"TP1_P_M2M_RING_BASE   ", TP_TP1_P_M2M_RING_BASE_reg},
        {"TP1_P_M2M_RING_RP     ", TP_TP1_P_M2M_RING_RP_reg},
        {"TP1_P_M2M_RING_WP     ", TP_TP1_P_M2M_RING_WP_reg},
        {"TP1_P_M2M_RING_CTRL   ", TP_TP1_P_M2M_RING_CTRL_reg},
        {"TP2_P_M2M_RING_LIMIT  ", TP_TP2_P_M2M_RING_LIMIT_reg},
        {"TP2_P_M2M_RING_BASE   ", TP_TP2_P_M2M_RING_BASE_reg},
        {"TP2_P_M2M_RING_RP     ", TP_TP2_P_M2M_RING_RP_reg},
        {"TP2_P_M2M_RING_WP     ", TP_TP2_P_M2M_RING_WP_reg},
        {"TP2_P_M2M_RING_CTRL   ", TP_TP2_P_M2M_RING_CTRL_reg},
        {"TP_TF0_P_CNTL         ", TP_TP_TF0_P_CNTL_reg},
        {"TP_TF0_P_CNT          ", TP_TP_TF0_P_CNT_reg},
        {"TP_TF0_P_DRP_CNT      ", TP_TP_TF0_P_DRP_CNT_reg},
        {"TP_TF0_P_FRMCFG       ", TP_TP_TF0_P_FRMCFG_reg},
        {"TP_TF0_P_INT          ", TP_TP_TF0_P_INT_reg},
        {"TP_TF0_P_INT_EN       ", TP_TP_TF0_P_INT_EN_reg},
        {"TP_TF1_P_CNTL         ", TP_TP_TF1_P_CNTL_reg},
        {"TP_TF1_P_CNT          ", TP_TP_TF1_P_CNT_reg},
        {"TP_TF1_P_DRP_CNT      ", TP_TP_TF1_P_DRP_CNT_reg},
        {"TP_TF1_P_FRMCFG       ", TP_TP_TF1_P_FRMCFG_reg},
        {"TP_TF1_P_INT          ", TP_TP_TF1_P_INT_reg},
        {"TP_TF1_P_INT_EN       ", TP_TP_TF1_P_INT_EN_reg},
        {"TP_TF2_P_CNTL         ", TP_TP_TF2_P_CNTL_reg},
        {"TP_TF2_P_CNT          ", TP_TP_TF2_P_CNT_reg},
        {"TP_TF2_P_DRP_CNT      ", TP_TP_TF2_P_DRP_CNT_reg},
        {"TP_TF2_P_FRMCFG       ", TP_TP_TF2_P_DRP_CNT_reg},
        {"TP_TF2_P_INT          ", TP_TP_TF2_P_INT_reg},
        {"TP_TF2_P_INT_EN       ", TP_TP_TF2_P_INT_EN_reg},
        {"TP_P_THRESHOLD        ", TP_TP_P_THRESHOLD_reg},
        {"TP_P_FULLNESS         ", TP_TP_P_FULLNESS_reg},
        {"TP_P_RING_AVAIL_INT   ", TP_TP_P_RING_AVAIL_INT_reg},
        {"TP_P_RING_FULL_INT    ", TP_TP_P_RING_FULL_INT_reg},
        {"TP_P_RING_AVAIL_INT_EN", TP_TP_P_RING_AVAIL_INT_EN_reg},
        {"TP_P_RING_FULL_INT_EN ", TP_TP_P_RING_FULL_INT_EN_reg},
        {"TP_P_SYNC_RPLACE      ", TP_TP_P_SYNC_RPLACE_reg},
        {"PREFIX_CTRL           ", TP_PREFIX_CTRL_reg},
        {"PREFIX_DATA1          ", TP_PREFIX_DATA1_reg},
        {"PREFIX_DATA2          ", TP_PREFIX_DATA2_reg},
        {"PREFIX_DATA3          ", TP_PREFIX_DATA3_reg},
        {"FR_CTRL               ", TP_FR_CTRL_reg},
        {"START_CODE_TP0        ", TP_START_CODE_TP0_reg},
        {"START_CODE_TP1        ", TP_START_CODE_TP1_reg},
        {"START_CODE_CRTL_TP0   ", TP_START_CODE_CTRL_TP0_reg},
        {"START_CODE_CRTL_TP1   ", TP_START_CODE_CTRL_TP1_reg},
        {"TP0_ERR_CNT_EN        ", TP_TP0_ERR_CNT_EN_reg},
        {"TP1_ERR_CNT_EN        ", TP_TP1_ERR_CNT_EN_reg},
        {"TP2_ERR_CNT_EN        ", TP_TP2_ERR_CNT_EN_reg}
};

INT32 Tp_DumpTPRegister(char *str)
{
        int i, j, size, total_size = 0;

        if(str == NULL)
                return TPK_FAIL;

        for(j = 0; j < MAX_PID_FILTER_COUNT; j++) {
                WRITE_REG32(tp_register_pid_filter[0].address, j);
                for(i = 1; i < sizeof(tp_register_pid_filter) / sizeof(TP_REGISTER); i++) {
                        size = sprintf(str, "%s[PID%02d]%s = %08X\n", str, j, tp_register_pid_filter[i].name, READ_REG32(tp_register_pid_filter[i].address));
                }
        }

        for(j = 0; j < MAX_SEC_COUNT; j++) {
                WRITE_REG32(tp_register_sec_filter[0].address, j);
                for(i = 1; i < sizeof(tp_register_sec_filter) / sizeof(TP_REGISTER); i++) {
                        size = sprintf(str, "%s[SEC%03d]%s = %08X\n", str, j, tp_register_sec_filter[i].name, READ_REG32(tp_register_sec_filter[i].address));
                }
        }

        for(j = 0; j < MAX_KEY_COUNT * 8; j++) {
                WRITE_REG32(tp_register_key_info[0].address, j);
                for(i = 1; i < sizeof(tp_register_key_info) / sizeof(TP_REGISTER); i++) {
                        size = sprintf(str, "%s[KEY%02d-%01d]%s = %08X\n", str, j / 8, j % 8, tp_register_key_info[i].name, READ_REG32(tp_register_key_info[i].address));
                }
        }

        for(j = 0; j < MAX_TP_BUFFER_COUNT; j++) {
                WRITE_REG32(tp_register_tp_ring[0].address, j);
                for(i = 1; i < sizeof(tp_register_tp_ring) / sizeof(TP_REGISTER); i++) {
                        size = sprintf(str, "%s[Ring%02d]%s = %08X\n", str, j, tp_register_tp_ring[i].name, READ_REG32(tp_register_tp_ring[i].address));
                }
        }

        for(j = 0; j < MAX_TPP_BUFFER_COUNT; j++) {
                WRITE_REG32(tp_register_tpp_ring[0].address, j);
                for(i = 1; i < sizeof(tp_register_tpp_ring) / sizeof(TP_REGISTER); i++) {
                        size = sprintf(str, "%s[Ring%02d]%s = %08X\n", str, j, tp_register_tpp_ring[i].name, READ_REG32(tp_register_tpp_ring[i].address));
                }
        }

        for(i = 0; i < sizeof(tp_register_list) / sizeof(TP_REGISTER); i++) {
                size = sprintf(str, "%s%s = %08X\n", str, tp_register_list[i].name, READ_REG32(tp_register_list[i].address));
        }

        TP_DBG("Tp_DumpTPRegister siez=%d\n", size);

        return TPK_SUCCESS;
}

INT32 Tp_FlushPatternSearch( TPK_TP_ENGINE_T tp_id)
{
        tp_start_code_tp0_RBUS tp_start_code_vaddr;
        REGADDR tp_start_code_vaddr_reg;

        switch(tp_id) {
                case TP_TP0:
                        tp_start_code_vaddr_reg          = TP_START_CODE_TP0_reg;
                        break;

                case TP_TP1:
                        tp_start_code_vaddr_reg          = TP_START_CODE_TP1_reg;
                        break;

                default:
                        TP_WARNING("unsupported PatternSearch id=%d\n", tp_id);
                        return TPK_BAD_PARAMETER;
        }

        tp_start_code_vaddr.regValue = READ_REG32(tp_start_code_vaddr_reg);
        tp_start_code_vaddr.dma_flush = 1;
        WRITE_REG32(tp_start_code_vaddr_reg, tp_start_code_vaddr.regValue);
        return TPK_SUCCESS;
}

INT32 TP_MTPStreamControl(TPK_TP_MTP_T mtp_id, TPK_MTP_STREAM_CTRL_T ctrl)
{
        tp_tp0_m2m_ring_ctrl_RBUS m2m_ctrl;
        REGADDR m2m_ctrl_reg, m2m_limit_reg, m2m_base_reg, m2m_rp_reg, m2m_wp_reg;
        UINT32 m2m_limit_val, m2m_base_val, m2m_rp_val, m2m_wp_val;

        switch (mtp_id) {
                case TP_TP0_MTP:
                        m2m_ctrl_reg  = TP_TP0_M2M_RING_CTRL_reg;
                        m2m_limit_reg = TP_TP0_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP0_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP0_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP0_M2M_RING_WP_reg;
                        break;
                case TP_TP1_MTP:
                        m2m_ctrl_reg  = TP_TP1_M2M_RING_CTRL_reg;
                        m2m_limit_reg = TP_TP1_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP1_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP1_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP1_M2M_RING_WP_reg;
                        break;
                case TP_TP2_MTP:
                        m2m_ctrl_reg  = TP_TP2_M2M_RING_CTRL_reg;
                        m2m_limit_reg = TP_TP2_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP2_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP2_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP2_M2M_RING_WP_reg;
                        break;
                case TP_TP3_MTP:
                        m2m_ctrl_reg  = TP_TP3_M2M_RING_CTRL_reg;
                        m2m_limit_reg = TP_TP3_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP3_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP3_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP3_M2M_RING_WP_reg;
                        break;
                case TP_TPP0_MTP:
                        m2m_ctrl_reg  = TP_TP0_P_M2M_RING_CTRL_reg;
                        m2m_limit_reg = TP_TP0_P_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP0_P_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP0_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP0_P_M2M_RING_WP_reg;
                        break;
                case TP_TPP1_MTP:
                        m2m_ctrl_reg  = TP_TP1_P_M2M_RING_CTRL_reg;
                        m2m_limit_reg = TP_TP1_P_M2M_RING_LIMIT_reg;
                        m2m_base_reg  = TP_TP1_P_M2M_RING_BASE_reg;
                        m2m_rp_reg    = TP_TP1_P_M2M_RING_RP_reg;
                        m2m_wp_reg    = TP_TP1_P_M2M_RING_WP_reg;
                        break;
                case TP_TPP2_MTP:
                        m2m_ctrl_reg  = TP_TP2_P_M2M_RING_CTRL_reg;
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

        pTp_drv->mtp[mtp_id].timestmp_offset = 0;
        if (ctrl == MTP_STREAM_START) {
#if 0
                /*  set m2m memory dma parameter */
                pMtpBufParam = &pTp_drv->mtp[mtp_id].mtp_buf_param;
                WRITE_REG32(m2m_limit_reg, pMtpBufParam->LimitPhy);
                WRITE_REG32(m2m_base_reg, pMtpBufParam->BasePhy);
                pMtpBufParam->RP = pMtpBufParam->WP = pMtpBufParam->BasePhy;
                WRITE_REG32(m2m_rp_reg, pMtpBufParam->RP);
                WRITE_REG32(m2m_wp_reg, pMtpBufParam->WP);
#endif

                m2m_rp_val    = READ_REG32(m2m_rp_reg);
                m2m_wp_val    = READ_REG32(m2m_wp_reg);
                m2m_limit_val = READ_REG32(m2m_limit_reg);
                m2m_base_val  = READ_REG32(m2m_base_reg);

                m2m_ctrl.regValue = 0;
                m2m_ctrl.in_go    = 1;
                if ((mtp_id >= TP_TPP0_MTP ) && (mtp_id <= TP_TPP2_MTP))
                        m2m_ctrl.go = 1;
                Tp_Write_Data_Reg_Write(m2m_ctrl_reg, m2m_ctrl.regValue);
                pTp_drv->mtp[mtp_id].first_tsp = 1;
        } else {
                /* set m2m memory dma parameter */
                m2m_ctrl.regValue = 0;
                if ((mtp_id >= TP_TPP0_MTP ) && (mtp_id <= TP_TPP2_MTP))
                        m2m_ctrl.go = 0;
                m2m_ctrl.in_go    = 0;
                Tp_Write_Data_Reg_Write(m2m_ctrl_reg, m2m_ctrl.regValue);
                pTp_drv->mtp[mtp_id].first_tsp = 0;

                m2m_rp_val    = READ_REG32(m2m_rp_reg);
                m2m_wp_val    = READ_REG32(m2m_wp_reg);
                m2m_limit_val = READ_REG32(m2m_limit_reg);
                m2m_base_val  = READ_REG32(m2m_base_reg);
        }

        udelay(100);
        /* must wait over 1us then write rp, wp; because we set in_go in mtp.*/
        /* rewrite rp wp for mtp hw limit */


#if 1
        if(m2m_rp_val > m2m_limit_val ||
            m2m_rp_val < m2m_base_val) {
                TP_WARNING("MTP RP out of BP to LP, repoint to BP.");
                WRITE_REG32(m2m_rp_reg, m2m_base_val);
        }

#endif

        if(m2m_wp_val > m2m_limit_val ||
            m2m_wp_val < m2m_base_val) {
                TP_WARNING("MTP WP out of BP to LP, repoint to BP.");
                WRITE_REG32(m2m_wp_reg, m2m_base_val);
        }

        pTp_drv->mtp[mtp_id].mtp_stream_status  = ctrl;
        pTp_drv->mtp[mtp_id].mtp_write_data_cnt = 0;
        return TPK_SUCCESS;

}

UINT32 Tp_Get_MTPFrameControlStatus(TPK_TP_ENGINE_T tp_id, UINT8 *fr_status)
{
        tp_fr_ctrl_RBUS fr_ctrl;
        fr_ctrl.regValue = READ_REG32(TP_FR_CTRL_reg);

        *fr_status = 0;
        switch(tp_id) {
                case TP_TP0:
                        *fr_status = fr_ctrl.tp0_en;
                        break;

                case TP_TP1:
                        *fr_status = fr_ctrl.tp1_en;
                        break;

                case TP_TP2:
                        *fr_status = fr_ctrl.tp2_en;
                        break;

                case TP_TP3:
                        *fr_status = fr_ctrl.tp3_en;
                        break;

                default:
                        TP_WARNING("%d unsupported tp_id id=%d\n", __LINE__, tp_id);
                        return TPK_BAD_PARAMETER;
        }
        return TPK_SUCCESS;
}

UINT32 Tp_Get_PrefixStatus(TPK_TP_ENGINE_T tp_id, UINT8 *keep, UINT8 *prefix_sel)
{
        tp_prefix_ctrl_RBUS prefix_ctrl;
        prefix_ctrl.regValue = READ_REG32(TP_PREFIX_CTRL_reg);

        *keep = 0;
        *prefix_sel = 0;
        switch(tp_id) {
                case TP_TP0:
                        *keep = prefix_ctrl.tp0_keep;
                        *prefix_sel = prefix_ctrl.tp0_sel;
                        break;

                case TP_TP1:
                        *keep = prefix_ctrl.tp1_keep;
                        *prefix_sel = prefix_ctrl.tp1_sel;
                        break;

                case TP_TP2:
                        *keep = prefix_ctrl.tp2_keep;
                        *prefix_sel = prefix_ctrl.tp2_sel;
                        break;

                case TP_TP3:
                        *keep = prefix_ctrl.tp3_keep;
                        *prefix_sel = prefix_ctrl.tp3_sel;
                        break;

                default:
                        TP_WARNING("%d unsupported tp_id id=%d\n", __LINE__, tp_id);
                        return TPK_BAD_PARAMETER;
        }
        return TPK_SUCCESS;
}


INT32 Tp_SetPIDEncryption( TPK_TP_ENGINE_T tp_id, UINT16 PID, UINT8 keytype)
{
        UINT16 max_pid_cnt, pid_idx, pid_idx_reg;
        UINT8 update_flag, ddr_q, info_q;
        TPK_PID_REG_PARAM_T pid_reg;
        TPK_PID_FILTER_PARAM_T PIDParm;
        INT32 result;
        memset(&PIDParm, 0, sizeof(TPK_PID_FILTER_PARAM_T));
        PIDParm.PID = PID;
        result = _PID_Filter_Update_Check(tp_id, PIDParm,
                                          &pid_idx, &pid_idx_reg,
                                          &update_flag, &max_pid_cnt,
                                          &ddr_q, &info_q);
        result = Tp_GetPidParam(pid_idx_reg, &pid_reg);
        pid_reg.encrypt_tsc_en = 1;
        pid_reg.encryption_key = keytype ? 1 : 0;
        pid_reg.encryption_en = 1;
        result = Tp_SetPidParam(pid_idx_reg, pid_reg);
        if (result != TPK_SUCCESS) {
                TP_WARNING("set pid reg error\n");
        }
        return result;

}




///////////////////tpp related functions/////////////////////

INT32 Tp_TPP_Init(TPK_TPP_ENGINE_T tp_p_id)
{
        INT32 result;
        tp_tp_tf0_p_cntl_RBUS tp_p_cntl;

        CHECK_MAX_TPP_COUNT(tp_p_id);
        CHECK_TP_STRUCTURE();

        if(pTp_drv->tpp[tp_p_id].Inited) {
                /* TP_WARNING("TP%d already inited\n",tp_p_id); */
                return TPK_SUCCESS;
        }

        /* reset TPP framer state machine */
        tp_p_cntl.regValue   = 0;
        tp_p_cntl.rst_en     = 1;
        Tp_TPP_SetCtrlReg(tp_p_id, tp_p_cntl.regValue, 1);
        ndelay(110);
        Tp_TPP_SetCtrlReg(tp_p_id, tp_p_cntl.regValue, 0);
        ndelay(110);

        /* basic TPP setting */
        tp_p_cntl.rst_en     = 0;
        tp_p_cntl.buf_rdy_ctl = 1;
        tp_p_cntl.ci_mode       = 1;
        tp_p_cntl.null_en       = 1;
        tp_p_cntl.sync_en       = 1;
        Tp_TPP_SetCtrlReg(tp_p_id, tp_p_cntl.regValue, 1);

        /* set default vaule of sync byte replacement*/
        Tp_TPP_SetSyncReplace(tp_p_id, 0x47);

        /* init mass buffer */
        result = Tp_TPP_MassBuffInit(tp_p_id);
        if( result != TPK_SUCCESS ) {
                TP_WARNING("TP%u init buffer buffer error (%d)\n", tp_p_id, result);
                return result;
        }

        /* update status */

        pTp_drv->tpp[tp_p_id].tpp_src                   = TS_UNMAPPING;
        pTp_drv->tpp[tp_p_id].tpp_stream_status = TPP_STREAM_STOP;
        pTp_drv->tpp[tp_p_id].Inited                    = 1;

        return TPK_SUCCESS;
}

INT32 Tp_TPP_SetCtrlReg(TPK_TPP_ENGINE_T tpp_id, UINT32 bit_sel, UINT8 data)
{
        UINT32 tp_tf_p_cntl_reg;

        CHECK_MAX_TP_P_COUNT(tpp_id);

        if (data)
                bit_sel |= _BIT0;
        else
                bit_sel &= ~_BIT0;

        switch (tpp_id) {
                case TP_TPP0:
                        tp_tf_p_cntl_reg = TP_TP_TF0_P_CNTL_reg;
                        break;
                case TP_TPP1:
                        tp_tf_p_cntl_reg = TP_TP_TF1_P_CNTL_reg;
                        break;
                case TP_TPP2:
                        tp_tf_p_cntl_reg = TP_TP_TF2_P_CNTL_reg;
                        break;

                default:
                        TP_WARNING("tpp_id=%u not support\n", tpp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        WRITE_REG32(tp_tf_p_cntl_reg, bit_sel);

        return TPK_SUCCESS;
}

INT32 Tp_TPP_GetCtrlReg(TPK_TPP_ENGINE_T tpp_id, UINT32 *data)
{
        REGADDR tpp_tf_cntl_reg;

        CHECK_MAX_TPP_COUNT(tpp_id);

        switch(tpp_id) {
                case TP_TPP0:
                        tpp_tf_cntl_reg = TP_TP_TF0_P_CNTL_reg;
                        break;
                case TP_TPP1:
                        tpp_tf_cntl_reg = TP_TP_TF1_P_CNTL_reg;
                        break;
                case TP_TPP2:
                        tpp_tf_cntl_reg = TP_TP_TF2_P_CNTL_reg;
                        break;
                default:
                        TP_WARNING("tpp_id=%u not support\n", tpp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        *data = READ_REG32(tpp_tf_cntl_reg);

        return TPK_SUCCESS;
}

INT32 Tp_TPP_SetFrmReg(TPK_TPP_ENGINE_T tpp_id, UINT32 data)
{
        REGADDR tpp_tf_frm_reg;

        CHECK_MAX_TPP_COUNT(tpp_id);

        switch(tpp_id) {
                case TP_TPP0:
                        tpp_tf_frm_reg = TP_TP_TF0_P_FRMCFG_reg;
                        break;
                case TP_TPP1:
                        tpp_tf_frm_reg = TP_TP_TF1_P_FRMCFG_reg;
                        break;
                case TP_TPP2:
                        tpp_tf_frm_reg = TP_TP_TF2_P_FRMCFG_reg;
                        break;
                default:
                        TP_WARNING("tpp_id=%u not support\n", tpp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        WRITE_REG32(tpp_tf_frm_reg, data);

        return TPK_SUCCESS;
}

INT32 Tp_TPP_GetFrmReg(TPK_TPP_ENGINE_T tpp_id, UINT32 *data)
{
        REGADDR tpp_tf_frm_reg;

        CHECK_MAX_TPP_COUNT(tpp_id);

        switch(tpp_id) {
                case TP_TPP0:
                        tpp_tf_frm_reg = TP_TP_TF0_P_FRMCFG_reg;
                        break;
                case TP_TPP1:
                        tpp_tf_frm_reg = TP_TP_TF1_P_FRMCFG_reg;
                        break;
                case TP_TPP2:
                        tpp_tf_frm_reg = TP_TP_TF2_P_FRMCFG_reg;
                        break;
                default:
                        TP_WARNING("tpp_id=%u not support\n", tpp_id);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        *data = READ_REG32(tpp_tf_frm_reg);

        return TPK_SUCCESS;
}

INT32 Tp_TPP_MassBuffInit(TPK_TPP_ENGINE_T tp_p_id)
{
        UINT32 virt_addr;
        UINT32 phys_addr;
        UINT32 size = 0;
        tp_tp_p_ring_ctrl_RBUS tp_p_ring_ctrl_reg;
        tp_tp_p_ring_base_RBUS tp_p_ring_base_reg;
        tp_tp_p_ring_limit_RBUS tp_p_ring_limit_reg;
        tp_tp_p_ring_rp_RBUS tp_p_ring_rp_reg;
        tp_tp_p_ring_wp_RBUS tp_p_ring_wp_reg;

        if(pTp_drv->tpp[tp_p_id].mass_buffer.inited) {
                return TPK_SUCCESS;
        }

        virt_addr = (UINT32)dvr_malloc_specific(TP_P_BUFFER_SIZE, GFP_DCU2_FIRST);
        if (virt_addr == 0) {
                TP_ERROR("can not allocate buffer for TPP, buffer size = %u \n",
                         TP_P_BUFFER_SIZE);
                return TPK_NOT_ENOUGH_RESOURCE;
        }
        phys_addr  = (UINT32)dvr_to_phys((void *)(virt_addr));
        if (phys_addr == 0) {
                TP_ERROR("virt to phy fail! can not allocate buffer for TPP, buffer size = %u \n",
                         TP_P_BUFFER_SIZE);
                return TPK_NOT_ENOUGH_RESOURCE;
        }

#ifdef CONFIG_LG_SNAPSHOT_BOOT
        register_cma_forbidden_region(__phys_to_pfn(phys_addr), TP_P_BUFFER_SIZE);
#endif

        size = TP_P_BUFFER_SIZE;
        if ((phys_addr & 0x3) != 0) {
                phys_addr = (phys_addr + 8) - (phys_addr & 0x3);
                size = TP_P_BUFFER_SIZE - TP_P_BUFFER_ALIGNMENT;
        }

        /* set TP' DDR fullness and threshold */
        WRITE_REG32(TP_TP_P_THRESHOLD_reg, TP_P_BUFFER_THRESHOLD);
        WRITE_REG32(TP_TP_P_FULLNESS_reg, TP_P_BUFFER_THRESHOLD);
        pTp_drv->tpp[tp_p_id].mass_buffer.BasePhy = phys_addr;
        pTp_drv->tpp[tp_p_id].mass_buffer.LimitPhy = phys_addr + TP_P_BUFFER_SIZE;
        pTp_drv->tpp[tp_p_id].mass_buffer.BufSize = TP_P_BUFFER_SIZE;
        pTp_drv->tpp[tp_p_id].mass_buffer.RP      = phys_addr;
        pTp_drv->tpp[tp_p_id].mass_buffer.WP      = phys_addr;


        WRITE_REG32(TP_TP_P_RING_LIMIT_reg, pTp_drv->tpp[tp_p_id].mass_buffer.LimitPhy);
        WRITE_REG32(TP_TP_P_RING_BASE_reg, pTp_drv->tpp[tp_p_id].mass_buffer.BasePhy);
        WRITE_REG32(TP_TP_P_RING_RP_reg, pTp_drv->tpp[tp_p_id].mass_buffer.BasePhy);
        WRITE_REG32(TP_TP_P_RING_WP_reg, pTp_drv->tpp[tp_p_id].mass_buffer.BasePhy);

        tp_p_ring_ctrl_reg.regValue = 0;
        tp_p_ring_ctrl_reg.wm       = 0;
        tp_p_ring_ctrl_reg.r_w      = 1;
        tp_p_ring_ctrl_reg.idx      = tp_p_id;
        WRITE_REG32(TP_TP_P_RING_CTRL_reg, tp_p_ring_ctrl_reg.regValue);
        pTp_drv->tpp[tp_p_id].mass_buffer.inited = 1;

        return TPK_SUCCESS;
}

void Tp_TPP_CheckRingBuffer(void)
{
        int i;

        for ( i = 0 ; i < 3; i++) {
                int error = 0;
                unsigned long Base;
                unsigned long Limit;
                unsigned long RP;
                unsigned long WP;

                if(!pTp_drv->tpp[i].mass_buffer.inited)
                        continue;

                WRITE_REG32(TP_TP_P_RING_CTRL_reg, i);

                Base  = READ_REG32(TP_TP_P_RING_BASE_reg);
                RP    = READ_REG32(TP_TP_P_RING_RP_reg);
                WP    = READ_REG32(TP_TP_P_RING_WP_reg);
                Limit = READ_REG32(TP_TP_P_RING_LIMIT_reg);

                if (Limit != pTp_drv->tpp[i].mass_buffer.LimitPhy) {
                        TP_WARNING("TPP[%d] Invalid Limit - %08lx (should be %08lx)\n",
                                   i, Limit, pTp_drv->tpp[i].mass_buffer.LimitPhy);
                        error = 1;
                }

                if (Base != pTp_drv->tpp[i].mass_buffer.BasePhy) {
                        TP_WARNING("TPP[%d] Invalid Base - %08lx (should be %08lx)\n",
                                   i, Base, pTp_drv->tpp[i].mass_buffer.BasePhy);
                        error = 1;
                }

                if (RP < pTp_drv->tpp[i].mass_buffer.BasePhy || RP > pTp_drv->tpp[i].mass_buffer.LimitPhy) {
                        TP_WARNING("TPP[%d] Invalid RP - %08lx (should within %08lx - %08lx)\n",
                                   i, RP, pTp_drv->tpp[i].mass_buffer.LimitPhy, pTp_drv->tpp[i].mass_buffer.BasePhy);
                        error = 1;
                }

                if (WP < pTp_drv->tpp[i].mass_buffer.BasePhy || WP > pTp_drv->tpp[i].mass_buffer.LimitPhy) {
                        TP_WARNING("TPP[%d] Invalid WP - %08lx (should within %08lx - %08lx)\n",
                                   i, WP, pTp_drv->tpp[i].mass_buffer.LimitPhy, pTp_drv->tpp[i].mass_buffer.BasePhy);
                        error = 1;
                }

                if (error) {
                        pTp_drv->tpp[i].mass_buffer.buffer_err_cnt++;

                        TP_WARNING("TPP_RING[%d] Ring buffer out of sync {%08lx, %08lx, %08lx, %08lx}, (Err=%lu)\n",
                                   i, Base, RP, WP, Limit, pTp_drv->tpp[i].mass_buffer.buffer_err_cnt);
                        TP_WARNING("TPP[%d] Ring buffer out of sync Detected, do recovery, Err=%lu\n",
                                   i, pTp_drv->tpp[i].mass_buffer.buffer_err_cnt);



                        WRITE_REG32(TP_TP_P_RING_LIMIT_reg, pTp_drv->tpp[i].mass_buffer.LimitPhy);
                        WRITE_REG32(TP_TP_P_RING_BASE_reg,  pTp_drv->tpp[i].mass_buffer.BasePhy);
                        WRITE_REG32(TP_TP_P_RING_RP_reg, pTp_drv->tpp[i].mass_buffer.BasePhy);
                        WRITE_REG32(TP_TP_P_RING_WP_reg, pTp_drv->tpp[i].mass_buffer.BasePhy);
                        WRITE_REG32(TP_TP_P_RING_CTRL_reg, 0x40 | i);
                }
        }
}

INT32 Tp_TPP_FlushBuf(TPK_TPP_ENGINE_T tpp_id)
{
        INT32 result;
        UINT8 fram_en_save;

        tp_tp_tf0_p_frmcfg_RBUS  tp_p_frmcfg_reg;
        unsigned long Base, Limit, RP, WP;
        tp_tp_p_ring_ctrl_RBUS tp_p_ring_ctrl_reg;
        tp_tp_p_ring_base_RBUS buf_base_reg;
        tp_tp_p_ring_limit_RBUS buf_limit_reg;
        tp_tp_p_ring_wp_RBUS buf_wp_reg;
        tp_tp_p_ring_rp_RBUS buf_rp_reg;
        tp_tp_p_ring_avail_int_RBUS tp_p_ring_avail_int_reg;
        tp_tp_p_ring_full_int_RBUS tp_p_ring_full_int_reg;


        /* check parameter */
        CHECK_MAX_TPP_COUNT(tpp_id);
        CHECK_TP_STRUCTURE();

        if(pTp_drv->tpp[tpp_id].mass_buffer.inited != 1) {
                TP_WARNING("buffer not init, tpp_id=%u\n", tpp_id);
                return TPK_NOT_INIT;
        }
        TP_WARNING("tpp_id=[%d] Tp_TPP_FlushBuf \n", tpp_id);

        /* stop streaming */
        Tp_TPP_GetFrmReg(tpp_id, &tp_p_frmcfg_reg.regValue);
        fram_en_save = tp_p_frmcfg_reg.frm_en;
        if(fram_en_save) {
                tp_p_frmcfg_reg.frm_en = 0;
                Tp_TPP_SetFrmReg(tpp_id, tp_p_frmcfg_reg.regValue);
        }
        /* get base and limit */
        WRITE_REG32(TP_TP_P_RING_CTRL_reg, tpp_id);
        buf_base_reg.regValue   = READ_REG32(TP_TP_P_RING_BASE_reg);
        buf_limit_reg.regValue  = READ_REG32(TP_TP_P_RING_LIMIT_reg);
        buf_wp_reg.regValue  = READ_REG32(TP_TP_P_RING_WP_reg);
        buf_rp_reg.regValue  = READ_REG32(TP_TP_P_RING_RP_reg);
        buf_base_reg.res1 = 0;
        buf_limit_reg.res1 = 0;
        udelay(100);


        WRITE_REG32(TP_TP_P_RING_LIMIT_reg, buf_limit_reg.regValue);
        WRITE_REG32(TP_TP_P_RING_BASE_reg, buf_base_reg.regValue);
        WRITE_REG32(TP_TP_P_RING_RP_reg, buf_base_reg.regValue);
        WRITE_REG32(TP_TP_P_RING_WP_reg, buf_base_reg.regValue);
        tp_p_ring_ctrl_reg.regValue = 0;
        tp_p_ring_ctrl_reg.wm      = 0;
        tp_p_ring_ctrl_reg.r_w     = 1;
        tp_p_ring_ctrl_reg.idx     = tpp_id;
        WRITE_REG32(TP_TP_P_RING_CTRL_reg, tp_p_ring_ctrl_reg.regValue);

        /* clear interrupt */
        tp_p_ring_avail_int_reg.ring_avail_0       = 0;
        tp_p_ring_avail_int_reg.ring_avail_1       = 0;
        tp_p_ring_avail_int_reg.ring_avail_2       = 0;
        tp_p_ring_avail_int_reg.write_data         = 1;
        tp_p_ring_full_int_reg.ring_full_0         = 0;
        tp_p_ring_full_int_reg.ring_full_0         = 0;
        tp_p_ring_full_int_reg.ring_full_0         = 0;
        tp_p_ring_full_int_reg.write_data          = 1;
        WRITE_REG32(TP_TP_P_RING_AVAIL_INT_reg, tp_p_ring_avail_int_reg.regValue);
        WRITE_REG32(TP_TP_P_RING_FULL_INT_reg, tp_p_ring_full_int_reg.regValue);

        /* start streaming */
        if(fram_en_save) {
                tp_p_frmcfg_reg.frm_en = 1;
                Tp_TPP_SetFrmReg(tpp_id, tp_p_frmcfg_reg.regValue);
        }

        return TPK_SUCCESS;

}

INT32 Tp_TPP_ResetCounter(TPK_TPP_ENGINE_T tpp_id)
{
        TPK_TPP_PKT_CNT_T *ppkt_cnt;

        CHECK_MAX_TPP_COUNT(tpp_id);
        CHECK_TP_STRUCTURE();

        switch(tpp_id) {
                case TP_TPP0:
                        WRITE_REG32(TP_TP_TF0_P_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF0_P_DRP_CNT_reg, _ZERO);

                        break;
                case TP_TPP1:
                        WRITE_REG32(TP_TP_TF1_P_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF1_P_DRP_CNT_reg, _ZERO);

                        break;
                case TP_TPP2:
                        WRITE_REG32(TP_TP_TF2_P_CNT_reg, _ZERO);
                        WRITE_REG32(TP_TP_TF2_P_DRP_CNT_reg, _ZERO);
                        break;

                default:
                        TP_WARNING("unsupported tp_id=%d\n", tpp_id);
                        return TPK_BAD_PARAMETER;
        }


        ppkt_cnt = &pTp_drv->tpp[tpp_id].tpp_pkt_cnt;
        ppkt_cnt->pkt = 0;
        ppkt_cnt->droppedPkt  = 0;

        return TPK_SUCCESS;
}

INT32 Tp_TPP_SetSyncReplace(TPK_TPP_ENGINE_T tpp_id, UINT8 sync_byte )
{
        tp_tp_p_sync_rplace_RBUS sync_rplace;

        sync_rplace.regValue = READ_REG32(TP_TP_P_SYNC_RPLACE_reg);

        switch (tpp_id) {
                case TP_TP0:
                        sync_rplace.tp0 = sync_byte;
                        break;
                case TP_TP1:
                        sync_rplace.tp1 = sync_byte;
                        break;
                case TP_TP2:
                        sync_rplace.tp2 = sync_byte;
                        break;
                default:
                        TP_WARNING("bad parameter - tp_id:%d, sync_byte:%d\n", tpp_id, sync_byte);
                        return TPK_BAD_PARAMETER;
                        break;
        }

        WRITE_REG32(TP_TP_P_SYNC_RPLACE_reg, sync_rplace.regValue);

        return TPK_SUCCESS;
}

INT32 Tp_TPP_SetDataSource(TPK_TPP_ENGINE_T tpp_id, TPK_TP_SOURCE_T remux_src)
{
        tp_tp_tf0_p_cntl_RBUS    tp_p_cntl_reg;
        tp_tp_tf0_p_frmcfg_RBUS  tp_p_frmcfg_reg;
        REGADDR tp_p_cntl_addr;
        REGADDR tp_p_frmcfg_addr;

        switch(tpp_id) {
                case TP_TPP0:
                        tp_p_cntl_addr   = TP_TP_TF0_P_CNTL_reg;
                        tp_p_frmcfg_addr  = TP_TP_TF0_P_FRMCFG_reg;
                        break;
                case TP_TPP1:
                        tp_p_cntl_addr   = TP_TP_TF1_P_CNTL_reg;
                        tp_p_frmcfg_addr  = TP_TP_TF1_P_FRMCFG_reg;
                        break;
                case TP_TPP2:
                        tp_p_cntl_addr   = TP_TP_TF2_P_CNTL_reg;
                        tp_p_frmcfg_addr  = TP_TP_TF2_P_FRMCFG_reg;
                        break;
                default:
                        TP_WARNING("unsupported tp_p_id=%d\n", tpp_id);
                        return TPK_BAD_PARAMETER;
        }
        tp_p_cntl_reg.regValue     = READ_REG32(tp_p_cntl_addr);
        tp_p_frmcfg_reg.regValue   = READ_REG32(tp_p_frmcfg_addr);

        switch(remux_src) {
                case MTP:
                        tp_p_cntl_reg.mode = 1;
                        break;
                case TS_SRC_0:
                        tp_p_cntl_reg.mode = 0;
                        tp_p_cntl_reg.src_sel_h = 0;
                        tp_p_cntl_reg.src_sel_l = 0;
                        break;
                case TS_SRC_1:
                        tp_p_cntl_reg.mode = 0;
                        tp_p_cntl_reg.src_sel_h = 0;
                        tp_p_cntl_reg.src_sel_l = 1;
                        break;
                case TS_SRC_2:
                        tp_p_cntl_reg.mode = 0;
                        tp_p_cntl_reg.src_sel_h = 1;
                        tp_p_cntl_reg.src_sel_l = 0;
                        break;
                case Internal_Demod:
                        tp_p_cntl_reg.mode = 0;
                        tp_p_cntl_reg.src_sel_h = 1;
                        tp_p_cntl_reg.src_sel_l = 1;
                        break;
                default:
                        _tp_unlock();
                        TP_WARNING("bad parameter (tp_p_id=%u, remux_src=%u)\n", tpp_id, remux_src);
                        return TPK_BAD_PARAMETER;
        }

        /* set TP frame reg */
        tp_p_frmcfg_reg.lockno   = (remux_src == MTP) ? 1 : 3; /* check 0x47 x 3 for TSP header lock */
        WRITE_REG32(tp_p_frmcfg_addr, tp_p_frmcfg_reg.regValue);

        Tp_Write_Data_Reg_Write(tp_p_cntl_addr, tp_p_cntl_reg.regValue);

        pTp_drv->tpp[tpp_id].tpp_src = remux_src;

        return TPK_SUCCESS;
}

INT32 Tp_TPP_TPOutControl(TPK_TPP_ENGINE_T tpp_id, UINT8 on )
{
        tp_tp0_p_m2m_ring_ctrl_RBUS tp_p_m2m_ring_ctrl ;
        REGADDR tp_p_mtp_ring_ctrl_addr;

        if(!pTp_drv->tpp[tpp_id].Inited) {
                return TPK_FAIL;
        }

        switch(tpp_id) {
                case TP_TPP0:
                        tp_p_mtp_ring_ctrl_addr = TP_TP0_P_M2M_RING_CTRL_reg;
                        break;
                case TP_TPP1:
                        tp_p_mtp_ring_ctrl_addr = TP_TP1_P_M2M_RING_CTRL_reg;
                        break;
                case TP_TPP2:
                        tp_p_mtp_ring_ctrl_addr = TP_TP2_P_M2M_RING_CTRL_reg;
                        break;
                default:
                        TP_WARNING("unsupported tp_p_id=%d\n", tpp_id);
                        return TPK_BAD_PARAMETER;
        }
        tp_p_m2m_ring_ctrl.regValue        = READ_REG32(tp_p_mtp_ring_ctrl_addr);
        tp_p_m2m_ring_ctrl.go = on ? 1 : 0;

        Tp_Write_Data_Reg_Write(tp_p_mtp_ring_ctrl_addr, tp_p_m2m_ring_ctrl.regValue);

        return TPK_SUCCESS;
}

INT32 TP_DisplayTPFramerInformation(TPK_TP_ENGINE_T tp_id)
{
        UINT64 pErrPkt, pRevPkt, pDropPkt;
        TP_BUFFER_PARAM_T buffer_param;

        pRevPkt = pTp_drv->tp[tp_id].tp_pkt_cnt.pkt;
        pDropPkt = pTp_drv->tp[tp_id].tp_pkt_cnt.droppedPkt;
        pErrPkt = pTp_drv->tp[tp_id].tp_pkt_cnt.errorPkt;
        UINT8 buffer_index[MAX_TP_COUNT] = {TP0_BUFFER_MASS_DATA, TP1_BUFFER_MASS_DATA, TP2_BUFFER_MASS_DATA, TP3_BUFFER_MASS_DATA};

        TP_WARNING("[TP%d] cnt=%llx drop=%llx Err=%llx\n", tp_id, pRevPkt, pDropPkt, pErrPkt);

        Tp_Get_Buffer(buffer_index[tp_id], &buffer_param);
        TP_WARNING("[TS%d] B=0x%08x L=0x%08x R=0x%08x W=0x%08x RR =%dKB/s RP((demux)%08x/(tp_sec)%08x/(pvr)%08x)\n", tp_id, buffer_param.Base, buffer_param.Limit, buffer_param.RP, buffer_param.WP, pTp_drv->tp_pid[tp_id].ringrate_KB, pTp_drv->tp[tp_id].mass_buffer.RP_Connect[MASS_DATA_BUFFER_RP], pTp_drv->tp[tp_id].mass_buffer.RP_Connect[SECTION_BUFFER_RP], pTp_drv->tp[tp_id].mass_buffer.RP_Connect[DUMP_BUFFER_RP]);

        return TPK_SUCCESS;
}

#ifdef CAM_SRC_CHANGE_BASE_ON_TP_INPUT_COUNT
INT32 TP_TPInput_Monitor_Init(TPK_TP_ENGINE_T tp_id)
{
	UINT32 tp_cnt_reg, tp_drp_cnt_reg, tp_err_cnt_reg;
	UINT32 tp_cntl_reg, tp_frmcfg_reg;
	UINT8  buf_idx;
	TP_BUFFER_PARAM_T buf_param;
	tp_tp_tf0_frmcfg_RBUS tp_frm;
	tp_tp_tf0_cntl_RBUS tp_cntl;
	int try_cnt = 0;
	UINT32 tmp_pkt_cnt = 0;

	if(pTp_drv->tp_input_monitor_virt_addr == 0x00)
	{	
		pTp_drv->tp_input_monitor_virt_addr = (UINT32)dvr_malloc_specific(TP_P_MONITOR_BUFFER_SIZE, GFP_DCU2_FIRST);
		if (pTp_drv->tp_input_monitor_virt_addr == 0)
		{
			TP_WARNING("error, TP_TPInput_Monitor_Init can not allocate buffer, buffer size = %u \n", TP_P_BUFFER_SIZE );
			return TPK_NOT_ENOUGH_RESOURCE;
		}
		
		pTp_drv->tp_input_monitor_phys_addr = (UINT32)dvr_to_phys((void *)pTp_drv->tp_input_monitor_virt_addr);
		if (pTp_drv->tp_input_monitor_phys_addr == 0)
		{
			TP_WARNING("error, TP_TPInput_Monitor_Init can not allocate buffer, buffer size = %u \n", TP_P_BUFFER_SIZE );
			return TPK_NOT_ENOUGH_RESOURCE;
		}
	}

	//RHAL_SetTPRingBuffer(TP_TP2, phys_addr, virt_addr, TP_P_BUFFER_SIZE);
	Tp_init(tp_id);

	switch(tp_id)
	{
		case TP_TP0:
			tp_cntl_reg    = TP_TP_TF0_CNTL_reg;
			tp_frmcfg_reg  = TP_TP_TF0_FRMCFG_reg;
			buf_idx        = TP0_BUFFER_MASS_DATA;
			tp_cnt_reg     = TP_TP_TF0_CNT_reg;
			tp_drp_cnt_reg = TP_TP_TF0_DRP_CNT_reg;
			tp_err_cnt_reg = TP_TP_TF0_ERR_CNT_reg;
			break;
			case TP_TP1:
			tp_cntl_reg    = TP_TP_TF1_CNTL_reg;
			tp_frmcfg_reg  = TP_TP_TF1_FRMCFG_reg;
			buf_idx        = TP1_BUFFER_MASS_DATA;
			tp_cnt_reg     = TP_TP_TF1_CNT_reg;
			tp_drp_cnt_reg = TP_TP_TF1_DRP_CNT_reg;
			tp_err_cnt_reg = TP_TP_TF1_ERR_CNT_reg;
			break;
		case TP_TP2:
			tp_cntl_reg    = TP_TP_TF2_CNTL_reg;
			tp_frmcfg_reg  = TP_TP_TF2_FRMCFG_reg;
			buf_idx        = TP2_BUFFER_MASS_DATA;
			tp_cnt_reg     = TP_TP_TF2_CNT_reg;
			tp_drp_cnt_reg = TP_TP_TF2_DRP_CNT_reg;
			tp_err_cnt_reg = TP_TP_TF2_ERR_CNT_reg;
			break;
		case TP_TP3:
			tp_cntl_reg    = TP_TP_TF3_CNTL_reg;
			tp_frmcfg_reg  = TP_TP_TF3_FRMCFG_reg;
			buf_idx        = TP3_BUFFER_MASS_DATA;
			tp_cnt_reg     = TP_TP_TF3_CNT_reg;
			tp_drp_cnt_reg = TP_TP_TF3_DRP_CNT_reg;
			tp_err_cnt_reg = TP_TP_TF3_ERR_CNT_reg;
			break;
		default:
			break;
	}

	buf_param.Base  =(UINT32)pTp_drv->tp_input_monitor_phys_addr;
	buf_param.Limit =(UINT32)pTp_drv->tp_input_monitor_phys_addr + TP_P_BUFFER_SIZE;
	buf_param.RP    =(UINT32)pTp_drv->tp_input_monitor_phys_addr;
	buf_param.WP    =(UINT32)pTp_drv->tp_input_monitor_phys_addr;
	Tp_Set_Buffer(buf_idx, buf_param, BUFFER_WRITE_MASK_NONE);

	Tp_SetMemoryMode(tp_id, 0);
	tp_cntl.regValue = 0;
	tp_cntl.regValue = READ_REG32(tp_cntl_reg);
	
	tp_cntl.ci_mode   = 0;
	tp_cntl.src_sel_h = 0;
	tp_cntl.src_sel_l = 1;
	tp_cntl.pid_en    = 1;
	
	Tp_Write_Data_Reg_Write(tp_cntl_reg, tp_cntl.regValue);

        WRITE_REG32(tp_cnt_reg, 0);
        WRITE_REG32(tp_drp_cnt_reg, 0);
        WRITE_REG32(tp_err_cnt_reg, 0);

	do {
		try_cnt++;
		tp_frm.regValue = READ_REG32(tp_frmcfg_reg);
		tp_frm.serial   = 0;
		tp_frm.frm_en	= 1;
		WRITE_REG32(tp_frmcfg_reg, tp_frm.regValue);
		mdelay(10);
		tp_frm.regValue = READ_REG32(tp_frmcfg_reg);
		tmp_pkt_cnt = READ_REG32(tp_cnt_reg);
	} while (tp_frm.regValue != 0xFFFFFFFF && (tp_frm.serial != 0 || tp_frm.frm_en != 1) && tmp_pkt_cnt != 0);

	TP_WARNING("Info, TP_TPInput_Monitor_Init successfully. tp_id:%d frm_en:%d try_cnt:%d tp_pkt_cnt:%d\n", tp_id, tp_frm.frm_en, try_cnt, tmp_pkt_cnt);

	return TPK_SUCCESS;
}

INT32 TP_TPInput_Monitor_Uninit(TPK_TP_ENGINE_T tp_id)
{
	UINT32 tp_frmcfg_reg;
	tp_tp_tf0_frmcfg_RBUS tp_frm;

	switch(tp_id)
	{
		case TP_TP0:
			tp_frmcfg_reg  = TP_TP_TF0_FRMCFG_reg;
			break;
		case TP_TP1:
			tp_frmcfg_reg  = TP_TP_TF1_FRMCFG_reg;
			break;
		case TP_TP2:
			tp_frmcfg_reg  = TP_TP_TF2_FRMCFG_reg;
			break;
		case TP_TP3:
			tp_frmcfg_reg  = TP_TP_TF3_FRMCFG_reg;
			break;
		default:
			break;
	}

	tp_frm.regValue = READ_REG32(tp_frmcfg_reg);
	tp_frm.frm_en	= 0;
	WRITE_REG32(tp_frmcfg_reg, tp_frm.regValue);
#if 0  //only 9k ,don't free for mutex problem.
	if(pTp_drv->tp_input_monitor_virt_addr != 0x00)
	{
		dvr_free((void *)pTp_drv->tp_input_monitor_virt_addr);
		pTp_drv->tp_input_monitor_virt_addr = 0x00;
	}
#endif
	return TPK_SUCCESS;
}
#endif
