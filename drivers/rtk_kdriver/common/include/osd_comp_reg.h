/**************************************************************
// Spec Version                  : 1.5
// Parser Version                : DVR_Parser_6.3
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014-1-2 15:17:38
***************************************************************/


#ifndef _OSDCOMP_REG_H_INCLUDED_
#define _OSDCOMP_REG_H_INCLUDED_
typedef union
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:15;
        unsigned int     software_abort:1;
        unsigned int     reserved_1:7;
        unsigned int     osd_prog_done:1;
        unsigned int     reserved_2:3;
        unsigned int     go:1;
        unsigned int     blend:1;
        unsigned int     d3_mode:1;
        unsigned int     gating_enable:1;
        unsigned int     write_data:1;
    };
}osdcomp_ctrl_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:12;
        unsigned int     vs_yodd:1;
        unsigned int     vs_codd:1;
        unsigned int     hs_yodd:1;
        unsigned int     hs_codd:1;
        unsigned int     reserved_1:1;
        unsigned int     vs:1;
        unsigned int     vs_near:1;
        unsigned int     hs:1;
        unsigned int     reserved_2:2;
        unsigned int     clear_region_en:1;
        unsigned int     plane_alpha_en:1;
        unsigned int     reserved_3:1;
        unsigned int     wi_endian:1;
        unsigned int     d3_dbw:1;
        unsigned int     d3_dup:1;
        unsigned int     reserved_4:1;
        unsigned int     rotate:1;
        unsigned int     en:1;
        unsigned int     write_data:1;
    };
}osdcomp_osd1_ctrl_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     a:32;
    };
}osdcomp_osd1_wi_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        unsigned int     a:32;
    };
}osdcomp_osd1_wi_3d_RBUS;

typedef union
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     w:13;
        unsigned int     reserved_1:3;
        unsigned int     h:13;
    };
}osdcomp_osd1_size_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     x_sta:13;
        unsigned int     reserved_1:3;
        unsigned int     x_end:13;
    };
}osdcomp_osd1_clear1_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     y_sta:13;
        unsigned int     reserved_1:3;
        unsigned int     y_end:13;
    };
}osdcomp_osd1_clear2_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     plane_alpha_a:8;
        unsigned int     plane_alpha_r:8;
        unsigned int     plane_alpha_g:8;
        unsigned int     plane_alpha_b:8;
    };
}osdcomp_osd1_plane_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     offset:13;
        unsigned int     phase:14;
        unsigned int     reserved_1:2;
    }
}osdcomp_osd1_vsi_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:19;
        unsigned int     out:13;
    };
}osdcomp_osd1_vsd_out_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:1;
        unsigned int     reserved_1:11;
        unsigned int     reserved_2:1;
        unsigned int     delta:19;
    };
}osdcomp_osd1_vsd_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:2;
        unsigned int     c1:14;
        unsigned int     reserved_1:2;
        unsigned int     c0:14;
    };
}osdcomp_osd1_vsyc_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     offset:13;
        unsigned int     phase:14;
        unsigned int     reserved_1:2;
    };
}osdcomp_osd1_hsi_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:19;
        unsigned int     out:13;
    };
}osdcomp_osd1_hsd_out_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:1;
        unsigned int     reserved_1:11;
        unsigned int     reserved_2:1;
        unsigned int     delta:19;
    };
}osdcomp_osd1_hsd_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:2;
        unsigned int     c1:14;
        unsigned int     reserved_1:2;
        unsigned int     c0:14;
    };
}osdcomp_osd1_hsyc_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:22;
        unsigned int     clear_region_en:1;
        unsigned int     plane_alpha_en:1;
        unsigned int     reserved_1:1;
        unsigned int     wi_endian:1;
        unsigned int     d3_dbw:1;
        unsigned int     d3_dup:1;
        unsigned int     reserved_2:1;
        unsigned int     rotate:1;
        unsigned int     en:1;
        unsigned int     write_data:1;
    };
}osdcomp_osd2_ctrl_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     a:32;
    };
}osdcomp_osd2_wi_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     a:32;
    };
}osdcomp_osd2_wi_3d_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     w:13;
        unsigned int     reserved_1:3;
        unsigned int     h:13;
    };
}osdcomp_osd2_size_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     x_sta:13;
        unsigned int     reserved_1:3;
        unsigned int     x_end:13;
    };
}osdcomp_osd2_clear1_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     y_sta:13;
        unsigned int     reserved_1:3;
        unsigned int     y_end:13;
    };
}osdcomp_osd2_clear2_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     plane_alpha_a:8;
        unsigned int     plane_alpha_r:8;
        unsigned int     plane_alpha_g:8;
        unsigned int     plane_alpha_b:8;
    };
}osdcomp_osd2_plane_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:22;
        unsigned int     clear_region_en:1;
        unsigned int     plane_alpha_en:1;
        unsigned int     reserved_1:1;
        unsigned int     wi_endian:1;
        unsigned int     d3_dbw:1;
        unsigned int     d3_dup:1;
        unsigned int     reserved_2:1;
        unsigned int     rotate:1;
        unsigned int     en:1;
        unsigned int     write_data:1;
    };
}osdcomp_osd3_ctrl_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     a:32;
    };
}osdcomp_osd3_wi_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     a:32;
    };
}osdcomp_osd3_wi_3d_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     w:13;
        unsigned int     reserved_1:3;
        unsigned int     h:13;
    };
}osdcomp_osd3_size_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     x_sta:13;
        unsigned int     reserved_1:3;
        unsigned int     x_end:13;
    };
}osdcomp_osd3_clear1_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     y_sta:13;
        unsigned int     reserved_1:3;
        unsigned int     y_end:13;
    };
}osdcomp_osd3_clear2_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     plane_alpha_a:8;
        unsigned int     plane_alpha_r:8;
        unsigned int     plane_alpha_g:8;
        unsigned int     plane_alpha_b:8;
    };
}osdcomp_osd3_plane_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     blend_mode:3;
        unsigned int     w:13;
        unsigned int     reserved_0:3;
        unsigned int     h:13;
    };
}osdcomp_blend_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     x:13;
        unsigned int     reserved_1:3;
        unsigned int     y:13;
    };
}osdcomp_blend_osd1_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     x:13;
        unsigned int     reserved_1:3;
        unsigned int     y:13;
    };
}osdcomp_blend_osd2_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:3;
        unsigned int     x:13;
        unsigned int     reserved_1:3;
        unsigned int     y:13;
    };
}osdcomp_blend_osd3_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:2;
        unsigned int     k1:6;
        unsigned int     reserved_1:2;
        unsigned int     k2:6;
        unsigned int     reserved_2:2;
        unsigned int     k3:6;
        unsigned int     reserved_3:2;
        unsigned int     k4:6;
    };
}osdcomp_blend_factor1_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:2;
        unsigned int     k5:6;
        unsigned int     reserved_1:2;
        unsigned int     k6:6;
        unsigned int     reserved_2:2;
        unsigned int     k7:6;
        unsigned int     reserved_3:2;
        unsigned int     k8:6;
    };
}osdcomp_blend_factor2_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:2;
        unsigned int     osd3_bl:6;
        unsigned int     reserved_1:2;
        unsigned int     wdma_bl:6;
        unsigned int     reserved_2:2;
        unsigned int     osd1_bl:6;
        unsigned int     mult_req:2;
        unsigned int     osd2_bl:6;
    };
}osdcomp_dma_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:8;
        unsigned int     osd1:12;
        unsigned int     reserved_1:12;
    };
}osdcomp_dma_wl_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:8;
        unsigned int     num:24;
    };
}osdcomp_osd1_seg0_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:8;
        unsigned int     num:24;
    };
}osdcomp_osd1_seg0_3d_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     a:32;
    };
}osdcomp_wdma_adr_seg0_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     a:32;
    };
}osdcomp_wdma_adr_seg0_3d_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     size:32;
    };
}osdcomp_wdma_seg0_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     size:32;
    };
}osdcomp_wdma_seg0_3d_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:30;
        unsigned int     conti:1;
        unsigned int     start:1;
    };
}osdcomp_wdma_crc_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     result:32;
    };
}osdcomp_wdma_seg0_crc_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:12;
        unsigned int     osd3_1b:1;
        unsigned int     osd3_2b:1;
        unsigned int     osd3_4b:1;
        unsigned int     osd3_8b:1;
        unsigned int     osd1_1b:1;
        unsigned int     osd1_2b:1;
        unsigned int     osd1_4b:1;
        unsigned int     osd1_8b:1;
        unsigned int     osd2_1b:1;
        unsigned int     osd2_2b:1;
        unsigned int     osd2_4b:1;
        unsigned int     osd2_8b:1;
        unsigned int     w_1b:1;
        unsigned int     w_2b:1;
        unsigned int     w_4b:1;
        unsigned int     w_8b:1;
        unsigned int     reserved_1:3;
        unsigned int     write_data:1;
    };
}osdcomp_dma_swap_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:18;
        unsigned int     wdma_ovfl:1;
        unsigned int     wdma_udfl:1;
        unsigned int     reserved_1:4;
        unsigned int     reserved_2:2;
        unsigned int     reserved_3:1;
        unsigned int     reserved_4:1;
        unsigned int     reserved_5:2;
        unsigned int     done:1;
        unsigned int     write_data:1;
    };
}osdcomp_inten_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:18;
        unsigned int     wdma_ovfl:1;
        unsigned int     wdma_udfl:1;
        unsigned int     reserved_1:4;
        unsigned int     reserved_2:2;
        unsigned int     reserved_3:1;
        unsigned int     reserved_4:1;
        unsigned int     reserved_5:2;
        unsigned int     done:1;
        unsigned int     write_data:1;
    };
}osdcomp_intst_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:6;
        unsigned int     reserved_1:2;
        unsigned int     cmp_width:8;
        unsigned int     cmp_height:16;
    };
}osdcomp_cmp_resolution_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     cmp_a_ch_mark:1;
        unsigned int     cmp_444to422_en:1;
        unsigned int     cmp_RGB_YC_sel:1;
        unsigned int     cmp_channel_bits:1;
        unsigned int     reserved_0:10;
        unsigned int     max_pixel_bits:6;
        unsigned int     short_term_bits:6;
        unsigned int     frame_bits:6;
    };
}osdcomp_cmp_setting_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:26;
        unsigned int     not_segment_status_clr:1;
        unsigned int     pixel_num_status_clr:1;
        unsigned int     over_bits_status_clr:1;
        unsigned int     comp_irq_en:3;
    };
}osdcomp_cmp_inten_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:28;
        unsigned int     comp_irq:1;
        unsigned int     comp_status:3;
    };
}osdcomp_cmp_intst_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:1;
        unsigned int     decmp_switch:3;
        unsigned int     reserved_1:2;
        unsigned int     reserved_2:2;
        unsigned int     decmp_width:8;
        unsigned int     decmp_height:16;
    };
}osdcomp_decmp_resolution_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:14;
        unsigned int     a_sat_en:1;
        unsigned int     b_cb_sat_en:1;
        unsigned int     g_Y_sat_en:1;
        unsigned int     r_cr_sat_en:1;
        unsigned int     decmp_frame_bits:6;
        unsigned int     reserved_1:2;
        unsigned int     decmp_a_ch_mark:1;
        unsigned int     decmp_444to422_en:1;
        unsigned int     decmp_RGB_YC_sel:1;
        unsigned int     decmp_channel_bits:1;
        unsigned int     decmp_CbCr_recov:1;
        unsigned int     decmp_fl_mode:1;
    };
}osdcomp_decmp_setting_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:22;
        unsigned int     mark_en_9:1;
        unsigned int     mark_en_8:1;
        unsigned int     mark_en_7:1;
        unsigned int     mark_en_6:1;
        unsigned int     mark_en_5:1;
        unsigned int     mark_en_4:1;
        unsigned int     mark_en_3:1;
        unsigned int     mark_en_2:1;
        unsigned int     mark_en_1:1;
        unsigned int     mark_en_0:1;
    };
}osdcomp_trunc_mark_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     mark_color_0:16;
        unsigned int     mark_color_1:16;
    };
}osdcomp_trunc_color_0_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     mark_color_2:16;
        unsigned int     mark_color_3:16;
    };
}osdcomp_trunc_color_1_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     mark_color_4:16;
        unsigned int     mark_color_5:16;
    };
}osdcomp_trunc_color_2_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     mark_color_6:16;
        unsigned int     mark_color_7:16;
    };
}osdcomp_trunc_color_3_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     mark_color_8:16;
        unsigned int     mark_color_9:16;
    };
}osdcomp_trunc_color_4_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:4;
        unsigned int     reserved_1:4;
        unsigned int     reserved_2:4;
        unsigned int     frm_cnt_0:4;
        unsigned int     reserved_3:4;
        unsigned int     reserved_4:4;
        unsigned int     reserved_5:4;
        unsigned int     max_truncation_0:4;
    };
}osdcomp_frame_inst_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{
        unsigned int     reserved_0:14;
        unsigned int     decomp_support_error_clr:1;
        unsigned int     decomp_support_error_irq_en:1;
        unsigned int     reserved_1:6;
        unsigned int     head_error_clr:1;
        unsigned int     pix_fifo_underflow_clr:1;
        unsigned int     reserved_2:3;
        unsigned int     head_error_irq_en:1;
        unsigned int     reserved_3:3;
        unsigned int     underflow_irq_en:1;
    };
}osdcomp_decomp_inten_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:13;
        unsigned int     decomp_support_error:3;
        unsigned int     reserved_1:7;
        unsigned int     decomp_irq:1;
        unsigned int     reserved_2:3;
        unsigned int     head_error:1;
        unsigned int     reserved_3:3;
        unsigned int     pix_fifo_underflow:1;
    };
}osdcomp_decomp_intst_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:30;
        unsigned int     conti:1;
        unsigned int     start:1;
    };
}osdcomp_decomp_crc_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     result:32;
    };
}osdcomp_decomp_seg0_crc_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:7;
        unsigned int     write_en3:1;
        unsigned int     sel1:8;
        unsigned int     reserved_1:3;
        unsigned int     write_en2:1;
        unsigned int     sel0:8;
        unsigned int     reserved_2:2;
        unsigned int     write_en1:1;
        unsigned int     en:1;
    };
}osdcomp_dbg_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:14;
        unsigned int     sel:2;
        unsigned int     mux:8;
        unsigned int     reserved_1:8;
    };
}osdcomp_decomp_debug_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     wdma_wptr:7;
        unsigned int     wdma_rptr:7;
        unsigned int     wdma_seg0_last_req:1;
        unsigned int     wdma_seg1_last_req:1;
        unsigned int     wdma_seg2_last_req:1;
        unsigned int     wdma_seg3_last_req:1;
        unsigned int     wdma_seg0_last_in:1;
        unsigned int     wdma_seg1_last_in:1;
        unsigned int     wdma_seg2_last_in:1;
        unsigned int     wdma_seg3_last_in:1;
        unsigned int     wdma_dct_st:3;
        unsigned int     reserved_0:7;
    };
}osdcomp_status_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:14;
        unsigned int     comp_height_cnt:18;
    };
}osdcomp_comp_status_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:26;
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:1;
        unsigned int     rbuf:1;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf:1;
    };
}osdcomp_bist_mode_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:26;
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:1;
        unsigned int     rbuf:1;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf:1;
    };
}osdcomp_bist_done_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:26;
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:1;
        unsigned int     rbuf:1;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf:1;
    };
}osdcomp_mbist_fail_group_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:26;
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:1;
        unsigned int     rbuf:1;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf:1;
    };
}osdcomp_drf_bist_mode_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:26;
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:1;
        unsigned int     rbuf:1;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf:1;
    };
}osdcomp_drf_test_resume_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:26;
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:1;
        unsigned int     rbuf:1;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf:1;
    };
}osdcomp_drf_bist_done_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:26;
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:1;
        unsigned int     rbuf:1;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf:1;
    };
}osdcomp_drf_start_pause_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:26;
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:1;
        unsigned int     rbuf:1;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf:1;
    };
}osdcomp_mbist_drf_fail_group_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:13;
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:8;
        unsigned int     rbuf:6;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf:2;
    };
}osdcomp_mbist_fail_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     reserved_0:13;
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:8;
        unsigned int     rbuf:6;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf:2;
    };
}osdcomp_mbist_drf_fail_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     revise_d3_dup_bug:1;
        unsigned int     dummy:3;
        unsigned int     decomp:4;
        unsigned int     comp:4;
        unsigned int     osd1:4;
        unsigned int     rbuf:4;
        unsigned int     dmabuf:4;
        unsigned int     dispbuf0:4;
        unsigned int     dispbuf1:4;
    };
}osdcomp_comp_mbist_rm_RBUS;

typedef union 
{
    uint32_t regValue;
    struct{    
        unsigned int     decomp:1;
        unsigned int     comp:1;
        unsigned int     osd1:1;
        unsigned int     rbuf:1;
        unsigned int     dmabuf:1;
        unsigned int     dispbuf0:1;
        unsigned int     dispbuf1:1;
        unsigned int     dummy:25;
    };
}osdcomp_comp_mbist_rme_RBUS;


#define OSDCOMP_CTRL                                                                 0x18031000
#define OSDCOMP_CTRL_reg_addr                                                        "0xB8031000"
#define OSDCOMP_CTRL_reg                                                             0xB8031000
#define set_OSDCOMP_CTRL_reg(data)   (*((volatile unsigned int*) OSDCOMP_CTRL_reg)=data)
#define get_OSDCOMP_CTRL_reg   (*((volatile unsigned int*) OSDCOMP_CTRL_reg))
#define OSDCOMP_CTRL_inst_adr                                                        "0x0000"
#define OSDCOMP_CTRL_inst                                                            0x0000
#define OSDCOMP_CTRL_software_abort_shift                                            (16)
#define OSDCOMP_CTRL_software_abort_mask                                             (0x00010000)
#define OSDCOMP_CTRL_software_abort(data)                                            (0x00010000&((data)<<16))
#define OSDCOMP_CTRL_software_abort_src(data)                                        ((0x00010000&(data))>>16)
#define OSDCOMP_CTRL_get_software_abort(data)                                        ((0x00010000&(data))>>16)
#define OSDCOMP_CTRL_osd_prog_done_shift                                             (8)
#define OSDCOMP_CTRL_osd_prog_done_mask                                              (0x00000100)
#define OSDCOMP_CTRL_osd_prog_done(data)                                             (0x00000100&((data)<<8))
#define OSDCOMP_CTRL_osd_prog_done_src(data)                                         ((0x00000100&(data))>>8)
#define OSDCOMP_CTRL_get_osd_prog_done(data)                                         ((0x00000100&(data))>>8)
#define OSDCOMP_CTRL_go_shift                                                        (4)
#define OSDCOMP_CTRL_go_mask                                                         (0x00000010)
#define OSDCOMP_CTRL_go(data)                                                        (0x00000010&((data)<<4))
#define OSDCOMP_CTRL_go_src(data)                                                    ((0x00000010&(data))>>4)
#define OSDCOMP_CTRL_get_go(data)                                                    ((0x00000010&(data))>>4)
#define OSDCOMP_CTRL_blend_shift                                                     (3)
#define OSDCOMP_CTRL_blend_mask                                                      (0x00000008)
#define OSDCOMP_CTRL_blend(data)                                                     (0x00000008&((data)<<3))
#define OSDCOMP_CTRL_blend_src(data)                                                 ((0x00000008&(data))>>3)
#define OSDCOMP_CTRL_get_blend(data)                                                 ((0x00000008&(data))>>3)
#define OSDCOMP_CTRL_d3_mode_shift                                                   (2)
#define OSDCOMP_CTRL_d3_mode_mask                                                    (0x00000004)
#define OSDCOMP_CTRL_d3_mode(data)                                                   (0x00000004&((data)<<2))
#define OSDCOMP_CTRL_d3_mode_src(data)                                               ((0x00000004&(data))>>2)
#define OSDCOMP_CTRL_get_d3_mode(data)                                               ((0x00000004&(data))>>2)
#define OSDCOMP_CTRL_gating_enable_shift                                             (1)
#define OSDCOMP_CTRL_gating_enable_mask                                              (0x00000002)
#define OSDCOMP_CTRL_gating_enable(data)                                             (0x00000002&((data)<<1))
#define OSDCOMP_CTRL_gating_enable_src(data)                                         ((0x00000002&(data))>>1)
#define OSDCOMP_CTRL_get_gating_enable(data)                                         ((0x00000002&(data))>>1)
#define OSDCOMP_CTRL_write_data_shift                                                (0)
#define OSDCOMP_CTRL_write_data_mask                                                 (0x00000001)
#define OSDCOMP_CTRL_write_data(data)                                                (0x00000001&((data)<<0))
#define OSDCOMP_CTRL_write_data_src(data)                                            ((0x00000001&(data))>>0)
#define OSDCOMP_CTRL_get_write_data(data)                                            ((0x00000001&(data))>>0)


#define OSDCOMP_OSD1_CTRL                                                            0x18031010
#define OSDCOMP_OSD1_CTRL_reg_addr                                                   "0xB8031010"
#define OSDCOMP_OSD1_CTRL_reg                                                        0xB8031010
#define set_OSDCOMP_OSD1_CTRL_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_CTRL_reg)=data)
#define get_OSDCOMP_OSD1_CTRL_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_CTRL_reg))
#define OSDCOMP_OSD1_CTRL_inst_adr                                                   "0x0004"
#define OSDCOMP_OSD1_CTRL_inst                                                       0x0004
#define OSDCOMP_OSD1_CTRL_vs_yodd_shift                                              (19)
#define OSDCOMP_OSD1_CTRL_vs_yodd_mask                                               (0x00080000)
#define OSDCOMP_OSD1_CTRL_vs_yodd(data)                                              (0x00080000&((data)<<19))
#define OSDCOMP_OSD1_CTRL_vs_yodd_src(data)                                          ((0x00080000&(data))>>19)
#define OSDCOMP_OSD1_CTRL_get_vs_yodd(data)                                          ((0x00080000&(data))>>19)
#define OSDCOMP_OSD1_CTRL_vs_codd_shift                                              (18)
#define OSDCOMP_OSD1_CTRL_vs_codd_mask                                               (0x00040000)
#define OSDCOMP_OSD1_CTRL_vs_codd(data)                                              (0x00040000&((data)<<18))
#define OSDCOMP_OSD1_CTRL_vs_codd_src(data)                                          ((0x00040000&(data))>>18)
#define OSDCOMP_OSD1_CTRL_get_vs_codd(data)                                          ((0x00040000&(data))>>18)
#define OSDCOMP_OSD1_CTRL_hs_yodd_shift                                              (17)
#define OSDCOMP_OSD1_CTRL_hs_yodd_mask                                               (0x00020000)
#define OSDCOMP_OSD1_CTRL_hs_yodd(data)                                              (0x00020000&((data)<<17))
#define OSDCOMP_OSD1_CTRL_hs_yodd_src(data)                                          ((0x00020000&(data))>>17)
#define OSDCOMP_OSD1_CTRL_get_hs_yodd(data)                                          ((0x00020000&(data))>>17)
#define OSDCOMP_OSD1_CTRL_hs_codd_shift                                              (16)
#define OSDCOMP_OSD1_CTRL_hs_codd_mask                                               (0x00010000)
#define OSDCOMP_OSD1_CTRL_hs_codd(data)                                              (0x00010000&((data)<<16))
#define OSDCOMP_OSD1_CTRL_hs_codd_src(data)                                          ((0x00010000&(data))>>16)
#define OSDCOMP_OSD1_CTRL_get_hs_codd(data)                                          ((0x00010000&(data))>>16)
#define OSDCOMP_OSD1_CTRL_vs_shift                                                   (14)
#define OSDCOMP_OSD1_CTRL_vs_mask                                                    (0x00004000)
#define OSDCOMP_OSD1_CTRL_vs(data)                                                   (0x00004000&((data)<<14))
#define OSDCOMP_OSD1_CTRL_vs_src(data)                                               ((0x00004000&(data))>>14)
#define OSDCOMP_OSD1_CTRL_get_vs(data)                                               ((0x00004000&(data))>>14)
#define OSDCOMP_OSD1_CTRL_vs_near_shift                                              (13)
#define OSDCOMP_OSD1_CTRL_vs_near_mask                                               (0x00002000)
#define OSDCOMP_OSD1_CTRL_vs_near(data)                                              (0x00002000&((data)<<13))
#define OSDCOMP_OSD1_CTRL_vs_near_src(data)                                          ((0x00002000&(data))>>13)
#define OSDCOMP_OSD1_CTRL_get_vs_near(data)                                          ((0x00002000&(data))>>13)
#define OSDCOMP_OSD1_CTRL_hs_shift                                                   (12)
#define OSDCOMP_OSD1_CTRL_hs_mask                                                    (0x00001000)
#define OSDCOMP_OSD1_CTRL_hs(data)                                                   (0x00001000&((data)<<12))
#define OSDCOMP_OSD1_CTRL_hs_src(data)                                               ((0x00001000&(data))>>12)
#define OSDCOMP_OSD1_CTRL_get_hs(data)                                               ((0x00001000&(data))>>12)
#define OSDCOMP_OSD1_CTRL_clear_region_en_shift                                      (9)
#define OSDCOMP_OSD1_CTRL_clear_region_en_mask                                       (0x00000200)
#define OSDCOMP_OSD1_CTRL_clear_region_en(data)                                      (0x00000200&((data)<<9))
#define OSDCOMP_OSD1_CTRL_clear_region_en_src(data)                                  ((0x00000200&(data))>>9)
#define OSDCOMP_OSD1_CTRL_get_clear_region_en(data)                                  ((0x00000200&(data))>>9)
#define OSDCOMP_OSD1_CTRL_plane_alpha_en_shift                                       (8)
#define OSDCOMP_OSD1_CTRL_plane_alpha_en_mask                                        (0x00000100)
#define OSDCOMP_OSD1_CTRL_plane_alpha_en(data)                                       (0x00000100&((data)<<8))
#define OSDCOMP_OSD1_CTRL_plane_alpha_en_src(data)                                   ((0x00000100&(data))>>8)
#define OSDCOMP_OSD1_CTRL_get_plane_alpha_en(data)                                   ((0x00000100&(data))>>8)
#define OSDCOMP_OSD1_CTRL_wi_endian_shift                                            (6)
#define OSDCOMP_OSD1_CTRL_wi_endian_mask                                             (0x00000040)
#define OSDCOMP_OSD1_CTRL_wi_endian(data)                                            (0x00000040&((data)<<6))
#define OSDCOMP_OSD1_CTRL_wi_endian_src(data)                                        ((0x00000040&(data))>>6)
#define OSDCOMP_OSD1_CTRL_get_wi_endian(data)                                        ((0x00000040&(data))>>6)
#define OSDCOMP_OSD1_CTRL_d3_dbw_shift                                               (5)
#define OSDCOMP_OSD1_CTRL_d3_dbw_mask                                                (0x00000020)
#define OSDCOMP_OSD1_CTRL_d3_dbw(data)                                               (0x00000020&((data)<<5))
#define OSDCOMP_OSD1_CTRL_d3_dbw_src(data)                                           ((0x00000020&(data))>>5)
#define OSDCOMP_OSD1_CTRL_get_d3_dbw(data)                                           ((0x00000020&(data))>>5)
#define OSDCOMP_OSD1_CTRL_d3_dup_shift                                               (4)
#define OSDCOMP_OSD1_CTRL_d3_dup_mask                                                (0x00000010)
#define OSDCOMP_OSD1_CTRL_d3_dup(data)                                               (0x00000010&((data)<<4))
#define OSDCOMP_OSD1_CTRL_d3_dup_src(data)                                           ((0x00000010&(data))>>4)
#define OSDCOMP_OSD1_CTRL_get_d3_dup(data)                                           ((0x00000010&(data))>>4)
#define OSDCOMP_OSD1_CTRL_rotate_shift                                               (2)
#define OSDCOMP_OSD1_CTRL_rotate_mask                                                (0x00000004)
#define OSDCOMP_OSD1_CTRL_rotate(data)                                               (0x00000004&((data)<<2))
#define OSDCOMP_OSD1_CTRL_rotate_src(data)                                           ((0x00000004&(data))>>2)
#define OSDCOMP_OSD1_CTRL_get_rotate(data)                                           ((0x00000004&(data))>>2)
#define OSDCOMP_OSD1_CTRL_en_shift                                                   (1)
#define OSDCOMP_OSD1_CTRL_en_mask                                                    (0x00000002)
#define OSDCOMP_OSD1_CTRL_en(data)                                                   (0x00000002&((data)<<1))
#define OSDCOMP_OSD1_CTRL_en_src(data)                                               ((0x00000002&(data))>>1)
#define OSDCOMP_OSD1_CTRL_get_en(data)                                               ((0x00000002&(data))>>1)
#define OSDCOMP_OSD1_CTRL_write_data_shift                                           (0)
#define OSDCOMP_OSD1_CTRL_write_data_mask                                            (0x00000001)
#define OSDCOMP_OSD1_CTRL_write_data(data)                                           (0x00000001&((data)<<0))
#define OSDCOMP_OSD1_CTRL_write_data_src(data)                                       ((0x00000001&(data))>>0)
#define OSDCOMP_OSD1_CTRL_get_write_data(data)                                       ((0x00000001&(data))>>0)


