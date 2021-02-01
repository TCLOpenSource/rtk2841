/**************************************************************
// Spec Version                  : 1.9
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014/10/8 19:44:54
***************************************************************/


#ifndef _GDMA_REG_H_INCLUDED_
#define _GDMA_REG_H_INCLUDED_


/* Global CLock */
#define MIS_SCPU_CLK90K_HI_reg                          0xB801B694
#define MIS_SCPU_CLK90K_LO_reg                          0xB801B690



typedef struct {
	unsigned int  left_offset:11;
	unsigned int  left_dir:1;              /* 0: shift left, 1: shift right */
	unsigned int  right_offset:11;
	unsigned int  right_dir:1;
	unsigned int  reserved:8;
} ppoverlay_3D_OFFSET ;

#ifndef LITTLE_ENDIAN /* apply BIG_ENDIAN */
typedef union {
	unsigned int     reserved_0:15;
	unsigned int     gating_enable:1;
	unsigned int     reserved_1:2;
	unsigned int     osd5_bypass_acc_sync_fix:1;
	unsigned int     osd4_bypass_acc_sync_fix:1;
	unsigned int     osd3_bypass_acc_sync_fix:1;
	unsigned int     osd2_bypass_acc_sync_fix:1;
	unsigned int     osd1_bypass_acc_sync_fix:1;
	unsigned int     reserved_2:7;
	unsigned int     osd_sel:1;
	unsigned int     write_data:1;
} update_RBUS;

typedef union {
	unsigned int     reserved_0:15;
	unsigned int     offline_software_abort:1;
	unsigned int     reserved_1:7;
	unsigned int     offline_go:1;
	unsigned int     reserved_2:1;
	unsigned int     osd_others_prog_done:1;
	unsigned int     osd5_prog_done:1;
	unsigned int     osd4_prog_done:1;
	unsigned int     osd3_prog_done:1;
	unsigned int     osd2_prog_done:1;
	unsigned int     osd1_prog_done:1;
	unsigned int     write_data:1;
} ctrl_RBUS;

typedef union {
	unsigned int     reserved_0:7;
	unsigned int     set_osd1_fbdc1_use_2nd_dma:1;
	unsigned int     set_osd1_fbdc2_use_2nd_dma:1;
	unsigned int     set_osd1_fbdc3_use_2nd_dma:1;
	unsigned int     set_osd2_fbdc1_use_2nd_dma:1;
	unsigned int     set_osd2_fbdc2_use_2nd_dma:1;
	unsigned int     set_osd2_fbdc3_use_2nd_dma:1;
	unsigned int     set_osd3_fbdc1_use_2nd_dma:1;
	unsigned int     set_osd3_fbdc2_use_2nd_dma:1;
	unsigned int     set_osd3_fbdc3_use_2nd_dma:1;
	unsigned int     reserved_1:2;
	unsigned int     set_osd5_online_use_offline_dma:1;
	unsigned int     set_osd4_online_use_offline_dma:1;
	unsigned int     set_osd3_online_use_offline_dma:1;
	unsigned int     set_osd2_online_use_offline_dma:1;
	unsigned int     set_osd1_online_use_offline_dma:1;
	unsigned int     reserved_2:3;
	unsigned int     set_osd5_offline:1;
	unsigned int     set_osd4_offline:1;
	unsigned int     set_osd3_offline:1;
	unsigned int     set_osd2_offline:1;
	unsigned int     set_osd1_offline:1;
	unsigned int     write_back_src_sel:1;
} online_RBUS;

typedef union {
	unsigned int     reserved_0:1;
	unsigned int     l6_config_5k:1;
	unsigned int     l5_config_5k:1;
	unsigned int     l4_config_5k:1;
	unsigned int     l3_config_5k:1;
	unsigned int     l2_config_5k:1;
	unsigned int     l1_config_5k:1;
	unsigned int     reserved_1:8;
	unsigned int     reserved_2:3;
	unsigned int     set_osd5_go_middle_blend:1;
	unsigned int     set_osd4_go_middle_blend:1;
	unsigned int     set_osd3_go_middle_blend:1;
	unsigned int     set_osd2_go_middle_blend:1;
	unsigned int     set_osd1_go_middle_blend:1;
	unsigned int     reserved_3:9;
} resource_lb_RBUS;

typedef union {
	unsigned int     l8:4;
	unsigned int     l7:4;
	unsigned int     l6:4;
	unsigned int     l5:4;
	unsigned int     l4:4;
	unsigned int     l3:4;
	unsigned int     l2:4;
	unsigned int     l1:4;
} line_buffer_sta_RBUS;

typedef union {
	unsigned int     l8:4;
	unsigned int     l7:4;
	unsigned int     l6:4;
	unsigned int     l5:4;
	unsigned int     l4:4;
	unsigned int     l3:4;
	unsigned int     l2:4;
	unsigned int     l1:4;
} line_buffer_size_RBUS;

typedef union {
	unsigned int     reserved_0:1;
	unsigned int     bundle_osd1_osd2:1;
	unsigned int     bundle_osd3_osd4:1;
	unsigned int     bundle_osd4_osd5:1;
	unsigned int     reserved_1:2;
	unsigned int     bundle_osdsr1_osdsr2:1;
	unsigned int     bundle_osdsrbypass4_osdsrbypass5:1;
	unsigned int     reserved_2:5;
	unsigned int     osdsr5_switch_to:3;
	unsigned int     reserved_3:1;
	unsigned int     osdsr4_switch_to:3;
	unsigned int     reserved_4:1;
	unsigned int     osdsr3_switch_to:3;
	unsigned int     reserved_5:1;
	unsigned int     osdsr2_switch_to:3;
	unsigned int     reserved_6:1;
	unsigned int     osdsr1_switch_to:3;
} line_buffer_end_RBUS;

typedef union {
	unsigned int     osd1_fbdc1_en:1;
	unsigned int     osd1_fbdc2_en:1;
	unsigned int     osd1_fbdc3_en:1;
	unsigned int     osd2_fbdc1_en:1;
	unsigned int     osd2_fbdc2_en:1;
	unsigned int     osd2_fbdc3_en:1;
	unsigned int     osd3_fbdc1_en:1;
	unsigned int     osd3_fbdc2_en:1;
	unsigned int     osd3_fbdc3_en:1;
	unsigned int     reserved_0:1;
	unsigned int     write_back_status:2;
	unsigned int     offline_blend_status:2;
	unsigned int     middle_blend_status:2;
	unsigned int     reserved_1:4;
	unsigned int     osd6_status:2;
	unsigned int     osd5_status:2;
	unsigned int     osd4_status:2;
	unsigned int     osd3_status:2;
	unsigned int     osd2_status:2;
	unsigned int     osd1_status:2;
} osd_status_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     pre_blend_c2:1;
	unsigned int     pre_blend_c1:1;
	unsigned int     pre_blend_c0:1;
	unsigned int     reserved_1:1;
	unsigned int     fbdc_over_6_picture:1;
	unsigned int     osdsr5:1;
	unsigned int     osdsr4:1;
	unsigned int     osdsr3:1;
	unsigned int     osdsr2:1;
	unsigned int     osdsr1:1;
	unsigned int     reserved_2:9;
	unsigned int     off_blend_c3:1;
	unsigned int     off_blend_c2:1;
	unsigned int     off_blend_c1:1;
	unsigned int     off_blend_c0:1;
	unsigned int     mid_blend_c3:1;
	unsigned int     mid_blend_c2:1;
	unsigned int     mid_blend_c1:1;
	unsigned int     mid_blend_c0:1;
} blend_setting_conflict_RBUS;

typedef union {
	unsigned int     reserved_0:29;
	unsigned int     sel:3;
} vbi_to_se_RBUS;

typedef union {
	unsigned int     reserved_0:22;
	unsigned int     d3_mode:1;
	unsigned int     rotate:1;
	unsigned int     reserved_1:4;
	unsigned int     reserved_2:2;
	unsigned int     osd1_en:1;
	unsigned int     write_data:1;
} osd1_ctrl_RBUS;

typedef union {
	unsigned int     reserved_0:6;
	unsigned int     wi_endian:1;
	unsigned int     rgb_out:1;
	unsigned int     reserved_1:7;
	unsigned int     osd:1;
	unsigned int     reserved_2:14;
	unsigned int     clear_region_en:1;
	unsigned int     write_data:1;
} osd1_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     th:13;
} osd1_start_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     th:13;
} osd1_vbi_end_RBUS;

typedef union {
	unsigned int     addr:32;
} osd1_wi_RBUS;

typedef union {
	unsigned int     addr:32;
} osd1_wi_3d_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     w:13;
	unsigned int     reserved_1:3;
	unsigned int     h:13;
} osd1_size_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m01:14;
	unsigned int     reserved_1:2;
	unsigned int     m00:14;
} osd1_cc1_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m10:14;
	unsigned int     reserved_1:2;
	unsigned int     m02:14;
} osd1_cc2_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m12:14;
	unsigned int     reserved_1:2;
	unsigned int     m11:14;
} osd1_cc3_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m21:14;
	unsigned int     reserved_1:2;
	unsigned int     m20:14;
} osd1_cc4_RBUS;

typedef union {
	unsigned int     reserved_0:18;
	unsigned int     m22:14;
} osd1_cc5_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     a2:9;
	unsigned int     a1:9;
	unsigned int     a0:9;
} osd1_cc6_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     b2:9;
	unsigned int     b1:9;
	unsigned int     b0:9;
} osd1_cc7_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     x_sta:13;
	unsigned int     reserved_1:3;
	unsigned int     x_end:13;
} osd1_clear1_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     y_sta:13;
	unsigned int     reserved_1:3;
	unsigned int     y_end:13;
} osd1_clear2_RBUS;

typedef union {
	unsigned int     reserved_0:22;
	unsigned int     d3_mode:1;
	unsigned int     rotate:1;
	unsigned int     reserved_1:4;
	unsigned int     reserved_2:2;
	unsigned int     osd2_en:1;
	unsigned int     write_data:1;
} osd2_ctrl_RBUS;

typedef union {
	unsigned int     reserved_0:6;
	unsigned int     wi_endian:1;
	unsigned int     rgb_out:1;
	unsigned int     reserved_1:7;
	unsigned int     osd:1;
	unsigned int     reserved_2:14;
	unsigned int     clear_region_en:1;
	unsigned int     write_data:1;
} osd2_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     th:13;
} osd2_start_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     th:13;
} osd2_vbi_end_RBUS;

typedef union {
	unsigned int     addr:32;
} osd2_wi_RBUS;

typedef union {
	unsigned int     addr:32;
} osd2_wi_3d_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     w:13;
	unsigned int     reserved_1:3;
	unsigned int     h:13;
} osd2_size_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m01:14;
	unsigned int     reserved_1:2;
	unsigned int     m00:14;
} osd2_cc1_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m10:14;
	unsigned int     reserved_1:2;
	unsigned int     m02:14;
} osd2_cc2_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m12:14;
	unsigned int     reserved_1:2;
	unsigned int     m11:14;
} osd2_cc3_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m21:14;
	unsigned int     reserved_1:2;
	unsigned int     m20:14;
} osd2_cc4_RBUS;

typedef union {
	unsigned int     reserved_0:18;
	unsigned int     m22:14;
} osd2_cc5_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     a2:9;
	unsigned int     a1:9;
	unsigned int     a0:9;
} osd2_cc6_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     b2:9;
	unsigned int     b1:9;
	unsigned int     b0:9;
} osd2_cc7_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     x_sta:13;
	unsigned int     reserved_1:3;
	unsigned int     x_end:13;
} osd2_clear1_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     y_sta:13;
	unsigned int     reserved_1:3;
	unsigned int     y_end:13;
} osd2_clear2_RBUS;

typedef union {
	unsigned int     reserved_0:22;
	unsigned int     d3_mode:1;
	unsigned int     rotate:1;
	unsigned int     reserved_1:4;
	unsigned int     reserved_2:2;
	unsigned int     osd3_en:1;
	unsigned int     write_data:1;
} osd3_ctrl_RBUS;

typedef union {
	unsigned int     reserved_0:6;
	unsigned int     wi_endian:1;
	unsigned int     rgb_out:1;
	unsigned int     reserved_1:7;
	unsigned int     osd:1;
	unsigned int     reserved_2:14;
	unsigned int     clear_region_en:1;
	unsigned int     write_data:1;
} osd3_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     th:13;
} osd3_start_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     th:13;
} osd3_vbi_end_RBUS;

typedef union {
	unsigned int     addr:32;
} osd3_wi_RBUS;

typedef union {
	unsigned int     addr:32;
} osd3_wi_3d;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     w:13;
	unsigned int     reserved_1:3;
	unsigned int     h:13;
} osd3_size_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m01:14;
	unsigned int     reserved_1:2;
	unsigned int     m00:14;
} osd3_cc1_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m10:14;
	unsigned int     reserved_1:2;
	unsigned int     m02:14;
} osd3_cc2_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m12:14;
	unsigned int     reserved_1:2;
	unsigned int     m11:14;
} osd3_cc3_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m21:14;
	unsigned int     reserved_1:2;
	unsigned int     m20:14;
} osd3_cc4_RBUS;

typedef union {
	unsigned int     reserved_0:18;
	unsigned int     m22:14;
} osd3_cc5_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     a2:9;
	unsigned int     a1:9;
	unsigned int     a0:9;
} osd3_cc6_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     b2:9;
	unsigned int     b1:9;
	unsigned int     b0:9;
} osd3_cc7_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     x_sta:13;
	unsigned int     reserved_1:3;
	unsigned int     x_end:13;
} osd3_clear1_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     y_sta:13;
	unsigned int     reserved_1:3;
	unsigned int     y_end:13;
} osd3_clear2_RBUS;

typedef union {
	unsigned int     reserved_0:22;
	unsigned int     d3_mode:1;
	unsigned int     rotate:1;
	unsigned int     reserved_1:4;
	unsigned int     reserved_2:2;
	unsigned int     osd4_en:1;
	unsigned int     write_data:1;
} osd4_ctrl_RBUS;

typedef union {
	unsigned int     reserved_0:6;
	unsigned int     wi_endian:1;
	unsigned int     rgb_out:1;
	unsigned int     reserved_1:7;
	unsigned int     osd:1;
	unsigned int     reserved_2:14;
	unsigned int     clear_region_en:1;
	unsigned int     write_data:1;
} osd4_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     th:13;
} osd4_start_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     th:13;
} osd4_vbi_end_RBUS;

typedef union {
	unsigned int     addr:32;
} osd4_wi_RBUS;

typedef union {
	unsigned int     addr:32;
} osd4_wi_3d_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     w:13;
	unsigned int     reserved_1:3;
	unsigned int     h:13;
} osd4_size_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m01:14;
	unsigned int     reserved_1:2;
	unsigned int     m00:14;
} osd4_cc1_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m10:14;
	unsigned int     reserved_1:2;
	unsigned int     m02:14;
} osd4_cc2_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m12:14;
	unsigned int     reserved_1:2;
	unsigned int     m11:14;
} osd4_cc3_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m21:14;
	unsigned int     reserved_1:2;
	unsigned int     m20:14;
} osd4_cc4_RBUS;

typedef union {
	unsigned int     reserved_0:18;
	unsigned int     m22:14;
} osd4_cc5_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     a2:9;
	unsigned int     a1:9;
	unsigned int     a0:9;
} osd4_cc6_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     b2:9;
	unsigned int     b1:9;
	unsigned int     b0:9;
} osd4_cc7_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     x_sta:13;
	unsigned int     reserved_1:3;
	unsigned int     x_end:13;
} osd4_clear1_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     y_sta:13;
	unsigned int     reserved_1:3;
	unsigned int     y_end:13;
} osd4_clear2_RBUS;

typedef union {
	unsigned int     reserved_0:22;
	unsigned int     d3_mode:1;
	unsigned int     rotate:1;
	unsigned int     reserved_1:4;
	unsigned int     reserved_2:2;
	unsigned int     osd5_en:1;
	unsigned int     write_data:1;
} osd5_ctrl_RBUS;

typedef union {
	unsigned int     reserved_0:6;
	unsigned int     wi_endian:1;
	unsigned int     rgb_out:1;
	unsigned int     reserved_1:7;
	unsigned int     osd:1;
	unsigned int     reserved_2:14;
	unsigned int     clear_region_en:1;
	unsigned int     write_data:1;
} osd5_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     th:13;
} osd5_start_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     th:13;
} osd5_vbi_end_RBUS;

typedef union {
	unsigned int     addr:32;
} osd5_wi_RBUS;

typedef union {
	unsigned int     addr:32;
} osd5_wi_3d_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     w:13;
	unsigned int     reserved_1:3;
	unsigned int     h:13;
} osd5_size_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m01:14;
	unsigned int     reserved_1:2;
	unsigned int     m00:14;
} osd5_cc1_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m10:14;
	unsigned int     reserved_1:2;
	unsigned int     m02:14;
} osd5_cc2_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m12:14;
	unsigned int     reserved_1:2;
	unsigned int     m11:14;
} osd5_cc3_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     m21:14;
	unsigned int     reserved_1:2;
	unsigned int     m20:14;
} osd5_cc4_RBUS;

typedef union {
	unsigned int     reserved_0:18;
	unsigned int     m22:14;
} osd5_cc5_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     a2:9;
	unsigned int     a1:9;
	unsigned int     a0:9;
} osd5_cc6_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     b2:9;
	unsigned int     b1:9;
	unsigned int     b0:9;
} osd5_cc7_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     x_sta:13;
	unsigned int     reserved_1:3;
	unsigned int     x_end:13;
} osd5_clear1_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     y_sta:13;
	unsigned int     reserved_1:3;
	unsigned int     y_end:13;
} osd5_clear2_RBUS;

typedef union {
	unsigned int     reserved_0:6;
	unsigned int     decmp_segment:2;
	unsigned int     decmp_width:8;
	unsigned int     decmp_height:16;
} decmp1_resolution_RBUS;

typedef union {
	unsigned int     reserved_0:14;
	unsigned int     a_sat_en:1;
	unsigned int     b_cb_sat_en:1;
	unsigned int     g_y_sat_en:1;
	unsigned int     r_cr_sat_en:1;
	unsigned int     decmp_frame_bits:6;
	unsigned int     reserved_1:2;
	unsigned int     decmp_a_ch_mark:1;
	unsigned int     decmp_444to422_en:1;
	unsigned int     decmp_rgb_yc_sel:1;
	unsigned int     decmp_channel_bits:1;
	unsigned int     decmp_cbcr_recov:1;
	unsigned int     decmp_fl_mode:1;
} decmp1_setting_RBUS;

typedef union {
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
} decmp1_trunc_mark_RBUS;

typedef union {
	unsigned int     mark_color_0:16;
	unsigned int     mark_color_1:16;
} decmp1_trunc_color_0_RBUS;

typedef union {
	unsigned int     mark_color_2:16;
	unsigned int     mark_color_3:16;
} decmp1_trunc_color_1_RBUS;

typedef union {
	unsigned int     mark_color_4:16;
	unsigned int     mark_color_5:16;
} decmp1_trunc_color_2_RBUS;

typedef union {
	unsigned int     mark_color_6:16;
	unsigned int     mark_color_7:16;
} decmp1_trunc_color_3_RBUS;

typedef union {
	unsigned int     mark_color_8:16;
	unsigned int     mark_color_9:16;
} decmp1_trunc_color_4_RBUS;

typedef union {
	unsigned int     reserved_0:6;
	unsigned int     decmp_segment:2;
	unsigned int     decmp_width:8;
	unsigned int     decmp_height:16;
} decmp2_resolution_RBUS;

typedef union {
	unsigned int     reserved_0:14;
	unsigned int     a_sat_en:1;
	unsigned int     b_cb_sat_en:1;
	unsigned int     g_y_sat_en:1;
	unsigned int     r_cr_sat_en:1;
	unsigned int     decmp_frame_bits:6;
	unsigned int     reserved_1:2;
	unsigned int     decmp_a_ch_mark:1;
	unsigned int     decmp_444to422_en:1;
	unsigned int     decmp_rgb_yc_sel:1;
	unsigned int     decmp_channel_bits:1;
	unsigned int     decmp_cbcr_recov:1;
	unsigned int     decmp_fl_mode:1;
} decmp2_setting_RBUS;

typedef union {
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
} decmp2_trunc_mark_RBUS;

typedef union {
	unsigned int     mark_color_0:16;
	unsigned int     mark_color_1:16;
} decmp2_trunc_color_0_RBUS;

typedef union {
	unsigned int     mark_color_2:16;
	unsigned int     mark_color_3:16;
} decmp2_trunc_color_1_RBUS;

typedef union {
	unsigned int     mark_color_4:16;
	unsigned int     mark_color_5:16;
} decmp2_trunc_color_2_RBUS;

typedef union {
	unsigned int     mark_color_6:16;
	unsigned int     mark_color_7:16;
} decmp2_trunc_color_3_RBUS;

typedef union {
	unsigned int     mark_color_8:16;
	unsigned int     mark_color_9:16;
} decmp2_trunc_color_4_RBUS;

typedef union {
	unsigned int     reserved_0:4;
	unsigned int     reserved_1:4;
	unsigned int     frm_cnt_2:4;
	unsigned int     frm_cnt_1:4;
	unsigned int     reserved_2:4;
	unsigned int     reserved_3:4;
	unsigned int     max_truncation_2:4;
	unsigned int     max_truncation_1:4;
} frame_inst_RBUS;

typedef union {
	unsigned int     reserved_0:22;
	unsigned int     head_error_clr:1;
	unsigned int     pix_fifo_underflow_clr:1;
	unsigned int     reserved_1:2;
	unsigned int     head_error_irq_en2:1;
	unsigned int     head_error_irq_en1:1;
	unsigned int     reserved_2:2;
	unsigned int     underflow_irq_en2:1;
	unsigned int     underflow_irq_en1:1;
} decomp_inten_RBUS;

typedef union {
	unsigned int     reserved_0:23;
	unsigned int     decomp_irq:1;
	unsigned int     reserved_1:2;
	unsigned int     head_error2:1;
	unsigned int     head_error1:1;
	unsigned int     reserved_2:2;
	unsigned int     pix_fifo_underflow2:1;
	unsigned int     pix_fifo_underflow1:1;
} decomp_intst_RBUS;

typedef union {
	unsigned int     reserved_0:14;
	unsigned int     sel:2;
	unsigned int     mux:8;
	unsigned int     reserved_1:8;
} decomp_debug_RBUS;

typedef union {
	unsigned int     reserved_0:30;
	unsigned int     conti:1;
	unsigned int     start:1;
} decomp1_crc_RBUS;

typedef union {
	unsigned int     result:32;
} decomp1_crc_result_RBUS;

typedef union {
	unsigned int     reserved_0:30;
	unsigned int     conti:1;
	unsigned int     start:1;
} decomp2_crc_RBUS;

typedef union {
	unsigned int     result:32;
} decomp2_crc_result_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     fbdc3_prio_end:4;
	unsigned int     fbdc3_prio_beg:4;
	unsigned int     fbdc2_prio_end:4;
	unsigned int     fbdc2_prio_beg:4;
	unsigned int     fbdc1_prio_end:4;
	unsigned int     fbdc1_prio_beg:4;
} fbdc_osd1_en_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     fbdc3_prio_end:4;
	unsigned int     fbdc3_prio_beg:4;
	unsigned int     fbdc2_prio_end:4;
	unsigned int     fbdc2_prio_beg:4;
	unsigned int     fbdc1_prio_end:4;
	unsigned int     fbdc1_prio_beg:4;
} fbdc_osd2_en_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     fbdc3_prio_end:4;
	unsigned int     fbdc3_prio_beg:4;
	unsigned int     fbdc2_prio_end:4;
	unsigned int     fbdc2_prio_beg:4;
	unsigned int     fbdc1_prio_end:4;
	unsigned int     fbdc1_prio_beg:4;
} fbdc_osd3_en_RBUS;

typedef union {
	unsigned int     dummy:16;
	unsigned int     reserved_0:11;
	unsigned int     fmt16_swap_1b:1;
	unsigned int     reserved_1:2;
	unsigned int     head_to_data_align:2;
} fbdc_RBUS;

typedef union {
	unsigned int     reserved_0:30;
	unsigned int     data_timing_error:1;
	unsigned int     head_timing_error:1;
} fbdc_core_RBUS;

typedef union {
	unsigned int     reserved_0:5;
	unsigned int     dtreq_tl_type:1;
	unsigned int     rgx_cr_clkgatestatus_req_clks:1;
	unsigned int     rgx_cr_clkgatestatus_fbdc_clks:1;
	unsigned int     reserved_1:1;
	unsigned int     dtreq_st:1;
	unsigned int     dtreq_mem_mode:1;
	unsigned int     dtreq_fmsk:5;
	unsigned int     rgx_cr_fb_cdc_fbdc_compatibility:16;
} fbdc_tie_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     decmp1:12;
	unsigned int     reserved_1:12;
} dma_wl1_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     num:24;
} decmp1_seg0_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     num:24;
} decmp1_seg0_3d_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     decmp2:12;
	unsigned int     reserved_1:12;
} dma_wl2_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     num:24;
} decmp2_seg0_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     num:24;
} decmp2_seg0_3d_RBUS;

typedef union {
	unsigned int     pitch:16;
	unsigned int     pitch_3d:16;
} write_back_RBUS;

typedef union {
	unsigned int     reserved_0:1;
	unsigned int     fbdc2_bl:7;
	unsigned int     reserved_1:1;
	unsigned int     fbdc1_bl:7;
	unsigned int     reserved_2:1;
	unsigned int     osd5_bl:7;
	unsigned int     reserved_3:1;
	unsigned int     osd4_bl:7;
} dma_bl_1_RBUS;

typedef union {
	unsigned int     reserved_0:1;
	unsigned int     osd3_bl:7;
	unsigned int     reserved_1:1;
	unsigned int     osd2_bl:7;
	unsigned int     reserved_2:1;
	unsigned int     osd1_bl:7;
	unsigned int     reserved_3:1;
	unsigned int     wdma_bl:7;
} dma_bl_2_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     fbdc2_mask:1;
	unsigned int     fbdc1_mask:1;
	unsigned int     osd5_mask:1;
	unsigned int     osd4_mask:1;
	unsigned int     osd3_mask:1;
	unsigned int     osd2_mask:1;
	unsigned int     osd1_mask:1;
	unsigned int     wdma_mask:1;
	unsigned int     fbdc2_req_num:2;
	unsigned int     fbdc1_req_num:2;
	unsigned int     osd5_req_num:2;
	unsigned int     osd4_req_num:2;
	unsigned int     osd3_req_num:2;
	unsigned int     osd2_req_num:2;
	unsigned int     osd1_req_num:2;
	unsigned int     wdma_req_num:2;
} dma_RBUS;

typedef union {
	unsigned int     fbdc2_1b:1;
	unsigned int     fbdc2_2b:1;
	unsigned int     fbdc2_4b:1;
	unsigned int     fbdc2_8b:1;
	unsigned int     fbdc1_1b:1;
	unsigned int     fbdc1_2b:1;
	unsigned int     fbdc1_4b:1;
	unsigned int     fbdc1_8b:1;
	unsigned int     osd5_1b:1;
	unsigned int     osd5_2b:1;
	unsigned int     osd5_4b:1;
	unsigned int     osd5_8b:1;
	unsigned int     osd4_1b:1;
	unsigned int     osd4_2b:1;
	unsigned int     osd4_4b:1;
	unsigned int     osd4_8b:1;
	unsigned int     osd3_1b:1;
	unsigned int     osd3_2b:1;
	unsigned int     osd3_4b:1;
	unsigned int     osd3_8b:1;
	unsigned int     osd2_1b:1;
	unsigned int     osd2_2b:1;
	unsigned int     osd2_4b:1;
	unsigned int     osd2_8b:1;
	unsigned int     osd1_1b:1;
	unsigned int     osd1_2b:1;
	unsigned int     osd1_4b:1;
	unsigned int     osd1_8b:1;
	unsigned int     wdma_1b:1;
	unsigned int     wdma_2b:1;
	unsigned int     wdma_4b:1;
	unsigned int     wdma_8b:1;
} dma_swap_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd1_wi_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd1_d0_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd1_d1_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd2_wi_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd2_d0_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd2_d1_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd3_wi_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd3_d0_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd3_d1_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd4_wi_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd4_d0_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd4_d1_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd5_wi_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd5_d0_RBUS;

typedef union {
	unsigned int     reserved_0:8;
	unsigned int     depth:12;
	unsigned int     sa:12;
} dma_osd5_d1_RBUS;

typedef union {
	unsigned int     addr:32;
} wdma_adr_seg0_RBUS;

typedef union {
	unsigned int     addr:32;
} wdma_adr_seg0_3d_RBUS;

typedef union {
	unsigned int     size:32;
} wdma_seg0_RBUS;

typedef union {
	unsigned int     size:32;
} wdma_seg0_3d_RBUS;

typedef union {
	unsigned int     reserved_0:30;
	unsigned int     conti:1;
	unsigned int     start:1;
} wdma_crc_RBUS;

typedef union {
	unsigned int     result:32;
} wdma_seg0_crc_RBUS;

typedef union {
	unsigned int     reserved_0:31;
	unsigned int     m422_cb_cr_swap:1;
} m422_swap_RBUS;

typedef union {
	unsigned int     result:32;
} wdma_seg1_crc_RBUS;


typedef union {
	unsigned int     mid_blend_en:1;
	unsigned int     reserved_0:11;
	unsigned int     c3_plane_alpha_en:1;
	unsigned int     c2_plane_alpha_en:1;
	unsigned int     c1_plane_alpha_en:1;
	unsigned int     c0_plane_alpha_en:1;
	unsigned int     reserved_1:1;
	unsigned int     c3_sel:3;
	unsigned int     reserved_2:1;
	unsigned int     c2_sel:3;
	unsigned int     reserved_3:1;
	unsigned int     c1_sel:3;
	unsigned int     reserved_4:1;
	unsigned int     c0_sel:3;
} mid_blend_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     w:13;
	unsigned int     reserved_1:3;
	unsigned int     h:13;
} mid_blend_size_RBUS;

typedef union {
	unsigned int     plane_alpha_a:8;
	unsigned int     plane_alpha_r:8;
	unsigned int     plane_alpha_g:8;
	unsigned int     plane_alpha_b:8;
} mid_blend_c0_RBUS;

typedef union {
	unsigned int     plane_alpha_a:8;
	unsigned int     plane_alpha_r:8;
	unsigned int     plane_alpha_g:8;
	unsigned int     plane_alpha_b:8;
} mid_blend_c1_RBUS;

typedef union {
	unsigned int     plane_alpha_a:8;
	unsigned int     plane_alpha_r:8;
	unsigned int     plane_alpha_g:8;
	unsigned int     plane_alpha_b:8;
} mid_blend_c2_RBUS;

typedef union {
	unsigned int     plane_alpha_a:8;
	unsigned int     plane_alpha_r:8;
	unsigned int     plane_alpha_g:8;
	unsigned int     plane_alpha_b:8;
} mid_blend_c3_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     x:13;
	unsigned int     reserved_1:3;
	unsigned int     y:13;
} mid_blend_osd1_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     x:13;
	unsigned int     reserved_1:3;
	unsigned int     y:13;
} mid_blend_osd2_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     x:13;
	unsigned int     reserved_1:3;
	unsigned int     y:13;
} mid_blend_osd3_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     x:13;
	unsigned int     reserved_1:3;
	unsigned int     y:13;
} mid_blend_osd4_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     x:13;
	unsigned int     reserved_1:3;
	unsigned int     y:13;
} mid_blend_osd5_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     k1:6;
	unsigned int     reserved_1:2;
	unsigned int     k2:6;
	unsigned int     reserved_2:2;
	unsigned int     k3:6;
	unsigned int     reserved_3:2;
	unsigned int     k4:6;
} mid_blend_b1_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     k1:6;
	unsigned int     reserved_1:2;
	unsigned int     k2:6;
	unsigned int     reserved_2:2;
	unsigned int     k3:6;
	unsigned int     reserved_3:2;
	unsigned int     k4:6;
} mid_blend_b2_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     k1:6;
	unsigned int     reserved_1:2;
	unsigned int     k2:6;
	unsigned int     reserved_2:2;
	unsigned int     k3:6;
	unsigned int     reserved_3:2;
	unsigned int     k4:6;
} mid_blend_b3_RBUS;

typedef union {
	unsigned int     offline_blend_en:1;
	unsigned int     reserved_0:11;
	unsigned int     c3_plane_alpha_en:1;
	unsigned int     c2_plane_alpha_en:1;
	unsigned int     c1_plane_alpha_en:1;
	unsigned int     c0_plane_alpha_en:1;
	unsigned int     reserved_1:1;
	unsigned int     c3_sel:3;
	unsigned int     reserved_2:1;
	unsigned int     c2_sel:3;
	unsigned int     reserved_3:1;
	unsigned int     c1_sel:3;
	unsigned int     reserved_4:1;
	unsigned int     c0_sel:3;
} offline_blend_RBUS;

typedef union {
	unsigned int     reserved_0:3;
	unsigned int     w:13;
	unsigned int     reserved_1:3;
	unsigned int     h:13;
} off_blend_size_RBUS;

typedef union {
	unsigned int     plane_alpha_a:8;
	unsigned int     plane_alpha_r:8;
	unsigned int     plane_alpha_g:8;
	unsigned int     plane_alpha_b:8;
} offline_blend_c0_RBUS;

typedef union {
	unsigned int     plane_alpha_a:8;
	unsigned int     plane_alpha_r:8;
	unsigned int     plane_alpha_g:8;
	unsigned int     plane_alpha_b:8;
} offline_blend_c1_RBUS;

typedef union {
	unsigned int     plane_alpha_a:8;
	unsigned int     plane_alpha_r:8;
	unsigned int     plane_alpha_g:8;
	unsigned int     plane_alpha_b:8;
} offline_blend_c2_RBUS;

typedef union {
	unsigned int     plane_alpha_a:8;
	unsigned int     plane_alpha_r:8;
	unsigned int     plane_alpha_g:8;
	unsigned int     plane_alpha_b:8;
} offline_blend_c3_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     k1:6;
	unsigned int     reserved_1:2;
	unsigned int     k2:6;
	unsigned int     reserved_2:2;
	unsigned int     k3:6;
	unsigned int     reserved_3:2;
	unsigned int     k4:6;
} offline_blend_b1_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     k1:6;
	unsigned int     reserved_1:2;
	unsigned int     k2:6;
	unsigned int     reserved_2:2;
	unsigned int     k3:6;
	unsigned int     reserved_3:2;
	unsigned int     k4:6;
} offline_blend_b2_RBUS;

typedef union {
	unsigned int     reserved_0:2;
	unsigned int     k1:6;
	unsigned int     reserved_1:2;
	unsigned int     k2:6;
	unsigned int     reserved_2:2;
	unsigned int     k3:6;
	unsigned int     reserved_3:2;
	unsigned int     k4:6;
} offline_blend_b3_RBUS;

typedef union {
	unsigned int     reserved_0:29;
	unsigned int     write_back_format:2;
	unsigned int     write_back_en:1;
} write_back_en_RBUS;

typedef union {
	unsigned int     reserved_0:6;
	unsigned int     reserved_1:2;
	unsigned int     cmp_width:8;
	unsigned int     cmp_height:16;
} cmp_resolution_RBUS;

typedef union {
	unsigned int     cmp_a_ch_mark:1;
	unsigned int     cmp_444to422_en:1;
	unsigned int     cmp_rgb_yc_sel:1;
	unsigned int     cmp_channel_bits:1;
	unsigned int     reserved_0:10;
	unsigned int     max_pixel_bits:6;
	unsigned int     short_term_bits:6;
	unsigned int     frame_bits:6;
} cmp_setting_RBUS;

typedef union {
	unsigned int     reserved_0:26;
	unsigned int     not_segment_status_clr:1;
	unsigned int     pixel_num_status_clr:1;
	unsigned int     over_bits_status_clr:1;
	unsigned int     comp_irq_en:3;
} comp_inten_RBUS;

typedef union {
	unsigned int     reserved_0:28;
	unsigned int     comp_irq:1;
	unsigned int     comp_status:3;
} comp_intst_RBUS;

typedef union {
	unsigned int     reserved_0:14;
	unsigned int     height_cnt:18;
} wb_debug_RBUS;

typedef union {
	unsigned int     reserved_0:7;
	unsigned int     wdma_done:1;
	unsigned int     reserved_1:1;
	unsigned int     osd6_fin:1;
	unsigned int     osd5_fin:1;
	unsigned int     osd4_fin:1;
	unsigned int     osd3_fin:1;
	unsigned int     osd2_fin:1;
	unsigned int     osd1_fin:1;
	unsigned int     reserved_2:2;
	unsigned int     osd6_vact_end:1;
	unsigned int     osd5_vact_end:1;
	unsigned int     osd4_vact_end:1;
	unsigned int     osd3_vact_end:1;
	unsigned int     osd2_vact_end:1;
	unsigned int     osd1_vact_end:1;
	unsigned int     reserved_3:2;
	unsigned int     osd6_vsync:1;
	unsigned int     osd5_vsync:1;
	unsigned int     osd4_vsync:1;
	unsigned int     osd3_vsync:1;
	unsigned int     osd2_vsync:1;
	unsigned int     osd1_vsync:1;
	unsigned int     write_data:1;
} osd_inten_RBUS;

typedef union {
	unsigned int     reserved_0:7;
	unsigned int     wdma_done:1;
	unsigned int     reserved_1:1;
	unsigned int     osd6_fin:1;
	unsigned int     osd5_fin:1;
	unsigned int     osd4_fin:1;
	unsigned int     osd3_fin:1;
	unsigned int     osd2_fin:1;
	unsigned int     osd1_fin:1;
	unsigned int     reserved_2:2;
	unsigned int     osd6_vact_end:1;
	unsigned int     osd5_vact_end:1;
	unsigned int     osd4_vact_end:1;
	unsigned int     osd3_vact_end:1;
	unsigned int     osd2_vact_end:1;
	unsigned int     osd1_vact_end:1;
	unsigned int     reserved_3:2;
	unsigned int     osd6_vsync:1;
	unsigned int     osd5_vsync:1;
	unsigned int     osd4_vsync:1;
	unsigned int     osd3_vsync:1;
	unsigned int     osd2_vsync:1;
	unsigned int     osd1_vsync:1;
	unsigned int     write_data:1;
} osd_intst_RBUS;

typedef union {
	unsigned int     reserved_0:7;
	unsigned int     wdma_done:1;
	unsigned int     reserved_1:1;
	unsigned int     osd6_fin:1;
	unsigned int     osd5_fin:1;
	unsigned int     osd4_fin:1;
	unsigned int     osd3_fin:1;
	unsigned int     osd2_fin:1;
	unsigned int     osd1_fin:1;
	unsigned int     reserved_2:2;
	unsigned int     osd6_vact_end:1;
	unsigned int     osd5_vact_end:1;
	unsigned int     osd4_vact_end:1;
	unsigned int     osd3_vact_end:1;
	unsigned int     osd2_vact_end:1;
	unsigned int     osd1_vact_end:1;
	unsigned int     reserved_3:2;
	unsigned int     osd6_vsync:1;
	unsigned int     osd5_vsync:1;
	unsigned int     osd4_vsync:1;
	unsigned int     osd3_vsync:1;
	unsigned int     osd2_vsync:1;
	unsigned int     osd1_vsync:1;
	unsigned int     write_data:1;
} osd_inten_3d_RBUS;

typedef union {
	unsigned int     reserved_0:7;
	unsigned int     wdma_done:1;
	unsigned int     reserved_1:1;
	unsigned int     osd6_fin:1;
	unsigned int     osd5_fin:1;
	unsigned int     osd4_fin:1;
	unsigned int     osd3_fin:1;
	unsigned int     osd2_fin:1;
	unsigned int     osd1_fin:1;
	unsigned int     reserved_2:2;
	unsigned int     osd6_vact_end:1;
	unsigned int     osd5_vact_end:1;
	unsigned int     osd4_vact_end:1;
	unsigned int     osd3_vact_end:1;
	unsigned int     osd2_vact_end:1;
	unsigned int     osd1_vact_end:1;
	unsigned int     reserved_3:2;
	unsigned int     osd6_vsync:1;
	unsigned int     osd5_vsync:1;
	unsigned int     osd4_vsync:1;
	unsigned int     osd3_vsync:1;
	unsigned int     osd2_vsync:1;
	unsigned int     osd1_vsync:1;
	unsigned int     write_data:1;
} osd_intst_3d_RBUS;

typedef union {
	unsigned int     reserved_0:10;
	unsigned int     fbdc_second_acc_sync:1;
	unsigned int     fbdc_first_acc_sync:1;
	unsigned int     reserved_1:1;
	unsigned int     wdma_acc_sync:1;
	unsigned int     wdma_ovfl:1;
	unsigned int     wdma_udfl:1;
	unsigned int     reserved_2:1;
	unsigned int     osd6_acc_sync:1;
	unsigned int     osd5_acc_sync:1;
	unsigned int     osd4_acc_sync:1;
	unsigned int     osd3_acc_sync:1;
	unsigned int     osd2_acc_sync:1;
	unsigned int     osd1_acc_sync:1;
	unsigned int     reserved_3:2;
	unsigned int     osd6_udfl:1;
	unsigned int     osd5_udfl:1;
	unsigned int     osd4_udfl:1;
	unsigned int     osd3_udfl:1;
	unsigned int     osd2_udfl:1;
	unsigned int     osd1_udfl:1;
	unsigned int     write_data:1;
} dma_inten_RBUS;

typedef union {
	unsigned int     reserved_0:10;
	unsigned int     fbdc_second_acc_sync:1;
	unsigned int     fbdc_first_acc_sync:1;
	unsigned int     reserved_1:1;
	unsigned int     wdma_acc_sync:1;
	unsigned int     wdma_ovfl:1;
	unsigned int     wdma_udfl:1;
	unsigned int     reserved_2:1;
	unsigned int     osd6_acc_sync:1;
	unsigned int     osd5_acc_sync:1;
	unsigned int     osd4_acc_sync:1;
	unsigned int     osd3_acc_sync:1;
	unsigned int     osd2_acc_sync:1;
	unsigned int     osd1_acc_sync:1;
	unsigned int     reserved_3:2;
	unsigned int     osd6_udfl:1;
	unsigned int     osd5_udfl:1;
	unsigned int     osd4_udfl:1;
	unsigned int     osd3_udfl:1;
	unsigned int     osd2_udfl:1;
	unsigned int     osd1_udfl:1;
	unsigned int     write_data:1;
} dma_intst_RBUS;

typedef union {
	unsigned int     reserved_0:14;
	unsigned int     wdma_ovfl:1;
	unsigned int     wdma_udfl:1;
	unsigned int     reserved_1:1;
	unsigned int     osd6_acc_sync:1;
	unsigned int     osd5_acc_sync:1;
	unsigned int     osd4_acc_sync:1;
	unsigned int     osd3_acc_sync:1;
	unsigned int     osd2_acc_sync:1;
	unsigned int     osd1_acc_sync:1;
	unsigned int     reserved_2:2;
	unsigned int     osd6_udfl:1;
	unsigned int     osd5_udfl:1;
	unsigned int     osd4_udfl:1;
	unsigned int     osd3_udfl:1;
	unsigned int     osd2_udfl:1;
	unsigned int     osd1_udfl:1;
	unsigned int     write_data:1;
} dma_inten_3d_RBUS;

typedef union {
	unsigned int     reserved_0:14;
	unsigned int     wdma_ovfl:1;
	unsigned int     wdma_udfl:1;
	unsigned int     reserved_1:1;
	unsigned int     osd6_acc_sync:1;
	unsigned int     osd5_acc_sync:1;
	unsigned int     osd4_acc_sync:1;
	unsigned int     osd3_acc_sync:1;
	unsigned int     osd2_acc_sync:1;
	unsigned int     osd1_acc_sync:1;
	unsigned int     reserved_2:2;
	unsigned int     osd6_udfl:1;
	unsigned int     osd5_udfl:1;
	unsigned int     osd4_udfl:1;
	unsigned int     osd3_udfl:1;
	unsigned int     osd2_udfl:1;
	unsigned int     osd1_udfl:1;
	unsigned int     write_data:1;
} dma_intst_3d_RBUS;

typedef union {
	unsigned int     reserved_0:7;
	unsigned int     test_rwm:1;
	unsigned int     reserved_1:4;
	unsigned int     fbdc_dma_ls:1;
	unsigned int     fbdc_data_ls:1;
	unsigned int     fbdc_header_ls:1;
	unsigned int     fbdc_ls:1;
	unsigned int     reserved_2:11;
	unsigned int     rme:1;
	unsigned int     rm:4;
} mbist_RBUS;

typedef union {
	unsigned int     reserved_0:1;
	unsigned int     dispbuf:6;
	unsigned int     dma_buf:5;
	unsigned int     osd5_clut:2;
	unsigned int     osd4_clut:2;
	unsigned int     osd3_clut:2;
	unsigned int     osd2_clut:2;
	unsigned int     osd1_clut:2;
	unsigned int     rbuf:10;
} mbist_fail_RBUS;

typedef union {
	unsigned int     reserved_0:1;
	unsigned int     dispbuf:6;
	unsigned int     dma_buf:5;
	unsigned int     osd5_clut:2;
	unsigned int     osd4_clut:2;
	unsigned int     osd3_clut:2;
	unsigned int     osd2_clut:2;
	unsigned int     osd1_clut:2;
	unsigned int     rbuf:10;
} mbist_drf_fail_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     fbdc_dma:4;
	unsigned int     fbdc_data1:2;
	unsigned int     fbdc_data0:2;
	unsigned int     fbdc_header:1;
	unsigned int     wdma:1;
	unsigned int     comp:1;
	unsigned int     decomp2:1;
	unsigned int     decomp1:1;
} mbist_fail2_RBUS;

typedef union {
	unsigned int     reserved_0:19;
	unsigned int     fbdc_dma:4;
	unsigned int     fbdc_data1:2;
	unsigned int     fbdc_data0:2;
	unsigned int     fbdc_header:1;
	unsigned int     wdma:1;
	unsigned int     comp:1;
	unsigned int     decomp2:1;
	unsigned int     decomp1:1;
} mbist_drf_fail2_RBUS;

typedef union {
	unsigned int     reserved_0:4;
	unsigned int     fbdc_003:7;
	unsigned int     fbdc_002:7;
	unsigned int     fbdc_001:7;
	unsigned int     fbdc_000:7;
} mbisr_fail_RBUS;

typedef union {
	unsigned int     reserved_0:4;
	unsigned int     fbdc_003:7;
	unsigned int     fbdc_002:7;
	unsigned int     fbdc_001:7;
	unsigned int     fbdc_000:7;
} mbisr_drf_fail_RBUS;

typedef union {
	unsigned int     reserved_0:28;
	unsigned int     fbdc_003:1;
	unsigned int     fbdc_002:1;
	unsigned int     fbdc_001:1;
	unsigned int     fbdc_000:1;
} mbisr_repaired_RBUS;

typedef union {
	unsigned int     reserved_0:6;
	unsigned int     write_en3:1;
	unsigned int     sel1:9;
	unsigned int     reserved_1:2;
	unsigned int     write_en2:1;
	unsigned int     sel0:9;
	unsigned int     reserved_2:2;
	unsigned int     write_en1:1;
	unsigned int     en:1;
} dbg_RBUS;

typedef union {
	unsigned int     reserved_0:29;
	unsigned int     sel:3;
} dbg_wi_info_RBUS;

typedef union {
	unsigned int     height:16;
	unsigned int     width:16;
} dbg_osd_wi_0_RBUS;

typedef union {
	unsigned int     extension_mode:1;
	unsigned int     rgb_order:3;
	unsigned int     alpha_replace_type:1;
	unsigned int     const_alpha_enable:1;
	unsigned int     reserved_0:1;
	unsigned int     object_type:1;
	unsigned int     alpha:8;
	unsigned int     reserved_1:5;
	unsigned int     clut_format:1;
	unsigned int     endian:1;
	unsigned int     keep_prev_clut:1;
	unsigned int     compress:1;
	unsigned int     img_compress:1;
	unsigned int     reserved_2:1;
	unsigned int     colortype:5;
} dbg_osd_wi_1_RBUS;

typedef union {
	unsigned int     top_addr:32;
} dbg_osd_wi_2_RBUS;

typedef union {
	unsigned int     bot_addr:32;
} dbg_osd_wi_3_RBUS;

typedef union {
	unsigned int     pitch_or_third_addr:32;
} dbg_osd_wi_4_RBUS;

typedef union {
	unsigned int     dbg_win_28:32;
} dbg_osd_wi_5_RBUS;

typedef union {
	unsigned int     dbg_win_2c:32;
} dbg_osd_wi_6_RBUS;

typedef union {
	unsigned int     dbg_win_30:32;
} dbg_osd_wi_7_RBUS;

typedef union {
	unsigned int     dbg_win_34:32;
} dbg_osd_wi_8_RBUS;

typedef union {
	unsigned int     dbg_win_38:32;
} dbg_osd_wi_9_RBUS;

typedef union {
	unsigned int     dbg_win_3c:32;
} dbg_osd_wi_a_RBUS;

typedef union {
	unsigned int     dbg_win_40:32;
} dbg_osd_wi_b_RBUS;

typedef union {
	unsigned int     dbg_win_44:32;
} dbg_osd_wi_c_RBUS;

typedef union {
	unsigned int     dbg_win_48:32;
} dbg_osd_wi_d_RBUS;

typedef union {
	unsigned int     dbg_win_4c:32;
} dbg_osd_wi_e_RBUS;

typedef union {
	unsigned int     dbg_win_50:32;
} dbg_osd_wi_f_RBUS;

typedef union {
	unsigned int     dbg_win_54:32;
} dbg_osd_wi_10_RBUS;

typedef union {
	unsigned int     dbg_win_58:32;
} dbg_osd_wi_11_RBUS;

typedef union {
	unsigned int     dbg_win_5c:32;
} dbg_osd_wi_12_RBUS;

typedef union {
	unsigned int     dbg_win_60:32;
} dbg_osd_wi_13_RBUS;

typedef union {
	unsigned int     dbg_win_64:32;
} dbg_osd_wi_14_RBUS;

typedef union {
	unsigned int     dbg_win_68:32;
} dbg_osd_wi_15_RBUS;

typedef union {
	unsigned int     dbg_win_6c:32;
} dbg_osd_wi_16_RBUS;

typedef union {
	unsigned int     dbg_win_70:32;
} dbg_osd_wi_17_RBUS;

typedef union {
	unsigned int     dbg_win_74:32;
} dbg_osd_wi_18_RBUS;

typedef union {
	unsigned int     reserved_0:7;
	unsigned int     set_osd1_fbdc1_use_2nd_dma:1;
	unsigned int     set_osd1_fbdc2_use_2nd_dma:1;
	unsigned int     set_osd1_fbdc3_use_2nd_dma:1;
	unsigned int     set_osd2_fbdc1_use_2nd_dma:1;
	unsigned int     set_osd2_fbdc2_use_2nd_dma:1;
	unsigned int     set_osd2_fbdc3_use_2nd_dma:1;
	unsigned int     set_osd3_fbdc1_use_2nd_dma:1;
	unsigned int     set_osd3_fbdc2_use_2nd_dma:1;
	unsigned int     set_osd3_fbdc3_use_2nd_dma:1;
	unsigned int     reserved_1:2;
	unsigned int     set_osd5_online_use_offline_dma:1;
	unsigned int     set_osd4_online_use_offline_dma:1;
	unsigned int     set_osd3_online_use_offline_dma:1;
	unsigned int     set_osd2_online_use_offline_dma:1;
	unsigned int     set_osd1_online_use_offline_dma:1;
	unsigned int     reserved_2:9;
} online_status_RBUS;

typedef union {
	unsigned int     dummy:32;
} gdma_dmy_RBUS;

#else   /* apply for little-Endian */

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     osd_sel:1;
		unsigned int     reserved_2:7;
		unsigned int     osd1_bypass_acc_sync_fix:1;
		unsigned int     osd2_bypass_acc_sync_fix:1;
		unsigned int     osd3_bypass_acc_sync_fix:1;
		unsigned int     osd4_bypass_acc_sync_fix:1;
		unsigned int     osd5_bypass_acc_sync_fix:1;
		unsigned int     reserved_1:2;
		unsigned int     gating_enable:1;
		unsigned int     reserved_0:15;
	};
} update_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     osd1_prog_done:1;
		unsigned int     osd2_prog_done:1;
		unsigned int     osd3_prog_done:1;
		unsigned int     osd4_prog_done:1;
		unsigned int     osd5_prog_done:1;
		unsigned int     osd_others_prog_done:1;
		unsigned int     reserved_2:1;
		unsigned int     offline_go:1;
		unsigned int     reserved_1:7;
		unsigned int     offline_software_abort:1;
		unsigned int     reserved_0:15;
	};
} ctrl_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_back_src_sel:1;
		unsigned int     set_osd1_offline:1;
		unsigned int     set_osd2_offline:1;
		unsigned int     set_osd3_offline:1;
		unsigned int     set_osd4_offline:1;
		unsigned int     set_osd5_offline:1;
		unsigned int     reserved_2:3;
		unsigned int     set_osd1_online_use_offline_dma:1;
		unsigned int     set_osd2_online_use_offline_dma:1;
		unsigned int     set_osd3_online_use_offline_dma:1;
		unsigned int     set_osd4_online_use_offline_dma:1;
		unsigned int     set_osd5_online_use_offline_dma:1;
		unsigned int     reserved_1:2;
		unsigned int     set_osd3_fbdc3_use_2nd_dma:1;
		unsigned int     set_osd3_fbdc2_use_2nd_dma:1;
		unsigned int     set_osd3_fbdc1_use_2nd_dma:1;
		unsigned int     set_osd2_fbdc3_use_2nd_dma:1;
		unsigned int     set_osd2_fbdc2_use_2nd_dma:1;
		unsigned int     set_osd2_fbdc1_use_2nd_dma:1;
		unsigned int     set_osd1_fbdc3_use_2nd_dma:1;
		unsigned int     set_osd1_fbdc2_use_2nd_dma:1;
		unsigned int     set_osd1_fbdc1_use_2nd_dma:1;
		unsigned int     reserved_0:7;
	};
} online_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     reserved_3:9;
		unsigned int     set_osd1_go_middle_blend:1;
		unsigned int     set_osd2_go_middle_blend:1;
		unsigned int     set_osd3_go_middle_blend:1;
		unsigned int     set_osd4_go_middle_blend:1;
		unsigned int     set_osd5_go_middle_blend:1;
		unsigned int     reserved_2:3;
		unsigned int     reserved_1:8;
		unsigned int     l1_config_5k:1;
		unsigned int     l2_config_5k:1;
		unsigned int     l3_config_5k:1;
		unsigned int     l4_config_5k:1;
		unsigned int     l5_config_5k:1;
		unsigned int     l6_config_5k:1;
		unsigned int     reserved_0:1;
	};
} resource_lb_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     l1:4;
		unsigned int     l2:4;
		unsigned int     l3:4;
		unsigned int     l4:4;
		unsigned int     l5:4;
		unsigned int     l6:4;
		unsigned int     l7:4;
		unsigned int     l8:4;
	};
} line_buffer_sta_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     l1:4;
		unsigned int     l2:4;
		unsigned int     l3:4;
		unsigned int     l4:4;
		unsigned int     l5:4;
		unsigned int     l6:4;
		unsigned int     l7:4;
		unsigned int     l8:4;
	};
} line_buffer_size_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int	 osdsr1_switch_to:3;
		unsigned int	 reserved_6:1;
		unsigned int	 osdsr2_switch_to:3;
		unsigned int	 reserved_5:1;
		unsigned int	 osdsr3_switch_to:3;
		unsigned int	 reserved_4:1;
		unsigned int	 osdsr4_switch_to:3;
		unsigned int	 reserved_3:1;
		unsigned int	 osdsr5_switch_to:3;
		unsigned int	 reserved_2:5;
		unsigned int	 bundle_osdsrbypass4_osdsrbypass5:1;
		unsigned int	 bundle_osdsr1_osdsr2:1;
		unsigned int	 reserved_1:2;
		unsigned int	 bundle_osd4_osd5:1;
		unsigned int	 bundle_osd3_osd4:1;
		unsigned int	 bundle_osd1_osd2:1;
		unsigned int  reserved_0:1;
	};
} line_buffer_end_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     osd1_en:1;
		unsigned int     reserved_2:2;
		unsigned int     reserved_1:4;
		unsigned int     rotate:1;
		unsigned int     d3_mode:1;
		unsigned int     reserved_0:22;
	};
} osd1_ctrl_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     clear_region_en:1;
		unsigned int     reserved_2:14;
		unsigned int     osd:1;
		unsigned int     reserved_1:7;
		unsigned int     rgb_out:1;
		unsigned int     wi_endian:1;
		unsigned int     reserved_0:6;
	};
} osd1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     addr:32;
	};
} osd1_wi_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     addr:32;
	};
} osd1_wi_3d_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     h:13;
		unsigned int     reserved_1:3;
		unsigned int     w:13;
		unsigned int     reserved_0:3;
	};
} osd1_size_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     x_end:13;
		unsigned int     reserved_1:3;
		unsigned int     x_sta:13;
		unsigned int     reserved_0:3;
	};
} osd1_clear1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     y_end:13;
		unsigned int     reserved_1:3;
		unsigned int     y_sta:13;
		unsigned int     reserved_0:3;
	};
} osd1_clear2_RBUS;


typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     osd2_en:1;
		unsigned int     reserved_2:2;
		unsigned int     reserved_1:4;
		unsigned int     rotate:1;
		unsigned int     d3_mode:1;
		unsigned int     reserved_0:22;
	};
} osd2_ctrl_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     clear_region_en:1;
		unsigned int     reserved_2:14;
		unsigned int     osd:1;
		unsigned int     reserved_1:7;
		unsigned int     rgb_out:1;
		unsigned int     wi_endian:1;
		unsigned int     reserved_0:6;
	};
} osd2_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     osd3_en:1;
		unsigned int     reserved_2:2;
		unsigned int     reserved_1:4;
		unsigned int     rotate:1;
		unsigned int     d3_mode:1;
		unsigned int     reserved_0:22;
	};
} osd3_ctrl_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     clear_region_en:1;
		unsigned int     reserved_2:14;
		unsigned int     osd:1;
		unsigned int     reserved_1:7;
		unsigned int     rgb_out:1;
		unsigned int     wi_endian:1;
		unsigned int     reserved_0:6;
	};
} osd3_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     osd4_en:1;
		unsigned int     reserved_2:2;
		unsigned int     reserved_1:4;
		unsigned int     rotate:1;
		unsigned int     d3_mode:1;
		unsigned int     reserved_0:22;
	};
} osd4_ctrl_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     clear_region_en:1;
		unsigned int     reserved_2:14;
		unsigned int     osd:1;
		unsigned int     reserved_1:7;
		unsigned int     rgb_out:1;
		unsigned int     wi_endian:1;
		unsigned int     reserved_0:6;
	};
} osd4_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     osd5_en:1;
		unsigned int     reserved_2:2;
		unsigned int     reserved_1:4;
		unsigned int     rotate:1;
		unsigned int     d3_mode:1;
		unsigned int     reserved_0:22;
	};
} osd5_ctrl_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     clear_region_en:1;
		unsigned int     reserved_2:14;
		unsigned int     osd:1;
		unsigned int     reserved_1:7;
		unsigned int     rgb_out:1;
		unsigned int     wi_endian:1;
		unsigned int     reserved_0:6;
	};
} osd5_RBUS;


typedef union {
	uint32_t regValue;
	struct {
		unsigned int     decmp_height:16;
		unsigned int     decmp_width:8;
		unsigned int     decmp_segment:2;
		unsigned int     reserved_0:6;
	};
} decmp1_resolution_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     decmp_fl_mode:1;
		unsigned int     decmp_cbcr_recov:1;
		unsigned int     decmp_channel_bits:1;
		unsigned int     decmp_rgb_yc_sel:1;
		unsigned int     decmp_444to422_en:1;
		unsigned int     decmp_a_ch_mark:1;
		unsigned int     reserved_1:2;
		unsigned int     decmp_frame_bits:6;
		unsigned int     r_cr_sat_en:1;
		unsigned int     g_y_sat_en:1;
		unsigned int     b_cb_sat_en:1;
		unsigned int     a_sat_en:1;
		unsigned int     reserved_0:14;
	};
} decmp1_setting_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     decmp_height:16;
		unsigned int     decmp_width:8;
		unsigned int     decmp_segment:2;
		unsigned int     reserved_0:6;
	};
} decmp2_resolution_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     decmp_fl_mode:1;
		unsigned int     decmp_cbcr_recov:1;
		unsigned int     decmp_channel_bits:1;
		unsigned int     decmp_rgb_yc_sel:1;
		unsigned int     decmp_444to422_en:1;
		unsigned int     decmp_a_ch_mark:1;
		unsigned int     reserved_1:2;
		unsigned int     decmp_frame_bits:6;
		unsigned int     r_cr_sat_en:1;
		unsigned int     g_y_sat_en:1;
		unsigned int     b_cb_sat_en:1;
		unsigned int     a_sat_en:1;
		unsigned int     reserved_0:14;
	};
} decmp2_setting_RBUS;


typedef union {
	uint32_t regValue;
	struct {
		unsigned int     underflow_irq_en1:1;
		unsigned int     underflow_irq_en2:1;
		unsigned int     reserved_2:2;
		unsigned int     head_error_irq_en1:1;
		unsigned int     head_error_irq_en2:1;
		unsigned int     reserved_1:2;
		unsigned int     pix_fifo_underflow_clr:1;
		unsigned int     head_error_clr:1;
		unsigned int     reserved_0:22;
	};
} decomp_inten_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     pix_fifo_underflow1:1;
		unsigned int     pix_fifo_underflow2:1;
		unsigned int     reserved_2:2;
		unsigned int     head_error1:1;
		unsigned int     head_error2:1;
		unsigned int     reserved_1:2;
		unsigned int     decomp_irq:1;
		unsigned int     reserved_0:23;
	};
} decomp_intst_RBUS;


typedef union {
	uint32_t regValue;
	struct {
		unsigned int     osd4_bl:7;
		unsigned int     reserved_3:1;
		unsigned int     osd5_bl:7;
		unsigned int     fbdc1_bl:7;
		unsigned int     reserved_1:1;
		unsigned int     fbdc2_bl:7;
		unsigned int     reserved_0:1;
		unsigned int     reserved_2:1;
	};
} dma_bl_1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     wdma_bl:7;
		unsigned int     reserved_3:1;
		unsigned int     osd1_bl:7;
		unsigned int     reserved_2:1;
		unsigned int     osd2_bl:7;
		unsigned int     reserved_1:1;
		unsigned int     osd3_bl:7;
		unsigned int     reserved_0:1;
	};
} dma_bl_2_RBUS;


typedef union {
	uint32_t regValue;
	struct {
		unsigned int     wdma_req_num:2;
		unsigned int     osd1_req_num:2;
		unsigned int     osd2_req_num:2;
		unsigned int     osd3_req_num:2;
		unsigned int     osd4_req_num:2;
		unsigned int     osd5_req_num:2;
		unsigned int     fbdc1_req_num:2;
		unsigned int     fbdc2_req_num:2;
		unsigned int     wdma_mask:1;
		unsigned int     osd1_mask:1;
		unsigned int     osd2_mask:1;
		unsigned int     osd3_mask:1;
		unsigned int     osd4_mask:1;
		unsigned int     osd5_mask:1;
		unsigned int     fbdc1_mask:1;
		unsigned int     fbdc2_mask:1;
		unsigned int     reserved_0:8;
	};
} dma_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     wdma_8b:1;
		unsigned int     wdma_4b:1;
		unsigned int     wdma_2b:1;
		unsigned int     wdma_1b:1;
		unsigned int     osd1_8b:1;
		unsigned int     osd1_4b:1;
		unsigned int     osd1_2b:1;
		unsigned int     osd1_1b:1;
		unsigned int     osd2_8b:1;
		unsigned int     osd2_4b:1;
		unsigned int     osd2_2b:1;
		unsigned int     osd2_1b:1;
		unsigned int     osd3_8b:1;
		unsigned int     osd3_4b:1;
		unsigned int     osd3_2b:1;
		unsigned int     osd3_1b:1;
		unsigned int     osd4_8b:1;
		unsigned int     osd4_4b:1;
		unsigned int     osd4_2b:1;
		unsigned int     osd4_1b:1;
		unsigned int     osd5_8b:1;
		unsigned int     osd5_4b:1;
		unsigned int     osd5_2b:1;
		unsigned int     osd5_1b:1;
		unsigned int     fbdc1_8b:1;
		unsigned int     fbdc1_4b:1;
		unsigned int     fbdc1_2b:1;
		unsigned int     fbdc1_1b:1;
		unsigned int     fbdc2_8b:1;
		unsigned int     fbdc2_4b:1;
		unsigned int     fbdc2_2b:1;
		unsigned int     fbdc2_1b:1;
	};
} dma_swap_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd1_wi_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd1_d0_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd1_d1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd2_wi_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd2_d0_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd2_d1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd3_wi_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd3_d0_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd3_d1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd4_wi_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd4_d0_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd4_d1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd5_wi_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd5_d0_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     sa:12;
		unsigned int     depth:12;
		unsigned int     reserved_0:8;
	};
} dma_osd5_d1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     addr:32;
	};
} wdma_adr_seg0_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     addr:32;
	};
} wdma_adr_seg0_3d_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     size:32;
	};
} wdma_seg0_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     size:32;
	};
} wdma_seg0_3d_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     start:1;
		unsigned int     conti:1;
		unsigned int     reserved_0:30;
	};
} wdma_crc_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     result:32;
	};
} wdma_seg0_crc_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     m422_cb_cr_swap:1;
		unsigned int     reserved_0:31;
	};
} m422_swap_RBUS;


typedef union {
	uint32_t regValue;
	struct {
		unsigned int     c0_sel:3;
		unsigned int     reserved_4:1;
		unsigned int     c1_sel:3;
		unsigned int     reserved_3:1;
		unsigned int     c2_sel:3;
		unsigned int     reserved_2:1;
		unsigned int     c3_sel:3;
		unsigned int     reserved_1:1;
		unsigned int     c0_plane_alpha_en:1;
		unsigned int     c1_plane_alpha_en:1;
		unsigned int     c2_plane_alpha_en:1;
		unsigned int     c3_plane_alpha_en:1;
		unsigned int     reserved_0:11;
		unsigned int     mid_blend_en:1;
	};
} mid_blend_RBUS;


typedef union {
	uint32_t regValue;
	struct {
		unsigned int     h:13;
		unsigned int     reserved_1:3;
		unsigned int     w:13;
		unsigned int     reserved_0:3;
	};
} mid_blend_size_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     plane_alpha_b:8;
		unsigned int     plane_alpha_g:8;
		unsigned int     plane_alpha_r:8;
		unsigned int     plane_alpha_a:8;
	};
} mid_blend_c0_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     plane_alpha_b:8;
		unsigned int     plane_alpha_g:8;
		unsigned int     plane_alpha_r:8;
		unsigned int     plane_alpha_a:8;
	};
} mid_blend_c1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     plane_alpha_b:8;
		unsigned int     plane_alpha_g:8;
		unsigned int     plane_alpha_r:8;
		unsigned int     plane_alpha_a:8;
	};
} mid_blend_c2_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     plane_alpha_b:8;
		unsigned int     plane_alpha_g:8;
		unsigned int     plane_alpha_r:8;
		unsigned int     plane_alpha_a:8;
	};
} mid_blend_c3_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     y:13;
		unsigned int     reserved_1:3;
		unsigned int     x:13;
		unsigned int     reserved_0:3;
	};
} mid_blend_osd1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     y:13;
		unsigned int     reserved_1:3;
		unsigned int     x:13;
		unsigned int     reserved_0:3;
	};
} mid_blend_osd2_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     y:13;
		unsigned int     reserved_1:3;
		unsigned int     x:13;
		unsigned int     reserved_0:3;
	};
} mid_blend_osd3_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     y:13;
		unsigned int     reserved_1:3;
		unsigned int     x:13;
		unsigned int     reserved_0:3;
	};
} mid_blend_osd4_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     y:13;
		unsigned int     reserved_1:3;
		unsigned int     x:13;
		unsigned int     reserved_0:3;
	};
} mid_blend_osd5_RBUS;


typedef union {
	uint32_t regValue;
	struct {
		unsigned int     c0_sel:3;
		unsigned int     reserved_4:1;
		unsigned int     c1_sel:3;
		unsigned int     reserved_3:1;
		unsigned int     c2_sel:3;
		unsigned int     reserved_2:1;
		unsigned int     c3_sel:3;
		unsigned int     reserved_1:1;
		unsigned int     c0_plane_alpha_en:1;
		unsigned int     c1_plane_alpha_en:1;
		unsigned int     c2_plane_alpha_en:1;
		unsigned int     c3_plane_alpha_en:1;
		unsigned int     reserved_0:11;
		unsigned int     offline_blend_en:1;
	};
} offline_blend_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     h:13;
		unsigned int     reserved_1:3;
		unsigned int     w:13;
		unsigned int     reserved_0:3;
	};
} off_blend_size_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     plane_alpha_b:8;
		unsigned int     plane_alpha_g:8;
		unsigned int     plane_alpha_r:8;
		unsigned int     plane_alpha_a:8;
	};
} offline_blend_c0_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     plane_alpha_b:8;
		unsigned int     plane_alpha_g:8;
		unsigned int     plane_alpha_r:8;
		unsigned int     plane_alpha_a:8;
	};
} offline_blend_c1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     plane_alpha_b:8;
		unsigned int     plane_alpha_g:8;
		unsigned int     plane_alpha_r:8;
		unsigned int     plane_alpha_a:8;
	};
} offline_blend_c2_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     plane_alpha_b:8;
		unsigned int     plane_alpha_g:8;
		unsigned int     plane_alpha_r:8;
		unsigned int     plane_alpha_a:8;
	};
} offline_blend_c3_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     k4:6;
		unsigned int     reserved_3:2;
		unsigned int     k3:6;
		unsigned int     reserved_2:2;
		unsigned int     k2:6;
		unsigned int     reserved_1:2;
		unsigned int     k1:6;
		unsigned int     reserved_0:2;
	};
} offline_blend_b1_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     k4:6;
		unsigned int     reserved_3:2;
		unsigned int     k3:6;
		unsigned int     reserved_2:2;
		unsigned int     k2:6;
		unsigned int     reserved_1:2;
		unsigned int     k1:6;
		unsigned int     reserved_0:2;
	};
} offline_blend_b2_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     k4:6;
		unsigned int     reserved_3:2;
		unsigned int     k3:6;
		unsigned int     reserved_2:2;
		unsigned int     k2:6;
		unsigned int     reserved_1:2;
		unsigned int     k1:6;
		unsigned int     reserved_0:2;
	};
} offline_blend_b3_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_back_en:1;
		unsigned int     write_back_format:2;
		unsigned int     reserved_0:29;
	};
} write_back_en_RBUS;


typedef union {
	uint32_t regValue;
	struct {
		unsigned int     cmp_height:16;
		unsigned int     cmp_width:8;
		unsigned int     reserved_1:2;
		unsigned int     reserved_0:6;
	};
} cmp_resolution_RBUS;

typedef union {
	uint32_t regValue;
	struct {
		unsigned int     frame_bits:6;
		unsigned int     short_term_bits:6;
		unsigned int     max_pixel_bits:6;
		unsigned int     reserved_0:10;
		unsigned int     cmp_channel_bits:1;
		unsigned int     cmp_rgb_yc_sel:1;
		unsigned int     cmp_444to422_en:1;
		unsigned int     cmp_a_ch_mark:1;
	};
} cmp_setting_RBUS;


typedef union {
	uint32_t regValue;
	struct {
		unsigned int     write_data:1;
		unsigned int     osd1_udfl:1;
		unsigned int     osd2_udfl:1;
		unsigned int     osd3_udfl:1;
		unsigned int     osd4_udfl:1;
		unsigned int     osd5_udfl:1;
		unsigned int     osd6_udfl:1;
		unsigned int     reserved_3:2;
		unsigned int     osd1_acc_sync:1;
		unsigned int     osd2_acc_sync:1;
		unsigned int     osd3_acc_sync:1;
		unsigned int     osd4_acc_sync:1;
		unsigned int     osd5_acc_sync:1;
		unsigned int     osd6_acc_sync:1;
		unsigned int     reserved_2:1;
		unsigned int     wdma_udfl:1;
		unsigned int     wdma_ovfl:1;
		unsigned int     wdma_acc_sync:1;
		unsigned int     reserved_1:1;
		unsigned int     fbdc_first_acc_sync:1;
		unsigned int     fbdc_second_acc_sync:1;
		unsigned int     reserved_0:10;
	};
} dma_intst_RBUS;


#endif

#define GDMA_UPDATE                                                                  0x1802ff00
#define GDMA_UPDATE_reg_addr                                                         "0xB802FF00"
#define GDMA_UPDATE_reg                                                              0xB802FF00
#define set_GDMA_UPDATE_reg(data)   (*((volatile unsigned int*) GDMA_UPDATE_reg)=data)
#define get_GDMA_UPDATE_reg   (*((volatile unsigned int*) GDMA_UPDATE_reg))
#define GDMA_UPDATE_inst_adr                                                         "0x00C0"
#define GDMA_UPDATE_inst                                                             0x00C0
#define GDMA_UPDATE_gating_enable_shift                                              (16)
#define GDMA_UPDATE_gating_enable_mask                                               (0x00010000)
#define GDMA_UPDATE_gating_enable(data)                                              (0x00010000&((data)<<16))
#define GDMA_UPDATE_gating_enable_src(data)                                          ((0x00010000&(data))>>16)
#define GDMA_UPDATE_get_gating_enable(data)                                          ((0x00010000&(data))>>16)
#define GDMA_UPDATE_osd5_bypass_acc_sync_fix_shift                                   (13)
#define GDMA_UPDATE_osd5_bypass_acc_sync_fix_mask                                    (0x00002000)
#define GDMA_UPDATE_osd5_bypass_acc_sync_fix(data)                                   (0x00002000&((data)<<13))
#define GDMA_UPDATE_osd5_bypass_acc_sync_fix_src(data)                               ((0x00002000&(data))>>13)
#define GDMA_UPDATE_get_osd5_bypass_acc_sync_fix(data)                               ((0x00002000&(data))>>13)
#define GDMA_UPDATE_osd4_bypass_acc_sync_fix_shift                                   (12)
#define GDMA_UPDATE_osd4_bypass_acc_sync_fix_mask                                    (0x00001000)
#define GDMA_UPDATE_osd4_bypass_acc_sync_fix(data)                                   (0x00001000&((data)<<12))
#define GDMA_UPDATE_osd4_bypass_acc_sync_fix_src(data)                               ((0x00001000&(data))>>12)
#define GDMA_UPDATE_get_osd4_bypass_acc_sync_fix(data)                               ((0x00001000&(data))>>12)
#define GDMA_UPDATE_osd3_bypass_acc_sync_fix_shift                                   (11)
#define GDMA_UPDATE_osd3_bypass_acc_sync_fix_mask                                    (0x00000800)
#define GDMA_UPDATE_osd3_bypass_acc_sync_fix(data)                                   (0x00000800&((data)<<11))
#define GDMA_UPDATE_osd3_bypass_acc_sync_fix_src(data)                               ((0x00000800&(data))>>11)
#define GDMA_UPDATE_get_osd3_bypass_acc_sync_fix(data)                               ((0x00000800&(data))>>11)
#define GDMA_UPDATE_osd2_bypass_acc_sync_fix_shift                                   (10)
#define GDMA_UPDATE_osd2_bypass_acc_sync_fix_mask                                    (0x00000400)
#define GDMA_UPDATE_osd2_bypass_acc_sync_fix(data)                                   (0x00000400&((data)<<10))
#define GDMA_UPDATE_osd2_bypass_acc_sync_fix_src(data)                               ((0x00000400&(data))>>10)
#define GDMA_UPDATE_get_osd2_bypass_acc_sync_fix(data)                               ((0x00000400&(data))>>10)
#define GDMA_UPDATE_osd1_bypass_acc_sync_fix_shift                                   (9)
#define GDMA_UPDATE_osd1_bypass_acc_sync_fix_mask                                    (0x00000200)
#define GDMA_UPDATE_osd1_bypass_acc_sync_fix(data)                                   (0x00000200&((data)<<9))
#define GDMA_UPDATE_osd1_bypass_acc_sync_fix_src(data)                               ((0x00000200&(data))>>9)
#define GDMA_UPDATE_get_osd1_bypass_acc_sync_fix(data)                               ((0x00000200&(data))>>9)
#define GDMA_UPDATE_osd_sel_shift                                                    (1)
#define GDMA_UPDATE_osd_sel_mask                                                     (0x00000002)
#define GDMA_UPDATE_osd_sel(data)                                                    (0x00000002&((data)<<1))
#define GDMA_UPDATE_osd_sel_src(data)                                                ((0x00000002&(data))>>1)
#define GDMA_UPDATE_get_osd_sel(data)                                                ((0x00000002&(data))>>1)
#define GDMA_UPDATE_write_data_shift                                                 (0)
#define GDMA_UPDATE_write_data_mask                                                  (0x00000001)
#define GDMA_UPDATE_write_data(data)                                                 (0x00000001&((data)<<0))
#define GDMA_UPDATE_write_data_src(data)                                             ((0x00000001&(data))>>0)
#define GDMA_UPDATE_get_write_data(data)                                             ((0x00000001&(data))>>0)


#define GDMA_CTRL                                                                    0x1802ff04
#define GDMA_CTRL_reg_addr                                                           "0xB802FF04"
#define GDMA_CTRL_reg                                                                0xB802FF04
#define set_GDMA_CTRL_reg(data)   (*((volatile unsigned int*) GDMA_CTRL_reg)=data)
#define get_GDMA_CTRL_reg   (*((volatile unsigned int*) GDMA_CTRL_reg))
#define GDMA_CTRL_inst_adr                                                           "0x00C1"
#define GDMA_CTRL_inst                                                               0x00C1
#define GDMA_CTRL_offline_software_abort_shift                                       (16)
#define GDMA_CTRL_offline_software_abort_mask                                        (0x00010000)
#define GDMA_CTRL_offline_software_abort(data)                                       (0x00010000&((data)<<16))
#define GDMA_CTRL_offline_software_abort_src(data)                                   ((0x00010000&(data))>>16)
#define GDMA_CTRL_get_offline_software_abort(data)                                   ((0x00010000&(data))>>16)
#define GDMA_CTRL_offline_go_shift                                                   (8)
#define GDMA_CTRL_offline_go_mask                                                    (0x00000100)
#define GDMA_CTRL_offline_go(data)                                                   (0x00000100&((data)<<8))
#define GDMA_CTRL_offline_go_src(data)                                               ((0x00000100&(data))>>8)
#define GDMA_CTRL_get_offline_go(data)                                               ((0x00000100&(data))>>8)
#define GDMA_CTRL_osd_others_prog_done_shift                                         (6)
#define GDMA_CTRL_osd_others_prog_done_mask                                          (0x00000040)
#define GDMA_CTRL_osd_others_prog_done(data)                                         (0x00000040&((data)<<6))
#define GDMA_CTRL_osd_others_prog_done_src(data)                                     ((0x00000040&(data))>>6)
#define GDMA_CTRL_get_osd_others_prog_done(data)                                     ((0x00000040&(data))>>6)
#define GDMA_CTRL_osd5_prog_done_shift                                               (5)
#define GDMA_CTRL_osd5_prog_done_mask                                                (0x00000020)
#define GDMA_CTRL_osd5_prog_done(data)                                               (0x00000020&((data)<<5))
#define GDMA_CTRL_osd5_prog_done_src(data)                                           ((0x00000020&(data))>>5)
#define GDMA_CTRL_get_osd5_prog_done(data)                                           ((0x00000020&(data))>>5)
#define GDMA_CTRL_osd4_prog_done_shift                                               (4)
#define GDMA_CTRL_osd4_prog_done_mask                                                (0x00000010)
#define GDMA_CTRL_osd4_prog_done(data)                                               (0x00000010&((data)<<4))
#define GDMA_CTRL_osd4_prog_done_src(data)                                           ((0x00000010&(data))>>4)
#define GDMA_CTRL_get_osd4_prog_done(data)                                           ((0x00000010&(data))>>4)
#define GDMA_CTRL_osd3_prog_done_shift                                               (3)
#define GDMA_CTRL_osd3_prog_done_mask                                                (0x00000008)
#define GDMA_CTRL_osd3_prog_done(data)                                               (0x00000008&((data)<<3))
#define GDMA_CTRL_osd3_prog_done_src(data)                                           ((0x00000008&(data))>>3)
#define GDMA_CTRL_get_osd3_prog_done(data)                                           ((0x00000008&(data))>>3)
#define GDMA_CTRL_osd2_prog_done_shift                                               (2)
#define GDMA_CTRL_osd2_prog_done_mask                                                (0x00000004)
#define GDMA_CTRL_osd2_prog_done(data)                                               (0x00000004&((data)<<2))
#define GDMA_CTRL_osd2_prog_done_src(data)                                           ((0x00000004&(data))>>2)
#define GDMA_CTRL_get_osd2_prog_done(data)                                           ((0x00000004&(data))>>2)
#define GDMA_CTRL_osd1_prog_done_shift                                               (1)
#define GDMA_CTRL_osd1_prog_done_mask                                                (0x00000002)
#define GDMA_CTRL_osd1_prog_done(data)                                               (0x00000002&((data)<<1))
#define GDMA_CTRL_osd1_prog_done_src(data)                                           ((0x00000002&(data))>>1)
#define GDMA_CTRL_get_osd1_prog_done(data)                                           ((0x00000002&(data))>>1)
#define GDMA_CTRL_write_data_shift                                                   (0)
#define GDMA_CTRL_write_data_mask                                                    (0x00000001)
#define GDMA_CTRL_write_data(data)                                                   (0x00000001&((data)<<0))
#define GDMA_CTRL_write_data_src(data)                                               ((0x00000001&(data))>>0)
#define GDMA_CTRL_get_write_data(data)                                               ((0x00000001&(data))>>0)


#define GDMA_ONLINE                                                                  0x1802ff08
#define GDMA_ONLINE_reg_addr                                                         "0xB802FF08"
#define GDMA_ONLINE_reg                                                              0xB802FF08
#define set_GDMA_ONLINE_reg(data)   (*((volatile unsigned int*) GDMA_ONLINE_reg)=data)
#define get_GDMA_ONLINE_reg   (*((volatile unsigned int*) GDMA_ONLINE_reg))
#define GDMA_ONLINE_inst_adr                                                         "0x00C2"
#define GDMA_ONLINE_inst                                                             0x00C2
#define GDMA_ONLINE_Set_osd1_fbdc1_use_2nd_dma_shift                                 (24)
#define GDMA_ONLINE_Set_osd1_fbdc1_use_2nd_dma_mask                                  (0x01000000)
#define GDMA_ONLINE_Set_osd1_fbdc1_use_2nd_dma(data)                                 (0x01000000&((data)<<24))
#define GDMA_ONLINE_Set_osd1_fbdc1_use_2nd_dma_src(data)                             ((0x01000000&(data))>>24)
#define GDMA_ONLINE_get_Set_osd1_fbdc1_use_2nd_dma(data)                             ((0x01000000&(data))>>24)
#define GDMA_ONLINE_Set_osd1_fbdc2_use_2nd_dma_shift                                 (23)
#define GDMA_ONLINE_Set_osd1_fbdc2_use_2nd_dma_mask                                  (0x00800000)
#define GDMA_ONLINE_Set_osd1_fbdc2_use_2nd_dma(data)                                 (0x00800000&((data)<<23))
#define GDMA_ONLINE_Set_osd1_fbdc2_use_2nd_dma_src(data)                             ((0x00800000&(data))>>23)
#define GDMA_ONLINE_get_Set_osd1_fbdc2_use_2nd_dma(data)                             ((0x00800000&(data))>>23)
#define GDMA_ONLINE_Set_osd1_fbdc3_use_2nd_dma_shift                                 (22)
#define GDMA_ONLINE_Set_osd1_fbdc3_use_2nd_dma_mask                                  (0x00400000)
#define GDMA_ONLINE_Set_osd1_fbdc3_use_2nd_dma(data)                                 (0x00400000&((data)<<22))
#define GDMA_ONLINE_Set_osd1_fbdc3_use_2nd_dma_src(data)                             ((0x00400000&(data))>>22)
#define GDMA_ONLINE_get_Set_osd1_fbdc3_use_2nd_dma(data)                             ((0x00400000&(data))>>22)
#define GDMA_ONLINE_Set_osd2_fbdc1_use_2nd_dma_shift                                 (21)
#define GDMA_ONLINE_Set_osd2_fbdc1_use_2nd_dma_mask                                  (0x00200000)
#define GDMA_ONLINE_Set_osd2_fbdc1_use_2nd_dma(data)                                 (0x00200000&((data)<<21))
#define GDMA_ONLINE_Set_osd2_fbdc1_use_2nd_dma_src(data)                             ((0x00200000&(data))>>21)
#define GDMA_ONLINE_get_Set_osd2_fbdc1_use_2nd_dma(data)                             ((0x00200000&(data))>>21)
#define GDMA_ONLINE_Set_osd2_fbdc2_use_2nd_dma_shift                                 (20)
#define GDMA_ONLINE_Set_osd2_fbdc2_use_2nd_dma_mask                                  (0x00100000)
#define GDMA_ONLINE_Set_osd2_fbdc2_use_2nd_dma(data)                                 (0x00100000&((data)<<20))
#define GDMA_ONLINE_Set_osd2_fbdc2_use_2nd_dma_src(data)                             ((0x00100000&(data))>>20)
#define GDMA_ONLINE_get_Set_osd2_fbdc2_use_2nd_dma(data)                             ((0x00100000&(data))>>20)
#define GDMA_ONLINE_Set_osd2_fbdc3_use_2nd_dma_shift                                 (19)
#define GDMA_ONLINE_Set_osd2_fbdc3_use_2nd_dma_mask                                  (0x00080000)
#define GDMA_ONLINE_Set_osd2_fbdc3_use_2nd_dma(data)                                 (0x00080000&((data)<<19))
#define GDMA_ONLINE_Set_osd2_fbdc3_use_2nd_dma_src(data)                             ((0x00080000&(data))>>19)
#define GDMA_ONLINE_get_Set_osd2_fbdc3_use_2nd_dma(data)                             ((0x00080000&(data))>>19)
#define GDMA_ONLINE_Set_osd3_fbdc1_use_2nd_dma_shift                                 (18)
#define GDMA_ONLINE_Set_osd3_fbdc1_use_2nd_dma_mask                                  (0x00040000)
#define GDMA_ONLINE_Set_osd3_fbdc1_use_2nd_dma(data)                                 (0x00040000&((data)<<18))
#define GDMA_ONLINE_Set_osd3_fbdc1_use_2nd_dma_src(data)                             ((0x00040000&(data))>>18)
#define GDMA_ONLINE_get_Set_osd3_fbdc1_use_2nd_dma(data)                             ((0x00040000&(data))>>18)
#define GDMA_ONLINE_Set_osd3_fbdc2_use_2nd_dma_shift                                 (17)
#define GDMA_ONLINE_Set_osd3_fbdc2_use_2nd_dma_mask                                  (0x00020000)
#define GDMA_ONLINE_Set_osd3_fbdc2_use_2nd_dma(data)                                 (0x00020000&((data)<<17))
#define GDMA_ONLINE_Set_osd3_fbdc2_use_2nd_dma_src(data)                             ((0x00020000&(data))>>17)
#define GDMA_ONLINE_get_Set_osd3_fbdc2_use_2nd_dma(data)                             ((0x00020000&(data))>>17)
#define GDMA_ONLINE_Set_osd3_fbdc3_use_2nd_dma_shift                                 (16)
#define GDMA_ONLINE_Set_osd3_fbdc3_use_2nd_dma_mask                                  (0x00010000)
#define GDMA_ONLINE_Set_osd3_fbdc3_use_2nd_dma(data)                                 (0x00010000&((data)<<16))
#define GDMA_ONLINE_Set_osd3_fbdc3_use_2nd_dma_src(data)                             ((0x00010000&(data))>>16)
#define GDMA_ONLINE_get_Set_osd3_fbdc3_use_2nd_dma(data)                             ((0x00010000&(data))>>16)
#define GDMA_ONLINE_set_osd5_online_use_offline_dma_shift                            (13)
#define GDMA_ONLINE_set_osd5_online_use_offline_dma_mask                             (0x00002000)
#define GDMA_ONLINE_set_osd5_online_use_offline_dma(data)                            (0x00002000&((data)<<13))
#define GDMA_ONLINE_set_osd5_online_use_offline_dma_src(data)                        ((0x00002000&(data))>>13)
#define GDMA_ONLINE_get_set_osd5_online_use_offline_dma(data)                        ((0x00002000&(data))>>13)
#define GDMA_ONLINE_set_osd4_online_use_offline_dma_shift                            (12)
#define GDMA_ONLINE_set_osd4_online_use_offline_dma_mask                             (0x00001000)
#define GDMA_ONLINE_set_osd4_online_use_offline_dma(data)                            (0x00001000&((data)<<12))
#define GDMA_ONLINE_set_osd4_online_use_offline_dma_src(data)                        ((0x00001000&(data))>>12)
#define GDMA_ONLINE_get_set_osd4_online_use_offline_dma(data)                        ((0x00001000&(data))>>12)
#define GDMA_ONLINE_set_osd3_online_use_offline_dma_shift                            (11)
#define GDMA_ONLINE_set_osd3_online_use_offline_dma_mask                             (0x00000800)
#define GDMA_ONLINE_set_osd3_online_use_offline_dma(data)                            (0x00000800&((data)<<11))
#define GDMA_ONLINE_set_osd3_online_use_offline_dma_src(data)                        ((0x00000800&(data))>>11)
#define GDMA_ONLINE_get_set_osd3_online_use_offline_dma(data)                        ((0x00000800&(data))>>11)
#define GDMA_ONLINE_set_osd2_online_use_offline_dma_shift                            (10)
#define GDMA_ONLINE_set_osd2_online_use_offline_dma_mask                             (0x00000400)
#define GDMA_ONLINE_set_osd2_online_use_offline_dma(data)                            (0x00000400&((data)<<10))
#define GDMA_ONLINE_set_osd2_online_use_offline_dma_src(data)                        ((0x00000400&(data))>>10)
#define GDMA_ONLINE_get_set_osd2_online_use_offline_dma(data)                        ((0x00000400&(data))>>10)
#define GDMA_ONLINE_set_osd1_online_use_offline_dma_shift                            (9)
#define GDMA_ONLINE_set_osd1_online_use_offline_dma_mask                             (0x00000200)
#define GDMA_ONLINE_set_osd1_online_use_offline_dma(data)                            (0x00000200&((data)<<9))
#define GDMA_ONLINE_set_osd1_online_use_offline_dma_src(data)                        ((0x00000200&(data))>>9)
#define GDMA_ONLINE_get_set_osd1_online_use_offline_dma(data)                        ((0x00000200&(data))>>9)
#define GDMA_ONLINE_set_osd5_offline_shift                                           (5)
#define GDMA_ONLINE_set_osd5_offline_mask                                            (0x00000020)
#define GDMA_ONLINE_set_osd5_offline(data)                                           (0x00000020&((data)<<5))
#define GDMA_ONLINE_set_osd5_offline_src(data)                                       ((0x00000020&(data))>>5)
#define GDMA_ONLINE_get_set_osd5_offline(data)                                       ((0x00000020&(data))>>5)
#define GDMA_ONLINE_set_osd4_offline_shift                                           (4)
#define GDMA_ONLINE_set_osd4_offline_mask                                            (0x00000010)
#define GDMA_ONLINE_set_osd4_offline(data)                                           (0x00000010&((data)<<4))
#define GDMA_ONLINE_set_osd4_offline_src(data)                                       ((0x00000010&(data))>>4)
#define GDMA_ONLINE_get_set_osd4_offline(data)                                       ((0x00000010&(data))>>4)
#define GDMA_ONLINE_set_osd3_offline_shift                                           (3)
#define GDMA_ONLINE_set_osd3_offline_mask                                            (0x00000008)
#define GDMA_ONLINE_set_osd3_offline(data)                                           (0x00000008&((data)<<3))
#define GDMA_ONLINE_set_osd3_offline_src(data)                                       ((0x00000008&(data))>>3)
#define GDMA_ONLINE_get_set_osd3_offline(data)                                       ((0x00000008&(data))>>3)
#define GDMA_ONLINE_set_osd2_offline_shift                                           (2)
#define GDMA_ONLINE_set_osd2_offline_mask                                            (0x00000004)
#define GDMA_ONLINE_set_osd2_offline(data)                                           (0x00000004&((data)<<2))
#define GDMA_ONLINE_set_osd2_offline_src(data)                                       ((0x00000004&(data))>>2)
#define GDMA_ONLINE_get_set_osd2_offline(data)                                       ((0x00000004&(data))>>2)
#define GDMA_ONLINE_set_osd1_offline_shift                                           (1)
#define GDMA_ONLINE_set_osd1_offline_mask                                            (0x00000002)
#define GDMA_ONLINE_set_osd1_offline(data)                                           (0x00000002&((data)<<1))
#define GDMA_ONLINE_set_osd1_offline_src(data)                                       ((0x00000002&(data))>>1)
#define GDMA_ONLINE_get_set_osd1_offline(data)                                       ((0x00000002&(data))>>1)
#define GDMA_ONLINE_write_back_src_sel_shift                                         (0)
#define GDMA_ONLINE_write_back_src_sel_mask                                          (0x00000001)
#define GDMA_ONLINE_write_back_src_sel(data)                                         (0x00000001&((data)<<0))
#define GDMA_ONLINE_write_back_src_sel_src(data)                                     ((0x00000001&(data))>>0)
#define GDMA_ONLINE_get_write_back_src_sel(data)                                     ((0x00000001&(data))>>0)


#define GDMA_RESOURCE_LB                                                             0x1802ff0c
#define GDMA_RESOURCE_LB_reg_addr                                                    "0xB802FF0C"
#define GDMA_RESOURCE_LB_reg                                                         0xB802FF0C
#define set_GDMA_RESOURCE_LB_reg(data)   (*((volatile unsigned int*) GDMA_RESOURCE_LB_reg)=data)
#define get_GDMA_RESOURCE_LB_reg   (*((volatile unsigned int*) GDMA_RESOURCE_LB_reg))
#define GDMA_RESOURCE_LB_inst_adr                                                    "0x00C3"
#define GDMA_RESOURCE_LB_inst                                                        0x00C3
#define GDMA_RESOURCE_LB_L6_config_5k_shift                                          (30)
#define GDMA_RESOURCE_LB_L6_config_5k_mask                                           (0x40000000)
#define GDMA_RESOURCE_LB_L6_config_5k(data)                                          (0x40000000&((data)<<30))
#define GDMA_RESOURCE_LB_L6_config_5k_src(data)                                      ((0x40000000&(data))>>30)
#define GDMA_RESOURCE_LB_get_L6_config_5k(data)                                      ((0x40000000&(data))>>30)
#define GDMA_RESOURCE_LB_L5_config_5k_shift                                          (29)
#define GDMA_RESOURCE_LB_L5_config_5k_mask                                           (0x20000000)
#define GDMA_RESOURCE_LB_L5_config_5k(data)                                          (0x20000000&((data)<<29))
#define GDMA_RESOURCE_LB_L5_config_5k_src(data)                                      ((0x20000000&(data))>>29)
#define GDMA_RESOURCE_LB_get_L5_config_5k(data)                                      ((0x20000000&(data))>>29)
#define GDMA_RESOURCE_LB_L4_config_5k_shift                                          (28)
#define GDMA_RESOURCE_LB_L4_config_5k_mask                                           (0x10000000)
#define GDMA_RESOURCE_LB_L4_config_5k(data)                                          (0x10000000&((data)<<28))
#define GDMA_RESOURCE_LB_L4_config_5k_src(data)                                      ((0x10000000&(data))>>28)
#define GDMA_RESOURCE_LB_get_L4_config_5k(data)                                      ((0x10000000&(data))>>28)
#define GDMA_RESOURCE_LB_L3_config_5k_shift                                          (27)
#define GDMA_RESOURCE_LB_L3_config_5k_mask                                           (0x08000000)
#define GDMA_RESOURCE_LB_L3_config_5k(data)                                          (0x08000000&((data)<<27))
#define GDMA_RESOURCE_LB_L3_config_5k_src(data)                                      ((0x08000000&(data))>>27)
#define GDMA_RESOURCE_LB_get_L3_config_5k(data)                                      ((0x08000000&(data))>>27)
#define GDMA_RESOURCE_LB_L2_config_5k_shift                                          (26)
#define GDMA_RESOURCE_LB_L2_config_5k_mask                                           (0x04000000)
#define GDMA_RESOURCE_LB_L2_config_5k(data)                                          (0x04000000&((data)<<26))
#define GDMA_RESOURCE_LB_L2_config_5k_src(data)                                      ((0x04000000&(data))>>26)
#define GDMA_RESOURCE_LB_get_L2_config_5k(data)                                      ((0x04000000&(data))>>26)
#define GDMA_RESOURCE_LB_L1_config_5k_shift                                          (25)
#define GDMA_RESOURCE_LB_L1_config_5k_mask                                           (0x02000000)
#define GDMA_RESOURCE_LB_L1_config_5k(data)                                          (0x02000000&((data)<<25))
#define GDMA_RESOURCE_LB_L1_config_5k_src(data)                                      ((0x02000000&(data))>>25)
#define GDMA_RESOURCE_LB_get_L1_config_5k(data)                                      ((0x02000000&(data))>>25)
#define GDMA_RESOURCE_LB_set_osd5_go_middle_blend_shift                              (13)
#define GDMA_RESOURCE_LB_set_osd5_go_middle_blend_mask                               (0x00002000)
#define GDMA_RESOURCE_LB_set_osd5_go_middle_blend(data)                              (0x00002000&((data)<<13))
#define GDMA_RESOURCE_LB_set_osd5_go_middle_blend_src(data)                          ((0x00002000&(data))>>13)
#define GDMA_RESOURCE_LB_get_set_osd5_go_middle_blend(data)                          ((0x00002000&(data))>>13)
#define GDMA_RESOURCE_LB_set_osd4_go_middle_blend_shift                              (12)
#define GDMA_RESOURCE_LB_set_osd4_go_middle_blend_mask                               (0x00001000)
#define GDMA_RESOURCE_LB_set_osd4_go_middle_blend(data)                              (0x00001000&((data)<<12))
#define GDMA_RESOURCE_LB_set_osd4_go_middle_blend_src(data)                          ((0x00001000&(data))>>12)
#define GDMA_RESOURCE_LB_get_set_osd4_go_middle_blend(data)                          ((0x00001000&(data))>>12)
#define GDMA_RESOURCE_LB_set_osd3_go_middle_blend_shift                              (11)
#define GDMA_RESOURCE_LB_set_osd3_go_middle_blend_mask                               (0x00000800)
#define GDMA_RESOURCE_LB_set_osd3_go_middle_blend(data)                              (0x00000800&((data)<<11))
#define GDMA_RESOURCE_LB_set_osd3_go_middle_blend_src(data)                          ((0x00000800&(data))>>11)
#define GDMA_RESOURCE_LB_get_set_osd3_go_middle_blend(data)                          ((0x00000800&(data))>>11)
#define GDMA_RESOURCE_LB_set_osd2_go_middle_blend_shift                              (10)
#define GDMA_RESOURCE_LB_set_osd2_go_middle_blend_mask                               (0x00000400)
#define GDMA_RESOURCE_LB_set_osd2_go_middle_blend(data)                              (0x00000400&((data)<<10))
#define GDMA_RESOURCE_LB_set_osd2_go_middle_blend_src(data)                          ((0x00000400&(data))>>10)
#define GDMA_RESOURCE_LB_get_set_osd2_go_middle_blend(data)                          ((0x00000400&(data))>>10)
#define GDMA_RESOURCE_LB_set_osd1_go_middle_blend_shift                              (9)
#define GDMA_RESOURCE_LB_set_osd1_go_middle_blend_mask                               (0x00000200)
#define GDMA_RESOURCE_LB_set_osd1_go_middle_blend(data)                              (0x00000200&((data)<<9))
#define GDMA_RESOURCE_LB_set_osd1_go_middle_blend_src(data)                          ((0x00000200&(data))>>9)
#define GDMA_RESOURCE_LB_get_set_osd1_go_middle_blend(data)                          ((0x00000200&(data))>>9)


#define GDMA_LINE_BUFFER_STA                                                         0x1802ff10
#define GDMA_LINE_BUFFER_STA_reg_addr                                                "0xB802FF10"
#define GDMA_LINE_BUFFER_STA_reg                                                     0xB802FF10
#define set_GDMA_LINE_BUFFER_STA_reg(data)   (*((volatile unsigned int*) GDMA_LINE_BUFFER_STA_reg)=data)
#define get_GDMA_LINE_BUFFER_STA_reg   (*((volatile unsigned int*) GDMA_LINE_BUFFER_STA_reg))
#define GDMA_LINE_BUFFER_STA_inst_adr                                                "0x00C4"
#define GDMA_LINE_BUFFER_STA_inst                                                    0x00C4
#define GDMA_LINE_BUFFER_STA_L8_shift                                                (28)
#define GDMA_LINE_BUFFER_STA_L8_mask                                                 (0xF0000000)
#define GDMA_LINE_BUFFER_STA_L8(data)                                                (0xF0000000&((data)<<28))
#define GDMA_LINE_BUFFER_STA_L8_src(data)                                            ((0xF0000000&(data))>>28)
#define GDMA_LINE_BUFFER_STA_get_L8(data)                                            ((0xF0000000&(data))>>28)
#define GDMA_LINE_BUFFER_STA_L7_shift                                                (24)
#define GDMA_LINE_BUFFER_STA_L7_mask                                                 (0x0F000000)
#define GDMA_LINE_BUFFER_STA_L7(data)                                                (0x0F000000&((data)<<24))
#define GDMA_LINE_BUFFER_STA_L7_src(data)                                            ((0x0F000000&(data))>>24)
#define GDMA_LINE_BUFFER_STA_get_L7(data)                                            ((0x0F000000&(data))>>24)
#define GDMA_LINE_BUFFER_STA_L6_shift                                                (20)
#define GDMA_LINE_BUFFER_STA_L6_mask                                                 (0x00F00000)
#define GDMA_LINE_BUFFER_STA_L6(data)                                                (0x00F00000&((data)<<20))
#define GDMA_LINE_BUFFER_STA_L6_src(data)                                            ((0x00F00000&(data))>>20)
#define GDMA_LINE_BUFFER_STA_get_L6(data)                                            ((0x00F00000&(data))>>20)
#define GDMA_LINE_BUFFER_STA_L5_shift                                                (16)
#define GDMA_LINE_BUFFER_STA_L5_mask                                                 (0x000F0000)
#define GDMA_LINE_BUFFER_STA_L5(data)                                                (0x000F0000&((data)<<16))
#define GDMA_LINE_BUFFER_STA_L5_src(data)                                            ((0x000F0000&(data))>>16)
#define GDMA_LINE_BUFFER_STA_get_L5(data)                                            ((0x000F0000&(data))>>16)
#define GDMA_LINE_BUFFER_STA_L4_shift                                                (12)
#define GDMA_LINE_BUFFER_STA_L4_mask                                                 (0x0000F000)
#define GDMA_LINE_BUFFER_STA_L4(data)                                                (0x0000F000&((data)<<12))
#define GDMA_LINE_BUFFER_STA_L4_src(data)                                            ((0x0000F000&(data))>>12)
#define GDMA_LINE_BUFFER_STA_get_L4(data)                                            ((0x0000F000&(data))>>12)
#define GDMA_LINE_BUFFER_STA_L3_shift                                                (8)
#define GDMA_LINE_BUFFER_STA_L3_mask                                                 (0x00000F00)
#define GDMA_LINE_BUFFER_STA_L3(data)                                                (0x00000F00&((data)<<8))
#define GDMA_LINE_BUFFER_STA_L3_src(data)                                            ((0x00000F00&(data))>>8)
#define GDMA_LINE_BUFFER_STA_get_L3(data)                                            ((0x00000F00&(data))>>8)
#define GDMA_LINE_BUFFER_STA_L2_shift                                                (4)
#define GDMA_LINE_BUFFER_STA_L2_mask                                                 (0x000000F0)
#define GDMA_LINE_BUFFER_STA_L2(data)                                                (0x000000F0&((data)<<4))
#define GDMA_LINE_BUFFER_STA_L2_src(data)                                            ((0x000000F0&(data))>>4)
#define GDMA_LINE_BUFFER_STA_get_L2(data)                                            ((0x000000F0&(data))>>4)
#define GDMA_LINE_BUFFER_STA_L1_shift                                                (0)
#define GDMA_LINE_BUFFER_STA_L1_mask                                                 (0x0000000F)
#define GDMA_LINE_BUFFER_STA_L1(data)                                                (0x0000000F&((data)<<0))
#define GDMA_LINE_BUFFER_STA_L1_src(data)                                            ((0x0000000F&(data))>>0)
#define GDMA_LINE_BUFFER_STA_get_L1(data)                                            ((0x0000000F&(data))>>0)


#define GDMA_LINE_BUFFER_SIZE                                                        0x1802ff14
#define GDMA_LINE_BUFFER_SIZE_reg_addr                                               "0xB802FF14"
#define GDMA_LINE_BUFFER_SIZE_reg                                                    0xB802FF14
#define set_GDMA_LINE_BUFFER_SIZE_reg(data)   (*((volatile unsigned int*) GDMA_LINE_BUFFER_SIZE_reg)=data)
#define get_GDMA_LINE_BUFFER_SIZE_reg   (*((volatile unsigned int*) GDMA_LINE_BUFFER_SIZE_reg))
#define GDMA_LINE_BUFFER_SIZE_inst_adr                                               "0x00C5"
#define GDMA_LINE_BUFFER_SIZE_inst                                                   0x00C5
#define GDMA_LINE_BUFFER_SIZE_L8_shift                                               (28)
#define GDMA_LINE_BUFFER_SIZE_L8_mask                                                (0xF0000000)
#define GDMA_LINE_BUFFER_SIZE_L8(data)                                               (0xF0000000&((data)<<28))
#define GDMA_LINE_BUFFER_SIZE_L8_src(data)                                           ((0xF0000000&(data))>>28)
#define GDMA_LINE_BUFFER_SIZE_get_L8(data)                                           ((0xF0000000&(data))>>28)
#define GDMA_LINE_BUFFER_SIZE_L7_shift                                               (24)
#define GDMA_LINE_BUFFER_SIZE_L7_mask                                                (0x0F000000)
#define GDMA_LINE_BUFFER_SIZE_L7(data)                                               (0x0F000000&((data)<<24))
#define GDMA_LINE_BUFFER_SIZE_L7_src(data)                                           ((0x0F000000&(data))>>24)
#define GDMA_LINE_BUFFER_SIZE_get_L7(data)                                           ((0x0F000000&(data))>>24)
#define GDMA_LINE_BUFFER_SIZE_L6_shift                                               (20)
#define GDMA_LINE_BUFFER_SIZE_L6_mask                                                (0x00F00000)
#define GDMA_LINE_BUFFER_SIZE_L6(data)                                               (0x00F00000&((data)<<20))
#define GDMA_LINE_BUFFER_SIZE_L6_src(data)                                           ((0x00F00000&(data))>>20)
#define GDMA_LINE_BUFFER_SIZE_get_L6(data)                                           ((0x00F00000&(data))>>20)
#define GDMA_LINE_BUFFER_SIZE_L5_shift                                               (16)
#define GDMA_LINE_BUFFER_SIZE_L5_mask                                                (0x000F0000)
#define GDMA_LINE_BUFFER_SIZE_L5(data)                                               (0x000F0000&((data)<<16))
#define GDMA_LINE_BUFFER_SIZE_L5_src(data)                                           ((0x000F0000&(data))>>16)
#define GDMA_LINE_BUFFER_SIZE_get_L5(data)                                           ((0x000F0000&(data))>>16)
#define GDMA_LINE_BUFFER_SIZE_L4_shift                                               (12)
#define GDMA_LINE_BUFFER_SIZE_L4_mask                                                (0x0000F000)
#define GDMA_LINE_BUFFER_SIZE_L4(data)                                               (0x0000F000&((data)<<12))
#define GDMA_LINE_BUFFER_SIZE_L4_src(data)                                           ((0x0000F000&(data))>>12)
#define GDMA_LINE_BUFFER_SIZE_get_L4(data)                                           ((0x0000F000&(data))>>12)
#define GDMA_LINE_BUFFER_SIZE_L3_shift                                               (8)
#define GDMA_LINE_BUFFER_SIZE_L3_mask                                                (0x00000F00)
#define GDMA_LINE_BUFFER_SIZE_L3(data)                                               (0x00000F00&((data)<<8))
#define GDMA_LINE_BUFFER_SIZE_L3_src(data)                                           ((0x00000F00&(data))>>8)
#define GDMA_LINE_BUFFER_SIZE_get_L3(data)                                           ((0x00000F00&(data))>>8)
#define GDMA_LINE_BUFFER_SIZE_L2_shift                                               (4)
#define GDMA_LINE_BUFFER_SIZE_L2_mask                                                (0x000000F0)
#define GDMA_LINE_BUFFER_SIZE_L2(data)                                               (0x000000F0&((data)<<4))
#define GDMA_LINE_BUFFER_SIZE_L2_src(data)                                           ((0x000000F0&(data))>>4)
#define GDMA_LINE_BUFFER_SIZE_get_L2(data)                                           ((0x000000F0&(data))>>4)
#define GDMA_LINE_BUFFER_SIZE_L1_shift                                               (0)
#define GDMA_LINE_BUFFER_SIZE_L1_mask                                                (0x0000000F)
#define GDMA_LINE_BUFFER_SIZE_L1(data)                                               (0x0000000F&((data)<<0))
#define GDMA_LINE_BUFFER_SIZE_L1_src(data)                                           ((0x0000000F&(data))>>0)
#define GDMA_LINE_BUFFER_SIZE_get_L1(data)                                           ((0x0000000F&(data))>>0)


#define GDMA_LINE_BUFFER_END                                                         0x1802ff18
#define GDMA_LINE_BUFFER_END_reg_addr                                                "0xB802FF18"
#define GDMA_LINE_BUFFER_END_reg                                                     0xB802FF18
#define set_GDMA_LINE_BUFFER_END_reg(data)   (*((volatile unsigned int*) GDMA_LINE_BUFFER_END_reg)=data)
#define get_GDMA_LINE_BUFFER_END_reg   (*((volatile unsigned int*) GDMA_LINE_BUFFER_END_reg))
#define GDMA_LINE_BUFFER_END_inst_adr                                                "0x00C6"
#define GDMA_LINE_BUFFER_END_inst                                                    0x00C6
#define GDMA_LINE_BUFFER_END_Bundle_osd1_osd2_shift                                  (30)
#define GDMA_LINE_BUFFER_END_Bundle_osd1_osd2_mask                                   (0x40000000)
#define GDMA_LINE_BUFFER_END_Bundle_osd1_osd2(data)                                  (0x40000000&((data)<<30))
#define GDMA_LINE_BUFFER_END_Bundle_osd1_osd2_src(data)                              ((0x40000000&(data))>>30)
#define GDMA_LINE_BUFFER_END_get_Bundle_osd1_osd2(data)                              ((0x40000000&(data))>>30)
#define GDMA_LINE_BUFFER_END_Bundle_osd3_osd4_shift                                  (29)
#define GDMA_LINE_BUFFER_END_Bundle_osd3_osd4_mask                                   (0x20000000)
#define GDMA_LINE_BUFFER_END_Bundle_osd3_osd4(data)                                  (0x20000000&((data)<<29))
#define GDMA_LINE_BUFFER_END_Bundle_osd3_osd4_src(data)                              ((0x20000000&(data))>>29)
#define GDMA_LINE_BUFFER_END_get_Bundle_osd3_osd4(data)                              ((0x20000000&(data))>>29)
#define GDMA_LINE_BUFFER_END_Bundle_osd4_osd5_shift                                  (28)
#define GDMA_LINE_BUFFER_END_Bundle_osd4_osd5_mask                                   (0x10000000)
#define GDMA_LINE_BUFFER_END_Bundle_osd4_osd5(data)                                  (0x10000000&((data)<<28))
#define GDMA_LINE_BUFFER_END_Bundle_osd4_osd5_src(data)                              ((0x10000000&(data))>>28)
#define GDMA_LINE_BUFFER_END_get_Bundle_osd4_osd5(data)                              ((0x10000000&(data))>>28)
#define GDMA_LINE_BUFFER_END_Bundle_osdsr1_osdsr2_shift                              (25)
#define GDMA_LINE_BUFFER_END_Bundle_osdsr1_osdsr2_mask                               (0x02000000)
#define GDMA_LINE_BUFFER_END_Bundle_osdsr1_osdsr2(data)                              (0x02000000&((data)<<25))
#define GDMA_LINE_BUFFER_END_Bundle_osdsr1_osdsr2_src(data)                          ((0x02000000&(data))>>25)
#define GDMA_LINE_BUFFER_END_get_Bundle_osdsr1_osdsr2(data)                          ((0x02000000&(data))>>25)
#define GDMA_LINE_BUFFER_END_Bundle_osdsrbypass4_osdsrbypass5_shift                  (24)
#define GDMA_LINE_BUFFER_END_Bundle_osdsrbypass4_osdsrbypass5_mask                   (0x01000000)
#define GDMA_LINE_BUFFER_END_Bundle_osdsrbypass4_osdsrbypass5(data)                  (0x01000000&((data)<<24))
#define GDMA_LINE_BUFFER_END_Bundle_osdsrbypass4_osdsrbypass5_src(data)              ((0x01000000&(data))>>24)
#define GDMA_LINE_BUFFER_END_get_Bundle_osdsrbypass4_osdsrbypass5(data)              ((0x01000000&(data))>>24)
#define GDMA_LINE_BUFFER_END_OSDSR5_switch_to_shift                                  (16)
#define GDMA_LINE_BUFFER_END_OSDSR5_switch_to_mask                                   (0x00070000)
#define GDMA_LINE_BUFFER_END_OSDSR5_switch_to(data)                                  (0x00070000&((data)<<16))
#define GDMA_LINE_BUFFER_END_OSDSR5_switch_to_src(data)                              ((0x00070000&(data))>>16)
#define GDMA_LINE_BUFFER_END_get_OSDSR5_switch_to(data)                              ((0x00070000&(data))>>16)
#define GDMA_LINE_BUFFER_END_OSDSR4_switch_to_shift                                  (12)
#define GDMA_LINE_BUFFER_END_OSDSR4_switch_to_mask                                   (0x00007000)
#define GDMA_LINE_BUFFER_END_OSDSR4_switch_to(data)                                  (0x00007000&((data)<<12))
#define GDMA_LINE_BUFFER_END_OSDSR4_switch_to_src(data)                              ((0x00007000&(data))>>12)
#define GDMA_LINE_BUFFER_END_get_OSDSR4_switch_to(data)                              ((0x00007000&(data))>>12)
#define GDMA_LINE_BUFFER_END_OSDSR3_switch_to_shift                                  (8)
#define GDMA_LINE_BUFFER_END_OSDSR3_switch_to_mask                                   (0x00000700)
#define GDMA_LINE_BUFFER_END_OSDSR3_switch_to(data)                                  (0x00000700&((data)<<8))
#define GDMA_LINE_BUFFER_END_OSDSR3_switch_to_src(data)                              ((0x00000700&(data))>>8)
#define GDMA_LINE_BUFFER_END_get_OSDSR3_switch_to(data)                              ((0x00000700&(data))>>8)
#define GDMA_LINE_BUFFER_END_OSDSR2_switch_to_shift                                  (4)
#define GDMA_LINE_BUFFER_END_OSDSR2_switch_to_mask                                   (0x00000070)
#define GDMA_LINE_BUFFER_END_OSDSR2_switch_to(data)                                  (0x00000070&((data)<<4))
#define GDMA_LINE_BUFFER_END_OSDSR2_switch_to_src(data)                              ((0x00000070&(data))>>4)
#define GDMA_LINE_BUFFER_END_get_OSDSR2_switch_to(data)                              ((0x00000070&(data))>>4)
#define GDMA_LINE_BUFFER_END_OSDSR1_switch_to_shift                                  (0)
#define GDMA_LINE_BUFFER_END_OSDSR1_switch_to_mask                                   (0x00000007)
#define GDMA_LINE_BUFFER_END_OSDSR1_switch_to(data)                                  (0x00000007&((data)<<0))
#define GDMA_LINE_BUFFER_END_OSDSR1_switch_to_src(data)                              ((0x00000007&(data))>>0)
#define GDMA_LINE_BUFFER_END_get_OSDSR1_switch_to(data)                              ((0x00000007&(data))>>0)


#define GDMA_OSD_STATUS                                                              0x1802ff20
#define GDMA_OSD_STATUS_reg_addr                                                     "0xB802FF20"
#define GDMA_OSD_STATUS_reg                                                          0xB802FF20
#define set_GDMA_OSD_STATUS_reg(data)   (*((volatile unsigned int*) GDMA_OSD_STATUS_reg)=data)
#define get_GDMA_OSD_STATUS_reg   (*((volatile unsigned int*) GDMA_OSD_STATUS_reg))
#define GDMA_OSD_STATUS_inst_adr                                                     "0x00C8"
#define GDMA_OSD_STATUS_inst                                                         0x00C8
#define GDMA_OSD_STATUS_osd1_fbdc1_en_shift                                          (31)
#define GDMA_OSD_STATUS_osd1_fbdc1_en_mask                                           (0x80000000)
#define GDMA_OSD_STATUS_osd1_fbdc1_en(data)                                          (0x80000000&((data)<<31))
#define GDMA_OSD_STATUS_osd1_fbdc1_en_src(data)                                      ((0x80000000&(data))>>31)
#define GDMA_OSD_STATUS_get_osd1_fbdc1_en(data)                                      ((0x80000000&(data))>>31)
#define GDMA_OSD_STATUS_osd1_fbdc2_en_shift                                          (30)
#define GDMA_OSD_STATUS_osd1_fbdc2_en_mask                                           (0x40000000)
#define GDMA_OSD_STATUS_osd1_fbdc2_en(data)                                          (0x40000000&((data)<<30))
#define GDMA_OSD_STATUS_osd1_fbdc2_en_src(data)                                      ((0x40000000&(data))>>30)
#define GDMA_OSD_STATUS_get_osd1_fbdc2_en(data)                                      ((0x40000000&(data))>>30)
#define GDMA_OSD_STATUS_osd1_fbdc3_en_shift                                          (29)
#define GDMA_OSD_STATUS_osd1_fbdc3_en_mask                                           (0x20000000)
#define GDMA_OSD_STATUS_osd1_fbdc3_en(data)                                          (0x20000000&((data)<<29))
#define GDMA_OSD_STATUS_osd1_fbdc3_en_src(data)                                      ((0x20000000&(data))>>29)
#define GDMA_OSD_STATUS_get_osd1_fbdc3_en(data)                                      ((0x20000000&(data))>>29)
#define GDMA_OSD_STATUS_osd2_fbdc1_en_shift                                          (28)
#define GDMA_OSD_STATUS_osd2_fbdc1_en_mask                                           (0x10000000)
#define GDMA_OSD_STATUS_osd2_fbdc1_en(data)                                          (0x10000000&((data)<<28))
#define GDMA_OSD_STATUS_osd2_fbdc1_en_src(data)                                      ((0x10000000&(data))>>28)
#define GDMA_OSD_STATUS_get_osd2_fbdc1_en(data)                                      ((0x10000000&(data))>>28)
#define GDMA_OSD_STATUS_osd2_fbdc2_en_shift                                          (27)
#define GDMA_OSD_STATUS_osd2_fbdc2_en_mask                                           (0x08000000)
#define GDMA_OSD_STATUS_osd2_fbdc2_en(data)                                          (0x08000000&((data)<<27))
#define GDMA_OSD_STATUS_osd2_fbdc2_en_src(data)                                      ((0x08000000&(data))>>27)
#define GDMA_OSD_STATUS_get_osd2_fbdc2_en(data)                                      ((0x08000000&(data))>>27)
#define GDMA_OSD_STATUS_osd2_fbdc3_en_shift                                          (26)
#define GDMA_OSD_STATUS_osd2_fbdc3_en_mask                                           (0x04000000)
#define GDMA_OSD_STATUS_osd2_fbdc3_en(data)                                          (0x04000000&((data)<<26))
#define GDMA_OSD_STATUS_osd2_fbdc3_en_src(data)                                      ((0x04000000&(data))>>26)
#define GDMA_OSD_STATUS_get_osd2_fbdc3_en(data)                                      ((0x04000000&(data))>>26)
#define GDMA_OSD_STATUS_osd3_fbdc1_en_shift                                          (25)
#define GDMA_OSD_STATUS_osd3_fbdc1_en_mask                                           (0x02000000)
#define GDMA_OSD_STATUS_osd3_fbdc1_en(data)                                          (0x02000000&((data)<<25))
#define GDMA_OSD_STATUS_osd3_fbdc1_en_src(data)                                      ((0x02000000&(data))>>25)
#define GDMA_OSD_STATUS_get_osd3_fbdc1_en(data)                                      ((0x02000000&(data))>>25)
#define GDMA_OSD_STATUS_osd3_fbdc2_en_shift                                          (24)
#define GDMA_OSD_STATUS_osd3_fbdc2_en_mask                                           (0x01000000)
#define GDMA_OSD_STATUS_osd3_fbdc2_en(data)                                          (0x01000000&((data)<<24))
#define GDMA_OSD_STATUS_osd3_fbdc2_en_src(data)                                      ((0x01000000&(data))>>24)
#define GDMA_OSD_STATUS_get_osd3_fbdc2_en(data)                                      ((0x01000000&(data))>>24)
#define GDMA_OSD_STATUS_osd3_fbdc3_en_shift                                          (23)
#define GDMA_OSD_STATUS_osd3_fbdc3_en_mask                                           (0x00800000)
#define GDMA_OSD_STATUS_osd3_fbdc3_en(data)                                          (0x00800000&((data)<<23))
#define GDMA_OSD_STATUS_osd3_fbdc3_en_src(data)                                      ((0x00800000&(data))>>23)
#define GDMA_OSD_STATUS_get_osd3_fbdc3_en(data)                                      ((0x00800000&(data))>>23)
#define GDMA_OSD_STATUS_write_back_status_shift                                      (20)
#define GDMA_OSD_STATUS_write_back_status_mask                                       (0x00300000)
#define GDMA_OSD_STATUS_write_back_status(data)                                      (0x00300000&((data)<<20))
#define GDMA_OSD_STATUS_write_back_status_src(data)                                  ((0x00300000&(data))>>20)
#define GDMA_OSD_STATUS_get_write_back_status(data)                                  ((0x00300000&(data))>>20)
#define GDMA_OSD_STATUS_offline_blend_status_shift                                   (18)
#define GDMA_OSD_STATUS_offline_blend_status_mask                                    (0x000C0000)
#define GDMA_OSD_STATUS_offline_blend_status(data)                                   (0x000C0000&((data)<<18))
#define GDMA_OSD_STATUS_offline_blend_status_src(data)                               ((0x000C0000&(data))>>18)
#define GDMA_OSD_STATUS_get_offline_blend_status(data)                               ((0x000C0000&(data))>>18)
#define GDMA_OSD_STATUS_middle_blend_status_shift                                    (16)
#define GDMA_OSD_STATUS_middle_blend_status_mask                                     (0x00030000)
#define GDMA_OSD_STATUS_middle_blend_status(data)                                    (0x00030000&((data)<<16))
#define GDMA_OSD_STATUS_middle_blend_status_src(data)                                ((0x00030000&(data))>>16)
#define GDMA_OSD_STATUS_get_middle_blend_status(data)                                ((0x00030000&(data))>>16)
#define GDMA_OSD_STATUS_osd6_status_shift                                            (10)
#define GDMA_OSD_STATUS_osd6_status_mask                                             (0x00000C00)
#define GDMA_OSD_STATUS_osd6_status(data)                                            (0x00000C00&((data)<<10))
#define GDMA_OSD_STATUS_osd6_status_src(data)                                        ((0x00000C00&(data))>>10)
#define GDMA_OSD_STATUS_get_osd6_status(data)                                        ((0x00000C00&(data))>>10)
#define GDMA_OSD_STATUS_osd5_status_shift                                            (8)
#define GDMA_OSD_STATUS_osd5_status_mask                                             (0x00000300)
#define GDMA_OSD_STATUS_osd5_status(data)                                            (0x00000300&((data)<<8))
#define GDMA_OSD_STATUS_osd5_status_src(data)                                        ((0x00000300&(data))>>8)
#define GDMA_OSD_STATUS_get_osd5_status(data)                                        ((0x00000300&(data))>>8)
#define GDMA_OSD_STATUS_osd4_status_shift                                            (6)
#define GDMA_OSD_STATUS_osd4_status_mask                                             (0x000000C0)
#define GDMA_OSD_STATUS_osd4_status(data)                                            (0x000000C0&((data)<<6))
#define GDMA_OSD_STATUS_osd4_status_src(data)                                        ((0x000000C0&(data))>>6)
#define GDMA_OSD_STATUS_get_osd4_status(data)                                        ((0x000000C0&(data))>>6)
#define GDMA_OSD_STATUS_osd3_status_shift                                            (4)
#define GDMA_OSD_STATUS_osd3_status_mask                                             (0x00000030)
#define GDMA_OSD_STATUS_osd3_status(data)                                            (0x00000030&((data)<<4))
#define GDMA_OSD_STATUS_osd3_status_src(data)                                        ((0x00000030&(data))>>4)
#define GDMA_OSD_STATUS_get_osd3_status(data)                                        ((0x00000030&(data))>>4)
#define GDMA_OSD_STATUS_osd2_status_shift                                            (2)
#define GDMA_OSD_STATUS_osd2_status_mask                                             (0x0000000C)
#define GDMA_OSD_STATUS_osd2_status(data)                                            (0x0000000C&((data)<<2))
#define GDMA_OSD_STATUS_osd2_status_src(data)                                        ((0x0000000C&(data))>>2)
#define GDMA_OSD_STATUS_get_osd2_status(data)                                        ((0x0000000C&(data))>>2)
#define GDMA_OSD_STATUS_osd1_status_shift                                            (0)
#define GDMA_OSD_STATUS_osd1_status_mask                                             (0x00000003)
#define GDMA_OSD_STATUS_osd1_status(data)                                            (0x00000003&((data)<<0))
#define GDMA_OSD_STATUS_osd1_status_src(data)                                        ((0x00000003&(data))>>0)
#define GDMA_OSD_STATUS_get_osd1_status(data)                                        ((0x00000003&(data))>>0)


#define GDMA_BLEND_SETTING_CONFLICT                                                  0x1802ff24
#define GDMA_BLEND_SETTING_CONFLICT_reg_addr                                         "0xB802FF24"
#define GDMA_BLEND_SETTING_CONFLICT_reg                                              0xB802FF24
#define set_GDMA_BLEND_SETTING_CONFLICT_reg(data)   (*((volatile unsigned int*) GDMA_BLEND_SETTING_CONFLICT_reg)=data)
#define get_GDMA_BLEND_SETTING_CONFLICT_reg   (*((volatile unsigned int*) GDMA_BLEND_SETTING_CONFLICT_reg))
#define GDMA_BLEND_SETTING_CONFLICT_inst_adr                                         "0x00C9"
#define GDMA_BLEND_SETTING_CONFLICT_inst                                             0x00C9
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c2_shift                               (26)
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c2_mask                                (0x04000000)
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c2(data)                               (0x04000000&((data)<<26))
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c2_src(data)                           ((0x04000000&(data))>>26)
#define GDMA_BLEND_SETTING_CONFLICT_get_pre_blend_c2(data)                           ((0x04000000&(data))>>26)
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c1_shift                               (25)
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c1_mask                                (0x02000000)
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c1(data)                               (0x02000000&((data)<<25))
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c1_src(data)                           ((0x02000000&(data))>>25)
#define GDMA_BLEND_SETTING_CONFLICT_get_pre_blend_c1(data)                           ((0x02000000&(data))>>25)
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c0_shift                               (24)
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c0_mask                                (0x01000000)
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c0(data)                               (0x01000000&((data)<<24))
#define GDMA_BLEND_SETTING_CONFLICT_pre_blend_c0_src(data)                           ((0x01000000&(data))>>24)
#define GDMA_BLEND_SETTING_CONFLICT_get_pre_blend_c0(data)                           ((0x01000000&(data))>>24)
#define GDMA_BLEND_SETTING_CONFLICT_fbdc_over_6_picture_shift                        (22)
#define GDMA_BLEND_SETTING_CONFLICT_fbdc_over_6_picture_mask                         (0x00400000)
#define GDMA_BLEND_SETTING_CONFLICT_fbdc_over_6_picture(data)                        (0x00400000&((data)<<22))
#define GDMA_BLEND_SETTING_CONFLICT_fbdc_over_6_picture_src(data)                    ((0x00400000&(data))>>22)
#define GDMA_BLEND_SETTING_CONFLICT_get_fbdc_over_6_picture(data)                    ((0x00400000&(data))>>22)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr5_shift                                     (21)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr5_mask                                      (0x00200000)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr5(data)                                     (0x00200000&((data)<<21))
#define GDMA_BLEND_SETTING_CONFLICT_osdsr5_src(data)                                 ((0x00200000&(data))>>21)
#define GDMA_BLEND_SETTING_CONFLICT_get_osdsr5(data)                                 ((0x00200000&(data))>>21)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr4_shift                                     (20)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr4_mask                                      (0x00100000)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr4(data)                                     (0x00100000&((data)<<20))
#define GDMA_BLEND_SETTING_CONFLICT_osdsr4_src(data)                                 ((0x00100000&(data))>>20)
#define GDMA_BLEND_SETTING_CONFLICT_get_osdsr4(data)                                 ((0x00100000&(data))>>20)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr3_shift                                     (19)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr3_mask                                      (0x00080000)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr3(data)                                     (0x00080000&((data)<<19))
#define GDMA_BLEND_SETTING_CONFLICT_osdsr3_src(data)                                 ((0x00080000&(data))>>19)
#define GDMA_BLEND_SETTING_CONFLICT_get_osdsr3(data)                                 ((0x00080000&(data))>>19)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr2_shift                                     (18)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr2_mask                                      (0x00040000)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr2(data)                                     (0x00040000&((data)<<18))
#define GDMA_BLEND_SETTING_CONFLICT_osdsr2_src(data)                                 ((0x00040000&(data))>>18)
#define GDMA_BLEND_SETTING_CONFLICT_get_osdsr2(data)                                 ((0x00040000&(data))>>18)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr1_shift                                     (17)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr1_mask                                      (0x00020000)
#define GDMA_BLEND_SETTING_CONFLICT_osdsr1(data)                                     (0x00020000&((data)<<17))
#define GDMA_BLEND_SETTING_CONFLICT_osdsr1_src(data)                                 ((0x00020000&(data))>>17)
#define GDMA_BLEND_SETTING_CONFLICT_get_osdsr1(data)                                 ((0x00020000&(data))>>17)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c3_shift                               (7)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c3_mask                                (0x00000080)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c3(data)                               (0x00000080&((data)<<7))
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c3_src(data)                           ((0x00000080&(data))>>7)
#define GDMA_BLEND_SETTING_CONFLICT_get_off_blend_c3(data)                           ((0x00000080&(data))>>7)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c2_shift                               (6)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c2_mask                                (0x00000040)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c2(data)                               (0x00000040&((data)<<6))
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c2_src(data)                           ((0x00000040&(data))>>6)
#define GDMA_BLEND_SETTING_CONFLICT_get_off_blend_c2(data)                           ((0x00000040&(data))>>6)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c1_shift                               (5)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c1_mask                                (0x00000020)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c1(data)                               (0x00000020&((data)<<5))
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c1_src(data)                           ((0x00000020&(data))>>5)
#define GDMA_BLEND_SETTING_CONFLICT_get_off_blend_c1(data)                           ((0x00000020&(data))>>5)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c0_shift                               (4)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c0_mask                                (0x00000010)
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c0(data)                               (0x00000010&((data)<<4))
#define GDMA_BLEND_SETTING_CONFLICT_off_blend_c0_src(data)                           ((0x00000010&(data))>>4)
#define GDMA_BLEND_SETTING_CONFLICT_get_off_blend_c0(data)                           ((0x00000010&(data))>>4)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c3_shift                               (3)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c3_mask                                (0x00000008)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c3(data)                               (0x00000008&((data)<<3))
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c3_src(data)                           ((0x00000008&(data))>>3)
#define GDMA_BLEND_SETTING_CONFLICT_get_mid_blend_c3(data)                           ((0x00000008&(data))>>3)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c2_shift                               (2)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c2_mask                                (0x00000004)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c2(data)                               (0x00000004&((data)<<2))
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c2_src(data)                           ((0x00000004&(data))>>2)
#define GDMA_BLEND_SETTING_CONFLICT_get_mid_blend_c2(data)                           ((0x00000004&(data))>>2)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c1_shift                               (1)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c1_mask                                (0x00000002)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c1(data)                               (0x00000002&((data)<<1))
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c1_src(data)                           ((0x00000002&(data))>>1)
#define GDMA_BLEND_SETTING_CONFLICT_get_mid_blend_c1(data)                           ((0x00000002&(data))>>1)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c0_shift                               (0)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c0_mask                                (0x00000001)
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c0(data)                               (0x00000001&((data)<<0))
#define GDMA_BLEND_SETTING_CONFLICT_mid_blend_c0_src(data)                           ((0x00000001&(data))>>0)
#define GDMA_BLEND_SETTING_CONFLICT_get_mid_blend_c0(data)                           ((0x00000001&(data))>>0)


#define GDMA_VBI_TO_SE                                                               0x1802ff28
#define GDMA_VBI_TO_SE_reg_addr                                                      "0xB802FF28"
#define GDMA_VBI_TO_SE_reg                                                           0xB802FF28
#define set_GDMA_VBI_TO_SE_reg(data)   (*((volatile unsigned int*) GDMA_VBI_TO_SE_reg)=data)
#define get_GDMA_VBI_TO_SE_reg   (*((volatile unsigned int*) GDMA_VBI_TO_SE_reg))
#define GDMA_VBI_TO_SE_inst_adr                                                      "0x00CA"
#define GDMA_VBI_TO_SE_inst                                                          0x00CA
#define GDMA_VBI_TO_SE_sel_shift                                                     (0)
#define GDMA_VBI_TO_SE_sel_mask                                                      (0x00000007)
#define GDMA_VBI_TO_SE_sel(data)                                                     (0x00000007&((data)<<0))
#define GDMA_VBI_TO_SE_sel_src(data)                                                 ((0x00000007&(data))>>0)
#define GDMA_VBI_TO_SE_get_sel(data)                                                 ((0x00000007&(data))>>0)


#define GDMA_OSD1_CTRL                                                               0x1802f200
#define GDMA_OSD1_CTRL_reg_addr                                                      "0xB802F200"
#define GDMA_OSD1_CTRL_reg                                                           0xB802F200
#define set_GDMA_OSD1_CTRL_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_CTRL_reg)=data)
#define get_GDMA_OSD1_CTRL_reg   (*((volatile unsigned int*) GDMA_OSD1_CTRL_reg))
#define GDMA_OSD1_CTRL_inst_adr                                                      "0x0080"
#define GDMA_OSD1_CTRL_inst                                                          0x0080
#define GDMA_OSD1_CTRL_d3_mode_shift                                                 (9)
#define GDMA_OSD1_CTRL_d3_mode_mask                                                  (0x00000200)
#define GDMA_OSD1_CTRL_d3_mode(data)                                                 (0x00000200&((data)<<9))
#define GDMA_OSD1_CTRL_d3_mode_src(data)                                             ((0x00000200&(data))>>9)
#define GDMA_OSD1_CTRL_get_d3_mode(data)                                             ((0x00000200&(data))>>9)
#define GDMA_OSD1_CTRL_rotate_shift                                                  (8)
#define GDMA_OSD1_CTRL_rotate_mask                                                   (0x00000100)
#define GDMA_OSD1_CTRL_rotate(data)                                                  (0x00000100&((data)<<8))
#define GDMA_OSD1_CTRL_rotate_src(data)                                              ((0x00000100&(data))>>8)
#define GDMA_OSD1_CTRL_get_rotate(data)                                              ((0x00000100&(data))>>8)
#define GDMA_OSD1_CTRL_osd1_en_shift                                                 (1)
#define GDMA_OSD1_CTRL_osd1_en_mask                                                  (0x00000002)
#define GDMA_OSD1_CTRL_osd1_en(data)                                                 (0x00000002&((data)<<1))
#define GDMA_OSD1_CTRL_osd1_en_src(data)                                             ((0x00000002&(data))>>1)
#define GDMA_OSD1_CTRL_get_osd1_en(data)                                             ((0x00000002&(data))>>1)
#define GDMA_OSD1_CTRL_write_data_shift                                              (0)
#define GDMA_OSD1_CTRL_write_data_mask                                               (0x00000001)
#define GDMA_OSD1_CTRL_write_data(data)                                              (0x00000001&((data)<<0))
#define GDMA_OSD1_CTRL_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define GDMA_OSD1_CTRL_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define GDMA_OSD1                                                                    0x1802f204
#define GDMA_OSD1_reg_addr                                                           "0xB802F204"
#define GDMA_OSD1_reg                                                                0xB802F204
#define set_GDMA_OSD1_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_reg)=data)
#define get_GDMA_OSD1_reg   (*((volatile unsigned int*) GDMA_OSD1_reg))
#define GDMA_OSD1_inst_adr                                                           "0x0081"
#define GDMA_OSD1_inst                                                               0x0081
#define GDMA_OSD1_wi_endian_shift                                                    (25)
#define GDMA_OSD1_wi_endian_mask                                                     (0x02000000)
#define GDMA_OSD1_wi_endian(data)                                                    (0x02000000&((data)<<25))
#define GDMA_OSD1_wi_endian_src(data)                                                ((0x02000000&(data))>>25)
#define GDMA_OSD1_get_wi_endian(data)                                                ((0x02000000&(data))>>25)
#define GDMA_OSD1_rgb_out_shift                                                      (24)
#define GDMA_OSD1_rgb_out_mask                                                       (0x01000000)
#define GDMA_OSD1_rgb_out(data)                                                      (0x01000000&((data)<<24))
#define GDMA_OSD1_rgb_out_src(data)                                                  ((0x01000000&(data))>>24)
#define GDMA_OSD1_get_rgb_out(data)                                                  ((0x01000000&(data))>>24)
#define GDMA_OSD1_osd_shift                                                          (16)
#define GDMA_OSD1_osd_mask                                                           (0x00010000)
#define GDMA_OSD1_osd(data)                                                          (0x00010000&((data)<<16))
#define GDMA_OSD1_osd_src(data)                                                      ((0x00010000&(data))>>16)
#define GDMA_OSD1_get_osd(data)                                                      ((0x00010000&(data))>>16)
#define GDMA_OSD1_clear_region_en_shift                                              (1)
#define GDMA_OSD1_clear_region_en_mask                                               (0x00000002)
#define GDMA_OSD1_clear_region_en(data)                                              (0x00000002&((data)<<1))
#define GDMA_OSD1_clear_region_en_src(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD1_get_clear_region_en(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD1_write_data_shift                                                   (0)
#define GDMA_OSD1_write_data_mask                                                    (0x00000001)
#define GDMA_OSD1_write_data(data)                                                   (0x00000001&((data)<<0))
#define GDMA_OSD1_write_data_src(data)                                               ((0x00000001&(data))>>0)
#define GDMA_OSD1_get_write_data(data)                                               ((0x00000001&(data))>>0)


#define GDMA_OSD1_START                                                              0x1802f208
#define GDMA_OSD1_START_reg_addr                                                     "0xB802F208"
#define GDMA_OSD1_START_reg                                                          0xB802F208
#define set_GDMA_OSD1_START_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_START_reg)=data)
#define get_GDMA_OSD1_START_reg   (*((volatile unsigned int*) GDMA_OSD1_START_reg))
#define GDMA_OSD1_START_inst_adr                                                     "0x0082"
#define GDMA_OSD1_START_inst                                                         0x0082
#define GDMA_OSD1_START_th_shift                                                     (0)
#define GDMA_OSD1_START_th_mask                                                      (0x00001FFF)
#define GDMA_OSD1_START_th(data)                                                     (0x00001FFF&((data)<<0))
#define GDMA_OSD1_START_th_src(data)                                                 ((0x00001FFF&(data))>>0)
#define GDMA_OSD1_START_get_th(data)                                                 ((0x00001FFF&(data))>>0)


#define GDMA_OSD1_VBI_END                                                            0x1802f20c
#define GDMA_OSD1_VBI_END_reg_addr                                                   "0xB802F20C"
#define GDMA_OSD1_VBI_END_reg                                                        0xB802F20C
#define set_GDMA_OSD1_VBI_END_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_VBI_END_reg)=data)
#define get_GDMA_OSD1_VBI_END_reg   (*((volatile unsigned int*) GDMA_OSD1_VBI_END_reg))
#define GDMA_OSD1_VBI_END_inst_adr                                                   "0x0083"
#define GDMA_OSD1_VBI_END_inst                                                       0x0083
#define GDMA_OSD1_VBI_END_th_shift                                                   (0)
#define GDMA_OSD1_VBI_END_th_mask                                                    (0x00001FFF)
#define GDMA_OSD1_VBI_END_th(data)                                                   (0x00001FFF&((data)<<0))
#define GDMA_OSD1_VBI_END_th_src(data)                                               ((0x00001FFF&(data))>>0)
#define GDMA_OSD1_VBI_END_get_th(data)                                               ((0x00001FFF&(data))>>0)


#define GDMA_OSD1_WI                                                                 0x1802f210
#define GDMA_OSD1_WI_reg_addr                                                        "0xB802F210"
#define GDMA_OSD1_WI_reg                                                             0xB802F210
#define set_GDMA_OSD1_WI_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_WI_reg)=data)
#define get_GDMA_OSD1_WI_reg   (*((volatile unsigned int*) GDMA_OSD1_WI_reg))
#define GDMA_OSD1_WI_inst_adr                                                        "0x0084"
#define GDMA_OSD1_WI_inst                                                            0x0084
#define GDMA_OSD1_WI_addr_shift                                                      (0)
#define GDMA_OSD1_WI_addr_mask                                                       (0xFFFFFFFF)
#define GDMA_OSD1_WI_addr(data)                                                      (0xFFFFFFFF&((data)<<0))
#define GDMA_OSD1_WI_addr_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define GDMA_OSD1_WI_get_addr(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define GDMA_OSD1_WI_3D                                                              0x1802f214
#define GDMA_OSD1_WI_3D_reg_addr                                                     "0xB802F214"
#define GDMA_OSD1_WI_3D_reg                                                          0xB802F214
#define set_GDMA_OSD1_WI_3D_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_WI_3D_reg)=data)
#define get_GDMA_OSD1_WI_3D_reg   (*((volatile unsigned int*) GDMA_OSD1_WI_3D_reg))
#define GDMA_OSD1_WI_3D_inst_adr                                                     "0x0085"
#define GDMA_OSD1_WI_3D_inst                                                         0x0085
#define GDMA_OSD1_WI_3D_addr_shift                                                   (0)
#define GDMA_OSD1_WI_3D_addr_mask                                                    (0xFFFFFFFF)
#define GDMA_OSD1_WI_3D_addr(data)                                                   (0xFFFFFFFF&((data)<<0))
#define GDMA_OSD1_WI_3D_addr_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define GDMA_OSD1_WI_3D_get_addr(data)                                               ((0xFFFFFFFF&(data))>>0)


#define GDMA_OSD1_SIZE                                                               0x1802f218
#define GDMA_OSD1_SIZE_reg_addr                                                      "0xB802F218"
#define GDMA_OSD1_SIZE_reg                                                           0xB802F218
#define set_GDMA_OSD1_SIZE_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_SIZE_reg)=data)
#define get_GDMA_OSD1_SIZE_reg   (*((volatile unsigned int*) GDMA_OSD1_SIZE_reg))
#define GDMA_OSD1_SIZE_inst_adr                                                      "0x0086"
#define GDMA_OSD1_SIZE_inst                                                          0x0086
#define GDMA_OSD1_SIZE_w_shift                                                       (16)
#define GDMA_OSD1_SIZE_w_mask                                                        (0x1FFF0000)
#define GDMA_OSD1_SIZE_w(data)                                                       (0x1FFF0000&((data)<<16))
#define GDMA_OSD1_SIZE_w_src(data)                                                   ((0x1FFF0000&(data))>>16)
#define GDMA_OSD1_SIZE_get_w(data)                                                   ((0x1FFF0000&(data))>>16)
#define GDMA_OSD1_SIZE_h_shift                                                       (0)
#define GDMA_OSD1_SIZE_h_mask                                                        (0x00001FFF)
#define GDMA_OSD1_SIZE_h(data)                                                       (0x00001FFF&((data)<<0))
#define GDMA_OSD1_SIZE_h_src(data)                                                   ((0x00001FFF&(data))>>0)
#define GDMA_OSD1_SIZE_get_h(data)                                                   ((0x00001FFF&(data))>>0)


#define GDMA_OSD1_CC1                                                                0x1802f21c
#define GDMA_OSD1_CC1_reg_addr                                                       "0xB802F21C"
#define GDMA_OSD1_CC1_reg                                                            0xB802F21C
#define set_GDMA_OSD1_CC1_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_CC1_reg)=data)
#define get_GDMA_OSD1_CC1_reg   (*((volatile unsigned int*) GDMA_OSD1_CC1_reg))
#define GDMA_OSD1_CC1_inst_adr                                                       "0x0087"
#define GDMA_OSD1_CC1_inst                                                           0x0087
#define GDMA_OSD1_CC1_m01_shift                                                      (16)
#define GDMA_OSD1_CC1_m01_mask                                                       (0x3FFF0000)
#define GDMA_OSD1_CC1_m01(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD1_CC1_m01_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD1_CC1_get_m01(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD1_CC1_m00_shift                                                      (0)
#define GDMA_OSD1_CC1_m00_mask                                                       (0x00003FFF)
#define GDMA_OSD1_CC1_m00(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD1_CC1_m00_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD1_CC1_get_m00(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD1_CC2                                                                0x1802f220
#define GDMA_OSD1_CC2_reg_addr                                                       "0xB802F220"
#define GDMA_OSD1_CC2_reg                                                            0xB802F220
#define set_GDMA_OSD1_CC2_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_CC2_reg)=data)
#define get_GDMA_OSD1_CC2_reg   (*((volatile unsigned int*) GDMA_OSD1_CC2_reg))
#define GDMA_OSD1_CC2_inst_adr                                                       "0x0088"
#define GDMA_OSD1_CC2_inst                                                           0x0088
#define GDMA_OSD1_CC2_m10_shift                                                      (16)
#define GDMA_OSD1_CC2_m10_mask                                                       (0x3FFF0000)
#define GDMA_OSD1_CC2_m10(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD1_CC2_m10_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD1_CC2_get_m10(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD1_CC2_m02_shift                                                      (0)
#define GDMA_OSD1_CC2_m02_mask                                                       (0x00003FFF)
#define GDMA_OSD1_CC2_m02(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD1_CC2_m02_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD1_CC2_get_m02(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD1_CC3                                                                0x1802f224
#define GDMA_OSD1_CC3_reg_addr                                                       "0xB802F224"
#define GDMA_OSD1_CC3_reg                                                            0xB802F224
#define set_GDMA_OSD1_CC3_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_CC3_reg)=data)
#define get_GDMA_OSD1_CC3_reg   (*((volatile unsigned int*) GDMA_OSD1_CC3_reg))
#define GDMA_OSD1_CC3_inst_adr                                                       "0x0089"
#define GDMA_OSD1_CC3_inst                                                           0x0089
#define GDMA_OSD1_CC3_m12_shift                                                      (16)
#define GDMA_OSD1_CC3_m12_mask                                                       (0x3FFF0000)
#define GDMA_OSD1_CC3_m12(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD1_CC3_m12_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD1_CC3_get_m12(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD1_CC3_m11_shift                                                      (0)
#define GDMA_OSD1_CC3_m11_mask                                                       (0x00003FFF)
#define GDMA_OSD1_CC3_m11(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD1_CC3_m11_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD1_CC3_get_m11(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD1_CC4                                                                0x1802f228
#define GDMA_OSD1_CC4_reg_addr                                                       "0xB802F228"
#define GDMA_OSD1_CC4_reg                                                            0xB802F228
#define set_GDMA_OSD1_CC4_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_CC4_reg)=data)
#define get_GDMA_OSD1_CC4_reg   (*((volatile unsigned int*) GDMA_OSD1_CC4_reg))
#define GDMA_OSD1_CC4_inst_adr                                                       "0x008A"
#define GDMA_OSD1_CC4_inst                                                           0x008A
#define GDMA_OSD1_CC4_m21_shift                                                      (16)
#define GDMA_OSD1_CC4_m21_mask                                                       (0x3FFF0000)
#define GDMA_OSD1_CC4_m21(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD1_CC4_m21_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD1_CC4_get_m21(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD1_CC4_m20_shift                                                      (0)
#define GDMA_OSD1_CC4_m20_mask                                                       (0x00003FFF)
#define GDMA_OSD1_CC4_m20(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD1_CC4_m20_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD1_CC4_get_m20(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD1_CC5                                                                0x1802f22c
#define GDMA_OSD1_CC5_reg_addr                                                       "0xB802F22C"
#define GDMA_OSD1_CC5_reg                                                            0xB802F22C
#define set_GDMA_OSD1_CC5_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_CC5_reg)=data)
#define get_GDMA_OSD1_CC5_reg   (*((volatile unsigned int*) GDMA_OSD1_CC5_reg))
#define GDMA_OSD1_CC5_inst_adr                                                       "0x008B"
#define GDMA_OSD1_CC5_inst                                                           0x008B
#define GDMA_OSD1_CC5_m22_shift                                                      (0)
#define GDMA_OSD1_CC5_m22_mask                                                       (0x00003FFF)
#define GDMA_OSD1_CC5_m22(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD1_CC5_m22_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD1_CC5_get_m22(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD1_CC6                                                                0x1802f230
#define GDMA_OSD1_CC6_reg_addr                                                       "0xB802F230"
#define GDMA_OSD1_CC6_reg                                                            0xB802F230
#define set_GDMA_OSD1_CC6_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_CC6_reg)=data)
#define get_GDMA_OSD1_CC6_reg   (*((volatile unsigned int*) GDMA_OSD1_CC6_reg))
#define GDMA_OSD1_CC6_inst_adr                                                       "0x008C"
#define GDMA_OSD1_CC6_inst                                                           0x008C
#define GDMA_OSD1_CC6_a2_shift                                                       (18)
#define GDMA_OSD1_CC6_a2_mask                                                        (0x07FC0000)
#define GDMA_OSD1_CC6_a2(data)                                                       (0x07FC0000&((data)<<18))
#define GDMA_OSD1_CC6_a2_src(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD1_CC6_get_a2(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD1_CC6_a1_shift                                                       (9)
#define GDMA_OSD1_CC6_a1_mask                                                        (0x0003FE00)
#define GDMA_OSD1_CC6_a1(data)                                                       (0x0003FE00&((data)<<9))
#define GDMA_OSD1_CC6_a1_src(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD1_CC6_get_a1(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD1_CC6_a0_shift                                                       (0)
#define GDMA_OSD1_CC6_a0_mask                                                        (0x000001FF)
#define GDMA_OSD1_CC6_a0(data)                                                       (0x000001FF&((data)<<0))
#define GDMA_OSD1_CC6_a0_src(data)                                                   ((0x000001FF&(data))>>0)
#define GDMA_OSD1_CC6_get_a0(data)                                                   ((0x000001FF&(data))>>0)


#define GDMA_OSD1_CC7                                                                0x1802f234
#define GDMA_OSD1_CC7_reg_addr                                                       "0xB802F234"
#define GDMA_OSD1_CC7_reg                                                            0xB802F234
#define set_GDMA_OSD1_CC7_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_CC7_reg)=data)
#define get_GDMA_OSD1_CC7_reg   (*((volatile unsigned int*) GDMA_OSD1_CC7_reg))
#define GDMA_OSD1_CC7_inst_adr                                                       "0x008D"
#define GDMA_OSD1_CC7_inst                                                           0x008D
#define GDMA_OSD1_CC7_b2_shift                                                       (18)
#define GDMA_OSD1_CC7_b2_mask                                                        (0x07FC0000)
#define GDMA_OSD1_CC7_b2(data)                                                       (0x07FC0000&((data)<<18))
#define GDMA_OSD1_CC7_b2_src(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD1_CC7_get_b2(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD1_CC7_b1_shift                                                       (9)
#define GDMA_OSD1_CC7_b1_mask                                                        (0x0003FE00)
#define GDMA_OSD1_CC7_b1(data)                                                       (0x0003FE00&((data)<<9))
#define GDMA_OSD1_CC7_b1_src(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD1_CC7_get_b1(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD1_CC7_b0_shift                                                       (0)
#define GDMA_OSD1_CC7_b0_mask                                                        (0x000001FF)
#define GDMA_OSD1_CC7_b0(data)                                                       (0x000001FF&((data)<<0))
#define GDMA_OSD1_CC7_b0_src(data)                                                   ((0x000001FF&(data))>>0)
#define GDMA_OSD1_CC7_get_b0(data)                                                   ((0x000001FF&(data))>>0)


#define GDMA_OSD1_CLEAR1                                                             0x1802f280
#define GDMA_OSD1_CLEAR1_reg_addr                                                    "0xB802F280"
#define GDMA_OSD1_CLEAR1_reg                                                         0xB802F280
#define set_GDMA_OSD1_CLEAR1_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_CLEAR1_reg)=data)
#define get_GDMA_OSD1_CLEAR1_reg   (*((volatile unsigned int*) GDMA_OSD1_CLEAR1_reg))
#define GDMA_OSD1_CLEAR1_inst_adr                                                    "0x00A0"
#define GDMA_OSD1_CLEAR1_inst                                                        0x00A0
#define GDMA_OSD1_CLEAR1_x_sta_shift                                                 (16)
#define GDMA_OSD1_CLEAR1_x_sta_mask                                                  (0x1FFF0000)
#define GDMA_OSD1_CLEAR1_x_sta(data)                                                 (0x1FFF0000&((data)<<16))
#define GDMA_OSD1_CLEAR1_x_sta_src(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD1_CLEAR1_get_x_sta(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD1_CLEAR1_x_end_shift                                                 (0)
#define GDMA_OSD1_CLEAR1_x_end_mask                                                  (0x00001FFF)
#define GDMA_OSD1_CLEAR1_x_end(data)                                                 (0x00001FFF&((data)<<0))
#define GDMA_OSD1_CLEAR1_x_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define GDMA_OSD1_CLEAR1_get_x_end(data)                                             ((0x00001FFF&(data))>>0)


#define GDMA_OSD1_CLEAR2                                                             0x1802f284
#define GDMA_OSD1_CLEAR2_reg_addr                                                    "0xB802F284"
#define GDMA_OSD1_CLEAR2_reg                                                         0xB802F284
#define set_GDMA_OSD1_CLEAR2_reg(data)   (*((volatile unsigned int*) GDMA_OSD1_CLEAR2_reg)=data)
#define get_GDMA_OSD1_CLEAR2_reg   (*((volatile unsigned int*) GDMA_OSD1_CLEAR2_reg))
#define GDMA_OSD1_CLEAR2_inst_adr                                                    "0x00A1"
#define GDMA_OSD1_CLEAR2_inst                                                        0x00A1
#define GDMA_OSD1_CLEAR2_y_sta_shift                                                 (16)
#define GDMA_OSD1_CLEAR2_y_sta_mask                                                  (0x1FFF0000)
#define GDMA_OSD1_CLEAR2_y_sta(data)                                                 (0x1FFF0000&((data)<<16))
#define GDMA_OSD1_CLEAR2_y_sta_src(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD1_CLEAR2_get_y_sta(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD1_CLEAR2_y_end_shift                                                 (0)
#define GDMA_OSD1_CLEAR2_y_end_mask                                                  (0x00001FFF)
#define GDMA_OSD1_CLEAR2_y_end(data)                                                 (0x00001FFF&((data)<<0))
#define GDMA_OSD1_CLEAR2_y_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define GDMA_OSD1_CLEAR2_get_y_end(data)                                             ((0x00001FFF&(data))>>0)


#define GDMA_OSD2_CTRL                                                               0x1802f300
#define GDMA_OSD2_CTRL_reg_addr                                                      "0xB802F300"
#define GDMA_OSD2_CTRL_reg                                                           0xB802F300
#define set_GDMA_OSD2_CTRL_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_CTRL_reg)=data)
#define get_GDMA_OSD2_CTRL_reg   (*((volatile unsigned int*) GDMA_OSD2_CTRL_reg))
#define GDMA_OSD2_CTRL_inst_adr                                                      "0x00C0"
#define GDMA_OSD2_CTRL_inst                                                          0x00C0
#define GDMA_OSD2_CTRL_d3_mode_shift                                                 (9)
#define GDMA_OSD2_CTRL_d3_mode_mask                                                  (0x00000200)
#define GDMA_OSD2_CTRL_d3_mode(data)                                                 (0x00000200&((data)<<9))
#define GDMA_OSD2_CTRL_d3_mode_src(data)                                             ((0x00000200&(data))>>9)
#define GDMA_OSD2_CTRL_get_d3_mode(data)                                             ((0x00000200&(data))>>9)
#define GDMA_OSD2_CTRL_rotate_shift                                                  (8)
#define GDMA_OSD2_CTRL_rotate_mask                                                   (0x00000100)
#define GDMA_OSD2_CTRL_rotate(data)                                                  (0x00000100&((data)<<8))
#define GDMA_OSD2_CTRL_rotate_src(data)                                              ((0x00000100&(data))>>8)
#define GDMA_OSD2_CTRL_get_rotate(data)                                              ((0x00000100&(data))>>8)
#define GDMA_OSD2_CTRL_osd2_en_shift                                                 (1)
#define GDMA_OSD2_CTRL_osd2_en_mask                                                  (0x00000002)
#define GDMA_OSD2_CTRL_osd2_en(data)                                                 (0x00000002&((data)<<1))
#define GDMA_OSD2_CTRL_osd2_en_src(data)                                             ((0x00000002&(data))>>1)
#define GDMA_OSD2_CTRL_get_osd2_en(data)                                             ((0x00000002&(data))>>1)
#define GDMA_OSD2_CTRL_write_data_shift                                              (0)
#define GDMA_OSD2_CTRL_write_data_mask                                               (0x00000001)
#define GDMA_OSD2_CTRL_write_data(data)                                              (0x00000001&((data)<<0))
#define GDMA_OSD2_CTRL_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define GDMA_OSD2_CTRL_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define GDMA_OSD2                                                                    0x1802f304
#define GDMA_OSD2_reg_addr                                                           "0xB802F304"
#define GDMA_OSD2_reg                                                                0xB802F304
#define set_GDMA_OSD2_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_reg)=data)
#define get_GDMA_OSD2_reg   (*((volatile unsigned int*) GDMA_OSD2_reg))
#define GDMA_OSD2_inst_adr                                                           "0x00C1"
#define GDMA_OSD2_inst                                                               0x00C1
#define GDMA_OSD2_wi_endian_shift                                                    (25)
#define GDMA_OSD2_wi_endian_mask                                                     (0x02000000)
#define GDMA_OSD2_wi_endian(data)                                                    (0x02000000&((data)<<25))
#define GDMA_OSD2_wi_endian_src(data)                                                ((0x02000000&(data))>>25)
#define GDMA_OSD2_get_wi_endian(data)                                                ((0x02000000&(data))>>25)
#define GDMA_OSD2_rgb_out_shift                                                      (24)
#define GDMA_OSD2_rgb_out_mask                                                       (0x01000000)
#define GDMA_OSD2_rgb_out(data)                                                      (0x01000000&((data)<<24))
#define GDMA_OSD2_rgb_out_src(data)                                                  ((0x01000000&(data))>>24)
#define GDMA_OSD2_get_rgb_out(data)                                                  ((0x01000000&(data))>>24)
#define GDMA_OSD2_osd_shift                                                          (16)
#define GDMA_OSD2_osd_mask                                                           (0x00010000)
#define GDMA_OSD2_osd(data)                                                          (0x00010000&((data)<<16))
#define GDMA_OSD2_osd_src(data)                                                      ((0x00010000&(data))>>16)
#define GDMA_OSD2_get_osd(data)                                                      ((0x00010000&(data))>>16)
#define GDMA_OSD2_clear_region_en_shift                                              (1)
#define GDMA_OSD2_clear_region_en_mask                                               (0x00000002)
#define GDMA_OSD2_clear_region_en(data)                                              (0x00000002&((data)<<1))
#define GDMA_OSD2_clear_region_en_src(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD2_get_clear_region_en(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD2_write_data_shift                                                   (0)
#define GDMA_OSD2_write_data_mask                                                    (0x00000001)
#define GDMA_OSD2_write_data(data)                                                   (0x00000001&((data)<<0))
#define GDMA_OSD2_write_data_src(data)                                               ((0x00000001&(data))>>0)
#define GDMA_OSD2_get_write_data(data)                                               ((0x00000001&(data))>>0)


#define GDMA_OSD2_START                                                              0x1802f308
#define GDMA_OSD2_START_reg_addr                                                     "0xB802F308"
#define GDMA_OSD2_START_reg                                                          0xB802F308
#define set_GDMA_OSD2_START_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_START_reg)=data)
#define get_GDMA_OSD2_START_reg   (*((volatile unsigned int*) GDMA_OSD2_START_reg))
#define GDMA_OSD2_START_inst_adr                                                     "0x00C2"
#define GDMA_OSD2_START_inst                                                         0x00C2
#define GDMA_OSD2_START_th_shift                                                     (0)
#define GDMA_OSD2_START_th_mask                                                      (0x00001FFF)
#define GDMA_OSD2_START_th(data)                                                     (0x00001FFF&((data)<<0))
#define GDMA_OSD2_START_th_src(data)                                                 ((0x00001FFF&(data))>>0)
#define GDMA_OSD2_START_get_th(data)                                                 ((0x00001FFF&(data))>>0)


#define GDMA_OSD2_VBI_END                                                            0x1802f30c
#define GDMA_OSD2_VBI_END_reg_addr                                                   "0xB802F30C"
#define GDMA_OSD2_VBI_END_reg                                                        0xB802F30C
#define set_GDMA_OSD2_VBI_END_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_VBI_END_reg)=data)
#define get_GDMA_OSD2_VBI_END_reg   (*((volatile unsigned int*) GDMA_OSD2_VBI_END_reg))
#define GDMA_OSD2_VBI_END_inst_adr                                                   "0x00C3"
#define GDMA_OSD2_VBI_END_inst                                                       0x00C3
#define GDMA_OSD2_VBI_END_th_shift                                                   (0)
#define GDMA_OSD2_VBI_END_th_mask                                                    (0x00001FFF)
#define GDMA_OSD2_VBI_END_th(data)                                                   (0x00001FFF&((data)<<0))
#define GDMA_OSD2_VBI_END_th_src(data)                                               ((0x00001FFF&(data))>>0)
#define GDMA_OSD2_VBI_END_get_th(data)                                               ((0x00001FFF&(data))>>0)


#define GDMA_OSD2_WI                                                                 0x1802f310
#define GDMA_OSD2_WI_reg_addr                                                        "0xB802F310"
#define GDMA_OSD2_WI_reg                                                             0xB802F310
#define set_GDMA_OSD2_WI_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_WI_reg)=data)
#define get_GDMA_OSD2_WI_reg   (*((volatile unsigned int*) GDMA_OSD2_WI_reg))
#define GDMA_OSD2_WI_inst_adr                                                        "0x00C4"
#define GDMA_OSD2_WI_inst                                                            0x00C4
#define GDMA_OSD2_WI_addr_shift                                                      (0)
#define GDMA_OSD2_WI_addr_mask                                                       (0xFFFFFFFF)
#define GDMA_OSD2_WI_addr(data)                                                      (0xFFFFFFFF&((data)<<0))
#define GDMA_OSD2_WI_addr_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define GDMA_OSD2_WI_get_addr(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define GDMA_OSD2_WI_3D                                                              0x1802f314
#define GDMA_OSD2_WI_3D_reg_addr                                                     "0xB802F314"
#define GDMA_OSD2_WI_3D_reg                                                          0xB802F314
#define set_GDMA_OSD2_WI_3D_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_WI_3D_reg)=data)
#define get_GDMA_OSD2_WI_3D_reg   (*((volatile unsigned int*) GDMA_OSD2_WI_3D_reg))
#define GDMA_OSD2_WI_3D_inst_adr                                                     "0x00C5"
#define GDMA_OSD2_WI_3D_inst                                                         0x00C5
#define GDMA_OSD2_WI_3D_addr_shift                                                   (0)
#define GDMA_OSD2_WI_3D_addr_mask                                                    (0xFFFFFFFF)
#define GDMA_OSD2_WI_3D_addr(data)                                                   (0xFFFFFFFF&((data)<<0))
#define GDMA_OSD2_WI_3D_addr_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define GDMA_OSD2_WI_3D_get_addr(data)                                               ((0xFFFFFFFF&(data))>>0)


#define GDMA_OSD2_SIZE                                                               0x1802f318
#define GDMA_OSD2_SIZE_reg_addr                                                      "0xB802F318"
#define GDMA_OSD2_SIZE_reg                                                           0xB802F318
#define set_GDMA_OSD2_SIZE_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_SIZE_reg)=data)
#define get_GDMA_OSD2_SIZE_reg   (*((volatile unsigned int*) GDMA_OSD2_SIZE_reg))
#define GDMA_OSD2_SIZE_inst_adr                                                      "0x00C6"
#define GDMA_OSD2_SIZE_inst                                                          0x00C6
#define GDMA_OSD2_SIZE_w_shift                                                       (16)
#define GDMA_OSD2_SIZE_w_mask                                                        (0x1FFF0000)
#define GDMA_OSD2_SIZE_w(data)                                                       (0x1FFF0000&((data)<<16))
#define GDMA_OSD2_SIZE_w_src(data)                                                   ((0x1FFF0000&(data))>>16)
#define GDMA_OSD2_SIZE_get_w(data)                                                   ((0x1FFF0000&(data))>>16)
#define GDMA_OSD2_SIZE_h_shift                                                       (0)
#define GDMA_OSD2_SIZE_h_mask                                                        (0x00001FFF)
#define GDMA_OSD2_SIZE_h(data)                                                       (0x00001FFF&((data)<<0))
#define GDMA_OSD2_SIZE_h_src(data)                                                   ((0x00001FFF&(data))>>0)
#define GDMA_OSD2_SIZE_get_h(data)                                                   ((0x00001FFF&(data))>>0)


#define GDMA_OSD2_CC1                                                                0x1802f31c
#define GDMA_OSD2_CC1_reg_addr                                                       "0xB802F31C"
#define GDMA_OSD2_CC1_reg                                                            0xB802F31C
#define set_GDMA_OSD2_CC1_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_CC1_reg)=data)
#define get_GDMA_OSD2_CC1_reg   (*((volatile unsigned int*) GDMA_OSD2_CC1_reg))
#define GDMA_OSD2_CC1_inst_adr                                                       "0x00C7"
#define GDMA_OSD2_CC1_inst                                                           0x00C7
#define GDMA_OSD2_CC1_m01_shift                                                      (16)
#define GDMA_OSD2_CC1_m01_mask                                                       (0x3FFF0000)
#define GDMA_OSD2_CC1_m01(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD2_CC1_m01_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD2_CC1_get_m01(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD2_CC1_m00_shift                                                      (0)
#define GDMA_OSD2_CC1_m00_mask                                                       (0x00003FFF)
#define GDMA_OSD2_CC1_m00(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD2_CC1_m00_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD2_CC1_get_m00(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD2_CC2                                                                0x1802f320
#define GDMA_OSD2_CC2_reg_addr                                                       "0xB802F320"
#define GDMA_OSD2_CC2_reg                                                            0xB802F320
#define set_GDMA_OSD2_CC2_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_CC2_reg)=data)
#define get_GDMA_OSD2_CC2_reg   (*((volatile unsigned int*) GDMA_OSD2_CC2_reg))
#define GDMA_OSD2_CC2_inst_adr                                                       "0x00C8"
#define GDMA_OSD2_CC2_inst                                                           0x00C8
#define GDMA_OSD2_CC2_m10_shift                                                      (16)
#define GDMA_OSD2_CC2_m10_mask                                                       (0x3FFF0000)
#define GDMA_OSD2_CC2_m10(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD2_CC2_m10_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD2_CC2_get_m10(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD2_CC2_m02_shift                                                      (0)
#define GDMA_OSD2_CC2_m02_mask                                                       (0x00003FFF)
#define GDMA_OSD2_CC2_m02(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD2_CC2_m02_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD2_CC2_get_m02(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD2_CC3                                                                0x1802f324
#define GDMA_OSD2_CC3_reg_addr                                                       "0xB802F324"
#define GDMA_OSD2_CC3_reg                                                            0xB802F324
#define set_GDMA_OSD2_CC3_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_CC3_reg)=data)
#define get_GDMA_OSD2_CC3_reg   (*((volatile unsigned int*) GDMA_OSD2_CC3_reg))
#define GDMA_OSD2_CC3_inst_adr                                                       "0x00C9"
#define GDMA_OSD2_CC3_inst                                                           0x00C9
#define GDMA_OSD2_CC3_m12_shift                                                      (16)
#define GDMA_OSD2_CC3_m12_mask                                                       (0x3FFF0000)
#define GDMA_OSD2_CC3_m12(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD2_CC3_m12_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD2_CC3_get_m12(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD2_CC3_m11_shift                                                      (0)
#define GDMA_OSD2_CC3_m11_mask                                                       (0x00003FFF)
#define GDMA_OSD2_CC3_m11(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD2_CC3_m11_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD2_CC3_get_m11(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD2_CC4                                                                0x1802f328
#define GDMA_OSD2_CC4_reg_addr                                                       "0xB802F328"
#define GDMA_OSD2_CC4_reg                                                            0xB802F328
#define set_GDMA_OSD2_CC4_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_CC4_reg)=data)
#define get_GDMA_OSD2_CC4_reg   (*((volatile unsigned int*) GDMA_OSD2_CC4_reg))
#define GDMA_OSD2_CC4_inst_adr                                                       "0x00CA"
#define GDMA_OSD2_CC4_inst                                                           0x00CA
#define GDMA_OSD2_CC4_m21_shift                                                      (16)
#define GDMA_OSD2_CC4_m21_mask                                                       (0x3FFF0000)
#define GDMA_OSD2_CC4_m21(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD2_CC4_m21_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD2_CC4_get_m21(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD2_CC4_m20_shift                                                      (0)
#define GDMA_OSD2_CC4_m20_mask                                                       (0x00003FFF)
#define GDMA_OSD2_CC4_m20(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD2_CC4_m20_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD2_CC4_get_m20(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD2_CC5                                                                0x1802f32c
#define GDMA_OSD2_CC5_reg_addr                                                       "0xB802F32C"
#define GDMA_OSD2_CC5_reg                                                            0xB802F32C
#define set_GDMA_OSD2_CC5_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_CC5_reg)=data)
#define get_GDMA_OSD2_CC5_reg   (*((volatile unsigned int*) GDMA_OSD2_CC5_reg))
#define GDMA_OSD2_CC5_inst_adr                                                       "0x00CB"
#define GDMA_OSD2_CC5_inst                                                           0x00CB
#define GDMA_OSD2_CC5_m22_shift                                                      (0)
#define GDMA_OSD2_CC5_m22_mask                                                       (0x00003FFF)
#define GDMA_OSD2_CC5_m22(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD2_CC5_m22_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD2_CC5_get_m22(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD2_CC6                                                                0x1802f330
#define GDMA_OSD2_CC6_reg_addr                                                       "0xB802F330"
#define GDMA_OSD2_CC6_reg                                                            0xB802F330
#define set_GDMA_OSD2_CC6_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_CC6_reg)=data)
#define get_GDMA_OSD2_CC6_reg   (*((volatile unsigned int*) GDMA_OSD2_CC6_reg))
#define GDMA_OSD2_CC6_inst_adr                                                       "0x00CC"
#define GDMA_OSD2_CC6_inst                                                           0x00CC
#define GDMA_OSD2_CC6_a2_shift                                                       (18)
#define GDMA_OSD2_CC6_a2_mask                                                        (0x07FC0000)
#define GDMA_OSD2_CC6_a2(data)                                                       (0x07FC0000&((data)<<18))
#define GDMA_OSD2_CC6_a2_src(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD2_CC6_get_a2(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD2_CC6_a1_shift                                                       (9)
#define GDMA_OSD2_CC6_a1_mask                                                        (0x0003FE00)
#define GDMA_OSD2_CC6_a1(data)                                                       (0x0003FE00&((data)<<9))
#define GDMA_OSD2_CC6_a1_src(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD2_CC6_get_a1(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD2_CC6_a0_shift                                                       (0)
#define GDMA_OSD2_CC6_a0_mask                                                        (0x000001FF)
#define GDMA_OSD2_CC6_a0(data)                                                       (0x000001FF&((data)<<0))
#define GDMA_OSD2_CC6_a0_src(data)                                                   ((0x000001FF&(data))>>0)
#define GDMA_OSD2_CC6_get_a0(data)                                                   ((0x000001FF&(data))>>0)


#define GDMA_OSD2_CC7                                                                0x1802f334
#define GDMA_OSD2_CC7_reg_addr                                                       "0xB802F334"
#define GDMA_OSD2_CC7_reg                                                            0xB802F334
#define set_GDMA_OSD2_CC7_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_CC7_reg)=data)
#define get_GDMA_OSD2_CC7_reg   (*((volatile unsigned int*) GDMA_OSD2_CC7_reg))
#define GDMA_OSD2_CC7_inst_adr                                                       "0x00CD"
#define GDMA_OSD2_CC7_inst                                                           0x00CD
#define GDMA_OSD2_CC7_b2_shift                                                       (18)
#define GDMA_OSD2_CC7_b2_mask                                                        (0x07FC0000)
#define GDMA_OSD2_CC7_b2(data)                                                       (0x07FC0000&((data)<<18))
#define GDMA_OSD2_CC7_b2_src(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD2_CC7_get_b2(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD2_CC7_b1_shift                                                       (9)
#define GDMA_OSD2_CC7_b1_mask                                                        (0x0003FE00)
#define GDMA_OSD2_CC7_b1(data)                                                       (0x0003FE00&((data)<<9))
#define GDMA_OSD2_CC7_b1_src(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD2_CC7_get_b1(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD2_CC7_b0_shift                                                       (0)
#define GDMA_OSD2_CC7_b0_mask                                                        (0x000001FF)
#define GDMA_OSD2_CC7_b0(data)                                                       (0x000001FF&((data)<<0))
#define GDMA_OSD2_CC7_b0_src(data)                                                   ((0x000001FF&(data))>>0)
#define GDMA_OSD2_CC7_get_b0(data)                                                   ((0x000001FF&(data))>>0)


#define GDMA_OSD2_CLEAR1                                                             0x1802f380
#define GDMA_OSD2_CLEAR1_reg_addr                                                    "0xB802F380"
#define GDMA_OSD2_CLEAR1_reg                                                         0xB802F380
#define set_GDMA_OSD2_CLEAR1_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_CLEAR1_reg)=data)
#define get_GDMA_OSD2_CLEAR1_reg   (*((volatile unsigned int*) GDMA_OSD2_CLEAR1_reg))
#define GDMA_OSD2_CLEAR1_inst_adr                                                    "0x00E0"
#define GDMA_OSD2_CLEAR1_inst                                                        0x00E0
#define GDMA_OSD2_CLEAR1_x_sta_shift                                                 (16)
#define GDMA_OSD2_CLEAR1_x_sta_mask                                                  (0x1FFF0000)
#define GDMA_OSD2_CLEAR1_x_sta(data)                                                 (0x1FFF0000&((data)<<16))
#define GDMA_OSD2_CLEAR1_x_sta_src(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD2_CLEAR1_get_x_sta(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD2_CLEAR1_x_end_shift                                                 (0)
#define GDMA_OSD2_CLEAR1_x_end_mask                                                  (0x00001FFF)
#define GDMA_OSD2_CLEAR1_x_end(data)                                                 (0x00001FFF&((data)<<0))
#define GDMA_OSD2_CLEAR1_x_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define GDMA_OSD2_CLEAR1_get_x_end(data)                                             ((0x00001FFF&(data))>>0)


#define GDMA_OSD2_CLEAR2                                                             0x1802f384
#define GDMA_OSD2_CLEAR2_reg_addr                                                    "0xB802F384"
#define GDMA_OSD2_CLEAR2_reg                                                         0xB802F384
#define set_GDMA_OSD2_CLEAR2_reg(data)   (*((volatile unsigned int*) GDMA_OSD2_CLEAR2_reg)=data)
#define get_GDMA_OSD2_CLEAR2_reg   (*((volatile unsigned int*) GDMA_OSD2_CLEAR2_reg))
#define GDMA_OSD2_CLEAR2_inst_adr                                                    "0x00E1"
#define GDMA_OSD2_CLEAR2_inst                                                        0x00E1
#define GDMA_OSD2_CLEAR2_y_sta_shift                                                 (16)
#define GDMA_OSD2_CLEAR2_y_sta_mask                                                  (0x1FFF0000)
#define GDMA_OSD2_CLEAR2_y_sta(data)                                                 (0x1FFF0000&((data)<<16))
#define GDMA_OSD2_CLEAR2_y_sta_src(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD2_CLEAR2_get_y_sta(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD2_CLEAR2_y_end_shift                                                 (0)
#define GDMA_OSD2_CLEAR2_y_end_mask                                                  (0x00001FFF)
#define GDMA_OSD2_CLEAR2_y_end(data)                                                 (0x00001FFF&((data)<<0))
#define GDMA_OSD2_CLEAR2_y_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define GDMA_OSD2_CLEAR2_get_y_end(data)                                             ((0x00001FFF&(data))>>0)


#define GDMA_OSD3_CTRL                                                               0x1802f400
#define GDMA_OSD3_CTRL_reg_addr                                                      "0xB802F400"
#define GDMA_OSD3_CTRL_reg                                                           0xB802F400
#define set_GDMA_OSD3_CTRL_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_CTRL_reg)=data)
#define get_GDMA_OSD3_CTRL_reg   (*((volatile unsigned int*) GDMA_OSD3_CTRL_reg))
#define GDMA_OSD3_CTRL_inst_adr                                                      "0x0000"
#define GDMA_OSD3_CTRL_inst                                                          0x0000
#define GDMA_OSD3_CTRL_d3_mode_shift                                                 (9)
#define GDMA_OSD3_CTRL_d3_mode_mask                                                  (0x00000200)
#define GDMA_OSD3_CTRL_d3_mode(data)                                                 (0x00000200&((data)<<9))
#define GDMA_OSD3_CTRL_d3_mode_src(data)                                             ((0x00000200&(data))>>9)
#define GDMA_OSD3_CTRL_get_d3_mode(data)                                             ((0x00000200&(data))>>9)
#define GDMA_OSD3_CTRL_rotate_shift                                                  (8)
#define GDMA_OSD3_CTRL_rotate_mask                                                   (0x00000100)
#define GDMA_OSD3_CTRL_rotate(data)                                                  (0x00000100&((data)<<8))
#define GDMA_OSD3_CTRL_rotate_src(data)                                              ((0x00000100&(data))>>8)
#define GDMA_OSD3_CTRL_get_rotate(data)                                              ((0x00000100&(data))>>8)
#define GDMA_OSD3_CTRL_osd3_en_shift                                                 (1)
#define GDMA_OSD3_CTRL_osd3_en_mask                                                  (0x00000002)
#define GDMA_OSD3_CTRL_osd3_en(data)                                                 (0x00000002&((data)<<1))
#define GDMA_OSD3_CTRL_osd3_en_src(data)                                             ((0x00000002&(data))>>1)
#define GDMA_OSD3_CTRL_get_osd3_en(data)                                             ((0x00000002&(data))>>1)
#define GDMA_OSD3_CTRL_write_data_shift                                              (0)
#define GDMA_OSD3_CTRL_write_data_mask                                               (0x00000001)
#define GDMA_OSD3_CTRL_write_data(data)                                              (0x00000001&((data)<<0))
#define GDMA_OSD3_CTRL_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define GDMA_OSD3_CTRL_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define GDMA_OSD3                                                                    0x1802f404
#define GDMA_OSD3_reg_addr                                                           "0xB802F404"
#define GDMA_OSD3_reg                                                                0xB802F404
#define set_GDMA_OSD3_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_reg)=data)
#define get_GDMA_OSD3_reg   (*((volatile unsigned int*) GDMA_OSD3_reg))
#define GDMA_OSD3_inst_adr                                                           "0x0001"
#define GDMA_OSD3_inst                                                               0x0001
#define GDMA_OSD3_wi_endian_shift                                                    (25)
#define GDMA_OSD3_wi_endian_mask                                                     (0x02000000)
#define GDMA_OSD3_wi_endian(data)                                                    (0x02000000&((data)<<25))
#define GDMA_OSD3_wi_endian_src(data)                                                ((0x02000000&(data))>>25)
#define GDMA_OSD3_get_wi_endian(data)                                                ((0x02000000&(data))>>25)
#define GDMA_OSD3_rgb_out_shift                                                      (24)
#define GDMA_OSD3_rgb_out_mask                                                       (0x01000000)
#define GDMA_OSD3_rgb_out(data)                                                      (0x01000000&((data)<<24))
#define GDMA_OSD3_rgb_out_src(data)                                                  ((0x01000000&(data))>>24)
#define GDMA_OSD3_get_rgb_out(data)                                                  ((0x01000000&(data))>>24)
#define GDMA_OSD3_osd_shift                                                          (16)
#define GDMA_OSD3_osd_mask                                                           (0x00010000)
#define GDMA_OSD3_osd(data)                                                          (0x00010000&((data)<<16))
#define GDMA_OSD3_osd_src(data)                                                      ((0x00010000&(data))>>16)
#define GDMA_OSD3_get_osd(data)                                                      ((0x00010000&(data))>>16)
#define GDMA_OSD3_clear_region_en_shift                                              (1)
#define GDMA_OSD3_clear_region_en_mask                                               (0x00000002)
#define GDMA_OSD3_clear_region_en(data)                                              (0x00000002&((data)<<1))
#define GDMA_OSD3_clear_region_en_src(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD3_get_clear_region_en(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD3_write_data_shift                                                   (0)
#define GDMA_OSD3_write_data_mask                                                    (0x00000001)
#define GDMA_OSD3_write_data(data)                                                   (0x00000001&((data)<<0))
#define GDMA_OSD3_write_data_src(data)                                               ((0x00000001&(data))>>0)
#define GDMA_OSD3_get_write_data(data)                                               ((0x00000001&(data))>>0)


#define GDMA_OSD3_START                                                              0x1802f408
#define GDMA_OSD3_START_reg_addr                                                     "0xB802F408"
#define GDMA_OSD3_START_reg                                                          0xB802F408
#define set_GDMA_OSD3_START_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_START_reg)=data)
#define get_GDMA_OSD3_START_reg   (*((volatile unsigned int*) GDMA_OSD3_START_reg))
#define GDMA_OSD3_START_inst_adr                                                     "0x0002"
#define GDMA_OSD3_START_inst                                                         0x0002
#define GDMA_OSD3_START_th_shift                                                     (0)
#define GDMA_OSD3_START_th_mask                                                      (0x00001FFF)
#define GDMA_OSD3_START_th(data)                                                     (0x00001FFF&((data)<<0))
#define GDMA_OSD3_START_th_src(data)                                                 ((0x00001FFF&(data))>>0)
#define GDMA_OSD3_START_get_th(data)                                                 ((0x00001FFF&(data))>>0)


#define GDMA_OSD3_VBI_END                                                            0x1802f40c
#define GDMA_OSD3_VBI_END_reg_addr                                                   "0xB802F40C"
#define GDMA_OSD3_VBI_END_reg                                                        0xB802F40C
#define set_GDMA_OSD3_VBI_END_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_VBI_END_reg)=data)
#define get_GDMA_OSD3_VBI_END_reg   (*((volatile unsigned int*) GDMA_OSD3_VBI_END_reg))
#define GDMA_OSD3_VBI_END_inst_adr                                                   "0x0003"
#define GDMA_OSD3_VBI_END_inst                                                       0x0003
#define GDMA_OSD3_VBI_END_th_shift                                                   (0)
#define GDMA_OSD3_VBI_END_th_mask                                                    (0x00001FFF)
#define GDMA_OSD3_VBI_END_th(data)                                                   (0x00001FFF&((data)<<0))
#define GDMA_OSD3_VBI_END_th_src(data)                                               ((0x00001FFF&(data))>>0)
#define GDMA_OSD3_VBI_END_get_th(data)                                               ((0x00001FFF&(data))>>0)


#define GDMA_OSD3_WI                                                                 0x1802f410
#define GDMA_OSD3_WI_reg_addr                                                        "0xB802F410"
#define GDMA_OSD3_WI_reg                                                             0xB802F410
#define set_GDMA_OSD3_WI_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_WI_reg)=data)
#define get_GDMA_OSD3_WI_reg   (*((volatile unsigned int*) GDMA_OSD3_WI_reg))
#define GDMA_OSD3_WI_inst_adr                                                        "0x0004"
#define GDMA_OSD3_WI_inst                                                            0x0004
#define GDMA_OSD3_WI_addr_shift                                                      (0)
#define GDMA_OSD3_WI_addr_mask                                                       (0xFFFFFFFF)
#define GDMA_OSD3_WI_addr(data)                                                      (0xFFFFFFFF&((data)<<0))
#define GDMA_OSD3_WI_addr_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define GDMA_OSD3_WI_get_addr(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define GDMA_OSD3_WI_3D                                                              0x1802f414
#define GDMA_OSD3_WI_3D_reg_addr                                                     "0xB802F414"
#define GDMA_OSD3_WI_3D_reg                                                          0xB802F414
#define set_GDMA_OSD3_WI_3D_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_WI_3D_reg)=data)
#define get_GDMA_OSD3_WI_3D_reg   (*((volatile unsigned int*) GDMA_OSD3_WI_3D_reg))
#define GDMA_OSD3_WI_3D_inst_adr                                                     "0x0005"
#define GDMA_OSD3_WI_3D_inst                                                         0x0005
#define GDMA_OSD3_WI_3D_addr_shift                                                   (0)
#define GDMA_OSD3_WI_3D_addr_mask                                                    (0xFFFFFFFF)
#define GDMA_OSD3_WI_3D_addr(data)                                                   (0xFFFFFFFF&((data)<<0))
#define GDMA_OSD3_WI_3D_addr_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define GDMA_OSD3_WI_3D_get_addr(data)                                               ((0xFFFFFFFF&(data))>>0)


#define GDMA_OSD3_SIZE                                                               0x1802f418
#define GDMA_OSD3_SIZE_reg_addr                                                      "0xB802F418"
#define GDMA_OSD3_SIZE_reg                                                           0xB802F418
#define set_GDMA_OSD3_SIZE_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_SIZE_reg)=data)
#define get_GDMA_OSD3_SIZE_reg   (*((volatile unsigned int*) GDMA_OSD3_SIZE_reg))
#define GDMA_OSD3_SIZE_inst_adr                                                      "0x0006"
#define GDMA_OSD3_SIZE_inst                                                          0x0006
#define GDMA_OSD3_SIZE_w_shift                                                       (16)
#define GDMA_OSD3_SIZE_w_mask                                                        (0x1FFF0000)
#define GDMA_OSD3_SIZE_w(data)                                                       (0x1FFF0000&((data)<<16))
#define GDMA_OSD3_SIZE_w_src(data)                                                   ((0x1FFF0000&(data))>>16)
#define GDMA_OSD3_SIZE_get_w(data)                                                   ((0x1FFF0000&(data))>>16)
#define GDMA_OSD3_SIZE_h_shift                                                       (0)
#define GDMA_OSD3_SIZE_h_mask                                                        (0x00001FFF)
#define GDMA_OSD3_SIZE_h(data)                                                       (0x00001FFF&((data)<<0))
#define GDMA_OSD3_SIZE_h_src(data)                                                   ((0x00001FFF&(data))>>0)
#define GDMA_OSD3_SIZE_get_h(data)                                                   ((0x00001FFF&(data))>>0)


#define GDMA_OSD3_CC1                                                                0x1802f41c
#define GDMA_OSD3_CC1_reg_addr                                                       "0xB802F41C"
#define GDMA_OSD3_CC1_reg                                                            0xB802F41C
#define set_GDMA_OSD3_CC1_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_CC1_reg)=data)
#define get_GDMA_OSD3_CC1_reg   (*((volatile unsigned int*) GDMA_OSD3_CC1_reg))
#define GDMA_OSD3_CC1_inst_adr                                                       "0x0007"
#define GDMA_OSD3_CC1_inst                                                           0x0007
#define GDMA_OSD3_CC1_m01_shift                                                      (16)
#define GDMA_OSD3_CC1_m01_mask                                                       (0x3FFF0000)
#define GDMA_OSD3_CC1_m01(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD3_CC1_m01_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD3_CC1_get_m01(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD3_CC1_m00_shift                                                      (0)
#define GDMA_OSD3_CC1_m00_mask                                                       (0x00003FFF)
#define GDMA_OSD3_CC1_m00(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD3_CC1_m00_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD3_CC1_get_m00(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD3_CC2                                                                0x1802f420
#define GDMA_OSD3_CC2_reg_addr                                                       "0xB802F420"
#define GDMA_OSD3_CC2_reg                                                            0xB802F420
#define set_GDMA_OSD3_CC2_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_CC2_reg)=data)
#define get_GDMA_OSD3_CC2_reg   (*((volatile unsigned int*) GDMA_OSD3_CC2_reg))
#define GDMA_OSD3_CC2_inst_adr                                                       "0x0008"
#define GDMA_OSD3_CC2_inst                                                           0x0008
#define GDMA_OSD3_CC2_m10_shift                                                      (16)
#define GDMA_OSD3_CC2_m10_mask                                                       (0x3FFF0000)
#define GDMA_OSD3_CC2_m10(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD3_CC2_m10_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD3_CC2_get_m10(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD3_CC2_m02_shift                                                      (0)
#define GDMA_OSD3_CC2_m02_mask                                                       (0x00003FFF)
#define GDMA_OSD3_CC2_m02(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD3_CC2_m02_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD3_CC2_get_m02(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD3_CC3                                                                0x1802f424
#define GDMA_OSD3_CC3_reg_addr                                                       "0xB802F424"
#define GDMA_OSD3_CC3_reg                                                            0xB802F424
#define set_GDMA_OSD3_CC3_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_CC3_reg)=data)
#define get_GDMA_OSD3_CC3_reg   (*((volatile unsigned int*) GDMA_OSD3_CC3_reg))
#define GDMA_OSD3_CC3_inst_adr                                                       "0x0009"
#define GDMA_OSD3_CC3_inst                                                           0x0009
#define GDMA_OSD3_CC3_m12_shift                                                      (16)
#define GDMA_OSD3_CC3_m12_mask                                                       (0x3FFF0000)
#define GDMA_OSD3_CC3_m12(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD3_CC3_m12_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD3_CC3_get_m12(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD3_CC3_m11_shift                                                      (0)
#define GDMA_OSD3_CC3_m11_mask                                                       (0x00003FFF)
#define GDMA_OSD3_CC3_m11(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD3_CC3_m11_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD3_CC3_get_m11(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD3_CC4                                                                0x1802f428
#define GDMA_OSD3_CC4_reg_addr                                                       "0xB802F428"
#define GDMA_OSD3_CC4_reg                                                            0xB802F428
#define set_GDMA_OSD3_CC4_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_CC4_reg)=data)
#define get_GDMA_OSD3_CC4_reg   (*((volatile unsigned int*) GDMA_OSD3_CC4_reg))
#define GDMA_OSD3_CC4_inst_adr                                                       "0x000A"
#define GDMA_OSD3_CC4_inst                                                           0x000A
#define GDMA_OSD3_CC4_m21_shift                                                      (16)
#define GDMA_OSD3_CC4_m21_mask                                                       (0x3FFF0000)
#define GDMA_OSD3_CC4_m21(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD3_CC4_m21_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD3_CC4_get_m21(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD3_CC4_m20_shift                                                      (0)
#define GDMA_OSD3_CC4_m20_mask                                                       (0x00003FFF)
#define GDMA_OSD3_CC4_m20(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD3_CC4_m20_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD3_CC4_get_m20(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD3_CC5                                                                0x1802f42c
#define GDMA_OSD3_CC5_reg_addr                                                       "0xB802F42C"
#define GDMA_OSD3_CC5_reg                                                            0xB802F42C
#define set_GDMA_OSD3_CC5_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_CC5_reg)=data)
#define get_GDMA_OSD3_CC5_reg   (*((volatile unsigned int*) GDMA_OSD3_CC5_reg))
#define GDMA_OSD3_CC5_inst_adr                                                       "0x000B"
#define GDMA_OSD3_CC5_inst                                                           0x000B
#define GDMA_OSD3_CC5_m22_shift                                                      (0)
#define GDMA_OSD3_CC5_m22_mask                                                       (0x00003FFF)
#define GDMA_OSD3_CC5_m22(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD3_CC5_m22_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD3_CC5_get_m22(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD3_CC6                                                                0x1802f430
#define GDMA_OSD3_CC6_reg_addr                                                       "0xB802F430"
#define GDMA_OSD3_CC6_reg                                                            0xB802F430
#define set_GDMA_OSD3_CC6_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_CC6_reg)=data)
#define get_GDMA_OSD3_CC6_reg   (*((volatile unsigned int*) GDMA_OSD3_CC6_reg))
#define GDMA_OSD3_CC6_inst_adr                                                       "0x000C"
#define GDMA_OSD3_CC6_inst                                                           0x000C
#define GDMA_OSD3_CC6_a2_shift                                                       (18)
#define GDMA_OSD3_CC6_a2_mask                                                        (0x07FC0000)
#define GDMA_OSD3_CC6_a2(data)                                                       (0x07FC0000&((data)<<18))
#define GDMA_OSD3_CC6_a2_src(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD3_CC6_get_a2(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD3_CC6_a1_shift                                                       (9)
#define GDMA_OSD3_CC6_a1_mask                                                        (0x0003FE00)
#define GDMA_OSD3_CC6_a1(data)                                                       (0x0003FE00&((data)<<9))
#define GDMA_OSD3_CC6_a1_src(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD3_CC6_get_a1(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD3_CC6_a0_shift                                                       (0)
#define GDMA_OSD3_CC6_a0_mask                                                        (0x000001FF)
#define GDMA_OSD3_CC6_a0(data)                                                       (0x000001FF&((data)<<0))
#define GDMA_OSD3_CC6_a0_src(data)                                                   ((0x000001FF&(data))>>0)
#define GDMA_OSD3_CC6_get_a0(data)                                                   ((0x000001FF&(data))>>0)


#define GDMA_OSD3_CC7                                                                0x1802f434
#define GDMA_OSD3_CC7_reg_addr                                                       "0xB802F434"
#define GDMA_OSD3_CC7_reg                                                            0xB802F434
#define set_GDMA_OSD3_CC7_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_CC7_reg)=data)
#define get_GDMA_OSD3_CC7_reg   (*((volatile unsigned int*) GDMA_OSD3_CC7_reg))
#define GDMA_OSD3_CC7_inst_adr                                                       "0x000D"
#define GDMA_OSD3_CC7_inst                                                           0x000D
#define GDMA_OSD3_CC7_b2_shift                                                       (18)
#define GDMA_OSD3_CC7_b2_mask                                                        (0x07FC0000)
#define GDMA_OSD3_CC7_b2(data)                                                       (0x07FC0000&((data)<<18))
#define GDMA_OSD3_CC7_b2_src(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD3_CC7_get_b2(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD3_CC7_b1_shift                                                       (9)
#define GDMA_OSD3_CC7_b1_mask                                                        (0x0003FE00)
#define GDMA_OSD3_CC7_b1(data)                                                       (0x0003FE00&((data)<<9))
#define GDMA_OSD3_CC7_b1_src(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD3_CC7_get_b1(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD3_CC7_b0_shift                                                       (0)
#define GDMA_OSD3_CC7_b0_mask                                                        (0x000001FF)
#define GDMA_OSD3_CC7_b0(data)                                                       (0x000001FF&((data)<<0))
#define GDMA_OSD3_CC7_b0_src(data)                                                   ((0x000001FF&(data))>>0)
#define GDMA_OSD3_CC7_get_b0(data)                                                   ((0x000001FF&(data))>>0)


#define GDMA_OSD3_CLEAR1                                                             0x1802f480
#define GDMA_OSD3_CLEAR1_reg_addr                                                    "0xB802F480"
#define GDMA_OSD3_CLEAR1_reg                                                         0xB802F480
#define set_GDMA_OSD3_CLEAR1_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_CLEAR1_reg)=data)
#define get_GDMA_OSD3_CLEAR1_reg   (*((volatile unsigned int*) GDMA_OSD3_CLEAR1_reg))
#define GDMA_OSD3_CLEAR1_inst_adr                                                    "0x0020"
#define GDMA_OSD3_CLEAR1_inst                                                        0x0020
#define GDMA_OSD3_CLEAR1_x_sta_shift                                                 (16)
#define GDMA_OSD3_CLEAR1_x_sta_mask                                                  (0x1FFF0000)
#define GDMA_OSD3_CLEAR1_x_sta(data)                                                 (0x1FFF0000&((data)<<16))
#define GDMA_OSD3_CLEAR1_x_sta_src(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD3_CLEAR1_get_x_sta(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD3_CLEAR1_x_end_shift                                                 (0)
#define GDMA_OSD3_CLEAR1_x_end_mask                                                  (0x00001FFF)
#define GDMA_OSD3_CLEAR1_x_end(data)                                                 (0x00001FFF&((data)<<0))
#define GDMA_OSD3_CLEAR1_x_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define GDMA_OSD3_CLEAR1_get_x_end(data)                                             ((0x00001FFF&(data))>>0)


#define GDMA_OSD3_CLEAR2                                                             0x1802f484
#define GDMA_OSD3_CLEAR2_reg_addr                                                    "0xB802F484"
#define GDMA_OSD3_CLEAR2_reg                                                         0xB802F484
#define set_GDMA_OSD3_CLEAR2_reg(data)   (*((volatile unsigned int*) GDMA_OSD3_CLEAR2_reg)=data)
#define get_GDMA_OSD3_CLEAR2_reg   (*((volatile unsigned int*) GDMA_OSD3_CLEAR2_reg))
#define GDMA_OSD3_CLEAR2_inst_adr                                                    "0x0021"
#define GDMA_OSD3_CLEAR2_inst                                                        0x0021
#define GDMA_OSD3_CLEAR2_y_sta_shift                                                 (16)
#define GDMA_OSD3_CLEAR2_y_sta_mask                                                  (0x1FFF0000)
#define GDMA_OSD3_CLEAR2_y_sta(data)                                                 (0x1FFF0000&((data)<<16))
#define GDMA_OSD3_CLEAR2_y_sta_src(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD3_CLEAR2_get_y_sta(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD3_CLEAR2_y_end_shift                                                 (0)
#define GDMA_OSD3_CLEAR2_y_end_mask                                                  (0x00001FFF)
#define GDMA_OSD3_CLEAR2_y_end(data)                                                 (0x00001FFF&((data)<<0))
#define GDMA_OSD3_CLEAR2_y_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define GDMA_OSD3_CLEAR2_get_y_end(data)                                             ((0x00001FFF&(data))>>0)


#define GDMA_OSD4_CTRL                                                               0x1802f500
#define GDMA_OSD4_CTRL_reg_addr                                                      "0xB802F500"
#define GDMA_OSD4_CTRL_reg                                                           0xB802F500
#define set_GDMA_OSD4_CTRL_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_CTRL_reg)=data)
#define get_GDMA_OSD4_CTRL_reg   (*((volatile unsigned int*) GDMA_OSD4_CTRL_reg))
#define GDMA_OSD4_CTRL_inst_adr                                                      "0x0040"
#define GDMA_OSD4_CTRL_inst                                                          0x0040
#define GDMA_OSD4_CTRL_d3_mode_shift                                                 (9)
#define GDMA_OSD4_CTRL_d3_mode_mask                                                  (0x00000200)
#define GDMA_OSD4_CTRL_d3_mode(data)                                                 (0x00000200&((data)<<9))
#define GDMA_OSD4_CTRL_d3_mode_src(data)                                             ((0x00000200&(data))>>9)
#define GDMA_OSD4_CTRL_get_d3_mode(data)                                             ((0x00000200&(data))>>9)
#define GDMA_OSD4_CTRL_rotate_shift                                                  (8)
#define GDMA_OSD4_CTRL_rotate_mask                                                   (0x00000100)
#define GDMA_OSD4_CTRL_rotate(data)                                                  (0x00000100&((data)<<8))
#define GDMA_OSD4_CTRL_rotate_src(data)                                              ((0x00000100&(data))>>8)
#define GDMA_OSD4_CTRL_get_rotate(data)                                              ((0x00000100&(data))>>8)
#define GDMA_OSD4_CTRL_osd4_en_shift                                                 (1)
#define GDMA_OSD4_CTRL_osd4_en_mask                                                  (0x00000002)
#define GDMA_OSD4_CTRL_osd4_en(data)                                                 (0x00000002&((data)<<1))
#define GDMA_OSD4_CTRL_osd4_en_src(data)                                             ((0x00000002&(data))>>1)
#define GDMA_OSD4_CTRL_get_osd4_en(data)                                             ((0x00000002&(data))>>1)
#define GDMA_OSD4_CTRL_write_data_shift                                              (0)
#define GDMA_OSD4_CTRL_write_data_mask                                               (0x00000001)
#define GDMA_OSD4_CTRL_write_data(data)                                              (0x00000001&((data)<<0))
#define GDMA_OSD4_CTRL_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define GDMA_OSD4_CTRL_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define GDMA_OSD4                                                                    0x1802f504
#define GDMA_OSD4_reg_addr                                                           "0xB802F504"
#define GDMA_OSD4_reg                                                                0xB802F504
#define set_GDMA_OSD4_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_reg)=data)
#define get_GDMA_OSD4_reg   (*((volatile unsigned int*) GDMA_OSD4_reg))
#define GDMA_OSD4_inst_adr                                                           "0x0041"
#define GDMA_OSD4_inst                                                               0x0041
#define GDMA_OSD4_wi_endian_shift                                                    (25)
#define GDMA_OSD4_wi_endian_mask                                                     (0x02000000)
#define GDMA_OSD4_wi_endian(data)                                                    (0x02000000&((data)<<25))
#define GDMA_OSD4_wi_endian_src(data)                                                ((0x02000000&(data))>>25)
#define GDMA_OSD4_get_wi_endian(data)                                                ((0x02000000&(data))>>25)
#define GDMA_OSD4_rgb_out_shift                                                      (24)
#define GDMA_OSD4_rgb_out_mask                                                       (0x01000000)
#define GDMA_OSD4_rgb_out(data)                                                      (0x01000000&((data)<<24))
#define GDMA_OSD4_rgb_out_src(data)                                                  ((0x01000000&(data))>>24)
#define GDMA_OSD4_get_rgb_out(data)                                                  ((0x01000000&(data))>>24)
#define GDMA_OSD4_osd_shift                                                          (16)
#define GDMA_OSD4_osd_mask                                                           (0x00010000)
#define GDMA_OSD4_osd(data)                                                          (0x00010000&((data)<<16))
#define GDMA_OSD4_osd_src(data)                                                      ((0x00010000&(data))>>16)
#define GDMA_OSD4_get_osd(data)                                                      ((0x00010000&(data))>>16)
#define GDMA_OSD4_clear_region_en_shift                                              (1)
#define GDMA_OSD4_clear_region_en_mask                                               (0x00000002)
#define GDMA_OSD4_clear_region_en(data)                                              (0x00000002&((data)<<1))
#define GDMA_OSD4_clear_region_en_src(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD4_get_clear_region_en(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD4_write_data_shift                                                   (0)
#define GDMA_OSD4_write_data_mask                                                    (0x00000001)
#define GDMA_OSD4_write_data(data)                                                   (0x00000001&((data)<<0))
#define GDMA_OSD4_write_data_src(data)                                               ((0x00000001&(data))>>0)
#define GDMA_OSD4_get_write_data(data)                                               ((0x00000001&(data))>>0)


#define GDMA_OSD4_START                                                              0x1802f508
#define GDMA_OSD4_START_reg_addr                                                     "0xB802F508"
#define GDMA_OSD4_START_reg                                                          0xB802F508
#define set_GDMA_OSD4_START_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_START_reg)=data)
#define get_GDMA_OSD4_START_reg   (*((volatile unsigned int*) GDMA_OSD4_START_reg))
#define GDMA_OSD4_START_inst_adr                                                     "0x0042"
#define GDMA_OSD4_START_inst                                                         0x0042
#define GDMA_OSD4_START_th_shift                                                     (0)
#define GDMA_OSD4_START_th_mask                                                      (0x00001FFF)
#define GDMA_OSD4_START_th(data)                                                     (0x00001FFF&((data)<<0))
#define GDMA_OSD4_START_th_src(data)                                                 ((0x00001FFF&(data))>>0)
#define GDMA_OSD4_START_get_th(data)                                                 ((0x00001FFF&(data))>>0)


#define GDMA_OSD4_VBI_END                                                            0x1802f50c
#define GDMA_OSD4_VBI_END_reg_addr                                                   "0xB802F50C"
#define GDMA_OSD4_VBI_END_reg                                                        0xB802F50C
#define set_GDMA_OSD4_VBI_END_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_VBI_END_reg)=data)
#define get_GDMA_OSD4_VBI_END_reg   (*((volatile unsigned int*) GDMA_OSD4_VBI_END_reg))
#define GDMA_OSD4_VBI_END_inst_adr                                                   "0x0043"
#define GDMA_OSD4_VBI_END_inst                                                       0x0043
#define GDMA_OSD4_VBI_END_th_shift                                                   (0)
#define GDMA_OSD4_VBI_END_th_mask                                                    (0x00001FFF)
#define GDMA_OSD4_VBI_END_th(data)                                                   (0x00001FFF&((data)<<0))
#define GDMA_OSD4_VBI_END_th_src(data)                                               ((0x00001FFF&(data))>>0)
#define GDMA_OSD4_VBI_END_get_th(data)                                               ((0x00001FFF&(data))>>0)


#define GDMA_OSD4_WI                                                                 0x1802f510
#define GDMA_OSD4_WI_reg_addr                                                        "0xB802F510"
#define GDMA_OSD4_WI_reg                                                             0xB802F510
#define set_GDMA_OSD4_WI_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_WI_reg)=data)
#define get_GDMA_OSD4_WI_reg   (*((volatile unsigned int*) GDMA_OSD4_WI_reg))
#define GDMA_OSD4_WI_inst_adr                                                        "0x0044"
#define GDMA_OSD4_WI_inst                                                            0x0044
#define GDMA_OSD4_WI_addr_shift                                                      (0)
#define GDMA_OSD4_WI_addr_mask                                                       (0xFFFFFFFF)
#define GDMA_OSD4_WI_addr(data)                                                      (0xFFFFFFFF&((data)<<0))
#define GDMA_OSD4_WI_addr_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define GDMA_OSD4_WI_get_addr(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define GDMA_OSD4_WI_3D                                                              0x1802f514
#define GDMA_OSD4_WI_3D_reg_addr                                                     "0xB802F514"
#define GDMA_OSD4_WI_3D_reg                                                          0xB802F514
#define set_GDMA_OSD4_WI_3D_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_WI_3D_reg)=data)
#define get_GDMA_OSD4_WI_3D_reg   (*((volatile unsigned int*) GDMA_OSD4_WI_3D_reg))
#define GDMA_OSD4_WI_3D_inst_adr                                                     "0x0045"
#define GDMA_OSD4_WI_3D_inst                                                         0x0045
#define GDMA_OSD4_WI_3D_addr_shift                                                   (0)
#define GDMA_OSD4_WI_3D_addr_mask                                                    (0xFFFFFFFF)
#define GDMA_OSD4_WI_3D_addr(data)                                                   (0xFFFFFFFF&((data)<<0))
#define GDMA_OSD4_WI_3D_addr_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define GDMA_OSD4_WI_3D_get_addr(data)                                               ((0xFFFFFFFF&(data))>>0)


#define GDMA_OSD4_SIZE                                                               0x1802f518
#define GDMA_OSD4_SIZE_reg_addr                                                      "0xB802F518"
#define GDMA_OSD4_SIZE_reg                                                           0xB802F518
#define set_GDMA_OSD4_SIZE_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_SIZE_reg)=data)
#define get_GDMA_OSD4_SIZE_reg   (*((volatile unsigned int*) GDMA_OSD4_SIZE_reg))
#define GDMA_OSD4_SIZE_inst_adr                                                      "0x0046"
#define GDMA_OSD4_SIZE_inst                                                          0x0046
#define GDMA_OSD4_SIZE_w_shift                                                       (16)
#define GDMA_OSD4_SIZE_w_mask                                                        (0x1FFF0000)
#define GDMA_OSD4_SIZE_w(data)                                                       (0x1FFF0000&((data)<<16))
#define GDMA_OSD4_SIZE_w_src(data)                                                   ((0x1FFF0000&(data))>>16)
#define GDMA_OSD4_SIZE_get_w(data)                                                   ((0x1FFF0000&(data))>>16)
#define GDMA_OSD4_SIZE_h_shift                                                       (0)
#define GDMA_OSD4_SIZE_h_mask                                                        (0x00001FFF)
#define GDMA_OSD4_SIZE_h(data)                                                       (0x00001FFF&((data)<<0))
#define GDMA_OSD4_SIZE_h_src(data)                                                   ((0x00001FFF&(data))>>0)
#define GDMA_OSD4_SIZE_get_h(data)                                                   ((0x00001FFF&(data))>>0)


#define GDMA_OSD4_CC1                                                                0x1802f51c
#define GDMA_OSD4_CC1_reg_addr                                                       "0xB802F51C"
#define GDMA_OSD4_CC1_reg                                                            0xB802F51C
#define set_GDMA_OSD4_CC1_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_CC1_reg)=data)
#define get_GDMA_OSD4_CC1_reg   (*((volatile unsigned int*) GDMA_OSD4_CC1_reg))
#define GDMA_OSD4_CC1_inst_adr                                                       "0x0047"
#define GDMA_OSD4_CC1_inst                                                           0x0047
#define GDMA_OSD4_CC1_m01_shift                                                      (16)
#define GDMA_OSD4_CC1_m01_mask                                                       (0x3FFF0000)
#define GDMA_OSD4_CC1_m01(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD4_CC1_m01_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD4_CC1_get_m01(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD4_CC1_m00_shift                                                      (0)
#define GDMA_OSD4_CC1_m00_mask                                                       (0x00003FFF)
#define GDMA_OSD4_CC1_m00(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD4_CC1_m00_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD4_CC1_get_m00(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD4_CC2                                                                0x1802f520
#define GDMA_OSD4_CC2_reg_addr                                                       "0xB802F520"
#define GDMA_OSD4_CC2_reg                                                            0xB802F520
#define set_GDMA_OSD4_CC2_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_CC2_reg)=data)
#define get_GDMA_OSD4_CC2_reg   (*((volatile unsigned int*) GDMA_OSD4_CC2_reg))
#define GDMA_OSD4_CC2_inst_adr                                                       "0x0048"
#define GDMA_OSD4_CC2_inst                                                           0x0048
#define GDMA_OSD4_CC2_m10_shift                                                      (16)
#define GDMA_OSD4_CC2_m10_mask                                                       (0x3FFF0000)
#define GDMA_OSD4_CC2_m10(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD4_CC2_m10_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD4_CC2_get_m10(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD4_CC2_m02_shift                                                      (0)
#define GDMA_OSD4_CC2_m02_mask                                                       (0x00003FFF)
#define GDMA_OSD4_CC2_m02(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD4_CC2_m02_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD4_CC2_get_m02(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD4_CC3                                                                0x1802f524
#define GDMA_OSD4_CC3_reg_addr                                                       "0xB802F524"
#define GDMA_OSD4_CC3_reg                                                            0xB802F524
#define set_GDMA_OSD4_CC3_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_CC3_reg)=data)
#define get_GDMA_OSD4_CC3_reg   (*((volatile unsigned int*) GDMA_OSD4_CC3_reg))
#define GDMA_OSD4_CC3_inst_adr                                                       "0x0049"
#define GDMA_OSD4_CC3_inst                                                           0x0049
#define GDMA_OSD4_CC3_m12_shift                                                      (16)
#define GDMA_OSD4_CC3_m12_mask                                                       (0x3FFF0000)
#define GDMA_OSD4_CC3_m12(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD4_CC3_m12_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD4_CC3_get_m12(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD4_CC3_m11_shift                                                      (0)
#define GDMA_OSD4_CC3_m11_mask                                                       (0x00003FFF)
#define GDMA_OSD4_CC3_m11(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD4_CC3_m11_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD4_CC3_get_m11(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD4_CC4                                                                0x1802f528
#define GDMA_OSD4_CC4_reg_addr                                                       "0xB802F528"
#define GDMA_OSD4_CC4_reg                                                            0xB802F528
#define set_GDMA_OSD4_CC4_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_CC4_reg)=data)
#define get_GDMA_OSD4_CC4_reg   (*((volatile unsigned int*) GDMA_OSD4_CC4_reg))
#define GDMA_OSD4_CC4_inst_adr                                                       "0x004A"
#define GDMA_OSD4_CC4_inst                                                           0x004A
#define GDMA_OSD4_CC4_m21_shift                                                      (16)
#define GDMA_OSD4_CC4_m21_mask                                                       (0x3FFF0000)
#define GDMA_OSD4_CC4_m21(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD4_CC4_m21_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD4_CC4_get_m21(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD4_CC4_m20_shift                                                      (0)
#define GDMA_OSD4_CC4_m20_mask                                                       (0x00003FFF)
#define GDMA_OSD4_CC4_m20(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD4_CC4_m20_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD4_CC4_get_m20(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD4_CC5                                                                0x1802f52c
#define GDMA_OSD4_CC5_reg_addr                                                       "0xB802F52C"
#define GDMA_OSD4_CC5_reg                                                            0xB802F52C
#define set_GDMA_OSD4_CC5_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_CC5_reg)=data)
#define get_GDMA_OSD4_CC5_reg   (*((volatile unsigned int*) GDMA_OSD4_CC5_reg))
#define GDMA_OSD4_CC5_inst_adr                                                       "0x004B"
#define GDMA_OSD4_CC5_inst                                                           0x004B
#define GDMA_OSD4_CC5_m22_shift                                                      (0)
#define GDMA_OSD4_CC5_m22_mask                                                       (0x00003FFF)
#define GDMA_OSD4_CC5_m22(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD4_CC5_m22_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD4_CC5_get_m22(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD4_CC6                                                                0x1802f530
#define GDMA_OSD4_CC6_reg_addr                                                       "0xB802F530"
#define GDMA_OSD4_CC6_reg                                                            0xB802F530
#define set_GDMA_OSD4_CC6_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_CC6_reg)=data)
#define get_GDMA_OSD4_CC6_reg   (*((volatile unsigned int*) GDMA_OSD4_CC6_reg))
#define GDMA_OSD4_CC6_inst_adr                                                       "0x004C"
#define GDMA_OSD4_CC6_inst                                                           0x004C
#define GDMA_OSD4_CC6_a2_shift                                                       (18)
#define GDMA_OSD4_CC6_a2_mask                                                        (0x07FC0000)
#define GDMA_OSD4_CC6_a2(data)                                                       (0x07FC0000&((data)<<18))
#define GDMA_OSD4_CC6_a2_src(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD4_CC6_get_a2(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD4_CC6_a1_shift                                                       (9)
#define GDMA_OSD4_CC6_a1_mask                                                        (0x0003FE00)
#define GDMA_OSD4_CC6_a1(data)                                                       (0x0003FE00&((data)<<9))
#define GDMA_OSD4_CC6_a1_src(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD4_CC6_get_a1(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD4_CC6_a0_shift                                                       (0)
#define GDMA_OSD4_CC6_a0_mask                                                        (0x000001FF)
#define GDMA_OSD4_CC6_a0(data)                                                       (0x000001FF&((data)<<0))
#define GDMA_OSD4_CC6_a0_src(data)                                                   ((0x000001FF&(data))>>0)
#define GDMA_OSD4_CC6_get_a0(data)                                                   ((0x000001FF&(data))>>0)


#define GDMA_OSD4_CC7                                                                0x1802f534
#define GDMA_OSD4_CC7_reg_addr                                                       "0xB802F534"
#define GDMA_OSD4_CC7_reg                                                            0xB802F534
#define set_GDMA_OSD4_CC7_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_CC7_reg)=data)
#define get_GDMA_OSD4_CC7_reg   (*((volatile unsigned int*) GDMA_OSD4_CC7_reg))
#define GDMA_OSD4_CC7_inst_adr                                                       "0x004D"
#define GDMA_OSD4_CC7_inst                                                           0x004D
#define GDMA_OSD4_CC7_b2_shift                                                       (18)
#define GDMA_OSD4_CC7_b2_mask                                                        (0x07FC0000)
#define GDMA_OSD4_CC7_b2(data)                                                       (0x07FC0000&((data)<<18))
#define GDMA_OSD4_CC7_b2_src(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD4_CC7_get_b2(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD4_CC7_b1_shift                                                       (9)
#define GDMA_OSD4_CC7_b1_mask                                                        (0x0003FE00)
#define GDMA_OSD4_CC7_b1(data)                                                       (0x0003FE00&((data)<<9))
#define GDMA_OSD4_CC7_b1_src(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD4_CC7_get_b1(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD4_CC7_b0_shift                                                       (0)
#define GDMA_OSD4_CC7_b0_mask                                                        (0x000001FF)
#define GDMA_OSD4_CC7_b0(data)                                                       (0x000001FF&((data)<<0))
#define GDMA_OSD4_CC7_b0_src(data)                                                   ((0x000001FF&(data))>>0)
#define GDMA_OSD4_CC7_get_b0(data)                                                   ((0x000001FF&(data))>>0)


#define GDMA_OSD4_CLEAR1                                                             0x1802f580
#define GDMA_OSD4_CLEAR1_reg_addr                                                    "0xB802F580"
#define GDMA_OSD4_CLEAR1_reg                                                         0xB802F580
#define set_GDMA_OSD4_CLEAR1_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_CLEAR1_reg)=data)
#define get_GDMA_OSD4_CLEAR1_reg   (*((volatile unsigned int*) GDMA_OSD4_CLEAR1_reg))
#define GDMA_OSD4_CLEAR1_inst_adr                                                    "0x0060"
#define GDMA_OSD4_CLEAR1_inst                                                        0x0060
#define GDMA_OSD4_CLEAR1_x_sta_shift                                                 (16)
#define GDMA_OSD4_CLEAR1_x_sta_mask                                                  (0x1FFF0000)
#define GDMA_OSD4_CLEAR1_x_sta(data)                                                 (0x1FFF0000&((data)<<16))
#define GDMA_OSD4_CLEAR1_x_sta_src(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD4_CLEAR1_get_x_sta(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD4_CLEAR1_x_end_shift                                                 (0)
#define GDMA_OSD4_CLEAR1_x_end_mask                                                  (0x00001FFF)
#define GDMA_OSD4_CLEAR1_x_end(data)                                                 (0x00001FFF&((data)<<0))
#define GDMA_OSD4_CLEAR1_x_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define GDMA_OSD4_CLEAR1_get_x_end(data)                                             ((0x00001FFF&(data))>>0)


#define GDMA_OSD4_CLEAR2                                                             0x1802f584
#define GDMA_OSD4_CLEAR2_reg_addr                                                    "0xB802F584"
#define GDMA_OSD4_CLEAR2_reg                                                         0xB802F584
#define set_GDMA_OSD4_CLEAR2_reg(data)   (*((volatile unsigned int*) GDMA_OSD4_CLEAR2_reg)=data)
#define get_GDMA_OSD4_CLEAR2_reg   (*((volatile unsigned int*) GDMA_OSD4_CLEAR2_reg))
#define GDMA_OSD4_CLEAR2_inst_adr                                                    "0x0061"
#define GDMA_OSD4_CLEAR2_inst                                                        0x0061
#define GDMA_OSD4_CLEAR2_y_sta_shift                                                 (16)
#define GDMA_OSD4_CLEAR2_y_sta_mask                                                  (0x1FFF0000)
#define GDMA_OSD4_CLEAR2_y_sta(data)                                                 (0x1FFF0000&((data)<<16))
#define GDMA_OSD4_CLEAR2_y_sta_src(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD4_CLEAR2_get_y_sta(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD4_CLEAR2_y_end_shift                                                 (0)
#define GDMA_OSD4_CLEAR2_y_end_mask                                                  (0x00001FFF)
#define GDMA_OSD4_CLEAR2_y_end(data)                                                 (0x00001FFF&((data)<<0))
#define GDMA_OSD4_CLEAR2_y_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define GDMA_OSD4_CLEAR2_get_y_end(data)                                             ((0x00001FFF&(data))>>0)


#define GDMA_OSD5_CTRL                                                               0x1802f600
#define GDMA_OSD5_CTRL_reg_addr                                                      "0xB802F600"
#define GDMA_OSD5_CTRL_reg                                                           0xB802F600
#define set_GDMA_OSD5_CTRL_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_CTRL_reg)=data)
#define get_GDMA_OSD5_CTRL_reg   (*((volatile unsigned int*) GDMA_OSD5_CTRL_reg))
#define GDMA_OSD5_CTRL_inst_adr                                                      "0x0080"
#define GDMA_OSD5_CTRL_inst                                                          0x0080
#define GDMA_OSD5_CTRL_d3_mode_shift                                                 (9)
#define GDMA_OSD5_CTRL_d3_mode_mask                                                  (0x00000200)
#define GDMA_OSD5_CTRL_d3_mode(data)                                                 (0x00000200&((data)<<9))
#define GDMA_OSD5_CTRL_d3_mode_src(data)                                             ((0x00000200&(data))>>9)
#define GDMA_OSD5_CTRL_get_d3_mode(data)                                             ((0x00000200&(data))>>9)
#define GDMA_OSD5_CTRL_rotate_shift                                                  (8)
#define GDMA_OSD5_CTRL_rotate_mask                                                   (0x00000100)
#define GDMA_OSD5_CTRL_rotate(data)                                                  (0x00000100&((data)<<8))
#define GDMA_OSD5_CTRL_rotate_src(data)                                              ((0x00000100&(data))>>8)
#define GDMA_OSD5_CTRL_get_rotate(data)                                              ((0x00000100&(data))>>8)
#define GDMA_OSD5_CTRL_osd5_en_shift                                                 (1)
#define GDMA_OSD5_CTRL_osd5_en_mask                                                  (0x00000002)
#define GDMA_OSD5_CTRL_osd5_en(data)                                                 (0x00000002&((data)<<1))
#define GDMA_OSD5_CTRL_osd5_en_src(data)                                             ((0x00000002&(data))>>1)
#define GDMA_OSD5_CTRL_get_osd5_en(data)                                             ((0x00000002&(data))>>1)
#define GDMA_OSD5_CTRL_write_data_shift                                              (0)
#define GDMA_OSD5_CTRL_write_data_mask                                               (0x00000001)
#define GDMA_OSD5_CTRL_write_data(data)                                              (0x00000001&((data)<<0))
#define GDMA_OSD5_CTRL_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define GDMA_OSD5_CTRL_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define GDMA_OSD5                                                                    0x1802f604
#define GDMA_OSD5_reg_addr                                                           "0xB802F604"
#define GDMA_OSD5_reg                                                                0xB802F604
#define set_GDMA_OSD5_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_reg)=data)
#define get_GDMA_OSD5_reg   (*((volatile unsigned int*) GDMA_OSD5_reg))
#define GDMA_OSD5_inst_adr                                                           "0x0081"
#define GDMA_OSD5_inst                                                               0x0081
#define GDMA_OSD5_wi_endian_shift                                                    (25)
#define GDMA_OSD5_wi_endian_mask                                                     (0x02000000)
#define GDMA_OSD5_wi_endian(data)                                                    (0x02000000&((data)<<25))
#define GDMA_OSD5_wi_endian_src(data)                                                ((0x02000000&(data))>>25)
#define GDMA_OSD5_get_wi_endian(data)                                                ((0x02000000&(data))>>25)
#define GDMA_OSD5_rgb_out_shift                                                      (24)
#define GDMA_OSD5_rgb_out_mask                                                       (0x01000000)
#define GDMA_OSD5_rgb_out(data)                                                      (0x01000000&((data)<<24))
#define GDMA_OSD5_rgb_out_src(data)                                                  ((0x01000000&(data))>>24)
#define GDMA_OSD5_get_rgb_out(data)                                                  ((0x01000000&(data))>>24)
#define GDMA_OSD5_osd_shift                                                          (16)
#define GDMA_OSD5_osd_mask                                                           (0x00010000)
#define GDMA_OSD5_osd(data)                                                          (0x00010000&((data)<<16))
#define GDMA_OSD5_osd_src(data)                                                      ((0x00010000&(data))>>16)
#define GDMA_OSD5_get_osd(data)                                                      ((0x00010000&(data))>>16)
#define GDMA_OSD5_clear_region_en_shift                                              (1)
#define GDMA_OSD5_clear_region_en_mask                                               (0x00000002)
#define GDMA_OSD5_clear_region_en(data)                                              (0x00000002&((data)<<1))
#define GDMA_OSD5_clear_region_en_src(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD5_get_clear_region_en(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD5_write_data_shift                                                   (0)
#define GDMA_OSD5_write_data_mask                                                    (0x00000001)
#define GDMA_OSD5_write_data(data)                                                   (0x00000001&((data)<<0))
#define GDMA_OSD5_write_data_src(data)                                               ((0x00000001&(data))>>0)
#define GDMA_OSD5_get_write_data(data)                                               ((0x00000001&(data))>>0)


#define GDMA_OSD5_START                                                              0x1802f608
#define GDMA_OSD5_START_reg_addr                                                     "0xB802F608"
#define GDMA_OSD5_START_reg                                                          0xB802F608
#define set_GDMA_OSD5_START_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_START_reg)=data)
#define get_GDMA_OSD5_START_reg   (*((volatile unsigned int*) GDMA_OSD5_START_reg))
#define GDMA_OSD5_START_inst_adr                                                     "0x0082"
#define GDMA_OSD5_START_inst                                                         0x0082
#define GDMA_OSD5_START_th_shift                                                     (0)
#define GDMA_OSD5_START_th_mask                                                      (0x00001FFF)
#define GDMA_OSD5_START_th(data)                                                     (0x00001FFF&((data)<<0))
#define GDMA_OSD5_START_th_src(data)                                                 ((0x00001FFF&(data))>>0)
#define GDMA_OSD5_START_get_th(data)                                                 ((0x00001FFF&(data))>>0)


#define GDMA_OSD5_VBI_END                                                            0x1802f60c
#define GDMA_OSD5_VBI_END_reg_addr                                                   "0xB802F60C"
#define GDMA_OSD5_VBI_END_reg                                                        0xB802F60C
#define set_GDMA_OSD5_VBI_END_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_VBI_END_reg)=data)
#define get_GDMA_OSD5_VBI_END_reg   (*((volatile unsigned int*) GDMA_OSD5_VBI_END_reg))
#define GDMA_OSD5_VBI_END_inst_adr                                                   "0x0083"
#define GDMA_OSD5_VBI_END_inst                                                       0x0083
#define GDMA_OSD5_VBI_END_th_shift                                                   (0)
#define GDMA_OSD5_VBI_END_th_mask                                                    (0x00001FFF)
#define GDMA_OSD5_VBI_END_th(data)                                                   (0x00001FFF&((data)<<0))
#define GDMA_OSD5_VBI_END_th_src(data)                                               ((0x00001FFF&(data))>>0)
#define GDMA_OSD5_VBI_END_get_th(data)                                               ((0x00001FFF&(data))>>0)


#define GDMA_OSD5_WI                                                                 0x1802f610
#define GDMA_OSD5_WI_reg_addr                                                        "0xB802F610"
#define GDMA_OSD5_WI_reg                                                             0xB802F610
#define set_GDMA_OSD5_WI_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_WI_reg)=data)
#define get_GDMA_OSD5_WI_reg   (*((volatile unsigned int*) GDMA_OSD5_WI_reg))
#define GDMA_OSD5_WI_inst_adr                                                        "0x0084"
#define GDMA_OSD5_WI_inst                                                            0x0084
#define GDMA_OSD5_WI_addr_shift                                                      (0)
#define GDMA_OSD5_WI_addr_mask                                                       (0xFFFFFFFF)
#define GDMA_OSD5_WI_addr(data)                                                      (0xFFFFFFFF&((data)<<0))
#define GDMA_OSD5_WI_addr_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define GDMA_OSD5_WI_get_addr(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define GDMA_OSD5_WI_3D                                                              0x1802f614
#define GDMA_OSD5_WI_3D_reg_addr                                                     "0xB802F614"
#define GDMA_OSD5_WI_3D_reg                                                          0xB802F614
#define set_GDMA_OSD5_WI_3D_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_WI_3D_reg)=data)
#define get_GDMA_OSD5_WI_3D_reg   (*((volatile unsigned int*) GDMA_OSD5_WI_3D_reg))
#define GDMA_OSD5_WI_3D_inst_adr                                                     "0x0085"
#define GDMA_OSD5_WI_3D_inst                                                         0x0085
#define GDMA_OSD5_WI_3D_addr_shift                                                   (0)
#define GDMA_OSD5_WI_3D_addr_mask                                                    (0xFFFFFFFF)
#define GDMA_OSD5_WI_3D_addr(data)                                                   (0xFFFFFFFF&((data)<<0))
#define GDMA_OSD5_WI_3D_addr_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define GDMA_OSD5_WI_3D_get_addr(data)                                               ((0xFFFFFFFF&(data))>>0)


#define GDMA_OSD5_SIZE                                                               0x1802f618
#define GDMA_OSD5_SIZE_reg_addr                                                      "0xB802F618"
#define GDMA_OSD5_SIZE_reg                                                           0xB802F618
#define set_GDMA_OSD5_SIZE_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_SIZE_reg)=data)
#define get_GDMA_OSD5_SIZE_reg   (*((volatile unsigned int*) GDMA_OSD5_SIZE_reg))
#define GDMA_OSD5_SIZE_inst_adr                                                      "0x0086"
#define GDMA_OSD5_SIZE_inst                                                          0x0086
#define GDMA_OSD5_SIZE_w_shift                                                       (16)
#define GDMA_OSD5_SIZE_w_mask                                                        (0x1FFF0000)
#define GDMA_OSD5_SIZE_w(data)                                                       (0x1FFF0000&((data)<<16))
#define GDMA_OSD5_SIZE_w_src(data)                                                   ((0x1FFF0000&(data))>>16)
#define GDMA_OSD5_SIZE_get_w(data)                                                   ((0x1FFF0000&(data))>>16)
#define GDMA_OSD5_SIZE_h_shift                                                       (0)
#define GDMA_OSD5_SIZE_h_mask                                                        (0x00001FFF)
#define GDMA_OSD5_SIZE_h(data)                                                       (0x00001FFF&((data)<<0))
#define GDMA_OSD5_SIZE_h_src(data)                                                   ((0x00001FFF&(data))>>0)
#define GDMA_OSD5_SIZE_get_h(data)                                                   ((0x00001FFF&(data))>>0)


#define GDMA_OSD5_CC1                                                                0x1802f61c
#define GDMA_OSD5_CC1_reg_addr                                                       "0xB802F61C"
#define GDMA_OSD5_CC1_reg                                                            0xB802F61C
#define set_GDMA_OSD5_CC1_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_CC1_reg)=data)
#define get_GDMA_OSD5_CC1_reg   (*((volatile unsigned int*) GDMA_OSD5_CC1_reg))
#define GDMA_OSD5_CC1_inst_adr                                                       "0x0087"
#define GDMA_OSD5_CC1_inst                                                           0x0087
#define GDMA_OSD5_CC1_m01_shift                                                      (16)
#define GDMA_OSD5_CC1_m01_mask                                                       (0x3FFF0000)
#define GDMA_OSD5_CC1_m01(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD5_CC1_m01_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD5_CC1_get_m01(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD5_CC1_m00_shift                                                      (0)
#define GDMA_OSD5_CC1_m00_mask                                                       (0x00003FFF)
#define GDMA_OSD5_CC1_m00(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD5_CC1_m00_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD5_CC1_get_m00(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD5_CC2                                                                0x1802f620
#define GDMA_OSD5_CC2_reg_addr                                                       "0xB802F620"
#define GDMA_OSD5_CC2_reg                                                            0xB802F620
#define set_GDMA_OSD5_CC2_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_CC2_reg)=data)
#define get_GDMA_OSD5_CC2_reg   (*((volatile unsigned int*) GDMA_OSD5_CC2_reg))
#define GDMA_OSD5_CC2_inst_adr                                                       "0x0088"
#define GDMA_OSD5_CC2_inst                                                           0x0088
#define GDMA_OSD5_CC2_m10_shift                                                      (16)
#define GDMA_OSD5_CC2_m10_mask                                                       (0x3FFF0000)
#define GDMA_OSD5_CC2_m10(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD5_CC2_m10_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD5_CC2_get_m10(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD5_CC2_m02_shift                                                      (0)
#define GDMA_OSD5_CC2_m02_mask                                                       (0x00003FFF)
#define GDMA_OSD5_CC2_m02(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD5_CC2_m02_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD5_CC2_get_m02(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD5_CC3                                                                0x1802f624
#define GDMA_OSD5_CC3_reg_addr                                                       "0xB802F624"
#define GDMA_OSD5_CC3_reg                                                            0xB802F624
#define set_GDMA_OSD5_CC3_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_CC3_reg)=data)
#define get_GDMA_OSD5_CC3_reg   (*((volatile unsigned int*) GDMA_OSD5_CC3_reg))
#define GDMA_OSD5_CC3_inst_adr                                                       "0x0089"
#define GDMA_OSD5_CC3_inst                                                           0x0089
#define GDMA_OSD5_CC3_m12_shift                                                      (16)
#define GDMA_OSD5_CC3_m12_mask                                                       (0x3FFF0000)
#define GDMA_OSD5_CC3_m12(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD5_CC3_m12_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD5_CC3_get_m12(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD5_CC3_m11_shift                                                      (0)
#define GDMA_OSD5_CC3_m11_mask                                                       (0x00003FFF)
#define GDMA_OSD5_CC3_m11(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD5_CC3_m11_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD5_CC3_get_m11(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD5_CC4                                                                0x1802f628
#define GDMA_OSD5_CC4_reg_addr                                                       "0xB802F628"
#define GDMA_OSD5_CC4_reg                                                            0xB802F628
#define set_GDMA_OSD5_CC4_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_CC4_reg)=data)
#define get_GDMA_OSD5_CC4_reg   (*((volatile unsigned int*) GDMA_OSD5_CC4_reg))
#define GDMA_OSD5_CC4_inst_adr                                                       "0x008A"
#define GDMA_OSD5_CC4_inst                                                           0x008A
#define GDMA_OSD5_CC4_m21_shift                                                      (16)
#define GDMA_OSD5_CC4_m21_mask                                                       (0x3FFF0000)
#define GDMA_OSD5_CC4_m21(data)                                                      (0x3FFF0000&((data)<<16))
#define GDMA_OSD5_CC4_m21_src(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD5_CC4_get_m21(data)                                                  ((0x3FFF0000&(data))>>16)
#define GDMA_OSD5_CC4_m20_shift                                                      (0)
#define GDMA_OSD5_CC4_m20_mask                                                       (0x00003FFF)
#define GDMA_OSD5_CC4_m20(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD5_CC4_m20_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD5_CC4_get_m20(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD5_CC5                                                                0x1802f62c
#define GDMA_OSD5_CC5_reg_addr                                                       "0xB802F62C"
#define GDMA_OSD5_CC5_reg                                                            0xB802F62C
#define set_GDMA_OSD5_CC5_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_CC5_reg)=data)
#define get_GDMA_OSD5_CC5_reg   (*((volatile unsigned int*) GDMA_OSD5_CC5_reg))
#define GDMA_OSD5_CC5_inst_adr                                                       "0x008B"
#define GDMA_OSD5_CC5_inst                                                           0x008B
#define GDMA_OSD5_CC5_m22_shift                                                      (0)
#define GDMA_OSD5_CC5_m22_mask                                                       (0x00003FFF)
#define GDMA_OSD5_CC5_m22(data)                                                      (0x00003FFF&((data)<<0))
#define GDMA_OSD5_CC5_m22_src(data)                                                  ((0x00003FFF&(data))>>0)
#define GDMA_OSD5_CC5_get_m22(data)                                                  ((0x00003FFF&(data))>>0)


#define GDMA_OSD5_CC6                                                                0x1802f630
#define GDMA_OSD5_CC6_reg_addr                                                       "0xB802F630"
#define GDMA_OSD5_CC6_reg                                                            0xB802F630
#define set_GDMA_OSD5_CC6_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_CC6_reg)=data)
#define get_GDMA_OSD5_CC6_reg   (*((volatile unsigned int*) GDMA_OSD5_CC6_reg))
#define GDMA_OSD5_CC6_inst_adr                                                       "0x008C"
#define GDMA_OSD5_CC6_inst                                                           0x008C
#define GDMA_OSD5_CC6_a2_shift                                                       (18)
#define GDMA_OSD5_CC6_a2_mask                                                        (0x07FC0000)
#define GDMA_OSD5_CC6_a2(data)                                                       (0x07FC0000&((data)<<18))
#define GDMA_OSD5_CC6_a2_src(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD5_CC6_get_a2(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD5_CC6_a1_shift                                                       (9)
#define GDMA_OSD5_CC6_a1_mask                                                        (0x0003FE00)
#define GDMA_OSD5_CC6_a1(data)                                                       (0x0003FE00&((data)<<9))
#define GDMA_OSD5_CC6_a1_src(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD5_CC6_get_a1(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD5_CC6_a0_shift                                                       (0)
#define GDMA_OSD5_CC6_a0_mask                                                        (0x000001FF)
#define GDMA_OSD5_CC6_a0(data)                                                       (0x000001FF&((data)<<0))
#define GDMA_OSD5_CC6_a0_src(data)                                                   ((0x000001FF&(data))>>0)
#define GDMA_OSD5_CC6_get_a0(data)                                                   ((0x000001FF&(data))>>0)


#define GDMA_OSD5_CC7                                                                0x1802f634
#define GDMA_OSD5_CC7_reg_addr                                                       "0xB802F634"
#define GDMA_OSD5_CC7_reg                                                            0xB802F634
#define set_GDMA_OSD5_CC7_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_CC7_reg)=data)
#define get_GDMA_OSD5_CC7_reg   (*((volatile unsigned int*) GDMA_OSD5_CC7_reg))
#define GDMA_OSD5_CC7_inst_adr                                                       "0x008D"
#define GDMA_OSD5_CC7_inst                                                           0x008D
#define GDMA_OSD5_CC7_b2_shift                                                       (18)
#define GDMA_OSD5_CC7_b2_mask                                                        (0x07FC0000)
#define GDMA_OSD5_CC7_b2(data)                                                       (0x07FC0000&((data)<<18))
#define GDMA_OSD5_CC7_b2_src(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD5_CC7_get_b2(data)                                                   ((0x07FC0000&(data))>>18)
#define GDMA_OSD5_CC7_b1_shift                                                       (9)
#define GDMA_OSD5_CC7_b1_mask                                                        (0x0003FE00)
#define GDMA_OSD5_CC7_b1(data)                                                       (0x0003FE00&((data)<<9))
#define GDMA_OSD5_CC7_b1_src(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD5_CC7_get_b1(data)                                                   ((0x0003FE00&(data))>>9)
#define GDMA_OSD5_CC7_b0_shift                                                       (0)
#define GDMA_OSD5_CC7_b0_mask                                                        (0x000001FF)
#define GDMA_OSD5_CC7_b0(data)                                                       (0x000001FF&((data)<<0))
#define GDMA_OSD5_CC7_b0_src(data)                                                   ((0x000001FF&(data))>>0)
#define GDMA_OSD5_CC7_get_b0(data)                                                   ((0x000001FF&(data))>>0)


#define GDMA_OSD5_CLEAR1                                                             0x1802f680
#define GDMA_OSD5_CLEAR1_reg_addr                                                    "0xB802F680"
#define GDMA_OSD5_CLEAR1_reg                                                         0xB802F680
#define set_GDMA_OSD5_CLEAR1_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_CLEAR1_reg)=data)
#define get_GDMA_OSD5_CLEAR1_reg   (*((volatile unsigned int*) GDMA_OSD5_CLEAR1_reg))
#define GDMA_OSD5_CLEAR1_inst_adr                                                    "0x00A0"
#define GDMA_OSD5_CLEAR1_inst                                                        0x00A0
#define GDMA_OSD5_CLEAR1_x_sta_shift                                                 (16)
#define GDMA_OSD5_CLEAR1_x_sta_mask                                                  (0x1FFF0000)
#define GDMA_OSD5_CLEAR1_x_sta(data)                                                 (0x1FFF0000&((data)<<16))
#define GDMA_OSD5_CLEAR1_x_sta_src(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD5_CLEAR1_get_x_sta(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD5_CLEAR1_x_end_shift                                                 (0)
#define GDMA_OSD5_CLEAR1_x_end_mask                                                  (0x00001FFF)
#define GDMA_OSD5_CLEAR1_x_end(data)                                                 (0x00001FFF&((data)<<0))
#define GDMA_OSD5_CLEAR1_x_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define GDMA_OSD5_CLEAR1_get_x_end(data)                                             ((0x00001FFF&(data))>>0)


#define GDMA_OSD5_CLEAR2                                                             0x1802f684
#define GDMA_OSD5_CLEAR2_reg_addr                                                    "0xB802F684"
#define GDMA_OSD5_CLEAR2_reg                                                         0xB802F684
#define set_GDMA_OSD5_CLEAR2_reg(data)   (*((volatile unsigned int*) GDMA_OSD5_CLEAR2_reg)=data)
#define get_GDMA_OSD5_CLEAR2_reg   (*((volatile unsigned int*) GDMA_OSD5_CLEAR2_reg))
#define GDMA_OSD5_CLEAR2_inst_adr                                                    "0x00A1"
#define GDMA_OSD5_CLEAR2_inst                                                        0x00A1
#define GDMA_OSD5_CLEAR2_y_sta_shift                                                 (16)
#define GDMA_OSD5_CLEAR2_y_sta_mask                                                  (0x1FFF0000)
#define GDMA_OSD5_CLEAR2_y_sta(data)                                                 (0x1FFF0000&((data)<<16))
#define GDMA_OSD5_CLEAR2_y_sta_src(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD5_CLEAR2_get_y_sta(data)                                             ((0x1FFF0000&(data))>>16)
#define GDMA_OSD5_CLEAR2_y_end_shift                                                 (0)
#define GDMA_OSD5_CLEAR2_y_end_mask                                                  (0x00001FFF)
#define GDMA_OSD5_CLEAR2_y_end(data)                                                 (0x00001FFF&((data)<<0))
#define GDMA_OSD5_CLEAR2_y_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define GDMA_OSD5_CLEAR2_get_y_end(data)                                             ((0x00001FFF&(data))>>0)


#define GDMA_DECMP1_RESOLUTION                                                       0x1802f700
#define GDMA_DECMP1_RESOLUTION_reg_addr                                              "0xB802F700"
#define GDMA_DECMP1_RESOLUTION_reg                                                   0xB802F700
#define set_GDMA_DECMP1_RESOLUTION_reg(data)   (*((volatile unsigned int*) GDMA_DECMP1_RESOLUTION_reg)=data)
#define get_GDMA_DECMP1_RESOLUTION_reg   (*((volatile unsigned int*) GDMA_DECMP1_RESOLUTION_reg))
#define GDMA_DECMP1_RESOLUTION_inst_adr                                              "0x00C0"
#define GDMA_DECMP1_RESOLUTION_inst                                                  0x00C0
#define GDMA_DECMP1_RESOLUTION_decmp_segment_shift                                   (24)
#define GDMA_DECMP1_RESOLUTION_decmp_segment_mask                                    (0x03000000)
#define GDMA_DECMP1_RESOLUTION_decmp_segment(data)                                   (0x03000000&((data)<<24))
#define GDMA_DECMP1_RESOLUTION_decmp_segment_src(data)                               ((0x03000000&(data))>>24)
#define GDMA_DECMP1_RESOLUTION_get_decmp_segment(data)                               ((0x03000000&(data))>>24)
#define GDMA_DECMP1_RESOLUTION_decmp_width_shift                                     (16)
#define GDMA_DECMP1_RESOLUTION_decmp_width_mask                                      (0x00FF0000)
#define GDMA_DECMP1_RESOLUTION_decmp_width(data)                                     (0x00FF0000&((data)<<16))
#define GDMA_DECMP1_RESOLUTION_decmp_width_src(data)                                 ((0x00FF0000&(data))>>16)
#define GDMA_DECMP1_RESOLUTION_get_decmp_width(data)                                 ((0x00FF0000&(data))>>16)
#define GDMA_DECMP1_RESOLUTION_decmp_height_shift                                    (0)
#define GDMA_DECMP1_RESOLUTION_decmp_height_mask                                     (0x0000FFFF)
#define GDMA_DECMP1_RESOLUTION_decmp_height(data)                                    (0x0000FFFF&((data)<<0))
#define GDMA_DECMP1_RESOLUTION_decmp_height_src(data)                                ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP1_RESOLUTION_get_decmp_height(data)                                ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP1_SETTING                                                          0x1802f704
#define GDMA_DECMP1_SETTING_reg_addr                                                 "0xB802F704"
#define GDMA_DECMP1_SETTING_reg                                                      0xB802F704
#define set_GDMA_DECMP1_SETTING_reg(data)   (*((volatile unsigned int*) GDMA_DECMP1_SETTING_reg)=data)
#define get_GDMA_DECMP1_SETTING_reg   (*((volatile unsigned int*) GDMA_DECMP1_SETTING_reg))
#define GDMA_DECMP1_SETTING_inst_adr                                                 "0x00C1"
#define GDMA_DECMP1_SETTING_inst                                                     0x00C1
#define GDMA_DECMP1_SETTING_a_sat_en_shift                                           (17)
#define GDMA_DECMP1_SETTING_a_sat_en_mask                                            (0x00020000)
#define GDMA_DECMP1_SETTING_a_sat_en(data)                                           (0x00020000&((data)<<17))
#define GDMA_DECMP1_SETTING_a_sat_en_src(data)                                       ((0x00020000&(data))>>17)
#define GDMA_DECMP1_SETTING_get_a_sat_en(data)                                       ((0x00020000&(data))>>17)
#define GDMA_DECMP1_SETTING_b_cb_sat_en_shift                                        (16)
#define GDMA_DECMP1_SETTING_b_cb_sat_en_mask                                         (0x00010000)
#define GDMA_DECMP1_SETTING_b_cb_sat_en(data)                                        (0x00010000&((data)<<16))
#define GDMA_DECMP1_SETTING_b_cb_sat_en_src(data)                                    ((0x00010000&(data))>>16)
#define GDMA_DECMP1_SETTING_get_b_cb_sat_en(data)                                    ((0x00010000&(data))>>16)
#define GDMA_DECMP1_SETTING_g_Y_sat_en_shift                                         (15)
#define GDMA_DECMP1_SETTING_g_Y_sat_en_mask                                          (0x00008000)
#define GDMA_DECMP1_SETTING_g_Y_sat_en(data)                                         (0x00008000&((data)<<15))
#define GDMA_DECMP1_SETTING_g_Y_sat_en_src(data)                                     ((0x00008000&(data))>>15)
#define GDMA_DECMP1_SETTING_get_g_Y_sat_en(data)                                     ((0x00008000&(data))>>15)
#define GDMA_DECMP1_SETTING_r_cr_sat_en_shift                                        (14)
#define GDMA_DECMP1_SETTING_r_cr_sat_en_mask                                         (0x00004000)
#define GDMA_DECMP1_SETTING_r_cr_sat_en(data)                                        (0x00004000&((data)<<14))
#define GDMA_DECMP1_SETTING_r_cr_sat_en_src(data)                                    ((0x00004000&(data))>>14)
#define GDMA_DECMP1_SETTING_get_r_cr_sat_en(data)                                    ((0x00004000&(data))>>14)
#define GDMA_DECMP1_SETTING_decmp_frame_bits_shift                                   (8)
#define GDMA_DECMP1_SETTING_decmp_frame_bits_mask                                    (0x00003F00)
#define GDMA_DECMP1_SETTING_decmp_frame_bits(data)                                   (0x00003F00&((data)<<8))
#define GDMA_DECMP1_SETTING_decmp_frame_bits_src(data)                               ((0x00003F00&(data))>>8)
#define GDMA_DECMP1_SETTING_get_decmp_frame_bits(data)                               ((0x00003F00&(data))>>8)
#define GDMA_DECMP1_SETTING_decmp_a_ch_mark_shift                                    (5)
#define GDMA_DECMP1_SETTING_decmp_a_ch_mark_mask                                     (0x00000020)
#define GDMA_DECMP1_SETTING_decmp_a_ch_mark(data)                                    (0x00000020&((data)<<5))
#define GDMA_DECMP1_SETTING_decmp_a_ch_mark_src(data)                                ((0x00000020&(data))>>5)
#define GDMA_DECMP1_SETTING_get_decmp_a_ch_mark(data)                                ((0x00000020&(data))>>5)
#define GDMA_DECMP1_SETTING_decmp_444to422_en_shift                                  (4)
#define GDMA_DECMP1_SETTING_decmp_444to422_en_mask                                   (0x00000010)
#define GDMA_DECMP1_SETTING_decmp_444to422_en(data)                                  (0x00000010&((data)<<4))
#define GDMA_DECMP1_SETTING_decmp_444to422_en_src(data)                              ((0x00000010&(data))>>4)
#define GDMA_DECMP1_SETTING_get_decmp_444to422_en(data)                              ((0x00000010&(data))>>4)
#define GDMA_DECMP1_SETTING_decmp_RGB_YC_sel_shift                                   (3)
#define GDMA_DECMP1_SETTING_decmp_RGB_YC_sel_mask                                    (0x00000008)
#define GDMA_DECMP1_SETTING_decmp_RGB_YC_sel(data)                                   (0x00000008&((data)<<3))
#define GDMA_DECMP1_SETTING_decmp_RGB_YC_sel_src(data)                               ((0x00000008&(data))>>3)
#define GDMA_DECMP1_SETTING_get_decmp_RGB_YC_sel(data)                               ((0x00000008&(data))>>3)
#define GDMA_DECMP1_SETTING_decmp_channel_bits_shift                                 (2)
#define GDMA_DECMP1_SETTING_decmp_channel_bits_mask                                  (0x00000004)
#define GDMA_DECMP1_SETTING_decmp_channel_bits(data)                                 (0x00000004&((data)<<2))
#define GDMA_DECMP1_SETTING_decmp_channel_bits_src(data)                             ((0x00000004&(data))>>2)
#define GDMA_DECMP1_SETTING_get_decmp_channel_bits(data)                             ((0x00000004&(data))>>2)
#define GDMA_DECMP1_SETTING_decmp_CbCr_recov_shift                                   (1)
#define GDMA_DECMP1_SETTING_decmp_CbCr_recov_mask                                    (0x00000002)
#define GDMA_DECMP1_SETTING_decmp_CbCr_recov(data)                                   (0x00000002&((data)<<1))
#define GDMA_DECMP1_SETTING_decmp_CbCr_recov_src(data)                               ((0x00000002&(data))>>1)
#define GDMA_DECMP1_SETTING_get_decmp_CbCr_recov(data)                               ((0x00000002&(data))>>1)
#define GDMA_DECMP1_SETTING_decmp_fl_mode_shift                                      (0)
#define GDMA_DECMP1_SETTING_decmp_fl_mode_mask                                       (0x00000001)
#define GDMA_DECMP1_SETTING_decmp_fl_mode(data)                                      (0x00000001&((data)<<0))
#define GDMA_DECMP1_SETTING_decmp_fl_mode_src(data)                                  ((0x00000001&(data))>>0)
#define GDMA_DECMP1_SETTING_get_decmp_fl_mode(data)                                  ((0x00000001&(data))>>0)


#define GDMA_DECMP1_TRUNC_MARK                                                       0x1802f708
#define GDMA_DECMP1_TRUNC_MARK_reg_addr                                              "0xB802F708"
#define GDMA_DECMP1_TRUNC_MARK_reg                                                   0xB802F708
#define set_GDMA_DECMP1_TRUNC_MARK_reg(data)   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_MARK_reg)=data)
#define get_GDMA_DECMP1_TRUNC_MARK_reg   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_MARK_reg))
#define GDMA_DECMP1_TRUNC_MARK_inst_adr                                              "0x00C2"
#define GDMA_DECMP1_TRUNC_MARK_inst                                                  0x00C2
#define GDMA_DECMP1_TRUNC_MARK_mark_en_9_shift                                       (9)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_9_mask                                        (0x00000200)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_9(data)                                       (0x00000200&((data)<<9))
#define GDMA_DECMP1_TRUNC_MARK_mark_en_9_src(data)                                   ((0x00000200&(data))>>9)
#define GDMA_DECMP1_TRUNC_MARK_get_mark_en_9(data)                                   ((0x00000200&(data))>>9)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_8_shift                                       (8)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_8_mask                                        (0x00000100)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_8(data)                                       (0x00000100&((data)<<8))
#define GDMA_DECMP1_TRUNC_MARK_mark_en_8_src(data)                                   ((0x00000100&(data))>>8)
#define GDMA_DECMP1_TRUNC_MARK_get_mark_en_8(data)                                   ((0x00000100&(data))>>8)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_7_shift                                       (7)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_7_mask                                        (0x00000080)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_7(data)                                       (0x00000080&((data)<<7))
#define GDMA_DECMP1_TRUNC_MARK_mark_en_7_src(data)                                   ((0x00000080&(data))>>7)
#define GDMA_DECMP1_TRUNC_MARK_get_mark_en_7(data)                                   ((0x00000080&(data))>>7)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_6_shift                                       (6)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_6_mask                                        (0x00000040)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_6(data)                                       (0x00000040&((data)<<6))
#define GDMA_DECMP1_TRUNC_MARK_mark_en_6_src(data)                                   ((0x00000040&(data))>>6)
#define GDMA_DECMP1_TRUNC_MARK_get_mark_en_6(data)                                   ((0x00000040&(data))>>6)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_5_shift                                       (5)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_5_mask                                        (0x00000020)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_5(data)                                       (0x00000020&((data)<<5))
#define GDMA_DECMP1_TRUNC_MARK_mark_en_5_src(data)                                   ((0x00000020&(data))>>5)
#define GDMA_DECMP1_TRUNC_MARK_get_mark_en_5(data)                                   ((0x00000020&(data))>>5)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_4_shift                                       (4)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_4_mask                                        (0x00000010)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_4(data)                                       (0x00000010&((data)<<4))
#define GDMA_DECMP1_TRUNC_MARK_mark_en_4_src(data)                                   ((0x00000010&(data))>>4)
#define GDMA_DECMP1_TRUNC_MARK_get_mark_en_4(data)                                   ((0x00000010&(data))>>4)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_3_shift                                       (3)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_3_mask                                        (0x00000008)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_3(data)                                       (0x00000008&((data)<<3))
#define GDMA_DECMP1_TRUNC_MARK_mark_en_3_src(data)                                   ((0x00000008&(data))>>3)
#define GDMA_DECMP1_TRUNC_MARK_get_mark_en_3(data)                                   ((0x00000008&(data))>>3)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_2_shift                                       (2)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_2_mask                                        (0x00000004)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_2(data)                                       (0x00000004&((data)<<2))
#define GDMA_DECMP1_TRUNC_MARK_mark_en_2_src(data)                                   ((0x00000004&(data))>>2)
#define GDMA_DECMP1_TRUNC_MARK_get_mark_en_2(data)                                   ((0x00000004&(data))>>2)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_1_shift                                       (1)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_1_mask                                        (0x00000002)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_1(data)                                       (0x00000002&((data)<<1))
#define GDMA_DECMP1_TRUNC_MARK_mark_en_1_src(data)                                   ((0x00000002&(data))>>1)
#define GDMA_DECMP1_TRUNC_MARK_get_mark_en_1(data)                                   ((0x00000002&(data))>>1)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_0_shift                                       (0)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_0_mask                                        (0x00000001)
#define GDMA_DECMP1_TRUNC_MARK_mark_en_0(data)                                       (0x00000001&((data)<<0))
#define GDMA_DECMP1_TRUNC_MARK_mark_en_0_src(data)                                   ((0x00000001&(data))>>0)
#define GDMA_DECMP1_TRUNC_MARK_get_mark_en_0(data)                                   ((0x00000001&(data))>>0)


#define GDMA_DECMP1_TRUNC_COLOR_0                                                    0x1802f70c
#define GDMA_DECMP1_TRUNC_COLOR_0_reg_addr                                           "0xB802F70C"
#define GDMA_DECMP1_TRUNC_COLOR_0_reg                                                0xB802F70C
#define set_GDMA_DECMP1_TRUNC_COLOR_0_reg(data)   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_COLOR_0_reg)=data)
#define get_GDMA_DECMP1_TRUNC_COLOR_0_reg   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_COLOR_0_reg))
#define GDMA_DECMP1_TRUNC_COLOR_0_inst_adr                                           "0x00C3"
#define GDMA_DECMP1_TRUNC_COLOR_0_inst                                               0x00C3
#define GDMA_DECMP1_TRUNC_COLOR_0_mark_color_0_shift                                 (16)
#define GDMA_DECMP1_TRUNC_COLOR_0_mark_color_0_mask                                  (0xFFFF0000)
#define GDMA_DECMP1_TRUNC_COLOR_0_mark_color_0(data)                                 (0xFFFF0000&((data)<<16))
#define GDMA_DECMP1_TRUNC_COLOR_0_mark_color_0_src(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP1_TRUNC_COLOR_0_get_mark_color_0(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP1_TRUNC_COLOR_0_mark_color_1_shift                                 (0)
#define GDMA_DECMP1_TRUNC_COLOR_0_mark_color_1_mask                                  (0x0000FFFF)
#define GDMA_DECMP1_TRUNC_COLOR_0_mark_color_1(data)                                 (0x0000FFFF&((data)<<0))
#define GDMA_DECMP1_TRUNC_COLOR_0_mark_color_1_src(data)                             ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP1_TRUNC_COLOR_0_get_mark_color_1(data)                             ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP1_TRUNC_COLOR_1                                                    0x1802f710
#define GDMA_DECMP1_TRUNC_COLOR_1_reg_addr                                           "0xB802F710"
#define GDMA_DECMP1_TRUNC_COLOR_1_reg                                                0xB802F710
#define set_GDMA_DECMP1_TRUNC_COLOR_1_reg(data)   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_COLOR_1_reg)=data)
#define get_GDMA_DECMP1_TRUNC_COLOR_1_reg   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_COLOR_1_reg))
#define GDMA_DECMP1_TRUNC_COLOR_1_inst_adr                                           "0x00C4"
#define GDMA_DECMP1_TRUNC_COLOR_1_inst                                               0x00C4
#define GDMA_DECMP1_TRUNC_COLOR_1_mark_color_2_shift                                 (16)
#define GDMA_DECMP1_TRUNC_COLOR_1_mark_color_2_mask                                  (0xFFFF0000)
#define GDMA_DECMP1_TRUNC_COLOR_1_mark_color_2(data)                                 (0xFFFF0000&((data)<<16))
#define GDMA_DECMP1_TRUNC_COLOR_1_mark_color_2_src(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP1_TRUNC_COLOR_1_get_mark_color_2(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP1_TRUNC_COLOR_1_mark_color_3_shift                                 (0)
#define GDMA_DECMP1_TRUNC_COLOR_1_mark_color_3_mask                                  (0x0000FFFF)
#define GDMA_DECMP1_TRUNC_COLOR_1_mark_color_3(data)                                 (0x0000FFFF&((data)<<0))
#define GDMA_DECMP1_TRUNC_COLOR_1_mark_color_3_src(data)                             ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP1_TRUNC_COLOR_1_get_mark_color_3(data)                             ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP1_TRUNC_COLOR_2                                                    0x1802f714
#define GDMA_DECMP1_TRUNC_COLOR_2_reg_addr                                           "0xB802F714"
#define GDMA_DECMP1_TRUNC_COLOR_2_reg                                                0xB802F714
#define set_GDMA_DECMP1_TRUNC_COLOR_2_reg(data)   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_COLOR_2_reg)=data)
#define get_GDMA_DECMP1_TRUNC_COLOR_2_reg   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_COLOR_2_reg))
#define GDMA_DECMP1_TRUNC_COLOR_2_inst_adr                                           "0x00C5"
#define GDMA_DECMP1_TRUNC_COLOR_2_inst                                               0x00C5
#define GDMA_DECMP1_TRUNC_COLOR_2_mark_color_4_shift                                 (16)
#define GDMA_DECMP1_TRUNC_COLOR_2_mark_color_4_mask                                  (0xFFFF0000)
#define GDMA_DECMP1_TRUNC_COLOR_2_mark_color_4(data)                                 (0xFFFF0000&((data)<<16))
#define GDMA_DECMP1_TRUNC_COLOR_2_mark_color_4_src(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP1_TRUNC_COLOR_2_get_mark_color_4(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP1_TRUNC_COLOR_2_mark_color_5_shift                                 (0)
#define GDMA_DECMP1_TRUNC_COLOR_2_mark_color_5_mask                                  (0x0000FFFF)
#define GDMA_DECMP1_TRUNC_COLOR_2_mark_color_5(data)                                 (0x0000FFFF&((data)<<0))
#define GDMA_DECMP1_TRUNC_COLOR_2_mark_color_5_src(data)                             ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP1_TRUNC_COLOR_2_get_mark_color_5(data)                             ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP1_TRUNC_COLOR_3                                                    0x1802f718
#define GDMA_DECMP1_TRUNC_COLOR_3_reg_addr                                           "0xB802F718"
#define GDMA_DECMP1_TRUNC_COLOR_3_reg                                                0xB802F718
#define set_GDMA_DECMP1_TRUNC_COLOR_3_reg(data)   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_COLOR_3_reg)=data)
#define get_GDMA_DECMP1_TRUNC_COLOR_3_reg   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_COLOR_3_reg))
#define GDMA_DECMP1_TRUNC_COLOR_3_inst_adr                                           "0x00C6"
#define GDMA_DECMP1_TRUNC_COLOR_3_inst                                               0x00C6
#define GDMA_DECMP1_TRUNC_COLOR_3_mark_color_6_shift                                 (16)
#define GDMA_DECMP1_TRUNC_COLOR_3_mark_color_6_mask                                  (0xFFFF0000)
#define GDMA_DECMP1_TRUNC_COLOR_3_mark_color_6(data)                                 (0xFFFF0000&((data)<<16))
#define GDMA_DECMP1_TRUNC_COLOR_3_mark_color_6_src(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP1_TRUNC_COLOR_3_get_mark_color_6(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP1_TRUNC_COLOR_3_mark_color_7_shift                                 (0)
#define GDMA_DECMP1_TRUNC_COLOR_3_mark_color_7_mask                                  (0x0000FFFF)
#define GDMA_DECMP1_TRUNC_COLOR_3_mark_color_7(data)                                 (0x0000FFFF&((data)<<0))
#define GDMA_DECMP1_TRUNC_COLOR_3_mark_color_7_src(data)                             ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP1_TRUNC_COLOR_3_get_mark_color_7(data)                             ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP1_TRUNC_COLOR_4                                                    0x1802f71c
#define GDMA_DECMP1_TRUNC_COLOR_4_reg_addr                                           "0xB802F71C"
#define GDMA_DECMP1_TRUNC_COLOR_4_reg                                                0xB802F71C
#define set_GDMA_DECMP1_TRUNC_COLOR_4_reg(data)   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_COLOR_4_reg)=data)
#define get_GDMA_DECMP1_TRUNC_COLOR_4_reg   (*((volatile unsigned int*) GDMA_DECMP1_TRUNC_COLOR_4_reg))
#define GDMA_DECMP1_TRUNC_COLOR_4_inst_adr                                           "0x00C7"
#define GDMA_DECMP1_TRUNC_COLOR_4_inst                                               0x00C7
#define GDMA_DECMP1_TRUNC_COLOR_4_mark_color_8_shift                                 (16)
#define GDMA_DECMP1_TRUNC_COLOR_4_mark_color_8_mask                                  (0xFFFF0000)
#define GDMA_DECMP1_TRUNC_COLOR_4_mark_color_8(data)                                 (0xFFFF0000&((data)<<16))
#define GDMA_DECMP1_TRUNC_COLOR_4_mark_color_8_src(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP1_TRUNC_COLOR_4_get_mark_color_8(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP1_TRUNC_COLOR_4_mark_color_9_shift                                 (0)
#define GDMA_DECMP1_TRUNC_COLOR_4_mark_color_9_mask                                  (0x0000FFFF)
#define GDMA_DECMP1_TRUNC_COLOR_4_mark_color_9(data)                                 (0x0000FFFF&((data)<<0))
#define GDMA_DECMP1_TRUNC_COLOR_4_mark_color_9_src(data)                             ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP1_TRUNC_COLOR_4_get_mark_color_9(data)                             ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP2_RESOLUTION                                                       0x1802f720
#define GDMA_DECMP2_RESOLUTION_reg_addr                                              "0xB802F720"
#define GDMA_DECMP2_RESOLUTION_reg                                                   0xB802F720
#define set_GDMA_DECMP2_RESOLUTION_reg(data)   (*((volatile unsigned int*) GDMA_DECMP2_RESOLUTION_reg)=data)
#define get_GDMA_DECMP2_RESOLUTION_reg   (*((volatile unsigned int*) GDMA_DECMP2_RESOLUTION_reg))
#define GDMA_DECMP2_RESOLUTION_inst_adr                                              "0x00C8"
#define GDMA_DECMP2_RESOLUTION_inst                                                  0x00C8
#define GDMA_DECMP2_RESOLUTION_decmp_segment_shift                                   (24)
#define GDMA_DECMP2_RESOLUTION_decmp_segment_mask                                    (0x03000000)
#define GDMA_DECMP2_RESOLUTION_decmp_segment(data)                                   (0x03000000&((data)<<24))
#define GDMA_DECMP2_RESOLUTION_decmp_segment_src(data)                               ((0x03000000&(data))>>24)
#define GDMA_DECMP2_RESOLUTION_get_decmp_segment(data)                               ((0x03000000&(data))>>24)
#define GDMA_DECMP2_RESOLUTION_decmp_width_shift                                     (16)
#define GDMA_DECMP2_RESOLUTION_decmp_width_mask                                      (0x00FF0000)
#define GDMA_DECMP2_RESOLUTION_decmp_width(data)                                     (0x00FF0000&((data)<<16))
#define GDMA_DECMP2_RESOLUTION_decmp_width_src(data)                                 ((0x00FF0000&(data))>>16)
#define GDMA_DECMP2_RESOLUTION_get_decmp_width(data)                                 ((0x00FF0000&(data))>>16)
#define GDMA_DECMP2_RESOLUTION_decmp_height_shift                                    (0)
#define GDMA_DECMP2_RESOLUTION_decmp_height_mask                                     (0x0000FFFF)
#define GDMA_DECMP2_RESOLUTION_decmp_height(data)                                    (0x0000FFFF&((data)<<0))
#define GDMA_DECMP2_RESOLUTION_decmp_height_src(data)                                ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP2_RESOLUTION_get_decmp_height(data)                                ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP2_SETTING                                                          0x1802f724
#define GDMA_DECMP2_SETTING_reg_addr                                                 "0xB802F724"
#define GDMA_DECMP2_SETTING_reg                                                      0xB802F724
#define set_GDMA_DECMP2_SETTING_reg(data)   (*((volatile unsigned int*) GDMA_DECMP2_SETTING_reg)=data)
#define get_GDMA_DECMP2_SETTING_reg   (*((volatile unsigned int*) GDMA_DECMP2_SETTING_reg))
#define GDMA_DECMP2_SETTING_inst_adr                                                 "0x00C9"
#define GDMA_DECMP2_SETTING_inst                                                     0x00C9
#define GDMA_DECMP2_SETTING_a_sat_en_shift                                           (17)
#define GDMA_DECMP2_SETTING_a_sat_en_mask                                            (0x00020000)
#define GDMA_DECMP2_SETTING_a_sat_en(data)                                           (0x00020000&((data)<<17))
#define GDMA_DECMP2_SETTING_a_sat_en_src(data)                                       ((0x00020000&(data))>>17)
#define GDMA_DECMP2_SETTING_get_a_sat_en(data)                                       ((0x00020000&(data))>>17)
#define GDMA_DECMP2_SETTING_b_cb_sat_en_shift                                        (16)
#define GDMA_DECMP2_SETTING_b_cb_sat_en_mask                                         (0x00010000)
#define GDMA_DECMP2_SETTING_b_cb_sat_en(data)                                        (0x00010000&((data)<<16))
#define GDMA_DECMP2_SETTING_b_cb_sat_en_src(data)                                    ((0x00010000&(data))>>16)
#define GDMA_DECMP2_SETTING_get_b_cb_sat_en(data)                                    ((0x00010000&(data))>>16)
#define GDMA_DECMP2_SETTING_g_Y_sat_en_shift                                         (15)
#define GDMA_DECMP2_SETTING_g_Y_sat_en_mask                                          (0x00008000)
#define GDMA_DECMP2_SETTING_g_Y_sat_en(data)                                         (0x00008000&((data)<<15))
#define GDMA_DECMP2_SETTING_g_Y_sat_en_src(data)                                     ((0x00008000&(data))>>15)
#define GDMA_DECMP2_SETTING_get_g_Y_sat_en(data)                                     ((0x00008000&(data))>>15)
#define GDMA_DECMP2_SETTING_r_cr_sat_en_shift                                        (14)
#define GDMA_DECMP2_SETTING_r_cr_sat_en_mask                                         (0x00004000)
#define GDMA_DECMP2_SETTING_r_cr_sat_en(data)                                        (0x00004000&((data)<<14))
#define GDMA_DECMP2_SETTING_r_cr_sat_en_src(data)                                    ((0x00004000&(data))>>14)
#define GDMA_DECMP2_SETTING_get_r_cr_sat_en(data)                                    ((0x00004000&(data))>>14)
#define GDMA_DECMP2_SETTING_decmp_frame_bits_shift                                   (8)
#define GDMA_DECMP2_SETTING_decmp_frame_bits_mask                                    (0x00003F00)
#define GDMA_DECMP2_SETTING_decmp_frame_bits(data)                                   (0x00003F00&((data)<<8))
#define GDMA_DECMP2_SETTING_decmp_frame_bits_src(data)                               ((0x00003F00&(data))>>8)
#define GDMA_DECMP2_SETTING_get_decmp_frame_bits(data)                               ((0x00003F00&(data))>>8)
#define GDMA_DECMP2_SETTING_decmp_a_ch_mark_shift                                    (5)
#define GDMA_DECMP2_SETTING_decmp_a_ch_mark_mask                                     (0x00000020)
#define GDMA_DECMP2_SETTING_decmp_a_ch_mark(data)                                    (0x00000020&((data)<<5))
#define GDMA_DECMP2_SETTING_decmp_a_ch_mark_src(data)                                ((0x00000020&(data))>>5)
#define GDMA_DECMP2_SETTING_get_decmp_a_ch_mark(data)                                ((0x00000020&(data))>>5)
#define GDMA_DECMP2_SETTING_decmp_444to422_en_shift                                  (4)
#define GDMA_DECMP2_SETTING_decmp_444to422_en_mask                                   (0x00000010)
#define GDMA_DECMP2_SETTING_decmp_444to422_en(data)                                  (0x00000010&((data)<<4))
#define GDMA_DECMP2_SETTING_decmp_444to422_en_src(data)                              ((0x00000010&(data))>>4)
#define GDMA_DECMP2_SETTING_get_decmp_444to422_en(data)                              ((0x00000010&(data))>>4)
#define GDMA_DECMP2_SETTING_decmp_RGB_YC_sel_shift                                   (3)
#define GDMA_DECMP2_SETTING_decmp_RGB_YC_sel_mask                                    (0x00000008)
#define GDMA_DECMP2_SETTING_decmp_RGB_YC_sel(data)                                   (0x00000008&((data)<<3))
#define GDMA_DECMP2_SETTING_decmp_RGB_YC_sel_src(data)                               ((0x00000008&(data))>>3)
#define GDMA_DECMP2_SETTING_get_decmp_RGB_YC_sel(data)                               ((0x00000008&(data))>>3)
#define GDMA_DECMP2_SETTING_decmp_channel_bits_shift                                 (2)
#define GDMA_DECMP2_SETTING_decmp_channel_bits_mask                                  (0x00000004)
#define GDMA_DECMP2_SETTING_decmp_channel_bits(data)                                 (0x00000004&((data)<<2))
#define GDMA_DECMP2_SETTING_decmp_channel_bits_src(data)                             ((0x00000004&(data))>>2)
#define GDMA_DECMP2_SETTING_get_decmp_channel_bits(data)                             ((0x00000004&(data))>>2)
#define GDMA_DECMP2_SETTING_decmp_CbCr_recov_shift                                   (1)
#define GDMA_DECMP2_SETTING_decmp_CbCr_recov_mask                                    (0x00000002)
#define GDMA_DECMP2_SETTING_decmp_CbCr_recov(data)                                   (0x00000002&((data)<<1))
#define GDMA_DECMP2_SETTING_decmp_CbCr_recov_src(data)                               ((0x00000002&(data))>>1)
#define GDMA_DECMP2_SETTING_get_decmp_CbCr_recov(data)                               ((0x00000002&(data))>>1)
#define GDMA_DECMP2_SETTING_decmp_fl_mode_shift                                      (0)
#define GDMA_DECMP2_SETTING_decmp_fl_mode_mask                                       (0x00000001)
#define GDMA_DECMP2_SETTING_decmp_fl_mode(data)                                      (0x00000001&((data)<<0))
#define GDMA_DECMP2_SETTING_decmp_fl_mode_src(data)                                  ((0x00000001&(data))>>0)
#define GDMA_DECMP2_SETTING_get_decmp_fl_mode(data)                                  ((0x00000001&(data))>>0)


#define GDMA_DECMP2_TRUNC_MARK                                                       0x1802f728
#define GDMA_DECMP2_TRUNC_MARK_reg_addr                                              "0xB802F728"
#define GDMA_DECMP2_TRUNC_MARK_reg                                                   0xB802F728
#define set_GDMA_DECMP2_TRUNC_MARK_reg(data)   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_MARK_reg)=data)
#define get_GDMA_DECMP2_TRUNC_MARK_reg   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_MARK_reg))
#define GDMA_DECMP2_TRUNC_MARK_inst_adr                                              "0x00CA"
#define GDMA_DECMP2_TRUNC_MARK_inst                                                  0x00CA
#define GDMA_DECMP2_TRUNC_MARK_mark_en_9_shift                                       (9)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_9_mask                                        (0x00000200)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_9(data)                                       (0x00000200&((data)<<9))
#define GDMA_DECMP2_TRUNC_MARK_mark_en_9_src(data)                                   ((0x00000200&(data))>>9)
#define GDMA_DECMP2_TRUNC_MARK_get_mark_en_9(data)                                   ((0x00000200&(data))>>9)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_8_shift                                       (8)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_8_mask                                        (0x00000100)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_8(data)                                       (0x00000100&((data)<<8))
#define GDMA_DECMP2_TRUNC_MARK_mark_en_8_src(data)                                   ((0x00000100&(data))>>8)
#define GDMA_DECMP2_TRUNC_MARK_get_mark_en_8(data)                                   ((0x00000100&(data))>>8)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_7_shift                                       (7)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_7_mask                                        (0x00000080)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_7(data)                                       (0x00000080&((data)<<7))
#define GDMA_DECMP2_TRUNC_MARK_mark_en_7_src(data)                                   ((0x00000080&(data))>>7)
#define GDMA_DECMP2_TRUNC_MARK_get_mark_en_7(data)                                   ((0x00000080&(data))>>7)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_6_shift                                       (6)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_6_mask                                        (0x00000040)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_6(data)                                       (0x00000040&((data)<<6))
#define GDMA_DECMP2_TRUNC_MARK_mark_en_6_src(data)                                   ((0x00000040&(data))>>6)
#define GDMA_DECMP2_TRUNC_MARK_get_mark_en_6(data)                                   ((0x00000040&(data))>>6)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_5_shift                                       (5)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_5_mask                                        (0x00000020)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_5(data)                                       (0x00000020&((data)<<5))
#define GDMA_DECMP2_TRUNC_MARK_mark_en_5_src(data)                                   ((0x00000020&(data))>>5)
#define GDMA_DECMP2_TRUNC_MARK_get_mark_en_5(data)                                   ((0x00000020&(data))>>5)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_4_shift                                       (4)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_4_mask                                        (0x00000010)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_4(data)                                       (0x00000010&((data)<<4))
#define GDMA_DECMP2_TRUNC_MARK_mark_en_4_src(data)                                   ((0x00000010&(data))>>4)
#define GDMA_DECMP2_TRUNC_MARK_get_mark_en_4(data)                                   ((0x00000010&(data))>>4)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_3_shift                                       (3)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_3_mask                                        (0x00000008)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_3(data)                                       (0x00000008&((data)<<3))
#define GDMA_DECMP2_TRUNC_MARK_mark_en_3_src(data)                                   ((0x00000008&(data))>>3)
#define GDMA_DECMP2_TRUNC_MARK_get_mark_en_3(data)                                   ((0x00000008&(data))>>3)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_2_shift                                       (2)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_2_mask                                        (0x00000004)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_2(data)                                       (0x00000004&((data)<<2))
#define GDMA_DECMP2_TRUNC_MARK_mark_en_2_src(data)                                   ((0x00000004&(data))>>2)
#define GDMA_DECMP2_TRUNC_MARK_get_mark_en_2(data)                                   ((0x00000004&(data))>>2)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_1_shift                                       (1)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_1_mask                                        (0x00000002)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_1(data)                                       (0x00000002&((data)<<1))
#define GDMA_DECMP2_TRUNC_MARK_mark_en_1_src(data)                                   ((0x00000002&(data))>>1)
#define GDMA_DECMP2_TRUNC_MARK_get_mark_en_1(data)                                   ((0x00000002&(data))>>1)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_0_shift                                       (0)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_0_mask                                        (0x00000001)
#define GDMA_DECMP2_TRUNC_MARK_mark_en_0(data)                                       (0x00000001&((data)<<0))
#define GDMA_DECMP2_TRUNC_MARK_mark_en_0_src(data)                                   ((0x00000001&(data))>>0)
#define GDMA_DECMP2_TRUNC_MARK_get_mark_en_0(data)                                   ((0x00000001&(data))>>0)


#define GDMA_DECMP2_TRUNC_COLOR_0                                                    0x1802f72c
#define GDMA_DECMP2_TRUNC_COLOR_0_reg_addr                                           "0xB802F72C"
#define GDMA_DECMP2_TRUNC_COLOR_0_reg                                                0xB802F72C
#define set_GDMA_DECMP2_TRUNC_COLOR_0_reg(data)   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_COLOR_0_reg)=data)
#define get_GDMA_DECMP2_TRUNC_COLOR_0_reg   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_COLOR_0_reg))
#define GDMA_DECMP2_TRUNC_COLOR_0_inst_adr                                           "0x00CB"
#define GDMA_DECMP2_TRUNC_COLOR_0_inst                                               0x00CB
#define GDMA_DECMP2_TRUNC_COLOR_0_mark_color_0_shift                                 (16)
#define GDMA_DECMP2_TRUNC_COLOR_0_mark_color_0_mask                                  (0xFFFF0000)
#define GDMA_DECMP2_TRUNC_COLOR_0_mark_color_0(data)                                 (0xFFFF0000&((data)<<16))
#define GDMA_DECMP2_TRUNC_COLOR_0_mark_color_0_src(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP2_TRUNC_COLOR_0_get_mark_color_0(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP2_TRUNC_COLOR_0_mark_color_1_shift                                 (0)
#define GDMA_DECMP2_TRUNC_COLOR_0_mark_color_1_mask                                  (0x0000FFFF)
#define GDMA_DECMP2_TRUNC_COLOR_0_mark_color_1(data)                                 (0x0000FFFF&((data)<<0))
#define GDMA_DECMP2_TRUNC_COLOR_0_mark_color_1_src(data)                             ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP2_TRUNC_COLOR_0_get_mark_color_1(data)                             ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP2_TRUNC_COLOR_1                                                    0x1802f730
#define GDMA_DECMP2_TRUNC_COLOR_1_reg_addr                                           "0xB802F730"
#define GDMA_DECMP2_TRUNC_COLOR_1_reg                                                0xB802F730
#define set_GDMA_DECMP2_TRUNC_COLOR_1_reg(data)   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_COLOR_1_reg)=data)
#define get_GDMA_DECMP2_TRUNC_COLOR_1_reg   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_COLOR_1_reg))
#define GDMA_DECMP2_TRUNC_COLOR_1_inst_adr                                           "0x00CC"
#define GDMA_DECMP2_TRUNC_COLOR_1_inst                                               0x00CC
#define GDMA_DECMP2_TRUNC_COLOR_1_mark_color_2_shift                                 (16)
#define GDMA_DECMP2_TRUNC_COLOR_1_mark_color_2_mask                                  (0xFFFF0000)
#define GDMA_DECMP2_TRUNC_COLOR_1_mark_color_2(data)                                 (0xFFFF0000&((data)<<16))
#define GDMA_DECMP2_TRUNC_COLOR_1_mark_color_2_src(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP2_TRUNC_COLOR_1_get_mark_color_2(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP2_TRUNC_COLOR_1_mark_color_3_shift                                 (0)
#define GDMA_DECMP2_TRUNC_COLOR_1_mark_color_3_mask                                  (0x0000FFFF)
#define GDMA_DECMP2_TRUNC_COLOR_1_mark_color_3(data)                                 (0x0000FFFF&((data)<<0))
#define GDMA_DECMP2_TRUNC_COLOR_1_mark_color_3_src(data)                             ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP2_TRUNC_COLOR_1_get_mark_color_3(data)                             ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP2_TRUNC_COLOR_2                                                    0x1802f734
#define GDMA_DECMP2_TRUNC_COLOR_2_reg_addr                                           "0xB802F734"
#define GDMA_DECMP2_TRUNC_COLOR_2_reg                                                0xB802F734
#define set_GDMA_DECMP2_TRUNC_COLOR_2_reg(data)   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_COLOR_2_reg)=data)
#define get_GDMA_DECMP2_TRUNC_COLOR_2_reg   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_COLOR_2_reg))
#define GDMA_DECMP2_TRUNC_COLOR_2_inst_adr                                           "0x00CD"
#define GDMA_DECMP2_TRUNC_COLOR_2_inst                                               0x00CD
#define GDMA_DECMP2_TRUNC_COLOR_2_mark_color_4_shift                                 (16)
#define GDMA_DECMP2_TRUNC_COLOR_2_mark_color_4_mask                                  (0xFFFF0000)
#define GDMA_DECMP2_TRUNC_COLOR_2_mark_color_4(data)                                 (0xFFFF0000&((data)<<16))
#define GDMA_DECMP2_TRUNC_COLOR_2_mark_color_4_src(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP2_TRUNC_COLOR_2_get_mark_color_4(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP2_TRUNC_COLOR_2_mark_color_5_shift                                 (0)
#define GDMA_DECMP2_TRUNC_COLOR_2_mark_color_5_mask                                  (0x0000FFFF)
#define GDMA_DECMP2_TRUNC_COLOR_2_mark_color_5(data)                                 (0x0000FFFF&((data)<<0))
#define GDMA_DECMP2_TRUNC_COLOR_2_mark_color_5_src(data)                             ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP2_TRUNC_COLOR_2_get_mark_color_5(data)                             ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP2_TRUNC_COLOR_3                                                    0x1802f738
#define GDMA_DECMP2_TRUNC_COLOR_3_reg_addr                                           "0xB802F738"
#define GDMA_DECMP2_TRUNC_COLOR_3_reg                                                0xB802F738
#define set_GDMA_DECMP2_TRUNC_COLOR_3_reg(data)   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_COLOR_3_reg)=data)
#define get_GDMA_DECMP2_TRUNC_COLOR_3_reg   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_COLOR_3_reg))
#define GDMA_DECMP2_TRUNC_COLOR_3_inst_adr                                           "0x00CE"
#define GDMA_DECMP2_TRUNC_COLOR_3_inst                                               0x00CE
#define GDMA_DECMP2_TRUNC_COLOR_3_mark_color_6_shift                                 (16)
#define GDMA_DECMP2_TRUNC_COLOR_3_mark_color_6_mask                                  (0xFFFF0000)
#define GDMA_DECMP2_TRUNC_COLOR_3_mark_color_6(data)                                 (0xFFFF0000&((data)<<16))
#define GDMA_DECMP2_TRUNC_COLOR_3_mark_color_6_src(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP2_TRUNC_COLOR_3_get_mark_color_6(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP2_TRUNC_COLOR_3_mark_color_7_shift                                 (0)
#define GDMA_DECMP2_TRUNC_COLOR_3_mark_color_7_mask                                  (0x0000FFFF)
#define GDMA_DECMP2_TRUNC_COLOR_3_mark_color_7(data)                                 (0x0000FFFF&((data)<<0))
#define GDMA_DECMP2_TRUNC_COLOR_3_mark_color_7_src(data)                             ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP2_TRUNC_COLOR_3_get_mark_color_7(data)                             ((0x0000FFFF&(data))>>0)


#define GDMA_DECMP2_TRUNC_COLOR_4                                                    0x1802f73c
#define GDMA_DECMP2_TRUNC_COLOR_4_reg_addr                                           "0xB802F73C"
#define GDMA_DECMP2_TRUNC_COLOR_4_reg                                                0xB802F73C
#define set_GDMA_DECMP2_TRUNC_COLOR_4_reg(data)   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_COLOR_4_reg)=data)
#define get_GDMA_DECMP2_TRUNC_COLOR_4_reg   (*((volatile unsigned int*) GDMA_DECMP2_TRUNC_COLOR_4_reg))
#define GDMA_DECMP2_TRUNC_COLOR_4_inst_adr                                           "0x00CF"
#define GDMA_DECMP2_TRUNC_COLOR_4_inst                                               0x00CF
#define GDMA_DECMP2_TRUNC_COLOR_4_mark_color_8_shift                                 (16)
#define GDMA_DECMP2_TRUNC_COLOR_4_mark_color_8_mask                                  (0xFFFF0000)
#define GDMA_DECMP2_TRUNC_COLOR_4_mark_color_8(data)                                 (0xFFFF0000&((data)<<16))
#define GDMA_DECMP2_TRUNC_COLOR_4_mark_color_8_src(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP2_TRUNC_COLOR_4_get_mark_color_8(data)                             ((0xFFFF0000&(data))>>16)
#define GDMA_DECMP2_TRUNC_COLOR_4_mark_color_9_shift                                 (0)
#define GDMA_DECMP2_TRUNC_COLOR_4_mark_color_9_mask                                  (0x0000FFFF)
#define GDMA_DECMP2_TRUNC_COLOR_4_mark_color_9(data)                                 (0x0000FFFF&((data)<<0))
#define GDMA_DECMP2_TRUNC_COLOR_4_mark_color_9_src(data)                             ((0x0000FFFF&(data))>>0)
#define GDMA_DECMP2_TRUNC_COLOR_4_get_mark_color_9(data)                             ((0x0000FFFF&(data))>>0)


#define GDMA_FRAME_INST                                                              0x1802f740
#define GDMA_FRAME_INST_reg_addr                                                     "0xB802F740"
#define GDMA_FRAME_INST_reg                                                          0xB802F740
#define set_GDMA_FRAME_INST_reg(data)   (*((volatile unsigned int*) GDMA_FRAME_INST_reg)=data)
#define get_GDMA_FRAME_INST_reg   (*((volatile unsigned int*) GDMA_FRAME_INST_reg))
#define GDMA_FRAME_INST_inst_adr                                                     "0x00D0"
#define GDMA_FRAME_INST_inst                                                         0x00D0
#define GDMA_FRAME_INST_frm_cnt_2_shift                                              (20)
#define GDMA_FRAME_INST_frm_cnt_2_mask                                               (0x00F00000)
#define GDMA_FRAME_INST_frm_cnt_2(data)                                              (0x00F00000&((data)<<20))
#define GDMA_FRAME_INST_frm_cnt_2_src(data)                                          ((0x00F00000&(data))>>20)
#define GDMA_FRAME_INST_get_frm_cnt_2(data)                                          ((0x00F00000&(data))>>20)
#define GDMA_FRAME_INST_frm_cnt_1_shift                                              (16)
#define GDMA_FRAME_INST_frm_cnt_1_mask                                               (0x000F0000)
#define GDMA_FRAME_INST_frm_cnt_1(data)                                              (0x000F0000&((data)<<16))
#define GDMA_FRAME_INST_frm_cnt_1_src(data)                                          ((0x000F0000&(data))>>16)
#define GDMA_FRAME_INST_get_frm_cnt_1(data)                                          ((0x000F0000&(data))>>16)
#define GDMA_FRAME_INST_max_truncation_2_shift                                       (4)
#define GDMA_FRAME_INST_max_truncation_2_mask                                        (0x000000F0)
#define GDMA_FRAME_INST_max_truncation_2(data)                                       (0x000000F0&((data)<<4))
#define GDMA_FRAME_INST_max_truncation_2_src(data)                                   ((0x000000F0&(data))>>4)
#define GDMA_FRAME_INST_get_max_truncation_2(data)                                   ((0x000000F0&(data))>>4)
#define GDMA_FRAME_INST_max_truncation_1_shift                                       (0)
#define GDMA_FRAME_INST_max_truncation_1_mask                                        (0x0000000F)
#define GDMA_FRAME_INST_max_truncation_1(data)                                       (0x0000000F&((data)<<0))
#define GDMA_FRAME_INST_max_truncation_1_src(data)                                   ((0x0000000F&(data))>>0)
#define GDMA_FRAME_INST_get_max_truncation_1(data)                                   ((0x0000000F&(data))>>0)


#define GDMA_DECOMP_INTEN                                                            0x1802f744
#define GDMA_DECOMP_INTEN_reg_addr                                                   "0xB802F744"
#define GDMA_DECOMP_INTEN_reg                                                        0xB802F744
#define set_GDMA_DECOMP_INTEN_reg(data)   (*((volatile unsigned int*) GDMA_DECOMP_INTEN_reg)=data)
#define get_GDMA_DECOMP_INTEN_reg   (*((volatile unsigned int*) GDMA_DECOMP_INTEN_reg))
#define GDMA_DECOMP_INTEN_inst_adr                                                   "0x00D1"
#define GDMA_DECOMP_INTEN_inst                                                       0x00D1
#define GDMA_DECOMP_INTEN_head_error_clr_shift                                       (9)
#define GDMA_DECOMP_INTEN_head_error_clr_mask                                        (0x00000200)
#define GDMA_DECOMP_INTEN_head_error_clr(data)                                       (0x00000200&((data)<<9))
#define GDMA_DECOMP_INTEN_head_error_clr_src(data)                                   ((0x00000200&(data))>>9)
#define GDMA_DECOMP_INTEN_get_head_error_clr(data)                                   ((0x00000200&(data))>>9)
#define GDMA_DECOMP_INTEN_pix_fifo_underflow_clr_shift                               (8)
#define GDMA_DECOMP_INTEN_pix_fifo_underflow_clr_mask                                (0x00000100)
#define GDMA_DECOMP_INTEN_pix_fifo_underflow_clr(data)                               (0x00000100&((data)<<8))
#define GDMA_DECOMP_INTEN_pix_fifo_underflow_clr_src(data)                           ((0x00000100&(data))>>8)
#define GDMA_DECOMP_INTEN_get_pix_fifo_underflow_clr(data)                           ((0x00000100&(data))>>8)
#define GDMA_DECOMP_INTEN_head_error_irq_en2_shift                                   (5)
#define GDMA_DECOMP_INTEN_head_error_irq_en2_mask                                    (0x00000020)
#define GDMA_DECOMP_INTEN_head_error_irq_en2(data)                                   (0x00000020&((data)<<5))
#define GDMA_DECOMP_INTEN_head_error_irq_en2_src(data)                               ((0x00000020&(data))>>5)
#define GDMA_DECOMP_INTEN_get_head_error_irq_en2(data)                               ((0x00000020&(data))>>5)
#define GDMA_DECOMP_INTEN_head_error_irq_en1_shift                                   (4)
#define GDMA_DECOMP_INTEN_head_error_irq_en1_mask                                    (0x00000010)
#define GDMA_DECOMP_INTEN_head_error_irq_en1(data)                                   (0x00000010&((data)<<4))
#define GDMA_DECOMP_INTEN_head_error_irq_en1_src(data)                               ((0x00000010&(data))>>4)
#define GDMA_DECOMP_INTEN_get_head_error_irq_en1(data)                               ((0x00000010&(data))>>4)
#define GDMA_DECOMP_INTEN_underflow_irq_en2_shift                                    (1)
#define GDMA_DECOMP_INTEN_underflow_irq_en2_mask                                     (0x00000002)
#define GDMA_DECOMP_INTEN_underflow_irq_en2(data)                                    (0x00000002&((data)<<1))
#define GDMA_DECOMP_INTEN_underflow_irq_en2_src(data)                                ((0x00000002&(data))>>1)
#define GDMA_DECOMP_INTEN_get_underflow_irq_en2(data)                                ((0x00000002&(data))>>1)
#define GDMA_DECOMP_INTEN_underflow_irq_en1_shift                                    (0)
#define GDMA_DECOMP_INTEN_underflow_irq_en1_mask                                     (0x00000001)
#define GDMA_DECOMP_INTEN_underflow_irq_en1(data)                                    (0x00000001&((data)<<0))
#define GDMA_DECOMP_INTEN_underflow_irq_en1_src(data)                                ((0x00000001&(data))>>0)
#define GDMA_DECOMP_INTEN_get_underflow_irq_en1(data)                                ((0x00000001&(data))>>0)


#define GDMA_DECOMP_INTST                                                            0x1802f748
#define GDMA_DECOMP_INTST_reg_addr                                                   "0xB802F748"
#define GDMA_DECOMP_INTST_reg                                                        0xB802F748
#define set_GDMA_DECOMP_INTST_reg(data)   (*((volatile unsigned int*) GDMA_DECOMP_INTST_reg)=data)
#define get_GDMA_DECOMP_INTST_reg   (*((volatile unsigned int*) GDMA_DECOMP_INTST_reg))
#define GDMA_DECOMP_INTST_inst_adr                                                   "0x00D2"
#define GDMA_DECOMP_INTST_inst                                                       0x00D2
#define GDMA_DECOMP_INTST_decomp_irq_shift                                           (8)
#define GDMA_DECOMP_INTST_decomp_irq_mask                                            (0x00000100)
#define GDMA_DECOMP_INTST_decomp_irq(data)                                           (0x00000100&((data)<<8))
#define GDMA_DECOMP_INTST_decomp_irq_src(data)                                       ((0x00000100&(data))>>8)
#define GDMA_DECOMP_INTST_get_decomp_irq(data)                                       ((0x00000100&(data))>>8)
#define GDMA_DECOMP_INTST_head_error2_shift                                          (5)
#define GDMA_DECOMP_INTST_head_error2_mask                                           (0x00000020)
#define GDMA_DECOMP_INTST_head_error2(data)                                          (0x00000020&((data)<<5))
#define GDMA_DECOMP_INTST_head_error2_src(data)                                      ((0x00000020&(data))>>5)
#define GDMA_DECOMP_INTST_get_head_error2(data)                                      ((0x00000020&(data))>>5)
#define GDMA_DECOMP_INTST_head_error1_shift                                          (4)
#define GDMA_DECOMP_INTST_head_error1_mask                                           (0x00000010)
#define GDMA_DECOMP_INTST_head_error1(data)                                          (0x00000010&((data)<<4))
#define GDMA_DECOMP_INTST_head_error1_src(data)                                      ((0x00000010&(data))>>4)
#define GDMA_DECOMP_INTST_get_head_error1(data)                                      ((0x00000010&(data))>>4)
#define GDMA_DECOMP_INTST_pix_fifo_underflow2_shift                                  (1)
#define GDMA_DECOMP_INTST_pix_fifo_underflow2_mask                                   (0x00000002)
#define GDMA_DECOMP_INTST_pix_fifo_underflow2(data)                                  (0x00000002&((data)<<1))
#define GDMA_DECOMP_INTST_pix_fifo_underflow2_src(data)                              ((0x00000002&(data))>>1)
#define GDMA_DECOMP_INTST_get_pix_fifo_underflow2(data)                              ((0x00000002&(data))>>1)
#define GDMA_DECOMP_INTST_pix_fifo_underflow1_shift                                  (0)
#define GDMA_DECOMP_INTST_pix_fifo_underflow1_mask                                   (0x00000001)
#define GDMA_DECOMP_INTST_pix_fifo_underflow1(data)                                  (0x00000001&((data)<<0))
#define GDMA_DECOMP_INTST_pix_fifo_underflow1_src(data)                              ((0x00000001&(data))>>0)
#define GDMA_DECOMP_INTST_get_pix_fifo_underflow1(data)                              ((0x00000001&(data))>>0)


#define GDMA_DECOMP_DEBUG                                                            0x1802f74c
#define GDMA_DECOMP_DEBUG_reg_addr                                                   "0xB802F74C"
#define GDMA_DECOMP_DEBUG_reg                                                        0xB802F74C
#define set_GDMA_DECOMP_DEBUG_reg(data)   (*((volatile unsigned int*) GDMA_DECOMP_DEBUG_reg)=data)
#define get_GDMA_DECOMP_DEBUG_reg   (*((volatile unsigned int*) GDMA_DECOMP_DEBUG_reg))
#define GDMA_DECOMP_DEBUG_inst_adr                                                   "0x00D3"
#define GDMA_DECOMP_DEBUG_inst                                                       0x00D3
#define GDMA_DECOMP_DEBUG_sel_shift                                                  (16)
#define GDMA_DECOMP_DEBUG_sel_mask                                                   (0x00030000)
#define GDMA_DECOMP_DEBUG_sel(data)                                                  (0x00030000&((data)<<16))
#define GDMA_DECOMP_DEBUG_sel_src(data)                                              ((0x00030000&(data))>>16)
#define GDMA_DECOMP_DEBUG_get_sel(data)                                              ((0x00030000&(data))>>16)
#define GDMA_DECOMP_DEBUG_mux_shift                                                  (8)
#define GDMA_DECOMP_DEBUG_mux_mask                                                   (0x0000FF00)
#define GDMA_DECOMP_DEBUG_mux(data)                                                  (0x0000FF00&((data)<<8))
#define GDMA_DECOMP_DEBUG_mux_src(data)                                              ((0x0000FF00&(data))>>8)
#define GDMA_DECOMP_DEBUG_get_mux(data)                                              ((0x0000FF00&(data))>>8)


#define GDMA_DECOMP1_CRC                                                             0x1802f750
#define GDMA_DECOMP1_CRC_reg_addr                                                    "0xB802F750"
#define GDMA_DECOMP1_CRC_reg                                                         0xB802F750
#define set_GDMA_DECOMP1_CRC_reg(data)   (*((volatile unsigned int*) GDMA_DECOMP1_CRC_reg)=data)
#define get_GDMA_DECOMP1_CRC_reg   (*((volatile unsigned int*) GDMA_DECOMP1_CRC_reg))
#define GDMA_DECOMP1_CRC_inst_adr                                                    "0x00D4"
#define GDMA_DECOMP1_CRC_inst                                                        0x00D4
#define GDMA_DECOMP1_CRC_conti_shift                                                 (1)
#define GDMA_DECOMP1_CRC_conti_mask                                                  (0x00000002)
#define GDMA_DECOMP1_CRC_conti(data)                                                 (0x00000002&((data)<<1))
#define GDMA_DECOMP1_CRC_conti_src(data)                                             ((0x00000002&(data))>>1)
#define GDMA_DECOMP1_CRC_get_conti(data)                                             ((0x00000002&(data))>>1)
#define GDMA_DECOMP1_CRC_start_shift                                                 (0)
#define GDMA_DECOMP1_CRC_start_mask                                                  (0x00000001)
#define GDMA_DECOMP1_CRC_start(data)                                                 (0x00000001&((data)<<0))
#define GDMA_DECOMP1_CRC_start_src(data)                                             ((0x00000001&(data))>>0)
#define GDMA_DECOMP1_CRC_get_start(data)                                             ((0x00000001&(data))>>0)


#define GDMA_DECOMP1_CRC_RESULT                                                      0x1802f754
#define GDMA_DECOMP1_CRC_RESULT_reg_addr                                             "0xB802F754"
#define GDMA_DECOMP1_CRC_RESULT_reg                                                  0xB802F754
#define set_GDMA_DECOMP1_CRC_RESULT_reg(data)   (*((volatile unsigned int*) GDMA_DECOMP1_CRC_RESULT_reg)=data)
#define get_GDMA_DECOMP1_CRC_RESULT_reg   (*((volatile unsigned int*) GDMA_DECOMP1_CRC_RESULT_reg))
#define GDMA_DECOMP1_CRC_RESULT_inst_adr                                             "0x00D5"
#define GDMA_DECOMP1_CRC_RESULT_inst                                                 0x00D5
#define GDMA_DECOMP1_CRC_RESULT_result_shift                                         (0)
#define GDMA_DECOMP1_CRC_RESULT_result_mask                                          (0xFFFFFFFF)
#define GDMA_DECOMP1_CRC_RESULT_result(data)                                         (0xFFFFFFFF&((data)<<0))
#define GDMA_DECOMP1_CRC_RESULT_result_src(data)                                     ((0xFFFFFFFF&(data))>>0)
#define GDMA_DECOMP1_CRC_RESULT_get_result(data)                                     ((0xFFFFFFFF&(data))>>0)


#define GDMA_DECOMP2_CRC                                                             0x1802f758
#define GDMA_DECOMP2_CRC_reg_addr                                                    "0xB802F758"
#define GDMA_DECOMP2_CRC_reg                                                         0xB802F758
#define set_GDMA_DECOMP2_CRC_reg(data)   (*((volatile unsigned int*) GDMA_DECOMP2_CRC_reg)=data)
#define get_GDMA_DECOMP2_CRC_reg   (*((volatile unsigned int*) GDMA_DECOMP2_CRC_reg))
#define GDMA_DECOMP2_CRC_inst_adr                                                    "0x00D6"
#define GDMA_DECOMP2_CRC_inst                                                        0x00D6
#define GDMA_DECOMP2_CRC_conti_shift                                                 (1)
#define GDMA_DECOMP2_CRC_conti_mask                                                  (0x00000002)
#define GDMA_DECOMP2_CRC_conti(data)                                                 (0x00000002&((data)<<1))
#define GDMA_DECOMP2_CRC_conti_src(data)                                             ((0x00000002&(data))>>1)
#define GDMA_DECOMP2_CRC_get_conti(data)                                             ((0x00000002&(data))>>1)
#define GDMA_DECOMP2_CRC_start_shift                                                 (0)
#define GDMA_DECOMP2_CRC_start_mask                                                  (0x00000001)
#define GDMA_DECOMP2_CRC_start(data)                                                 (0x00000001&((data)<<0))
#define GDMA_DECOMP2_CRC_start_src(data)                                             ((0x00000001&(data))>>0)
#define GDMA_DECOMP2_CRC_get_start(data)                                             ((0x00000001&(data))>>0)


#define GDMA_DECOMP2_CRC_RESULT                                                      0x1802f75c
#define GDMA_DECOMP2_CRC_RESULT_reg_addr                                             "0xB802F75C"
#define GDMA_DECOMP2_CRC_RESULT_reg                                                  0xB802F75C
#define set_GDMA_DECOMP2_CRC_RESULT_reg(data)   (*((volatile unsigned int*) GDMA_DECOMP2_CRC_RESULT_reg)=data)
#define get_GDMA_DECOMP2_CRC_RESULT_reg   (*((volatile unsigned int*) GDMA_DECOMP2_CRC_RESULT_reg))
#define GDMA_DECOMP2_CRC_RESULT_inst_adr                                             "0x00D7"
#define GDMA_DECOMP2_CRC_RESULT_inst                                                 0x00D7
#define GDMA_DECOMP2_CRC_RESULT_result_shift                                         (0)
#define GDMA_DECOMP2_CRC_RESULT_result_mask                                          (0xFFFFFFFF)
#define GDMA_DECOMP2_CRC_RESULT_result(data)                                         (0xFFFFFFFF&((data)<<0))
#define GDMA_DECOMP2_CRC_RESULT_result_src(data)                                     ((0xFFFFFFFF&(data))>>0)
#define GDMA_DECOMP2_CRC_RESULT_get_result(data)                                     ((0xFFFFFFFF&(data))>>0)


#define GDMA_FBDC_OSD1_EN                                                            0x1802f800
#define GDMA_FBDC_OSD1_EN_reg_addr                                                   "0xB802F800"
#define GDMA_FBDC_OSD1_EN_reg                                                        0xB802F800
#define set_GDMA_FBDC_OSD1_EN_reg(data)   (*((volatile unsigned int*) GDMA_FBDC_OSD1_EN_reg)=data)
#define get_GDMA_FBDC_OSD1_EN_reg   (*((volatile unsigned int*) GDMA_FBDC_OSD1_EN_reg))
#define GDMA_FBDC_OSD1_EN_inst_adr                                                   "0x0000"
#define GDMA_FBDC_OSD1_EN_inst                                                       0x0000
#define GDMA_FBDC_OSD1_EN_fbdc3_prio_end_shift                                       (20)
#define GDMA_FBDC_OSD1_EN_fbdc3_prio_end_mask                                        (0x00F00000)
#define GDMA_FBDC_OSD1_EN_fbdc3_prio_end(data)                                       (0x00F00000&((data)<<20))
#define GDMA_FBDC_OSD1_EN_fbdc3_prio_end_src(data)                                   ((0x00F00000&(data))>>20)
#define GDMA_FBDC_OSD1_EN_get_fbdc3_prio_end(data)                                   ((0x00F00000&(data))>>20)
#define GDMA_FBDC_OSD1_EN_fbdc3_prio_beg_shift                                       (16)
#define GDMA_FBDC_OSD1_EN_fbdc3_prio_beg_mask                                        (0x000F0000)
#define GDMA_FBDC_OSD1_EN_fbdc3_prio_beg(data)                                       (0x000F0000&((data)<<16))
#define GDMA_FBDC_OSD1_EN_fbdc3_prio_beg_src(data)                                   ((0x000F0000&(data))>>16)
#define GDMA_FBDC_OSD1_EN_get_fbdc3_prio_beg(data)                                   ((0x000F0000&(data))>>16)
#define GDMA_FBDC_OSD1_EN_fbdc2_prio_end_shift                                       (12)
#define GDMA_FBDC_OSD1_EN_fbdc2_prio_end_mask                                        (0x0000F000)
#define GDMA_FBDC_OSD1_EN_fbdc2_prio_end(data)                                       (0x0000F000&((data)<<12))
#define GDMA_FBDC_OSD1_EN_fbdc2_prio_end_src(data)                                   ((0x0000F000&(data))>>12)
#define GDMA_FBDC_OSD1_EN_get_fbdc2_prio_end(data)                                   ((0x0000F000&(data))>>12)
#define GDMA_FBDC_OSD1_EN_fbdc2_prio_beg_shift                                       (8)
#define GDMA_FBDC_OSD1_EN_fbdc2_prio_beg_mask                                        (0x00000F00)
#define GDMA_FBDC_OSD1_EN_fbdc2_prio_beg(data)                                       (0x00000F00&((data)<<8))
#define GDMA_FBDC_OSD1_EN_fbdc2_prio_beg_src(data)                                   ((0x00000F00&(data))>>8)
#define GDMA_FBDC_OSD1_EN_get_fbdc2_prio_beg(data)                                   ((0x00000F00&(data))>>8)
#define GDMA_FBDC_OSD1_EN_fbdc1_prio_end_shift                                       (4)
#define GDMA_FBDC_OSD1_EN_fbdc1_prio_end_mask                                        (0x000000F0)
#define GDMA_FBDC_OSD1_EN_fbdc1_prio_end(data)                                       (0x000000F0&((data)<<4))
#define GDMA_FBDC_OSD1_EN_fbdc1_prio_end_src(data)                                   ((0x000000F0&(data))>>4)
#define GDMA_FBDC_OSD1_EN_get_fbdc1_prio_end(data)                                   ((0x000000F0&(data))>>4)
#define GDMA_FBDC_OSD1_EN_fbdc1_prio_beg_shift                                       (0)
#define GDMA_FBDC_OSD1_EN_fbdc1_prio_beg_mask                                        (0x0000000F)
#define GDMA_FBDC_OSD1_EN_fbdc1_prio_beg(data)                                       (0x0000000F&((data)<<0))
#define GDMA_FBDC_OSD1_EN_fbdc1_prio_beg_src(data)                                   ((0x0000000F&(data))>>0)
#define GDMA_FBDC_OSD1_EN_get_fbdc1_prio_beg(data)                                   ((0x0000000F&(data))>>0)


#define GDMA_FBDC_OSD2_EN                                                            0x1802f804
#define GDMA_FBDC_OSD2_EN_reg_addr                                                   "0xB802F804"
#define GDMA_FBDC_OSD2_EN_reg                                                        0xB802F804
#define set_GDMA_FBDC_OSD2_EN_reg(data)   (*((volatile unsigned int*) GDMA_FBDC_OSD2_EN_reg)=data)
#define get_GDMA_FBDC_OSD2_EN_reg   (*((volatile unsigned int*) GDMA_FBDC_OSD2_EN_reg))
#define GDMA_FBDC_OSD2_EN_inst_adr                                                   "0x0001"
#define GDMA_FBDC_OSD2_EN_inst                                                       0x0001
#define GDMA_FBDC_OSD2_EN_fbdc3_prio_end_shift                                       (20)
#define GDMA_FBDC_OSD2_EN_fbdc3_prio_end_mask                                        (0x00F00000)
#define GDMA_FBDC_OSD2_EN_fbdc3_prio_end(data)                                       (0x00F00000&((data)<<20))
#define GDMA_FBDC_OSD2_EN_fbdc3_prio_end_src(data)                                   ((0x00F00000&(data))>>20)
#define GDMA_FBDC_OSD2_EN_get_fbdc3_prio_end(data)                                   ((0x00F00000&(data))>>20)
#define GDMA_FBDC_OSD2_EN_fbdc3_prio_beg_shift                                       (16)
#define GDMA_FBDC_OSD2_EN_fbdc3_prio_beg_mask                                        (0x000F0000)
#define GDMA_FBDC_OSD2_EN_fbdc3_prio_beg(data)                                       (0x000F0000&((data)<<16))
#define GDMA_FBDC_OSD2_EN_fbdc3_prio_beg_src(data)                                   ((0x000F0000&(data))>>16)
#define GDMA_FBDC_OSD2_EN_get_fbdc3_prio_beg(data)                                   ((0x000F0000&(data))>>16)
#define GDMA_FBDC_OSD2_EN_fbdc2_prio_end_shift                                       (12)
#define GDMA_FBDC_OSD2_EN_fbdc2_prio_end_mask                                        (0x0000F000)
#define GDMA_FBDC_OSD2_EN_fbdc2_prio_end(data)                                       (0x0000F000&((data)<<12))
#define GDMA_FBDC_OSD2_EN_fbdc2_prio_end_src(data)                                   ((0x0000F000&(data))>>12)
#define GDMA_FBDC_OSD2_EN_get_fbdc2_prio_end(data)                                   ((0x0000F000&(data))>>12)
#define GDMA_FBDC_OSD2_EN_fbdc2_prio_beg_shift                                       (8)
#define GDMA_FBDC_OSD2_EN_fbdc2_prio_beg_mask                                        (0x00000F00)
#define GDMA_FBDC_OSD2_EN_fbdc2_prio_beg(data)                                       (0x00000F00&((data)<<8))
#define GDMA_FBDC_OSD2_EN_fbdc2_prio_beg_src(data)                                   ((0x00000F00&(data))>>8)
#define GDMA_FBDC_OSD2_EN_get_fbdc2_prio_beg(data)                                   ((0x00000F00&(data))>>8)
#define GDMA_FBDC_OSD2_EN_fbdc1_prio_end_shift                                       (4)
#define GDMA_FBDC_OSD2_EN_fbdc1_prio_end_mask                                        (0x000000F0)
#define GDMA_FBDC_OSD2_EN_fbdc1_prio_end(data)                                       (0x000000F0&((data)<<4))
#define GDMA_FBDC_OSD2_EN_fbdc1_prio_end_src(data)                                   ((0x000000F0&(data))>>4)
#define GDMA_FBDC_OSD2_EN_get_fbdc1_prio_end(data)                                   ((0x000000F0&(data))>>4)
#define GDMA_FBDC_OSD2_EN_fbdc1_prio_beg_shift                                       (0)
#define GDMA_FBDC_OSD2_EN_fbdc1_prio_beg_mask                                        (0x0000000F)
#define GDMA_FBDC_OSD2_EN_fbdc1_prio_beg(data)                                       (0x0000000F&((data)<<0))
#define GDMA_FBDC_OSD2_EN_fbdc1_prio_beg_src(data)                                   ((0x0000000F&(data))>>0)
#define GDMA_FBDC_OSD2_EN_get_fbdc1_prio_beg(data)                                   ((0x0000000F&(data))>>0)


#define GDMA_FBDC_OSD3_EN                                                            0x1802f808
#define GDMA_FBDC_OSD3_EN_reg_addr                                                   "0xB802F808"
#define GDMA_FBDC_OSD3_EN_reg                                                        0xB802F808
#define set_GDMA_FBDC_OSD3_EN_reg(data)   (*((volatile unsigned int*) GDMA_FBDC_OSD3_EN_reg)=data)
#define get_GDMA_FBDC_OSD3_EN_reg   (*((volatile unsigned int*) GDMA_FBDC_OSD3_EN_reg))
#define GDMA_FBDC_OSD3_EN_inst_adr                                                   "0x0002"
#define GDMA_FBDC_OSD3_EN_inst                                                       0x0002
#define GDMA_FBDC_OSD3_EN_fbdc3_prio_end_shift                                       (20)
#define GDMA_FBDC_OSD3_EN_fbdc3_prio_end_mask                                        (0x00F00000)
#define GDMA_FBDC_OSD3_EN_fbdc3_prio_end(data)                                       (0x00F00000&((data)<<20))
#define GDMA_FBDC_OSD3_EN_fbdc3_prio_end_src(data)                                   ((0x00F00000&(data))>>20)
#define GDMA_FBDC_OSD3_EN_get_fbdc3_prio_end(data)                                   ((0x00F00000&(data))>>20)
#define GDMA_FBDC_OSD3_EN_fbdc3_prio_beg_shift                                       (16)
#define GDMA_FBDC_OSD3_EN_fbdc3_prio_beg_mask                                        (0x000F0000)
#define GDMA_FBDC_OSD3_EN_fbdc3_prio_beg(data)                                       (0x000F0000&((data)<<16))
#define GDMA_FBDC_OSD3_EN_fbdc3_prio_beg_src(data)                                   ((0x000F0000&(data))>>16)
#define GDMA_FBDC_OSD3_EN_get_fbdc3_prio_beg(data)                                   ((0x000F0000&(data))>>16)
#define GDMA_FBDC_OSD3_EN_fbdc2_prio_end_shift                                       (12)
#define GDMA_FBDC_OSD3_EN_fbdc2_prio_end_mask                                        (0x0000F000)
#define GDMA_FBDC_OSD3_EN_fbdc2_prio_end(data)                                       (0x0000F000&((data)<<12))
#define GDMA_FBDC_OSD3_EN_fbdc2_prio_end_src(data)                                   ((0x0000F000&(data))>>12)
#define GDMA_FBDC_OSD3_EN_get_fbdc2_prio_end(data)                                   ((0x0000F000&(data))>>12)
#define GDMA_FBDC_OSD3_EN_fbdc2_prio_beg_shift                                       (8)
#define GDMA_FBDC_OSD3_EN_fbdc2_prio_beg_mask                                        (0x00000F00)
#define GDMA_FBDC_OSD3_EN_fbdc2_prio_beg(data)                                       (0x00000F00&((data)<<8))
#define GDMA_FBDC_OSD3_EN_fbdc2_prio_beg_src(data)                                   ((0x00000F00&(data))>>8)
#define GDMA_FBDC_OSD3_EN_get_fbdc2_prio_beg(data)                                   ((0x00000F00&(data))>>8)
#define GDMA_FBDC_OSD3_EN_fbdc1_prio_end_shift                                       (4)
#define GDMA_FBDC_OSD3_EN_fbdc1_prio_end_mask                                        (0x000000F0)
#define GDMA_FBDC_OSD3_EN_fbdc1_prio_end(data)                                       (0x000000F0&((data)<<4))
#define GDMA_FBDC_OSD3_EN_fbdc1_prio_end_src(data)                                   ((0x000000F0&(data))>>4)
#define GDMA_FBDC_OSD3_EN_get_fbdc1_prio_end(data)                                   ((0x000000F0&(data))>>4)
#define GDMA_FBDC_OSD3_EN_fbdc1_prio_beg_shift                                       (0)
#define GDMA_FBDC_OSD3_EN_fbdc1_prio_beg_mask                                        (0x0000000F)
#define GDMA_FBDC_OSD3_EN_fbdc1_prio_beg(data)                                       (0x0000000F&((data)<<0))
#define GDMA_FBDC_OSD3_EN_fbdc1_prio_beg_src(data)                                   ((0x0000000F&(data))>>0)
#define GDMA_FBDC_OSD3_EN_get_fbdc1_prio_beg(data)                                   ((0x0000000F&(data))>>0)


#define GDMA_FBDC                                                                    0x1802f810
#define GDMA_FBDC_reg_addr                                                           "0xB802F810"
#define GDMA_FBDC_reg                                                                0xB802F810
#define set_GDMA_FBDC_reg(data)   (*((volatile unsigned int*) GDMA_FBDC_reg)=data)
#define get_GDMA_FBDC_reg   (*((volatile unsigned int*) GDMA_FBDC_reg))
#define GDMA_FBDC_inst_adr                                                           "0x0004"
#define GDMA_FBDC_inst                                                               0x0004
#define GDMA_FBDC_dummy_shift                                                        (16)
#define GDMA_FBDC_dummy_mask                                                         (0xFFFF0000)
#define GDMA_FBDC_dummy(data)                                                        (0xFFFF0000&((data)<<16))
#define GDMA_FBDC_dummy_src(data)                                                    ((0xFFFF0000&(data))>>16)
#define GDMA_FBDC_get_dummy(data)                                                    ((0xFFFF0000&(data))>>16)
#define GDMA_FBDC_fmt16_swap_1b_shift                                                (4)
#define GDMA_FBDC_fmt16_swap_1b_mask                                                 (0x00000010)
#define GDMA_FBDC_fmt16_swap_1b(data)                                                (0x00000010&((data)<<4))
#define GDMA_FBDC_fmt16_swap_1b_src(data)                                            ((0x00000010&(data))>>4)
#define GDMA_FBDC_get_fmt16_swap_1b(data)                                            ((0x00000010&(data))>>4)
#define GDMA_FBDC_head_to_data_align_shift                                           (0)
#define GDMA_FBDC_head_to_data_align_mask                                            (0x00000003)
#define GDMA_FBDC_head_to_data_align(data)                                           (0x00000003&((data)<<0))
#define GDMA_FBDC_head_to_data_align_src(data)                                       ((0x00000003&(data))>>0)
#define GDMA_FBDC_get_head_to_data_align(data)                                       ((0x00000003&(data))>>0)


#define GDMA_FBDC_CORE                                                               0x1802f814
#define GDMA_FBDC_CORE_reg_addr                                                      "0xB802F814"
#define GDMA_FBDC_CORE_reg                                                           0xB802F814
#define set_GDMA_FBDC_CORE_reg(data)   (*((volatile unsigned int*) GDMA_FBDC_CORE_reg)=data)
#define get_GDMA_FBDC_CORE_reg   (*((volatile unsigned int*) GDMA_FBDC_CORE_reg))
#define GDMA_FBDC_CORE_inst_adr                                                      "0x0005"
#define GDMA_FBDC_CORE_inst                                                          0x0005
#define GDMA_FBDC_CORE_data_timing_error_shift                                       (1)
#define GDMA_FBDC_CORE_data_timing_error_mask                                        (0x00000002)
#define GDMA_FBDC_CORE_data_timing_error(data)                                       (0x00000002&((data)<<1))
#define GDMA_FBDC_CORE_data_timing_error_src(data)                                   ((0x00000002&(data))>>1)
#define GDMA_FBDC_CORE_get_data_timing_error(data)                                   ((0x00000002&(data))>>1)
#define GDMA_FBDC_CORE_head_timing_error_shift                                       (0)
#define GDMA_FBDC_CORE_head_timing_error_mask                                        (0x00000001)
#define GDMA_FBDC_CORE_head_timing_error(data)                                       (0x00000001&((data)<<0))
#define GDMA_FBDC_CORE_head_timing_error_src(data)                                   ((0x00000001&(data))>>0)
#define GDMA_FBDC_CORE_get_head_timing_error(data)                                   ((0x00000001&(data))>>0)


#define GDMA_FBDC_TIE                                                                0x1802f820
#define GDMA_FBDC_TIE_reg_addr                                                       "0xB802F820"
#define GDMA_FBDC_TIE_reg                                                            0xB802F820
#define set_GDMA_FBDC_TIE_reg(data)   (*((volatile unsigned int*) GDMA_FBDC_TIE_reg)=data)
#define get_GDMA_FBDC_TIE_reg   (*((volatile unsigned int*) GDMA_FBDC_TIE_reg))
#define GDMA_FBDC_TIE_inst_adr                                                       "0x0008"
#define GDMA_FBDC_TIE_inst                                                           0x0008
#define GDMA_FBDC_TIE_dtreq_tl_type_shift                                            (26)
#define GDMA_FBDC_TIE_dtreq_tl_type_mask                                             (0x04000000)
#define GDMA_FBDC_TIE_dtreq_tl_type(data)                                            (0x04000000&((data)<<26))
#define GDMA_FBDC_TIE_dtreq_tl_type_src(data)                                        ((0x04000000&(data))>>26)
#define GDMA_FBDC_TIE_get_dtreq_tl_type(data)                                        ((0x04000000&(data))>>26)
#define GDMA_FBDC_TIE_rgx_cr_clkgatestatus_req_clks_shift                            (25)
#define GDMA_FBDC_TIE_rgx_cr_clkgatestatus_req_clks_mask                             (0x02000000)
#define GDMA_FBDC_TIE_rgx_cr_clkgatestatus_req_clks(data)                            (0x02000000&((data)<<25))
#define GDMA_FBDC_TIE_rgx_cr_clkgatestatus_req_clks_src(data)                        ((0x02000000&(data))>>25)
#define GDMA_FBDC_TIE_get_rgx_cr_clkgatestatus_req_clks(data)                        ((0x02000000&(data))>>25)
#define GDMA_FBDC_TIE_rgx_cr_clkgatestatus_fbdc_clks_shift                           (24)
#define GDMA_FBDC_TIE_rgx_cr_clkgatestatus_fbdc_clks_mask                            (0x01000000)
#define GDMA_FBDC_TIE_rgx_cr_clkgatestatus_fbdc_clks(data)                           (0x01000000&((data)<<24))
#define GDMA_FBDC_TIE_rgx_cr_clkgatestatus_fbdc_clks_src(data)                       ((0x01000000&(data))>>24)
#define GDMA_FBDC_TIE_get_rgx_cr_clkgatestatus_fbdc_clks(data)                       ((0x01000000&(data))>>24)
#define GDMA_FBDC_TIE_dtreq_st_shift                                                 (22)
#define GDMA_FBDC_TIE_dtreq_st_mask                                                  (0x00400000)
#define GDMA_FBDC_TIE_dtreq_st(data)                                                 (0x00400000&((data)<<22))
#define GDMA_FBDC_TIE_dtreq_st_src(data)                                             ((0x00400000&(data))>>22)
#define GDMA_FBDC_TIE_get_dtreq_st(data)                                             ((0x00400000&(data))>>22)
#define GDMA_FBDC_TIE_dtreq_mem_mode_shift                                           (21)
#define GDMA_FBDC_TIE_dtreq_mem_mode_mask                                            (0x00200000)
#define GDMA_FBDC_TIE_dtreq_mem_mode(data)                                           (0x00200000&((data)<<21))
#define GDMA_FBDC_TIE_dtreq_mem_mode_src(data)                                       ((0x00200000&(data))>>21)
#define GDMA_FBDC_TIE_get_dtreq_mem_mode(data)                                       ((0x00200000&(data))>>21)
#define GDMA_FBDC_TIE_dtreq_fmsk_shift                                               (16)
#define GDMA_FBDC_TIE_dtreq_fmsk_mask                                                (0x001F0000)
#define GDMA_FBDC_TIE_dtreq_fmsk(data)                                               (0x001F0000&((data)<<16))
#define GDMA_FBDC_TIE_dtreq_fmsk_src(data)                                           ((0x001F0000&(data))>>16)
#define GDMA_FBDC_TIE_get_dtreq_fmsk(data)                                           ((0x001F0000&(data))>>16)
#define GDMA_FBDC_TIE_rgx_cr_fb_cdc_fbdc_compatibility_shift                         (0)
#define GDMA_FBDC_TIE_rgx_cr_fb_cdc_fbdc_compatibility_mask                          (0x0000FFFF)
#define GDMA_FBDC_TIE_rgx_cr_fb_cdc_fbdc_compatibility(data)                         (0x0000FFFF&((data)<<0))
#define GDMA_FBDC_TIE_rgx_cr_fb_cdc_fbdc_compatibility_src(data)                     ((0x0000FFFF&(data))>>0)
#define GDMA_FBDC_TIE_get_rgx_cr_fb_cdc_fbdc_compatibility(data)                     ((0x0000FFFF&(data))>>0)


#define GDMA_DMA_WL1                                                                 0x1802f900
#define GDMA_DMA_WL1_reg_addr                                                        "0xB802F900"
#define GDMA_DMA_WL1_reg                                                             0xB802F900
#define set_GDMA_DMA_WL1_reg(data)   (*((volatile unsigned int*) GDMA_DMA_WL1_reg)=data)
#define get_GDMA_DMA_WL1_reg   (*((volatile unsigned int*) GDMA_DMA_WL1_reg))
#define GDMA_DMA_WL1_inst_adr                                                        "0x0040"
#define GDMA_DMA_WL1_inst                                                            0x0040
#define GDMA_DMA_WL1_decmp1_shift                                                    (12)
#define GDMA_DMA_WL1_decmp1_mask                                                     (0x00FFF000)
#define GDMA_DMA_WL1_decmp1(data)                                                    (0x00FFF000&((data)<<12))
#define GDMA_DMA_WL1_decmp1_src(data)                                                ((0x00FFF000&(data))>>12)
#define GDMA_DMA_WL1_get_decmp1(data)                                                ((0x00FFF000&(data))>>12)


#define GDMA_DECMP1_SEG0                                                             0x1802f904
#define GDMA_DECMP1_SEG0_reg_addr                                                    "0xB802F904"
#define GDMA_DECMP1_SEG0_reg                                                         0xB802F904
#define set_GDMA_DECMP1_SEG0_reg(data)   (*((volatile unsigned int*) GDMA_DECMP1_SEG0_reg)=data)
#define get_GDMA_DECMP1_SEG0_reg   (*((volatile unsigned int*) GDMA_DECMP1_SEG0_reg))
#define GDMA_DECMP1_SEG0_inst_adr                                                    "0x0041"
#define GDMA_DECMP1_SEG0_inst                                                        0x0041
#define GDMA_DECMP1_SEG0_num_shift                                                   (0)
#define GDMA_DECMP1_SEG0_num_mask                                                    (0x00FFFFFF)
#define GDMA_DECMP1_SEG0_num(data)                                                   (0x00FFFFFF&((data)<<0))
#define GDMA_DECMP1_SEG0_num_src(data)                                               ((0x00FFFFFF&(data))>>0)
#define GDMA_DECMP1_SEG0_get_num(data)                                               ((0x00FFFFFF&(data))>>0)


#define GDMA_DECMP1_SEG0_3D                                                          0x1802f908
#define GDMA_DECMP1_SEG0_3D_reg_addr                                                 "0xB802F908"
#define GDMA_DECMP1_SEG0_3D_reg                                                      0xB802F908
#define set_GDMA_DECMP1_SEG0_3D_reg(data)   (*((volatile unsigned int*) GDMA_DECMP1_SEG0_3D_reg)=data)
#define get_GDMA_DECMP1_SEG0_3D_reg   (*((volatile unsigned int*) GDMA_DECMP1_SEG0_3D_reg))
#define GDMA_DECMP1_SEG0_3D_inst_adr                                                 "0x0042"
#define GDMA_DECMP1_SEG0_3D_inst                                                     0x0042
#define GDMA_DECMP1_SEG0_3D_num_shift                                                (0)
#define GDMA_DECMP1_SEG0_3D_num_mask                                                 (0x00FFFFFF)
#define GDMA_DECMP1_SEG0_3D_num(data)                                                (0x00FFFFFF&((data)<<0))
#define GDMA_DECMP1_SEG0_3D_num_src(data)                                            ((0x00FFFFFF&(data))>>0)
#define GDMA_DECMP1_SEG0_3D_get_num(data)                                            ((0x00FFFFFF&(data))>>0)


#define GDMA_DMA_WL2                                                                 0x1802f910
#define GDMA_DMA_WL2_reg_addr                                                        "0xB802F910"
#define GDMA_DMA_WL2_reg                                                             0xB802F910
#define set_GDMA_DMA_WL2_reg(data)   (*((volatile unsigned int*) GDMA_DMA_WL2_reg)=data)
#define get_GDMA_DMA_WL2_reg   (*((volatile unsigned int*) GDMA_DMA_WL2_reg))
#define GDMA_DMA_WL2_inst_adr                                                        "0x0044"
#define GDMA_DMA_WL2_inst                                                            0x0044
#define GDMA_DMA_WL2_decmp2_shift                                                    (12)
#define GDMA_DMA_WL2_decmp2_mask                                                     (0x00FFF000)
#define GDMA_DMA_WL2_decmp2(data)                                                    (0x00FFF000&((data)<<12))
#define GDMA_DMA_WL2_decmp2_src(data)                                                ((0x00FFF000&(data))>>12)
#define GDMA_DMA_WL2_get_decmp2(data)                                                ((0x00FFF000&(data))>>12)


#define GDMA_DECMP2_SEG0                                                             0x1802f914
#define GDMA_DECMP2_SEG0_reg_addr                                                    "0xB802F914"
#define GDMA_DECMP2_SEG0_reg                                                         0xB802F914
#define set_GDMA_DECMP2_SEG0_reg(data)   (*((volatile unsigned int*) GDMA_DECMP2_SEG0_reg)=data)
#define get_GDMA_DECMP2_SEG0_reg   (*((volatile unsigned int*) GDMA_DECMP2_SEG0_reg))
#define GDMA_DECMP2_SEG0_inst_adr                                                    "0x0045"
#define GDMA_DECMP2_SEG0_inst                                                        0x0045
#define GDMA_DECMP2_SEG0_num_shift                                                   (0)
#define GDMA_DECMP2_SEG0_num_mask                                                    (0x00FFFFFF)
#define GDMA_DECMP2_SEG0_num(data)                                                   (0x00FFFFFF&((data)<<0))
#define GDMA_DECMP2_SEG0_num_src(data)                                               ((0x00FFFFFF&(data))>>0)
#define GDMA_DECMP2_SEG0_get_num(data)                                               ((0x00FFFFFF&(data))>>0)


#define GDMA_DECMP2_SEG0_3D                                                          0x1802f918
#define GDMA_DECMP2_SEG0_3D_reg_addr                                                 "0xB802F918"
#define GDMA_DECMP2_SEG0_3D_reg                                                      0xB802F918
#define set_GDMA_DECMP2_SEG0_3D_reg(data)   (*((volatile unsigned int*) GDMA_DECMP2_SEG0_3D_reg)=data)
#define get_GDMA_DECMP2_SEG0_3D_reg   (*((volatile unsigned int*) GDMA_DECMP2_SEG0_3D_reg))
#define GDMA_DECMP2_SEG0_3D_inst_adr                                                 "0x0046"
#define GDMA_DECMP2_SEG0_3D_inst                                                     0x0046
#define GDMA_DECMP2_SEG0_3D_num_shift                                                (0)
#define GDMA_DECMP2_SEG0_3D_num_mask                                                 (0x00FFFFFF)
#define GDMA_DECMP2_SEG0_3D_num(data)                                                (0x00FFFFFF&((data)<<0))
#define GDMA_DECMP2_SEG0_3D_num_src(data)                                            ((0x00FFFFFF&(data))>>0)
#define GDMA_DECMP2_SEG0_3D_get_num(data)                                            ((0x00FFFFFF&(data))>>0)


#define GDMA_WRITE_BACK                                                              0x1802f91c
#define GDMA_WRITE_BACK_reg_addr                                                     "0xB802F91C"
#define GDMA_WRITE_BACK_reg                                                          0xB802F91C
#define set_GDMA_WRITE_BACK_reg(data)   (*((volatile unsigned int*) GDMA_WRITE_BACK_reg)=data)
#define get_GDMA_WRITE_BACK_reg   (*((volatile unsigned int*) GDMA_WRITE_BACK_reg))
#define GDMA_WRITE_BACK_inst_adr                                                     "0x0047"
#define GDMA_WRITE_BACK_inst                                                         0x0047
#define GDMA_WRITE_BACK_pitch_shift                                                  (16)
#define GDMA_WRITE_BACK_pitch_mask                                                   (0xFFFF0000)
#define GDMA_WRITE_BACK_pitch(data)                                                  (0xFFFF0000&((data)<<16))
#define GDMA_WRITE_BACK_pitch_src(data)                                              ((0xFFFF0000&(data))>>16)
#define GDMA_WRITE_BACK_get_pitch(data)                                              ((0xFFFF0000&(data))>>16)
#define GDMA_WRITE_BACK_pitch_3d_shift                                               (0)
#define GDMA_WRITE_BACK_pitch_3d_mask                                                (0x0000FFFF)
#define GDMA_WRITE_BACK_pitch_3d(data)                                               (0x0000FFFF&((data)<<0))
#define GDMA_WRITE_BACK_pitch_3d_src(data)                                           ((0x0000FFFF&(data))>>0)
#define GDMA_WRITE_BACK_get_pitch_3d(data)                                           ((0x0000FFFF&(data))>>0)


#define GDMA_DMA_BL_1                                                                0x1802f920
#define GDMA_DMA_BL_1_reg_addr                                                       "0xB802F920"
#define GDMA_DMA_BL_1_reg                                                            0xB802F920
#define set_GDMA_DMA_BL_1_reg(data)   (*((volatile unsigned int*) GDMA_DMA_BL_1_reg)=data)
#define get_GDMA_DMA_BL_1_reg   (*((volatile unsigned int*) GDMA_DMA_BL_1_reg))
#define GDMA_DMA_BL_1_inst_adr                                                       "0x0048"
#define GDMA_DMA_BL_1_inst                                                           0x0048
#define GDMA_DMA_BL_1_fbdc2_bl_shift                                                 (24)
#define GDMA_DMA_BL_1_fbdc2_bl_mask                                                  (0x7F000000)
#define GDMA_DMA_BL_1_fbdc2_bl(data)                                                 (0x7F000000&((data)<<24))
#define GDMA_DMA_BL_1_fbdc2_bl_src(data)                                             ((0x7F000000&(data))>>24)
#define GDMA_DMA_BL_1_get_fbdc2_bl(data)                                             ((0x7F000000&(data))>>24)
#define GDMA_DMA_BL_1_fbdc1_bl_shift                                                 (16)
#define GDMA_DMA_BL_1_fbdc1_bl_mask                                                  (0x007F0000)
#define GDMA_DMA_BL_1_fbdc1_bl(data)                                                 (0x007F0000&((data)<<16))
#define GDMA_DMA_BL_1_fbdc1_bl_src(data)                                             ((0x007F0000&(data))>>16)
#define GDMA_DMA_BL_1_get_fbdc1_bl(data)                                             ((0x007F0000&(data))>>16)
#define GDMA_DMA_BL_1_osd5_bl_shift                                                  (8)
#define GDMA_DMA_BL_1_osd5_bl_mask                                                   (0x00007F00)
#define GDMA_DMA_BL_1_osd5_bl(data)                                                  (0x00007F00&((data)<<8))
#define GDMA_DMA_BL_1_osd5_bl_src(data)                                              ((0x00007F00&(data))>>8)
#define GDMA_DMA_BL_1_get_osd5_bl(data)                                              ((0x00007F00&(data))>>8)
#define GDMA_DMA_BL_1_osd4_bl_shift                                                  (0)
#define GDMA_DMA_BL_1_osd4_bl_mask                                                   (0x0000007F)
#define GDMA_DMA_BL_1_osd4_bl(data)                                                  (0x0000007F&((data)<<0))
#define GDMA_DMA_BL_1_osd4_bl_src(data)                                              ((0x0000007F&(data))>>0)
#define GDMA_DMA_BL_1_get_osd4_bl(data)                                              ((0x0000007F&(data))>>0)


#define GDMA_DMA_BL_2                                                                0x1802f924
#define GDMA_DMA_BL_2_reg_addr                                                       "0xB802F924"
#define GDMA_DMA_BL_2_reg                                                            0xB802F924
#define set_GDMA_DMA_BL_2_reg(data)   (*((volatile unsigned int*) GDMA_DMA_BL_2_reg)=data)
#define get_GDMA_DMA_BL_2_reg   (*((volatile unsigned int*) GDMA_DMA_BL_2_reg))
#define GDMA_DMA_BL_2_inst_adr                                                       "0x0049"
#define GDMA_DMA_BL_2_inst                                                           0x0049
#define GDMA_DMA_BL_2_osd3_bl_shift                                                  (24)
#define GDMA_DMA_BL_2_osd3_bl_mask                                                   (0x7F000000)
#define GDMA_DMA_BL_2_osd3_bl(data)                                                  (0x7F000000&((data)<<24))
#define GDMA_DMA_BL_2_osd3_bl_src(data)                                              ((0x7F000000&(data))>>24)
#define GDMA_DMA_BL_2_get_osd3_bl(data)                                              ((0x7F000000&(data))>>24)
#define GDMA_DMA_BL_2_osd2_bl_shift                                                  (16)
#define GDMA_DMA_BL_2_osd2_bl_mask                                                   (0x007F0000)
#define GDMA_DMA_BL_2_osd2_bl(data)                                                  (0x007F0000&((data)<<16))
#define GDMA_DMA_BL_2_osd2_bl_src(data)                                              ((0x007F0000&(data))>>16)
#define GDMA_DMA_BL_2_get_osd2_bl(data)                                              ((0x007F0000&(data))>>16)
#define GDMA_DMA_BL_2_osd1_bl_shift                                                  (8)
#define GDMA_DMA_BL_2_osd1_bl_mask                                                   (0x00007F00)
#define GDMA_DMA_BL_2_osd1_bl(data)                                                  (0x00007F00&((data)<<8))
#define GDMA_DMA_BL_2_osd1_bl_src(data)                                              ((0x00007F00&(data))>>8)
#define GDMA_DMA_BL_2_get_osd1_bl(data)                                              ((0x00007F00&(data))>>8)
#define GDMA_DMA_BL_2_wdma_bl_shift                                                  (0)
#define GDMA_DMA_BL_2_wdma_bl_mask                                                   (0x0000007F)
#define GDMA_DMA_BL_2_wdma_bl(data)                                                  (0x0000007F&((data)<<0))
#define GDMA_DMA_BL_2_wdma_bl_src(data)                                              ((0x0000007F&(data))>>0)
#define GDMA_DMA_BL_2_get_wdma_bl(data)                                              ((0x0000007F&(data))>>0)


#define GDMA_DMA                                                                     0x1802f928
#define GDMA_DMA_reg_addr                                                            "0xB802F928"
#define GDMA_DMA_reg                                                                 0xB802F928
#define set_GDMA_DMA_reg(data)   (*((volatile unsigned int*) GDMA_DMA_reg)=data)
#define get_GDMA_DMA_reg   (*((volatile unsigned int*) GDMA_DMA_reg))
#define GDMA_DMA_inst_adr                                                            "0x004A"
#define GDMA_DMA_inst                                                                0x004A
#define GDMA_DMA_fbdc2_mask_shift                                                    (23)
#define GDMA_DMA_fbdc2_mask_mask                                                     (0x00800000)
#define GDMA_DMA_fbdc2_mask(data)                                                    (0x00800000&((data)<<23))
#define GDMA_DMA_fbdc2_mask_src(data)                                                ((0x00800000&(data))>>23)
#define GDMA_DMA_get_fbdc2_mask(data)                                                ((0x00800000&(data))>>23)
#define GDMA_DMA_fbdc1_mask_shift                                                    (22)
#define GDMA_DMA_fbdc1_mask_mask                                                     (0x00400000)
#define GDMA_DMA_fbdc1_mask(data)                                                    (0x00400000&((data)<<22))
#define GDMA_DMA_fbdc1_mask_src(data)                                                ((0x00400000&(data))>>22)
#define GDMA_DMA_get_fbdc1_mask(data)                                                ((0x00400000&(data))>>22)
#define GDMA_DMA_osd5_mask_shift                                                     (21)
#define GDMA_DMA_osd5_mask_mask                                                      (0x00200000)
#define GDMA_DMA_osd5_mask(data)                                                     (0x00200000&((data)<<21))
#define GDMA_DMA_osd5_mask_src(data)                                                 ((0x00200000&(data))>>21)
#define GDMA_DMA_get_osd5_mask(data)                                                 ((0x00200000&(data))>>21)
#define GDMA_DMA_osd4_mask_shift                                                     (20)
#define GDMA_DMA_osd4_mask_mask                                                      (0x00100000)
#define GDMA_DMA_osd4_mask(data)                                                     (0x00100000&((data)<<20))
#define GDMA_DMA_osd4_mask_src(data)                                                 ((0x00100000&(data))>>20)
#define GDMA_DMA_get_osd4_mask(data)                                                 ((0x00100000&(data))>>20)
#define GDMA_DMA_osd3_mask_shift                                                     (19)
#define GDMA_DMA_osd3_mask_mask                                                      (0x00080000)
#define GDMA_DMA_osd3_mask(data)                                                     (0x00080000&((data)<<19))
#define GDMA_DMA_osd3_mask_src(data)                                                 ((0x00080000&(data))>>19)
#define GDMA_DMA_get_osd3_mask(data)                                                 ((0x00080000&(data))>>19)
#define GDMA_DMA_osd2_mask_shift                                                     (18)
#define GDMA_DMA_osd2_mask_mask                                                      (0x00040000)
#define GDMA_DMA_osd2_mask(data)                                                     (0x00040000&((data)<<18))
#define GDMA_DMA_osd2_mask_src(data)                                                 ((0x00040000&(data))>>18)
#define GDMA_DMA_get_osd2_mask(data)                                                 ((0x00040000&(data))>>18)
#define GDMA_DMA_osd1_mask_shift                                                     (17)
#define GDMA_DMA_osd1_mask_mask                                                      (0x00020000)
#define GDMA_DMA_osd1_mask(data)                                                     (0x00020000&((data)<<17))
#define GDMA_DMA_osd1_mask_src(data)                                                 ((0x00020000&(data))>>17)
#define GDMA_DMA_get_osd1_mask(data)                                                 ((0x00020000&(data))>>17)
#define GDMA_DMA_wdma_mask_shift                                                     (16)
#define GDMA_DMA_wdma_mask_mask                                                      (0x00010000)
#define GDMA_DMA_wdma_mask(data)                                                     (0x00010000&((data)<<16))
#define GDMA_DMA_wdma_mask_src(data)                                                 ((0x00010000&(data))>>16)
#define GDMA_DMA_get_wdma_mask(data)                                                 ((0x00010000&(data))>>16)
#define GDMA_DMA_fbdc2_req_num_shift                                                 (14)
#define GDMA_DMA_fbdc2_req_num_mask                                                  (0x0000C000)
#define GDMA_DMA_fbdc2_req_num(data)                                                 (0x0000C000&((data)<<14))
#define GDMA_DMA_fbdc2_req_num_src(data)                                             ((0x0000C000&(data))>>14)
#define GDMA_DMA_get_fbdc2_req_num(data)                                             ((0x0000C000&(data))>>14)
#define GDMA_DMA_fbdc1_req_num_shift                                                 (12)
#define GDMA_DMA_fbdc1_req_num_mask                                                  (0x00003000)
#define GDMA_DMA_fbdc1_req_num(data)                                                 (0x00003000&((data)<<12))
#define GDMA_DMA_fbdc1_req_num_src(data)                                             ((0x00003000&(data))>>12)
#define GDMA_DMA_get_fbdc1_req_num(data)                                             ((0x00003000&(data))>>12)
#define GDMA_DMA_osd5_req_num_shift                                                  (10)
#define GDMA_DMA_osd5_req_num_mask                                                   (0x00000C00)
#define GDMA_DMA_osd5_req_num(data)                                                  (0x00000C00&((data)<<10))
#define GDMA_DMA_osd5_req_num_src(data)                                              ((0x00000C00&(data))>>10)
#define GDMA_DMA_get_osd5_req_num(data)                                              ((0x00000C00&(data))>>10)
#define GDMA_DMA_osd4_req_num_shift                                                  (8)
#define GDMA_DMA_osd4_req_num_mask                                                   (0x00000300)
#define GDMA_DMA_osd4_req_num(data)                                                  (0x00000300&((data)<<8))
#define GDMA_DMA_osd4_req_num_src(data)                                              ((0x00000300&(data))>>8)
#define GDMA_DMA_get_osd4_req_num(data)                                              ((0x00000300&(data))>>8)
#define GDMA_DMA_osd3_req_num_shift                                                  (6)
#define GDMA_DMA_osd3_req_num_mask                                                   (0x000000C0)
#define GDMA_DMA_osd3_req_num(data)                                                  (0x000000C0&((data)<<6))
#define GDMA_DMA_osd3_req_num_src(data)                                              ((0x000000C0&(data))>>6)
#define GDMA_DMA_get_osd3_req_num(data)                                              ((0x000000C0&(data))>>6)
#define GDMA_DMA_osd2_req_num_shift                                                  (4)
#define GDMA_DMA_osd2_req_num_mask                                                   (0x00000030)
#define GDMA_DMA_osd2_req_num(data)                                                  (0x00000030&((data)<<4))
#define GDMA_DMA_osd2_req_num_src(data)                                              ((0x00000030&(data))>>4)
#define GDMA_DMA_get_osd2_req_num(data)                                              ((0x00000030&(data))>>4)
#define GDMA_DMA_osd1_req_num_shift                                                  (2)
#define GDMA_DMA_osd1_req_num_mask                                                   (0x0000000C)
#define GDMA_DMA_osd1_req_num(data)                                                  (0x0000000C&((data)<<2))
#define GDMA_DMA_osd1_req_num_src(data)                                              ((0x0000000C&(data))>>2)
#define GDMA_DMA_get_osd1_req_num(data)                                              ((0x0000000C&(data))>>2)
#define GDMA_DMA_wdma_req_num_shift                                                  (0)
#define GDMA_DMA_wdma_req_num_mask                                                   (0x00000003)
#define GDMA_DMA_wdma_req_num(data)                                                  (0x00000003&((data)<<0))
#define GDMA_DMA_wdma_req_num_src(data)                                              ((0x00000003&(data))>>0)
#define GDMA_DMA_get_wdma_req_num(data)                                              ((0x00000003&(data))>>0)


#define GDMA_DMA_SWAP                                                                0x1802f92c
#define GDMA_DMA_SWAP_reg_addr                                                       "0xB802F92C"
#define GDMA_DMA_SWAP_reg                                                            0xB802F92C
#define set_GDMA_DMA_SWAP_reg(data)   (*((volatile unsigned int*) GDMA_DMA_SWAP_reg)=data)
#define get_GDMA_DMA_SWAP_reg   (*((volatile unsigned int*) GDMA_DMA_SWAP_reg))
#define GDMA_DMA_SWAP_inst_adr                                                       "0x004B"
#define GDMA_DMA_SWAP_inst                                                           0x004B
#define GDMA_DMA_SWAP_fbdc2_1b_shift                                                 (31)
#define GDMA_DMA_SWAP_fbdc2_1b_mask                                                  (0x80000000)
#define GDMA_DMA_SWAP_fbdc2_1b(data)                                                 (0x80000000&((data)<<31))
#define GDMA_DMA_SWAP_fbdc2_1b_src(data)                                             ((0x80000000&(data))>>31)
#define GDMA_DMA_SWAP_get_fbdc2_1b(data)                                             ((0x80000000&(data))>>31)
#define GDMA_DMA_SWAP_fbdc2_2b_shift                                                 (30)
#define GDMA_DMA_SWAP_fbdc2_2b_mask                                                  (0x40000000)
#define GDMA_DMA_SWAP_fbdc2_2b(data)                                                 (0x40000000&((data)<<30))
#define GDMA_DMA_SWAP_fbdc2_2b_src(data)                                             ((0x40000000&(data))>>30)
#define GDMA_DMA_SWAP_get_fbdc2_2b(data)                                             ((0x40000000&(data))>>30)
#define GDMA_DMA_SWAP_fbdc2_4b_shift                                                 (29)
#define GDMA_DMA_SWAP_fbdc2_4b_mask                                                  (0x20000000)
#define GDMA_DMA_SWAP_fbdc2_4b(data)                                                 (0x20000000&((data)<<29))
#define GDMA_DMA_SWAP_fbdc2_4b_src(data)                                             ((0x20000000&(data))>>29)
#define GDMA_DMA_SWAP_get_fbdc2_4b(data)                                             ((0x20000000&(data))>>29)
#define GDMA_DMA_SWAP_fbdc2_8b_shift                                                 (28)
#define GDMA_DMA_SWAP_fbdc2_8b_mask                                                  (0x10000000)
#define GDMA_DMA_SWAP_fbdc2_8b(data)                                                 (0x10000000&((data)<<28))
#define GDMA_DMA_SWAP_fbdc2_8b_src(data)                                             ((0x10000000&(data))>>28)
#define GDMA_DMA_SWAP_get_fbdc2_8b(data)                                             ((0x10000000&(data))>>28)
#define GDMA_DMA_SWAP_fbdc1_1b_shift                                                 (27)
#define GDMA_DMA_SWAP_fbdc1_1b_mask                                                  (0x08000000)
#define GDMA_DMA_SWAP_fbdc1_1b(data)                                                 (0x08000000&((data)<<27))
#define GDMA_DMA_SWAP_fbdc1_1b_src(data)                                             ((0x08000000&(data))>>27)
#define GDMA_DMA_SWAP_get_fbdc1_1b(data)                                             ((0x08000000&(data))>>27)
#define GDMA_DMA_SWAP_fbdc1_2b_shift                                                 (26)
#define GDMA_DMA_SWAP_fbdc1_2b_mask                                                  (0x04000000)
#define GDMA_DMA_SWAP_fbdc1_2b(data)                                                 (0x04000000&((data)<<26))
#define GDMA_DMA_SWAP_fbdc1_2b_src(data)                                             ((0x04000000&(data))>>26)
#define GDMA_DMA_SWAP_get_fbdc1_2b(data)                                             ((0x04000000&(data))>>26)
#define GDMA_DMA_SWAP_fbdc1_4b_shift                                                 (25)
#define GDMA_DMA_SWAP_fbdc1_4b_mask                                                  (0x02000000)
#define GDMA_DMA_SWAP_fbdc1_4b(data)                                                 (0x02000000&((data)<<25))
#define GDMA_DMA_SWAP_fbdc1_4b_src(data)                                             ((0x02000000&(data))>>25)
#define GDMA_DMA_SWAP_get_fbdc1_4b(data)                                             ((0x02000000&(data))>>25)
#define GDMA_DMA_SWAP_fbdc1_8b_shift                                                 (24)
#define GDMA_DMA_SWAP_fbdc1_8b_mask                                                  (0x01000000)
#define GDMA_DMA_SWAP_fbdc1_8b(data)                                                 (0x01000000&((data)<<24))
#define GDMA_DMA_SWAP_fbdc1_8b_src(data)                                             ((0x01000000&(data))>>24)
#define GDMA_DMA_SWAP_get_fbdc1_8b(data)                                             ((0x01000000&(data))>>24)
#define GDMA_DMA_SWAP_osd5_1b_shift                                                  (23)
#define GDMA_DMA_SWAP_osd5_1b_mask                                                   (0x00800000)
#define GDMA_DMA_SWAP_osd5_1b(data)                                                  (0x00800000&((data)<<23))
#define GDMA_DMA_SWAP_osd5_1b_src(data)                                              ((0x00800000&(data))>>23)
#define GDMA_DMA_SWAP_get_osd5_1b(data)                                              ((0x00800000&(data))>>23)
#define GDMA_DMA_SWAP_osd5_2b_shift                                                  (22)
#define GDMA_DMA_SWAP_osd5_2b_mask                                                   (0x00400000)
#define GDMA_DMA_SWAP_osd5_2b(data)                                                  (0x00400000&((data)<<22))
#define GDMA_DMA_SWAP_osd5_2b_src(data)                                              ((0x00400000&(data))>>22)
#define GDMA_DMA_SWAP_get_osd5_2b(data)                                              ((0x00400000&(data))>>22)
#define GDMA_DMA_SWAP_osd5_4b_shift                                                  (21)
#define GDMA_DMA_SWAP_osd5_4b_mask                                                   (0x00200000)
#define GDMA_DMA_SWAP_osd5_4b(data)                                                  (0x00200000&((data)<<21))
#define GDMA_DMA_SWAP_osd5_4b_src(data)                                              ((0x00200000&(data))>>21)
#define GDMA_DMA_SWAP_get_osd5_4b(data)                                              ((0x00200000&(data))>>21)
#define GDMA_DMA_SWAP_osd5_8b_shift                                                  (20)
#define GDMA_DMA_SWAP_osd5_8b_mask                                                   (0x00100000)
#define GDMA_DMA_SWAP_osd5_8b(data)                                                  (0x00100000&((data)<<20))
#define GDMA_DMA_SWAP_osd5_8b_src(data)                                              ((0x00100000&(data))>>20)
#define GDMA_DMA_SWAP_get_osd5_8b(data)                                              ((0x00100000&(data))>>20)
#define GDMA_DMA_SWAP_osd4_1b_shift                                                  (19)
#define GDMA_DMA_SWAP_osd4_1b_mask                                                   (0x00080000)
#define GDMA_DMA_SWAP_osd4_1b(data)                                                  (0x00080000&((data)<<19))
#define GDMA_DMA_SWAP_osd4_1b_src(data)                                              ((0x00080000&(data))>>19)
#define GDMA_DMA_SWAP_get_osd4_1b(data)                                              ((0x00080000&(data))>>19)
#define GDMA_DMA_SWAP_osd4_2b_shift                                                  (18)
#define GDMA_DMA_SWAP_osd4_2b_mask                                                   (0x00040000)
#define GDMA_DMA_SWAP_osd4_2b(data)                                                  (0x00040000&((data)<<18))
#define GDMA_DMA_SWAP_osd4_2b_src(data)                                              ((0x00040000&(data))>>18)
#define GDMA_DMA_SWAP_get_osd4_2b(data)                                              ((0x00040000&(data))>>18)
#define GDMA_DMA_SWAP_osd4_4b_shift                                                  (17)
#define GDMA_DMA_SWAP_osd4_4b_mask                                                   (0x00020000)
#define GDMA_DMA_SWAP_osd4_4b(data)                                                  (0x00020000&((data)<<17))
#define GDMA_DMA_SWAP_osd4_4b_src(data)                                              ((0x00020000&(data))>>17)
#define GDMA_DMA_SWAP_get_osd4_4b(data)                                              ((0x00020000&(data))>>17)
#define GDMA_DMA_SWAP_osd4_8b_shift                                                  (16)
#define GDMA_DMA_SWAP_osd4_8b_mask                                                   (0x00010000)
#define GDMA_DMA_SWAP_osd4_8b(data)                                                  (0x00010000&((data)<<16))
#define GDMA_DMA_SWAP_osd4_8b_src(data)                                              ((0x00010000&(data))>>16)
#define GDMA_DMA_SWAP_get_osd4_8b(data)                                              ((0x00010000&(data))>>16)
#define GDMA_DMA_SWAP_osd3_1b_shift                                                  (15)
#define GDMA_DMA_SWAP_osd3_1b_mask                                                   (0x00008000)
#define GDMA_DMA_SWAP_osd3_1b(data)                                                  (0x00008000&((data)<<15))
#define GDMA_DMA_SWAP_osd3_1b_src(data)                                              ((0x00008000&(data))>>15)
#define GDMA_DMA_SWAP_get_osd3_1b(data)                                              ((0x00008000&(data))>>15)
#define GDMA_DMA_SWAP_osd3_2b_shift                                                  (14)
#define GDMA_DMA_SWAP_osd3_2b_mask                                                   (0x00004000)
#define GDMA_DMA_SWAP_osd3_2b(data)                                                  (0x00004000&((data)<<14))
#define GDMA_DMA_SWAP_osd3_2b_src(data)                                              ((0x00004000&(data))>>14)
#define GDMA_DMA_SWAP_get_osd3_2b(data)                                              ((0x00004000&(data))>>14)
#define GDMA_DMA_SWAP_osd3_4b_shift                                                  (13)
#define GDMA_DMA_SWAP_osd3_4b_mask                                                   (0x00002000)
#define GDMA_DMA_SWAP_osd3_4b(data)                                                  (0x00002000&((data)<<13))
#define GDMA_DMA_SWAP_osd3_4b_src(data)                                              ((0x00002000&(data))>>13)
#define GDMA_DMA_SWAP_get_osd3_4b(data)                                              ((0x00002000&(data))>>13)
#define GDMA_DMA_SWAP_osd3_8b_shift                                                  (12)
#define GDMA_DMA_SWAP_osd3_8b_mask                                                   (0x00001000)
#define GDMA_DMA_SWAP_osd3_8b(data)                                                  (0x00001000&((data)<<12))
#define GDMA_DMA_SWAP_osd3_8b_src(data)                                              ((0x00001000&(data))>>12)
#define GDMA_DMA_SWAP_get_osd3_8b(data)                                              ((0x00001000&(data))>>12)
#define GDMA_DMA_SWAP_osd2_1b_shift                                                  (11)
#define GDMA_DMA_SWAP_osd2_1b_mask                                                   (0x00000800)
#define GDMA_DMA_SWAP_osd2_1b(data)                                                  (0x00000800&((data)<<11))
#define GDMA_DMA_SWAP_osd2_1b_src(data)                                              ((0x00000800&(data))>>11)
#define GDMA_DMA_SWAP_get_osd2_1b(data)                                              ((0x00000800&(data))>>11)
#define GDMA_DMA_SWAP_osd2_2b_shift                                                  (10)
#define GDMA_DMA_SWAP_osd2_2b_mask                                                   (0x00000400)
#define GDMA_DMA_SWAP_osd2_2b(data)                                                  (0x00000400&((data)<<10))
#define GDMA_DMA_SWAP_osd2_2b_src(data)                                              ((0x00000400&(data))>>10)
#define GDMA_DMA_SWAP_get_osd2_2b(data)                                              ((0x00000400&(data))>>10)
#define GDMA_DMA_SWAP_osd2_4b_shift                                                  (9)
#define GDMA_DMA_SWAP_osd2_4b_mask                                                   (0x00000200)
#define GDMA_DMA_SWAP_osd2_4b(data)                                                  (0x00000200&((data)<<9))
#define GDMA_DMA_SWAP_osd2_4b_src(data)                                              ((0x00000200&(data))>>9)
#define GDMA_DMA_SWAP_get_osd2_4b(data)                                              ((0x00000200&(data))>>9)
#define GDMA_DMA_SWAP_osd2_8b_shift                                                  (8)
#define GDMA_DMA_SWAP_osd2_8b_mask                                                   (0x00000100)
#define GDMA_DMA_SWAP_osd2_8b(data)                                                  (0x00000100&((data)<<8))
#define GDMA_DMA_SWAP_osd2_8b_src(data)                                              ((0x00000100&(data))>>8)
#define GDMA_DMA_SWAP_get_osd2_8b(data)                                              ((0x00000100&(data))>>8)
#define GDMA_DMA_SWAP_osd1_1b_shift                                                  (7)
#define GDMA_DMA_SWAP_osd1_1b_mask                                                   (0x00000080)
#define GDMA_DMA_SWAP_osd1_1b(data)                                                  (0x00000080&((data)<<7))
#define GDMA_DMA_SWAP_osd1_1b_src(data)                                              ((0x00000080&(data))>>7)
#define GDMA_DMA_SWAP_get_osd1_1b(data)                                              ((0x00000080&(data))>>7)
#define GDMA_DMA_SWAP_osd1_2b_shift                                                  (6)
#define GDMA_DMA_SWAP_osd1_2b_mask                                                   (0x00000040)
#define GDMA_DMA_SWAP_osd1_2b(data)                                                  (0x00000040&((data)<<6))
#define GDMA_DMA_SWAP_osd1_2b_src(data)                                              ((0x00000040&(data))>>6)
#define GDMA_DMA_SWAP_get_osd1_2b(data)                                              ((0x00000040&(data))>>6)
#define GDMA_DMA_SWAP_osd1_4b_shift                                                  (5)
#define GDMA_DMA_SWAP_osd1_4b_mask                                                   (0x00000020)
#define GDMA_DMA_SWAP_osd1_4b(data)                                                  (0x00000020&((data)<<5))
#define GDMA_DMA_SWAP_osd1_4b_src(data)                                              ((0x00000020&(data))>>5)
#define GDMA_DMA_SWAP_get_osd1_4b(data)                                              ((0x00000020&(data))>>5)
#define GDMA_DMA_SWAP_osd1_8b_shift                                                  (4)
#define GDMA_DMA_SWAP_osd1_8b_mask                                                   (0x00000010)
#define GDMA_DMA_SWAP_osd1_8b(data)                                                  (0x00000010&((data)<<4))
#define GDMA_DMA_SWAP_osd1_8b_src(data)                                              ((0x00000010&(data))>>4)
#define GDMA_DMA_SWAP_get_osd1_8b(data)                                              ((0x00000010&(data))>>4)
#define GDMA_DMA_SWAP_wdma_1b_shift                                                  (3)
#define GDMA_DMA_SWAP_wdma_1b_mask                                                   (0x00000008)
#define GDMA_DMA_SWAP_wdma_1b(data)                                                  (0x00000008&((data)<<3))
#define GDMA_DMA_SWAP_wdma_1b_src(data)                                              ((0x00000008&(data))>>3)
#define GDMA_DMA_SWAP_get_wdma_1b(data)                                              ((0x00000008&(data))>>3)
#define GDMA_DMA_SWAP_wdma_2b_shift                                                  (2)
#define GDMA_DMA_SWAP_wdma_2b_mask                                                   (0x00000004)
#define GDMA_DMA_SWAP_wdma_2b(data)                                                  (0x00000004&((data)<<2))
#define GDMA_DMA_SWAP_wdma_2b_src(data)                                              ((0x00000004&(data))>>2)
#define GDMA_DMA_SWAP_get_wdma_2b(data)                                              ((0x00000004&(data))>>2)
#define GDMA_DMA_SWAP_wdma_4b_shift                                                  (1)
#define GDMA_DMA_SWAP_wdma_4b_mask                                                   (0x00000002)
#define GDMA_DMA_SWAP_wdma_4b(data)                                                  (0x00000002&((data)<<1))
#define GDMA_DMA_SWAP_wdma_4b_src(data)                                              ((0x00000002&(data))>>1)
#define GDMA_DMA_SWAP_get_wdma_4b(data)                                              ((0x00000002&(data))>>1)
#define GDMA_DMA_SWAP_wdma_8b_shift                                                  (0)
#define GDMA_DMA_SWAP_wdma_8b_mask                                                   (0x00000001)
#define GDMA_DMA_SWAP_wdma_8b(data)                                                  (0x00000001&((data)<<0))
#define GDMA_DMA_SWAP_wdma_8b_src(data)                                              ((0x00000001&(data))>>0)
#define GDMA_DMA_SWAP_get_wdma_8b(data)                                              ((0x00000001&(data))>>0)


#define GDMA_DMA_OSD1_WI                                                             0x1802f930
#define GDMA_DMA_OSD1_WI_reg_addr                                                    "0xB802F930"
#define GDMA_DMA_OSD1_WI_reg                                                         0xB802F930
#define set_GDMA_DMA_OSD1_WI_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD1_WI_reg)=data)
#define get_GDMA_DMA_OSD1_WI_reg   (*((volatile unsigned int*) GDMA_DMA_OSD1_WI_reg))
#define GDMA_DMA_OSD1_WI_inst_adr                                                    "0x004C"
#define GDMA_DMA_OSD1_WI_inst                                                        0x004C
#define GDMA_DMA_OSD1_WI_depth_shift                                                 (12)
#define GDMA_DMA_OSD1_WI_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD1_WI_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD1_WI_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD1_WI_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD1_WI_sa_shift                                                    (0)
#define GDMA_DMA_OSD1_WI_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD1_WI_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD1_WI_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD1_WI_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD1_D0                                                             0x1802f934
#define GDMA_DMA_OSD1_D0_reg_addr                                                    "0xB802F934"
#define GDMA_DMA_OSD1_D0_reg                                                         0xB802F934
#define set_GDMA_DMA_OSD1_D0_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD1_D0_reg)=data)
#define get_GDMA_DMA_OSD1_D0_reg   (*((volatile unsigned int*) GDMA_DMA_OSD1_D0_reg))
#define GDMA_DMA_OSD1_D0_inst_adr                                                    "0x004D"
#define GDMA_DMA_OSD1_D0_inst                                                        0x004D
#define GDMA_DMA_OSD1_D0_depth_shift                                                 (12)
#define GDMA_DMA_OSD1_D0_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD1_D0_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD1_D0_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD1_D0_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD1_D0_sa_shift                                                    (0)
#define GDMA_DMA_OSD1_D0_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD1_D0_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD1_D0_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD1_D0_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD1_D1                                                             0x1802f938
#define GDMA_DMA_OSD1_D1_reg_addr                                                    "0xB802F938"
#define GDMA_DMA_OSD1_D1_reg                                                         0xB802F938
#define set_GDMA_DMA_OSD1_D1_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD1_D1_reg)=data)
#define get_GDMA_DMA_OSD1_D1_reg   (*((volatile unsigned int*) GDMA_DMA_OSD1_D1_reg))
#define GDMA_DMA_OSD1_D1_inst_adr                                                    "0x004E"
#define GDMA_DMA_OSD1_D1_inst                                                        0x004E
#define GDMA_DMA_OSD1_D1_depth_shift                                                 (12)
#define GDMA_DMA_OSD1_D1_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD1_D1_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD1_D1_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD1_D1_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD1_D1_sa_shift                                                    (0)
#define GDMA_DMA_OSD1_D1_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD1_D1_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD1_D1_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD1_D1_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD2_WI                                                             0x1802f93c
#define GDMA_DMA_OSD2_WI_reg_addr                                                    "0xB802F93C"
#define GDMA_DMA_OSD2_WI_reg                                                         0xB802F93C
#define set_GDMA_DMA_OSD2_WI_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD2_WI_reg)=data)
#define get_GDMA_DMA_OSD2_WI_reg   (*((volatile unsigned int*) GDMA_DMA_OSD2_WI_reg))
#define GDMA_DMA_OSD2_WI_inst_adr                                                    "0x004F"
#define GDMA_DMA_OSD2_WI_inst                                                        0x004F
#define GDMA_DMA_OSD2_WI_depth_shift                                                 (12)
#define GDMA_DMA_OSD2_WI_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD2_WI_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD2_WI_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD2_WI_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD2_WI_sa_shift                                                    (0)
#define GDMA_DMA_OSD2_WI_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD2_WI_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD2_WI_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD2_WI_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD2_D0                                                             0x1802f940
#define GDMA_DMA_OSD2_D0_reg_addr                                                    "0xB802F940"
#define GDMA_DMA_OSD2_D0_reg                                                         0xB802F940
#define set_GDMA_DMA_OSD2_D0_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD2_D0_reg)=data)
#define get_GDMA_DMA_OSD2_D0_reg   (*((volatile unsigned int*) GDMA_DMA_OSD2_D0_reg))
#define GDMA_DMA_OSD2_D0_inst_adr                                                    "0x0050"
#define GDMA_DMA_OSD2_D0_inst                                                        0x0050
#define GDMA_DMA_OSD2_D0_depth_shift                                                 (12)
#define GDMA_DMA_OSD2_D0_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD2_D0_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD2_D0_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD2_D0_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD2_D0_sa_shift                                                    (0)
#define GDMA_DMA_OSD2_D0_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD2_D0_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD2_D0_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD2_D0_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD2_D1                                                             0x1802f944
#define GDMA_DMA_OSD2_D1_reg_addr                                                    "0xB802F944"
#define GDMA_DMA_OSD2_D1_reg                                                         0xB802F944
#define set_GDMA_DMA_OSD2_D1_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD2_D1_reg)=data)
#define get_GDMA_DMA_OSD2_D1_reg   (*((volatile unsigned int*) GDMA_DMA_OSD2_D1_reg))
#define GDMA_DMA_OSD2_D1_inst_adr                                                    "0x0051"
#define GDMA_DMA_OSD2_D1_inst                                                        0x0051
#define GDMA_DMA_OSD2_D1_depth_shift                                                 (12)
#define GDMA_DMA_OSD2_D1_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD2_D1_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD2_D1_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD2_D1_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD2_D1_sa_shift                                                    (0)
#define GDMA_DMA_OSD2_D1_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD2_D1_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD2_D1_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD2_D1_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD3_WI                                                             0x1802f948
#define GDMA_DMA_OSD3_WI_reg_addr                                                    "0xB802F948"
#define GDMA_DMA_OSD3_WI_reg                                                         0xB802F948
#define set_GDMA_DMA_OSD3_WI_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD3_WI_reg)=data)
#define get_GDMA_DMA_OSD3_WI_reg   (*((volatile unsigned int*) GDMA_DMA_OSD3_WI_reg))
#define GDMA_DMA_OSD3_WI_inst_adr                                                    "0x0052"
#define GDMA_DMA_OSD3_WI_inst                                                        0x0052
#define GDMA_DMA_OSD3_WI_depth_shift                                                 (12)
#define GDMA_DMA_OSD3_WI_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD3_WI_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD3_WI_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD3_WI_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD3_WI_sa_shift                                                    (0)
#define GDMA_DMA_OSD3_WI_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD3_WI_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD3_WI_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD3_WI_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD3_D0                                                             0x1802f94c
#define GDMA_DMA_OSD3_D0_reg_addr                                                    "0xB802F94C"
#define GDMA_DMA_OSD3_D0_reg                                                         0xB802F94C
#define set_GDMA_DMA_OSD3_D0_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD3_D0_reg)=data)
#define get_GDMA_DMA_OSD3_D0_reg   (*((volatile unsigned int*) GDMA_DMA_OSD3_D0_reg))
#define GDMA_DMA_OSD3_D0_inst_adr                                                    "0x0053"
#define GDMA_DMA_OSD3_D0_inst                                                        0x0053
#define GDMA_DMA_OSD3_D0_depth_shift                                                 (12)
#define GDMA_DMA_OSD3_D0_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD3_D0_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD3_D0_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD3_D0_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD3_D0_sa_shift                                                    (0)
#define GDMA_DMA_OSD3_D0_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD3_D0_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD3_D0_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD3_D0_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD3_D1                                                             0x1802f950
#define GDMA_DMA_OSD3_D1_reg_addr                                                    "0xB802F950"
#define GDMA_DMA_OSD3_D1_reg                                                         0xB802F950
#define set_GDMA_DMA_OSD3_D1_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD3_D1_reg)=data)
#define get_GDMA_DMA_OSD3_D1_reg   (*((volatile unsigned int*) GDMA_DMA_OSD3_D1_reg))
#define GDMA_DMA_OSD3_D1_inst_adr                                                    "0x0054"
#define GDMA_DMA_OSD3_D1_inst                                                        0x0054
#define GDMA_DMA_OSD3_D1_depth_shift                                                 (12)
#define GDMA_DMA_OSD3_D1_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD3_D1_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD3_D1_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD3_D1_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD3_D1_sa_shift                                                    (0)
#define GDMA_DMA_OSD3_D1_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD3_D1_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD3_D1_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD3_D1_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD4_WI                                                             0x1802f954
#define GDMA_DMA_OSD4_WI_reg_addr                                                    "0xB802F954"
#define GDMA_DMA_OSD4_WI_reg                                                         0xB802F954
#define set_GDMA_DMA_OSD4_WI_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD4_WI_reg)=data)
#define get_GDMA_DMA_OSD4_WI_reg   (*((volatile unsigned int*) GDMA_DMA_OSD4_WI_reg))
#define GDMA_DMA_OSD4_WI_inst_adr                                                    "0x0055"
#define GDMA_DMA_OSD4_WI_inst                                                        0x0055
#define GDMA_DMA_OSD4_WI_depth_shift                                                 (12)
#define GDMA_DMA_OSD4_WI_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD4_WI_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD4_WI_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD4_WI_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD4_WI_sa_shift                                                    (0)
#define GDMA_DMA_OSD4_WI_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD4_WI_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD4_WI_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD4_WI_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD4_D0                                                             0x1802f958
#define GDMA_DMA_OSD4_D0_reg_addr                                                    "0xB802F958"
#define GDMA_DMA_OSD4_D0_reg                                                         0xB802F958
#define set_GDMA_DMA_OSD4_D0_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD4_D0_reg)=data)
#define get_GDMA_DMA_OSD4_D0_reg   (*((volatile unsigned int*) GDMA_DMA_OSD4_D0_reg))
#define GDMA_DMA_OSD4_D0_inst_adr                                                    "0x0056"
#define GDMA_DMA_OSD4_D0_inst                                                        0x0056
#define GDMA_DMA_OSD4_D0_depth_shift                                                 (12)
#define GDMA_DMA_OSD4_D0_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD4_D0_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD4_D0_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD4_D0_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD4_D0_sa_shift                                                    (0)
#define GDMA_DMA_OSD4_D0_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD4_D0_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD4_D0_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD4_D0_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD4_D1                                                             0x1802f95c
#define GDMA_DMA_OSD4_D1_reg_addr                                                    "0xB802F95C"
#define GDMA_DMA_OSD4_D1_reg                                                         0xB802F95C
#define set_GDMA_DMA_OSD4_D1_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD4_D1_reg)=data)
#define get_GDMA_DMA_OSD4_D1_reg   (*((volatile unsigned int*) GDMA_DMA_OSD4_D1_reg))
#define GDMA_DMA_OSD4_D1_inst_adr                                                    "0x0057"
#define GDMA_DMA_OSD4_D1_inst                                                        0x0057
#define GDMA_DMA_OSD4_D1_depth_shift                                                 (12)
#define GDMA_DMA_OSD4_D1_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD4_D1_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD4_D1_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD4_D1_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD4_D1_sa_shift                                                    (0)
#define GDMA_DMA_OSD4_D1_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD4_D1_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD4_D1_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD4_D1_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD5_WI                                                             0x1802f960
#define GDMA_DMA_OSD5_WI_reg_addr                                                    "0xB802F960"
#define GDMA_DMA_OSD5_WI_reg                                                         0xB802F960
#define set_GDMA_DMA_OSD5_WI_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD5_WI_reg)=data)
#define get_GDMA_DMA_OSD5_WI_reg   (*((volatile unsigned int*) GDMA_DMA_OSD5_WI_reg))
#define GDMA_DMA_OSD5_WI_inst_adr                                                    "0x0058"
#define GDMA_DMA_OSD5_WI_inst                                                        0x0058
#define GDMA_DMA_OSD5_WI_depth_shift                                                 (12)
#define GDMA_DMA_OSD5_WI_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD5_WI_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD5_WI_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD5_WI_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD5_WI_sa_shift                                                    (0)
#define GDMA_DMA_OSD5_WI_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD5_WI_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD5_WI_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD5_WI_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD5_D0                                                             0x1802f964
#define GDMA_DMA_OSD5_D0_reg_addr                                                    "0xB802F964"
#define GDMA_DMA_OSD5_D0_reg                                                         0xB802F964
#define set_GDMA_DMA_OSD5_D0_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD5_D0_reg)=data)
#define get_GDMA_DMA_OSD5_D0_reg   (*((volatile unsigned int*) GDMA_DMA_OSD5_D0_reg))
#define GDMA_DMA_OSD5_D0_inst_adr                                                    "0x0059"
#define GDMA_DMA_OSD5_D0_inst                                                        0x0059
#define GDMA_DMA_OSD5_D0_depth_shift                                                 (12)
#define GDMA_DMA_OSD5_D0_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD5_D0_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD5_D0_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD5_D0_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD5_D0_sa_shift                                                    (0)
#define GDMA_DMA_OSD5_D0_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD5_D0_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD5_D0_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD5_D0_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_DMA_OSD5_D1                                                             0x1802f968
#define GDMA_DMA_OSD5_D1_reg_addr                                                    "0xB802F968"
#define GDMA_DMA_OSD5_D1_reg                                                         0xB802F968
#define set_GDMA_DMA_OSD5_D1_reg(data)   (*((volatile unsigned int*) GDMA_DMA_OSD5_D1_reg)=data)
#define get_GDMA_DMA_OSD5_D1_reg   (*((volatile unsigned int*) GDMA_DMA_OSD5_D1_reg))
#define GDMA_DMA_OSD5_D1_inst_adr                                                    "0x005A"
#define GDMA_DMA_OSD5_D1_inst                                                        0x005A
#define GDMA_DMA_OSD5_D1_depth_shift                                                 (12)
#define GDMA_DMA_OSD5_D1_depth_mask                                                  (0x00FFF000)
#define GDMA_DMA_OSD5_D1_depth(data)                                                 (0x00FFF000&((data)<<12))
#define GDMA_DMA_OSD5_D1_depth_src(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD5_D1_get_depth(data)                                             ((0x00FFF000&(data))>>12)
#define GDMA_DMA_OSD5_D1_sa_shift                                                    (0)
#define GDMA_DMA_OSD5_D1_sa_mask                                                     (0x00000FFF)
#define GDMA_DMA_OSD5_D1_sa(data)                                                    (0x00000FFF&((data)<<0))
#define GDMA_DMA_OSD5_D1_sa_src(data)                                                ((0x00000FFF&(data))>>0)
#define GDMA_DMA_OSD5_D1_get_sa(data)                                                ((0x00000FFF&(data))>>0)


#define GDMA_WDMA_ADR_SEG0                                                           0x1802f970
#define GDMA_WDMA_ADR_SEG0_reg_addr                                                  "0xB802F970"
#define GDMA_WDMA_ADR_SEG0_reg                                                       0xB802F970
#define set_GDMA_WDMA_ADR_SEG0_reg(data)   (*((volatile unsigned int*) GDMA_WDMA_ADR_SEG0_reg)=data)
#define get_GDMA_WDMA_ADR_SEG0_reg   (*((volatile unsigned int*) GDMA_WDMA_ADR_SEG0_reg))
#define GDMA_WDMA_ADR_SEG0_inst_adr                                                  "0x005C"
#define GDMA_WDMA_ADR_SEG0_inst                                                      0x005C
#define GDMA_WDMA_ADR_SEG0_addr_shift                                                (0)
#define GDMA_WDMA_ADR_SEG0_addr_mask                                                 (0xFFFFFFFF)
#define GDMA_WDMA_ADR_SEG0_addr(data)                                                (0xFFFFFFFF&((data)<<0))
#define GDMA_WDMA_ADR_SEG0_addr_src(data)                                            ((0xFFFFFFFF&(data))>>0)
#define GDMA_WDMA_ADR_SEG0_get_addr(data)                                            ((0xFFFFFFFF&(data))>>0)


#define GDMA_WDMA_ADR_SEG1                                                           0x1802f974
#define GDMA_WDMA_ADR_SEG1_reg_addr                                                  "0xB802F974"
#define GDMA_WDMA_ADR_SEG1_reg                                                       0xB802F974
#define set_GDMA_WDMA_ADR_SEG1_reg(data)   (*((volatile unsigned int*) GDMA_WDMA_ADR_SEG1_reg)=data)
#define get_GDMA_WDMA_ADR_SEG1_reg   (*((volatile unsigned int*) GDMA_WDMA_ADR_SEG1_reg))
#define GDMA_WDMA_ADR_SEG1_inst_adr                                                  "0x005D"
#define GDMA_WDMA_ADR_SEG1_inst                                                      0x005D
#define GDMA_WDMA_ADR_SEG1_addr_shift                                                (0)
#define GDMA_WDMA_ADR_SEG1_addr_mask                                                 (0xFFFFFFFF)
#define GDMA_WDMA_ADR_SEG1_addr(data)                                                (0xFFFFFFFF&((data)<<0))
#define GDMA_WDMA_ADR_SEG1_addr_src(data)                                            ((0xFFFFFFFF&(data))>>0)
#define GDMA_WDMA_ADR_SEG1_get_addr(data)                                            ((0xFFFFFFFF&(data))>>0)


#define GDMA_WDMA_SEG0                                                               0x1802f978
#define GDMA_WDMA_SEG0_reg_addr                                                      "0xB802F978"
#define GDMA_WDMA_SEG0_reg                                                           0xB802F978
#define set_GDMA_WDMA_SEG0_reg(data)   (*((volatile unsigned int*) GDMA_WDMA_SEG0_reg)=data)
#define get_GDMA_WDMA_SEG0_reg   (*((volatile unsigned int*) GDMA_WDMA_SEG0_reg))
#define GDMA_WDMA_SEG0_inst_adr                                                      "0x005E"
#define GDMA_WDMA_SEG0_inst                                                          0x005E
#define GDMA_WDMA_SEG0_size_shift                                                    (0)
#define GDMA_WDMA_SEG0_size_mask                                                     (0xFFFFFFFF)
#define GDMA_WDMA_SEG0_size(data)                                                    (0xFFFFFFFF&((data)<<0))
#define GDMA_WDMA_SEG0_size_src(data)                                                ((0xFFFFFFFF&(data))>>0)
#define GDMA_WDMA_SEG0_get_size(data)                                                ((0xFFFFFFFF&(data))>>0)


#define GDMA_WDMA_SEG1                                                               0x1802f97C
#define GDMA_WDMA_SEG1_reg_addr                                                      "0xB802F97C"
#define GDMA_WDMA_SEG1_reg                                                           0xB802F97C
#define set_GDMA_WDMA_SEG1_reg(data)   (*((volatile unsigned int*) GDMA_WDMA_SEG1_reg)=data)
#define get_GDMA_WDMA_SEG1_reg   (*((volatile unsigned int*) GDMA_WDMA_SEG1_reg))
#define GDMA_WDMA_SEG1_inst_adr                                                      "0x005F"
#define GDMA_WDMA_SEG1_inst                                                          0x005F
#define GDMA_WDMA_SEG1_size_shift                                                    (0)
#define GDMA_WDMA_SEG1_size_mask                                                     (0xFFFFFFFF)
#define GDMA_WDMA_SEG1_size(data)                                                    (0xFFFFFFFF&((data)<<0))
#define GDMA_WDMA_SEG1_size_src(data)                                                ((0xFFFFFFFF&(data))>>0)
#define GDMA_WDMA_SEG1_get_size(data)                                                ((0xFFFFFFFF&(data))>>0)


#define GDMA_WDMA_CRC                                                                0x1802f980
#define GDMA_WDMA_CRC_reg_addr                                                       "0xB802F980"
#define GDMA_WDMA_CRC_reg                                                            0xB802F980
#define set_GDMA_WDMA_CRC_reg(data)   (*((volatile unsigned int*) GDMA_WDMA_CRC_reg)=data)
#define get_GDMA_WDMA_CRC_reg   (*((volatile unsigned int*) GDMA_WDMA_CRC_reg))
#define GDMA_WDMA_CRC_inst_adr                                                       "0x0060"
#define GDMA_WDMA_CRC_inst                                                           0x0060
#define GDMA_WDMA_CRC_conti_shift                                                    (1)
#define GDMA_WDMA_CRC_conti_mask                                                     (0x00000002)
#define GDMA_WDMA_CRC_conti(data)                                                    (0x00000002&((data)<<1))
#define GDMA_WDMA_CRC_conti_src(data)                                                ((0x00000002&(data))>>1)
#define GDMA_WDMA_CRC_get_conti(data)                                                ((0x00000002&(data))>>1)
#define GDMA_WDMA_CRC_start_shift                                                    (0)
#define GDMA_WDMA_CRC_start_mask                                                     (0x00000001)
#define GDMA_WDMA_CRC_start(data)                                                    (0x00000001&((data)<<0))
#define GDMA_WDMA_CRC_start_src(data)                                                ((0x00000001&(data))>>0)
#define GDMA_WDMA_CRC_get_start(data)                                                ((0x00000001&(data))>>0)


#define GDMA_WDMA_SEG0_CRC                                                           0x1802f984
#define GDMA_WDMA_SEG0_CRC_reg_addr                                                  "0xB802F984"
#define GDMA_WDMA_SEG0_CRC_reg                                                       0xB802F984
#define set_GDMA_WDMA_SEG0_CRC_reg(data)   (*((volatile unsigned int*) GDMA_WDMA_SEG0_CRC_reg)=data)
#define get_GDMA_WDMA_SEG0_CRC_reg   (*((volatile unsigned int*) GDMA_WDMA_SEG0_CRC_reg))
#define GDMA_WDMA_SEG0_CRC_inst_adr                                                  "0x0061"
#define GDMA_WDMA_SEG0_CRC_inst                                                      0x0061
#define GDMA_WDMA_SEG0_CRC_result_shift                                              (0)
#define GDMA_WDMA_SEG0_CRC_result_mask                                               (0xFFFFFFFF)
#define GDMA_WDMA_SEG0_CRC_result(data)                                              (0xFFFFFFFF&((data)<<0))
#define GDMA_WDMA_SEG0_CRC_result_src(data)                                          ((0xFFFFFFFF&(data))>>0)
#define GDMA_WDMA_SEG0_CRC_get_result(data)                                          ((0xFFFFFFFF&(data))>>0)


#define GDMA_M422_SWAP                                                               0x1802f988
#define GDMA_M422_SWAP_reg_addr                                                      "0xB802F988"
#define GDMA_M422_SWAP_reg                                                           0xB802F988
#define set_GDMA_M422_SWAP_reg(data)   (*((volatile unsigned int*) GDMA_M422_SWAP_reg)=data)
#define get_GDMA_M422_SWAP_reg   (*((volatile unsigned int*) GDMA_M422_SWAP_reg))
#define GDMA_M422_SWAP_inst_adr                                                      "0x0062"
#define GDMA_M422_SWAP_inst                                                          0x0062
#define GDMA_M422_SWAP_m422_cb_cr_swap_shift                                         (0)
#define GDMA_M422_SWAP_m422_cb_cr_swap_mask                                          (0x00000001)
#define GDMA_M422_SWAP_m422_cb_cr_swap(data)                                         (0x00000001&((data)<<0))
#define GDMA_M422_SWAP_m422_cb_cr_swap_src(data)                                     ((0x00000001&(data))>>0)
#define GDMA_M422_SWAP_get_m422_cb_cr_swap(data)                                     ((0x00000001&(data))>>0)


#define GDMA_WDMA_SEG1_CRC                                                           0x1802f98c
#define GDMA_WDMA_SEG1_CRC_reg_addr                                                  "0xB802F98C"
#define GDMA_WDMA_SEG1_CRC_reg                                                       0xB802F98C
#define set_GDMA_WDMA_SEG1_CRC_reg(data)   (*((volatile unsigned int*) GDMA_WDMA_SEG1_CRC_reg)=data)
#define get_GDMA_WDMA_SEG1_CRC_reg   (*((volatile unsigned int*) GDMA_WDMA_SEG1_CRC_reg))
#define GDMA_WDMA_SEG1_CRC_inst_adr                                                  "0x0063"
#define GDMA_WDMA_SEG1_CRC_inst                                                      0x0063
#define GDMA_WDMA_SEG1_CRC_result_shift                                              (0)
#define GDMA_WDMA_SEG1_CRC_result_mask                                               (0xFFFFFFFF)
#define GDMA_WDMA_SEG1_CRC_result(data)                                              (0xFFFFFFFF&((data)<<0))
#define GDMA_WDMA_SEG1_CRC_result_src(data)                                          ((0xFFFFFFFF&(data))>>0)
#define GDMA_WDMA_SEG1_CRC_get_result(data)                                          ((0xFFFFFFFF&(data))>>0)


#define GDMA_MID_BLEND                                                               0x1802fa00
#define GDMA_MID_BLEND_reg_addr                                                      "0xB802FA00"
#define GDMA_MID_BLEND_reg                                                           0xB802FA00
#define set_GDMA_MID_BLEND_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_reg)=data)
#define get_GDMA_MID_BLEND_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_reg))
#define GDMA_MID_BLEND_inst_adr                                                      "0x0080"
#define GDMA_MID_BLEND_inst                                                          0x0080
#define GDMA_MID_BLEND_mid_blend_en_shift                                            (31)
#define GDMA_MID_BLEND_mid_blend_en_mask                                             (0x80000000)
#define GDMA_MID_BLEND_mid_blend_en(data)                                            (0x80000000&((data)<<31))
#define GDMA_MID_BLEND_mid_blend_en_src(data)                                        ((0x80000000&(data))>>31)
#define GDMA_MID_BLEND_get_mid_blend_en(data)                                        ((0x80000000&(data))>>31)
#define GDMA_MID_BLEND_c3_plane_alpha_en_shift                                       (19)
#define GDMA_MID_BLEND_c3_plane_alpha_en_mask                                        (0x00080000)
#define GDMA_MID_BLEND_c3_plane_alpha_en(data)                                       (0x00080000&((data)<<19))
#define GDMA_MID_BLEND_c3_plane_alpha_en_src(data)                                   ((0x00080000&(data))>>19)
#define GDMA_MID_BLEND_get_c3_plane_alpha_en(data)                                   ((0x00080000&(data))>>19)
#define GDMA_MID_BLEND_c2_plane_alpha_en_shift                                       (18)
#define GDMA_MID_BLEND_c2_plane_alpha_en_mask                                        (0x00040000)
#define GDMA_MID_BLEND_c2_plane_alpha_en(data)                                       (0x00040000&((data)<<18))
#define GDMA_MID_BLEND_c2_plane_alpha_en_src(data)                                   ((0x00040000&(data))>>18)
#define GDMA_MID_BLEND_get_c2_plane_alpha_en(data)                                   ((0x00040000&(data))>>18)
#define GDMA_MID_BLEND_c1_plane_alpha_en_shift                                       (17)
#define GDMA_MID_BLEND_c1_plane_alpha_en_mask                                        (0x00020000)
#define GDMA_MID_BLEND_c1_plane_alpha_en(data)                                       (0x00020000&((data)<<17))
#define GDMA_MID_BLEND_c1_plane_alpha_en_src(data)                                   ((0x00020000&(data))>>17)
#define GDMA_MID_BLEND_get_c1_plane_alpha_en(data)                                   ((0x00020000&(data))>>17)
#define GDMA_MID_BLEND_c0_plane_alpha_en_shift                                       (16)
#define GDMA_MID_BLEND_c0_plane_alpha_en_mask                                        (0x00010000)
#define GDMA_MID_BLEND_c0_plane_alpha_en(data)                                       (0x00010000&((data)<<16))
#define GDMA_MID_BLEND_c0_plane_alpha_en_src(data)                                   ((0x00010000&(data))>>16)
#define GDMA_MID_BLEND_get_c0_plane_alpha_en(data)                                   ((0x00010000&(data))>>16)
#define GDMA_MID_BLEND_c3_sel_shift                                                  (12)
#define GDMA_MID_BLEND_c3_sel_mask                                                   (0x00007000)
#define GDMA_MID_BLEND_c3_sel(data)                                                  (0x00007000&((data)<<12))
#define GDMA_MID_BLEND_c3_sel_src(data)                                              ((0x00007000&(data))>>12)
#define GDMA_MID_BLEND_get_c3_sel(data)                                              ((0x00007000&(data))>>12)
#define GDMA_MID_BLEND_c2_sel_shift                                                  (8)
#define GDMA_MID_BLEND_c2_sel_mask                                                   (0x00000700)
#define GDMA_MID_BLEND_c2_sel(data)                                                  (0x00000700&((data)<<8))
#define GDMA_MID_BLEND_c2_sel_src(data)                                              ((0x00000700&(data))>>8)
#define GDMA_MID_BLEND_get_c2_sel(data)                                              ((0x00000700&(data))>>8)
#define GDMA_MID_BLEND_c1_sel_shift                                                  (4)
#define GDMA_MID_BLEND_c1_sel_mask                                                   (0x00000070)
#define GDMA_MID_BLEND_c1_sel(data)                                                  (0x00000070&((data)<<4))
#define GDMA_MID_BLEND_c1_sel_src(data)                                              ((0x00000070&(data))>>4)
#define GDMA_MID_BLEND_get_c1_sel(data)                                              ((0x00000070&(data))>>4)
#define GDMA_MID_BLEND_c0_sel_shift                                                  (0)
#define GDMA_MID_BLEND_c0_sel_mask                                                   (0x00000007)
#define GDMA_MID_BLEND_c0_sel(data)                                                  (0x00000007&((data)<<0))
#define GDMA_MID_BLEND_c0_sel_src(data)                                              ((0x00000007&(data))>>0)
#define GDMA_MID_BLEND_get_c0_sel(data)                                              ((0x00000007&(data))>>0)


#define GDMA_MID_BLEND_SIZE                                                          0x1802fa04
#define GDMA_MID_BLEND_SIZE_reg_addr                                                 "0xB802FA04"
#define GDMA_MID_BLEND_SIZE_reg                                                      0xB802FA04
#define set_GDMA_MID_BLEND_SIZE_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_SIZE_reg)=data)
#define get_GDMA_MID_BLEND_SIZE_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_SIZE_reg))
#define GDMA_MID_BLEND_SIZE_inst_adr                                                 "0x0081"
#define GDMA_MID_BLEND_SIZE_inst                                                     0x0081
#define GDMA_MID_BLEND_SIZE_w_shift                                                  (16)
#define GDMA_MID_BLEND_SIZE_w_mask                                                   (0x1FFF0000)
#define GDMA_MID_BLEND_SIZE_w(data)                                                  (0x1FFF0000&((data)<<16))
#define GDMA_MID_BLEND_SIZE_w_src(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_SIZE_get_w(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_SIZE_h_shift                                                  (0)
#define GDMA_MID_BLEND_SIZE_h_mask                                                   (0x00001FFF)
#define GDMA_MID_BLEND_SIZE_h(data)                                                  (0x00001FFF&((data)<<0))
#define GDMA_MID_BLEND_SIZE_h_src(data)                                              ((0x00001FFF&(data))>>0)
#define GDMA_MID_BLEND_SIZE_get_h(data)                                              ((0x00001FFF&(data))>>0)


#define GDMA_MID_BLEND_C0                                                            0x1802fa10
#define GDMA_MID_BLEND_C0_reg_addr                                                   "0xB802FA10"
#define GDMA_MID_BLEND_C0_reg                                                        0xB802FA10
#define set_GDMA_MID_BLEND_C0_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_C0_reg)=data)
#define get_GDMA_MID_BLEND_C0_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_C0_reg))
#define GDMA_MID_BLEND_C0_inst_adr                                                   "0x0084"
#define GDMA_MID_BLEND_C0_inst                                                       0x0084
#define GDMA_MID_BLEND_C0_plane_alpha_a_shift                                        (24)
#define GDMA_MID_BLEND_C0_plane_alpha_a_mask                                         (0xFF000000)
#define GDMA_MID_BLEND_C0_plane_alpha_a(data)                                        (0xFF000000&((data)<<24))
#define GDMA_MID_BLEND_C0_plane_alpha_a_src(data)                                    ((0xFF000000&(data))>>24)
#define GDMA_MID_BLEND_C0_get_plane_alpha_a(data)                                    ((0xFF000000&(data))>>24)
#define GDMA_MID_BLEND_C0_plane_alpha_r_shift                                        (16)
#define GDMA_MID_BLEND_C0_plane_alpha_r_mask                                         (0x00FF0000)
#define GDMA_MID_BLEND_C0_plane_alpha_r(data)                                        (0x00FF0000&((data)<<16))
#define GDMA_MID_BLEND_C0_plane_alpha_r_src(data)                                    ((0x00FF0000&(data))>>16)
#define GDMA_MID_BLEND_C0_get_plane_alpha_r(data)                                    ((0x00FF0000&(data))>>16)
#define GDMA_MID_BLEND_C0_plane_alpha_g_shift                                        (8)
#define GDMA_MID_BLEND_C0_plane_alpha_g_mask                                         (0x0000FF00)
#define GDMA_MID_BLEND_C0_plane_alpha_g(data)                                        (0x0000FF00&((data)<<8))
#define GDMA_MID_BLEND_C0_plane_alpha_g_src(data)                                    ((0x0000FF00&(data))>>8)
#define GDMA_MID_BLEND_C0_get_plane_alpha_g(data)                                    ((0x0000FF00&(data))>>8)
#define GDMA_MID_BLEND_C0_plane_alpha_b_shift                                        (0)
#define GDMA_MID_BLEND_C0_plane_alpha_b_mask                                         (0x000000FF)
#define GDMA_MID_BLEND_C0_plane_alpha_b(data)                                        (0x000000FF&((data)<<0))
#define GDMA_MID_BLEND_C0_plane_alpha_b_src(data)                                    ((0x000000FF&(data))>>0)
#define GDMA_MID_BLEND_C0_get_plane_alpha_b(data)                                    ((0x000000FF&(data))>>0)


#define GDMA_MID_BLEND_C1                                                            0x1802fa14
#define GDMA_MID_BLEND_C1_reg_addr                                                   "0xB802FA14"
#define GDMA_MID_BLEND_C1_reg                                                        0xB802FA14
#define set_GDMA_MID_BLEND_C1_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_C1_reg)=data)
#define get_GDMA_MID_BLEND_C1_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_C1_reg))
#define GDMA_MID_BLEND_C1_inst_adr                                                   "0x0085"
#define GDMA_MID_BLEND_C1_inst                                                       0x0085
#define GDMA_MID_BLEND_C1_plane_alpha_a_shift                                        (24)
#define GDMA_MID_BLEND_C1_plane_alpha_a_mask                                         (0xFF000000)
#define GDMA_MID_BLEND_C1_plane_alpha_a(data)                                        (0xFF000000&((data)<<24))
#define GDMA_MID_BLEND_C1_plane_alpha_a_src(data)                                    ((0xFF000000&(data))>>24)
#define GDMA_MID_BLEND_C1_get_plane_alpha_a(data)                                    ((0xFF000000&(data))>>24)
#define GDMA_MID_BLEND_C1_plane_alpha_r_shift                                        (16)
#define GDMA_MID_BLEND_C1_plane_alpha_r_mask                                         (0x00FF0000)
#define GDMA_MID_BLEND_C1_plane_alpha_r(data)                                        (0x00FF0000&((data)<<16))
#define GDMA_MID_BLEND_C1_plane_alpha_r_src(data)                                    ((0x00FF0000&(data))>>16)
#define GDMA_MID_BLEND_C1_get_plane_alpha_r(data)                                    ((0x00FF0000&(data))>>16)
#define GDMA_MID_BLEND_C1_plane_alpha_g_shift                                        (8)
#define GDMA_MID_BLEND_C1_plane_alpha_g_mask                                         (0x0000FF00)
#define GDMA_MID_BLEND_C1_plane_alpha_g(data)                                        (0x0000FF00&((data)<<8))
#define GDMA_MID_BLEND_C1_plane_alpha_g_src(data)                                    ((0x0000FF00&(data))>>8)
#define GDMA_MID_BLEND_C1_get_plane_alpha_g(data)                                    ((0x0000FF00&(data))>>8)
#define GDMA_MID_BLEND_C1_plane_alpha_b_shift                                        (0)
#define GDMA_MID_BLEND_C1_plane_alpha_b_mask                                         (0x000000FF)
#define GDMA_MID_BLEND_C1_plane_alpha_b(data)                                        (0x000000FF&((data)<<0))
#define GDMA_MID_BLEND_C1_plane_alpha_b_src(data)                                    ((0x000000FF&(data))>>0)
#define GDMA_MID_BLEND_C1_get_plane_alpha_b(data)                                    ((0x000000FF&(data))>>0)


#define GDMA_MID_BLEND_C2                                                            0x1802fa18
#define GDMA_MID_BLEND_C2_reg_addr                                                   "0xB802FA18"
#define GDMA_MID_BLEND_C2_reg                                                        0xB802FA18
#define set_GDMA_MID_BLEND_C2_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_C2_reg)=data)
#define get_GDMA_MID_BLEND_C2_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_C2_reg))
#define GDMA_MID_BLEND_C2_inst_adr                                                   "0x0086"
#define GDMA_MID_BLEND_C2_inst                                                       0x0086
#define GDMA_MID_BLEND_C2_plane_alpha_a_shift                                        (24)
#define GDMA_MID_BLEND_C2_plane_alpha_a_mask                                         (0xFF000000)
#define GDMA_MID_BLEND_C2_plane_alpha_a(data)                                        (0xFF000000&((data)<<24))
#define GDMA_MID_BLEND_C2_plane_alpha_a_src(data)                                    ((0xFF000000&(data))>>24)
#define GDMA_MID_BLEND_C2_get_plane_alpha_a(data)                                    ((0xFF000000&(data))>>24)
#define GDMA_MID_BLEND_C2_plane_alpha_r_shift                                        (16)
#define GDMA_MID_BLEND_C2_plane_alpha_r_mask                                         (0x00FF0000)
#define GDMA_MID_BLEND_C2_plane_alpha_r(data)                                        (0x00FF0000&((data)<<16))
#define GDMA_MID_BLEND_C2_plane_alpha_r_src(data)                                    ((0x00FF0000&(data))>>16)
#define GDMA_MID_BLEND_C2_get_plane_alpha_r(data)                                    ((0x00FF0000&(data))>>16)
#define GDMA_MID_BLEND_C2_plane_alpha_g_shift                                        (8)
#define GDMA_MID_BLEND_C2_plane_alpha_g_mask                                         (0x0000FF00)
#define GDMA_MID_BLEND_C2_plane_alpha_g(data)                                        (0x0000FF00&((data)<<8))
#define GDMA_MID_BLEND_C2_plane_alpha_g_src(data)                                    ((0x0000FF00&(data))>>8)
#define GDMA_MID_BLEND_C2_get_plane_alpha_g(data)                                    ((0x0000FF00&(data))>>8)
#define GDMA_MID_BLEND_C2_plane_alpha_b_shift                                        (0)
#define GDMA_MID_BLEND_C2_plane_alpha_b_mask                                         (0x000000FF)
#define GDMA_MID_BLEND_C2_plane_alpha_b(data)                                        (0x000000FF&((data)<<0))
#define GDMA_MID_BLEND_C2_plane_alpha_b_src(data)                                    ((0x000000FF&(data))>>0)
#define GDMA_MID_BLEND_C2_get_plane_alpha_b(data)                                    ((0x000000FF&(data))>>0)


#define GDMA_MID_BLEND_C3                                                            0x1802fa1c
#define GDMA_MID_BLEND_C3_reg_addr                                                   "0xB802FA1C"
#define GDMA_MID_BLEND_C3_reg                                                        0xB802FA1C
#define set_GDMA_MID_BLEND_C3_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_C3_reg)=data)
#define get_GDMA_MID_BLEND_C3_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_C3_reg))
#define GDMA_MID_BLEND_C3_inst_adr                                                   "0x0087"
#define GDMA_MID_BLEND_C3_inst                                                       0x0087
#define GDMA_MID_BLEND_C3_plane_alpha_a_shift                                        (24)
#define GDMA_MID_BLEND_C3_plane_alpha_a_mask                                         (0xFF000000)
#define GDMA_MID_BLEND_C3_plane_alpha_a(data)                                        (0xFF000000&((data)<<24))
#define GDMA_MID_BLEND_C3_plane_alpha_a_src(data)                                    ((0xFF000000&(data))>>24)
#define GDMA_MID_BLEND_C3_get_plane_alpha_a(data)                                    ((0xFF000000&(data))>>24)
#define GDMA_MID_BLEND_C3_plane_alpha_r_shift                                        (16)
#define GDMA_MID_BLEND_C3_plane_alpha_r_mask                                         (0x00FF0000)
#define GDMA_MID_BLEND_C3_plane_alpha_r(data)                                        (0x00FF0000&((data)<<16))
#define GDMA_MID_BLEND_C3_plane_alpha_r_src(data)                                    ((0x00FF0000&(data))>>16)
#define GDMA_MID_BLEND_C3_get_plane_alpha_r(data)                                    ((0x00FF0000&(data))>>16)
#define GDMA_MID_BLEND_C3_plane_alpha_g_shift                                        (8)
#define GDMA_MID_BLEND_C3_plane_alpha_g_mask                                         (0x0000FF00)
#define GDMA_MID_BLEND_C3_plane_alpha_g(data)                                        (0x0000FF00&((data)<<8))
#define GDMA_MID_BLEND_C3_plane_alpha_g_src(data)                                    ((0x0000FF00&(data))>>8)
#define GDMA_MID_BLEND_C3_get_plane_alpha_g(data)                                    ((0x0000FF00&(data))>>8)
#define GDMA_MID_BLEND_C3_plane_alpha_b_shift                                        (0)
#define GDMA_MID_BLEND_C3_plane_alpha_b_mask                                         (0x000000FF)
#define GDMA_MID_BLEND_C3_plane_alpha_b(data)                                        (0x000000FF&((data)<<0))
#define GDMA_MID_BLEND_C3_plane_alpha_b_src(data)                                    ((0x000000FF&(data))>>0)
#define GDMA_MID_BLEND_C3_get_plane_alpha_b(data)                                    ((0x000000FF&(data))>>0)


#define GDMA_MID_BLEND_OSD1                                                          0x1802fa20
#define GDMA_MID_BLEND_OSD1_reg_addr                                                 "0xB802FA20"
#define GDMA_MID_BLEND_OSD1_reg                                                      0xB802FA20
#define set_GDMA_MID_BLEND_OSD1_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_OSD1_reg)=data)
#define get_GDMA_MID_BLEND_OSD1_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_OSD1_reg))
#define GDMA_MID_BLEND_OSD1_inst_adr                                                 "0x0088"
#define GDMA_MID_BLEND_OSD1_inst                                                     0x0088
#define GDMA_MID_BLEND_OSD1_x_shift                                                  (16)
#define GDMA_MID_BLEND_OSD1_x_mask                                                   (0x1FFF0000)
#define GDMA_MID_BLEND_OSD1_x(data)                                                  (0x1FFF0000&((data)<<16))
#define GDMA_MID_BLEND_OSD1_x_src(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_OSD1_get_x(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_OSD1_y_shift                                                  (0)
#define GDMA_MID_BLEND_OSD1_y_mask                                                   (0x00001FFF)
#define GDMA_MID_BLEND_OSD1_y(data)                                                  (0x00001FFF&((data)<<0))
#define GDMA_MID_BLEND_OSD1_y_src(data)                                              ((0x00001FFF&(data))>>0)
#define GDMA_MID_BLEND_OSD1_get_y(data)                                              ((0x00001FFF&(data))>>0)


#define GDMA_MID_BLEND_OSD2                                                          0x1802fa24
#define GDMA_MID_BLEND_OSD2_reg_addr                                                 "0xB802FA24"
#define GDMA_MID_BLEND_OSD2_reg                                                      0xB802FA24
#define set_GDMA_MID_BLEND_OSD2_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_OSD2_reg)=data)
#define get_GDMA_MID_BLEND_OSD2_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_OSD2_reg))
#define GDMA_MID_BLEND_OSD2_inst_adr                                                 "0x0089"
#define GDMA_MID_BLEND_OSD2_inst                                                     0x0089
#define GDMA_MID_BLEND_OSD2_x_shift                                                  (16)
#define GDMA_MID_BLEND_OSD2_x_mask                                                   (0x1FFF0000)
#define GDMA_MID_BLEND_OSD2_x(data)                                                  (0x1FFF0000&((data)<<16))
#define GDMA_MID_BLEND_OSD2_x_src(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_OSD2_get_x(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_OSD2_y_shift                                                  (0)
#define GDMA_MID_BLEND_OSD2_y_mask                                                   (0x00001FFF)
#define GDMA_MID_BLEND_OSD2_y(data)                                                  (0x00001FFF&((data)<<0))
#define GDMA_MID_BLEND_OSD2_y_src(data)                                              ((0x00001FFF&(data))>>0)
#define GDMA_MID_BLEND_OSD2_get_y(data)                                              ((0x00001FFF&(data))>>0)


#define GDMA_MID_BLEND_OSD3                                                          0x1802fa28
#define GDMA_MID_BLEND_OSD3_reg_addr                                                 "0xB802FA28"
#define GDMA_MID_BLEND_OSD3_reg                                                      0xB802FA28
#define set_GDMA_MID_BLEND_OSD3_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_OSD3_reg)=data)
#define get_GDMA_MID_BLEND_OSD3_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_OSD3_reg))
#define GDMA_MID_BLEND_OSD3_inst_adr                                                 "0x008A"
#define GDMA_MID_BLEND_OSD3_inst                                                     0x008A
#define GDMA_MID_BLEND_OSD3_x_shift                                                  (16)
#define GDMA_MID_BLEND_OSD3_x_mask                                                   (0x1FFF0000)
#define GDMA_MID_BLEND_OSD3_x(data)                                                  (0x1FFF0000&((data)<<16))
#define GDMA_MID_BLEND_OSD3_x_src(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_OSD3_get_x(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_OSD3_y_shift                                                  (0)
#define GDMA_MID_BLEND_OSD3_y_mask                                                   (0x00001FFF)
#define GDMA_MID_BLEND_OSD3_y(data)                                                  (0x00001FFF&((data)<<0))
#define GDMA_MID_BLEND_OSD3_y_src(data)                                              ((0x00001FFF&(data))>>0)
#define GDMA_MID_BLEND_OSD3_get_y(data)                                              ((0x00001FFF&(data))>>0)


#define GDMA_MID_BLEND_OSD4                                                          0x1802fa2c
#define GDMA_MID_BLEND_OSD4_reg_addr                                                 "0xB802FA2C"
#define GDMA_MID_BLEND_OSD4_reg                                                      0xB802FA2C
#define set_GDMA_MID_BLEND_OSD4_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_OSD4_reg)=data)
#define get_GDMA_MID_BLEND_OSD4_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_OSD4_reg))
#define GDMA_MID_BLEND_OSD4_inst_adr                                                 "0x008B"
#define GDMA_MID_BLEND_OSD4_inst                                                     0x008B
#define GDMA_MID_BLEND_OSD4_x_shift                                                  (16)
#define GDMA_MID_BLEND_OSD4_x_mask                                                   (0x1FFF0000)
#define GDMA_MID_BLEND_OSD4_x(data)                                                  (0x1FFF0000&((data)<<16))
#define GDMA_MID_BLEND_OSD4_x_src(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_OSD4_get_x(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_OSD4_y_shift                                                  (0)
#define GDMA_MID_BLEND_OSD4_y_mask                                                   (0x00001FFF)
#define GDMA_MID_BLEND_OSD4_y(data)                                                  (0x00001FFF&((data)<<0))
#define GDMA_MID_BLEND_OSD4_y_src(data)                                              ((0x00001FFF&(data))>>0)
#define GDMA_MID_BLEND_OSD4_get_y(data)                                              ((0x00001FFF&(data))>>0)


#define GDMA_MID_BLEND_OSD5                                                          0x1802fa30
#define GDMA_MID_BLEND_OSD5_reg_addr                                                 "0xB802FA30"
#define GDMA_MID_BLEND_OSD5_reg                                                      0xB802FA30
#define set_GDMA_MID_BLEND_OSD5_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_OSD5_reg)=data)
#define get_GDMA_MID_BLEND_OSD5_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_OSD5_reg))
#define GDMA_MID_BLEND_OSD5_inst_adr                                                 "0x008C"
#define GDMA_MID_BLEND_OSD5_inst                                                     0x008C
#define GDMA_MID_BLEND_OSD5_x_shift                                                  (16)
#define GDMA_MID_BLEND_OSD5_x_mask                                                   (0x1FFF0000)
#define GDMA_MID_BLEND_OSD5_x(data)                                                  (0x1FFF0000&((data)<<16))
#define GDMA_MID_BLEND_OSD5_x_src(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_OSD5_get_x(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_MID_BLEND_OSD5_y_shift                                                  (0)
#define GDMA_MID_BLEND_OSD5_y_mask                                                   (0x00001FFF)
#define GDMA_MID_BLEND_OSD5_y(data)                                                  (0x00001FFF&((data)<<0))
#define GDMA_MID_BLEND_OSD5_y_src(data)                                              ((0x00001FFF&(data))>>0)
#define GDMA_MID_BLEND_OSD5_get_y(data)                                              ((0x00001FFF&(data))>>0)


#define GDMA_MID_BLEND_B1                                                            0x1802fa34
#define GDMA_MID_BLEND_B1_reg_addr                                                   "0xB802FA34"
#define GDMA_MID_BLEND_B1_reg                                                        0xB802FA34
#define set_GDMA_MID_BLEND_B1_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_B1_reg)=data)
#define get_GDMA_MID_BLEND_B1_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_B1_reg))
#define GDMA_MID_BLEND_B1_inst_adr                                                   "0x008D"
#define GDMA_MID_BLEND_B1_inst                                                       0x008D
#define GDMA_MID_BLEND_B1_k1_shift                                                   (24)
#define GDMA_MID_BLEND_B1_k1_mask                                                    (0x3F000000)
#define GDMA_MID_BLEND_B1_k1(data)                                                   (0x3F000000&((data)<<24))
#define GDMA_MID_BLEND_B1_k1_src(data)                                               ((0x3F000000&(data))>>24)
#define GDMA_MID_BLEND_B1_get_k1(data)                                               ((0x3F000000&(data))>>24)
#define GDMA_MID_BLEND_B1_k2_shift                                                   (16)
#define GDMA_MID_BLEND_B1_k2_mask                                                    (0x003F0000)
#define GDMA_MID_BLEND_B1_k2(data)                                                   (0x003F0000&((data)<<16))
#define GDMA_MID_BLEND_B1_k2_src(data)                                               ((0x003F0000&(data))>>16)
#define GDMA_MID_BLEND_B1_get_k2(data)                                               ((0x003F0000&(data))>>16)
#define GDMA_MID_BLEND_B1_k3_shift                                                   (8)
#define GDMA_MID_BLEND_B1_k3_mask                                                    (0x00003F00)
#define GDMA_MID_BLEND_B1_k3(data)                                                   (0x00003F00&((data)<<8))
#define GDMA_MID_BLEND_B1_k3_src(data)                                               ((0x00003F00&(data))>>8)
#define GDMA_MID_BLEND_B1_get_k3(data)                                               ((0x00003F00&(data))>>8)
#define GDMA_MID_BLEND_B1_k4_shift                                                   (0)
#define GDMA_MID_BLEND_B1_k4_mask                                                    (0x0000003F)
#define GDMA_MID_BLEND_B1_k4(data)                                                   (0x0000003F&((data)<<0))
#define GDMA_MID_BLEND_B1_k4_src(data)                                               ((0x0000003F&(data))>>0)
#define GDMA_MID_BLEND_B1_get_k4(data)                                               ((0x0000003F&(data))>>0)


#define GDMA_MID_BLEND_B2                                                            0x1802fa38
#define GDMA_MID_BLEND_B2_reg_addr                                                   "0xB802FA38"
#define GDMA_MID_BLEND_B2_reg                                                        0xB802FA38
#define set_GDMA_MID_BLEND_B2_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_B2_reg)=data)
#define get_GDMA_MID_BLEND_B2_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_B2_reg))
#define GDMA_MID_BLEND_B2_inst_adr                                                   "0x008E"
#define GDMA_MID_BLEND_B2_inst                                                       0x008E
#define GDMA_MID_BLEND_B2_k1_shift                                                   (24)
#define GDMA_MID_BLEND_B2_k1_mask                                                    (0x3F000000)
#define GDMA_MID_BLEND_B2_k1(data)                                                   (0x3F000000&((data)<<24))
#define GDMA_MID_BLEND_B2_k1_src(data)                                               ((0x3F000000&(data))>>24)
#define GDMA_MID_BLEND_B2_get_k1(data)                                               ((0x3F000000&(data))>>24)
#define GDMA_MID_BLEND_B2_k2_shift                                                   (16)
#define GDMA_MID_BLEND_B2_k2_mask                                                    (0x003F0000)
#define GDMA_MID_BLEND_B2_k2(data)                                                   (0x003F0000&((data)<<16))
#define GDMA_MID_BLEND_B2_k2_src(data)                                               ((0x003F0000&(data))>>16)
#define GDMA_MID_BLEND_B2_get_k2(data)                                               ((0x003F0000&(data))>>16)
#define GDMA_MID_BLEND_B2_k3_shift                                                   (8)
#define GDMA_MID_BLEND_B2_k3_mask                                                    (0x00003F00)
#define GDMA_MID_BLEND_B2_k3(data)                                                   (0x00003F00&((data)<<8))
#define GDMA_MID_BLEND_B2_k3_src(data)                                               ((0x00003F00&(data))>>8)
#define GDMA_MID_BLEND_B2_get_k3(data)                                               ((0x00003F00&(data))>>8)
#define GDMA_MID_BLEND_B2_k4_shift                                                   (0)
#define GDMA_MID_BLEND_B2_k4_mask                                                    (0x0000003F)
#define GDMA_MID_BLEND_B2_k4(data)                                                   (0x0000003F&((data)<<0))
#define GDMA_MID_BLEND_B2_k4_src(data)                                               ((0x0000003F&(data))>>0)
#define GDMA_MID_BLEND_B2_get_k4(data)                                               ((0x0000003F&(data))>>0)


#define GDMA_MID_BLEND_B3                                                            0x1802fa3c
#define GDMA_MID_BLEND_B3_reg_addr                                                   "0xB802FA3C"
#define GDMA_MID_BLEND_B3_reg                                                        0xB802FA3C
#define set_GDMA_MID_BLEND_B3_reg(data)   (*((volatile unsigned int*) GDMA_MID_BLEND_B3_reg)=data)
#define get_GDMA_MID_BLEND_B3_reg   (*((volatile unsigned int*) GDMA_MID_BLEND_B3_reg))
#define GDMA_MID_BLEND_B3_inst_adr                                                   "0x008F"
#define GDMA_MID_BLEND_B3_inst                                                       0x008F
#define GDMA_MID_BLEND_B3_k1_shift                                                   (24)
#define GDMA_MID_BLEND_B3_k1_mask                                                    (0x3F000000)
#define GDMA_MID_BLEND_B3_k1(data)                                                   (0x3F000000&((data)<<24))
#define GDMA_MID_BLEND_B3_k1_src(data)                                               ((0x3F000000&(data))>>24)
#define GDMA_MID_BLEND_B3_get_k1(data)                                               ((0x3F000000&(data))>>24)
#define GDMA_MID_BLEND_B3_k2_shift                                                   (16)
#define GDMA_MID_BLEND_B3_k2_mask                                                    (0x003F0000)
#define GDMA_MID_BLEND_B3_k2(data)                                                   (0x003F0000&((data)<<16))
#define GDMA_MID_BLEND_B3_k2_src(data)                                               ((0x003F0000&(data))>>16)
#define GDMA_MID_BLEND_B3_get_k2(data)                                               ((0x003F0000&(data))>>16)
#define GDMA_MID_BLEND_B3_k3_shift                                                   (8)
#define GDMA_MID_BLEND_B3_k3_mask                                                    (0x00003F00)
#define GDMA_MID_BLEND_B3_k3(data)                                                   (0x00003F00&((data)<<8))
#define GDMA_MID_BLEND_B3_k3_src(data)                                               ((0x00003F00&(data))>>8)
#define GDMA_MID_BLEND_B3_get_k3(data)                                               ((0x00003F00&(data))>>8)
#define GDMA_MID_BLEND_B3_k4_shift                                                   (0)
#define GDMA_MID_BLEND_B3_k4_mask                                                    (0x0000003F)
#define GDMA_MID_BLEND_B3_k4(data)                                                   (0x0000003F&((data)<<0))
#define GDMA_MID_BLEND_B3_k4_src(data)                                               ((0x0000003F&(data))>>0)
#define GDMA_MID_BLEND_B3_get_k4(data)                                               ((0x0000003F&(data))>>0)


#define GDMA_OFFLINE_BLEND                                                           0x1802fa80
#define GDMA_OFFLINE_BLEND_reg_addr                                                  "0xB802FA80"
#define GDMA_OFFLINE_BLEND_reg                                                       0xB802FA80
#define set_GDMA_OFFLINE_BLEND_reg(data)   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_reg)=data)
#define get_GDMA_OFFLINE_BLEND_reg   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_reg))
#define GDMA_OFFLINE_BLEND_inst_adr                                                  "0x00A0"
#define GDMA_OFFLINE_BLEND_inst                                                      0x00A0
#define GDMA_OFFLINE_BLEND_offline_blend_en_shift                                    (31)
#define GDMA_OFFLINE_BLEND_offline_blend_en_mask                                     (0x80000000)
#define GDMA_OFFLINE_BLEND_offline_blend_en(data)                                    (0x80000000&((data)<<31))
#define GDMA_OFFLINE_BLEND_offline_blend_en_src(data)                                ((0x80000000&(data))>>31)
#define GDMA_OFFLINE_BLEND_get_offline_blend_en(data)                                ((0x80000000&(data))>>31)
#define GDMA_OFFLINE_BLEND_c3_plane_alpha_en_shift                                   (19)
#define GDMA_OFFLINE_BLEND_c3_plane_alpha_en_mask                                    (0x00080000)
#define GDMA_OFFLINE_BLEND_c3_plane_alpha_en(data)                                   (0x00080000&((data)<<19))
#define GDMA_OFFLINE_BLEND_c3_plane_alpha_en_src(data)                               ((0x00080000&(data))>>19)
#define GDMA_OFFLINE_BLEND_get_c3_plane_alpha_en(data)                               ((0x00080000&(data))>>19)
#define GDMA_OFFLINE_BLEND_c2_plane_alpha_en_shift                                   (18)
#define GDMA_OFFLINE_BLEND_c2_plane_alpha_en_mask                                    (0x00040000)
#define GDMA_OFFLINE_BLEND_c2_plane_alpha_en(data)                                   (0x00040000&((data)<<18))
#define GDMA_OFFLINE_BLEND_c2_plane_alpha_en_src(data)                               ((0x00040000&(data))>>18)
#define GDMA_OFFLINE_BLEND_get_c2_plane_alpha_en(data)                               ((0x00040000&(data))>>18)
#define GDMA_OFFLINE_BLEND_c1_plane_alpha_en_shift                                   (17)
#define GDMA_OFFLINE_BLEND_c1_plane_alpha_en_mask                                    (0x00020000)
#define GDMA_OFFLINE_BLEND_c1_plane_alpha_en(data)                                   (0x00020000&((data)<<17))
#define GDMA_OFFLINE_BLEND_c1_plane_alpha_en_src(data)                               ((0x00020000&(data))>>17)
#define GDMA_OFFLINE_BLEND_get_c1_plane_alpha_en(data)                               ((0x00020000&(data))>>17)
#define GDMA_OFFLINE_BLEND_c0_plane_alpha_en_shift                                   (16)
#define GDMA_OFFLINE_BLEND_c0_plane_alpha_en_mask                                    (0x00010000)
#define GDMA_OFFLINE_BLEND_c0_plane_alpha_en(data)                                   (0x00010000&((data)<<16))
#define GDMA_OFFLINE_BLEND_c0_plane_alpha_en_src(data)                               ((0x00010000&(data))>>16)
#define GDMA_OFFLINE_BLEND_get_c0_plane_alpha_en(data)                               ((0x00010000&(data))>>16)
#define GDMA_OFFLINE_BLEND_c3_sel_shift                                              (12)
#define GDMA_OFFLINE_BLEND_c3_sel_mask                                               (0x00007000)
#define GDMA_OFFLINE_BLEND_c3_sel(data)                                              (0x00007000&((data)<<12))
#define GDMA_OFFLINE_BLEND_c3_sel_src(data)                                          ((0x00007000&(data))>>12)
#define GDMA_OFFLINE_BLEND_get_c3_sel(data)                                          ((0x00007000&(data))>>12)
#define GDMA_OFFLINE_BLEND_c2_sel_shift                                              (8)
#define GDMA_OFFLINE_BLEND_c2_sel_mask                                               (0x00000700)
#define GDMA_OFFLINE_BLEND_c2_sel(data)                                              (0x00000700&((data)<<8))
#define GDMA_OFFLINE_BLEND_c2_sel_src(data)                                          ((0x00000700&(data))>>8)
#define GDMA_OFFLINE_BLEND_get_c2_sel(data)                                          ((0x00000700&(data))>>8)
#define GDMA_OFFLINE_BLEND_c1_sel_shift                                              (4)
#define GDMA_OFFLINE_BLEND_c1_sel_mask                                               (0x00000070)
#define GDMA_OFFLINE_BLEND_c1_sel(data)                                              (0x00000070&((data)<<4))
#define GDMA_OFFLINE_BLEND_c1_sel_src(data)                                          ((0x00000070&(data))>>4)
#define GDMA_OFFLINE_BLEND_get_c1_sel(data)                                          ((0x00000070&(data))>>4)
#define GDMA_OFFLINE_BLEND_c0_sel_shift                                              (0)
#define GDMA_OFFLINE_BLEND_c0_sel_mask                                               (0x00000007)
#define GDMA_OFFLINE_BLEND_c0_sel(data)                                              (0x00000007&((data)<<0))
#define GDMA_OFFLINE_BLEND_c0_sel_src(data)                                          ((0x00000007&(data))>>0)
#define GDMA_OFFLINE_BLEND_get_c0_sel(data)                                          ((0x00000007&(data))>>0)


#define GDMA_OFF_BLEND_SIZE                                                          0x1802fa84
#define GDMA_OFF_BLEND_SIZE_reg_addr                                                 "0xB802FA84"
#define GDMA_OFF_BLEND_SIZE_reg                                                      0xB802FA84
#define set_GDMA_OFF_BLEND_SIZE_reg(data)   (*((volatile unsigned int*) GDMA_OFF_BLEND_SIZE_reg)=data)
#define get_GDMA_OFF_BLEND_SIZE_reg   (*((volatile unsigned int*) GDMA_OFF_BLEND_SIZE_reg))
#define GDMA_OFF_BLEND_SIZE_inst_adr                                                 "0x00A1"
#define GDMA_OFF_BLEND_SIZE_inst                                                     0x00A1
#define GDMA_OFF_BLEND_SIZE_w_shift                                                  (16)
#define GDMA_OFF_BLEND_SIZE_w_mask                                                   (0x1FFF0000)
#define GDMA_OFF_BLEND_SIZE_w(data)                                                  (0x1FFF0000&((data)<<16))
#define GDMA_OFF_BLEND_SIZE_w_src(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_OFF_BLEND_SIZE_get_w(data)                                              ((0x1FFF0000&(data))>>16)
#define GDMA_OFF_BLEND_SIZE_h_shift                                                  (0)
#define GDMA_OFF_BLEND_SIZE_h_mask                                                   (0x00001FFF)
#define GDMA_OFF_BLEND_SIZE_h(data)                                                  (0x00001FFF&((data)<<0))
#define GDMA_OFF_BLEND_SIZE_h_src(data)                                              ((0x00001FFF&(data))>>0)
#define GDMA_OFF_BLEND_SIZE_get_h(data)                                              ((0x00001FFF&(data))>>0)


#define GDMA_OFFLINE_BLEND_C0                                                        0x1802fa90
#define GDMA_OFFLINE_BLEND_C0_reg_addr                                               "0xB802FA90"
#define GDMA_OFFLINE_BLEND_C0_reg                                                    0xB802FA90
#define set_GDMA_OFFLINE_BLEND_C0_reg(data)   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_C0_reg)=data)
#define get_GDMA_OFFLINE_BLEND_C0_reg   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_C0_reg))
#define GDMA_OFFLINE_BLEND_C0_inst_adr                                               "0x00A4"
#define GDMA_OFFLINE_BLEND_C0_inst                                                   0x00A4
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_a_shift                                    (24)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_a_mask                                     (0xFF000000)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_a(data)                                    (0xFF000000&((data)<<24))
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_a_src(data)                                ((0xFF000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_C0_get_plane_alpha_a(data)                                ((0xFF000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_r_shift                                    (16)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_r_mask                                     (0x00FF0000)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_r(data)                                    (0x00FF0000&((data)<<16))
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_r_src(data)                                ((0x00FF0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_C0_get_plane_alpha_r(data)                                ((0x00FF0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_g_shift                                    (8)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_g_mask                                     (0x0000FF00)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_g(data)                                    (0x0000FF00&((data)<<8))
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_g_src(data)                                ((0x0000FF00&(data))>>8)
#define GDMA_OFFLINE_BLEND_C0_get_plane_alpha_g(data)                                ((0x0000FF00&(data))>>8)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_b_shift                                    (0)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_b_mask                                     (0x000000FF)
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_b(data)                                    (0x000000FF&((data)<<0))
#define GDMA_OFFLINE_BLEND_C0_plane_alpha_b_src(data)                                ((0x000000FF&(data))>>0)
#define GDMA_OFFLINE_BLEND_C0_get_plane_alpha_b(data)                                ((0x000000FF&(data))>>0)


#define GDMA_OFFLINE_BLEND_C1                                                        0x1802fa94
#define GDMA_OFFLINE_BLEND_C1_reg_addr                                               "0xB802FA94"
#define GDMA_OFFLINE_BLEND_C1_reg                                                    0xB802FA94
#define set_GDMA_OFFLINE_BLEND_C1_reg(data)   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_C1_reg)=data)
#define get_GDMA_OFFLINE_BLEND_C1_reg   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_C1_reg))
#define GDMA_OFFLINE_BLEND_C1_inst_adr                                               "0x00A5"
#define GDMA_OFFLINE_BLEND_C1_inst                                                   0x00A5
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_a_shift                                    (24)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_a_mask                                     (0xFF000000)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_a(data)                                    (0xFF000000&((data)<<24))
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_a_src(data)                                ((0xFF000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_C1_get_plane_alpha_a(data)                                ((0xFF000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_r_shift                                    (16)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_r_mask                                     (0x00FF0000)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_r(data)                                    (0x00FF0000&((data)<<16))
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_r_src(data)                                ((0x00FF0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_C1_get_plane_alpha_r(data)                                ((0x00FF0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_g_shift                                    (8)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_g_mask                                     (0x0000FF00)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_g(data)                                    (0x0000FF00&((data)<<8))
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_g_src(data)                                ((0x0000FF00&(data))>>8)
#define GDMA_OFFLINE_BLEND_C1_get_plane_alpha_g(data)                                ((0x0000FF00&(data))>>8)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_b_shift                                    (0)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_b_mask                                     (0x000000FF)
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_b(data)                                    (0x000000FF&((data)<<0))
#define GDMA_OFFLINE_BLEND_C1_plane_alpha_b_src(data)                                ((0x000000FF&(data))>>0)
#define GDMA_OFFLINE_BLEND_C1_get_plane_alpha_b(data)                                ((0x000000FF&(data))>>0)


#define GDMA_OFFLINE_BLEND_C2                                                        0x1802fa98
#define GDMA_OFFLINE_BLEND_C2_reg_addr                                               "0xB802FA98"
#define GDMA_OFFLINE_BLEND_C2_reg                                                    0xB802FA98
#define set_GDMA_OFFLINE_BLEND_C2_reg(data)   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_C2_reg)=data)
#define get_GDMA_OFFLINE_BLEND_C2_reg   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_C2_reg))
#define GDMA_OFFLINE_BLEND_C2_inst_adr                                               "0x00A6"
#define GDMA_OFFLINE_BLEND_C2_inst                                                   0x00A6
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_a_shift                                    (24)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_a_mask                                     (0xFF000000)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_a(data)                                    (0xFF000000&((data)<<24))
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_a_src(data)                                ((0xFF000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_C2_get_plane_alpha_a(data)                                ((0xFF000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_r_shift                                    (16)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_r_mask                                     (0x00FF0000)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_r(data)                                    (0x00FF0000&((data)<<16))
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_r_src(data)                                ((0x00FF0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_C2_get_plane_alpha_r(data)                                ((0x00FF0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_g_shift                                    (8)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_g_mask                                     (0x0000FF00)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_g(data)                                    (0x0000FF00&((data)<<8))
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_g_src(data)                                ((0x0000FF00&(data))>>8)
#define GDMA_OFFLINE_BLEND_C2_get_plane_alpha_g(data)                                ((0x0000FF00&(data))>>8)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_b_shift                                    (0)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_b_mask                                     (0x000000FF)
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_b(data)                                    (0x000000FF&((data)<<0))
#define GDMA_OFFLINE_BLEND_C2_plane_alpha_b_src(data)                                ((0x000000FF&(data))>>0)
#define GDMA_OFFLINE_BLEND_C2_get_plane_alpha_b(data)                                ((0x000000FF&(data))>>0)


#define GDMA_OFFLINE_BLEND_C3                                                        0x1802fa9c
#define GDMA_OFFLINE_BLEND_C3_reg_addr                                               "0xB802FA9C"
#define GDMA_OFFLINE_BLEND_C3_reg                                                    0xB802FA9C
#define set_GDMA_OFFLINE_BLEND_C3_reg(data)   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_C3_reg)=data)
#define get_GDMA_OFFLINE_BLEND_C3_reg   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_C3_reg))
#define GDMA_OFFLINE_BLEND_C3_inst_adr                                               "0x00A7"
#define GDMA_OFFLINE_BLEND_C3_inst                                                   0x00A7
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_a_shift                                    (24)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_a_mask                                     (0xFF000000)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_a(data)                                    (0xFF000000&((data)<<24))
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_a_src(data)                                ((0xFF000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_C3_get_plane_alpha_a(data)                                ((0xFF000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_r_shift                                    (16)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_r_mask                                     (0x00FF0000)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_r(data)                                    (0x00FF0000&((data)<<16))
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_r_src(data)                                ((0x00FF0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_C3_get_plane_alpha_r(data)                                ((0x00FF0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_g_shift                                    (8)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_g_mask                                     (0x0000FF00)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_g(data)                                    (0x0000FF00&((data)<<8))
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_g_src(data)                                ((0x0000FF00&(data))>>8)
#define GDMA_OFFLINE_BLEND_C3_get_plane_alpha_g(data)                                ((0x0000FF00&(data))>>8)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_b_shift                                    (0)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_b_mask                                     (0x000000FF)
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_b(data)                                    (0x000000FF&((data)<<0))
#define GDMA_OFFLINE_BLEND_C3_plane_alpha_b_src(data)                                ((0x000000FF&(data))>>0)
#define GDMA_OFFLINE_BLEND_C3_get_plane_alpha_b(data)                                ((0x000000FF&(data))>>0)


#define GDMA_OFFLINE_BLEND_B1                                                        0x1802fab4
#define GDMA_OFFLINE_BLEND_B1_reg_addr                                               "0xB802FAB4"
#define GDMA_OFFLINE_BLEND_B1_reg                                                    0xB802FAB4
#define set_GDMA_OFFLINE_BLEND_B1_reg(data)   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_B1_reg)=data)
#define get_GDMA_OFFLINE_BLEND_B1_reg   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_B1_reg))
#define GDMA_OFFLINE_BLEND_B1_inst_adr                                               "0x00AD"
#define GDMA_OFFLINE_BLEND_B1_inst                                                   0x00AD
#define GDMA_OFFLINE_BLEND_B1_k1_shift                                               (24)
#define GDMA_OFFLINE_BLEND_B1_k1_mask                                                (0x3F000000)
#define GDMA_OFFLINE_BLEND_B1_k1(data)                                               (0x3F000000&((data)<<24))
#define GDMA_OFFLINE_BLEND_B1_k1_src(data)                                           ((0x3F000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_B1_get_k1(data)                                           ((0x3F000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_B1_k2_shift                                               (16)
#define GDMA_OFFLINE_BLEND_B1_k2_mask                                                (0x003F0000)
#define GDMA_OFFLINE_BLEND_B1_k2(data)                                               (0x003F0000&((data)<<16))
#define GDMA_OFFLINE_BLEND_B1_k2_src(data)                                           ((0x003F0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_B1_get_k2(data)                                           ((0x003F0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_B1_k3_shift                                               (8)
#define GDMA_OFFLINE_BLEND_B1_k3_mask                                                (0x00003F00)
#define GDMA_OFFLINE_BLEND_B1_k3(data)                                               (0x00003F00&((data)<<8))
#define GDMA_OFFLINE_BLEND_B1_k3_src(data)                                           ((0x00003F00&(data))>>8)
#define GDMA_OFFLINE_BLEND_B1_get_k3(data)                                           ((0x00003F00&(data))>>8)
#define GDMA_OFFLINE_BLEND_B1_k4_shift                                               (0)
#define GDMA_OFFLINE_BLEND_B1_k4_mask                                                (0x0000003F)
#define GDMA_OFFLINE_BLEND_B1_k4(data)                                               (0x0000003F&((data)<<0))
#define GDMA_OFFLINE_BLEND_B1_k4_src(data)                                           ((0x0000003F&(data))>>0)
#define GDMA_OFFLINE_BLEND_B1_get_k4(data)                                           ((0x0000003F&(data))>>0)


#define GDMA_OFFLINE_BLEND_B2                                                        0x1802fab8
#define GDMA_OFFLINE_BLEND_B2_reg_addr                                               "0xB802FAB8"
#define GDMA_OFFLINE_BLEND_B2_reg                                                    0xB802FAB8
#define set_GDMA_OFFLINE_BLEND_B2_reg(data)   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_B2_reg)=data)
#define get_GDMA_OFFLINE_BLEND_B2_reg   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_B2_reg))
#define GDMA_OFFLINE_BLEND_B2_inst_adr                                               "0x00AE"
#define GDMA_OFFLINE_BLEND_B2_inst                                                   0x00AE
#define GDMA_OFFLINE_BLEND_B2_k1_shift                                               (24)
#define GDMA_OFFLINE_BLEND_B2_k1_mask                                                (0x3F000000)
#define GDMA_OFFLINE_BLEND_B2_k1(data)                                               (0x3F000000&((data)<<24))
#define GDMA_OFFLINE_BLEND_B2_k1_src(data)                                           ((0x3F000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_B2_get_k1(data)                                           ((0x3F000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_B2_k2_shift                                               (16)
#define GDMA_OFFLINE_BLEND_B2_k2_mask                                                (0x003F0000)
#define GDMA_OFFLINE_BLEND_B2_k2(data)                                               (0x003F0000&((data)<<16))
#define GDMA_OFFLINE_BLEND_B2_k2_src(data)                                           ((0x003F0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_B2_get_k2(data)                                           ((0x003F0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_B2_k3_shift                                               (8)
#define GDMA_OFFLINE_BLEND_B2_k3_mask                                                (0x00003F00)
#define GDMA_OFFLINE_BLEND_B2_k3(data)                                               (0x00003F00&((data)<<8))
#define GDMA_OFFLINE_BLEND_B2_k3_src(data)                                           ((0x00003F00&(data))>>8)
#define GDMA_OFFLINE_BLEND_B2_get_k3(data)                                           ((0x00003F00&(data))>>8)
#define GDMA_OFFLINE_BLEND_B2_k4_shift                                               (0)
#define GDMA_OFFLINE_BLEND_B2_k4_mask                                                (0x0000003F)
#define GDMA_OFFLINE_BLEND_B2_k4(data)                                               (0x0000003F&((data)<<0))
#define GDMA_OFFLINE_BLEND_B2_k4_src(data)                                           ((0x0000003F&(data))>>0)
#define GDMA_OFFLINE_BLEND_B2_get_k4(data)                                           ((0x0000003F&(data))>>0)


#define GDMA_OFFLINE_BLEND_B3                                                        0x1802fabc
#define GDMA_OFFLINE_BLEND_B3_reg_addr                                               "0xB802FABC"
#define GDMA_OFFLINE_BLEND_B3_reg                                                    0xB802FABC
#define set_GDMA_OFFLINE_BLEND_B3_reg(data)   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_B3_reg)=data)
#define get_GDMA_OFFLINE_BLEND_B3_reg   (*((volatile unsigned int*) GDMA_OFFLINE_BLEND_B3_reg))
#define GDMA_OFFLINE_BLEND_B3_inst_adr                                               "0x00AF"
#define GDMA_OFFLINE_BLEND_B3_inst                                                   0x00AF
#define GDMA_OFFLINE_BLEND_B3_k1_shift                                               (24)
#define GDMA_OFFLINE_BLEND_B3_k1_mask                                                (0x3F000000)
#define GDMA_OFFLINE_BLEND_B3_k1(data)                                               (0x3F000000&((data)<<24))
#define GDMA_OFFLINE_BLEND_B3_k1_src(data)                                           ((0x3F000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_B3_get_k1(data)                                           ((0x3F000000&(data))>>24)
#define GDMA_OFFLINE_BLEND_B3_k2_shift                                               (16)
#define GDMA_OFFLINE_BLEND_B3_k2_mask                                                (0x003F0000)
#define GDMA_OFFLINE_BLEND_B3_k2(data)                                               (0x003F0000&((data)<<16))
#define GDMA_OFFLINE_BLEND_B3_k2_src(data)                                           ((0x003F0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_B3_get_k2(data)                                           ((0x003F0000&(data))>>16)
#define GDMA_OFFLINE_BLEND_B3_k3_shift                                               (8)
#define GDMA_OFFLINE_BLEND_B3_k3_mask                                                (0x00003F00)
#define GDMA_OFFLINE_BLEND_B3_k3(data)                                               (0x00003F00&((data)<<8))
#define GDMA_OFFLINE_BLEND_B3_k3_src(data)                                           ((0x00003F00&(data))>>8)
#define GDMA_OFFLINE_BLEND_B3_get_k3(data)                                           ((0x00003F00&(data))>>8)
#define GDMA_OFFLINE_BLEND_B3_k4_shift                                               (0)
#define GDMA_OFFLINE_BLEND_B3_k4_mask                                                (0x0000003F)
#define GDMA_OFFLINE_BLEND_B3_k4(data)                                               (0x0000003F&((data)<<0))
#define GDMA_OFFLINE_BLEND_B3_k4_src(data)                                           ((0x0000003F&(data))>>0)
#define GDMA_OFFLINE_BLEND_B3_get_k4(data)                                           ((0x0000003F&(data))>>0)


#define GDMA_WRITE_BACK_EN                                                           0x1802fb00
#define GDMA_WRITE_BACK_EN_reg_addr                                                  "0xB802FB00"
#define GDMA_WRITE_BACK_EN_reg                                                       0xB802FB00
#define set_GDMA_WRITE_BACK_EN_reg(data)   (*((volatile unsigned int*) GDMA_WRITE_BACK_EN_reg)=data)
#define get_GDMA_WRITE_BACK_EN_reg   (*((volatile unsigned int*) GDMA_WRITE_BACK_EN_reg))
#define GDMA_WRITE_BACK_EN_inst_adr                                                  "0x00C0"
#define GDMA_WRITE_BACK_EN_inst                                                      0x00C0
#define GDMA_WRITE_BACK_EN_write_back_format_shift                                   (1)
#define GDMA_WRITE_BACK_EN_write_back_format_mask                                    (0x00000006)
#define GDMA_WRITE_BACK_EN_write_back_format(data)                                   (0x00000006&((data)<<1))
#define GDMA_WRITE_BACK_EN_write_back_format_src(data)                               ((0x00000006&(data))>>1)
#define GDMA_WRITE_BACK_EN_get_write_back_format(data)                               ((0x00000006&(data))>>1)
#define GDMA_WRITE_BACK_EN_write_back_en_shift                                       (0)
#define GDMA_WRITE_BACK_EN_write_back_en_mask                                        (0x00000001)
#define GDMA_WRITE_BACK_EN_write_back_en(data)                                       (0x00000001&((data)<<0))
#define GDMA_WRITE_BACK_EN_write_back_en_src(data)                                   ((0x00000001&(data))>>0)
#define GDMA_WRITE_BACK_EN_get_write_back_en(data)                                   ((0x00000001&(data))>>0)


#define GDMA_CMP_RESOLUTION                                                          0x1802fb04
#define GDMA_CMP_RESOLUTION_reg_addr                                                 "0xB802FB04"
#define GDMA_CMP_RESOLUTION_reg                                                      0xB802FB04
#define set_GDMA_CMP_RESOLUTION_reg(data)   (*((volatile unsigned int*) GDMA_CMP_RESOLUTION_reg)=data)
#define get_GDMA_CMP_RESOLUTION_reg   (*((volatile unsigned int*) GDMA_CMP_RESOLUTION_reg))
#define GDMA_CMP_RESOLUTION_inst_adr                                                 "0x00C1"
#define GDMA_CMP_RESOLUTION_inst                                                     0x00C1
#define GDMA_CMP_RESOLUTION_cmp_segment_shift                                        (24)
#define GDMA_CMP_RESOLUTION_cmp_segment_mask                                         (0x03000000)
#define GDMA_CMP_RESOLUTION_cmp_segment(data)                                        (0x03000000&((data)<<24))
#define GDMA_CMP_RESOLUTION_cmp_segment_src(data)                                    ((0x03000000&(data))>>24)
#define GDMA_CMP_RESOLUTION_get_cmp_segment(data)                                    ((0x03000000&(data))>>24)
#define GDMA_CMP_RESOLUTION_cmp_width_shift                                          (16)
#define GDMA_CMP_RESOLUTION_cmp_width_mask                                           (0x00FF0000)
#define GDMA_CMP_RESOLUTION_cmp_width(data)                                          (0x00FF0000&((data)<<16))
#define GDMA_CMP_RESOLUTION_cmp_width_src(data)                                      ((0x00FF0000&(data))>>16)
#define GDMA_CMP_RESOLUTION_get_cmp_width(data)                                      ((0x00FF0000&(data))>>16)
#define GDMA_CMP_RESOLUTION_cmp_height_shift                                         (0)
#define GDMA_CMP_RESOLUTION_cmp_height_mask                                          (0x0000FFFF)
#define GDMA_CMP_RESOLUTION_cmp_height(data)                                         (0x0000FFFF&((data)<<0))
#define GDMA_CMP_RESOLUTION_cmp_height_src(data)                                     ((0x0000FFFF&(data))>>0)
#define GDMA_CMP_RESOLUTION_get_cmp_height(data)                                     ((0x0000FFFF&(data))>>0)


#define GDMA_CMP_SETTING                                                             0x1802fb08
#define GDMA_CMP_SETTING_reg_addr                                                    "0xB802FB08"
#define GDMA_CMP_SETTING_reg                                                         0xB802FB08
#define set_GDMA_CMP_SETTING_reg(data)   (*((volatile unsigned int*) GDMA_CMP_SETTING_reg)=data)
#define get_GDMA_CMP_SETTING_reg   (*((volatile unsigned int*) GDMA_CMP_SETTING_reg))
#define GDMA_CMP_SETTING_inst_adr                                                    "0x00C2"
#define GDMA_CMP_SETTING_inst                                                        0x00C2
#define GDMA_CMP_SETTING_cmp_a_ch_mark_shift                                         (31)
#define GDMA_CMP_SETTING_cmp_a_ch_mark_mask                                          (0x80000000)
#define GDMA_CMP_SETTING_cmp_a_ch_mark(data)                                         (0x80000000&((data)<<31))
#define GDMA_CMP_SETTING_cmp_a_ch_mark_src(data)                                     ((0x80000000&(data))>>31)
#define GDMA_CMP_SETTING_get_cmp_a_ch_mark(data)                                     ((0x80000000&(data))>>31)
#define GDMA_CMP_SETTING_cmp_444to422_en_shift                                       (30)
#define GDMA_CMP_SETTING_cmp_444to422_en_mask                                        (0x40000000)
#define GDMA_CMP_SETTING_cmp_444to422_en(data)                                       (0x40000000&((data)<<30))
#define GDMA_CMP_SETTING_cmp_444to422_en_src(data)                                   ((0x40000000&(data))>>30)
#define GDMA_CMP_SETTING_get_cmp_444to422_en(data)                                   ((0x40000000&(data))>>30)
#define GDMA_CMP_SETTING_cmp_RGB_YC_sel_shift                                        (29)
#define GDMA_CMP_SETTING_cmp_RGB_YC_sel_mask                                         (0x20000000)
#define GDMA_CMP_SETTING_cmp_RGB_YC_sel(data)                                        (0x20000000&((data)<<29))
#define GDMA_CMP_SETTING_cmp_RGB_YC_sel_src(data)                                    ((0x20000000&(data))>>29)
#define GDMA_CMP_SETTING_get_cmp_RGB_YC_sel(data)                                    ((0x20000000&(data))>>29)
#define GDMA_CMP_SETTING_cmp_channel_bits_shift                                      (28)
#define GDMA_CMP_SETTING_cmp_channel_bits_mask                                       (0x10000000)
#define GDMA_CMP_SETTING_cmp_channel_bits(data)                                      (0x10000000&((data)<<28))
#define GDMA_CMP_SETTING_cmp_channel_bits_src(data)                                  ((0x10000000&(data))>>28)
#define GDMA_CMP_SETTING_get_cmp_channel_bits(data)                                  ((0x10000000&(data))>>28)
#define GDMA_CMP_SETTING_max_pixel_bits_shift                                        (12)
#define GDMA_CMP_SETTING_max_pixel_bits_mask                                         (0x0003F000)
#define GDMA_CMP_SETTING_max_pixel_bits(data)                                        (0x0003F000&((data)<<12))
#define GDMA_CMP_SETTING_max_pixel_bits_src(data)                                    ((0x0003F000&(data))>>12)
#define GDMA_CMP_SETTING_get_max_pixel_bits(data)                                    ((0x0003F000&(data))>>12)
#define GDMA_CMP_SETTING_short_term_bits_shift                                       (6)
#define GDMA_CMP_SETTING_short_term_bits_mask                                        (0x00000FC0)
#define GDMA_CMP_SETTING_short_term_bits(data)                                       (0x00000FC0&((data)<<6))
#define GDMA_CMP_SETTING_short_term_bits_src(data)                                   ((0x00000FC0&(data))>>6)
#define GDMA_CMP_SETTING_get_short_term_bits(data)                                   ((0x00000FC0&(data))>>6)
#define GDMA_CMP_SETTING_frame_bits_shift                                            (0)
#define GDMA_CMP_SETTING_frame_bits_mask                                             (0x0000003F)
#define GDMA_CMP_SETTING_frame_bits(data)                                            (0x0000003F&((data)<<0))
#define GDMA_CMP_SETTING_frame_bits_src(data)                                        ((0x0000003F&(data))>>0)
#define GDMA_CMP_SETTING_get_frame_bits(data)                                        ((0x0000003F&(data))>>0)


#define GDMA_COMP_INTEN                                                              0x1802fb0c
#define GDMA_COMP_INTEN_reg_addr                                                     "0xB802FB0C"
#define GDMA_COMP_INTEN_reg                                                          0xB802FB0C
#define set_GDMA_COMP_INTEN_reg(data)   (*((volatile unsigned int*) GDMA_COMP_INTEN_reg)=data)
#define get_GDMA_COMP_INTEN_reg   (*((volatile unsigned int*) GDMA_COMP_INTEN_reg))
#define GDMA_COMP_INTEN_inst_adr                                                     "0x00C3"
#define GDMA_COMP_INTEN_inst                                                         0x00C3
#define GDMA_COMP_INTEN_not_segment_status_clr_shift                                 (5)
#define GDMA_COMP_INTEN_not_segment_status_clr_mask                                  (0x00000020)
#define GDMA_COMP_INTEN_not_segment_status_clr(data)                                 (0x00000020&((data)<<5))
#define GDMA_COMP_INTEN_not_segment_status_clr_src(data)                             ((0x00000020&(data))>>5)
#define GDMA_COMP_INTEN_get_not_segment_status_clr(data)                             ((0x00000020&(data))>>5)
#define GDMA_COMP_INTEN_pixel_num_status_clr_shift                                   (4)
#define GDMA_COMP_INTEN_pixel_num_status_clr_mask                                    (0x00000010)
#define GDMA_COMP_INTEN_pixel_num_status_clr(data)                                   (0x00000010&((data)<<4))
#define GDMA_COMP_INTEN_pixel_num_status_clr_src(data)                               ((0x00000010&(data))>>4)
#define GDMA_COMP_INTEN_get_pixel_num_status_clr(data)                               ((0x00000010&(data))>>4)
#define GDMA_COMP_INTEN_over_bits_status_clr_shift                                   (3)
#define GDMA_COMP_INTEN_over_bits_status_clr_mask                                    (0x00000008)
#define GDMA_COMP_INTEN_over_bits_status_clr(data)                                   (0x00000008&((data)<<3))
#define GDMA_COMP_INTEN_over_bits_status_clr_src(data)                               ((0x00000008&(data))>>3)
#define GDMA_COMP_INTEN_get_over_bits_status_clr(data)                               ((0x00000008&(data))>>3)
#define GDMA_COMP_INTEN_comp_irq_en_shift                                            (0)
#define GDMA_COMP_INTEN_comp_irq_en_mask                                             (0x00000007)
#define GDMA_COMP_INTEN_comp_irq_en(data)                                            (0x00000007&((data)<<0))
#define GDMA_COMP_INTEN_comp_irq_en_src(data)                                        ((0x00000007&(data))>>0)
#define GDMA_COMP_INTEN_get_comp_irq_en(data)                                        ((0x00000007&(data))>>0)


#define GDMA_COMP_INTST                                                              0x1802fb10
#define GDMA_COMP_INTST_reg_addr                                                     "0xB802FB10"
#define GDMA_COMP_INTST_reg                                                          0xB802FB10
#define set_GDMA_COMP_INTST_reg(data)   (*((volatile unsigned int*) GDMA_COMP_INTST_reg)=data)
#define get_GDMA_COMP_INTST_reg   (*((volatile unsigned int*) GDMA_COMP_INTST_reg))
#define GDMA_COMP_INTST_inst_adr                                                     "0x00C4"
#define GDMA_COMP_INTST_inst                                                         0x00C4
#define GDMA_COMP_INTST_comp_irq_shift                                               (3)
#define GDMA_COMP_INTST_comp_irq_mask                                                (0x00000008)
#define GDMA_COMP_INTST_comp_irq(data)                                               (0x00000008&((data)<<3))
#define GDMA_COMP_INTST_comp_irq_src(data)                                           ((0x00000008&(data))>>3)
#define GDMA_COMP_INTST_get_comp_irq(data)                                           ((0x00000008&(data))>>3)
#define GDMA_COMP_INTST_comp_status_shift                                            (0)
#define GDMA_COMP_INTST_comp_status_mask                                             (0x00000007)
#define GDMA_COMP_INTST_comp_status(data)                                            (0x00000007&((data)<<0))
#define GDMA_COMP_INTST_comp_status_src(data)                                        ((0x00000007&(data))>>0)
#define GDMA_COMP_INTST_get_comp_status(data)                                        ((0x00000007&(data))>>0)


#define GDMA_WB_DEBUG                                                                0x1802fb14
#define GDMA_WB_DEBUG_reg_addr                                                       "0xB802FB14"
#define GDMA_WB_DEBUG_reg                                                            0xB802FB14
#define set_GDMA_WB_DEBUG_reg(data)   (*((volatile unsigned int*) GDMA_WB_DEBUG_reg)=data)
#define get_GDMA_WB_DEBUG_reg   (*((volatile unsigned int*) GDMA_WB_DEBUG_reg))
#define GDMA_WB_DEBUG_inst_adr                                                       "0x00C5"
#define GDMA_WB_DEBUG_inst                                                           0x00C5
#define GDMA_WB_DEBUG_height_cnt_shift                                               (0)
#define GDMA_WB_DEBUG_height_cnt_mask                                                (0x0003FFFF)
#define GDMA_WB_DEBUG_height_cnt(data)                                               (0x0003FFFF&((data)<<0))
#define GDMA_WB_DEBUG_height_cnt_src(data)                                           ((0x0003FFFF&(data))>>0)
#define GDMA_WB_DEBUG_get_height_cnt(data)                                           ((0x0003FFFF&(data))>>0)


#define GDMA_OSD_INTEN                                                               0x1802fc00
#define GDMA_OSD_INTEN_reg_addr                                                      "0xB802FC00"
#define GDMA_OSD_INTEN_reg                                                           0xB802FC00
#define set_GDMA_OSD_INTEN_reg(data)   (*((volatile unsigned int*) GDMA_OSD_INTEN_reg)=data)
#define get_GDMA_OSD_INTEN_reg   (*((volatile unsigned int*) GDMA_OSD_INTEN_reg))
#define GDMA_OSD_INTEN_inst_adr                                                      "0x0000"
#define GDMA_OSD_INTEN_inst                                                          0x0000
#define GDMA_OSD_INTEN_wdma_done_shift                                               (24)
#define GDMA_OSD_INTEN_wdma_done_mask                                                (0x01000000)
#define GDMA_OSD_INTEN_wdma_done(data)                                               (0x01000000&((data)<<24))
#define GDMA_OSD_INTEN_wdma_done_src(data)                                           ((0x01000000&(data))>>24)
#define GDMA_OSD_INTEN_get_wdma_done(data)                                           ((0x01000000&(data))>>24)
#define GDMA_OSD_INTEN_osd6_fin_shift                                                (22)
#define GDMA_OSD_INTEN_osd6_fin_mask                                                 (0x00400000)
#define GDMA_OSD_INTEN_osd6_fin(data)                                                (0x00400000&((data)<<22))
#define GDMA_OSD_INTEN_osd6_fin_src(data)                                            ((0x00400000&(data))>>22)
#define GDMA_OSD_INTEN_get_osd6_fin(data)                                            ((0x00400000&(data))>>22)
#define GDMA_OSD_INTEN_osd5_fin_shift                                                (21)
#define GDMA_OSD_INTEN_osd5_fin_mask                                                 (0x00200000)
#define GDMA_OSD_INTEN_osd5_fin(data)                                                (0x00200000&((data)<<21))
#define GDMA_OSD_INTEN_osd5_fin_src(data)                                            ((0x00200000&(data))>>21)
#define GDMA_OSD_INTEN_get_osd5_fin(data)                                            ((0x00200000&(data))>>21)
#define GDMA_OSD_INTEN_osd4_fin_shift                                                (20)
#define GDMA_OSD_INTEN_osd4_fin_mask                                                 (0x00100000)
#define GDMA_OSD_INTEN_osd4_fin(data)                                                (0x00100000&((data)<<20))
#define GDMA_OSD_INTEN_osd4_fin_src(data)                                            ((0x00100000&(data))>>20)
#define GDMA_OSD_INTEN_get_osd4_fin(data)                                            ((0x00100000&(data))>>20)
#define GDMA_OSD_INTEN_osd3_fin_shift                                                (19)
#define GDMA_OSD_INTEN_osd3_fin_mask                                                 (0x00080000)
#define GDMA_OSD_INTEN_osd3_fin(data)                                                (0x00080000&((data)<<19))
#define GDMA_OSD_INTEN_osd3_fin_src(data)                                            ((0x00080000&(data))>>19)
#define GDMA_OSD_INTEN_get_osd3_fin(data)                                            ((0x00080000&(data))>>19)
#define GDMA_OSD_INTEN_osd2_fin_shift                                                (18)
#define GDMA_OSD_INTEN_osd2_fin_mask                                                 (0x00040000)
#define GDMA_OSD_INTEN_osd2_fin(data)                                                (0x00040000&((data)<<18))
#define GDMA_OSD_INTEN_osd2_fin_src(data)                                            ((0x00040000&(data))>>18)
#define GDMA_OSD_INTEN_get_osd2_fin(data)                                            ((0x00040000&(data))>>18)
#define GDMA_OSD_INTEN_osd1_fin_shift                                                (17)
#define GDMA_OSD_INTEN_osd1_fin_mask                                                 (0x00020000)
#define GDMA_OSD_INTEN_osd1_fin(data)                                                (0x00020000&((data)<<17))
#define GDMA_OSD_INTEN_osd1_fin_src(data)                                            ((0x00020000&(data))>>17)
#define GDMA_OSD_INTEN_get_osd1_fin(data)                                            ((0x00020000&(data))>>17)
#define GDMA_OSD_INTEN_osd6_vact_end_shift                                           (14)
#define GDMA_OSD_INTEN_osd6_vact_end_mask                                            (0x00004000)
#define GDMA_OSD_INTEN_osd6_vact_end(data)                                           (0x00004000&((data)<<14))
#define GDMA_OSD_INTEN_osd6_vact_end_src(data)                                       ((0x00004000&(data))>>14)
#define GDMA_OSD_INTEN_get_osd6_vact_end(data)                                       ((0x00004000&(data))>>14)
#define GDMA_OSD_INTEN_osd5_vact_end_shift                                           (13)
#define GDMA_OSD_INTEN_osd5_vact_end_mask                                            (0x00002000)
#define GDMA_OSD_INTEN_osd5_vact_end(data)                                           (0x00002000&((data)<<13))
#define GDMA_OSD_INTEN_osd5_vact_end_src(data)                                       ((0x00002000&(data))>>13)
#define GDMA_OSD_INTEN_get_osd5_vact_end(data)                                       ((0x00002000&(data))>>13)
#define GDMA_OSD_INTEN_osd4_vact_end_shift                                           (12)
#define GDMA_OSD_INTEN_osd4_vact_end_mask                                            (0x00001000)
#define GDMA_OSD_INTEN_osd4_vact_end(data)                                           (0x00001000&((data)<<12))
#define GDMA_OSD_INTEN_osd4_vact_end_src(data)                                       ((0x00001000&(data))>>12)
#define GDMA_OSD_INTEN_get_osd4_vact_end(data)                                       ((0x00001000&(data))>>12)
#define GDMA_OSD_INTEN_osd3_vact_end_shift                                           (11)
#define GDMA_OSD_INTEN_osd3_vact_end_mask                                            (0x00000800)
#define GDMA_OSD_INTEN_osd3_vact_end(data)                                           (0x00000800&((data)<<11))
#define GDMA_OSD_INTEN_osd3_vact_end_src(data)                                       ((0x00000800&(data))>>11)
#define GDMA_OSD_INTEN_get_osd3_vact_end(data)                                       ((0x00000800&(data))>>11)
#define GDMA_OSD_INTEN_osd2_vact_end_shift                                           (10)
#define GDMA_OSD_INTEN_osd2_vact_end_mask                                            (0x00000400)
#define GDMA_OSD_INTEN_osd2_vact_end(data)                                           (0x00000400&((data)<<10))
#define GDMA_OSD_INTEN_osd2_vact_end_src(data)                                       ((0x00000400&(data))>>10)
#define GDMA_OSD_INTEN_get_osd2_vact_end(data)                                       ((0x00000400&(data))>>10)
#define GDMA_OSD_INTEN_osd1_vact_end_shift                                           (9)
#define GDMA_OSD_INTEN_osd1_vact_end_mask                                            (0x00000200)
#define GDMA_OSD_INTEN_osd1_vact_end(data)                                           (0x00000200&((data)<<9))
#define GDMA_OSD_INTEN_osd1_vact_end_src(data)                                       ((0x00000200&(data))>>9)
#define GDMA_OSD_INTEN_get_osd1_vact_end(data)                                       ((0x00000200&(data))>>9)
#define GDMA_OSD_INTEN_osd6_vsync_shift                                              (6)
#define GDMA_OSD_INTEN_osd6_vsync_mask                                               (0x00000040)
#define GDMA_OSD_INTEN_osd6_vsync(data)                                              (0x00000040&((data)<<6))
#define GDMA_OSD_INTEN_osd6_vsync_src(data)                                          ((0x00000040&(data))>>6)
#define GDMA_OSD_INTEN_get_osd6_vsync(data)                                          ((0x00000040&(data))>>6)
#define GDMA_OSD_INTEN_osd5_vsync_shift                                              (5)
#define GDMA_OSD_INTEN_osd5_vsync_mask                                               (0x00000020)
#define GDMA_OSD_INTEN_osd5_vsync(data)                                              (0x00000020&((data)<<5))
#define GDMA_OSD_INTEN_osd5_vsync_src(data)                                          ((0x00000020&(data))>>5)
#define GDMA_OSD_INTEN_get_osd5_vsync(data)                                          ((0x00000020&(data))>>5)
#define GDMA_OSD_INTEN_osd4_vsync_shift                                              (4)
#define GDMA_OSD_INTEN_osd4_vsync_mask                                               (0x00000010)
#define GDMA_OSD_INTEN_osd4_vsync(data)                                              (0x00000010&((data)<<4))
#define GDMA_OSD_INTEN_osd4_vsync_src(data)                                          ((0x00000010&(data))>>4)
#define GDMA_OSD_INTEN_get_osd4_vsync(data)                                          ((0x00000010&(data))>>4)
#define GDMA_OSD_INTEN_osd3_vsync_shift                                              (3)
#define GDMA_OSD_INTEN_osd3_vsync_mask                                               (0x00000008)
#define GDMA_OSD_INTEN_osd3_vsync(data)                                              (0x00000008&((data)<<3))
#define GDMA_OSD_INTEN_osd3_vsync_src(data)                                          ((0x00000008&(data))>>3)
#define GDMA_OSD_INTEN_get_osd3_vsync(data)                                          ((0x00000008&(data))>>3)
#define GDMA_OSD_INTEN_osd2_vsync_shift                                              (2)
#define GDMA_OSD_INTEN_osd2_vsync_mask                                               (0x00000004)
#define GDMA_OSD_INTEN_osd2_vsync(data)                                              (0x00000004&((data)<<2))
#define GDMA_OSD_INTEN_osd2_vsync_src(data)                                          ((0x00000004&(data))>>2)
#define GDMA_OSD_INTEN_get_osd2_vsync(data)                                          ((0x00000004&(data))>>2)
#define GDMA_OSD_INTEN_osd1_vsync_shift                                              (1)
#define GDMA_OSD_INTEN_osd1_vsync_mask                                               (0x00000002)
#define GDMA_OSD_INTEN_osd1_vsync(data)                                              (0x00000002&((data)<<1))
#define GDMA_OSD_INTEN_osd1_vsync_src(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD_INTEN_get_osd1_vsync(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD_INTEN_write_data_shift                                              (0)
#define GDMA_OSD_INTEN_write_data_mask                                               (0x00000001)
#define GDMA_OSD_INTEN_write_data(data)                                              (0x00000001&((data)<<0))
#define GDMA_OSD_INTEN_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define GDMA_OSD_INTEN_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define GDMA_OSD_INTST                                                               0x1802fc04
#define GDMA_OSD_INTST_reg_addr                                                      "0xB802FC04"
#define GDMA_OSD_INTST_reg                                                           0xB802FC04
#define set_GDMA_OSD_INTST_reg(data)   (*((volatile unsigned int*) GDMA_OSD_INTST_reg)=data)
#define get_GDMA_OSD_INTST_reg   (*((volatile unsigned int*) GDMA_OSD_INTST_reg))
#define GDMA_OSD_INTST_inst_adr                                                      "0x0001"
#define GDMA_OSD_INTST_inst                                                          0x0001
#define GDMA_OSD_INTST_wdma_done_shift                                               (24)
#define GDMA_OSD_INTST_wdma_done_mask                                                (0x01000000)
#define GDMA_OSD_INTST_wdma_done(data)                                               (0x01000000&((data)<<24))
#define GDMA_OSD_INTST_wdma_done_src(data)                                           ((0x01000000&(data))>>24)
#define GDMA_OSD_INTST_get_wdma_done(data)                                           ((0x01000000&(data))>>24)
#define GDMA_OSD_INTST_osd6_fin_shift                                                (22)
#define GDMA_OSD_INTST_osd6_fin_mask                                                 (0x00400000)
#define GDMA_OSD_INTST_osd6_fin(data)                                                (0x00400000&((data)<<22))
#define GDMA_OSD_INTST_osd6_fin_src(data)                                            ((0x00400000&(data))>>22)
#define GDMA_OSD_INTST_get_osd6_fin(data)                                            ((0x00400000&(data))>>22)
#define GDMA_OSD_INTST_osd5_fin_shift                                                (21)
#define GDMA_OSD_INTST_osd5_fin_mask                                                 (0x00200000)
#define GDMA_OSD_INTST_osd5_fin(data)                                                (0x00200000&((data)<<21))
#define GDMA_OSD_INTST_osd5_fin_src(data)                                            ((0x00200000&(data))>>21)
#define GDMA_OSD_INTST_get_osd5_fin(data)                                            ((0x00200000&(data))>>21)
#define GDMA_OSD_INTST_osd4_fin_shift                                                (20)
#define GDMA_OSD_INTST_osd4_fin_mask                                                 (0x00100000)
#define GDMA_OSD_INTST_osd4_fin(data)                                                (0x00100000&((data)<<20))
#define GDMA_OSD_INTST_osd4_fin_src(data)                                            ((0x00100000&(data))>>20)
#define GDMA_OSD_INTST_get_osd4_fin(data)                                            ((0x00100000&(data))>>20)
#define GDMA_OSD_INTST_osd3_fin_shift                                                (19)
#define GDMA_OSD_INTST_osd3_fin_mask                                                 (0x00080000)
#define GDMA_OSD_INTST_osd3_fin(data)                                                (0x00080000&((data)<<19))
#define GDMA_OSD_INTST_osd3_fin_src(data)                                            ((0x00080000&(data))>>19)
#define GDMA_OSD_INTST_get_osd3_fin(data)                                            ((0x00080000&(data))>>19)
#define GDMA_OSD_INTST_osd2_fin_shift                                                (18)
#define GDMA_OSD_INTST_osd2_fin_mask                                                 (0x00040000)
#define GDMA_OSD_INTST_osd2_fin(data)                                                (0x00040000&((data)<<18))
#define GDMA_OSD_INTST_osd2_fin_src(data)                                            ((0x00040000&(data))>>18)
#define GDMA_OSD_INTST_get_osd2_fin(data)                                            ((0x00040000&(data))>>18)
#define GDMA_OSD_INTST_osd1_fin_shift                                                (17)
#define GDMA_OSD_INTST_osd1_fin_mask                                                 (0x00020000)
#define GDMA_OSD_INTST_osd1_fin(data)                                                (0x00020000&((data)<<17))
#define GDMA_OSD_INTST_osd1_fin_src(data)                                            ((0x00020000&(data))>>17)
#define GDMA_OSD_INTST_get_osd1_fin(data)                                            ((0x00020000&(data))>>17)
#define GDMA_OSD_INTST_osd6_vact_end_shift                                           (14)
#define GDMA_OSD_INTST_osd6_vact_end_mask                                            (0x00004000)
#define GDMA_OSD_INTST_osd6_vact_end(data)                                           (0x00004000&((data)<<14))
#define GDMA_OSD_INTST_osd6_vact_end_src(data)                                       ((0x00004000&(data))>>14)
#define GDMA_OSD_INTST_get_osd6_vact_end(data)                                       ((0x00004000&(data))>>14)
#define GDMA_OSD_INTST_osd5_vact_end_shift                                           (13)
#define GDMA_OSD_INTST_osd5_vact_end_mask                                            (0x00002000)
#define GDMA_OSD_INTST_osd5_vact_end(data)                                           (0x00002000&((data)<<13))
#define GDMA_OSD_INTST_osd5_vact_end_src(data)                                       ((0x00002000&(data))>>13)
#define GDMA_OSD_INTST_get_osd5_vact_end(data)                                       ((0x00002000&(data))>>13)
#define GDMA_OSD_INTST_osd4_vact_end_shift                                           (12)
#define GDMA_OSD_INTST_osd4_vact_end_mask                                            (0x00001000)
#define GDMA_OSD_INTST_osd4_vact_end(data)                                           (0x00001000&((data)<<12))
#define GDMA_OSD_INTST_osd4_vact_end_src(data)                                       ((0x00001000&(data))>>12)
#define GDMA_OSD_INTST_get_osd4_vact_end(data)                                       ((0x00001000&(data))>>12)
#define GDMA_OSD_INTST_osd3_vact_end_shift                                           (11)
#define GDMA_OSD_INTST_osd3_vact_end_mask                                            (0x00000800)
#define GDMA_OSD_INTST_osd3_vact_end(data)                                           (0x00000800&((data)<<11))
#define GDMA_OSD_INTST_osd3_vact_end_src(data)                                       ((0x00000800&(data))>>11)
#define GDMA_OSD_INTST_get_osd3_vact_end(data)                                       ((0x00000800&(data))>>11)
#define GDMA_OSD_INTST_osd2_vact_end_shift                                           (10)
#define GDMA_OSD_INTST_osd2_vact_end_mask                                            (0x00000400)
#define GDMA_OSD_INTST_osd2_vact_end(data)                                           (0x00000400&((data)<<10))
#define GDMA_OSD_INTST_osd2_vact_end_src(data)                                       ((0x00000400&(data))>>10)
#define GDMA_OSD_INTST_get_osd2_vact_end(data)                                       ((0x00000400&(data))>>10)
#define GDMA_OSD_INTST_osd1_vact_end_shift                                           (9)
#define GDMA_OSD_INTST_osd1_vact_end_mask                                            (0x00000200)
#define GDMA_OSD_INTST_osd1_vact_end(data)                                           (0x00000200&((data)<<9))
#define GDMA_OSD_INTST_osd1_vact_end_src(data)                                       ((0x00000200&(data))>>9)
#define GDMA_OSD_INTST_get_osd1_vact_end(data)                                       ((0x00000200&(data))>>9)
#define GDMA_OSD_INTST_osd6_vsync_shift                                              (6)
#define GDMA_OSD_INTST_osd6_vsync_mask                                               (0x00000040)
#define GDMA_OSD_INTST_osd6_vsync(data)                                              (0x00000040&((data)<<6))
#define GDMA_OSD_INTST_osd6_vsync_src(data)                                          ((0x00000040&(data))>>6)
#define GDMA_OSD_INTST_get_osd6_vsync(data)                                          ((0x00000040&(data))>>6)
#define GDMA_OSD_INTST_osd5_vsync_shift                                              (5)
#define GDMA_OSD_INTST_osd5_vsync_mask                                               (0x00000020)
#define GDMA_OSD_INTST_osd5_vsync(data)                                              (0x00000020&((data)<<5))
#define GDMA_OSD_INTST_osd5_vsync_src(data)                                          ((0x00000020&(data))>>5)
#define GDMA_OSD_INTST_get_osd5_vsync(data)                                          ((0x00000020&(data))>>5)
#define GDMA_OSD_INTST_osd4_vsync_shift                                              (4)
#define GDMA_OSD_INTST_osd4_vsync_mask                                               (0x00000010)
#define GDMA_OSD_INTST_osd4_vsync(data)                                              (0x00000010&((data)<<4))
#define GDMA_OSD_INTST_osd4_vsync_src(data)                                          ((0x00000010&(data))>>4)
#define GDMA_OSD_INTST_get_osd4_vsync(data)                                          ((0x00000010&(data))>>4)
#define GDMA_OSD_INTST_osd3_vsync_shift                                              (3)
#define GDMA_OSD_INTST_osd3_vsync_mask                                               (0x00000008)
#define GDMA_OSD_INTST_osd3_vsync(data)                                              (0x00000008&((data)<<3))
#define GDMA_OSD_INTST_osd3_vsync_src(data)                                          ((0x00000008&(data))>>3)
#define GDMA_OSD_INTST_get_osd3_vsync(data)                                          ((0x00000008&(data))>>3)
#define GDMA_OSD_INTST_osd2_vsync_shift                                              (2)
#define GDMA_OSD_INTST_osd2_vsync_mask                                               (0x00000004)
#define GDMA_OSD_INTST_osd2_vsync(data)                                              (0x00000004&((data)<<2))
#define GDMA_OSD_INTST_osd2_vsync_src(data)                                          ((0x00000004&(data))>>2)
#define GDMA_OSD_INTST_get_osd2_vsync(data)                                          ((0x00000004&(data))>>2)
#define GDMA_OSD_INTST_osd1_vsync_shift                                              (1)
#define GDMA_OSD_INTST_osd1_vsync_mask                                               (0x00000002)
#define GDMA_OSD_INTST_osd1_vsync(data)                                              (0x00000002&((data)<<1))
#define GDMA_OSD_INTST_osd1_vsync_src(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD_INTST_get_osd1_vsync(data)                                          ((0x00000002&(data))>>1)
#define GDMA_OSD_INTST_write_data_shift                                              (0)
#define GDMA_OSD_INTST_write_data_mask                                               (0x00000001)
#define GDMA_OSD_INTST_write_data(data)                                              (0x00000001&((data)<<0))
#define GDMA_OSD_INTST_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define GDMA_OSD_INTST_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define GDMA_OSD_INTEN_3D                                                            0x1802fc08
#define GDMA_OSD_INTEN_3D_reg_addr                                                   "0xB802FC08"
#define GDMA_OSD_INTEN_3D_reg                                                        0xB802FC08
#define set_GDMA_OSD_INTEN_3D_reg(data)   (*((volatile unsigned int*) GDMA_OSD_INTEN_3D_reg)=data)
#define get_GDMA_OSD_INTEN_3D_reg   (*((volatile unsigned int*) GDMA_OSD_INTEN_3D_reg))
#define GDMA_OSD_INTEN_3D_inst_adr                                                   "0x0002"
#define GDMA_OSD_INTEN_3D_inst                                                       0x0002
#define GDMA_OSD_INTEN_3D_wdma_done_shift                                            (24)
#define GDMA_OSD_INTEN_3D_wdma_done_mask                                             (0x01000000)
#define GDMA_OSD_INTEN_3D_wdma_done(data)                                            (0x01000000&((data)<<24))
#define GDMA_OSD_INTEN_3D_wdma_done_src(data)                                        ((0x01000000&(data))>>24)
#define GDMA_OSD_INTEN_3D_get_wdma_done(data)                                        ((0x01000000&(data))>>24)
#define GDMA_OSD_INTEN_3D_osd6_fin_shift                                             (22)
#define GDMA_OSD_INTEN_3D_osd6_fin_mask                                              (0x00400000)
#define GDMA_OSD_INTEN_3D_osd6_fin(data)                                             (0x00400000&((data)<<22))
#define GDMA_OSD_INTEN_3D_osd6_fin_src(data)                                         ((0x00400000&(data))>>22)
#define GDMA_OSD_INTEN_3D_get_osd6_fin(data)                                         ((0x00400000&(data))>>22)
#define GDMA_OSD_INTEN_3D_osd5_fin_shift                                             (21)
#define GDMA_OSD_INTEN_3D_osd5_fin_mask                                              (0x00200000)
#define GDMA_OSD_INTEN_3D_osd5_fin(data)                                             (0x00200000&((data)<<21))
#define GDMA_OSD_INTEN_3D_osd5_fin_src(data)                                         ((0x00200000&(data))>>21)
#define GDMA_OSD_INTEN_3D_get_osd5_fin(data)                                         ((0x00200000&(data))>>21)
#define GDMA_OSD_INTEN_3D_osd4_fin_shift                                             (20)
#define GDMA_OSD_INTEN_3D_osd4_fin_mask                                              (0x00100000)
#define GDMA_OSD_INTEN_3D_osd4_fin(data)                                             (0x00100000&((data)<<20))
#define GDMA_OSD_INTEN_3D_osd4_fin_src(data)                                         ((0x00100000&(data))>>20)
#define GDMA_OSD_INTEN_3D_get_osd4_fin(data)                                         ((0x00100000&(data))>>20)
#define GDMA_OSD_INTEN_3D_osd3_fin_shift                                             (19)
#define GDMA_OSD_INTEN_3D_osd3_fin_mask                                              (0x00080000)
#define GDMA_OSD_INTEN_3D_osd3_fin(data)                                             (0x00080000&((data)<<19))
#define GDMA_OSD_INTEN_3D_osd3_fin_src(data)                                         ((0x00080000&(data))>>19)
#define GDMA_OSD_INTEN_3D_get_osd3_fin(data)                                         ((0x00080000&(data))>>19)
#define GDMA_OSD_INTEN_3D_osd2_fin_shift                                             (18)
#define GDMA_OSD_INTEN_3D_osd2_fin_mask                                              (0x00040000)
#define GDMA_OSD_INTEN_3D_osd2_fin(data)                                             (0x00040000&((data)<<18))
#define GDMA_OSD_INTEN_3D_osd2_fin_src(data)                                         ((0x00040000&(data))>>18)
#define GDMA_OSD_INTEN_3D_get_osd2_fin(data)                                         ((0x00040000&(data))>>18)
#define GDMA_OSD_INTEN_3D_osd1_fin_shift                                             (17)
#define GDMA_OSD_INTEN_3D_osd1_fin_mask                                              (0x00020000)
#define GDMA_OSD_INTEN_3D_osd1_fin(data)                                             (0x00020000&((data)<<17))
#define GDMA_OSD_INTEN_3D_osd1_fin_src(data)                                         ((0x00020000&(data))>>17)
#define GDMA_OSD_INTEN_3D_get_osd1_fin(data)                                         ((0x00020000&(data))>>17)
#define GDMA_OSD_INTEN_3D_osd6_vact_end_shift                                        (14)
#define GDMA_OSD_INTEN_3D_osd6_vact_end_mask                                         (0x00004000)
#define GDMA_OSD_INTEN_3D_osd6_vact_end(data)                                        (0x00004000&((data)<<14))
#define GDMA_OSD_INTEN_3D_osd6_vact_end_src(data)                                    ((0x00004000&(data))>>14)
#define GDMA_OSD_INTEN_3D_get_osd6_vact_end(data)                                    ((0x00004000&(data))>>14)
#define GDMA_OSD_INTEN_3D_osd5_vact_end_shift                                        (13)
#define GDMA_OSD_INTEN_3D_osd5_vact_end_mask                                         (0x00002000)
#define GDMA_OSD_INTEN_3D_osd5_vact_end(data)                                        (0x00002000&((data)<<13))
#define GDMA_OSD_INTEN_3D_osd5_vact_end_src(data)                                    ((0x00002000&(data))>>13)
#define GDMA_OSD_INTEN_3D_get_osd5_vact_end(data)                                    ((0x00002000&(data))>>13)
#define GDMA_OSD_INTEN_3D_osd4_vact_end_shift                                        (12)
#define GDMA_OSD_INTEN_3D_osd4_vact_end_mask                                         (0x00001000)
#define GDMA_OSD_INTEN_3D_osd4_vact_end(data)                                        (0x00001000&((data)<<12))
#define GDMA_OSD_INTEN_3D_osd4_vact_end_src(data)                                    ((0x00001000&(data))>>12)
#define GDMA_OSD_INTEN_3D_get_osd4_vact_end(data)                                    ((0x00001000&(data))>>12)
#define GDMA_OSD_INTEN_3D_osd3_vact_end_shift                                        (11)
#define GDMA_OSD_INTEN_3D_osd3_vact_end_mask                                         (0x00000800)
#define GDMA_OSD_INTEN_3D_osd3_vact_end(data)                                        (0x00000800&((data)<<11))
#define GDMA_OSD_INTEN_3D_osd3_vact_end_src(data)                                    ((0x00000800&(data))>>11)
#define GDMA_OSD_INTEN_3D_get_osd3_vact_end(data)                                    ((0x00000800&(data))>>11)
#define GDMA_OSD_INTEN_3D_osd2_vact_end_shift                                        (10)
#define GDMA_OSD_INTEN_3D_osd2_vact_end_mask                                         (0x00000400)
#define GDMA_OSD_INTEN_3D_osd2_vact_end(data)                                        (0x00000400&((data)<<10))
#define GDMA_OSD_INTEN_3D_osd2_vact_end_src(data)                                    ((0x00000400&(data))>>10)
#define GDMA_OSD_INTEN_3D_get_osd2_vact_end(data)                                    ((0x00000400&(data))>>10)
#define GDMA_OSD_INTEN_3D_osd1_vact_end_shift                                        (9)
#define GDMA_OSD_INTEN_3D_osd1_vact_end_mask                                         (0x00000200)
#define GDMA_OSD_INTEN_3D_osd1_vact_end(data)                                        (0x00000200&((data)<<9))
#define GDMA_OSD_INTEN_3D_osd1_vact_end_src(data)                                    ((0x00000200&(data))>>9)
#define GDMA_OSD_INTEN_3D_get_osd1_vact_end(data)                                    ((0x00000200&(data))>>9)
#define GDMA_OSD_INTEN_3D_osd6_vsync_shift                                           (6)
#define GDMA_OSD_INTEN_3D_osd6_vsync_mask                                            (0x00000040)
#define GDMA_OSD_INTEN_3D_osd6_vsync(data)                                           (0x00000040&((data)<<6))
#define GDMA_OSD_INTEN_3D_osd6_vsync_src(data)                                       ((0x00000040&(data))>>6)
#define GDMA_OSD_INTEN_3D_get_osd6_vsync(data)                                       ((0x00000040&(data))>>6)
#define GDMA_OSD_INTEN_3D_osd5_vsync_shift                                           (5)
#define GDMA_OSD_INTEN_3D_osd5_vsync_mask                                            (0x00000020)
#define GDMA_OSD_INTEN_3D_osd5_vsync(data)                                           (0x00000020&((data)<<5))
#define GDMA_OSD_INTEN_3D_osd5_vsync_src(data)                                       ((0x00000020&(data))>>5)
#define GDMA_OSD_INTEN_3D_get_osd5_vsync(data)                                       ((0x00000020&(data))>>5)
#define GDMA_OSD_INTEN_3D_osd4_vsync_shift                                           (4)
#define GDMA_OSD_INTEN_3D_osd4_vsync_mask                                            (0x00000010)
#define GDMA_OSD_INTEN_3D_osd4_vsync(data)                                           (0x00000010&((data)<<4))
#define GDMA_OSD_INTEN_3D_osd4_vsync_src(data)                                       ((0x00000010&(data))>>4)
#define GDMA_OSD_INTEN_3D_get_osd4_vsync(data)                                       ((0x00000010&(data))>>4)
#define GDMA_OSD_INTEN_3D_osd3_vsync_shift                                           (3)
#define GDMA_OSD_INTEN_3D_osd3_vsync_mask                                            (0x00000008)
#define GDMA_OSD_INTEN_3D_osd3_vsync(data)                                           (0x00000008&((data)<<3))
#define GDMA_OSD_INTEN_3D_osd3_vsync_src(data)                                       ((0x00000008&(data))>>3)
#define GDMA_OSD_INTEN_3D_get_osd3_vsync(data)                                       ((0x00000008&(data))>>3)
#define GDMA_OSD_INTEN_3D_osd2_vsync_shift                                           (2)
#define GDMA_OSD_INTEN_3D_osd2_vsync_mask                                            (0x00000004)
#define GDMA_OSD_INTEN_3D_osd2_vsync(data)                                           (0x00000004&((data)<<2))
#define GDMA_OSD_INTEN_3D_osd2_vsync_src(data)                                       ((0x00000004&(data))>>2)
#define GDMA_OSD_INTEN_3D_get_osd2_vsync(data)                                       ((0x00000004&(data))>>2)
#define GDMA_OSD_INTEN_3D_osd1_vsync_shift                                           (1)
#define GDMA_OSD_INTEN_3D_osd1_vsync_mask                                            (0x00000002)
#define GDMA_OSD_INTEN_3D_osd1_vsync(data)                                           (0x00000002&((data)<<1))
#define GDMA_OSD_INTEN_3D_osd1_vsync_src(data)                                       ((0x00000002&(data))>>1)
#define GDMA_OSD_INTEN_3D_get_osd1_vsync(data)                                       ((0x00000002&(data))>>1)
#define GDMA_OSD_INTEN_3D_write_data_shift                                           (0)
#define GDMA_OSD_INTEN_3D_write_data_mask                                            (0x00000001)
#define GDMA_OSD_INTEN_3D_write_data(data)                                           (0x00000001&((data)<<0))
#define GDMA_OSD_INTEN_3D_write_data_src(data)                                       ((0x00000001&(data))>>0)
#define GDMA_OSD_INTEN_3D_get_write_data(data)                                       ((0x00000001&(data))>>0)


#define GDMA_OSD_INTST_3D                                                            0x1802fc0c
#define GDMA_OSD_INTST_3D_reg_addr                                                   "0xB802FC0C"
#define GDMA_OSD_INTST_3D_reg                                                        0xB802FC0C
#define set_GDMA_OSD_INTST_3D_reg(data)   (*((volatile unsigned int*) GDMA_OSD_INTST_3D_reg)=data)
#define get_GDMA_OSD_INTST_3D_reg   (*((volatile unsigned int*) GDMA_OSD_INTST_3D_reg))
#define GDMA_OSD_INTST_3D_inst_adr                                                   "0x0003"
#define GDMA_OSD_INTST_3D_inst                                                       0x0003
#define GDMA_OSD_INTST_3D_wdma_done_shift                                            (24)
#define GDMA_OSD_INTST_3D_wdma_done_mask                                             (0x01000000)
#define GDMA_OSD_INTST_3D_wdma_done(data)                                            (0x01000000&((data)<<24))
#define GDMA_OSD_INTST_3D_wdma_done_src(data)                                        ((0x01000000&(data))>>24)
#define GDMA_OSD_INTST_3D_get_wdma_done(data)                                        ((0x01000000&(data))>>24)
#define GDMA_OSD_INTST_3D_osd6_fin_shift                                             (22)
#define GDMA_OSD_INTST_3D_osd6_fin_mask                                              (0x00400000)
#define GDMA_OSD_INTST_3D_osd6_fin(data)                                             (0x00400000&((data)<<22))
#define GDMA_OSD_INTST_3D_osd6_fin_src(data)                                         ((0x00400000&(data))>>22)
#define GDMA_OSD_INTST_3D_get_osd6_fin(data)                                         ((0x00400000&(data))>>22)
#define GDMA_OSD_INTST_3D_osd5_fin_shift                                             (21)
#define GDMA_OSD_INTST_3D_osd5_fin_mask                                              (0x00200000)
#define GDMA_OSD_INTST_3D_osd5_fin(data)                                             (0x00200000&((data)<<21))
#define GDMA_OSD_INTST_3D_osd5_fin_src(data)                                         ((0x00200000&(data))>>21)
#define GDMA_OSD_INTST_3D_get_osd5_fin(data)                                         ((0x00200000&(data))>>21)
#define GDMA_OSD_INTST_3D_osd4_fin_shift                                             (20)
#define GDMA_OSD_INTST_3D_osd4_fin_mask                                              (0x00100000)
#define GDMA_OSD_INTST_3D_osd4_fin(data)                                             (0x00100000&((data)<<20))
#define GDMA_OSD_INTST_3D_osd4_fin_src(data)                                         ((0x00100000&(data))>>20)
#define GDMA_OSD_INTST_3D_get_osd4_fin(data)                                         ((0x00100000&(data))>>20)
#define GDMA_OSD_INTST_3D_osd3_fin_shift                                             (19)
#define GDMA_OSD_INTST_3D_osd3_fin_mask                                              (0x00080000)
#define GDMA_OSD_INTST_3D_osd3_fin(data)                                             (0x00080000&((data)<<19))
#define GDMA_OSD_INTST_3D_osd3_fin_src(data)                                         ((0x00080000&(data))>>19)
#define GDMA_OSD_INTST_3D_get_osd3_fin(data)                                         ((0x00080000&(data))>>19)
#define GDMA_OSD_INTST_3D_osd2_fin_shift                                             (18)
#define GDMA_OSD_INTST_3D_osd2_fin_mask                                              (0x00040000)
#define GDMA_OSD_INTST_3D_osd2_fin(data)                                             (0x00040000&((data)<<18))
#define GDMA_OSD_INTST_3D_osd2_fin_src(data)                                         ((0x00040000&(data))>>18)
#define GDMA_OSD_INTST_3D_get_osd2_fin(data)                                         ((0x00040000&(data))>>18)
#define GDMA_OSD_INTST_3D_osd1_fin_shift                                             (17)
#define GDMA_OSD_INTST_3D_osd1_fin_mask                                              (0x00020000)
#define GDMA_OSD_INTST_3D_osd1_fin(data)                                             (0x00020000&((data)<<17))
#define GDMA_OSD_INTST_3D_osd1_fin_src(data)                                         ((0x00020000&(data))>>17)
#define GDMA_OSD_INTST_3D_get_osd1_fin(data)                                         ((0x00020000&(data))>>17)
#define GDMA_OSD_INTST_3D_osd6_vact_end_shift                                        (14)
#define GDMA_OSD_INTST_3D_osd6_vact_end_mask                                         (0x00004000)
#define GDMA_OSD_INTST_3D_osd6_vact_end(data)                                        (0x00004000&((data)<<14))
#define GDMA_OSD_INTST_3D_osd6_vact_end_src(data)                                    ((0x00004000&(data))>>14)
#define GDMA_OSD_INTST_3D_get_osd6_vact_end(data)                                    ((0x00004000&(data))>>14)
#define GDMA_OSD_INTST_3D_osd5_vact_end_shift                                        (13)
#define GDMA_OSD_INTST_3D_osd5_vact_end_mask                                         (0x00002000)
#define GDMA_OSD_INTST_3D_osd5_vact_end(data)                                        (0x00002000&((data)<<13))
#define GDMA_OSD_INTST_3D_osd5_vact_end_src(data)                                    ((0x00002000&(data))>>13)
#define GDMA_OSD_INTST_3D_get_osd5_vact_end(data)                                    ((0x00002000&(data))>>13)
#define GDMA_OSD_INTST_3D_osd4_vact_end_shift                                        (12)
#define GDMA_OSD_INTST_3D_osd4_vact_end_mask                                         (0x00001000)
#define GDMA_OSD_INTST_3D_osd4_vact_end(data)                                        (0x00001000&((data)<<12))
#define GDMA_OSD_INTST_3D_osd4_vact_end_src(data)                                    ((0x00001000&(data))>>12)
#define GDMA_OSD_INTST_3D_get_osd4_vact_end(data)                                    ((0x00001000&(data))>>12)
#define GDMA_OSD_INTST_3D_osd3_vact_end_shift                                        (11)
#define GDMA_OSD_INTST_3D_osd3_vact_end_mask                                         (0x00000800)
#define GDMA_OSD_INTST_3D_osd3_vact_end(data)                                        (0x00000800&((data)<<11))
#define GDMA_OSD_INTST_3D_osd3_vact_end_src(data)                                    ((0x00000800&(data))>>11)
#define GDMA_OSD_INTST_3D_get_osd3_vact_end(data)                                    ((0x00000800&(data))>>11)
#define GDMA_OSD_INTST_3D_osd2_vact_end_shift                                        (10)
#define GDMA_OSD_INTST_3D_osd2_vact_end_mask                                         (0x00000400)
#define GDMA_OSD_INTST_3D_osd2_vact_end(data)                                        (0x00000400&((data)<<10))
#define GDMA_OSD_INTST_3D_osd2_vact_end_src(data)                                    ((0x00000400&(data))>>10)
#define GDMA_OSD_INTST_3D_get_osd2_vact_end(data)                                    ((0x00000400&(data))>>10)
#define GDMA_OSD_INTST_3D_osd1_vact_end_shift                                        (9)
#define GDMA_OSD_INTST_3D_osd1_vact_end_mask                                         (0x00000200)
#define GDMA_OSD_INTST_3D_osd1_vact_end(data)                                        (0x00000200&((data)<<9))
#define GDMA_OSD_INTST_3D_osd1_vact_end_src(data)                                    ((0x00000200&(data))>>9)
#define GDMA_OSD_INTST_3D_get_osd1_vact_end(data)                                    ((0x00000200&(data))>>9)
#define GDMA_OSD_INTST_3D_osd6_vsync_shift                                           (6)
#define GDMA_OSD_INTST_3D_osd6_vsync_mask                                            (0x00000040)
#define GDMA_OSD_INTST_3D_osd6_vsync(data)                                           (0x00000040&((data)<<6))
#define GDMA_OSD_INTST_3D_osd6_vsync_src(data)                                       ((0x00000040&(data))>>6)
#define GDMA_OSD_INTST_3D_get_osd6_vsync(data)                                       ((0x00000040&(data))>>6)
#define GDMA_OSD_INTST_3D_osd5_vsync_shift                                           (5)
#define GDMA_OSD_INTST_3D_osd5_vsync_mask                                            (0x00000020)
#define GDMA_OSD_INTST_3D_osd5_vsync(data)                                           (0x00000020&((data)<<5))
#define GDMA_OSD_INTST_3D_osd5_vsync_src(data)                                       ((0x00000020&(data))>>5)
#define GDMA_OSD_INTST_3D_get_osd5_vsync(data)                                       ((0x00000020&(data))>>5)
#define GDMA_OSD_INTST_3D_osd4_vsync_shift                                           (4)
#define GDMA_OSD_INTST_3D_osd4_vsync_mask                                            (0x00000010)
#define GDMA_OSD_INTST_3D_osd4_vsync(data)                                           (0x00000010&((data)<<4))
#define GDMA_OSD_INTST_3D_osd4_vsync_src(data)                                       ((0x00000010&(data))>>4)
#define GDMA_OSD_INTST_3D_get_osd4_vsync(data)                                       ((0x00000010&(data))>>4)
#define GDMA_OSD_INTST_3D_osd3_vsync_shift                                           (3)
#define GDMA_OSD_INTST_3D_osd3_vsync_mask                                            (0x00000008)
#define GDMA_OSD_INTST_3D_osd3_vsync(data)                                           (0x00000008&((data)<<3))
#define GDMA_OSD_INTST_3D_osd3_vsync_src(data)                                       ((0x00000008&(data))>>3)
#define GDMA_OSD_INTST_3D_get_osd3_vsync(data)                                       ((0x00000008&(data))>>3)
#define GDMA_OSD_INTST_3D_osd2_vsync_shift                                           (2)
#define GDMA_OSD_INTST_3D_osd2_vsync_mask                                            (0x00000004)
#define GDMA_OSD_INTST_3D_osd2_vsync(data)                                           (0x00000004&((data)<<2))
#define GDMA_OSD_INTST_3D_osd2_vsync_src(data)                                       ((0x00000004&(data))>>2)
#define GDMA_OSD_INTST_3D_get_osd2_vsync(data)                                       ((0x00000004&(data))>>2)
#define GDMA_OSD_INTST_3D_osd1_vsync_shift                                           (1)
#define GDMA_OSD_INTST_3D_osd1_vsync_mask                                            (0x00000002)
#define GDMA_OSD_INTST_3D_osd1_vsync(data)                                           (0x00000002&((data)<<1))
#define GDMA_OSD_INTST_3D_osd1_vsync_src(data)                                       ((0x00000002&(data))>>1)
#define GDMA_OSD_INTST_3D_get_osd1_vsync(data)                                       ((0x00000002&(data))>>1)
#define GDMA_OSD_INTST_3D_write_data_shift                                           (0)
#define GDMA_OSD_INTST_3D_write_data_mask                                            (0x00000001)
#define GDMA_OSD_INTST_3D_write_data(data)                                           (0x00000001&((data)<<0))
#define GDMA_OSD_INTST_3D_write_data_src(data)                                       ((0x00000001&(data))>>0)
#define GDMA_OSD_INTST_3D_get_write_data(data)                                       ((0x00000001&(data))>>0)


#define GDMA_DMA_INTEN                                                               0x1802fc10
#define GDMA_DMA_INTEN_reg_addr                                                      "0xB802FC10"
#define GDMA_DMA_INTEN_reg                                                           0xB802FC10
#define set_GDMA_DMA_INTEN_reg(data)   (*((volatile unsigned int*) GDMA_DMA_INTEN_reg)=data)
#define get_GDMA_DMA_INTEN_reg   (*((volatile unsigned int*) GDMA_DMA_INTEN_reg))
#define GDMA_DMA_INTEN_inst_adr                                                      "0x0004"
#define GDMA_DMA_INTEN_inst                                                          0x0004
#define GDMA_DMA_INTEN_fbdc_second_acc_sync_shift                                    (21)
#define GDMA_DMA_INTEN_fbdc_second_acc_sync_mask                                     (0x00200000)
#define GDMA_DMA_INTEN_fbdc_second_acc_sync(data)                                    (0x00200000&((data)<<21))
#define GDMA_DMA_INTEN_fbdc_second_acc_sync_src(data)                                ((0x00200000&(data))>>21)
#define GDMA_DMA_INTEN_get_fbdc_second_acc_sync(data)                                ((0x00200000&(data))>>21)
#define GDMA_DMA_INTEN_fbdc_first_acc_sync_shift                                     (20)
#define GDMA_DMA_INTEN_fbdc_first_acc_sync_mask                                      (0x00100000)
#define GDMA_DMA_INTEN_fbdc_first_acc_sync(data)                                     (0x00100000&((data)<<20))
#define GDMA_DMA_INTEN_fbdc_first_acc_sync_src(data)                                 ((0x00100000&(data))>>20)
#define GDMA_DMA_INTEN_get_fbdc_first_acc_sync(data)                                 ((0x00100000&(data))>>20)
#define GDMA_DMA_INTEN_wdma_acc_sync_shift                                           (18)
#define GDMA_DMA_INTEN_wdma_acc_sync_mask                                            (0x00040000)
#define GDMA_DMA_INTEN_wdma_acc_sync(data)                                           (0x00040000&((data)<<18))
#define GDMA_DMA_INTEN_wdma_acc_sync_src(data)                                       ((0x00040000&(data))>>18)
#define GDMA_DMA_INTEN_get_wdma_acc_sync(data)                                       ((0x00040000&(data))>>18)
#define GDMA_DMA_INTEN_wdma_ovfl_shift                                               (17)
#define GDMA_DMA_INTEN_wdma_ovfl_mask                                                (0x00020000)
#define GDMA_DMA_INTEN_wdma_ovfl(data)                                               (0x00020000&((data)<<17))
#define GDMA_DMA_INTEN_wdma_ovfl_src(data)                                           ((0x00020000&(data))>>17)
#define GDMA_DMA_INTEN_get_wdma_ovfl(data)                                           ((0x00020000&(data))>>17)
#define GDMA_DMA_INTEN_wdma_udfl_shift                                               (16)
#define GDMA_DMA_INTEN_wdma_udfl_mask                                                (0x00010000)
#define GDMA_DMA_INTEN_wdma_udfl(data)                                               (0x00010000&((data)<<16))
#define GDMA_DMA_INTEN_wdma_udfl_src(data)                                           ((0x00010000&(data))>>16)
#define GDMA_DMA_INTEN_get_wdma_udfl(data)                                           ((0x00010000&(data))>>16)
#define GDMA_DMA_INTEN_osd6_acc_sync_shift                                           (14)
#define GDMA_DMA_INTEN_osd6_acc_sync_mask                                            (0x00004000)
#define GDMA_DMA_INTEN_osd6_acc_sync(data)                                           (0x00004000&((data)<<14))
#define GDMA_DMA_INTEN_osd6_acc_sync_src(data)                                       ((0x00004000&(data))>>14)
#define GDMA_DMA_INTEN_get_osd6_acc_sync(data)                                       ((0x00004000&(data))>>14)
#define GDMA_DMA_INTEN_osd5_acc_sync_shift                                           (13)
#define GDMA_DMA_INTEN_osd5_acc_sync_mask                                            (0x00002000)
#define GDMA_DMA_INTEN_osd5_acc_sync(data)                                           (0x00002000&((data)<<13))
#define GDMA_DMA_INTEN_osd5_acc_sync_src(data)                                       ((0x00002000&(data))>>13)
#define GDMA_DMA_INTEN_get_osd5_acc_sync(data)                                       ((0x00002000&(data))>>13)
#define GDMA_DMA_INTEN_osd4_acc_sync_shift                                           (12)
#define GDMA_DMA_INTEN_osd4_acc_sync_mask                                            (0x00001000)
#define GDMA_DMA_INTEN_osd4_acc_sync(data)                                           (0x00001000&((data)<<12))
#define GDMA_DMA_INTEN_osd4_acc_sync_src(data)                                       ((0x00001000&(data))>>12)
#define GDMA_DMA_INTEN_get_osd4_acc_sync(data)                                       ((0x00001000&(data))>>12)
#define GDMA_DMA_INTEN_osd3_acc_sync_shift                                           (11)
#define GDMA_DMA_INTEN_osd3_acc_sync_mask                                            (0x00000800)
#define GDMA_DMA_INTEN_osd3_acc_sync(data)                                           (0x00000800&((data)<<11))
#define GDMA_DMA_INTEN_osd3_acc_sync_src(data)                                       ((0x00000800&(data))>>11)
#define GDMA_DMA_INTEN_get_osd3_acc_sync(data)                                       ((0x00000800&(data))>>11)
#define GDMA_DMA_INTEN_osd2_acc_sync_shift                                           (10)
#define GDMA_DMA_INTEN_osd2_acc_sync_mask                                            (0x00000400)
#define GDMA_DMA_INTEN_osd2_acc_sync(data)                                           (0x00000400&((data)<<10))
#define GDMA_DMA_INTEN_osd2_acc_sync_src(data)                                       ((0x00000400&(data))>>10)
#define GDMA_DMA_INTEN_get_osd2_acc_sync(data)                                       ((0x00000400&(data))>>10)
#define GDMA_DMA_INTEN_osd1_acc_sync_shift                                           (9)
#define GDMA_DMA_INTEN_osd1_acc_sync_mask                                            (0x00000200)
#define GDMA_DMA_INTEN_osd1_acc_sync(data)                                           (0x00000200&((data)<<9))
#define GDMA_DMA_INTEN_osd1_acc_sync_src(data)                                       ((0x00000200&(data))>>9)
#define GDMA_DMA_INTEN_get_osd1_acc_sync(data)                                       ((0x00000200&(data))>>9)
#define GDMA_DMA_INTEN_osd6_udfl_shift                                               (6)
#define GDMA_DMA_INTEN_osd6_udfl_mask                                                (0x00000040)
#define GDMA_DMA_INTEN_osd6_udfl(data)                                               (0x00000040&((data)<<6))
#define GDMA_DMA_INTEN_osd6_udfl_src(data)                                           ((0x00000040&(data))>>6)
#define GDMA_DMA_INTEN_get_osd6_udfl(data)                                           ((0x00000040&(data))>>6)
#define GDMA_DMA_INTEN_osd5_udfl_shift                                               (5)
#define GDMA_DMA_INTEN_osd5_udfl_mask                                                (0x00000020)
#define GDMA_DMA_INTEN_osd5_udfl(data)                                               (0x00000020&((data)<<5))
#define GDMA_DMA_INTEN_osd5_udfl_src(data)                                           ((0x00000020&(data))>>5)
#define GDMA_DMA_INTEN_get_osd5_udfl(data)                                           ((0x00000020&(data))>>5)
#define GDMA_DMA_INTEN_osd4_udfl_shift                                               (4)
#define GDMA_DMA_INTEN_osd4_udfl_mask                                                (0x00000010)
#define GDMA_DMA_INTEN_osd4_udfl(data)                                               (0x00000010&((data)<<4))
#define GDMA_DMA_INTEN_osd4_udfl_src(data)                                           ((0x00000010&(data))>>4)
#define GDMA_DMA_INTEN_get_osd4_udfl(data)                                           ((0x00000010&(data))>>4)
#define GDMA_DMA_INTEN_osd3_udfl_shift                                               (3)
#define GDMA_DMA_INTEN_osd3_udfl_mask                                                (0x00000008)
#define GDMA_DMA_INTEN_osd3_udfl(data)                                               (0x00000008&((data)<<3))
#define GDMA_DMA_INTEN_osd3_udfl_src(data)                                           ((0x00000008&(data))>>3)
#define GDMA_DMA_INTEN_get_osd3_udfl(data)                                           ((0x00000008&(data))>>3)
#define GDMA_DMA_INTEN_osd2_udfl_shift                                               (2)
#define GDMA_DMA_INTEN_osd2_udfl_mask                                                (0x00000004)
#define GDMA_DMA_INTEN_osd2_udfl(data)                                               (0x00000004&((data)<<2))
#define GDMA_DMA_INTEN_osd2_udfl_src(data)                                           ((0x00000004&(data))>>2)
#define GDMA_DMA_INTEN_get_osd2_udfl(data)                                           ((0x00000004&(data))>>2)
#define GDMA_DMA_INTEN_osd1_udfl_shift                                               (1)
#define GDMA_DMA_INTEN_osd1_udfl_mask                                                (0x00000002)
#define GDMA_DMA_INTEN_osd1_udfl(data)                                               (0x00000002&((data)<<1))
#define GDMA_DMA_INTEN_osd1_udfl_src(data)                                           ((0x00000002&(data))>>1)
#define GDMA_DMA_INTEN_get_osd1_udfl(data)                                           ((0x00000002&(data))>>1)
#define GDMA_DMA_INTEN_write_data_shift                                              (0)
#define GDMA_DMA_INTEN_write_data_mask                                               (0x00000001)
#define GDMA_DMA_INTEN_write_data(data)                                              (0x00000001&((data)<<0))
#define GDMA_DMA_INTEN_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define GDMA_DMA_INTEN_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define GDMA_DMA_INTST                                                               0x1802fc14
#define GDMA_DMA_INTST_reg_addr                                                      "0xB802FC14"
#define GDMA_DMA_INTST_reg                                                           0xB802FC14
#define set_GDMA_DMA_INTST_reg(data)   (*((volatile unsigned int*) GDMA_DMA_INTST_reg)=data)
#define get_GDMA_DMA_INTST_reg   (*((volatile unsigned int*) GDMA_DMA_INTST_reg))
#define GDMA_DMA_INTST_inst_adr                                                      "0x0005"
#define GDMA_DMA_INTST_inst                                                          0x0005
#define GDMA_DMA_INTST_fbdc_second_acc_sync_shift                                    (21)
#define GDMA_DMA_INTST_fbdc_second_acc_sync_mask                                     (0x00200000)
#define GDMA_DMA_INTST_fbdc_second_acc_sync(data)                                    (0x00200000&((data)<<21))
#define GDMA_DMA_INTST_fbdc_second_acc_sync_src(data)                                ((0x00200000&(data))>>21)
#define GDMA_DMA_INTST_get_fbdc_second_acc_sync(data)                                ((0x00200000&(data))>>21)
#define GDMA_DMA_INTST_fbdc_first_acc_sync_shift                                     (20)
#define GDMA_DMA_INTST_fbdc_first_acc_sync_mask                                      (0x00100000)
#define GDMA_DMA_INTST_fbdc_first_acc_sync(data)                                     (0x00100000&((data)<<20))
#define GDMA_DMA_INTST_fbdc_first_acc_sync_src(data)                                 ((0x00100000&(data))>>20)
#define GDMA_DMA_INTST_get_fbdc_first_acc_sync(data)                                 ((0x00100000&(data))>>20)
#define GDMA_DMA_INTST_wdma_acc_sync_shift                                           (18)
#define GDMA_DMA_INTST_wdma_acc_sync_mask                                            (0x00040000)
#define GDMA_DMA_INTST_wdma_acc_sync(data)                                           (0x00040000&((data)<<18))
#define GDMA_DMA_INTST_wdma_acc_sync_src(data)                                       ((0x00040000&(data))>>18)
#define GDMA_DMA_INTST_get_wdma_acc_sync(data)                                       ((0x00040000&(data))>>18)
#define GDMA_DMA_INTST_wdma_ovfl_shift                                               (17)
#define GDMA_DMA_INTST_wdma_ovfl_mask                                                (0x00020000)
#define GDMA_DMA_INTST_wdma_ovfl(data)                                               (0x00020000&((data)<<17))
#define GDMA_DMA_INTST_wdma_ovfl_src(data)                                           ((0x00020000&(data))>>17)
#define GDMA_DMA_INTST_get_wdma_ovfl(data)                                           ((0x00020000&(data))>>17)
#define GDMA_DMA_INTST_wdma_udfl_shift                                               (16)
#define GDMA_DMA_INTST_wdma_udfl_mask                                                (0x00010000)
#define GDMA_DMA_INTST_wdma_udfl(data)                                               (0x00010000&((data)<<16))
#define GDMA_DMA_INTST_wdma_udfl_src(data)                                           ((0x00010000&(data))>>16)
#define GDMA_DMA_INTST_get_wdma_udfl(data)                                           ((0x00010000&(data))>>16)
#define GDMA_DMA_INTST_osd6_acc_sync_shift                                           (14)
#define GDMA_DMA_INTST_osd6_acc_sync_mask                                            (0x00004000)
#define GDMA_DMA_INTST_osd6_acc_sync(data)                                           (0x00004000&((data)<<14))
#define GDMA_DMA_INTST_osd6_acc_sync_src(data)                                       ((0x00004000&(data))>>14)
#define GDMA_DMA_INTST_get_osd6_acc_sync(data)                                       ((0x00004000&(data))>>14)
#define GDMA_DMA_INTST_osd5_acc_sync_shift                                           (13)
#define GDMA_DMA_INTST_osd5_acc_sync_mask                                            (0x00002000)
#define GDMA_DMA_INTST_osd5_acc_sync(data)                                           (0x00002000&((data)<<13))
#define GDMA_DMA_INTST_osd5_acc_sync_src(data)                                       ((0x00002000&(data))>>13)
#define GDMA_DMA_INTST_get_osd5_acc_sync(data)                                       ((0x00002000&(data))>>13)
#define GDMA_DMA_INTST_osd4_acc_sync_shift                                           (12)
#define GDMA_DMA_INTST_osd4_acc_sync_mask                                            (0x00001000)
#define GDMA_DMA_INTST_osd4_acc_sync(data)                                           (0x00001000&((data)<<12))
#define GDMA_DMA_INTST_osd4_acc_sync_src(data)                                       ((0x00001000&(data))>>12)
#define GDMA_DMA_INTST_get_osd4_acc_sync(data)                                       ((0x00001000&(data))>>12)
#define GDMA_DMA_INTST_osd3_acc_sync_shift                                           (11)
#define GDMA_DMA_INTST_osd3_acc_sync_mask                                            (0x00000800)
#define GDMA_DMA_INTST_osd3_acc_sync(data)                                           (0x00000800&((data)<<11))
#define GDMA_DMA_INTST_osd3_acc_sync_src(data)                                       ((0x00000800&(data))>>11)
#define GDMA_DMA_INTST_get_osd3_acc_sync(data)                                       ((0x00000800&(data))>>11)
#define GDMA_DMA_INTST_osd2_acc_sync_shift                                           (10)
#define GDMA_DMA_INTST_osd2_acc_sync_mask                                            (0x00000400)
#define GDMA_DMA_INTST_osd2_acc_sync(data)                                           (0x00000400&((data)<<10))
#define GDMA_DMA_INTST_osd2_acc_sync_src(data)                                       ((0x00000400&(data))>>10)
#define GDMA_DMA_INTST_get_osd2_acc_sync(data)                                       ((0x00000400&(data))>>10)
#define GDMA_DMA_INTST_osd1_acc_sync_shift                                           (9)
#define GDMA_DMA_INTST_osd1_acc_sync_mask                                            (0x00000200)
#define GDMA_DMA_INTST_osd1_acc_sync(data)                                           (0x00000200&((data)<<9))
#define GDMA_DMA_INTST_osd1_acc_sync_src(data)                                       ((0x00000200&(data))>>9)
#define GDMA_DMA_INTST_get_osd1_acc_sync(data)                                       ((0x00000200&(data))>>9)
#define GDMA_DMA_INTST_osd6_udfl_shift                                               (6)
#define GDMA_DMA_INTST_osd6_udfl_mask                                                (0x00000040)
#define GDMA_DMA_INTST_osd6_udfl(data)                                               (0x00000040&((data)<<6))
#define GDMA_DMA_INTST_osd6_udfl_src(data)                                           ((0x00000040&(data))>>6)
#define GDMA_DMA_INTST_get_osd6_udfl(data)                                           ((0x00000040&(data))>>6)
#define GDMA_DMA_INTST_osd5_udfl_shift                                               (5)
#define GDMA_DMA_INTST_osd5_udfl_mask                                                (0x00000020)
#define GDMA_DMA_INTST_osd5_udfl(data)                                               (0x00000020&((data)<<5))
#define GDMA_DMA_INTST_osd5_udfl_src(data)                                           ((0x00000020&(data))>>5)
#define GDMA_DMA_INTST_get_osd5_udfl(data)                                           ((0x00000020&(data))>>5)
#define GDMA_DMA_INTST_osd4_udfl_shift                                               (4)
#define GDMA_DMA_INTST_osd4_udfl_mask                                                (0x00000010)
#define GDMA_DMA_INTST_osd4_udfl(data)                                               (0x00000010&((data)<<4))
#define GDMA_DMA_INTST_osd4_udfl_src(data)                                           ((0x00000010&(data))>>4)
#define GDMA_DMA_INTST_get_osd4_udfl(data)                                           ((0x00000010&(data))>>4)
#define GDMA_DMA_INTST_osd3_udfl_shift                                               (3)
#define GDMA_DMA_INTST_osd3_udfl_mask                                                (0x00000008)
#define GDMA_DMA_INTST_osd3_udfl(data)                                               (0x00000008&((data)<<3))
#define GDMA_DMA_INTST_osd3_udfl_src(data)                                           ((0x00000008&(data))>>3)
#define GDMA_DMA_INTST_get_osd3_udfl(data)                                           ((0x00000008&(data))>>3)
#define GDMA_DMA_INTST_osd2_udfl_shift                                               (2)
#define GDMA_DMA_INTST_osd2_udfl_mask                                                (0x00000004)
#define GDMA_DMA_INTST_osd2_udfl(data)                                               (0x00000004&((data)<<2))
#define GDMA_DMA_INTST_osd2_udfl_src(data)                                           ((0x00000004&(data))>>2)
#define GDMA_DMA_INTST_get_osd2_udfl(data)                                           ((0x00000004&(data))>>2)
#define GDMA_DMA_INTST_osd1_udfl_shift                                               (1)
#define GDMA_DMA_INTST_osd1_udfl_mask                                                (0x00000002)
#define GDMA_DMA_INTST_osd1_udfl(data)                                               (0x00000002&((data)<<1))
#define GDMA_DMA_INTST_osd1_udfl_src(data)                                           ((0x00000002&(data))>>1)
#define GDMA_DMA_INTST_get_osd1_udfl(data)                                           ((0x00000002&(data))>>1)
#define GDMA_DMA_INTST_write_data_shift                                              (0)
#define GDMA_DMA_INTST_write_data_mask                                               (0x00000001)
#define GDMA_DMA_INTST_write_data(data)                                              (0x00000001&((data)<<0))
#define GDMA_DMA_INTST_write_data_src(data)                                          ((0x00000001&(data))>>0)
#define GDMA_DMA_INTST_get_write_data(data)                                          ((0x00000001&(data))>>0)


#define GDMA_DMA_INTEN_3D                                                            0x1802fc18
#define GDMA_DMA_INTEN_3D_reg_addr                                                   "0xB802FC18"
#define GDMA_DMA_INTEN_3D_reg                                                        0xB802FC18
#define set_GDMA_DMA_INTEN_3D_reg(data)   (*((volatile unsigned int*) GDMA_DMA_INTEN_3D_reg)=data)
#define get_GDMA_DMA_INTEN_3D_reg   (*((volatile unsigned int*) GDMA_DMA_INTEN_3D_reg))
#define GDMA_DMA_INTEN_3D_inst_adr                                                   "0x0006"
#define GDMA_DMA_INTEN_3D_inst                                                       0x0006
#define GDMA_DMA_INTEN_3D_wdma_ovfl_shift                                            (17)
#define GDMA_DMA_INTEN_3D_wdma_ovfl_mask                                             (0x00020000)
#define GDMA_DMA_INTEN_3D_wdma_ovfl(data)                                            (0x00020000&((data)<<17))
#define GDMA_DMA_INTEN_3D_wdma_ovfl_src(data)                                        ((0x00020000&(data))>>17)
#define GDMA_DMA_INTEN_3D_get_wdma_ovfl(data)                                        ((0x00020000&(data))>>17)
#define GDMA_DMA_INTEN_3D_wdma_udfl_shift                                            (16)
#define GDMA_DMA_INTEN_3D_wdma_udfl_mask                                             (0x00010000)
#define GDMA_DMA_INTEN_3D_wdma_udfl(data)                                            (0x00010000&((data)<<16))
#define GDMA_DMA_INTEN_3D_wdma_udfl_src(data)                                        ((0x00010000&(data))>>16)
#define GDMA_DMA_INTEN_3D_get_wdma_udfl(data)                                        ((0x00010000&(data))>>16)
#define GDMA_DMA_INTEN_3D_osd6_acc_sync_shift                                        (14)
#define GDMA_DMA_INTEN_3D_osd6_acc_sync_mask                                         (0x00004000)
#define GDMA_DMA_INTEN_3D_osd6_acc_sync(data)                                        (0x00004000&((data)<<14))
#define GDMA_DMA_INTEN_3D_osd6_acc_sync_src(data)                                    ((0x00004000&(data))>>14)
#define GDMA_DMA_INTEN_3D_get_osd6_acc_sync(data)                                    ((0x00004000&(data))>>14)
#define GDMA_DMA_INTEN_3D_osd5_acc_sync_shift                                        (13)
#define GDMA_DMA_INTEN_3D_osd5_acc_sync_mask                                         (0x00002000)
#define GDMA_DMA_INTEN_3D_osd5_acc_sync(data)                                        (0x00002000&((data)<<13))
#define GDMA_DMA_INTEN_3D_osd5_acc_sync_src(data)                                    ((0x00002000&(data))>>13)
#define GDMA_DMA_INTEN_3D_get_osd5_acc_sync(data)                                    ((0x00002000&(data))>>13)
#define GDMA_DMA_INTEN_3D_osd4_acc_sync_shift                                        (12)
#define GDMA_DMA_INTEN_3D_osd4_acc_sync_mask                                         (0x00001000)
#define GDMA_DMA_INTEN_3D_osd4_acc_sync(data)                                        (0x00001000&((data)<<12))
#define GDMA_DMA_INTEN_3D_osd4_acc_sync_src(data)                                    ((0x00001000&(data))>>12)
#define GDMA_DMA_INTEN_3D_get_osd4_acc_sync(data)                                    ((0x00001000&(data))>>12)
#define GDMA_DMA_INTEN_3D_osd3_acc_sync_shift                                        (11)
#define GDMA_DMA_INTEN_3D_osd3_acc_sync_mask                                         (0x00000800)
#define GDMA_DMA_INTEN_3D_osd3_acc_sync(data)                                        (0x00000800&((data)<<11))
#define GDMA_DMA_INTEN_3D_osd3_acc_sync_src(data)                                    ((0x00000800&(data))>>11)
#define GDMA_DMA_INTEN_3D_get_osd3_acc_sync(data)                                    ((0x00000800&(data))>>11)
#define GDMA_DMA_INTEN_3D_osd2_acc_sync_shift                                        (10)
#define GDMA_DMA_INTEN_3D_osd2_acc_sync_mask                                         (0x00000400)
#define GDMA_DMA_INTEN_3D_osd2_acc_sync(data)                                        (0x00000400&((data)<<10))
#define GDMA_DMA_INTEN_3D_osd2_acc_sync_src(data)                                    ((0x00000400&(data))>>10)
#define GDMA_DMA_INTEN_3D_get_osd2_acc_sync(data)                                    ((0x00000400&(data))>>10)
#define GDMA_DMA_INTEN_3D_osd1_acc_sync_shift                                        (9)
#define GDMA_DMA_INTEN_3D_osd1_acc_sync_mask                                         (0x00000200)
#define GDMA_DMA_INTEN_3D_osd1_acc_sync(data)                                        (0x00000200&((data)<<9))
#define GDMA_DMA_INTEN_3D_osd1_acc_sync_src(data)                                    ((0x00000200&(data))>>9)
#define GDMA_DMA_INTEN_3D_get_osd1_acc_sync(data)                                    ((0x00000200&(data))>>9)
#define GDMA_DMA_INTEN_3D_osd6_udfl_shift                                            (6)
#define GDMA_DMA_INTEN_3D_osd6_udfl_mask                                             (0x00000040)
#define GDMA_DMA_INTEN_3D_osd6_udfl(data)                                            (0x00000040&((data)<<6))
#define GDMA_DMA_INTEN_3D_osd6_udfl_src(data)                                        ((0x00000040&(data))>>6)
#define GDMA_DMA_INTEN_3D_get_osd6_udfl(data)                                        ((0x00000040&(data))>>6)
#define GDMA_DMA_INTEN_3D_osd5_udfl_shift                                            (5)
#define GDMA_DMA_INTEN_3D_osd5_udfl_mask                                             (0x00000020)
#define GDMA_DMA_INTEN_3D_osd5_udfl(data)                                            (0x00000020&((data)<<5))
#define GDMA_DMA_INTEN_3D_osd5_udfl_src(data)                                        ((0x00000020&(data))>>5)
#define GDMA_DMA_INTEN_3D_get_osd5_udfl(data)                                        ((0x00000020&(data))>>5)
#define GDMA_DMA_INTEN_3D_osd4_udfl_shift                                            (4)
#define GDMA_DMA_INTEN_3D_osd4_udfl_mask                                             (0x00000010)
#define GDMA_DMA_INTEN_3D_osd4_udfl(data)                                            (0x00000010&((data)<<4))
#define GDMA_DMA_INTEN_3D_osd4_udfl_src(data)                                        ((0x00000010&(data))>>4)
#define GDMA_DMA_INTEN_3D_get_osd4_udfl(data)                                        ((0x00000010&(data))>>4)
#define GDMA_DMA_INTEN_3D_osd3_udfl_shift                                            (3)
#define GDMA_DMA_INTEN_3D_osd3_udfl_mask                                             (0x00000008)
#define GDMA_DMA_INTEN_3D_osd3_udfl(data)                                            (0x00000008&((data)<<3))
#define GDMA_DMA_INTEN_3D_osd3_udfl_src(data)                                        ((0x00000008&(data))>>3)
#define GDMA_DMA_INTEN_3D_get_osd3_udfl(data)                                        ((0x00000008&(data))>>3)
#define GDMA_DMA_INTEN_3D_osd2_udfl_shift                                            (2)
#define GDMA_DMA_INTEN_3D_osd2_udfl_mask                                             (0x00000004)
#define GDMA_DMA_INTEN_3D_osd2_udfl(data)                                            (0x00000004&((data)<<2))
#define GDMA_DMA_INTEN_3D_osd2_udfl_src(data)                                        ((0x00000004&(data))>>2)
#define GDMA_DMA_INTEN_3D_get_osd2_udfl(data)                                        ((0x00000004&(data))>>2)
#define GDMA_DMA_INTEN_3D_osd1_udfl_shift                                            (1)
#define GDMA_DMA_INTEN_3D_osd1_udfl_mask                                             (0x00000002)
#define GDMA_DMA_INTEN_3D_osd1_udfl(data)                                            (0x00000002&((data)<<1))
#define GDMA_DMA_INTEN_3D_osd1_udfl_src(data)                                        ((0x00000002&(data))>>1)
#define GDMA_DMA_INTEN_3D_get_osd1_udfl(data)                                        ((0x00000002&(data))>>1)
#define GDMA_DMA_INTEN_3D_write_data_shift                                           (0)
#define GDMA_DMA_INTEN_3D_write_data_mask                                            (0x00000001)
#define GDMA_DMA_INTEN_3D_write_data(data)                                           (0x00000001&((data)<<0))
#define GDMA_DMA_INTEN_3D_write_data_src(data)                                       ((0x00000001&(data))>>0)
#define GDMA_DMA_INTEN_3D_get_write_data(data)                                       ((0x00000001&(data))>>0)


#define GDMA_DMA_INTST_3D                                                            0x1802fc1c
#define GDMA_DMA_INTST_3D_reg_addr                                                   "0xB802FC1C"
#define GDMA_DMA_INTST_3D_reg                                                        0xB802FC1C
#define set_GDMA_DMA_INTST_3D_reg(data)   (*((volatile unsigned int*) GDMA_DMA_INTST_3D_reg)=data)
#define get_GDMA_DMA_INTST_3D_reg   (*((volatile unsigned int*) GDMA_DMA_INTST_3D_reg))
#define GDMA_DMA_INTST_3D_inst_adr                                                   "0x0007"
#define GDMA_DMA_INTST_3D_inst                                                       0x0007
#define GDMA_DMA_INTST_3D_wdma_ovfl_shift                                            (17)
#define GDMA_DMA_INTST_3D_wdma_ovfl_mask                                             (0x00020000)
#define GDMA_DMA_INTST_3D_wdma_ovfl(data)                                            (0x00020000&((data)<<17))
#define GDMA_DMA_INTST_3D_wdma_ovfl_src(data)                                        ((0x00020000&(data))>>17)
#define GDMA_DMA_INTST_3D_get_wdma_ovfl(data)                                        ((0x00020000&(data))>>17)
#define GDMA_DMA_INTST_3D_wdma_udfl_shift                                            (16)
#define GDMA_DMA_INTST_3D_wdma_udfl_mask                                             (0x00010000)
#define GDMA_DMA_INTST_3D_wdma_udfl(data)                                            (0x00010000&((data)<<16))
#define GDMA_DMA_INTST_3D_wdma_udfl_src(data)                                        ((0x00010000&(data))>>16)
#define GDMA_DMA_INTST_3D_get_wdma_udfl(data)                                        ((0x00010000&(data))>>16)
#define GDMA_DMA_INTST_3D_osd6_acc_sync_shift                                        (14)
#define GDMA_DMA_INTST_3D_osd6_acc_sync_mask                                         (0x00004000)
#define GDMA_DMA_INTST_3D_osd6_acc_sync(data)                                        (0x00004000&((data)<<14))
#define GDMA_DMA_INTST_3D_osd6_acc_sync_src(data)                                    ((0x00004000&(data))>>14)
#define GDMA_DMA_INTST_3D_get_osd6_acc_sync(data)                                    ((0x00004000&(data))>>14)
#define GDMA_DMA_INTST_3D_osd5_acc_sync_shift                                        (13)
#define GDMA_DMA_INTST_3D_osd5_acc_sync_mask                                         (0x00002000)
#define GDMA_DMA_INTST_3D_osd5_acc_sync(data)                                        (0x00002000&((data)<<13))
#define GDMA_DMA_INTST_3D_osd5_acc_sync_src(data)                                    ((0x00002000&(data))>>13)
#define GDMA_DMA_INTST_3D_get_osd5_acc_sync(data)                                    ((0x00002000&(data))>>13)
#define GDMA_DMA_INTST_3D_osd4_acc_sync_shift                                        (12)
#define GDMA_DMA_INTST_3D_osd4_acc_sync_mask                                         (0x00001000)
#define GDMA_DMA_INTST_3D_osd4_acc_sync(data)                                        (0x00001000&((data)<<12))
#define GDMA_DMA_INTST_3D_osd4_acc_sync_src(data)                                    ((0x00001000&(data))>>12)
#define GDMA_DMA_INTST_3D_get_osd4_acc_sync(data)                                    ((0x00001000&(data))>>12)
#define GDMA_DMA_INTST_3D_osd3_acc_sync_shift                                        (11)
#define GDMA_DMA_INTST_3D_osd3_acc_sync_mask                                         (0x00000800)
#define GDMA_DMA_INTST_3D_osd3_acc_sync(data)                                        (0x00000800&((data)<<11))
#define GDMA_DMA_INTST_3D_osd3_acc_sync_src(data)                                    ((0x00000800&(data))>>11)
#define GDMA_DMA_INTST_3D_get_osd3_acc_sync(data)                                    ((0x00000800&(data))>>11)
#define GDMA_DMA_INTST_3D_osd2_acc_sync_shift                                        (10)
#define GDMA_DMA_INTST_3D_osd2_acc_sync_mask                                         (0x00000400)
#define GDMA_DMA_INTST_3D_osd2_acc_sync(data)                                        (0x00000400&((data)<<10))
#define GDMA_DMA_INTST_3D_osd2_acc_sync_src(data)                                    ((0x00000400&(data))>>10)
#define GDMA_DMA_INTST_3D_get_osd2_acc_sync(data)                                    ((0x00000400&(data))>>10)
#define GDMA_DMA_INTST_3D_osd1_acc_sync_shift                                        (9)
#define GDMA_DMA_INTST_3D_osd1_acc_sync_mask                                         (0x00000200)
#define GDMA_DMA_INTST_3D_osd1_acc_sync(data)                                        (0x00000200&((data)<<9))
#define GDMA_DMA_INTST_3D_osd1_acc_sync_src(data)                                    ((0x00000200&(data))>>9)
#define GDMA_DMA_INTST_3D_get_osd1_acc_sync(data)                                    ((0x00000200&(data))>>9)
#define GDMA_DMA_INTST_3D_osd6_udfl_shift                                            (6)
#define GDMA_DMA_INTST_3D_osd6_udfl_mask                                             (0x00000040)
#define GDMA_DMA_INTST_3D_osd6_udfl(data)                                            (0x00000040&((data)<<6))
#define GDMA_DMA_INTST_3D_osd6_udfl_src(data)                                        ((0x00000040&(data))>>6)
#define GDMA_DMA_INTST_3D_get_osd6_udfl(data)                                        ((0x00000040&(data))>>6)
#define GDMA_DMA_INTST_3D_osd5_udfl_shift                                            (5)
#define GDMA_DMA_INTST_3D_osd5_udfl_mask                                             (0x00000020)
#define GDMA_DMA_INTST_3D_osd5_udfl(data)                                            (0x00000020&((data)<<5))
#define GDMA_DMA_INTST_3D_osd5_udfl_src(data)                                        ((0x00000020&(data))>>5)
#define GDMA_DMA_INTST_3D_get_osd5_udfl(data)                                        ((0x00000020&(data))>>5)
#define GDMA_DMA_INTST_3D_osd4_udfl_shift                                            (4)
#define GDMA_DMA_INTST_3D_osd4_udfl_mask                                             (0x00000010)
#define GDMA_DMA_INTST_3D_osd4_udfl(data)                                            (0x00000010&((data)<<4))
#define GDMA_DMA_INTST_3D_osd4_udfl_src(data)                                        ((0x00000010&(data))>>4)
#define GDMA_DMA_INTST_3D_get_osd4_udfl(data)                                        ((0x00000010&(data))>>4)
#define GDMA_DMA_INTST_3D_osd3_udfl_shift                                            (3)
#define GDMA_DMA_INTST_3D_osd3_udfl_mask                                             (0x00000008)
#define GDMA_DMA_INTST_3D_osd3_udfl(data)                                            (0x00000008&((data)<<3))
#define GDMA_DMA_INTST_3D_osd3_udfl_src(data)                                        ((0x00000008&(data))>>3)
#define GDMA_DMA_INTST_3D_get_osd3_udfl(data)                                        ((0x00000008&(data))>>3)
#define GDMA_DMA_INTST_3D_osd2_udfl_shift                                            (2)
#define GDMA_DMA_INTST_3D_osd2_udfl_mask                                             (0x00000004)
#define GDMA_DMA_INTST_3D_osd2_udfl(data)                                            (0x00000004&((data)<<2))
#define GDMA_DMA_INTST_3D_osd2_udfl_src(data)                                        ((0x00000004&(data))>>2)
#define GDMA_DMA_INTST_3D_get_osd2_udfl(data)                                        ((0x00000004&(data))>>2)
#define GDMA_DMA_INTST_3D_osd1_udfl_shift                                            (1)
#define GDMA_DMA_INTST_3D_osd1_udfl_mask                                             (0x00000002)
#define GDMA_DMA_INTST_3D_osd1_udfl(data)                                            (0x00000002&((data)<<1))
#define GDMA_DMA_INTST_3D_osd1_udfl_src(data)                                        ((0x00000002&(data))>>1)
#define GDMA_DMA_INTST_3D_get_osd1_udfl(data)                                        ((0x00000002&(data))>>1)
#define GDMA_DMA_INTST_3D_write_data_shift                                           (0)
#define GDMA_DMA_INTST_3D_write_data_mask                                            (0x00000001)
#define GDMA_DMA_INTST_3D_write_data(data)                                           (0x00000001&((data)<<0))
#define GDMA_DMA_INTST_3D_write_data_src(data)                                       ((0x00000001&(data))>>0)
#define GDMA_DMA_INTST_3D_get_write_data(data)                                       ((0x00000001&(data))>>0)


#define GDMA_MBIST                                                                   0x1802fdc0
#define GDMA_MBIST_reg_addr                                                          "0xB802FDC0"
#define GDMA_MBIST_reg                                                               0xB802FDC0
#define set_GDMA_MBIST_reg(data)   (*((volatile unsigned int*) GDMA_MBIST_reg)=data)
#define get_GDMA_MBIST_reg   (*((volatile unsigned int*) GDMA_MBIST_reg))
#define GDMA_MBIST_inst_adr                                                          "0x0070"
#define GDMA_MBIST_inst                                                              0x0070
#define GDMA_MBIST_test_rwm_shift                                                    (24)
#define GDMA_MBIST_test_rwm_mask                                                     (0x01000000)
#define GDMA_MBIST_test_rwm(data)                                                    (0x01000000&((data)<<24))
#define GDMA_MBIST_test_rwm_src(data)                                                ((0x01000000&(data))>>24)
#define GDMA_MBIST_get_test_rwm(data)                                                ((0x01000000&(data))>>24)
#define GDMA_MBIST_fbdc_dma_ls_shift                                                 (19)
#define GDMA_MBIST_fbdc_dma_ls_mask                                                  (0x00080000)
#define GDMA_MBIST_fbdc_dma_ls(data)                                                 (0x00080000&((data)<<19))
#define GDMA_MBIST_fbdc_dma_ls_src(data)                                             ((0x00080000&(data))>>19)
#define GDMA_MBIST_get_fbdc_dma_ls(data)                                             ((0x00080000&(data))>>19)
#define GDMA_MBIST_fbdc_data_ls_shift                                                (18)
#define GDMA_MBIST_fbdc_data_ls_mask                                                 (0x00040000)
#define GDMA_MBIST_fbdc_data_ls(data)                                                (0x00040000&((data)<<18))
#define GDMA_MBIST_fbdc_data_ls_src(data)                                            ((0x00040000&(data))>>18)
#define GDMA_MBIST_get_fbdc_data_ls(data)                                            ((0x00040000&(data))>>18)
#define GDMA_MBIST_fbdc_header_ls_shift                                              (17)
#define GDMA_MBIST_fbdc_header_ls_mask                                               (0x00020000)
#define GDMA_MBIST_fbdc_header_ls(data)                                              (0x00020000&((data)<<17))
#define GDMA_MBIST_fbdc_header_ls_src(data)                                          ((0x00020000&(data))>>17)
#define GDMA_MBIST_get_fbdc_header_ls(data)                                          ((0x00020000&(data))>>17)
#define GDMA_MBIST_fbdc_ls_shift                                                     (16)
#define GDMA_MBIST_fbdc_ls_mask                                                      (0x00010000)
#define GDMA_MBIST_fbdc_ls(data)                                                     (0x00010000&((data)<<16))
#define GDMA_MBIST_fbdc_ls_src(data)                                                 ((0x00010000&(data))>>16)
#define GDMA_MBIST_get_fbdc_ls(data)                                                 ((0x00010000&(data))>>16)
#define GDMA_MBIST_rme_shift                                                         (4)
#define GDMA_MBIST_rme_mask                                                          (0x00000010)
#define GDMA_MBIST_rme(data)                                                         (0x00000010&((data)<<4))
#define GDMA_MBIST_rme_src(data)                                                     ((0x00000010&(data))>>4)
#define GDMA_MBIST_get_rme(data)                                                     ((0x00000010&(data))>>4)
#define GDMA_MBIST_rm_shift                                                          (0)
#define GDMA_MBIST_rm_mask                                                           (0x0000000F)
#define GDMA_MBIST_rm(data)                                                          (0x0000000F&((data)<<0))
#define GDMA_MBIST_rm_src(data)                                                      ((0x0000000F&(data))>>0)
#define GDMA_MBIST_get_rm(data)                                                      ((0x0000000F&(data))>>0)


#define GDMA_MBIST_FAIL                                                              0x1802fdc4
#define GDMA_MBIST_FAIL_reg_addr                                                     "0xB802FDC4"
#define GDMA_MBIST_FAIL_reg                                                          0xB802FDC4
#define set_GDMA_MBIST_FAIL_reg(data)   (*((volatile unsigned int*) GDMA_MBIST_FAIL_reg)=data)
#define get_GDMA_MBIST_FAIL_reg   (*((volatile unsigned int*) GDMA_MBIST_FAIL_reg))
#define GDMA_MBIST_FAIL_inst_adr                                                     "0x0071"
#define GDMA_MBIST_FAIL_inst                                                         0x0071
#define GDMA_MBIST_FAIL_dispbuf_shift                                                (25)
#define GDMA_MBIST_FAIL_dispbuf_mask                                                 (0x7E000000)
#define GDMA_MBIST_FAIL_dispbuf(data)                                                (0x7E000000&((data)<<25))
#define GDMA_MBIST_FAIL_dispbuf_src(data)                                            ((0x7E000000&(data))>>25)
#define GDMA_MBIST_FAIL_get_dispbuf(data)                                            ((0x7E000000&(data))>>25)
#define GDMA_MBIST_FAIL_dma_buf_shift                                                (20)
#define GDMA_MBIST_FAIL_dma_buf_mask                                                 (0x01F00000)
#define GDMA_MBIST_FAIL_dma_buf(data)                                                (0x01F00000&((data)<<20))
#define GDMA_MBIST_FAIL_dma_buf_src(data)                                            ((0x01F00000&(data))>>20)
#define GDMA_MBIST_FAIL_get_dma_buf(data)                                            ((0x01F00000&(data))>>20)
#define GDMA_MBIST_FAIL_osd5_clut_shift                                              (18)
#define GDMA_MBIST_FAIL_osd5_clut_mask                                               (0x000C0000)
#define GDMA_MBIST_FAIL_osd5_clut(data)                                              (0x000C0000&((data)<<18))
#define GDMA_MBIST_FAIL_osd5_clut_src(data)                                          ((0x000C0000&(data))>>18)
#define GDMA_MBIST_FAIL_get_osd5_clut(data)                                          ((0x000C0000&(data))>>18)
#define GDMA_MBIST_FAIL_osd4_clut_shift                                              (16)
#define GDMA_MBIST_FAIL_osd4_clut_mask                                               (0x00030000)
#define GDMA_MBIST_FAIL_osd4_clut(data)                                              (0x00030000&((data)<<16))
#define GDMA_MBIST_FAIL_osd4_clut_src(data)                                          ((0x00030000&(data))>>16)
#define GDMA_MBIST_FAIL_get_osd4_clut(data)                                          ((0x00030000&(data))>>16)
#define GDMA_MBIST_FAIL_osd3_clut_shift                                              (14)
#define GDMA_MBIST_FAIL_osd3_clut_mask                                               (0x0000C000)
#define GDMA_MBIST_FAIL_osd3_clut(data)                                              (0x0000C000&((data)<<14))
#define GDMA_MBIST_FAIL_osd3_clut_src(data)                                          ((0x0000C000&(data))>>14)
#define GDMA_MBIST_FAIL_get_osd3_clut(data)                                          ((0x0000C000&(data))>>14)
#define GDMA_MBIST_FAIL_osd2_clut_shift                                              (12)
#define GDMA_MBIST_FAIL_osd2_clut_mask                                               (0x00003000)
#define GDMA_MBIST_FAIL_osd2_clut(data)                                              (0x00003000&((data)<<12))
#define GDMA_MBIST_FAIL_osd2_clut_src(data)                                          ((0x00003000&(data))>>12)
#define GDMA_MBIST_FAIL_get_osd2_clut(data)                                          ((0x00003000&(data))>>12)
#define GDMA_MBIST_FAIL_osd1_clut_shift                                              (10)
#define GDMA_MBIST_FAIL_osd1_clut_mask                                               (0x00000C00)
#define GDMA_MBIST_FAIL_osd1_clut(data)                                              (0x00000C00&((data)<<10))
#define GDMA_MBIST_FAIL_osd1_clut_src(data)                                          ((0x00000C00&(data))>>10)
#define GDMA_MBIST_FAIL_get_osd1_clut(data)                                          ((0x00000C00&(data))>>10)
#define GDMA_MBIST_FAIL_rbuf_shift                                                   (0)
#define GDMA_MBIST_FAIL_rbuf_mask                                                    (0x000003FF)
#define GDMA_MBIST_FAIL_rbuf(data)                                                   (0x000003FF&((data)<<0))
#define GDMA_MBIST_FAIL_rbuf_src(data)                                               ((0x000003FF&(data))>>0)
#define GDMA_MBIST_FAIL_get_rbuf(data)                                               ((0x000003FF&(data))>>0)


#define GDMA_MBIST_DRF_FAIL                                                          0x1802fdcc
#define GDMA_MBIST_DRF_FAIL_reg_addr                                                 "0xB802FDCC"
#define GDMA_MBIST_DRF_FAIL_reg                                                      0xB802FDCC
#define set_GDMA_MBIST_DRF_FAIL_reg(data)   (*((volatile unsigned int*) GDMA_MBIST_DRF_FAIL_reg)=data)
#define get_GDMA_MBIST_DRF_FAIL_reg   (*((volatile unsigned int*) GDMA_MBIST_DRF_FAIL_reg))
#define GDMA_MBIST_DRF_FAIL_inst_adr                                                 "0x0073"
#define GDMA_MBIST_DRF_FAIL_inst                                                     0x0073
#define GDMA_MBIST_DRF_FAIL_dispbuf_shift                                            (25)
#define GDMA_MBIST_DRF_FAIL_dispbuf_mask                                             (0x7E000000)
#define GDMA_MBIST_DRF_FAIL_dispbuf(data)                                            (0x7E000000&((data)<<25))
#define GDMA_MBIST_DRF_FAIL_dispbuf_src(data)                                        ((0x7E000000&(data))>>25)
#define GDMA_MBIST_DRF_FAIL_get_dispbuf(data)                                        ((0x7E000000&(data))>>25)
#define GDMA_MBIST_DRF_FAIL_dma_buf_shift                                            (20)
#define GDMA_MBIST_DRF_FAIL_dma_buf_mask                                             (0x01F00000)
#define GDMA_MBIST_DRF_FAIL_dma_buf(data)                                            (0x01F00000&((data)<<20))
#define GDMA_MBIST_DRF_FAIL_dma_buf_src(data)                                        ((0x01F00000&(data))>>20)
#define GDMA_MBIST_DRF_FAIL_get_dma_buf(data)                                        ((0x01F00000&(data))>>20)
#define GDMA_MBIST_DRF_FAIL_osd5_clut_shift                                          (18)
#define GDMA_MBIST_DRF_FAIL_osd5_clut_mask                                           (0x000C0000)
#define GDMA_MBIST_DRF_FAIL_osd5_clut(data)                                          (0x000C0000&((data)<<18))
#define GDMA_MBIST_DRF_FAIL_osd5_clut_src(data)                                      ((0x000C0000&(data))>>18)
#define GDMA_MBIST_DRF_FAIL_get_osd5_clut(data)                                      ((0x000C0000&(data))>>18)
#define GDMA_MBIST_DRF_FAIL_osd4_clut_shift                                          (16)
#define GDMA_MBIST_DRF_FAIL_osd4_clut_mask                                           (0x00030000)
#define GDMA_MBIST_DRF_FAIL_osd4_clut(data)                                          (0x00030000&((data)<<16))
#define GDMA_MBIST_DRF_FAIL_osd4_clut_src(data)                                      ((0x00030000&(data))>>16)
#define GDMA_MBIST_DRF_FAIL_get_osd4_clut(data)                                      ((0x00030000&(data))>>16)
#define GDMA_MBIST_DRF_FAIL_osd3_clut_shift                                          (14)
#define GDMA_MBIST_DRF_FAIL_osd3_clut_mask                                           (0x0000C000)
#define GDMA_MBIST_DRF_FAIL_osd3_clut(data)                                          (0x0000C000&((data)<<14))
#define GDMA_MBIST_DRF_FAIL_osd3_clut_src(data)                                      ((0x0000C000&(data))>>14)
#define GDMA_MBIST_DRF_FAIL_get_osd3_clut(data)                                      ((0x0000C000&(data))>>14)
#define GDMA_MBIST_DRF_FAIL_osd2_clut_shift                                          (12)
#define GDMA_MBIST_DRF_FAIL_osd2_clut_mask                                           (0x00003000)
#define GDMA_MBIST_DRF_FAIL_osd2_clut(data)                                          (0x00003000&((data)<<12))
#define GDMA_MBIST_DRF_FAIL_osd2_clut_src(data)                                      ((0x00003000&(data))>>12)
#define GDMA_MBIST_DRF_FAIL_get_osd2_clut(data)                                      ((0x00003000&(data))>>12)
#define GDMA_MBIST_DRF_FAIL_osd1_clut_shift                                          (10)
#define GDMA_MBIST_DRF_FAIL_osd1_clut_mask                                           (0x00000C00)
#define GDMA_MBIST_DRF_FAIL_osd1_clut(data)                                          (0x00000C00&((data)<<10))
#define GDMA_MBIST_DRF_FAIL_osd1_clut_src(data)                                      ((0x00000C00&(data))>>10)
#define GDMA_MBIST_DRF_FAIL_get_osd1_clut(data)                                      ((0x00000C00&(data))>>10)
#define GDMA_MBIST_DRF_FAIL_rbuf_shift                                               (0)
#define GDMA_MBIST_DRF_FAIL_rbuf_mask                                                (0x000003FF)
#define GDMA_MBIST_DRF_FAIL_rbuf(data)                                               (0x000003FF&((data)<<0))
#define GDMA_MBIST_DRF_FAIL_rbuf_src(data)                                           ((0x000003FF&(data))>>0)
#define GDMA_MBIST_DRF_FAIL_get_rbuf(data)                                           ((0x000003FF&(data))>>0)


#define GDMA_MBIST_FAIL2                                                             0x1802fdc8
#define GDMA_MBIST_FAIL2_reg_addr                                                    "0xB802FDC8"
#define GDMA_MBIST_FAIL2_reg                                                         0xB802FDC8
#define set_GDMA_MBIST_FAIL2_reg(data)   (*((volatile unsigned int*) GDMA_MBIST_FAIL2_reg)=data)
#define get_GDMA_MBIST_FAIL2_reg   (*((volatile unsigned int*) GDMA_MBIST_FAIL2_reg))
#define GDMA_MBIST_FAIL2_inst_adr                                                    "0x0072"
#define GDMA_MBIST_FAIL2_inst                                                        0x0072
#define GDMA_MBIST_FAIL2_fbdc_dma_shift                                              (9)
#define GDMA_MBIST_FAIL2_fbdc_dma_mask                                               (0x00001E00)
#define GDMA_MBIST_FAIL2_fbdc_dma(data)                                              (0x00001E00&((data)<<9))
#define GDMA_MBIST_FAIL2_fbdc_dma_src(data)                                          ((0x00001E00&(data))>>9)
#define GDMA_MBIST_FAIL2_get_fbdc_dma(data)                                          ((0x00001E00&(data))>>9)
#define GDMA_MBIST_FAIL2_fbdc_data1_shift                                            (7)
#define GDMA_MBIST_FAIL2_fbdc_data1_mask                                             (0x00000180)
#define GDMA_MBIST_FAIL2_fbdc_data1(data)                                            (0x00000180&((data)<<7))
#define GDMA_MBIST_FAIL2_fbdc_data1_src(data)                                        ((0x00000180&(data))>>7)
#define GDMA_MBIST_FAIL2_get_fbdc_data1(data)                                        ((0x00000180&(data))>>7)
#define GDMA_MBIST_FAIL2_fbdc_data0_shift                                            (5)
#define GDMA_MBIST_FAIL2_fbdc_data0_mask                                             (0x00000060)
#define GDMA_MBIST_FAIL2_fbdc_data0(data)                                            (0x00000060&((data)<<5))
#define GDMA_MBIST_FAIL2_fbdc_data0_src(data)                                        ((0x00000060&(data))>>5)
#define GDMA_MBIST_FAIL2_get_fbdc_data0(data)                                        ((0x00000060&(data))>>5)
#define GDMA_MBIST_FAIL2_fbdc_header_shift                                           (4)
#define GDMA_MBIST_FAIL2_fbdc_header_mask                                            (0x00000010)
#define GDMA_MBIST_FAIL2_fbdc_header(data)                                           (0x00000010&((data)<<4))
#define GDMA_MBIST_FAIL2_fbdc_header_src(data)                                       ((0x00000010&(data))>>4)
#define GDMA_MBIST_FAIL2_get_fbdc_header(data)                                       ((0x00000010&(data))>>4)
#define GDMA_MBIST_FAIL2_wdma_shift                                                  (3)
#define GDMA_MBIST_FAIL2_wdma_mask                                                   (0x00000008)
#define GDMA_MBIST_FAIL2_wdma(data)                                                  (0x00000008&((data)<<3))
#define GDMA_MBIST_FAIL2_wdma_src(data)                                              ((0x00000008&(data))>>3)
#define GDMA_MBIST_FAIL2_get_wdma(data)                                              ((0x00000008&(data))>>3)
#define GDMA_MBIST_FAIL2_comp_shift                                                  (2)
#define GDMA_MBIST_FAIL2_comp_mask                                                   (0x00000004)
#define GDMA_MBIST_FAIL2_comp(data)                                                  (0x00000004&((data)<<2))
#define GDMA_MBIST_FAIL2_comp_src(data)                                              ((0x00000004&(data))>>2)
#define GDMA_MBIST_FAIL2_get_comp(data)                                              ((0x00000004&(data))>>2)
#define GDMA_MBIST_FAIL2_decomp2_shift                                               (1)
#define GDMA_MBIST_FAIL2_decomp2_mask                                                (0x00000002)
#define GDMA_MBIST_FAIL2_decomp2(data)                                               (0x00000002&((data)<<1))
#define GDMA_MBIST_FAIL2_decomp2_src(data)                                           ((0x00000002&(data))>>1)
#define GDMA_MBIST_FAIL2_get_decomp2(data)                                           ((0x00000002&(data))>>1)
#define GDMA_MBIST_FAIL2_decomp1_shift                                               (0)
#define GDMA_MBIST_FAIL2_decomp1_mask                                                (0x00000001)
#define GDMA_MBIST_FAIL2_decomp1(data)                                               (0x00000001&((data)<<0))
#define GDMA_MBIST_FAIL2_decomp1_src(data)                                           ((0x00000001&(data))>>0)
#define GDMA_MBIST_FAIL2_get_decomp1(data)                                           ((0x00000001&(data))>>0)


#define GDMA_MBIST_DRF_FAIL2                                                         0x1802fdd0
#define GDMA_MBIST_DRF_FAIL2_reg_addr                                                "0xB802FDD0"
#define GDMA_MBIST_DRF_FAIL2_reg                                                     0xB802FDD0
#define set_GDMA_MBIST_DRF_FAIL2_reg(data)   (*((volatile unsigned int*) GDMA_MBIST_DRF_FAIL2_reg)=data)
#define get_GDMA_MBIST_DRF_FAIL2_reg   (*((volatile unsigned int*) GDMA_MBIST_DRF_FAIL2_reg))
#define GDMA_MBIST_DRF_FAIL2_inst_adr                                                "0x0074"
#define GDMA_MBIST_DRF_FAIL2_inst                                                    0x0074
#define GDMA_MBIST_DRF_FAIL2_fbdc_dma_shift                                          (9)
#define GDMA_MBIST_DRF_FAIL2_fbdc_dma_mask                                           (0x00001E00)
#define GDMA_MBIST_DRF_FAIL2_fbdc_dma(data)                                          (0x00001E00&((data)<<9))
#define GDMA_MBIST_DRF_FAIL2_fbdc_dma_src(data)                                      ((0x00001E00&(data))>>9)
#define GDMA_MBIST_DRF_FAIL2_get_fbdc_dma(data)                                      ((0x00001E00&(data))>>9)
#define GDMA_MBIST_DRF_FAIL2_fbdc_data1_shift                                        (7)
#define GDMA_MBIST_DRF_FAIL2_fbdc_data1_mask                                         (0x00000180)
#define GDMA_MBIST_DRF_FAIL2_fbdc_data1(data)                                        (0x00000180&((data)<<7))
#define GDMA_MBIST_DRF_FAIL2_fbdc_data1_src(data)                                    ((0x00000180&(data))>>7)
#define GDMA_MBIST_DRF_FAIL2_get_fbdc_data1(data)                                    ((0x00000180&(data))>>7)
#define GDMA_MBIST_DRF_FAIL2_fbdc_data0_shift                                        (5)
#define GDMA_MBIST_DRF_FAIL2_fbdc_data0_mask                                         (0x00000060)
#define GDMA_MBIST_DRF_FAIL2_fbdc_data0(data)                                        (0x00000060&((data)<<5))
#define GDMA_MBIST_DRF_FAIL2_fbdc_data0_src(data)                                    ((0x00000060&(data))>>5)
#define GDMA_MBIST_DRF_FAIL2_get_fbdc_data0(data)                                    ((0x00000060&(data))>>5)
#define GDMA_MBIST_DRF_FAIL2_fbdc_header_shift                                       (4)
#define GDMA_MBIST_DRF_FAIL2_fbdc_header_mask                                        (0x00000010)
#define GDMA_MBIST_DRF_FAIL2_fbdc_header(data)                                       (0x00000010&((data)<<4))
#define GDMA_MBIST_DRF_FAIL2_fbdc_header_src(data)                                   ((0x00000010&(data))>>4)
#define GDMA_MBIST_DRF_FAIL2_get_fbdc_header(data)                                   ((0x00000010&(data))>>4)
#define GDMA_MBIST_DRF_FAIL2_wdma_shift                                              (3)
#define GDMA_MBIST_DRF_FAIL2_wdma_mask                                               (0x00000008)
#define GDMA_MBIST_DRF_FAIL2_wdma(data)                                              (0x00000008&((data)<<3))
#define GDMA_MBIST_DRF_FAIL2_wdma_src(data)                                          ((0x00000008&(data))>>3)
#define GDMA_MBIST_DRF_FAIL2_get_wdma(data)                                          ((0x00000008&(data))>>3)
#define GDMA_MBIST_DRF_FAIL2_comp_shift                                              (2)
#define GDMA_MBIST_DRF_FAIL2_comp_mask                                               (0x00000004)
#define GDMA_MBIST_DRF_FAIL2_comp(data)                                              (0x00000004&((data)<<2))
#define GDMA_MBIST_DRF_FAIL2_comp_src(data)                                          ((0x00000004&(data))>>2)
#define GDMA_MBIST_DRF_FAIL2_get_comp(data)                                          ((0x00000004&(data))>>2)
#define GDMA_MBIST_DRF_FAIL2_decomp2_shift                                           (1)
#define GDMA_MBIST_DRF_FAIL2_decomp2_mask                                            (0x00000002)
#define GDMA_MBIST_DRF_FAIL2_decomp2(data)                                           (0x00000002&((data)<<1))
#define GDMA_MBIST_DRF_FAIL2_decomp2_src(data)                                       ((0x00000002&(data))>>1)
#define GDMA_MBIST_DRF_FAIL2_get_decomp2(data)                                       ((0x00000002&(data))>>1)
#define GDMA_MBIST_DRF_FAIL2_decomp1_shift                                           (0)
#define GDMA_MBIST_DRF_FAIL2_decomp1_mask                                            (0x00000001)
#define GDMA_MBIST_DRF_FAIL2_decomp1(data)                                           (0x00000001&((data)<<0))
#define GDMA_MBIST_DRF_FAIL2_decomp1_src(data)                                       ((0x00000001&(data))>>0)
#define GDMA_MBIST_DRF_FAIL2_get_decomp1(data)                                       ((0x00000001&(data))>>0)


#define GDMA_MBISR_FAIL                                                              0x1802fdd4
#define GDMA_MBISR_FAIL_reg_addr                                                     "0xB802FDD4"
#define GDMA_MBISR_FAIL_reg                                                          0xB802FDD4
#define set_GDMA_MBISR_FAIL_reg(data)   (*((volatile unsigned int*) GDMA_MBISR_FAIL_reg)=data)
#define get_GDMA_MBISR_FAIL_reg   (*((volatile unsigned int*) GDMA_MBISR_FAIL_reg))
#define GDMA_MBISR_FAIL_inst_adr                                                     "0x0075"
#define GDMA_MBISR_FAIL_inst                                                         0x0075
#define GDMA_MBISR_FAIL_fbdc_003_shift                                               (21)
#define GDMA_MBISR_FAIL_fbdc_003_mask                                                (0x0FE00000)
#define GDMA_MBISR_FAIL_fbdc_003(data)                                               (0x0FE00000&((data)<<21))
#define GDMA_MBISR_FAIL_fbdc_003_src(data)                                           ((0x0FE00000&(data))>>21)
#define GDMA_MBISR_FAIL_get_fbdc_003(data)                                           ((0x0FE00000&(data))>>21)
#define GDMA_MBISR_FAIL_fbdc_002_shift                                               (14)
#define GDMA_MBISR_FAIL_fbdc_002_mask                                                (0x001FC000)
#define GDMA_MBISR_FAIL_fbdc_002(data)                                               (0x001FC000&((data)<<14))
#define GDMA_MBISR_FAIL_fbdc_002_src(data)                                           ((0x001FC000&(data))>>14)
#define GDMA_MBISR_FAIL_get_fbdc_002(data)                                           ((0x001FC000&(data))>>14)
#define GDMA_MBISR_FAIL_fbdc_001_shift                                               (7)
#define GDMA_MBISR_FAIL_fbdc_001_mask                                                (0x00003F80)
#define GDMA_MBISR_FAIL_fbdc_001(data)                                               (0x00003F80&((data)<<7))
#define GDMA_MBISR_FAIL_fbdc_001_src(data)                                           ((0x00003F80&(data))>>7)
#define GDMA_MBISR_FAIL_get_fbdc_001(data)                                           ((0x00003F80&(data))>>7)
#define GDMA_MBISR_FAIL_fbdc_000_shift                                               (0)
#define GDMA_MBISR_FAIL_fbdc_000_mask                                                (0x0000007F)
#define GDMA_MBISR_FAIL_fbdc_000(data)                                               (0x0000007F&((data)<<0))
#define GDMA_MBISR_FAIL_fbdc_000_src(data)                                           ((0x0000007F&(data))>>0)
#define GDMA_MBISR_FAIL_get_fbdc_000(data)                                           ((0x0000007F&(data))>>0)


#define GDMA_MBISR_DRF_FAIL                                                          0x1802fdd8
#define GDMA_MBISR_DRF_FAIL_reg_addr                                                 "0xB802FDD8"
#define GDMA_MBISR_DRF_FAIL_reg                                                      0xB802FDD8
#define set_GDMA_MBISR_DRF_FAIL_reg(data)   (*((volatile unsigned int*) GDMA_MBISR_DRF_FAIL_reg)=data)
#define get_GDMA_MBISR_DRF_FAIL_reg   (*((volatile unsigned int*) GDMA_MBISR_DRF_FAIL_reg))
#define GDMA_MBISR_DRF_FAIL_inst_adr                                                 "0x0076"
#define GDMA_MBISR_DRF_FAIL_inst                                                     0x0076
#define GDMA_MBISR_DRF_FAIL_fbdc_003_shift                                           (21)
#define GDMA_MBISR_DRF_FAIL_fbdc_003_mask                                            (0x0FE00000)
#define GDMA_MBISR_DRF_FAIL_fbdc_003(data)                                           (0x0FE00000&((data)<<21))
#define GDMA_MBISR_DRF_FAIL_fbdc_003_src(data)                                       ((0x0FE00000&(data))>>21)
#define GDMA_MBISR_DRF_FAIL_get_fbdc_003(data)                                       ((0x0FE00000&(data))>>21)
#define GDMA_MBISR_DRF_FAIL_fbdc_002_shift                                           (14)
#define GDMA_MBISR_DRF_FAIL_fbdc_002_mask                                            (0x001FC000)
#define GDMA_MBISR_DRF_FAIL_fbdc_002(data)                                           (0x001FC000&((data)<<14))
#define GDMA_MBISR_DRF_FAIL_fbdc_002_src(data)                                       ((0x001FC000&(data))>>14)
#define GDMA_MBISR_DRF_FAIL_get_fbdc_002(data)                                       ((0x001FC000&(data))>>14)
#define GDMA_MBISR_DRF_FAIL_fbdc_001_shift                                           (7)
#define GDMA_MBISR_DRF_FAIL_fbdc_001_mask                                            (0x00003F80)
#define GDMA_MBISR_DRF_FAIL_fbdc_001(data)                                           (0x00003F80&((data)<<7))
#define GDMA_MBISR_DRF_FAIL_fbdc_001_src(data)                                       ((0x00003F80&(data))>>7)
#define GDMA_MBISR_DRF_FAIL_get_fbdc_001(data)                                       ((0x00003F80&(data))>>7)
#define GDMA_MBISR_DRF_FAIL_fbdc_000_shift                                           (0)
#define GDMA_MBISR_DRF_FAIL_fbdc_000_mask                                            (0x0000007F)
#define GDMA_MBISR_DRF_FAIL_fbdc_000(data)                                           (0x0000007F&((data)<<0))
#define GDMA_MBISR_DRF_FAIL_fbdc_000_src(data)                                       ((0x0000007F&(data))>>0)
#define GDMA_MBISR_DRF_FAIL_get_fbdc_000(data)                                       ((0x0000007F&(data))>>0)


#define GDMA_MBISR_REPAIRED                                                          0x1802fddc
#define GDMA_MBISR_REPAIRED_reg_addr                                                 "0xB802FDDC"
#define GDMA_MBISR_REPAIRED_reg                                                      0xB802FDDC
#define set_GDMA_MBISR_REPAIRED_reg(data)   (*((volatile unsigned int*) GDMA_MBISR_REPAIRED_reg)=data)
#define get_GDMA_MBISR_REPAIRED_reg   (*((volatile unsigned int*) GDMA_MBISR_REPAIRED_reg))
#define GDMA_MBISR_REPAIRED_inst_adr                                                 "0x0077"
#define GDMA_MBISR_REPAIRED_inst                                                     0x0077
#define GDMA_MBISR_REPAIRED_fbdc_003_shift                                           (3)
#define GDMA_MBISR_REPAIRED_fbdc_003_mask                                            (0x00000008)
#define GDMA_MBISR_REPAIRED_fbdc_003(data)                                           (0x00000008&((data)<<3))
#define GDMA_MBISR_REPAIRED_fbdc_003_src(data)                                       ((0x00000008&(data))>>3)
#define GDMA_MBISR_REPAIRED_get_fbdc_003(data)                                       ((0x00000008&(data))>>3)
#define GDMA_MBISR_REPAIRED_fbdc_002_shift                                           (2)
#define GDMA_MBISR_REPAIRED_fbdc_002_mask                                            (0x00000004)
#define GDMA_MBISR_REPAIRED_fbdc_002(data)                                           (0x00000004&((data)<<2))
#define GDMA_MBISR_REPAIRED_fbdc_002_src(data)                                       ((0x00000004&(data))>>2)
#define GDMA_MBISR_REPAIRED_get_fbdc_002(data)                                       ((0x00000004&(data))>>2)
#define GDMA_MBISR_REPAIRED_fbdc_001_shift                                           (1)
#define GDMA_MBISR_REPAIRED_fbdc_001_mask                                            (0x00000002)
#define GDMA_MBISR_REPAIRED_fbdc_001(data)                                           (0x00000002&((data)<<1))
#define GDMA_MBISR_REPAIRED_fbdc_001_src(data)                                       ((0x00000002&(data))>>1)
#define GDMA_MBISR_REPAIRED_get_fbdc_001(data)                                       ((0x00000002&(data))>>1)
#define GDMA_MBISR_REPAIRED_fbdc_000_shift                                           (0)
#define GDMA_MBISR_REPAIRED_fbdc_000_mask                                            (0x00000001)
#define GDMA_MBISR_REPAIRED_fbdc_000(data)                                           (0x00000001&((data)<<0))
#define GDMA_MBISR_REPAIRED_fbdc_000_src(data)                                       ((0x00000001&(data))>>0)
#define GDMA_MBISR_REPAIRED_get_fbdc_000(data)                                       ((0x00000001&(data))>>0)


#define GDMA_DBG                                                                     0x1802fd00
#define GDMA_DBG_reg_addr                                                            "0xB802FD00"
#define GDMA_DBG_reg                                                                 0xB802FD00
#define set_GDMA_DBG_reg(data)   (*((volatile unsigned int*) GDMA_DBG_reg)=data)
#define get_GDMA_DBG_reg   (*((volatile unsigned int*) GDMA_DBG_reg))
#define GDMA_DBG_inst_adr                                                            "0x0040"
#define GDMA_DBG_inst                                                                0x0040
#define GDMA_DBG_write_en3_shift                                                     (25)
#define GDMA_DBG_write_en3_mask                                                      (0x02000000)
#define GDMA_DBG_write_en3(data)                                                     (0x02000000&((data)<<25))
#define GDMA_DBG_write_en3_src(data)                                                 ((0x02000000&(data))>>25)
#define GDMA_DBG_get_write_en3(data)                                                 ((0x02000000&(data))>>25)
#define GDMA_DBG_sel1_shift                                                          (16)
#define GDMA_DBG_sel1_mask                                                           (0x01FF0000)
#define GDMA_DBG_sel1(data)                                                          (0x01FF0000&((data)<<16))
#define GDMA_DBG_sel1_src(data)                                                      ((0x01FF0000&(data))>>16)
#define GDMA_DBG_get_sel1(data)                                                      ((0x01FF0000&(data))>>16)
#define GDMA_DBG_write_en2_shift                                                     (13)
#define GDMA_DBG_write_en2_mask                                                      (0x00002000)
#define GDMA_DBG_write_en2(data)                                                     (0x00002000&((data)<<13))
#define GDMA_DBG_write_en2_src(data)                                                 ((0x00002000&(data))>>13)
#define GDMA_DBG_get_write_en2(data)                                                 ((0x00002000&(data))>>13)
#define GDMA_DBG_sel0_shift                                                          (4)
#define GDMA_DBG_sel0_mask                                                           (0x00001FF0)
#define GDMA_DBG_sel0(data)                                                          (0x00001FF0&((data)<<4))
#define GDMA_DBG_sel0_src(data)                                                      ((0x00001FF0&(data))>>4)
#define GDMA_DBG_get_sel0(data)                                                      ((0x00001FF0&(data))>>4)
#define GDMA_DBG_write_en1_shift                                                     (1)
#define GDMA_DBG_write_en1_mask                                                      (0x00000002)
#define GDMA_DBG_write_en1(data)                                                     (0x00000002&((data)<<1))
#define GDMA_DBG_write_en1_src(data)                                                 ((0x00000002&(data))>>1)
#define GDMA_DBG_get_write_en1(data)                                                 ((0x00000002&(data))>>1)
#define GDMA_DBG_en_shift                                                            (0)
#define GDMA_DBG_en_mask                                                             (0x00000001)
#define GDMA_DBG_en(data)                                                            (0x00000001&((data)<<0))
#define GDMA_DBG_en_src(data)                                                        ((0x00000001&(data))>>0)
#define GDMA_DBG_get_en(data)                                                        ((0x00000001&(data))>>0)


#define GDMA_DBG_WI_INFO                                                             0x1802fd0c
#define GDMA_DBG_WI_INFO_reg_addr                                                    "0xB802FD0C"
#define GDMA_DBG_WI_INFO_reg                                                         0xB802FD0C
#define set_GDMA_DBG_WI_INFO_reg(data)   (*((volatile unsigned int*) GDMA_DBG_WI_INFO_reg)=data)
#define get_GDMA_DBG_WI_INFO_reg   (*((volatile unsigned int*) GDMA_DBG_WI_INFO_reg))
#define GDMA_DBG_WI_INFO_inst_adr                                                    "0x0043"
#define GDMA_DBG_WI_INFO_inst                                                        0x0043
#define GDMA_DBG_WI_INFO_sel_shift                                                   (0)
#define GDMA_DBG_WI_INFO_sel_mask                                                    (0x00000007)
#define GDMA_DBG_WI_INFO_sel(data)                                                   (0x00000007&((data)<<0))
#define GDMA_DBG_WI_INFO_sel_src(data)                                               ((0x00000007&(data))>>0)
#define GDMA_DBG_WI_INFO_get_sel(data)                                               ((0x00000007&(data))>>0)


#define GDMA_DBG_OSD_WI_0                                                            0x1802fd10
#define GDMA_DBG_OSD_WI_0_reg_addr                                                   "0xB802FD10"
#define GDMA_DBG_OSD_WI_0_reg                                                        0xB802FD10
#define set_GDMA_DBG_OSD_WI_0_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_0_reg)=data)
#define get_GDMA_DBG_OSD_WI_0_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_0_reg))
#define GDMA_DBG_OSD_WI_0_inst_adr                                                   "0x0044"
#define GDMA_DBG_OSD_WI_0_inst                                                       0x0044
#define GDMA_DBG_OSD_WI_0_height_shift                                               (16)
#define GDMA_DBG_OSD_WI_0_height_mask                                                (0xFFFF0000)
#define GDMA_DBG_OSD_WI_0_height(data)                                               (0xFFFF0000&((data)<<16))
#define GDMA_DBG_OSD_WI_0_height_src(data)                                           ((0xFFFF0000&(data))>>16)
#define GDMA_DBG_OSD_WI_0_get_height(data)                                           ((0xFFFF0000&(data))>>16)
#define GDMA_DBG_OSD_WI_0_width_shift                                                (0)
#define GDMA_DBG_OSD_WI_0_width_mask                                                 (0x0000FFFF)
#define GDMA_DBG_OSD_WI_0_width(data)                                                (0x0000FFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_0_width_src(data)                                            ((0x0000FFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_0_get_width(data)                                            ((0x0000FFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_1                                                            0x1802fd14
#define GDMA_DBG_OSD_WI_1_reg_addr                                                   "0xB802FD14"
#define GDMA_DBG_OSD_WI_1_reg                                                        0xB802FD14
#define set_GDMA_DBG_OSD_WI_1_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_1_reg)=data)
#define get_GDMA_DBG_OSD_WI_1_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_1_reg))
#define GDMA_DBG_OSD_WI_1_inst_adr                                                   "0x0045"
#define GDMA_DBG_OSD_WI_1_inst                                                       0x0045
#define GDMA_DBG_OSD_WI_1_extension_mode_shift                                       (31)
#define GDMA_DBG_OSD_WI_1_extension_mode_mask                                        (0x80000000)
#define GDMA_DBG_OSD_WI_1_extension_mode(data)                                       (0x80000000&((data)<<31))
#define GDMA_DBG_OSD_WI_1_extension_mode_src(data)                                   ((0x80000000&(data))>>31)
#define GDMA_DBG_OSD_WI_1_get_extension_mode(data)                                   ((0x80000000&(data))>>31)
#define GDMA_DBG_OSD_WI_1_rgb_order_shift                                            (28)
#define GDMA_DBG_OSD_WI_1_rgb_order_mask                                             (0x70000000)
#define GDMA_DBG_OSD_WI_1_rgb_order(data)                                            (0x70000000&((data)<<28))
#define GDMA_DBG_OSD_WI_1_rgb_order_src(data)                                        ((0x70000000&(data))>>28)
#define GDMA_DBG_OSD_WI_1_get_rgb_order(data)                                        ((0x70000000&(data))>>28)
#define GDMA_DBG_OSD_WI_1_alpha_replace_type_shift                                   (27)
#define GDMA_DBG_OSD_WI_1_alpha_replace_type_mask                                    (0x08000000)
#define GDMA_DBG_OSD_WI_1_alpha_replace_type(data)                                   (0x08000000&((data)<<27))
#define GDMA_DBG_OSD_WI_1_alpha_replace_type_src(data)                               ((0x08000000&(data))>>27)
#define GDMA_DBG_OSD_WI_1_get_alpha_replace_type(data)                               ((0x08000000&(data))>>27)
#define GDMA_DBG_OSD_WI_1_const_alpha_enable_shift                                   (26)
#define GDMA_DBG_OSD_WI_1_const_alpha_enable_mask                                    (0x04000000)
#define GDMA_DBG_OSD_WI_1_const_alpha_enable(data)                                   (0x04000000&((data)<<26))
#define GDMA_DBG_OSD_WI_1_const_alpha_enable_src(data)                               ((0x04000000&(data))>>26)
#define GDMA_DBG_OSD_WI_1_get_const_alpha_enable(data)                               ((0x04000000&(data))>>26)
#define GDMA_DBG_OSD_WI_1_object_type_shift                                          (24)
#define GDMA_DBG_OSD_WI_1_object_type_mask                                           (0x01000000)
#define GDMA_DBG_OSD_WI_1_object_type(data)                                          (0x01000000&((data)<<24))
#define GDMA_DBG_OSD_WI_1_object_type_src(data)                                      ((0x01000000&(data))>>24)
#define GDMA_DBG_OSD_WI_1_get_object_type(data)                                      ((0x01000000&(data))>>24)
#define GDMA_DBG_OSD_WI_1_alpha_shift                                                (16)
#define GDMA_DBG_OSD_WI_1_alpha_mask                                                 (0x00FF0000)
#define GDMA_DBG_OSD_WI_1_alpha(data)                                                (0x00FF0000&((data)<<16))
#define GDMA_DBG_OSD_WI_1_alpha_src(data)                                            ((0x00FF0000&(data))>>16)
#define GDMA_DBG_OSD_WI_1_get_alpha(data)                                            ((0x00FF0000&(data))>>16)
#define GDMA_DBG_OSD_WI_1_clut_format_shift                                          (10)
#define GDMA_DBG_OSD_WI_1_clut_format_mask                                           (0x00000400)
#define GDMA_DBG_OSD_WI_1_clut_format(data)                                          (0x00000400&((data)<<10))
#define GDMA_DBG_OSD_WI_1_clut_format_src(data)                                      ((0x00000400&(data))>>10)
#define GDMA_DBG_OSD_WI_1_get_clut_format(data)                                      ((0x00000400&(data))>>10)
#define GDMA_DBG_OSD_WI_1_endian_shift                                               (9)
#define GDMA_DBG_OSD_WI_1_endian_mask                                                (0x00000200)
#define GDMA_DBG_OSD_WI_1_endian(data)                                               (0x00000200&((data)<<9))
#define GDMA_DBG_OSD_WI_1_endian_src(data)                                           ((0x00000200&(data))>>9)
#define GDMA_DBG_OSD_WI_1_get_endian(data)                                           ((0x00000200&(data))>>9)
#define GDMA_DBG_OSD_WI_1_keep_prev_clut_shift                                       (8)
#define GDMA_DBG_OSD_WI_1_keep_prev_clut_mask                                        (0x00000100)
#define GDMA_DBG_OSD_WI_1_keep_prev_clut(data)                                       (0x00000100&((data)<<8))
#define GDMA_DBG_OSD_WI_1_keep_prev_clut_src(data)                                   ((0x00000100&(data))>>8)
#define GDMA_DBG_OSD_WI_1_get_keep_prev_clut(data)                                   ((0x00000100&(data))>>8)
#define GDMA_DBG_OSD_WI_1_compress_shift                                             (7)
#define GDMA_DBG_OSD_WI_1_compress_mask                                              (0x00000080)
#define GDMA_DBG_OSD_WI_1_compress(data)                                             (0x00000080&((data)<<7))
#define GDMA_DBG_OSD_WI_1_compress_src(data)                                         ((0x00000080&(data))>>7)
#define GDMA_DBG_OSD_WI_1_get_compress(data)                                         ((0x00000080&(data))>>7)
#define GDMA_DBG_OSD_WI_1_IMG_compress_shift                                         (6)
#define GDMA_DBG_OSD_WI_1_IMG_compress_mask                                          (0x00000040)
#define GDMA_DBG_OSD_WI_1_IMG_compress(data)                                         (0x00000040&((data)<<6))
#define GDMA_DBG_OSD_WI_1_IMG_compress_src(data)                                     ((0x00000040&(data))>>6)
#define GDMA_DBG_OSD_WI_1_get_IMG_compress(data)                                     ((0x00000040&(data))>>6)
#define GDMA_DBG_OSD_WI_1_colortype_shift                                            (0)
#define GDMA_DBG_OSD_WI_1_colortype_mask                                             (0x0000001F)
#define GDMA_DBG_OSD_WI_1_colortype(data)                                            (0x0000001F&((data)<<0))
#define GDMA_DBG_OSD_WI_1_colortype_src(data)                                        ((0x0000001F&(data))>>0)
#define GDMA_DBG_OSD_WI_1_get_colortype(data)                                        ((0x0000001F&(data))>>0)


#define GDMA_DBG_OSD_WI_2                                                            0x1802fd18
#define GDMA_DBG_OSD_WI_2_reg_addr                                                   "0xB802FD18"
#define GDMA_DBG_OSD_WI_2_reg                                                        0xB802FD18
#define set_GDMA_DBG_OSD_WI_2_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_2_reg)=data)
#define get_GDMA_DBG_OSD_WI_2_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_2_reg))
#define GDMA_DBG_OSD_WI_2_inst_adr                                                   "0x0046"
#define GDMA_DBG_OSD_WI_2_inst                                                       0x0046
#define GDMA_DBG_OSD_WI_2_top_addr_shift                                             (0)
#define GDMA_DBG_OSD_WI_2_top_addr_mask                                              (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_2_top_addr(data)                                             (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_2_top_addr_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_2_get_top_addr(data)                                         ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_3                                                            0x1802fd1c
#define GDMA_DBG_OSD_WI_3_reg_addr                                                   "0xB802FD1C"
#define GDMA_DBG_OSD_WI_3_reg                                                        0xB802FD1C
#define set_GDMA_DBG_OSD_WI_3_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_3_reg)=data)
#define get_GDMA_DBG_OSD_WI_3_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_3_reg))
#define GDMA_DBG_OSD_WI_3_inst_adr                                                   "0x0047"
#define GDMA_DBG_OSD_WI_3_inst                                                       0x0047
#define GDMA_DBG_OSD_WI_3_bot_addr_shift                                             (0)
#define GDMA_DBG_OSD_WI_3_bot_addr_mask                                              (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_3_bot_addr(data)                                             (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_3_bot_addr_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_3_get_bot_addr(data)                                         ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_4                                                            0x1802fd20
#define GDMA_DBG_OSD_WI_4_reg_addr                                                   "0xB802FD20"
#define GDMA_DBG_OSD_WI_4_reg                                                        0xB802FD20
#define set_GDMA_DBG_OSD_WI_4_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_4_reg)=data)
#define get_GDMA_DBG_OSD_WI_4_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_4_reg))
#define GDMA_DBG_OSD_WI_4_inst_adr                                                   "0x0048"
#define GDMA_DBG_OSD_WI_4_inst                                                       0x0048
#define GDMA_DBG_OSD_WI_4_pitch_or_third_addr_shift                                  (0)
#define GDMA_DBG_OSD_WI_4_pitch_or_third_addr_mask                                   (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_4_pitch_or_third_addr(data)                                  (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_4_pitch_or_third_addr_src(data)                              ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_4_get_pitch_or_third_addr(data)                              ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_5                                                            0x1802fd24
#define GDMA_DBG_OSD_WI_5_reg_addr                                                   "0xB802FD24"
#define GDMA_DBG_OSD_WI_5_reg                                                        0xB802FD24
#define set_GDMA_DBG_OSD_WI_5_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_5_reg)=data)
#define get_GDMA_DBG_OSD_WI_5_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_5_reg))
#define GDMA_DBG_OSD_WI_5_inst_adr                                                   "0x0049"
#define GDMA_DBG_OSD_WI_5_inst                                                       0x0049
#define GDMA_DBG_OSD_WI_5_dbg_win_28_shift                                           (0)
#define GDMA_DBG_OSD_WI_5_dbg_win_28_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_5_dbg_win_28(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_5_dbg_win_28_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_5_get_dbg_win_28(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_6                                                            0x1802fd28
#define GDMA_DBG_OSD_WI_6_reg_addr                                                   "0xB802FD28"
#define GDMA_DBG_OSD_WI_6_reg                                                        0xB802FD28
#define set_GDMA_DBG_OSD_WI_6_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_6_reg)=data)
#define get_GDMA_DBG_OSD_WI_6_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_6_reg))
#define GDMA_DBG_OSD_WI_6_inst_adr                                                   "0x004A"
#define GDMA_DBG_OSD_WI_6_inst                                                       0x004A
#define GDMA_DBG_OSD_WI_6_dbg_win_2c_shift                                           (0)
#define GDMA_DBG_OSD_WI_6_dbg_win_2c_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_6_dbg_win_2c(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_6_dbg_win_2c_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_6_get_dbg_win_2c(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_7                                                            0x1802fd2c
#define GDMA_DBG_OSD_WI_7_reg_addr                                                   "0xB802FD2C"
#define GDMA_DBG_OSD_WI_7_reg                                                        0xB802FD2C
#define set_GDMA_DBG_OSD_WI_7_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_7_reg)=data)
#define get_GDMA_DBG_OSD_WI_7_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_7_reg))
#define GDMA_DBG_OSD_WI_7_inst_adr                                                   "0x004B"
#define GDMA_DBG_OSD_WI_7_inst                                                       0x004B
#define GDMA_DBG_OSD_WI_7_dbg_win_30_shift                                           (0)
#define GDMA_DBG_OSD_WI_7_dbg_win_30_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_7_dbg_win_30(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_7_dbg_win_30_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_7_get_dbg_win_30(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_8                                                            0x1802fd30
#define GDMA_DBG_OSD_WI_8_reg_addr                                                   "0xB802FD30"
#define GDMA_DBG_OSD_WI_8_reg                                                        0xB802FD30
#define set_GDMA_DBG_OSD_WI_8_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_8_reg)=data)
#define get_GDMA_DBG_OSD_WI_8_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_8_reg))
#define GDMA_DBG_OSD_WI_8_inst_adr                                                   "0x004C"
#define GDMA_DBG_OSD_WI_8_inst                                                       0x004C
#define GDMA_DBG_OSD_WI_8_dbg_win_34_shift                                           (0)
#define GDMA_DBG_OSD_WI_8_dbg_win_34_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_8_dbg_win_34(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_8_dbg_win_34_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_8_get_dbg_win_34(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_9                                                            0x1802fd34
#define GDMA_DBG_OSD_WI_9_reg_addr                                                   "0xB802FD34"
#define GDMA_DBG_OSD_WI_9_reg                                                        0xB802FD34
#define set_GDMA_DBG_OSD_WI_9_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_9_reg)=data)
#define get_GDMA_DBG_OSD_WI_9_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_9_reg))
#define GDMA_DBG_OSD_WI_9_inst_adr                                                   "0x004D"
#define GDMA_DBG_OSD_WI_9_inst                                                       0x004D
#define GDMA_DBG_OSD_WI_9_dbg_win_38_shift                                           (0)
#define GDMA_DBG_OSD_WI_9_dbg_win_38_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_9_dbg_win_38(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_9_dbg_win_38_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_9_get_dbg_win_38(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_A                                                            0x1802fd38
#define GDMA_DBG_OSD_WI_A_reg_addr                                                   "0xB802FD38"
#define GDMA_DBG_OSD_WI_A_reg                                                        0xB802FD38
#define set_GDMA_DBG_OSD_WI_A_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_A_reg)=data)
#define get_GDMA_DBG_OSD_WI_A_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_A_reg))
#define GDMA_DBG_OSD_WI_A_inst_adr                                                   "0x004E"
#define GDMA_DBG_OSD_WI_A_inst                                                       0x004E
#define GDMA_DBG_OSD_WI_A_dbg_win_3c_shift                                           (0)
#define GDMA_DBG_OSD_WI_A_dbg_win_3c_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_A_dbg_win_3c(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_A_dbg_win_3c_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_A_get_dbg_win_3c(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_B                                                            0x1802fd3c
#define GDMA_DBG_OSD_WI_B_reg_addr                                                   "0xB802FD3C"
#define GDMA_DBG_OSD_WI_B_reg                                                        0xB802FD3C
#define set_GDMA_DBG_OSD_WI_B_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_B_reg)=data)
#define get_GDMA_DBG_OSD_WI_B_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_B_reg))
#define GDMA_DBG_OSD_WI_B_inst_adr                                                   "0x004F"
#define GDMA_DBG_OSD_WI_B_inst                                                       0x004F
#define GDMA_DBG_OSD_WI_B_dbg_win_40_shift                                           (0)
#define GDMA_DBG_OSD_WI_B_dbg_win_40_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_B_dbg_win_40(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_B_dbg_win_40_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_B_get_dbg_win_40(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_C                                                            0x1802fd40
#define GDMA_DBG_OSD_WI_C_reg_addr                                                   "0xB802FD40"
#define GDMA_DBG_OSD_WI_C_reg                                                        0xB802FD40
#define set_GDMA_DBG_OSD_WI_C_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_C_reg)=data)
#define get_GDMA_DBG_OSD_WI_C_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_C_reg))
#define GDMA_DBG_OSD_WI_C_inst_adr                                                   "0x0050"
#define GDMA_DBG_OSD_WI_C_inst                                                       0x0050
#define GDMA_DBG_OSD_WI_C_dbg_win_44_shift                                           (0)
#define GDMA_DBG_OSD_WI_C_dbg_win_44_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_C_dbg_win_44(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_C_dbg_win_44_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_C_get_dbg_win_44(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_D                                                            0x1802fd44
#define GDMA_DBG_OSD_WI_D_reg_addr                                                   "0xB802FD44"
#define GDMA_DBG_OSD_WI_D_reg                                                        0xB802FD44
#define set_GDMA_DBG_OSD_WI_D_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_D_reg)=data)
#define get_GDMA_DBG_OSD_WI_D_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_D_reg))
#define GDMA_DBG_OSD_WI_D_inst_adr                                                   "0x0051"
#define GDMA_DBG_OSD_WI_D_inst                                                       0x0051
#define GDMA_DBG_OSD_WI_D_dbg_win_48_shift                                           (0)
#define GDMA_DBG_OSD_WI_D_dbg_win_48_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_D_dbg_win_48(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_D_dbg_win_48_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_D_get_dbg_win_48(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_E                                                            0x1802fd48
#define GDMA_DBG_OSD_WI_E_reg_addr                                                   "0xB802FD48"
#define GDMA_DBG_OSD_WI_E_reg                                                        0xB802FD48
#define set_GDMA_DBG_OSD_WI_E_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_E_reg)=data)
#define get_GDMA_DBG_OSD_WI_E_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_E_reg))
#define GDMA_DBG_OSD_WI_E_inst_adr                                                   "0x0052"
#define GDMA_DBG_OSD_WI_E_inst                                                       0x0052
#define GDMA_DBG_OSD_WI_E_dbg_win_4c_shift                                           (0)
#define GDMA_DBG_OSD_WI_E_dbg_win_4c_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_E_dbg_win_4c(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_E_dbg_win_4c_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_E_get_dbg_win_4c(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_F                                                            0x1802fd4c
#define GDMA_DBG_OSD_WI_F_reg_addr                                                   "0xB802FD4C"
#define GDMA_DBG_OSD_WI_F_reg                                                        0xB802FD4C
#define set_GDMA_DBG_OSD_WI_F_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_F_reg)=data)
#define get_GDMA_DBG_OSD_WI_F_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_F_reg))
#define GDMA_DBG_OSD_WI_F_inst_adr                                                   "0x0053"
#define GDMA_DBG_OSD_WI_F_inst                                                       0x0053
#define GDMA_DBG_OSD_WI_F_dbg_win_50_shift                                           (0)
#define GDMA_DBG_OSD_WI_F_dbg_win_50_mask                                            (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_F_dbg_win_50(data)                                           (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_F_dbg_win_50_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_F_get_dbg_win_50(data)                                       ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_10                                                           0x1802fd50
#define GDMA_DBG_OSD_WI_10_reg_addr                                                  "0xB802FD50"
#define GDMA_DBG_OSD_WI_10_reg                                                       0xB802FD50
#define set_GDMA_DBG_OSD_WI_10_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_10_reg)=data)
#define get_GDMA_DBG_OSD_WI_10_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_10_reg))
#define GDMA_DBG_OSD_WI_10_inst_adr                                                  "0x0054"
#define GDMA_DBG_OSD_WI_10_inst                                                      0x0054
#define GDMA_DBG_OSD_WI_10_dbg_win_54_shift                                          (0)
#define GDMA_DBG_OSD_WI_10_dbg_win_54_mask                                           (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_10_dbg_win_54(data)                                          (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_10_dbg_win_54_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_10_get_dbg_win_54(data)                                      ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_11                                                           0x1802fd54
#define GDMA_DBG_OSD_WI_11_reg_addr                                                  "0xB802FD54"
#define GDMA_DBG_OSD_WI_11_reg                                                       0xB802FD54
#define set_GDMA_DBG_OSD_WI_11_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_11_reg)=data)
#define get_GDMA_DBG_OSD_WI_11_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_11_reg))
#define GDMA_DBG_OSD_WI_11_inst_adr                                                  "0x0055"
#define GDMA_DBG_OSD_WI_11_inst                                                      0x0055
#define GDMA_DBG_OSD_WI_11_dbg_win_58_shift                                          (0)
#define GDMA_DBG_OSD_WI_11_dbg_win_58_mask                                           (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_11_dbg_win_58(data)                                          (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_11_dbg_win_58_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_11_get_dbg_win_58(data)                                      ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_12                                                           0x1802fd58
#define GDMA_DBG_OSD_WI_12_reg_addr                                                  "0xB802FD58"
#define GDMA_DBG_OSD_WI_12_reg                                                       0xB802FD58
#define set_GDMA_DBG_OSD_WI_12_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_12_reg)=data)
#define get_GDMA_DBG_OSD_WI_12_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_12_reg))
#define GDMA_DBG_OSD_WI_12_inst_adr                                                  "0x0056"
#define GDMA_DBG_OSD_WI_12_inst                                                      0x0056
#define GDMA_DBG_OSD_WI_12_dbg_win_5c_shift                                          (0)
#define GDMA_DBG_OSD_WI_12_dbg_win_5c_mask                                           (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_12_dbg_win_5c(data)                                          (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_12_dbg_win_5c_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_12_get_dbg_win_5c(data)                                      ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_13                                                           0x1802fd5c
#define GDMA_DBG_OSD_WI_13_reg_addr                                                  "0xB802FD5C"
#define GDMA_DBG_OSD_WI_13_reg                                                       0xB802FD5C
#define set_GDMA_DBG_OSD_WI_13_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_13_reg)=data)
#define get_GDMA_DBG_OSD_WI_13_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_13_reg))
#define GDMA_DBG_OSD_WI_13_inst_adr                                                  "0x0057"
#define GDMA_DBG_OSD_WI_13_inst                                                      0x0057
#define GDMA_DBG_OSD_WI_13_dbg_win_60_shift                                          (0)
#define GDMA_DBG_OSD_WI_13_dbg_win_60_mask                                           (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_13_dbg_win_60(data)                                          (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_13_dbg_win_60_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_13_get_dbg_win_60(data)                                      ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_14                                                           0x1802fd60
#define GDMA_DBG_OSD_WI_14_reg_addr                                                  "0xB802FD60"
#define GDMA_DBG_OSD_WI_14_reg                                                       0xB802FD60
#define set_GDMA_DBG_OSD_WI_14_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_14_reg)=data)
#define get_GDMA_DBG_OSD_WI_14_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_14_reg))
#define GDMA_DBG_OSD_WI_14_inst_adr                                                  "0x0058"
#define GDMA_DBG_OSD_WI_14_inst                                                      0x0058
#define GDMA_DBG_OSD_WI_14_dbg_win_64_shift                                          (0)
#define GDMA_DBG_OSD_WI_14_dbg_win_64_mask                                           (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_14_dbg_win_64(data)                                          (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_14_dbg_win_64_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_14_get_dbg_win_64(data)                                      ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_15                                                           0x1802fd64
#define GDMA_DBG_OSD_WI_15_reg_addr                                                  "0xB802FD64"
#define GDMA_DBG_OSD_WI_15_reg                                                       0xB802FD64
#define set_GDMA_DBG_OSD_WI_15_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_15_reg)=data)
#define get_GDMA_DBG_OSD_WI_15_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_15_reg))
#define GDMA_DBG_OSD_WI_15_inst_adr                                                  "0x0059"
#define GDMA_DBG_OSD_WI_15_inst                                                      0x0059
#define GDMA_DBG_OSD_WI_15_dbg_win_68_shift                                          (0)
#define GDMA_DBG_OSD_WI_15_dbg_win_68_mask                                           (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_15_dbg_win_68(data)                                          (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_15_dbg_win_68_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_15_get_dbg_win_68(data)                                      ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_16                                                           0x1802fd68
#define GDMA_DBG_OSD_WI_16_reg_addr                                                  "0xB802FD68"
#define GDMA_DBG_OSD_WI_16_reg                                                       0xB802FD68
#define set_GDMA_DBG_OSD_WI_16_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_16_reg)=data)
#define get_GDMA_DBG_OSD_WI_16_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_16_reg))
#define GDMA_DBG_OSD_WI_16_inst_adr                                                  "0x005A"
#define GDMA_DBG_OSD_WI_16_inst                                                      0x005A
#define GDMA_DBG_OSD_WI_16_dbg_win_6c_shift                                          (0)
#define GDMA_DBG_OSD_WI_16_dbg_win_6c_mask                                           (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_16_dbg_win_6c(data)                                          (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_16_dbg_win_6c_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_16_get_dbg_win_6c(data)                                      ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_17                                                           0x1802fd6c
#define GDMA_DBG_OSD_WI_17_reg_addr                                                  "0xB802FD6C"
#define GDMA_DBG_OSD_WI_17_reg                                                       0xB802FD6C
#define set_GDMA_DBG_OSD_WI_17_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_17_reg)=data)
#define get_GDMA_DBG_OSD_WI_17_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_17_reg))
#define GDMA_DBG_OSD_WI_17_inst_adr                                                  "0x005B"
#define GDMA_DBG_OSD_WI_17_inst                                                      0x005B
#define GDMA_DBG_OSD_WI_17_dbg_win_70_shift                                          (0)
#define GDMA_DBG_OSD_WI_17_dbg_win_70_mask                                           (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_17_dbg_win_70(data)                                          (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_17_dbg_win_70_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_17_get_dbg_win_70(data)                                      ((0xFFFFFFFF&(data))>>0)


#define GDMA_DBG_OSD_WI_18                                                           0x1802fd70
#define GDMA_DBG_OSD_WI_18_reg_addr                                                  "0xB802FD70"
#define GDMA_DBG_OSD_WI_18_reg                                                       0xB802FD70
#define set_GDMA_DBG_OSD_WI_18_reg(data)   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_18_reg)=data)
#define get_GDMA_DBG_OSD_WI_18_reg   (*((volatile unsigned int*) GDMA_DBG_OSD_WI_18_reg))
#define GDMA_DBG_OSD_WI_18_inst_adr                                                  "0x005C"
#define GDMA_DBG_OSD_WI_18_inst                                                      0x005C
#define GDMA_DBG_OSD_WI_18_dbg_win_74_shift                                          (0)
#define GDMA_DBG_OSD_WI_18_dbg_win_74_mask                                           (0xFFFFFFFF)
#define GDMA_DBG_OSD_WI_18_dbg_win_74(data)                                          (0xFFFFFFFF&((data)<<0))
#define GDMA_DBG_OSD_WI_18_dbg_win_74_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define GDMA_DBG_OSD_WI_18_get_dbg_win_74(data)                                      ((0xFFFFFFFF&(data))>>0)


#define GDMA_ONLINE_STATUS                                                           0x1802fd80
#define GDMA_ONLINE_STATUS_reg_addr                                                  "0xB802FD80"
#define GDMA_ONLINE_STATUS_reg                                                       0xB802FD80
#define set_GDMA_ONLINE_STATUS_reg(data)   (*((volatile unsigned int*) GDMA_ONLINE_STATUS_reg)=data)
#define get_GDMA_ONLINE_STATUS_reg   (*((volatile unsigned int*) GDMA_ONLINE_STATUS_reg))
#define GDMA_ONLINE_STATUS_inst_adr                                                  "0x0060"
#define GDMA_ONLINE_STATUS_inst                                                      0x0060
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc1_use_2nd_dma_shift                          (24)
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc1_use_2nd_dma_mask                           (0x01000000)
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc1_use_2nd_dma(data)                          (0x01000000&((data)<<24))
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc1_use_2nd_dma_src(data)                      ((0x01000000&(data))>>24)
#define GDMA_ONLINE_STATUS_get_Set_osd1_fbdc1_use_2nd_dma(data)                      ((0x01000000&(data))>>24)
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc2_use_2nd_dma_shift                          (23)
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc2_use_2nd_dma_mask                           (0x00800000)
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc2_use_2nd_dma(data)                          (0x00800000&((data)<<23))
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc2_use_2nd_dma_src(data)                      ((0x00800000&(data))>>23)
#define GDMA_ONLINE_STATUS_get_Set_osd1_fbdc2_use_2nd_dma(data)                      ((0x00800000&(data))>>23)
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc3_use_2nd_dma_shift                          (22)
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc3_use_2nd_dma_mask                           (0x00400000)
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc3_use_2nd_dma(data)                          (0x00400000&((data)<<22))
#define GDMA_ONLINE_STATUS_Set_osd1_fbdc3_use_2nd_dma_src(data)                      ((0x00400000&(data))>>22)
#define GDMA_ONLINE_STATUS_get_Set_osd1_fbdc3_use_2nd_dma(data)                      ((0x00400000&(data))>>22)
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc1_use_2nd_dma_shift                          (21)
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc1_use_2nd_dma_mask                           (0x00200000)
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc1_use_2nd_dma(data)                          (0x00200000&((data)<<21))
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc1_use_2nd_dma_src(data)                      ((0x00200000&(data))>>21)
#define GDMA_ONLINE_STATUS_get_Set_osd2_fbdc1_use_2nd_dma(data)                      ((0x00200000&(data))>>21)
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc2_use_2nd_dma_shift                          (20)
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc2_use_2nd_dma_mask                           (0x00100000)
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc2_use_2nd_dma(data)                          (0x00100000&((data)<<20))
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc2_use_2nd_dma_src(data)                      ((0x00100000&(data))>>20)
#define GDMA_ONLINE_STATUS_get_Set_osd2_fbdc2_use_2nd_dma(data)                      ((0x00100000&(data))>>20)
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc3_use_2nd_dma_shift                          (19)
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc3_use_2nd_dma_mask                           (0x00080000)
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc3_use_2nd_dma(data)                          (0x00080000&((data)<<19))
#define GDMA_ONLINE_STATUS_Set_osd2_fbdc3_use_2nd_dma_src(data)                      ((0x00080000&(data))>>19)
#define GDMA_ONLINE_STATUS_get_Set_osd2_fbdc3_use_2nd_dma(data)                      ((0x00080000&(data))>>19)
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc1_use_2nd_dma_shift                          (18)
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc1_use_2nd_dma_mask                           (0x00040000)
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc1_use_2nd_dma(data)                          (0x00040000&((data)<<18))
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc1_use_2nd_dma_src(data)                      ((0x00040000&(data))>>18)
#define GDMA_ONLINE_STATUS_get_Set_osd3_fbdc1_use_2nd_dma(data)                      ((0x00040000&(data))>>18)
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc2_use_2nd_dma_shift                          (17)
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc2_use_2nd_dma_mask                           (0x00020000)
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc2_use_2nd_dma(data)                          (0x00020000&((data)<<17))
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc2_use_2nd_dma_src(data)                      ((0x00020000&(data))>>17)
#define GDMA_ONLINE_STATUS_get_Set_osd3_fbdc2_use_2nd_dma(data)                      ((0x00020000&(data))>>17)
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc3_use_2nd_dma_shift                          (16)
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc3_use_2nd_dma_mask                           (0x00010000)
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc3_use_2nd_dma(data)                          (0x00010000&((data)<<16))
#define GDMA_ONLINE_STATUS_Set_osd3_fbdc3_use_2nd_dma_src(data)                      ((0x00010000&(data))>>16)
#define GDMA_ONLINE_STATUS_get_Set_osd3_fbdc3_use_2nd_dma(data)                      ((0x00010000&(data))>>16)
#define GDMA_ONLINE_STATUS_set_osd5_online_use_offline_dma_shift                     (13)
#define GDMA_ONLINE_STATUS_set_osd5_online_use_offline_dma_mask                      (0x00002000)
#define GDMA_ONLINE_STATUS_set_osd5_online_use_offline_dma(data)                     (0x00002000&((data)<<13))
#define GDMA_ONLINE_STATUS_set_osd5_online_use_offline_dma_src(data)                 ((0x00002000&(data))>>13)
#define GDMA_ONLINE_STATUS_get_set_osd5_online_use_offline_dma(data)                 ((0x00002000&(data))>>13)
#define GDMA_ONLINE_STATUS_set_osd4_online_use_offline_dma_shift                     (12)
#define GDMA_ONLINE_STATUS_set_osd4_online_use_offline_dma_mask                      (0x00001000)
#define GDMA_ONLINE_STATUS_set_osd4_online_use_offline_dma(data)                     (0x00001000&((data)<<12))
#define GDMA_ONLINE_STATUS_set_osd4_online_use_offline_dma_src(data)                 ((0x00001000&(data))>>12)
#define GDMA_ONLINE_STATUS_get_set_osd4_online_use_offline_dma(data)                 ((0x00001000&(data))>>12)
#define GDMA_ONLINE_STATUS_set_osd3_online_use_offline_dma_shift                     (11)
#define GDMA_ONLINE_STATUS_set_osd3_online_use_offline_dma_mask                      (0x00000800)
#define GDMA_ONLINE_STATUS_set_osd3_online_use_offline_dma(data)                     (0x00000800&((data)<<11))
#define GDMA_ONLINE_STATUS_set_osd3_online_use_offline_dma_src(data)                 ((0x00000800&(data))>>11)
#define GDMA_ONLINE_STATUS_get_set_osd3_online_use_offline_dma(data)                 ((0x00000800&(data))>>11)
#define GDMA_ONLINE_STATUS_set_osd2_online_use_offline_dma_shift                     (10)
#define GDMA_ONLINE_STATUS_set_osd2_online_use_offline_dma_mask                      (0x00000400)
#define GDMA_ONLINE_STATUS_set_osd2_online_use_offline_dma(data)                     (0x00000400&((data)<<10))
#define GDMA_ONLINE_STATUS_set_osd2_online_use_offline_dma_src(data)                 ((0x00000400&(data))>>10)
#define GDMA_ONLINE_STATUS_get_set_osd2_online_use_offline_dma(data)                 ((0x00000400&(data))>>10)
#define GDMA_ONLINE_STATUS_set_osd1_online_use_offline_dma_shift                     (9)
#define GDMA_ONLINE_STATUS_set_osd1_online_use_offline_dma_mask                      (0x00000200)
#define GDMA_ONLINE_STATUS_set_osd1_online_use_offline_dma(data)                     (0x00000200&((data)<<9))
#define GDMA_ONLINE_STATUS_set_osd1_online_use_offline_dma_src(data)                 ((0x00000200&(data))>>9)
#define GDMA_ONLINE_STATUS_get_set_osd1_online_use_offline_dma(data)                 ((0x00000200&(data))>>9)


#define GDMA_DMY_0                                                                   0x1802FDFC
#define GDMA_DMY_1                                                                   0x1802FE00
#define GDMA_DMY_0_reg_addr                                                          "0xB802FDFC"
#define GDMA_DMY_1_reg_addr                                                          "0xB802FE00"
#define GDMA_DMY_0_reg                                                               0xB802FDFC
#define GDMA_DMY_1_reg                                                               0xB802FE00
#define set_GDMA_DMY_0_reg(data)   (*((volatile unsigned int*) GDMA_DMY_0_reg)=data)
#define set_GDMA_DMY_1_reg(data)   (*((volatile unsigned int*) GDMA_DMY_1_reg)=data)
#define get_GDMA_DMY_0_reg   (*((volatile unsigned int*) GDMA_DMY_0_reg))
#define get_GDMA_DMY_1_reg   (*((volatile unsigned int*) GDMA_DMY_1_reg))
#define GDMA_DMY_0_inst_adr                                                          "0x007F"
#define GDMA_DMY_1_inst_adr                                                          "0x0080"
#define GDMA_DMY_0_inst                                                              0x007F
#define GDMA_DMY_1_inst                                                              0x0080
#define GDMA_DMY_dummy_shift                                                         (0)
#define GDMA_DMY_dummy_mask                                                          (0xFFFFFFFF)
#define GDMA_DMY_dummy(data)                                                         (0xFFFFFFFF&((data)<<0))
#define GDMA_DMY_dummy_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define GDMA_DMY_get_dummy(data)                                                     ((0xFFFFFFFF&(data))>>0)


#endif
