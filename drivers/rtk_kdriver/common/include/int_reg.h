// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:777                    Version flow no.:1.1.14
#ifndef _INT_REG_H_INCLUDED_
#define _INT_REG_H_INCLUDED_

//#define  _INT_USE_STRUCT
#ifdef _INT_USE_STRUCT

typedef struct
{
    unsigned int    m_dcu_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    reserved_1:4;
    unsigned int    reserved_2:4;
    unsigned int    reserved_3:4;
    unsigned int    m_tvsb_irs:4;
    unsigned int    reserved_4:4;
    unsigned int    m_rb_irs:4;
}SIC_m_gir0;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    reserved_1:4;
    unsigned int    m_adma_irs:4;
    unsigned int    reserved_2:4;
    unsigned int    reserved_3:4;
    unsigned int    m_md_irs:4;
    unsigned int    reserved_4:4;
    unsigned int    m_cpu_irs:4;
}SIC_m_gir1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    m_if_demod_irs:4;
    unsigned int    m_vd_irs:4;
    unsigned int    m_vbi_irs:4;
    unsigned int    m_aud_irs:4;
    unsigned int    m_hdmi_irs:4;
    unsigned int    m_cec_irs:4;
    unsigned int    reserved_1:4;
}SIC_m_gir2;

typedef struct
{
    unsigned int    m_cp_irs:4;
    unsigned int    m_tp_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    m_mpeg_irs:4;
    unsigned int    m_vge_irs:4;
    unsigned int    m_osd_irs:4;
    unsigned int    reserved_1:4;
    unsigned int    reserved_2:4;
}SIC_m_gir3;

typedef struct
{
    unsigned int    m_apll_irs:4;
    unsigned int    m_vodma_irs:4;
    unsigned int    m_dct_irs:4;
    unsigned int    m_uz_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    m_idomain_irs:4;
    unsigned int    m_mdomain_irs:4;
    unsigned int    reserved_1:4;
}SIC_m_gir4;

typedef struct
{
    unsigned int    m_timer7_irs:4;
    unsigned int    m_timer6_irs:4;
    unsigned int    m_timer5_irs:4;
    unsigned int    m_timer4_irs:4;
    unsigned int    m_timer3_irs:4;
    unsigned int    m_timer2_irs:4;
    unsigned int    m_timer1_irs:4;
    unsigned int    m_timer0_irs:4;
}SIC_m_gir5;

typedef struct
{
    unsigned int    m_uart_0_irs:4;
    unsigned int    m_uart_1_irs:4;
    unsigned int    m_uart_2_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    m_lsadc_irs:4;
    unsigned int    m_rtc_irs:4;
    unsigned int    reserved_1:4;
    unsigned int    reserved_2:4;
}SIC_m_gir6;

typedef struct
{
    unsigned int    m_irda_irs:4;
    unsigned int    m_i2c_0_irs:4;
    unsigned int    m_i2c_1_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    m_ddc0_irs:4;
    unsigned int    m_ddc1_irs:4;
    unsigned int    m_ddc2_irs:4;
    unsigned int    m_ddc3_irs:4;
}SIC_m_gir7;

typedef struct
{
    unsigned int    m_gpioa_irs:4;
    unsigned int    m_gpiob_irs:4;
    unsigned int    m_gpioc_irs:4;
    unsigned int    m_gpiod_irs:4;
    unsigned int    m_gpioe_irs:4;
    unsigned int    m_gpiof_irs:4;
    unsigned int    m_gpiog_irs:4;
    unsigned int    m_gpioh_irs:4;
}SIC_m_gir8;

typedef struct
{
    unsigned int    m_gpiok_irs:4;
    unsigned int    m_gpiom_irs:4;
    unsigned int    m_gpion_irs:4;
    unsigned int    m_gpiop_irs:4;
    unsigned int    m_gpioq_irs:4;
    unsigned int    m_gpior_irs:4;
    unsigned int    m_gpios_irs:4;
    unsigned int    m_gpiot_irs:4;
}SIC_m_gir9;

typedef struct
{
    unsigned int    m_gpiou_irs:4;
    unsigned int    m_gpiov_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    reserved_1:4;
    unsigned int    m_sc_irs:4;
    unsigned int    m_pcmcia_irs:4;
    unsigned int    m_etn_irs:4;
    unsigned int    m_usb_irs:4;
}SIC_m_gir10;

typedef struct
{
    unsigned int    m_wdog_irs:4;
    unsigned int    m_nf_irs:4;
    unsigned int    m_cr_irs:4;
    unsigned int    reserved_0:20;
}SIC_m_gir11;

typedef struct
{
    unsigned int    m_dcu_ie:1;
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    m_tvsb_ie:1;
    unsigned int    reserved_4:1;
    unsigned int    m_rb_ie:1;
    unsigned int    reserved_5:1;
    unsigned int    reserved_6:1;
    unsigned int    m_adma_ie:1;
    unsigned int    reserved_7:1;
    unsigned int    reserved_8:1;
    unsigned int    m_md_ie:1;
    unsigned int    reserved_9:1;
    unsigned int    m_cpu_ie:1;
    unsigned int    reserved_10:1;
    unsigned int    m_if_demod_ie:1;
    unsigned int    m_vd_ie:1;
    unsigned int    m_vbi_ie:1;
    unsigned int    m_aud_ie:1;
    unsigned int    m_hdmi_ie:1;
    unsigned int    m_cec_ie:1;
    unsigned int    reserved_11:1;
    unsigned int    m_cp_ie:1;
    unsigned int    m_tp_ie:1;
    unsigned int    reserved_12:1;
    unsigned int    m_mpeg_ie:1;
    unsigned int    m_vge_ie:1;
    unsigned int    m_osd_ie:1;
    unsigned int    reserved_13:1;
    unsigned int    reserved_14:1;
}SIC_m_gie0;

typedef struct
{
    unsigned int    m_apll_ie:1;
    unsigned int    m_vodma_ie:1;
    unsigned int    m_dct_ie:1;
    unsigned int    m_uz_ie:1;
    unsigned int    reserved_0:1;
    unsigned int    m_idomain_ie:1;
    unsigned int    m_mdomain_ie:1;
    unsigned int    reserved_1:1;
    unsigned int    m_timer7_ie:1;
    unsigned int    m_timer6_ie:1;
    unsigned int    m_timer5_ie:1;
    unsigned int    m_timer4_ie:1;
    unsigned int    m_timer3_ie:1;
    unsigned int    m_timer2_ie:1;
    unsigned int    m_timer1_ie:1;
    unsigned int    m_timer0_ie:1;
    unsigned int    m_uart_0_ie:1;
    unsigned int    m_uart_1_ie:1;
    unsigned int    m_uart_2_ie:1;
    unsigned int    reserved_2:1;
    unsigned int    m_lsadc_ie:1;
    unsigned int    m_rtc_ie:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    m_irda_ie:1;
    unsigned int    m_i2c_0_ie:1;
    unsigned int    m_i2c_1_ie:1;
    unsigned int    reserved_5:1;
    unsigned int    m_ddc0_ie:1;
    unsigned int    m_ddc1_ie:1;
    unsigned int    m_ddc2_ie:1;
    unsigned int    m_ddc3_ie:1;
}SIC_m_gie1;

typedef struct
{
    unsigned int    m_gpioa_ie:1;
    unsigned int    m_gpiob_ie:1;
    unsigned int    m_gpioc_ie:1;
    unsigned int    m_gpiod_ie:1;
    unsigned int    m_gpioe_ie:1;
    unsigned int    m_gpiof_ie:1;
    unsigned int    m_gpiog_ie:1;
    unsigned int    m_gpioh_ie:1;
    unsigned int    m_gpiok_ie:1;
    unsigned int    m_gpiom_ie:1;
    unsigned int    m_gpion_ie:1;
    unsigned int    m_gpiop_ie:1;
    unsigned int    m_gpioq_ie:1;
    unsigned int    m_gpior_ie:1;
    unsigned int    m_gpios_ie:1;
    unsigned int    m_gpiot_ie:1;
    unsigned int    m_gpiou_ie:1;
    unsigned int    m_gpiov_ie:1;
    unsigned int    m_sc_ie:1;
    unsigned int    m_pcmcia_ie:1;
    unsigned int    m_etn_ie:1;
    unsigned int    m_usb_ie:1;
    unsigned int    m_wdog_ie:1;
    unsigned int    m_nf_ie:1;
    unsigned int    m_cr_ie:1;
    unsigned int    reserved_0:7;
}SIC_m_gie2;

typedef struct
{
    unsigned int    m_dcu_ip:1;
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    m_tvsb_ip:1;
    unsigned int    reserved_4:1;
    unsigned int    m_rb_ip:1;
    unsigned int    reserved_5:1;
    unsigned int    reserved_6:1;
    unsigned int    m_adma_ip:1;
    unsigned int    reserved_7:1;
    unsigned int    reserved_8:1;
    unsigned int    m_md_ip:1;
    unsigned int    reserved_9:1;
    unsigned int    m_cpu_ip:1;
    unsigned int    reserved_10:1;
    unsigned int    m_if_demod_ip:1;
    unsigned int    m_vd_ip:1;
    unsigned int    m_vbi_ip:1;
    unsigned int    m_aud_ip:1;
    unsigned int    m_hdmi_ip:1;
    unsigned int    m_cec_ip:1;
    unsigned int    reserved_11:1;
    unsigned int    m_cp_ip:1;
    unsigned int    m_tp_ip:1;
    unsigned int    reserved_12:1;
    unsigned int    m_mpeg_ip:1;
    unsigned int    m_vge_ip:1;
    unsigned int    m_osd_ip:1;
    unsigned int    reserved_13:1;
    unsigned int    reserved_14:1;
}SIC_m_gip0;

typedef struct
{
    unsigned int    m_apll_ip:1;
    unsigned int    m_vodma_ip:1;
    unsigned int    m_dct_ip:1;
    unsigned int    m_uz_ip:1;
    unsigned int    reserved_0:1;
    unsigned int    m_idomain_ip:1;
    unsigned int    m_mdomain_ip:1;
    unsigned int    reserved_1:1;
    unsigned int    m_timer7_ip:1;
    unsigned int    m_timer6_ip:1;
    unsigned int    m_timer5_ip:1;
    unsigned int    m_timer4_ip:1;
    unsigned int    m_timer3_ip:1;
    unsigned int    m_timer2_ip:1;
    unsigned int    m_timer1_ip:1;
    unsigned int    m_timer0_ip:1;
    unsigned int    m_uart_0_ip:1;
    unsigned int    m_uart_1_ip:1;
    unsigned int    m_uart_2_ip:1;
    unsigned int    reserved_2:1;
    unsigned int    m_lsadc_ip:1;
    unsigned int    m_rtc_ip:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    m_irda_ip:1;
    unsigned int    m_i2c_0_ip:1;
    unsigned int    m_i2c_1_ip:1;
    unsigned int    reserved_5:1;
    unsigned int    m_ddc0_ip:1;
    unsigned int    m_ddc1_ip:1;
    unsigned int    m_ddc2_ip:1;
    unsigned int    m_ddc3_ip:1;
}SIC_m_gip1;

typedef struct
{
    unsigned int    m_gpioa_ip:1;
    unsigned int    m_gpiob_ip:1;
    unsigned int    m_gpioc_ip:1;
    unsigned int    m_gpiod_ip:1;
    unsigned int    m_gpioe_ip:1;
    unsigned int    m_gpiof_ip:1;
    unsigned int    m_gpiog_ip:1;
    unsigned int    m_gpioh_ip:1;
    unsigned int    m_gpiok_ip:1;
    unsigned int    m_gpiom_ip:1;
    unsigned int    m_gpion_ip:1;
    unsigned int    m_gpiop_ip:1;
    unsigned int    m_gpioq_ip:1;
    unsigned int    m_gpior_ip:1;
    unsigned int    m_gpios_ip:1;
    unsigned int    m_gpiot_ip:1;
    unsigned int    m_gpiou_ip:1;
    unsigned int    m_gpiov_ip:1;
    unsigned int    m_sc_ip:1;
    unsigned int    m_pcmcia_ip:1;
    unsigned int    m_etn_ip:1;
    unsigned int    m_usb_ip:1;
    unsigned int    m_wdog_ip:1;
    unsigned int    m_nf_ip:1;
    unsigned int    m_cr_ip:1;
    unsigned int    reserved_0:7;
}SIC_m_gip2;

typedef struct
{
    unsigned int    av_dcu_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    reserved_1:4;
    unsigned int    reserved_2:4;
    unsigned int    reserved_3:4;
    unsigned int    av_tvsb_irs:4;
    unsigned int    reserved_4:4;
    unsigned int    av_rb_irs:4;
}SIC_av_gir0;

typedef struct
{
    unsigned int    av_ae_irs:4;
    unsigned int    av_cpudma_irs:4;
    unsigned int    av_adma_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    reserved_1:4;
    unsigned int    av_md_irs:4;
    unsigned int    reserved_2:4;
    unsigned int    av_cpu_irs:4;
}SIC_av_gir1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    av_if_demod_irs:4;
    unsigned int    av_vd_irs:4;
    unsigned int    av_vbi_irs:4;
    unsigned int    av_aud_irs:4;
    unsigned int    av_hdmi_irs:4;
    unsigned int    av_cec_irs:4;
    unsigned int    reserved_1:4;
}SIC_av_gir2;

typedef struct
{
    unsigned int    av_cp_irs:4;
    unsigned int    av_tp_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    av_mpeg_irs:4;
    unsigned int    av_vge_irs:4;
    unsigned int    av_osd_irs:4;
    unsigned int    reserved_1:4;
    unsigned int    reserved_2:4;
}SIC_av_gir3;

typedef struct
{
    unsigned int    av_apll_irs:4;
    unsigned int    av_vodma_irs:4;
    unsigned int    av_dct_irs:4;
    unsigned int    av_uz_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    av_idomain_irs:4;
    unsigned int    av_mdomain_irs:4;
    unsigned int    reserved_1:4;
}SIC_av_gir4;

typedef struct
{
    unsigned int    av_timer7_irs:4;
    unsigned int    av_timer6_irs:4;
    unsigned int    av_timer5_irs:4;
    unsigned int    av_timer4_irs:4;
    unsigned int    av_timer3_irs:4;
    unsigned int    av_timer2_irs:4;
    unsigned int    av_timer1_irs:4;
    unsigned int    av_timer0_irs:4;
}SIC_av_gir5;

typedef struct
{
    unsigned int    av_uart_0_irs:4;
    unsigned int    av_uart_1_irs:4;
    unsigned int    av_uart_2_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    av_lsadc_irs:4;
    unsigned int    av_rtc_irs:4;
    unsigned int    reserved_1:4;
    unsigned int    reserved_2:4;
}SIC_av_gir6;

typedef struct
{
    unsigned int    av_irda_irs:4;
    unsigned int    av_i2c_0_irs:4;
    unsigned int    av_i2c_1_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    av_ddc0_irs:4;
    unsigned int    av_ddc1_irs:4;
    unsigned int    av_ddc2_irs:4;
    unsigned int    av_ddc3_irs:4;
}SIC_av_gir7;

typedef struct
{
    unsigned int    av_gpioa_irs:4;
    unsigned int    av_gpiob_irs:4;
    unsigned int    av_gpioc_irs:4;
    unsigned int    av_gpiod_irs:4;
    unsigned int    av_gpioe_irs:4;
    unsigned int    av_gpiof_irs:4;
    unsigned int    av_gpiog_irs:4;
    unsigned int    av_gpioh_irs:4;
}SIC_av_gir8;

typedef struct
{
    unsigned int    av_gpiok_irs:4;
    unsigned int    av_gpiom_irs:4;
    unsigned int    av_gpion_irs:4;
    unsigned int    av_gpiop_irs:4;
    unsigned int    av_gpioq_irs:4;
    unsigned int    av_gpior_irs:4;
    unsigned int    av_gpios_irs:4;
    unsigned int    av_gpiot_irs:4;
}SIC_av_gir9;

typedef struct
{
    unsigned int    av_gpiou_irs:4;
    unsigned int    av_gpiov_irs:4;
    unsigned int    reserved_0:4;
    unsigned int    reserved_1:4;
    unsigned int    av_sc_irs:4;
    unsigned int    av_pcmcia_irs:4;
    unsigned int    av_etn_irs:4;
    unsigned int    av_usb_irs:4;
}SIC_av_gir10;

typedef struct
{
    unsigned int    av_wdog_irs:4;
    unsigned int    av_nf_irs:4;
    unsigned int    av_cr_irs:4;
    unsigned int    reserved_0:20;
}SIC_av_gir11;

typedef struct
{
    unsigned int    av_dcu_ie:1;
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    av_tvsb_ie:1;
    unsigned int    reserved_4:1;
    unsigned int    av_rb_ie:1;
    unsigned int    av_ae_ie:1;
    unsigned int    av_cpudma_ie:1;
    unsigned int    av_adma_ie:1;
    unsigned int    reserved_5:1;
    unsigned int    reserved_6:1;
    unsigned int    av_md_ie:1;
    unsigned int    reserved_7:1;
    unsigned int    av_cpu_ie:1;
    unsigned int    reserved_8:1;
    unsigned int    av_if_demod_ie:1;
    unsigned int    av_vd_ie:1;
    unsigned int    av_vbi_ie:1;
    unsigned int    av_aud_ie:1;
    unsigned int    av_hdmi_ie:1;
    unsigned int    av_cec_ie:1;
    unsigned int    reserved_9:1;
    unsigned int    av_cp_ie:1;
    unsigned int    av_tp_ie:1;
    unsigned int    reserved_10:1;
    unsigned int    av_mpeg_ie:1;
    unsigned int    av_vge_ie:1;
    unsigned int    av_osd_ie:1;
    unsigned int    reserved_11:1;
    unsigned int    reserved_12:1;
}SIC_av_gie0;

typedef struct
{
    unsigned int    av_apll_ie:1;
    unsigned int    av_vodma_ie:1;
    unsigned int    av_dct_ie:1;
    unsigned int    av_uz_ie:1;
    unsigned int    reserved_0:1;
    unsigned int    av_idomain_ie:1;
    unsigned int    av_mdomain_ie:1;
    unsigned int    reserved_1:1;
    unsigned int    av_timer7_ie:1;
    unsigned int    av_timer6_ie:1;
    unsigned int    av_timer5_ie:1;
    unsigned int    av_timer4_ie:1;
    unsigned int    av_timer3_ie:1;
    unsigned int    av_timer2_ie:1;
    unsigned int    av_timer1_ie:1;
    unsigned int    av_timer0_ie:1;
    unsigned int    av_uart_0_ie:1;
    unsigned int    av_uart_1_ie:1;
    unsigned int    av_uart_2_ie:1;
    unsigned int    reserved_2:1;
    unsigned int    av_lsadc_ie:1;
    unsigned int    av_rtc_ie:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    av_irda_ie:1;
    unsigned int    av_i2c_0_ie:1;
    unsigned int    av_i2c_1_ie:1;
    unsigned int    reserved_5:1;
    unsigned int    av_ddc0_ie:1;
    unsigned int    av_ddc1_ie:1;
    unsigned int    av_ddc2_ie:1;
    unsigned int    av_ddc3_ie:1;
}SIC_av_gie1;

typedef struct
{
    unsigned int    av_gpioa_ie:1;
    unsigned int    av_gpiob_ie:1;
    unsigned int    av_gpioc_ie:1;
    unsigned int    av_gpiod_ie:1;
    unsigned int    av_gpioe_ie:1;
    unsigned int    av_gpiof_ie:1;
    unsigned int    av_gpiog_ie:1;
    unsigned int    av_gpioh_ie:1;
    unsigned int    av_gpiok_ie:1;
    unsigned int    av_gpiom_ie:1;
    unsigned int    av_gpion_ie:1;
    unsigned int    av_gpiop_ie:1;
    unsigned int    av_gpioq_ie:1;
    unsigned int    av_gpior_ie:1;
    unsigned int    av_gpios_ie:1;
    unsigned int    av_gpiot_ie:1;
    unsigned int    av_gpiou_ie:1;
    unsigned int    av_gpiov_ie:1;
    unsigned int    av_sc_ie:1;
    unsigned int    av_pcmcia_ie:1;
    unsigned int    av_etn_ie:1;
    unsigned int    av_usb_ie:1;
    unsigned int    av_wdog_ie:1;
    unsigned int    av_nf_ie:1;
    unsigned int    av_cr_ie:1;
    unsigned int    reserved_0:7;
}SIC_av_gie2;

typedef struct
{
    unsigned int    av_dcu_ip:1;
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    av_tvsb_ip:1;
    unsigned int    reserved_4:1;
    unsigned int    av_rb_ip:1;
    unsigned int    av_ae_ip:1;
    unsigned int    av_cpudma_ip:1;
    unsigned int    av_adma_ip:1;
    unsigned int    reserved_5:1;
    unsigned int    reserved_6:1;
    unsigned int    av_md_ip:1;
    unsigned int    reserved_7:1;
    unsigned int    av_cpu_ip:1;
    unsigned int    reserved_8:1;
    unsigned int    av_if_demod_ip:1;
    unsigned int    av_vd_ip:1;
    unsigned int    av_vbi_ip:1;
    unsigned int    av_aud_ip:1;
    unsigned int    av_hdmi_ip:1;
    unsigned int    av_cec_ip:1;
    unsigned int    reserved_9:1;
    unsigned int    av_cp_ip:1;
    unsigned int    av_tp_ip:1;
    unsigned int    reserved_10:1;
    unsigned int    av_mpeg_ip:1;
    unsigned int    av_vge_ip:1;
    unsigned int    av_osd_ip:1;
    unsigned int    reserved_11:1;
    unsigned int    reserved_12:1;
}SIC_av_gip0;

typedef struct
{
    unsigned int    av_apll_ip:1;
    unsigned int    av_vodma_ip:1;
    unsigned int    av_dct_ip:1;
    unsigned int    av_uz_ip:1;
    unsigned int    reserved_0:1;
    unsigned int    av_idomain_ip:1;
    unsigned int    av_mdomain_ip:1;
    unsigned int    reserved_1:1;
    unsigned int    av_timer7_ip:1;
    unsigned int    av_timer6_ip:1;
    unsigned int    av_timer5_ip:1;
    unsigned int    av_timer4_ip:1;
    unsigned int    av_timer3_ip:1;
    unsigned int    av_timer2_ip:1;
    unsigned int    av_timer1_ip:1;
    unsigned int    av_timer0_ip:1;
    unsigned int    av_uart_0_ip:1;
    unsigned int    av_uart_1_ip:1;
    unsigned int    av_uart_2_ip:1;
    unsigned int    reserved_2:1;
    unsigned int    av_lsadc_ip:1;
    unsigned int    av_rtc_ip:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    av_irda_ip:1;
    unsigned int    av_i2c_0_ip:1;
    unsigned int    av_i2c_1_ip:1;
    unsigned int    reserved_5:1;
    unsigned int    av_ddc0_ip:1;
    unsigned int    av_ddc1_ip:1;
    unsigned int    av_ddc2_ip:1;
    unsigned int    av_ddc3_ip:1;
}SIC_av_gip1;

typedef struct
{
    unsigned int    av_gpioa_ip:1;
    unsigned int    av_gpiob_ip:1;
    unsigned int    av_gpioc_ip:1;
    unsigned int    av_gpiod_ip:1;
    unsigned int    av_gpioe_ip:1;
    unsigned int    av_gpiof_ip:1;
    unsigned int    av_gpiog_ip:1;
    unsigned int    av_gpioh_ip:1;
    unsigned int    av_gpiok_ip:1;
    unsigned int    av_gpiom_ip:1;
    unsigned int    av_gpion_ip:1;
    unsigned int    av_gpiop_ip:1;
    unsigned int    av_gpioq_ip:1;
    unsigned int    av_gpior_ip:1;
    unsigned int    av_gpios_ip:1;
    unsigned int    av_gpiot_ip:1;
    unsigned int    av_gpiou_ip:1;
    unsigned int    av_gpiov_ip:1;
    unsigned int    av_sc_ip:1;
    unsigned int    av_pcmcia_ip:1;
    unsigned int    av_etn_ip:1;
    unsigned int    av_usb_ip:1;
    unsigned int    av_wdog_ip:1;
    unsigned int    av_nf_ip:1;
    unsigned int    av_cr_ip:1;
    unsigned int    reserved_0:7;
}SIC_av_gip2;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    int_debug_en:1;
}SIC_debug_info_enable;

typedef struct
{
    unsigned int    m_debug_ie0:32;
}SIC_debug_mcpu_ie0;

typedef struct
{
    unsigned int    m_debug_ie1:32;
}SIC_debug_mcpu_ie1;

typedef struct
{
    unsigned int    m_debug_ie2:32;
}SIC_debug_mcpu_ie2;

typedef struct
{
    unsigned int    m_debug_ip0:32;
}SIC_debug_mcpu_ip0;

typedef struct
{
    unsigned int    m_debug_ip1:32;
}SIC_debug_mcpu_ip1;

typedef struct
{
    unsigned int    m_debug_ip2:32;
}SIC_debug_mcpu_ip2;

typedef struct
{
    unsigned int    av_debug_ie0:32;
}SIC_debug_avcpu_ie0;

typedef struct
{
    unsigned int    av_debug_ie1:32;
}SIC_debug_avcpu_ie1;

typedef struct
{
    unsigned int    av_debug_ie2:32;
}SIC_debug_avcpu_ie2;

typedef struct
{
    unsigned int    av_debug_ip0:32;
}SIC_debug_avcpu_ip0;

typedef struct
{
    unsigned int    av_debug_ip1:32;
}SIC_debug_avcpu_ip1;