#define OSDCOMP_OSD1_WI                                                              0x18031014
#define OSDCOMP_OSD1_WI_reg_addr                                                     "0xB8031014"
#define OSDCOMP_OSD1_WI_reg                                                          0xB8031014
#define set_OSDCOMP_OSD1_WI_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_WI_reg)=data)
#define get_OSDCOMP_OSD1_WI_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_WI_reg))
#define OSDCOMP_OSD1_WI_inst_adr                                                     "0x0005"
#define OSDCOMP_OSD1_WI_inst                                                         0x0005
#define OSDCOMP_OSD1_WI_a_shift                                                      (0)
#define OSDCOMP_OSD1_WI_a_mask                                                       (0xFFFFFFFF)
#define OSDCOMP_OSD1_WI_a(data)                                                      (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_OSD1_WI_a_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_OSD1_WI_get_a(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_OSD1_WI_3D                                                           0x18031018
#define OSDCOMP_OSD1_WI_3D_reg_addr                                                  "0xB8031018"
#define OSDCOMP_OSD1_WI_3D_reg                                                       0xB8031018
#define set_OSDCOMP_OSD1_WI_3D_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_WI_3D_reg)=data)
#define get_OSDCOMP_OSD1_WI_3D_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_WI_3D_reg))
#define OSDCOMP_OSD1_WI_3D_inst_adr                                                  "0x0006"
#define OSDCOMP_OSD1_WI_3D_inst                                                      0x0006
#define OSDCOMP_OSD1_WI_3D_a_shift                                                   (0)
#define OSDCOMP_OSD1_WI_3D_a_mask                                                    (0xFFFFFFFF)
#define OSDCOMP_OSD1_WI_3D_a(data)                                                   (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_OSD1_WI_3D_a_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_OSD1_WI_3D_get_a(data)                                               ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_OSD1_SIZE                                                            0x1803101c
#define OSDCOMP_OSD1_SIZE_reg_addr                                                   "0xB803101C"
#define OSDCOMP_OSD1_SIZE_reg                                                        0xB803101C
#define set_OSDCOMP_OSD1_SIZE_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_SIZE_reg)=data)
#define get_OSDCOMP_OSD1_SIZE_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_SIZE_reg))
#define OSDCOMP_OSD1_SIZE_inst_adr                                                   "0x0007"
#define OSDCOMP_OSD1_SIZE_inst                                                       0x0007
#define OSDCOMP_OSD1_SIZE_w_shift                                                    (16)
#define OSDCOMP_OSD1_SIZE_w_mask                                                     (0x1FFF0000)
#define OSDCOMP_OSD1_SIZE_w(data)                                                    (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD1_SIZE_w_src(data)                                                ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD1_SIZE_get_w(data)                                                ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD1_SIZE_h_shift                                                    (0)
#define OSDCOMP_OSD1_SIZE_h_mask                                                     (0x00001FFF)
#define OSDCOMP_OSD1_SIZE_h(data)                                                    (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD1_SIZE_h_src(data)                                                ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD1_SIZE_get_h(data)                                                ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD1_CLEAR1                                                          0x18031020
#define OSDCOMP_OSD1_CLEAR1_reg_addr                                                 "0xB8031020"
#define OSDCOMP_OSD1_CLEAR1_reg                                                      0xB8031020
#define set_OSDCOMP_OSD1_CLEAR1_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_CLEAR1_reg)=data)
#define get_OSDCOMP_OSD1_CLEAR1_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_CLEAR1_reg))
#define OSDCOMP_OSD1_CLEAR1_inst_adr                                                 "0x0008"
#define OSDCOMP_OSD1_CLEAR1_inst                                                     0x0008
#define OSDCOMP_OSD1_CLEAR1_x_sta_shift                                              (16)
#define OSDCOMP_OSD1_CLEAR1_x_sta_mask                                               (0x1FFF0000)
#define OSDCOMP_OSD1_CLEAR1_x_sta(data)                                              (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD1_CLEAR1_x_sta_src(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD1_CLEAR1_get_x_sta(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD1_CLEAR1_x_end_shift                                              (0)
#define OSDCOMP_OSD1_CLEAR1_x_end_mask                                               (0x00001FFF)
#define OSDCOMP_OSD1_CLEAR1_x_end(data)                                              (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD1_CLEAR1_x_end_src(data)                                          ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD1_CLEAR1_get_x_end(data)                                          ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD1_CLEAR2                                                          0x18031024
#define OSDCOMP_OSD1_CLEAR2_reg_addr                                                 "0xB8031024"
#define OSDCOMP_OSD1_CLEAR2_reg                                                      0xB8031024
#define set_OSDCOMP_OSD1_CLEAR2_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_CLEAR2_reg)=data)
#define get_OSDCOMP_OSD1_CLEAR2_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_CLEAR2_reg))
#define OSDCOMP_OSD1_CLEAR2_inst_adr                                                 "0x0009"
#define OSDCOMP_OSD1_CLEAR2_inst                                                     0x0009
#define OSDCOMP_OSD1_CLEAR2_y_sta_shift                                              (16)
#define OSDCOMP_OSD1_CLEAR2_y_sta_mask                                               (0x1FFF0000)
#define OSDCOMP_OSD1_CLEAR2_y_sta(data)                                              (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD1_CLEAR2_y_sta_src(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD1_CLEAR2_get_y_sta(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD1_CLEAR2_y_end_shift                                              (0)
#define OSDCOMP_OSD1_CLEAR2_y_end_mask                                               (0x00001FFF)
#define OSDCOMP_OSD1_CLEAR2_y_end(data)                                              (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD1_CLEAR2_y_end_src(data)                                          ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD1_CLEAR2_get_y_end(data)                                          ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD1_PLANE                                                           0x18031028
#define OSDCOMP_OSD1_PLANE_reg_addr                                                  "0xB8031028"
#define OSDCOMP_OSD1_PLANE_reg                                                       0xB8031028
#define set_OSDCOMP_OSD1_PLANE_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_PLANE_reg)=data)
#define get_OSDCOMP_OSD1_PLANE_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_PLANE_reg))
#define OSDCOMP_OSD1_PLANE_inst_adr                                                  "0x000A"
#define OSDCOMP_OSD1_PLANE_inst                                                      0x000A
#define OSDCOMP_OSD1_PLANE_plane_alpha_a_shift                                       (24)
#define OSDCOMP_OSD1_PLANE_plane_alpha_a_mask                                        (0xFF000000)
#define OSDCOMP_OSD1_PLANE_plane_alpha_a(data)                                       (0xFF000000&((data)<<24))
#define OSDCOMP_OSD1_PLANE_plane_alpha_a_src(data)                                   ((0xFF000000&(data))>>24)
#define OSDCOMP_OSD1_PLANE_get_plane_alpha_a(data)                                   ((0xFF000000&(data))>>24)
#define OSDCOMP_OSD1_PLANE_plane_alpha_r_shift                                       (16)
#define OSDCOMP_OSD1_PLANE_plane_alpha_r_mask                                        (0x00FF0000)
#define OSDCOMP_OSD1_PLANE_plane_alpha_r(data)                                       (0x00FF0000&((data)<<16))
#define OSDCOMP_OSD1_PLANE_plane_alpha_r_src(data)                                   ((0x00FF0000&(data))>>16)
#define OSDCOMP_OSD1_PLANE_get_plane_alpha_r(data)                                   ((0x00FF0000&(data))>>16)
#define OSDCOMP_OSD1_PLANE_plane_alpha_g_shift                                       (8)
#define OSDCOMP_OSD1_PLANE_plane_alpha_g_mask                                        (0x0000FF00)
#define OSDCOMP_OSD1_PLANE_plane_alpha_g(data)                                       (0x0000FF00&((data)<<8))
#define OSDCOMP_OSD1_PLANE_plane_alpha_g_src(data)                                   ((0x0000FF00&(data))>>8)
#define OSDCOMP_OSD1_PLANE_get_plane_alpha_g(data)                                   ((0x0000FF00&(data))>>8)
#define OSDCOMP_OSD1_PLANE_plane_alpha_b_shift                                       (0)
#define OSDCOMP_OSD1_PLANE_plane_alpha_b_mask                                        (0x000000FF)
#define OSDCOMP_OSD1_PLANE_plane_alpha_b(data)                                       (0x000000FF&((data)<<0))
#define OSDCOMP_OSD1_PLANE_plane_alpha_b_src(data)                                   ((0x000000FF&(data))>>0)
#define OSDCOMP_OSD1_PLANE_get_plane_alpha_b(data)                                   ((0x000000FF&(data))>>0)


#define OSDCOMP_OSD1_VSI                                                             0x18031030
#define OSDCOMP_OSD1_VSI_reg_addr                                                    "0xB8031030"
#define OSDCOMP_OSD1_VSI_reg                                                         0xB8031030
#define set_OSDCOMP_OSD1_VSI_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_VSI_reg)=data)
#define get_OSDCOMP_OSD1_VSI_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_VSI_reg))
#define OSDCOMP_OSD1_VSI_inst_adr                                                    "0x000C"
#define OSDCOMP_OSD1_VSI_inst                                                        0x000C
#define OSDCOMP_OSD1_VSI_offset_shift                                                (16)
#define OSDCOMP_OSD1_VSI_offset_mask                                                 (0x1FFF0000)
#define OSDCOMP_OSD1_VSI_offset(data)                                                (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD1_VSI_offset_src(data)                                            ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD1_VSI_get_offset(data)                                            ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD1_VSI_phase_shift                                                 (2)
#define OSDCOMP_OSD1_VSI_phase_mask                                                  (0x0000FFFC)
#define OSDCOMP_OSD1_VSI_phase(data)                                                 (0x0000FFFC&((data)<<2))
#define OSDCOMP_OSD1_VSI_phase_src(data)                                             ((0x0000FFFC&(data))>>2)
#define OSDCOMP_OSD1_VSI_get_phase(data)                                             ((0x0000FFFC&(data))>>2)


#define OSDCOMP_OSD1_VSD_OUT                                                         0x18031034
#define OSDCOMP_OSD1_VSD_OUT_reg_addr                                                "0xB8031034"
#define OSDCOMP_OSD1_VSD_OUT_reg                                                     0xB8031034
#define set_OSDCOMP_OSD1_VSD_OUT_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_VSD_OUT_reg)=data)
#define get_OSDCOMP_OSD1_VSD_OUT_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_VSD_OUT_reg))
#define OSDCOMP_OSD1_VSD_OUT_inst_adr                                                "0x000D"
#define OSDCOMP_OSD1_VSD_OUT_inst                                                    0x000D
#define OSDCOMP_OSD1_VSD_OUT_out_shift                                               (0)
#define OSDCOMP_OSD1_VSD_OUT_out_mask                                                (0x00001FFF)
#define OSDCOMP_OSD1_VSD_OUT_out(data)                                               (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD1_VSD_OUT_out_src(data)                                           ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD1_VSD_OUT_get_out(data)                                           ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD1_VSD                                                             0x18031038
#define OSDCOMP_OSD1_VSD_reg_addr                                                    "0xB8031038"
#define OSDCOMP_OSD1_VSD_reg                                                         0xB8031038
#define set_OSDCOMP_OSD1_VSD_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_VSD_reg)=data)
#define get_OSDCOMP_OSD1_VSD_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_VSD_reg))
#define OSDCOMP_OSD1_VSD_inst_adr                                                    "0x000E"
#define OSDCOMP_OSD1_VSD_inst                                                        0x000E
#define OSDCOMP_OSD1_VSD_delta_shift                                                 (0)
#define OSDCOMP_OSD1_VSD_delta_mask                                                  (0x0007FFFF)
#define OSDCOMP_OSD1_VSD_delta(data)                                                 (0x0007FFFF&((data)<<0))
#define OSDCOMP_OSD1_VSD_delta_src(data)                                             ((0x0007FFFF&(data))>>0)
#define OSDCOMP_OSD1_VSD_get_delta(data)                                             ((0x0007FFFF&(data))>>0)


#define OSDCOMP_OSD1_VSYC_0                                                          0x1803103C
#define OSDCOMP_OSD1_VSYC_1                                                          0x18031040
#define OSDCOMP_OSD1_VSYC_2                                                          0x18031044
#define OSDCOMP_OSD1_VSYC_3                                                          0x18031048
#define OSDCOMP_OSD1_VSYC_0_reg_addr                                                 "0xB803103C"
#define OSDCOMP_OSD1_VSYC_1_reg_addr                                                 "0xB8031040"
#define OSDCOMP_OSD1_VSYC_2_reg_addr                                                 "0xB8031044"
#define OSDCOMP_OSD1_VSYC_3_reg_addr                                                 "0xB8031048"
#define OSDCOMP_OSD1_VSYC_0_reg                                                      0xB803103C
#define OSDCOMP_OSD1_VSYC_1_reg                                                      0xB8031040
#define OSDCOMP_OSD1_VSYC_2_reg                                                      0xB8031044
#define OSDCOMP_OSD1_VSYC_3_reg                                                      0xB8031048
#define set_OSDCOMP_OSD1_VSYC_0_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_VSYC_0_reg)=data)
#define set_OSDCOMP_OSD1_VSYC_1_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_VSYC_1_reg)=data)
#define set_OSDCOMP_OSD1_VSYC_2_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_VSYC_2_reg)=data)
#define set_OSDCOMP_OSD1_VSYC_3_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_VSYC_3_reg)=data)
#define get_OSDCOMP_OSD1_VSYC_0_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_VSYC_0_reg))
#define get_OSDCOMP_OSD1_VSYC_1_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_VSYC_1_reg))
#define get_OSDCOMP_OSD1_VSYC_2_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_VSYC_2_reg))
#define get_OSDCOMP_OSD1_VSYC_3_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_VSYC_3_reg))
#define OSDCOMP_OSD1_VSYC_0_inst_adr                                                 "0x000F"
#define OSDCOMP_OSD1_VSYC_1_inst_adr                                                 "0x0010"
#define OSDCOMP_OSD1_VSYC_2_inst_adr                                                 "0x0011"
#define OSDCOMP_OSD1_VSYC_3_inst_adr                                                 "0x0012"
#define OSDCOMP_OSD1_VSYC_0_inst                                                     0x000F
#define OSDCOMP_OSD1_VSYC_1_inst                                                     0x0010
#define OSDCOMP_OSD1_VSYC_2_inst                                                     0x0011
#define OSDCOMP_OSD1_VSYC_3_inst                                                     0x0012
#define OSDCOMP_OSD1_VSYC_c1_shift                                                   (16)
#define OSDCOMP_OSD1_VSYC_c1_mask                                                    (0x3FFF0000)
#define OSDCOMP_OSD1_VSYC_c1(data)                                                   (0x3FFF0000&((data)<<16))
#define OSDCOMP_OSD1_VSYC_c1_src(data)                                               ((0x3FFF0000&(data))>>16)
#define OSDCOMP_OSD1_VSYC_get_c1(data)                                               ((0x3FFF0000&(data))>>16)
#define OSDCOMP_OSD1_VSYC_c0_shift                                                   (0)
#define OSDCOMP_OSD1_VSYC_c0_mask                                                    (0x00003FFF)
#define OSDCOMP_OSD1_VSYC_c0(data)                                                   (0x00003FFF&((data)<<0))
#define OSDCOMP_OSD1_VSYC_c0_src(data)                                               ((0x00003FFF&(data))>>0)
#define OSDCOMP_OSD1_VSYC_get_c0(data)                                               ((0x00003FFF&(data))>>0)


#define OSDCOMP_OSD1_HSI                                                             0x1803104c
#define OSDCOMP_OSD1_HSI_reg_addr                                                    "0xB803104C"
#define OSDCOMP_OSD1_HSI_reg                                                         0xB803104C
#define set_OSDCOMP_OSD1_HSI_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSI_reg)=data)
#define get_OSDCOMP_OSD1_HSI_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSI_reg))
#define OSDCOMP_OSD1_HSI_inst_adr                                                    "0x0013"
#define OSDCOMP_OSD1_HSI_inst                                                        0x0013
#define OSDCOMP_OSD1_HSI_offset_shift                                                (16)
#define OSDCOMP_OSD1_HSI_offset_mask                                                 (0x1FFF0000)
#define OSDCOMP_OSD1_HSI_offset(data)                                                (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD1_HSI_offset_src(data)                                            ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD1_HSI_get_offset(data)                                            ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD1_HSI_phase_shift                                                 (2)
#define OSDCOMP_OSD1_HSI_phase_mask                                                  (0x0000FFFC)
#define OSDCOMP_OSD1_HSI_phase(data)                                                 (0x0000FFFC&((data)<<2))
#define OSDCOMP_OSD1_HSI_phase_src(data)                                             ((0x0000FFFC&(data))>>2)
#define OSDCOMP_OSD1_HSI_get_phase(data)                                             ((0x0000FFFC&(data))>>2)


#define OSDCOMP_OSD1_HSD_OUT                                                         0x18031050
#define OSDCOMP_OSD1_HSD_OUT_reg_addr                                                "0xB8031050"
#define OSDCOMP_OSD1_HSD_OUT_reg                                                     0xB8031050
#define set_OSDCOMP_OSD1_HSD_OUT_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSD_OUT_reg)=data)
#define get_OSDCOMP_OSD1_HSD_OUT_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSD_OUT_reg))
#define OSDCOMP_OSD1_HSD_OUT_inst_adr                                                "0x0014"
#define OSDCOMP_OSD1_HSD_OUT_inst                                                    0x0014
#define OSDCOMP_OSD1_HSD_OUT_out_shift                                               (0)
#define OSDCOMP_OSD1_HSD_OUT_out_mask                                                (0x00001FFF)
#define OSDCOMP_OSD1_HSD_OUT_out(data)                                               (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD1_HSD_OUT_out_src(data)                                           ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD1_HSD_OUT_get_out(data)                                           ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD1_HSD                                                             0x18031054
#define OSDCOMP_OSD1_HSD_reg_addr                                                    "0xB8031054"
#define OSDCOMP_OSD1_HSD_reg                                                         0xB8031054
#define set_OSDCOMP_OSD1_HSD_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSD_reg)=data)
#define get_OSDCOMP_OSD1_HSD_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSD_reg))
#define OSDCOMP_OSD1_HSD_inst_adr                                                    "0x0015"
#define OSDCOMP_OSD1_HSD_inst                                                        0x0015
#define OSDCOMP_OSD1_HSD_delta_shift                                                 (0)
#define OSDCOMP_OSD1_HSD_delta_mask                                                  (0x0007FFFF)
#define OSDCOMP_OSD1_HSD_delta(data)                                                 (0x0007FFFF&((data)<<0))
#define OSDCOMP_OSD1_HSD_delta_src(data)                                             ((0x0007FFFF&(data))>>0)
#define OSDCOMP_OSD1_HSD_get_delta(data)                                             ((0x0007FFFF&(data))>>0)


#define OSDCOMP_OSD1_HSYC_0                                                          0x18031058
#define OSDCOMP_OSD1_HSYC_1                                                          0x1803105C
#define OSDCOMP_OSD1_HSYC_2                                                          0x18031060
#define OSDCOMP_OSD1_HSYC_3                                                          0x18031064
#define OSDCOMP_OSD1_HSYC_4                                                          0x18031068
#define OSDCOMP_OSD1_HSYC_5                                                          0x1803106C
#define OSDCOMP_OSD1_HSYC_6                                                          0x18031070
#define OSDCOMP_OSD1_HSYC_7                                                          0x18031074
#define OSDCOMP_OSD1_HSYC_0_reg_addr                                                 "0xB8031058"
#define OSDCOMP_OSD1_HSYC_1_reg_addr                                                 "0xB803105C"
#define OSDCOMP_OSD1_HSYC_2_reg_addr                                                 "0xB8031060"
#define OSDCOMP_OSD1_HSYC_3_reg_addr                                                 "0xB8031064"
#define OSDCOMP_OSD1_HSYC_4_reg_addr                                                 "0xB8031068"
#define OSDCOMP_OSD1_HSYC_5_reg_addr                                                 "0xB803106C"
#define OSDCOMP_OSD1_HSYC_6_reg_addr                                                 "0xB8031070"
#define OSDCOMP_OSD1_HSYC_7_reg_addr                                                 "0xB8031074"
#define OSDCOMP_OSD1_HSYC_0_reg                                                      0xB8031058
#define OSDCOMP_OSD1_HSYC_1_reg                                                      0xB803105C
#define OSDCOMP_OSD1_HSYC_2_reg                                                      0xB8031060
#define OSDCOMP_OSD1_HSYC_3_reg                                                      0xB8031064
#define OSDCOMP_OSD1_HSYC_4_reg                                                      0xB8031068
#define OSDCOMP_OSD1_HSYC_5_reg                                                      0xB803106C
#define OSDCOMP_OSD1_HSYC_6_reg                                                      0xB8031070
#define OSDCOMP_OSD1_HSYC_7_reg                                                      0xB8031074
#define set_OSDCOMP_OSD1_HSYC_0_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_0_reg)=data)
#define set_OSDCOMP_OSD1_HSYC_1_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_1_reg)=data)
#define set_OSDCOMP_OSD1_HSYC_2_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_2_reg)=data)
#define set_OSDCOMP_OSD1_HSYC_3_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_3_reg)=data)
#define set_OSDCOMP_OSD1_HSYC_4_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_4_reg)=data)
#define set_OSDCOMP_OSD1_HSYC_5_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_5_reg)=data)
#define set_OSDCOMP_OSD1_HSYC_6_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_6_reg)=data)
#define set_OSDCOMP_OSD1_HSYC_7_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_7_reg)=data)
#define get_OSDCOMP_OSD1_HSYC_0_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_0_reg))
#define get_OSDCOMP_OSD1_HSYC_1_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_1_reg))
#define get_OSDCOMP_OSD1_HSYC_2_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_2_reg))
#define get_OSDCOMP_OSD1_HSYC_3_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_3_reg))
#define get_OSDCOMP_OSD1_HSYC_4_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_4_reg))
#define get_OSDCOMP_OSD1_HSYC_5_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_5_reg))
#define get_OSDCOMP_OSD1_HSYC_6_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_6_reg))
#define get_OSDCOMP_OSD1_HSYC_7_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_HSYC_7_reg))
#define OSDCOMP_OSD1_HSYC_0_inst_adr                                                 "0x0016"
#define OSDCOMP_OSD1_HSYC_1_inst_adr                                                 "0x0017"
#define OSDCOMP_OSD1_HSYC_2_inst_adr                                                 "0x0018"
#define OSDCOMP_OSD1_HSYC_3_inst_adr                                                 "0x0019"
#define OSDCOMP_OSD1_HSYC_4_inst_adr                                                 "0x001A"
#define OSDCOMP_OSD1_HSYC_5_inst_adr                                                 "0x001B"
#define OSDCOMP_OSD1_HSYC_6_inst_adr                                                 "0x001C"
#define OSDCOMP_OSD1_HSYC_7_inst_adr                                                 "0x001D"
#define OSDCOMP_OSD1_HSYC_0_inst                                                     0x0016
#define OSDCOMP_OSD1_HSYC_1_inst                                                     0x0017
#define OSDCOMP_OSD1_HSYC_2_inst                                                     0x0018
#define OSDCOMP_OSD1_HSYC_3_inst                                                     0x0019
#define OSDCOMP_OSD1_HSYC_4_inst                                                     0x001A
#define OSDCOMP_OSD1_HSYC_5_inst                                                     0x001B
#define OSDCOMP_OSD1_HSYC_6_inst                                                     0x001C
#define OSDCOMP_OSD1_HSYC_7_inst                                                     0x001D
#define OSDCOMP_OSD1_HSYC_c1_shift                                                   (16)
#define OSDCOMP_OSD1_HSYC_c1_mask                                                    (0x3FFF0000)
#define OSDCOMP_OSD1_HSYC_c1(data)                                                   (0x3FFF0000&((data)<<16))
#define OSDCOMP_OSD1_HSYC_c1_src(data)                                               ((0x3FFF0000&(data))>>16)
#define OSDCOMP_OSD1_HSYC_get_c1(data)                                               ((0x3FFF0000&(data))>>16)
#define OSDCOMP_OSD1_HSYC_c0_shift                                                   (0)
#define OSDCOMP_OSD1_HSYC_c0_mask                                                    (0x00003FFF)
#define OSDCOMP_OSD1_HSYC_c0(data)                                                   (0x00003FFF&((data)<<0))
#define OSDCOMP_OSD1_HSYC_c0_src(data)                                               ((0x00003FFF&(data))>>0)
#define OSDCOMP_OSD1_HSYC_get_c0(data)                                               ((0x00003FFF&(data))>>0)


#define OSDCOMP_OSD2_CTRL                                                            0x18031080
#define OSDCOMP_OSD2_CTRL_reg_addr                                                   "0xB8031080"
#define OSDCOMP_OSD2_CTRL_reg                                                        0xB8031080
#define set_OSDCOMP_OSD2_CTRL_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD2_CTRL_reg)=data)
#define get_OSDCOMP_OSD2_CTRL_reg   (*((volatile unsigned int*) OSDCOMP_OSD2_CTRL_reg))
#define OSDCOMP_OSD2_CTRL_inst_adr                                                   "0x0020"
#define OSDCOMP_OSD2_CTRL_inst                                                       0x0020
#define OSDCOMP_OSD2_CTRL_clear_region_en_shift                                      (9)
#define OSDCOMP_OSD2_CTRL_clear_region_en_mask                                       (0x00000200)
#define OSDCOMP_OSD2_CTRL_clear_region_en(data)                                      (0x00000200&((data)<<9))
#define OSDCOMP_OSD2_CTRL_clear_region_en_src(data)                                  ((0x00000200&(data))>>9)
#define OSDCOMP_OSD2_CTRL_get_clear_region_en(data)                                  ((0x00000200&(data))>>9)
#define OSDCOMP_OSD2_CTRL_plane_alpha_en_shift                                       (8)
#define OSDCOMP_OSD2_CTRL_plane_alpha_en_mask                                        (0x00000100)
#define OSDCOMP_OSD2_CTRL_plane_alpha_en(data)                                       (0x00000100&((data)<<8))
#define OSDCOMP_OSD2_CTRL_plane_alpha_en_src(data)                                   ((0x00000100&(data))>>8)
#define OSDCOMP_OSD2_CTRL_get_plane_alpha_en(data)                                   ((0x00000100&(data))>>8)
#define OSDCOMP_OSD2_CTRL_wi_endian_shift                                            (6)
#define OSDCOMP_OSD2_CTRL_wi_endian_mask                                             (0x00000040)
#define OSDCOMP_OSD2_CTRL_wi_endian(data)                                            (0x00000040&((data)<<6))
#define OSDCOMP_OSD2_CTRL_wi_endian_src(data)                                        ((0x00000040&(data))>>6)
#define OSDCOMP_OSD2_CTRL_get_wi_endian(data)                                        ((0x00000040&(data))>>6)
#define OSDCOMP_OSD2_CTRL_d3_dbw_shift                                               (5)
#define OSDCOMP_OSD2_CTRL_d3_dbw_mask                                                (0x00000020)
#define OSDCOMP_OSD2_CTRL_d3_dbw(data)                                               (0x00000020&((data)<<5))
#define OSDCOMP_OSD2_CTRL_d3_dbw_src(data)                                           ((0x00000020&(data))>>5)
#define OSDCOMP_OSD2_CTRL_get_d3_dbw(data)                                           ((0x00000020&(data))>>5)
#define OSDCOMP_OSD2_CTRL_d3_dup_shift                                               (4)
#define OSDCOMP_OSD2_CTRL_d3_dup_mask                                                (0x00000010)
#define OSDCOMP_OSD2_CTRL_d3_dup(data)                                               (0x00000010&((data)<<4))
#define OSDCOMP_OSD2_CTRL_d3_dup_src(data)                                           ((0x00000010&(data))>>4)
#define OSDCOMP_OSD2_CTRL_get_d3_dup(data)                                           ((0x00000010&(data))>>4)
#define OSDCOMP_OSD2_CTRL_rotate_shift                                               (2)
#define OSDCOMP_OSD2_CTRL_rotate_mask                                                (0x00000004)
#define OSDCOMP_OSD2_CTRL_rotate(data)                                               (0x00000004&((data)<<2))
#define OSDCOMP_OSD2_CTRL_rotate_src(data)                                           ((0x00000004&(data))>>2)
#define OSDCOMP_OSD2_CTRL_get_rotate(data)                                           ((0x00000004&(data))>>2)
#define OSDCOMP_OSD2_CTRL_en_shift                                                   (1)
#define OSDCOMP_OSD2_CTRL_en_mask                                                    (0x00000002)
#define OSDCOMP_OSD2_CTRL_en(data)                                                   (0x00000002&((data)<<1))
#define OSDCOMP_OSD2_CTRL_en_src(data)                                               ((0x00000002&(data))>>1)
#define OSDCOMP_OSD2_CTRL_get_en(data)                                               ((0x00000002&(data))>>1)
#define OSDCOMP_OSD2_CTRL_write_data_shift                                           (0)
#define OSDCOMP_OSD2_CTRL_write_data_mask                                            (0x00000001)
#define OSDCOMP_OSD2_CTRL_write_data(data)                                           (0x00000001&((data)<<0))
#define OSDCOMP_OSD2_CTRL_write_data_src(data)                                       ((0x00000001&(data))>>0)
#define OSDCOMP_OSD2_CTRL_get_write_data(data)                                       ((0x00000001&(data))>>0)


