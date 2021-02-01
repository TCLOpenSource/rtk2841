#ifndef __RTK_ICE_DMA_DEFINE_H__
#define __RTK_ICE_DMA_DEFINE_H__

#include <mach/io.h>
#include "../core/rtk_ice.h"
//#define USE_MERLINE_SIMULATE_MERLINE2
#ifndef USE_MERLINE_SIMULATE_MERLINE2
#include <rbus/di_reg.h>
#include <rbus/iedge_smooth_reg.h>
#include <rbus/de_xcxl_reg.h>
#include <rbus/vdpq_reg.h>
#include <rbus/od_dma_reg.h>
#include <rbus/audio_reg.h>
#include <rbus/pst_i2rnd_reg.h>
//#include <rbus/demura_reg.h>
#else
#include <rbus/rbusDiReg.h>
#include <rbus/rbusIedge_smoothReg.h>
#include <rbus/rbusVDPQReg.h>
#include <rbus/rbusOD_DMAReg.h>
#endif
#include <rbus/mdomain_cap_reg.h>
#include <rbus/mdomain_disp_reg.h>
#include <rbus/h3ddma_reg.h>
#include <rbus/vodma_reg.h>
#include <rbus/vodma2_reg.h>


#include <rbus/vbi_reg.h>
#include <rbus/tve_dma_reg.h>
#include <rbus/mmc_reg.h>


#include <rbus/dc2h_vi_reg.h>

/*******************************ip's object************************************/
////////////////////////////////tvsb2///////////////////////////////////////////
/*diw*/
unsigned int update_tvsb2_diw_data_overflow(void){
    return (rtd_inl(DI_DDR_DMAStatus_reg) >> 15) & 0x1;
}
unsigned int update_tvsb2_diw_info_overflow (void ){
    return (rtd_inl(DI_DDR_DMAStatus_reg) >> 10) & 0x1;
}
#if 0
unsigned int update_tvsb2_diw_snr_overflow (void ){
    return ((rtd_inl(DI_MVF_DDR_DMAStatus_reg) & DI_MVF_DDR_DMAStatus_mvf_ovfl_mask)\
        >> DI_MVF_DDR_DMAStatus_mvf_ovfl_shift);
}
struct CFIFODataInfo tvsb2_diw_snr_overflow = {DMA_STATUS_OVERFLOW_2,0,\
    NULL,false,update_tvsb2_diw_snr_overflow};

struct CFIFODataInfo tvsb2_diw_info_overflow = {DMA_STATUS_OVERFLOW_1,0,\
    &tvsb2_diw_snr_overflow,false,update_tvsb2_diw_info_overflow};
#else
struct CFIFODataInfo tvsb2_diw_info_overflow = {DMA_STATUS_OVERFLOW_1,0,\
    NULL,false,update_tvsb2_diw_info_overflow};
#endif
struct CFIFODataInfo tvsb2_diw_data_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb2_diw_info_overflow,false,update_tvsb2_diw_data_overflow};
/*dir*/
unsigned int update_tvsb2_dir_data_overflow(void){
    return (rtd_inl(DI_DDR_DMAStatus_reg) >> 11) & 0xf;
}
unsigned int update_tvsb2_dir_info_overflow (void ){
    return (rtd_inl(DI_DDR_DMAStatus_reg) >> 8) & 0x3;
}
static struct CFIFODataInfo tvsb2_dir_info_overflow = {DMA_STATUS_OVERFLOW_1,0,\
    NULL,false,update_tvsb2_dir_info_overflow};
