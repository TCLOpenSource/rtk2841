/**************************************************************
// Spec Version                  : 0.3
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014/1/28 15:31:13
***************************************************************/


#ifndef _SCPU_A12_REG_H_INCLUDED_
#define _SCPU_A12_REG_H_INCLUDED_
#ifdef  _SCPU_A12_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     pmuirq_o:1;
unsigned int     event_o:1;
unsigned int     nctiirq:1;
unsigned int     nfiqout:1;
unsigned int     nirqout:1;
unsigned int     naxierrirq:1;
}SCPU_A12_STAT0;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     standbywfi:1;
unsigned int     standbywfil2:1;
unsigned int     standbywfe:1;
}SCPU_A12_STAT1;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     dbgpwrupreq:4;
unsigned int     dbgnopwrdwn:4;
}SCPU_A12_STAT2;

typedef struct 
{
unsigned int     pmuevent0:32;
}SCPU_A12_STAT3;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     pmuevent0_h:6;
}SCPU_A12_STAT3;

typedef struct 
{
unsigned int     reserved_0:17;
unsigned int     l2rstdisable:1;
unsigned int     aclkenm:1;
unsigned int     teinit:4;
unsigned int     cfgend:4;
unsigned int     event_i:1;
unsigned int     edbgrq:4;
}SCPU_A12_CTRL0;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     dbgpwrdup:4;
unsigned int     vinithi:4;
}SCPU_A12_CTRL1;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     dbgromaddrv:1;
unsigned int     dbgromaddr:28;
}SCPU_A12_CTRL3;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     dbgselfaddrv:1;
unsigned int     dbgselfaddr:23;
}SCPU_A12_CTRL4;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     cssys_cpwrupreq_sys:1;
unsigned int     cssys_cdbgrstreq:1;
unsigned int     cssys_cpwrupreq_dbg:1;
unsigned int     cssys_jtagtop:1;
unsigned int     cssys_jtagnsw:1;
}SCPU_A12_CS_STAT0;

typedef struct 
{
unsigned int     reserved_0:2;
unsigned int     cssys_ctiapbsbypass:1;
unsigned int     cssys_todbgensel:2;
unsigned int     cssys_revision:4;
unsigned int     cssys_partnumber:12;
unsigned int     cssys_cpwrupack_sys:1;
unsigned int     cssys_cdbgrstack:1;
unsigned int     cssys_cpwrupack_dbg:1;
unsigned int     cssys_tpmaxdatasize:5;
unsigned int     cssys_tpctl:1;
unsigned int     cssys_niden:1;
unsigned int     cssys_dbgen:1;
}SCPU_A12_CS_CTRL0;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     tckchange:1;
}SCPU_A12_TCKCHANGE;

typedef struct 
{
unsigned int     apb_cssys_a:32;
}SCPU_A12_APB_CSSYS0;

typedef struct 
{
unsigned int     apb_cssys_d:32;
}SCPU_A12_APB_CSSYS1;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     apb_cssys_slverr:1;
}SCPU_A12_APB_ERR;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     fbusrandwstrb:1;
unsigned int     remote_cmd_num:4;
unsigned int     remote_wdata_num:4;
unsigned int     wcmd_bufable_sel:2;
unsigned int     wr_outstand_num:4;
unsigned int     rd_outstand_num:4;
}SCPU_A12_SCPU_A12_CTRL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     scpu_dbg_sel:4;
}SCPU_A12_CTRL2;

typedef struct 
{
unsigned int     dbg_start_addr_m0:32;
}SCPU_A12_DBG_START;

typedef struct 
{
unsigned int     dbg_end_addr_m0:32;
}SCPU_A12_DBG_END;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     write_en2:1;
unsigned int     dbg_wr_chk_m0:2;
unsigned int     write_en1:1;
unsigned int     dbg_en_m0:1;
}SCPU_A12_DBG_CTRL;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     scpu_int_m0:1;
unsigned int     scpu_int_en_m0:1;
unsigned int     scpu_neg_int_m0:1;
unsigned int     scpu_neg_int_en_m0:1;
unsigned int     write_data:1;
}SCPU_A12_DBG_INT;

typedef struct 
{
unsigned int     dbg_addr_m0:32;
}SCPU_A12_DBG_ADDR;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_dbg_write_m0:1;
}SCPU_A12_DBG_ADDR1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     dss_c35_speed_en:1;
unsigned int     dss_c35_data_in:20;
unsigned int     dss_c35_wire_sel:1;
unsigned int     dss_c35_ro_sel:3;
unsigned int     dss_c35_dss_rst_n:1;
}SCPU_A12_DSS_C35_12D5T_CTRL;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     dss_c35_wsort_go:1;
unsigned int     dss_c35_count_out:20;
unsigned int     dss_c35_ready:1;
}SCPU_A12_DSS_C35_12D5T_STAT0;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     dss_c35_dbgo:16;
}SCPU_A12_DSS_C35_12D5T_STAT1;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     dss_c35d5_speed_en:1;
unsigned int     dss_c35d5_data_in:20;
unsigned int     dss_c35d5_wire_sel:1;
unsigned int     dss_c35d5_ro_sel:3;
unsigned int     dss_c35d5_dss_rst_n:1;
}SCPU_A12_DSS_C35D5_12D5T_CTRL;

typedef struct 
{
unsigned int     reserved_0:10;
unsigned int     dss_c35d5_wsort_go:1;
unsigned int     dss_c35d5_count_out:20;
unsigned int     dss_c35d5_ready:1;
}SCPU_A12_DSS_C35D5_12D5T_STAT0;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     dss_c35d5_dbgo:16;
}SCPU_A12_DSS_C35D5_12D5T_STAT1;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     SRAM_LS:1;
unsigned int     SRAM_RME:1;
}SCPU_A12_SRAM_CTRL1;

typedef struct 
{
unsigned int     SRAM_RM_l2tag:4;
unsigned int     SRAM_RM_l2data:4;
unsigned int     SRAM_RM_lfbram:4;
unsigned int     SRAM_RM_stbram:4;
unsigned int     SRAM_RM_evbram:4;
unsigned int     SRAM_RM_ddata:4;
unsigned int     SRAM_RM_dtag:4;
unsigned int     SRAM_RM_tlbram:4;
}SCPU_A12_SCU_CTRL;

typedef struct 
{
unsigned int     SRAM_RM_tlbbuf:4;
unsigned int     SRAM_RM_pred1:4;
unsigned int     SRAM_RM_pred0:4;
unsigned int     SRAM_RM_btacc:4;
unsigned int     SRAM_RM_btact:4;
unsigned int     SRAM_RM_idata:4;
unsigned int     SRAM_RM_itag:4;
unsigned int     SRAM_RM_scu:4;
}SCPU_A12_SCU_CTRL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     share_bus_en:1;
}SCPU_A12_SHARE_EN;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     MBISTACK_all:1;
}SCPU_A12_MBISTACK_ALL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     MBISTACK3_DBG:1;
unsigned int     MBISTACK2_DBG:1;
unsigned int     MBISTACK1_DBG:4;
}SCPU_A12_MBISTACK1_DBG;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     BIST_RSTN:1;
}SCPU_A12_BIST_RSTN;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     BIST_MODE_all:1;
}SCPU_A12_BIST_MODE_ALL;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     BIST_MODE1_tlb_buf:1;
unsigned int     BIST_MODE1_tlb_ram:1;
unsigned int     BIST_MODE1_pred_8bit:1;
unsigned int     BIST_MODE1_pred_4bit:1;
unsigned int     BIST_MODE1_btac_ctrl:1;
unsigned int     BIST_MODE1_btac_tag:1;
unsigned int     BIST_MODE1_dtag1:1;
unsigned int     BIST_MODE1_dtag0:1;
unsigned int     BIST_MODE1_ddata:1;
unsigned int     BIST_MODE1_itag:1;
unsigned int     BIST_MODE1_idata:1;
}SCPU_A12_BIST_MODE1;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     BIST_MODE2_linefill_buf:1;
unsigned int     BIST_MODE2_eviction_buf:1;
unsigned int     BIST_MODE2_store_buf:1;
}SCPU_A12_BIST_MODE2;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     BIST_MODE3_l2tag:1;
unsigned int     BIST_MODE3_scu:1;
}SCPU_A12_BIST_MODE3;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     BIST_DONE1_tlb_buf:1;
unsigned int     BIST_DONE1_tlb_ram:1;
unsigned int     BIST_DONE1_pred_8bit:1;
unsigned int     BIST_DONE1_pred_4bit:1;
unsigned int     BIST_DONE1_btac_ctrl:1;
unsigned int     BIST_DONE1_btac_tag:1;
unsigned int     BIST_DONE1_dtag1:1;
unsigned int     BIST_DONE1_dtag0:1;
unsigned int     BIST_DONE1_ddata:1;
unsigned int     BIST_DONE1_itag:1;
unsigned int     BIST_DONE1_idata:1;
}SCPU_A12_BIST_DONE1;

typedef struct 
{
unsigned int     reserved_0:29;
unsigned int     BIST_DONE2_linefill_buf:1;
unsigned int     BIST_DONE2_eviction_buf:1;
unsigned int     BIST_DONE2_store_buf:1;
}SCPU_A12_BIST_DONE2;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     BIST_DONE3_l2tag:1;
unsigned int     BIST_DONE3_scu:1;
}SCPU_A12_BIST_DONE3;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BIST_MODE1:1;
}SCPU_A12_DRF_BIST_MODE1;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BIST_MODE2:1;
}SCPU_A12_DRF_BIST_MODE2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BIST_MODE3:1;
}SCPU_A12_DRF_BIST_MODE3;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_TEST_RESUME1:1;
}SCPU_A12_DRF_TETS_RESUME1;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_TEST_RESUME2:1;
}SCPU_A12_DRF_TETS_RESUME2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_TEST_RESUME3:1;
}SCPU_A12_DRF_TETS_RESUME3;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_START_PAUSE1:1;
}SCPU_A12_DRF_START_PAUSE1;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_START_PAUSE2:1;
}SCPU_A12_DRF_START_PAUSE2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_START_PAUSE3:1;
}SCPU_A12_DRF_START_PAUSE3;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BIST_DONE1:1;
}SCPU_A12_DRF_BIST_DONE1;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BIST_DONE2:1;
}SCPU_A12_DRF_BIST_DONE2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BIST_DONE3:1;
}SCPU_A12_DRF_BIST_DONE3;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BISR_MODE2:1;
}SCPU_A12_DRF_BISR_MODE2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BISR_TEST_RESUME2:1;
}SCPU_A12_DRF_BISR_TETS_RESUME2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BISR_START_PAUSE2:1;
}SCPU_A12_DRF_BISR_START_PAUSE2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BISR_DONE2:1;
}SCPU_A12_DRF_BISR_DONE2;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     DRF_BISR_FAIL2:8;
}SCPU_A12_DRF_BISR_DONE2;

typedef struct 
{
unsigned int     cpu0_BIST_FAIL1_btac_ctrl:2;
unsigned int     cpu0_BIST_FAIL1_btac_tag:2;
unsigned int     cpu0_BIST_FAIL1_dtag1:4;
unsigned int     cpu0_BIST_FAIL1_dtag0:4;
unsigned int     cpu0_BIST_FAIL1_ddata:8;
unsigned int     cpu0_BIST_FAIL1_itag:4;
unsigned int     cpu0_BIST_FAIL1_idata:8;
}SCPU_A12_CPU0_BIST_FAIL1;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     cpu0_BIST_FAIL1_tlb_buf:2;
unsigned int     cpu0_BIST_FAIL1_tlb_ram:4;
unsigned int     cpu0_BIST_FAIL1_pred_8bit:4;
unsigned int     cpu0_BIST_FAIL1_pred_4bit:8;
}SCPU_A12_CPU0_BIST_FAIL1_2;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     cpu0_BIST_FAIL2_linefill_buf:4;
unsigned int     cpu0_BIST_FAIL2_eviction_buf:4;
unsigned int     cpu0_BIST_FAIL2_store_buf:4;
}SCPU_A12_CPU0_BIST_FAIL2;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     cpu0_BIST_FAIL3_l2tag:16;
unsigned int     cpu0_BIST_FAIL3_scu:4;
}SCPU_A12_CPU0_BIST_FAIL3;

typedef struct 
{
unsigned int     cpu0_DRF_BIST_FAIL1_btac_ctrl:2;
unsigned int     cpu0_DRF_BIST_FAIL1_btac_tag:2;
unsigned int     cpu0_DRF_BIST_FAIL1_dtag1:4;
unsigned int     cpu0_DRF_BIST_FAIL1_dtag0:4;
unsigned int     cpu0_DRF_BIST_FAIL1_ddata:8;
unsigned int     cpu0_DRF_BIST_FAIL1_itag:4;
unsigned int     cpu0_DRF_BIST_FAIL1_idata:8;
}SCPU_A12_CPU0_DRF_BIST_FAIL1;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     cpu0_DRF_BIST_FAIL1_tlb_buf:2;
unsigned int     cpu0_DRF_BIST_FAIL1_tlb_ram:4;
unsigned int     cpu0_DRF_BIST_FAIL1_pred_8bit:4;
unsigned int     cpu0_DRF_BIST_FAIL1_pred_4bit:8;
}SCPU_A12_CPU0_DRF_BIST_FAIL12;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     cpu0_DRF_BIST_FAIL2_linefill_buf:4;
unsigned int     cpu0_DRF_BIST_FAIL2_eviction_buf:4;
unsigned int     cpu0_DRF_BIST_FAIL2_store_buf:4;
}SCPU_A12_CPU0_DRF_BIST_FAIL2;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     cpu0_DRF_BIST_FAIL3_l2tag:16;
unsigned int     cpu0_DRF_BIST_FAIL3_scu:4;
}SCPU_A12_CPU0_DRF_BIST_FAIL3;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     BISR_RSTN:1;
}SCPU_A12_BISR_RSTN;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     SECOND_RUN_EN:1;
}SCPU_A12_SE_RUN_EN;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     HOLD_REMAP:1;
}SCPU_A12_HOLD_REMAP;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     BISR_DONE:1;
}SCPU_A12_BISR_DONE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     BISR_FAIL:8;
}SCPU_A12_BISR_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     BISR_REPAIR:1;
}SCPU_A12_BISR_REPAIR;

typedef struct 
{
unsigned int     BISR_OUT:32;
}SCPU_A12_BISR_OUT;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     BISR_OUT_2:24;
}SCPU_A12_BISR_OUT_2;

#endif

#define SCPU_A12_STAT0                                                               0x1805C000
#define SCPU_A12_STAT0_reg_addr                                                      "0xB805C000"
#define SCPU_A12_STAT0_reg                                                           0xB805C000
#define set_SCPU_A12_STAT0_reg(data)   (*((volatile unsigned int*) SCPU_A12_STAT0_reg)=data)
#define get_SCPU_A12_STAT0_reg   (*((volatile unsigned int*) SCPU_A12_STAT0_reg))
#define SCPU_A12_STAT0_inst_adr                                                      "0x0000"
#define SCPU_A12_STAT0_inst                                                          0x0000
#define SCPU_A12_STAT0_pmuirq_o_shift                                                (5)
#define SCPU_A12_STAT0_pmuirq_o_mask                                                 (0x00000020)
#define SCPU_A12_STAT0_pmuirq_o(data)                                                (0x00000020&((data)<<5))
#define SCPU_A12_STAT0_pmuirq_o_src(data)                                            ((0x00000020&(data))>>5)
#define SCPU_A12_STAT0_get_pmuirq_o(data)                                            ((0x00000020&(data))>>5)
#define SCPU_A12_STAT0_event_o_shift                                                 (4)
#define SCPU_A12_STAT0_event_o_mask                                                  (0x00000010)
#define SCPU_A12_STAT0_event_o(data)                                                 (0x00000010&((data)<<4))
#define SCPU_A12_STAT0_event_o_src(data)                                             ((0x00000010&(data))>>4)
#define SCPU_A12_STAT0_get_event_o(data)                                             ((0x00000010&(data))>>4)
#define SCPU_A12_STAT0_nctiirq_shift                                                 (3)
#define SCPU_A12_STAT0_nctiirq_mask                                                  (0x00000008)
#define SCPU_A12_STAT0_nctiirq(data)                                                 (0x00000008&((data)<<3))
#define SCPU_A12_STAT0_nctiirq_src(data)                                             ((0x00000008&(data))>>3)
#define SCPU_A12_STAT0_get_nctiirq(data)                                             ((0x00000008&(data))>>3)
#define SCPU_A12_STAT0_nfiqout_shift                                                 (2)
#define SCPU_A12_STAT0_nfiqout_mask                                                  (0x00000004)
#define SCPU_A12_STAT0_nfiqout(data)                                                 (0x00000004&((data)<<2))
#define SCPU_A12_STAT0_nfiqout_src(data)                                             ((0x00000004&(data))>>2)
#define SCPU_A12_STAT0_get_nfiqout(data)                                             ((0x00000004&(data))>>2)
#define SCPU_A12_STAT0_nirqout_shift                                                 (1)
#define SCPU_A12_STAT0_nirqout_mask                                                  (0x00000002)
#define SCPU_A12_STAT0_nirqout(data)                                                 (0x00000002&((data)<<1))
#define SCPU_A12_STAT0_nirqout_src(data)                                             ((0x00000002&(data))>>1)
#define SCPU_A12_STAT0_get_nirqout(data)                                             ((0x00000002&(data))>>1)
#define SCPU_A12_STAT0_naxierrirq_shift                                              (0)
#define SCPU_A12_STAT0_naxierrirq_mask                                               (0x00000001)
#define SCPU_A12_STAT0_naxierrirq(data)                                              (0x00000001&((data)<<0))
#define SCPU_A12_STAT0_naxierrirq_src(data)                                          ((0x00000001&(data))>>0)
#define SCPU_A12_STAT0_get_naxierrirq(data)                                          ((0x00000001&(data))>>0)


#define SCPU_A12_STAT1                                                               0x1805C004
#define SCPU_A12_STAT1_reg_addr                                                      "0xB805C004"
#define SCPU_A12_STAT1_reg                                                           0xB805C004
#define set_SCPU_A12_STAT1_reg(data)   (*((volatile unsigned int*) SCPU_A12_STAT1_reg)=data)
#define get_SCPU_A12_STAT1_reg   (*((volatile unsigned int*) SCPU_A12_STAT1_reg))
#define SCPU_A12_STAT1_inst_adr                                                      "0x0001"
#define SCPU_A12_STAT1_inst                                                          0x0001
#define SCPU_A12_STAT1_standbywfi_shift                                              (2)
#define SCPU_A12_STAT1_standbywfi_mask                                               (0x00000004)
#define SCPU_A12_STAT1_standbywfi(data)                                              (0x00000004&((data)<<2))
#define SCPU_A12_STAT1_standbywfi_src(data)                                          ((0x00000004&(data))>>2)
#define SCPU_A12_STAT1_get_standbywfi(data)                                          ((0x00000004&(data))>>2)
#define SCPU_A12_STAT1_standbywfil2_shift                                            (1)
#define SCPU_A12_STAT1_standbywfil2_mask                                             (0x00000002)
#define SCPU_A12_STAT1_standbywfil2(data)                                            (0x00000002&((data)<<1))
#define SCPU_A12_STAT1_standbywfil2_src(data)                                        ((0x00000002&(data))>>1)
#define SCPU_A12_STAT1_get_standbywfil2(data)                                        ((0x00000002&(data))>>1)
#define SCPU_A12_STAT1_standbywfe_shift                                              (0)
#define SCPU_A12_STAT1_standbywfe_mask                                               (0x00000001)
#define SCPU_A12_STAT1_standbywfe(data)                                              (0x00000001&((data)<<0))
#define SCPU_A12_STAT1_standbywfe_src(data)                                          ((0x00000001&(data))>>0)
#define SCPU_A12_STAT1_get_standbywfe(data)                                          ((0x00000001&(data))>>0)


#define SCPU_A12_STAT2                                                               0x1805C008
#define SCPU_A12_STAT2_reg_addr                                                      "0xB805C008"
#define SCPU_A12_STAT2_reg                                                           0xB805C008
#define set_SCPU_A12_STAT2_reg(data)   (*((volatile unsigned int*) SCPU_A12_STAT2_reg)=data)
#define get_SCPU_A12_STAT2_reg   (*((volatile unsigned int*) SCPU_A12_STAT2_reg))
#define SCPU_A12_STAT2_inst_adr                                                      "0x0002"
#define SCPU_A12_STAT2_inst                                                          0x0002
#define SCPU_A12_STAT2_dbgpwrupreq_shift                                             (4)
#define SCPU_A12_STAT2_dbgpwrupreq_mask                                              (0x000000F0)
#define SCPU_A12_STAT2_dbgpwrupreq(data)                                             (0x000000F0&((data)<<4))
#define SCPU_A12_STAT2_dbgpwrupreq_src(data)                                         ((0x000000F0&(data))>>4)
#define SCPU_A12_STAT2_get_dbgpwrupreq(data)                                         ((0x000000F0&(data))>>4)
#define SCPU_A12_STAT2_dbgnopwrdwn_shift                                             (0)
#define SCPU_A12_STAT2_dbgnopwrdwn_mask                                              (0x0000000F)
#define SCPU_A12_STAT2_dbgnopwrdwn(data)                                             (0x0000000F&((data)<<0))
#define SCPU_A12_STAT2_dbgnopwrdwn_src(data)                                         ((0x0000000F&(data))>>0)
#define SCPU_A12_STAT2_get_dbgnopwrdwn(data)                                         ((0x0000000F&(data))>>0)


