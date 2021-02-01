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
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/jiffies.h>
#include <linux/platform_device.h>
#include <linux/delay.h>

#include <base_types.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rbus/sys_reg_reg.h>

#include <tp/tp_dbg.h>
#include <tp/tp_drv_global.h>
#include <tp/tp_drv_verify.h>
#include <tp/tp_drv.h>
#include <tp/tp_reg_ctrl.h>



/*-----------------------------------------------------------------------------------
 * File Operations
 *------------------------------------------------------------------------------------*/

int tp_open(struct inode *inode, struct file *file)
{
        file->private_data = (void*) pTp_drv;

        return (file->private_data) ? 0 : -ENOMEM;
}


int tp_release(struct inode *inode, struct file *file)
{
        return 0;
}

long tp_ioctl(
        struct file*            file,
        unsigned int            cmd,
        unsigned long           arg
)
{
        return TPVerify_ioctl(file, cmd, arg);
}


static struct file_operations tp_fops = {
        .unlocked_ioctl = tp_ioctl,
        .open           = tp_open,
        .release        = tp_release,
};

/***************************************************************************
         ------------------- Power Management ----------------
****************************************************************************/
#ifdef CONFIG_PM
static TP_REG_INFO tp_reg_data;

TPK_TP_CLK_STU_T check_tp_clk_status(void)
{
        TP_DBG_SIMPLE( "[%s] clk:0x%x, srst:0x%x\n", __func__, SYS_REG_SYS_CLKEN1_get_clken_tp(rtd_inl(SYS_REG_SYS_CLKEN1_reg)), SYS_REG_SYS_SRST1_get_rstn_tp(rtd_inl(SYS_REG_SYS_SRST1_reg)));

        if ( SYS_REG_SYS_CLKEN1_get_clken_tp(rtd_inl(SYS_REG_SYS_CLKEN1_reg)) &&
             SYS_REG_SYS_SRST1_get_rstn_tp(rtd_inl(SYS_REG_SYS_SRST1_reg)) )
                return TP_CLK_ON;
        else
                return TP_CLK_OFF;

}

