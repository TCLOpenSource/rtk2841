/**************************************************************
// Spec Version                  : 0.0.1
// Parser Version                : DVR_Parser_6.8(110516)
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2012/8/13 17:15:7
***************************************************************/


#ifndef _WRAP_A9_REG_H_INCLUDED_
#define _WRAP_A9_REG_H_INCLUDED_
#ifdef  _WRAP_A9_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     dss_svt_data_in:20;
unsigned int     reserved_1:2;
unsigned int     dss_svt_data_in_ready:1;
unsigned int     dss_svt_wire_sel:1;
unsigned int     dss_svt_ro_sel:3;
unsigned int     dss_svt_dss_rst_n:1;
}DSS_SVT_CTRL;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     dss_svt_count_out:20;
unsigned int     reserved_1:2;
unsigned int     dss_svt_wsort_go:1;
unsigned int     dss_svt_ready:1;
}DSS_SVT_STATUS;

typedef struct 
{
unsigned int     reserved_0:4;
unsigned int     dss_lvt_data_in:20;
unsigned int     reserved_1:2;
unsigned int     dss_lvt_data_in_ready:1;
unsigned int     dss_lvt_wire_sel:1;
unsigned int     dss_lvt_ro_sel:3;
unsigned int     dss_lvt_dss_rst_n:1;
}DSS_LVT_CTRL;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     dss_lvt_count_out:20;
unsigned int     reserved_1:2;
unsigned int     dss_lvt_wsort_go:1;
unsigned int     dss_lvt_ready:1;
}DSS_LVT_STATUS;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     wcmd_bufable_sel:2;
unsigned int     wr_outstand_num:4;
unsigned int     rd_outstand_num:4;
}WRAP_CTRL0;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     smpnamp_o:2;
unsigned int     evento_o:1;
unsigned int     scuevabort_o:1;
unsigned int     pwrctl1_o:2;
unsigned int     pwrctl0_o:2;
unsigned int     reserved_1:1;
unsigned int     deflags1_o:7;
unsigned int     reserved_2:1;
unsigned int     deflags0_o:7;
}A9_STAT0;

typedef struct 
{
unsigned int     reserved_0:20;
unsigned int     eventi_i:1;
unsigned int     spniden_pl310_i:1;
unsigned int     edbgrq_i:2;
unsigned int     spniden_i:2;
unsigned int     spiden_i:2;
unsigned int     niden_i:2;
unsigned int     dbgen_i:2;
}A9_CTRL1;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     STANDBYWFE:2;
unsigned int     STANDBYWFI:2;
}A9_STAT1;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     PMUIRQ:2;
unsigned int     PMUSECURE:2;
unsigned int     PMUPRIV:2;
}A9_STAT2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     cfgsdisable_i:1;
}A9_CTRL2;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     protect_3_ena_reg:1;
unsigned int     protect_2_ena_reg:1;
unsigned int     protect_1_ena_reg:1;
unsigned int     protect_0_ena_reg:1;
}DC_MEM_PROTECT_CTRL;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     reserved_1:1;
unsigned int     reserved_2:1;
unsigned int     reserved_3:1;
unsigned int     reserved_4:1;
unsigned int     reserved_5:1;
unsigned int     scramble_3_ena_reg:1;
unsigned int     scramble_2_ena_reg:1;
unsigned int     scramble_1_ena_reg:1;
unsigned int     scramble_0_ena_reg:1;
}DC_MEM_SCRAMBLE_CTRL;

typedef struct 
{
unsigned int     mem_protect_saddr_0:20;
unsigned int     reserved_0:12;
}DC_MEM_PROTECT_SADDR0;

typedef struct 
{
unsigned int     mem_protect_eaddr_0:20;
unsigned int     reserved_0:12;
}DC_MEM_PROTECT_EADDR0;

typedef struct 
{
unsigned int     mem_protect_saddr_1:20;
unsigned int     reserved_0:12;
}DC_MEM_PROTECT_SADDR1;

typedef struct 
{
unsigned int     mem_protect_eaddr_1:20;
unsigned int     reserved_0:12;
}DC_MEM_PROTECT_EADDR1;

typedef struct 
{
unsigned int     mem_protect_saddr_2:20;
unsigned int     reserved_0:12;
}DC_MEM_PROTECT_SADDR2;

typedef struct 
{
unsigned int     mem_protect_eaddr_2:20;
unsigned int     reserved_0:12;
}DC_MEM_PROTECT_EADDR2;

typedef struct 
{
unsigned int     mem_protect_saddr_3:20;
unsigned int     reserved_0:12;
}DC_MEM_PROTECT_SADDR3;

typedef struct 
{
unsigned int     mem_protect_eaddr_3:20;
unsigned int     reserved_0:12;
}DC_MEM_PROTECT_EADDR3;

typedef struct 
{
unsigned int     mem_scramble_saddr_0:20;
unsigned int     reserved_0:12;
}DC_MEM_SCRAMBLE_SADDR0;

typedef struct 
{
unsigned int     mem_scramble_eaddr_0:20;
unsigned int     reserved_0:12;
}DC_MEM_SCRAMBLE_EADDR0;

typedef struct 
{
unsigned int     mem_scramble_saddr_1:20;
unsigned int     reserved_0:12;
}DC_MEM_SCRAMBLE_SADDR1;

typedef struct 
{
unsigned int     mem_scramble_eaddr_1:20;
unsigned int     reserved_0:12;
}DC_MEM_SCRAMBLE_EADDR1;

typedef struct 
{
unsigned int     mem_scramble_saddr_2:20;
unsigned int     reserved_0:12;
}DC_MEM_SCRAMBLE_SADDR2;

typedef struct 
{
unsigned int     mem_scramble_eaddr_2:20;
unsigned int     reserved_0:12;
}DC_MEM_SCRAMBLE_EADDR2;

typedef struct 
{
unsigned int     mem_scramble_saddr_3:20;
unsigned int     reserved_0:12;
}DC_MEM_SCRAMBLE_SADDR3;

typedef struct 
{
unsigned int     mem_scramble_eaddr_3:20;
unsigned int     reserved_0:12;
}DC_MEM_SCRAMBLE_EADDR3;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_scramble_en:1;
}DC_MEM_SCRAMBLE_CTRL;

typedef struct 
{
unsigned int     dbg_start_addr_m0:32;
}DBG_START_M0;

typedef struct 
{
unsigned int     dbg_end_addr_m0:32;
}DBG_END_M0;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     write_en2:1;
unsigned int     dbg_wr_chk_m0:2;
unsigned int     write_en1:1;
unsigned int     dbg_en_m0:1;
}DBG_CTRL_M0;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     scpu_int_m0:1;
unsigned int     scpu_int_en_m0:1;
unsigned int     scpu_neg_int_m0:1;
unsigned int     scpu_neg_int_en_m0:1;
unsigned int     write_data:1;
}DBG_INT_M0;

typedef struct 
{
unsigned int     dbg_addr_m0:32;
}DBG_ADDR_M0;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_dbg_write_m0:1;
}DBG_ADDR1_M0;

typedef struct 
{
unsigned int     dbg_start_addr_m1:32;
}DBG_START_M1;

typedef struct 
{
unsigned int     dbg_end_addr_m1:32;
}DBG_END_M1;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     write_en2:1;
unsigned int     dbg_wr_chk_m1:2;
unsigned int     write_en1:1;
unsigned int     dbg_en_m1:1;
}DBG_CTRL_M1;

typedef struct 
{
unsigned int     reserved_0:27;
unsigned int     scpu_int_m1:1;
unsigned int     scpu_int_en_m1:1;
unsigned int     scpu_neg_int_m1:1;
unsigned int     scpu_neg_int_en_m1:1;
unsigned int     write_data:1;
}DBG_INT_M1;

typedef struct 
{
unsigned int     dbg_addr_m1:32;
}DBG_ADDR_M1;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_dbg_write_m1:1;
}DBG_ADDR1_M1;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     scu_mbist_mode:1;
unsigned int     idata_mbist_mode:1;
unsigned int     itag_mbist_mode:1;
unsigned int     ddata_mbist_mode:1;
unsigned int     dtag_mbist_mode:1;
unsigned int     douter_mbist_mode:1;
unsigned int     btac_mbist_mode:1;
unsigned int     ghb_mbist_mode:1;
unsigned int     tlb_mbist_mode:1;
}BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     scu_drf_mbist_mode:1;
unsigned int     cpu_drf_mbist_mode:1;
}DRF_BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     scu_drf_test_resume:1;
unsigned int     cpu_drf_test_resume:1;
}DRF_TEST_RESUME;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     idata_mbist_done:1;
unsigned int     itag_mbist_done:1;
unsigned int     ddata_mbist_done:1;
unsigned int     dtag_mbist_done:1;
unsigned int     douter_mbist_done:1;
unsigned int     btac_mbist_done:1;
unsigned int     ghb_mbist_done:1;
unsigned int     tlb_mbist_done:1;
}CPU_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scu_mbist_done:1;
}SCU_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     cpu_drf_mbist_done:1;
}CPU_DRF_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scu_drf_mbist_done:1;
}SCU_DRF_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu0_idata_mbist_fail:1;
unsigned int     cpu0_itag_mbist_fail:1;
unsigned int     cpu0_ddata_mbist_fail:1;
unsigned int     cpu0_dtag_mbist_fail:1;
unsigned int     cpu0_douter_mbist_fail:1;
unsigned int     cpu0_btac_mbist_fail:1;
unsigned int     cpu0_ghb_mbist_fail:1;
unsigned int     cpu0_tlb_mbist_fail:1;
}CPU0_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu1_idata_mbist_fail:1;
unsigned int     cpu1_itag_mbist_fail:1;
unsigned int     cpu1_ddata_mbist_fail:1;
unsigned int     cpu1_dtag_mbist_fail:1;
unsigned int     cpu1_douter_mbist_fail:1;
unsigned int     cpu1_btac_mbist_fail:1;
unsigned int     cpu1_ghb_mbist_fail:1;
unsigned int     cpu1_tlb_mbist_fail:1;
}CPU1_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu0_idata_drf_mbist_fail:1;
unsigned int     cpu0_itag_drf_mbist_fail:1;
unsigned int     cpu0_ddata_drf_mbist_fail:1;
unsigned int     cpu0_dtag_drf_mbist_fail:1;
unsigned int     cpu0_douter_drf_mbist_fail:1;
unsigned int     cpu0_btac_drf_mbist_fail:1;
unsigned int     cpu0_ghb_drf_mbist_fail:1;
unsigned int     cpu0_tlb_drf_mbist_fail:1;
}CPU0_DRF_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu1_idata_drf_mbist_fail:1;
unsigned int     cpu1_itag_drf_mbist_fail:1;
unsigned int     cpu1_ddata_drf_mbist_fail:1;
unsigned int     cpu1_dtag_drf_mbist_fail:1;
unsigned int     cpu1_douter_drf_mbist_fail:1;
unsigned int     cpu1_btac_drf_mbist_fail:1;
unsigned int     cpu1_ghb_drf_mbist_fail:1;
unsigned int     cpu1_tlb_drf_mbist_fail:1;
}CPU1_DRF_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu0_idata_mbist_fail_7:1;
unsigned int     cpu0_idata_mbist_fail_6:1;
unsigned int     cpu0_idata_mbist_fail_5:1;
unsigned int     cpu0_idata_mbist_fail_4:1;
unsigned int     cpu0_idata_mbist_fail_3:1;
unsigned int     cpu0_idata_mbist_fail_2:1;
unsigned int     cpu0_idata_mbist_fail_1:1;
unsigned int     cpu0_idata_mbist_fail_0:1;
}CPU0_IDATA_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu1_idata_mbist_fail_7:1;
unsigned int     cpu1_idata_mbist_fail_6:1;
unsigned int     cpu1_idata_mbist_fail_5:1;
unsigned int     cpu1_idata_mbist_fail_4:1;
unsigned int     cpu1_idata_mbist_fail_3:1;
unsigned int     cpu1_idata_mbist_fail_2:1;
unsigned int     cpu1_idata_mbist_fail_1:1;
unsigned int     cpu1_idata_mbist_fail_0:1;
}CPU1_IDATA_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu0_idata_drf_mbist_fail_7:1;
unsigned int     cpu0_idata_drf_mbist_fail_6:1;
unsigned int     cpu0_idata_drf_mbist_fail_5:1;
unsigned int     cpu0_idata_drf_mbist_fail_4:1;
unsigned int     cpu0_idata_drf_mbist_fail_3:1;
unsigned int     cpu0_idata_drf_mbist_fail_2:1;
unsigned int     cpu0_idata_drf_mbist_fail_1:1;
unsigned int     cpu0_idata_drf_mbist_fail_0:1;
}CPU0_IDATA_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu1_idata_drf_mbist_fail_7:1;
unsigned int     cpu1_idata_drf_mbist_fail_6:1;
unsigned int     cpu1_idata_drf_mbist_fail_5:1;
unsigned int     cpu1_idata_drf_mbist_fail_4:1;
unsigned int     cpu1_idata_drf_mbist_fail_3:1;
unsigned int     cpu1_idata_drf_mbist_fail_2:1;
unsigned int     cpu1_idata_drf_mbist_fail_1:1;
unsigned int     cpu1_idata_drf_mbist_fail_0:1;
}CPU1_IDATA_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu0_itag_mbist_fail_3:1;
unsigned int     cpu0_itag_mbist_fail_2:1;
unsigned int     cpu0_itag_mbist_fail_1:1;
unsigned int     cpu0_itag_mbist_fail_0:1;
}CPU0_ITAG_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu1_itag_mbist_fail_3:1;
unsigned int     cpu1_itag_mbist_fail_2:1;
unsigned int     cpu1_itag_mbist_fail_1:1;
unsigned int     cpu1_itag_mbist_fail_0:1;
}CPU1_ITAG_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu0_itag_drf_mbist_fail_3:1;
unsigned int     cpu0_itag_drf_mbist_fail_2:1;
unsigned int     cpu0_itag_drf_mbist_fail_1:1;
unsigned int     cpu0_itag_drf_mbist_fail_0:1;
}CPU0_ITAG_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu1_itag_drf_mbist_fail_3:1;
unsigned int     cpu1_itag_drf_mbist_fail_2:1;
unsigned int     cpu1_itag_drf_mbist_fail_1:1;
unsigned int     cpu1_itag_drf_mbist_fail_0:1;
}CPU1_ITAG_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu0_ddata_mbist_fail_7:1;
unsigned int     cpu0_ddata_mbist_fail_6:1;
unsigned int     cpu0_ddata_mbist_fail_5:1;
unsigned int     cpu0_ddata_mbist_fail_4:1;
unsigned int     cpu0_ddata_mbist_fail_3:1;
unsigned int     cpu0_ddata_mbist_fail_2:1;
unsigned int     cpu0_ddata_mbist_fail_1:1;
unsigned int     cpu0_ddata_mbist_fail_0:1;
}CPU0_DDATA_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu1_ddata_mbist_fail_7:1;
unsigned int     cpu1_ddata_mbist_fail_6:1;
unsigned int     cpu1_ddata_mbist_fail_5:1;
unsigned int     cpu1_ddata_mbist_fail_4:1;
unsigned int     cpu1_ddata_mbist_fail_3:1;
unsigned int     cpu1_ddata_mbist_fail_2:1;
unsigned int     cpu1_ddata_mbist_fail_1:1;
unsigned int     cpu1_ddata_mbist_fail_0:1;
}CPU1_DDATA_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu0_ddata_drf_mbist_fail_7:1;
unsigned int     cpu0_ddata_drf_mbist_fail_6:1;
unsigned int     cpu0_ddata_drf_mbist_fail_5:1;
unsigned int     cpu0_ddata_drf_mbist_fail_4:1;
unsigned int     cpu0_ddata_drf_mbist_fail_3:1;
unsigned int     cpu0_ddata_drf_mbist_fail_2:1;
unsigned int     cpu0_ddata_drf_mbist_fail_1:1;
unsigned int     cpu0_ddata_drf_mbist_fail_0:1;
}CPU0_DDATA_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     cpu1_ddata_drf_mbist_fail_7:1;
unsigned int     cpu1_ddata_drf_mbist_fail_6:1;
unsigned int     cpu1_ddata_drf_mbist_fail_5:1;
unsigned int     cpu1_ddata_drf_mbist_fail_4:1;
unsigned int     cpu1_ddata_drf_mbist_fail_3:1;
unsigned int     cpu1_ddata_drf_mbist_fail_2:1;
unsigned int     cpu1_ddata_drf_mbist_fail_1:1;
unsigned int     cpu1_ddata_drf_mbist_fail_0:1;
}CPU1_DDATA_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu0_dtag_mbist_fail_3:1;
unsigned int     cpu0_dtag_mbist_fail_2:1;
unsigned int     cpu0_dtag_mbist_fail_1:1;
unsigned int     cpu0_dtag_mbist_fail_0:1;
}CPU0_DTAG_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu1_dtag_mbist_fail_3:1;
unsigned int     cpu1_dtag_mbist_fail_2:1;
unsigned int     cpu1_dtag_mbist_fail_1:1;
unsigned int     cpu1_dtag_mbist_fail_0:1;
}CPU1_DTAG_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu0_dtag_drf_mbist_fail_3:1;
unsigned int     cpu0_dtag_drf_mbist_fail_2:1;
unsigned int     cpu0_dtag_drf_mbist_fail_1:1;
unsigned int     cpu0_dtag_drf_mbist_fail_0:1;
}CPU0_DTAG_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu1_dtag_drf_mbist_fail_3:1;
unsigned int     cpu1_dtag_drf_mbist_fail_2:1;
unsigned int     cpu1_dtag_drf_mbist_fail_1:1;
unsigned int     cpu1_dtag_drf_mbist_fail_0:1;
}CPU1_DTAG_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu0_btac_mbist_fail_3:1;
unsigned int     cpu0_btac_mbist_fail_2:1;
unsigned int     cpu0_btac_mbist_fail_1:1;
unsigned int     cpu0_btac_mbist_fail_0:1;
}CPU0_BTAC_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu1_btac_mbist_fail_3:1;
unsigned int     cpu1_btac_mbist_fail_2:1;
unsigned int     cpu1_btac_mbist_fail_1:1;
unsigned int     cpu1_btac_mbist_fail_0:1;
}CPU1_BTAC_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu0_btac_drf_mbist_fail_3:1;
unsigned int     cpu0_btac_drf_mbist_fail_2:1;
unsigned int     cpu0_btac_drf_mbist_fail_1:1;
unsigned int     cpu0_btac_drf_mbist_fail_0:1;
}CPU0_BTAC_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu1_btac_drf_mbist_fail_3:1;
unsigned int     cpu1_btac_drf_mbist_fail_2:1;
unsigned int     cpu1_btac_drf_mbist_fail_1:1;
unsigned int     cpu1_btac_drf_mbist_fail_0:1;
}CPU1_BTAC_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu0_ghb_mbist_fail_3:1;
unsigned int     cpu0_ghb_mbist_fail_2:1;
unsigned int     cpu0_ghb_mbist_fail_1:1;
unsigned int     cpu0_ghb_mbist_fail_0:1;
}CPU0_GHB_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu1_ghb_mbist_fail_3:1;
unsigned int     cpu1_ghb_mbist_fail_2:1;
unsigned int     cpu1_ghb_mbist_fail_1:1;
unsigned int     cpu1_ghb_mbist_fail_0:1;
}CPU1_GHB_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu0_ghb_drf_mbist_fail_3:1;
unsigned int     cpu0_ghb_drf_mbist_fail_2:1;
unsigned int     cpu0_ghb_drf_mbist_fail_1:1;
unsigned int     cpu0_ghb_drf_mbist_fail_0:1;
}CPU0_GHB_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     cpu1_ghb_drf_mbist_fail_3:1;
unsigned int     cpu1_ghb_drf_mbist_fail_2:1;
unsigned int     cpu1_ghb_drf_mbist_fail_1:1;
unsigned int     cpu1_ghb_drf_mbist_fail_0:1;
}CPU1_GHB_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     cpu0_tlb_mbist_fail_1:1;
unsigned int     cpu0_tlb_mbist_fail_0:1;
}CPU0_TLB_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     cpu1_tlb_mbist_fail_1:1;
unsigned int     cpu1_tlb_mbist_fail_0:1;
}CPU1_TLB_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     cpu0_tlb_drf_mbist_fail_1:1;
unsigned int     cpu0_tlb_drf_mbist_fail_0:1;
}CPU0_TLB_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     cpu1_tlb_drf_mbist_fail_1:1;
unsigned int     cpu1_tlb_drf_mbist_fail_0:1;
}CPU1_TLB_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scu_mbist_fail_group:1;
}SCU_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scu_drf_mbist_fail_group:1;
}SCU_DRF_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     scu_mbist_fail:8;
}SCU_BIST_FAIL_SEP;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     scu_drf_mbist_fail:8;
}SCU_DRF_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     cpu1_drf_start_pause:1;
unsigned int     cpu0_drf_start_pause:1;
}CPU_DRF_START_PAUSE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scu_drf_start_pause:1;
}SCU_DRF_START_PAUSE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     BISR_RSTN_TAG:1;
unsigned int     BISR_RSTN_DATA:1;
}BISR_RSTN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     HOLD_REMAP_TAG:1;
unsigned int     HOLD_REMAP_DATA:1;
}HOLD_REMAP;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     SECOND_RUN_EN_TAG:1;
unsigned int     SECOND_RUN_EN_DATA:1;
}SECOND_RUN_EN;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DRF_BISR_MODE_TAG:1;
unsigned int     DRF_BISR_MODE_DATA:1;
}DRF_BISR_MODE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     DRF_BISR_TEST_RESUME:1;
}DRF_BISR_TEST_RESUME;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     BISR_REPAIRED_TAG:1;
unsigned int     BISR_REPAIRED_DATA:1;
}BISR_REPAIR;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     BISR_DONE_TAG:1;
unsigned int     BISR_DONE_DATA:1;
}BISR_DONE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DRF_BISR_DONE_TAG:1;
unsigned int     DRF_BISR_DONE_DATA:1;
}DRF_BISR_DONE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DRF_BISR_START_PAUSE_TAG:1;
unsigned int     DRF_BISR_START_PAUSE_DATA:1;
}DRF_START_PAUSE;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     BISR_FAIL_TAG:1;
unsigned int     BISR_FAIL_DATA:1;
}BISR_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     BISR_FAIL_DATA_3:1;
unsigned int     BISR_FAIL_DATA_2:1;
unsigned int     BISR_FAIL_DATA_1:1;
unsigned int     BISR_FAIL_DATA_0:1;
}BISR_FAIL_DATA_SEP;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     BISR_FAIL_TAG_15:1;
unsigned int     BISR_FAIL_TAG_14:1;
unsigned int     BISR_FAIL_TAG_13:1;
unsigned int     BISR_FAIL_TAG_12:1;
unsigned int     BISR_FAIL_TAG_11:1;
unsigned int     BISR_FAIL_TAG_10:1;
unsigned int     BISR_FAIL_TAG_9:1;
unsigned int     BISR_FAIL_TAG_8:1;
unsigned int     BISR_FAIL_TAG_7:1;
unsigned int     BISR_FAIL_TAG_6:1;
unsigned int     BISR_FAIL_TAG_5:1;
unsigned int     BISR_FAIL_TAG_4:1;
unsigned int     BISR_FAIL_TAG_3:1;
unsigned int     BISR_FAIL_TAG_2:1;
unsigned int     BISR_FAIL_TAG_1:1;
unsigned int     BISR_FAIL_TAG_0:1;
}BISR_FAIL_TAG_SEP;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     DRF_BISR_FAIL_TAG:1;
unsigned int     DRF_BISR_FAIL_DATA:1;
}DRF_BISR_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     DRF_BISR_FAIL_DATA_3:1;
unsigned int     DRF_BISR_FAIL_DATA_2:1;
unsigned int     DRF_BISR_FAIL_DATA_1:1;
unsigned int     DRF_BISR_FAIL_DATA_0:1;
}DRF_BISR_FAIL_DATA_SEP;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     DRF_BISR_FAIL_TAG_15:1;
unsigned int     DRF_BISR_FAIL_TAG_14:1;
unsigned int     DRF_BISR_FAIL_TAG_13:1;
unsigned int     DRF_BISR_FAIL_TAG_12:1;
unsigned int     DRF_BISR_FAIL_TAG_11:1;
unsigned int     DRF_BISR_FAIL_TAG_10:1;
unsigned int     DRF_BISR_FAIL_TAG_9:1;
unsigned int     DRF_BISR_FAIL_TAG_8:1;
unsigned int     DRF_BISR_FAIL_TAG_7:1;
unsigned int     DRF_BISR_FAIL_TAG_6:1;
unsigned int     DRF_BISR_FAIL_TAG_5:1;
unsigned int     DRF_BISR_FAIL_TAG_4:1;
unsigned int     DRF_BISR_FAIL_TAG_3:1;
unsigned int     DRF_BISR_FAIL_TAG_2:1;
unsigned int     DRF_BISR_FAIL_TAG_1:1;
unsigned int     DRF_BISR_FAIL_TAG_0:1;
}DRF_BISR_FAIL_TAG_SEP;

typedef struct 
{
unsigned int     reserved_0:23;
unsigned int     scu_ram_RME:1;
unsigned int     idata_ram_RME:1;
unsigned int     itag_ram_RME:1;
unsigned int     ddata_ram_RME:1;
unsigned int     dtag_ram_RME:1;
unsigned int     douter_ram_RME:1;
unsigned int     btac_ram_RME:1;
unsigned int     ghb_ram_RME:1;
unsigned int     tlb_ram_RME:1;
}SRAM_RME;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     douter_ram_RM:4;
unsigned int     btac_ram_RM:4;
unsigned int     ghb_ram_RM:4;
unsigned int     tlb_ram_RM:4;
}SRAM_RM;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     scu_ram_RM:4;
unsigned int     idata_ram_RM:4;
unsigned int     itag_ram_RM:4;
unsigned int     ddata_ram_RM:4;
unsigned int     dtag_ram_RM:4;
}SRAM_RM;

typedef struct 
{
unsigned int     reserved_0:30;
unsigned int     l2_data_ram_RME:1;
unsigned int     l2_tag_ram_RME:1;
}L2_SRAM_RME;

typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     l2_data_ram_RM:4;
unsigned int     l2_tag_ram_RM:4;
}L2_SRAM_RM;

#endif

#define DSS_SVT_CTRL                                                                 0x1805C000
#define DSS_SVT_CTRL_reg_addr                                                        "0xB805C000"
#define DSS_SVT_CTRL_reg                                                             0xB805C000
#define set_DSS_SVT_CTRL_reg(data)   (*((volatile unsigned int*) DSS_SVT_CTRL_reg)=data)
#define get_DSS_SVT_CTRL_reg   (*((volatile unsigned int*) DSS_SVT_CTRL_reg))
#define DSS_SVT_CTRL_inst_adr                                                        "0x0000"
#define DSS_SVT_CTRL_inst                                                            0x0000
#define DSS_SVT_CTRL_dss_svt_data_in_shift                                           (8)
#define DSS_SVT_CTRL_dss_svt_data_in_mask                                            (0x0FFFFF00)
#define DSS_SVT_CTRL_dss_svt_data_in(data)                                           (0x0FFFFF00&((data)<<8))
#define DSS_SVT_CTRL_dss_svt_data_in_src(data)                                       ((0x0FFFFF00&(data))>>8)
#define DSS_SVT_CTRL_get_dss_svt_data_in(data)                                       ((0x0FFFFF00&(data))>>8)
#define DSS_SVT_CTRL_dss_svt_data_in_ready_shift                                     (5)
#define DSS_SVT_CTRL_dss_svt_data_in_ready_mask                                      (0x00000020)
#define DSS_SVT_CTRL_dss_svt_data_in_ready(data)                                     (0x00000020&((data)<<5))
#define DSS_SVT_CTRL_dss_svt_data_in_ready_src(data)                                 ((0x00000020&(data))>>5)
#define DSS_SVT_CTRL_get_dss_svt_data_in_ready(data)                                 ((0x00000020&(data))>>5)
#define DSS_SVT_CTRL_dss_svt_wire_sel_shift                                          (4)
#define DSS_SVT_CTRL_dss_svt_wire_sel_mask                                           (0x00000010)
#define DSS_SVT_CTRL_dss_svt_wire_sel(data)                                          (0x00000010&((data)<<4))
#define DSS_SVT_CTRL_dss_svt_wire_sel_src(data)                                      ((0x00000010&(data))>>4)
#define DSS_SVT_CTRL_get_dss_svt_wire_sel(data)                                      ((0x00000010&(data))>>4)
#define DSS_SVT_CTRL_dss_svt_ro_sel_shift                                            (1)
#define DSS_SVT_CTRL_dss_svt_ro_sel_mask                                             (0x0000000E)
#define DSS_SVT_CTRL_dss_svt_ro_sel(data)                                            (0x0000000E&((data)<<1))
#define DSS_SVT_CTRL_dss_svt_ro_sel_src(data)                                        ((0x0000000E&(data))>>1)
#define DSS_SVT_CTRL_get_dss_svt_ro_sel(data)                                        ((0x0000000E&(data))>>1)
#define DSS_SVT_CTRL_dss_svt_dss_rst_n_shift                                         (0)
#define DSS_SVT_CTRL_dss_svt_dss_rst_n_mask                                          (0x00000001)
#define DSS_SVT_CTRL_dss_svt_dss_rst_n(data)                                         (0x00000001&((data)<<0))
#define DSS_SVT_CTRL_dss_svt_dss_rst_n_src(data)                                     ((0x00000001&(data))>>0)
#define DSS_SVT_CTRL_get_dss_svt_dss_rst_n(data)                                     ((0x00000001&(data))>>0)


#define DSS_SVT_STATUS                                                               0x1805C004
#define DSS_SVT_STATUS_reg_addr                                                      "0xB805C004"
#define DSS_SVT_STATUS_reg                                                           0xB805C004
#define set_DSS_SVT_STATUS_reg(data)   (*((volatile unsigned int*) DSS_SVT_STATUS_reg)=data)
#define get_DSS_SVT_STATUS_reg   (*((volatile unsigned int*) DSS_SVT_STATUS_reg))
#define DSS_SVT_STATUS_inst_adr                                                      "0x0001"
#define DSS_SVT_STATUS_inst                                                          0x0001
#define DSS_SVT_STATUS_dss_svt_count_out_shift                                       (4)
#define DSS_SVT_STATUS_dss_svt_count_out_mask                                        (0x00FFFFF0)
#define DSS_SVT_STATUS_dss_svt_count_out(data)                                       (0x00FFFFF0&((data)<<4))
#define DSS_SVT_STATUS_dss_svt_count_out_src(data)                                   ((0x00FFFFF0&(data))>>4)
#define DSS_SVT_STATUS_get_dss_svt_count_out(data)                                   ((0x00FFFFF0&(data))>>4)
#define DSS_SVT_STATUS_dss_svt_wsort_go_shift                                        (1)
#define DSS_SVT_STATUS_dss_svt_wsort_go_mask                                         (0x00000002)
#define DSS_SVT_STATUS_dss_svt_wsort_go(data)                                        (0x00000002&((data)<<1))
#define DSS_SVT_STATUS_dss_svt_wsort_go_src(data)                                    ((0x00000002&(data))>>1)
#define DSS_SVT_STATUS_get_dss_svt_wsort_go(data)                                    ((0x00000002&(data))>>1)
#define DSS_SVT_STATUS_dss_svt_ready_shift                                           (0)
#define DSS_SVT_STATUS_dss_svt_ready_mask                                            (0x00000001)
#define DSS_SVT_STATUS_dss_svt_ready(data)                                           (0x00000001&((data)<<0))
#define DSS_SVT_STATUS_dss_svt_ready_src(data)                                       ((0x00000001&(data))>>0)
#define DSS_SVT_STATUS_get_dss_svt_ready(data)                                       ((0x00000001&(data))>>0)


