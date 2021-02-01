/**************************************************************
// Spec Version                  : 1.10
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Register_Name
// Naming Rule                   : Register_Name
// Parse Option                  : Only Parse _op2
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2014/1/7 19:34:54
***************************************************************/


#ifndef _RSA_REG_H_INCLUDED_
#define _RSA_REG_H_INCLUDED_
#ifdef  _RSA_USE_STRUCT
typedef struct 
{
unsigned int     data:32;
}RSA_X;

typedef struct 
{
unsigned int     data:32;
}RSA_Y;

typedef struct 
{
unsigned int     data:32;
}RSA_M;

typedef struct 
{
unsigned int     data:32;
}RSA_A;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     go:1;
}RSA_CTRL;

typedef struct 
{
unsigned int     reserved_0:26;
unsigned int     bits_num:6;
}RSA_NUM;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     rsa_done:1;
}RSA_INT_STATUS;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     rsa_clear:1;
}RSA_CLEAR;

typedef struct 
{
unsigned int     dummy:32;
}RSA_DUMMY;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_en:1;
}S_RSA_INT_EN;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_sel:1;
}S_RSA_SEL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     scpu_st:1;
}S_RSA_ST;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     kcpu_en:1;
}K_RSA_INT_EN;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     kcpu_sel:1;
}K_RSA_SEL;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     kcpu_st:1;
}K_RSA_ST;

typedef struct 
{
unsigned int     reserved_0:31;
unsigned int     on:1;
}K_RSA_SECURITY;

#endif

#define RSA_X_0                                                                      0x1806E000
#define RSA_X_1                                                                      0x1806E004
#define RSA_X_2                                                                      0x1806E008
#define RSA_X_3                                                                      0x1806E00C
#define RSA_X_4                                                                      0x1806E010
#define RSA_X_5                                                                      0x1806E014
#define RSA_X_6                                                                      0x1806E018
#define RSA_X_7                                                                      0x1806E01C
#define RSA_X_8                                                                      0x1806E020
#define RSA_X_9                                                                      0x1806E024
#define RSA_X_10                                                                      0x1806E028
#define RSA_X_11                                                                      0x1806E02C
#define RSA_X_12                                                                      0x1806E030
#define RSA_X_13                                                                      0x1806E034
#define RSA_X_14                                                                      0x1806E038
#define RSA_X_15                                                                      0x1806E03C
#define RSA_X_16                                                                      0x1806E040
#define RSA_X_17                                                                      0x1806E044
#define RSA_X_18                                                                      0x1806E048
#define RSA_X_19                                                                      0x1806E04C
#define RSA_X_20                                                                      0x1806E050
#define RSA_X_21                                                                      0x1806E054
#define RSA_X_22                                                                      0x1806E058
#define RSA_X_23                                                                      0x1806E05C
#define RSA_X_24                                                                      0x1806E060
#define RSA_X_25                                                                      0x1806E064
#define RSA_X_26                                                                      0x1806E068
#define RSA_X_27                                                                      0x1806E06C
#define RSA_X_28                                                                      0x1806E070
#define RSA_X_29                                                                      0x1806E074
#define RSA_X_30                                                                      0x1806E078
#define RSA_X_31                                                                      0x1806E07C
#define RSA_X_32                                                                      0x1806E080
#define RSA_X_33                                                                      0x1806E084
#define RSA_X_34                                                                      0x1806E088
#define RSA_X_35                                                                      0x1806E08C
#define RSA_X_36                                                                      0x1806E090
#define RSA_X_37                                                                      0x1806E094
#define RSA_X_38                                                                      0x1806E098
#define RSA_X_39                                                                      0x1806E09C
#define RSA_X_40                                                                      0x1806E0A0
#define RSA_X_41                                                                      0x1806E0A4
#define RSA_X_42                                                                      0x1806E0A8
#define RSA_X_43                                                                      0x1806E0AC
#define RSA_X_44                                                                      0x1806E0B0
#define RSA_X_45                                                                      0x1806E0B4
#define RSA_X_46                                                                      0x1806E0B8
#define RSA_X_47                                                                      0x1806E0BC
#define RSA_X_48                                                                      0x1806E0C0
#define RSA_X_49                                                                      0x1806E0C4
#define RSA_X_50                                                                      0x1806E0C8
#define RSA_X_51                                                                      0x1806E0CC
#define RSA_X_52                                                                      0x1806E0D0
#define RSA_X_53                                                                      0x1806E0D4
#define RSA_X_54                                                                      0x1806E0D8
#define RSA_X_55                                                                      0x1806E0DC
#define RSA_X_56                                                                      0x1806E0E0
#define RSA_X_57                                                                      0x1806E0E4
#define RSA_X_58                                                                      0x1806E0E8
#define RSA_X_59                                                                      0x1806E0EC
#define RSA_X_60                                                                      0x1806E0F0
#define RSA_X_61                                                                      0x1806E0F4
#define RSA_X_62                                                                      0x1806E0F8
#define RSA_X_63                                                                      0x1806E0FC
#define RSA_X_0_reg_addr                                                             "0xB806E000"
#define RSA_X_1_reg_addr                                                             "0xB806E004"
#define RSA_X_2_reg_addr                                                             "0xB806E008"
#define RSA_X_3_reg_addr                                                             "0xB806E00C"
#define RSA_X_4_reg_addr                                                             "0xB806E010"
#define RSA_X_5_reg_addr                                                             "0xB806E014"
#define RSA_X_6_reg_addr                                                             "0xB806E018"
#define RSA_X_7_reg_addr                                                             "0xB806E01C"
#define RSA_X_8_reg_addr                                                             "0xB806E020"
#define RSA_X_9_reg_addr                                                             "0xB806E024"
#define RSA_X_10_reg_addr                                                             "0xB806E028"
#define RSA_X_11_reg_addr                                                             "0xB806E02C"
#define RSA_X_12_reg_addr                                                             "0xB806E030"
#define RSA_X_13_reg_addr                                                             "0xB806E034"
#define RSA_X_14_reg_addr                                                             "0xB806E038"
#define RSA_X_15_reg_addr                                                             "0xB806E03C"
#define RSA_X_16_reg_addr                                                             "0xB806E040"
#define RSA_X_17_reg_addr                                                             "0xB806E044"
#define RSA_X_18_reg_addr                                                             "0xB806E048"
#define RSA_X_19_reg_addr                                                             "0xB806E04C"
#define RSA_X_20_reg_addr                                                             "0xB806E050"
#define RSA_X_21_reg_addr                                                             "0xB806E054"
#define RSA_X_22_reg_addr                                                             "0xB806E058"
#define RSA_X_23_reg_addr                                                             "0xB806E05C"
#define RSA_X_24_reg_addr                                                             "0xB806E060"
#define RSA_X_25_reg_addr                                                             "0xB806E064"
#define RSA_X_26_reg_addr                                                             "0xB806E068"
#define RSA_X_27_reg_addr                                                             "0xB806E06C"
#define RSA_X_28_reg_addr                                                             "0xB806E070"
#define RSA_X_29_reg_addr                                                             "0xB806E074"
#define RSA_X_30_reg_addr                                                             "0xB806E078"
#define RSA_X_31_reg_addr                                                             "0xB806E07C"
#define RSA_X_32_reg_addr                                                             "0xB806E080"
#define RSA_X_33_reg_addr                                                             "0xB806E084"
#define RSA_X_34_reg_addr                                                             "0xB806E088"
#define RSA_X_35_reg_addr                                                             "0xB806E08C"
#define RSA_X_36_reg_addr                                                             "0xB806E090"
#define RSA_X_37_reg_addr                                                             "0xB806E094"
#define RSA_X_38_reg_addr                                                             "0xB806E098"
#define RSA_X_39_reg_addr                                                             "0xB806E09C"
#define RSA_X_40_reg_addr                                                             "0xB806E0A0"
#define RSA_X_41_reg_addr                                                             "0xB806E0A4"
#define RSA_X_42_reg_addr                                                             "0xB806E0A8"
#define RSA_X_43_reg_addr                                                             "0xB806E0AC"
#define RSA_X_44_reg_addr                                                             "0xB806E0B0"
#define RSA_X_45_reg_addr                                                             "0xB806E0B4"
#define RSA_X_46_reg_addr                                                             "0xB806E0B8"
#define RSA_X_47_reg_addr                                                             "0xB806E0BC"
#define RSA_X_48_reg_addr                                                             "0xB806E0C0"
#define RSA_X_49_reg_addr                                                             "0xB806E0C4"
#define RSA_X_50_reg_addr                                                             "0xB806E0C8"
#define RSA_X_51_reg_addr                                                             "0xB806E0CC"
#define RSA_X_52_reg_addr                                                             "0xB806E0D0"
#define RSA_X_53_reg_addr                                                             "0xB806E0D4"
#define RSA_X_54_reg_addr                                                             "0xB806E0D8"
#define RSA_X_55_reg_addr                                                             "0xB806E0DC"
#define RSA_X_56_reg_addr                                                             "0xB806E0E0"
#define RSA_X_57_reg_addr                                                             "0xB806E0E4"
#define RSA_X_58_reg_addr                                                             "0xB806E0E8"
#define RSA_X_59_reg_addr                                                             "0xB806E0EC"
#define RSA_X_60_reg_addr                                                             "0xB806E0F0"
#define RSA_X_61_reg_addr                                                             "0xB806E0F4"
#define RSA_X_62_reg_addr                                                             "0xB806E0F8"
#define RSA_X_63_reg_addr                                                             "0xB806E0FC"
#define RSA_X_0_reg                                                                  0xB806E000
#define RSA_X_1_reg                                                                  0xB806E004
#define RSA_X_2_reg                                                                  0xB806E008
#define RSA_X_3_reg                                                                  0xB806E00C
#define RSA_X_4_reg                                                                  0xB806E010
#define RSA_X_5_reg                                                                  0xB806E014
#define RSA_X_6_reg                                                                  0xB806E018
#define RSA_X_7_reg                                                                  0xB806E01C
#define RSA_X_8_reg                                                                  0xB806E020
#define RSA_X_9_reg                                                                  0xB806E024
#define RSA_X_10_reg                                                                  0xB806E028
#define RSA_X_11_reg                                                                  0xB806E02C
#define RSA_X_12_reg                                                                  0xB806E030
#define RSA_X_13_reg                                                                  0xB806E034
#define RSA_X_14_reg                                                                  0xB806E038
#define RSA_X_15_reg                                                                  0xB806E03C
#define RSA_X_16_reg                                                                  0xB806E040
#define RSA_X_17_reg                                                                  0xB806E044
#define RSA_X_18_reg                                                                  0xB806E048
#define RSA_X_19_reg                                                                  0xB806E04C
#define RSA_X_20_reg                                                                  0xB806E050
#define RSA_X_21_reg                                                                  0xB806E054
#define RSA_X_22_reg                                                                  0xB806E058
#define RSA_X_23_reg                                                                  0xB806E05C
#define RSA_X_24_reg                                                                  0xB806E060
#define RSA_X_25_reg                                                                  0xB806E064
#define RSA_X_26_reg                                                                  0xB806E068
#define RSA_X_27_reg                                                                  0xB806E06C
#define RSA_X_28_reg                                                                  0xB806E070
#define RSA_X_29_reg                                                                  0xB806E074
#define RSA_X_30_reg                                                                  0xB806E078
#define RSA_X_31_reg                                                                  0xB806E07C
#define RSA_X_32_reg                                                                  0xB806E080
#define RSA_X_33_reg                                                                  0xB806E084
#define RSA_X_34_reg                                                                  0xB806E088
#define RSA_X_35_reg                                                                  0xB806E08C
#define RSA_X_36_reg                                                                  0xB806E090
#define RSA_X_37_reg                                                                  0xB806E094
#define RSA_X_38_reg                                                                  0xB806E098
#define RSA_X_39_reg                                                                  0xB806E09C
#define RSA_X_40_reg                                                                  0xB806E0A0
#define RSA_X_41_reg                                                                  0xB806E0A4
#define RSA_X_42_reg                                                                  0xB806E0A8
#define RSA_X_43_reg                                                                  0xB806E0AC
#define RSA_X_44_reg                                                                  0xB806E0B0
#define RSA_X_45_reg                                                                  0xB806E0B4
#define RSA_X_46_reg                                                                  0xB806E0B8
#define RSA_X_47_reg                                                                  0xB806E0BC
#define RSA_X_48_reg                                                                  0xB806E0C0
#define RSA_X_49_reg                                                                  0xB806E0C4
#define RSA_X_50_reg                                                                  0xB806E0C8
#define RSA_X_51_reg                                                                  0xB806E0CC
#define RSA_X_52_reg                                                                  0xB806E0D0
#define RSA_X_53_reg                                                                  0xB806E0D4
#define RSA_X_54_reg                                                                  0xB806E0D8
#define RSA_X_55_reg                                                                  0xB806E0DC
#define RSA_X_56_reg                                                                  0xB806E0E0
#define RSA_X_57_reg                                                                  0xB806E0E4
#define RSA_X_58_reg                                                                  0xB806E0E8
#define RSA_X_59_reg                                                                  0xB806E0EC
#define RSA_X_60_reg                                                                  0xB806E0F0
#define RSA_X_61_reg                                                                  0xB806E0F4
#define RSA_X_62_reg                                                                  0xB806E0F8
#define RSA_X_63_reg                                                                  0xB806E0FC
#define set_RSA_X_0_reg(data)   (*((volatile unsigned int*) RSA_X_0_reg)=data)
#define set_RSA_X_1_reg(data)   (*((volatile unsigned int*) RSA_X_1_reg)=data)
#define set_RSA_X_2_reg(data)   (*((volatile unsigned int*) RSA_X_2_reg)=data)
#define set_RSA_X_3_reg(data)   (*((volatile unsigned int*) RSA_X_3_reg)=data)
#define set_RSA_X_4_reg(data)   (*((volatile unsigned int*) RSA_X_4_reg)=data)
#define set_RSA_X_5_reg(data)   (*((volatile unsigned int*) RSA_X_5_reg)=data)
#define set_RSA_X_6_reg(data)   (*((volatile unsigned int*) RSA_X_6_reg)=data)
#define set_RSA_X_7_reg(data)   (*((volatile unsigned int*) RSA_X_7_reg)=data)
#define set_RSA_X_8_reg(data)   (*((volatile unsigned int*) RSA_X_8_reg)=data)
#define set_RSA_X_9_reg(data)   (*((volatile unsigned int*) RSA_X_9_reg)=data)
#define set_RSA_X_10_reg(data)   (*((volatile unsigned int*) RSA_X_10_reg)=data)
#define set_RSA_X_11_reg(data)   (*((volatile unsigned int*) RSA_X_11_reg)=data)
#define set_RSA_X_12_reg(data)   (*((volatile unsigned int*) RSA_X_12_reg)=data)
#define set_RSA_X_13_reg(data)   (*((volatile unsigned int*) RSA_X_13_reg)=data)
#define set_RSA_X_14_reg(data)   (*((volatile unsigned int*) RSA_X_14_reg)=data)
#define set_RSA_X_15_reg(data)   (*((volatile unsigned int*) RSA_X_15_reg)=data)
#define set_RSA_X_16_reg(data)   (*((volatile unsigned int*) RSA_X_16_reg)=data)
#define set_RSA_X_17_reg(data)   (*((volatile unsigned int*) RSA_X_17_reg)=data)
#define set_RSA_X_18_reg(data)   (*((volatile unsigned int*) RSA_X_18_reg)=data)
#define set_RSA_X_19_reg(data)   (*((volatile unsigned int*) RSA_X_19_reg)=data)
#define set_RSA_X_20_reg(data)   (*((volatile unsigned int*) RSA_X_20_reg)=data)
#define set_RSA_X_21_reg(data)   (*((volatile unsigned int*) RSA_X_21_reg)=data)
#define set_RSA_X_22_reg(data)   (*((volatile unsigned int*) RSA_X_22_reg)=data)
#define set_RSA_X_23_reg(data)   (*((volatile unsigned int*) RSA_X_23_reg)=data)
#define set_RSA_X_24_reg(data)   (*((volatile unsigned int*) RSA_X_24_reg)=data)
#define set_RSA_X_25_reg(data)   (*((volatile unsigned int*) RSA_X_25_reg)=data)
#define set_RSA_X_26_reg(data)   (*((volatile unsigned int*) RSA_X_26_reg)=data)
#define set_RSA_X_27_reg(data)   (*((volatile unsigned int*) RSA_X_27_reg)=data)
#define set_RSA_X_28_reg(data)   (*((volatile unsigned int*) RSA_X_28_reg)=data)
#define set_RSA_X_29_reg(data)   (*((volatile unsigned int*) RSA_X_29_reg)=data)
#define set_RSA_X_30_reg(data)   (*((volatile unsigned int*) RSA_X_30_reg)=data)
#define set_RSA_X_31_reg(data)   (*((volatile unsigned int*) RSA_X_31_reg)=data)
#define set_RSA_X_32_reg(data)   (*((volatile unsigned int*) RSA_X_32_reg)=data)
#define set_RSA_X_33_reg(data)   (*((volatile unsigned int*) RSA_X_33_reg)=data)
#define set_RSA_X_34_reg(data)   (*((volatile unsigned int*) RSA_X_34_reg)=data)
#define set_RSA_X_35_reg(data)   (*((volatile unsigned int*) RSA_X_35_reg)=data)
#define set_RSA_X_36_reg(data)   (*((volatile unsigned int*) RSA_X_36_reg)=data)
#define set_RSA_X_37_reg(data)   (*((volatile unsigned int*) RSA_X_37_reg)=data)
#define set_RSA_X_38_reg(data)   (*((volatile unsigned int*) RSA_X_38_reg)=data)
#define set_RSA_X_39_reg(data)   (*((volatile unsigned int*) RSA_X_39_reg)=data)
#define set_RSA_X_40_reg(data)   (*((volatile unsigned int*) RSA_X_40_reg)=data)
#define set_RSA_X_41_reg(data)   (*((volatile unsigned int*) RSA_X_41_reg)=data)
#define set_RSA_X_42_reg(data)   (*((volatile unsigned int*) RSA_X_42_reg)=data)
#define set_RSA_X_43_reg(data)   (*((volatile unsigned int*) RSA_X_43_reg)=data)
#define set_RSA_X_44_reg(data)   (*((volatile unsigned int*) RSA_X_44_reg)=data)
#define set_RSA_X_45_reg(data)   (*((volatile unsigned int*) RSA_X_45_reg)=data)
#define set_RSA_X_46_reg(data)   (*((volatile unsigned int*) RSA_X_46_reg)=data)
#define set_RSA_X_47_reg(data)   (*((volatile unsigned int*) RSA_X_47_reg)=data)
#define set_RSA_X_48_reg(data)   (*((volatile unsigned int*) RSA_X_48_reg)=data)
#define set_RSA_X_49_reg(data)   (*((volatile unsigned int*) RSA_X_49_reg)=data)
#define set_RSA_X_50_reg(data)   (*((volatile unsigned int*) RSA_X_50_reg)=data)
#define set_RSA_X_51_reg(data)   (*((volatile unsigned int*) RSA_X_51_reg)=data)
#define set_RSA_X_52_reg(data)   (*((volatile unsigned int*) RSA_X_52_reg)=data)
#define set_RSA_X_53_reg(data)   (*((volatile unsigned int*) RSA_X_53_reg)=data)
#define set_RSA_X_54_reg(data)   (*((volatile unsigned int*) RSA_X_54_reg)=data)
#define set_RSA_X_55_reg(data)   (*((volatile unsigned int*) RSA_X_55_reg)=data)
#define set_RSA_X_56_reg(data)   (*((volatile unsigned int*) RSA_X_56_reg)=data)
#define set_RSA_X_57_reg(data)   (*((volatile unsigned int*) RSA_X_57_reg)=data)
#define set_RSA_X_58_reg(data)   (*((volatile unsigned int*) RSA_X_58_reg)=data)
#define set_RSA_X_59_reg(data)   (*((volatile unsigned int*) RSA_X_59_reg)=data)
#define set_RSA_X_60_reg(data)   (*((volatile unsigned int*) RSA_X_60_reg)=data)
#define set_RSA_X_61_reg(data)   (*((volatile unsigned int*) RSA_X_61_reg)=data)
#define set_RSA_X_62_reg(data)   (*((volatile unsigned int*) RSA_X_62_reg)=data)
#define set_RSA_X_63_reg(data)   (*((volatile unsigned int*) RSA_X_63_reg)=data)
#define get_RSA_X_0_reg   (*((volatile unsigned int*) RSA_X_0_reg))
#define get_RSA_X_1_reg   (*((volatile unsigned int*) RSA_X_1_reg))
#define get_RSA_X_2_reg   (*((volatile unsigned int*) RSA_X_2_reg))
#define get_RSA_X_3_reg   (*((volatile unsigned int*) RSA_X_3_reg))
#define get_RSA_X_4_reg   (*((volatile unsigned int*) RSA_X_4_reg))
#define get_RSA_X_5_reg   (*((volatile unsigned int*) RSA_X_5_reg))
#define get_RSA_X_6_reg   (*((volatile unsigned int*) RSA_X_6_reg))
#define get_RSA_X_7_reg   (*((volatile unsigned int*) RSA_X_7_reg))
#define get_RSA_X_8_reg   (*((volatile unsigned int*) RSA_X_8_reg))
#define get_RSA_X_9_reg   (*((volatile unsigned int*) RSA_X_9_reg))
#define get_RSA_X_10_reg   (*((volatile unsigned int*) RSA_X_10_reg))
#define get_RSA_X_11_reg   (*((volatile unsigned int*) RSA_X_11_reg))
#define get_RSA_X_12_reg   (*((volatile unsigned int*) RSA_X_12_reg))
#define get_RSA_X_13_reg   (*((volatile unsigned int*) RSA_X_13_reg))
#define get_RSA_X_14_reg   (*((volatile unsigned int*) RSA_X_14_reg))
#define get_RSA_X_15_reg   (*((volatile unsigned int*) RSA_X_15_reg))
#define get_RSA_X_16_reg   (*((volatile unsigned int*) RSA_X_16_reg))
#define get_RSA_X_17_reg   (*((volatile unsigned int*) RSA_X_17_reg))
#define get_RSA_X_18_reg   (*((volatile unsigned int*) RSA_X_18_reg))
#define get_RSA_X_19_reg   (*((volatile unsigned int*) RSA_X_19_reg))
#define get_RSA_X_20_reg   (*((volatile unsigned int*) RSA_X_20_reg))
#define get_RSA_X_21_reg   (*((volatile unsigned int*) RSA_X_21_reg))
#define get_RSA_X_22_reg   (*((volatile unsigned int*) RSA_X_22_reg))
#define get_RSA_X_23_reg   (*((volatile unsigned int*) RSA_X_23_reg))
#define get_RSA_X_24_reg   (*((volatile unsigned int*) RSA_X_24_reg))
#define get_RSA_X_25_reg   (*((volatile unsigned int*) RSA_X_25_reg))
#define get_RSA_X_26_reg   (*((volatile unsigned int*) RSA_X_26_reg))
#define get_RSA_X_27_reg   (*((volatile unsigned int*) RSA_X_27_reg))
#define get_RSA_X_28_reg   (*((volatile unsigned int*) RSA_X_28_reg))
#define get_RSA_X_29_reg   (*((volatile unsigned int*) RSA_X_29_reg))
#define get_RSA_X_30_reg   (*((volatile unsigned int*) RSA_X_30_reg))
#define get_RSA_X_31_reg   (*((volatile unsigned int*) RSA_X_31_reg))
#define get_RSA_X_32_reg   (*((volatile unsigned int*) RSA_X_32_reg))
#define get_RSA_X_33_reg   (*((volatile unsigned int*) RSA_X_33_reg))
#define get_RSA_X_34_reg   (*((volatile unsigned int*) RSA_X_34_reg))
#define get_RSA_X_35_reg   (*((volatile unsigned int*) RSA_X_35_reg))
#define get_RSA_X_36_reg   (*((volatile unsigned int*) RSA_X_36_reg))
#define get_RSA_X_37_reg   (*((volatile unsigned int*) RSA_X_37_reg))
#define get_RSA_X_38_reg   (*((volatile unsigned int*) RSA_X_38_reg))
#define get_RSA_X_39_reg   (*((volatile unsigned int*) RSA_X_39_reg))
#define get_RSA_X_40_reg   (*((volatile unsigned int*) RSA_X_40_reg))
#define get_RSA_X_41_reg   (*((volatile unsigned int*) RSA_X_41_reg))
#define get_RSA_X_42_reg   (*((volatile unsigned int*) RSA_X_42_reg))
#define get_RSA_X_43_reg   (*((volatile unsigned int*) RSA_X_43_reg))
#define get_RSA_X_44_reg   (*((volatile unsigned int*) RSA_X_44_reg))
#define get_RSA_X_45_reg   (*((volatile unsigned int*) RSA_X_45_reg))
#define get_RSA_X_46_reg   (*((volatile unsigned int*) RSA_X_46_reg))
#define get_RSA_X_47_reg   (*((volatile unsigned int*) RSA_X_47_reg))
#define get_RSA_X_48_reg   (*((volatile unsigned int*) RSA_X_48_reg))
#define get_RSA_X_49_reg   (*((volatile unsigned int*) RSA_X_49_reg))
#define get_RSA_X_50_reg   (*((volatile unsigned int*) RSA_X_50_reg))
#define get_RSA_X_51_reg   (*((volatile unsigned int*) RSA_X_51_reg))
#define get_RSA_X_52_reg   (*((volatile unsigned int*) RSA_X_52_reg))
#define get_RSA_X_53_reg   (*((volatile unsigned int*) RSA_X_53_reg))
#define get_RSA_X_54_reg   (*((volatile unsigned int*) RSA_X_54_reg))
#define get_RSA_X_55_reg   (*((volatile unsigned int*) RSA_X_55_reg))
#define get_RSA_X_56_reg   (*((volatile unsigned int*) RSA_X_56_reg))
#define get_RSA_X_57_reg   (*((volatile unsigned int*) RSA_X_57_reg))
#define get_RSA_X_58_reg   (*((volatile unsigned int*) RSA_X_58_reg))
#define get_RSA_X_59_reg   (*((volatile unsigned int*) RSA_X_59_reg))
#define get_RSA_X_60_reg   (*((volatile unsigned int*) RSA_X_60_reg))
#define get_RSA_X_61_reg   (*((volatile unsigned int*) RSA_X_61_reg))
#define get_RSA_X_62_reg   (*((volatile unsigned int*) RSA_X_62_reg))
#define get_RSA_X_63_reg   (*((volatile unsigned int*) RSA_X_63_reg))
#define RSA_X_0_inst_adr                                                             "0x0000"
#define RSA_X_1_inst_adr                                                             "0x0001"
#define RSA_X_2_inst_adr                                                             "0x0002"
#define RSA_X_3_inst_adr                                                             "0x0003"
#define RSA_X_4_inst_adr                                                             "0x0004"
#define RSA_X_5_inst_adr                                                             "0x0005"
#define RSA_X_6_inst_adr                                                             "0x0006"
#define RSA_X_7_inst_adr                                                             "0x0007"
#define RSA_X_8_inst_adr                                                             "0x0008"
#define RSA_X_9_inst_adr                                                             "0x0009"
#define RSA_X_10_inst_adr                                                             "0x000A"
#define RSA_X_11_inst_adr                                                             "0x000B"
#define RSA_X_12_inst_adr                                                             "0x000C"
#define RSA_X_13_inst_adr                                                             "0x000D"
#define RSA_X_14_inst_adr                                                             "0x000E"
#define RSA_X_15_inst_adr                                                             "0x000F"
#define RSA_X_16_inst_adr                                                             "0x0010"
#define RSA_X_17_inst_adr                                                             "0x0011"
#define RSA_X_18_inst_adr                                                             "0x0012"
#define RSA_X_19_inst_adr                                                             "0x0013"
#define RSA_X_20_inst_adr                                                             "0x0014"
#define RSA_X_21_inst_adr                                                             "0x0015"
#define RSA_X_22_inst_adr                                                             "0x0016"
#define RSA_X_23_inst_adr                                                             "0x0017"
#define RSA_X_24_inst_adr                                                             "0x0018"
#define RSA_X_25_inst_adr                                                             "0x0019"
#define RSA_X_26_inst_adr                                                             "0x001A"
#define RSA_X_27_inst_adr                                                             "0x001B"
#define RSA_X_28_inst_adr                                                             "0x001C"
#define RSA_X_29_inst_adr                                                             "0x001D"
#define RSA_X_30_inst_adr                                                             "0x001E"
#define RSA_X_31_inst_adr                                                             "0x001F"
#define RSA_X_32_inst_adr                                                             "0x0020"
#define RSA_X_33_inst_adr                                                             "0x0021"
#define RSA_X_34_inst_adr                                                             "0x0022"
#define RSA_X_35_inst_adr                                                             "0x0023"
#define RSA_X_36_inst_adr                                                             "0x0024"
#define RSA_X_37_inst_adr                                                             "0x0025"
#define RSA_X_38_inst_adr                                                             "0x0026"
#define RSA_X_39_inst_adr                                                             "0x0027"
#define RSA_X_40_inst_adr                                                             "0x0028"
#define RSA_X_41_inst_adr                                                             "0x0029"
#define RSA_X_42_inst_adr                                                             "0x002A"
#define RSA_X_43_inst_adr                                                             "0x002B"
#define RSA_X_44_inst_adr                                                             "0x002C"
#define RSA_X_45_inst_adr                                                             "0x002D"
#define RSA_X_46_inst_adr                                                             "0x002E"
#define RSA_X_47_inst_adr                                                             "0x002F"
#define RSA_X_48_inst_adr                                                             "0x0030"
#define RSA_X_49_inst_adr                                                             "0x0031"
#define RSA_X_50_inst_adr                                                             "0x0032"
#define RSA_X_51_inst_adr                                                             "0x0033"
#define RSA_X_52_inst_adr                                                             "0x0034"
#define RSA_X_53_inst_adr                                                             "0x0035"
#define RSA_X_54_inst_adr                                                             "0x0036"
#define RSA_X_55_inst_adr                                                             "0x0037"
#define RSA_X_56_inst_adr                                                             "0x0038"
#define RSA_X_57_inst_adr                                                             "0x0039"
#define RSA_X_58_inst_adr                                                             "0x003A"
#define RSA_X_59_inst_adr                                                             "0x003B"
#define RSA_X_60_inst_adr                                                             "0x003C"
#define RSA_X_61_inst_adr                                                             "0x003D"
#define RSA_X_62_inst_adr                                                             "0x003E"
#define RSA_X_63_inst_adr                                                             "0x003F"
#define RSA_X_0_inst                                                                 0x0000
#define RSA_X_1_inst                                                                 0x0001
#define RSA_X_2_inst                                                                 0x0002
#define RSA_X_3_inst                                                                 0x0003
#define RSA_X_4_inst                                                                 0x0004
#define RSA_X_5_inst                                                                 0x0005
#define RSA_X_6_inst                                                                 0x0006
#define RSA_X_7_inst                                                                 0x0007
#define RSA_X_8_inst                                                                 0x0008
#define RSA_X_9_inst                                                                 0x0009
#define RSA_X_10_inst                                                                 0x000A
#define RSA_X_11_inst                                                                 0x000B
#define RSA_X_12_inst                                                                 0x000C
#define RSA_X_13_inst                                                                 0x000D
#define RSA_X_14_inst                                                                 0x000E
#define RSA_X_15_inst                                                                 0x000F
#define RSA_X_16_inst                                                                 0x0010
#define RSA_X_17_inst                                                                 0x0011
#define RSA_X_18_inst                                                                 0x0012
#define RSA_X_19_inst                                                                 0x0013
#define RSA_X_20_inst                                                                 0x0014
#define RSA_X_21_inst                                                                 0x0015
#define RSA_X_22_inst                                                                 0x0016
#define RSA_X_23_inst                                                                 0x0017
#define RSA_X_24_inst                                                                 0x0018
#define RSA_X_25_inst                                                                 0x0019
#define RSA_X_26_inst                                                                 0x001A
#define RSA_X_27_inst                                                                 0x001B
#define RSA_X_28_inst                                                                 0x001C
#define RSA_X_29_inst                                                                 0x001D
#define RSA_X_30_inst                                                                 0x001E
#define RSA_X_31_inst                                                                 0x001F
#define RSA_X_32_inst                                                                 0x0020
#define RSA_X_33_inst                                                                 0x0021
#define RSA_X_34_inst                                                                 0x0022
#define RSA_X_35_inst                                                                 0x0023
#define RSA_X_36_inst                                                                 0x0024
#define RSA_X_37_inst                                                                 0x0025
#define RSA_X_38_inst                                                                 0x0026
#define RSA_X_39_inst                                                                 0x0027
#define RSA_X_40_inst                                                                 0x0028
#define RSA_X_41_inst                                                                 0x0029
#define RSA_X_42_inst                                                                 0x002A
#define RSA_X_43_inst                                                                 0x002B
#define RSA_X_44_inst                                                                 0x002C
#define RSA_X_45_inst                                                                 0x002D
#define RSA_X_46_inst                                                                 0x002E
#define RSA_X_47_inst                                                                 0x002F
#define RSA_X_48_inst                                                                 0x0030
#define RSA_X_49_inst                                                                 0x0031
#define RSA_X_50_inst                                                                 0x0032
#define RSA_X_51_inst                                                                 0x0033
#define RSA_X_52_inst                                                                 0x0034
#define RSA_X_53_inst                                                                 0x0035
#define RSA_X_54_inst                                                                 0x0036
#define RSA_X_55_inst                                                                 0x0037
#define RSA_X_56_inst                                                                 0x0038
#define RSA_X_57_inst                                                                 0x0039
#define RSA_X_58_inst                                                                 0x003A
#define RSA_X_59_inst                                                                 0x003B
#define RSA_X_60_inst                                                                 0x003C
#define RSA_X_61_inst                                                                 0x003D
#define RSA_X_62_inst                                                                 0x003E
#define RSA_X_63_inst                                                                 0x003F
#define RSA_X_data_shift                                                             (0)
#define RSA_X_data_mask                                                              (0xFFFFFFFF)
#define RSA_X_data(data)                                                             (0xFFFFFFFF&((data)<<0))
#define RSA_X_data_src(data)                                                         ((0xFFFFFFFF&(data))>>0)
#define RSA_X_get_data(data)                                                         ((0xFFFFFFFF&(data))>>0)