static struct CFIFODataInfo tvsb2_dir_data_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb2_dir_info_overflow,false,update_tvsb2_dir_data_overflow};
/*m-cap (w)*/
unsigned int update_tvsb2_m_cap_w_data_overflow(void){
        return (rtd_inl(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg) & \
        MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifoof_mask)>> \
        MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifoof_shift;
}
unsigned int update_tvsb2_m_cap_w_data_underflow(void){
    return (rtd_inl(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg) & \
        MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifouf_mask)>> \
        MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifouf_shift;
}
static struct CFIFODataInfo tvsb2_m_cap_w_data_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb2_m_cap_w_data_underflow};
static struct CFIFODataInfo tvsb2_m_cap_w_data_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb2_m_cap_w_data_underflow,false,update_tvsb2_m_cap_w_data_overflow};
/*m-disp (r)*/
unsigned int update_tvsb2_m_disp_r_data_overflow(void){
    return (rtd_inl(MDOMAIN_DISP_Disp_DDR_FIFOStatus_reg) & \
        MDOMAIN_DISP_Disp_DDR_FIFOStatus_main_fifoof_mask)>> \
        MDOMAIN_DISP_Disp_DDR_FIFOStatus_main_fifoof_shift;
}
unsigned int update_tvsb2_m_disp_r_data_underflow(void){
    return (rtd_inl(MDOMAIN_DISP_Disp_DDR_FIFOStatus_reg) & \
        MDOMAIN_DISP_Disp_DDR_FIFOStatus_main_fifouf_mask)>> \
        MDOMAIN_DISP_Disp_DDR_FIFOStatus_main_fifouf_shift;
}
static struct CFIFODataInfo tvsb2_m_disp_r_data_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb2_m_disp_r_data_underflow};
static struct CFIFODataInfo tvsb2_m_disp_r_data_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb2_m_disp_r_data_underflow,false,update_tvsb2_m_disp_r_data_overflow};
/*s-cap (w)*/
unsigned int update_tvsb2_s_cap_w_data_overflow(void){
    return (rtd_inl(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg) & \
        MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifoof_mask)>> \
        MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifoof_shift;
}
unsigned int update_tvsb2_s_cap_w_data_underflow(void){
    return (rtd_inl(MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg) & \
        MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifouf_mask)>> \
        MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifouf_shift;
}
static struct CFIFODataInfo tvsb2_s_cap_w_data_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb2_s_cap_w_data_underflow};
static struct CFIFODataInfo tvsb2_s_cap_w_data_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb2_s_cap_w_data_underflow,false,update_tvsb2_s_cap_w_data_overflow};
/*s-disp (r)*/
unsigned int update_tvsb2_s_disp_r_data_overflow(void){
    return (rtd_inl(MDOMAIN_DISP_Disp_DDR_FIFOStatus_reg) & \
        MDOMAIN_DISP_Disp_DDR_FIFOStatus_sub_fifoof_mask)>> \
        MDOMAIN_DISP_Disp_DDR_FIFOStatus_sub_fifoof_shift;
}
unsigned int update_tvsb2_s_disp_r_data_underflow(void){
    return (rtd_inl(MDOMAIN_DISP_Disp_DDR_FIFOStatus_reg) & \
        MDOMAIN_DISP_Disp_DDR_FIFOStatus_sub_fifouf_mask)>> \
        MDOMAIN_DISP_Disp_DDR_FIFOStatus_sub_fifouf_shift;
}
static struct CFIFODataInfo tvsb2_s_disp_r_data_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb2_s_disp_r_data_underflow};
static struct CFIFODataInfo tvsb2_s_disp_r_data_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb2_s_disp_r_data_underflow,false,update_tvsb2_s_disp_r_data_overflow};
/*vo1_y (r) ,vo1 c*/
unsigned int update_tvsb2_vo1_y_underflow(void){
    unsigned int val = rtd_inl(VODMA_VODMA_VGIP_INTST_reg);
    //RTICE_DEBUG("[%s:%d]Address=0x%x,Value=0x%x\r\n",__func__,__LINE__,VODMA_VODMA_VGIP_INTST,val);
    val = val & VODMA_VODMA_VGIP_INTST_buf_underflow_ints1_mask;
    val = val >> VODMA_VODMA_VGIP_INTST_buf_underflow_ints1_shift;
    //RTICE_DEBUG("[%s:%d]vo1_y_underflow=0x%x\r\n",__func__,__LINE__,val);
    return val;
}
static struct CFIFODataInfo tvsb2_vo1_y_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb2_vo1_y_underflow};
/*vo2 y,vo2 c*/
unsigned int update_tvsb2_vo2_y_underflow(void){
    return (rtd_inl(VODMA2_VODMA2_VGIP_INTST_reg) & \
        VODMA2_VODMA2_VGIP_INTST_buf_underflow_ints1_mask)>> \
        VODMA2_VODMA2_VGIP_INTST_buf_underflow_ints1_shift;
}
static struct CFIFODataInfo tvsb2_vo2_y_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb2_vo2_y_underflow};
/*i3ddma*/
unsigned int update_tvsb2_i3ddma_overflow(void){
    return (rtd_inl(H3DDMA_Cap_Status_reg) & \
        H3DDMA_Cap_Status_cap_fifo_overflow_mask)>> \
        H3DDMA_Cap_Status_cap_fifo_overflow_shift;
}
unsigned int update_tvsb2_i3ddma_underflow(void){
    return (rtd_inl(H3DDMA_Cap_Status_reg) & \
        H3DDMA_Cap_Status_cap_fifo_underflow_mask)>> \
        H3DDMA_Cap_Status_cap_fifo_underflow_shift;
}
static struct CFIFODataInfo tvsb2_i3ddma_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb2_i3ddma_underflow};
static struct CFIFODataInfo tvsb2_i3ddma_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb2_i3ddma_underflow,false,update_tvsb2_i3ddma_overflow};
/*de_xc w*/
unsigned int update_tvsb2_de_xc_wdata_overflow(void){
    return (rtd_inl(DE_XCXL_DE_XCXL_DMAStatus_reg)>>9) & 0x1;
}
unsigned int update_tvsb2_de_xc_wdata_underflow(void){
    return (rtd_inl(DE_XCXL_DE_XCXL_DMAStatus_reg)>>4) & 0x1;
}
unsigned int update_tvsb2_de_xc_winfo_overflow(void){   
    return (rtd_inl(DE_XCXL_DE_XCXL_DMAStatus_reg)>>6) & 0x1;
}
unsigned int update_tvsb2_de_xc_winfo_underflow(void){   
    return (rtd_inl(DE_XCXL_DE_XCXL_DMAStatus_reg)>>1) & 0x1;
}
static struct CFIFODataInfo tvsb2_de_xc_winfo_underflow = {DMA_STATUS_UNDERFLOW_1,0,\
    NULL,false,update_tvsb2_de_xc_winfo_underflow};