#define DSS_LVT_CTRL                                                                 0x1805C008
#define DSS_LVT_CTRL_reg_addr                                                        "0xB805C008"
#define DSS_LVT_CTRL_reg                                                             0xB805C008
#define set_DSS_LVT_CTRL_reg(data)   (*((volatile unsigned int*) DSS_LVT_CTRL_reg)=data)
#define get_DSS_LVT_CTRL_reg   (*((volatile unsigned int*) DSS_LVT_CTRL_reg))
#define DSS_LVT_CTRL_inst_adr                                                        "0x0002"
#define DSS_LVT_CTRL_inst                                                            0x0002
#define DSS_LVT_CTRL_dss_lvt_data_in_shift                                           (8)
#define DSS_LVT_CTRL_dss_lvt_data_in_mask                                            (0x0FFFFF00)
#define DSS_LVT_CTRL_dss_lvt_data_in(data)                                           (0x0FFFFF00&((data)<<8))
#define DSS_LVT_CTRL_dss_lvt_data_in_src(data)                                       ((0x0FFFFF00&(data))>>8)
#define DSS_LVT_CTRL_get_dss_lvt_data_in(data)                                       ((0x0FFFFF00&(data))>>8)
#define DSS_LVT_CTRL_dss_lvt_data_in_ready_shift                                     (5)
#define DSS_LVT_CTRL_dss_lvt_data_in_ready_mask                                      (0x00000020)
#define DSS_LVT_CTRL_dss_lvt_data_in_ready(data)                                     (0x00000020&((data)<<5))
#define DSS_LVT_CTRL_dss_lvt_data_in_ready_src(data)                                 ((0x00000020&(data))>>5)
#define DSS_LVT_CTRL_get_dss_lvt_data_in_ready(data)                                 ((0x00000020&(data))>>5)
#define DSS_LVT_CTRL_dss_lvt_wire_sel_shift                                          (4)
#define DSS_LVT_CTRL_dss_lvt_wire_sel_mask                                           (0x00000010)
#define DSS_LVT_CTRL_dss_lvt_wire_sel(data)                                          (0x00000010&((data)<<4))
#define DSS_LVT_CTRL_dss_lvt_wire_sel_src(data)                                      ((0x00000010&(data))>>4)
#define DSS_LVT_CTRL_get_dss_lvt_wire_sel(data)                                      ((0x00000010&(data))>>4)
#define DSS_LVT_CTRL_dss_lvt_ro_sel_shift                                            (1)
#define DSS_LVT_CTRL_dss_lvt_ro_sel_mask                                             (0x0000000E)
#define DSS_LVT_CTRL_dss_lvt_ro_sel(data)                                            (0x0000000E&((data)<<1))
#define DSS_LVT_CTRL_dss_lvt_ro_sel_src(data)                                        ((0x0000000E&(data))>>1)
#define DSS_LVT_CTRL_get_dss_lvt_ro_sel(data)                                        ((0x0000000E&(data))>>1)
#define DSS_LVT_CTRL_dss_lvt_dss_rst_n_shift                                         (0)
#define DSS_LVT_CTRL_dss_lvt_dss_rst_n_mask                                          (0x00000001)
#define DSS_LVT_CTRL_dss_lvt_dss_rst_n(data)                                         (0x00000001&((data)<<0))
#define DSS_LVT_CTRL_dss_lvt_dss_rst_n_src(data)                                     ((0x00000001&(data))>>0)
#define DSS_LVT_CTRL_get_dss_lvt_dss_rst_n(data)                                     ((0x00000001&(data))>>0)


#define DSS_LVT_STATUS                                                               0x1805C010
#define DSS_LVT_STATUS_reg_addr                                                      "0xB805C010"
#define DSS_LVT_STATUS_reg                                                           0xB805C010
#define set_DSS_LVT_STATUS_reg(data)   (*((volatile unsigned int*) DSS_LVT_STATUS_reg)=data)
#define get_DSS_LVT_STATUS_reg   (*((volatile unsigned int*) DSS_LVT_STATUS_reg))
#define DSS_LVT_STATUS_inst_adr                                                      "0x0004"
#define DSS_LVT_STATUS_inst                                                          0x0004
#define DSS_LVT_STATUS_dss_lvt_count_out_shift                                       (4)
#define DSS_LVT_STATUS_dss_lvt_count_out_mask                                        (0x00FFFFF0)
#define DSS_LVT_STATUS_dss_lvt_count_out(data)                                       (0x00FFFFF0&((data)<<4))
#define DSS_LVT_STATUS_dss_lvt_count_out_src(data)                                   ((0x00FFFFF0&(data))>>4)
#define DSS_LVT_STATUS_get_dss_lvt_count_out(data)                                   ((0x00FFFFF0&(data))>>4)
#define DSS_LVT_STATUS_dss_lvt_wsort_go_shift                                        (1)
#define DSS_LVT_STATUS_dss_lvt_wsort_go_mask                                         (0x00000002)
#define DSS_LVT_STATUS_dss_lvt_wsort_go(data)                                        (0x00000002&((data)<<1))
#define DSS_LVT_STATUS_dss_lvt_wsort_go_src(data)                                    ((0x00000002&(data))>>1)
#define DSS_LVT_STATUS_get_dss_lvt_wsort_go(data)                                    ((0x00000002&(data))>>1)
#define DSS_LVT_STATUS_dss_lvt_ready_shift                                           (0)
#define DSS_LVT_STATUS_dss_lvt_ready_mask                                            (0x00000001)
#define DSS_LVT_STATUS_dss_lvt_ready(data)                                           (0x00000001&((data)<<0))
#define DSS_LVT_STATUS_dss_lvt_ready_src(data)                                       ((0x00000001&(data))>>0)
#define DSS_LVT_STATUS_get_dss_lvt_ready(data)                                       ((0x00000001&(data))>>0)


#define WRAP_CTRL0                                                                   0x1805C020
#define WRAP_CTRL0_reg_addr                                                          "0xB805C020"
#define WRAP_CTRL0_reg                                                               0xB805C020
#define set_WRAP_CTRL0_reg(data)   (*((volatile unsigned int*) WRAP_CTRL0_reg)=data)
#define get_WRAP_CTRL0_reg   (*((volatile unsigned int*) WRAP_CTRL0_reg))
#define WRAP_CTRL0_inst_adr                                                          "0x0008"
#define WRAP_CTRL0_inst                                                              0x0008
#define WRAP_CTRL0_wcmd_bufable_sel_shift                                            (8)
#define WRAP_CTRL0_wcmd_bufable_sel_mask                                             (0x00000300)
#define WRAP_CTRL0_wcmd_bufable_sel(data)                                            (0x00000300&((data)<<8))
#define WRAP_CTRL0_wcmd_bufable_sel_src(data)                                        ((0x00000300&(data))>>8)
#define WRAP_CTRL0_get_wcmd_bufable_sel(data)                                        ((0x00000300&(data))>>8)
#define WRAP_CTRL0_wr_outstand_num_shift                                             (4)
#define WRAP_CTRL0_wr_outstand_num_mask                                              (0x000000F0)
#define WRAP_CTRL0_wr_outstand_num(data)                                             (0x000000F0&((data)<<4))
#define WRAP_CTRL0_wr_outstand_num_src(data)                                         ((0x000000F0&(data))>>4)
#define WRAP_CTRL0_get_wr_outstand_num(data)                                         ((0x000000F0&(data))>>4)
#define WRAP_CTRL0_rd_outstand_num_shift                                             (0)
#define WRAP_CTRL0_rd_outstand_num_mask                                              (0x0000000F)
#define WRAP_CTRL0_rd_outstand_num(data)                                             (0x0000000F&((data)<<0))
#define WRAP_CTRL0_rd_outstand_num_src(data)                                         ((0x0000000F&(data))>>0)
#define WRAP_CTRL0_get_rd_outstand_num(data)                                         ((0x0000000F&(data))>>0)


#define A9_STAT0                                                                     0x1805C100
#define A9_STAT0_reg_addr                                                            "0xB805C100"
#define A9_STAT0_reg                                                                 0xB805C100
#define set_A9_STAT0_reg(data)   (*((volatile unsigned int*) A9_STAT0_reg)=data)
#define get_A9_STAT0_reg   (*((volatile unsigned int*) A9_STAT0_reg))
#define A9_STAT0_inst_adr                                                            "0x0040"
#define A9_STAT0_inst                                                                0x0040
#define A9_STAT0_smpnamp_o_shift                                                     (22)
#define A9_STAT0_smpnamp_o_mask                                                      (0x00C00000)
#define A9_STAT0_smpnamp_o(data)                                                     (0x00C00000&((data)<<22))
#define A9_STAT0_smpnamp_o_src(data)                                                 ((0x00C00000&(data))>>22)
#define A9_STAT0_get_smpnamp_o(data)                                                 ((0x00C00000&(data))>>22)
#define A9_STAT0_evento_o_shift                                                      (21)
#define A9_STAT0_evento_o_mask                                                       (0x00200000)
#define A9_STAT0_evento_o(data)                                                      (0x00200000&((data)<<21))
#define A9_STAT0_evento_o_src(data)                                                  ((0x00200000&(data))>>21)
#define A9_STAT0_get_evento_o(data)                                                  ((0x00200000&(data))>>21)
#define A9_STAT0_scuevabort_o_shift                                                  (20)
#define A9_STAT0_scuevabort_o_mask                                                   (0x00100000)
#define A9_STAT0_scuevabort_o(data)                                                  (0x00100000&((data)<<20))
#define A9_STAT0_scuevabort_o_src(data)                                              ((0x00100000&(data))>>20)
#define A9_STAT0_get_scuevabort_o(data)                                              ((0x00100000&(data))>>20)
#define A9_STAT0_pwrctl1_o_shift                                                     (18)
#define A9_STAT0_pwrctl1_o_mask                                                      (0x000C0000)
#define A9_STAT0_pwrctl1_o(data)                                                     (0x000C0000&((data)<<18))
#define A9_STAT0_pwrctl1_o_src(data)                                                 ((0x000C0000&(data))>>18)
#define A9_STAT0_get_pwrctl1_o(data)                                                 ((0x000C0000&(data))>>18)
#define A9_STAT0_pwrctl0_o_shift                                                     (16)
#define A9_STAT0_pwrctl0_o_mask                                                      (0x00030000)
#define A9_STAT0_pwrctl0_o(data)                                                     (0x00030000&((data)<<16))
#define A9_STAT0_pwrctl0_o_src(data)                                                 ((0x00030000&(data))>>16)
#define A9_STAT0_get_pwrctl0_o(data)                                                 ((0x00030000&(data))>>16)
#define A9_STAT0_deflags1_o_shift                                                    (8)
#define A9_STAT0_deflags1_o_mask                                                     (0x00007F00)
#define A9_STAT0_deflags1_o(data)                                                    (0x00007F00&((data)<<8))
#define A9_STAT0_deflags1_o_src(data)                                                ((0x00007F00&(data))>>8)
#define A9_STAT0_get_deflags1_o(data)                                                ((0x00007F00&(data))>>8)
#define A9_STAT0_deflags0_o_shift                                                    (0)
#define A9_STAT0_deflags0_o_mask                                                     (0x0000007F)
#define A9_STAT0_deflags0_o(data)                                                    (0x0000007F&((data)<<0))
#define A9_STAT0_deflags0_o_src(data)                                                ((0x0000007F&(data))>>0)
#define A9_STAT0_get_deflags0_o(data)                                                ((0x0000007F&(data))>>0)


#define A9_CTRL1                                                                     0x1805C104
#define A9_CTRL1_reg_addr                                                            "0xB805C104"
#define A9_CTRL1_reg                                                                 0xB805C104
#define set_A9_CTRL1_reg(data)   (*((volatile unsigned int*) A9_CTRL1_reg)=data)
#define get_A9_CTRL1_reg   (*((volatile unsigned int*) A9_CTRL1_reg))
#define A9_CTRL1_inst_adr                                                            "0x0041"
#define A9_CTRL1_inst                                                                0x0041
#define A9_CTRL1_eventi_i_shift                                                      (11)
#define A9_CTRL1_eventi_i_mask                                                       (0x00000800)
#define A9_CTRL1_eventi_i(data)                                                      (0x00000800&((data)<<11))
#define A9_CTRL1_eventi_i_src(data)                                                  ((0x00000800&(data))>>11)
#define A9_CTRL1_get_eventi_i(data)                                                  ((0x00000800&(data))>>11)
#define A9_CTRL1_spniden_pl310_i_shift                                               (10)
#define A9_CTRL1_spniden_pl310_i_mask                                                (0x00000400)
#define A9_CTRL1_spniden_pl310_i(data)                                               (0x00000400&((data)<<10))
#define A9_CTRL1_spniden_pl310_i_src(data)                                           ((0x00000400&(data))>>10)
#define A9_CTRL1_get_spniden_pl310_i(data)                                           ((0x00000400&(data))>>10)
#define A9_CTRL1_edbgrq_i_shift                                                      (8)
#define A9_CTRL1_edbgrq_i_mask                                                       (0x00000300)
#define A9_CTRL1_edbgrq_i(data)                                                      (0x00000300&((data)<<8))
#define A9_CTRL1_edbgrq_i_src(data)                                                  ((0x00000300&(data))>>8)
#define A9_CTRL1_get_edbgrq_i(data)                                                  ((0x00000300&(data))>>8)
#define A9_CTRL1_spniden_i_shift                                                     (6)
#define A9_CTRL1_spniden_i_mask                                                      (0x000000C0)
#define A9_CTRL1_spniden_i(data)                                                     (0x000000C0&((data)<<6))
#define A9_CTRL1_spniden_i_src(data)                                                 ((0x000000C0&(data))>>6)
#define A9_CTRL1_get_spniden_i(data)                                                 ((0x000000C0&(data))>>6)
#define A9_CTRL1_spiden_i_shift                                                      (4)
#define A9_CTRL1_spiden_i_mask                                                       (0x00000030)
#define A9_CTRL1_spiden_i(data)                                                      (0x00000030&((data)<<4))
#define A9_CTRL1_spiden_i_src(data)                                                  ((0x00000030&(data))>>4)
#define A9_CTRL1_get_spiden_i(data)                                                  ((0x00000030&(data))>>4)
#define A9_CTRL1_niden_i_shift                                                       (2)
#define A9_CTRL1_niden_i_mask                                                        (0x0000000C)
#define A9_CTRL1_niden_i(data)                                                       (0x0000000C&((data)<<2))
#define A9_CTRL1_niden_i_src(data)                                                   ((0x0000000C&(data))>>2)
#define A9_CTRL1_get_niden_i(data)                                                   ((0x0000000C&(data))>>2)
#define A9_CTRL1_dbgen_i_shift                                                       (0)
#define A9_CTRL1_dbgen_i_mask                                                        (0x00000003)
#define A9_CTRL1_dbgen_i(data)                                                       (0x00000003&((data)<<0))
#define A9_CTRL1_dbgen_i_src(data)                                                   ((0x00000003&(data))>>0)
#define A9_CTRL1_get_dbgen_i(data)                                                   ((0x00000003&(data))>>0)


#define A9_STAT1                                                                     0x1805C108
#define A9_STAT1_reg_addr                                                            "0xB805C108"
#define A9_STAT1_reg                                                                 0xB805C108
#define set_A9_STAT1_reg(data)   (*((volatile unsigned int*) A9_STAT1_reg)=data)
#define get_A9_STAT1_reg   (*((volatile unsigned int*) A9_STAT1_reg))
#define A9_STAT1_inst_adr                                                            "0x0042"
#define A9_STAT1_inst                                                                0x0042
#define A9_STAT1_STANDBYWFE_shift                                                    (2)
#define A9_STAT1_STANDBYWFE_mask                                                     (0x0000000C)
#define A9_STAT1_STANDBYWFE(data)                                                    (0x0000000C&((data)<<2))
#define A9_STAT1_STANDBYWFE_src(data)                                                ((0x0000000C&(data))>>2)
#define A9_STAT1_get_STANDBYWFE(data)                                                ((0x0000000C&(data))>>2)
#define A9_STAT1_STANDBYWFI_shift                                                    (0)
#define A9_STAT1_STANDBYWFI_mask                                                     (0x00000003)
#define A9_STAT1_STANDBYWFI(data)                                                    (0x00000003&((data)<<0))
#define A9_STAT1_STANDBYWFI_src(data)                                                ((0x00000003&(data))>>0)
#define A9_STAT1_get_STANDBYWFI(data)                                                ((0x00000003&(data))>>0)


#define A9_STAT2                                                                     0x1805C10C
#define A9_STAT2_reg_addr                                                            "0xB805C10C"
#define A9_STAT2_reg                                                                 0xB805C10C
#define set_A9_STAT2_reg(data)   (*((volatile unsigned int*) A9_STAT2_reg)=data)
#define get_A9_STAT2_reg   (*((volatile unsigned int*) A9_STAT2_reg))
#define A9_STAT2_inst_adr                                                            "0x0043"
#define A9_STAT2_inst                                                                0x0043
#define A9_STAT2_PMUIRQ_shift                                                        (4)
#define A9_STAT2_PMUIRQ_mask                                                         (0x00000030)
#define A9_STAT2_PMUIRQ(data)                                                        (0x00000030&((data)<<4))
#define A9_STAT2_PMUIRQ_src(data)                                                    ((0x00000030&(data))>>4)
#define A9_STAT2_get_PMUIRQ(data)                                                    ((0x00000030&(data))>>4)
#define A9_STAT2_PMUSECURE_shift                                                     (2)
#define A9_STAT2_PMUSECURE_mask                                                      (0x0000000C)
#define A9_STAT2_PMUSECURE(data)                                                     (0x0000000C&((data)<<2))
#define A9_STAT2_PMUSECURE_src(data)                                                 ((0x0000000C&(data))>>2)
#define A9_STAT2_get_PMUSECURE(data)                                                 ((0x0000000C&(data))>>2)
#define A9_STAT2_PMUPRIV_shift                                                       (0)
#define A9_STAT2_PMUPRIV_mask                                                        (0x00000003)
#define A9_STAT2_PMUPRIV(data)                                                       (0x00000003&((data)<<0))
#define A9_STAT2_PMUPRIV_src(data)                                                   ((0x00000003&(data))>>0)
#define A9_STAT2_get_PMUPRIV(data)                                                   ((0x00000003&(data))>>0)


#define A9_CTRL2                                                                     0x1805C110
#define A9_CTRL2_reg_addr                                                            "0xB805C110"
#define A9_CTRL2_reg                                                                 0xB805C110
#define set_A9_CTRL2_reg(data)   (*((volatile unsigned int*) A9_CTRL2_reg)=data)
#define get_A9_CTRL2_reg   (*((volatile unsigned int*) A9_CTRL2_reg))
#define A9_CTRL2_inst_adr                                                            "0x0044"
#define A9_CTRL2_inst                                                                0x0044
#define A9_CTRL2_cfgsdisable_i_shift                                                 (0)
#define A9_CTRL2_cfgsdisable_i_mask                                                  (0x00000001)
#define A9_CTRL2_cfgsdisable_i(data)                                                 (0x00000001&((data)<<0))
#define A9_CTRL2_cfgsdisable_i_src(data)                                             ((0x00000001&(data))>>0)
#define A9_CTRL2_get_cfgsdisable_i(data)                                             ((0x00000001&(data))>>0)


#define DC_MEM_PROTECT_CTRL                                                          0x1805C300
#define DC_MEM_PROTECT_CTRL_reg_addr                                                 "0xB805C300"
#define DC_MEM_PROTECT_CTRL_reg                                                      0xB805C300
#define set_DC_MEM_PROTECT_CTRL_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_CTRL_reg)=data)
#define get_DC_MEM_PROTECT_CTRL_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_CTRL_reg))
#define DC_MEM_PROTECT_CTRL_inst_adr                                                 "0x00C0"
#define DC_MEM_PROTECT_CTRL_inst                                                     0x00C0
#define DC_MEM_PROTECT_CTRL_protect_3_ena_reg_shift                                  (3)
#define DC_MEM_PROTECT_CTRL_protect_3_ena_reg_mask                                   (0x00000008)
#define DC_MEM_PROTECT_CTRL_protect_3_ena_reg(data)                                  (0x00000008&((data)<<3))
#define DC_MEM_PROTECT_CTRL_protect_3_ena_reg_src(data)                              ((0x00000008&(data))>>3)
#define DC_MEM_PROTECT_CTRL_get_protect_3_ena_reg(data)                              ((0x00000008&(data))>>3)
#define DC_MEM_PROTECT_CTRL_protect_2_ena_reg_shift                                  (2)
#define DC_MEM_PROTECT_CTRL_protect_2_ena_reg_mask                                   (0x00000004)
#define DC_MEM_PROTECT_CTRL_protect_2_ena_reg(data)                                  (0x00000004&((data)<<2))
#define DC_MEM_PROTECT_CTRL_protect_2_ena_reg_src(data)                              ((0x00000004&(data))>>2)
#define DC_MEM_PROTECT_CTRL_get_protect_2_ena_reg(data)                              ((0x00000004&(data))>>2)
#define DC_MEM_PROTECT_CTRL_protect_1_ena_reg_shift                                  (1)
#define DC_MEM_PROTECT_CTRL_protect_1_ena_reg_mask                                   (0x00000002)
#define DC_MEM_PROTECT_CTRL_protect_1_ena_reg(data)                                  (0x00000002&((data)<<1))
#define DC_MEM_PROTECT_CTRL_protect_1_ena_reg_src(data)                              ((0x00000002&(data))>>1)
#define DC_MEM_PROTECT_CTRL_get_protect_1_ena_reg(data)                              ((0x00000002&(data))>>1)
#define DC_MEM_PROTECT_CTRL_protect_0_ena_reg_shift                                  (0)
#define DC_MEM_PROTECT_CTRL_protect_0_ena_reg_mask                                   (0x00000001)
#define DC_MEM_PROTECT_CTRL_protect_0_ena_reg(data)                                  (0x00000001&((data)<<0))
#define DC_MEM_PROTECT_CTRL_protect_0_ena_reg_src(data)                              ((0x00000001&(data))>>0)
#define DC_MEM_PROTECT_CTRL_get_protect_0_ena_reg(data)                              ((0x00000001&(data))>>0)


#define DC_MEM_SCRAMBLE_CTRL                                                         0x1805C304
#define DC_MEM_SCRAMBLE_CTRL_reg_addr                                                "0xB805C304"
#define DC_MEM_SCRAMBLE_CTRL_reg                                                     0xB805C304
#define set_DC_MEM_SCRAMBLE_CTRL_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_CTRL_reg)=data)
#define get_DC_MEM_SCRAMBLE_CTRL_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_CTRL_reg))
#define DC_MEM_SCRAMBLE_CTRL_inst_adr                                                "0x00C1"
#define DC_MEM_SCRAMBLE_CTRL_inst                                                    0x00C1
#define DC_MEM_SCRAMBLE_CTRL_scramble_3_ena_reg_shift                                (3)
#define DC_MEM_SCRAMBLE_CTRL_scramble_3_ena_reg_mask                                 (0x00000008)
#define DC_MEM_SCRAMBLE_CTRL_scramble_3_ena_reg(data)                                (0x00000008&((data)<<3))
#define DC_MEM_SCRAMBLE_CTRL_scramble_3_ena_reg_src(data)                            ((0x00000008&(data))>>3)
#define DC_MEM_SCRAMBLE_CTRL_get_scramble_3_ena_reg(data)                            ((0x00000008&(data))>>3)
#define DC_MEM_SCRAMBLE_CTRL_scramble_2_ena_reg_shift                                (2)
#define DC_MEM_SCRAMBLE_CTRL_scramble_2_ena_reg_mask                                 (0x00000004)
#define DC_MEM_SCRAMBLE_CTRL_scramble_2_ena_reg(data)                                (0x00000004&((data)<<2))
#define DC_MEM_SCRAMBLE_CTRL_scramble_2_ena_reg_src(data)                            ((0x00000004&(data))>>2)
#define DC_MEM_SCRAMBLE_CTRL_get_scramble_2_ena_reg(data)                            ((0x00000004&(data))>>2)
#define DC_MEM_SCRAMBLE_CTRL_scramble_1_ena_reg_shift                                (1)
#define DC_MEM_SCRAMBLE_CTRL_scramble_1_ena_reg_mask                                 (0x00000002)
#define DC_MEM_SCRAMBLE_CTRL_scramble_1_ena_reg(data)                                (0x00000002&((data)<<1))
#define DC_MEM_SCRAMBLE_CTRL_scramble_1_ena_reg_src(data)                            ((0x00000002&(data))>>1)
#define DC_MEM_SCRAMBLE_CTRL_get_scramble_1_ena_reg(data)                            ((0x00000002&(data))>>1)
#define DC_MEM_SCRAMBLE_CTRL_scramble_0_ena_reg_shift                                (0)
#define DC_MEM_SCRAMBLE_CTRL_scramble_0_ena_reg_mask                                 (0x00000001)
#define DC_MEM_SCRAMBLE_CTRL_scramble_0_ena_reg(data)                                (0x00000001&((data)<<0))
#define DC_MEM_SCRAMBLE_CTRL_scramble_0_ena_reg_src(data)                            ((0x00000001&(data))>>0)
#define DC_MEM_SCRAMBLE_CTRL_get_scramble_0_ena_reg(data)                            ((0x00000001&(data))>>0)


#define DC_MEM_PROTECT_SADDR0                                                        0x1805C308
#define DC_MEM_PROTECT_SADDR0_reg_addr                                               "0xB805C308"
#define DC_MEM_PROTECT_SADDR0_reg                                                    0xB805C308
#define set_DC_MEM_PROTECT_SADDR0_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_SADDR0_reg)=data)
#define get_DC_MEM_PROTECT_SADDR0_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_SADDR0_reg))
#define DC_MEM_PROTECT_SADDR0_inst_adr                                               "0x00C2"
#define DC_MEM_PROTECT_SADDR0_inst                                                   0x00C2
#define DC_MEM_PROTECT_SADDR0_mem_protect_saddr_0_shift                              (12)
#define DC_MEM_PROTECT_SADDR0_mem_protect_saddr_0_mask                               (0xFFFFF000)
#define DC_MEM_PROTECT_SADDR0_mem_protect_saddr_0(data)                              (0xFFFFF000&((data)<<12))
#define DC_MEM_PROTECT_SADDR0_mem_protect_saddr_0_src(data)                          ((0xFFFFF000&(data))>>12)
#define DC_MEM_PROTECT_SADDR0_get_mem_protect_saddr_0(data)                          ((0xFFFFF000&(data))>>12)


#define DC_MEM_PROTECT_EADDR0                                                        0x1805C30C
#define DC_MEM_PROTECT_EADDR0_reg_addr                                               "0xB805C30C"
#define DC_MEM_PROTECT_EADDR0_reg                                                    0xB805C30C
#define set_DC_MEM_PROTECT_EADDR0_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_EADDR0_reg)=data)
#define get_DC_MEM_PROTECT_EADDR0_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_EADDR0_reg))
#define DC_MEM_PROTECT_EADDR0_inst_adr                                               "0x00C3"
#define DC_MEM_PROTECT_EADDR0_inst                                                   0x00C3
#define DC_MEM_PROTECT_EADDR0_mem_protect_eaddr_0_shift                              (12)
#define DC_MEM_PROTECT_EADDR0_mem_protect_eaddr_0_mask                               (0xFFFFF000)
#define DC_MEM_PROTECT_EADDR0_mem_protect_eaddr_0(data)                              (0xFFFFF000&((data)<<12))
#define DC_MEM_PROTECT_EADDR0_mem_protect_eaddr_0_src(data)                          ((0xFFFFF000&(data))>>12)
#define DC_MEM_PROTECT_EADDR0_get_mem_protect_eaddr_0(data)                          ((0xFFFFF000&(data))>>12)


#define DC_MEM_PROTECT_SADDR1                                                        0x1805C310
#define DC_MEM_PROTECT_SADDR1_reg_addr                                               "0xB805C310"
#define DC_MEM_PROTECT_SADDR1_reg                                                    0xB805C310
#define set_DC_MEM_PROTECT_SADDR1_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_SADDR1_reg)=data)
#define get_DC_MEM_PROTECT_SADDR1_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_SADDR1_reg))
#define DC_MEM_PROTECT_SADDR1_inst_adr                                               "0x00C4"
#define DC_MEM_PROTECT_SADDR1_inst                                                   0x00C4
#define DC_MEM_PROTECT_SADDR1_mem_protect_saddr_1_shift                              (12)
#define DC_MEM_PROTECT_SADDR1_mem_protect_saddr_1_mask                               (0xFFFFF000)
#define DC_MEM_PROTECT_SADDR1_mem_protect_saddr_1(data)                              (0xFFFFF000&((data)<<12))
#define DC_MEM_PROTECT_SADDR1_mem_protect_saddr_1_src(data)                          ((0xFFFFF000&(data))>>12)
#define DC_MEM_PROTECT_SADDR1_get_mem_protect_saddr_1(data)                          ((0xFFFFF000&(data))>>12)


#define DC_MEM_PROTECT_EADDR1                                                        0x1805C314
#define DC_MEM_PROTECT_EADDR1_reg_addr                                               "0xB805C314"
#define DC_MEM_PROTECT_EADDR1_reg                                                    0xB805C314
#define set_DC_MEM_PROTECT_EADDR1_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_EADDR1_reg)=data)
#define get_DC_MEM_PROTECT_EADDR1_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_EADDR1_reg))
#define DC_MEM_PROTECT_EADDR1_inst_adr                                               "0x00C5"
#define DC_MEM_PROTECT_EADDR1_inst                                                   0x00C5
#define DC_MEM_PROTECT_EADDR1_mem_protect_eaddr_1_shift                              (12)
#define DC_MEM_PROTECT_EADDR1_mem_protect_eaddr_1_mask                               (0xFFFFF000)
#define DC_MEM_PROTECT_EADDR1_mem_protect_eaddr_1(data)                              (0xFFFFF000&((data)<<12))
#define DC_MEM_PROTECT_EADDR1_mem_protect_eaddr_1_src(data)                          ((0xFFFFF000&(data))>>12)
#define DC_MEM_PROTECT_EADDR1_get_mem_protect_eaddr_1(data)                          ((0xFFFFF000&(data))>>12)


#define DC_MEM_PROTECT_SADDR2                                                        0x1805C318
#define DC_MEM_PROTECT_SADDR2_reg_addr                                               "0xB805C318"
#define DC_MEM_PROTECT_SADDR2_reg                                                    0xB805C318
#define set_DC_MEM_PROTECT_SADDR2_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_SADDR2_reg)=data)
#define get_DC_MEM_PROTECT_SADDR2_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_SADDR2_reg))
#define DC_MEM_PROTECT_SADDR2_inst_adr                                               "0x00C6"
#define DC_MEM_PROTECT_SADDR2_inst                                                   0x00C6
#define DC_MEM_PROTECT_SADDR2_mem_protect_saddr_2_shift                              (12)
#define DC_MEM_PROTECT_SADDR2_mem_protect_saddr_2_mask                               (0xFFFFF000)
#define DC_MEM_PROTECT_SADDR2_mem_protect_saddr_2(data)                              (0xFFFFF000&((data)<<12))
#define DC_MEM_PROTECT_SADDR2_mem_protect_saddr_2_src(data)                          ((0xFFFFF000&(data))>>12)
#define DC_MEM_PROTECT_SADDR2_get_mem_protect_saddr_2(data)                          ((0xFFFFF000&(data))>>12)


#define DC_MEM_PROTECT_EADDR2                                                        0x1805C31C
#define DC_MEM_PROTECT_EADDR2_reg_addr                                               "0xB805C31C"
#define DC_MEM_PROTECT_EADDR2_reg                                                    0xB805C31C
#define set_DC_MEM_PROTECT_EADDR2_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_EADDR2_reg)=data)
#define get_DC_MEM_PROTECT_EADDR2_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_EADDR2_reg))
#define DC_MEM_PROTECT_EADDR2_inst_adr                                               "0x00C7"
#define DC_MEM_PROTECT_EADDR2_inst                                                   0x00C7
#define DC_MEM_PROTECT_EADDR2_mem_protect_eaddr_2_shift                              (12)
#define DC_MEM_PROTECT_EADDR2_mem_protect_eaddr_2_mask                               (0xFFFFF000)
#define DC_MEM_PROTECT_EADDR2_mem_protect_eaddr_2(data)                              (0xFFFFF000&((data)<<12))
#define DC_MEM_PROTECT_EADDR2_mem_protect_eaddr_2_src(data)                          ((0xFFFFF000&(data))>>12)
#define DC_MEM_PROTECT_EADDR2_get_mem_protect_eaddr_2(data)                          ((0xFFFFF000&(data))>>12)


#define DC_MEM_PROTECT_SADDR3                                                        0x1805C320
#define DC_MEM_PROTECT_SADDR3_reg_addr                                               "0xB805C320"
#define DC_MEM_PROTECT_SADDR3_reg                                                    0xB805C320
#define set_DC_MEM_PROTECT_SADDR3_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_SADDR3_reg)=data)
#define get_DC_MEM_PROTECT_SADDR3_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_SADDR3_reg))
#define DC_MEM_PROTECT_SADDR3_inst_adr                                               "0x00C8"
#define DC_MEM_PROTECT_SADDR3_inst                                                   0x00C8
#define DC_MEM_PROTECT_SADDR3_mem_protect_saddr_3_shift                              (12)
#define DC_MEM_PROTECT_SADDR3_mem_protect_saddr_3_mask                               (0xFFFFF000)
#define DC_MEM_PROTECT_SADDR3_mem_protect_saddr_3(data)                              (0xFFFFF000&((data)<<12))
#define DC_MEM_PROTECT_SADDR3_mem_protect_saddr_3_src(data)                          ((0xFFFFF000&(data))>>12)
#define DC_MEM_PROTECT_SADDR3_get_mem_protect_saddr_3(data)                          ((0xFFFFF000&(data))>>12)


