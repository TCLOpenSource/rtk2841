/**************************************************************
// Spec Version                  : 1.15
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Register_Name
// Naming Rule                   : Register_Name
// Parse Option                  : Only Parse _op2
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014/2/6 17:9:15
***************************************************************/


#ifndef _CP_REG_H_INCLUDED_
#define _CP_REG_H_INCLUDED_
#ifdef  _CP_USE_STRUCT
typedef struct 
{
unsigned int     data:32;
}CP_REG_KEY;

typedef struct 
{
unsigned int     data:32;
}CP_REG_DATAIN;

typedef struct 
{
unsigned int     data:32;
}CP_REG_DATAOUT;

typedef struct 
{
unsigned int     data:32;
}CP_REG_IV;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     write_enable5:1;
unsigned int     mode:4;
unsigned int     reserved_1:1;
unsigned int     write_enable4:1;
unsigned int     endian_swap:1;
unsigned int     write_enable3:1;
unsigned int     cw_logic_opsel:2;
unsigned int     write_enable2:1;
unsigned int     bcm:2;
unsigned int     write_enable1:1;
unsigned int     reg_first:1;
unsigned int     write_enable0:1;
unsigned int     reg_ende:1;
}CP_REG_SET;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     des_key_order:1;
unsigned int     reserved_1:1;
unsigned int     key_mode:2;
unsigned int     iv_mode:2;
unsigned int     input_mode:2;
unsigned int     output_mode:2;
}CP_REG_SET1;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     output_entry:7;
unsigned int     reserved_1:1;
unsigned int     input_entry:7;
unsigned int     reserved_2:1;
unsigned int     key_entry:7;
unsigned int     reserved_3:1;
unsigned int     iv_entry:7;
}CP_REG_SET2;

typedef struct 
{
unsigned int     reg1:16;
unsigned int     reg0:16;
}CP_SCTCH;

typedef struct 
{
unsigned int     data:32;
}CP_NF_KEY;

typedef struct 
{
unsigned int     data:32;
}CP_NF_INI_KEY;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     bcm:2;
unsigned int     cw_entry:7;
unsigned int     sel:2;
}CP_NF_SET;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     sel:1;
}CP_NF_EMMC;

typedef struct 
{
unsigned int     data:32;
}CP_MD_KEY;

typedef struct 
{
unsigned int     data:32;
}CP_MD_INI_KEY;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     bcm:2;
unsigned int     cw_entry:7;
unsigned int     sel:2;
}CP_MD_SET;

typedef struct 
{
unsigned int     data:32;
}K_CP_REG_KEY;

typedef struct 
{
unsigned int     data:32;
}K_CP_REG_DATAIN;

typedef struct 
{
unsigned int     data:32;
}K_CP_REG_DATAOUT;

typedef struct 
{
unsigned int     data:32;
}K_CP_REG_IV;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     write_enable5:1;
unsigned int     mode:4;
unsigned int     reserved_1:1;
unsigned int     write_enable4:1;
unsigned int     endian_swap:1;
unsigned int     write_enable3:1;
unsigned int     cw_logic_opsel:2;
unsigned int     write_enable2:1;
unsigned int     bcm:2;
unsigned int     write_enable1:1;
unsigned int     reg_first:1;
unsigned int     write_enable0:1;
unsigned int     reg_ende:1;
}K_CP_REG_SET;

typedef struct 
{
unsigned int     reserved_0:22;
unsigned int     des_key_order:1;
unsigned int     key_mode:3;
unsigned int     iv_mode:2;
unsigned int     input_mode:2;
unsigned int     output_mode:2;
}K_CP_REG_SET1;

typedef struct 
{
unsigned int     reserved_0:1;
unsigned int     output_entry:7;
unsigned int     reserved_1:1;
unsigned int     input_entry:7;
unsigned int     reserved_2:1;
unsigned int     key_entry:7;
unsigned int     reserved_3:1;
unsigned int     iv_entry:7;
}K_CP_REG_SET2;

typedef struct 
{
unsigned int     data:32;
}K_CP_NF_KEY;

typedef struct 
{
unsigned int     data:32;
}K_CP_NF_INI_KEY;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     bcm:2;
unsigned int     cw_entry:7;
unsigned int     sel:2;
}K_CP_NF_SET;

typedef struct 
{
unsigned int     data:32;
}K_CP_MD_KEY;

typedef struct 
{
unsigned int     data:32;
}K_CP_MD_INI_KEY;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     bcm:2;
unsigned int     cw_entry:7;
unsigned int     sel:2;
}K_CP_MD_SET;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     dbg_sel1:5;
unsigned int     dbg_sel0:5;
unsigned int     dbg_en:1;
}CP_DBG;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_illegal_access:1;
}K_CP_STATUS;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_illegal_access_en:1;
}K_CP_EN;

typedef struct 
{
unsigned int     reserved_0:21;
unsigned int     tst_sel1:5;
unsigned int     tst_sel0:5;
unsigned int     tst_en:1;
}CP_TST1;

typedef struct 
{
unsigned int     test_out:32;
}CP_TST2;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     en:1;
}CP_BIST_MODE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     done:1;
}CP_BIST_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     fail_group:1;
}CP_BIST_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     fail3:1;
unsigned int     reserved_1:3;
unsigned int     fail2:1;
unsigned int     reserved_2:3;
unsigned int     fail1:1;
unsigned int     reserved_3:3;
unsigned int     fail0:1;
}CP_BIST_FAIL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     en:1;
}CP_DRF_MODE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     done:1;
}CP_DRF_DONE;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     fail_group:1;
}CP_DRF_FAIL_GROUP;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     fail3:1;
unsigned int     reserved_1:3;
unsigned int     fail2:1;
unsigned int     reserved_2:3;
unsigned int     fail1:1;
unsigned int     reserved_3:3;
unsigned int     fail0:1;
}CP_DRF_FAIL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     en:1;
}CP_DRF_RESUME;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     flag:1;
}CP_DRF_PAUSE;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     rsa_rme:1;
unsigned int     rsa_rm:4;
unsigned int     reserved_1:3;
unsigned int     din1_rme:1;
unsigned int     din1_rm:4;
unsigned int     reserved_2:3;
unsigned int     din0_rme:1;
unsigned int     din0_rm:4;
unsigned int     reserved_3:3;
unsigned int     desc_rme:1;
unsigned int     desc_rm:4;
}CP_SRAM_RM;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     rsa_ls:1;
unsigned int     reserved_1:3;
unsigned int     din1_ls:1;
unsigned int     reserved_2:3;
unsigned int     din0_ls:1;
unsigned int     reserved_3:3;
unsigned int     desc_ls:1;
}CP_SRAM_LS;

typedef struct 
{
unsigned int     reserved_0:17;
unsigned int     start:7;
unsigned int     reserved_1:1;
unsigned int     end:7;
}K_CP_SCPU_CW_RANGE;

#endif

#define CP_REG_KEY_0                                                                 0x18015034
#define CP_REG_KEY_1                                                                 0x18015038
#define CP_REG_KEY_2                                                                 0x1801503C
#define CP_REG_KEY_3                                                                 0x18015040
#define CP_REG_KEY_0_reg_addr                                                        "0xB8015034"
#define CP_REG_KEY_1_reg_addr                                                        "0xB8015038"
#define CP_REG_KEY_2_reg_addr                                                        "0xB801503C"
#define CP_REG_KEY_3_reg_addr                                                        "0xB8015040"
#define CP_REG_KEY_0_reg                                                             0xB8015034
#define CP_REG_KEY_1_reg                                                             0xB8015038
#define CP_REG_KEY_2_reg                                                             0xB801503C
#define CP_REG_KEY_3_reg                                                             0xB8015040
#define set_CP_REG_KEY_0_reg(data)   (*((volatile unsigned int*) CP_REG_KEY_0_reg)=data)
#define set_CP_REG_KEY_1_reg(data)   (*((volatile unsigned int*) CP_REG_KEY_1_reg)=data)
#define set_CP_REG_KEY_2_reg(data)   (*((volatile unsigned int*) CP_REG_KEY_2_reg)=data)
#define set_CP_REG_KEY_3_reg(data)   (*((volatile unsigned int*) CP_REG_KEY_3_reg)=data)
#define get_CP_REG_KEY_0_reg   (*((volatile unsigned int*) CP_REG_KEY_0_reg))
#define get_CP_REG_KEY_1_reg   (*((volatile unsigned int*) CP_REG_KEY_1_reg))
#define get_CP_REG_KEY_2_reg   (*((volatile unsigned int*) CP_REG_KEY_2_reg))
#define get_CP_REG_KEY_3_reg   (*((volatile unsigned int*) CP_REG_KEY_3_reg))
#define CP_REG_KEY_0_inst_adr                                                        "0x000D"
#define CP_REG_KEY_1_inst_adr                                                        "0x000E"
#define CP_REG_KEY_2_inst_adr                                                        "0x000F"
#define CP_REG_KEY_3_inst_adr                                                        "0x0010"
#define CP_REG_KEY_0_inst                                                            0x000D
#define CP_REG_KEY_1_inst                                                            0x000E
#define CP_REG_KEY_2_inst                                                            0x000F
#define CP_REG_KEY_3_inst                                                            0x0010
#define CP_REG_KEY_data_shift                                                        (0)
#define CP_REG_KEY_data_mask                                                         (0xFFFFFFFF)
#define CP_REG_KEY_data(data)                                                        (0xFFFFFFFF&((data)<<0))
#define CP_REG_KEY_data_src(data)                                                    ((0xFFFFFFFF&(data))>>0)
#define CP_REG_KEY_get_data(data)                                                    ((0xFFFFFFFF&(data))>>0)


#define CP_REG_DATAIN_0                                                              0x18015044
#define CP_REG_DATAIN_1                                                              0x18015048
#define CP_REG_DATAIN_2                                                              0x1801504C
#define CP_REG_DATAIN_3                                                              0x18015050
#define CP_REG_DATAIN_0_reg_addr                                                     "0xB8015044"
#define CP_REG_DATAIN_1_reg_addr                                                     "0xB8015048"
#define CP_REG_DATAIN_2_reg_addr                                                     "0xB801504C"
#define CP_REG_DATAIN_3_reg_addr                                                     "0xB8015050"
#define CP_REG_DATAIN_0_reg                                                          0xB8015044
#define CP_REG_DATAIN_1_reg                                                          0xB8015048
#define CP_REG_DATAIN_2_reg                                                          0xB801504C
#define CP_REG_DATAIN_3_reg                                                          0xB8015050
#define set_CP_REG_DATAIN_0_reg(data)   (*((volatile unsigned int*) CP_REG_DATAIN_0_reg)=data)
#define set_CP_REG_DATAIN_1_reg(data)   (*((volatile unsigned int*) CP_REG_DATAIN_1_reg)=data)
#define set_CP_REG_DATAIN_2_reg(data)   (*((volatile unsigned int*) CP_REG_DATAIN_2_reg)=data)
#define set_CP_REG_DATAIN_3_reg(data)   (*((volatile unsigned int*) CP_REG_DATAIN_3_reg)=data)
#define get_CP_REG_DATAIN_0_reg   (*((volatile unsigned int*) CP_REG_DATAIN_0_reg))
#define get_CP_REG_DATAIN_1_reg   (*((volatile unsigned int*) CP_REG_DATAIN_1_reg))
#define get_CP_REG_DATAIN_2_reg   (*((volatile unsigned int*) CP_REG_DATAIN_2_reg))
#define get_CP_REG_DATAIN_3_reg   (*((volatile unsigned int*) CP_REG_DATAIN_3_reg))
#define CP_REG_DATAIN_0_inst_adr                                                     "0x0011"
#define CP_REG_DATAIN_1_inst_adr                                                     "0x0012"
#define CP_REG_DATAIN_2_inst_adr                                                     "0x0013"
#define CP_REG_DATAIN_3_inst_adr                                                     "0x0014"
#define CP_REG_DATAIN_0_inst                                                         0x0011
#define CP_REG_DATAIN_1_inst                                                         0x0012
#define CP_REG_DATAIN_2_inst                                                         0x0013
#define CP_REG_DATAIN_3_inst                                                         0x0014
#define CP_REG_DATAIN_data_shift                                                     (0)
#define CP_REG_DATAIN_data_mask                                                      (0xFFFFFFFF)
#define CP_REG_DATAIN_data(data)                                                     (0xFFFFFFFF&((data)<<0))
#define CP_REG_DATAIN_data_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define CP_REG_DATAIN_get_data(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define CP_REG_DATAOUT_0                                                             0x18015054
#define CP_REG_DATAOUT_1                                                             0x18015058
#define CP_REG_DATAOUT_2                                                             0x1801505C
#define CP_REG_DATAOUT_3                                                             0x18015060
#define CP_REG_DATAOUT_4                                                             0x18015064
#define CP_REG_DATAOUT_5                                                             0x18015068
#define CP_REG_DATAOUT_6                                                             0x1801506C
#define CP_REG_DATAOUT_7                                                             0x18015070
#define CP_REG_DATAOUT_0_reg_addr                                                    "0xB8015054"
#define CP_REG_DATAOUT_1_reg_addr                                                    "0xB8015058"
#define CP_REG_DATAOUT_2_reg_addr                                                    "0xB801505C"
#define CP_REG_DATAOUT_3_reg_addr                                                    "0xB8015060"
#define CP_REG_DATAOUT_4_reg_addr                                                    "0xB8015064"
#define CP_REG_DATAOUT_5_reg_addr                                                    "0xB8015068"
#define CP_REG_DATAOUT_6_reg_addr                                                    "0xB801506C"
#define CP_REG_DATAOUT_7_reg_addr                                                    "0xB8015070"
#define CP_REG_DATAOUT_0_reg                                                         0xB8015054
#define CP_REG_DATAOUT_1_reg                                                         0xB8015058
#define CP_REG_DATAOUT_2_reg                                                         0xB801505C
#define CP_REG_DATAOUT_3_reg                                                         0xB8015060
#define CP_REG_DATAOUT_4_reg                                                         0xB8015064
#define CP_REG_DATAOUT_5_reg                                                         0xB8015068
#define CP_REG_DATAOUT_6_reg                                                         0xB801506C
#define CP_REG_DATAOUT_7_reg                                                         0xB8015070
#define set_CP_REG_DATAOUT_0_reg(data)   (*((volatile unsigned int*) CP_REG_DATAOUT_0_reg)=data)
#define set_CP_REG_DATAOUT_1_reg(data)   (*((volatile unsigned int*) CP_REG_DATAOUT_1_reg)=data)
#define set_CP_REG_DATAOUT_2_reg(data)   (*((volatile unsigned int*) CP_REG_DATAOUT_2_reg)=data)
#define set_CP_REG_DATAOUT_3_reg(data)   (*((volatile unsigned int*) CP_REG_DATAOUT_3_reg)=data)
#define set_CP_REG_DATAOUT_4_reg(data)   (*((volatile unsigned int*) CP_REG_DATAOUT_4_reg)=data)
#define set_CP_REG_DATAOUT_5_reg(data)   (*((volatile unsigned int*) CP_REG_DATAOUT_5_reg)=data)
#define set_CP_REG_DATAOUT_6_reg(data)   (*((volatile unsigned int*) CP_REG_DATAOUT_6_reg)=data)
#define set_CP_REG_DATAOUT_7_reg(data)   (*((volatile unsigned int*) CP_REG_DATAOUT_7_reg)=data)
#define get_CP_REG_DATAOUT_0_reg   (*((volatile unsigned int*) CP_REG_DATAOUT_0_reg))
#define get_CP_REG_DATAOUT_1_reg   (*((volatile unsigned int*) CP_REG_DATAOUT_1_reg))
#define get_CP_REG_DATAOUT_2_reg   (*((volatile unsigned int*) CP_REG_DATAOUT_2_reg))
#define get_CP_REG_DATAOUT_3_reg   (*((volatile unsigned int*) CP_REG_DATAOUT_3_reg))
#define get_CP_REG_DATAOUT_4_reg   (*((volatile unsigned int*) CP_REG_DATAOUT_4_reg))
#define get_CP_REG_DATAOUT_5_reg   (*((volatile unsigned int*) CP_REG_DATAOUT_5_reg))
#define get_CP_REG_DATAOUT_6_reg   (*((volatile unsigned int*) CP_REG_DATAOUT_6_reg))
#define get_CP_REG_DATAOUT_7_reg   (*((volatile unsigned int*) CP_REG_DATAOUT_7_reg))
#define CP_REG_DATAOUT_0_inst_adr                                                    "0x0015"
#define CP_REG_DATAOUT_1_inst_adr                                                    "0x0016"
#define CP_REG_DATAOUT_2_inst_adr                                                    "0x0017"
#define CP_REG_DATAOUT_3_inst_adr                                                    "0x0018"
#define CP_REG_DATAOUT_4_inst_adr                                                    "0x0019"
#define CP_REG_DATAOUT_5_inst_adr                                                    "0x001A"
#define CP_REG_DATAOUT_6_inst_adr                                                    "0x001B"
#define CP_REG_DATAOUT_7_inst_adr                                                    "0x001C"
#define CP_REG_DATAOUT_0_inst                                                        0x0015
#define CP_REG_DATAOUT_1_inst                                                        0x0016
#define CP_REG_DATAOUT_2_inst                                                        0x0017
#define CP_REG_DATAOUT_3_inst                                                        0x0018
#define CP_REG_DATAOUT_4_inst                                                        0x0019
#define CP_REG_DATAOUT_5_inst                                                        0x001A
#define CP_REG_DATAOUT_6_inst                                                        0x001B
#define CP_REG_DATAOUT_7_inst                                                        0x001C
#define CP_REG_DATAOUT_data_shift                                                    (0)
#define CP_REG_DATAOUT_data_mask                                                     (0xFFFFFFFF)
#define CP_REG_DATAOUT_data(data)                                                    (0xFFFFFFFF&((data)<<0))
#define CP_REG_DATAOUT_data_src(data)                                                ((0xFFFFFFFF&(data))>>0)
#define CP_REG_DATAOUT_get_data(data)                                                ((0xFFFFFFFF&(data))>>0)


