// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:798                    Version flow no.:1.1.55
#ifndef _MDOMAIN_REG_H_INCLUDED_
#define _MDOMAIN_REG_H_INCLUDED_

//#define  _MDOMAIN_USE_STRUCT
#ifdef _MDOMAIN_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    in1_wtlvl:8;
    unsigned int    in1_write_num:16;
}DDR_in1wtlvl_num;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    in1_wrlen:7;
    unsigned int    reserved_1:1;
    unsigned int    in1_write_remain:7;
}DDR_in1wrlen_rem;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    in1_wr_mem_start:28;
    unsigned int    reserved_1:3;
}DDR_in1addr;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    in1_line_step:28;
    unsigned int    reserved_1:3;
}DDR_in1linestep;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    in1_block_step:28;
    unsigned int    reserved_1:3;
}DDR_in1blkstep;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    in1_sec_bl:28;
    unsigned int    reserved_1:3;
}DDR_in1_2ndaddr;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    in1_third_bl:28;
    unsigned int    reserved_1:3;
}DDR_in1_3rdaddr;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    in1_zero:1;
    unsigned int    in1_frame_access_mode:1;
    unsigned int    reserved_1:3;
    unsigned int    in1_line_number:13;
}DDR_in1linenum;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    in1_freeze_control:1;
    unsigned int    in1_bad_edit_suppression:1;
    unsigned int    dispm_dbg_sel:4;
    unsigned int    in1_l_flag_inv:1;
    unsigned int    in1_rm_r_vs_en:1;
    unsigned int    reserved_1:1;
    unsigned int    in1_v_flip_3buf_en:1;
    unsigned int    reserved_2:1;
    unsigned int    in1_merge_enable:1;
    unsigned int    in1_double_enable:1;
    unsigned int    in1_block_free:1;
    unsigned int    in1_single_buffer_select:2;
    unsigned int    in1_freeze_enable:1;
    unsigned int    in1_en_vs_rst:1;
}DDR_in1ctrl;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    in1_block_select:2;
    unsigned int    in1_freeze_ok:1;
    unsigned int    in1_field_polarity_error:1;
    unsigned int    in1_field_polarity_status:4;
}DDR_in1status;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    in1_cap_enable:1;
}CAP_in1_enable;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    dummy1802722c_18:1;
    unsigned int    dummy1802722c_17:1;
    unsigned int    dummy1802722c_16:1;
    unsigned int    reserved_1:13;
    unsigned int    cap1_db_apply:1;
    unsigned int    cap1_db_sel:1;
    unsigned int    cap1_db_en:1;
}CAP_reg_doublbuffer;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    in1_cap_last_wr_flag:1;
    unsigned int    in1_fifofull:1;
    unsigned int    in1_fifoempty:1;
    unsigned int    in1_fifouf:1;
    unsigned int    in1_fifoof:1;
    unsigned int    reserved_1:11;
    unsigned int    dummy18027270_4:1;
    unsigned int    dummy18027270_3:1;
    unsigned int    dummy18027270_2:1;
    unsigned int    dummy18027270_1:1;
    unsigned int    dummy18027270_0:1;
}CAP_ddr_fifostatus;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    in1_drop:1;
    unsigned int    in1_over_size:1;
    unsigned int    in1_under_size:1;
    unsigned int    reserved_1:13;
    unsigned int    dummy18027274_2:1;
    unsigned int    dummy18027274_1:1;
    unsigned int    dummy18027274_0:1;
}CAP_help_debug_status;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    in1_cap_downlimit_adr:28;
    unsigned int    reserved_1:3;
}CAPMAIN_boundaryaddr1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    in1_cap_uplimit_adr:28;
    unsigned int    reserved_1:3;
}CAPMAIN_boundaryaddr2;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    in1_cap_downlimit_ov:1;
    unsigned int    in1_cap_uplimit_ov:1;
}DI1CAP_wrrd_boundaryadd_status;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:28;
    unsigned int    reserved_2:3;
}CAPSUB_boundaryaddr1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:28;
    unsigned int    reserved_2:3;
}CAPSUB_boundaryaddr2;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
}DI2CAP_wrrd_boundaryadd_status;

typedef struct
{
    unsigned int    reserved_0:11;
    unsigned int    in1_fifoerr_ie:1;
    unsigned int    in1_cap_last_wr_ie:1;
    unsigned int    in1_fifoerr_wde:1;
    unsigned int    in1_cap_last_wr_wde:1;
    unsigned int    wd_to_main:1;
    unsigned int    reserved_1:11;
    unsigned int    dummy18027290_4:1;
    unsigned int    dummy18027290_3:1;
    unsigned int    dummy18027290_2:1;
    unsigned int    dummy18027290_1:1;
    unsigned int    dummy18027290_0:1;
}CAP_ie_wd_ctrl;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    in1_sbs_vsd_en:1;
}CAPMAIN_sbs_vsd_cap_ctrl;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    in1_lr_offset:28;
    unsigned int    reserved_1:3;
}CAPMAIN_sbs_vsd_cap_offset;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    crc_comp_error_int:1;
    unsigned int    dynamic_crc_cmp_en:1;
    unsigned int    reserved_1:1;
    unsigned int    crc_bit_sel:2;
    unsigned int    reserved_2:2;
    unsigned int    disp_crc_3d_en:1;
    unsigned int    reserved_3:1;
    unsigned int    disp_crc_conti:1;
    unsigned int    disp_crc_start:1;
    unsigned int    cap_crc_3d_en:1;
    unsigned int    reserved_4:1;
    unsigned int    cap_crc_conti:1;
    unsigned int    cap_crc_start:1;
}DISPM_crc_ctrl;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    match_buffer:2;
    unsigned int    reserved_1:15;
    unsigned int    crc_comp_error_flag:1;
}DISPM_crc_status;

typedef struct
{
    unsigned int    crc_mask:32;
}CRC_mask;

typedef struct
{
    unsigned int    cap_l_crc_result:32;
}CAP_l_crc_result;

typedef struct
{
    unsigned int    cap_r_crc_result:32;
}CAP_r_crc_result;

typedef struct
{
    unsigned int    disp_l_crc_result:32;
}DISP_l_crc_result;

typedef struct
{
    unsigned int    disp_r_crc_result:32;
}DISPLAY_r_crc_result;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    in1_rate_en:1;
}CAP_dma_rate_ctrl;

typedef struct
{
    unsigned int    in1_rate:32;
}CAPTURE_rate;

typedef struct
{
    unsigned int    reserved_0:12;
    unsigned int    dummy180272c8_19:1;
    unsigned int    dummy180272c8_18:1;
    unsigned int    dummy180272c8_17:1;
    unsigned int    dummy180272c8_16:1;
    unsigned int    reserved_1:12;
    unsigned int    in1_8byte_swap:1;
    unsigned int    in1_4byte_swap:1;
    unsigned int    in1_2byte_swap:1;
    unsigned int    in1_1byte_swap:1;
}CAPTURE_byte_swap;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    dispd_fs_3d_en:1;
    unsigned int    dispi_fs_3d_en:1;
    unsigned int    reserved_1:1;
    unsigned int    dummy180272f0_2:1;
    unsigned int    dummy180272f0_1:1;
    unsigned int    dummy180272f0_0:1;
}SMOOTH_tog_ctrl_0;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    md_reg_is_db:1;
    unsigned int    im_reg_is_db:1;
}SMOOTH_tog_status_0;

typedef struct
{
    unsigned int    reserved_0:17;
    unsigned int    main_rgb2gbr_fmt:1;
    unsigned int    main_usb2vga_en:1;
    unsigned int    main_usb2vga_fmt:1;
    unsigned int    reserved_1:1;
    unsigned int    main_pre_rd_v_start:11;
}DDR_mainprevstart;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    main_pixel_num:14;
    unsigned int    main_wtlvl:8;
}DDR_mainnumwtl;

typedef struct
{
    unsigned int    main_read_num:16;
    unsigned int    reserved_0:1;
    unsigned int    main_read_len:7;
    unsigned int    reserved_1:1;
    unsigned int    main_read_remain:7;
}DDR_mainrdnumlenrem;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    main_read_addr:28;
    unsigned int    reserved_1:3;
}DDR_mainaddr;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    main_addr_drop:16;
}DDR_mainaddrdropbits;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    main_line_step:28;
    unsigned int    reserved_1:3;
}DDR_mainlinestep;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    main_block_step:28;
    unsigned int    reserved_1:3;
}DDR_mainblkstep;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    main_sec_block:28;
    unsigned int    reserved_1:3;
}DDR_main2ndaddr;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    main_third_block:28;
    unsigned int    reserved_1:3;
}DDR_main3rdaddr;

typedef struct
{
    unsigned int    reserved_0:19;
    unsigned int    main_line_number:13;
}DDR_mainlinenum;

typedef struct
{
    unsigned int    reserved_0:9;
    unsigned int    dummy18027328_22:1;
    unsigned int    dummy18027328_21:1;
    unsigned int    dummy18027328_20:1;
    unsigned int    maincolorspace:1;
    unsigned int    reserved_1:1;
    unsigned int    main_in_format:1;
    unsigned int    main_bit_num:1;
    unsigned int    reserved_2:1;
    unsigned int    main_pr_out_merge_triple:1;
    unsigned int    main_pr_our_merge_en:1;
    unsigned int    main_frame_seq_out_en:1;
    unsigned int    main_stop_burst_en:1;
    unsigned int    reserved_3:1;
    unsigned int    main_single_buffer_select:2;
    unsigned int    main_v_flip_3buf_en:1;
    unsigned int    main_double_en:1;
    unsigned int    main_merge_en0:1;
    unsigned int    main_block_free:1;
    unsigned int    main_frc_style:1;
    unsigned int    main_source_sel:2;
    unsigned int    main_use_sub_block:1;
}DDR_mainctrl;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    main_disp_en:1;
}DISP_main_enable;

typedef struct
{
    unsigned int    reserved_0:16;
    unsigned int    main_repeat_chgflg:1;
    unsigned int    main_repeat_frame_sequence:3;
    unsigned int    main_drop_chgflg:1;
    unsigned int    main_drop_frame_sequence:3;
    unsigned int    reserved_1:2;
    unsigned int    main_block_select:2;
    unsigned int    reserved_2:3;
    unsigned int    main_read_l_flag:1;
}DDR_mainstatus;

typedef struct
{
    unsigned int    reserved_0:13;
    unsigned int    dummy18027334_18:1;
    unsigned int    dummy18027334_17:1;
    unsigned int    dummy18027334_16:1;
    unsigned int    reserved_1:13;
    unsigned int    disp1_db_rd_sel:1;
    unsigned int    disp1_double_enable:1;
    unsigned int    disp1_double_apply:1;
}DDR_mainsubctrl;

typedef struct
{
    unsigned int    reserved_0:15;
    unsigned int    main_en_syn_rst:1;
    unsigned int    reserved_1:2;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:2;
    unsigned int    reserved_5:1;
    unsigned int    reserved_6:1;
    unsigned int    reserved_7:2;
    unsigned int    reserved_8:1;
    unsigned int    reserved_9:1;
    unsigned int    reserved_10:1;
    unsigned int    reserved_11:1;
    unsigned int    reserved_12:1;
    unsigned int    reserved_13:1;
}DDR_mainmaskctrl;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    reserved_1:11;
}DDR_mainvmoffset;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    reserved_1:11;
}DDR_main_mask1_mask2_offset;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    reserved_1:12;
}DDR_main_up_hmoffset;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    reserved_1:12;
}DDR_main_mid_hmoffset;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    reserved_1:12;
}DDR_main_mid1_mid2_offset;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    reserved_1:12;
}DDR_main_down_hmoffset;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    reserved_1:6;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:7;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:7;
}DDR_main_up_hmnumlenremleft;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    reserved_1:6;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:7;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:7;
}DDR_main_up_hmnumlenremright;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    reserved_1:6;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:7;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:7;
}DDR_main_mid_hmnumlenremleft;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    reserved_1:6;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:7;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:7;
}DDR_main_mid_hmnumlenremmiddle;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    reserved_1:6;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:7;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:7;
}DDR_main_mid_hmnumlenremright;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    reserved_1:6;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:7;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:7;
}DDR_main_down_hmnumlenremleft;

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    reserved_1:6;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:7;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:7;
}DDR_main_down_hmnumlenremright;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    reserved_1:11;
}DDR_main_up_vmsize;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    reserved_1:12;
}DDR_main_up_hmsize;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    reserved_1:11;
}DDR_main_mid_vmsize;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    reserved_1:12;
}DDR_main_mid1_hmsize;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    reserved_1:12;
}DDR_main_mid2_hmsize;

typedef struct
{
    unsigned int    reserved_0:21;
    unsigned int    reserved_1:11;
}DDR_main_down_vmsize;

typedef struct
{
    unsigned int    reserved_0:20;
    unsigned int    reserved_1:12;
}DDR_main_down_hmsize;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:28;
    unsigned int    reserved_2:3;
}DDR_main_up_maskstep;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:28;
    unsigned int    reserved_2:3;
}DDR_main_mid1_maskstep;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:28;
    unsigned int    reserved_2:3;
}DDR_main_mid2_maskstep;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:28;
    unsigned int    reserved_2:3;
}DDR_main_down_maskstep;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
}DDR_mainmaskfnt;

typedef struct
{
    unsigned int    reserved_0:7;
    unsigned int    main_field:1;
    unsigned int    main_fifoof:1;
    unsigned int    main_fifouf:1;
    unsigned int    main_fifofull:1;
    unsigned int    main_fifoempty:1;
    unsigned int    main_combine_fifoof:1;
    unsigned int    main_combine_fifouf:1;
    unsigned int    main_combine_fifofull:1;
    unsigned int    main_combine_fifoempty:1;
    unsigned int    reserved_1:7;
    unsigned int    dummy18027460_8:1;
    unsigned int    dummy18027460_7:1;
    unsigned int    dummy18027460_6:1;
    unsigned int    dummy18027460_5:1;
    unsigned int    dummy18027460_4:1;
    unsigned int    dummy18027460_3:1;
    unsigned int    dummy18027460_2:1;
    unsigned int    dummy18027460_1:1;
    unsigned int    dummy18027460_0:1;
}DISP_ddr_fifostatus;

typedef struct
{
    unsigned int    reserved_0:14;
    unsigned int    main_fifoerr_ie:1;
    unsigned int    main_fifoerr_wde:1;
    unsigned int    reserved_1:14;
    unsigned int    dummy18027464_1:1;
    unsigned int    dummy18027464_0:1;
}DISP_ie_wd_ctrl;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    main_disp_downlimit_adr:28;
    unsigned int    reserved_1:3;
}DISPMAIN_boundaryaddr1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    main_disp_uplimit_adr:28;
    unsigned int    reserved_1:3;
}DISPMAIN_boundaryaddr2;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    main_disp_downlimit_ov:1;
    unsigned int    main_dispuplimit_ov:1;
}DISPI1_rd_boundaryadd_status;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:28;
    unsigned int    reserved_2:3;
}DISPSUB_boundaryaddr1;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    reserved_1:28;
    unsigned int    reserved_2:3;
}DISPSUB_boundaryaddr2;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
}DISPI2_rd_boundaryadd_status;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    main_r_first_addr:28;
    unsigned int    reserved_1:3;
}DDR_main_r_1st_addr;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    main_r_second_addr:28;
    unsigned int    reserved_1:3;
}DDR_main_r_2nd_addr;

typedef struct
{
    unsigned int    reserved_0:1;
    unsigned int    main_r_third_addr:28;
    unsigned int    reserved_1:3;
}DDR_main_r_3rd_addr;

typedef struct
{
    unsigned int    reserved_0:8;
    unsigned int    main_repeat_4x:1;
    unsigned int    main_repeat_3x:1;
    unsigned int    main_repeat_2x:1;
    unsigned int    main_repeat_1x:1;
    unsigned int    reserved_1:1;
    unsigned int    main_drop:1;
    unsigned int    reserved_2:1;
    unsigned int    main_under_size:1;
    unsigned int    reserved_3:8;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:1;
    unsigned int    reserved_6:1;
    unsigned int    reserved_7:1;
    unsigned int    reserved_8:1;
    unsigned int    reserved_9:1;
    unsigned int    reserved_10:1;
    unsigned int    reserved_11:1;
}DISP_help_debug;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    dispm_bist_mode_mbist_disp_main:1;
    unsigned int    dispm_bist_mode_mbist_cap_main:1;
}DISPM_bist_mode;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    dispm_bist_done_mbist_disp_main:1;
    unsigned int    dispm_bist_done_mbist_cap_main:1;
}DISPM_bist_done;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    dispm_bist_fail_group_mbist_disp_main:1;
    unsigned int    dispm_bist_fail_group_mbist_cap_main:1;
}DISPM_bist_fail_group;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    dispm_drf_mode_mbist_disp_main:1;
    unsigned int    dispm_drf_mode_mbist_cap_main:1;
}DISPM_drf_mode;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    dispm_drf_resume_mbist_disp_main:1;
    unsigned int    dispm_drf_resume_mbist_cap_main:1;
}DISPM_drf_resume;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    dispm_drf_done_mbist_disp_main:1;
    unsigned int    dispm_drf_done_mbist_cap_main:1;
}DISPM_drf_done;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    dispm_drf_pause_mbist_disp_main:1;
    unsigned int    dispm_drf_pause_mbist_cap_main:1;
}DISPM_drf_pause;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    dispm_drf_fail_group_mbist_disp_main:1;
    unsigned int    dispm_drf_fail_group_mbist_cap_main:1;
}DISPM_drf_fail_group;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    reserved_1:4;
    unsigned int    dispm_rmb_mbist_disp_main:4;
    unsigned int    dispm_rma_mbist_disp_main:4;
    unsigned int    reserved_2:4;
    unsigned int    reserved_3:4;
    unsigned int    dispm_rmb_mbist_cap_main:4;
    unsigned int    dispm_rma_mbist_cap_main:4;
}DISPM_rm;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    dispm_rmeb_mbist_disp_main:1;
    unsigned int    dispm_rmea_mbist_disp_main:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    dispm_rmeb_mbist_cap_main:1;
    unsigned int    dispm_rmea_mbist_cap_main:1;
}DISPM_rme;

typedef struct
{
    unsigned int    reserved_0:28;
    unsigned int    reserved_1:1;
    unsigned int    dispm_ls_mbist_disp_main:1;
    unsigned int    reserved_2:1;
    unsigned int    dispm_ls_mbist_cap_main:1;
}DISPM_ls;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    reserved_1:1;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:4;
}DISPM_decomp_rm;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    main_rate_en:1;
}DISP_dma_rate_ctrl;