#define SCPU_A12_STAT3                                                               0x1805C00c
#define SCPU_A12_STAT3_reg_addr                                                      "0xB805C00C"
#define SCPU_A12_STAT3_reg                                                           0xB805C00C
#define set_SCPU_A12_STAT3_reg(data)   (*((volatile unsigned int*) SCPU_A12_STAT3_reg)=data)
#define get_SCPU_A12_STAT3_reg   (*((volatile unsigned int*) SCPU_A12_STAT3_reg))
#define SCPU_A12_STAT3_inst_adr                                                      "0x0003"
#define SCPU_A12_STAT3_inst                                                          0x0003
#define SCPU_A12_STAT3_pmuevent0_shift                                               (0)
#define SCPU_A12_STAT3_pmuevent0_mask                                                (0xFFFFFFFF)
#define SCPU_A12_STAT3_pmuevent0(data)                                               (0xFFFFFFFF&((data)<<0))
#define SCPU_A12_STAT3_pmuevent0_src(data)                                           ((0xFFFFFFFF&(data))>>0)
#define SCPU_A12_STAT3_get_pmuevent0(data)                                           ((0xFFFFFFFF&(data))>>0)


#define SCPU_A12_STAT3                                                               0x1805C010
#define SCPU_A12_STAT3_reg_addr                                                      "0xB805C010"
#define SCPU_A12_STAT3_reg                                                           0xB805C010
#define set_SCPU_A12_STAT3_reg(data)   (*((volatile unsigned int*) SCPU_A12_STAT3_reg)=data)
#define get_SCPU_A12_STAT3_reg   (*((volatile unsigned int*) SCPU_A12_STAT3_reg))
#define SCPU_A12_STAT3_inst_adr                                                      "0x0004"
#define SCPU_A12_STAT3_inst                                                          0x0004
#define SCPU_A12_STAT3_pmuevent0_h_shift                                             (0)
#define SCPU_A12_STAT3_pmuevent0_h_mask                                              (0x0000003F)
#define SCPU_A12_STAT3_pmuevent0_h(data)                                             (0x0000003F&((data)<<0))
#define SCPU_A12_STAT3_pmuevent0_h_src(data)                                         ((0x0000003F&(data))>>0)
#define SCPU_A12_STAT3_get_pmuevent0_h(data)                                         ((0x0000003F&(data))>>0)


#define SCPU_A12_CTRL0                                                               0x1805C014
#define SCPU_A12_CTRL0_reg_addr                                                      "0xB805C014"
#define SCPU_A12_CTRL0_reg                                                           0xB805C014
#define set_SCPU_A12_CTRL0_reg(data)   (*((volatile unsigned int*) SCPU_A12_CTRL0_reg)=data)
#define get_SCPU_A12_CTRL0_reg   (*((volatile unsigned int*) SCPU_A12_CTRL0_reg))
#define SCPU_A12_CTRL0_inst_adr                                                      "0x0005"
#define SCPU_A12_CTRL0_inst                                                          0x0005
#define SCPU_A12_CTRL0_l2rstdisable_shift                                            (14)
#define SCPU_A12_CTRL0_l2rstdisable_mask                                             (0x00004000)
#define SCPU_A12_CTRL0_l2rstdisable(data)                                            (0x00004000&((data)<<14))
#define SCPU_A12_CTRL0_l2rstdisable_src(data)                                        ((0x00004000&(data))>>14)
#define SCPU_A12_CTRL0_get_l2rstdisable(data)                                        ((0x00004000&(data))>>14)
#define SCPU_A12_CTRL0_aclkenm_shift                                                 (13)
#define SCPU_A12_CTRL0_aclkenm_mask                                                  (0x00002000)
#define SCPU_A12_CTRL0_aclkenm(data)                                                 (0x00002000&((data)<<13))
#define SCPU_A12_CTRL0_aclkenm_src(data)                                             ((0x00002000&(data))>>13)
#define SCPU_A12_CTRL0_get_aclkenm(data)                                             ((0x00002000&(data))>>13)
#define SCPU_A12_CTRL0_teinit_shift                                                  (9)
#define SCPU_A12_CTRL0_teinit_mask                                                   (0x00001E00)
#define SCPU_A12_CTRL0_teinit(data)                                                  (0x00001E00&((data)<<9))
#define SCPU_A12_CTRL0_teinit_src(data)                                              ((0x00001E00&(data))>>9)
#define SCPU_A12_CTRL0_get_teinit(data)                                              ((0x00001E00&(data))>>9)
#define SCPU_A12_CTRL0_cfgend_shift                                                  (5)
#define SCPU_A12_CTRL0_cfgend_mask                                                   (0x000001E0)
#define SCPU_A12_CTRL0_cfgend(data)                                                  (0x000001E0&((data)<<5))
#define SCPU_A12_CTRL0_cfgend_src(data)                                              ((0x000001E0&(data))>>5)
#define SCPU_A12_CTRL0_get_cfgend(data)                                              ((0x000001E0&(data))>>5)
#define SCPU_A12_CTRL0_event_i_shift                                                 (4)
#define SCPU_A12_CTRL0_event_i_mask                                                  (0x00000010)
#define SCPU_A12_CTRL0_event_i(data)                                                 (0x00000010&((data)<<4))
#define SCPU_A12_CTRL0_event_i_src(data)                                             ((0x00000010&(data))>>4)
#define SCPU_A12_CTRL0_get_event_i(data)                                             ((0x00000010&(data))>>4)
#define SCPU_A12_CTRL0_edbgrq_shift                                                  (0)
#define SCPU_A12_CTRL0_edbgrq_mask                                                   (0x0000000F)
#define SCPU_A12_CTRL0_edbgrq(data)                                                  (0x0000000F&((data)<<0))
#define SCPU_A12_CTRL0_edbgrq_src(data)                                              ((0x0000000F&(data))>>0)
#define SCPU_A12_CTRL0_get_edbgrq(data)                                              ((0x0000000F&(data))>>0)


#define SCPU_A12_CTRL1                                                               0x1805C018
#define SCPU_A12_CTRL1_reg_addr                                                      "0xB805C018"
#define SCPU_A12_CTRL1_reg                                                           0xB805C018
#define set_SCPU_A12_CTRL1_reg(data)   (*((volatile unsigned int*) SCPU_A12_CTRL1_reg)=data)
#define get_SCPU_A12_CTRL1_reg   (*((volatile unsigned int*) SCPU_A12_CTRL1_reg))
#define SCPU_A12_CTRL1_inst_adr                                                      "0x0006"
#define SCPU_A12_CTRL1_inst                                                          0x0006
#define SCPU_A12_CTRL1_dbgpwrdup_shift                                               (4)
#define SCPU_A12_CTRL1_dbgpwrdup_mask                                                (0x000000F0)
#define SCPU_A12_CTRL1_dbgpwrdup(data)                                               (0x000000F0&((data)<<4))
#define SCPU_A12_CTRL1_dbgpwrdup_src(data)                                           ((0x000000F0&(data))>>4)
#define SCPU_A12_CTRL1_get_dbgpwrdup(data)                                           ((0x000000F0&(data))>>4)
#define SCPU_A12_CTRL1_vinithi_shift                                                 (0)
#define SCPU_A12_CTRL1_vinithi_mask                                                  (0x0000000F)
#define SCPU_A12_CTRL1_vinithi(data)                                                 (0x0000000F&((data)<<0))
#define SCPU_A12_CTRL1_vinithi_src(data)                                             ((0x0000000F&(data))>>0)
#define SCPU_A12_CTRL1_get_vinithi(data)                                             ((0x0000000F&(data))>>0)


#define SCPU_A12_CTRL3                                                               0x1805C01c
#define SCPU_A12_CTRL3_reg_addr                                                      "0xB805C01C"
#define SCPU_A12_CTRL3_reg                                                           0xB805C01C
#define set_SCPU_A12_CTRL3_reg(data)   (*((volatile unsigned int*) SCPU_A12_CTRL3_reg)=data)
#define get_SCPU_A12_CTRL3_reg   (*((volatile unsigned int*) SCPU_A12_CTRL3_reg))
#define SCPU_A12_CTRL3_inst_adr                                                      "0x0007"
#define SCPU_A12_CTRL3_inst                                                          0x0007
#define SCPU_A12_CTRL3_dbgromaddrv_shift                                             (28)
#define SCPU_A12_CTRL3_dbgromaddrv_mask                                              (0x10000000)
#define SCPU_A12_CTRL3_dbgromaddrv(data)                                             (0x10000000&((data)<<28))
#define SCPU_A12_CTRL3_dbgromaddrv_src(data)                                         ((0x10000000&(data))>>28)
#define SCPU_A12_CTRL3_get_dbgromaddrv(data)                                         ((0x10000000&(data))>>28)
#define SCPU_A12_CTRL3_dbgromaddr_shift                                              (0)
#define SCPU_A12_CTRL3_dbgromaddr_mask                                               (0x0FFFFFFF)
#define SCPU_A12_CTRL3_dbgromaddr(data)                                              (0x0FFFFFFF&((data)<<0))
#define SCPU_A12_CTRL3_dbgromaddr_src(data)                                          ((0x0FFFFFFF&(data))>>0)
#define SCPU_A12_CTRL3_get_dbgromaddr(data)                                          ((0x0FFFFFFF&(data))>>0)


#define SCPU_A12_CTRL4                                                               0x1805C020
#define SCPU_A12_CTRL4_reg_addr                                                      "0xB805C020"
#define SCPU_A12_CTRL4_reg                                                           0xB805C020
#define set_SCPU_A12_CTRL4_reg(data)   (*((volatile unsigned int*) SCPU_A12_CTRL4_reg)=data)
#define get_SCPU_A12_CTRL4_reg   (*((volatile unsigned int*) SCPU_A12_CTRL4_reg))
#define SCPU_A12_CTRL4_inst_adr                                                      "0x0008"
#define SCPU_A12_CTRL4_inst                                                          0x0008
#define SCPU_A12_CTRL4_dbgselfaddrv_shift                                            (23)
#define SCPU_A12_CTRL4_dbgselfaddrv_mask                                             (0x00800000)
#define SCPU_A12_CTRL4_dbgselfaddrv(data)                                            (0x00800000&((data)<<23))
#define SCPU_A12_CTRL4_dbgselfaddrv_src(data)                                        ((0x00800000&(data))>>23)
#define SCPU_A12_CTRL4_get_dbgselfaddrv(data)                                        ((0x00800000&(data))>>23)
#define SCPU_A12_CTRL4_dbgselfaddr_shift                                             (0)
#define SCPU_A12_CTRL4_dbgselfaddr_mask                                              (0x007FFFFF)
#define SCPU_A12_CTRL4_dbgselfaddr(data)                                             (0x007FFFFF&((data)<<0))
#define SCPU_A12_CTRL4_dbgselfaddr_src(data)                                         ((0x007FFFFF&(data))>>0)
#define SCPU_A12_CTRL4_get_dbgselfaddr(data)                                         ((0x007FFFFF&(data))>>0)


#define SCPU_A12_CS_STAT0                                                            0x1805C024
#define SCPU_A12_CS_STAT0_reg_addr                                                   "0xB805C024"
#define SCPU_A12_CS_STAT0_reg                                                        0xB805C024
#define set_SCPU_A12_CS_STAT0_reg(data)   (*((volatile unsigned int*) SCPU_A12_CS_STAT0_reg)=data)
#define get_SCPU_A12_CS_STAT0_reg   (*((volatile unsigned int*) SCPU_A12_CS_STAT0_reg))
#define SCPU_A12_CS_STAT0_inst_adr                                                   "0x0009"
#define SCPU_A12_CS_STAT0_inst                                                       0x0009
#define SCPU_A12_CS_STAT0_cssys_cpwrupreq_sys_shift                                  (4)
#define SCPU_A12_CS_STAT0_cssys_cpwrupreq_sys_mask                                   (0x00000010)
#define SCPU_A12_CS_STAT0_cssys_cpwrupreq_sys(data)                                  (0x00000010&((data)<<4))
#define SCPU_A12_CS_STAT0_cssys_cpwrupreq_sys_src(data)                              ((0x00000010&(data))>>4)
#define SCPU_A12_CS_STAT0_get_cssys_cpwrupreq_sys(data)                              ((0x00000010&(data))>>4)
#define SCPU_A12_CS_STAT0_cssys_cdbgrstreq_shift                                     (3)
#define SCPU_A12_CS_STAT0_cssys_cdbgrstreq_mask                                      (0x00000008)
#define SCPU_A12_CS_STAT0_cssys_cdbgrstreq(data)                                     (0x00000008&((data)<<3))
#define SCPU_A12_CS_STAT0_cssys_cdbgrstreq_src(data)                                 ((0x00000008&(data))>>3)
#define SCPU_A12_CS_STAT0_get_cssys_cdbgrstreq(data)                                 ((0x00000008&(data))>>3)
#define SCPU_A12_CS_STAT0_cssys_cpwrupreq_dbg_shift                                  (2)
#define SCPU_A12_CS_STAT0_cssys_cpwrupreq_dbg_mask                                   (0x00000004)
#define SCPU_A12_CS_STAT0_cssys_cpwrupreq_dbg(data)                                  (0x00000004&((data)<<2))
#define SCPU_A12_CS_STAT0_cssys_cpwrupreq_dbg_src(data)                              ((0x00000004&(data))>>2)
#define SCPU_A12_CS_STAT0_get_cssys_cpwrupreq_dbg(data)                              ((0x00000004&(data))>>2)
#define SCPU_A12_CS_STAT0_cssys_jtagtop_shift                                        (1)
#define SCPU_A12_CS_STAT0_cssys_jtagtop_mask                                         (0x00000002)
#define SCPU_A12_CS_STAT0_cssys_jtagtop(data)                                        (0x00000002&((data)<<1))
#define SCPU_A12_CS_STAT0_cssys_jtagtop_src(data)                                    ((0x00000002&(data))>>1)
#define SCPU_A12_CS_STAT0_get_cssys_jtagtop(data)                                    ((0x00000002&(data))>>1)
#define SCPU_A12_CS_STAT0_cssys_jtagnsw_shift                                        (0)
#define SCPU_A12_CS_STAT0_cssys_jtagnsw_mask                                         (0x00000001)
#define SCPU_A12_CS_STAT0_cssys_jtagnsw(data)                                        (0x00000001&((data)<<0))
#define SCPU_A12_CS_STAT0_cssys_jtagnsw_src(data)                                    ((0x00000001&(data))>>0)
#define SCPU_A12_CS_STAT0_get_cssys_jtagnsw(data)                                    ((0x00000001&(data))>>0)


#define SCPU_A12_CS_CTRL0                                                            0x1805C028
#define SCPU_A12_CS_CTRL0_reg_addr                                                   "0xB805C028"
#define SCPU_A12_CS_CTRL0_reg                                                        0xB805C028
#define set_SCPU_A12_CS_CTRL0_reg(data)   (*((volatile unsigned int*) SCPU_A12_CS_CTRL0_reg)=data)
#define get_SCPU_A12_CS_CTRL0_reg   (*((volatile unsigned int*) SCPU_A12_CS_CTRL0_reg))
#define SCPU_A12_CS_CTRL0_inst_adr                                                   "0x000A"
#define SCPU_A12_CS_CTRL0_inst                                                       0x000A
#define SCPU_A12_CS_CTRL0_cssys_ctiapbsbypass_shift                                  (29)
#define SCPU_A12_CS_CTRL0_cssys_ctiapbsbypass_mask                                   (0x20000000)
#define SCPU_A12_CS_CTRL0_cssys_ctiapbsbypass(data)                                  (0x20000000&((data)<<29))
#define SCPU_A12_CS_CTRL0_cssys_ctiapbsbypass_src(data)                              ((0x20000000&(data))>>29)
#define SCPU_A12_CS_CTRL0_get_cssys_ctiapbsbypass(data)                              ((0x20000000&(data))>>29)
#define SCPU_A12_CS_CTRL0_cssys_todbgensel_shift                                     (27)
#define SCPU_A12_CS_CTRL0_cssys_todbgensel_mask                                      (0x18000000)
#define SCPU_A12_CS_CTRL0_cssys_todbgensel(data)                                     (0x18000000&((data)<<27))
#define SCPU_A12_CS_CTRL0_cssys_todbgensel_src(data)                                 ((0x18000000&(data))>>27)
#define SCPU_A12_CS_CTRL0_get_cssys_todbgensel(data)                                 ((0x18000000&(data))>>27)
#define SCPU_A12_CS_CTRL0_cssys_revision_shift                                       (23)
#define SCPU_A12_CS_CTRL0_cssys_revision_mask                                        (0x07800000)
#define SCPU_A12_CS_CTRL0_cssys_revision(data)                                       (0x07800000&((data)<<23))
#define SCPU_A12_CS_CTRL0_cssys_revision_src(data)                                   ((0x07800000&(data))>>23)
#define SCPU_A12_CS_CTRL0_get_cssys_revision(data)                                   ((0x07800000&(data))>>23)
#define SCPU_A12_CS_CTRL0_cssys_partnumber_shift                                     (11)
#define SCPU_A12_CS_CTRL0_cssys_partnumber_mask                                      (0x007FF800)
#define SCPU_A12_CS_CTRL0_cssys_partnumber(data)                                     (0x007FF800&((data)<<11))
#define SCPU_A12_CS_CTRL0_cssys_partnumber_src(data)                                 ((0x007FF800&(data))>>11)
#define SCPU_A12_CS_CTRL0_get_cssys_partnumber(data)                                 ((0x007FF800&(data))>>11)
#define SCPU_A12_CS_CTRL0_cssys_cpwrupack_sys_shift                                  (10)
#define SCPU_A12_CS_CTRL0_cssys_cpwrupack_sys_mask                                   (0x00000400)
#define SCPU_A12_CS_CTRL0_cssys_cpwrupack_sys(data)                                  (0x00000400&((data)<<10))
#define SCPU_A12_CS_CTRL0_cssys_cpwrupack_sys_src(data)                              ((0x00000400&(data))>>10)
#define SCPU_A12_CS_CTRL0_get_cssys_cpwrupack_sys(data)                              ((0x00000400&(data))>>10)
#define SCPU_A12_CS_CTRL0_cssys_cdbgrstack_shift                                     (9)
#define SCPU_A12_CS_CTRL0_cssys_cdbgrstack_mask                                      (0x00000200)
#define SCPU_A12_CS_CTRL0_cssys_cdbgrstack(data)                                     (0x00000200&((data)<<9))
#define SCPU_A12_CS_CTRL0_cssys_cdbgrstack_src(data)                                 ((0x00000200&(data))>>9)
#define SCPU_A12_CS_CTRL0_get_cssys_cdbgrstack(data)                                 ((0x00000200&(data))>>9)
#define SCPU_A12_CS_CTRL0_cssys_cpwrupack_dbg_shift                                  (8)
#define SCPU_A12_CS_CTRL0_cssys_cpwrupack_dbg_mask                                   (0x00000100)
#define SCPU_A12_CS_CTRL0_cssys_cpwrupack_dbg(data)                                  (0x00000100&((data)<<8))
#define SCPU_A12_CS_CTRL0_cssys_cpwrupack_dbg_src(data)                              ((0x00000100&(data))>>8)
#define SCPU_A12_CS_CTRL0_get_cssys_cpwrupack_dbg(data)                              ((0x00000100&(data))>>8)
#define SCPU_A12_CS_CTRL0_cssys_tpmaxdatasize_shift                                  (3)
#define SCPU_A12_CS_CTRL0_cssys_tpmaxdatasize_mask                                   (0x000000F8)
#define SCPU_A12_CS_CTRL0_cssys_tpmaxdatasize(data)                                  (0x000000F8&((data)<<3))
#define SCPU_A12_CS_CTRL0_cssys_tpmaxdatasize_src(data)                              ((0x000000F8&(data))>>3)
#define SCPU_A12_CS_CTRL0_get_cssys_tpmaxdatasize(data)                              ((0x000000F8&(data))>>3)
#define SCPU_A12_CS_CTRL0_cssys_tpctl_shift                                          (2)
#define SCPU_A12_CS_CTRL0_cssys_tpctl_mask                                           (0x00000004)
#define SCPU_A12_CS_CTRL0_cssys_tpctl(data)                                          (0x00000004&((data)<<2))
#define SCPU_A12_CS_CTRL0_cssys_tpctl_src(data)                                      ((0x00000004&(data))>>2)
#define SCPU_A12_CS_CTRL0_get_cssys_tpctl(data)                                      ((0x00000004&(data))>>2)
#define SCPU_A12_CS_CTRL0_cssys_niden_shift                                          (1)
#define SCPU_A12_CS_CTRL0_cssys_niden_mask                                           (0x00000002)
#define SCPU_A12_CS_CTRL0_cssys_niden(data)                                          (0x00000002&((data)<<1))
#define SCPU_A12_CS_CTRL0_cssys_niden_src(data)                                      ((0x00000002&(data))>>1)
#define SCPU_A12_CS_CTRL0_get_cssys_niden(data)                                      ((0x00000002&(data))>>1)
#define SCPU_A12_CS_CTRL0_cssys_dbgen_shift                                          (0)
#define SCPU_A12_CS_CTRL0_cssys_dbgen_mask                                           (0x00000001)
#define SCPU_A12_CS_CTRL0_cssys_dbgen(data)                                          (0x00000001&((data)<<0))
#define SCPU_A12_CS_CTRL0_cssys_dbgen_src(data)                                      ((0x00000001&(data))>>0)
#define SCPU_A12_CS_CTRL0_get_cssys_dbgen(data)                                      ((0x00000001&(data))>>0)