#define CP_REG_IV_0                                                                  0x180150D0
#define CP_REG_IV_1                                                                  0x180150D4
#define CP_REG_IV_2                                                                  0x180150D8
#define CP_REG_IV_3                                                                  0x180150DC
#define CP_REG_IV_4                                                                  0x180150E0
#define CP_REG_IV_5                                                                  0x180150E4
#define CP_REG_IV_6                                                                  0x180150E8
#define CP_REG_IV_7                                                                  0x180150EC
#define CP_REG_IV_0_reg_addr                                                         "0xB80150D0"
#define CP_REG_IV_1_reg_addr                                                         "0xB80150D4"
#define CP_REG_IV_2_reg_addr                                                         "0xB80150D8"
#define CP_REG_IV_3_reg_addr                                                         "0xB80150DC"
#define CP_REG_IV_4_reg_addr                                                         "0xB80150E0"
#define CP_REG_IV_5_reg_addr                                                         "0xB80150E4"
#define CP_REG_IV_6_reg_addr                                                         "0xB80150E8"
#define CP_REG_IV_7_reg_addr                                                         "0xB80150EC"
#define CP_REG_IV_0_reg                                                              0xB80150D0
#define CP_REG_IV_1_reg                                                              0xB80150D4
#define CP_REG_IV_2_reg                                                              0xB80150D8
#define CP_REG_IV_3_reg                                                              0xB80150DC
#define CP_REG_IV_4_reg                                                              0xB80150E0
#define CP_REG_IV_5_reg                                                              0xB80150E4
#define CP_REG_IV_6_reg                                                              0xB80150E8
#define CP_REG_IV_7_reg                                                              0xB80150EC
#define set_CP_REG_IV_0_reg(data)   (*((volatile unsigned int*) CP_REG_IV_0_reg)=data)
#define set_CP_REG_IV_1_reg(data)   (*((volatile unsigned int*) CP_REG_IV_1_reg)=data)
#define set_CP_REG_IV_2_reg(data)   (*((volatile unsigned int*) CP_REG_IV_2_reg)=data)
#define set_CP_REG_IV_3_reg(data)   (*((volatile unsigned int*) CP_REG_IV_3_reg)=data)
#define set_CP_REG_IV_4_reg(data)   (*((volatile unsigned int*) CP_REG_IV_4_reg)=data)
#define set_CP_REG_IV_5_reg(data)   (*((volatile unsigned int*) CP_REG_IV_5_reg)=data)
#define set_CP_REG_IV_6_reg(data)   (*((volatile unsigned int*) CP_REG_IV_6_reg)=data)
#define set_CP_REG_IV_7_reg(data)   (*((volatile unsigned int*) CP_REG_IV_7_reg)=data)
#define get_CP_REG_IV_0_reg   (*((volatile unsigned int*) CP_REG_IV_0_reg))
#define get_CP_REG_IV_1_reg   (*((volatile unsigned int*) CP_REG_IV_1_reg))
#define get_CP_REG_IV_2_reg   (*((volatile unsigned int*) CP_REG_IV_2_reg))
#define get_CP_REG_IV_3_reg   (*((volatile unsigned int*) CP_REG_IV_3_reg))
#define get_CP_REG_IV_4_reg   (*((volatile unsigned int*) CP_REG_IV_4_reg))
#define get_CP_REG_IV_5_reg   (*((volatile unsigned int*) CP_REG_IV_5_reg))
#define get_CP_REG_IV_6_reg   (*((volatile unsigned int*) CP_REG_IV_6_reg))
#define get_CP_REG_IV_7_reg   (*((volatile unsigned int*) CP_REG_IV_7_reg))
#define CP_REG_IV_0_inst_adr                                                         "0x0034"
#define CP_REG_IV_1_inst_adr                                                         "0x0035"
#define CP_REG_IV_2_inst_adr                                                         "0x0036"
#define CP_REG_IV_3_inst_adr                                                         "0x0037"
#define CP_REG_IV_4_inst_adr                                                         "0x0038"
#define CP_REG_IV_5_inst_adr                                                         "0x0039"
#define CP_REG_IV_6_inst_adr                                                         "0x003A"
#define CP_REG_IV_7_inst_adr                                                         "0x003B"
#define CP_REG_IV_0_inst                                                             0x0034
#define CP_REG_IV_1_inst                                                             0x0035
#define CP_REG_IV_2_inst                                                             0x0036
#define CP_REG_IV_3_inst                                                             0x0037
#define CP_REG_IV_4_inst                                                             0x0038
#define CP_REG_IV_5_inst                                                             0x0039
#define CP_REG_IV_6_inst                                                             0x003A
#define CP_REG_IV_7_inst                                                             0x003B
#define CP_REG_IV_data_shift                                                         (0)
#define CP_REG_IV_data_mask                                                          (0xFFFFFFFF)
#define CP_REG_IV_data(data)                                                         (0xFFFFFFFF&((data)<<0))
#define CP_REG_IV_data_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define CP_REG_IV_get_data(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define CP_REG_SET                                                                   0x18015074
#define CP_REG_SET_reg_addr                                                          "0xB8015074"
#define CP_REG_SET_reg                                                               0xB8015074
#define set_CP_REG_SET_reg(data)   (*((volatile unsigned int*) CP_REG_SET_reg)=data)
#define get_CP_REG_SET_reg   (*((volatile unsigned int*) CP_REG_SET_reg))
#define CP_REG_SET_inst_adr                                                          "0x001D"
#define CP_REG_SET_inst                                                              0x001D
#define CP_REG_SET_write_enable5_shift                                               (17)
#define CP_REG_SET_write_enable5_mask                                                (0x00020000)
#define CP_REG_SET_write_enable5(data)                                               (0x00020000&((data)<<17))
#define CP_REG_SET_write_enable5_src(data)                                           ((0x00020000&(data))>>17)
#define CP_REG_SET_get_write_enable5(data)                                           ((0x00020000&(data))>>17)
#define CP_REG_SET_mode_shift                                                        (13)
#define CP_REG_SET_mode_mask                                                         (0x0001E000)
#define CP_REG_SET_mode(data)                                                        (0x0001E000&((data)<<13))
#define CP_REG_SET_mode_src(data)                                                    ((0x0001E000&(data))>>13)
#define CP_REG_SET_get_mode(data)                                                    ((0x0001E000&(data))>>13)
#define CP_REG_SET_write_enable4_shift                                               (11)
#define CP_REG_SET_write_enable4_mask                                                (0x00000800)
#define CP_REG_SET_write_enable4(data)                                               (0x00000800&((data)<<11))
#define CP_REG_SET_write_enable4_src(data)                                           ((0x00000800&(data))>>11)
#define CP_REG_SET_get_write_enable4(data)                                           ((0x00000800&(data))>>11)
#define CP_REG_SET_endian_swap_shift                                                 (10)
#define CP_REG_SET_endian_swap_mask                                                  (0x00000400)
#define CP_REG_SET_endian_swap(data)                                                 (0x00000400&((data)<<10))
#define CP_REG_SET_endian_swap_src(data)                                             ((0x00000400&(data))>>10)
#define CP_REG_SET_get_endian_swap(data)                                             ((0x00000400&(data))>>10)
#define CP_REG_SET_write_enable3_shift                                               (9)
#define CP_REG_SET_write_enable3_mask                                                (0x00000200)
#define CP_REG_SET_write_enable3(data)                                               (0x00000200&((data)<<9))
#define CP_REG_SET_write_enable3_src(data)                                           ((0x00000200&(data))>>9)
#define CP_REG_SET_get_write_enable3(data)                                           ((0x00000200&(data))>>9)
#define CP_REG_SET_cw_logic_opsel_shift                                              (7)
#define CP_REG_SET_cw_logic_opsel_mask                                               (0x00000180)
#define CP_REG_SET_cw_logic_opsel(data)                                              (0x00000180&((data)<<7))
#define CP_REG_SET_cw_logic_opsel_src(data)                                          ((0x00000180&(data))>>7)
#define CP_REG_SET_get_cw_logic_opsel(data)                                          ((0x00000180&(data))>>7)
#define CP_REG_SET_write_enable2_shift                                               (6)
#define CP_REG_SET_write_enable2_mask                                                (0x00000040)
#define CP_REG_SET_write_enable2(data)                                               (0x00000040&((data)<<6))
#define CP_REG_SET_write_enable2_src(data)                                           ((0x00000040&(data))>>6)
#define CP_REG_SET_get_write_enable2(data)                                           ((0x00000040&(data))>>6)
#define CP_REG_SET_bcm_shift                                                         (4)
#define CP_REG_SET_bcm_mask                                                          (0x00000030)
#define CP_REG_SET_bcm(data)                                                         (0x00000030&((data)<<4))
#define CP_REG_SET_bcm_src(data)                                                     ((0x00000030&(data))>>4)
#define CP_REG_SET_get_bcm(data)                                                     ((0x00000030&(data))>>4)
#define CP_REG_SET_write_enable1_shift                                               (3)
#define CP_REG_SET_write_enable1_mask                                                (0x00000008)
#define CP_REG_SET_write_enable1(data)                                               (0x00000008&((data)<<3))
#define CP_REG_SET_write_enable1_src(data)                                           ((0x00000008&(data))>>3)
#define CP_REG_SET_get_write_enable1(data)                                           ((0x00000008&(data))>>3)
#define CP_REG_SET_reg_first_shift                                                   (2)
#define CP_REG_SET_reg_first_mask                                                    (0x00000004)
#define CP_REG_SET_reg_first(data)                                                   (0x00000004&((data)<<2))
#define CP_REG_SET_reg_first_src(data)                                               ((0x00000004&(data))>>2)
#define CP_REG_SET_get_reg_first(data)                                               ((0x00000004&(data))>>2)
#define CP_REG_SET_write_enable0_shift                                               (1)
#define CP_REG_SET_write_enable0_mask                                                (0x00000002)
#define CP_REG_SET_write_enable0(data)                                               (0x00000002&((data)<<1))
#define CP_REG_SET_write_enable0_src(data)                                           ((0x00000002&(data))>>1)
#define CP_REG_SET_get_write_enable0(data)                                           ((0x00000002&(data))>>1)
#define CP_REG_SET_reg_ende_shift                                                    (0)
#define CP_REG_SET_reg_ende_mask                                                     (0x00000001)
#define CP_REG_SET_reg_ende(data)                                                    (0x00000001&((data)<<0))
#define CP_REG_SET_reg_ende_src(data)                                                ((0x00000001&(data))>>0)
#define CP_REG_SET_get_reg_ende(data)                                                ((0x00000001&(data))>>0)


#define CP_REG_SET1                                                                  0x18015078
#define CP_REG_SET1_reg_addr                                                         "0xB8015078"
#define CP_REG_SET1_reg                                                              0xB8015078
#define set_CP_REG_SET1_reg(data)   (*((volatile unsigned int*) CP_REG_SET1_reg)=data)
#define get_CP_REG_SET1_reg   (*((volatile unsigned int*) CP_REG_SET1_reg))
#define CP_REG_SET1_inst_adr                                                         "0x001E"
#define CP_REG_SET1_inst                                                             0x001E
#define CP_REG_SET1_des_key_order_shift                                              (9)
#define CP_REG_SET1_des_key_order_mask                                               (0x00000200)
#define CP_REG_SET1_des_key_order(data)                                              (0x00000200&((data)<<9))
#define CP_REG_SET1_des_key_order_src(data)                                          ((0x00000200&(data))>>9)
#define CP_REG_SET1_get_des_key_order(data)                                          ((0x00000200&(data))>>9)
#define CP_REG_SET1_key_mode_shift                                                   (6)
#define CP_REG_SET1_key_mode_mask                                                    (0x000000C0)
#define CP_REG_SET1_key_mode(data)                                                   (0x000000C0&((data)<<6))
#define CP_REG_SET1_key_mode_src(data)                                               ((0x000000C0&(data))>>6)
#define CP_REG_SET1_get_key_mode(data)                                               ((0x000000C0&(data))>>6)
#define CP_REG_SET1_iv_mode_shift                                                    (4)
#define CP_REG_SET1_iv_mode_mask                                                     (0x00000030)
#define CP_REG_SET1_iv_mode(data)                                                    (0x00000030&((data)<<4))
#define CP_REG_SET1_iv_mode_src(data)                                                ((0x00000030&(data))>>4)
#define CP_REG_SET1_get_iv_mode(data)                                                ((0x00000030&(data))>>4)
#define CP_REG_SET1_input_mode_shift                                                 (2)
#define CP_REG_SET1_input_mode_mask                                                  (0x0000000C)
#define CP_REG_SET1_input_mode(data)                                                 (0x0000000C&((data)<<2))
#define CP_REG_SET1_input_mode_src(data)                                             ((0x0000000C&(data))>>2)
#define CP_REG_SET1_get_input_mode(data)                                             ((0x0000000C&(data))>>2)
#define CP_REG_SET1_output_mode_shift                                                (0)
#define CP_REG_SET1_output_mode_mask                                                 (0x00000003)
#define CP_REG_SET1_output_mode(data)                                                (0x00000003&((data)<<0))
#define CP_REG_SET1_output_mode_src(data)                                            ((0x00000003&(data))>>0)
#define CP_REG_SET1_get_output_mode(data)                                            ((0x00000003&(data))>>0)