static struct CFIFODataInfo tvsb2_de_xc_winfo_overflow = {DMA_STATUS_OVERFLOW_1,0,\
    &tvsb2_de_xc_winfo_underflow,false,update_tvsb2_de_xc_winfo_overflow};
static struct CFIFODataInfo tvsb2_de_xc_wdata_underflow = {DMA_STATUS_UNDERFLOW,0,\
    &tvsb2_de_xc_winfo_overflow,false,update_tvsb2_de_xc_wdata_underflow};
static struct CFIFODataInfo tvsb2_de_xc_wdata_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb2_de_xc_wdata_underflow,false,update_tvsb2_de_xc_wdata_overflow};

/*de_xc r*/
unsigned int update_tvsb2_de_xc_rdata0_overflow(void){
    return (rtd_inl(DE_XCXL_DE_XCXL_DMAStatus_reg)>>7) & 0x1;
}
unsigned int update_tvsb2_de_xc_rdata0_underflow(void){
    return (rtd_inl(DE_XCXL_DE_XCXL_DMAStatus_reg)>>2) & 0x1;
}
unsigned int update_tvsb2_de_xc_rdata1_overflow(void){
        return (rtd_inl(DE_XCXL_DE_XCXL_DMAStatus_reg)>>8) & 0x1;
}
unsigned int update_tvsb2_de_xc_rdata1_underflow(void){
        return (rtd_inl(DE_XCXL_DE_XCXL_DMAStatus_reg)>>3) & 0x1;
}
unsigned int update_tvsb2_de_xc_rinfo_overflow(void){
        return (rtd_inl(DE_XCXL_DE_XCXL_DMAStatus_reg)>>5) & 0x1;
}
unsigned int update_tvsb2_de_xc_rinfo_underflow(void){
        return (rtd_inl(DE_XCXL_DE_XCXL_DMAStatus_reg)>>0) & 0x1;
}
static struct CFIFODataInfo tvsb2_de_xc_rinfo_underflow = {DMA_STATUS_UNDERFLOW_2,0,\
    NULL,false,update_tvsb2_de_xc_rinfo_underflow};