#define SCPU_A12_TCKCHANGE                                                           0x1805C02c
#define SCPU_A12_TCKCHANGE_reg_addr                                                  "0xB805C02C"
#define SCPU_A12_TCKCHANGE_reg                                                       0xB805C02C
#define set_SCPU_A12_TCKCHANGE_reg(data)   (*((volatile unsigned int*) SCPU_A12_TCKCHANGE_reg)=data)
#define get_SCPU_A12_TCKCHANGE_reg   (*((volatile unsigned int*) SCPU_A12_TCKCHANGE_reg))
#define SCPU_A12_TCKCHANGE_inst_adr                                                  "0x000B"
#define SCPU_A12_TCKCHANGE_inst                                                      0x000B
#define SCPU_A12_TCKCHANGE_tckchange_shift                                           (0)
#define SCPU_A12_TCKCHANGE_tckchange_mask                                            (0x00000001)
#define SCPU_A12_TCKCHANGE_tckchange(data)                                           (0x00000001&((data)<<0))
#define SCPU_A12_TCKCHANGE_tckchange_src(data)                                       ((0x00000001&(data))>>0)
#define SCPU_A12_TCKCHANGE_get_tckchange(data)                                       ((0x00000001&(data))>>0)


#define SCPU_A12_APB_CSSYS0                                                          0x1805C030
#define SCPU_A12_APB_CSSYS0_reg_addr                                                 "0xB805C030"
#define SCPU_A12_APB_CSSYS0_reg                                                      0xB805C030
#define set_SCPU_A12_APB_CSSYS0_reg(data)   (*((volatile unsigned int*) SCPU_A12_APB_CSSYS0_reg)=data)
#define get_SCPU_A12_APB_CSSYS0_reg   (*((volatile unsigned int*) SCPU_A12_APB_CSSYS0_reg))
#define SCPU_A12_APB_CSSYS0_inst_adr                                                 "0x000C"
#define SCPU_A12_APB_CSSYS0_inst                                                     0x000C
#define SCPU_A12_APB_CSSYS0_apb_cssys_a_shift                                        (0)
#define SCPU_A12_APB_CSSYS0_apb_cssys_a_mask                                         (0xFFFFFFFF)
#define SCPU_A12_APB_CSSYS0_apb_cssys_a(data)                                        (0xFFFFFFFF&((data)<<0))
#define SCPU_A12_APB_CSSYS0_apb_cssys_a_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define SCPU_A12_APB_CSSYS0_get_apb_cssys_a(data)                                    ((0xFFFFFFFF&(data))>>0)


#define SCPU_A12_APB_CSSYS1                                                          0x1805C034
#define SCPU_A12_APB_CSSYS1_reg_addr                                                 "0xB805C034"
#define SCPU_A12_APB_CSSYS1_reg                                                      0xB805C034
#define set_SCPU_A12_APB_CSSYS1_reg(data)   (*((volatile unsigned int*) SCPU_A12_APB_CSSYS1_reg)=data)
#define get_SCPU_A12_APB_CSSYS1_reg   (*((volatile unsigned int*) SCPU_A12_APB_CSSYS1_reg))
#define SCPU_A12_APB_CSSYS1_inst_adr                                                 "0x000D"
#define SCPU_A12_APB_CSSYS1_inst                                                     0x000D
#define SCPU_A12_APB_CSSYS1_apb_cssys_d_shift                                        (0)
#define SCPU_A12_APB_CSSYS1_apb_cssys_d_mask                                         (0xFFFFFFFF)
#define SCPU_A12_APB_CSSYS1_apb_cssys_d(data)                                        (0xFFFFFFFF&((data)<<0))
#define SCPU_A12_APB_CSSYS1_apb_cssys_d_src(data)                                    ((0xFFFFFFFF&(data))>>0)
#define SCPU_A12_APB_CSSYS1_get_apb_cssys_d(data)                                    ((0xFFFFFFFF&(data))>>0)


#define SCPU_A12_APB_ERR                                                             0x1805C040
#define SCPU_A12_APB_ERR_reg_addr                                                    "0xB805C040"
#define SCPU_A12_APB_ERR_reg                                                         0xB805C040
#define set_SCPU_A12_APB_ERR_reg(data)   (*((volatile unsigned int*) SCPU_A12_APB_ERR_reg)=data)
#define get_SCPU_A12_APB_ERR_reg   (*((volatile unsigned int*) SCPU_A12_APB_ERR_reg))
#define SCPU_A12_APB_ERR_inst_adr                                                    "0x0010"
#define SCPU_A12_APB_ERR_inst                                                        0x0010
#define SCPU_A12_APB_ERR_apb_cssys_slverr_shift                                      (0)
#define SCPU_A12_APB_ERR_apb_cssys_slverr_mask                                       (0x00000001)
#define SCPU_A12_APB_ERR_apb_cssys_slverr(data)                                      (0x00000001&((data)<<0))
#define SCPU_A12_APB_ERR_apb_cssys_slverr_src(data)                                  ((0x00000001&(data))>>0)
#define SCPU_A12_APB_ERR_get_apb_cssys_slverr(data)                                  ((0x00000001&(data))>>0)


#define SCPU_A12_SCPU_A12_CTRL                                                       0x1805C100
#define SCPU_A12_SCPU_A12_CTRL_reg_addr                                              "0xB805C100"
#define SCPU_A12_SCPU_A12_CTRL_reg                                                   0xB805C100
#define set_SCPU_A12_SCPU_A12_CTRL_reg(data)   (*((volatile unsigned int*) SCPU_A12_SCPU_A12_CTRL_reg)=data)
#define get_SCPU_A12_SCPU_A12_CTRL_reg   (*((volatile unsigned int*) SCPU_A12_SCPU_A12_CTRL_reg))
#define SCPU_A12_SCPU_A12_CTRL_inst_adr                                              "0x0040"
#define SCPU_A12_SCPU_A12_CTRL_inst                                                  0x0040
#define SCPU_A12_SCPU_A12_CTRL_fbusrandwstrb_shift                                   (18)
#define SCPU_A12_SCPU_A12_CTRL_fbusrandwstrb_mask                                    (0x00040000)
#define SCPU_A12_SCPU_A12_CTRL_fbusrandwstrb(data)                                   (0x00040000&((data)<<18))
#define SCPU_A12_SCPU_A12_CTRL_fbusrandwstrb_src(data)                               ((0x00040000&(data))>>18)
#define SCPU_A12_SCPU_A12_CTRL_get_fbusrandwstrb(data)                               ((0x00040000&(data))>>18)
#define SCPU_A12_SCPU_A12_CTRL_remote_cmd_num_shift                                  (14)
#define SCPU_A12_SCPU_A12_CTRL_remote_cmd_num_mask                                   (0x0003C000)
#define SCPU_A12_SCPU_A12_CTRL_remote_cmd_num(data)                                  (0x0003C000&((data)<<14))
#define SCPU_A12_SCPU_A12_CTRL_remote_cmd_num_src(data)                              ((0x0003C000&(data))>>14)
#define SCPU_A12_SCPU_A12_CTRL_get_remote_cmd_num(data)                              ((0x0003C000&(data))>>14)
#define SCPU_A12_SCPU_A12_CTRL_remote_wdata_num_shift                                (10)
#define SCPU_A12_SCPU_A12_CTRL_remote_wdata_num_mask                                 (0x00003C00)
#define SCPU_A12_SCPU_A12_CTRL_remote_wdata_num(data)                                (0x00003C00&((data)<<10))
#define SCPU_A12_SCPU_A12_CTRL_remote_wdata_num_src(data)                            ((0x00003C00&(data))>>10)
#define SCPU_A12_SCPU_A12_CTRL_get_remote_wdata_num(data)                            ((0x00003C00&(data))>>10)
#define SCPU_A12_SCPU_A12_CTRL_wcmd_bufable_sel_shift                                (8)
#define SCPU_A12_SCPU_A12_CTRL_wcmd_bufable_sel_mask                                 (0x00000300)
#define SCPU_A12_SCPU_A12_CTRL_wcmd_bufable_sel(data)                                (0x00000300&((data)<<8))
#define SCPU_A12_SCPU_A12_CTRL_wcmd_bufable_sel_src(data)                            ((0x00000300&(data))>>8)
#define SCPU_A12_SCPU_A12_CTRL_get_wcmd_bufable_sel(data)                            ((0x00000300&(data))>>8)
#define SCPU_A12_SCPU_A12_CTRL_wr_outstand_num_shift                                 (4)
#define SCPU_A12_SCPU_A12_CTRL_wr_outstand_num_mask                                  (0x000000F0)
#define SCPU_A12_SCPU_A12_CTRL_wr_outstand_num(data)                                 (0x000000F0&((data)<<4))
#define SCPU_A12_SCPU_A12_CTRL_wr_outstand_num_src(data)                             ((0x000000F0&(data))>>4)
#define SCPU_A12_SCPU_A12_CTRL_get_wr_outstand_num(data)                             ((0x000000F0&(data))>>4)
#define SCPU_A12_SCPU_A12_CTRL_rd_outstand_num_shift                                 (0)
#define SCPU_A12_SCPU_A12_CTRL_rd_outstand_num_mask                                  (0x0000000F)
#define SCPU_A12_SCPU_A12_CTRL_rd_outstand_num(data)                                 (0x0000000F&((data)<<0))
#define SCPU_A12_SCPU_A12_CTRL_rd_outstand_num_src(data)                             ((0x0000000F&(data))>>0)
#define SCPU_A12_SCPU_A12_CTRL_get_rd_outstand_num(data)                             ((0x0000000F&(data))>>0)


#define SCPU_A12_CTRL2                                                               0x1805C104
#define SCPU_A12_CTRL2_reg_addr                                                      "0xB805C104"
#define SCPU_A12_CTRL2_reg                                                           0xB805C104
#define set_SCPU_A12_CTRL2_reg(data)   (*((volatile unsigned int*) SCPU_A12_CTRL2_reg)=data)
#define get_SCPU_A12_CTRL2_reg   (*((volatile unsigned int*) SCPU_A12_CTRL2_reg))
#define SCPU_A12_CTRL2_inst_adr                                                      "0x0041"
#define SCPU_A12_CTRL2_inst                                                          0x0041
#define SCPU_A12_CTRL2_scpu_dbg_sel_shift                                            (0)
#define SCPU_A12_CTRL2_scpu_dbg_sel_mask                                             (0x0000000F)
#define SCPU_A12_CTRL2_scpu_dbg_sel(data)                                            (0x0000000F&((data)<<0))
#define SCPU_A12_CTRL2_scpu_dbg_sel_src(data)                                        ((0x0000000F&(data))>>0)
#define SCPU_A12_CTRL2_get_scpu_dbg_sel(data)                                        ((0x0000000F&(data))>>0)


#define SCPU_A12_DBG_START_0                                                         0x1805C360
#define SCPU_A12_DBG_START_1                                                         0x1805C364
#define SCPU_A12_DBG_START_2                                                         0x1805C368
#define SCPU_A12_DBG_START_3                                                         0x1805C36C
#define SCPU_A12_DBG_START_0_reg_addr                                                "0xB805C360"
#define SCPU_A12_DBG_START_1_reg_addr                                                "0xB805C364"
#define SCPU_A12_DBG_START_2_reg_addr                                                "0xB805C368"
#define SCPU_A12_DBG_START_3_reg_addr                                                "0xB805C36C"
#define SCPU_A12_DBG_START_0_reg                                                     0xB805C360
#define SCPU_A12_DBG_START_1_reg                                                     0xB805C364
#define SCPU_A12_DBG_START_2_reg                                                     0xB805C368
#define SCPU_A12_DBG_START_3_reg                                                     0xB805C36C
#define set_SCPU_A12_DBG_START_0_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_START_0_reg)=data)
#define set_SCPU_A12_DBG_START_1_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_START_1_reg)=data)
#define set_SCPU_A12_DBG_START_2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_START_2_reg)=data)
#define set_SCPU_A12_DBG_START_3_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_START_3_reg)=data)
#define get_SCPU_A12_DBG_START_0_reg   (*((volatile unsigned int*) SCPU_A12_DBG_START_0_reg))
#define get_SCPU_A12_DBG_START_1_reg   (*((volatile unsigned int*) SCPU_A12_DBG_START_1_reg))
#define get_SCPU_A12_DBG_START_2_reg   (*((volatile unsigned int*) SCPU_A12_DBG_START_2_reg))
#define get_SCPU_A12_DBG_START_3_reg   (*((volatile unsigned int*) SCPU_A12_DBG_START_3_reg))
#define SCPU_A12_DBG_START_0_inst_adr                                                "0x00D8"
#define SCPU_A12_DBG_START_1_inst_adr                                                "0x00D9"
#define SCPU_A12_DBG_START_2_inst_adr                                                "0x00DA"
#define SCPU_A12_DBG_START_3_inst_adr                                                "0x00DB"
#define SCPU_A12_DBG_START_0_inst                                                    0x00D8
#define SCPU_A12_DBG_START_1_inst                                                    0x00D9
#define SCPU_A12_DBG_START_2_inst                                                    0x00DA
#define SCPU_A12_DBG_START_3_inst                                                    0x00DB
#define SCPU_A12_DBG_START_dbg_start_addr_m0_shift                                   (0)
#define SCPU_A12_DBG_START_dbg_start_addr_m0_mask                                    (0xFFFFFFFF)
#define SCPU_A12_DBG_START_dbg_start_addr_m0(data)                                   (0xFFFFFFFF&((data)<<0))
#define SCPU_A12_DBG_START_dbg_start_addr_m0_src(data)                               ((0xFFFFFFFF&(data))>>0)
#define SCPU_A12_DBG_START_get_dbg_start_addr_m0(data)                               ((0xFFFFFFFF&(data))>>0)


#define SCPU_A12_DBG_END_0                                                           0x1805C370
#define SCPU_A12_DBG_END_1                                                           0x1805C374
#define SCPU_A12_DBG_END_2                                                           0x1805C378
#define SCPU_A12_DBG_END_3                                                           0x1805C37C
#define SCPU_A12_DBG_END_0_reg_addr                                                  "0xB805C370"
#define SCPU_A12_DBG_END_1_reg_addr                                                  "0xB805C374"
#define SCPU_A12_DBG_END_2_reg_addr                                                  "0xB805C378"
#define SCPU_A12_DBG_END_3_reg_addr                                                  "0xB805C37C"
#define SCPU_A12_DBG_END_0_reg                                                       0xB805C370
#define SCPU_A12_DBG_END_1_reg                                                       0xB805C374
#define SCPU_A12_DBG_END_2_reg                                                       0xB805C378
#define SCPU_A12_DBG_END_3_reg                                                       0xB805C37C
#define set_SCPU_A12_DBG_END_0_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_END_0_reg)=data)
#define set_SCPU_A12_DBG_END_1_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_END_1_reg)=data)
#define set_SCPU_A12_DBG_END_2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_END_2_reg)=data)
#define set_SCPU_A12_DBG_END_3_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_END_3_reg)=data)
#define get_SCPU_A12_DBG_END_0_reg   (*((volatile unsigned int*) SCPU_A12_DBG_END_0_reg))
#define get_SCPU_A12_DBG_END_1_reg   (*((volatile unsigned int*) SCPU_A12_DBG_END_1_reg))
#define get_SCPU_A12_DBG_END_2_reg   (*((volatile unsigned int*) SCPU_A12_DBG_END_2_reg))
#define get_SCPU_A12_DBG_END_3_reg   (*((volatile unsigned int*) SCPU_A12_DBG_END_3_reg))
#define SCPU_A12_DBG_END_0_inst_adr                                                  "0x00DC"
#define SCPU_A12_DBG_END_1_inst_adr                                                  "0x00DD"
#define SCPU_A12_DBG_END_2_inst_adr                                                  "0x00DE"
#define SCPU_A12_DBG_END_3_inst_adr                                                  "0x00DF"
#define SCPU_A12_DBG_END_0_inst                                                      0x00DC
#define SCPU_A12_DBG_END_1_inst                                                      0x00DD
#define SCPU_A12_DBG_END_2_inst                                                      0x00DE
#define SCPU_A12_DBG_END_3_inst                                                      0x00DF
#define SCPU_A12_DBG_END_dbg_end_addr_m0_shift                                       (0)
#define SCPU_A12_DBG_END_dbg_end_addr_m0_mask                                        (0xFFFFFFFF)
#define SCPU_A12_DBG_END_dbg_end_addr_m0(data)                                       (0xFFFFFFFF&((data)<<0))
#define SCPU_A12_DBG_END_dbg_end_addr_m0_src(data)                                   ((0xFFFFFFFF&(data))>>0)
#define SCPU_A12_DBG_END_get_dbg_end_addr_m0(data)                                   ((0xFFFFFFFF&(data))>>0)


#define SCPU_A12_DBG_CTRL_0                                                          0x1805C380
#define SCPU_A12_DBG_CTRL_1                                                          0x1805C384
#define SCPU_A12_DBG_CTRL_2                                                          0x1805C388
#define SCPU_A12_DBG_CTRL_3                                                          0x1805C38C
#define SCPU_A12_DBG_CTRL_0_reg_addr                                                 "0xB805C380"
#define SCPU_A12_DBG_CTRL_1_reg_addr                                                 "0xB805C384"
#define SCPU_A12_DBG_CTRL_2_reg_addr                                                 "0xB805C388"
#define SCPU_A12_DBG_CTRL_3_reg_addr                                                 "0xB805C38C"
#define SCPU_A12_DBG_CTRL_0_reg                                                      0xB805C380
#define SCPU_A12_DBG_CTRL_1_reg                                                      0xB805C384
#define SCPU_A12_DBG_CTRL_2_reg                                                      0xB805C388
#define SCPU_A12_DBG_CTRL_3_reg                                                      0xB805C38C
#define set_SCPU_A12_DBG_CTRL_0_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_CTRL_0_reg)=data)
#define set_SCPU_A12_DBG_CTRL_1_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_CTRL_1_reg)=data)
#define set_SCPU_A12_DBG_CTRL_2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_CTRL_2_reg)=data)
#define set_SCPU_A12_DBG_CTRL_3_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_CTRL_3_reg)=data)
#define get_SCPU_A12_DBG_CTRL_0_reg   (*((volatile unsigned int*) SCPU_A12_DBG_CTRL_0_reg))
#define get_SCPU_A12_DBG_CTRL_1_reg   (*((volatile unsigned int*) SCPU_A12_DBG_CTRL_1_reg))
#define get_SCPU_A12_DBG_CTRL_2_reg   (*((volatile unsigned int*) SCPU_A12_DBG_CTRL_2_reg))
#define get_SCPU_A12_DBG_CTRL_3_reg   (*((volatile unsigned int*) SCPU_A12_DBG_CTRL_3_reg))
#define SCPU_A12_DBG_CTRL_0_inst_adr                                                 "0x00E0"
#define SCPU_A12_DBG_CTRL_1_inst_adr                                                 "0x00E1"
#define SCPU_A12_DBG_CTRL_2_inst_adr                                                 "0x00E2"
#define SCPU_A12_DBG_CTRL_3_inst_adr                                                 "0x00E3"
#define SCPU_A12_DBG_CTRL_0_inst                                                     0x00E0
#define SCPU_A12_DBG_CTRL_1_inst                                                     0x00E1
#define SCPU_A12_DBG_CTRL_2_inst                                                     0x00E2
#define SCPU_A12_DBG_CTRL_3_inst                                                     0x00E3
#define SCPU_A12_DBG_CTRL_write_en2_shift                                            (4)
#define SCPU_A12_DBG_CTRL_write_en2_mask                                             (0x00000010)
#define SCPU_A12_DBG_CTRL_write_en2(data)                                            (0x00000010&((data)<<4))
#define SCPU_A12_DBG_CTRL_write_en2_src(data)                                        ((0x00000010&(data))>>4)
#define SCPU_A12_DBG_CTRL_get_write_en2(data)                                        ((0x00000010&(data))>>4)
#define SCPU_A12_DBG_CTRL_dbg_wr_chk_m0_shift                                        (2)
#define SCPU_A12_DBG_CTRL_dbg_wr_chk_m0_mask                                         (0x0000000C)
#define SCPU_A12_DBG_CTRL_dbg_wr_chk_m0(data)                                        (0x0000000C&((data)<<2))
#define SCPU_A12_DBG_CTRL_dbg_wr_chk_m0_src(data)                                    ((0x0000000C&(data))>>2)
#define SCPU_A12_DBG_CTRL_get_dbg_wr_chk_m0(data)                                    ((0x0000000C&(data))>>2)
#define SCPU_A12_DBG_CTRL_write_en1_shift                                            (1)
#define SCPU_A12_DBG_CTRL_write_en1_mask                                             (0x00000002)
#define SCPU_A12_DBG_CTRL_write_en1(data)                                            (0x00000002&((data)<<1))
#define SCPU_A12_DBG_CTRL_write_en1_src(data)                                        ((0x00000002&(data))>>1)
#define SCPU_A12_DBG_CTRL_get_write_en1(data)                                        ((0x00000002&(data))>>1)
#define SCPU_A12_DBG_CTRL_dbg_en_m0_shift                                            (0)
#define SCPU_A12_DBG_CTRL_dbg_en_m0_mask                                             (0x00000001)
#define SCPU_A12_DBG_CTRL_dbg_en_m0(data)                                            (0x00000001&((data)<<0))
#define SCPU_A12_DBG_CTRL_dbg_en_m0_src(data)                                        ((0x00000001&(data))>>0)
#define SCPU_A12_DBG_CTRL_get_dbg_en_m0(data)                                        ((0x00000001&(data))>>0)