#define DC_MEM_PROTECT_EADDR3                                                        0x1805C324
#define DC_MEM_PROTECT_EADDR3_reg_addr                                               "0xB805C324"
#define DC_MEM_PROTECT_EADDR3_reg                                                    0xB805C324
#define set_DC_MEM_PROTECT_EADDR3_reg(data)   (*((volatile unsigned int*) DC_MEM_PROTECT_EADDR3_reg)=data)
#define get_DC_MEM_PROTECT_EADDR3_reg   (*((volatile unsigned int*) DC_MEM_PROTECT_EADDR3_reg))
#define DC_MEM_PROTECT_EADDR3_inst_adr                                               "0x00C9"
#define DC_MEM_PROTECT_EADDR3_inst                                                   0x00C9
#define DC_MEM_PROTECT_EADDR3_mem_protect_eaddr_3_shift                              (12)
#define DC_MEM_PROTECT_EADDR3_mem_protect_eaddr_3_mask                               (0xFFFFF000)
#define DC_MEM_PROTECT_EADDR3_mem_protect_eaddr_3(data)                              (0xFFFFF000&((data)<<12))
#define DC_MEM_PROTECT_EADDR3_mem_protect_eaddr_3_src(data)                          ((0xFFFFF000&(data))>>12)
#define DC_MEM_PROTECT_EADDR3_get_mem_protect_eaddr_3(data)                          ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_SADDR0                                                       0x1805C328
#define DC_MEM_SCRAMBLE_SADDR0_reg_addr                                              "0xB805C328"
#define DC_MEM_SCRAMBLE_SADDR0_reg                                                   0xB805C328
#define set_DC_MEM_SCRAMBLE_SADDR0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_SADDR0_reg)=data)
#define get_DC_MEM_SCRAMBLE_SADDR0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_SADDR0_reg))
#define DC_MEM_SCRAMBLE_SADDR0_inst_adr                                              "0x00CA"
#define DC_MEM_SCRAMBLE_SADDR0_inst                                                  0x00CA
#define DC_MEM_SCRAMBLE_SADDR0_mem_scramble_saddr_0_shift                            (12)
#define DC_MEM_SCRAMBLE_SADDR0_mem_scramble_saddr_0_mask                             (0xFFFFF000)
#define DC_MEM_SCRAMBLE_SADDR0_mem_scramble_saddr_0(data)                            (0xFFFFF000&((data)<<12))
#define DC_MEM_SCRAMBLE_SADDR0_mem_scramble_saddr_0_src(data)                        ((0xFFFFF000&(data))>>12)
#define DC_MEM_SCRAMBLE_SADDR0_get_mem_scramble_saddr_0(data)                        ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_EADDR0                                                       0x1805C32C
#define DC_MEM_SCRAMBLE_EADDR0_reg_addr                                              "0xB805C32C"
#define DC_MEM_SCRAMBLE_EADDR0_reg                                                   0xB805C32C
#define set_DC_MEM_SCRAMBLE_EADDR0_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_EADDR0_reg)=data)
#define get_DC_MEM_SCRAMBLE_EADDR0_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_EADDR0_reg))
#define DC_MEM_SCRAMBLE_EADDR0_inst_adr                                              "0x00CB"
#define DC_MEM_SCRAMBLE_EADDR0_inst                                                  0x00CB
#define DC_MEM_SCRAMBLE_EADDR0_mem_scramble_eaddr_0_shift                            (12)
#define DC_MEM_SCRAMBLE_EADDR0_mem_scramble_eaddr_0_mask                             (0xFFFFF000)
#define DC_MEM_SCRAMBLE_EADDR0_mem_scramble_eaddr_0(data)                            (0xFFFFF000&((data)<<12))
#define DC_MEM_SCRAMBLE_EADDR0_mem_scramble_eaddr_0_src(data)                        ((0xFFFFF000&(data))>>12)
#define DC_MEM_SCRAMBLE_EADDR0_get_mem_scramble_eaddr_0(data)                        ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_SADDR1                                                       0x1805C330
#define DC_MEM_SCRAMBLE_SADDR1_reg_addr                                              "0xB805C330"
#define DC_MEM_SCRAMBLE_SADDR1_reg                                                   0xB805C330
#define set_DC_MEM_SCRAMBLE_SADDR1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_SADDR1_reg)=data)
#define get_DC_MEM_SCRAMBLE_SADDR1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_SADDR1_reg))
#define DC_MEM_SCRAMBLE_SADDR1_inst_adr                                              "0x00CC"
#define DC_MEM_SCRAMBLE_SADDR1_inst                                                  0x00CC
#define DC_MEM_SCRAMBLE_SADDR1_mem_scramble_saddr_1_shift                            (12)
#define DC_MEM_SCRAMBLE_SADDR1_mem_scramble_saddr_1_mask                             (0xFFFFF000)
#define DC_MEM_SCRAMBLE_SADDR1_mem_scramble_saddr_1(data)                            (0xFFFFF000&((data)<<12))
#define DC_MEM_SCRAMBLE_SADDR1_mem_scramble_saddr_1_src(data)                        ((0xFFFFF000&(data))>>12)
#define DC_MEM_SCRAMBLE_SADDR1_get_mem_scramble_saddr_1(data)                        ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_EADDR1                                                       0x1805C334
#define DC_MEM_SCRAMBLE_EADDR1_reg_addr                                              "0xB805C334"
#define DC_MEM_SCRAMBLE_EADDR1_reg                                                   0xB805C334
#define set_DC_MEM_SCRAMBLE_EADDR1_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_EADDR1_reg)=data)
#define get_DC_MEM_SCRAMBLE_EADDR1_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_EADDR1_reg))
#define DC_MEM_SCRAMBLE_EADDR1_inst_adr                                              "0x00CD"
#define DC_MEM_SCRAMBLE_EADDR1_inst                                                  0x00CD
#define DC_MEM_SCRAMBLE_EADDR1_mem_scramble_eaddr_1_shift                            (12)
#define DC_MEM_SCRAMBLE_EADDR1_mem_scramble_eaddr_1_mask                             (0xFFFFF000)
#define DC_MEM_SCRAMBLE_EADDR1_mem_scramble_eaddr_1(data)                            (0xFFFFF000&((data)<<12))
#define DC_MEM_SCRAMBLE_EADDR1_mem_scramble_eaddr_1_src(data)                        ((0xFFFFF000&(data))>>12)
#define DC_MEM_SCRAMBLE_EADDR1_get_mem_scramble_eaddr_1(data)                        ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_SADDR2                                                       0x1805C338
#define DC_MEM_SCRAMBLE_SADDR2_reg_addr                                              "0xB805C338"
#define DC_MEM_SCRAMBLE_SADDR2_reg                                                   0xB805C338
#define set_DC_MEM_SCRAMBLE_SADDR2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_SADDR2_reg)=data)
#define get_DC_MEM_SCRAMBLE_SADDR2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_SADDR2_reg))
#define DC_MEM_SCRAMBLE_SADDR2_inst_adr                                              "0x00CE"
#define DC_MEM_SCRAMBLE_SADDR2_inst                                                  0x00CE
#define DC_MEM_SCRAMBLE_SADDR2_mem_scramble_saddr_2_shift                            (12)
#define DC_MEM_SCRAMBLE_SADDR2_mem_scramble_saddr_2_mask                             (0xFFFFF000)
#define DC_MEM_SCRAMBLE_SADDR2_mem_scramble_saddr_2(data)                            (0xFFFFF000&((data)<<12))
#define DC_MEM_SCRAMBLE_SADDR2_mem_scramble_saddr_2_src(data)                        ((0xFFFFF000&(data))>>12)
#define DC_MEM_SCRAMBLE_SADDR2_get_mem_scramble_saddr_2(data)                        ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_EADDR2                                                       0x1805C33C
#define DC_MEM_SCRAMBLE_EADDR2_reg_addr                                              "0xB805C33C"
#define DC_MEM_SCRAMBLE_EADDR2_reg                                                   0xB805C33C
#define set_DC_MEM_SCRAMBLE_EADDR2_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_EADDR2_reg)=data)
#define get_DC_MEM_SCRAMBLE_EADDR2_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_EADDR2_reg))
#define DC_MEM_SCRAMBLE_EADDR2_inst_adr                                              "0x00CF"
#define DC_MEM_SCRAMBLE_EADDR2_inst                                                  0x00CF
#define DC_MEM_SCRAMBLE_EADDR2_mem_scramble_eaddr_2_shift                            (12)
#define DC_MEM_SCRAMBLE_EADDR2_mem_scramble_eaddr_2_mask                             (0xFFFFF000)
#define DC_MEM_SCRAMBLE_EADDR2_mem_scramble_eaddr_2(data)                            (0xFFFFF000&((data)<<12))
#define DC_MEM_SCRAMBLE_EADDR2_mem_scramble_eaddr_2_src(data)                        ((0xFFFFF000&(data))>>12)
#define DC_MEM_SCRAMBLE_EADDR2_get_mem_scramble_eaddr_2(data)                        ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_SADDR3                                                       0x1805C340
#define DC_MEM_SCRAMBLE_SADDR3_reg_addr                                              "0xB805C340"
#define DC_MEM_SCRAMBLE_SADDR3_reg                                                   0xB805C340
#define set_DC_MEM_SCRAMBLE_SADDR3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_SADDR3_reg)=data)
#define get_DC_MEM_SCRAMBLE_SADDR3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_SADDR3_reg))
#define DC_MEM_SCRAMBLE_SADDR3_inst_adr                                              "0x00D0"
#define DC_MEM_SCRAMBLE_SADDR3_inst                                                  0x00D0
#define DC_MEM_SCRAMBLE_SADDR3_mem_scramble_saddr_3_shift                            (12)
#define DC_MEM_SCRAMBLE_SADDR3_mem_scramble_saddr_3_mask                             (0xFFFFF000)
#define DC_MEM_SCRAMBLE_SADDR3_mem_scramble_saddr_3(data)                            (0xFFFFF000&((data)<<12))
#define DC_MEM_SCRAMBLE_SADDR3_mem_scramble_saddr_3_src(data)                        ((0xFFFFF000&(data))>>12)
#define DC_MEM_SCRAMBLE_SADDR3_get_mem_scramble_saddr_3(data)                        ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_EADDR3                                                       0x1805C344
#define DC_MEM_SCRAMBLE_EADDR3_reg_addr                                              "0xB805C344"
#define DC_MEM_SCRAMBLE_EADDR3_reg                                                   0xB805C344
#define set_DC_MEM_SCRAMBLE_EADDR3_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_EADDR3_reg)=data)
#define get_DC_MEM_SCRAMBLE_EADDR3_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_EADDR3_reg))
#define DC_MEM_SCRAMBLE_EADDR3_inst_adr                                              "0x00D1"
#define DC_MEM_SCRAMBLE_EADDR3_inst                                                  0x00D1
#define DC_MEM_SCRAMBLE_EADDR3_mem_scramble_eaddr_3_shift                            (12)
#define DC_MEM_SCRAMBLE_EADDR3_mem_scramble_eaddr_3_mask                             (0xFFFFF000)
#define DC_MEM_SCRAMBLE_EADDR3_mem_scramble_eaddr_3(data)                            (0xFFFFF000&((data)<<12))
#define DC_MEM_SCRAMBLE_EADDR3_mem_scramble_eaddr_3_src(data)                        ((0xFFFFF000&(data))>>12)
#define DC_MEM_SCRAMBLE_EADDR3_get_mem_scramble_eaddr_3(data)                        ((0xFFFFF000&(data))>>12)


#define DC_MEM_SCRAMBLE_CTRL                                                         0x1805C3A8
#define DC_MEM_SCRAMBLE_CTRL_reg_addr                                                "0xB805C3A8"
#define DC_MEM_SCRAMBLE_CTRL_reg                                                     0xB805C3A8
#define set_DC_MEM_SCRAMBLE_CTRL_reg(data)   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_CTRL_reg)=data)
#define get_DC_MEM_SCRAMBLE_CTRL_reg   (*((volatile unsigned int*) DC_MEM_SCRAMBLE_CTRL_reg))
#define DC_MEM_SCRAMBLE_CTRL_inst_adr                                                "0x00EA"
#define DC_MEM_SCRAMBLE_CTRL_inst                                                    0x00EA
#define DC_MEM_SCRAMBLE_CTRL_scpu_scramble_en_shift                                  (0)
#define DC_MEM_SCRAMBLE_CTRL_scpu_scramble_en_mask                                   (0x00000001)
#define DC_MEM_SCRAMBLE_CTRL_scpu_scramble_en(data)                                  (0x00000001&((data)<<0))
#define DC_MEM_SCRAMBLE_CTRL_scpu_scramble_en_src(data)                              ((0x00000001&(data))>>0)
#define DC_MEM_SCRAMBLE_CTRL_get_scpu_scramble_en(data)                              ((0x00000001&(data))>>0)


#define DBG_START_M0_0                                                               0x1805C400
#define DBG_START_M0_1                                                               0x1805C404
#define DBG_START_M0_2                                                               0x1805C408
#define DBG_START_M0_3                                                               0x1805C40C
#define DBG_START_M0_0_reg_addr                                                      "0xB805C400"
#define DBG_START_M0_1_reg_addr                                                      "0xB805C404"
#define DBG_START_M0_2_reg_addr                                                      "0xB805C408"
#define DBG_START_M0_3_reg_addr                                                      "0xB805C40C"
#define DBG_START_M0_0_reg                                                           0xB805C400
#define DBG_START_M0_1_reg                                                           0xB805C404
#define DBG_START_M0_2_reg                                                           0xB805C408
#define DBG_START_M0_3_reg                                                           0xB805C40C
#define set_DBG_START_M0_0_reg(data)   (*((volatile unsigned int*) DBG_START_M0_0_reg)=data)
#define set_DBG_START_M0_1_reg(data)   (*((volatile unsigned int*) DBG_START_M0_1_reg)=data)
#define set_DBG_START_M0_2_reg(data)   (*((volatile unsigned int*) DBG_START_M0_2_reg)=data)
#define set_DBG_START_M0_3_reg(data)   (*((volatile unsigned int*) DBG_START_M0_3_reg)=data)
#define get_DBG_START_M0_0_reg   (*((volatile unsigned int*) DBG_START_M0_0_reg))
#define get_DBG_START_M0_1_reg   (*((volatile unsigned int*) DBG_START_M0_1_reg))
#define get_DBG_START_M0_2_reg   (*((volatile unsigned int*) DBG_START_M0_2_reg))
#define get_DBG_START_M0_3_reg   (*((volatile unsigned int*) DBG_START_M0_3_reg))
#define DBG_START_M0_0_inst_adr                                                      "0x0000"
#define DBG_START_M0_1_inst_adr                                                      "0x0001"
#define DBG_START_M0_2_inst_adr                                                      "0x0002"
#define DBG_START_M0_3_inst_adr                                                      "0x0003"
#define DBG_START_M0_0_inst                                                          0x0000
#define DBG_START_M0_1_inst                                                          0x0001
#define DBG_START_M0_2_inst                                                          0x0002
#define DBG_START_M0_3_inst                                                          0x0003
#define DBG_START_M0_dbg_start_addr_m0_shift                                         (0)
#define DBG_START_M0_dbg_start_addr_m0_mask                                          (0xFFFFFFFF)
#define DBG_START_M0_dbg_start_addr_m0(data)                                         (0xFFFFFFFF&((data)<<0))
#define DBG_START_M0_dbg_start_addr_m0_src(data)                                     ((0xFFFFFFFF&(data))>>0)
#define DBG_START_M0_get_dbg_start_addr_m0(data)                                     ((0xFFFFFFFF&(data))>>0)


#define DBG_END_M0_0                                                                 0x1805C410
#define DBG_END_M0_1                                                                 0x1805C414
#define DBG_END_M0_2                                                                 0x1805C418
#define DBG_END_M0_3                                                                 0x1805C41C
#define DBG_END_M0_0_reg_addr                                                        "0xB805C410"
#define DBG_END_M0_1_reg_addr                                                        "0xB805C414"
#define DBG_END_M0_2_reg_addr                                                        "0xB805C418"
#define DBG_END_M0_3_reg_addr                                                        "0xB805C41C"
#define DBG_END_M0_0_reg                                                             0xB805C410
#define DBG_END_M0_1_reg                                                             0xB805C414
#define DBG_END_M0_2_reg                                                             0xB805C418
#define DBG_END_M0_3_reg                                                             0xB805C41C
#define set_DBG_END_M0_0_reg(data)   (*((volatile unsigned int*) DBG_END_M0_0_reg)=data)
#define set_DBG_END_M0_1_reg(data)   (*((volatile unsigned int*) DBG_END_M0_1_reg)=data)
#define set_DBG_END_M0_2_reg(data)   (*((volatile unsigned int*) DBG_END_M0_2_reg)=data)
#define set_DBG_END_M0_3_reg(data)   (*((volatile unsigned int*) DBG_END_M0_3_reg)=data)
#define get_DBG_END_M0_0_reg   (*((volatile unsigned int*) DBG_END_M0_0_reg))
#define get_DBG_END_M0_1_reg   (*((volatile unsigned int*) DBG_END_M0_1_reg))
#define get_DBG_END_M0_2_reg   (*((volatile unsigned int*) DBG_END_M0_2_reg))
#define get_DBG_END_M0_3_reg   (*((volatile unsigned int*) DBG_END_M0_3_reg))
#define DBG_END_M0_0_inst_adr                                                        "0x0004"
#define DBG_END_M0_1_inst_adr                                                        "0x0005"
#define DBG_END_M0_2_inst_adr                                                        "0x0006"
#define DBG_END_M0_3_inst_adr                                                        "0x0007"
#define DBG_END_M0_0_inst                                                            0x0004
#define DBG_END_M0_1_inst                                                            0x0005
#define DBG_END_M0_2_inst                                                            0x0006
#define DBG_END_M0_3_inst                                                            0x0007
#define DBG_END_M0_dbg_end_addr_m0_shift                                             (0)
#define DBG_END_M0_dbg_end_addr_m0_mask                                              (0xFFFFFFFF)
#define DBG_END_M0_dbg_end_addr_m0(data)                                             (0xFFFFFFFF&((data)<<0))
#define DBG_END_M0_dbg_end_addr_m0_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define DBG_END_M0_get_dbg_end_addr_m0(data)                                         ((0xFFFFFFFF&(data))>>0)


#define DBG_CTRL_M0_0                                                                0x1805C420
#define DBG_CTRL_M0_1                                                                0x1805C424
#define DBG_CTRL_M0_2                                                                0x1805C428
#define DBG_CTRL_M0_3                                                                0x1805C42C
#define DBG_CTRL_M0_0_reg_addr                                                       "0xB805C420"
#define DBG_CTRL_M0_1_reg_addr                                                       "0xB805C424"
#define DBG_CTRL_M0_2_reg_addr                                                       "0xB805C428"
#define DBG_CTRL_M0_3_reg_addr                                                       "0xB805C42C"
#define DBG_CTRL_M0_0_reg                                                            0xB805C420
#define DBG_CTRL_M0_1_reg                                                            0xB805C424
#define DBG_CTRL_M0_2_reg                                                            0xB805C428
#define DBG_CTRL_M0_3_reg                                                            0xB805C42C
#define set_DBG_CTRL_M0_0_reg(data)   (*((volatile unsigned int*) DBG_CTRL_M0_0_reg)=data)
#define set_DBG_CTRL_M0_1_reg(data)   (*((volatile unsigned int*) DBG_CTRL_M0_1_reg)=data)
#define set_DBG_CTRL_M0_2_reg(data)   (*((volatile unsigned int*) DBG_CTRL_M0_2_reg)=data)
#define set_DBG_CTRL_M0_3_reg(data)   (*((volatile unsigned int*) DBG_CTRL_M0_3_reg)=data)
#define get_DBG_CTRL_M0_0_reg   (*((volatile unsigned int*) DBG_CTRL_M0_0_reg))
#define get_DBG_CTRL_M0_1_reg   (*((volatile unsigned int*) DBG_CTRL_M0_1_reg))
#define get_DBG_CTRL_M0_2_reg   (*((volatile unsigned int*) DBG_CTRL_M0_2_reg))
#define get_DBG_CTRL_M0_3_reg   (*((volatile unsigned int*) DBG_CTRL_M0_3_reg))
#define DBG_CTRL_M0_0_inst_adr                                                       "0x0008"
#define DBG_CTRL_M0_1_inst_adr                                                       "0x0009"
#define DBG_CTRL_M0_2_inst_adr                                                       "0x000A"
#define DBG_CTRL_M0_3_inst_adr                                                       "0x000B"
#define DBG_CTRL_M0_0_inst                                                           0x0008
#define DBG_CTRL_M0_1_inst                                                           0x0009
#define DBG_CTRL_M0_2_inst                                                           0x000A
#define DBG_CTRL_M0_3_inst                                                           0x000B
#define DBG_CTRL_M0_write_en2_shift                                                  (4)
#define DBG_CTRL_M0_write_en2_mask                                                   (0x00000010)
#define DBG_CTRL_M0_write_en2(data)                                                  (0x00000010&((data)<<4))
#define DBG_CTRL_M0_write_en2_src(data)                                              ((0x00000010&(data))>>4)
#define DBG_CTRL_M0_get_write_en2(data)                                              ((0x00000010&(data))>>4)
#define DBG_CTRL_M0_dbg_wr_chk_m0_shift                                              (2)
#define DBG_CTRL_M0_dbg_wr_chk_m0_mask                                               (0x0000000C)
#define DBG_CTRL_M0_dbg_wr_chk_m0(data)                                              (0x0000000C&((data)<<2))
#define DBG_CTRL_M0_dbg_wr_chk_m0_src(data)                                          ((0x0000000C&(data))>>2)
#define DBG_CTRL_M0_get_dbg_wr_chk_m0(data)                                          ((0x0000000C&(data))>>2)
#define DBG_CTRL_M0_write_en1_shift                                                  (1)
#define DBG_CTRL_M0_write_en1_mask                                                   (0x00000002)
#define DBG_CTRL_M0_write_en1(data)                                                  (0x00000002&((data)<<1))
#define DBG_CTRL_M0_write_en1_src(data)                                              ((0x00000002&(data))>>1)
#define DBG_CTRL_M0_get_write_en1(data)                                              ((0x00000002&(data))>>1)
#define DBG_CTRL_M0_dbg_en_m0_shift                                                  (0)
#define DBG_CTRL_M0_dbg_en_m0_mask                                                   (0x00000001)
#define DBG_CTRL_M0_dbg_en_m0(data)                                                  (0x00000001&((data)<<0))
#define DBG_CTRL_M0_dbg_en_m0_src(data)                                              ((0x00000001&(data))>>0)
#define DBG_CTRL_M0_get_dbg_en_m0(data)                                              ((0x00000001&(data))>>0)


#define DBG_INT_M0                                                                   0x1805C430
#define DBG_INT_M0_reg_addr                                                          "0xB805C430"
#define DBG_INT_M0_reg                                                               0xB805C430
#define set_DBG_INT_M0_reg(data)   (*((volatile unsigned int*) DBG_INT_M0_reg)=data)
#define get_DBG_INT_M0_reg   (*((volatile unsigned int*) DBG_INT_M0_reg))
#define DBG_INT_M0_inst_adr                                                          "0x000C"
#define DBG_INT_M0_inst                                                              0x000C
#define DBG_INT_M0_scpu_int_m0_shift                                                 (4)
#define DBG_INT_M0_scpu_int_m0_mask                                                  (0x00000010)
#define DBG_INT_M0_scpu_int_m0(data)                                                 (0x00000010&((data)<<4))
#define DBG_INT_M0_scpu_int_m0_src(data)                                             ((0x00000010&(data))>>4)
#define DBG_INT_M0_get_scpu_int_m0(data)                                             ((0x00000010&(data))>>4)
#define DBG_INT_M0_scpu_int_en_m0_shift                                              (3)
#define DBG_INT_M0_scpu_int_en_m0_mask                                               (0x00000008)
#define DBG_INT_M0_scpu_int_en_m0(data)                                              (0x00000008&((data)<<3))
#define DBG_INT_M0_scpu_int_en_m0_src(data)                                          ((0x00000008&(data))>>3)
#define DBG_INT_M0_get_scpu_int_en_m0(data)                                          ((0x00000008&(data))>>3)
#define DBG_INT_M0_scpu_neg_int_m0_shift                                             (2)
#define DBG_INT_M0_scpu_neg_int_m0_mask                                              (0x00000004)
#define DBG_INT_M0_scpu_neg_int_m0(data)                                             (0x00000004&((data)<<2))
#define DBG_INT_M0_scpu_neg_int_m0_src(data)                                         ((0x00000004&(data))>>2)
#define DBG_INT_M0_get_scpu_neg_int_m0(data)                                         ((0x00000004&(data))>>2)
#define DBG_INT_M0_scpu_neg_int_en_m0_shift                                          (1)
#define DBG_INT_M0_scpu_neg_int_en_m0_mask                                           (0x00000002)
#define DBG_INT_M0_scpu_neg_int_en_m0(data)                                          (0x00000002&((data)<<1))
#define DBG_INT_M0_scpu_neg_int_en_m0_src(data)                                      ((0x00000002&(data))>>1)
#define DBG_INT_M0_get_scpu_neg_int_en_m0(data)                                      ((0x00000002&(data))>>1)
#define DBG_INT_M0_write_data_shift                                                  (0)
#define DBG_INT_M0_write_data_mask                                                   (0x00000001)
#define DBG_INT_M0_write_data(data)                                                  (0x00000001&((data)<<0))
#define DBG_INT_M0_write_data_src(data)                                              ((0x00000001&(data))>>0)
#define DBG_INT_M0_get_write_data(data)                                              ((0x00000001&(data))>>0)


#define DBG_ADDR_M0                                                                  0x1805C434
#define DBG_ADDR_M0_reg_addr                                                         "0xB805C434"
#define DBG_ADDR_M0_reg                                                              0xB805C434
#define set_DBG_ADDR_M0_reg(data)   (*((volatile unsigned int*) DBG_ADDR_M0_reg)=data)
#define get_DBG_ADDR_M0_reg   (*((volatile unsigned int*) DBG_ADDR_M0_reg))
#define DBG_ADDR_M0_inst_adr                                                         "0x000D"
#define DBG_ADDR_M0_inst                                                             0x000D
#define DBG_ADDR_M0_dbg_addr_m0_shift                                                (0)
#define DBG_ADDR_M0_dbg_addr_m0_mask                                                 (0xFFFFFFFF)
#define DBG_ADDR_M0_dbg_addr_m0(data)                                                (0xFFFFFFFF&((data)<<0))
#define DBG_ADDR_M0_dbg_addr_m0_src(data)                                            ((0xFFFFFFFF&(data))>>0)
#define DBG_ADDR_M0_get_dbg_addr_m0(data)                                            ((0xFFFFFFFF&(data))>>0)


#define DBG_ADDR1_M0                                                                 0x1805C438
#define DBG_ADDR1_M0_reg_addr                                                        "0xB805C438"
#define DBG_ADDR1_M0_reg                                                             0xB805C438
#define set_DBG_ADDR1_M0_reg(data)   (*((volatile unsigned int*) DBG_ADDR1_M0_reg)=data)
#define get_DBG_ADDR1_M0_reg   (*((volatile unsigned int*) DBG_ADDR1_M0_reg))
#define DBG_ADDR1_M0_inst_adr                                                        "0x000E"
#define DBG_ADDR1_M0_inst                                                            0x000E
#define DBG_ADDR1_M0_scpu_dbg_write_m0_shift                                         (0)
#define DBG_ADDR1_M0_scpu_dbg_write_m0_mask                                          (0x00000001)
#define DBG_ADDR1_M0_scpu_dbg_write_m0(data)                                         (0x00000001&((data)<<0))
#define DBG_ADDR1_M0_scpu_dbg_write_m0_src(data)                                     ((0x00000001&(data))>>0)
#define DBG_ADDR1_M0_get_scpu_dbg_write_m0(data)                                     ((0x00000001&(data))>>0)


#define DBG_START_M1_0                                                               0x1805C440
#define DBG_START_M1_1                                                               0x1805C444
#define DBG_START_M1_2                                                               0x1805C448
#define DBG_START_M1_3                                                               0x1805C44C
#define DBG_START_M1_0_reg_addr                                                      "0xB805C440"
#define DBG_START_M1_1_reg_addr                                                      "0xB805C444"
#define DBG_START_M1_2_reg_addr                                                      "0xB805C448"
#define DBG_START_M1_3_reg_addr                                                      "0xB805C44C"
#define DBG_START_M1_0_reg                                                           0xB805C440
#define DBG_START_M1_1_reg                                                           0xB805C444
#define DBG_START_M1_2_reg                                                           0xB805C448
#define DBG_START_M1_3_reg                                                           0xB805C44C
#define set_DBG_START_M1_0_reg(data)   (*((volatile unsigned int*) DBG_START_M1_0_reg)=data)
#define set_DBG_START_M1_1_reg(data)   (*((volatile unsigned int*) DBG_START_M1_1_reg)=data)
#define set_DBG_START_M1_2_reg(data)   (*((volatile unsigned int*) DBG_START_M1_2_reg)=data)
#define set_DBG_START_M1_3_reg(data)   (*((volatile unsigned int*) DBG_START_M1_3_reg)=data)
#define get_DBG_START_M1_0_reg   (*((volatile unsigned int*) DBG_START_M1_0_reg))
#define get_DBG_START_M1_1_reg   (*((volatile unsigned int*) DBG_START_M1_1_reg))
#define get_DBG_START_M1_2_reg   (*((volatile unsigned int*) DBG_START_M1_2_reg))
#define get_DBG_START_M1_3_reg   (*((volatile unsigned int*) DBG_START_M1_3_reg))
#define DBG_START_M1_0_inst_adr                                                      "0x0010"
#define DBG_START_M1_1_inst_adr                                                      "0x0011"
#define DBG_START_M1_2_inst_adr                                                      "0x0012"
#define DBG_START_M1_3_inst_adr                                                      "0x0013"
#define DBG_START_M1_0_inst                                                          0x0010
#define DBG_START_M1_1_inst                                                          0x0011
#define DBG_START_M1_2_inst                                                          0x0012
#define DBG_START_M1_3_inst                                                          0x0013
#define DBG_START_M1_dbg_start_addr_m1_shift                                         (0)
#define DBG_START_M1_dbg_start_addr_m1_mask                                          (0xFFFFFFFF)
#define DBG_START_M1_dbg_start_addr_m1(data)                                         (0xFFFFFFFF&((data)<<0))
#define DBG_START_M1_dbg_start_addr_m1_src(data)                                     ((0xFFFFFFFF&(data))>>0)
#define DBG_START_M1_get_dbg_start_addr_m1(data)                                     ((0xFFFFFFFF&(data))>>0)


#define DBG_END_M1_0                                                                 0x1805C450
#define DBG_END_M1_1                                                                 0x1805C454
#define DBG_END_M1_2                                                                 0x1805C458
#define DBG_END_M1_3                                                                 0x1805C45C
#define DBG_END_M1_0_reg_addr                                                        "0xB805C450"
#define DBG_END_M1_1_reg_addr                                                        "0xB805C454"
#define DBG_END_M1_2_reg_addr                                                        "0xB805C458"
#define DBG_END_M1_3_reg_addr                                                        "0xB805C45C"
#define DBG_END_M1_0_reg                                                             0xB805C450
#define DBG_END_M1_1_reg                                                             0xB805C454
#define DBG_END_M1_2_reg                                                             0xB805C458
#define DBG_END_M1_3_reg                                                             0xB805C45C
#define set_DBG_END_M1_0_reg(data)   (*((volatile unsigned int*) DBG_END_M1_0_reg)=data)
#define set_DBG_END_M1_1_reg(data)   (*((volatile unsigned int*) DBG_END_M1_1_reg)=data)
#define set_DBG_END_M1_2_reg(data)   (*((volatile unsigned int*) DBG_END_M1_2_reg)=data)
#define set_DBG_END_M1_3_reg(data)   (*((volatile unsigned int*) DBG_END_M1_3_reg)=data)
#define get_DBG_END_M1_0_reg   (*((volatile unsigned int*) DBG_END_M1_0_reg))
#define get_DBG_END_M1_1_reg   (*((volatile unsigned int*) DBG_END_M1_1_reg))
#define get_DBG_END_M1_2_reg   (*((volatile unsigned int*) DBG_END_M1_2_reg))
#define get_DBG_END_M1_3_reg   (*((volatile unsigned int*) DBG_END_M1_3_reg))
#define DBG_END_M1_0_inst_adr                                                        "0x0014"
#define DBG_END_M1_1_inst_adr                                                        "0x0015"
#define DBG_END_M1_2_inst_adr                                                        "0x0016"
#define DBG_END_M1_3_inst_adr                                                        "0x0017"
#define DBG_END_M1_0_inst                                                            0x0014
#define DBG_END_M1_1_inst                                                            0x0015
#define DBG_END_M1_2_inst                                                            0x0016
#define DBG_END_M1_3_inst                                                            0x0017
#define DBG_END_M1_dbg_end_addr_m1_shift                                             (0)
#define DBG_END_M1_dbg_end_addr_m1_mask                                              (0xFFFFFFFF)
#define DBG_END_M1_dbg_end_addr_m1(data)                                             (0xFFFFFFFF&((data)<<0))
#define DBG_END_M1_dbg_end_addr_m1_src(data)                                         ((0xFFFFFFFF&(data))>>0)
#define DBG_END_M1_get_dbg_end_addr_m1(data)                                         ((0xFFFFFFFF&(data))>>0)