#define CP_REG_SET2                                                                  0x1801507c
#define CP_REG_SET2_reg_addr                                                         "0xB801507C"
#define CP_REG_SET2_reg                                                              0xB801507C
#define set_CP_REG_SET2_reg(data)   (*((volatile unsigned int*) CP_REG_SET2_reg)=data)
#define get_CP_REG_SET2_reg   (*((volatile unsigned int*) CP_REG_SET2_reg))
#define CP_REG_SET2_inst_adr                                                         "0x001F"
#define CP_REG_SET2_inst                                                             0x001F
#define CP_REG_SET2_output_entry_shift                                               (24)
#define CP_REG_SET2_output_entry_mask                                                (0x7F000000)
#define CP_REG_SET2_output_entry(data)                                               (0x7F000000&((data)<<24))
#define CP_REG_SET2_output_entry_src(data)                                           ((0x7F000000&(data))>>24)
#define CP_REG_SET2_get_output_entry(data)                                           ((0x7F000000&(data))>>24)
#define CP_REG_SET2_input_entry_shift                                                (16)
#define CP_REG_SET2_input_entry_mask                                                 (0x007F0000)
#define CP_REG_SET2_input_entry(data)                                                (0x007F0000&((data)<<16))
#define CP_REG_SET2_input_entry_src(data)                                            ((0x007F0000&(data))>>16)
#define CP_REG_SET2_get_input_entry(data)                                            ((0x007F0000&(data))>>16)
#define CP_REG_SET2_key_entry_shift                                                  (8)
#define CP_REG_SET2_key_entry_mask                                                   (0x00007F00)
#define CP_REG_SET2_key_entry(data)                                                  (0x00007F00&((data)<<8))
#define CP_REG_SET2_key_entry_src(data)                                              ((0x00007F00&(data))>>8)
#define CP_REG_SET2_get_key_entry(data)                                              ((0x00007F00&(data))>>8)
#define CP_REG_SET2_iv_entry_shift                                                   (0)
#define CP_REG_SET2_iv_entry_mask                                                    (0x0000007F)
#define CP_REG_SET2_iv_entry(data)                                                   (0x0000007F&((data)<<0))
#define CP_REG_SET2_iv_entry_src(data)                                               ((0x0000007F&(data))>>0)
#define CP_REG_SET2_get_iv_entry(data)                                               ((0x0000007F&(data))>>0)


#define CP_SCTCH                                                                     0x18015080
#define CP_SCTCH_reg_addr                                                            "0xB8015080"
#define CP_SCTCH_reg                                                                 0xB8015080
#define set_CP_SCTCH_reg(data)   (*((volatile unsigned int*) CP_SCTCH_reg)=data)
#define get_CP_SCTCH_reg   (*((volatile unsigned int*) CP_SCTCH_reg))
#define CP_SCTCH_inst_adr                                                            "0x0020"
#define CP_SCTCH_inst                                                                0x0020
#define CP_SCTCH_reg1_shift                                                          (16)
#define CP_SCTCH_reg1_mask                                                           (0xFFFF0000)
#define CP_SCTCH_reg1(data)                                                          (0xFFFF0000&((data)<<16))
#define CP_SCTCH_reg1_src(data)                                                      ((0xFFFF0000&(data))>>16)
#define CP_SCTCH_get_reg1(data)                                                      ((0xFFFF0000&(data))>>16)
#define CP_SCTCH_reg0_shift                                                          (0)
#define CP_SCTCH_reg0_mask                                                           (0x0000FFFF)
#define CP_SCTCH_reg0(data)                                                          (0x0000FFFF&((data)<<0))
#define CP_SCTCH_reg0_src(data)                                                      ((0x0000FFFF&(data))>>0)
#define CP_SCTCH_get_reg0(data)                                                      ((0x0000FFFF&(data))>>0)


#define CP_NF_KEY_0                                                                  0x18015084
#define CP_NF_KEY_1                                                                  0x18015088
#define CP_NF_KEY_2                                                                  0x1801508C
#define CP_NF_KEY_3                                                                  0x18015090
#define CP_NF_KEY_0_reg_addr                                                         "0xB8015084"
#define CP_NF_KEY_1_reg_addr                                                         "0xB8015088"
#define CP_NF_KEY_2_reg_addr                                                         "0xB801508C"
#define CP_NF_KEY_3_reg_addr                                                         "0xB8015090"
#define CP_NF_KEY_0_reg                                                              0xB8015084
#define CP_NF_KEY_1_reg                                                              0xB8015088
#define CP_NF_KEY_2_reg                                                              0xB801508C
#define CP_NF_KEY_3_reg                                                              0xB8015090
#define set_CP_NF_KEY_0_reg(data)   (*((volatile unsigned int*) CP_NF_KEY_0_reg)=data)
#define set_CP_NF_KEY_1_reg(data)   (*((volatile unsigned int*) CP_NF_KEY_1_reg)=data)
#define set_CP_NF_KEY_2_reg(data)   (*((volatile unsigned int*) CP_NF_KEY_2_reg)=data)
#define set_CP_NF_KEY_3_reg(data)   (*((volatile unsigned int*) CP_NF_KEY_3_reg)=data)
#define get_CP_NF_KEY_0_reg   (*((volatile unsigned int*) CP_NF_KEY_0_reg))
#define get_CP_NF_KEY_1_reg   (*((volatile unsigned int*) CP_NF_KEY_1_reg))
#define get_CP_NF_KEY_2_reg   (*((volatile unsigned int*) CP_NF_KEY_2_reg))
#define get_CP_NF_KEY_3_reg   (*((volatile unsigned int*) CP_NF_KEY_3_reg))
#define CP_NF_KEY_0_inst_adr                                                         "0x0021"
#define CP_NF_KEY_1_inst_adr                                                         "0x0022"
#define CP_NF_KEY_2_inst_adr                                                         "0x0023"
#define CP_NF_KEY_3_inst_adr                                                         "0x0024"
#define CP_NF_KEY_0_inst                                                             0x0021
#define CP_NF_KEY_1_inst                                                             0x0022
#define CP_NF_KEY_2_inst                                                             0x0023
#define CP_NF_KEY_3_inst                                                             0x0024
#define CP_NF_KEY_data_shift                                                         (0)
#define CP_NF_KEY_data_mask                                                          (0xFFFFFFFF)
#define CP_NF_KEY_data(data)                                                         (0xFFFFFFFF&((data)<<0))
#define CP_NF_KEY_data_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define CP_NF_KEY_get_data(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define CP_NF_INI_KEY_0                                                              0x18015094
#define CP_NF_INI_KEY_1                                                              0x18015098
#define CP_NF_INI_KEY_2                                                              0x1801509C
#define CP_NF_INI_KEY_3                                                              0x180150A0
#define CP_NF_INI_KEY_0_reg_addr                                                     "0xB8015094"
#define CP_NF_INI_KEY_1_reg_addr                                                     "0xB8015098"
#define CP_NF_INI_KEY_2_reg_addr                                                     "0xB801509C"
#define CP_NF_INI_KEY_3_reg_addr                                                     "0xB80150A0"
#define CP_NF_INI_KEY_0_reg                                                          0xB8015094
#define CP_NF_INI_KEY_1_reg                                                          0xB8015098
#define CP_NF_INI_KEY_2_reg                                                          0xB801509C
#define CP_NF_INI_KEY_3_reg                                                          0xB80150A0
#define set_CP_NF_INI_KEY_0_reg(data)   (*((volatile unsigned int*) CP_NF_INI_KEY_0_reg)=data)
#define set_CP_NF_INI_KEY_1_reg(data)   (*((volatile unsigned int*) CP_NF_INI_KEY_1_reg)=data)
#define set_CP_NF_INI_KEY_2_reg(data)   (*((volatile unsigned int*) CP_NF_INI_KEY_2_reg)=data)
#define set_CP_NF_INI_KEY_3_reg(data)   (*((volatile unsigned int*) CP_NF_INI_KEY_3_reg)=data)
#define get_CP_NF_INI_KEY_0_reg   (*((volatile unsigned int*) CP_NF_INI_KEY_0_reg))
#define get_CP_NF_INI_KEY_1_reg   (*((volatile unsigned int*) CP_NF_INI_KEY_1_reg))
#define get_CP_NF_INI_KEY_2_reg   (*((volatile unsigned int*) CP_NF_INI_KEY_2_reg))
#define get_CP_NF_INI_KEY_3_reg   (*((volatile unsigned int*) CP_NF_INI_KEY_3_reg))
#define CP_NF_INI_KEY_0_inst_adr                                                     "0x0025"
#define CP_NF_INI_KEY_1_inst_adr                                                     "0x0026"
#define CP_NF_INI_KEY_2_inst_adr                                                     "0x0027"
#define CP_NF_INI_KEY_3_inst_adr                                                     "0x0028"
#define CP_NF_INI_KEY_0_inst                                                         0x0025
#define CP_NF_INI_KEY_1_inst                                                         0x0026
#define CP_NF_INI_KEY_2_inst                                                         0x0027
#define CP_NF_INI_KEY_3_inst                                                         0x0028
#define CP_NF_INI_KEY_data_shift                                                     (0)
#define CP_NF_INI_KEY_data_mask                                                      (0xFFFFFFFF)
#define CP_NF_INI_KEY_data(data)                                                     (0xFFFFFFFF&((data)<<0))
#define CP_NF_INI_KEY_data_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define CP_NF_INI_KEY_get_data(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define CP_NF_SET                                                                    0x180150a4
#define CP_NF_SET_reg_addr                                                           "0xB80150A4"
#define CP_NF_SET_reg                                                                0xB80150A4
#define set_CP_NF_SET_reg(data)   (*((volatile unsigned int*) CP_NF_SET_reg)=data)
#define get_CP_NF_SET_reg   (*((volatile unsigned int*) CP_NF_SET_reg))
#define CP_NF_SET_inst_adr                                                           "0x0029"
#define CP_NF_SET_inst                                                               0x0029
#define CP_NF_SET_bcm_shift                                                          (9)
#define CP_NF_SET_bcm_mask                                                           (0x00000600)
#define CP_NF_SET_bcm(data)                                                          (0x00000600&((data)<<9))
#define CP_NF_SET_bcm_src(data)                                                      ((0x00000600&(data))>>9)
#define CP_NF_SET_get_bcm(data)                                                      ((0x00000600&(data))>>9)
#define CP_NF_SET_cw_entry_shift                                                     (2)
#define CP_NF_SET_cw_entry_mask                                                      (0x000001FC)
#define CP_NF_SET_cw_entry(data)                                                     (0x000001FC&((data)<<2))
#define CP_NF_SET_cw_entry_src(data)                                                 ((0x000001FC&(data))>>2)
#define CP_NF_SET_get_cw_entry(data)                                                 ((0x000001FC&(data))>>2)
#define CP_NF_SET_sel_shift                                                          (0)
#define CP_NF_SET_sel_mask                                                           (0x00000003)
#define CP_NF_SET_sel(data)                                                          (0x00000003&((data)<<0))
#define CP_NF_SET_sel_src(data)                                                      ((0x00000003&(data))>>0)
#define CP_NF_SET_get_sel(data)                                                      ((0x00000003&(data))>>0)


#define CP_NF_EMMC                                                                   0x18015200
#define CP_NF_EMMC_reg_addr                                                          "0xB8015200"
#define CP_NF_EMMC_reg                                                               0xB8015200
#define set_CP_NF_EMMC_reg(data)   (*((volatile unsigned int*) CP_NF_EMMC_reg)=data)
#define get_CP_NF_EMMC_reg   (*((volatile unsigned int*) CP_NF_EMMC_reg))
#define CP_NF_EMMC_inst_adr                                                          "0x0080"
#define CP_NF_EMMC_inst                                                              0x0080
#define CP_NF_EMMC_sel_shift                                                         (0)
#define CP_NF_EMMC_sel_mask                                                          (0x00000001)
#define CP_NF_EMMC_sel(data)                                                         (0x00000001&((data)<<0))
#define CP_NF_EMMC_sel_src(data)                                                     ((0x00000001&(data))>>0)
#define CP_NF_EMMC_get_sel(data)                                                     ((0x00000001&(data))>>0)


#define CP_MD_KEY_0                                                                  0x180150A8
#define CP_MD_KEY_1                                                                  0x180150AC
#define CP_MD_KEY_2                                                                  0x180150B0
#define CP_MD_KEY_3                                                                  0x180150B4
#define CP_MD_KEY_0_reg_addr                                                         "0xB80150A8"
#define CP_MD_KEY_1_reg_addr                                                         "0xB80150AC"
#define CP_MD_KEY_2_reg_addr                                                         "0xB80150B0"
#define CP_MD_KEY_3_reg_addr                                                         "0xB80150B4"
#define CP_MD_KEY_0_reg                                                              0xB80150A8
#define CP_MD_KEY_1_reg                                                              0xB80150AC
#define CP_MD_KEY_2_reg                                                              0xB80150B0
#define CP_MD_KEY_3_reg                                                              0xB80150B4
#define set_CP_MD_KEY_0_reg(data)   (*((volatile unsigned int*) CP_MD_KEY_0_reg)=data)
#define set_CP_MD_KEY_1_reg(data)   (*((volatile unsigned int*) CP_MD_KEY_1_reg)=data)
#define set_CP_MD_KEY_2_reg(data)   (*((volatile unsigned int*) CP_MD_KEY_2_reg)=data)
#define set_CP_MD_KEY_3_reg(data)   (*((volatile unsigned int*) CP_MD_KEY_3_reg)=data)
#define get_CP_MD_KEY_0_reg   (*((volatile unsigned int*) CP_MD_KEY_0_reg))
#define get_CP_MD_KEY_1_reg   (*((volatile unsigned int*) CP_MD_KEY_1_reg))
#define get_CP_MD_KEY_2_reg   (*((volatile unsigned int*) CP_MD_KEY_2_reg))
#define get_CP_MD_KEY_3_reg   (*((volatile unsigned int*) CP_MD_KEY_3_reg))
#define CP_MD_KEY_0_inst_adr                                                         "0x002A"
#define CP_MD_KEY_1_inst_adr                                                         "0x002B"
#define CP_MD_KEY_2_inst_adr                                                         "0x002C"
#define CP_MD_KEY_3_inst_adr                                                         "0x002D"
#define CP_MD_KEY_0_inst                                                             0x002A
#define CP_MD_KEY_1_inst                                                             0x002B
#define CP_MD_KEY_2_inst                                                             0x002C
#define CP_MD_KEY_3_inst                                                             0x002D
#define CP_MD_KEY_data_shift                                                         (0)
#define CP_MD_KEY_data_mask                                                          (0xFFFFFFFF)
#define CP_MD_KEY_data(data)                                                         (0xFFFFFFFF&((data)<<0))
#define CP_MD_KEY_data_src(data)                                                     ((0xFFFFFFFF&(data))>>0)
#define CP_MD_KEY_get_data(data)                                                     ((0xFFFFFFFF&(data))>>0)


