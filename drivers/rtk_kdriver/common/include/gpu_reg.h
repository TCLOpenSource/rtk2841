/**************************************************************
// Spec Version                  : 0.07
// Parser Version                : DVR_Parser_6.3
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2010/9/13 19:0:41
***************************************************************/


#ifndef _GPU_REG_H_INCLUDED_
#define _GPU_REG_H_INCLUDED_
#ifdef  _GPU_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     srg_mode:1;
unsigned int     srg_write_disable:1;
unsigned int     srg_read_disable:1;
unsigned int     srg_burst_limit:1;
unsigned int     srg_grp_limit:1;
unsigned int     mrd_bytelane_mode:1;
unsigned int     mwr_bytelane_mode:1;
unsigned int     read_burst_mode:1;
unsigned int     dbg_enable:1;
unsigned int     dbg_ctl1:5;
unsigned int     dbg_ctl0:5;
unsigned int     sys_clk_en:1;
unsigned int     mem_clk_en:1;
unsigned int     core_clk_en:1;
unsigned int     reset_ptr:1;
}GPU_CNTL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     dctl_iwd_idle:1;
unsigned int     dctl_ird_idle:1;
unsigned int     dctl_ipif_idle:1;
unsigned int     dctl_cif_idle:1;
unsigned int     dbusctl_idle:1;
unsigned int     IDLE:1;
}GPU_STATUS;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     dctl_iwd_error:1;
unsigned int     dctl_ird_error:1;
unsigned int     dctl_ibus_error:10;
unsigned int     thalia_irq:1;
}GPU_INT_STATUS;

typedef struct 
{
unsigned int     designer_field1:16;
unsigned int     reserved_0:3;
unsigned int     dctl_iwd_error_ie:1;
unsigned int     dctl_ird_error_ie:1;
unsigned int     dctl_ibus_error_ie:10;
unsigned int     thalia_ie:1;
}GPU_INT_EN;

typedef struct 
{
unsigned int     gpu_dbug_dout:32;
}GPU_DBUGOUT;

#endif