#define OSDCOMP_OSD2_WI                                                              0x18031084
#define OSDCOMP_OSD2_WI_reg_addr                                                     "0xB8031084"
#define OSDCOMP_OSD2_WI_reg                                                          0xB8031084
#define set_OSDCOMP_OSD2_WI_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD2_WI_reg)=data)
#define get_OSDCOMP_OSD2_WI_reg   (*((volatile unsigned int*) OSDCOMP_OSD2_WI_reg))
#define OSDCOMP_OSD2_WI_inst_adr                                                     "0x0021"
#define OSDCOMP_OSD2_WI_inst                                                         0x0021
#define OSDCOMP_OSD2_WI_a_shift                                                      (0)
#define OSDCOMP_OSD2_WI_a_mask                                                       (0xFFFFFFFF)
#define OSDCOMP_OSD2_WI_a(data)                                                      (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_OSD2_WI_a_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_OSD2_WI_get_a(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_OSD2_WI_3D                                                           0x18031088
#define OSDCOMP_OSD2_WI_3D_reg_addr                                                  "0xB8031088"
#define OSDCOMP_OSD2_WI_3D_reg                                                       0xB8031088
#define set_OSDCOMP_OSD2_WI_3D_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD2_WI_3D_reg)=data)
#define get_OSDCOMP_OSD2_WI_3D_reg   (*((volatile unsigned int*) OSDCOMP_OSD2_WI_3D_reg))
#define OSDCOMP_OSD2_WI_3D_inst_adr                                                  "0x0022"
#define OSDCOMP_OSD2_WI_3D_inst                                                      0x0022
#define OSDCOMP_OSD2_WI_3D_a_shift                                                   (0)
#define OSDCOMP_OSD2_WI_3D_a_mask                                                    (0xFFFFFFFF)
#define OSDCOMP_OSD2_WI_3D_a(data)                                                   (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_OSD2_WI_3D_a_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_OSD2_WI_3D_get_a(data)                                               ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_OSD2_SIZE                                                            0x1803108c
#define OSDCOMP_OSD2_SIZE_reg_addr                                                   "0xB803108C"
#define OSDCOMP_OSD2_SIZE_reg                                                        0xB803108C
#define set_OSDCOMP_OSD2_SIZE_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD2_SIZE_reg)=data)
#define get_OSDCOMP_OSD2_SIZE_reg   (*((volatile unsigned int*) OSDCOMP_OSD2_SIZE_reg))
#define OSDCOMP_OSD2_SIZE_inst_adr                                                   "0x0023"
#define OSDCOMP_OSD2_SIZE_inst                                                       0x0023
#define OSDCOMP_OSD2_SIZE_w_shift                                                    (16)
#define OSDCOMP_OSD2_SIZE_w_mask                                                     (0x1FFF0000)
#define OSDCOMP_OSD2_SIZE_w(data)                                                    (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD2_SIZE_w_src(data)                                                ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD2_SIZE_get_w(data)                                                ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD2_SIZE_h_shift                                                    (0)
#define OSDCOMP_OSD2_SIZE_h_mask                                                     (0x00001FFF)
#define OSDCOMP_OSD2_SIZE_h(data)                                                    (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD2_SIZE_h_src(data)                                                ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD2_SIZE_get_h(data)                                                ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD2_CLEAR1                                                          0x18031090
#define OSDCOMP_OSD2_CLEAR1_reg_addr                                                 "0xB8031090"
#define OSDCOMP_OSD2_CLEAR1_reg                                                      0xB8031090
#define set_OSDCOMP_OSD2_CLEAR1_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD2_CLEAR1_reg)=data)
#define get_OSDCOMP_OSD2_CLEAR1_reg   (*((volatile unsigned int*) OSDCOMP_OSD2_CLEAR1_reg))
#define OSDCOMP_OSD2_CLEAR1_inst_adr                                                 "0x0024"
#define OSDCOMP_OSD2_CLEAR1_inst                                                     0x0024
#define OSDCOMP_OSD2_CLEAR1_x_sta_shift                                              (16)
#define OSDCOMP_OSD2_CLEAR1_x_sta_mask                                               (0x1FFF0000)
#define OSDCOMP_OSD2_CLEAR1_x_sta(data)                                              (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD2_CLEAR1_x_sta_src(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD2_CLEAR1_get_x_sta(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD2_CLEAR1_x_end_shift                                              (0)
#define OSDCOMP_OSD2_CLEAR1_x_end_mask                                               (0x00001FFF)
#define OSDCOMP_OSD2_CLEAR1_x_end(data)                                              (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD2_CLEAR1_x_end_src(data)                                          ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD2_CLEAR1_get_x_end(data)                                          ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD2_CLEAR2                                                          0x18031094
#define OSDCOMP_OSD2_CLEAR2_reg_addr                                                 "0xB8031094"
#define OSDCOMP_OSD2_CLEAR2_reg                                                      0xB8031094
#define set_OSDCOMP_OSD2_CLEAR2_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD2_CLEAR2_reg)=data)
#define get_OSDCOMP_OSD2_CLEAR2_reg   (*((volatile unsigned int*) OSDCOMP_OSD2_CLEAR2_reg))
#define OSDCOMP_OSD2_CLEAR2_inst_adr                                                 "0x0025"
#define OSDCOMP_OSD2_CLEAR2_inst                                                     0x0025
#define OSDCOMP_OSD2_CLEAR2_y_sta_shift                                              (16)
#define OSDCOMP_OSD2_CLEAR2_y_sta_mask                                               (0x1FFF0000)
#define OSDCOMP_OSD2_CLEAR2_y_sta(data)                                              (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD2_CLEAR2_y_sta_src(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD2_CLEAR2_get_y_sta(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD2_CLEAR2_y_end_shift                                              (0)
#define OSDCOMP_OSD2_CLEAR2_y_end_mask                                               (0x00001FFF)
#define OSDCOMP_OSD2_CLEAR2_y_end(data)                                              (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD2_CLEAR2_y_end_src(data)                                          ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD2_CLEAR2_get_y_end(data)                                          ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD2_PLANE                                                           0x18031098
#define OSDCOMP_OSD2_PLANE_reg_addr                                                  "0xB8031098"
#define OSDCOMP_OSD2_PLANE_reg                                                       0xB8031098
#define set_OSDCOMP_OSD2_PLANE_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD2_PLANE_reg)=data)
#define get_OSDCOMP_OSD2_PLANE_reg   (*((volatile unsigned int*) OSDCOMP_OSD2_PLANE_reg))
#define OSDCOMP_OSD2_PLANE_inst_adr                                                  "0x0026"
#define OSDCOMP_OSD2_PLANE_inst                                                      0x0026
#define OSDCOMP_OSD2_PLANE_plane_alpha_a_shift                                       (24)
#define OSDCOMP_OSD2_PLANE_plane_alpha_a_mask                                        (0xFF000000)
#define OSDCOMP_OSD2_PLANE_plane_alpha_a(data)                                       (0xFF000000&((data)<<24))
#define OSDCOMP_OSD2_PLANE_plane_alpha_a_src(data)                                   ((0xFF000000&(data))>>24)
#define OSDCOMP_OSD2_PLANE_get_plane_alpha_a(data)                                   ((0xFF000000&(data))>>24)
#define OSDCOMP_OSD2_PLANE_plane_alpha_r_shift                                       (16)
#define OSDCOMP_OSD2_PLANE_plane_alpha_r_mask                                        (0x00FF0000)
#define OSDCOMP_OSD2_PLANE_plane_alpha_r(data)                                       (0x00FF0000&((data)<<16))
#define OSDCOMP_OSD2_PLANE_plane_alpha_r_src(data)                                   ((0x00FF0000&(data))>>16)
#define OSDCOMP_OSD2_PLANE_get_plane_alpha_r(data)                                   ((0x00FF0000&(data))>>16)
#define OSDCOMP_OSD2_PLANE_plane_alpha_g_shift                                       (8)
#define OSDCOMP_OSD2_PLANE_plane_alpha_g_mask                                        (0x0000FF00)
#define OSDCOMP_OSD2_PLANE_plane_alpha_g(data)                                       (0x0000FF00&((data)<<8))
#define OSDCOMP_OSD2_PLANE_plane_alpha_g_src(data)                                   ((0x0000FF00&(data))>>8)
#define OSDCOMP_OSD2_PLANE_get_plane_alpha_g(data)                                   ((0x0000FF00&(data))>>8)
#define OSDCOMP_OSD2_PLANE_plane_alpha_b_shift                                       (0)
#define OSDCOMP_OSD2_PLANE_plane_alpha_b_mask                                        (0x000000FF)
#define OSDCOMP_OSD2_PLANE_plane_alpha_b(data)                                       (0x000000FF&((data)<<0))
#define OSDCOMP_OSD2_PLANE_plane_alpha_b_src(data)                                   ((0x000000FF&(data))>>0)
#define OSDCOMP_OSD2_PLANE_get_plane_alpha_b(data)                                   ((0x000000FF&(data))>>0)


#define OSDCOMP_OSD3_CTRL                                                            0x180310a0
#define OSDCOMP_OSD3_CTRL_reg_addr                                                   "0xB80310A0"
#define OSDCOMP_OSD3_CTRL_reg                                                        0xB80310A0
#define set_OSDCOMP_OSD3_CTRL_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD3_CTRL_reg)=data)
#define get_OSDCOMP_OSD3_CTRL_reg   (*((volatile unsigned int*) OSDCOMP_OSD3_CTRL_reg))
#define OSDCOMP_OSD3_CTRL_inst_adr                                                   "0x0028"
#define OSDCOMP_OSD3_CTRL_inst                                                       0x0028
#define OSDCOMP_OSD3_CTRL_clear_region_en_shift                                      (9)
#define OSDCOMP_OSD3_CTRL_clear_region_en_mask                                       (0x00000200)
#define OSDCOMP_OSD3_CTRL_clear_region_en(data)                                      (0x00000200&((data)<<9))
#define OSDCOMP_OSD3_CTRL_clear_region_en_src(data)                                  ((0x00000200&(data))>>9)
#define OSDCOMP_OSD3_CTRL_get_clear_region_en(data)                                  ((0x00000200&(data))>>9)
#define OSDCOMP_OSD3_CTRL_plane_alpha_en_shift                                       (8)
#define OSDCOMP_OSD3_CTRL_plane_alpha_en_mask                                        (0x00000100)
#define OSDCOMP_OSD3_CTRL_plane_alpha_en(data)                                       (0x00000100&((data)<<8))
#define OSDCOMP_OSD3_CTRL_plane_alpha_en_src(data)                                   ((0x00000100&(data))>>8)
#define OSDCOMP_OSD3_CTRL_get_plane_alpha_en(data)                                   ((0x00000100&(data))>>8)
#define OSDCOMP_OSD3_CTRL_wi_endian_shift                                            (6)
#define OSDCOMP_OSD3_CTRL_wi_endian_mask                                             (0x00000040)
#define OSDCOMP_OSD3_CTRL_wi_endian(data)                                            (0x00000040&((data)<<6))
#define OSDCOMP_OSD3_CTRL_wi_endian_src(data)                                        ((0x00000040&(data))>>6)
#define OSDCOMP_OSD3_CTRL_get_wi_endian(data)                                        ((0x00000040&(data))>>6)
#define OSDCOMP_OSD3_CTRL_d3_dbw_shift                                               (5)
#define OSDCOMP_OSD3_CTRL_d3_dbw_mask                                                (0x00000020)
#define OSDCOMP_OSD3_CTRL_d3_dbw(data)                                               (0x00000020&((data)<<5))
#define OSDCOMP_OSD3_CTRL_d3_dbw_src(data)                                           ((0x00000020&(data))>>5)
#define OSDCOMP_OSD3_CTRL_get_d3_dbw(data)                                           ((0x00000020&(data))>>5)
#define OSDCOMP_OSD3_CTRL_d3_dup_shift                                               (4)
#define OSDCOMP_OSD3_CTRL_d3_dup_mask                                                (0x00000010)
#define OSDCOMP_OSD3_CTRL_d3_dup(data)                                               (0x00000010&((data)<<4))
#define OSDCOMP_OSD3_CTRL_d3_dup_src(data)                                           ((0x00000010&(data))>>4)
#define OSDCOMP_OSD3_CTRL_get_d3_dup(data)                                           ((0x00000010&(data))>>4)
#define OSDCOMP_OSD3_CTRL_rotate_shift                                               (2)
#define OSDCOMP_OSD3_CTRL_rotate_mask                                                (0x00000004)
#define OSDCOMP_OSD3_CTRL_rotate(data)                                               (0x00000004&((data)<<2))
#define OSDCOMP_OSD3_CTRL_rotate_src(data)                                           ((0x00000004&(data))>>2)
#define OSDCOMP_OSD3_CTRL_get_rotate(data)                                           ((0x00000004&(data))>>2)
#define OSDCOMP_OSD3_CTRL_en_shift                                                   (1)
#define OSDCOMP_OSD3_CTRL_en_mask                                                    (0x00000002)
#define OSDCOMP_OSD3_CTRL_en(data)                                                   (0x00000002&((data)<<1))
#define OSDCOMP_OSD3_CTRL_en_src(data)                                               ((0x00000002&(data))>>1)
#define OSDCOMP_OSD3_CTRL_get_en(data)                                               ((0x00000002&(data))>>1)
#define OSDCOMP_OSD3_CTRL_write_data_shift                                           (0)
#define OSDCOMP_OSD3_CTRL_write_data_mask                                            (0x00000001)
#define OSDCOMP_OSD3_CTRL_write_data(data)                                           (0x00000001&((data)<<0))
#define OSDCOMP_OSD3_CTRL_write_data_src(data)                                       ((0x00000001&(data))>>0)
#define OSDCOMP_OSD3_CTRL_get_write_data(data)                                       ((0x00000001&(data))>>0)


#define OSDCOMP_OSD3_WI                                                              0x180310a4
#define OSDCOMP_OSD3_WI_reg_addr                                                     "0xB80310A4"
#define OSDCOMP_OSD3_WI_reg                                                          0xB80310A4
#define set_OSDCOMP_OSD3_WI_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD3_WI_reg)=data)
#define get_OSDCOMP_OSD3_WI_reg   (*((volatile unsigned int*) OSDCOMP_OSD3_WI_reg))
#define OSDCOMP_OSD3_WI_inst_adr                                                     "0x0029"
#define OSDCOMP_OSD3_WI_inst                                                         0x0029
#define OSDCOMP_OSD3_WI_a_shift                                                      (0)
#define OSDCOMP_OSD3_WI_a_mask                                                       (0xFFFFFFFF)
#define OSDCOMP_OSD3_WI_a(data)                                                      (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_OSD3_WI_a_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_OSD3_WI_get_a(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_OSD3_WI_3D                                                           0x180310a8
#define OSDCOMP_OSD3_WI_3D_reg_addr                                                  "0xB80310A8"
#define OSDCOMP_OSD3_WI_3D_reg                                                       0xB80310A8
#define set_OSDCOMP_OSD3_WI_3D_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD3_WI_3D_reg)=data)
#define get_OSDCOMP_OSD3_WI_3D_reg   (*((volatile unsigned int*) OSDCOMP_OSD3_WI_3D_reg))
#define OSDCOMP_OSD3_WI_3D_inst_adr                                                  "0x002A"
#define OSDCOMP_OSD3_WI_3D_inst                                                      0x002A
#define OSDCOMP_OSD3_WI_3D_a_shift                                                   (0)
#define OSDCOMP_OSD3_WI_3D_a_mask                                                    (0xFFFFFFFF)
#define OSDCOMP_OSD3_WI_3D_a(data)                                                   (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_OSD3_WI_3D_a_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_OSD3_WI_3D_get_a(data)                                               ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_OSD3_SIZE                                                            0x180310ac
#define OSDCOMP_OSD3_SIZE_reg_addr                                                   "0xB80310AC"
#define OSDCOMP_OSD3_SIZE_reg                                                        0xB80310AC
#define set_OSDCOMP_OSD3_SIZE_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD3_SIZE_reg)=data)
#define get_OSDCOMP_OSD3_SIZE_reg   (*((volatile unsigned int*) OSDCOMP_OSD3_SIZE_reg))
#define OSDCOMP_OSD3_SIZE_inst_adr                                                   "0x002B"
#define OSDCOMP_OSD3_SIZE_inst                                                       0x002B
#define OSDCOMP_OSD3_SIZE_w_shift                                                    (16)
#define OSDCOMP_OSD3_SIZE_w_mask                                                     (0x1FFF0000)
#define OSDCOMP_OSD3_SIZE_w(data)                                                    (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD3_SIZE_w_src(data)                                                ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD3_SIZE_get_w(data)                                                ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD3_SIZE_h_shift                                                    (0)
#define OSDCOMP_OSD3_SIZE_h_mask                                                     (0x00001FFF)
#define OSDCOMP_OSD3_SIZE_h(data)                                                    (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD3_SIZE_h_src(data)                                                ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD3_SIZE_get_h(data)                                                ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD3_CLEAR1                                                          0x180310b0
#define OSDCOMP_OSD3_CLEAR1_reg_addr                                                 "0xB80310B0"
#define OSDCOMP_OSD3_CLEAR1_reg                                                      0xB80310B0
#define set_OSDCOMP_OSD3_CLEAR1_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD3_CLEAR1_reg)=data)
#define get_OSDCOMP_OSD3_CLEAR1_reg   (*((volatile unsigned int*) OSDCOMP_OSD3_CLEAR1_reg))
#define OSDCOMP_OSD3_CLEAR1_inst_adr                                                 "0x002C"
#define OSDCOMP_OSD3_CLEAR1_inst                                                     0x002C
#define OSDCOMP_OSD3_CLEAR1_x_sta_shift                                              (16)
#define OSDCOMP_OSD3_CLEAR1_x_sta_mask                                               (0x1FFF0000)
#define OSDCOMP_OSD3_CLEAR1_x_sta(data)                                              (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD3_CLEAR1_x_sta_src(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD3_CLEAR1_get_x_sta(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD3_CLEAR1_x_end_shift                                              (0)
#define OSDCOMP_OSD3_CLEAR1_x_end_mask                                               (0x00001FFF)
#define OSDCOMP_OSD3_CLEAR1_x_end(data)                                              (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD3_CLEAR1_x_end_src(data)                                          ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD3_CLEAR1_get_x_end(data)                                          ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD3_CLEAR2                                                          0x180310b4
#define OSDCOMP_OSD3_CLEAR2_reg_addr                                                 "0xB80310B4"
#define OSDCOMP_OSD3_CLEAR2_reg                                                      0xB80310B4
#define set_OSDCOMP_OSD3_CLEAR2_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD3_CLEAR2_reg)=data)
#define get_OSDCOMP_OSD3_CLEAR2_reg   (*((volatile unsigned int*) OSDCOMP_OSD3_CLEAR2_reg))
#define OSDCOMP_OSD3_CLEAR2_inst_adr                                                 "0x002D"
#define OSDCOMP_OSD3_CLEAR2_inst                                                     0x002D
#define OSDCOMP_OSD3_CLEAR2_y_sta_shift                                              (16)
#define OSDCOMP_OSD3_CLEAR2_y_sta_mask                                               (0x1FFF0000)
#define OSDCOMP_OSD3_CLEAR2_y_sta(data)                                              (0x1FFF0000&((data)<<16))
#define OSDCOMP_OSD3_CLEAR2_y_sta_src(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD3_CLEAR2_get_y_sta(data)                                          ((0x1FFF0000&(data))>>16)
#define OSDCOMP_OSD3_CLEAR2_y_end_shift                                              (0)
#define OSDCOMP_OSD3_CLEAR2_y_end_mask                                               (0x00001FFF)
#define OSDCOMP_OSD3_CLEAR2_y_end(data)                                              (0x00001FFF&((data)<<0))
#define OSDCOMP_OSD3_CLEAR2_y_end_src(data)                                          ((0x00001FFF&(data))>>0)
#define OSDCOMP_OSD3_CLEAR2_get_y_end(data)                                          ((0x00001FFF&(data))>>0)


#define OSDCOMP_OSD3_PLANE                                                           0x180310b8
#define OSDCOMP_OSD3_PLANE_reg_addr                                                  "0xB80310B8"
#define OSDCOMP_OSD3_PLANE_reg                                                       0xB80310B8
#define set_OSDCOMP_OSD3_PLANE_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD3_PLANE_reg)=data)
#define get_OSDCOMP_OSD3_PLANE_reg   (*((volatile unsigned int*) OSDCOMP_OSD3_PLANE_reg))
#define OSDCOMP_OSD3_PLANE_inst_adr                                                  "0x002E"
#define OSDCOMP_OSD3_PLANE_inst                                                      0x002E
#define OSDCOMP_OSD3_PLANE_plane_alpha_a_shift                                       (24)
#define OSDCOMP_OSD3_PLANE_plane_alpha_a_mask                                        (0xFF000000)
#define OSDCOMP_OSD3_PLANE_plane_alpha_a(data)                                       (0xFF000000&((data)<<24))
#define OSDCOMP_OSD3_PLANE_plane_alpha_a_src(data)                                   ((0xFF000000&(data))>>24)
#define OSDCOMP_OSD3_PLANE_get_plane_alpha_a(data)                                   ((0xFF000000&(data))>>24)
#define OSDCOMP_OSD3_PLANE_plane_alpha_r_shift                                       (16)
#define OSDCOMP_OSD3_PLANE_plane_alpha_r_mask                                        (0x00FF0000)
#define OSDCOMP_OSD3_PLANE_plane_alpha_r(data)                                       (0x00FF0000&((data)<<16))
#define OSDCOMP_OSD3_PLANE_plane_alpha_r_src(data)                                   ((0x00FF0000&(data))>>16)
#define OSDCOMP_OSD3_PLANE_get_plane_alpha_r(data)                                   ((0x00FF0000&(data))>>16)
#define OSDCOMP_OSD3_PLANE_plane_alpha_g_shift                                       (8)
#define OSDCOMP_OSD3_PLANE_plane_alpha_g_mask                                        (0x0000FF00)
#define OSDCOMP_OSD3_PLANE_plane_alpha_g(data)                                       (0x0000FF00&((data)<<8))
#define OSDCOMP_OSD3_PLANE_plane_alpha_g_src(data)                                   ((0x0000FF00&(data))>>8)
#define OSDCOMP_OSD3_PLANE_get_plane_alpha_g(data)                                   ((0x0000FF00&(data))>>8)
#define OSDCOMP_OSD3_PLANE_plane_alpha_b_shift                                       (0)
#define OSDCOMP_OSD3_PLANE_plane_alpha_b_mask                                        (0x000000FF)
#define OSDCOMP_OSD3_PLANE_plane_alpha_b(data)                                       (0x000000FF&((data)<<0))
#define OSDCOMP_OSD3_PLANE_plane_alpha_b_src(data)                                   ((0x000000FF&(data))>>0)
#define OSDCOMP_OSD3_PLANE_get_plane_alpha_b(data)                                   ((0x000000FF&(data))>>0)


#define OSDCOMP_BLEND                                                                0x180310c0
#define OSDCOMP_BLEND_reg_addr                                                       "0xB80310C0"
#define OSDCOMP_BLEND_reg                                                            0xB80310C0
#define set_OSDCOMP_BLEND_reg(data)   (*((volatile unsigned int*) OSDCOMP_BLEND_reg)=data)
#define get_OSDCOMP_BLEND_reg   (*((volatile unsigned int*) OSDCOMP_BLEND_reg))
#define OSDCOMP_BLEND_inst_adr                                                       "0x0030"
#define OSDCOMP_BLEND_inst                                                           0x0030
#define OSDCOMP_BLEND_blend_mode_shift                                               (29)
#define OSDCOMP_BLEND_blend_mode_mask                                                (0xE0000000)
#define OSDCOMP_BLEND_blend_mode(data)                                               (0xE0000000&((data)<<29))
#define OSDCOMP_BLEND_blend_mode_src(data)                                           ((0xE0000000&(data))>>29)
#define OSDCOMP_BLEND_get_blend_mode(data)                                           ((0xE0000000&(data))>>29)
#define OSDCOMP_BLEND_w_shift                                                        (16)
#define OSDCOMP_BLEND_w_mask                                                         (0x1FFF0000)
#define OSDCOMP_BLEND_w(data)                                                        (0x1FFF0000&((data)<<16))
#define OSDCOMP_BLEND_w_src(data)                                                    ((0x1FFF0000&(data))>>16)
#define OSDCOMP_BLEND_get_w(data)                                                    ((0x1FFF0000&(data))>>16)
#define OSDCOMP_BLEND_h_shift                                                        (0)
#define OSDCOMP_BLEND_h_mask                                                         (0x00001FFF)
#define OSDCOMP_BLEND_h(data)                                                        (0x00001FFF&((data)<<0))
#define OSDCOMP_BLEND_h_src(data)                                                    ((0x00001FFF&(data))>>0)
#define OSDCOMP_BLEND_get_h(data)                                                    ((0x00001FFF&(data))>>0)


#define OSDCOMP_BLEND_OSD1                                                           0x180310c4
#define OSDCOMP_BLEND_OSD1_reg_addr                                                  "0xB80310C4"
#define OSDCOMP_BLEND_OSD1_reg                                                       0xB80310C4
#define set_OSDCOMP_BLEND_OSD1_reg(data)   (*((volatile unsigned int*) OSDCOMP_BLEND_OSD1_reg)=data)
#define get_OSDCOMP_BLEND_OSD1_reg   (*((volatile unsigned int*) OSDCOMP_BLEND_OSD1_reg))
#define OSDCOMP_BLEND_OSD1_inst_adr                                                  "0x0031"
#define OSDCOMP_BLEND_OSD1_inst                                                      0x0031
#define OSDCOMP_BLEND_OSD1_x_shift                                                   (16)
#define OSDCOMP_BLEND_OSD1_x_mask                                                    (0x1FFF0000)
#define OSDCOMP_BLEND_OSD1_x(data)                                                   (0x1FFF0000&((data)<<16))
#define OSDCOMP_BLEND_OSD1_x_src(data)                                               ((0x1FFF0000&(data))>>16)
#define OSDCOMP_BLEND_OSD1_get_x(data)                                               ((0x1FFF0000&(data))>>16)
#define OSDCOMP_BLEND_OSD1_y_shift                                                   (0)
#define OSDCOMP_BLEND_OSD1_y_mask                                                    (0x00001FFF)
#define OSDCOMP_BLEND_OSD1_y(data)                                                   (0x00001FFF&((data)<<0))
#define OSDCOMP_BLEND_OSD1_y_src(data)                                               ((0x00001FFF&(data))>>0)
#define OSDCOMP_BLEND_OSD1_get_y(data)                                               ((0x00001FFF&(data))>>0)


#define OSDCOMP_BLEND_OSD2                                                           0x180310c8
#define OSDCOMP_BLEND_OSD2_reg_addr                                                  "0xB80310C8"
#define OSDCOMP_BLEND_OSD2_reg                                                       0xB80310C8
#define set_OSDCOMP_BLEND_OSD2_reg(data)   (*((volatile unsigned int*) OSDCOMP_BLEND_OSD2_reg)=data)
#define get_OSDCOMP_BLEND_OSD2_reg   (*((volatile unsigned int*) OSDCOMP_BLEND_OSD2_reg))
#define OSDCOMP_BLEND_OSD2_inst_adr                                                  "0x0032"
#define OSDCOMP_BLEND_OSD2_inst                                                      0x0032
#define OSDCOMP_BLEND_OSD2_x_shift                                                   (16)
#define OSDCOMP_BLEND_OSD2_x_mask                                                    (0x1FFF0000)
#define OSDCOMP_BLEND_OSD2_x(data)                                                   (0x1FFF0000&((data)<<16))
#define OSDCOMP_BLEND_OSD2_x_src(data)                                               ((0x1FFF0000&(data))>>16)
#define OSDCOMP_BLEND_OSD2_get_x(data)                                               ((0x1FFF0000&(data))>>16)
#define OSDCOMP_BLEND_OSD2_y_shift                                                   (0)
#define OSDCOMP_BLEND_OSD2_y_mask                                                    (0x00001FFF)
#define OSDCOMP_BLEND_OSD2_y(data)                                                   (0x00001FFF&((data)<<0))
#define OSDCOMP_BLEND_OSD2_y_src(data)                                               ((0x00001FFF&(data))>>0)
#define OSDCOMP_BLEND_OSD2_get_y(data)                                               ((0x00001FFF&(data))>>0)