static struct CFIFODataInfo tvsb2_de_xc_rinfo_overflow = {DMA_STATUS_OVERFLOW_2,0,\
    &tvsb2_de_xc_rinfo_underflow,false,update_tvsb2_de_xc_rinfo_overflow};
static struct CFIFODataInfo tvsb2_de_xc_rdata1_underflow = {DMA_STATUS_UNDERFLOW_1,0,\
    &tvsb2_de_xc_rinfo_overflow,false,update_tvsb2_de_xc_rdata1_underflow};
static struct CFIFODataInfo tvsb2_de_xc_rdata1_overflow = {DMA_STATUS_OVERFLOW_1,0,\
    &tvsb2_de_xc_rdata1_underflow,false,update_tvsb2_de_xc_rdata1_overflow};
static struct CFIFODataInfo tvsb2_de_xc_rdata0_underflow = {DMA_STATUS_UNDERFLOW,0,\
    &tvsb2_de_xc_rdata1_overflow,false,update_tvsb2_de_xc_rdata0_underflow};
static struct CFIFODataInfo tvsb2_de_xc_rdata0_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb2_de_xc_rdata0_underflow,false,update_tvsb2_de_xc_rdata0_overflow};
//snr(r)
#if 0
unsigned int update_tvsb2_snr_r_underflow(void){
    return (rtd_inl(IEDGE_SMOOTH_MVF_DMA_Err_Status_reg) & \
        IEDGE_SMOOTH_MVF_DMA_Err_Status_dma_fifo_unfl_mask)>> \
        IEDGE_SMOOTH_MVF_DMA_Err_Status_dma_fifo_unfl_shift;
}
static struct CFIFODataInfo tvsb2_snr_r_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb2_snr_r_underflow};
#endif
////////////////////////////////tvsb1///////////////////////////////////////////
/*vd*/
unsigned int update_tvsb1_vd_underflow(void){
    return (rtd_inl(VDPQ_DMA_CTRL5_reg) >>3) & 0x1f;
}
static struct CFIFODataInfo tvsb1_vd_underflow = {DMA_STATUS_OVER_UNDER_FLOW,0,\
    NULL,false,update_tvsb1_vd_underflow};
/*audio*/
unsigned int update_tvsb1_audio_overflow(void){
    return (rtd_inl(AUDIO_ADMA_CSR_reg)  & 0x0f);
}
static struct CFIFODataInfo tvsb1_audio_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_tvsb1_audio_overflow};
/*audio2*/
unsigned int update_tvsb1_audio2_overflow_0(void){
    return (rtd_inl(AUDIO_ARC_ADMA_CSR_reg)  & 0x0f);
}
unsigned int update_tvsb1_audio2_overflow_1(void){
    return (rtd_inl(AUDIO_TSADMA_CSR_reg)  & 0x0f);
}
static struct CFIFODataInfo tvsb1_audio2_overflow_1 = {DMA_STATUS_OVERFLOW_1,0,\
    NULL,false,update_tvsb1_audio2_overflow_1};
static struct CFIFODataInfo tvsb1_audio2_overflow_0 = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb1_audio2_overflow_1,false,update_tvsb1_audio2_overflow_0};
/*VBI*/
unsigned int update_tvsb1_vbi_overflow(void){
    return ((rtd_inl(VBI_VBI_DMA_CTRL_reg) >> 3) & 0x1);
}
static struct CFIFODataInfo tvsb1_vbi_overflow = {DMA_STATUS_OVER_UNDER_FLOW,0,\
    NULL,false,update_tvsb1_vbi_overflow};