typedef struct
{
    unsigned int    main_rate:32;
}DISPLAY_rate;

typedef struct
{
    unsigned int    reserved_0:9;
    unsigned int    reserved_1:3;
    unsigned int    reserved_2:1;
    unsigned int    reserved_3:1;
    unsigned int    reserved_4:1;
    unsigned int    reserved_5:1;
    unsigned int    reserved_6:9;
    unsigned int    main_channel_swap:3;
    unsigned int    main_8byte_swap:1;
    unsigned int    main_4byte_swap:1;
    unsigned int    main_2byte_swap:1;
    unsigned int    main_1byte_swap:1;
}DISPLAY_byte_channel_swap;
#endif


#define DDR_IN1WTLVL_NUM                                              0x18027200
#define DDR_IN1WTLVL_NUM_reg_addr                                     "0xb8027200"
#define DDR_IN1WTLVL_NUM_reg                                          0xb8027200
#define DDR_IN1WTLVL_NUM_inst_addr                                    "0x0080"
#define DDR_IN1WTLVL_NUM_inst                                         0x0080
#define DDR_IN1WTLVL_NUM_in1_wtlvl_shift                              (16)
#define DDR_IN1WTLVL_NUM_in1_write_num_shift                          (0)
#define DDR_IN1WTLVL_NUM_in1_wtlvl_mask                               (0x00FF0000)
#define DDR_IN1WTLVL_NUM_in1_write_num_mask                           (0x0000FFFF)
#define DDR_IN1WTLVL_NUM_in1_wtlvl(data)                              (0x00FF0000&((data)<<16))
#define DDR_IN1WTLVL_NUM_in1_write_num(data)                          (0x0000FFFF&(data))
#define DDR_IN1WTLVL_NUM_get_in1_wtlvl(data)                          ((0x00FF0000&(data))>>16)
#define DDR_IN1WTLVL_NUM_get_in1_write_num(data)                      (0x0000FFFF&(data))


#define DDR_IN1WRLEN_REM                                              0x18027204
#define DDR_IN1WRLEN_REM_reg_addr                                     "0xb8027204"
#define DDR_IN1WRLEN_REM_reg                                          0xb8027204
#define DDR_IN1WRLEN_REM_inst_addr                                    "0x0081"
#define DDR_IN1WRLEN_REM_inst                                         0x0081
#define DDR_IN1WRLEN_REM_in1_wrlen_shift                              (8)
#define DDR_IN1WRLEN_REM_in1_write_remain_shift                       (0)
#define DDR_IN1WRLEN_REM_in1_wrlen_mask                               (0x00007F00)
#define DDR_IN1WRLEN_REM_in1_write_remain_mask                        (0x0000007F)
#define DDR_IN1WRLEN_REM_in1_wrlen(data)                              (0x00007F00&((data)<<8))
#define DDR_IN1WRLEN_REM_in1_write_remain(data)                       (0x0000007F&(data))
#define DDR_IN1WRLEN_REM_get_in1_wrlen(data)                          ((0x00007F00&(data))>>8)
#define DDR_IN1WRLEN_REM_get_in1_write_remain(data)                   (0x0000007F&(data))


#define DDR_IN1ADDR                                                   0x18027208
#define DDR_IN1ADDR_reg_addr                                          "0xb8027208"
#define DDR_IN1ADDR_reg                                               0xb8027208
#define DDR_IN1ADDR_inst_addr                                         "0x0082"
#define DDR_IN1ADDR_inst                                              0x0082
#define DDR_IN1ADDR_in1_wr_mem_start_shift                            (3)
#define DDR_IN1ADDR_in1_wr_mem_start_mask                             (0x7FFFFFF8)
#define DDR_IN1ADDR_in1_wr_mem_start(data)                            (0x7FFFFFF8&((data)<<3))
#define DDR_IN1ADDR_get_in1_wr_mem_start(data)                        ((0x7FFFFFF8&(data))>>3)


#define DDR_IN1LINESTEP                                               0x1802720c
#define DDR_IN1LINESTEP_reg_addr                                      "0xb802720c"
#define DDR_IN1LINESTEP_reg                                           0xb802720c
#define DDR_IN1LINESTEP_inst_addr                                     "0x0083"
#define DDR_IN1LINESTEP_inst                                          0x0083
#define DDR_IN1LINESTEP_in1_line_step_shift                           (3)
#define DDR_IN1LINESTEP_in1_line_step_mask                            (0x7FFFFFF8)
#define DDR_IN1LINESTEP_in1_line_step(data)                           (0x7FFFFFF8&((data)<<3))
#define DDR_IN1LINESTEP_get_in1_line_step(data)                       ((0x7FFFFFF8&(data))>>3)


#define DDR_IN1BLKSTEP                                                0x18027210
#define DDR_IN1BLKSTEP_reg_addr                                       "0xb8027210"
#define DDR_IN1BLKSTEP_reg                                            0xb8027210
#define DDR_IN1BLKSTEP_inst_addr                                      "0x0084"
#define DDR_IN1BLKSTEP_inst                                           0x0084
#define DDR_IN1BLKSTEP_in1_block_step_shift                           (3)
#define DDR_IN1BLKSTEP_in1_block_step_mask                            (0x7FFFFFF8)
#define DDR_IN1BLKSTEP_in1_block_step(data)                           (0x7FFFFFF8&((data)<<3))
#define DDR_IN1BLKSTEP_get_in1_block_step(data)                       ((0x7FFFFFF8&(data))>>3)


#define DDR_IN1_2NDADDR                                               0x18027214
#define DDR_IN1_2NDADDR_reg_addr                                      "0xb8027214"
#define DDR_IN1_2NDADDR_reg                                           0xb8027214
#define DDR_IN1_2NDADDR_inst_addr                                     "0x0085"
#define DDR_IN1_2NDADDR_inst                                          0x0085
#define DDR_IN1_2NDADDR_in1_sec_bl_shift                              (3)
#define DDR_IN1_2NDADDR_in1_sec_bl_mask                               (0x7FFFFFF8)
#define DDR_IN1_2NDADDR_in1_sec_bl(data)                              (0x7FFFFFF8&((data)<<3))
#define DDR_IN1_2NDADDR_get_in1_sec_bl(data)                          ((0x7FFFFFF8&(data))>>3)


#define DDR_IN1_3RDADDR                                               0x18027218
#define DDR_IN1_3RDADDR_reg_addr                                      "0xb8027218"
#define DDR_IN1_3RDADDR_reg                                           0xb8027218
#define DDR_IN1_3RDADDR_inst_addr                                     "0x0086"
#define DDR_IN1_3RDADDR_inst                                          0x0086
#define DDR_IN1_3RDADDR_in1_third_bl_shift                            (3)
#define DDR_IN1_3RDADDR_in1_third_bl_mask                             (0x7FFFFFF8)
#define DDR_IN1_3RDADDR_in1_third_bl(data)                            (0x7FFFFFF8&((data)<<3))
#define DDR_IN1_3RDADDR_get_in1_third_bl(data)                        ((0x7FFFFFF8&(data))>>3)


#define DDR_IN1LINENUM                                                0x1802721c
#define DDR_IN1LINENUM_reg_addr                                       "0xb802721c"
#define DDR_IN1LINENUM_reg                                            0xb802721c
#define DDR_IN1LINENUM_inst_addr                                      "0x0087"
#define DDR_IN1LINENUM_inst                                           0x0087
#define DDR_IN1LINENUM_in1_zero_shift                                 (17)
#define DDR_IN1LINENUM_in1_frame_access_mode_shift                    (16)
#define DDR_IN1LINENUM_in1_line_number_shift                          (0)
#define DDR_IN1LINENUM_in1_zero_mask                                  (0x00020000)
#define DDR_IN1LINENUM_in1_frame_access_mode_mask                     (0x00010000)
#define DDR_IN1LINENUM_in1_line_number_mask                           (0x00001FFF)
#define DDR_IN1LINENUM_in1_zero(data)                                 (0x00020000&((data)<<17))
#define DDR_IN1LINENUM_in1_frame_access_mode(data)                    (0x00010000&((data)<<16))
#define DDR_IN1LINENUM_in1_line_number(data)                          (0x00001FFF&(data))
#define DDR_IN1LINENUM_get_in1_zero(data)                             ((0x00020000&(data))>>17)
#define DDR_IN1LINENUM_get_in1_frame_access_mode(data)                ((0x00010000&(data))>>16)
#define DDR_IN1LINENUM_get_in1_line_number(data)                      (0x00001FFF&(data))


#define DDR_IN1CTRL                                                   0x18027220
#define DDR_IN1CTRL_reg_addr                                          "0xb8027220"
#define DDR_IN1CTRL_reg                                               0xb8027220
#define DDR_IN1CTRL_inst_addr                                         "0x0088"
#define DDR_IN1CTRL_inst                                              0x0088
#define DDR_IN1CTRL_in1_freeze_control_shift                          (17)
#define DDR_IN1CTRL_in1_bad_edit_suppression_shift                    (16)
#define DDR_IN1CTRL_dispm_dbg_sel_shift                               (12)
#define DDR_IN1CTRL_in1_l_flag_inv_shift                              (11)
#define DDR_IN1CTRL_in1_rm_r_vs_en_shift                              (10)
#define DDR_IN1CTRL_in1_v_flip_3buf_en_shift                          (8)
#define DDR_IN1CTRL_in1_merge_enable_shift                            (6)
#define DDR_IN1CTRL_in1_double_enable_shift                           (5)
#define DDR_IN1CTRL_in1_block_free_shift                              (4)
#define DDR_IN1CTRL_in1_single_buffer_select_shift                    (2)
#define DDR_IN1CTRL_in1_freeze_enable_shift                           (1)
#define DDR_IN1CTRL_in1_en_vs_rst_shift                               (0)
#define DDR_IN1CTRL_in1_freeze_control_mask                           (0x00020000)
#define DDR_IN1CTRL_in1_bad_edit_suppression_mask                     (0x00010000)
#define DDR_IN1CTRL_dispm_dbg_sel_mask                                (0x0000F000)
#define DDR_IN1CTRL_in1_l_flag_inv_mask                               (0x00000800)
#define DDR_IN1CTRL_in1_rm_r_vs_en_mask                               (0x00000400)
#define DDR_IN1CTRL_in1_v_flip_3buf_en_mask                           (0x00000100)
#define DDR_IN1CTRL_in1_merge_enable_mask                             (0x00000040)
#define DDR_IN1CTRL_in1_double_enable_mask                            (0x00000020)
#define DDR_IN1CTRL_in1_block_free_mask                               (0x00000010)
#define DDR_IN1CTRL_in1_single_buffer_select_mask                     (0x0000000C)
#define DDR_IN1CTRL_in1_freeze_enable_mask                            (0x00000002)
#define DDR_IN1CTRL_in1_en_vs_rst_mask                                (0x00000001)
#define DDR_IN1CTRL_in1_freeze_control(data)                          (0x00020000&((data)<<17))
#define DDR_IN1CTRL_in1_bad_edit_suppression(data)                    (0x00010000&((data)<<16))
#define DDR_IN1CTRL_dispm_dbg_sel(data)                               (0x0000F000&((data)<<12))
#define DDR_IN1CTRL_in1_l_flag_inv(data)                              (0x00000800&((data)<<11))
#define DDR_IN1CTRL_in1_rm_r_vs_en(data)                              (0x00000400&((data)<<10))
#define DDR_IN1CTRL_in1_v_flip_3buf_en(data)                          (0x00000100&((data)<<8))
#define DDR_IN1CTRL_in1_merge_enable(data)                            (0x00000040&((data)<<6))
#define DDR_IN1CTRL_in1_double_enable(data)                           (0x00000020&((data)<<5))
#define DDR_IN1CTRL_in1_block_free(data)                              (0x00000010&((data)<<4))
#define DDR_IN1CTRL_in1_single_buffer_select(data)                    (0x0000000C&((data)<<2))
#define DDR_IN1CTRL_in1_freeze_enable(data)                           (0x00000002&((data)<<1))
#define DDR_IN1CTRL_in1_en_vs_rst(data)                               (0x00000001&(data))
#define DDR_IN1CTRL_get_in1_freeze_control(data)                      ((0x00020000&(data))>>17)
#define DDR_IN1CTRL_get_in1_bad_edit_suppression(data)                ((0x00010000&(data))>>16)
#define DDR_IN1CTRL_get_dispm_dbg_sel(data)                           ((0x0000F000&(data))>>12)
#define DDR_IN1CTRL_get_in1_l_flag_inv(data)                          ((0x00000800&(data))>>11)
#define DDR_IN1CTRL_get_in1_rm_r_vs_en(data)                          ((0x00000400&(data))>>10)
#define DDR_IN1CTRL_get_in1_v_flip_3buf_en(data)                      ((0x00000100&(data))>>8)
#define DDR_IN1CTRL_get_in1_merge_enable(data)                        ((0x00000040&(data))>>6)
#define DDR_IN1CTRL_get_in1_double_enable(data)                       ((0x00000020&(data))>>5)
#define DDR_IN1CTRL_get_in1_block_free(data)                          ((0x00000010&(data))>>4)
#define DDR_IN1CTRL_get_in1_single_buffer_select(data)                ((0x0000000C&(data))>>2)
#define DDR_IN1CTRL_get_in1_freeze_enable(data)                       ((0x00000002&(data))>>1)
#define DDR_IN1CTRL_get_in1_en_vs_rst(data)                           (0x00000001&(data))


#define DDR_IN1STATUS                                                 0x18027224
#define DDR_IN1STATUS_reg_addr                                        "0xb8027224"
#define DDR_IN1STATUS_reg                                             0xb8027224
#define DDR_IN1STATUS_inst_addr                                       "0x0089"
#define DDR_IN1STATUS_inst                                            0x0089
#define DDR_IN1STATUS_in1_block_select_shift                          (6)
#define DDR_IN1STATUS_in1_freeze_ok_shift                             (5)
#define DDR_IN1STATUS_in1_field_polarity_error_shift                  (4)
#define DDR_IN1STATUS_in1_field_polarity_status_shift                 (0)
#define DDR_IN1STATUS_in1_block_select_mask                           (0x000000C0)
#define DDR_IN1STATUS_in1_freeze_ok_mask                              (0x00000020)
#define DDR_IN1STATUS_in1_field_polarity_error_mask                   (0x00000010)
#define DDR_IN1STATUS_in1_field_polarity_status_mask                  (0x0000000F)
#define DDR_IN1STATUS_in1_block_select(data)                          (0x000000C0&((data)<<6))
#define DDR_IN1STATUS_in1_freeze_ok(data)                             (0x00000020&((data)<<5))
#define DDR_IN1STATUS_in1_field_polarity_error(data)                  (0x00000010&((data)<<4))
#define DDR_IN1STATUS_in1_field_polarity_status(data)                 (0x0000000F&(data))
#define DDR_IN1STATUS_get_in1_block_select(data)                      ((0x000000C0&(data))>>6)
#define DDR_IN1STATUS_get_in1_freeze_ok(data)                         ((0x00000020&(data))>>5)
#define DDR_IN1STATUS_get_in1_field_polarity_error(data)              ((0x00000010&(data))>>4)
#define DDR_IN1STATUS_get_in1_field_polarity_status(data)             (0x0000000F&(data))


#define CAP_IN1_ENABLE                                                0x18027228
#define CAP_IN1_ENABLE_reg_addr                                       "0xb8027228"
#define CAP_IN1_ENABLE_reg                                            0xb8027228
#define CAP_IN1_ENABLE_inst_addr                                      "0x008A"
#define CAP_IN1_ENABLE_inst                                           0x008A
#define CAP_IN1_ENABLE_in1_cap_enable_shift                           (0)
#define CAP_IN1_ENABLE_in1_cap_enable_mask                            (0x00000001)
#define CAP_IN1_ENABLE_in1_cap_enable(data)                           (0x00000001&(data))
#define CAP_IN1_ENABLE_get_in1_cap_enable(data)                       (0x00000001&(data))


#define CAP_REG_DOUBLBUFFER                                           0x1802722c
#define CAP_REG_DOUBLBUFFER_reg_addr                                  "0xb802722c"
#define CAP_REG_DOUBLBUFFER_reg                                       0xb802722c
#define CAP_REG_DOUBLBUFFER_inst_addr                                 "0x008B"
#define CAP_REG_DOUBLBUFFER_inst                                      0x008B
#define CAP_REG_DOUBLBUFFER_dummy1802722c_18_shift                    (18)
#define CAP_REG_DOUBLBUFFER_dummy1802722c_17_shift                    (17)
#define CAP_REG_DOUBLBUFFER_dummy1802722c_16_shift                    (16)
#define CAP_REG_DOUBLBUFFER_cap1_db_apply_shift                       (2)
#define CAP_REG_DOUBLBUFFER_cap1_db_sel_shift                         (1)
#define CAP_REG_DOUBLBUFFER_cap1_db_en_shift                          (0)
#define CAP_REG_DOUBLBUFFER_dummy1802722c_18_mask                     (0x00040000)
#define CAP_REG_DOUBLBUFFER_dummy1802722c_17_mask                     (0x00020000)
#define CAP_REG_DOUBLBUFFER_dummy1802722c_16_mask                     (0x00010000)
#define CAP_REG_DOUBLBUFFER_cap1_db_apply_mask                        (0x00000004)
#define CAP_REG_DOUBLBUFFER_cap1_db_sel_mask                          (0x00000002)
#define CAP_REG_DOUBLBUFFER_cap1_db_en_mask                           (0x00000001)
#define CAP_REG_DOUBLBUFFER_dummy1802722c_18(data)                    (0x00040000&((data)<<18))
#define CAP_REG_DOUBLBUFFER_dummy1802722c_17(data)                    (0x00020000&((data)<<17))
#define CAP_REG_DOUBLBUFFER_dummy1802722c_16(data)                    (0x00010000&((data)<<16))
#define CAP_REG_DOUBLBUFFER_cap1_db_apply(data)                       (0x00000004&((data)<<2))
#define CAP_REG_DOUBLBUFFER_cap1_db_sel(data)                         (0x00000002&((data)<<1))
#define CAP_REG_DOUBLBUFFER_cap1_db_en(data)                          (0x00000001&(data))
#define CAP_REG_DOUBLBUFFER_get_dummy1802722c_18(data)                ((0x00040000&(data))>>18)
#define CAP_REG_DOUBLBUFFER_get_dummy1802722c_17(data)                ((0x00020000&(data))>>17)
#define CAP_REG_DOUBLBUFFER_get_dummy1802722c_16(data)                ((0x00010000&(data))>>16)
#define CAP_REG_DOUBLBUFFER_get_cap1_db_apply(data)                   ((0x00000004&(data))>>2)
#define CAP_REG_DOUBLBUFFER_get_cap1_db_sel(data)                     ((0x00000002&(data))>>1)
#define CAP_REG_DOUBLBUFFER_get_cap1_db_en(data)                      (0x00000001&(data))