int save_tp_reigster_value_ex(void)
{
        REGADDR tp_tf_cntl_addr;
        REGADDR tp_tf_frmcfg_addr;
        REGADDR tp_tf_int_addr;
        REGADDR tp_tf_int_en_addr;

        REGADDR tp_pcr_ctl_addr;

        REGADDR tp_tp_des_cntl_addr;

        REGADDR tp_m2m_ring_limit_addr;
        REGADDR tp_m2m_ring_base_addr;
        REGADDR tp_m2m_ring_rp_addr;
        REGADDR tp_m2m_ring_wp_addr;
        REGADDR tp_m2m_ring_ctrl_addr;

        REGADDR tp_p_m2m_ring_limit_addr;
        REGADDR tp_p_m2m_ring_base_addr;
        REGADDR tp_p_m2m_ring_rp_addr;
        REGADDR tp_p_m2m_ring_wp_addr;
        REGADDR tp_p_m2m_ring_ctrl_addr;

        REGADDR tp_p_tf_cntl_addr;
        REGADDR tp_p_tf_frmcfg_addr;
        REGADDR tp_p_tf_int_addr;
        REGADDR tp_p_tf_int_en_addr;

        tp_tp_pid_ctrl_RBUS        tp_pid_ctrl_reg;
        tp_tp_sec_ctrl_RBUS        tp_sec_ctrl_reg;
        tp_tp_key_ctrl_RBUS        tp_key_ctrl_reg;
        tp_tp_ring_ctrl_RBUS       tp_ring_ctrl_reg;
        tp_tp_p_ring_ctrl_RBUS     tp_p_ring_ctrl_reg;

        TPK_TP_ENGINE_T tp_id;

        UINT8 pid_idx;
        UINT8 sec_idx;
        UINT8 key_idx;
        UINT8 buf_idx;

        for (tp_id = 0; tp_id < MAX_TP_COUNT; tp_id++) {

                switch (tp_id) {
                        case TP_TP0: {
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF0_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF0_FRMCFG_reg;
                                tp_tf_int_addr           = TP_TP_TF0_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF0_INT_EN_reg;
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
                                break;
                        }
                        case TP_TP1: {
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF1_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF1_FRMCFG_reg;
                                tp_tf_int_addr           = TP_TP_TF1_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF1_INT_EN_reg;
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
                                break;
                        }
                        case TP_TP2: {
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF2_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF2_FRMCFG_reg;
                                tp_tf_int_addr           = TP_TP_TF2_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF2_INT_EN_reg;
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

                                break;
                        }
                        case TP_TP3: {
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF3_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF3_FRMCFG_reg;
                                tp_tf_int_addr           = TP_TP_TF3_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF3_INT_EN_reg;
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
                tp_reg_data.tp_tf_cntl_reg[tp_id].regValue   = READ_REG32(tp_tf_cntl_addr);
                tp_reg_data.tp_tf_frmcfg_reg[tp_id].regValue = READ_REG32(tp_tf_frmcfg_addr);
                tp_reg_data.tp_tf_int_reg[tp_id].regValue    = READ_REG32(tp_tf_int_addr);
                tp_reg_data.tp_tf_int_en_reg[tp_id].regValue = READ_REG32(tp_tf_int_en_addr);

                /* pcr */
                tp_reg_data.tp_pcr_ctl_reg[tp_id].regValue = READ_REG32(tp_pcr_ctl_addr);

                /* tp mtp */
                tp_reg_data.tp_m2m_ring_limit_reg[tp_id].regValue = READ_REG32(tp_m2m_ring_limit_addr);
                tp_reg_data.tp_m2m_ring_base_reg[tp_id].regValue  = READ_REG32(tp_m2m_ring_base_addr);
                tp_reg_data.tp_m2m_ring_rp_reg[tp_id].regValue    = READ_REG32(tp_m2m_ring_rp_addr);
                tp_reg_data.tp_m2m_ring_wp_reg[tp_id].regValue    = READ_REG32(tp_m2m_ring_wp_addr);
                tp_reg_data.tp_m2m_ring_ctrl_reg[tp_id].regValue  = READ_REG32(tp_m2m_ring_ctrl_addr);


                if ( tp_id != TP_TP3 ) {
                        /* des & tdes */
                        tp_reg_data.tp_tp_des_cntl_reg[tp_id].regValue = READ_REG32(tp_tp_des_cntl_addr);

                        /* tpp mtp */
                        tp_reg_data.tp_p_m2m_ring_limit_reg[tp_id].regValue = READ_REG32(tp_p_m2m_ring_limit_addr);
                        tp_reg_data.tp_p_m2m_ring_base_reg[tp_id].regValue  = READ_REG32(tp_p_m2m_ring_base_addr);
                        tp_reg_data.tp_p_m2m_ring_rp_reg[tp_id].regValue    = READ_REG32(tp_p_m2m_ring_rp_addr);
                        tp_reg_data.tp_p_m2m_ring_wp_reg[tp_id].regValue    = READ_REG32(tp_p_m2m_ring_wp_addr);
                        tp_reg_data.tp_p_m2m_ring_ctrl_reg[tp_id].regValue  = READ_REG32(tp_p_m2m_ring_ctrl_addr);

                        /* tpp */
                        tp_reg_data.tp_tf_p_cntl_reg[tp_id].regValue   = READ_REG32(tp_p_tf_cntl_addr);
                        tp_reg_data.tp_tf_p_frmcfg_reg[tp_id].regValue = READ_REG32(tp_p_tf_frmcfg_addr);
                        tp_reg_data.tp_tf_p_int_reg[tp_id].regValue    = READ_REG32(tp_p_tf_int_addr);
                        tp_reg_data.tp_tf_p_int_en_reg[tp_id].regValue = READ_REG32(tp_p_tf_int_en_addr);
                }
        }

        /* tpout */
        tp_reg_data.tp_tf_out_frmcfg_reg.regValue = READ_REG32(TP_TP_TF_OUT_FRMCFG_reg);
        tp_reg_data.tp_out_ctrl_reg.regValue      = READ_REG32(TP_TP_OUT_CTRL_reg);
        tp_reg_data.tp_out_int_reg.regValue       = READ_REG32(TP_TP_OUT_INT_reg);

        /* tp input control */
        tp_reg_data.tp_in_pol_reg.regValue        = READ_REG32(TP_TP_IN_POL_reg);

        /* sync replace */
        tp_reg_data.tp_sync_rplace_reg.regValue   = READ_REG32(TP_TP_SYNC_RPLACE_reg);

        /* pid filter */
        tp_reg_data.tp_pid_part_reg.regValue      = READ_REG32(TP_TP_PID_PART_reg);
        for (pid_idx = 0; pid_idx < MAX_PID_FILTER_COUNT; pid_idx++) {
                tp_pid_ctrl_reg.regValue = 0;
                tp_pid_ctrl_reg.idx      = pid_idx;
                WRITE_REG32(TP_TP_PID_CTRL_reg, tp_pid_ctrl_reg.regValue);

                tp_reg_data.tp_pid_data_reg[pid_idx].regValue  = READ_REG32(TP_TP_PID_DATA_reg);
                tp_reg_data.tp_pid_data2_reg[pid_idx].regValue = READ_REG32(TP_TP_PID_DATA2_reg);
                tp_reg_data.tp_pid_data3_reg[pid_idx].regValue = READ_REG32(TP_TP_PID_DATA3_reg);
        }
        /* section filter */
        for (sec_idx = 0; sec_idx < MAX_SEC_COUNT; sec_idx++) {
                tp_sec_ctrl_reg.regValue = 0;
                tp_sec_ctrl_reg.idx      = sec_idx;
                WRITE_REG32(TP_TP_SEC_CTRL_reg, tp_sec_ctrl_reg.regValue);

                tp_reg_data.tp_sec_data0_reg[sec_idx].regValue = READ_REG32(TP_TP_SEC_DATA0_reg);
                tp_reg_data.tp_sec_data1_reg[sec_idx].regValue = READ_REG32(TP_TP_SEC_DATA1_reg);
                tp_reg_data.tp_sec_data2_reg[sec_idx].regValue = READ_REG32(TP_TP_SEC_DATA2_reg);
                tp_reg_data.tp_sec_data3_reg[sec_idx].regValue = READ_REG32(TP_TP_SEC_DATA3_reg);
                tp_reg_data.tp_sec_data4_reg[sec_idx].regValue = READ_REG32(TP_TP_SEC_DATA4_reg);
                tp_reg_data.tp_sec_data5_reg[sec_idx].regValue = READ_REG32(TP_TP_SEC_DATA5_reg);
                tp_reg_data.tp_sec_data6_reg[sec_idx].regValue = READ_REG32(TP_TP_SEC_DATA6_reg);
                tp_reg_data.tp_sec_data7_reg[sec_idx].regValue = READ_REG32(TP_TP_SEC_DATA7_reg);
                tp_reg_data.tp_sec_data8_reg[sec_idx].regValue = READ_REG32(TP_TP_SEC_DATA8_reg);
                tp_reg_data.tp_sec_data9_reg[sec_idx].regValue = READ_REG32(TP_TP_SEC_DATA9_reg);
        }

        /* des & tdes */
        for (key_idx = 0; key_idx < MAX_KEY_COUNT; key_idx++) {
                tp_key_ctrl_reg.regValue = 0;
                tp_key_ctrl_reg.idx      = key_idx;
                WRITE_REG32(TP_TP_KEY_CTRL_reg, tp_key_ctrl_reg.regValue);

                tp_reg_data.tp_key_info_reg[key_idx].regValue  = READ_REG32(TP_TP_KEY_INFO_0_reg);
                tp_reg_data.tp_key_info2_reg[key_idx].regValue = READ_REG32(TP_TP_KEY_INFO_1_reg);
        }

        /* crc */
        tp_reg_data.tp_crc_init_reg.regValue = READ_REG32(TP_TP_CRC_INIT_reg);

        /* tp ddr ring buffer */
        tp_reg_data.tp_threshold_reg.regValue = READ_REG32(TP_TP_THRESHOLD_reg);
        tp_reg_data.tp_fullness_reg.regValue  = READ_REG32(TP_TP_FULLNESS_reg);
        for (buf_idx = 0; buf_idx < MAX_TP_BUFFER_COUNT; buf_idx++) {
                tp_ring_ctrl_reg.regValue = 0;
                tp_ring_ctrl_reg.idx      = buf_idx;
                WRITE_REG32(TP_TP_RING_CTRL_reg, tp_ring_ctrl_reg.regValue);

                tp_reg_data.tp_ring_limit_reg[buf_idx].regValue = READ_REG32(TP_TP_RING_LIMIT_reg);
                tp_reg_data.tp_ring_base_reg[buf_idx].regValue  = READ_REG32(TP_TP_RING_BASE_reg);
                tp_reg_data.tp_ring_rp_reg[buf_idx].regValue    = READ_REG32(TP_TP_RING_RP_reg);
                tp_reg_data.tp_ring_wp_reg[buf_idx].regValue    = READ_REG32(TP_TP_RING_WP_reg);
        }
        tp_reg_data.tp_ring_avail_int_reg.regValue     = READ_REG32(TP_TP_RING_AVAIL_INT_0_reg);
        tp_reg_data.tp_ring_avail_int2_reg.regValue    = READ_REG32(TP_TP_RING_AVAIL_INT_1_reg);
        tp_reg_data.tp_ring_full_int_reg.regValue      = READ_REG32(TP_TP_RING_FULL_INT_0_reg);
        tp_reg_data.tp_ring_full_int2_reg.regValue     = READ_REG32(TP_TP_RING_FULL_INT_1_reg);
        tp_reg_data.tp_ring_avail_int_en_reg.regValue  = READ_REG32(TP_TP_RING_AVAIL_INT_EN_0_reg);
        tp_reg_data.tp_ring_avail_int_en2_reg.regValue = READ_REG32(TP_TP_RING_AVAIL_INT_EN_1_reg);
        tp_reg_data.tp_ring_full_int_en_reg.regValue   = READ_REG32(TP_TP_RING_FULL_INT_EN_0_reg);
        tp_reg_data.tp_ring_full_int_en2_reg.regValue  = READ_REG32(TP_TP_RING_FULL_INT_EN_1_reg);

        /* tp_p ring buffer */
        tp_reg_data.tp_p_threshold_reg.regValue = READ_REG32(TP_TP_P_THRESHOLD_reg);
        tp_reg_data.tp_p_fullness_reg.regValue  = READ_REG32(TP_TP_P_FULLNESS_reg);

        for (buf_idx = 0; buf_idx < MAX_TPP_BUFFER_COUNT; buf_idx++) {
                tp_p_ring_ctrl_reg.regValue = 0;
                tp_p_ring_ctrl_reg.idx      = buf_idx;
                WRITE_REG32(TP_TP_P_RING_CTRL_reg, tp_p_ring_ctrl_reg.regValue);

                /* clean tp_p ring buff data*/
                tp_reg_data.tp_p_ring_limit_reg[buf_idx].regValue = READ_REG32(TP_TP_P_RING_LIMIT_reg);
                tp_reg_data.tp_p_ring_base_reg[buf_idx].regValue  = READ_REG32(TP_TP_P_RING_BASE_reg);
                tp_reg_data.tp_p_ring_rp_reg[buf_idx].regValue    = READ_REG32(TP_TP_P_RING_BASE_reg);
                tp_reg_data.tp_p_ring_wp_reg[buf_idx].regValue    = READ_REG32(TP_TP_P_RING_BASE_reg);
        }

        tp_reg_data.tp_p_ring_avail_int_reg.regValue    = READ_REG32(TP_TP_P_RING_AVAIL_INT_reg);
        tp_reg_data.tp_p_ring_full_int_reg.regValue     = READ_REG32(TP_TP_P_RING_FULL_INT_reg);
        tp_reg_data.tp_p_ring_avail_int_en_reg.regValue = READ_REG32(TP_TP_P_RING_AVAIL_INT_EN_reg);
        tp_reg_data.tp_p_ring_full_int_en_reg.regValue  = READ_REG32(TP_TP_P_RING_FULL_INT_EN_reg);

        /* tp_p dmy_a & dmy_b */
        tp_reg_data.tp_dmy_a_reg.regValue = READ_REG32(TP_TP_DMY_A_reg);
        tp_reg_data.tp_dmy_b_reg.regValue = READ_REG32(TP_TP_DMY_B_reg);

        /* tp_p sync replace */
        tp_reg_data.tp_p_sync_rplace_reg.regValue = READ_REG32(TP_TP_P_SYNC_RPLACE_reg);

        /* frame rate control */
        tp_reg_data.prefix_ctrl_reg.regValue  = READ_REG32(TP_PREFIX_CTRL_reg);
        tp_reg_data.prefix_data1_reg.regValue = READ_REG32(TP_PREFIX_DATA1_reg);
        tp_reg_data.prefix_data2_reg.regValue = READ_REG32(TP_PREFIX_DATA2_reg);
        tp_reg_data.prefix_data3_reg.regValue = READ_REG32(TP_PREFIX_DATA3_reg);
        tp_reg_data.fr_ctrl_reg.regValue      = READ_REG32(TP_FR_CTRL_reg);

        /* start code search */
        tp_reg_data.start_code_tp0_reg.regValue      = READ_REG32(TP_START_CODE_TP0_reg);
        tp_reg_data.start_code_tp1_reg.regValue      = READ_REG32(TP_START_CODE_TP1_reg);
        tp_reg_data.start_code_ctrl_tp0_reg.regValue = READ_REG32(TP_START_CODE_CTRL_TP0_reg);
        tp_reg_data.start_code_ctrl_tp1_reg.regValue = READ_REG32(TP_START_CODE_CTRL_TP1_reg);

        /* Others */
        tp_reg_data.tp0_err_cnt_en.regValue = READ_REG32(TP_TP0_ERR_CNT_EN_reg);
        tp_reg_data.tp1_err_cnt_en.regValue = READ_REG32(TP_TP1_ERR_CNT_EN_reg);

        /* TPO CLK */
        tp_reg_data.tpout_clk_reg  = READ_REG32(SYS_REG_SYS_CLKSEL_reg);

        /* misc 27M */
        tp_reg_data.misc_27m_cfg.regValue = READ_REG32(TP_TP_MISC_27M_CFG_reg);

        return TPK_SUCCESS;
}

int restore_tp_reigster_value_ex(void)
{
        REGADDR tp_tf_cntl_addr;
        REGADDR tp_tf_frmcfg_addr;
        REGADDR tp_tf_cnt_addr;
        REGADDR tp_tf_drp_cnt_addr;
        REGADDR tp_tf_err_cnt_addr;
        REGADDR tp_tf_int_addr;
        REGADDR tp_tf_int_en_addr;

        REGADDR tp_pcr_ctl_addr;

        REGADDR tp_tp_des_cntl_addr;

        REGADDR tp_m2m_ring_limit_addr;
        REGADDR tp_m2m_ring_base_addr;
        REGADDR tp_m2m_ring_rp_addr;
        REGADDR tp_m2m_ring_wp_addr;
        REGADDR tp_m2m_ring_ctrl_addr;

        REGADDR tp_p_m2m_ring_limit_addr;
        REGADDR tp_p_m2m_ring_base_addr;
        REGADDR tp_p_m2m_ring_rp_addr;
        REGADDR tp_p_m2m_ring_wp_addr;
        REGADDR tp_p_m2m_ring_ctrl_addr;

        REGADDR tp_p_tf_cntl_addr;
        REGADDR tp_p_tf_frmcfg_addr;
        REGADDR tp_p_tf_int_addr;
        REGADDR tp_p_tf_int_en_addr;

        REGADDR tp_p_tf_cnt_addr;
        REGADDR tp_p_tf_drp_cnt_addr;

        tp_tp_pid_ctrl_RBUS        tp_pid_ctrl_reg;
        tp_tp_sec_ctrl_RBUS        tp_sec_ctrl_reg;
        tp_tp_key_ctrl_RBUS        tp_key_ctrl_reg;
        tp_tp_ring_ctrl_RBUS       tp_ring_ctrl_reg;
        tp_tp_p_ring_ctrl_RBUS     tp_p_ring_ctrl_reg;
        tp_tp_tf_out_frmcfg_RBUS   tp_tf_out_frmcfg_reg;

        TPK_TP_ENGINE_T tp_id;
        UINT8 pid_idx;
        UINT8 sec_idx;
        UINT8 key_idx;
        UINT8 buf_idx;
        UINT32 mpu_status;

        /* misc 27M */
        WRITE_REG32(TP_TP_MISC_27M_CFG_reg, tp_reg_data.misc_27m_cfg.regValue);

        /* TPO CLK */
        WRITE_REG32(SYS_REG_SYS_CLKSEL_reg, READ_REG32(SYS_REG_SYS_CLKSEL_reg) |
                    (tp_reg_data.tpout_clk_reg & (SYS_REG_SYS_CLKSEL_tp_pre_div_mask | SYS_REG_SYS_CLKSEL_tp_post_div_mask)));

        /* enable tpout clock */
        CRT_CLK_OnOff(TPOUT, CLK_ON, NULL);

        /* tp ddr ring buffer */
        WRITE_REG32(TP_TP_THRESHOLD_reg, tp_reg_data.tp_threshold_reg.regValue);
        WRITE_REG32(TP_TP_FULLNESS_reg, tp_reg_data.tp_fullness_reg.regValue);

        for (buf_idx = 0; buf_idx < MAX_TP_BUFFER_COUNT; buf_idx++) {
                WRITE_REG32(TP_TP_RING_LIMIT_reg, tp_reg_data.tp_ring_limit_reg[buf_idx].regValue);
                WRITE_REG32(TP_TP_RING_BASE_reg, tp_reg_data.tp_ring_base_reg[buf_idx].regValue);
                WRITE_REG32(TP_TP_RING_RP_reg, tp_reg_data.tp_ring_rp_reg[buf_idx].regValue);
                WRITE_REG32(TP_TP_RING_WP_reg, tp_reg_data.tp_ring_wp_reg[buf_idx].regValue);

                tp_ring_ctrl_reg.regValue = 0;
                tp_ring_ctrl_reg.r_w      = 1;
                tp_ring_ctrl_reg.idx      = buf_idx;
                WRITE_REG32(TP_TP_RING_CTRL_reg, tp_ring_ctrl_reg.regValue);
        }

        tp_reg_data.tp_ring_avail_int_reg.write_data     = 1;
        tp_reg_data.tp_ring_avail_int2_reg.write_data    = 1;
        tp_reg_data.tp_ring_full_int_reg.write_data      = 1;
        tp_reg_data.tp_ring_full_int2_reg.write_data     = 1;
        tp_reg_data.tp_ring_avail_int_en_reg.write_data  = 1;
        tp_reg_data.tp_ring_avail_int_en2_reg.write_data = 1;
        tp_reg_data.tp_ring_full_int_en_reg.write_data   = 1;
        tp_reg_data.tp_ring_full_int_en2_reg.write_data  = 1;
        WRITE_REG32(TP_TP_RING_AVAIL_INT_0_reg, tp_reg_data.tp_ring_avail_int_reg.regValue);
        WRITE_REG32(TP_TP_RING_AVAIL_INT_1_reg, tp_reg_data.tp_ring_avail_int2_reg.regValue);
        WRITE_REG32(TP_TP_RING_FULL_INT_0_reg, tp_reg_data.tp_ring_full_int_reg.regValue);
        WRITE_REG32(TP_TP_RING_FULL_INT_1_reg, tp_reg_data.tp_ring_full_int2_reg.regValue);
        WRITE_REG32(TP_TP_RING_AVAIL_INT_EN_0_reg, tp_reg_data.tp_ring_avail_int_en_reg.regValue);
        WRITE_REG32(TP_TP_RING_AVAIL_INT_EN_1_reg, tp_reg_data.tp_ring_avail_int_en2_reg.regValue);
        WRITE_REG32(TP_TP_RING_FULL_INT_EN_0_reg, tp_reg_data.tp_ring_full_int_en_reg.regValue);
        WRITE_REG32(TP_TP_RING_FULL_INT_EN_1_reg, tp_reg_data.tp_ring_full_int_en2_reg.regValue);

        /* tp_p ddr ring buffer */
        WRITE_REG32(TP_TP_P_THRESHOLD_reg, tp_reg_data.tp_p_threshold_reg.regValue);
        WRITE_REG32(TP_TP_P_FULLNESS_reg, tp_reg_data.tp_p_fullness_reg.regValue);
        for (buf_idx = 0; buf_idx < MAX_TPP_BUFFER_COUNT; buf_idx++) {
                WRITE_REG32(TP_TP_P_RING_LIMIT_reg, tp_reg_data.tp_p_ring_limit_reg[buf_idx].regValue);
                WRITE_REG32(TP_TP_P_RING_BASE_reg, tp_reg_data.tp_p_ring_base_reg[buf_idx].regValue);
                WRITE_REG32(TP_TP_P_RING_RP_reg, tp_reg_data.tp_p_ring_rp_reg[buf_idx].regValue);
                WRITE_REG32(TP_TP_P_RING_WP_reg, tp_reg_data.tp_p_ring_wp_reg[buf_idx].regValue);

                tp_p_ring_ctrl_reg.regValue = 0;
                tp_p_ring_ctrl_reg.r_w      = 1;
                tp_p_ring_ctrl_reg.idx      = buf_idx;
                WRITE_REG32(TP_TP_P_RING_CTRL_reg, tp_p_ring_ctrl_reg.regValue);
        }

        tp_reg_data.tp_p_ring_avail_int_en_reg.write_data = 1;
        tp_reg_data.tp_p_ring_full_int_en_reg.write_data  = 1;
        tp_reg_data.tp_p_ring_avail_int_en_reg.write_data = 1;
        tp_reg_data.tp_p_ring_full_int_en_reg.write_data  = 1;
        WRITE_REG32(TP_TP_P_RING_AVAIL_INT_reg, tp_reg_data.tp_p_ring_avail_int_reg.regValue);
        WRITE_REG32(TP_TP_P_RING_FULL_INT_reg, tp_reg_data.tp_p_ring_full_int_reg.regValue);
        WRITE_REG32(TP_TP_P_RING_AVAIL_INT_EN_reg, tp_reg_data.tp_p_ring_avail_int_en_reg.regValue);
        WRITE_REG32(TP_TP_P_RING_FULL_INT_EN_reg, tp_reg_data.tp_p_ring_full_int_en_reg.regValue);

        /* pid filter */
        WRITE_REG32(TP_TP_PID_PART_reg, tp_reg_data.tp_pid_part_reg.regValue);
        for (pid_idx = 0; pid_idx < MAX_PID_FILTER_COUNT; pid_idx++) {
                WRITE_REG32(TP_TP_PID_DATA_reg, tp_reg_data.tp_pid_data_reg[pid_idx].regValue);
                WRITE_REG32(TP_TP_PID_DATA2_reg, tp_reg_data.tp_pid_data2_reg[pid_idx].regValue);
                WRITE_REG32(TP_TP_PID_DATA3_reg, tp_reg_data.tp_pid_data3_reg[pid_idx].regValue);

                tp_pid_ctrl_reg.regValue = 0;
                tp_pid_ctrl_reg.r_w      = 1;
                tp_pid_ctrl_reg.idx      = pid_idx;
                WRITE_REG32(TP_TP_PID_CTRL_reg, tp_pid_ctrl_reg.regValue);
        }
        /* section filter */
        for (sec_idx = 0; sec_idx < MAX_SEC_COUNT; sec_idx++) {
                WRITE_REG32(TP_TP_SEC_DATA0_reg, tp_reg_data.tp_sec_data0_reg[sec_idx].regValue);
                WRITE_REG32(TP_TP_SEC_DATA1_reg, tp_reg_data.tp_sec_data1_reg[sec_idx].regValue);
                WRITE_REG32(TP_TP_SEC_DATA2_reg, tp_reg_data.tp_sec_data2_reg[sec_idx].regValue);
                WRITE_REG32(TP_TP_SEC_DATA3_reg, tp_reg_data.tp_sec_data3_reg[sec_idx].regValue);
                WRITE_REG32(TP_TP_SEC_DATA4_reg, tp_reg_data.tp_sec_data4_reg[sec_idx].regValue);
                WRITE_REG32(TP_TP_SEC_DATA5_reg, tp_reg_data.tp_sec_data5_reg[sec_idx].regValue);
                WRITE_REG32(TP_TP_SEC_DATA6_reg, tp_reg_data.tp_sec_data6_reg[sec_idx].regValue);
                WRITE_REG32(TP_TP_SEC_DATA7_reg, tp_reg_data.tp_sec_data7_reg[sec_idx].regValue);
                WRITE_REG32(TP_TP_SEC_DATA8_reg, tp_reg_data.tp_sec_data8_reg[sec_idx].regValue);
                WRITE_REG32(TP_TP_SEC_DATA9_reg, tp_reg_data.tp_sec_data9_reg[sec_idx].regValue);

                tp_sec_ctrl_reg.regValue = 0;
                tp_sec_ctrl_reg.r_w      = 1;
                tp_sec_ctrl_reg.idx      = sec_idx;
                WRITE_REG32(TP_TP_SEC_CTRL_reg, tp_sec_ctrl_reg.regValue);
        }

        /* des & tdes */
        for (key_idx = 0; key_idx < MAX_KEY_COUNT; key_idx++) {
                WRITE_REG32(TP_TP_KEY_INFO_0_reg, tp_reg_data.tp_key_info_reg[key_idx].regValue);
                WRITE_REG32(TP_TP_KEY_INFO_1_reg, tp_reg_data.tp_key_info_reg[key_idx].regValue);

                tp_key_ctrl_reg.regValue = 0;
                tp_key_ctrl_reg.r_w      = 1;
                tp_key_ctrl_reg.idx      = key_idx;
                WRITE_REG32(TP_TP_KEY_CTRL_reg, tp_key_ctrl_reg.regValue);
        }

        /* crc */
        WRITE_REG32(TP_TP_CRC_INIT_reg, tp_reg_data.tp_crc_init_reg.regValue);

        /* sync replace */
        WRITE_REG32(TP_TP_SYNC_RPLACE_reg, tp_reg_data.tp_sync_rplace_reg.regValue);

        /* tp_p sync replace */
        WRITE_REG32(TP_TP_P_SYNC_RPLACE_reg, tp_reg_data.tp_p_sync_rplace_reg.regValue);

        /* tp dmy_a & dmy_b */
        WRITE_REG32(TP_TP_DMY_A_reg, tp_reg_data.tp_dmy_a_reg.regValue);
        WRITE_REG32(TP_TP_DMY_B_reg, tp_reg_data.tp_dmy_b_reg.regValue);

        /* frame rate control */
        WRITE_REG32(TP_PREFIX_CTRL_reg, tp_reg_data.prefix_ctrl_reg.regValue);
        WRITE_REG32(TP_PREFIX_DATA1_reg, tp_reg_data.prefix_data1_reg.regValue);
        WRITE_REG32(TP_PREFIX_DATA2_reg, tp_reg_data.prefix_data2_reg.regValue);
        WRITE_REG32(TP_PREFIX_DATA3_reg, tp_reg_data.prefix_data3_reg.regValue);
        WRITE_REG32(TP_FR_CTRL_reg, tp_reg_data.fr_ctrl_reg.regValue);

        /* start code search */
        WRITE_REG32(TP_START_CODE_TP0_reg, tp_reg_data.start_code_tp0_reg.regValue);
        WRITE_REG32(TP_START_CODE_TP1_reg, tp_reg_data.start_code_tp1_reg.regValue);
        WRITE_REG32(TP_START_CODE_CTRL_TP0_reg, tp_reg_data.start_code_ctrl_tp0_reg.regValue);
        WRITE_REG32(TP_START_CODE_CTRL_TP1_reg, tp_reg_data.start_code_ctrl_tp1_reg.regValue);

        /* tpout */
        tp_tf_out_frmcfg_reg.regValue  = 0;
        tp_tf_out_frmcfg_reg.in_tp_rst = 1;
        WRITE_REG32(TP_TP_TF_OUT_FRMCFG_reg, tp_tf_out_frmcfg_reg.regValue);
        udelay(100);
        tp_tf_out_frmcfg_reg.in_tp_rst = 0;
        WRITE_REG32(TP_TP_TF_OUT_FRMCFG_reg, tp_tf_out_frmcfg_reg.regValue);
        udelay(100);

        WRITE_REG32(TP_TP_TF_OUT_FRMCFG_reg, tp_reg_data.tp_tf_out_frmcfg_reg.regValue);
        WRITE_REG32(TP_TP_OUT_CTRL_reg, tp_reg_data.tp_out_ctrl_reg.regValue);
        WRITE_REG32(TP_TP_OUT_INT_reg, tp_reg_data.tp_out_int_reg.regValue);

        /* tp input control */
        WRITE_REG32(TP_TP_IN_POL_reg, tp_reg_data.tp_in_pol_reg.regValue);

        /* Others */
        WRITE_REG32(TP_TP0_ERR_CNT_EN_reg, tp_reg_data.tp0_err_cnt_en.regValue);
        WRITE_REG32(TP_TP1_ERR_CNT_EN_reg, tp_reg_data.tp1_err_cnt_en.regValue);

        for (tp_id = 0; tp_id < MAX_TP_COUNT; tp_id++) {
                switch (tp_id) {
                        case TP_TP0:
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF0_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF0_FRMCFG_reg;
                                tp_tf_cnt_addr           = TP_TP_TF0_CNT_reg;
                                tp_tf_drp_cnt_addr       = TP_TP_TF0_CNT_reg;
                                tp_tf_err_cnt_addr       = TP_TP_TF0_CNT_reg;
                                tp_tf_int_addr           = TP_TP_TF0_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF0_INT_EN_reg;
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
                                tp_p_tf_drp_cnt_addr     = TP_TP_TF0_P_DRP_CNT_reg;

                                break;

                        case TP_TP1:
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF1_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF1_FRMCFG_reg;
                                tp_tf_cnt_addr           = TP_TP_TF1_CNT_reg;
                                tp_tf_drp_cnt_addr       = TP_TP_TF1_CNT_reg;
                                tp_tf_err_cnt_addr       = TP_TP_TF1_CNT_reg;
                                tp_tf_int_addr           = TP_TP_TF1_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF1_INT_EN_reg;
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
                                tp_p_tf_drp_cnt_addr     = TP_TP_TF1_P_DRP_CNT_reg;

                                break;

                        case TP_TP2:
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF2_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF2_FRMCFG_reg;
                                tp_tf_cnt_addr           = TP_TP_TF2_CNT_reg;
                                tp_tf_drp_cnt_addr       = TP_TP_TF2_CNT_reg;
                                tp_tf_err_cnt_addr       = TP_TP_TF2_CNT_reg;
                                tp_tf_int_addr           = TP_TP_TF2_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF2_INT_EN_reg;
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
                                tp_p_tf_drp_cnt_addr     = TP_TP_TF2_P_DRP_CNT_reg;

                                break;
                        case TP_TP3: {
                                /* tp */
                                tp_tf_cntl_addr          = TP_TP_TF3_CNTL_reg;
                                tp_tf_frmcfg_addr        = TP_TP_TF3_FRMCFG_reg;
                                tp_tf_cnt_addr           = TP_TP_TF3_CNT_reg;
                                tp_tf_drp_cnt_addr       = TP_TP_TF3_CNT_reg;
                                tp_tf_err_cnt_addr       = TP_TP_TF3_CNT_reg;
                                tp_tf_int_addr           = TP_TP_TF3_INT_reg;
                                tp_tf_int_en_addr        = TP_TP_TF3_INT_EN_reg;
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

                /* tp mtp */
                tp_reg_data.tp_m2m_ring_ctrl_reg[tp_id].write_data       = 1;
                WRITE_REG32(tp_m2m_ring_limit_addr, tp_reg_data.tp_m2m_ring_limit_reg[tp_id].regValue);
                WRITE_REG32(tp_m2m_ring_base_addr, tp_reg_data.tp_m2m_ring_base_reg[tp_id].regValue);
                WRITE_REG32(tp_m2m_ring_rp_addr, tp_reg_data.tp_m2m_ring_rp_reg[tp_id].regValue);
                WRITE_REG32(tp_m2m_ring_wp_addr, tp_reg_data.tp_m2m_ring_wp_reg[tp_id].regValue);
                WRITE_REG32(tp_m2m_ring_ctrl_addr, tp_reg_data.tp_m2m_ring_ctrl_reg[tp_id].regValue);

                /* pcr */
                WRITE_REG32(tp_pcr_ctl_addr, tp_reg_data.tp_pcr_ctl_reg[tp_id].regValue);

                /* tp */
                tp_reg_data.tp_tf_cntl_reg[tp_id].write_data   = 1;
                tp_reg_data.tp_tf_int_reg[tp_id].write_data    = 1;
                tp_reg_data.tp_tf_int_en_reg[tp_id].write_data = 1;
                WRITE_REG32(tp_tf_cntl_addr, tp_reg_data.tp_tf_cntl_reg[tp_id].regValue);
                WRITE_REG32(tp_tf_frmcfg_addr, tp_reg_data.tp_tf_frmcfg_reg[tp_id].regValue);
                WRITE_REG32(tp_tf_cnt_addr, _ZERO);
                WRITE_REG32(tp_tf_drp_cnt_addr, _ZERO);
                WRITE_REG32(tp_tf_err_cnt_addr, _ZERO);
                WRITE_REG32(tp_tf_int_addr, tp_reg_data.tp_tf_int_reg[tp_id].regValue);
                WRITE_REG32(tp_tf_int_en_addr, tp_reg_data.tp_tf_int_en_reg[tp_id].regValue);

                if ( tp_id != TP_TP3 ) {
                        /* des & tdes */
                        WRITE_REG32(tp_tp_des_cntl_addr, tp_reg_data.tp_tp_des_cntl_reg[tp_id].regValue);
                        /* tpp mtp */
                        tp_reg_data.tp_p_m2m_ring_ctrl_reg[tp_id].write_data = 1;
                        WRITE_REG32(tp_p_m2m_ring_limit_addr, tp_reg_data.tp_p_m2m_ring_limit_reg[tp_id].regValue);
                        WRITE_REG32(tp_p_m2m_ring_base_addr, tp_reg_data.tp_p_m2m_ring_base_reg[tp_id].regValue);
                        WRITE_REG32(tp_p_m2m_ring_rp_addr, tp_reg_data.tp_p_m2m_ring_rp_reg[tp_id].regValue);
                        WRITE_REG32(tp_p_m2m_ring_wp_addr, tp_reg_data.tp_p_m2m_ring_wp_reg[tp_id].regValue);
                        WRITE_REG32(tp_p_m2m_ring_ctrl_addr, tp_reg_data.tp_p_m2m_ring_ctrl_reg[tp_id].regValue);
                        /* tp_p */
                        tp_reg_data.tp_tf_p_cntl_reg[tp_id].write_data   = 1;
                        tp_reg_data.tp_tf_p_int_reg[tp_id].write_data    = 1;
                        tp_reg_data.tp_tf_p_int_en_reg[tp_id].write_data = 1;
                        WRITE_REG32(tp_p_tf_cntl_addr, tp_reg_data.tp_tf_p_cntl_reg[tp_id].regValue);
                        WRITE_REG32(tp_p_tf_frmcfg_addr, tp_reg_data.tp_tf_p_frmcfg_reg[tp_id].regValue);
                        WRITE_REG32(tp_p_tf_int_addr, tp_reg_data.tp_tf_p_int_reg[tp_id].regValue);
                        WRITE_REG32(tp_p_tf_int_en_addr, tp_reg_data.tp_tf_p_int_en_reg[tp_id].regValue);

                        WRITE_REG32(tp_p_tf_cnt_addr, _ZERO);
                        WRITE_REG32(tp_p_tf_drp_cnt_addr, _ZERO);
                }

        }

        return TPK_SUCCESS;
}


static int tp_suspend(struct device *dev)
{
        INT32 ret = 0;

        TP_DBG_SIMPLE( "do tp_suspend\n");

        ret = save_tp_reigster_value_ex();
        if ( ret == TPK_SUCCESS ) {
                /* disable tp clock */
                CRT_CLK_OnOff(TP, CLK_OFF, NULL);
        }

        TP_DBG_SIMPLE( "do tp_suspend finish\n");
        return 0;
}

static int tp_resume(struct device *dev)
{
        TP_DBG_SIMPLE( "do tp_resume\n");

        /* enable tp clock and restore tp register value */
        if ( check_tp_clk_status() != TP_CLK_ON ) {
                CRT_CLK_OnOff(TP, CLK_ON, NULL);
        }
        restore_tp_reigster_value_ex();

        TP_DBG_SIMPLE( "do tp_resume finish\n");
        return 0;
}

#ifdef CONFIG_HIBERNATION
static int tp_poweroff(struct device *dev)
{
        /* TO BE IMPLEMENT */
        TP_DBG_SIMPLE( "do tp_poweroff\n");
        /* do nothing */
        TP_DBG_SIMPLE( "do tp_poweroff finish\n");
        return 0;
}

static int tp_restore(struct device *dev)
{
        TP_DBG_SIMPLE( "do tp_restore\n");

        /* enable tp clock and restore tp register value */
        if ( check_tp_clk_status() != TP_CLK_ON ) {
                CRT_CLK_OnOff(TP, CLK_ON, NULL);
        }
        restore_tp_reigster_value_ex();

        TP_DBG_SIMPLE( "do tp_restore finish\n");
        return 0;
}

static int tp_freeze(struct device *dev)
{
        INT32 ret;
        ret = 0;

        TP_DBG_SIMPLE( "do tp_freeze \n");

        ret = save_tp_reigster_value_ex();
        if ( ret == TPK_SUCCESS ) {
                /* disable tp clock */
                CRT_CLK_OnOff(TP, CLK_OFF, NULL);
                TP_DBG_SIMPLE( "disable tp clock finish\n");
        }

        TP_DBG_SIMPLE( "do tp_freeze finish \n");
        return 0;
}
static int tp_thaw(struct device *dev)
{
        TP_DBG_SIMPLE( "do tp_thaw\n");

        /* enable tp clock and restore tp register value */
        if ( check_tp_clk_status() != TP_CLK_ON ) {
                CRT_CLK_OnOff(TP, CLK_ON, NULL);
        }
        restore_tp_reigster_value_ex();

        TP_DBG_SIMPLE( "do tp_thaw finish\n");
        return 0;
}
#endif

static struct platform_device *tp_platform_devs;


static const struct dev_pm_ops tp_pm_ops = {
        .suspend_noirq    = tp_suspend,
        .resume_noirq     = tp_resume,
#ifdef CONFIG_HIBERNATION
        .freeze_noirq     = tp_freeze,
        .thaw_noirq       = tp_thaw,
        .poweroff_noirq   = tp_poweroff,
        .restore_noirq    = tp_restore,
#endif
};



static struct platform_driver tp_platform_driver = {
        .driver = {
                .name         = (char *)TP_DRIVER_NAME,
                .bus          = &platform_bus_type,
#ifdef CONFIG_PM
                .pm           = &tp_pm_ops,
#endif
        },
};
#endif /* CONFIG_PM */

/***************************************************************************
         ------------------- module Init ----------------
****************************************************************************/
static struct miscdevice tp_miscdev = {
        MISC_DYNAMIC_MINOR,
        TP_DRIVER_NAME,
        &tp_fops
};

int __init tp_module_init(void)
{
        TP_DBG( "Initial TP module\n");
        if (TPVerify_CreateSectionBuffer() < 0) {
                return -1;
        }
        create_tp_controller();

        if (pTp_drv == NULL) {
                return -1;
        }

        if (misc_register(&tp_miscdev)) {
                release_tp_controller();
                pTp_drv = NULL;
                return -1;
        }

#ifdef CONFIG_PM
        tp_platform_devs = platform_device_register_simple(TP_DRIVER_NAME, -1, NULL, 0);
        TP_DBG( "TP platform device name %s\n", TP_DRIVER_NAME);

        if(platform_driver_register(&tp_platform_driver) != 0) {
                platform_device_unregister(tp_platform_devs);
                tp_platform_devs = NULL;
                TP_ERROR( "TP platform driver register fail\n");
                return -1;
        }
#endif

        TP_DBG( "Initial TP module successed\n");
        return 0;
}

static void __exit tp_module_exit(void)
{

        TP_DBG( "[TP] Release TP module\n");
        release_tp_controller();
        misc_deregister(&tp_miscdev);

        TPVerify_ReleaseSectionBuffer();
        TP_DBG( "[TP] Release TP module successed\n");
}

module_init(tp_module_init);
module_exit(tp_module_exit);

MODULE_AUTHOR( "Andrew Feng, Realtek Semiconductor");
MODULE_LICENSE( "GPL");