typedef struct
{
    unsigned int    av_debug_ip2:32;
}SIC_debug_avcpu_ip2;
#endif


#define SIC_M_GIR0                                                    0x18003200
#define SIC_M_GIR0_reg_addr                                           "0xb8003200"
#define SIC_M_GIR0_reg                                                0xb8003200
#define SIC_M_GIR0_inst_addr                                          "0x0080"
#define SIC_M_GIR0_inst                                               0x0080
#define SIC_M_GIR0_m_dcu_irs_shift                                    (28)
#define SIC_M_GIR0_m_tvsb_irs_shift                                   (8)
#define SIC_M_GIR0_m_rb_irs_shift                                     (0)
#define SIC_M_GIR0_m_dcu_irs_mask                                     (0xF0000000)
#define SIC_M_GIR0_m_tvsb_irs_mask                                    (0x00000F00)
#define SIC_M_GIR0_m_rb_irs_mask                                      (0x0000000F)
#define SIC_M_GIR0_m_dcu_irs(data)                                    (0xF0000000&((data)<<28))
#define SIC_M_GIR0_m_tvsb_irs(data)                                   (0x00000F00&((data)<<8))
#define SIC_M_GIR0_m_rb_irs(data)                                     (0x0000000F&(data))
#define SIC_M_GIR0_get_m_dcu_irs(data)                                ((0xF0000000&(data))>>28)
#define SIC_M_GIR0_get_m_tvsb_irs(data)                               ((0x00000F00&(data))>>8)
#define SIC_M_GIR0_get_m_rb_irs(data)                                 (0x0000000F&(data))


#define SIC_M_GIR1                                                    0x18003204
#define SIC_M_GIR1_reg_addr                                           "0xb8003204"
#define SIC_M_GIR1_reg                                                0xb8003204
#define SIC_M_GIR1_inst_addr                                          "0x0081"
#define SIC_M_GIR1_inst                                               0x0081
#define SIC_M_GIR1_m_adma_irs_shift                                   (20)
#define SIC_M_GIR1_m_md_irs_shift                                     (8)
#define SIC_M_GIR1_m_cpu_irs_shift                                    (0)
#define SIC_M_GIR1_m_adma_irs_mask                                    (0x00F00000)
#define SIC_M_GIR1_m_md_irs_mask                                      (0x00000F00)
#define SIC_M_GIR1_m_cpu_irs_mask                                     (0x0000000F)
#define SIC_M_GIR1_m_adma_irs(data)                                   (0x00F00000&((data)<<20))
#define SIC_M_GIR1_m_md_irs(data)                                     (0x00000F00&((data)<<8))
#define SIC_M_GIR1_m_cpu_irs(data)                                    (0x0000000F&(data))
#define SIC_M_GIR1_get_m_adma_irs(data)                               ((0x00F00000&(data))>>20)
#define SIC_M_GIR1_get_m_md_irs(data)                                 ((0x00000F00&(data))>>8)
#define SIC_M_GIR1_get_m_cpu_irs(data)                                (0x0000000F&(data))


#define SIC_M_GIR2                                                    0x18003208
#define SIC_M_GIR2_reg_addr                                           "0xb8003208"
#define SIC_M_GIR2_reg                                                0xb8003208
#define SIC_M_GIR2_inst_addr                                          "0x0082"
#define SIC_M_GIR2_inst                                               0x0082
#define SIC_M_GIR2_m_if_demod_irs_shift                               (24)
#define SIC_M_GIR2_m_vd_irs_shift                                     (20)
#define SIC_M_GIR2_m_vbi_irs_shift                                    (16)
#define SIC_M_GIR2_m_aud_irs_shift                                    (12)
#define SIC_M_GIR2_m_hdmi_irs_shift                                   (8)
#define SIC_M_GIR2_m_cec_irs_shift                                    (4)
#define SIC_M_GIR2_m_if_demod_irs_mask                                (0x0F000000)
#define SIC_M_GIR2_m_vd_irs_mask                                      (0x00F00000)
#define SIC_M_GIR2_m_vbi_irs_mask                                     (0x000F0000)
#define SIC_M_GIR2_m_aud_irs_mask                                     (0x0000F000)
#define SIC_M_GIR2_m_hdmi_irs_mask                                    (0x00000F00)
#define SIC_M_GIR2_m_cec_irs_mask                                     (0x000000F0)
#define SIC_M_GIR2_m_if_demod_irs(data)                               (0x0F000000&((data)<<24))
#define SIC_M_GIR2_m_vd_irs(data)                                     (0x00F00000&((data)<<20))
#define SIC_M_GIR2_m_vbi_irs(data)                                    (0x000F0000&((data)<<16))
#define SIC_M_GIR2_m_aud_irs(data)                                    (0x0000F000&((data)<<12))
#define SIC_M_GIR2_m_hdmi_irs(data)                                   (0x00000F00&((data)<<8))
#define SIC_M_GIR2_m_cec_irs(data)                                    (0x000000F0&((data)<<4))
#define SIC_M_GIR2_get_m_if_demod_irs(data)                           ((0x0F000000&(data))>>24)
#define SIC_M_GIR2_get_m_vd_irs(data)                                 ((0x00F00000&(data))>>20)
#define SIC_M_GIR2_get_m_vbi_irs(data)                                ((0x000F0000&(data))>>16)
#define SIC_M_GIR2_get_m_aud_irs(data)                                ((0x0000F000&(data))>>12)
#define SIC_M_GIR2_get_m_hdmi_irs(data)                               ((0x00000F00&(data))>>8)
#define SIC_M_GIR2_get_m_cec_irs(data)                                ((0x000000F0&(data))>>4)


#define SIC_M_GIR3                                                    0x1800320c
#define SIC_M_GIR3_reg_addr                                           "0xb800320c"
#define SIC_M_GIR3_reg                                                0xb800320c
#define SIC_M_GIR3_inst_addr                                          "0x0083"
#define SIC_M_GIR3_inst                                               0x0083
#define SIC_M_GIR3_m_cp_irs_shift                                     (28)
#define SIC_M_GIR3_m_tp_irs_shift                                     (24)
#define SIC_M_GIR3_m_mpeg_irs_shift                                   (16)
#define SIC_M_GIR3_m_vge_irs_shift                                    (12)
#define SIC_M_GIR3_m_osd_irs_shift                                    (8)
#define SIC_M_GIR3_m_cp_irs_mask                                      (0xF0000000)
#define SIC_M_GIR3_m_tp_irs_mask                                      (0x0F000000)
#define SIC_M_GIR3_m_mpeg_irs_mask                                    (0x000F0000)
#define SIC_M_GIR3_m_vge_irs_mask                                     (0x0000F000)
#define SIC_M_GIR3_m_osd_irs_mask                                     (0x00000F00)
#define SIC_M_GIR3_m_cp_irs(data)                                     (0xF0000000&((data)<<28))
#define SIC_M_GIR3_m_tp_irs(data)                                     (0x0F000000&((data)<<24))
#define SIC_M_GIR3_m_mpeg_irs(data)                                   (0x000F0000&((data)<<16))
#define SIC_M_GIR3_m_vge_irs(data)                                    (0x0000F000&((data)<<12))
#define SIC_M_GIR3_m_osd_irs(data)                                    (0x00000F00&((data)<<8))
#define SIC_M_GIR3_get_m_cp_irs(data)                                 ((0xF0000000&(data))>>28)
#define SIC_M_GIR3_get_m_tp_irs(data)                                 ((0x0F000000&(data))>>24)
#define SIC_M_GIR3_get_m_mpeg_irs(data)                               ((0x000F0000&(data))>>16)
#define SIC_M_GIR3_get_m_vge_irs(data)                                ((0x0000F000&(data))>>12)
#define SIC_M_GIR3_get_m_osd_irs(data)                                ((0x00000F00&(data))>>8)


#define SIC_M_GIR4                                                    0x18003210
#define SIC_M_GIR4_reg_addr                                           "0xb8003210"
#define SIC_M_GIR4_reg                                                0xb8003210
#define SIC_M_GIR4_inst_addr                                          "0x0084"
#define SIC_M_GIR4_inst                                               0x0084
#define SIC_M_GIR4_m_apll_irs_shift                                   (28)
#define SIC_M_GIR4_m_vodma_irs_shift                                  (24)
#define SIC_M_GIR4_m_dct_irs_shift                                    (20)
#define SIC_M_GIR4_m_uz_irs_shift                                     (16)
#define SIC_M_GIR4_m_idomain_irs_shift                                (8)
#define SIC_M_GIR4_m_mdomain_irs_shift                                (4)
#define SIC_M_GIR4_m_apll_irs_mask                                    (0xF0000000)
#define SIC_M_GIR4_m_vodma_irs_mask                                   (0x0F000000)
#define SIC_M_GIR4_m_dct_irs_mask                                     (0x00F00000)
#define SIC_M_GIR4_m_uz_irs_mask                                      (0x000F0000)
#define SIC_M_GIR4_m_idomain_irs_mask                                 (0x00000F00)
#define SIC_M_GIR4_m_mdomain_irs_mask                                 (0x000000F0)
#define SIC_M_GIR4_m_apll_irs(data)                                   (0xF0000000&((data)<<28))
#define SIC_M_GIR4_m_vodma_irs(data)                                  (0x0F000000&((data)<<24))
#define SIC_M_GIR4_m_dct_irs(data)                                    (0x00F00000&((data)<<20))
#define SIC_M_GIR4_m_uz_irs(data)                                     (0x000F0000&((data)<<16))
#define SIC_M_GIR4_m_idomain_irs(data)                                (0x00000F00&((data)<<8))
#define SIC_M_GIR4_m_mdomain_irs(data)                                (0x000000F0&((data)<<4))
#define SIC_M_GIR4_get_m_apll_irs(data)                               ((0xF0000000&(data))>>28)
#define SIC_M_GIR4_get_m_vodma_irs(data)                              ((0x0F000000&(data))>>24)
#define SIC_M_GIR4_get_m_dct_irs(data)                                ((0x00F00000&(data))>>20)
#define SIC_M_GIR4_get_m_uz_irs(data)                                 ((0x000F0000&(data))>>16)
#define SIC_M_GIR4_get_m_idomain_irs(data)                            ((0x00000F00&(data))>>8)
#define SIC_M_GIR4_get_m_mdomain_irs(data)                            ((0x000000F0&(data))>>4)


#define SIC_M_GIR5                                                    0x18003214
#define SIC_M_GIR5_reg_addr                                           "0xb8003214"
#define SIC_M_GIR5_reg                                                0xb8003214
#define SIC_M_GIR5_inst_addr                                          "0x0085"
#define SIC_M_GIR5_inst                                               0x0085
#define SIC_M_GIR5_m_timer7_irs_shift                                 (28)
#define SIC_M_GIR5_m_timer6_irs_shift                                 (24)
#define SIC_M_GIR5_m_timer5_irs_shift                                 (20)
#define SIC_M_GIR5_m_timer4_irs_shift                                 (16)
#define SIC_M_GIR5_m_timer3_irs_shift                                 (12)
#define SIC_M_GIR5_m_timer2_irs_shift                                 (8)
#define SIC_M_GIR5_m_timer1_irs_shift                                 (4)
#define SIC_M_GIR5_m_timer0_irs_shift                                 (0)
#define SIC_M_GIR5_m_timer7_irs_mask                                  (0xF0000000)
#define SIC_M_GIR5_m_timer6_irs_mask                                  (0x0F000000)
#define SIC_M_GIR5_m_timer5_irs_mask                                  (0x00F00000)
#define SIC_M_GIR5_m_timer4_irs_mask                                  (0x000F0000)
#define SIC_M_GIR5_m_timer3_irs_mask                                  (0x0000F000)
#define SIC_M_GIR5_m_timer2_irs_mask                                  (0x00000F00)
#define SIC_M_GIR5_m_timer1_irs_mask                                  (0x000000F0)
#define SIC_M_GIR5_m_timer0_irs_mask                                  (0x0000000F)
#define SIC_M_GIR5_m_timer7_irs(data)                                 (0xF0000000&((data)<<28))
#define SIC_M_GIR5_m_timer6_irs(data)                                 (0x0F000000&((data)<<24))
#define SIC_M_GIR5_m_timer5_irs(data)                                 (0x00F00000&((data)<<20))
#define SIC_M_GIR5_m_timer4_irs(data)                                 (0x000F0000&((data)<<16))
#define SIC_M_GIR5_m_timer3_irs(data)                                 (0x0000F000&((data)<<12))
#define SIC_M_GIR5_m_timer2_irs(data)                                 (0x00000F00&((data)<<8))
#define SIC_M_GIR5_m_timer1_irs(data)                                 (0x000000F0&((data)<<4))
#define SIC_M_GIR5_m_timer0_irs(data)                                 (0x0000000F&(data))
#define SIC_M_GIR5_get_m_timer7_irs(data)                             ((0xF0000000&(data))>>28)
#define SIC_M_GIR5_get_m_timer6_irs(data)                             ((0x0F000000&(data))>>24)
#define SIC_M_GIR5_get_m_timer5_irs(data)                             ((0x00F00000&(data))>>20)
#define SIC_M_GIR5_get_m_timer4_irs(data)                             ((0x000F0000&(data))>>16)
#define SIC_M_GIR5_get_m_timer3_irs(data)                             ((0x0000F000&(data))>>12)
#define SIC_M_GIR5_get_m_timer2_irs(data)                             ((0x00000F00&(data))>>8)
#define SIC_M_GIR5_get_m_timer1_irs(data)                             ((0x000000F0&(data))>>4)
#define SIC_M_GIR5_get_m_timer0_irs(data)                             (0x0000000F&(data))


#define SIC_M_GIR6                                                    0x18003218
#define SIC_M_GIR6_reg_addr                                           "0xb8003218"
#define SIC_M_GIR6_reg                                                0xb8003218
#define SIC_M_GIR6_inst_addr                                          "0x0086"
#define SIC_M_GIR6_inst                                               0x0086
#define SIC_M_GIR6_m_uart_0_irs_shift                                 (28)
#define SIC_M_GIR6_m_uart_1_irs_shift                                 (24)
#define SIC_M_GIR6_m_uart_2_irs_shift                                 (20)
#define SIC_M_GIR6_m_lsadc_irs_shift                                  (12)
#define SIC_M_GIR6_m_rtc_irs_shift                                    (8)
#define SIC_M_GIR6_m_uart_0_irs_mask                                  (0xF0000000)
#define SIC_M_GIR6_m_uart_1_irs_mask                                  (0x0F000000)
#define SIC_M_GIR6_m_uart_2_irs_mask                                  (0x00F00000)
#define SIC_M_GIR6_m_lsadc_irs_mask                                   (0x0000F000)
#define SIC_M_GIR6_m_rtc_irs_mask                                     (0x00000F00)
#define SIC_M_GIR6_m_uart_0_irs(data)                                 (0xF0000000&((data)<<28))
#define SIC_M_GIR6_m_uart_1_irs(data)                                 (0x0F000000&((data)<<24))
#define SIC_M_GIR6_m_uart_2_irs(data)                                 (0x00F00000&((data)<<20))
#define SIC_M_GIR6_m_lsadc_irs(data)                                  (0x0000F000&((data)<<12))
#define SIC_M_GIR6_m_rtc_irs(data)                                    (0x00000F00&((data)<<8))
#define SIC_M_GIR6_get_m_uart_0_irs(data)                             ((0xF0000000&(data))>>28)
#define SIC_M_GIR6_get_m_uart_1_irs(data)                             ((0x0F000000&(data))>>24)
#define SIC_M_GIR6_get_m_uart_2_irs(data)                             ((0x00F00000&(data))>>20)
#define SIC_M_GIR6_get_m_lsadc_irs(data)                              ((0x0000F000&(data))>>12)
#define SIC_M_GIR6_get_m_rtc_irs(data)                                ((0x00000F00&(data))>>8)


#define SIC_M_GIR7                                                    0x1800321c
#define SIC_M_GIR7_reg_addr                                           "0xb800321c"
#define SIC_M_GIR7_reg                                                0xb800321c
#define SIC_M_GIR7_inst_addr                                          "0x0087"
#define SIC_M_GIR7_inst                                               0x0087
#define SIC_M_GIR7_m_irda_irs_shift                                   (28)
#define SIC_M_GIR7_m_i2c_0_irs_shift                                  (24)
#define SIC_M_GIR7_m_i2c_1_irs_shift                                  (20)
#define SIC_M_GIR7_m_ddc0_irs_shift                                   (12)
#define SIC_M_GIR7_m_ddc1_irs_shift                                   (8)
#define SIC_M_GIR7_m_ddc2_irs_shift                                   (4)
#define SIC_M_GIR7_m_ddc3_irs_shift                                   (0)
#define SIC_M_GIR7_m_irda_irs_mask                                    (0xF0000000)
#define SIC_M_GIR7_m_i2c_0_irs_mask                                   (0x0F000000)
#define SIC_M_GIR7_m_i2c_1_irs_mask                                   (0x00F00000)
#define SIC_M_GIR7_m_ddc0_irs_mask                                    (0x0000F000)
#define SIC_M_GIR7_m_ddc1_irs_mask                                    (0x00000F00)
#define SIC_M_GIR7_m_ddc2_irs_mask                                    (0x000000F0)
#define SIC_M_GIR7_m_ddc3_irs_mask                                    (0x0000000F)
#define SIC_M_GIR7_m_irda_irs(data)                                   (0xF0000000&((data)<<28))
#define SIC_M_GIR7_m_i2c_0_irs(data)                                  (0x0F000000&((data)<<24))
#define SIC_M_GIR7_m_i2c_1_irs(data)                                  (0x00F00000&((data)<<20))
#define SIC_M_GIR7_m_ddc0_irs(data)                                   (0x0000F000&((data)<<12))
#define SIC_M_GIR7_m_ddc1_irs(data)                                   (0x00000F00&((data)<<8))
#define SIC_M_GIR7_m_ddc2_irs(data)                                   (0x000000F0&((data)<<4))
#define SIC_M_GIR7_m_ddc3_irs(data)                                   (0x0000000F&(data))
#define SIC_M_GIR7_get_m_irda_irs(data)                               ((0xF0000000&(data))>>28)
#define SIC_M_GIR7_get_m_i2c_0_irs(data)                              ((0x0F000000&(data))>>24)
#define SIC_M_GIR7_get_m_i2c_1_irs(data)                              ((0x00F00000&(data))>>20)
#define SIC_M_GIR7_get_m_ddc0_irs(data)                               ((0x0000F000&(data))>>12)
#define SIC_M_GIR7_get_m_ddc1_irs(data)                               ((0x00000F00&(data))>>8)
#define SIC_M_GIR7_get_m_ddc2_irs(data)                               ((0x000000F0&(data))>>4)
#define SIC_M_GIR7_get_m_ddc3_irs(data)                               (0x0000000F&(data))


#define SIC_M_GIR8                                                    0x18003220
#define SIC_M_GIR8_reg_addr                                           "0xb8003220"
#define SIC_M_GIR8_reg                                                0xb8003220
#define SIC_M_GIR8_inst_addr                                          "0x0088"
#define SIC_M_GIR8_inst                                               0x0088
#define SIC_M_GIR8_m_gpioa_irs_shift                                  (28)
#define SIC_M_GIR8_m_gpiob_irs_shift                                  (24)
#define SIC_M_GIR8_m_gpioc_irs_shift                                  (20)
#define SIC_M_GIR8_m_gpiod_irs_shift                                  (16)
#define SIC_M_GIR8_m_gpioe_irs_shift                                  (12)
#define SIC_M_GIR8_m_gpiof_irs_shift                                  (8)
#define SIC_M_GIR8_m_gpiog_irs_shift                                  (4)
#define SIC_M_GIR8_m_gpioh_irs_shift                                  (0)
#define SIC_M_GIR8_m_gpioa_irs_mask                                   (0xF0000000)
#define SIC_M_GIR8_m_gpiob_irs_mask                                   (0x0F000000)
#define SIC_M_GIR8_m_gpioc_irs_mask                                   (0x00F00000)
#define SIC_M_GIR8_m_gpiod_irs_mask                                   (0x000F0000)
#define SIC_M_GIR8_m_gpioe_irs_mask                                   (0x0000F000)
#define SIC_M_GIR8_m_gpiof_irs_mask                                   (0x00000F00)
#define SIC_M_GIR8_m_gpiog_irs_mask                                   (0x000000F0)
#define SIC_M_GIR8_m_gpioh_irs_mask                                   (0x0000000F)
#define SIC_M_GIR8_m_gpioa_irs(data)                                  (0xF0000000&((data)<<28))
#define SIC_M_GIR8_m_gpiob_irs(data)                                  (0x0F000000&((data)<<24))
#define SIC_M_GIR8_m_gpioc_irs(data)                                  (0x00F00000&((data)<<20))
#define SIC_M_GIR8_m_gpiod_irs(data)                                  (0x000F0000&((data)<<16))
#define SIC_M_GIR8_m_gpioe_irs(data)                                  (0x0000F000&((data)<<12))
#define SIC_M_GIR8_m_gpiof_irs(data)                                  (0x00000F00&((data)<<8))
#define SIC_M_GIR8_m_gpiog_irs(data)                                  (0x000000F0&((data)<<4))
#define SIC_M_GIR8_m_gpioh_irs(data)                                  (0x0000000F&(data))
#define SIC_M_GIR8_get_m_gpioa_irs(data)                              ((0xF0000000&(data))>>28)
#define SIC_M_GIR8_get_m_gpiob_irs(data)                              ((0x0F000000&(data))>>24)
#define SIC_M_GIR8_get_m_gpioc_irs(data)                              ((0x00F00000&(data))>>20)
#define SIC_M_GIR8_get_m_gpiod_irs(data)                              ((0x000F0000&(data))>>16)
#define SIC_M_GIR8_get_m_gpioe_irs(data)                              ((0x0000F000&(data))>>12)
#define SIC_M_GIR8_get_m_gpiof_irs(data)                              ((0x00000F00&(data))>>8)
#define SIC_M_GIR8_get_m_gpiog_irs(data)                              ((0x000000F0&(data))>>4)
#define SIC_M_GIR8_get_m_gpioh_irs(data)                              (0x0000000F&(data))


#define SIC_M_GIR9                                                    0x18003224
#define SIC_M_GIR9_reg_addr                                           "0xb8003224"
#define SIC_M_GIR9_reg                                                0xb8003224
#define SIC_M_GIR9_inst_addr                                          "0x0089"
#define SIC_M_GIR9_inst                                               0x0089
#define SIC_M_GIR9_m_gpiok_irs_shift                                  (28)
#define SIC_M_GIR9_m_gpiom_irs_shift                                  (24)
#define SIC_M_GIR9_m_gpion_irs_shift                                  (20)
#define SIC_M_GIR9_m_gpiop_irs_shift                                  (16)
#define SIC_M_GIR9_m_gpioq_irs_shift                                  (12)
#define SIC_M_GIR9_m_gpior_irs_shift                                  (8)
#define SIC_M_GIR9_m_gpios_irs_shift                                  (4)
#define SIC_M_GIR9_m_gpiot_irs_shift                                  (0)
#define SIC_M_GIR9_m_gpiok_irs_mask                                   (0xF0000000)
#define SIC_M_GIR9_m_gpiom_irs_mask                                   (0x0F000000)
#define SIC_M_GIR9_m_gpion_irs_mask                                   (0x00F00000)
#define SIC_M_GIR9_m_gpiop_irs_mask                                   (0x000F0000)
#define SIC_M_GIR9_m_gpioq_irs_mask                                   (0x0000F000)
#define SIC_M_GIR9_m_gpior_irs_mask                                   (0x00000F00)
#define SIC_M_GIR9_m_gpios_irs_mask                                   (0x000000F0)
#define SIC_M_GIR9_m_gpiot_irs_mask                                   (0x0000000F)
#define SIC_M_GIR9_m_gpiok_irs(data)                                  (0xF0000000&((data)<<28))
#define SIC_M_GIR9_m_gpiom_irs(data)                                  (0x0F000000&((data)<<24))
#define SIC_M_GIR9_m_gpion_irs(data)                                  (0x00F00000&((data)<<20))
#define SIC_M_GIR9_m_gpiop_irs(data)                                  (0x000F0000&((data)<<16))
#define SIC_M_GIR9_m_gpioq_irs(data)                                  (0x0000F000&((data)<<12))
#define SIC_M_GIR9_m_gpior_irs(data)                                  (0x00000F00&((data)<<8))
#define SIC_M_GIR9_m_gpios_irs(data)                                  (0x000000F0&((data)<<4))
#define SIC_M_GIR9_m_gpiot_irs(data)                                  (0x0000000F&(data))
#define SIC_M_GIR9_get_m_gpiok_irs(data)                              ((0xF0000000&(data))>>28)
#define SIC_M_GIR9_get_m_gpiom_irs(data)                              ((0x0F000000&(data))>>24)
#define SIC_M_GIR9_get_m_gpion_irs(data)                              ((0x00F00000&(data))>>20)
#define SIC_M_GIR9_get_m_gpiop_irs(data)                              ((0x000F0000&(data))>>16)
#define SIC_M_GIR9_get_m_gpioq_irs(data)                              ((0x0000F000&(data))>>12)
#define SIC_M_GIR9_get_m_gpior_irs(data)                              ((0x00000F00&(data))>>8)
#define SIC_M_GIR9_get_m_gpios_irs(data)                              ((0x000000F0&(data))>>4)
#define SIC_M_GIR9_get_m_gpiot_irs(data)                              (0x0000000F&(data))