#define CAP_DDR_FIFOSTATUS                                            0x18027270
#define CAP_DDR_FIFOSTATUS_reg_addr                                   "0xb8027270"
#define CAP_DDR_FIFOSTATUS_reg                                        0xb8027270
#define CAP_DDR_FIFOSTATUS_inst_addr                                  "0x009C"
#define CAP_DDR_FIFOSTATUS_inst                                       0x009C
#define CAP_DDR_FIFOSTATUS_in1_cap_last_wr_flag_shift                 (20)
#define CAP_DDR_FIFOSTATUS_in1_fifofull_shift                         (19)
#define CAP_DDR_FIFOSTATUS_in1_fifoempty_shift                        (18)
#define CAP_DDR_FIFOSTATUS_in1_fifouf_shift                           (17)
#define CAP_DDR_FIFOSTATUS_in1_fifoof_shift                           (16)
#define CAP_DDR_FIFOSTATUS_dummy18027270_4_shift                      (4)
#define CAP_DDR_FIFOSTATUS_dummy18027270_3_shift                      (3)
#define CAP_DDR_FIFOSTATUS_dummy18027270_2_shift                      (2)
#define CAP_DDR_FIFOSTATUS_dummy18027270_1_shift                      (1)
#define CAP_DDR_FIFOSTATUS_dummy18027270_0_shift                      (0)
#define CAP_DDR_FIFOSTATUS_in1_cap_last_wr_flag_mask                  (0x00100000)
#define CAP_DDR_FIFOSTATUS_in1_fifofull_mask                          (0x00080000)
#define CAP_DDR_FIFOSTATUS_in1_fifoempty_mask                         (0x00040000)
#define CAP_DDR_FIFOSTATUS_in1_fifouf_mask                            (0x00020000)
#define CAP_DDR_FIFOSTATUS_in1_fifoof_mask                            (0x00010000)
#define CAP_DDR_FIFOSTATUS_dummy18027270_4_mask                       (0x00000010)
#define CAP_DDR_FIFOSTATUS_dummy18027270_3_mask                       (0x00000008)
#define CAP_DDR_FIFOSTATUS_dummy18027270_2_mask                       (0x00000004)
#define CAP_DDR_FIFOSTATUS_dummy18027270_1_mask                       (0x00000002)
#define CAP_DDR_FIFOSTATUS_dummy18027270_0_mask                       (0x00000001)
#define CAP_DDR_FIFOSTATUS_in1_cap_last_wr_flag(data)                 (0x00100000&((data)<<20))
#define CAP_DDR_FIFOSTATUS_in1_fifofull(data)                         (0x00080000&((data)<<19))
#define CAP_DDR_FIFOSTATUS_in1_fifoempty(data)                        (0x00040000&((data)<<18))
#define CAP_DDR_FIFOSTATUS_in1_fifouf(data)                           (0x00020000&((data)<<17))
#define CAP_DDR_FIFOSTATUS_in1_fifoof(data)                           (0x00010000&((data)<<16))
#define CAP_DDR_FIFOSTATUS_dummy18027270_4(data)                      (0x00000010&((data)<<4))
#define CAP_DDR_FIFOSTATUS_dummy18027270_3(data)                      (0x00000008&((data)<<3))
#define CAP_DDR_FIFOSTATUS_dummy18027270_2(data)                      (0x00000004&((data)<<2))
#define CAP_DDR_FIFOSTATUS_dummy18027270_1(data)                      (0x00000002&((data)<<1))
#define CAP_DDR_FIFOSTATUS_dummy18027270_0(data)                      (0x00000001&(data))
#define CAP_DDR_FIFOSTATUS_get_in1_cap_last_wr_flag(data)             ((0x00100000&(data))>>20)
#define CAP_DDR_FIFOSTATUS_get_in1_fifofull(data)                     ((0x00080000&(data))>>19)
#define CAP_DDR_FIFOSTATUS_get_in1_fifoempty(data)                    ((0x00040000&(data))>>18)
#define CAP_DDR_FIFOSTATUS_get_in1_fifouf(data)                       ((0x00020000&(data))>>17)
#define CAP_DDR_FIFOSTATUS_get_in1_fifoof(data)                       ((0x00010000&(data))>>16)
#define CAP_DDR_FIFOSTATUS_get_dummy18027270_4(data)                  ((0x00000010&(data))>>4)
#define CAP_DDR_FIFOSTATUS_get_dummy18027270_3(data)                  ((0x00000008&(data))>>3)
#define CAP_DDR_FIFOSTATUS_get_dummy18027270_2(data)                  ((0x00000004&(data))>>2)
#define CAP_DDR_FIFOSTATUS_get_dummy18027270_1(data)                  ((0x00000002&(data))>>1)
#define CAP_DDR_FIFOSTATUS_get_dummy18027270_0(data)                  (0x00000001&(data))


#define CAP_HELP_DEBUG_STATUS                                         0x18027274
#define CAP_HELP_DEBUG_STATUS_reg_addr                                "0xb8027274"
#define CAP_HELP_DEBUG_STATUS_reg                                     0xb8027274
#define CAP_HELP_DEBUG_STATUS_inst_addr                               "0x009D"
#define CAP_HELP_DEBUG_STATUS_inst                                    0x009D
#define CAP_HELP_DEBUG_STATUS_in1_drop_shift                          (18)
#define CAP_HELP_DEBUG_STATUS_in1_over_size_shift                     (17)
#define CAP_HELP_DEBUG_STATUS_in1_under_size_shift                    (16)
#define CAP_HELP_DEBUG_STATUS_dummy18027274_2_shift                   (2)
#define CAP_HELP_DEBUG_STATUS_dummy18027274_1_shift                   (1)
#define CAP_HELP_DEBUG_STATUS_dummy18027274_0_shift                   (0)
#define CAP_HELP_DEBUG_STATUS_in1_drop_mask                           (0x00040000)
#define CAP_HELP_DEBUG_STATUS_in1_over_size_mask                      (0x00020000)
#define CAP_HELP_DEBUG_STATUS_in1_under_size_mask                     (0x00010000)
#define CAP_HELP_DEBUG_STATUS_dummy18027274_2_mask                    (0x00000004)
#define CAP_HELP_DEBUG_STATUS_dummy18027274_1_mask                    (0x00000002)
#define CAP_HELP_DEBUG_STATUS_dummy18027274_0_mask                    (0x00000001)
#define CAP_HELP_DEBUG_STATUS_in1_drop(data)                          (0x00040000&((data)<<18))
#define CAP_HELP_DEBUG_STATUS_in1_over_size(data)                     (0x00020000&((data)<<17))
#define CAP_HELP_DEBUG_STATUS_in1_under_size(data)                    (0x00010000&((data)<<16))
#define CAP_HELP_DEBUG_STATUS_dummy18027274_2(data)                   (0x00000004&((data)<<2))
#define CAP_HELP_DEBUG_STATUS_dummy18027274_1(data)                   (0x00000002&((data)<<1))
#define CAP_HELP_DEBUG_STATUS_dummy18027274_0(data)                   (0x00000001&(data))
#define CAP_HELP_DEBUG_STATUS_get_in1_drop(data)                      ((0x00040000&(data))>>18)
#define CAP_HELP_DEBUG_STATUS_get_in1_over_size(data)                 ((0x00020000&(data))>>17)
#define CAP_HELP_DEBUG_STATUS_get_in1_under_size(data)                ((0x00010000&(data))>>16)
#define CAP_HELP_DEBUG_STATUS_get_dummy18027274_2(data)               ((0x00000004&(data))>>2)
#define CAP_HELP_DEBUG_STATUS_get_dummy18027274_1(data)               ((0x00000002&(data))>>1)
#define CAP_HELP_DEBUG_STATUS_get_dummy18027274_0(data)               (0x00000001&(data))


#define CAPMAIN_BOUNDARYADDR1                                         0x18027278
#define CAPMAIN_BOUNDARYADDR1_reg_addr                                "0xb8027278"
#define CAPMAIN_BOUNDARYADDR1_reg                                     0xb8027278
#define CAPMAIN_BOUNDARYADDR1_inst_addr                               "0x009E"
#define CAPMAIN_BOUNDARYADDR1_inst                                    0x009E
#define CAPMAIN_BOUNDARYADDR1_in1_cap_downlimit_adr_shift             (3)
#define CAPMAIN_BOUNDARYADDR1_in1_cap_downlimit_adr_mask              (0x7FFFFFF8)
#define CAPMAIN_BOUNDARYADDR1_in1_cap_downlimit_adr(data)             (0x7FFFFFF8&((data)<<3))
#define CAPMAIN_BOUNDARYADDR1_get_in1_cap_downlimit_adr(data)         ((0x7FFFFFF8&(data))>>3)


#define CAPMAIN_BOUNDARYADDR2                                         0x1802727c
#define CAPMAIN_BOUNDARYADDR2_reg_addr                                "0xb802727c"
#define CAPMAIN_BOUNDARYADDR2_reg                                     0xb802727c
#define CAPMAIN_BOUNDARYADDR2_inst_addr                               "0x009F"
#define CAPMAIN_BOUNDARYADDR2_inst                                    0x009F
#define CAPMAIN_BOUNDARYADDR2_in1_cap_uplimit_adr_shift               (3)
#define CAPMAIN_BOUNDARYADDR2_in1_cap_uplimit_adr_mask                (0x7FFFFFF8)
#define CAPMAIN_BOUNDARYADDR2_in1_cap_uplimit_adr(data)               (0x7FFFFFF8&((data)<<3))
#define CAPMAIN_BOUNDARYADDR2_get_in1_cap_uplimit_adr(data)           ((0x7FFFFFF8&(data))>>3)


#define DI1CAP_WRRD_BOUNDARYADD_STATUS                                0x18027280
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_reg_addr                       "0xb8027280"
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_reg                            0xb8027280
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_inst_addr                      "0x00A0"
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_inst                           0x00A0
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_in1_cap_downlimit_ov_shift     (1)
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_in1_cap_uplimit_ov_shift       (0)
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_in1_cap_downlimit_ov_mask      (0x00000002)
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_in1_cap_uplimit_ov_mask        (0x00000001)
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_in1_cap_downlimit_ov(data)     (0x00000002&((data)<<1))
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_in1_cap_uplimit_ov(data)       (0x00000001&(data))
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_get_in1_cap_downlimit_ov(data) ((0x00000002&(data))>>1)
#define DI1CAP_WRRD_BOUNDARYADD_STATUS_get_in1_cap_uplimit_ov(data)   (0x00000001&(data))


#define CAPSUB_BOUNDARYADDR1                                          0x18027284
#define CAPSUB_BOUNDARYADDR1_reg_addr                                 "0xb8027284"
#define CAPSUB_BOUNDARYADDR1_reg                                      0xb8027284
#define CAPSUB_BOUNDARYADDR1_inst_addr                                "0x00A1"
#define CAPSUB_BOUNDARYADDR1_inst                                     0x00A1


#define CAPSUB_BOUNDARYADDR2                                          0x18027288
#define CAPSUB_BOUNDARYADDR2_reg_addr                                 "0xb8027288"
#define CAPSUB_BOUNDARYADDR2_reg                                      0xb8027288
#define CAPSUB_BOUNDARYADDR2_inst_addr                                "0x00A2"
#define CAPSUB_BOUNDARYADDR2_inst                                     0x00A2


#define DI2CAP_WRRD_BOUNDARYADD_STATUS                                0x1802728c
#define DI2CAP_WRRD_BOUNDARYADD_STATUS_reg_addr                       "0xb802728c"
#define DI2CAP_WRRD_BOUNDARYADD_STATUS_reg                            0xb802728c
#define DI2CAP_WRRD_BOUNDARYADD_STATUS_inst_addr                      "0x00A3"
#define DI2CAP_WRRD_BOUNDARYADD_STATUS_inst                           0x00A3


#define CAP_IE_WD_CTRL                                                0x18027290
#define CAP_IE_WD_CTRL_reg_addr                                       "0xb8027290"
#define CAP_IE_WD_CTRL_reg                                            0xb8027290
#define CAP_IE_WD_CTRL_inst_addr                                      "0x00A4"
#define CAP_IE_WD_CTRL_inst                                           0x00A4
#define CAP_IE_WD_CTRL_in1_fifoerr_ie_shift                           (20)
#define CAP_IE_WD_CTRL_in1_cap_last_wr_ie_shift                       (19)
#define CAP_IE_WD_CTRL_in1_fifoerr_wde_shift                          (18)
#define CAP_IE_WD_CTRL_in1_cap_last_wr_wde_shift                      (17)
#define CAP_IE_WD_CTRL_wd_to_main_shift                               (16)
#define CAP_IE_WD_CTRL_dummy18027290_4_shift                          (4)
#define CAP_IE_WD_CTRL_dummy18027290_3_shift                          (3)
#define CAP_IE_WD_CTRL_dummy18027290_2_shift                          (2)
#define CAP_IE_WD_CTRL_dummy18027290_1_shift                          (1)
#define CAP_IE_WD_CTRL_dummy18027290_0_shift                          (0)
#define CAP_IE_WD_CTRL_in1_fifoerr_ie_mask                            (0x00100000)
#define CAP_IE_WD_CTRL_in1_cap_last_wr_ie_mask                        (0x00080000)
#define CAP_IE_WD_CTRL_in1_fifoerr_wde_mask                           (0x00040000)
#define CAP_IE_WD_CTRL_in1_cap_last_wr_wde_mask                       (0x00020000)
#define CAP_IE_WD_CTRL_wd_to_main_mask                                (0x00010000)
#define CAP_IE_WD_CTRL_dummy18027290_4_mask                           (0x00000010)
#define CAP_IE_WD_CTRL_dummy18027290_3_mask                           (0x00000008)
#define CAP_IE_WD_CTRL_dummy18027290_2_mask                           (0x00000004)
#define CAP_IE_WD_CTRL_dummy18027290_1_mask                           (0x00000002)
#define CAP_IE_WD_CTRL_dummy18027290_0_mask                           (0x00000001)
#define CAP_IE_WD_CTRL_in1_fifoerr_ie(data)                           (0x00100000&((data)<<20))
#define CAP_IE_WD_CTRL_in1_cap_last_wr_ie(data)                       (0x00080000&((data)<<19))
#define CAP_IE_WD_CTRL_in1_fifoerr_wde(data)                          (0x00040000&((data)<<18))
#define CAP_IE_WD_CTRL_in1_cap_last_wr_wde(data)                      (0x00020000&((data)<<17))
#define CAP_IE_WD_CTRL_wd_to_main(data)                               (0x00010000&((data)<<16))
#define CAP_IE_WD_CTRL_dummy18027290_4(data)                          (0x00000010&((data)<<4))
#define CAP_IE_WD_CTRL_dummy18027290_3(data)                          (0x00000008&((data)<<3))
#define CAP_IE_WD_CTRL_dummy18027290_2(data)                          (0x00000004&((data)<<2))
#define CAP_IE_WD_CTRL_dummy18027290_1(data)                          (0x00000002&((data)<<1))
#define CAP_IE_WD_CTRL_dummy18027290_0(data)                          (0x00000001&(data))
#define CAP_IE_WD_CTRL_get_in1_fifoerr_ie(data)                       ((0x00100000&(data))>>20)
#define CAP_IE_WD_CTRL_get_in1_cap_last_wr_ie(data)                   ((0x00080000&(data))>>19)
#define CAP_IE_WD_CTRL_get_in1_fifoerr_wde(data)                      ((0x00040000&(data))>>18)
#define CAP_IE_WD_CTRL_get_in1_cap_last_wr_wde(data)                  ((0x00020000&(data))>>17)
#define CAP_IE_WD_CTRL_get_wd_to_main(data)                           ((0x00010000&(data))>>16)
#define CAP_IE_WD_CTRL_get_dummy18027290_4(data)                      ((0x00000010&(data))>>4)
#define CAP_IE_WD_CTRL_get_dummy18027290_3(data)                      ((0x00000008&(data))>>3)
#define CAP_IE_WD_CTRL_get_dummy18027290_2(data)                      ((0x00000004&(data))>>2)
#define CAP_IE_WD_CTRL_get_dummy18027290_1(data)                      ((0x00000002&(data))>>1)
#define CAP_IE_WD_CTRL_get_dummy18027290_0(data)                      (0x00000001&(data))


#define CAPMAIN_SBS_VSD_CAP_CTRL                                      0x18027294
#define CAPMAIN_SBS_VSD_CAP_CTRL_reg_addr                             "0xb8027294"
#define CAPMAIN_SBS_VSD_CAP_CTRL_reg                                  0xb8027294
#define CAPMAIN_SBS_VSD_CAP_CTRL_inst_addr                            "0x00A5"
#define CAPMAIN_SBS_VSD_CAP_CTRL_inst                                 0x00A5
#define CAPMAIN_SBS_VSD_CAP_CTRL_in1_sbs_vsd_en_shift                 (0)
#define CAPMAIN_SBS_VSD_CAP_CTRL_in1_sbs_vsd_en_mask                  (0x00000001)
#define CAPMAIN_SBS_VSD_CAP_CTRL_in1_sbs_vsd_en(data)                 (0x00000001&(data))
#define CAPMAIN_SBS_VSD_CAP_CTRL_get_in1_sbs_vsd_en(data)             (0x00000001&(data))


#define CAPMAIN_SBS_VSD_CAP_OFFSET                                    0x18027298
#define CAPMAIN_SBS_VSD_CAP_OFFSET_reg_addr                           "0xb8027298"
#define CAPMAIN_SBS_VSD_CAP_OFFSET_reg                                0xb8027298
#define CAPMAIN_SBS_VSD_CAP_OFFSET_inst_addr                          "0x00A6"
#define CAPMAIN_SBS_VSD_CAP_OFFSET_inst                               0x00A6
#define CAPMAIN_SBS_VSD_CAP_OFFSET_in1_lr_offset_shift                (3)
#define CAPMAIN_SBS_VSD_CAP_OFFSET_in1_lr_offset_mask                 (0x7FFFFFF8)
#define CAPMAIN_SBS_VSD_CAP_OFFSET_in1_lr_offset(data)                (0x7FFFFFF8&((data)<<3))
#define CAPMAIN_SBS_VSD_CAP_OFFSET_get_in1_lr_offset(data)            ((0x7FFFFFF8&(data))>>3)