#define OSDCOMP_BLEND_OSD3                                                           0x180310cc
#define OSDCOMP_BLEND_OSD3_reg_addr                                                  "0xB80310CC"
#define OSDCOMP_BLEND_OSD3_reg                                                       0xB80310CC
#define set_OSDCOMP_BLEND_OSD3_reg(data)   (*((volatile unsigned int*) OSDCOMP_BLEND_OSD3_reg)=data)
#define get_OSDCOMP_BLEND_OSD3_reg   (*((volatile unsigned int*) OSDCOMP_BLEND_OSD3_reg))
#define OSDCOMP_BLEND_OSD3_inst_adr                                                  "0x0033"
#define OSDCOMP_BLEND_OSD3_inst                                                      0x0033
#define OSDCOMP_BLEND_OSD3_x_shift                                                   (16)
#define OSDCOMP_BLEND_OSD3_x_mask                                                    (0x1FFF0000)
#define OSDCOMP_BLEND_OSD3_x(data)                                                   (0x1FFF0000&((data)<<16))
#define OSDCOMP_BLEND_OSD3_x_src(data)                                               ((0x1FFF0000&(data))>>16)
#define OSDCOMP_BLEND_OSD3_get_x(data)                                               ((0x1FFF0000&(data))>>16)
#define OSDCOMP_BLEND_OSD3_y_shift                                                   (0)
#define OSDCOMP_BLEND_OSD3_y_mask                                                    (0x00001FFF)
#define OSDCOMP_BLEND_OSD3_y(data)                                                   (0x00001FFF&((data)<<0))
#define OSDCOMP_BLEND_OSD3_y_src(data)                                               ((0x00001FFF&(data))>>0)
#define OSDCOMP_BLEND_OSD3_get_y(data)                                               ((0x00001FFF&(data))>>0)


#define OSDCOMP_BLEND_FACTOR1                                                        0x180310d0
#define OSDCOMP_BLEND_FACTOR1_reg_addr                                               "0xB80310D0"
#define OSDCOMP_BLEND_FACTOR1_reg                                                    0xB80310D0
#define set_OSDCOMP_BLEND_FACTOR1_reg(data)   (*((volatile unsigned int*) OSDCOMP_BLEND_FACTOR1_reg)=data)
#define get_OSDCOMP_BLEND_FACTOR1_reg   (*((volatile unsigned int*) OSDCOMP_BLEND_FACTOR1_reg))
#define OSDCOMP_BLEND_FACTOR1_inst_adr                                               "0x0034"
#define OSDCOMP_BLEND_FACTOR1_inst                                                   0x0034
#define OSDCOMP_BLEND_FACTOR1_k1_shift                                               (24)
#define OSDCOMP_BLEND_FACTOR1_k1_mask                                                (0x3F000000)
#define OSDCOMP_BLEND_FACTOR1_k1(data)                                               (0x3F000000&((data)<<24))
#define OSDCOMP_BLEND_FACTOR1_k1_src(data)                                           ((0x3F000000&(data))>>24)
#define OSDCOMP_BLEND_FACTOR1_get_k1(data)                                           ((0x3F000000&(data))>>24)
#define OSDCOMP_BLEND_FACTOR1_k2_shift                                               (16)
#define OSDCOMP_BLEND_FACTOR1_k2_mask                                                (0x003F0000)
#define OSDCOMP_BLEND_FACTOR1_k2(data)                                               (0x003F0000&((data)<<16))
#define OSDCOMP_BLEND_FACTOR1_k2_src(data)                                           ((0x003F0000&(data))>>16)
#define OSDCOMP_BLEND_FACTOR1_get_k2(data)                                           ((0x003F0000&(data))>>16)
#define OSDCOMP_BLEND_FACTOR1_k3_shift                                               (8)
#define OSDCOMP_BLEND_FACTOR1_k3_mask                                                (0x00003F00)
#define OSDCOMP_BLEND_FACTOR1_k3(data)                                               (0x00003F00&((data)<<8))
#define OSDCOMP_BLEND_FACTOR1_k3_src(data)                                           ((0x00003F00&(data))>>8)
#define OSDCOMP_BLEND_FACTOR1_get_k3(data)                                           ((0x00003F00&(data))>>8)
#define OSDCOMP_BLEND_FACTOR1_k4_shift                                               (0)
#define OSDCOMP_BLEND_FACTOR1_k4_mask                                                (0x0000003F)
#define OSDCOMP_BLEND_FACTOR1_k4(data)                                               (0x0000003F&((data)<<0))
#define OSDCOMP_BLEND_FACTOR1_k4_src(data)                                           ((0x0000003F&(data))>>0)
#define OSDCOMP_BLEND_FACTOR1_get_k4(data)                                           ((0x0000003F&(data))>>0)


#define OSDCOMP_BLEND_FACTOR2                                                        0x180310d4
#define OSDCOMP_BLEND_FACTOR2_reg_addr                                               "0xB80310D4"
#define OSDCOMP_BLEND_FACTOR2_reg                                                    0xB80310D4
#define set_OSDCOMP_BLEND_FACTOR2_reg(data)   (*((volatile unsigned int*) OSDCOMP_BLEND_FACTOR2_reg)=data)
#define get_OSDCOMP_BLEND_FACTOR2_reg   (*((volatile unsigned int*) OSDCOMP_BLEND_FACTOR2_reg))
#define OSDCOMP_BLEND_FACTOR2_inst_adr                                               "0x0035"
#define OSDCOMP_BLEND_FACTOR2_inst                                                   0x0035
#define OSDCOMP_BLEND_FACTOR2_k5_shift                                               (24)
#define OSDCOMP_BLEND_FACTOR2_k5_mask                                                (0x3F000000)
#define OSDCOMP_BLEND_FACTOR2_k5(data)                                               (0x3F000000&((data)<<24))
#define OSDCOMP_BLEND_FACTOR2_k5_src(data)                                           ((0x3F000000&(data))>>24)
#define OSDCOMP_BLEND_FACTOR2_get_k5(data)                                           ((0x3F000000&(data))>>24)
#define OSDCOMP_BLEND_FACTOR2_k6_shift                                               (16)
#define OSDCOMP_BLEND_FACTOR2_k6_mask                                                (0x003F0000)
#define OSDCOMP_BLEND_FACTOR2_k6(data)                                               (0x003F0000&((data)<<16))
#define OSDCOMP_BLEND_FACTOR2_k6_src(data)                                           ((0x003F0000&(data))>>16)
#define OSDCOMP_BLEND_FACTOR2_get_k6(data)                                           ((0x003F0000&(data))>>16)
#define OSDCOMP_BLEND_FACTOR2_k7_shift                                               (8)
#define OSDCOMP_BLEND_FACTOR2_k7_mask                                                (0x00003F00)
#define OSDCOMP_BLEND_FACTOR2_k7(data)                                               (0x00003F00&((data)<<8))
#define OSDCOMP_BLEND_FACTOR2_k7_src(data)                                           ((0x00003F00&(data))>>8)
#define OSDCOMP_BLEND_FACTOR2_get_k7(data)                                           ((0x00003F00&(data))>>8)
#define OSDCOMP_BLEND_FACTOR2_k8_shift                                               (0)
#define OSDCOMP_BLEND_FACTOR2_k8_mask                                                (0x0000003F)
#define OSDCOMP_BLEND_FACTOR2_k8(data)                                               (0x0000003F&((data)<<0))
#define OSDCOMP_BLEND_FACTOR2_k8_src(data)                                           ((0x0000003F&(data))>>0)
#define OSDCOMP_BLEND_FACTOR2_get_k8(data)                                           ((0x0000003F&(data))>>0)


#define OSDCOMP_DMA                                                                  0x18031100
#define OSDCOMP_DMA_reg_addr                                                         "0xB8031100"
#define OSDCOMP_DMA_reg                                                              0xB8031100
#define set_OSDCOMP_DMA_reg(data)   (*((volatile unsigned int*) OSDCOMP_DMA_reg)=data)
#define get_OSDCOMP_DMA_reg   (*((volatile unsigned int*) OSDCOMP_DMA_reg))
#define OSDCOMP_DMA_inst_adr                                                         "0x0040"
#define OSDCOMP_DMA_inst                                                             0x0040
#define OSDCOMP_DMA_osd3_bl_shift                                                    (24)
#define OSDCOMP_DMA_osd3_bl_mask                                                     (0x3F000000)
#define OSDCOMP_DMA_osd3_bl(data)                                                    (0x3F000000&((data)<<24))
#define OSDCOMP_DMA_osd3_bl_src(data)                                                ((0x3F000000&(data))>>24)
#define OSDCOMP_DMA_get_osd3_bl(data)                                                ((0x3F000000&(data))>>24)
#define OSDCOMP_DMA_wdma_bl_shift                                                    (16)
#define OSDCOMP_DMA_wdma_bl_mask                                                     (0x003F0000)
#define OSDCOMP_DMA_wdma_bl(data)                                                    (0x003F0000&((data)<<16))
#define OSDCOMP_DMA_wdma_bl_src(data)                                                ((0x003F0000&(data))>>16)
#define OSDCOMP_DMA_get_wdma_bl(data)                                                ((0x003F0000&(data))>>16)
#define OSDCOMP_DMA_osd1_bl_shift                                                    (8)
#define OSDCOMP_DMA_osd1_bl_mask                                                     (0x00003F00)
#define OSDCOMP_DMA_osd1_bl(data)                                                    (0x00003F00&((data)<<8))
#define OSDCOMP_DMA_osd1_bl_src(data)                                                ((0x00003F00&(data))>>8)
#define OSDCOMP_DMA_get_osd1_bl(data)                                                ((0x00003F00&(data))>>8)
#define OSDCOMP_DMA_mult_req_shift                                                   (6)
#define OSDCOMP_DMA_mult_req_mask                                                    (0x000000C0)
#define OSDCOMP_DMA_mult_req(data)                                                   (0x000000C0&((data)<<6))
#define OSDCOMP_DMA_mult_req_src(data)                                               ((0x000000C0&(data))>>6)
#define OSDCOMP_DMA_get_mult_req(data)                                               ((0x000000C0&(data))>>6)
#define OSDCOMP_DMA_osd2_bl_shift                                                    (0)
#define OSDCOMP_DMA_osd2_bl_mask                                                     (0x0000003F)
#define OSDCOMP_DMA_osd2_bl(data)                                                    (0x0000003F&((data)<<0))
#define OSDCOMP_DMA_osd2_bl_src(data)                                                ((0x0000003F&(data))>>0)
#define OSDCOMP_DMA_get_osd2_bl(data)                                                ((0x0000003F&(data))>>0)


#define OSDCOMP_DMA_WL                                                               0x18031104
#define OSDCOMP_DMA_WL_reg_addr                                                      "0xB8031104"
#define OSDCOMP_DMA_WL_reg                                                           0xB8031104
#define set_OSDCOMP_DMA_WL_reg(data)   (*((volatile unsigned int*) OSDCOMP_DMA_WL_reg)=data)
#define get_OSDCOMP_DMA_WL_reg   (*((volatile unsigned int*) OSDCOMP_DMA_WL_reg))
#define OSDCOMP_DMA_WL_inst_adr                                                      "0x0041"
#define OSDCOMP_DMA_WL_inst                                                          0x0041
#define OSDCOMP_DMA_WL_osd1_shift                                                    (12)
#define OSDCOMP_DMA_WL_osd1_mask                                                     (0x00FFF000)
#define OSDCOMP_DMA_WL_osd1(data)                                                    (0x00FFF000&((data)<<12))
#define OSDCOMP_DMA_WL_osd1_src(data)                                                ((0x00FFF000&(data))>>12)
#define OSDCOMP_DMA_WL_get_osd1(data)                                                ((0x00FFF000&(data))>>12)


#define OSDCOMP_OSD1_SEG0                                                            0x18031108
#define OSDCOMP_OSD1_SEG0_reg_addr                                                   "0xB8031108"
#define OSDCOMP_OSD1_SEG0_reg                                                        0xB8031108
#define set_OSDCOMP_OSD1_SEG0_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_SEG0_reg)=data)
#define get_OSDCOMP_OSD1_SEG0_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_SEG0_reg))
#define OSDCOMP_OSD1_SEG0_inst_adr                                                   "0x0042"
#define OSDCOMP_OSD1_SEG0_inst                                                       0x0042
#define OSDCOMP_OSD1_SEG0_num_shift                                                  (0)
#define OSDCOMP_OSD1_SEG0_num_mask                                                   (0x00FFFFFF)
#define OSDCOMP_OSD1_SEG0_num(data)                                                  (0x00FFFFFF&((data)<<0))
#define OSDCOMP_OSD1_SEG0_num_src(data)                                              ((0x00FFFFFF&(data))>>0)
#define OSDCOMP_OSD1_SEG0_get_num(data)                                              ((0x00FFFFFF&(data))>>0)


#define OSDCOMP_OSD1_SEG0_3D                                                         0x1803110c
#define OSDCOMP_OSD1_SEG0_3D_reg_addr                                                "0xB803110C"
#define OSDCOMP_OSD1_SEG0_3D_reg                                                     0xB803110C
#define set_OSDCOMP_OSD1_SEG0_3D_reg(data)   (*((volatile unsigned int*) OSDCOMP_OSD1_SEG0_3D_reg)=data)
#define get_OSDCOMP_OSD1_SEG0_3D_reg   (*((volatile unsigned int*) OSDCOMP_OSD1_SEG0_3D_reg))
#define OSDCOMP_OSD1_SEG0_3D_inst_adr                                                "0x0043"
#define OSDCOMP_OSD1_SEG0_3D_inst                                                    0x0043
#define OSDCOMP_OSD1_SEG0_3D_num_shift                                               (0)
#define OSDCOMP_OSD1_SEG0_3D_num_mask                                                (0x00FFFFFF)
#define OSDCOMP_OSD1_SEG0_3D_num(data)                                               (0x00FFFFFF&((data)<<0))
#define OSDCOMP_OSD1_SEG0_3D_num_src(data)                                           ((0x00FFFFFF&(data))>>0)
#define OSDCOMP_OSD1_SEG0_3D_get_num(data)                                           ((0x00FFFFFF&(data))>>0)


#define OSDCOMP_WDMA_ADR_SEG0                                                        0x18031110
#define OSDCOMP_WDMA_ADR_SEG0_reg_addr                                               "0xB8031110"
#define OSDCOMP_WDMA_ADR_SEG0_reg                                                    0xB8031110
#define set_OSDCOMP_WDMA_ADR_SEG0_reg(data)   (*((volatile unsigned int*) OSDCOMP_WDMA_ADR_SEG0_reg)=data)
#define get_OSDCOMP_WDMA_ADR_SEG0_reg   (*((volatile unsigned int*) OSDCOMP_WDMA_ADR_SEG0_reg))
#define OSDCOMP_WDMA_ADR_SEG0_inst_adr                                               "0x0044"
#define OSDCOMP_WDMA_ADR_SEG0_inst                                                   0x0044
#define OSDCOMP_WDMA_ADR_SEG0_a_shift                                                (0)
#define OSDCOMP_WDMA_ADR_SEG0_a_mask                                                 (0xFFFFFFFF)
#define OSDCOMP_WDMA_ADR_SEG0_a(data)                                                (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_WDMA_ADR_SEG0_a_src(data)                                            ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_WDMA_ADR_SEG0_get_a(data)                                            ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_WDMA_ADR_SEG0_3D                                                     0x18031114
#define OSDCOMP_WDMA_ADR_SEG0_3D_reg_addr                                            "0xB8031114"
#define OSDCOMP_WDMA_ADR_SEG0_3D_reg                                                 0xB8031114
#define set_OSDCOMP_WDMA_ADR_SEG0_3D_reg(data)   (*((volatile unsigned int*) OSDCOMP_WDMA_ADR_SEG0_3D_reg)=data)
#define get_OSDCOMP_WDMA_ADR_SEG0_3D_reg   (*((volatile unsigned int*) OSDCOMP_WDMA_ADR_SEG0_3D_reg))
#define OSDCOMP_WDMA_ADR_SEG0_3D_inst_adr                                            "0x0045"
#define OSDCOMP_WDMA_ADR_SEG0_3D_inst                                                0x0045
#define OSDCOMP_WDMA_ADR_SEG0_3D_a_shift                                             (0)
#define OSDCOMP_WDMA_ADR_SEG0_3D_a_mask                                              (0xFFFFFFFF)
#define OSDCOMP_WDMA_ADR_SEG0_3D_a(data)                                             (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_WDMA_ADR_SEG0_3D_a_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_WDMA_ADR_SEG0_3D_get_a(data)                                         ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_WDMA_SEG0                                                            0x18031118
#define OSDCOMP_WDMA_SEG0_reg_addr                                                   "0xB8031118"
#define OSDCOMP_WDMA_SEG0_reg                                                        0xB8031118
#define set_OSDCOMP_WDMA_SEG0_reg(data)   (*((volatile unsigned int*) OSDCOMP_WDMA_SEG0_reg)=data)
#define get_OSDCOMP_WDMA_SEG0_reg   (*((volatile unsigned int*) OSDCOMP_WDMA_SEG0_reg))
#define OSDCOMP_WDMA_SEG0_inst_adr                                                   "0x0046"
#define OSDCOMP_WDMA_SEG0_inst                                                       0x0046
#define OSDCOMP_WDMA_SEG0_size_shift                                                 (0)
#define OSDCOMP_WDMA_SEG0_size_mask                                                  (0xFFFFFFFF)
#define OSDCOMP_WDMA_SEG0_size(data)                                                 (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_WDMA_SEG0_size_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_WDMA_SEG0_get_size(data)                                             ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_WDMA_SEG0_3D                                                         0x1803111c
#define OSDCOMP_WDMA_SEG0_3D_reg_addr                                                "0xB803111C"
#define OSDCOMP_WDMA_SEG0_3D_reg                                                     0xB803111C
#define set_OSDCOMP_WDMA_SEG0_3D_reg(data)   (*((volatile unsigned int*) OSDCOMP_WDMA_SEG0_3D_reg)=data)
#define get_OSDCOMP_WDMA_SEG0_3D_reg   (*((volatile unsigned int*) OSDCOMP_WDMA_SEG0_3D_reg))
#define OSDCOMP_WDMA_SEG0_3D_inst_adr                                                "0x0047"
#define OSDCOMP_WDMA_SEG0_3D_inst                                                    0x0047
#define OSDCOMP_WDMA_SEG0_3D_size_shift                                              (0)
#define OSDCOMP_WDMA_SEG0_3D_size_mask                                               (0xFFFFFFFF)
#define OSDCOMP_WDMA_SEG0_3D_size(data)                                              (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_WDMA_SEG0_3D_size_src(data)                                          ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_WDMA_SEG0_3D_get_size(data)                                          ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_WDMA_CRC                                                             0x18031120
#define OSDCOMP_WDMA_CRC_reg_addr                                                    "0xB8031120"
#define OSDCOMP_WDMA_CRC_reg                                                         0xB8031120
#define set_OSDCOMP_WDMA_CRC_reg(data)   (*((volatile unsigned int*) OSDCOMP_WDMA_CRC_reg)=data)
#define get_OSDCOMP_WDMA_CRC_reg   (*((volatile unsigned int*) OSDCOMP_WDMA_CRC_reg))
#define OSDCOMP_WDMA_CRC_inst_adr                                                    "0x0048"
#define OSDCOMP_WDMA_CRC_inst                                                        0x0048
#define OSDCOMP_WDMA_CRC_conti_shift                                                 (1)
#define OSDCOMP_WDMA_CRC_conti_mask                                                  (0x00000002)
#define OSDCOMP_WDMA_CRC_conti(data)                                                 (0x00000002&((data)<<1))
#define OSDCOMP_WDMA_CRC_conti_src(data)                                             ((0x00000002&(data))>>1)
#define OSDCOMP_WDMA_CRC_get_conti(data)                                             ((0x00000002&(data))>>1)
#define OSDCOMP_WDMA_CRC_start_shift                                                 (0)
#define OSDCOMP_WDMA_CRC_start_mask                                                  (0x00000001)
#define OSDCOMP_WDMA_CRC_start(data)                                                 (0x00000001&((data)<<0))
#define OSDCOMP_WDMA_CRC_start_src(data)                                             ((0x00000001&(data))>>0)
#define OSDCOMP_WDMA_CRC_get_start(data)                                             ((0x00000001&(data))>>0)


#define OSDCOMP_WDMA_SEG0_CRC                                                        0x18031124
#define OSDCOMP_WDMA_SEG0_CRC_reg_addr                                               "0xB8031124"
#define OSDCOMP_WDMA_SEG0_CRC_reg                                                    0xB8031124
#define set_OSDCOMP_WDMA_SEG0_CRC_reg(data)   (*((volatile unsigned int*) OSDCOMP_WDMA_SEG0_CRC_reg)=data)
#define get_OSDCOMP_WDMA_SEG0_CRC_reg   (*((volatile unsigned int*) OSDCOMP_WDMA_SEG0_CRC_reg))
#define OSDCOMP_WDMA_SEG0_CRC_inst_adr                                               "0x0049"
#define OSDCOMP_WDMA_SEG0_CRC_inst                                                   0x0049
#define OSDCOMP_WDMA_SEG0_CRC_result_shift                                           (0)
#define OSDCOMP_WDMA_SEG0_CRC_result_mask                                            (0xFFFFFFFF)
#define OSDCOMP_WDMA_SEG0_CRC_result(data)                                           (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_WDMA_SEG0_CRC_result_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_WDMA_SEG0_CRC_get_result(data)                                       ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_DMA_SWAP                                                             0x18031128
#define OSDCOMP_DMA_SWAP_reg_addr                                                    "0xB8031128"
#define OSDCOMP_DMA_SWAP_reg                                                         0xB8031128
#define set_OSDCOMP_DMA_SWAP_reg(data)   (*((volatile unsigned int*) OSDCOMP_DMA_SWAP_reg)=data)
#define get_OSDCOMP_DMA_SWAP_reg   (*((volatile unsigned int*) OSDCOMP_DMA_SWAP_reg))
#define OSDCOMP_DMA_SWAP_inst_adr                                                    "0x004A"
#define OSDCOMP_DMA_SWAP_inst                                                        0x004A
#define OSDCOMP_DMA_SWAP_osd3_1b_shift                                               (19)
#define OSDCOMP_DMA_SWAP_osd3_1b_mask                                                (0x00080000)
#define OSDCOMP_DMA_SWAP_osd3_1b(data)                                               (0x00080000&((data)<<19))
#define OSDCOMP_DMA_SWAP_osd3_1b_src(data)                                           ((0x00080000&(data))>>19)
#define OSDCOMP_DMA_SWAP_get_osd3_1b(data)                                           ((0x00080000&(data))>>19)
#define OSDCOMP_DMA_SWAP_osd3_2b_shift                                               (18)
#define OSDCOMP_DMA_SWAP_osd3_2b_mask                                                (0x00040000)
#define OSDCOMP_DMA_SWAP_osd3_2b(data)                                               (0x00040000&((data)<<18))
#define OSDCOMP_DMA_SWAP_osd3_2b_src(data)                                           ((0x00040000&(data))>>18)
#define OSDCOMP_DMA_SWAP_get_osd3_2b(data)                                           ((0x00040000&(data))>>18)
#define OSDCOMP_DMA_SWAP_osd3_4b_shift                                               (17)
#define OSDCOMP_DMA_SWAP_osd3_4b_mask                                                (0x00020000)
#define OSDCOMP_DMA_SWAP_osd3_4b(data)                                               (0x00020000&((data)<<17))
#define OSDCOMP_DMA_SWAP_osd3_4b_src(data)                                           ((0x00020000&(data))>>17)
#define OSDCOMP_DMA_SWAP_get_osd3_4b(data)                                           ((0x00020000&(data))>>17)
#define OSDCOMP_DMA_SWAP_osd3_8b_shift                                               (16)
#define OSDCOMP_DMA_SWAP_osd3_8b_mask                                                (0x00010000)
#define OSDCOMP_DMA_SWAP_osd3_8b(data)                                               (0x00010000&((data)<<16))
#define OSDCOMP_DMA_SWAP_osd3_8b_src(data)                                           ((0x00010000&(data))>>16)
#define OSDCOMP_DMA_SWAP_get_osd3_8b(data)                                           ((0x00010000&(data))>>16)
#define OSDCOMP_DMA_SWAP_osd1_1b_shift                                               (15)
#define OSDCOMP_DMA_SWAP_osd1_1b_mask                                                (0x00008000)
#define OSDCOMP_DMA_SWAP_osd1_1b(data)                                               (0x00008000&((data)<<15))
#define OSDCOMP_DMA_SWAP_osd1_1b_src(data)                                           ((0x00008000&(data))>>15)
#define OSDCOMP_DMA_SWAP_get_osd1_1b(data)                                           ((0x00008000&(data))>>15)
#define OSDCOMP_DMA_SWAP_osd1_2b_shift                                               (14)
#define OSDCOMP_DMA_SWAP_osd1_2b_mask                                                (0x00004000)
#define OSDCOMP_DMA_SWAP_osd1_2b(data)                                               (0x00004000&((data)<<14))
#define OSDCOMP_DMA_SWAP_osd1_2b_src(data)                                           ((0x00004000&(data))>>14)
#define OSDCOMP_DMA_SWAP_get_osd1_2b(data)                                           ((0x00004000&(data))>>14)
#define OSDCOMP_DMA_SWAP_osd1_4b_shift                                               (13)
#define OSDCOMP_DMA_SWAP_osd1_4b_mask                                                (0x00002000)
#define OSDCOMP_DMA_SWAP_osd1_4b(data)                                               (0x00002000&((data)<<13))
#define OSDCOMP_DMA_SWAP_osd1_4b_src(data)                                           ((0x00002000&(data))>>13)
#define OSDCOMP_DMA_SWAP_get_osd1_4b(data)                                           ((0x00002000&(data))>>13)
#define OSDCOMP_DMA_SWAP_osd1_8b_shift                                               (12)
#define OSDCOMP_DMA_SWAP_osd1_8b_mask                                                (0x00001000)
#define OSDCOMP_DMA_SWAP_osd1_8b(data)                                               (0x00001000&((data)<<12))
#define OSDCOMP_DMA_SWAP_osd1_8b_src(data)                                           ((0x00001000&(data))>>12)
#define OSDCOMP_DMA_SWAP_get_osd1_8b(data)                                           ((0x00001000&(data))>>12)
#define OSDCOMP_DMA_SWAP_osd2_1b_shift                                               (11)
#define OSDCOMP_DMA_SWAP_osd2_1b_mask                                                (0x00000800)
#define OSDCOMP_DMA_SWAP_osd2_1b(data)                                               (0x00000800&((data)<<11))
#define OSDCOMP_DMA_SWAP_osd2_1b_src(data)                                           ((0x00000800&(data))>>11)
#define OSDCOMP_DMA_SWAP_get_osd2_1b(data)                                           ((0x00000800&(data))>>11)
#define OSDCOMP_DMA_SWAP_osd2_2b_shift                                               (10)
#define OSDCOMP_DMA_SWAP_osd2_2b_mask                                                (0x00000400)
#define OSDCOMP_DMA_SWAP_osd2_2b(data)                                               (0x00000400&((data)<<10))
#define OSDCOMP_DMA_SWAP_osd2_2b_src(data)                                           ((0x00000400&(data))>>10)
#define OSDCOMP_DMA_SWAP_get_osd2_2b(data)                                           ((0x00000400&(data))>>10)
#define OSDCOMP_DMA_SWAP_osd2_4b_shift                                               (9)
#define OSDCOMP_DMA_SWAP_osd2_4b_mask                                                (0x00000200)
#define OSDCOMP_DMA_SWAP_osd2_4b(data)                                               (0x00000200&((data)<<9))
#define OSDCOMP_DMA_SWAP_osd2_4b_src(data)                                           ((0x00000200&(data))>>9)
#define OSDCOMP_DMA_SWAP_get_osd2_4b(data)                                           ((0x00000200&(data))>>9)
#define OSDCOMP_DMA_SWAP_osd2_8b_shift                                               (8)
#define OSDCOMP_DMA_SWAP_osd2_8b_mask                                                (0x00000100)
#define OSDCOMP_DMA_SWAP_osd2_8b(data)                                               (0x00000100&((data)<<8))
#define OSDCOMP_DMA_SWAP_osd2_8b_src(data)                                           ((0x00000100&(data))>>8)
#define OSDCOMP_DMA_SWAP_get_osd2_8b(data)                                           ((0x00000100&(data))>>8)
#define OSDCOMP_DMA_SWAP_w_1b_shift                                                  (7)
#define OSDCOMP_DMA_SWAP_w_1b_mask                                                   (0x00000080)
#define OSDCOMP_DMA_SWAP_w_1b(data)                                                  (0x00000080&((data)<<7))
#define OSDCOMP_DMA_SWAP_w_1b_src(data)                                              ((0x00000080&(data))>>7)
#define OSDCOMP_DMA_SWAP_get_w_1b(data)                                              ((0x00000080&(data))>>7)
#define OSDCOMP_DMA_SWAP_w_2b_shift                                                  (6)
#define OSDCOMP_DMA_SWAP_w_2b_mask                                                   (0x00000040)
#define OSDCOMP_DMA_SWAP_w_2b(data)                                                  (0x00000040&((data)<<6))
#define OSDCOMP_DMA_SWAP_w_2b_src(data)                                              ((0x00000040&(data))>>6)
#define OSDCOMP_DMA_SWAP_get_w_2b(data)                                              ((0x00000040&(data))>>6)
#define OSDCOMP_DMA_SWAP_w_4b_shift                                                  (5)
#define OSDCOMP_DMA_SWAP_w_4b_mask                                                   (0x00000020)
#define OSDCOMP_DMA_SWAP_w_4b(data)                                                  (0x00000020&((data)<<5))
#define OSDCOMP_DMA_SWAP_w_4b_src(data)                                              ((0x00000020&(data))>>5)
#define OSDCOMP_DMA_SWAP_get_w_4b(data)                                              ((0x00000020&(data))>>5)
#define OSDCOMP_DMA_SWAP_w_8b_shift                                                  (4)
#define OSDCOMP_DMA_SWAP_w_8b_mask                                                   (0x00000010)
#define OSDCOMP_DMA_SWAP_w_8b(data)                                                  (0x00000010&((data)<<4))
#define OSDCOMP_DMA_SWAP_w_8b_src(data)                                              ((0x00000010&(data))>>4)
#define OSDCOMP_DMA_SWAP_get_w_8b(data)                                              ((0x00000010&(data))>>4)
#define OSDCOMP_DMA_SWAP_write_data_shift                                            (0)
#define OSDCOMP_DMA_SWAP_write_data_mask                                             (0x00000001)
#define OSDCOMP_DMA_SWAP_write_data(data)                                            (0x00000001&((data)<<0))
#define OSDCOMP_DMA_SWAP_write_data_src(data)                                        ((0x00000001&(data))>>0)
#define OSDCOMP_DMA_SWAP_get_write_data(data)                                        ((0x00000001&(data))>>0)