#define SIC_M_GIR10                                                   0x18003228
#define SIC_M_GIR10_reg_addr                                          "0xb8003228"
#define SIC_M_GIR10_reg                                               0xb8003228
#define SIC_M_GIR10_inst_addr                                         "0x008A"
#define SIC_M_GIR10_inst                                              0x008A
#define SIC_M_GIR10_m_gpiou_irs_shift                                 (28)
#define SIC_M_GIR10_m_gpiov_irs_shift                                 (24)
#define SIC_M_GIR10_m_sc_irs_shift                                    (12)
#define SIC_M_GIR10_m_pcmcia_irs_shift                                (8)
#define SIC_M_GIR10_m_etn_irs_shift                                   (4)
#define SIC_M_GIR10_m_usb_irs_shift                                   (0)
#define SIC_M_GIR10_m_gpiou_irs_mask                                  (0xF0000000)
#define SIC_M_GIR10_m_gpiov_irs_mask                                  (0x0F000000)
#define SIC_M_GIR10_m_sc_irs_mask                                     (0x0000F000)
#define SIC_M_GIR10_m_pcmcia_irs_mask                                 (0x00000F00)
#define SIC_M_GIR10_m_etn_irs_mask                                    (0x000000F0)
#define SIC_M_GIR10_m_usb_irs_mask                                    (0x0000000F)
#define SIC_M_GIR10_m_gpiou_irs(data)                                 (0xF0000000&((data)<<28))
#define SIC_M_GIR10_m_gpiov_irs(data)                                 (0x0F000000&((data)<<24))
#define SIC_M_GIR10_m_sc_irs(data)                                    (0x0000F000&((data)<<12))
#define SIC_M_GIR10_m_pcmcia_irs(data)                                (0x00000F00&((data)<<8))
#define SIC_M_GIR10_m_etn_irs(data)                                   (0x000000F0&((data)<<4))
#define SIC_M_GIR10_m_usb_irs(data)                                   (0x0000000F&(data))
#define SIC_M_GIR10_get_m_gpiou_irs(data)                             ((0xF0000000&(data))>>28)
#define SIC_M_GIR10_get_m_gpiov_irs(data)                             ((0x0F000000&(data))>>24)
#define SIC_M_GIR10_get_m_sc_irs(data)                                ((0x0000F000&(data))>>12)
#define SIC_M_GIR10_get_m_pcmcia_irs(data)                            ((0x00000F00&(data))>>8)
#define SIC_M_GIR10_get_m_etn_irs(data)                               ((0x000000F0&(data))>>4)
#define SIC_M_GIR10_get_m_usb_irs(data)                               (0x0000000F&(data))


#define SIC_M_GIR11                                                   0x1800322c
#define SIC_M_GIR11_reg_addr                                          "0xb800322c"
#define SIC_M_GIR11_reg                                               0xb800322c
#define SIC_M_GIR11_inst_addr                                         "0x008B"
#define SIC_M_GIR11_inst                                              0x008B
#define SIC_M_GIR11_m_wdog_irs_shift                                  (28)
#define SIC_M_GIR11_m_nf_irs_shift                                    (24)
#define SIC_M_GIR11_m_cr_irs_shift                                    (20)
#define SIC_M_GIR11_m_wdog_irs_mask                                   (0xF0000000)
#define SIC_M_GIR11_m_nf_irs_mask                                     (0x0F000000)
#define SIC_M_GIR11_m_cr_irs_mask                                     (0x00F00000)
#define SIC_M_GIR11_m_wdog_irs(data)                                  (0xF0000000&((data)<<28))
#define SIC_M_GIR11_m_nf_irs(data)                                    (0x0F000000&((data)<<24))
#define SIC_M_GIR11_m_cr_irs(data)                                    (0x00F00000&((data)<<20))
#define SIC_M_GIR11_get_m_wdog_irs(data)                              ((0xF0000000&(data))>>28)
#define SIC_M_GIR11_get_m_nf_irs(data)                                ((0x0F000000&(data))>>24)
#define SIC_M_GIR11_get_m_cr_irs(data)                                ((0x00F00000&(data))>>20)


#define SIC_M_GIE0                                                    0x18003230
#define SIC_M_GIE0_reg_addr                                           "0xb8003230"
#define SIC_M_GIE0_reg                                                0xb8003230
#define SIC_M_GIE0_inst_addr                                          "0x008C"
#define SIC_M_GIE0_inst                                               0x008C
#define SIC_M_GIE0_m_dcu_ie_shift                                     (31)
#define SIC_M_GIE0_m_tvsb_ie_shift                                    (26)
#define SIC_M_GIE0_m_rb_ie_shift                                      (24)
#define SIC_M_GIE0_m_adma_ie_shift                                    (21)
#define SIC_M_GIE0_m_md_ie_shift                                      (18)
#define SIC_M_GIE0_m_cpu_ie_shift                                     (16)
#define SIC_M_GIE0_m_if_demod_ie_shift                                (14)
#define SIC_M_GIE0_m_vd_ie_shift                                      (13)
#define SIC_M_GIE0_m_vbi_ie_shift                                     (12)
#define SIC_M_GIE0_m_aud_ie_shift                                     (11)
#define SIC_M_GIE0_m_hdmi_ie_shift                                    (10)
#define SIC_M_GIE0_m_cec_ie_shift                                     (9)
#define SIC_M_GIE0_m_cp_ie_shift                                      (7)
#define SIC_M_GIE0_m_tp_ie_shift                                      (6)
#define SIC_M_GIE0_m_mpeg_ie_shift                                    (4)
#define SIC_M_GIE0_m_vge_ie_shift                                     (3)
#define SIC_M_GIE0_m_osd_ie_shift                                     (2)
#define SIC_M_GIE0_m_dcu_ie_mask                                      (0x80000000)
#define SIC_M_GIE0_m_tvsb_ie_mask                                     (0x04000000)
#define SIC_M_GIE0_m_rb_ie_mask                                       (0x01000000)
#define SIC_M_GIE0_m_adma_ie_mask                                     (0x00200000)
#define SIC_M_GIE0_m_md_ie_mask                                       (0x00040000)
#define SIC_M_GIE0_m_cpu_ie_mask                                      (0x00010000)
#define SIC_M_GIE0_m_if_demod_ie_mask                                 (0x00004000)
#define SIC_M_GIE0_m_vd_ie_mask                                       (0x00002000)
#define SIC_M_GIE0_m_vbi_ie_mask                                      (0x00001000)
#define SIC_M_GIE0_m_aud_ie_mask                                      (0x00000800)
#define SIC_M_GIE0_m_hdmi_ie_mask                                     (0x00000400)
#define SIC_M_GIE0_m_cec_ie_mask                                      (0x00000200)
#define SIC_M_GIE0_m_cp_ie_mask                                       (0x00000080)
#define SIC_M_GIE0_m_tp_ie_mask                                       (0x00000040)
#define SIC_M_GIE0_m_mpeg_ie_mask                                     (0x00000010)
#define SIC_M_GIE0_m_vge_ie_mask                                      (0x00000008)
#define SIC_M_GIE0_m_osd_ie_mask                                      (0x00000004)
#define SIC_M_GIE0_m_dcu_ie(data)                                     (0x80000000&((data)<<31))
#define SIC_M_GIE0_m_tvsb_ie(data)                                    (0x04000000&((data)<<26))
#define SIC_M_GIE0_m_rb_ie(data)                                      (0x01000000&((data)<<24))
#define SIC_M_GIE0_m_adma_ie(data)                                    (0x00200000&((data)<<21))
#define SIC_M_GIE0_m_md_ie(data)                                      (0x00040000&((data)<<18))
#define SIC_M_GIE0_m_cpu_ie(data)                                     (0x00010000&((data)<<16))
#define SIC_M_GIE0_m_if_demod_ie(data)                                (0x00004000&((data)<<14))
#define SIC_M_GIE0_m_vd_ie(data)                                      (0x00002000&((data)<<13))
#define SIC_M_GIE0_m_vbi_ie(data)                                     (0x00001000&((data)<<12))
#define SIC_M_GIE0_m_aud_ie(data)                                     (0x00000800&((data)<<11))
#define SIC_M_GIE0_m_hdmi_ie(data)                                    (0x00000400&((data)<<10))
#define SIC_M_GIE0_m_cec_ie(data)                                     (0x00000200&((data)<<9))
#define SIC_M_GIE0_m_cp_ie(data)                                      (0x00000080&((data)<<7))
#define SIC_M_GIE0_m_tp_ie(data)                                      (0x00000040&((data)<<6))
#define SIC_M_GIE0_m_mpeg_ie(data)                                    (0x00000010&((data)<<4))
#define SIC_M_GIE0_m_vge_ie(data)                                     (0x00000008&((data)<<3))
#define SIC_M_GIE0_m_osd_ie(data)                                     (0x00000004&((data)<<2))
#define SIC_M_GIE0_get_m_dcu_ie(data)                                 ((0x80000000&(data))>>31)
#define SIC_M_GIE0_get_m_tvsb_ie(data)                                ((0x04000000&(data))>>26)
#define SIC_M_GIE0_get_m_rb_ie(data)                                  ((0x01000000&(data))>>24)
#define SIC_M_GIE0_get_m_adma_ie(data)                                ((0x00200000&(data))>>21)
#define SIC_M_GIE0_get_m_md_ie(data)                                  ((0x00040000&(data))>>18)
#define SIC_M_GIE0_get_m_cpu_ie(data)                                 ((0x00010000&(data))>>16)
#define SIC_M_GIE0_get_m_if_demod_ie(data)                            ((0x00004000&(data))>>14)
#define SIC_M_GIE0_get_m_vd_ie(data)                                  ((0x00002000&(data))>>13)
#define SIC_M_GIE0_get_m_vbi_ie(data)                                 ((0x00001000&(data))>>12)
#define SIC_M_GIE0_get_m_aud_ie(data)                                 ((0x00000800&(data))>>11)
#define SIC_M_GIE0_get_m_hdmi_ie(data)                                ((0x00000400&(data))>>10)
#define SIC_M_GIE0_get_m_cec_ie(data)                                 ((0x00000200&(data))>>9)
#define SIC_M_GIE0_get_m_cp_ie(data)                                  ((0x00000080&(data))>>7)
#define SIC_M_GIE0_get_m_tp_ie(data)                                  ((0x00000040&(data))>>6)
#define SIC_M_GIE0_get_m_mpeg_ie(data)                                ((0x00000010&(data))>>4)
#define SIC_M_GIE0_get_m_vge_ie(data)                                 ((0x00000008&(data))>>3)
#define SIC_M_GIE0_get_m_osd_ie(data)                                 ((0x00000004&(data))>>2)


#define SIC_M_GIE1                                                    0x18003234
#define SIC_M_GIE1_reg_addr                                           "0xb8003234"
#define SIC_M_GIE1_reg                                                0xb8003234
#define SIC_M_GIE1_inst_addr                                          "0x008D"
#define SIC_M_GIE1_inst                                               0x008D
#define SIC_M_GIE1_m_apll_ie_shift                                    (31)
#define SIC_M_GIE1_m_vodma_ie_shift                                   (30)
#define SIC_M_GIE1_m_dct_ie_shift                                     (29)
#define SIC_M_GIE1_m_uz_ie_shift                                      (28)
#define SIC_M_GIE1_m_idomain_ie_shift                                 (26)
#define SIC_M_GIE1_m_mdomain_ie_shift                                 (25)
#define SIC_M_GIE1_m_timer7_ie_shift                                  (23)
#define SIC_M_GIE1_m_timer6_ie_shift                                  (22)
#define SIC_M_GIE1_m_timer5_ie_shift                                  (21)
#define SIC_M_GIE1_m_timer4_ie_shift                                  (20)
#define SIC_M_GIE1_m_timer3_ie_shift                                  (19)
#define SIC_M_GIE1_m_timer2_ie_shift                                  (18)
#define SIC_M_GIE1_m_timer1_ie_shift                                  (17)
#define SIC_M_GIE1_m_timer0_ie_shift                                  (16)
#define SIC_M_GIE1_m_uart_0_ie_shift                                  (15)
#define SIC_M_GIE1_m_uart_1_ie_shift                                  (14)
#define SIC_M_GIE1_m_uart_2_ie_shift                                  (13)
#define SIC_M_GIE1_m_lsadc_ie_shift                                   (11)
#define SIC_M_GIE1_m_rtc_ie_shift                                     (10)
#define SIC_M_GIE1_m_irda_ie_shift                                    (7)
#define SIC_M_GIE1_m_i2c_0_ie_shift                                   (6)
#define SIC_M_GIE1_m_i2c_1_ie_shift                                   (5)
#define SIC_M_GIE1_m_ddc0_ie_shift                                    (3)
#define SIC_M_GIE1_m_ddc1_ie_shift                                    (2)
#define SIC_M_GIE1_m_ddc2_ie_shift                                    (1)
#define SIC_M_GIE1_m_ddc3_ie_shift                                    (0)
#define SIC_M_GIE1_m_apll_ie_mask                                     (0x80000000)
#define SIC_M_GIE1_m_vodma_ie_mask                                    (0x40000000)
#define SIC_M_GIE1_m_dct_ie_mask                                      (0x20000000)
#define SIC_M_GIE1_m_uz_ie_mask                                       (0x10000000)
#define SIC_M_GIE1_m_idomain_ie_mask                                  (0x04000000)
#define SIC_M_GIE1_m_mdomain_ie_mask                                  (0x02000000)
#define SIC_M_GIE1_m_timer7_ie_mask                                   (0x00800000)
#define SIC_M_GIE1_m_timer6_ie_mask                                   (0x00400000)
#define SIC_M_GIE1_m_timer5_ie_mask                                   (0x00200000)
#define SIC_M_GIE1_m_timer4_ie_mask                                   (0x00100000)
#define SIC_M_GIE1_m_timer3_ie_mask                                   (0x00080000)
#define SIC_M_GIE1_m_timer2_ie_mask                                   (0x00040000)
#define SIC_M_GIE1_m_timer1_ie_mask                                   (0x00020000)
#define SIC_M_GIE1_m_timer0_ie_mask                                   (0x00010000)
#define SIC_M_GIE1_m_uart_0_ie_mask                                   (0x00008000)
#define SIC_M_GIE1_m_uart_1_ie_mask                                   (0x00004000)
#define SIC_M_GIE1_m_uart_2_ie_mask                                   (0x00002000)
#define SIC_M_GIE1_m_lsadc_ie_mask                                    (0x00000800)
#define SIC_M_GIE1_m_rtc_ie_mask                                      (0x00000400)
#define SIC_M_GIE1_m_irda_ie_mask                                     (0x00000080)
#define SIC_M_GIE1_m_i2c_0_ie_mask                                    (0x00000040)
#define SIC_M_GIE1_m_i2c_1_ie_mask                                    (0x00000020)
#define SIC_M_GIE1_m_ddc0_ie_mask                                     (0x00000008)
#define SIC_M_GIE1_m_ddc1_ie_mask                                     (0x00000004)
#define SIC_M_GIE1_m_ddc2_ie_mask                                     (0x00000002)
#define SIC_M_GIE1_m_ddc3_ie_mask                                     (0x00000001)
#define SIC_M_GIE1_m_apll_ie(data)                                    (0x80000000&((data)<<31))
#define SIC_M_GIE1_m_vodma_ie(data)                                   (0x40000000&((data)<<30))
#define SIC_M_GIE1_m_dct_ie(data)                                     (0x20000000&((data)<<29))
#define SIC_M_GIE1_m_uz_ie(data)                                      (0x10000000&((data)<<28))
#define SIC_M_GIE1_m_idomain_ie(data)                                 (0x04000000&((data)<<26))
#define SIC_M_GIE1_m_mdomain_ie(data)                                 (0x02000000&((data)<<25))
#define SIC_M_GIE1_m_timer7_ie(data)                                  (0x00800000&((data)<<23))
#define SIC_M_GIE1_m_timer6_ie(data)                                  (0x00400000&((data)<<22))
#define SIC_M_GIE1_m_timer5_ie(data)                                  (0x00200000&((data)<<21))
#define SIC_M_GIE1_m_timer4_ie(data)                                  (0x00100000&((data)<<20))
#define SIC_M_GIE1_m_timer3_ie(data)                                  (0x00080000&((data)<<19))
#define SIC_M_GIE1_m_timer2_ie(data)                                  (0x00040000&((data)<<18))
#define SIC_M_GIE1_m_timer1_ie(data)                                  (0x00020000&((data)<<17))
#define SIC_M_GIE1_m_timer0_ie(data)                                  (0x00010000&((data)<<16))
#define SIC_M_GIE1_m_uart_0_ie(data)                                  (0x00008000&((data)<<15))
#define SIC_M_GIE1_m_uart_1_ie(data)                                  (0x00004000&((data)<<14))
#define SIC_M_GIE1_m_uart_2_ie(data)                                  (0x00002000&((data)<<13))
#define SIC_M_GIE1_m_lsadc_ie(data)                                   (0x00000800&((data)<<11))
#define SIC_M_GIE1_m_rtc_ie(data)                                     (0x00000400&((data)<<10))
#define SIC_M_GIE1_m_irda_ie(data)                                    (0x00000080&((data)<<7))
#define SIC_M_GIE1_m_i2c_0_ie(data)                                   (0x00000040&((data)<<6))
#define SIC_M_GIE1_m_i2c_1_ie(data)                                   (0x00000020&((data)<<5))
#define SIC_M_GIE1_m_ddc0_ie(data)                                    (0x00000008&((data)<<3))
#define SIC_M_GIE1_m_ddc1_ie(data)                                    (0x00000004&((data)<<2))
#define SIC_M_GIE1_m_ddc2_ie(data)                                    (0x00000002&((data)<<1))
#define SIC_M_GIE1_m_ddc3_ie(data)                                    (0x00000001&(data))
#define SIC_M_GIE1_get_m_apll_ie(data)                                ((0x80000000&(data))>>31)
#define SIC_M_GIE1_get_m_vodma_ie(data)                               ((0x40000000&(data))>>30)
#define SIC_M_GIE1_get_m_dct_ie(data)                                 ((0x20000000&(data))>>29)
#define SIC_M_GIE1_get_m_uz_ie(data)                                  ((0x10000000&(data))>>28)
#define SIC_M_GIE1_get_m_idomain_ie(data)                             ((0x04000000&(data))>>26)
#define SIC_M_GIE1_get_m_mdomain_ie(data)                             ((0x02000000&(data))>>25)
#define SIC_M_GIE1_get_m_timer7_ie(data)                              ((0x00800000&(data))>>23)
#define SIC_M_GIE1_get_m_timer6_ie(data)                              ((0x00400000&(data))>>22)
#define SIC_M_GIE1_get_m_timer5_ie(data)                              ((0x00200000&(data))>>21)
#define SIC_M_GIE1_get_m_timer4_ie(data)                              ((0x00100000&(data))>>20)
#define SIC_M_GIE1_get_m_timer3_ie(data)                              ((0x00080000&(data))>>19)
#define SIC_M_GIE1_get_m_timer2_ie(data)                              ((0x00040000&(data))>>18)
#define SIC_M_GIE1_get_m_timer1_ie(data)                              ((0x00020000&(data))>>17)
#define SIC_M_GIE1_get_m_timer0_ie(data)                              ((0x00010000&(data))>>16)
#define SIC_M_GIE1_get_m_uart_0_ie(data)                              ((0x00008000&(data))>>15)
#define SIC_M_GIE1_get_m_uart_1_ie(data)                              ((0x00004000&(data))>>14)
#define SIC_M_GIE1_get_m_uart_2_ie(data)                              ((0x00002000&(data))>>13)
#define SIC_M_GIE1_get_m_lsadc_ie(data)                               ((0x00000800&(data))>>11)
#define SIC_M_GIE1_get_m_rtc_ie(data)                                 ((0x00000400&(data))>>10)
#define SIC_M_GIE1_get_m_irda_ie(data)                                ((0x00000080&(data))>>7)
#define SIC_M_GIE1_get_m_i2c_0_ie(data)                               ((0x00000040&(data))>>6)
#define SIC_M_GIE1_get_m_i2c_1_ie(data)                               ((0x00000020&(data))>>5)
#define SIC_M_GIE1_get_m_ddc0_ie(data)                                ((0x00000008&(data))>>3)
#define SIC_M_GIE1_get_m_ddc1_ie(data)                                ((0x00000004&(data))>>2)
#define SIC_M_GIE1_get_m_ddc2_ie(data)                                ((0x00000002&(data))>>1)
#define SIC_M_GIE1_get_m_ddc3_ie(data)                                (0x00000001&(data))


#define SIC_M_GIE2                                                    0x18003238
#define SIC_M_GIE2_reg_addr                                           "0xb8003238"
#define SIC_M_GIE2_reg                                                0xb8003238
#define SIC_M_GIE2_inst_addr                                          "0x008E"
#define SIC_M_GIE2_inst                                               0x008E
#define SIC_M_GIE2_m_gpioa_ie_shift                                   (31)
#define SIC_M_GIE2_m_gpiob_ie_shift                                   (30)
#define SIC_M_GIE2_m_gpioc_ie_shift                                   (29)
#define SIC_M_GIE2_m_gpiod_ie_shift                                   (28)
#define SIC_M_GIE2_m_gpioe_ie_shift                                   (27)
#define SIC_M_GIE2_m_gpiof_ie_shift                                   (26)
#define SIC_M_GIE2_m_gpiog_ie_shift                                   (25)
#define SIC_M_GIE2_m_gpioh_ie_shift                                   (24)
#define SIC_M_GIE2_m_gpiok_ie_shift                                   (23)
#define SIC_M_GIE2_m_gpiom_ie_shift                                   (22)
#define SIC_M_GIE2_m_gpion_ie_shift                                   (21)
#define SIC_M_GIE2_m_gpiop_ie_shift                                   (20)
#define SIC_M_GIE2_m_gpioq_ie_shift                                   (19)
#define SIC_M_GIE2_m_gpior_ie_shift                                   (18)
#define SIC_M_GIE2_m_gpios_ie_shift                                   (17)
#define SIC_M_GIE2_m_gpiot_ie_shift                                   (16)
#define SIC_M_GIE2_m_gpiou_ie_shift                                   (15)
#define SIC_M_GIE2_m_gpiov_ie_shift                                   (14)
#define SIC_M_GIE2_m_sc_ie_shift                                      (13)
#define SIC_M_GIE2_m_pcmcia_ie_shift                                  (12)
#define SIC_M_GIE2_m_etn_ie_shift                                     (11)
#define SIC_M_GIE2_m_usb_ie_shift                                     (10)
#define SIC_M_GIE2_m_wdog_ie_shift                                    (9)
#define SIC_M_GIE2_m_nf_ie_shift                                      (8)
#define SIC_M_GIE2_m_cr_ie_shift                                      (7)
#define SIC_M_GIE2_m_gpioa_ie_mask                                    (0x80000000)
#define SIC_M_GIE2_m_gpiob_ie_mask                                    (0x40000000)
#define SIC_M_GIE2_m_gpioc_ie_mask                                    (0x20000000)
#define SIC_M_GIE2_m_gpiod_ie_mask                                    (0x10000000)
#define SIC_M_GIE2_m_gpioe_ie_mask                                    (0x08000000)
#define SIC_M_GIE2_m_gpiof_ie_mask                                    (0x04000000)
#define SIC_M_GIE2_m_gpiog_ie_mask                                    (0x02000000)
#define SIC_M_GIE2_m_gpioh_ie_mask                                    (0x01000000)
#define SIC_M_GIE2_m_gpiok_ie_mask                                    (0x00800000)
#define SIC_M_GIE2_m_gpiom_ie_mask                                    (0x00400000)
#define SIC_M_GIE2_m_gpion_ie_mask                                    (0x00200000)
#define SIC_M_GIE2_m_gpiop_ie_mask                                    (0x00100000)
#define SIC_M_GIE2_m_gpioq_ie_mask                                    (0x00080000)
#define SIC_M_GIE2_m_gpior_ie_mask                                    (0x00040000)
#define SIC_M_GIE2_m_gpios_ie_mask                                    (0x00020000)
#define SIC_M_GIE2_m_gpiot_ie_mask                                    (0x00010000)
#define SIC_M_GIE2_m_gpiou_ie_mask                                    (0x00008000)
#define SIC_M_GIE2_m_gpiov_ie_mask                                    (0x00004000)
#define SIC_M_GIE2_m_sc_ie_mask                                       (0x00002000)
#define SIC_M_GIE2_m_pcmcia_ie_mask                                   (0x00001000)
#define SIC_M_GIE2_m_etn_ie_mask                                      (0x00000800)
#define SIC_M_GIE2_m_usb_ie_mask                                      (0x00000400)
#define SIC_M_GIE2_m_wdog_ie_mask                                     (0x00000200)
#define SIC_M_GIE2_m_nf_ie_mask                                       (0x00000100)
#define SIC_M_GIE2_m_cr_ie_mask                                       (0x00000080)
#define SIC_M_GIE2_m_gpioa_ie(data)                                   (0x80000000&((data)<<31))
#define SIC_M_GIE2_m_gpiob_ie(data)                                   (0x40000000&((data)<<30))
#define SIC_M_GIE2_m_gpioc_ie(data)                                   (0x20000000&((data)<<29))
#define SIC_M_GIE2_m_gpiod_ie(data)                                   (0x10000000&((data)<<28))
#define SIC_M_GIE2_m_gpioe_ie(data)                                   (0x08000000&((data)<<27))
#define SIC_M_GIE2_m_gpiof_ie(data)                                   (0x04000000&((data)<<26))
#define SIC_M_GIE2_m_gpiog_ie(data)                                   (0x02000000&((data)<<25))
#define SIC_M_GIE2_m_gpioh_ie(data)                                   (0x01000000&((data)<<24))
#define SIC_M_GIE2_m_gpiok_ie(data)                                   (0x00800000&((data)<<23))
#define SIC_M_GIE2_m_gpiom_ie(data)                                   (0x00400000&((data)<<22))
#define SIC_M_GIE2_m_gpion_ie(data)                                   (0x00200000&((data)<<21))
#define SIC_M_GIE2_m_gpiop_ie(data)                                   (0x00100000&((data)<<20))
#define SIC_M_GIE2_m_gpioq_ie(data)                                   (0x00080000&((data)<<19))
#define SIC_M_GIE2_m_gpior_ie(data)                                   (0x00040000&((data)<<18))
#define SIC_M_GIE2_m_gpios_ie(data)                                   (0x00020000&((data)<<17))
#define SIC_M_GIE2_m_gpiot_ie(data)                                   (0x00010000&((data)<<16))
#define SIC_M_GIE2_m_gpiou_ie(data)                                   (0x00008000&((data)<<15))
#define SIC_M_GIE2_m_gpiov_ie(data)                                   (0x00004000&((data)<<14))
#define SIC_M_GIE2_m_sc_ie(data)                                      (0x00002000&((data)<<13))
#define SIC_M_GIE2_m_pcmcia_ie(data)                                  (0x00001000&((data)<<12))
#define SIC_M_GIE2_m_etn_ie(data)                                     (0x00000800&((data)<<11))
#define SIC_M_GIE2_m_usb_ie(data)                                     (0x00000400&((data)<<10))
#define SIC_M_GIE2_m_wdog_ie(data)                                    (0x00000200&((data)<<9))
#define SIC_M_GIE2_m_nf_ie(data)                                      (0x00000100&((data)<<8))
#define SIC_M_GIE2_m_cr_ie(data)                                      (0x00000080&((data)<<7))
#define SIC_M_GIE2_get_m_gpioa_ie(data)                               ((0x80000000&(data))>>31)
#define SIC_M_GIE2_get_m_gpiob_ie(data)                               ((0x40000000&(data))>>30)
#define SIC_M_GIE2_get_m_gpioc_ie(data)                               ((0x20000000&(data))>>29)
#define SIC_M_GIE2_get_m_gpiod_ie(data)                               ((0x10000000&(data))>>28)
#define SIC_M_GIE2_get_m_gpioe_ie(data)                               ((0x08000000&(data))>>27)
#define SIC_M_GIE2_get_m_gpiof_ie(data)                               ((0x04000000&(data))>>26)
#define SIC_M_GIE2_get_m_gpiog_ie(data)                               ((0x02000000&(data))>>25)
#define SIC_M_GIE2_get_m_gpioh_ie(data)                               ((0x01000000&(data))>>24)
#define SIC_M_GIE2_get_m_gpiok_ie(data)                               ((0x00800000&(data))>>23)
#define SIC_M_GIE2_get_m_gpiom_ie(data)                               ((0x00400000&(data))>>22)
#define SIC_M_GIE2_get_m_gpion_ie(data)                               ((0x00200000&(data))>>21)
#define SIC_M_GIE2_get_m_gpiop_ie(data)                               ((0x00100000&(data))>>20)
#define SIC_M_GIE2_get_m_gpioq_ie(data)                               ((0x00080000&(data))>>19)
#define SIC_M_GIE2_get_m_gpior_ie(data)                               ((0x00040000&(data))>>18)
#define SIC_M_GIE2_get_m_gpios_ie(data)                               ((0x00020000&(data))>>17)
#define SIC_M_GIE2_get_m_gpiot_ie(data)                               ((0x00010000&(data))>>16)
#define SIC_M_GIE2_get_m_gpiou_ie(data)                               ((0x00008000&(data))>>15)
#define SIC_M_GIE2_get_m_gpiov_ie(data)                               ((0x00004000&(data))>>14)
#define SIC_M_GIE2_get_m_sc_ie(data)                                  ((0x00002000&(data))>>13)
#define SIC_M_GIE2_get_m_pcmcia_ie(data)                              ((0x00001000&(data))>>12)
#define SIC_M_GIE2_get_m_etn_ie(data)                                 ((0x00000800&(data))>>11)
#define SIC_M_GIE2_get_m_usb_ie(data)                                 ((0x00000400&(data))>>10)
#define SIC_M_GIE2_get_m_wdog_ie(data)                                ((0x00000200&(data))>>9)
#define SIC_M_GIE2_get_m_nf_ie(data)                                  ((0x00000100&(data))>>8)
#define SIC_M_GIE2_get_m_cr_ie(data)                                  ((0x00000080&(data))>>7)


