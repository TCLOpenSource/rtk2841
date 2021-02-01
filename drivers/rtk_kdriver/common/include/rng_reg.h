/**************************************************************
// Spec Version                  : 0.1
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014/2/6 14:50:45
***************************************************************/


#ifndef _RNG_REG_H_INCLUDED_
#define _RNG_REG_H_INCLUDED_
#ifdef  _RNG_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:15;
unsigned int     lfsr_bypass_1:1;
unsigned int     dbg1_sel:4;
unsigned int     dbg0_sel:4;
unsigned int     reserved_1:2;
unsigned int     corrector_imode:1;
unsigned int     lfsr_bypass_0:1;
unsigned int     rng_cali_srst:1;
unsigned int     corrector_bypass:1;
unsigned int     clk_hf_sel:1;
unsigned int     rng_srst:1;
}CTRL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     out_ready:1;
}RETURN0;

typedef struct 
{
unsigned int     valid_bit_num:32;
}RETURN1;

typedef struct 
{
unsigned int     drop_num:32;
}RETURN2;

typedef struct 
{
unsigned int     random_out:32;
}RESULTN;

typedef struct 
{
unsigned int     reserved_0:16;
unsigned int     rosc_d:4;
unsigned int     rosc_res:2;
unsigned int     rosc_div:2;
unsigned int     rosc_gain:2;
unsigned int     rosc_fs:2;
unsigned int     reserved_1:2;
unsigned int     rosc_test:1;
unsigned int     rosc_pow:1;
}ANALOG;

typedef struct 
{
unsigned int     prd_ub:16;
unsigned int     prd_lb:16;
}CALI_CHK;

typedef struct 
{
unsigned int     shot_num:12;
unsigned int     cyc_num:3;
unsigned int     wait_num:5;
unsigned int     dummy_opt:3;
unsigned int     trig_num:5;
unsigned int     lock:1;
unsigned int     shot_mode:1;
unsigned int     pol:1;
unsigned int     hw_en:1;
}CALI_CTRL;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     hw_d:4;
unsigned int     reserved_1:2;
unsigned int     rosc_lock:1;
unsigned int     cnt_ovflw:1;
unsigned int     cnt:16;
}CALI_RETURN;

typedef struct 
{
unsigned int     prd_ub:16;
unsigned int     prd_lb:16;
}LOCK_CHK;

typedef struct 
{
unsigned int     reserved_0:12;
unsigned int     exit_num:4;
unsigned int     reserved_1:12;
unsigned int     enter_num:4;
}LOCK_CTRL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     out_ready:1;
}RETURN3;

typedef struct 
{
unsigned int     valid_bit_num:32;
}RETURN4;

typedef struct 
{
unsigned int     drop_num:32;
}RETURN5;

typedef struct 
{
unsigned int     random_out:32;
}RESULTR;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     sw_s:6;
unsigned int     cap:2;
unsigned int     div:2;
unsigned int     reserved_1:7;
unsigned int     pow:1;
}FOSC_ANA;

typedef struct 
{
unsigned int     prd_ub:16;
unsigned int     prd_lb:16;
}FOSC_CALI_CHK;

typedef struct 
{
unsigned int     shot_num:12;
unsigned int     cyc_num:3;
unsigned int     wait_num:5;
unsigned int     dummy_opt:3;
unsigned int     trig_num:5;
unsigned int     lock:1;
unsigned int     shot_mode:1;
unsigned int     pol:1;
unsigned int     hw_en:1;
}FOSC_CALI_CTRL;

typedef struct 
{
unsigned int     reserved_0:6;
unsigned int     hw_s:6;
unsigned int     reserved_1:2;
unsigned int     rosc_lock:1;
unsigned int     cnt_ovflw:1;
unsigned int     cnt:16;
}FOSC_CALI_RETURN;

typedef struct 
{
unsigned int     prd_ub:16;
unsigned int     prd_lb:16;
}FOSC_LOCK_CHK;

typedef struct 
{
unsigned int     range_sel:1;
unsigned int     reserved_0:11;
unsigned int     exit_num:4;
unsigned int     reserved_1:12;
unsigned int     enter_num:4;
}FOSC_LOCK_CTRL;

typedef struct 
{
unsigned int     exit_ub:16;
unsigned int     exit_lb:16;
}FOSC_LOCK_CHK;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     mode:1;
unsigned int     status_mask:8;
unsigned int     reserved_1:3;
unsigned int     tst_fro_select:5;
unsigned int     tst_fro_iddq:1;
unsigned int     tst_fro_ctrl_en:1;
unsigned int     tst_fro_enable:1;
unsigned int     tst_fro_delay:1;
}EIP76_CTRL;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     bufr_cnt:3;
unsigned int     reserved_1:11;
unsigned int     bufn_cnt:5;
}RETURN6;

#endif