#define SCPU_A12_DBG_INT                                                             0x1805C390
#define SCPU_A12_DBG_INT_reg_addr                                                    "0xB805C390"
#define SCPU_A12_DBG_INT_reg                                                         0xB805C390
#define set_SCPU_A12_DBG_INT_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_INT_reg)=data)
#define get_SCPU_A12_DBG_INT_reg   (*((volatile unsigned int*) SCPU_A12_DBG_INT_reg))
#define SCPU_A12_DBG_INT_inst_adr                                                    "0x00E4"
#define SCPU_A12_DBG_INT_inst                                                        0x00E4
#define SCPU_A12_DBG_INT_scpu_int_m0_shift                                           (4)
#define SCPU_A12_DBG_INT_scpu_int_m0_mask                                            (0x00000010)
#define SCPU_A12_DBG_INT_scpu_int_m0(data)                                           (0x00000010&((data)<<4))
#define SCPU_A12_DBG_INT_scpu_int_m0_src(data)                                       ((0x00000010&(data))>>4)
#define SCPU_A12_DBG_INT_get_scpu_int_m0(data)                                       ((0x00000010&(data))>>4)
#define SCPU_A12_DBG_INT_scpu_int_en_m0_shift                                        (3)
#define SCPU_A12_DBG_INT_scpu_int_en_m0_mask                                         (0x00000008)
#define SCPU_A12_DBG_INT_scpu_int_en_m0(data)                                        (0x00000008&((data)<<3))
#define SCPU_A12_DBG_INT_scpu_int_en_m0_src(data)                                    ((0x00000008&(data))>>3)
#define SCPU_A12_DBG_INT_get_scpu_int_en_m0(data)                                    ((0x00000008&(data))>>3)
#define SCPU_A12_DBG_INT_scpu_neg_int_m0_shift                                       (2)
#define SCPU_A12_DBG_INT_scpu_neg_int_m0_mask                                        (0x00000004)
#define SCPU_A12_DBG_INT_scpu_neg_int_m0(data)                                       (0x00000004&((data)<<2))
#define SCPU_A12_DBG_INT_scpu_neg_int_m0_src(data)                                   ((0x00000004&(data))>>2)
#define SCPU_A12_DBG_INT_get_scpu_neg_int_m0(data)                                   ((0x00000004&(data))>>2)
#define SCPU_A12_DBG_INT_scpu_neg_int_en_m0_shift                                    (1)
#define SCPU_A12_DBG_INT_scpu_neg_int_en_m0_mask                                     (0x00000002)
#define SCPU_A12_DBG_INT_scpu_neg_int_en_m0(data)                                    (0x00000002&((data)<<1))
#define SCPU_A12_DBG_INT_scpu_neg_int_en_m0_src(data)                                ((0x00000002&(data))>>1)
#define SCPU_A12_DBG_INT_get_scpu_neg_int_en_m0(data)                                ((0x00000002&(data))>>1)
#define SCPU_A12_DBG_INT_write_data_shift                                            (0)
#define SCPU_A12_DBG_INT_write_data_mask                                             (0x00000001)
#define SCPU_A12_DBG_INT_write_data(data)                                            (0x00000001&((data)<<0))
#define SCPU_A12_DBG_INT_write_data_src(data)                                        ((0x00000001&(data))>>0)
#define SCPU_A12_DBG_INT_get_write_data(data)                                        ((0x00000001&(data))>>0)


#define SCPU_A12_DBG_ADDR                                                            0x1805C394
#define SCPU_A12_DBG_ADDR_reg_addr                                                   "0xB805C394"
#define SCPU_A12_DBG_ADDR_reg                                                        0xB805C394
#define set_SCPU_A12_DBG_ADDR_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_ADDR_reg)=data)
#define get_SCPU_A12_DBG_ADDR_reg   (*((volatile unsigned int*) SCPU_A12_DBG_ADDR_reg))
#define SCPU_A12_DBG_ADDR_inst_adr                                                   "0x00E5"
#define SCPU_A12_DBG_ADDR_inst                                                       0x00E5
#define SCPU_A12_DBG_ADDR_dbg_addr_m0_shift                                          (0)
#define SCPU_A12_DBG_ADDR_dbg_addr_m0_mask                                           (0xFFFFFFFF)
#define SCPU_A12_DBG_ADDR_dbg_addr_m0(data)                                          (0xFFFFFFFF&((data)<<0))
#define SCPU_A12_DBG_ADDR_dbg_addr_m0_src(data)                                      ((0xFFFFFFFF&(data))>>0)
#define SCPU_A12_DBG_ADDR_get_dbg_addr_m0(data)                                      ((0xFFFFFFFF&(data))>>0)


#define SCPU_A12_DBG_ADDR1                                                           0x1805C398
#define SCPU_A12_DBG_ADDR1_reg_addr                                                  "0xB805C398"
#define SCPU_A12_DBG_ADDR1_reg                                                       0xB805C398
#define set_SCPU_A12_DBG_ADDR1_reg(data)   (*((volatile unsigned int*) SCPU_A12_DBG_ADDR1_reg)=data)
#define get_SCPU_A12_DBG_ADDR1_reg   (*((volatile unsigned int*) SCPU_A12_DBG_ADDR1_reg))
#define SCPU_A12_DBG_ADDR1_inst_adr                                                  "0x00E6"
#define SCPU_A12_DBG_ADDR1_inst                                                      0x00E6
#define SCPU_A12_DBG_ADDR1_scpu_dbg_write_m0_shift                                   (0)
#define SCPU_A12_DBG_ADDR1_scpu_dbg_write_m0_mask                                    (0x00000001)
#define SCPU_A12_DBG_ADDR1_scpu_dbg_write_m0(data)                                   (0x00000001&((data)<<0))
#define SCPU_A12_DBG_ADDR1_scpu_dbg_write_m0_src(data)                               ((0x00000001&(data))>>0)
#define SCPU_A12_DBG_ADDR1_get_scpu_dbg_write_m0(data)                               ((0x00000001&(data))>>0)


#define SCPU_A12_DSS_C35_12D5T_CTRL                                                  0x1805C3d0
#define SCPU_A12_DSS_C35_12D5T_CTRL_reg_addr                                         "0xB805C3D0"
#define SCPU_A12_DSS_C35_12D5T_CTRL_reg                                              0xB805C3D0
#define set_SCPU_A12_DSS_C35_12D5T_CTRL_reg(data)   (*((volatile unsigned int*) SCPU_A12_DSS_C35_12D5T_CTRL_reg)=data)
#define get_SCPU_A12_DSS_C35_12D5T_CTRL_reg   (*((volatile unsigned int*) SCPU_A12_DSS_C35_12D5T_CTRL_reg))
#define SCPU_A12_DSS_C35_12D5T_CTRL_inst_adr                                         "0x00F4"
#define SCPU_A12_DSS_C35_12D5T_CTRL_inst                                             0x00F4
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_speed_en_shift                           (25)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_speed_en_mask                            (0x02000000)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_speed_en(data)                           (0x02000000&((data)<<25))
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_speed_en_src(data)                       ((0x02000000&(data))>>25)
#define SCPU_A12_DSS_C35_12D5T_CTRL_get_dss_c35_speed_en(data)                       ((0x02000000&(data))>>25)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_data_in_shift                            (5)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_data_in_mask                             (0x01FFFFE0)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_data_in(data)                            (0x01FFFFE0&((data)<<5))
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_data_in_src(data)                        ((0x01FFFFE0&(data))>>5)
#define SCPU_A12_DSS_C35_12D5T_CTRL_get_dss_c35_data_in(data)                        ((0x01FFFFE0&(data))>>5)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_wire_sel_shift                           (4)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_wire_sel_mask                            (0x00000010)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_wire_sel(data)                           (0x00000010&((data)<<4))
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_wire_sel_src(data)                       ((0x00000010&(data))>>4)
#define SCPU_A12_DSS_C35_12D5T_CTRL_get_dss_c35_wire_sel(data)                       ((0x00000010&(data))>>4)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_ro_sel_shift                             (1)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_ro_sel_mask                              (0x0000000E)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_ro_sel(data)                             (0x0000000E&((data)<<1))
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_ro_sel_src(data)                         ((0x0000000E&(data))>>1)
#define SCPU_A12_DSS_C35_12D5T_CTRL_get_dss_c35_ro_sel(data)                         ((0x0000000E&(data))>>1)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_dss_rst_n_shift                          (0)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_dss_rst_n_mask                           (0x00000001)
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_dss_rst_n(data)                          (0x00000001&((data)<<0))
#define SCPU_A12_DSS_C35_12D5T_CTRL_dss_c35_dss_rst_n_src(data)                      ((0x00000001&(data))>>0)
#define SCPU_A12_DSS_C35_12D5T_CTRL_get_dss_c35_dss_rst_n(data)                      ((0x00000001&(data))>>0)


#define SCPU_A12_DSS_C35_12D5T_STAT0                                                 0x1805C3d4
#define SCPU_A12_DSS_C35_12D5T_STAT0_reg_addr                                        "0xB805C3D4"
#define SCPU_A12_DSS_C35_12D5T_STAT0_reg                                             0xB805C3D4
#define set_SCPU_A12_DSS_C35_12D5T_STAT0_reg(data)   (*((volatile unsigned int*) SCPU_A12_DSS_C35_12D5T_STAT0_reg)=data)
#define get_SCPU_A12_DSS_C35_12D5T_STAT0_reg   (*((volatile unsigned int*) SCPU_A12_DSS_C35_12D5T_STAT0_reg))
#define SCPU_A12_DSS_C35_12D5T_STAT0_inst_adr                                        "0x00F5"
#define SCPU_A12_DSS_C35_12D5T_STAT0_inst                                            0x00F5
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_wsort_go_shift                          (21)
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_wsort_go_mask                           (0x00200000)
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_wsort_go(data)                          (0x00200000&((data)<<21))
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_wsort_go_src(data)                      ((0x00200000&(data))>>21)
#define SCPU_A12_DSS_C35_12D5T_STAT0_get_dss_c35_wsort_go(data)                      ((0x00200000&(data))>>21)
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_count_out_shift                         (1)
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_count_out_mask                          (0x001FFFFE)
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_count_out(data)                         (0x001FFFFE&((data)<<1))
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_count_out_src(data)                     ((0x001FFFFE&(data))>>1)
#define SCPU_A12_DSS_C35_12D5T_STAT0_get_dss_c35_count_out(data)                     ((0x001FFFFE&(data))>>1)
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_ready_shift                             (0)
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_ready_mask                              (0x00000001)
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_ready(data)                             (0x00000001&((data)<<0))
#define SCPU_A12_DSS_C35_12D5T_STAT0_dss_c35_ready_src(data)                         ((0x00000001&(data))>>0)
#define SCPU_A12_DSS_C35_12D5T_STAT0_get_dss_c35_ready(data)                         ((0x00000001&(data))>>0)


#define SCPU_A12_DSS_C35_12D5T_STAT1                                                 0x1805C3d8
#define SCPU_A12_DSS_C35_12D5T_STAT1_reg_addr                                        "0xB805C3D8"
#define SCPU_A12_DSS_C35_12D5T_STAT1_reg                                             0xB805C3D8
#define set_SCPU_A12_DSS_C35_12D5T_STAT1_reg(data)   (*((volatile unsigned int*) SCPU_A12_DSS_C35_12D5T_STAT1_reg)=data)
#define get_SCPU_A12_DSS_C35_12D5T_STAT1_reg   (*((volatile unsigned int*) SCPU_A12_DSS_C35_12D5T_STAT1_reg))
#define SCPU_A12_DSS_C35_12D5T_STAT1_inst_adr                                        "0x00F6"
#define SCPU_A12_DSS_C35_12D5T_STAT1_inst                                            0x00F6
#define SCPU_A12_DSS_C35_12D5T_STAT1_dss_c35_dbgo_shift                              (0)
#define SCPU_A12_DSS_C35_12D5T_STAT1_dss_c35_dbgo_mask                               (0x0000FFFF)
#define SCPU_A12_DSS_C35_12D5T_STAT1_dss_c35_dbgo(data)                              (0x0000FFFF&((data)<<0))
#define SCPU_A12_DSS_C35_12D5T_STAT1_dss_c35_dbgo_src(data)                          ((0x0000FFFF&(data))>>0)
#define SCPU_A12_DSS_C35_12D5T_STAT1_get_dss_c35_dbgo(data)                          ((0x0000FFFF&(data))>>0)


#define SCPU_A12_DSS_C35D5_12D5T_CTRL                                                0x1805C3dC
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_reg_addr                                       "0xB805C3DC"
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_reg                                            0xB805C3DC
#define set_SCPU_A12_DSS_C35D5_12D5T_CTRL_reg(data)   (*((volatile unsigned int*) SCPU_A12_DSS_C35D5_12D5T_CTRL_reg)=data)
#define get_SCPU_A12_DSS_C35D5_12D5T_CTRL_reg   (*((volatile unsigned int*) SCPU_A12_DSS_C35D5_12D5T_CTRL_reg))
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_inst_adr                                       "0x00F7"
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_inst                                           0x00F7
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_speed_en_shift                       (25)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_speed_en_mask                        (0x02000000)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_speed_en(data)                       (0x02000000&((data)<<25))
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_speed_en_src(data)                   ((0x02000000&(data))>>25)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_get_dss_c35d5_speed_en(data)                   ((0x02000000&(data))>>25)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_data_in_shift                        (5)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_data_in_mask                         (0x01FFFFE0)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_data_in(data)                        (0x01FFFFE0&((data)<<5))
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_data_in_src(data)                    ((0x01FFFFE0&(data))>>5)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_get_dss_c35d5_data_in(data)                    ((0x01FFFFE0&(data))>>5)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_wire_sel_shift                       (4)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_wire_sel_mask                        (0x00000010)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_wire_sel(data)                       (0x00000010&((data)<<4))
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_wire_sel_src(data)                   ((0x00000010&(data))>>4)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_get_dss_c35d5_wire_sel(data)                   ((0x00000010&(data))>>4)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_ro_sel_shift                         (1)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_ro_sel_mask                          (0x0000000E)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_ro_sel(data)                         (0x0000000E&((data)<<1))
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_ro_sel_src(data)                     ((0x0000000E&(data))>>1)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_get_dss_c35d5_ro_sel(data)                     ((0x0000000E&(data))>>1)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_dss_rst_n_shift                      (0)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_dss_rst_n_mask                       (0x00000001)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_dss_rst_n(data)                      (0x00000001&((data)<<0))
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_dss_c35d5_dss_rst_n_src(data)                  ((0x00000001&(data))>>0)
#define SCPU_A12_DSS_C35D5_12D5T_CTRL_get_dss_c35d5_dss_rst_n(data)                  ((0x00000001&(data))>>0)


#define SCPU_A12_DSS_C35D5_12D5T_STAT0                                               0x1805C3e0
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_reg_addr                                      "0xB805C3E0"
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_reg                                           0xB805C3E0
#define set_SCPU_A12_DSS_C35D5_12D5T_STAT0_reg(data)   (*((volatile unsigned int*) SCPU_A12_DSS_C35D5_12D5T_STAT0_reg)=data)
#define get_SCPU_A12_DSS_C35D5_12D5T_STAT0_reg   (*((volatile unsigned int*) SCPU_A12_DSS_C35D5_12D5T_STAT0_reg))
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_inst_adr                                      "0x00F8"
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_inst                                          0x00F8
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_wsort_go_shift                      (21)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_wsort_go_mask                       (0x00200000)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_wsort_go(data)                      (0x00200000&((data)<<21))
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_wsort_go_src(data)                  ((0x00200000&(data))>>21)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_get_dss_c35d5_wsort_go(data)                  ((0x00200000&(data))>>21)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_count_out_shift                     (1)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_count_out_mask                      (0x001FFFFE)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_count_out(data)                     (0x001FFFFE&((data)<<1))
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_count_out_src(data)                 ((0x001FFFFE&(data))>>1)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_get_dss_c35d5_count_out(data)                 ((0x001FFFFE&(data))>>1)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_ready_shift                         (0)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_ready_mask                          (0x00000001)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_ready(data)                         (0x00000001&((data)<<0))
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_dss_c35d5_ready_src(data)                     ((0x00000001&(data))>>0)
#define SCPU_A12_DSS_C35D5_12D5T_STAT0_get_dss_c35d5_ready(data)                     ((0x00000001&(data))>>0)


#define SCPU_A12_DSS_C35D5_12D5T_STAT1                                               0x1805C3e4
#define SCPU_A12_DSS_C35D5_12D5T_STAT1_reg_addr                                      "0xB805C3E4"
#define SCPU_A12_DSS_C35D5_12D5T_STAT1_reg                                           0xB805C3E4
#define set_SCPU_A12_DSS_C35D5_12D5T_STAT1_reg(data)   (*((volatile unsigned int*) SCPU_A12_DSS_C35D5_12D5T_STAT1_reg)=data)
#define get_SCPU_A12_DSS_C35D5_12D5T_STAT1_reg   (*((volatile unsigned int*) SCPU_A12_DSS_C35D5_12D5T_STAT1_reg))
#define SCPU_A12_DSS_C35D5_12D5T_STAT1_inst_adr                                      "0x00F9"
#define SCPU_A12_DSS_C35D5_12D5T_STAT1_inst                                          0x00F9
#define SCPU_A12_DSS_C35D5_12D5T_STAT1_dss_c35d5_dbgo_shift                          (0)
#define SCPU_A12_DSS_C35D5_12D5T_STAT1_dss_c35d5_dbgo_mask                           (0x0000FFFF)
#define SCPU_A12_DSS_C35D5_12D5T_STAT1_dss_c35d5_dbgo(data)                          (0x0000FFFF&((data)<<0))
#define SCPU_A12_DSS_C35D5_12D5T_STAT1_dss_c35d5_dbgo_src(data)                      ((0x0000FFFF&(data))>>0)
#define SCPU_A12_DSS_C35D5_12D5T_STAT1_get_dss_c35d5_dbgo(data)                      ((0x0000FFFF&(data))>>0)


#define SCPU_A12_SRAM_CTRL1                                                          0x1805C400
#define SCPU_A12_SRAM_CTRL1_reg_addr                                                 "0xB805C400"
#define SCPU_A12_SRAM_CTRL1_reg                                                      0xB805C400
#define set_SCPU_A12_SRAM_CTRL1_reg(data)   (*((volatile unsigned int*) SCPU_A12_SRAM_CTRL1_reg)=data)
#define get_SCPU_A12_SRAM_CTRL1_reg   (*((volatile unsigned int*) SCPU_A12_SRAM_CTRL1_reg))
#define SCPU_A12_SRAM_CTRL1_inst_adr                                                 "0x0000"
#define SCPU_A12_SRAM_CTRL1_inst                                                     0x0000
#define SCPU_A12_SRAM_CTRL1_SRAM_LS_shift                                            (1)
#define SCPU_A12_SRAM_CTRL1_SRAM_LS_mask                                             (0x00000002)
#define SCPU_A12_SRAM_CTRL1_SRAM_LS(data)                                            (0x00000002&((data)<<1))
#define SCPU_A12_SRAM_CTRL1_SRAM_LS_src(data)                                        ((0x00000002&(data))>>1)
#define SCPU_A12_SRAM_CTRL1_get_SRAM_LS(data)                                        ((0x00000002&(data))>>1)
#define SCPU_A12_SRAM_CTRL1_SRAM_RME_shift                                           (0)
#define SCPU_A12_SRAM_CTRL1_SRAM_RME_mask                                            (0x00000001)
#define SCPU_A12_SRAM_CTRL1_SRAM_RME(data)                                           (0x00000001&((data)<<0))
#define SCPU_A12_SRAM_CTRL1_SRAM_RME_src(data)                                       ((0x00000001&(data))>>0)
#define SCPU_A12_SRAM_CTRL1_get_SRAM_RME(data)                                       ((0x00000001&(data))>>0)