#define SIC_M_GIP0                                                    0x18003240
#define SIC_M_GIP0_reg_addr                                           "0xb8003240"
#define SIC_M_GIP0_reg                                                0xb8003240
#define SIC_M_GIP0_inst_addr                                          "0x0090"
#define SIC_M_GIP0_inst                                               0x0090
#define SIC_M_GIP0_m_dcu_ip_shift                                     (31)
#define SIC_M_GIP0_m_tvsb_ip_shift                                    (26)
#define SIC_M_GIP0_m_rb_ip_shift                                      (24)
#define SIC_M_GIP0_m_adma_ip_shift                                    (21)
#define SIC_M_GIP0_m_md_ip_shift                                      (18)
#define SIC_M_GIP0_m_cpu_ip_shift                                     (16)
#define SIC_M_GIP0_m_if_demod_ip_shift                                (14)
#define SIC_M_GIP0_m_vd_ip_shift                                      (13)
#define SIC_M_GIP0_m_vbi_ip_shift                                     (12)
#define SIC_M_GIP0_m_aud_ip_shift                                     (11)
#define SIC_M_GIP0_m_hdmi_ip_shift                                    (10)
#define SIC_M_GIP0_m_cec_ip_shift                                     (9)
#define SIC_M_GIP0_m_cp_ip_shift                                      (7)
#define SIC_M_GIP0_m_tp_ip_shift                                      (6)
#define SIC_M_GIP0_m_mpeg_ip_shift                                    (4)
#define SIC_M_GIP0_m_vge_ip_shift                                     (3)
#define SIC_M_GIP0_m_osd_ip_shift                                     (2)
#define SIC_M_GIP0_m_dcu_ip_mask                                      (0x80000000)
#define SIC_M_GIP0_m_tvsb_ip_mask                                     (0x04000000)
#define SIC_M_GIP0_m_rb_ip_mask                                       (0x01000000)
#define SIC_M_GIP0_m_adma_ip_mask                                     (0x00200000)
#define SIC_M_GIP0_m_md_ip_mask                                       (0x00040000)
#define SIC_M_GIP0_m_cpu_ip_mask                                      (0x00010000)
#define SIC_M_GIP0_m_if_demod_ip_mask                                 (0x00004000)
#define SIC_M_GIP0_m_vd_ip_mask                                       (0x00002000)
#define SIC_M_GIP0_m_vbi_ip_mask                                      (0x00001000)
#define SIC_M_GIP0_m_aud_ip_mask                                      (0x00000800)
#define SIC_M_GIP0_m_hdmi_ip_mask                                     (0x00000400)
#define SIC_M_GIP0_m_cec_ip_mask                                      (0x00000200)
#define SIC_M_GIP0_m_cp_ip_mask                                       (0x00000080)
#define SIC_M_GIP0_m_tp_ip_mask                                       (0x00000040)
#define SIC_M_GIP0_m_mpeg_ip_mask                                     (0x00000010)
#define SIC_M_GIP0_m_vge_ip_mask                                      (0x00000008)
#define SIC_M_GIP0_m_osd_ip_mask                                      (0x00000004)
#define SIC_M_GIP0_m_dcu_ip(data)                                     (0x80000000&((data)<<31))
#define SIC_M_GIP0_m_tvsb_ip(data)                                    (0x04000000&((data)<<26))
#define SIC_M_GIP0_m_rb_ip(data)                                      (0x01000000&((data)<<24))
#define SIC_M_GIP0_m_adma_ip(data)                                    (0x00200000&((data)<<21))
#define SIC_M_GIP0_m_md_ip(data)                                      (0x00040000&((data)<<18))
#define SIC_M_GIP0_m_cpu_ip(data)                                     (0x00010000&((data)<<16))
#define SIC_M_GIP0_m_if_demod_ip(data)                                (0x00004000&((data)<<14))
#define SIC_M_GIP0_m_vd_ip(data)                                      (0x00002000&((data)<<13))
#define SIC_M_GIP0_m_vbi_ip(data)                                     (0x00001000&((data)<<12))
#define SIC_M_GIP0_m_aud_ip(data)                                     (0x00000800&((data)<<11))
#define SIC_M_GIP0_m_hdmi_ip(data)                                    (0x00000400&((data)<<10))
#define SIC_M_GIP0_m_cec_ip(data)                                     (0x00000200&((data)<<9))
#define SIC_M_GIP0_m_cp_ip(data)                                      (0x00000080&((data)<<7))
#define SIC_M_GIP0_m_tp_ip(data)                                      (0x00000040&((data)<<6))
#define SIC_M_GIP0_m_mpeg_ip(data)                                    (0x00000010&((data)<<4))
#define SIC_M_GIP0_m_vge_ip(data)                                     (0x00000008&((data)<<3))
#define SIC_M_GIP0_m_osd_ip(data)                                     (0x00000004&((data)<<2))
#define SIC_M_GIP0_get_m_dcu_ip(data)                                 ((0x80000000&(data))>>31)
#define SIC_M_GIP0_get_m_tvsb_ip(data)                                ((0x04000000&(data))>>26)
#define SIC_M_GIP0_get_m_rb_ip(data)                                  ((0x01000000&(data))>>24)
#define SIC_M_GIP0_get_m_adma_ip(data)                                ((0x00200000&(data))>>21)
#define SIC_M_GIP0_get_m_md_ip(data)                                  ((0x00040000&(data))>>18)
#define SIC_M_GIP0_get_m_cpu_ip(data)                                 ((0x00010000&(data))>>16)
#define SIC_M_GIP0_get_m_if_demod_ip(data)                            ((0x00004000&(data))>>14)
#define SIC_M_GIP0_get_m_vd_ip(data)                                  ((0x00002000&(data))>>13)
#define SIC_M_GIP0_get_m_vbi_ip(data)                                 ((0x00001000&(data))>>12)
#define SIC_M_GIP0_get_m_aud_ip(data)                                 ((0x00000800&(data))>>11)
#define SIC_M_GIP0_get_m_hdmi_ip(data)                                ((0x00000400&(data))>>10)
#define SIC_M_GIP0_get_m_cec_ip(data)                                 ((0x00000200&(data))>>9)
#define SIC_M_GIP0_get_m_cp_ip(data)                                  ((0x00000080&(data))>>7)
#define SIC_M_GIP0_get_m_tp_ip(data)                                  ((0x00000040&(data))>>6)
#define SIC_M_GIP0_get_m_mpeg_ip(data)                                ((0x00000010&(data))>>4)
#define SIC_M_GIP0_get_m_vge_ip(data)                                 ((0x00000008&(data))>>3)
#define SIC_M_GIP0_get_m_osd_ip(data)                                 ((0x00000004&(data))>>2)


#define SIC_M_GIP1                                                    0x18003244
#define SIC_M_GIP1_reg_addr                                           "0xb8003244"
#define SIC_M_GIP1_reg                                                0xb8003244
#define SIC_M_GIP1_inst_addr                                          "0x0091"
#define SIC_M_GIP1_inst                                               0x0091
#define SIC_M_GIP1_m_apll_ip_shift                                    (31)
#define SIC_M_GIP1_m_vodma_ip_shift                                   (30)
#define SIC_M_GIP1_m_dct_ip_shift                                     (29)
#define SIC_M_GIP1_m_uz_ip_shift                                      (28)
#define SIC_M_GIP1_m_idomain_ip_shift                                 (26)
#define SIC_M_GIP1_m_mdomain_ip_shift                                 (25)
#define SIC_M_GIP1_m_timer7_ip_shift                                  (23)
#define SIC_M_GIP1_m_timer6_ip_shift                                  (22)
#define SIC_M_GIP1_m_timer5_ip_shift                                  (21)
#define SIC_M_GIP1_m_timer4_ip_shift                                  (20)
#define SIC_M_GIP1_m_timer3_ip_shift                                  (19)
#define SIC_M_GIP1_m_timer2_ip_shift                                  (18)
#define SIC_M_GIP1_m_timer1_ip_shift                                  (17)
#define SIC_M_GIP1_m_timer0_ip_shift                                  (16)
#define SIC_M_GIP1_m_uart_0_ip_shift                                  (15)
#define SIC_M_GIP1_m_uart_1_ip_shift                                  (14)
#define SIC_M_GIP1_m_uart_2_ip_shift                                  (13)
#define SIC_M_GIP1_m_lsadc_ip_shift                                   (11)
#define SIC_M_GIP1_m_rtc_ip_shift                                     (10)
#define SIC_M_GIP1_m_irda_ip_shift                                    (7)
#define SIC_M_GIP1_m_i2c_0_ip_shift                                   (6)
#define SIC_M_GIP1_m_i2c_1_ip_shift                                   (5)
#define SIC_M_GIP1_m_ddc0_ip_shift                                    (3)
#define SIC_M_GIP1_m_ddc1_ip_shift                                    (2)
#define SIC_M_GIP1_m_ddc2_ip_shift                                    (1)
#define SIC_M_GIP1_m_ddc3_ip_shift                                    (0)
#define SIC_M_GIP1_m_apll_ip_mask                                     (0x80000000)
#define SIC_M_GIP1_m_vodma_ip_mask                                    (0x40000000)
#define SIC_M_GIP1_m_dct_ip_mask                                      (0x20000000)
#define SIC_M_GIP1_m_uz_ip_mask                                       (0x10000000)
#define SIC_M_GIP1_m_idomain_ip_mask                                  (0x04000000)
#define SIC_M_GIP1_m_mdomain_ip_mask                                  (0x02000000)
#define SIC_M_GIP1_m_timer7_ip_mask                                   (0x00800000)
#define SIC_M_GIP1_m_timer6_ip_mask                                   (0x00400000)
#define SIC_M_GIP1_m_timer5_ip_mask                                   (0x00200000)
#define SIC_M_GIP1_m_timer4_ip_mask                                   (0x00100000)
#define SIC_M_GIP1_m_timer3_ip_mask                                   (0x00080000)
#define SIC_M_GIP1_m_timer2_ip_mask                                   (0x00040000)
#define SIC_M_GIP1_m_timer1_ip_mask                                   (0x00020000)
#define SIC_M_GIP1_m_timer0_ip_mask                                   (0x00010000)
#define SIC_M_GIP1_m_uart_0_ip_mask                                   (0x00008000)
#define SIC_M_GIP1_m_uart_1_ip_mask                                   (0x00004000)
#define SIC_M_GIP1_m_uart_2_ip_mask                                   (0x00002000)
#define SIC_M_GIP1_m_lsadc_ip_mask                                    (0x00000800)
#define SIC_M_GIP1_m_rtc_ip_mask                                      (0x00000400)
#define SIC_M_GIP1_m_irda_ip_mask                                     (0x00000080)
#define SIC_M_GIP1_m_i2c_0_ip_mask                                    (0x00000040)
#define SIC_M_GIP1_m_i2c_1_ip_mask                                    (0x00000020)
#define SIC_M_GIP1_m_ddc0_ip_mask                                     (0x00000008)
#define SIC_M_GIP1_m_ddc1_ip_mask                                     (0x00000004)
#define SIC_M_GIP1_m_ddc2_ip_mask                                     (0x00000002)
#define SIC_M_GIP1_m_ddc3_ip_mask                                     (0x00000001)
#define SIC_M_GIP1_m_apll_ip(data)                                    (0x80000000&((data)<<31))
#define SIC_M_GIP1_m_vodma_ip(data)                                   (0x40000000&((data)<<30))
#define SIC_M_GIP1_m_dct_ip(data)                                     (0x20000000&((data)<<29))
#define SIC_M_GIP1_m_uz_ip(data)                                      (0x10000000&((data)<<28))
#define SIC_M_GIP1_m_idomain_ip(data)                                 (0x04000000&((data)<<26))
#define SIC_M_GIP1_m_mdomain_ip(data)                                 (0x02000000&((data)<<25))
#define SIC_M_GIP1_m_timer7_ip(data)                                  (0x00800000&((data)<<23))
#define SIC_M_GIP1_m_timer6_ip(data)                                  (0x00400000&((data)<<22))
#define SIC_M_GIP1_m_timer5_ip(data)                                  (0x00200000&((data)<<21))
#define SIC_M_GIP1_m_timer4_ip(data)                                  (0x00100000&((data)<<20))
#define SIC_M_GIP1_m_timer3_ip(data)                                  (0x00080000&((data)<<19))
#define SIC_M_GIP1_m_timer2_ip(data)                                  (0x00040000&((data)<<18))
#define SIC_M_GIP1_m_timer1_ip(data)                                  (0x00020000&((data)<<17))
#define SIC_M_GIP1_m_timer0_ip(data)                                  (0x00010000&((data)<<16))
#define SIC_M_GIP1_m_uart_0_ip(data)                                  (0x00008000&((data)<<15))
#define SIC_M_GIP1_m_uart_1_ip(data)                                  (0x00004000&((data)<<14))
#define SIC_M_GIP1_m_uart_2_ip(data)                                  (0x00002000&((data)<<13))
#define SIC_M_GIP1_m_lsadc_ip(data)                                   (0x00000800&((data)<<11))
#define SIC_M_GIP1_m_rtc_ip(data)                                     (0x00000400&((data)<<10))
#define SIC_M_GIP1_m_irda_ip(data)                                    (0x00000080&((data)<<7))
#define SIC_M_GIP1_m_i2c_0_ip(data)                                   (0x00000040&((data)<<6))
#define SIC_M_GIP1_m_i2c_1_ip(data)                                   (0x00000020&((data)<<5))
#define SIC_M_GIP1_m_ddc0_ip(data)                                    (0x00000008&((data)<<3))
#define SIC_M_GIP1_m_ddc1_ip(data)                                    (0x00000004&((data)<<2))
#define SIC_M_GIP1_m_ddc2_ip(data)                                    (0x00000002&((data)<<1))
#define SIC_M_GIP1_m_ddc3_ip(data)                                    (0x00000001&(data))
#define SIC_M_GIP1_get_m_apll_ip(data)                                ((0x80000000&(data))>>31)
#define SIC_M_GIP1_get_m_vodma_ip(data)                               ((0x40000000&(data))>>30)
#define SIC_M_GIP1_get_m_dct_ip(data)                                 ((0x20000000&(data))>>29)
#define SIC_M_GIP1_get_m_uz_ip(data)                                  ((0x10000000&(data))>>28)
#define SIC_M_GIP1_get_m_idomain_ip(data)                             ((0x04000000&(data))>>26)
#define SIC_M_GIP1_get_m_mdomain_ip(data)                             ((0x02000000&(data))>>25)
#define SIC_M_GIP1_get_m_timer7_ip(data)                              ((0x00800000&(data))>>23)
#define SIC_M_GIP1_get_m_timer6_ip(data)                              ((0x00400000&(data))>>22)
#define SIC_M_GIP1_get_m_timer5_ip(data)                              ((0x00200000&(data))>>21)
#define SIC_M_GIP1_get_m_timer4_ip(data)                              ((0x00100000&(data))>>20)
#define SIC_M_GIP1_get_m_timer3_ip(data)                              ((0x00080000&(data))>>19)
#define SIC_M_GIP1_get_m_timer2_ip(data)                              ((0x00040000&(data))>>18)
#define SIC_M_GIP1_get_m_timer1_ip(data)                              ((0x00020000&(data))>>17)
#define SIC_M_GIP1_get_m_timer0_ip(data)                              ((0x00010000&(data))>>16)
#define SIC_M_GIP1_get_m_uart_0_ip(data)                              ((0x00008000&(data))>>15)
#define SIC_M_GIP1_get_m_uart_1_ip(data)                              ((0x00004000&(data))>>14)
#define SIC_M_GIP1_get_m_uart_2_ip(data)                              ((0x00002000&(data))>>13)
#define SIC_M_GIP1_get_m_lsadc_ip(data)                               ((0x00000800&(data))>>11)
#define SIC_M_GIP1_get_m_rtc_ip(data)                                 ((0x00000400&(data))>>10)
#define SIC_M_GIP1_get_m_irda_ip(data)                                ((0x00000080&(data))>>7)
#define SIC_M_GIP1_get_m_i2c_0_ip(data)                               ((0x00000040&(data))>>6)
#define SIC_M_GIP1_get_m_i2c_1_ip(data)                               ((0x00000020&(data))>>5)
#define SIC_M_GIP1_get_m_ddc0_ip(data)                                ((0x00000008&(data))>>3)
#define SIC_M_GIP1_get_m_ddc1_ip(data)                                ((0x00000004&(data))>>2)
#define SIC_M_GIP1_get_m_ddc2_ip(data)                                ((0x00000002&(data))>>1)
#define SIC_M_GIP1_get_m_ddc3_ip(data)                                (0x00000001&(data))


