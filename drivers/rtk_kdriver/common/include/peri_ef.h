// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:781                    Version flow no.:1.1.21
#ifndef _DEFAULT_REG_H_INCLUDED_
#define _DEFAULT_REG_H_INCLUDED_

//#define  _DEFAULT_USE_STRUCT
#ifdef _DEFAULT_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    rvd_a:3;
    unsigned int    auto_read:1;
    unsigned int    reserved_1:1;
    unsigned int    selvpp:3;
    unsigned int    reserved_2:1;
    unsigned int    op:3;
    unsigned int    key_protect_bit:1;
    unsigned int    reserved_3:1;
    unsigned int    read:1;
    unsigned int    enb:1;
    unsigned int    reserved_4:1;
    unsigned int    b:3;
    unsigned int    reserved_5:3;
    unsigned int    a:5;
}EF_ctrl0;

typedef struct
{
    unsigned int    reserved_0:30;
    unsigned int    mode:1;
    unsigned int    program:1;
}EF_ctrl1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    auto_read_done:1;
}EF_ctrl_st;

typedef struct
{
    unsigned int    dout:32;
}EF0;

typedef struct
{
    unsigned int    dout:32;
}EF1;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    crc_en:1;
}EF_crc_ctrl;

typedef struct
{
    unsigned int    crc_ini:16;
    unsigned int    crc_out:16;
}EF_crc;
#endif


#define EF_CTRL0                                                      0x18012200
#define EF_CTRL0_reg_addr                                             "0xb8012200"
#define EF_CTRL0_reg                                                  0xb8012200
#define EF_CTRL0_inst_addr                                            "0x0080"
#define EF_CTRL0_inst                                                 0x0080
#define EF_CTRL0_rvd_a_shift                                          (25)
#define EF_CTRL0_auto_read_shift                                      (24)
#define EF_CTRL0_selvpp_shift                                         (20)
#define EF_CTRL0_op_shift                                             (16)
#define EF_CTRL0_key_protect_bit_shift                                (15)
#define EF_CTRL0_read_shift                                           (13)
#define EF_CTRL0_enb_shift                                            (12)
#define EF_CTRL0_b_shift                                              (8)
#define EF_CTRL0_a_shift                                              (0)
#define EF_CTRL0_rvd_a_mask                                           (0x0E000000)
#define EF_CTRL0_auto_read_mask                                       (0x01000000)
#define EF_CTRL0_selvpp_mask                                          (0x00700000)
#define EF_CTRL0_op_mask                                              (0x00070000)
#define EF_CTRL0_key_protect_bit_mask                                 (0x00008000)
#define EF_CTRL0_read_mask                                            (0x00002000)
#define EF_CTRL0_enb_mask                                             (0x00001000)
#define EF_CTRL0_b_mask                                               (0x00000700)
#define EF_CTRL0_a_mask                                               (0x0000001F)
#define EF_CTRL0_rvd_a(data)                                          (0x0E000000&((data)<<25))
#define EF_CTRL0_auto_read(data)                                      (0x01000000&((data)<<24))
#define EF_CTRL0_selvpp(data)                                         (0x00700000&((data)<<20))
#define EF_CTRL0_op(data)                                             (0x00070000&((data)<<16))
#define EF_CTRL0_key_protect_bit(data)                                (0x00008000&((data)<<15))
#define EF_CTRL0_read(data)                                           (0x00002000&((data)<<13))
#define EF_CTRL0_enb(data)                                            (0x00001000&((data)<<12))
#define EF_CTRL0_b(data)                                              (0x00000700&((data)<<8))
#define EF_CTRL0_a(data)                                              (0x0000001F&(data))
#define EF_CTRL0_get_rvd_a(data)                                      ((0x0E000000&(data))>>25)
#define EF_CTRL0_get_auto_read(data)                                  ((0x01000000&(data))>>24)
#define EF_CTRL0_get_selvpp(data)                                     ((0x00700000&(data))>>20)
#define EF_CTRL0_get_op(data)                                         ((0x00070000&(data))>>16)
#define EF_CTRL0_get_key_protect_bit(data)                            ((0x00008000&(data))>>15)
#define EF_CTRL0_get_read(data)                                       ((0x00002000&(data))>>13)
#define EF_CTRL0_get_enb(data)                                        ((0x00001000&(data))>>12)
#define EF_CTRL0_get_b(data)                                          ((0x00000700&(data))>>8)
#define EF_CTRL0_get_a(data)                                          (0x0000001F&(data))


