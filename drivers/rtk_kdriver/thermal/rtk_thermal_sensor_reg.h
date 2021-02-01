#ifndef __RKT_THERMAL_REG_H__
#define __RKT_THERMAL_REG_H__
#include <rbus/pll_reg_reg.h>
#include <mach/rtk_log.h>

#define THERMAL_SENSOR_1                PLL_REG_TEMP_SENSOR_1_reg
#define THERMAL_SENSOR_2                PLL_REG_TEMP_SENSOR_2_reg
#define THERMAL_SENSOR_3                PLL_REG_TEMP_SENSOR_3_reg
#define THERMAL_SENSOR_4                PLL_REG_TEMP_SENSOR_4_reg
#define THERMAL_SENSOR_5                PLL_REG_TEMP_SENSOR_5_reg
#define THERMAL_SENSOR_6                PLL_REG_TEMP_SENSOR_6_reg
#define THERMAL_SENSOR_7                PLL_REG_TEMP_SENSOR_7_reg
#define THERMAL_SENSOR_8                PLL_REG_TEMP_SENSOR_8_reg
#define THERMAL_RESULT_1                 PLL_REG_THERMAL_RESULT_1_reg
#define THERMAL_RESULT_2                 PLL_REG_THERMAL_RESULT_2_reg
#define THERMAL_IRQ_Threshold_1      PLL_REG_THERMAL_IRQ_Threshold_1_reg
#define THERMAL_IRQ_Threshold_2      PLL_REG_THERMAL_IRQ_Threshold_2_reg

#define SET_THERMAL_SENSOR_1(x)                 rtd_outl(THERMAL_SENSOR_1, x)
#define SET_THERMAL_SENSOR_2(x)                 rtd_outl(THERMAL_SENSOR_2, x)
#define SET_THERMAL_SENSOR_3(x)                 rtd_outl(THERMAL_SENSOR_3, x)
#define SET_THERMAL_SENSOR_4(x)                 rtd_outl(THERMAL_SENSOR_4, x)
#define SET_THERMAL_SENSOR_5(x)                 rtd_outl(THERMAL_SENSOR_5, x)
#define SET_THERMAL_SENSOR_6(x)                 rtd_outl(THERMAL_SENSOR_6, x)
#define SET_THERMAL_SENSOR_7(x)                 rtd_outl(THERMAL_SENSOR_7, x)
#define SET_THERMAL_SENSOR_8(x)                 rtd_outl(THERMAL_SENSOR_8, x)
#define SET_THERMAL_RESULT_1(x)                  rtd_outl(THERMAL_RESULT_1, x)
#define SET_THERMAL_RESULT_2(x)                  rtd_outl(THERMAL_RESULT_2, x)
#define SET_THERMAL_IRQ_Threshold_1(x)       rtd_outl(THERMAL_IRQ_Threshold_1, x)
#define SET_THERMAL_IRQ_Threshold_2(x)       rtd_outl(THERMAL_IRQ_Threshold_2, x)

#define GET_THERMAL_SENSOR_1()                  rtd_inl(THERMAL_SENSOR_1)
#define GET_THERMAL_SENSOR_2()                  rtd_inl(THERMAL_SENSOR_2)
#define GET_THERMAL_SENSOR_3()                  rtd_inl(THERMAL_SENSOR_3)
#define GET_THERMAL_SENSOR_4()                  rtd_inl(THERMAL_SENSOR_4)
#define GET_THERMAL_SENSOR_5()                  rtd_inl(THERMAL_SENSOR_5)
#define GET_THERMAL_SENSOR_6()                  rtd_inl(THERMAL_SENSOR_6)
#define GET_THERMAL_SENSOR_7()                  rtd_inl(THERMAL_SENSOR_7)
#define GET_THERMAL_SENSOR_8()                  rtd_inl(THERMAL_SENSOR_8)
#define GET_THERMAL_RESULT_1()                   rtd_inl(THERMAL_RESULT_1)
#define GET_THERMAL_RESULT_2()                   rtd_inl(THERMAL_RESULT_2)
#define GET_THERMAL_IRQ_Threshold_1()        rtd_inl(THERMAL_IRQ_Threshold_1)
#define GET_THERMAL_IRQ_Threshold_2()        rtd_inl(THERMAL_IRQ_Threshold_2)


#define THERMAL_TM_A_SHIFT                          PLL_REG_TEMP_SENSOR_1_tm_a_shift
#define THERMAL_TM_A_MASK                           PLL_REG_TEMP_SENSOR_1_tm_a_mask