#define RSA_Y_0                                                                      0x1806E100
#define RSA_Y_1                                                                      0x1806E104
#define RSA_Y_2                                                                      0x1806E108
#define RSA_Y_3                                                                      0x1806E10C
#define RSA_Y_4                                                                      0x1806E110
#define RSA_Y_5                                                                      0x1806E114
#define RSA_Y_6                                                                      0x1806E118
#define RSA_Y_7                                                                      0x1806E11C
#define RSA_Y_8                                                                      0x1806E120
#define RSA_Y_9                                                                      0x1806E124
#define RSA_Y_10                                                                      0x1806E128
#define RSA_Y_11                                                                      0x1806E12C
#define RSA_Y_12                                                                      0x1806E130
#define RSA_Y_13                                                                      0x1806E134
#define RSA_Y_14                                                                      0x1806E138
#define RSA_Y_15                                                                      0x1806E13C
#define RSA_Y_16                                                                      0x1806E140
#define RSA_Y_17                                                                      0x1806E144
#define RSA_Y_18                                                                      0x1806E148
#define RSA_Y_19                                                                      0x1806E14C
#define RSA_Y_20                                                                      0x1806E150
#define RSA_Y_21                                                                      0x1806E154
#define RSA_Y_22                                                                      0x1806E158
#define RSA_Y_23                                                                      0x1806E15C
#define RSA_Y_24                                                                      0x1806E160
#define RSA_Y_25                                                                      0x1806E164
#define RSA_Y_26                                                                      0x1806E168
#define RSA_Y_27                                                                      0x1806E16C
#define RSA_Y_28                                                                      0x1806E170
#define RSA_Y_29                                                                      0x1806E174
#define RSA_Y_30                                                                      0x1806E178
#define RSA_Y_31                                                                      0x1806E17C
#define RSA_Y_32                                                                      0x1806E180
#define RSA_Y_33                                                                      0x1806E184
#define RSA_Y_34                                                                      0x1806E188
#define RSA_Y_35                                                                      0x1806E18C
#define RSA_Y_36                                                                      0x1806E190
#define RSA_Y_37                                                                      0x1806E194
#define RSA_Y_38                                                                      0x1806E198
#define RSA_Y_39                                                                      0x1806E19C
#define RSA_Y_40                                                                      0x1806E1A0
#define RSA_Y_41                                                                      0x1806E1A4
#define RSA_Y_42                                                                      0x1806E1A8
#define RSA_Y_43                                                                      0x1806E1AC
#define RSA_Y_44                                                                      0x1806E1B0
#define RSA_Y_45                                                                      0x1806E1B4
#define RSA_Y_46                                                                      0x1806E1B8
#define RSA_Y_47                                                                      0x1806E1BC
#define RSA_Y_48                                                                      0x1806E1C0
#define RSA_Y_49                                                                      0x1806E1C4
#define RSA_Y_50                                                                      0x1806E1C8
#define RSA_Y_51                                                                      0x1806E1CC
#define RSA_Y_52                                                                      0x1806E1D0
#define RSA_Y_53                                                                      0x1806E1D4
#define RSA_Y_54                                                                      0x1806E1D8
#define RSA_Y_55                                                                      0x1806E1DC
#define RSA_Y_56                                                                      0x1806E1E0
#define RSA_Y_57                                                                      0x1806E1E4
#define RSA_Y_58                                                                      0x1806E1E8
#define RSA_Y_59                                                                      0x1806E1EC
#define RSA_Y_60                                                                      0x1806E1F0
#define RSA_Y_61                                                                      0x1806E1F4
#define RSA_Y_62                                                                      0x1806E1F8
#define RSA_Y_63                                                                      0x1806E1FC
#define RSA_Y_0_reg_addr                                                             "0xB806E100"
#define RSA_Y_1_reg_addr                                                             "0xB806E104"
#define RSA_Y_2_reg_addr                                                             "0xB806E108"
#define RSA_Y_3_reg_addr                                                             "0xB806E10C"
#define RSA_Y_4_reg_addr                                                             "0xB806E110"
#define RSA_Y_5_reg_addr                                                             "0xB806E114"
#define RSA_Y_6_reg_addr                                                             "0xB806E118"
#define RSA_Y_7_reg_addr                                                             "0xB806E11C"
#define RSA_Y_8_reg_addr                                                             "0xB806E120"
#define RSA_Y_9_reg_addr                                                             "0xB806E124"
#define RSA_Y_10_reg_addr                                                             "0xB806E128"
#define RSA_Y_11_reg_addr                                                             "0xB806E12C"
#define RSA_Y_12_reg_addr                                                             "0xB806E130"
#define RSA_Y_13_reg_addr                                                             "0xB806E134"
#define RSA_Y_14_reg_addr                                                             "0xB806E138"
#define RSA_Y_15_reg_addr                                                             "0xB806E13C"
#define RSA_Y_16_reg_addr                                                             "0xB806E140"
#define RSA_Y_17_reg_addr                                                             "0xB806E144"
#define RSA_Y_18_reg_addr                                                             "0xB806E148"
#define RSA_Y_19_reg_addr                                                             "0xB806E14C"
#define RSA_Y_20_reg_addr                                                             "0xB806E150"
#define RSA_Y_21_reg_addr                                                             "0xB806E154"
#define RSA_Y_22_reg_addr                                                             "0xB806E158"
#define RSA_Y_23_reg_addr                                                             "0xB806E15C"
#define RSA_Y_24_reg_addr                                                             "0xB806E160"
#define RSA_Y_25_reg_addr                                                             "0xB806E164"
#define RSA_Y_26_reg_addr                                                             "0xB806E168"
#define RSA_Y_27_reg_addr                                                             "0xB806E16C"
#define RSA_Y_28_reg_addr                                                             "0xB806E170"
#define RSA_Y_29_reg_addr                                                             "0xB806E174"
#define RSA_Y_30_reg_addr                                                             "0xB806E178"
#define RSA_Y_31_reg_addr                                                             "0xB806E17C"
#define RSA_Y_32_reg_addr                                                             "0xB806E180"
#define RSA_Y_33_reg_addr                                                             "0xB806E184"
#define RSA_Y_34_reg_addr                                                             "0xB806E188"
#define RSA_Y_35_reg_addr                                                             "0xB806E18C"
#define RSA_Y_36_reg_addr                                                             "0xB806E190"
#define RSA_Y_37_reg_addr                                                             "0xB806E194"
#define RSA_Y_38_reg_addr                                                             "0xB806E198"
#define RSA_Y_39_reg_addr                                                             "0xB806E19C"
#define RSA_Y_40_reg_addr                                                             "0xB806E1A0"
#define RSA_Y_41_reg_addr                                                             "0xB806E1A4"
#define RSA_Y_42_reg_addr                                                             "0xB806E1A8"
#define RSA_Y_43_reg_addr                                                             "0xB806E1AC"
#define RSA_Y_44_reg_addr                                                             "0xB806E1B0"
#define RSA_Y_45_reg_addr                                                             "0xB806E1B4"
#define RSA_Y_46_reg_addr                                                             "0xB806E1B8"
#define RSA_Y_47_reg_addr                                                             "0xB806E1BC"
#define RSA_Y_48_reg_addr                                                             "0xB806E1C0"
#define RSA_Y_49_reg_addr                                                             "0xB806E1C4"
#define RSA_Y_50_reg_addr                                                             "0xB806E1C8"
#define RSA_Y_51_reg_addr                                                             "0xB806E1CC"
#define RSA_Y_52_reg_addr                                                             "0xB806E1D0"
#define RSA_Y_53_reg_addr                                                             "0xB806E1D4"
#define RSA_Y_54_reg_addr                                                             "0xB806E1D8"
#define RSA_Y_55_reg_addr                                                             "0xB806E1DC"
#define RSA_Y_56_reg_addr                                                             "0xB806E1E0"
#define RSA_Y_57_reg_addr                                                             "0xB806E1E4"
#define RSA_Y_58_reg_addr                                                             "0xB806E1E8"
#define RSA_Y_59_reg_addr                                                             "0xB806E1EC"
#define RSA_Y_60_reg_addr                                                             "0xB806E1F0"
#define RSA_Y_61_reg_addr                                                             "0xB806E1F4"
#define RSA_Y_62_reg_addr                                                             "0xB806E1F8"
#define RSA_Y_63_reg_addr                                                             "0xB806E1FC"
#define RSA_Y_0_reg                                                                  0xB806E100
#define RSA_Y_1_reg                                                                  0xB806E104
#define RSA_Y_2_reg                                                                  0xB806E108
#define RSA_Y_3_reg                                                                  0xB806E10C
#define RSA_Y_4_reg                                                                  0xB806E110
#define RSA_Y_5_reg                                                                  0xB806E114
#define RSA_Y_6_reg                                                                  0xB806E118
#define RSA_Y_7_reg                                                                  0xB806E11C
#define RSA_Y_8_reg                                                                  0xB806E120
#define RSA_Y_9_reg                                                                  0xB806E124
#define RSA_Y_10_reg                                                                  0xB806E128
#define RSA_Y_11_reg                                                                  0xB806E12C
#define RSA_Y_12_reg                                                                  0xB806E130
#define RSA_Y_13_reg                                                                  0xB806E134
#define RSA_Y_14_reg                                                                  0xB806E138
#define RSA_Y_15_reg                                                                  0xB806E13C
#define RSA_Y_16_reg                                                                  0xB806E140
#define RSA_Y_17_reg                                                                  0xB806E144
#define RSA_Y_18_reg                                                                  0xB806E148
#define RSA_Y_19_reg                                                                  0xB806E14C
#define RSA_Y_20_reg                                                                  0xB806E150
#define RSA_Y_21_reg                                                                  0xB806E154
#define RSA_Y_22_reg                                                                  0xB806E158
#define RSA_Y_23_reg                                                                  0xB806E15C
#define RSA_Y_24_reg                                                                  0xB806E160
#define RSA_Y_25_reg                                                                  0xB806E164
#define RSA_Y_26_reg                                                                  0xB806E168
#define RSA_Y_27_reg                                                                  0xB806E16C
#define RSA_Y_28_reg                                                                  0xB806E170
#define RSA_Y_29_reg                                                                  0xB806E174
#define RSA_Y_30_reg                                                                  0xB806E178
#define RSA_Y_31_reg                                                                  0xB806E17C
#define RSA_Y_32_reg                                                                  0xB806E180
#define RSA_Y_33_reg                                                                  0xB806E184
#define RSA_Y_34_reg                                                                  0xB806E188
#define RSA_Y_35_reg                                                                  0xB806E18C
#define RSA_Y_36_reg                                                                  0xB806E190
#define RSA_Y_37_reg                                                                  0xB806E194
#define RSA_Y_38_reg                                                                  0xB806E198
#define RSA_Y_39_reg                                                                  0xB806E19C
#define RSA_Y_40_reg                                                                  0xB806E1A0
#define RSA_Y_41_reg                                                                  0xB806E1A4
#define RSA_Y_42_reg                                                                  0xB806E1A8
#define RSA_Y_43_reg                                                                  0xB806E1AC
#define RSA_Y_44_reg                                                                  0xB806E1B0
#define RSA_Y_45_reg                                                                  0xB806E1B4
#define RSA_Y_46_reg                                                                  0xB806E1B8
#define RSA_Y_47_reg                                                                  0xB806E1BC
#define RSA_Y_48_reg                                                                  0xB806E1C0
#define RSA_Y_49_reg                                                                  0xB806E1C4
#define RSA_Y_50_reg                                                                  0xB806E1C8
#define RSA_Y_51_reg                                                                  0xB806E1CC
#define RSA_Y_52_reg                                                                  0xB806E1D0
#define RSA_Y_53_reg                                                                  0xB806E1D4
#define RSA_Y_54_reg                                                                  0xB806E1D8
#define RSA_Y_55_reg                                                                  0xB806E1DC
#define RSA_Y_56_reg                                                                  0xB806E1E0
#define RSA_Y_57_reg                                                                  0xB806E1E4
#define RSA_Y_58_reg                                                                  0xB806E1E8
#define RSA_Y_59_reg                                                                  0xB806E1EC
#define RSA_Y_60_reg                                                                  0xB806E1F0
#define RSA_Y_61_reg                                                                  0xB806E1F4
#define RSA_Y_62_reg                                                                  0xB806E1F8
#define RSA_Y_63_reg                                                                  0xB806E1FC
#define set_RSA_Y_0_reg(data)   (*((volatile unsigned int*) RSA_Y_0_reg)=data)
#define set_RSA_Y_1_reg(data)   (*((volatile unsigned int*) RSA_Y_1_reg)=data)
#define set_RSA_Y_2_reg(data)   (*((volatile unsigned int*) RSA_Y_2_reg)=data)
#define set_RSA_Y_3_reg(data)   (*((volatile unsigned int*) RSA_Y_3_reg)=data)
#define set_RSA_Y_4_reg(data)   (*((volatile unsigned int*) RSA_Y_4_reg)=data)
#define set_RSA_Y_5_reg(data)   (*((volatile unsigned int*) RSA_Y_5_reg)=data)
#define set_RSA_Y_6_reg(data)   (*((volatile unsigned int*) RSA_Y_6_reg)=data)
#define set_RSA_Y_7_reg(data)   (*((volatile unsigned int*) RSA_Y_7_reg)=data)
#define set_RSA_Y_8_reg(data)   (*((volatile unsigned int*) RSA_Y_8_reg)=data)
#define set_RSA_Y_9_reg(data)   (*((volatile unsigned int*) RSA_Y_9_reg)=data)
#define set_RSA_Y_10_reg(data)   (*((volatile unsigned int*) RSA_Y_10_reg)=data)
#define set_RSA_Y_11_reg(data)   (*((volatile unsigned int*) RSA_Y_11_reg)=data)
#define set_RSA_Y_12_reg(data)   (*((volatile unsigned int*) RSA_Y_12_reg)=data)
#define set_RSA_Y_13_reg(data)   (*((volatile unsigned int*) RSA_Y_13_reg)=data)
#define set_RSA_Y_14_reg(data)   (*((volatile unsigned int*) RSA_Y_14_reg)=data)
#define set_RSA_Y_15_reg(data)   (*((volatile unsigned int*) RSA_Y_15_reg)=data)
#define set_RSA_Y_16_reg(data)   (*((volatile unsigned int*) RSA_Y_16_reg)=data)
#define set_RSA_Y_17_reg(data)   (*((volatile unsigned int*) RSA_Y_17_reg)=data)
#define set_RSA_Y_18_reg(data)   (*((volatile unsigned int*) RSA_Y_18_reg)=data)
#define set_RSA_Y_19_reg(data)   (*((volatile unsigned int*) RSA_Y_19_reg)=data)
#define set_RSA_Y_20_reg(data)   (*((volatile unsigned int*) RSA_Y_20_reg)=data)
#define set_RSA_Y_21_reg(data)   (*((volatile unsigned int*) RSA_Y_21_reg)=data)
#define set_RSA_Y_22_reg(data)   (*((volatile unsigned int*) RSA_Y_22_reg)=data)
#define set_RSA_Y_23_reg(data)   (*((volatile unsigned int*) RSA_Y_23_reg)=data)
#define set_RSA_Y_24_reg(data)   (*((volatile unsigned int*) RSA_Y_24_reg)=data)
#define set_RSA_Y_25_reg(data)   (*((volatile unsigned int*) RSA_Y_25_reg)=data)
#define set_RSA_Y_26_reg(data)   (*((volatile unsigned int*) RSA_Y_26_reg)=data)
#define set_RSA_Y_27_reg(data)   (*((volatile unsigned int*) RSA_Y_27_reg)=data)
#define set_RSA_Y_28_reg(data)   (*((volatile unsigned int*) RSA_Y_28_reg)=data)
#define set_RSA_Y_29_reg(data)   (*((volatile unsigned int*) RSA_Y_29_reg)=data)
#define set_RSA_Y_30_reg(data)   (*((volatile unsigned int*) RSA_Y_30_reg)=data)
#define set_RSA_Y_31_reg(data)   (*((volatile unsigned int*) RSA_Y_31_reg)=data)
#define set_RSA_Y_32_reg(data)   (*((volatile unsigned int*) RSA_Y_32_reg)=data)
#define set_RSA_Y_33_reg(data)   (*((volatile unsigned int*) RSA_Y_33_reg)=data)
#define set_RSA_Y_34_reg(data)   (*((volatile unsigned int*) RSA_Y_34_reg)=data)
#define set_RSA_Y_35_reg(data)   (*((volatile unsigned int*) RSA_Y_35_reg)=data)
#define set_RSA_Y_36_reg(data)   (*((volatile unsigned int*) RSA_Y_36_reg)=data)
#define set_RSA_Y_37_reg(data)   (*((volatile unsigned int*) RSA_Y_37_reg)=data)
#define set_RSA_Y_38_reg(data)   (*((volatile unsigned int*) RSA_Y_38_reg)=data)
#define set_RSA_Y_39_reg(data)   (*((volatile unsigned int*) RSA_Y_39_reg)=data)
#define set_RSA_Y_40_reg(data)   (*((volatile unsigned int*) RSA_Y_40_reg)=data)
#define set_RSA_Y_41_reg(data)   (*((volatile unsigned int*) RSA_Y_41_reg)=data)
#define set_RSA_Y_42_reg(data)   (*((volatile unsigned int*) RSA_Y_42_reg)=data)
#define set_RSA_Y_43_reg(data)   (*((volatile unsigned int*) RSA_Y_43_reg)=data)
#define set_RSA_Y_44_reg(data)   (*((volatile unsigned int*) RSA_Y_44_reg)=data)
#define set_RSA_Y_45_reg(data)   (*((volatile unsigned int*) RSA_Y_45_reg)=data)
#define set_RSA_Y_46_reg(data)   (*((volatile unsigned int*) RSA_Y_46_reg)=data)
#define set_RSA_Y_47_reg(data)   (*((volatile unsigned int*) RSA_Y_47_reg)=data)
#define set_RSA_Y_48_reg(data)   (*((volatile unsigned int*) RSA_Y_48_reg)=data)
#define set_RSA_Y_49_reg(data)   (*((volatile unsigned int*) RSA_Y_49_reg)=data)
#define set_RSA_Y_50_reg(data)   (*((volatile unsigned int*) RSA_Y_50_reg)=data)
#define set_RSA_Y_51_reg(data)   (*((volatile unsigned int*) RSA_Y_51_reg)=data)
#define set_RSA_Y_52_reg(data)   (*((volatile unsigned int*) RSA_Y_52_reg)=data)
#define set_RSA_Y_53_reg(data)   (*((volatile unsigned int*) RSA_Y_53_reg)=data)
#define set_RSA_Y_54_reg(data)   (*((volatile unsigned int*) RSA_Y_54_reg)=data)
#define set_RSA_Y_55_reg(data)   (*((volatile unsigned int*) RSA_Y_55_reg)=data)
#define set_RSA_Y_56_reg(data)   (*((volatile unsigned int*) RSA_Y_56_reg)=data)
#define set_RSA_Y_57_reg(data)   (*((volatile unsigned int*) RSA_Y_57_reg)=data)
#define set_RSA_Y_58_reg(data)   (*((volatile unsigned int*) RSA_Y_58_reg)=data)
#define set_RSA_Y_59_reg(data)   (*((volatile unsigned int*) RSA_Y_59_reg)=data)
#define set_RSA_Y_60_reg(data)   (*((volatile unsigned int*) RSA_Y_60_reg)=data)
#define set_RSA_Y_61_reg(data)   (*((volatile unsigned int*) RSA_Y_61_reg)=data)
#define set_RSA_Y_62_reg(data)   (*((volatile unsigned int*) RSA_Y_62_reg)=data)
#define set_RSA_Y_63_reg(data)   (*((volatile unsigned int*) RSA_Y_63_reg)=data)
#define get_RSA_Y_0_reg   (*((volatile unsigned int*) RSA_Y_0_reg))
#define get_RSA_Y_1_reg   (*((volatile unsigned int*) RSA_Y_1_reg))
#define get_RSA_Y_2_reg   (*((volatile unsigned int*) RSA_Y_2_reg))
#define get_RSA_Y_3_reg   (*((volatile unsigned int*) RSA_Y_3_reg))
#define get_RSA_Y_4_reg   (*((volatile unsigned int*) RSA_Y_4_reg))
#define get_RSA_Y_5_reg   (*((volatile unsigned int*) RSA_Y_5_reg))
#define get_RSA_Y_6_reg   (*((volatile unsigned int*) RSA_Y_6_reg))
#define get_RSA_Y_7_reg   (*((volatile unsigned int*) RSA_Y_7_reg))
#define get_RSA_Y_8_reg   (*((volatile unsigned int*) RSA_Y_8_reg))
#define get_RSA_Y_9_reg   (*((volatile unsigned int*) RSA_Y_9_reg))
#define get_RSA_Y_10_reg   (*((volatile unsigned int*) RSA_Y_10_reg))
#define get_RSA_Y_11_reg   (*((volatile unsigned int*) RSA_Y_11_reg))
#define get_RSA_Y_12_reg   (*((volatile unsigned int*) RSA_Y_12_reg))
#define get_RSA_Y_13_reg   (*((volatile unsigned int*) RSA_Y_13_reg))
#define get_RSA_Y_14_reg   (*((volatile unsigned int*) RSA_Y_14_reg))
#define get_RSA_Y_15_reg   (*((volatile unsigned int*) RSA_Y_15_reg))
#define get_RSA_Y_16_reg   (*((volatile unsigned int*) RSA_Y_16_reg))
#define get_RSA_Y_17_reg   (*((volatile unsigned int*) RSA_Y_17_reg))
#define get_RSA_Y_18_reg   (*((volatile unsigned int*) RSA_Y_18_reg))
#define get_RSA_Y_19_reg   (*((volatile unsigned int*) RSA_Y_19_reg))
#define get_RSA_Y_20_reg   (*((volatile unsigned int*) RSA_Y_20_reg))
#define get_RSA_Y_21_reg   (*((volatile unsigned int*) RSA_Y_21_reg))
#define get_RSA_Y_22_reg   (*((volatile unsigned int*) RSA_Y_22_reg))
#define get_RSA_Y_23_reg   (*((volatile unsigned int*) RSA_Y_23_reg))
#define get_RSA_Y_24_reg   (*((volatile unsigned int*) RSA_Y_24_reg))
#define get_RSA_Y_25_reg   (*((volatile unsigned int*) RSA_Y_25_reg))
#define get_RSA_Y_26_reg   (*((volatile unsigned int*) RSA_Y_26_reg))
#define get_RSA_Y_27_reg   (*((volatile unsigned int*) RSA_Y_27_reg))
#define get_RSA_Y_28_reg   (*((volatile unsigned int*) RSA_Y_28_reg))
#define get_RSA_Y_29_reg   (*((volatile unsigned int*) RSA_Y_29_reg))
#define get_RSA_Y_30_reg   (*((volatile unsigned int*) RSA_Y_30_reg))
#define get_RSA_Y_31_reg   (*((volatile unsigned int*) RSA_Y_31_reg))
#define get_RSA_Y_32_reg   (*((volatile unsigned int*) RSA_Y_32_reg))
#define get_RSA_Y_33_reg   (*((volatile unsigned int*) RSA_Y_33_reg))
#define get_RSA_Y_34_reg   (*((volatile unsigned int*) RSA_Y_34_reg))
#define get_RSA_Y_35_reg   (*((volatile unsigned int*) RSA_Y_35_reg))
#define get_RSA_Y_36_reg   (*((volatile unsigned int*) RSA_Y_36_reg))
#define get_RSA_Y_37_reg   (*((volatile unsigned int*) RSA_Y_37_reg))
#define get_RSA_Y_38_reg   (*((volatile unsigned int*) RSA_Y_38_reg))
#define get_RSA_Y_39_reg   (*((volatile unsigned int*) RSA_Y_39_reg))
#define get_RSA_Y_40_reg   (*((volatile unsigned int*) RSA_Y_40_reg))
#define get_RSA_Y_41_reg   (*((volatile unsigned int*) RSA_Y_41_reg))
#define get_RSA_Y_42_reg   (*((volatile unsigned int*) RSA_Y_42_reg))
#define get_RSA_Y_43_reg   (*((volatile unsigned int*) RSA_Y_43_reg))
#define get_RSA_Y_44_reg   (*((volatile unsigned int*) RSA_Y_44_reg))
#define get_RSA_Y_45_reg   (*((volatile unsigned int*) RSA_Y_45_reg))
#define get_RSA_Y_46_reg   (*((volatile unsigned int*) RSA_Y_46_reg))
#define get_RSA_Y_47_reg   (*((volatile unsigned int*) RSA_Y_47_reg))
#define get_RSA_Y_48_reg   (*((volatile unsigned int*) RSA_Y_48_reg))
#define get_RSA_Y_49_reg   (*((volatile unsigned int*) RSA_Y_49_reg))
#define get_RSA_Y_50_reg   (*((volatile unsigned int*) RSA_Y_50_reg))
#define get_RSA_Y_51_reg   (*((volatile unsigned int*) RSA_Y_51_reg))
#define get_RSA_Y_52_reg   (*((volatile unsigned int*) RSA_Y_52_reg))
#define get_RSA_Y_53_reg   (*((volatile unsigned int*) RSA_Y_53_reg))
#define get_RSA_Y_54_reg   (*((volatile unsigned int*) RSA_Y_54_reg))
#define get_RSA_Y_55_reg   (*((volatile unsigned int*) RSA_Y_55_reg))
#define get_RSA_Y_56_reg   (*((volatile unsigned int*) RSA_Y_56_reg))
#define get_RSA_Y_57_reg   (*((volatile unsigned int*) RSA_Y_57_reg))
#define get_RSA_Y_58_reg   (*((volatile unsigned int*) RSA_Y_58_reg))
#define get_RSA_Y_59_reg   (*((volatile unsigned int*) RSA_Y_59_reg))
#define get_RSA_Y_60_reg   (*((volatile unsigned int*) RSA_Y_60_reg))
#define get_RSA_Y_61_reg   (*((volatile unsigned int*) RSA_Y_61_reg))
#define get_RSA_Y_62_reg   (*((volatile unsigned int*) RSA_Y_62_reg))
#define get_RSA_Y_63_reg   (*((volatile unsigned int*) RSA_Y_63_reg))
#define RSA_Y_0_inst_adr                                                             "0x0040"
#define RSA_Y_1_inst_adr                                                             "0x0041"
#define RSA_Y_2_inst_adr                                                             "0x0042"
#define RSA_Y_3_inst_adr                                                             "0x0043"
#define RSA_Y_4_inst_adr                                                             "0x0044"
#define RSA_Y_5_inst_adr                                                             "0x0045"
#define RSA_Y_6_inst_adr                                                             "0x0046"
#define RSA_Y_7_inst_adr                                                             "0x0047"
#define RSA_Y_8_inst_adr                                                             "0x0048"
#define RSA_Y_9_inst_adr                                                             "0x0049"
#define RSA_Y_10_inst_adr                                                             "0x004A"
#define RSA_Y_11_inst_adr                                                             "0x004B"
#define RSA_Y_12_inst_adr                                                             "0x004C"
#define RSA_Y_13_inst_adr                                                             "0x004D"
#define RSA_Y_14_inst_adr                                                             "0x004E"
#define RSA_Y_15_inst_adr                                                             "0x004F"
#define RSA_Y_16_inst_adr                                                             "0x0050"
#define RSA_Y_17_inst_adr                                                             "0x0051"
#define RSA_Y_18_inst_adr                                                             "0x0052"
#define RSA_Y_19_inst_adr                                                             "0x0053"
#define RSA_Y_20_inst_adr                                                             "0x0054"
#define RSA_Y_21_inst_adr                                                             "0x0055"
#define RSA_Y_22_inst_adr                                                             "0x0056"
#define RSA_Y_23_inst_adr                                                             "0x0057"
#define RSA_Y_24_inst_adr                                                             "0x0058"
#define RSA_Y_25_inst_adr                                                             "0x0059"
#define RSA_Y_26_inst_adr                                                             "0x005A"
#define RSA_Y_27_inst_adr                                                             "0x005B"
#define RSA_Y_28_inst_adr                                                             "0x005C"
#define RSA_Y_29_inst_adr                                                             "0x005D"
#define RSA_Y_30_inst_adr                                                             "0x005E"
#define RSA_Y_31_inst_adr                                                             "0x005F"
#define RSA_Y_32_inst_adr                                                             "0x0060"
#define RSA_Y_33_inst_adr                                                             "0x0061"
#define RSA_Y_34_inst_adr                                                             "0x0062"
#define RSA_Y_35_inst_adr                                                             "0x0063"
#define RSA_Y_36_inst_adr                                                             "0x0064"
#define RSA_Y_37_inst_adr                                                             "0x0065"
#define RSA_Y_38_inst_adr                                                             "0x0066"
#define RSA_Y_39_inst_adr                                                             "0x0067"
#define RSA_Y_40_inst_adr                                                             "0x0068"
#define RSA_Y_41_inst_adr                                                             "0x0069"
#define RSA_Y_42_inst_adr                                                             "0x006A"
#define RSA_Y_43_inst_adr                                                             "0x006B"
#define RSA_Y_44_inst_adr                                                             "0x006C"
#define RSA_Y_45_inst_adr                                                             "0x006D"
#define RSA_Y_46_inst_adr                                                             "0x006E"
#define RSA_Y_47_inst_adr                                                             "0x006F"
#define RSA_Y_48_inst_adr                                                             "0x0070"
#define RSA_Y_49_inst_adr                                                             "0x0071"
#define RSA_Y_50_inst_adr                                                             "0x0072"
#define RSA_Y_51_inst_adr                                                             "0x0073"
#define RSA_Y_52_inst_adr                                                             "0x0074"
#define RSA_Y_53_inst_adr                                                             "0x0075"
#define RSA_Y_54_inst_adr                                                             "0x0076"
#define RSA_Y_55_inst_adr                                                             "0x0077"
#define RSA_Y_56_inst_adr                                                             "0x0078"
#define RSA_Y_57_inst_adr                                                             "0x0079"
#define RSA_Y_58_inst_adr                                                             "0x007A"
#define RSA_Y_59_inst_adr                                                             "0x007B"
#define RSA_Y_60_inst_adr                                                             "0x007C"
#define RSA_Y_61_inst_adr                                                             "0x007D"
#define RSA_Y_62_inst_adr                                                             "0x007E"
#define RSA_Y_63_inst_adr                                                             "0x007F"
#define RSA_Y_0_inst                                                                 0x0040
#define RSA_Y_1_inst                                                                 0x0041
#define RSA_Y_2_inst                                                                 0x0042
#define RSA_Y_3_inst                                                                 0x0043
#define RSA_Y_4_inst                                                                 0x0044
#define RSA_Y_5_inst                                                                 0x0045
#define RSA_Y_6_inst                                                                 0x0046
#define RSA_Y_7_inst                                                                 0x0047
#define RSA_Y_8_inst                                                                 0x0048
#define RSA_Y_9_inst                                                                 0x0049
#define RSA_Y_10_inst                                                                 0x004A
#define RSA_Y_11_inst                                                                 0x004B
#define RSA_Y_12_inst                                                                 0x004C
#define RSA_Y_13_inst                                                                 0x004D
#define RSA_Y_14_inst                                                                 0x004E
#define RSA_Y_15_inst                                                                 0x004F
#define RSA_Y_16_inst                                                                 0x0050
#define RSA_Y_17_inst                                                                 0x0051
#define RSA_Y_18_inst                                                                 0x0052
#define RSA_Y_19_inst                                                                 0x0053
#define RSA_Y_20_inst                                                                 0x0054
#define RSA_Y_21_inst                                                                 0x0055
#define RSA_Y_22_inst                                                                 0x0056
#define RSA_Y_23_inst                                                                 0x0057
#define RSA_Y_24_inst                                                                 0x0058
#define RSA_Y_25_inst                                                                 0x0059
#define RSA_Y_26_inst                                                                 0x005A
#define RSA_Y_27_inst                                                                 0x005B
#define RSA_Y_28_inst                                                                 0x005C
#define RSA_Y_29_inst                                                                 0x005D
#define RSA_Y_30_inst                                                                 0x005E
#define RSA_Y_31_inst                                                                 0x005F
#define RSA_Y_32_inst                                                                 0x0060
#define RSA_Y_33_inst                                                                 0x0061
#define RSA_Y_34_inst                                                                 0x0062
#define RSA_Y_35_inst                                                                 0x0063
#define RSA_Y_36_inst                                                                 0x0064
#define RSA_Y_37_inst                                                                 0x0065
#define RSA_Y_38_inst                                                                 0x0066
#define RSA_Y_39_inst                                                                 0x0067
#define RSA_Y_40_inst                                                                 0x0068
#define RSA_Y_41_inst                                                                 0x0069
#define RSA_Y_42_inst                                                                 0x006A
#define RSA_Y_43_inst                                                                 0x006B
#define RSA_Y_44_inst                                                                 0x006C
#define RSA_Y_45_inst                                                                 0x006D
#define RSA_Y_46_inst                                                                 0x006E
#define RSA_Y_47_inst                                                                 0x006F
#define RSA_Y_48_inst                                                                 0x0070
#define RSA_Y_49_inst                                                                 0x0071
#define RSA_Y_50_inst                                                                 0x0072
#define RSA_Y_51_inst                                                                 0x0073
#define RSA_Y_52_inst                                                                 0x0074
#define RSA_Y_53_inst                                                                 0x0075
#define RSA_Y_54_inst                                                                 0x0076
#define RSA_Y_55_inst                                                                 0x0077
#define RSA_Y_56_inst                                                                 0x0078
#define RSA_Y_57_inst                                                                 0x0079
#define RSA_Y_58_inst                                                                 0x007A
#define RSA_Y_59_inst                                                                 0x007B
#define RSA_Y_60_inst                                                                 0x007C
#define RSA_Y_61_inst                                                                 0x007D
#define RSA_Y_62_inst                                                                 0x007E
#define RSA_Y_63_inst                                                                 0x007F
#define RSA_Y_data_shift                                                             (0)
#define RSA_Y_data_mask                                                              (0xFFFFFFFF)
#define RSA_Y_data(data)                                                             (0xFFFFFFFF&((data)<<0))
#define RSA_Y_data_src(data)                                                         ((0xFFFFFFFF&(data))>>0)
#define RSA_Y_get_data(data)                                                         ((0xFFFFFFFF&(data))>>0)