#define DBG_CTRL_M1_0                                                                0x1805C460
#define DBG_CTRL_M1_1                                                                0x1805C464
#define DBG_CTRL_M1_2                                                                0x1805C468
#define DBG_CTRL_M1_3                                                                0x1805C46C
#define DBG_CTRL_M1_0_reg_addr                                                       "0xB805C460"
#define DBG_CTRL_M1_1_reg_addr                                                       "0xB805C464"
#define DBG_CTRL_M1_2_reg_addr                                                       "0xB805C468"
#define DBG_CTRL_M1_3_reg_addr                                                       "0xB805C46C"
#define DBG_CTRL_M1_0_reg                                                            0xB805C460
#define DBG_CTRL_M1_1_reg                                                            0xB805C464
#define DBG_CTRL_M1_2_reg                                                            0xB805C468
#define DBG_CTRL_M1_3_reg                                                            0xB805C46C
#define set_DBG_CTRL_M1_0_reg(data)   (*((volatile unsigned int*) DBG_CTRL_M1_0_reg)=data)
#define set_DBG_CTRL_M1_1_reg(data)   (*((volatile unsigned int*) DBG_CTRL_M1_1_reg)=data)
#define set_DBG_CTRL_M1_2_reg(data)   (*((volatile unsigned int*) DBG_CTRL_M1_2_reg)=data)
#define set_DBG_CTRL_M1_3_reg(data)   (*((volatile unsigned int*) DBG_CTRL_M1_3_reg)=data)
#define get_DBG_CTRL_M1_0_reg   (*((volatile unsigned int*) DBG_CTRL_M1_0_reg))
#define get_DBG_CTRL_M1_1_reg   (*((volatile unsigned int*) DBG_CTRL_M1_1_reg))
#define get_DBG_CTRL_M1_2_reg   (*((volatile unsigned int*) DBG_CTRL_M1_2_reg))
#define get_DBG_CTRL_M1_3_reg   (*((volatile unsigned int*) DBG_CTRL_M1_3_reg))
#define DBG_CTRL_M1_0_inst_adr                                                       "0x0018"
#define DBG_CTRL_M1_1_inst_adr                                                       "0x0019"
#define DBG_CTRL_M1_2_inst_adr                                                       "0x001A"
#define DBG_CTRL_M1_3_inst_adr                                                       "0x001B"
#define DBG_CTRL_M1_0_inst                                                           0x0018
#define DBG_CTRL_M1_1_inst                                                           0x0019
#define DBG_CTRL_M1_2_inst                                                           0x001A
#define DBG_CTRL_M1_3_inst                                                           0x001B
#define DBG_CTRL_M1_write_en2_shift                                                  (4)
#define DBG_CTRL_M1_write_en2_mask                                                   (0x00000010)
#define DBG_CTRL_M1_write_en2(data)                                                  (0x00000010&((data)<<4))
#define DBG_CTRL_M1_write_en2_src(data)                                              ((0x00000010&(data))>>4)
#define DBG_CTRL_M1_get_write_en2(data)                                              ((0x00000010&(data))>>4)
#define DBG_CTRL_M1_dbg_wr_chk_m1_shift                                              (2)
#define DBG_CTRL_M1_dbg_wr_chk_m1_mask                                               (0x0000000C)
#define DBG_CTRL_M1_dbg_wr_chk_m1(data)                                              (0x0000000C&((data)<<2))
#define DBG_CTRL_M1_dbg_wr_chk_m1_src(data)                                          ((0x0000000C&(data))>>2)
#define DBG_CTRL_M1_get_dbg_wr_chk_m1(data)                                          ((0x0000000C&(data))>>2)
#define DBG_CTRL_M1_write_en1_shift                                                  (1)
#define DBG_CTRL_M1_write_en1_mask                                                   (0x00000002)
#define DBG_CTRL_M1_write_en1(data)                                                  (0x00000002&((data)<<1))
#define DBG_CTRL_M1_write_en1_src(data)                                              ((0x00000002&(data))>>1)
#define DBG_CTRL_M1_get_write_en1(data)                                              ((0x00000002&(data))>>1)
#define DBG_CTRL_M1_dbg_en_m1_shift                                                  (0)
#define DBG_CTRL_M1_dbg_en_m1_mask                                                   (0x00000001)
#define DBG_CTRL_M1_dbg_en_m1(data)                                                  (0x00000001&((data)<<0))
#define DBG_CTRL_M1_dbg_en_m1_src(data)                                              ((0x00000001&(data))>>0)
#define DBG_CTRL_M1_get_dbg_en_m1(data)                                              ((0x00000001&(data))>>0)


#define DBG_INT_M1                                                                   0x1805C470
#define DBG_INT_M1_reg_addr                                                          "0xB805C470"
#define DBG_INT_M1_reg                                                               0xB805C470
#define set_DBG_INT_M1_reg(data)   (*((volatile unsigned int*) DBG_INT_M1_reg)=data)
#define get_DBG_INT_M1_reg   (*((volatile unsigned int*) DBG_INT_M1_reg))
#define DBG_INT_M1_inst_adr                                                          "0x001C"
#define DBG_INT_M1_inst                                                              0x001C
#define DBG_INT_M1_scpu_int_m1_shift                                                 (4)
#define DBG_INT_M1_scpu_int_m1_mask                                                  (0x00000010)
#define DBG_INT_M1_scpu_int_m1(data)                                                 (0x00000010&((data)<<4))
#define DBG_INT_M1_scpu_int_m1_src(data)                                             ((0x00000010&(data))>>4)
#define DBG_INT_M1_get_scpu_int_m1(data)                                             ((0x00000010&(data))>>4)
#define DBG_INT_M1_scpu_int_en_m1_shift                                              (3)
#define DBG_INT_M1_scpu_int_en_m1_mask                                               (0x00000008)
#define DBG_INT_M1_scpu_int_en_m1(data)                                              (0x00000008&((data)<<3))
#define DBG_INT_M1_scpu_int_en_m1_src(data)                                          ((0x00000008&(data))>>3)
#define DBG_INT_M1_get_scpu_int_en_m1(data)                                          ((0x00000008&(data))>>3)
#define DBG_INT_M1_scpu_neg_int_m1_shift                                             (2)
#define DBG_INT_M1_scpu_neg_int_m1_mask                                              (0x00000004)
#define DBG_INT_M1_scpu_neg_int_m1(data)                                             (0x00000004&((data)<<2))
#define DBG_INT_M1_scpu_neg_int_m1_src(data)                                         ((0x00000004&(data))>>2)
#define DBG_INT_M1_get_scpu_neg_int_m1(data)                                         ((0x00000004&(data))>>2)
#define DBG_INT_M1_scpu_neg_int_en_m1_shift                                          (1)
#define DBG_INT_M1_scpu_neg_int_en_m1_mask                                           (0x00000002)
#define DBG_INT_M1_scpu_neg_int_en_m1(data)                                          (0x00000002&((data)<<1))
#define DBG_INT_M1_scpu_neg_int_en_m1_src(data)                                      ((0x00000002&(data))>>1)
#define DBG_INT_M1_get_scpu_neg_int_en_m1(data)                                      ((0x00000002&(data))>>1)
#define DBG_INT_M1_write_data_shift                                                  (0)
#define DBG_INT_M1_write_data_mask                                                   (0x00000001)
#define DBG_INT_M1_write_data(data)                                                  (0x00000001&((data)<<0))
#define DBG_INT_M1_write_data_src(data)                                              ((0x00000001&(data))>>0)
#define DBG_INT_M1_get_write_data(data)                                              ((0x00000001&(data))>>0)


#define DBG_ADDR_M1                                                                  0x1805C474
#define DBG_ADDR_M1_reg_addr                                                         "0xB805C474"
#define DBG_ADDR_M1_reg                                                              0xB805C474
#define set_DBG_ADDR_M1_reg(data)   (*((volatile unsigned int*) DBG_ADDR_M1_reg)=data)
#define get_DBG_ADDR_M1_reg   (*((volatile unsigned int*) DBG_ADDR_M1_reg))
#define DBG_ADDR_M1_inst_adr                                                         "0x001D"
#define DBG_ADDR_M1_inst                                                             0x001D
#define DBG_ADDR_M1_dbg_addr_m1_shift                                                (0)
#define DBG_ADDR_M1_dbg_addr_m1_mask                                                 (0xFFFFFFFF)
#define DBG_ADDR_M1_dbg_addr_m1(data)                                                (0xFFFFFFFF&((data)<<0))
#define DBG_ADDR_M1_dbg_addr_m1_src(data)                                            ((0xFFFFFFFF&(data))>>0)
#define DBG_ADDR_M1_get_dbg_addr_m1(data)                                            ((0xFFFFFFFF&(data))>>0)


#define DBG_ADDR1_M1                                                                 0x1805C478
#define DBG_ADDR1_M1_reg_addr                                                        "0xB805C478"
#define DBG_ADDR1_M1_reg                                                             0xB805C478
#define set_DBG_ADDR1_M1_reg(data)   (*((volatile unsigned int*) DBG_ADDR1_M1_reg)=data)
#define get_DBG_ADDR1_M1_reg   (*((volatile unsigned int*) DBG_ADDR1_M1_reg))
#define DBG_ADDR1_M1_inst_adr                                                        "0x001E"
#define DBG_ADDR1_M1_inst                                                            0x001E
#define DBG_ADDR1_M1_scpu_dbg_write_m1_shift                                         (0)
#define DBG_ADDR1_M1_scpu_dbg_write_m1_mask                                          (0x00000001)
#define DBG_ADDR1_M1_scpu_dbg_write_m1(data)                                         (0x00000001&((data)<<0))
#define DBG_ADDR1_M1_scpu_dbg_write_m1_src(data)                                     ((0x00000001&(data))>>0)
#define DBG_ADDR1_M1_get_scpu_dbg_write_m1(data)                                     ((0x00000001&(data))>>0)


#define BIST_MODE                                                                    0x1805C200
#define BIST_MODE_reg_addr                                                           "0xB805C200"
#define BIST_MODE_reg                                                                0xB805C200
#define set_BIST_MODE_reg(data)   (*((volatile unsigned int*) BIST_MODE_reg)=data)
#define get_BIST_MODE_reg   (*((volatile unsigned int*) BIST_MODE_reg))
#define BIST_MODE_inst_adr                                                           "0x0080"
#define BIST_MODE_inst                                                               0x0080
#define BIST_MODE_scu_mbist_mode_shift                                               (8)
#define BIST_MODE_scu_mbist_mode_mask                                                (0x00000100)
#define BIST_MODE_scu_mbist_mode(data)                                               (0x00000100&((data)<<8))
#define BIST_MODE_scu_mbist_mode_src(data)                                           ((0x00000100&(data))>>8)
#define BIST_MODE_get_scu_mbist_mode(data)                                           ((0x00000100&(data))>>8)
#define BIST_MODE_idata_mbist_mode_shift                                             (7)
#define BIST_MODE_idata_mbist_mode_mask                                              (0x00000080)
#define BIST_MODE_idata_mbist_mode(data)                                             (0x00000080&((data)<<7))
#define BIST_MODE_idata_mbist_mode_src(data)                                         ((0x00000080&(data))>>7)
#define BIST_MODE_get_idata_mbist_mode(data)                                         ((0x00000080&(data))>>7)
#define BIST_MODE_itag_mbist_mode_shift                                              (6)
#define BIST_MODE_itag_mbist_mode_mask                                               (0x00000040)
#define BIST_MODE_itag_mbist_mode(data)                                              (0x00000040&((data)<<6))
#define BIST_MODE_itag_mbist_mode_src(data)                                          ((0x00000040&(data))>>6)
#define BIST_MODE_get_itag_mbist_mode(data)                                          ((0x00000040&(data))>>6)
#define BIST_MODE_ddata_mbist_mode_shift                                             (5)
#define BIST_MODE_ddata_mbist_mode_mask                                              (0x00000020)
#define BIST_MODE_ddata_mbist_mode(data)                                             (0x00000020&((data)<<5))
#define BIST_MODE_ddata_mbist_mode_src(data)                                         ((0x00000020&(data))>>5)
#define BIST_MODE_get_ddata_mbist_mode(data)                                         ((0x00000020&(data))>>5)
#define BIST_MODE_dtag_mbist_mode_shift                                              (4)
#define BIST_MODE_dtag_mbist_mode_mask                                               (0x00000010)
#define BIST_MODE_dtag_mbist_mode(data)                                              (0x00000010&((data)<<4))
#define BIST_MODE_dtag_mbist_mode_src(data)                                          ((0x00000010&(data))>>4)
#define BIST_MODE_get_dtag_mbist_mode(data)                                          ((0x00000010&(data))>>4)
#define BIST_MODE_douter_mbist_mode_shift                                            (3)
#define BIST_MODE_douter_mbist_mode_mask                                             (0x00000008)
#define BIST_MODE_douter_mbist_mode(data)                                            (0x00000008&((data)<<3))
#define BIST_MODE_douter_mbist_mode_src(data)                                        ((0x00000008&(data))>>3)
#define BIST_MODE_get_douter_mbist_mode(data)                                        ((0x00000008&(data))>>3)
#define BIST_MODE_btac_mbist_mode_shift                                              (2)
#define BIST_MODE_btac_mbist_mode_mask                                               (0x00000004)
#define BIST_MODE_btac_mbist_mode(data)                                              (0x00000004&((data)<<2))
#define BIST_MODE_btac_mbist_mode_src(data)                                          ((0x00000004&(data))>>2)
#define BIST_MODE_get_btac_mbist_mode(data)                                          ((0x00000004&(data))>>2)
#define BIST_MODE_ghb_mbist_mode_shift                                               (1)
#define BIST_MODE_ghb_mbist_mode_mask                                                (0x00000002)
#define BIST_MODE_ghb_mbist_mode(data)                                               (0x00000002&((data)<<1))
#define BIST_MODE_ghb_mbist_mode_src(data)                                           ((0x00000002&(data))>>1)
#define BIST_MODE_get_ghb_mbist_mode(data)                                           ((0x00000002&(data))>>1)
#define BIST_MODE_tlb_mbist_mode_shift                                               (0)
#define BIST_MODE_tlb_mbist_mode_mask                                                (0x00000001)
#define BIST_MODE_tlb_mbist_mode(data)                                               (0x00000001&((data)<<0))
#define BIST_MODE_tlb_mbist_mode_src(data)                                           ((0x00000001&(data))>>0)
#define BIST_MODE_get_tlb_mbist_mode(data)                                           ((0x00000001&(data))>>0)


#define DRF_BIST_MODE                                                                0x1805C204
#define DRF_BIST_MODE_reg_addr                                                       "0xB805C204"
#define DRF_BIST_MODE_reg                                                            0xB805C204
#define set_DRF_BIST_MODE_reg(data)   (*((volatile unsigned int*) DRF_BIST_MODE_reg)=data)
#define get_DRF_BIST_MODE_reg   (*((volatile unsigned int*) DRF_BIST_MODE_reg))
#define DRF_BIST_MODE_inst_adr                                                       "0x0081"
#define DRF_BIST_MODE_inst                                                           0x0081
#define DRF_BIST_MODE_scu_drf_mbist_mode_shift                                       (1)
#define DRF_BIST_MODE_scu_drf_mbist_mode_mask                                        (0x00000002)
#define DRF_BIST_MODE_scu_drf_mbist_mode(data)                                       (0x00000002&((data)<<1))
#define DRF_BIST_MODE_scu_drf_mbist_mode_src(data)                                   ((0x00000002&(data))>>1)
#define DRF_BIST_MODE_get_scu_drf_mbist_mode(data)                                   ((0x00000002&(data))>>1)
#define DRF_BIST_MODE_cpu_drf_mbist_mode_shift                                       (0)
#define DRF_BIST_MODE_cpu_drf_mbist_mode_mask                                        (0x00000001)
#define DRF_BIST_MODE_cpu_drf_mbist_mode(data)                                       (0x00000001&((data)<<0))
#define DRF_BIST_MODE_cpu_drf_mbist_mode_src(data)                                   ((0x00000001&(data))>>0)
#define DRF_BIST_MODE_get_cpu_drf_mbist_mode(data)                                   ((0x00000001&(data))>>0)


#define DRF_TEST_RESUME                                                              0x1805C208
#define DRF_TEST_RESUME_reg_addr                                                     "0xB805C208"
#define DRF_TEST_RESUME_reg                                                          0xB805C208
#define set_DRF_TEST_RESUME_reg(data)   (*((volatile unsigned int*) DRF_TEST_RESUME_reg)=data)
#define get_DRF_TEST_RESUME_reg   (*((volatile unsigned int*) DRF_TEST_RESUME_reg))
#define DRF_TEST_RESUME_inst_adr                                                     "0x0082"
#define DRF_TEST_RESUME_inst                                                         0x0082
#define DRF_TEST_RESUME_scu_drf_test_resume_shift                                    (1)
#define DRF_TEST_RESUME_scu_drf_test_resume_mask                                     (0x00000002)
#define DRF_TEST_RESUME_scu_drf_test_resume(data)                                    (0x00000002&((data)<<1))
#define DRF_TEST_RESUME_scu_drf_test_resume_src(data)                                ((0x00000002&(data))>>1)
#define DRF_TEST_RESUME_get_scu_drf_test_resume(data)                                ((0x00000002&(data))>>1)
#define DRF_TEST_RESUME_cpu_drf_test_resume_shift                                    (0)
#define DRF_TEST_RESUME_cpu_drf_test_resume_mask                                     (0x00000001)
#define DRF_TEST_RESUME_cpu_drf_test_resume(data)                                    (0x00000001&((data)<<0))
#define DRF_TEST_RESUME_cpu_drf_test_resume_src(data)                                ((0x00000001&(data))>>0)
#define DRF_TEST_RESUME_get_cpu_drf_test_resume(data)                                ((0x00000001&(data))>>0)


#define CPU_BIST_DONE                                                                0x1805C20C
#define CPU_BIST_DONE_reg_addr                                                       "0xB805C20C"
#define CPU_BIST_DONE_reg                                                            0xB805C20C
#define set_CPU_BIST_DONE_reg(data)   (*((volatile unsigned int*) CPU_BIST_DONE_reg)=data)
#define get_CPU_BIST_DONE_reg   (*((volatile unsigned int*) CPU_BIST_DONE_reg))
#define CPU_BIST_DONE_inst_adr                                                       "0x0083"
#define CPU_BIST_DONE_inst                                                           0x0083
#define CPU_BIST_DONE_idata_mbist_done_shift                                         (7)
#define CPU_BIST_DONE_idata_mbist_done_mask                                          (0x00000080)
#define CPU_BIST_DONE_idata_mbist_done(data)                                         (0x00000080&((data)<<7))
#define CPU_BIST_DONE_idata_mbist_done_src(data)                                     ((0x00000080&(data))>>7)
#define CPU_BIST_DONE_get_idata_mbist_done(data)                                     ((0x00000080&(data))>>7)
#define CPU_BIST_DONE_itag_mbist_done_shift                                          (6)
#define CPU_BIST_DONE_itag_mbist_done_mask                                           (0x00000040)
#define CPU_BIST_DONE_itag_mbist_done(data)                                          (0x00000040&((data)<<6))
#define CPU_BIST_DONE_itag_mbist_done_src(data)                                      ((0x00000040&(data))>>6)
#define CPU_BIST_DONE_get_itag_mbist_done(data)                                      ((0x00000040&(data))>>6)
#define CPU_BIST_DONE_ddata_mbist_done_shift                                         (5)
#define CPU_BIST_DONE_ddata_mbist_done_mask                                          (0x00000020)
#define CPU_BIST_DONE_ddata_mbist_done(data)                                         (0x00000020&((data)<<5))
#define CPU_BIST_DONE_ddata_mbist_done_src(data)                                     ((0x00000020&(data))>>5)
#define CPU_BIST_DONE_get_ddata_mbist_done(data)                                     ((0x00000020&(data))>>5)
#define CPU_BIST_DONE_dtag_mbist_done_shift                                          (4)
#define CPU_BIST_DONE_dtag_mbist_done_mask                                           (0x00000010)
#define CPU_BIST_DONE_dtag_mbist_done(data)                                          (0x00000010&((data)<<4))
#define CPU_BIST_DONE_dtag_mbist_done_src(data)                                      ((0x00000010&(data))>>4)
#define CPU_BIST_DONE_get_dtag_mbist_done(data)                                      ((0x00000010&(data))>>4)
#define CPU_BIST_DONE_douter_mbist_done_shift                                        (3)
#define CPU_BIST_DONE_douter_mbist_done_mask                                         (0x00000008)
#define CPU_BIST_DONE_douter_mbist_done(data)                                        (0x00000008&((data)<<3))
#define CPU_BIST_DONE_douter_mbist_done_src(data)                                    ((0x00000008&(data))>>3)
#define CPU_BIST_DONE_get_douter_mbist_done(data)                                    ((0x00000008&(data))>>3)
#define CPU_BIST_DONE_btac_mbist_done_shift                                          (2)
#define CPU_BIST_DONE_btac_mbist_done_mask                                           (0x00000004)
#define CPU_BIST_DONE_btac_mbist_done(data)                                          (0x00000004&((data)<<2))
#define CPU_BIST_DONE_btac_mbist_done_src(data)                                      ((0x00000004&(data))>>2)
#define CPU_BIST_DONE_get_btac_mbist_done(data)                                      ((0x00000004&(data))>>2)
#define CPU_BIST_DONE_ghb_mbist_done_shift                                           (1)
#define CPU_BIST_DONE_ghb_mbist_done_mask                                            (0x00000002)
#define CPU_BIST_DONE_ghb_mbist_done(data)                                           (0x00000002&((data)<<1))
#define CPU_BIST_DONE_ghb_mbist_done_src(data)                                       ((0x00000002&(data))>>1)
#define CPU_BIST_DONE_get_ghb_mbist_done(data)                                       ((0x00000002&(data))>>1)
#define CPU_BIST_DONE_tlb_mbist_done_shift                                           (0)
#define CPU_BIST_DONE_tlb_mbist_done_mask                                            (0x00000001)
#define CPU_BIST_DONE_tlb_mbist_done(data)                                           (0x00000001&((data)<<0))
#define CPU_BIST_DONE_tlb_mbist_done_src(data)                                       ((0x00000001&(data))>>0)
#define CPU_BIST_DONE_get_tlb_mbist_done(data)                                       ((0x00000001&(data))>>0)


#define SCU_BIST_DONE                                                                0x1805C210
#define SCU_BIST_DONE_reg_addr                                                       "0xB805C210"
#define SCU_BIST_DONE_reg                                                            0xB805C210
#define set_SCU_BIST_DONE_reg(data)   (*((volatile unsigned int*) SCU_BIST_DONE_reg)=data)
#define get_SCU_BIST_DONE_reg   (*((volatile unsigned int*) SCU_BIST_DONE_reg))
#define SCU_BIST_DONE_inst_adr                                                       "0x0084"
#define SCU_BIST_DONE_inst                                                           0x0084
#define SCU_BIST_DONE_scu_mbist_done_shift                                           (0)
#define SCU_BIST_DONE_scu_mbist_done_mask                                            (0x00000001)
#define SCU_BIST_DONE_scu_mbist_done(data)                                           (0x00000001&((data)<<0))
#define SCU_BIST_DONE_scu_mbist_done_src(data)                                       ((0x00000001&(data))>>0)
#define SCU_BIST_DONE_get_scu_mbist_done(data)                                       ((0x00000001&(data))>>0)


#define CPU_DRF_BIST_DONE                                                            0x1805C214
#define CPU_DRF_BIST_DONE_reg_addr                                                   "0xB805C214"
#define CPU_DRF_BIST_DONE_reg                                                        0xB805C214
#define set_CPU_DRF_BIST_DONE_reg(data)   (*((volatile unsigned int*) CPU_DRF_BIST_DONE_reg)=data)
#define get_CPU_DRF_BIST_DONE_reg   (*((volatile unsigned int*) CPU_DRF_BIST_DONE_reg))
#define CPU_DRF_BIST_DONE_inst_adr                                                   "0x0085"
#define CPU_DRF_BIST_DONE_inst                                                       0x0085
#define CPU_DRF_BIST_DONE_cpu_drf_mbist_done_shift                                   (0)
#define CPU_DRF_BIST_DONE_cpu_drf_mbist_done_mask                                    (0x00000001)
#define CPU_DRF_BIST_DONE_cpu_drf_mbist_done(data)                                   (0x00000001&((data)<<0))
#define CPU_DRF_BIST_DONE_cpu_drf_mbist_done_src(data)                               ((0x00000001&(data))>>0)
#define CPU_DRF_BIST_DONE_get_cpu_drf_mbist_done(data)                               ((0x00000001&(data))>>0)


#define SCU_DRF_BIST_DONE                                                            0x1805C218
#define SCU_DRF_BIST_DONE_reg_addr                                                   "0xB805C218"
#define SCU_DRF_BIST_DONE_reg                                                        0xB805C218
#define set_SCU_DRF_BIST_DONE_reg(data)   (*((volatile unsigned int*) SCU_DRF_BIST_DONE_reg)=data)
#define get_SCU_DRF_BIST_DONE_reg   (*((volatile unsigned int*) SCU_DRF_BIST_DONE_reg))
#define SCU_DRF_BIST_DONE_inst_adr                                                   "0x0086"
#define SCU_DRF_BIST_DONE_inst                                                       0x0086
#define SCU_DRF_BIST_DONE_scu_drf_mbist_done_shift                                   (0)
#define SCU_DRF_BIST_DONE_scu_drf_mbist_done_mask                                    (0x00000001)
#define SCU_DRF_BIST_DONE_scu_drf_mbist_done(data)                                   (0x00000001&((data)<<0))
#define SCU_DRF_BIST_DONE_scu_drf_mbist_done_src(data)                               ((0x00000001&(data))>>0)
#define SCU_DRF_BIST_DONE_get_scu_drf_mbist_done(data)                               ((0x00000001&(data))>>0)


#define CPU0_BIST_FAIL_GROUP                                                         0x1805C21C
#define CPU0_BIST_FAIL_GROUP_reg_addr                                                "0xB805C21C"
#define CPU0_BIST_FAIL_GROUP_reg                                                     0xB805C21C
#define set_CPU0_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) CPU0_BIST_FAIL_GROUP_reg)=data)
#define get_CPU0_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) CPU0_BIST_FAIL_GROUP_reg))
#define CPU0_BIST_FAIL_GROUP_inst_adr                                                "0x0087"
#define CPU0_BIST_FAIL_GROUP_inst                                                    0x0087
#define CPU0_BIST_FAIL_GROUP_cpu0_idata_mbist_fail_shift                             (7)
#define CPU0_BIST_FAIL_GROUP_cpu0_idata_mbist_fail_mask                              (0x00000080)
#define CPU0_BIST_FAIL_GROUP_cpu0_idata_mbist_fail(data)                             (0x00000080&((data)<<7))
#define CPU0_BIST_FAIL_GROUP_cpu0_idata_mbist_fail_src(data)                         ((0x00000080&(data))>>7)
#define CPU0_BIST_FAIL_GROUP_get_cpu0_idata_mbist_fail(data)                         ((0x00000080&(data))>>7)
#define CPU0_BIST_FAIL_GROUP_cpu0_itag_mbist_fail_shift                              (6)
#define CPU0_BIST_FAIL_GROUP_cpu0_itag_mbist_fail_mask                               (0x00000040)
#define CPU0_BIST_FAIL_GROUP_cpu0_itag_mbist_fail(data)                              (0x00000040&((data)<<6))
#define CPU0_BIST_FAIL_GROUP_cpu0_itag_mbist_fail_src(data)                          ((0x00000040&(data))>>6)
#define CPU0_BIST_FAIL_GROUP_get_cpu0_itag_mbist_fail(data)                          ((0x00000040&(data))>>6)
#define CPU0_BIST_FAIL_GROUP_cpu0_ddata_mbist_fail_shift                             (5)
#define CPU0_BIST_FAIL_GROUP_cpu0_ddata_mbist_fail_mask                              (0x00000020)
#define CPU0_BIST_FAIL_GROUP_cpu0_ddata_mbist_fail(data)                             (0x00000020&((data)<<5))
#define CPU0_BIST_FAIL_GROUP_cpu0_ddata_mbist_fail_src(data)                         ((0x00000020&(data))>>5)
#define CPU0_BIST_FAIL_GROUP_get_cpu0_ddata_mbist_fail(data)                         ((0x00000020&(data))>>5)
#define CPU0_BIST_FAIL_GROUP_cpu0_dtag_mbist_fail_shift                              (4)
#define CPU0_BIST_FAIL_GROUP_cpu0_dtag_mbist_fail_mask                               (0x00000010)
#define CPU0_BIST_FAIL_GROUP_cpu0_dtag_mbist_fail(data)                              (0x00000010&((data)<<4))
#define CPU0_BIST_FAIL_GROUP_cpu0_dtag_mbist_fail_src(data)                          ((0x00000010&(data))>>4)
#define CPU0_BIST_FAIL_GROUP_get_cpu0_dtag_mbist_fail(data)                          ((0x00000010&(data))>>4)
#define CPU0_BIST_FAIL_GROUP_cpu0_douter_mbist_fail_shift                            (3)
#define CPU0_BIST_FAIL_GROUP_cpu0_douter_mbist_fail_mask                             (0x00000008)
#define CPU0_BIST_FAIL_GROUP_cpu0_douter_mbist_fail(data)                            (0x00000008&((data)<<3))
#define CPU0_BIST_FAIL_GROUP_cpu0_douter_mbist_fail_src(data)                        ((0x00000008&(data))>>3)
#define CPU0_BIST_FAIL_GROUP_get_cpu0_douter_mbist_fail(data)                        ((0x00000008&(data))>>3)
#define CPU0_BIST_FAIL_GROUP_cpu0_btac_mbist_fail_shift                              (2)
#define CPU0_BIST_FAIL_GROUP_cpu0_btac_mbist_fail_mask                               (0x00000004)
#define CPU0_BIST_FAIL_GROUP_cpu0_btac_mbist_fail(data)                              (0x00000004&((data)<<2))
#define CPU0_BIST_FAIL_GROUP_cpu0_btac_mbist_fail_src(data)                          ((0x00000004&(data))>>2)
#define CPU0_BIST_FAIL_GROUP_get_cpu0_btac_mbist_fail(data)                          ((0x00000004&(data))>>2)
#define CPU0_BIST_FAIL_GROUP_cpu0_ghb_mbist_fail_shift                               (1)
#define CPU0_BIST_FAIL_GROUP_cpu0_ghb_mbist_fail_mask                                (0x00000002)
#define CPU0_BIST_FAIL_GROUP_cpu0_ghb_mbist_fail(data)                               (0x00000002&((data)<<1))
#define CPU0_BIST_FAIL_GROUP_cpu0_ghb_mbist_fail_src(data)                           ((0x00000002&(data))>>1)
#define CPU0_BIST_FAIL_GROUP_get_cpu0_ghb_mbist_fail(data)                           ((0x00000002&(data))>>1)
#define CPU0_BIST_FAIL_GROUP_cpu0_tlb_mbist_fail_shift                               (0)
#define CPU0_BIST_FAIL_GROUP_cpu0_tlb_mbist_fail_mask                                (0x00000001)
#define CPU0_BIST_FAIL_GROUP_cpu0_tlb_mbist_fail(data)                               (0x00000001&((data)<<0))
#define CPU0_BIST_FAIL_GROUP_cpu0_tlb_mbist_fail_src(data)                           ((0x00000001&(data))>>0)
#define CPU0_BIST_FAIL_GROUP_get_cpu0_tlb_mbist_fail(data)                           ((0x00000001&(data))>>0)