#define GPU_CNTL                                                                     0x18059F00
#define GPU_CNTL_reg_addr                                                            "0xB8059F00"
#define GPU_CNTL_reg                                                                 0xB8059F00
#define set_GPU_CNTL_reg(data)   (*((volatile unsigned int*) GPU_CNTL_reg)=data)
#define get_GPU_CNTL_reg   (*((volatile unsigned int*) GPU_CNTL_reg))
#define GPU_CNTL_inst_adr                                                            "0x00C0"
#define GPU_CNTL_inst                                                                0x00C0
#define GPU_CNTL_srg_mode_shift                                                      (22)
#define GPU_CNTL_srg_mode_mask                                                       (0x00400000)
#define GPU_CNTL_srg_mode(data)                                                      (0x00400000&((data)<<22))
#define GPU_CNTL_srg_mode_src(data)                                                  ((0x00400000&(data))>>22)
#define GPU_CNTL_get_srg_mode(data)                                                  ((0x00400000&(data))>>22)
#define GPU_CNTL_srg_write_disable_shift                                             (21)
#define GPU_CNTL_srg_write_disable_mask                                              (0x00200000)
#define GPU_CNTL_srg_write_disable(data)                                             (0x00200000&((data)<<21))
#define GPU_CNTL_srg_write_disable_src(data)                                         ((0x00200000&(data))>>21)
#define GPU_CNTL_get_srg_write_disable(data)                                         ((0x00200000&(data))>>21)
#define GPU_CNTL_srg_read_disable_shift                                              (20)
#define GPU_CNTL_srg_read_disable_mask                                               (0x00100000)
#define GPU_CNTL_srg_read_disable(data)                                              (0x00100000&((data)<<20))
#define GPU_CNTL_srg_read_disable_src(data)                                          ((0x00100000&(data))>>20)
#define GPU_CNTL_get_srg_read_disable(data)                                          ((0x00100000&(data))>>20)
#define GPU_CNTL_srg_burst_limit_shift                                               (19)
#define GPU_CNTL_srg_burst_limit_mask                                                (0x00080000)
#define GPU_CNTL_srg_burst_limit(data)                                               (0x00080000&((data)<<19))
#define GPU_CNTL_srg_burst_limit_src(data)                                           ((0x00080000&(data))>>19)
#define GPU_CNTL_get_srg_burst_limit(data)                                           ((0x00080000&(data))>>19)
#define GPU_CNTL_srg_grp_limit_shift                                                 (18)
#define GPU_CNTL_srg_grp_limit_mask                                                  (0x00040000)
#define GPU_CNTL_srg_grp_limit(data)                                                 (0x00040000&((data)<<18))
#define GPU_CNTL_srg_grp_limit_src(data)                                             ((0x00040000&(data))>>18)
#define GPU_CNTL_get_srg_grp_limit(data)                                             ((0x00040000&(data))>>18)
#define GPU_CNTL_mrd_bytelane_mode_shift                                             (17)
#define GPU_CNTL_mrd_bytelane_mode_mask                                              (0x00020000)
#define GPU_CNTL_mrd_bytelane_mode(data)                                             (0x00020000&((data)<<17))
#define GPU_CNTL_mrd_bytelane_mode_src(data)                                         ((0x00020000&(data))>>17)
#define GPU_CNTL_get_mrd_bytelane_mode(data)                                         ((0x00020000&(data))>>17)
#define GPU_CNTL_mwr_bytelane_mode_shift                                             (16)
#define GPU_CNTL_mwr_bytelane_mode_mask                                              (0x00010000)
#define GPU_CNTL_mwr_bytelane_mode(data)                                             (0x00010000&((data)<<16))
#define GPU_CNTL_mwr_bytelane_mode_src(data)                                         ((0x00010000&(data))>>16)
#define GPU_CNTL_get_mwr_bytelane_mode(data)                                         ((0x00010000&(data))>>16)
#define GPU_CNTL_read_burst_mode_shift                                               (15)
#define GPU_CNTL_read_burst_mode_mask                                                (0x00008000)
#define GPU_CNTL_read_burst_mode(data)                                               (0x00008000&((data)<<15))
#define GPU_CNTL_read_burst_mode_src(data)                                           ((0x00008000&(data))>>15)
#define GPU_CNTL_get_read_burst_mode(data)                                           ((0x00008000&(data))>>15)
#define GPU_CNTL_dbg_enable_shift                                                    (14)
#define GPU_CNTL_dbg_enable_mask                                                     (0x00004000)
#define GPU_CNTL_dbg_enable(data)                                                    (0x00004000&((data)<<14))
#define GPU_CNTL_dbg_enable_src(data)                                                ((0x00004000&(data))>>14)
#define GPU_CNTL_get_dbg_enable(data)                                                ((0x00004000&(data))>>14)
#define GPU_CNTL_dbg_ctl1_shift                                                      (9)
#define GPU_CNTL_dbg_ctl1_mask                                                       (0x00003E00)
#define GPU_CNTL_dbg_ctl1(data)                                                      (0x00003E00&((data)<<9))
#define GPU_CNTL_dbg_ctl1_src(data)                                                  ((0x00003E00&(data))>>9)
#define GPU_CNTL_get_dbg_ctl1(data)                                                  ((0x00003E00&(data))>>9)
#define GPU_CNTL_dbg_ctl0_shift                                                      (4)
#define GPU_CNTL_dbg_ctl0_mask                                                       (0x000001F0)
#define GPU_CNTL_dbg_ctl0(data)                                                      (0x000001F0&((data)<<4))
#define GPU_CNTL_dbg_ctl0_src(data)                                                  ((0x000001F0&(data))>>4)
#define GPU_CNTL_get_dbg_ctl0(data)                                                  ((0x000001F0&(data))>>4)
#define GPU_CNTL_sys_clk_en_shift                                                    (3)
#define GPU_CNTL_sys_clk_en_mask                                                     (0x00000008)
#define GPU_CNTL_sys_clk_en(data)                                                    (0x00000008&((data)<<3))
#define GPU_CNTL_sys_clk_en_src(data)                                                ((0x00000008&(data))>>3)
#define GPU_CNTL_get_sys_clk_en(data)                                                ((0x00000008&(data))>>3)
#define GPU_CNTL_mem_clk_en_shift                                                    (2)
#define GPU_CNTL_mem_clk_en_mask                                                     (0x00000004)
#define GPU_CNTL_mem_clk_en(data)                                                    (0x00000004&((data)<<2))
#define GPU_CNTL_mem_clk_en_src(data)                                                ((0x00000004&(data))>>2)
#define GPU_CNTL_get_mem_clk_en(data)                                                ((0x00000004&(data))>>2)
#define GPU_CNTL_core_clk_en_shift                                                   (1)
#define GPU_CNTL_core_clk_en_mask                                                    (0x00000002)
#define GPU_CNTL_core_clk_en(data)                                                   (0x00000002&((data)<<1))
#define GPU_CNTL_core_clk_en_src(data)                                               ((0x00000002&(data))>>1)
#define GPU_CNTL_get_core_clk_en(data)                                               ((0x00000002&(data))>>1)
#define GPU_CNTL_reset_ptr_shift                                                     (0)
#define GPU_CNTL_reset_ptr_mask                                                      (0x00000001)
#define GPU_CNTL_reset_ptr(data)                                                     (0x00000001&((data)<<0))
#define GPU_CNTL_reset_ptr_src(data)                                                 ((0x00000001&(data))>>0)
#define GPU_CNTL_get_reset_ptr(data)                                                 ((0x00000001&(data))>>0)