#define CTRL                                                                         0x18001800
#define CTRL_reg_addr                                                                "0xB8001800"
#define CTRL_reg                                                                     0xB8001800
#define set_CTRL_reg(data)   (*((volatile unsigned int*) CTRL_reg)=data)
#define get_CTRL_reg   (*((volatile unsigned int*) CTRL_reg))
#define CTRL_inst_adr                                                                "0x0000"
#define CTRL_inst                                                                    0x0000
#define CTRL_lfsr_bypass_1_shift                                                     (16)
#define CTRL_lfsr_bypass_1_mask                                                      (0x00010000)
#define CTRL_lfsr_bypass_1(data)                                                     (0x00010000&((data)<<16))
#define CTRL_lfsr_bypass_1_src(data)                                                 ((0x00010000&(data))>>16)
#define CTRL_get_lfsr_bypass_1(data)                                                 ((0x00010000&(data))>>16)
#define CTRL_dbg1_sel_shift                                                          (12)
#define CTRL_dbg1_sel_mask                                                           (0x0000F000)
#define CTRL_dbg1_sel(data)                                                          (0x0000F000&((data)<<12))
#define CTRL_dbg1_sel_src(data)                                                      ((0x0000F000&(data))>>12)
#define CTRL_get_dbg1_sel(data)                                                      ((0x0000F000&(data))>>12)
#define CTRL_dbg0_sel_shift                                                          (8)
#define CTRL_dbg0_sel_mask                                                           (0x00000F00)
#define CTRL_dbg0_sel(data)                                                          (0x00000F00&((data)<<8))
#define CTRL_dbg0_sel_src(data)                                                      ((0x00000F00&(data))>>8)
#define CTRL_get_dbg0_sel(data)                                                      ((0x00000F00&(data))>>8)
#define CTRL_corrector_imode_shift                                                   (5)
#define CTRL_corrector_imode_mask                                                    (0x00000020)
#define CTRL_corrector_imode(data)                                                   (0x00000020&((data)<<5))
#define CTRL_corrector_imode_src(data)                                               ((0x00000020&(data))>>5)
#define CTRL_get_corrector_imode(data)                                               ((0x00000020&(data))>>5)
#define CTRL_lfsr_bypass_0_shift                                                     (4)
#define CTRL_lfsr_bypass_0_mask                                                      (0x00000010)
#define CTRL_lfsr_bypass_0(data)                                                     (0x00000010&((data)<<4))
#define CTRL_lfsr_bypass_0_src(data)                                                 ((0x00000010&(data))>>4)
#define CTRL_get_lfsr_bypass_0(data)                                                 ((0x00000010&(data))>>4)
#define CTRL_rng_cali_srst_shift                                                     (3)
#define CTRL_rng_cali_srst_mask                                                      (0x00000008)
#define CTRL_rng_cali_srst(data)                                                     (0x00000008&((data)<<3))
#define CTRL_rng_cali_srst_src(data)                                                 ((0x00000008&(data))>>3)
#define CTRL_get_rng_cali_srst(data)                                                 ((0x00000008&(data))>>3)
#define CTRL_corrector_bypass_shift                                                  (2)
#define CTRL_corrector_bypass_mask                                                   (0x00000004)
#define CTRL_corrector_bypass(data)                                                  (0x00000004&((data)<<2))
#define CTRL_corrector_bypass_src(data)                                              ((0x00000004&(data))>>2)
#define CTRL_get_corrector_bypass(data)                                              ((0x00000004&(data))>>2)
#define CTRL_clk_hf_sel_shift                                                        (1)
#define CTRL_clk_hf_sel_mask                                                         (0x00000002)
#define CTRL_clk_hf_sel(data)                                                        (0x00000002&((data)<<1))
#define CTRL_clk_hf_sel_src(data)                                                    ((0x00000002&(data))>>1)
#define CTRL_get_clk_hf_sel(data)                                                    ((0x00000002&(data))>>1)
#define CTRL_rng_srst_shift                                                          (0)
#define CTRL_rng_srst_mask                                                           (0x00000001)
#define CTRL_rng_srst(data)                                                          (0x00000001&((data)<<0))
#define CTRL_rng_srst_src(data)                                                      ((0x00000001&(data))>>0)
#define CTRL_get_rng_srst(data)                                                      ((0x00000001&(data))>>0)


#define RETURN0                                                                      0x18001804
#define RETURN0_reg_addr                                                             "0xB8001804"
#define RETURN0_reg                                                                  0xB8001804
#define set_RETURN0_reg(data)   (*((volatile unsigned int*) RETURN0_reg)=data)
#define get_RETURN0_reg   (*((volatile unsigned int*) RETURN0_reg))
#define RETURN0_inst_adr                                                             "0x0001"
#define RETURN0_inst                                                                 0x0001
#define RETURN0_out_ready_shift                                                      (0)
#define RETURN0_out_ready_mask                                                       (0x00000001)
#define RETURN0_out_ready(data)                                                      (0x00000001&((data)<<0))
#define RETURN0_out_ready_src(data)                                                  ((0x00000001&(data))>>0)
#define RETURN0_get_out_ready(data)                                                  ((0x00000001&(data))>>0)


#define RETURN1                                                                      0x18001808
#define RETURN1_reg_addr                                                             "0xB8001808"
#define RETURN1_reg                                                                  0xB8001808
#define set_RETURN1_reg(data)   (*((volatile unsigned int*) RETURN1_reg)=data)
#define get_RETURN1_reg   (*((volatile unsigned int*) RETURN1_reg))
#define RETURN1_inst_adr                                                             "0x0002"
#define RETURN1_inst                                                                 0x0002
#define RETURN1_valid_bit_num_shift                                                  (0)
#define RETURN1_valid_bit_num_mask                                                   (0xFFFFFFFF)
#define RETURN1_valid_bit_num(data)                                                  (0xFFFFFFFF&((data)<<0))
#define RETURN1_valid_bit_num_src(data)                                              ((0xFFFFFFFF&(data))>>0)
#define RETURN1_get_valid_bit_num(data)                                              ((0xFFFFFFFF&(data))>>0)


#define RETURN2                                                                      0x1800180C
#define RETURN2_reg_addr                                                             "0xB800180C"
#define RETURN2_reg                                                                  0xB800180C
#define set_RETURN2_reg(data)   (*((volatile unsigned int*) RETURN2_reg)=data)
#define get_RETURN2_reg   (*((volatile unsigned int*) RETURN2_reg))
#define RETURN2_inst_adr                                                             "0x0003"
#define RETURN2_inst                                                                 0x0003
#define RETURN2_drop_num_shift                                                       (0)
#define RETURN2_drop_num_mask                                                        (0xFFFFFFFF)
#define RETURN2_drop_num(data)                                                       (0xFFFFFFFF&((data)<<0))
#define RETURN2_drop_num_src(data)                                                   ((0xFFFFFFFF&(data))>>0)
#define RETURN2_get_drop_num(data)                                                   ((0xFFFFFFFF&(data))>>0)