#define EF_CTRL1                                                      0x18012204
#define EF_CTRL1_reg_addr                                             "0xb8012204"
#define EF_CTRL1_reg                                                  0xb8012204
#define EF_CTRL1_inst_addr                                            "0x0081"
#define EF_CTRL1_inst                                                 0x0081
#define EF_CTRL1_mode_shift                                           (1)
#define EF_CTRL1_program_shift                                        (0)
#define EF_CTRL1_mode_mask                                            (0x00000002)
#define EF_CTRL1_program_mask                                         (0x00000001)
#define EF_CTRL1_mode(data)                                           (0x00000002&((data)<<1))
#define EF_CTRL1_program(data)                                        (0x00000001&(data))
#define EF_CTRL1_get_mode(data)                                       ((0x00000002&(data))>>1)
#define EF_CTRL1_get_program(data)                                    (0x00000001&(data))


#define EF_CTRL_ST                                                    0x18012208
#define EF_CTRL_ST_reg_addr                                           "0xb8012208"
#define EF_CTRL_ST_reg                                                0xb8012208
#define EF_CTRL_ST_inst_addr                                          "0x0082"
#define EF_CTRL_ST_inst                                               0x0082
#define EF_CTRL_ST_auto_read_done_shift                               (0)
#define EF_CTRL_ST_auto_read_done_mask                                (0x00000001)
#define EF_CTRL_ST_auto_read_done(data)                               (0x00000001&(data))
#define EF_CTRL_ST_get_auto_read_done(data)                           (0x00000001&(data))


#define EF0                                                           0x1801220c
#define EF0_reg_addr                                                  "0xb801220c"
#define EF0_reg                                                       0xb801220c
#define EF0_inst_addr                                                 "0x0083"
#define EF0_inst                                                      0x0083
#define EF0_dout_shift                                                (0)
#define EF0_dout_mask                                                 (0xFFFFFFFF)
#define EF0_dout(data)                                                (0xFFFFFFFF&(data))
#define EF0_get_dout(data)                                            (0xFFFFFFFF&(data))


#define EF1                                                           0x18012210
#define EF1_reg_addr                                                  "0xb8012210"
#define EF1_reg                                                       0xb8012210
#define EF1_inst_addr                                                 "0x0084"
#define EF1_inst                                                      0x0084
#define EF1_dout_shift                                                (0)
#define EF1_dout_mask                                                 (0xFFFFFFFF)
#define EF1_dout(data)                                                (0xFFFFFFFF&(data))
#define EF1_get_dout(data)                                            (0xFFFFFFFF&(data))


#define EF_CRC_CTRL                                                     0x18012214
#define EF_CRC_CTRL_reg_addr                                            "0xb8012214"
#define EF_CRC_CTRL_reg                                                 0xb8012214
#define EF_CRC_CTRL_inst_addr                                           "0x0085"
#define EF_CRC_CTRL_inst                                                0x0085
#define EF_CRC_CTRL_crc_en_shift                                        (0)
#define EF_CRC_CTRL_crc_en_mask                                         (0x00000001)
#define EF_CRC_CTRL_crc_en(data)                                        (0x00000001&(data))
#define EF_CRC_CTRL_get_crc_en(data)                                    (0x00000001&(data))


#define EF_CRC                                                        0x18012218
#define EF_CRC_reg_addr                                               "0xb8012218"
#define EF_CRC_reg                                                    0xb8012218
#define EF_CRC_inst_addr                                              "0x0086"
#define EF_CRC_inst                                                   0x0086
#define EF_CRC_crc_ini_shift                                          (16)
#define EF_CRC_crc_out_shift                                          (0)
#define EF_CRC_crc_ini_mask                                           (0xFFFF0000)
#define EF_CRC_crc_out_mask                                           (0x0000FFFF)
#define EF_CRC_crc_ini(data)                                          (0xFFFF0000&((data)<<16))
#define EF_CRC_crc_out(data)                                          (0x0000FFFF&(data))
#define EF_CRC_get_crc_ini(data)                                      ((0xFFFF0000&(data))>>16)
#define EF_CRC_get_crc_out(data)                                      (0x0000FFFF&(data))
#endif