#define THERMAL_TM_B_SHIFT                          PLL_REG_TEMP_SENSOR_2_tm_b_shift
#define THERMAL_TM_B_MASK                           PLL_REG_TEMP_SENSOR_2_tm_b_mask
#define THERMAL_TM_ADCCKSEL_SHIFT             PLL_REG_TEMP_SENSOR_2_tm_adccksel_shift
#define THERMAL_TM_ADCCKSEL_MASK              PLL_REG_TEMP_SENSOR_2_tm_adccksel_mask
#define THERMAL_TM_CHOPEN_SHIFT                PLL_REG_TEMP_SENSOR_2_tm_chopen_shift
#define THERMAL_TM_CHOPEN_MASK                 PLL_REG_TEMP_SENSOR_2_tm_chopen_mask
#define THERMAL_TM_OSR_SHIFT                      PLL_REG_TEMP_SENSOR_2_tm_osr_shift
#define THERMAL_TM_OSR_MASK                       PLL_REG_TEMP_SENSOR_2_tm_osr_mask

#define THERMAL_TM_HOLD_EN_SHIFT               PLL_REG_TEMP_SENSOR_3_tm_hold_en_shift
#define THERMAL_TM_HOLD_EN_MASK               PLL_REG_TEMP_SENSOR_3_tm_hold_en_mask
#define THERMAL_TM_POW_SHIFT                     PLL_REG_TEMP_SENSOR_3_tm_pow_shift
#define THERMAL_TM_POW_MASK                      PLL_REG_TEMP_SENSOR_3_tm_pow_mask

#define THERMAL_TM_HOLD_DLY_SHIFT             PLL_REG_TEMP_SENSOR_4_tm_hold_dly_shift
#define THERMAL_TM_HOLD_DLY_MASK              PLL_REG_TEMP_SENSOR_4_tm_hold_dly_mask

#define THERMAL_TM_RSTB_SHIFT                     PLL_REG_TEMP_SENSOR_5_tm_rstb_shift
#define THERMAL_TM_RSTB_MASK                      PLL_REG_TEMP_SENSOR_5_tm_rstb_mask
#define THERMAL_TM_CHOPFREQSEL_SHIFT       PLL_REG_TEMP_SENSOR_5_tm_chopfreqsel_shift
#define THERMAL_TM_CHOPFREQSEL_MASK        PLL_REG_TEMP_SENSOR_5_tm_chopfreqsel_mask

#define THERMAL_TM_BIASDEM_EN_SHIFT          PLL_REG_TEMP_SENSOR_7_tm_biasdem_en_shift
#define THERMAL_TM_BIASDEM_EN_MASK           PLL_REG_TEMP_SENSOR_7_tm_biasdem_en_mask
#define THERMAL_TD_WREQ_EDGE_SEL_SHIFT    PLL_REG_TEMP_SENSOR_7_td_wrep_edge_sel_shift
#define THERMAL_TD_WREQ_EDGE_SEL_MASK     PLL_REG_TEMP_SENSOR_7_td_wrep_edge_sel_mask

#define THERMAL_CT_OUT_O_TM_SHIFT              PLL_REG_THERMAL_RESULT_1_ct_out_o_tm_shift
#define THERMAL_CT_OUT_O_TM_MASK               PLL_REG_THERMAL_RESULT_1_ct_out_o_tm_mask

#define THERMAL_U_OUT_TM_SHIFT                    PLL_REG_THERMAL_RESULT_2_u_out_tm_shift
#define THERMAL_U_OUT_TM_MASK                     PLL_REG_THERMAL_RESULT_2_u_out_tm_mask

#define THERMAL_SENSOR_SCPU_IE_SHIFT           PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_ie_shift
#define THERMAL_SENSOR_SCPU_IE_MASK            PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_ie_mask
#define THERMAL_SENSOR_IRQ_SCPU_STATUS_SHIFT   PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_irq_status_shift
#define THERMAL_SENSOR_IRQ_SCPU_STATUS_MASK    PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_irq_status_mask
#define THERMAL_SENSOR_KCPU_IE_SHIFT             PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_kcpu_ie_shift
#define THERMAL_SENSOR_KCPU_IE_MASK              PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_kcpu_ie_mask
#define THERMAL_SENSOR_THH_SHIFT                    PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_thh_shift
#define THERMAL_SENSOR_THH_MASK                     PLL_REG_THERMAL_IRQ_Threshold_1_thermal_sensor_thh_mask