#define GPU_STATUS                                                                   0x18059F04
#define GPU_STATUS_reg_addr                                                          "0xB8059F04"
#define GPU_STATUS_reg                                                               0xB8059F04
#define set_GPU_STATUS_reg(data)   (*((volatile unsigned int*) GPU_STATUS_reg)=data)
#define get_GPU_STATUS_reg   (*((volatile unsigned int*) GPU_STATUS_reg))
#define GPU_STATUS_inst_adr                                                          "0x00C1"
#define GPU_STATUS_inst                                                              0x00C1
#define GPU_STATUS_dctl_iwd_idle_shift                                               (5)
#define GPU_STATUS_dctl_iwd_idle_mask                                                (0x00000020)
#define GPU_STATUS_dctl_iwd_idle(data)                                               (0x00000020&((data)<<5))
#define GPU_STATUS_dctl_iwd_idle_src(data)                                           ((0x00000020&(data))>>5)
#define GPU_STATUS_get_dctl_iwd_idle(data)                                           ((0x00000020&(data))>>5)
#define GPU_STATUS_dctl_ird_idle_shift                                               (4)
#define GPU_STATUS_dctl_ird_idle_mask                                                (0x00000010)
#define GPU_STATUS_dctl_ird_idle(data)                                               (0x00000010&((data)<<4))
#define GPU_STATUS_dctl_ird_idle_src(data)                                           ((0x00000010&(data))>>4)
#define GPU_STATUS_get_dctl_ird_idle(data)                                           ((0x00000010&(data))>>4)
#define GPU_STATUS_dctl_ipif_idle_shift                                              (3)
#define GPU_STATUS_dctl_ipif_idle_mask                                               (0x00000008)
#define GPU_STATUS_dctl_ipif_idle(data)                                              (0x00000008&((data)<<3))
#define GPU_STATUS_dctl_ipif_idle_src(data)                                          ((0x00000008&(data))>>3)
#define GPU_STATUS_get_dctl_ipif_idle(data)                                          ((0x00000008&(data))>>3)
#define GPU_STATUS_dctl_cif_idle_shift                                               (2)
#define GPU_STATUS_dctl_cif_idle_mask                                                (0x00000004)
#define GPU_STATUS_dctl_cif_idle(data)                                               (0x00000004&((data)<<2))
#define GPU_STATUS_dctl_cif_idle_src(data)                                           ((0x00000004&(data))>>2)
#define GPU_STATUS_get_dctl_cif_idle(data)                                           ((0x00000004&(data))>>2)
#define GPU_STATUS_dbusctl_idle_shift                                                (1)
#define GPU_STATUS_dbusctl_idle_mask                                                 (0x00000002)
#define GPU_STATUS_dbusctl_idle(data)                                                (0x00000002&((data)<<1))
#define GPU_STATUS_dbusctl_idle_src(data)                                            ((0x00000002&(data))>>1)
#define GPU_STATUS_get_dbusctl_idle(data)                                            ((0x00000002&(data))>>1)
#define GPU_STATUS_IDLE_shift                                                        (0)
#define GPU_STATUS_IDLE_mask                                                         (0x00000001)
#define GPU_STATUS_IDLE(data)                                                        (0x00000001&((data)<<0))
#define GPU_STATUS_IDLE_src(data)                                                    ((0x00000001&(data))>>0)
#define GPU_STATUS_get_IDLE(data)                                                    ((0x00000001&(data))>>0)