#define CP_MD_INI_KEY_0                                                              0x180150B8
#define CP_MD_INI_KEY_1                                                              0x180150BC
#define CP_MD_INI_KEY_2                                                              0x180150C0
#define CP_MD_INI_KEY_3                                                              0x180150C4
#define CP_MD_INI_KEY_0_reg_addr                                                     "0xB80150B8"
#define CP_MD_INI_KEY_1_reg_addr                                                     "0xB80150BC"
#define CP_MD_INI_KEY_2_reg_addr                                                     "0xB80150C0"
#define CP_MD_INI_KEY_3_reg_addr                                                     "0xB80150C4"
#define CP_MD_INI_KEY_0_reg                                                          0xB80150B8
#define CP_MD_INI_KEY_1_reg                                                          0xB80150BC
#define CP_MD_INI_KEY_2_reg                                                          0xB80150C0
#define CP_MD_INI_KEY_3_reg                                                          0xB80150C4
#define set_CP_MD_INI_KEY_0_reg(data)   (*((volatile unsigned int*) CP_MD_INI_KEY_0_reg)=data)
#define set_CP_MD_INI_KEY_1_reg(data)   (*((volatile unsigned int*) CP_MD_INI_KEY_1_reg)=data)
#define set_CP_MD_INI_KEY_2_reg(data)   (*((volatile unsigned int*) CP_MD_INI_KEY_2_reg)=data)
#define set_CP_MD_INI_KEY_3_reg(data)   (*((volatile unsigned int*) CP_MD_INI_KEY_3_reg)=data)
#define get_CP_MD_INI_KEY_0_reg   (*((volatile unsigned int*) CP_MD_INI_KEY_0_reg))
#define get_CP_MD_INI_KEY_1_reg   (*((volatile unsigned int*) CP_MD_INI_KEY_1_reg))
#define get_CP_MD_INI_KEY_2_reg   (*((volatile unsigned int*) CP_MD_INI_KEY_2_reg))
#define get_CP_MD_INI_KEY_3_reg   (*((volatile unsigned int*) CP_MD_INI_KEY_3_reg))
#define CP_MD_INI_KEY_0_inst_adr                                                     "0x002E"
#define CP_MD_INI_KEY_1_inst_adr                                                     "0x002F"
#define CP_MD_INI_KEY_2_inst_adr                                                     "0x0030"
#define CP_MD_INI_KEY_3_inst_adr                                                     "0x0031"
#define CP_MD_INI_KEY_0_inst                                                         0x002E
#define CP_MD_INI_KEY_1_inst                                                         0x002F
#define CP_MD_INI_KEY_2_inst                                                         0x0030
#define CP_MD_INI_KEY_3_inst                                                         0x0031
#define CP_MD_INI_KEY_data_shift                                                     (0)
#define CP_MD_INI_KEY_data_mask                                                      (0xFFFFFFFF)
#define CP_MD_INI_KEY_data(data)                                                     (0xFFFFFFFF&((data)<<0))
#define CP_MD_INI_KEY_data_src(data)                                                 ((0xFFFFFFFF&(data))>>0)
#define CP_MD_INI_KEY_get_data(data)                                                 ((0xFFFFFFFF&(data))>>0)


#define CP_MD_SET                                                                    0x180150c8
#define CP_MD_SET_reg_addr                                                           "0xB80150C8"
#define CP_MD_SET_reg                                                                0xB80150C8
#define set_CP_MD_SET_reg(data)   (*((volatile unsigned int*) CP_MD_SET_reg)=data)
#define get_CP_MD_SET_reg   (*((volatile unsigned int*) CP_MD_SET_reg))
#define CP_MD_SET_inst_adr                                                           "0x0032"
#define CP_MD_SET_inst                                                               0x0032
#define CP_MD_SET_bcm_shift                                                          (9)
#define CP_MD_SET_bcm_mask                                                           (0x00000600)
#define CP_MD_SET_bcm(data)                                                          (0x00000600&((data)<<9))
#define CP_MD_SET_bcm_src(data)                                                      ((0x00000600&(data))>>9)
#define CP_MD_SET_get_bcm(data)                                                      ((0x00000600&(data))>>9)
#define CP_MD_SET_cw_entry_shift                                                     (2)
#define CP_MD_SET_cw_entry_mask                                                      (0x000001FC)
#define CP_MD_SET_cw_entry(data)                                                     (0x000001FC&((data)<<2))
#define CP_MD_SET_cw_entry_src(data)                                                 ((0x000001FC&(data))>>2)
#define CP_MD_SET_get_cw_entry(data)                                                 ((0x000001FC&(data))>>2)
#define CP_MD_SET_sel_shift                                                          (0)
#define CP_MD_SET_sel_mask                                                           (0x00000003)
#define CP_MD_SET_sel(data)                                                          (0x00000003&((data)<<0))
#define CP_MD_SET_sel_src(data)                                                      ((0x00000003&(data))>>0)
#define CP_MD_SET_get_sel(data)                                                      ((0x00000003&(data))>>0)


#define K_CP_REG_KEY_0                                                               0x18015834
#define K_CP_REG_KEY_1                                                               0x18015838
#define K_CP_REG_KEY_2                                                               0x1801583C
#define K_CP_REG_KEY_3                                                               0x18015840
#define K_CP_REG_KEY_0_reg_addr                                                      "0xB8015834"
#define K_CP_REG_KEY_1_reg_addr                                                      "0xB8015838"
#define K_CP_REG_KEY_2_reg_addr                                                      "0xB801583C"
#define K_CP_REG_KEY_3_reg_addr                                                      "0xB8015840"
#define K_CP_REG_KEY_0_reg                                                           0xB8015834
#define K_CP_REG_KEY_1_reg                                                           0xB8015838
#define K_CP_REG_KEY_2_reg                                                           0xB801583C
#define K_CP_REG_KEY_3_reg                                                           0xB8015840
#define set_K_CP_REG_KEY_0_reg(data)   (*((volatile unsigned int*) K_CP_REG_KEY_0_reg)=data)
#define set_K_CP_REG_KEY_1_reg(data)   (*((volatile unsigned int*) K_CP_REG_KEY_1_reg)=data)
#define set_K_CP_REG_KEY_2_reg(data)   (*((volatile unsigned int*) K_CP_REG_KEY_2_reg)=data)
#define set_K_CP_REG_KEY_3_reg(data)   (*((volatile unsigned int*) K_CP_REG_KEY_3_reg)=data)
#define get_K_CP_REG_KEY_0_reg   (*((volatile unsigned int*) K_CP_REG_KEY_0_reg))
#define get_K_CP_REG_KEY_1_reg   (*((volatile unsigned int*) K_CP_REG_KEY_1_reg))
#define get_K_CP_REG_KEY_2_reg   (*((volatile unsigned int*) K_CP_REG_KEY_2_reg))
#define get_K_CP_REG_KEY_3_reg   (*((volatile unsigned int*) K_CP_REG_KEY_3_reg))
#define K_CP_REG_KEY_0_inst_adr                                                      "0x000D"
#define K_CP_REG_KEY_1_inst_adr                                                      "0x000E"
#define K_CP_REG_KEY_2_inst_adr                                                      "0x000F"
#define K_CP_REG_KEY_3_inst_adr                                                      "0x0010"
#define K_CP_REG_KEY_0_inst                                                          0x000D
#define K_CP_REG_KEY_1_inst                                                          0x000E
#define K_CP_REG_KEY_2_inst                                                          0x000F
#define K_CP_REG_KEY_3_inst                                                          0x0010
#define K_CP_REG_KEY_data_shift                                                      (0)
#define K_CP_REG_KEY_data_mask                                                       (0xFFFFFFFF)
#define K_CP_REG_KEY_data(data)                                                      (0xFFFFFFFF&((data)<<0))
#define K_CP_REG_KEY_data_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define K_CP_REG_KEY_get_data(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define K_CP_REG_DATAIN_0                                                            0x18015844
#define K_CP_REG_DATAIN_1                                                            0x18015848
#define K_CP_REG_DATAIN_2                                                            0x1801584C
#define K_CP_REG_DATAIN_3                                                            0x18015850
#define K_CP_REG_DATAIN_0_reg_addr                                                   "0xB8015844"
#define K_CP_REG_DATAIN_1_reg_addr                                                   "0xB8015848"
#define K_CP_REG_DATAIN_2_reg_addr                                                   "0xB801584C"
#define K_CP_REG_DATAIN_3_reg_addr                                                   "0xB8015850"
#define K_CP_REG_DATAIN_0_reg                                                        0xB8015844
#define K_CP_REG_DATAIN_1_reg                                                        0xB8015848
#define K_CP_REG_DATAIN_2_reg                                                        0xB801584C
#define K_CP_REG_DATAIN_3_reg                                                        0xB8015850
#define set_K_CP_REG_DATAIN_0_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAIN_0_reg)=data)
#define set_K_CP_REG_DATAIN_1_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAIN_1_reg)=data)
#define set_K_CP_REG_DATAIN_2_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAIN_2_reg)=data)
#define set_K_CP_REG_DATAIN_3_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAIN_3_reg)=data)
#define get_K_CP_REG_DATAIN_0_reg   (*((volatile unsigned int*) K_CP_REG_DATAIN_0_reg))
#define get_K_CP_REG_DATAIN_1_reg   (*((volatile unsigned int*) K_CP_REG_DATAIN_1_reg))
#define get_K_CP_REG_DATAIN_2_reg   (*((volatile unsigned int*) K_CP_REG_DATAIN_2_reg))
#define get_K_CP_REG_DATAIN_3_reg   (*((volatile unsigned int*) K_CP_REG_DATAIN_3_reg))
#define K_CP_REG_DATAIN_0_inst_adr                                                   "0x0011"
#define K_CP_REG_DATAIN_1_inst_adr                                                   "0x0012"
#define K_CP_REG_DATAIN_2_inst_adr                                                   "0x0013"
#define K_CP_REG_DATAIN_3_inst_adr                                                   "0x0014"
#define K_CP_REG_DATAIN_0_inst                                                       0x0011
#define K_CP_REG_DATAIN_1_inst                                                       0x0012
#define K_CP_REG_DATAIN_2_inst                                                       0x0013
#define K_CP_REG_DATAIN_3_inst                                                       0x0014
#define K_CP_REG_DATAIN_data_shift                                                   (0)
#define K_CP_REG_DATAIN_data_mask                                                    (0xFFFFFFFF)
#define K_CP_REG_DATAIN_data(data)                                                   (0xFFFFFFFF&((data)<<0))
#define K_CP_REG_DATAIN_data_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define K_CP_REG_DATAIN_get_data(data)                                               ((0xFFFFFFFF&(data))>>0)


#define K_CP_REG_DATAOUT_0                                                           0x18015854
#define K_CP_REG_DATAOUT_1                                                           0x18015858
#define K_CP_REG_DATAOUT_2                                                           0x1801585C
#define K_CP_REG_DATAOUT_3                                                           0x18015860
#define K_CP_REG_DATAOUT_4                                                           0x18015864
#define K_CP_REG_DATAOUT_5                                                           0x18015868
#define K_CP_REG_DATAOUT_6                                                           0x1801586C
#define K_CP_REG_DATAOUT_7                                                           0x18015870
#define K_CP_REG_DATAOUT_0_reg_addr                                                  "0xB8015854"
#define K_CP_REG_DATAOUT_1_reg_addr                                                  "0xB8015858"
#define K_CP_REG_DATAOUT_2_reg_addr                                                  "0xB801585C"
#define K_CP_REG_DATAOUT_3_reg_addr                                                  "0xB8015860"
#define K_CP_REG_DATAOUT_4_reg_addr                                                  "0xB8015864"
#define K_CP_REG_DATAOUT_5_reg_addr                                                  "0xB8015868"
#define K_CP_REG_DATAOUT_6_reg_addr                                                  "0xB801586C"
#define K_CP_REG_DATAOUT_7_reg_addr                                                  "0xB8015870"
#define K_CP_REG_DATAOUT_0_reg                                                       0xB8015854
#define K_CP_REG_DATAOUT_1_reg                                                       0xB8015858
#define K_CP_REG_DATAOUT_2_reg                                                       0xB801585C
#define K_CP_REG_DATAOUT_3_reg                                                       0xB8015860
#define K_CP_REG_DATAOUT_4_reg                                                       0xB8015864
#define K_CP_REG_DATAOUT_5_reg                                                       0xB8015868
#define K_CP_REG_DATAOUT_6_reg                                                       0xB801586C
#define K_CP_REG_DATAOUT_7_reg                                                       0xB8015870
#define set_K_CP_REG_DATAOUT_0_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAOUT_0_reg)=data)
#define set_K_CP_REG_DATAOUT_1_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAOUT_1_reg)=data)
#define set_K_CP_REG_DATAOUT_2_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAOUT_2_reg)=data)
#define set_K_CP_REG_DATAOUT_3_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAOUT_3_reg)=data)
#define set_K_CP_REG_DATAOUT_4_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAOUT_4_reg)=data)
#define set_K_CP_REG_DATAOUT_5_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAOUT_5_reg)=data)
#define set_K_CP_REG_DATAOUT_6_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAOUT_6_reg)=data)
#define set_K_CP_REG_DATAOUT_7_reg(data)   (*((volatile unsigned int*) K_CP_REG_DATAOUT_7_reg)=data)
#define get_K_CP_REG_DATAOUT_0_reg   (*((volatile unsigned int*) K_CP_REG_DATAOUT_0_reg))
#define get_K_CP_REG_DATAOUT_1_reg   (*((volatile unsigned int*) K_CP_REG_DATAOUT_1_reg))
#define get_K_CP_REG_DATAOUT_2_reg   (*((volatile unsigned int*) K_CP_REG_DATAOUT_2_reg))
#define get_K_CP_REG_DATAOUT_3_reg   (*((volatile unsigned int*) K_CP_REG_DATAOUT_3_reg))
#define get_K_CP_REG_DATAOUT_4_reg   (*((volatile unsigned int*) K_CP_REG_DATAOUT_4_reg))
#define get_K_CP_REG_DATAOUT_5_reg   (*((volatile unsigned int*) K_CP_REG_DATAOUT_5_reg))
#define get_K_CP_REG_DATAOUT_6_reg   (*((volatile unsigned int*) K_CP_REG_DATAOUT_6_reg))
#define get_K_CP_REG_DATAOUT_7_reg   (*((volatile unsigned int*) K_CP_REG_DATAOUT_7_reg))
#define K_CP_REG_DATAOUT_0_inst_adr                                                  "0x0015"
#define K_CP_REG_DATAOUT_1_inst_adr                                                  "0x0016"
#define K_CP_REG_DATAOUT_2_inst_adr                                                  "0x0017"
#define K_CP_REG_DATAOUT_3_inst_adr                                                  "0x0018"
#define K_CP_REG_DATAOUT_4_inst_adr                                                  "0x0019"
#define K_CP_REG_DATAOUT_5_inst_adr                                                  "0x001A"
#define K_CP_REG_DATAOUT_6_inst_adr                                                  "0x001B"
#define K_CP_REG_DATAOUT_7_inst_adr                                                  "0x001C"
#define K_CP_REG_DATAOUT_0_inst                                                      0x0015
#define K_CP_REG_DATAOUT_1_inst                                                      0x0016
#define K_CP_REG_DATAOUT_2_inst                                                      0x0017
#define K_CP_REG_DATAOUT_3_inst                                                      0x0018
#define K_CP_REG_DATAOUT_4_inst                                                      0x0019
#define K_CP_REG_DATAOUT_5_inst                                                      0x001A
#define K_CP_REG_DATAOUT_6_inst                                                      0x001B
#define K_CP_REG_DATAOUT_7_inst                                                      0x001C
#define K_CP_REG_DATAOUT_data_shift                                                  (0)
#define K_CP_REG_DATAOUT_data_mask                                                   (0xFFFFFFFF)
#define K_CP_REG_DATAOUT_data(data)                                                  (0xFFFFFFFF&((data)<<0))
#define K_CP_REG_DATAOUT_data_src(data)                                              ((0xFFFFFFFF&(data))>>0)
#define K_CP_REG_DATAOUT_get_data(data)                                              ((0xFFFFFFFF&(data))>>0)