#define DISPM_CRC_CTRL                                                0x180272a0
#define DISPM_CRC_CTRL_reg_addr                                       "0xb80272a0"
#define DISPM_CRC_CTRL_reg                                            0xb80272a0
#define DISPM_CRC_CTRL_inst_addr                                      "0x00A8"
#define DISPM_CRC_CTRL_inst                                           0x00A8
#define DISPM_CRC_CTRL_crc_comp_error_int_shift                       (14)
#define DISPM_CRC_CTRL_dynamic_crc_cmp_en_shift                       (13)
#define DISPM_CRC_CTRL_crc_bit_sel_shift                              (10)
#define DISPM_CRC_CTRL_disp_crc_3d_en_shift                           (7)
#define DISPM_CRC_CTRL_disp_crc_conti_shift                           (5)
#define DISPM_CRC_CTRL_disp_crc_start_shift                           (4)
#define DISPM_CRC_CTRL_cap_crc_3d_en_shift                            (3)
#define DISPM_CRC_CTRL_cap_crc_conti_shift                            (1)
#define DISPM_CRC_CTRL_cap_crc_start_shift                            (0)
#define DISPM_CRC_CTRL_crc_comp_error_int_mask                        (0x00004000)
#define DISPM_CRC_CTRL_dynamic_crc_cmp_en_mask                        (0x00002000)
#define DISPM_CRC_CTRL_crc_bit_sel_mask                               (0x00000C00)
#define DISPM_CRC_CTRL_disp_crc_3d_en_mask                            (0x00000080)
#define DISPM_CRC_CTRL_disp_crc_conti_mask                            (0x00000020)
#define DISPM_CRC_CTRL_disp_crc_start_mask                            (0x00000010)
#define DISPM_CRC_CTRL_cap_crc_3d_en_mask                             (0x00000008)
#define DISPM_CRC_CTRL_cap_crc_conti_mask                             (0x00000002)
#define DISPM_CRC_CTRL_cap_crc_start_mask                             (0x00000001)
#define DISPM_CRC_CTRL_crc_comp_error_int(data)                       (0x00004000&((data)<<14))
#define DISPM_CRC_CTRL_dynamic_crc_cmp_en(data)                       (0x00002000&((data)<<13))
#define DISPM_CRC_CTRL_crc_bit_sel(data)                              (0x00000C00&((data)<<10))
#define DISPM_CRC_CTRL_disp_crc_3d_en(data)                           (0x00000080&((data)<<7))
#define DISPM_CRC_CTRL_disp_crc_conti(data)                           (0x00000020&((data)<<5))
#define DISPM_CRC_CTRL_disp_crc_start(data)                           (0x00000010&((data)<<4))
#define DISPM_CRC_CTRL_cap_crc_3d_en(data)                            (0x00000008&((data)<<3))
#define DISPM_CRC_CTRL_cap_crc_conti(data)                            (0x00000002&((data)<<1))
#define DISPM_CRC_CTRL_cap_crc_start(data)                            (0x00000001&(data))
#define DISPM_CRC_CTRL_get_crc_comp_error_int(data)                   ((0x00004000&(data))>>14)
#define DISPM_CRC_CTRL_get_dynamic_crc_cmp_en(data)                   ((0x00002000&(data))>>13)
#define DISPM_CRC_CTRL_get_crc_bit_sel(data)                          ((0x00000C00&(data))>>10)
#define DISPM_CRC_CTRL_get_disp_crc_3d_en(data)                       ((0x00000080&(data))>>7)
#define DISPM_CRC_CTRL_get_disp_crc_conti(data)                       ((0x00000020&(data))>>5)
#define DISPM_CRC_CTRL_get_disp_crc_start(data)                       ((0x00000010&(data))>>4)
#define DISPM_CRC_CTRL_get_cap_crc_3d_en(data)                        ((0x00000008&(data))>>3)
#define DISPM_CRC_CTRL_get_cap_crc_conti(data)                        ((0x00000002&(data))>>1)
#define DISPM_CRC_CTRL_get_cap_crc_start(data)                        (0x00000001&(data))


#define DISPM_CRC_STATUS                                              0x180272a4
#define DISPM_CRC_STATUS_reg_addr                                     "0xb80272a4"
#define DISPM_CRC_STATUS_reg                                          0xb80272a4
#define DISPM_CRC_STATUS_inst_addr                                    "0x00A9"
#define DISPM_CRC_STATUS_inst                                         0x00A9
#define DISPM_CRC_STATUS_match_buffer_shift                           (16)
#define DISPM_CRC_STATUS_crc_comp_error_flag_shift                    (0)
#define DISPM_CRC_STATUS_match_buffer_mask                            (0x00030000)
#define DISPM_CRC_STATUS_crc_comp_error_flag_mask                     (0x00000001)
#define DISPM_CRC_STATUS_match_buffer(data)                           (0x00030000&((data)<<16))
#define DISPM_CRC_STATUS_crc_comp_error_flag(data)                    (0x00000001&(data))
#define DISPM_CRC_STATUS_get_match_buffer(data)                       ((0x00030000&(data))>>16)
#define DISPM_CRC_STATUS_get_crc_comp_error_flag(data)                (0x00000001&(data))


#define CRC_MASK                                                      0x180272a8
#define CRC_MASK_reg_addr                                             "0xb80272a8"
#define CRC_MASK_reg                                                  0xb80272a8
#define CRC_MASK_inst_addr                                            "0x00AA"
#define CRC_MASK_inst                                                 0x00AA
#define CRC_MASK_crc_mask_shift                                       (0)
#define CRC_MASK_crc_mask_mask                                        (0xFFFFFFFF)
#define CRC_MASK_crc_mask(data)                                       (0xFFFFFFFF&(data))
#define CRC_MASK_get_crc_mask(data)                                   (0xFFFFFFFF&(data))


#define CAP_L_CRC_RESULT                                              0x180272ac
#define CAP_L_CRC_RESULT_reg_addr                                     "0xb80272ac"
#define CAP_L_CRC_RESULT_reg                                          0xb80272ac
#define CAP_L_CRC_RESULT_inst_addr                                    "0x00AB"
#define CAP_L_CRC_RESULT_inst                                         0x00AB
#define CAP_L_CRC_RESULT_cap_l_crc_result_shift                       (0)
#define CAP_L_CRC_RESULT_cap_l_crc_result_mask                        (0xFFFFFFFF)
#define CAP_L_CRC_RESULT_cap_l_crc_result(data)                       (0xFFFFFFFF&(data))
#define CAP_L_CRC_RESULT_get_cap_l_crc_result(data)                   (0xFFFFFFFF&(data))


#define CAP_R_CRC_RESULT                                              0x180272b0
#define CAP_R_CRC_RESULT_reg_addr                                     "0xb80272b0"
#define CAP_R_CRC_RESULT_reg                                          0xb80272b0
#define CAP_R_CRC_RESULT_inst_addr                                    "0x00AC"
#define CAP_R_CRC_RESULT_inst                                         0x00AC
#define CAP_R_CRC_RESULT_cap_r_crc_result_shift                       (0)
#define CAP_R_CRC_RESULT_cap_r_crc_result_mask                        (0xFFFFFFFF)
#define CAP_R_CRC_RESULT_cap_r_crc_result(data)                       (0xFFFFFFFF&(data))
#define CAP_R_CRC_RESULT_get_cap_r_crc_result(data)                   (0xFFFFFFFF&(data))


#define DISP_L_CRC_RESULT                                             0x180272b4
#define DISP_L_CRC_RESULT_reg_addr                                    "0xb80272b4"
#define DISP_L_CRC_RESULT_reg                                         0xb80272b4
#define DISP_L_CRC_RESULT_inst_addr                                   "0x00AD"
#define DISP_L_CRC_RESULT_inst                                        0x00AD
#define DISP_L_CRC_RESULT_disp_l_crc_result_shift                     (0)
#define DISP_L_CRC_RESULT_disp_l_crc_result_mask                      (0xFFFFFFFF)
#define DISP_L_CRC_RESULT_disp_l_crc_result(data)                     (0xFFFFFFFF&(data))
#define DISP_L_CRC_RESULT_get_disp_l_crc_result(data)                 (0xFFFFFFFF&(data))


#define DISPLAY_R_CRC_RESULT                                          0x180272b8
#define DISPLAY_R_CRC_RESULT_reg_addr                                 "0xb80272b8"
#define DISPLAY_R_CRC_RESULT_reg                                      0xb80272b8
#define DISPLAY_R_CRC_RESULT_inst_addr                                "0x00AE"
#define DISPLAY_R_CRC_RESULT_inst                                     0x00AE
#define DISPLAY_R_CRC_RESULT_disp_r_crc_result_shift                  (0)
#define DISPLAY_R_CRC_RESULT_disp_r_crc_result_mask                   (0xFFFFFFFF)
#define DISPLAY_R_CRC_RESULT_disp_r_crc_result(data)                  (0xFFFFFFFF&(data))
#define DISPLAY_R_CRC_RESULT_get_disp_r_crc_result(data)              (0xFFFFFFFF&(data))


#define CAP_DMA_RATE_CTRL                                             0x180272c0
#define CAP_DMA_RATE_CTRL_reg_addr                                    "0xb80272c0"
#define CAP_DMA_RATE_CTRL_reg                                         0xb80272c0
#define CAP_DMA_RATE_CTRL_inst_addr                                   "0x00B0"
#define CAP_DMA_RATE_CTRL_inst                                        0x00B0
#define CAP_DMA_RATE_CTRL_in1_rate_en_shift                           (0)
#define CAP_DMA_RATE_CTRL_in1_rate_en_mask                            (0x00000001)
#define CAP_DMA_RATE_CTRL_in1_rate_en(data)                           (0x00000001&(data))
#define CAP_DMA_RATE_CTRL_get_in1_rate_en(data)                       (0x00000001&(data))


#define CAPTURE_RATE                                                  0x180272c4
#define CAPTURE_RATE_reg_addr                                         "0xb80272c4"
#define CAPTURE_RATE_reg                                              0xb80272c4
#define CAPTURE_RATE_inst_addr                                        "0x00B1"
#define CAPTURE_RATE_inst                                             0x00B1
#define CAPTURE_RATE_in1_rate_shift                                   (0)
#define CAPTURE_RATE_in1_rate_mask                                    (0xFFFFFFFF)
#define CAPTURE_RATE_in1_rate(data)                                   (0xFFFFFFFF&(data))
#define CAPTURE_RATE_get_in1_rate(data)                               (0xFFFFFFFF&(data))


#define CAPTURE_BYTE_SWAP                                             0x180272c8
#define CAPTURE_BYTE_SWAP_reg_addr                                    "0xb80272c8"
#define CAPTURE_BYTE_SWAP_reg                                         0xb80272c8
#define CAPTURE_BYTE_SWAP_inst_addr                                   "0x00B2"
#define CAPTURE_BYTE_SWAP_inst                                        0x00B2
#define CAPTURE_BYTE_SWAP_dummy180272c8_19_shift                      (19)
#define CAPTURE_BYTE_SWAP_dummy180272c8_18_shift                      (18)
#define CAPTURE_BYTE_SWAP_dummy180272c8_17_shift                      (17)
#define CAPTURE_BYTE_SWAP_dummy180272c8_16_shift                      (16)
#define CAPTURE_BYTE_SWAP_in1_8byte_swap_shift                        (3)
#define CAPTURE_BYTE_SWAP_in1_4byte_swap_shift                        (2)
#define CAPTURE_BYTE_SWAP_in1_2byte_swap_shift                        (1)
#define CAPTURE_BYTE_SWAP_in1_1byte_swap_shift                        (0)
#define CAPTURE_BYTE_SWAP_dummy180272c8_19_mask                       (0x00080000)
#define CAPTURE_BYTE_SWAP_dummy180272c8_18_mask                       (0x00040000)
#define CAPTURE_BYTE_SWAP_dummy180272c8_17_mask                       (0x00020000)
#define CAPTURE_BYTE_SWAP_dummy180272c8_16_mask                       (0x00010000)
#define CAPTURE_BYTE_SWAP_in1_8byte_swap_mask                         (0x00000008)
#define CAPTURE_BYTE_SWAP_in1_4byte_swap_mask                         (0x00000004)
#define CAPTURE_BYTE_SWAP_in1_2byte_swap_mask                         (0x00000002)
#define CAPTURE_BYTE_SWAP_in1_1byte_swap_mask                         (0x00000001)
#define CAPTURE_BYTE_SWAP_dummy180272c8_19(data)                      (0x00080000&((data)<<19))
#define CAPTURE_BYTE_SWAP_dummy180272c8_18(data)                      (0x00040000&((data)<<18))
#define CAPTURE_BYTE_SWAP_dummy180272c8_17(data)                      (0x00020000&((data)<<17))
#define CAPTURE_BYTE_SWAP_dummy180272c8_16(data)                      (0x00010000&((data)<<16))
#define CAPTURE_BYTE_SWAP_in1_8byte_swap(data)                        (0x00000008&((data)<<3))
#define CAPTURE_BYTE_SWAP_in1_4byte_swap(data)                        (0x00000004&((data)<<2))
#define CAPTURE_BYTE_SWAP_in1_2byte_swap(data)                        (0x00000002&((data)<<1))
#define CAPTURE_BYTE_SWAP_in1_1byte_swap(data)                        (0x00000001&(data))
#define CAPTURE_BYTE_SWAP_get_dummy180272c8_19(data)                  ((0x00080000&(data))>>19)
#define CAPTURE_BYTE_SWAP_get_dummy180272c8_18(data)                  ((0x00040000&(data))>>18)
#define CAPTURE_BYTE_SWAP_get_dummy180272c8_17(data)                  ((0x00020000&(data))>>17)
#define CAPTURE_BYTE_SWAP_get_dummy180272c8_16(data)                  ((0x00010000&(data))>>16)
#define CAPTURE_BYTE_SWAP_get_in1_8byte_swap(data)                    ((0x00000008&(data))>>3)
#define CAPTURE_BYTE_SWAP_get_in1_4byte_swap(data)                    ((0x00000004&(data))>>2)
#define CAPTURE_BYTE_SWAP_get_in1_2byte_swap(data)                    ((0x00000002&(data))>>1)
#define CAPTURE_BYTE_SWAP_get_in1_1byte_swap(data)                    (0x00000001&(data))


#define SMOOTH_TOG_CTRL_0                                             0x180272f0
#define SMOOTH_TOG_CTRL_0_reg_addr                                    "0xb80272f0"
#define SMOOTH_TOG_CTRL_0_reg                                         0xb80272f0
#define SMOOTH_TOG_CTRL_0_inst_addr                                   "0x00BC"
#define SMOOTH_TOG_CTRL_0_inst                                        0x00BC
#define SMOOTH_TOG_CTRL_0_dispd_fs_3d_en_shift                        (5)
#define SMOOTH_TOG_CTRL_0_dispi_fs_3d_en_shift                        (4)
#define SMOOTH_TOG_CTRL_0_dummy180272f0_2_shift                       (2)
#define SMOOTH_TOG_CTRL_0_dummy180272f0_1_shift                       (1)
#define SMOOTH_TOG_CTRL_0_dummy180272f0_0_shift                       (0)
#define SMOOTH_TOG_CTRL_0_dispd_fs_3d_en_mask                         (0x00000020)
#define SMOOTH_TOG_CTRL_0_dispi_fs_3d_en_mask                         (0x00000010)
#define SMOOTH_TOG_CTRL_0_dummy180272f0_2_mask                        (0x00000004)
#define SMOOTH_TOG_CTRL_0_dummy180272f0_1_mask                        (0x00000002)
#define SMOOTH_TOG_CTRL_0_dummy180272f0_0_mask                        (0x00000001)
#define SMOOTH_TOG_CTRL_0_dispd_fs_3d_en(data)                        (0x00000020&((data)<<5))
#define SMOOTH_TOG_CTRL_0_dispi_fs_3d_en(data)                        (0x00000010&((data)<<4))
#define SMOOTH_TOG_CTRL_0_dummy180272f0_2(data)                       (0x00000004&((data)<<2))
#define SMOOTH_TOG_CTRL_0_dummy180272f0_1(data)                       (0x00000002&((data)<<1))
#define SMOOTH_TOG_CTRL_0_dummy180272f0_0(data)                       (0x00000001&(data))
#define SMOOTH_TOG_CTRL_0_get_dispd_fs_3d_en(data)                    ((0x00000020&(data))>>5)
#define SMOOTH_TOG_CTRL_0_get_dispi_fs_3d_en(data)                    ((0x00000010&(data))>>4)
#define SMOOTH_TOG_CTRL_0_get_dummy180272f0_2(data)                   ((0x00000004&(data))>>2)
#define SMOOTH_TOG_CTRL_0_get_dummy180272f0_1(data)                   ((0x00000002&(data))>>1)
#define SMOOTH_TOG_CTRL_0_get_dummy180272f0_0(data)                   (0x00000001&(data))


#define SMOOTH_TOG_STATUS_0                                           0x180272f4
#define SMOOTH_TOG_STATUS_0_reg_addr                                  "0xb80272f4"
#define SMOOTH_TOG_STATUS_0_reg                                       0xb80272f4
#define SMOOTH_TOG_STATUS_0_inst_addr                                 "0x00BD"
#define SMOOTH_TOG_STATUS_0_inst                                      0x00BD
#define SMOOTH_TOG_STATUS_0_md_reg_is_db_shift                        (1)
#define SMOOTH_TOG_STATUS_0_im_reg_is_db_shift                        (0)
#define SMOOTH_TOG_STATUS_0_md_reg_is_db_mask                         (0x00000002)
#define SMOOTH_TOG_STATUS_0_im_reg_is_db_mask                         (0x00000001)
#define SMOOTH_TOG_STATUS_0_md_reg_is_db(data)                        (0x00000002&((data)<<1))
#define SMOOTH_TOG_STATUS_0_im_reg_is_db(data)                        (0x00000001&(data))
#define SMOOTH_TOG_STATUS_0_get_md_reg_is_db(data)                    ((0x00000002&(data))>>1)
#define SMOOTH_TOG_STATUS_0_get_im_reg_is_db(data)                    (0x00000001&(data))