#define RSA_M_0                                                                      0x1806E200
#define RSA_M_1                                                                      0x1806E204
#define RSA_M_2                                                                      0x1806E208
#define RSA_M_3                                                                      0x1806E20C
#define RSA_M_4                                                                      0x1806E210
#define RSA_M_5                                                                      0x1806E214
#define RSA_M_6                                                                      0x1806E218
#define RSA_M_7                                                                      0x1806E21C
#define RSA_M_8                                                                      0x1806E220
#define RSA_M_9                                                                      0x1806E224
#define RSA_M_10                                                                      0x1806E228
#define RSA_M_11                                                                      0x1806E22C
#define RSA_M_12                                                                      0x1806E230
#define RSA_M_13                                                                      0x1806E234
#define RSA_M_14                                                                      0x1806E238
#define RSA_M_15                                                                      0x1806E23C
#define RSA_M_16                                                                      0x1806E240
#define RSA_M_17                                                                      0x1806E244
#define RSA_M_18                                                                      0x1806E248
#define RSA_M_19                                                                      0x1806E24C
#define RSA_M_20                                                                      0x1806E250
#define RSA_M_21                                                                      0x1806E254
#define RSA_M_22                                                                      0x1806E258
#define RSA_M_23                                                                      0x1806E25C
#define RSA_M_24                                                                      0x1806E260
#define RSA_M_25                                                                      0x1806E264
#define RSA_M_26                                                                      0x1806E268
#define RSA_M_27                                                                      0x1806E26C
#define RSA_M_28                                                                      0x1806E270
#define RSA_M_29                                                                      0x1806E274
#define RSA_M_30                                                                      0x1806E278
#define RSA_M_31                                                                      0x1806E27C
#define RSA_M_32                                                                      0x1806E280
#define RSA_M_33                                                                      0x1806E284
#define RSA_M_34                                                                      0x1806E288
#define RSA_M_35                                                                      0x1806E28C
#define RSA_M_36                                                                      0x1806E290
#define RSA_M_37                                                                      0x1806E294
#define RSA_M_38                                                                      0x1806E298
#define RSA_M_39                                                                      0x1806E29C
#define RSA_M_40                                                                      0x1806E2A0
#define RSA_M_41                                                                      0x1806E2A4
#define RSA_M_42                                                                      0x1806E2A8
#define RSA_M_43                                                                      0x1806E2AC
#define RSA_M_44                                                                      0x1806E2B0
#define RSA_M_45                                                                      0x1806E2B4
#define RSA_M_46                                                                      0x1806E2B8
#define RSA_M_47                                                                      0x1806E2BC
#define RSA_M_48                                                                      0x1806E2C0
#define RSA_M_49                                                                      0x1806E2C4
#define RSA_M_50                                                                      0x1806E2C8
#define RSA_M_51                                                                      0x1806E2CC
#define RSA_M_52                                                                      0x1806E2D0
#define RSA_M_53                                                                      0x1806E2D4
#define RSA_M_54                                                                      0x1806E2D8
#define RSA_M_55                                                                      0x1806E2DC
#define RSA_M_56                                                                      0x1806E2E0
#define RSA_M_57                                                                      0x1806E2E4
#define RSA_M_58                                                                      0x1806E2E8
#define RSA_M_59                                                                      0x1806E2EC
#define RSA_M_60                                                                      0x1806E2F0
#define RSA_M_61                                                                      0x1806E2F4
#define RSA_M_62                                                                      0x1806E2F8
#define RSA_M_63                                                                      0x1806E2FC
#define RSA_M_0_reg_addr                                                             "0xB806E200"
#define RSA_M_1_reg_addr                                                             "0xB806E204"
#define RSA_M_2_reg_addr                                                             "0xB806E208"
#define RSA_M_3_reg_addr                                                             "0xB806E20C"
#define RSA_M_4_reg_addr                                                             "0xB806E210"
#define RSA_M_5_reg_addr                                                             "0xB806E214"
#define RSA_M_6_reg_addr                                                             "0xB806E218"
#define RSA_M_7_reg_addr                                                             "0xB806E21C"
#define RSA_M_8_reg_addr                                                             "0xB806E220"
#define RSA_M_9_reg_addr                                                             "0xB806E224"
#define RSA_M_10_reg_addr                                                             "0xB806E228"
#define RSA_M_11_reg_addr                                                             "0xB806E22C"
#define RSA_M_12_reg_addr                                                             "0xB806E230"
#define RSA_M_13_reg_addr                                                             "0xB806E234"
#define RSA_M_14_reg_addr                                                             "0xB806E238"
#define RSA_M_15_reg_addr                                                             "0xB806E23C"
#define RSA_M_16_reg_addr                                                             "0xB806E240"
#define RSA_M_17_reg_addr                                                             "0xB806E244"
#define RSA_M_18_reg_addr                                                             "0xB806E248"
#define RSA_M_19_reg_addr                                                             "0xB806E24C"
#define RSA_M_20_reg_addr                                                             "0xB806E250"
#define RSA_M_21_reg_addr                                                             "0xB806E254"
#define RSA_M_22_reg_addr                                                             "0xB806E258"
#define RSA_M_23_reg_addr                                                             "0xB806E25C"
#define RSA_M_24_reg_addr                                                             "0xB806E260"
#define RSA_M_25_reg_addr                                                             "0xB806E264"
#define RSA_M_26_reg_addr                                                             "0xB806E268"
#define RSA_M_27_reg_addr                                                             "0xB806E26C"
#define RSA_M_28_reg_addr                                                             "0xB806E270"
#define RSA_M_29_reg_addr                                                             "0xB806E274"
#define RSA_M_30_reg_addr                                                             "0xB806E278"
#define RSA_M_31_reg_addr                                                             "0xB806E27C"
#define RSA_M_32_reg_addr                                                             "0xB806E280"
#define RSA_M_33_reg_addr                                                             "0xB806E284"
#define RSA_M_34_reg_addr                                                             "0xB806E288"
#define RSA_M_35_reg_addr                                                             "0xB806E28C"
#define RSA_M_36_reg_addr                                                             "0xB806E290"
#define RSA_M_37_reg_addr                                                             "0xB806E294"
#define RSA_M_38_reg_addr                                                             "0xB806E298"
#define RSA_M_39_reg_addr                                                             "0xB806E29C"
#define RSA_M_40_reg_addr                                                             "0xB806E2A0"
#define RSA_M_41_reg_addr                                                             "0xB806E2A4"
#define RSA_M_42_reg_addr                                                             "0xB806E2A8"
#define RSA_M_43_reg_addr                                                             "0xB806E2AC"
#define RSA_M_44_reg_addr                                                             "0xB806E2B0"
#define RSA_M_45_reg_addr                                                             "0xB806E2B4"
#define RSA_M_46_reg_addr                                                             "0xB806E2B8"
#define RSA_M_47_reg_addr                                                             "0xB806E2BC"
#define RSA_M_48_reg_addr                                                             "0xB806E2C0"
#define RSA_M_49_reg_addr                                                             "0xB806E2C4"
#define RSA_M_50_reg_addr                                                             "0xB806E2C8"
#define RSA_M_51_reg_addr                                                             "0xB806E2CC"
#define RSA_M_52_reg_addr                                                             "0xB806E2D0"
#define RSA_M_53_reg_addr                                                             "0xB806E2D4"
#define RSA_M_54_reg_addr                                                             "0xB806E2D8"
#define RSA_M_55_reg_addr                                                             "0xB806E2DC"
#define RSA_M_56_reg_addr                                                             "0xB806E2E0"
#define RSA_M_57_reg_addr                                                             "0xB806E2E4"
#define RSA_M_58_reg_addr                                                             "0xB806E2E8"
#define RSA_M_59_reg_addr                                                             "0xB806E2EC"
#define RSA_M_60_reg_addr                                                             "0xB806E2F0"
#define RSA_M_61_reg_addr                                                             "0xB806E2F4"
#define RSA_M_62_reg_addr                                                             "0xB806E2F8"
#define RSA_M_63_reg_addr                                                             "0xB806E2FC"
#define RSA_M_0_reg                                                                  0xB806E200
#define RSA_M_1_reg                                                                  0xB806E204
#define RSA_M_2_reg                                                                  0xB806E208
#define RSA_M_3_reg                                                                  0xB806E20C
#define RSA_M_4_reg                                                                  0xB806E210
#define RSA_M_5_reg                                                                  0xB806E214
#define RSA_M_6_reg                                                                  0xB806E218
#define RSA_M_7_reg                                                                  0xB806E21C
#define RSA_M_8_reg                                                                  0xB806E220
#define RSA_M_9_reg                                                                  0xB806E224
#define RSA_M_10_reg                                                                  0xB806E228
#define RSA_M_11_reg                                                                  0xB806E22C
#define RSA_M_12_reg                                                                  0xB806E230
#define RSA_M_13_reg                                                                  0xB806E234
#define RSA_M_14_reg                                                                  0xB806E238
#define RSA_M_15_reg                                                                  0xB806E23C
#define RSA_M_16_reg                                                                  0xB806E240
#define RSA_M_17_reg                                                                  0xB806E244
#define RSA_M_18_reg                                                                  0xB806E248
#define RSA_M_19_reg                                                                  0xB806E24C
#define RSA_M_20_reg                                                                  0xB806E250
#define RSA_M_21_reg                                                                  0xB806E254
#define RSA_M_22_reg                                                                  0xB806E258
#define RSA_M_23_reg                                                                  0xB806E25C
#define RSA_M_24_reg                                                                  0xB806E260
#define RSA_M_25_reg                                                                  0xB806E264
#define RSA_M_26_reg                                                                  0xB806E268
#define RSA_M_27_reg                                                                  0xB806E26C
#define RSA_M_28_reg                                                                  0xB806E270
#define RSA_M_29_reg                                                                  0xB806E274
#define RSA_M_30_reg                                                                  0xB806E278
#define RSA_M_31_reg                                                                  0xB806E27C
#define RSA_M_32_reg                                                                  0xB806E280
#define RSA_M_33_reg                                                                  0xB806E284
#define RSA_M_34_reg                                                                  0xB806E288
#define RSA_M_35_reg                                                                  0xB806E28C
#define RSA_M_36_reg                                                                  0xB806E290
#define RSA_M_37_reg                                                                  0xB806E294
#define RSA_M_38_reg                                                                  0xB806E298
#define RSA_M_39_reg                                                                  0xB806E29C
#define RSA_M_40_reg                                                                  0xB806E2A0
#define RSA_M_41_reg                                                                  0xB806E2A4
#define RSA_M_42_reg                                                                  0xB806E2A8
#define RSA_M_43_reg                                                                  0xB806E2AC
#define RSA_M_44_reg                                                                  0xB806E2B0
#define RSA_M_45_reg                                                                  0xB806E2B4
#define RSA_M_46_reg                                                                  0xB806E2B8
#define RSA_M_47_reg                                                                  0xB806E2BC
#define RSA_M_48_reg                                                                  0xB806E2C0
#define RSA_M_49_reg                                                                  0xB806E2C4
#define RSA_M_50_reg                                                                  0xB806E2C8
#define RSA_M_51_reg                                                                  0xB806E2CC
#define RSA_M_52_reg                                                                  0xB806E2D0
#define RSA_M_53_reg                                                                  0xB806E2D4
#define RSA_M_54_reg                                                                  0xB806E2D8
#define RSA_M_55_reg                                                                  0xB806E2DC
#define RSA_M_56_reg                                                                  0xB806E2E0
#define RSA_M_57_reg                                                                  0xB806E2E4
#define RSA_M_58_reg                                                                  0xB806E2E8
#define RSA_M_59_reg                                                                  0xB806E2EC
#define RSA_M_60_reg                                                                  0xB806E2F0
#define RSA_M_61_reg                                                                  0xB806E2F4
#define RSA_M_62_reg                                                                  0xB806E2F8
#define RSA_M_63_reg                                                                  0xB806E2FC
#define set_RSA_M_0_reg(data)   (*((volatile unsigned int*) RSA_M_0_reg)=data)
#define set_RSA_M_1_reg(data)   (*((volatile unsigned int*) RSA_M_1_reg)=data)
#define set_RSA_M_2_reg(data)   (*((volatile unsigned int*) RSA_M_2_reg)=data)
#define set_RSA_M_3_reg(data)   (*((volatile unsigned int*) RSA_M_3_reg)=data)
#define set_RSA_M_4_reg(data)   (*((volatile unsigned int*) RSA_M_4_reg)=data)
#define set_RSA_M_5_reg(data)   (*((volatile unsigned int*) RSA_M_5_reg)=data)
#define set_RSA_M_6_reg(data)   (*((volatile unsigned int*) RSA_M_6_reg)=data)
#define set_RSA_M_7_reg(data)   (*((volatile unsigned int*) RSA_M_7_reg)=data)
#define set_RSA_M_8_reg(data)   (*((volatile unsigned int*) RSA_M_8_reg)=data)
#define set_RSA_M_9_reg(data)   (*((volatile unsigned int*) RSA_M_9_reg)=data)
#define set_RSA_M_10_reg(data)   (*((volatile unsigned int*) RSA_M_10_reg)=data)
#define set_RSA_M_11_reg(data)   (*((volatile unsigned int*) RSA_M_11_reg)=data)
#define set_RSA_M_12_reg(data)   (*((volatile unsigned int*) RSA_M_12_reg)=data)
#define set_RSA_M_13_reg(data)   (*((volatile unsigned int*) RSA_M_13_reg)=data)
#define set_RSA_M_14_reg(data)   (*((volatile unsigned int*) RSA_M_14_reg)=data)
#define set_RSA_M_15_reg(data)   (*((volatile unsigned int*) RSA_M_15_reg)=data)
#define set_RSA_M_16_reg(data)   (*((volatile unsigned int*) RSA_M_16_reg)=data)
#define set_RSA_M_17_reg(data)   (*((volatile unsigned int*) RSA_M_17_reg)=data)
#define set_RSA_M_18_reg(data)   (*((volatile unsigned int*) RSA_M_18_reg)=data)
#define set_RSA_M_19_reg(data)   (*((volatile unsigned int*) RSA_M_19_reg)=data)
#define set_RSA_M_20_reg(data)   (*((volatile unsigned int*) RSA_M_20_reg)=data)
#define set_RSA_M_21_reg(data)   (*((volatile unsigned int*) RSA_M_21_reg)=data)
#define set_RSA_M_22_reg(data)   (*((volatile unsigned int*) RSA_M_22_reg)=data)
#define set_RSA_M_23_reg(data)   (*((volatile unsigned int*) RSA_M_23_reg)=data)
#define set_RSA_M_24_reg(data)   (*((volatile unsigned int*) RSA_M_24_reg)=data)
#define set_RSA_M_25_reg(data)   (*((volatile unsigned int*) RSA_M_25_reg)=data)
#define set_RSA_M_26_reg(data)   (*((volatile unsigned int*) RSA_M_26_reg)=data)
#define set_RSA_M_27_reg(data)   (*((volatile unsigned int*) RSA_M_27_reg)=data)
#define set_RSA_M_28_reg(data)   (*((volatile unsigned int*) RSA_M_28_reg)=data)
#define set_RSA_M_29_reg(data)   (*((volatile unsigned int*) RSA_M_29_reg)=data)
#define set_RSA_M_30_reg(data)   (*((volatile unsigned int*) RSA_M_30_reg)=data)
#define set_RSA_M_31_reg(data)   (*((volatile unsigned int*) RSA_M_31_reg)=data)
#define set_RSA_M_32_reg(data)   (*((volatile unsigned int*) RSA_M_32_reg)=data)
#define set_RSA_M_33_reg(data)   (*((volatile unsigned int*) RSA_M_33_reg)=data)
#define set_RSA_M_34_reg(data)   (*((volatile unsigned int*) RSA_M_34_reg)=data)
#define set_RSA_M_35_reg(data)   (*((volatile unsigned int*) RSA_M_35_reg)=data)
#define set_RSA_M_36_reg(data)   (*((volatile unsigned int*) RSA_M_36_reg)=data)
#define set_RSA_M_37_reg(data)   (*((volatile unsigned int*) RSA_M_37_reg)=data)
#define set_RSA_M_38_reg(data)   (*((volatile unsigned int*) RSA_M_38_reg)=data)
#define set_RSA_M_39_reg(data)   (*((volatile unsigned int*) RSA_M_39_reg)=data)
#define set_RSA_M_40_reg(data)   (*((volatile unsigned int*) RSA_M_40_reg)=data)
#define set_RSA_M_41_reg(data)   (*((volatile unsigned int*) RSA_M_41_reg)=data)
#define set_RSA_M_42_reg(data)   (*((volatile unsigned int*) RSA_M_42_reg)=data)
#define set_RSA_M_43_reg(data)   (*((volatile unsigned int*) RSA_M_43_reg)=data)
#define set_RSA_M_44_reg(data)   (*((volatile unsigned int*) RSA_M_44_reg)=data)
#define set_RSA_M_45_reg(data)   (*((volatile unsigned int*) RSA_M_45_reg)=data)
#define set_RSA_M_46_reg(data)   (*((volatile unsigned int*) RSA_M_46_reg)=data)
#define set_RSA_M_47_reg(data)   (*((volatile unsigned int*) RSA_M_47_reg)=data)
#define set_RSA_M_48_reg(data)   (*((volatile unsigned int*) RSA_M_48_reg)=data)
#define set_RSA_M_49_reg(data)   (*((volatile unsigned int*) RSA_M_49_reg)=data)
#define set_RSA_M_50_reg(data)   (*((volatile unsigned int*) RSA_M_50_reg)=data)
#define set_RSA_M_51_reg(data)   (*((volatile unsigned int*) RSA_M_51_reg)=data)
#define set_RSA_M_52_reg(data)   (*((volatile unsigned int*) RSA_M_52_reg)=data)
#define set_RSA_M_53_reg(data)   (*((volatile unsigned int*) RSA_M_53_reg)=data)
#define set_RSA_M_54_reg(data)   (*((volatile unsigned int*) RSA_M_54_reg)=data)
#define set_RSA_M_55_reg(data)   (*((volatile unsigned int*) RSA_M_55_reg)=data)
#define set_RSA_M_56_reg(data)   (*((volatile unsigned int*) RSA_M_56_reg)=data)
#define set_RSA_M_57_reg(data)   (*((volatile unsigned int*) RSA_M_57_reg)=data)
#define set_RSA_M_58_reg(data)   (*((volatile unsigned int*) RSA_M_58_reg)=data)
#define set_RSA_M_59_reg(data)   (*((volatile unsigned int*) RSA_M_59_reg)=data)
#define set_RSA_M_60_reg(data)   (*((volatile unsigned int*) RSA_M_60_reg)=data)
#define set_RSA_M_61_reg(data)   (*((volatile unsigned int*) RSA_M_61_reg)=data)
#define set_RSA_M_62_reg(data)   (*((volatile unsigned int*) RSA_M_62_reg)=data)
#define set_RSA_M_63_reg(data)   (*((volatile unsigned int*) RSA_M_63_reg)=data)
#define get_RSA_M_0_reg   (*((volatile unsigned int*) RSA_M_0_reg))
#define get_RSA_M_1_reg   (*((volatile unsigned int*) RSA_M_1_reg))
#define get_RSA_M_2_reg   (*((volatile unsigned int*) RSA_M_2_reg))
#define get_RSA_M_3_reg   (*((volatile unsigned int*) RSA_M_3_reg))
#define get_RSA_M_4_reg   (*((volatile unsigned int*) RSA_M_4_reg))
#define get_RSA_M_5_reg   (*((volatile unsigned int*) RSA_M_5_reg))
#define get_RSA_M_6_reg   (*((volatile unsigned int*) RSA_M_6_reg))
#define get_RSA_M_7_reg   (*((volatile unsigned int*) RSA_M_7_reg))
#define get_RSA_M_8_reg   (*((volatile unsigned int*) RSA_M_8_reg))
#define get_RSA_M_9_reg   (*((volatile unsigned int*) RSA_M_9_reg))
#define get_RSA_M_10_reg   (*((volatile unsigned int*) RSA_M_10_reg))
#define get_RSA_M_11_reg   (*((volatile unsigned int*) RSA_M_11_reg))
#define get_RSA_M_12_reg   (*((volatile unsigned int*) RSA_M_12_reg))
#define get_RSA_M_13_reg   (*((volatile unsigned int*) RSA_M_13_reg))
#define get_RSA_M_14_reg   (*((volatile unsigned int*) RSA_M_14_reg))
#define get_RSA_M_15_reg   (*((volatile unsigned int*) RSA_M_15_reg))
#define get_RSA_M_16_reg   (*((volatile unsigned int*) RSA_M_16_reg))
#define get_RSA_M_17_reg   (*((volatile unsigned int*) RSA_M_17_reg))
#define get_RSA_M_18_reg   (*((volatile unsigned int*) RSA_M_18_reg))
#define get_RSA_M_19_reg   (*((volatile unsigned int*) RSA_M_19_reg))
#define get_RSA_M_20_reg   (*((volatile unsigned int*) RSA_M_20_reg))
#define get_RSA_M_21_reg   (*((volatile unsigned int*) RSA_M_21_reg))
#define get_RSA_M_22_reg   (*((volatile unsigned int*) RSA_M_22_reg))
#define get_RSA_M_23_reg   (*((volatile unsigned int*) RSA_M_23_reg))
#define get_RSA_M_24_reg   (*((volatile unsigned int*) RSA_M_24_reg))
#define get_RSA_M_25_reg   (*((volatile unsigned int*) RSA_M_25_reg))
#define get_RSA_M_26_reg   (*((volatile unsigned int*) RSA_M_26_reg))
#define get_RSA_M_27_reg   (*((volatile unsigned int*) RSA_M_27_reg))
#define get_RSA_M_28_reg   (*((volatile unsigned int*) RSA_M_28_reg))
#define get_RSA_M_29_reg   (*((volatile unsigned int*) RSA_M_29_reg))
#define get_RSA_M_30_reg   (*((volatile unsigned int*) RSA_M_30_reg))
#define get_RSA_M_31_reg   (*((volatile unsigned int*) RSA_M_31_reg))
#define get_RSA_M_32_reg   (*((volatile unsigned int*) RSA_M_32_reg))
#define get_RSA_M_33_reg   (*((volatile unsigned int*) RSA_M_33_reg))
#define get_RSA_M_34_reg   (*((volatile unsigned int*) RSA_M_34_reg))
#define get_RSA_M_35_reg   (*((volatile unsigned int*) RSA_M_35_reg))
#define get_RSA_M_36_reg   (*((volatile unsigned int*) RSA_M_36_reg))
#define get_RSA_M_37_reg   (*((volatile unsigned int*) RSA_M_37_reg))
#define get_RSA_M_38_reg   (*((volatile unsigned int*) RSA_M_38_reg))
#define get_RSA_M_39_reg   (*((volatile unsigned int*) RSA_M_39_reg))
#define get_RSA_M_40_reg   (*((volatile unsigned int*) RSA_M_40_reg))
#define get_RSA_M_41_reg   (*((volatile unsigned int*) RSA_M_41_reg))
#define get_RSA_M_42_reg   (*((volatile unsigned int*) RSA_M_42_reg))
#define get_RSA_M_43_reg   (*((volatile unsigned int*) RSA_M_43_reg))
#define get_RSA_M_44_reg   (*((volatile unsigned int*) RSA_M_44_reg))
#define get_RSA_M_45_reg   (*((volatile unsigned int*) RSA_M_45_reg))
#define get_RSA_M_46_reg   (*((volatile unsigned int*) RSA_M_46_reg))
#define get_RSA_M_47_reg   (*((volatile unsigned int*) RSA_M_47_reg))
#define get_RSA_M_48_reg   (*((volatile unsigned int*) RSA_M_48_reg))
#define get_RSA_M_49_reg   (*((volatile unsigned int*) RSA_M_49_reg))
#define get_RSA_M_50_reg   (*((volatile unsigned int*) RSA_M_50_reg))
#define get_RSA_M_51_reg   (*((volatile unsigned int*) RSA_M_51_reg))
#define get_RSA_M_52_reg   (*((volatile unsigned int*) RSA_M_52_reg))
#define get_RSA_M_53_reg   (*((volatile unsigned int*) RSA_M_53_reg))
#define get_RSA_M_54_reg   (*((volatile unsigned int*) RSA_M_54_reg))
#define get_RSA_M_55_reg   (*((volatile unsigned int*) RSA_M_55_reg))
#define get_RSA_M_56_reg   (*((volatile unsigned int*) RSA_M_56_reg))
#define get_RSA_M_57_reg   (*((volatile unsigned int*) RSA_M_57_reg))
#define get_RSA_M_58_reg   (*((volatile unsigned int*) RSA_M_58_reg))
#define get_RSA_M_59_reg   (*((volatile unsigned int*) RSA_M_59_reg))
#define get_RSA_M_60_reg   (*((volatile unsigned int*) RSA_M_60_reg))
#define get_RSA_M_61_reg   (*((volatile unsigned int*) RSA_M_61_reg))
#define get_RSA_M_62_reg   (*((volatile unsigned int*) RSA_M_62_reg))
#define get_RSA_M_63_reg   (*((volatile unsigned int*) RSA_M_63_reg))
#define RSA_M_0_inst_adr                                                             "0x0080"
#define RSA_M_1_inst_adr                                                             "0x0081"
#define RSA_M_2_inst_adr                                                             "0x0082"
#define RSA_M_3_inst_adr                                                             "0x0083"
#define RSA_M_4_inst_adr                                                             "0x0084"
#define RSA_M_5_inst_adr                                                             "0x0085"
#define RSA_M_6_inst_adr                                                             "0x0086"
#define RSA_M_7_inst_adr                                                             "0x0087"
#define RSA_M_8_inst_adr                                                             "0x0088"
#define RSA_M_9_inst_adr                                                             "0x0089"
#define RSA_M_10_inst_adr                                                             "0x008A"
#define RSA_M_11_inst_adr                                                             "0x008B"
#define RSA_M_12_inst_adr                                                             "0x008C"
#define RSA_M_13_inst_adr                                                             "0x008D"
#define RSA_M_14_inst_adr                                                             "0x008E"
#define RSA_M_15_inst_adr                                                             "0x008F"
#define RSA_M_16_inst_adr                                                             "0x0090"
#define RSA_M_17_inst_adr                                                             "0x0091"
#define RSA_M_18_inst_adr                                                             "0x0092"
#define RSA_M_19_inst_adr                                                             "0x0093"
#define RSA_M_20_inst_adr                                                             "0x0094"
#define RSA_M_21_inst_adr                                                             "0x0095"
#define RSA_M_22_inst_adr                                                             "0x0096"
#define RSA_M_23_inst_adr                                                             "0x0097"
#define RSA_M_24_inst_adr                                                             "0x0098"
#define RSA_M_25_inst_adr                                                             "0x0099"
#define RSA_M_26_inst_adr                                                             "0x009A"
#define RSA_M_27_inst_adr                                                             "0x009B"
#define RSA_M_28_inst_adr                                                             "0x009C"
#define RSA_M_29_inst_adr                                                             "0x009D"
#define RSA_M_30_inst_adr                                                             "0x009E"
#define RSA_M_31_inst_adr                                                             "0x009F"
#define RSA_M_32_inst_adr                                                             "0x00A0"
#define RSA_M_33_inst_adr                                                             "0x00A1"
#define RSA_M_34_inst_adr                                                             "0x00A2"
#define RSA_M_35_inst_adr                                                             "0x00A3"
#define RSA_M_36_inst_adr                                                             "0x00A4"
#define RSA_M_37_inst_adr                                                             "0x00A5"
#define RSA_M_38_inst_adr                                                             "0x00A6"
#define RSA_M_39_inst_adr                                                             "0x00A7"
#define RSA_M_40_inst_adr                                                             "0x00A8"
#define RSA_M_41_inst_adr                                                             "0x00A9"
#define RSA_M_42_inst_adr                                                             "0x00AA"
#define RSA_M_43_inst_adr                                                             "0x00AB"
#define RSA_M_44_inst_adr                                                             "0x00AC"
#define RSA_M_45_inst_adr                                                             "0x00AD"
#define RSA_M_46_inst_adr                                                             "0x00AE"
#define RSA_M_47_inst_adr                                                             "0x00AF"
#define RSA_M_48_inst_adr                                                             "0x00B0"
#define RSA_M_49_inst_adr                                                             "0x00B1"
#define RSA_M_50_inst_adr                                                             "0x00B2"
#define RSA_M_51_inst_adr                                                             "0x00B3"
#define RSA_M_52_inst_adr                                                             "0x00B4"
#define RSA_M_53_inst_adr                                                             "0x00B5"
#define RSA_M_54_inst_adr                                                             "0x00B6"
#define RSA_M_55_inst_adr                                                             "0x00B7"
#define RSA_M_56_inst_adr                                                             "0x00B8"
#define RSA_M_57_inst_adr                                                             "0x00B9"
#define RSA_M_58_inst_adr                                                             "0x00BA"
#define RSA_M_59_inst_adr                                                             "0x00BB"
#define RSA_M_60_inst_adr                                                             "0x00BC"
#define RSA_M_61_inst_adr                                                             "0x00BD"
#define RSA_M_62_inst_adr                                                             "0x00BE"
#define RSA_M_63_inst_adr                                                             "0x00BF"
#define RSA_M_0_inst                                                                 0x0080
#define RSA_M_1_inst                                                                 0x0081
#define RSA_M_2_inst                                                                 0x0082
#define RSA_M_3_inst                                                                 0x0083
#define RSA_M_4_inst                                                                 0x0084
#define RSA_M_5_inst                                                                 0x0085
#define RSA_M_6_inst                                                                 0x0086
#define RSA_M_7_inst                                                                 0x0087
#define RSA_M_8_inst                                                                 0x0088
#define RSA_M_9_inst                                                                 0x0089
#define RSA_M_10_inst                                                                 0x008A
#define RSA_M_11_inst                                                                 0x008B
#define RSA_M_12_inst                                                                 0x008C
#define RSA_M_13_inst                                                                 0x008D
#define RSA_M_14_inst                                                                 0x008E
#define RSA_M_15_inst                                                                 0x008F
#define RSA_M_16_inst                                                                 0x0090
#define RSA_M_17_inst                                                                 0x0091
#define RSA_M_18_inst                                                                 0x0092
#define RSA_M_19_inst                                                                 0x0093
#define RSA_M_20_inst                                                                 0x0094
#define RSA_M_21_inst                                                                 0x0095
#define RSA_M_22_inst                                                                 0x0096
#define RSA_M_23_inst                                                                 0x0097
#define RSA_M_24_inst                                                                 0x0098
#define RSA_M_25_inst                                                                 0x0099
#define RSA_M_26_inst                                                                 0x009A
#define RSA_M_27_inst                                                                 0x009B
#define RSA_M_28_inst                                                                 0x009C
#define RSA_M_29_inst                                                                 0x009D
#define RSA_M_30_inst                                                                 0x009E
#define RSA_M_31_inst                                                                 0x009F
#define RSA_M_32_inst                                                                 0x00A0
#define RSA_M_33_inst                                                                 0x00A1
#define RSA_M_34_inst                                                                 0x00A2
#define RSA_M_35_inst                                                                 0x00A3
#define RSA_M_36_inst                                                                 0x00A4
#define RSA_M_37_inst                                                                 0x00A5
#define RSA_M_38_inst                                                                 0x00A6
#define RSA_M_39_inst                                                                 0x00A7
#define RSA_M_40_inst                                                                 0x00A8
#define RSA_M_41_inst                                                                 0x00A9
#define RSA_M_42_inst                                                                 0x00AA
#define RSA_M_43_inst                                                                 0x00AB
#define RSA_M_44_inst                                                                 0x00AC
#define RSA_M_45_inst                                                                 0x00AD
#define RSA_M_46_inst                                                                 0x00AE
#define RSA_M_47_inst                                                                 0x00AF
#define RSA_M_48_inst                                                                 0x00B0
#define RSA_M_49_inst                                                                 0x00B1
#define RSA_M_50_inst                                                                 0x00B2
#define RSA_M_51_inst                                                                 0x00B3
#define RSA_M_52_inst                                                                 0x00B4
#define RSA_M_53_inst                                                                 0x00B5
#define RSA_M_54_inst                                                                 0x00B6
#define RSA_M_55_inst                                                                 0x00B7
#define RSA_M_56_inst                                                                 0x00B8
#define RSA_M_57_inst                                                                 0x00B9
#define RSA_M_58_inst                                                                 0x00BA
#define RSA_M_59_inst                                                                 0x00BB
#define RSA_M_60_inst                                                                 0x00BC
#define RSA_M_61_inst                                                                 0x00BD
#define RSA_M_62_inst                                                                 0x00BE
#define RSA_M_63_inst                                                                 0x00BF
#define RSA_M_data_shift                                                             (0)
#define RSA_M_data_mask                                                              (0xFFFFFFFF)
#define RSA_M_data(data)                                                             (0xFFFFFFFF&((data)<<0))
#define RSA_M_data_src(data)                                                         ((0xFFFFFFFF&(data))>>0)
#define RSA_M_get_data(data)                                                         ((0xFFFFFFFF&(data))>>0)