/*TVE-VD*/
unsigned int update_tvsb1_tve_vd_overflow(void){
    return ((rtd_inl(TVE_DMA_TVEDMA_FIFOSTATUS_reg) >> 1) & 0x1);
}
static struct CFIFODataInfo tvsb1_tve_vd_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_tvsb1_tve_vd_overflow};
/*TVE-VBI*/
unsigned int update_tvsb1_tve_vbi_overflow(void){
    return ((rtd_inl(TVE_DMA_TVEDMA_FIFOSTATUS_reg) >> 5) & 0x1);
}
static struct CFIFODataInfo tvsb1_tve_vbi_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_tvsb1_tve_vbi_overflow};
////////////////////////////////sb1///////////////////////////////////////////
/*EMMC*/
unsigned int update_sb1_emmc_overflow(void){
    return ((rtd_inl(0xb8010948) >>2) & 0x3);
}
static struct CFIFODataInfo sb1_emmc_overflow = {DMA_STATUS_OVER_UNDER_FLOW,0,\
    NULL,false,update_sb1_emmc_overflow};
////////////////////////////////sb3///////////////////////////////////////////
/*MD*/
unsigned int update_sb3_md_overflow(void){
    return ((rtd_inl(0xb800b230) >>5) & 0x1);
}
static struct CFIFODataInfo sb3_md_overflow = {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_sb3_md_overflow};
////////////////////////////////tvsb3///////////////////////////////////////////
/*OSD_OFF1-5*/
unsigned int update_tvsb3_osd_off1_5_underflow(void){
    return ((rtd_inl(0xb802FC10) >>1) & 0x3f);
}
static struct CFIFODataInfo tvsb3_osd_off1_5_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb3_osd_off1_5_underflow};
////////////////////////////////tvsb5///////////////////////////////////////////
/*PST*/
unsigned int update_tvsb5_pst_underflow(void){
#ifdef USE_MERLINE_SIMULATE_MERLINE2
    return 0x9;
#else
    return ((rtd_inl(PST_I2RND_DEBUG0_reg) >>8) & 0x1);
#endif
}
static struct CFIFODataInfo tvsb5_pst_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb5_pst_underflow};
////////////////////////////////tvsb4///////////////////////////////////////////
/*OD(W)*/
unsigned int update_tvsb4_odw_overflow_0(void){
    return ((rtd_inl(OD_DMA_ODDMA_Cap_Status_reg) >>2) & 0x1);
}
#if 0
unsigned int update_tvsb4_odw_overflow_1(void){
    return ((rtd_inl(OD_DMA_ODDMA_Cap1_Status_reg) >>2) & 0x1);
}
static struct CFIFODataInfo tvsb4_odw_overflow_1 = {DMA_STATUS_OVERFLOW_1,0,\
    NULL,false,update_tvsb4_odw_overflow_1};
static struct CFIFODataInfo tvsb4_odw_overflow_0 = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb4_odw_overflow_1,false,update_tvsb4_odw_overflow_0};
#else
static struct CFIFODataInfo tvsb4_odw_overflow_0 = {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_tvsb4_odw_overflow_0};
#endif
/*OD(R)*/
unsigned int update_tvsb4_odr_underflow_0(void){
    return ((rtd_inl(OD_DMA_ODDMA_Display_Status1_reg) >>2) & 0x1);
}
unsigned int update_tvsb4_odr_underflow_1(void){
    return ((rtd_inl(OD_DMA_ODDMA_Display_Status1_reg) >>2) & 0x1);
}
static struct CFIFODataInfo tvsb4_odr_underflow_1 = {DMA_STATUS_UNDERFLOW_1,0,\
    NULL,false,update_tvsb4_odr_underflow_1};
static struct CFIFODataInfo tvsb4_odr_underflow_0 = {DMA_STATUS_UNDERFLOW,0,\
    &tvsb4_odr_underflow_1,false,update_tvsb4_odr_underflow_0};