#define CPU1_BIST_FAIL_GROUP                                                         0x1805C220
#define CPU1_BIST_FAIL_GROUP_reg_addr                                                "0xB805C220"
#define CPU1_BIST_FAIL_GROUP_reg                                                     0xB805C220
#define set_CPU1_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) CPU1_BIST_FAIL_GROUP_reg)=data)
#define get_CPU1_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) CPU1_BIST_FAIL_GROUP_reg))
#define CPU1_BIST_FAIL_GROUP_inst_adr                                                "0x0088"
#define CPU1_BIST_FAIL_GROUP_inst                                                    0x0088
#define CPU1_BIST_FAIL_GROUP_cpu1_idata_mbist_fail_shift                             (7)
#define CPU1_BIST_FAIL_GROUP_cpu1_idata_mbist_fail_mask                              (0x00000080)
#define CPU1_BIST_FAIL_GROUP_cpu1_idata_mbist_fail(data)                             (0x00000080&((data)<<7))
#define CPU1_BIST_FAIL_GROUP_cpu1_idata_mbist_fail_src(data)                         ((0x00000080&(data))>>7)
#define CPU1_BIST_FAIL_GROUP_get_cpu1_idata_mbist_fail(data)                         ((0x00000080&(data))>>7)
#define CPU1_BIST_FAIL_GROUP_cpu1_itag_mbist_fail_shift                              (6)
#define CPU1_BIST_FAIL_GROUP_cpu1_itag_mbist_fail_mask                               (0x00000040)
#define CPU1_BIST_FAIL_GROUP_cpu1_itag_mbist_fail(data)                              (0x00000040&((data)<<6))
#define CPU1_BIST_FAIL_GROUP_cpu1_itag_mbist_fail_src(data)                          ((0x00000040&(data))>>6)
#define CPU1_BIST_FAIL_GROUP_get_cpu1_itag_mbist_fail(data)                          ((0x00000040&(data))>>6)
#define CPU1_BIST_FAIL_GROUP_cpu1_ddata_mbist_fail_shift                             (5)
#define CPU1_BIST_FAIL_GROUP_cpu1_ddata_mbist_fail_mask                              (0x00000020)
#define CPU1_BIST_FAIL_GROUP_cpu1_ddata_mbist_fail(data)                             (0x00000020&((data)<<5))
#define CPU1_BIST_FAIL_GROUP_cpu1_ddata_mbist_fail_src(data)                         ((0x00000020&(data))>>5)
#define CPU1_BIST_FAIL_GROUP_get_cpu1_ddata_mbist_fail(data)                         ((0x00000020&(data))>>5)
#define CPU1_BIST_FAIL_GROUP_cpu1_dtag_mbist_fail_shift                              (4)
#define CPU1_BIST_FAIL_GROUP_cpu1_dtag_mbist_fail_mask                               (0x00000010)
#define CPU1_BIST_FAIL_GROUP_cpu1_dtag_mbist_fail(data)                              (0x00000010&((data)<<4))
#define CPU1_BIST_FAIL_GROUP_cpu1_dtag_mbist_fail_src(data)                          ((0x00000010&(data))>>4)
#define CPU1_BIST_FAIL_GROUP_get_cpu1_dtag_mbist_fail(data)                          ((0x00000010&(data))>>4)
#define CPU1_BIST_FAIL_GROUP_cpu1_douter_mbist_fail_shift                            (3)
#define CPU1_BIST_FAIL_GROUP_cpu1_douter_mbist_fail_mask                             (0x00000008)
#define CPU1_BIST_FAIL_GROUP_cpu1_douter_mbist_fail(data)                            (0x00000008&((data)<<3))
#define CPU1_BIST_FAIL_GROUP_cpu1_douter_mbist_fail_src(data)                        ((0x00000008&(data))>>3)
#define CPU1_BIST_FAIL_GROUP_get_cpu1_douter_mbist_fail(data)                        ((0x00000008&(data))>>3)
#define CPU1_BIST_FAIL_GROUP_cpu1_btac_mbist_fail_shift                              (2)
#define CPU1_BIST_FAIL_GROUP_cpu1_btac_mbist_fail_mask                               (0x00000004)
#define CPU1_BIST_FAIL_GROUP_cpu1_btac_mbist_fail(data)                              (0x00000004&((data)<<2))
#define CPU1_BIST_FAIL_GROUP_cpu1_btac_mbist_fail_src(data)                          ((0x00000004&(data))>>2)
#define CPU1_BIST_FAIL_GROUP_get_cpu1_btac_mbist_fail(data)                          ((0x00000004&(data))>>2)
#define CPU1_BIST_FAIL_GROUP_cpu1_ghb_mbist_fail_shift                               (1)
#define CPU1_BIST_FAIL_GROUP_cpu1_ghb_mbist_fail_mask                                (0x00000002)
#define CPU1_BIST_FAIL_GROUP_cpu1_ghb_mbist_fail(data)                               (0x00000002&((data)<<1))
#define CPU1_BIST_FAIL_GROUP_cpu1_ghb_mbist_fail_src(data)                           ((0x00000002&(data))>>1)
#define CPU1_BIST_FAIL_GROUP_get_cpu1_ghb_mbist_fail(data)                           ((0x00000002&(data))>>1)
#define CPU1_BIST_FAIL_GROUP_cpu1_tlb_mbist_fail_shift                               (0)
#define CPU1_BIST_FAIL_GROUP_cpu1_tlb_mbist_fail_mask                                (0x00000001)
#define CPU1_BIST_FAIL_GROUP_cpu1_tlb_mbist_fail(data)                               (0x00000001&((data)<<0))
#define CPU1_BIST_FAIL_GROUP_cpu1_tlb_mbist_fail_src(data)                           ((0x00000001&(data))>>0)
#define CPU1_BIST_FAIL_GROUP_get_cpu1_tlb_mbist_fail(data)                           ((0x00000001&(data))>>0)


#define CPU0_DRF_BIST_FAIL_GROUP                                                     0x1805C224
#define CPU0_DRF_BIST_FAIL_GROUP_reg_addr                                            "0xB805C224"
#define CPU0_DRF_BIST_FAIL_GROUP_reg                                                 0xB805C224
#define set_CPU0_DRF_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) CPU0_DRF_BIST_FAIL_GROUP_reg)=data)
#define get_CPU0_DRF_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) CPU0_DRF_BIST_FAIL_GROUP_reg))
#define CPU0_DRF_BIST_FAIL_GROUP_inst_adr                                            "0x0089"
#define CPU0_DRF_BIST_FAIL_GROUP_inst                                                0x0089
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_idata_drf_mbist_fail_shift                     (7)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_idata_drf_mbist_fail_mask                      (0x00000080)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_idata_drf_mbist_fail(data)                     (0x00000080&((data)<<7))
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_idata_drf_mbist_fail_src(data)                 ((0x00000080&(data))>>7)
#define CPU0_DRF_BIST_FAIL_GROUP_get_cpu0_idata_drf_mbist_fail(data)                 ((0x00000080&(data))>>7)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_itag_drf_mbist_fail_shift                      (6)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_itag_drf_mbist_fail_mask                       (0x00000040)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_itag_drf_mbist_fail(data)                      (0x00000040&((data)<<6))
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_itag_drf_mbist_fail_src(data)                  ((0x00000040&(data))>>6)
#define CPU0_DRF_BIST_FAIL_GROUP_get_cpu0_itag_drf_mbist_fail(data)                  ((0x00000040&(data))>>6)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_ddata_drf_mbist_fail_shift                     (5)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_ddata_drf_mbist_fail_mask                      (0x00000020)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_ddata_drf_mbist_fail(data)                     (0x00000020&((data)<<5))
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_ddata_drf_mbist_fail_src(data)                 ((0x00000020&(data))>>5)
#define CPU0_DRF_BIST_FAIL_GROUP_get_cpu0_ddata_drf_mbist_fail(data)                 ((0x00000020&(data))>>5)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_dtag_drf_mbist_fail_shift                      (4)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_dtag_drf_mbist_fail_mask                       (0x00000010)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_dtag_drf_mbist_fail(data)                      (0x00000010&((data)<<4))
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_dtag_drf_mbist_fail_src(data)                  ((0x00000010&(data))>>4)
#define CPU0_DRF_BIST_FAIL_GROUP_get_cpu0_dtag_drf_mbist_fail(data)                  ((0x00000010&(data))>>4)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_douter_drf_mbist_fail_shift                    (3)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_douter_drf_mbist_fail_mask                     (0x00000008)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_douter_drf_mbist_fail(data)                    (0x00000008&((data)<<3))
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_douter_drf_mbist_fail_src(data)                ((0x00000008&(data))>>3)
#define CPU0_DRF_BIST_FAIL_GROUP_get_cpu0_douter_drf_mbist_fail(data)                ((0x00000008&(data))>>3)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_btac_drf_mbist_fail_shift                      (2)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_btac_drf_mbist_fail_mask                       (0x00000004)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_btac_drf_mbist_fail(data)                      (0x00000004&((data)<<2))
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_btac_drf_mbist_fail_src(data)                  ((0x00000004&(data))>>2)
#define CPU0_DRF_BIST_FAIL_GROUP_get_cpu0_btac_drf_mbist_fail(data)                  ((0x00000004&(data))>>2)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_ghb_drf_mbist_fail_shift                       (1)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_ghb_drf_mbist_fail_mask                        (0x00000002)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_ghb_drf_mbist_fail(data)                       (0x00000002&((data)<<1))
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_ghb_drf_mbist_fail_src(data)                   ((0x00000002&(data))>>1)
#define CPU0_DRF_BIST_FAIL_GROUP_get_cpu0_ghb_drf_mbist_fail(data)                   ((0x00000002&(data))>>1)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_tlb_drf_mbist_fail_shift                       (0)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_tlb_drf_mbist_fail_mask                        (0x00000001)
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_tlb_drf_mbist_fail(data)                       (0x00000001&((data)<<0))
#define CPU0_DRF_BIST_FAIL_GROUP_cpu0_tlb_drf_mbist_fail_src(data)                   ((0x00000001&(data))>>0)
#define CPU0_DRF_BIST_FAIL_GROUP_get_cpu0_tlb_drf_mbist_fail(data)                   ((0x00000001&(data))>>0)


#define CPU1_DRF_BIST_FAIL_GROUP                                                     0x1805C228
#define CPU1_DRF_BIST_FAIL_GROUP_reg_addr                                            "0xB805C228"
#define CPU1_DRF_BIST_FAIL_GROUP_reg                                                 0xB805C228
#define set_CPU1_DRF_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) CPU1_DRF_BIST_FAIL_GROUP_reg)=data)
#define get_CPU1_DRF_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) CPU1_DRF_BIST_FAIL_GROUP_reg))
#define CPU1_DRF_BIST_FAIL_GROUP_inst_adr                                            "0x008A"
#define CPU1_DRF_BIST_FAIL_GROUP_inst                                                0x008A
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_idata_drf_mbist_fail_shift                     (7)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_idata_drf_mbist_fail_mask                      (0x00000080)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_idata_drf_mbist_fail(data)                     (0x00000080&((data)<<7))
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_idata_drf_mbist_fail_src(data)                 ((0x00000080&(data))>>7)
#define CPU1_DRF_BIST_FAIL_GROUP_get_cpu1_idata_drf_mbist_fail(data)                 ((0x00000080&(data))>>7)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_itag_drf_mbist_fail_shift                      (6)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_itag_drf_mbist_fail_mask                       (0x00000040)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_itag_drf_mbist_fail(data)                      (0x00000040&((data)<<6))
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_itag_drf_mbist_fail_src(data)                  ((0x00000040&(data))>>6)
#define CPU1_DRF_BIST_FAIL_GROUP_get_cpu1_itag_drf_mbist_fail(data)                  ((0x00000040&(data))>>6)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_ddata_drf_mbist_fail_shift                     (5)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_ddata_drf_mbist_fail_mask                      (0x00000020)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_ddata_drf_mbist_fail(data)                     (0x00000020&((data)<<5))
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_ddata_drf_mbist_fail_src(data)                 ((0x00000020&(data))>>5)
#define CPU1_DRF_BIST_FAIL_GROUP_get_cpu1_ddata_drf_mbist_fail(data)                 ((0x00000020&(data))>>5)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_dtag_drf_mbist_fail_shift                      (4)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_dtag_drf_mbist_fail_mask                       (0x00000010)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_dtag_drf_mbist_fail(data)                      (0x00000010&((data)<<4))
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_dtag_drf_mbist_fail_src(data)                  ((0x00000010&(data))>>4)
#define CPU1_DRF_BIST_FAIL_GROUP_get_cpu1_dtag_drf_mbist_fail(data)                  ((0x00000010&(data))>>4)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_douter_drf_mbist_fail_shift                    (3)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_douter_drf_mbist_fail_mask                     (0x00000008)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_douter_drf_mbist_fail(data)                    (0x00000008&((data)<<3))
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_douter_drf_mbist_fail_src(data)                ((0x00000008&(data))>>3)
#define CPU1_DRF_BIST_FAIL_GROUP_get_cpu1_douter_drf_mbist_fail(data)                ((0x00000008&(data))>>3)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_btac_drf_mbist_fail_shift                      (2)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_btac_drf_mbist_fail_mask                       (0x00000004)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_btac_drf_mbist_fail(data)                      (0x00000004&((data)<<2))
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_btac_drf_mbist_fail_src(data)                  ((0x00000004&(data))>>2)
#define CPU1_DRF_BIST_FAIL_GROUP_get_cpu1_btac_drf_mbist_fail(data)                  ((0x00000004&(data))>>2)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_ghb_drf_mbist_fail_shift                       (1)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_ghb_drf_mbist_fail_mask                        (0x00000002)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_ghb_drf_mbist_fail(data)                       (0x00000002&((data)<<1))
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_ghb_drf_mbist_fail_src(data)                   ((0x00000002&(data))>>1)
#define CPU1_DRF_BIST_FAIL_GROUP_get_cpu1_ghb_drf_mbist_fail(data)                   ((0x00000002&(data))>>1)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_tlb_drf_mbist_fail_shift                       (0)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_tlb_drf_mbist_fail_mask                        (0x00000001)
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_tlb_drf_mbist_fail(data)                       (0x00000001&((data)<<0))
#define CPU1_DRF_BIST_FAIL_GROUP_cpu1_tlb_drf_mbist_fail_src(data)                   ((0x00000001&(data))>>0)
#define CPU1_DRF_BIST_FAIL_GROUP_get_cpu1_tlb_drf_mbist_fail(data)                   ((0x00000001&(data))>>0)


#define CPU0_IDATA_BIST_FAIL                                                         0x1805C22C
#define CPU0_IDATA_BIST_FAIL_reg_addr                                                "0xB805C22C"
#define CPU0_IDATA_BIST_FAIL_reg                                                     0xB805C22C
#define set_CPU0_IDATA_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_IDATA_BIST_FAIL_reg)=data)
#define get_CPU0_IDATA_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_IDATA_BIST_FAIL_reg))
#define CPU0_IDATA_BIST_FAIL_inst_adr                                                "0x008B"
#define CPU0_IDATA_BIST_FAIL_inst                                                    0x008B
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_7_shift                           (7)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_7_mask                            (0x00000080)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_7(data)                           (0x00000080&((data)<<7))
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_7_src(data)                       ((0x00000080&(data))>>7)
#define CPU0_IDATA_BIST_FAIL_get_cpu0_idata_mbist_fail_7(data)                       ((0x00000080&(data))>>7)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_6_shift                           (6)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_6_mask                            (0x00000040)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_6(data)                           (0x00000040&((data)<<6))
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_6_src(data)                       ((0x00000040&(data))>>6)
#define CPU0_IDATA_BIST_FAIL_get_cpu0_idata_mbist_fail_6(data)                       ((0x00000040&(data))>>6)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_5_shift                           (5)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_5_mask                            (0x00000020)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_5(data)                           (0x00000020&((data)<<5))
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_5_src(data)                       ((0x00000020&(data))>>5)
#define CPU0_IDATA_BIST_FAIL_get_cpu0_idata_mbist_fail_5(data)                       ((0x00000020&(data))>>5)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_4_shift                           (4)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_4_mask                            (0x00000010)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_4(data)                           (0x00000010&((data)<<4))
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_4_src(data)                       ((0x00000010&(data))>>4)
#define CPU0_IDATA_BIST_FAIL_get_cpu0_idata_mbist_fail_4(data)                       ((0x00000010&(data))>>4)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_3_shift                           (3)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_3_mask                            (0x00000008)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_3(data)                           (0x00000008&((data)<<3))
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_3_src(data)                       ((0x00000008&(data))>>3)
#define CPU0_IDATA_BIST_FAIL_get_cpu0_idata_mbist_fail_3(data)                       ((0x00000008&(data))>>3)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_2_shift                           (2)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_2_mask                            (0x00000004)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_2(data)                           (0x00000004&((data)<<2))
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_2_src(data)                       ((0x00000004&(data))>>2)
#define CPU0_IDATA_BIST_FAIL_get_cpu0_idata_mbist_fail_2(data)                       ((0x00000004&(data))>>2)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_1_shift                           (1)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_1_mask                            (0x00000002)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_1(data)                           (0x00000002&((data)<<1))
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_1_src(data)                       ((0x00000002&(data))>>1)
#define CPU0_IDATA_BIST_FAIL_get_cpu0_idata_mbist_fail_1(data)                       ((0x00000002&(data))>>1)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_0_shift                           (0)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_0_mask                            (0x00000001)
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_0(data)                           (0x00000001&((data)<<0))
#define CPU0_IDATA_BIST_FAIL_cpu0_idata_mbist_fail_0_src(data)                       ((0x00000001&(data))>>0)
#define CPU0_IDATA_BIST_FAIL_get_cpu0_idata_mbist_fail_0(data)                       ((0x00000001&(data))>>0)


#define CPU1_IDATA_BIST_FAIL                                                         0x1805C230
#define CPU1_IDATA_BIST_FAIL_reg_addr                                                "0xB805C230"
#define CPU1_IDATA_BIST_FAIL_reg                                                     0xB805C230
#define set_CPU1_IDATA_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_IDATA_BIST_FAIL_reg)=data)
#define get_CPU1_IDATA_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_IDATA_BIST_FAIL_reg))
#define CPU1_IDATA_BIST_FAIL_inst_adr                                                "0x008C"
#define CPU1_IDATA_BIST_FAIL_inst                                                    0x008C
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_7_shift                           (7)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_7_mask                            (0x00000080)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_7(data)                           (0x00000080&((data)<<7))
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_7_src(data)                       ((0x00000080&(data))>>7)
#define CPU1_IDATA_BIST_FAIL_get_cpu1_idata_mbist_fail_7(data)                       ((0x00000080&(data))>>7)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_6_shift                           (6)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_6_mask                            (0x00000040)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_6(data)                           (0x00000040&((data)<<6))
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_6_src(data)                       ((0x00000040&(data))>>6)
#define CPU1_IDATA_BIST_FAIL_get_cpu1_idata_mbist_fail_6(data)                       ((0x00000040&(data))>>6)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_5_shift                           (5)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_5_mask                            (0x00000020)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_5(data)                           (0x00000020&((data)<<5))
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_5_src(data)                       ((0x00000020&(data))>>5)
#define CPU1_IDATA_BIST_FAIL_get_cpu1_idata_mbist_fail_5(data)                       ((0x00000020&(data))>>5)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_4_shift                           (4)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_4_mask                            (0x00000010)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_4(data)                           (0x00000010&((data)<<4))
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_4_src(data)                       ((0x00000010&(data))>>4)
#define CPU1_IDATA_BIST_FAIL_get_cpu1_idata_mbist_fail_4(data)                       ((0x00000010&(data))>>4)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_3_shift                           (3)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_3_mask                            (0x00000008)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_3(data)                           (0x00000008&((data)<<3))
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_3_src(data)                       ((0x00000008&(data))>>3)
#define CPU1_IDATA_BIST_FAIL_get_cpu1_idata_mbist_fail_3(data)                       ((0x00000008&(data))>>3)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_2_shift                           (2)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_2_mask                            (0x00000004)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_2(data)                           (0x00000004&((data)<<2))
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_2_src(data)                       ((0x00000004&(data))>>2)
#define CPU1_IDATA_BIST_FAIL_get_cpu1_idata_mbist_fail_2(data)                       ((0x00000004&(data))>>2)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_1_shift                           (1)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_1_mask                            (0x00000002)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_1(data)                           (0x00000002&((data)<<1))
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_1_src(data)                       ((0x00000002&(data))>>1)
#define CPU1_IDATA_BIST_FAIL_get_cpu1_idata_mbist_fail_1(data)                       ((0x00000002&(data))>>1)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_0_shift                           (0)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_0_mask                            (0x00000001)
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_0(data)                           (0x00000001&((data)<<0))
#define CPU1_IDATA_BIST_FAIL_cpu1_idata_mbist_fail_0_src(data)                       ((0x00000001&(data))>>0)
#define CPU1_IDATA_BIST_FAIL_get_cpu1_idata_mbist_fail_0(data)                       ((0x00000001&(data))>>0)


#define CPU0_IDATA_DRF_BIST_FAIL                                                     0x1805C234
#define CPU0_IDATA_DRF_BIST_FAIL_reg_addr                                            "0xB805C234"
#define CPU0_IDATA_DRF_BIST_FAIL_reg                                                 0xB805C234
#define set_CPU0_IDATA_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_IDATA_DRF_BIST_FAIL_reg)=data)
#define get_CPU0_IDATA_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_IDATA_DRF_BIST_FAIL_reg))
#define CPU0_IDATA_DRF_BIST_FAIL_inst_adr                                            "0x008D"
#define CPU0_IDATA_DRF_BIST_FAIL_inst                                                0x008D
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_7_shift                   (7)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_7_mask                    (0x00000080)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_7(data)                   (0x00000080&((data)<<7))
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_7_src(data)               ((0x00000080&(data))>>7)
#define CPU0_IDATA_DRF_BIST_FAIL_get_cpu0_idata_drf_mbist_fail_7(data)               ((0x00000080&(data))>>7)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_6_shift                   (6)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_6_mask                    (0x00000040)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_6(data)                   (0x00000040&((data)<<6))
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_6_src(data)               ((0x00000040&(data))>>6)
#define CPU0_IDATA_DRF_BIST_FAIL_get_cpu0_idata_drf_mbist_fail_6(data)               ((0x00000040&(data))>>6)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_5_shift                   (5)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_5_mask                    (0x00000020)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_5(data)                   (0x00000020&((data)<<5))
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_5_src(data)               ((0x00000020&(data))>>5)
#define CPU0_IDATA_DRF_BIST_FAIL_get_cpu0_idata_drf_mbist_fail_5(data)               ((0x00000020&(data))>>5)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_4_shift                   (4)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_4_mask                    (0x00000010)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_4(data)                   (0x00000010&((data)<<4))
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_4_src(data)               ((0x00000010&(data))>>4)
#define CPU0_IDATA_DRF_BIST_FAIL_get_cpu0_idata_drf_mbist_fail_4(data)               ((0x00000010&(data))>>4)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_3_shift                   (3)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_3_mask                    (0x00000008)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_3(data)                   (0x00000008&((data)<<3))
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_3_src(data)               ((0x00000008&(data))>>3)
#define CPU0_IDATA_DRF_BIST_FAIL_get_cpu0_idata_drf_mbist_fail_3(data)               ((0x00000008&(data))>>3)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_2_shift                   (2)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_2_mask                    (0x00000004)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_2(data)                   (0x00000004&((data)<<2))
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_2_src(data)               ((0x00000004&(data))>>2)
#define CPU0_IDATA_DRF_BIST_FAIL_get_cpu0_idata_drf_mbist_fail_2(data)               ((0x00000004&(data))>>2)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_1_shift                   (1)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_1_mask                    (0x00000002)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_1(data)                   (0x00000002&((data)<<1))
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_1_src(data)               ((0x00000002&(data))>>1)
#define CPU0_IDATA_DRF_BIST_FAIL_get_cpu0_idata_drf_mbist_fail_1(data)               ((0x00000002&(data))>>1)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_0_shift                   (0)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_0_mask                    (0x00000001)
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_0(data)                   (0x00000001&((data)<<0))
#define CPU0_IDATA_DRF_BIST_FAIL_cpu0_idata_drf_mbist_fail_0_src(data)               ((0x00000001&(data))>>0)
#define CPU0_IDATA_DRF_BIST_FAIL_get_cpu0_idata_drf_mbist_fail_0(data)               ((0x00000001&(data))>>0)


#define CPU1_IDATA_DRF_BIST_FAIL                                                     0x1805C238
#define CPU1_IDATA_DRF_BIST_FAIL_reg_addr                                            "0xB805C238"
#define CPU1_IDATA_DRF_BIST_FAIL_reg                                                 0xB805C238
#define set_CPU1_IDATA_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_IDATA_DRF_BIST_FAIL_reg)=data)
#define get_CPU1_IDATA_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_IDATA_DRF_BIST_FAIL_reg))
#define CPU1_IDATA_DRF_BIST_FAIL_inst_adr                                            "0x008E"
#define CPU1_IDATA_DRF_BIST_FAIL_inst                                                0x008E
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_7_shift                   (7)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_7_mask                    (0x00000080)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_7(data)                   (0x00000080&((data)<<7))
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_7_src(data)               ((0x00000080&(data))>>7)
#define CPU1_IDATA_DRF_BIST_FAIL_get_cpu1_idata_drf_mbist_fail_7(data)               ((0x00000080&(data))>>7)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_6_shift                   (6)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_6_mask                    (0x00000040)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_6(data)                   (0x00000040&((data)<<6))
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_6_src(data)               ((0x00000040&(data))>>6)
#define CPU1_IDATA_DRF_BIST_FAIL_get_cpu1_idata_drf_mbist_fail_6(data)               ((0x00000040&(data))>>6)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_5_shift                   (5)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_5_mask                    (0x00000020)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_5(data)                   (0x00000020&((data)<<5))
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_5_src(data)               ((0x00000020&(data))>>5)
#define CPU1_IDATA_DRF_BIST_FAIL_get_cpu1_idata_drf_mbist_fail_5(data)               ((0x00000020&(data))>>5)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_4_shift                   (4)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_4_mask                    (0x00000010)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_4(data)                   (0x00000010&((data)<<4))
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_4_src(data)               ((0x00000010&(data))>>4)
#define CPU1_IDATA_DRF_BIST_FAIL_get_cpu1_idata_drf_mbist_fail_4(data)               ((0x00000010&(data))>>4)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_3_shift                   (3)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_3_mask                    (0x00000008)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_3(data)                   (0x00000008&((data)<<3))
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_3_src(data)               ((0x00000008&(data))>>3)
#define CPU1_IDATA_DRF_BIST_FAIL_get_cpu1_idata_drf_mbist_fail_3(data)               ((0x00000008&(data))>>3)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_2_shift                   (2)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_2_mask                    (0x00000004)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_2(data)                   (0x00000004&((data)<<2))
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_2_src(data)               ((0x00000004&(data))>>2)
#define CPU1_IDATA_DRF_BIST_FAIL_get_cpu1_idata_drf_mbist_fail_2(data)               ((0x00000004&(data))>>2)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_1_shift                   (1)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_1_mask                    (0x00000002)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_1(data)                   (0x00000002&((data)<<1))
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_1_src(data)               ((0x00000002&(data))>>1)
#define CPU1_IDATA_DRF_BIST_FAIL_get_cpu1_idata_drf_mbist_fail_1(data)               ((0x00000002&(data))>>1)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_0_shift                   (0)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_0_mask                    (0x00000001)
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_0(data)                   (0x00000001&((data)<<0))
#define CPU1_IDATA_DRF_BIST_FAIL_cpu1_idata_drf_mbist_fail_0_src(data)               ((0x00000001&(data))>>0)
#define CPU1_IDATA_DRF_BIST_FAIL_get_cpu1_idata_drf_mbist_fail_0(data)               ((0x00000001&(data))>>0)


#define CPU0_ITAG_BIST_FAIL                                                          0x1805C23C
#define CPU0_ITAG_BIST_FAIL_reg_addr                                                 "0xB805C23C"
#define CPU0_ITAG_BIST_FAIL_reg                                                      0xB805C23C
#define set_CPU0_ITAG_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_ITAG_BIST_FAIL_reg)=data)
#define get_CPU0_ITAG_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_ITAG_BIST_FAIL_reg))
#define CPU0_ITAG_BIST_FAIL_inst_adr                                                 "0x008F"
#define CPU0_ITAG_BIST_FAIL_inst                                                     0x008F
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_3_shift                             (3)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_3_mask                              (0x00000008)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_3(data)                             (0x00000008&((data)<<3))
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_3_src(data)                         ((0x00000008&(data))>>3)
#define CPU0_ITAG_BIST_FAIL_get_cpu0_itag_mbist_fail_3(data)                         ((0x00000008&(data))>>3)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_2_shift                             (2)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_2_mask                              (0x00000004)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_2(data)                             (0x00000004&((data)<<2))
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_2_src(data)                         ((0x00000004&(data))>>2)
#define CPU0_ITAG_BIST_FAIL_get_cpu0_itag_mbist_fail_2(data)                         ((0x00000004&(data))>>2)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_1_shift                             (1)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_1_mask                              (0x00000002)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_1(data)                             (0x00000002&((data)<<1))
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_1_src(data)                         ((0x00000002&(data))>>1)
#define CPU0_ITAG_BIST_FAIL_get_cpu0_itag_mbist_fail_1(data)                         ((0x00000002&(data))>>1)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_0_shift                             (0)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_0_mask                              (0x00000001)
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_0(data)                             (0x00000001&((data)<<0))
#define CPU0_ITAG_BIST_FAIL_cpu0_itag_mbist_fail_0_src(data)                         ((0x00000001&(data))>>0)
#define CPU0_ITAG_BIST_FAIL_get_cpu0_itag_mbist_fail_0(data)                         ((0x00000001&(data))>>0)


#define CPU1_ITAG_BIST_FAIL                                                          0x1805C240
#define CPU1_ITAG_BIST_FAIL_reg_addr                                                 "0xB805C240"
#define CPU1_ITAG_BIST_FAIL_reg                                                      0xB805C240
#define set_CPU1_ITAG_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_ITAG_BIST_FAIL_reg)=data)
#define get_CPU1_ITAG_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_ITAG_BIST_FAIL_reg))
#define CPU1_ITAG_BIST_FAIL_inst_adr                                                 "0x0090"
#define CPU1_ITAG_BIST_FAIL_inst                                                     0x0090
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_3_shift                             (3)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_3_mask                              (0x00000008)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_3(data)                             (0x00000008&((data)<<3))
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_3_src(data)                         ((0x00000008&(data))>>3)
#define CPU1_ITAG_BIST_FAIL_get_cpu1_itag_mbist_fail_3(data)                         ((0x00000008&(data))>>3)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_2_shift                             (2)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_2_mask                              (0x00000004)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_2(data)                             (0x00000004&((data)<<2))
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_2_src(data)                         ((0x00000004&(data))>>2)
#define CPU1_ITAG_BIST_FAIL_get_cpu1_itag_mbist_fail_2(data)                         ((0x00000004&(data))>>2)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_1_shift                             (1)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_1_mask                              (0x00000002)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_1(data)                             (0x00000002&((data)<<1))
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_1_src(data)                         ((0x00000002&(data))>>1)
#define CPU1_ITAG_BIST_FAIL_get_cpu1_itag_mbist_fail_1(data)                         ((0x00000002&(data))>>1)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_0_shift                             (0)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_0_mask                              (0x00000001)
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_0(data)                             (0x00000001&((data)<<0))
#define CPU1_ITAG_BIST_FAIL_cpu1_itag_mbist_fail_0_src(data)                         ((0x00000001&(data))>>0)
#define CPU1_ITAG_BIST_FAIL_get_cpu1_itag_mbist_fail_0(data)                         ((0x00000001&(data))>>0)


#define CPU0_ITAG_DRF_BIST_FAIL                                                      0x1805C244
#define CPU0_ITAG_DRF_BIST_FAIL_reg_addr                                             "0xB805C244"
#define CPU0_ITAG_DRF_BIST_FAIL_reg                                                  0xB805C244
#define set_CPU0_ITAG_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_ITAG_DRF_BIST_FAIL_reg)=data)
#define get_CPU0_ITAG_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_ITAG_DRF_BIST_FAIL_reg))
#define CPU0_ITAG_DRF_BIST_FAIL_inst_adr                                             "0x0091"
#define CPU0_ITAG_DRF_BIST_FAIL_inst                                                 0x0091
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_3_shift                     (3)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_3_mask                      (0x00000008)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_3(data)                     (0x00000008&((data)<<3))
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_3_src(data)                 ((0x00000008&(data))>>3)
#define CPU0_ITAG_DRF_BIST_FAIL_get_cpu0_itag_drf_mbist_fail_3(data)                 ((0x00000008&(data))>>3)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_2_shift                     (2)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_2_mask                      (0x00000004)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_2(data)                     (0x00000004&((data)<<2))
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_2_src(data)                 ((0x00000004&(data))>>2)
#define CPU0_ITAG_DRF_BIST_FAIL_get_cpu0_itag_drf_mbist_fail_2(data)                 ((0x00000004&(data))>>2)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_1_shift                     (1)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_1_mask                      (0x00000002)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_1(data)                     (0x00000002&((data)<<1))
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_1_src(data)                 ((0x00000002&(data))>>1)
#define CPU0_ITAG_DRF_BIST_FAIL_get_cpu0_itag_drf_mbist_fail_1(data)                 ((0x00000002&(data))>>1)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_0_shift                     (0)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_0_mask                      (0x00000001)
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_0(data)                     (0x00000001&((data)<<0))
#define CPU0_ITAG_DRF_BIST_FAIL_cpu0_itag_drf_mbist_fail_0_src(data)                 ((0x00000001&(data))>>0)
#define CPU0_ITAG_DRF_BIST_FAIL_get_cpu0_itag_drf_mbist_fail_0(data)                 ((0x00000001&(data))>>0)


#define CPU1_ITAG_DRF_BIST_FAIL                                                      0x1805C248
#define CPU1_ITAG_DRF_BIST_FAIL_reg_addr                                             "0xB805C248"
#define CPU1_ITAG_DRF_BIST_FAIL_reg                                                  0xB805C248
#define set_CPU1_ITAG_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_ITAG_DRF_BIST_FAIL_reg)=data)
#define get_CPU1_ITAG_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_ITAG_DRF_BIST_FAIL_reg))
#define CPU1_ITAG_DRF_BIST_FAIL_inst_adr                                             "0x0092"
#define CPU1_ITAG_DRF_BIST_FAIL_inst                                                 0x0092
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_3_shift                     (3)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_3_mask                      (0x00000008)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_3(data)                     (0x00000008&((data)<<3))
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_3_src(data)                 ((0x00000008&(data))>>3)
#define CPU1_ITAG_DRF_BIST_FAIL_get_cpu1_itag_drf_mbist_fail_3(data)                 ((0x00000008&(data))>>3)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_2_shift                     (2)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_2_mask                      (0x00000004)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_2(data)                     (0x00000004&((data)<<2))
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_2_src(data)                 ((0x00000004&(data))>>2)
#define CPU1_ITAG_DRF_BIST_FAIL_get_cpu1_itag_drf_mbist_fail_2(data)                 ((0x00000004&(data))>>2)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_1_shift                     (1)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_1_mask                      (0x00000002)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_1(data)                     (0x00000002&((data)<<1))
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_1_src(data)                 ((0x00000002&(data))>>1)
#define CPU1_ITAG_DRF_BIST_FAIL_get_cpu1_itag_drf_mbist_fail_1(data)                 ((0x00000002&(data))>>1)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_0_shift                     (0)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_0_mask                      (0x00000001)
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_0(data)                     (0x00000001&((data)<<0))
#define CPU1_ITAG_DRF_BIST_FAIL_cpu1_itag_drf_mbist_fail_0_src(data)                 ((0x00000001&(data))>>0)
#define CPU1_ITAG_DRF_BIST_FAIL_get_cpu1_itag_drf_mbist_fail_0(data)                 ((0x00000001&(data))>>0)