#define SIC_M_GIP2                                                    0x18003248
#define SIC_M_GIP2_reg_addr                                           "0xb8003248"
#define SIC_M_GIP2_reg                                                0xb8003248
#define SIC_M_GIP2_inst_addr                                          "0x0092"
#define SIC_M_GIP2_inst                                               0x0092
#define SIC_M_GIP2_m_gpioa_ip_shift                                   (31)
#define SIC_M_GIP2_m_gpiob_ip_shift                                   (30)
#define SIC_M_GIP2_m_gpioc_ip_shift                                   (29)
#define SIC_M_GIP2_m_gpiod_ip_shift                                   (28)
#define SIC_M_GIP2_m_gpioe_ip_shift                                   (27)
#define SIC_M_GIP2_m_gpiof_ip_shift                                   (26)
#define SIC_M_GIP2_m_gpiog_ip_shift                                   (25)
#define SIC_M_GIP2_m_gpioh_ip_shift                                   (24)
#define SIC_M_GIP2_m_gpiok_ip_shift                                   (23)
#define SIC_M_GIP2_m_gpiom_ip_shift                                   (22)
#define SIC_M_GIP2_m_gpion_ip_shift                                   (21)
#define SIC_M_GIP2_m_gpiop_ip_shift                                   (20)
#define SIC_M_GIP2_m_gpioq_ip_shift                                   (19)
#define SIC_M_GIP2_m_gpior_ip_shift                                   (18)
#define SIC_M_GIP2_m_gpios_ip_shift                                   (17)
#define SIC_M_GIP2_m_gpiot_ip_shift                                   (16)
#define SIC_M_GIP2_m_gpiou_ip_shift                                   (15)
#define SIC_M_GIP2_m_gpiov_ip_shift                                   (14)
#define SIC_M_GIP2_m_sc_ip_shift                                      (13)
#define SIC_M_GIP2_m_pcmcia_ip_shift                                  (12)
#define SIC_M_GIP2_m_etn_ip_shift                                     (11)
#define SIC_M_GIP2_m_usb_ip_shift                                     (10)
#define SIC_M_GIP2_m_wdog_ip_shift                                    (9)
#define SIC_M_GIP2_m_nf_ip_shift                                      (8)
#define SIC_M_GIP2_m_cr_ip_shift                                      (7)
#define SIC_M_GIP2_m_gpioa_ip_mask                                    (0x80000000)
#define SIC_M_GIP2_m_gpiob_ip_mask                                    (0x40000000)
#define SIC_M_GIP2_m_gpioc_ip_mask                                    (0x20000000)
#define SIC_M_GIP2_m_gpiod_ip_mask                                    (0x10000000)
#define SIC_M_GIP2_m_gpioe_ip_mask                                    (0x08000000)
#define SIC_M_GIP2_m_gpiof_ip_mask                                    (0x04000000)
#define SIC_M_GIP2_m_gpiog_ip_mask                                    (0x02000000)
#define SIC_M_GIP2_m_gpioh_ip_mask                                    (0x01000000)
#define SIC_M_GIP2_m_gpiok_ip_mask                                    (0x00800000)
#define SIC_M_GIP2_m_gpiom_ip_mask                                    (0x00400000)
#define SIC_M_GIP2_m_gpion_ip_mask                                    (0x00200000)
#define SIC_M_GIP2_m_gpiop_ip_mask                                    (0x00100000)
#define SIC_M_GIP2_m_gpioq_ip_mask                                    (0x00080000)
#define SIC_M_GIP2_m_gpior_ip_mask                                    (0x00040000)
#define SIC_M_GIP2_m_gpios_ip_mask                                    (0x00020000)
#define SIC_M_GIP2_m_gpiot_ip_mask                                    (0x00010000)
#define SIC_M_GIP2_m_gpiou_ip_mask                                    (0x00008000)
#define SIC_M_GIP2_m_gpiov_ip_mask                                    (0x00004000)
#define SIC_M_GIP2_m_sc_ip_mask                                       (0x00002000)
#define SIC_M_GIP2_m_pcmcia_ip_mask                                   (0x00001000)
#define SIC_M_GIP2_m_etn_ip_mask                                      (0x00000800)
#define SIC_M_GIP2_m_usb_ip_mask                                      (0x00000400)
#define SIC_M_GIP2_m_wdog_ip_mask                                     (0x00000200)
#define SIC_M_GIP2_m_nf_ip_mask                                       (0x00000100)
#define SIC_M_GIP2_m_cr_ip_mask                                       (0x00000080)
#define SIC_M_GIP2_m_gpioa_ip(data)                                   (0x80000000&((data)<<31))
#define SIC_M_GIP2_m_gpiob_ip(data)                                   (0x40000000&((data)<<30))
#define SIC_M_GIP2_m_gpioc_ip(data)                                   (0x20000000&((data)<<29))
#define SIC_M_GIP2_m_gpiod_ip(data)                                   (0x10000000&((data)<<28))
#define SIC_M_GIP2_m_gpioe_ip(data)                                   (0x08000000&((data)<<27))
#define SIC_M_GIP2_m_gpiof_ip(data)                                   (0x04000000&((data)<<26))
#define SIC_M_GIP2_m_gpiog_ip(data)                                   (0x02000000&((data)<<25))
#define SIC_M_GIP2_m_gpioh_ip(data)                                   (0x01000000&((data)<<24))
#define SIC_M_GIP2_m_gpiok_ip(data)                                   (0x00800000&((data)<<23))
#define SIC_M_GIP2_m_gpiom_ip(data)                                   (0x00400000&((data)<<22))
#define SIC_M_GIP2_m_gpion_ip(data)                                   (0x00200000&((data)<<21))
#define SIC_M_GIP2_m_gpiop_ip(data)                                   (0x00100000&((data)<<20))
#define SIC_M_GIP2_m_gpioq_ip(data)                                   (0x00080000&((data)<<19))
#define SIC_M_GIP2_m_gpior_ip(data)                                   (0x00040000&((data)<<18))
#define SIC_M_GIP2_m_gpios_ip(data)                                   (0x00020000&((data)<<17))
#define SIC_M_GIP2_m_gpiot_ip(data)                                   (0x00010000&((data)<<16))
#define SIC_M_GIP2_m_gpiou_ip(data)                                   (0x00008000&((data)<<15))
#define SIC_M_GIP2_m_gpiov_ip(data)                                   (0x00004000&((data)<<14))
#define SIC_M_GIP2_m_sc_ip(data)                                      (0x00002000&((data)<<13))
#define SIC_M_GIP2_m_pcmcia_ip(data)                                  (0x00001000&((data)<<12))
#define SIC_M_GIP2_m_etn_ip(data)                                     (0x00000800&((data)<<11))
#define SIC_M_GIP2_m_usb_ip(data)                                     (0x00000400&((data)<<10))
#define SIC_M_GIP2_m_wdog_ip(data)                                    (0x00000200&((data)<<9))
#define SIC_M_GIP2_m_nf_ip(data)                                      (0x00000100&((data)<<8))
#define SIC_M_GIP2_m_cr_ip(data)                                      (0x00000080&((data)<<7))
#define SIC_M_GIP2_get_m_gpioa_ip(data)                               ((0x80000000&(data))>>31)
#define SIC_M_GIP2_get_m_gpiob_ip(data)                               ((0x40000000&(data))>>30)
#define SIC_M_GIP2_get_m_gpioc_ip(data)                               ((0x20000000&(data))>>29)
#define SIC_M_GIP2_get_m_gpiod_ip(data)                               ((0x10000000&(data))>>28)
#define SIC_M_GIP2_get_m_gpioe_ip(data)                               ((0x08000000&(data))>>27)
#define SIC_M_GIP2_get_m_gpiof_ip(data)                               ((0x04000000&(data))>>26)
#define SIC_M_GIP2_get_m_gpiog_ip(data)                               ((0x02000000&(data))>>25)
#define SIC_M_GIP2_get_m_gpioh_ip(data)                               ((0x01000000&(data))>>24)
#define SIC_M_GIP2_get_m_gpiok_ip(data)                               ((0x00800000&(data))>>23)
#define SIC_M_GIP2_get_m_gpiom_ip(data)                               ((0x00400000&(data))>>22)
#define SIC_M_GIP2_get_m_gpion_ip(data)                               ((0x00200000&(data))>>21)
#define SIC_M_GIP2_get_m_gpiop_ip(data)                               ((0x00100000&(data))>>20)
#define SIC_M_GIP2_get_m_gpioq_ip(data)                               ((0x00080000&(data))>>19)
#define SIC_M_GIP2_get_m_gpior_ip(data)                               ((0x00040000&(data))>>18)
#define SIC_M_GIP2_get_m_gpios_ip(data)                               ((0x00020000&(data))>>17)
#define SIC_M_GIP2_get_m_gpiot_ip(data)                               ((0x00010000&(data))>>16)
#define SIC_M_GIP2_get_m_gpiou_ip(data)                               ((0x00008000&(data))>>15)
#define SIC_M_GIP2_get_m_gpiov_ip(data)                               ((0x00004000&(data))>>14)
#define SIC_M_GIP2_get_m_sc_ip(data)                                  ((0x00002000&(data))>>13)
#define SIC_M_GIP2_get_m_pcmcia_ip(data)                              ((0x00001000&(data))>>12)
#define SIC_M_GIP2_get_m_etn_ip(data)                                 ((0x00000800&(data))>>11)
#define SIC_M_GIP2_get_m_usb_ip(data)                                 ((0x00000400&(data))>>10)
#define SIC_M_GIP2_get_m_wdog_ip(data)                                ((0x00000200&(data))>>9)
#define SIC_M_GIP2_get_m_nf_ip(data)                                  ((0x00000100&(data))>>8)
#define SIC_M_GIP2_get_m_cr_ip(data)                                  ((0x00000080&(data))>>7)


#define SIC_AV_GIR0                                                   0x18003250
#define SIC_AV_GIR0_reg_addr                                          "0xb8003250"
#define SIC_AV_GIR0_reg                                               0xb8003250
#define SIC_AV_GIR0_inst_addr                                         "0x0094"
#define SIC_AV_GIR0_inst                                              0x0094
#define SIC_AV_GIR0_av_dcu_irs_shift                                  (28)
#define SIC_AV_GIR0_av_tvsb_irs_shift                                 (8)
#define SIC_AV_GIR0_av_rb_irs_shift                                   (0)
#define SIC_AV_GIR0_av_dcu_irs_mask                                   (0xF0000000)
#define SIC_AV_GIR0_av_tvsb_irs_mask                                  (0x00000F00)
#define SIC_AV_GIR0_av_rb_irs_mask                                    (0x0000000F)
#define SIC_AV_GIR0_av_dcu_irs(data)                                  (0xF0000000&((data)<<28))
#define SIC_AV_GIR0_av_tvsb_irs(data)                                 (0x00000F00&((data)<<8))
#define SIC_AV_GIR0_av_rb_irs(data)                                   (0x0000000F&(data))
#define SIC_AV_GIR0_get_av_dcu_irs(data)                              ((0xF0000000&(data))>>28)
#define SIC_AV_GIR0_get_av_tvsb_irs(data)                             ((0x00000F00&(data))>>8)
#define SIC_AV_GIR0_get_av_rb_irs(data)                               (0x0000000F&(data))


#define SIC_AV_GIR1                                                   0x18003254
#define SIC_AV_GIR1_reg_addr                                          "0xb8003254"
#define SIC_AV_GIR1_reg                                               0xb8003254
#define SIC_AV_GIR1_inst_addr                                         "0x0095"
#define SIC_AV_GIR1_inst                                              0x0095
#define SIC_AV_GIR1_av_ae_irs_shift                                   (28)
#define SIC_AV_GIR1_av_cpudma_irs_shift                               (24)
#define SIC_AV_GIR1_av_adma_irs_shift                                 (20)
#define SIC_AV_GIR1_av_md_irs_shift                                   (8)
#define SIC_AV_GIR1_av_cpu_irs_shift                                  (0)
#define SIC_AV_GIR1_av_ae_irs_mask                                    (0xF0000000)
#define SIC_AV_GIR1_av_cpudma_irs_mask                                (0x0F000000)
#define SIC_AV_GIR1_av_adma_irs_mask                                  (0x00F00000)
#define SIC_AV_GIR1_av_md_irs_mask                                    (0x00000F00)
#define SIC_AV_GIR1_av_cpu_irs_mask                                   (0x0000000F)
#define SIC_AV_GIR1_av_ae_irs(data)                                   (0xF0000000&((data)<<28))
#define SIC_AV_GIR1_av_cpudma_irs(data)                               (0x0F000000&((data)<<24))
#define SIC_AV_GIR1_av_adma_irs(data)                                 (0x00F00000&((data)<<20))
#define SIC_AV_GIR1_av_md_irs(data)                                   (0x00000F00&((data)<<8))
#define SIC_AV_GIR1_av_cpu_irs(data)                                  (0x0000000F&(data))
#define SIC_AV_GIR1_get_av_ae_irs(data)                               ((0xF0000000&(data))>>28)
#define SIC_AV_GIR1_get_av_cpudma_irs(data)                           ((0x0F000000&(data))>>24)
#define SIC_AV_GIR1_get_av_adma_irs(data)                             ((0x00F00000&(data))>>20)
#define SIC_AV_GIR1_get_av_md_irs(data)                               ((0x00000F00&(data))>>8)
#define SIC_AV_GIR1_get_av_cpu_irs(data)                              (0x0000000F&(data))


#define SIC_AV_GIR2                                                   0x18003258
#define SIC_AV_GIR2_reg_addr                                          "0xb8003258"
#define SIC_AV_GIR2_reg                                               0xb8003258
#define SIC_AV_GIR2_inst_addr                                         "0x0096"
#define SIC_AV_GIR2_inst                                              0x0096
#define SIC_AV_GIR2_av_if_demod_irs_shift                             (24)
#define SIC_AV_GIR2_av_vd_irs_shift                                   (20)
#define SIC_AV_GIR2_av_vbi_irs_shift                                  (16)
#define SIC_AV_GIR2_av_aud_irs_shift                                  (12)
#define SIC_AV_GIR2_av_hdmi_irs_shift                                 (8)
#define SIC_AV_GIR2_av_cec_irs_shift                                  (4)
#define SIC_AV_GIR2_av_if_demod_irs_mask                              (0x0F000000)
#define SIC_AV_GIR2_av_vd_irs_mask                                    (0x00F00000)
#define SIC_AV_GIR2_av_vbi_irs_mask                                   (0x000F0000)
#define SIC_AV_GIR2_av_aud_irs_mask                                   (0x0000F000)
#define SIC_AV_GIR2_av_hdmi_irs_mask                                  (0x00000F00)
#define SIC_AV_GIR2_av_cec_irs_mask                                   (0x000000F0)
#define SIC_AV_GIR2_av_if_demod_irs(data)                             (0x0F000000&((data)<<24))
#define SIC_AV_GIR2_av_vd_irs(data)                                   (0x00F00000&((data)<<20))
#define SIC_AV_GIR2_av_vbi_irs(data)                                  (0x000F0000&((data)<<16))
#define SIC_AV_GIR2_av_aud_irs(data)                                  (0x0000F000&((data)<<12))
#define SIC_AV_GIR2_av_hdmi_irs(data)                                 (0x00000F00&((data)<<8))
#define SIC_AV_GIR2_av_cec_irs(data)                                  (0x000000F0&((data)<<4))
#define SIC_AV_GIR2_get_av_if_demod_irs(data)                         ((0x0F000000&(data))>>24)
#define SIC_AV_GIR2_get_av_vd_irs(data)                               ((0x00F00000&(data))>>20)
#define SIC_AV_GIR2_get_av_vbi_irs(data)                              ((0x000F0000&(data))>>16)
#define SIC_AV_GIR2_get_av_aud_irs(data)                              ((0x0000F000&(data))>>12)
#define SIC_AV_GIR2_get_av_hdmi_irs(data)                             ((0x00000F00&(data))>>8)
#define SIC_AV_GIR2_get_av_cec_irs(data)                              ((0x000000F0&(data))>>4)


#define SIC_AV_GIR3                                                   0x1800325c
#define SIC_AV_GIR3_reg_addr                                          "0xb800325c"
#define SIC_AV_GIR3_reg                                               0xb800325c
#define SIC_AV_GIR3_inst_addr                                         "0x0097"
#define SIC_AV_GIR3_inst                                              0x0097
#define SIC_AV_GIR3_av_cp_irs_shift                                   (28)
#define SIC_AV_GIR3_av_tp_irs_shift                                   (24)
#define SIC_AV_GIR3_av_mpeg_irs_shift                                 (16)
#define SIC_AV_GIR3_av_vge_irs_shift                                  (12)
#define SIC_AV_GIR3_av_osd_irs_shift                                  (8)
#define SIC_AV_GIR3_av_cp_irs_mask                                    (0xF0000000)
#define SIC_AV_GIR3_av_tp_irs_mask                                    (0x0F000000)
#define SIC_AV_GIR3_av_mpeg_irs_mask                                  (0x000F0000)
#define SIC_AV_GIR3_av_vge_irs_mask                                   (0x0000F000)
#define SIC_AV_GIR3_av_osd_irs_mask                                   (0x00000F00)
#define SIC_AV_GIR3_av_cp_irs(data)                                   (0xF0000000&((data)<<28))
#define SIC_AV_GIR3_av_tp_irs(data)                                   (0x0F000000&((data)<<24))
#define SIC_AV_GIR3_av_mpeg_irs(data)                                 (0x000F0000&((data)<<16))
#define SIC_AV_GIR3_av_vge_irs(data)                                  (0x0000F000&((data)<<12))
#define SIC_AV_GIR3_av_osd_irs(data)                                  (0x00000F00&((data)<<8))
#define SIC_AV_GIR3_get_av_cp_irs(data)                               ((0xF0000000&(data))>>28)
#define SIC_AV_GIR3_get_av_tp_irs(data)                               ((0x0F000000&(data))>>24)
#define SIC_AV_GIR3_get_av_mpeg_irs(data)                             ((0x000F0000&(data))>>16)
#define SIC_AV_GIR3_get_av_vge_irs(data)                              ((0x0000F000&(data))>>12)
#define SIC_AV_GIR3_get_av_osd_irs(data)                              ((0x00000F00&(data))>>8)


#define SIC_AV_GIR4                                                   0x18003260
#define SIC_AV_GIR4_reg_addr                                          "0xb8003260"
#define SIC_AV_GIR4_reg                                               0xb8003260
#define SIC_AV_GIR4_inst_addr                                         "0x0098"
#define SIC_AV_GIR4_inst                                              0x0098
#define SIC_AV_GIR4_av_apll_irs_shift                                 (28)
#define SIC_AV_GIR4_av_vodma_irs_shift                                (24)
#define SIC_AV_GIR4_av_dct_irs_shift                                  (20)
#define SIC_AV_GIR4_av_uz_irs_shift                                   (16)
#define SIC_AV_GIR4_av_idomain_irs_shift                              (8)
#define SIC_AV_GIR4_av_mdomain_irs_shift                              (4)
#define SIC_AV_GIR4_av_apll_irs_mask                                  (0xF0000000)
#define SIC_AV_GIR4_av_vodma_irs_mask                                 (0x0F000000)
#define SIC_AV_GIR4_av_dct_irs_mask                                   (0x00F00000)
#define SIC_AV_GIR4_av_uz_irs_mask                                    (0x000F0000)
#define SIC_AV_GIR4_av_idomain_irs_mask                               (0x00000F00)
#define SIC_AV_GIR4_av_mdomain_irs_mask                               (0x000000F0)
#define SIC_AV_GIR4_av_apll_irs(data)                                 (0xF0000000&((data)<<28))
#define SIC_AV_GIR4_av_vodma_irs(data)                                (0x0F000000&((data)<<24))
#define SIC_AV_GIR4_av_dct_irs(data)                                  (0x00F00000&((data)<<20))
#define SIC_AV_GIR4_av_uz_irs(data)                                   (0x000F0000&((data)<<16))
#define SIC_AV_GIR4_av_idomain_irs(data)                              (0x00000F00&((data)<<8))
#define SIC_AV_GIR4_av_mdomain_irs(data)                              (0x000000F0&((data)<<4))
#define SIC_AV_GIR4_get_av_apll_irs(data)                             ((0xF0000000&(data))>>28)
#define SIC_AV_GIR4_get_av_vodma_irs(data)                            ((0x0F000000&(data))>>24)
#define SIC_AV_GIR4_get_av_dct_irs(data)                              ((0x00F00000&(data))>>20)
#define SIC_AV_GIR4_get_av_uz_irs(data)                               ((0x000F0000&(data))>>16)
#define SIC_AV_GIR4_get_av_idomain_irs(data)                          ((0x00000F00&(data))>>8)
#define SIC_AV_GIR4_get_av_mdomain_irs(data)                          ((0x000000F0&(data))>>4)


#define SIC_AV_GIR5                                                   0x18003264
#define SIC_AV_GIR5_reg_addr                                          "0xb8003264"
#define SIC_AV_GIR5_reg                                               0xb8003264
#define SIC_AV_GIR5_inst_addr                                         "0x0099"
#define SIC_AV_GIR5_inst                                              0x0099
#define SIC_AV_GIR5_av_timer7_irs_shift                               (28)
#define SIC_AV_GIR5_av_timer6_irs_shift                               (24)
#define SIC_AV_GIR5_av_timer5_irs_shift                               (20)
#define SIC_AV_GIR5_av_timer4_irs_shift                               (16)
#define SIC_AV_GIR5_av_timer3_irs_shift                               (12)
#define SIC_AV_GIR5_av_timer2_irs_shift                               (8)
#define SIC_AV_GIR5_av_timer1_irs_shift                               (4)
#define SIC_AV_GIR5_av_timer0_irs_shift                               (0)
#define SIC_AV_GIR5_av_timer7_irs_mask                                (0xF0000000)
#define SIC_AV_GIR5_av_timer6_irs_mask                                (0x0F000000)
#define SIC_AV_GIR5_av_timer5_irs_mask                                (0x00F00000)
#define SIC_AV_GIR5_av_timer4_irs_mask                                (0x000F0000)
#define SIC_AV_GIR5_av_timer3_irs_mask                                (0x0000F000)
#define SIC_AV_GIR5_av_timer2_irs_mask                                (0x00000F00)
#define SIC_AV_GIR5_av_timer1_irs_mask                                (0x000000F0)
#define SIC_AV_GIR5_av_timer0_irs_mask                                (0x0000000F)
#define SIC_AV_GIR5_av_timer7_irs(data)                               (0xF0000000&((data)<<28))
#define SIC_AV_GIR5_av_timer6_irs(data)                               (0x0F000000&((data)<<24))
#define SIC_AV_GIR5_av_timer5_irs(data)                               (0x00F00000&((data)<<20))
#define SIC_AV_GIR5_av_timer4_irs(data)                               (0x000F0000&((data)<<16))
#define SIC_AV_GIR5_av_timer3_irs(data)                               (0x0000F000&((data)<<12))
#define SIC_AV_GIR5_av_timer2_irs(data)                               (0x00000F00&((data)<<8))
#define SIC_AV_GIR5_av_timer1_irs(data)                               (0x000000F0&((data)<<4))
#define SIC_AV_GIR5_av_timer0_irs(data)                               (0x0000000F&(data))
#define SIC_AV_GIR5_get_av_timer7_irs(data)                           ((0xF0000000&(data))>>28)
#define SIC_AV_GIR5_get_av_timer6_irs(data)                           ((0x0F000000&(data))>>24)
#define SIC_AV_GIR5_get_av_timer5_irs(data)                           ((0x00F00000&(data))>>20)
#define SIC_AV_GIR5_get_av_timer4_irs(data)                           ((0x000F0000&(data))>>16)
#define SIC_AV_GIR5_get_av_timer3_irs(data)                           ((0x0000F000&(data))>>12)
#define SIC_AV_GIR5_get_av_timer2_irs(data)                           ((0x00000F00&(data))>>8)
#define SIC_AV_GIR5_get_av_timer1_irs(data)                           ((0x000000F0&(data))>>4)
#define SIC_AV_GIR5_get_av_timer0_irs(data)                           (0x0000000F&(data))


#define SIC_AV_GIR6                                                   0x18003268
#define SIC_AV_GIR6_reg_addr                                          "0xb8003268"
#define SIC_AV_GIR6_reg                                               0xb8003268
#define SIC_AV_GIR6_inst_addr                                         "0x009A"
#define SIC_AV_GIR6_inst                                              0x009A
#define SIC_AV_GIR6_av_uart_0_irs_shift                               (28)
#define SIC_AV_GIR6_av_uart_1_irs_shift                               (24)
#define SIC_AV_GIR6_av_uart_2_irs_shift                               (20)
#define SIC_AV_GIR6_av_lsadc_irs_shift                                (12)
#define SIC_AV_GIR6_av_rtc_irs_shift                                  (8)
#define SIC_AV_GIR6_av_uart_0_irs_mask                                (0xF0000000)
#define SIC_AV_GIR6_av_uart_1_irs_mask                                (0x0F000000)
#define SIC_AV_GIR6_av_uart_2_irs_mask                                (0x00F00000)
#define SIC_AV_GIR6_av_lsadc_irs_mask                                 (0x0000F000)
#define SIC_AV_GIR6_av_rtc_irs_mask                                   (0x00000F00)
#define SIC_AV_GIR6_av_uart_0_irs(data)                               (0xF0000000&((data)<<28))
#define SIC_AV_GIR6_av_uart_1_irs(data)                               (0x0F000000&((data)<<24))
#define SIC_AV_GIR6_av_uart_2_irs(data)                               (0x00F00000&((data)<<20))
#define SIC_AV_GIR6_av_lsadc_irs(data)                                (0x0000F000&((data)<<12))
#define SIC_AV_GIR6_av_rtc_irs(data)                                  (0x00000F00&((data)<<8))
#define SIC_AV_GIR6_get_av_uart_0_irs(data)                           ((0xF0000000&(data))>>28)
#define SIC_AV_GIR6_get_av_uart_1_irs(data)                           ((0x0F000000&(data))>>24)
#define SIC_AV_GIR6_get_av_uart_2_irs(data)                           ((0x00F00000&(data))>>20)
#define SIC_AV_GIR6_get_av_lsadc_irs(data)                            ((0x0000F000&(data))>>12)
#define SIC_AV_GIR6_get_av_rtc_irs(data)                              ((0x00000F00&(data))>>8)


#define SIC_AV_GIR7                                                   0x1800326c
#define SIC_AV_GIR7_reg_addr                                          "0xb800326c"
#define SIC_AV_GIR7_reg                                               0xb800326c
#define SIC_AV_GIR7_inst_addr                                         "0x009B"
#define SIC_AV_GIR7_inst                                              0x009B
#define SIC_AV_GIR7_av_irda_irs_shift                                 (28)
#define SIC_AV_GIR7_av_i2c_0_irs_shift                                (24)
#define SIC_AV_GIR7_av_i2c_1_irs_shift                                (20)
#define SIC_AV_GIR7_av_ddc0_irs_shift                                 (12)
#define SIC_AV_GIR7_av_ddc1_irs_shift                                 (8)
#define SIC_AV_GIR7_av_ddc2_irs_shift                                 (4)
#define SIC_AV_GIR7_av_ddc3_irs_shift                                 (0)
#define SIC_AV_GIR7_av_irda_irs_mask                                  (0xF0000000)
#define SIC_AV_GIR7_av_i2c_0_irs_mask                                 (0x0F000000)
#define SIC_AV_GIR7_av_i2c_1_irs_mask                                 (0x00F00000)
#define SIC_AV_GIR7_av_ddc0_irs_mask                                  (0x0000F000)
#define SIC_AV_GIR7_av_ddc1_irs_mask                                  (0x00000F00)
#define SIC_AV_GIR7_av_ddc2_irs_mask                                  (0x000000F0)
#define SIC_AV_GIR7_av_ddc3_irs_mask                                  (0x0000000F)
#define SIC_AV_GIR7_av_irda_irs(data)                                 (0xF0000000&((data)<<28))
#define SIC_AV_GIR7_av_i2c_0_irs(data)                                (0x0F000000&((data)<<24))
#define SIC_AV_GIR7_av_i2c_1_irs(data)                                (0x00F00000&((data)<<20))
#define SIC_AV_GIR7_av_ddc0_irs(data)                                 (0x0000F000&((data)<<12))
#define SIC_AV_GIR7_av_ddc1_irs(data)                                 (0x00000F00&((data)<<8))
#define SIC_AV_GIR7_av_ddc2_irs(data)                                 (0x000000F0&((data)<<4))
#define SIC_AV_GIR7_av_ddc3_irs(data)                                 (0x0000000F&(data))
#define SIC_AV_GIR7_get_av_irda_irs(data)                             ((0xF0000000&(data))>>28)
#define SIC_AV_GIR7_get_av_i2c_0_irs(data)                            ((0x0F000000&(data))>>24)
#define SIC_AV_GIR7_get_av_i2c_1_irs(data)                            ((0x00F00000&(data))>>20)
#define SIC_AV_GIR7_get_av_ddc0_irs(data)                             ((0x0000F000&(data))>>12)
#define SIC_AV_GIR7_get_av_ddc1_irs(data)                             ((0x00000F00&(data))>>8)
#define SIC_AV_GIR7_get_av_ddc2_irs(data)                             ((0x000000F0&(data))>>4)
#define SIC_AV_GIR7_get_av_ddc3_irs(data)                             (0x0000000F&(data))