#define OSDCOMP_INTEN                                                                0x18031160
#define OSDCOMP_INTEN_reg_addr                                                       "0xB8031160"
#define OSDCOMP_INTEN_reg                                                            0xB8031160
#define set_OSDCOMP_INTEN_reg(data)   (*((volatile unsigned int*) OSDCOMP_INTEN_reg)=data)
#define get_OSDCOMP_INTEN_reg   (*((volatile unsigned int*) OSDCOMP_INTEN_reg))
#define OSDCOMP_INTEN_inst_adr                                                       "0x0058"
#define OSDCOMP_INTEN_inst                                                           0x0058
#define OSDCOMP_INTEN_wdma_ovfl_shift                                                (13)
#define OSDCOMP_INTEN_wdma_ovfl_mask                                                 (0x00002000)
#define OSDCOMP_INTEN_wdma_ovfl(data)                                                (0x00002000&((data)<<13))
#define OSDCOMP_INTEN_wdma_ovfl_src(data)                                            ((0x00002000&(data))>>13)
#define OSDCOMP_INTEN_get_wdma_ovfl(data)                                            ((0x00002000&(data))>>13)
#define OSDCOMP_INTEN_wdma_udfl_shift                                                (12)
#define OSDCOMP_INTEN_wdma_udfl_mask                                                 (0x00001000)
#define OSDCOMP_INTEN_wdma_udfl(data)                                                (0x00001000&((data)<<12))
#define OSDCOMP_INTEN_wdma_udfl_src(data)                                            ((0x00001000&(data))>>12)
#define OSDCOMP_INTEN_get_wdma_udfl(data)                                            ((0x00001000&(data))>>12)
#define OSDCOMP_INTEN_done_shift                                                     (1)
#define OSDCOMP_INTEN_done_mask                                                      (0x00000002)
#define OSDCOMP_INTEN_done(data)                                                     (0x00000002&((data)<<1))
#define OSDCOMP_INTEN_done_src(data)                                                 ((0x00000002&(data))>>1)
#define OSDCOMP_INTEN_get_done(data)                                                 ((0x00000002&(data))>>1)
#define OSDCOMP_INTEN_write_data_shift                                               (0)
#define OSDCOMP_INTEN_write_data_mask                                                (0x00000001)
#define OSDCOMP_INTEN_write_data(data)                                               (0x00000001&((data)<<0))
#define OSDCOMP_INTEN_write_data_src(data)                                           ((0x00000001&(data))>>0)
#define OSDCOMP_INTEN_get_write_data(data)                                           ((0x00000001&(data))>>0)


#define OSDCOMP_INTST                                                                0x18031164
#define OSDCOMP_INTST_reg_addr                                                       "0xB8031164"
#define OSDCOMP_INTST_reg                                                            0xB8031164
#define set_OSDCOMP_INTST_reg(data)   (*((volatile unsigned int*) OSDCOMP_INTST_reg)=data)
#define get_OSDCOMP_INTST_reg   (*((volatile unsigned int*) OSDCOMP_INTST_reg))
#define OSDCOMP_INTST_inst_adr                                                       "0x0059"
#define OSDCOMP_INTST_inst                                                           0x0059
#define OSDCOMP_INTST_wdma_ovfl_shift                                                (13)
#define OSDCOMP_INTST_wdma_ovfl_mask                                                 (0x00002000)
#define OSDCOMP_INTST_wdma_ovfl(data)                                                (0x00002000&((data)<<13))
#define OSDCOMP_INTST_wdma_ovfl_src(data)                                            ((0x00002000&(data))>>13)
#define OSDCOMP_INTST_get_wdma_ovfl(data)                                            ((0x00002000&(data))>>13)
#define OSDCOMP_INTST_wdma_udfl_shift                                                (12)
#define OSDCOMP_INTST_wdma_udfl_mask                                                 (0x00001000)
#define OSDCOMP_INTST_wdma_udfl(data)                                                (0x00001000&((data)<<12))
#define OSDCOMP_INTST_wdma_udfl_src(data)                                            ((0x00001000&(data))>>12)
#define OSDCOMP_INTST_get_wdma_udfl(data)                                            ((0x00001000&(data))>>12)
#define OSDCOMP_INTST_done_shift                                                     (1)
#define OSDCOMP_INTST_done_mask                                                      (0x00000002)
#define OSDCOMP_INTST_done(data)                                                     (0x00000002&((data)<<1))
#define OSDCOMP_INTST_done_src(data)                                                 ((0x00000002&(data))>>1)
#define OSDCOMP_INTST_get_done(data)                                                 ((0x00000002&(data))>>1)
#define OSDCOMP_INTST_write_data_shift                                               (0)
#define OSDCOMP_INTST_write_data_mask                                                (0x00000001)
#define OSDCOMP_INTST_write_data(data)                                               (0x00000001&((data)<<0))
#define OSDCOMP_INTST_write_data_src(data)                                           ((0x00000001&(data))>>0)
#define OSDCOMP_INTST_get_write_data(data)                                           ((0x00000001&(data))>>0)


#define OSDCOMP_CMP_RESOLUTION                                                       0x18031170
#define OSDCOMP_CMP_RESOLUTION_reg_addr                                              "0xB8031170"
#define OSDCOMP_CMP_RESOLUTION_reg                                                   0xB8031170
#define set_OSDCOMP_CMP_RESOLUTION_reg(data)   (*((volatile unsigned int*) OSDCOMP_CMP_RESOLUTION_reg)=data)
#define get_OSDCOMP_CMP_RESOLUTION_reg   (*((volatile unsigned int*) OSDCOMP_CMP_RESOLUTION_reg))
#define OSDCOMP_CMP_RESOLUTION_inst_adr                                              "0x005C"
#define OSDCOMP_CMP_RESOLUTION_inst                                                  0x005C
#define OSDCOMP_CMP_RESOLUTION_cmp_width_shift                                       (16)
#define OSDCOMP_CMP_RESOLUTION_cmp_width_mask                                        (0x00FF0000)
#define OSDCOMP_CMP_RESOLUTION_cmp_width(data)                                       (0x00FF0000&((data)<<16))
#define OSDCOMP_CMP_RESOLUTION_cmp_width_src(data)                                   ((0x00FF0000&(data))>>16)
#define OSDCOMP_CMP_RESOLUTION_get_cmp_width(data)                                   ((0x00FF0000&(data))>>16)
#define OSDCOMP_CMP_RESOLUTION_cmp_height_shift                                      (0)
#define OSDCOMP_CMP_RESOLUTION_cmp_height_mask                                       (0x0000FFFF)
#define OSDCOMP_CMP_RESOLUTION_cmp_height(data)                                      (0x0000FFFF&((data)<<0))
#define OSDCOMP_CMP_RESOLUTION_cmp_height_src(data)                                  ((0x0000FFFF&(data))>>0)
#define OSDCOMP_CMP_RESOLUTION_get_cmp_height(data)                                  ((0x0000FFFF&(data))>>0)


#define OSDCOMP_CMP_SETTING                                                          0x18031174
#define OSDCOMP_CMP_SETTING_reg_addr                                                 "0xB8031174"
#define OSDCOMP_CMP_SETTING_reg                                                      0xB8031174
#define set_OSDCOMP_CMP_SETTING_reg(data)   (*((volatile unsigned int*) OSDCOMP_CMP_SETTING_reg)=data)
#define get_OSDCOMP_CMP_SETTING_reg   (*((volatile unsigned int*) OSDCOMP_CMP_SETTING_reg))
#define OSDCOMP_CMP_SETTING_inst_adr                                                 "0x005D"
#define OSDCOMP_CMP_SETTING_inst                                                     0x005D
#define OSDCOMP_CMP_SETTING_cmp_a_ch_mark_shift                                      (31)
#define OSDCOMP_CMP_SETTING_cmp_a_ch_mark_mask                                       (0x80000000)
#define OSDCOMP_CMP_SETTING_cmp_a_ch_mark(data)                                      (0x80000000&((data)<<31))
#define OSDCOMP_CMP_SETTING_cmp_a_ch_mark_src(data)                                  ((0x80000000&(data))>>31)
#define OSDCOMP_CMP_SETTING_get_cmp_a_ch_mark(data)                                  ((0x80000000&(data))>>31)
#define OSDCOMP_CMP_SETTING_cmp_444to422_en_shift                                    (30)
#define OSDCOMP_CMP_SETTING_cmp_444to422_en_mask                                     (0x40000000)
#define OSDCOMP_CMP_SETTING_cmp_444to422_en(data)                                    (0x40000000&((data)<<30))
#define OSDCOMP_CMP_SETTING_cmp_444to422_en_src(data)                                ((0x40000000&(data))>>30)
#define OSDCOMP_CMP_SETTING_get_cmp_444to422_en(data)                                ((0x40000000&(data))>>30)
#define OSDCOMP_CMP_SETTING_cmp_RGB_YC_sel_shift                                     (29)
#define OSDCOMP_CMP_SETTING_cmp_RGB_YC_sel_mask                                      (0x20000000)
#define OSDCOMP_CMP_SETTING_cmp_RGB_YC_sel(data)                                     (0x20000000&((data)<<29))
#define OSDCOMP_CMP_SETTING_cmp_RGB_YC_sel_src(data)                                 ((0x20000000&(data))>>29)
#define OSDCOMP_CMP_SETTING_get_cmp_RGB_YC_sel(data)                                 ((0x20000000&(data))>>29)
#define OSDCOMP_CMP_SETTING_cmp_channel_bits_shift                                   (28)
#define OSDCOMP_CMP_SETTING_cmp_channel_bits_mask                                    (0x10000000)
#define OSDCOMP_CMP_SETTING_cmp_channel_bits(data)                                   (0x10000000&((data)<<28))
#define OSDCOMP_CMP_SETTING_cmp_channel_bits_src(data)                               ((0x10000000&(data))>>28)
#define OSDCOMP_CMP_SETTING_get_cmp_channel_bits(data)                               ((0x10000000&(data))>>28)
#define OSDCOMP_CMP_SETTING_max_pixel_bits_shift                                     (12)
#define OSDCOMP_CMP_SETTING_max_pixel_bits_mask                                      (0x0003F000)
#define OSDCOMP_CMP_SETTING_max_pixel_bits(data)                                     (0x0003F000&((data)<<12))
#define OSDCOMP_CMP_SETTING_max_pixel_bits_src(data)                                 ((0x0003F000&(data))>>12)
#define OSDCOMP_CMP_SETTING_get_max_pixel_bits(data)                                 ((0x0003F000&(data))>>12)
#define OSDCOMP_CMP_SETTING_short_term_bits_shift                                    (6)
#define OSDCOMP_CMP_SETTING_short_term_bits_mask                                     (0x00000FC0)
#define OSDCOMP_CMP_SETTING_short_term_bits(data)                                    (0x00000FC0&((data)<<6))
#define OSDCOMP_CMP_SETTING_short_term_bits_src(data)                                ((0x00000FC0&(data))>>6)
#define OSDCOMP_CMP_SETTING_get_short_term_bits(data)                                ((0x00000FC0&(data))>>6)
#define OSDCOMP_CMP_SETTING_frame_bits_shift                                         (0)
#define OSDCOMP_CMP_SETTING_frame_bits_mask                                          (0x0000003F)
#define OSDCOMP_CMP_SETTING_frame_bits(data)                                         (0x0000003F&((data)<<0))
#define OSDCOMP_CMP_SETTING_frame_bits_src(data)                                     ((0x0000003F&(data))>>0)
#define OSDCOMP_CMP_SETTING_get_frame_bits(data)                                     ((0x0000003F&(data))>>0)


#define OSDCOMP_COMP_INTEN                                                           0x18031178
#define OSDCOMP_COMP_INTEN_reg_addr                                                  "0xB8031178"
#define OSDCOMP_COMP_INTEN_reg                                                       0xB8031178
#define set_OSDCOMP_COMP_INTEN_reg(data)   (*((volatile unsigned int*) OSDCOMP_COMP_INTEN_reg)=data)
#define get_OSDCOMP_COMP_INTEN_reg   (*((volatile unsigned int*) OSDCOMP_COMP_INTEN_reg))
#define OSDCOMP_COMP_INTEN_inst_adr                                                  "0x005E"
#define OSDCOMP_COMP_INTEN_inst                                                      0x005E
#define OSDCOMP_COMP_INTEN_not_segment_status_clr_shift                              (5)
#define OSDCOMP_COMP_INTEN_not_segment_status_clr_mask                               (0x00000020)
#define OSDCOMP_COMP_INTEN_not_segment_status_clr(data)                              (0x00000020&((data)<<5))
#define OSDCOMP_COMP_INTEN_not_segment_status_clr_src(data)                          ((0x00000020&(data))>>5)
#define OSDCOMP_COMP_INTEN_get_not_segment_status_clr(data)                          ((0x00000020&(data))>>5)
#define OSDCOMP_COMP_INTEN_pixel_num_status_clr_shift                                (4)
#define OSDCOMP_COMP_INTEN_pixel_num_status_clr_mask                                 (0x00000010)
#define OSDCOMP_COMP_INTEN_pixel_num_status_clr(data)                                (0x00000010&((data)<<4))
#define OSDCOMP_COMP_INTEN_pixel_num_status_clr_src(data)                            ((0x00000010&(data))>>4)
#define OSDCOMP_COMP_INTEN_get_pixel_num_status_clr(data)                            ((0x00000010&(data))>>4)
#define OSDCOMP_COMP_INTEN_over_bits_status_clr_shift                                (3)
#define OSDCOMP_COMP_INTEN_over_bits_status_clr_mask                                 (0x00000008)
#define OSDCOMP_COMP_INTEN_over_bits_status_clr(data)                                (0x00000008&((data)<<3))
#define OSDCOMP_COMP_INTEN_over_bits_status_clr_src(data)                            ((0x00000008&(data))>>3)
#define OSDCOMP_COMP_INTEN_get_over_bits_status_clr(data)                            ((0x00000008&(data))>>3)
#define OSDCOMP_COMP_INTEN_comp_irq_en_shift                                         (0)
#define OSDCOMP_COMP_INTEN_comp_irq_en_mask                                          (0x00000007)
#define OSDCOMP_COMP_INTEN_comp_irq_en(data)                                         (0x00000007&((data)<<0))
#define OSDCOMP_COMP_INTEN_comp_irq_en_src(data)                                     ((0x00000007&(data))>>0)
#define OSDCOMP_COMP_INTEN_get_comp_irq_en(data)                                     ((0x00000007&(data))>>0)


#define OSDCOMP_COMP_INTST                                                           0x1803117c
#define OSDCOMP_COMP_INTST_reg_addr                                                  "0xB803117C"
#define OSDCOMP_COMP_INTST_reg                                                       0xB803117C
#define set_OSDCOMP_COMP_INTST_reg(data)   (*((volatile unsigned int*) OSDCOMP_COMP_INTST_reg)=data)
#define get_OSDCOMP_COMP_INTST_reg   (*((volatile unsigned int*) OSDCOMP_COMP_INTST_reg))
#define OSDCOMP_COMP_INTST_inst_adr                                                  "0x005F"
#define OSDCOMP_COMP_INTST_inst                                                      0x005F
#define OSDCOMP_COMP_INTST_comp_irq_shift                                            (3)
#define OSDCOMP_COMP_INTST_comp_irq_mask                                             (0x00000008)
#define OSDCOMP_COMP_INTST_comp_irq(data)                                            (0x00000008&((data)<<3))
#define OSDCOMP_COMP_INTST_comp_irq_src(data)                                        ((0x00000008&(data))>>3)
#define OSDCOMP_COMP_INTST_get_comp_irq(data)                                        ((0x00000008&(data))>>3)
#define OSDCOMP_COMP_INTST_comp_status_shift                                         (0)
#define OSDCOMP_COMP_INTST_comp_status_mask                                          (0x00000007)
#define OSDCOMP_COMP_INTST_comp_status(data)                                         (0x00000007&((data)<<0))
#define OSDCOMP_COMP_INTST_comp_status_src(data)                                     ((0x00000007&(data))>>0)
#define OSDCOMP_COMP_INTST_get_comp_status(data)                                     ((0x00000007&(data))>>0)


#define OSDCOMP_DECMP_RESOLUTION                                                     0x18031180
#define OSDCOMP_DECMP_RESOLUTION_reg_addr                                            "0xB8031180"
#define OSDCOMP_DECMP_RESOLUTION_reg                                                 0xB8031180
#define set_OSDCOMP_DECMP_RESOLUTION_reg(data)   (*((volatile unsigned int*) OSDCOMP_DECMP_RESOLUTION_reg)=data)
#define get_OSDCOMP_DECMP_RESOLUTION_reg   (*((volatile unsigned int*) OSDCOMP_DECMP_RESOLUTION_reg))
#define OSDCOMP_DECMP_RESOLUTION_inst_adr                                            "0x0060"
#define OSDCOMP_DECMP_RESOLUTION_inst                                                0x0060
#define OSDCOMP_DECMP_RESOLUTION_decmp_switch_shift                                  (28)
#define OSDCOMP_DECMP_RESOLUTION_decmp_switch_mask                                   (0x70000000)
#define OSDCOMP_DECMP_RESOLUTION_decmp_switch(data)                                  (0x70000000&((data)<<28))
#define OSDCOMP_DECMP_RESOLUTION_decmp_switch_src(data)                              ((0x70000000&(data))>>28)
#define OSDCOMP_DECMP_RESOLUTION_get_decmp_switch(data)                              ((0x70000000&(data))>>28)
#define OSDCOMP_DECMP_RESOLUTION_decmp_width_shift                                   (16)
#define OSDCOMP_DECMP_RESOLUTION_decmp_width_mask                                    (0x00FF0000)
#define OSDCOMP_DECMP_RESOLUTION_decmp_width(data)                                   (0x00FF0000&((data)<<16))
#define OSDCOMP_DECMP_RESOLUTION_decmp_width_src(data)                               ((0x00FF0000&(data))>>16)
#define OSDCOMP_DECMP_RESOLUTION_get_decmp_width(data)                               ((0x00FF0000&(data))>>16)
#define OSDCOMP_DECMP_RESOLUTION_decmp_height_shift                                  (0)
#define OSDCOMP_DECMP_RESOLUTION_decmp_height_mask                                   (0x0000FFFF)
#define OSDCOMP_DECMP_RESOLUTION_decmp_height(data)                                  (0x0000FFFF&((data)<<0))
#define OSDCOMP_DECMP_RESOLUTION_decmp_height_src(data)                              ((0x0000FFFF&(data))>>0)
#define OSDCOMP_DECMP_RESOLUTION_get_decmp_height(data)                              ((0x0000FFFF&(data))>>0)


#define OSDCOMP_DECMP_SETTING                                                        0x18031184
#define OSDCOMP_DECMP_SETTING_reg_addr                                               "0xB8031184"
#define OSDCOMP_DECMP_SETTING_reg                                                    0xB8031184
#define set_OSDCOMP_DECMP_SETTING_reg(data)   (*((volatile unsigned int*) OSDCOMP_DECMP_SETTING_reg)=data)
#define get_OSDCOMP_DECMP_SETTING_reg   (*((volatile unsigned int*) OSDCOMP_DECMP_SETTING_reg))
#define OSDCOMP_DECMP_SETTING_inst_adr                                               "0x0061"
#define OSDCOMP_DECMP_SETTING_inst                                                   0x0061
#define OSDCOMP_DECMP_SETTING_a_sat_en_shift                                         (17)
#define OSDCOMP_DECMP_SETTING_a_sat_en_mask                                          (0x00020000)
#define OSDCOMP_DECMP_SETTING_a_sat_en(data)                                         (0x00020000&((data)<<17))
#define OSDCOMP_DECMP_SETTING_a_sat_en_src(data)                                     ((0x00020000&(data))>>17)
#define OSDCOMP_DECMP_SETTING_get_a_sat_en(data)                                     ((0x00020000&(data))>>17)
#define OSDCOMP_DECMP_SETTING_b_cb_sat_en_shift                                      (16)
#define OSDCOMP_DECMP_SETTING_b_cb_sat_en_mask                                       (0x00010000)
#define OSDCOMP_DECMP_SETTING_b_cb_sat_en(data)                                      (0x00010000&((data)<<16))
#define OSDCOMP_DECMP_SETTING_b_cb_sat_en_src(data)                                  ((0x00010000&(data))>>16)
#define OSDCOMP_DECMP_SETTING_get_b_cb_sat_en(data)                                  ((0x00010000&(data))>>16)
#define OSDCOMP_DECMP_SETTING_g_Y_sat_en_shift                                       (15)
#define OSDCOMP_DECMP_SETTING_g_Y_sat_en_mask                                        (0x00008000)
#define OSDCOMP_DECMP_SETTING_g_Y_sat_en(data)                                       (0x00008000&((data)<<15))
#define OSDCOMP_DECMP_SETTING_g_Y_sat_en_src(data)                                   ((0x00008000&(data))>>15)
#define OSDCOMP_DECMP_SETTING_get_g_Y_sat_en(data)                                   ((0x00008000&(data))>>15)
#define OSDCOMP_DECMP_SETTING_r_cr_sat_en_shift                                      (14)
#define OSDCOMP_DECMP_SETTING_r_cr_sat_en_mask                                       (0x00004000)
#define OSDCOMP_DECMP_SETTING_r_cr_sat_en(data)                                      (0x00004000&((data)<<14))
#define OSDCOMP_DECMP_SETTING_r_cr_sat_en_src(data)                                  ((0x00004000&(data))>>14)
#define OSDCOMP_DECMP_SETTING_get_r_cr_sat_en(data)                                  ((0x00004000&(data))>>14)
#define OSDCOMP_DECMP_SETTING_decmp_frame_bits_shift                                 (8)
#define OSDCOMP_DECMP_SETTING_decmp_frame_bits_mask                                  (0x00003F00)
#define OSDCOMP_DECMP_SETTING_decmp_frame_bits(data)                                 (0x00003F00&((data)<<8))
#define OSDCOMP_DECMP_SETTING_decmp_frame_bits_src(data)                             ((0x00003F00&(data))>>8)
#define OSDCOMP_DECMP_SETTING_get_decmp_frame_bits(data)                             ((0x00003F00&(data))>>8)
#define OSDCOMP_DECMP_SETTING_decmp_a_ch_mark_shift                                  (5)
#define OSDCOMP_DECMP_SETTING_decmp_a_ch_mark_mask                                   (0x00000020)
#define OSDCOMP_DECMP_SETTING_decmp_a_ch_mark(data)                                  (0x00000020&((data)<<5))
#define OSDCOMP_DECMP_SETTING_decmp_a_ch_mark_src(data)                              ((0x00000020&(data))>>5)
#define OSDCOMP_DECMP_SETTING_get_decmp_a_ch_mark(data)                              ((0x00000020&(data))>>5)
#define OSDCOMP_DECMP_SETTING_decmp_444to422_en_shift                                (4)
#define OSDCOMP_DECMP_SETTING_decmp_444to422_en_mask                                 (0x00000010)
#define OSDCOMP_DECMP_SETTING_decmp_444to422_en(data)                                (0x00000010&((data)<<4))
#define OSDCOMP_DECMP_SETTING_decmp_444to422_en_src(data)                            ((0x00000010&(data))>>4)
#define OSDCOMP_DECMP_SETTING_get_decmp_444to422_en(data)                            ((0x00000010&(data))>>4)
#define OSDCOMP_DECMP_SETTING_decmp_RGB_YC_sel_shift                                 (3)
#define OSDCOMP_DECMP_SETTING_decmp_RGB_YC_sel_mask                                  (0x00000008)
#define OSDCOMP_DECMP_SETTING_decmp_RGB_YC_sel(data)                                 (0x00000008&((data)<<3))
#define OSDCOMP_DECMP_SETTING_decmp_RGB_YC_sel_src(data)                             ((0x00000008&(data))>>3)
#define OSDCOMP_DECMP_SETTING_get_decmp_RGB_YC_sel(data)                             ((0x00000008&(data))>>3)
#define OSDCOMP_DECMP_SETTING_decmp_channel_bits_shift                               (2)
#define OSDCOMP_DECMP_SETTING_decmp_channel_bits_mask                                (0x00000004)
#define OSDCOMP_DECMP_SETTING_decmp_channel_bits(data)                               (0x00000004&((data)<<2))
#define OSDCOMP_DECMP_SETTING_decmp_channel_bits_src(data)                           ((0x00000004&(data))>>2)
#define OSDCOMP_DECMP_SETTING_get_decmp_channel_bits(data)                           ((0x00000004&(data))>>2)
#define OSDCOMP_DECMP_SETTING_decmp_CbCr_recov_shift                                 (1)
#define OSDCOMP_DECMP_SETTING_decmp_CbCr_recov_mask                                  (0x00000002)
#define OSDCOMP_DECMP_SETTING_decmp_CbCr_recov(data)                                 (0x00000002&((data)<<1))
#define OSDCOMP_DECMP_SETTING_decmp_CbCr_recov_src(data)                             ((0x00000002&(data))>>1)
#define OSDCOMP_DECMP_SETTING_get_decmp_CbCr_recov(data)                             ((0x00000002&(data))>>1)
#define OSDCOMP_DECMP_SETTING_decmp_fl_mode_shift                                    (0)
#define OSDCOMP_DECMP_SETTING_decmp_fl_mode_mask                                     (0x00000001)
#define OSDCOMP_DECMP_SETTING_decmp_fl_mode(data)                                    (0x00000001&((data)<<0))
#define OSDCOMP_DECMP_SETTING_decmp_fl_mode_src(data)                                ((0x00000001&(data))>>0)
#define OSDCOMP_DECMP_SETTING_get_decmp_fl_mode(data)                                ((0x00000001&(data))>>0)