#define CPU0_DDATA_BIST_FAIL                                                         0x1805C24C
#define CPU0_DDATA_BIST_FAIL_reg_addr                                                "0xB805C24C"
#define CPU0_DDATA_BIST_FAIL_reg                                                     0xB805C24C
#define set_CPU0_DDATA_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_DDATA_BIST_FAIL_reg)=data)
#define get_CPU0_DDATA_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_DDATA_BIST_FAIL_reg))
#define CPU0_DDATA_BIST_FAIL_inst_adr                                                "0x0093"
#define CPU0_DDATA_BIST_FAIL_inst                                                    0x0093
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_7_shift                           (7)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_7_mask                            (0x00000080)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_7(data)                           (0x00000080&((data)<<7))
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_7_src(data)                       ((0x00000080&(data))>>7)
#define CPU0_DDATA_BIST_FAIL_get_cpu0_ddata_mbist_fail_7(data)                       ((0x00000080&(data))>>7)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_6_shift                           (6)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_6_mask                            (0x00000040)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_6(data)                           (0x00000040&((data)<<6))
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_6_src(data)                       ((0x00000040&(data))>>6)
#define CPU0_DDATA_BIST_FAIL_get_cpu0_ddata_mbist_fail_6(data)                       ((0x00000040&(data))>>6)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_5_shift                           (5)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_5_mask                            (0x00000020)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_5(data)                           (0x00000020&((data)<<5))
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_5_src(data)                       ((0x00000020&(data))>>5)
#define CPU0_DDATA_BIST_FAIL_get_cpu0_ddata_mbist_fail_5(data)                       ((0x00000020&(data))>>5)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_4_shift                           (4)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_4_mask                            (0x00000010)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_4(data)                           (0x00000010&((data)<<4))
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_4_src(data)                       ((0x00000010&(data))>>4)
#define CPU0_DDATA_BIST_FAIL_get_cpu0_ddata_mbist_fail_4(data)                       ((0x00000010&(data))>>4)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_3_shift                           (3)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_3_mask                            (0x00000008)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_3(data)                           (0x00000008&((data)<<3))
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_3_src(data)                       ((0x00000008&(data))>>3)
#define CPU0_DDATA_BIST_FAIL_get_cpu0_ddata_mbist_fail_3(data)                       ((0x00000008&(data))>>3)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_2_shift                           (2)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_2_mask                            (0x00000004)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_2(data)                           (0x00000004&((data)<<2))
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_2_src(data)                       ((0x00000004&(data))>>2)
#define CPU0_DDATA_BIST_FAIL_get_cpu0_ddata_mbist_fail_2(data)                       ((0x00000004&(data))>>2)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_1_shift                           (1)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_1_mask                            (0x00000002)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_1(data)                           (0x00000002&((data)<<1))
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_1_src(data)                       ((0x00000002&(data))>>1)
#define CPU0_DDATA_BIST_FAIL_get_cpu0_ddata_mbist_fail_1(data)                       ((0x00000002&(data))>>1)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_0_shift                           (0)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_0_mask                            (0x00000001)
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_0(data)                           (0x00000001&((data)<<0))
#define CPU0_DDATA_BIST_FAIL_cpu0_ddata_mbist_fail_0_src(data)                       ((0x00000001&(data))>>0)
#define CPU0_DDATA_BIST_FAIL_get_cpu0_ddata_mbist_fail_0(data)                       ((0x00000001&(data))>>0)


#define CPU1_DDATA_BIST_FAIL                                                         0x1805C250
#define CPU1_DDATA_BIST_FAIL_reg_addr                                                "0xB805C250"
#define CPU1_DDATA_BIST_FAIL_reg                                                     0xB805C250
#define set_CPU1_DDATA_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_DDATA_BIST_FAIL_reg)=data)
#define get_CPU1_DDATA_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_DDATA_BIST_FAIL_reg))
#define CPU1_DDATA_BIST_FAIL_inst_adr                                                "0x0094"
#define CPU1_DDATA_BIST_FAIL_inst                                                    0x0094
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_7_shift                           (7)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_7_mask                            (0x00000080)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_7(data)                           (0x00000080&((data)<<7))
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_7_src(data)                       ((0x00000080&(data))>>7)
#define CPU1_DDATA_BIST_FAIL_get_cpu1_ddata_mbist_fail_7(data)                       ((0x00000080&(data))>>7)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_6_shift                           (6)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_6_mask                            (0x00000040)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_6(data)                           (0x00000040&((data)<<6))
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_6_src(data)                       ((0x00000040&(data))>>6)
#define CPU1_DDATA_BIST_FAIL_get_cpu1_ddata_mbist_fail_6(data)                       ((0x00000040&(data))>>6)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_5_shift                           (5)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_5_mask                            (0x00000020)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_5(data)                           (0x00000020&((data)<<5))
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_5_src(data)                       ((0x00000020&(data))>>5)
#define CPU1_DDATA_BIST_FAIL_get_cpu1_ddata_mbist_fail_5(data)                       ((0x00000020&(data))>>5)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_4_shift                           (4)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_4_mask                            (0x00000010)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_4(data)                           (0x00000010&((data)<<4))
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_4_src(data)                       ((0x00000010&(data))>>4)
#define CPU1_DDATA_BIST_FAIL_get_cpu1_ddata_mbist_fail_4(data)                       ((0x00000010&(data))>>4)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_3_shift                           (3)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_3_mask                            (0x00000008)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_3(data)                           (0x00000008&((data)<<3))
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_3_src(data)                       ((0x00000008&(data))>>3)
#define CPU1_DDATA_BIST_FAIL_get_cpu1_ddata_mbist_fail_3(data)                       ((0x00000008&(data))>>3)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_2_shift                           (2)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_2_mask                            (0x00000004)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_2(data)                           (0x00000004&((data)<<2))
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_2_src(data)                       ((0x00000004&(data))>>2)
#define CPU1_DDATA_BIST_FAIL_get_cpu1_ddata_mbist_fail_2(data)                       ((0x00000004&(data))>>2)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_1_shift                           (1)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_1_mask                            (0x00000002)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_1(data)                           (0x00000002&((data)<<1))
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_1_src(data)                       ((0x00000002&(data))>>1)
#define CPU1_DDATA_BIST_FAIL_get_cpu1_ddata_mbist_fail_1(data)                       ((0x00000002&(data))>>1)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_0_shift                           (0)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_0_mask                            (0x00000001)
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_0(data)                           (0x00000001&((data)<<0))
#define CPU1_DDATA_BIST_FAIL_cpu1_ddata_mbist_fail_0_src(data)                       ((0x00000001&(data))>>0)
#define CPU1_DDATA_BIST_FAIL_get_cpu1_ddata_mbist_fail_0(data)                       ((0x00000001&(data))>>0)


#define CPU0_DDATA_DRF_BIST_FAIL                                                     0x1805C254
#define CPU0_DDATA_DRF_BIST_FAIL_reg_addr                                            "0xB805C254"
#define CPU0_DDATA_DRF_BIST_FAIL_reg                                                 0xB805C254
#define set_CPU0_DDATA_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_DDATA_DRF_BIST_FAIL_reg)=data)
#define get_CPU0_DDATA_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_DDATA_DRF_BIST_FAIL_reg))
#define CPU0_DDATA_DRF_BIST_FAIL_inst_adr                                            "0x0095"
#define CPU0_DDATA_DRF_BIST_FAIL_inst                                                0x0095
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_7_shift                   (7)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_7_mask                    (0x00000080)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_7(data)                   (0x00000080&((data)<<7))
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_7_src(data)               ((0x00000080&(data))>>7)
#define CPU0_DDATA_DRF_BIST_FAIL_get_cpu0_ddata_drf_mbist_fail_7(data)               ((0x00000080&(data))>>7)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_6_shift                   (6)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_6_mask                    (0x00000040)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_6(data)                   (0x00000040&((data)<<6))
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_6_src(data)               ((0x00000040&(data))>>6)
#define CPU0_DDATA_DRF_BIST_FAIL_get_cpu0_ddata_drf_mbist_fail_6(data)               ((0x00000040&(data))>>6)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_5_shift                   (5)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_5_mask                    (0x00000020)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_5(data)                   (0x00000020&((data)<<5))
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_5_src(data)               ((0x00000020&(data))>>5)
#define CPU0_DDATA_DRF_BIST_FAIL_get_cpu0_ddata_drf_mbist_fail_5(data)               ((0x00000020&(data))>>5)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_4_shift                   (4)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_4_mask                    (0x00000010)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_4(data)                   (0x00000010&((data)<<4))
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_4_src(data)               ((0x00000010&(data))>>4)
#define CPU0_DDATA_DRF_BIST_FAIL_get_cpu0_ddata_drf_mbist_fail_4(data)               ((0x00000010&(data))>>4)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_3_shift                   (3)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_3_mask                    (0x00000008)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_3(data)                   (0x00000008&((data)<<3))
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_3_src(data)               ((0x00000008&(data))>>3)
#define CPU0_DDATA_DRF_BIST_FAIL_get_cpu0_ddata_drf_mbist_fail_3(data)               ((0x00000008&(data))>>3)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_2_shift                   (2)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_2_mask                    (0x00000004)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_2(data)                   (0x00000004&((data)<<2))
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_2_src(data)               ((0x00000004&(data))>>2)
#define CPU0_DDATA_DRF_BIST_FAIL_get_cpu0_ddata_drf_mbist_fail_2(data)               ((0x00000004&(data))>>2)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_1_shift                   (1)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_1_mask                    (0x00000002)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_1(data)                   (0x00000002&((data)<<1))
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_1_src(data)               ((0x00000002&(data))>>1)
#define CPU0_DDATA_DRF_BIST_FAIL_get_cpu0_ddata_drf_mbist_fail_1(data)               ((0x00000002&(data))>>1)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_0_shift                   (0)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_0_mask                    (0x00000001)
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_0(data)                   (0x00000001&((data)<<0))
#define CPU0_DDATA_DRF_BIST_FAIL_cpu0_ddata_drf_mbist_fail_0_src(data)               ((0x00000001&(data))>>0)
#define CPU0_DDATA_DRF_BIST_FAIL_get_cpu0_ddata_drf_mbist_fail_0(data)               ((0x00000001&(data))>>0)


#define CPU1_DDATA_DRF_BIST_FAIL                                                     0x1805C258
#define CPU1_DDATA_DRF_BIST_FAIL_reg_addr                                            "0xB805C258"
#define CPU1_DDATA_DRF_BIST_FAIL_reg                                                 0xB805C258
#define set_CPU1_DDATA_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_DDATA_DRF_BIST_FAIL_reg)=data)
#define get_CPU1_DDATA_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_DDATA_DRF_BIST_FAIL_reg))
#define CPU1_DDATA_DRF_BIST_FAIL_inst_adr                                            "0x0096"
#define CPU1_DDATA_DRF_BIST_FAIL_inst                                                0x0096
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_7_shift                   (7)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_7_mask                    (0x00000080)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_7(data)                   (0x00000080&((data)<<7))
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_7_src(data)               ((0x00000080&(data))>>7)
#define CPU1_DDATA_DRF_BIST_FAIL_get_cpu1_ddata_drf_mbist_fail_7(data)               ((0x00000080&(data))>>7)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_6_shift                   (6)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_6_mask                    (0x00000040)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_6(data)                   (0x00000040&((data)<<6))
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_6_src(data)               ((0x00000040&(data))>>6)
#define CPU1_DDATA_DRF_BIST_FAIL_get_cpu1_ddata_drf_mbist_fail_6(data)               ((0x00000040&(data))>>6)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_5_shift                   (5)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_5_mask                    (0x00000020)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_5(data)                   (0x00000020&((data)<<5))
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_5_src(data)               ((0x00000020&(data))>>5)
#define CPU1_DDATA_DRF_BIST_FAIL_get_cpu1_ddata_drf_mbist_fail_5(data)               ((0x00000020&(data))>>5)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_4_shift                   (4)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_4_mask                    (0x00000010)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_4(data)                   (0x00000010&((data)<<4))
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_4_src(data)               ((0x00000010&(data))>>4)
#define CPU1_DDATA_DRF_BIST_FAIL_get_cpu1_ddata_drf_mbist_fail_4(data)               ((0x00000010&(data))>>4)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_3_shift                   (3)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_3_mask                    (0x00000008)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_3(data)                   (0x00000008&((data)<<3))
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_3_src(data)               ((0x00000008&(data))>>3)
#define CPU1_DDATA_DRF_BIST_FAIL_get_cpu1_ddata_drf_mbist_fail_3(data)               ((0x00000008&(data))>>3)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_2_shift                   (2)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_2_mask                    (0x00000004)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_2(data)                   (0x00000004&((data)<<2))
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_2_src(data)               ((0x00000004&(data))>>2)
#define CPU1_DDATA_DRF_BIST_FAIL_get_cpu1_ddata_drf_mbist_fail_2(data)               ((0x00000004&(data))>>2)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_1_shift                   (1)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_1_mask                    (0x00000002)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_1(data)                   (0x00000002&((data)<<1))
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_1_src(data)               ((0x00000002&(data))>>1)
#define CPU1_DDATA_DRF_BIST_FAIL_get_cpu1_ddata_drf_mbist_fail_1(data)               ((0x00000002&(data))>>1)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_0_shift                   (0)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_0_mask                    (0x00000001)
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_0(data)                   (0x00000001&((data)<<0))
#define CPU1_DDATA_DRF_BIST_FAIL_cpu1_ddata_drf_mbist_fail_0_src(data)               ((0x00000001&(data))>>0)
#define CPU1_DDATA_DRF_BIST_FAIL_get_cpu1_ddata_drf_mbist_fail_0(data)               ((0x00000001&(data))>>0)


#define CPU0_DTAG_BIST_FAIL                                                          0x1805C25C
#define CPU0_DTAG_BIST_FAIL_reg_addr                                                 "0xB805C25C"
#define CPU0_DTAG_BIST_FAIL_reg                                                      0xB805C25C
#define set_CPU0_DTAG_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_DTAG_BIST_FAIL_reg)=data)
#define get_CPU0_DTAG_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_DTAG_BIST_FAIL_reg))
#define CPU0_DTAG_BIST_FAIL_inst_adr                                                 "0x0097"
#define CPU0_DTAG_BIST_FAIL_inst                                                     0x0097
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_3_shift                             (3)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_3_mask                              (0x00000008)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_3(data)                             (0x00000008&((data)<<3))
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_3_src(data)                         ((0x00000008&(data))>>3)
#define CPU0_DTAG_BIST_FAIL_get_cpu0_dtag_mbist_fail_3(data)                         ((0x00000008&(data))>>3)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_2_shift                             (2)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_2_mask                              (0x00000004)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_2(data)                             (0x00000004&((data)<<2))
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_2_src(data)                         ((0x00000004&(data))>>2)
#define CPU0_DTAG_BIST_FAIL_get_cpu0_dtag_mbist_fail_2(data)                         ((0x00000004&(data))>>2)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_1_shift                             (1)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_1_mask                              (0x00000002)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_1(data)                             (0x00000002&((data)<<1))
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_1_src(data)                         ((0x00000002&(data))>>1)
#define CPU0_DTAG_BIST_FAIL_get_cpu0_dtag_mbist_fail_1(data)                         ((0x00000002&(data))>>1)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_0_shift                             (0)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_0_mask                              (0x00000001)
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_0(data)                             (0x00000001&((data)<<0))
#define CPU0_DTAG_BIST_FAIL_cpu0_dtag_mbist_fail_0_src(data)                         ((0x00000001&(data))>>0)
#define CPU0_DTAG_BIST_FAIL_get_cpu0_dtag_mbist_fail_0(data)                         ((0x00000001&(data))>>0)


#define CPU1_DTAG_BIST_FAIL                                                          0x1805C260
#define CPU1_DTAG_BIST_FAIL_reg_addr                                                 "0xB805C260"
#define CPU1_DTAG_BIST_FAIL_reg                                                      0xB805C260
#define set_CPU1_DTAG_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_DTAG_BIST_FAIL_reg)=data)
#define get_CPU1_DTAG_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_DTAG_BIST_FAIL_reg))
#define CPU1_DTAG_BIST_FAIL_inst_adr                                                 "0x0098"
#define CPU1_DTAG_BIST_FAIL_inst                                                     0x0098
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_3_shift                             (3)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_3_mask                              (0x00000008)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_3(data)                             (0x00000008&((data)<<3))
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_3_src(data)                         ((0x00000008&(data))>>3)
#define CPU1_DTAG_BIST_FAIL_get_cpu1_dtag_mbist_fail_3(data)                         ((0x00000008&(data))>>3)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_2_shift                             (2)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_2_mask                              (0x00000004)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_2(data)                             (0x00000004&((data)<<2))
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_2_src(data)                         ((0x00000004&(data))>>2)
#define CPU1_DTAG_BIST_FAIL_get_cpu1_dtag_mbist_fail_2(data)                         ((0x00000004&(data))>>2)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_1_shift                             (1)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_1_mask                              (0x00000002)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_1(data)                             (0x00000002&((data)<<1))
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_1_src(data)                         ((0x00000002&(data))>>1)
#define CPU1_DTAG_BIST_FAIL_get_cpu1_dtag_mbist_fail_1(data)                         ((0x00000002&(data))>>1)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_0_shift                             (0)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_0_mask                              (0x00000001)
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_0(data)                             (0x00000001&((data)<<0))
#define CPU1_DTAG_BIST_FAIL_cpu1_dtag_mbist_fail_0_src(data)                         ((0x00000001&(data))>>0)
#define CPU1_DTAG_BIST_FAIL_get_cpu1_dtag_mbist_fail_0(data)                         ((0x00000001&(data))>>0)


#define CPU0_DTAG_DRF_BIST_FAIL                                                      0x1805C264
#define CPU0_DTAG_DRF_BIST_FAIL_reg_addr                                             "0xB805C264"
#define CPU0_DTAG_DRF_BIST_FAIL_reg                                                  0xB805C264
#define set_CPU0_DTAG_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_DTAG_DRF_BIST_FAIL_reg)=data)
#define get_CPU0_DTAG_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_DTAG_DRF_BIST_FAIL_reg))
#define CPU0_DTAG_DRF_BIST_FAIL_inst_adr                                             "0x0099"
#define CPU0_DTAG_DRF_BIST_FAIL_inst                                                 0x0099
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_3_shift                     (3)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_3_mask                      (0x00000008)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_3(data)                     (0x00000008&((data)<<3))
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_3_src(data)                 ((0x00000008&(data))>>3)
#define CPU0_DTAG_DRF_BIST_FAIL_get_cpu0_dtag_drf_mbist_fail_3(data)                 ((0x00000008&(data))>>3)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_2_shift                     (2)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_2_mask                      (0x00000004)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_2(data)                     (0x00000004&((data)<<2))
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_2_src(data)                 ((0x00000004&(data))>>2)
#define CPU0_DTAG_DRF_BIST_FAIL_get_cpu0_dtag_drf_mbist_fail_2(data)                 ((0x00000004&(data))>>2)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_1_shift                     (1)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_1_mask                      (0x00000002)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_1(data)                     (0x00000002&((data)<<1))
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_1_src(data)                 ((0x00000002&(data))>>1)
#define CPU0_DTAG_DRF_BIST_FAIL_get_cpu0_dtag_drf_mbist_fail_1(data)                 ((0x00000002&(data))>>1)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_0_shift                     (0)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_0_mask                      (0x00000001)
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_0(data)                     (0x00000001&((data)<<0))
#define CPU0_DTAG_DRF_BIST_FAIL_cpu0_dtag_drf_mbist_fail_0_src(data)                 ((0x00000001&(data))>>0)
#define CPU0_DTAG_DRF_BIST_FAIL_get_cpu0_dtag_drf_mbist_fail_0(data)                 ((0x00000001&(data))>>0)


#define CPU1_DTAG_DRF_BIST_FAIL                                                      0x1805C268
#define CPU1_DTAG_DRF_BIST_FAIL_reg_addr                                             "0xB805C268"
#define CPU1_DTAG_DRF_BIST_FAIL_reg                                                  0xB805C268
#define set_CPU1_DTAG_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_DTAG_DRF_BIST_FAIL_reg)=data)
#define get_CPU1_DTAG_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_DTAG_DRF_BIST_FAIL_reg))
#define CPU1_DTAG_DRF_BIST_FAIL_inst_adr                                             "0x009A"
#define CPU1_DTAG_DRF_BIST_FAIL_inst                                                 0x009A
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_3_shift                     (3)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_3_mask                      (0x00000008)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_3(data)                     (0x00000008&((data)<<3))
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_3_src(data)                 ((0x00000008&(data))>>3)
#define CPU1_DTAG_DRF_BIST_FAIL_get_cpu1_dtag_drf_mbist_fail_3(data)                 ((0x00000008&(data))>>3)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_2_shift                     (2)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_2_mask                      (0x00000004)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_2(data)                     (0x00000004&((data)<<2))
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_2_src(data)                 ((0x00000004&(data))>>2)
#define CPU1_DTAG_DRF_BIST_FAIL_get_cpu1_dtag_drf_mbist_fail_2(data)                 ((0x00000004&(data))>>2)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_1_shift                     (1)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_1_mask                      (0x00000002)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_1(data)                     (0x00000002&((data)<<1))
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_1_src(data)                 ((0x00000002&(data))>>1)
#define CPU1_DTAG_DRF_BIST_FAIL_get_cpu1_dtag_drf_mbist_fail_1(data)                 ((0x00000002&(data))>>1)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_0_shift                     (0)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_0_mask                      (0x00000001)
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_0(data)                     (0x00000001&((data)<<0))
#define CPU1_DTAG_DRF_BIST_FAIL_cpu1_dtag_drf_mbist_fail_0_src(data)                 ((0x00000001&(data))>>0)
#define CPU1_DTAG_DRF_BIST_FAIL_get_cpu1_dtag_drf_mbist_fail_0(data)                 ((0x00000001&(data))>>0)


#define CPU0_BTAC_BIST_FAIL                                                          0x1805C26C
#define CPU0_BTAC_BIST_FAIL_reg_addr                                                 "0xB805C26C"
#define CPU0_BTAC_BIST_FAIL_reg                                                      0xB805C26C
#define set_CPU0_BTAC_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_BTAC_BIST_FAIL_reg)=data)
#define get_CPU0_BTAC_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_BTAC_BIST_FAIL_reg))
#define CPU0_BTAC_BIST_FAIL_inst_adr                                                 "0x009B"
#define CPU0_BTAC_BIST_FAIL_inst                                                     0x009B
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_3_shift                             (3)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_3_mask                              (0x00000008)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_3(data)                             (0x00000008&((data)<<3))
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_3_src(data)                         ((0x00000008&(data))>>3)
#define CPU0_BTAC_BIST_FAIL_get_cpu0_btac_mbist_fail_3(data)                         ((0x00000008&(data))>>3)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_2_shift                             (2)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_2_mask                              (0x00000004)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_2(data)                             (0x00000004&((data)<<2))
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_2_src(data)                         ((0x00000004&(data))>>2)
#define CPU0_BTAC_BIST_FAIL_get_cpu0_btac_mbist_fail_2(data)                         ((0x00000004&(data))>>2)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_1_shift                             (1)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_1_mask                              (0x00000002)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_1(data)                             (0x00000002&((data)<<1))
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_1_src(data)                         ((0x00000002&(data))>>1)
#define CPU0_BTAC_BIST_FAIL_get_cpu0_btac_mbist_fail_1(data)                         ((0x00000002&(data))>>1)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_0_shift                             (0)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_0_mask                              (0x00000001)
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_0(data)                             (0x00000001&((data)<<0))
#define CPU0_BTAC_BIST_FAIL_cpu0_btac_mbist_fail_0_src(data)                         ((0x00000001&(data))>>0)
#define CPU0_BTAC_BIST_FAIL_get_cpu0_btac_mbist_fail_0(data)                         ((0x00000001&(data))>>0)


#define CPU1_BTAC_BIST_FAIL                                                          0x1805C270
#define CPU1_BTAC_BIST_FAIL_reg_addr                                                 "0xB805C270"
#define CPU1_BTAC_BIST_FAIL_reg                                                      0xB805C270
#define set_CPU1_BTAC_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_BTAC_BIST_FAIL_reg)=data)
#define get_CPU1_BTAC_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_BTAC_BIST_FAIL_reg))
#define CPU1_BTAC_BIST_FAIL_inst_adr                                                 "0x009C"
#define CPU1_BTAC_BIST_FAIL_inst                                                     0x009C
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_3_shift                             (3)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_3_mask                              (0x00000008)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_3(data)                             (0x00000008&((data)<<3))
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_3_src(data)                         ((0x00000008&(data))>>3)
#define CPU1_BTAC_BIST_FAIL_get_cpu1_btac_mbist_fail_3(data)                         ((0x00000008&(data))>>3)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_2_shift                             (2)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_2_mask                              (0x00000004)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_2(data)                             (0x00000004&((data)<<2))
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_2_src(data)                         ((0x00000004&(data))>>2)
#define CPU1_BTAC_BIST_FAIL_get_cpu1_btac_mbist_fail_2(data)                         ((0x00000004&(data))>>2)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_1_shift                             (1)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_1_mask                              (0x00000002)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_1(data)                             (0x00000002&((data)<<1))
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_1_src(data)                         ((0x00000002&(data))>>1)
#define CPU1_BTAC_BIST_FAIL_get_cpu1_btac_mbist_fail_1(data)                         ((0x00000002&(data))>>1)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_0_shift                             (0)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_0_mask                              (0x00000001)
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_0(data)                             (0x00000001&((data)<<0))
#define CPU1_BTAC_BIST_FAIL_cpu1_btac_mbist_fail_0_src(data)                         ((0x00000001&(data))>>0)
#define CPU1_BTAC_BIST_FAIL_get_cpu1_btac_mbist_fail_0(data)                         ((0x00000001&(data))>>0)


#define CPU0_BTAC_DRF_BIST_FAIL                                                      0x1805C274
#define CPU0_BTAC_DRF_BIST_FAIL_reg_addr                                             "0xB805C274"
#define CPU0_BTAC_DRF_BIST_FAIL_reg                                                  0xB805C274
#define set_CPU0_BTAC_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_BTAC_DRF_BIST_FAIL_reg)=data)
#define get_CPU0_BTAC_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_BTAC_DRF_BIST_FAIL_reg))
#define CPU0_BTAC_DRF_BIST_FAIL_inst_adr                                             "0x009D"
#define CPU0_BTAC_DRF_BIST_FAIL_inst                                                 0x009D
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_3_shift                     (3)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_3_mask                      (0x00000008)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_3(data)                     (0x00000008&((data)<<3))
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_3_src(data)                 ((0x00000008&(data))>>3)
#define CPU0_BTAC_DRF_BIST_FAIL_get_cpu0_btac_drf_mbist_fail_3(data)                 ((0x00000008&(data))>>3)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_2_shift                     (2)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_2_mask                      (0x00000004)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_2(data)                     (0x00000004&((data)<<2))
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_2_src(data)                 ((0x00000004&(data))>>2)
#define CPU0_BTAC_DRF_BIST_FAIL_get_cpu0_btac_drf_mbist_fail_2(data)                 ((0x00000004&(data))>>2)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_1_shift                     (1)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_1_mask                      (0x00000002)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_1(data)                     (0x00000002&((data)<<1))
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_1_src(data)                 ((0x00000002&(data))>>1)
#define CPU0_BTAC_DRF_BIST_FAIL_get_cpu0_btac_drf_mbist_fail_1(data)                 ((0x00000002&(data))>>1)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_0_shift                     (0)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_0_mask                      (0x00000001)
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_0(data)                     (0x00000001&((data)<<0))
#define CPU0_BTAC_DRF_BIST_FAIL_cpu0_btac_drf_mbist_fail_0_src(data)                 ((0x00000001&(data))>>0)
#define CPU0_BTAC_DRF_BIST_FAIL_get_cpu0_btac_drf_mbist_fail_0(data)                 ((0x00000001&(data))>>0)


#define CPU1_BTAC_DRF_BIST_FAIL                                                      0x1805C278
#define CPU1_BTAC_DRF_BIST_FAIL_reg_addr                                             "0xB805C278"
#define CPU1_BTAC_DRF_BIST_FAIL_reg                                                  0xB805C278
#define set_CPU1_BTAC_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_BTAC_DRF_BIST_FAIL_reg)=data)
#define get_CPU1_BTAC_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_BTAC_DRF_BIST_FAIL_reg))
#define CPU1_BTAC_DRF_BIST_FAIL_inst_adr                                             "0x009E"
#define CPU1_BTAC_DRF_BIST_FAIL_inst                                                 0x009E
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_3_shift                     (3)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_3_mask                      (0x00000008)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_3(data)                     (0x00000008&((data)<<3))
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_3_src(data)                 ((0x00000008&(data))>>3)
#define CPU1_BTAC_DRF_BIST_FAIL_get_cpu1_btac_drf_mbist_fail_3(data)                 ((0x00000008&(data))>>3)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_2_shift                     (2)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_2_mask                      (0x00000004)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_2(data)                     (0x00000004&((data)<<2))
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_2_src(data)                 ((0x00000004&(data))>>2)
#define CPU1_BTAC_DRF_BIST_FAIL_get_cpu1_btac_drf_mbist_fail_2(data)                 ((0x00000004&(data))>>2)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_1_shift                     (1)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_1_mask                      (0x00000002)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_1(data)                     (0x00000002&((data)<<1))
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_1_src(data)                 ((0x00000002&(data))>>1)
#define CPU1_BTAC_DRF_BIST_FAIL_get_cpu1_btac_drf_mbist_fail_1(data)                 ((0x00000002&(data))>>1)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_0_shift                     (0)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_0_mask                      (0x00000001)
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_0(data)                     (0x00000001&((data)<<0))
#define CPU1_BTAC_DRF_BIST_FAIL_cpu1_btac_drf_mbist_fail_0_src(data)                 ((0x00000001&(data))>>0)
#define CPU1_BTAC_DRF_BIST_FAIL_get_cpu1_btac_drf_mbist_fail_0(data)                 ((0x00000001&(data))>>0)


#define CPU0_GHB_BIST_FAIL                                                           0x1805C27C
#define CPU0_GHB_BIST_FAIL_reg_addr                                                  "0xB805C27C"
#define CPU0_GHB_BIST_FAIL_reg                                                       0xB805C27C
#define set_CPU0_GHB_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_GHB_BIST_FAIL_reg)=data)
#define get_CPU0_GHB_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_GHB_BIST_FAIL_reg))
#define CPU0_GHB_BIST_FAIL_inst_adr                                                  "0x009F"
#define CPU0_GHB_BIST_FAIL_inst                                                      0x009F
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_3_shift                               (3)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_3_mask                                (0x00000008)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_3(data)                               (0x00000008&((data)<<3))
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_3_src(data)                           ((0x00000008&(data))>>3)
#define CPU0_GHB_BIST_FAIL_get_cpu0_ghb_mbist_fail_3(data)                           ((0x00000008&(data))>>3)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_2_shift                               (2)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_2_mask                                (0x00000004)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_2(data)                               (0x00000004&((data)<<2))
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_2_src(data)                           ((0x00000004&(data))>>2)
#define CPU0_GHB_BIST_FAIL_get_cpu0_ghb_mbist_fail_2(data)                           ((0x00000004&(data))>>2)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_1_shift                               (1)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_1_mask                                (0x00000002)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_1(data)                               (0x00000002&((data)<<1))
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_1_src(data)                           ((0x00000002&(data))>>1)
#define CPU0_GHB_BIST_FAIL_get_cpu0_ghb_mbist_fail_1(data)                           ((0x00000002&(data))>>1)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_0_shift                               (0)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_0_mask                                (0x00000001)
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_0(data)                               (0x00000001&((data)<<0))
#define CPU0_GHB_BIST_FAIL_cpu0_ghb_mbist_fail_0_src(data)                           ((0x00000001&(data))>>0)
#define CPU0_GHB_BIST_FAIL_get_cpu0_ghb_mbist_fail_0(data)                           ((0x00000001&(data))>>0)