#define SCPU_A12_SCU_CTRL                                                            0x1805C404
#define SCPU_A12_SCU_CTRL_reg_addr                                                   "0xB805C404"
#define SCPU_A12_SCU_CTRL_reg                                                        0xB805C404
#define set_SCPU_A12_SCU_CTRL_reg(data)   (*((volatile unsigned int*) SCPU_A12_SCU_CTRL_reg)=data)
#define get_SCPU_A12_SCU_CTRL_reg   (*((volatile unsigned int*) SCPU_A12_SCU_CTRL_reg))
#define SCPU_A12_SCU_CTRL_inst_adr                                                   "0x0001"
#define SCPU_A12_SCU_CTRL_inst                                                       0x0001
#define SCPU_A12_SCU_CTRL_SRAM_RM_l2tag_shift                                        (28)
#define SCPU_A12_SCU_CTRL_SRAM_RM_l2tag_mask                                         (0xF0000000)
#define SCPU_A12_SCU_CTRL_SRAM_RM_l2tag(data)                                        (0xF0000000&((data)<<28))
#define SCPU_A12_SCU_CTRL_SRAM_RM_l2tag_src(data)                                    ((0xF0000000&(data))>>28)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_l2tag(data)                                    ((0xF0000000&(data))>>28)
#define SCPU_A12_SCU_CTRL_SRAM_RM_l2data_shift                                       (24)
#define SCPU_A12_SCU_CTRL_SRAM_RM_l2data_mask                                        (0x0F000000)
#define SCPU_A12_SCU_CTRL_SRAM_RM_l2data(data)                                       (0x0F000000&((data)<<24))
#define SCPU_A12_SCU_CTRL_SRAM_RM_l2data_src(data)                                   ((0x0F000000&(data))>>24)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_l2data(data)                                   ((0x0F000000&(data))>>24)
#define SCPU_A12_SCU_CTRL_SRAM_RM_lfbram_shift                                       (20)
#define SCPU_A12_SCU_CTRL_SRAM_RM_lfbram_mask                                        (0x00F00000)
#define SCPU_A12_SCU_CTRL_SRAM_RM_lfbram(data)                                       (0x00F00000&((data)<<20))
#define SCPU_A12_SCU_CTRL_SRAM_RM_lfbram_src(data)                                   ((0x00F00000&(data))>>20)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_lfbram(data)                                   ((0x00F00000&(data))>>20)
#define SCPU_A12_SCU_CTRL_SRAM_RM_stbram_shift                                       (16)
#define SCPU_A12_SCU_CTRL_SRAM_RM_stbram_mask                                        (0x000F0000)
#define SCPU_A12_SCU_CTRL_SRAM_RM_stbram(data)                                       (0x000F0000&((data)<<16))
#define SCPU_A12_SCU_CTRL_SRAM_RM_stbram_src(data)                                   ((0x000F0000&(data))>>16)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_stbram(data)                                   ((0x000F0000&(data))>>16)
#define SCPU_A12_SCU_CTRL_SRAM_RM_evbram_shift                                       (12)
#define SCPU_A12_SCU_CTRL_SRAM_RM_evbram_mask                                        (0x0000F000)
#define SCPU_A12_SCU_CTRL_SRAM_RM_evbram(data)                                       (0x0000F000&((data)<<12))
#define SCPU_A12_SCU_CTRL_SRAM_RM_evbram_src(data)                                   ((0x0000F000&(data))>>12)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_evbram(data)                                   ((0x0000F000&(data))>>12)
#define SCPU_A12_SCU_CTRL_SRAM_RM_ddata_shift                                        (8)
#define SCPU_A12_SCU_CTRL_SRAM_RM_ddata_mask                                         (0x00000F00)
#define SCPU_A12_SCU_CTRL_SRAM_RM_ddata(data)                                        (0x00000F00&((data)<<8))
#define SCPU_A12_SCU_CTRL_SRAM_RM_ddata_src(data)                                    ((0x00000F00&(data))>>8)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_ddata(data)                                    ((0x00000F00&(data))>>8)
#define SCPU_A12_SCU_CTRL_SRAM_RM_dtag_shift                                         (4)
#define SCPU_A12_SCU_CTRL_SRAM_RM_dtag_mask                                          (0x000000F0)
#define SCPU_A12_SCU_CTRL_SRAM_RM_dtag(data)                                         (0x000000F0&((data)<<4))
#define SCPU_A12_SCU_CTRL_SRAM_RM_dtag_src(data)                                     ((0x000000F0&(data))>>4)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_dtag(data)                                     ((0x000000F0&(data))>>4)
#define SCPU_A12_SCU_CTRL_SRAM_RM_tlbram_shift                                       (0)
#define SCPU_A12_SCU_CTRL_SRAM_RM_tlbram_mask                                        (0x0000000F)
#define SCPU_A12_SCU_CTRL_SRAM_RM_tlbram(data)                                       (0x0000000F&((data)<<0))
#define SCPU_A12_SCU_CTRL_SRAM_RM_tlbram_src(data)                                   ((0x0000000F&(data))>>0)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_tlbram(data)                                   ((0x0000000F&(data))>>0)


#define SCPU_A12_SCU_CTRL                                                            0x1805C408
#define SCPU_A12_SCU_CTRL_reg_addr                                                   "0xB805C408"
#define SCPU_A12_SCU_CTRL_reg                                                        0xB805C408
#define set_SCPU_A12_SCU_CTRL_reg(data)   (*((volatile unsigned int*) SCPU_A12_SCU_CTRL_reg)=data)
#define get_SCPU_A12_SCU_CTRL_reg   (*((volatile unsigned int*) SCPU_A12_SCU_CTRL_reg))
#define SCPU_A12_SCU_CTRL_inst_adr                                                   "0x0002"
#define SCPU_A12_SCU_CTRL_inst                                                       0x0002
#define SCPU_A12_SCU_CTRL_SRAM_RM_tlbbuf_shift                                       (28)
#define SCPU_A12_SCU_CTRL_SRAM_RM_tlbbuf_mask                                        (0xF0000000)
#define SCPU_A12_SCU_CTRL_SRAM_RM_tlbbuf(data)                                       (0xF0000000&((data)<<28))
#define SCPU_A12_SCU_CTRL_SRAM_RM_tlbbuf_src(data)                                   ((0xF0000000&(data))>>28)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_tlbbuf(data)                                   ((0xF0000000&(data))>>28)
#define SCPU_A12_SCU_CTRL_SRAM_RM_pred1_shift                                        (24)
#define SCPU_A12_SCU_CTRL_SRAM_RM_pred1_mask                                         (0x0F000000)
#define SCPU_A12_SCU_CTRL_SRAM_RM_pred1(data)                                        (0x0F000000&((data)<<24))
#define SCPU_A12_SCU_CTRL_SRAM_RM_pred1_src(data)                                    ((0x0F000000&(data))>>24)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_pred1(data)                                    ((0x0F000000&(data))>>24)
#define SCPU_A12_SCU_CTRL_SRAM_RM_pred0_shift                                        (20)
#define SCPU_A12_SCU_CTRL_SRAM_RM_pred0_mask                                         (0x00F00000)
#define SCPU_A12_SCU_CTRL_SRAM_RM_pred0(data)                                        (0x00F00000&((data)<<20))
#define SCPU_A12_SCU_CTRL_SRAM_RM_pred0_src(data)                                    ((0x00F00000&(data))>>20)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_pred0(data)                                    ((0x00F00000&(data))>>20)
#define SCPU_A12_SCU_CTRL_SRAM_RM_btacc_shift                                        (16)
#define SCPU_A12_SCU_CTRL_SRAM_RM_btacc_mask                                         (0x000F0000)
#define SCPU_A12_SCU_CTRL_SRAM_RM_btacc(data)                                        (0x000F0000&((data)<<16))
#define SCPU_A12_SCU_CTRL_SRAM_RM_btacc_src(data)                                    ((0x000F0000&(data))>>16)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_btacc(data)                                    ((0x000F0000&(data))>>16)
#define SCPU_A12_SCU_CTRL_SRAM_RM_btact_shift                                        (12)
#define SCPU_A12_SCU_CTRL_SRAM_RM_btact_mask                                         (0x0000F000)
#define SCPU_A12_SCU_CTRL_SRAM_RM_btact(data)                                        (0x0000F000&((data)<<12))
#define SCPU_A12_SCU_CTRL_SRAM_RM_btact_src(data)                                    ((0x0000F000&(data))>>12)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_btact(data)                                    ((0x0000F000&(data))>>12)
#define SCPU_A12_SCU_CTRL_SRAM_RM_idata_shift                                        (8)
#define SCPU_A12_SCU_CTRL_SRAM_RM_idata_mask                                         (0x00000F00)
#define SCPU_A12_SCU_CTRL_SRAM_RM_idata(data)                                        (0x00000F00&((data)<<8))
#define SCPU_A12_SCU_CTRL_SRAM_RM_idata_src(data)                                    ((0x00000F00&(data))>>8)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_idata(data)                                    ((0x00000F00&(data))>>8)
#define SCPU_A12_SCU_CTRL_SRAM_RM_itag_shift                                         (4)
#define SCPU_A12_SCU_CTRL_SRAM_RM_itag_mask                                          (0x000000F0)
#define SCPU_A12_SCU_CTRL_SRAM_RM_itag(data)                                         (0x000000F0&((data)<<4))
#define SCPU_A12_SCU_CTRL_SRAM_RM_itag_src(data)                                     ((0x000000F0&(data))>>4)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_itag(data)                                     ((0x000000F0&(data))>>4)
#define SCPU_A12_SCU_CTRL_SRAM_RM_scu_shift                                          (0)
#define SCPU_A12_SCU_CTRL_SRAM_RM_scu_mask                                           (0x0000000F)
#define SCPU_A12_SCU_CTRL_SRAM_RM_scu(data)                                          (0x0000000F&((data)<<0))
#define SCPU_A12_SCU_CTRL_SRAM_RM_scu_src(data)                                      ((0x0000000F&(data))>>0)
#define SCPU_A12_SCU_CTRL_get_SRAM_RM_scu(data)                                      ((0x0000000F&(data))>>0)


#define SCPU_A12_SHARE_EN                                                            0x1805C450
#define SCPU_A12_SHARE_EN_reg_addr                                                   "0xB805C450"
#define SCPU_A12_SHARE_EN_reg                                                        0xB805C450
#define set_SCPU_A12_SHARE_EN_reg(data)   (*((volatile unsigned int*) SCPU_A12_SHARE_EN_reg)=data)
#define get_SCPU_A12_SHARE_EN_reg   (*((volatile unsigned int*) SCPU_A12_SHARE_EN_reg))
#define SCPU_A12_SHARE_EN_inst_adr                                                   "0x0014"
#define SCPU_A12_SHARE_EN_inst                                                       0x0014
#define SCPU_A12_SHARE_EN_share_bus_en_shift                                         (0)
#define SCPU_A12_SHARE_EN_share_bus_en_mask                                          (0x00000001)
#define SCPU_A12_SHARE_EN_share_bus_en(data)                                         (0x00000001&((data)<<0))
#define SCPU_A12_SHARE_EN_share_bus_en_src(data)                                     ((0x00000001&(data))>>0)
#define SCPU_A12_SHARE_EN_get_share_bus_en(data)                                     ((0x00000001&(data))>>0)


#define SCPU_A12_MBISTACK_ALL                                                        0x1805C454
#define SCPU_A12_MBISTACK_ALL_reg_addr                                               "0xB805C454"
#define SCPU_A12_MBISTACK_ALL_reg                                                    0xB805C454
#define set_SCPU_A12_MBISTACK_ALL_reg(data)   (*((volatile unsigned int*) SCPU_A12_MBISTACK_ALL_reg)=data)
#define get_SCPU_A12_MBISTACK_ALL_reg   (*((volatile unsigned int*) SCPU_A12_MBISTACK_ALL_reg))
#define SCPU_A12_MBISTACK_ALL_inst_adr                                               "0x0015"
#define SCPU_A12_MBISTACK_ALL_inst                                                   0x0015
#define SCPU_A12_MBISTACK_ALL_MBISTACK_all_shift                                     (0)
#define SCPU_A12_MBISTACK_ALL_MBISTACK_all_mask                                      (0x00000001)
#define SCPU_A12_MBISTACK_ALL_MBISTACK_all(data)                                     (0x00000001&((data)<<0))
#define SCPU_A12_MBISTACK_ALL_MBISTACK_all_src(data)                                 ((0x00000001&(data))>>0)
#define SCPU_A12_MBISTACK_ALL_get_MBISTACK_all(data)                                 ((0x00000001&(data))>>0)


#define SCPU_A12_MBISTACK1_DBG                                                       0x1805C458
#define SCPU_A12_MBISTACK1_DBG_reg_addr                                              "0xB805C458"
#define SCPU_A12_MBISTACK1_DBG_reg                                                   0xB805C458
#define set_SCPU_A12_MBISTACK1_DBG_reg(data)   (*((volatile unsigned int*) SCPU_A12_MBISTACK1_DBG_reg)=data)
#define get_SCPU_A12_MBISTACK1_DBG_reg   (*((volatile unsigned int*) SCPU_A12_MBISTACK1_DBG_reg))
#define SCPU_A12_MBISTACK1_DBG_inst_adr                                              "0x0016"
#define SCPU_A12_MBISTACK1_DBG_inst                                                  0x0016
#define SCPU_A12_MBISTACK1_DBG_MBISTACK3_DBG_shift                                   (5)
#define SCPU_A12_MBISTACK1_DBG_MBISTACK3_DBG_mask                                    (0x00000020)
#define SCPU_A12_MBISTACK1_DBG_MBISTACK3_DBG(data)                                   (0x00000020&((data)<<5))
#define SCPU_A12_MBISTACK1_DBG_MBISTACK3_DBG_src(data)                               ((0x00000020&(data))>>5)
#define SCPU_A12_MBISTACK1_DBG_get_MBISTACK3_DBG(data)                               ((0x00000020&(data))>>5)
#define SCPU_A12_MBISTACK1_DBG_MBISTACK2_DBG_shift                                   (4)
#define SCPU_A12_MBISTACK1_DBG_MBISTACK2_DBG_mask                                    (0x00000010)
#define SCPU_A12_MBISTACK1_DBG_MBISTACK2_DBG(data)                                   (0x00000010&((data)<<4))
#define SCPU_A12_MBISTACK1_DBG_MBISTACK2_DBG_src(data)                               ((0x00000010&(data))>>4)
#define SCPU_A12_MBISTACK1_DBG_get_MBISTACK2_DBG(data)                               ((0x00000010&(data))>>4)
#define SCPU_A12_MBISTACK1_DBG_MBISTACK1_DBG_shift                                   (0)
#define SCPU_A12_MBISTACK1_DBG_MBISTACK1_DBG_mask                                    (0x0000000F)
#define SCPU_A12_MBISTACK1_DBG_MBISTACK1_DBG(data)                                   (0x0000000F&((data)<<0))
#define SCPU_A12_MBISTACK1_DBG_MBISTACK1_DBG_src(data)                               ((0x0000000F&(data))>>0)
#define SCPU_A12_MBISTACK1_DBG_get_MBISTACK1_DBG(data)                               ((0x0000000F&(data))>>0)


#define SCPU_A12_BIST_RSTN                                                           0x1805C500
#define SCPU_A12_BIST_RSTN_reg_addr                                                  "0xB805C500"
#define SCPU_A12_BIST_RSTN_reg                                                       0xB805C500
#define set_SCPU_A12_BIST_RSTN_reg(data)   (*((volatile unsigned int*) SCPU_A12_BIST_RSTN_reg)=data)
#define get_SCPU_A12_BIST_RSTN_reg   (*((volatile unsigned int*) SCPU_A12_BIST_RSTN_reg))
#define SCPU_A12_BIST_RSTN_inst_adr                                                  "0x0040"
#define SCPU_A12_BIST_RSTN_inst                                                      0x0040
#define SCPU_A12_BIST_RSTN_BIST_RSTN_shift                                           (0)
#define SCPU_A12_BIST_RSTN_BIST_RSTN_mask                                            (0x00000001)
#define SCPU_A12_BIST_RSTN_BIST_RSTN(data)                                           (0x00000001&((data)<<0))
#define SCPU_A12_BIST_RSTN_BIST_RSTN_src(data)                                       ((0x00000001&(data))>>0)
#define SCPU_A12_BIST_RSTN_get_BIST_RSTN(data)                                       ((0x00000001&(data))>>0)


#define SCPU_A12_BIST_MODE_ALL                                                       0x1805C504
#define SCPU_A12_BIST_MODE_ALL_reg_addr                                              "0xB805C504"
#define SCPU_A12_BIST_MODE_ALL_reg                                                   0xB805C504
#define set_SCPU_A12_BIST_MODE_ALL_reg(data)   (*((volatile unsigned int*) SCPU_A12_BIST_MODE_ALL_reg)=data)
#define get_SCPU_A12_BIST_MODE_ALL_reg   (*((volatile unsigned int*) SCPU_A12_BIST_MODE_ALL_reg))
#define SCPU_A12_BIST_MODE_ALL_inst_adr                                              "0x0041"
#define SCPU_A12_BIST_MODE_ALL_inst                                                  0x0041
#define SCPU_A12_BIST_MODE_ALL_BIST_MODE_all_shift                                   (0)
#define SCPU_A12_BIST_MODE_ALL_BIST_MODE_all_mask                                    (0x00000001)
#define SCPU_A12_BIST_MODE_ALL_BIST_MODE_all(data)                                   (0x00000001&((data)<<0))
#define SCPU_A12_BIST_MODE_ALL_BIST_MODE_all_src(data)                               ((0x00000001&(data))>>0)
#define SCPU_A12_BIST_MODE_ALL_get_BIST_MODE_all(data)                               ((0x00000001&(data))>>0)


#define SCPU_A12_BIST_MODE1                                                          0x1805C508
#define SCPU_A12_BIST_MODE1_reg_addr                                                 "0xB805C508"
#define SCPU_A12_BIST_MODE1_reg                                                      0xB805C508
#define set_SCPU_A12_BIST_MODE1_reg(data)   (*((volatile unsigned int*) SCPU_A12_BIST_MODE1_reg)=data)
#define get_SCPU_A12_BIST_MODE1_reg   (*((volatile unsigned int*) SCPU_A12_BIST_MODE1_reg))
#define SCPU_A12_BIST_MODE1_inst_adr                                                 "0x0042"
#define SCPU_A12_BIST_MODE1_inst                                                     0x0042
#define SCPU_A12_BIST_MODE1_BIST_MODE1_tlb_buf_shift                                 (10)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_tlb_buf_mask                                  (0x00000400)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_tlb_buf(data)                                 (0x00000400&((data)<<10))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_tlb_buf_src(data)                             ((0x00000400&(data))>>10)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_tlb_buf(data)                             ((0x00000400&(data))>>10)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_tlb_ram_shift                                 (9)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_tlb_ram_mask                                  (0x00000200)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_tlb_ram(data)                                 (0x00000200&((data)<<9))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_tlb_ram_src(data)                             ((0x00000200&(data))>>9)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_tlb_ram(data)                             ((0x00000200&(data))>>9)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_pred_8bit_shift                               (8)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_pred_8bit_mask                                (0x00000100)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_pred_8bit(data)                               (0x00000100&((data)<<8))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_pred_8bit_src(data)                           ((0x00000100&(data))>>8)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_pred_8bit(data)                           ((0x00000100&(data))>>8)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_pred_4bit_shift                               (7)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_pred_4bit_mask                                (0x00000080)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_pred_4bit(data)                               (0x00000080&((data)<<7))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_pred_4bit_src(data)                           ((0x00000080&(data))>>7)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_pred_4bit(data)                           ((0x00000080&(data))>>7)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_btac_ctrl_shift                               (6)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_btac_ctrl_mask                                (0x00000040)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_btac_ctrl(data)                               (0x00000040&((data)<<6))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_btac_ctrl_src(data)                           ((0x00000040&(data))>>6)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_btac_ctrl(data)                           ((0x00000040&(data))>>6)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_btac_tag_shift                                (5)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_btac_tag_mask                                 (0x00000020)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_btac_tag(data)                                (0x00000020&((data)<<5))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_btac_tag_src(data)                            ((0x00000020&(data))>>5)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_btac_tag(data)                            ((0x00000020&(data))>>5)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_dtag1_shift                                   (4)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_dtag1_mask                                    (0x00000010)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_dtag1(data)                                   (0x00000010&((data)<<4))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_dtag1_src(data)                               ((0x00000010&(data))>>4)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_dtag1(data)                               ((0x00000010&(data))>>4)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_dtag0_shift                                   (3)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_dtag0_mask                                    (0x00000008)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_dtag0(data)                                   (0x00000008&((data)<<3))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_dtag0_src(data)                               ((0x00000008&(data))>>3)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_dtag0(data)                               ((0x00000008&(data))>>3)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_ddata_shift                                   (2)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_ddata_mask                                    (0x00000004)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_ddata(data)                                   (0x00000004&((data)<<2))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_ddata_src(data)                               ((0x00000004&(data))>>2)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_ddata(data)                               ((0x00000004&(data))>>2)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_itag_shift                                    (1)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_itag_mask                                     (0x00000002)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_itag(data)                                    (0x00000002&((data)<<1))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_itag_src(data)                                ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_itag(data)                                ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_idata_shift                                   (0)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_idata_mask                                    (0x00000001)
#define SCPU_A12_BIST_MODE1_BIST_MODE1_idata(data)                                   (0x00000001&((data)<<0))
#define SCPU_A12_BIST_MODE1_BIST_MODE1_idata_src(data)                               ((0x00000001&(data))>>0)
#define SCPU_A12_BIST_MODE1_get_BIST_MODE1_idata(data)                               ((0x00000001&(data))>>0)