#define DDR_MAINPREVSTART                                             0x18027300
#define DDR_MAINPREVSTART_reg_addr                                    "0xb8027300"
#define DDR_MAINPREVSTART_reg                                         0xb8027300
#define DDR_MAINPREVSTART_inst_addr                                   "0x00C0"
#define DDR_MAINPREVSTART_inst                                        0x00C0
#define DDR_MAINPREVSTART_main_rgb2gbr_fmt_shift                      (14)
#define DDR_MAINPREVSTART_main_usb2vga_en_shift                       (13)
#define DDR_MAINPREVSTART_main_usb2vga_fmt_shift                      (12)
#define DDR_MAINPREVSTART_main_pre_rd_v_start_shift                   (0)
#define DDR_MAINPREVSTART_main_rgb2gbr_fmt_mask                       (0x00004000)
#define DDR_MAINPREVSTART_main_usb2vga_en_mask                        (0x00002000)
#define DDR_MAINPREVSTART_main_usb2vga_fmt_mask                       (0x00001000)
#define DDR_MAINPREVSTART_main_pre_rd_v_start_mask                    (0x000007FF)
#define DDR_MAINPREVSTART_main_rgb2gbr_fmt(data)                      (0x00004000&((data)<<14))
#define DDR_MAINPREVSTART_main_usb2vga_en(data)                       (0x00002000&((data)<<13))
#define DDR_MAINPREVSTART_main_usb2vga_fmt(data)                      (0x00001000&((data)<<12))
#define DDR_MAINPREVSTART_main_pre_rd_v_start(data)                   (0x000007FF&(data))
#define DDR_MAINPREVSTART_get_main_rgb2gbr_fmt(data)                  ((0x00004000&(data))>>14)
#define DDR_MAINPREVSTART_get_main_usb2vga_en(data)                   ((0x00002000&(data))>>13)
#define DDR_MAINPREVSTART_get_main_usb2vga_fmt(data)                  ((0x00001000&(data))>>12)
#define DDR_MAINPREVSTART_get_main_pre_rd_v_start(data)               (0x000007FF&(data))


#define DDR_MAINNUMWTL                                                0x18027304
#define DDR_MAINNUMWTL_reg_addr                                       "0xb8027304"
#define DDR_MAINNUMWTL_reg                                            0xb8027304
#define DDR_MAINNUMWTL_inst_addr                                      "0x00C1"
#define DDR_MAINNUMWTL_inst                                           0x00C1
#define DDR_MAINNUMWTL_main_pixel_num_shift                           (8)
#define DDR_MAINNUMWTL_main_wtlvl_shift                               (0)
#define DDR_MAINNUMWTL_main_pixel_num_mask                            (0x003FFF00)
#define DDR_MAINNUMWTL_main_wtlvl_mask                                (0x000000FF)
#define DDR_MAINNUMWTL_main_pixel_num(data)                           (0x003FFF00&((data)<<8))
#define DDR_MAINNUMWTL_main_wtlvl(data)                               (0x000000FF&(data))
#define DDR_MAINNUMWTL_get_main_pixel_num(data)                       ((0x003FFF00&(data))>>8)
#define DDR_MAINNUMWTL_get_main_wtlvl(data)                           (0x000000FF&(data))


#define DDR_MAINRDNUMLENREM                                           0x18027308
#define DDR_MAINRDNUMLENREM_reg_addr                                  "0xb8027308"
#define DDR_MAINRDNUMLENREM_reg                                       0xb8027308
#define DDR_MAINRDNUMLENREM_inst_addr                                 "0x00C2"
#define DDR_MAINRDNUMLENREM_inst                                      0x00C2
#define DDR_MAINRDNUMLENREM_main_read_num_shift                       (16)
#define DDR_MAINRDNUMLENREM_main_read_len_shift                       (8)
#define DDR_MAINRDNUMLENREM_main_read_remain_shift                    (0)
#define DDR_MAINRDNUMLENREM_main_read_num_mask                        (0xFFFF0000)
#define DDR_MAINRDNUMLENREM_main_read_len_mask                        (0x00007F00)
#define DDR_MAINRDNUMLENREM_main_read_remain_mask                     (0x0000007F)
#define DDR_MAINRDNUMLENREM_main_read_num(data)                       (0xFFFF0000&((data)<<16))
#define DDR_MAINRDNUMLENREM_main_read_len(data)                       (0x00007F00&((data)<<8))
#define DDR_MAINRDNUMLENREM_main_read_remain(data)                    (0x0000007F&(data))
#define DDR_MAINRDNUMLENREM_get_main_read_num(data)                   ((0xFFFF0000&(data))>>16)
#define DDR_MAINRDNUMLENREM_get_main_read_len(data)                   ((0x00007F00&(data))>>8)
#define DDR_MAINRDNUMLENREM_get_main_read_remain(data)                (0x0000007F&(data))


#define DDR_MAINADDR                                                  0x1802730c
#define DDR_MAINADDR_reg_addr                                         "0xb802730c"
#define DDR_MAINADDR_reg                                              0xb802730c
#define DDR_MAINADDR_inst_addr                                        "0x00C3"
#define DDR_MAINADDR_inst                                             0x00C3
#define DDR_MAINADDR_main_read_addr_shift                             (3)
#define DDR_MAINADDR_main_read_addr_mask                              (0x7FFFFFF8)
#define DDR_MAINADDR_main_read_addr(data)                             (0x7FFFFFF8&((data)<<3))
#define DDR_MAINADDR_get_main_read_addr(data)                         ((0x7FFFFFF8&(data))>>3)


#define DDR_MAINADDRDROPBITS                                          0x18027310
#define DDR_MAINADDRDROPBITS_reg_addr                                 "0xb8027310"
#define DDR_MAINADDRDROPBITS_reg                                      0xb8027310
#define DDR_MAINADDRDROPBITS_inst_addr                                "0x00C4"
#define DDR_MAINADDRDROPBITS_inst                                     0x00C4
#define DDR_MAINADDRDROPBITS_main_addr_drop_shift                     (0)
#define DDR_MAINADDRDROPBITS_main_addr_drop_mask                      (0x0000FFFF)
#define DDR_MAINADDRDROPBITS_main_addr_drop(data)                     (0x0000FFFF&(data))
#define DDR_MAINADDRDROPBITS_get_main_addr_drop(data)                 (0x0000FFFF&(data))


#define DDR_MAINLINESTEP                                              0x18027314
#define DDR_MAINLINESTEP_reg_addr                                     "0xb8027314"
#define DDR_MAINLINESTEP_reg                                          0xb8027314
#define DDR_MAINLINESTEP_inst_addr                                    "0x00C5"
#define DDR_MAINLINESTEP_inst                                         0x00C5
#define DDR_MAINLINESTEP_main_line_step_shift                         (3)
#define DDR_MAINLINESTEP_main_line_step_mask                          (0x7FFFFFF8)
#define DDR_MAINLINESTEP_main_line_step(data)                         (0x7FFFFFF8&((data)<<3))
#define DDR_MAINLINESTEP_get_main_line_step(data)                     ((0x7FFFFFF8&(data))>>3)


#define DDR_MAINBLKSTEP                                               0x18027318
#define DDR_MAINBLKSTEP_reg_addr                                      "0xb8027318"
#define DDR_MAINBLKSTEP_reg                                           0xb8027318
#define DDR_MAINBLKSTEP_inst_addr                                     "0x00C6"
#define DDR_MAINBLKSTEP_inst                                          0x00C6
#define DDR_MAINBLKSTEP_main_block_step_shift                         (3)
#define DDR_MAINBLKSTEP_main_block_step_mask                          (0x7FFFFFF8)
#define DDR_MAINBLKSTEP_main_block_step(data)                         (0x7FFFFFF8&((data)<<3))
#define DDR_MAINBLKSTEP_get_main_block_step(data)                     ((0x7FFFFFF8&(data))>>3)


#define DDR_MAIN2NDADDR                                               0x1802731c
#define DDR_MAIN2NDADDR_reg_addr                                      "0xb802731c"
#define DDR_MAIN2NDADDR_reg                                           0xb802731c
#define DDR_MAIN2NDADDR_inst_addr                                     "0x00C7"
#define DDR_MAIN2NDADDR_inst                                          0x00C7
#define DDR_MAIN2NDADDR_main_sec_block_shift                          (3)
#define DDR_MAIN2NDADDR_main_sec_block_mask                           (0x7FFFFFF8)
#define DDR_MAIN2NDADDR_main_sec_block(data)                          (0x7FFFFFF8&((data)<<3))
#define DDR_MAIN2NDADDR_get_main_sec_block(data)                      ((0x7FFFFFF8&(data))>>3)


#define DDR_MAIN3RDADDR                                               0x18027320
#define DDR_MAIN3RDADDR_reg_addr                                      "0xb8027320"
#define DDR_MAIN3RDADDR_reg                                           0xb8027320
#define DDR_MAIN3RDADDR_inst_addr                                     "0x00C8"
#define DDR_MAIN3RDADDR_inst                                          0x00C8
#define DDR_MAIN3RDADDR_main_third_block_shift                        (3)
#define DDR_MAIN3RDADDR_main_third_block_mask                         (0x7FFFFFF8)
#define DDR_MAIN3RDADDR_main_third_block(data)                        (0x7FFFFFF8&((data)<<3))
#define DDR_MAIN3RDADDR_get_main_third_block(data)                    ((0x7FFFFFF8&(data))>>3)


#define DDR_MAINLINENUM                                               0x18027324
#define DDR_MAINLINENUM_reg_addr                                      "0xb8027324"
#define DDR_MAINLINENUM_reg                                           0xb8027324
#define DDR_MAINLINENUM_inst_addr                                     "0x00C9"
#define DDR_MAINLINENUM_inst                                          0x00C9
#define DDR_MAINLINENUM_main_line_number_shift                        (0)
#define DDR_MAINLINENUM_main_line_number_mask                         (0x00001FFF)
#define DDR_MAINLINENUM_main_line_number(data)                        (0x00001FFF&(data))
#define DDR_MAINLINENUM_get_main_line_number(data)                    (0x00001FFF&(data))


#define DDR_MAINCTRL                                                  0x18027328
#define DDR_MAINCTRL_reg_addr                                         "0xb8027328"
#define DDR_MAINCTRL_reg                                              0xb8027328
#define DDR_MAINCTRL_inst_addr                                        "0x00CA"
#define DDR_MAINCTRL_inst                                             0x00CA
#define DDR_MAINCTRL_dummy18027328_22_shift                           (22)
#define DDR_MAINCTRL_dummy18027328_21_shift                           (21)
#define DDR_MAINCTRL_dummy18027328_20_shift                           (20)
#define DDR_MAINCTRL_maincolorspace_shift                             (19)
#define DDR_MAINCTRL_main_in_format_shift                             (17)
#define DDR_MAINCTRL_main_bit_num_shift                               (16)
#define DDR_MAINCTRL_main_pr_out_merge_triple_shift                   (14)
#define DDR_MAINCTRL_main_pr_our_merge_en_shift                       (13)
#define DDR_MAINCTRL_main_frame_seq_out_en_shift                      (12)
#define DDR_MAINCTRL_main_stop_burst_en_shift                         (11)
#define DDR_MAINCTRL_main_single_buffer_select_shift                  (8)
#define DDR_MAINCTRL_main_v_flip_3buf_en_shift                        (7)
#define DDR_MAINCTRL_main_double_en_shift                             (6)
#define DDR_MAINCTRL_main_merge_en0_shift                             (5)
#define DDR_MAINCTRL_main_block_free_shift                            (4)
#define DDR_MAINCTRL_main_frc_style_shift                             (3)
#define DDR_MAINCTRL_main_source_sel_shift                            (1)
#define DDR_MAINCTRL_main_use_sub_block_shift                         (0)
#define DDR_MAINCTRL_dummy18027328_22_mask                            (0x00400000)
#define DDR_MAINCTRL_dummy18027328_21_mask                            (0x00200000)
#define DDR_MAINCTRL_dummy18027328_20_mask                            (0x00100000)
#define DDR_MAINCTRL_maincolorspace_mask                              (0x00080000)
#define DDR_MAINCTRL_main_in_format_mask                              (0x00020000)
#define DDR_MAINCTRL_main_bit_num_mask                                (0x00010000)
#define DDR_MAINCTRL_main_pr_out_merge_triple_mask                    (0x00004000)
#define DDR_MAINCTRL_main_pr_our_merge_en_mask                        (0x00002000)
#define DDR_MAINCTRL_main_frame_seq_out_en_mask                       (0x00001000)
#define DDR_MAINCTRL_main_stop_burst_en_mask                          (0x00000800)
#define DDR_MAINCTRL_main_single_buffer_select_mask                   (0x00000300)
#define DDR_MAINCTRL_main_v_flip_3buf_en_mask                         (0x00000080)
#define DDR_MAINCTRL_main_double_en_mask                              (0x00000040)
#define DDR_MAINCTRL_main_merge_en0_mask                              (0x00000020)
#define DDR_MAINCTRL_main_block_free_mask                             (0x00000010)
#define DDR_MAINCTRL_main_frc_style_mask                              (0x00000008)
#define DDR_MAINCTRL_main_source_sel_mask                             (0x00000006)
#define DDR_MAINCTRL_main_use_sub_block_mask                          (0x00000001)
#define DDR_MAINCTRL_dummy18027328_22(data)                           (0x00400000&((data)<<22))
#define DDR_MAINCTRL_dummy18027328_21(data)                           (0x00200000&((data)<<21))
#define DDR_MAINCTRL_dummy18027328_20(data)                           (0x00100000&((data)<<20))
#define DDR_MAINCTRL_maincolorspace(data)                             (0x00080000&((data)<<19))
#define DDR_MAINCTRL_main_in_format(data)                             (0x00020000&((data)<<17))
#define DDR_MAINCTRL_main_bit_num(data)                               (0x00010000&((data)<<16))
#define DDR_MAINCTRL_main_pr_out_merge_triple(data)                   (0x00004000&((data)<<14))
#define DDR_MAINCTRL_main_pr_our_merge_en(data)                       (0x00002000&((data)<<13))
#define DDR_MAINCTRL_main_frame_seq_out_en(data)                      (0x00001000&((data)<<12))
#define DDR_MAINCTRL_main_stop_burst_en(data)                         (0x00000800&((data)<<11))
#define DDR_MAINCTRL_main_single_buffer_select(data)                  (0x00000300&((data)<<8))
#define DDR_MAINCTRL_main_v_flip_3buf_en(data)                        (0x00000080&((data)<<7))
#define DDR_MAINCTRL_main_double_en(data)                             (0x00000040&((data)<<6))
#define DDR_MAINCTRL_main_merge_en0(data)                             (0x00000020&((data)<<5))
#define DDR_MAINCTRL_main_block_free(data)                            (0x00000010&((data)<<4))
#define DDR_MAINCTRL_main_frc_style(data)                             (0x00000008&((data)<<3))
#define DDR_MAINCTRL_main_source_sel(data)                            (0x00000006&((data)<<1))
#define DDR_MAINCTRL_main_use_sub_block(data)                         (0x00000001&(data))
#define DDR_MAINCTRL_get_dummy18027328_22(data)                       ((0x00400000&(data))>>22)
#define DDR_MAINCTRL_get_dummy18027328_21(data)                       ((0x00200000&(data))>>21)
#define DDR_MAINCTRL_get_dummy18027328_20(data)                       ((0x00100000&(data))>>20)
#define DDR_MAINCTRL_get_maincolorspace(data)                         ((0x00080000&(data))>>19)
#define DDR_MAINCTRL_get_main_in_format(data)                         ((0x00020000&(data))>>17)
#define DDR_MAINCTRL_get_main_bit_num(data)                           ((0x00010000&(data))>>16)
#define DDR_MAINCTRL_get_main_pr_out_merge_triple(data)               ((0x00004000&(data))>>14)
#define DDR_MAINCTRL_get_main_pr_our_merge_en(data)                   ((0x00002000&(data))>>13)
#define DDR_MAINCTRL_get_main_frame_seq_out_en(data)                  ((0x00001000&(data))>>12)
#define DDR_MAINCTRL_get_main_stop_burst_en(data)                     ((0x00000800&(data))>>11)
#define DDR_MAINCTRL_get_main_single_buffer_select(data)              ((0x00000300&(data))>>8)
#define DDR_MAINCTRL_get_main_v_flip_3buf_en(data)                    ((0x00000080&(data))>>7)
#define DDR_MAINCTRL_get_main_double_en(data)                         ((0x00000040&(data))>>6)
#define DDR_MAINCTRL_get_main_merge_en0(data)                         ((0x00000020&(data))>>5)
#define DDR_MAINCTRL_get_main_block_free(data)                        ((0x00000010&(data))>>4)
#define DDR_MAINCTRL_get_main_frc_style(data)                         ((0x00000008&(data))>>3)
#define DDR_MAINCTRL_get_main_source_sel(data)                        ((0x00000006&(data))>>1)
#define DDR_MAINCTRL_get_main_use_sub_block(data)                     (0x00000001&(data))


#define DISP_MAIN_ENABLE                                              0x1802732c
#define DISP_MAIN_ENABLE_reg_addr                                     "0xb802732c"
#define DISP_MAIN_ENABLE_reg                                          0xb802732c
#define DISP_MAIN_ENABLE_inst_addr                                    "0x00CB"
#define DISP_MAIN_ENABLE_inst                                         0x00CB
#define DISP_MAIN_ENABLE_main_disp_en_shift                           (0)
#define DISP_MAIN_ENABLE_main_disp_en_mask                            (0x00000001)
#define DISP_MAIN_ENABLE_main_disp_en(data)                           (0x00000001&(data))
#define DISP_MAIN_ENABLE_get_main_disp_en(data)                       (0x00000001&(data))


#define DDR_MAINSTATUS                                                0x18027330
#define DDR_MAINSTATUS_reg_addr                                       "0xb8027330"
#define DDR_MAINSTATUS_reg                                            0xb8027330
#define DDR_MAINSTATUS_inst_addr                                      "0x00CC"
#define DDR_MAINSTATUS_inst                                           0x00CC
#define DDR_MAINSTATUS_main_repeat_chgflg_shift                       (15)
#define DDR_MAINSTATUS_main_repeat_frame_sequence_shift               (12)
#define DDR_MAINSTATUS_main_drop_chgflg_shift                         (11)
#define DDR_MAINSTATUS_main_drop_frame_sequence_shift                 (8)
#define DDR_MAINSTATUS_main_block_select_shift                        (4)
#define DDR_MAINSTATUS_main_read_l_flag_shift                         (0)
#define DDR_MAINSTATUS_main_repeat_chgflg_mask                        (0x00008000)
#define DDR_MAINSTATUS_main_repeat_frame_sequence_mask                (0x00007000)
#define DDR_MAINSTATUS_main_drop_chgflg_mask                          (0x00000800)
#define DDR_MAINSTATUS_main_drop_frame_sequence_mask                  (0x00000700)
#define DDR_MAINSTATUS_main_block_select_mask                         (0x00000030)
#define DDR_MAINSTATUS_main_read_l_flag_mask                          (0x00000001)
#define DDR_MAINSTATUS_main_repeat_chgflg(data)                       (0x00008000&((data)<<15))
#define DDR_MAINSTATUS_main_repeat_frame_sequence(data)               (0x00007000&((data)<<12))
#define DDR_MAINSTATUS_main_drop_chgflg(data)                         (0x00000800&((data)<<11))
#define DDR_MAINSTATUS_main_drop_frame_sequence(data)                 (0x00000700&((data)<<8))
#define DDR_MAINSTATUS_main_block_select(data)                        (0x00000030&((data)<<4))
#define DDR_MAINSTATUS_main_read_l_flag(data)                         (0x00000001&(data))
#define DDR_MAINSTATUS_get_main_repeat_chgflg(data)                   ((0x00008000&(data))>>15)
#define DDR_MAINSTATUS_get_main_repeat_frame_sequence(data)           ((0x00007000&(data))>>12)
#define DDR_MAINSTATUS_get_main_drop_chgflg(data)                     ((0x00000800&(data))>>11)
#define DDR_MAINSTATUS_get_main_drop_frame_sequence(data)             ((0x00000700&(data))>>8)
#define DDR_MAINSTATUS_get_main_block_select(data)                    ((0x00000030&(data))>>4)
#define DDR_MAINSTATUS_get_main_read_l_flag(data)                     (0x00000001&(data))