#define RESULTN                                                                      0x18001810
#define RESULTN_reg_addr                                                             "0xB8001810"
#define RESULTN_reg                                                                  0xB8001810
#define set_RESULTN_reg(data)   (*((volatile unsigned int*) RESULTN_reg)=data)
#define get_RESULTN_reg   (*((volatile unsigned int*) RESULTN_reg))
#define RESULTN_inst_adr                                                             "0x0004"
#define RESULTN_inst                                                                 0x0004
#define RESULTN_random_out_shift                                                     (0)
#define RESULTN_random_out_mask                                                      (0xFFFFFFFF)
#define RESULTN_random_out(data)                                                     (0xFFFFFFFF&((data)<<0))
#define RESULTN_random_out_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define RESULTN_get_random_out(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define ANALOG                                                                       0x18001814
#define ANALOG_reg_addr                                                              "0xB8001814"
#define ANALOG_reg                                                                   0xB8001814
#define set_ANALOG_reg(data)   (*((volatile unsigned int*) ANALOG_reg)=data)
#define get_ANALOG_reg   (*((volatile unsigned int*) ANALOG_reg))
#define ANALOG_inst_adr                                                              "0x0005"
#define ANALOG_inst                                                                  0x0005
#define ANALOG_rosc_d_shift                                                          (12)
#define ANALOG_rosc_d_mask                                                           (0x0000F000)
#define ANALOG_rosc_d(data)                                                          (0x0000F000&((data)<<12))
#define ANALOG_rosc_d_src(data)                                                      ((0x0000F000&(data))>>12)
#define ANALOG_get_rosc_d(data)                                                      ((0x0000F000&(data))>>12)
#define ANALOG_rosc_res_shift                                                        (10)
#define ANALOG_rosc_res_mask                                                         (0x00000C00)
#define ANALOG_rosc_res(data)                                                        (0x00000C00&((data)<<10))
#define ANALOG_rosc_res_src(data)                                                    ((0x00000C00&(data))>>10)
#define ANALOG_get_rosc_res(data)                                                    ((0x00000C00&(data))>>10)
#define ANALOG_rosc_div_shift                                                        (8)
#define ANALOG_rosc_div_mask                                                         (0x00000300)
#define ANALOG_rosc_div(data)                                                        (0x00000300&((data)<<8))
#define ANALOG_rosc_div_src(data)                                                    ((0x00000300&(data))>>8)
#define ANALOG_get_rosc_div(data)                                                    ((0x00000300&(data))>>8)
#define ANALOG_rosc_gain_shift                                                       (6)
#define ANALOG_rosc_gain_mask                                                        (0x000000C0)
#define ANALOG_rosc_gain(data)                                                       (0x000000C0&((data)<<6))
#define ANALOG_rosc_gain_src(data)                                                   ((0x000000C0&(data))>>6)
#define ANALOG_get_rosc_gain(data)                                                   ((0x000000C0&(data))>>6)
#define ANALOG_rosc_fs_shift                                                         (4)
#define ANALOG_rosc_fs_mask                                                          (0x00000030)
#define ANALOG_rosc_fs(data)                                                         (0x00000030&((data)<<4))
#define ANALOG_rosc_fs_src(data)                                                     ((0x00000030&(data))>>4)
#define ANALOG_get_rosc_fs(data)                                                     ((0x00000030&(data))>>4)
#define ANALOG_rosc_test_shift                                                       (1)
#define ANALOG_rosc_test_mask                                                        (0x00000002)
#define ANALOG_rosc_test(data)                                                       (0x00000002&((data)<<1))
#define ANALOG_rosc_test_src(data)                                                   ((0x00000002&(data))>>1)
#define ANALOG_get_rosc_test(data)                                                   ((0x00000002&(data))>>1)
#define ANALOG_rosc_pow_shift                                                        (0)
#define ANALOG_rosc_pow_mask                                                         (0x00000001)
#define ANALOG_rosc_pow(data)                                                        (0x00000001&((data)<<0))
#define ANALOG_rosc_pow_src(data)                                                    ((0x00000001&(data))>>0)
#define ANALOG_get_rosc_pow(data)                                                    ((0x00000001&(data))>>0)


#define CALI_CHK                                                                     0x18001818
#define CALI_CHK_reg_addr                                                            "0xB8001818"
#define CALI_CHK_reg                                                                 0xB8001818
#define set_CALI_CHK_reg(data)   (*((volatile unsigned int*) CALI_CHK_reg)=data)
#define get_CALI_CHK_reg   (*((volatile unsigned int*) CALI_CHK_reg))
#define CALI_CHK_inst_adr                                                            "0x0006"
#define CALI_CHK_inst                                                                0x0006
#define CALI_CHK_prd_ub_shift                                                        (16)
#define CALI_CHK_prd_ub_mask                                                         (0xFFFF0000)
#define CALI_CHK_prd_ub(data)                                                        (0xFFFF0000&((data)<<16))
#define CALI_CHK_prd_ub_src(data)                                                    ((0xFFFF0000&(data))>>16)
#define CALI_CHK_get_prd_ub(data)                                                    ((0xFFFF0000&(data))>>16)
#define CALI_CHK_prd_lb_shift                                                        (0)
#define CALI_CHK_prd_lb_mask                                                         (0x0000FFFF)
#define CALI_CHK_prd_lb(data)                                                        (0x0000FFFF&((data)<<0))
#define CALI_CHK_prd_lb_src(data)                                                    ((0x0000FFFF&(data))>>0)
#define CALI_CHK_get_prd_lb(data)                                                    ((0x0000FFFF&(data))>>0)


#define CALI_CTRL                                                                    0x1800181C
#define CALI_CTRL_reg_addr                                                           "0xB800181C"
#define CALI_CTRL_reg                                                                0xB800181C
#define set_CALI_CTRL_reg(data)   (*((volatile unsigned int*) CALI_CTRL_reg)=data)
#define get_CALI_CTRL_reg   (*((volatile unsigned int*) CALI_CTRL_reg))
#define CALI_CTRL_inst_adr                                                           "0x0007"
#define CALI_CTRL_inst                                                               0x0007
#define CALI_CTRL_shot_num_shift                                                     (20)
#define CALI_CTRL_shot_num_mask                                                      (0xFFF00000)
#define CALI_CTRL_shot_num(data)                                                     (0xFFF00000&((data)<<20))
#define CALI_CTRL_shot_num_src(data)                                                 ((0xFFF00000&(data))>>20)
#define CALI_CTRL_get_shot_num(data)                                                 ((0xFFF00000&(data))>>20)
#define CALI_CTRL_cyc_num_shift                                                      (17)
#define CALI_CTRL_cyc_num_mask                                                       (0x000E0000)
#define CALI_CTRL_cyc_num(data)                                                      (0x000E0000&((data)<<17))
#define CALI_CTRL_cyc_num_src(data)                                                  ((0x000E0000&(data))>>17)
#define CALI_CTRL_get_cyc_num(data)                                                  ((0x000E0000&(data))>>17)
#define CALI_CTRL_wait_num_shift                                                     (12)
#define CALI_CTRL_wait_num_mask                                                      (0x0001F000)
#define CALI_CTRL_wait_num(data)                                                     (0x0001F000&((data)<<12))
#define CALI_CTRL_wait_num_src(data)                                                 ((0x0001F000&(data))>>12)
#define CALI_CTRL_get_wait_num(data)                                                 ((0x0001F000&(data))>>12)
#define CALI_CTRL_dummy_opt_shift                                                    (9)
#define CALI_CTRL_dummy_opt_mask                                                     (0x00000E00)
#define CALI_CTRL_dummy_opt(data)                                                    (0x00000E00&((data)<<9))
#define CALI_CTRL_dummy_opt_src(data)                                                ((0x00000E00&(data))>>9)
#define CALI_CTRL_get_dummy_opt(data)                                                ((0x00000E00&(data))>>9)
#define CALI_CTRL_trig_num_shift                                                     (4)
#define CALI_CTRL_trig_num_mask                                                      (0x000001F0)
#define CALI_CTRL_trig_num(data)                                                     (0x000001F0&((data)<<4))
#define CALI_CTRL_trig_num_src(data)                                                 ((0x000001F0&(data))>>4)
#define CALI_CTRL_get_trig_num(data)                                                 ((0x000001F0&(data))>>4)
#define CALI_CTRL_lock_shift                                                         (3)
#define CALI_CTRL_lock_mask                                                          (0x00000008)
#define CALI_CTRL_lock(data)                                                         (0x00000008&((data)<<3))
#define CALI_CTRL_lock_src(data)                                                     ((0x00000008&(data))>>3)
#define CALI_CTRL_get_lock(data)                                                     ((0x00000008&(data))>>3)
#define CALI_CTRL_shot_mode_shift                                                    (2)
#define CALI_CTRL_shot_mode_mask                                                     (0x00000004)
#define CALI_CTRL_shot_mode(data)                                                    (0x00000004&((data)<<2))
#define CALI_CTRL_shot_mode_src(data)                                                ((0x00000004&(data))>>2)
#define CALI_CTRL_get_shot_mode(data)                                                ((0x00000004&(data))>>2)
#define CALI_CTRL_pol_shift                                                          (1)
#define CALI_CTRL_pol_mask                                                           (0x00000002)
#define CALI_CTRL_pol(data)                                                          (0x00000002&((data)<<1))
#define CALI_CTRL_pol_src(data)                                                      ((0x00000002&(data))>>1)
#define CALI_CTRL_get_pol(data)                                                      ((0x00000002&(data))>>1)
#define CALI_CTRL_hw_en_shift                                                        (0)
#define CALI_CTRL_hw_en_mask                                                         (0x00000001)
#define CALI_CTRL_hw_en(data)                                                        (0x00000001&((data)<<0))
#define CALI_CTRL_hw_en_src(data)                                                    ((0x00000001&(data))>>0)
#define CALI_CTRL_get_hw_en(data)                                                    ((0x00000001&(data))>>0)