#define RSA_A_0                                                                      0x1806E300
#define RSA_A_1                                                                      0x1806E304
#define RSA_A_2                                                                      0x1806E308
#define RSA_A_3                                                                      0x1806E30C
#define RSA_A_4                                                                      0x1806E310
#define RSA_A_5                                                                      0x1806E314
#define RSA_A_6                                                                      0x1806E318
#define RSA_A_7                                                                      0x1806E31C
#define RSA_A_8                                                                      0x1806E320
#define RSA_A_9                                                                      0x1806E324
#define RSA_A_10                                                                      0x1806E328
#define RSA_A_11                                                                      0x1806E32C
#define RSA_A_12                                                                      0x1806E330
#define RSA_A_13                                                                      0x1806E334
#define RSA_A_14                                                                      0x1806E338
#define RSA_A_15                                                                      0x1806E33C
#define RSA_A_16                                                                      0x1806E340
#define RSA_A_17                                                                      0x1806E344
#define RSA_A_18                                                                      0x1806E348
#define RSA_A_19                                                                      0x1806E34C
#define RSA_A_20                                                                      0x1806E350
#define RSA_A_21                                                                      0x1806E354
#define RSA_A_22                                                                      0x1806E358
#define RSA_A_23                                                                      0x1806E35C
#define RSA_A_24                                                                      0x1806E360
#define RSA_A_25                                                                      0x1806E364
#define RSA_A_26                                                                      0x1806E368
#define RSA_A_27                                                                      0x1806E36C
#define RSA_A_28                                                                      0x1806E370
#define RSA_A_29                                                                      0x1806E374
#define RSA_A_30                                                                      0x1806E378
#define RSA_A_31                                                                      0x1806E37C
#define RSA_A_32                                                                      0x1806E380
#define RSA_A_33                                                                      0x1806E384
#define RSA_A_34                                                                      0x1806E388
#define RSA_A_35                                                                      0x1806E38C
#define RSA_A_36                                                                      0x1806E390
#define RSA_A_37                                                                      0x1806E394
#define RSA_A_38                                                                      0x1806E398
#define RSA_A_39                                                                      0x1806E39C
#define RSA_A_40                                                                      0x1806E3A0
#define RSA_A_41                                                                      0x1806E3A4
#define RSA_A_42                                                                      0x1806E3A8
#define RSA_A_43                                                                      0x1806E3AC
#define RSA_A_44                                                                      0x1806E3B0
#define RSA_A_45                                                                      0x1806E3B4
#define RSA_A_46                                                                      0x1806E3B8
#define RSA_A_47                                                                      0x1806E3BC
#define RSA_A_48                                                                      0x1806E3C0
#define RSA_A_49                                                                      0x1806E3C4
#define RSA_A_50                                                                      0x1806E3C8
#define RSA_A_51                                                                      0x1806E3CC
#define RSA_A_52                                                                      0x1806E3D0
#define RSA_A_53                                                                      0x1806E3D4
#define RSA_A_54                                                                      0x1806E3D8
#define RSA_A_55                                                                      0x1806E3DC
#define RSA_A_56                                                                      0x1806E3E0
#define RSA_A_57                                                                      0x1806E3E4
#define RSA_A_58                                                                      0x1806E3E8
#define RSA_A_59                                                                      0x1806E3EC
#define RSA_A_60                                                                      0x1806E3F0
#define RSA_A_61                                                                      0x1806E3F4
#define RSA_A_62                                                                      0x1806E3F8
#define RSA_A_63                                                                      0x1806E3FC
#define RSA_A_0_reg_addr                                                             "0xB806E300"
#define RSA_A_1_reg_addr                                                             "0xB806E304"
#define RSA_A_2_reg_addr                                                             "0xB806E308"
#define RSA_A_3_reg_addr                                                             "0xB806E30C"
#define RSA_A_4_reg_addr                                                             "0xB806E310"
#define RSA_A_5_reg_addr                                                             "0xB806E314"
#define RSA_A_6_reg_addr                                                             "0xB806E318"
#define RSA_A_7_reg_addr                                                             "0xB806E31C"
#define RSA_A_8_reg_addr                                                             "0xB806E320"
#define RSA_A_9_reg_addr                                                             "0xB806E324"
#define RSA_A_10_reg_addr                                                             "0xB806E328"
#define RSA_A_11_reg_addr                                                             "0xB806E32C"
#define RSA_A_12_reg_addr                                                             "0xB806E330"
#define RSA_A_13_reg_addr                                                             "0xB806E334"
#define RSA_A_14_reg_addr                                                             "0xB806E338"
#define RSA_A_15_reg_addr                                                             "0xB806E33C"
#define RSA_A_16_reg_addr                                                             "0xB806E340"
#define RSA_A_17_reg_addr                                                             "0xB806E344"
#define RSA_A_18_reg_addr                                                             "0xB806E348"
#define RSA_A_19_reg_addr                                                             "0xB806E34C"
#define RSA_A_20_reg_addr                                                             "0xB806E350"
#define RSA_A_21_reg_addr                                                             "0xB806E354"
#define RSA_A_22_reg_addr                                                             "0xB806E358"
#define RSA_A_23_reg_addr                                                             "0xB806E35C"
#define RSA_A_24_reg_addr                                                             "0xB806E360"
#define RSA_A_25_reg_addr                                                             "0xB806E364"
#define RSA_A_26_reg_addr                                                             "0xB806E368"
#define RSA_A_27_reg_addr                                                             "0xB806E36C"
#define RSA_A_28_reg_addr                                                             "0xB806E370"
#define RSA_A_29_reg_addr                                                             "0xB806E374"
#define RSA_A_30_reg_addr                                                             "0xB806E378"
#define RSA_A_31_reg_addr                                                             "0xB806E37C"
#define RSA_A_32_reg_addr                                                             "0xB806E380"
#define RSA_A_33_reg_addr                                                             "0xB806E384"
#define RSA_A_34_reg_addr                                                             "0xB806E388"
#define RSA_A_35_reg_addr                                                             "0xB806E38C"
#define RSA_A_36_reg_addr                                                             "0xB806E390"
#define RSA_A_37_reg_addr                                                             "0xB806E394"
#define RSA_A_38_reg_addr                                                             "0xB806E398"
#define RSA_A_39_reg_addr                                                             "0xB806E39C"
#define RSA_A_40_reg_addr                                                             "0xB806E3A0"
#define RSA_A_41_reg_addr                                                             "0xB806E3A4"
#define RSA_A_42_reg_addr                                                             "0xB806E3A8"
#define RSA_A_43_reg_addr                                                             "0xB806E3AC"
#define RSA_A_44_reg_addr                                                             "0xB806E3B0"
#define RSA_A_45_reg_addr                                                             "0xB806E3B4"
#define RSA_A_46_reg_addr                                                             "0xB806E3B8"
#define RSA_A_47_reg_addr                                                             "0xB806E3BC"
#define RSA_A_48_reg_addr                                                             "0xB806E3C0"
#define RSA_A_49_reg_addr                                                             "0xB806E3C4"
#define RSA_A_50_reg_addr                                                             "0xB806E3C8"
#define RSA_A_51_reg_addr                                                             "0xB806E3CC"
#define RSA_A_52_reg_addr                                                             "0xB806E3D0"
#define RSA_A_53_reg_addr                                                             "0xB806E3D4"
#define RSA_A_54_reg_addr                                                             "0xB806E3D8"
#define RSA_A_55_reg_addr                                                             "0xB806E3DC"
#define RSA_A_56_reg_addr                                                             "0xB806E3E0"
#define RSA_A_57_reg_addr                                                             "0xB806E3E4"
#define RSA_A_58_reg_addr                                                             "0xB806E3E8"
#define RSA_A_59_reg_addr                                                             "0xB806E3EC"
#define RSA_A_60_reg_addr                                                             "0xB806E3F0"
#define RSA_A_61_reg_addr                                                             "0xB806E3F4"
#define RSA_A_62_reg_addr                                                             "0xB806E3F8"
#define RSA_A_63_reg_addr                                                             "0xB806E3FC"
#define RSA_A_0_reg                                                                  0xB806E300
#define RSA_A_1_reg                                                                  0xB806E304
#define RSA_A_2_reg                                                                  0xB806E308
#define RSA_A_3_reg                                                                  0xB806E30C
#define RSA_A_4_reg                                                                  0xB806E310
#define RSA_A_5_reg                                                                  0xB806E314
#define RSA_A_6_reg                                                                  0xB806E318
#define RSA_A_7_reg                                                                  0xB806E31C
#define RSA_A_8_reg                                                                  0xB806E320
#define RSA_A_9_reg                                                                  0xB806E324
#define RSA_A_10_reg                                                                  0xB806E328
#define RSA_A_11_reg                                                                  0xB806E32C
#define RSA_A_12_reg                                                                  0xB806E330
#define RSA_A_13_reg                                                                  0xB806E334
#define RSA_A_14_reg                                                                  0xB806E338
#define RSA_A_15_reg                                                                  0xB806E33C
#define RSA_A_16_reg                                                                  0xB806E340
#define RSA_A_17_reg                                                                  0xB806E344
#define RSA_A_18_reg                                                                  0xB806E348
#define RSA_A_19_reg                                                                  0xB806E34C
#define RSA_A_20_reg                                                                  0xB806E350
#define RSA_A_21_reg                                                                  0xB806E354
#define RSA_A_22_reg                                                                  0xB806E358
#define RSA_A_23_reg                                                                  0xB806E35C
#define RSA_A_24_reg                                                                  0xB806E360
#define RSA_A_25_reg                                                                  0xB806E364
#define RSA_A_26_reg                                                                  0xB806E368
#define RSA_A_27_reg                                                                  0xB806E36C
#define RSA_A_28_reg                                                                  0xB806E370
#define RSA_A_29_reg                                                                  0xB806E374
#define RSA_A_30_reg                                                                  0xB806E378
#define RSA_A_31_reg                                                                  0xB806E37C
#define RSA_A_32_reg                                                                  0xB806E380
#define RSA_A_33_reg                                                                  0xB806E384
#define RSA_A_34_reg                                                                  0xB806E388
#define RSA_A_35_reg                                                                  0xB806E38C
#define RSA_A_36_reg                                                                  0xB806E390
#define RSA_A_37_reg                                                                  0xB806E394
#define RSA_A_38_reg                                                                  0xB806E398
#define RSA_A_39_reg                                                                  0xB806E39C
#define RSA_A_40_reg                                                                  0xB806E3A0
#define RSA_A_41_reg                                                                  0xB806E3A4
#define RSA_A_42_reg                                                                  0xB806E3A8
#define RSA_A_43_reg                                                                  0xB806E3AC
#define RSA_A_44_reg                                                                  0xB806E3B0
#define RSA_A_45_reg                                                                  0xB806E3B4
#define RSA_A_46_reg                                                                  0xB806E3B8
#define RSA_A_47_reg                                                                  0xB806E3BC
#define RSA_A_48_reg                                                                  0xB806E3C0
#define RSA_A_49_reg                                                                  0xB806E3C4
#define RSA_A_50_reg                                                                  0xB806E3C8
#define RSA_A_51_reg                                                                  0xB806E3CC
#define RSA_A_52_reg                                                                  0xB806E3D0
#define RSA_A_53_reg                                                                  0xB806E3D4
#define RSA_A_54_reg                                                                  0xB806E3D8
#define RSA_A_55_reg                                                                  0xB806E3DC
#define RSA_A_56_reg                                                                  0xB806E3E0
#define RSA_A_57_reg                                                                  0xB806E3E4
#define RSA_A_58_reg                                                                  0xB806E3E8
#define RSA_A_59_reg                                                                  0xB806E3EC
#define RSA_A_60_reg                                                                  0xB806E3F0
#define RSA_A_61_reg                                                                  0xB806E3F4
#define RSA_A_62_reg                                                                  0xB806E3F8
#define RSA_A_63_reg                                                                  0xB806E3FC
#define set_RSA_A_0_reg(data)   (*((volatile unsigned int*) RSA_A_0_reg)=data)
#define set_RSA_A_1_reg(data)   (*((volatile unsigned int*) RSA_A_1_reg)=data)
#define set_RSA_A_2_reg(data)   (*((volatile unsigned int*) RSA_A_2_reg)=data)
#define set_RSA_A_3_reg(data)   (*((volatile unsigned int*) RSA_A_3_reg)=data)
#define set_RSA_A_4_reg(data)   (*((volatile unsigned int*) RSA_A_4_reg)=data)
#define set_RSA_A_5_reg(data)   (*((volatile unsigned int*) RSA_A_5_reg)=data)
#define set_RSA_A_6_reg(data)   (*((volatile unsigned int*) RSA_A_6_reg)=data)
#define set_RSA_A_7_reg(data)   (*((volatile unsigned int*) RSA_A_7_reg)=data)
#define set_RSA_A_8_reg(data)   (*((volatile unsigned int*) RSA_A_8_reg)=data)
#define set_RSA_A_9_reg(data)   (*((volatile unsigned int*) RSA_A_9_reg)=data)
#define set_RSA_A_10_reg(data)   (*((volatile unsigned int*) RSA_A_10_reg)=data)
#define set_RSA_A_11_reg(data)   (*((volatile unsigned int*) RSA_A_11_reg)=data)
#define set_RSA_A_12_reg(data)   (*((volatile unsigned int*) RSA_A_12_reg)=data)
#define set_RSA_A_13_reg(data)   (*((volatile unsigned int*) RSA_A_13_reg)=data)
#define set_RSA_A_14_reg(data)   (*((volatile unsigned int*) RSA_A_14_reg)=data)
#define set_RSA_A_15_reg(data)   (*((volatile unsigned int*) RSA_A_15_reg)=data)
#define set_RSA_A_16_reg(data)   (*((volatile unsigned int*) RSA_A_16_reg)=data)
#define set_RSA_A_17_reg(data)   (*((volatile unsigned int*) RSA_A_17_reg)=data)
#define set_RSA_A_18_reg(data)   (*((volatile unsigned int*) RSA_A_18_reg)=data)
#define set_RSA_A_19_reg(data)   (*((volatile unsigned int*) RSA_A_19_reg)=data)
#define set_RSA_A_20_reg(data)   (*((volatile unsigned int*) RSA_A_20_reg)=data)
#define set_RSA_A_21_reg(data)   (*((volatile unsigned int*) RSA_A_21_reg)=data)
#define set_RSA_A_22_reg(data)   (*((volatile unsigned int*) RSA_A_22_reg)=data)
#define set_RSA_A_23_reg(data)   (*((volatile unsigned int*) RSA_A_23_reg)=data)
#define set_RSA_A_24_reg(data)   (*((volatile unsigned int*) RSA_A_24_reg)=data)
#define set_RSA_A_25_reg(data)   (*((volatile unsigned int*) RSA_A_25_reg)=data)
#define set_RSA_A_26_reg(data)   (*((volatile unsigned int*) RSA_A_26_reg)=data)
#define set_RSA_A_27_reg(data)   (*((volatile unsigned int*) RSA_A_27_reg)=data)
#define set_RSA_A_28_reg(data)   (*((volatile unsigned int*) RSA_A_28_reg)=data)
#define set_RSA_A_29_reg(data)   (*((volatile unsigned int*) RSA_A_29_reg)=data)
#define set_RSA_A_30_reg(data)   (*((volatile unsigned int*) RSA_A_30_reg)=data)
#define set_RSA_A_31_reg(data)   (*((volatile unsigned int*) RSA_A_31_reg)=data)
#define set_RSA_A_32_reg(data)   (*((volatile unsigned int*) RSA_A_32_reg)=data)
#define set_RSA_A_33_reg(data)   (*((volatile unsigned int*) RSA_A_33_reg)=data)
#define set_RSA_A_34_reg(data)   (*((volatile unsigned int*) RSA_A_34_reg)=data)
#define set_RSA_A_35_reg(data)   (*((volatile unsigned int*) RSA_A_35_reg)=data)
#define set_RSA_A_36_reg(data)   (*((volatile unsigned int*) RSA_A_36_reg)=data)
#define set_RSA_A_37_reg(data)   (*((volatile unsigned int*) RSA_A_37_reg)=data)
#define set_RSA_A_38_reg(data)   (*((volatile unsigned int*) RSA_A_38_reg)=data)
#define set_RSA_A_39_reg(data)   (*((volatile unsigned int*) RSA_A_39_reg)=data)
#define set_RSA_A_40_reg(data)   (*((volatile unsigned int*) RSA_A_40_reg)=data)
#define set_RSA_A_41_reg(data)   (*((volatile unsigned int*) RSA_A_41_reg)=data)
#define set_RSA_A_42_reg(data)   (*((volatile unsigned int*) RSA_A_42_reg)=data)
#define set_RSA_A_43_reg(data)   (*((volatile unsigned int*) RSA_A_43_reg)=data)
#define set_RSA_A_44_reg(data)   (*((volatile unsigned int*) RSA_A_44_reg)=data)
#define set_RSA_A_45_reg(data)   (*((volatile unsigned int*) RSA_A_45_reg)=data)
#define set_RSA_A_46_reg(data)   (*((volatile unsigned int*) RSA_A_46_reg)=data)
#define set_RSA_A_47_reg(data)   (*((volatile unsigned int*) RSA_A_47_reg)=data)
#define set_RSA_A_48_reg(data)   (*((volatile unsigned int*) RSA_A_48_reg)=data)
#define set_RSA_A_49_reg(data)   (*((volatile unsigned int*) RSA_A_49_reg)=data)
#define set_RSA_A_50_reg(data)   (*((volatile unsigned int*) RSA_A_50_reg)=data)
#define set_RSA_A_51_reg(data)   (*((volatile unsigned int*) RSA_A_51_reg)=data)
#define set_RSA_A_52_reg(data)   (*((volatile unsigned int*) RSA_A_52_reg)=data)
#define set_RSA_A_53_reg(data)   (*((volatile unsigned int*) RSA_A_53_reg)=data)
#define set_RSA_A_54_reg(data)   (*((volatile unsigned int*) RSA_A_54_reg)=data)
#define set_RSA_A_55_reg(data)   (*((volatile unsigned int*) RSA_A_55_reg)=data)
#define set_RSA_A_56_reg(data)   (*((volatile unsigned int*) RSA_A_56_reg)=data)
#define set_RSA_A_57_reg(data)   (*((volatile unsigned int*) RSA_A_57_reg)=data)
#define set_RSA_A_58_reg(data)   (*((volatile unsigned int*) RSA_A_58_reg)=data)
#define set_RSA_A_59_reg(data)   (*((volatile unsigned int*) RSA_A_59_reg)=data)
#define set_RSA_A_60_reg(data)   (*((volatile unsigned int*) RSA_A_60_reg)=data)
#define set_RSA_A_61_reg(data)   (*((volatile unsigned int*) RSA_A_61_reg)=data)
#define set_RSA_A_62_reg(data)   (*((volatile unsigned int*) RSA_A_62_reg)=data)
#define set_RSA_A_63_reg(data)   (*((volatile unsigned int*) RSA_A_63_reg)=data)
#define get_RSA_A_0_reg   (*((volatile unsigned int*) RSA_A_0_reg))
#define get_RSA_A_1_reg   (*((volatile unsigned int*) RSA_A_1_reg))
#define get_RSA_A_2_reg   (*((volatile unsigned int*) RSA_A_2_reg))
#define get_RSA_A_3_reg   (*((volatile unsigned int*) RSA_A_3_reg))
#define get_RSA_A_4_reg   (*((volatile unsigned int*) RSA_A_4_reg))
#define get_RSA_A_5_reg   (*((volatile unsigned int*) RSA_A_5_reg))
#define get_RSA_A_6_reg   (*((volatile unsigned int*) RSA_A_6_reg))
#define get_RSA_A_7_reg   (*((volatile unsigned int*) RSA_A_7_reg))
#define get_RSA_A_8_reg   (*((volatile unsigned int*) RSA_A_8_reg))
#define get_RSA_A_9_reg   (*((volatile unsigned int*) RSA_A_9_reg))
#define get_RSA_A_10_reg   (*((volatile unsigned int*) RSA_A_10_reg))
#define get_RSA_A_11_reg   (*((volatile unsigned int*) RSA_A_11_reg))
#define get_RSA_A_12_reg   (*((volatile unsigned int*) RSA_A_12_reg))
#define get_RSA_A_13_reg   (*((volatile unsigned int*) RSA_A_13_reg))
#define get_RSA_A_14_reg   (*((volatile unsigned int*) RSA_A_14_reg))
#define get_RSA_A_15_reg   (*((volatile unsigned int*) RSA_A_15_reg))
#define get_RSA_A_16_reg   (*((volatile unsigned int*) RSA_A_16_reg))
#define get_RSA_A_17_reg   (*((volatile unsigned int*) RSA_A_17_reg))
#define get_RSA_A_18_reg   (*((volatile unsigned int*) RSA_A_18_reg))
#define get_RSA_A_19_reg   (*((volatile unsigned int*) RSA_A_19_reg))
#define get_RSA_A_20_reg   (*((volatile unsigned int*) RSA_A_20_reg))
#define get_RSA_A_21_reg   (*((volatile unsigned int*) RSA_A_21_reg))
#define get_RSA_A_22_reg   (*((volatile unsigned int*) RSA_A_22_reg))
#define get_RSA_A_23_reg   (*((volatile unsigned int*) RSA_A_23_reg))
#define get_RSA_A_24_reg   (*((volatile unsigned int*) RSA_A_24_reg))
#define get_RSA_A_25_reg   (*((volatile unsigned int*) RSA_A_25_reg))
#define get_RSA_A_26_reg   (*((volatile unsigned int*) RSA_A_26_reg))
#define get_RSA_A_27_reg   (*((volatile unsigned int*) RSA_A_27_reg))
#define get_RSA_A_28_reg   (*((volatile unsigned int*) RSA_A_28_reg))
#define get_RSA_A_29_reg   (*((volatile unsigned int*) RSA_A_29_reg))
#define get_RSA_A_30_reg   (*((volatile unsigned int*) RSA_A_30_reg))
#define get_RSA_A_31_reg   (*((volatile unsigned int*) RSA_A_31_reg))
#define get_RSA_A_32_reg   (*((volatile unsigned int*) RSA_A_32_reg))
#define get_RSA_A_33_reg   (*((volatile unsigned int*) RSA_A_33_reg))
#define get_RSA_A_34_reg   (*((volatile unsigned int*) RSA_A_34_reg))
#define get_RSA_A_35_reg   (*((volatile unsigned int*) RSA_A_35_reg))
#define get_RSA_A_36_reg   (*((volatile unsigned int*) RSA_A_36_reg))
#define get_RSA_A_37_reg   (*((volatile unsigned int*) RSA_A_37_reg))
#define get_RSA_A_38_reg   (*((volatile unsigned int*) RSA_A_38_reg))
#define get_RSA_A_39_reg   (*((volatile unsigned int*) RSA_A_39_reg))
#define get_RSA_A_40_reg   (*((volatile unsigned int*) RSA_A_40_reg))
#define get_RSA_A_41_reg   (*((volatile unsigned int*) RSA_A_41_reg))
#define get_RSA_A_42_reg   (*((volatile unsigned int*) RSA_A_42_reg))
#define get_RSA_A_43_reg   (*((volatile unsigned int*) RSA_A_43_reg))
#define get_RSA_A_44_reg   (*((volatile unsigned int*) RSA_A_44_reg))
#define get_RSA_A_45_reg   (*((volatile unsigned int*) RSA_A_45_reg))
#define get_RSA_A_46_reg   (*((volatile unsigned int*) RSA_A_46_reg))
#define get_RSA_A_47_reg   (*((volatile unsigned int*) RSA_A_47_reg))
#define get_RSA_A_48_reg   (*((volatile unsigned int*) RSA_A_48_reg))
#define get_RSA_A_49_reg   (*((volatile unsigned int*) RSA_A_49_reg))
#define get_RSA_A_50_reg   (*((volatile unsigned int*) RSA_A_50_reg))
#define get_RSA_A_51_reg   (*((volatile unsigned int*) RSA_A_51_reg))
#define get_RSA_A_52_reg   (*((volatile unsigned int*) RSA_A_52_reg))
#define get_RSA_A_53_reg   (*((volatile unsigned int*) RSA_A_53_reg))
#define get_RSA_A_54_reg   (*((volatile unsigned int*) RSA_A_54_reg))
#define get_RSA_A_55_reg   (*((volatile unsigned int*) RSA_A_55_reg))
#define get_RSA_A_56_reg   (*((volatile unsigned int*) RSA_A_56_reg))
#define get_RSA_A_57_reg   (*((volatile unsigned int*) RSA_A_57_reg))
#define get_RSA_A_58_reg   (*((volatile unsigned int*) RSA_A_58_reg))
#define get_RSA_A_59_reg   (*((volatile unsigned int*) RSA_A_59_reg))
#define get_RSA_A_60_reg   (*((volatile unsigned int*) RSA_A_60_reg))
#define get_RSA_A_61_reg   (*((volatile unsigned int*) RSA_A_61_reg))
#define get_RSA_A_62_reg   (*((volatile unsigned int*) RSA_A_62_reg))
#define get_RSA_A_63_reg   (*((volatile unsigned int*) RSA_A_63_reg))
#define RSA_A_0_inst_adr                                                             "0x00C0"
#define RSA_A_1_inst_adr                                                             "0x00C1"
#define RSA_A_2_inst_adr                                                             "0x00C2"
#define RSA_A_3_inst_adr                                                             "0x00C3"
#define RSA_A_4_inst_adr                                                             "0x00C4"
#define RSA_A_5_inst_adr                                                             "0x00C5"
#define RSA_A_6_inst_adr                                                             "0x00C6"
#define RSA_A_7_inst_adr                                                             "0x00C7"
#define RSA_A_8_inst_adr                                                             "0x00C8"
#define RSA_A_9_inst_adr                                                             "0x00C9"
#define RSA_A_10_inst_adr                                                             "0x00CA"
#define RSA_A_11_inst_adr                                                             "0x00CB"
#define RSA_A_12_inst_adr                                                             "0x00CC"
#define RSA_A_13_inst_adr                                                             "0x00CD"
#define RSA_A_14_inst_adr                                                             "0x00CE"
#define RSA_A_15_inst_adr                                                             "0x00CF"
#define RSA_A_16_inst_adr                                                             "0x00D0"
#define RSA_A_17_inst_adr                                                             "0x00D1"
#define RSA_A_18_inst_adr                                                             "0x00D2"
#define RSA_A_19_inst_adr                                                             "0x00D3"
#define RSA_A_20_inst_adr                                                             "0x00D4"
#define RSA_A_21_inst_adr                                                             "0x00D5"
#define RSA_A_22_inst_adr                                                             "0x00D6"
#define RSA_A_23_inst_adr                                                             "0x00D7"
#define RSA_A_24_inst_adr                                                             "0x00D8"
#define RSA_A_25_inst_adr                                                             "0x00D9"
#define RSA_A_26_inst_adr                                                             "0x00DA"
#define RSA_A_27_inst_adr                                                             "0x00DB"
#define RSA_A_28_inst_adr                                                             "0x00DC"
#define RSA_A_29_inst_adr                                                             "0x00DD"
#define RSA_A_30_inst_adr                                                             "0x00DE"
#define RSA_A_31_inst_adr                                                             "0x00DF"
#define RSA_A_32_inst_adr                                                             "0x00E0"
#define RSA_A_33_inst_adr                                                             "0x00E1"
#define RSA_A_34_inst_adr                                                             "0x00E2"
#define RSA_A_35_inst_adr                                                             "0x00E3"
#define RSA_A_36_inst_adr                                                             "0x00E4"
#define RSA_A_37_inst_adr                                                             "0x00E5"
#define RSA_A_38_inst_adr                                                             "0x00E6"
#define RSA_A_39_inst_adr                                                             "0x00E7"
#define RSA_A_40_inst_adr                                                             "0x00E8"
#define RSA_A_41_inst_adr                                                             "0x00E9"
#define RSA_A_42_inst_adr                                                             "0x00EA"
#define RSA_A_43_inst_adr                                                             "0x00EB"
#define RSA_A_44_inst_adr                                                             "0x00EC"
#define RSA_A_45_inst_adr                                                             "0x00ED"
#define RSA_A_46_inst_adr                                                             "0x00EE"
#define RSA_A_47_inst_adr                                                             "0x00EF"
#define RSA_A_48_inst_adr                                                             "0x00F0"
#define RSA_A_49_inst_adr                                                             "0x00F1"
#define RSA_A_50_inst_adr                                                             "0x00F2"
#define RSA_A_51_inst_adr                                                             "0x00F3"
#define RSA_A_52_inst_adr                                                             "0x00F4"
#define RSA_A_53_inst_adr                                                             "0x00F5"
#define RSA_A_54_inst_adr                                                             "0x00F6"
#define RSA_A_55_inst_adr                                                             "0x00F7"
#define RSA_A_56_inst_adr                                                             "0x00F8"
#define RSA_A_57_inst_adr                                                             "0x00F9"
#define RSA_A_58_inst_adr                                                             "0x00FA"
#define RSA_A_59_inst_adr                                                             "0x00FB"
#define RSA_A_60_inst_adr                                                             "0x00FC"
#define RSA_A_61_inst_adr                                                             "0x00FD"
#define RSA_A_62_inst_adr                                                             "0x00FE"
#define RSA_A_63_inst_adr                                                             "0x00FF"
#define RSA_A_0_inst                                                                 0x00C0
#define RSA_A_1_inst                                                                 0x00C1
#define RSA_A_2_inst                                                                 0x00C2
#define RSA_A_3_inst                                                                 0x00C3
#define RSA_A_4_inst                                                                 0x00C4
#define RSA_A_5_inst                                                                 0x00C5
#define RSA_A_6_inst                                                                 0x00C6
#define RSA_A_7_inst                                                                 0x00C7
#define RSA_A_8_inst                                                                 0x00C8
#define RSA_A_9_inst                                                                 0x00C9
#define RSA_A_10_inst                                                                 0x00CA
#define RSA_A_11_inst                                                                 0x00CB
#define RSA_A_12_inst                                                                 0x00CC
#define RSA_A_13_inst                                                                 0x00CD
#define RSA_A_14_inst                                                                 0x00CE
#define RSA_A_15_inst                                                                 0x00CF
#define RSA_A_16_inst                                                                 0x00D0
#define RSA_A_17_inst                                                                 0x00D1
#define RSA_A_18_inst                                                                 0x00D2
#define RSA_A_19_inst                                                                 0x00D3
#define RSA_A_20_inst                                                                 0x00D4
#define RSA_A_21_inst                                                                 0x00D5
#define RSA_A_22_inst                                                                 0x00D6
#define RSA_A_23_inst                                                                 0x00D7
#define RSA_A_24_inst                                                                 0x00D8
#define RSA_A_25_inst                                                                 0x00D9
#define RSA_A_26_inst                                                                 0x00DA
#define RSA_A_27_inst                                                                 0x00DB
#define RSA_A_28_inst                                                                 0x00DC
#define RSA_A_29_inst                                                                 0x00DD
#define RSA_A_30_inst                                                                 0x00DE
#define RSA_A_31_inst                                                                 0x00DF
#define RSA_A_32_inst                                                                 0x00E0
#define RSA_A_33_inst                                                                 0x00E1
#define RSA_A_34_inst                                                                 0x00E2
#define RSA_A_35_inst                                                                 0x00E3
#define RSA_A_36_inst                                                                 0x00E4
#define RSA_A_37_inst                                                                 0x00E5
#define RSA_A_38_inst                                                                 0x00E6
#define RSA_A_39_inst                                                                 0x00E7
#define RSA_A_40_inst                                                                 0x00E8
#define RSA_A_41_inst                                                                 0x00E9
#define RSA_A_42_inst                                                                 0x00EA
#define RSA_A_43_inst                                                                 0x00EB
#define RSA_A_44_inst                                                                 0x00EC
#define RSA_A_45_inst                                                                 0x00ED
#define RSA_A_46_inst                                                                 0x00EE
#define RSA_A_47_inst                                                                 0x00EF
#define RSA_A_48_inst                                                                 0x00F0
#define RSA_A_49_inst                                                                 0x00F1
#define RSA_A_50_inst                                                                 0x00F2
#define RSA_A_51_inst                                                                 0x00F3
#define RSA_A_52_inst                                                                 0x00F4
#define RSA_A_53_inst                                                                 0x00F5
#define RSA_A_54_inst                                                                 0x00F6
#define RSA_A_55_inst                                                                 0x00F7
#define RSA_A_56_inst                                                                 0x00F8
#define RSA_A_57_inst                                                                 0x00F9
#define RSA_A_58_inst                                                                 0x00FA
#define RSA_A_59_inst                                                                 0x00FB
#define RSA_A_60_inst                                                                 0x00FC
#define RSA_A_61_inst                                                                 0x00FD
#define RSA_A_62_inst                                                                 0x00FE
#define RSA_A_63_inst                                                                 0x00FF
#define RSA_A_data_shift                                                             (0)
#define RSA_A_data_mask                                                              (0xFFFFFFFF)
#define RSA_A_data(data)                                                             (0xFFFFFFFF&((data)<<0))
#define RSA_A_data_src(data)                                                         ((0xFFFFFFFF&(data))>>0)
#define RSA_A_get_data(data)                                                         ((0xFFFFFFFF&(data))>>0)


