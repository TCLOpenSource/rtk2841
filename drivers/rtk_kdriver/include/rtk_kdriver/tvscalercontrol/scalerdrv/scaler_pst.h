#ifndef _SCALER_PST_H_
#define _SCALER_PST_H_

#ifdef __cplusplus
extern "C" {
#endif

#define PST_CMD_NUMBER 3 //hw setting + 1
typedef struct _PST_STEP_SIZE {
    unsigned int	i_m_blk_size;
    unsigned int	i_s_blk_size;
    unsigned int	dispm_blk_size;
    unsigned int	disps_blk_size;
    unsigned int	gdma_blk_size;
} PST_STEP_SIZE;

typedef struct _PST_CMD_BUF {
    unsigned int	i_m_cur_cmd;
    unsigned int	i_s_cur_cmd;
    unsigned int	dispm_cur_cmd;
    unsigned int	disps_cur_cmd;
    unsigned int	gdma_cur_cmd;
} PST_CMD_BUF;

typedef enum{
	_DEFAULT_OFF = 0,
	_MAIN_MD,
	_MAIN_VO_IMD,
	_SUB_MD,
	_SUB_VO_IMD,
	_PST_MODE_MAX,
}_PST_MODE_T;
typedef struct _PST_DISPM_SCPU_VIR_START_ADDR {
	unsigned int    s0_mdisp_st_vir_addr; //0xb8005000 - 0xb8005288
	unsigned int	s0_uzu_st_vir_addr; //0xb806b900 -  0xb806b9fc
	unsigned int	s0_dtg_st_vir_addr; //0xb806b900 -  0xb806b9fc
	unsigned int	pst_enable_vir_addr;//pst enable flag
	unsigned int	pst_dispm_write_cmd_vir_addr;
	unsigned int	pst_dispm_read_cmd_vir_addr;
}PST_DISPM_SCPU_VIR_START_ADDR;

unsigned char Scaler_main_md_pst_get_enable(void);

void Scaler_main_md_pst_set_enable(unsigned char enable);
void drvif_scaler_pst_initial(_PST_MODE_T mode);
void drvif_scaler_pst_uninitial(_PST_MODE_T mode);
void drvif_scaler_pst_dma_setting(unsigned int cmd_num, unsigned int blk_size,_PST_MODE_T mode);
void drvif_scaler_pst_top_ctrl(bool enable, _PST_MODE_T mode);
void drvif_scaler_pst_set_mode(_PST_MODE_T  mode);
_PST_MODE_T drvif_scaler_pst_get_mode(void);
unsigned int Scaler_PST_IP_register_get_cur_write_addr(unsigned int addr,unsigned char display);
unsigned char	Scaler_pst_setbuffer(_PST_MODE_T  mode);
void Scaler_pst_set_write_point(_PST_MODE_T  mode);
unsigned char Scaler_pst_get_write_point(_PST_MODE_T  mode);
unsigned char Scaler_pst_get_read_point(_PST_MODE_T mode);
void Scaler_pst_buffer_copy(_PST_MODE_T mode);
void Scaler_pst_main_md_set_write_cmd_num(void);
void Scaler_pst_main_md_write_default_cmd_num(void);
void Scaler_pst_main_md_set_read_cmd_num(unsigned char enable);
#ifdef __cplusplus
}
#endif

#endif // #ifndef _SCALER_H_
/*======================== End of File =======================================*/
/**
*
* @}
*/