#define SCPU_A12_BIST_MODE2                                                          0x1805C50C
#define SCPU_A12_BIST_MODE2_reg_addr                                                 "0xB805C50C"
#define SCPU_A12_BIST_MODE2_reg                                                      0xB805C50C
#define set_SCPU_A12_BIST_MODE2_reg(data)   (*((volatile unsigned int*) SCPU_A12_BIST_MODE2_reg)=data)
#define get_SCPU_A12_BIST_MODE2_reg   (*((volatile unsigned int*) SCPU_A12_BIST_MODE2_reg))
#define SCPU_A12_BIST_MODE2_inst_adr                                                 "0x0043"
#define SCPU_A12_BIST_MODE2_inst                                                     0x0043
#define SCPU_A12_BIST_MODE2_BIST_MODE2_linefill_buf_shift                            (2)
#define SCPU_A12_BIST_MODE2_BIST_MODE2_linefill_buf_mask                             (0x00000004)
#define SCPU_A12_BIST_MODE2_BIST_MODE2_linefill_buf(data)                            (0x00000004&((data)<<2))
#define SCPU_A12_BIST_MODE2_BIST_MODE2_linefill_buf_src(data)                        ((0x00000004&(data))>>2)
#define SCPU_A12_BIST_MODE2_get_BIST_MODE2_linefill_buf(data)                        ((0x00000004&(data))>>2)
#define SCPU_A12_BIST_MODE2_BIST_MODE2_eviction_buf_shift                            (1)
#define SCPU_A12_BIST_MODE2_BIST_MODE2_eviction_buf_mask                             (0x00000002)
#define SCPU_A12_BIST_MODE2_BIST_MODE2_eviction_buf(data)                            (0x00000002&((data)<<1))
#define SCPU_A12_BIST_MODE2_BIST_MODE2_eviction_buf_src(data)                        ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_MODE2_get_BIST_MODE2_eviction_buf(data)                        ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_MODE2_BIST_MODE2_store_buf_shift                               (0)
#define SCPU_A12_BIST_MODE2_BIST_MODE2_store_buf_mask                                (0x00000001)
#define SCPU_A12_BIST_MODE2_BIST_MODE2_store_buf(data)                               (0x00000001&((data)<<0))
#define SCPU_A12_BIST_MODE2_BIST_MODE2_store_buf_src(data)                           ((0x00000001&(data))>>0)
#define SCPU_A12_BIST_MODE2_get_BIST_MODE2_store_buf(data)                           ((0x00000001&(data))>>0)


#define SCPU_A12_BIST_MODE3                                                          0x1805C510
#define SCPU_A12_BIST_MODE3_reg_addr                                                 "0xB805C510"
#define SCPU_A12_BIST_MODE3_reg                                                      0xB805C510
#define set_SCPU_A12_BIST_MODE3_reg(data)   (*((volatile unsigned int*) SCPU_A12_BIST_MODE3_reg)=data)
#define get_SCPU_A12_BIST_MODE3_reg   (*((volatile unsigned int*) SCPU_A12_BIST_MODE3_reg))
#define SCPU_A12_BIST_MODE3_inst_adr                                                 "0x0044"
#define SCPU_A12_BIST_MODE3_inst                                                     0x0044
#define SCPU_A12_BIST_MODE3_BIST_MODE3_l2tag_shift                                   (1)
#define SCPU_A12_BIST_MODE3_BIST_MODE3_l2tag_mask                                    (0x00000002)
#define SCPU_A12_BIST_MODE3_BIST_MODE3_l2tag(data)                                   (0x00000002&((data)<<1))
#define SCPU_A12_BIST_MODE3_BIST_MODE3_l2tag_src(data)                               ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_MODE3_get_BIST_MODE3_l2tag(data)                               ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_MODE3_BIST_MODE3_scu_shift                                     (0)
#define SCPU_A12_BIST_MODE3_BIST_MODE3_scu_mask                                      (0x00000001)
#define SCPU_A12_BIST_MODE3_BIST_MODE3_scu(data)                                     (0x00000001&((data)<<0))
#define SCPU_A12_BIST_MODE3_BIST_MODE3_scu_src(data)                                 ((0x00000001&(data))>>0)
#define SCPU_A12_BIST_MODE3_get_BIST_MODE3_scu(data)                                 ((0x00000001&(data))>>0)


#define SCPU_A12_BIST_DONE1                                                          0x1805C514
#define SCPU_A12_BIST_DONE1_reg_addr                                                 "0xB805C514"
#define SCPU_A12_BIST_DONE1_reg                                                      0xB805C514
#define set_SCPU_A12_BIST_DONE1_reg(data)   (*((volatile unsigned int*) SCPU_A12_BIST_DONE1_reg)=data)
#define get_SCPU_A12_BIST_DONE1_reg   (*((volatile unsigned int*) SCPU_A12_BIST_DONE1_reg))
#define SCPU_A12_BIST_DONE1_inst_adr                                                 "0x0045"
#define SCPU_A12_BIST_DONE1_inst                                                     0x0045
#define SCPU_A12_BIST_DONE1_BIST_DONE1_tlb_buf_shift                                 (10)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_tlb_buf_mask                                  (0x00000400)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_tlb_buf(data)                                 (0x00000400&((data)<<10))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_tlb_buf_src(data)                             ((0x00000400&(data))>>10)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_tlb_buf(data)                             ((0x00000400&(data))>>10)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_tlb_ram_shift                                 (9)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_tlb_ram_mask                                  (0x00000200)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_tlb_ram(data)                                 (0x00000200&((data)<<9))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_tlb_ram_src(data)                             ((0x00000200&(data))>>9)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_tlb_ram(data)                             ((0x00000200&(data))>>9)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_pred_8bit_shift                               (8)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_pred_8bit_mask                                (0x00000100)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_pred_8bit(data)                               (0x00000100&((data)<<8))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_pred_8bit_src(data)                           ((0x00000100&(data))>>8)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_pred_8bit(data)                           ((0x00000100&(data))>>8)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_pred_4bit_shift                               (7)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_pred_4bit_mask                                (0x00000080)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_pred_4bit(data)                               (0x00000080&((data)<<7))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_pred_4bit_src(data)                           ((0x00000080&(data))>>7)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_pred_4bit(data)                           ((0x00000080&(data))>>7)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_btac_ctrl_shift                               (6)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_btac_ctrl_mask                                (0x00000040)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_btac_ctrl(data)                               (0x00000040&((data)<<6))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_btac_ctrl_src(data)                           ((0x00000040&(data))>>6)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_btac_ctrl(data)                           ((0x00000040&(data))>>6)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_btac_tag_shift                                (5)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_btac_tag_mask                                 (0x00000020)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_btac_tag(data)                                (0x00000020&((data)<<5))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_btac_tag_src(data)                            ((0x00000020&(data))>>5)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_btac_tag(data)                            ((0x00000020&(data))>>5)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_dtag1_shift                                   (4)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_dtag1_mask                                    (0x00000010)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_dtag1(data)                                   (0x00000010&((data)<<4))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_dtag1_src(data)                               ((0x00000010&(data))>>4)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_dtag1(data)                               ((0x00000010&(data))>>4)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_dtag0_shift                                   (3)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_dtag0_mask                                    (0x00000008)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_dtag0(data)                                   (0x00000008&((data)<<3))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_dtag0_src(data)                               ((0x00000008&(data))>>3)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_dtag0(data)                               ((0x00000008&(data))>>3)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_ddata_shift                                   (2)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_ddata_mask                                    (0x00000004)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_ddata(data)                                   (0x00000004&((data)<<2))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_ddata_src(data)                               ((0x00000004&(data))>>2)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_ddata(data)                               ((0x00000004&(data))>>2)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_itag_shift                                    (1)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_itag_mask                                     (0x00000002)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_itag(data)                                    (0x00000002&((data)<<1))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_itag_src(data)                                ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_itag(data)                                ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_idata_shift                                   (0)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_idata_mask                                    (0x00000001)
#define SCPU_A12_BIST_DONE1_BIST_DONE1_idata(data)                                   (0x00000001&((data)<<0))
#define SCPU_A12_BIST_DONE1_BIST_DONE1_idata_src(data)                               ((0x00000001&(data))>>0)
#define SCPU_A12_BIST_DONE1_get_BIST_DONE1_idata(data)                               ((0x00000001&(data))>>0)


#define SCPU_A12_BIST_DONE2                                                          0x1805C518
#define SCPU_A12_BIST_DONE2_reg_addr                                                 "0xB805C518"
#define SCPU_A12_BIST_DONE2_reg                                                      0xB805C518
#define set_SCPU_A12_BIST_DONE2_reg(data)   (*((volatile unsigned int*) SCPU_A12_BIST_DONE2_reg)=data)
#define get_SCPU_A12_BIST_DONE2_reg   (*((volatile unsigned int*) SCPU_A12_BIST_DONE2_reg))
#define SCPU_A12_BIST_DONE2_inst_adr                                                 "0x0046"
#define SCPU_A12_BIST_DONE2_inst                                                     0x0046
#define SCPU_A12_BIST_DONE2_BIST_DONE2_linefill_buf_shift                            (2)
#define SCPU_A12_BIST_DONE2_BIST_DONE2_linefill_buf_mask                             (0x00000004)
#define SCPU_A12_BIST_DONE2_BIST_DONE2_linefill_buf(data)                            (0x00000004&((data)<<2))
#define SCPU_A12_BIST_DONE2_BIST_DONE2_linefill_buf_src(data)                        ((0x00000004&(data))>>2)
#define SCPU_A12_BIST_DONE2_get_BIST_DONE2_linefill_buf(data)                        ((0x00000004&(data))>>2)
#define SCPU_A12_BIST_DONE2_BIST_DONE2_eviction_buf_shift                            (1)
#define SCPU_A12_BIST_DONE2_BIST_DONE2_eviction_buf_mask                             (0x00000002)
#define SCPU_A12_BIST_DONE2_BIST_DONE2_eviction_buf(data)                            (0x00000002&((data)<<1))
#define SCPU_A12_BIST_DONE2_BIST_DONE2_eviction_buf_src(data)                        ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_DONE2_get_BIST_DONE2_eviction_buf(data)                        ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_DONE2_BIST_DONE2_store_buf_shift                               (0)
#define SCPU_A12_BIST_DONE2_BIST_DONE2_store_buf_mask                                (0x00000001)
#define SCPU_A12_BIST_DONE2_BIST_DONE2_store_buf(data)                               (0x00000001&((data)<<0))
#define SCPU_A12_BIST_DONE2_BIST_DONE2_store_buf_src(data)                           ((0x00000001&(data))>>0)
#define SCPU_A12_BIST_DONE2_get_BIST_DONE2_store_buf(data)                           ((0x00000001&(data))>>0)


