#ifndef YC_SEPARATION_VPQ_H
#define YC_SEPARATION_VPQ_H

/* KEYWORD DEFINITION */
#ifndef _ENABLE
#define _ENABLE 1
#endif
#ifndef _DISABLE
#define _DISABLE 0
#endif

/* FUNCTION PROTOTYPE ************************************************************************/
void drvif_module_vpq_YcSeparation(unsigned char ucInputSrc, unsigned char ucInputFormat, unsigned char uc3DEnable); // Main entry

/* VDPQ 1D FLOW FUNCTION */
void module_vpq_VDPQTable_1DSet(unsigned char ucInputSrc, unsigned char ucFormat);
void module_vpq_VDTOP_1DSet(unsigned char ucInputSrc, unsigned char ucFormat);
void module_vpq_1DTableWrite(unsigned char ucTableSel);

/* VDPQ 2D FLOW FUNCTION */
void module_vpq_VDPQTable_2DSet(unsigned char ucInputSrc, unsigned char ucFormat);
void module_vpq_VDTOP_2DSet(unsigned char ucInputSrc, unsigned char ucFormat);
void module_vpq_2DTableWrite(unsigned char ucTableSel);

/* VDPQ 3D FLOW FUNCTION */
void module_vpq_VDPQTable_3DSet(unsigned char ucInputSrc, unsigned char ucFormat);
void module_vpq_VDTOP_3DSet(unsigned char ucInputSrc, unsigned char ucFormat);
void module_vpq_3DTableWrite(unsigned char ucTableSel);
void module_vpq_3DDMATableWrite(unsigned char ucTableSel);

/* VDPQ_NONTABLE_FUNCTIONS */
void module_vpq_postp_alpha_weight_table_write(unsigned char *table);
void module_vpq_digital_filter_set(unsigned char ucInYcSep, unsigned char ucInputSrc, unsigned char ucInputFormat);

/* VDPQ_GENERNAL_FUNCTION */
void module_vpq_TableWrite(unsigned int *pArray);
void module_vpq_disable_video_auto(void);
void module_vpq_enable_video_auto(void);
void module_vpq_table_info_to_fw(unsigned char ucFormat, unsigned char ucTBL);
void module_vpq_format_change_bit_to_fw(void);
void module_vpq_IC_hardware_reset(void);

/* MODULE FUNCTION */
unsigned char module_vpq_Get_TableIdxByPrjID(unsigned char ItemSel);
unsigned char module_vpq_Param_FormatRemapping(unsigned char ucFormat);
unsigned char module_vpq_Param_YcSepStatusRemapping(unsigned char ucYcSepStatus);
void module_vpq_clear_f_num_3d_fail_det_bit(void);
void module_vpq_h2v_lk_en(unsigned char on_off);
void module_vpq_3D_MemCheck(void);
void module_vpq_Y_EQ_Filter(unsigned char ucInputSrc, unsigned char unInputFormat);
void module_vpq_Y_EQ_Filter_Write(unsigned int* ptr);
void module_vpq_27M_FrontDigitalFilterEnable(unsigned char ucMode);
void module_vpq_cresample_lpf_sel(unsigned char ucMode);
void module_vpq_YCbCrDelay(unsigned char bEnable, unsigned char ucInYcSep, unsigned char ucInputSrc, unsigned char ucInputFormat);
void module_vpq_DCTI_Table_write(unsigned char *table);
void module_vpq_DMA_cnt_inverse(void);

/* MODULE API */
unsigned char drvif_module_vpq_get_ProjectId(void);
unsigned char drvif_module_vpq_set_ProjectId(unsigned char Id);
unsigned char drvif_module_vpq_get_f_num_3d_fail_det_bit(void);
unsigned char drvif_module_vpq_get_2d_table_index_Factory(void);
unsigned char drvif_module_vpq_GetYcSep(void);
unsigned char drvif_module_vpq_SetYcSep(unsigned char YcSep);
unsigned char drvif_module_vpq_Get_DeXC_Threshold(void);
unsigned char drvif_module_vpq_get_dcti_table_index_Factory(void);

void drvif_module_vpq_1DSet(unsigned char ucInputSrc, unsigned char ucFormat);
void drvif_module_vpq_2DSet(unsigned char ucInputSrc, unsigned char ucFormat);
void drvif_module_vpq_3DSet(unsigned char ucInputSrc, unsigned char ucFormat);
void drvif_module_vpq_DmaAccessCtrl(unsigned char on_off);
void drvif_module_vpq_3D_mem_Initial(unsigned int mem_addr);
void drvif_module_vpq_FRAME_BUF_CHK3D_control(unsigned char chk_3d_sel,unsigned char open_3d_cnt,unsigned char close_3d_cnt);
void drvif_module_vpq_DMA_CHK3D_VCNT_control(unsigned char dma_3d_on_vcnt);
void drvif_module_vpq_set_2d_table_index_Factory(unsigned char value);
void drvif_module_vpq_DisableMemory(void);
void drvif_module_vpq_TV_DCTIeh_Enable(unsigned char on_off);
void drvif_module_vpq_set_DeXC_Enable(unsigned char on_off);
void drvif_module_vpq_set_DeXC_Threshold(unsigned char value);
void drvif_module_vpq_DCTI_Set(unsigned char ucMode);
#endif