#define GPU_INT_STATUS                                                               0x18059F08
#define GPU_INT_STATUS_reg_addr                                                      "0xB8059F08"
#define GPU_INT_STATUS_reg                                                           0xB8059F08
#define set_GPU_INT_STATUS_reg(data)   (*((volatile unsigned int*) GPU_INT_STATUS_reg)=data)
#define get_GPU_INT_STATUS_reg   (*((volatile unsigned int*) GPU_INT_STATUS_reg))
#define GPU_INT_STATUS_inst_adr                                                      "0x00C2"
#define GPU_INT_STATUS_inst                                                          0x00C2
#define GPU_INT_STATUS_dctl_iwd_error_shift                                          (12)
#define GPU_INT_STATUS_dctl_iwd_error_mask                                           (0x00001000)
#define GPU_INT_STATUS_dctl_iwd_error(data)                                          (0x00001000&((data)<<12))
#define GPU_INT_STATUS_dctl_iwd_error_src(data)                                      ((0x00001000&(data))>>12)
#define GPU_INT_STATUS_get_dctl_iwd_error(data)                                      ((0x00001000&(data))>>12)
#define GPU_INT_STATUS_dctl_ird_error_shift                                          (11)
#define GPU_INT_STATUS_dctl_ird_error_mask                                           (0x00000800)
#define GPU_INT_STATUS_dctl_ird_error(data)                                          (0x00000800&((data)<<11))
#define GPU_INT_STATUS_dctl_ird_error_src(data)                                      ((0x00000800&(data))>>11)
#define GPU_INT_STATUS_get_dctl_ird_error(data)                                      ((0x00000800&(data))>>11)
#define GPU_INT_STATUS_dctl_ibus_error_shift                                         (1)
#define GPU_INT_STATUS_dctl_ibus_error_mask                                          (0x000007FE)
#define GPU_INT_STATUS_dctl_ibus_error(data)                                         (0x000007FE&((data)<<1))
#define GPU_INT_STATUS_dctl_ibus_error_src(data)                                     ((0x000007FE&(data))>>1)
#define GPU_INT_STATUS_get_dctl_ibus_error(data)                                     ((0x000007FE&(data))>>1)
#define GPU_INT_STATUS_thalia_irq_shift                                              (0)
#define GPU_INT_STATUS_thalia_irq_mask                                               (0x00000001)
#define GPU_INT_STATUS_thalia_irq(data)                                              (0x00000001&((data)<<0))
#define GPU_INT_STATUS_thalia_irq_src(data)                                          ((0x00000001&(data))>>0)
#define GPU_INT_STATUS_get_thalia_irq(data)                                          ((0x00000001&(data))>>0)