#define RSA_CTRL                                                                     0x1806E400
#define RSA_CTRL_reg_addr                                                            "0xB806E400"
#define RSA_CTRL_reg                                                                 0xB806E400
#define set_RSA_CTRL_reg(data)   (*((volatile unsigned int*) RSA_CTRL_reg)=data)
#define get_RSA_CTRL_reg   (*((volatile unsigned int*) RSA_CTRL_reg))
#define RSA_CTRL_inst_adr                                                            "0x0000"
#define RSA_CTRL_inst                                                                0x0000
#define RSA_CTRL_go_shift                                                            (0)
#define RSA_CTRL_go_mask                                                             (0x00000001)
#define RSA_CTRL_go(data)                                                            (0x00000001&((data)<<0))
#define RSA_CTRL_go_src(data)                                                        ((0x00000001&(data))>>0)
#define RSA_CTRL_get_go(data)                                                        ((0x00000001&(data))>>0)


#define RSA_NUM                                                                      0x1806E404
#define RSA_NUM_reg_addr                                                             "0xB806E404"
#define RSA_NUM_reg                                                                  0xB806E404
#define set_RSA_NUM_reg(data)   (*((volatile unsigned int*) RSA_NUM_reg)=data)
#define get_RSA_NUM_reg   (*((volatile unsigned int*) RSA_NUM_reg))
#define RSA_NUM_inst_adr                                                             "0x0001"
#define RSA_NUM_inst                                                                 0x0001
#define RSA_NUM_bits_num_shift                                                       (0)
#define RSA_NUM_bits_num_mask                                                        (0x0000003F)
#define RSA_NUM_bits_num(data)                                                       (0x0000003F&((data)<<0))
#define RSA_NUM_bits_num_src(data)                                                   ((0x0000003F&(data))>>0)
#define RSA_NUM_get_bits_num(data)                                                   ((0x0000003F&(data))>>0)