#define CALI_RETURN                                                                  0x18001820
#define CALI_RETURN_reg_addr                                                         "0xB8001820"
#define CALI_RETURN_reg                                                              0xB8001820
#define set_CALI_RETURN_reg(data)   (*((volatile unsigned int*) CALI_RETURN_reg)=data)
#define get_CALI_RETURN_reg   (*((volatile unsigned int*) CALI_RETURN_reg))
#define CALI_RETURN_inst_adr                                                         "0x0008"
#define CALI_RETURN_inst                                                             0x0008
#define CALI_RETURN_hw_d_shift                                                       (20)
#define CALI_RETURN_hw_d_mask                                                        (0x00F00000)
#define CALI_RETURN_hw_d(data)                                                       (0x00F00000&((data)<<20))
#define CALI_RETURN_hw_d_src(data)                                                   ((0x00F00000&(data))>>20)
#define CALI_RETURN_get_hw_d(data)                                                   ((0x00F00000&(data))>>20)
#define CALI_RETURN_rosc_lock_shift                                                  (17)
#define CALI_RETURN_rosc_lock_mask                                                   (0x00020000)
#define CALI_RETURN_rosc_lock(data)                                                  (0x00020000&((data)<<17))
#define CALI_RETURN_rosc_lock_src(data)                                              ((0x00020000&(data))>>17)
#define CALI_RETURN_get_rosc_lock(data)                                              ((0x00020000&(data))>>17)
#define CALI_RETURN_cnt_ovflw_shift                                                  (16)
#define CALI_RETURN_cnt_ovflw_mask                                                   (0x00010000)
#define CALI_RETURN_cnt_ovflw(data)                                                  (0x00010000&((data)<<16))
#define CALI_RETURN_cnt_ovflw_src(data)                                              ((0x00010000&(data))>>16)
#define CALI_RETURN_get_cnt_ovflw(data)                                              ((0x00010000&(data))>>16)
#define CALI_RETURN_cnt_shift                                                        (0)
#define CALI_RETURN_cnt_mask                                                         (0x0000FFFF)
#define CALI_RETURN_cnt(data)                                                        (0x0000FFFF&((data)<<0))
#define CALI_RETURN_cnt_src(data)                                                    ((0x0000FFFF&(data))>>0)
#define CALI_RETURN_get_cnt(data)                                                    ((0x0000FFFF&(data))>>0)


#define LOCK_CHK                                                                     0x18001824
#define LOCK_CHK_reg_addr                                                            "0xB8001824"
#define LOCK_CHK_reg                                                                 0xB8001824
#define set_LOCK_CHK_reg(data)   (*((volatile unsigned int*) LOCK_CHK_reg)=data)
#define get_LOCK_CHK_reg   (*((volatile unsigned int*) LOCK_CHK_reg))
#define LOCK_CHK_inst_adr                                                            "0x0009"
#define LOCK_CHK_inst                                                                0x0009
#define LOCK_CHK_prd_ub_shift                                                        (16)
#define LOCK_CHK_prd_ub_mask                                                         (0xFFFF0000)
#define LOCK_CHK_prd_ub(data)                                                        (0xFFFF0000&((data)<<16))
#define LOCK_CHK_prd_ub_src(data)                                                    ((0xFFFF0000&(data))>>16)
#define LOCK_CHK_get_prd_ub(data)                                                    ((0xFFFF0000&(data))>>16)
#define LOCK_CHK_prd_lb_shift                                                        (0)
#define LOCK_CHK_prd_lb_mask                                                         (0x0000FFFF)
#define LOCK_CHK_prd_lb(data)                                                        (0x0000FFFF&((data)<<0))
#define LOCK_CHK_prd_lb_src(data)                                                    ((0x0000FFFF&(data))>>0)
#define LOCK_CHK_get_prd_lb(data)                                                    ((0x0000FFFF&(data))>>0)


#define LOCK_CTRL                                                                    0x18001828
#define LOCK_CTRL_reg_addr                                                           "0xB8001828"
#define LOCK_CTRL_reg                                                                0xB8001828
#define set_LOCK_CTRL_reg(data)   (*((volatile unsigned int*) LOCK_CTRL_reg)=data)
#define get_LOCK_CTRL_reg   (*((volatile unsigned int*) LOCK_CTRL_reg))
#define LOCK_CTRL_inst_adr                                                           "0x000A"
#define LOCK_CTRL_inst                                                               0x000A
#define LOCK_CTRL_exit_num_shift                                                     (16)
#define LOCK_CTRL_exit_num_mask                                                      (0x000F0000)
#define LOCK_CTRL_exit_num(data)                                                     (0x000F0000&((data)<<16))
#define LOCK_CTRL_exit_num_src(data)                                                 ((0x000F0000&(data))>>16)
#define LOCK_CTRL_get_exit_num(data)                                                 ((0x000F0000&(data))>>16)
#define LOCK_CTRL_enter_num_shift                                                    (0)
#define LOCK_CTRL_enter_num_mask                                                     (0x0000000F)
#define LOCK_CTRL_enter_num(data)                                                    (0x0000000F&((data)<<0))
#define LOCK_CTRL_enter_num_src(data)                                                ((0x0000000F&(data))>>0)
#define LOCK_CTRL_get_enter_num(data)                                                ((0x0000000F&(data))>>0)