#define K_CP_REG_IV_0                                                                0x180158D0
#define K_CP_REG_IV_1                                                                0x180158D4
#define K_CP_REG_IV_2                                                                0x180158D8
#define K_CP_REG_IV_3                                                                0x180158DC
#define K_CP_REG_IV_4                                                                0x180158E0
#define K_CP_REG_IV_5                                                                0x180158E4
#define K_CP_REG_IV_6                                                                0x180158E8
#define K_CP_REG_IV_7                                                                0x180158EC
#define K_CP_REG_IV_0_reg_addr                                                       "0xB80158D0"
#define K_CP_REG_IV_1_reg_addr                                                       "0xB80158D4"
#define K_CP_REG_IV_2_reg_addr                                                       "0xB80158D8"
#define K_CP_REG_IV_3_reg_addr                                                       "0xB80158DC"
#define K_CP_REG_IV_4_reg_addr                                                       "0xB80158E0"
#define K_CP_REG_IV_5_reg_addr                                                       "0xB80158E4"
#define K_CP_REG_IV_6_reg_addr                                                       "0xB80158E8"
#define K_CP_REG_IV_7_reg_addr                                                       "0xB80158EC"
#define K_CP_REG_IV_0_reg                                                            0xB80158D0
#define K_CP_REG_IV_1_reg                                                            0xB80158D4
#define K_CP_REG_IV_2_reg                                                            0xB80158D8
#define K_CP_REG_IV_3_reg                                                            0xB80158DC
#define K_CP_REG_IV_4_reg                                                            0xB80158E0
#define K_CP_REG_IV_5_reg                                                            0xB80158E4
#define K_CP_REG_IV_6_reg                                                            0xB80158E8
#define K_CP_REG_IV_7_reg                                                            0xB80158EC
#define set_K_CP_REG_IV_0_reg(data)   (*((volatile unsigned int*) K_CP_REG_IV_0_reg)=data)
#define set_K_CP_REG_IV_1_reg(data)   (*((volatile unsigned int*) K_CP_REG_IV_1_reg)=data)
#define set_K_CP_REG_IV_2_reg(data)   (*((volatile unsigned int*) K_CP_REG_IV_2_reg)=data)
#define set_K_CP_REG_IV_3_reg(data)   (*((volatile unsigned int*) K_CP_REG_IV_3_reg)=data)
#define set_K_CP_REG_IV_4_reg(data)   (*((volatile unsigned int*) K_CP_REG_IV_4_reg)=data)
#define set_K_CP_REG_IV_5_reg(data)   (*((volatile unsigned int*) K_CP_REG_IV_5_reg)=data)
#define set_K_CP_REG_IV_6_reg(data)   (*((volatile unsigned int*) K_CP_REG_IV_6_reg)=data)
#define set_K_CP_REG_IV_7_reg(data)   (*((volatile unsigned int*) K_CP_REG_IV_7_reg)=data)
#define get_K_CP_REG_IV_0_reg   (*((volatile unsigned int*) K_CP_REG_IV_0_reg))
#define get_K_CP_REG_IV_1_reg   (*((volatile unsigned int*) K_CP_REG_IV_1_reg))
#define get_K_CP_REG_IV_2_reg   (*((volatile unsigned int*) K_CP_REG_IV_2_reg))
#define get_K_CP_REG_IV_3_reg   (*((volatile unsigned int*) K_CP_REG_IV_3_reg))
#define get_K_CP_REG_IV_4_reg   (*((volatile unsigned int*) K_CP_REG_IV_4_reg))
#define get_K_CP_REG_IV_5_reg   (*((volatile unsigned int*) K_CP_REG_IV_5_reg))
#define get_K_CP_REG_IV_6_reg   (*((volatile unsigned int*) K_CP_REG_IV_6_reg))
#define get_K_CP_REG_IV_7_reg   (*((volatile unsigned int*) K_CP_REG_IV_7_reg))
#define K_CP_REG_IV_0_inst_adr                                                       "0x0034"
#define K_CP_REG_IV_1_inst_adr                                                       "0x0035"
#define K_CP_REG_IV_2_inst_adr                                                       "0x0036"
#define K_CP_REG_IV_3_inst_adr                                                       "0x0037"
#define K_CP_REG_IV_4_inst_adr                                                       "0x0038"
#define K_CP_REG_IV_5_inst_adr                                                       "0x0039"
#define K_CP_REG_IV_6_inst_adr                                                       "0x003A"
#define K_CP_REG_IV_7_inst_adr                                                       "0x003B"
#define K_CP_REG_IV_0_inst                                                           0x0034
#define K_CP_REG_IV_1_inst                                                           0x0035
#define K_CP_REG_IV_2_inst                                                           0x0036
#define K_CP_REG_IV_3_inst                                                           0x0037
#define K_CP_REG_IV_4_inst                                                           0x0038
#define K_CP_REG_IV_5_inst                                                           0x0039
#define K_CP_REG_IV_6_inst                                                           0x003A
#define K_CP_REG_IV_7_inst                                                           0x003B
#define K_CP_REG_IV_data_shift                                                       (0)
#define K_CP_REG_IV_data_mask                                                        (0xFFFFFFFF)
#define K_CP_REG_IV_data(data)                                                       (0xFFFFFFFF&((data)<<0))
#define K_CP_REG_IV_data_src(data)                                                   ((0xFFFFFFFF&(data))>>0)
#define K_CP_REG_IV_get_data(data)                                                   ((0xFFFFFFFF&(data))>>0)


#define K_CP_REG_SET                                                                 0x18015874
#define K_CP_REG_SET_reg_addr                                                        "0xB8015874"
#define K_CP_REG_SET_reg                                                             0xB8015874
#define set_K_CP_REG_SET_reg(data)   (*((volatile unsigned int*) K_CP_REG_SET_reg)=data)
#define get_K_CP_REG_SET_reg   (*((volatile unsigned int*) K_CP_REG_SET_reg))
#define K_CP_REG_SET_inst_adr                                                        "0x001D"
#define K_CP_REG_SET_inst                                                            0x001D
#define K_CP_REG_SET_write_enable5_shift                                             (17)
#define K_CP_REG_SET_write_enable5_mask                                              (0x00020000)
#define K_CP_REG_SET_write_enable5(data)                                             (0x00020000&((data)<<17))
#define K_CP_REG_SET_write_enable5_src(data)                                         ((0x00020000&(data))>>17)
#define K_CP_REG_SET_get_write_enable5(data)                                         ((0x00020000&(data))>>17)
#define K_CP_REG_SET_mode_shift                                                      (13)
#define K_CP_REG_SET_mode_mask                                                       (0x0001E000)
#define K_CP_REG_SET_mode(data)                                                      (0x0001E000&((data)<<13))
#define K_CP_REG_SET_mode_src(data)                                                  ((0x0001E000&(data))>>13)
#define K_CP_REG_SET_get_mode(data)                                                  ((0x0001E000&(data))>>13)
#define K_CP_REG_SET_write_enable4_shift                                             (11)
#define K_CP_REG_SET_write_enable4_mask                                              (0x00000800)
#define K_CP_REG_SET_write_enable4(data)                                             (0x00000800&((data)<<11))
#define K_CP_REG_SET_write_enable4_src(data)                                         ((0x00000800&(data))>>11)
#define K_CP_REG_SET_get_write_enable4(data)                                         ((0x00000800&(data))>>11)
#define K_CP_REG_SET_endian_swap_shift                                               (10)
#define K_CP_REG_SET_endian_swap_mask                                                (0x00000400)
#define K_CP_REG_SET_endian_swap(data)                                               (0x00000400&((data)<<10))
#define K_CP_REG_SET_endian_swap_src(data)                                           ((0x00000400&(data))>>10)
#define K_CP_REG_SET_get_endian_swap(data)                                           ((0x00000400&(data))>>10)
#define K_CP_REG_SET_write_enable3_shift                                             (9)
#define K_CP_REG_SET_write_enable3_mask                                              (0x00000200)
#define K_CP_REG_SET_write_enable3(data)                                             (0x00000200&((data)<<9))
#define K_CP_REG_SET_write_enable3_src(data)                                         ((0x00000200&(data))>>9)
#define K_CP_REG_SET_get_write_enable3(data)                                         ((0x00000200&(data))>>9)
#define K_CP_REG_SET_cw_logic_opsel_shift                                            (7)
#define K_CP_REG_SET_cw_logic_opsel_mask                                             (0x00000180)
#define K_CP_REG_SET_cw_logic_opsel(data)                                            (0x00000180&((data)<<7))
#define K_CP_REG_SET_cw_logic_opsel_src(data)                                        ((0x00000180&(data))>>7)
#define K_CP_REG_SET_get_cw_logic_opsel(data)                                        ((0x00000180&(data))>>7)
#define K_CP_REG_SET_write_enable2_shift                                             (6)
#define K_CP_REG_SET_write_enable2_mask                                              (0x00000040)
#define K_CP_REG_SET_write_enable2(data)                                             (0x00000040&((data)<<6))
#define K_CP_REG_SET_write_enable2_src(data)                                         ((0x00000040&(data))>>6)
#define K_CP_REG_SET_get_write_enable2(data)                                         ((0x00000040&(data))>>6)
#define K_CP_REG_SET_bcm_shift                                                       (4)
#define K_CP_REG_SET_bcm_mask                                                        (0x00000030)
#define K_CP_REG_SET_bcm(data)                                                       (0x00000030&((data)<<4))
#define K_CP_REG_SET_bcm_src(data)                                                   ((0x00000030&(data))>>4)
#define K_CP_REG_SET_get_bcm(data)                                                   ((0x00000030&(data))>>4)
#define K_CP_REG_SET_write_enable1_shift                                             (3)
#define K_CP_REG_SET_write_enable1_mask                                              (0x00000008)
#define K_CP_REG_SET_write_enable1(data)                                             (0x00000008&((data)<<3))
#define K_CP_REG_SET_write_enable1_src(data)                                         ((0x00000008&(data))>>3)
#define K_CP_REG_SET_get_write_enable1(data)                                         ((0x00000008&(data))>>3)
#define K_CP_REG_SET_reg_first_shift                                                 (2)
#define K_CP_REG_SET_reg_first_mask                                                  (0x00000004)
#define K_CP_REG_SET_reg_first(data)                                                 (0x00000004&((data)<<2))
#define K_CP_REG_SET_reg_first_src(data)                                             ((0x00000004&(data))>>2)
#define K_CP_REG_SET_get_reg_first(data)                                             ((0x00000004&(data))>>2)
#define K_CP_REG_SET_write_enable0_shift                                             (1)
#define K_CP_REG_SET_write_enable0_mask                                              (0x00000002)
#define K_CP_REG_SET_write_enable0(data)                                             (0x00000002&((data)<<1))
#define K_CP_REG_SET_write_enable0_src(data)                                         ((0x00000002&(data))>>1)
#define K_CP_REG_SET_get_write_enable0(data)                                         ((0x00000002&(data))>>1)
#define K_CP_REG_SET_reg_ende_shift                                                  (0)
#define K_CP_REG_SET_reg_ende_mask                                                   (0x00000001)
#define K_CP_REG_SET_reg_ende(data)                                                  (0x00000001&((data)<<0))
#define K_CP_REG_SET_reg_ende_src(data)                                              ((0x00000001&(data))>>0)
#define K_CP_REG_SET_get_reg_ende(data)                                              ((0x00000001&(data))>>0)


#define K_CP_REG_SET1                                                                0x18015878
#define K_CP_REG_SET1_reg_addr                                                       "0xB8015878"
#define K_CP_REG_SET1_reg                                                            0xB8015878
#define set_K_CP_REG_SET1_reg(data)   (*((volatile unsigned int*) K_CP_REG_SET1_reg)=data)
#define get_K_CP_REG_SET1_reg   (*((volatile unsigned int*) K_CP_REG_SET1_reg))
#define K_CP_REG_SET1_inst_adr                                                       "0x001E"
#define K_CP_REG_SET1_inst                                                           0x001E
#define K_CP_REG_SET1_des_key_order_shift                                            (9)
#define K_CP_REG_SET1_des_key_order_mask                                             (0x00000200)
#define K_CP_REG_SET1_des_key_order(data)                                            (0x00000200&((data)<<9))
#define K_CP_REG_SET1_des_key_order_src(data)                                        ((0x00000200&(data))>>9)
#define K_CP_REG_SET1_get_des_key_order(data)                                        ((0x00000200&(data))>>9)
#define K_CP_REG_SET1_key_mode_shift                                                 (6)
#define K_CP_REG_SET1_key_mode_mask                                                  (0x000001C0)
#define K_CP_REG_SET1_key_mode(data)                                                 (0x000001C0&((data)<<6))
#define K_CP_REG_SET1_key_mode_src(data)                                             ((0x000001C0&(data))>>6)
#define K_CP_REG_SET1_get_key_mode(data)                                             ((0x000001C0&(data))>>6)
#define K_CP_REG_SET1_iv_mode_shift                                                  (4)
#define K_CP_REG_SET1_iv_mode_mask                                                   (0x00000030)
#define K_CP_REG_SET1_iv_mode(data)                                                  (0x00000030&((data)<<4))
#define K_CP_REG_SET1_iv_mode_src(data)                                              ((0x00000030&(data))>>4)
#define K_CP_REG_SET1_get_iv_mode(data)                                              ((0x00000030&(data))>>4)
#define K_CP_REG_SET1_input_mode_shift                                               (2)
#define K_CP_REG_SET1_input_mode_mask                                                (0x0000000C)
#define K_CP_REG_SET1_input_mode(data)                                               (0x0000000C&((data)<<2))
#define K_CP_REG_SET1_input_mode_src(data)                                           ((0x0000000C&(data))>>2)
#define K_CP_REG_SET1_get_input_mode(data)                                           ((0x0000000C&(data))>>2)
#define K_CP_REG_SET1_output_mode_shift                                              (0)
#define K_CP_REG_SET1_output_mode_mask                                               (0x00000003)
#define K_CP_REG_SET1_output_mode(data)                                              (0x00000003&((data)<<0))
#define K_CP_REG_SET1_output_mode_src(data)                                          ((0x00000003&(data))>>0)
#define K_CP_REG_SET1_get_output_mode(data)                                          ((0x00000003&(data))>>0)


