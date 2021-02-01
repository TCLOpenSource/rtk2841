/**
* @file rbusIFDReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2011/12/12
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_IFD_REG_H_
#define _RBUS_IFD_REG_H_

#include "rbusTypes.h"




// IFD Register Address

#define IFD_CR_BPF_SEL_VADDR                   (0xb8032000)
#define IFD_CR_BPF_READ_VADDR                  (0xb8032004)
#define IFD_CR_PGAIN_VADDR                     (0xb8032008)
#define IFD_CR_LOCK_VADDR                      (0xb803200c)
#define IFD_CR_NCO_FIX_DATA_VADDR              (0xb8032010)
#define IFD_CR_FREQ_SAT_VADDR                  (0xb8032014)
#define IFD_CR_FREQ_STATUS_VADDR               (0xb8032018)
#define IFD_CR_WEIGHT_EN_VADDR                 (0xb803201c)
#define IFD_CR_SINE_PART_INNER_LPF_VADDR       (0xb8032020)
#define IFD_CR_INNER_LPF_1_VADDR               (0xb8032024)
#define IFD_CR_INNER_LPF_2_VADDR               (0xb8032028)
#define IFD_DUMMY1_VADDR                       (0xb803202c)
#define IFD_DUMMY2_VADDR                       (0xb8032030)
#define IFD_DUMMY3_VADDR                       (0xb8032034)
#define IFD_DUMMY4_VADDR                       (0xb8032038)
#define IFD_DUMMY5_VADDR                       (0xb803203c)
#define IFD_SHAPE_FILTER_SELECTION_VADDR       (0xb8032040)
#define IFD_SOFT_RESET_27_CLK_PHASE_VADDR      (0xb8032048)
#define IFD_DMA_VADDR                          (0xb803204c)
#define IFD_CR_LOCK_THD_VADDR                  (0xb8032050)
#define IFD_CR_AUTO_RESET_EN_VADDR             (0xb8032054)
#define IFD_CR_PHASE_INVERSE_VADDR             (0xb8032058)
#define IFD_CR_SHIFT_EN_VADDR                  (0xb8032060)
#define IFD_CR_DATA_GAIN_EN_VADDR              (0xb8032064)
#define IFD_CR_PHASE_ERROR_SEL_VADDR           (0xb8032068)
#define IFD_CR_BPF_MASK_EN_VADDR               (0xb8032070)
#define IFD_CR_BPF_MASK_THR_VADDR              (0xb8032074)
#define IFD_DATA_GAIN_MASK_THR_VADDR           (0xb8032078)
#define IFD_DECIMATION_FILTER_ENABLE_VADDR     (0xb8032080)
#define IFD_OUTPUT_LPF_VSYNC_START_VADDR       (0xb8032084)
#define IFD_RESAMPLER_STATUS_VADDR             (0xb803208c)
#define IFD_CR_PHASE_ERROR_AVG_SET_VADDR       (0xb8032090)
#define IFD_CR_PHASE_ERROR_AVG_STATUS_VADDR    (0xb8032094)
#define IFD_CR_FREQ_ERROR_AVG_SET_VADDR        (0xb80320a0)
#define IFD_CR_FREQ_ERROR_AVG_STATUS_VADDR     (0xb80320a4)
#define IFD_CR_VSYNC_START_VADDR               (0xb80320a8)
#define IFD_CR_HSYNC_START_VADDR               (0xb80320ac)
#define IFD_POWER_CAL_VADDR                    (0xb80320b0)
#define IFD_DATA_SHAPED_FLAG_VADDR             (0xb80320b4)
#define IFD_FREQ_OFFSET_POWER_STATUS_VADDR     (0xb80320b8)
#define IFD_DIFF_POWER_STATUS_VADDR            (0xb80320bc)
#define IFD_MOD_DETECT_MAX_CNTL_VADDR          (0xb80320c0)
#define IFD_MOD_DETECT_MIN_CNTL_VADDR          (0xb80320c4)
#define IFD_MOD_DETECT_UPDATE_CNTL_VADDR       (0xb80320c8)
#define IFD_MOD_DETECT_THR_VADDR               (0xb80320cc)
#define IFD_MOD_DETECT_STATE_VADDR             (0xb80320d0)
#define IFD_MOD_DETECT_OUT_VADDR               (0xb80320d4)
#define IFD_MOD_DETECT_AUTO_VADDR              (0xb80320d8)
#define IFD_CR_STATE_DEBOUNCE_VADDR            (0xb80320e0)
#define IFD_CR_STATE_THR1_VADDR                (0xb80320e4)
#define IFD_CR_STATE_THR2_VADDR                (0xb80320e8)
#define IFD_CR_STATE_THR3_VADDR                (0xb80320ec)
#define IFD_CR_STATE_THR4_VADDR                (0xb80320f0)
#define IFD_CR_STATE_CNTL_VADDR                (0xb80320f4)
#define IFD_CR_STATE_READ_VADDR                (0xb80320f8)
#define IFD_CR_STATE_WEIGHT_SHIFT_VADDR        (0xb80320fc)
#define IFD_AGC_ENABLE_SEL_VADDR               (0xb8032100)
#define IFD_AGC_MAX_LIMIT_CNT_1_VADDR          (0xb8032104)
#define IFD_AGC_MAX_COUNT_FOR_COARSE_MODE_AGC_CNTL1_VADDR  (0xb8032108)
#define IFD_AGC_MAX_COUNT_FOR_FINE_LOCK_MODE_AGC_CNTL2_VADDR  (0xb803210c)
#define IFD_AGC_AVG_TARGET_VADDR               (0xb8032110)
#define IFD_AGC_MAX_COUNT_FOR_COARSE_MODE_AGC_LOCK2_VADDR  (0xb8032114)
#define IFD_AGC_TARG_VAL_VADDR                 (0xb8032118)
#define IFD_AGC_CNTL_SEL_VADDR                 (0xb803211c)
#define IFD_AGC_MANU_VALUE_VADDR               (0xb8032120)
#define IFD_AGC_IF_MANU_VALUE_VADDR            (0xb8032124)
#define IFD_AGC_RF_MANU_VALUE_VADDR            (0xb8032128)
#define IFD_KI_VAL_VADDR                       (0xb803212c)
#define IFD_IF_AGC_MIN_VADDR                   (0xb8032130)
#define IFD_RF_AGC_LIMIT_VALUE_VADDR           (0xb8032134)
#define IFD_AGC_LOCK_LEN_VADDR                 (0xb8032138)
#define IFD_AGC_LOCK_TH_VADDR                  (0xb803213c)
#define IFD_AGC_LOCK_STATUS_VADDR              (0xb8032140)
#define IFD_AGC_HSYNC_START_VADDR              (0xb8032144)
#define IFD_AGC_VSYNC_START1_VADDR             (0xb8032148)
#define IFD_AGC_PEAK_DETECT_VADDR              (0xb8032150)
#define IFD_AGC_PEAK_VALUE_VADDR               (0xb8032154)
#define IFD_AGC_MAX_STATUS_VADDR               (0xb803215c)
#define IFD_AGC_ERR0_STATUS_VADDR              (0xb8032160)
#define IFD_AGC_ACC3_STATUS_VADDR              (0xb8032164)
#define IFD_AGC_IF_STATUS_VADDR                (0xb8032168)
#define IFD_AGC_RF_STATUS_VADDR                (0xb803216c)
#define IFD_AGC_PGA_1_VADDR                    (0xb8032170)
#define IFD_AGC_RF_HASTEN_VADDR                (0xb8032174)
#define IFD_AGC_SEP_RF_IF_VADDR                (0xb8032178)
#define IFD_VTOP_VALUE_VADDR                   (0xb8032180)
#define IFD_KRF_VALUE_VADDR                    (0xb8032184)
#define IFD_READ_PGA_VADDR                     (0xb8032188)
#define IFD_NOISE_CAL_VADDR                    (0xb803218c)
#define IFD_AGC_LINEBASE_CTL_VADDR             (0xb8032198)
#define IFD_AGC_MAX2_CNT_1_VADDR               (0xb803219c)
#define IFD_AGC_IN_KP_KI_VADDR                 (0xb80321a0)
#define IFD_AGC_IN_MAX_MIN_VADDR               (0xb80321a4)
#define IFD_AGC_MAX2_LIMIT_CNT_1_VADDR         (0xb80321ac)
#define IFD_AGC_LOOOP2_ERR_VADDR               (0xb80321b0)
#define IFD_AGC_INNER_STATUS_VADDR             (0xb80321b4)
#define IFD_LOOP2_KP_KI_ERR_VADDR              (0xb80321b8)
#define IFD_READ_LOOP2_MAX_VADDR               (0xb80321bc)
#define IFD_AGC_PEAK2_DETECT_VADDR             (0xb80321c0)
#define IFD_AGC_PEAK2_STATUS_VADDR             (0xb80321c8)
#define IFD_AGC_LOOP2_CNTL_VADDR               (0xb80321d0)
#define IFD_SIGMA_DELTA_CNTL_VADDR             (0xb80321d4)
#define IFD_AGC_INTERRUPT_THD_VADDR            (0xb80321d8)
#define IFD_AGC_2STEP_EN_VADDR                 (0xb80321dc)
#define IFD_AGC_DGAIN_STEP_VADDR               (0xb80321e0)
#define IFD_AGC_DGAIN_THR_VADDR                (0xb80321e4)
#define IFD_AGC_DGAIN_TO_PGA_VADDR             (0xb80321e8)
#define IFD_AGC_DGAIN_VIRTUAL_PGA_HSYNC_GATE_VADDR  (0xb80321ec)
#define IFD_INTERRUPT_MASK_EN_VADDR            (0xb80321f0)
#define IFD_AGC_FINE_TUNE_DOWN_SAMPLE_VADDR    (0xb80321f4)
#define IFD_AGC_2STEP_STATUS_VADDR             (0xb80321f8)
#define IFD_AGC_GAIN_AVG_CTRL_VADDR            (0xb8032200)
#define IFD_AGC_GAIN_STATUS_VADDR              (0xb8032204)
#define IFD_AGC_ADAPT_TARG_CNTL_VADDR          (0xb8032208)
#define IFD_AGC_ADAPT_TARG_INC_THR_VADDR       (0xb803220c)
#define IFD_AGC_ADAPT_TARG_MIN_VAL_VADDR       (0xb8032210)
#define IFD_AGC_ADAPT_TARG_FINE_MODE_VADDR     (0xb8032214)
#define IFD_AGC_ADAPT_TARG_STATUS_VADDR        (0xb8032218)
#define IFD_IMPULSIVE_GATE_SET_VADDR           (0xb8032220)
#define IFD_IMPULSIVE_GATE_SETII_VADDR         (0xb8032224)
#define IFD_AGC_SYNC_LEVEL_STATUS_VADDR        (0xb8032230)
#define IFD_AGC_MAX_VAR_STATUS_VADDR           (0xb8032234)
#define IFD_AGC_HUM_CTRL_VADDR                 (0xb8032238)
#define IFD_AGC_HUM_MAX_THR_VADDR              (0xb803223c)
#define IFD_AGC_HUM_SYNC_LEVEL_THR_VADDR       (0xb8032240)
#define IFD_PGA_INT_THR_VADDR                  (0xb8032250)
#define IFD_RF_INT_THR_VADDR                   (0xb8032254)
#define IFD_IF_INT_THR_VADDR                   (0xb8032258)
#define IFD_AGC_PEAK_LSADC_VADDR               (0xb8032260)
#define IFD_AUTO_PGA_MIN_VADDR                 (0xb8032264)
#define IFD_LSADC_OUT_VADDR                    (0xb8032268)
#define IFD_PGA_MIN_STATUS_VADDR               (0xb803226c)
#define IFD_INPUT_POWER_CTRL_VADDR             (0xb8032280)
#define IFD_NCO_IF_VADDR                       (0xb8032284)
#define IFD_NCO_SEQUENTIAL1_VADDR              (0xb8032288)
#define IFD_NCO_SEQUENTIAL2_VADDR              (0xb803228c)
#define IFD_NCO_SEQUENTIAL3_VADDR              (0xb8032290)
#define IFD_NCO_SEQUENTIAL4_VADDR              (0xb8032294)
#define IFD_NCO_SCAN_RANGE1_VADDR              (0xb8032298)
#define IFD_NCO_SCAN_RANGE4_VADDR              (0xb803229c)
#define IFD_INPUT_POWER_OUTPUT_IF_VADDR        (0xb80322a0)
#define IFD_INPUT_POWER_OUTPUT_00_VADDR        (0xb80322a4)
#define IFD_INPUT_POWER_OUTPUT_01_VADDR        (0xb80322a8)
#define IFD_INPUT_POWER_OUTPUT_02_VADDR        (0xb80322ac)
#define IFD_INPUT_POWER_OUTPUT_03_VADDR        (0xb80322b0)
#define IFD_INPUT_POWER_OUTPUT_04_VADDR        (0xb80322b4)
#define IFD_INPUT_POWER_OUTPUT_05_VADDR        (0xb80322b8)
#define IFD_INPUT_POWER_DONE_VADDR             (0xb80322bc)
#define IFD_DEBUG_MODE_VADDR                   (0xb8032340)
#define IFD_DEBUG_MODE3_VADDR                  (0xb8032344)
#define IFD_TEST_MODE_VADDR                    (0xb8032348)
#define IFD_CR_SELF_TEST_VADDR                 (0xb803234c)
#define IFD_CRC_CTRL_REGISTER_VADDR            (0xb8032350)
#define IFD_CRC2_RESULT_VADDR                  (0xb8032358)
#define IFD_DACTEST_REGISTER1_VADDR            (0xb803235c)
#define IFD_AD_BYPASS_ENABLE_VADDR               (0xb8032360)
#define IFD_TUNER_VSYNC_START_VADDR            (0xb8032370)
#define IFD_FPGA_TEST1_VADDR                   (0xb8032380)
#define IFD_FPGA_TEST2_VADDR                   (0xb8032384)
#define IFD_FPGA_TEST3_VADDR                   (0xb8032388)
#define IFD_FPGA_TEST4_DEBUG_CLK_VADDR         (0xb803238c)
#define IFD_AGC_RF_RECORD_0_1_VADDR            (0xb8032800)
#define IFD_AGC_RF_RECORD_2_3_VADDR            (0xb8032804)
#define IFD_AGC_RF_RECORD_4_5_VADDR            (0xb8032808)
#define IFD_AGC_RF_RECORD_6_7_VADDR            (0xb803280c)
#define IFD_AGC_RF_RECORD_8_9_VADDR            (0xb8032810)
#define IFD_AGC_RF_RECORD_10_11_VADDR          (0xb8032814)
#define IFD_AGC_RF_RECORD_12_13_VADDR          (0xb8032818)
#define IFD_AGC_RF_RECORD_14_15_VADDR          (0xb803281c)
#define IFD_AGC_RF_RECORD_16_17_VADDR          (0xb8032820)
#define IFD_AGC_RF_RECORD_18_19_VADDR          (0xb8032824)
#define IFD_AGC_RF_RECORD_20_21_VADDR          (0xb8032828)
#define IFD_AGC_RF_RECORD_22_23_VADDR          (0xb803282c)
#define IFD_AGC_RF_RECORD_24_25_VADDR          (0xb8032830)
#define IFD_AGC_RF_RECORD_26_27_VADDR          (0xb8032834)
#define IFD_AGC_RF_RECORD_28_29_VADDR          (0xb8032838)
#define IFD_AGC_RF_RECORD_30_31_VADDR          (0xb803283c)
#define IFD_AGC_RF_RECORD_32_33_VADDR          (0xb8032840)
#define IFD_AGC_RF_RECORD_34_35_VADDR          (0xb8032844)
#define IFD_AGC_RF_RECORD_36_37_VADDR          (0xb8032848)
#define IFD_AGC_RF_RECORD_38_39_VADDR          (0xb803284c)
#define IFD_AGC_RF_RECORD_40_41_VADDR          (0xb8032850)
#define IFD_AGC_RF_RECORD_42_43_VADDR          (0xb8032854)
#define IFD_AGC_RF_RECORD_44_45_VADDR          (0xb8032858)
#define IFD_AGC_RF_RECORD_46_47_VADDR          (0xb803285c)
#define IFD_AGC_RF_RECORD_48_49_VADDR          (0xb8032860)
#define IFD_AGC_RF_RECORD_50_51_VADDR          (0xb8032864)
#define IFD_AGC_RF_RECORD_52_53_VADDR          (0xb8032868)
#define IFD_AGC_RF_RECORD_54_55_VADDR          (0xb803286c)
#define IFD_AGC_RF_RECORD_56_57_VADDR          (0xb8032870)
#define IFD_AGC_RF_RECORD_58_59_VADDR          (0xb8032874)
#define IFD_AGC_RF_RECORD_60_61_VADDR          (0xb8032878)
#define IFD_AGC_RF_RECORD_62_63_VADDR          (0xb803287c)
#define IFD_AGC_RF_RECORD_64_65_VADDR          (0xb8032880)
#define IFD_AGC_RF_RECORD_66_67_VADDR          (0xb8032884)
#define IFD_AGC_RF_RECORD_68_69_VADDR          (0xb8032888)
#define IFD_AGC_RF_RECORD_70_71_VADDR          (0xb803288c)
#define IFD_AGC_RF_RECORD_72_73_VADDR          (0xb8032890)
#define IFD_AGC_RF_RECORD_74_75_VADDR          (0xb8032894)
#define IFD_AGC_RF_RECORD_76_77_VADDR          (0xb8032898)
#define IFD_AGC_RF_RECORD_78_79_VADDR          (0xb803289c)
#define IFD_AGC_RF_RECORD_80_81_VADDR          (0xb80328a0)
#define IFD_AGC_RF_RECORD_82_83_VADDR          (0xb80328a4)
#define IFD_AGC_RF_RECORD_84_85_VADDR          (0xb80328a8)
#define IFD_AGC_RF_RECORD_86_87_VADDR          (0xb80328ac)
#define IFD_AGC_RF_RECORD_88_89_VADDR          (0xb80328b0)
#define IFD_AGC_RF_RECORD_90_91_VADDR          (0xb80328b4)
#define IFD_AGC_RF_RECORD_92_93_VADDR          (0xb80328b8)
#define IFD_AGC_RF_RECORD_94_95_VADDR          (0xb80328bc)
#define IFD_AGC_RF_RECORD_96_97_VADDR          (0xb80328c0)
#define IFD_AGC_RF_RECORD_98_99_VADDR          (0xb80328c4)
#define IFD_AGC_RF_RECORD_ENABLE_VADDR         (0xb80328c8)





#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======IFD register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_delay:4;
        RBus_UInt32  cr_inner_lpf_sel:1;
        RBus_UInt32  cr_inner_lpf_en:1;
        RBus_UInt32  cr_bpf_en:1;
        RBus_UInt32  cr_bpf_coe_modify_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_bpf_coe_tap:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_bpf_coe:15;
    };
}cr_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cr_bpf_coe_read_tap:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_bpf_coe_read:15;
    };
}cr_bpf_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_st4_kp:4;
        RBus_UInt32  cr_st4_ki:4;
        RBus_UInt32  cr_st2_kp:4;
        RBus_UInt32  cr_st2_ki:4;
        RBus_UInt32  cr_st0_kp:4;
        RBus_UInt32  cr_st0_ki:4;
        RBus_UInt32  cr_pgain:4;
        RBus_UInt32  cr_igain:4;
    };
}cr_pgain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_lock_freq_thr:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_lock_with_freq:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cr_lock_with_hsync:1;
        RBus_UInt32  cr_lock_with_agc:1;
        RBus_UInt32  cr_lock_ref:8;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_lock:1;
    };
}cr_lock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cr_ncoerr_en:1;
        RBus_UInt32  cr_nco_fix_data:20;
    };
}cr_nco_fix_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  cr_offset_sat:17;
    };
}cr_freq_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  cr_freq_status:20;
    };
}cr_freq_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cr_weighting_thr:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_weighting_thr_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  cr_weighting_cr_lock_dis:1;
        RBus_UInt32  cr_weighting_en:1;
        RBus_UInt32  cr_weight_max_decrease:4;
        RBus_UInt32  cr_weight_shift:4;
    };
}cr_weight_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  sin_sample_d:15;
    };
}cr_sine_part_inner_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_inner_lpf_tap1:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_inner_lpf_tap0:15;
    };
}cr_inner_lpf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_inner_lpf_tap3:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_inner_lpf_tap2:15;
    };
}cr_inner_lpf_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}dummy2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy3:32;
    };
}dummy3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy4:32;
    };
}dummy4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy5:32;
    };
}dummy5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  data_gain:15;
        RBus_UInt32  res2:3;
        RBus_UInt32  data_gain_mask_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  data_gain_sel:3;
        RBus_UInt32  shaping_bw_sel:4;
        RBus_UInt32  res4:3;
        RBus_UInt32  shaping_image_sel:1;
    };
}shape_filter_selection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ifd_int_mask:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  soft_reset:1;
    };
}soft_reset_27_clk_phase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dma_fifo_debug_full:1;
        RBus_UInt32  dma_fifo_debug_empty:1;
        RBus_UInt32  dma_fifo_adc_full:1;
        RBus_UInt32  dma_fifo_adc_empty:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dma_full:1;
        RBus_UInt32  dma_empty:1;
    };
}dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cr_lock_thd:8;
        RBus_UInt32  cr_lock_len:8;
        RBus_UInt32  cr_cnt_thd:8;
    };
}cr_lock_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_nco_offset:16;
        RBus_UInt32  res1:2;
        RBus_UInt32  cr_sin_trunc_len:2;
        RBus_UInt32  cr_track_len:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_unlock_track_en:1;
        RBus_UInt32  cr_reset_track_en:1;
        RBus_UInt32  cr_nco_track_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_auto_reset_en:1;
    };
}cr_auto_reset_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cr_phase_inverse_en_st4:1;
        RBus_UInt32  cr_phase_inverse_en_st2:1;
        RBus_UInt32  cr_phase_inverse_en_st0:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_phase_inverse_thr:15;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_cordic_phase_modify_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  cr_phase_inverse_fine_lock_dis:1;
        RBus_UInt32  cr_phase_inverse_cr_lock_dis:1;
        RBus_UInt32  cr_phase_inverse_en:1;
    };
}cr_phase_inverse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_fm_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_shift_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_shift_polar:1;
        RBus_UInt32  cr_shift_nco_offset:20;
    };
}cr_shift_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  cr_less_delay:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_data_gain_en:1;
    };
}cr_data_gain_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  cr_phase_error_sel:2;
    };
}cr_phase_error_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cr_bpf_mask_en:1;
    };
}cr_bpf_mask_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bpf_mask_out_thr:16;
        RBus_UInt32  cr_bpf_mask_in_thr:16;
    };
}cr_bpf_mask_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_gain_mask_out_thr:16;
        RBus_UInt32  data_gain_mask_in_thr:16;
    };
}data_gain_mask_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  decimation_en:1;
        RBus_UInt32  res2:20;
    };
}decimation_filter_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lpf_vsync_start:16;
        RBus_UInt32  lpf_vsync_end:16;
    };
}output_lpf_vsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  fifo_full_clear:1;
        RBus_UInt32  fifo_empty_clear:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  fifo_full:1;
        RBus_UInt32  fifo_empty:1;
    };
}resampler_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  cr_phase_error_avg_src:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_phase_error_avg_vcatch:1;
        RBus_UInt32  cr_phase_error_avg_interval:12;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_phase_error_avg_length:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  cr_phase_error_avg_linebase:1;
    };
}cr_phase_error_avg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cr_phase_error_mean:12;
        RBus_UInt32  cr_phase_error_var:12;
    };
}cr_phase_error_avg_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_error_avg_vinterval:11;
        RBus_UInt32  cr_freq_error_avg_vcatch:1;
        RBus_UInt32  cr_freq_error_avg_interval:12;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_freq_error_avg_length:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_freq_error_avg_linebase:1;
    };
}cr_freq_error_avg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_error_mean:16;
        RBus_UInt32  cr_freq_error_var:16;
    };
}cr_freq_error_avg_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_vsync_start:16;
        RBus_UInt32  cr_vsync_end:16;
    };
}cr_vsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  cr_hsync_start:8;
        RBus_UInt32  cr_hsync_end:8;
    };
}cr_hsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  power_nco_offset:20;
        RBus_UInt32  res1:3;
        RBus_UInt32  power_cal_reset:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  power_cal_len:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  power_cal_shift:3;
    };
}power_cal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  data_shaped_ready:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  data_shaped:1;
        RBus_UInt32  data_shaped_thr:16;
    };
}data_shaped_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  power_offset_pos:16;
        RBus_UInt32  power_offset_neg:16;
    };
}freq_offset_power_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  power_offset_diff:16;
        RBus_UInt32  power_offset_diff_avg:16;
    };
}diff_power_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  mod_max_out:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  mod_max_slow_charge_en:1;
        RBus_UInt32  mod_max_slow_charge_value:5;
        RBus_UInt32  mod_max_cntl:12;
    };
}mod_detect_max_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  mod_min_out:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  mod_min_slow_charge_en:1;
        RBus_UInt32  mod_min_slow_charge_value:5;
        RBus_UInt32  mod_min_cntl:12;
    };
}mod_detect_min_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mod_update_cntl:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  mod_reset:1;
    };
}mod_detect_update_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  mod_state_thr:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  neg_mod_thr:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  pos_mod_thr:11;
    };
}mod_detect_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  min_diff_min:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  mod_neg_cnt:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  mod_pos_cnt:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  uncertain_mod_cnt:3;
        RBus_UInt32  res5:2;
        RBus_UInt32  mod_state:2;
    };
}mod_detect_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  min_diff_max:11;
        RBus_UInt32  min_diff_value:12;
    };
}mod_detect_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  mod_relate_cr:1;
        RBus_UInt32  mod_relate_cr_thr:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  mod_once_auto_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  mod_auto_en:1;
    };
}mod_detect_auto_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_st4_dn_debounce:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_st3_dn_debounce:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_st3_up_debounce:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  cr_st2_dn_debounce:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  cr_st2_up_debounce:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  cr_st1_dn_debounce:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  cr_st1_up_debounce:3;
        RBus_UInt32  res8:1;
        RBus_UInt32  cr_st0_up_debounce:3;
    };
}cr_state_debounce_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cr_phase_var_st0_thr:12;
        RBus_UInt32  cr_freq_var_st0_thr:16;
    };
}cr_state_thr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cr_phase_var_st2_thr:12;
        RBus_UInt32  cr_freq_varvcheck_thr:16;
    };
}cr_state_thr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_var_st2_up_thr:16;
        RBus_UInt32  cr_freq_var_st2_low_thr:16;
    };
}cr_state_thr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_var_st4_thr:16;
        RBus_UInt32  cr_freq_var_st3_thr:16;
    };
}cr_state_thr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  cr_st2_dn_update_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_fix_state:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_state_fix_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  cr_state_en:1;
    };
}cr_state_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  cr_phase_inverse_en:1;
        RBus_UInt32  cr_weight_shift:4;
        RBus_UInt32  cr_pgain:4;
        RBus_UInt32  cr_igain:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_state:3;
    };
}cr_state_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  cr_weight_shift_st4:4;
        RBus_UInt32  cr_weight_shift_st2:4;
        RBus_UInt32  cr_weight_shift_st0:4;
    };
}cr_state_weight_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  agc_max4_sel:1;
        RBus_UInt32  agc_en:1;
        RBus_UInt32  dgain_en:1;
        RBus_UInt32  agc_bpf_en:1;
        RBus_UInt32  agc_max4_en:1;
        RBus_UInt32  agc_lpf_en:1;
        RBus_UInt32  agc_if_en:1;
        RBus_UInt32  agc_rf_en:1;
        RBus_UInt32  agc_fine_tune_en:1;
    };
}agc_enable_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_max_count_limit_en:1;
        RBus_UInt32  agc_max_count_limit:12;
    };
}agc_max_limit_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_peak_slow_charge_value:3;
        RBus_UInt32  agc_max_slow_charge_value:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_slow_charge_max_en:1;
        RBus_UInt32  agc_slow_charge_peak_en:1;
        RBus_UInt32  agc_max_cntl_unlock:12;
    };
}agc_max_count_for_coarse_mode_agc_cntl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  agc_max_cntl_lock:12;
    };
}agc_max_count_forfine_lock_mode_agc_cntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_diff_level_inv:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_diff_targ:11;
    };
}agc_avg_target_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  agc_loop1_downsample_sel:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_pos_en:1;
    };
}agc_max_count_for_coarse_mode_agc_lock2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_data_targ:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_targ_val:11;
    };
}agc_targ_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  agc_if_sd_in_fix_value:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_out_inv_rf:1;
        RBus_UInt32  agc_if_sd_in_fix_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  fine_cr_ind:1;
        RBus_UInt32  agc_out_inv_if:1;
        RBus_UInt32  agc_if_manu_en:1;
        RBus_UInt32  agc_rf_manu_en:1;
        RBus_UInt32  agc_manu_en:1;
        RBus_UInt32  agc_hold:1;
        RBus_UInt32  agc_polar:1;
    };
}agc_cntl_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_manu_value:13;
    };
}agc_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_if_manu_value:13;
    };
}agc_if_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_rf_manu_value:13;
    };
}agc_rf_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_kpd_add_method_shift:5;
        RBus_UInt32  res2:7;
        RBus_UInt32  agc_kd:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_kp:5;
        RBus_UInt32  agc_ki:4;
    };
}ki_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_if_max:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_if_min:13;
    };
}if_agc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_rf_min:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_rf_max:13;
    };
}rf_agc_limit_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  agc_lock_debounce_num:5;
        RBus_UInt32  agc_lock_peak_thr:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_lock_cnt_len_off:2;
    };
}agc_lock_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  agc_lock_en_sel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_lock_exception:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_lock_err_sel:1;
        RBus_UInt32  agc_lock_th_out:8;
        RBus_UInt32  agc_lock_th:8;
    };
}agc_lock_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  agc_fpga_pga_test_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_fine_force:1;
        RBus_UInt32  agc_fine:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_lock:1;
    };
}agc_lock_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_gate_delay:8;
        RBus_UInt32  agc_hsync_start:8;
        RBus_UInt32  agc_hsync_end:8;
    };
}agc_hsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_vsync_start:16;
        RBus_UInt32  agc_vsync_end:16;
    };
}agc_vsync_start1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  agc_peak_force:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_peak_status:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_peak_en:1;
        RBus_UInt32  agc_peak_cnt:12;
    };
}agc_peak_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  agc_peak_value:11;
    };
}agc_peak_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_peak_max:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_max:11;
    };
}agc_max_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_peak_error:12;
        RBus_UInt32  agc_err:12;
    };
}agc_err0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  agc_acc3:14;
    };
}agc_acc3_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_if_mode:13;
    };
}agc_if_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_rf_mode:13;
    };
}agc_rf_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  agc_pga_src_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_pga_fix_en:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  agc_pga_fix:9;
    };
}agc_pga_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_rf_hasten_en:1;
        RBus_UInt32  agc_ki_rf_hasten:4;
        RBus_UInt32  agc_max_cntl_rf_hasten:12;
        RBus_UInt32  agc_rf_hasten_thr:12;
    };
}agc_rf_hasten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_sep_rf_if_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_if_kp:5;
        RBus_UInt32  agc_if_ki:4;
    };
}agc_sep_rf_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  agc_vtop:13;
    };
}vtop_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  agc_krf:14;
    };
}krf_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  pga_set_read:9;
    };
}read_pga_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reset_noise_cal:1;
        RBus_UInt32  noise_cal_sel:1;
        RBus_UInt32  noise_cal_mean:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  noise:14;
    };
}noise_cal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  agc_loop2_hold:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_loop2_clear:1;
        RBus_UInt32  res3:16;
    };
}agc_linebase_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_max2_cntl_unlock:12;
        RBus_UInt32  agc_max2_cntl_lock:12;
    };
}agc_max2_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_in_kp_shift:4;
        RBus_UInt32  agc_in_ki_shift:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_in_kp:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_in_ki:5;
    };
}agc_in_kp_ki_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_in_max:16;
        RBus_UInt32  agc_in_min:16;
    };
}agc_in_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  agc_max2_count_limit:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_max2_count_limit_en:1;
    };
}agc_max2_limit_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  loop2_err:12;
    };
}agc_looop2_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_inner1:16;
        RBus_UInt32  agc_inner2:16;
    };
}agc_inner_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loop2_err_kp:16;
        RBus_UInt32  loop2_err_ki:16;
    };
}loop2_kp_ki_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_lpf_out_dgained:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_max2_out:11;
    };
}read_loop2_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_adaptive_peak2_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  agc_peak2_force:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_peak2_status:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  agc_peak2_en:1;
        RBus_UInt32  agc_peak2_cnt:12;
    };
}agc_peak2_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  agc_peak2_max:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  agc_peak2_error:12;
    };
}agc_peak2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  agc_loop2_downsample_sel:12;
    };
}agc_loop2_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  agc_if_pad_control:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_rf_pad_control:1;
        RBus_UInt32  agc_sigma_delta_dnsel:4;
    };
}sigma_delta_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  rf_agc_interrupt_thd:13;
    };
}agc_interrupt_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  agc_2step_en:1;
    };
}agc_2step_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain_up_step:16;
        RBus_UInt32  agc_dgain_down_step:16;
    };
}agc_dgain_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain_low_thr:16;
        RBus_UInt32  agc_dgain_up_thr:16;
    };
}agc_dgain_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain_min_pga:8;
        RBus_UInt32  agc_step_num_pga:4;
        RBus_UInt32  agc_settle_time_pga:20;
    };
}agc_dgain_to_pga_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_max_if_gain_count:8;
        RBus_UInt32  res2:16;
    };
}agc_dgain_virtual_pga_hsync_gate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_lower_int:1;
        RBus_UInt32  input_power_over_int:1;
        RBus_UInt32  if_w2s_int:1;
        RBus_UInt32  if_s2w_int:1;
        RBus_UInt32  rf_w2s_int:1;
        RBus_UInt32  rf_s2w_int:1;
        RBus_UInt32  pga_w2s_int:1;
        RBus_UInt32  pga_s2w_int:1;
        RBus_UInt32  agc_unlock_int:1;
        RBus_UInt32  mod_state_int:1;
        RBus_UInt32  data_shaped_int:1;
        RBus_UInt32  cr_unlock_int:1;
        RBus_UInt32  input_fifo_int:1;
        RBus_UInt32  rf_agc_max_int:1;
        RBus_UInt32  agc_lock_int:1;
        RBus_UInt32  cr_lock_int:1;
        RBus_UInt32  mask_data_shaped_en:1;
        RBus_UInt32  mask_input_power_lower_en:1;
        RBus_UInt32  mask_input_power_over_en:1;
        RBus_UInt32  mask_if_w2s_en:1;
        RBus_UInt32  mask_if_s2w_en:1;
        RBus_UInt32  mask_rf_w2s_en:1;
        RBus_UInt32  mask_rf_s2w_en:1;
        RBus_UInt32  mask_pga_w2s_en:1;
        RBus_UInt32  mask_pga_s2w_en:1;
        RBus_UInt32  mask_agc_unlock_en:1;
        RBus_UInt32  mask_mod_state_en:1;
        RBus_UInt32  mask_cr_unlock_en:1;
        RBus_UInt32  mask_input_fifo_status_en:1;
        RBus_UInt32  mask_rf_agc_max_en:1;
        RBus_UInt32  mask_agc_lock_en:1;
        RBus_UInt32  mask_cr_lock_en:1;
    };
}interrupt_mask_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fine_tune2_down_sample_en:1;
        RBus_UInt32  fine_tune2_down_sample:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  fine_tune_down_sample_en:1;
        RBus_UInt32  fine_tune_down_sample:12;
    };
}agc_fine_tune_down_sample_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  if_min:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rf_full:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  if_lower:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  if_raise:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  if_gain_count:9;
    };
}agc_2step_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  agc_gain_avg_interval:12;
        RBus_UInt32  res2:7;
        RBus_UInt32  agc_gain_avg_sel:1;
        RBus_UInt32  res3:5;
        RBus_UInt32  agc_gain_avg_length:3;
    };
}agc_gain_avg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_gain_var:16;
        RBus_UInt32  agc_gain_mean:16;
    };
}agc_gain_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  agc_fine_adapt_interval:12;
        RBus_UInt32  agc_adapt_interval:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_adapt_targ_en:1;
    };
}agc_adapt_targ_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  agc_targ_inc_thr:11;
    };
}agc_adapt_targ_inc_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_min_diff_targ:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_min_targ:11;
    };
}agc_adapt_targ_min_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_fine_targ_thr:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_diff_coarse_step:11;
    };
}agc_adapt_targ_fine_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  adaptive_diff_targ_ro:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  adaptive_targ_val_ro:11;
    };
}agc_adapt_targ_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  impn_gate_end:12;
        RBus_UInt32  impn_det_thr:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  impn_det_input_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_impn_mask_en:1;
        RBus_UInt32  impn_det_en:1;
    };
}impulsive_gate_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  impn_detect:1;
        RBus_UInt32  impn_det_stop:8;
        RBus_UInt32  impn_gate_delay:12;
    };
}impulsive_gate_setII_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  agc_sync_level_avg_length:1;
        RBus_UInt32  agc_sync_level_var:12;
        RBus_UInt32  agc_sync_level_mean:12;
    };
}agc_sync_level_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  agc_max_avg_length:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_max_var:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  agc_max_mean:11;
    };
}agc_max_var_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  hum_detect:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_hum_debounce:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_hum_update_sel:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  agc_hum_en:1;
    };
}agc_hum_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_hum_max_thr_out:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_hum_max_thr_in:11;
    };
}agc_hum_max_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  agc_hum_sync_thr_out:12;
        RBus_UInt32  agc_hum_sync_thr_in:12;
    };
}agc_hum_sync_level_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  agc_pga_int_thr:8;
    };
}pga_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_rf_w2s_int_thr:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_rf_s2w_int_thr:13;
    };
}rf_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_if_w2s_int_thr:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_if_s2w_int_thr:13;
    };
}if_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  agc_auto_min_pga_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_slow_charge_lsadc_peak_value:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_slow_charge_lsadc_peak_en:1;
        RBus_UInt32  agc_lsadc_peak_cnt:12;
        RBus_UInt32  res4:2;
        RBus_UInt32  agc_peak_lsadc:6;
    };
}agc_peak_lsadc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_pga_min_update_step:4;
        RBus_UInt32  agc_pga_min_update_interval:12;
        RBus_UInt32  res1:2;
        RBus_UInt32  agc_pga_min_up_thr:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_pga_min_low_thr:6;
    };
}auto_pga_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ls_adc_out:6;
    };
}lsadc_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  pga_min_auto:8;
    };
}pga_min_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_scan_mode_offset:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_power_pc_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  input_power_cal_shift:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  input_power_acc_len:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  input_power_cal_len:3;
        RBus_UInt32  input_power_interrupt_mode:1;
        RBus_UInt32  input_power_cal_reset:1;
        RBus_UInt32  input_power_mod_sel:1;
        RBus_UInt32  input_power_mode:1;
    };
}input_power_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_pc:16;
        RBus_UInt32  input_power_nco_ac:16;
    };
}nco_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_02:16;
        RBus_UInt32  input_power_nco_01:16;
    };
}nco_sequential1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_04:16;
        RBus_UInt32  input_power_nco_03:16;
    };
}nco_sequential2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_06:16;
        RBus_UInt32  input_power_nco_05:16;
    };
}nco_sequential3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_08:16;
        RBus_UInt32  input_power_nco_07:16;
    };
}nco_sequential4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_range2:16;
        RBus_UInt32  input_power_range1:16;
    };
}nco_scan_range1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_range4:16;
        RBus_UInt32  input_power_range3:16;
    };
}nco_scan_range4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_ac:16;
        RBus_UInt32  input_power_pc:16;
    };
}input_power_output_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_00:16;
        RBus_UInt32  input_power_00:16;
    };
}input_power_output_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_01:16;
        RBus_UInt32  input_power_01:16;
    };
}input_power_output_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_02:16;
        RBus_UInt32  input_power_02:16;
    };
}input_power_output_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_03:16;
        RBus_UInt32  input_power_03:16;
    };
}input_power_output_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_04:16;
        RBus_UInt32  input_power_04:16;
    };
}input_power_output_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_offset_05:16;
        RBus_UInt32  input_power_05:16;
    };
}input_power_output_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_diff_thr:12;
        RBus_UInt32  res1:1;
        RBus_UInt32  input_power_diff:15;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_power_detect_done:1;
    };
}input_power_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  debug_clk27_polar:1;
        RBus_UInt32  debug_clk49_polar:1;
        RBus_UInt32  debug_clk54_polar:1;
        RBus_UInt32  debug_clk108_polar:1;
        RBus_UInt32  debug_adcclk_polar:1;
        RBus_UInt32  debug_mode_en:1;
        RBus_UInt32  debug_mode:7;
    };
}debug_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  debug_mode3_en:1;
        RBus_UInt32  debug_mode3:7;
        RBus_UInt32  res2:8;
    };
}debug_mode3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  test_mode_en:1;
        RBus_UInt32  test_mode:7;
    };
}test_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cr_self_test_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_self_test_en:1;
        RBus_UInt32  agc_self_test_sel:1;
        RBus_UInt32  res3:2;
    };
}cr_self_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  crc1_insel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  crc2_en:1;
        RBus_UInt32  crc2_insel:1;
        RBus_UInt32  res3:2;
    };
}CRC_Ctrl_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc2_result:32;
    };
}CRC2_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  dactest_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sinout_sel:1;
        RBus_UInt32  dac_dctest:12;
    };
}DACtest_register1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bypassad:1;
    };
}ad_bypass_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tuner_vsync_start:16;
        RBus_UInt32  tuner_vsync_end:16;
    };
}tuner_vsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test1:32;
    };
}fpga_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test2:32;
    };
}fpga_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test3:32;
    };
}fpga_test3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test4:27;
        RBus_UInt32  debug_clk5:1;
        RBus_UInt32  debug_clk4:1;
        RBus_UInt32  debug_clk3:1;
        RBus_UInt32  debug_clk2:1;
        RBus_UInt32  debug_clk1:1;
    };
}fpga_test4_debug_clk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record0:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record1:11;
    };
}agc_rf_record_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record2:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record3:11;
    };
}agc_rf_record_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record4:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record5:11;
    };
}agc_rf_record_4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record6:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record7:11;
    };
}agc_rf_record_6_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record8:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record9:11;
    };
}agc_rf_record_8_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record10:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record11:11;
    };
}agc_rf_record_10_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record12:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record13:11;
    };
}agc_rf_record_12_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record14:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record15:11;
    };
}agc_rf_record_14_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record16:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record17:11;
    };
}agc_rf_record_16_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record18:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record19:11;
    };
}agc_rf_record_18_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record20:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record21:11;
    };
}agc_rf_record_20_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record22:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record23:11;
    };
}agc_rf_record_22_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record24:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record25:11;
    };
}agc_rf_record_24_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record26:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record27:11;
    };
}agc_rf_record_26_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record28:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record29:11;
    };
}agc_rf_record_28_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record30:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record31:11;
    };
}agc_rf_record_30_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record32:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record33:11;
    };
}agc_rf_record_32_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record34:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record35:11;
    };
}agc_rf_record_34_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record36:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record37:11;
    };
}agc_rf_record_36_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record38:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record39:11;
    };
}agc_rf_record_38_39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record40:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record41:11;
    };
}agc_rf_record_40_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record42:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record43:11;
    };
}agc_rf_record_42_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record44:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record45:11;
    };
}agc_rf_record_44_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record46:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record47:11;
    };
}agc_rf_record_46_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record48:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record49:11;
    };
}agc_rf_record_48_49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record50:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record51:11;
    };
}agc_rf_record_50_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record52:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record53:11;
    };
}agc_rf_record_52_53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record54:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record55:11;
    };
}agc_rf_record_54_55_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record56:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record57:11;
    };
}agc_rf_record_56_57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record58:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record59:11;
    };
}agc_rf_record_58_59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record60:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record61:11;
    };
}agc_rf_record_60_61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record62:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record63:11;
    };
}agc_rf_record_62_63_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record64:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record65:11;
    };
}agc_rf_record_64_65_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record66:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record67:11;
    };
}agc_rf_record_66_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record68:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record69:11;
    };
}agc_rf_record_68_69_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record70:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record71:11;
    };
}agc_rf_record_70_71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record72:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record73:11;
    };
}agc_rf_record_72_73_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record74:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record75:11;
    };
}agc_rf_record_74_75_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record76:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record77:11;
    };
}agc_rf_record_76_77_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record78:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record79:11;
    };
}agc_rf_record_78_79_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record80:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record81:11;
    };
}agc_rf_record_80_81_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record82:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record83:11;
    };
}agc_rf_record_82_83_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record84:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record85:11;
    };
}agc_rf_record_84_85_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record86:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record87:11;
    };
}agc_rf_record_86_87_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record88:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record89:11;
    };
}agc_rf_record_88_89_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record90:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record91:11;
    };
}agc_rf_record_90_91_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record92:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record93:11;
    };
}agc_rf_record_92_93_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record94:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record95:11;
    };
}agc_rf_record_94_95_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record96:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record97:11;
    };
}agc_rf_record_96_97_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  agc_rf_record98:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record99:11;
    };
}agc_rf_record_98_99_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  agc_rf_record_len:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_rf_record_en:1;
    };
}agc_rf_record_enable_RBUS;





#else //apply LITTLE_ENDIAN


//======IFD register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bpf_coe:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_bpf_coe_tap:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_bpf_coe_modify_en:1;
        RBus_UInt32  cr_bpf_en:1;
        RBus_UInt32  cr_inner_lpf_en:1;
        RBus_UInt32  cr_inner_lpf_sel:1;
        RBus_UInt32  cr_delay:4;
    };
}cr_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bpf_coe_read:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_bpf_coe_read_tap:7;
        RBus_UInt32  res1:9;
    };
}cr_bpf_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_igain:4;
        RBus_UInt32  cr_pgain:4;
        RBus_UInt32  cr_st0_ki:4;
        RBus_UInt32  cr_st0_kp:4;
        RBus_UInt32  cr_st2_ki:4;
        RBus_UInt32  cr_st2_kp:4;
        RBus_UInt32  cr_st4_ki:4;
        RBus_UInt32  cr_st4_kp:4;
    };
}cr_pgain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_lock:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_lock_ref:8;
        RBus_UInt32  cr_lock_with_agc:1;
        RBus_UInt32  cr_lock_with_hsync:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cr_lock_with_freq:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cr_lock_freq_thr:12;
    };
}cr_lock_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_nco_fix_data:20;
        RBus_UInt32  cr_ncoerr_en:1;
        RBus_UInt32  res1:11;
    };
}cr_nco_fix_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_offset_sat:17;
        RBus_UInt32  res1:15;
    };
}cr_freq_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_status:20;
        RBus_UInt32  res1:12;
    };
}cr_freq_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_weight_shift:4;
        RBus_UInt32  cr_weight_max_decrease:4;
        RBus_UInt32  cr_weighting_en:1;
        RBus_UInt32  cr_weighting_cr_lock_dis:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  cr_weighting_thr_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_weighting_thr:12;
        RBus_UInt32  res1:4;
    };
}cr_weight_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sin_sample_d:15;
        RBus_UInt32  res1:17;
    };
}cr_sine_part_inner_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_inner_lpf_tap0:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_inner_lpf_tap1:15;
        RBus_UInt32  res1:1;
    };
}cr_inner_lpf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_inner_lpf_tap2:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_inner_lpf_tap3:15;
        RBus_UInt32  res1:1;
    };
}cr_inner_lpf_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}dummy2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy3:32;
    };
}dummy3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy4:32;
    };
}dummy4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy5:32;
    };
}dummy5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shaping_image_sel:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  shaping_bw_sel:4;
        RBus_UInt32  data_gain_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  data_gain_mask_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  data_gain:15;
        RBus_UInt32  res1:1;
    };
}shape_filter_selection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  soft_reset:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ifd_int_mask:1;
        RBus_UInt32  res1:27;
    };
}soft_reset_27_clk_phase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_empty:1;
        RBus_UInt32  dma_full:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dma_fifo_adc_empty:1;
        RBus_UInt32  dma_fifo_adc_full:1;
        RBus_UInt32  dma_fifo_debug_empty:1;
        RBus_UInt32  dma_fifo_debug_full:1;
        RBus_UInt32  res1:24;
    };
}dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_cnt_thd:8;
        RBus_UInt32  cr_lock_len:8;
        RBus_UInt32  cr_lock_thd:8;
        RBus_UInt32  res1:8;
    };
}cr_lock_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_auto_reset_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_nco_track_sel:1;
        RBus_UInt32  cr_reset_track_en:1;
        RBus_UInt32  cr_unlock_track_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_track_len:4;
        RBus_UInt32  cr_sin_trunc_len:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  cr_nco_offset:16;
    };
}cr_auto_reset_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_phase_inverse_en:1;
        RBus_UInt32  cr_phase_inverse_cr_lock_dis:1;
        RBus_UInt32  cr_phase_inverse_fine_lock_dis:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  cr_cordic_phase_modify_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_phase_inverse_thr:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_phase_inverse_en_st0:1;
        RBus_UInt32  cr_phase_inverse_en_st2:1;
        RBus_UInt32  cr_phase_inverse_en_st4:1;
        RBus_UInt32  res1:5;
    };
}cr_phase_inverse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_shift_nco_offset:20;
        RBus_UInt32  cr_shift_polar:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_shift_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_fm_en:1;
        RBus_UInt32  res1:3;
    };
}cr_shift_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_data_gain_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_less_delay:1;
        RBus_UInt32  res1:27;
    };
}cr_data_gain_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_phase_error_sel:2;
        RBus_UInt32  res1:30;
    };
}cr_phase_error_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bpf_mask_en:1;
        RBus_UInt32  res1:31;
    };
}cr_bpf_mask_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_bpf_mask_in_thr:16;
        RBus_UInt32  cr_bpf_mask_out_thr:16;
    };
}cr_bpf_mask_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_gain_mask_in_thr:16;
        RBus_UInt32  data_gain_mask_out_thr:16;
    };
}data_gain_mask_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:20;
        RBus_UInt32  decimation_en:1;
        RBus_UInt32  res1:11;
    };
}decimation_filter_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lpf_vsync_end:16;
        RBus_UInt32  lpf_vsync_start:16;
    };
}output_lpf_vsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_empty:1;
        RBus_UInt32  fifo_full:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  fifo_empty_clear:1;
        RBus_UInt32  fifo_full_clear:1;
        RBus_UInt32  res1:26;
    };
}resampler_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_phase_error_avg_linebase:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  cr_phase_error_avg_length:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_phase_error_avg_interval:12;
        RBus_UInt32  cr_phase_error_avg_vcatch:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_phase_error_avg_src:1;
        RBus_UInt32  res1:7;
    };
}cr_phase_error_avg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_phase_error_var:12;
        RBus_UInt32  cr_phase_error_mean:12;
        RBus_UInt32  res1:8;
    };
}cr_phase_error_avg_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_error_avg_linebase:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_freq_error_avg_length:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cr_freq_error_avg_interval:12;
        RBus_UInt32  cr_freq_error_avg_vcatch:1;
        RBus_UInt32  cr_freq_error_avg_vinterval:11;
    };
}cr_freq_error_avg_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_error_var:16;
        RBus_UInt32  cr_freq_error_mean:16;
    };
}cr_freq_error_avg_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_vsync_end:16;
        RBus_UInt32  cr_vsync_start:16;
    };
}cr_vsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_hsync_end:8;
        RBus_UInt32  cr_hsync_start:8;
        RBus_UInt32  res1:16;
    };
}cr_hsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  power_cal_shift:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  power_cal_len:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  power_cal_reset:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  power_nco_offset:20;
    };
}power_cal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_shaped_thr:16;
        RBus_UInt32  data_shaped:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  data_shaped_ready:1;
        RBus_UInt32  res1:11;
    };
}data_shaped_flag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  power_offset_neg:16;
        RBus_UInt32  power_offset_pos:16;
    };
}freq_offset_power_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  power_offset_diff_avg:16;
        RBus_UInt32  power_offset_diff:16;
    };
}diff_power_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_max_cntl:12;
        RBus_UInt32  mod_max_slow_charge_value:5;
        RBus_UInt32  mod_max_slow_charge_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mod_max_out:11;
        RBus_UInt32  res1:1;
    };
}mod_detect_max_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_min_cntl:12;
        RBus_UInt32  mod_min_slow_charge_value:5;
        RBus_UInt32  mod_min_slow_charge_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mod_min_out:11;
        RBus_UInt32  res1:1;
    };
}mod_detect_min_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_reset:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mod_update_cntl:13;
        RBus_UInt32  res1:15;
    };
}mod_detect_update_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pos_mod_thr:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  neg_mod_thr:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  mod_state_thr:3;
        RBus_UInt32  res1:5;
    };
}mod_detect_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_state:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  uncertain_mod_cnt:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  mod_pos_cnt:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  mod_neg_cnt:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  min_diff_min:11;
        RBus_UInt32  res1:5;
    };
}mod_detect_state_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_diff_value:12;
        RBus_UInt32  min_diff_max:11;
        RBus_UInt32  res1:9;
    };
}mod_detect_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mod_auto_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  mod_once_auto_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  mod_relate_cr_thr:4;
        RBus_UInt32  mod_relate_cr:1;
        RBus_UInt32  res1:19;
    };
}mod_detect_auto_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_st0_up_debounce:3;
        RBus_UInt32  res8:1;
        RBus_UInt32  cr_st1_up_debounce:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  cr_st1_dn_debounce:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  cr_st2_up_debounce:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  cr_st2_dn_debounce:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  cr_st3_up_debounce:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cr_st3_dn_debounce:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_st4_dn_debounce:3;
        RBus_UInt32  res1:1;
    };
}cr_state_debounce_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_var_st0_thr:16;
        RBus_UInt32  cr_phase_var_st0_thr:12;
        RBus_UInt32  res1:4;
    };
}cr_state_thr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_varvcheck_thr:16;
        RBus_UInt32  cr_phase_var_st2_thr:12;
        RBus_UInt32  res1:4;
    };
}cr_state_thr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_var_st2_low_thr:16;
        RBus_UInt32  cr_freq_var_st2_up_thr:16;
    };
}cr_state_thr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_freq_var_st3_thr:16;
        RBus_UInt32  cr_freq_var_st4_thr:16;
    };
}cr_state_thr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_state_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  cr_state_fix_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_fix_state:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_st2_dn_update_sel:1;
        RBus_UInt32  res1:19;
    };
}cr_state_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_state:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cr_igain:4;
        RBus_UInt32  cr_pgain:4;
        RBus_UInt32  cr_weight_shift:4;
        RBus_UInt32  cr_phase_inverse_en:1;
        RBus_UInt32  res1:15;
    };
}cr_state_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_weight_shift_st0:4;
        RBus_UInt32  cr_weight_shift_st2:4;
        RBus_UInt32  cr_weight_shift_st4:4;
        RBus_UInt32  res1:20;
    };
}cr_state_weight_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_fine_tune_en:1;
        RBus_UInt32  agc_rf_en:1;
        RBus_UInt32  agc_if_en:1;
        RBus_UInt32  agc_lpf_en:1;
        RBus_UInt32  agc_max4_en:1;
        RBus_UInt32  agc_bpf_en:1;
        RBus_UInt32  dgain_en:1;
        RBus_UInt32  agc_en:1;
        RBus_UInt32  agc_max4_sel:1;
        RBus_UInt32  res1:23;
    };
}agc_enable_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max_count_limit:12;
        RBus_UInt32  agc_max_count_limit_en:1;
        RBus_UInt32  res1:19;
    };
}agc_max_limit_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max_cntl_unlock:12;
        RBus_UInt32  agc_slow_charge_peak_en:1;
        RBus_UInt32  agc_slow_charge_max_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_max_slow_charge_value:4;
        RBus_UInt32  agc_peak_slow_charge_value:3;
        RBus_UInt32  res1:9;
    };
}agc_max_count_for_coarse_mode_agc_cntl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max_cntl_lock:12;
        RBus_UInt32  res1:20;
    };
}agc_max_count_for_finelock_mode_agc_cntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_diff_targ:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_diff_level_inv:1;
        RBus_UInt32  res1:19;
    };
}agc_avg_target_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_pos_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_loop1_downsample_sel:12;
        RBus_UInt32  res1:16;
    };
}agc_max_count_for_coarse_mode_agc_lock2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_targ_val:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_data_targ:11;
        RBus_UInt32  res1:9;
    };
}agc_targ_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_polar:1;
        RBus_UInt32  agc_hold:1;
        RBus_UInt32  agc_manu_en:1;
        RBus_UInt32  agc_rf_manu_en:1;
        RBus_UInt32  agc_if_manu_en:1;
        RBus_UInt32  agc_out_inv_if:1;
        RBus_UInt32  fine_cr_ind:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  agc_if_sd_in_fix_en:1;
        RBus_UInt32  agc_out_inv_rf:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_if_sd_in_fix_value:13;
        RBus_UInt32  res1:7;
    };
}agc_cntl_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_manu_value:13;
        RBus_UInt32  res1:19;
    };
}agc_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_if_manu_value:13;
        RBus_UInt32  res1:19;
    };
}agc_if_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_manu_value:13;
        RBus_UInt32  res1:19;
    };
}agc_rf_manu_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_ki:4;
        RBus_UInt32  agc_kp:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_kd:5;
        RBus_UInt32  res2:7;
        RBus_UInt32  agc_kpd_add_method_shift:5;
        RBus_UInt32  res1:3;
    };
}ki_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_if_min:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_if_max:13;
        RBus_UInt32  res1:3;
    };
}if_agc_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_max:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_rf_min:13;
        RBus_UInt32  res1:3;
    };
}rf_agc_limit_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_lock_cnt_len_off:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_lock_peak_thr:12;
        RBus_UInt32  agc_lock_debounce_num:5;
        RBus_UInt32  res1:11;
    };
}agc_lock_len_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_lock_th:8;
        RBus_UInt32  agc_lock_th_out:8;
        RBus_UInt32  agc_lock_err_sel:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_lock_exception:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_lock_en_sel:2;
        RBus_UInt32  res1:6;
    };
}agc_lock_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_lock:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_fine:1;
        RBus_UInt32  agc_fine_force:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_fpga_pga_test_en:1;
        RBus_UInt32  res1:23;
    };
}agc_lock_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_hsync_end:8;
        RBus_UInt32  agc_hsync_start:8;
        RBus_UInt32  agc_gate_delay:8;
        RBus_UInt32  res1:8;
    };
}agc_hsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_vsync_end:16;
        RBus_UInt32  agc_vsync_start:16;
    };
}agc_vsync_start1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak_cnt:12;
        RBus_UInt32  agc_peak_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_peak_status:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_peak_force:1;
        RBus_UInt32  res1:11;
    };
}agc_peak_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak_value:11;
        RBus_UInt32  res1:21;
    };
}agc_peak_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_peak_max:12;
        RBus_UInt32  res1:8;
    };
}agc_max_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_err:12;
        RBus_UInt32  agc_peak_error:12;
        RBus_UInt32  res1:8;
    };
}agc_err0_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_acc3:14;
        RBus_UInt32  res1:18;
    };
}agc_acc3_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_if_mode:13;
        RBus_UInt32  res1:19;
    };
}agc_if_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_mode:13;
        RBus_UInt32  res1:19;
    };
}agc_rf_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_pga_fix:9;
        RBus_UInt32  res3:7;
        RBus_UInt32  agc_pga_fix_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_pga_src_sel:1;
        RBus_UInt32  res1:11;
    };
}agc_pga_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_hasten_thr:12;
        RBus_UInt32  agc_max_cntl_rf_hasten:12;
        RBus_UInt32  agc_ki_rf_hasten:4;
        RBus_UInt32  agc_rf_hasten_en:1;
        RBus_UInt32  res1:3;
    };
}agc_rf_hasten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_if_ki:4;
        RBus_UInt32  agc_if_kp:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_sep_rf_if_en:1;
        RBus_UInt32  res1:19;
    };
}agc_sep_rf_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_vtop:13;
        RBus_UInt32  res1:19;
    };
}vtop_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_krf:14;
        RBus_UInt32  res1:18;
    };
}krf_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pga_set_read:9;
        RBus_UInt32  res1:23;
    };
}read_pga_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noise:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  noise_cal_mean:14;
        RBus_UInt32  noise_cal_sel:1;
        RBus_UInt32  reset_noise_cal:1;
    };
}noise_cal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res3:16;
        RBus_UInt32  agc_loop2_clear:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_loop2_hold:1;
        RBus_UInt32  res1:11;
    };
}agc_linebase_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max2_cntl_lock:12;
        RBus_UInt32  agc_max2_cntl_unlock:12;
        RBus_UInt32  res1:8;
    };
}agc_max2_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_in_ki:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_in_kp:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_in_ki_shift:4;
        RBus_UInt32  agc_in_kp_shift:4;
        RBus_UInt32  res1:8;
    };
}agc_in_kp_ki_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_in_min:16;
        RBus_UInt32  agc_in_max:16;
    };
}agc_in_max_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max2_count_limit_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_max2_count_limit:12;
        RBus_UInt32  res1:16;
    };
}agc_max2_limit_cnt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loop2_err:12;
        RBus_UInt32  res1:20;
    };
}agc_looop2_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_inner2:16;
        RBus_UInt32  agc_inner1:16;
    };
}agc_inner_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loop2_err_ki:16;
        RBus_UInt32  loop2_err_kp:16;
    };
}loop2_kp_ki_err_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max2_out:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_lpf_out_dgained:11;
        RBus_UInt32  res1:9;
    };
}read_loop2_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak2_cnt:12;
        RBus_UInt32  agc_peak2_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  agc_peak2_status:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_peak2_force:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  agc_adaptive_peak2_en:1;
        RBus_UInt32  res1:3;
    };
}agc_peak2_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak2_error:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  agc_peak2_max:12;
        RBus_UInt32  res1:4;
    };
}agc_peak2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_loop2_downsample_sel:12;
        RBus_UInt32  res1:20;
    };
}agc_loop2_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_sigma_delta_dnsel:4;
        RBus_UInt32  agc_rf_pad_control:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_if_pad_control:1;
        RBus_UInt32  res1:23;
    };
}sigma_delta_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rf_agc_interrupt_thd:13;
        RBus_UInt32  res1:19;
    };
}agc_interrupt_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_2step_en:1;
        RBus_UInt32  res1:31;
    };
}agc_2step_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain_down_step:16;
        RBus_UInt32  agc_dgain_up_step:16;
    };
}agc_dgain_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_dgain_up_thr:16;
        RBus_UInt32  agc_dgain_low_thr:16;
    };
}agc_dgain_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_settle_time_pga:20;
        RBus_UInt32  agc_step_num_pga:4;
        RBus_UInt32  agc_dgain_min_pga:8;
    };
}agc_dgain_to_pga_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:16;
        RBus_UInt32  agc_max_if_gain_count:8;
        RBus_UInt32  res1:8;
    };
}agc_dgain_virtual_pga_hsync_gate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_cr_lock_en:1;
        RBus_UInt32  mask_agc_lock_en:1;
        RBus_UInt32  mask_rf_agc_max_en:1;
        RBus_UInt32  mask_input_fifo_status_en:1;
        RBus_UInt32  mask_cr_unlock_en:1;
        RBus_UInt32  mask_mod_state_en:1;
        RBus_UInt32  mask_agc_unlock_en:1;
        RBus_UInt32  mask_pga_s2w_en:1;
        RBus_UInt32  mask_pga_w2s_en:1;
        RBus_UInt32  mask_rf_s2w_en:1;
        RBus_UInt32  mask_rf_w2s_en:1;
        RBus_UInt32  mask_if_s2w_en:1;
        RBus_UInt32  mask_if_w2s_en:1;
        RBus_UInt32  mask_input_power_over_en:1;
        RBus_UInt32  mask_input_power_lower_en:1;
        RBus_UInt32  mask_data_shaped_en:1;
        RBus_UInt32  cr_lock_int:1;
        RBus_UInt32  agc_lock_int:1;
        RBus_UInt32  rf_agc_max_int:1;
        RBus_UInt32  input_fifo_int:1;
        RBus_UInt32  cr_unlock_int:1;
        RBus_UInt32  data_shaped_int:1;
        RBus_UInt32  mod_state_int:1;
        RBus_UInt32  agc_unlock_int:1;
        RBus_UInt32  pga_s2w_int:1;
        RBus_UInt32  pga_w2s_int:1;
        RBus_UInt32  rf_s2w_int:1;
        RBus_UInt32  rf_w2s_int:1;
        RBus_UInt32  if_s2w_int:1;
        RBus_UInt32  if_w2s_int:1;
        RBus_UInt32  input_power_over_int:1;
        RBus_UInt32  input_power_lower_int:1;
    };
}interrupt_mask_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fine_tune_down_sample:12;
        RBus_UInt32  fine_tune_down_sample_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  fine_tune2_down_sample:12;
        RBus_UInt32  fine_tune2_down_sample_en:1;
        RBus_UInt32  res1:3;
    };
}agc_fine_tune_down_sample_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  if_gain_count:9;
        RBus_UInt32  res5:3;
        RBus_UInt32  if_raise:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  if_lower:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  rf_full:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  if_min:1;
        RBus_UInt32  res1:7;
    };
}agc_2step_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_gain_avg_length:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  agc_gain_avg_sel:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  agc_gain_avg_interval:12;
        RBus_UInt32  res1:4;
    };
}agc_gain_avg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_gain_mean:16;
        RBus_UInt32  agc_gain_var:16;
    };
}agc_gain_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_adapt_targ_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_adapt_interval:12;
        RBus_UInt32  agc_fine_adapt_interval:12;
        RBus_UInt32  res1:4;
    };
}agc_adapt_targ_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_targ_inc_thr:11;
        RBus_UInt32  res1:21;
    };
}agc_adapt_targ_inc_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_min_targ:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_min_diff_targ:11;
        RBus_UInt32  res1:9;
    };
}agc_adapt_targ_min_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_diff_coarse_step:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_fine_targ_thr:11;
        RBus_UInt32  res1:9;
    };
}agc_adapt_targ_fine_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adaptive_targ_val_ro:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  adaptive_diff_targ_ro:11;
        RBus_UInt32  res1:9;
    };
}agc_adapt_targ_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  impn_det_en:1;
        RBus_UInt32  agc_impn_mask_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  impn_det_input_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  impn_det_thr:12;
        RBus_UInt32  impn_gate_end:12;
    };
}impulsive_gate_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  impn_gate_delay:12;
        RBus_UInt32  impn_det_stop:8;
        RBus_UInt32  impn_detect:1;
        RBus_UInt32  res1:11;
    };
}impulsive_gate_setII_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_sync_level_mean:12;
        RBus_UInt32  agc_sync_level_var:12;
        RBus_UInt32  agc_sync_level_avg_length:1;
        RBus_UInt32  res1:7;
    };
}agc_sync_level_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_max_mean:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  agc_max_var:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_max_avg_length:1;
        RBus_UInt32  res1:7;
    };
}agc_max_var_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_hum_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  agc_hum_update_sel:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_hum_debounce:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  hum_detect:1;
        RBus_UInt32  res1:19;
    };
}agc_hum_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_hum_max_thr_in:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_hum_max_thr_out:11;
        RBus_UInt32  res1:9;
    };
}agc_hum_max_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_hum_sync_thr_in:12;
        RBus_UInt32  agc_hum_sync_thr_out:12;
        RBus_UInt32  res1:8;
    };
}agc_hum_sync_level_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_pga_int_thr:8;
        RBus_UInt32  res1:24;
    };
}pga_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_s2w_int_thr:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_rf_w2s_int_thr:13;
        RBus_UInt32  res1:3;
    };
}rf_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_if_s2w_int_thr:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_if_w2s_int_thr:13;
        RBus_UInt32  res1:3;
    };
}if_int_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_peak_lsadc:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  agc_lsadc_peak_cnt:12;
        RBus_UInt32  agc_slow_charge_lsadc_peak_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  agc_slow_charge_lsadc_peak_value:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_auto_min_pga_en:1;
        RBus_UInt32  res1:3;
    };
}agc_peak_lsadc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_pga_min_low_thr:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc_pga_min_up_thr:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  agc_pga_min_update_interval:12;
        RBus_UInt32  agc_pga_min_update_step:4;
    };
}auto_pga_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_adc_out:6;
        RBus_UInt32  res1:26;
    };
}lsadc_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pga_min_auto:8;
        RBus_UInt32  res1:24;
    };
}pga_min_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_mode:1;
        RBus_UInt32  input_power_mod_sel:1;
        RBus_UInt32  input_power_cal_reset:1;
        RBus_UInt32  input_power_interrupt_mode:1;
        RBus_UInt32  input_power_cal_len:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  input_power_acc_len:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  input_power_cal_shift:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  input_power_pc_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_power_scan_mode_offset:12;
    };
}input_power_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_ac:16;
        RBus_UInt32  input_power_nco_pc:16;
    };
}nco_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_01:16;
        RBus_UInt32  input_power_nco_02:16;
    };
}nco_sequential1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_03:16;
        RBus_UInt32  input_power_nco_04:16;
    };
}nco_sequential2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_05:16;
        RBus_UInt32  input_power_nco_06:16;
    };
}nco_sequential3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_nco_07:16;
        RBus_UInt32  input_power_nco_08:16;
    };
}nco_sequential4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_range1:16;
        RBus_UInt32  input_power_range2:16;
    };
}nco_scan_range1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_range3:16;
        RBus_UInt32  input_power_range4:16;
    };
}nco_scan_range4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_pc:16;
        RBus_UInt32  input_power_ac:16;
    };
}input_power_output_if_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_00:16;
        RBus_UInt32  input_power_offset_00:16;
    };
}input_power_output_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_01:16;
        RBus_UInt32  input_power_offset_01:16;
    };
}input_power_output_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_02:16;
        RBus_UInt32  input_power_offset_02:16;
    };
}input_power_output_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_03:16;
        RBus_UInt32  input_power_offset_03:16;
    };
}input_power_output_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_04:16;
        RBus_UInt32  input_power_offset_04:16;
    };
}input_power_output_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_05:16;
        RBus_UInt32  input_power_offset_05:16;
    };
}input_power_output_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_power_detect_done:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_power_diff:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  input_power_diff_thr:12;
    };
}input_power_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode:7;
        RBus_UInt32  debug_mode_en:1;
        RBus_UInt32  debug_adcclk_polar:1;
        RBus_UInt32  debug_clk108_polar:1;
        RBus_UInt32  debug_clk54_polar:1;
        RBus_UInt32  debug_clk49_polar:1;
        RBus_UInt32  debug_clk27_polar:1;
        RBus_UInt32  res1:19;
    };
}debug_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:8;
        RBus_UInt32  debug_mode3:7;
        RBus_UInt32  debug_mode3_en:1;
        RBus_UInt32  res1:16;
    };
}debug_mode3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_mode:7;
        RBus_UInt32  test_mode_en:1;
        RBus_UInt32  res1:24;
    };
}test_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res3:2;
        RBus_UInt32  agc_self_test_sel:1;
        RBus_UInt32  agc_self_test_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  cr_self_test_en:1;
        RBus_UInt32  res1:24;
    };
}cr_self_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res3:2;
        RBus_UInt32  crc2_insel:1;
        RBus_UInt32  crc2_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  crc1_insel:1;
        RBus_UInt32  res1:25;
    };
}CRC_Ctrl_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc2_result:32;
    };
}CRC2_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dac_dctest:12;
        RBus_UInt32  sinout_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dactest_sel:1;
        RBus_UInt32  res1:15;
    };
}DACtest_register1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bypassad:1;
        RBus_UInt32  res1:31;
    };
}ad_bypass_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tuner_vsync_end:16;
        RBus_UInt32  tuner_vsync_start:16;
    };
}tuner_vsync_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test1:32;
    };
}fpga_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test2:32;
    };
}fpga_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fpga_test3:32;
    };
}fpga_test3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_clk1:1;
        RBus_UInt32  debug_clk2:1;
        RBus_UInt32  debug_clk3:1;
        RBus_UInt32  debug_clk4:1;
        RBus_UInt32  debug_clk5:1;
        RBus_UInt32  fpga_test4:27;
    };
}fpga_test4_debug_clk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record1:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record0:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record3:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record2:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record5:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record4:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record7:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record6:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_6_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record9:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record8:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_8_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record11:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record10:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_10_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record13:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record12:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_12_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record15:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record14:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_14_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record17:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record16:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_16_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record19:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record18:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_18_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record21:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record20:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_20_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record23:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record22:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_22_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record25:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record24:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_24_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record27:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record26:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_26_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record29:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record28:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_28_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record31:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record30:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_30_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record33:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record32:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_32_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record35:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record34:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_34_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record37:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record36:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_36_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record39:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record38:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_38_39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record41:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record40:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_40_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record43:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record42:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_42_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record45:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record44:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_44_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record47:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record46:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_46_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record49:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record48:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_48_49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record51:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record50:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_50_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record53:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record52:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_52_53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record55:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record54:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_54_55_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record57:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record56:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_56_57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record59:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record58:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_58_59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record61:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record60:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_60_61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record63:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record62:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_62_63_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record65:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record64:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_64_65_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record67:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record66:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_66_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record69:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record68:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_68_69_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record71:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record70:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_70_71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record73:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record72:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_72_73_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record75:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record74:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_74_75_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record77:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record76:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_76_77_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record79:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record78:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_78_79_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record81:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record80:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_80_81_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record83:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record82:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_82_83_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record85:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record84:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_84_85_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record87:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record86:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_86_87_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record89:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record88:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_88_89_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record91:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record90:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_90_91_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record93:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record92:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_92_93_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record95:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record94:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_94_95_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record97:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record96:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_96_97_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record99:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc_rf_record98:11;
        RBus_UInt32  res1:9;
    };
}agc_rf_record_98_99_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc_rf_record_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  agc_rf_record_len:8;
        RBus_UInt32  res1:20;
    };
}agc_rf_record_enable_RBUS;


#endif







#endif //_RBUS_IFD_REG_H_