#define OSDCOMP_TRUNC_MARK                                                           0x18031188
#define OSDCOMP_TRUNC_MARK_reg_addr                                                  "0xB8031188"
#define OSDCOMP_TRUNC_MARK_reg                                                       0xB8031188
#define set_OSDCOMP_TRUNC_MARK_reg(data)   (*((volatile unsigned int*) OSDCOMP_TRUNC_MARK_reg)=data)
#define get_OSDCOMP_TRUNC_MARK_reg   (*((volatile unsigned int*) OSDCOMP_TRUNC_MARK_reg))
#define OSDCOMP_TRUNC_MARK_inst_adr                                                  "0x0062"
#define OSDCOMP_TRUNC_MARK_inst                                                      0x0062
#define OSDCOMP_TRUNC_MARK_mark_en_9_shift                                           (9)
#define OSDCOMP_TRUNC_MARK_mark_en_9_mask                                            (0x00000200)
#define OSDCOMP_TRUNC_MARK_mark_en_9(data)                                           (0x00000200&((data)<<9))
#define OSDCOMP_TRUNC_MARK_mark_en_9_src(data)                                       ((0x00000200&(data))>>9)
#define OSDCOMP_TRUNC_MARK_get_mark_en_9(data)                                       ((0x00000200&(data))>>9)
#define OSDCOMP_TRUNC_MARK_mark_en_8_shift                                           (8)
#define OSDCOMP_TRUNC_MARK_mark_en_8_mask                                            (0x00000100)
#define OSDCOMP_TRUNC_MARK_mark_en_8(data)                                           (0x00000100&((data)<<8))
#define OSDCOMP_TRUNC_MARK_mark_en_8_src(data)                                       ((0x00000100&(data))>>8)
#define OSDCOMP_TRUNC_MARK_get_mark_en_8(data)                                       ((0x00000100&(data))>>8)
#define OSDCOMP_TRUNC_MARK_mark_en_7_shift                                           (7)
#define OSDCOMP_TRUNC_MARK_mark_en_7_mask                                            (0x00000080)
#define OSDCOMP_TRUNC_MARK_mark_en_7(data)                                           (0x00000080&((data)<<7))
#define OSDCOMP_TRUNC_MARK_mark_en_7_src(data)                                       ((0x00000080&(data))>>7)
#define OSDCOMP_TRUNC_MARK_get_mark_en_7(data)                                       ((0x00000080&(data))>>7)
#define OSDCOMP_TRUNC_MARK_mark_en_6_shift                                           (6)
#define OSDCOMP_TRUNC_MARK_mark_en_6_mask                                            (0x00000040)
#define OSDCOMP_TRUNC_MARK_mark_en_6(data)                                           (0x00000040&((data)<<6))
#define OSDCOMP_TRUNC_MARK_mark_en_6_src(data)                                       ((0x00000040&(data))>>6)
#define OSDCOMP_TRUNC_MARK_get_mark_en_6(data)                                       ((0x00000040&(data))>>6)
#define OSDCOMP_TRUNC_MARK_mark_en_5_shift                                           (5)
#define OSDCOMP_TRUNC_MARK_mark_en_5_mask                                            (0x00000020)
#define OSDCOMP_TRUNC_MARK_mark_en_5(data)                                           (0x00000020&((data)<<5))
#define OSDCOMP_TRUNC_MARK_mark_en_5_src(data)                                       ((0x00000020&(data))>>5)
#define OSDCOMP_TRUNC_MARK_get_mark_en_5(data)                                       ((0x00000020&(data))>>5)
#define OSDCOMP_TRUNC_MARK_mark_en_4_shift                                           (4)
#define OSDCOMP_TRUNC_MARK_mark_en_4_mask                                            (0x00000010)
#define OSDCOMP_TRUNC_MARK_mark_en_4(data)                                           (0x00000010&((data)<<4))
#define OSDCOMP_TRUNC_MARK_mark_en_4_src(data)                                       ((0x00000010&(data))>>4)
#define OSDCOMP_TRUNC_MARK_get_mark_en_4(data)                                       ((0x00000010&(data))>>4)
#define OSDCOMP_TRUNC_MARK_mark_en_3_shift                                           (3)
#define OSDCOMP_TRUNC_MARK_mark_en_3_mask                                            (0x00000008)
#define OSDCOMP_TRUNC_MARK_mark_en_3(data)                                           (0x00000008&((data)<<3))
#define OSDCOMP_TRUNC_MARK_mark_en_3_src(data)                                       ((0x00000008&(data))>>3)
#define OSDCOMP_TRUNC_MARK_get_mark_en_3(data)                                       ((0x00000008&(data))>>3)
#define OSDCOMP_TRUNC_MARK_mark_en_2_shift                                           (2)
#define OSDCOMP_TRUNC_MARK_mark_en_2_mask                                            (0x00000004)
#define OSDCOMP_TRUNC_MARK_mark_en_2(data)                                           (0x00000004&((data)<<2))
#define OSDCOMP_TRUNC_MARK_mark_en_2_src(data)                                       ((0x00000004&(data))>>2)
#define OSDCOMP_TRUNC_MARK_get_mark_en_2(data)                                       ((0x00000004&(data))>>2)
#define OSDCOMP_TRUNC_MARK_mark_en_1_shift                                           (1)
#define OSDCOMP_TRUNC_MARK_mark_en_1_mask                                            (0x00000002)
#define OSDCOMP_TRUNC_MARK_mark_en_1(data)                                           (0x00000002&((data)<<1))
#define OSDCOMP_TRUNC_MARK_mark_en_1_src(data)                                       ((0x00000002&(data))>>1)
#define OSDCOMP_TRUNC_MARK_get_mark_en_1(data)                                       ((0x00000002&(data))>>1)
#define OSDCOMP_TRUNC_MARK_mark_en_0_shift                                           (0)
#define OSDCOMP_TRUNC_MARK_mark_en_0_mask                                            (0x00000001)
#define OSDCOMP_TRUNC_MARK_mark_en_0(data)                                           (0x00000001&((data)<<0))
#define OSDCOMP_TRUNC_MARK_mark_en_0_src(data)                                       ((0x00000001&(data))>>0)
#define OSDCOMP_TRUNC_MARK_get_mark_en_0(data)                                       ((0x00000001&(data))>>0)


#define OSDCOMP_TRUNC_COLOR_0                                                        0x1803118c
#define OSDCOMP_TRUNC_COLOR_0_reg_addr                                               "0xB803118C"
#define OSDCOMP_TRUNC_COLOR_0_reg                                                    0xB803118C
#define set_OSDCOMP_TRUNC_COLOR_0_reg(data)   (*((volatile unsigned int*) OSDCOMP_TRUNC_COLOR_0_reg)=data)
#define get_OSDCOMP_TRUNC_COLOR_0_reg   (*((volatile unsigned int*) OSDCOMP_TRUNC_COLOR_0_reg))
#define OSDCOMP_TRUNC_COLOR_0_inst_adr                                               "0x0063"
#define OSDCOMP_TRUNC_COLOR_0_inst                                                   0x0063
#define OSDCOMP_TRUNC_COLOR_0_mark_color_0_shift                                     (16)
#define OSDCOMP_TRUNC_COLOR_0_mark_color_0_mask                                      (0xFFFF0000)
#define OSDCOMP_TRUNC_COLOR_0_mark_color_0(data)                                     (0xFFFF0000&((data)<<16))
#define OSDCOMP_TRUNC_COLOR_0_mark_color_0_src(data)                                 ((0xFFFF0000&(data))>>16)
#define OSDCOMP_TRUNC_COLOR_0_get_mark_color_0(data)                                 ((0xFFFF0000&(data))>>16)
#define OSDCOMP_TRUNC_COLOR_0_mark_color_1_shift                                     (0)
#define OSDCOMP_TRUNC_COLOR_0_mark_color_1_mask                                      (0x0000FFFF)
#define OSDCOMP_TRUNC_COLOR_0_mark_color_1(data)                                     (0x0000FFFF&((data)<<0))
#define OSDCOMP_TRUNC_COLOR_0_mark_color_1_src(data)                                 ((0x0000FFFF&(data))>>0)
#define OSDCOMP_TRUNC_COLOR_0_get_mark_color_1(data)                                 ((0x0000FFFF&(data))>>0)


#define OSDCOMP_TRUNC_COLOR_1                                                        0x18031190
#define OSDCOMP_TRUNC_COLOR_1_reg_addr                                               "0xB8031190"
#define OSDCOMP_TRUNC_COLOR_1_reg                                                    0xB8031190
#define set_OSDCOMP_TRUNC_COLOR_1_reg(data)   (*((volatile unsigned int*) OSDCOMP_TRUNC_COLOR_1_reg)=data)
#define get_OSDCOMP_TRUNC_COLOR_1_reg   (*((volatile unsigned int*) OSDCOMP_TRUNC_COLOR_1_reg))
#define OSDCOMP_TRUNC_COLOR_1_inst_adr                                               "0x0064"
#define OSDCOMP_TRUNC_COLOR_1_inst                                                   0x0064
#define OSDCOMP_TRUNC_COLOR_1_mark_color_2_shift                                     (16)
#define OSDCOMP_TRUNC_COLOR_1_mark_color_2_mask                                      (0xFFFF0000)
#define OSDCOMP_TRUNC_COLOR_1_mark_color_2(data)                                     (0xFFFF0000&((data)<<16))
#define OSDCOMP_TRUNC_COLOR_1_mark_color_2_src(data)                                 ((0xFFFF0000&(data))>>16)
#define OSDCOMP_TRUNC_COLOR_1_get_mark_color_2(data)                                 ((0xFFFF0000&(data))>>16)
#define OSDCOMP_TRUNC_COLOR_1_mark_color_3_shift                                     (0)
#define OSDCOMP_TRUNC_COLOR_1_mark_color_3_mask                                      (0x0000FFFF)
#define OSDCOMP_TRUNC_COLOR_1_mark_color_3(data)                                     (0x0000FFFF&((data)<<0))
#define OSDCOMP_TRUNC_COLOR_1_mark_color_3_src(data)                                 ((0x0000FFFF&(data))>>0)
#define OSDCOMP_TRUNC_COLOR_1_get_mark_color_3(data)                                 ((0x0000FFFF&(data))>>0)


#define OSDCOMP_TRUNC_COLOR_2                                                        0x18031194
#define OSDCOMP_TRUNC_COLOR_2_reg_addr                                               "0xB8031194"
#define OSDCOMP_TRUNC_COLOR_2_reg                                                    0xB8031194
#define set_OSDCOMP_TRUNC_COLOR_2_reg(data)   (*((volatile unsigned int*) OSDCOMP_TRUNC_COLOR_2_reg)=data)
#define get_OSDCOMP_TRUNC_COLOR_2_reg   (*((volatile unsigned int*) OSDCOMP_TRUNC_COLOR_2_reg))
#define OSDCOMP_TRUNC_COLOR_2_inst_adr                                               "0x0065"
#define OSDCOMP_TRUNC_COLOR_2_inst                                                   0x0065
#define OSDCOMP_TRUNC_COLOR_2_mark_color_4_shift                                     (16)
#define OSDCOMP_TRUNC_COLOR_2_mark_color_4_mask                                      (0xFFFF0000)
#define OSDCOMP_TRUNC_COLOR_2_mark_color_4(data)                                     (0xFFFF0000&((data)<<16))
#define OSDCOMP_TRUNC_COLOR_2_mark_color_4_src(data)                                 ((0xFFFF0000&(data))>>16)
#define OSDCOMP_TRUNC_COLOR_2_get_mark_color_4(data)                                 ((0xFFFF0000&(data))>>16)
#define OSDCOMP_TRUNC_COLOR_2_mark_color_5_shift                                     (0)
#define OSDCOMP_TRUNC_COLOR_2_mark_color_5_mask                                      (0x0000FFFF)
#define OSDCOMP_TRUNC_COLOR_2_mark_color_5(data)                                     (0x0000FFFF&((data)<<0))
#define OSDCOMP_TRUNC_COLOR_2_mark_color_5_src(data)                                 ((0x0000FFFF&(data))>>0)
#define OSDCOMP_TRUNC_COLOR_2_get_mark_color_5(data)                                 ((0x0000FFFF&(data))>>0)


#define OSDCOMP_TRUNC_COLOR_3                                                        0x18031198
#define OSDCOMP_TRUNC_COLOR_3_reg_addr                                               "0xB8031198"
#define OSDCOMP_TRUNC_COLOR_3_reg                                                    0xB8031198
#define set_OSDCOMP_TRUNC_COLOR_3_reg(data)   (*((volatile unsigned int*) OSDCOMP_TRUNC_COLOR_3_reg)=data)
#define get_OSDCOMP_TRUNC_COLOR_3_reg   (*((volatile unsigned int*) OSDCOMP_TRUNC_COLOR_3_reg))
#define OSDCOMP_TRUNC_COLOR_3_inst_adr                                               "0x0066"
#define OSDCOMP_TRUNC_COLOR_3_inst                                                   0x0066
#define OSDCOMP_TRUNC_COLOR_3_mark_color_6_shift                                     (16)
#define OSDCOMP_TRUNC_COLOR_3_mark_color_6_mask                                      (0xFFFF0000)
#define OSDCOMP_TRUNC_COLOR_3_mark_color_6(data)                                     (0xFFFF0000&((data)<<16))
#define OSDCOMP_TRUNC_COLOR_3_mark_color_6_src(data)                                 ((0xFFFF0000&(data))>>16)
#define OSDCOMP_TRUNC_COLOR_3_get_mark_color_6(data)                                 ((0xFFFF0000&(data))>>16)
#define OSDCOMP_TRUNC_COLOR_3_mark_color_7_shift                                     (0)
#define OSDCOMP_TRUNC_COLOR_3_mark_color_7_mask                                      (0x0000FFFF)
#define OSDCOMP_TRUNC_COLOR_3_mark_color_7(data)                                     (0x0000FFFF&((data)<<0))
#define OSDCOMP_TRUNC_COLOR_3_mark_color_7_src(data)                                 ((0x0000FFFF&(data))>>0)
#define OSDCOMP_TRUNC_COLOR_3_get_mark_color_7(data)                                 ((0x0000FFFF&(data))>>0)


#define OSDCOMP_TRUNC_COLOR_4                                                        0x1803119c
#define OSDCOMP_TRUNC_COLOR_4_reg_addr                                               "0xB803119C"
#define OSDCOMP_TRUNC_COLOR_4_reg                                                    0xB803119C
#define set_OSDCOMP_TRUNC_COLOR_4_reg(data)   (*((volatile unsigned int*) OSDCOMP_TRUNC_COLOR_4_reg)=data)
#define get_OSDCOMP_TRUNC_COLOR_4_reg   (*((volatile unsigned int*) OSDCOMP_TRUNC_COLOR_4_reg))
#define OSDCOMP_TRUNC_COLOR_4_inst_adr                                               "0x0067"
#define OSDCOMP_TRUNC_COLOR_4_inst                                                   0x0067
#define OSDCOMP_TRUNC_COLOR_4_mark_color_8_shift                                     (16)
#define OSDCOMP_TRUNC_COLOR_4_mark_color_8_mask                                      (0xFFFF0000)
#define OSDCOMP_TRUNC_COLOR_4_mark_color_8(data)                                     (0xFFFF0000&((data)<<16))
#define OSDCOMP_TRUNC_COLOR_4_mark_color_8_src(data)                                 ((0xFFFF0000&(data))>>16)
#define OSDCOMP_TRUNC_COLOR_4_get_mark_color_8(data)                                 ((0xFFFF0000&(data))>>16)
#define OSDCOMP_TRUNC_COLOR_4_mark_color_9_shift                                     (0)
#define OSDCOMP_TRUNC_COLOR_4_mark_color_9_mask                                      (0x0000FFFF)
#define OSDCOMP_TRUNC_COLOR_4_mark_color_9(data)                                     (0x0000FFFF&((data)<<0))
#define OSDCOMP_TRUNC_COLOR_4_mark_color_9_src(data)                                 ((0x0000FFFF&(data))>>0)
#define OSDCOMP_TRUNC_COLOR_4_get_mark_color_9(data)                                 ((0x0000FFFF&(data))>>0)


#define OSDCOMP_FRAME_INST                                                           0x180311a0
#define OSDCOMP_FRAME_INST_reg_addr                                                  "0xB80311A0"
#define OSDCOMP_FRAME_INST_reg                                                       0xB80311A0
#define set_OSDCOMP_FRAME_INST_reg(data)   (*((volatile unsigned int*) OSDCOMP_FRAME_INST_reg)=data)
#define get_OSDCOMP_FRAME_INST_reg   (*((volatile unsigned int*) OSDCOMP_FRAME_INST_reg))
#define OSDCOMP_FRAME_INST_inst_adr                                                  "0x0068"
#define OSDCOMP_FRAME_INST_inst                                                      0x0068
#define OSDCOMP_FRAME_INST_frm_cnt_0_shift                                           (16)
#define OSDCOMP_FRAME_INST_frm_cnt_0_mask                                            (0x000F0000)
#define OSDCOMP_FRAME_INST_frm_cnt_0(data)                                           (0x000F0000&((data)<<16))
#define OSDCOMP_FRAME_INST_frm_cnt_0_src(data)                                       ((0x000F0000&(data))>>16)
#define OSDCOMP_FRAME_INST_get_frm_cnt_0(data)                                       ((0x000F0000&(data))>>16)
#define OSDCOMP_FRAME_INST_max_truncation_0_shift                                    (0)
#define OSDCOMP_FRAME_INST_max_truncation_0_mask                                     (0x0000000F)
#define OSDCOMP_FRAME_INST_max_truncation_0(data)                                    (0x0000000F&((data)<<0))
#define OSDCOMP_FRAME_INST_max_truncation_0_src(data)                                ((0x0000000F&(data))>>0)
#define OSDCOMP_FRAME_INST_get_max_truncation_0(data)                                ((0x0000000F&(data))>>0)


#define OSDCOMP_DECOMP_INTEN                                                         0x180311a4
#define OSDCOMP_DECOMP_INTEN_reg_addr                                                "0xB80311A4"
#define OSDCOMP_DECOMP_INTEN_reg                                                     0xB80311A4
#define set_OSDCOMP_DECOMP_INTEN_reg(data)   (*((volatile unsigned int*) OSDCOMP_DECOMP_INTEN_reg)=data)
#define get_OSDCOMP_DECOMP_INTEN_reg   (*((volatile unsigned int*) OSDCOMP_DECOMP_INTEN_reg))
#define OSDCOMP_DECOMP_INTEN_inst_adr                                                "0x0069"
#define OSDCOMP_DECOMP_INTEN_inst                                                    0x0069
#define OSDCOMP_DECOMP_INTEN_decomp_support_error_clr_shift                          (17)
#define OSDCOMP_DECOMP_INTEN_decomp_support_error_clr_mask                           (0x00020000)
#define OSDCOMP_DECOMP_INTEN_decomp_support_error_clr(data)                          (0x00020000&((data)<<17))
#define OSDCOMP_DECOMP_INTEN_decomp_support_error_clr_src(data)                      ((0x00020000&(data))>>17)
#define OSDCOMP_DECOMP_INTEN_get_decomp_support_error_clr(data)                      ((0x00020000&(data))>>17)
#define OSDCOMP_DECOMP_INTEN_decomp_support_error_irq_en_shift                       (16)
#define OSDCOMP_DECOMP_INTEN_decomp_support_error_irq_en_mask                        (0x00010000)
#define OSDCOMP_DECOMP_INTEN_decomp_support_error_irq_en(data)                       (0x00010000&((data)<<16))
#define OSDCOMP_DECOMP_INTEN_decomp_support_error_irq_en_src(data)                   ((0x00010000&(data))>>16)
#define OSDCOMP_DECOMP_INTEN_get_decomp_support_error_irq_en(data)                   ((0x00010000&(data))>>16)
#define OSDCOMP_DECOMP_INTEN_head_error_clr_shift                                    (9)
#define OSDCOMP_DECOMP_INTEN_head_error_clr_mask                                     (0x00000200)
#define OSDCOMP_DECOMP_INTEN_head_error_clr(data)                                    (0x00000200&((data)<<9))
#define OSDCOMP_DECOMP_INTEN_head_error_clr_src(data)                                ((0x00000200&(data))>>9)
#define OSDCOMP_DECOMP_INTEN_get_head_error_clr(data)                                ((0x00000200&(data))>>9)
#define OSDCOMP_DECOMP_INTEN_pix_fifo_underflow_clr_shift                            (8)
#define OSDCOMP_DECOMP_INTEN_pix_fifo_underflow_clr_mask                             (0x00000100)
#define OSDCOMP_DECOMP_INTEN_pix_fifo_underflow_clr(data)                            (0x00000100&((data)<<8))
#define OSDCOMP_DECOMP_INTEN_pix_fifo_underflow_clr_src(data)                        ((0x00000100&(data))>>8)
#define OSDCOMP_DECOMP_INTEN_get_pix_fifo_underflow_clr(data)                        ((0x00000100&(data))>>8)
#define OSDCOMP_DECOMP_INTEN_head_error_irq_en_shift                                 (4)
#define OSDCOMP_DECOMP_INTEN_head_error_irq_en_mask                                  (0x00000010)
#define OSDCOMP_DECOMP_INTEN_head_error_irq_en(data)                                 (0x00000010&((data)<<4))
#define OSDCOMP_DECOMP_INTEN_head_error_irq_en_src(data)                             ((0x00000010&(data))>>4)
#define OSDCOMP_DECOMP_INTEN_get_head_error_irq_en(data)                             ((0x00000010&(data))>>4)
#define OSDCOMP_DECOMP_INTEN_underflow_irq_en_shift                                  (0)
#define OSDCOMP_DECOMP_INTEN_underflow_irq_en_mask                                   (0x00000001)
#define OSDCOMP_DECOMP_INTEN_underflow_irq_en(data)                                  (0x00000001&((data)<<0))
#define OSDCOMP_DECOMP_INTEN_underflow_irq_en_src(data)                              ((0x00000001&(data))>>0)
#define OSDCOMP_DECOMP_INTEN_get_underflow_irq_en(data)                              ((0x00000001&(data))>>0)


#define OSDCOMP_DECOMP_INTST                                                         0x180311a8
#define OSDCOMP_DECOMP_INTST_reg_addr                                                "0xB80311A8"
#define OSDCOMP_DECOMP_INTST_reg                                                     0xB80311A8
#define set_OSDCOMP_DECOMP_INTST_reg(data)   (*((volatile unsigned int*) OSDCOMP_DECOMP_INTST_reg)=data)
#define get_OSDCOMP_DECOMP_INTST_reg   (*((volatile unsigned int*) OSDCOMP_DECOMP_INTST_reg))
#define OSDCOMP_DECOMP_INTST_inst_adr                                                "0x006A"
#define OSDCOMP_DECOMP_INTST_inst                                                    0x006A
#define OSDCOMP_DECOMP_INTST_decomp_support_error_shift                              (16)
#define OSDCOMP_DECOMP_INTST_decomp_support_error_mask                               (0x00070000)
#define OSDCOMP_DECOMP_INTST_decomp_support_error(data)                              (0x00070000&((data)<<16))
#define OSDCOMP_DECOMP_INTST_decomp_support_error_src(data)                          ((0x00070000&(data))>>16)
#define OSDCOMP_DECOMP_INTST_get_decomp_support_error(data)                          ((0x00070000&(data))>>16)
#define OSDCOMP_DECOMP_INTST_decomp_irq_shift                                        (8)
#define OSDCOMP_DECOMP_INTST_decomp_irq_mask                                         (0x00000100)
#define OSDCOMP_DECOMP_INTST_decomp_irq(data)                                        (0x00000100&((data)<<8))
#define OSDCOMP_DECOMP_INTST_decomp_irq_src(data)                                    ((0x00000100&(data))>>8)
#define OSDCOMP_DECOMP_INTST_get_decomp_irq(data)                                    ((0x00000100&(data))>>8)
#define OSDCOMP_DECOMP_INTST_head_error_shift                                        (4)
#define OSDCOMP_DECOMP_INTST_head_error_mask                                         (0x00000010)
#define OSDCOMP_DECOMP_INTST_head_error(data)                                        (0x00000010&((data)<<4))
#define OSDCOMP_DECOMP_INTST_head_error_src(data)                                    ((0x00000010&(data))>>4)
#define OSDCOMP_DECOMP_INTST_get_head_error(data)                                    ((0x00000010&(data))>>4)
#define OSDCOMP_DECOMP_INTST_pix_fifo_underflow_shift                                (0)
#define OSDCOMP_DECOMP_INTST_pix_fifo_underflow_mask                                 (0x00000001)
#define OSDCOMP_DECOMP_INTST_pix_fifo_underflow(data)                                (0x00000001&((data)<<0))
#define OSDCOMP_DECOMP_INTST_pix_fifo_underflow_src(data)                            ((0x00000001&(data))>>0)
#define OSDCOMP_DECOMP_INTST_get_pix_fifo_underflow(data)                            ((0x00000001&(data))>>0)


#define OSDCOMP_DECOMP_CRC                                                           0x180311b0
#define OSDCOMP_DECOMP_CRC_reg_addr                                                  "0xB80311B0"
#define OSDCOMP_DECOMP_CRC_reg                                                       0xB80311B0
#define set_OSDCOMP_DECOMP_CRC_reg(data)   (*((volatile unsigned int*) OSDCOMP_DECOMP_CRC_reg)=data)
#define get_OSDCOMP_DECOMP_CRC_reg   (*((volatile unsigned int*) OSDCOMP_DECOMP_CRC_reg))
#define OSDCOMP_DECOMP_CRC_inst_adr                                                  "0x006C"
#define OSDCOMP_DECOMP_CRC_inst                                                      0x006C
#define OSDCOMP_DECOMP_CRC_conti_shift                                               (1)
#define OSDCOMP_DECOMP_CRC_conti_mask                                                (0x00000002)
#define OSDCOMP_DECOMP_CRC_conti(data)                                               (0x00000002&((data)<<1))
#define OSDCOMP_DECOMP_CRC_conti_src(data)                                           ((0x00000002&(data))>>1)
#define OSDCOMP_DECOMP_CRC_get_conti(data)                                           ((0x00000002&(data))>>1)
#define OSDCOMP_DECOMP_CRC_start_shift                                               (0)
#define OSDCOMP_DECOMP_CRC_start_mask                                                (0x00000001)
#define OSDCOMP_DECOMP_CRC_start(data)                                               (0x00000001&((data)<<0))
#define OSDCOMP_DECOMP_CRC_start_src(data)                                           ((0x00000001&(data))>>0)
#define OSDCOMP_DECOMP_CRC_get_start(data)                                           ((0x00000001&(data))>>0)


#define OSDCOMP_DECOMP_SEG0_CRC                                                      0x180311b4
#define OSDCOMP_DECOMP_SEG0_CRC_reg_addr                                             "0xB80311B4"
#define OSDCOMP_DECOMP_SEG0_CRC_reg                                                  0xB80311B4
#define set_OSDCOMP_DECOMP_SEG0_CRC_reg(data)   (*((volatile unsigned int*) OSDCOMP_DECOMP_SEG0_CRC_reg)=data)
#define get_OSDCOMP_DECOMP_SEG0_CRC_reg   (*((volatile unsigned int*) OSDCOMP_DECOMP_SEG0_CRC_reg))
#define OSDCOMP_DECOMP_SEG0_CRC_inst_adr                                             "0x006D"
#define OSDCOMP_DECOMP_SEG0_CRC_inst                                                 0x006D
#define OSDCOMP_DECOMP_SEG0_CRC_result_shift                                         (0)
#define OSDCOMP_DECOMP_SEG0_CRC_result_mask                                          (0xFFFFFFFF)
#define OSDCOMP_DECOMP_SEG0_CRC_result(data)                                         (0xFFFFFFFF&((data)<<0))
#define OSDCOMP_DECOMP_SEG0_CRC_result_src(data)                                     ((0xFFFFFFFF&(data))>>0)
#define OSDCOMP_DECOMP_SEG0_CRC_get_result(data)                                     ((0xFFFFFFFF&(data))>>0)


#define OSDCOMP_DBG                                                                  0x180311c0
#define OSDCOMP_DBG_reg_addr                                                         "0xB80311C0"
#define OSDCOMP_DBG_reg                                                              0xB80311C0
#define set_OSDCOMP_DBG_reg(data)   (*((volatile unsigned int*) OSDCOMP_DBG_reg)=data)
#define get_OSDCOMP_DBG_reg   (*((volatile unsigned int*) OSDCOMP_DBG_reg))
#define OSDCOMP_DBG_inst_adr                                                         "0x0070"
#define OSDCOMP_DBG_inst                                                             0x0070
#define OSDCOMP_DBG_write_en3_shift                                                  (24)
#define OSDCOMP_DBG_write_en3_mask                                                   (0x01000000)
#define OSDCOMP_DBG_write_en3(data)                                                  (0x01000000&((data)<<24))
#define OSDCOMP_DBG_write_en3_src(data)                                              ((0x01000000&(data))>>24)
#define OSDCOMP_DBG_get_write_en3(data)                                              ((0x01000000&(data))>>24)
#define OSDCOMP_DBG_sel1_shift                                                       (16)
#define OSDCOMP_DBG_sel1_mask                                                        (0x00FF0000)
#define OSDCOMP_DBG_sel1(data)                                                       (0x00FF0000&((data)<<16))
#define OSDCOMP_DBG_sel1_src(data)                                                   ((0x00FF0000&(data))>>16)
#define OSDCOMP_DBG_get_sel1(data)                                                   ((0x00FF0000&(data))>>16)
#define OSDCOMP_DBG_write_en2_shift                                                  (12)
#define OSDCOMP_DBG_write_en2_mask                                                   (0x00001000)
#define OSDCOMP_DBG_write_en2(data)                                                  (0x00001000&((data)<<12))
#define OSDCOMP_DBG_write_en2_src(data)                                              ((0x00001000&(data))>>12)
#define OSDCOMP_DBG_get_write_en2(data)                                              ((0x00001000&(data))>>12)
#define OSDCOMP_DBG_sel0_shift                                                       (4)
#define OSDCOMP_DBG_sel0_mask                                                        (0x00000FF0)
#define OSDCOMP_DBG_sel0(data)                                                       (0x00000FF0&((data)<<4))
#define OSDCOMP_DBG_sel0_src(data)                                                   ((0x00000FF0&(data))>>4)
#define OSDCOMP_DBG_get_sel0(data)                                                   ((0x00000FF0&(data))>>4)
#define OSDCOMP_DBG_write_en1_shift                                                  (1)
#define OSDCOMP_DBG_write_en1_mask                                                   (0x00000002)
#define OSDCOMP_DBG_write_en1(data)                                                  (0x00000002&((data)<<1))
#define OSDCOMP_DBG_write_en1_src(data)                                              ((0x00000002&(data))>>1)
#define OSDCOMP_DBG_get_write_en1(data)                                              ((0x00000002&(data))>>1)
#define OSDCOMP_DBG_en_shift                                                         (0)
#define OSDCOMP_DBG_en_mask                                                          (0x00000001)
#define OSDCOMP_DBG_en(data)                                                         (0x00000001&((data)<<0))
#define OSDCOMP_DBG_en_src(data)                                                     ((0x00000001&(data))>>0)
#define OSDCOMP_DBG_get_en(data)                                                     ((0x00000001&(data))>>0)