#define K_CP_REG_SET2                                                                0x1801587c
#define K_CP_REG_SET2_reg_addr                                                       "0xB801587C"
#define K_CP_REG_SET2_reg                                                            0xB801587C
#define set_K_CP_REG_SET2_reg(data)   (*((volatile unsigned int*) K_CP_REG_SET2_reg)=data)
#define get_K_CP_REG_SET2_reg   (*((volatile unsigned int*) K_CP_REG_SET2_reg))
#define K_CP_REG_SET2_inst_adr                                                       "0x001F"
#define K_CP_REG_SET2_inst                                                           0x001F
#define K_CP_REG_SET2_output_entry_shift                                             (24)
#define K_CP_REG_SET2_output_entry_mask                                              (0x7F000000)
#define K_CP_REG_SET2_output_entry(data)                                             (0x7F000000&((data)<<24))
#define K_CP_REG_SET2_output_entry_src(data)                                         ((0x7F000000&(data))>>24)
#define K_CP_REG_SET2_get_output_entry(data)                                         ((0x7F000000&(data))>>24)
#define K_CP_REG_SET2_input_entry_shift                                              (16)
#define K_CP_REG_SET2_input_entry_mask                                               (0x007F0000)
#define K_CP_REG_SET2_input_entry(data)                                              (0x007F0000&((data)<<16))
#define K_CP_REG_SET2_input_entry_src(data)                                          ((0x007F0000&(data))>>16)
#define K_CP_REG_SET2_get_input_entry(data)                                          ((0x007F0000&(data))>>16)
#define K_CP_REG_SET2_key_entry_shift                                                (8)
#define K_CP_REG_SET2_key_entry_mask                                                 (0x00007F00)
#define K_CP_REG_SET2_key_entry(data)                                                (0x00007F00&((data)<<8))
#define K_CP_REG_SET2_key_entry_src(data)                                            ((0x00007F00&(data))>>8)
#define K_CP_REG_SET2_get_key_entry(data)                                            ((0x00007F00&(data))>>8)
#define K_CP_REG_SET2_iv_entry_shift                                                 (0)
#define K_CP_REG_SET2_iv_entry_mask                                                  (0x0000007F)
#define K_CP_REG_SET2_iv_entry(data)                                                 (0x0000007F&((data)<<0))
#define K_CP_REG_SET2_iv_entry_src(data)                                             ((0x0000007F&(data))>>0)
#define K_CP_REG_SET2_get_iv_entry(data)                                             ((0x0000007F&(data))>>0)


#define K_CP_NF_KEY_0                                                                0x18015884
#define K_CP_NF_KEY_1                                                                0x18015888
#define K_CP_NF_KEY_2                                                                0x1801588C
#define K_CP_NF_KEY_3                                                                0x18015890
#define K_CP_NF_KEY_0_reg_addr                                                       "0xB8015884"
#define K_CP_NF_KEY_1_reg_addr                                                       "0xB8015888"
#define K_CP_NF_KEY_2_reg_addr                                                       "0xB801588C"
#define K_CP_NF_KEY_3_reg_addr                                                       "0xB8015890"
#define K_CP_NF_KEY_0_reg                                                            0xB8015884
#define K_CP_NF_KEY_1_reg                                                            0xB8015888
#define K_CP_NF_KEY_2_reg                                                            0xB801588C
#define K_CP_NF_KEY_3_reg                                                            0xB8015890
#define set_K_CP_NF_KEY_0_reg(data)   (*((volatile unsigned int*) K_CP_NF_KEY_0_reg)=data)
#define set_K_CP_NF_KEY_1_reg(data)   (*((volatile unsigned int*) K_CP_NF_KEY_1_reg)=data)
#define set_K_CP_NF_KEY_2_reg(data)   (*((volatile unsigned int*) K_CP_NF_KEY_2_reg)=data)
#define set_K_CP_NF_KEY_3_reg(data)   (*((volatile unsigned int*) K_CP_NF_KEY_3_reg)=data)
#define get_K_CP_NF_KEY_0_reg   (*((volatile unsigned int*) K_CP_NF_KEY_0_reg))
#define get_K_CP_NF_KEY_1_reg   (*((volatile unsigned int*) K_CP_NF_KEY_1_reg))
#define get_K_CP_NF_KEY_2_reg   (*((volatile unsigned int*) K_CP_NF_KEY_2_reg))
#define get_K_CP_NF_KEY_3_reg   (*((volatile unsigned int*) K_CP_NF_KEY_3_reg))
#define K_CP_NF_KEY_0_inst_adr                                                       "0x0021"
#define K_CP_NF_KEY_1_inst_adr                                                       "0x0022"
#define K_CP_NF_KEY_2_inst_adr                                                       "0x0023"
#define K_CP_NF_KEY_3_inst_adr                                                       "0x0024"
#define K_CP_NF_KEY_0_inst                                                           0x0021
#define K_CP_NF_KEY_1_inst                                                           0x0022
#define K_CP_NF_KEY_2_inst                                                           0x0023
#define K_CP_NF_KEY_3_inst                                                           0x0024
#define K_CP_NF_KEY_data_shift                                                       (0)
#define K_CP_NF_KEY_data_mask                                                        (0xFFFFFFFF)
#define K_CP_NF_KEY_data(data)                                                       (0xFFFFFFFF&((data)<<0))
#define K_CP_NF_KEY_data_src(data)                                                   ((0xFFFFFFFF&(data))>>0)
#define K_CP_NF_KEY_get_data(data)                                                   ((0xFFFFFFFF&(data))>>0)


#define K_CP_NF_INI_KEY_0                                                            0x18015894
#define K_CP_NF_INI_KEY_1                                                            0x18015898
#define K_CP_NF_INI_KEY_2                                                            0x1801589C
#define K_CP_NF_INI_KEY_3                                                            0x180158A0
#define K_CP_NF_INI_KEY_0_reg_addr                                                   "0xB8015894"
#define K_CP_NF_INI_KEY_1_reg_addr                                                   "0xB8015898"
#define K_CP_NF_INI_KEY_2_reg_addr                                                   "0xB801589C"
#define K_CP_NF_INI_KEY_3_reg_addr                                                   "0xB80158A0"
#define K_CP_NF_INI_KEY_0_reg                                                        0xB8015894
#define K_CP_NF_INI_KEY_1_reg                                                        0xB8015898
#define K_CP_NF_INI_KEY_2_reg                                                        0xB801589C
#define K_CP_NF_INI_KEY_3_reg                                                        0xB80158A0
#define set_K_CP_NF_INI_KEY_0_reg(data)   (*((volatile unsigned int*) K_CP_NF_INI_KEY_0_reg)=data)
#define set_K_CP_NF_INI_KEY_1_reg(data)   (*((volatile unsigned int*) K_CP_NF_INI_KEY_1_reg)=data)
#define set_K_CP_NF_INI_KEY_2_reg(data)   (*((volatile unsigned int*) K_CP_NF_INI_KEY_2_reg)=data)
#define set_K_CP_NF_INI_KEY_3_reg(data)   (*((volatile unsigned int*) K_CP_NF_INI_KEY_3_reg)=data)
#define get_K_CP_NF_INI_KEY_0_reg   (*((volatile unsigned int*) K_CP_NF_INI_KEY_0_reg))
#define get_K_CP_NF_INI_KEY_1_reg   (*((volatile unsigned int*) K_CP_NF_INI_KEY_1_reg))
#define get_K_CP_NF_INI_KEY_2_reg   (*((volatile unsigned int*) K_CP_NF_INI_KEY_2_reg))
#define get_K_CP_NF_INI_KEY_3_reg   (*((volatile unsigned int*) K_CP_NF_INI_KEY_3_reg))
#define K_CP_NF_INI_KEY_0_inst_adr                                                   "0x0025"
#define K_CP_NF_INI_KEY_1_inst_adr                                                   "0x0026"
#define K_CP_NF_INI_KEY_2_inst_adr                                                   "0x0027"
#define K_CP_NF_INI_KEY_3_inst_adr                                                   "0x0028"
#define K_CP_NF_INI_KEY_0_inst                                                       0x0025
#define K_CP_NF_INI_KEY_1_inst                                                       0x0026
#define K_CP_NF_INI_KEY_2_inst                                                       0x0027
#define K_CP_NF_INI_KEY_3_inst                                                       0x0028
#define K_CP_NF_INI_KEY_data_shift                                                   (0)
#define K_CP_NF_INI_KEY_data_mask                                                    (0xFFFFFFFF)
#define K_CP_NF_INI_KEY_data(data)                                                   (0xFFFFFFFF&((data)<<0))
#define K_CP_NF_INI_KEY_data_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define K_CP_NF_INI_KEY_get_data(data)                                               ((0xFFFFFFFF&(data))>>0)


#define K_CP_NF_SET                                                                  0x180158a4
#define K_CP_NF_SET_reg_addr                                                         "0xB80158A4"
#define K_CP_NF_SET_reg                                                              0xB80158A4
#define set_K_CP_NF_SET_reg(data)   (*((volatile unsigned int*) K_CP_NF_SET_reg)=data)
#define get_K_CP_NF_SET_reg   (*((volatile unsigned int*) K_CP_NF_SET_reg))
#define K_CP_NF_SET_inst_adr                                                         "0x0029"
#define K_CP_NF_SET_inst                                                             0x0029
#define K_CP_NF_SET_bcm_shift                                                        (9)
#define K_CP_NF_SET_bcm_mask                                                         (0x00000600)
#define K_CP_NF_SET_bcm(data)                                                        (0x00000600&((data)<<9))
#define K_CP_NF_SET_bcm_src(data)                                                    ((0x00000600&(data))>>9)
#define K_CP_NF_SET_get_bcm(data)                                                    ((0x00000600&(data))>>9)
#define K_CP_NF_SET_cw_entry_shift                                                   (2)
#define K_CP_NF_SET_cw_entry_mask                                                    (0x000001FC)
#define K_CP_NF_SET_cw_entry(data)                                                   (0x000001FC&((data)<<2))
#define K_CP_NF_SET_cw_entry_src(data)                                               ((0x000001FC&(data))>>2)
#define K_CP_NF_SET_get_cw_entry(data)                                               ((0x000001FC&(data))>>2)
#define K_CP_NF_SET_sel_shift                                                        (0)
#define K_CP_NF_SET_sel_mask                                                         (0x00000003)
#define K_CP_NF_SET_sel(data)                                                        (0x00000003&((data)<<0))
#define K_CP_NF_SET_sel_src(data)                                                    ((0x00000003&(data))>>0)
#define K_CP_NF_SET_get_sel(data)                                                    ((0x00000003&(data))>>0)


#define K_CP_MD_KEY_0                                                                0x180158A8
#define K_CP_MD_KEY_1                                                                0x180158AC
#define K_CP_MD_KEY_2                                                                0x180158B0
#define K_CP_MD_KEY_3                                                                0x180158B4
#define K_CP_MD_KEY_0_reg_addr                                                       "0xB80158A8"
#define K_CP_MD_KEY_1_reg_addr                                                       "0xB80158AC"
#define K_CP_MD_KEY_2_reg_addr                                                       "0xB80158B0"
#define K_CP_MD_KEY_3_reg_addr                                                       "0xB80158B4"
#define K_CP_MD_KEY_0_reg                                                            0xB80158A8
#define K_CP_MD_KEY_1_reg                                                            0xB80158AC
#define K_CP_MD_KEY_2_reg                                                            0xB80158B0
#define K_CP_MD_KEY_3_reg                                                            0xB80158B4
#define set_K_CP_MD_KEY_0_reg(data)   (*((volatile unsigned int*) K_CP_MD_KEY_0_reg)=data)
#define set_K_CP_MD_KEY_1_reg(data)   (*((volatile unsigned int*) K_CP_MD_KEY_1_reg)=data)
#define set_K_CP_MD_KEY_2_reg(data)   (*((volatile unsigned int*) K_CP_MD_KEY_2_reg)=data)
#define set_K_CP_MD_KEY_3_reg(data)   (*((volatile unsigned int*) K_CP_MD_KEY_3_reg)=data)
#define get_K_CP_MD_KEY_0_reg   (*((volatile unsigned int*) K_CP_MD_KEY_0_reg))
#define get_K_CP_MD_KEY_1_reg   (*((volatile unsigned int*) K_CP_MD_KEY_1_reg))
#define get_K_CP_MD_KEY_2_reg   (*((volatile unsigned int*) K_CP_MD_KEY_2_reg))
#define get_K_CP_MD_KEY_3_reg   (*((volatile unsigned int*) K_CP_MD_KEY_3_reg))
#define K_CP_MD_KEY_0_inst_adr                                                       "0x002A"
#define K_CP_MD_KEY_1_inst_adr                                                       "0x002B"
#define K_CP_MD_KEY_2_inst_adr                                                       "0x002C"
#define K_CP_MD_KEY_3_inst_adr                                                       "0x002D"
#define K_CP_MD_KEY_0_inst                                                           0x002A
#define K_CP_MD_KEY_1_inst                                                           0x002B
#define K_CP_MD_KEY_2_inst                                                           0x002C
#define K_CP_MD_KEY_3_inst                                                           0x002D
#define K_CP_MD_KEY_data_shift                                                       (0)
#define K_CP_MD_KEY_data_mask                                                        (0xFFFFFFFF)
#define K_CP_MD_KEY_data(data)                                                       (0xFFFFFFFF&((data)<<0))
#define K_CP_MD_KEY_data_src(data)                                                   ((0xFFFFFFFF&(data))>>0)
#define K_CP_MD_KEY_get_data(data)                                                   ((0xFFFFFFFF&(data))>>0)


#define K_CP_MD_INI_KEY_0                                                            0x180158B8
#define K_CP_MD_INI_KEY_1                                                            0x180158BC
#define K_CP_MD_INI_KEY_2                                                            0x180158C0
#define K_CP_MD_INI_KEY_3                                                            0x180158C4
#define K_CP_MD_INI_KEY_0_reg_addr                                                   "0xB80158B8"
#define K_CP_MD_INI_KEY_1_reg_addr                                                   "0xB80158BC"
#define K_CP_MD_INI_KEY_2_reg_addr                                                   "0xB80158C0"
#define K_CP_MD_INI_KEY_3_reg_addr                                                   "0xB80158C4"
#define K_CP_MD_INI_KEY_0_reg                                                        0xB80158B8
#define K_CP_MD_INI_KEY_1_reg                                                        0xB80158BC
#define K_CP_MD_INI_KEY_2_reg                                                        0xB80158C0
#define K_CP_MD_INI_KEY_3_reg                                                        0xB80158C4
#define set_K_CP_MD_INI_KEY_0_reg(data)   (*((volatile unsigned int*) K_CP_MD_INI_KEY_0_reg)=data)
#define set_K_CP_MD_INI_KEY_1_reg(data)   (*((volatile unsigned int*) K_CP_MD_INI_KEY_1_reg)=data)
#define set_K_CP_MD_INI_KEY_2_reg(data)   (*((volatile unsigned int*) K_CP_MD_INI_KEY_2_reg)=data)
#define set_K_CP_MD_INI_KEY_3_reg(data)   (*((volatile unsigned int*) K_CP_MD_INI_KEY_3_reg)=data)
#define get_K_CP_MD_INI_KEY_0_reg   (*((volatile unsigned int*) K_CP_MD_INI_KEY_0_reg))
#define get_K_CP_MD_INI_KEY_1_reg   (*((volatile unsigned int*) K_CP_MD_INI_KEY_1_reg))
#define get_K_CP_MD_INI_KEY_2_reg   (*((volatile unsigned int*) K_CP_MD_INI_KEY_2_reg))
#define get_K_CP_MD_INI_KEY_3_reg   (*((volatile unsigned int*) K_CP_MD_INI_KEY_3_reg))
#define K_CP_MD_INI_KEY_0_inst_adr                                                   "0x002E"
#define K_CP_MD_INI_KEY_1_inst_adr                                                   "0x002F"
#define K_CP_MD_INI_KEY_2_inst_adr                                                   "0x0030"
#define K_CP_MD_INI_KEY_3_inst_adr                                                   "0x0031"
#define K_CP_MD_INI_KEY_0_inst                                                       0x002E
#define K_CP_MD_INI_KEY_1_inst                                                       0x002F
#define K_CP_MD_INI_KEY_2_inst                                                       0x0030
#define K_CP_MD_INI_KEY_3_inst                                                       0x0031
#define K_CP_MD_INI_KEY_data_shift                                                   (0)
#define K_CP_MD_INI_KEY_data_mask                                                    (0xFFFFFFFF)
#define K_CP_MD_INI_KEY_data(data)                                                   (0xFFFFFFFF&((data)<<0))
#define K_CP_MD_INI_KEY_data_src(data)                                               ((0xFFFFFFFF&(data))>>0)
#define K_CP_MD_INI_KEY_get_data(data)                                               ((0xFFFFFFFF&(data))>>0)