#define RSA_INT_STATUS                                                               0x1806E408
#define RSA_INT_STATUS_reg_addr                                                      "0xB806E408"
#define RSA_INT_STATUS_reg                                                           0xB806E408
#define set_RSA_INT_STATUS_reg(data)   (*((volatile unsigned int*) RSA_INT_STATUS_reg)=data)
#define get_RSA_INT_STATUS_reg   (*((volatile unsigned int*) RSA_INT_STATUS_reg))
#define RSA_INT_STATUS_inst_adr                                                      "0x0002"
#define RSA_INT_STATUS_inst                                                          0x0002
#define RSA_INT_STATUS_rsa_done_shift                                                (0)
#define RSA_INT_STATUS_rsa_done_mask                                                 (0x00000001)
#define RSA_INT_STATUS_rsa_done(data)                                                (0x00000001&((data)<<0))
#define RSA_INT_STATUS_rsa_done_src(data)                                            ((0x00000001&(data))>>0)
#define RSA_INT_STATUS_get_rsa_done(data)                                            ((0x00000001&(data))>>0)


#define RSA_CLEAR                                                                    0x1806E40C
#define RSA_CLEAR_reg_addr                                                           "0xB806E40C"
#define RSA_CLEAR_reg                                                                0xB806E40C
#define set_RSA_CLEAR_reg(data)   (*((volatile unsigned int*) RSA_CLEAR_reg)=data)
#define get_RSA_CLEAR_reg   (*((volatile unsigned int*) RSA_CLEAR_reg))
#define RSA_CLEAR_inst_adr                                                           "0x0003"
#define RSA_CLEAR_inst                                                               0x0003
#define RSA_CLEAR_rsa_clear_shift                                                    (0)
#define RSA_CLEAR_rsa_clear_mask                                                     (0x00000001)
#define RSA_CLEAR_rsa_clear(data)                                                    (0x00000001&((data)<<0))
#define RSA_CLEAR_rsa_clear_src(data)                                                ((0x00000001&(data))>>0)
#define RSA_CLEAR_get_rsa_clear(data)                                                ((0x00000001&(data))>>0)