#define GPU_INT_EN                                                                   0x18059F0C
#define GPU_INT_EN_reg_addr                                                          "0xB8059F0C"
#define GPU_INT_EN_reg                                                               0xB8059F0C
#define set_GPU_INT_EN_reg(data)   (*((volatile unsigned int*) GPU_INT_EN_reg)=data)
#define get_GPU_INT_EN_reg   (*((volatile unsigned int*) GPU_INT_EN_reg))
#define GPU_INT_EN_inst_adr                                                          "0x00C3"
#define GPU_INT_EN_inst                                                              0x00C3
#define GPU_INT_EN_designer_field1_shift                                             (16)
#define GPU_INT_EN_designer_field1_mask                                              (0xFFFF0000)
#define GPU_INT_EN_designer_field1(data)                                             (0xFFFF0000&((data)<<16))
#define GPU_INT_EN_designer_field1_src(data)                                         ((0xFFFF0000&(data))>>16)
#define GPU_INT_EN_get_designer_field1(data)                                         ((0xFFFF0000&(data))>>16)
#define GPU_INT_EN_dctl_iwd_error_ie_shift                                           (12)
#define GPU_INT_EN_dctl_iwd_error_ie_mask                                            (0x00001000)
#define GPU_INT_EN_dctl_iwd_error_ie(data)                                           (0x00001000&((data)<<12))
#define GPU_INT_EN_dctl_iwd_error_ie_src(data)                                       ((0x00001000&(data))>>12)
#define GPU_INT_EN_get_dctl_iwd_error_ie(data)                                       ((0x00001000&(data))>>12)
#define GPU_INT_EN_dctl_ird_error_ie_shift                                           (11)
#define GPU_INT_EN_dctl_ird_error_ie_mask                                            (0x00000800)
#define GPU_INT_EN_dctl_ird_error_ie(data)                                           (0x00000800&((data)<<11))
#define GPU_INT_EN_dctl_ird_error_ie_src(data)                                       ((0x00000800&(data))>>11)
#define GPU_INT_EN_get_dctl_ird_error_ie(data)                                       ((0x00000800&(data))>>11)
#define GPU_INT_EN_dctl_ibus_error_ie_shift                                          (1)
#define GPU_INT_EN_dctl_ibus_error_ie_mask                                           (0x000007FE)
#define GPU_INT_EN_dctl_ibus_error_ie(data)                                          (0x000007FE&((data)<<1))
#define GPU_INT_EN_dctl_ibus_error_ie_src(data)                                      ((0x000007FE&(data))>>1)
#define GPU_INT_EN_get_dctl_ibus_error_ie(data)                                      ((0x000007FE&(data))>>1)
#define GPU_INT_EN_thalia_ie_shift                                                   (0)
#define GPU_INT_EN_thalia_ie_mask                                                    (0x00000001)
#define GPU_INT_EN_thalia_ie(data)                                                   (0x00000001&((data)<<0))
#define GPU_INT_EN_thalia_ie_src(data)                                               ((0x00000001&(data))>>0)
#define GPU_INT_EN_get_thalia_ie(data)                                               ((0x00000001&(data))>>0)


#define GPU_DBUGOUT                                                                  0x18059F10
#define GPU_DBUGOUT_reg_addr                                                         "0xB8059F10"
#define GPU_DBUGOUT_reg                                                              0xB8059F10
#define set_GPU_DBUGOUT_reg(data)   (*((volatile unsigned int*) GPU_DBUGOUT_reg)=data)
#define get_GPU_DBUGOUT_reg   (*((volatile unsigned int*) GPU_DBUGOUT_reg))
#define GPU_DBUGOUT_inst_adr                                                         "0x00C4"
#define GPU_DBUGOUT_inst                                                             0x00C4
#define GPU_DBUGOUT_gpu_dbug_dout_shift                                              (0)
#define GPU_DBUGOUT_gpu_dbug_dout_mask                                               (0xFFFFFFFF)
#define GPU_DBUGOUT_gpu_dbug_dout(data)                                              (0xFFFFFFFF&((data)<<0))
#define GPU_DBUGOUT_gpu_dbug_dout_src(data)                                          ((0xFFFFFFFF&(data))>>0)
#define GPU_DBUGOUT_get_gpu_dbug_dout(data)                                          ((0xFFFFFFFF&(data))>>0)


#endif