#define SCPU_A12_BIST_DONE3                                                          0x1805C51C
#define SCPU_A12_BIST_DONE3_reg_addr                                                 "0xB805C51C"
#define SCPU_A12_BIST_DONE3_reg                                                      0xB805C51C
#define set_SCPU_A12_BIST_DONE3_reg(data)   (*((volatile unsigned int*) SCPU_A12_BIST_DONE3_reg)=data)
#define get_SCPU_A12_BIST_DONE3_reg   (*((volatile unsigned int*) SCPU_A12_BIST_DONE3_reg))
#define SCPU_A12_BIST_DONE3_inst_adr                                                 "0x0047"
#define SCPU_A12_BIST_DONE3_inst                                                     0x0047
#define SCPU_A12_BIST_DONE3_BIST_DONE3_l2tag_shift                                   (1)
#define SCPU_A12_BIST_DONE3_BIST_DONE3_l2tag_mask                                    (0x00000002)
#define SCPU_A12_BIST_DONE3_BIST_DONE3_l2tag(data)                                   (0x00000002&((data)<<1))
#define SCPU_A12_BIST_DONE3_BIST_DONE3_l2tag_src(data)                               ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_DONE3_get_BIST_DONE3_l2tag(data)                               ((0x00000002&(data))>>1)
#define SCPU_A12_BIST_DONE3_BIST_DONE3_scu_shift                                     (0)
#define SCPU_A12_BIST_DONE3_BIST_DONE3_scu_mask                                      (0x00000001)
#define SCPU_A12_BIST_DONE3_BIST_DONE3_scu(data)                                     (0x00000001&((data)<<0))
#define SCPU_A12_BIST_DONE3_BIST_DONE3_scu_src(data)                                 ((0x00000001&(data))>>0)
#define SCPU_A12_BIST_DONE3_get_BIST_DONE3_scu(data)                                 ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BIST_MODE1                                                      0x1805C52c
#define SCPU_A12_DRF_BIST_MODE1_reg_addr                                             "0xB805C52C"
#define SCPU_A12_DRF_BIST_MODE1_reg                                                  0xB805C52C
#define set_SCPU_A12_DRF_BIST_MODE1_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_MODE1_reg)=data)
#define get_SCPU_A12_DRF_BIST_MODE1_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_MODE1_reg))
#define SCPU_A12_DRF_BIST_MODE1_inst_adr                                             "0x004B"
#define SCPU_A12_DRF_BIST_MODE1_inst                                                 0x004B
#define SCPU_A12_DRF_BIST_MODE1_DRF_BIST_MODE1_shift                                 (0)
#define SCPU_A12_DRF_BIST_MODE1_DRF_BIST_MODE1_mask                                  (0x00000001)
#define SCPU_A12_DRF_BIST_MODE1_DRF_BIST_MODE1(data)                                 (0x00000001&((data)<<0))
#define SCPU_A12_DRF_BIST_MODE1_DRF_BIST_MODE1_src(data)                             ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_BIST_MODE1_get_DRF_BIST_MODE1(data)                             ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BIST_MODE2                                                      0x1805C530
#define SCPU_A12_DRF_BIST_MODE2_reg_addr                                             "0xB805C530"
#define SCPU_A12_DRF_BIST_MODE2_reg                                                  0xB805C530
#define set_SCPU_A12_DRF_BIST_MODE2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_MODE2_reg)=data)
#define get_SCPU_A12_DRF_BIST_MODE2_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_MODE2_reg))
#define SCPU_A12_DRF_BIST_MODE2_inst_adr                                             "0x004C"
#define SCPU_A12_DRF_BIST_MODE2_inst                                                 0x004C
#define SCPU_A12_DRF_BIST_MODE2_DRF_BIST_MODE2_shift                                 (0)
#define SCPU_A12_DRF_BIST_MODE2_DRF_BIST_MODE2_mask                                  (0x00000001)
#define SCPU_A12_DRF_BIST_MODE2_DRF_BIST_MODE2(data)                                 (0x00000001&((data)<<0))
#define SCPU_A12_DRF_BIST_MODE2_DRF_BIST_MODE2_src(data)                             ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_BIST_MODE2_get_DRF_BIST_MODE2(data)                             ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BIST_MODE3                                                      0x1805C534
#define SCPU_A12_DRF_BIST_MODE3_reg_addr                                             "0xB805C534"
#define SCPU_A12_DRF_BIST_MODE3_reg                                                  0xB805C534
#define set_SCPU_A12_DRF_BIST_MODE3_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_MODE3_reg)=data)
#define get_SCPU_A12_DRF_BIST_MODE3_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_MODE3_reg))
#define SCPU_A12_DRF_BIST_MODE3_inst_adr                                             "0x004D"
#define SCPU_A12_DRF_BIST_MODE3_inst                                                 0x004D
#define SCPU_A12_DRF_BIST_MODE3_DRF_BIST_MODE3_shift                                 (0)
#define SCPU_A12_DRF_BIST_MODE3_DRF_BIST_MODE3_mask                                  (0x00000001)
#define SCPU_A12_DRF_BIST_MODE3_DRF_BIST_MODE3(data)                                 (0x00000001&((data)<<0))
#define SCPU_A12_DRF_BIST_MODE3_DRF_BIST_MODE3_src(data)                             ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_BIST_MODE3_get_DRF_BIST_MODE3(data)                             ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_TETS_RESUME1                                                    0x1805C538
#define SCPU_A12_DRF_TETS_RESUME1_reg_addr                                           "0xB805C538"
#define SCPU_A12_DRF_TETS_RESUME1_reg                                                0xB805C538
#define set_SCPU_A12_DRF_TETS_RESUME1_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_TETS_RESUME1_reg)=data)
#define get_SCPU_A12_DRF_TETS_RESUME1_reg   (*((volatile unsigned int*) SCPU_A12_DRF_TETS_RESUME1_reg))
#define SCPU_A12_DRF_TETS_RESUME1_inst_adr                                           "0x004E"
#define SCPU_A12_DRF_TETS_RESUME1_inst                                               0x004E
#define SCPU_A12_DRF_TETS_RESUME1_DRF_TEST_RESUME1_shift                             (0)
#define SCPU_A12_DRF_TETS_RESUME1_DRF_TEST_RESUME1_mask                              (0x00000001)
#define SCPU_A12_DRF_TETS_RESUME1_DRF_TEST_RESUME1(data)                             (0x00000001&((data)<<0))
#define SCPU_A12_DRF_TETS_RESUME1_DRF_TEST_RESUME1_src(data)                         ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_TETS_RESUME1_get_DRF_TEST_RESUME1(data)                         ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_TETS_RESUME2                                                    0x1805C53c
#define SCPU_A12_DRF_TETS_RESUME2_reg_addr                                           "0xB805C53C"
#define SCPU_A12_DRF_TETS_RESUME2_reg                                                0xB805C53C
#define set_SCPU_A12_DRF_TETS_RESUME2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_TETS_RESUME2_reg)=data)
#define get_SCPU_A12_DRF_TETS_RESUME2_reg   (*((volatile unsigned int*) SCPU_A12_DRF_TETS_RESUME2_reg))
#define SCPU_A12_DRF_TETS_RESUME2_inst_adr                                           "0x004F"
#define SCPU_A12_DRF_TETS_RESUME2_inst                                               0x004F
#define SCPU_A12_DRF_TETS_RESUME2_DRF_TEST_RESUME2_shift                             (0)
#define SCPU_A12_DRF_TETS_RESUME2_DRF_TEST_RESUME2_mask                              (0x00000001)
#define SCPU_A12_DRF_TETS_RESUME2_DRF_TEST_RESUME2(data)                             (0x00000001&((data)<<0))
#define SCPU_A12_DRF_TETS_RESUME2_DRF_TEST_RESUME2_src(data)                         ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_TETS_RESUME2_get_DRF_TEST_RESUME2(data)                         ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_TETS_RESUME3                                                    0x1805C540
#define SCPU_A12_DRF_TETS_RESUME3_reg_addr                                           "0xB805C540"
#define SCPU_A12_DRF_TETS_RESUME3_reg                                                0xB805C540
#define set_SCPU_A12_DRF_TETS_RESUME3_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_TETS_RESUME3_reg)=data)
#define get_SCPU_A12_DRF_TETS_RESUME3_reg   (*((volatile unsigned int*) SCPU_A12_DRF_TETS_RESUME3_reg))
#define SCPU_A12_DRF_TETS_RESUME3_inst_adr                                           "0x0050"
#define SCPU_A12_DRF_TETS_RESUME3_inst                                               0x0050
#define SCPU_A12_DRF_TETS_RESUME3_DRF_TEST_RESUME3_shift                             (0)
#define SCPU_A12_DRF_TETS_RESUME3_DRF_TEST_RESUME3_mask                              (0x00000001)
#define SCPU_A12_DRF_TETS_RESUME3_DRF_TEST_RESUME3(data)                             (0x00000001&((data)<<0))
#define SCPU_A12_DRF_TETS_RESUME3_DRF_TEST_RESUME3_src(data)                         ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_TETS_RESUME3_get_DRF_TEST_RESUME3(data)                         ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_START_PAUSE1                                                    0x1805C544
#define SCPU_A12_DRF_START_PAUSE1_reg_addr                                           "0xB805C544"
#define SCPU_A12_DRF_START_PAUSE1_reg                                                0xB805C544
#define set_SCPU_A12_DRF_START_PAUSE1_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_START_PAUSE1_reg)=data)
#define get_SCPU_A12_DRF_START_PAUSE1_reg   (*((volatile unsigned int*) SCPU_A12_DRF_START_PAUSE1_reg))
#define SCPU_A12_DRF_START_PAUSE1_inst_adr                                           "0x0051"
#define SCPU_A12_DRF_START_PAUSE1_inst                                               0x0051
#define SCPU_A12_DRF_START_PAUSE1_DRF_START_PAUSE1_shift                             (0)
#define SCPU_A12_DRF_START_PAUSE1_DRF_START_PAUSE1_mask                              (0x00000001)
#define SCPU_A12_DRF_START_PAUSE1_DRF_START_PAUSE1(data)                             (0x00000001&((data)<<0))
#define SCPU_A12_DRF_START_PAUSE1_DRF_START_PAUSE1_src(data)                         ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_START_PAUSE1_get_DRF_START_PAUSE1(data)                         ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_START_PAUSE2                                                    0x1805C548
#define SCPU_A12_DRF_START_PAUSE2_reg_addr                                           "0xB805C548"
#define SCPU_A12_DRF_START_PAUSE2_reg                                                0xB805C548
#define set_SCPU_A12_DRF_START_PAUSE2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_START_PAUSE2_reg)=data)
#define get_SCPU_A12_DRF_START_PAUSE2_reg   (*((volatile unsigned int*) SCPU_A12_DRF_START_PAUSE2_reg))
#define SCPU_A12_DRF_START_PAUSE2_inst_adr                                           "0x0052"
#define SCPU_A12_DRF_START_PAUSE2_inst                                               0x0052
#define SCPU_A12_DRF_START_PAUSE2_DRF_START_PAUSE2_shift                             (0)
#define SCPU_A12_DRF_START_PAUSE2_DRF_START_PAUSE2_mask                              (0x00000001)
#define SCPU_A12_DRF_START_PAUSE2_DRF_START_PAUSE2(data)                             (0x00000001&((data)<<0))
#define SCPU_A12_DRF_START_PAUSE2_DRF_START_PAUSE2_src(data)                         ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_START_PAUSE2_get_DRF_START_PAUSE2(data)                         ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_START_PAUSE3                                                    0x1805C54C
#define SCPU_A12_DRF_START_PAUSE3_reg_addr                                           "0xB805C54C"
#define SCPU_A12_DRF_START_PAUSE3_reg                                                0xB805C54C
#define set_SCPU_A12_DRF_START_PAUSE3_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_START_PAUSE3_reg)=data)
#define get_SCPU_A12_DRF_START_PAUSE3_reg   (*((volatile unsigned int*) SCPU_A12_DRF_START_PAUSE3_reg))
#define SCPU_A12_DRF_START_PAUSE3_inst_adr                                           "0x0053"
#define SCPU_A12_DRF_START_PAUSE3_inst                                               0x0053
#define SCPU_A12_DRF_START_PAUSE3_DRF_START_PAUSE3_shift                             (0)
#define SCPU_A12_DRF_START_PAUSE3_DRF_START_PAUSE3_mask                              (0x00000001)
#define SCPU_A12_DRF_START_PAUSE3_DRF_START_PAUSE3(data)                             (0x00000001&((data)<<0))
#define SCPU_A12_DRF_START_PAUSE3_DRF_START_PAUSE3_src(data)                         ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_START_PAUSE3_get_DRF_START_PAUSE3(data)                         ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BIST_DONE1                                                      0x1805C554
#define SCPU_A12_DRF_BIST_DONE1_reg_addr                                             "0xB805C554"
#define SCPU_A12_DRF_BIST_DONE1_reg                                                  0xB805C554
#define set_SCPU_A12_DRF_BIST_DONE1_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_DONE1_reg)=data)
#define get_SCPU_A12_DRF_BIST_DONE1_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_DONE1_reg))
#define SCPU_A12_DRF_BIST_DONE1_inst_adr                                             "0x0055"
#define SCPU_A12_DRF_BIST_DONE1_inst                                                 0x0055
#define SCPU_A12_DRF_BIST_DONE1_DRF_BIST_DONE1_shift                                 (0)
#define SCPU_A12_DRF_BIST_DONE1_DRF_BIST_DONE1_mask                                  (0x00000001)
#define SCPU_A12_DRF_BIST_DONE1_DRF_BIST_DONE1(data)                                 (0x00000001&((data)<<0))
#define SCPU_A12_DRF_BIST_DONE1_DRF_BIST_DONE1_src(data)                             ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_BIST_DONE1_get_DRF_BIST_DONE1(data)                             ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BIST_DONE2                                                      0x1805C558
#define SCPU_A12_DRF_BIST_DONE2_reg_addr                                             "0xB805C558"
#define SCPU_A12_DRF_BIST_DONE2_reg                                                  0xB805C558
#define set_SCPU_A12_DRF_BIST_DONE2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_DONE2_reg)=data)
#define get_SCPU_A12_DRF_BIST_DONE2_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_DONE2_reg))
#define SCPU_A12_DRF_BIST_DONE2_inst_adr                                             "0x0056"
#define SCPU_A12_DRF_BIST_DONE2_inst                                                 0x0056
#define SCPU_A12_DRF_BIST_DONE2_DRF_BIST_DONE2_shift                                 (0)
#define SCPU_A12_DRF_BIST_DONE2_DRF_BIST_DONE2_mask                                  (0x00000001)
#define SCPU_A12_DRF_BIST_DONE2_DRF_BIST_DONE2(data)                                 (0x00000001&((data)<<0))
#define SCPU_A12_DRF_BIST_DONE2_DRF_BIST_DONE2_src(data)                             ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_BIST_DONE2_get_DRF_BIST_DONE2(data)                             ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BIST_DONE3                                                      0x1805C55C
#define SCPU_A12_DRF_BIST_DONE3_reg_addr                                             "0xB805C55C"
#define SCPU_A12_DRF_BIST_DONE3_reg                                                  0xB805C55C
#define set_SCPU_A12_DRF_BIST_DONE3_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_DONE3_reg)=data)
#define get_SCPU_A12_DRF_BIST_DONE3_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BIST_DONE3_reg))
#define SCPU_A12_DRF_BIST_DONE3_inst_adr                                             "0x0057"
#define SCPU_A12_DRF_BIST_DONE3_inst                                                 0x0057
#define SCPU_A12_DRF_BIST_DONE3_DRF_BIST_DONE3_shift                                 (0)
#define SCPU_A12_DRF_BIST_DONE3_DRF_BIST_DONE3_mask                                  (0x00000001)
#define SCPU_A12_DRF_BIST_DONE3_DRF_BIST_DONE3(data)                                 (0x00000001&((data)<<0))
#define SCPU_A12_DRF_BIST_DONE3_DRF_BIST_DONE3_src(data)                             ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_BIST_DONE3_get_DRF_BIST_DONE3(data)                             ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BISR_MODE2                                                      0x1805C560
#define SCPU_A12_DRF_BISR_MODE2_reg_addr                                             "0xB805C560"
#define SCPU_A12_DRF_BISR_MODE2_reg                                                  0xB805C560
#define set_SCPU_A12_DRF_BISR_MODE2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BISR_MODE2_reg)=data)
#define get_SCPU_A12_DRF_BISR_MODE2_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BISR_MODE2_reg))
#define SCPU_A12_DRF_BISR_MODE2_inst_adr                                             "0x0058"
#define SCPU_A12_DRF_BISR_MODE2_inst                                                 0x0058
#define SCPU_A12_DRF_BISR_MODE2_DRF_BISR_MODE2_shift                                 (0)
#define SCPU_A12_DRF_BISR_MODE2_DRF_BISR_MODE2_mask                                  (0x00000001)
#define SCPU_A12_DRF_BISR_MODE2_DRF_BISR_MODE2(data)                                 (0x00000001&((data)<<0))
#define SCPU_A12_DRF_BISR_MODE2_DRF_BISR_MODE2_src(data)                             ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_BISR_MODE2_get_DRF_BISR_MODE2(data)                             ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BISR_TETS_RESUME2                                               0x1805C564
#define SCPU_A12_DRF_BISR_TETS_RESUME2_reg_addr                                      "0xB805C564"
#define SCPU_A12_DRF_BISR_TETS_RESUME2_reg                                           0xB805C564
#define set_SCPU_A12_DRF_BISR_TETS_RESUME2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BISR_TETS_RESUME2_reg)=data)
#define get_SCPU_A12_DRF_BISR_TETS_RESUME2_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BISR_TETS_RESUME2_reg))
#define SCPU_A12_DRF_BISR_TETS_RESUME2_inst_adr                                      "0x0059"
#define SCPU_A12_DRF_BISR_TETS_RESUME2_inst                                          0x0059
#define SCPU_A12_DRF_BISR_TETS_RESUME2_DRF_BISR_TEST_RESUME2_shift                   (0)
#define SCPU_A12_DRF_BISR_TETS_RESUME2_DRF_BISR_TEST_RESUME2_mask                    (0x00000001)
#define SCPU_A12_DRF_BISR_TETS_RESUME2_DRF_BISR_TEST_RESUME2(data)                   (0x00000001&((data)<<0))
#define SCPU_A12_DRF_BISR_TETS_RESUME2_DRF_BISR_TEST_RESUME2_src(data)               ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_BISR_TETS_RESUME2_get_DRF_BISR_TEST_RESUME2(data)               ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BISR_START_PAUSE2                                               0x1805C568
#define SCPU_A12_DRF_BISR_START_PAUSE2_reg_addr                                      "0xB805C568"
#define SCPU_A12_DRF_BISR_START_PAUSE2_reg                                           0xB805C568
#define set_SCPU_A12_DRF_BISR_START_PAUSE2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BISR_START_PAUSE2_reg)=data)
#define get_SCPU_A12_DRF_BISR_START_PAUSE2_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BISR_START_PAUSE2_reg))
#define SCPU_A12_DRF_BISR_START_PAUSE2_inst_adr                                      "0x005A"
#define SCPU_A12_DRF_BISR_START_PAUSE2_inst                                          0x005A
#define SCPU_A12_DRF_BISR_START_PAUSE2_DRF_BISR_START_PAUSE2_shift                   (0)
#define SCPU_A12_DRF_BISR_START_PAUSE2_DRF_BISR_START_PAUSE2_mask                    (0x00000001)
#define SCPU_A12_DRF_BISR_START_PAUSE2_DRF_BISR_START_PAUSE2(data)                   (0x00000001&((data)<<0))
#define SCPU_A12_DRF_BISR_START_PAUSE2_DRF_BISR_START_PAUSE2_src(data)               ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_BISR_START_PAUSE2_get_DRF_BISR_START_PAUSE2(data)               ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BISR_DONE2                                                      0x1805C56C
#define SCPU_A12_DRF_BISR_DONE2_reg_addr                                             "0xB805C56C"
#define SCPU_A12_DRF_BISR_DONE2_reg                                                  0xB805C56C
#define set_SCPU_A12_DRF_BISR_DONE2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BISR_DONE2_reg)=data)
#define get_SCPU_A12_DRF_BISR_DONE2_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BISR_DONE2_reg))
#define SCPU_A12_DRF_BISR_DONE2_inst_adr                                             "0x005B"
#define SCPU_A12_DRF_BISR_DONE2_inst                                                 0x005B
#define SCPU_A12_DRF_BISR_DONE2_DRF_BISR_DONE2_shift                                 (0)
#define SCPU_A12_DRF_BISR_DONE2_DRF_BISR_DONE2_mask                                  (0x00000001)
#define SCPU_A12_DRF_BISR_DONE2_DRF_BISR_DONE2(data)                                 (0x00000001&((data)<<0))
#define SCPU_A12_DRF_BISR_DONE2_DRF_BISR_DONE2_src(data)                             ((0x00000001&(data))>>0)
#define SCPU_A12_DRF_BISR_DONE2_get_DRF_BISR_DONE2(data)                             ((0x00000001&(data))>>0)


#define SCPU_A12_DRF_BISR_DONE2                                                      0x1805C570
#define SCPU_A12_DRF_BISR_DONE2_reg_addr                                             "0xB805C570"
#define SCPU_A12_DRF_BISR_DONE2_reg                                                  0xB805C570
#define set_SCPU_A12_DRF_BISR_DONE2_reg(data)   (*((volatile unsigned int*) SCPU_A12_DRF_BISR_DONE2_reg)=data)
#define get_SCPU_A12_DRF_BISR_DONE2_reg   (*((volatile unsigned int*) SCPU_A12_DRF_BISR_DONE2_reg))
#define SCPU_A12_DRF_BISR_DONE2_inst_adr                                             "0x005C"
#define SCPU_A12_DRF_BISR_DONE2_inst                                                 0x005C
#define SCPU_A12_DRF_BISR_DONE2_DRF_BISR_FAIL2_shift                                 (0)
#define SCPU_A12_DRF_BISR_DONE2_DRF_BISR_FAIL2_mask                                  (0x000000FF)
#define SCPU_A12_DRF_BISR_DONE2_DRF_BISR_FAIL2(data)                                 (0x000000FF&((data)<<0))
#define SCPU_A12_DRF_BISR_DONE2_DRF_BISR_FAIL2_src(data)                             ((0x000000FF&(data))>>0)
#define SCPU_A12_DRF_BISR_DONE2_get_DRF_BISR_FAIL2(data)                             ((0x000000FF&(data))>>0)


#define SCPU_A12_CPU0_BIST_FAIL1                                                     0x1805C574
#define SCPU_A12_CPU0_BIST_FAIL1_reg_addr                                            "0xB805C574"
#define SCPU_A12_CPU0_BIST_FAIL1_reg                                                 0xB805C574
#define set_SCPU_A12_CPU0_BIST_FAIL1_reg(data)   (*((volatile unsigned int*) SCPU_A12_CPU0_BIST_FAIL1_reg)=data)
#define get_SCPU_A12_CPU0_BIST_FAIL1_reg   (*((volatile unsigned int*) SCPU_A12_CPU0_BIST_FAIL1_reg))
#define SCPU_A12_CPU0_BIST_FAIL1_inst_adr                                            "0x005D"
#define SCPU_A12_CPU0_BIST_FAIL1_inst                                                0x005D
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_btac_ctrl_shift                     (30)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_btac_ctrl_mask                      (0xC0000000)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_btac_ctrl(data)                     (0xC0000000&((data)<<30))
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_btac_ctrl_src(data)                 ((0xC0000000&(data))>>30)
#define SCPU_A12_CPU0_BIST_FAIL1_get_cpu0_BIST_FAIL1_btac_ctrl(data)                 ((0xC0000000&(data))>>30)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_btac_tag_shift                      (28)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_btac_tag_mask                       (0x30000000)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_btac_tag(data)                      (0x30000000&((data)<<28))
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_btac_tag_src(data)                  ((0x30000000&(data))>>28)
#define SCPU_A12_CPU0_BIST_FAIL1_get_cpu0_BIST_FAIL1_btac_tag(data)                  ((0x30000000&(data))>>28)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_dtag1_shift                         (24)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_dtag1_mask                          (0x0F000000)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_dtag1(data)                         (0x0F000000&((data)<<24))
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_dtag1_src(data)                     ((0x0F000000&(data))>>24)
#define SCPU_A12_CPU0_BIST_FAIL1_get_cpu0_BIST_FAIL1_dtag1(data)                     ((0x0F000000&(data))>>24)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_dtag0_shift                         (20)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_dtag0_mask                          (0x00F00000)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_dtag0(data)                         (0x00F00000&((data)<<20))
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_dtag0_src(data)                     ((0x00F00000&(data))>>20)
#define SCPU_A12_CPU0_BIST_FAIL1_get_cpu0_BIST_FAIL1_dtag0(data)                     ((0x00F00000&(data))>>20)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_ddata_shift                         (12)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_ddata_mask                          (0x000FF000)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_ddata(data)                         (0x000FF000&((data)<<12))
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_ddata_src(data)                     ((0x000FF000&(data))>>12)
#define SCPU_A12_CPU0_BIST_FAIL1_get_cpu0_BIST_FAIL1_ddata(data)                     ((0x000FF000&(data))>>12)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_itag_shift                          (8)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_itag_mask                           (0x00000F00)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_itag(data)                          (0x00000F00&((data)<<8))
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_itag_src(data)                      ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_BIST_FAIL1_get_cpu0_BIST_FAIL1_itag(data)                      ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_idata_shift                         (0)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_idata_mask                          (0x000000FF)
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_idata(data)                         (0x000000FF&((data)<<0))
#define SCPU_A12_CPU0_BIST_FAIL1_cpu0_BIST_FAIL1_idata_src(data)                     ((0x000000FF&(data))>>0)
#define SCPU_A12_CPU0_BIST_FAIL1_get_cpu0_BIST_FAIL1_idata(data)                     ((0x000000FF&(data))>>0)


#define SCPU_A12_CPU0_BIST_FAIL1_2                                                   0x1805C578
#define SCPU_A12_CPU0_BIST_FAIL1_2_reg_addr                                          "0xB805C578"
#define SCPU_A12_CPU0_BIST_FAIL1_2_reg                                               0xB805C578
#define set_SCPU_A12_CPU0_BIST_FAIL1_2_reg(data)   (*((volatile unsigned int*) SCPU_A12_CPU0_BIST_FAIL1_2_reg)=data)
#define get_SCPU_A12_CPU0_BIST_FAIL1_2_reg   (*((volatile unsigned int*) SCPU_A12_CPU0_BIST_FAIL1_2_reg))
#define SCPU_A12_CPU0_BIST_FAIL1_2_inst_adr                                          "0x005E"
#define SCPU_A12_CPU0_BIST_FAIL1_2_inst                                              0x005E
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_tlb_buf_shift                     (16)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_tlb_buf_mask                      (0x00030000)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_tlb_buf(data)                     (0x00030000&((data)<<16))
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_tlb_buf_src(data)                 ((0x00030000&(data))>>16)
#define SCPU_A12_CPU0_BIST_FAIL1_2_get_cpu0_BIST_FAIL1_tlb_buf(data)                 ((0x00030000&(data))>>16)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_tlb_ram_shift                     (12)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_tlb_ram_mask                      (0x0000F000)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_tlb_ram(data)                     (0x0000F000&((data)<<12))
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_tlb_ram_src(data)                 ((0x0000F000&(data))>>12)
#define SCPU_A12_CPU0_BIST_FAIL1_2_get_cpu0_BIST_FAIL1_tlb_ram(data)                 ((0x0000F000&(data))>>12)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_pred_8bit_shift                   (8)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_pred_8bit_mask                    (0x00000F00)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_pred_8bit(data)                   (0x00000F00&((data)<<8))
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_pred_8bit_src(data)               ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_BIST_FAIL1_2_get_cpu0_BIST_FAIL1_pred_8bit(data)               ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_pred_4bit_shift                   (0)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_pred_4bit_mask                    (0x000000FF)
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_pred_4bit(data)                   (0x000000FF&((data)<<0))
#define SCPU_A12_CPU0_BIST_FAIL1_2_cpu0_BIST_FAIL1_pred_4bit_src(data)               ((0x000000FF&(data))>>0)
#define SCPU_A12_CPU0_BIST_FAIL1_2_get_cpu0_BIST_FAIL1_pred_4bit(data)               ((0x000000FF&(data))>>0)


#define SCPU_A12_CPU0_BIST_FAIL2                                                     0x1805C57C
#define SCPU_A12_CPU0_BIST_FAIL2_reg_addr                                            "0xB805C57C"
#define SCPU_A12_CPU0_BIST_FAIL2_reg                                                 0xB805C57C
#define set_SCPU_A12_CPU0_BIST_FAIL2_reg(data)   (*((volatile unsigned int*) SCPU_A12_CPU0_BIST_FAIL2_reg)=data)
#define get_SCPU_A12_CPU0_BIST_FAIL2_reg   (*((volatile unsigned int*) SCPU_A12_CPU0_BIST_FAIL2_reg))
#define SCPU_A12_CPU0_BIST_FAIL2_inst_adr                                            "0x005F"
#define SCPU_A12_CPU0_BIST_FAIL2_inst                                                0x005F
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_linefill_buf_shift                  (8)
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_linefill_buf_mask                   (0x00000F00)
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_linefill_buf(data)                  (0x00000F00&((data)<<8))
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_linefill_buf_src(data)              ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_BIST_FAIL2_get_cpu0_BIST_FAIL2_linefill_buf(data)              ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_eviction_buf_shift                  (4)
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_eviction_buf_mask                   (0x000000F0)
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_eviction_buf(data)                  (0x000000F0&((data)<<4))
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_eviction_buf_src(data)              ((0x000000F0&(data))>>4)
#define SCPU_A12_CPU0_BIST_FAIL2_get_cpu0_BIST_FAIL2_eviction_buf(data)              ((0x000000F0&(data))>>4)
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_store_buf_shift                     (0)
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_store_buf_mask                      (0x0000000F)
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_store_buf(data)                     (0x0000000F&((data)<<0))
#define SCPU_A12_CPU0_BIST_FAIL2_cpu0_BIST_FAIL2_store_buf_src(data)                 ((0x0000000F&(data))>>0)
#define SCPU_A12_CPU0_BIST_FAIL2_get_cpu0_BIST_FAIL2_store_buf(data)                 ((0x0000000F&(data))>>0)