#define RSA_DUMMY                                                                    0x1806E410
#define RSA_DUMMY_reg_addr                                                           "0xB806E410"
#define RSA_DUMMY_reg                                                                0xB806E410
#define set_RSA_DUMMY_reg(data)   (*((volatile unsigned int*) RSA_DUMMY_reg)=data)
#define get_RSA_DUMMY_reg   (*((volatile unsigned int*) RSA_DUMMY_reg))
#define RSA_DUMMY_inst_adr                                                           "0x0004"
#define RSA_DUMMY_inst                                                               0x0004
#define RSA_DUMMY_dummy_shift                                                        (0)
#define RSA_DUMMY_dummy_mask                                                         (0xFFFFFFFF)
#define RSA_DUMMY_dummy(data)                                                        (0xFFFFFFFF&((data)<<0))
#define RSA_DUMMY_dummy_src(data)                                                    ((0xFFFFFFFF&(data))>>0)
#define RSA_DUMMY_get_dummy(data)                                                    ((0xFFFFFFFF&(data))>>0)


#define S_RSA_INT_EN                                                                 0x1806E500
#define S_RSA_INT_EN_reg_addr                                                        "0xB806E500"
#define S_RSA_INT_EN_reg                                                             0xB806E500
#define set_S_RSA_INT_EN_reg(data)   (*((volatile unsigned int*) S_RSA_INT_EN_reg)=data)
#define get_S_RSA_INT_EN_reg   (*((volatile unsigned int*) S_RSA_INT_EN_reg))
#define S_RSA_INT_EN_inst_adr                                                        "0x0040"
#define S_RSA_INT_EN_inst                                                            0x0040
#define S_RSA_INT_EN_scpu_en_shift                                                   (0)
#define S_RSA_INT_EN_scpu_en_mask                                                    (0x00000001)
#define S_RSA_INT_EN_scpu_en(data)                                                   (0x00000001&((data)<<0))
#define S_RSA_INT_EN_scpu_en_src(data)                                               ((0x00000001&(data))>>0)
#define S_RSA_INT_EN_get_scpu_en(data)                                               ((0x00000001&(data))>>0)