#define SIC_AV_GIR8                                                   0x18003270
#define SIC_AV_GIR8_reg_addr                                          "0xb8003270"
#define SIC_AV_GIR8_reg                                               0xb8003270
#define SIC_AV_GIR8_inst_addr                                         "0x009C"
#define SIC_AV_GIR8_inst                                              0x009C
#define SIC_AV_GIR8_av_gpioa_irs_shift                                (28)
#define SIC_AV_GIR8_av_gpiob_irs_shift                                (24)
#define SIC_AV_GIR8_av_gpioc_irs_shift                                (20)
#define SIC_AV_GIR8_av_gpiod_irs_shift                                (16)
#define SIC_AV_GIR8_av_gpioe_irs_shift                                (12)
#define SIC_AV_GIR8_av_gpiof_irs_shift                                (8)
#define SIC_AV_GIR8_av_gpiog_irs_shift                                (4)
#define SIC_AV_GIR8_av_gpioh_irs_shift                                (0)
#define SIC_AV_GIR8_av_gpioa_irs_mask                                 (0xF0000000)
#define SIC_AV_GIR8_av_gpiob_irs_mask                                 (0x0F000000)
#define SIC_AV_GIR8_av_gpioc_irs_mask                                 (0x00F00000)
#define SIC_AV_GIR8_av_gpiod_irs_mask                                 (0x000F0000)
#define SIC_AV_GIR8_av_gpioe_irs_mask                                 (0x0000F000)
#define SIC_AV_GIR8_av_gpiof_irs_mask                                 (0x00000F00)
#define SIC_AV_GIR8_av_gpiog_irs_mask                                 (0x000000F0)
#define SIC_AV_GIR8_av_gpioh_irs_mask                                 (0x0000000F)
#define SIC_AV_GIR8_av_gpioa_irs(data)                                (0xF0000000&((data)<<28))
#define SIC_AV_GIR8_av_gpiob_irs(data)                                (0x0F000000&((data)<<24))
#define SIC_AV_GIR8_av_gpioc_irs(data)                                (0x00F00000&((data)<<20))
#define SIC_AV_GIR8_av_gpiod_irs(data)                                (0x000F0000&((data)<<16))
#define SIC_AV_GIR8_av_gpioe_irs(data)                                (0x0000F000&((data)<<12))
#define SIC_AV_GIR8_av_gpiof_irs(data)                                (0x00000F00&((data)<<8))
#define SIC_AV_GIR8_av_gpiog_irs(data)                                (0x000000F0&((data)<<4))
#define SIC_AV_GIR8_av_gpioh_irs(data)                                (0x0000000F&(data))
#define SIC_AV_GIR8_get_av_gpioa_irs(data)                            ((0xF0000000&(data))>>28)
#define SIC_AV_GIR8_get_av_gpiob_irs(data)                            ((0x0F000000&(data))>>24)
#define SIC_AV_GIR8_get_av_gpioc_irs(data)                            ((0x00F00000&(data))>>20)
#define SIC_AV_GIR8_get_av_gpiod_irs(data)                            ((0x000F0000&(data))>>16)
#define SIC_AV_GIR8_get_av_gpioe_irs(data)                            ((0x0000F000&(data))>>12)
#define SIC_AV_GIR8_get_av_gpiof_irs(data)                            ((0x00000F00&(data))>>8)
#define SIC_AV_GIR8_get_av_gpiog_irs(data)                            ((0x000000F0&(data))>>4)
#define SIC_AV_GIR8_get_av_gpioh_irs(data)                            (0x0000000F&(data))


#define SIC_AV_GIR9                                                   0x18003274
#define SIC_AV_GIR9_reg_addr                                          "0xb8003274"
#define SIC_AV_GIR9_reg                                               0xb8003274
#define SIC_AV_GIR9_inst_addr                                         "0x009D"
#define SIC_AV_GIR9_inst                                              0x009D
#define SIC_AV_GIR9_av_gpiok_irs_shift                                (28)
#define SIC_AV_GIR9_av_gpiom_irs_shift                                (24)
#define SIC_AV_GIR9_av_gpion_irs_shift                                (20)
#define SIC_AV_GIR9_av_gpiop_irs_shift                                (16)
#define SIC_AV_GIR9_av_gpioq_irs_shift                                (12)
#define SIC_AV_GIR9_av_gpior_irs_shift                                (8)
#define SIC_AV_GIR9_av_gpios_irs_shift                                (4)
#define SIC_AV_GIR9_av_gpiot_irs_shift                                (0)
#define SIC_AV_GIR9_av_gpiok_irs_mask                                 (0xF0000000)
#define SIC_AV_GIR9_av_gpiom_irs_mask                                 (0x0F000000)
#define SIC_AV_GIR9_av_gpion_irs_mask                                 (0x00F00000)
#define SIC_AV_GIR9_av_gpiop_irs_mask                                 (0x000F0000)
#define SIC_AV_GIR9_av_gpioq_irs_mask                                 (0x0000F000)
#define SIC_AV_GIR9_av_gpior_irs_mask                                 (0x00000F00)
#define SIC_AV_GIR9_av_gpios_irs_mask                                 (0x000000F0)
#define SIC_AV_GIR9_av_gpiot_irs_mask                                 (0x0000000F)
#define SIC_AV_GIR9_av_gpiok_irs(data)                                (0xF0000000&((data)<<28))
#define SIC_AV_GIR9_av_gpiom_irs(data)                                (0x0F000000&((data)<<24))
#define SIC_AV_GIR9_av_gpion_irs(data)                                (0x00F00000&((data)<<20))
#define SIC_AV_GIR9_av_gpiop_irs(data)                                (0x000F0000&((data)<<16))
#define SIC_AV_GIR9_av_gpioq_irs(data)                                (0x0000F000&((data)<<12))
#define SIC_AV_GIR9_av_gpior_irs(data)                                (0x00000F00&((data)<<8))
#define SIC_AV_GIR9_av_gpios_irs(data)                                (0x000000F0&((data)<<4))
#define SIC_AV_GIR9_av_gpiot_irs(data)                                (0x0000000F&(data))
#define SIC_AV_GIR9_get_av_gpiok_irs(data)                            ((0xF0000000&(data))>>28)
#define SIC_AV_GIR9_get_av_gpiom_irs(data)                            ((0x0F000000&(data))>>24)
#define SIC_AV_GIR9_get_av_gpion_irs(data)                            ((0x00F00000&(data))>>20)
#define SIC_AV_GIR9_get_av_gpiop_irs(data)                            ((0x000F0000&(data))>>16)
#define SIC_AV_GIR9_get_av_gpioq_irs(data)                            ((0x0000F000&(data))>>12)
#define SIC_AV_GIR9_get_av_gpior_irs(data)                            ((0x00000F00&(data))>>8)
#define SIC_AV_GIR9_get_av_gpios_irs(data)                            ((0x000000F0&(data))>>4)
#define SIC_AV_GIR9_get_av_gpiot_irs(data)                            (0x0000000F&(data))


#define SIC_AV_GIR10                                                  0x18003278
#define SIC_AV_GIR10_reg_addr                                         "0xb8003278"
#define SIC_AV_GIR10_reg                                              0xb8003278
#define SIC_AV_GIR10_inst_addr                                        "0x009E"
#define SIC_AV_GIR10_inst                                             0x009E
#define SIC_AV_GIR10_av_gpiou_irs_shift                               (28)
#define SIC_AV_GIR10_av_gpiov_irs_shift                               (24)
#define SIC_AV_GIR10_av_sc_irs_shift                                  (12)
#define SIC_AV_GIR10_av_pcmcia_irs_shift                              (8)
#define SIC_AV_GIR10_av_etn_irs_shift                                 (4)
#define SIC_AV_GIR10_av_usb_irs_shift                                 (0)
#define SIC_AV_GIR10_av_gpiou_irs_mask                                (0xF0000000)
#define SIC_AV_GIR10_av_gpiov_irs_mask                                (0x0F000000)
#define SIC_AV_GIR10_av_sc_irs_mask                                   (0x0000F000)
#define SIC_AV_GIR10_av_pcmcia_irs_mask                               (0x00000F00)
#define SIC_AV_GIR10_av_etn_irs_mask                                  (0x000000F0)
#define SIC_AV_GIR10_av_usb_irs_mask                                  (0x0000000F)
#define SIC_AV_GIR10_av_gpiou_irs(data)                               (0xF0000000&((data)<<28))
#define SIC_AV_GIR10_av_gpiov_irs(data)                               (0x0F000000&((data)<<24))
#define SIC_AV_GIR10_av_sc_irs(data)                                  (0x0000F000&((data)<<12))
#define SIC_AV_GIR10_av_pcmcia_irs(data)                              (0x00000F00&((data)<<8))
#define SIC_AV_GIR10_av_etn_irs(data)                                 (0x000000F0&((data)<<4))
#define SIC_AV_GIR10_av_usb_irs(data)                                 (0x0000000F&(data))
#define SIC_AV_GIR10_get_av_gpiou_irs(data)                           ((0xF0000000&(data))>>28)
#define SIC_AV_GIR10_get_av_gpiov_irs(data)                           ((0x0F000000&(data))>>24)
#define SIC_AV_GIR10_get_av_sc_irs(data)                              ((0x0000F000&(data))>>12)
#define SIC_AV_GIR10_get_av_pcmcia_irs(data)                          ((0x00000F00&(data))>>8)
#define SIC_AV_GIR10_get_av_etn_irs(data)                             ((0x000000F0&(data))>>4)
#define SIC_AV_GIR10_get_av_usb_irs(data)                             (0x0000000F&(data))


#define SIC_AV_GIR11                                                  0x1800327c
#define SIC_AV_GIR11_reg_addr                                         "0xb800327c"
#define SIC_AV_GIR11_reg                                              0xb800327c
#define SIC_AV_GIR11_inst_addr                                        "0x009F"
#define SIC_AV_GIR11_inst                                             0x009F
#define SIC_AV_GIR11_av_wdog_irs_shift                                (28)
#define SIC_AV_GIR11_av_nf_irs_shift                                  (24)
#define SIC_AV_GIR11_av_cr_irs_shift                                  (20)
#define SIC_AV_GIR11_av_wdog_irs_mask                                 (0xF0000000)
#define SIC_AV_GIR11_av_nf_irs_mask                                   (0x0F000000)
#define SIC_AV_GIR11_av_cr_irs_mask                                   (0x00F00000)
#define SIC_AV_GIR11_av_wdog_irs(data)                                (0xF0000000&((data)<<28))
#define SIC_AV_GIR11_av_nf_irs(data)                                  (0x0F000000&((data)<<24))
#define SIC_AV_GIR11_av_cr_irs(data)                                  (0x00F00000&((data)<<20))
#define SIC_AV_GIR11_get_av_wdog_irs(data)                            ((0xF0000000&(data))>>28)
#define SIC_AV_GIR11_get_av_nf_irs(data)                              ((0x0F000000&(data))>>24)
#define SIC_AV_GIR11_get_av_cr_irs(data)                              ((0x00F00000&(data))>>20)


#define SIC_AV_GIE0                                                   0x18003280
#define SIC_AV_GIE0_reg_addr                                          "0xb8003280"
#define SIC_AV_GIE0_reg                                               0xb8003280
#define SIC_AV_GIE0_inst_addr                                         "0x00A0"
#define SIC_AV_GIE0_inst                                              0x00A0
#define SIC_AV_GIE0_av_dcu_ie_shift                                   (31)
#define SIC_AV_GIE0_av_tvsb_ie_shift                                  (26)
#define SIC_AV_GIE0_av_rb_ie_shift                                    (24)
#define SIC_AV_GIE0_av_ae_ie_shift                                    (23)
#define SIC_AV_GIE0_av_cpudma_ie_shift                                (22)
#define SIC_AV_GIE0_av_adma_ie_shift                                  (21)
#define SIC_AV_GIE0_av_md_ie_shift                                    (18)
#define SIC_AV_GIE0_av_cpu_ie_shift                                   (16)
#define SIC_AV_GIE0_av_if_demod_ie_shift                              (14)
#define SIC_AV_GIE0_av_vd_ie_shift                                    (13)
#define SIC_AV_GIE0_av_vbi_ie_shift                                   (12)
#define SIC_AV_GIE0_av_aud_ie_shift                                   (11)
#define SIC_AV_GIE0_av_hdmi_ie_shift                                  (10)
#define SIC_AV_GIE0_av_cec_ie_shift                                   (9)
#define SIC_AV_GIE0_av_cp_ie_shift                                    (7)
#define SIC_AV_GIE0_av_tp_ie_shift                                    (6)
#define SIC_AV_GIE0_av_mpeg_ie_shift                                  (4)
#define SIC_AV_GIE0_av_vge_ie_shift                                   (3)
#define SIC_AV_GIE0_av_osd_ie_shift                                   (2)
#define SIC_AV_GIE0_av_dcu_ie_mask                                    (0x80000000)
#define SIC_AV_GIE0_av_tvsb_ie_mask                                   (0x04000000)
#define SIC_AV_GIE0_av_rb_ie_mask                                     (0x01000000)
#define SIC_AV_GIE0_av_ae_ie_mask                                     (0x00800000)
#define SIC_AV_GIE0_av_cpudma_ie_mask                                 (0x00400000)
#define SIC_AV_GIE0_av_adma_ie_mask                                   (0x00200000)
#define SIC_AV_GIE0_av_md_ie_mask                                     (0x00040000)
#define SIC_AV_GIE0_av_cpu_ie_mask                                    (0x00010000)
#define SIC_AV_GIE0_av_if_demod_ie_mask                               (0x00004000)
#define SIC_AV_GIE0_av_vd_ie_mask                                     (0x00002000)
#define SIC_AV_GIE0_av_vbi_ie_mask                                    (0x00001000)
#define SIC_AV_GIE0_av_aud_ie_mask                                    (0x00000800)
#define SIC_AV_GIE0_av_hdmi_ie_mask                                   (0x00000400)
#define SIC_AV_GIE0_av_cec_ie_mask                                    (0x00000200)
#define SIC_AV_GIE0_av_cp_ie_mask                                     (0x00000080)
#define SIC_AV_GIE0_av_tp_ie_mask                                     (0x00000040)
#define SIC_AV_GIE0_av_mpeg_ie_mask                                   (0x00000010)
#define SIC_AV_GIE0_av_vge_ie_mask                                    (0x00000008)
#define SIC_AV_GIE0_av_osd_ie_mask                                    (0x00000004)
#define SIC_AV_GIE0_av_dcu_ie(data)                                   (0x80000000&((data)<<31))
#define SIC_AV_GIE0_av_tvsb_ie(data)                                  (0x04000000&((data)<<26))
#define SIC_AV_GIE0_av_rb_ie(data)                                    (0x01000000&((data)<<24))
#define SIC_AV_GIE0_av_ae_ie(data)                                    (0x00800000&((data)<<23))
#define SIC_AV_GIE0_av_cpudma_ie(data)                                (0x00400000&((data)<<22))
#define SIC_AV_GIE0_av_adma_ie(data)                                  (0x00200000&((data)<<21))
#define SIC_AV_GIE0_av_md_ie(data)                                    (0x00040000&((data)<<18))
#define SIC_AV_GIE0_av_cpu_ie(data)                                   (0x00010000&((data)<<16))
#define SIC_AV_GIE0_av_if_demod_ie(data)                              (0x00004000&((data)<<14))
#define SIC_AV_GIE0_av_vd_ie(data)                                    (0x00002000&((data)<<13))
#define SIC_AV_GIE0_av_vbi_ie(data)                                   (0x00001000&((data)<<12))
#define SIC_AV_GIE0_av_aud_ie(data)                                   (0x00000800&((data)<<11))
#define SIC_AV_GIE0_av_hdmi_ie(data)                                  (0x00000400&((data)<<10))
#define SIC_AV_GIE0_av_cec_ie(data)                                   (0x00000200&((data)<<9))
#define SIC_AV_GIE0_av_cp_ie(data)                                    (0x00000080&((data)<<7))
#define SIC_AV_GIE0_av_tp_ie(data)                                    (0x00000040&((data)<<6))
#define SIC_AV_GIE0_av_mpeg_ie(data)                                  (0x00000010&((data)<<4))
#define SIC_AV_GIE0_av_vge_ie(data)                                   (0x00000008&((data)<<3))
#define SIC_AV_GIE0_av_osd_ie(data)                                   (0x00000004&((data)<<2))
#define SIC_AV_GIE0_get_av_dcu_ie(data)                               ((0x80000000&(data))>>31)
#define SIC_AV_GIE0_get_av_tvsb_ie(data)                              ((0x04000000&(data))>>26)
#define SIC_AV_GIE0_get_av_rb_ie(data)                                ((0x01000000&(data))>>24)
#define SIC_AV_GIE0_get_av_ae_ie(data)                                ((0x00800000&(data))>>23)
#define SIC_AV_GIE0_get_av_cpudma_ie(data)                            ((0x00400000&(data))>>22)
#define SIC_AV_GIE0_get_av_adma_ie(data)                              ((0x00200000&(data))>>21)
#define SIC_AV_GIE0_get_av_md_ie(data)                                ((0x00040000&(data))>>18)
#define SIC_AV_GIE0_get_av_cpu_ie(data)                               ((0x00010000&(data))>>16)
#define SIC_AV_GIE0_get_av_if_demod_ie(data)                          ((0x00004000&(data))>>14)
#define SIC_AV_GIE0_get_av_vd_ie(data)                                ((0x00002000&(data))>>13)
#define SIC_AV_GIE0_get_av_vbi_ie(data)                               ((0x00001000&(data))>>12)
#define SIC_AV_GIE0_get_av_aud_ie(data)                               ((0x00000800&(data))>>11)
#define SIC_AV_GIE0_get_av_hdmi_ie(data)                              ((0x00000400&(data))>>10)
#define SIC_AV_GIE0_get_av_cec_ie(data)                               ((0x00000200&(data))>>9)
#define SIC_AV_GIE0_get_av_cp_ie(data)                                ((0x00000080&(data))>>7)
#define SIC_AV_GIE0_get_av_tp_ie(data)                                ((0x00000040&(data))>>6)
#define SIC_AV_GIE0_get_av_mpeg_ie(data)                              ((0x00000010&(data))>>4)
#define SIC_AV_GIE0_get_av_vge_ie(data)                               ((0x00000008&(data))>>3)
#define SIC_AV_GIE0_get_av_osd_ie(data)                               ((0x00000004&(data))>>2)


#define SIC_AV_GIE1                                                   0x18003284
#define SIC_AV_GIE1_reg_addr                                          "0xb8003284"
#define SIC_AV_GIE1_reg                                               0xb8003284
#define SIC_AV_GIE1_inst_addr                                         "0x00A1"
#define SIC_AV_GIE1_inst                                              0x00A1
#define SIC_AV_GIE1_av_apll_ie_shift                                  (31)
#define SIC_AV_GIE1_av_vodma_ie_shift                                 (30)
#define SIC_AV_GIE1_av_dct_ie_shift                                   (29)
#define SIC_AV_GIE1_av_uz_ie_shift                                    (28)
#define SIC_AV_GIE1_av_idomain_ie_shift                               (26)
#define SIC_AV_GIE1_av_mdomain_ie_shift                               (25)
#define SIC_AV_GIE1_av_timer7_ie_shift                                (23)
#define SIC_AV_GIE1_av_timer6_ie_shift                                (22)
#define SIC_AV_GIE1_av_timer5_ie_shift                                (21)
#define SIC_AV_GIE1_av_timer4_ie_shift                                (20)
#define SIC_AV_GIE1_av_timer3_ie_shift                                (19)
#define SIC_AV_GIE1_av_timer2_ie_shift                                (18)
#define SIC_AV_GIE1_av_timer1_ie_shift                                (17)
#define SIC_AV_GIE1_av_timer0_ie_shift                                (16)
#define SIC_AV_GIE1_av_uart_0_ie_shift                                (15)
#define SIC_AV_GIE1_av_uart_1_ie_shift                                (14)
#define SIC_AV_GIE1_av_uart_2_ie_shift                                (13)
#define SIC_AV_GIE1_av_lsadc_ie_shift                                 (11)
#define SIC_AV_GIE1_av_rtc_ie_shift                                   (10)
#define SIC_AV_GIE1_av_irda_ie_shift                                  (7)
#define SIC_AV_GIE1_av_i2c_0_ie_shift                                 (6)
#define SIC_AV_GIE1_av_i2c_1_ie_shift                                 (5)
#define SIC_AV_GIE1_av_ddc0_ie_shift                                  (3)
#define SIC_AV_GIE1_av_ddc1_ie_shift                                  (2)
#define SIC_AV_GIE1_av_ddc2_ie_shift                                  (1)
#define SIC_AV_GIE1_av_ddc3_ie_shift                                  (0)
#define SIC_AV_GIE1_av_apll_ie_mask                                   (0x80000000)
#define SIC_AV_GIE1_av_vodma_ie_mask                                  (0x40000000)
#define SIC_AV_GIE1_av_dct_ie_mask                                    (0x20000000)
#define SIC_AV_GIE1_av_uz_ie_mask                                     (0x10000000)
#define SIC_AV_GIE1_av_idomain_ie_mask                                (0x04000000)
#define SIC_AV_GIE1_av_mdomain_ie_mask                                (0x02000000)
#define SIC_AV_GIE1_av_timer7_ie_mask                                 (0x00800000)
#define SIC_AV_GIE1_av_timer6_ie_mask                                 (0x00400000)
#define SIC_AV_GIE1_av_timer5_ie_mask                                 (0x00200000)
#define SIC_AV_GIE1_av_timer4_ie_mask                                 (0x00100000)
#define SIC_AV_GIE1_av_timer3_ie_mask                                 (0x00080000)
#define SIC_AV_GIE1_av_timer2_ie_mask                                 (0x00040000)
#define SIC_AV_GIE1_av_timer1_ie_mask                                 (0x00020000)
#define SIC_AV_GIE1_av_timer0_ie_mask                                 (0x00010000)
#define SIC_AV_GIE1_av_uart_0_ie_mask                                 (0x00008000)
#define SIC_AV_GIE1_av_uart_1_ie_mask                                 (0x00004000)
#define SIC_AV_GIE1_av_uart_2_ie_mask                                 (0x00002000)
#define SIC_AV_GIE1_av_lsadc_ie_mask                                  (0x00000800)
#define SIC_AV_GIE1_av_rtc_ie_mask                                    (0x00000400)
#define SIC_AV_GIE1_av_irda_ie_mask                                   (0x00000080)
#define SIC_AV_GIE1_av_i2c_0_ie_mask                                  (0x00000040)
#define SIC_AV_GIE1_av_i2c_1_ie_mask                                  (0x00000020)
#define SIC_AV_GIE1_av_ddc0_ie_mask                                   (0x00000008)
#define SIC_AV_GIE1_av_ddc1_ie_mask                                   (0x00000004)
#define SIC_AV_GIE1_av_ddc2_ie_mask                                   (0x00000002)
#define SIC_AV_GIE1_av_ddc3_ie_mask                                   (0x00000001)
#define SIC_AV_GIE1_av_apll_ie(data)                                  (0x80000000&((data)<<31))
#define SIC_AV_GIE1_av_vodma_ie(data)                                 (0x40000000&((data)<<30))
#define SIC_AV_GIE1_av_dct_ie(data)                                   (0x20000000&((data)<<29))
#define SIC_AV_GIE1_av_uz_ie(data)                                    (0x10000000&((data)<<28))
#define SIC_AV_GIE1_av_idomain_ie(data)                               (0x04000000&((data)<<26))
#define SIC_AV_GIE1_av_mdomain_ie(data)                               (0x02000000&((data)<<25))
#define SIC_AV_GIE1_av_timer7_ie(data)                                (0x00800000&((data)<<23))
#define SIC_AV_GIE1_av_timer6_ie(data)                                (0x00400000&((data)<<22))
#define SIC_AV_GIE1_av_timer5_ie(data)                                (0x00200000&((data)<<21))
#define SIC_AV_GIE1_av_timer4_ie(data)                                (0x00100000&((data)<<20))
#define SIC_AV_GIE1_av_timer3_ie(data)                                (0x00080000&((data)<<19))
#define SIC_AV_GIE1_av_timer2_ie(data)                                (0x00040000&((data)<<18))
#define SIC_AV_GIE1_av_timer1_ie(data)                                (0x00020000&((data)<<17))
#define SIC_AV_GIE1_av_timer0_ie(data)                                (0x00010000&((data)<<16))
#define SIC_AV_GIE1_av_uart_0_ie(data)                                (0x00008000&((data)<<15))
#define SIC_AV_GIE1_av_uart_1_ie(data)                                (0x00004000&((data)<<14))
#define SIC_AV_GIE1_av_uart_2_ie(data)                                (0x00002000&((data)<<13))
#define SIC_AV_GIE1_av_lsadc_ie(data)                                 (0x00000800&((data)<<11))
#define SIC_AV_GIE1_av_rtc_ie(data)                                   (0x00000400&((data)<<10))
#define SIC_AV_GIE1_av_irda_ie(data)                                  (0x00000080&((data)<<7))
#define SIC_AV_GIE1_av_i2c_0_ie(data)                                 (0x00000040&((data)<<6))
#define SIC_AV_GIE1_av_i2c_1_ie(data)                                 (0x00000020&((data)<<5))
#define SIC_AV_GIE1_av_ddc0_ie(data)                                  (0x00000008&((data)<<3))
#define SIC_AV_GIE1_av_ddc1_ie(data)                                  (0x00000004&((data)<<2))
#define SIC_AV_GIE1_av_ddc2_ie(data)                                  (0x00000002&((data)<<1))
#define SIC_AV_GIE1_av_ddc3_ie(data)                                  (0x00000001&(data))
#define SIC_AV_GIE1_get_av_apll_ie(data)                              ((0x80000000&(data))>>31)
#define SIC_AV_GIE1_get_av_vodma_ie(data)                             ((0x40000000&(data))>>30)
#define SIC_AV_GIE1_get_av_dct_ie(data)                               ((0x20000000&(data))>>29)
#define SIC_AV_GIE1_get_av_uz_ie(data)                                ((0x10000000&(data))>>28)
#define SIC_AV_GIE1_get_av_idomain_ie(data)                           ((0x04000000&(data))>>26)
#define SIC_AV_GIE1_get_av_mdomain_ie(data)                           ((0x02000000&(data))>>25)
#define SIC_AV_GIE1_get_av_timer7_ie(data)                            ((0x00800000&(data))>>23)
#define SIC_AV_GIE1_get_av_timer6_ie(data)                            ((0x00400000&(data))>>22)
#define SIC_AV_GIE1_get_av_timer5_ie(data)                            ((0x00200000&(data))>>21)
#define SIC_AV_GIE1_get_av_timer4_ie(data)                            ((0x00100000&(data))>>20)
#define SIC_AV_GIE1_get_av_timer3_ie(data)                            ((0x00080000&(data))>>19)
#define SIC_AV_GIE1_get_av_timer2_ie(data)                            ((0x00040000&(data))>>18)
#define SIC_AV_GIE1_get_av_timer1_ie(data)                            ((0x00020000&(data))>>17)
#define SIC_AV_GIE1_get_av_timer0_ie(data)                            ((0x00010000&(data))>>16)
#define SIC_AV_GIE1_get_av_uart_0_ie(data)                            ((0x00008000&(data))>>15)
#define SIC_AV_GIE1_get_av_uart_1_ie(data)                            ((0x00004000&(data))>>14)
#define SIC_AV_GIE1_get_av_uart_2_ie(data)                            ((0x00002000&(data))>>13)
#define SIC_AV_GIE1_get_av_lsadc_ie(data)                             ((0x00000800&(data))>>11)
#define SIC_AV_GIE1_get_av_rtc_ie(data)                               ((0x00000400&(data))>>10)
#define SIC_AV_GIE1_get_av_irda_ie(data)                              ((0x00000080&(data))>>7)
#define SIC_AV_GIE1_get_av_i2c_0_ie(data)                             ((0x00000040&(data))>>6)
#define SIC_AV_GIE1_get_av_i2c_1_ie(data)                             ((0x00000020&(data))>>5)
#define SIC_AV_GIE1_get_av_ddc0_ie(data)                              ((0x00000008&(data))>>3)
#define SIC_AV_GIE1_get_av_ddc1_ie(data)                              ((0x00000004&(data))>>2)
#define SIC_AV_GIE1_get_av_ddc2_ie(data)                              ((0x00000002&(data))>>1)
#define SIC_AV_GIE1_get_av_ddc3_ie(data)                              (0x00000001&(data))