#define OSDCOMP_DECOMP_DEBUG                                                         0x180311c4
#define OSDCOMP_DECOMP_DEBUG_reg_addr                                                "0xB80311C4"
#define OSDCOMP_DECOMP_DEBUG_reg                                                     0xB80311C4
#define set_OSDCOMP_DECOMP_DEBUG_reg(data)   (*((volatile unsigned int*) OSDCOMP_DECOMP_DEBUG_reg)=data)
#define get_OSDCOMP_DECOMP_DEBUG_reg   (*((volatile unsigned int*) OSDCOMP_DECOMP_DEBUG_reg))
#define OSDCOMP_DECOMP_DEBUG_inst_adr                                                "0x0071"
#define OSDCOMP_DECOMP_DEBUG_inst                                                    0x0071
#define OSDCOMP_DECOMP_DEBUG_sel_shift                                               (16)
#define OSDCOMP_DECOMP_DEBUG_sel_mask                                                (0x00030000)
#define OSDCOMP_DECOMP_DEBUG_sel(data)                                               (0x00030000&((data)<<16))
#define OSDCOMP_DECOMP_DEBUG_sel_src(data)                                           ((0x00030000&(data))>>16)
#define OSDCOMP_DECOMP_DEBUG_get_sel(data)                                           ((0x00030000&(data))>>16)
#define OSDCOMP_DECOMP_DEBUG_mux_shift                                               (8)
#define OSDCOMP_DECOMP_DEBUG_mux_mask                                                (0x0000FF00)
#define OSDCOMP_DECOMP_DEBUG_mux(data)                                               (0x0000FF00&((data)<<8))
#define OSDCOMP_DECOMP_DEBUG_mux_src(data)                                           ((0x0000FF00&(data))>>8)
#define OSDCOMP_DECOMP_DEBUG_get_mux(data)                                           ((0x0000FF00&(data))>>8)


#define OSDCOMP_STATUS                                                               0x180311c8
#define OSDCOMP_STATUS_reg_addr                                                      "0xB80311C8"
#define OSDCOMP_STATUS_reg                                                           0xB80311C8
#define set_OSDCOMP_STATUS_reg(data)   (*((volatile unsigned int*) OSDCOMP_STATUS_reg)=data)
#define get_OSDCOMP_STATUS_reg   (*((volatile unsigned int*) OSDCOMP_STATUS_reg))
#define OSDCOMP_STATUS_inst_adr                                                      "0x0072"
#define OSDCOMP_STATUS_inst                                                          0x0072
#define OSDCOMP_STATUS_wdma_wptr_shift                                               (25)
#define OSDCOMP_STATUS_wdma_wptr_mask                                                (0xFE000000)
#define OSDCOMP_STATUS_wdma_wptr(data)                                               (0xFE000000&((data)<<25))
#define OSDCOMP_STATUS_wdma_wptr_src(data)                                           ((0xFE000000&(data))>>25)
#define OSDCOMP_STATUS_get_wdma_wptr(data)                                           ((0xFE000000&(data))>>25)
#define OSDCOMP_STATUS_wdma_rptr_shift                                               (18)
#define OSDCOMP_STATUS_wdma_rptr_mask                                                (0x01FC0000)
#define OSDCOMP_STATUS_wdma_rptr(data)                                               (0x01FC0000&((data)<<18))
#define OSDCOMP_STATUS_wdma_rptr_src(data)                                           ((0x01FC0000&(data))>>18)
#define OSDCOMP_STATUS_get_wdma_rptr(data)                                           ((0x01FC0000&(data))>>18)
#define OSDCOMP_STATUS_wdma_seg0_last_req_shift                                      (17)
#define OSDCOMP_STATUS_wdma_seg0_last_req_mask                                       (0x00020000)
#define OSDCOMP_STATUS_wdma_seg0_last_req(data)                                      (0x00020000&((data)<<17))
#define OSDCOMP_STATUS_wdma_seg0_last_req_src(data)                                  ((0x00020000&(data))>>17)
#define OSDCOMP_STATUS_get_wdma_seg0_last_req(data)                                  ((0x00020000&(data))>>17)
#define OSDCOMP_STATUS_wdma_seg1_last_req_shift                                      (16)
#define OSDCOMP_STATUS_wdma_seg1_last_req_mask                                       (0x00010000)
#define OSDCOMP_STATUS_wdma_seg1_last_req(data)                                      (0x00010000&((data)<<16))
#define OSDCOMP_STATUS_wdma_seg1_last_req_src(data)                                  ((0x00010000&(data))>>16)
#define OSDCOMP_STATUS_get_wdma_seg1_last_req(data)                                  ((0x00010000&(data))>>16)
#define OSDCOMP_STATUS_wdma_seg2_last_req_shift                                      (15)
#define OSDCOMP_STATUS_wdma_seg2_last_req_mask                                       (0x00008000)
#define OSDCOMP_STATUS_wdma_seg2_last_req(data)                                      (0x00008000&((data)<<15))
#define OSDCOMP_STATUS_wdma_seg2_last_req_src(data)                                  ((0x00008000&(data))>>15)
#define OSDCOMP_STATUS_get_wdma_seg2_last_req(data)                                  ((0x00008000&(data))>>15)
#define OSDCOMP_STATUS_wdma_seg3_last_req_shift                                      (14)
#define OSDCOMP_STATUS_wdma_seg3_last_req_mask                                       (0x00004000)
#define OSDCOMP_STATUS_wdma_seg3_last_req(data)                                      (0x00004000&((data)<<14))
#define OSDCOMP_STATUS_wdma_seg3_last_req_src(data)                                  ((0x00004000&(data))>>14)
#define OSDCOMP_STATUS_get_wdma_seg3_last_req(data)                                  ((0x00004000&(data))>>14)
#define OSDCOMP_STATUS_wdma_seg0_last_in_shift                                       (13)
#define OSDCOMP_STATUS_wdma_seg0_last_in_mask                                        (0x00002000)
#define OSDCOMP_STATUS_wdma_seg0_last_in(data)                                       (0x00002000&((data)<<13))
#define OSDCOMP_STATUS_wdma_seg0_last_in_src(data)                                   ((0x00002000&(data))>>13)
#define OSDCOMP_STATUS_get_wdma_seg0_last_in(data)                                   ((0x00002000&(data))>>13)
#define OSDCOMP_STATUS_wdma_seg1_last_in_shift                                       (12)
#define OSDCOMP_STATUS_wdma_seg1_last_in_mask                                        (0x00001000)
#define OSDCOMP_STATUS_wdma_seg1_last_in(data)                                       (0x00001000&((data)<<12))
#define OSDCOMP_STATUS_wdma_seg1_last_in_src(data)                                   ((0x00001000&(data))>>12)
#define OSDCOMP_STATUS_get_wdma_seg1_last_in(data)                                   ((0x00001000&(data))>>12)
#define OSDCOMP_STATUS_wdma_seg2_last_in_shift                                       (11)
#define OSDCOMP_STATUS_wdma_seg2_last_in_mask                                        (0x00000800)
#define OSDCOMP_STATUS_wdma_seg2_last_in(data)                                       (0x00000800&((data)<<11))
#define OSDCOMP_STATUS_wdma_seg2_last_in_src(data)                                   ((0x00000800&(data))>>11)
#define OSDCOMP_STATUS_get_wdma_seg2_last_in(data)                                   ((0x00000800&(data))>>11)
#define OSDCOMP_STATUS_wdma_seg3_last_in_shift                                       (10)
#define OSDCOMP_STATUS_wdma_seg3_last_in_mask                                        (0x00000400)
#define OSDCOMP_STATUS_wdma_seg3_last_in(data)                                       (0x00000400&((data)<<10))
#define OSDCOMP_STATUS_wdma_seg3_last_in_src(data)                                   ((0x00000400&(data))>>10)
#define OSDCOMP_STATUS_get_wdma_seg3_last_in(data)                                   ((0x00000400&(data))>>10)
#define OSDCOMP_STATUS_wdma_dct_st_shift                                             (7)
#define OSDCOMP_STATUS_wdma_dct_st_mask                                              (0x00000380)
#define OSDCOMP_STATUS_wdma_dct_st(data)                                             (0x00000380&((data)<<7))
#define OSDCOMP_STATUS_wdma_dct_st_src(data)                                         ((0x00000380&(data))>>7)
#define OSDCOMP_STATUS_get_wdma_dct_st(data)                                         ((0x00000380&(data))>>7)


#define OSDCOMP_COMP_STATUS                                                          0x180311cc
#define OSDCOMP_COMP_STATUS_reg_addr                                                 "0xB80311CC"
#define OSDCOMP_COMP_STATUS_reg                                                      0xB80311CC
#define set_OSDCOMP_COMP_STATUS_reg(data)   (*((volatile unsigned int*) OSDCOMP_COMP_STATUS_reg)=data)
#define get_OSDCOMP_COMP_STATUS_reg   (*((volatile unsigned int*) OSDCOMP_COMP_STATUS_reg))
#define OSDCOMP_COMP_STATUS_inst_adr                                                 "0x0073"
#define OSDCOMP_COMP_STATUS_inst                                                     0x0073
#define OSDCOMP_COMP_STATUS_comp_height_cnt_shift                                    (0)
#define OSDCOMP_COMP_STATUS_comp_height_cnt_mask                                     (0x0003FFFF)
#define OSDCOMP_COMP_STATUS_comp_height_cnt(data)                                    (0x0003FFFF&((data)<<0))
#define OSDCOMP_COMP_STATUS_comp_height_cnt_src(data)                                ((0x0003FFFF&(data))>>0)
#define OSDCOMP_COMP_STATUS_get_comp_height_cnt(data)                                ((0x0003FFFF&(data))>>0)


#define OSDCOMP_BIST_MODE                                                            0x180311d0
#define OSDCOMP_BIST_MODE_reg_addr                                                   "0xB80311D0"
#define OSDCOMP_BIST_MODE_reg                                                        0xB80311D0
#define set_OSDCOMP_BIST_MODE_reg(data)   (*((volatile unsigned int*) OSDCOMP_BIST_MODE_reg)=data)
#define get_OSDCOMP_BIST_MODE_reg   (*((volatile unsigned int*) OSDCOMP_BIST_MODE_reg))
#define OSDCOMP_BIST_MODE_inst_adr                                                   "0x0074"
#define OSDCOMP_BIST_MODE_inst                                                       0x0074
#define OSDCOMP_BIST_MODE_decomp_shift                                               (5)
#define OSDCOMP_BIST_MODE_decomp_mask                                                (0x00000020)
#define OSDCOMP_BIST_MODE_decomp(data)                                               (0x00000020&((data)<<5))
#define OSDCOMP_BIST_MODE_decomp_src(data)                                           ((0x00000020&(data))>>5)
#define OSDCOMP_BIST_MODE_get_decomp(data)                                           ((0x00000020&(data))>>5)
#define OSDCOMP_BIST_MODE_comp_shift                                                 (4)
#define OSDCOMP_BIST_MODE_comp_mask                                                  (0x00000010)
#define OSDCOMP_BIST_MODE_comp(data)                                                 (0x00000010&((data)<<4))
#define OSDCOMP_BIST_MODE_comp_src(data)                                             ((0x00000010&(data))>>4)
#define OSDCOMP_BIST_MODE_get_comp(data)                                             ((0x00000010&(data))>>4)
#define OSDCOMP_BIST_MODE_osd1_shift                                                 (3)
#define OSDCOMP_BIST_MODE_osd1_mask                                                  (0x00000008)
#define OSDCOMP_BIST_MODE_osd1(data)                                                 (0x00000008&((data)<<3))
#define OSDCOMP_BIST_MODE_osd1_src(data)                                             ((0x00000008&(data))>>3)
#define OSDCOMP_BIST_MODE_get_osd1(data)                                             ((0x00000008&(data))>>3)
#define OSDCOMP_BIST_MODE_rbuf_shift                                                 (2)
#define OSDCOMP_BIST_MODE_rbuf_mask                                                  (0x00000004)
#define OSDCOMP_BIST_MODE_rbuf(data)                                                 (0x00000004&((data)<<2))
#define OSDCOMP_BIST_MODE_rbuf_src(data)                                             ((0x00000004&(data))>>2)
#define OSDCOMP_BIST_MODE_get_rbuf(data)                                             ((0x00000004&(data))>>2)
#define OSDCOMP_BIST_MODE_dmabuf_shift                                               (1)
#define OSDCOMP_BIST_MODE_dmabuf_mask                                                (0x00000002)
#define OSDCOMP_BIST_MODE_dmabuf(data)                                               (0x00000002&((data)<<1))
#define OSDCOMP_BIST_MODE_dmabuf_src(data)                                           ((0x00000002&(data))>>1)
#define OSDCOMP_BIST_MODE_get_dmabuf(data)                                           ((0x00000002&(data))>>1)
#define OSDCOMP_BIST_MODE_dispbuf_shift                                              (0)
#define OSDCOMP_BIST_MODE_dispbuf_mask                                               (0x00000001)
#define OSDCOMP_BIST_MODE_dispbuf(data)                                              (0x00000001&((data)<<0))
#define OSDCOMP_BIST_MODE_dispbuf_src(data)                                          ((0x00000001&(data))>>0)
#define OSDCOMP_BIST_MODE_get_dispbuf(data)                                          ((0x00000001&(data))>>0)


#define OSDCOMP_BIST_DONE                                                            0x180311d4
#define OSDCOMP_BIST_DONE_reg_addr                                                   "0xB80311D4"
#define OSDCOMP_BIST_DONE_reg                                                        0xB80311D4
#define set_OSDCOMP_BIST_DONE_reg(data)   (*((volatile unsigned int*) OSDCOMP_BIST_DONE_reg)=data)
#define get_OSDCOMP_BIST_DONE_reg   (*((volatile unsigned int*) OSDCOMP_BIST_DONE_reg))
#define OSDCOMP_BIST_DONE_inst_adr                                                   "0x0075"
#define OSDCOMP_BIST_DONE_inst                                                       0x0075
#define OSDCOMP_BIST_DONE_decomp_shift                                               (5)
#define OSDCOMP_BIST_DONE_decomp_mask                                                (0x00000020)
#define OSDCOMP_BIST_DONE_decomp(data)                                               (0x00000020&((data)<<5))
#define OSDCOMP_BIST_DONE_decomp_src(data)                                           ((0x00000020&(data))>>5)
#define OSDCOMP_BIST_DONE_get_decomp(data)                                           ((0x00000020&(data))>>5)
#define OSDCOMP_BIST_DONE_comp_shift                                                 (4)
#define OSDCOMP_BIST_DONE_comp_mask                                                  (0x00000010)
#define OSDCOMP_BIST_DONE_comp(data)                                                 (0x00000010&((data)<<4))
#define OSDCOMP_BIST_DONE_comp_src(data)                                             ((0x00000010&(data))>>4)
#define OSDCOMP_BIST_DONE_get_comp(data)                                             ((0x00000010&(data))>>4)
#define OSDCOMP_BIST_DONE_osd1_shift                                                 (3)
#define OSDCOMP_BIST_DONE_osd1_mask                                                  (0x00000008)
#define OSDCOMP_BIST_DONE_osd1(data)                                                 (0x00000008&((data)<<3))
#define OSDCOMP_BIST_DONE_osd1_src(data)                                             ((0x00000008&(data))>>3)
#define OSDCOMP_BIST_DONE_get_osd1(data)                                             ((0x00000008&(data))>>3)
#define OSDCOMP_BIST_DONE_rbuf_shift                                                 (2)
#define OSDCOMP_BIST_DONE_rbuf_mask                                                  (0x00000004)
#define OSDCOMP_BIST_DONE_rbuf(data)                                                 (0x00000004&((data)<<2))
#define OSDCOMP_BIST_DONE_rbuf_src(data)                                             ((0x00000004&(data))>>2)
#define OSDCOMP_BIST_DONE_get_rbuf(data)                                             ((0x00000004&(data))>>2)
#define OSDCOMP_BIST_DONE_dmabuf_shift                                               (1)
#define OSDCOMP_BIST_DONE_dmabuf_mask                                                (0x00000002)
#define OSDCOMP_BIST_DONE_dmabuf(data)                                               (0x00000002&((data)<<1))
#define OSDCOMP_BIST_DONE_dmabuf_src(data)                                           ((0x00000002&(data))>>1)
#define OSDCOMP_BIST_DONE_get_dmabuf(data)                                           ((0x00000002&(data))>>1)
#define OSDCOMP_BIST_DONE_dispbuf_shift                                              (0)
#define OSDCOMP_BIST_DONE_dispbuf_mask                                               (0x00000001)
#define OSDCOMP_BIST_DONE_dispbuf(data)                                              (0x00000001&((data)<<0))
#define OSDCOMP_BIST_DONE_dispbuf_src(data)                                          ((0x00000001&(data))>>0)
#define OSDCOMP_BIST_DONE_get_dispbuf(data)                                          ((0x00000001&(data))>>0)


#define OSDCOMP_MBIST_FAIL_GROUP                                                     0x180311d8
#define OSDCOMP_MBIST_FAIL_GROUP_reg_addr                                            "0xB80311D8"
#define OSDCOMP_MBIST_FAIL_GROUP_reg                                                 0xB80311D8
#define set_OSDCOMP_MBIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) OSDCOMP_MBIST_FAIL_GROUP_reg)=data)
#define get_OSDCOMP_MBIST_FAIL_GROUP_reg   (*((volatile unsigned int*) OSDCOMP_MBIST_FAIL_GROUP_reg))
#define OSDCOMP_MBIST_FAIL_GROUP_inst_adr                                            "0x0076"
#define OSDCOMP_MBIST_FAIL_GROUP_inst                                                0x0076
#define OSDCOMP_MBIST_FAIL_GROUP_decomp_shift                                        (5)
#define OSDCOMP_MBIST_FAIL_GROUP_decomp_mask                                         (0x00000020)
#define OSDCOMP_MBIST_FAIL_GROUP_decomp(data)                                        (0x00000020&((data)<<5))
#define OSDCOMP_MBIST_FAIL_GROUP_decomp_src(data)                                    ((0x00000020&(data))>>5)
#define OSDCOMP_MBIST_FAIL_GROUP_get_decomp(data)                                    ((0x00000020&(data))>>5)
#define OSDCOMP_MBIST_FAIL_GROUP_comp_shift                                          (4)
#define OSDCOMP_MBIST_FAIL_GROUP_comp_mask                                           (0x00000010)
#define OSDCOMP_MBIST_FAIL_GROUP_comp(data)                                          (0x00000010&((data)<<4))
#define OSDCOMP_MBIST_FAIL_GROUP_comp_src(data)                                      ((0x00000010&(data))>>4)
#define OSDCOMP_MBIST_FAIL_GROUP_get_comp(data)                                      ((0x00000010&(data))>>4)
#define OSDCOMP_MBIST_FAIL_GROUP_osd1_shift                                          (3)
#define OSDCOMP_MBIST_FAIL_GROUP_osd1_mask                                           (0x00000008)
#define OSDCOMP_MBIST_FAIL_GROUP_osd1(data)                                          (0x00000008&((data)<<3))
#define OSDCOMP_MBIST_FAIL_GROUP_osd1_src(data)                                      ((0x00000008&(data))>>3)
#define OSDCOMP_MBIST_FAIL_GROUP_get_osd1(data)                                      ((0x00000008&(data))>>3)
#define OSDCOMP_MBIST_FAIL_GROUP_rbuf_shift                                          (2)
#define OSDCOMP_MBIST_FAIL_GROUP_rbuf_mask                                           (0x00000004)
#define OSDCOMP_MBIST_FAIL_GROUP_rbuf(data)                                          (0x00000004&((data)<<2))
#define OSDCOMP_MBIST_FAIL_GROUP_rbuf_src(data)                                      ((0x00000004&(data))>>2)
#define OSDCOMP_MBIST_FAIL_GROUP_get_rbuf(data)                                      ((0x00000004&(data))>>2)
#define OSDCOMP_MBIST_FAIL_GROUP_dmabuf_shift                                        (1)
#define OSDCOMP_MBIST_FAIL_GROUP_dmabuf_mask                                         (0x00000002)
#define OSDCOMP_MBIST_FAIL_GROUP_dmabuf(data)                                        (0x00000002&((data)<<1))
#define OSDCOMP_MBIST_FAIL_GROUP_dmabuf_src(data)                                    ((0x00000002&(data))>>1)
#define OSDCOMP_MBIST_FAIL_GROUP_get_dmabuf(data)                                    ((0x00000002&(data))>>1)
#define OSDCOMP_MBIST_FAIL_GROUP_dispbuf_shift                                       (0)
#define OSDCOMP_MBIST_FAIL_GROUP_dispbuf_mask                                        (0x00000001)
#define OSDCOMP_MBIST_FAIL_GROUP_dispbuf(data)                                       (0x00000001&((data)<<0))
#define OSDCOMP_MBIST_FAIL_GROUP_dispbuf_src(data)                                   ((0x00000001&(data))>>0)
#define OSDCOMP_MBIST_FAIL_GROUP_get_dispbuf(data)                                   ((0x00000001&(data))>>0)


#define OSDCOMP_DRF_BIST_MODE                                                        0x180311dc
#define OSDCOMP_DRF_BIST_MODE_reg_addr                                               "0xB80311DC"
#define OSDCOMP_DRF_BIST_MODE_reg                                                    0xB80311DC
#define set_OSDCOMP_DRF_BIST_MODE_reg(data)   (*((volatile unsigned int*) OSDCOMP_DRF_BIST_MODE_reg)=data)
#define get_OSDCOMP_DRF_BIST_MODE_reg   (*((volatile unsigned int*) OSDCOMP_DRF_BIST_MODE_reg))
#define OSDCOMP_DRF_BIST_MODE_inst_adr                                               "0x0077"
#define OSDCOMP_DRF_BIST_MODE_inst                                                   0x0077
#define OSDCOMP_DRF_BIST_MODE_decomp_shift                                           (5)
#define OSDCOMP_DRF_BIST_MODE_decomp_mask                                            (0x00000020)
#define OSDCOMP_DRF_BIST_MODE_decomp(data)                                           (0x00000020&((data)<<5))
#define OSDCOMP_DRF_BIST_MODE_decomp_src(data)                                       ((0x00000020&(data))>>5)
#define OSDCOMP_DRF_BIST_MODE_get_decomp(data)                                       ((0x00000020&(data))>>5)
#define OSDCOMP_DRF_BIST_MODE_comp_shift                                             (4)
#define OSDCOMP_DRF_BIST_MODE_comp_mask                                              (0x00000010)
#define OSDCOMP_DRF_BIST_MODE_comp(data)                                             (0x00000010&((data)<<4))
#define OSDCOMP_DRF_BIST_MODE_comp_src(data)                                         ((0x00000010&(data))>>4)
#define OSDCOMP_DRF_BIST_MODE_get_comp(data)                                         ((0x00000010&(data))>>4)
#define OSDCOMP_DRF_BIST_MODE_osd1_shift                                             (3)
#define OSDCOMP_DRF_BIST_MODE_osd1_mask                                              (0x00000008)
#define OSDCOMP_DRF_BIST_MODE_osd1(data)                                             (0x00000008&((data)<<3))
#define OSDCOMP_DRF_BIST_MODE_osd1_src(data)                                         ((0x00000008&(data))>>3)
#define OSDCOMP_DRF_BIST_MODE_get_osd1(data)                                         ((0x00000008&(data))>>3)
#define OSDCOMP_DRF_BIST_MODE_rbuf_shift                                             (2)
#define OSDCOMP_DRF_BIST_MODE_rbuf_mask                                              (0x00000004)
#define OSDCOMP_DRF_BIST_MODE_rbuf(data)                                             (0x00000004&((data)<<2))
#define OSDCOMP_DRF_BIST_MODE_rbuf_src(data)                                         ((0x00000004&(data))>>2)
#define OSDCOMP_DRF_BIST_MODE_get_rbuf(data)                                         ((0x00000004&(data))>>2)
#define OSDCOMP_DRF_BIST_MODE_dmabuf_shift                                           (1)
#define OSDCOMP_DRF_BIST_MODE_dmabuf_mask                                            (0x00000002)
#define OSDCOMP_DRF_BIST_MODE_dmabuf(data)                                           (0x00000002&((data)<<1))
#define OSDCOMP_DRF_BIST_MODE_dmabuf_src(data)                                       ((0x00000002&(data))>>1)
#define OSDCOMP_DRF_BIST_MODE_get_dmabuf(data)                                       ((0x00000002&(data))>>1)
#define OSDCOMP_DRF_BIST_MODE_dispbuf_shift                                          (0)
#define OSDCOMP_DRF_BIST_MODE_dispbuf_mask                                           (0x00000001)
#define OSDCOMP_DRF_BIST_MODE_dispbuf(data)                                          (0x00000001&((data)<<0))
#define OSDCOMP_DRF_BIST_MODE_dispbuf_src(data)                                      ((0x00000001&(data))>>0)
#define OSDCOMP_DRF_BIST_MODE_get_dispbuf(data)                                      ((0x00000001&(data))>>0)


#define OSDCOMP_DRF_TEST_RESUME                                                      0x180311e0
#define OSDCOMP_DRF_TEST_RESUME_reg_addr                                             "0xB80311E0"
#define OSDCOMP_DRF_TEST_RESUME_reg                                                  0xB80311E0
#define set_OSDCOMP_DRF_TEST_RESUME_reg(data)   (*((volatile unsigned int*) OSDCOMP_DRF_TEST_RESUME_reg)=data)
#define get_OSDCOMP_DRF_TEST_RESUME_reg   (*((volatile unsigned int*) OSDCOMP_DRF_TEST_RESUME_reg))
#define OSDCOMP_DRF_TEST_RESUME_inst_adr                                             "0x0078"
#define OSDCOMP_DRF_TEST_RESUME_inst                                                 0x0078
#define OSDCOMP_DRF_TEST_RESUME_decomp_shift                                         (5)
#define OSDCOMP_DRF_TEST_RESUME_decomp_mask                                          (0x00000020)
#define OSDCOMP_DRF_TEST_RESUME_decomp(data)                                         (0x00000020&((data)<<5))
#define OSDCOMP_DRF_TEST_RESUME_decomp_src(data)                                     ((0x00000020&(data))>>5)
#define OSDCOMP_DRF_TEST_RESUME_get_decomp(data)                                     ((0x00000020&(data))>>5)
#define OSDCOMP_DRF_TEST_RESUME_comp_shift                                           (4)
#define OSDCOMP_DRF_TEST_RESUME_comp_mask                                            (0x00000010)
#define OSDCOMP_DRF_TEST_RESUME_comp(data)                                           (0x00000010&((data)<<4))
#define OSDCOMP_DRF_TEST_RESUME_comp_src(data)                                       ((0x00000010&(data))>>4)
#define OSDCOMP_DRF_TEST_RESUME_get_comp(data)                                       ((0x00000010&(data))>>4)
#define OSDCOMP_DRF_TEST_RESUME_osd1_shift                                           (3)
#define OSDCOMP_DRF_TEST_RESUME_osd1_mask                                            (0x00000008)
#define OSDCOMP_DRF_TEST_RESUME_osd1(data)                                           (0x00000008&((data)<<3))
#define OSDCOMP_DRF_TEST_RESUME_osd1_src(data)                                       ((0x00000008&(data))>>3)
#define OSDCOMP_DRF_TEST_RESUME_get_osd1(data)                                       ((0x00000008&(data))>>3)
#define OSDCOMP_DRF_TEST_RESUME_rbuf_shift                                           (2)
#define OSDCOMP_DRF_TEST_RESUME_rbuf_mask                                            (0x00000004)
#define OSDCOMP_DRF_TEST_RESUME_rbuf(data)                                           (0x00000004&((data)<<2))
#define OSDCOMP_DRF_TEST_RESUME_rbuf_src(data)                                       ((0x00000004&(data))>>2)
#define OSDCOMP_DRF_TEST_RESUME_get_rbuf(data)                                       ((0x00000004&(data))>>2)
#define OSDCOMP_DRF_TEST_RESUME_dmabuf_shift                                         (1)
#define OSDCOMP_DRF_TEST_RESUME_dmabuf_mask                                          (0x00000002)
#define OSDCOMP_DRF_TEST_RESUME_dmabuf(data)                                         (0x00000002&((data)<<1))
#define OSDCOMP_DRF_TEST_RESUME_dmabuf_src(data)                                     ((0x00000002&(data))>>1)
#define OSDCOMP_DRF_TEST_RESUME_get_dmabuf(data)                                     ((0x00000002&(data))>>1)
#define OSDCOMP_DRF_TEST_RESUME_dispbuf_shift                                        (0)
#define OSDCOMP_DRF_TEST_RESUME_dispbuf_mask                                         (0x00000001)
#define OSDCOMP_DRF_TEST_RESUME_dispbuf(data)                                        (0x00000001&((data)<<0))
#define OSDCOMP_DRF_TEST_RESUME_dispbuf_src(data)                                    ((0x00000001&(data))>>0)
#define OSDCOMP_DRF_TEST_RESUME_get_dispbuf(data)                                    ((0x00000001&(data))>>0)