#define DDR_MAINSUBCTRL                                               0x18027334
#define DDR_MAINSUBCTRL_reg_addr                                      "0xb8027334"
#define DDR_MAINSUBCTRL_reg                                           0xb8027334
#define DDR_MAINSUBCTRL_inst_addr                                     "0x00CD"
#define DDR_MAINSUBCTRL_inst                                          0x00CD
#define DDR_MAINSUBCTRL_dummy18027334_18_shift                        (18)
#define DDR_MAINSUBCTRL_dummy18027334_17_shift                        (17)
#define DDR_MAINSUBCTRL_dummy18027334_16_shift                        (16)
#define DDR_MAINSUBCTRL_disp1_db_rd_sel_shift                         (2)
#define DDR_MAINSUBCTRL_disp1_double_enable_shift                     (1)
#define DDR_MAINSUBCTRL_disp1_double_apply_shift                      (0)
#define DDR_MAINSUBCTRL_dummy18027334_18_mask                         (0x00040000)
#define DDR_MAINSUBCTRL_dummy18027334_17_mask                         (0x00020000)
#define DDR_MAINSUBCTRL_dummy18027334_16_mask                         (0x00010000)
#define DDR_MAINSUBCTRL_disp1_db_rd_sel_mask                          (0x00000004)
#define DDR_MAINSUBCTRL_disp1_double_enable_mask                      (0x00000002)
#define DDR_MAINSUBCTRL_disp1_double_apply_mask                       (0x00000001)
#define DDR_MAINSUBCTRL_dummy18027334_18(data)                        (0x00040000&((data)<<18))
#define DDR_MAINSUBCTRL_dummy18027334_17(data)                        (0x00020000&((data)<<17))
#define DDR_MAINSUBCTRL_dummy18027334_16(data)                        (0x00010000&((data)<<16))
#define DDR_MAINSUBCTRL_disp1_db_rd_sel(data)                         (0x00000004&((data)<<2))
#define DDR_MAINSUBCTRL_disp1_double_enable(data)                     (0x00000002&((data)<<1))
#define DDR_MAINSUBCTRL_disp1_double_apply(data)                      (0x00000001&(data))
#define DDR_MAINSUBCTRL_get_dummy18027334_18(data)                    ((0x00040000&(data))>>18)
#define DDR_MAINSUBCTRL_get_dummy18027334_17(data)                    ((0x00020000&(data))>>17)
#define DDR_MAINSUBCTRL_get_dummy18027334_16(data)                    ((0x00010000&(data))>>16)
#define DDR_MAINSUBCTRL_get_disp1_db_rd_sel(data)                     ((0x00000004&(data))>>2)
#define DDR_MAINSUBCTRL_get_disp1_double_enable(data)                 ((0x00000002&(data))>>1)
#define DDR_MAINSUBCTRL_get_disp1_double_apply(data)                  (0x00000001&(data))


#define DDR_MAINMASKCTRL                                              0x18027350
#define DDR_MAINMASKCTRL_reg_addr                                     "0xb8027350"
#define DDR_MAINMASKCTRL_reg                                          0xb8027350
#define DDR_MAINMASKCTRL_inst_addr                                    "0x00D4"
#define DDR_MAINMASKCTRL_inst                                         0x00D4
#define DDR_MAINMASKCTRL_main_en_syn_rst_shift                        (16)
#define DDR_MAINMASKCTRL_main_en_syn_rst_mask                         (0x00010000)
#define DDR_MAINMASKCTRL_main_en_syn_rst(data)                        (0x00010000&((data)<<16))
#define DDR_MAINMASKCTRL_get_main_en_syn_rst(data)                    ((0x00010000&(data))>>16)


#define DDR_MAINVMOFFSET                                              0x18027354
#define DDR_MAINVMOFFSET_reg_addr                                     "0xb8027354"
#define DDR_MAINVMOFFSET_reg                                          0xb8027354
#define DDR_MAINVMOFFSET_inst_addr                                    "0x00D5"
#define DDR_MAINVMOFFSET_inst                                         0x00D5


#define DDR_MAIN_MASK1_MASK2_OFFSET                                   0x18027358
#define DDR_MAIN_MASK1_MASK2_OFFSET_reg_addr                          "0xb8027358"
#define DDR_MAIN_MASK1_MASK2_OFFSET_reg                               0xb8027358
#define DDR_MAIN_MASK1_MASK2_OFFSET_inst_addr                         "0x00D6"
#define DDR_MAIN_MASK1_MASK2_OFFSET_inst                              0x00D6


#define DDR_MAIN_UP_HMOFFSET                                          0x1802735c
#define DDR_MAIN_UP_HMOFFSET_reg_addr                                 "0xb802735c"
#define DDR_MAIN_UP_HMOFFSET_reg                                      0xb802735c
#define DDR_MAIN_UP_HMOFFSET_inst_addr                                "0x00D7"
#define DDR_MAIN_UP_HMOFFSET_inst                                     0x00D7


#define DDR_MAIN_MID_HMOFFSET                                         0x18027360
#define DDR_MAIN_MID_HMOFFSET_reg_addr                                "0xb8027360"
#define DDR_MAIN_MID_HMOFFSET_reg                                     0xb8027360
#define DDR_MAIN_MID_HMOFFSET_inst_addr                               "0x00D8"
#define DDR_MAIN_MID_HMOFFSET_inst                                    0x00D8


#define DDR_MAIN_MID1_MID2_OFFSET                                     0x18027364
#define DDR_MAIN_MID1_MID2_OFFSET_reg_addr                            "0xb8027364"
#define DDR_MAIN_MID1_MID2_OFFSET_reg                                 0xb8027364
#define DDR_MAIN_MID1_MID2_OFFSET_inst_addr                           "0x00D9"
#define DDR_MAIN_MID1_MID2_OFFSET_inst                                0x00D9


#define DDR_MAIN_DOWN_HMOFFSET                                        0x18027368
#define DDR_MAIN_DOWN_HMOFFSET_reg_addr                               "0xb8027368"
#define DDR_MAIN_DOWN_HMOFFSET_reg                                    0xb8027368
#define DDR_MAIN_DOWN_HMOFFSET_inst_addr                              "0x00DA"
#define DDR_MAIN_DOWN_HMOFFSET_inst                                   0x00DA


#define DDR_MAIN_UP_HMNUMLENREMLEFT                                   0x1802736c
#define DDR_MAIN_UP_HMNUMLENREMLEFT_reg_addr                          "0xb802736c"
#define DDR_MAIN_UP_HMNUMLENREMLEFT_reg                               0xb802736c
#define DDR_MAIN_UP_HMNUMLENREMLEFT_inst_addr                         "0x00DB"
#define DDR_MAIN_UP_HMNUMLENREMLEFT_inst                              0x00DB


#define DDR_MAIN_UP_HMNUMLENREMRIGHT                                  0x18027370
#define DDR_MAIN_UP_HMNUMLENREMRIGHT_reg_addr                         "0xb8027370"
#define DDR_MAIN_UP_HMNUMLENREMRIGHT_reg                              0xb8027370
#define DDR_MAIN_UP_HMNUMLENREMRIGHT_inst_addr                        "0x00DC"
#define DDR_MAIN_UP_HMNUMLENREMRIGHT_inst                             0x00DC


#define DDR_MAIN_MID_HMNUMLENREMLEFT                                  0x18027374
#define DDR_MAIN_MID_HMNUMLENREMLEFT_reg_addr                         "0xb8027374"
#define DDR_MAIN_MID_HMNUMLENREMLEFT_reg                              0xb8027374
#define DDR_MAIN_MID_HMNUMLENREMLEFT_inst_addr                        "0x00DD"
#define DDR_MAIN_MID_HMNUMLENREMLEFT_inst                             0x00DD


#define DDR_MAIN_MID_HMNUMLENREMMIDDLE                                0x18027378
#define DDR_MAIN_MID_HMNUMLENREMMIDDLE_reg_addr                       "0xb8027378"
#define DDR_MAIN_MID_HMNUMLENREMMIDDLE_reg                            0xb8027378
#define DDR_MAIN_MID_HMNUMLENREMMIDDLE_inst_addr                      "0x00DE"
#define DDR_MAIN_MID_HMNUMLENREMMIDDLE_inst                           0x00DE


#define DDR_MAIN_MID_HMNUMLENREMRIGHT                                 0x1802737c
#define DDR_MAIN_MID_HMNUMLENREMRIGHT_reg_addr                        "0xb802737c"
#define DDR_MAIN_MID_HMNUMLENREMRIGHT_reg                             0xb802737c
#define DDR_MAIN_MID_HMNUMLENREMRIGHT_inst_addr                       "0x00DF"
#define DDR_MAIN_MID_HMNUMLENREMRIGHT_inst                            0x00DF


#define DDR_MAIN_DOWN_HMNUMLENREMLEFT                                 0x18027380
#define DDR_MAIN_DOWN_HMNUMLENREMLEFT_reg_addr                        "0xb8027380"
#define DDR_MAIN_DOWN_HMNUMLENREMLEFT_reg                             0xb8027380
#define DDR_MAIN_DOWN_HMNUMLENREMLEFT_inst_addr                       "0x00E0"
#define DDR_MAIN_DOWN_HMNUMLENREMLEFT_inst                            0x00E0


#define DDR_MAIN_DOWN_HMNUMLENREMRIGHT                                0x18027384
#define DDR_MAIN_DOWN_HMNUMLENREMRIGHT_reg_addr                       "0xb8027384"
#define DDR_MAIN_DOWN_HMNUMLENREMRIGHT_reg                            0xb8027384
#define DDR_MAIN_DOWN_HMNUMLENREMRIGHT_inst_addr                      "0x00E1"
#define DDR_MAIN_DOWN_HMNUMLENREMRIGHT_inst                           0x00E1


#define DDR_MAIN_UP_VMSIZE                                            0x18027388
#define DDR_MAIN_UP_VMSIZE_reg_addr                                   "0xb8027388"
#define DDR_MAIN_UP_VMSIZE_reg                                        0xb8027388
#define DDR_MAIN_UP_VMSIZE_inst_addr                                  "0x00E2"
#define DDR_MAIN_UP_VMSIZE_inst                                       0x00E2


#define DDR_MAIN_UP_HMSIZE                                            0x1802738c
#define DDR_MAIN_UP_HMSIZE_reg_addr                                   "0xb802738c"
#define DDR_MAIN_UP_HMSIZE_reg                                        0xb802738c
#define DDR_MAIN_UP_HMSIZE_inst_addr                                  "0x00E3"
#define DDR_MAIN_UP_HMSIZE_inst                                       0x00E3


#define DDR_MAIN_MID_VMSIZE                                           0x18027390
#define DDR_MAIN_MID_VMSIZE_reg_addr                                  "0xb8027390"
#define DDR_MAIN_MID_VMSIZE_reg                                       0xb8027390
#define DDR_MAIN_MID_VMSIZE_inst_addr                                 "0x00E4"
#define DDR_MAIN_MID_VMSIZE_inst                                      0x00E4


#define DDR_MAIN_MID1_HMSIZE                                          0x18027394
#define DDR_MAIN_MID1_HMSIZE_reg_addr                                 "0xb8027394"
#define DDR_MAIN_MID1_HMSIZE_reg                                      0xb8027394
#define DDR_MAIN_MID1_HMSIZE_inst_addr                                "0x00E5"
#define DDR_MAIN_MID1_HMSIZE_inst                                     0x00E5


#define DDR_MAIN_MID2_HMSIZE                                          0x18027398
#define DDR_MAIN_MID2_HMSIZE_reg_addr                                 "0xb8027398"
#define DDR_MAIN_MID2_HMSIZE_reg                                      0xb8027398
#define DDR_MAIN_MID2_HMSIZE_inst_addr                                "0x00E6"
#define DDR_MAIN_MID2_HMSIZE_inst                                     0x00E6


#define DDR_MAIN_DOWN_VMSIZE                                          0x1802739c
#define DDR_MAIN_DOWN_VMSIZE_reg_addr                                 "0xb802739c"
#define DDR_MAIN_DOWN_VMSIZE_reg                                      0xb802739c
#define DDR_MAIN_DOWN_VMSIZE_inst_addr                                "0x00E7"
#define DDR_MAIN_DOWN_VMSIZE_inst                                     0x00E7


#define DDR_MAIN_DOWN_HMSIZE                                          0x180273a0
#define DDR_MAIN_DOWN_HMSIZE_reg_addr                                 "0xb80273a0"
#define DDR_MAIN_DOWN_HMSIZE_reg                                      0xb80273a0
#define DDR_MAIN_DOWN_HMSIZE_inst_addr                                "0x00E8"
#define DDR_MAIN_DOWN_HMSIZE_inst                                     0x00E8


#define DDR_MAIN_UP_MASKSTEP                                          0x180273a4
#define DDR_MAIN_UP_MASKSTEP_reg_addr                                 "0xb80273a4"
#define DDR_MAIN_UP_MASKSTEP_reg                                      0xb80273a4
#define DDR_MAIN_UP_MASKSTEP_inst_addr                                "0x00E9"
#define DDR_MAIN_UP_MASKSTEP_inst                                     0x00E9


#define DDR_MAIN_MID1_MASKSTEP                                        0x180273a8
#define DDR_MAIN_MID1_MASKSTEP_reg_addr                               "0xb80273a8"
#define DDR_MAIN_MID1_MASKSTEP_reg                                    0xb80273a8
#define DDR_MAIN_MID1_MASKSTEP_inst_addr                              "0x00EA"
#define DDR_MAIN_MID1_MASKSTEP_inst                                   0x00EA


#define DDR_MAIN_MID2_MASKSTEP                                        0x180273ac
#define DDR_MAIN_MID2_MASKSTEP_reg_addr                               "0xb80273ac"
#define DDR_MAIN_MID2_MASKSTEP_reg                                    0xb80273ac
#define DDR_MAIN_MID2_MASKSTEP_inst_addr                              "0x00EB"
#define DDR_MAIN_MID2_MASKSTEP_inst                                   0x00EB


#define DDR_MAIN_DOWN_MASKSTEP                                        0x180273b0
#define DDR_MAIN_DOWN_MASKSTEP_reg_addr                               "0xb80273b0"
#define DDR_MAIN_DOWN_MASKSTEP_reg                                    0xb80273b0
#define DDR_MAIN_DOWN_MASKSTEP_inst_addr                              "0x00EC"
#define DDR_MAIN_DOWN_MASKSTEP_inst                                   0x00EC


#define DDR_MAINMASKFNT                                               0x180273b4
#define DDR_MAINMASKFNT_reg_addr                                      "0xb80273b4"
#define DDR_MAINMASKFNT_reg                                           0xb80273b4
#define DDR_MAINMASKFNT_inst_addr                                     "0x00ED"
#define DDR_MAINMASKFNT_inst                                          0x00ED