#define SIC_AV_GIE2                                                   0x18003288
#define SIC_AV_GIE2_reg_addr                                          "0xb8003288"
#define SIC_AV_GIE2_reg                                               0xb8003288
#define SIC_AV_GIE2_inst_addr                                         "0x00A2"
#define SIC_AV_GIE2_inst                                              0x00A2
#define SIC_AV_GIE2_av_gpioa_ie_shift                                 (31)
#define SIC_AV_GIE2_av_gpiob_ie_shift                                 (30)
#define SIC_AV_GIE2_av_gpioc_ie_shift                                 (29)
#define SIC_AV_GIE2_av_gpiod_ie_shift                                 (28)
#define SIC_AV_GIE2_av_gpioe_ie_shift                                 (27)
#define SIC_AV_GIE2_av_gpiof_ie_shift                                 (26)
#define SIC_AV_GIE2_av_gpiog_ie_shift                                 (25)
#define SIC_AV_GIE2_av_gpioh_ie_shift                                 (24)
#define SIC_AV_GIE2_av_gpiok_ie_shift                                 (23)
#define SIC_AV_GIE2_av_gpiom_ie_shift                                 (22)
#define SIC_AV_GIE2_av_gpion_ie_shift                                 (21)
#define SIC_AV_GIE2_av_gpiop_ie_shift                                 (20)
#define SIC_AV_GIE2_av_gpioq_ie_shift                                 (19)
#define SIC_AV_GIE2_av_gpior_ie_shift                                 (18)
#define SIC_AV_GIE2_av_gpios_ie_shift                                 (17)
#define SIC_AV_GIE2_av_gpiot_ie_shift                                 (16)
#define SIC_AV_GIE2_av_gpiou_ie_shift                                 (15)
#define SIC_AV_GIE2_av_gpiov_ie_shift                                 (14)
#define SIC_AV_GIE2_av_sc_ie_shift                                    (13)
#define SIC_AV_GIE2_av_pcmcia_ie_shift                                (12)
#define SIC_AV_GIE2_av_etn_ie_shift                                   (11)
#define SIC_AV_GIE2_av_usb_ie_shift                                   (10)
#define SIC_AV_GIE2_av_wdog_ie_shift                                  (9)
#define SIC_AV_GIE2_av_nf_ie_shift                                    (8)
#define SIC_AV_GIE2_av_cr_ie_shift                                    (7)
#define SIC_AV_GIE2_av_gpioa_ie_mask                                  (0x80000000)
#define SIC_AV_GIE2_av_gpiob_ie_mask                                  (0x40000000)
#define SIC_AV_GIE2_av_gpioc_ie_mask                                  (0x20000000)
#define SIC_AV_GIE2_av_gpiod_ie_mask                                  (0x10000000)
#define SIC_AV_GIE2_av_gpioe_ie_mask                                  (0x08000000)
#define SIC_AV_GIE2_av_gpiof_ie_mask                                  (0x04000000)
#define SIC_AV_GIE2_av_gpiog_ie_mask                                  (0x02000000)
#define SIC_AV_GIE2_av_gpioh_ie_mask                                  (0x01000000)
#define SIC_AV_GIE2_av_gpiok_ie_mask                                  (0x00800000)
#define SIC_AV_GIE2_av_gpiom_ie_mask                                  (0x00400000)
#define SIC_AV_GIE2_av_gpion_ie_mask                                  (0x00200000)
#define SIC_AV_GIE2_av_gpiop_ie_mask                                  (0x00100000)
#define SIC_AV_GIE2_av_gpioq_ie_mask                                  (0x00080000)
#define SIC_AV_GIE2_av_gpior_ie_mask                                  (0x00040000)
#define SIC_AV_GIE2_av_gpios_ie_mask                                  (0x00020000)
#define SIC_AV_GIE2_av_gpiot_ie_mask                                  (0x00010000)
#define SIC_AV_GIE2_av_gpiou_ie_mask                                  (0x00008000)
#define SIC_AV_GIE2_av_gpiov_ie_mask                                  (0x00004000)
#define SIC_AV_GIE2_av_sc_ie_mask                                     (0x00002000)
#define SIC_AV_GIE2_av_pcmcia_ie_mask                                 (0x00001000)
#define SIC_AV_GIE2_av_etn_ie_mask                                    (0x00000800)
#define SIC_AV_GIE2_av_usb_ie_mask                                    (0x00000400)
#define SIC_AV_GIE2_av_wdog_ie_mask                                   (0x00000200)
#define SIC_AV_GIE2_av_nf_ie_mask                                     (0x00000100)
#define SIC_AV_GIE2_av_cr_ie_mask                                     (0x00000080)
#define SIC_AV_GIE2_av_gpioa_ie(data)                                 (0x80000000&((data)<<31))
#define SIC_AV_GIE2_av_gpiob_ie(data)                                 (0x40000000&((data)<<30))
#define SIC_AV_GIE2_av_gpioc_ie(data)                                 (0x20000000&((data)<<29))
#define SIC_AV_GIE2_av_gpiod_ie(data)                                 (0x10000000&((data)<<28))
#define SIC_AV_GIE2_av_gpioe_ie(data)                                 (0x08000000&((data)<<27))
#define SIC_AV_GIE2_av_gpiof_ie(data)                                 (0x04000000&((data)<<26))
#define SIC_AV_GIE2_av_gpiog_ie(data)                                 (0x02000000&((data)<<25))
#define SIC_AV_GIE2_av_gpioh_ie(data)                                 (0x01000000&((data)<<24))
#define SIC_AV_GIE2_av_gpiok_ie(data)                                 (0x00800000&((data)<<23))
#define SIC_AV_GIE2_av_gpiom_ie(data)                                 (0x00400000&((data)<<22))
#define SIC_AV_GIE2_av_gpion_ie(data)                                 (0x00200000&((data)<<21))
#define SIC_AV_GIE2_av_gpiop_ie(data)                                 (0x00100000&((data)<<20))
#define SIC_AV_GIE2_av_gpioq_ie(data)                                 (0x00080000&((data)<<19))
#define SIC_AV_GIE2_av_gpior_ie(data)                                 (0x00040000&((data)<<18))
#define SIC_AV_GIE2_av_gpios_ie(data)                                 (0x00020000&((data)<<17))
#define SIC_AV_GIE2_av_gpiot_ie(data)                                 (0x00010000&((data)<<16))
#define SIC_AV_GIE2_av_gpiou_ie(data)                                 (0x00008000&((data)<<15))
#define SIC_AV_GIE2_av_gpiov_ie(data)                                 (0x00004000&((data)<<14))
#define SIC_AV_GIE2_av_sc_ie(data)                                    (0x00002000&((data)<<13))
#define SIC_AV_GIE2_av_pcmcia_ie(data)                                (0x00001000&((data)<<12))
#define SIC_AV_GIE2_av_etn_ie(data)                                   (0x00000800&((data)<<11))
#define SIC_AV_GIE2_av_usb_ie(data)                                   (0x00000400&((data)<<10))
#define SIC_AV_GIE2_av_wdog_ie(data)                                  (0x00000200&((data)<<9))
#define SIC_AV_GIE2_av_nf_ie(data)                                    (0x00000100&((data)<<8))
#define SIC_AV_GIE2_av_cr_ie(data)                                    (0x00000080&((data)<<7))
#define SIC_AV_GIE2_get_av_gpioa_ie(data)                             ((0x80000000&(data))>>31)
#define SIC_AV_GIE2_get_av_gpiob_ie(data)                             ((0x40000000&(data))>>30)
#define SIC_AV_GIE2_get_av_gpioc_ie(data)                             ((0x20000000&(data))>>29)
#define SIC_AV_GIE2_get_av_gpiod_ie(data)                             ((0x10000000&(data))>>28)
#define SIC_AV_GIE2_get_av_gpioe_ie(data)                             ((0x08000000&(data))>>27)
#define SIC_AV_GIE2_get_av_gpiof_ie(data)                             ((0x04000000&(data))>>26)
#define SIC_AV_GIE2_get_av_gpiog_ie(data)                             ((0x02000000&(data))>>25)
#define SIC_AV_GIE2_get_av_gpioh_ie(data)                             ((0x01000000&(data))>>24)
#define SIC_AV_GIE2_get_av_gpiok_ie(data)                             ((0x00800000&(data))>>23)
#define SIC_AV_GIE2_get_av_gpiom_ie(data)                             ((0x00400000&(data))>>22)
#define SIC_AV_GIE2_get_av_gpion_ie(data)                             ((0x00200000&(data))>>21)
#define SIC_AV_GIE2_get_av_gpiop_ie(data)                             ((0x00100000&(data))>>20)
#define SIC_AV_GIE2_get_av_gpioq_ie(data)                             ((0x00080000&(data))>>19)
#define SIC_AV_GIE2_get_av_gpior_ie(data)                             ((0x00040000&(data))>>18)
#define SIC_AV_GIE2_get_av_gpios_ie(data)                             ((0x00020000&(data))>>17)
#define SIC_AV_GIE2_get_av_gpiot_ie(data)                             ((0x00010000&(data))>>16)
#define SIC_AV_GIE2_get_av_gpiou_ie(data)                             ((0x00008000&(data))>>15)
#define SIC_AV_GIE2_get_av_gpiov_ie(data)                             ((0x00004000&(data))>>14)
#define SIC_AV_GIE2_get_av_sc_ie(data)                                ((0x00002000&(data))>>13)
#define SIC_AV_GIE2_get_av_pcmcia_ie(data)                            ((0x00001000&(data))>>12)
#define SIC_AV_GIE2_get_av_etn_ie(data)                               ((0x00000800&(data))>>11)
#define SIC_AV_GIE2_get_av_usb_ie(data)                               ((0x00000400&(data))>>10)
#define SIC_AV_GIE2_get_av_wdog_ie(data)                              ((0x00000200&(data))>>9)
#define SIC_AV_GIE2_get_av_nf_ie(data)                                ((0x00000100&(data))>>8)
#define SIC_AV_GIE2_get_av_cr_ie(data)                                ((0x00000080&(data))>>7)


#define SIC_AV_GIP0                                                   0x18003290
#define SIC_AV_GIP0_reg_addr                                          "0xb8003290"
#define SIC_AV_GIP0_reg                                               0xb8003290
#define SIC_AV_GIP0_inst_addr                                         "0x00A4"
#define SIC_AV_GIP0_inst                                              0x00A4
#define SIC_AV_GIP0_av_dcu_ip_shift                                   (31)
#define SIC_AV_GIP0_av_tvsb_ip_shift                                  (26)
#define SIC_AV_GIP0_av_rb_ip_shift                                    (24)
#define SIC_AV_GIP0_av_ae_ip_shift                                    (23)
#define SIC_AV_GIP0_av_cpudma_ip_shift                                (22)
#define SIC_AV_GIP0_av_adma_ip_shift                                  (21)
#define SIC_AV_GIP0_av_md_ip_shift                                    (18)
#define SIC_AV_GIP0_av_cpu_ip_shift                                   (16)
#define SIC_AV_GIP0_av_if_demod_ip_shift                              (14)
#define SIC_AV_GIP0_av_vd_ip_shift                                    (13)
#define SIC_AV_GIP0_av_vbi_ip_shift                                   (12)
#define SIC_AV_GIP0_av_aud_ip_shift                                   (11)
#define SIC_AV_GIP0_av_hdmi_ip_shift                                  (10)
#define SIC_AV_GIP0_av_cec_ip_shift                                   (9)
#define SIC_AV_GIP0_av_cp_ip_shift                                    (7)
#define SIC_AV_GIP0_av_tp_ip_shift                                    (6)
#define SIC_AV_GIP0_av_mpeg_ip_shift                                  (4)
#define SIC_AV_GIP0_av_vge_ip_shift                                   (3)
#define SIC_AV_GIP0_av_osd_ip_shift                                   (2)
#define SIC_AV_GIP0_av_dcu_ip_mask                                    (0x80000000)
#define SIC_AV_GIP0_av_tvsb_ip_mask                                   (0x04000000)
#define SIC_AV_GIP0_av_rb_ip_mask                                     (0x01000000)
#define SIC_AV_GIP0_av_ae_ip_mask                                     (0x00800000)
#define SIC_AV_GIP0_av_cpudma_ip_mask                                 (0x00400000)
#define SIC_AV_GIP0_av_adma_ip_mask                                   (0x00200000)
#define SIC_AV_GIP0_av_md_ip_mask                                     (0x00040000)
#define SIC_AV_GIP0_av_cpu_ip_mask                                    (0x00010000)
#define SIC_AV_GIP0_av_if_demod_ip_mask                               (0x00004000)
#define SIC_AV_GIP0_av_vd_ip_mask                                     (0x00002000)
#define SIC_AV_GIP0_av_vbi_ip_mask                                    (0x00001000)
#define SIC_AV_GIP0_av_aud_ip_mask                                    (0x00000800)
#define SIC_AV_GIP0_av_hdmi_ip_mask                                   (0x00000400)
#define SIC_AV_GIP0_av_cec_ip_mask                                    (0x00000200)
#define SIC_AV_GIP0_av_cp_ip_mask                                     (0x00000080)
#define SIC_AV_GIP0_av_tp_ip_mask                                     (0x00000040)
#define SIC_AV_GIP0_av_mpeg_ip_mask                                   (0x00000010)
#define SIC_AV_GIP0_av_vge_ip_mask                                    (0x00000008)
#define SIC_AV_GIP0_av_osd_ip_mask                                    (0x00000004)
#define SIC_AV_GIP0_av_dcu_ip(data)                                   (0x80000000&((data)<<31))
#define SIC_AV_GIP0_av_tvsb_ip(data)                                  (0x04000000&((data)<<26))
#define SIC_AV_GIP0_av_rb_ip(data)                                    (0x01000000&((data)<<24))
#define SIC_AV_GIP0_av_ae_ip(data)                                    (0x00800000&((data)<<23))
#define SIC_AV_GIP0_av_cpudma_ip(data)                                (0x00400000&((data)<<22))
#define SIC_AV_GIP0_av_adma_ip(data)                                  (0x00200000&((data)<<21))
#define SIC_AV_GIP0_av_md_ip(data)                                    (0x00040000&((data)<<18))
#define SIC_AV_GIP0_av_cpu_ip(data)                                   (0x00010000&((data)<<16))
#define SIC_AV_GIP0_av_if_demod_ip(data)                              (0x00004000&((data)<<14))
#define SIC_AV_GIP0_av_vd_ip(data)                                    (0x00002000&((data)<<13))
#define SIC_AV_GIP0_av_vbi_ip(data)                                   (0x00001000&((data)<<12))
#define SIC_AV_GIP0_av_aud_ip(data)                                   (0x00000800&((data)<<11))
#define SIC_AV_GIP0_av_hdmi_ip(data)                                  (0x00000400&((data)<<10))
#define SIC_AV_GIP0_av_cec_ip(data)                                   (0x00000200&((data)<<9))
#define SIC_AV_GIP0_av_cp_ip(data)                                    (0x00000080&((data)<<7))
#define SIC_AV_GIP0_av_tp_ip(data)                                    (0x00000040&((data)<<6))
#define SIC_AV_GIP0_av_mpeg_ip(data)                                  (0x00000010&((data)<<4))
#define SIC_AV_GIP0_av_vge_ip(data)                                   (0x00000008&((data)<<3))
#define SIC_AV_GIP0_av_osd_ip(data)                                   (0x00000004&((data)<<2))
#define SIC_AV_GIP0_get_av_dcu_ip(data)                               ((0x80000000&(data))>>31)
#define SIC_AV_GIP0_get_av_tvsb_ip(data)                              ((0x04000000&(data))>>26)
#define SIC_AV_GIP0_get_av_rb_ip(data)                                ((0x01000000&(data))>>24)
#define SIC_AV_GIP0_get_av_ae_ip(data)                                ((0x00800000&(data))>>23)
#define SIC_AV_GIP0_get_av_cpudma_ip(data)                            ((0x00400000&(data))>>22)
#define SIC_AV_GIP0_get_av_adma_ip(data)                              ((0x00200000&(data))>>21)
#define SIC_AV_GIP0_get_av_md_ip(data)                                ((0x00040000&(data))>>18)
#define SIC_AV_GIP0_get_av_cpu_ip(data)                               ((0x00010000&(data))>>16)
#define SIC_AV_GIP0_get_av_if_demod_ip(data)                          ((0x00004000&(data))>>14)
#define SIC_AV_GIP0_get_av_vd_ip(data)                                ((0x00002000&(data))>>13)
#define SIC_AV_GIP0_get_av_vbi_ip(data)                               ((0x00001000&(data))>>12)
#define SIC_AV_GIP0_get_av_aud_ip(data)                               ((0x00000800&(data))>>11)
#define SIC_AV_GIP0_get_av_hdmi_ip(data)                              ((0x00000400&(data))>>10)
#define SIC_AV_GIP0_get_av_cec_ip(data)                               ((0x00000200&(data))>>9)
#define SIC_AV_GIP0_get_av_cp_ip(data)                                ((0x00000080&(data))>>7)
#define SIC_AV_GIP0_get_av_tp_ip(data)                                ((0x00000040&(data))>>6)
#define SIC_AV_GIP0_get_av_mpeg_ip(data)                              ((0x00000010&(data))>>4)
#define SIC_AV_GIP0_get_av_vge_ip(data)                               ((0x00000008&(data))>>3)
#define SIC_AV_GIP0_get_av_osd_ip(data)                               ((0x00000004&(data))>>2)


#define SIC_AV_GIP1                                                   0x18003294
#define SIC_AV_GIP1_reg_addr                                          "0xb8003294"
#define SIC_AV_GIP1_reg                                               0xb8003294
#define SIC_AV_GIP1_inst_addr                                         "0x00A5"
#define SIC_AV_GIP1_inst                                              0x00A5
#define SIC_AV_GIP1_av_apll_ip_shift                                  (31)
#define SIC_AV_GIP1_av_vodma_ip_shift                                 (30)
#define SIC_AV_GIP1_av_dct_ip_shift                                   (29)
#define SIC_AV_GIP1_av_uz_ip_shift                                    (28)
#define SIC_AV_GIP1_av_idomain_ip_shift                               (26)
#define SIC_AV_GIP1_av_mdomain_ip_shift                               (25)
#define SIC_AV_GIP1_av_timer7_ip_shift                                (23)
#define SIC_AV_GIP1_av_timer6_ip_shift                                (22)
#define SIC_AV_GIP1_av_timer5_ip_shift                                (21)
#define SIC_AV_GIP1_av_timer4_ip_shift                                (20)
#define SIC_AV_GIP1_av_timer3_ip_shift                                (19)
#define SIC_AV_GIP1_av_timer2_ip_shift                                (18)
#define SIC_AV_GIP1_av_timer1_ip_shift                                (17)
#define SIC_AV_GIP1_av_timer0_ip_shift                                (16)
#define SIC_AV_GIP1_av_uart_0_ip_shift                                (15)
#define SIC_AV_GIP1_av_uart_1_ip_shift                                (14)
#define SIC_AV_GIP1_av_uart_2_ip_shift                                (13)
#define SIC_AV_GIP1_av_lsadc_ip_shift                                 (11)
#define SIC_AV_GIP1_av_rtc_ip_shift                                   (10)
#define SIC_AV_GIP1_av_irda_ip_shift                                  (7)
#define SIC_AV_GIP1_av_i2c_0_ip_shift                                 (6)
#define SIC_AV_GIP1_av_i2c_1_ip_shift                                 (5)
#define SIC_AV_GIP1_av_ddc0_ip_shift                                  (3)
#define SIC_AV_GIP1_av_ddc1_ip_shift                                  (2)
#define SIC_AV_GIP1_av_ddc2_ip_shift                                  (1)
#define SIC_AV_GIP1_av_ddc3_ip_shift                                  (0)
#define SIC_AV_GIP1_av_apll_ip_mask                                   (0x80000000)
#define SIC_AV_GIP1_av_vodma_ip_mask                                  (0x40000000)
#define SIC_AV_GIP1_av_dct_ip_mask                                    (0x20000000)
#define SIC_AV_GIP1_av_uz_ip_mask                                     (0x10000000)
#define SIC_AV_GIP1_av_idomain_ip_mask                                (0x04000000)
#define SIC_AV_GIP1_av_mdomain_ip_mask                                (0x02000000)
#define SIC_AV_GIP1_av_timer7_ip_mask                                 (0x00800000)
#define SIC_AV_GIP1_av_timer6_ip_mask                                 (0x00400000)
#define SIC_AV_GIP1_av_timer5_ip_mask                                 (0x00200000)
#define SIC_AV_GIP1_av_timer4_ip_mask                                 (0x00100000)
#define SIC_AV_GIP1_av_timer3_ip_mask                                 (0x00080000)
#define SIC_AV_GIP1_av_timer2_ip_mask                                 (0x00040000)
#define SIC_AV_GIP1_av_timer1_ip_mask                                 (0x00020000)
#define SIC_AV_GIP1_av_timer0_ip_mask                                 (0x00010000)
#define SIC_AV_GIP1_av_uart_0_ip_mask                                 (0x00008000)
#define SIC_AV_GIP1_av_uart_1_ip_mask                                 (0x00004000)
#define SIC_AV_GIP1_av_uart_2_ip_mask                                 (0x00002000)
#define SIC_AV_GIP1_av_lsadc_ip_mask                                  (0x00000800)
#define SIC_AV_GIP1_av_rtc_ip_mask                                    (0x00000400)
#define SIC_AV_GIP1_av_irda_ip_mask                                   (0x00000080)
#define SIC_AV_GIP1_av_i2c_0_ip_mask                                  (0x00000040)
#define SIC_AV_GIP1_av_i2c_1_ip_mask                                  (0x00000020)
#define SIC_AV_GIP1_av_ddc0_ip_mask                                   (0x00000008)
#define SIC_AV_GIP1_av_ddc1_ip_mask                                   (0x00000004)
#define SIC_AV_GIP1_av_ddc2_ip_mask                                   (0x00000002)
#define SIC_AV_GIP1_av_ddc3_ip_mask                                   (0x00000001)
#define SIC_AV_GIP1_av_apll_ip(data)                                  (0x80000000&((data)<<31))
#define SIC_AV_GIP1_av_vodma_ip(data)                                 (0x40000000&((data)<<30))
#define SIC_AV_GIP1_av_dct_ip(data)                                   (0x20000000&((data)<<29))
#define SIC_AV_GIP1_av_uz_ip(data)                                    (0x10000000&((data)<<28))
#define SIC_AV_GIP1_av_idomain_ip(data)                               (0x04000000&((data)<<26))
#define SIC_AV_GIP1_av_mdomain_ip(data)                               (0x02000000&((data)<<25))
#define SIC_AV_GIP1_av_timer7_ip(data)                                (0x00800000&((data)<<23))
#define SIC_AV_GIP1_av_timer6_ip(data)                                (0x00400000&((data)<<22))
#define SIC_AV_GIP1_av_timer5_ip(data)                                (0x00200000&((data)<<21))
#define SIC_AV_GIP1_av_timer4_ip(data)                                (0x00100000&((data)<<20))
#define SIC_AV_GIP1_av_timer3_ip(data)                                (0x00080000&((data)<<19))
#define SIC_AV_GIP1_av_timer2_ip(data)                                (0x00040000&((data)<<18))
#define SIC_AV_GIP1_av_timer1_ip(data)                                (0x00020000&((data)<<17))
#define SIC_AV_GIP1_av_timer0_ip(data)                                (0x00010000&((data)<<16))
#define SIC_AV_GIP1_av_uart_0_ip(data)                                (0x00008000&((data)<<15))
#define SIC_AV_GIP1_av_uart_1_ip(data)                                (0x00004000&((data)<<14))
#define SIC_AV_GIP1_av_uart_2_ip(data)                                (0x00002000&((data)<<13))
#define SIC_AV_GIP1_av_lsadc_ip(data)                                 (0x00000800&((data)<<11))
#define SIC_AV_GIP1_av_rtc_ip(data)                                   (0x00000400&((data)<<10))
#define SIC_AV_GIP1_av_irda_ip(data)                                  (0x00000080&((data)<<7))
#define SIC_AV_GIP1_av_i2c_0_ip(data)                                 (0x00000040&((data)<<6))
#define SIC_AV_GIP1_av_i2c_1_ip(data)                                 (0x00000020&((data)<<5))
#define SIC_AV_GIP1_av_ddc0_ip(data)                                  (0x00000008&((data)<<3))
#define SIC_AV_GIP1_av_ddc1_ip(data)                                  (0x00000004&((data)<<2))
#define SIC_AV_GIP1_av_ddc2_ip(data)                                  (0x00000002&((data)<<1))
#define SIC_AV_GIP1_av_ddc3_ip(data)                                  (0x00000001&(data))
#define SIC_AV_GIP1_get_av_apll_ip(data)                              ((0x80000000&(data))>>31)
#define SIC_AV_GIP1_get_av_vodma_ip(data)                             ((0x40000000&(data))>>30)
#define SIC_AV_GIP1_get_av_dct_ip(data)                               ((0x20000000&(data))>>29)
#define SIC_AV_GIP1_get_av_uz_ip(data)                                ((0x10000000&(data))>>28)
#define SIC_AV_GIP1_get_av_idomain_ip(data)                           ((0x04000000&(data))>>26)
#define SIC_AV_GIP1_get_av_mdomain_ip(data)                           ((0x02000000&(data))>>25)
#define SIC_AV_GIP1_get_av_timer7_ip(data)                            ((0x00800000&(data))>>23)
#define SIC_AV_GIP1_get_av_timer6_ip(data)                            ((0x00400000&(data))>>22)
#define SIC_AV_GIP1_get_av_timer5_ip(data)                            ((0x00200000&(data))>>21)
#define SIC_AV_GIP1_get_av_timer4_ip(data)                            ((0x00100000&(data))>>20)
#define SIC_AV_GIP1_get_av_timer3_ip(data)                            ((0x00080000&(data))>>19)
#define SIC_AV_GIP1_get_av_timer2_ip(data)                            ((0x00040000&(data))>>18)
#define SIC_AV_GIP1_get_av_timer1_ip(data)                            ((0x00020000&(data))>>17)
#define SIC_AV_GIP1_get_av_timer0_ip(data)                            ((0x00010000&(data))>>16)
#define SIC_AV_GIP1_get_av_uart_0_ip(data)                            ((0x00008000&(data))>>15)
#define SIC_AV_GIP1_get_av_uart_1_ip(data)                            ((0x00004000&(data))>>14)
#define SIC_AV_GIP1_get_av_uart_2_ip(data)                            ((0x00002000&(data))>>13)
#define SIC_AV_GIP1_get_av_lsadc_ip(data)                             ((0x00000800&(data))>>11)
#define SIC_AV_GIP1_get_av_rtc_ip(data)                               ((0x00000400&(data))>>10)
#define SIC_AV_GIP1_get_av_irda_ip(data)                              ((0x00000080&(data))>>7)
#define SIC_AV_GIP1_get_av_i2c_0_ip(data)                             ((0x00000040&(data))>>6)
#define SIC_AV_GIP1_get_av_i2c_1_ip(data)                             ((0x00000020&(data))>>5)
#define SIC_AV_GIP1_get_av_ddc0_ip(data)                              ((0x00000008&(data))>>3)
#define SIC_AV_GIP1_get_av_ddc1_ip(data)                              ((0x00000004&(data))>>2)
#define SIC_AV_GIP1_get_av_ddc2_ip(data)                              ((0x00000002&(data))>>1)
#define SIC_AV_GIP1_get_av_ddc3_ip(data)                              (0x00000001&(data))