#define SCPU_A12_CPU0_BIST_FAIL3                                                     0x1805C580
#define SCPU_A12_CPU0_BIST_FAIL3_reg_addr                                            "0xB805C580"
#define SCPU_A12_CPU0_BIST_FAIL3_reg                                                 0xB805C580
#define set_SCPU_A12_CPU0_BIST_FAIL3_reg(data)   (*((volatile unsigned int*) SCPU_A12_CPU0_BIST_FAIL3_reg)=data)
#define get_SCPU_A12_CPU0_BIST_FAIL3_reg   (*((volatile unsigned int*) SCPU_A12_CPU0_BIST_FAIL3_reg))
#define SCPU_A12_CPU0_BIST_FAIL3_inst_adr                                            "0x0060"
#define SCPU_A12_CPU0_BIST_FAIL3_inst                                                0x0060
#define SCPU_A12_CPU0_BIST_FAIL3_cpu0_BIST_FAIL3_l2tag_shift                         (4)
#define SCPU_A12_CPU0_BIST_FAIL3_cpu0_BIST_FAIL3_l2tag_mask                          (0x000FFFF0)
#define SCPU_A12_CPU0_BIST_FAIL3_cpu0_BIST_FAIL3_l2tag(data)                         (0x000FFFF0&((data)<<4))
#define SCPU_A12_CPU0_BIST_FAIL3_cpu0_BIST_FAIL3_l2tag_src(data)                     ((0x000FFFF0&(data))>>4)
#define SCPU_A12_CPU0_BIST_FAIL3_get_cpu0_BIST_FAIL3_l2tag(data)                     ((0x000FFFF0&(data))>>4)
#define SCPU_A12_CPU0_BIST_FAIL3_cpu0_BIST_FAIL3_scu_shift                           (0)
#define SCPU_A12_CPU0_BIST_FAIL3_cpu0_BIST_FAIL3_scu_mask                            (0x0000000F)
#define SCPU_A12_CPU0_BIST_FAIL3_cpu0_BIST_FAIL3_scu(data)                           (0x0000000F&((data)<<0))
#define SCPU_A12_CPU0_BIST_FAIL3_cpu0_BIST_FAIL3_scu_src(data)                       ((0x0000000F&(data))>>0)
#define SCPU_A12_CPU0_BIST_FAIL3_get_cpu0_BIST_FAIL3_scu(data)                       ((0x0000000F&(data))>>0)


#define SCPU_A12_CPU0_DRF_BIST_FAIL1                                                 0x1805C584
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_reg_addr                                        "0xB805C584"
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_reg                                             0xB805C584
#define set_SCPU_A12_CPU0_DRF_BIST_FAIL1_reg(data)   (*((volatile unsigned int*) SCPU_A12_CPU0_DRF_BIST_FAIL1_reg)=data)
#define get_SCPU_A12_CPU0_DRF_BIST_FAIL1_reg   (*((volatile unsigned int*) SCPU_A12_CPU0_DRF_BIST_FAIL1_reg))
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_inst_adr                                        "0x0061"
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_inst                                            0x0061
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_btac_ctrl_shift             (30)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_btac_ctrl_mask              (0xC0000000)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_btac_ctrl(data)             (0xC0000000&((data)<<30))
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_btac_ctrl_src(data)         ((0xC0000000&(data))>>30)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_get_cpu0_DRF_BIST_FAIL1_btac_ctrl(data)         ((0xC0000000&(data))>>30)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_btac_tag_shift              (28)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_btac_tag_mask               (0x30000000)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_btac_tag(data)              (0x30000000&((data)<<28))
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_btac_tag_src(data)          ((0x30000000&(data))>>28)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_get_cpu0_DRF_BIST_FAIL1_btac_tag(data)          ((0x30000000&(data))>>28)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_dtag1_shift                 (24)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_dtag1_mask                  (0x0F000000)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_dtag1(data)                 (0x0F000000&((data)<<24))
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_dtag1_src(data)             ((0x0F000000&(data))>>24)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_get_cpu0_DRF_BIST_FAIL1_dtag1(data)             ((0x0F000000&(data))>>24)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_dtag0_shift                 (20)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_dtag0_mask                  (0x00F00000)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_dtag0(data)                 (0x00F00000&((data)<<20))
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_dtag0_src(data)             ((0x00F00000&(data))>>20)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_get_cpu0_DRF_BIST_FAIL1_dtag0(data)             ((0x00F00000&(data))>>20)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_ddata_shift                 (12)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_ddata_mask                  (0x000FF000)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_ddata(data)                 (0x000FF000&((data)<<12))
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_ddata_src(data)             ((0x000FF000&(data))>>12)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_get_cpu0_DRF_BIST_FAIL1_ddata(data)             ((0x000FF000&(data))>>12)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_itag_shift                  (8)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_itag_mask                   (0x00000F00)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_itag(data)                  (0x00000F00&((data)<<8))
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_itag_src(data)              ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_get_cpu0_DRF_BIST_FAIL1_itag(data)              ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_idata_shift                 (0)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_idata_mask                  (0x000000FF)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_idata(data)                 (0x000000FF&((data)<<0))
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_cpu0_DRF_BIST_FAIL1_idata_src(data)             ((0x000000FF&(data))>>0)
#define SCPU_A12_CPU0_DRF_BIST_FAIL1_get_cpu0_DRF_BIST_FAIL1_idata(data)             ((0x000000FF&(data))>>0)


#define SCPU_A12_CPU0_DRF_BIST_FAIL12                                                0x1805C588
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_reg_addr                                       "0xB805C588"
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_reg                                            0xB805C588
#define set_SCPU_A12_CPU0_DRF_BIST_FAIL12_reg(data)   (*((volatile unsigned int*) SCPU_A12_CPU0_DRF_BIST_FAIL12_reg)=data)
#define get_SCPU_A12_CPU0_DRF_BIST_FAIL12_reg   (*((volatile unsigned int*) SCPU_A12_CPU0_DRF_BIST_FAIL12_reg))
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_inst_adr                                       "0x0062"
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_inst                                           0x0062
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_tlb_buf_shift              (16)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_tlb_buf_mask               (0x00030000)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_tlb_buf(data)              (0x00030000&((data)<<16))
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_tlb_buf_src(data)          ((0x00030000&(data))>>16)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_get_cpu0_DRF_BIST_FAIL1_tlb_buf(data)          ((0x00030000&(data))>>16)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_tlb_ram_shift              (12)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_tlb_ram_mask               (0x0000F000)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_tlb_ram(data)              (0x0000F000&((data)<<12))
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_tlb_ram_src(data)          ((0x0000F000&(data))>>12)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_get_cpu0_DRF_BIST_FAIL1_tlb_ram(data)          ((0x0000F000&(data))>>12)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_pred_8bit_shift            (8)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_pred_8bit_mask             (0x00000F00)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_pred_8bit(data)            (0x00000F00&((data)<<8))
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_pred_8bit_src(data)        ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_get_cpu0_DRF_BIST_FAIL1_pred_8bit(data)        ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_pred_4bit_shift            (0)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_pred_4bit_mask             (0x000000FF)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_pred_4bit(data)            (0x000000FF&((data)<<0))
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_cpu0_DRF_BIST_FAIL1_pred_4bit_src(data)        ((0x000000FF&(data))>>0)
#define SCPU_A12_CPU0_DRF_BIST_FAIL12_get_cpu0_DRF_BIST_FAIL1_pred_4bit(data)        ((0x000000FF&(data))>>0)


#define SCPU_A12_CPU0_DRF_BIST_FAIL2                                                 0x1805C58C
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_reg_addr                                        "0xB805C58C"
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_reg                                             0xB805C58C
#define set_SCPU_A12_CPU0_DRF_BIST_FAIL2_reg(data)   (*((volatile unsigned int*) SCPU_A12_CPU0_DRF_BIST_FAIL2_reg)=data)
#define get_SCPU_A12_CPU0_DRF_BIST_FAIL2_reg   (*((volatile unsigned int*) SCPU_A12_CPU0_DRF_BIST_FAIL2_reg))
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_inst_adr                                        "0x0063"
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_inst                                            0x0063
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_linefill_buf_shift          (8)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_linefill_buf_mask           (0x00000F00)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_linefill_buf(data)          (0x00000F00&((data)<<8))
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_linefill_buf_src(data)      ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_get_cpu0_DRF_BIST_FAIL2_linefill_buf(data)      ((0x00000F00&(data))>>8)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_eviction_buf_shift          (4)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_eviction_buf_mask           (0x000000F0)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_eviction_buf(data)          (0x000000F0&((data)<<4))
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_eviction_buf_src(data)      ((0x000000F0&(data))>>4)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_get_cpu0_DRF_BIST_FAIL2_eviction_buf(data)      ((0x000000F0&(data))>>4)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_store_buf_shift             (0)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_store_buf_mask              (0x0000000F)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_store_buf(data)             (0x0000000F&((data)<<0))
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_cpu0_DRF_BIST_FAIL2_store_buf_src(data)         ((0x0000000F&(data))>>0)
#define SCPU_A12_CPU0_DRF_BIST_FAIL2_get_cpu0_DRF_BIST_FAIL2_store_buf(data)         ((0x0000000F&(data))>>0)


#define SCPU_A12_CPU0_DRF_BIST_FAIL3                                                 0x1805C590
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_reg_addr                                        "0xB805C590"
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_reg                                             0xB805C590
#define set_SCPU_A12_CPU0_DRF_BIST_FAIL3_reg(data)   (*((volatile unsigned int*) SCPU_A12_CPU0_DRF_BIST_FAIL3_reg)=data)
#define get_SCPU_A12_CPU0_DRF_BIST_FAIL3_reg   (*((volatile unsigned int*) SCPU_A12_CPU0_DRF_BIST_FAIL3_reg))
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_inst_adr                                        "0x0064"
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_inst                                            0x0064
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_cpu0_DRF_BIST_FAIL3_l2tag_shift                 (4)
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_cpu0_DRF_BIST_FAIL3_l2tag_mask                  (0x000FFFF0)
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_cpu0_DRF_BIST_FAIL3_l2tag(data)                 (0x000FFFF0&((data)<<4))
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_cpu0_DRF_BIST_FAIL3_l2tag_src(data)             ((0x000FFFF0&(data))>>4)
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_get_cpu0_DRF_BIST_FAIL3_l2tag(data)             ((0x000FFFF0&(data))>>4)
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_cpu0_DRF_BIST_FAIL3_scu_shift                   (0)
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_cpu0_DRF_BIST_FAIL3_scu_mask                    (0x0000000F)
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_cpu0_DRF_BIST_FAIL3_scu(data)                   (0x0000000F&((data)<<0))
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_cpu0_DRF_BIST_FAIL3_scu_src(data)               ((0x0000000F&(data))>>0)
#define SCPU_A12_CPU0_DRF_BIST_FAIL3_get_cpu0_DRF_BIST_FAIL3_scu(data)               ((0x0000000F&(data))>>0)


#define SCPU_A12_BISR_RSTN                                                           0x1805C594
#define SCPU_A12_BISR_RSTN_reg_addr                                                  "0xB805C594"
#define SCPU_A12_BISR_RSTN_reg                                                       0xB805C594
#define set_SCPU_A12_BISR_RSTN_reg(data)   (*((volatile unsigned int*) SCPU_A12_BISR_RSTN_reg)=data)
#define get_SCPU_A12_BISR_RSTN_reg   (*((volatile unsigned int*) SCPU_A12_BISR_RSTN_reg))
#define SCPU_A12_BISR_RSTN_inst_adr                                                  "0x0065"
#define SCPU_A12_BISR_RSTN_inst                                                      0x0065
#define SCPU_A12_BISR_RSTN_BISR_RSTN_shift                                           (0)
#define SCPU_A12_BISR_RSTN_BISR_RSTN_mask                                            (0x00000001)
#define SCPU_A12_BISR_RSTN_BISR_RSTN(data)                                           (0x00000001&((data)<<0))
#define SCPU_A12_BISR_RSTN_BISR_RSTN_src(data)                                       ((0x00000001&(data))>>0)
#define SCPU_A12_BISR_RSTN_get_BISR_RSTN(data)                                       ((0x00000001&(data))>>0)


#define SCPU_A12_SE_RUN_EN                                                           0x1805C598
#define SCPU_A12_SE_RUN_EN_reg_addr                                                  "0xB805C598"
#define SCPU_A12_SE_RUN_EN_reg                                                       0xB805C598
#define set_SCPU_A12_SE_RUN_EN_reg(data)   (*((volatile unsigned int*) SCPU_A12_SE_RUN_EN_reg)=data)
#define get_SCPU_A12_SE_RUN_EN_reg   (*((volatile unsigned int*) SCPU_A12_SE_RUN_EN_reg))
#define SCPU_A12_SE_RUN_EN_inst_adr                                                  "0x0066"
#define SCPU_A12_SE_RUN_EN_inst                                                      0x0066
#define SCPU_A12_SE_RUN_EN_SECOND_RUN_EN_shift                                       (0)
#define SCPU_A12_SE_RUN_EN_SECOND_RUN_EN_mask                                        (0x00000001)
#define SCPU_A12_SE_RUN_EN_SECOND_RUN_EN(data)                                       (0x00000001&((data)<<0))
#define SCPU_A12_SE_RUN_EN_SECOND_RUN_EN_src(data)                                   ((0x00000001&(data))>>0)
#define SCPU_A12_SE_RUN_EN_get_SECOND_RUN_EN(data)                                   ((0x00000001&(data))>>0)


#define SCPU_A12_HOLD_REMAP                                                          0x1805C59C
#define SCPU_A12_HOLD_REMAP_reg_addr                                                 "0xB805C59C"
#define SCPU_A12_HOLD_REMAP_reg                                                      0xB805C59C
#define set_SCPU_A12_HOLD_REMAP_reg(data)   (*((volatile unsigned int*) SCPU_A12_HOLD_REMAP_reg)=data)
#define get_SCPU_A12_HOLD_REMAP_reg   (*((volatile unsigned int*) SCPU_A12_HOLD_REMAP_reg))
#define SCPU_A12_HOLD_REMAP_inst_adr                                                 "0x0067"
#define SCPU_A12_HOLD_REMAP_inst                                                     0x0067
#define SCPU_A12_HOLD_REMAP_HOLD_REMAP_shift                                         (0)
#define SCPU_A12_HOLD_REMAP_HOLD_REMAP_mask                                          (0x00000001)
#define SCPU_A12_HOLD_REMAP_HOLD_REMAP(data)                                         (0x00000001&((data)<<0))
#define SCPU_A12_HOLD_REMAP_HOLD_REMAP_src(data)                                     ((0x00000001&(data))>>0)
#define SCPU_A12_HOLD_REMAP_get_HOLD_REMAP(data)                                     ((0x00000001&(data))>>0)


#define SCPU_A12_BISR_DONE                                                           0x1805C5A0
#define SCPU_A12_BISR_DONE_reg_addr                                                  "0xB805C5A0"
#define SCPU_A12_BISR_DONE_reg                                                       0xB805C5A0
#define set_SCPU_A12_BISR_DONE_reg(data)   (*((volatile unsigned int*) SCPU_A12_BISR_DONE_reg)=data)
#define get_SCPU_A12_BISR_DONE_reg   (*((volatile unsigned int*) SCPU_A12_BISR_DONE_reg))
#define SCPU_A12_BISR_DONE_inst_adr                                                  "0x0068"
#define SCPU_A12_BISR_DONE_inst                                                      0x0068
#define SCPU_A12_BISR_DONE_BISR_DONE_shift                                           (0)
#define SCPU_A12_BISR_DONE_BISR_DONE_mask                                            (0x00000001)
#define SCPU_A12_BISR_DONE_BISR_DONE(data)                                           (0x00000001&((data)<<0))
#define SCPU_A12_BISR_DONE_BISR_DONE_src(data)                                       ((0x00000001&(data))>>0)
#define SCPU_A12_BISR_DONE_get_BISR_DONE(data)                                       ((0x00000001&(data))>>0)


#define SCPU_A12_BISR_DONE                                                           0x1805C5A4
#define SCPU_A12_BISR_DONE_reg_addr                                                  "0xB805C5A4"
#define SCPU_A12_BISR_DONE_reg                                                       0xB805C5A4
#define set_SCPU_A12_BISR_DONE_reg(data)   (*((volatile unsigned int*) SCPU_A12_BISR_DONE_reg)=data)
#define get_SCPU_A12_BISR_DONE_reg   (*((volatile unsigned int*) SCPU_A12_BISR_DONE_reg))
#define SCPU_A12_BISR_DONE_inst_adr                                                  "0x0069"
#define SCPU_A12_BISR_DONE_inst                                                      0x0069
#define SCPU_A12_BISR_DONE_BISR_FAIL_shift                                           (0)
#define SCPU_A12_BISR_DONE_BISR_FAIL_mask                                            (0x000000FF)
#define SCPU_A12_BISR_DONE_BISR_FAIL(data)                                           (0x000000FF&((data)<<0))
#define SCPU_A12_BISR_DONE_BISR_FAIL_src(data)                                       ((0x000000FF&(data))>>0)
#define SCPU_A12_BISR_DONE_get_BISR_FAIL(data)                                       ((0x000000FF&(data))>>0)


#define SCPU_A12_BISR_REPAIR                                                         0x1805C5A8
#define SCPU_A12_BISR_REPAIR_reg_addr                                                "0xB805C5A8"
#define SCPU_A12_BISR_REPAIR_reg                                                     0xB805C5A8
#define set_SCPU_A12_BISR_REPAIR_reg(data)   (*((volatile unsigned int*) SCPU_A12_BISR_REPAIR_reg)=data)
#define get_SCPU_A12_BISR_REPAIR_reg   (*((volatile unsigned int*) SCPU_A12_BISR_REPAIR_reg))
#define SCPU_A12_BISR_REPAIR_inst_adr                                                "0x006A"
#define SCPU_A12_BISR_REPAIR_inst                                                    0x006A
#define SCPU_A12_BISR_REPAIR_BISR_REPAIR_shift                                       (0)
#define SCPU_A12_BISR_REPAIR_BISR_REPAIR_mask                                        (0x00000001)
#define SCPU_A12_BISR_REPAIR_BISR_REPAIR(data)                                       (0x00000001&((data)<<0))
#define SCPU_A12_BISR_REPAIR_BISR_REPAIR_src(data)                                   ((0x00000001&(data))>>0)
#define SCPU_A12_BISR_REPAIR_get_BISR_REPAIR(data)                                   ((0x00000001&(data))>>0)


#define SCPU_A12_BISR_OUT                                                            0x1805C5AC
#define SCPU_A12_BISR_OUT_reg_addr                                                   "0xB805C5AC"
#define SCPU_A12_BISR_OUT_reg                                                        0xB805C5AC
#define set_SCPU_A12_BISR_OUT_reg(data)   (*((volatile unsigned int*) SCPU_A12_BISR_OUT_reg)=data)
#define get_SCPU_A12_BISR_OUT_reg   (*((volatile unsigned int*) SCPU_A12_BISR_OUT_reg))
#define SCPU_A12_BISR_OUT_inst_adr                                                   "0x006B"
#define SCPU_A12_BISR_OUT_inst                                                       0x006B
#define SCPU_A12_BISR_OUT_BISR_OUT_shift                                             (0)
#define SCPU_A12_BISR_OUT_BISR_OUT_mask                                              (0xFFFFFFFF)
#define SCPU_A12_BISR_OUT_BISR_OUT(data)                                             (0xFFFFFFFF&((data)<<0))
#define SCPU_A12_BISR_OUT_BISR_OUT_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define SCPU_A12_BISR_OUT_get_BISR_OUT(data)                                         ((0xFFFFFFFF&(data))>>0)


#define SCPU_A12_BISR_OUT_2                                                          0x1805C5B0
#define SCPU_A12_BISR_OUT_2_reg_addr                                                 "0xB805C5B0"
#define SCPU_A12_BISR_OUT_2_reg                                                      0xB805C5B0
#define set_SCPU_A12_BISR_OUT_2_reg(data)   (*((volatile unsigned int*) SCPU_A12_BISR_OUT_2_reg)=data)
#define get_SCPU_A12_BISR_OUT_2_reg   (*((volatile unsigned int*) SCPU_A12_BISR_OUT_2_reg))
#define SCPU_A12_BISR_OUT_2_inst_adr                                                 "0x006C"
#define SCPU_A12_BISR_OUT_2_inst                                                     0x006C
#define SCPU_A12_BISR_OUT_2_BISR_OUT_2_shift                                         (0)
#define SCPU_A12_BISR_OUT_2_BISR_OUT_2_mask                                          (0x00FFFFFF)
#define SCPU_A12_BISR_OUT_2_BISR_OUT_2(data)                                         (0x00FFFFFF&((data)<<0))
#define SCPU_A12_BISR_OUT_2_BISR_OUT_2_src(data)                                     ((0x00FFFFFF&(data))>>0)
#define SCPU_A12_BISR_OUT_2_get_BISR_OUT_2(data)                                     ((0x00FFFFFF&(data))>>0)


#endif