#define CPU1_GHB_BIST_FAIL                                                           0x1805C280
#define CPU1_GHB_BIST_FAIL_reg_addr                                                  "0xB805C280"
#define CPU1_GHB_BIST_FAIL_reg                                                       0xB805C280
#define set_CPU1_GHB_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_GHB_BIST_FAIL_reg)=data)
#define get_CPU1_GHB_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_GHB_BIST_FAIL_reg))
#define CPU1_GHB_BIST_FAIL_inst_adr                                                  "0x00A0"
#define CPU1_GHB_BIST_FAIL_inst                                                      0x00A0
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_3_shift                               (3)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_3_mask                                (0x00000008)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_3(data)                               (0x00000008&((data)<<3))
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_3_src(data)                           ((0x00000008&(data))>>3)
#define CPU1_GHB_BIST_FAIL_get_cpu1_ghb_mbist_fail_3(data)                           ((0x00000008&(data))>>3)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_2_shift                               (2)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_2_mask                                (0x00000004)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_2(data)                               (0x00000004&((data)<<2))
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_2_src(data)                           ((0x00000004&(data))>>2)
#define CPU1_GHB_BIST_FAIL_get_cpu1_ghb_mbist_fail_2(data)                           ((0x00000004&(data))>>2)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_1_shift                               (1)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_1_mask                                (0x00000002)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_1(data)                               (0x00000002&((data)<<1))
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_1_src(data)                           ((0x00000002&(data))>>1)
#define CPU1_GHB_BIST_FAIL_get_cpu1_ghb_mbist_fail_1(data)                           ((0x00000002&(data))>>1)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_0_shift                               (0)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_0_mask                                (0x00000001)
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_0(data)                               (0x00000001&((data)<<0))
#define CPU1_GHB_BIST_FAIL_cpu1_ghb_mbist_fail_0_src(data)                           ((0x00000001&(data))>>0)
#define CPU1_GHB_BIST_FAIL_get_cpu1_ghb_mbist_fail_0(data)                           ((0x00000001&(data))>>0)


#define CPU0_GHB_DRF_BIST_FAIL                                                       0x1805C284
#define CPU0_GHB_DRF_BIST_FAIL_reg_addr                                              "0xB805C284"
#define CPU0_GHB_DRF_BIST_FAIL_reg                                                   0xB805C284
#define set_CPU0_GHB_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_GHB_DRF_BIST_FAIL_reg)=data)
#define get_CPU0_GHB_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_GHB_DRF_BIST_FAIL_reg))
#define CPU0_GHB_DRF_BIST_FAIL_inst_adr                                              "0x00A1"
#define CPU0_GHB_DRF_BIST_FAIL_inst                                                  0x00A1
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_3_shift                       (3)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_3_mask                        (0x00000008)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_3(data)                       (0x00000008&((data)<<3))
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_3_src(data)                   ((0x00000008&(data))>>3)
#define CPU0_GHB_DRF_BIST_FAIL_get_cpu0_ghb_drf_mbist_fail_3(data)                   ((0x00000008&(data))>>3)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_2_shift                       (2)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_2_mask                        (0x00000004)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_2(data)                       (0x00000004&((data)<<2))
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_2_src(data)                   ((0x00000004&(data))>>2)
#define CPU0_GHB_DRF_BIST_FAIL_get_cpu0_ghb_drf_mbist_fail_2(data)                   ((0x00000004&(data))>>2)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_1_shift                       (1)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_1_mask                        (0x00000002)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_1(data)                       (0x00000002&((data)<<1))
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_1_src(data)                   ((0x00000002&(data))>>1)
#define CPU0_GHB_DRF_BIST_FAIL_get_cpu0_ghb_drf_mbist_fail_1(data)                   ((0x00000002&(data))>>1)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_0_shift                       (0)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_0_mask                        (0x00000001)
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_0(data)                       (0x00000001&((data)<<0))
#define CPU0_GHB_DRF_BIST_FAIL_cpu0_ghb_drf_mbist_fail_0_src(data)                   ((0x00000001&(data))>>0)
#define CPU0_GHB_DRF_BIST_FAIL_get_cpu0_ghb_drf_mbist_fail_0(data)                   ((0x00000001&(data))>>0)


#define CPU1_GHB_DRF_BIST_FAIL                                                       0x1805C288
#define CPU1_GHB_DRF_BIST_FAIL_reg_addr                                              "0xB805C288"
#define CPU1_GHB_DRF_BIST_FAIL_reg                                                   0xB805C288
#define set_CPU1_GHB_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_GHB_DRF_BIST_FAIL_reg)=data)
#define get_CPU1_GHB_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_GHB_DRF_BIST_FAIL_reg))
#define CPU1_GHB_DRF_BIST_FAIL_inst_adr                                              "0x00A2"
#define CPU1_GHB_DRF_BIST_FAIL_inst                                                  0x00A2
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_3_shift                       (3)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_3_mask                        (0x00000008)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_3(data)                       (0x00000008&((data)<<3))
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_3_src(data)                   ((0x00000008&(data))>>3)
#define CPU1_GHB_DRF_BIST_FAIL_get_cpu1_ghb_drf_mbist_fail_3(data)                   ((0x00000008&(data))>>3)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_2_shift                       (2)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_2_mask                        (0x00000004)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_2(data)                       (0x00000004&((data)<<2))
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_2_src(data)                   ((0x00000004&(data))>>2)
#define CPU1_GHB_DRF_BIST_FAIL_get_cpu1_ghb_drf_mbist_fail_2(data)                   ((0x00000004&(data))>>2)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_1_shift                       (1)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_1_mask                        (0x00000002)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_1(data)                       (0x00000002&((data)<<1))
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_1_src(data)                   ((0x00000002&(data))>>1)
#define CPU1_GHB_DRF_BIST_FAIL_get_cpu1_ghb_drf_mbist_fail_1(data)                   ((0x00000002&(data))>>1)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_0_shift                       (0)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_0_mask                        (0x00000001)
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_0(data)                       (0x00000001&((data)<<0))
#define CPU1_GHB_DRF_BIST_FAIL_cpu1_ghb_drf_mbist_fail_0_src(data)                   ((0x00000001&(data))>>0)
#define CPU1_GHB_DRF_BIST_FAIL_get_cpu1_ghb_drf_mbist_fail_0(data)                   ((0x00000001&(data))>>0)


#define CPU0_TLB_BIST_FAIL                                                           0x1805C28C
#define CPU0_TLB_BIST_FAIL_reg_addr                                                  "0xB805C28C"
#define CPU0_TLB_BIST_FAIL_reg                                                       0xB805C28C
#define set_CPU0_TLB_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_TLB_BIST_FAIL_reg)=data)
#define get_CPU0_TLB_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_TLB_BIST_FAIL_reg))
#define CPU0_TLB_BIST_FAIL_inst_adr                                                  "0x00A3"
#define CPU0_TLB_BIST_FAIL_inst                                                      0x00A3
#define CPU0_TLB_BIST_FAIL_cpu0_tlb_mbist_fail_1_shift                               (1)
#define CPU0_TLB_BIST_FAIL_cpu0_tlb_mbist_fail_1_mask                                (0x00000002)
#define CPU0_TLB_BIST_FAIL_cpu0_tlb_mbist_fail_1(data)                               (0x00000002&((data)<<1))
#define CPU0_TLB_BIST_FAIL_cpu0_tlb_mbist_fail_1_src(data)                           ((0x00000002&(data))>>1)
#define CPU0_TLB_BIST_FAIL_get_cpu0_tlb_mbist_fail_1(data)                           ((0x00000002&(data))>>1)
#define CPU0_TLB_BIST_FAIL_cpu0_tlb_mbist_fail_0_shift                               (0)
#define CPU0_TLB_BIST_FAIL_cpu0_tlb_mbist_fail_0_mask                                (0x00000001)
#define CPU0_TLB_BIST_FAIL_cpu0_tlb_mbist_fail_0(data)                               (0x00000001&((data)<<0))
#define CPU0_TLB_BIST_FAIL_cpu0_tlb_mbist_fail_0_src(data)                           ((0x00000001&(data))>>0)
#define CPU0_TLB_BIST_FAIL_get_cpu0_tlb_mbist_fail_0(data)                           ((0x00000001&(data))>>0)


#define CPU1_TLB_BIST_FAIL                                                           0x1805C290
#define CPU1_TLB_BIST_FAIL_reg_addr                                                  "0xB805C290"
#define CPU1_TLB_BIST_FAIL_reg                                                       0xB805C290
#define set_CPU1_TLB_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_TLB_BIST_FAIL_reg)=data)
#define get_CPU1_TLB_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_TLB_BIST_FAIL_reg))
#define CPU1_TLB_BIST_FAIL_inst_adr                                                  "0x00A4"
#define CPU1_TLB_BIST_FAIL_inst                                                      0x00A4
#define CPU1_TLB_BIST_FAIL_cpu1_tlb_mbist_fail_1_shift                               (1)
#define CPU1_TLB_BIST_FAIL_cpu1_tlb_mbist_fail_1_mask                                (0x00000002)
#define CPU1_TLB_BIST_FAIL_cpu1_tlb_mbist_fail_1(data)                               (0x00000002&((data)<<1))
#define CPU1_TLB_BIST_FAIL_cpu1_tlb_mbist_fail_1_src(data)                           ((0x00000002&(data))>>1)
#define CPU1_TLB_BIST_FAIL_get_cpu1_tlb_mbist_fail_1(data)                           ((0x00000002&(data))>>1)
#define CPU1_TLB_BIST_FAIL_cpu1_tlb_mbist_fail_0_shift                               (0)
#define CPU1_TLB_BIST_FAIL_cpu1_tlb_mbist_fail_0_mask                                (0x00000001)
#define CPU1_TLB_BIST_FAIL_cpu1_tlb_mbist_fail_0(data)                               (0x00000001&((data)<<0))
#define CPU1_TLB_BIST_FAIL_cpu1_tlb_mbist_fail_0_src(data)                           ((0x00000001&(data))>>0)
#define CPU1_TLB_BIST_FAIL_get_cpu1_tlb_mbist_fail_0(data)                           ((0x00000001&(data))>>0)


#define CPU0_TLB_DRF_BIST_FAIL                                                       0x1805C294
#define CPU0_TLB_DRF_BIST_FAIL_reg_addr                                              "0xB805C294"
#define CPU0_TLB_DRF_BIST_FAIL_reg                                                   0xB805C294
#define set_CPU0_TLB_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU0_TLB_DRF_BIST_FAIL_reg)=data)
#define get_CPU0_TLB_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU0_TLB_DRF_BIST_FAIL_reg))
#define CPU0_TLB_DRF_BIST_FAIL_inst_adr                                              "0x00A5"
#define CPU0_TLB_DRF_BIST_FAIL_inst                                                  0x00A5
#define CPU0_TLB_DRF_BIST_FAIL_cpu0_tlb_drf_mbist_fail_1_shift                       (1)
#define CPU0_TLB_DRF_BIST_FAIL_cpu0_tlb_drf_mbist_fail_1_mask                        (0x00000002)
#define CPU0_TLB_DRF_BIST_FAIL_cpu0_tlb_drf_mbist_fail_1(data)                       (0x00000002&((data)<<1))
#define CPU0_TLB_DRF_BIST_FAIL_cpu0_tlb_drf_mbist_fail_1_src(data)                   ((0x00000002&(data))>>1)
#define CPU0_TLB_DRF_BIST_FAIL_get_cpu0_tlb_drf_mbist_fail_1(data)                   ((0x00000002&(data))>>1)
#define CPU0_TLB_DRF_BIST_FAIL_cpu0_tlb_drf_mbist_fail_0_shift                       (0)
#define CPU0_TLB_DRF_BIST_FAIL_cpu0_tlb_drf_mbist_fail_0_mask                        (0x00000001)
#define CPU0_TLB_DRF_BIST_FAIL_cpu0_tlb_drf_mbist_fail_0(data)                       (0x00000001&((data)<<0))
#define CPU0_TLB_DRF_BIST_FAIL_cpu0_tlb_drf_mbist_fail_0_src(data)                   ((0x00000001&(data))>>0)
#define CPU0_TLB_DRF_BIST_FAIL_get_cpu0_tlb_drf_mbist_fail_0(data)                   ((0x00000001&(data))>>0)


#define CPU1_TLB_DRF_BIST_FAIL                                                       0x1805C298
#define CPU1_TLB_DRF_BIST_FAIL_reg_addr                                              "0xB805C298"
#define CPU1_TLB_DRF_BIST_FAIL_reg                                                   0xB805C298
#define set_CPU1_TLB_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CPU1_TLB_DRF_BIST_FAIL_reg)=data)
#define get_CPU1_TLB_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) CPU1_TLB_DRF_BIST_FAIL_reg))
#define CPU1_TLB_DRF_BIST_FAIL_inst_adr                                              "0x00A6"
#define CPU1_TLB_DRF_BIST_FAIL_inst                                                  0x00A6
#define CPU1_TLB_DRF_BIST_FAIL_cpu1_tlb_drf_mbist_fail_1_shift                       (1)
#define CPU1_TLB_DRF_BIST_FAIL_cpu1_tlb_drf_mbist_fail_1_mask                        (0x00000002)
#define CPU1_TLB_DRF_BIST_FAIL_cpu1_tlb_drf_mbist_fail_1(data)                       (0x00000002&((data)<<1))
#define CPU1_TLB_DRF_BIST_FAIL_cpu1_tlb_drf_mbist_fail_1_src(data)                   ((0x00000002&(data))>>1)
#define CPU1_TLB_DRF_BIST_FAIL_get_cpu1_tlb_drf_mbist_fail_1(data)                   ((0x00000002&(data))>>1)
#define CPU1_TLB_DRF_BIST_FAIL_cpu1_tlb_drf_mbist_fail_0_shift                       (0)
#define CPU1_TLB_DRF_BIST_FAIL_cpu1_tlb_drf_mbist_fail_0_mask                        (0x00000001)
#define CPU1_TLB_DRF_BIST_FAIL_cpu1_tlb_drf_mbist_fail_0(data)                       (0x00000001&((data)<<0))
#define CPU1_TLB_DRF_BIST_FAIL_cpu1_tlb_drf_mbist_fail_0_src(data)                   ((0x00000001&(data))>>0)
#define CPU1_TLB_DRF_BIST_FAIL_get_cpu1_tlb_drf_mbist_fail_0(data)                   ((0x00000001&(data))>>0)


#define SCU_BIST_FAIL_GROUP                                                          0x1805C29C
#define SCU_BIST_FAIL_GROUP_reg_addr                                                 "0xB805C29C"
#define SCU_BIST_FAIL_GROUP_reg                                                      0xB805C29C
#define set_SCU_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) SCU_BIST_FAIL_GROUP_reg)=data)
#define get_SCU_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) SCU_BIST_FAIL_GROUP_reg))
#define SCU_BIST_FAIL_GROUP_inst_adr                                                 "0x00A7"
#define SCU_BIST_FAIL_GROUP_inst                                                     0x00A7
#define SCU_BIST_FAIL_GROUP_scu_mbist_fail_group_shift                               (0)
#define SCU_BIST_FAIL_GROUP_scu_mbist_fail_group_mask                                (0x00000001)
#define SCU_BIST_FAIL_GROUP_scu_mbist_fail_group(data)                               (0x00000001&((data)<<0))
#define SCU_BIST_FAIL_GROUP_scu_mbist_fail_group_src(data)                           ((0x00000001&(data))>>0)
#define SCU_BIST_FAIL_GROUP_get_scu_mbist_fail_group(data)                           ((0x00000001&(data))>>0)


#define SCU_DRF_BIST_FAIL_GROUP                                                      0x1805C2A0
#define SCU_DRF_BIST_FAIL_GROUP_reg_addr                                             "0xB805C2A0"
#define SCU_DRF_BIST_FAIL_GROUP_reg                                                  0xB805C2A0
#define set_SCU_DRF_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) SCU_DRF_BIST_FAIL_GROUP_reg)=data)
#define get_SCU_DRF_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) SCU_DRF_BIST_FAIL_GROUP_reg))
#define SCU_DRF_BIST_FAIL_GROUP_inst_adr                                             "0x00A8"
#define SCU_DRF_BIST_FAIL_GROUP_inst                                                 0x00A8
#define SCU_DRF_BIST_FAIL_GROUP_scu_drf_mbist_fail_group_shift                       (0)
#define SCU_DRF_BIST_FAIL_GROUP_scu_drf_mbist_fail_group_mask                        (0x00000001)
#define SCU_DRF_BIST_FAIL_GROUP_scu_drf_mbist_fail_group(data)                       (0x00000001&((data)<<0))
#define SCU_DRF_BIST_FAIL_GROUP_scu_drf_mbist_fail_group_src(data)                   ((0x00000001&(data))>>0)
#define SCU_DRF_BIST_FAIL_GROUP_get_scu_drf_mbist_fail_group(data)                   ((0x00000001&(data))>>0)


#define SCU_BIST_FAIL_SEP                                                            0x1805C2A4
#define SCU_BIST_FAIL_SEP_reg_addr                                                   "0xB805C2A4"
#define SCU_BIST_FAIL_SEP_reg                                                        0xB805C2A4
#define set_SCU_BIST_FAIL_SEP_reg(data)   (*((volatile unsigned int*) SCU_BIST_FAIL_SEP_reg)=data)
#define get_SCU_BIST_FAIL_SEP_reg   (*((volatile unsigned int*) SCU_BIST_FAIL_SEP_reg))
#define SCU_BIST_FAIL_SEP_inst_adr                                                   "0x00A9"
#define SCU_BIST_FAIL_SEP_inst                                                       0x00A9
#define SCU_BIST_FAIL_SEP_scu_mbist_fail_shift                                       (0)
#define SCU_BIST_FAIL_SEP_scu_mbist_fail_mask                                        (0x000000FF)
#define SCU_BIST_FAIL_SEP_scu_mbist_fail(data)                                       (0x000000FF&((data)<<0))
#define SCU_BIST_FAIL_SEP_scu_mbist_fail_src(data)                                   ((0x000000FF&(data))>>0)
#define SCU_BIST_FAIL_SEP_get_scu_mbist_fail(data)                                   ((0x000000FF&(data))>>0)


#define SCU_DRF_BIST_FAIL                                                            0x1805C2A8
#define SCU_DRF_BIST_FAIL_reg_addr                                                   "0xB805C2A8"
#define SCU_DRF_BIST_FAIL_reg                                                        0xB805C2A8
#define set_SCU_DRF_BIST_FAIL_reg(data)   (*((volatile unsigned int*) SCU_DRF_BIST_FAIL_reg)=data)
#define get_SCU_DRF_BIST_FAIL_reg   (*((volatile unsigned int*) SCU_DRF_BIST_FAIL_reg))
#define SCU_DRF_BIST_FAIL_inst_adr                                                   "0x00AA"
#define SCU_DRF_BIST_FAIL_inst                                                       0x00AA
#define SCU_DRF_BIST_FAIL_scu_drf_mbist_fail_shift                                   (0)
#define SCU_DRF_BIST_FAIL_scu_drf_mbist_fail_mask                                    (0x000000FF)
#define SCU_DRF_BIST_FAIL_scu_drf_mbist_fail(data)                                   (0x000000FF&((data)<<0))
#define SCU_DRF_BIST_FAIL_scu_drf_mbist_fail_src(data)                               ((0x000000FF&(data))>>0)
#define SCU_DRF_BIST_FAIL_get_scu_drf_mbist_fail(data)                               ((0x000000FF&(data))>>0)


#define CPU_DRF_START_PAUSE                                                          0x1805C2AC
#define CPU_DRF_START_PAUSE_reg_addr                                                 "0xB805C2AC"
#define CPU_DRF_START_PAUSE_reg                                                      0xB805C2AC
#define set_CPU_DRF_START_PAUSE_reg(data)   (*((volatile unsigned int*) CPU_DRF_START_PAUSE_reg)=data)
#define get_CPU_DRF_START_PAUSE_reg   (*((volatile unsigned int*) CPU_DRF_START_PAUSE_reg))
#define CPU_DRF_START_PAUSE_inst_adr                                                 "0x00AB"
#define CPU_DRF_START_PAUSE_inst                                                     0x00AB
#define CPU_DRF_START_PAUSE_cpu1_drf_start_pause_shift                               (1)
#define CPU_DRF_START_PAUSE_cpu1_drf_start_pause_mask                                (0x00000002)
#define CPU_DRF_START_PAUSE_cpu1_drf_start_pause(data)                               (0x00000002&((data)<<1))
#define CPU_DRF_START_PAUSE_cpu1_drf_start_pause_src(data)                           ((0x00000002&(data))>>1)
#define CPU_DRF_START_PAUSE_get_cpu1_drf_start_pause(data)                           ((0x00000002&(data))>>1)
#define CPU_DRF_START_PAUSE_cpu0_drf_start_pause_shift                               (0)
#define CPU_DRF_START_PAUSE_cpu0_drf_start_pause_mask                                (0x00000001)
#define CPU_DRF_START_PAUSE_cpu0_drf_start_pause(data)                               (0x00000001&((data)<<0))
#define CPU_DRF_START_PAUSE_cpu0_drf_start_pause_src(data)                           ((0x00000001&(data))>>0)
#define CPU_DRF_START_PAUSE_get_cpu0_drf_start_pause(data)                           ((0x00000001&(data))>>0)


#define SCU_DRF_START_PAUSE                                                          0x1805C2B0
#define SCU_DRF_START_PAUSE_reg_addr                                                 "0xB805C2B0"
#define SCU_DRF_START_PAUSE_reg                                                      0xB805C2B0
#define set_SCU_DRF_START_PAUSE_reg(data)   (*((volatile unsigned int*) SCU_DRF_START_PAUSE_reg)=data)
#define get_SCU_DRF_START_PAUSE_reg   (*((volatile unsigned int*) SCU_DRF_START_PAUSE_reg))
#define SCU_DRF_START_PAUSE_inst_adr                                                 "0x00AC"
#define SCU_DRF_START_PAUSE_inst                                                     0x00AC
#define SCU_DRF_START_PAUSE_scu_drf_start_pause_shift                                (0)
#define SCU_DRF_START_PAUSE_scu_drf_start_pause_mask                                 (0x00000001)
#define SCU_DRF_START_PAUSE_scu_drf_start_pause(data)                                (0x00000001&((data)<<0))
#define SCU_DRF_START_PAUSE_scu_drf_start_pause_src(data)                            ((0x00000001&(data))>>0)
#define SCU_DRF_START_PAUSE_get_scu_drf_start_pause(data)                            ((0x00000001&(data))>>0)


#define BISR_RSTN                                                                    0x1805C500
#define BISR_RSTN_reg_addr                                                           "0xB805C500"
#define BISR_RSTN_reg                                                                0xB805C500
#define set_BISR_RSTN_reg(data)   (*((volatile unsigned int*) BISR_RSTN_reg)=data)
#define get_BISR_RSTN_reg   (*((volatile unsigned int*) BISR_RSTN_reg))
#define BISR_RSTN_inst_adr                                                           "0x0040"
#define BISR_RSTN_inst                                                               0x0040
#define BISR_RSTN_BISR_RSTN_TAG_shift                                                (1)
#define BISR_RSTN_BISR_RSTN_TAG_mask                                                 (0x00000002)
#define BISR_RSTN_BISR_RSTN_TAG(data)                                                (0x00000002&((data)<<1))
#define BISR_RSTN_BISR_RSTN_TAG_src(data)                                            ((0x00000002&(data))>>1)
#define BISR_RSTN_get_BISR_RSTN_TAG(data)                                            ((0x00000002&(data))>>1)
#define BISR_RSTN_BISR_RSTN_DATA_shift                                               (0)
#define BISR_RSTN_BISR_RSTN_DATA_mask                                                (0x00000001)
#define BISR_RSTN_BISR_RSTN_DATA(data)                                               (0x00000001&((data)<<0))
#define BISR_RSTN_BISR_RSTN_DATA_src(data)                                           ((0x00000001&(data))>>0)
#define BISR_RSTN_get_BISR_RSTN_DATA(data)                                           ((0x00000001&(data))>>0)


#define HOLD_REMAP                                                                   0x1805C504
#define HOLD_REMAP_reg_addr                                                          "0xB805C504"
#define HOLD_REMAP_reg                                                               0xB805C504
#define set_HOLD_REMAP_reg(data)   (*((volatile unsigned int*) HOLD_REMAP_reg)=data)
#define get_HOLD_REMAP_reg   (*((volatile unsigned int*) HOLD_REMAP_reg))
#define HOLD_REMAP_inst_adr                                                          "0x0041"
#define HOLD_REMAP_inst                                                              0x0041
#define HOLD_REMAP_HOLD_REMAP_TAG_shift                                              (1)
#define HOLD_REMAP_HOLD_REMAP_TAG_mask                                               (0x00000002)
#define HOLD_REMAP_HOLD_REMAP_TAG(data)                                              (0x00000002&((data)<<1))
#define HOLD_REMAP_HOLD_REMAP_TAG_src(data)                                          ((0x00000002&(data))>>1)
#define HOLD_REMAP_get_HOLD_REMAP_TAG(data)                                          ((0x00000002&(data))>>1)
#define HOLD_REMAP_HOLD_REMAP_DATA_shift                                             (0)
#define HOLD_REMAP_HOLD_REMAP_DATA_mask                                              (0x00000001)
#define HOLD_REMAP_HOLD_REMAP_DATA(data)                                             (0x00000001&((data)<<0))
#define HOLD_REMAP_HOLD_REMAP_DATA_src(data)                                         ((0x00000001&(data))>>0)
#define HOLD_REMAP_get_HOLD_REMAP_DATA(data)                                         ((0x00000001&(data))>>0)


#define SECOND_RUN_EN                                                                0x1805C508
#define SECOND_RUN_EN_reg_addr                                                       "0xB805C508"
#define SECOND_RUN_EN_reg                                                            0xB805C508
#define set_SECOND_RUN_EN_reg(data)   (*((volatile unsigned int*) SECOND_RUN_EN_reg)=data)
#define get_SECOND_RUN_EN_reg   (*((volatile unsigned int*) SECOND_RUN_EN_reg))
#define SECOND_RUN_EN_inst_adr                                                       "0x0042"
#define SECOND_RUN_EN_inst                                                           0x0042
#define SECOND_RUN_EN_SECOND_RUN_EN_TAG_shift                                        (1)
#define SECOND_RUN_EN_SECOND_RUN_EN_TAG_mask                                         (0x00000002)
#define SECOND_RUN_EN_SECOND_RUN_EN_TAG(data)                                        (0x00000002&((data)<<1))
#define SECOND_RUN_EN_SECOND_RUN_EN_TAG_src(data)                                    ((0x00000002&(data))>>1)
#define SECOND_RUN_EN_get_SECOND_RUN_EN_TAG(data)                                    ((0x00000002&(data))>>1)
#define SECOND_RUN_EN_SECOND_RUN_EN_DATA_shift                                       (0)
#define SECOND_RUN_EN_SECOND_RUN_EN_DATA_mask                                        (0x00000001)
#define SECOND_RUN_EN_SECOND_RUN_EN_DATA(data)                                       (0x00000001&((data)<<0))
#define SECOND_RUN_EN_SECOND_RUN_EN_DATA_src(data)                                   ((0x00000001&(data))>>0)
#define SECOND_RUN_EN_get_SECOND_RUN_EN_DATA(data)                                   ((0x00000001&(data))>>0)


#define DRF_BISR_MODE                                                                0x1805C510
#define DRF_BISR_MODE_reg_addr                                                       "0xB805C510"
#define DRF_BISR_MODE_reg                                                            0xB805C510
#define set_DRF_BISR_MODE_reg(data)   (*((volatile unsigned int*) DRF_BISR_MODE_reg)=data)
#define get_DRF_BISR_MODE_reg   (*((volatile unsigned int*) DRF_BISR_MODE_reg))
#define DRF_BISR_MODE_inst_adr                                                       "0x0044"
#define DRF_BISR_MODE_inst                                                           0x0044
#define DRF_BISR_MODE_DRF_BISR_MODE_TAG_shift                                        (1)
#define DRF_BISR_MODE_DRF_BISR_MODE_TAG_mask                                         (0x00000002)
#define DRF_BISR_MODE_DRF_BISR_MODE_TAG(data)                                        (0x00000002&((data)<<1))
#define DRF_BISR_MODE_DRF_BISR_MODE_TAG_src(data)                                    ((0x00000002&(data))>>1)
#define DRF_BISR_MODE_get_DRF_BISR_MODE_TAG(data)                                    ((0x00000002&(data))>>1)
#define DRF_BISR_MODE_DRF_BISR_MODE_DATA_shift                                       (0)
#define DRF_BISR_MODE_DRF_BISR_MODE_DATA_mask                                        (0x00000001)
#define DRF_BISR_MODE_DRF_BISR_MODE_DATA(data)                                       (0x00000001&((data)<<0))
#define DRF_BISR_MODE_DRF_BISR_MODE_DATA_src(data)                                   ((0x00000001&(data))>>0)
#define DRF_BISR_MODE_get_DRF_BISR_MODE_DATA(data)                                   ((0x00000001&(data))>>0)


#define DRF_BISR_TEST_RESUME                                                         0x1805C514
#define DRF_BISR_TEST_RESUME_reg_addr                                                "0xB805C514"
#define DRF_BISR_TEST_RESUME_reg                                                     0xB805C514
#define set_DRF_BISR_TEST_RESUME_reg(data)   (*((volatile unsigned int*) DRF_BISR_TEST_RESUME_reg)=data)
#define get_DRF_BISR_TEST_RESUME_reg   (*((volatile unsigned int*) DRF_BISR_TEST_RESUME_reg))
#define DRF_BISR_TEST_RESUME_inst_adr                                                "0x0045"
#define DRF_BISR_TEST_RESUME_inst                                                    0x0045
#define DRF_BISR_TEST_RESUME_DRF_BISR_TEST_RESUME_shift                              (0)
#define DRF_BISR_TEST_RESUME_DRF_BISR_TEST_RESUME_mask                               (0x00000001)
#define DRF_BISR_TEST_RESUME_DRF_BISR_TEST_RESUME(data)                              (0x00000001&((data)<<0))
#define DRF_BISR_TEST_RESUME_DRF_BISR_TEST_RESUME_src(data)                          ((0x00000001&(data))>>0)
#define DRF_BISR_TEST_RESUME_get_DRF_BISR_TEST_RESUME(data)                          ((0x00000001&(data))>>0)


#define BISR_REPAIR                                                                  0x1805C518
#define BISR_REPAIR_reg_addr                                                         "0xB805C518"
#define BISR_REPAIR_reg                                                              0xB805C518
#define set_BISR_REPAIR_reg(data)   (*((volatile unsigned int*) BISR_REPAIR_reg)=data)
#define get_BISR_REPAIR_reg   (*((volatile unsigned int*) BISR_REPAIR_reg))
#define BISR_REPAIR_inst_adr                                                         "0x0046"
#define BISR_REPAIR_inst                                                             0x0046
#define BISR_REPAIR_BISR_REPAIRED_TAG_shift                                          (1)
#define BISR_REPAIR_BISR_REPAIRED_TAG_mask                                           (0x00000002)
#define BISR_REPAIR_BISR_REPAIRED_TAG(data)                                          (0x00000002&((data)<<1))
#define BISR_REPAIR_BISR_REPAIRED_TAG_src(data)                                      ((0x00000002&(data))>>1)
#define BISR_REPAIR_get_BISR_REPAIRED_TAG(data)                                      ((0x00000002&(data))>>1)
#define BISR_REPAIR_BISR_REPAIRED_DATA_shift                                         (0)
#define BISR_REPAIR_BISR_REPAIRED_DATA_mask                                          (0x00000001)
#define BISR_REPAIR_BISR_REPAIRED_DATA(data)                                         (0x00000001&((data)<<0))
#define BISR_REPAIR_BISR_REPAIRED_DATA_src(data)                                     ((0x00000001&(data))>>0)
#define BISR_REPAIR_get_BISR_REPAIRED_DATA(data)                                     ((0x00000001&(data))>>0)


#define BISR_DONE                                                                    0x1805C51C
#define BISR_DONE_reg_addr                                                           "0xB805C51C"
#define BISR_DONE_reg                                                                0xB805C51C
#define set_BISR_DONE_reg(data)   (*((volatile unsigned int*) BISR_DONE_reg)=data)
#define get_BISR_DONE_reg   (*((volatile unsigned int*) BISR_DONE_reg))
#define BISR_DONE_inst_adr                                                           "0x0047"
#define BISR_DONE_inst                                                               0x0047
#define BISR_DONE_BISR_DONE_TAG_shift                                                (1)
#define BISR_DONE_BISR_DONE_TAG_mask                                                 (0x00000002)
#define BISR_DONE_BISR_DONE_TAG(data)                                                (0x00000002&((data)<<1))
#define BISR_DONE_BISR_DONE_TAG_src(data)                                            ((0x00000002&(data))>>1)
#define BISR_DONE_get_BISR_DONE_TAG(data)                                            ((0x00000002&(data))>>1)
#define BISR_DONE_BISR_DONE_DATA_shift                                               (0)
#define BISR_DONE_BISR_DONE_DATA_mask                                                (0x00000001)
#define BISR_DONE_BISR_DONE_DATA(data)                                               (0x00000001&((data)<<0))
#define BISR_DONE_BISR_DONE_DATA_src(data)                                           ((0x00000001&(data))>>0)
#define BISR_DONE_get_BISR_DONE_DATA(data)                                           ((0x00000001&(data))>>0)