#define RETURN3                                                                      0x1800182C
#define RETURN3_reg_addr                                                             "0xB800182C"
#define RETURN3_reg                                                                  0xB800182C
#define set_RETURN3_reg(data)   (*((volatile unsigned int*) RETURN3_reg)=data)
#define get_RETURN3_reg   (*((volatile unsigned int*) RETURN3_reg))
#define RETURN3_inst_adr                                                             "0x000B"
#define RETURN3_inst                                                                 0x000B
#define RETURN3_out_ready_shift                                                      (0)
#define RETURN3_out_ready_mask                                                       (0x00000001)
#define RETURN3_out_ready(data)                                                      (0x00000001&((data)<<0))
#define RETURN3_out_ready_src(data)                                                  ((0x00000001&(data))>>0)
#define RETURN3_get_out_ready(data)                                                  ((0x00000001&(data))>>0)


#define RETURN4                                                                      0x18001830
#define RETURN4_reg_addr                                                             "0xB8001830"
#define RETURN4_reg                                                                  0xB8001830
#define set_RETURN4_reg(data)   (*((volatile unsigned int*) RETURN4_reg)=data)
#define get_RETURN4_reg   (*((volatile unsigned int*) RETURN4_reg))
#define RETURN4_inst_adr                                                             "0x000C"
#define RETURN4_inst                                                                 0x000C
#define RETURN4_valid_bit_num_shift                                                  (0)
#define RETURN4_valid_bit_num_mask                                                   (0xFFFFFFFF)
#define RETURN4_valid_bit_num(data)                                                  (0xFFFFFFFF&((data)<<0))
#define RETURN4_valid_bit_num_src(data)                                              ((0xFFFFFFFF&(data))>>0)
#define RETURN4_get_valid_bit_num(data)                                              ((0xFFFFFFFF&(data))>>0)


#define RETURN5                                                                      0x18001834
#define RETURN5_reg_addr                                                             "0xB8001834"
#define RETURN5_reg                                                                  0xB8001834
#define set_RETURN5_reg(data)   (*((volatile unsigned int*) RETURN5_reg)=data)
#define get_RETURN5_reg   (*((volatile unsigned int*) RETURN5_reg))
#define RETURN5_inst_adr                                                             "0x000D"
#define RETURN5_inst                                                                 0x000D
#define RETURN5_drop_num_shift                                                       (0)
#define RETURN5_drop_num_mask                                                        (0xFFFFFFFF)
#define RETURN5_drop_num(data)                                                       (0xFFFFFFFF&((data)<<0))
#define RETURN5_drop_num_src(data)                                                   ((0xFFFFFFFF&(data))>>0)
#define RETURN5_get_drop_num(data)                                                   ((0xFFFFFFFF&(data))>>0)


#define RESULTR                                                                      0x18001838
#define RESULTR_reg_addr                                                             "0xB8001838"
#define RESULTR_reg                                                                  0xB8001838
#define set_RESULTR_reg(data)   (*((volatile unsigned int*) RESULTR_reg)=data)
#define get_RESULTR_reg   (*((volatile unsigned int*) RESULTR_reg))
#define RESULTR_inst_adr                                                             "0x000E"
#define RESULTR_inst                                                                 0x000E
#define RESULTR_random_out_shift                                                     (0)
#define RESULTR_random_out_mask                                                      (0xFFFFFFFF)
#define RESULTR_random_out(data)                                                     (0xFFFFFFFF&((data)<<0))
#define RESULTR_random_out_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define RESULTR_get_random_out(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define FOSC_ANA                                                                     0x1800183c
#define FOSC_ANA_reg_addr                                                            "0xB800183C"
#define FOSC_ANA_reg                                                                 0xB800183C
#define set_FOSC_ANA_reg(data)   (*((volatile unsigned int*) FOSC_ANA_reg)=data)
#define get_FOSC_ANA_reg   (*((volatile unsigned int*) FOSC_ANA_reg))
#define FOSC_ANA_inst_adr                                                            "0x000F"
#define FOSC_ANA_inst                                                                0x000F
#define FOSC_ANA_sw_s_shift                                                          (12)
#define FOSC_ANA_sw_s_mask                                                           (0x0003F000)
#define FOSC_ANA_sw_s(data)                                                          (0x0003F000&((data)<<12))
#define FOSC_ANA_sw_s_src(data)                                                      ((0x0003F000&(data))>>12)
#define FOSC_ANA_get_sw_s(data)                                                      ((0x0003F000&(data))>>12)
#define FOSC_ANA_cap_shift                                                           (10)
#define FOSC_ANA_cap_mask                                                            (0x00000C00)
#define FOSC_ANA_cap(data)                                                           (0x00000C00&((data)<<10))
#define FOSC_ANA_cap_src(data)                                                       ((0x00000C00&(data))>>10)
#define FOSC_ANA_get_cap(data)                                                       ((0x00000C00&(data))>>10)
#define FOSC_ANA_div_shift                                                           (8)
#define FOSC_ANA_div_mask                                                            (0x00000300)
#define FOSC_ANA_div(data)                                                           (0x00000300&((data)<<8))
#define FOSC_ANA_div_src(data)                                                       ((0x00000300&(data))>>8)
#define FOSC_ANA_get_div(data)                                                       ((0x00000300&(data))>>8)
#define FOSC_ANA_pow_shift                                                           (0)
#define FOSC_ANA_pow_mask                                                            (0x00000001)
#define FOSC_ANA_pow(data)                                                           (0x00000001&((data)<<0))
#define FOSC_ANA_pow_src(data)                                                       ((0x00000001&(data))>>0)
#define FOSC_ANA_get_pow(data)                                                       ((0x00000001&(data))>>0)


