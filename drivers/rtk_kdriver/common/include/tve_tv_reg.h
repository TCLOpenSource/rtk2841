/**************************************************************
// Spec Version                  : 0.0.1
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2013/6/5 14:3:2
***************************************************************/


#ifndef _TVE_REG_H_INCLUDED_
#define _TVE_REG_H_INCLUDED_
#ifdef  _TVE_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     write_en6:1;
unsigned int     ph_sync_go:1;
unsigned int     write_en5:1;
unsigned int     hi_sync_go:1;
unsigned int     write_en4:1;
unsigned int     pi_sync_go:1;
unsigned int     write_en3:1;
unsigned int     i_sync_go:1;
unsigned int     write_en2:1;
unsigned int     p_sync_go:1;
unsigned int     write_en1:1;
unsigned int     h_sync_go:1;
}SYNCGEN_RST;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     v_thr:11;
unsigned int     write_en1:1;
unsigned int     h_thr:13;
}SYNCGEN_I;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     write_en3:1;
unsigned int     i_p_sel:1;
unsigned int     write_en2:1;
unsigned int     v_thr:11;
unsigned int     write_en1:1;
unsigned int     h_thr:13;
}SYNCGEN_P;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     write_en4:1;
unsigned int     mode_1080i:1;
unsigned int     write_en3:1;
unsigned int     i_p_sel:1;
unsigned int     write_en2:1;
unsigned int     v_thr:11;
unsigned int     write_en1:1;
unsigned int     h_thr:13;
}SYNCGEN_HDMI;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     comp_ebl:1;
unsigned int     sdtv_ebl:1;
unsigned int     vs_polar:1;
unsigned int     hs_polar:1;
unsigned int     vga_hvsync:1;
unsigned int     comp_sel:1;
unsigned int     sync_rb_ebl:1;
unsigned int     sync_g_ebl:1;
unsigned int     rgb_mod:1;
unsigned int     vbi_rb_ebl:1;
unsigned int     vbi_g_ebl:1;
unsigned int     hdsync:1;
unsigned int     syncmod_sel:1;
unsigned int     write_data:1;
}COMP_CTRL;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     i_field:1;
unsigned int     i_vcnt:11;
unsigned int     p_field:1;
unsigned int     p_vcnt:11;
}SYNCGEN_STATUS_I;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     h_field:1;
unsigned int     h_vcnt:11;
}SYNCGEN_STATUS_H;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     inten_vbi_h:1;
unsigned int     inten_vbi_i:1;
unsigned int     inten_vbi_p:1;
unsigned int     inten_h:1;
unsigned int     inten_i:1;
unsigned int     inten_p:1;
unsigned int     write_data:1;
}INTEN;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     intst_vbi_h:1;
unsigned int     intst_vbi_i:1;
unsigned int     intst_vbi_p:1;
unsigned int     intst_h:1;
unsigned int     intst_i:1;
unsigned int     intst_p:1;
unsigned int     write_data:1;
}INTST;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     int_vpos:11;
unsigned int     write_en1:1;
unsigned int     int_hpos:13;
}INTPOS_I;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     int_vpos:11;
unsigned int     write_en1:1;
unsigned int     int_hpos:13;
}INTPOS_P1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     int_vpos:11;
unsigned int     write_en1:1;
unsigned int     int_hpos:13;
}INTPOS_P2;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     int_vpos:11;
unsigned int     write_en1:1;
unsigned int     int_hpos:13;
}INTPOS_H1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     int_vpos:11;
unsigned int     write_en1:1;
unsigned int     int_hpos:13;
}INTPOS_H2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     srstn:1;
}SRSTN;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     h_colorbar_ebl:1;
unsigned int     h_black_ebl:1;
unsigned int     i_colorbar_ebl:1;
unsigned int     p_colorbar_ebl:1;
unsigned int     i_black_ebl:1;
unsigned int     p_black_ebl:1;
unsigned int     write_data:1;
}AV_CTRL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     fir422_sel:2;
}CAV_422;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     write_en4:1;
unsigned int     i_en:1;
unsigned int     write_en3:1;
unsigned int     p_en:1;
unsigned int     write_en2:1;
unsigned int     i_slewrate:2;
unsigned int     write_en1:1;
unsigned int     p_slewrate:2;
}AV_SLEW;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     write_en2:1;
unsigned int     i_h_st:10;
unsigned int     write_en1:1;
unsigned int     i_h_end:10;
}SLEW_I_HPOS;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     write_en2:1;
unsigned int     i_h_st:13;
unsigned int     write_en1:1;
unsigned int     i_h_end:13;
}AV_I_HPOS;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     write_en3:1;
unsigned int     p_av_cord:1;
unsigned int     write_en2:1;
unsigned int     p_h_st:13;
unsigned int     write_en1:1;
unsigned int     p_h_end:13;
}AV_P_HPOS1;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     write_en3:1;
unsigned int     h_av_cord:1;
unsigned int     write_en2:1;
unsigned int     h_h_st:13;
unsigned int     write_en1:1;
unsigned int     h_h_end:13;
}AV_H_HPOS1;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     itop_v_st:11;
unsigned int     write_en1:1;
unsigned int     itop_v_end:11;
}ITOP_VPOS;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     ibot_v_st:11;
unsigned int     write_en1:1;
unsigned int     ibot_v_end:11;
}IBOT_VPOS;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     p_v_st:11;
unsigned int     write_en1:1;
unsigned int     p_v_end:11;
}P_VPOS1;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     p_v_st:11;
unsigned int     write_en1:1;
unsigned int     p_v_end:11;
}P_VPOS2;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     h_v_st:11;
unsigned int     write_en1:1;
unsigned int     h_v_end:11;
}H_VPOS1;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     h_v_st:11;
unsigned int     write_en1:1;
unsigned int     h_v_end:11;
}H_VPOS2;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     write_en2:1;
unsigned int     i_h_width:10;
unsigned int     write_en1:1;
unsigned int     i_h_st_pos:10;
}I_COLORBAR_HPOS;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     write_en2:1;
unsigned int     p_h_width:10;
unsigned int     write_en1:1;
unsigned int     p_h_st_pos:10;
}P_COLORBAR_HPOS;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     write_en2:1;
unsigned int     p_h_width:10;
unsigned int     write_en1:1;
unsigned int     p_h_st_pos:10;
}H_COLORBAR_HPOS;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     write_en3:1;
unsigned int     negsyncst:9;
unsigned int     write_en2:1;
unsigned int     possyncst:9;
unsigned int     write_en1:1;
unsigned int     syncend:9;
}COMP_VSYNC_HPOS;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     1080i_ebl:1;
}COMP_SER_CTRL;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     write_en2:1;
unsigned int     ser_hstart:13;
unsigned int     write_en1:1;
unsigned int     ser_hend:13;
}COMP_SER_HPOS;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     write_en2:1;
unsigned int     ser_vstart:5;
unsigned int     write_en1:1;
unsigned int     ser_vend:5;
}COMP_SER_VPOS;

typedef struct 
{
unsigned int     write_en4:1;
unsigned int     dsync_b_vstart:10;
unsigned int     write_en3:1;
unsigned int     dsync_b_vend:10;
unsigned int     write_en2:1;
unsigned int     dsync_t_vstart:4;
unsigned int     write_en1:1;
unsigned int     dsync_t_vend:4;
}COMP_DSYNC_VPOS;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     write_en2:1;
unsigned int     hs_start:13;
unsigned int     write_en1:1;
unsigned int     hs_end:13;
}VGA_HSYNC_HPOS;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     vs_st_posv:11;
unsigned int     write_en1:1;
unsigned int     vs_st_posh:13;
}VGA_VSYNC_ST_POS;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     vs_end_posv:11;
unsigned int     write_en1:1;
unsigned int     vs_end_posh:13;
}VGA_VSYNC_END_POS;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     write_en2:1;
unsigned int     ip_vsync_pos1:10;
unsigned int     write_en1:1;
unsigned int     ip_vsync_pos2:10;
}IP_VSYNCPOS;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     hthr:11;
}IP_HSYNCPOS;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     write_en4:1;
unsigned int     sync_en:1;
unsigned int     write_en3:1;
unsigned int     ch_sel:1;
unsigned int     write_en2:1;
unsigned int     vpos:11;
unsigned int     write_en1:1;
unsigned int     hpos:13;
}HDMI_ST;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     write_en2:1;
unsigned int     hs_start:13;
unsigned int     write_en1:1;
unsigned int     hs_end:13;
}HDMI_DISP_HS;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     vs_st_pos1v:11;
unsigned int     write_en1:1;
unsigned int     vs_st_pos1h:13;
}HDMI_DISP_VSST1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     vs_end_pos1v:11;
unsigned int     write_en1:1;
unsigned int     vs_end_pos1h:13;
}HDMI_DISP_VSED1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     vs_st_pos2v:11;
unsigned int     write_en1:1;
unsigned int     vs_st_pos2h:13;
}HDMI_DISP_VSST2;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     vs_end_pos2v:11;
unsigned int     write_en1:1;
unsigned int     vs_end_pos2h:13;
}HDMI_DISP_VSED2;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     write_en2:1;
unsigned int     hpos_end:13;
unsigned int     write_en1:1;
unsigned int     hpos_st:13;
}HDMI_PXLACT;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     write_en3:1;
unsigned int     slewrate:2;
unsigned int     write_en2:1;
unsigned int     y_negsynclvl:12;
unsigned int     write_en1:1;
unsigned int     y_possynclvl:12;
}COMP_SYNCLVL;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     y_sync_h:12;
unsigned int     write_en1:1;
unsigned int     y_sync_m:12;
}COMP_SYNC_SLEWLVL;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     y_sync_l:12;
unsigned int     write_en1:1;
unsigned int     bp_lvl:12;
}COMP_BP_LVL;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     pbpr_negsynclvl:12;
unsigned int     write_en1:1;
unsigned int     pbpr_possynclvl:12;
}COMP_PBPR_SYNCLVL;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     y_blank_lvl:12;
unsigned int     write_en1:1;
unsigned int     pbpr_blank_lvl:12;
}COMP_PBPR_BLNKLVL;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     g_up:12;
unsigned int     write_en1:1;
unsigned int     g_dn:12;
}COMP_G_CLMPLVL;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     rb_up:12;
unsigned int     write_en1:1;
unsigned int     rb_dn:12;
}COMP_RB_CLMPLVL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     y_black_lvl:8;
}IP_INPUT;

typedef struct 
{
unsigned int     write_en2:1;
unsigned int     gain:15;
unsigned int     write_en1:1;
unsigned int     offset:15;
}VBI_COEFF;

typedef struct 
{
unsigned int     write_en2:1;
unsigned int     gain:15;
unsigned int     write_en1:1;
unsigned int     offset:15;
}BLNK_COEFF;

typedef struct 
{
unsigned int     write_en2:1;
unsigned int     c2:15;
unsigned int     write_en1:1;
unsigned int     c1:15;
}AV_COEFF1;

typedef struct 
{
unsigned int     write_en2:1;
unsigned int     c3:15;
unsigned int     write_en1:1;
unsigned int     c4:15;
}AV_COEFF2;

typedef struct 
{
unsigned int     write_en2:1;
unsigned int     c5:15;
unsigned int     write_en1:1;
unsigned int     c6:15;
}AV_COEFF3;

typedef struct 
{
unsigned int     write_en2:1;
unsigned int     k1:15;
unsigned int     write_en1:1;
unsigned int     k2:15;
}AV_COEFF4;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     write_en1:1;
unsigned int     vbi_gain_ebl:1;
unsigned int     write_en2:1;
unsigned int     k3:15;
}AV_COEFF5;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     mv_rb_ebl:1;
unsigned int     mv_g_ebl:1;
unsigned int     mv_ebl:1;
unsigned int     write_data:1;
}MV_CTRL;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     write_en2:1;
unsigned int     mv_end_line:6;
unsigned int     write_en1:1;
unsigned int     mv_st_line:6;
}MV_VPOS;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     write_en4:1;
unsigned int     mv_st_ps:8;
unsigned int     write_en3:1;
unsigned int     mv_ps_len:6;
unsigned int     write_en2:1;
unsigned int     mv_agc_len:6;
unsigned int     write_en1:1;
unsigned int     mv_blnk_len:6;
}MV_LEN;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     mv_rd:20;
}MV_RD;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     mv_dn:20;
}MV_DN;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     mv_ru:20;
}MV_RU;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     mv_up:20;
}MV_UP;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     write_en3:1;
unsigned int     mv_ru_dlt:8;
unsigned int     write_en2:1;
unsigned int     mv_rd_dlt:8;
unsigned int     write_en1:1;
unsigned int     mv_stn:12;
}MV_LVL;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     write_en3:1;
unsigned int     cgms_i_ebl:1;
unsigned int     write_en2:1;
unsigned int     cgms_p_ebl:1;
unsigned int     write_en1:1;
unsigned int     cgms_data:20;
}CGMS_CTRL;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     cgms_data:20;
}CGMS_CTRL1;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     write_en2:1;
unsigned int     cgms_i_vpos1:9;
unsigned int     write_en1:1;
unsigned int     cgms_i_vpos2:10;
}CGMS_I_VPOS;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     write_en2:1;
unsigned int     cgms_p_vpos2:11;
unsigned int     write_en1:1;
unsigned int     cgms_p_vpos1:10;
}CGMS_P_VPOS;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     write_en2:1;
unsigned int     cgms_i_hst:10;
unsigned int     write_en1:1;
unsigned int     cgms_i_len:10;
}CGMS_I_HPOS;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     write_en3:1;
unsigned int     cgms_p_lvl:8;
unsigned int     write_en2:1;
unsigned int     cgms_p_hst:10;
unsigned int     write_en1:1;
unsigned int     cgms_p_len:10;
}CGMS_P_HPOS;

typedef struct 
{
unsigned int     reserved_0:7;
unsigned int     write_en3:1;
unsigned int     cgms_p_b_ebl:1;
unsigned int     write_en2:1;
unsigned int     cgms_p2_vpos2:11;
unsigned int     write_en1:1;
unsigned int     cgms_p2_vpos1:10;
}CGMS_P2_VPOS;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     write_en3:1;
unsigned int     cgms_p2_lvl:8;
unsigned int     write_en2:1;
unsigned int     cgms_p2_hst:10;
unsigned int     write_en1:1;
unsigned int     cgms_p2_len:10;
}CGMS_P2_HPOS;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     cgms_hdr:6;
}CGMS_B_HDR;

typedef struct 
{
unsigned int     cgms_data:32;
}CGMS_B_DATA;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     write_en4:1;
unsigned int     wss_ebl:1;
unsigned int     write_en3:1;
unsigned int     wss_intp_sel:1;
unsigned int     write_en2:1;
unsigned int     wss_end_hpos:11;
unsigned int     write_en1:1;
unsigned int     wss_data:14;
}WSS_CTRL;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     write_en2:1;
unsigned int     wss_h_pos:11;
unsigned int     write_en1:1;
unsigned int     wss_v_pos:10;
}WSS_POS;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     write_en3:1;
unsigned int     wss_ebl:1;
unsigned int     write_en2:1;
unsigned int     wss_intp_sel:1;
unsigned int     write_en1:1;
unsigned int     wss_data:14;
}TVE_625P_WSS_CTRL;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     write_en2:1;
unsigned int     wss_h_pos:11;
unsigned int     write_en1:1;
unsigned int     wss_v_pos:10;
}TVE_625P_WSS_POS;

typedef struct 
{
unsigned int     reserved_0:5;
unsigned int     write_en5:1;
unsigned int     tt_bit_swap:1;
unsigned int     write_en4:1;
unsigned int     tt_h_st:11;
unsigned int     write_en3:1;
unsigned int     tt_line_no:8;
unsigned int     write_en2:1;
unsigned int     tt_intp_sel:1;
unsigned int     write_en1:1;
unsigned int     vbi_tt_ebl:1;
}TT_CTRL;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     write_en2:1;
unsigned int     tt_b_vst:9;
unsigned int     write_en1:1;
unsigned int     tt_t_vst:5;
}TT_VPOS;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     start_line2:11;
unsigned int     write_en1:1;
unsigned int     start_line1:11;
}TT_MASK_VPOS;

typedef struct 
{
unsigned int     tt_line_mask:32;
}TT_MASK_FLG;

typedef struct 
{
unsigned int     reserved_0:5;
unsigned int     write_en4:1;
unsigned int     vps_h_pos:11;
unsigned int     write_en3:1;
unsigned int     vps_v_pos:10;
unsigned int     write_en2:1;
unsigned int     vps_intp_sel:1;
unsigned int     write_en1:1;
unsigned int     vbi_vps_ebl:1;
}VPS_CTRL;

typedef struct 
{
unsigned int     vps_data:32;
}VPS_DATA;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     vps_data:8;
}VPS_DATA1;

typedef struct 
{
unsigned int     write_en4:1;
unsigned int     dwn_ebl:2;
unsigned int     write_en3:1;
unsigned int     dwn_i_p_sel:1;
unsigned int     write_en2:1;
unsigned int     dwn_st_i:12;
unsigned int     write_en1:1;
unsigned int     dwn_end_i:13;
}VBI_DWN_CTRL;

typedef struct 
{
unsigned int     reserved_0:5;
unsigned int     write_en2:1;
unsigned int     dwn_st_p:12;
unsigned int     write_en1:1;
unsigned int     dwn_end_p:13;
}VBI_DWN_HPOS;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     vbi_start_line2:11;
unsigned int     write_en1:1;
unsigned int     vbi_start_line1:11;
}VBI_DWN_VPOS_I;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     vbi_start_line2:11;
unsigned int     write_en1:1;
unsigned int     vbi_start_line1:11;
}VBI_DWN_VPOS_P;

typedef struct 
{
unsigned int     vbi_line_flg:32;
}VBI_LINE_FLAG_I;

typedef struct 
{
unsigned int     vbi_line_flg:32;
}VBI_LINE_FLAG_P;

typedef struct 
{
unsigned int     vbi_pty:32;
}VBI_LINE_PTY_I;

typedef struct 
{
unsigned int     vbi_pty:32;
}VBI_LINE_PTY_P;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     write_en3:1;
unsigned int     di_i_p_sel:2;
unsigned int     write_en2:1;
unsigned int     hact_start:13;
unsigned int     write_en1:1;
unsigned int     hact_end:13;
}DIF_HACTIVE;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     cd:1;
unsigned int     di_bus_swap:1;
unsigned int     di_clk_phs:1;
unsigned int     di_fpga_clk_sel:1;
unsigned int     di_vbi_bypass:1;
unsigned int     di_ebl:1;
unsigned int     di_source_sel:1;
unsigned int     di_mod:1;
unsigned int     di_hdr_ebl:1;
unsigned int     write_data:1;
}DIF_CTRL;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     write_en3:1;
unsigned int     hs_polar:1;
unsigned int     write_en2:1;
unsigned int     hs_start:13;
unsigned int     write_en1:1;
unsigned int     hs_end:13;
}DIF_HSYNC;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     write_en3:1;
unsigned int     vs_polar:1;
unsigned int     write_en2:1;
unsigned int     vs_st_pos1v:11;
unsigned int     write_en1:1;
unsigned int     vs_st_pos1h:13;
}DIF_VS_ST_POS1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     vs_end_pos1v:11;
unsigned int     write_en1:1;
unsigned int     vs_end_pos1h:13;
}DIF_VS_END_POS1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     vs_st_pos2v:11;
unsigned int     write_en1:1;
unsigned int     vs_st_pos2h:13;
}DIF_VS_ST_POS2;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     vs_end_pos2v:11;
unsigned int     write_en1:1;
unsigned int     vs_end_pos2h:13;
}DIF_VS_END_POS2;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     v_tgl_hi:11;
unsigned int     write_en1:1;
unsigned int     v_tgl_lo:11;
}DIF_F_BIT_POS;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     v_tgl1_hi:11;
unsigned int     write_en1:1;
unsigned int     v_tgl1_lo:11;
}DIF_V_BIT_POS1;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_en2:1;
unsigned int     v_tgl2_hi:11;
unsigned int     write_en1:1;
unsigned int     v_tgl2_lo:11;
}DIF_V_BIT_POS2;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     write_en2:1;
unsigned int     fv_start:13;
unsigned int     write_en1:1;
unsigned int     fv_end:13;
}DIF_FV_BIT_HPOS;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     phi:8;
}IP_PHS;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     sctoh:8;
}IP_SCTOH;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     u_invert:1;
unsigned int     v_invert:1;
unsigned int     t_offset_phase:1;
unsigned int     t_reset_fsc:1;
}IP_F_CTRL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     t_sel_sin:1;
unsigned int     t_fsc_rom:1;
}IP_T_SEL_SIN;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     black_lvl:8;
}IP_BLCK_LVL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     blank_lvl:8;
}IP_BLNK_LVL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     clamp_lvl:8;
}IP_CLAMP_LVL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     sync_lvl:8;
}IP_SYNC_LVL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     y_interp:2;
unsigned int     y_colorbar_en:1;
unsigned int     t_ydel_adj:3;
unsigned int     t_sel_ylpf:1;
unsigned int     t_ygain_val:1;
}IP_Y_CTRL;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     t_byp_yups:1;
unsigned int     t_sel_ylp:1;
unsigned int     t_ygain_off:1;
unsigned int     y_tsin_cos:1;
unsigned int     y_tsel_dac_tst:1;
unsigned int     y_tdig_out:2;
}IP_TEST_PARAM;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     y_gain:10;
}IP_Y_GAIN;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     sync_lvl_h:8;
}IP_SYNC_LVL2;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     sync_lvl_m:8;
}IP_SYNC_LVL3;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     sync_lvl_l:8;
}IP_SYNC_LVL4;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     y_tsel_yuv:1;
unsigned int     t_pd_cvdac:1;
unsigned int     t_pd_ydac:1;
unsigned int     t_pd_cdac:1;
}IP_O_CTRL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     nba:8;
}IP_NBA;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     pba:8;
}IP_PBA;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     t_pal_clpf:1;
unsigned int     t_sel_c_gain:1;
}IP_C_CTRL;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     t_byp_cups:1;
unsigned int     t_byp_clpf:1;
unsigned int     t_c_gain_off:1;
}IP_TEST_T_BYP_CUPS;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     clpf_gain:8;
}IP_SYNCLPF_GAIN;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     t_hsync_phs:1;
unsigned int     t_vsync_phs:1;
unsigned int     y_tsyncmode:3;
unsigned int     y_tencd_mode:3;
}IP_S_CTRL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     clk_phs:2;
unsigned int     t_fsync_enbl:1;
unsigned int     t_fsync_phs:1;
unsigned int     reserved_1:2;
unsigned int     vso:2;
}IP_VSO0;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     vso:8;
}IP_VSO1;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     hso:3;
}IP_HSO0;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     hso:8;
}IP_HSO1;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     hlc:2;
}IP_HLC0;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     hlc:8;
}IP_HLC1;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ccd_odd:8;
}IP_CCD_ODD;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     ccd_even:8;
}IP_CCD_EVEN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     cc_enbl:2;
}IP_CCD_ENBL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     hlr:2;
}IP_TEST_HLR0;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     hlr:8;
}IP_TEST_HLR1;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     vsmr:5;
}IP_TEST_VSMR;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     sync_strt:4;
}IP_SYNC_STRT;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     sync_end:7;
}IP_SYNC_END;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     sync_srend:8;
}IP_SYNC_SREND;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     sync_eqend:6;
}IP_SYNC_EQEND;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     actv_strt:8;
}IP_ACTV_STRT;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     actv_end:8;
}IP_ACTV_END;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     wbrst_strt:7;
}IP_WBRST_STRT;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     nbrst_strt:7;
}IP_NBRST_STRT;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     nbrst_end:8;
}IP_NBRST_END;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvfcr:8;
}IP_MVFCR;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvcsl1:8;
}IP_MVCSL1;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     mvcls1:6;
}IP_MVCLS1;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvcsl2:8;
}IP_MVCSL2;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     mvcls2:6;
}IP_MVCLS2;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvcssp:3;
unsigned int     mvcsnum:3;
unsigned int     mvcsln:2;
}IP_MVCSSP;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     mvpsd:6;
}IP_MVPSD;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     mvpsl:6;
}IP_MVPSL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     mvpss:6;
}IP_MVPSS;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     mvpsls:7;
}IP_MVPSLS0;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvpsls:8;
}IP_MVPSLS1;

typedef struct 
{
unsigned int     reserved_0:25;
unsigned int     mvpsfs:7;
}IP_MVPSFS0;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvpsfs:8;
}IP_MVPSFS1;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvpsagca:8;
}IP_MVPSAGCA;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvpsagcb:8;
}IP_MVPSAGCB;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mveofbpc:8;
}IP_MVEOFBPC;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvpbz1:4;
unsigned int     mvpbz2:4;
}IP_MVPBZ1;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvpbz3:4;
unsigned int     mvpadvbsen:1;
unsigned int     mvpzninvrt:3;
}IP_MVPBZ3;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvpcslimd_lsb:8;
}IP_MVPCSLIMD0;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     mvpcslimd_msb:2;
}IP_MVPCSLIMD1;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     mvtms:8;
}IP_MV_CTRL;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     vdac_apow:1;
unsigned int     vdac_bpow:1;
unsigned int     vdac_cpow:1;
unsigned int     powldv_l:1;
unsigned int     stanby_l:1;
unsigned int     reserved_1:2;
unsigned int     biasa_regl:4;
unsigned int     reserved_2:2;
unsigned int     biasb_regl:4;
unsigned int     reserved_3:2;
unsigned int     biasc_regl:4;
}VIDEO_DAC_CTRL;

typedef struct 
{
unsigned int     reserved_0:17;
unsigned int     abiq_regl:3;
unsigned int     ldvbias_regl:3;
unsigned int     vcmref_regl:2;
unsigned int     reserved_1:2;
unsigned int     vdac_cf_regl:3;
unsigned int     vdac_rf_regl:2;
}VIDEO_DAC_CTRL2;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     write_en6:1;
unsigned int     dcc2_l:1;
unsigned int     write_en5:1;
unsigned int     dcc_l:1;
unsigned int     write_en4:1;
unsigned int     caldiv:2;
unsigned int     reserved_1:3;
unsigned int     write_en3:1;
unsigned int     div_regl:2;
unsigned int     write_en2:1;
unsigned int     ckmode_regl:2;
unsigned int     write_en1:1;
unsigned int     calen_regl:2;
}VIDEO_DAC_CTRL3;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     write_en1:1;
unsigned int     dac0_sel:2;
}DAC_SEL;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     write_en6:1;
unsigned int     up_ctrl_prog:2;
unsigned int     write_en5:1;
unsigned int     up_ctrl_int0:2;
unsigned int     write_en4:1;
unsigned int     up_ctrl_int1:2;
unsigned int     write_en3:1;
unsigned int     dacmode:2;
unsigned int     write_en2:1;
unsigned int     swap23:1;
unsigned int     write_en1:1;
unsigned int     swap56:1;
}DAC_MUX;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     write_en3:1;
unsigned int     ygdelay:2;
unsigned int     write_en2:1;
unsigned int     bdelay:2;
unsigned int     write_en1:1;
unsigned int     rdelay:2;
}CMP_DLY;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en4:1;
unsigned int     out_control123:3;
unsigned int     write_en3:1;
unsigned int     neg_out:6;
unsigned int     write_en2:1;
unsigned int     out_control:1;
unsigned int     write_en1:1;
unsigned int     dac_value:10;
unsigned int     reserved_1:2;
}DAC_MISC;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     dac_value3:10;
unsigned int     dac_value2:10;
unsigned int     dac_value1:10;
}DAC_MISC1;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     write_en3:1;
unsigned int     sel1:4;
unsigned int     write_en2:1;
unsigned int     sel0:4;
unsigned int     write_en1:1;
unsigned int     enable:1;
}DBG;

typedef struct 
{
unsigned int     dummy:32;
}DUMMY;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     aio_dac_en:1;
unsigned int     dac1_en:1;
unsigned int     dac0_en:1;
}DAC_TEST;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     int_vpos:11;
unsigned int     write_en1:1;
unsigned int     int_hpos:13;
}INTVBI_I;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     int_vpos:11;
unsigned int     write_en1:1;
unsigned int     int_hpos:13;
}INTVBI_P1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     int_vpos:11;
unsigned int     write_en1:1;
unsigned int     int_hpos:13;
}INTVBI_P2;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     int_vpos:11;
unsigned int     write_en1:1;
unsigned int     int_hpos:13;
}INTVBI_H1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     write_en2:1;
unsigned int     int_vpos:11;
unsigned int     write_en1:1;
unsigned int     int_hpos:13;
}INTVBI_H2;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     c1:14;
unsigned int     reserved_1:2;
unsigned int     c0:14;
}DAC1_FIR_1;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     c3:14;
unsigned int     reserved_1:2;
unsigned int     c2:14;
}DAC1_FIR_2;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     c1:14;
unsigned int     reserved_1:2;
unsigned int     c0:14;
}DAC2_FIR_1;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     c3:14;
unsigned int     reserved_1:2;
unsigned int     c2:14;
}DAC2_FIR_2;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     c1:14;
unsigned int     reserved_1:2;
unsigned int     c0:14;
}DAC3_FIR_1;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     c3:14;
unsigned int     reserved_1:2;
unsigned int     c2:14;
}DAC3_FIR_2;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     c1:14;
unsigned int     reserved_1:2;
unsigned int     c0:14;
}DAC4_FIR_1;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     c3:14;
unsigned int     reserved_1:2;
unsigned int     c2:14;
}DAC4_FIR_2;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     tve_sim_cntl:1;
unsigned int     empty_clr:1;
unsigned int     full_clr:1;
}DAC4_FIFO;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     fifo_empty:1;
unsigned int     fifo_full:1;
}DAC4_FIFO_READ;

#endif

#define SYNCGEN_RST                                                                  0x1801F000
#define SYNCGEN_RST_reg_addr                                                         "0xB800A000"
#define SYNCGEN_RST_reg                                                             0xB801F000
#define set_SYNCGEN_RST_reg(data)   (*((volatile unsigned int*) SYNCGEN_RST_reg)=data)
#define get_SYNCGEN_RST_reg   (*((volatile unsigned int*) SYNCGEN_RST_reg))
#define SYNCGEN_RST_inst_adr                                                         "0x0000"
#define SYNCGEN_RST_inst                                                             0x0000
#define SYNCGEN_RST_write_en6_shift                                                  (11)
#define SYNCGEN_RST_write_en6_mask                                                   (0x00000800)
#define SYNCGEN_RST_write_en6(data)                                                  (0x00000800&((data)<<11))
#define SYNCGEN_RST_write_en6_src(data)                                              ((0x00000800&(data))>>11)
#define SYNCGEN_RST_get_write_en6(data)                                              ((0x00000800&(data))>>11)
#define SYNCGEN_RST_ph_sync_go_shift                                                 (10)
#define SYNCGEN_RST_ph_sync_go_mask                                                  (0x00000400)
#define SYNCGEN_RST_ph_sync_go(data)                                                 (0x00000400&((data)<<10))
#define SYNCGEN_RST_ph_sync_go_src(data)                                             ((0x00000400&(data))>>10)
#define SYNCGEN_RST_get_ph_sync_go(data)                                             ((0x00000400&(data))>>10)
#define SYNCGEN_RST_write_en5_shift                                                  (9)
#define SYNCGEN_RST_write_en5_mask                                                   (0x00000200)
#define SYNCGEN_RST_write_en5(data)                                                  (0x00000200&((data)<<9))
#define SYNCGEN_RST_write_en5_src(data)                                              ((0x00000200&(data))>>9)
#define SYNCGEN_RST_get_write_en5(data)                                              ((0x00000200&(data))>>9)
#define SYNCGEN_RST_hi_sync_go_shift                                                 (8)
#define SYNCGEN_RST_hi_sync_go_mask                                                  (0x00000100)
#define SYNCGEN_RST_hi_sync_go(data)                                                 (0x00000100&((data)<<8))
#define SYNCGEN_RST_hi_sync_go_src(data)                                             ((0x00000100&(data))>>8)
#define SYNCGEN_RST_get_hi_sync_go(data)                                             ((0x00000100&(data))>>8)
#define SYNCGEN_RST_write_en4_shift                                                  (7)
#define SYNCGEN_RST_write_en4_mask                                                   (0x00000080)
#define SYNCGEN_RST_write_en4(data)                                                  (0x00000080&((data)<<7))
#define SYNCGEN_RST_write_en4_src(data)                                              ((0x00000080&(data))>>7)
#define SYNCGEN_RST_get_write_en4(data)                                              ((0x00000080&(data))>>7)
#define SYNCGEN_RST_pi_sync_go_shift                                                 (6)
#define SYNCGEN_RST_pi_sync_go_mask                                                  (0x00000040)
#define SYNCGEN_RST_pi_sync_go(data)                                                 (0x00000040&((data)<<6))
#define SYNCGEN_RST_pi_sync_go_src(data)                                             ((0x00000040&(data))>>6)
#define SYNCGEN_RST_get_pi_sync_go(data)                                             ((0x00000040&(data))>>6)
#define SYNCGEN_RST_write_en3_shift                                                  (5)
#define SYNCGEN_RST_write_en3_mask                                                   (0x00000020)
#define SYNCGEN_RST_write_en3(data)                                                  (0x00000020&((data)<<5))
#define SYNCGEN_RST_write_en3_src(data)                                              ((0x00000020&(data))>>5)
#define SYNCGEN_RST_get_write_en3(data)                                              ((0x00000020&(data))>>5)
#define SYNCGEN_RST_i_sync_go_shift                                                  (4)
#define SYNCGEN_RST_i_sync_go_mask                                                   (0x00000010)
#define SYNCGEN_RST_i_sync_go(data)                                                  (0x00000010&((data)<<4))
#define SYNCGEN_RST_i_sync_go_src(data)                                              ((0x00000010&(data))>>4)
#define SYNCGEN_RST_get_i_sync_go(data)                                              ((0x00000010&(data))>>4)
#define SYNCGEN_RST_write_en2_shift                                                  (3)
#define SYNCGEN_RST_write_en2_mask                                                   (0x00000008)
#define SYNCGEN_RST_write_en2(data)                                                  (0x00000008&((data)<<3))
#define SYNCGEN_RST_write_en2_src(data)                                              ((0x00000008&(data))>>3)
#define SYNCGEN_RST_get_write_en2(data)                                              ((0x00000008&(data))>>3)
#define SYNCGEN_RST_p_sync_go_shift                                                  (2)
#define SYNCGEN_RST_p_sync_go_mask                                                   (0x00000004)
#define SYNCGEN_RST_p_sync_go(data)                                                  (0x00000004&((data)<<2))
#define SYNCGEN_RST_p_sync_go_src(data)                                              ((0x00000004&(data))>>2)
#define SYNCGEN_RST_get_p_sync_go(data)                                              ((0x00000004&(data))>>2)
#define SYNCGEN_RST_write_en1_shift                                                  (1)
#define SYNCGEN_RST_write_en1_mask                                                   (0x00000002)
#define SYNCGEN_RST_write_en1(data)                                                  (0x00000002&((data)<<1))
#define SYNCGEN_RST_write_en1_src(data)                                              ((0x00000002&(data))>>1)
#define SYNCGEN_RST_get_write_en1(data)                                              ((0x00000002&(data))>>1)
#define SYNCGEN_RST_h_sync_go_shift                                                  (0)
#define SYNCGEN_RST_h_sync_go_mask                                                   (0x00000001)
#define SYNCGEN_RST_h_sync_go(data)                                                  (0x00000001&((data)<<0))
#define SYNCGEN_RST_h_sync_go_src(data)                                              ((0x00000001&(data))>>0)
#define SYNCGEN_RST_get_h_sync_go(data)                                              ((0x00000001&(data))>>0)


#define SYNCGEN_I                                                                    0x1801F004
#define SYNCGEN_I_reg_addr                                                           "0xB800A004"
#define SYNCGEN_I_reg                                                               0xB801F004
#define set_SYNCGEN_I_reg(data)   (*((volatile unsigned int*) SYNCGEN_I_reg)=data)
#define get_SYNCGEN_I_reg   (*((volatile unsigned int*) SYNCGEN_I_reg))
#define SYNCGEN_I_inst_adr                                                           "0x0001"
#define SYNCGEN_I_inst                                                               0x0001
#define SYNCGEN_I_write_en2_shift                                                    (25)
#define SYNCGEN_I_write_en2_mask                                                     (0x02000000)
#define SYNCGEN_I_write_en2(data)                                                    (0x02000000&((data)<<25))
#define SYNCGEN_I_write_en2_src(data)                                                ((0x02000000&(data))>>25)
#define SYNCGEN_I_get_write_en2(data)                                                ((0x02000000&(data))>>25)
#define SYNCGEN_I_v_thr_shift                                                        (14)
#define SYNCGEN_I_v_thr_mask                                                         (0x01FFC000)
#define SYNCGEN_I_v_thr(data)                                                        (0x01FFC000&((data)<<14))
#define SYNCGEN_I_v_thr_src(data)                                                    ((0x01FFC000&(data))>>14)
#define SYNCGEN_I_get_v_thr(data)                                                    ((0x01FFC000&(data))>>14)
#define SYNCGEN_I_write_en1_shift                                                    (13)
#define SYNCGEN_I_write_en1_mask                                                     (0x00002000)
#define SYNCGEN_I_write_en1(data)                                                    (0x00002000&((data)<<13))
#define SYNCGEN_I_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define SYNCGEN_I_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define SYNCGEN_I_h_thr_shift                                                        (0)
#define SYNCGEN_I_h_thr_mask                                                         (0x00001FFF)
#define SYNCGEN_I_h_thr(data)                                                        (0x00001FFF&((data)<<0))
#define SYNCGEN_I_h_thr_src(data)                                                    ((0x00001FFF&(data))>>0)
#define SYNCGEN_I_get_h_thr(data)                                                    ((0x00001FFF&(data))>>0)


#define SYNCGEN_P                                                                    0x1801F008
#define SYNCGEN_P_reg_addr                                                           "0xB800A008"
#define SYNCGEN_P_reg                                                               0xB801F008
#define set_SYNCGEN_P_reg(data)   (*((volatile unsigned int*) SYNCGEN_P_reg)=data)
#define get_SYNCGEN_P_reg   (*((volatile unsigned int*) SYNCGEN_P_reg))
#define SYNCGEN_P_inst_adr                                                           "0x0002"
#define SYNCGEN_P_inst                                                               0x0002
#define SYNCGEN_P_write_en3_shift                                                    (27)
#define SYNCGEN_P_write_en3_mask                                                     (0x08000000)
#define SYNCGEN_P_write_en3(data)                                                    (0x08000000&((data)<<27))
#define SYNCGEN_P_write_en3_src(data)                                                ((0x08000000&(data))>>27)
#define SYNCGEN_P_get_write_en3(data)                                                ((0x08000000&(data))>>27)
#define SYNCGEN_P_i_p_sel_shift                                                      (26)
#define SYNCGEN_P_i_p_sel_mask                                                       (0x04000000)
#define SYNCGEN_P_i_p_sel(data)                                                      (0x04000000&((data)<<26))
#define SYNCGEN_P_i_p_sel_src(data)                                                  ((0x04000000&(data))>>26)
#define SYNCGEN_P_get_i_p_sel(data)                                                  ((0x04000000&(data))>>26)
#define SYNCGEN_P_write_en2_shift                                                    (25)
#define SYNCGEN_P_write_en2_mask                                                     (0x02000000)
#define SYNCGEN_P_write_en2(data)                                                    (0x02000000&((data)<<25))
#define SYNCGEN_P_write_en2_src(data)                                                ((0x02000000&(data))>>25)
#define SYNCGEN_P_get_write_en2(data)                                                ((0x02000000&(data))>>25)
#define SYNCGEN_P_v_thr_shift                                                        (14)
#define SYNCGEN_P_v_thr_mask                                                         (0x01FFC000)
#define SYNCGEN_P_v_thr(data)                                                        (0x01FFC000&((data)<<14))
#define SYNCGEN_P_v_thr_src(data)                                                    ((0x01FFC000&(data))>>14)
#define SYNCGEN_P_get_v_thr(data)                                                    ((0x01FFC000&(data))>>14)
#define SYNCGEN_P_write_en1_shift                                                    (13)
#define SYNCGEN_P_write_en1_mask                                                     (0x00002000)
#define SYNCGEN_P_write_en1(data)                                                    (0x00002000&((data)<<13))
#define SYNCGEN_P_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define SYNCGEN_P_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define SYNCGEN_P_h_thr_shift                                                        (0)
#define SYNCGEN_P_h_thr_mask                                                         (0x00001FFF)
#define SYNCGEN_P_h_thr(data)                                                        (0x00001FFF&((data)<<0))
#define SYNCGEN_P_h_thr_src(data)                                                    ((0x00001FFF&(data))>>0)
#define SYNCGEN_P_get_h_thr(data)                                                    ((0x00001FFF&(data))>>0)


#define SYNCGEN_HDMI                                                                 0x1801F00c
#define SYNCGEN_HDMI_reg_addr                                                        "0xB800A00C"
#define SYNCGEN_HDMI_reg                                                            0xB801F00C
#define set_SYNCGEN_HDMI_reg(data)   (*((volatile unsigned int*) SYNCGEN_HDMI_reg)=data)
#define get_SYNCGEN_HDMI_reg   (*((volatile unsigned int*) SYNCGEN_HDMI_reg))
#define SYNCGEN_HDMI_inst_adr                                                        "0x0003"
#define SYNCGEN_HDMI_inst                                                            0x0003
#define SYNCGEN_HDMI_write_en4_shift                                                 (29)
#define SYNCGEN_HDMI_write_en4_mask                                                  (0x20000000)
#define SYNCGEN_HDMI_write_en4(data)                                                 (0x20000000&((data)<<29))
#define SYNCGEN_HDMI_write_en4_src(data)                                             ((0x20000000&(data))>>29)
#define SYNCGEN_HDMI_get_write_en4(data)                                             ((0x20000000&(data))>>29)
#define SYNCGEN_HDMI_mode_1080i_shift                                                (28)
#define SYNCGEN_HDMI_mode_1080i_mask                                                 (0x10000000)
#define SYNCGEN_HDMI_mode_1080i(data)                                                (0x10000000&((data)<<28))
#define SYNCGEN_HDMI_mode_1080i_src(data)                                            ((0x10000000&(data))>>28)
#define SYNCGEN_HDMI_get_mode_1080i(data)                                            ((0x10000000&(data))>>28)
#define SYNCGEN_HDMI_write_en3_shift                                                 (27)
#define SYNCGEN_HDMI_write_en3_mask                                                  (0x08000000)
#define SYNCGEN_HDMI_write_en3(data)                                                 (0x08000000&((data)<<27))
#define SYNCGEN_HDMI_write_en3_src(data)                                             ((0x08000000&(data))>>27)
#define SYNCGEN_HDMI_get_write_en3(data)                                             ((0x08000000&(data))>>27)
#define SYNCGEN_HDMI_i_p_sel_shift                                                   (26)
#define SYNCGEN_HDMI_i_p_sel_mask                                                    (0x04000000)
#define SYNCGEN_HDMI_i_p_sel(data)                                                   (0x04000000&((data)<<26))
#define SYNCGEN_HDMI_i_p_sel_src(data)                                               ((0x04000000&(data))>>26)
#define SYNCGEN_HDMI_get_i_p_sel(data)                                               ((0x04000000&(data))>>26)
#define SYNCGEN_HDMI_write_en2_shift                                                 (25)
#define SYNCGEN_HDMI_write_en2_mask                                                  (0x02000000)
#define SYNCGEN_HDMI_write_en2(data)                                                 (0x02000000&((data)<<25))
#define SYNCGEN_HDMI_write_en2_src(data)                                             ((0x02000000&(data))>>25)
#define SYNCGEN_HDMI_get_write_en2(data)                                             ((0x02000000&(data))>>25)
#define SYNCGEN_HDMI_v_thr_shift                                                     (14)
#define SYNCGEN_HDMI_v_thr_mask                                                      (0x01FFC000)
#define SYNCGEN_HDMI_v_thr(data)                                                     (0x01FFC000&((data)<<14))
#define SYNCGEN_HDMI_v_thr_src(data)                                                 ((0x01FFC000&(data))>>14)
#define SYNCGEN_HDMI_get_v_thr(data)                                                 ((0x01FFC000&(data))>>14)
#define SYNCGEN_HDMI_write_en1_shift                                                 (13)
#define SYNCGEN_HDMI_write_en1_mask                                                  (0x00002000)
#define SYNCGEN_HDMI_write_en1(data)                                                 (0x00002000&((data)<<13))
#define SYNCGEN_HDMI_write_en1_src(data)                                             ((0x00002000&(data))>>13)
#define SYNCGEN_HDMI_get_write_en1(data)                                             ((0x00002000&(data))>>13)
#define SYNCGEN_HDMI_h_thr_shift                                                     (0)
#define SYNCGEN_HDMI_h_thr_mask                                                      (0x00001FFF)
#define SYNCGEN_HDMI_h_thr(data)                                                     (0x00001FFF&((data)<<0))
#define SYNCGEN_HDMI_h_thr_src(data)                                                 ((0x00001FFF&(data))>>0)
#define SYNCGEN_HDMI_get_h_thr(data)                                                 ((0x00001FFF&(data))>>0)


#define COMP_CTRL                                                                    0x1801F010
#define COMP_CTRL_reg_addr                                                           "0xB800A010"
#define COMP_CTRL_reg                                                               0xB801F010
#define set_COMP_CTRL_reg(data)   (*((volatile unsigned int*) COMP_CTRL_reg)=data)
#define get_COMP_CTRL_reg   (*((volatile unsigned int*) COMP_CTRL_reg))
#define COMP_CTRL_inst_adr                                                           "0x0004"
#define COMP_CTRL_inst                                                               0x0004
#define COMP_CTRL_comp_ebl_shift                                                     (13)
#define COMP_CTRL_comp_ebl_mask                                                      (0x00002000)
#define COMP_CTRL_comp_ebl(data)                                                     (0x00002000&((data)<<13))
#define COMP_CTRL_comp_ebl_src(data)                                                 ((0x00002000&(data))>>13)
#define COMP_CTRL_get_comp_ebl(data)                                                 ((0x00002000&(data))>>13)
#define COMP_CTRL_sdtv_ebl_shift                                                     (12)
#define COMP_CTRL_sdtv_ebl_mask                                                      (0x00001000)
#define COMP_CTRL_sdtv_ebl(data)                                                     (0x00001000&((data)<<12))
#define COMP_CTRL_sdtv_ebl_src(data)                                                 ((0x00001000&(data))>>12)
#define COMP_CTRL_get_sdtv_ebl(data)                                                 ((0x00001000&(data))>>12)
#define COMP_CTRL_vs_polar_shift                                                     (11)
#define COMP_CTRL_vs_polar_mask                                                      (0x00000800)
#define COMP_CTRL_vs_polar(data)                                                     (0x00000800&((data)<<11))
#define COMP_CTRL_vs_polar_src(data)                                                 ((0x00000800&(data))>>11)
#define COMP_CTRL_get_vs_polar(data)                                                 ((0x00000800&(data))>>11)
#define COMP_CTRL_hs_polar_shift                                                     (10)
#define COMP_CTRL_hs_polar_mask                                                      (0x00000400)
#define COMP_CTRL_hs_polar(data)                                                     (0x00000400&((data)<<10))
#define COMP_CTRL_hs_polar_src(data)                                                 ((0x00000400&(data))>>10)
#define COMP_CTRL_get_hs_polar(data)                                                 ((0x00000400&(data))>>10)
#define COMP_CTRL_vga_hvsync_shift                                                   (9)
#define COMP_CTRL_vga_hvsync_mask                                                    (0x00000200)
#define COMP_CTRL_vga_hvsync(data)                                                   (0x00000200&((data)<<9))
#define COMP_CTRL_vga_hvsync_src(data)                                               ((0x00000200&(data))>>9)
#define COMP_CTRL_get_vga_hvsync(data)                                               ((0x00000200&(data))>>9)
#define COMP_CTRL_comp_sel_shift                                                     (8)
#define COMP_CTRL_comp_sel_mask                                                      (0x00000100)
#define COMP_CTRL_comp_sel(data)                                                     (0x00000100&((data)<<8))
#define COMP_CTRL_comp_sel_src(data)                                                 ((0x00000100&(data))>>8)
#define COMP_CTRL_get_comp_sel(data)                                                 ((0x00000100&(data))>>8)
#define COMP_CTRL_sync_rb_ebl_shift                                                  (7)
#define COMP_CTRL_sync_rb_ebl_mask                                                   (0x00000080)
#define COMP_CTRL_sync_rb_ebl(data)                                                  (0x00000080&((data)<<7))
#define COMP_CTRL_sync_rb_ebl_src(data)                                              ((0x00000080&(data))>>7)
#define COMP_CTRL_get_sync_rb_ebl(data)                                              ((0x00000080&(data))>>7)
#define COMP_CTRL_sync_g_ebl_shift                                                   (6)
#define COMP_CTRL_sync_g_ebl_mask                                                    (0x00000040)
#define COMP_CTRL_sync_g_ebl(data)                                                   (0x00000040&((data)<<6))
#define COMP_CTRL_sync_g_ebl_src(data)                                               ((0x00000040&(data))>>6)
#define COMP_CTRL_get_sync_g_ebl(data)                                               ((0x00000040&(data))>>6)
#define COMP_CTRL_rgb_mod_shift                                                      (5)
#define COMP_CTRL_rgb_mod_mask                                                       (0x00000020)
#define COMP_CTRL_rgb_mod(data)                                                      (0x00000020&((data)<<5))
#define COMP_CTRL_rgb_mod_src(data)                                                  ((0x00000020&(data))>>5)
#define COMP_CTRL_get_rgb_mod(data)                                                  ((0x00000020&(data))>>5)
#define COMP_CTRL_vbi_rb_ebl_shift                                                   (4)
#define COMP_CTRL_vbi_rb_ebl_mask                                                    (0x00000010)
#define COMP_CTRL_vbi_rb_ebl(data)                                                   (0x00000010&((data)<<4))
#define COMP_CTRL_vbi_rb_ebl_src(data)                                               ((0x00000010&(data))>>4)
#define COMP_CTRL_get_vbi_rb_ebl(data)                                               ((0x00000010&(data))>>4)
#define COMP_CTRL_vbi_g_ebl_shift                                                    (3)
#define COMP_CTRL_vbi_g_ebl_mask                                                     (0x00000008)
#define COMP_CTRL_vbi_g_ebl(data)                                                    (0x00000008&((data)<<3))
#define COMP_CTRL_vbi_g_ebl_src(data)                                                ((0x00000008&(data))>>3)
#define COMP_CTRL_get_vbi_g_ebl(data)                                                ((0x00000008&(data))>>3)
#define COMP_CTRL_hdsync_shift                                                       (2)
#define COMP_CTRL_hdsync_mask                                                        (0x00000004)
#define COMP_CTRL_hdsync(data)                                                       (0x00000004&((data)<<2))
#define COMP_CTRL_hdsync_src(data)                                                   ((0x00000004&(data))>>2)
#define COMP_CTRL_get_hdsync(data)                                                   ((0x00000004&(data))>>2)
#define COMP_CTRL_syncmod_sel_shift                                                  (1)
#define COMP_CTRL_syncmod_sel_mask                                                   (0x00000002)
#define COMP_CTRL_syncmod_sel(data)                                                  (0x00000002&((data)<<1))
#define COMP_CTRL_syncmod_sel_src(data)                                              ((0x00000002&(data))>>1)
#define COMP_CTRL_get_syncmod_sel(data)                                              ((0x00000002&(data))>>1)
#define COMP_CTRL_write_data_shift                                                   (0)
#define COMP_CTRL_write_data_mask                                                    (0x00000001)
#define COMP_CTRL_write_data(data)                                                   (0x00000001&((data)<<0))
#define COMP_CTRL_write_data_src(data)                                               ((0x00000001&(data))>>0)
#define COMP_CTRL_get_write_data(data)                                               ((0x00000001&(data))>>0)


#define SYNCGEN_STATUS_I                                                             0x1801F014
#define SYNCGEN_STATUS_I_reg_addr                                                    "0xB800A014"
#define SYNCGEN_STATUS_I_reg                                                        0xB801F014
#define set_SYNCGEN_STATUS_I_reg(data)   (*((volatile unsigned int*) SYNCGEN_STATUS_I_reg)=data)
#define get_SYNCGEN_STATUS_I_reg   (*((volatile unsigned int*) SYNCGEN_STATUS_I_reg))
#define SYNCGEN_STATUS_I_inst_adr                                                    "0x0005"
#define SYNCGEN_STATUS_I_inst                                                        0x0005
#define SYNCGEN_STATUS_I_i_field_shift                                               (23)
#define SYNCGEN_STATUS_I_i_field_mask                                                (0x00800000)
#define SYNCGEN_STATUS_I_i_field(data)                                               (0x00800000&((data)<<23))
#define SYNCGEN_STATUS_I_i_field_src(data)                                           ((0x00800000&(data))>>23)
#define SYNCGEN_STATUS_I_get_i_field(data)                                           ((0x00800000&(data))>>23)
#define SYNCGEN_STATUS_I_i_vcnt_shift                                                (12)
#define SYNCGEN_STATUS_I_i_vcnt_mask                                                 (0x007FF000)
#define SYNCGEN_STATUS_I_i_vcnt(data)                                                (0x007FF000&((data)<<12))
#define SYNCGEN_STATUS_I_i_vcnt_src(data)                                            ((0x007FF000&(data))>>12)
#define SYNCGEN_STATUS_I_get_i_vcnt(data)                                            ((0x007FF000&(data))>>12)
#define SYNCGEN_STATUS_I_p_field_shift                                               (11)
#define SYNCGEN_STATUS_I_p_field_mask                                                (0x00000800)
#define SYNCGEN_STATUS_I_p_field(data)                                               (0x00000800&((data)<<11))
#define SYNCGEN_STATUS_I_p_field_src(data)                                           ((0x00000800&(data))>>11)
#define SYNCGEN_STATUS_I_get_p_field(data)                                           ((0x00000800&(data))>>11)
#define SYNCGEN_STATUS_I_p_vcnt_shift                                                (0)
#define SYNCGEN_STATUS_I_p_vcnt_mask                                                 (0x000007FF)
#define SYNCGEN_STATUS_I_p_vcnt(data)                                                (0x000007FF&((data)<<0))
#define SYNCGEN_STATUS_I_p_vcnt_src(data)                                            ((0x000007FF&(data))>>0)
#define SYNCGEN_STATUS_I_get_p_vcnt(data)                                            ((0x000007FF&(data))>>0)


#define SYNCGEN_STATUS_H                                                             0x1801F018
#define SYNCGEN_STATUS_H_reg_addr                                                    "0xB800A018"
#define SYNCGEN_STATUS_H_reg                                                        0xB801F018
#define set_SYNCGEN_STATUS_H_reg(data)   (*((volatile unsigned int*) SYNCGEN_STATUS_H_reg)=data)
#define get_SYNCGEN_STATUS_H_reg   (*((volatile unsigned int*) SYNCGEN_STATUS_H_reg))
#define SYNCGEN_STATUS_H_inst_adr                                                    "0x0006"
#define SYNCGEN_STATUS_H_inst                                                        0x0006
#define SYNCGEN_STATUS_H_h_field_shift                                               (11)
#define SYNCGEN_STATUS_H_h_field_mask                                                (0x00000800)
#define SYNCGEN_STATUS_H_h_field(data)                                               (0x00000800&((data)<<11))
#define SYNCGEN_STATUS_H_h_field_src(data)                                           ((0x00000800&(data))>>11)
#define SYNCGEN_STATUS_H_get_h_field(data)                                           ((0x00000800&(data))>>11)
#define SYNCGEN_STATUS_H_h_vcnt_shift                                                (0)
#define SYNCGEN_STATUS_H_h_vcnt_mask                                                 (0x000007FF)
#define SYNCGEN_STATUS_H_h_vcnt(data)                                                (0x000007FF&((data)<<0))
#define SYNCGEN_STATUS_H_h_vcnt_src(data)                                            ((0x000007FF&(data))>>0)
#define SYNCGEN_STATUS_H_get_h_vcnt(data)                                            ((0x000007FF&(data))>>0)


#define INTEN                                                                        0x1801F01c
#define INTEN_reg_addr                                                               "0xB800A01C"
#define INTEN_reg                                                                   0xB801F01C
#define set_INTEN_reg(data)   (*((volatile unsigned int*) INTEN_reg)=data)
#define get_INTEN_reg   (*((volatile unsigned int*) INTEN_reg))
#define INTEN_inst_adr                                                               "0x0007"
#define INTEN_inst                                                                   0x0007
#define INTEN_inten_vbi_h_shift                                                      (6)
#define INTEN_inten_vbi_h_mask                                                       (0x00000040)
#define INTEN_inten_vbi_h(data)                                                      (0x00000040&((data)<<6))
#define INTEN_inten_vbi_h_src(data)                                                  ((0x00000040&(data))>>6)
#define INTEN_get_inten_vbi_h(data)                                                  ((0x00000040&(data))>>6)
#define INTEN_inten_vbi_i_shift                                                      (5)
#define INTEN_inten_vbi_i_mask                                                       (0x00000020)
#define INTEN_inten_vbi_i(data)                                                      (0x00000020&((data)<<5))
#define INTEN_inten_vbi_i_src(data)                                                  ((0x00000020&(data))>>5)
#define INTEN_get_inten_vbi_i(data)                                                  ((0x00000020&(data))>>5)
#define INTEN_inten_vbi_p_shift                                                      (4)
#define INTEN_inten_vbi_p_mask                                                       (0x00000010)
#define INTEN_inten_vbi_p(data)                                                      (0x00000010&((data)<<4))
#define INTEN_inten_vbi_p_src(data)                                                  ((0x00000010&(data))>>4)
#define INTEN_get_inten_vbi_p(data)                                                  ((0x00000010&(data))>>4)
#define INTEN_inten_h_shift                                                          (3)
#define INTEN_inten_h_mask                                                           (0x00000008)
#define INTEN_inten_h(data)                                                          (0x00000008&((data)<<3))
#define INTEN_inten_h_src(data)                                                      ((0x00000008&(data))>>3)
#define INTEN_get_inten_h(data)                                                      ((0x00000008&(data))>>3)
#define INTEN_inten_i_shift                                                          (2)
#define INTEN_inten_i_mask                                                           (0x00000004)
#define INTEN_inten_i(data)                                                          (0x00000004&((data)<<2))
#define INTEN_inten_i_src(data)                                                      ((0x00000004&(data))>>2)
#define INTEN_get_inten_i(data)                                                      ((0x00000004&(data))>>2)
#define INTEN_inten_p_shift                                                          (1)
#define INTEN_inten_p_mask                                                           (0x00000002)
#define INTEN_inten_p(data)                                                          (0x00000002&((data)<<1))
#define INTEN_inten_p_src(data)                                                      ((0x00000002&(data))>>1)
#define INTEN_get_inten_p(data)                                                      ((0x00000002&(data))>>1)
#define INTEN_write_data_shift                                                       (0)
#define INTEN_write_data_mask                                                        (0x00000001)
#define INTEN_write_data(data)                                                       (0x00000001&((data)<<0))
#define INTEN_write_data_src(data)                                                   ((0x00000001&(data))>>0)
#define INTEN_get_write_data(data)                                                   ((0x00000001&(data))>>0)


#define INTST                                                                        0x1801F020
#define INTST_reg_addr                                                               "0xB800A020"
#define INTST_reg                                                                   0xB801F020
#define set_INTST_reg(data)   (*((volatile unsigned int*) INTST_reg)=data)
#define get_INTST_reg   (*((volatile unsigned int*) INTST_reg))
#define INTST_inst_adr                                                               "0x0008"
#define INTST_inst                                                                   0x0008
#define INTST_intst_vbi_h_shift                                                      (6)
#define INTST_intst_vbi_h_mask                                                       (0x00000040)
#define INTST_intst_vbi_h(data)                                                      (0x00000040&((data)<<6))
#define INTST_intst_vbi_h_src(data)                                                  ((0x00000040&(data))>>6)
#define INTST_get_intst_vbi_h(data)                                                  ((0x00000040&(data))>>6)
#define INTST_intst_vbi_i_shift                                                      (5)
#define INTST_intst_vbi_i_mask                                                       (0x00000020)
#define INTST_intst_vbi_i(data)                                                      (0x00000020&((data)<<5))
#define INTST_intst_vbi_i_src(data)                                                  ((0x00000020&(data))>>5)
#define INTST_get_intst_vbi_i(data)                                                  ((0x00000020&(data))>>5)
#define INTST_intst_vbi_p_shift                                                      (4)
#define INTST_intst_vbi_p_mask                                                       (0x00000010)
#define INTST_intst_vbi_p(data)                                                      (0x00000010&((data)<<4))
#define INTST_intst_vbi_p_src(data)                                                  ((0x00000010&(data))>>4)
#define INTST_get_intst_vbi_p(data)                                                  ((0x00000010&(data))>>4)
#define INTST_intst_h_shift                                                          (3)
#define INTST_intst_h_mask                                                           (0x00000008)
#define INTST_intst_h(data)                                                          (0x00000008&((data)<<3))
#define INTST_intst_h_src(data)                                                      ((0x00000008&(data))>>3)
#define INTST_get_intst_h(data)                                                      ((0x00000008&(data))>>3)
#define INTST_intst_i_shift                                                          (2)
#define INTST_intst_i_mask                                                           (0x00000004)
#define INTST_intst_i(data)                                                          (0x00000004&((data)<<2))
#define INTST_intst_i_src(data)                                                      ((0x00000004&(data))>>2)
#define INTST_get_intst_i(data)                                                      ((0x00000004&(data))>>2)
#define INTST_intst_p_shift                                                          (1)
#define INTST_intst_p_mask                                                           (0x00000002)
#define INTST_intst_p(data)                                                          (0x00000002&((data)<<1))
#define INTST_intst_p_src(data)                                                      ((0x00000002&(data))>>1)
#define INTST_get_intst_p(data)                                                      ((0x00000002&(data))>>1)
#define INTST_write_data_shift                                                       (0)
#define INTST_write_data_mask                                                        (0x00000001)
#define INTST_write_data(data)                                                       (0x00000001&((data)<<0))
#define INTST_write_data_src(data)                                                   ((0x00000001&(data))>>0)
#define INTST_get_write_data(data)                                                   ((0x00000001&(data))>>0)


#define INTPOS_I                                                                     0x1801F024
#define INTPOS_I_reg_addr                                                            "0xB800A024"
#define INTPOS_I_reg                                                                0xB801F024
#define set_INTPOS_I_reg(data)   (*((volatile unsigned int*) INTPOS_I_reg)=data)
#define get_INTPOS_I_reg   (*((volatile unsigned int*) INTPOS_I_reg))
#define INTPOS_I_inst_adr                                                            "0x0009"
#define INTPOS_I_inst                                                                0x0009
#define INTPOS_I_write_en2_shift                                                     (25)
#define INTPOS_I_write_en2_mask                                                      (0x02000000)
#define INTPOS_I_write_en2(data)                                                     (0x02000000&((data)<<25))
#define INTPOS_I_write_en2_src(data)                                                 ((0x02000000&(data))>>25)
#define INTPOS_I_get_write_en2(data)                                                 ((0x02000000&(data))>>25)
#define INTPOS_I_int_vpos_shift                                                      (14)
#define INTPOS_I_int_vpos_mask                                                       (0x01FFC000)
#define INTPOS_I_int_vpos(data)                                                      (0x01FFC000&((data)<<14))
#define INTPOS_I_int_vpos_src(data)                                                  ((0x01FFC000&(data))>>14)
#define INTPOS_I_get_int_vpos(data)                                                  ((0x01FFC000&(data))>>14)
#define INTPOS_I_write_en1_shift                                                     (13)
#define INTPOS_I_write_en1_mask                                                      (0x00002000)
#define INTPOS_I_write_en1(data)                                                     (0x00002000&((data)<<13))
#define INTPOS_I_write_en1_src(data)                                                 ((0x00002000&(data))>>13)
#define INTPOS_I_get_write_en1(data)                                                 ((0x00002000&(data))>>13)
#define INTPOS_I_int_hpos_shift                                                      (0)
#define INTPOS_I_int_hpos_mask                                                       (0x00001FFF)
#define INTPOS_I_int_hpos(data)                                                      (0x00001FFF&((data)<<0))
#define INTPOS_I_int_hpos_src(data)                                                  ((0x00001FFF&(data))>>0)
#define INTPOS_I_get_int_hpos(data)                                                  ((0x00001FFF&(data))>>0)


#define INTPOS_P1                                                                    0x1801F028
#define INTPOS_P1_reg_addr                                                           "0xB800A028"
#define INTPOS_P1_reg                                                               0xB801F028
#define set_INTPOS_P1_reg(data)   (*((volatile unsigned int*) INTPOS_P1_reg)=data)
#define get_INTPOS_P1_reg   (*((volatile unsigned int*) INTPOS_P1_reg))
#define INTPOS_P1_inst_adr                                                           "0x000A"
#define INTPOS_P1_inst                                                               0x000A
#define INTPOS_P1_write_en2_shift                                                    (25)
#define INTPOS_P1_write_en2_mask                                                     (0x02000000)
#define INTPOS_P1_write_en2(data)                                                    (0x02000000&((data)<<25))
#define INTPOS_P1_write_en2_src(data)                                                ((0x02000000&(data))>>25)
#define INTPOS_P1_get_write_en2(data)                                                ((0x02000000&(data))>>25)
#define INTPOS_P1_int_vpos_shift                                                     (14)
#define INTPOS_P1_int_vpos_mask                                                      (0x01FFC000)
#define INTPOS_P1_int_vpos(data)                                                     (0x01FFC000&((data)<<14))
#define INTPOS_P1_int_vpos_src(data)                                                 ((0x01FFC000&(data))>>14)
#define INTPOS_P1_get_int_vpos(data)                                                 ((0x01FFC000&(data))>>14)
#define INTPOS_P1_write_en1_shift                                                    (13)
#define INTPOS_P1_write_en1_mask                                                     (0x00002000)
#define INTPOS_P1_write_en1(data)                                                    (0x00002000&((data)<<13))
#define INTPOS_P1_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define INTPOS_P1_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define INTPOS_P1_int_hpos_shift                                                     (0)
#define INTPOS_P1_int_hpos_mask                                                      (0x00001FFF)
#define INTPOS_P1_int_hpos(data)                                                     (0x00001FFF&((data)<<0))
#define INTPOS_P1_int_hpos_src(data)                                                 ((0x00001FFF&(data))>>0)
#define INTPOS_P1_get_int_hpos(data)                                                 ((0x00001FFF&(data))>>0)


#define INTPOS_P2                                                                    0x1801F02c
#define INTPOS_P2_reg_addr                                                           "0xB800A02C"
#define INTPOS_P2_reg                                                               0xB801F02C
#define set_INTPOS_P2_reg(data)   (*((volatile unsigned int*) INTPOS_P2_reg)=data)
#define get_INTPOS_P2_reg   (*((volatile unsigned int*) INTPOS_P2_reg))
#define INTPOS_P2_inst_adr                                                           "0x000B"
#define INTPOS_P2_inst                                                               0x000B
#define INTPOS_P2_write_en2_shift                                                    (25)
#define INTPOS_P2_write_en2_mask                                                     (0x02000000)
#define INTPOS_P2_write_en2(data)                                                    (0x02000000&((data)<<25))
#define INTPOS_P2_write_en2_src(data)                                                ((0x02000000&(data))>>25)
#define INTPOS_P2_get_write_en2(data)                                                ((0x02000000&(data))>>25)
#define INTPOS_P2_int_vpos_shift                                                     (14)
#define INTPOS_P2_int_vpos_mask                                                      (0x01FFC000)
#define INTPOS_P2_int_vpos(data)                                                     (0x01FFC000&((data)<<14))
#define INTPOS_P2_int_vpos_src(data)                                                 ((0x01FFC000&(data))>>14)
#define INTPOS_P2_get_int_vpos(data)                                                 ((0x01FFC000&(data))>>14)
#define INTPOS_P2_write_en1_shift                                                    (13)
#define INTPOS_P2_write_en1_mask                                                     (0x00002000)
#define INTPOS_P2_write_en1(data)                                                    (0x00002000&((data)<<13))
#define INTPOS_P2_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define INTPOS_P2_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define INTPOS_P2_int_hpos_shift                                                     (0)
#define INTPOS_P2_int_hpos_mask                                                      (0x00001FFF)
#define INTPOS_P2_int_hpos(data)                                                     (0x00001FFF&((data)<<0))
#define INTPOS_P2_int_hpos_src(data)                                                 ((0x00001FFF&(data))>>0)
#define INTPOS_P2_get_int_hpos(data)                                                 ((0x00001FFF&(data))>>0)


#define INTPOS_H1                                                                    0x1801F030
#define INTPOS_H1_reg_addr                                                           "0xB800A030"
#define INTPOS_H1_reg                                                               0xB801F030
#define set_INTPOS_H1_reg(data)   (*((volatile unsigned int*) INTPOS_H1_reg)=data)
#define get_INTPOS_H1_reg   (*((volatile unsigned int*) INTPOS_H1_reg))
#define INTPOS_H1_inst_adr                                                           "0x000C"
#define INTPOS_H1_inst                                                               0x000C
#define INTPOS_H1_write_en2_shift                                                    (25)
#define INTPOS_H1_write_en2_mask                                                     (0x02000000)
#define INTPOS_H1_write_en2(data)                                                    (0x02000000&((data)<<25))
#define INTPOS_H1_write_en2_src(data)                                                ((0x02000000&(data))>>25)
#define INTPOS_H1_get_write_en2(data)                                                ((0x02000000&(data))>>25)
#define INTPOS_H1_int_vpos_shift                                                     (14)
#define INTPOS_H1_int_vpos_mask                                                      (0x01FFC000)
#define INTPOS_H1_int_vpos(data)                                                     (0x01FFC000&((data)<<14))
#define INTPOS_H1_int_vpos_src(data)                                                 ((0x01FFC000&(data))>>14)
#define INTPOS_H1_get_int_vpos(data)                                                 ((0x01FFC000&(data))>>14)
#define INTPOS_H1_write_en1_shift                                                    (13)
#define INTPOS_H1_write_en1_mask                                                     (0x00002000)
#define INTPOS_H1_write_en1(data)                                                    (0x00002000&((data)<<13))
#define INTPOS_H1_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define INTPOS_H1_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define INTPOS_H1_int_hpos_shift                                                     (0)
#define INTPOS_H1_int_hpos_mask                                                      (0x00001FFF)
#define INTPOS_H1_int_hpos(data)                                                     (0x00001FFF&((data)<<0))
#define INTPOS_H1_int_hpos_src(data)                                                 ((0x00001FFF&(data))>>0)
#define INTPOS_H1_get_int_hpos(data)                                                 ((0x00001FFF&(data))>>0)


#define INTPOS_H2                                                                    0x1801F034
#define INTPOS_H2_reg_addr                                                           "0xB800A034"
#define INTPOS_H2_reg                                                               0xB801F034
#define set_INTPOS_H2_reg(data)   (*((volatile unsigned int*) INTPOS_H2_reg)=data)
#define get_INTPOS_H2_reg   (*((volatile unsigned int*) INTPOS_H2_reg))
#define INTPOS_H2_inst_adr                                                           "0x000D"
#define INTPOS_H2_inst                                                               0x000D
#define INTPOS_H2_write_en2_shift                                                    (25)
#define INTPOS_H2_write_en2_mask                                                     (0x02000000)
#define INTPOS_H2_write_en2(data)                                                    (0x02000000&((data)<<25))
#define INTPOS_H2_write_en2_src(data)                                                ((0x02000000&(data))>>25)
#define INTPOS_H2_get_write_en2(data)                                                ((0x02000000&(data))>>25)
#define INTPOS_H2_int_vpos_shift                                                     (14)
#define INTPOS_H2_int_vpos_mask                                                      (0x01FFC000)
#define INTPOS_H2_int_vpos(data)                                                     (0x01FFC000&((data)<<14))
#define INTPOS_H2_int_vpos_src(data)                                                 ((0x01FFC000&(data))>>14)
#define INTPOS_H2_get_int_vpos(data)                                                 ((0x01FFC000&(data))>>14)
#define INTPOS_H2_write_en1_shift                                                    (13)
#define INTPOS_H2_write_en1_mask                                                     (0x00002000)
#define INTPOS_H2_write_en1(data)                                                    (0x00002000&((data)<<13))
#define INTPOS_H2_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define INTPOS_H2_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define INTPOS_H2_int_hpos_shift                                                     (0)
#define INTPOS_H2_int_hpos_mask                                                      (0x00001FFF)
#define INTPOS_H2_int_hpos(data)                                                     (0x00001FFF&((data)<<0))
#define INTPOS_H2_int_hpos_src(data)                                                 ((0x00001FFF&(data))>>0)
#define INTPOS_H2_get_int_hpos(data)                                                 ((0x00001FFF&(data))>>0)


#define SRSTN                                                                        0x1801F038
#define SRSTN_reg_addr                                                               "0xB800A038"
#define SRSTN_reg                                                                   0xB801F038
#define set_SRSTN_reg(data)   (*((volatile unsigned int*) SRSTN_reg)=data)
#define get_SRSTN_reg   (*((volatile unsigned int*) SRSTN_reg))
#define SRSTN_inst_adr                                                               "0x000E"
#define SRSTN_inst                                                                   0x000E
#define SRSTN_srstn_shift                                                            (0)
#define SRSTN_srstn_mask                                                             (0x00000001)
#define SRSTN_srstn(data)                                                            (0x00000001&((data)<<0))
#define SRSTN_srstn_src(data)                                                        ((0x00000001&(data))>>0)
#define SRSTN_get_srstn(data)                                                        ((0x00000001&(data))>>0)


#define AV_CTRL                                                                      0x1801F040
#define AV_CTRL_reg_addr                                                             "0xB800A040"
#define AV_CTRL_reg                                                                 0xB801F040
#define set_AV_CTRL_reg(data)   (*((volatile unsigned int*) AV_CTRL_reg)=data)
#define get_AV_CTRL_reg   (*((volatile unsigned int*) AV_CTRL_reg))
#define AV_CTRL_inst_adr                                                             "0x0010"
#define AV_CTRL_inst                                                                 0x0010
#define AV_CTRL_h_colorbar_ebl_shift                                                 (6)
#define AV_CTRL_h_colorbar_ebl_mask                                                  (0x00000040)
#define AV_CTRL_h_colorbar_ebl(data)                                                 (0x00000040&((data)<<6))
#define AV_CTRL_h_colorbar_ebl_src(data)                                             ((0x00000040&(data))>>6)
#define AV_CTRL_get_h_colorbar_ebl(data)                                             ((0x00000040&(data))>>6)
#define AV_CTRL_h_black_ebl_shift                                                    (5)
#define AV_CTRL_h_black_ebl_mask                                                     (0x00000020)
#define AV_CTRL_h_black_ebl(data)                                                    (0x00000020&((data)<<5))
#define AV_CTRL_h_black_ebl_src(data)                                                ((0x00000020&(data))>>5)
#define AV_CTRL_get_h_black_ebl(data)                                                ((0x00000020&(data))>>5)
#define AV_CTRL_i_colorbar_ebl_shift                                                 (4)
#define AV_CTRL_i_colorbar_ebl_mask                                                  (0x00000010)
#define AV_CTRL_i_colorbar_ebl(data)                                                 (0x00000010&((data)<<4))
#define AV_CTRL_i_colorbar_ebl_src(data)                                             ((0x00000010&(data))>>4)
#define AV_CTRL_get_i_colorbar_ebl(data)                                             ((0x00000010&(data))>>4)
#define AV_CTRL_p_colorbar_ebl_shift                                                 (3)
#define AV_CTRL_p_colorbar_ebl_mask                                                  (0x00000008)
#define AV_CTRL_p_colorbar_ebl(data)                                                 (0x00000008&((data)<<3))
#define AV_CTRL_p_colorbar_ebl_src(data)                                             ((0x00000008&(data))>>3)
#define AV_CTRL_get_p_colorbar_ebl(data)                                             ((0x00000008&(data))>>3)
#define AV_CTRL_i_black_ebl_shift                                                    (2)
#define AV_CTRL_i_black_ebl_mask                                                     (0x00000004)
#define AV_CTRL_i_black_ebl(data)                                                    (0x00000004&((data)<<2))
#define AV_CTRL_i_black_ebl_src(data)                                                ((0x00000004&(data))>>2)
#define AV_CTRL_get_i_black_ebl(data)                                                ((0x00000004&(data))>>2)
#define AV_CTRL_p_black_ebl_shift                                                    (1)
#define AV_CTRL_p_black_ebl_mask                                                     (0x00000002)
#define AV_CTRL_p_black_ebl(data)                                                    (0x00000002&((data)<<1))
#define AV_CTRL_p_black_ebl_src(data)                                                ((0x00000002&(data))>>1)
#define AV_CTRL_get_p_black_ebl(data)                                                ((0x00000002&(data))>>1)
#define AV_CTRL_write_data_shift                                                     (0)
#define AV_CTRL_write_data_mask                                                      (0x00000001)
#define AV_CTRL_write_data(data)                                                     (0x00000001&((data)<<0))
#define AV_CTRL_write_data_src(data)                                                 ((0x00000001&(data))>>0)
#define AV_CTRL_get_write_data(data)                                                 ((0x00000001&(data))>>0)


#define CAV_422                                                                      0x1801F044
#define CAV_422_reg_addr                                                             "0xB800A044"
#define CAV_422_reg                                                                 0xB801F044
#define set_CAV_422_reg(data)   (*((volatile unsigned int*) CAV_422_reg)=data)
#define get_CAV_422_reg   (*((volatile unsigned int*) CAV_422_reg))
#define CAV_422_inst_adr                                                             "0x0011"
#define CAV_422_inst                                                                 0x0011
#define CAV_422_fir422_sel_shift                                                     (0)
#define CAV_422_fir422_sel_mask                                                      (0x00000003)
#define CAV_422_fir422_sel(data)                                                     (0x00000003&((data)<<0))
#define CAV_422_fir422_sel_src(data)                                                 ((0x00000003&(data))>>0)
#define CAV_422_get_fir422_sel(data)                                                 ((0x00000003&(data))>>0)


#define AV_SLEW                                                                      0x1801F048
#define AV_SLEW_reg_addr                                                             "0xB800A048"
#define AV_SLEW_reg                                                                 0xB801F048
#define set_AV_SLEW_reg(data)   (*((volatile unsigned int*) AV_SLEW_reg)=data)
#define get_AV_SLEW_reg   (*((volatile unsigned int*) AV_SLEW_reg))
#define AV_SLEW_inst_adr                                                             "0x0012"
#define AV_SLEW_inst                                                                 0x0012
#define AV_SLEW_write_en4_shift                                                      (9)
#define AV_SLEW_write_en4_mask                                                       (0x00000200)
#define AV_SLEW_write_en4(data)                                                      (0x00000200&((data)<<9))
#define AV_SLEW_write_en4_src(data)                                                  ((0x00000200&(data))>>9)
#define AV_SLEW_get_write_en4(data)                                                  ((0x00000200&(data))>>9)
#define AV_SLEW_i_en_shift                                                           (8)
#define AV_SLEW_i_en_mask                                                            (0x00000100)
#define AV_SLEW_i_en(data)                                                           (0x00000100&((data)<<8))
#define AV_SLEW_i_en_src(data)                                                       ((0x00000100&(data))>>8)
#define AV_SLEW_get_i_en(data)                                                       ((0x00000100&(data))>>8)
#define AV_SLEW_write_en3_shift                                                      (7)
#define AV_SLEW_write_en3_mask                                                       (0x00000080)
#define AV_SLEW_write_en3(data)                                                      (0x00000080&((data)<<7))
#define AV_SLEW_write_en3_src(data)                                                  ((0x00000080&(data))>>7)
#define AV_SLEW_get_write_en3(data)                                                  ((0x00000080&(data))>>7)
#define AV_SLEW_p_en_shift                                                           (6)
#define AV_SLEW_p_en_mask                                                            (0x00000040)
#define AV_SLEW_p_en(data)                                                           (0x00000040&((data)<<6))
#define AV_SLEW_p_en_src(data)                                                       ((0x00000040&(data))>>6)
#define AV_SLEW_get_p_en(data)                                                       ((0x00000040&(data))>>6)
#define AV_SLEW_write_en2_shift                                                      (5)
#define AV_SLEW_write_en2_mask                                                       (0x00000020)
#define AV_SLEW_write_en2(data)                                                      (0x00000020&((data)<<5))
#define AV_SLEW_write_en2_src(data)                                                  ((0x00000020&(data))>>5)
#define AV_SLEW_get_write_en2(data)                                                  ((0x00000020&(data))>>5)
#define AV_SLEW_i_slewrate_shift                                                     (3)
#define AV_SLEW_i_slewrate_mask                                                      (0x00000018)
#define AV_SLEW_i_slewrate(data)                                                     (0x00000018&((data)<<3))
#define AV_SLEW_i_slewrate_src(data)                                                 ((0x00000018&(data))>>3)
#define AV_SLEW_get_i_slewrate(data)                                                 ((0x00000018&(data))>>3)
#define AV_SLEW_write_en1_shift                                                      (2)
#define AV_SLEW_write_en1_mask                                                       (0x00000004)
#define AV_SLEW_write_en1(data)                                                      (0x00000004&((data)<<2))
#define AV_SLEW_write_en1_src(data)                                                  ((0x00000004&(data))>>2)
#define AV_SLEW_get_write_en1(data)                                                  ((0x00000004&(data))>>2)
#define AV_SLEW_p_slewrate_shift                                                     (0)
#define AV_SLEW_p_slewrate_mask                                                      (0x00000003)
#define AV_SLEW_p_slewrate(data)                                                     (0x00000003&((data)<<0))
#define AV_SLEW_p_slewrate_src(data)                                                 ((0x00000003&(data))>>0)
#define AV_SLEW_get_p_slewrate(data)                                                 ((0x00000003&(data))>>0)


#define SLEW_I_HPOS                                                                  0x1801F04c
#define SLEW_I_HPOS_reg_addr                                                         "0xB800A04C"
#define SLEW_I_HPOS_reg                                                             0xB801F04C
#define set_SLEW_I_HPOS_reg(data)   (*((volatile unsigned int*) SLEW_I_HPOS_reg)=data)
#define get_SLEW_I_HPOS_reg   (*((volatile unsigned int*) SLEW_I_HPOS_reg))
#define SLEW_I_HPOS_inst_adr                                                         "0x0013"
#define SLEW_I_HPOS_inst                                                             0x0013
#define SLEW_I_HPOS_write_en2_shift                                                  (21)
#define SLEW_I_HPOS_write_en2_mask                                                   (0x00200000)
#define SLEW_I_HPOS_write_en2(data)                                                  (0x00200000&((data)<<21))
#define SLEW_I_HPOS_write_en2_src(data)                                              ((0x00200000&(data))>>21)
#define SLEW_I_HPOS_get_write_en2(data)                                              ((0x00200000&(data))>>21)
#define SLEW_I_HPOS_i_h_st_shift                                                     (11)
#define SLEW_I_HPOS_i_h_st_mask                                                      (0x001FF800)
#define SLEW_I_HPOS_i_h_st(data)                                                     (0x001FF800&((data)<<11))
#define SLEW_I_HPOS_i_h_st_src(data)                                                 ((0x001FF800&(data))>>11)
#define SLEW_I_HPOS_get_i_h_st(data)                                                 ((0x001FF800&(data))>>11)
#define SLEW_I_HPOS_write_en1_shift                                                  (10)
#define SLEW_I_HPOS_write_en1_mask                                                   (0x00000400)
#define SLEW_I_HPOS_write_en1(data)                                                  (0x00000400&((data)<<10))
#define SLEW_I_HPOS_write_en1_src(data)                                              ((0x00000400&(data))>>10)
#define SLEW_I_HPOS_get_write_en1(data)                                              ((0x00000400&(data))>>10)
#define SLEW_I_HPOS_i_h_end_shift                                                    (0)
#define SLEW_I_HPOS_i_h_end_mask                                                     (0x000003FF)
#define SLEW_I_HPOS_i_h_end(data)                                                    (0x000003FF&((data)<<0))
#define SLEW_I_HPOS_i_h_end_src(data)                                                ((0x000003FF&(data))>>0)
#define SLEW_I_HPOS_get_i_h_end(data)                                                ((0x000003FF&(data))>>0)


#define AV_I_HPOS                                                                    0x1801F050
#define AV_I_HPOS_reg_addr                                                           "0xB800A050"
#define AV_I_HPOS_reg                                                               0xB801F050
#define set_AV_I_HPOS_reg(data)   (*((volatile unsigned int*) AV_I_HPOS_reg)=data)
#define get_AV_I_HPOS_reg   (*((volatile unsigned int*) AV_I_HPOS_reg))
#define AV_I_HPOS_inst_adr                                                           "0x0014"
#define AV_I_HPOS_inst                                                               0x0014
#define AV_I_HPOS_write_en2_shift                                                    (27)
#define AV_I_HPOS_write_en2_mask                                                     (0x08000000)
#define AV_I_HPOS_write_en2(data)                                                    (0x08000000&((data)<<27))
#define AV_I_HPOS_write_en2_src(data)                                                ((0x08000000&(data))>>27)
#define AV_I_HPOS_get_write_en2(data)                                                ((0x08000000&(data))>>27)
#define AV_I_HPOS_i_h_st_shift                                                       (14)
#define AV_I_HPOS_i_h_st_mask                                                        (0x07FFC000)
#define AV_I_HPOS_i_h_st(data)                                                       (0x07FFC000&((data)<<14))
#define AV_I_HPOS_i_h_st_src(data)                                                   ((0x07FFC000&(data))>>14)
#define AV_I_HPOS_get_i_h_st(data)                                                   ((0x07FFC000&(data))>>14)
#define AV_I_HPOS_write_en1_shift                                                    (13)
#define AV_I_HPOS_write_en1_mask                                                     (0x00002000)
#define AV_I_HPOS_write_en1(data)                                                    (0x00002000&((data)<<13))
#define AV_I_HPOS_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define AV_I_HPOS_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define AV_I_HPOS_i_h_end_shift                                                      (0)
#define AV_I_HPOS_i_h_end_mask                                                       (0x00001FFF)
#define AV_I_HPOS_i_h_end(data)                                                      (0x00001FFF&((data)<<0))
#define AV_I_HPOS_i_h_end_src(data)                                                  ((0x00001FFF&(data))>>0)
#define AV_I_HPOS_get_i_h_end(data)                                                  ((0x00001FFF&(data))>>0)


#define AV_P_HPOS1                                                                   0x1801F054
#define AV_P_HPOS1_reg_addr                                                          "0xB800A054"
#define AV_P_HPOS1_reg                                                              0xB801F054
#define set_AV_P_HPOS1_reg(data)   (*((volatile unsigned int*) AV_P_HPOS1_reg)=data)
#define get_AV_P_HPOS1_reg   (*((volatile unsigned int*) AV_P_HPOS1_reg))
#define AV_P_HPOS1_inst_adr                                                          "0x0015"
#define AV_P_HPOS1_inst                                                              0x0015
#define AV_P_HPOS1_write_en3_shift                                                   (29)
#define AV_P_HPOS1_write_en3_mask                                                    (0x20000000)
#define AV_P_HPOS1_write_en3(data)                                                   (0x20000000&((data)<<29))
#define AV_P_HPOS1_write_en3_src(data)                                               ((0x20000000&(data))>>29)
#define AV_P_HPOS1_get_write_en3(data)                                               ((0x20000000&(data))>>29)
#define AV_P_HPOS1_p_av_cord_shift                                                   (28)
#define AV_P_HPOS1_p_av_cord_mask                                                    (0x10000000)
#define AV_P_HPOS1_p_av_cord(data)                                                   (0x10000000&((data)<<28))
#define AV_P_HPOS1_p_av_cord_src(data)                                               ((0x10000000&(data))>>28)
#define AV_P_HPOS1_get_p_av_cord(data)                                               ((0x10000000&(data))>>28)
#define AV_P_HPOS1_write_en2_shift                                                   (27)
#define AV_P_HPOS1_write_en2_mask                                                    (0x08000000)
#define AV_P_HPOS1_write_en2(data)                                                   (0x08000000&((data)<<27))
#define AV_P_HPOS1_write_en2_src(data)                                               ((0x08000000&(data))>>27)
#define AV_P_HPOS1_get_write_en2(data)                                               ((0x08000000&(data))>>27)
#define AV_P_HPOS1_p_h_st_shift                                                      (14)
#define AV_P_HPOS1_p_h_st_mask                                                       (0x07FFC000)
#define AV_P_HPOS1_p_h_st(data)                                                      (0x07FFC000&((data)<<14))
#define AV_P_HPOS1_p_h_st_src(data)                                                  ((0x07FFC000&(data))>>14)
#define AV_P_HPOS1_get_p_h_st(data)                                                  ((0x07FFC000&(data))>>14)
#define AV_P_HPOS1_write_en1_shift                                                   (13)
#define AV_P_HPOS1_write_en1_mask                                                    (0x00002000)
#define AV_P_HPOS1_write_en1(data)                                                   (0x00002000&((data)<<13))
#define AV_P_HPOS1_write_en1_src(data)                                               ((0x00002000&(data))>>13)
#define AV_P_HPOS1_get_write_en1(data)                                               ((0x00002000&(data))>>13)
#define AV_P_HPOS1_p_h_end_shift                                                     (0)
#define AV_P_HPOS1_p_h_end_mask                                                      (0x00001FFF)
#define AV_P_HPOS1_p_h_end(data)                                                     (0x00001FFF&((data)<<0))
#define AV_P_HPOS1_p_h_end_src(data)                                                 ((0x00001FFF&(data))>>0)
#define AV_P_HPOS1_get_p_h_end(data)                                                 ((0x00001FFF&(data))>>0)


#define AV_H_HPOS1                                                                   0x1801F058
#define AV_H_HPOS1_reg_addr                                                          "0xB800A058"
#define AV_H_HPOS1_reg                                                              0xB801F058
#define set_AV_H_HPOS1_reg(data)   (*((volatile unsigned int*) AV_H_HPOS1_reg)=data)
#define get_AV_H_HPOS1_reg   (*((volatile unsigned int*) AV_H_HPOS1_reg))
#define AV_H_HPOS1_inst_adr                                                          "0x0016"
#define AV_H_HPOS1_inst                                                              0x0016
#define AV_H_HPOS1_write_en3_shift                                                   (29)
#define AV_H_HPOS1_write_en3_mask                                                    (0x20000000)
#define AV_H_HPOS1_write_en3(data)                                                   (0x20000000&((data)<<29))
#define AV_H_HPOS1_write_en3_src(data)                                               ((0x20000000&(data))>>29)
#define AV_H_HPOS1_get_write_en3(data)                                               ((0x20000000&(data))>>29)
#define AV_H_HPOS1_h_av_cord_shift                                                   (28)
#define AV_H_HPOS1_h_av_cord_mask                                                    (0x10000000)
#define AV_H_HPOS1_h_av_cord(data)                                                   (0x10000000&((data)<<28))
#define AV_H_HPOS1_h_av_cord_src(data)                                               ((0x10000000&(data))>>28)
#define AV_H_HPOS1_get_h_av_cord(data)                                               ((0x10000000&(data))>>28)
#define AV_H_HPOS1_write_en2_shift                                                   (27)
#define AV_H_HPOS1_write_en2_mask                                                    (0x08000000)
#define AV_H_HPOS1_write_en2(data)                                                   (0x08000000&((data)<<27))
#define AV_H_HPOS1_write_en2_src(data)                                               ((0x08000000&(data))>>27)
#define AV_H_HPOS1_get_write_en2(data)                                               ((0x08000000&(data))>>27)
#define AV_H_HPOS1_h_h_st_shift                                                      (14)
#define AV_H_HPOS1_h_h_st_mask                                                       (0x07FFC000)
#define AV_H_HPOS1_h_h_st(data)                                                      (0x07FFC000&((data)<<14))
#define AV_H_HPOS1_h_h_st_src(data)                                                  ((0x07FFC000&(data))>>14)
#define AV_H_HPOS1_get_h_h_st(data)                                                  ((0x07FFC000&(data))>>14)
#define AV_H_HPOS1_write_en1_shift                                                   (13)
#define AV_H_HPOS1_write_en1_mask                                                    (0x00002000)
#define AV_H_HPOS1_write_en1(data)                                                   (0x00002000&((data)<<13))
#define AV_H_HPOS1_write_en1_src(data)                                               ((0x00002000&(data))>>13)
#define AV_H_HPOS1_get_write_en1(data)                                               ((0x00002000&(data))>>13)
#define AV_H_HPOS1_h_h_end_shift                                                     (0)
#define AV_H_HPOS1_h_h_end_mask                                                      (0x00001FFF)
#define AV_H_HPOS1_h_h_end(data)                                                     (0x00001FFF&((data)<<0))
#define AV_H_HPOS1_h_h_end_src(data)                                                 ((0x00001FFF&(data))>>0)
#define AV_H_HPOS1_get_h_h_end(data)                                                 ((0x00001FFF&(data))>>0)


#define ITOP_VPOS                                                                    0x1801F05c
#define ITOP_VPOS_reg_addr                                                           "0xB800A05C"
#define ITOP_VPOS_reg                                                               0xB801F05C
#define set_ITOP_VPOS_reg(data)   (*((volatile unsigned int*) ITOP_VPOS_reg)=data)
#define get_ITOP_VPOS_reg   (*((volatile unsigned int*) ITOP_VPOS_reg))
#define ITOP_VPOS_inst_adr                                                           "0x0017"
#define ITOP_VPOS_inst                                                               0x0017
#define ITOP_VPOS_write_en2_shift                                                    (23)
#define ITOP_VPOS_write_en2_mask                                                     (0x00800000)
#define ITOP_VPOS_write_en2(data)                                                    (0x00800000&((data)<<23))
#define ITOP_VPOS_write_en2_src(data)                                                ((0x00800000&(data))>>23)
#define ITOP_VPOS_get_write_en2(data)                                                ((0x00800000&(data))>>23)
#define ITOP_VPOS_itop_v_st_shift                                                    (12)
#define ITOP_VPOS_itop_v_st_mask                                                     (0x007FF000)
#define ITOP_VPOS_itop_v_st(data)                                                    (0x007FF000&((data)<<12))
#define ITOP_VPOS_itop_v_st_src(data)                                                ((0x007FF000&(data))>>12)
#define ITOP_VPOS_get_itop_v_st(data)                                                ((0x007FF000&(data))>>12)
#define ITOP_VPOS_write_en1_shift                                                    (11)
#define ITOP_VPOS_write_en1_mask                                                     (0x00000800)
#define ITOP_VPOS_write_en1(data)                                                    (0x00000800&((data)<<11))
#define ITOP_VPOS_write_en1_src(data)                                                ((0x00000800&(data))>>11)
#define ITOP_VPOS_get_write_en1(data)                                                ((0x00000800&(data))>>11)
#define ITOP_VPOS_itop_v_end_shift                                                   (0)
#define ITOP_VPOS_itop_v_end_mask                                                    (0x000007FF)
#define ITOP_VPOS_itop_v_end(data)                                                   (0x000007FF&((data)<<0))
#define ITOP_VPOS_itop_v_end_src(data)                                               ((0x000007FF&(data))>>0)
#define ITOP_VPOS_get_itop_v_end(data)                                               ((0x000007FF&(data))>>0)


#define IBOT_VPOS                                                                    0x1801F060
#define IBOT_VPOS_reg_addr                                                           "0xB800A060"
#define IBOT_VPOS_reg                                                               0xB801F060
#define set_IBOT_VPOS_reg(data)   (*((volatile unsigned int*) IBOT_VPOS_reg)=data)
#define get_IBOT_VPOS_reg   (*((volatile unsigned int*) IBOT_VPOS_reg))
#define IBOT_VPOS_inst_adr                                                           "0x0018"
#define IBOT_VPOS_inst                                                               0x0018
#define IBOT_VPOS_write_en2_shift                                                    (23)
#define IBOT_VPOS_write_en2_mask                                                     (0x00800000)
#define IBOT_VPOS_write_en2(data)                                                    (0x00800000&((data)<<23))
#define IBOT_VPOS_write_en2_src(data)                                                ((0x00800000&(data))>>23)
#define IBOT_VPOS_get_write_en2(data)                                                ((0x00800000&(data))>>23)
#define IBOT_VPOS_ibot_v_st_shift                                                    (12)
#define IBOT_VPOS_ibot_v_st_mask                                                     (0x007FF000)
#define IBOT_VPOS_ibot_v_st(data)                                                    (0x007FF000&((data)<<12))
#define IBOT_VPOS_ibot_v_st_src(data)                                                ((0x007FF000&(data))>>12)
#define IBOT_VPOS_get_ibot_v_st(data)                                                ((0x007FF000&(data))>>12)
#define IBOT_VPOS_write_en1_shift                                                    (11)
#define IBOT_VPOS_write_en1_mask                                                     (0x00000800)
#define IBOT_VPOS_write_en1(data)                                                    (0x00000800&((data)<<11))
#define IBOT_VPOS_write_en1_src(data)                                                ((0x00000800&(data))>>11)
#define IBOT_VPOS_get_write_en1(data)                                                ((0x00000800&(data))>>11)
#define IBOT_VPOS_ibot_v_end_shift                                                   (0)
#define IBOT_VPOS_ibot_v_end_mask                                                    (0x000007FF)
#define IBOT_VPOS_ibot_v_end(data)                                                   (0x000007FF&((data)<<0))
#define IBOT_VPOS_ibot_v_end_src(data)                                               ((0x000007FF&(data))>>0)
#define IBOT_VPOS_get_ibot_v_end(data)                                               ((0x000007FF&(data))>>0)


#define P_VPOS1                                                                      0x1801F064
#define P_VPOS1_reg_addr                                                             "0xB800A064"
#define P_VPOS1_reg                                                                 0xB801F064
#define set_P_VPOS1_reg(data)   (*((volatile unsigned int*) P_VPOS1_reg)=data)
#define get_P_VPOS1_reg   (*((volatile unsigned int*) P_VPOS1_reg))
#define P_VPOS1_inst_adr                                                             "0x0019"
#define P_VPOS1_inst                                                                 0x0019
#define P_VPOS1_write_en2_shift                                                      (23)
#define P_VPOS1_write_en2_mask                                                       (0x00800000)
#define P_VPOS1_write_en2(data)                                                      (0x00800000&((data)<<23))
#define P_VPOS1_write_en2_src(data)                                                  ((0x00800000&(data))>>23)
#define P_VPOS1_get_write_en2(data)                                                  ((0x00800000&(data))>>23)
#define P_VPOS1_p_v_st_shift                                                         (12)
#define P_VPOS1_p_v_st_mask                                                          (0x007FF000)
#define P_VPOS1_p_v_st(data)                                                         (0x007FF000&((data)<<12))
#define P_VPOS1_p_v_st_src(data)                                                     ((0x007FF000&(data))>>12)
#define P_VPOS1_get_p_v_st(data)                                                     ((0x007FF000&(data))>>12)
#define P_VPOS1_write_en1_shift                                                      (11)
#define P_VPOS1_write_en1_mask                                                       (0x00000800)
#define P_VPOS1_write_en1(data)                                                      (0x00000800&((data)<<11))
#define P_VPOS1_write_en1_src(data)                                                  ((0x00000800&(data))>>11)
#define P_VPOS1_get_write_en1(data)                                                  ((0x00000800&(data))>>11)
#define P_VPOS1_p_v_end_shift                                                        (0)
#define P_VPOS1_p_v_end_mask                                                         (0x000007FF)
#define P_VPOS1_p_v_end(data)                                                        (0x000007FF&((data)<<0))
#define P_VPOS1_p_v_end_src(data)                                                    ((0x000007FF&(data))>>0)
#define P_VPOS1_get_p_v_end(data)                                                    ((0x000007FF&(data))>>0)


#define P_VPOS2                                                                      0x1801F068
#define P_VPOS2_reg_addr                                                             "0xB800A068"
#define P_VPOS2_reg                                                                 0xB801F068
#define set_P_VPOS2_reg(data)   (*((volatile unsigned int*) P_VPOS2_reg)=data)
#define get_P_VPOS2_reg   (*((volatile unsigned int*) P_VPOS2_reg))
#define P_VPOS2_inst_adr                                                             "0x001A"
#define P_VPOS2_inst                                                                 0x001A
#define P_VPOS2_write_en2_shift                                                      (23)
#define P_VPOS2_write_en2_mask                                                       (0x00800000)
#define P_VPOS2_write_en2(data)                                                      (0x00800000&((data)<<23))
#define P_VPOS2_write_en2_src(data)                                                  ((0x00800000&(data))>>23)
#define P_VPOS2_get_write_en2(data)                                                  ((0x00800000&(data))>>23)
#define P_VPOS2_p_v_st_shift                                                         (12)
#define P_VPOS2_p_v_st_mask                                                          (0x007FF000)
#define P_VPOS2_p_v_st(data)                                                         (0x007FF000&((data)<<12))
#define P_VPOS2_p_v_st_src(data)                                                     ((0x007FF000&(data))>>12)
#define P_VPOS2_get_p_v_st(data)                                                     ((0x007FF000&(data))>>12)
#define P_VPOS2_write_en1_shift                                                      (11)
#define P_VPOS2_write_en1_mask                                                       (0x00000800)
#define P_VPOS2_write_en1(data)                                                      (0x00000800&((data)<<11))
#define P_VPOS2_write_en1_src(data)                                                  ((0x00000800&(data))>>11)
#define P_VPOS2_get_write_en1(data)                                                  ((0x00000800&(data))>>11)
#define P_VPOS2_p_v_end_shift                                                        (0)
#define P_VPOS2_p_v_end_mask                                                         (0x000007FF)
#define P_VPOS2_p_v_end(data)                                                        (0x000007FF&((data)<<0))
#define P_VPOS2_p_v_end_src(data)                                                    ((0x000007FF&(data))>>0)
#define P_VPOS2_get_p_v_end(data)                                                    ((0x000007FF&(data))>>0)


#define H_VPOS1                                                                      0x1801F06c
#define H_VPOS1_reg_addr                                                             "0xB800A06C"
#define H_VPOS1_reg                                                                 0xB801F06C
#define set_H_VPOS1_reg(data)   (*((volatile unsigned int*) H_VPOS1_reg)=data)
#define get_H_VPOS1_reg   (*((volatile unsigned int*) H_VPOS1_reg))
#define H_VPOS1_inst_adr                                                             "0x001B"
#define H_VPOS1_inst                                                                 0x001B
#define H_VPOS1_write_en2_shift                                                      (23)
#define H_VPOS1_write_en2_mask                                                       (0x00800000)
#define H_VPOS1_write_en2(data)                                                      (0x00800000&((data)<<23))
#define H_VPOS1_write_en2_src(data)                                                  ((0x00800000&(data))>>23)
#define H_VPOS1_get_write_en2(data)                                                  ((0x00800000&(data))>>23)
#define H_VPOS1_h_v_st_shift                                                         (12)
#define H_VPOS1_h_v_st_mask                                                          (0x007FF000)
#define H_VPOS1_h_v_st(data)                                                         (0x007FF000&((data)<<12))
#define H_VPOS1_h_v_st_src(data)                                                     ((0x007FF000&(data))>>12)
#define H_VPOS1_get_h_v_st(data)                                                     ((0x007FF000&(data))>>12)
#define H_VPOS1_write_en1_shift                                                      (11)
#define H_VPOS1_write_en1_mask                                                       (0x00000800)
#define H_VPOS1_write_en1(data)                                                      (0x00000800&((data)<<11))
#define H_VPOS1_write_en1_src(data)                                                  ((0x00000800&(data))>>11)
#define H_VPOS1_get_write_en1(data)                                                  ((0x00000800&(data))>>11)
#define H_VPOS1_h_v_end_shift                                                        (0)
#define H_VPOS1_h_v_end_mask                                                         (0x000007FF)
#define H_VPOS1_h_v_end(data)                                                        (0x000007FF&((data)<<0))
#define H_VPOS1_h_v_end_src(data)                                                    ((0x000007FF&(data))>>0)
#define H_VPOS1_get_h_v_end(data)                                                    ((0x000007FF&(data))>>0)


#define H_VPOS2                                                                      0x1801F070
#define H_VPOS2_reg_addr                                                             "0xB800A070"
#define H_VPOS2_reg                                                                 0xB801F070
#define set_H_VPOS2_reg(data)   (*((volatile unsigned int*) H_VPOS2_reg)=data)
#define get_H_VPOS2_reg   (*((volatile unsigned int*) H_VPOS2_reg))
#define H_VPOS2_inst_adr                                                             "0x001C"
#define H_VPOS2_inst                                                                 0x001C
#define H_VPOS2_write_en2_shift                                                      (23)
#define H_VPOS2_write_en2_mask                                                       (0x00800000)
#define H_VPOS2_write_en2(data)                                                      (0x00800000&((data)<<23))
#define H_VPOS2_write_en2_src(data)                                                  ((0x00800000&(data))>>23)
#define H_VPOS2_get_write_en2(data)                                                  ((0x00800000&(data))>>23)
#define H_VPOS2_h_v_st_shift                                                         (12)
#define H_VPOS2_h_v_st_mask                                                          (0x007FF000)
#define H_VPOS2_h_v_st(data)                                                         (0x007FF000&((data)<<12))
#define H_VPOS2_h_v_st_src(data)                                                     ((0x007FF000&(data))>>12)
#define H_VPOS2_get_h_v_st(data)                                                     ((0x007FF000&(data))>>12)
#define H_VPOS2_write_en1_shift                                                      (11)
#define H_VPOS2_write_en1_mask                                                       (0x00000800)
#define H_VPOS2_write_en1(data)                                                      (0x00000800&((data)<<11))
#define H_VPOS2_write_en1_src(data)                                                  ((0x00000800&(data))>>11)
#define H_VPOS2_get_write_en1(data)                                                  ((0x00000800&(data))>>11)
#define H_VPOS2_h_v_end_shift                                                        (0)
#define H_VPOS2_h_v_end_mask                                                         (0x000007FF)
#define H_VPOS2_h_v_end(data)                                                        (0x000007FF&((data)<<0))
#define H_VPOS2_h_v_end_src(data)                                                    ((0x000007FF&(data))>>0)
#define H_VPOS2_get_h_v_end(data)                                                    ((0x000007FF&(data))>>0)


#define I_COLORBAR_HPOS                                                              0x1801F074
#define I_COLORBAR_HPOS_reg_addr                                                     "0xB800A074"
#define I_COLORBAR_HPOS_reg                                                         0xB801F074
#define set_I_COLORBAR_HPOS_reg(data)   (*((volatile unsigned int*) I_COLORBAR_HPOS_reg)=data)
#define get_I_COLORBAR_HPOS_reg   (*((volatile unsigned int*) I_COLORBAR_HPOS_reg))
#define I_COLORBAR_HPOS_inst_adr                                                     "0x001D"
#define I_COLORBAR_HPOS_inst                                                         0x001D
#define I_COLORBAR_HPOS_write_en2_shift                                              (21)
#define I_COLORBAR_HPOS_write_en2_mask                                               (0x00200000)
#define I_COLORBAR_HPOS_write_en2(data)                                              (0x00200000&((data)<<21))
#define I_COLORBAR_HPOS_write_en2_src(data)                                          ((0x00200000&(data))>>21)
#define I_COLORBAR_HPOS_get_write_en2(data)                                          ((0x00200000&(data))>>21)
#define I_COLORBAR_HPOS_i_h_width_shift                                              (11)
#define I_COLORBAR_HPOS_i_h_width_mask                                               (0x001FF800)
#define I_COLORBAR_HPOS_i_h_width(data)                                              (0x001FF800&((data)<<11))
#define I_COLORBAR_HPOS_i_h_width_src(data)                                          ((0x001FF800&(data))>>11)
#define I_COLORBAR_HPOS_get_i_h_width(data)                                          ((0x001FF800&(data))>>11)
#define I_COLORBAR_HPOS_write_en1_shift                                              (10)
#define I_COLORBAR_HPOS_write_en1_mask                                               (0x00000400)
#define I_COLORBAR_HPOS_write_en1(data)                                              (0x00000400&((data)<<10))
#define I_COLORBAR_HPOS_write_en1_src(data)                                          ((0x00000400&(data))>>10)
#define I_COLORBAR_HPOS_get_write_en1(data)                                          ((0x00000400&(data))>>10)
#define I_COLORBAR_HPOS_i_h_st_pos_shift                                             (0)
#define I_COLORBAR_HPOS_i_h_st_pos_mask                                              (0x000003FF)
#define I_COLORBAR_HPOS_i_h_st_pos(data)                                             (0x000003FF&((data)<<0))
#define I_COLORBAR_HPOS_i_h_st_pos_src(data)                                         ((0x000003FF&(data))>>0)
#define I_COLORBAR_HPOS_get_i_h_st_pos(data)                                         ((0x000003FF&(data))>>0)


#define P_COLORBAR_HPOS                                                              0x1801F078
#define P_COLORBAR_HPOS_reg_addr                                                     "0xB800A078"
#define P_COLORBAR_HPOS_reg                                                         0xB801F078
#define set_P_COLORBAR_HPOS_reg(data)   (*((volatile unsigned int*) P_COLORBAR_HPOS_reg)=data)
#define get_P_COLORBAR_HPOS_reg   (*((volatile unsigned int*) P_COLORBAR_HPOS_reg))
#define P_COLORBAR_HPOS_inst_adr                                                     "0x001E"
#define P_COLORBAR_HPOS_inst                                                         0x001E
#define P_COLORBAR_HPOS_write_en2_shift                                              (21)
#define P_COLORBAR_HPOS_write_en2_mask                                               (0x00200000)
#define P_COLORBAR_HPOS_write_en2(data)                                              (0x00200000&((data)<<21))
#define P_COLORBAR_HPOS_write_en2_src(data)                                          ((0x00200000&(data))>>21)
#define P_COLORBAR_HPOS_get_write_en2(data)                                          ((0x00200000&(data))>>21)
#define P_COLORBAR_HPOS_p_h_width_shift                                              (11)
#define P_COLORBAR_HPOS_p_h_width_mask                                               (0x001FF800)
#define P_COLORBAR_HPOS_p_h_width(data)                                              (0x001FF800&((data)<<11))
#define P_COLORBAR_HPOS_p_h_width_src(data)                                          ((0x001FF800&(data))>>11)
#define P_COLORBAR_HPOS_get_p_h_width(data)                                          ((0x001FF800&(data))>>11)
#define P_COLORBAR_HPOS_write_en1_shift                                              (10)
#define P_COLORBAR_HPOS_write_en1_mask                                               (0x00000400)
#define P_COLORBAR_HPOS_write_en1(data)                                              (0x00000400&((data)<<10))
#define P_COLORBAR_HPOS_write_en1_src(data)                                          ((0x00000400&(data))>>10)
#define P_COLORBAR_HPOS_get_write_en1(data)                                          ((0x00000400&(data))>>10)
#define P_COLORBAR_HPOS_p_h_st_pos_shift                                             (0)
#define P_COLORBAR_HPOS_p_h_st_pos_mask                                              (0x000003FF)
#define P_COLORBAR_HPOS_p_h_st_pos(data)                                             (0x000003FF&((data)<<0))
#define P_COLORBAR_HPOS_p_h_st_pos_src(data)                                         ((0x000003FF&(data))>>0)
#define P_COLORBAR_HPOS_get_p_h_st_pos(data)                                         ((0x000003FF&(data))>>0)


#define H_COLORBAR_HPOS                                                              0x1801F07c
#define H_COLORBAR_HPOS_reg_addr                                                     "0xB800A07C"
#define H_COLORBAR_HPOS_reg                                                         0xB801F07C
#define set_H_COLORBAR_HPOS_reg(data)   (*((volatile unsigned int*) H_COLORBAR_HPOS_reg)=data)
#define get_H_COLORBAR_HPOS_reg   (*((volatile unsigned int*) H_COLORBAR_HPOS_reg))
#define H_COLORBAR_HPOS_inst_adr                                                     "0x001F"
#define H_COLORBAR_HPOS_inst                                                         0x001F
#define H_COLORBAR_HPOS_write_en2_shift                                              (21)
#define H_COLORBAR_HPOS_write_en2_mask                                               (0x00200000)
#define H_COLORBAR_HPOS_write_en2(data)                                              (0x00200000&((data)<<21))
#define H_COLORBAR_HPOS_write_en2_src(data)                                          ((0x00200000&(data))>>21)
#define H_COLORBAR_HPOS_get_write_en2(data)                                          ((0x00200000&(data))>>21)
#define H_COLORBAR_HPOS_p_h_width_shift                                              (11)
#define H_COLORBAR_HPOS_p_h_width_mask                                               (0x001FF800)
#define H_COLORBAR_HPOS_p_h_width(data)                                              (0x001FF800&((data)<<11))
#define H_COLORBAR_HPOS_p_h_width_src(data)                                          ((0x001FF800&(data))>>11)
#define H_COLORBAR_HPOS_get_p_h_width(data)                                          ((0x001FF800&(data))>>11)
#define H_COLORBAR_HPOS_write_en1_shift                                              (10)
#define H_COLORBAR_HPOS_write_en1_mask                                               (0x00000400)
#define H_COLORBAR_HPOS_write_en1(data)                                              (0x00000400&((data)<<10))
#define H_COLORBAR_HPOS_write_en1_src(data)                                          ((0x00000400&(data))>>10)
#define H_COLORBAR_HPOS_get_write_en1(data)                                          ((0x00000400&(data))>>10)
#define H_COLORBAR_HPOS_p_h_st_pos_shift                                             (0)
#define H_COLORBAR_HPOS_p_h_st_pos_mask                                              (0x000003FF)
#define H_COLORBAR_HPOS_p_h_st_pos(data)                                             (0x000003FF&((data)<<0))
#define H_COLORBAR_HPOS_p_h_st_pos_src(data)                                         ((0x000003FF&(data))>>0)
#define H_COLORBAR_HPOS_get_p_h_st_pos(data)                                         ((0x000003FF&(data))>>0)


#define COMP_VSYNC_HPOS                                                              0x1801F080
#define COMP_VSYNC_HPOS_reg_addr                                                     "0xB800A080"
#define COMP_VSYNC_HPOS_reg                                                         0xB801F080
#define set_COMP_VSYNC_HPOS_reg(data)   (*((volatile unsigned int*) COMP_VSYNC_HPOS_reg)=data)
#define get_COMP_VSYNC_HPOS_reg   (*((volatile unsigned int*) COMP_VSYNC_HPOS_reg))
#define COMP_VSYNC_HPOS_inst_adr                                                     "0x0020"
#define COMP_VSYNC_HPOS_inst                                                         0x0020
#define COMP_VSYNC_HPOS_write_en3_shift                                              (29)
#define COMP_VSYNC_HPOS_write_en3_mask                                               (0x20000000)
#define COMP_VSYNC_HPOS_write_en3(data)                                              (0x20000000&((data)<<29))
#define COMP_VSYNC_HPOS_write_en3_src(data)                                          ((0x20000000&(data))>>29)
#define COMP_VSYNC_HPOS_get_write_en3(data)                                          ((0x20000000&(data))>>29)
#define COMP_VSYNC_HPOS_negsyncst_shift                                              (20)
#define COMP_VSYNC_HPOS_negsyncst_mask                                               (0x1FF00000)
#define COMP_VSYNC_HPOS_negsyncst(data)                                              (0x1FF00000&((data)<<20))
#define COMP_VSYNC_HPOS_negsyncst_src(data)                                          ((0x1FF00000&(data))>>20)
#define COMP_VSYNC_HPOS_get_negsyncst(data)                                          ((0x1FF00000&(data))>>20)
#define COMP_VSYNC_HPOS_write_en2_shift                                              (19)
#define COMP_VSYNC_HPOS_write_en2_mask                                               (0x00080000)
#define COMP_VSYNC_HPOS_write_en2(data)                                              (0x00080000&((data)<<19))
#define COMP_VSYNC_HPOS_write_en2_src(data)                                          ((0x00080000&(data))>>19)
#define COMP_VSYNC_HPOS_get_write_en2(data)                                          ((0x00080000&(data))>>19)
#define COMP_VSYNC_HPOS_possyncst_shift                                              (10)
#define COMP_VSYNC_HPOS_possyncst_mask                                               (0x0007FC00)
#define COMP_VSYNC_HPOS_possyncst(data)                                              (0x0007FC00&((data)<<10))
#define COMP_VSYNC_HPOS_possyncst_src(data)                                          ((0x0007FC00&(data))>>10)
#define COMP_VSYNC_HPOS_get_possyncst(data)                                          ((0x0007FC00&(data))>>10)
#define COMP_VSYNC_HPOS_write_en1_shift                                              (9)
#define COMP_VSYNC_HPOS_write_en1_mask                                               (0x00000200)
#define COMP_VSYNC_HPOS_write_en1(data)                                              (0x00000200&((data)<<9))
#define COMP_VSYNC_HPOS_write_en1_src(data)                                          ((0x00000200&(data))>>9)
#define COMP_VSYNC_HPOS_get_write_en1(data)                                          ((0x00000200&(data))>>9)
#define COMP_VSYNC_HPOS_syncend_shift                                                (0)
#define COMP_VSYNC_HPOS_syncend_mask                                                 (0x000001FF)
#define COMP_VSYNC_HPOS_syncend(data)                                                (0x000001FF&((data)<<0))
#define COMP_VSYNC_HPOS_syncend_src(data)                                            ((0x000001FF&(data))>>0)
#define COMP_VSYNC_HPOS_get_syncend(data)                                            ((0x000001FF&(data))>>0)


#define COMP_SER_CTRL                                                                0x1801F084
#define COMP_SER_CTRL_reg_addr                                                       "0xB800A084"
#define COMP_SER_CTRL_reg                                                           0xB801F084
#define set_COMP_SER_CTRL_reg(data)   (*((volatile unsigned int*) COMP_SER_CTRL_reg)=data)
#define get_COMP_SER_CTRL_reg   (*((volatile unsigned int*) COMP_SER_CTRL_reg))
#define COMP_SER_CTRL_inst_adr                                                       "0x0021"
#define COMP_SER_CTRL_inst                                                           0x0021
#define COMP_SER_CTRL_1080i_ebl_shift                                                (0)
#define COMP_SER_CTRL_1080i_ebl_mask                                                 (0x00000001)
#define COMP_SER_CTRL_1080i_ebl(data)                                                (0x00000001&((data)<<0))
#define COMP_SER_CTRL_1080i_ebl_src(data)                                            ((0x00000001&(data))>>0)
#define COMP_SER_CTRL_get_1080i_ebl(data)                                            ((0x00000001&(data))>>0)


#define COMP_SER_HPOS                                                                0x1801F088
#define COMP_SER_HPOS_reg_addr                                                       "0xB800A088"
#define COMP_SER_HPOS_reg                                                           0xB801F088
#define set_COMP_SER_HPOS_reg(data)   (*((volatile unsigned int*) COMP_SER_HPOS_reg)=data)
#define get_COMP_SER_HPOS_reg   (*((volatile unsigned int*) COMP_SER_HPOS_reg))
#define COMP_SER_HPOS_inst_adr                                                       "0x0022"
#define COMP_SER_HPOS_inst                                                           0x0022
#define COMP_SER_HPOS_write_en2_shift                                                (27)
#define COMP_SER_HPOS_write_en2_mask                                                 (0x08000000)
#define COMP_SER_HPOS_write_en2(data)                                                (0x08000000&((data)<<27))
#define COMP_SER_HPOS_write_en2_src(data)                                            ((0x08000000&(data))>>27)
#define COMP_SER_HPOS_get_write_en2(data)                                            ((0x08000000&(data))>>27)
#define COMP_SER_HPOS_ser_hstart_shift                                               (14)
#define COMP_SER_HPOS_ser_hstart_mask                                                (0x07FFC000)
#define COMP_SER_HPOS_ser_hstart(data)                                               (0x07FFC000&((data)<<14))
#define COMP_SER_HPOS_ser_hstart_src(data)                                           ((0x07FFC000&(data))>>14)
#define COMP_SER_HPOS_get_ser_hstart(data)                                           ((0x07FFC000&(data))>>14)
#define COMP_SER_HPOS_write_en1_shift                                                (13)
#define COMP_SER_HPOS_write_en1_mask                                                 (0x00002000)
#define COMP_SER_HPOS_write_en1(data)                                                (0x00002000&((data)<<13))
#define COMP_SER_HPOS_write_en1_src(data)                                            ((0x00002000&(data))>>13)
#define COMP_SER_HPOS_get_write_en1(data)                                            ((0x00002000&(data))>>13)
#define COMP_SER_HPOS_ser_hend_shift                                                 (0)
#define COMP_SER_HPOS_ser_hend_mask                                                  (0x00001FFF)
#define COMP_SER_HPOS_ser_hend(data)                                                 (0x00001FFF&((data)<<0))
#define COMP_SER_HPOS_ser_hend_src(data)                                             ((0x00001FFF&(data))>>0)
#define COMP_SER_HPOS_get_ser_hend(data)                                             ((0x00001FFF&(data))>>0)


#define COMP_SER_VPOS                                                                0x1801F08c
#define COMP_SER_VPOS_reg_addr                                                       "0xB800A08C"
#define COMP_SER_VPOS_reg                                                           0xB801F08C
#define set_COMP_SER_VPOS_reg(data)   (*((volatile unsigned int*) COMP_SER_VPOS_reg)=data)
#define get_COMP_SER_VPOS_reg   (*((volatile unsigned int*) COMP_SER_VPOS_reg))
#define COMP_SER_VPOS_inst_adr                                                       "0x0023"
#define COMP_SER_VPOS_inst                                                           0x0023
#define COMP_SER_VPOS_write_en2_shift                                                (11)
#define COMP_SER_VPOS_write_en2_mask                                                 (0x00000800)
#define COMP_SER_VPOS_write_en2(data)                                                (0x00000800&((data)<<11))
#define COMP_SER_VPOS_write_en2_src(data)                                            ((0x00000800&(data))>>11)
#define COMP_SER_VPOS_get_write_en2(data)                                            ((0x00000800&(data))>>11)
#define COMP_SER_VPOS_ser_vstart_shift                                               (6)
#define COMP_SER_VPOS_ser_vstart_mask                                                (0x000007C0)
#define COMP_SER_VPOS_ser_vstart(data)                                               (0x000007C0&((data)<<6))
#define COMP_SER_VPOS_ser_vstart_src(data)                                           ((0x000007C0&(data))>>6)
#define COMP_SER_VPOS_get_ser_vstart(data)                                           ((0x000007C0&(data))>>6)
#define COMP_SER_VPOS_write_en1_shift                                                (5)
#define COMP_SER_VPOS_write_en1_mask                                                 (0x00000020)
#define COMP_SER_VPOS_write_en1(data)                                                (0x00000020&((data)<<5))
#define COMP_SER_VPOS_write_en1_src(data)                                            ((0x00000020&(data))>>5)
#define COMP_SER_VPOS_get_write_en1(data)                                            ((0x00000020&(data))>>5)
#define COMP_SER_VPOS_ser_vend_shift                                                 (0)
#define COMP_SER_VPOS_ser_vend_mask                                                  (0x0000001F)
#define COMP_SER_VPOS_ser_vend(data)                                                 (0x0000001F&((data)<<0))
#define COMP_SER_VPOS_ser_vend_src(data)                                             ((0x0000001F&(data))>>0)
#define COMP_SER_VPOS_get_ser_vend(data)                                             ((0x0000001F&(data))>>0)


#define COMP_DSYNC_VPOS                                                              0x1801F090
#define COMP_DSYNC_VPOS_reg_addr                                                     "0xB800A090"
#define COMP_DSYNC_VPOS_reg                                                         0xB801F090
#define set_COMP_DSYNC_VPOS_reg(data)   (*((volatile unsigned int*) COMP_DSYNC_VPOS_reg)=data)
#define get_COMP_DSYNC_VPOS_reg   (*((volatile unsigned int*) COMP_DSYNC_VPOS_reg))
#define COMP_DSYNC_VPOS_inst_adr                                                     "0x0024"
#define COMP_DSYNC_VPOS_inst                                                         0x0024
#define COMP_DSYNC_VPOS_write_en4_shift                                              (31)
#define COMP_DSYNC_VPOS_write_en4_mask                                               (0x80000000)
#define COMP_DSYNC_VPOS_write_en4(data)                                              (0x80000000&((data)<<31))
#define COMP_DSYNC_VPOS_write_en4_src(data)                                          ((0x80000000&(data))>>31)
#define COMP_DSYNC_VPOS_get_write_en4(data)                                          ((0x80000000&(data))>>31)
#define COMP_DSYNC_VPOS_dsync_b_vstart_shift                                         (21)
#define COMP_DSYNC_VPOS_dsync_b_vstart_mask                                          (0x7FE00000)
#define COMP_DSYNC_VPOS_dsync_b_vstart(data)                                         (0x7FE00000&((data)<<21))
#define COMP_DSYNC_VPOS_dsync_b_vstart_src(data)                                     ((0x7FE00000&(data))>>21)
#define COMP_DSYNC_VPOS_get_dsync_b_vstart(data)                                     ((0x7FE00000&(data))>>21)
#define COMP_DSYNC_VPOS_write_en3_shift                                              (20)
#define COMP_DSYNC_VPOS_write_en3_mask                                               (0x00100000)
#define COMP_DSYNC_VPOS_write_en3(data)                                              (0x00100000&((data)<<20))
#define COMP_DSYNC_VPOS_write_en3_src(data)                                          ((0x00100000&(data))>>20)
#define COMP_DSYNC_VPOS_get_write_en3(data)                                          ((0x00100000&(data))>>20)
#define COMP_DSYNC_VPOS_dsync_b_vend_shift                                           (10)
#define COMP_DSYNC_VPOS_dsync_b_vend_mask                                            (0x000FFC00)
#define COMP_DSYNC_VPOS_dsync_b_vend(data)                                           (0x000FFC00&((data)<<10))
#define COMP_DSYNC_VPOS_dsync_b_vend_src(data)                                       ((0x000FFC00&(data))>>10)
#define COMP_DSYNC_VPOS_get_dsync_b_vend(data)                                       ((0x000FFC00&(data))>>10)
#define COMP_DSYNC_VPOS_write_en2_shift                                              (9)
#define COMP_DSYNC_VPOS_write_en2_mask                                               (0x00000200)
#define COMP_DSYNC_VPOS_write_en2(data)                                              (0x00000200&((data)<<9))
#define COMP_DSYNC_VPOS_write_en2_src(data)                                          ((0x00000200&(data))>>9)
#define COMP_DSYNC_VPOS_get_write_en2(data)                                          ((0x00000200&(data))>>9)
#define COMP_DSYNC_VPOS_dsync_t_vstart_shift                                         (5)
#define COMP_DSYNC_VPOS_dsync_t_vstart_mask                                          (0x000001E0)
#define COMP_DSYNC_VPOS_dsync_t_vstart(data)                                         (0x000001E0&((data)<<5))
#define COMP_DSYNC_VPOS_dsync_t_vstart_src(data)                                     ((0x000001E0&(data))>>5)
#define COMP_DSYNC_VPOS_get_dsync_t_vstart(data)                                     ((0x000001E0&(data))>>5)
#define COMP_DSYNC_VPOS_write_en1_shift                                              (4)
#define COMP_DSYNC_VPOS_write_en1_mask                                               (0x00000010)
#define COMP_DSYNC_VPOS_write_en1(data)                                              (0x00000010&((data)<<4))
#define COMP_DSYNC_VPOS_write_en1_src(data)                                          ((0x00000010&(data))>>4)
#define COMP_DSYNC_VPOS_get_write_en1(data)                                          ((0x00000010&(data))>>4)
#define COMP_DSYNC_VPOS_dsync_t_vend_shift                                           (0)
#define COMP_DSYNC_VPOS_dsync_t_vend_mask                                            (0x0000000F)
#define COMP_DSYNC_VPOS_dsync_t_vend(data)                                           (0x0000000F&((data)<<0))
#define COMP_DSYNC_VPOS_dsync_t_vend_src(data)                                       ((0x0000000F&(data))>>0)
#define COMP_DSYNC_VPOS_get_dsync_t_vend(data)                                       ((0x0000000F&(data))>>0)


#define VGA_HSYNC_HPOS                                                               0x1801F094
#define VGA_HSYNC_HPOS_reg_addr                                                      "0xB800A094"
#define VGA_HSYNC_HPOS_reg                                                          0xB801F094
#define set_VGA_HSYNC_HPOS_reg(data)   (*((volatile unsigned int*) VGA_HSYNC_HPOS_reg)=data)
#define get_VGA_HSYNC_HPOS_reg   (*((volatile unsigned int*) VGA_HSYNC_HPOS_reg))
#define VGA_HSYNC_HPOS_inst_adr                                                      "0x0025"
#define VGA_HSYNC_HPOS_inst                                                          0x0025
#define VGA_HSYNC_HPOS_write_en2_shift                                               (27)
#define VGA_HSYNC_HPOS_write_en2_mask                                                (0x08000000)
#define VGA_HSYNC_HPOS_write_en2(data)                                               (0x08000000&((data)<<27))
#define VGA_HSYNC_HPOS_write_en2_src(data)                                           ((0x08000000&(data))>>27)
#define VGA_HSYNC_HPOS_get_write_en2(data)                                           ((0x08000000&(data))>>27)
#define VGA_HSYNC_HPOS_hs_start_shift                                                (14)
#define VGA_HSYNC_HPOS_hs_start_mask                                                 (0x07FFC000)
#define VGA_HSYNC_HPOS_hs_start(data)                                                (0x07FFC000&((data)<<14))
#define VGA_HSYNC_HPOS_hs_start_src(data)                                            ((0x07FFC000&(data))>>14)
#define VGA_HSYNC_HPOS_get_hs_start(data)                                            ((0x07FFC000&(data))>>14)
#define VGA_HSYNC_HPOS_write_en1_shift                                               (13)
#define VGA_HSYNC_HPOS_write_en1_mask                                                (0x00002000)
#define VGA_HSYNC_HPOS_write_en1(data)                                               (0x00002000&((data)<<13))
#define VGA_HSYNC_HPOS_write_en1_src(data)                                           ((0x00002000&(data))>>13)
#define VGA_HSYNC_HPOS_get_write_en1(data)                                           ((0x00002000&(data))>>13)
#define VGA_HSYNC_HPOS_hs_end_shift                                                  (0)
#define VGA_HSYNC_HPOS_hs_end_mask                                                   (0x00001FFF)
#define VGA_HSYNC_HPOS_hs_end(data)                                                  (0x00001FFF&((data)<<0))
#define VGA_HSYNC_HPOS_hs_end_src(data)                                              ((0x00001FFF&(data))>>0)
#define VGA_HSYNC_HPOS_get_hs_end(data)                                              ((0x00001FFF&(data))>>0)


#define VGA_VSYNC_ST_POS_0                                                           0x1801F098
#define VGA_VSYNC_ST_POS_1                                                           0x1801F09C
#define VGA_VSYNC_ST_POS_0_reg_addr                                                  "0xB800A098"
#define VGA_VSYNC_ST_POS_1_reg_addr                                                  "0xB800A09C"
#define VGA_VSYNC_ST_POS_0_reg                                                      0xB801F098
#define VGA_VSYNC_ST_POS_1_reg                                                      0xB801F09C
#define set_VGA_VSYNC_ST_POS_0_reg(data)   (*((volatile unsigned int*) VGA_VSYNC_ST_POS_0_reg)=data)
#define set_VGA_VSYNC_ST_POS_1_reg(data)   (*((volatile unsigned int*) VGA_VSYNC_ST_POS_1_reg)=data)
#define get_VGA_VSYNC_ST_POS_0_reg   (*((volatile unsigned int*) VGA_VSYNC_ST_POS_0_reg))
#define get_VGA_VSYNC_ST_POS_1_reg   (*((volatile unsigned int*) VGA_VSYNC_ST_POS_1_reg))
#define VGA_VSYNC_ST_POS_0_inst_adr                                                  "0x0026"
#define VGA_VSYNC_ST_POS_1_inst_adr                                                  "0x0027"
#define VGA_VSYNC_ST_POS_0_inst                                                      0x0026
#define VGA_VSYNC_ST_POS_1_inst                                                      0x0027
#define VGA_VSYNC_ST_POS_write_en2_shift                                             (25)
#define VGA_VSYNC_ST_POS_write_en2_mask                                              (0x02000000)
#define VGA_VSYNC_ST_POS_write_en2(data)                                             (0x02000000&((data)<<25))
#define VGA_VSYNC_ST_POS_write_en2_src(data)                                         ((0x02000000&(data))>>25)
#define VGA_VSYNC_ST_POS_get_write_en2(data)                                         ((0x02000000&(data))>>25)
#define VGA_VSYNC_ST_POS_vs_st_posv_shift                                            (14)
#define VGA_VSYNC_ST_POS_vs_st_posv_mask                                             (0x01FFC000)
#define VGA_VSYNC_ST_POS_vs_st_posv(data)                                            (0x01FFC000&((data)<<14))
#define VGA_VSYNC_ST_POS_vs_st_posv_src(data)                                        ((0x01FFC000&(data))>>14)
#define VGA_VSYNC_ST_POS_get_vs_st_posv(data)                                        ((0x01FFC000&(data))>>14)
#define VGA_VSYNC_ST_POS_write_en1_shift                                             (13)
#define VGA_VSYNC_ST_POS_write_en1_mask                                              (0x00002000)
#define VGA_VSYNC_ST_POS_write_en1(data)                                             (0x00002000&((data)<<13))
#define VGA_VSYNC_ST_POS_write_en1_src(data)                                         ((0x00002000&(data))>>13)
#define VGA_VSYNC_ST_POS_get_write_en1(data)                                         ((0x00002000&(data))>>13)
#define VGA_VSYNC_ST_POS_vs_st_posh_shift                                            (0)
#define VGA_VSYNC_ST_POS_vs_st_posh_mask                                             (0x00001FFF)
#define VGA_VSYNC_ST_POS_vs_st_posh(data)                                            (0x00001FFF&((data)<<0))
#define VGA_VSYNC_ST_POS_vs_st_posh_src(data)                                        ((0x00001FFF&(data))>>0)
#define VGA_VSYNC_ST_POS_get_vs_st_posh(data)                                        ((0x00001FFF&(data))>>0)


#define VGA_VSYNC_END_POS_0                                                          0x1801F0A0
#define VGA_VSYNC_END_POS_1                                                          0x1801F0A4
#define VGA_VSYNC_END_POS_0_reg_addr                                                 "0xB800A0A0"
#define VGA_VSYNC_END_POS_1_reg_addr                                                 "0xB800A0A4"
#define VGA_VSYNC_END_POS_0_reg                                                     0xB801F0A0
#define VGA_VSYNC_END_POS_1_reg                                                     0xB801F0A4
#define set_VGA_VSYNC_END_POS_0_reg(data)   (*((volatile unsigned int*) VGA_VSYNC_END_POS_0_reg)=data)
#define set_VGA_VSYNC_END_POS_1_reg(data)   (*((volatile unsigned int*) VGA_VSYNC_END_POS_1_reg)=data)
#define get_VGA_VSYNC_END_POS_0_reg   (*((volatile unsigned int*) VGA_VSYNC_END_POS_0_reg))
#define get_VGA_VSYNC_END_POS_1_reg   (*((volatile unsigned int*) VGA_VSYNC_END_POS_1_reg))
#define VGA_VSYNC_END_POS_0_inst_adr                                                 "0x0028"
#define VGA_VSYNC_END_POS_1_inst_adr                                                 "0x0029"
#define VGA_VSYNC_END_POS_0_inst                                                     0x0028
#define VGA_VSYNC_END_POS_1_inst                                                     0x0029
#define VGA_VSYNC_END_POS_write_en2_shift                                            (25)
#define VGA_VSYNC_END_POS_write_en2_mask                                             (0x02000000)
#define VGA_VSYNC_END_POS_write_en2(data)                                            (0x02000000&((data)<<25))
#define VGA_VSYNC_END_POS_write_en2_src(data)                                        ((0x02000000&(data))>>25)
#define VGA_VSYNC_END_POS_get_write_en2(data)                                        ((0x02000000&(data))>>25)
#define VGA_VSYNC_END_POS_vs_end_posv_shift                                          (14)
#define VGA_VSYNC_END_POS_vs_end_posv_mask                                           (0x01FFC000)
#define VGA_VSYNC_END_POS_vs_end_posv(data)                                          (0x01FFC000&((data)<<14))
#define VGA_VSYNC_END_POS_vs_end_posv_src(data)                                      ((0x01FFC000&(data))>>14)
#define VGA_VSYNC_END_POS_get_vs_end_posv(data)                                      ((0x01FFC000&(data))>>14)
#define VGA_VSYNC_END_POS_write_en1_shift                                            (13)
#define VGA_VSYNC_END_POS_write_en1_mask                                             (0x00002000)
#define VGA_VSYNC_END_POS_write_en1(data)                                            (0x00002000&((data)<<13))
#define VGA_VSYNC_END_POS_write_en1_src(data)                                        ((0x00002000&(data))>>13)
#define VGA_VSYNC_END_POS_get_write_en1(data)                                        ((0x00002000&(data))>>13)
#define VGA_VSYNC_END_POS_vs_end_posh_shift                                          (0)
#define VGA_VSYNC_END_POS_vs_end_posh_mask                                           (0x00001FFF)
#define VGA_VSYNC_END_POS_vs_end_posh(data)                                          (0x00001FFF&((data)<<0))
#define VGA_VSYNC_END_POS_vs_end_posh_src(data)                                      ((0x00001FFF&(data))>>0)
#define VGA_VSYNC_END_POS_get_vs_end_posh(data)                                      ((0x00001FFF&(data))>>0)


#define IP_VSYNCPOS                                                                  0x1801F0b0
#define IP_VSYNCPOS_reg_addr                                                         "0xB800A0B0"
#define IP_VSYNCPOS_reg                                                             0xB801F0B0
#define set_IP_VSYNCPOS_reg(data)   (*((volatile unsigned int*) IP_VSYNCPOS_reg)=data)
#define get_IP_VSYNCPOS_reg   (*((volatile unsigned int*) IP_VSYNCPOS_reg))
#define IP_VSYNCPOS_inst_adr                                                         "0x002C"
#define IP_VSYNCPOS_inst                                                             0x002C
#define IP_VSYNCPOS_write_en2_shift                                                  (21)
#define IP_VSYNCPOS_write_en2_mask                                                   (0x00200000)
#define IP_VSYNCPOS_write_en2(data)                                                  (0x00200000&((data)<<21))
#define IP_VSYNCPOS_write_en2_src(data)                                              ((0x00200000&(data))>>21)
#define IP_VSYNCPOS_get_write_en2(data)                                              ((0x00200000&(data))>>21)
#define IP_VSYNCPOS_ip_vsync_pos1_shift                                              (11)
#define IP_VSYNCPOS_ip_vsync_pos1_mask                                               (0x001FF800)
#define IP_VSYNCPOS_ip_vsync_pos1(data)                                              (0x001FF800&((data)<<11))
#define IP_VSYNCPOS_ip_vsync_pos1_src(data)                                          ((0x001FF800&(data))>>11)
#define IP_VSYNCPOS_get_ip_vsync_pos1(data)                                          ((0x001FF800&(data))>>11)
#define IP_VSYNCPOS_write_en1_shift                                                  (10)
#define IP_VSYNCPOS_write_en1_mask                                                   (0x00000400)
#define IP_VSYNCPOS_write_en1(data)                                                  (0x00000400&((data)<<10))
#define IP_VSYNCPOS_write_en1_src(data)                                              ((0x00000400&(data))>>10)
#define IP_VSYNCPOS_get_write_en1(data)                                              ((0x00000400&(data))>>10)
#define IP_VSYNCPOS_ip_vsync_pos2_shift                                              (0)
#define IP_VSYNCPOS_ip_vsync_pos2_mask                                               (0x000003FF)
#define IP_VSYNCPOS_ip_vsync_pos2(data)                                              (0x000003FF&((data)<<0))
#define IP_VSYNCPOS_ip_vsync_pos2_src(data)                                          ((0x000003FF&(data))>>0)
#define IP_VSYNCPOS_get_ip_vsync_pos2(data)                                          ((0x000003FF&(data))>>0)


#define IP_HSYNCPOS                                                                  0x1801F0b4
#define IP_HSYNCPOS_reg_addr                                                         "0xB800A0B4"
#define IP_HSYNCPOS_reg                                                             0xB801F0B4
#define set_IP_HSYNCPOS_reg(data)   (*((volatile unsigned int*) IP_HSYNCPOS_reg)=data)
#define get_IP_HSYNCPOS_reg   (*((volatile unsigned int*) IP_HSYNCPOS_reg))
#define IP_HSYNCPOS_inst_adr                                                         "0x002D"
#define IP_HSYNCPOS_inst                                                             0x002D
#define IP_HSYNCPOS_hthr_shift                                                       (0)
#define IP_HSYNCPOS_hthr_mask                                                        (0x000007FF)
#define IP_HSYNCPOS_hthr(data)                                                       (0x000007FF&((data)<<0))
#define IP_HSYNCPOS_hthr_src(data)                                                   ((0x000007FF&(data))>>0)
#define IP_HSYNCPOS_get_hthr(data)                                                   ((0x000007FF&(data))>>0)


#define HDMI_ST                                                                      0x1801F0b8
#define HDMI_ST_reg_addr                                                             "0xB800A0B8"
#define HDMI_ST_reg                                                                 0xB801F0B8
#define set_HDMI_ST_reg(data)   (*((volatile unsigned int*) HDMI_ST_reg)=data)
#define get_HDMI_ST_reg   (*((volatile unsigned int*) HDMI_ST_reg))
#define HDMI_ST_inst_adr                                                             "0x002E"
#define HDMI_ST_inst                                                                 0x002E
#define HDMI_ST_write_en4_shift                                                      (29)
#define HDMI_ST_write_en4_mask                                                       (0x20000000)
#define HDMI_ST_write_en4(data)                                                      (0x20000000&((data)<<29))
#define HDMI_ST_write_en4_src(data)                                                  ((0x20000000&(data))>>29)
#define HDMI_ST_get_write_en4(data)                                                  ((0x20000000&(data))>>29)
#define HDMI_ST_sync_en_shift                                                        (28)
#define HDMI_ST_sync_en_mask                                                         (0x10000000)
#define HDMI_ST_sync_en(data)                                                        (0x10000000&((data)<<28))
#define HDMI_ST_sync_en_src(data)                                                    ((0x10000000&(data))>>28)
#define HDMI_ST_get_sync_en(data)                                                    ((0x10000000&(data))>>28)
#define HDMI_ST_write_en3_shift                                                      (27)
#define HDMI_ST_write_en3_mask                                                       (0x08000000)
#define HDMI_ST_write_en3(data)                                                      (0x08000000&((data)<<27))
#define HDMI_ST_write_en3_src(data)                                                  ((0x08000000&(data))>>27)
#define HDMI_ST_get_write_en3(data)                                                  ((0x08000000&(data))>>27)
#define HDMI_ST_ch_sel_shift                                                         (26)
#define HDMI_ST_ch_sel_mask                                                          (0x04000000)
#define HDMI_ST_ch_sel(data)                                                         (0x04000000&((data)<<26))
#define HDMI_ST_ch_sel_src(data)                                                     ((0x04000000&(data))>>26)
#define HDMI_ST_get_ch_sel(data)                                                     ((0x04000000&(data))>>26)
#define HDMI_ST_write_en2_shift                                                      (25)
#define HDMI_ST_write_en2_mask                                                       (0x02000000)
#define HDMI_ST_write_en2(data)                                                      (0x02000000&((data)<<25))
#define HDMI_ST_write_en2_src(data)                                                  ((0x02000000&(data))>>25)
#define HDMI_ST_get_write_en2(data)                                                  ((0x02000000&(data))>>25)
#define HDMI_ST_vpos_shift                                                           (14)
#define HDMI_ST_vpos_mask                                                            (0x01FFC000)
#define HDMI_ST_vpos(data)                                                           (0x01FFC000&((data)<<14))
#define HDMI_ST_vpos_src(data)                                                       ((0x01FFC000&(data))>>14)
#define HDMI_ST_get_vpos(data)                                                       ((0x01FFC000&(data))>>14)
#define HDMI_ST_write_en1_shift                                                      (13)
#define HDMI_ST_write_en1_mask                                                       (0x00002000)
#define HDMI_ST_write_en1(data)                                                      (0x00002000&((data)<<13))
#define HDMI_ST_write_en1_src(data)                                                  ((0x00002000&(data))>>13)
#define HDMI_ST_get_write_en1(data)                                                  ((0x00002000&(data))>>13)
#define HDMI_ST_hpos_shift                                                           (0)
#define HDMI_ST_hpos_mask                                                            (0x00001FFF)
#define HDMI_ST_hpos(data)                                                           (0x00001FFF&((data)<<0))
#define HDMI_ST_hpos_src(data)                                                       ((0x00001FFF&(data))>>0)
#define HDMI_ST_get_hpos(data)                                                       ((0x00001FFF&(data))>>0)


#define HDMI_DISP_HS                                                                 0x1801F0bc
#define HDMI_DISP_HS_reg_addr                                                        "0xB800A0BC"
#define HDMI_DISP_HS_reg                                                            0xB801F0BC
#define set_HDMI_DISP_HS_reg(data)   (*((volatile unsigned int*) HDMI_DISP_HS_reg)=data)
#define get_HDMI_DISP_HS_reg   (*((volatile unsigned int*) HDMI_DISP_HS_reg))
#define HDMI_DISP_HS_inst_adr                                                        "0x002F"
#define HDMI_DISP_HS_inst                                                            0x002F
#define HDMI_DISP_HS_write_en2_shift                                                 (27)
#define HDMI_DISP_HS_write_en2_mask                                                  (0x08000000)
#define HDMI_DISP_HS_write_en2(data)                                                 (0x08000000&((data)<<27))
#define HDMI_DISP_HS_write_en2_src(data)                                             ((0x08000000&(data))>>27)
#define HDMI_DISP_HS_get_write_en2(data)                                             ((0x08000000&(data))>>27)
#define HDMI_DISP_HS_hs_start_shift                                                  (14)
#define HDMI_DISP_HS_hs_start_mask                                                   (0x07FFC000)
#define HDMI_DISP_HS_hs_start(data)                                                  (0x07FFC000&((data)<<14))
#define HDMI_DISP_HS_hs_start_src(data)                                              ((0x07FFC000&(data))>>14)
#define HDMI_DISP_HS_get_hs_start(data)                                              ((0x07FFC000&(data))>>14)
#define HDMI_DISP_HS_write_en1_shift                                                 (13)
#define HDMI_DISP_HS_write_en1_mask                                                  (0x00002000)
#define HDMI_DISP_HS_write_en1(data)                                                 (0x00002000&((data)<<13))
#define HDMI_DISP_HS_write_en1_src(data)                                             ((0x00002000&(data))>>13)
#define HDMI_DISP_HS_get_write_en1(data)                                             ((0x00002000&(data))>>13)
#define HDMI_DISP_HS_hs_end_shift                                                    (0)
#define HDMI_DISP_HS_hs_end_mask                                                     (0x00001FFF)
#define HDMI_DISP_HS_hs_end(data)                                                    (0x00001FFF&((data)<<0))
#define HDMI_DISP_HS_hs_end_src(data)                                                ((0x00001FFF&(data))>>0)
#define HDMI_DISP_HS_get_hs_end(data)                                                ((0x00001FFF&(data))>>0)


#define HDMI_DISP_VSST1                                                              0x1801F0c0
#define HDMI_DISP_VSST1_reg_addr                                                     "0xB800A0C0"
#define HDMI_DISP_VSST1_reg                                                         0xB801F0C0
#define set_HDMI_DISP_VSST1_reg(data)   (*((volatile unsigned int*) HDMI_DISP_VSST1_reg)=data)
#define get_HDMI_DISP_VSST1_reg   (*((volatile unsigned int*) HDMI_DISP_VSST1_reg))
#define HDMI_DISP_VSST1_inst_adr                                                     "0x0030"
#define HDMI_DISP_VSST1_inst                                                         0x0030
#define HDMI_DISP_VSST1_write_en2_shift                                              (25)
#define HDMI_DISP_VSST1_write_en2_mask                                               (0x02000000)
#define HDMI_DISP_VSST1_write_en2(data)                                              (0x02000000&((data)<<25))
#define HDMI_DISP_VSST1_write_en2_src(data)                                          ((0x02000000&(data))>>25)
#define HDMI_DISP_VSST1_get_write_en2(data)                                          ((0x02000000&(data))>>25)
#define HDMI_DISP_VSST1_vs_st_pos1v_shift                                            (14)
#define HDMI_DISP_VSST1_vs_st_pos1v_mask                                             (0x01FFC000)
#define HDMI_DISP_VSST1_vs_st_pos1v(data)                                            (0x01FFC000&((data)<<14))
#define HDMI_DISP_VSST1_vs_st_pos1v_src(data)                                        ((0x01FFC000&(data))>>14)
#define HDMI_DISP_VSST1_get_vs_st_pos1v(data)                                        ((0x01FFC000&(data))>>14)
#define HDMI_DISP_VSST1_write_en1_shift                                              (13)
#define HDMI_DISP_VSST1_write_en1_mask                                               (0x00002000)
#define HDMI_DISP_VSST1_write_en1(data)                                              (0x00002000&((data)<<13))
#define HDMI_DISP_VSST1_write_en1_src(data)                                          ((0x00002000&(data))>>13)
#define HDMI_DISP_VSST1_get_write_en1(data)                                          ((0x00002000&(data))>>13)
#define HDMI_DISP_VSST1_vs_st_pos1h_shift                                            (0)
#define HDMI_DISP_VSST1_vs_st_pos1h_mask                                             (0x00001FFF)
#define HDMI_DISP_VSST1_vs_st_pos1h(data)                                            (0x00001FFF&((data)<<0))
#define HDMI_DISP_VSST1_vs_st_pos1h_src(data)                                        ((0x00001FFF&(data))>>0)
#define HDMI_DISP_VSST1_get_vs_st_pos1h(data)                                        ((0x00001FFF&(data))>>0)


#define HDMI_DISP_VSED1                                                              0x1801F0c4
#define HDMI_DISP_VSED1_reg_addr                                                     "0xB800A0C4"
#define HDMI_DISP_VSED1_reg                                                         0xB801F0C4
#define set_HDMI_DISP_VSED1_reg(data)   (*((volatile unsigned int*) HDMI_DISP_VSED1_reg)=data)
#define get_HDMI_DISP_VSED1_reg   (*((volatile unsigned int*) HDMI_DISP_VSED1_reg))
#define HDMI_DISP_VSED1_inst_adr                                                     "0x0031"
#define HDMI_DISP_VSED1_inst                                                         0x0031
#define HDMI_DISP_VSED1_write_en2_shift                                              (25)
#define HDMI_DISP_VSED1_write_en2_mask                                               (0x02000000)
#define HDMI_DISP_VSED1_write_en2(data)                                              (0x02000000&((data)<<25))
#define HDMI_DISP_VSED1_write_en2_src(data)                                          ((0x02000000&(data))>>25)
#define HDMI_DISP_VSED1_get_write_en2(data)                                          ((0x02000000&(data))>>25)
#define HDMI_DISP_VSED1_vs_end_pos1v_shift                                           (14)
#define HDMI_DISP_VSED1_vs_end_pos1v_mask                                            (0x01FFC000)
#define HDMI_DISP_VSED1_vs_end_pos1v(data)                                           (0x01FFC000&((data)<<14))
#define HDMI_DISP_VSED1_vs_end_pos1v_src(data)                                       ((0x01FFC000&(data))>>14)
#define HDMI_DISP_VSED1_get_vs_end_pos1v(data)                                       ((0x01FFC000&(data))>>14)
#define HDMI_DISP_VSED1_write_en1_shift                                              (13)
#define HDMI_DISP_VSED1_write_en1_mask                                               (0x00002000)
#define HDMI_DISP_VSED1_write_en1(data)                                              (0x00002000&((data)<<13))
#define HDMI_DISP_VSED1_write_en1_src(data)                                          ((0x00002000&(data))>>13)
#define HDMI_DISP_VSED1_get_write_en1(data)                                          ((0x00002000&(data))>>13)
#define HDMI_DISP_VSED1_vs_end_pos1h_shift                                           (0)
#define HDMI_DISP_VSED1_vs_end_pos1h_mask                                            (0x00001FFF)
#define HDMI_DISP_VSED1_vs_end_pos1h(data)                                           (0x00001FFF&((data)<<0))
#define HDMI_DISP_VSED1_vs_end_pos1h_src(data)                                       ((0x00001FFF&(data))>>0)
#define HDMI_DISP_VSED1_get_vs_end_pos1h(data)                                       ((0x00001FFF&(data))>>0)


#define HDMI_DISP_VSST2                                                              0x1801F0c8
#define HDMI_DISP_VSST2_reg_addr                                                     "0xB800A0C8"
#define HDMI_DISP_VSST2_reg                                                         0xB801F0C8
#define set_HDMI_DISP_VSST2_reg(data)   (*((volatile unsigned int*) HDMI_DISP_VSST2_reg)=data)
#define get_HDMI_DISP_VSST2_reg   (*((volatile unsigned int*) HDMI_DISP_VSST2_reg))
#define HDMI_DISP_VSST2_inst_adr                                                     "0x0032"
#define HDMI_DISP_VSST2_inst                                                         0x0032
#define HDMI_DISP_VSST2_write_en2_shift                                              (25)
#define HDMI_DISP_VSST2_write_en2_mask                                               (0x02000000)
#define HDMI_DISP_VSST2_write_en2(data)                                              (0x02000000&((data)<<25))
#define HDMI_DISP_VSST2_write_en2_src(data)                                          ((0x02000000&(data))>>25)
#define HDMI_DISP_VSST2_get_write_en2(data)                                          ((0x02000000&(data))>>25)
#define HDMI_DISP_VSST2_vs_st_pos2v_shift                                            (14)
#define HDMI_DISP_VSST2_vs_st_pos2v_mask                                             (0x01FFC000)
#define HDMI_DISP_VSST2_vs_st_pos2v(data)                                            (0x01FFC000&((data)<<14))
#define HDMI_DISP_VSST2_vs_st_pos2v_src(data)                                        ((0x01FFC000&(data))>>14)
#define HDMI_DISP_VSST2_get_vs_st_pos2v(data)                                        ((0x01FFC000&(data))>>14)
#define HDMI_DISP_VSST2_write_en1_shift                                              (13)
#define HDMI_DISP_VSST2_write_en1_mask                                               (0x00002000)
#define HDMI_DISP_VSST2_write_en1(data)                                              (0x00002000&((data)<<13))
#define HDMI_DISP_VSST2_write_en1_src(data)                                          ((0x00002000&(data))>>13)
#define HDMI_DISP_VSST2_get_write_en1(data)                                          ((0x00002000&(data))>>13)
#define HDMI_DISP_VSST2_vs_st_pos2h_shift                                            (0)
#define HDMI_DISP_VSST2_vs_st_pos2h_mask                                             (0x00001FFF)
#define HDMI_DISP_VSST2_vs_st_pos2h(data)                                            (0x00001FFF&((data)<<0))
#define HDMI_DISP_VSST2_vs_st_pos2h_src(data)                                        ((0x00001FFF&(data))>>0)
#define HDMI_DISP_VSST2_get_vs_st_pos2h(data)                                        ((0x00001FFF&(data))>>0)


#define HDMI_DISP_VSED2                                                              0x1801F0cc
#define HDMI_DISP_VSED2_reg_addr                                                     "0xB800A0CC"
#define HDMI_DISP_VSED2_reg                                                         0xB801F0CC
#define set_HDMI_DISP_VSED2_reg(data)   (*((volatile unsigned int*) HDMI_DISP_VSED2_reg)=data)
#define get_HDMI_DISP_VSED2_reg   (*((volatile unsigned int*) HDMI_DISP_VSED2_reg))
#define HDMI_DISP_VSED2_inst_adr                                                     "0x0033"
#define HDMI_DISP_VSED2_inst                                                         0x0033
#define HDMI_DISP_VSED2_write_en2_shift                                              (25)
#define HDMI_DISP_VSED2_write_en2_mask                                               (0x02000000)
#define HDMI_DISP_VSED2_write_en2(data)                                              (0x02000000&((data)<<25))
#define HDMI_DISP_VSED2_write_en2_src(data)                                          ((0x02000000&(data))>>25)
#define HDMI_DISP_VSED2_get_write_en2(data)                                          ((0x02000000&(data))>>25)
#define HDMI_DISP_VSED2_vs_end_pos2v_shift                                           (14)
#define HDMI_DISP_VSED2_vs_end_pos2v_mask                                            (0x01FFC000)
#define HDMI_DISP_VSED2_vs_end_pos2v(data)                                           (0x01FFC000&((data)<<14))
#define HDMI_DISP_VSED2_vs_end_pos2v_src(data)                                       ((0x01FFC000&(data))>>14)
#define HDMI_DISP_VSED2_get_vs_end_pos2v(data)                                       ((0x01FFC000&(data))>>14)
#define HDMI_DISP_VSED2_write_en1_shift                                              (13)
#define HDMI_DISP_VSED2_write_en1_mask                                               (0x00002000)
#define HDMI_DISP_VSED2_write_en1(data)                                              (0x00002000&((data)<<13))
#define HDMI_DISP_VSED2_write_en1_src(data)                                          ((0x00002000&(data))>>13)
#define HDMI_DISP_VSED2_get_write_en1(data)                                          ((0x00002000&(data))>>13)
#define HDMI_DISP_VSED2_vs_end_pos2h_shift                                           (0)
#define HDMI_DISP_VSED2_vs_end_pos2h_mask                                            (0x00001FFF)
#define HDMI_DISP_VSED2_vs_end_pos2h(data)                                           (0x00001FFF&((data)<<0))
#define HDMI_DISP_VSED2_vs_end_pos2h_src(data)                                       ((0x00001FFF&(data))>>0)
#define HDMI_DISP_VSED2_get_vs_end_pos2h(data)                                       ((0x00001FFF&(data))>>0)


#define HDMI_PXLACT                                                                  0x1801F0d0
#define HDMI_PXLACT_reg_addr                                                         "0xB800A0D0"
#define HDMI_PXLACT_reg                                                             0xB801F0D0
#define set_HDMI_PXLACT_reg(data)   (*((volatile unsigned int*) HDMI_PXLACT_reg)=data)
#define get_HDMI_PXLACT_reg   (*((volatile unsigned int*) HDMI_PXLACT_reg))
#define HDMI_PXLACT_inst_adr                                                         "0x0034"
#define HDMI_PXLACT_inst                                                             0x0034
#define HDMI_PXLACT_write_en2_shift                                                  (27)
#define HDMI_PXLACT_write_en2_mask                                                   (0x08000000)
#define HDMI_PXLACT_write_en2(data)                                                  (0x08000000&((data)<<27))
#define HDMI_PXLACT_write_en2_src(data)                                              ((0x08000000&(data))>>27)
#define HDMI_PXLACT_get_write_en2(data)                                              ((0x08000000&(data))>>27)
#define HDMI_PXLACT_hpos_end_shift                                                   (14)
#define HDMI_PXLACT_hpos_end_mask                                                    (0x07FFC000)
#define HDMI_PXLACT_hpos_end(data)                                                   (0x07FFC000&((data)<<14))
#define HDMI_PXLACT_hpos_end_src(data)                                               ((0x07FFC000&(data))>>14)
#define HDMI_PXLACT_get_hpos_end(data)                                               ((0x07FFC000&(data))>>14)
#define HDMI_PXLACT_write_en1_shift                                                  (13)
#define HDMI_PXLACT_write_en1_mask                                                   (0x00002000)
#define HDMI_PXLACT_write_en1(data)                                                  (0x00002000&((data)<<13))
#define HDMI_PXLACT_write_en1_src(data)                                              ((0x00002000&(data))>>13)
#define HDMI_PXLACT_get_write_en1(data)                                              ((0x00002000&(data))>>13)
#define HDMI_PXLACT_hpos_st_shift                                                    (0)
#define HDMI_PXLACT_hpos_st_mask                                                     (0x00001FFF)
#define HDMI_PXLACT_hpos_st(data)                                                    (0x00001FFF&((data)<<0))
#define HDMI_PXLACT_hpos_st_src(data)                                                ((0x00001FFF&(data))>>0)
#define HDMI_PXLACT_get_hpos_st(data)                                                ((0x00001FFF&(data))>>0)


#define COMP_SYNCLVL                                                                 0x1801F0e0
#define COMP_SYNCLVL_reg_addr                                                        "0xB800A0E0"
#define COMP_SYNCLVL_reg                                                            0xB801F0E0
#define set_COMP_SYNCLVL_reg(data)   (*((volatile unsigned int*) COMP_SYNCLVL_reg)=data)
#define get_COMP_SYNCLVL_reg   (*((volatile unsigned int*) COMP_SYNCLVL_reg))
#define COMP_SYNCLVL_inst_adr                                                        "0x0038"
#define COMP_SYNCLVL_inst                                                            0x0038
#define COMP_SYNCLVL_write_en3_shift                                                 (28)
#define COMP_SYNCLVL_write_en3_mask                                                  (0x10000000)
#define COMP_SYNCLVL_write_en3(data)                                                 (0x10000000&((data)<<28))
#define COMP_SYNCLVL_write_en3_src(data)                                             ((0x10000000&(data))>>28)
#define COMP_SYNCLVL_get_write_en3(data)                                             ((0x10000000&(data))>>28)
#define COMP_SYNCLVL_slewrate_shift                                                  (26)
#define COMP_SYNCLVL_slewrate_mask                                                   (0x0C000000)
#define COMP_SYNCLVL_slewrate(data)                                                  (0x0C000000&((data)<<26))
#define COMP_SYNCLVL_slewrate_src(data)                                              ((0x0C000000&(data))>>26)
#define COMP_SYNCLVL_get_slewrate(data)                                              ((0x0C000000&(data))>>26)
#define COMP_SYNCLVL_write_en2_shift                                                 (25)
#define COMP_SYNCLVL_write_en2_mask                                                  (0x02000000)
#define COMP_SYNCLVL_write_en2(data)                                                 (0x02000000&((data)<<25))
#define COMP_SYNCLVL_write_en2_src(data)                                             ((0x02000000&(data))>>25)
#define COMP_SYNCLVL_get_write_en2(data)                                             ((0x02000000&(data))>>25)
#define COMP_SYNCLVL_y_negsynclvl_shift                                              (13)
#define COMP_SYNCLVL_y_negsynclvl_mask                                               (0x01FFE000)
#define COMP_SYNCLVL_y_negsynclvl(data)                                              (0x01FFE000&((data)<<13))
#define COMP_SYNCLVL_y_negsynclvl_src(data)                                          ((0x01FFE000&(data))>>13)
#define COMP_SYNCLVL_get_y_negsynclvl(data)                                          ((0x01FFE000&(data))>>13)
#define COMP_SYNCLVL_write_en1_shift                                                 (12)
#define COMP_SYNCLVL_write_en1_mask                                                  (0x00001000)
#define COMP_SYNCLVL_write_en1(data)                                                 (0x00001000&((data)<<12))
#define COMP_SYNCLVL_write_en1_src(data)                                             ((0x00001000&(data))>>12)
#define COMP_SYNCLVL_get_write_en1(data)                                             ((0x00001000&(data))>>12)
#define COMP_SYNCLVL_y_possynclvl_shift                                              (0)
#define COMP_SYNCLVL_y_possynclvl_mask                                               (0x00000FFF)
#define COMP_SYNCLVL_y_possynclvl(data)                                              (0x00000FFF&((data)<<0))
#define COMP_SYNCLVL_y_possynclvl_src(data)                                          ((0x00000FFF&(data))>>0)
#define COMP_SYNCLVL_get_y_possynclvl(data)                                          ((0x00000FFF&(data))>>0)


#define COMP_SYNC_SLEWLVL                                                            0x1801F0e4
#define COMP_SYNC_SLEWLVL_reg_addr                                                   "0xB800A0E4"
#define COMP_SYNC_SLEWLVL_reg                                                       0xB801F0E4
#define set_COMP_SYNC_SLEWLVL_reg(data)   (*((volatile unsigned int*) COMP_SYNC_SLEWLVL_reg)=data)
#define get_COMP_SYNC_SLEWLVL_reg   (*((volatile unsigned int*) COMP_SYNC_SLEWLVL_reg))
#define COMP_SYNC_SLEWLVL_inst_adr                                                   "0x0039"
#define COMP_SYNC_SLEWLVL_inst                                                       0x0039
#define COMP_SYNC_SLEWLVL_write_en2_shift                                            (25)
#define COMP_SYNC_SLEWLVL_write_en2_mask                                             (0x02000000)
#define COMP_SYNC_SLEWLVL_write_en2(data)                                            (0x02000000&((data)<<25))
#define COMP_SYNC_SLEWLVL_write_en2_src(data)                                        ((0x02000000&(data))>>25)
#define COMP_SYNC_SLEWLVL_get_write_en2(data)                                        ((0x02000000&(data))>>25)
#define COMP_SYNC_SLEWLVL_y_sync_h_shift                                             (13)
#define COMP_SYNC_SLEWLVL_y_sync_h_mask                                              (0x01FFE000)
#define COMP_SYNC_SLEWLVL_y_sync_h(data)                                             (0x01FFE000&((data)<<13))
#define COMP_SYNC_SLEWLVL_y_sync_h_src(data)                                         ((0x01FFE000&(data))>>13)
#define COMP_SYNC_SLEWLVL_get_y_sync_h(data)                                         ((0x01FFE000&(data))>>13)
#define COMP_SYNC_SLEWLVL_write_en1_shift                                            (12)
#define COMP_SYNC_SLEWLVL_write_en1_mask                                             (0x00001000)
#define COMP_SYNC_SLEWLVL_write_en1(data)                                            (0x00001000&((data)<<12))
#define COMP_SYNC_SLEWLVL_write_en1_src(data)                                        ((0x00001000&(data))>>12)
#define COMP_SYNC_SLEWLVL_get_write_en1(data)                                        ((0x00001000&(data))>>12)
#define COMP_SYNC_SLEWLVL_y_sync_m_shift                                             (0)
#define COMP_SYNC_SLEWLVL_y_sync_m_mask                                              (0x00000FFF)
#define COMP_SYNC_SLEWLVL_y_sync_m(data)                                             (0x00000FFF&((data)<<0))
#define COMP_SYNC_SLEWLVL_y_sync_m_src(data)                                         ((0x00000FFF&(data))>>0)
#define COMP_SYNC_SLEWLVL_get_y_sync_m(data)                                         ((0x00000FFF&(data))>>0)


#define COMP_BP_LVL                                                                  0x1801F0e8
#define COMP_BP_LVL_reg_addr                                                         "0xB800A0E8"
#define COMP_BP_LVL_reg                                                             0xB801F0E8
#define set_COMP_BP_LVL_reg(data)   (*((volatile unsigned int*) COMP_BP_LVL_reg)=data)
#define get_COMP_BP_LVL_reg   (*((volatile unsigned int*) COMP_BP_LVL_reg))
#define COMP_BP_LVL_inst_adr                                                         "0x003A"
#define COMP_BP_LVL_inst                                                             0x003A
#define COMP_BP_LVL_write_en2_shift                                                  (25)
#define COMP_BP_LVL_write_en2_mask                                                   (0x02000000)
#define COMP_BP_LVL_write_en2(data)                                                  (0x02000000&((data)<<25))
#define COMP_BP_LVL_write_en2_src(data)                                              ((0x02000000&(data))>>25)
#define COMP_BP_LVL_get_write_en2(data)                                              ((0x02000000&(data))>>25)
#define COMP_BP_LVL_y_sync_l_shift                                                   (13)
#define COMP_BP_LVL_y_sync_l_mask                                                    (0x01FFE000)
#define COMP_BP_LVL_y_sync_l(data)                                                   (0x01FFE000&((data)<<13))
#define COMP_BP_LVL_y_sync_l_src(data)                                               ((0x01FFE000&(data))>>13)
#define COMP_BP_LVL_get_y_sync_l(data)                                               ((0x01FFE000&(data))>>13)
#define COMP_BP_LVL_write_en1_shift                                                  (12)
#define COMP_BP_LVL_write_en1_mask                                                   (0x00001000)
#define COMP_BP_LVL_write_en1(data)                                                  (0x00001000&((data)<<12))
#define COMP_BP_LVL_write_en1_src(data)                                              ((0x00001000&(data))>>12)
#define COMP_BP_LVL_get_write_en1(data)                                              ((0x00001000&(data))>>12)
#define COMP_BP_LVL_bp_lvl_shift                                                     (0)
#define COMP_BP_LVL_bp_lvl_mask                                                      (0x00000FFF)
#define COMP_BP_LVL_bp_lvl(data)                                                     (0x00000FFF&((data)<<0))
#define COMP_BP_LVL_bp_lvl_src(data)                                                 ((0x00000FFF&(data))>>0)
#define COMP_BP_LVL_get_bp_lvl(data)                                                 ((0x00000FFF&(data))>>0)


#define COMP_PBPR_SYNCLVL                                                            0x1801F0ec
#define COMP_PBPR_SYNCLVL_reg_addr                                                   "0xB800A0EC"
#define COMP_PBPR_SYNCLVL_reg                                                       0xB801F0EC
#define set_COMP_PBPR_SYNCLVL_reg(data)   (*((volatile unsigned int*) COMP_PBPR_SYNCLVL_reg)=data)
#define get_COMP_PBPR_SYNCLVL_reg   (*((volatile unsigned int*) COMP_PBPR_SYNCLVL_reg))
#define COMP_PBPR_SYNCLVL_inst_adr                                                   "0x003B"
#define COMP_PBPR_SYNCLVL_inst                                                       0x003B
#define COMP_PBPR_SYNCLVL_write_en2_shift                                            (25)
#define COMP_PBPR_SYNCLVL_write_en2_mask                                             (0x02000000)
#define COMP_PBPR_SYNCLVL_write_en2(data)                                            (0x02000000&((data)<<25))
#define COMP_PBPR_SYNCLVL_write_en2_src(data)                                        ((0x02000000&(data))>>25)
#define COMP_PBPR_SYNCLVL_get_write_en2(data)                                        ((0x02000000&(data))>>25)
#define COMP_PBPR_SYNCLVL_pbpr_negsynclvl_shift                                      (13)
#define COMP_PBPR_SYNCLVL_pbpr_negsynclvl_mask                                       (0x01FFE000)
#define COMP_PBPR_SYNCLVL_pbpr_negsynclvl(data)                                      (0x01FFE000&((data)<<13))
#define COMP_PBPR_SYNCLVL_pbpr_negsynclvl_src(data)                                  ((0x01FFE000&(data))>>13)
#define COMP_PBPR_SYNCLVL_get_pbpr_negsynclvl(data)                                  ((0x01FFE000&(data))>>13)
#define COMP_PBPR_SYNCLVL_write_en1_shift                                            (12)
#define COMP_PBPR_SYNCLVL_write_en1_mask                                             (0x00001000)
#define COMP_PBPR_SYNCLVL_write_en1(data)                                            (0x00001000&((data)<<12))
#define COMP_PBPR_SYNCLVL_write_en1_src(data)                                        ((0x00001000&(data))>>12)
#define COMP_PBPR_SYNCLVL_get_write_en1(data)                                        ((0x00001000&(data))>>12)
#define COMP_PBPR_SYNCLVL_pbpr_possynclvl_shift                                      (0)
#define COMP_PBPR_SYNCLVL_pbpr_possynclvl_mask                                       (0x00000FFF)
#define COMP_PBPR_SYNCLVL_pbpr_possynclvl(data)                                      (0x00000FFF&((data)<<0))
#define COMP_PBPR_SYNCLVL_pbpr_possynclvl_src(data)                                  ((0x00000FFF&(data))>>0)
#define COMP_PBPR_SYNCLVL_get_pbpr_possynclvl(data)                                  ((0x00000FFF&(data))>>0)


#define COMP_PBPR_BLNKLVL                                                            0x1801F0f0
#define COMP_PBPR_BLNKLVL_reg_addr                                                   "0xB800A0F0"
#define COMP_PBPR_BLNKLVL_reg                                                       0xB801F0F0
#define set_COMP_PBPR_BLNKLVL_reg(data)   (*((volatile unsigned int*) COMP_PBPR_BLNKLVL_reg)=data)
#define get_COMP_PBPR_BLNKLVL_reg   (*((volatile unsigned int*) COMP_PBPR_BLNKLVL_reg))
#define COMP_PBPR_BLNKLVL_inst_adr                                                   "0x003C"
#define COMP_PBPR_BLNKLVL_inst                                                       0x003C
#define COMP_PBPR_BLNKLVL_write_en2_shift                                            (25)
#define COMP_PBPR_BLNKLVL_write_en2_mask                                             (0x02000000)
#define COMP_PBPR_BLNKLVL_write_en2(data)                                            (0x02000000&((data)<<25))
#define COMP_PBPR_BLNKLVL_write_en2_src(data)                                        ((0x02000000&(data))>>25)
#define COMP_PBPR_BLNKLVL_get_write_en2(data)                                        ((0x02000000&(data))>>25)
#define COMP_PBPR_BLNKLVL_y_blank_lvl_shift                                          (13)
#define COMP_PBPR_BLNKLVL_y_blank_lvl_mask                                           (0x01FFE000)
#define COMP_PBPR_BLNKLVL_y_blank_lvl(data)                                          (0x01FFE000&((data)<<13))
#define COMP_PBPR_BLNKLVL_y_blank_lvl_src(data)                                      ((0x01FFE000&(data))>>13)
#define COMP_PBPR_BLNKLVL_get_y_blank_lvl(data)                                      ((0x01FFE000&(data))>>13)
#define COMP_PBPR_BLNKLVL_write_en1_shift                                            (12)
#define COMP_PBPR_BLNKLVL_write_en1_mask                                             (0x00001000)
#define COMP_PBPR_BLNKLVL_write_en1(data)                                            (0x00001000&((data)<<12))
#define COMP_PBPR_BLNKLVL_write_en1_src(data)                                        ((0x00001000&(data))>>12)
#define COMP_PBPR_BLNKLVL_get_write_en1(data)                                        ((0x00001000&(data))>>12)
#define COMP_PBPR_BLNKLVL_pbpr_blank_lvl_shift                                       (0)
#define COMP_PBPR_BLNKLVL_pbpr_blank_lvl_mask                                        (0x00000FFF)
#define COMP_PBPR_BLNKLVL_pbpr_blank_lvl(data)                                       (0x00000FFF&((data)<<0))
#define COMP_PBPR_BLNKLVL_pbpr_blank_lvl_src(data)                                   ((0x00000FFF&(data))>>0)
#define COMP_PBPR_BLNKLVL_get_pbpr_blank_lvl(data)                                   ((0x00000FFF&(data))>>0)


#define COMP_G_CLMPLVL                                                               0x1801F0f4
#define COMP_G_CLMPLVL_reg_addr                                                      "0xB800A0F4"
#define COMP_G_CLMPLVL_reg                                                          0xB801F0F4
#define set_COMP_G_CLMPLVL_reg(data)   (*((volatile unsigned int*) COMP_G_CLMPLVL_reg)=data)
#define get_COMP_G_CLMPLVL_reg   (*((volatile unsigned int*) COMP_G_CLMPLVL_reg))
#define COMP_G_CLMPLVL_inst_adr                                                      "0x003D"
#define COMP_G_CLMPLVL_inst                                                          0x003D
#define COMP_G_CLMPLVL_write_en2_shift                                               (25)
#define COMP_G_CLMPLVL_write_en2_mask                                                (0x02000000)
#define COMP_G_CLMPLVL_write_en2(data)                                               (0x02000000&((data)<<25))
#define COMP_G_CLMPLVL_write_en2_src(data)                                           ((0x02000000&(data))>>25)
#define COMP_G_CLMPLVL_get_write_en2(data)                                           ((0x02000000&(data))>>25)
#define COMP_G_CLMPLVL_g_up_shift                                                    (13)
#define COMP_G_CLMPLVL_g_up_mask                                                     (0x01FFE000)
#define COMP_G_CLMPLVL_g_up(data)                                                    (0x01FFE000&((data)<<13))
#define COMP_G_CLMPLVL_g_up_src(data)                                                ((0x01FFE000&(data))>>13)
#define COMP_G_CLMPLVL_get_g_up(data)                                                ((0x01FFE000&(data))>>13)
#define COMP_G_CLMPLVL_write_en1_shift                                               (12)
#define COMP_G_CLMPLVL_write_en1_mask                                                (0x00001000)
#define COMP_G_CLMPLVL_write_en1(data)                                               (0x00001000&((data)<<12))
#define COMP_G_CLMPLVL_write_en1_src(data)                                           ((0x00001000&(data))>>12)
#define COMP_G_CLMPLVL_get_write_en1(data)                                           ((0x00001000&(data))>>12)
#define COMP_G_CLMPLVL_g_dn_shift                                                    (0)
#define COMP_G_CLMPLVL_g_dn_mask                                                     (0x00000FFF)
#define COMP_G_CLMPLVL_g_dn(data)                                                    (0x00000FFF&((data)<<0))
#define COMP_G_CLMPLVL_g_dn_src(data)                                                ((0x00000FFF&(data))>>0)
#define COMP_G_CLMPLVL_get_g_dn(data)                                                ((0x00000FFF&(data))>>0)


#define COMP_RB_CLMPLVL                                                              0x1801F0f8
#define COMP_RB_CLMPLVL_reg_addr                                                     "0xB800A0F8"
#define COMP_RB_CLMPLVL_reg                                                         0xB801F0F8
#define set_COMP_RB_CLMPLVL_reg(data)   (*((volatile unsigned int*) COMP_RB_CLMPLVL_reg)=data)
#define get_COMP_RB_CLMPLVL_reg   (*((volatile unsigned int*) COMP_RB_CLMPLVL_reg))
#define COMP_RB_CLMPLVL_inst_adr                                                     "0x003E"
#define COMP_RB_CLMPLVL_inst                                                         0x003E
#define COMP_RB_CLMPLVL_write_en2_shift                                              (25)
#define COMP_RB_CLMPLVL_write_en2_mask                                               (0x02000000)
#define COMP_RB_CLMPLVL_write_en2(data)                                              (0x02000000&((data)<<25))
#define COMP_RB_CLMPLVL_write_en2_src(data)                                          ((0x02000000&(data))>>25)
#define COMP_RB_CLMPLVL_get_write_en2(data)                                          ((0x02000000&(data))>>25)
#define COMP_RB_CLMPLVL_rb_up_shift                                                  (13)
#define COMP_RB_CLMPLVL_rb_up_mask                                                   (0x01FFE000)
#define COMP_RB_CLMPLVL_rb_up(data)                                                  (0x01FFE000&((data)<<13))
#define COMP_RB_CLMPLVL_rb_up_src(data)                                              ((0x01FFE000&(data))>>13)
#define COMP_RB_CLMPLVL_get_rb_up(data)                                              ((0x01FFE000&(data))>>13)
#define COMP_RB_CLMPLVL_write_en1_shift                                              (12)
#define COMP_RB_CLMPLVL_write_en1_mask                                               (0x00001000)
#define COMP_RB_CLMPLVL_write_en1(data)                                              (0x00001000&((data)<<12))
#define COMP_RB_CLMPLVL_write_en1_src(data)                                          ((0x00001000&(data))>>12)
#define COMP_RB_CLMPLVL_get_write_en1(data)                                          ((0x00001000&(data))>>12)
#define COMP_RB_CLMPLVL_rb_dn_shift                                                  (0)
#define COMP_RB_CLMPLVL_rb_dn_mask                                                   (0x00000FFF)
#define COMP_RB_CLMPLVL_rb_dn(data)                                                  (0x00000FFF&((data)<<0))
#define COMP_RB_CLMPLVL_rb_dn_src(data)                                              ((0x00000FFF&(data))>>0)
#define COMP_RB_CLMPLVL_get_rb_dn(data)                                              ((0x00000FFF&(data))>>0)


#define IP_INPUT                                                                     0x1801F220
#define IP_INPUT_reg_addr                                                            "0xB800A220"
#define IP_INPUT_reg                                                                0xB801F220
#define set_IP_INPUT_reg(data)   (*((volatile unsigned int*) IP_INPUT_reg)=data)
#define get_IP_INPUT_reg   (*((volatile unsigned int*) IP_INPUT_reg))
#define IP_INPUT_inst_adr                                                            "0x0088"
#define IP_INPUT_inst                                                                0x0088
#define IP_INPUT_y_black_lvl_shift                                                   (0)
#define IP_INPUT_y_black_lvl_mask                                                    (0x000000FF)
#define IP_INPUT_y_black_lvl(data)                                                   (0x000000FF&((data)<<0))
#define IP_INPUT_y_black_lvl_src(data)                                               ((0x000000FF&(data))>>0)
#define IP_INPUT_get_y_black_lvl(data)                                               ((0x000000FF&(data))>>0)


#define VBI_COEFF                                                                    0x1801F100
#define VBI_COEFF_reg_addr                                                           "0xB800A100"
#define VBI_COEFF_reg                                                               0xB801F100
#define set_VBI_COEFF_reg(data)   (*((volatile unsigned int*) VBI_COEFF_reg)=data)
#define get_VBI_COEFF_reg   (*((volatile unsigned int*) VBI_COEFF_reg))
#define VBI_COEFF_inst_adr                                                           "0x0040"
#define VBI_COEFF_inst                                                               0x0040
#define VBI_COEFF_write_en2_shift                                                    (31)
#define VBI_COEFF_write_en2_mask                                                     (0x80000000)
#define VBI_COEFF_write_en2(data)                                                    (0x80000000&((data)<<31))
#define VBI_COEFF_write_en2_src(data)                                                ((0x80000000&(data))>>31)
#define VBI_COEFF_get_write_en2(data)                                                ((0x80000000&(data))>>31)
#define VBI_COEFF_gain_shift                                                         (16)
#define VBI_COEFF_gain_mask                                                          (0x7FFF0000)
#define VBI_COEFF_gain(data)                                                         (0x7FFF0000&((data)<<16))
#define VBI_COEFF_gain_src(data)                                                     ((0x7FFF0000&(data))>>16)
#define VBI_COEFF_get_gain(data)                                                     ((0x7FFF0000&(data))>>16)
#define VBI_COEFF_write_en1_shift                                                    (15)
#define VBI_COEFF_write_en1_mask                                                     (0x00008000)
#define VBI_COEFF_write_en1(data)                                                    (0x00008000&((data)<<15))
#define VBI_COEFF_write_en1_src(data)                                                ((0x00008000&(data))>>15)
#define VBI_COEFF_get_write_en1(data)                                                ((0x00008000&(data))>>15)
#define VBI_COEFF_offset_shift                                                       (0)
#define VBI_COEFF_offset_mask                                                        (0x00007FFF)
#define VBI_COEFF_offset(data)                                                       (0x00007FFF&((data)<<0))
#define VBI_COEFF_offset_src(data)                                                   ((0x00007FFF&(data))>>0)
#define VBI_COEFF_get_offset(data)                                                   ((0x00007FFF&(data))>>0)


#define BLNK_COEFF                                                                   0x1801F104
#define BLNK_COEFF_reg_addr                                                          "0xB800A104"
#define BLNK_COEFF_reg                                                              0xB801F104
#define set_BLNK_COEFF_reg(data)   (*((volatile unsigned int*) BLNK_COEFF_reg)=data)
#define get_BLNK_COEFF_reg   (*((volatile unsigned int*) BLNK_COEFF_reg))
#define BLNK_COEFF_inst_adr                                                          "0x0041"
#define BLNK_COEFF_inst                                                              0x0041
#define BLNK_COEFF_write_en2_shift                                                   (31)
#define BLNK_COEFF_write_en2_mask                                                    (0x80000000)
#define BLNK_COEFF_write_en2(data)                                                   (0x80000000&((data)<<31))
#define BLNK_COEFF_write_en2_src(data)                                               ((0x80000000&(data))>>31)
#define BLNK_COEFF_get_write_en2(data)                                               ((0x80000000&(data))>>31)
#define BLNK_COEFF_gain_shift                                                        (16)
#define BLNK_COEFF_gain_mask                                                         (0x7FFF0000)
#define BLNK_COEFF_gain(data)                                                        (0x7FFF0000&((data)<<16))
#define BLNK_COEFF_gain_src(data)                                                    ((0x7FFF0000&(data))>>16)
#define BLNK_COEFF_get_gain(data)                                                    ((0x7FFF0000&(data))>>16)
#define BLNK_COEFF_write_en1_shift                                                   (15)
#define BLNK_COEFF_write_en1_mask                                                    (0x00008000)
#define BLNK_COEFF_write_en1(data)                                                   (0x00008000&((data)<<15))
#define BLNK_COEFF_write_en1_src(data)                                               ((0x00008000&(data))>>15)
#define BLNK_COEFF_get_write_en1(data)                                               ((0x00008000&(data))>>15)
#define BLNK_COEFF_offset_shift                                                      (0)
#define BLNK_COEFF_offset_mask                                                       (0x00007FFF)
#define BLNK_COEFF_offset(data)                                                      (0x00007FFF&((data)<<0))
#define BLNK_COEFF_offset_src(data)                                                  ((0x00007FFF&(data))>>0)
#define BLNK_COEFF_get_offset(data)                                                  ((0x00007FFF&(data))>>0)


#define AV_COEFF1                                                                    0x1801F108
#define AV_COEFF1_reg_addr                                                           "0xB800A108"
#define AV_COEFF1_reg                                                               0xB801F108
#define set_AV_COEFF1_reg(data)   (*((volatile unsigned int*) AV_COEFF1_reg)=data)
#define get_AV_COEFF1_reg   (*((volatile unsigned int*) AV_COEFF1_reg))
#define AV_COEFF1_inst_adr                                                           "0x0042"
#define AV_COEFF1_inst                                                               0x0042
#define AV_COEFF1_write_en2_shift                                                    (31)
#define AV_COEFF1_write_en2_mask                                                     (0x80000000)
#define AV_COEFF1_write_en2(data)                                                    (0x80000000&((data)<<31))
#define AV_COEFF1_write_en2_src(data)                                                ((0x80000000&(data))>>31)
#define AV_COEFF1_get_write_en2(data)                                                ((0x80000000&(data))>>31)
#define AV_COEFF1_c2_shift                                                           (16)
#define AV_COEFF1_c2_mask                                                            (0x7FFF0000)
#define AV_COEFF1_c2(data)                                                           (0x7FFF0000&((data)<<16))
#define AV_COEFF1_c2_src(data)                                                       ((0x7FFF0000&(data))>>16)
#define AV_COEFF1_get_c2(data)                                                       ((0x7FFF0000&(data))>>16)
#define AV_COEFF1_write_en1_shift                                                    (15)
#define AV_COEFF1_write_en1_mask                                                     (0x00008000)
#define AV_COEFF1_write_en1(data)                                                    (0x00008000&((data)<<15))
#define AV_COEFF1_write_en1_src(data)                                                ((0x00008000&(data))>>15)
#define AV_COEFF1_get_write_en1(data)                                                ((0x00008000&(data))>>15)
#define AV_COEFF1_c1_shift                                                           (0)
#define AV_COEFF1_c1_mask                                                            (0x00007FFF)
#define AV_COEFF1_c1(data)                                                           (0x00007FFF&((data)<<0))
#define AV_COEFF1_c1_src(data)                                                       ((0x00007FFF&(data))>>0)
#define AV_COEFF1_get_c1(data)                                                       ((0x00007FFF&(data))>>0)


#define AV_COEFF2                                                                    0x1801F10c
#define AV_COEFF2_reg_addr                                                           "0xB800A10C"
#define AV_COEFF2_reg                                                               0xB801F10C
#define set_AV_COEFF2_reg(data)   (*((volatile unsigned int*) AV_COEFF2_reg)=data)
#define get_AV_COEFF2_reg   (*((volatile unsigned int*) AV_COEFF2_reg))
#define AV_COEFF2_inst_adr                                                           "0x0043"
#define AV_COEFF2_inst                                                               0x0043
#define AV_COEFF2_write_en2_shift                                                    (31)
#define AV_COEFF2_write_en2_mask                                                     (0x80000000)
#define AV_COEFF2_write_en2(data)                                                    (0x80000000&((data)<<31))
#define AV_COEFF2_write_en2_src(data)                                                ((0x80000000&(data))>>31)
#define AV_COEFF2_get_write_en2(data)                                                ((0x80000000&(data))>>31)
#define AV_COEFF2_c3_shift                                                           (16)
#define AV_COEFF2_c3_mask                                                            (0x7FFF0000)
#define AV_COEFF2_c3(data)                                                           (0x7FFF0000&((data)<<16))
#define AV_COEFF2_c3_src(data)                                                       ((0x7FFF0000&(data))>>16)
#define AV_COEFF2_get_c3(data)                                                       ((0x7FFF0000&(data))>>16)
#define AV_COEFF2_write_en1_shift                                                    (15)
#define AV_COEFF2_write_en1_mask                                                     (0x00008000)
#define AV_COEFF2_write_en1(data)                                                    (0x00008000&((data)<<15))
#define AV_COEFF2_write_en1_src(data)                                                ((0x00008000&(data))>>15)
#define AV_COEFF2_get_write_en1(data)                                                ((0x00008000&(data))>>15)
#define AV_COEFF2_c4_shift                                                           (0)
#define AV_COEFF2_c4_mask                                                            (0x00007FFF)
#define AV_COEFF2_c4(data)                                                           (0x00007FFF&((data)<<0))
#define AV_COEFF2_c4_src(data)                                                       ((0x00007FFF&(data))>>0)
#define AV_COEFF2_get_c4(data)                                                       ((0x00007FFF&(data))>>0)


#define AV_COEFF3                                                                    0x1801F110
#define AV_COEFF3_reg_addr                                                           "0xB800A110"
#define AV_COEFF3_reg                                                               0xB801F110
#define set_AV_COEFF3_reg(data)   (*((volatile unsigned int*) AV_COEFF3_reg)=data)
#define get_AV_COEFF3_reg   (*((volatile unsigned int*) AV_COEFF3_reg))
#define AV_COEFF3_inst_adr                                                           "0x0044"
#define AV_COEFF3_inst                                                               0x0044
#define AV_COEFF3_write_en2_shift                                                    (31)
#define AV_COEFF3_write_en2_mask                                                     (0x80000000)
#define AV_COEFF3_write_en2(data)                                                    (0x80000000&((data)<<31))
#define AV_COEFF3_write_en2_src(data)                                                ((0x80000000&(data))>>31)
#define AV_COEFF3_get_write_en2(data)                                                ((0x80000000&(data))>>31)
#define AV_COEFF3_c5_shift                                                           (16)
#define AV_COEFF3_c5_mask                                                            (0x7FFF0000)
#define AV_COEFF3_c5(data)                                                           (0x7FFF0000&((data)<<16))
#define AV_COEFF3_c5_src(data)                                                       ((0x7FFF0000&(data))>>16)
#define AV_COEFF3_get_c5(data)                                                       ((0x7FFF0000&(data))>>16)
#define AV_COEFF3_write_en1_shift                                                    (15)
#define AV_COEFF3_write_en1_mask                                                     (0x00008000)
#define AV_COEFF3_write_en1(data)                                                    (0x00008000&((data)<<15))
#define AV_COEFF3_write_en1_src(data)                                                ((0x00008000&(data))>>15)
#define AV_COEFF3_get_write_en1(data)                                                ((0x00008000&(data))>>15)
#define AV_COEFF3_c6_shift                                                           (0)
#define AV_COEFF3_c6_mask                                                            (0x00007FFF)
#define AV_COEFF3_c6(data)                                                           (0x00007FFF&((data)<<0))
#define AV_COEFF3_c6_src(data)                                                       ((0x00007FFF&(data))>>0)
#define AV_COEFF3_get_c6(data)                                                       ((0x00007FFF&(data))>>0)


#define AV_COEFF4                                                                    0x1801F114
#define AV_COEFF4_reg_addr                                                           "0xB800A114"
#define AV_COEFF4_reg                                                               0xB801F114
#define set_AV_COEFF4_reg(data)   (*((volatile unsigned int*) AV_COEFF4_reg)=data)
#define get_AV_COEFF4_reg   (*((volatile unsigned int*) AV_COEFF4_reg))
#define AV_COEFF4_inst_adr                                                           "0x0045"
#define AV_COEFF4_inst                                                               0x0045
#define AV_COEFF4_write_en2_shift                                                    (31)
#define AV_COEFF4_write_en2_mask                                                     (0x80000000)
#define AV_COEFF4_write_en2(data)                                                    (0x80000000&((data)<<31))
#define AV_COEFF4_write_en2_src(data)                                                ((0x80000000&(data))>>31)
#define AV_COEFF4_get_write_en2(data)                                                ((0x80000000&(data))>>31)
#define AV_COEFF4_k1_shift                                                           (16)
#define AV_COEFF4_k1_mask                                                            (0x7FFF0000)
#define AV_COEFF4_k1(data)                                                           (0x7FFF0000&((data)<<16))
#define AV_COEFF4_k1_src(data)                                                       ((0x7FFF0000&(data))>>16)
#define AV_COEFF4_get_k1(data)                                                       ((0x7FFF0000&(data))>>16)
#define AV_COEFF4_write_en1_shift                                                    (15)
#define AV_COEFF4_write_en1_mask                                                     (0x00008000)
#define AV_COEFF4_write_en1(data)                                                    (0x00008000&((data)<<15))
#define AV_COEFF4_write_en1_src(data)                                                ((0x00008000&(data))>>15)
#define AV_COEFF4_get_write_en1(data)                                                ((0x00008000&(data))>>15)
#define AV_COEFF4_k2_shift                                                           (0)
#define AV_COEFF4_k2_mask                                                            (0x00007FFF)
#define AV_COEFF4_k2(data)                                                           (0x00007FFF&((data)<<0))
#define AV_COEFF4_k2_src(data)                                                       ((0x00007FFF&(data))>>0)
#define AV_COEFF4_get_k2(data)                                                       ((0x00007FFF&(data))>>0)


#define AV_COEFF5                                                                    0x1801F118
#define AV_COEFF5_reg_addr                                                           "0xB800A118"
#define AV_COEFF5_reg                                                               0xB801F118
#define set_AV_COEFF5_reg(data)   (*((volatile unsigned int*) AV_COEFF5_reg)=data)
#define get_AV_COEFF5_reg   (*((volatile unsigned int*) AV_COEFF5_reg))
#define AV_COEFF5_inst_adr                                                           "0x0046"
#define AV_COEFF5_inst                                                               0x0046
#define AV_COEFF5_write_en1_shift                                                    (17)
#define AV_COEFF5_write_en1_mask                                                     (0x00020000)
#define AV_COEFF5_write_en1(data)                                                    (0x00020000&((data)<<17))
#define AV_COEFF5_write_en1_src(data)                                                ((0x00020000&(data))>>17)
#define AV_COEFF5_get_write_en1(data)                                                ((0x00020000&(data))>>17)
#define AV_COEFF5_vbi_gain_ebl_shift                                                 (16)
#define AV_COEFF5_vbi_gain_ebl_mask                                                  (0x00010000)
#define AV_COEFF5_vbi_gain_ebl(data)                                                 (0x00010000&((data)<<16))
#define AV_COEFF5_vbi_gain_ebl_src(data)                                             ((0x00010000&(data))>>16)
#define AV_COEFF5_get_vbi_gain_ebl(data)                                             ((0x00010000&(data))>>16)
#define AV_COEFF5_write_en2_shift                                                    (15)
#define AV_COEFF5_write_en2_mask                                                     (0x00008000)
#define AV_COEFF5_write_en2(data)                                                    (0x00008000&((data)<<15))
#define AV_COEFF5_write_en2_src(data)                                                ((0x00008000&(data))>>15)
#define AV_COEFF5_get_write_en2(data)                                                ((0x00008000&(data))>>15)
#define AV_COEFF5_k3_shift                                                           (0)
#define AV_COEFF5_k3_mask                                                            (0x00007FFF)
#define AV_COEFF5_k3(data)                                                           (0x00007FFF&((data)<<0))
#define AV_COEFF5_k3_src(data)                                                       ((0x00007FFF&(data))>>0)
#define AV_COEFF5_get_k3(data)                                                       ((0x00007FFF&(data))>>0)


#define MV_CTRL                                                                      0x1801F130
#define MV_CTRL_reg_addr                                                             "0xB800A130"
#define MV_CTRL_reg                                                                 0xB801F130
#define set_MV_CTRL_reg(data)   (*((volatile unsigned int*) MV_CTRL_reg)=data)
#define get_MV_CTRL_reg   (*((volatile unsigned int*) MV_CTRL_reg))
#define MV_CTRL_inst_adr                                                             "0x004C"
#define MV_CTRL_inst                                                                 0x004C
#define MV_CTRL_mv_rb_ebl_shift                                                      (3)
#define MV_CTRL_mv_rb_ebl_mask                                                       (0x00000008)
#define MV_CTRL_mv_rb_ebl(data)                                                      (0x00000008&((data)<<3))
#define MV_CTRL_mv_rb_ebl_src(data)                                                  ((0x00000008&(data))>>3)
#define MV_CTRL_get_mv_rb_ebl(data)                                                  ((0x00000008&(data))>>3)
#define MV_CTRL_mv_g_ebl_shift                                                       (2)
#define MV_CTRL_mv_g_ebl_mask                                                        (0x00000004)
#define MV_CTRL_mv_g_ebl(data)                                                       (0x00000004&((data)<<2))
#define MV_CTRL_mv_g_ebl_src(data)                                                   ((0x00000004&(data))>>2)
#define MV_CTRL_get_mv_g_ebl(data)                                                   ((0x00000004&(data))>>2)
#define MV_CTRL_mv_ebl_shift                                                         (1)
#define MV_CTRL_mv_ebl_mask                                                          (0x00000002)
#define MV_CTRL_mv_ebl(data)                                                         (0x00000002&((data)<<1))
#define MV_CTRL_mv_ebl_src(data)                                                     ((0x00000002&(data))>>1)
#define MV_CTRL_get_mv_ebl(data)                                                     ((0x00000002&(data))>>1)
#define MV_CTRL_write_data_shift                                                     (0)
#define MV_CTRL_write_data_mask                                                      (0x00000001)
#define MV_CTRL_write_data(data)                                                     (0x00000001&((data)<<0))
#define MV_CTRL_write_data_src(data)                                                 ((0x00000001&(data))>>0)
#define MV_CTRL_get_write_data(data)                                                 ((0x00000001&(data))>>0)


#define MV_VPOS                                                                      0x1801F134
#define MV_VPOS_reg_addr                                                             "0xB800A134"
#define MV_VPOS_reg                                                                 0xB801F134
#define set_MV_VPOS_reg(data)   (*((volatile unsigned int*) MV_VPOS_reg)=data)
#define get_MV_VPOS_reg   (*((volatile unsigned int*) MV_VPOS_reg))
#define MV_VPOS_inst_adr                                                             "0x004D"
#define MV_VPOS_inst                                                                 0x004D
#define MV_VPOS_write_en2_shift                                                      (13)
#define MV_VPOS_write_en2_mask                                                       (0x00002000)
#define MV_VPOS_write_en2(data)                                                      (0x00002000&((data)<<13))
#define MV_VPOS_write_en2_src(data)                                                  ((0x00002000&(data))>>13)
#define MV_VPOS_get_write_en2(data)                                                  ((0x00002000&(data))>>13)
#define MV_VPOS_mv_end_line_shift                                                    (7)
#define MV_VPOS_mv_end_line_mask                                                     (0x00001F80)
#define MV_VPOS_mv_end_line(data)                                                    (0x00001F80&((data)<<7))
#define MV_VPOS_mv_end_line_src(data)                                                ((0x00001F80&(data))>>7)
#define MV_VPOS_get_mv_end_line(data)                                                ((0x00001F80&(data))>>7)
#define MV_VPOS_write_en1_shift                                                      (6)
#define MV_VPOS_write_en1_mask                                                       (0x00000040)
#define MV_VPOS_write_en1(data)                                                      (0x00000040&((data)<<6))
#define MV_VPOS_write_en1_src(data)                                                  ((0x00000040&(data))>>6)
#define MV_VPOS_get_write_en1(data)                                                  ((0x00000040&(data))>>6)
#define MV_VPOS_mv_st_line_shift                                                     (0)
#define MV_VPOS_mv_st_line_mask                                                      (0x0000003F)
#define MV_VPOS_mv_st_line(data)                                                     (0x0000003F&((data)<<0))
#define MV_VPOS_mv_st_line_src(data)                                                 ((0x0000003F&(data))>>0)
#define MV_VPOS_get_mv_st_line(data)                                                 ((0x0000003F&(data))>>0)


#define MV_LEN                                                                       0x1801F138
#define MV_LEN_reg_addr                                                              "0xB800A138"
#define MV_LEN_reg                                                                  0xB801F138
#define set_MV_LEN_reg(data)   (*((volatile unsigned int*) MV_LEN_reg)=data)
#define get_MV_LEN_reg   (*((volatile unsigned int*) MV_LEN_reg))
#define MV_LEN_inst_adr                                                              "0x004E"
#define MV_LEN_inst                                                                  0x004E
#define MV_LEN_write_en4_shift                                                       (29)
#define MV_LEN_write_en4_mask                                                        (0x20000000)
#define MV_LEN_write_en4(data)                                                       (0x20000000&((data)<<29))
#define MV_LEN_write_en4_src(data)                                                   ((0x20000000&(data))>>29)
#define MV_LEN_get_write_en4(data)                                                   ((0x20000000&(data))>>29)
#define MV_LEN_mv_st_ps_shift                                                        (21)
#define MV_LEN_mv_st_ps_mask                                                         (0x1FE00000)
#define MV_LEN_mv_st_ps(data)                                                        (0x1FE00000&((data)<<21))
#define MV_LEN_mv_st_ps_src(data)                                                    ((0x1FE00000&(data))>>21)
#define MV_LEN_get_mv_st_ps(data)                                                    ((0x1FE00000&(data))>>21)
#define MV_LEN_write_en3_shift                                                       (20)
#define MV_LEN_write_en3_mask                                                        (0x00100000)
#define MV_LEN_write_en3(data)                                                       (0x00100000&((data)<<20))
#define MV_LEN_write_en3_src(data)                                                   ((0x00100000&(data))>>20)
#define MV_LEN_get_write_en3(data)                                                   ((0x00100000&(data))>>20)
#define MV_LEN_mv_ps_len_shift                                                       (14)
#define MV_LEN_mv_ps_len_mask                                                        (0x000FC000)
#define MV_LEN_mv_ps_len(data)                                                       (0x000FC000&((data)<<14))
#define MV_LEN_mv_ps_len_src(data)                                                   ((0x000FC000&(data))>>14)
#define MV_LEN_get_mv_ps_len(data)                                                   ((0x000FC000&(data))>>14)
#define MV_LEN_write_en2_shift                                                       (13)
#define MV_LEN_write_en2_mask                                                        (0x00002000)
#define MV_LEN_write_en2(data)                                                       (0x00002000&((data)<<13))
#define MV_LEN_write_en2_src(data)                                                   ((0x00002000&(data))>>13)
#define MV_LEN_get_write_en2(data)                                                   ((0x00002000&(data))>>13)
#define MV_LEN_mv_agc_len_shift                                                      (7)
#define MV_LEN_mv_agc_len_mask                                                       (0x00001F80)
#define MV_LEN_mv_agc_len(data)                                                      (0x00001F80&((data)<<7))
#define MV_LEN_mv_agc_len_src(data)                                                  ((0x00001F80&(data))>>7)
#define MV_LEN_get_mv_agc_len(data)                                                  ((0x00001F80&(data))>>7)
#define MV_LEN_write_en1_shift                                                       (6)
#define MV_LEN_write_en1_mask                                                        (0x00000040)
#define MV_LEN_write_en1(data)                                                       (0x00000040&((data)<<6))
#define MV_LEN_write_en1_src(data)                                                   ((0x00000040&(data))>>6)
#define MV_LEN_get_write_en1(data)                                                   ((0x00000040&(data))>>6)
#define MV_LEN_mv_blnk_len_shift                                                     (0)
#define MV_LEN_mv_blnk_len_mask                                                      (0x0000003F)
#define MV_LEN_mv_blnk_len(data)                                                     (0x0000003F&((data)<<0))
#define MV_LEN_mv_blnk_len_src(data)                                                 ((0x0000003F&(data))>>0)
#define MV_LEN_get_mv_blnk_len(data)                                                 ((0x0000003F&(data))>>0)


#define MV_RD                                                                        0x1801F13c
#define MV_RD_reg_addr                                                               "0xB800A13C"
#define MV_RD_reg                                                                   0xB801F13C
#define set_MV_RD_reg(data)   (*((volatile unsigned int*) MV_RD_reg)=data)
#define get_MV_RD_reg   (*((volatile unsigned int*) MV_RD_reg))
#define MV_RD_inst_adr                                                               "0x004F"
#define MV_RD_inst                                                                   0x004F
#define MV_RD_mv_rd_shift                                                            (0)
#define MV_RD_mv_rd_mask                                                             (0x000FFFFF)
#define MV_RD_mv_rd(data)                                                            (0x000FFFFF&((data)<<0))
#define MV_RD_mv_rd_src(data)                                                        ((0x000FFFFF&(data))>>0)
#define MV_RD_get_mv_rd(data)                                                        ((0x000FFFFF&(data))>>0)


#define MV_DN                                                                        0x1801F140
#define MV_DN_reg_addr                                                               "0xB800A140"
#define MV_DN_reg                                                                   0xB801F140
#define set_MV_DN_reg(data)   (*((volatile unsigned int*) MV_DN_reg)=data)
#define get_MV_DN_reg   (*((volatile unsigned int*) MV_DN_reg))
#define MV_DN_inst_adr                                                               "0x0050"
#define MV_DN_inst                                                                   0x0050
#define MV_DN_mv_dn_shift                                                            (0)
#define MV_DN_mv_dn_mask                                                             (0x000FFFFF)
#define MV_DN_mv_dn(data)                                                            (0x000FFFFF&((data)<<0))
#define MV_DN_mv_dn_src(data)                                                        ((0x000FFFFF&(data))>>0)
#define MV_DN_get_mv_dn(data)                                                        ((0x000FFFFF&(data))>>0)


#define MV_RU                                                                        0x1801F144
#define MV_RU_reg_addr                                                               "0xB800A144"
#define MV_RU_reg                                                                   0xB801F144
#define set_MV_RU_reg(data)   (*((volatile unsigned int*) MV_RU_reg)=data)
#define get_MV_RU_reg   (*((volatile unsigned int*) MV_RU_reg))
#define MV_RU_inst_adr                                                               "0x0051"
#define MV_RU_inst                                                                   0x0051
#define MV_RU_mv_ru_shift                                                            (0)
#define MV_RU_mv_ru_mask                                                             (0x000FFFFF)
#define MV_RU_mv_ru(data)                                                            (0x000FFFFF&((data)<<0))
#define MV_RU_mv_ru_src(data)                                                        ((0x000FFFFF&(data))>>0)
#define MV_RU_get_mv_ru(data)                                                        ((0x000FFFFF&(data))>>0)


#define MV_UP                                                                        0x1801F148
#define MV_UP_reg_addr                                                               "0xB800A148"
#define MV_UP_reg                                                                   0xB801F148
#define set_MV_UP_reg(data)   (*((volatile unsigned int*) MV_UP_reg)=data)
#define get_MV_UP_reg   (*((volatile unsigned int*) MV_UP_reg))
#define MV_UP_inst_adr                                                               "0x0052"
#define MV_UP_inst                                                                   0x0052
#define MV_UP_mv_up_shift                                                            (0)
#define MV_UP_mv_up_mask                                                             (0x000FFFFF)
#define MV_UP_mv_up(data)                                                            (0x000FFFFF&((data)<<0))
#define MV_UP_mv_up_src(data)                                                        ((0x000FFFFF&(data))>>0)
#define MV_UP_get_mv_up(data)                                                        ((0x000FFFFF&(data))>>0)


#define MV_LVL                                                                       0x1801F14c
#define MV_LVL_reg_addr                                                              "0xB800A14C"
#define MV_LVL_reg                                                                  0xB801F14C
#define set_MV_LVL_reg(data)   (*((volatile unsigned int*) MV_LVL_reg)=data)
#define get_MV_LVL_reg   (*((volatile unsigned int*) MV_LVL_reg))
#define MV_LVL_inst_adr                                                              "0x0053"
#define MV_LVL_inst                                                                  0x0053
#define MV_LVL_write_en3_shift                                                       (30)
#define MV_LVL_write_en3_mask                                                        (0x40000000)
#define MV_LVL_write_en3(data)                                                       (0x40000000&((data)<<30))
#define MV_LVL_write_en3_src(data)                                                   ((0x40000000&(data))>>30)
#define MV_LVL_get_write_en3(data)                                                   ((0x40000000&(data))>>30)
#define MV_LVL_mv_ru_dlt_shift                                                       (22)
#define MV_LVL_mv_ru_dlt_mask                                                        (0x3FC00000)
#define MV_LVL_mv_ru_dlt(data)                                                       (0x3FC00000&((data)<<22))
#define MV_LVL_mv_ru_dlt_src(data)                                                   ((0x3FC00000&(data))>>22)
#define MV_LVL_get_mv_ru_dlt(data)                                                   ((0x3FC00000&(data))>>22)
#define MV_LVL_write_en2_shift                                                       (21)
#define MV_LVL_write_en2_mask                                                        (0x00200000)
#define MV_LVL_write_en2(data)                                                       (0x00200000&((data)<<21))
#define MV_LVL_write_en2_src(data)                                                   ((0x00200000&(data))>>21)
#define MV_LVL_get_write_en2(data)                                                   ((0x00200000&(data))>>21)
#define MV_LVL_mv_rd_dlt_shift                                                       (13)
#define MV_LVL_mv_rd_dlt_mask                                                        (0x001FE000)
#define MV_LVL_mv_rd_dlt(data)                                                       (0x001FE000&((data)<<13))
#define MV_LVL_mv_rd_dlt_src(data)                                                   ((0x001FE000&(data))>>13)
#define MV_LVL_get_mv_rd_dlt(data)                                                   ((0x001FE000&(data))>>13)
#define MV_LVL_write_en1_shift                                                       (12)
#define MV_LVL_write_en1_mask                                                        (0x00001000)
#define MV_LVL_write_en1(data)                                                       (0x00001000&((data)<<12))
#define MV_LVL_write_en1_src(data)                                                   ((0x00001000&(data))>>12)
#define MV_LVL_get_write_en1(data)                                                   ((0x00001000&(data))>>12)
#define MV_LVL_mv_stn_shift                                                          (0)
#define MV_LVL_mv_stn_mask                                                           (0x00000FFF)
#define MV_LVL_mv_stn(data)                                                          (0x00000FFF&((data)<<0))
#define MV_LVL_mv_stn_src(data)                                                      ((0x00000FFF&(data))>>0)
#define MV_LVL_get_mv_stn(data)                                                      ((0x00000FFF&(data))>>0)


#define CGMS_CTRL                                                                    0x1801F160
#define CGMS_CTRL_reg_addr                                                           "0xB800A160"
#define CGMS_CTRL_reg                                                               0xB801F160
#define set_CGMS_CTRL_reg(data)   (*((volatile unsigned int*) CGMS_CTRL_reg)=data)
#define get_CGMS_CTRL_reg   (*((volatile unsigned int*) CGMS_CTRL_reg))
#define CGMS_CTRL_inst_adr                                                           "0x0058"
#define CGMS_CTRL_inst                                                               0x0058
#define CGMS_CTRL_write_en3_shift                                                    (24)
#define CGMS_CTRL_write_en3_mask                                                     (0x01000000)
#define CGMS_CTRL_write_en3(data)                                                    (0x01000000&((data)<<24))
#define CGMS_CTRL_write_en3_src(data)                                                ((0x01000000&(data))>>24)
#define CGMS_CTRL_get_write_en3(data)                                                ((0x01000000&(data))>>24)
#define CGMS_CTRL_cgms_i_ebl_shift                                                   (23)
#define CGMS_CTRL_cgms_i_ebl_mask                                                    (0x00800000)
#define CGMS_CTRL_cgms_i_ebl(data)                                                   (0x00800000&((data)<<23))
#define CGMS_CTRL_cgms_i_ebl_src(data)                                               ((0x00800000&(data))>>23)
#define CGMS_CTRL_get_cgms_i_ebl(data)                                               ((0x00800000&(data))>>23)
#define CGMS_CTRL_write_en2_shift                                                    (22)
#define CGMS_CTRL_write_en2_mask                                                     (0x00400000)
#define CGMS_CTRL_write_en2(data)                                                    (0x00400000&((data)<<22))
#define CGMS_CTRL_write_en2_src(data)                                                ((0x00400000&(data))>>22)
#define CGMS_CTRL_get_write_en2(data)                                                ((0x00400000&(data))>>22)
#define CGMS_CTRL_cgms_p_ebl_shift                                                   (21)
#define CGMS_CTRL_cgms_p_ebl_mask                                                    (0x00200000)
#define CGMS_CTRL_cgms_p_ebl(data)                                                   (0x00200000&((data)<<21))
#define CGMS_CTRL_cgms_p_ebl_src(data)                                               ((0x00200000&(data))>>21)
#define CGMS_CTRL_get_cgms_p_ebl(data)                                               ((0x00200000&(data))>>21)
#define CGMS_CTRL_write_en1_shift                                                    (20)
#define CGMS_CTRL_write_en1_mask                                                     (0x00100000)
#define CGMS_CTRL_write_en1(data)                                                    (0x00100000&((data)<<20))
#define CGMS_CTRL_write_en1_src(data)                                                ((0x00100000&(data))>>20)
#define CGMS_CTRL_get_write_en1(data)                                                ((0x00100000&(data))>>20)
#define CGMS_CTRL_cgms_data_shift                                                    (0)
#define CGMS_CTRL_cgms_data_mask                                                     (0x000FFFFF)
#define CGMS_CTRL_cgms_data(data)                                                    (0x000FFFFF&((data)<<0))
#define CGMS_CTRL_cgms_data_src(data)                                                ((0x000FFFFF&(data))>>0)
#define CGMS_CTRL_get_cgms_data(data)                                                ((0x000FFFFF&(data))>>0)


#define CGMS_CTRL1                                                                   0x1801F310
#define CGMS_CTRL1_reg_addr                                                          "0xB800A310"
#define CGMS_CTRL1_reg                                                              0xB801F310
#define set_CGMS_CTRL1_reg(data)   (*((volatile unsigned int*) CGMS_CTRL1_reg)=data)
#define get_CGMS_CTRL1_reg   (*((volatile unsigned int*) CGMS_CTRL1_reg))
#define CGMS_CTRL1_inst_adr                                                          "0x00C4"
#define CGMS_CTRL1_inst                                                              0x00C4
#define CGMS_CTRL1_cgms_data_shift                                                   (0)
#define CGMS_CTRL1_cgms_data_mask                                                    (0x000FFFFF)
#define CGMS_CTRL1_cgms_data(data)                                                   (0x000FFFFF&((data)<<0))
#define CGMS_CTRL1_cgms_data_src(data)                                               ((0x000FFFFF&(data))>>0)
#define CGMS_CTRL1_get_cgms_data(data)                                               ((0x000FFFFF&(data))>>0)


#define CGMS_I_VPOS                                                                  0x1801F164
#define CGMS_I_VPOS_reg_addr                                                         "0xB800A164"
#define CGMS_I_VPOS_reg                                                             0xB801F164
#define set_CGMS_I_VPOS_reg(data)   (*((volatile unsigned int*) CGMS_I_VPOS_reg)=data)
#define get_CGMS_I_VPOS_reg   (*((volatile unsigned int*) CGMS_I_VPOS_reg))
#define CGMS_I_VPOS_inst_adr                                                         "0x0059"
#define CGMS_I_VPOS_inst                                                             0x0059
#define CGMS_I_VPOS_write_en2_shift                                                  (20)
#define CGMS_I_VPOS_write_en2_mask                                                   (0x00100000)
#define CGMS_I_VPOS_write_en2(data)                                                  (0x00100000&((data)<<20))
#define CGMS_I_VPOS_write_en2_src(data)                                              ((0x00100000&(data))>>20)
#define CGMS_I_VPOS_get_write_en2(data)                                              ((0x00100000&(data))>>20)
#define CGMS_I_VPOS_cgms_i_vpos1_shift                                               (11)
#define CGMS_I_VPOS_cgms_i_vpos1_mask                                                (0x000FF800)
#define CGMS_I_VPOS_cgms_i_vpos1(data)                                               (0x000FF800&((data)<<11))
#define CGMS_I_VPOS_cgms_i_vpos1_src(data)                                           ((0x000FF800&(data))>>11)
#define CGMS_I_VPOS_get_cgms_i_vpos1(data)                                           ((0x000FF800&(data))>>11)
#define CGMS_I_VPOS_write_en1_shift                                                  (10)
#define CGMS_I_VPOS_write_en1_mask                                                   (0x00000400)
#define CGMS_I_VPOS_write_en1(data)                                                  (0x00000400&((data)<<10))
#define CGMS_I_VPOS_write_en1_src(data)                                              ((0x00000400&(data))>>10)
#define CGMS_I_VPOS_get_write_en1(data)                                              ((0x00000400&(data))>>10)
#define CGMS_I_VPOS_cgms_i_vpos2_shift                                               (0)
#define CGMS_I_VPOS_cgms_i_vpos2_mask                                                (0x000003FF)
#define CGMS_I_VPOS_cgms_i_vpos2(data)                                               (0x000003FF&((data)<<0))
#define CGMS_I_VPOS_cgms_i_vpos2_src(data)                                           ((0x000003FF&(data))>>0)
#define CGMS_I_VPOS_get_cgms_i_vpos2(data)                                           ((0x000003FF&(data))>>0)


#define CGMS_P_VPOS                                                                  0x1801F168
#define CGMS_P_VPOS_reg_addr                                                         "0xB800A168"
#define CGMS_P_VPOS_reg                                                             0xB801F168
#define set_CGMS_P_VPOS_reg(data)   (*((volatile unsigned int*) CGMS_P_VPOS_reg)=data)
#define get_CGMS_P_VPOS_reg   (*((volatile unsigned int*) CGMS_P_VPOS_reg))
#define CGMS_P_VPOS_inst_adr                                                         "0x005A"
#define CGMS_P_VPOS_inst                                                             0x005A
#define CGMS_P_VPOS_write_en2_shift                                                  (22)
#define CGMS_P_VPOS_write_en2_mask                                                   (0x00400000)
#define CGMS_P_VPOS_write_en2(data)                                                  (0x00400000&((data)<<22))
#define CGMS_P_VPOS_write_en2_src(data)                                              ((0x00400000&(data))>>22)
#define CGMS_P_VPOS_get_write_en2(data)                                              ((0x00400000&(data))>>22)
#define CGMS_P_VPOS_cgms_p_vpos2_shift                                               (11)
#define CGMS_P_VPOS_cgms_p_vpos2_mask                                                (0x003FF800)
#define CGMS_P_VPOS_cgms_p_vpos2(data)                                               (0x003FF800&((data)<<11))
#define CGMS_P_VPOS_cgms_p_vpos2_src(data)                                           ((0x003FF800&(data))>>11)
#define CGMS_P_VPOS_get_cgms_p_vpos2(data)                                           ((0x003FF800&(data))>>11)
#define CGMS_P_VPOS_write_en1_shift                                                  (10)
#define CGMS_P_VPOS_write_en1_mask                                                   (0x00000400)
#define CGMS_P_VPOS_write_en1(data)                                                  (0x00000400&((data)<<10))
#define CGMS_P_VPOS_write_en1_src(data)                                              ((0x00000400&(data))>>10)
#define CGMS_P_VPOS_get_write_en1(data)                                              ((0x00000400&(data))>>10)
#define CGMS_P_VPOS_cgms_p_vpos1_shift                                               (0)
#define CGMS_P_VPOS_cgms_p_vpos1_mask                                                (0x000003FF)
#define CGMS_P_VPOS_cgms_p_vpos1(data)                                               (0x000003FF&((data)<<0))
#define CGMS_P_VPOS_cgms_p_vpos1_src(data)                                           ((0x000003FF&(data))>>0)
#define CGMS_P_VPOS_get_cgms_p_vpos1(data)                                           ((0x000003FF&(data))>>0)


#define CGMS_I_HPOS                                                                  0x1801F16c
#define CGMS_I_HPOS_reg_addr                                                         "0xB800A16C"
#define CGMS_I_HPOS_reg                                                             0xB801F16C
#define set_CGMS_I_HPOS_reg(data)   (*((volatile unsigned int*) CGMS_I_HPOS_reg)=data)
#define get_CGMS_I_HPOS_reg   (*((volatile unsigned int*) CGMS_I_HPOS_reg))
#define CGMS_I_HPOS_inst_adr                                                         "0x005B"
#define CGMS_I_HPOS_inst                                                             0x005B
#define CGMS_I_HPOS_write_en2_shift                                                  (21)
#define CGMS_I_HPOS_write_en2_mask                                                   (0x00200000)
#define CGMS_I_HPOS_write_en2(data)                                                  (0x00200000&((data)<<21))
#define CGMS_I_HPOS_write_en2_src(data)                                              ((0x00200000&(data))>>21)
#define CGMS_I_HPOS_get_write_en2(data)                                              ((0x00200000&(data))>>21)
#define CGMS_I_HPOS_cgms_i_hst_shift                                                 (11)
#define CGMS_I_HPOS_cgms_i_hst_mask                                                  (0x001FF800)
#define CGMS_I_HPOS_cgms_i_hst(data)                                                 (0x001FF800&((data)<<11))
#define CGMS_I_HPOS_cgms_i_hst_src(data)                                             ((0x001FF800&(data))>>11)
#define CGMS_I_HPOS_get_cgms_i_hst(data)                                             ((0x001FF800&(data))>>11)
#define CGMS_I_HPOS_write_en1_shift                                                  (10)
#define CGMS_I_HPOS_write_en1_mask                                                   (0x00000400)
#define CGMS_I_HPOS_write_en1(data)                                                  (0x00000400&((data)<<10))
#define CGMS_I_HPOS_write_en1_src(data)                                              ((0x00000400&(data))>>10)
#define CGMS_I_HPOS_get_write_en1(data)                                              ((0x00000400&(data))>>10)
#define CGMS_I_HPOS_cgms_i_len_shift                                                 (0)
#define CGMS_I_HPOS_cgms_i_len_mask                                                  (0x000003FF)
#define CGMS_I_HPOS_cgms_i_len(data)                                                 (0x000003FF&((data)<<0))
#define CGMS_I_HPOS_cgms_i_len_src(data)                                             ((0x000003FF&(data))>>0)
#define CGMS_I_HPOS_get_cgms_i_len(data)                                             ((0x000003FF&(data))>>0)


#define CGMS_P_HPOS                                                                  0x1801F170
#define CGMS_P_HPOS_reg_addr                                                         "0xB800A170"
#define CGMS_P_HPOS_reg                                                             0xB801F170
#define set_CGMS_P_HPOS_reg(data)   (*((volatile unsigned int*) CGMS_P_HPOS_reg)=data)
#define get_CGMS_P_HPOS_reg   (*((volatile unsigned int*) CGMS_P_HPOS_reg))
#define CGMS_P_HPOS_inst_adr                                                         "0x005C"
#define CGMS_P_HPOS_inst                                                             0x005C
#define CGMS_P_HPOS_write_en3_shift                                                  (30)
#define CGMS_P_HPOS_write_en3_mask                                                   (0x40000000)
#define CGMS_P_HPOS_write_en3(data)                                                  (0x40000000&((data)<<30))
#define CGMS_P_HPOS_write_en3_src(data)                                              ((0x40000000&(data))>>30)
#define CGMS_P_HPOS_get_write_en3(data)                                              ((0x40000000&(data))>>30)
#define CGMS_P_HPOS_cgms_p_lvl_shift                                                 (22)
#define CGMS_P_HPOS_cgms_p_lvl_mask                                                  (0x3FC00000)
#define CGMS_P_HPOS_cgms_p_lvl(data)                                                 (0x3FC00000&((data)<<22))
#define CGMS_P_HPOS_cgms_p_lvl_src(data)                                             ((0x3FC00000&(data))>>22)
#define CGMS_P_HPOS_get_cgms_p_lvl(data)                                             ((0x3FC00000&(data))>>22)
#define CGMS_P_HPOS_write_en2_shift                                                  (21)
#define CGMS_P_HPOS_write_en2_mask                                                   (0x00200000)
#define CGMS_P_HPOS_write_en2(data)                                                  (0x00200000&((data)<<21))
#define CGMS_P_HPOS_write_en2_src(data)                                              ((0x00200000&(data))>>21)
#define CGMS_P_HPOS_get_write_en2(data)                                              ((0x00200000&(data))>>21)
#define CGMS_P_HPOS_cgms_p_hst_shift                                                 (11)
#define CGMS_P_HPOS_cgms_p_hst_mask                                                  (0x001FF800)
#define CGMS_P_HPOS_cgms_p_hst(data)                                                 (0x001FF800&((data)<<11))
#define CGMS_P_HPOS_cgms_p_hst_src(data)                                             ((0x001FF800&(data))>>11)
#define CGMS_P_HPOS_get_cgms_p_hst(data)                                             ((0x001FF800&(data))>>11)
#define CGMS_P_HPOS_write_en1_shift                                                  (10)
#define CGMS_P_HPOS_write_en1_mask                                                   (0x00000400)
#define CGMS_P_HPOS_write_en1(data)                                                  (0x00000400&((data)<<10))
#define CGMS_P_HPOS_write_en1_src(data)                                              ((0x00000400&(data))>>10)
#define CGMS_P_HPOS_get_write_en1(data)                                              ((0x00000400&(data))>>10)
#define CGMS_P_HPOS_cgms_p_len_shift                                                 (0)
#define CGMS_P_HPOS_cgms_p_len_mask                                                  (0x000003FF)
#define CGMS_P_HPOS_cgms_p_len(data)                                                 (0x000003FF&((data)<<0))
#define CGMS_P_HPOS_cgms_p_len_src(data)                                             ((0x000003FF&(data))>>0)
#define CGMS_P_HPOS_get_cgms_p_len(data)                                             ((0x000003FF&(data))>>0)


#define CGMS_P2_VPOS                                                                 0x1801F384
#define CGMS_P2_VPOS_reg_addr                                                        "0xB800A384"
#define CGMS_P2_VPOS_reg                                                            0xB801F384
#define set_CGMS_P2_VPOS_reg(data)   (*((volatile unsigned int*) CGMS_P2_VPOS_reg)=data)
#define get_CGMS_P2_VPOS_reg   (*((volatile unsigned int*) CGMS_P2_VPOS_reg))
#define CGMS_P2_VPOS_inst_adr                                                        "0x00E1"
#define CGMS_P2_VPOS_inst                                                            0x00E1
#define CGMS_P2_VPOS_write_en3_shift                                                 (24)
#define CGMS_P2_VPOS_write_en3_mask                                                  (0x01000000)
#define CGMS_P2_VPOS_write_en3(data)                                                 (0x01000000&((data)<<24))
#define CGMS_P2_VPOS_write_en3_src(data)                                             ((0x01000000&(data))>>24)
#define CGMS_P2_VPOS_get_write_en3(data)                                             ((0x01000000&(data))>>24)
#define CGMS_P2_VPOS_cgms_p_b_ebl_shift                                              (23)
#define CGMS_P2_VPOS_cgms_p_b_ebl_mask                                               (0x00800000)
#define CGMS_P2_VPOS_cgms_p_b_ebl(data)                                              (0x00800000&((data)<<23))
#define CGMS_P2_VPOS_cgms_p_b_ebl_src(data)                                          ((0x00800000&(data))>>23)
#define CGMS_P2_VPOS_get_cgms_p_b_ebl(data)                                          ((0x00800000&(data))>>23)
#define CGMS_P2_VPOS_write_en2_shift                                                 (22)
#define CGMS_P2_VPOS_write_en2_mask                                                  (0x00400000)
#define CGMS_P2_VPOS_write_en2(data)                                                 (0x00400000&((data)<<22))
#define CGMS_P2_VPOS_write_en2_src(data)                                             ((0x00400000&(data))>>22)
#define CGMS_P2_VPOS_get_write_en2(data)                                             ((0x00400000&(data))>>22)
#define CGMS_P2_VPOS_cgms_p2_vpos2_shift                                             (11)
#define CGMS_P2_VPOS_cgms_p2_vpos2_mask                                              (0x003FF800)
#define CGMS_P2_VPOS_cgms_p2_vpos2(data)                                             (0x003FF800&((data)<<11))
#define CGMS_P2_VPOS_cgms_p2_vpos2_src(data)                                         ((0x003FF800&(data))>>11)
#define CGMS_P2_VPOS_get_cgms_p2_vpos2(data)                                         ((0x003FF800&(data))>>11)
#define CGMS_P2_VPOS_write_en1_shift                                                 (10)
#define CGMS_P2_VPOS_write_en1_mask                                                  (0x00000400)
#define CGMS_P2_VPOS_write_en1(data)                                                 (0x00000400&((data)<<10))
#define CGMS_P2_VPOS_write_en1_src(data)                                             ((0x00000400&(data))>>10)
#define CGMS_P2_VPOS_get_write_en1(data)                                             ((0x00000400&(data))>>10)
#define CGMS_P2_VPOS_cgms_p2_vpos1_shift                                             (0)
#define CGMS_P2_VPOS_cgms_p2_vpos1_mask                                              (0x000003FF)
#define CGMS_P2_VPOS_cgms_p2_vpos1(data)                                             (0x000003FF&((data)<<0))
#define CGMS_P2_VPOS_cgms_p2_vpos1_src(data)                                         ((0x000003FF&(data))>>0)
#define CGMS_P2_VPOS_get_cgms_p2_vpos1(data)                                         ((0x000003FF&(data))>>0)


#define CGMS_P2_HPOS                                                                 0x1801F354
#define CGMS_P2_HPOS_reg_addr                                                        "0xB800A354"
#define CGMS_P2_HPOS_reg                                                            0xB801F354
#define set_CGMS_P2_HPOS_reg(data)   (*((volatile unsigned int*) CGMS_P2_HPOS_reg)=data)
#define get_CGMS_P2_HPOS_reg   (*((volatile unsigned int*) CGMS_P2_HPOS_reg))
#define CGMS_P2_HPOS_inst_adr                                                        "0x00D5"
#define CGMS_P2_HPOS_inst                                                            0x00D5
#define CGMS_P2_HPOS_write_en3_shift                                                 (30)
#define CGMS_P2_HPOS_write_en3_mask                                                  (0x40000000)
#define CGMS_P2_HPOS_write_en3(data)                                                 (0x40000000&((data)<<30))
#define CGMS_P2_HPOS_write_en3_src(data)                                             ((0x40000000&(data))>>30)
#define CGMS_P2_HPOS_get_write_en3(data)                                             ((0x40000000&(data))>>30)
#define CGMS_P2_HPOS_cgms_p2_lvl_shift                                               (22)
#define CGMS_P2_HPOS_cgms_p2_lvl_mask                                                (0x3FC00000)
#define CGMS_P2_HPOS_cgms_p2_lvl(data)                                               (0x3FC00000&((data)<<22))
#define CGMS_P2_HPOS_cgms_p2_lvl_src(data)                                           ((0x3FC00000&(data))>>22)
#define CGMS_P2_HPOS_get_cgms_p2_lvl(data)                                           ((0x3FC00000&(data))>>22)
#define CGMS_P2_HPOS_write_en2_shift                                                 (21)
#define CGMS_P2_HPOS_write_en2_mask                                                  (0x00200000)
#define CGMS_P2_HPOS_write_en2(data)                                                 (0x00200000&((data)<<21))
#define CGMS_P2_HPOS_write_en2_src(data)                                             ((0x00200000&(data))>>21)
#define CGMS_P2_HPOS_get_write_en2(data)                                             ((0x00200000&(data))>>21)
#define CGMS_P2_HPOS_cgms_p2_hst_shift                                               (11)
#define CGMS_P2_HPOS_cgms_p2_hst_mask                                                (0x001FF800)
#define CGMS_P2_HPOS_cgms_p2_hst(data)                                               (0x001FF800&((data)<<11))
#define CGMS_P2_HPOS_cgms_p2_hst_src(data)                                           ((0x001FF800&(data))>>11)
#define CGMS_P2_HPOS_get_cgms_p2_hst(data)                                           ((0x001FF800&(data))>>11)
#define CGMS_P2_HPOS_write_en1_shift                                                 (10)
#define CGMS_P2_HPOS_write_en1_mask                                                  (0x00000400)
#define CGMS_P2_HPOS_write_en1(data)                                                 (0x00000400&((data)<<10))
#define CGMS_P2_HPOS_write_en1_src(data)                                             ((0x00000400&(data))>>10)
#define CGMS_P2_HPOS_get_write_en1(data)                                             ((0x00000400&(data))>>10)
#define CGMS_P2_HPOS_cgms_p2_len_shift                                               (0)
#define CGMS_P2_HPOS_cgms_p2_len_mask                                                (0x000003FF)
#define CGMS_P2_HPOS_cgms_p2_len(data)                                               (0x000003FF&((data)<<0))
#define CGMS_P2_HPOS_cgms_p2_len_src(data)                                           ((0x000003FF&(data))>>0)
#define CGMS_P2_HPOS_get_cgms_p2_len(data)                                           ((0x000003FF&(data))>>0)


#define CGMS_B_HDR                                                                   0x1801F358
#define CGMS_B_HDR_reg_addr                                                          "0xB800A358"
#define CGMS_B_HDR_reg                                                              0xB801F358
#define set_CGMS_B_HDR_reg(data)   (*((volatile unsigned int*) CGMS_B_HDR_reg)=data)
#define get_CGMS_B_HDR_reg   (*((volatile unsigned int*) CGMS_B_HDR_reg))
#define CGMS_B_HDR_inst_adr                                                          "0x00D6"
#define CGMS_B_HDR_inst                                                              0x00D6
#define CGMS_B_HDR_cgms_hdr_shift                                                    (0)
#define CGMS_B_HDR_cgms_hdr_mask                                                     (0x0000003F)
#define CGMS_B_HDR_cgms_hdr(data)                                                    (0x0000003F&((data)<<0))
#define CGMS_B_HDR_cgms_hdr_src(data)                                                ((0x0000003F&(data))>>0)
#define CGMS_B_HDR_get_cgms_hdr(data)                                                ((0x0000003F&(data))>>0)


#define CGMS_B_DATA_0                                                                0x1801F35C
#define CGMS_B_DATA_1                                                                0x1801F360
#define CGMS_B_DATA_2                                                                0x1801F364
#define CGMS_B_DATA_3                                                                0x1801F368
#define CGMS_B_DATA_0_reg_addr                                                       "0xB800A35C"
#define CGMS_B_DATA_1_reg_addr                                                       "0xB800A360"
#define CGMS_B_DATA_2_reg_addr                                                       "0xB800A364"
#define CGMS_B_DATA_3_reg_addr                                                       "0xB800A368"
#define CGMS_B_DATA_0_reg                                                           0xB801F35C
#define CGMS_B_DATA_1_reg                                                           0xB801F360
#define CGMS_B_DATA_2_reg                                                           0xB801F364
#define CGMS_B_DATA_3_reg                                                           0xB801F368
#define set_CGMS_B_DATA_0_reg(data)   (*((volatile unsigned int*) CGMS_B_DATA_0_reg)=data)
#define set_CGMS_B_DATA_1_reg(data)   (*((volatile unsigned int*) CGMS_B_DATA_1_reg)=data)
#define set_CGMS_B_DATA_2_reg(data)   (*((volatile unsigned int*) CGMS_B_DATA_2_reg)=data)
#define set_CGMS_B_DATA_3_reg(data)   (*((volatile unsigned int*) CGMS_B_DATA_3_reg)=data)
#define get_CGMS_B_DATA_0_reg   (*((volatile unsigned int*) CGMS_B_DATA_0_reg))
#define get_CGMS_B_DATA_1_reg   (*((volatile unsigned int*) CGMS_B_DATA_1_reg))
#define get_CGMS_B_DATA_2_reg   (*((volatile unsigned int*) CGMS_B_DATA_2_reg))
#define get_CGMS_B_DATA_3_reg   (*((volatile unsigned int*) CGMS_B_DATA_3_reg))
#define CGMS_B_DATA_0_inst_adr                                                       "0x00D7"
#define CGMS_B_DATA_1_inst_adr                                                       "0x00D8"
#define CGMS_B_DATA_2_inst_adr                                                       "0x00D9"
#define CGMS_B_DATA_3_inst_adr                                                       "0x00DA"
#define CGMS_B_DATA_0_inst                                                           0x00D7
#define CGMS_B_DATA_1_inst                                                           0x00D8
#define CGMS_B_DATA_2_inst                                                           0x00D9
#define CGMS_B_DATA_3_inst                                                           0x00DA
#define CGMS_B_DATA_cgms_data_shift                                                  (0)
#define CGMS_B_DATA_cgms_data_mask                                                   (0xFFFFFFFF)
#define CGMS_B_DATA_cgms_data(data)                                                  (0xFFFFFFFF&((data)<<0))
#define CGMS_B_DATA_cgms_data_src(data)                                              ((0xFFFFFFFF&(data))>>0)
#define CGMS_B_DATA_get_cgms_data(data)                                              ((0xFFFFFFFF&(data))>>0)


#define WSS_CTRL                                                                     0x1801F174
#define WSS_CTRL_reg_addr                                                            "0xB800A174"
#define WSS_CTRL_reg                                                                0xB801F174
#define set_WSS_CTRL_reg(data)   (*((volatile unsigned int*) WSS_CTRL_reg)=data)
#define get_WSS_CTRL_reg   (*((volatile unsigned int*) WSS_CTRL_reg))
#define WSS_CTRL_inst_adr                                                            "0x005D"
#define WSS_CTRL_inst                                                                0x005D
#define WSS_CTRL_write_en4_shift                                                     (30)
#define WSS_CTRL_write_en4_mask                                                      (0x40000000)
#define WSS_CTRL_write_en4(data)                                                     (0x40000000&((data)<<30))
#define WSS_CTRL_write_en4_src(data)                                                 ((0x40000000&(data))>>30)
#define WSS_CTRL_get_write_en4(data)                                                 ((0x40000000&(data))>>30)
#define WSS_CTRL_wss_ebl_shift                                                       (29)
#define WSS_CTRL_wss_ebl_mask                                                        (0x20000000)
#define WSS_CTRL_wss_ebl(data)                                                       (0x20000000&((data)<<29))
#define WSS_CTRL_wss_ebl_src(data)                                                   ((0x20000000&(data))>>29)
#define WSS_CTRL_get_wss_ebl(data)                                                   ((0x20000000&(data))>>29)
#define WSS_CTRL_write_en3_shift                                                     (28)
#define WSS_CTRL_write_en3_mask                                                      (0x10000000)
#define WSS_CTRL_write_en3(data)                                                     (0x10000000&((data)<<28))
#define WSS_CTRL_write_en3_src(data)                                                 ((0x10000000&(data))>>28)
#define WSS_CTRL_get_write_en3(data)                                                 ((0x10000000&(data))>>28)
#define WSS_CTRL_wss_intp_sel_shift                                                  (27)
#define WSS_CTRL_wss_intp_sel_mask                                                   (0x08000000)
#define WSS_CTRL_wss_intp_sel(data)                                                  (0x08000000&((data)<<27))
#define WSS_CTRL_wss_intp_sel_src(data)                                              ((0x08000000&(data))>>27)
#define WSS_CTRL_get_wss_intp_sel(data)                                              ((0x08000000&(data))>>27)
#define WSS_CTRL_write_en2_shift                                                     (26)
#define WSS_CTRL_write_en2_mask                                                      (0x04000000)
#define WSS_CTRL_write_en2(data)                                                     (0x04000000&((data)<<26))
#define WSS_CTRL_write_en2_src(data)                                                 ((0x04000000&(data))>>26)
#define WSS_CTRL_get_write_en2(data)                                                 ((0x04000000&(data))>>26)
#define WSS_CTRL_wss_end_hpos_shift                                                  (15)
#define WSS_CTRL_wss_end_hpos_mask                                                   (0x03FF8000)
#define WSS_CTRL_wss_end_hpos(data)                                                  (0x03FF8000&((data)<<15))
#define WSS_CTRL_wss_end_hpos_src(data)                                              ((0x03FF8000&(data))>>15)
#define WSS_CTRL_get_wss_end_hpos(data)                                              ((0x03FF8000&(data))>>15)
#define WSS_CTRL_write_en1_shift                                                     (14)
#define WSS_CTRL_write_en1_mask                                                      (0x00004000)
#define WSS_CTRL_write_en1(data)                                                     (0x00004000&((data)<<14))
#define WSS_CTRL_write_en1_src(data)                                                 ((0x00004000&(data))>>14)
#define WSS_CTRL_get_write_en1(data)                                                 ((0x00004000&(data))>>14)
#define WSS_CTRL_wss_data_shift                                                      (0)
#define WSS_CTRL_wss_data_mask                                                       (0x00003FFF)
#define WSS_CTRL_wss_data(data)                                                      (0x00003FFF&((data)<<0))
#define WSS_CTRL_wss_data_src(data)                                                  ((0x00003FFF&(data))>>0)
#define WSS_CTRL_get_wss_data(data)                                                  ((0x00003FFF&(data))>>0)


#define WSS_POS                                                                      0x1801F178
#define WSS_POS_reg_addr                                                             "0xB800A178"
#define WSS_POS_reg                                                                 0xB801F178
#define set_WSS_POS_reg(data)   (*((volatile unsigned int*) WSS_POS_reg)=data)
#define get_WSS_POS_reg   (*((volatile unsigned int*) WSS_POS_reg))
#define WSS_POS_inst_adr                                                             "0x005E"
#define WSS_POS_inst                                                                 0x005E
#define WSS_POS_write_en2_shift                                                      (22)
#define WSS_POS_write_en2_mask                                                       (0x00400000)
#define WSS_POS_write_en2(data)                                                      (0x00400000&((data)<<22))
#define WSS_POS_write_en2_src(data)                                                  ((0x00400000&(data))>>22)
#define WSS_POS_get_write_en2(data)                                                  ((0x00400000&(data))>>22)
#define WSS_POS_wss_h_pos_shift                                                      (11)
#define WSS_POS_wss_h_pos_mask                                                       (0x003FF800)
#define WSS_POS_wss_h_pos(data)                                                      (0x003FF800&((data)<<11))
#define WSS_POS_wss_h_pos_src(data)                                                  ((0x003FF800&(data))>>11)
#define WSS_POS_get_wss_h_pos(data)                                                  ((0x003FF800&(data))>>11)
#define WSS_POS_write_en1_shift                                                      (10)
#define WSS_POS_write_en1_mask                                                       (0x00000400)
#define WSS_POS_write_en1(data)                                                      (0x00000400&((data)<<10))
#define WSS_POS_write_en1_src(data)                                                  ((0x00000400&(data))>>10)
#define WSS_POS_get_write_en1(data)                                                  ((0x00000400&(data))>>10)
#define WSS_POS_wss_v_pos_shift                                                      (0)
#define WSS_POS_wss_v_pos_mask                                                       (0x000003FF)
#define WSS_POS_wss_v_pos(data)                                                      (0x000003FF&((data)<<0))
#define WSS_POS_wss_v_pos_src(data)                                                  ((0x000003FF&(data))>>0)
#define WSS_POS_get_wss_v_pos(data)                                                  ((0x000003FF&(data))>>0)


#define TVE_625P_WSS_CTRL                                                                0x1801F17c
#define TVE_625P_WSS_CTRL_reg_addr                                                       "0xB800A17C"
#define TVE_625P_WSS_CTRL_reg                                                           0xB801F17C
#define set_TVE_625P_WSS_CTRL_reg(data)   (*((volatile unsigned int*) TVE_625P_WSS_CTRL_reg)=data)
#define get_TVE_625P_WSS_CTRL_reg   (*((volatile unsigned int*) TVE_625P_WSS_CTRL_reg))
#define TVE_625P_WSS_CTRL_inst_adr                                                       "0x005F"
#define TVE_625P_WSS_CTRL_inst                                                           0x005F
#define TVE_625P_WSS_CTRL_write_en3_shift                                                (18)
#define TVE_625P_WSS_CTRL_write_en3_mask                                                 (0x00040000)
#define TVE_625P_WSS_CTRL_write_en3(data)                                                (0x00040000&((data)<<18))
#define TVE_625P_WSS_CTRL_write_en3_src(data)                                            ((0x00040000&(data))>>18)
#define TVE_625P_WSS_CTRL_get_write_en3(data)                                            ((0x00040000&(data))>>18)
#define TVE_625P_WSS_CTRL_wss_ebl_shift                                                  (17)
#define TVE_625P_WSS_CTRL_wss_ebl_mask                                                   (0x00020000)
#define TVE_625P_WSS_CTRL_wss_ebl(data)                                                  (0x00020000&((data)<<17))
#define TVE_625P_WSS_CTRL_wss_ebl_src(data)                                              ((0x00020000&(data))>>17)
#define TVE_625P_WSS_CTRL_get_wss_ebl(data)                                              ((0x00020000&(data))>>17)
#define TVE_625P_WSS_CTRL_write_en2_shift                                                (16)
#define TVE_625P_WSS_CTRL_write_en2_mask                                                 (0x00010000)
#define TVE_625P_WSS_CTRL_write_en2(data)                                                (0x00010000&((data)<<16))
#define TVE_625P_WSS_CTRL_write_en2_src(data)                                            ((0x00010000&(data))>>16)
#define TVE_625P_WSS_CTRL_get_write_en2(data)                                            ((0x00010000&(data))>>16)
#define TVE_625P_WSS_CTRL_wss_intp_sel_shift                                             (15)
#define TVE_625P_WSS_CTRL_wss_intp_sel_mask                                              (0x00008000)
#define TVE_625P_WSS_CTRL_wss_intp_sel(data)                                             (0x00008000&((data)<<15))
#define TVE_625P_WSS_CTRL_wss_intp_sel_src(data)                                         ((0x00008000&(data))>>15)
#define TVE_625P_WSS_CTRL_get_wss_intp_sel(data)                                         ((0x00008000&(data))>>15)
#define TVE_625P_WSS_CTRL_write_en1_shift                                                (14)
#define TVE_625P_WSS_CTRL_write_en1_mask                                                 (0x00004000)
#define TVE_625P_WSS_CTRL_write_en1(data)                                                (0x00004000&((data)<<14))
#define TVE_625P_WSS_CTRL_write_en1_src(data)                                            ((0x00004000&(data))>>14)
#define TVE_625P_WSS_CTRL_get_write_en1(data)                                            ((0x00004000&(data))>>14)
#define TVE_625P_WSS_CTRL_wss_data_shift                                                 (0)
#define TVE_625P_WSS_CTRL_wss_data_mask                                                  (0x00003FFF)
#define TVE_625P_WSS_CTRL_wss_data(data)                                                 (0x00003FFF&((data)<<0))
#define TVE_625P_WSS_CTRL_wss_data_src(data)                                             ((0x00003FFF&(data))>>0)
#define TVE_625P_WSS_CTRL_get_wss_data(data)                                             ((0x00003FFF&(data))>>0)


#define TVE_625P_WSS_POS                                                                 0x1801F180
#define TVE_625P_WSS_POS_reg_addr                                                        "0xB800A180"
#define TVE_625P_WSS_POS_reg                                                            0xB801F180
#define set_TVE_625P_WSS_POS_reg(data)   (*((volatile unsigned int*) TVE_625P_WSS_POS_reg)=data)
#define get_TVE_625P_WSS_POS_reg   (*((volatile unsigned int*) TVE_625P_WSS_POS_reg))
#define TVE_625P_WSS_POS_inst_adr                                                        "0x0060"
#define TVE_625P_WSS_POS_inst                                                            0x0060
#define TVE_625P_WSS_POS_write_en2_shift                                                 (22)
#define TVE_625P_WSS_POS_write_en2_mask                                                  (0x00400000)
#define TVE_625P_WSS_POS_write_en2(data)                                                 (0x00400000&((data)<<22))
#define TVE_625P_WSS_POS_write_en2_src(data)                                             ((0x00400000&(data))>>22)
#define TVE_625P_WSS_POS_get_write_en2(data)                                             ((0x00400000&(data))>>22)
#define TVE_625P_WSS_POS_wss_h_pos_shift                                                 (11)
#define TVE_625P_WSS_POS_wss_h_pos_mask                                                  (0x003FF800)
#define TVE_625P_WSS_POS_wss_h_pos(data)                                                 (0x003FF800&((data)<<11))
#define TVE_625P_WSS_POS_wss_h_pos_src(data)                                             ((0x003FF800&(data))>>11)
#define TVE_625P_WSS_POS_get_wss_h_pos(data)                                             ((0x003FF800&(data))>>11)
#define TVE_625P_WSS_POS_write_en1_shift                                                 (10)
#define TVE_625P_WSS_POS_write_en1_mask                                                  (0x00000400)
#define TVE_625P_WSS_POS_write_en1(data)                                                 (0x00000400&((data)<<10))
#define TVE_625P_WSS_POS_write_en1_src(data)                                             ((0x00000400&(data))>>10)
#define TVE_625P_WSS_POS_get_write_en1(data)                                             ((0x00000400&(data))>>10)
#define TVE_625P_WSS_POS_wss_v_pos_shift                                                 (0)
#define TVE_625P_WSS_POS_wss_v_pos_mask                                                  (0x000003FF)
#define TVE_625P_WSS_POS_wss_v_pos(data)                                                 (0x000003FF&((data)<<0))
#define TVE_625P_WSS_POS_wss_v_pos_src(data)                                             ((0x000003FF&(data))>>0)
#define TVE_625P_WSS_POS_get_wss_v_pos(data)                                             ((0x000003FF&(data))>>0)


#define TT_CTRL                                                                      0x1801F184
#define TT_CTRL_reg_addr                                                             "0xB800A184"
#define TT_CTRL_reg                                                                 0xB801F184
#define set_TT_CTRL_reg(data)   (*((volatile unsigned int*) TT_CTRL_reg)=data)
#define get_TT_CTRL_reg   (*((volatile unsigned int*) TT_CTRL_reg))
#define TT_CTRL_inst_adr                                                             "0x0061"
#define TT_CTRL_inst                                                                 0x0061
#define TT_CTRL_write_en5_shift                                                      (26)
#define TT_CTRL_write_en5_mask                                                       (0x04000000)
#define TT_CTRL_write_en5(data)                                                      (0x04000000&((data)<<26))
#define TT_CTRL_write_en5_src(data)                                                  ((0x04000000&(data))>>26)
#define TT_CTRL_get_write_en5(data)                                                  ((0x04000000&(data))>>26)
#define TT_CTRL_tt_bit_swap_shift                                                    (25)
#define TT_CTRL_tt_bit_swap_mask                                                     (0x02000000)
#define TT_CTRL_tt_bit_swap(data)                                                    (0x02000000&((data)<<25))
#define TT_CTRL_tt_bit_swap_src(data)                                                ((0x02000000&(data))>>25)
#define TT_CTRL_get_tt_bit_swap(data)                                                ((0x02000000&(data))>>25)
#define TT_CTRL_write_en4_shift                                                      (24)
#define TT_CTRL_write_en4_mask                                                       (0x01000000)
#define TT_CTRL_write_en4(data)                                                      (0x01000000&((data)<<24))
#define TT_CTRL_write_en4_src(data)                                                  ((0x01000000&(data))>>24)
#define TT_CTRL_get_write_en4(data)                                                  ((0x01000000&(data))>>24)
#define TT_CTRL_tt_h_st_shift                                                        (13)
#define TT_CTRL_tt_h_st_mask                                                         (0x00FFE000)
#define TT_CTRL_tt_h_st(data)                                                        (0x00FFE000&((data)<<13))
#define TT_CTRL_tt_h_st_src(data)                                                    ((0x00FFE000&(data))>>13)
#define TT_CTRL_get_tt_h_st(data)                                                    ((0x00FFE000&(data))>>13)
#define TT_CTRL_write_en3_shift                                                      (12)
#define TT_CTRL_write_en3_mask                                                       (0x00001000)
#define TT_CTRL_write_en3(data)                                                      (0x00001000&((data)<<12))
#define TT_CTRL_write_en3_src(data)                                                  ((0x00001000&(data))>>12)
#define TT_CTRL_get_write_en3(data)                                                  ((0x00001000&(data))>>12)
#define TT_CTRL_tt_line_no_shift                                                     (4)
#define TT_CTRL_tt_line_no_mask                                                      (0x00000FF0)
#define TT_CTRL_tt_line_no(data)                                                     (0x00000FF0&((data)<<4))
#define TT_CTRL_tt_line_no_src(data)                                                 ((0x00000FF0&(data))>>4)
#define TT_CTRL_get_tt_line_no(data)                                                 ((0x00000FF0&(data))>>4)
#define TT_CTRL_write_en2_shift                                                      (3)
#define TT_CTRL_write_en2_mask                                                       (0x00000008)
#define TT_CTRL_write_en2(data)                                                      (0x00000008&((data)<<3))
#define TT_CTRL_write_en2_src(data)                                                  ((0x00000008&(data))>>3)
#define TT_CTRL_get_write_en2(data)                                                  ((0x00000008&(data))>>3)
#define TT_CTRL_tt_intp_sel_shift                                                    (2)
#define TT_CTRL_tt_intp_sel_mask                                                     (0x00000004)
#define TT_CTRL_tt_intp_sel(data)                                                    (0x00000004&((data)<<2))
#define TT_CTRL_tt_intp_sel_src(data)                                                ((0x00000004&(data))>>2)
#define TT_CTRL_get_tt_intp_sel(data)                                                ((0x00000004&(data))>>2)
#define TT_CTRL_write_en1_shift                                                      (1)
#define TT_CTRL_write_en1_mask                                                       (0x00000002)
#define TT_CTRL_write_en1(data)                                                      (0x00000002&((data)<<1))
#define TT_CTRL_write_en1_src(data)                                                  ((0x00000002&(data))>>1)
#define TT_CTRL_get_write_en1(data)                                                  ((0x00000002&(data))>>1)
#define TT_CTRL_vbi_tt_ebl_shift                                                     (0)
#define TT_CTRL_vbi_tt_ebl_mask                                                      (0x00000001)
#define TT_CTRL_vbi_tt_ebl(data)                                                     (0x00000001&((data)<<0))
#define TT_CTRL_vbi_tt_ebl_src(data)                                                 ((0x00000001&(data))>>0)
#define TT_CTRL_get_vbi_tt_ebl(data)                                                 ((0x00000001&(data))>>0)


#define TT_VPOS                                                                      0x1801F188
#define TT_VPOS_reg_addr                                                             "0xB800A188"
#define TT_VPOS_reg                                                                 0xB801F188
#define set_TT_VPOS_reg(data)   (*((volatile unsigned int*) TT_VPOS_reg)=data)
#define get_TT_VPOS_reg   (*((volatile unsigned int*) TT_VPOS_reg))
#define TT_VPOS_inst_adr                                                             "0x0062"
#define TT_VPOS_inst                                                                 0x0062
#define TT_VPOS_write_en2_shift                                                      (15)
#define TT_VPOS_write_en2_mask                                                       (0x00008000)
#define TT_VPOS_write_en2(data)                                                      (0x00008000&((data)<<15))
#define TT_VPOS_write_en2_src(data)                                                  ((0x00008000&(data))>>15)
#define TT_VPOS_get_write_en2(data)                                                  ((0x00008000&(data))>>15)
#define TT_VPOS_tt_b_vst_shift                                                       (6)
#define TT_VPOS_tt_b_vst_mask                                                        (0x00007FC0)
#define TT_VPOS_tt_b_vst(data)                                                       (0x00007FC0&((data)<<6))
#define TT_VPOS_tt_b_vst_src(data)                                                   ((0x00007FC0&(data))>>6)
#define TT_VPOS_get_tt_b_vst(data)                                                   ((0x00007FC0&(data))>>6)
#define TT_VPOS_write_en1_shift                                                      (5)
#define TT_VPOS_write_en1_mask                                                       (0x00000020)
#define TT_VPOS_write_en1(data)                                                      (0x00000020&((data)<<5))
#define TT_VPOS_write_en1_src(data)                                                  ((0x00000020&(data))>>5)
#define TT_VPOS_get_write_en1(data)                                                  ((0x00000020&(data))>>5)
#define TT_VPOS_tt_t_vst_shift                                                       (0)
#define TT_VPOS_tt_t_vst_mask                                                        (0x0000001F)
#define TT_VPOS_tt_t_vst(data)                                                       (0x0000001F&((data)<<0))
#define TT_VPOS_tt_t_vst_src(data)                                                   ((0x0000001F&(data))>>0)
#define TT_VPOS_get_tt_t_vst(data)                                                   ((0x0000001F&(data))>>0)


#define TT_MASK_VPOS                                                                 0x1801F18c
#define TT_MASK_VPOS_reg_addr                                                        "0xB800A18C"
#define TT_MASK_VPOS_reg                                                            0xB801F18C
#define set_TT_MASK_VPOS_reg(data)   (*((volatile unsigned int*) TT_MASK_VPOS_reg)=data)
#define get_TT_MASK_VPOS_reg   (*((volatile unsigned int*) TT_MASK_VPOS_reg))
#define TT_MASK_VPOS_inst_adr                                                        "0x0063"
#define TT_MASK_VPOS_inst                                                            0x0063
#define TT_MASK_VPOS_write_en2_shift                                                 (23)
#define TT_MASK_VPOS_write_en2_mask                                                  (0x00800000)
#define TT_MASK_VPOS_write_en2(data)                                                 (0x00800000&((data)<<23))
#define TT_MASK_VPOS_write_en2_src(data)                                             ((0x00800000&(data))>>23)
#define TT_MASK_VPOS_get_write_en2(data)                                             ((0x00800000&(data))>>23)
#define TT_MASK_VPOS_start_line2_shift                                               (12)
#define TT_MASK_VPOS_start_line2_mask                                                (0x007FF000)
#define TT_MASK_VPOS_start_line2(data)                                               (0x007FF000&((data)<<12))
#define TT_MASK_VPOS_start_line2_src(data)                                           ((0x007FF000&(data))>>12)
#define TT_MASK_VPOS_get_start_line2(data)                                           ((0x007FF000&(data))>>12)
#define TT_MASK_VPOS_write_en1_shift                                                 (11)
#define TT_MASK_VPOS_write_en1_mask                                                  (0x00000800)
#define TT_MASK_VPOS_write_en1(data)                                                 (0x00000800&((data)<<11))
#define TT_MASK_VPOS_write_en1_src(data)                                             ((0x00000800&(data))>>11)
#define TT_MASK_VPOS_get_write_en1(data)                                             ((0x00000800&(data))>>11)
#define TT_MASK_VPOS_start_line1_shift                                               (0)
#define TT_MASK_VPOS_start_line1_mask                                                (0x000007FF)
#define TT_MASK_VPOS_start_line1(data)                                               (0x000007FF&((data)<<0))
#define TT_MASK_VPOS_start_line1_src(data)                                           ((0x000007FF&(data))>>0)
#define TT_MASK_VPOS_get_start_line1(data)                                           ((0x000007FF&(data))>>0)


#define TT_MASK_FLG_0                                                                0x1801F190
#define TT_MASK_FLG_1                                                                0x1801F194
#define TT_MASK_FLG_0_reg_addr                                                       "0xB800A190"
#define TT_MASK_FLG_1_reg_addr                                                       "0xB800A194"
#define TT_MASK_FLG_0_reg                                                           0xB801F190
#define TT_MASK_FLG_1_reg                                                           0xB801F194
#define set_TT_MASK_FLG_0_reg(data)   (*((volatile unsigned int*) TT_MASK_FLG_0_reg)=data)
#define set_TT_MASK_FLG_1_reg(data)   (*((volatile unsigned int*) TT_MASK_FLG_1_reg)=data)
#define get_TT_MASK_FLG_0_reg   (*((volatile unsigned int*) TT_MASK_FLG_0_reg))
#define get_TT_MASK_FLG_1_reg   (*((volatile unsigned int*) TT_MASK_FLG_1_reg))
#define TT_MASK_FLG_0_inst_adr                                                       "0x0064"
#define TT_MASK_FLG_1_inst_adr                                                       "0x0065"
#define TT_MASK_FLG_0_inst                                                           0x0064
#define TT_MASK_FLG_1_inst                                                           0x0065
#define TT_MASK_FLG_tt_line_mask_shift                                               (0)
#define TT_MASK_FLG_tt_line_mask_mask                                                (0xFFFFFFFF)
#define TT_MASK_FLG_tt_line_mask(data)                                               (0xFFFFFFFF&((data)<<0))
#define TT_MASK_FLG_tt_line_mask_src(data)                                           ((0xFFFFFFFF&(data))>>0)
#define TT_MASK_FLG_get_tt_line_mask(data)                                           ((0xFFFFFFFF&(data))>>0)


#define VPS_CTRL                                                                     0x1801F198
#define VPS_CTRL_reg_addr                                                            "0xB800A198"
#define VPS_CTRL_reg                                                                0xB801F198
#define set_VPS_CTRL_reg(data)   (*((volatile unsigned int*) VPS_CTRL_reg)=data)
#define get_VPS_CTRL_reg   (*((volatile unsigned int*) VPS_CTRL_reg))
#define VPS_CTRL_inst_adr                                                            "0x0066"
#define VPS_CTRL_inst                                                                0x0066
#define VPS_CTRL_write_en4_shift                                                     (26)
#define VPS_CTRL_write_en4_mask                                                      (0x04000000)
#define VPS_CTRL_write_en4(data)                                                     (0x04000000&((data)<<26))
#define VPS_CTRL_write_en4_src(data)                                                 ((0x04000000&(data))>>26)
#define VPS_CTRL_get_write_en4(data)                                                 ((0x04000000&(data))>>26)
#define VPS_CTRL_vps_h_pos_shift                                                     (15)
#define VPS_CTRL_vps_h_pos_mask                                                      (0x03FF8000)
#define VPS_CTRL_vps_h_pos(data)                                                     (0x03FF8000&((data)<<15))
#define VPS_CTRL_vps_h_pos_src(data)                                                 ((0x03FF8000&(data))>>15)
#define VPS_CTRL_get_vps_h_pos(data)                                                 ((0x03FF8000&(data))>>15)
#define VPS_CTRL_write_en3_shift                                                     (14)
#define VPS_CTRL_write_en3_mask                                                      (0x00004000)
#define VPS_CTRL_write_en3(data)                                                     (0x00004000&((data)<<14))
#define VPS_CTRL_write_en3_src(data)                                                 ((0x00004000&(data))>>14)
#define VPS_CTRL_get_write_en3(data)                                                 ((0x00004000&(data))>>14)
#define VPS_CTRL_vps_v_pos_shift                                                     (4)
#define VPS_CTRL_vps_v_pos_mask                                                      (0x00003FF0)
#define VPS_CTRL_vps_v_pos(data)                                                     (0x00003FF0&((data)<<4))
#define VPS_CTRL_vps_v_pos_src(data)                                                 ((0x00003FF0&(data))>>4)
#define VPS_CTRL_get_vps_v_pos(data)                                                 ((0x00003FF0&(data))>>4)
#define VPS_CTRL_write_en2_shift                                                     (3)
#define VPS_CTRL_write_en2_mask                                                      (0x00000008)
#define VPS_CTRL_write_en2(data)                                                     (0x00000008&((data)<<3))
#define VPS_CTRL_write_en2_src(data)                                                 ((0x00000008&(data))>>3)
#define VPS_CTRL_get_write_en2(data)                                                 ((0x00000008&(data))>>3)
#define VPS_CTRL_vps_intp_sel_shift                                                  (2)
#define VPS_CTRL_vps_intp_sel_mask                                                   (0x00000004)
#define VPS_CTRL_vps_intp_sel(data)                                                  (0x00000004&((data)<<2))
#define VPS_CTRL_vps_intp_sel_src(data)                                              ((0x00000004&(data))>>2)
#define VPS_CTRL_get_vps_intp_sel(data)                                              ((0x00000004&(data))>>2)
#define VPS_CTRL_write_en1_shift                                                     (1)
#define VPS_CTRL_write_en1_mask                                                      (0x00000002)
#define VPS_CTRL_write_en1(data)                                                     (0x00000002&((data)<<1))
#define VPS_CTRL_write_en1_src(data)                                                 ((0x00000002&(data))>>1)
#define VPS_CTRL_get_write_en1(data)                                                 ((0x00000002&(data))>>1)
#define VPS_CTRL_vbi_vps_ebl_shift                                                   (0)
#define VPS_CTRL_vbi_vps_ebl_mask                                                    (0x00000001)
#define VPS_CTRL_vbi_vps_ebl(data)                                                   (0x00000001&((data)<<0))
#define VPS_CTRL_vbi_vps_ebl_src(data)                                               ((0x00000001&(data))>>0)
#define VPS_CTRL_get_vbi_vps_ebl(data)                                               ((0x00000001&(data))>>0)


#define VPS_DATA_0                                                                   0x1801F1A0
#define VPS_DATA_1                                                                   0x1801F1A4
#define VPS_DATA_2                                                                   0x1801F1A8
#define VPS_DATA_0_reg_addr                                                          "0xB800A1A0"
#define VPS_DATA_1_reg_addr                                                          "0xB800A1A4"
#define VPS_DATA_2_reg_addr                                                          "0xB800A1A8"
#define VPS_DATA_0_reg                                                              0xB801F1A0
#define VPS_DATA_1_reg                                                              0xB801F1A4
#define VPS_DATA_2_reg                                                              0xB801F1A8
#define set_VPS_DATA_0_reg(data)   (*((volatile unsigned int*) VPS_DATA_0_reg)=data)
#define set_VPS_DATA_1_reg(data)   (*((volatile unsigned int*) VPS_DATA_1_reg)=data)
#define set_VPS_DATA_2_reg(data)   (*((volatile unsigned int*) VPS_DATA_2_reg)=data)
#define get_VPS_DATA_0_reg   (*((volatile unsigned int*) VPS_DATA_0_reg))
#define get_VPS_DATA_1_reg   (*((volatile unsigned int*) VPS_DATA_1_reg))
#define get_VPS_DATA_2_reg   (*((volatile unsigned int*) VPS_DATA_2_reg))
#define VPS_DATA_0_inst_adr                                                          "0x0068"
#define VPS_DATA_1_inst_adr                                                          "0x0069"
#define VPS_DATA_2_inst_adr                                                          "0x006A"
#define VPS_DATA_0_inst                                                              0x0068
#define VPS_DATA_1_inst                                                              0x0069
#define VPS_DATA_2_inst                                                              0x006A
#define VPS_DATA_vps_data_shift                                                      (0)
#define VPS_DATA_vps_data_mask                                                       (0xFFFFFFFF)
#define VPS_DATA_vps_data(data)                                                      (0xFFFFFFFF&((data)<<0))
#define VPS_DATA_vps_data_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define VPS_DATA_get_vps_data(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define VPS_DATA1                                                                    0x1801F1ac
#define VPS_DATA1_reg_addr                                                           "0xB800A1AC"
#define VPS_DATA1_reg                                                               0xB801F1AC
#define set_VPS_DATA1_reg(data)   (*((volatile unsigned int*) VPS_DATA1_reg)=data)
#define get_VPS_DATA1_reg   (*((volatile unsigned int*) VPS_DATA1_reg))
#define VPS_DATA1_inst_adr                                                           "0x006B"
#define VPS_DATA1_inst                                                               0x006B
#define VPS_DATA1_vps_data_shift                                                     (0)
#define VPS_DATA1_vps_data_mask                                                      (0x000000FF)
#define VPS_DATA1_vps_data(data)                                                     (0x000000FF&((data)<<0))
#define VPS_DATA1_vps_data_src(data)                                                 ((0x000000FF&(data))>>0)
#define VPS_DATA1_get_vps_data(data)                                                 ((0x000000FF&(data))>>0)


#define VBI_DWN_CTRL                                                                 0x1801F314
#define VBI_DWN_CTRL_reg_addr                                                        "0xB800A314"
#define VBI_DWN_CTRL_reg                                                            0xB801F314
#define set_VBI_DWN_CTRL_reg(data)   (*((volatile unsigned int*) VBI_DWN_CTRL_reg)=data)
#define get_VBI_DWN_CTRL_reg   (*((volatile unsigned int*) VBI_DWN_CTRL_reg))
#define VBI_DWN_CTRL_inst_adr                                                        "0x00C5"
#define VBI_DWN_CTRL_inst                                                            0x00C5
#define VBI_DWN_CTRL_write_en4_shift                                                 (31)
#define VBI_DWN_CTRL_write_en4_mask                                                  (0x80000000)
#define VBI_DWN_CTRL_write_en4(data)                                                 (0x80000000&((data)<<31))
#define VBI_DWN_CTRL_write_en4_src(data)                                             ((0x80000000&(data))>>31)
#define VBI_DWN_CTRL_get_write_en4(data)                                             ((0x80000000&(data))>>31)
#define VBI_DWN_CTRL_dwn_ebl_shift                                                   (29)
#define VBI_DWN_CTRL_dwn_ebl_mask                                                    (0x60000000)
#define VBI_DWN_CTRL_dwn_ebl(data)                                                   (0x60000000&((data)<<29))
#define VBI_DWN_CTRL_dwn_ebl_src(data)                                               ((0x60000000&(data))>>29)
#define VBI_DWN_CTRL_get_dwn_ebl(data)                                               ((0x60000000&(data))>>29)
#define VBI_DWN_CTRL_write_en3_shift                                                 (28)
#define VBI_DWN_CTRL_write_en3_mask                                                  (0x10000000)
#define VBI_DWN_CTRL_write_en3(data)                                                 (0x10000000&((data)<<28))
#define VBI_DWN_CTRL_write_en3_src(data)                                             ((0x10000000&(data))>>28)
#define VBI_DWN_CTRL_get_write_en3(data)                                             ((0x10000000&(data))>>28)
#define VBI_DWN_CTRL_dwn_i_p_sel_shift                                               (27)
#define VBI_DWN_CTRL_dwn_i_p_sel_mask                                                (0x08000000)
#define VBI_DWN_CTRL_dwn_i_p_sel(data)                                               (0x08000000&((data)<<27))
#define VBI_DWN_CTRL_dwn_i_p_sel_src(data)                                           ((0x08000000&(data))>>27)
#define VBI_DWN_CTRL_get_dwn_i_p_sel(data)                                           ((0x08000000&(data))>>27)
#define VBI_DWN_CTRL_write_en2_shift                                                 (26)
#define VBI_DWN_CTRL_write_en2_mask                                                  (0x04000000)
#define VBI_DWN_CTRL_write_en2(data)                                                 (0x04000000&((data)<<26))
#define VBI_DWN_CTRL_write_en2_src(data)                                             ((0x04000000&(data))>>26)
#define VBI_DWN_CTRL_get_write_en2(data)                                             ((0x04000000&(data))>>26)
#define VBI_DWN_CTRL_dwn_st_i_shift                                                  (14)
#define VBI_DWN_CTRL_dwn_st_i_mask                                                   (0x03FFC000)
#define VBI_DWN_CTRL_dwn_st_i(data)                                                  (0x03FFC000&((data)<<14))
#define VBI_DWN_CTRL_dwn_st_i_src(data)                                              ((0x03FFC000&(data))>>14)
#define VBI_DWN_CTRL_get_dwn_st_i(data)                                              ((0x03FFC000&(data))>>14)
#define VBI_DWN_CTRL_write_en1_shift                                                 (13)
#define VBI_DWN_CTRL_write_en1_mask                                                  (0x00002000)
#define VBI_DWN_CTRL_write_en1(data)                                                 (0x00002000&((data)<<13))
#define VBI_DWN_CTRL_write_en1_src(data)                                             ((0x00002000&(data))>>13)
#define VBI_DWN_CTRL_get_write_en1(data)                                             ((0x00002000&(data))>>13)
#define VBI_DWN_CTRL_dwn_end_i_shift                                                 (0)
#define VBI_DWN_CTRL_dwn_end_i_mask                                                  (0x00001FFF)
#define VBI_DWN_CTRL_dwn_end_i(data)                                                 (0x00001FFF&((data)<<0))
#define VBI_DWN_CTRL_dwn_end_i_src(data)                                             ((0x00001FFF&(data))>>0)
#define VBI_DWN_CTRL_get_dwn_end_i(data)                                             ((0x00001FFF&(data))>>0)


#define VBI_DWN_HPOS                                                                 0x1801F318
#define VBI_DWN_HPOS_reg_addr                                                        "0xB800A318"
#define VBI_DWN_HPOS_reg                                                            0xB801F318
#define set_VBI_DWN_HPOS_reg(data)   (*((volatile unsigned int*) VBI_DWN_HPOS_reg)=data)
#define get_VBI_DWN_HPOS_reg   (*((volatile unsigned int*) VBI_DWN_HPOS_reg))
#define VBI_DWN_HPOS_inst_adr                                                        "0x00C6"
#define VBI_DWN_HPOS_inst                                                            0x00C6
#define VBI_DWN_HPOS_write_en2_shift                                                 (26)
#define VBI_DWN_HPOS_write_en2_mask                                                  (0x04000000)
#define VBI_DWN_HPOS_write_en2(data)                                                 (0x04000000&((data)<<26))
#define VBI_DWN_HPOS_write_en2_src(data)                                             ((0x04000000&(data))>>26)
#define VBI_DWN_HPOS_get_write_en2(data)                                             ((0x04000000&(data))>>26)
#define VBI_DWN_HPOS_dwn_st_p_shift                                                  (14)
#define VBI_DWN_HPOS_dwn_st_p_mask                                                   (0x03FFC000)
#define VBI_DWN_HPOS_dwn_st_p(data)                                                  (0x03FFC000&((data)<<14))
#define VBI_DWN_HPOS_dwn_st_p_src(data)                                              ((0x03FFC000&(data))>>14)
#define VBI_DWN_HPOS_get_dwn_st_p(data)                                              ((0x03FFC000&(data))>>14)
#define VBI_DWN_HPOS_write_en1_shift                                                 (13)
#define VBI_DWN_HPOS_write_en1_mask                                                  (0x00002000)
#define VBI_DWN_HPOS_write_en1(data)                                                 (0x00002000&((data)<<13))
#define VBI_DWN_HPOS_write_en1_src(data)                                             ((0x00002000&(data))>>13)
#define VBI_DWN_HPOS_get_write_en1(data)                                             ((0x00002000&(data))>>13)
#define VBI_DWN_HPOS_dwn_end_p_shift                                                 (0)
#define VBI_DWN_HPOS_dwn_end_p_mask                                                  (0x00001FFF)
#define VBI_DWN_HPOS_dwn_end_p(data)                                                 (0x00001FFF&((data)<<0))
#define VBI_DWN_HPOS_dwn_end_p_src(data)                                             ((0x00001FFF&(data))>>0)
#define VBI_DWN_HPOS_get_dwn_end_p(data)                                             ((0x00001FFF&(data))>>0)


#define VBI_DWN_VPOS_I                                                               0x1801F31c
#define VBI_DWN_VPOS_I_reg_addr                                                      "0xB800A31C"
#define VBI_DWN_VPOS_I_reg                                                          0xB801F31C
#define set_VBI_DWN_VPOS_I_reg(data)   (*((volatile unsigned int*) VBI_DWN_VPOS_I_reg)=data)
#define get_VBI_DWN_VPOS_I_reg   (*((volatile unsigned int*) VBI_DWN_VPOS_I_reg))
#define VBI_DWN_VPOS_I_inst_adr                                                      "0x00C7"
#define VBI_DWN_VPOS_I_inst                                                          0x00C7
#define VBI_DWN_VPOS_I_write_en2_shift                                               (23)
#define VBI_DWN_VPOS_I_write_en2_mask                                                (0x00800000)
#define VBI_DWN_VPOS_I_write_en2(data)                                               (0x00800000&((data)<<23))
#define VBI_DWN_VPOS_I_write_en2_src(data)                                           ((0x00800000&(data))>>23)
#define VBI_DWN_VPOS_I_get_write_en2(data)                                           ((0x00800000&(data))>>23)
#define VBI_DWN_VPOS_I_vbi_start_line2_shift                                         (12)
#define VBI_DWN_VPOS_I_vbi_start_line2_mask                                          (0x007FF000)
#define VBI_DWN_VPOS_I_vbi_start_line2(data)                                         (0x007FF000&((data)<<12))
#define VBI_DWN_VPOS_I_vbi_start_line2_src(data)                                     ((0x007FF000&(data))>>12)
#define VBI_DWN_VPOS_I_get_vbi_start_line2(data)                                     ((0x007FF000&(data))>>12)
#define VBI_DWN_VPOS_I_write_en1_shift                                               (11)
#define VBI_DWN_VPOS_I_write_en1_mask                                                (0x00000800)
#define VBI_DWN_VPOS_I_write_en1(data)                                               (0x00000800&((data)<<11))
#define VBI_DWN_VPOS_I_write_en1_src(data)                                           ((0x00000800&(data))>>11)
#define VBI_DWN_VPOS_I_get_write_en1(data)                                           ((0x00000800&(data))>>11)
#define VBI_DWN_VPOS_I_vbi_start_line1_shift                                         (0)
#define VBI_DWN_VPOS_I_vbi_start_line1_mask                                          (0x000007FF)
#define VBI_DWN_VPOS_I_vbi_start_line1(data)                                         (0x000007FF&((data)<<0))
#define VBI_DWN_VPOS_I_vbi_start_line1_src(data)                                     ((0x000007FF&(data))>>0)
#define VBI_DWN_VPOS_I_get_vbi_start_line1(data)                                     ((0x000007FF&(data))>>0)


#define VBI_DWN_VPOS_P                                                               0x1801F320
#define VBI_DWN_VPOS_P_reg_addr                                                      "0xB800A320"
#define VBI_DWN_VPOS_P_reg                                                          0xB801F320
#define set_VBI_DWN_VPOS_P_reg(data)   (*((volatile unsigned int*) VBI_DWN_VPOS_P_reg)=data)
#define get_VBI_DWN_VPOS_P_reg   (*((volatile unsigned int*) VBI_DWN_VPOS_P_reg))
#define VBI_DWN_VPOS_P_inst_adr                                                      "0x00C8"
#define VBI_DWN_VPOS_P_inst                                                          0x00C8
#define VBI_DWN_VPOS_P_write_en2_shift                                               (23)
#define VBI_DWN_VPOS_P_write_en2_mask                                                (0x00800000)
#define VBI_DWN_VPOS_P_write_en2(data)                                               (0x00800000&((data)<<23))
#define VBI_DWN_VPOS_P_write_en2_src(data)                                           ((0x00800000&(data))>>23)
#define VBI_DWN_VPOS_P_get_write_en2(data)                                           ((0x00800000&(data))>>23)
#define VBI_DWN_VPOS_P_vbi_start_line2_shift                                         (12)
#define VBI_DWN_VPOS_P_vbi_start_line2_mask                                          (0x007FF000)
#define VBI_DWN_VPOS_P_vbi_start_line2(data)                                         (0x007FF000&((data)<<12))
#define VBI_DWN_VPOS_P_vbi_start_line2_src(data)                                     ((0x007FF000&(data))>>12)
#define VBI_DWN_VPOS_P_get_vbi_start_line2(data)                                     ((0x007FF000&(data))>>12)
#define VBI_DWN_VPOS_P_write_en1_shift                                               (11)
#define VBI_DWN_VPOS_P_write_en1_mask                                                (0x00000800)
#define VBI_DWN_VPOS_P_write_en1(data)                                               (0x00000800&((data)<<11))
#define VBI_DWN_VPOS_P_write_en1_src(data)                                           ((0x00000800&(data))>>11)
#define VBI_DWN_VPOS_P_get_write_en1(data)                                           ((0x00000800&(data))>>11)
#define VBI_DWN_VPOS_P_vbi_start_line1_shift                                         (0)
#define VBI_DWN_VPOS_P_vbi_start_line1_mask                                          (0x000007FF)
#define VBI_DWN_VPOS_P_vbi_start_line1(data)                                         (0x000007FF&((data)<<0))
#define VBI_DWN_VPOS_P_vbi_start_line1_src(data)                                     ((0x000007FF&(data))>>0)
#define VBI_DWN_VPOS_P_get_vbi_start_line1(data)                                     ((0x000007FF&(data))>>0)


#define VBI_LINE_FLAG_I_0                                                            0x1801F324
#define VBI_LINE_FLAG_I_1                                                            0x1801F328
#define VBI_LINE_FLAG_I_0_reg_addr                                                   "0xB800A324"
#define VBI_LINE_FLAG_I_1_reg_addr                                                   "0xB800A328"
#define VBI_LINE_FLAG_I_0_reg                                                       0xB801F324
#define VBI_LINE_FLAG_I_1_reg                                                       0xB801F328
#define set_VBI_LINE_FLAG_I_0_reg(data)   (*((volatile unsigned int*) VBI_LINE_FLAG_I_0_reg)=data)
#define set_VBI_LINE_FLAG_I_1_reg(data)   (*((volatile unsigned int*) VBI_LINE_FLAG_I_1_reg)=data)
#define get_VBI_LINE_FLAG_I_0_reg   (*((volatile unsigned int*) VBI_LINE_FLAG_I_0_reg))
#define get_VBI_LINE_FLAG_I_1_reg   (*((volatile unsigned int*) VBI_LINE_FLAG_I_1_reg))
#define VBI_LINE_FLAG_I_0_inst_adr                                                   "0x00C9"
#define VBI_LINE_FLAG_I_1_inst_adr                                                   "0x00CA"
#define VBI_LINE_FLAG_I_0_inst                                                       0x00C9
#define VBI_LINE_FLAG_I_1_inst                                                       0x00CA
#define VBI_LINE_FLAG_I_vbi_line_flg_shift                                           (0)
#define VBI_LINE_FLAG_I_vbi_line_flg_mask                                            (0xFFFFFFFF)
#define VBI_LINE_FLAG_I_vbi_line_flg(data)                                           (0xFFFFFFFF&((data)<<0))
#define VBI_LINE_FLAG_I_vbi_line_flg_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define VBI_LINE_FLAG_I_get_vbi_line_flg(data)                                       ((0xFFFFFFFF&(data))>>0)


#define VBI_LINE_FLAG_P_0                                                            0x1801F32C
#define VBI_LINE_FLAG_P_1                                                            0x1801F330
#define VBI_LINE_FLAG_P_0_reg_addr                                                   "0xB800A32C"
#define VBI_LINE_FLAG_P_1_reg_addr                                                   "0xB800A330"
#define VBI_LINE_FLAG_P_0_reg                                                       0xB801F32C
#define VBI_LINE_FLAG_P_1_reg                                                       0xB801F330
#define set_VBI_LINE_FLAG_P_0_reg(data)   (*((volatile unsigned int*) VBI_LINE_FLAG_P_0_reg)=data)
#define set_VBI_LINE_FLAG_P_1_reg(data)   (*((volatile unsigned int*) VBI_LINE_FLAG_P_1_reg)=data)
#define get_VBI_LINE_FLAG_P_0_reg   (*((volatile unsigned int*) VBI_LINE_FLAG_P_0_reg))
#define get_VBI_LINE_FLAG_P_1_reg   (*((volatile unsigned int*) VBI_LINE_FLAG_P_1_reg))
#define VBI_LINE_FLAG_P_0_inst_adr                                                   "0x00CB"
#define VBI_LINE_FLAG_P_1_inst_adr                                                   "0x00CC"
#define VBI_LINE_FLAG_P_0_inst                                                       0x00CB
#define VBI_LINE_FLAG_P_1_inst                                                       0x00CC
#define VBI_LINE_FLAG_P_vbi_line_flg_shift                                           (0)
#define VBI_LINE_FLAG_P_vbi_line_flg_mask                                            (0xFFFFFFFF)
#define VBI_LINE_FLAG_P_vbi_line_flg(data)                                           (0xFFFFFFFF&((data)<<0))
#define VBI_LINE_FLAG_P_vbi_line_flg_src(data)                                       ((0xFFFFFFFF&(data))>>0)
#define VBI_LINE_FLAG_P_get_vbi_line_flg(data)                                       ((0xFFFFFFFF&(data))>>0)


#define VBI_LINE_PTY_I_0                                                             0x1801F334
#define VBI_LINE_PTY_I_1                                                             0x1801F338
#define VBI_LINE_PTY_I_0_reg_addr                                                    "0xB800A334"
#define VBI_LINE_PTY_I_1_reg_addr                                                    "0xB800A338"
#define VBI_LINE_PTY_I_0_reg                                                        0xB801F334
#define VBI_LINE_PTY_I_1_reg                                                        0xB801F338
#define set_VBI_LINE_PTY_I_0_reg(data)   (*((volatile unsigned int*) VBI_LINE_PTY_I_0_reg)=data)
#define set_VBI_LINE_PTY_I_1_reg(data)   (*((volatile unsigned int*) VBI_LINE_PTY_I_1_reg)=data)
#define get_VBI_LINE_PTY_I_0_reg   (*((volatile unsigned int*) VBI_LINE_PTY_I_0_reg))
#define get_VBI_LINE_PTY_I_1_reg   (*((volatile unsigned int*) VBI_LINE_PTY_I_1_reg))
#define VBI_LINE_PTY_I_0_inst_adr                                                    "0x00CD"
#define VBI_LINE_PTY_I_1_inst_adr                                                    "0x00CE"
#define VBI_LINE_PTY_I_0_inst                                                        0x00CD
#define VBI_LINE_PTY_I_1_inst                                                        0x00CE
#define VBI_LINE_PTY_I_vbi_pty_shift                                                 (0)
#define VBI_LINE_PTY_I_vbi_pty_mask                                                  (0xFFFFFFFF)
#define VBI_LINE_PTY_I_vbi_pty(data)                                                 (0xFFFFFFFF&((data)<<0))
#define VBI_LINE_PTY_I_vbi_pty_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define VBI_LINE_PTY_I_get_vbi_pty(data)                                             ((0xFFFFFFFF&(data))>>0)


#define VBI_LINE_PTY_P_0                                                             0x1801F33C
#define VBI_LINE_PTY_P_1                                                             0x1801F340
#define VBI_LINE_PTY_P_0_reg_addr                                                    "0xB800A33C"
#define VBI_LINE_PTY_P_1_reg_addr                                                    "0xB800A340"
#define VBI_LINE_PTY_P_0_reg                                                        0xB801F33C
#define VBI_LINE_PTY_P_1_reg                                                        0xB801F340
#define set_VBI_LINE_PTY_P_0_reg(data)   (*((volatile unsigned int*) VBI_LINE_PTY_P_0_reg)=data)
#define set_VBI_LINE_PTY_P_1_reg(data)   (*((volatile unsigned int*) VBI_LINE_PTY_P_1_reg)=data)
#define get_VBI_LINE_PTY_P_0_reg   (*((volatile unsigned int*) VBI_LINE_PTY_P_0_reg))
#define get_VBI_LINE_PTY_P_1_reg   (*((volatile unsigned int*) VBI_LINE_PTY_P_1_reg))
#define VBI_LINE_PTY_P_0_inst_adr                                                    "0x00CF"
#define VBI_LINE_PTY_P_1_inst_adr                                                    "0x00D0"
#define VBI_LINE_PTY_P_0_inst                                                        0x00CF
#define VBI_LINE_PTY_P_1_inst                                                        0x00D0
#define VBI_LINE_PTY_P_vbi_pty_shift                                                 (0)
#define VBI_LINE_PTY_P_vbi_pty_mask                                                  (0xFFFFFFFF)
#define VBI_LINE_PTY_P_vbi_pty(data)                                                 (0xFFFFFFFF&((data)<<0))
#define VBI_LINE_PTY_P_vbi_pty_src(data)                                             ((0xFFFFFFFF&(data))>>0)
#define VBI_LINE_PTY_P_get_vbi_pty(data)                                             ((0xFFFFFFFF&(data))>>0)


#define DIF_HACTIVE                                                                  0x1801F1b0
#define DIF_HACTIVE_reg_addr                                                         "0xB800A1B0"
#define DIF_HACTIVE_reg                                                             0xB801F1B0
#define set_DIF_HACTIVE_reg(data)   (*((volatile unsigned int*) DIF_HACTIVE_reg)=data)
#define get_DIF_HACTIVE_reg   (*((volatile unsigned int*) DIF_HACTIVE_reg))
#define DIF_HACTIVE_inst_adr                                                         "0x006C"
#define DIF_HACTIVE_inst                                                             0x006C
#define DIF_HACTIVE_write_en3_shift                                                  (30)
#define DIF_HACTIVE_write_en3_mask                                                   (0x40000000)
#define DIF_HACTIVE_write_en3(data)                                                  (0x40000000&((data)<<30))
#define DIF_HACTIVE_write_en3_src(data)                                              ((0x40000000&(data))>>30)
#define DIF_HACTIVE_get_write_en3(data)                                              ((0x40000000&(data))>>30)
#define DIF_HACTIVE_di_i_p_sel_shift                                                 (28)
#define DIF_HACTIVE_di_i_p_sel_mask                                                  (0x30000000)
#define DIF_HACTIVE_di_i_p_sel(data)                                                 (0x30000000&((data)<<28))
#define DIF_HACTIVE_di_i_p_sel_src(data)                                             ((0x30000000&(data))>>28)
#define DIF_HACTIVE_get_di_i_p_sel(data)                                             ((0x30000000&(data))>>28)
#define DIF_HACTIVE_write_en2_shift                                                  (27)
#define DIF_HACTIVE_write_en2_mask                                                   (0x08000000)
#define DIF_HACTIVE_write_en2(data)                                                  (0x08000000&((data)<<27))
#define DIF_HACTIVE_write_en2_src(data)                                              ((0x08000000&(data))>>27)
#define DIF_HACTIVE_get_write_en2(data)                                              ((0x08000000&(data))>>27)
#define DIF_HACTIVE_hact_start_shift                                                 (14)
#define DIF_HACTIVE_hact_start_mask                                                  (0x07FFC000)
#define DIF_HACTIVE_hact_start(data)                                                 (0x07FFC000&((data)<<14))
#define DIF_HACTIVE_hact_start_src(data)                                             ((0x07FFC000&(data))>>14)
#define DIF_HACTIVE_get_hact_start(data)                                             ((0x07FFC000&(data))>>14)
#define DIF_HACTIVE_write_en1_shift                                                  (13)
#define DIF_HACTIVE_write_en1_mask                                                   (0x00002000)
#define DIF_HACTIVE_write_en1(data)                                                  (0x00002000&((data)<<13))
#define DIF_HACTIVE_write_en1_src(data)                                              ((0x00002000&(data))>>13)
#define DIF_HACTIVE_get_write_en1(data)                                              ((0x00002000&(data))>>13)
#define DIF_HACTIVE_hact_end_shift                                                   (0)
#define DIF_HACTIVE_hact_end_mask                                                    (0x00001FFF)
#define DIF_HACTIVE_hact_end(data)                                                   (0x00001FFF&((data)<<0))
#define DIF_HACTIVE_hact_end_src(data)                                               ((0x00001FFF&(data))>>0)
#define DIF_HACTIVE_get_hact_end(data)                                               ((0x00001FFF&(data))>>0)


#define DIF_CTRL                                                                     0x1801F1b4
#define DIF_CTRL_reg_addr                                                            "0xB800A1B4"
#define DIF_CTRL_reg                                                                0xB801F1B4
#define set_DIF_CTRL_reg(data)   (*((volatile unsigned int*) DIF_CTRL_reg)=data)
#define get_DIF_CTRL_reg   (*((volatile unsigned int*) DIF_CTRL_reg))
#define DIF_CTRL_inst_adr                                                            "0x006D"
#define DIF_CTRL_inst                                                                0x006D
#define DIF_CTRL_cd_shift                                                            (9)
#define DIF_CTRL_cd_mask                                                             (0x00000200)
#define DIF_CTRL_cd(data)                                                            (0x00000200&((data)<<9))
#define DIF_CTRL_cd_src(data)                                                        ((0x00000200&(data))>>9)
#define DIF_CTRL_get_cd(data)                                                        ((0x00000200&(data))>>9)
#define DIF_CTRL_di_bus_swap_shift                                                   (8)
#define DIF_CTRL_di_bus_swap_mask                                                    (0x00000100)
#define DIF_CTRL_di_bus_swap(data)                                                   (0x00000100&((data)<<8))
#define DIF_CTRL_di_bus_swap_src(data)                                               ((0x00000100&(data))>>8)
#define DIF_CTRL_get_di_bus_swap(data)                                               ((0x00000100&(data))>>8)
#define DIF_CTRL_di_clk_phs_shift                                                    (7)
#define DIF_CTRL_di_clk_phs_mask                                                     (0x00000080)
#define DIF_CTRL_di_clk_phs(data)                                                    (0x00000080&((data)<<7))
#define DIF_CTRL_di_clk_phs_src(data)                                                ((0x00000080&(data))>>7)
#define DIF_CTRL_get_di_clk_phs(data)                                                ((0x00000080&(data))>>7)
#define DIF_CTRL_di_fpga_clk_sel_shift                                               (6)
#define DIF_CTRL_di_fpga_clk_sel_mask                                                (0x00000040)
#define DIF_CTRL_di_fpga_clk_sel(data)                                               (0x00000040&((data)<<6))
#define DIF_CTRL_di_fpga_clk_sel_src(data)                                           ((0x00000040&(data))>>6)
#define DIF_CTRL_get_di_fpga_clk_sel(data)                                           ((0x00000040&(data))>>6)
#define DIF_CTRL_di_vbi_bypass_shift                                                 (5)
#define DIF_CTRL_di_vbi_bypass_mask                                                  (0x00000020)
#define DIF_CTRL_di_vbi_bypass(data)                                                 (0x00000020&((data)<<5))
#define DIF_CTRL_di_vbi_bypass_src(data)                                             ((0x00000020&(data))>>5)
#define DIF_CTRL_get_di_vbi_bypass(data)                                             ((0x00000020&(data))>>5)
#define DIF_CTRL_di_ebl_shift                                                        (4)
#define DIF_CTRL_di_ebl_mask                                                         (0x00000010)
#define DIF_CTRL_di_ebl(data)                                                        (0x00000010&((data)<<4))
#define DIF_CTRL_di_ebl_src(data)                                                    ((0x00000010&(data))>>4)
#define DIF_CTRL_get_di_ebl(data)                                                    ((0x00000010&(data))>>4)
#define DIF_CTRL_di_source_sel_shift                                                 (3)
#define DIF_CTRL_di_source_sel_mask                                                  (0x00000008)
#define DIF_CTRL_di_source_sel(data)                                                 (0x00000008&((data)<<3))
#define DIF_CTRL_di_source_sel_src(data)                                             ((0x00000008&(data))>>3)
#define DIF_CTRL_get_di_source_sel(data)                                             ((0x00000008&(data))>>3)
#define DIF_CTRL_di_mod_shift                                                        (2)
#define DIF_CTRL_di_mod_mask                                                         (0x00000004)
#define DIF_CTRL_di_mod(data)                                                        (0x00000004&((data)<<2))
#define DIF_CTRL_di_mod_src(data)                                                    ((0x00000004&(data))>>2)
#define DIF_CTRL_get_di_mod(data)                                                    ((0x00000004&(data))>>2)
#define DIF_CTRL_di_hdr_ebl_shift                                                    (1)
#define DIF_CTRL_di_hdr_ebl_mask                                                     (0x00000002)
#define DIF_CTRL_di_hdr_ebl(data)                                                    (0x00000002&((data)<<1))
#define DIF_CTRL_di_hdr_ebl_src(data)                                                ((0x00000002&(data))>>1)
#define DIF_CTRL_get_di_hdr_ebl(data)                                                ((0x00000002&(data))>>1)
#define DIF_CTRL_write_data_shift                                                    (0)
#define DIF_CTRL_write_data_mask                                                     (0x00000001)
#define DIF_CTRL_write_data(data)                                                    (0x00000001&((data)<<0))
#define DIF_CTRL_write_data_src(data)                                                ((0x00000001&(data))>>0)
#define DIF_CTRL_get_write_data(data)                                                ((0x00000001&(data))>>0)


#define DIF_HSYNC                                                                    0x1801F1b8
#define DIF_HSYNC_reg_addr                                                           "0xB800A1B8"
#define DIF_HSYNC_reg                                                               0xB801F1B8
#define set_DIF_HSYNC_reg(data)   (*((volatile unsigned int*) DIF_HSYNC_reg)=data)
#define get_DIF_HSYNC_reg   (*((volatile unsigned int*) DIF_HSYNC_reg))
#define DIF_HSYNC_inst_adr                                                           "0x006E"
#define DIF_HSYNC_inst                                                               0x006E
#define DIF_HSYNC_write_en3_shift                                                    (29)
#define DIF_HSYNC_write_en3_mask                                                     (0x20000000)
#define DIF_HSYNC_write_en3(data)                                                    (0x20000000&((data)<<29))
#define DIF_HSYNC_write_en3_src(data)                                                ((0x20000000&(data))>>29)
#define DIF_HSYNC_get_write_en3(data)                                                ((0x20000000&(data))>>29)
#define DIF_HSYNC_hs_polar_shift                                                     (28)
#define DIF_HSYNC_hs_polar_mask                                                      (0x10000000)
#define DIF_HSYNC_hs_polar(data)                                                     (0x10000000&((data)<<28))
#define DIF_HSYNC_hs_polar_src(data)                                                 ((0x10000000&(data))>>28)
#define DIF_HSYNC_get_hs_polar(data)                                                 ((0x10000000&(data))>>28)
#define DIF_HSYNC_write_en2_shift                                                    (27)
#define DIF_HSYNC_write_en2_mask                                                     (0x08000000)
#define DIF_HSYNC_write_en2(data)                                                    (0x08000000&((data)<<27))
#define DIF_HSYNC_write_en2_src(data)                                                ((0x08000000&(data))>>27)
#define DIF_HSYNC_get_write_en2(data)                                                ((0x08000000&(data))>>27)
#define DIF_HSYNC_hs_start_shift                                                     (14)
#define DIF_HSYNC_hs_start_mask                                                      (0x07FFC000)
#define DIF_HSYNC_hs_start(data)                                                     (0x07FFC000&((data)<<14))
#define DIF_HSYNC_hs_start_src(data)                                                 ((0x07FFC000&(data))>>14)
#define DIF_HSYNC_get_hs_start(data)                                                 ((0x07FFC000&(data))>>14)
#define DIF_HSYNC_write_en1_shift                                                    (13)
#define DIF_HSYNC_write_en1_mask                                                     (0x00002000)
#define DIF_HSYNC_write_en1(data)                                                    (0x00002000&((data)<<13))
#define DIF_HSYNC_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define DIF_HSYNC_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define DIF_HSYNC_hs_end_shift                                                       (0)
#define DIF_HSYNC_hs_end_mask                                                        (0x00001FFF)
#define DIF_HSYNC_hs_end(data)                                                       (0x00001FFF&((data)<<0))
#define DIF_HSYNC_hs_end_src(data)                                                   ((0x00001FFF&(data))>>0)
#define DIF_HSYNC_get_hs_end(data)                                                   ((0x00001FFF&(data))>>0)


#define DIF_VS_ST_POS1                                                               0x1801F1bc
#define DIF_VS_ST_POS1_reg_addr                                                      "0xB800A1BC"
#define DIF_VS_ST_POS1_reg                                                          0xB801F1BC
#define set_DIF_VS_ST_POS1_reg(data)   (*((volatile unsigned int*) DIF_VS_ST_POS1_reg)=data)
#define get_DIF_VS_ST_POS1_reg   (*((volatile unsigned int*) DIF_VS_ST_POS1_reg))
#define DIF_VS_ST_POS1_inst_adr                                                      "0x006F"
#define DIF_VS_ST_POS1_inst                                                          0x006F
#define DIF_VS_ST_POS1_write_en3_shift                                               (27)
#define DIF_VS_ST_POS1_write_en3_mask                                                (0x08000000)
#define DIF_VS_ST_POS1_write_en3(data)                                               (0x08000000&((data)<<27))
#define DIF_VS_ST_POS1_write_en3_src(data)                                           ((0x08000000&(data))>>27)
#define DIF_VS_ST_POS1_get_write_en3(data)                                           ((0x08000000&(data))>>27)
#define DIF_VS_ST_POS1_vs_polar_shift                                                (26)
#define DIF_VS_ST_POS1_vs_polar_mask                                                 (0x04000000)
#define DIF_VS_ST_POS1_vs_polar(data)                                                (0x04000000&((data)<<26))
#define DIF_VS_ST_POS1_vs_polar_src(data)                                            ((0x04000000&(data))>>26)
#define DIF_VS_ST_POS1_get_vs_polar(data)                                            ((0x04000000&(data))>>26)
#define DIF_VS_ST_POS1_write_en2_shift                                               (25)
#define DIF_VS_ST_POS1_write_en2_mask                                                (0x02000000)
#define DIF_VS_ST_POS1_write_en2(data)                                               (0x02000000&((data)<<25))
#define DIF_VS_ST_POS1_write_en2_src(data)                                           ((0x02000000&(data))>>25)
#define DIF_VS_ST_POS1_get_write_en2(data)                                           ((0x02000000&(data))>>25)
#define DIF_VS_ST_POS1_vs_st_pos1v_shift                                             (14)
#define DIF_VS_ST_POS1_vs_st_pos1v_mask                                              (0x01FFC000)
#define DIF_VS_ST_POS1_vs_st_pos1v(data)                                             (0x01FFC000&((data)<<14))
#define DIF_VS_ST_POS1_vs_st_pos1v_src(data)                                         ((0x01FFC000&(data))>>14)
#define DIF_VS_ST_POS1_get_vs_st_pos1v(data)                                         ((0x01FFC000&(data))>>14)
#define DIF_VS_ST_POS1_write_en1_shift                                               (13)
#define DIF_VS_ST_POS1_write_en1_mask                                                (0x00002000)
#define DIF_VS_ST_POS1_write_en1(data)                                               (0x00002000&((data)<<13))
#define DIF_VS_ST_POS1_write_en1_src(data)                                           ((0x00002000&(data))>>13)
#define DIF_VS_ST_POS1_get_write_en1(data)                                           ((0x00002000&(data))>>13)
#define DIF_VS_ST_POS1_vs_st_pos1h_shift                                             (0)
#define DIF_VS_ST_POS1_vs_st_pos1h_mask                                              (0x00001FFF)
#define DIF_VS_ST_POS1_vs_st_pos1h(data)                                             (0x00001FFF&((data)<<0))
#define DIF_VS_ST_POS1_vs_st_pos1h_src(data)                                         ((0x00001FFF&(data))>>0)
#define DIF_VS_ST_POS1_get_vs_st_pos1h(data)                                         ((0x00001FFF&(data))>>0)


#define DIF_VS_END_POS1                                                              0x1801F1c0
#define DIF_VS_END_POS1_reg_addr                                                     "0xB800A1C0"
#define DIF_VS_END_POS1_reg                                                         0xB801F1C0
#define set_DIF_VS_END_POS1_reg(data)   (*((volatile unsigned int*) DIF_VS_END_POS1_reg)=data)
#define get_DIF_VS_END_POS1_reg   (*((volatile unsigned int*) DIF_VS_END_POS1_reg))
#define DIF_VS_END_POS1_inst_adr                                                     "0x0070"
#define DIF_VS_END_POS1_inst                                                         0x0070
#define DIF_VS_END_POS1_write_en2_shift                                              (25)
#define DIF_VS_END_POS1_write_en2_mask                                               (0x02000000)
#define DIF_VS_END_POS1_write_en2(data)                                              (0x02000000&((data)<<25))
#define DIF_VS_END_POS1_write_en2_src(data)                                          ((0x02000000&(data))>>25)
#define DIF_VS_END_POS1_get_write_en2(data)                                          ((0x02000000&(data))>>25)
#define DIF_VS_END_POS1_vs_end_pos1v_shift                                           (14)
#define DIF_VS_END_POS1_vs_end_pos1v_mask                                            (0x01FFC000)
#define DIF_VS_END_POS1_vs_end_pos1v(data)                                           (0x01FFC000&((data)<<14))
#define DIF_VS_END_POS1_vs_end_pos1v_src(data)                                       ((0x01FFC000&(data))>>14)
#define DIF_VS_END_POS1_get_vs_end_pos1v(data)                                       ((0x01FFC000&(data))>>14)
#define DIF_VS_END_POS1_write_en1_shift                                              (13)
#define DIF_VS_END_POS1_write_en1_mask                                               (0x00002000)
#define DIF_VS_END_POS1_write_en1(data)                                              (0x00002000&((data)<<13))
#define DIF_VS_END_POS1_write_en1_src(data)                                          ((0x00002000&(data))>>13)
#define DIF_VS_END_POS1_get_write_en1(data)                                          ((0x00002000&(data))>>13)
#define DIF_VS_END_POS1_vs_end_pos1h_shift                                           (0)
#define DIF_VS_END_POS1_vs_end_pos1h_mask                                            (0x00001FFF)
#define DIF_VS_END_POS1_vs_end_pos1h(data)                                           (0x00001FFF&((data)<<0))
#define DIF_VS_END_POS1_vs_end_pos1h_src(data)                                       ((0x00001FFF&(data))>>0)
#define DIF_VS_END_POS1_get_vs_end_pos1h(data)                                       ((0x00001FFF&(data))>>0)


#define DIF_VS_ST_POS2                                                               0x1801F1c4
#define DIF_VS_ST_POS2_reg_addr                                                      "0xB800A1C4"
#define DIF_VS_ST_POS2_reg                                                          0xB801F1C4
#define set_DIF_VS_ST_POS2_reg(data)   (*((volatile unsigned int*) DIF_VS_ST_POS2_reg)=data)
#define get_DIF_VS_ST_POS2_reg   (*((volatile unsigned int*) DIF_VS_ST_POS2_reg))
#define DIF_VS_ST_POS2_inst_adr                                                      "0x0071"
#define DIF_VS_ST_POS2_inst                                                          0x0071
#define DIF_VS_ST_POS2_write_en2_shift                                               (25)
#define DIF_VS_ST_POS2_write_en2_mask                                                (0x02000000)
#define DIF_VS_ST_POS2_write_en2(data)                                               (0x02000000&((data)<<25))
#define DIF_VS_ST_POS2_write_en2_src(data)                                           ((0x02000000&(data))>>25)
#define DIF_VS_ST_POS2_get_write_en2(data)                                           ((0x02000000&(data))>>25)
#define DIF_VS_ST_POS2_vs_st_pos2v_shift                                             (14)
#define DIF_VS_ST_POS2_vs_st_pos2v_mask                                              (0x01FFC000)
#define DIF_VS_ST_POS2_vs_st_pos2v(data)                                             (0x01FFC000&((data)<<14))
#define DIF_VS_ST_POS2_vs_st_pos2v_src(data)                                         ((0x01FFC000&(data))>>14)
#define DIF_VS_ST_POS2_get_vs_st_pos2v(data)                                         ((0x01FFC000&(data))>>14)
#define DIF_VS_ST_POS2_write_en1_shift                                               (13)
#define DIF_VS_ST_POS2_write_en1_mask                                                (0x00002000)
#define DIF_VS_ST_POS2_write_en1(data)                                               (0x00002000&((data)<<13))
#define DIF_VS_ST_POS2_write_en1_src(data)                                           ((0x00002000&(data))>>13)
#define DIF_VS_ST_POS2_get_write_en1(data)                                           ((0x00002000&(data))>>13)
#define DIF_VS_ST_POS2_vs_st_pos2h_shift                                             (0)
#define DIF_VS_ST_POS2_vs_st_pos2h_mask                                              (0x00001FFF)
#define DIF_VS_ST_POS2_vs_st_pos2h(data)                                             (0x00001FFF&((data)<<0))
#define DIF_VS_ST_POS2_vs_st_pos2h_src(data)                                         ((0x00001FFF&(data))>>0)
#define DIF_VS_ST_POS2_get_vs_st_pos2h(data)                                         ((0x00001FFF&(data))>>0)


#define DIF_VS_END_POS2                                                              0x1801F1c8
#define DIF_VS_END_POS2_reg_addr                                                     "0xB800A1C8"
#define DIF_VS_END_POS2_reg                                                         0xB801F1C8
#define set_DIF_VS_END_POS2_reg(data)   (*((volatile unsigned int*) DIF_VS_END_POS2_reg)=data)
#define get_DIF_VS_END_POS2_reg   (*((volatile unsigned int*) DIF_VS_END_POS2_reg))
#define DIF_VS_END_POS2_inst_adr                                                     "0x0072"
#define DIF_VS_END_POS2_inst                                                         0x0072
#define DIF_VS_END_POS2_write_en2_shift                                              (25)
#define DIF_VS_END_POS2_write_en2_mask                                               (0x02000000)
#define DIF_VS_END_POS2_write_en2(data)                                              (0x02000000&((data)<<25))
#define DIF_VS_END_POS2_write_en2_src(data)                                          ((0x02000000&(data))>>25)
#define DIF_VS_END_POS2_get_write_en2(data)                                          ((0x02000000&(data))>>25)
#define DIF_VS_END_POS2_vs_end_pos2v_shift                                           (14)
#define DIF_VS_END_POS2_vs_end_pos2v_mask                                            (0x01FFC000)
#define DIF_VS_END_POS2_vs_end_pos2v(data)                                           (0x01FFC000&((data)<<14))
#define DIF_VS_END_POS2_vs_end_pos2v_src(data)                                       ((0x01FFC000&(data))>>14)
#define DIF_VS_END_POS2_get_vs_end_pos2v(data)                                       ((0x01FFC000&(data))>>14)
#define DIF_VS_END_POS2_write_en1_shift                                              (13)
#define DIF_VS_END_POS2_write_en1_mask                                               (0x00002000)
#define DIF_VS_END_POS2_write_en1(data)                                              (0x00002000&((data)<<13))
#define DIF_VS_END_POS2_write_en1_src(data)                                          ((0x00002000&(data))>>13)
#define DIF_VS_END_POS2_get_write_en1(data)                                          ((0x00002000&(data))>>13)
#define DIF_VS_END_POS2_vs_end_pos2h_shift                                           (0)
#define DIF_VS_END_POS2_vs_end_pos2h_mask                                            (0x00001FFF)
#define DIF_VS_END_POS2_vs_end_pos2h(data)                                           (0x00001FFF&((data)<<0))
#define DIF_VS_END_POS2_vs_end_pos2h_src(data)                                       ((0x00001FFF&(data))>>0)
#define DIF_VS_END_POS2_get_vs_end_pos2h(data)                                       ((0x00001FFF&(data))>>0)


#define DIF_F_BIT_POS                                                                0x1801F1cc
#define DIF_F_BIT_POS_reg_addr                                                       "0xB800A1CC"
#define DIF_F_BIT_POS_reg                                                           0xB801F1CC
#define set_DIF_F_BIT_POS_reg(data)   (*((volatile unsigned int*) DIF_F_BIT_POS_reg)=data)
#define get_DIF_F_BIT_POS_reg   (*((volatile unsigned int*) DIF_F_BIT_POS_reg))
#define DIF_F_BIT_POS_inst_adr                                                       "0x0073"
#define DIF_F_BIT_POS_inst                                                           0x0073
#define DIF_F_BIT_POS_write_en2_shift                                                (23)
#define DIF_F_BIT_POS_write_en2_mask                                                 (0x00800000)
#define DIF_F_BIT_POS_write_en2(data)                                                (0x00800000&((data)<<23))
#define DIF_F_BIT_POS_write_en2_src(data)                                            ((0x00800000&(data))>>23)
#define DIF_F_BIT_POS_get_write_en2(data)                                            ((0x00800000&(data))>>23)
#define DIF_F_BIT_POS_v_tgl_hi_shift                                                 (12)
#define DIF_F_BIT_POS_v_tgl_hi_mask                                                  (0x007FF000)
#define DIF_F_BIT_POS_v_tgl_hi(data)                                                 (0x007FF000&((data)<<12))
#define DIF_F_BIT_POS_v_tgl_hi_src(data)                                             ((0x007FF000&(data))>>12)
#define DIF_F_BIT_POS_get_v_tgl_hi(data)                                             ((0x007FF000&(data))>>12)
#define DIF_F_BIT_POS_write_en1_shift                                                (11)
#define DIF_F_BIT_POS_write_en1_mask                                                 (0x00000800)
#define DIF_F_BIT_POS_write_en1(data)                                                (0x00000800&((data)<<11))
#define DIF_F_BIT_POS_write_en1_src(data)                                            ((0x00000800&(data))>>11)
#define DIF_F_BIT_POS_get_write_en1(data)                                            ((0x00000800&(data))>>11)
#define DIF_F_BIT_POS_v_tgl_lo_shift                                                 (0)
#define DIF_F_BIT_POS_v_tgl_lo_mask                                                  (0x000007FF)
#define DIF_F_BIT_POS_v_tgl_lo(data)                                                 (0x000007FF&((data)<<0))
#define DIF_F_BIT_POS_v_tgl_lo_src(data)                                             ((0x000007FF&(data))>>0)
#define DIF_F_BIT_POS_get_v_tgl_lo(data)                                             ((0x000007FF&(data))>>0)


#define DIF_V_BIT_POS1                                                               0x1801F1d0
#define DIF_V_BIT_POS1_reg_addr                                                      "0xB800A1D0"
#define DIF_V_BIT_POS1_reg                                                          0xB801F1D0
#define set_DIF_V_BIT_POS1_reg(data)   (*((volatile unsigned int*) DIF_V_BIT_POS1_reg)=data)
#define get_DIF_V_BIT_POS1_reg   (*((volatile unsigned int*) DIF_V_BIT_POS1_reg))
#define DIF_V_BIT_POS1_inst_adr                                                      "0x0074"
#define DIF_V_BIT_POS1_inst                                                          0x0074
#define DIF_V_BIT_POS1_write_en2_shift                                               (23)
#define DIF_V_BIT_POS1_write_en2_mask                                                (0x00800000)
#define DIF_V_BIT_POS1_write_en2(data)                                               (0x00800000&((data)<<23))
#define DIF_V_BIT_POS1_write_en2_src(data)                                           ((0x00800000&(data))>>23)
#define DIF_V_BIT_POS1_get_write_en2(data)                                           ((0x00800000&(data))>>23)
#define DIF_V_BIT_POS1_v_tgl1_hi_shift                                               (12)
#define DIF_V_BIT_POS1_v_tgl1_hi_mask                                                (0x007FF000)
#define DIF_V_BIT_POS1_v_tgl1_hi(data)                                               (0x007FF000&((data)<<12))
#define DIF_V_BIT_POS1_v_tgl1_hi_src(data)                                           ((0x007FF000&(data))>>12)
#define DIF_V_BIT_POS1_get_v_tgl1_hi(data)                                           ((0x007FF000&(data))>>12)
#define DIF_V_BIT_POS1_write_en1_shift                                               (11)
#define DIF_V_BIT_POS1_write_en1_mask                                                (0x00000800)
#define DIF_V_BIT_POS1_write_en1(data)                                               (0x00000800&((data)<<11))
#define DIF_V_BIT_POS1_write_en1_src(data)                                           ((0x00000800&(data))>>11)
#define DIF_V_BIT_POS1_get_write_en1(data)                                           ((0x00000800&(data))>>11)
#define DIF_V_BIT_POS1_v_tgl1_lo_shift                                               (0)
#define DIF_V_BIT_POS1_v_tgl1_lo_mask                                                (0x000007FF)
#define DIF_V_BIT_POS1_v_tgl1_lo(data)                                               (0x000007FF&((data)<<0))
#define DIF_V_BIT_POS1_v_tgl1_lo_src(data)                                           ((0x000007FF&(data))>>0)
#define DIF_V_BIT_POS1_get_v_tgl1_lo(data)                                           ((0x000007FF&(data))>>0)


#define DIF_V_BIT_POS2                                                               0x1801F1d4
#define DIF_V_BIT_POS2_reg_addr                                                      "0xB800A1D4"
#define DIF_V_BIT_POS2_reg                                                          0xB801F1D4
#define set_DIF_V_BIT_POS2_reg(data)   (*((volatile unsigned int*) DIF_V_BIT_POS2_reg)=data)
#define get_DIF_V_BIT_POS2_reg   (*((volatile unsigned int*) DIF_V_BIT_POS2_reg))
#define DIF_V_BIT_POS2_inst_adr                                                      "0x0075"
#define DIF_V_BIT_POS2_inst                                                          0x0075
#define DIF_V_BIT_POS2_write_en2_shift                                               (23)
#define DIF_V_BIT_POS2_write_en2_mask                                                (0x00800000)
#define DIF_V_BIT_POS2_write_en2(data)                                               (0x00800000&((data)<<23))
#define DIF_V_BIT_POS2_write_en2_src(data)                                           ((0x00800000&(data))>>23)
#define DIF_V_BIT_POS2_get_write_en2(data)                                           ((0x00800000&(data))>>23)
#define DIF_V_BIT_POS2_v_tgl2_hi_shift                                               (12)
#define DIF_V_BIT_POS2_v_tgl2_hi_mask                                                (0x007FF000)
#define DIF_V_BIT_POS2_v_tgl2_hi(data)                                               (0x007FF000&((data)<<12))
#define DIF_V_BIT_POS2_v_tgl2_hi_src(data)                                           ((0x007FF000&(data))>>12)
#define DIF_V_BIT_POS2_get_v_tgl2_hi(data)                                           ((0x007FF000&(data))>>12)
#define DIF_V_BIT_POS2_write_en1_shift                                               (11)
#define DIF_V_BIT_POS2_write_en1_mask                                                (0x00000800)
#define DIF_V_BIT_POS2_write_en1(data)                                               (0x00000800&((data)<<11))
#define DIF_V_BIT_POS2_write_en1_src(data)                                           ((0x00000800&(data))>>11)
#define DIF_V_BIT_POS2_get_write_en1(data)                                           ((0x00000800&(data))>>11)
#define DIF_V_BIT_POS2_v_tgl2_lo_shift                                               (0)
#define DIF_V_BIT_POS2_v_tgl2_lo_mask                                                (0x000007FF)
#define DIF_V_BIT_POS2_v_tgl2_lo(data)                                               (0x000007FF&((data)<<0))
#define DIF_V_BIT_POS2_v_tgl2_lo_src(data)                                           ((0x000007FF&(data))>>0)
#define DIF_V_BIT_POS2_get_v_tgl2_lo(data)                                           ((0x000007FF&(data))>>0)


#define DIF_FV_BIT_HPOS                                                              0x1801F1d8
#define DIF_FV_BIT_HPOS_reg_addr                                                     "0xB800A1D8"
#define DIF_FV_BIT_HPOS_reg                                                         0xB801F1D8
#define set_DIF_FV_BIT_HPOS_reg(data)   (*((volatile unsigned int*) DIF_FV_BIT_HPOS_reg)=data)
#define get_DIF_FV_BIT_HPOS_reg   (*((volatile unsigned int*) DIF_FV_BIT_HPOS_reg))
#define DIF_FV_BIT_HPOS_inst_adr                                                     "0x0076"
#define DIF_FV_BIT_HPOS_inst                                                         0x0076
#define DIF_FV_BIT_HPOS_write_en2_shift                                              (27)
#define DIF_FV_BIT_HPOS_write_en2_mask                                               (0x08000000)
#define DIF_FV_BIT_HPOS_write_en2(data)                                              (0x08000000&((data)<<27))
#define DIF_FV_BIT_HPOS_write_en2_src(data)                                          ((0x08000000&(data))>>27)
#define DIF_FV_BIT_HPOS_get_write_en2(data)                                          ((0x08000000&(data))>>27)
#define DIF_FV_BIT_HPOS_fv_start_shift                                               (14)
#define DIF_FV_BIT_HPOS_fv_start_mask                                                (0x07FFC000)
#define DIF_FV_BIT_HPOS_fv_start(data)                                               (0x07FFC000&((data)<<14))
#define DIF_FV_BIT_HPOS_fv_start_src(data)                                           ((0x07FFC000&(data))>>14)
#define DIF_FV_BIT_HPOS_get_fv_start(data)                                           ((0x07FFC000&(data))>>14)
#define DIF_FV_BIT_HPOS_write_en1_shift                                              (13)
#define DIF_FV_BIT_HPOS_write_en1_mask                                               (0x00002000)
#define DIF_FV_BIT_HPOS_write_en1(data)                                              (0x00002000&((data)<<13))
#define DIF_FV_BIT_HPOS_write_en1_src(data)                                          ((0x00002000&(data))>>13)
#define DIF_FV_BIT_HPOS_get_write_en1(data)                                          ((0x00002000&(data))>>13)
#define DIF_FV_BIT_HPOS_fv_end_shift                                                 (0)
#define DIF_FV_BIT_HPOS_fv_end_mask                                                  (0x00001FFF)
#define DIF_FV_BIT_HPOS_fv_end(data)                                                 (0x00001FFF&((data)<<0))
#define DIF_FV_BIT_HPOS_fv_end_src(data)                                             ((0x00001FFF&(data))>>0)
#define DIF_FV_BIT_HPOS_get_fv_end(data)                                             ((0x00001FFF&(data))>>0)


#define IP_PHS_0                                                                     0x1801F880
#define IP_PHS_1                                                                     0x1801F884
#define IP_PHS_2                                                                     0x1801F888
#define IP_PHS_3                                                                     0x1801F88C
#define IP_PHS_0_reg_addr                                                            "0xB800A880"
#define IP_PHS_1_reg_addr                                                            "0xB800A884"
#define IP_PHS_2_reg_addr                                                            "0xB800A888"
#define IP_PHS_3_reg_addr                                                            "0xB800A88C"
#define IP_PHS_0_reg                                                                0xB801F880
#define IP_PHS_1_reg                                                                0xB801F884
#define IP_PHS_2_reg                                                                0xB801F888
#define IP_PHS_3_reg                                                                0xB801F88C
#define set_IP_PHS_0_reg(data)   (*((volatile unsigned int*) IP_PHS_0_reg)=data)
#define set_IP_PHS_1_reg(data)   (*((volatile unsigned int*) IP_PHS_1_reg)=data)
#define set_IP_PHS_2_reg(data)   (*((volatile unsigned int*) IP_PHS_2_reg)=data)
#define set_IP_PHS_3_reg(data)   (*((volatile unsigned int*) IP_PHS_3_reg)=data)
#define get_IP_PHS_0_reg   (*((volatile unsigned int*) IP_PHS_0_reg))
#define get_IP_PHS_1_reg   (*((volatile unsigned int*) IP_PHS_1_reg))
#define get_IP_PHS_2_reg   (*((volatile unsigned int*) IP_PHS_2_reg))
#define get_IP_PHS_3_reg   (*((volatile unsigned int*) IP_PHS_3_reg))
#define IP_PHS_0_inst_adr                                                            "0x0020"
#define IP_PHS_1_inst_adr                                                            "0x0021"
#define IP_PHS_2_inst_adr                                                            "0x0022"
#define IP_PHS_3_inst_adr                                                            "0x0023"
#define IP_PHS_0_inst                                                                0x0020
#define IP_PHS_1_inst                                                                0x0021
#define IP_PHS_2_inst                                                                0x0022
#define IP_PHS_3_inst                                                                0x0023
#define IP_PHS_phi_shift                                                             (0)
#define IP_PHS_phi_mask                                                              (0x000000FF)
#define IP_PHS_phi(data)                                                             (0x000000FF&((data)<<0))
#define IP_PHS_phi_src(data)                                                         ((0x000000FF&(data))>>0)
#define IP_PHS_get_phi(data)                                                         ((0x000000FF&(data))>>0)


#define IP_SCTOH_0                                                                   0x1801F890
#define IP_SCTOH_1                                                                   0x1801F894
#define IP_SCTOH_2                                                                   0x1801F898
#define IP_SCTOH_3                                                                   0x1801F89C
#define IP_SCTOH_0_reg_addr                                                          "0xB800A890"
#define IP_SCTOH_1_reg_addr                                                          "0xB800A894"
#define IP_SCTOH_2_reg_addr                                                          "0xB800A898"
#define IP_SCTOH_3_reg_addr                                                          "0xB800A89C"
#define IP_SCTOH_0_reg                                                              0xB801F890
#define IP_SCTOH_1_reg                                                              0xB801F894
#define IP_SCTOH_2_reg                                                              0xB801F898
#define IP_SCTOH_3_reg                                                              0xB801F89C
#define set_IP_SCTOH_0_reg(data)   (*((volatile unsigned int*) IP_SCTOH_0_reg)=data)
#define set_IP_SCTOH_1_reg(data)   (*((volatile unsigned int*) IP_SCTOH_1_reg)=data)
#define set_IP_SCTOH_2_reg(data)   (*((volatile unsigned int*) IP_SCTOH_2_reg)=data)
#define set_IP_SCTOH_3_reg(data)   (*((volatile unsigned int*) IP_SCTOH_3_reg)=data)
#define get_IP_SCTOH_0_reg   (*((volatile unsigned int*) IP_SCTOH_0_reg))
#define get_IP_SCTOH_1_reg   (*((volatile unsigned int*) IP_SCTOH_1_reg))
#define get_IP_SCTOH_2_reg   (*((volatile unsigned int*) IP_SCTOH_2_reg))
#define get_IP_SCTOH_3_reg   (*((volatile unsigned int*) IP_SCTOH_3_reg))
#define IP_SCTOH_0_inst_adr                                                          "0x0024"
#define IP_SCTOH_1_inst_adr                                                          "0x0025"
#define IP_SCTOH_2_inst_adr                                                          "0x0026"
#define IP_SCTOH_3_inst_adr                                                          "0x0027"
#define IP_SCTOH_0_inst                                                              0x0024
#define IP_SCTOH_1_inst                                                              0x0025
#define IP_SCTOH_2_inst                                                              0x0026
#define IP_SCTOH_3_inst                                                              0x0027
#define IP_SCTOH_sctoh_shift                                                         (0)
#define IP_SCTOH_sctoh_mask                                                          (0x000000FF)
#define IP_SCTOH_sctoh(data)                                                         (0x000000FF&((data)<<0))
#define IP_SCTOH_sctoh_src(data)                                                     ((0x000000FF&(data))>>0)
#define IP_SCTOH_get_sctoh(data)                                                     ((0x000000FF&(data))>>0)


#define IP_F_CTRL                                                                    0x1801F8a0
#define IP_F_CTRL_reg_addr                                                           "0xB800A8A0"
#define IP_F_CTRL_reg                                                               0xB801F8A0
#define set_IP_F_CTRL_reg(data)   (*((volatile unsigned int*) IP_F_CTRL_reg)=data)
#define get_IP_F_CTRL_reg   (*((volatile unsigned int*) IP_F_CTRL_reg))
#define IP_F_CTRL_inst_adr                                                           "0x0028"
#define IP_F_CTRL_inst                                                               0x0028
#define IP_F_CTRL_u_invert_shift                                                     (3)
#define IP_F_CTRL_u_invert_mask                                                      (0x00000008)
#define IP_F_CTRL_u_invert(data)                                                     (0x00000008&((data)<<3))
#define IP_F_CTRL_u_invert_src(data)                                                 ((0x00000008&(data))>>3)
#define IP_F_CTRL_get_u_invert(data)                                                 ((0x00000008&(data))>>3)
#define IP_F_CTRL_v_invert_shift                                                     (2)
#define IP_F_CTRL_v_invert_mask                                                      (0x00000004)
#define IP_F_CTRL_v_invert(data)                                                     (0x00000004&((data)<<2))
#define IP_F_CTRL_v_invert_src(data)                                                 ((0x00000004&(data))>>2)
#define IP_F_CTRL_get_v_invert(data)                                                 ((0x00000004&(data))>>2)
#define IP_F_CTRL_t_offset_phase_shift                                               (1)
#define IP_F_CTRL_t_offset_phase_mask                                                (0x00000002)
#define IP_F_CTRL_t_offset_phase(data)                                               (0x00000002&((data)<<1))
#define IP_F_CTRL_t_offset_phase_src(data)                                           ((0x00000002&(data))>>1)
#define IP_F_CTRL_get_t_offset_phase(data)                                           ((0x00000002&(data))>>1)
#define IP_F_CTRL_t_reset_fsc_shift                                                  (0)
#define IP_F_CTRL_t_reset_fsc_mask                                                   (0x00000001)
#define IP_F_CTRL_t_reset_fsc(data)                                                  (0x00000001&((data)<<0))
#define IP_F_CTRL_t_reset_fsc_src(data)                                              ((0x00000001&(data))>>0)
#define IP_F_CTRL_get_t_reset_fsc(data)                                              ((0x00000001&(data))>>0)


#define IP_T_SEL_SIN                                                                 0x1801F980
#define IP_T_SEL_SIN_reg_addr                                                        "0xB800A980"
#define IP_T_SEL_SIN_reg                                                            0xB801F980
#define set_IP_T_SEL_SIN_reg(data)   (*((volatile unsigned int*) IP_T_SEL_SIN_reg)=data)
#define get_IP_T_SEL_SIN_reg   (*((volatile unsigned int*) IP_T_SEL_SIN_reg))
#define IP_T_SEL_SIN_inst_adr                                                        "0x0060"
#define IP_T_SEL_SIN_inst                                                            0x0060
#define IP_T_SEL_SIN_t_sel_sin_shift                                                 (1)
#define IP_T_SEL_SIN_t_sel_sin_mask                                                  (0x00000002)
#define IP_T_SEL_SIN_t_sel_sin(data)                                                 (0x00000002&((data)<<1))
#define IP_T_SEL_SIN_t_sel_sin_src(data)                                             ((0x00000002&(data))>>1)
#define IP_T_SEL_SIN_get_t_sel_sin(data)                                             ((0x00000002&(data))>>1)
#define IP_T_SEL_SIN_t_fsc_rom_shift                                                 (0)
#define IP_T_SEL_SIN_t_fsc_rom_mask                                                  (0x00000001)
#define IP_T_SEL_SIN_t_fsc_rom(data)                                                 (0x00000001&((data)<<0))
#define IP_T_SEL_SIN_t_fsc_rom_src(data)                                             ((0x00000001&(data))>>0)
#define IP_T_SEL_SIN_get_t_fsc_rom(data)                                             ((0x00000001&(data))>>0)


#define IP_BLCK_LVL                                                                  0x1801F8a8
#define IP_BLCK_LVL_reg_addr                                                         "0xB800A8A8"
#define IP_BLCK_LVL_reg                                                             0xB801F8A8
#define set_IP_BLCK_LVL_reg(data)   (*((volatile unsigned int*) IP_BLCK_LVL_reg)=data)
#define get_IP_BLCK_LVL_reg   (*((volatile unsigned int*) IP_BLCK_LVL_reg))
#define IP_BLCK_LVL_inst_adr                                                         "0x002A"
#define IP_BLCK_LVL_inst                                                             0x002A
#define IP_BLCK_LVL_black_lvl_shift                                                  (0)
#define IP_BLCK_LVL_black_lvl_mask                                                   (0x000000FF)
#define IP_BLCK_LVL_black_lvl(data)                                                  (0x000000FF&((data)<<0))
#define IP_BLCK_LVL_black_lvl_src(data)                                              ((0x000000FF&(data))>>0)
#define IP_BLCK_LVL_get_black_lvl(data)                                              ((0x000000FF&(data))>>0)


#define IP_BLNK_LVL                                                                  0x1801F8ac
#define IP_BLNK_LVL_reg_addr                                                         "0xB800A8AC"
#define IP_BLNK_LVL_reg                                                             0xB801F8AC
#define set_IP_BLNK_LVL_reg(data)   (*((volatile unsigned int*) IP_BLNK_LVL_reg)=data)
#define get_IP_BLNK_LVL_reg   (*((volatile unsigned int*) IP_BLNK_LVL_reg))
#define IP_BLNK_LVL_inst_adr                                                         "0x002B"
#define IP_BLNK_LVL_inst                                                             0x002B
#define IP_BLNK_LVL_blank_lvl_shift                                                  (0)
#define IP_BLNK_LVL_blank_lvl_mask                                                   (0x000000FF)
#define IP_BLNK_LVL_blank_lvl(data)                                                  (0x000000FF&((data)<<0))
#define IP_BLNK_LVL_blank_lvl_src(data)                                              ((0x000000FF&(data))>>0)
#define IP_BLNK_LVL_get_blank_lvl(data)                                              ((0x000000FF&(data))>>0)


#define IP_CLAMP_LVL                                                                 0x1801F8b0
#define IP_CLAMP_LVL_reg_addr                                                        "0xB800A8B0"
#define IP_CLAMP_LVL_reg                                                            0xB801F8B0
#define set_IP_CLAMP_LVL_reg(data)   (*((volatile unsigned int*) IP_CLAMP_LVL_reg)=data)
#define get_IP_CLAMP_LVL_reg   (*((volatile unsigned int*) IP_CLAMP_LVL_reg))
#define IP_CLAMP_LVL_inst_adr                                                        "0x002C"
#define IP_CLAMP_LVL_inst                                                            0x002C
#define IP_CLAMP_LVL_clamp_lvl_shift                                                 (0)
#define IP_CLAMP_LVL_clamp_lvl_mask                                                  (0x000000FF)
#define IP_CLAMP_LVL_clamp_lvl(data)                                                 (0x000000FF&((data)<<0))
#define IP_CLAMP_LVL_clamp_lvl_src(data)                                             ((0x000000FF&(data))>>0)
#define IP_CLAMP_LVL_get_clamp_lvl(data)                                             ((0x000000FF&(data))>>0)


#define IP_SYNC_LVL                                                                  0x1801F8b4
#define IP_SYNC_LVL_reg_addr                                                         "0xB800A8B4"
#define IP_SYNC_LVL_reg                                                             0xB801F8B4
#define set_IP_SYNC_LVL_reg(data)   (*((volatile unsigned int*) IP_SYNC_LVL_reg)=data)
#define get_IP_SYNC_LVL_reg   (*((volatile unsigned int*) IP_SYNC_LVL_reg))
#define IP_SYNC_LVL_inst_adr                                                         "0x002D"
#define IP_SYNC_LVL_inst                                                             0x002D
#define IP_SYNC_LVL_sync_lvl_shift                                                   (0)
#define IP_SYNC_LVL_sync_lvl_mask                                                    (0x000000FF)
#define IP_SYNC_LVL_sync_lvl(data)                                                   (0x000000FF&((data)<<0))
#define IP_SYNC_LVL_sync_lvl_src(data)                                               ((0x000000FF&(data))>>0)
#define IP_SYNC_LVL_get_sync_lvl(data)                                               ((0x000000FF&(data))>>0)


#define IP_Y_CTRL                                                                    0x1801F8b8
#define IP_Y_CTRL_reg_addr                                                           "0xB800A8B8"
#define IP_Y_CTRL_reg                                                               0xB801F8B8
#define set_IP_Y_CTRL_reg(data)   (*((volatile unsigned int*) IP_Y_CTRL_reg)=data)
#define get_IP_Y_CTRL_reg   (*((volatile unsigned int*) IP_Y_CTRL_reg))
#define IP_Y_CTRL_inst_adr                                                           "0x002E"
#define IP_Y_CTRL_inst                                                               0x002E
#define IP_Y_CTRL_y_interp_shift                                                     (6)
#define IP_Y_CTRL_y_interp_mask                                                      (0x000000C0)
#define IP_Y_CTRL_y_interp(data)                                                     (0x000000C0&((data)<<6))
#define IP_Y_CTRL_y_interp_src(data)                                                 ((0x000000C0&(data))>>6)
#define IP_Y_CTRL_get_y_interp(data)                                                 ((0x000000C0&(data))>>6)
#define IP_Y_CTRL_y_colorbar_en_shift                                                (5)
#define IP_Y_CTRL_y_colorbar_en_mask                                                 (0x00000020)
#define IP_Y_CTRL_y_colorbar_en(data)                                                (0x00000020&((data)<<5))
#define IP_Y_CTRL_y_colorbar_en_src(data)                                            ((0x00000020&(data))>>5)
#define IP_Y_CTRL_get_y_colorbar_en(data)                                            ((0x00000020&(data))>>5)
#define IP_Y_CTRL_t_ydel_adj_shift                                                   (2)
#define IP_Y_CTRL_t_ydel_adj_mask                                                    (0x0000001C)
#define IP_Y_CTRL_t_ydel_adj(data)                                                   (0x0000001C&((data)<<2))
#define IP_Y_CTRL_t_ydel_adj_src(data)                                               ((0x0000001C&(data))>>2)
#define IP_Y_CTRL_get_t_ydel_adj(data)                                               ((0x0000001C&(data))>>2)
#define IP_Y_CTRL_t_sel_ylpf_shift                                                   (1)
#define IP_Y_CTRL_t_sel_ylpf_mask                                                    (0x00000002)
#define IP_Y_CTRL_t_sel_ylpf(data)                                                   (0x00000002&((data)<<1))
#define IP_Y_CTRL_t_sel_ylpf_src(data)                                               ((0x00000002&(data))>>1)
#define IP_Y_CTRL_get_t_sel_ylpf(data)                                               ((0x00000002&(data))>>1)
#define IP_Y_CTRL_t_ygain_val_shift                                                  (0)
#define IP_Y_CTRL_t_ygain_val_mask                                                   (0x00000001)
#define IP_Y_CTRL_t_ygain_val(data)                                                  (0x00000001&((data)<<0))
#define IP_Y_CTRL_t_ygain_val_src(data)                                              ((0x00000001&(data))>>0)
#define IP_Y_CTRL_get_t_ygain_val(data)                                              ((0x00000001&(data))>>0)


#define IP_TEST_PARAM                                                                0x1801F984
#define IP_TEST_PARAM_reg_addr                                                       "0xB800A984"
#define IP_TEST_PARAM_reg                                                           0xB801F984
#define set_IP_TEST_PARAM_reg(data)   (*((volatile unsigned int*) IP_TEST_PARAM_reg)=data)
#define get_IP_TEST_PARAM_reg   (*((volatile unsigned int*) IP_TEST_PARAM_reg))
#define IP_TEST_PARAM_inst_adr                                                       "0x0061"
#define IP_TEST_PARAM_inst                                                           0x0061
#define IP_TEST_PARAM_t_byp_yups_shift                                               (6)
#define IP_TEST_PARAM_t_byp_yups_mask                                                (0x00000040)
#define IP_TEST_PARAM_t_byp_yups(data)                                               (0x00000040&((data)<<6))
#define IP_TEST_PARAM_t_byp_yups_src(data)                                           ((0x00000040&(data))>>6)
#define IP_TEST_PARAM_get_t_byp_yups(data)                                           ((0x00000040&(data))>>6)
#define IP_TEST_PARAM_t_sel_ylp_shift                                                (5)
#define IP_TEST_PARAM_t_sel_ylp_mask                                                 (0x00000020)
#define IP_TEST_PARAM_t_sel_ylp(data)                                                (0x00000020&((data)<<5))
#define IP_TEST_PARAM_t_sel_ylp_src(data)                                            ((0x00000020&(data))>>5)
#define IP_TEST_PARAM_get_t_sel_ylp(data)                                            ((0x00000020&(data))>>5)
#define IP_TEST_PARAM_t_ygain_off_shift                                              (4)
#define IP_TEST_PARAM_t_ygain_off_mask                                               (0x00000010)
#define IP_TEST_PARAM_t_ygain_off(data)                                              (0x00000010&((data)<<4))
#define IP_TEST_PARAM_t_ygain_off_src(data)                                          ((0x00000010&(data))>>4)
#define IP_TEST_PARAM_get_t_ygain_off(data)                                          ((0x00000010&(data))>>4)
#define IP_TEST_PARAM_y_tsin_cos_shift                                               (3)
#define IP_TEST_PARAM_y_tsin_cos_mask                                                (0x00000008)
#define IP_TEST_PARAM_y_tsin_cos(data)                                               (0x00000008&((data)<<3))
#define IP_TEST_PARAM_y_tsin_cos_src(data)                                           ((0x00000008&(data))>>3)
#define IP_TEST_PARAM_get_y_tsin_cos(data)                                           ((0x00000008&(data))>>3)
#define IP_TEST_PARAM_y_tsel_dac_tst_shift                                           (2)
#define IP_TEST_PARAM_y_tsel_dac_tst_mask                                            (0x00000004)
#define IP_TEST_PARAM_y_tsel_dac_tst(data)                                           (0x00000004&((data)<<2))
#define IP_TEST_PARAM_y_tsel_dac_tst_src(data)                                       ((0x00000004&(data))>>2)
#define IP_TEST_PARAM_get_y_tsel_dac_tst(data)                                       ((0x00000004&(data))>>2)
#define IP_TEST_PARAM_y_tdig_out_shift                                               (0)
#define IP_TEST_PARAM_y_tdig_out_mask                                                (0x00000003)
#define IP_TEST_PARAM_y_tdig_out(data)                                               (0x00000003&((data)<<0))
#define IP_TEST_PARAM_y_tdig_out_src(data)                                           ((0x00000003&(data))>>0)
#define IP_TEST_PARAM_get_y_tdig_out(data)                                           ((0x00000003&(data))>>0)


#define IP_Y_GAIN                                                                    0x1801Fa00
#define IP_Y_GAIN_reg_addr                                                           "0xB800AA00"
#define IP_Y_GAIN_reg                                                               0xB801FA00
#define set_IP_Y_GAIN_reg(data)   (*((volatile unsigned int*) IP_Y_GAIN_reg)=data)
#define get_IP_Y_GAIN_reg   (*((volatile unsigned int*) IP_Y_GAIN_reg))
#define IP_Y_GAIN_inst_adr                                                           "0x0080"
#define IP_Y_GAIN_inst                                                               0x0080
#define IP_Y_GAIN_y_gain_shift                                                       (0)
#define IP_Y_GAIN_y_gain_mask                                                        (0x000003FF)
#define IP_Y_GAIN_y_gain(data)                                                       (0x000003FF&((data)<<0))
#define IP_Y_GAIN_y_gain_src(data)                                                   ((0x000003FF&(data))>>0)
#define IP_Y_GAIN_get_y_gain(data)                                                   ((0x000003FF&(data))>>0)


#define IP_SYNC_LVL2                                                                 0x1801F9c0
#define IP_SYNC_LVL2_reg_addr                                                        "0xB800A9C0"
#define IP_SYNC_LVL2_reg                                                            0xB801F9C0
#define set_IP_SYNC_LVL2_reg(data)   (*((volatile unsigned int*) IP_SYNC_LVL2_reg)=data)
#define get_IP_SYNC_LVL2_reg   (*((volatile unsigned int*) IP_SYNC_LVL2_reg))
#define IP_SYNC_LVL2_inst_adr                                                        "0x0070"
#define IP_SYNC_LVL2_inst                                                            0x0070
#define IP_SYNC_LVL2_sync_lvl_h_shift                                                (0)
#define IP_SYNC_LVL2_sync_lvl_h_mask                                                 (0x000000FF)
#define IP_SYNC_LVL2_sync_lvl_h(data)                                                (0x000000FF&((data)<<0))
#define IP_SYNC_LVL2_sync_lvl_h_src(data)                                            ((0x000000FF&(data))>>0)
#define IP_SYNC_LVL2_get_sync_lvl_h(data)                                            ((0x000000FF&(data))>>0)


#define IP_SYNC_LVL3                                                                 0x1801F9c4
#define IP_SYNC_LVL3_reg_addr                                                        "0xB800A9C4"
#define IP_SYNC_LVL3_reg                                                            0xB801F9C4
#define set_IP_SYNC_LVL3_reg(data)   (*((volatile unsigned int*) IP_SYNC_LVL3_reg)=data)
#define get_IP_SYNC_LVL3_reg   (*((volatile unsigned int*) IP_SYNC_LVL3_reg))
#define IP_SYNC_LVL3_inst_adr                                                        "0x0071"
#define IP_SYNC_LVL3_inst                                                            0x0071
#define IP_SYNC_LVL3_sync_lvl_m_shift                                                (0)
#define IP_SYNC_LVL3_sync_lvl_m_mask                                                 (0x000000FF)
#define IP_SYNC_LVL3_sync_lvl_m(data)                                                (0x000000FF&((data)<<0))
#define IP_SYNC_LVL3_sync_lvl_m_src(data)                                            ((0x000000FF&(data))>>0)
#define IP_SYNC_LVL3_get_sync_lvl_m(data)                                            ((0x000000FF&(data))>>0)


#define IP_SYNC_LVL4                                                                 0x1801F9c8
#define IP_SYNC_LVL4_reg_addr                                                        "0xB800A9C8"
#define IP_SYNC_LVL4_reg                                                            0xB801F9C8
#define set_IP_SYNC_LVL4_reg(data)   (*((volatile unsigned int*) IP_SYNC_LVL4_reg)=data)
#define get_IP_SYNC_LVL4_reg   (*((volatile unsigned int*) IP_SYNC_LVL4_reg))
#define IP_SYNC_LVL4_inst_adr                                                        "0x0072"
#define IP_SYNC_LVL4_inst                                                            0x0072
#define IP_SYNC_LVL4_sync_lvl_l_shift                                                (0)
#define IP_SYNC_LVL4_sync_lvl_l_mask                                                 (0x000000FF)
#define IP_SYNC_LVL4_sync_lvl_l(data)                                                (0x000000FF&((data)<<0))
#define IP_SYNC_LVL4_sync_lvl_l_src(data)                                            ((0x000000FF&(data))>>0)
#define IP_SYNC_LVL4_get_sync_lvl_l(data)                                            ((0x000000FF&(data))>>0)


#define IP_O_CTRL                                                                    0x1801F8bc
#define IP_O_CTRL_reg_addr                                                           "0xB800A8BC"
#define IP_O_CTRL_reg                                                               0xB801F8BC
#define set_IP_O_CTRL_reg(data)   (*((volatile unsigned int*) IP_O_CTRL_reg)=data)
#define get_IP_O_CTRL_reg   (*((volatile unsigned int*) IP_O_CTRL_reg))
#define IP_O_CTRL_inst_adr                                                           "0x002F"
#define IP_O_CTRL_inst                                                               0x002F
#define IP_O_CTRL_y_tsel_yuv_shift                                                   (3)
#define IP_O_CTRL_y_tsel_yuv_mask                                                    (0x00000008)
#define IP_O_CTRL_y_tsel_yuv(data)                                                   (0x00000008&((data)<<3))
#define IP_O_CTRL_y_tsel_yuv_src(data)                                               ((0x00000008&(data))>>3)
#define IP_O_CTRL_get_y_tsel_yuv(data)                                               ((0x00000008&(data))>>3)
#define IP_O_CTRL_t_pd_cvdac_shift                                                   (2)
#define IP_O_CTRL_t_pd_cvdac_mask                                                    (0x00000004)
#define IP_O_CTRL_t_pd_cvdac(data)                                                   (0x00000004&((data)<<2))
#define IP_O_CTRL_t_pd_cvdac_src(data)                                               ((0x00000004&(data))>>2)
#define IP_O_CTRL_get_t_pd_cvdac(data)                                               ((0x00000004&(data))>>2)
#define IP_O_CTRL_t_pd_ydac_shift                                                    (1)
#define IP_O_CTRL_t_pd_ydac_mask                                                     (0x00000002)
#define IP_O_CTRL_t_pd_ydac(data)                                                    (0x00000002&((data)<<1))
#define IP_O_CTRL_t_pd_ydac_src(data)                                                ((0x00000002&(data))>>1)
#define IP_O_CTRL_get_t_pd_ydac(data)                                                ((0x00000002&(data))>>1)
#define IP_O_CTRL_t_pd_cdac_shift                                                    (0)
#define IP_O_CTRL_t_pd_cdac_mask                                                     (0x00000001)
#define IP_O_CTRL_t_pd_cdac(data)                                                    (0x00000001&((data)<<0))
#define IP_O_CTRL_t_pd_cdac_src(data)                                                ((0x00000001&(data))>>0)
#define IP_O_CTRL_get_t_pd_cdac(data)                                                ((0x00000001&(data))>>0)


#define IP_NBA                                                                       0x1801F8c8
#define IP_NBA_reg_addr                                                              "0xB800A8C8"
#define IP_NBA_reg                                                                  0xB801F8C8
#define set_IP_NBA_reg(data)   (*((volatile unsigned int*) IP_NBA_reg)=data)
#define get_IP_NBA_reg   (*((volatile unsigned int*) IP_NBA_reg))
#define IP_NBA_inst_adr                                                              "0x0032"
#define IP_NBA_inst                                                                  0x0032
#define IP_NBA_nba_shift                                                             (0)
#define IP_NBA_nba_mask                                                              (0x000000FF)
#define IP_NBA_nba(data)                                                             (0x000000FF&((data)<<0))
#define IP_NBA_nba_src(data)                                                         ((0x000000FF&(data))>>0)
#define IP_NBA_get_nba(data)                                                         ((0x000000FF&(data))>>0)


#define IP_PBA                                                                       0x1801F8cc
#define IP_PBA_reg_addr                                                              "0xB800A8CC"
#define IP_PBA_reg                                                                  0xB801F8CC
#define set_IP_PBA_reg(data)   (*((volatile unsigned int*) IP_PBA_reg)=data)
#define get_IP_PBA_reg   (*((volatile unsigned int*) IP_PBA_reg))
#define IP_PBA_inst_adr                                                              "0x0033"
#define IP_PBA_inst                                                                  0x0033
#define IP_PBA_pba_shift                                                             (0)
#define IP_PBA_pba_mask                                                              (0x000000FF)
#define IP_PBA_pba(data)                                                             (0x000000FF&((data)<<0))
#define IP_PBA_pba_src(data)                                                         ((0x000000FF&(data))>>0)
#define IP_PBA_get_pba(data)                                                         ((0x000000FF&(data))>>0)


#define IP_C_CTRL                                                                    0x1801F8d0
#define IP_C_CTRL_reg_addr                                                           "0xB800A8D0"
#define IP_C_CTRL_reg                                                               0xB801F8D0
#define set_IP_C_CTRL_reg(data)   (*((volatile unsigned int*) IP_C_CTRL_reg)=data)
#define get_IP_C_CTRL_reg   (*((volatile unsigned int*) IP_C_CTRL_reg))
#define IP_C_CTRL_inst_adr                                                           "0x0034"
#define IP_C_CTRL_inst                                                               0x0034
#define IP_C_CTRL_t_pal_clpf_shift                                                   (1)
#define IP_C_CTRL_t_pal_clpf_mask                                                    (0x00000002)
#define IP_C_CTRL_t_pal_clpf(data)                                                   (0x00000002&((data)<<1))
#define IP_C_CTRL_t_pal_clpf_src(data)                                               ((0x00000002&(data))>>1)
#define IP_C_CTRL_get_t_pal_clpf(data)                                               ((0x00000002&(data))>>1)
#define IP_C_CTRL_t_sel_c_gain_shift                                                 (0)
#define IP_C_CTRL_t_sel_c_gain_mask                                                  (0x00000001)
#define IP_C_CTRL_t_sel_c_gain(data)                                                 (0x00000001&((data)<<0))
#define IP_C_CTRL_t_sel_c_gain_src(data)                                             ((0x00000001&(data))>>0)
#define IP_C_CTRL_get_t_sel_c_gain(data)                                             ((0x00000001&(data))>>0)


#define IP_TEST_T_BYP_CUPS                                                           0x1801F98c
#define IP_TEST_T_BYP_CUPS_reg_addr                                                  "0xB800A98C"
#define IP_TEST_T_BYP_CUPS_reg                                                      0xB801F98C
#define set_IP_TEST_T_BYP_CUPS_reg(data)   (*((volatile unsigned int*) IP_TEST_T_BYP_CUPS_reg)=data)
#define get_IP_TEST_T_BYP_CUPS_reg   (*((volatile unsigned int*) IP_TEST_T_BYP_CUPS_reg))
#define IP_TEST_T_BYP_CUPS_inst_adr                                                  "0x0063"
#define IP_TEST_T_BYP_CUPS_inst                                                      0x0063
#define IP_TEST_T_BYP_CUPS_t_byp_cups_shift                                          (2)
#define IP_TEST_T_BYP_CUPS_t_byp_cups_mask                                           (0x00000004)
#define IP_TEST_T_BYP_CUPS_t_byp_cups(data)                                          (0x00000004&((data)<<2))
#define IP_TEST_T_BYP_CUPS_t_byp_cups_src(data)                                      ((0x00000004&(data))>>2)
#define IP_TEST_T_BYP_CUPS_get_t_byp_cups(data)                                      ((0x00000004&(data))>>2)
#define IP_TEST_T_BYP_CUPS_t_byp_clpf_shift                                          (1)
#define IP_TEST_T_BYP_CUPS_t_byp_clpf_mask                                           (0x00000002)
#define IP_TEST_T_BYP_CUPS_t_byp_clpf(data)                                          (0x00000002&((data)<<1))
#define IP_TEST_T_BYP_CUPS_t_byp_clpf_src(data)                                      ((0x00000002&(data))>>1)
#define IP_TEST_T_BYP_CUPS_get_t_byp_clpf(data)                                      ((0x00000002&(data))>>1)
#define IP_TEST_T_BYP_CUPS_t_c_gain_off_shift                                        (0)
#define IP_TEST_T_BYP_CUPS_t_c_gain_off_mask                                         (0x00000001)
#define IP_TEST_T_BYP_CUPS_t_c_gain_off(data)                                        (0x00000001&((data)<<0))
#define IP_TEST_T_BYP_CUPS_t_c_gain_off_src(data)                                    ((0x00000001&(data))>>0)
#define IP_TEST_T_BYP_CUPS_get_t_c_gain_off(data)                                    ((0x00000001&(data))>>0)


#define IP_SYNCLPF_GAIN                                                              0x1801F9cc
#define IP_SYNCLPF_GAIN_reg_addr                                                     "0xB800A9CC"
#define IP_SYNCLPF_GAIN_reg                                                         0xB801F9CC
#define set_IP_SYNCLPF_GAIN_reg(data)   (*((volatile unsigned int*) IP_SYNCLPF_GAIN_reg)=data)
#define get_IP_SYNCLPF_GAIN_reg   (*((volatile unsigned int*) IP_SYNCLPF_GAIN_reg))
#define IP_SYNCLPF_GAIN_inst_adr                                                     "0x0073"
#define IP_SYNCLPF_GAIN_inst                                                         0x0073
#define IP_SYNCLPF_GAIN_clpf_gain_shift                                              (0)
#define IP_SYNCLPF_GAIN_clpf_gain_mask                                               (0x000000FF)
#define IP_SYNCLPF_GAIN_clpf_gain(data)                                              (0x000000FF&((data)<<0))
#define IP_SYNCLPF_GAIN_clpf_gain_src(data)                                          ((0x000000FF&(data))>>0)
#define IP_SYNCLPF_GAIN_get_clpf_gain(data)                                          ((0x000000FF&(data))>>0)


#define IP_S_CTRL                                                                    0x1801F8e0
#define IP_S_CTRL_reg_addr                                                           "0xB800A8E0"
#define IP_S_CTRL_reg                                                               0xB801F8E0
#define set_IP_S_CTRL_reg(data)   (*((volatile unsigned int*) IP_S_CTRL_reg)=data)
#define get_IP_S_CTRL_reg   (*((volatile unsigned int*) IP_S_CTRL_reg))
#define IP_S_CTRL_inst_adr                                                           "0x0038"
#define IP_S_CTRL_inst                                                               0x0038
#define IP_S_CTRL_t_hsync_phs_shift                                                  (7)
#define IP_S_CTRL_t_hsync_phs_mask                                                   (0x00000080)
#define IP_S_CTRL_t_hsync_phs(data)                                                  (0x00000080&((data)<<7))
#define IP_S_CTRL_t_hsync_phs_src(data)                                              ((0x00000080&(data))>>7)
#define IP_S_CTRL_get_t_hsync_phs(data)                                              ((0x00000080&(data))>>7)
#define IP_S_CTRL_t_vsync_phs_shift                                                  (6)
#define IP_S_CTRL_t_vsync_phs_mask                                                   (0x00000040)
#define IP_S_CTRL_t_vsync_phs(data)                                                  (0x00000040&((data)<<6))
#define IP_S_CTRL_t_vsync_phs_src(data)                                              ((0x00000040&(data))>>6)
#define IP_S_CTRL_get_t_vsync_phs(data)                                              ((0x00000040&(data))>>6)
#define IP_S_CTRL_y_tsyncmode_shift                                                  (3)
#define IP_S_CTRL_y_tsyncmode_mask                                                   (0x00000038)
#define IP_S_CTRL_y_tsyncmode(data)                                                  (0x00000038&((data)<<3))
#define IP_S_CTRL_y_tsyncmode_src(data)                                              ((0x00000038&(data))>>3)
#define IP_S_CTRL_get_y_tsyncmode(data)                                              ((0x00000038&(data))>>3)
#define IP_S_CTRL_y_tencd_mode_shift                                                 (0)
#define IP_S_CTRL_y_tencd_mode_mask                                                  (0x00000007)
#define IP_S_CTRL_y_tencd_mode(data)                                                 (0x00000007&((data)<<0))
#define IP_S_CTRL_y_tencd_mode_src(data)                                             ((0x00000007&(data))>>0)
#define IP_S_CTRL_get_y_tencd_mode(data)                                             ((0x00000007&(data))>>0)


#define IP_VSO0                                                                      0x1801F8e4
#define IP_VSO0_reg_addr                                                             "0xB800A8E4"
#define IP_VSO0_reg                                                                 0xB801F8E4
#define set_IP_VSO0_reg(data)   (*((volatile unsigned int*) IP_VSO0_reg)=data)
#define get_IP_VSO0_reg   (*((volatile unsigned int*) IP_VSO0_reg))
#define IP_VSO0_inst_adr                                                             "0x0039"
#define IP_VSO0_inst                                                                 0x0039
#define IP_VSO0_clk_phs_shift                                                        (6)
#define IP_VSO0_clk_phs_mask                                                         (0x000000C0)
#define IP_VSO0_clk_phs(data)                                                        (0x000000C0&((data)<<6))
#define IP_VSO0_clk_phs_src(data)                                                    ((0x000000C0&(data))>>6)
#define IP_VSO0_get_clk_phs(data)                                                    ((0x000000C0&(data))>>6)
#define IP_VSO0_t_fsync_enbl_shift                                                   (5)
#define IP_VSO0_t_fsync_enbl_mask                                                    (0x00000020)
#define IP_VSO0_t_fsync_enbl(data)                                                   (0x00000020&((data)<<5))
#define IP_VSO0_t_fsync_enbl_src(data)                                               ((0x00000020&(data))>>5)
#define IP_VSO0_get_t_fsync_enbl(data)                                               ((0x00000020&(data))>>5)
#define IP_VSO0_t_fsync_phs_shift                                                    (4)
#define IP_VSO0_t_fsync_phs_mask                                                     (0x00000010)
#define IP_VSO0_t_fsync_phs(data)                                                    (0x00000010&((data)<<4))
#define IP_VSO0_t_fsync_phs_src(data)                                                ((0x00000010&(data))>>4)
#define IP_VSO0_get_t_fsync_phs(data)                                                ((0x00000010&(data))>>4)
#define IP_VSO0_vso_shift                                                            (0)
#define IP_VSO0_vso_mask                                                             (0x00000003)
#define IP_VSO0_vso(data)                                                            (0x00000003&((data)<<0))
#define IP_VSO0_vso_src(data)                                                        ((0x00000003&(data))>>0)
#define IP_VSO0_get_vso(data)                                                        ((0x00000003&(data))>>0)


#define IP_VSO1                                                                      0x1801F8e8
#define IP_VSO1_reg_addr                                                             "0xB800A8E8"
#define IP_VSO1_reg                                                                 0xB801F8E8
#define set_IP_VSO1_reg(data)   (*((volatile unsigned int*) IP_VSO1_reg)=data)
#define get_IP_VSO1_reg   (*((volatile unsigned int*) IP_VSO1_reg))
#define IP_VSO1_inst_adr                                                             "0x003A"
#define IP_VSO1_inst                                                                 0x003A
#define IP_VSO1_vso_shift                                                            (0)
#define IP_VSO1_vso_mask                                                             (0x000000FF)
#define IP_VSO1_vso(data)                                                            (0x000000FF&((data)<<0))
#define IP_VSO1_vso_src(data)                                                        ((0x000000FF&(data))>>0)
#define IP_VSO1_get_vso(data)                                                        ((0x000000FF&(data))>>0)


#define IP_HSO0                                                                      0x1801F8ec
#define IP_HSO0_reg_addr                                                             "0xB800A8EC"
#define IP_HSO0_reg                                                                 0xB801F8EC
#define set_IP_HSO0_reg(data)   (*((volatile unsigned int*) IP_HSO0_reg)=data)
#define get_IP_HSO0_reg   (*((volatile unsigned int*) IP_HSO0_reg))
#define IP_HSO0_inst_adr                                                             "0x003B"
#define IP_HSO0_inst                                                                 0x003B
#define IP_HSO0_hso_shift                                                            (0)
#define IP_HSO0_hso_mask                                                             (0x00000007)
#define IP_HSO0_hso(data)                                                            (0x00000007&((data)<<0))
#define IP_HSO0_hso_src(data)                                                        ((0x00000007&(data))>>0)
#define IP_HSO0_get_hso(data)                                                        ((0x00000007&(data))>>0)


#define IP_HSO1                                                                      0x1801F8f0
#define IP_HSO1_reg_addr                                                             "0xB800A8F0"
#define IP_HSO1_reg                                                                 0xB801F8F0
#define set_IP_HSO1_reg(data)   (*((volatile unsigned int*) IP_HSO1_reg)=data)
#define get_IP_HSO1_reg   (*((volatile unsigned int*) IP_HSO1_reg))
#define IP_HSO1_inst_adr                                                             "0x003C"
#define IP_HSO1_inst                                                                 0x003C
#define IP_HSO1_hso_shift                                                            (0)
#define IP_HSO1_hso_mask                                                             (0x000000FF)
#define IP_HSO1_hso(data)                                                            (0x000000FF&((data)<<0))
#define IP_HSO1_hso_src(data)                                                        ((0x000000FF&(data))>>0)
#define IP_HSO1_get_hso(data)                                                        ((0x000000FF&(data))>>0)


#define IP_HLC0                                                                      0x1801F8f4
#define IP_HLC0_reg_addr                                                             "0xB800A8F4"
#define IP_HLC0_reg                                                                 0xB801F8F4
#define set_IP_HLC0_reg(data)   (*((volatile unsigned int*) IP_HLC0_reg)=data)
#define get_IP_HLC0_reg   (*((volatile unsigned int*) IP_HLC0_reg))
#define IP_HLC0_inst_adr                                                             "0x003D"
#define IP_HLC0_inst                                                                 0x003D
#define IP_HLC0_hlc_shift                                                            (0)
#define IP_HLC0_hlc_mask                                                             (0x00000003)
#define IP_HLC0_hlc(data)                                                            (0x00000003&((data)<<0))
#define IP_HLC0_hlc_src(data)                                                        ((0x00000003&(data))>>0)
#define IP_HLC0_get_hlc(data)                                                        ((0x00000003&(data))>>0)


#define IP_HLC1                                                                      0x1801F8f8
#define IP_HLC1_reg_addr                                                             "0xB800A8F8"
#define IP_HLC1_reg                                                                 0xB801F8F8
#define set_IP_HLC1_reg(data)   (*((volatile unsigned int*) IP_HLC1_reg)=data)
#define get_IP_HLC1_reg   (*((volatile unsigned int*) IP_HLC1_reg))
#define IP_HLC1_inst_adr                                                             "0x003E"
#define IP_HLC1_inst                                                                 0x003E
#define IP_HLC1_hlc_shift                                                            (0)
#define IP_HLC1_hlc_mask                                                             (0x000000FF)
#define IP_HLC1_hlc(data)                                                            (0x000000FF&((data)<<0))
#define IP_HLC1_hlc_src(data)                                                        ((0x000000FF&(data))>>0)
#define IP_HLC1_get_hlc(data)                                                        ((0x000000FF&(data))>>0)


#define IP_CCD_ODD_0                                                                 0x1801F904
#define IP_CCD_ODD_1                                                                 0x1801F908
#define IP_CCD_ODD_0_reg_addr                                                        "0xB800A904"
#define IP_CCD_ODD_1_reg_addr                                                        "0xB800A908"
#define IP_CCD_ODD_0_reg                                                            0xB801F904
#define IP_CCD_ODD_1_reg                                                            0xB801F908
#define set_IP_CCD_ODD_0_reg(data)   (*((volatile unsigned int*) IP_CCD_ODD_0_reg)=data)
#define set_IP_CCD_ODD_1_reg(data)   (*((volatile unsigned int*) IP_CCD_ODD_1_reg)=data)
#define get_IP_CCD_ODD_0_reg   (*((volatile unsigned int*) IP_CCD_ODD_0_reg))
#define get_IP_CCD_ODD_1_reg   (*((volatile unsigned int*) IP_CCD_ODD_1_reg))
#define IP_CCD_ODD_0_inst_adr                                                        "0x0041"
#define IP_CCD_ODD_1_inst_adr                                                        "0x0042"
#define IP_CCD_ODD_0_inst                                                            0x0041
#define IP_CCD_ODD_1_inst                                                            0x0042
#define IP_CCD_ODD_ccd_odd_shift                                                     (0)
#define IP_CCD_ODD_ccd_odd_mask                                                      (0x000000FF)
#define IP_CCD_ODD_ccd_odd(data)                                                     (0x000000FF&((data)<<0))
#define IP_CCD_ODD_ccd_odd_src(data)                                                 ((0x000000FF&(data))>>0)
#define IP_CCD_ODD_get_ccd_odd(data)                                                 ((0x000000FF&(data))>>0)


#define IP_CCD_EVEN_0                                                                0x1801F90C
#define IP_CCD_EVEN_1                                                                0x1801F910
#define IP_CCD_EVEN_0_reg_addr                                                       "0xB800A90C"
#define IP_CCD_EVEN_1_reg_addr                                                       "0xB800A910"
#define IP_CCD_EVEN_0_reg                                                           0xB801F90C
#define IP_CCD_EVEN_1_reg                                                           0xB801F910
#define set_IP_CCD_EVEN_0_reg(data)   (*((volatile unsigned int*) IP_CCD_EVEN_0_reg)=data)
#define set_IP_CCD_EVEN_1_reg(data)   (*((volatile unsigned int*) IP_CCD_EVEN_1_reg)=data)
#define get_IP_CCD_EVEN_0_reg   (*((volatile unsigned int*) IP_CCD_EVEN_0_reg))
#define get_IP_CCD_EVEN_1_reg   (*((volatile unsigned int*) IP_CCD_EVEN_1_reg))
#define IP_CCD_EVEN_0_inst_adr                                                       "0x0043"
#define IP_CCD_EVEN_1_inst_adr                                                       "0x0044"
#define IP_CCD_EVEN_0_inst                                                           0x0043
#define IP_CCD_EVEN_1_inst                                                           0x0044
#define IP_CCD_EVEN_ccd_even_shift                                                   (0)
#define IP_CCD_EVEN_ccd_even_mask                                                    (0x000000FF)
#define IP_CCD_EVEN_ccd_even(data)                                                   (0x000000FF&((data)<<0))
#define IP_CCD_EVEN_ccd_even_src(data)                                               ((0x000000FF&(data))>>0)
#define IP_CCD_EVEN_get_ccd_even(data)                                               ((0x000000FF&(data))>>0)


#define IP_CCD_ENBL                                                                  0x1801F914
#define IP_CCD_ENBL_reg_addr                                                         "0xB800A914"
#define IP_CCD_ENBL_reg                                                             0xB801F914
#define set_IP_CCD_ENBL_reg(data)   (*((volatile unsigned int*) IP_CCD_ENBL_reg)=data)
#define get_IP_CCD_ENBL_reg   (*((volatile unsigned int*) IP_CCD_ENBL_reg))
#define IP_CCD_ENBL_inst_adr                                                         "0x0045"
#define IP_CCD_ENBL_inst                                                             0x0045
#define IP_CCD_ENBL_cc_enbl_shift                                                    (0)
#define IP_CCD_ENBL_cc_enbl_mask                                                     (0x00000003)
#define IP_CCD_ENBL_cc_enbl(data)                                                    (0x00000003&((data)<<0))
#define IP_CCD_ENBL_cc_enbl_src(data)                                                ((0x00000003&(data))>>0)
#define IP_CCD_ENBL_get_cc_enbl(data)                                                ((0x00000003&(data))>>0)


#define IP_TEST_HLR0                                                                 0x1801F9b4
#define IP_TEST_HLR0_reg_addr                                                        "0xB800A9B4"
#define IP_TEST_HLR0_reg                                                            0xB801F9B4
#define set_IP_TEST_HLR0_reg(data)   (*((volatile unsigned int*) IP_TEST_HLR0_reg)=data)
#define get_IP_TEST_HLR0_reg   (*((volatile unsigned int*) IP_TEST_HLR0_reg))
#define IP_TEST_HLR0_inst_adr                                                        "0x006D"
#define IP_TEST_HLR0_inst                                                            0x006D
#define IP_TEST_HLR0_hlr_shift                                                       (0)
#define IP_TEST_HLR0_hlr_mask                                                        (0x00000003)
#define IP_TEST_HLR0_hlr(data)                                                       (0x00000003&((data)<<0))
#define IP_TEST_HLR0_hlr_src(data)                                                   ((0x00000003&(data))>>0)
#define IP_TEST_HLR0_get_hlr(data)                                                   ((0x00000003&(data))>>0)


#define IP_TEST_HLR1                                                                 0x1801F9b8
#define IP_TEST_HLR1_reg_addr                                                        "0xB800A9B8"
#define IP_TEST_HLR1_reg                                                            0xB801F9B8
#define set_IP_TEST_HLR1_reg(data)   (*((volatile unsigned int*) IP_TEST_HLR1_reg)=data)
#define get_IP_TEST_HLR1_reg   (*((volatile unsigned int*) IP_TEST_HLR1_reg))
#define IP_TEST_HLR1_inst_adr                                                        "0x006E"
#define IP_TEST_HLR1_inst                                                            0x006E
#define IP_TEST_HLR1_hlr_shift                                                       (0)
#define IP_TEST_HLR1_hlr_mask                                                        (0x000000FF)
#define IP_TEST_HLR1_hlr(data)                                                       (0x000000FF&((data)<<0))
#define IP_TEST_HLR1_hlr_src(data)                                                   ((0x000000FF&(data))>>0)
#define IP_TEST_HLR1_get_hlr(data)                                                   ((0x000000FF&(data))>>0)


#define IP_TEST_VSMR                                                                 0x1801F9bc
#define IP_TEST_VSMR_reg_addr                                                        "0xB800A9BC"
#define IP_TEST_VSMR_reg                                                            0xB801F9BC
#define set_IP_TEST_VSMR_reg(data)   (*((volatile unsigned int*) IP_TEST_VSMR_reg)=data)
#define get_IP_TEST_VSMR_reg   (*((volatile unsigned int*) IP_TEST_VSMR_reg))
#define IP_TEST_VSMR_inst_adr                                                        "0x006F"
#define IP_TEST_VSMR_inst                                                            0x006F
#define IP_TEST_VSMR_vsmr_shift                                                      (0)
#define IP_TEST_VSMR_vsmr_mask                                                       (0x0000001F)
#define IP_TEST_VSMR_vsmr(data)                                                      (0x0000001F&((data)<<0))
#define IP_TEST_VSMR_vsmr_src(data)                                                  ((0x0000001F&(data))>>0)
#define IP_TEST_VSMR_get_vsmr(data)                                                  ((0x0000001F&(data))>>0)


#define IP_SYNC_STRT                                                                 0x1801F9d0
#define IP_SYNC_STRT_reg_addr                                                        "0xB800A9D0"
#define IP_SYNC_STRT_reg                                                            0xB801F9D0
#define set_IP_SYNC_STRT_reg(data)   (*((volatile unsigned int*) IP_SYNC_STRT_reg)=data)
#define get_IP_SYNC_STRT_reg   (*((volatile unsigned int*) IP_SYNC_STRT_reg))
#define IP_SYNC_STRT_inst_adr                                                        "0x0074"
#define IP_SYNC_STRT_inst                                                            0x0074
#define IP_SYNC_STRT_sync_strt_shift                                                 (0)
#define IP_SYNC_STRT_sync_strt_mask                                                  (0x0000000F)
#define IP_SYNC_STRT_sync_strt(data)                                                 (0x0000000F&((data)<<0))
#define IP_SYNC_STRT_sync_strt_src(data)                                             ((0x0000000F&(data))>>0)
#define IP_SYNC_STRT_get_sync_strt(data)                                             ((0x0000000F&(data))>>0)


#define IP_SYNC_END                                                                  0x1801F9d4
#define IP_SYNC_END_reg_addr                                                         "0xB800A9D4"
#define IP_SYNC_END_reg                                                             0xB801F9D4
#define set_IP_SYNC_END_reg(data)   (*((volatile unsigned int*) IP_SYNC_END_reg)=data)
#define get_IP_SYNC_END_reg   (*((volatile unsigned int*) IP_SYNC_END_reg))
#define IP_SYNC_END_inst_adr                                                         "0x0075"
#define IP_SYNC_END_inst                                                             0x0075
#define IP_SYNC_END_sync_end_shift                                                   (0)
#define IP_SYNC_END_sync_end_mask                                                    (0x0000007F)
#define IP_SYNC_END_sync_end(data)                                                   (0x0000007F&((data)<<0))
#define IP_SYNC_END_sync_end_src(data)                                               ((0x0000007F&(data))>>0)
#define IP_SYNC_END_get_sync_end(data)                                               ((0x0000007F&(data))>>0)


#define IP_SYNC_SREND                                                                0x1801F9d8
#define IP_SYNC_SREND_reg_addr                                                       "0xB800A9D8"
#define IP_SYNC_SREND_reg                                                           0xB801F9D8
#define set_IP_SYNC_SREND_reg(data)   (*((volatile unsigned int*) IP_SYNC_SREND_reg)=data)
#define get_IP_SYNC_SREND_reg   (*((volatile unsigned int*) IP_SYNC_SREND_reg))
#define IP_SYNC_SREND_inst_adr                                                       "0x0076"
#define IP_SYNC_SREND_inst                                                           0x0076
#define IP_SYNC_SREND_sync_srend_shift                                               (0)
#define IP_SYNC_SREND_sync_srend_mask                                                (0x000000FF)
#define IP_SYNC_SREND_sync_srend(data)                                               (0x000000FF&((data)<<0))
#define IP_SYNC_SREND_sync_srend_src(data)                                           ((0x000000FF&(data))>>0)
#define IP_SYNC_SREND_get_sync_srend(data)                                           ((0x000000FF&(data))>>0)


#define IP_SYNC_EQEND                                                                0x1801F9dc
#define IP_SYNC_EQEND_reg_addr                                                       "0xB800A9DC"
#define IP_SYNC_EQEND_reg                                                           0xB801F9DC
#define set_IP_SYNC_EQEND_reg(data)   (*((volatile unsigned int*) IP_SYNC_EQEND_reg)=data)
#define get_IP_SYNC_EQEND_reg   (*((volatile unsigned int*) IP_SYNC_EQEND_reg))
#define IP_SYNC_EQEND_inst_adr                                                       "0x0077"
#define IP_SYNC_EQEND_inst                                                           0x0077
#define IP_SYNC_EQEND_sync_eqend_shift                                               (0)
#define IP_SYNC_EQEND_sync_eqend_mask                                                (0x0000003F)
#define IP_SYNC_EQEND_sync_eqend(data)                                               (0x0000003F&((data)<<0))
#define IP_SYNC_EQEND_sync_eqend_src(data)                                           ((0x0000003F&(data))>>0)
#define IP_SYNC_EQEND_get_sync_eqend(data)                                           ((0x0000003F&(data))>>0)


#define IP_ACTV_STRT                                                                 0x1801F9e0
#define IP_ACTV_STRT_reg_addr                                                        "0xB800A9E0"
#define IP_ACTV_STRT_reg                                                            0xB801F9E0
#define set_IP_ACTV_STRT_reg(data)   (*((volatile unsigned int*) IP_ACTV_STRT_reg)=data)
#define get_IP_ACTV_STRT_reg   (*((volatile unsigned int*) IP_ACTV_STRT_reg))
#define IP_ACTV_STRT_inst_adr                                                        "0x0078"
#define IP_ACTV_STRT_inst                                                            0x0078
#define IP_ACTV_STRT_actv_strt_shift                                                 (0)
#define IP_ACTV_STRT_actv_strt_mask                                                  (0x000000FF)
#define IP_ACTV_STRT_actv_strt(data)                                                 (0x000000FF&((data)<<0))
#define IP_ACTV_STRT_actv_strt_src(data)                                             ((0x000000FF&(data))>>0)
#define IP_ACTV_STRT_get_actv_strt(data)                                             ((0x000000FF&(data))>>0)


#define IP_ACTV_END                                                                  0x1801F9e4
#define IP_ACTV_END_reg_addr                                                         "0xB800A9E4"
#define IP_ACTV_END_reg                                                             0xB801F9E4
#define set_IP_ACTV_END_reg(data)   (*((volatile unsigned int*) IP_ACTV_END_reg)=data)
#define get_IP_ACTV_END_reg   (*((volatile unsigned int*) IP_ACTV_END_reg))
#define IP_ACTV_END_inst_adr                                                         "0x0079"
#define IP_ACTV_END_inst                                                             0x0079
#define IP_ACTV_END_actv_end_shift                                                   (0)
#define IP_ACTV_END_actv_end_mask                                                    (0x000000FF)
#define IP_ACTV_END_actv_end(data)                                                   (0x000000FF&((data)<<0))
#define IP_ACTV_END_actv_end_src(data)                                               ((0x000000FF&(data))>>0)
#define IP_ACTV_END_get_actv_end(data)                                               ((0x000000FF&(data))>>0)


#define IP_WBRST_STRT                                                                0x1801F9e8
#define IP_WBRST_STRT_reg_addr                                                       "0xB800A9E8"
#define IP_WBRST_STRT_reg                                                           0xB801F9E8
#define set_IP_WBRST_STRT_reg(data)   (*((volatile unsigned int*) IP_WBRST_STRT_reg)=data)
#define get_IP_WBRST_STRT_reg   (*((volatile unsigned int*) IP_WBRST_STRT_reg))
#define IP_WBRST_STRT_inst_adr                                                       "0x007A"
#define IP_WBRST_STRT_inst                                                           0x007A
#define IP_WBRST_STRT_wbrst_strt_shift                                               (0)
#define IP_WBRST_STRT_wbrst_strt_mask                                                (0x0000007F)
#define IP_WBRST_STRT_wbrst_strt(data)                                               (0x0000007F&((data)<<0))
#define IP_WBRST_STRT_wbrst_strt_src(data)                                           ((0x0000007F&(data))>>0)
#define IP_WBRST_STRT_get_wbrst_strt(data)                                           ((0x0000007F&(data))>>0)


#define IP_NBRST_STRT                                                                0x1801F9ec
#define IP_NBRST_STRT_reg_addr                                                       "0xB800A9EC"
#define IP_NBRST_STRT_reg                                                           0xB801F9EC
#define set_IP_NBRST_STRT_reg(data)   (*((volatile unsigned int*) IP_NBRST_STRT_reg)=data)
#define get_IP_NBRST_STRT_reg   (*((volatile unsigned int*) IP_NBRST_STRT_reg))
#define IP_NBRST_STRT_inst_adr                                                       "0x007B"
#define IP_NBRST_STRT_inst                                                           0x007B
#define IP_NBRST_STRT_nbrst_strt_shift                                               (0)
#define IP_NBRST_STRT_nbrst_strt_mask                                                (0x0000007F)
#define IP_NBRST_STRT_nbrst_strt(data)                                               (0x0000007F&((data)<<0))
#define IP_NBRST_STRT_nbrst_strt_src(data)                                           ((0x0000007F&(data))>>0)
#define IP_NBRST_STRT_get_nbrst_strt(data)                                           ((0x0000007F&(data))>>0)


#define IP_NBRST_END                                                                 0x1801F9f0
#define IP_NBRST_END_reg_addr                                                        "0xB800A9F0"
#define IP_NBRST_END_reg                                                            0xB801F9F0
#define set_IP_NBRST_END_reg(data)   (*((volatile unsigned int*) IP_NBRST_END_reg)=data)
#define get_IP_NBRST_END_reg   (*((volatile unsigned int*) IP_NBRST_END_reg))
#define IP_NBRST_END_inst_adr                                                        "0x007C"
#define IP_NBRST_END_inst                                                            0x007C
#define IP_NBRST_END_nbrst_end_shift                                                 (0)
#define IP_NBRST_END_nbrst_end_mask                                                  (0x000000FF)
#define IP_NBRST_END_nbrst_end(data)                                                 (0x000000FF&((data)<<0))
#define IP_NBRST_END_nbrst_end_src(data)                                             ((0x000000FF&(data))>>0)
#define IP_NBRST_END_get_nbrst_end(data)                                             ((0x000000FF&(data))>>0)


#define IP_MVFCR                                                                     0x1801F920
#define IP_MVFCR_reg_addr                                                            "0xB800A920"
#define IP_MVFCR_reg                                                                0xB801F920
#define set_IP_MVFCR_reg(data)   (*((volatile unsigned int*) IP_MVFCR_reg)=data)
#define get_IP_MVFCR_reg   (*((volatile unsigned int*) IP_MVFCR_reg))
#define IP_MVFCR_inst_adr                                                            "0x0048"
#define IP_MVFCR_inst                                                                0x0048
#define IP_MVFCR_mvfcr_shift                                                         (0)
#define IP_MVFCR_mvfcr_mask                                                          (0x000000FF)
#define IP_MVFCR_mvfcr(data)                                                         (0x000000FF&((data)<<0))
#define IP_MVFCR_mvfcr_src(data)                                                     ((0x000000FF&(data))>>0)
#define IP_MVFCR_get_mvfcr(data)                                                     ((0x000000FF&(data))>>0)


#define IP_MVCSL1                                                                    0x1801F924
#define IP_MVCSL1_reg_addr                                                           "0xB800A924"
#define IP_MVCSL1_reg                                                               0xB801F924
#define set_IP_MVCSL1_reg(data)   (*((volatile unsigned int*) IP_MVCSL1_reg)=data)
#define get_IP_MVCSL1_reg   (*((volatile unsigned int*) IP_MVCSL1_reg))
#define IP_MVCSL1_inst_adr                                                           "0x0049"
#define IP_MVCSL1_inst                                                               0x0049
#define IP_MVCSL1_mvcsl1_shift                                                       (0)
#define IP_MVCSL1_mvcsl1_mask                                                        (0x000000FF)
#define IP_MVCSL1_mvcsl1(data)                                                       (0x000000FF&((data)<<0))
#define IP_MVCSL1_mvcsl1_src(data)                                                   ((0x000000FF&(data))>>0)
#define IP_MVCSL1_get_mvcsl1(data)                                                   ((0x000000FF&(data))>>0)


#define IP_MVCLS1                                                                    0x1801F928
#define IP_MVCLS1_reg_addr                                                           "0xB800A928"
#define IP_MVCLS1_reg                                                               0xB801F928
#define set_IP_MVCLS1_reg(data)   (*((volatile unsigned int*) IP_MVCLS1_reg)=data)
#define get_IP_MVCLS1_reg   (*((volatile unsigned int*) IP_MVCLS1_reg))
#define IP_MVCLS1_inst_adr                                                           "0x004A"
#define IP_MVCLS1_inst                                                               0x004A
#define IP_MVCLS1_mvcls1_shift                                                       (0)
#define IP_MVCLS1_mvcls1_mask                                                        (0x0000003F)
#define IP_MVCLS1_mvcls1(data)                                                       (0x0000003F&((data)<<0))
#define IP_MVCLS1_mvcls1_src(data)                                                   ((0x0000003F&(data))>>0)
#define IP_MVCLS1_get_mvcls1(data)                                                   ((0x0000003F&(data))>>0)


#define IP_MVCSL2                                                                    0x1801F92c
#define IP_MVCSL2_reg_addr                                                           "0xB800A92C"
#define IP_MVCSL2_reg                                                               0xB801F92C
#define set_IP_MVCSL2_reg(data)   (*((volatile unsigned int*) IP_MVCSL2_reg)=data)
#define get_IP_MVCSL2_reg   (*((volatile unsigned int*) IP_MVCSL2_reg))
#define IP_MVCSL2_inst_adr                                                           "0x004B"
#define IP_MVCSL2_inst                                                               0x004B
#define IP_MVCSL2_mvcsl2_shift                                                       (0)
#define IP_MVCSL2_mvcsl2_mask                                                        (0x000000FF)
#define IP_MVCSL2_mvcsl2(data)                                                       (0x000000FF&((data)<<0))
#define IP_MVCSL2_mvcsl2_src(data)                                                   ((0x000000FF&(data))>>0)
#define IP_MVCSL2_get_mvcsl2(data)                                                   ((0x000000FF&(data))>>0)


#define IP_MVCLS2                                                                    0x1801F930
#define IP_MVCLS2_reg_addr                                                           "0xB800A930"
#define IP_MVCLS2_reg                                                               0xB801F930
#define set_IP_MVCLS2_reg(data)   (*((volatile unsigned int*) IP_MVCLS2_reg)=data)
#define get_IP_MVCLS2_reg   (*((volatile unsigned int*) IP_MVCLS2_reg))
#define IP_MVCLS2_inst_adr                                                           "0x004C"
#define IP_MVCLS2_inst                                                               0x004C
#define IP_MVCLS2_mvcls2_shift                                                       (0)
#define IP_MVCLS2_mvcls2_mask                                                        (0x0000003F)
#define IP_MVCLS2_mvcls2(data)                                                       (0x0000003F&((data)<<0))
#define IP_MVCLS2_mvcls2_src(data)                                                   ((0x0000003F&(data))>>0)
#define IP_MVCLS2_get_mvcls2(data)                                                   ((0x0000003F&(data))>>0)


#define IP_MVCSSP                                                                    0x1801F934
#define IP_MVCSSP_reg_addr                                                           "0xB800A934"
#define IP_MVCSSP_reg                                                               0xB801F934
#define set_IP_MVCSSP_reg(data)   (*((volatile unsigned int*) IP_MVCSSP_reg)=data)
#define get_IP_MVCSSP_reg   (*((volatile unsigned int*) IP_MVCSSP_reg))
#define IP_MVCSSP_inst_adr                                                           "0x004D"
#define IP_MVCSSP_inst                                                               0x004D
#define IP_MVCSSP_mvcssp_shift                                                       (5)
#define IP_MVCSSP_mvcssp_mask                                                        (0x000000E0)
#define IP_MVCSSP_mvcssp(data)                                                       (0x000000E0&((data)<<5))
#define IP_MVCSSP_mvcssp_src(data)                                                   ((0x000000E0&(data))>>5)
#define IP_MVCSSP_get_mvcssp(data)                                                   ((0x000000E0&(data))>>5)
#define IP_MVCSSP_mvcsnum_shift                                                      (2)
#define IP_MVCSSP_mvcsnum_mask                                                       (0x0000001C)
#define IP_MVCSSP_mvcsnum(data)                                                      (0x0000001C&((data)<<2))
#define IP_MVCSSP_mvcsnum_src(data)                                                  ((0x0000001C&(data))>>2)
#define IP_MVCSSP_get_mvcsnum(data)                                                  ((0x0000001C&(data))>>2)
#define IP_MVCSSP_mvcsln_shift                                                       (0)
#define IP_MVCSSP_mvcsln_mask                                                        (0x00000003)
#define IP_MVCSSP_mvcsln(data)                                                       (0x00000003&((data)<<0))
#define IP_MVCSSP_mvcsln_src(data)                                                   ((0x00000003&(data))>>0)
#define IP_MVCSSP_get_mvcsln(data)                                                   ((0x00000003&(data))>>0)


#define IP_MVPSD                                                                     0x1801F938
#define IP_MVPSD_reg_addr                                                            "0xB800A938"
#define IP_MVPSD_reg                                                                0xB801F938
#define set_IP_MVPSD_reg(data)   (*((volatile unsigned int*) IP_MVPSD_reg)=data)
#define get_IP_MVPSD_reg   (*((volatile unsigned int*) IP_MVPSD_reg))
#define IP_MVPSD_inst_adr                                                            "0x004E"
#define IP_MVPSD_inst                                                                0x004E
#define IP_MVPSD_mvpsd_shift                                                         (0)
#define IP_MVPSD_mvpsd_mask                                                          (0x0000003F)
#define IP_MVPSD_mvpsd(data)                                                         (0x0000003F&((data)<<0))
#define IP_MVPSD_mvpsd_src(data)                                                     ((0x0000003F&(data))>>0)
#define IP_MVPSD_get_mvpsd(data)                                                     ((0x0000003F&(data))>>0)


#define IP_MVPSL                                                                     0x1801F93c
#define IP_MVPSL_reg_addr                                                            "0xB800A93C"
#define IP_MVPSL_reg                                                                0xB801F93C
#define set_IP_MVPSL_reg(data)   (*((volatile unsigned int*) IP_MVPSL_reg)=data)
#define get_IP_MVPSL_reg   (*((volatile unsigned int*) IP_MVPSL_reg))
#define IP_MVPSL_inst_adr                                                            "0x004F"
#define IP_MVPSL_inst                                                                0x004F
#define IP_MVPSL_mvpsl_shift                                                         (0)
#define IP_MVPSL_mvpsl_mask                                                          (0x0000003F)
#define IP_MVPSL_mvpsl(data)                                                         (0x0000003F&((data)<<0))
#define IP_MVPSL_mvpsl_src(data)                                                     ((0x0000003F&(data))>>0)
#define IP_MVPSL_get_mvpsl(data)                                                     ((0x0000003F&(data))>>0)


#define IP_MVPSS                                                                     0x1801F940
#define IP_MVPSS_reg_addr                                                            "0xB800A940"
#define IP_MVPSS_reg                                                                0xB801F940
#define set_IP_MVPSS_reg(data)   (*((volatile unsigned int*) IP_MVPSS_reg)=data)
#define get_IP_MVPSS_reg   (*((volatile unsigned int*) IP_MVPSS_reg))
#define IP_MVPSS_inst_adr                                                            "0x0050"
#define IP_MVPSS_inst                                                                0x0050
#define IP_MVPSS_mvpss_shift                                                         (0)
#define IP_MVPSS_mvpss_mask                                                          (0x0000003F)
#define IP_MVPSS_mvpss(data)                                                         (0x0000003F&((data)<<0))
#define IP_MVPSS_mvpss_src(data)                                                     ((0x0000003F&(data))>>0)
#define IP_MVPSS_get_mvpss(data)                                                     ((0x0000003F&(data))>>0)


#define IP_MVPSLS0                                                                   0x1801F944
#define IP_MVPSLS0_reg_addr                                                          "0xB800A944"
#define IP_MVPSLS0_reg                                                              0xB801F944
#define set_IP_MVPSLS0_reg(data)   (*((volatile unsigned int*) IP_MVPSLS0_reg)=data)
#define get_IP_MVPSLS0_reg   (*((volatile unsigned int*) IP_MVPSLS0_reg))
#define IP_MVPSLS0_inst_adr                                                          "0x0051"
#define IP_MVPSLS0_inst                                                              0x0051
#define IP_MVPSLS0_mvpsls_shift                                                      (0)
#define IP_MVPSLS0_mvpsls_mask                                                       (0x0000007F)
#define IP_MVPSLS0_mvpsls(data)                                                      (0x0000007F&((data)<<0))
#define IP_MVPSLS0_mvpsls_src(data)                                                  ((0x0000007F&(data))>>0)
#define IP_MVPSLS0_get_mvpsls(data)                                                  ((0x0000007F&(data))>>0)


#define IP_MVPSLS1                                                                   0x1801F948
#define IP_MVPSLS1_reg_addr                                                          "0xB800A948"
#define IP_MVPSLS1_reg                                                              0xB801F948
#define set_IP_MVPSLS1_reg(data)   (*((volatile unsigned int*) IP_MVPSLS1_reg)=data)
#define get_IP_MVPSLS1_reg   (*((volatile unsigned int*) IP_MVPSLS1_reg))
#define IP_MVPSLS1_inst_adr                                                          "0x0052"
#define IP_MVPSLS1_inst                                                              0x0052
#define IP_MVPSLS1_mvpsls_shift                                                      (0)
#define IP_MVPSLS1_mvpsls_mask                                                       (0x000000FF)
#define IP_MVPSLS1_mvpsls(data)                                                      (0x000000FF&((data)<<0))
#define IP_MVPSLS1_mvpsls_src(data)                                                  ((0x000000FF&(data))>>0)
#define IP_MVPSLS1_get_mvpsls(data)                                                  ((0x000000FF&(data))>>0)


#define IP_MVPSFS0                                                                   0x1801F94c
#define IP_MVPSFS0_reg_addr                                                          "0xB800A94C"
#define IP_MVPSFS0_reg                                                              0xB801F94C
#define set_IP_MVPSFS0_reg(data)   (*((volatile unsigned int*) IP_MVPSFS0_reg)=data)
#define get_IP_MVPSFS0_reg   (*((volatile unsigned int*) IP_MVPSFS0_reg))
#define IP_MVPSFS0_inst_adr                                                          "0x0053"
#define IP_MVPSFS0_inst                                                              0x0053
#define IP_MVPSFS0_mvpsfs_shift                                                      (0)
#define IP_MVPSFS0_mvpsfs_mask                                                       (0x0000007F)
#define IP_MVPSFS0_mvpsfs(data)                                                      (0x0000007F&((data)<<0))
#define IP_MVPSFS0_mvpsfs_src(data)                                                  ((0x0000007F&(data))>>0)
#define IP_MVPSFS0_get_mvpsfs(data)                                                  ((0x0000007F&(data))>>0)


#define IP_MVPSFS1                                                                   0x1801F950
#define IP_MVPSFS1_reg_addr                                                          "0xB800A950"
#define IP_MVPSFS1_reg                                                              0xB801F950
#define set_IP_MVPSFS1_reg(data)   (*((volatile unsigned int*) IP_MVPSFS1_reg)=data)
#define get_IP_MVPSFS1_reg   (*((volatile unsigned int*) IP_MVPSFS1_reg))
#define IP_MVPSFS1_inst_adr                                                          "0x0054"
#define IP_MVPSFS1_inst                                                              0x0054
#define IP_MVPSFS1_mvpsfs_shift                                                      (0)
#define IP_MVPSFS1_mvpsfs_mask                                                       (0x000000FF)
#define IP_MVPSFS1_mvpsfs(data)                                                      (0x000000FF&((data)<<0))
#define IP_MVPSFS1_mvpsfs_src(data)                                                  ((0x000000FF&(data))>>0)
#define IP_MVPSFS1_get_mvpsfs(data)                                                  ((0x000000FF&(data))>>0)


#define IP_MVPSAGCA                                                                  0x1801F954
#define IP_MVPSAGCA_reg_addr                                                         "0xB800A954"
#define IP_MVPSAGCA_reg                                                             0xB801F954
#define set_IP_MVPSAGCA_reg(data)   (*((volatile unsigned int*) IP_MVPSAGCA_reg)=data)
#define get_IP_MVPSAGCA_reg   (*((volatile unsigned int*) IP_MVPSAGCA_reg))
#define IP_MVPSAGCA_inst_adr                                                         "0x0055"
#define IP_MVPSAGCA_inst                                                             0x0055
#define IP_MVPSAGCA_mvpsagca_shift                                                   (0)
#define IP_MVPSAGCA_mvpsagca_mask                                                    (0x000000FF)
#define IP_MVPSAGCA_mvpsagca(data)                                                   (0x000000FF&((data)<<0))
#define IP_MVPSAGCA_mvpsagca_src(data)                                               ((0x000000FF&(data))>>0)
#define IP_MVPSAGCA_get_mvpsagca(data)                                               ((0x000000FF&(data))>>0)


#define IP_MVPSAGCB                                                                  0x1801F958
#define IP_MVPSAGCB_reg_addr                                                         "0xB800A958"
#define IP_MVPSAGCB_reg                                                             0xB801F958
#define set_IP_MVPSAGCB_reg(data)   (*((volatile unsigned int*) IP_MVPSAGCB_reg)=data)
#define get_IP_MVPSAGCB_reg   (*((volatile unsigned int*) IP_MVPSAGCB_reg))
#define IP_MVPSAGCB_inst_adr                                                         "0x0056"
#define IP_MVPSAGCB_inst                                                             0x0056
#define IP_MVPSAGCB_mvpsagcb_shift                                                   (0)
#define IP_MVPSAGCB_mvpsagcb_mask                                                    (0x000000FF)
#define IP_MVPSAGCB_mvpsagcb(data)                                                   (0x000000FF&((data)<<0))
#define IP_MVPSAGCB_mvpsagcb_src(data)                                               ((0x000000FF&(data))>>0)
#define IP_MVPSAGCB_get_mvpsagcb(data)                                               ((0x000000FF&(data))>>0)


#define IP_MVEOFBPC                                                                  0x1801F95c
#define IP_MVEOFBPC_reg_addr                                                         "0xB800A95C"
#define IP_MVEOFBPC_reg                                                             0xB801F95C
#define set_IP_MVEOFBPC_reg(data)   (*((volatile unsigned int*) IP_MVEOFBPC_reg)=data)
#define get_IP_MVEOFBPC_reg   (*((volatile unsigned int*) IP_MVEOFBPC_reg))
#define IP_MVEOFBPC_inst_adr                                                         "0x0057"
#define IP_MVEOFBPC_inst                                                             0x0057
#define IP_MVEOFBPC_mveofbpc_shift                                                   (0)
#define IP_MVEOFBPC_mveofbpc_mask                                                    (0x000000FF)
#define IP_MVEOFBPC_mveofbpc(data)                                                   (0x000000FF&((data)<<0))
#define IP_MVEOFBPC_mveofbpc_src(data)                                               ((0x000000FF&(data))>>0)
#define IP_MVEOFBPC_get_mveofbpc(data)                                               ((0x000000FF&(data))>>0)


#define IP_MVPBZ1                                                                    0x1801F960
#define IP_MVPBZ1_reg_addr                                                           "0xB800A960"
#define IP_MVPBZ1_reg                                                               0xB801F960
#define set_IP_MVPBZ1_reg(data)   (*((volatile unsigned int*) IP_MVPBZ1_reg)=data)
#define get_IP_MVPBZ1_reg   (*((volatile unsigned int*) IP_MVPBZ1_reg))
#define IP_MVPBZ1_inst_adr                                                           "0x0058"
#define IP_MVPBZ1_inst                                                               0x0058
#define IP_MVPBZ1_mvpbz1_shift                                                       (4)
#define IP_MVPBZ1_mvpbz1_mask                                                        (0x000000F0)
#define IP_MVPBZ1_mvpbz1(data)                                                       (0x000000F0&((data)<<4))
#define IP_MVPBZ1_mvpbz1_src(data)                                                   ((0x000000F0&(data))>>4)
#define IP_MVPBZ1_get_mvpbz1(data)                                                   ((0x000000F0&(data))>>4)
#define IP_MVPBZ1_mvpbz2_shift                                                       (0)
#define IP_MVPBZ1_mvpbz2_mask                                                        (0x0000000F)
#define IP_MVPBZ1_mvpbz2(data)                                                       (0x0000000F&((data)<<0))
#define IP_MVPBZ1_mvpbz2_src(data)                                                   ((0x0000000F&(data))>>0)
#define IP_MVPBZ1_get_mvpbz2(data)                                                   ((0x0000000F&(data))>>0)


#define IP_MVPBZ3                                                                    0x1801F964
#define IP_MVPBZ3_reg_addr                                                           "0xB800A964"
#define IP_MVPBZ3_reg                                                               0xB801F964
#define set_IP_MVPBZ3_reg(data)   (*((volatile unsigned int*) IP_MVPBZ3_reg)=data)
#define get_IP_MVPBZ3_reg   (*((volatile unsigned int*) IP_MVPBZ3_reg))
#define IP_MVPBZ3_inst_adr                                                           "0x0059"
#define IP_MVPBZ3_inst                                                               0x0059
#define IP_MVPBZ3_mvpbz3_shift                                                       (4)
#define IP_MVPBZ3_mvpbz3_mask                                                        (0x000000F0)
#define IP_MVPBZ3_mvpbz3(data)                                                       (0x000000F0&((data)<<4))
#define IP_MVPBZ3_mvpbz3_src(data)                                                   ((0x000000F0&(data))>>4)
#define IP_MVPBZ3_get_mvpbz3(data)                                                   ((0x000000F0&(data))>>4)
#define IP_MVPBZ3_mvpadvbsen_shift                                                   (3)
#define IP_MVPBZ3_mvpadvbsen_mask                                                    (0x00000008)
#define IP_MVPBZ3_mvpadvbsen(data)                                                   (0x00000008&((data)<<3))
#define IP_MVPBZ3_mvpadvbsen_src(data)                                               ((0x00000008&(data))>>3)
#define IP_MVPBZ3_get_mvpadvbsen(data)                                               ((0x00000008&(data))>>3)
#define IP_MVPBZ3_mvpzninvrt_shift                                                   (0)
#define IP_MVPBZ3_mvpzninvrt_mask                                                    (0x00000007)
#define IP_MVPBZ3_mvpzninvrt(data)                                                   (0x00000007&((data)<<0))
#define IP_MVPBZ3_mvpzninvrt_src(data)                                               ((0x00000007&(data))>>0)
#define IP_MVPBZ3_get_mvpzninvrt(data)                                               ((0x00000007&(data))>>0)


#define IP_MVPCSLIMD0                                                                0x1801F968
#define IP_MVPCSLIMD0_reg_addr                                                       "0xB800A968"
#define IP_MVPCSLIMD0_reg                                                           0xB801F968
#define set_IP_MVPCSLIMD0_reg(data)   (*((volatile unsigned int*) IP_MVPCSLIMD0_reg)=data)
#define get_IP_MVPCSLIMD0_reg   (*((volatile unsigned int*) IP_MVPCSLIMD0_reg))
#define IP_MVPCSLIMD0_inst_adr                                                       "0x005A"
#define IP_MVPCSLIMD0_inst                                                           0x005A
#define IP_MVPCSLIMD0_mvpcslimd_lsb_shift                                            (0)
#define IP_MVPCSLIMD0_mvpcslimd_lsb_mask                                             (0x000000FF)
#define IP_MVPCSLIMD0_mvpcslimd_lsb(data)                                            (0x000000FF&((data)<<0))
#define IP_MVPCSLIMD0_mvpcslimd_lsb_src(data)                                        ((0x000000FF&(data))>>0)
#define IP_MVPCSLIMD0_get_mvpcslimd_lsb(data)                                        ((0x000000FF&(data))>>0)


#define IP_MVPCSLIMD1                                                                0x1801F96c
#define IP_MVPCSLIMD1_reg_addr                                                       "0xB800A96C"
#define IP_MVPCSLIMD1_reg                                                           0xB801F96C
#define set_IP_MVPCSLIMD1_reg(data)   (*((volatile unsigned int*) IP_MVPCSLIMD1_reg)=data)
#define get_IP_MVPCSLIMD1_reg   (*((volatile unsigned int*) IP_MVPCSLIMD1_reg))
#define IP_MVPCSLIMD1_inst_adr                                                       "0x005B"
#define IP_MVPCSLIMD1_inst                                                           0x005B
#define IP_MVPCSLIMD1_mvpcslimd_msb_shift                                            (0)
#define IP_MVPCSLIMD1_mvpcslimd_msb_mask                                             (0x00000003)
#define IP_MVPCSLIMD1_mvpcslimd_msb(data)                                            (0x00000003&((data)<<0))
#define IP_MVPCSLIMD1_mvpcslimd_msb_src(data)                                        ((0x00000003&(data))>>0)
#define IP_MVPCSLIMD1_get_mvpcslimd_msb(data)                                        ((0x00000003&(data))>>0)


#define IP_MV_CTRL                                                                   0x1801F990
#define IP_MV_CTRL_reg_addr                                                          "0xB800A990"
#define IP_MV_CTRL_reg                                                              0xB801F990
#define set_IP_MV_CTRL_reg(data)   (*((volatile unsigned int*) IP_MV_CTRL_reg)=data)
#define get_IP_MV_CTRL_reg   (*((volatile unsigned int*) IP_MV_CTRL_reg))
#define IP_MV_CTRL_inst_adr                                                          "0x0064"
#define IP_MV_CTRL_inst                                                              0x0064
#define IP_MV_CTRL_mvtms_shift                                                       (0)
#define IP_MV_CTRL_mvtms_mask                                                        (0x000000FF)
#define IP_MV_CTRL_mvtms(data)                                                       (0x000000FF&((data)<<0))
#define IP_MV_CTRL_mvtms_src(data)                                                   ((0x000000FF&(data))>>0)
#define IP_MV_CTRL_get_mvtms(data)                                                   ((0x000000FF&(data))>>0)


#define VIDEO_DAC_CTRL_0                                                             0x1801F200
#define VIDEO_DAC_CTRL_1                                                             0x1801F204
#define VIDEO_DAC_CTRL_0_reg_addr                                                    "0xB800A200"
#define VIDEO_DAC_CTRL_1_reg_addr                                                    "0xB800A204"
#define VIDEO_DAC_CTRL_0_reg                                                        0xB801F200
#define VIDEO_DAC_CTRL_1_reg                                                        0xB801F204
#define set_VIDEO_DAC_CTRL_0_reg(data)   (*((volatile unsigned int*) VIDEO_DAC_CTRL_0_reg)=data)
#define set_VIDEO_DAC_CTRL_1_reg(data)   (*((volatile unsigned int*) VIDEO_DAC_CTRL_1_reg)=data)
#define get_VIDEO_DAC_CTRL_0_reg   (*((volatile unsigned int*) VIDEO_DAC_CTRL_0_reg))
#define get_VIDEO_DAC_CTRL_1_reg   (*((volatile unsigned int*) VIDEO_DAC_CTRL_1_reg))
#define VIDEO_DAC_CTRL_0_inst_adr                                                    "0x0080"
#define VIDEO_DAC_CTRL_1_inst_adr                                                    "0x0081"
#define VIDEO_DAC_CTRL_0_inst                                                        0x0080
#define VIDEO_DAC_CTRL_1_inst                                                        0x0081
#define VIDEO_DAC_CTRL_vdac_apow_shift                                               (22)
#define VIDEO_DAC_CTRL_vdac_apow_mask                                                (0x00400000)
#define VIDEO_DAC_CTRL_vdac_apow(data)                                               (0x00400000&((data)<<22))
#define VIDEO_DAC_CTRL_vdac_apow_src(data)                                           ((0x00400000&(data))>>22)
#define VIDEO_DAC_CTRL_get_vdac_apow(data)                                           ((0x00400000&(data))>>22)
#define VIDEO_DAC_CTRL_vdac_bpow_shift                                               (21)
#define VIDEO_DAC_CTRL_vdac_bpow_mask                                                (0x00200000)
#define VIDEO_DAC_CTRL_vdac_bpow(data)                                               (0x00200000&((data)<<21))
#define VIDEO_DAC_CTRL_vdac_bpow_src(data)                                           ((0x00200000&(data))>>21)
#define VIDEO_DAC_CTRL_get_vdac_bpow(data)                                           ((0x00200000&(data))>>21)
#define VIDEO_DAC_CTRL_vdac_cpow_shift                                               (20)
#define VIDEO_DAC_CTRL_vdac_cpow_mask                                                (0x00100000)
#define VIDEO_DAC_CTRL_vdac_cpow(data)                                               (0x00100000&((data)<<20))
#define VIDEO_DAC_CTRL_vdac_cpow_src(data)                                           ((0x00100000&(data))>>20)
#define VIDEO_DAC_CTRL_get_vdac_cpow(data)                                           ((0x00100000&(data))>>20)
#define VIDEO_DAC_CTRL_powldv_l_shift                                                (19)
#define VIDEO_DAC_CTRL_powldv_l_mask                                                 (0x00080000)
#define VIDEO_DAC_CTRL_powldv_l(data)                                                (0x00080000&((data)<<19))
#define VIDEO_DAC_CTRL_powldv_l_src(data)                                            ((0x00080000&(data))>>19)
#define VIDEO_DAC_CTRL_get_powldv_l(data)                                            ((0x00080000&(data))>>19)
#define VIDEO_DAC_CTRL_stanby_l_shift                                                (18)
#define VIDEO_DAC_CTRL_stanby_l_mask                                                 (0x00040000)
#define VIDEO_DAC_CTRL_stanby_l(data)                                                (0x00040000&((data)<<18))
#define VIDEO_DAC_CTRL_stanby_l_src(data)                                            ((0x00040000&(data))>>18)
#define VIDEO_DAC_CTRL_get_stanby_l(data)                                            ((0x00040000&(data))>>18)
#define VIDEO_DAC_CTRL_biasa_regl_shift                                              (12)
#define VIDEO_DAC_CTRL_biasa_regl_mask                                               (0x0000F000)
#define VIDEO_DAC_CTRL_biasa_regl(data)                                              (0x0000F000&((data)<<12))
#define VIDEO_DAC_CTRL_biasa_regl_src(data)                                          ((0x0000F000&(data))>>12)
#define VIDEO_DAC_CTRL_get_biasa_regl(data)                                          ((0x0000F000&(data))>>12)
#define VIDEO_DAC_CTRL_biasb_regl_shift                                              (6)
#define VIDEO_DAC_CTRL_biasb_regl_mask                                               (0x000003C0)
#define VIDEO_DAC_CTRL_biasb_regl(data)                                              (0x000003C0&((data)<<6))
#define VIDEO_DAC_CTRL_biasb_regl_src(data)                                          ((0x000003C0&(data))>>6)
#define VIDEO_DAC_CTRL_get_biasb_regl(data)                                          ((0x000003C0&(data))>>6)
#define VIDEO_DAC_CTRL_biasc_regl_shift                                              (0)
#define VIDEO_DAC_CTRL_biasc_regl_mask                                               (0x0000000F)
#define VIDEO_DAC_CTRL_biasc_regl(data)                                              (0x0000000F&((data)<<0))
#define VIDEO_DAC_CTRL_biasc_regl_src(data)                                          ((0x0000000F&(data))>>0)
#define VIDEO_DAC_CTRL_get_biasc_regl(data)                                          ((0x0000000F&(data))>>0)


#define VIDEO_DAC_CTRL2_0                                                            0x1801F218
#define VIDEO_DAC_CTRL2_1                                                            0x1801F21C
#define VIDEO_DAC_CTRL2_0_reg_addr                                                   "0xB800A218"
#define VIDEO_DAC_CTRL2_1_reg_addr                                                   "0xB800A21C"
#define VIDEO_DAC_CTRL2_0_reg                                                       0xB801F218
#define VIDEO_DAC_CTRL2_1_reg                                                       0xB801F21C
#define set_VIDEO_DAC_CTRL2_0_reg(data)   (*((volatile unsigned int*) VIDEO_DAC_CTRL2_0_reg)=data)
#define set_VIDEO_DAC_CTRL2_1_reg(data)   (*((volatile unsigned int*) VIDEO_DAC_CTRL2_1_reg)=data)
#define get_VIDEO_DAC_CTRL2_0_reg   (*((volatile unsigned int*) VIDEO_DAC_CTRL2_0_reg))
#define get_VIDEO_DAC_CTRL2_1_reg   (*((volatile unsigned int*) VIDEO_DAC_CTRL2_1_reg))
#define VIDEO_DAC_CTRL2_0_inst_adr                                                   "0x0086"
#define VIDEO_DAC_CTRL2_1_inst_adr                                                   "0x0087"
#define VIDEO_DAC_CTRL2_0_inst                                                       0x0086
#define VIDEO_DAC_CTRL2_1_inst                                                       0x0087
#define VIDEO_DAC_CTRL2_abiq_regl_shift                                              (12)
#define VIDEO_DAC_CTRL2_abiq_regl_mask                                               (0x00007000)
#define VIDEO_DAC_CTRL2_abiq_regl(data)                                              (0x00007000&((data)<<12))
#define VIDEO_DAC_CTRL2_abiq_regl_src(data)                                          ((0x00007000&(data))>>12)
#define VIDEO_DAC_CTRL2_get_abiq_regl(data)                                          ((0x00007000&(data))>>12)
#define VIDEO_DAC_CTRL2_ldvbias_regl_shift                                           (9)
#define VIDEO_DAC_CTRL2_ldvbias_regl_mask                                            (0x00000E00)
#define VIDEO_DAC_CTRL2_ldvbias_regl(data)                                           (0x00000E00&((data)<<9))
#define VIDEO_DAC_CTRL2_ldvbias_regl_src(data)                                       ((0x00000E00&(data))>>9)
#define VIDEO_DAC_CTRL2_get_ldvbias_regl(data)                                       ((0x00000E00&(data))>>9)
#define VIDEO_DAC_CTRL2_vcmref_regl_shift                                            (7)
#define VIDEO_DAC_CTRL2_vcmref_regl_mask                                             (0x00000180)
#define VIDEO_DAC_CTRL2_vcmref_regl(data)                                            (0x00000180&((data)<<7))
#define VIDEO_DAC_CTRL2_vcmref_regl_src(data)                                        ((0x00000180&(data))>>7)
#define VIDEO_DAC_CTRL2_get_vcmref_regl(data)                                        ((0x00000180&(data))>>7)
#define VIDEO_DAC_CTRL2_vdac_cf_regl_shift                                           (2)
#define VIDEO_DAC_CTRL2_vdac_cf_regl_mask                                            (0x0000001C)
#define VIDEO_DAC_CTRL2_vdac_cf_regl(data)                                           (0x0000001C&((data)<<2))
#define VIDEO_DAC_CTRL2_vdac_cf_regl_src(data)                                       ((0x0000001C&(data))>>2)
#define VIDEO_DAC_CTRL2_get_vdac_cf_regl(data)                                       ((0x0000001C&(data))>>2)
#define VIDEO_DAC_CTRL2_vdac_rf_regl_shift                                           (0)
#define VIDEO_DAC_CTRL2_vdac_rf_regl_mask                                            (0x00000003)
#define VIDEO_DAC_CTRL2_vdac_rf_regl(data)                                           (0x00000003&((data)<<0))
#define VIDEO_DAC_CTRL2_vdac_rf_regl_src(data)                                       ((0x00000003&(data))>>0)
#define VIDEO_DAC_CTRL2_get_vdac_rf_regl(data)                                       ((0x00000003&(data))>>0)


#define VIDEO_DAC_CTRL3                                                              0x1801F350
#define VIDEO_DAC_CTRL3_reg_addr                                                     "0xB800A350"
#define VIDEO_DAC_CTRL3_reg                                                         0xB801F350
#define set_VIDEO_DAC_CTRL3_reg(data)   (*((volatile unsigned int*) VIDEO_DAC_CTRL3_reg)=data)
#define get_VIDEO_DAC_CTRL3_reg   (*((volatile unsigned int*) VIDEO_DAC_CTRL3_reg))
#define VIDEO_DAC_CTRL3_inst_adr                                                     "0x00D4"
#define VIDEO_DAC_CTRL3_inst                                                         0x00D4
#define VIDEO_DAC_CTRL3_write_en6_shift                                              (18)
#define VIDEO_DAC_CTRL3_write_en6_mask                                               (0x00040000)
#define VIDEO_DAC_CTRL3_write_en6(data)                                              (0x00040000&((data)<<18))
#define VIDEO_DAC_CTRL3_write_en6_src(data)                                          ((0x00040000&(data))>>18)
#define VIDEO_DAC_CTRL3_get_write_en6(data)                                          ((0x00040000&(data))>>18)
#define VIDEO_DAC_CTRL3_dcc2_l_shift                                                 (17)
#define VIDEO_DAC_CTRL3_dcc2_l_mask                                                  (0x00020000)
#define VIDEO_DAC_CTRL3_dcc2_l(data)                                                 (0x00020000&((data)<<17))
#define VIDEO_DAC_CTRL3_dcc2_l_src(data)                                             ((0x00020000&(data))>>17)
#define VIDEO_DAC_CTRL3_get_dcc2_l(data)                                             ((0x00020000&(data))>>17)
#define VIDEO_DAC_CTRL3_write_en5_shift                                              (16)
#define VIDEO_DAC_CTRL3_write_en5_mask                                               (0x00010000)
#define VIDEO_DAC_CTRL3_write_en5(data)                                              (0x00010000&((data)<<16))
#define VIDEO_DAC_CTRL3_write_en5_src(data)                                          ((0x00010000&(data))>>16)
#define VIDEO_DAC_CTRL3_get_write_en5(data)                                          ((0x00010000&(data))>>16)
#define VIDEO_DAC_CTRL3_dcc_l_shift                                                  (15)
#define VIDEO_DAC_CTRL3_dcc_l_mask                                                   (0x00008000)
#define VIDEO_DAC_CTRL3_dcc_l(data)                                                  (0x00008000&((data)<<15))
#define VIDEO_DAC_CTRL3_dcc_l_src(data)                                              ((0x00008000&(data))>>15)
#define VIDEO_DAC_CTRL3_get_dcc_l(data)                                              ((0x00008000&(data))>>15)
#define VIDEO_DAC_CTRL3_write_en4_shift                                              (14)
#define VIDEO_DAC_CTRL3_write_en4_mask                                               (0x00004000)
#define VIDEO_DAC_CTRL3_write_en4(data)                                              (0x00004000&((data)<<14))
#define VIDEO_DAC_CTRL3_write_en4_src(data)                                          ((0x00004000&(data))>>14)
#define VIDEO_DAC_CTRL3_get_write_en4(data)                                          ((0x00004000&(data))>>14)
#define VIDEO_DAC_CTRL3_caldiv_shift                                                 (12)
#define VIDEO_DAC_CTRL3_caldiv_mask                                                  (0x00003000)
#define VIDEO_DAC_CTRL3_caldiv(data)                                                 (0x00003000&((data)<<12))
#define VIDEO_DAC_CTRL3_caldiv_src(data)                                             ((0x00003000&(data))>>12)
#define VIDEO_DAC_CTRL3_get_caldiv(data)                                             ((0x00003000&(data))>>12)
#define VIDEO_DAC_CTRL3_write_en3_shift                                              (8)
#define VIDEO_DAC_CTRL3_write_en3_mask                                               (0x00000100)
#define VIDEO_DAC_CTRL3_write_en3(data)                                              (0x00000100&((data)<<8))
#define VIDEO_DAC_CTRL3_write_en3_src(data)                                          ((0x00000100&(data))>>8)
#define VIDEO_DAC_CTRL3_get_write_en3(data)                                          ((0x00000100&(data))>>8)
#define VIDEO_DAC_CTRL3_div_regl_shift                                               (6)
#define VIDEO_DAC_CTRL3_div_regl_mask                                                (0x000000C0)
#define VIDEO_DAC_CTRL3_div_regl(data)                                               (0x000000C0&((data)<<6))
#define VIDEO_DAC_CTRL3_div_regl_src(data)                                           ((0x000000C0&(data))>>6)
#define VIDEO_DAC_CTRL3_get_div_regl(data)                                           ((0x000000C0&(data))>>6)
#define VIDEO_DAC_CTRL3_write_en2_shift                                              (5)
#define VIDEO_DAC_CTRL3_write_en2_mask                                               (0x00000020)
#define VIDEO_DAC_CTRL3_write_en2(data)                                              (0x00000020&((data)<<5))
#define VIDEO_DAC_CTRL3_write_en2_src(data)                                          ((0x00000020&(data))>>5)
#define VIDEO_DAC_CTRL3_get_write_en2(data)                                          ((0x00000020&(data))>>5)
#define VIDEO_DAC_CTRL3_ckmode_regl_shift                                            (3)
#define VIDEO_DAC_CTRL3_ckmode_regl_mask                                             (0x00000018)
#define VIDEO_DAC_CTRL3_ckmode_regl(data)                                            (0x00000018&((data)<<3))
#define VIDEO_DAC_CTRL3_ckmode_regl_src(data)                                        ((0x00000018&(data))>>3)
#define VIDEO_DAC_CTRL3_get_ckmode_regl(data)                                        ((0x00000018&(data))>>3)
#define VIDEO_DAC_CTRL3_write_en1_shift                                              (2)
#define VIDEO_DAC_CTRL3_write_en1_mask                                               (0x00000004)
#define VIDEO_DAC_CTRL3_write_en1(data)                                              (0x00000004&((data)<<2))
#define VIDEO_DAC_CTRL3_write_en1_src(data)                                          ((0x00000004&(data))>>2)
#define VIDEO_DAC_CTRL3_get_write_en1(data)                                          ((0x00000004&(data))>>2)
#define VIDEO_DAC_CTRL3_calen_regl_shift                                             (0)
#define VIDEO_DAC_CTRL3_calen_regl_mask                                              (0x00000003)
#define VIDEO_DAC_CTRL3_calen_regl(data)                                             (0x00000003&((data)<<0))
#define VIDEO_DAC_CTRL3_calen_regl_src(data)                                         ((0x00000003&(data))>>0)
#define VIDEO_DAC_CTRL3_get_calen_regl(data)                                         ((0x00000003&(data))>>0)


#define DAC_SEL                                                                      0x1801F36c
#define DAC_SEL_reg_addr                                                             "0xB800A36C"
#define DAC_SEL_reg                                                                 0xB801F36C
#define set_DAC_SEL_reg(data)   (*((volatile unsigned int*) DAC_SEL_reg)=data)
#define get_DAC_SEL_reg   (*((volatile unsigned int*) DAC_SEL_reg))
#define DAC_SEL_inst_adr                                                             "0x00DB"
#define DAC_SEL_inst                                                                 0x00DB
#define DAC_SEL_write_en1_shift                                                      (2)
#define DAC_SEL_write_en1_mask                                                       (0x00000004)
#define DAC_SEL_write_en1(data)                                                      (0x00000004&((data)<<2))
#define DAC_SEL_write_en1_src(data)                                                  ((0x00000004&(data))>>2)
#define DAC_SEL_get_write_en1(data)                                                  ((0x00000004&(data))>>2)
#define DAC_SEL_dac0_sel_shift                                                       (0)
#define DAC_SEL_dac0_sel_mask                                                        (0x00000003)
#define DAC_SEL_dac0_sel(data)                                                       (0x00000003&((data)<<0))
#define DAC_SEL_dac0_sel_src(data)                                                   ((0x00000003&(data))>>0)
#define DAC_SEL_get_dac0_sel(data)                                                   ((0x00000003&(data))>>0)


#define DAC_MUX                                                                      0x1801F208
#define DAC_MUX_reg_addr                                                             "0xB800A208"
#define DAC_MUX_reg                                                                 0xB801F208
#define set_DAC_MUX_reg(data)   (*((volatile unsigned int*) DAC_MUX_reg)=data)
#define get_DAC_MUX_reg   (*((volatile unsigned int*) DAC_MUX_reg))
#define DAC_MUX_inst_adr                                                             "0x0082"
#define DAC_MUX_inst                                                                 0x0082
#define DAC_MUX_write_en6_shift                                                      (15)
#define DAC_MUX_write_en6_mask                                                       (0x00008000)
#define DAC_MUX_write_en6(data)                                                      (0x00008000&((data)<<15))
#define DAC_MUX_write_en6_src(data)                                                  ((0x00008000&(data))>>15)
#define DAC_MUX_get_write_en6(data)                                                  ((0x00008000&(data))>>15)
#define DAC_MUX_up_ctrl_prog_shift                                                   (13)
#define DAC_MUX_up_ctrl_prog_mask                                                    (0x00006000)
#define DAC_MUX_up_ctrl_prog(data)                                                   (0x00006000&((data)<<13))
#define DAC_MUX_up_ctrl_prog_src(data)                                               ((0x00006000&(data))>>13)
#define DAC_MUX_get_up_ctrl_prog(data)                                               ((0x00006000&(data))>>13)
#define DAC_MUX_write_en5_shift                                                      (12)
#define DAC_MUX_write_en5_mask                                                       (0x00001000)
#define DAC_MUX_write_en5(data)                                                      (0x00001000&((data)<<12))
#define DAC_MUX_write_en5_src(data)                                                  ((0x00001000&(data))>>12)
#define DAC_MUX_get_write_en5(data)                                                  ((0x00001000&(data))>>12)
#define DAC_MUX_up_ctrl_int0_shift                                                   (10)
#define DAC_MUX_up_ctrl_int0_mask                                                    (0x00000C00)
#define DAC_MUX_up_ctrl_int0(data)                                                   (0x00000C00&((data)<<10))
#define DAC_MUX_up_ctrl_int0_src(data)                                               ((0x00000C00&(data))>>10)
#define DAC_MUX_get_up_ctrl_int0(data)                                               ((0x00000C00&(data))>>10)
#define DAC_MUX_write_en4_shift                                                      (9)
#define DAC_MUX_write_en4_mask                                                       (0x00000200)
#define DAC_MUX_write_en4(data)                                                      (0x00000200&((data)<<9))
#define DAC_MUX_write_en4_src(data)                                                  ((0x00000200&(data))>>9)
#define DAC_MUX_get_write_en4(data)                                                  ((0x00000200&(data))>>9)
#define DAC_MUX_up_ctrl_int1_shift                                                   (7)
#define DAC_MUX_up_ctrl_int1_mask                                                    (0x00000180)
#define DAC_MUX_up_ctrl_int1(data)                                                   (0x00000180&((data)<<7))
#define DAC_MUX_up_ctrl_int1_src(data)                                               ((0x00000180&(data))>>7)
#define DAC_MUX_get_up_ctrl_int1(data)                                               ((0x00000180&(data))>>7)
#define DAC_MUX_write_en3_shift                                                      (6)
#define DAC_MUX_write_en3_mask                                                       (0x00000040)
#define DAC_MUX_write_en3(data)                                                      (0x00000040&((data)<<6))
#define DAC_MUX_write_en3_src(data)                                                  ((0x00000040&(data))>>6)
#define DAC_MUX_get_write_en3(data)                                                  ((0x00000040&(data))>>6)
#define DAC_MUX_dacmode_shift                                                        (4)
#define DAC_MUX_dacmode_mask                                                         (0x00000030)
#define DAC_MUX_dacmode(data)                                                        (0x00000030&((data)<<4))
#define DAC_MUX_dacmode_src(data)                                                    ((0x00000030&(data))>>4)
#define DAC_MUX_get_dacmode(data)                                                    ((0x00000030&(data))>>4)
#define DAC_MUX_write_en2_shift                                                      (3)
#define DAC_MUX_write_en2_mask                                                       (0x00000008)
#define DAC_MUX_write_en2(data)                                                      (0x00000008&((data)<<3))
#define DAC_MUX_write_en2_src(data)                                                  ((0x00000008&(data))>>3)
#define DAC_MUX_get_write_en2(data)                                                  ((0x00000008&(data))>>3)
#define DAC_MUX_swap23_shift                                                         (2)
#define DAC_MUX_swap23_mask                                                          (0x00000004)
#define DAC_MUX_swap23(data)                                                         (0x00000004&((data)<<2))
#define DAC_MUX_swap23_src(data)                                                     ((0x00000004&(data))>>2)
#define DAC_MUX_get_swap23(data)                                                     ((0x00000004&(data))>>2)
#define DAC_MUX_write_en1_shift                                                      (1)
#define DAC_MUX_write_en1_mask                                                       (0x00000002)
#define DAC_MUX_write_en1(data)                                                      (0x00000002&((data)<<1))
#define DAC_MUX_write_en1_src(data)                                                  ((0x00000002&(data))>>1)
#define DAC_MUX_get_write_en1(data)                                                  ((0x00000002&(data))>>1)
#define DAC_MUX_swap56_shift                                                         (0)
#define DAC_MUX_swap56_mask                                                          (0x00000001)
#define DAC_MUX_swap56(data)                                                         (0x00000001&((data)<<0))
#define DAC_MUX_swap56_src(data)                                                     ((0x00000001&(data))>>0)
#define DAC_MUX_get_swap56(data)                                                     ((0x00000001&(data))>>0)


#define CMP_DLY                                                                      0x1801F20c
#define CMP_DLY_reg_addr                                                             "0xB800A20C"
#define CMP_DLY_reg                                                                 0xB801F20C
#define set_CMP_DLY_reg(data)   (*((volatile unsigned int*) CMP_DLY_reg)=data)
#define get_CMP_DLY_reg   (*((volatile unsigned int*) CMP_DLY_reg))
#define CMP_DLY_inst_adr                                                             "0x0083"
#define CMP_DLY_inst                                                                 0x0083
#define CMP_DLY_write_en3_shift                                                      (8)
#define CMP_DLY_write_en3_mask                                                       (0x00000100)
#define CMP_DLY_write_en3(data)                                                      (0x00000100&((data)<<8))
#define CMP_DLY_write_en3_src(data)                                                  ((0x00000100&(data))>>8)
#define CMP_DLY_get_write_en3(data)                                                  ((0x00000100&(data))>>8)
#define CMP_DLY_ygdelay_shift                                                        (6)
#define CMP_DLY_ygdelay_mask                                                         (0x000000C0)
#define CMP_DLY_ygdelay(data)                                                        (0x000000C0&((data)<<6))
#define CMP_DLY_ygdelay_src(data)                                                    ((0x000000C0&(data))>>6)
#define CMP_DLY_get_ygdelay(data)                                                    ((0x000000C0&(data))>>6)
#define CMP_DLY_write_en2_shift                                                      (5)
#define CMP_DLY_write_en2_mask                                                       (0x00000020)
#define CMP_DLY_write_en2(data)                                                      (0x00000020&((data)<<5))
#define CMP_DLY_write_en2_src(data)                                                  ((0x00000020&(data))>>5)
#define CMP_DLY_get_write_en2(data)                                                  ((0x00000020&(data))>>5)
#define CMP_DLY_bdelay_shift                                                         (3)
#define CMP_DLY_bdelay_mask                                                          (0x00000018)
#define CMP_DLY_bdelay(data)                                                         (0x00000018&((data)<<3))
#define CMP_DLY_bdelay_src(data)                                                     ((0x00000018&(data))>>3)
#define CMP_DLY_get_bdelay(data)                                                     ((0x00000018&(data))>>3)
#define CMP_DLY_write_en1_shift                                                      (2)
#define CMP_DLY_write_en1_mask                                                       (0x00000004)
#define CMP_DLY_write_en1(data)                                                      (0x00000004&((data)<<2))
#define CMP_DLY_write_en1_src(data)                                                  ((0x00000004&(data))>>2)
#define CMP_DLY_get_write_en1(data)                                                  ((0x00000004&(data))>>2)
#define CMP_DLY_rdelay_shift                                                         (0)
#define CMP_DLY_rdelay_mask                                                          (0x00000003)
#define CMP_DLY_rdelay(data)                                                         (0x00000003&((data)<<0))
#define CMP_DLY_rdelay_src(data)                                                     ((0x00000003&(data))>>0)
#define CMP_DLY_get_rdelay(data)                                                     ((0x00000003&(data))>>0)


#define DAC_MISC                                                                     0x1801F210
#define DAC_MISC_reg_addr                                                            "0xB800A210"
#define DAC_MISC_reg                                                                0xB801F210
#define set_DAC_MISC_reg(data)   (*((volatile unsigned int*) DAC_MISC_reg)=data)
#define get_DAC_MISC_reg   (*((volatile unsigned int*) DAC_MISC_reg))
#define DAC_MISC_inst_adr                                                            "0x0084"
#define DAC_MISC_inst                                                                0x0084
#define DAC_MISC_write_en4_shift                                                     (25)
#define DAC_MISC_write_en4_mask                                                      (0x02000000)
#define DAC_MISC_write_en4(data)                                                     (0x02000000&((data)<<25))
#define DAC_MISC_write_en4_src(data)                                                 ((0x02000000&(data))>>25)
#define DAC_MISC_get_write_en4(data)                                                 ((0x02000000&(data))>>25)
#define DAC_MISC_out_control123_shift                                                (22)
#define DAC_MISC_out_control123_mask                                                 (0x01C00000)
#define DAC_MISC_out_control123(data)                                                (0x01C00000&((data)<<22))
#define DAC_MISC_out_control123_src(data)                                            ((0x01C00000&(data))>>22)
#define DAC_MISC_get_out_control123(data)                                            ((0x01C00000&(data))>>22)
#define DAC_MISC_write_en3_shift                                                     (21)
#define DAC_MISC_write_en3_mask                                                      (0x00200000)
#define DAC_MISC_write_en3(data)                                                     (0x00200000&((data)<<21))
#define DAC_MISC_write_en3_src(data)                                                 ((0x00200000&(data))>>21)
#define DAC_MISC_get_write_en3(data)                                                 ((0x00200000&(data))>>21)
#define DAC_MISC_neg_out_shift                                                       (15)
#define DAC_MISC_neg_out_mask                                                        (0x001F8000)
#define DAC_MISC_neg_out(data)                                                       (0x001F8000&((data)<<15))
#define DAC_MISC_neg_out_src(data)                                                   ((0x001F8000&(data))>>15)
#define DAC_MISC_get_neg_out(data)                                                   ((0x001F8000&(data))>>15)
#define DAC_MISC_write_en2_shift                                                     (14)
#define DAC_MISC_write_en2_mask                                                      (0x00004000)
#define DAC_MISC_write_en2(data)                                                     (0x00004000&((data)<<14))
#define DAC_MISC_write_en2_src(data)                                                 ((0x00004000&(data))>>14)
#define DAC_MISC_get_write_en2(data)                                                 ((0x00004000&(data))>>14)
#define DAC_MISC_out_control_shift                                                   (13)
#define DAC_MISC_out_control_mask                                                    (0x00002000)
#define DAC_MISC_out_control(data)                                                   (0x00002000&((data)<<13))
#define DAC_MISC_out_control_src(data)                                               ((0x00002000&(data))>>13)
#define DAC_MISC_get_out_control(data)                                               ((0x00002000&(data))>>13)
#define DAC_MISC_write_en1_shift                                                     (12)
#define DAC_MISC_write_en1_mask                                                      (0x00001000)
#define DAC_MISC_write_en1(data)                                                     (0x00001000&((data)<<12))
#define DAC_MISC_write_en1_src(data)                                                 ((0x00001000&(data))>>12)
#define DAC_MISC_get_write_en1(data)                                                 ((0x00001000&(data))>>12)
#define DAC_MISC_dac_value_shift                                                     (2)
#define DAC_MISC_dac_value_mask                                                      (0x00000FFC)
#define DAC_MISC_dac_value(data)                                                     (0x00000FFC&((data)<<2))
#define DAC_MISC_dac_value_src(data)                                                 ((0x00000FFC&(data))>>2)
#define DAC_MISC_get_dac_value(data)                                                 ((0x00000FFC&(data))>>2)


#define DAC_MISC1                                                                    0x1801F224
#define DAC_MISC1_reg_addr                                                           "0xB800A224"
#define DAC_MISC1_reg                                                               0xB801F224
#define set_DAC_MISC1_reg(data)   (*((volatile unsigned int*) DAC_MISC1_reg)=data)
#define get_DAC_MISC1_reg   (*((volatile unsigned int*) DAC_MISC1_reg))
#define DAC_MISC1_inst_adr                                                           "0x0089"
#define DAC_MISC1_inst                                                               0x0089
#define DAC_MISC1_dac_value3_shift                                                   (20)
#define DAC_MISC1_dac_value3_mask                                                    (0x3FF00000)
#define DAC_MISC1_dac_value3(data)                                                   (0x3FF00000&((data)<<20))
#define DAC_MISC1_dac_value3_src(data)                                               ((0x3FF00000&(data))>>20)
#define DAC_MISC1_get_dac_value3(data)                                               ((0x3FF00000&(data))>>20)
#define DAC_MISC1_dac_value2_shift                                                   (10)
#define DAC_MISC1_dac_value2_mask                                                    (0x000FFC00)
#define DAC_MISC1_dac_value2(data)                                                   (0x000FFC00&((data)<<10))
#define DAC_MISC1_dac_value2_src(data)                                               ((0x000FFC00&(data))>>10)
#define DAC_MISC1_get_dac_value2(data)                                               ((0x000FFC00&(data))>>10)
#define DAC_MISC1_dac_value1_shift                                                   (0)
#define DAC_MISC1_dac_value1_mask                                                    (0x000003FF)
#define DAC_MISC1_dac_value1(data)                                                   (0x000003FF&((data)<<0))
#define DAC_MISC1_dac_value1_src(data)                                               ((0x000003FF&(data))>>0)
#define DAC_MISC1_get_dac_value1(data)                                               ((0x000003FF&(data))>>0)


#define TVE_DBG                                                                          0x1801F214
#define TVE_DBG_reg_addr                                                                 "0xB800A214"
#define TVE_DBG_reg                                                                     0xB801F214
#define TVE_set_DBG_reg(data)   (*((volatile unsigned int*) DBG_reg)=data)
#define TVE_get_DBG_reg   (*((volatile unsigned int*) DBG_reg))
#define TVE_DBG_inst_adr                                                                 "0x0085"
#define TVE_DBG_inst                                                                     0x0085
#define TVE_DBG_write_en3_shift                                                          (11)
#define TVE_DBG_write_en3_mask                                                           (0x00000800)
#define TVE_DBG_write_en3(data)                                                          (0x00000800&((data)<<11))
#define TVE_DBG_write_en3_src(data)                                                      ((0x00000800&(data))>>11)
#define TVE_DBG_get_write_en3(data)                                                      ((0x00000800&(data))>>11)
#define TVE_DBG_sel1_shift                                                               (7)
#define TVE_DBG_sel1_mask                                                                (0x00000780)
#define TVE_DBG_sel1(data)                                                               (0x00000780&((data)<<7))
#define TVE_DBG_sel1_src(data)                                                           ((0x00000780&(data))>>7)
#define TVE_DBG_get_sel1(data)                                                           ((0x00000780&(data))>>7)
#define TVE_DBG_write_en2_shift                                                          (6)
#define TVE_DBG_write_en2_mask                                                           (0x00000040)
#define TVE_DBG_write_en2(data)                                                          (0x00000040&((data)<<6))
#define TVE_DBG_write_en2_src(data)                                                      ((0x00000040&(data))>>6)
#define TVE_DBG_get_write_en2(data)                                                      ((0x00000040&(data))>>6)
#define TVE_DBG_sel0_shift                                                               (2)
#define TVE_DBG_sel0_mask                                                                (0x0000003C)
#define TVE_DBG_sel0(data)                                                               (0x0000003C&((data)<<2))
#define TVE_DBG_sel0_src(data)                                                           ((0x0000003C&(data))>>2)
#define TVE_DBG_get_sel0(data)                                                           ((0x0000003C&(data))>>2)
#define TVE_DBG_write_en1_shift                                                          (1)
#define TVE_DBG_write_en1_mask                                                           (0x00000002)
#define TVE_DBG_write_en1(data)                                                          (0x00000002&((data)<<1))
#define TVE_DBG_write_en1_src(data)                                                      ((0x00000002&(data))>>1)
#define TVE_DBG_get_write_en1(data)                                                      ((0x00000002&(data))>>1)
#define TVE_DBG_enable_shift                                                             (0)
#define TVE_DBG_enable_mask                                                              (0x00000001)
#define TVE_DBG_enable(data)                                                             (0x00000001&((data)<<0))
#define TVE_DBG_enable_src(data)                                                         ((0x00000001&(data))>>0)
#define TVE_DBG_get_enable(data)                                                         ((0x00000001&(data))>>0)


#define DUMMY_0                                                                      0x1801F300
#define DUMMY_1                                                                      0x1801F304
#define DUMMY_0_reg_addr                                                             "0xB800A300"
#define DUMMY_1_reg_addr                                                             "0xB800A304"
#define DUMMY_0_reg                                                                 0xB801F300
#define DUMMY_1_reg                                                                 0xB801F304
#define set_DUMMY_0_reg(data)   (*((volatile unsigned int*) DUMMY_0_reg)=data)
#define set_DUMMY_1_reg(data)   (*((volatile unsigned int*) DUMMY_1_reg)=data)
#define get_DUMMY_0_reg   (*((volatile unsigned int*) DUMMY_0_reg))
#define get_DUMMY_1_reg   (*((volatile unsigned int*) DUMMY_1_reg))
#define DUMMY_0_inst_adr                                                             "0x00C0"
#define DUMMY_1_inst_adr                                                             "0x00C1"
#define DUMMY_0_inst                                                                 0x00C0
#define DUMMY_1_inst                                                                 0x00C1
#define DUMMY_dummy_shift                                                            (0)
#define DUMMY_dummy_mask                                                             (0xFFFFFFFF)
#define DUMMY_dummy(data)                                                            (0xFFFFFFFF&((data)<<0))
#define DUMMY_dummy_src(data)                                                        ((0xFFFFFFFF&(data))>>0)
#define DUMMY_get_dummy(data)                                                        ((0xFFFFFFFF&(data))>>0)


#define DAC_TEST                                                                     0x1801F344
#define DAC_TEST_reg_addr                                                            "0xB800A344"
#define DAC_TEST_reg                                                                0xB801F344
#define set_DAC_TEST_reg(data)   (*((volatile unsigned int*) DAC_TEST_reg)=data)
#define get_DAC_TEST_reg   (*((volatile unsigned int*) DAC_TEST_reg))
#define DAC_TEST_inst_adr                                                            "0x00D1"
#define DAC_TEST_inst                                                                0x00D1
#define DAC_TEST_aio_dac_en_shift                                                    (2)
#define DAC_TEST_aio_dac_en_mask                                                     (0x00000004)
#define DAC_TEST_aio_dac_en(data)                                                    (0x00000004&((data)<<2))
#define DAC_TEST_aio_dac_en_src(data)                                                ((0x00000004&(data))>>2)
#define DAC_TEST_get_aio_dac_en(data)                                                ((0x00000004&(data))>>2)
#define DAC_TEST_dac1_en_shift                                                       (1)
#define DAC_TEST_dac1_en_mask                                                        (0x00000002)
#define DAC_TEST_dac1_en(data)                                                       (0x00000002&((data)<<1))
#define DAC_TEST_dac1_en_src(data)                                                   ((0x00000002&(data))>>1)
#define DAC_TEST_get_dac1_en(data)                                                   ((0x00000002&(data))>>1)
#define DAC_TEST_dac0_en_shift                                                       (0)
#define DAC_TEST_dac0_en_mask                                                        (0x00000001)
#define DAC_TEST_dac0_en(data)                                                       (0x00000001&((data)<<0))
#define DAC_TEST_dac0_en_src(data)                                                   ((0x00000001&(data))>>0)
#define DAC_TEST_get_dac0_en(data)                                                   ((0x00000001&(data))>>0)


#define INTVBI_I                                                                     0x1801F348
#define INTVBI_I_reg_addr                                                            "0xB800A348"
#define INTVBI_I_reg                                                                0xB801F348
#define set_INTVBI_I_reg(data)   (*((volatile unsigned int*) INTVBI_I_reg)=data)
#define get_INTVBI_I_reg   (*((volatile unsigned int*) INTVBI_I_reg))
#define INTVBI_I_inst_adr                                                            "0x00D2"
#define INTVBI_I_inst                                                                0x00D2
#define INTVBI_I_write_en2_shift                                                     (25)
#define INTVBI_I_write_en2_mask                                                      (0x02000000)
#define INTVBI_I_write_en2(data)                                                     (0x02000000&((data)<<25))
#define INTVBI_I_write_en2_src(data)                                                 ((0x02000000&(data))>>25)
#define INTVBI_I_get_write_en2(data)                                                 ((0x02000000&(data))>>25)
#define INTVBI_I_int_vpos_shift                                                      (14)
#define INTVBI_I_int_vpos_mask                                                       (0x01FFC000)
#define INTVBI_I_int_vpos(data)                                                      (0x01FFC000&((data)<<14))
#define INTVBI_I_int_vpos_src(data)                                                  ((0x01FFC000&(data))>>14)
#define INTVBI_I_get_int_vpos(data)                                                  ((0x01FFC000&(data))>>14)
#define INTVBI_I_write_en1_shift                                                     (13)
#define INTVBI_I_write_en1_mask                                                      (0x00002000)
#define INTVBI_I_write_en1(data)                                                     (0x00002000&((data)<<13))
#define INTVBI_I_write_en1_src(data)                                                 ((0x00002000&(data))>>13)
#define INTVBI_I_get_write_en1(data)                                                 ((0x00002000&(data))>>13)
#define INTVBI_I_int_hpos_shift                                                      (0)
#define INTVBI_I_int_hpos_mask                                                       (0x00001FFF)
#define INTVBI_I_int_hpos(data)                                                      (0x00001FFF&((data)<<0))
#define INTVBI_I_int_hpos_src(data)                                                  ((0x00001FFF&(data))>>0)
#define INTVBI_I_get_int_hpos(data)                                                  ((0x00001FFF&(data))>>0)


#define INTVBI_P1                                                                    0x1801F34c
#define INTVBI_P1_reg_addr                                                           "0xB800A34C"
#define INTVBI_P1_reg                                                               0xB801F34C
#define set_INTVBI_P1_reg(data)   (*((volatile unsigned int*) INTVBI_P1_reg)=data)
#define get_INTVBI_P1_reg   (*((volatile unsigned int*) INTVBI_P1_reg))
#define INTVBI_P1_inst_adr                                                           "0x00D3"
#define INTVBI_P1_inst                                                               0x00D3
#define INTVBI_P1_write_en2_shift                                                    (25)
#define INTVBI_P1_write_en2_mask                                                     (0x02000000)
#define INTVBI_P1_write_en2(data)                                                    (0x02000000&((data)<<25))
#define INTVBI_P1_write_en2_src(data)                                                ((0x02000000&(data))>>25)
#define INTVBI_P1_get_write_en2(data)                                                ((0x02000000&(data))>>25)
#define INTVBI_P1_int_vpos_shift                                                     (14)
#define INTVBI_P1_int_vpos_mask                                                      (0x01FFC000)
#define INTVBI_P1_int_vpos(data)                                                     (0x01FFC000&((data)<<14))
#define INTVBI_P1_int_vpos_src(data)                                                 ((0x01FFC000&(data))>>14)
#define INTVBI_P1_get_int_vpos(data)                                                 ((0x01FFC000&(data))>>14)
#define INTVBI_P1_write_en1_shift                                                    (13)
#define INTVBI_P1_write_en1_mask                                                     (0x00002000)
#define INTVBI_P1_write_en1(data)                                                    (0x00002000&((data)<<13))
#define INTVBI_P1_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define INTVBI_P1_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define INTVBI_P1_int_hpos_shift                                                     (0)
#define INTVBI_P1_int_hpos_mask                                                      (0x00001FFF)
#define INTVBI_P1_int_hpos(data)                                                     (0x00001FFF&((data)<<0))
#define INTVBI_P1_int_hpos_src(data)                                                 ((0x00001FFF&(data))>>0)
#define INTVBI_P1_get_int_hpos(data)                                                 ((0x00001FFF&(data))>>0)


#define INTVBI_P2                                                                    0x1801F370
#define INTVBI_P2_reg_addr                                                           "0xB800A370"
#define INTVBI_P2_reg                                                               0xB801F370
#define set_INTVBI_P2_reg(data)   (*((volatile unsigned int*) INTVBI_P2_reg)=data)
#define get_INTVBI_P2_reg   (*((volatile unsigned int*) INTVBI_P2_reg))
#define INTVBI_P2_inst_adr                                                           "0x00DC"
#define INTVBI_P2_inst                                                               0x00DC
#define INTVBI_P2_write_en2_shift                                                    (25)
#define INTVBI_P2_write_en2_mask                                                     (0x02000000)
#define INTVBI_P2_write_en2(data)                                                    (0x02000000&((data)<<25))
#define INTVBI_P2_write_en2_src(data)                                                ((0x02000000&(data))>>25)
#define INTVBI_P2_get_write_en2(data)                                                ((0x02000000&(data))>>25)
#define INTVBI_P2_int_vpos_shift                                                     (14)
#define INTVBI_P2_int_vpos_mask                                                      (0x01FFC000)
#define INTVBI_P2_int_vpos(data)                                                     (0x01FFC000&((data)<<14))
#define INTVBI_P2_int_vpos_src(data)                                                 ((0x01FFC000&(data))>>14)
#define INTVBI_P2_get_int_vpos(data)                                                 ((0x01FFC000&(data))>>14)
#define INTVBI_P2_write_en1_shift                                                    (13)
#define INTVBI_P2_write_en1_mask                                                     (0x00002000)
#define INTVBI_P2_write_en1(data)                                                    (0x00002000&((data)<<13))
#define INTVBI_P2_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define INTVBI_P2_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define INTVBI_P2_int_hpos_shift                                                     (0)
#define INTVBI_P2_int_hpos_mask                                                      (0x00001FFF)
#define INTVBI_P2_int_hpos(data)                                                     (0x00001FFF&((data)<<0))
#define INTVBI_P2_int_hpos_src(data)                                                 ((0x00001FFF&(data))>>0)
#define INTVBI_P2_get_int_hpos(data)                                                 ((0x00001FFF&(data))>>0)


#define INTVBI_H1                                                                    0x1801F374
#define INTVBI_H1_reg_addr                                                           "0xB800A374"
#define INTVBI_H1_reg                                                               0xB801F374
#define set_INTVBI_H1_reg(data)   (*((volatile unsigned int*) INTVBI_H1_reg)=data)
#define get_INTVBI_H1_reg   (*((volatile unsigned int*) INTVBI_H1_reg))
#define INTVBI_H1_inst_adr                                                           "0x00DD"
#define INTVBI_H1_inst                                                               0x00DD
#define INTVBI_H1_write_en2_shift                                                    (25)
#define INTVBI_H1_write_en2_mask                                                     (0x02000000)
#define INTVBI_H1_write_en2(data)                                                    (0x02000000&((data)<<25))
#define INTVBI_H1_write_en2_src(data)                                                ((0x02000000&(data))>>25)
#define INTVBI_H1_get_write_en2(data)                                                ((0x02000000&(data))>>25)
#define INTVBI_H1_int_vpos_shift                                                     (14)
#define INTVBI_H1_int_vpos_mask                                                      (0x01FFC000)
#define INTVBI_H1_int_vpos(data)                                                     (0x01FFC000&((data)<<14))
#define INTVBI_H1_int_vpos_src(data)                                                 ((0x01FFC000&(data))>>14)
#define INTVBI_H1_get_int_vpos(data)                                                 ((0x01FFC000&(data))>>14)
#define INTVBI_H1_write_en1_shift                                                    (13)
#define INTVBI_H1_write_en1_mask                                                     (0x00002000)
#define INTVBI_H1_write_en1(data)                                                    (0x00002000&((data)<<13))
#define INTVBI_H1_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define INTVBI_H1_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define INTVBI_H1_int_hpos_shift                                                     (0)
#define INTVBI_H1_int_hpos_mask                                                      (0x00001FFF)
#define INTVBI_H1_int_hpos(data)                                                     (0x00001FFF&((data)<<0))
#define INTVBI_H1_int_hpos_src(data)                                                 ((0x00001FFF&(data))>>0)
#define INTVBI_H1_get_int_hpos(data)                                                 ((0x00001FFF&(data))>>0)


#define INTVBI_H2                                                                    0x1801F378
#define INTVBI_H2_reg_addr                                                           "0xB800A378"
#define INTVBI_H2_reg                                                               0xB801F378
#define set_INTVBI_H2_reg(data)   (*((volatile unsigned int*) INTVBI_H2_reg)=data)
#define get_INTVBI_H2_reg   (*((volatile unsigned int*) INTVBI_H2_reg))
#define INTVBI_H2_inst_adr                                                           "0x00DE"
#define INTVBI_H2_inst                                                               0x00DE
#define INTVBI_H2_write_en2_shift                                                    (25)
#define INTVBI_H2_write_en2_mask                                                     (0x02000000)
#define INTVBI_H2_write_en2(data)                                                    (0x02000000&((data)<<25))
#define INTVBI_H2_write_en2_src(data)                                                ((0x02000000&(data))>>25)
#define INTVBI_H2_get_write_en2(data)                                                ((0x02000000&(data))>>25)
#define INTVBI_H2_int_vpos_shift                                                     (14)
#define INTVBI_H2_int_vpos_mask                                                      (0x01FFC000)
#define INTVBI_H2_int_vpos(data)                                                     (0x01FFC000&((data)<<14))
#define INTVBI_H2_int_vpos_src(data)                                                 ((0x01FFC000&(data))>>14)
#define INTVBI_H2_get_int_vpos(data)                                                 ((0x01FFC000&(data))>>14)
#define INTVBI_H2_write_en1_shift                                                    (13)
#define INTVBI_H2_write_en1_mask                                                     (0x00002000)
#define INTVBI_H2_write_en1(data)                                                    (0x00002000&((data)<<13))
#define INTVBI_H2_write_en1_src(data)                                                ((0x00002000&(data))>>13)
#define INTVBI_H2_get_write_en1(data)                                                ((0x00002000&(data))>>13)
#define INTVBI_H2_int_hpos_shift                                                     (0)
#define INTVBI_H2_int_hpos_mask                                                      (0x00001FFF)
#define INTVBI_H2_int_hpos(data)                                                     (0x00001FFF&((data)<<0))
#define INTVBI_H2_int_hpos_src(data)                                                 ((0x00001FFF&(data))>>0)
#define INTVBI_H2_get_int_hpos(data)                                                 ((0x00001FFF&(data))>>0)


#define DAC1_FIR_1                                                                   0x1801F37c
#define DAC1_FIR_1_reg_addr                                                          "0xB800A37C"
#define DAC1_FIR_1_reg                                                              0xB801F37C
#define set_DAC1_FIR_1_reg(data)   (*((volatile unsigned int*) DAC1_FIR_1_reg)=data)
#define get_DAC1_FIR_1_reg   (*((volatile unsigned int*) DAC1_FIR_1_reg))
#define DAC1_FIR_1_inst_adr                                                          "0x00DF"
#define DAC1_FIR_1_inst                                                              0x00DF
#define DAC1_FIR_1_c1_shift                                                          (16)
#define DAC1_FIR_1_c1_mask                                                           (0x3FFF0000)
#define DAC1_FIR_1_c1(data)                                                          (0x3FFF0000&((data)<<16))
#define DAC1_FIR_1_c1_src(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC1_FIR_1_get_c1(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC1_FIR_1_c0_shift                                                          (0)
#define DAC1_FIR_1_c0_mask                                                           (0x00003FFF)
#define DAC1_FIR_1_c0(data)                                                          (0x00003FFF&((data)<<0))
#define DAC1_FIR_1_c0_src(data)                                                      ((0x00003FFF&(data))>>0)
#define DAC1_FIR_1_get_c0(data)                                                      ((0x00003FFF&(data))>>0)


#define DAC1_FIR_2                                                                   0x1801F380
#define DAC1_FIR_2_reg_addr                                                          "0xB800A380"
#define DAC1_FIR_2_reg                                                              0xB801F380
#define set_DAC1_FIR_2_reg(data)   (*((volatile unsigned int*) DAC1_FIR_2_reg)=data)
#define get_DAC1_FIR_2_reg   (*((volatile unsigned int*) DAC1_FIR_2_reg))
#define DAC1_FIR_2_inst_adr                                                          "0x00E0"
#define DAC1_FIR_2_inst                                                              0x00E0
#define DAC1_FIR_2_c3_shift                                                          (16)
#define DAC1_FIR_2_c3_mask                                                           (0x3FFF0000)
#define DAC1_FIR_2_c3(data)                                                          (0x3FFF0000&((data)<<16))
#define DAC1_FIR_2_c3_src(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC1_FIR_2_get_c3(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC1_FIR_2_c2_shift                                                          (0)
#define DAC1_FIR_2_c2_mask                                                           (0x00003FFF)
#define DAC1_FIR_2_c2(data)                                                          (0x00003FFF&((data)<<0))
#define DAC1_FIR_2_c2_src(data)                                                      ((0x00003FFF&(data))>>0)
#define DAC1_FIR_2_get_c2(data)                                                      ((0x00003FFF&(data))>>0)


#define DAC2_FIR_1                                                                   0x1801F388
#define DAC2_FIR_1_reg_addr                                                          "0xB800A388"
#define DAC2_FIR_1_reg                                                              0xB801F388
#define set_DAC2_FIR_1_reg(data)   (*((volatile unsigned int*) DAC2_FIR_1_reg)=data)
#define get_DAC2_FIR_1_reg   (*((volatile unsigned int*) DAC2_FIR_1_reg))
#define DAC2_FIR_1_inst_adr                                                          "0x00E2"
#define DAC2_FIR_1_inst                                                              0x00E2
#define DAC2_FIR_1_c1_shift                                                          (16)
#define DAC2_FIR_1_c1_mask                                                           (0x3FFF0000)
#define DAC2_FIR_1_c1(data)                                                          (0x3FFF0000&((data)<<16))
#define DAC2_FIR_1_c1_src(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC2_FIR_1_get_c1(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC2_FIR_1_c0_shift                                                          (0)
#define DAC2_FIR_1_c0_mask                                                           (0x00003FFF)
#define DAC2_FIR_1_c0(data)                                                          (0x00003FFF&((data)<<0))
#define DAC2_FIR_1_c0_src(data)                                                      ((0x00003FFF&(data))>>0)
#define DAC2_FIR_1_get_c0(data)                                                      ((0x00003FFF&(data))>>0)


#define DAC2_FIR_2                                                                   0x1801F38c
#define DAC2_FIR_2_reg_addr                                                          "0xB800A38C"
#define DAC2_FIR_2_reg                                                              0xB801F38C
#define set_DAC2_FIR_2_reg(data)   (*((volatile unsigned int*) DAC2_FIR_2_reg)=data)
#define get_DAC2_FIR_2_reg   (*((volatile unsigned int*) DAC2_FIR_2_reg))
#define DAC2_FIR_2_inst_adr                                                          "0x00E3"
#define DAC2_FIR_2_inst                                                              0x00E3
#define DAC2_FIR_2_c3_shift                                                          (16)
#define DAC2_FIR_2_c3_mask                                                           (0x3FFF0000)
#define DAC2_FIR_2_c3(data)                                                          (0x3FFF0000&((data)<<16))
#define DAC2_FIR_2_c3_src(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC2_FIR_2_get_c3(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC2_FIR_2_c2_shift                                                          (0)
#define DAC2_FIR_2_c2_mask                                                           (0x00003FFF)
#define DAC2_FIR_2_c2(data)                                                          (0x00003FFF&((data)<<0))
#define DAC2_FIR_2_c2_src(data)                                                      ((0x00003FFF&(data))>>0)
#define DAC2_FIR_2_get_c2(data)                                                      ((0x00003FFF&(data))>>0)


#define DAC3_FIR_1                                                                   0x1801F390
#define DAC3_FIR_1_reg_addr                                                          "0xB800A390"
#define DAC3_FIR_1_reg                                                              0xB801F390
#define set_DAC3_FIR_1_reg(data)   (*((volatile unsigned int*) DAC3_FIR_1_reg)=data)
#define get_DAC3_FIR_1_reg   (*((volatile unsigned int*) DAC3_FIR_1_reg))
#define DAC3_FIR_1_inst_adr                                                          "0x00E4"
#define DAC3_FIR_1_inst                                                              0x00E4
#define DAC3_FIR_1_c1_shift                                                          (16)
#define DAC3_FIR_1_c1_mask                                                           (0x3FFF0000)
#define DAC3_FIR_1_c1(data)                                                          (0x3FFF0000&((data)<<16))
#define DAC3_FIR_1_c1_src(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC3_FIR_1_get_c1(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC3_FIR_1_c0_shift                                                          (0)
#define DAC3_FIR_1_c0_mask                                                           (0x00003FFF)
#define DAC3_FIR_1_c0(data)                                                          (0x00003FFF&((data)<<0))
#define DAC3_FIR_1_c0_src(data)                                                      ((0x00003FFF&(data))>>0)
#define DAC3_FIR_1_get_c0(data)                                                      ((0x00003FFF&(data))>>0)


#define DAC3_FIR_2                                                                   0x1801F394
#define DAC3_FIR_2_reg_addr                                                          "0xB800A394"
#define DAC3_FIR_2_reg                                                              0xB801F394
#define set_DAC3_FIR_2_reg(data)   (*((volatile unsigned int*) DAC3_FIR_2_reg)=data)
#define get_DAC3_FIR_2_reg   (*((volatile unsigned int*) DAC3_FIR_2_reg))
#define DAC3_FIR_2_inst_adr                                                          "0x00E5"
#define DAC3_FIR_2_inst                                                              0x00E5
#define DAC3_FIR_2_c3_shift                                                          (16)
#define DAC3_FIR_2_c3_mask                                                           (0x3FFF0000)
#define DAC3_FIR_2_c3(data)                                                          (0x3FFF0000&((data)<<16))
#define DAC3_FIR_2_c3_src(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC3_FIR_2_get_c3(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC3_FIR_2_c2_shift                                                          (0)
#define DAC3_FIR_2_c2_mask                                                           (0x00003FFF)
#define DAC3_FIR_2_c2(data)                                                          (0x00003FFF&((data)<<0))
#define DAC3_FIR_2_c2_src(data)                                                      ((0x00003FFF&(data))>>0)
#define DAC3_FIR_2_get_c2(data)                                                      ((0x00003FFF&(data))>>0)


#define DAC4_FIR_1                                                                   0x1801F398
#define DAC4_FIR_1_reg_addr                                                          "0xB800A398"
#define DAC4_FIR_1_reg                                                              0xB801F398
#define set_DAC4_FIR_1_reg(data)   (*((volatile unsigned int*) DAC4_FIR_1_reg)=data)
#define get_DAC4_FIR_1_reg   (*((volatile unsigned int*) DAC4_FIR_1_reg))
#define DAC4_FIR_1_inst_adr                                                          "0x00E6"
#define DAC4_FIR_1_inst                                                              0x00E6
#define DAC4_FIR_1_c1_shift                                                          (16)
#define DAC4_FIR_1_c1_mask                                                           (0x3FFF0000)
#define DAC4_FIR_1_c1(data)                                                          (0x3FFF0000&((data)<<16))
#define DAC4_FIR_1_c1_src(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC4_FIR_1_get_c1(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC4_FIR_1_c0_shift                                                          (0)
#define DAC4_FIR_1_c0_mask                                                           (0x00003FFF)
#define DAC4_FIR_1_c0(data)                                                          (0x00003FFF&((data)<<0))
#define DAC4_FIR_1_c0_src(data)                                                      ((0x00003FFF&(data))>>0)
#define DAC4_FIR_1_get_c0(data)                                                      ((0x00003FFF&(data))>>0)


#define DAC4_FIR_2                                                                   0x1801F39c
#define DAC4_FIR_2_reg_addr                                                          "0xB800A39C"
#define DAC4_FIR_2_reg                                                              0xB801F39C
#define set_DAC4_FIR_2_reg(data)   (*((volatile unsigned int*) DAC4_FIR_2_reg)=data)
#define get_DAC4_FIR_2_reg   (*((volatile unsigned int*) DAC4_FIR_2_reg))
#define DAC4_FIR_2_inst_adr                                                          "0x00E7"
#define DAC4_FIR_2_inst                                                              0x00E7
#define DAC4_FIR_2_c3_shift                                                          (16)
#define DAC4_FIR_2_c3_mask                                                           (0x3FFF0000)
#define DAC4_FIR_2_c3(data)                                                          (0x3FFF0000&((data)<<16))
#define DAC4_FIR_2_c3_src(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC4_FIR_2_get_c3(data)                                                      ((0x3FFF0000&(data))>>16)
#define DAC4_FIR_2_c2_shift                                                          (0)
#define DAC4_FIR_2_c2_mask                                                           (0x00003FFF)
#define DAC4_FIR_2_c2(data)                                                          (0x00003FFF&((data)<<0))
#define DAC4_FIR_2_c2_src(data)                                                      ((0x00003FFF&(data))>>0)
#define DAC4_FIR_2_get_c2(data)                                                      ((0x00003FFF&(data))>>0)


#define DAC4_FIFO                                                                    0x1801F3a0
#define DAC4_FIFO_reg_addr                                                           "0xB800A3A0"
#define DAC4_FIFO_reg                                                               0xB801F3A0
#define set_DAC4_FIFO_reg(data)   (*((volatile unsigned int*) DAC4_FIFO_reg)=data)
#define get_DAC4_FIFO_reg   (*((volatile unsigned int*) DAC4_FIFO_reg))
#define DAC4_FIFO_inst_adr                                                           "0x00E8"
#define DAC4_FIFO_inst                                                               0x00E8
#define DAC4_FIFO_tve_sim_cntl_shift                                                 (2)
#define DAC4_FIFO_tve_sim_cntl_mask                                                  (0x00000004)
#define DAC4_FIFO_tve_sim_cntl(data)                                                 (0x00000004&((data)<<2))
#define DAC4_FIFO_tve_sim_cntl_src(data)                                             ((0x00000004&(data))>>2)
#define DAC4_FIFO_get_tve_sim_cntl(data)                                             ((0x00000004&(data))>>2)
#define DAC4_FIFO_empty_clr_shift                                                    (1)
#define DAC4_FIFO_empty_clr_mask                                                     (0x00000002)
#define DAC4_FIFO_empty_clr(data)                                                    (0x00000002&((data)<<1))
#define DAC4_FIFO_empty_clr_src(data)                                                ((0x00000002&(data))>>1)
#define DAC4_FIFO_get_empty_clr(data)                                                ((0x00000002&(data))>>1)
#define DAC4_FIFO_full_clr_shift                                                     (0)
#define DAC4_FIFO_full_clr_mask                                                      (0x00000001)
#define DAC4_FIFO_full_clr(data)                                                     (0x00000001&((data)<<0))
#define DAC4_FIFO_full_clr_src(data)                                                 ((0x00000001&(data))>>0)
#define DAC4_FIFO_get_full_clr(data)                                                 ((0x00000001&(data))>>0)


#define DAC4_FIFO_READ                                                               0x1801F3a4
#define DAC4_FIFO_READ_reg_addr                                                      "0xB800A3A4"
#define DAC4_FIFO_READ_reg                                                          0xB801F3A4
#define set_DAC4_FIFO_READ_reg(data)   (*((volatile unsigned int*) DAC4_FIFO_READ_reg)=data)
#define get_DAC4_FIFO_READ_reg   (*((volatile unsigned int*) DAC4_FIFO_READ_reg))
#define DAC4_FIFO_READ_inst_adr                                                      "0x00E9"
#define DAC4_FIFO_READ_inst                                                          0x00E9
#define DAC4_FIFO_READ_fifo_empty_shift                                              (1)
#define DAC4_FIFO_READ_fifo_empty_mask                                               (0x00000002)
#define DAC4_FIFO_READ_fifo_empty(data)                                              (0x00000002&((data)<<1))
#define DAC4_FIFO_READ_fifo_empty_src(data)                                          ((0x00000002&(data))>>1)
#define DAC4_FIFO_READ_get_fifo_empty(data)                                          ((0x00000002&(data))>>1)
#define DAC4_FIFO_READ_fifo_full_shift                                               (0)
#define DAC4_FIFO_READ_fifo_full_mask                                                (0x00000001)
#define DAC4_FIFO_READ_fifo_full(data)                                               (0x00000001&((data)<<0))
#define DAC4_FIFO_READ_fifo_full_src(data)                                           ((0x00000001&(data))>>0)
#define DAC4_FIFO_READ_get_fifo_full(data)                                           ((0x00000001&(data))>>0)


#endif