#define DRF_BISR_DONE                                                                0x1805C520
#define DRF_BISR_DONE_reg_addr                                                       "0xB805C520"
#define DRF_BISR_DONE_reg                                                            0xB805C520
#define set_DRF_BISR_DONE_reg(data)   (*((volatile unsigned int*) DRF_BISR_DONE_reg)=data)
#define get_DRF_BISR_DONE_reg   (*((volatile unsigned int*) DRF_BISR_DONE_reg))
#define DRF_BISR_DONE_inst_adr                                                       "0x0048"
#define DRF_BISR_DONE_inst                                                           0x0048
#define DRF_BISR_DONE_DRF_BISR_DONE_TAG_shift                                        (1)
#define DRF_BISR_DONE_DRF_BISR_DONE_TAG_mask                                         (0x00000002)
#define DRF_BISR_DONE_DRF_BISR_DONE_TAG(data)                                        (0x00000002&((data)<<1))
#define DRF_BISR_DONE_DRF_BISR_DONE_TAG_src(data)                                    ((0x00000002&(data))>>1)
#define DRF_BISR_DONE_get_DRF_BISR_DONE_TAG(data)                                    ((0x00000002&(data))>>1)
#define DRF_BISR_DONE_DRF_BISR_DONE_DATA_shift                                       (0)
#define DRF_BISR_DONE_DRF_BISR_DONE_DATA_mask                                        (0x00000001)
#define DRF_BISR_DONE_DRF_BISR_DONE_DATA(data)                                       (0x00000001&((data)<<0))
#define DRF_BISR_DONE_DRF_BISR_DONE_DATA_src(data)                                   ((0x00000001&(data))>>0)
#define DRF_BISR_DONE_get_DRF_BISR_DONE_DATA(data)                                   ((0x00000001&(data))>>0)


#define DRF_START_PAUSE                                                              0x1805C524
#define DRF_START_PAUSE_reg_addr                                                     "0xB805C524"
#define DRF_START_PAUSE_reg                                                          0xB805C524
#define set_DRF_START_PAUSE_reg(data)   (*((volatile unsigned int*) DRF_START_PAUSE_reg)=data)
#define get_DRF_START_PAUSE_reg   (*((volatile unsigned int*) DRF_START_PAUSE_reg))
#define DRF_START_PAUSE_inst_adr                                                     "0x0049"
#define DRF_START_PAUSE_inst                                                         0x0049
#define DRF_START_PAUSE_DRF_BISR_START_PAUSE_TAG_shift                               (1)
#define DRF_START_PAUSE_DRF_BISR_START_PAUSE_TAG_mask                                (0x00000002)
#define DRF_START_PAUSE_DRF_BISR_START_PAUSE_TAG(data)                               (0x00000002&((data)<<1))
#define DRF_START_PAUSE_DRF_BISR_START_PAUSE_TAG_src(data)                           ((0x00000002&(data))>>1)
#define DRF_START_PAUSE_get_DRF_BISR_START_PAUSE_TAG(data)                           ((0x00000002&(data))>>1)
#define DRF_START_PAUSE_DRF_BISR_START_PAUSE_DATA_shift                              (0)
#define DRF_START_PAUSE_DRF_BISR_START_PAUSE_DATA_mask                               (0x00000001)
#define DRF_START_PAUSE_DRF_BISR_START_PAUSE_DATA(data)                              (0x00000001&((data)<<0))
#define DRF_START_PAUSE_DRF_BISR_START_PAUSE_DATA_src(data)                          ((0x00000001&(data))>>0)
#define DRF_START_PAUSE_get_DRF_BISR_START_PAUSE_DATA(data)                          ((0x00000001&(data))>>0)


#define BISR_FAIL_GROUP                                                              0x1805C528
#define BISR_FAIL_GROUP_reg_addr                                                     "0xB805C528"
#define BISR_FAIL_GROUP_reg                                                          0xB805C528
#define set_BISR_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) BISR_FAIL_GROUP_reg)=data)
#define get_BISR_FAIL_GROUP_reg   (*((volatile unsigned int*) BISR_FAIL_GROUP_reg))
#define BISR_FAIL_GROUP_inst_adr                                                     "0x004A"
#define BISR_FAIL_GROUP_inst                                                         0x004A
#define BISR_FAIL_GROUP_BISR_FAIL_TAG_shift                                          (1)
#define BISR_FAIL_GROUP_BISR_FAIL_TAG_mask                                           (0x00000002)
#define BISR_FAIL_GROUP_BISR_FAIL_TAG(data)                                          (0x00000002&((data)<<1))
#define BISR_FAIL_GROUP_BISR_FAIL_TAG_src(data)                                      ((0x00000002&(data))>>1)
#define BISR_FAIL_GROUP_get_BISR_FAIL_TAG(data)                                      ((0x00000002&(data))>>1)
#define BISR_FAIL_GROUP_BISR_FAIL_DATA_shift                                         (0)
#define BISR_FAIL_GROUP_BISR_FAIL_DATA_mask                                          (0x00000001)
#define BISR_FAIL_GROUP_BISR_FAIL_DATA(data)                                         (0x00000001&((data)<<0))
#define BISR_FAIL_GROUP_BISR_FAIL_DATA_src(data)                                     ((0x00000001&(data))>>0)
#define BISR_FAIL_GROUP_get_BISR_FAIL_DATA(data)                                     ((0x00000001&(data))>>0)


#define BISR_FAIL_DATA_SEP                                                           0x1805C52C
#define BISR_FAIL_DATA_SEP_reg_addr                                                  "0xB805C52C"
#define BISR_FAIL_DATA_SEP_reg                                                       0xB805C52C
#define set_BISR_FAIL_DATA_SEP_reg(data)   (*((volatile unsigned int*) BISR_FAIL_DATA_SEP_reg)=data)
#define get_BISR_FAIL_DATA_SEP_reg   (*((volatile unsigned int*) BISR_FAIL_DATA_SEP_reg))
#define BISR_FAIL_DATA_SEP_inst_adr                                                  "0x004B"
#define BISR_FAIL_DATA_SEP_inst                                                      0x004B
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_3_shift                                    (3)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_3_mask                                     (0x00000008)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_3(data)                                    (0x00000008&((data)<<3))
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_3_src(data)                                ((0x00000008&(data))>>3)
#define BISR_FAIL_DATA_SEP_get_BISR_FAIL_DATA_3(data)                                ((0x00000008&(data))>>3)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_2_shift                                    (2)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_2_mask                                     (0x00000004)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_2(data)                                    (0x00000004&((data)<<2))
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_2_src(data)                                ((0x00000004&(data))>>2)
#define BISR_FAIL_DATA_SEP_get_BISR_FAIL_DATA_2(data)                                ((0x00000004&(data))>>2)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_1_shift                                    (1)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_1_mask                                     (0x00000002)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_1(data)                                    (0x00000002&((data)<<1))
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_1_src(data)                                ((0x00000002&(data))>>1)
#define BISR_FAIL_DATA_SEP_get_BISR_FAIL_DATA_1(data)                                ((0x00000002&(data))>>1)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_0_shift                                    (0)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_0_mask                                     (0x00000001)
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_0(data)                                    (0x00000001&((data)<<0))
#define BISR_FAIL_DATA_SEP_BISR_FAIL_DATA_0_src(data)                                ((0x00000001&(data))>>0)
#define BISR_FAIL_DATA_SEP_get_BISR_FAIL_DATA_0(data)                                ((0x00000001&(data))>>0)


#define BISR_FAIL_TAG_SEP                                                            0x1805C560
#define BISR_FAIL_TAG_SEP_reg_addr                                                   "0xB805C560"
#define BISR_FAIL_TAG_SEP_reg                                                        0xB805C560
#define set_BISR_FAIL_TAG_SEP_reg(data)   (*((volatile unsigned int*) BISR_FAIL_TAG_SEP_reg)=data)
#define get_BISR_FAIL_TAG_SEP_reg   (*((volatile unsigned int*) BISR_FAIL_TAG_SEP_reg))
#define BISR_FAIL_TAG_SEP_inst_adr                                                   "0x0058"
#define BISR_FAIL_TAG_SEP_inst                                                       0x0058
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_15_shift                                     (15)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_15_mask                                      (0x00008000)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_15(data)                                     (0x00008000&((data)<<15))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_15_src(data)                                 ((0x00008000&(data))>>15)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_15(data)                                 ((0x00008000&(data))>>15)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_14_shift                                     (14)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_14_mask                                      (0x00004000)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_14(data)                                     (0x00004000&((data)<<14))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_14_src(data)                                 ((0x00004000&(data))>>14)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_14(data)                                 ((0x00004000&(data))>>14)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_13_shift                                     (13)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_13_mask                                      (0x00002000)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_13(data)                                     (0x00002000&((data)<<13))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_13_src(data)                                 ((0x00002000&(data))>>13)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_13(data)                                 ((0x00002000&(data))>>13)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_12_shift                                     (12)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_12_mask                                      (0x00001000)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_12(data)                                     (0x00001000&((data)<<12))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_12_src(data)                                 ((0x00001000&(data))>>12)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_12(data)                                 ((0x00001000&(data))>>12)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_11_shift                                     (11)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_11_mask                                      (0x00000800)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_11(data)                                     (0x00000800&((data)<<11))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_11_src(data)                                 ((0x00000800&(data))>>11)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_11(data)                                 ((0x00000800&(data))>>11)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_10_shift                                     (10)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_10_mask                                      (0x00000400)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_10(data)                                     (0x00000400&((data)<<10))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_10_src(data)                                 ((0x00000400&(data))>>10)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_10(data)                                 ((0x00000400&(data))>>10)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_9_shift                                      (9)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_9_mask                                       (0x00000200)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_9(data)                                      (0x00000200&((data)<<9))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_9_src(data)                                  ((0x00000200&(data))>>9)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_9(data)                                  ((0x00000200&(data))>>9)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_8_shift                                      (8)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_8_mask                                       (0x00000100)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_8(data)                                      (0x00000100&((data)<<8))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_8_src(data)                                  ((0x00000100&(data))>>8)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_8(data)                                  ((0x00000100&(data))>>8)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_7_shift                                      (7)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_7_mask                                       (0x00000080)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_7(data)                                      (0x00000080&((data)<<7))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_7_src(data)                                  ((0x00000080&(data))>>7)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_7(data)                                  ((0x00000080&(data))>>7)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_6_shift                                      (6)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_6_mask                                       (0x00000040)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_6(data)                                      (0x00000040&((data)<<6))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_6_src(data)                                  ((0x00000040&(data))>>6)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_6(data)                                  ((0x00000040&(data))>>6)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_5_shift                                      (5)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_5_mask                                       (0x00000020)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_5(data)                                      (0x00000020&((data)<<5))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_5_src(data)                                  ((0x00000020&(data))>>5)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_5(data)                                  ((0x00000020&(data))>>5)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_4_shift                                      (4)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_4_mask                                       (0x00000010)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_4(data)                                      (0x00000010&((data)<<4))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_4_src(data)                                  ((0x00000010&(data))>>4)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_4(data)                                  ((0x00000010&(data))>>4)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_3_shift                                      (3)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_3_mask                                       (0x00000008)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_3(data)                                      (0x00000008&((data)<<3))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_3_src(data)                                  ((0x00000008&(data))>>3)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_3(data)                                  ((0x00000008&(data))>>3)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_2_shift                                      (2)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_2_mask                                       (0x00000004)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_2(data)                                      (0x00000004&((data)<<2))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_2_src(data)                                  ((0x00000004&(data))>>2)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_2(data)                                  ((0x00000004&(data))>>2)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_1_shift                                      (1)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_1_mask                                       (0x00000002)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_1(data)                                      (0x00000002&((data)<<1))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_1_src(data)                                  ((0x00000002&(data))>>1)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_1(data)                                  ((0x00000002&(data))>>1)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_0_shift                                      (0)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_0_mask                                       (0x00000001)
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_0(data)                                      (0x00000001&((data)<<0))
#define BISR_FAIL_TAG_SEP_BISR_FAIL_TAG_0_src(data)                                  ((0x00000001&(data))>>0)
#define BISR_FAIL_TAG_SEP_get_BISR_FAIL_TAG_0(data)                                  ((0x00000001&(data))>>0)


#define DRF_BISR_FAIL_GROUP                                                          0x1805C564
#define DRF_BISR_FAIL_GROUP_reg_addr                                                 "0xB805C564"
#define DRF_BISR_FAIL_GROUP_reg                                                      0xB805C564
#define set_DRF_BISR_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) DRF_BISR_FAIL_GROUP_reg)=data)
#define get_DRF_BISR_FAIL_GROUP_reg   (*((volatile unsigned int*) DRF_BISR_FAIL_GROUP_reg))
#define DRF_BISR_FAIL_GROUP_inst_adr                                                 "0x0059"
#define DRF_BISR_FAIL_GROUP_inst                                                     0x0059
#define DRF_BISR_FAIL_GROUP_DRF_BISR_FAIL_TAG_shift                                  (1)
#define DRF_BISR_FAIL_GROUP_DRF_BISR_FAIL_TAG_mask                                   (0x00000002)
#define DRF_BISR_FAIL_GROUP_DRF_BISR_FAIL_TAG(data)                                  (0x00000002&((data)<<1))
#define DRF_BISR_FAIL_GROUP_DRF_BISR_FAIL_TAG_src(data)                              ((0x00000002&(data))>>1)
#define DRF_BISR_FAIL_GROUP_get_DRF_BISR_FAIL_TAG(data)                              ((0x00000002&(data))>>1)
#define DRF_BISR_FAIL_GROUP_DRF_BISR_FAIL_DATA_shift                                 (0)
#define DRF_BISR_FAIL_GROUP_DRF_BISR_FAIL_DATA_mask                                  (0x00000001)
#define DRF_BISR_FAIL_GROUP_DRF_BISR_FAIL_DATA(data)                                 (0x00000001&((data)<<0))
#define DRF_BISR_FAIL_GROUP_DRF_BISR_FAIL_DATA_src(data)                             ((0x00000001&(data))>>0)
#define DRF_BISR_FAIL_GROUP_get_DRF_BISR_FAIL_DATA(data)                             ((0x00000001&(data))>>0)


#define DRF_BISR_FAIL_DATA_SEP                                                       0x1805C568
#define DRF_BISR_FAIL_DATA_SEP_reg_addr                                              "0xB805C568"
#define DRF_BISR_FAIL_DATA_SEP_reg                                                   0xB805C568
#define set_DRF_BISR_FAIL_DATA_SEP_reg(data)   (*((volatile unsigned int*) DRF_BISR_FAIL_DATA_SEP_reg)=data)
#define get_DRF_BISR_FAIL_DATA_SEP_reg   (*((volatile unsigned int*) DRF_BISR_FAIL_DATA_SEP_reg))
#define DRF_BISR_FAIL_DATA_SEP_inst_adr                                              "0x005A"
#define DRF_BISR_FAIL_DATA_SEP_inst                                                  0x005A
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_3_shift                            (3)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_3_mask                             (0x00000008)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_3(data)                            (0x00000008&((data)<<3))
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_3_src(data)                        ((0x00000008&(data))>>3)
#define DRF_BISR_FAIL_DATA_SEP_get_DRF_BISR_FAIL_DATA_3(data)                        ((0x00000008&(data))>>3)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_2_shift                            (2)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_2_mask                             (0x00000004)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_2(data)                            (0x00000004&((data)<<2))
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_2_src(data)                        ((0x00000004&(data))>>2)
#define DRF_BISR_FAIL_DATA_SEP_get_DRF_BISR_FAIL_DATA_2(data)                        ((0x00000004&(data))>>2)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_1_shift                            (1)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_1_mask                             (0x00000002)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_1(data)                            (0x00000002&((data)<<1))
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_1_src(data)                        ((0x00000002&(data))>>1)
#define DRF_BISR_FAIL_DATA_SEP_get_DRF_BISR_FAIL_DATA_1(data)                        ((0x00000002&(data))>>1)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_0_shift                            (0)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_0_mask                             (0x00000001)
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_0(data)                            (0x00000001&((data)<<0))
#define DRF_BISR_FAIL_DATA_SEP_DRF_BISR_FAIL_DATA_0_src(data)                        ((0x00000001&(data))>>0)
#define DRF_BISR_FAIL_DATA_SEP_get_DRF_BISR_FAIL_DATA_0(data)                        ((0x00000001&(data))>>0)


#define DRF_BISR_FAIL_TAG_SEP                                                        0x1805C56C
#define DRF_BISR_FAIL_TAG_SEP_reg_addr                                               "0xB805C56C"
#define DRF_BISR_FAIL_TAG_SEP_reg                                                    0xB805C56C
#define set_DRF_BISR_FAIL_TAG_SEP_reg(data)   (*((volatile unsigned int*) DRF_BISR_FAIL_TAG_SEP_reg)=data)
#define get_DRF_BISR_FAIL_TAG_SEP_reg   (*((volatile unsigned int*) DRF_BISR_FAIL_TAG_SEP_reg))
#define DRF_BISR_FAIL_TAG_SEP_inst_adr                                               "0x005B"
#define DRF_BISR_FAIL_TAG_SEP_inst                                                   0x005B
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_15_shift                             (15)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_15_mask                              (0x00008000)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_15(data)                             (0x00008000&((data)<<15))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_15_src(data)                         ((0x00008000&(data))>>15)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_15(data)                         ((0x00008000&(data))>>15)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_14_shift                             (14)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_14_mask                              (0x00004000)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_14(data)                             (0x00004000&((data)<<14))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_14_src(data)                         ((0x00004000&(data))>>14)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_14(data)                         ((0x00004000&(data))>>14)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_13_shift                             (13)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_13_mask                              (0x00002000)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_13(data)                             (0x00002000&((data)<<13))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_13_src(data)                         ((0x00002000&(data))>>13)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_13(data)                         ((0x00002000&(data))>>13)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_12_shift                             (12)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_12_mask                              (0x00001000)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_12(data)                             (0x00001000&((data)<<12))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_12_src(data)                         ((0x00001000&(data))>>12)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_12(data)                         ((0x00001000&(data))>>12)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_11_shift                             (11)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_11_mask                              (0x00000800)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_11(data)                             (0x00000800&((data)<<11))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_11_src(data)                         ((0x00000800&(data))>>11)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_11(data)                         ((0x00000800&(data))>>11)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_10_shift                             (10)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_10_mask                              (0x00000400)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_10(data)                             (0x00000400&((data)<<10))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_10_src(data)                         ((0x00000400&(data))>>10)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_10(data)                         ((0x00000400&(data))>>10)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_9_shift                              (9)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_9_mask                               (0x00000200)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_9(data)                              (0x00000200&((data)<<9))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_9_src(data)                          ((0x00000200&(data))>>9)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_9(data)                          ((0x00000200&(data))>>9)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_8_shift                              (8)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_8_mask                               (0x00000100)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_8(data)                              (0x00000100&((data)<<8))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_8_src(data)                          ((0x00000100&(data))>>8)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_8(data)                          ((0x00000100&(data))>>8)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_7_shift                              (7)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_7_mask                               (0x00000080)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_7(data)                              (0x00000080&((data)<<7))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_7_src(data)                          ((0x00000080&(data))>>7)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_7(data)                          ((0x00000080&(data))>>7)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_6_shift                              (6)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_6_mask                               (0x00000040)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_6(data)                              (0x00000040&((data)<<6))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_6_src(data)                          ((0x00000040&(data))>>6)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_6(data)                          ((0x00000040&(data))>>6)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_5_shift                              (5)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_5_mask                               (0x00000020)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_5(data)                              (0x00000020&((data)<<5))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_5_src(data)                          ((0x00000020&(data))>>5)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_5(data)                          ((0x00000020&(data))>>5)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_4_shift                              (4)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_4_mask                               (0x00000010)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_4(data)                              (0x00000010&((data)<<4))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_4_src(data)                          ((0x00000010&(data))>>4)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_4(data)                          ((0x00000010&(data))>>4)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_3_shift                              (3)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_3_mask                               (0x00000008)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_3(data)                              (0x00000008&((data)<<3))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_3_src(data)                          ((0x00000008&(data))>>3)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_3(data)                          ((0x00000008&(data))>>3)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_2_shift                              (2)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_2_mask                               (0x00000004)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_2(data)                              (0x00000004&((data)<<2))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_2_src(data)                          ((0x00000004&(data))>>2)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_2(data)                          ((0x00000004&(data))>>2)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_1_shift                              (1)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_1_mask                               (0x00000002)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_1(data)                              (0x00000002&((data)<<1))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_1_src(data)                          ((0x00000002&(data))>>1)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_1(data)                          ((0x00000002&(data))>>1)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_0_shift                              (0)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_0_mask                               (0x00000001)
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_0(data)                              (0x00000001&((data)<<0))
#define DRF_BISR_FAIL_TAG_SEP_DRF_BISR_FAIL_TAG_0_src(data)                          ((0x00000001&(data))>>0)
#define DRF_BISR_FAIL_TAG_SEP_get_DRF_BISR_FAIL_TAG_0(data)                          ((0x00000001&(data))>>0)


#define SRAM_RME                                                                     0x1805C580
#define SRAM_RME_reg_addr                                                            "0xB805C580"
#define SRAM_RME_reg                                                                 0xB805C580
#define set_SRAM_RME_reg(data)   (*((volatile unsigned int*) SRAM_RME_reg)=data)
#define get_SRAM_RME_reg   (*((volatile unsigned int*) SRAM_RME_reg))
#define SRAM_RME_inst_adr                                                            "0x0060"
#define SRAM_RME_inst                                                                0x0060
#define SRAM_RME_scu_ram_RME_shift                                                   (8)
#define SRAM_RME_scu_ram_RME_mask                                                    (0x00000100)
#define SRAM_RME_scu_ram_RME(data)                                                   (0x00000100&((data)<<8))
#define SRAM_RME_scu_ram_RME_src(data)                                               ((0x00000100&(data))>>8)
#define SRAM_RME_get_scu_ram_RME(data)                                               ((0x00000100&(data))>>8)
#define SRAM_RME_idata_ram_RME_shift                                                 (7)
#define SRAM_RME_idata_ram_RME_mask                                                  (0x00000080)
#define SRAM_RME_idata_ram_RME(data)                                                 (0x00000080&((data)<<7))
#define SRAM_RME_idata_ram_RME_src(data)                                             ((0x00000080&(data))>>7)
#define SRAM_RME_get_idata_ram_RME(data)                                             ((0x00000080&(data))>>7)
#define SRAM_RME_itag_ram_RME_shift                                                  (6)
#define SRAM_RME_itag_ram_RME_mask                                                   (0x00000040)
#define SRAM_RME_itag_ram_RME(data)                                                  (0x00000040&((data)<<6))
#define SRAM_RME_itag_ram_RME_src(data)                                              ((0x00000040&(data))>>6)
#define SRAM_RME_get_itag_ram_RME(data)                                              ((0x00000040&(data))>>6)
#define SRAM_RME_ddata_ram_RME_shift                                                 (5)
#define SRAM_RME_ddata_ram_RME_mask                                                  (0x00000020)
#define SRAM_RME_ddata_ram_RME(data)                                                 (0x00000020&((data)<<5))
#define SRAM_RME_ddata_ram_RME_src(data)                                             ((0x00000020&(data))>>5)
#define SRAM_RME_get_ddata_ram_RME(data)                                             ((0x00000020&(data))>>5)
#define SRAM_RME_dtag_ram_RME_shift                                                  (4)
#define SRAM_RME_dtag_ram_RME_mask                                                   (0x00000010)
#define SRAM_RME_dtag_ram_RME(data)                                                  (0x00000010&((data)<<4))
#define SRAM_RME_dtag_ram_RME_src(data)                                              ((0x00000010&(data))>>4)
#define SRAM_RME_get_dtag_ram_RME(data)                                              ((0x00000010&(data))>>4)
#define SRAM_RME_douter_ram_RME_shift                                                (3)
#define SRAM_RME_douter_ram_RME_mask                                                 (0x00000008)
#define SRAM_RME_douter_ram_RME(data)                                                (0x00000008&((data)<<3))
#define SRAM_RME_douter_ram_RME_src(data)                                            ((0x00000008&(data))>>3)
#define SRAM_RME_get_douter_ram_RME(data)                                            ((0x00000008&(data))>>3)
#define SRAM_RME_btac_ram_RME_shift                                                  (2)
#define SRAM_RME_btac_ram_RME_mask                                                   (0x00000004)
#define SRAM_RME_btac_ram_RME(data)                                                  (0x00000004&((data)<<2))
#define SRAM_RME_btac_ram_RME_src(data)                                              ((0x00000004&(data))>>2)
#define SRAM_RME_get_btac_ram_RME(data)                                              ((0x00000004&(data))>>2)
#define SRAM_RME_ghb_ram_RME_shift                                                   (1)
#define SRAM_RME_ghb_ram_RME_mask                                                    (0x00000002)
#define SRAM_RME_ghb_ram_RME(data)                                                   (0x00000002&((data)<<1))
#define SRAM_RME_ghb_ram_RME_src(data)                                               ((0x00000002&(data))>>1)
#define SRAM_RME_get_ghb_ram_RME(data)                                               ((0x00000002&(data))>>1)
#define SRAM_RME_tlb_ram_RME_shift                                                   (0)
#define SRAM_RME_tlb_ram_RME_mask                                                    (0x00000001)
#define SRAM_RME_tlb_ram_RME(data)                                                   (0x00000001&((data)<<0))
#define SRAM_RME_tlb_ram_RME_src(data)                                               ((0x00000001&(data))>>0)
#define SRAM_RME_get_tlb_ram_RME(data)                                               ((0x00000001&(data))>>0)


#define SRAM_RM                                                                      0x1805C584
#define SRAM_RM_reg_addr                                                             "0xB805C584"
#define SRAM_RM_reg                                                                  0xB805C584
#define set_SRAM_RM_reg(data)   (*((volatile unsigned int*) SRAM_RM_reg)=data)
#define get_SRAM_RM_reg   (*((volatile unsigned int*) SRAM_RM_reg))
#define SRAM_RM_inst_adr                                                             "0x0061"
#define SRAM_RM_inst                                                                 0x0061
#define SRAM_RM_douter_ram_RM_shift                                                  (12)
#define SRAM_RM_douter_ram_RM_mask                                                   (0x0000F000)
#define SRAM_RM_douter_ram_RM(data)                                                  (0x0000F000&((data)<<12))
#define SRAM_RM_douter_ram_RM_src(data)                                              ((0x0000F000&(data))>>12)
#define SRAM_RM_get_douter_ram_RM(data)                                              ((0x0000F000&(data))>>12)
#define SRAM_RM_btac_ram_RM_shift                                                    (8)
#define SRAM_RM_btac_ram_RM_mask                                                     (0x00000F00)
#define SRAM_RM_btac_ram_RM(data)                                                    (0x00000F00&((data)<<8))
#define SRAM_RM_btac_ram_RM_src(data)                                                ((0x00000F00&(data))>>8)
#define SRAM_RM_get_btac_ram_RM(data)                                                ((0x00000F00&(data))>>8)
#define SRAM_RM_ghb_ram_RM_shift                                                     (4)
#define SRAM_RM_ghb_ram_RM_mask                                                      (0x000000F0)
#define SRAM_RM_ghb_ram_RM(data)                                                     (0x000000F0&((data)<<4))
#define SRAM_RM_ghb_ram_RM_src(data)                                                 ((0x000000F0&(data))>>4)
#define SRAM_RM_get_ghb_ram_RM(data)                                                 ((0x000000F0&(data))>>4)
#define SRAM_RM_tlb_ram_RM_shift                                                     (0)
#define SRAM_RM_tlb_ram_RM_mask                                                      (0x0000000F)
#define SRAM_RM_tlb_ram_RM(data)                                                     (0x0000000F&((data)<<0))
#define SRAM_RM_tlb_ram_RM_src(data)                                                 ((0x0000000F&(data))>>0)
#define SRAM_RM_get_tlb_ram_RM(data)                                                 ((0x0000000F&(data))>>0)


#define SRAM_RM                                                                      0x1805C588
#define SRAM_RM_reg_addr                                                             "0xB805C588"
#define SRAM_RM_reg                                                                  0xB805C588
#define set_SRAM_RM_reg(data)   (*((volatile unsigned int*) SRAM_RM_reg)=data)
#define get_SRAM_RM_reg   (*((volatile unsigned int*) SRAM_RM_reg))
#define SRAM_RM_inst_adr                                                             "0x0062"
#define SRAM_RM_inst                                                                 0x0062
#define SRAM_RM_scu_ram_RM_shift                                                     (16)
#define SRAM_RM_scu_ram_RM_mask                                                      (0x000F0000)
#define SRAM_RM_scu_ram_RM(data)                                                     (0x000F0000&((data)<<16))
#define SRAM_RM_scu_ram_RM_src(data)                                                 ((0x000F0000&(data))>>16)
#define SRAM_RM_get_scu_ram_RM(data)                                                 ((0x000F0000&(data))>>16)
#define SRAM_RM_idata_ram_RM_shift                                                   (12)
#define SRAM_RM_idata_ram_RM_mask                                                    (0x0000F000)
#define SRAM_RM_idata_ram_RM(data)                                                   (0x0000F000&((data)<<12))
#define SRAM_RM_idata_ram_RM_src(data)                                               ((0x0000F000&(data))>>12)
#define SRAM_RM_get_idata_ram_RM(data)                                               ((0x0000F000&(data))>>12)
#define SRAM_RM_itag_ram_RM_shift                                                    (8)
#define SRAM_RM_itag_ram_RM_mask                                                     (0x00000F00)
#define SRAM_RM_itag_ram_RM(data)                                                    (0x00000F00&((data)<<8))
#define SRAM_RM_itag_ram_RM_src(data)                                                ((0x00000F00&(data))>>8)
#define SRAM_RM_get_itag_ram_RM(data)                                                ((0x00000F00&(data))>>8)
#define SRAM_RM_ddata_ram_RM_shift                                                   (4)
#define SRAM_RM_ddata_ram_RM_mask                                                    (0x000000F0)
#define SRAM_RM_ddata_ram_RM(data)                                                   (0x000000F0&((data)<<4))
#define SRAM_RM_ddata_ram_RM_src(data)                                               ((0x000000F0&(data))>>4)
#define SRAM_RM_get_ddata_ram_RM(data)                                               ((0x000000F0&(data))>>4)
#define SRAM_RM_dtag_ram_RM_shift                                                    (0)
#define SRAM_RM_dtag_ram_RM_mask                                                     (0x0000000F)
#define SRAM_RM_dtag_ram_RM(data)                                                    (0x0000000F&((data)<<0))
#define SRAM_RM_dtag_ram_RM_src(data)                                                ((0x0000000F&(data))>>0)
#define SRAM_RM_get_dtag_ram_RM(data)                                                ((0x0000000F&(data))>>0)


#define L2_SRAM_RME                                                                  0x1805C58C
#define L2_SRAM_RME_reg_addr                                                         "0xB805C58C"
#define L2_SRAM_RME_reg                                                              0xB805C58C
#define set_L2_SRAM_RME_reg(data)   (*((volatile unsigned int*) L2_SRAM_RME_reg)=data)
#define get_L2_SRAM_RME_reg   (*((volatile unsigned int*) L2_SRAM_RME_reg))
#define L2_SRAM_RME_inst_adr                                                         "0x0063"
#define L2_SRAM_RME_inst                                                             0x0063
#define L2_SRAM_RME_l2_data_ram_RME_shift                                            (1)
#define L2_SRAM_RME_l2_data_ram_RME_mask                                             (0x00000002)
#define L2_SRAM_RME_l2_data_ram_RME(data)                                            (0x00000002&((data)<<1))
#define L2_SRAM_RME_l2_data_ram_RME_src(data)                                        ((0x00000002&(data))>>1)
#define L2_SRAM_RME_get_l2_data_ram_RME(data)                                        ((0x00000002&(data))>>1)
#define L2_SRAM_RME_l2_tag_ram_RME_shift                                             (0)
#define L2_SRAM_RME_l2_tag_ram_RME_mask                                              (0x00000001)
#define L2_SRAM_RME_l2_tag_ram_RME(data)                                             (0x00000001&((data)<<0))
#define L2_SRAM_RME_l2_tag_ram_RME_src(data)                                         ((0x00000001&(data))>>0)
#define L2_SRAM_RME_get_l2_tag_ram_RME(data)                                         ((0x00000001&(data))>>0)


#define L2_SRAM_RM                                                                   0x1805C590
#define L2_SRAM_RM_reg_addr                                                          "0xB805C590"
#define L2_SRAM_RM_reg                                                               0xB805C590
#define set_L2_SRAM_RM_reg(data)   (*((volatile unsigned int*) L2_SRAM_RM_reg)=data)
#define get_L2_SRAM_RM_reg   (*((volatile unsigned int*) L2_SRAM_RM_reg))
#define L2_SRAM_RM_inst_adr                                                          "0x0064"
#define L2_SRAM_RM_inst                                                              0x0064
#define L2_SRAM_RM_l2_data_ram_RM_shift                                              (4)
#define L2_SRAM_RM_l2_data_ram_RM_mask                                               (0x000000F0)
#define L2_SRAM_RM_l2_data_ram_RM(data)                                              (0x000000F0&((data)<<4))
#define L2_SRAM_RM_l2_data_ram_RM_src(data)                                          ((0x000000F0&(data))>>4)
#define L2_SRAM_RM_get_l2_data_ram_RM(data)                                          ((0x000000F0&(data))>>4)
#define L2_SRAM_RM_l2_tag_ram_RM_shift                                               (0)
#define L2_SRAM_RM_l2_tag_ram_RM_mask                                                (0x0000000F)
#define L2_SRAM_RM_l2_tag_ram_RM(data)                                               (0x0000000F&((data)<<0))
#define L2_SRAM_RM_l2_tag_ram_RM_src(data)                                           ((0x0000000F&(data))>>0)
#define L2_SRAM_RM_get_l2_tag_ram_RM(data)                                           ((0x0000000F&(data))>>0)


#endif