#define FOSC_CALI_CHK                                                                0x18001840
#define FOSC_CALI_CHK_reg_addr                                                       "0xB8001840"
#define FOSC_CALI_CHK_reg                                                            0xB8001840
#define set_FOSC_CALI_CHK_reg(data)   (*((volatile unsigned int*) FOSC_CALI_CHK_reg)=data)
#define get_FOSC_CALI_CHK_reg   (*((volatile unsigned int*) FOSC_CALI_CHK_reg))
#define FOSC_CALI_CHK_inst_adr                                                       "0x0010"
#define FOSC_CALI_CHK_inst                                                           0x0010
#define FOSC_CALI_CHK_prd_ub_shift                                                   (16)
#define FOSC_CALI_CHK_prd_ub_mask                                                    (0xFFFF0000)
#define FOSC_CALI_CHK_prd_ub(data)                                                   (0xFFFF0000&((data)<<16))
#define FOSC_CALI_CHK_prd_ub_src(data)                                               ((0xFFFF0000&(data))>>16)
#define FOSC_CALI_CHK_get_prd_ub(data)                                               ((0xFFFF0000&(data))>>16)
#define FOSC_CALI_CHK_prd_lb_shift                                                   (0)
#define FOSC_CALI_CHK_prd_lb_mask                                                    (0x0000FFFF)
#define FOSC_CALI_CHK_prd_lb(data)                                                   (0x0000FFFF&((data)<<0))
#define FOSC_CALI_CHK_prd_lb_src(data)                                               ((0x0000FFFF&(data))>>0)
#define FOSC_CALI_CHK_get_prd_lb(data)                                               ((0x0000FFFF&(data))>>0)


#define FOSC_CALI_CTRL                                                               0x18001844
#define FOSC_CALI_CTRL_reg_addr                                                      "0xB8001844"
#define FOSC_CALI_CTRL_reg                                                           0xB8001844
#define set_FOSC_CALI_CTRL_reg(data)   (*((volatile unsigned int*) FOSC_CALI_CTRL_reg)=data)
#define get_FOSC_CALI_CTRL_reg   (*((volatile unsigned int*) FOSC_CALI_CTRL_reg))
#define FOSC_CALI_CTRL_inst_adr                                                      "0x0011"
#define FOSC_CALI_CTRL_inst                                                          0x0011
#define FOSC_CALI_CTRL_shot_num_shift                                                (20)
#define FOSC_CALI_CTRL_shot_num_mask                                                 (0xFFF00000)
#define FOSC_CALI_CTRL_shot_num(data)                                                (0xFFF00000&((data)<<20))
#define FOSC_CALI_CTRL_shot_num_src(data)                                            ((0xFFF00000&(data))>>20)
#define FOSC_CALI_CTRL_get_shot_num(data)                                            ((0xFFF00000&(data))>>20)
#define FOSC_CALI_CTRL_cyc_num_shift                                                 (17)
#define FOSC_CALI_CTRL_cyc_num_mask                                                  (0x000E0000)
#define FOSC_CALI_CTRL_cyc_num(data)                                                 (0x000E0000&((data)<<17))
#define FOSC_CALI_CTRL_cyc_num_src(data)                                             ((0x000E0000&(data))>>17)
#define FOSC_CALI_CTRL_get_cyc_num(data)                                             ((0x000E0000&(data))>>17)
#define FOSC_CALI_CTRL_wait_num_shift                                                (12)
#define FOSC_CALI_CTRL_wait_num_mask                                                 (0x0001F000)
#define FOSC_CALI_CTRL_wait_num(data)                                                (0x0001F000&((data)<<12))
#define FOSC_CALI_CTRL_wait_num_src(data)                                            ((0x0001F000&(data))>>12)
#define FOSC_CALI_CTRL_get_wait_num(data)                                            ((0x0001F000&(data))>>12)
#define FOSC_CALI_CTRL_dummy_opt_shift                                               (9)
#define FOSC_CALI_CTRL_dummy_opt_mask                                                (0x00000E00)
#define FOSC_CALI_CTRL_dummy_opt(data)                                               (0x00000E00&((data)<<9))
#define FOSC_CALI_CTRL_dummy_opt_src(data)                                           ((0x00000E00&(data))>>9)
#define FOSC_CALI_CTRL_get_dummy_opt(data)                                           ((0x00000E00&(data))>>9)
#define FOSC_CALI_CTRL_trig_num_shift                                                (4)
#define FOSC_CALI_CTRL_trig_num_mask                                                 (0x000001F0)
#define FOSC_CALI_CTRL_trig_num(data)                                                (0x000001F0&((data)<<4))
#define FOSC_CALI_CTRL_trig_num_src(data)                                            ((0x000001F0&(data))>>4)
#define FOSC_CALI_CTRL_get_trig_num(data)                                            ((0x000001F0&(data))>>4)
#define FOSC_CALI_CTRL_lock_shift                                                    (3)
#define FOSC_CALI_CTRL_lock_mask                                                     (0x00000008)
#define FOSC_CALI_CTRL_lock(data)                                                    (0x00000008&((data)<<3))
#define FOSC_CALI_CTRL_lock_src(data)                                                ((0x00000008&(data))>>3)
#define FOSC_CALI_CTRL_get_lock(data)                                                ((0x00000008&(data))>>3)
#define FOSC_CALI_CTRL_shot_mode_shift                                               (2)
#define FOSC_CALI_CTRL_shot_mode_mask                                                (0x00000004)
#define FOSC_CALI_CTRL_shot_mode(data)                                               (0x00000004&((data)<<2))
#define FOSC_CALI_CTRL_shot_mode_src(data)                                           ((0x00000004&(data))>>2)
#define FOSC_CALI_CTRL_get_shot_mode(data)                                           ((0x00000004&(data))>>2)
#define FOSC_CALI_CTRL_pol_shift                                                     (1)
#define FOSC_CALI_CTRL_pol_mask                                                      (0x00000002)
#define FOSC_CALI_CTRL_pol(data)                                                     (0x00000002&((data)<<1))
#define FOSC_CALI_CTRL_pol_src(data)                                                 ((0x00000002&(data))>>1)
#define FOSC_CALI_CTRL_get_pol(data)                                                 ((0x00000002&(data))>>1)
#define FOSC_CALI_CTRL_hw_en_shift                                                   (0)
#define FOSC_CALI_CTRL_hw_en_mask                                                    (0x00000001)
#define FOSC_CALI_CTRL_hw_en(data)                                                   (0x00000001&((data)<<0))
#define FOSC_CALI_CTRL_hw_en_src(data)                                               ((0x00000001&(data))>>0)
#define FOSC_CALI_CTRL_get_hw_en(data)                                               ((0x00000001&(data))>>0)