#define OSDCOMP_DRF_BIST_DONE                                                        0x180311e4
#define OSDCOMP_DRF_BIST_DONE_reg_addr                                               "0xB80311E4"
#define OSDCOMP_DRF_BIST_DONE_reg                                                    0xB80311E4
#define set_OSDCOMP_DRF_BIST_DONE_reg(data)   (*((volatile unsigned int*) OSDCOMP_DRF_BIST_DONE_reg)=data)
#define get_OSDCOMP_DRF_BIST_DONE_reg   (*((volatile unsigned int*) OSDCOMP_DRF_BIST_DONE_reg))
#define OSDCOMP_DRF_BIST_DONE_inst_adr                                               "0x0079"
#define OSDCOMP_DRF_BIST_DONE_inst                                                   0x0079
#define OSDCOMP_DRF_BIST_DONE_decomp_shift                                           (5)
#define OSDCOMP_DRF_BIST_DONE_decomp_mask                                            (0x00000020)
#define OSDCOMP_DRF_BIST_DONE_decomp(data)                                           (0x00000020&((data)<<5))
#define OSDCOMP_DRF_BIST_DONE_decomp_src(data)                                       ((0x00000020&(data))>>5)
#define OSDCOMP_DRF_BIST_DONE_get_decomp(data)                                       ((0x00000020&(data))>>5)
#define OSDCOMP_DRF_BIST_DONE_comp_shift                                             (4)
#define OSDCOMP_DRF_BIST_DONE_comp_mask                                              (0x00000010)
#define OSDCOMP_DRF_BIST_DONE_comp(data)                                             (0x00000010&((data)<<4))
#define OSDCOMP_DRF_BIST_DONE_comp_src(data)                                         ((0x00000010&(data))>>4)
#define OSDCOMP_DRF_BIST_DONE_get_comp(data)                                         ((0x00000010&(data))>>4)
#define OSDCOMP_DRF_BIST_DONE_osd1_shift                                             (3)
#define OSDCOMP_DRF_BIST_DONE_osd1_mask                                              (0x00000008)
#define OSDCOMP_DRF_BIST_DONE_osd1(data)                                             (0x00000008&((data)<<3))
#define OSDCOMP_DRF_BIST_DONE_osd1_src(data)                                         ((0x00000008&(data))>>3)
#define OSDCOMP_DRF_BIST_DONE_get_osd1(data)                                         ((0x00000008&(data))>>3)
#define OSDCOMP_DRF_BIST_DONE_rbuf_shift                                             (2)
#define OSDCOMP_DRF_BIST_DONE_rbuf_mask                                              (0x00000004)
#define OSDCOMP_DRF_BIST_DONE_rbuf(data)                                             (0x00000004&((data)<<2))
#define OSDCOMP_DRF_BIST_DONE_rbuf_src(data)                                         ((0x00000004&(data))>>2)
#define OSDCOMP_DRF_BIST_DONE_get_rbuf(data)                                         ((0x00000004&(data))>>2)
#define OSDCOMP_DRF_BIST_DONE_dmabuf_shift                                           (1)
#define OSDCOMP_DRF_BIST_DONE_dmabuf_mask                                            (0x00000002)
#define OSDCOMP_DRF_BIST_DONE_dmabuf(data)                                           (0x00000002&((data)<<1))
#define OSDCOMP_DRF_BIST_DONE_dmabuf_src(data)                                       ((0x00000002&(data))>>1)
#define OSDCOMP_DRF_BIST_DONE_get_dmabuf(data)                                       ((0x00000002&(data))>>1)
#define OSDCOMP_DRF_BIST_DONE_dispbuf_shift                                          (0)
#define OSDCOMP_DRF_BIST_DONE_dispbuf_mask                                           (0x00000001)
#define OSDCOMP_DRF_BIST_DONE_dispbuf(data)                                          (0x00000001&((data)<<0))
#define OSDCOMP_DRF_BIST_DONE_dispbuf_src(data)                                      ((0x00000001&(data))>>0)
#define OSDCOMP_DRF_BIST_DONE_get_dispbuf(data)                                      ((0x00000001&(data))>>0)


#define OSDCOMP_DRF_START_PAUSE                                                      0x180311e8
#define OSDCOMP_DRF_START_PAUSE_reg_addr                                             "0xB80311E8"
#define OSDCOMP_DRF_START_PAUSE_reg                                                  0xB80311E8
#define set_OSDCOMP_DRF_START_PAUSE_reg(data)   (*((volatile unsigned int*) OSDCOMP_DRF_START_PAUSE_reg)=data)
#define get_OSDCOMP_DRF_START_PAUSE_reg   (*((volatile unsigned int*) OSDCOMP_DRF_START_PAUSE_reg))
#define OSDCOMP_DRF_START_PAUSE_inst_adr                                             "0x007A"
#define OSDCOMP_DRF_START_PAUSE_inst                                                 0x007A
#define OSDCOMP_DRF_START_PAUSE_decomp_shift                                         (5)
#define OSDCOMP_DRF_START_PAUSE_decomp_mask                                          (0x00000020)
#define OSDCOMP_DRF_START_PAUSE_decomp(data)                                         (0x00000020&((data)<<5))
#define OSDCOMP_DRF_START_PAUSE_decomp_src(data)                                     ((0x00000020&(data))>>5)
#define OSDCOMP_DRF_START_PAUSE_get_decomp(data)                                     ((0x00000020&(data))>>5)
#define OSDCOMP_DRF_START_PAUSE_comp_shift                                           (4)
#define OSDCOMP_DRF_START_PAUSE_comp_mask                                            (0x00000010)
#define OSDCOMP_DRF_START_PAUSE_comp(data)                                           (0x00000010&((data)<<4))
#define OSDCOMP_DRF_START_PAUSE_comp_src(data)                                       ((0x00000010&(data))>>4)
#define OSDCOMP_DRF_START_PAUSE_get_comp(data)                                       ((0x00000010&(data))>>4)
#define OSDCOMP_DRF_START_PAUSE_osd1_shift                                           (3)
#define OSDCOMP_DRF_START_PAUSE_osd1_mask                                            (0x00000008)
#define OSDCOMP_DRF_START_PAUSE_osd1(data)                                           (0x00000008&((data)<<3))
#define OSDCOMP_DRF_START_PAUSE_osd1_src(data)                                       ((0x00000008&(data))>>3)
#define OSDCOMP_DRF_START_PAUSE_get_osd1(data)                                       ((0x00000008&(data))>>3)
#define OSDCOMP_DRF_START_PAUSE_rbuf_shift                                           (2)
#define OSDCOMP_DRF_START_PAUSE_rbuf_mask                                            (0x00000004)
#define OSDCOMP_DRF_START_PAUSE_rbuf(data)                                           (0x00000004&((data)<<2))
#define OSDCOMP_DRF_START_PAUSE_rbuf_src(data)                                       ((0x00000004&(data))>>2)
#define OSDCOMP_DRF_START_PAUSE_get_rbuf(data)                                       ((0x00000004&(data))>>2)
#define OSDCOMP_DRF_START_PAUSE_dmabuf_shift                                         (1)
#define OSDCOMP_DRF_START_PAUSE_dmabuf_mask                                          (0x00000002)
#define OSDCOMP_DRF_START_PAUSE_dmabuf(data)                                         (0x00000002&((data)<<1))
#define OSDCOMP_DRF_START_PAUSE_dmabuf_src(data)                                     ((0x00000002&(data))>>1)
#define OSDCOMP_DRF_START_PAUSE_get_dmabuf(data)                                     ((0x00000002&(data))>>1)
#define OSDCOMP_DRF_START_PAUSE_dispbuf_shift                                        (0)
#define OSDCOMP_DRF_START_PAUSE_dispbuf_mask                                         (0x00000001)
#define OSDCOMP_DRF_START_PAUSE_dispbuf(data)                                        (0x00000001&((data)<<0))
#define OSDCOMP_DRF_START_PAUSE_dispbuf_src(data)                                    ((0x00000001&(data))>>0)
#define OSDCOMP_DRF_START_PAUSE_get_dispbuf(data)                                    ((0x00000001&(data))>>0)


#define OSDCOMP_MBIST_DRF_FAIL_GROUP                                                 0x180311ec
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_reg_addr                                        "0xB80311EC"
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_reg                                             0xB80311EC
#define set_OSDCOMP_MBIST_DRF_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) OSDCOMP_MBIST_DRF_FAIL_GROUP_reg)=data)
#define get_OSDCOMP_MBIST_DRF_FAIL_GROUP_reg   (*((volatile unsigned int*) OSDCOMP_MBIST_DRF_FAIL_GROUP_reg))
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_inst_adr                                        "0x007B"
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_inst                                            0x007B
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_decomp_shift                                    (5)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_decomp_mask                                     (0x00000020)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_decomp(data)                                    (0x00000020&((data)<<5))
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_decomp_src(data)                                ((0x00000020&(data))>>5)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_get_decomp(data)                                ((0x00000020&(data))>>5)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_comp_shift                                      (4)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_comp_mask                                       (0x00000010)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_comp(data)                                      (0x00000010&((data)<<4))
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_comp_src(data)                                  ((0x00000010&(data))>>4)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_get_comp(data)                                  ((0x00000010&(data))>>4)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_osd1_shift                                      (3)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_osd1_mask                                       (0x00000008)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_osd1(data)                                      (0x00000008&((data)<<3))
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_osd1_src(data)                                  ((0x00000008&(data))>>3)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_get_osd1(data)                                  ((0x00000008&(data))>>3)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_rbuf_shift                                      (2)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_rbuf_mask                                       (0x00000004)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_rbuf(data)                                      (0x00000004&((data)<<2))
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_rbuf_src(data)                                  ((0x00000004&(data))>>2)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_get_rbuf(data)                                  ((0x00000004&(data))>>2)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_dmabuf_shift                                    (1)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_dmabuf_mask                                     (0x00000002)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_dmabuf(data)                                    (0x00000002&((data)<<1))
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_dmabuf_src(data)                                ((0x00000002&(data))>>1)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_get_dmabuf(data)                                ((0x00000002&(data))>>1)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_dispbuf_shift                                   (0)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_dispbuf_mask                                    (0x00000001)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_dispbuf(data)                                   (0x00000001&((data)<<0))
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_dispbuf_src(data)                               ((0x00000001&(data))>>0)
#define OSDCOMP_MBIST_DRF_FAIL_GROUP_get_dispbuf(data)                               ((0x00000001&(data))>>0)


#define OSDCOMP_MBIST_FAIL                                                           0x180311f0
#define OSDCOMP_MBIST_FAIL_reg_addr                                                  "0xB80311F0"
#define OSDCOMP_MBIST_FAIL_reg                                                       0xB80311F0
#define set_OSDCOMP_MBIST_FAIL_reg(data)   (*((volatile unsigned int*) OSDCOMP_MBIST_FAIL_reg)=data)
#define get_OSDCOMP_MBIST_FAIL_reg   (*((volatile unsigned int*) OSDCOMP_MBIST_FAIL_reg))
#define OSDCOMP_MBIST_FAIL_inst_adr                                                  "0x007C"
#define OSDCOMP_MBIST_FAIL_inst                                                      0x007C
#define OSDCOMP_MBIST_FAIL_decomp_shift                                              (18)
#define OSDCOMP_MBIST_FAIL_decomp_mask                                               (0x00040000)
#define OSDCOMP_MBIST_FAIL_decomp(data)                                              (0x00040000&((data)<<18))
#define OSDCOMP_MBIST_FAIL_decomp_src(data)                                          ((0x00040000&(data))>>18)
#define OSDCOMP_MBIST_FAIL_get_decomp(data)                                          ((0x00040000&(data))>>18)
#define OSDCOMP_MBIST_FAIL_comp_shift                                                (17)
#define OSDCOMP_MBIST_FAIL_comp_mask                                                 (0x00020000)
#define OSDCOMP_MBIST_FAIL_comp(data)                                                (0x00020000&((data)<<17))
#define OSDCOMP_MBIST_FAIL_comp_src(data)                                            ((0x00020000&(data))>>17)
#define OSDCOMP_MBIST_FAIL_get_comp(data)                                            ((0x00020000&(data))>>17)
#define OSDCOMP_MBIST_FAIL_osd1_shift                                                (9)
#define OSDCOMP_MBIST_FAIL_osd1_mask                                                 (0x0001FE00)
#define OSDCOMP_MBIST_FAIL_osd1(data)                                                (0x0001FE00&((data)<<9))
#define OSDCOMP_MBIST_FAIL_osd1_src(data)                                            ((0x0001FE00&(data))>>9)
#define OSDCOMP_MBIST_FAIL_get_osd1(data)                                            ((0x0001FE00&(data))>>9)
#define OSDCOMP_MBIST_FAIL_rbuf_shift                                                (3)
#define OSDCOMP_MBIST_FAIL_rbuf_mask                                                 (0x000001F8)
#define OSDCOMP_MBIST_FAIL_rbuf(data)                                                (0x000001F8&((data)<<3))
#define OSDCOMP_MBIST_FAIL_rbuf_src(data)                                            ((0x000001F8&(data))>>3)
#define OSDCOMP_MBIST_FAIL_get_rbuf(data)                                            ((0x000001F8&(data))>>3)
#define OSDCOMP_MBIST_FAIL_dmabuf_shift                                              (2)
#define OSDCOMP_MBIST_FAIL_dmabuf_mask                                               (0x00000004)
#define OSDCOMP_MBIST_FAIL_dmabuf(data)                                              (0x00000004&((data)<<2))
#define OSDCOMP_MBIST_FAIL_dmabuf_src(data)                                          ((0x00000004&(data))>>2)
#define OSDCOMP_MBIST_FAIL_get_dmabuf(data)                                          ((0x00000004&(data))>>2)
#define OSDCOMP_MBIST_FAIL_dispbuf_shift                                             (0)
#define OSDCOMP_MBIST_FAIL_dispbuf_mask                                              (0x00000003)
#define OSDCOMP_MBIST_FAIL_dispbuf(data)                                             (0x00000003&((data)<<0))
#define OSDCOMP_MBIST_FAIL_dispbuf_src(data)                                         ((0x00000003&(data))>>0)
#define OSDCOMP_MBIST_FAIL_get_dispbuf(data)                                         ((0x00000003&(data))>>0)


#define OSDCOMP_MBIST_DRF_FAIL                                                       0x180311f4
#define OSDCOMP_MBIST_DRF_FAIL_reg_addr                                              "0xB80311F4"
#define OSDCOMP_MBIST_DRF_FAIL_reg                                                   0xB80311F4
#define set_OSDCOMP_MBIST_DRF_FAIL_reg(data)   (*((volatile unsigned int*) OSDCOMP_MBIST_DRF_FAIL_reg)=data)
#define get_OSDCOMP_MBIST_DRF_FAIL_reg   (*((volatile unsigned int*) OSDCOMP_MBIST_DRF_FAIL_reg))
#define OSDCOMP_MBIST_DRF_FAIL_inst_adr                                              "0x007D"
#define OSDCOMP_MBIST_DRF_FAIL_inst                                                  0x007D
#define OSDCOMP_MBIST_DRF_FAIL_decomp_shift                                          (18)
#define OSDCOMP_MBIST_DRF_FAIL_decomp_mask                                           (0x00040000)
#define OSDCOMP_MBIST_DRF_FAIL_decomp(data)                                          (0x00040000&((data)<<18))
#define OSDCOMP_MBIST_DRF_FAIL_decomp_src(data)                                      ((0x00040000&(data))>>18)
#define OSDCOMP_MBIST_DRF_FAIL_get_decomp(data)                                      ((0x00040000&(data))>>18)
#define OSDCOMP_MBIST_DRF_FAIL_comp_shift                                            (17)
#define OSDCOMP_MBIST_DRF_FAIL_comp_mask                                             (0x00020000)
#define OSDCOMP_MBIST_DRF_FAIL_comp(data)                                            (0x00020000&((data)<<17))
#define OSDCOMP_MBIST_DRF_FAIL_comp_src(data)                                        ((0x00020000&(data))>>17)
#define OSDCOMP_MBIST_DRF_FAIL_get_comp(data)                                        ((0x00020000&(data))>>17)
#define OSDCOMP_MBIST_DRF_FAIL_osd1_shift                                            (9)
#define OSDCOMP_MBIST_DRF_FAIL_osd1_mask                                             (0x0001FE00)
#define OSDCOMP_MBIST_DRF_FAIL_osd1(data)                                            (0x0001FE00&((data)<<9))
#define OSDCOMP_MBIST_DRF_FAIL_osd1_src(data)                                        ((0x0001FE00&(data))>>9)
#define OSDCOMP_MBIST_DRF_FAIL_get_osd1(data)                                        ((0x0001FE00&(data))>>9)
#define OSDCOMP_MBIST_DRF_FAIL_rbuf_shift                                            (3)
#define OSDCOMP_MBIST_DRF_FAIL_rbuf_mask                                             (0x000001F8)
#define OSDCOMP_MBIST_DRF_FAIL_rbuf(data)                                            (0x000001F8&((data)<<3))
#define OSDCOMP_MBIST_DRF_FAIL_rbuf_src(data)                                        ((0x000001F8&(data))>>3)
#define OSDCOMP_MBIST_DRF_FAIL_get_rbuf(data)                                        ((0x000001F8&(data))>>3)
#define OSDCOMP_MBIST_DRF_FAIL_dmabuf_shift                                          (2)
#define OSDCOMP_MBIST_DRF_FAIL_dmabuf_mask                                           (0x00000004)
#define OSDCOMP_MBIST_DRF_FAIL_dmabuf(data)                                          (0x00000004&((data)<<2))
#define OSDCOMP_MBIST_DRF_FAIL_dmabuf_src(data)                                      ((0x00000004&(data))>>2)
#define OSDCOMP_MBIST_DRF_FAIL_get_dmabuf(data)                                      ((0x00000004&(data))>>2)
#define OSDCOMP_MBIST_DRF_FAIL_dispbuf_shift                                         (0)
#define OSDCOMP_MBIST_DRF_FAIL_dispbuf_mask                                          (0x00000003)
#define OSDCOMP_MBIST_DRF_FAIL_dispbuf(data)                                         (0x00000003&((data)<<0))
#define OSDCOMP_MBIST_DRF_FAIL_dispbuf_src(data)                                     ((0x00000003&(data))>>0)
#define OSDCOMP_MBIST_DRF_FAIL_get_dispbuf(data)                                     ((0x00000003&(data))>>0)


#define OSDCOMP_COMP_MBIST_RM                                                        0x180311f8
#define OSDCOMP_COMP_MBIST_RM_reg_addr                                               "0xB80311F8"
#define OSDCOMP_COMP_MBIST_RM_reg                                                    0xB80311F8
#define set_OSDCOMP_COMP_MBIST_RM_reg(data)   (*((volatile unsigned int*) OSDCOMP_COMP_MBIST_RM_reg)=data)
#define get_OSDCOMP_COMP_MBIST_RM_reg   (*((volatile unsigned int*) OSDCOMP_COMP_MBIST_RM_reg))
#define OSDCOMP_COMP_MBIST_RM_inst_adr                                               "0x007E"
#define OSDCOMP_COMP_MBIST_RM_inst                                                   0x007E
#define OSDCOMP_COMP_MBIST_RM_revise_d3_dup_bug_shift                                (31)
#define OSDCOMP_COMP_MBIST_RM_revise_d3_dup_bug_mask                                 (0x80000000)
#define OSDCOMP_COMP_MBIST_RM_revise_d3_dup_bug(data)                                (0x80000000&((data)<<31))
#define OSDCOMP_COMP_MBIST_RM_revise_d3_dup_bug_src(data)                            ((0x80000000&(data))>>31)
#define OSDCOMP_COMP_MBIST_RM_get_revise_d3_dup_bug(data)                            ((0x80000000&(data))>>31)
#define OSDCOMP_COMP_MBIST_RM_dummy_shift                                            (28)
#define OSDCOMP_COMP_MBIST_RM_dummy_mask                                             (0x70000000)
#define OSDCOMP_COMP_MBIST_RM_dummy(data)                                            (0x70000000&((data)<<28))
#define OSDCOMP_COMP_MBIST_RM_dummy_src(data)                                        ((0x70000000&(data))>>28)
#define OSDCOMP_COMP_MBIST_RM_get_dummy(data)                                        ((0x70000000&(data))>>28)
#define OSDCOMP_COMP_MBIST_RM_decomp_shift                                           (24)
#define OSDCOMP_COMP_MBIST_RM_decomp_mask                                            (0x0F000000)
#define OSDCOMP_COMP_MBIST_RM_decomp(data)                                           (0x0F000000&((data)<<24))
#define OSDCOMP_COMP_MBIST_RM_decomp_src(data)                                       ((0x0F000000&(data))>>24)
#define OSDCOMP_COMP_MBIST_RM_get_decomp(data)                                       ((0x0F000000&(data))>>24)
#define OSDCOMP_COMP_MBIST_RM_comp_shift                                             (20)
#define OSDCOMP_COMP_MBIST_RM_comp_mask                                              (0x00F00000)
#define OSDCOMP_COMP_MBIST_RM_comp(data)                                             (0x00F00000&((data)<<20))
#define OSDCOMP_COMP_MBIST_RM_comp_src(data)                                         ((0x00F00000&(data))>>20)
#define OSDCOMP_COMP_MBIST_RM_get_comp(data)                                         ((0x00F00000&(data))>>20)
#define OSDCOMP_COMP_MBIST_RM_osd1_shift                                             (16)
#define OSDCOMP_COMP_MBIST_RM_osd1_mask                                              (0x000F0000)
#define OSDCOMP_COMP_MBIST_RM_osd1(data)                                             (0x000F0000&((data)<<16))
#define OSDCOMP_COMP_MBIST_RM_osd1_src(data)                                         ((0x000F0000&(data))>>16)
#define OSDCOMP_COMP_MBIST_RM_get_osd1(data)                                         ((0x000F0000&(data))>>16)
#define OSDCOMP_COMP_MBIST_RM_rbuf_shift                                             (12)
#define OSDCOMP_COMP_MBIST_RM_rbuf_mask                                              (0x0000F000)
#define OSDCOMP_COMP_MBIST_RM_rbuf(data)                                             (0x0000F000&((data)<<12))
#define OSDCOMP_COMP_MBIST_RM_rbuf_src(data)                                         ((0x0000F000&(data))>>12)
#define OSDCOMP_COMP_MBIST_RM_get_rbuf(data)                                         ((0x0000F000&(data))>>12)
#define OSDCOMP_COMP_MBIST_RM_dmabuf_shift                                           (8)
#define OSDCOMP_COMP_MBIST_RM_dmabuf_mask                                            (0x00000F00)
#define OSDCOMP_COMP_MBIST_RM_dmabuf(data)                                           (0x00000F00&((data)<<8))
#define OSDCOMP_COMP_MBIST_RM_dmabuf_src(data)                                       ((0x00000F00&(data))>>8)
#define OSDCOMP_COMP_MBIST_RM_get_dmabuf(data)                                       ((0x00000F00&(data))>>8)
#define OSDCOMP_COMP_MBIST_RM_dispbuf0_shift                                         (4)
#define OSDCOMP_COMP_MBIST_RM_dispbuf0_mask                                          (0x000000F0)
#define OSDCOMP_COMP_MBIST_RM_dispbuf0(data)                                         (0x000000F0&((data)<<4))
#define OSDCOMP_COMP_MBIST_RM_dispbuf0_src(data)                                     ((0x000000F0&(data))>>4)
#define OSDCOMP_COMP_MBIST_RM_get_dispbuf0(data)                                     ((0x000000F0&(data))>>4)
#define OSDCOMP_COMP_MBIST_RM_dispbuf1_shift                                         (0)
#define OSDCOMP_COMP_MBIST_RM_dispbuf1_mask                                          (0x0000000F)
#define OSDCOMP_COMP_MBIST_RM_dispbuf1(data)                                         (0x0000000F&((data)<<0))
#define OSDCOMP_COMP_MBIST_RM_dispbuf1_src(data)                                     ((0x0000000F&(data))>>0)
#define OSDCOMP_COMP_MBIST_RM_get_dispbuf1(data)                                     ((0x0000000F&(data))>>0)


#define OSDCOMP_COMP_MBIST_RME                                                       0x180311fc
#define OSDCOMP_COMP_MBIST_RME_reg_addr                                              "0xB80311FC"
#define OSDCOMP_COMP_MBIST_RME_reg                                                   0xB80311FC
#define set_OSDCOMP_COMP_MBIST_RME_reg(data)   (*((volatile unsigned int*) OSDCOMP_COMP_MBIST_RME_reg)=data)
#define get_OSDCOMP_COMP_MBIST_RME_reg   (*((volatile unsigned int*) OSDCOMP_COMP_MBIST_RME_reg))
#define OSDCOMP_COMP_MBIST_RME_inst_adr                                              "0x007F"
#define OSDCOMP_COMP_MBIST_RME_inst                                                  0x007F
#define OSDCOMP_COMP_MBIST_RME_decomp_shift                                          (31)
#define OSDCOMP_COMP_MBIST_RME_decomp_mask                                           (0x80000000)
#define OSDCOMP_COMP_MBIST_RME_decomp(data)                                          (0x80000000&((data)<<31))
#define OSDCOMP_COMP_MBIST_RME_decomp_src(data)                                      ((0x80000000&(data))>>31)
#define OSDCOMP_COMP_MBIST_RME_get_decomp(data)                                      ((0x80000000&(data))>>31)
#define OSDCOMP_COMP_MBIST_RME_comp_shift                                            (30)
#define OSDCOMP_COMP_MBIST_RME_comp_mask                                             (0x40000000)
#define OSDCOMP_COMP_MBIST_RME_comp(data)                                            (0x40000000&((data)<<30))
#define OSDCOMP_COMP_MBIST_RME_comp_src(data)                                        ((0x40000000&(data))>>30)
#define OSDCOMP_COMP_MBIST_RME_get_comp(data)                                        ((0x40000000&(data))>>30)
#define OSDCOMP_COMP_MBIST_RME_osd1_shift                                            (29)
#define OSDCOMP_COMP_MBIST_RME_osd1_mask                                             (0x20000000)
#define OSDCOMP_COMP_MBIST_RME_osd1(data)                                            (0x20000000&((data)<<29))
#define OSDCOMP_COMP_MBIST_RME_osd1_src(data)                                        ((0x20000000&(data))>>29)
#define OSDCOMP_COMP_MBIST_RME_get_osd1(data)                                        ((0x20000000&(data))>>29)
#define OSDCOMP_COMP_MBIST_RME_rbuf_shift                                            (28)
#define OSDCOMP_COMP_MBIST_RME_rbuf_mask                                             (0x10000000)
#define OSDCOMP_COMP_MBIST_RME_rbuf(data)                                            (0x10000000&((data)<<28))
#define OSDCOMP_COMP_MBIST_RME_rbuf_src(data)                                        ((0x10000000&(data))>>28)
#define OSDCOMP_COMP_MBIST_RME_get_rbuf(data)                                        ((0x10000000&(data))>>28)
#define OSDCOMP_COMP_MBIST_RME_dmabuf_shift                                          (27)
#define OSDCOMP_COMP_MBIST_RME_dmabuf_mask                                           (0x08000000)
#define OSDCOMP_COMP_MBIST_RME_dmabuf(data)                                          (0x08000000&((data)<<27))
#define OSDCOMP_COMP_MBIST_RME_dmabuf_src(data)                                      ((0x08000000&(data))>>27)
#define OSDCOMP_COMP_MBIST_RME_get_dmabuf(data)                                      ((0x08000000&(data))>>27)
#define OSDCOMP_COMP_MBIST_RME_dispbuf0_shift                                        (26)
#define OSDCOMP_COMP_MBIST_RME_dispbuf0_mask                                         (0x04000000)
#define OSDCOMP_COMP_MBIST_RME_dispbuf0(data)                                        (0x04000000&((data)<<26))
#define OSDCOMP_COMP_MBIST_RME_dispbuf0_src(data)                                    ((0x04000000&(data))>>26)
#define OSDCOMP_COMP_MBIST_RME_get_dispbuf0(data)                                    ((0x04000000&(data))>>26)
#define OSDCOMP_COMP_MBIST_RME_dispbuf1_shift                                        (25)
#define OSDCOMP_COMP_MBIST_RME_dispbuf1_mask                                         (0x02000000)
#define OSDCOMP_COMP_MBIST_RME_dispbuf1(data)                                        (0x02000000&((data)<<25))
#define OSDCOMP_COMP_MBIST_RME_dispbuf1_src(data)                                    ((0x02000000&(data))>>25)
#define OSDCOMP_COMP_MBIST_RME_get_dispbuf1(data)                                    ((0x02000000&(data))>>25)
#define OSDCOMP_COMP_MBIST_RME_dummy_shift                                           (0)
#define OSDCOMP_COMP_MBIST_RME_dummy_mask                                            (0x01FFFFFF)
#define OSDCOMP_COMP_MBIST_RME_dummy(data)                                           (0x01FFFFFF&((data)<<0))
#define OSDCOMP_COMP_MBIST_RME_dummy_src(data)                                       ((0x01FFFFFF&(data))>>0)
#define OSDCOMP_COMP_MBIST_RME_get_dummy(data)                                       ((0x01FFFFFF&(data))>>0)


#endif