#define SIC_AV_GIP2                                                   0x18003298
#define SIC_AV_GIP2_reg_addr                                          "0xb8003298"
#define SIC_AV_GIP2_reg                                               0xb8003298
#define SIC_AV_GIP2_inst_addr                                         "0x00A6"
#define SIC_AV_GIP2_inst                                              0x00A6
#define SIC_AV_GIP2_av_gpioa_ip_shift                                 (31)
#define SIC_AV_GIP2_av_gpiob_ip_shift                                 (30)
#define SIC_AV_GIP2_av_gpioc_ip_shift                                 (29)
#define SIC_AV_GIP2_av_gpiod_ip_shift                                 (28)
#define SIC_AV_GIP2_av_gpioe_ip_shift                                 (27)
#define SIC_AV_GIP2_av_gpiof_ip_shift                                 (26)
#define SIC_AV_GIP2_av_gpiog_ip_shift                                 (25)
#define SIC_AV_GIP2_av_gpioh_ip_shift                                 (24)
#define SIC_AV_GIP2_av_gpiok_ip_shift                                 (23)
#define SIC_AV_GIP2_av_gpiom_ip_shift                                 (22)
#define SIC_AV_GIP2_av_gpion_ip_shift                                 (21)
#define SIC_AV_GIP2_av_gpiop_ip_shift                                 (20)
#define SIC_AV_GIP2_av_gpioq_ip_shift                                 (19)
#define SIC_AV_GIP2_av_gpior_ip_shift                                 (18)
#define SIC_AV_GIP2_av_gpios_ip_shift                                 (17)
#define SIC_AV_GIP2_av_gpiot_ip_shift                                 (16)
#define SIC_AV_GIP2_av_gpiou_ip_shift                                 (15)
#define SIC_AV_GIP2_av_gpiov_ip_shift                                 (14)
#define SIC_AV_GIP2_av_sc_ip_shift                                    (13)
#define SIC_AV_GIP2_av_pcmcia_ip_shift                                (12)
#define SIC_AV_GIP2_av_etn_ip_shift                                   (11)
#define SIC_AV_GIP2_av_usb_ip_shift                                   (10)
#define SIC_AV_GIP2_av_wdog_ip_shift                                  (9)
#define SIC_AV_GIP2_av_nf_ip_shift                                    (8)
#define SIC_AV_GIP2_av_cr_ip_shift                                    (7)
#define SIC_AV_GIP2_av_gpioa_ip_mask                                  (0x80000000)
#define SIC_AV_GIP2_av_gpiob_ip_mask                                  (0x40000000)
#define SIC_AV_GIP2_av_gpioc_ip_mask                                  (0x20000000)
#define SIC_AV_GIP2_av_gpiod_ip_mask                                  (0x10000000)
#define SIC_AV_GIP2_av_gpioe_ip_mask                                  (0x08000000)
#define SIC_AV_GIP2_av_gpiof_ip_mask                                  (0x04000000)
#define SIC_AV_GIP2_av_gpiog_ip_mask                                  (0x02000000)
#define SIC_AV_GIP2_av_gpioh_ip_mask                                  (0x01000000)
#define SIC_AV_GIP2_av_gpiok_ip_mask                                  (0x00800000)
#define SIC_AV_GIP2_av_gpiom_ip_mask                                  (0x00400000)
#define SIC_AV_GIP2_av_gpion_ip_mask                                  (0x00200000)
#define SIC_AV_GIP2_av_gpiop_ip_mask                                  (0x00100000)
#define SIC_AV_GIP2_av_gpioq_ip_mask                                  (0x00080000)
#define SIC_AV_GIP2_av_gpior_ip_mask                                  (0x00040000)
#define SIC_AV_GIP2_av_gpios_ip_mask                                  (0x00020000)
#define SIC_AV_GIP2_av_gpiot_ip_mask                                  (0x00010000)
#define SIC_AV_GIP2_av_gpiou_ip_mask                                  (0x00008000)
#define SIC_AV_GIP2_av_gpiov_ip_mask                                  (0x00004000)
#define SIC_AV_GIP2_av_sc_ip_mask                                     (0x00002000)
#define SIC_AV_GIP2_av_pcmcia_ip_mask                                 (0x00001000)
#define SIC_AV_GIP2_av_etn_ip_mask                                    (0x00000800)
#define SIC_AV_GIP2_av_usb_ip_mask                                    (0x00000400)
#define SIC_AV_GIP2_av_wdog_ip_mask                                   (0x00000200)
#define SIC_AV_GIP2_av_nf_ip_mask                                     (0x00000100)
#define SIC_AV_GIP2_av_cr_ip_mask                                     (0x00000080)
#define SIC_AV_GIP2_av_gpioa_ip(data)                                 (0x80000000&((data)<<31))
#define SIC_AV_GIP2_av_gpiob_ip(data)                                 (0x40000000&((data)<<30))
#define SIC_AV_GIP2_av_gpioc_ip(data)                                 (0x20000000&((data)<<29))
#define SIC_AV_GIP2_av_gpiod_ip(data)                                 (0x10000000&((data)<<28))
#define SIC_AV_GIP2_av_gpioe_ip(data)                                 (0x08000000&((data)<<27))
#define SIC_AV_GIP2_av_gpiof_ip(data)                                 (0x04000000&((data)<<26))
#define SIC_AV_GIP2_av_gpiog_ip(data)                                 (0x02000000&((data)<<25))
#define SIC_AV_GIP2_av_gpioh_ip(data)                                 (0x01000000&((data)<<24))
#define SIC_AV_GIP2_av_gpiok_ip(data)                                 (0x00800000&((data)<<23))
#define SIC_AV_GIP2_av_gpiom_ip(data)                                 (0x00400000&((data)<<22))
#define SIC_AV_GIP2_av_gpion_ip(data)                                 (0x00200000&((data)<<21))
#define SIC_AV_GIP2_av_gpiop_ip(data)                                 (0x00100000&((data)<<20))
#define SIC_AV_GIP2_av_gpioq_ip(data)                                 (0x00080000&((data)<<19))
#define SIC_AV_GIP2_av_gpior_ip(data)                                 (0x00040000&((data)<<18))
#define SIC_AV_GIP2_av_gpios_ip(data)                                 (0x00020000&((data)<<17))
#define SIC_AV_GIP2_av_gpiot_ip(data)                                 (0x00010000&((data)<<16))
#define SIC_AV_GIP2_av_gpiou_ip(data)                                 (0x00008000&((data)<<15))
#define SIC_AV_GIP2_av_gpiov_ip(data)                                 (0x00004000&((data)<<14))
#define SIC_AV_GIP2_av_sc_ip(data)                                    (0x00002000&((data)<<13))
#define SIC_AV_GIP2_av_pcmcia_ip(data)                                (0x00001000&((data)<<12))
#define SIC_AV_GIP2_av_etn_ip(data)                                   (0x00000800&((data)<<11))
#define SIC_AV_GIP2_av_usb_ip(data)                                   (0x00000400&((data)<<10))
#define SIC_AV_GIP2_av_wdog_ip(data)                                  (0x00000200&((data)<<9))
#define SIC_AV_GIP2_av_nf_ip(data)                                    (0x00000100&((data)<<8))
#define SIC_AV_GIP2_av_cr_ip(data)                                    (0x00000080&((data)<<7))
#define SIC_AV_GIP2_get_av_gpioa_ip(data)                             ((0x80000000&(data))>>31)
#define SIC_AV_GIP2_get_av_gpiob_ip(data)                             ((0x40000000&(data))>>30)
#define SIC_AV_GIP2_get_av_gpioc_ip(data)                             ((0x20000000&(data))>>29)
#define SIC_AV_GIP2_get_av_gpiod_ip(data)                             ((0x10000000&(data))>>28)
#define SIC_AV_GIP2_get_av_gpioe_ip(data)                             ((0x08000000&(data))>>27)
#define SIC_AV_GIP2_get_av_gpiof_ip(data)                             ((0x04000000&(data))>>26)
#define SIC_AV_GIP2_get_av_gpiog_ip(data)                             ((0x02000000&(data))>>25)
#define SIC_AV_GIP2_get_av_gpioh_ip(data)                             ((0x01000000&(data))>>24)
#define SIC_AV_GIP2_get_av_gpiok_ip(data)                             ((0x00800000&(data))>>23)
#define SIC_AV_GIP2_get_av_gpiom_ip(data)                             ((0x00400000&(data))>>22)
#define SIC_AV_GIP2_get_av_gpion_ip(data)                             ((0x00200000&(data))>>21)
#define SIC_AV_GIP2_get_av_gpiop_ip(data)                             ((0x00100000&(data))>>20)
#define SIC_AV_GIP2_get_av_gpioq_ip(data)                             ((0x00080000&(data))>>19)
#define SIC_AV_GIP2_get_av_gpior_ip(data)                             ((0x00040000&(data))>>18)
#define SIC_AV_GIP2_get_av_gpios_ip(data)                             ((0x00020000&(data))>>17)
#define SIC_AV_GIP2_get_av_gpiot_ip(data)                             ((0x00010000&(data))>>16)
#define SIC_AV_GIP2_get_av_gpiou_ip(data)                             ((0x00008000&(data))>>15)
#define SIC_AV_GIP2_get_av_gpiov_ip(data)                             ((0x00004000&(data))>>14)
#define SIC_AV_GIP2_get_av_sc_ip(data)                                ((0x00002000&(data))>>13)
#define SIC_AV_GIP2_get_av_pcmcia_ip(data)                            ((0x00001000&(data))>>12)
#define SIC_AV_GIP2_get_av_etn_ip(data)                               ((0x00000800&(data))>>11)
#define SIC_AV_GIP2_get_av_usb_ip(data)                               ((0x00000400&(data))>>10)
#define SIC_AV_GIP2_get_av_wdog_ip(data)                              ((0x00000200&(data))>>9)
#define SIC_AV_GIP2_get_av_nf_ip(data)                                ((0x00000100&(data))>>8)
#define SIC_AV_GIP2_get_av_cr_ip(data)                                ((0x00000080&(data))>>7)


#define SIC_DEBUG_INFO_ENABLE                                         0x180032a0
#define SIC_DEBUG_INFO_ENABLE_reg_addr                                "0xb80032a0"
#define SIC_DEBUG_INFO_ENABLE_reg                                     0xb80032a0
#define SIC_DEBUG_INFO_ENABLE_inst_addr                               "0x00A8"
#define SIC_DEBUG_INFO_ENABLE_inst                                    0x00A8
#define SIC_DEBUG_INFO_ENABLE_int_debug_en_shift                      (0)
#define SIC_DEBUG_INFO_ENABLE_int_debug_en_mask                       (0x00000001)
#define SIC_DEBUG_INFO_ENABLE_int_debug_en(data)                      (0x00000001&(data))
#define SIC_DEBUG_INFO_ENABLE_get_int_debug_en(data)                  (0x00000001&(data))


#define SIC_DEBUG_MCPU_IE0                                            0x180032b0
#define SIC_DEBUG_MCPU_IE0_reg_addr                                   "0xb80032b0"
#define SIC_DEBUG_MCPU_IE0_reg                                        0xb80032b0
#define SIC_DEBUG_MCPU_IE0_inst_addr                                  "0x00AC"
#define SIC_DEBUG_MCPU_IE0_inst                                       0x00AC
#define SIC_DEBUG_MCPU_IE0_m_debug_ie0_shift                          (0)
#define SIC_DEBUG_MCPU_IE0_m_debug_ie0_mask                           (0xFFFFFFFF)
#define SIC_DEBUG_MCPU_IE0_m_debug_ie0(data)                          (0xFFFFFFFF&(data))
#define SIC_DEBUG_MCPU_IE0_get_m_debug_ie0(data)                      (0xFFFFFFFF&(data))


#define SIC_DEBUG_MCPU_IE1                                            0x180032b4
#define SIC_DEBUG_MCPU_IE1_reg_addr                                   "0xb80032b4"
#define SIC_DEBUG_MCPU_IE1_reg                                        0xb80032b4
#define SIC_DEBUG_MCPU_IE1_inst_addr                                  "0x00AD"
#define SIC_DEBUG_MCPU_IE1_inst                                       0x00AD
#define SIC_DEBUG_MCPU_IE1_m_debug_ie1_shift                          (0)
#define SIC_DEBUG_MCPU_IE1_m_debug_ie1_mask                           (0xFFFFFFFF)
#define SIC_DEBUG_MCPU_IE1_m_debug_ie1(data)                          (0xFFFFFFFF&(data))
#define SIC_DEBUG_MCPU_IE1_get_m_debug_ie1(data)                      (0xFFFFFFFF&(data))


#define SIC_DEBUG_MCPU_IE2                                            0x180032b8
#define SIC_DEBUG_MCPU_IE2_reg_addr                                   "0xb80032b8"
#define SIC_DEBUG_MCPU_IE2_reg                                        0xb80032b8
#define SIC_DEBUG_MCPU_IE2_inst_addr                                  "0x00AE"
#define SIC_DEBUG_MCPU_IE2_inst                                       0x00AE
#define SIC_DEBUG_MCPU_IE2_m_debug_ie2_shift                          (0)
#define SIC_DEBUG_MCPU_IE2_m_debug_ie2_mask                           (0xFFFFFFFF)
#define SIC_DEBUG_MCPU_IE2_m_debug_ie2(data)                          (0xFFFFFFFF&(data))
#define SIC_DEBUG_MCPU_IE2_get_m_debug_ie2(data)                      (0xFFFFFFFF&(data))


#define SIC_DEBUG_MCPU_IP0                                            0x180032c0
#define SIC_DEBUG_MCPU_IP0_reg_addr                                   "0xb80032c0"
#define SIC_DEBUG_MCPU_IP0_reg                                        0xb80032c0
#define SIC_DEBUG_MCPU_IP0_inst_addr                                  "0x00B0"
#define SIC_DEBUG_MCPU_IP0_inst                                       0x00B0
#define SIC_DEBUG_MCPU_IP0_m_debug_ip0_shift                          (0)
#define SIC_DEBUG_MCPU_IP0_m_debug_ip0_mask                           (0xFFFFFFFF)
#define SIC_DEBUG_MCPU_IP0_m_debug_ip0(data)                          (0xFFFFFFFF&(data))
#define SIC_DEBUG_MCPU_IP0_get_m_debug_ip0(data)                      (0xFFFFFFFF&(data))


#define SIC_DEBUG_MCPU_IP1                                            0x180032c4
#define SIC_DEBUG_MCPU_IP1_reg_addr                                   "0xb80032c4"
#define SIC_DEBUG_MCPU_IP1_reg                                        0xb80032c4
#define SIC_DEBUG_MCPU_IP1_inst_addr                                  "0x00B1"
#define SIC_DEBUG_MCPU_IP1_inst                                       0x00B1
#define SIC_DEBUG_MCPU_IP1_m_debug_ip1_shift                          (0)
#define SIC_DEBUG_MCPU_IP1_m_debug_ip1_mask                           (0xFFFFFFFF)
#define SIC_DEBUG_MCPU_IP1_m_debug_ip1(data)                          (0xFFFFFFFF&(data))
#define SIC_DEBUG_MCPU_IP1_get_m_debug_ip1(data)                      (0xFFFFFFFF&(data))


#define SIC_DEBUG_MCPU_IP2                                            0x180032c8
#define SIC_DEBUG_MCPU_IP2_reg_addr                                   "0xb80032c8"
#define SIC_DEBUG_MCPU_IP2_reg                                        0xb80032c8
#define SIC_DEBUG_MCPU_IP2_inst_addr                                  "0x00B2"
#define SIC_DEBUG_MCPU_IP2_inst                                       0x00B2
#define SIC_DEBUG_MCPU_IP2_m_debug_ip2_shift                          (0)
#define SIC_DEBUG_MCPU_IP2_m_debug_ip2_mask                           (0xFFFFFFFF)
#define SIC_DEBUG_MCPU_IP2_m_debug_ip2(data)                          (0xFFFFFFFF&(data))
#define SIC_DEBUG_MCPU_IP2_get_m_debug_ip2(data)                      (0xFFFFFFFF&(data))


#define SIC_DEBUG_AVCPU_IE0                                           0x180032d0
#define SIC_DEBUG_AVCPU_IE0_reg_addr                                  "0xb80032d0"
#define SIC_DEBUG_AVCPU_IE0_reg                                       0xb80032d0
#define SIC_DEBUG_AVCPU_IE0_inst_addr                                 "0x00B4"
#define SIC_DEBUG_AVCPU_IE0_inst                                      0x00B4
#define SIC_DEBUG_AVCPU_IE0_av_debug_ie0_shift                        (0)
#define SIC_DEBUG_AVCPU_IE0_av_debug_ie0_mask                         (0xFFFFFFFF)
#define SIC_DEBUG_AVCPU_IE0_av_debug_ie0(data)                        (0xFFFFFFFF&(data))
#define SIC_DEBUG_AVCPU_IE0_get_av_debug_ie0(data)                    (0xFFFFFFFF&(data))


#define SIC_DEBUG_AVCPU_IE1                                           0x180032d4
#define SIC_DEBUG_AVCPU_IE1_reg_addr                                  "0xb80032d4"
#define SIC_DEBUG_AVCPU_IE1_reg                                       0xb80032d4
#define SIC_DEBUG_AVCPU_IE1_inst_addr                                 "0x00B5"
#define SIC_DEBUG_AVCPU_IE1_inst                                      0x00B5
#define SIC_DEBUG_AVCPU_IE1_av_debug_ie1_shift                        (0)
#define SIC_DEBUG_AVCPU_IE1_av_debug_ie1_mask                         (0xFFFFFFFF)
#define SIC_DEBUG_AVCPU_IE1_av_debug_ie1(data)                        (0xFFFFFFFF&(data))
#define SIC_DEBUG_AVCPU_IE1_get_av_debug_ie1(data)                    (0xFFFFFFFF&(data))


#define SIC_DEBUG_AVCPU_IE2                                           0x180032d8
#define SIC_DEBUG_AVCPU_IE2_reg_addr                                  "0xb80032d8"
#define SIC_DEBUG_AVCPU_IE2_reg                                       0xb80032d8
#define SIC_DEBUG_AVCPU_IE2_inst_addr                                 "0x00B6"
#define SIC_DEBUG_AVCPU_IE2_inst                                      0x00B6
#define SIC_DEBUG_AVCPU_IE2_av_debug_ie2_shift                        (0)
#define SIC_DEBUG_AVCPU_IE2_av_debug_ie2_mask                         (0xFFFFFFFF)
#define SIC_DEBUG_AVCPU_IE2_av_debug_ie2(data)                        (0xFFFFFFFF&(data))
#define SIC_DEBUG_AVCPU_IE2_get_av_debug_ie2(data)                    (0xFFFFFFFF&(data))


#define SIC_DEBUG_AVCPU_IP0                                           0x180032e0
#define SIC_DEBUG_AVCPU_IP0_reg_addr                                  "0xb80032e0"
#define SIC_DEBUG_AVCPU_IP0_reg                                       0xb80032e0
#define SIC_DEBUG_AVCPU_IP0_inst_addr                                 "0x00B8"
#define SIC_DEBUG_AVCPU_IP0_inst                                      0x00B8
#define SIC_DEBUG_AVCPU_IP0_av_debug_ip0_shift                        (0)
#define SIC_DEBUG_AVCPU_IP0_av_debug_ip0_mask                         (0xFFFFFFFF)
#define SIC_DEBUG_AVCPU_IP0_av_debug_ip0(data)                        (0xFFFFFFFF&(data))
#define SIC_DEBUG_AVCPU_IP0_get_av_debug_ip0(data)                    (0xFFFFFFFF&(data))


#define SIC_DEBUG_AVCPU_IP1                                           0x180032e4
#define SIC_DEBUG_AVCPU_IP1_reg_addr                                  "0xb80032e4"
#define SIC_DEBUG_AVCPU_IP1_reg                                       0xb80032e4
#define SIC_DEBUG_AVCPU_IP1_inst_addr                                 "0x00B9"
#define SIC_DEBUG_AVCPU_IP1_inst                                      0x00B9
#define SIC_DEBUG_AVCPU_IP1_av_debug_ip1_shift                        (0)
#define SIC_DEBUG_AVCPU_IP1_av_debug_ip1_mask                         (0xFFFFFFFF)
#define SIC_DEBUG_AVCPU_IP1_av_debug_ip1(data)                        (0xFFFFFFFF&(data))
#define SIC_DEBUG_AVCPU_IP1_get_av_debug_ip1(data)                    (0xFFFFFFFF&(data))


#define SIC_DEBUG_AVCPU_IP2                                           0x180032e8
#define SIC_DEBUG_AVCPU_IP2_reg_addr                                  "0xb80032e8"
#define SIC_DEBUG_AVCPU_IP2_reg                                       0xb80032e8
#define SIC_DEBUG_AVCPU_IP2_inst_addr                                 "0x00BA"
#define SIC_DEBUG_AVCPU_IP2_inst                                      0x00BA
#define SIC_DEBUG_AVCPU_IP2_av_debug_ip2_shift                        (0)
#define SIC_DEBUG_AVCPU_IP2_av_debug_ip2_mask                         (0xFFFFFFFF)
#define SIC_DEBUG_AVCPU_IP2_av_debug_ip2(data)                        (0xFFFFFFFF&(data))
#define SIC_DEBUG_AVCPU_IP2_get_av_debug_ip2(data)                    (0xFFFFFFFF&(data))
#endif