#define THERMAL_SENSOR_THL_SHIFT                    PLL_REG_THERMAL_IRQ_Threshold_2_thermal_sensor_thl_shift
#define THERMAL_SENSOR_THL_MASK                     PLL_REG_THERMAL_IRQ_Threshold_2_thermal_sensor_thl_mask


#define THERMAL_TM_A(x)                       (((x) << THERMAL_TM_A_SHIFT) & THERMAL_TM_A_MASK)

#define THERMAL_TM_B(x)                       (((x) << THERMAL_TM_B_SHIFT) & THERMAL_TM_B_MASK)
#define THERMAL_TM_ADCCKSEL(x)          (((x) << THERMAL_TM_ADCCKSEL_SHIFT) & THERMAL_TM_ADCCKSEL_MASK)
#define THERMAL_TM_CHOPEN(x)             (((x) << THERMAL_TM_CHOPEN_SHIFT) & THERMAL_TM_CHOPEN_MASK)
#define THERMAL_TM_OSR(x)                   (((x) << THERMAL_TM_OSR_SHIFT) & THERMAL_TM_OSR_MASK)

#define THERMAL_TM_HOLD_EN(x)            (((x) << THERMAL_TM_HOLD_EN_SHIFT) & THERMAL_TM_HOLD_EN_MASK)
#define THERMAL_TM_POW(x)                  (((x) << THERMAL_TM_POW_SHIFT) & THERMAL_TM_POW_MASK)
#define THERMAL_TM_POW_ON                THERMAL_TM_POW(1)
#define THERMAL_TM_POW_DOWN           THERMAL_TM_POW(0)

#define THERMAL_TM_HOLD_DLY(x)         (((x) << THERMAL_TM_HOLD_DLY_SHIFT) & THERMAL_TM_HOLD_DLY_MASK)

#define THERMAL_TM_RSTB(x)                 (((x) << THERMAL_TM_RSTB_SHIFT) & THERMAL_TM_RSTB_MASK)
#define THERMAL_TM_CHOPFREQSEL(x)   (((x) << THERMAL_TM_CHOPFREQSEL_SHIFT) & THERMAL_TM_CHOPFREQSEL_MASK)

#define THERMAL_TM_BIASDEM_EN(x)         (((x) << THERMAL_TM_BIASDEM_EN_SHIFT) & THERMAL_TM_BIASDEM_EN_MASK)
#define THERMAL_TD_WREQ_EDGE_SEL(x)  (((x) << THERMAL_TD_WREQ_EDGE_SEL_SHIFT) & THERMAL_TD_WREQ_EDGE_SEL_MASK)

#define  GET_THERMAL_CT_OUT_O_TM()     (((GET_THERMAL_RESULT_1()) & THERMAL_CT_OUT_O_TM_MASK) >>  THERMAL_CT_OUT_O_TM_SHIFT)

#define  GET_THERMAL_U_OUT_TM()           (((GET_THERMAL_RESULT_2()) & THERMAL_U_OUT_TM_MASK) >> THERMAL_U_OUT_TM_SHIFT)

#define GET_THERMAL_SENSOR_IRQ_SCPU_STATUS()       (((GET_THERMAL_IRQ_Threshold_1()) & THERMAL_SENSOR_IRQ_SCPU_STATUS_MASK) >> THERMAL_SENSOR_IRQ_SCPU_STATUS_SHIFT)
#define CLEAR_THERMAL_SENSOR_IRQ_SCPU_STATUS()    SET_THERMAL_IRQ_Threshold_1(GET_THERMAL_IRQ_Threshold_1() & (~THERMAL_SENSOR_IRQ_SCPU_STATUS_MASK))
#define THERMAL_SENSOR_THH(x)                                    (((x) << THERMAL_SENSOR_THH_SHIFT) & THERMAL_SENSOR_THH_MASK)
#define SET_THERMAL_SENSOR_THH(x)                             SET_THERMAL_IRQ_Threshold_1((GET_THERMAL_IRQ_Threshold_1() & (~THERMAL_SENSOR_THH_MASK)) | THERMAL_SENSOR_THH((x)))

#define THERMAL_SENSOR_THL(x)                  (((x) << THERMAL_SENSOR_THL_SHIFT) & THERMAL_SENSOR_THL_MASK)
#define SET_THERMAL_SENSOR_THL(x)          SET_THERMAL_IRQ_Threshold_2((GET_THERMAL_IRQ_Threshold_2() & (~THERMAL_SENSOR_THL_MASK)) | THERMAL_SENSOR_THL((x)))


#endif