#define K_CP_MD_SET                                                                  0x180158c8
#define K_CP_MD_SET_reg_addr                                                         "0xB80158C8"
#define K_CP_MD_SET_reg                                                              0xB80158C8
#define set_K_CP_MD_SET_reg(data)   (*((volatile unsigned int*) K_CP_MD_SET_reg)=data)
#define get_K_CP_MD_SET_reg   (*((volatile unsigned int*) K_CP_MD_SET_reg))
#define K_CP_MD_SET_inst_adr                                                         "0x0032"
#define K_CP_MD_SET_inst                                                             0x0032
#define K_CP_MD_SET_bcm_shift                                                        (9)
#define K_CP_MD_SET_bcm_mask                                                         (0x00000600)
#define K_CP_MD_SET_bcm(data)                                                        (0x00000600&((data)<<9))
#define K_CP_MD_SET_bcm_src(data)                                                    ((0x00000600&(data))>>9)
#define K_CP_MD_SET_get_bcm(data)                                                    ((0x00000600&(data))>>9)
#define K_CP_MD_SET_cw_entry_shift                                                   (2)
#define K_CP_MD_SET_cw_entry_mask                                                    (0x000001FC)
#define K_CP_MD_SET_cw_entry(data)                                                   (0x000001FC&((data)<<2))
#define K_CP_MD_SET_cw_entry_src(data)                                               ((0x000001FC&(data))>>2)
#define K_CP_MD_SET_get_cw_entry(data)                                               ((0x000001FC&(data))>>2)
#define K_CP_MD_SET_sel_shift                                                        (0)
#define K_CP_MD_SET_sel_mask                                                         (0x00000003)
#define K_CP_MD_SET_sel(data)                                                        (0x00000003&((data)<<0))
#define K_CP_MD_SET_sel_src(data)                                                    ((0x00000003&(data))>>0)
#define K_CP_MD_SET_get_sel(data)                                                    ((0x00000003&(data))>>0)


#define CP_DBG                                                                       0x180150cc
#define CP_DBG_reg_addr                                                              "0xB80150CC"
#define CP_DBG_reg                                                                   0xB80150CC
#define set_CP_DBG_reg(data)   (*((volatile unsigned int*) CP_DBG_reg)=data)
#define get_CP_DBG_reg   (*((volatile unsigned int*) CP_DBG_reg))
#define CP_DBG_inst_adr                                                              "0x0033"
#define CP_DBG_inst                                                                  0x0033
#define CP_DBG_dbg_sel1_shift                                                        (6)
#define CP_DBG_dbg_sel1_mask                                                         (0x000007C0)
#define CP_DBG_dbg_sel1(data)                                                        (0x000007C0&((data)<<6))
#define CP_DBG_dbg_sel1_src(data)                                                    ((0x000007C0&(data))>>6)
#define CP_DBG_get_dbg_sel1(data)                                                    ((0x000007C0&(data))>>6)
#define CP_DBG_dbg_sel0_shift                                                        (1)
#define CP_DBG_dbg_sel0_mask                                                         (0x0000003E)
#define CP_DBG_dbg_sel0(data)                                                        (0x0000003E&((data)<<1))
#define CP_DBG_dbg_sel0_src(data)                                                    ((0x0000003E&(data))>>1)
#define CP_DBG_get_dbg_sel0(data)                                                    ((0x0000003E&(data))>>1)
#define CP_DBG_dbg_en_shift                                                          (0)
#define CP_DBG_dbg_en_mask                                                           (0x00000001)
#define CP_DBG_dbg_en(data)                                                          (0x00000001&((data)<<0))
#define CP_DBG_dbg_en_src(data)                                                      ((0x00000001&(data))>>0)
#define CP_DBG_get_dbg_en(data)                                                      ((0x00000001&(data))>>0)


#define K_CP_STATUS                                                                  0x180158F0
#define K_CP_STATUS_reg_addr                                                         "0xB80158F0"
#define K_CP_STATUS_reg                                                              0xB80158F0
#define set_K_CP_STATUS_reg(data)   (*((volatile unsigned int*) K_CP_STATUS_reg)=data)
#define get_K_CP_STATUS_reg   (*((volatile unsigned int*) K_CP_STATUS_reg))
#define K_CP_STATUS_inst_adr                                                         "0x003C"
#define K_CP_STATUS_inst                                                             0x003C
#define K_CP_STATUS_scpu_illegal_access_shift                                        (0)
#define K_CP_STATUS_scpu_illegal_access_mask                                         (0x00000001)
#define K_CP_STATUS_scpu_illegal_access(data)                                        (0x00000001&((data)<<0))
#define K_CP_STATUS_scpu_illegal_access_src(data)                                    ((0x00000001&(data))>>0)
#define K_CP_STATUS_get_scpu_illegal_access(data)                                    ((0x00000001&(data))>>0)


#define K_CP_EN                                                                      0x180158F4
#define K_CP_EN_reg_addr                                                             "0xB80158F4"
#define K_CP_EN_reg                                                                  0xB80158F4
#define set_K_CP_EN_reg(data)   (*((volatile unsigned int*) K_CP_EN_reg)=data)
#define get_K_CP_EN_reg   (*((volatile unsigned int*) K_CP_EN_reg))
#define K_CP_EN_inst_adr                                                             "0x003D"
#define K_CP_EN_inst                                                                 0x003D
#define K_CP_EN_scpu_illegal_access_en_shift                                         (0)
#define K_CP_EN_scpu_illegal_access_en_mask                                          (0x00000001)
#define K_CP_EN_scpu_illegal_access_en(data)                                         (0x00000001&((data)<<0))
#define K_CP_EN_scpu_illegal_access_en_src(data)                                     ((0x00000001&(data))>>0)
#define K_CP_EN_get_scpu_illegal_access_en(data)                                     ((0x00000001&(data))>>0)


#define CP_TST1                                                                      0x180150F0
#define CP_TST1_reg_addr                                                             "0xB80150F0"
#define CP_TST1_reg                                                                  0xB80150F0
#define set_CP_TST1_reg(data)   (*((volatile unsigned int*) CP_TST1_reg)=data)
#define get_CP_TST1_reg   (*((volatile unsigned int*) CP_TST1_reg))
#define CP_TST1_inst_adr                                                             "0x003C"
#define CP_TST1_inst                                                                 0x003C
#define CP_TST1_tst_sel1_shift                                                       (6)
#define CP_TST1_tst_sel1_mask                                                        (0x000007C0)
#define CP_TST1_tst_sel1(data)                                                       (0x000007C0&((data)<<6))
#define CP_TST1_tst_sel1_src(data)                                                   ((0x000007C0&(data))>>6)
#define CP_TST1_get_tst_sel1(data)                                                   ((0x000007C0&(data))>>6)
#define CP_TST1_tst_sel0_shift                                                       (1)
#define CP_TST1_tst_sel0_mask                                                        (0x0000003E)
#define CP_TST1_tst_sel0(data)                                                       (0x0000003E&((data)<<1))
#define CP_TST1_tst_sel0_src(data)                                                   ((0x0000003E&(data))>>1)
#define CP_TST1_get_tst_sel0(data)                                                   ((0x0000003E&(data))>>1)
#define CP_TST1_tst_en_shift                                                         (0)
#define CP_TST1_tst_en_mask                                                          (0x00000001)
#define CP_TST1_tst_en(data)                                                         (0x00000001&((data)<<0))
#define CP_TST1_tst_en_src(data)                                                     ((0x00000001&(data))>>0)
#define CP_TST1_get_tst_en(data)                                                     ((0x00000001&(data))>>0)


#define CP_TST2                                                                      0x180150F4
#define CP_TST2_reg_addr                                                             "0xB80150F4"
#define CP_TST2_reg                                                                  0xB80150F4
#define set_CP_TST2_reg(data)   (*((volatile unsigned int*) CP_TST2_reg)=data)
#define get_CP_TST2_reg   (*((volatile unsigned int*) CP_TST2_reg))
#define CP_TST2_inst_adr                                                             "0x003D"
#define CP_TST2_inst                                                                 0x003D
#define CP_TST2_test_out_shift                                                       (0)
#define CP_TST2_test_out_mask                                                        (0xFFFFFFFF)
#define CP_TST2_test_out(data)                                                       (0xFFFFFFFF&((data)<<0))
#define CP_TST2_test_out_src(data)                                                   ((0xFFFFFFFF&(data))>>0)
#define CP_TST2_get_test_out(data)                                                   ((0xFFFFFFFF&(data))>>0)


#define CP_BIST_MODE                                                                 0x18015000
#define CP_BIST_MODE_reg_addr                                                        "0xB8015000"
#define CP_BIST_MODE_reg                                                             0xB8015000
#define set_CP_BIST_MODE_reg(data)   (*((volatile unsigned int*) CP_BIST_MODE_reg)=data)
#define get_CP_BIST_MODE_reg   (*((volatile unsigned int*) CP_BIST_MODE_reg))
#define CP_BIST_MODE_inst_adr                                                        "0x0000"
#define CP_BIST_MODE_inst                                                            0x0000
#define CP_BIST_MODE_en_shift                                                        (0)
#define CP_BIST_MODE_en_mask                                                         (0x00000001)
#define CP_BIST_MODE_en(data)                                                        (0x00000001&((data)<<0))
#define CP_BIST_MODE_en_src(data)                                                    ((0x00000001&(data))>>0)
#define CP_BIST_MODE_get_en(data)                                                    ((0x00000001&(data))>>0)


#define CP_BIST_DONE                                                                 0x18015004
#define CP_BIST_DONE_reg_addr                                                        "0xB8015004"
#define CP_BIST_DONE_reg                                                             0xB8015004
#define set_CP_BIST_DONE_reg(data)   (*((volatile unsigned int*) CP_BIST_DONE_reg)=data)
#define get_CP_BIST_DONE_reg   (*((volatile unsigned int*) CP_BIST_DONE_reg))
#define CP_BIST_DONE_inst_adr                                                        "0x0001"
#define CP_BIST_DONE_inst                                                            0x0001
#define CP_BIST_DONE_done_shift                                                      (0)
#define CP_BIST_DONE_done_mask                                                       (0x00000001)
#define CP_BIST_DONE_done(data)                                                      (0x00000001&((data)<<0))
#define CP_BIST_DONE_done_src(data)                                                  ((0x00000001&(data))>>0)
#define CP_BIST_DONE_get_done(data)                                                  ((0x00000001&(data))>>0)


#define CP_BIST_FAIL_GROUP                                                           0x18015008
#define CP_BIST_FAIL_GROUP_reg_addr                                                  "0xB8015008"
#define CP_BIST_FAIL_GROUP_reg                                                       0xB8015008
#define set_CP_BIST_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) CP_BIST_FAIL_GROUP_reg)=data)
#define get_CP_BIST_FAIL_GROUP_reg   (*((volatile unsigned int*) CP_BIST_FAIL_GROUP_reg))
#define CP_BIST_FAIL_GROUP_inst_adr                                                  "0x0002"
#define CP_BIST_FAIL_GROUP_inst                                                      0x0002
#define CP_BIST_FAIL_GROUP_fail_group_shift                                          (0)
#define CP_BIST_FAIL_GROUP_fail_group_mask                                           (0x00000001)
#define CP_BIST_FAIL_GROUP_fail_group(data)                                          (0x00000001&((data)<<0))
#define CP_BIST_FAIL_GROUP_fail_group_src(data)                                      ((0x00000001&(data))>>0)
#define CP_BIST_FAIL_GROUP_get_fail_group(data)                                      ((0x00000001&(data))>>0)


#define CP_BIST_FAIL                                                                 0x1801500C
#define CP_BIST_FAIL_reg_addr                                                        "0xB801500C"
#define CP_BIST_FAIL_reg                                                             0xB801500C
#define set_CP_BIST_FAIL_reg(data)   (*((volatile unsigned int*) CP_BIST_FAIL_reg)=data)
#define get_CP_BIST_FAIL_reg   (*((volatile unsigned int*) CP_BIST_FAIL_reg))
#define CP_BIST_FAIL_inst_adr                                                        "0x0003"
#define CP_BIST_FAIL_inst                                                            0x0003
#define CP_BIST_FAIL_fail3_shift                                                     (12)
#define CP_BIST_FAIL_fail3_mask                                                      (0x00001000)
#define CP_BIST_FAIL_fail3(data)                                                     (0x00001000&((data)<<12))
#define CP_BIST_FAIL_fail3_src(data)                                                 ((0x00001000&(data))>>12)
#define CP_BIST_FAIL_get_fail3(data)                                                 ((0x00001000&(data))>>12)
#define CP_BIST_FAIL_fail2_shift                                                     (8)
#define CP_BIST_FAIL_fail2_mask                                                      (0x00000100)
#define CP_BIST_FAIL_fail2(data)                                                     (0x00000100&((data)<<8))
#define CP_BIST_FAIL_fail2_src(data)                                                 ((0x00000100&(data))>>8)
#define CP_BIST_FAIL_get_fail2(data)                                                 ((0x00000100&(data))>>8)
#define CP_BIST_FAIL_fail1_shift                                                     (4)
#define CP_BIST_FAIL_fail1_mask                                                      (0x00000010)
#define CP_BIST_FAIL_fail1(data)                                                     (0x00000010&((data)<<4))
#define CP_BIST_FAIL_fail1_src(data)                                                 ((0x00000010&(data))>>4)
#define CP_BIST_FAIL_get_fail1(data)                                                 ((0x00000010&(data))>>4)
#define CP_BIST_FAIL_fail0_shift                                                     (0)
#define CP_BIST_FAIL_fail0_mask                                                      (0x00000001)
#define CP_BIST_FAIL_fail0(data)                                                     (0x00000001&((data)<<0))
#define CP_BIST_FAIL_fail0_src(data)                                                 ((0x00000001&(data))>>0)
#define CP_BIST_FAIL_get_fail0(data)                                                 ((0x00000001&(data))>>0)


#define CP_DRF_MODE                                                                  0x18015010
#define CP_DRF_MODE_reg_addr                                                         "0xB8015010"
#define CP_DRF_MODE_reg                                                              0xB8015010
#define set_CP_DRF_MODE_reg(data)   (*((volatile unsigned int*) CP_DRF_MODE_reg)=data)
#define get_CP_DRF_MODE_reg   (*((volatile unsigned int*) CP_DRF_MODE_reg))
#define CP_DRF_MODE_inst_adr                                                         "0x0004"
#define CP_DRF_MODE_inst                                                             0x0004
#define CP_DRF_MODE_en_shift                                                         (0)
#define CP_DRF_MODE_en_mask                                                          (0x00000001)
#define CP_DRF_MODE_en(data)                                                         (0x00000001&((data)<<0))
#define CP_DRF_MODE_en_src(data)                                                     ((0x00000001&(data))>>0)
#define CP_DRF_MODE_get_en(data)                                                     ((0x00000001&(data))>>0)