/*DC2H*/
unsigned int update_tvsb4_dc2h_overflow(void){
    return ((rtd_inl(DC2H_VI_DC2H_INTST_reg) & DC2H_VI_DC2H_INTST_dma_fifo_of_mask)\
        >> DC2H_VI_DC2H_INTST_dma_fifo_of_shift);
}
unsigned int update_tvsb4_dc2h_underflow(void){
    return ((rtd_inl(DC2H_VI_DC2H_INTST_reg) & DC2H_VI_DC2H_INTST_dma_fifo_uf_mask) >> DC2H_VI_DC2H_INTST_dma_fifo_uf_shift);
}
static struct CFIFODataInfo  tvsb4_dc2h_underflow= {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb4_dc2h_underflow};
static struct CFIFODataInfo tvsb4_dc2h_overflow  = {DMA_STATUS_OVERFLOW_0,0,\
    &tvsb4_dc2h_underflow,false,update_tvsb4_dc2h_overflow};
/*subtitle*/
unsigned int update_tvsb4_subtitle_underflow(void){
    return ((rtd_inl(0xb802f0d8) >>14) & 0x1);
}
static struct CFIFODataInfo tvsb4_subtitle_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb4_subtitle_underflow};
/*osd1-5*/
unsigned int update_tvsb4_osd_1_5_underflow(void){
    return ((rtd_inl(0xb802fc10) >>1) & 0x3f);
}
static struct CFIFODataInfo tvsb4_osd_1_5_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb4_osd_1_5_underflow};
#if 0
/*demura*/
unsigned int update_tvsb4_demura_underflow(void){
    return ((rtd_inl(DEMURA_DEMURA_DMA_STATUS_reg)  & DEMURA_DEMURA_DMA_STATUS_fifo_underflow_mask)\
        >> DEMURA_DEMURA_DMA_STATUS_fifo_underflow_shift);
}
static struct CFIFODataInfo tvsb4_demura_underflow = {DMA_STATUS_UNDERFLOW,0,\
    NULL,false,update_tvsb4_demura_underflow};
#endif
#if 0
////////////////////////////////MEMC///////////////////////////////////////////
/*ME0*/
unsigned int update_memc_me0_overflow(void){
    return (rtd_inl(0xb80930f8) >>25) & 0x1;
}
static struct CFIFODataInfo memc_me0_overflow= {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_memc_me0_overflow};
/*ME4*/
unsigned int update_memc_me4_overflow(void){
    return (rtd_inl(0xb80930f8) >>26) & 0x1;
}
static struct CFIFODataInfo memc_me4_overflow= {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_memc_me4_overflow};
/*ME5*/
unsigned int update_memc_me5_overflow(void){
    return (rtd_inl(0xb80930f8) >>27) & 0x1;
}
static struct CFIFODataInfo memc_me5_overflow= {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_memc_me5_overflow};
/*ME8*/
unsigned int update_memc_me8_overflow(void){
    return (rtd_inl(0xb80930f8) >>28) & 0x1;
}
static struct CFIFODataInfo memc_me8_overflow= {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_memc_me8_overflow};
/*ME10*/
unsigned int update_memc_me10_overflow(void){
    return (rtd_inl(0xb80930f8) >>29) & 0x1;
}
static struct CFIFODataInfo memc_me10_overflow= {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_memc_me10_overflow};
/*ME12*/
unsigned int update_memc_me12_overflow(void){
    return (rtd_inl(0xb80930f8) >>30) & 0x1;
}
static struct CFIFODataInfo memc_me12_overflow= {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_memc_me12_overflow};
/*ME14*/
unsigned int update_memc_me14_overflow(void){
    return (rtd_inl(0xb80930f8) >>31) & 0x1;
}
static struct CFIFODataInfo memc_me14_overflow= {DMA_STATUS_OVERFLOW_0,0,\
    NULL,false,update_memc_me14_overflow};
#endif
#endif