#define DISP_DDR_FIFOSTATUS                                           0x18027460
#define DISP_DDR_FIFOSTATUS_reg_addr                                  "0xb8027460"
#define DISP_DDR_FIFOSTATUS_reg                                       0xb8027460
#define DISP_DDR_FIFOSTATUS_inst_addr                                 "0x0118"
#define DISP_DDR_FIFOSTATUS_inst                                      0x0118
#define DISP_DDR_FIFOSTATUS_main_field_shift                          (24)
#define DISP_DDR_FIFOSTATUS_main_fifoof_shift                         (23)
#define DISP_DDR_FIFOSTATUS_main_fifouf_shift                         (22)
#define DISP_DDR_FIFOSTATUS_main_fifofull_shift                       (21)
#define DISP_DDR_FIFOSTATUS_main_fifoempty_shift                      (20)
#define DISP_DDR_FIFOSTATUS_main_combine_fifoof_shift                 (19)
#define DISP_DDR_FIFOSTATUS_main_combine_fifouf_shift                 (18)
#define DISP_DDR_FIFOSTATUS_main_combine_fifofull_shift               (17)
#define DISP_DDR_FIFOSTATUS_main_combine_fifoempty_shift              (16)
#define DISP_DDR_FIFOSTATUS_dummy18027460_8_shift                     (8)
#define DISP_DDR_FIFOSTATUS_dummy18027460_7_shift                     (7)
#define DISP_DDR_FIFOSTATUS_dummy18027460_6_shift                     (6)
#define DISP_DDR_FIFOSTATUS_dummy18027460_5_shift                     (5)
#define DISP_DDR_FIFOSTATUS_dummy18027460_4_shift                     (4)
#define DISP_DDR_FIFOSTATUS_dummy18027460_3_shift                     (3)
#define DISP_DDR_FIFOSTATUS_dummy18027460_2_shift                     (2)
#define DISP_DDR_FIFOSTATUS_dummy18027460_1_shift                     (1)
#define DISP_DDR_FIFOSTATUS_dummy18027460_0_shift                     (0)
#define DISP_DDR_FIFOSTATUS_main_field_mask                           (0x01000000)
#define DISP_DDR_FIFOSTATUS_main_fifoof_mask                          (0x00800000)
#define DISP_DDR_FIFOSTATUS_main_fifouf_mask                          (0x00400000)
#define DISP_DDR_FIFOSTATUS_main_fifofull_mask                        (0x00200000)
#define DISP_DDR_FIFOSTATUS_main_fifoempty_mask                       (0x00100000)
#define DISP_DDR_FIFOSTATUS_main_combine_fifoof_mask                  (0x00080000)
#define DISP_DDR_FIFOSTATUS_main_combine_fifouf_mask                  (0x00040000)
#define DISP_DDR_FIFOSTATUS_main_combine_fifofull_mask                (0x00020000)
#define DISP_DDR_FIFOSTATUS_main_combine_fifoempty_mask               (0x00010000)
#define DISP_DDR_FIFOSTATUS_dummy18027460_8_mask                      (0x00000100)
#define DISP_DDR_FIFOSTATUS_dummy18027460_7_mask                      (0x00000080)
#define DISP_DDR_FIFOSTATUS_dummy18027460_6_mask                      (0x00000040)
#define DISP_DDR_FIFOSTATUS_dummy18027460_5_mask                      (0x00000020)
#define DISP_DDR_FIFOSTATUS_dummy18027460_4_mask                      (0x00000010)
#define DISP_DDR_FIFOSTATUS_dummy18027460_3_mask                      (0x00000008)
#define DISP_DDR_FIFOSTATUS_dummy18027460_2_mask                      (0x00000004)
#define DISP_DDR_FIFOSTATUS_dummy18027460_1_mask                      (0x00000002)
#define DISP_DDR_FIFOSTATUS_dummy18027460_0_mask                      (0x00000001)
#define DISP_DDR_FIFOSTATUS_main_field(data)                          (0x01000000&((data)<<24))
#define DISP_DDR_FIFOSTATUS_main_fifoof(data)                         (0x00800000&((data)<<23))
#define DISP_DDR_FIFOSTATUS_main_fifouf(data)                         (0x00400000&((data)<<22))
#define DISP_DDR_FIFOSTATUS_main_fifofull(data)                       (0x00200000&((data)<<21))
#define DISP_DDR_FIFOSTATUS_main_fifoempty(data)                      (0x00100000&((data)<<20))
#define DISP_DDR_FIFOSTATUS_main_combine_fifoof(data)                 (0x00080000&((data)<<19))
#define DISP_DDR_FIFOSTATUS_main_combine_fifouf(data)                 (0x00040000&((data)<<18))
#define DISP_DDR_FIFOSTATUS_main_combine_fifofull(data)               (0x00020000&((data)<<17))
#define DISP_DDR_FIFOSTATUS_main_combine_fifoempty(data)              (0x00010000&((data)<<16))
#define DISP_DDR_FIFOSTATUS_dummy18027460_8(data)                     (0x00000100&((data)<<8))
#define DISP_DDR_FIFOSTATUS_dummy18027460_7(data)                     (0x00000080&((data)<<7))
#define DISP_DDR_FIFOSTATUS_dummy18027460_6(data)                     (0x00000040&((data)<<6))
#define DISP_DDR_FIFOSTATUS_dummy18027460_5(data)                     (0x00000020&((data)<<5))
#define DISP_DDR_FIFOSTATUS_dummy18027460_4(data)                     (0x00000010&((data)<<4))
#define DISP_DDR_FIFOSTATUS_dummy18027460_3(data)                     (0x00000008&((data)<<3))
#define DISP_DDR_FIFOSTATUS_dummy18027460_2(data)                     (0x00000004&((data)<<2))
#define DISP_DDR_FIFOSTATUS_dummy18027460_1(data)                     (0x00000002&((data)<<1))
#define DISP_DDR_FIFOSTATUS_dummy18027460_0(data)                     (0x00000001&(data))
#define DISP_DDR_FIFOSTATUS_get_main_field(data)                      ((0x01000000&(data))>>24)
#define DISP_DDR_FIFOSTATUS_get_main_fifoof(data)                     ((0x00800000&(data))>>23)
#define DISP_DDR_FIFOSTATUS_get_main_fifouf(data)                     ((0x00400000&(data))>>22)
#define DISP_DDR_FIFOSTATUS_get_main_fifofull(data)                   ((0x00200000&(data))>>21)
#define DISP_DDR_FIFOSTATUS_get_main_fifoempty(data)                  ((0x00100000&(data))>>20)
#define DISP_DDR_FIFOSTATUS_get_main_combine_fifoof(data)             ((0x00080000&(data))>>19)
#define DISP_DDR_FIFOSTATUS_get_main_combine_fifouf(data)             ((0x00040000&(data))>>18)
#define DISP_DDR_FIFOSTATUS_get_main_combine_fifofull(data)           ((0x00020000&(data))>>17)
#define DISP_DDR_FIFOSTATUS_get_main_combine_fifoempty(data)          ((0x00010000&(data))>>16)
#define DISP_DDR_FIFOSTATUS_get_dummy18027460_8(data)                 ((0x00000100&(data))>>8)
#define DISP_DDR_FIFOSTATUS_get_dummy18027460_7(data)                 ((0x00000080&(data))>>7)
#define DISP_DDR_FIFOSTATUS_get_dummy18027460_6(data)                 ((0x00000040&(data))>>6)
#define DISP_DDR_FIFOSTATUS_get_dummy18027460_5(data)                 ((0x00000020&(data))>>5)
#define DISP_DDR_FIFOSTATUS_get_dummy18027460_4(data)                 ((0x00000010&(data))>>4)
#define DISP_DDR_FIFOSTATUS_get_dummy18027460_3(data)                 ((0x00000008&(data))>>3)
#define DISP_DDR_FIFOSTATUS_get_dummy18027460_2(data)                 ((0x00000004&(data))>>2)
#define DISP_DDR_FIFOSTATUS_get_dummy18027460_1(data)                 ((0x00000002&(data))>>1)
#define DISP_DDR_FIFOSTATUS_get_dummy18027460_0(data)                 (0x00000001&(data))


#define DISP_IE_WD_CTRL                                               0x18027464
#define DISP_IE_WD_CTRL_reg_addr                                      "0xb8027464"
#define DISP_IE_WD_CTRL_reg                                           0xb8027464
#define DISP_IE_WD_CTRL_inst_addr                                     "0x0119"
#define DISP_IE_WD_CTRL_inst                                          0x0119
#define DISP_IE_WD_CTRL_main_fifoerr_ie_shift                         (17)
#define DISP_IE_WD_CTRL_main_fifoerr_wde_shift                        (16)
#define DISP_IE_WD_CTRL_dummy18027464_1_shift                         (1)
#define DISP_IE_WD_CTRL_dummy18027464_0_shift                         (0)
#define DISP_IE_WD_CTRL_main_fifoerr_ie_mask                          (0x00020000)
#define DISP_IE_WD_CTRL_main_fifoerr_wde_mask                         (0x00010000)
#define DISP_IE_WD_CTRL_dummy18027464_1_mask                          (0x00000002)
#define DISP_IE_WD_CTRL_dummy18027464_0_mask                          (0x00000001)
#define DISP_IE_WD_CTRL_main_fifoerr_ie(data)                         (0x00020000&((data)<<17))
#define DISP_IE_WD_CTRL_main_fifoerr_wde(data)                        (0x00010000&((data)<<16))
#define DISP_IE_WD_CTRL_dummy18027464_1(data)                         (0x00000002&((data)<<1))
#define DISP_IE_WD_CTRL_dummy18027464_0(data)                         (0x00000001&(data))
#define DISP_IE_WD_CTRL_get_main_fifoerr_ie(data)                     ((0x00020000&(data))>>17)
#define DISP_IE_WD_CTRL_get_main_fifoerr_wde(data)                    ((0x00010000&(data))>>16)
#define DISP_IE_WD_CTRL_get_dummy18027464_1(data)                     ((0x00000002&(data))>>1)
#define DISP_IE_WD_CTRL_get_dummy18027464_0(data)                     (0x00000001&(data))


#define DISPMAIN_BOUNDARYADDR1                                        0x18027468
#define DISPMAIN_BOUNDARYADDR1_reg_addr                               "0xb8027468"
#define DISPMAIN_BOUNDARYADDR1_reg                                    0xb8027468
#define DISPMAIN_BOUNDARYADDR1_inst_addr                              "0x011A"
#define DISPMAIN_BOUNDARYADDR1_inst                                   0x011A
#define DISPMAIN_BOUNDARYADDR1_main_disp_downlimit_adr_shift          (3)
#define DISPMAIN_BOUNDARYADDR1_main_disp_downlimit_adr_mask           (0x7FFFFFF8)
#define DISPMAIN_BOUNDARYADDR1_main_disp_downlimit_adr(data)          (0x7FFFFFF8&((data)<<3))
#define DISPMAIN_BOUNDARYADDR1_get_main_disp_downlimit_adr(data)      ((0x7FFFFFF8&(data))>>3)


#define DISPMAIN_BOUNDARYADDR2                                        0x1802746c
#define DISPMAIN_BOUNDARYADDR2_reg_addr                               "0xb802746c"
#define DISPMAIN_BOUNDARYADDR2_reg                                    0xb802746c
#define DISPMAIN_BOUNDARYADDR2_inst_addr                              "0x011B"
#define DISPMAIN_BOUNDARYADDR2_inst                                   0x011B
#define DISPMAIN_BOUNDARYADDR2_main_disp_uplimit_adr_shift            (3)
#define DISPMAIN_BOUNDARYADDR2_main_disp_uplimit_adr_mask             (0x7FFFFFF8)
#define DISPMAIN_BOUNDARYADDR2_main_disp_uplimit_adr(data)            (0x7FFFFFF8&((data)<<3))
#define DISPMAIN_BOUNDARYADDR2_get_main_disp_uplimit_adr(data)        ((0x7FFFFFF8&(data))>>3)


#define DISPI1_RD_BOUNDARYADD_STATUS                                  0x18027470
#define DISPI1_RD_BOUNDARYADD_STATUS_reg_addr                         "0xb8027470"
#define DISPI1_RD_BOUNDARYADD_STATUS_reg                              0xb8027470
#define DISPI1_RD_BOUNDARYADD_STATUS_inst_addr                        "0x011C"
#define DISPI1_RD_BOUNDARYADD_STATUS_inst                             0x011C
#define DISPI1_RD_BOUNDARYADD_STATUS_main_disp_downlimit_ov_shift     (1)
#define DISPI1_RD_BOUNDARYADD_STATUS_main_dispuplimit_ov_shift        (0)
#define DISPI1_RD_BOUNDARYADD_STATUS_main_disp_downlimit_ov_mask      (0x00000002)
#define DISPI1_RD_BOUNDARYADD_STATUS_main_dispuplimit_ov_mask         (0x00000001)
#define DISPI1_RD_BOUNDARYADD_STATUS_main_disp_downlimit_ov(data)     (0x00000002&((data)<<1))
#define DISPI1_RD_BOUNDARYADD_STATUS_main_dispuplimit_ov(data)        (0x00000001&(data))
#define DISPI1_RD_BOUNDARYADD_STATUS_get_main_disp_downlimit_ov(data) ((0x00000002&(data))>>1)
#define DISPI1_RD_BOUNDARYADD_STATUS_get_main_dispuplimit_ov(data)    (0x00000001&(data))


#define DISPSUB_BOUNDARYADDR1                                         0x18027474
#define DISPSUB_BOUNDARYADDR1_reg_addr                                "0xb8027474"
#define DISPSUB_BOUNDARYADDR1_reg                                     0xb8027474
#define DISPSUB_BOUNDARYADDR1_inst_addr                               "0x011D"
#define DISPSUB_BOUNDARYADDR1_inst                                    0x011D


#define DISPSUB_BOUNDARYADDR2                                         0x18027478
#define DISPSUB_BOUNDARYADDR2_reg_addr                                "0xb8027478"
#define DISPSUB_BOUNDARYADDR2_reg                                     0xb8027478
#define DISPSUB_BOUNDARYADDR2_inst_addr                               "0x011E"
#define DISPSUB_BOUNDARYADDR2_inst                                    0x011E


#define DISPI2_RD_BOUNDARYADD_STATUS                                  0x1802747c
#define DISPI2_RD_BOUNDARYADD_STATUS_reg_addr                         "0xb802747c"
#define DISPI2_RD_BOUNDARYADD_STATUS_reg                              0xb802747c
#define DISPI2_RD_BOUNDARYADD_STATUS_inst_addr                        "0x011F"
#define DISPI2_RD_BOUNDARYADD_STATUS_inst                             0x011F


#define DDR_MAIN_R_1ST_ADDR                                           0x18027480
#define DDR_MAIN_R_1ST_ADDR_reg_addr                                  "0xb8027480"
#define DDR_MAIN_R_1ST_ADDR_reg                                       0xb8027480
#define DDR_MAIN_R_1ST_ADDR_inst_addr                                 "0x0120"
#define DDR_MAIN_R_1ST_ADDR_inst                                      0x0120
#define DDR_MAIN_R_1ST_ADDR_main_r_first_addr_shift                   (3)
#define DDR_MAIN_R_1ST_ADDR_main_r_first_addr_mask                    (0x7FFFFFF8)
#define DDR_MAIN_R_1ST_ADDR_main_r_first_addr(data)                   (0x7FFFFFF8&((data)<<3))
#define DDR_MAIN_R_1ST_ADDR_get_main_r_first_addr(data)               ((0x7FFFFFF8&(data))>>3)


#define DDR_MAIN_R_2ND_ADDR                                           0x18027484
#define DDR_MAIN_R_2ND_ADDR_reg_addr                                  "0xb8027484"
#define DDR_MAIN_R_2ND_ADDR_reg                                       0xb8027484
#define DDR_MAIN_R_2ND_ADDR_inst_addr                                 "0x0121"
#define DDR_MAIN_R_2ND_ADDR_inst                                      0x0121
#define DDR_MAIN_R_2ND_ADDR_main_r_second_addr_shift                  (3)
#define DDR_MAIN_R_2ND_ADDR_main_r_second_addr_mask                   (0x7FFFFFF8)
#define DDR_MAIN_R_2ND_ADDR_main_r_second_addr(data)                  (0x7FFFFFF8&((data)<<3))
#define DDR_MAIN_R_2ND_ADDR_get_main_r_second_addr(data)              ((0x7FFFFFF8&(data))>>3)


#define DDR_MAIN_R_3RD_ADDR                                           0x18027488
#define DDR_MAIN_R_3RD_ADDR_reg_addr                                  "0xb8027488"
#define DDR_MAIN_R_3RD_ADDR_reg                                       0xb8027488
#define DDR_MAIN_R_3RD_ADDR_inst_addr                                 "0x0122"
#define DDR_MAIN_R_3RD_ADDR_inst                                      0x0122
#define DDR_MAIN_R_3RD_ADDR_main_r_third_addr_shift                   (3)
#define DDR_MAIN_R_3RD_ADDR_main_r_third_addr_mask                    (0x7FFFFFF8)
#define DDR_MAIN_R_3RD_ADDR_main_r_third_addr(data)                   (0x7FFFFFF8&((data)<<3))
#define DDR_MAIN_R_3RD_ADDR_get_main_r_third_addr(data)               ((0x7FFFFFF8&(data))>>3)


#define DISP_HELP_DEBUG                                               0x1802748c
#define DISP_HELP_DEBUG_reg_addr                                      "0xb802748c"
#define DISP_HELP_DEBUG_reg                                           0xb802748c
#define DISP_HELP_DEBUG_inst_addr                                     "0x0123"
#define DISP_HELP_DEBUG_inst                                          0x0123
#define DISP_HELP_DEBUG_main_repeat_4x_shift                          (23)
#define DISP_HELP_DEBUG_main_repeat_3x_shift                          (22)
#define DISP_HELP_DEBUG_main_repeat_2x_shift                          (21)
#define DISP_HELP_DEBUG_main_repeat_1x_shift                          (20)
#define DISP_HELP_DEBUG_main_drop_shift                               (18)
#define DISP_HELP_DEBUG_main_under_size_shift                         (16)
#define DISP_HELP_DEBUG_main_repeat_4x_mask                           (0x00800000)
#define DISP_HELP_DEBUG_main_repeat_3x_mask                           (0x00400000)
#define DISP_HELP_DEBUG_main_repeat_2x_mask                           (0x00200000)
#define DISP_HELP_DEBUG_main_repeat_1x_mask                           (0x00100000)
#define DISP_HELP_DEBUG_main_drop_mask                                (0x00040000)
#define DISP_HELP_DEBUG_main_under_size_mask                          (0x00010000)
#define DISP_HELP_DEBUG_main_repeat_4x(data)                          (0x00800000&((data)<<23))
#define DISP_HELP_DEBUG_main_repeat_3x(data)                          (0x00400000&((data)<<22))
#define DISP_HELP_DEBUG_main_repeat_2x(data)                          (0x00200000&((data)<<21))
#define DISP_HELP_DEBUG_main_repeat_1x(data)                          (0x00100000&((data)<<20))
#define DISP_HELP_DEBUG_main_drop(data)                               (0x00040000&((data)<<18))
#define DISP_HELP_DEBUG_main_under_size(data)                         (0x00010000&((data)<<16))
#define DISP_HELP_DEBUG_get_main_repeat_4x(data)                      ((0x00800000&(data))>>23)
#define DISP_HELP_DEBUG_get_main_repeat_3x(data)                      ((0x00400000&(data))>>22)
#define DISP_HELP_DEBUG_get_main_repeat_2x(data)                      ((0x00200000&(data))>>21)
#define DISP_HELP_DEBUG_get_main_repeat_1x(data)                      ((0x00100000&(data))>>20)
#define DISP_HELP_DEBUG_get_main_drop(data)                           ((0x00040000&(data))>>18)
#define DISP_HELP_DEBUG_get_main_under_size(data)                     ((0x00010000&(data))>>16)


#define DISPM_BIST_MODE                                               0x180274a0
#define DISPM_BIST_MODE_reg_addr                                      "0xb80274a0"
#define DISPM_BIST_MODE_reg                                           0xb80274a0
#define DISPM_BIST_MODE_inst_addr                                     "0x0128"
#define DISPM_BIST_MODE_inst                                          0x0128
#define DISPM_BIST_MODE_dispm_bist_mode_mbist_disp_main_shift         (1)
#define DISPM_BIST_MODE_dispm_bist_mode_mbist_cap_main_shift          (0)
#define DISPM_BIST_MODE_dispm_bist_mode_mbist_disp_main_mask          (0x00000002)
#define DISPM_BIST_MODE_dispm_bist_mode_mbist_cap_main_mask           (0x00000001)
#define DISPM_BIST_MODE_dispm_bist_mode_mbist_disp_main(data)         (0x00000002&((data)<<1))
#define DISPM_BIST_MODE_dispm_bist_mode_mbist_cap_main(data)          (0x00000001&(data))
#define DISPM_BIST_MODE_get_dispm_bist_mode_mbist_disp_main(data)     ((0x00000002&(data))>>1)
#define DISPM_BIST_MODE_get_dispm_bist_mode_mbist_cap_main(data)      (0x00000001&(data))