#define CP_DRF_DONE                                                                  0x18015014
#define CP_DRF_DONE_reg_addr                                                         "0xB8015014"
#define CP_DRF_DONE_reg                                                              0xB8015014
#define set_CP_DRF_DONE_reg(data)   (*((volatile unsigned int*) CP_DRF_DONE_reg)=data)
#define get_CP_DRF_DONE_reg   (*((volatile unsigned int*) CP_DRF_DONE_reg))
#define CP_DRF_DONE_inst_adr                                                         "0x0005"
#define CP_DRF_DONE_inst                                                             0x0005
#define CP_DRF_DONE_done_shift                                                       (0)
#define CP_DRF_DONE_done_mask                                                        (0x00000001)
#define CP_DRF_DONE_done(data)                                                       (0x00000001&((data)<<0))
#define CP_DRF_DONE_done_src(data)                                                   ((0x00000001&(data))>>0)
#define CP_DRF_DONE_get_done(data)                                                   ((0x00000001&(data))>>0)


#define CP_DRF_FAIL_GROUP                                                            0x18015018
#define CP_DRF_FAIL_GROUP_reg_addr                                                   "0xB8015018"
#define CP_DRF_FAIL_GROUP_reg                                                        0xB8015018
#define set_CP_DRF_FAIL_GROUP_reg(data)   (*((volatile unsigned int*) CP_DRF_FAIL_GROUP_reg)=data)
#define get_CP_DRF_FAIL_GROUP_reg   (*((volatile unsigned int*) CP_DRF_FAIL_GROUP_reg))
#define CP_DRF_FAIL_GROUP_inst_adr                                                   "0x0006"
#define CP_DRF_FAIL_GROUP_inst                                                       0x0006
#define CP_DRF_FAIL_GROUP_fail_group_shift                                           (0)
#define CP_DRF_FAIL_GROUP_fail_group_mask                                            (0x00000001)
#define CP_DRF_FAIL_GROUP_fail_group(data)                                           (0x00000001&((data)<<0))
#define CP_DRF_FAIL_GROUP_fail_group_src(data)                                       ((0x00000001&(data))>>0)
#define CP_DRF_FAIL_GROUP_get_fail_group(data)                                       ((0x00000001&(data))>>0)


#define CP_DRF_FAIL                                                                  0x1801501C
#define CP_DRF_FAIL_reg_addr                                                         "0xB801501C"
#define CP_DRF_FAIL_reg                                                              0xB801501C
#define set_CP_DRF_FAIL_reg(data)   (*((volatile unsigned int*) CP_DRF_FAIL_reg)=data)
#define get_CP_DRF_FAIL_reg   (*((volatile unsigned int*) CP_DRF_FAIL_reg))
#define CP_DRF_FAIL_inst_adr                                                         "0x0007"
#define CP_DRF_FAIL_inst                                                             0x0007
#define CP_DRF_FAIL_fail3_shift                                                      (12)
#define CP_DRF_FAIL_fail3_mask                                                       (0x00001000)
#define CP_DRF_FAIL_fail3(data)                                                      (0x00001000&((data)<<12))
#define CP_DRF_FAIL_fail3_src(data)                                                  ((0x00001000&(data))>>12)
#define CP_DRF_FAIL_get_fail3(data)                                                  ((0x00001000&(data))>>12)
#define CP_DRF_FAIL_fail2_shift                                                      (8)
#define CP_DRF_FAIL_fail2_mask                                                       (0x00000100)
#define CP_DRF_FAIL_fail2(data)                                                      (0x00000100&((data)<<8))
#define CP_DRF_FAIL_fail2_src(data)                                                  ((0x00000100&(data))>>8)
#define CP_DRF_FAIL_get_fail2(data)                                                  ((0x00000100&(data))>>8)
#define CP_DRF_FAIL_fail1_shift                                                      (4)
#define CP_DRF_FAIL_fail1_mask                                                       (0x00000010)
#define CP_DRF_FAIL_fail1(data)                                                      (0x00000010&((data)<<4))
#define CP_DRF_FAIL_fail1_src(data)                                                  ((0x00000010&(data))>>4)
#define CP_DRF_FAIL_get_fail1(data)                                                  ((0x00000010&(data))>>4)
#define CP_DRF_FAIL_fail0_shift                                                      (0)
#define CP_DRF_FAIL_fail0_mask                                                       (0x00000001)
#define CP_DRF_FAIL_fail0(data)                                                      (0x00000001&((data)<<0))
#define CP_DRF_FAIL_fail0_src(data)                                                  ((0x00000001&(data))>>0)
#define CP_DRF_FAIL_get_fail0(data)                                                  ((0x00000001&(data))>>0)


#define CP_DRF_RESUME                                                                0x18015020
#define CP_DRF_RESUME_reg_addr                                                       "0xB8015020"
#define CP_DRF_RESUME_reg                                                            0xB8015020
#define set_CP_DRF_RESUME_reg(data)   (*((volatile unsigned int*) CP_DRF_RESUME_reg)=data)
#define get_CP_DRF_RESUME_reg   (*((volatile unsigned int*) CP_DRF_RESUME_reg))
#define CP_DRF_RESUME_inst_adr                                                       "0x0008"
#define CP_DRF_RESUME_inst                                                           0x0008
#define CP_DRF_RESUME_en_shift                                                       (0)
#define CP_DRF_RESUME_en_mask                                                        (0x00000001)
#define CP_DRF_RESUME_en(data)                                                       (0x00000001&((data)<<0))
#define CP_DRF_RESUME_en_src(data)                                                   ((0x00000001&(data))>>0)
#define CP_DRF_RESUME_get_en(data)                                                   ((0x00000001&(data))>>0)


#define CP_DRF_PAUSE                                                                 0x18015024
#define CP_DRF_PAUSE_reg_addr                                                        "0xB8015024"
#define CP_DRF_PAUSE_reg                                                             0xB8015024
#define set_CP_DRF_PAUSE_reg(data)   (*((volatile unsigned int*) CP_DRF_PAUSE_reg)=data)
#define get_CP_DRF_PAUSE_reg   (*((volatile unsigned int*) CP_DRF_PAUSE_reg))
#define CP_DRF_PAUSE_inst_adr                                                        "0x0009"
#define CP_DRF_PAUSE_inst                                                            0x0009
#define CP_DRF_PAUSE_flag_shift                                                      (0)
#define CP_DRF_PAUSE_flag_mask                                                       (0x00000001)
#define CP_DRF_PAUSE_flag(data)                                                      (0x00000001&((data)<<0))
#define CP_DRF_PAUSE_flag_src(data)                                                  ((0x00000001&(data))>>0)
#define CP_DRF_PAUSE_get_flag(data)                                                  ((0x00000001&(data))>>0)


#define CP_SRAM_RM                                                                   0x18015028
#define CP_SRAM_RM_reg_addr                                                          "0xB8015028"
#define CP_SRAM_RM_reg                                                               0xB8015028
#define set_CP_SRAM_RM_reg(data)   (*((volatile unsigned int*) CP_SRAM_RM_reg)=data)
#define get_CP_SRAM_RM_reg   (*((volatile unsigned int*) CP_SRAM_RM_reg))
#define CP_SRAM_RM_inst_adr                                                          "0x000A"
#define CP_SRAM_RM_inst                                                              0x000A
#define CP_SRAM_RM_rsa_rme_shift                                                     (28)
#define CP_SRAM_RM_rsa_rme_mask                                                      (0x10000000)
#define CP_SRAM_RM_rsa_rme(data)                                                     (0x10000000&((data)<<28))
#define CP_SRAM_RM_rsa_rme_src(data)                                                 ((0x10000000&(data))>>28)
#define CP_SRAM_RM_get_rsa_rme(data)                                                 ((0x10000000&(data))>>28)
#define CP_SRAM_RM_rsa_rm_shift                                                      (24)
#define CP_SRAM_RM_rsa_rm_mask                                                       (0x0F000000)
#define CP_SRAM_RM_rsa_rm(data)                                                      (0x0F000000&((data)<<24))
#define CP_SRAM_RM_rsa_rm_src(data)                                                  ((0x0F000000&(data))>>24)
#define CP_SRAM_RM_get_rsa_rm(data)                                                  ((0x0F000000&(data))>>24)
#define CP_SRAM_RM_din1_rme_shift                                                    (20)
#define CP_SRAM_RM_din1_rme_mask                                                     (0x00100000)
#define CP_SRAM_RM_din1_rme(data)                                                    (0x00100000&((data)<<20))
#define CP_SRAM_RM_din1_rme_src(data)                                                ((0x00100000&(data))>>20)
#define CP_SRAM_RM_get_din1_rme(data)                                                ((0x00100000&(data))>>20)
#define CP_SRAM_RM_din1_rm_shift                                                     (16)
#define CP_SRAM_RM_din1_rm_mask                                                      (0x000F0000)
#define CP_SRAM_RM_din1_rm(data)                                                     (0x000F0000&((data)<<16))
#define CP_SRAM_RM_din1_rm_src(data)                                                 ((0x000F0000&(data))>>16)
#define CP_SRAM_RM_get_din1_rm(data)                                                 ((0x000F0000&(data))>>16)
#define CP_SRAM_RM_din0_rme_shift                                                    (12)
#define CP_SRAM_RM_din0_rme_mask                                                     (0x00001000)
#define CP_SRAM_RM_din0_rme(data)                                                    (0x00001000&((data)<<12))
#define CP_SRAM_RM_din0_rme_src(data)                                                ((0x00001000&(data))>>12)
#define CP_SRAM_RM_get_din0_rme(data)                                                ((0x00001000&(data))>>12)
#define CP_SRAM_RM_din0_rm_shift                                                     (8)
#define CP_SRAM_RM_din0_rm_mask                                                      (0x00000F00)
#define CP_SRAM_RM_din0_rm(data)                                                     (0x00000F00&((data)<<8))
#define CP_SRAM_RM_din0_rm_src(data)                                                 ((0x00000F00&(data))>>8)
#define CP_SRAM_RM_get_din0_rm(data)                                                 ((0x00000F00&(data))>>8)
#define CP_SRAM_RM_desc_rme_shift                                                    (4)
#define CP_SRAM_RM_desc_rme_mask                                                     (0x00000010)
#define CP_SRAM_RM_desc_rme(data)                                                    (0x00000010&((data)<<4))
#define CP_SRAM_RM_desc_rme_src(data)                                                ((0x00000010&(data))>>4)
#define CP_SRAM_RM_get_desc_rme(data)                                                ((0x00000010&(data))>>4)
#define CP_SRAM_RM_desc_rm_shift                                                     (0)
#define CP_SRAM_RM_desc_rm_mask                                                      (0x0000000F)
#define CP_SRAM_RM_desc_rm(data)                                                     (0x0000000F&((data)<<0))
#define CP_SRAM_RM_desc_rm_src(data)                                                 ((0x0000000F&(data))>>0)
#define CP_SRAM_RM_get_desc_rm(data)                                                 ((0x0000000F&(data))>>0)


#define CP_SRAM_LS                                                                   0x1801502c
#define CP_SRAM_LS_reg_addr                                                          "0xB801502C"
#define CP_SRAM_LS_reg                                                               0xB801502C
#define set_CP_SRAM_LS_reg(data)   (*((volatile unsigned int*) CP_SRAM_LS_reg)=data)
#define get_CP_SRAM_LS_reg   (*((volatile unsigned int*) CP_SRAM_LS_reg))
#define CP_SRAM_LS_inst_adr                                                          "0x000B"
#define CP_SRAM_LS_inst                                                              0x000B
#define CP_SRAM_LS_rsa_ls_shift                                                      (12)
#define CP_SRAM_LS_rsa_ls_mask                                                       (0x00001000)
#define CP_SRAM_LS_rsa_ls(data)                                                      (0x00001000&((data)<<12))
#define CP_SRAM_LS_rsa_ls_src(data)                                                  ((0x00001000&(data))>>12)
#define CP_SRAM_LS_get_rsa_ls(data)                                                  ((0x00001000&(data))>>12)
#define CP_SRAM_LS_din1_ls_shift                                                     (8)
#define CP_SRAM_LS_din1_ls_mask                                                      (0x00000100)
#define CP_SRAM_LS_din1_ls(data)                                                     (0x00000100&((data)<<8))
#define CP_SRAM_LS_din1_ls_src(data)                                                 ((0x00000100&(data))>>8)
#define CP_SRAM_LS_get_din1_ls(data)                                                 ((0x00000100&(data))>>8)
#define CP_SRAM_LS_din0_ls_shift                                                     (4)
#define CP_SRAM_LS_din0_ls_mask                                                      (0x00000010)
#define CP_SRAM_LS_din0_ls(data)                                                     (0x00000010&((data)<<4))
#define CP_SRAM_LS_din0_ls_src(data)                                                 ((0x00000010&(data))>>4)
#define CP_SRAM_LS_get_din0_ls(data)                                                 ((0x00000010&(data))>>4)
#define CP_SRAM_LS_desc_ls_shift                                                     (0)
#define CP_SRAM_LS_desc_ls_mask                                                      (0x00000001)
#define CP_SRAM_LS_desc_ls(data)                                                     (0x00000001&((data)<<0))
#define CP_SRAM_LS_desc_ls_src(data)                                                 ((0x00000001&(data))>>0)
#define CP_SRAM_LS_get_desc_ls(data)                                                 ((0x00000001&(data))>>0)


#define K_CP_SCPU_CW_RANGE                                                           0x18015a00
#define K_CP_SCPU_CW_RANGE_reg_addr                                                  "0xB8015A00"
#define K_CP_SCPU_CW_RANGE_reg                                                       0xB8015A00
#define set_K_CP_SCPU_CW_RANGE_reg(data)   (*((volatile unsigned int*) K_CP_SCPU_CW_RANGE_reg)=data)
#define get_K_CP_SCPU_CW_RANGE_reg   (*((volatile unsigned int*) K_CP_SCPU_CW_RANGE_reg))
#define K_CP_SCPU_CW_RANGE_inst_adr                                                  "0x0080"
#define K_CP_SCPU_CW_RANGE_inst                                                      0x0080
#define K_CP_SCPU_CW_RANGE_start_shift                                               (8)
#define K_CP_SCPU_CW_RANGE_start_mask                                                (0x00007F00)
#define K_CP_SCPU_CW_RANGE_start(data)                                               (0x00007F00&((data)<<8))
#define K_CP_SCPU_CW_RANGE_start_src(data)                                           ((0x00007F00&(data))>>8)
#define K_CP_SCPU_CW_RANGE_get_start(data)                                           ((0x00007F00&(data))>>8)
#define K_CP_SCPU_CW_RANGE_end_shift                                                 (0)
#define K_CP_SCPU_CW_RANGE_end_mask                                                  (0x0000007F)
#define K_CP_SCPU_CW_RANGE_end(data)                                                 (0x0000007F&((data)<<0))
#define K_CP_SCPU_CW_RANGE_end_src(data)                                             ((0x0000007F&(data))>>0)
#define K_CP_SCPU_CW_RANGE_get_end(data)                                             ((0x0000007F&(data))>>0)


#endif