#define FOSC_CALI_RETURN                                                             0x18001848
#define FOSC_CALI_RETURN_reg_addr                                                    "0xB8001848"
#define FOSC_CALI_RETURN_reg                                                         0xB8001848
#define set_FOSC_CALI_RETURN_reg(data)   (*((volatile unsigned int*) FOSC_CALI_RETURN_reg)=data)
#define get_FOSC_CALI_RETURN_reg   (*((volatile unsigned int*) FOSC_CALI_RETURN_reg))
#define FOSC_CALI_RETURN_inst_adr                                                    "0x0012"
#define FOSC_CALI_RETURN_inst                                                        0x0012
#define FOSC_CALI_RETURN_hw_s_shift                                                  (20)
#define FOSC_CALI_RETURN_hw_s_mask                                                   (0x03F00000)
#define FOSC_CALI_RETURN_hw_s(data)                                                  (0x03F00000&((data)<<20))
#define FOSC_CALI_RETURN_hw_s_src(data)                                              ((0x03F00000&(data))>>20)
#define FOSC_CALI_RETURN_get_hw_s(data)                                              ((0x03F00000&(data))>>20)
#define FOSC_CALI_RETURN_rosc_lock_shift                                             (17)
#define FOSC_CALI_RETURN_rosc_lock_mask                                              (0x00020000)
#define FOSC_CALI_RETURN_rosc_lock(data)                                             (0x00020000&((data)<<17))
#define FOSC_CALI_RETURN_rosc_lock_src(data)                                         ((0x00020000&(data))>>17)
#define FOSC_CALI_RETURN_get_rosc_lock(data)                                         ((0x00020000&(data))>>17)
#define FOSC_CALI_RETURN_cnt_ovflw_shift                                             (16)
#define FOSC_CALI_RETURN_cnt_ovflw_mask                                              (0x00010000)
#define FOSC_CALI_RETURN_cnt_ovflw(data)                                             (0x00010000&((data)<<16))
#define FOSC_CALI_RETURN_cnt_ovflw_src(data)                                         ((0x00010000&(data))>>16)
#define FOSC_CALI_RETURN_get_cnt_ovflw(data)                                         ((0x00010000&(data))>>16)
#define FOSC_CALI_RETURN_cnt_shift                                                   (0)
#define FOSC_CALI_RETURN_cnt_mask                                                    (0x0000FFFF)
#define FOSC_CALI_RETURN_cnt(data)                                                   (0x0000FFFF&((data)<<0))
#define FOSC_CALI_RETURN_cnt_src(data)                                               ((0x0000FFFF&(data))>>0)
#define FOSC_CALI_RETURN_get_cnt(data)                                               ((0x0000FFFF&(data))>>0)


#define FOSC_LOCK_CHK                                                                0x1800184C
#define FOSC_LOCK_CHK_reg_addr                                                       "0xB800184C"
#define FOSC_LOCK_CHK_reg                                                            0xB800184C
#define set_FOSC_LOCK_CHK_reg(data)   (*((volatile unsigned int*) FOSC_LOCK_CHK_reg)=data)
#define get_FOSC_LOCK_CHK_reg   (*((volatile unsigned int*) FOSC_LOCK_CHK_reg))
#define FOSC_LOCK_CHK_inst_adr                                                       "0x0013"
#define FOSC_LOCK_CHK_inst                                                           0x0013
#define FOSC_LOCK_CHK_prd_ub_shift                                                   (16)
#define FOSC_LOCK_CHK_prd_ub_mask                                                    (0xFFFF0000)
#define FOSC_LOCK_CHK_prd_ub(data)                                                   (0xFFFF0000&((data)<<16))
#define FOSC_LOCK_CHK_prd_ub_src(data)                                               ((0xFFFF0000&(data))>>16)
#define FOSC_LOCK_CHK_get_prd_ub(data)                                               ((0xFFFF0000&(data))>>16)
#define FOSC_LOCK_CHK_prd_lb_shift                                                   (0)
#define FOSC_LOCK_CHK_prd_lb_mask                                                    (0x0000FFFF)
#define FOSC_LOCK_CHK_prd_lb(data)                                                   (0x0000FFFF&((data)<<0))
#define FOSC_LOCK_CHK_prd_lb_src(data)                                               ((0x0000FFFF&(data))>>0)
#define FOSC_LOCK_CHK_get_prd_lb(data)                                               ((0x0000FFFF&(data))>>0)


#define FOSC_LOCK_CTRL                                                               0x18001850
#define FOSC_LOCK_CTRL_reg_addr                                                      "0xB8001850"
#define FOSC_LOCK_CTRL_reg                                                           0xB8001850
#define set_FOSC_LOCK_CTRL_reg(data)   (*((volatile unsigned int*) FOSC_LOCK_CTRL_reg)=data)
#define get_FOSC_LOCK_CTRL_reg   (*((volatile unsigned int*) FOSC_LOCK_CTRL_reg))
#define FOSC_LOCK_CTRL_inst_adr                                                      "0x0014"
#define FOSC_LOCK_CTRL_inst                                                          0x0014
#define FOSC_LOCK_CTRL_range_sel_shift                                               (31)
#define FOSC_LOCK_CTRL_range_sel_mask                                                (0x80000000)
#define FOSC_LOCK_CTRL_range_sel(data)                                               (0x80000000&((data)<<31))
#define FOSC_LOCK_CTRL_range_sel_src(data)                                           ((0x80000000&(data))>>31)
#define FOSC_LOCK_CTRL_get_range_sel(data)                                           ((0x80000000&(data))>>31)
#define FOSC_LOCK_CTRL_exit_num_shift                                                (16)
#define FOSC_LOCK_CTRL_exit_num_mask                                                 (0x000F0000)
#define FOSC_LOCK_CTRL_exit_num(data)                                                (0x000F0000&((data)<<16))
#define FOSC_LOCK_CTRL_exit_num_src(data)                                            ((0x000F0000&(data))>>16)
#define FOSC_LOCK_CTRL_get_exit_num(data)                                            ((0x000F0000&(data))>>16)
#define FOSC_LOCK_CTRL_enter_num_shift                                               (0)
#define FOSC_LOCK_CTRL_enter_num_mask                                                (0x0000000F)
#define FOSC_LOCK_CTRL_enter_num(data)                                               (0x0000000F&((data)<<0))
#define FOSC_LOCK_CTRL_enter_num_src(data)                                           ((0x0000000F&(data))>>0)
#define FOSC_LOCK_CTRL_get_enter_num(data)                                           ((0x0000000F&(data))>>0)