#define DISPM_BIST_DONE                                               0x180274a4
#define DISPM_BIST_DONE_reg_addr                                      "0xb80274a4"
#define DISPM_BIST_DONE_reg                                           0xb80274a4
#define DISPM_BIST_DONE_inst_addr                                     "0x0129"
#define DISPM_BIST_DONE_inst                                          0x0129
#define DISPM_BIST_DONE_dispm_bist_done_mbist_disp_main_shift         (1)
#define DISPM_BIST_DONE_dispm_bist_done_mbist_cap_main_shift          (0)
#define DISPM_BIST_DONE_dispm_bist_done_mbist_disp_main_mask          (0x00000002)
#define DISPM_BIST_DONE_dispm_bist_done_mbist_cap_main_mask           (0x00000001)
#define DISPM_BIST_DONE_dispm_bist_done_mbist_disp_main(data)         (0x00000002&((data)<<1))
#define DISPM_BIST_DONE_dispm_bist_done_mbist_cap_main(data)          (0x00000001&(data))
#define DISPM_BIST_DONE_get_dispm_bist_done_mbist_disp_main(data)     ((0x00000002&(data))>>1)
#define DISPM_BIST_DONE_get_dispm_bist_done_mbist_cap_main(data)      (0x00000001&(data))


#define DISPM_BIST_FAIL_GROUP                                         0x180274a8
#define DISPM_BIST_FAIL_GROUP_reg_addr                                "0xb80274a8"
#define DISPM_BIST_FAIL_GROUP_reg                                     0xb80274a8
#define DISPM_BIST_FAIL_GROUP_inst_addr                               "0x012A"
#define DISPM_BIST_FAIL_GROUP_inst                                    0x012A
#define DISPM_BIST_FAIL_GROUP_dispm_bist_fail_group_mbist_disp_main_shift  (1)
#define DISPM_BIST_FAIL_GROUP_dispm_bist_fail_group_mbist_cap_main_shift  (0)
#define DISPM_BIST_FAIL_GROUP_dispm_bist_fail_group_mbist_disp_main_mask  (0x00000002)
#define DISPM_BIST_FAIL_GROUP_dispm_bist_fail_group_mbist_cap_main_mask  (0x00000001)
#define DISPM_BIST_FAIL_GROUP_dispm_bist_fail_group_mbist_disp_main(data)  (0x00000002&((data)<<1))
#define DISPM_BIST_FAIL_GROUP_dispm_bist_fail_group_mbist_cap_main(data)  (0x00000001&(data))
#define DISPM_BIST_FAIL_GROUP_get_dispm_bist_fail_group_mbist_disp_main(data)  ((0x00000002&(data))>>1)
#define DISPM_BIST_FAIL_GROUP_get_dispm_bist_fail_group_mbist_cap_main(data)  (0x00000001&(data))


#define DISPM_DRF_MODE                                                0x180274b0
#define DISPM_DRF_MODE_reg_addr                                       "0xb80274b0"
#define DISPM_DRF_MODE_reg                                            0xb80274b0
#define DISPM_DRF_MODE_inst_addr                                      "0x012C"
#define DISPM_DRF_MODE_inst                                           0x012C
#define DISPM_DRF_MODE_dispm_drf_mode_mbist_disp_main_shift           (1)
#define DISPM_DRF_MODE_dispm_drf_mode_mbist_cap_main_shift            (0)
#define DISPM_DRF_MODE_dispm_drf_mode_mbist_disp_main_mask            (0x00000002)
#define DISPM_DRF_MODE_dispm_drf_mode_mbist_cap_main_mask             (0x00000001)
#define DISPM_DRF_MODE_dispm_drf_mode_mbist_disp_main(data)           (0x00000002&((data)<<1))
#define DISPM_DRF_MODE_dispm_drf_mode_mbist_cap_main(data)            (0x00000001&(data))
#define DISPM_DRF_MODE_get_dispm_drf_mode_mbist_disp_main(data)       ((0x00000002&(data))>>1)
#define DISPM_DRF_MODE_get_dispm_drf_mode_mbist_cap_main(data)        (0x00000001&(data))


#define DISPM_DRF_RESUME                                              0x180274b4
#define DISPM_DRF_RESUME_reg_addr                                     "0xb80274b4"
#define DISPM_DRF_RESUME_reg                                          0xb80274b4
#define DISPM_DRF_RESUME_inst_addr                                    "0x012D"
#define DISPM_DRF_RESUME_inst                                         0x012D
#define DISPM_DRF_RESUME_dispm_drf_resume_mbist_disp_main_shift       (1)
#define DISPM_DRF_RESUME_dispm_drf_resume_mbist_cap_main_shift        (0)
#define DISPM_DRF_RESUME_dispm_drf_resume_mbist_disp_main_mask        (0x00000002)
#define DISPM_DRF_RESUME_dispm_drf_resume_mbist_cap_main_mask         (0x00000001)
#define DISPM_DRF_RESUME_dispm_drf_resume_mbist_disp_main(data)       (0x00000002&((data)<<1))
#define DISPM_DRF_RESUME_dispm_drf_resume_mbist_cap_main(data)        (0x00000001&(data))
#define DISPM_DRF_RESUME_get_dispm_drf_resume_mbist_disp_main(data)   ((0x00000002&(data))>>1)
#define DISPM_DRF_RESUME_get_dispm_drf_resume_mbist_cap_main(data)    (0x00000001&(data))


#define DISPM_DRF_DONE                                                0x180274b8
#define DISPM_DRF_DONE_reg_addr                                       "0xb80274b8"
#define DISPM_DRF_DONE_reg                                            0xb80274b8
#define DISPM_DRF_DONE_inst_addr                                      "0x012E"
#define DISPM_DRF_DONE_inst                                           0x012E
#define DISPM_DRF_DONE_dispm_drf_done_mbist_disp_main_shift           (1)
#define DISPM_DRF_DONE_dispm_drf_done_mbist_cap_main_shift            (0)
#define DISPM_DRF_DONE_dispm_drf_done_mbist_disp_main_mask            (0x00000002)
#define DISPM_DRF_DONE_dispm_drf_done_mbist_cap_main_mask             (0x00000001)
#define DISPM_DRF_DONE_dispm_drf_done_mbist_disp_main(data)           (0x00000002&((data)<<1))
#define DISPM_DRF_DONE_dispm_drf_done_mbist_cap_main(data)            (0x00000001&(data))
#define DISPM_DRF_DONE_get_dispm_drf_done_mbist_disp_main(data)       ((0x00000002&(data))>>1)
#define DISPM_DRF_DONE_get_dispm_drf_done_mbist_cap_main(data)        (0x00000001&(data))


#define DISPM_DRF_PAUSE                                               0x180274bc
#define DISPM_DRF_PAUSE_reg_addr                                      "0xb80274bc"
#define DISPM_DRF_PAUSE_reg                                           0xb80274bc
#define DISPM_DRF_PAUSE_inst_addr                                     "0x012F"
#define DISPM_DRF_PAUSE_inst                                          0x012F
#define DISPM_DRF_PAUSE_dispm_drf_pause_mbist_disp_main_shift         (1)
#define DISPM_DRF_PAUSE_dispm_drf_pause_mbist_cap_main_shift          (0)
#define DISPM_DRF_PAUSE_dispm_drf_pause_mbist_disp_main_mask          (0x00000002)
#define DISPM_DRF_PAUSE_dispm_drf_pause_mbist_cap_main_mask           (0x00000001)
#define DISPM_DRF_PAUSE_dispm_drf_pause_mbist_disp_main(data)         (0x00000002&((data)<<1))
#define DISPM_DRF_PAUSE_dispm_drf_pause_mbist_cap_main(data)          (0x00000001&(data))
#define DISPM_DRF_PAUSE_get_dispm_drf_pause_mbist_disp_main(data)     ((0x00000002&(data))>>1)
#define DISPM_DRF_PAUSE_get_dispm_drf_pause_mbist_cap_main(data)      (0x00000001&(data))


#define DISPM_DRF_FAIL_GROUP                                          0x180274c0
#define DISPM_DRF_FAIL_GROUP_reg_addr                                 "0xb80274c0"
#define DISPM_DRF_FAIL_GROUP_reg                                      0xb80274c0
#define DISPM_DRF_FAIL_GROUP_inst_addr                                "0x0130"
#define DISPM_DRF_FAIL_GROUP_inst                                     0x0130
#define DISPM_DRF_FAIL_GROUP_dispm_drf_fail_group_mbist_disp_main_shift  (1)
#define DISPM_DRF_FAIL_GROUP_dispm_drf_fail_group_mbist_cap_main_shift  (0)
#define DISPM_DRF_FAIL_GROUP_dispm_drf_fail_group_mbist_disp_main_mask  (0x00000002)
#define DISPM_DRF_FAIL_GROUP_dispm_drf_fail_group_mbist_cap_main_mask (0x00000001)
#define DISPM_DRF_FAIL_GROUP_dispm_drf_fail_group_mbist_disp_main(data)  (0x00000002&((data)<<1))
#define DISPM_DRF_FAIL_GROUP_dispm_drf_fail_group_mbist_cap_main(data)  (0x00000001&(data))
#define DISPM_DRF_FAIL_GROUP_get_dispm_drf_fail_group_mbist_disp_main(data)  ((0x00000002&(data))>>1)
#define DISPM_DRF_FAIL_GROUP_get_dispm_drf_fail_group_mbist_cap_main(data)  (0x00000001&(data))


#define DISPM_RM                                                      0x180274c4
#define DISPM_RM_reg_addr                                             "0xb80274c4"
#define DISPM_RM_reg                                                  0xb80274c4
#define DISPM_RM_inst_addr                                            "0x0131"
#define DISPM_RM_inst                                                 0x0131
#define DISPM_RM_dispm_rmb_mbist_disp_main_shift                      (20)
#define DISPM_RM_dispm_rma_mbist_disp_main_shift                      (16)
#define DISPM_RM_dispm_rmb_mbist_cap_main_shift                       (4)
#define DISPM_RM_dispm_rma_mbist_cap_main_shift                       (0)
#define DISPM_RM_dispm_rmb_mbist_disp_main_mask                       (0x00F00000)
#define DISPM_RM_dispm_rma_mbist_disp_main_mask                       (0x000F0000)
#define DISPM_RM_dispm_rmb_mbist_cap_main_mask                        (0x000000F0)
#define DISPM_RM_dispm_rma_mbist_cap_main_mask                        (0x0000000F)
#define DISPM_RM_dispm_rmb_mbist_disp_main(data)                      (0x00F00000&((data)<<20))
#define DISPM_RM_dispm_rma_mbist_disp_main(data)                      (0x000F0000&((data)<<16))
#define DISPM_RM_dispm_rmb_mbist_cap_main(data)                       (0x000000F0&((data)<<4))
#define DISPM_RM_dispm_rma_mbist_cap_main(data)                       (0x0000000F&(data))
#define DISPM_RM_get_dispm_rmb_mbist_disp_main(data)                  ((0x00F00000&(data))>>20)
#define DISPM_RM_get_dispm_rma_mbist_disp_main(data)                  ((0x000F0000&(data))>>16)
#define DISPM_RM_get_dispm_rmb_mbist_cap_main(data)                   ((0x000000F0&(data))>>4)
#define DISPM_RM_get_dispm_rma_mbist_cap_main(data)                   (0x0000000F&(data))


#define DISPM_RME                                                     0x180274c8
#define DISPM_RME_reg_addr                                            "0xb80274c8"
#define DISPM_RME_reg                                                 0xb80274c8
#define DISPM_RME_inst_addr                                           "0x0132"
#define DISPM_RME_inst                                                0x0132
#define DISPM_RME_dispm_rmeb_mbist_disp_main_shift                    (5)
#define DISPM_RME_dispm_rmea_mbist_disp_main_shift                    (4)
#define DISPM_RME_dispm_rmeb_mbist_cap_main_shift                     (1)
#define DISPM_RME_dispm_rmea_mbist_cap_main_shift                     (0)
#define DISPM_RME_dispm_rmeb_mbist_disp_main_mask                     (0x00000020)
#define DISPM_RME_dispm_rmea_mbist_disp_main_mask                     (0x00000010)
#define DISPM_RME_dispm_rmeb_mbist_cap_main_mask                      (0x00000002)
#define DISPM_RME_dispm_rmea_mbist_cap_main_mask                      (0x00000001)
#define DISPM_RME_dispm_rmeb_mbist_disp_main(data)                    (0x00000020&((data)<<5))
#define DISPM_RME_dispm_rmea_mbist_disp_main(data)                    (0x00000010&((data)<<4))
#define DISPM_RME_dispm_rmeb_mbist_cap_main(data)                     (0x00000002&((data)<<1))
#define DISPM_RME_dispm_rmea_mbist_cap_main(data)                     (0x00000001&(data))
#define DISPM_RME_get_dispm_rmeb_mbist_disp_main(data)                ((0x00000020&(data))>>5)
#define DISPM_RME_get_dispm_rmea_mbist_disp_main(data)                ((0x00000010&(data))>>4)
#define DISPM_RME_get_dispm_rmeb_mbist_cap_main(data)                 ((0x00000002&(data))>>1)
#define DISPM_RME_get_dispm_rmea_mbist_cap_main(data)                 (0x00000001&(data))


#define DISPM_LS                                                      0x180274cc
#define DISPM_LS_reg_addr                                             "0xb80274cc"
#define DISPM_LS_reg                                                  0xb80274cc
#define DISPM_LS_inst_addr                                            "0x0133"
#define DISPM_LS_inst                                                 0x0133
#define DISPM_LS_dispm_ls_mbist_disp_main_shift                       (2)
#define DISPM_LS_dispm_ls_mbist_cap_main_shift                        (0)
#define DISPM_LS_dispm_ls_mbist_disp_main_mask                        (0x00000004)
#define DISPM_LS_dispm_ls_mbist_cap_main_mask                         (0x00000001)
#define DISPM_LS_dispm_ls_mbist_disp_main(data)                       (0x00000004&((data)<<2))
#define DISPM_LS_dispm_ls_mbist_cap_main(data)                        (0x00000001&(data))
#define DISPM_LS_get_dispm_ls_mbist_disp_main(data)                   ((0x00000004&(data))>>2)
#define DISPM_LS_get_dispm_ls_mbist_cap_main(data)                    (0x00000001&(data))


#define DISPM_DECOMP_RM                                               0x180274d0
#define DISPM_DECOMP_RM_reg_addr                                      "0xb80274d0"
#define DISPM_DECOMP_RM_reg                                           0xb80274d0
#define DISPM_DECOMP_RM_inst_addr                                     "0x0134"
#define DISPM_DECOMP_RM_inst                                          0x0134


#define DISP_DMA_RATE_CTRL                                            0x180274f0
#define DISP_DMA_RATE_CTRL_reg_addr                                   "0xb80274f0"
#define DISP_DMA_RATE_CTRL_reg                                        0xb80274f0
#define DISP_DMA_RATE_CTRL_inst_addr                                  "0x013C"
#define DISP_DMA_RATE_CTRL_inst                                       0x013C
#define DISP_DMA_RATE_CTRL_main_rate_en_shift                         (0)
#define DISP_DMA_RATE_CTRL_main_rate_en_mask                          (0x00000001)
#define DISP_DMA_RATE_CTRL_main_rate_en(data)                         (0x00000001&(data))
#define DISP_DMA_RATE_CTRL_get_main_rate_en(data)                     (0x00000001&(data))


#define DISPLAY_RATE                                                  0x180274f4
#define DISPLAY_RATE_reg_addr                                         "0xb80274f4"
#define DISPLAY_RATE_reg                                              0xb80274f4
#define DISPLAY_RATE_inst_addr                                        "0x013D"
#define DISPLAY_RATE_inst                                             0x013D
#define DISPLAY_RATE_main_rate_shift                                  (0)
#define DISPLAY_RATE_main_rate_mask                                   (0xFFFFFFFF)
#define DISPLAY_RATE_main_rate(data)                                  (0xFFFFFFFF&(data))
#define DISPLAY_RATE_get_main_rate(data)                              (0xFFFFFFFF&(data))


#define DISPLAY_BYTE_CHANNEL_SWAP                                     0x180274f8
#define DISPLAY_BYTE_CHANNEL_SWAP_reg_addr                            "0xb80274f8"
#define DISPLAY_BYTE_CHANNEL_SWAP_reg                                 0xb80274f8
#define DISPLAY_BYTE_CHANNEL_SWAP_inst_addr                           "0x013E"
#define DISPLAY_BYTE_CHANNEL_SWAP_inst                                0x013E
#define DISPLAY_BYTE_CHANNEL_SWAP_main_channel_swap_shift             (4)
#define DISPLAY_BYTE_CHANNEL_SWAP_main_8byte_swap_shift               (3)
#define DISPLAY_BYTE_CHANNEL_SWAP_main_4byte_swap_shift               (2)
#define DISPLAY_BYTE_CHANNEL_SWAP_main_2byte_swap_shift               (1)
#define DISPLAY_BYTE_CHANNEL_SWAP_main_1byte_swap_shift               (0)
#define DISPLAY_BYTE_CHANNEL_SWAP_main_channel_swap_mask              (0x00000070)
#define DISPLAY_BYTE_CHANNEL_SWAP_main_8byte_swap_mask                (0x00000008)
#define DISPLAY_BYTE_CHANNEL_SWAP_main_4byte_swap_mask                (0x00000004)
#define DISPLAY_BYTE_CHANNEL_SWAP_main_2byte_swap_mask                (0x00000002)
#define DISPLAY_BYTE_CHANNEL_SWAP_main_1byte_swap_mask                (0x00000001)
#define DISPLAY_BYTE_CHANNEL_SWAP_main_channel_swap(data)             (0x00000070&((data)<<4))
#define DISPLAY_BYTE_CHANNEL_SWAP_main_8byte_swap(data)               (0x00000008&((data)<<3))
#define DISPLAY_BYTE_CHANNEL_SWAP_main_4byte_swap(data)               (0x00000004&((data)<<2))
#define DISPLAY_BYTE_CHANNEL_SWAP_main_2byte_swap(data)               (0x00000002&((data)<<1))
#define DISPLAY_BYTE_CHANNEL_SWAP_main_1byte_swap(data)               (0x00000001&(data))
#define DISPLAY_BYTE_CHANNEL_SWAP_get_main_channel_swap(data)         ((0x00000070&(data))>>4)
#define DISPLAY_BYTE_CHANNEL_SWAP_get_main_8byte_swap(data)           ((0x00000008&(data))>>3)
#define DISPLAY_BYTE_CHANNEL_SWAP_get_main_4byte_swap(data)           ((0x00000004&(data))>>2)
#define DISPLAY_BYTE_CHANNEL_SWAP_get_main_2byte_swap(data)           ((0x00000002&(data))>>1)
#define DISPLAY_BYTE_CHANNEL_SWAP_get_main_1byte_swap(data)           (0x00000001&(data))
#endif