#define S_RSA_SEL                                                                    0x1806E504
#define S_RSA_SEL_reg_addr                                                           "0xB806E504"
#define S_RSA_SEL_reg                                                                0xB806E504
#define set_S_RSA_SEL_reg(data)   (*((volatile unsigned int*) S_RSA_SEL_reg)=data)
#define get_S_RSA_SEL_reg   (*((volatile unsigned int*) S_RSA_SEL_reg))
#define S_RSA_SEL_inst_adr                                                           "0x0041"
#define S_RSA_SEL_inst                                                               0x0041
#define S_RSA_SEL_scpu_sel_shift                                                     (0)
#define S_RSA_SEL_scpu_sel_mask                                                      (0x00000001)
#define S_RSA_SEL_scpu_sel(data)                                                     (0x00000001&((data)<<0))
#define S_RSA_SEL_scpu_sel_src(data)                                                 ((0x00000001&(data))>>0)
#define S_RSA_SEL_get_scpu_sel(data)                                                 ((0x00000001&(data))>>0)


#define S_RSA_ST                                                                     0x1806E508
#define S_RSA_ST_reg_addr                                                            "0xB806E508"
#define S_RSA_ST_reg                                                                 0xB806E508
#define set_S_RSA_ST_reg(data)   (*((volatile unsigned int*) S_RSA_ST_reg)=data)
#define get_S_RSA_ST_reg   (*((volatile unsigned int*) S_RSA_ST_reg))
#define S_RSA_ST_inst_adr                                                            "0x0042"
#define S_RSA_ST_inst                                                                0x0042
#define S_RSA_ST_scpu_st_shift                                                       (0)
#define S_RSA_ST_scpu_st_mask                                                        (0x00000001)
#define S_RSA_ST_scpu_st(data)                                                       (0x00000001&((data)<<0))
#define S_RSA_ST_scpu_st_src(data)                                                   ((0x00000001&(data))>>0)
#define S_RSA_ST_get_scpu_st(data)                                                   ((0x00000001&(data))>>0)


#define K_RSA_INT_EN                                                                 0x1806E600
#define K_RSA_INT_EN_reg_addr                                                        "0xB806E600"
#define K_RSA_INT_EN_reg                                                             0xB806E600
#define set_K_RSA_INT_EN_reg(data)   (*((volatile unsigned int*) K_RSA_INT_EN_reg)=data)
#define get_K_RSA_INT_EN_reg   (*((volatile unsigned int*) K_RSA_INT_EN_reg))
#define K_RSA_INT_EN_inst_adr                                                        "0x0080"
#define K_RSA_INT_EN_inst                                                            0x0080
#define K_RSA_INT_EN_kcpu_en_shift                                                   (0)
#define K_RSA_INT_EN_kcpu_en_mask                                                    (0x00000001)
#define K_RSA_INT_EN_kcpu_en(data)                                                   (0x00000001&((data)<<0))
#define K_RSA_INT_EN_kcpu_en_src(data)                                               ((0x00000001&(data))>>0)
#define K_RSA_INT_EN_get_kcpu_en(data)                                               ((0x00000001&(data))>>0)


#define K_RSA_SEL                                                                    0x1806E604
#define K_RSA_SEL_reg_addr                                                           "0xB806E604"
#define K_RSA_SEL_reg                                                                0xB806E604
#define set_K_RSA_SEL_reg(data)   (*((volatile unsigned int*) K_RSA_SEL_reg)=data)
#define get_K_RSA_SEL_reg   (*((volatile unsigned int*) K_RSA_SEL_reg))
#define K_RSA_SEL_inst_adr                                                           "0x0081"
#define K_RSA_SEL_inst                                                               0x0081
#define K_RSA_SEL_kcpu_sel_shift                                                     (0)
#define K_RSA_SEL_kcpu_sel_mask                                                      (0x00000001)
#define K_RSA_SEL_kcpu_sel(data)                                                     (0x00000001&((data)<<0))
#define K_RSA_SEL_kcpu_sel_src(data)                                                 ((0x00000001&(data))>>0)
#define K_RSA_SEL_get_kcpu_sel(data)                                                 ((0x00000001&(data))>>0)


#define K_RSA_ST                                                                     0x1806E608
#define K_RSA_ST_reg_addr                                                            "0xB806E608"
#define K_RSA_ST_reg                                                                 0xB806E608
#define set_K_RSA_ST_reg(data)   (*((volatile unsigned int*) K_RSA_ST_reg)=data)
#define get_K_RSA_ST_reg   (*((volatile unsigned int*) K_RSA_ST_reg))
#define K_RSA_ST_inst_adr                                                            "0x0082"
#define K_RSA_ST_inst                                                                0x0082
#define K_RSA_ST_kcpu_st_shift                                                       (0)
#define K_RSA_ST_kcpu_st_mask                                                        (0x00000001)
#define K_RSA_ST_kcpu_st(data)                                                       (0x00000001&((data)<<0))
#define K_RSA_ST_kcpu_st_src(data)                                                   ((0x00000001&(data))>>0)
#define K_RSA_ST_get_kcpu_st(data)                                                   ((0x00000001&(data))>>0)


#define K_RSA_SECURITY                                                               0x1806E610
#define K_RSA_SECURITY_reg_addr                                                      "0xB806E610"
#define K_RSA_SECURITY_reg                                                           0xB806E610
#define set_K_RSA_SECURITY_reg(data)   (*((volatile unsigned int*) K_RSA_SECURITY_reg)=data)
#define get_K_RSA_SECURITY_reg   (*((volatile unsigned int*) K_RSA_SECURITY_reg))
#define K_RSA_SECURITY_inst_adr                                                      "0x0084"
#define K_RSA_SECURITY_inst                                                          0x0084
#define K_RSA_SECURITY_on_shift                                                      (0)
#define K_RSA_SECURITY_on_mask                                                       (0x00000001)
#define K_RSA_SECURITY_on(data)                                                      (0x00000001&((data)<<0))
#define K_RSA_SECURITY_on_src(data)                                                  ((0x00000001&(data))>>0)
#define K_RSA_SECURITY_get_on(data)                                                  ((0x00000001&(data))>>0)


#endif