#define FOSC_LOCK_CHK                                                                0x18001854
#define FOSC_LOCK_CHK_reg_addr                                                       "0xB8001854"
#define FOSC_LOCK_CHK_reg                                                            0xB8001854
#define set_FOSC_LOCK_CHK_reg(data)   (*((volatile unsigned int*) FOSC_LOCK_CHK_reg)=data)
#define get_FOSC_LOCK_CHK_reg   (*((volatile unsigned int*) FOSC_LOCK_CHK_reg))
#define FOSC_LOCK_CHK_inst_adr                                                       "0x0015"
#define FOSC_LOCK_CHK_inst                                                           0x0015
#define FOSC_LOCK_CHK_exit_ub_shift                                                  (16)
#define FOSC_LOCK_CHK_exit_ub_mask                                                   (0xFFFF0000)
#define FOSC_LOCK_CHK_exit_ub(data)                                                  (0xFFFF0000&((data)<<16))
#define FOSC_LOCK_CHK_exit_ub_src(data)                                              ((0xFFFF0000&(data))>>16)
#define FOSC_LOCK_CHK_get_exit_ub(data)                                              ((0xFFFF0000&(data))>>16)
#define FOSC_LOCK_CHK_exit_lb_shift                                                  (0)
#define FOSC_LOCK_CHK_exit_lb_mask                                                   (0x0000FFFF)
#define FOSC_LOCK_CHK_exit_lb(data)                                                  (0x0000FFFF&((data)<<0))
#define FOSC_LOCK_CHK_exit_lb_src(data)                                              ((0x0000FFFF&(data))>>0)
#define FOSC_LOCK_CHK_get_exit_lb(data)                                              ((0x0000FFFF&(data))>>0)


#define EIP76_CTRL                                                                   0x18001858
#define EIP76_CTRL_reg_addr                                                          "0xB8001858"
#define EIP76_CTRL_reg                                                               0xB8001858
#define set_EIP76_CTRL_reg(data)   (*((volatile unsigned int*) EIP76_CTRL_reg)=data)
#define get_EIP76_CTRL_reg   (*((volatile unsigned int*) EIP76_CTRL_reg))
#define EIP76_CTRL_inst_adr                                                          "0x0016"
#define EIP76_CTRL_inst                                                              0x0016
#define EIP76_CTRL_mode_shift                                                        (20)
#define EIP76_CTRL_mode_mask                                                         (0x00100000)
#define EIP76_CTRL_mode(data)                                                        (0x00100000&((data)<<20))
#define EIP76_CTRL_mode_src(data)                                                    ((0x00100000&(data))>>20)
#define EIP76_CTRL_get_mode(data)                                                    ((0x00100000&(data))>>20)
#define EIP76_CTRL_status_mask_shift                                                 (12)
#define EIP76_CTRL_status_mask_mask                                                  (0x000FF000)
#define EIP76_CTRL_status_mask(data)                                                 (0x000FF000&((data)<<12))
#define EIP76_CTRL_status_mask_src(data)                                             ((0x000FF000&(data))>>12)
#define EIP76_CTRL_get_status_mask(data)                                             ((0x000FF000&(data))>>12)
#define EIP76_CTRL_tst_fro_select_shift                                              (4)
#define EIP76_CTRL_tst_fro_select_mask                                               (0x000001F0)
#define EIP76_CTRL_tst_fro_select(data)                                              (0x000001F0&((data)<<4))
#define EIP76_CTRL_tst_fro_select_src(data)                                          ((0x000001F0&(data))>>4)
#define EIP76_CTRL_get_tst_fro_select(data)                                          ((0x000001F0&(data))>>4)
#define EIP76_CTRL_tst_fro_iddq_shift                                                (3)
#define EIP76_CTRL_tst_fro_iddq_mask                                                 (0x00000008)
#define EIP76_CTRL_tst_fro_iddq(data)                                                (0x00000008&((data)<<3))
#define EIP76_CTRL_tst_fro_iddq_src(data)                                            ((0x00000008&(data))>>3)
#define EIP76_CTRL_get_tst_fro_iddq(data)                                            ((0x00000008&(data))>>3)
#define EIP76_CTRL_tst_fro_ctrl_en_shift                                             (2)
#define EIP76_CTRL_tst_fro_ctrl_en_mask                                              (0x00000004)
#define EIP76_CTRL_tst_fro_ctrl_en(data)                                             (0x00000004&((data)<<2))
#define EIP76_CTRL_tst_fro_ctrl_en_src(data)                                         ((0x00000004&(data))>>2)
#define EIP76_CTRL_get_tst_fro_ctrl_en(data)                                         ((0x00000004&(data))>>2)
#define EIP76_CTRL_tst_fro_enable_shift                                              (1)
#define EIP76_CTRL_tst_fro_enable_mask                                               (0x00000002)
#define EIP76_CTRL_tst_fro_enable(data)                                              (0x00000002&((data)<<1))
#define EIP76_CTRL_tst_fro_enable_src(data)                                          ((0x00000002&(data))>>1)
#define EIP76_CTRL_get_tst_fro_enable(data)                                          ((0x00000002&(data))>>1)
#define EIP76_CTRL_tst_fro_delay_shift                                               (0)
#define EIP76_CTRL_tst_fro_delay_mask                                                (0x00000001)
#define EIP76_CTRL_tst_fro_delay(data)                                               (0x00000001&((data)<<0))
#define EIP76_CTRL_tst_fro_delay_src(data)                                           ((0x00000001&(data))>>0)
#define EIP76_CTRL_get_tst_fro_delay(data)                                           ((0x00000001&(data))>>0)


#define RETURN6                                                                      0x1800185C
#define RETURN6_reg_addr                                                             "0xB800185C"
#define RETURN6_reg                                                                  0xB800185C
#define set_RETURN6_reg(data)   (*((volatile unsigned int*) RETURN6_reg)=data)
#define get_RETURN6_reg   (*((volatile unsigned int*) RETURN6_reg))
#define RETURN6_inst_adr                                                             "0x0017"
#define RETURN6_inst                                                                 0x0017
#define RETURN6_bufr_cnt_shift                                                       (16)
#define RETURN6_bufr_cnt_mask                                                        (0x00070000)
#define RETURN6_bufr_cnt(data)                                                       (0x00070000&((data)<<16))
#define RETURN6_bufr_cnt_src(data)                                                   ((0x00070000&(data))>>16)
#define RETURN6_get_bufr_cnt(data)                                                   ((0x00070000&(data))>>16)
#define RETURN6_bufn_cnt_shift                                                       (0)
#define RETURN6_bufn_cnt_mask                                                        (0x0000001F)
#define RETURN6_bufn_cnt(data)                                                       (0x0000001F&((data)<<0))
#define RETURN6_bufn_cnt_src(data)                                                   ((0x0000001F&(data))>>0)
#define RETURN6_get_bufn_cnt(data)                                                   ((0x0000001F&(data))>>0)


#endif
