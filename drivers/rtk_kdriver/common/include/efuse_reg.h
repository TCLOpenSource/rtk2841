/**************************************************************
// Spec Version                  : 1.0
// Parser Version                : DVR_Parser_6.8(110516)
// CModelGen Version             : 5.0 2009.04.09
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2012/7/12 15:57:44
***************************************************************/


#ifndef _EFUSE_REG_H_INCLUDED_
#define _EFUSE_REG_H_INCLUDED_
#ifdef  _EFUSE_USE_STRUCT
typedef struct 
{
unsigned int     datao:32;
}EFUSE_DATA;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     write_enable4:1;
unsigned int     en_pro_efuse:1;
unsigned int     write_enable3:1;
unsigned int     auto_rd_req:1;
unsigned int     reserved_1:5;
unsigned int     write_enable2:1;
unsigned int     strobe:1;
unsigned int     write_enable1:1;
unsigned int     a:12;
}EFUSE_EF_CTRL;

typedef struct 
{
unsigned int     reserved_0:15;
unsigned int     pro_efuse_act:1;
unsigned int     reserved_1:15;
unsigned int     crc_en:1;
}EFUSE_EF_CTRL_ST;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     crc_ini:8;
unsigned int     reserved_1:8;
unsigned int     crc_out:8;
}EFUSE_EF_CRC;

#endif

#define EFUSE_DATA_0                                                                 0x18038000
#define EFUSE_DATA_1                                                                 0x18038004
#define EFUSE_DATA_2                                                                 0x18038008
#define EFUSE_DATA_3                                                                 0x1803800C
#define EFUSE_DATA_4                                                                 0x18038010
#define EFUSE_DATA_5                                                                 0x18038014
#define EFUSE_DATA_6                                                                 0x18038018
#define EFUSE_DATA_7                                                                 0x1803801C
#define EFUSE_DATA_8                                                                 0x18038020
#define EFUSE_DATA_9                                                                 0x18038024
#define EFUSE_DATA_10                                                                 0x18038028
#define EFUSE_DATA_11                                                                 0x1803802C
#define EFUSE_DATA_12                                                                 0x18038030
#define EFUSE_DATA_13                                                                 0x18038034
#define EFUSE_DATA_14                                                                 0x18038038
#define EFUSE_DATA_15                                                                 0x1803803C
#define EFUSE_DATA_16                                                                 0x18038040
#define EFUSE_DATA_17                                                                 0x18038044
#define EFUSE_DATA_18                                                                 0x18038048
#define EFUSE_DATA_19                                                                 0x1803804C
#define EFUSE_DATA_20                                                                 0x18038050
#define EFUSE_DATA_21                                                                 0x18038054
#define EFUSE_DATA_22                                                                 0x18038058
#define EFUSE_DATA_23                                                                 0x1803805C
#define EFUSE_DATA_24                                                                 0x18038060
#define EFUSE_DATA_25                                                                 0x18038064
#define EFUSE_DATA_26                                                                 0x18038068
#define EFUSE_DATA_27                                                                 0x1803806C
#define EFUSE_DATA_28                                                                 0x18038070
#define EFUSE_DATA_29                                                                 0x18038074
#define EFUSE_DATA_30                                                                 0x18038078
#define EFUSE_DATA_31                                                                 0x1803807C
#define EFUSE_DATA_32                                                                 0x18038080
#define EFUSE_DATA_33                                                                 0x18038084
#define EFUSE_DATA_34                                                                 0x18038088
#define EFUSE_DATA_35                                                                 0x1803808C
#define EFUSE_DATA_36                                                                 0x18038090
#define EFUSE_DATA_37                                                                 0x18038094
#define EFUSE_DATA_38                                                                 0x18038098
#define EFUSE_DATA_39                                                                 0x1803809C
#define EFUSE_DATA_40                                                                 0x180380A0
#define EFUSE_DATA_41                                                                 0x180380A4
#define EFUSE_DATA_42                                                                 0x180380A8
#define EFUSE_DATA_43                                                                 0x180380AC
#define EFUSE_DATA_44                                                                 0x180380B0
#define EFUSE_DATA_45                                                                 0x180380B4
#define EFUSE_DATA_46                                                                 0x180380B8
#define EFUSE_DATA_47                                                                 0x180380BC
#define EFUSE_DATA_48                                                                 0x180380C0
#define EFUSE_DATA_49                                                                 0x180380C4
#define EFUSE_DATA_50                                                                 0x180380C8
#define EFUSE_DATA_51                                                                 0x180380CC
#define EFUSE_DATA_52                                                                 0x180380D0
#define EFUSE_DATA_53                                                                 0x180380D4
#define EFUSE_DATA_54                                                                 0x180380D8
#define EFUSE_DATA_55                                                                 0x180380DC
#define EFUSE_DATA_56                                                                 0x180380E0
#define EFUSE_DATA_57                                                                 0x180380E4
#define EFUSE_DATA_58                                                                 0x180380E8
#define EFUSE_DATA_59                                                                 0x180380EC
#define EFUSE_DATA_60                                                                 0x180380F0
#define EFUSE_DATA_61                                                                 0x180380F4
#define EFUSE_DATA_62                                                                 0x180380F8
#define EFUSE_DATA_63                                                                 0x180380FC
#define EFUSE_DATA_64                                                                 0x18038100
#define EFUSE_DATA_65                                                                 0x18038104
#define EFUSE_DATA_66                                                                 0x18038108
#define EFUSE_DATA_67                                                                 0x1803810C
#define EFUSE_DATA_68                                                                 0x18038110
#define EFUSE_DATA_69                                                                 0x18038114
#define EFUSE_DATA_70                                                                 0x18038118
#define EFUSE_DATA_71                                                                 0x1803811C
#define EFUSE_DATA_72                                                                 0x18038120
#define EFUSE_DATA_73                                                                 0x18038124
#define EFUSE_DATA_74                                                                 0x18038128
#define EFUSE_DATA_75                                                                 0x1803812C
#define EFUSE_DATA_76                                                                 0x18038130
#define EFUSE_DATA_77                                                                 0x18038134
#define EFUSE_DATA_78                                                                 0x18038138
#define EFUSE_DATA_79                                                                 0x1803813C
#define EFUSE_DATA_80                                                                 0x18038140
#define EFUSE_DATA_81                                                                 0x18038144
#define EFUSE_DATA_82                                                                 0x18038148
#define EFUSE_DATA_83                                                                 0x1803814C
#define EFUSE_DATA_84                                                                 0x18038150
#define EFUSE_DATA_85                                                                 0x18038154
#define EFUSE_DATA_86                                                                 0x18038158
#define EFUSE_DATA_87                                                                 0x1803815C
#define EFUSE_DATA_88                                                                 0x18038160
#define EFUSE_DATA_89                                                                 0x18038164
#define EFUSE_DATA_90                                                                 0x18038168
#define EFUSE_DATA_91                                                                 0x1803816C
#define EFUSE_DATA_92                                                                 0x18038170
#define EFUSE_DATA_93                                                                 0x18038174
#define EFUSE_DATA_94                                                                 0x18038178
#define EFUSE_DATA_95                                                                 0x1803817C
#define EFUSE_DATA_96                                                                 0x18038180
#define EFUSE_DATA_97                                                                 0x18038184
#define EFUSE_DATA_98                                                                 0x18038188
#define EFUSE_DATA_99                                                                 0x1803818C
#define EFUSE_DATA_100                                                                 0x18038190
#define EFUSE_DATA_101                                                                 0x18038194
#define EFUSE_DATA_102                                                                 0x18038198
#define EFUSE_DATA_103                                                                 0x1803819C
#define EFUSE_DATA_104                                                                 0x180381A0
#define EFUSE_DATA_105                                                                 0x180381A4
#define EFUSE_DATA_106                                                                 0x180381A8
#define EFUSE_DATA_107                                                                 0x180381AC
#define EFUSE_DATA_108                                                                 0x180381B0
#define EFUSE_DATA_109                                                                 0x180381B4
#define EFUSE_DATA_110                                                                 0x180381B8
#define EFUSE_DATA_111                                                                 0x180381BC
#define EFUSE_DATA_112                                                                 0x180381C0
#define EFUSE_DATA_113                                                                 0x180381C4
#define EFUSE_DATA_114                                                                 0x180381C8
#define EFUSE_DATA_115                                                                 0x180381CC
#define EFUSE_DATA_116                                                                 0x180381D0
#define EFUSE_DATA_117                                                                 0x180381D4
#define EFUSE_DATA_118                                                                 0x180381D8
#define EFUSE_DATA_119                                                                 0x180381DC
#define EFUSE_DATA_120                                                                 0x180381E0
#define EFUSE_DATA_121                                                                 0x180381E4
#define EFUSE_DATA_122                                                                 0x180381E8
#define EFUSE_DATA_123                                                                 0x180381EC
#define EFUSE_DATA_124                                                                 0x180381F0
#define EFUSE_DATA_125                                                                 0x180381F4
#define EFUSE_DATA_126                                                                 0x180381F8
#define EFUSE_DATA_127                                                                 0x180381FC
#define EFUSE_DATA_0_reg_addr                                                        "0xB8038000"
#define EFUSE_DATA_1_reg_addr                                                        "0xB8038004"
#define EFUSE_DATA_2_reg_addr                                                        "0xB8038008"
#define EFUSE_DATA_3_reg_addr                                                        "0xB803800C"
#define EFUSE_DATA_4_reg_addr                                                        "0xB8038010"
#define EFUSE_DATA_5_reg_addr                                                        "0xB8038014"
#define EFUSE_DATA_6_reg_addr                                                        "0xB8038018"
#define EFUSE_DATA_7_reg_addr                                                        "0xB803801C"
#define EFUSE_DATA_8_reg_addr                                                        "0xB8038020"
#define EFUSE_DATA_9_reg_addr                                                        "0xB8038024"
#define EFUSE_DATA_10_reg_addr                                                        "0xB8038028"
#define EFUSE_DATA_11_reg_addr                                                        "0xB803802C"
#define EFUSE_DATA_12_reg_addr                                                        "0xB8038030"
#define EFUSE_DATA_13_reg_addr                                                        "0xB8038034"
#define EFUSE_DATA_14_reg_addr                                                        "0xB8038038"
#define EFUSE_DATA_15_reg_addr                                                        "0xB803803C"
#define EFUSE_DATA_16_reg_addr                                                        "0xB8038040"
#define EFUSE_DATA_17_reg_addr                                                        "0xB8038044"
#define EFUSE_DATA_18_reg_addr                                                        "0xB8038048"
#define EFUSE_DATA_19_reg_addr                                                        "0xB803804C"
#define EFUSE_DATA_20_reg_addr                                                        "0xB8038050"
#define EFUSE_DATA_21_reg_addr                                                        "0xB8038054"
#define EFUSE_DATA_22_reg_addr                                                        "0xB8038058"
#define EFUSE_DATA_23_reg_addr                                                        "0xB803805C"
#define EFUSE_DATA_24_reg_addr                                                        "0xB8038060"
#define EFUSE_DATA_25_reg_addr                                                        "0xB8038064"
#define EFUSE_DATA_26_reg_addr                                                        "0xB8038068"
#define EFUSE_DATA_27_reg_addr                                                        "0xB803806C"
#define EFUSE_DATA_28_reg_addr                                                        "0xB8038070"
#define EFUSE_DATA_29_reg_addr                                                        "0xB8038074"
#define EFUSE_DATA_30_reg_addr                                                        "0xB8038078"
#define EFUSE_DATA_31_reg_addr                                                        "0xB803807C"
#define EFUSE_DATA_32_reg_addr                                                        "0xB8038080"
#define EFUSE_DATA_33_reg_addr                                                        "0xB8038084"
#define EFUSE_DATA_34_reg_addr                                                        "0xB8038088"
#define EFUSE_DATA_35_reg_addr                                                        "0xB803808C"
#define EFUSE_DATA_36_reg_addr                                                        "0xB8038090"
#define EFUSE_DATA_37_reg_addr                                                        "0xB8038094"
#define EFUSE_DATA_38_reg_addr                                                        "0xB8038098"
#define EFUSE_DATA_39_reg_addr                                                        "0xB803809C"
#define EFUSE_DATA_40_reg_addr                                                        "0xB80380A0"
#define EFUSE_DATA_41_reg_addr                                                        "0xB80380A4"
#define EFUSE_DATA_42_reg_addr                                                        "0xB80380A8"
#define EFUSE_DATA_43_reg_addr                                                        "0xB80380AC"
#define EFUSE_DATA_44_reg_addr                                                        "0xB80380B0"
#define EFUSE_DATA_45_reg_addr                                                        "0xB80380B4"
#define EFUSE_DATA_46_reg_addr                                                        "0xB80380B8"
#define EFUSE_DATA_47_reg_addr                                                        "0xB80380BC"
#define EFUSE_DATA_48_reg_addr                                                        "0xB80380C0"
#define EFUSE_DATA_49_reg_addr                                                        "0xB80380C4"
#define EFUSE_DATA_50_reg_addr                                                        "0xB80380C8"
#define EFUSE_DATA_51_reg_addr                                                        "0xB80380CC"
#define EFUSE_DATA_52_reg_addr                                                        "0xB80380D0"
#define EFUSE_DATA_53_reg_addr                                                        "0xB80380D4"
#define EFUSE_DATA_54_reg_addr                                                        "0xB80380D8"
#define EFUSE_DATA_55_reg_addr                                                        "0xB80380DC"
#define EFUSE_DATA_56_reg_addr                                                        "0xB80380E0"
#define EFUSE_DATA_57_reg_addr                                                        "0xB80380E4"
#define EFUSE_DATA_58_reg_addr                                                        "0xB80380E8"
#define EFUSE_DATA_59_reg_addr                                                        "0xB80380EC"
#define EFUSE_DATA_60_reg_addr                                                        "0xB80380F0"
#define EFUSE_DATA_61_reg_addr                                                        "0xB80380F4"
#define EFUSE_DATA_62_reg_addr                                                        "0xB80380F8"
#define EFUSE_DATA_63_reg_addr                                                        "0xB80380FC"
#define EFUSE_DATA_64_reg_addr                                                        "0xB8038100"
#define EFUSE_DATA_65_reg_addr                                                        "0xB8038104"
#define EFUSE_DATA_66_reg_addr                                                        "0xB8038108"
#define EFUSE_DATA_67_reg_addr                                                        "0xB803810C"
#define EFUSE_DATA_68_reg_addr                                                        "0xB8038110"
#define EFUSE_DATA_69_reg_addr                                                        "0xB8038114"
#define EFUSE_DATA_70_reg_addr                                                        "0xB8038118"
#define EFUSE_DATA_71_reg_addr                                                        "0xB803811C"
#define EFUSE_DATA_72_reg_addr                                                        "0xB8038120"
#define EFUSE_DATA_73_reg_addr                                                        "0xB8038124"
#define EFUSE_DATA_74_reg_addr                                                        "0xB8038128"
#define EFUSE_DATA_75_reg_addr                                                        "0xB803812C"
#define EFUSE_DATA_76_reg_addr                                                        "0xB8038130"
#define EFUSE_DATA_77_reg_addr                                                        "0xB8038134"
#define EFUSE_DATA_78_reg_addr                                                        "0xB8038138"
#define EFUSE_DATA_79_reg_addr                                                        "0xB803813C"
#define EFUSE_DATA_80_reg_addr                                                        "0xB8038140"
#define EFUSE_DATA_81_reg_addr                                                        "0xB8038144"
#define EFUSE_DATA_82_reg_addr                                                        "0xB8038148"
#define EFUSE_DATA_83_reg_addr                                                        "0xB803814C"
#define EFUSE_DATA_84_reg_addr                                                        "0xB8038150"
#define EFUSE_DATA_85_reg_addr                                                        "0xB8038154"
#define EFUSE_DATA_86_reg_addr                                                        "0xB8038158"
#define EFUSE_DATA_87_reg_addr                                                        "0xB803815C"
#define EFUSE_DATA_88_reg_addr                                                        "0xB8038160"
#define EFUSE_DATA_89_reg_addr                                                        "0xB8038164"
#define EFUSE_DATA_90_reg_addr                                                        "0xB8038168"
#define EFUSE_DATA_91_reg_addr                                                        "0xB803816C"
#define EFUSE_DATA_92_reg_addr                                                        "0xB8038170"
#define EFUSE_DATA_93_reg_addr                                                        "0xB8038174"
#define EFUSE_DATA_94_reg_addr                                                        "0xB8038178"
#define EFUSE_DATA_95_reg_addr                                                        "0xB803817C"
#define EFUSE_DATA_96_reg_addr                                                        "0xB8038180"
#define EFUSE_DATA_97_reg_addr                                                        "0xB8038184"
#define EFUSE_DATA_98_reg_addr                                                        "0xB8038188"
#define EFUSE_DATA_99_reg_addr                                                        "0xB803818C"
#define EFUSE_DATA_100_reg_addr                                                        "0xB8038190"
#define EFUSE_DATA_101_reg_addr                                                        "0xB8038194"
#define EFUSE_DATA_102_reg_addr                                                        "0xB8038198"
#define EFUSE_DATA_103_reg_addr                                                        "0xB803819C"
#define EFUSE_DATA_104_reg_addr                                                        "0xB80381A0"
#define EFUSE_DATA_105_reg_addr                                                        "0xB80381A4"
#define EFUSE_DATA_106_reg_addr                                                        "0xB80381A8"
#define EFUSE_DATA_107_reg_addr                                                        "0xB80381AC"
#define EFUSE_DATA_108_reg_addr                                                        "0xB80381B0"
#define EFUSE_DATA_109_reg_addr                                                        "0xB80381B4"
#define EFUSE_DATA_110_reg_addr                                                        "0xB80381B8"
#define EFUSE_DATA_111_reg_addr                                                        "0xB80381BC"
#define EFUSE_DATA_112_reg_addr                                                        "0xB80381C0"
#define EFUSE_DATA_113_reg_addr                                                        "0xB80381C4"
#define EFUSE_DATA_114_reg_addr                                                        "0xB80381C8"
#define EFUSE_DATA_115_reg_addr                                                        "0xB80381CC"
#define EFUSE_DATA_116_reg_addr                                                        "0xB80381D0"
#define EFUSE_DATA_117_reg_addr                                                        "0xB80381D4"
#define EFUSE_DATA_118_reg_addr                                                        "0xB80381D8"
#define EFUSE_DATA_119_reg_addr                                                        "0xB80381DC"
#define EFUSE_DATA_120_reg_addr                                                        "0xB80381E0"
#define EFUSE_DATA_121_reg_addr                                                        "0xB80381E4"
#define EFUSE_DATA_122_reg_addr                                                        "0xB80381E8"
#define EFUSE_DATA_123_reg_addr                                                        "0xB80381EC"
#define EFUSE_DATA_124_reg_addr                                                        "0xB80381F0"
#define EFUSE_DATA_125_reg_addr                                                        "0xB80381F4"
#define EFUSE_DATA_126_reg_addr                                                        "0xB80381F8"
#define EFUSE_DATA_127_reg_addr                                                        "0xB80381FC"
#define EFUSE_DATA_0_reg                                                             0xB8038000
#define EFUSE_DATA_1_reg                                                             0xB8038004
#define EFUSE_DATA_2_reg                                                             0xB8038008
#define EFUSE_DATA_3_reg                                                             0xB803800C
#define EFUSE_DATA_4_reg                                                             0xB8038010
#define EFUSE_DATA_5_reg                                                             0xB8038014
#define EFUSE_DATA_6_reg                                                             0xB8038018
#define EFUSE_DATA_7_reg                                                             0xB803801C
#define EFUSE_DATA_8_reg                                                             0xB8038020
#define EFUSE_DATA_9_reg                                                             0xB8038024
#define EFUSE_DATA_10_reg                                                             0xB8038028
#define EFUSE_DATA_11_reg                                                             0xB803802C
#define EFUSE_DATA_12_reg                                                             0xB8038030
#define EFUSE_DATA_13_reg                                                             0xB8038034
#define EFUSE_DATA_14_reg                                                             0xB8038038
#define EFUSE_DATA_15_reg                                                             0xB803803C
#define EFUSE_DATA_16_reg                                                             0xB8038040
#define EFUSE_DATA_17_reg                                                             0xB8038044
#define EFUSE_DATA_18_reg                                                             0xB8038048
#define EFUSE_DATA_19_reg                                                             0xB803804C
#define EFUSE_DATA_20_reg                                                             0xB8038050
#define EFUSE_DATA_21_reg                                                             0xB8038054
#define EFUSE_DATA_22_reg                                                             0xB8038058
#define EFUSE_DATA_23_reg                                                             0xB803805C
#define EFUSE_DATA_24_reg                                                             0xB8038060
#define EFUSE_DATA_25_reg                                                             0xB8038064
#define EFUSE_DATA_26_reg                                                             0xB8038068
#define EFUSE_DATA_27_reg                                                             0xB803806C
#define EFUSE_DATA_28_reg                                                             0xB8038070
#define EFUSE_DATA_29_reg                                                             0xB8038074
#define EFUSE_DATA_30_reg                                                             0xB8038078
#define EFUSE_DATA_31_reg                                                             0xB803807C
#define EFUSE_DATA_32_reg                                                             0xB8038080
#define EFUSE_DATA_33_reg                                                             0xB8038084
#define EFUSE_DATA_34_reg                                                             0xB8038088
#define EFUSE_DATA_35_reg                                                             0xB803808C
#define EFUSE_DATA_36_reg                                                             0xB8038090
#define EFUSE_DATA_37_reg                                                             0xB8038094
#define EFUSE_DATA_38_reg                                                             0xB8038098
#define EFUSE_DATA_39_reg                                                             0xB803809C
#define EFUSE_DATA_40_reg                                                             0xB80380A0
#define EFUSE_DATA_41_reg                                                             0xB80380A4
#define EFUSE_DATA_42_reg                                                             0xB80380A8
#define EFUSE_DATA_43_reg                                                             0xB80380AC
#define EFUSE_DATA_44_reg                                                             0xB80380B0
#define EFUSE_DATA_45_reg                                                             0xB80380B4
#define EFUSE_DATA_46_reg                                                             0xB80380B8
#define EFUSE_DATA_47_reg                                                             0xB80380BC
#define EFUSE_DATA_48_reg                                                             0xB80380C0
#define EFUSE_DATA_49_reg                                                             0xB80380C4
#define EFUSE_DATA_50_reg                                                             0xB80380C8
#define EFUSE_DATA_51_reg                                                             0xB80380CC
#define EFUSE_DATA_52_reg                                                             0xB80380D0
#define EFUSE_DATA_53_reg                                                             0xB80380D4
#define EFUSE_DATA_54_reg                                                             0xB80380D8
#define EFUSE_DATA_55_reg                                                             0xB80380DC
#define EFUSE_DATA_56_reg                                                             0xB80380E0
#define EFUSE_DATA_57_reg                                                             0xB80380E4
#define EFUSE_DATA_58_reg                                                             0xB80380E8
#define EFUSE_DATA_59_reg                                                             0xB80380EC
#define EFUSE_DATA_60_reg                                                             0xB80380F0
#define EFUSE_DATA_61_reg                                                             0xB80380F4
#define EFUSE_DATA_62_reg                                                             0xB80380F8
#define EFUSE_DATA_63_reg                                                             0xB80380FC
#define EFUSE_DATA_64_reg                                                             0xB8038100
#define EFUSE_DATA_65_reg                                                             0xB8038104
#define EFUSE_DATA_66_reg                                                             0xB8038108
#define EFUSE_DATA_67_reg                                                             0xB803810C
#define EFUSE_DATA_68_reg                                                             0xB8038110
#define EFUSE_DATA_69_reg                                                             0xB8038114
#define EFUSE_DATA_70_reg                                                             0xB8038118
#define EFUSE_DATA_71_reg                                                             0xB803811C
#define EFUSE_DATA_72_reg                                                             0xB8038120
#define EFUSE_DATA_73_reg                                                             0xB8038124
#define EFUSE_DATA_74_reg                                                             0xB8038128
#define EFUSE_DATA_75_reg                                                             0xB803812C
#define EFUSE_DATA_76_reg                                                             0xB8038130
#define EFUSE_DATA_77_reg                                                             0xB8038134
#define EFUSE_DATA_78_reg                                                             0xB8038138
#define EFUSE_DATA_79_reg                                                             0xB803813C
#define EFUSE_DATA_80_reg                                                             0xB8038140
#define EFUSE_DATA_81_reg                                                             0xB8038144
#define EFUSE_DATA_82_reg                                                             0xB8038148
#define EFUSE_DATA_83_reg                                                             0xB803814C
#define EFUSE_DATA_84_reg                                                             0xB8038150
#define EFUSE_DATA_85_reg                                                             0xB8038154
#define EFUSE_DATA_86_reg                                                             0xB8038158
#define EFUSE_DATA_87_reg                                                             0xB803815C
#define EFUSE_DATA_88_reg                                                             0xB8038160
#define EFUSE_DATA_89_reg                                                             0xB8038164
#define EFUSE_DATA_90_reg                                                             0xB8038168
#define EFUSE_DATA_91_reg                                                             0xB803816C
#define EFUSE_DATA_92_reg                                                             0xB8038170
#define EFUSE_DATA_93_reg                                                             0xB8038174
#define EFUSE_DATA_94_reg                                                             0xB8038178
#define EFUSE_DATA_95_reg                                                             0xB803817C
#define EFUSE_DATA_96_reg                                                             0xB8038180
#define EFUSE_DATA_97_reg                                                             0xB8038184
#define EFUSE_DATA_98_reg                                                             0xB8038188
#define EFUSE_DATA_99_reg                                                             0xB803818C
#define EFUSE_DATA_100_reg                                                             0xB8038190
#define EFUSE_DATA_101_reg                                                             0xB8038194
#define EFUSE_DATA_102_reg                                                             0xB8038198
#define EFUSE_DATA_103_reg                                                             0xB803819C
#define EFUSE_DATA_104_reg                                                             0xB80381A0
#define EFUSE_DATA_105_reg                                                             0xB80381A4
#define EFUSE_DATA_106_reg                                                             0xB80381A8
#define EFUSE_DATA_107_reg                                                             0xB80381AC
#define EFUSE_DATA_108_reg                                                             0xB80381B0
#define EFUSE_DATA_109_reg                                                             0xB80381B4
#define EFUSE_DATA_110_reg                                                             0xB80381B8
#define EFUSE_DATA_111_reg                                                             0xB80381BC
#define EFUSE_DATA_112_reg                                                             0xB80381C0
#define EFUSE_DATA_113_reg                                                             0xB80381C4
#define EFUSE_DATA_114_reg                                                             0xB80381C8
#define EFUSE_DATA_115_reg                                                             0xB80381CC
#define EFUSE_DATA_116_reg                                                             0xB80381D0
#define EFUSE_DATA_117_reg                                                             0xB80381D4
#define EFUSE_DATA_118_reg                                                             0xB80381D8
#define EFUSE_DATA_119_reg                                                             0xB80381DC
#define EFUSE_DATA_120_reg                                                             0xB80381E0
#define EFUSE_DATA_121_reg                                                             0xB80381E4
#define EFUSE_DATA_122_reg                                                             0xB80381E8
#define EFUSE_DATA_123_reg                                                             0xB80381EC
#define EFUSE_DATA_124_reg                                                             0xB80381F0
#define EFUSE_DATA_125_reg                                                             0xB80381F4
#define EFUSE_DATA_126_reg                                                             0xB80381F8
#define EFUSE_DATA_127_reg                                                             0xB80381FC
#define set_EFUSE_DATA_0_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_0_reg)=data)
#define set_EFUSE_DATA_1_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_1_reg)=data)
#define set_EFUSE_DATA_2_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_2_reg)=data)
#define set_EFUSE_DATA_3_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_3_reg)=data)
#define set_EFUSE_DATA_4_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_4_reg)=data)
#define set_EFUSE_DATA_5_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_5_reg)=data)
#define set_EFUSE_DATA_6_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_6_reg)=data)
#define set_EFUSE_DATA_7_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_7_reg)=data)
#define set_EFUSE_DATA_8_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_8_reg)=data)
#define set_EFUSE_DATA_9_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_9_reg)=data)
#define set_EFUSE_DATA_10_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_10_reg)=data)
#define set_EFUSE_DATA_11_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_11_reg)=data)
#define set_EFUSE_DATA_12_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_12_reg)=data)
#define set_EFUSE_DATA_13_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_13_reg)=data)
#define set_EFUSE_DATA_14_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_14_reg)=data)
#define set_EFUSE_DATA_15_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_15_reg)=data)
#define set_EFUSE_DATA_16_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_16_reg)=data)
#define set_EFUSE_DATA_17_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_17_reg)=data)
#define set_EFUSE_DATA_18_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_18_reg)=data)
#define set_EFUSE_DATA_19_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_19_reg)=data)
#define set_EFUSE_DATA_20_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_20_reg)=data)
#define set_EFUSE_DATA_21_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_21_reg)=data)
#define set_EFUSE_DATA_22_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_22_reg)=data)
#define set_EFUSE_DATA_23_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_23_reg)=data)
#define set_EFUSE_DATA_24_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_24_reg)=data)
#define set_EFUSE_DATA_25_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_25_reg)=data)
#define set_EFUSE_DATA_26_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_26_reg)=data)
#define set_EFUSE_DATA_27_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_27_reg)=data)
#define set_EFUSE_DATA_28_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_28_reg)=data)
#define set_EFUSE_DATA_29_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_29_reg)=data)
#define set_EFUSE_DATA_30_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_30_reg)=data)
#define set_EFUSE_DATA_31_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_31_reg)=data)
#define set_EFUSE_DATA_32_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_32_reg)=data)
#define set_EFUSE_DATA_33_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_33_reg)=data)
#define set_EFUSE_DATA_34_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_34_reg)=data)
#define set_EFUSE_DATA_35_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_35_reg)=data)
#define set_EFUSE_DATA_36_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_36_reg)=data)
#define set_EFUSE_DATA_37_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_37_reg)=data)
#define set_EFUSE_DATA_38_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_38_reg)=data)
#define set_EFUSE_DATA_39_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_39_reg)=data)
#define set_EFUSE_DATA_40_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_40_reg)=data)
#define set_EFUSE_DATA_41_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_41_reg)=data)
#define set_EFUSE_DATA_42_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_42_reg)=data)
#define set_EFUSE_DATA_43_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_43_reg)=data)
#define set_EFUSE_DATA_44_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_44_reg)=data)
#define set_EFUSE_DATA_45_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_45_reg)=data)
#define set_EFUSE_DATA_46_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_46_reg)=data)
#define set_EFUSE_DATA_47_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_47_reg)=data)
#define set_EFUSE_DATA_48_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_48_reg)=data)
#define set_EFUSE_DATA_49_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_49_reg)=data)
#define set_EFUSE_DATA_50_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_50_reg)=data)
#define set_EFUSE_DATA_51_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_51_reg)=data)
#define set_EFUSE_DATA_52_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_52_reg)=data)
#define set_EFUSE_DATA_53_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_53_reg)=data)
#define set_EFUSE_DATA_54_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_54_reg)=data)
#define set_EFUSE_DATA_55_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_55_reg)=data)
#define set_EFUSE_DATA_56_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_56_reg)=data)
#define set_EFUSE_DATA_57_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_57_reg)=data)
#define set_EFUSE_DATA_58_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_58_reg)=data)
#define set_EFUSE_DATA_59_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_59_reg)=data)
#define set_EFUSE_DATA_60_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_60_reg)=data)
#define set_EFUSE_DATA_61_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_61_reg)=data)
#define set_EFUSE_DATA_62_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_62_reg)=data)
#define set_EFUSE_DATA_63_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_63_reg)=data)
#define set_EFUSE_DATA_64_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_64_reg)=data)
#define set_EFUSE_DATA_65_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_65_reg)=data)
#define set_EFUSE_DATA_66_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_66_reg)=data)
#define set_EFUSE_DATA_67_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_67_reg)=data)
#define set_EFUSE_DATA_68_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_68_reg)=data)
#define set_EFUSE_DATA_69_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_69_reg)=data)
#define set_EFUSE_DATA_70_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_70_reg)=data)
#define set_EFUSE_DATA_71_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_71_reg)=data)
#define set_EFUSE_DATA_72_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_72_reg)=data)
#define set_EFUSE_DATA_73_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_73_reg)=data)
#define set_EFUSE_DATA_74_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_74_reg)=data)
#define set_EFUSE_DATA_75_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_75_reg)=data)
#define set_EFUSE_DATA_76_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_76_reg)=data)
#define set_EFUSE_DATA_77_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_77_reg)=data)
#define set_EFUSE_DATA_78_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_78_reg)=data)
#define set_EFUSE_DATA_79_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_79_reg)=data)
#define set_EFUSE_DATA_80_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_80_reg)=data)
#define set_EFUSE_DATA_81_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_81_reg)=data)
#define set_EFUSE_DATA_82_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_82_reg)=data)
#define set_EFUSE_DATA_83_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_83_reg)=data)
#define set_EFUSE_DATA_84_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_84_reg)=data)
#define set_EFUSE_DATA_85_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_85_reg)=data)
#define set_EFUSE_DATA_86_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_86_reg)=data)
#define set_EFUSE_DATA_87_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_87_reg)=data)
#define set_EFUSE_DATA_88_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_88_reg)=data)
#define set_EFUSE_DATA_89_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_89_reg)=data)
#define set_EFUSE_DATA_90_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_90_reg)=data)
#define set_EFUSE_DATA_91_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_91_reg)=data)
#define set_EFUSE_DATA_92_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_92_reg)=data)
#define set_EFUSE_DATA_93_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_93_reg)=data)
#define set_EFUSE_DATA_94_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_94_reg)=data)
#define set_EFUSE_DATA_95_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_95_reg)=data)
#define set_EFUSE_DATA_96_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_96_reg)=data)
#define set_EFUSE_DATA_97_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_97_reg)=data)
#define set_EFUSE_DATA_98_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_98_reg)=data)
#define set_EFUSE_DATA_99_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_99_reg)=data)
#define set_EFUSE_DATA_100_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_100_reg)=data)
#define set_EFUSE_DATA_101_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_101_reg)=data)
#define set_EFUSE_DATA_102_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_102_reg)=data)
#define set_EFUSE_DATA_103_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_103_reg)=data)
#define set_EFUSE_DATA_104_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_104_reg)=data)
#define set_EFUSE_DATA_105_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_105_reg)=data)
#define set_EFUSE_DATA_106_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_106_reg)=data)
#define set_EFUSE_DATA_107_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_107_reg)=data)
#define set_EFUSE_DATA_108_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_108_reg)=data)
#define set_EFUSE_DATA_109_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_109_reg)=data)
#define set_EFUSE_DATA_110_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_110_reg)=data)
#define set_EFUSE_DATA_111_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_111_reg)=data)
#define set_EFUSE_DATA_112_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_112_reg)=data)
#define set_EFUSE_DATA_113_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_113_reg)=data)
#define set_EFUSE_DATA_114_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_114_reg)=data)
#define set_EFUSE_DATA_115_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_115_reg)=data)
#define set_EFUSE_DATA_116_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_116_reg)=data)
#define set_EFUSE_DATA_117_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_117_reg)=data)
#define set_EFUSE_DATA_118_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_118_reg)=data)
#define set_EFUSE_DATA_119_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_119_reg)=data)
#define set_EFUSE_DATA_120_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_120_reg)=data)
#define set_EFUSE_DATA_121_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_121_reg)=data)
#define set_EFUSE_DATA_122_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_122_reg)=data)
#define set_EFUSE_DATA_123_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_123_reg)=data)
#define set_EFUSE_DATA_124_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_124_reg)=data)
#define set_EFUSE_DATA_125_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_125_reg)=data)
#define set_EFUSE_DATA_126_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_126_reg)=data)
#define set_EFUSE_DATA_127_reg(data)   (*((volatile unsigned int*) EFUSE_DATA_127_reg)=data)
#define get_EFUSE_DATA_0_reg   (*((volatile unsigned int*) EFUSE_DATA_0_reg))
#define get_EFUSE_DATA_1_reg   (*((volatile unsigned int*) EFUSE_DATA_1_reg))
#define get_EFUSE_DATA_2_reg   (*((volatile unsigned int*) EFUSE_DATA_2_reg))
#define get_EFUSE_DATA_3_reg   (*((volatile unsigned int*) EFUSE_DATA_3_reg))
#define get_EFUSE_DATA_4_reg   (*((volatile unsigned int*) EFUSE_DATA_4_reg))
#define get_EFUSE_DATA_5_reg   (*((volatile unsigned int*) EFUSE_DATA_5_reg))
#define get_EFUSE_DATA_6_reg   (*((volatile unsigned int*) EFUSE_DATA_6_reg))
#define get_EFUSE_DATA_7_reg   (*((volatile unsigned int*) EFUSE_DATA_7_reg))
#define get_EFUSE_DATA_8_reg   (*((volatile unsigned int*) EFUSE_DATA_8_reg))
#define get_EFUSE_DATA_9_reg   (*((volatile unsigned int*) EFUSE_DATA_9_reg))
#define get_EFUSE_DATA_10_reg   (*((volatile unsigned int*) EFUSE_DATA_10_reg))
#define get_EFUSE_DATA_11_reg   (*((volatile unsigned int*) EFUSE_DATA_11_reg))
#define get_EFUSE_DATA_12_reg   (*((volatile unsigned int*) EFUSE_DATA_12_reg))
#define get_EFUSE_DATA_13_reg   (*((volatile unsigned int*) EFUSE_DATA_13_reg))
#define get_EFUSE_DATA_14_reg   (*((volatile unsigned int*) EFUSE_DATA_14_reg))
#define get_EFUSE_DATA_15_reg   (*((volatile unsigned int*) EFUSE_DATA_15_reg))
#define get_EFUSE_DATA_16_reg   (*((volatile unsigned int*) EFUSE_DATA_16_reg))
#define get_EFUSE_DATA_17_reg   (*((volatile unsigned int*) EFUSE_DATA_17_reg))
#define get_EFUSE_DATA_18_reg   (*((volatile unsigned int*) EFUSE_DATA_18_reg))
#define get_EFUSE_DATA_19_reg   (*((volatile unsigned int*) EFUSE_DATA_19_reg))
#define get_EFUSE_DATA_20_reg   (*((volatile unsigned int*) EFUSE_DATA_20_reg))
#define get_EFUSE_DATA_21_reg   (*((volatile unsigned int*) EFUSE_DATA_21_reg))
#define get_EFUSE_DATA_22_reg   (*((volatile unsigned int*) EFUSE_DATA_22_reg))
#define get_EFUSE_DATA_23_reg   (*((volatile unsigned int*) EFUSE_DATA_23_reg))
#define get_EFUSE_DATA_24_reg   (*((volatile unsigned int*) EFUSE_DATA_24_reg))
#define get_EFUSE_DATA_25_reg   (*((volatile unsigned int*) EFUSE_DATA_25_reg))
#define get_EFUSE_DATA_26_reg   (*((volatile unsigned int*) EFUSE_DATA_26_reg))
#define get_EFUSE_DATA_27_reg   (*((volatile unsigned int*) EFUSE_DATA_27_reg))
#define get_EFUSE_DATA_28_reg   (*((volatile unsigned int*) EFUSE_DATA_28_reg))
#define get_EFUSE_DATA_29_reg   (*((volatile unsigned int*) EFUSE_DATA_29_reg))
#define get_EFUSE_DATA_30_reg   (*((volatile unsigned int*) EFUSE_DATA_30_reg))
#define get_EFUSE_DATA_31_reg   (*((volatile unsigned int*) EFUSE_DATA_31_reg))
#define get_EFUSE_DATA_32_reg   (*((volatile unsigned int*) EFUSE_DATA_32_reg))
#define get_EFUSE_DATA_33_reg   (*((volatile unsigned int*) EFUSE_DATA_33_reg))
#define get_EFUSE_DATA_34_reg   (*((volatile unsigned int*) EFUSE_DATA_34_reg))
#define get_EFUSE_DATA_35_reg   (*((volatile unsigned int*) EFUSE_DATA_35_reg))
#define get_EFUSE_DATA_36_reg   (*((volatile unsigned int*) EFUSE_DATA_36_reg))
#define get_EFUSE_DATA_37_reg   (*((volatile unsigned int*) EFUSE_DATA_37_reg))
#define get_EFUSE_DATA_38_reg   (*((volatile unsigned int*) EFUSE_DATA_38_reg))
#define get_EFUSE_DATA_39_reg   (*((volatile unsigned int*) EFUSE_DATA_39_reg))
#define get_EFUSE_DATA_40_reg   (*((volatile unsigned int*) EFUSE_DATA_40_reg))
#define get_EFUSE_DATA_41_reg   (*((volatile unsigned int*) EFUSE_DATA_41_reg))
#define get_EFUSE_DATA_42_reg   (*((volatile unsigned int*) EFUSE_DATA_42_reg))
#define get_EFUSE_DATA_43_reg   (*((volatile unsigned int*) EFUSE_DATA_43_reg))
#define get_EFUSE_DATA_44_reg   (*((volatile unsigned int*) EFUSE_DATA_44_reg))
#define get_EFUSE_DATA_45_reg   (*((volatile unsigned int*) EFUSE_DATA_45_reg))
#define get_EFUSE_DATA_46_reg   (*((volatile unsigned int*) EFUSE_DATA_46_reg))
#define get_EFUSE_DATA_47_reg   (*((volatile unsigned int*) EFUSE_DATA_47_reg))
#define get_EFUSE_DATA_48_reg   (*((volatile unsigned int*) EFUSE_DATA_48_reg))
#define get_EFUSE_DATA_49_reg   (*((volatile unsigned int*) EFUSE_DATA_49_reg))
#define get_EFUSE_DATA_50_reg   (*((volatile unsigned int*) EFUSE_DATA_50_reg))
#define get_EFUSE_DATA_51_reg   (*((volatile unsigned int*) EFUSE_DATA_51_reg))
#define get_EFUSE_DATA_52_reg   (*((volatile unsigned int*) EFUSE_DATA_52_reg))
#define get_EFUSE_DATA_53_reg   (*((volatile unsigned int*) EFUSE_DATA_53_reg))
#define get_EFUSE_DATA_54_reg   (*((volatile unsigned int*) EFUSE_DATA_54_reg))
#define get_EFUSE_DATA_55_reg   (*((volatile unsigned int*) EFUSE_DATA_55_reg))
#define get_EFUSE_DATA_56_reg   (*((volatile unsigned int*) EFUSE_DATA_56_reg))
#define get_EFUSE_DATA_57_reg   (*((volatile unsigned int*) EFUSE_DATA_57_reg))
#define get_EFUSE_DATA_58_reg   (*((volatile unsigned int*) EFUSE_DATA_58_reg))
#define get_EFUSE_DATA_59_reg   (*((volatile unsigned int*) EFUSE_DATA_59_reg))
#define get_EFUSE_DATA_60_reg   (*((volatile unsigned int*) EFUSE_DATA_60_reg))
#define get_EFUSE_DATA_61_reg   (*((volatile unsigned int*) EFUSE_DATA_61_reg))
#define get_EFUSE_DATA_62_reg   (*((volatile unsigned int*) EFUSE_DATA_62_reg))
#define get_EFUSE_DATA_63_reg   (*((volatile unsigned int*) EFUSE_DATA_63_reg))
#define get_EFUSE_DATA_64_reg   (*((volatile unsigned int*) EFUSE_DATA_64_reg))
#define get_EFUSE_DATA_65_reg   (*((volatile unsigned int*) EFUSE_DATA_65_reg))
#define get_EFUSE_DATA_66_reg   (*((volatile unsigned int*) EFUSE_DATA_66_reg))
#define get_EFUSE_DATA_67_reg   (*((volatile unsigned int*) EFUSE_DATA_67_reg))
#define get_EFUSE_DATA_68_reg   (*((volatile unsigned int*) EFUSE_DATA_68_reg))
#define get_EFUSE_DATA_69_reg   (*((volatile unsigned int*) EFUSE_DATA_69_reg))
#define get_EFUSE_DATA_70_reg   (*((volatile unsigned int*) EFUSE_DATA_70_reg))
#define get_EFUSE_DATA_71_reg   (*((volatile unsigned int*) EFUSE_DATA_71_reg))
#define get_EFUSE_DATA_72_reg   (*((volatile unsigned int*) EFUSE_DATA_72_reg))
#define get_EFUSE_DATA_73_reg   (*((volatile unsigned int*) EFUSE_DATA_73_reg))
#define get_EFUSE_DATA_74_reg   (*((volatile unsigned int*) EFUSE_DATA_74_reg))
#define get_EFUSE_DATA_75_reg   (*((volatile unsigned int*) EFUSE_DATA_75_reg))
#define get_EFUSE_DATA_76_reg   (*((volatile unsigned int*) EFUSE_DATA_76_reg))
#define get_EFUSE_DATA_77_reg   (*((volatile unsigned int*) EFUSE_DATA_77_reg))
#define get_EFUSE_DATA_78_reg   (*((volatile unsigned int*) EFUSE_DATA_78_reg))
#define get_EFUSE_DATA_79_reg   (*((volatile unsigned int*) EFUSE_DATA_79_reg))
#define get_EFUSE_DATA_80_reg   (*((volatile unsigned int*) EFUSE_DATA_80_reg))
#define get_EFUSE_DATA_81_reg   (*((volatile unsigned int*) EFUSE_DATA_81_reg))
#define get_EFUSE_DATA_82_reg   (*((volatile unsigned int*) EFUSE_DATA_82_reg))
#define get_EFUSE_DATA_83_reg   (*((volatile unsigned int*) EFUSE_DATA_83_reg))
#define get_EFUSE_DATA_84_reg   (*((volatile unsigned int*) EFUSE_DATA_84_reg))
#define get_EFUSE_DATA_85_reg   (*((volatile unsigned int*) EFUSE_DATA_85_reg))
#define get_EFUSE_DATA_86_reg   (*((volatile unsigned int*) EFUSE_DATA_86_reg))
#define get_EFUSE_DATA_87_reg   (*((volatile unsigned int*) EFUSE_DATA_87_reg))
#define get_EFUSE_DATA_88_reg   (*((volatile unsigned int*) EFUSE_DATA_88_reg))
#define get_EFUSE_DATA_89_reg   (*((volatile unsigned int*) EFUSE_DATA_89_reg))
#define get_EFUSE_DATA_90_reg   (*((volatile unsigned int*) EFUSE_DATA_90_reg))
#define get_EFUSE_DATA_91_reg   (*((volatile unsigned int*) EFUSE_DATA_91_reg))
#define get_EFUSE_DATA_92_reg   (*((volatile unsigned int*) EFUSE_DATA_92_reg))
#define get_EFUSE_DATA_93_reg   (*((volatile unsigned int*) EFUSE_DATA_93_reg))
#define get_EFUSE_DATA_94_reg   (*((volatile unsigned int*) EFUSE_DATA_94_reg))
#define get_EFUSE_DATA_95_reg   (*((volatile unsigned int*) EFUSE_DATA_95_reg))
#define get_EFUSE_DATA_96_reg   (*((volatile unsigned int*) EFUSE_DATA_96_reg))
#define get_EFUSE_DATA_97_reg   (*((volatile unsigned int*) EFUSE_DATA_97_reg))
#define get_EFUSE_DATA_98_reg   (*((volatile unsigned int*) EFUSE_DATA_98_reg))
#define get_EFUSE_DATA_99_reg   (*((volatile unsigned int*) EFUSE_DATA_99_reg))
#define get_EFUSE_DATA_100_reg   (*((volatile unsigned int*) EFUSE_DATA_100_reg))
#define get_EFUSE_DATA_101_reg   (*((volatile unsigned int*) EFUSE_DATA_101_reg))
#define get_EFUSE_DATA_102_reg   (*((volatile unsigned int*) EFUSE_DATA_102_reg))
#define get_EFUSE_DATA_103_reg   (*((volatile unsigned int*) EFUSE_DATA_103_reg))
#define get_EFUSE_DATA_104_reg   (*((volatile unsigned int*) EFUSE_DATA_104_reg))
#define get_EFUSE_DATA_105_reg   (*((volatile unsigned int*) EFUSE_DATA_105_reg))
#define get_EFUSE_DATA_106_reg   (*((volatile unsigned int*) EFUSE_DATA_106_reg))
#define get_EFUSE_DATA_107_reg   (*((volatile unsigned int*) EFUSE_DATA_107_reg))
#define get_EFUSE_DATA_108_reg   (*((volatile unsigned int*) EFUSE_DATA_108_reg))
#define get_EFUSE_DATA_109_reg   (*((volatile unsigned int*) EFUSE_DATA_109_reg))
#define get_EFUSE_DATA_110_reg   (*((volatile unsigned int*) EFUSE_DATA_110_reg))
#define get_EFUSE_DATA_111_reg   (*((volatile unsigned int*) EFUSE_DATA_111_reg))
#define get_EFUSE_DATA_112_reg   (*((volatile unsigned int*) EFUSE_DATA_112_reg))
#define get_EFUSE_DATA_113_reg   (*((volatile unsigned int*) EFUSE_DATA_113_reg))
#define get_EFUSE_DATA_114_reg   (*((volatile unsigned int*) EFUSE_DATA_114_reg))
#define get_EFUSE_DATA_115_reg   (*((volatile unsigned int*) EFUSE_DATA_115_reg))
#define get_EFUSE_DATA_116_reg   (*((volatile unsigned int*) EFUSE_DATA_116_reg))
#define get_EFUSE_DATA_117_reg   (*((volatile unsigned int*) EFUSE_DATA_117_reg))
#define get_EFUSE_DATA_118_reg   (*((volatile unsigned int*) EFUSE_DATA_118_reg))
#define get_EFUSE_DATA_119_reg   (*((volatile unsigned int*) EFUSE_DATA_119_reg))
#define get_EFUSE_DATA_120_reg   (*((volatile unsigned int*) EFUSE_DATA_120_reg))
#define get_EFUSE_DATA_121_reg   (*((volatile unsigned int*) EFUSE_DATA_121_reg))
#define get_EFUSE_DATA_122_reg   (*((volatile unsigned int*) EFUSE_DATA_122_reg))
#define get_EFUSE_DATA_123_reg   (*((volatile unsigned int*) EFUSE_DATA_123_reg))
#define get_EFUSE_DATA_124_reg   (*((volatile unsigned int*) EFUSE_DATA_124_reg))
#define get_EFUSE_DATA_125_reg   (*((volatile unsigned int*) EFUSE_DATA_125_reg))
#define get_EFUSE_DATA_126_reg   (*((volatile unsigned int*) EFUSE_DATA_126_reg))
#define get_EFUSE_DATA_127_reg   (*((volatile unsigned int*) EFUSE_DATA_127_reg))
#define EFUSE_DATA_0_inst_adr                                                        "0x0000"
#define EFUSE_DATA_1_inst_adr                                                        "0x0001"
#define EFUSE_DATA_2_inst_adr                                                        "0x0002"
#define EFUSE_DATA_3_inst_adr                                                        "0x0003"
#define EFUSE_DATA_4_inst_adr                                                        "0x0004"
#define EFUSE_DATA_5_inst_adr                                                        "0x0005"
#define EFUSE_DATA_6_inst_adr                                                        "0x0006"
#define EFUSE_DATA_7_inst_adr                                                        "0x0007"
#define EFUSE_DATA_8_inst_adr                                                        "0x0008"
#define EFUSE_DATA_9_inst_adr                                                        "0x0009"
#define EFUSE_DATA_10_inst_adr                                                        "0x000A"
#define EFUSE_DATA_11_inst_adr                                                        "0x000B"
#define EFUSE_DATA_12_inst_adr                                                        "0x000C"
#define EFUSE_DATA_13_inst_adr                                                        "0x000D"
#define EFUSE_DATA_14_inst_adr                                                        "0x000E"
#define EFUSE_DATA_15_inst_adr                                                        "0x000F"
#define EFUSE_DATA_16_inst_adr                                                        "0x0010"
#define EFUSE_DATA_17_inst_adr                                                        "0x0011"
#define EFUSE_DATA_18_inst_adr                                                        "0x0012"
#define EFUSE_DATA_19_inst_adr                                                        "0x0013"
#define EFUSE_DATA_20_inst_adr                                                        "0x0014"
#define EFUSE_DATA_21_inst_adr                                                        "0x0015"
#define EFUSE_DATA_22_inst_adr                                                        "0x0016"
#define EFUSE_DATA_23_inst_adr                                                        "0x0017"
#define EFUSE_DATA_24_inst_adr                                                        "0x0018"
#define EFUSE_DATA_25_inst_adr                                                        "0x0019"
#define EFUSE_DATA_26_inst_adr                                                        "0x001A"
#define EFUSE_DATA_27_inst_adr                                                        "0x001B"
#define EFUSE_DATA_28_inst_adr                                                        "0x001C"
#define EFUSE_DATA_29_inst_adr                                                        "0x001D"
#define EFUSE_DATA_30_inst_adr                                                        "0x001E"
#define EFUSE_DATA_31_inst_adr                                                        "0x001F"
#define EFUSE_DATA_32_inst_adr                                                        "0x0020"
#define EFUSE_DATA_33_inst_adr                                                        "0x0021"
#define EFUSE_DATA_34_inst_adr                                                        "0x0022"
#define EFUSE_DATA_35_inst_adr                                                        "0x0023"
#define EFUSE_DATA_36_inst_adr                                                        "0x0024"
#define EFUSE_DATA_37_inst_adr                                                        "0x0025"
#define EFUSE_DATA_38_inst_adr                                                        "0x0026"
#define EFUSE_DATA_39_inst_adr                                                        "0x0027"
#define EFUSE_DATA_40_inst_adr                                                        "0x0028"
#define EFUSE_DATA_41_inst_adr                                                        "0x0029"
#define EFUSE_DATA_42_inst_adr                                                        "0x002A"
#define EFUSE_DATA_43_inst_adr                                                        "0x002B"
#define EFUSE_DATA_44_inst_adr                                                        "0x002C"
#define EFUSE_DATA_45_inst_adr                                                        "0x002D"
#define EFUSE_DATA_46_inst_adr                                                        "0x002E"
#define EFUSE_DATA_47_inst_adr                                                        "0x002F"
#define EFUSE_DATA_48_inst_adr                                                        "0x0030"
#define EFUSE_DATA_49_inst_adr                                                        "0x0031"
#define EFUSE_DATA_50_inst_adr                                                        "0x0032"
#define EFUSE_DATA_51_inst_adr                                                        "0x0033"
#define EFUSE_DATA_52_inst_adr                                                        "0x0034"
#define EFUSE_DATA_53_inst_adr                                                        "0x0035"
#define EFUSE_DATA_54_inst_adr                                                        "0x0036"
#define EFUSE_DATA_55_inst_adr                                                        "0x0037"
#define EFUSE_DATA_56_inst_adr                                                        "0x0038"
#define EFUSE_DATA_57_inst_adr                                                        "0x0039"
#define EFUSE_DATA_58_inst_adr                                                        "0x003A"
#define EFUSE_DATA_59_inst_adr                                                        "0x003B"
#define EFUSE_DATA_60_inst_adr                                                        "0x003C"
#define EFUSE_DATA_61_inst_adr                                                        "0x003D"
#define EFUSE_DATA_62_inst_adr                                                        "0x003E"
#define EFUSE_DATA_63_inst_adr                                                        "0x003F"
#define EFUSE_DATA_64_inst_adr                                                        "0x0040"
#define EFUSE_DATA_65_inst_adr                                                        "0x0041"
#define EFUSE_DATA_66_inst_adr                                                        "0x0042"
#define EFUSE_DATA_67_inst_adr                                                        "0x0043"
#define EFUSE_DATA_68_inst_adr                                                        "0x0044"
#define EFUSE_DATA_69_inst_adr                                                        "0x0045"
#define EFUSE_DATA_70_inst_adr                                                        "0x0046"
#define EFUSE_DATA_71_inst_adr                                                        "0x0047"
#define EFUSE_DATA_72_inst_adr                                                        "0x0048"
#define EFUSE_DATA_73_inst_adr                                                        "0x0049"
#define EFUSE_DATA_74_inst_adr                                                        "0x004A"
#define EFUSE_DATA_75_inst_adr                                                        "0x004B"
#define EFUSE_DATA_76_inst_adr                                                        "0x004C"
#define EFUSE_DATA_77_inst_adr                                                        "0x004D"
#define EFUSE_DATA_78_inst_adr                                                        "0x004E"
#define EFUSE_DATA_79_inst_adr                                                        "0x004F"
#define EFUSE_DATA_80_inst_adr                                                        "0x0050"
#define EFUSE_DATA_81_inst_adr                                                        "0x0051"
#define EFUSE_DATA_82_inst_adr                                                        "0x0052"
#define EFUSE_DATA_83_inst_adr                                                        "0x0053"
#define EFUSE_DATA_84_inst_adr                                                        "0x0054"
#define EFUSE_DATA_85_inst_adr                                                        "0x0055"
#define EFUSE_DATA_86_inst_adr                                                        "0x0056"
#define EFUSE_DATA_87_inst_adr                                                        "0x0057"
#define EFUSE_DATA_88_inst_adr                                                        "0x0058"
#define EFUSE_DATA_89_inst_adr                                                        "0x0059"
#define EFUSE_DATA_90_inst_adr                                                        "0x005A"
#define EFUSE_DATA_91_inst_adr                                                        "0x005B"
#define EFUSE_DATA_92_inst_adr                                                        "0x005C"
#define EFUSE_DATA_93_inst_adr                                                        "0x005D"
#define EFUSE_DATA_94_inst_adr                                                        "0x005E"
#define EFUSE_DATA_95_inst_adr                                                        "0x005F"
#define EFUSE_DATA_96_inst_adr                                                        "0x0060"
#define EFUSE_DATA_97_inst_adr                                                        "0x0061"
#define EFUSE_DATA_98_inst_adr                                                        "0x0062"
#define EFUSE_DATA_99_inst_adr                                                        "0x0063"
#define EFUSE_DATA_100_inst_adr                                                        "0x0064"
#define EFUSE_DATA_101_inst_adr                                                        "0x0065"
#define EFUSE_DATA_102_inst_adr                                                        "0x0066"
#define EFUSE_DATA_103_inst_adr                                                        "0x0067"
#define EFUSE_DATA_104_inst_adr                                                        "0x0068"
#define EFUSE_DATA_105_inst_adr                                                        "0x0069"
#define EFUSE_DATA_106_inst_adr                                                        "0x006A"
#define EFUSE_DATA_107_inst_adr                                                        "0x006B"
#define EFUSE_DATA_108_inst_adr                                                        "0x006C"
#define EFUSE_DATA_109_inst_adr                                                        "0x006D"
#define EFUSE_DATA_110_inst_adr                                                        "0x006E"
#define EFUSE_DATA_111_inst_adr                                                        "0x006F"
#define EFUSE_DATA_112_inst_adr                                                        "0x0070"
#define EFUSE_DATA_113_inst_adr                                                        "0x0071"
#define EFUSE_DATA_114_inst_adr                                                        "0x0072"
#define EFUSE_DATA_115_inst_adr                                                        "0x0073"
#define EFUSE_DATA_116_inst_adr                                                        "0x0074"
#define EFUSE_DATA_117_inst_adr                                                        "0x0075"
#define EFUSE_DATA_118_inst_adr                                                        "0x0076"
#define EFUSE_DATA_119_inst_adr                                                        "0x0077"
#define EFUSE_DATA_120_inst_adr                                                        "0x0078"
#define EFUSE_DATA_121_inst_adr                                                        "0x0079"
#define EFUSE_DATA_122_inst_adr                                                        "0x007A"
#define EFUSE_DATA_123_inst_adr                                                        "0x007B"
#define EFUSE_DATA_124_inst_adr                                                        "0x007C"
#define EFUSE_DATA_125_inst_adr                                                        "0x007D"
#define EFUSE_DATA_126_inst_adr                                                        "0x007E"
#define EFUSE_DATA_127_inst_adr                                                        "0x007F"
#define EFUSE_DATA_0_inst                                                            0x0000
#define EFUSE_DATA_1_inst                                                            0x0001
#define EFUSE_DATA_2_inst                                                            0x0002
#define EFUSE_DATA_3_inst                                                            0x0003
#define EFUSE_DATA_4_inst                                                            0x0004
#define EFUSE_DATA_5_inst                                                            0x0005
#define EFUSE_DATA_6_inst                                                            0x0006
#define EFUSE_DATA_7_inst                                                            0x0007
#define EFUSE_DATA_8_inst                                                            0x0008
#define EFUSE_DATA_9_inst                                                            0x0009
#define EFUSE_DATA_10_inst                                                            0x000A
#define EFUSE_DATA_11_inst                                                            0x000B
#define EFUSE_DATA_12_inst                                                            0x000C
#define EFUSE_DATA_13_inst                                                            0x000D
#define EFUSE_DATA_14_inst                                                            0x000E
#define EFUSE_DATA_15_inst                                                            0x000F
#define EFUSE_DATA_16_inst                                                            0x0010
#define EFUSE_DATA_17_inst                                                            0x0011
#define EFUSE_DATA_18_inst                                                            0x0012
#define EFUSE_DATA_19_inst                                                            0x0013
#define EFUSE_DATA_20_inst                                                            0x0014
#define EFUSE_DATA_21_inst                                                            0x0015
#define EFUSE_DATA_22_inst                                                            0x0016
#define EFUSE_DATA_23_inst                                                            0x0017
#define EFUSE_DATA_24_inst                                                            0x0018
#define EFUSE_DATA_25_inst                                                            0x0019
#define EFUSE_DATA_26_inst                                                            0x001A
#define EFUSE_DATA_27_inst                                                            0x001B
#define EFUSE_DATA_28_inst                                                            0x001C
#define EFUSE_DATA_29_inst                                                            0x001D
#define EFUSE_DATA_30_inst                                                            0x001E
#define EFUSE_DATA_31_inst                                                            0x001F
#define EFUSE_DATA_32_inst                                                            0x0020
#define EFUSE_DATA_33_inst                                                            0x0021
#define EFUSE_DATA_34_inst                                                            0x0022
#define EFUSE_DATA_35_inst                                                            0x0023
#define EFUSE_DATA_36_inst                                                            0x0024
#define EFUSE_DATA_37_inst                                                            0x0025
#define EFUSE_DATA_38_inst                                                            0x0026
#define EFUSE_DATA_39_inst                                                            0x0027
#define EFUSE_DATA_40_inst                                                            0x0028
#define EFUSE_DATA_41_inst                                                            0x0029
#define EFUSE_DATA_42_inst                                                            0x002A
#define EFUSE_DATA_43_inst                                                            0x002B
#define EFUSE_DATA_44_inst                                                            0x002C
#define EFUSE_DATA_45_inst                                                            0x002D
#define EFUSE_DATA_46_inst                                                            0x002E
#define EFUSE_DATA_47_inst                                                            0x002F
#define EFUSE_DATA_48_inst                                                            0x0030
#define EFUSE_DATA_49_inst                                                            0x0031
#define EFUSE_DATA_50_inst                                                            0x0032
#define EFUSE_DATA_51_inst                                                            0x0033
#define EFUSE_DATA_52_inst                                                            0x0034
#define EFUSE_DATA_53_inst                                                            0x0035
#define EFUSE_DATA_54_inst                                                            0x0036
#define EFUSE_DATA_55_inst                                                            0x0037
#define EFUSE_DATA_56_inst                                                            0x0038
#define EFUSE_DATA_57_inst                                                            0x0039
#define EFUSE_DATA_58_inst                                                            0x003A
#define EFUSE_DATA_59_inst                                                            0x003B
#define EFUSE_DATA_60_inst                                                            0x003C
#define EFUSE_DATA_61_inst                                                            0x003D
#define EFUSE_DATA_62_inst                                                            0x003E
#define EFUSE_DATA_63_inst                                                            0x003F
#define EFUSE_DATA_64_inst                                                            0x0040
#define EFUSE_DATA_65_inst                                                            0x0041
#define EFUSE_DATA_66_inst                                                            0x0042
#define EFUSE_DATA_67_inst                                                            0x0043
#define EFUSE_DATA_68_inst                                                            0x0044
#define EFUSE_DATA_69_inst                                                            0x0045
#define EFUSE_DATA_70_inst                                                            0x0046
#define EFUSE_DATA_71_inst                                                            0x0047
#define EFUSE_DATA_72_inst                                                            0x0048
#define EFUSE_DATA_73_inst                                                            0x0049
#define EFUSE_DATA_74_inst                                                            0x004A
#define EFUSE_DATA_75_inst                                                            0x004B
#define EFUSE_DATA_76_inst                                                            0x004C
#define EFUSE_DATA_77_inst                                                            0x004D
#define EFUSE_DATA_78_inst                                                            0x004E
#define EFUSE_DATA_79_inst                                                            0x004F
#define EFUSE_DATA_80_inst                                                            0x0050
#define EFUSE_DATA_81_inst                                                            0x0051
#define EFUSE_DATA_82_inst                                                            0x0052
#define EFUSE_DATA_83_inst                                                            0x0053
#define EFUSE_DATA_84_inst                                                            0x0054
#define EFUSE_DATA_85_inst                                                            0x0055
#define EFUSE_DATA_86_inst                                                            0x0056
#define EFUSE_DATA_87_inst                                                            0x0057
#define EFUSE_DATA_88_inst                                                            0x0058
#define EFUSE_DATA_89_inst                                                            0x0059
#define EFUSE_DATA_90_inst                                                            0x005A
#define EFUSE_DATA_91_inst                                                            0x005B
#define EFUSE_DATA_92_inst                                                            0x005C
#define EFUSE_DATA_93_inst                                                            0x005D
#define EFUSE_DATA_94_inst                                                            0x005E
#define EFUSE_DATA_95_inst                                                            0x005F
#define EFUSE_DATA_96_inst                                                            0x0060
#define EFUSE_DATA_97_inst                                                            0x0061
#define EFUSE_DATA_98_inst                                                            0x0062
#define EFUSE_DATA_99_inst                                                            0x0063
#define EFUSE_DATA_100_inst                                                            0x0064
#define EFUSE_DATA_101_inst                                                            0x0065
#define EFUSE_DATA_102_inst                                                            0x0066
#define EFUSE_DATA_103_inst                                                            0x0067
#define EFUSE_DATA_104_inst                                                            0x0068
#define EFUSE_DATA_105_inst                                                            0x0069
#define EFUSE_DATA_106_inst                                                            0x006A
#define EFUSE_DATA_107_inst                                                            0x006B
#define EFUSE_DATA_108_inst                                                            0x006C
#define EFUSE_DATA_109_inst                                                            0x006D
#define EFUSE_DATA_110_inst                                                            0x006E
#define EFUSE_DATA_111_inst                                                            0x006F
#define EFUSE_DATA_112_inst                                                            0x0070
#define EFUSE_DATA_113_inst                                                            0x0071
#define EFUSE_DATA_114_inst                                                            0x0072
#define EFUSE_DATA_115_inst                                                            0x0073
#define EFUSE_DATA_116_inst                                                            0x0074
#define EFUSE_DATA_117_inst                                                            0x0075
#define EFUSE_DATA_118_inst                                                            0x0076
#define EFUSE_DATA_119_inst                                                            0x0077
#define EFUSE_DATA_120_inst                                                            0x0078
#define EFUSE_DATA_121_inst                                                            0x0079
#define EFUSE_DATA_122_inst                                                            0x007A
#define EFUSE_DATA_123_inst                                                            0x007B
#define EFUSE_DATA_124_inst                                                            0x007C
#define EFUSE_DATA_125_inst                                                            0x007D
#define EFUSE_DATA_126_inst                                                            0x007E
#define EFUSE_DATA_127_inst                                                            0x007F
#define EFUSE_DATA_datao_shift                                                       (0)
#define EFUSE_DATA_datao_mask                                                        (0xFFFFFFFF)
#define EFUSE_DATA_datao(data)                                                       (0xFFFFFFFF&((data)<<0))
#define EFUSE_DATA_datao_src(data)                                                   ((0xFFFFFFFF&(data))>>0)
#define EFUSE_DATA_get_datao(data)                                                   ((0xFFFFFFFF&(data))>>0)


#define EFUSE_EF_CTRL                                                                0x18038200
#define EFUSE_EF_CTRL_reg_addr                                                       "0xB8038200"
#define EFUSE_EF_CTRL_reg                                                            0xB8038200
#define set_EFUSE_EF_CTRL_reg(data)   (*((volatile unsigned int*) EFUSE_EF_CTRL_reg)=data)
#define get_EFUSE_EF_CTRL_reg   (*((volatile unsigned int*) EFUSE_EF_CTRL_reg))
#define EFUSE_EF_CTRL_inst_adr                                                       "0x0080"
#define EFUSE_EF_CTRL_inst                                                           0x0080
#define EFUSE_EF_CTRL_write_enable4_shift                                            (23)
#define EFUSE_EF_CTRL_write_enable4_mask                                             (0x00800000)
#define EFUSE_EF_CTRL_write_enable4(data)                                            (0x00800000&((data)<<23))
#define EFUSE_EF_CTRL_write_enable4_src(data)                                        ((0x00800000&(data))>>23)
#define EFUSE_EF_CTRL_get_write_enable4(data)                                        ((0x00800000&(data))>>23)
#define EFUSE_EF_CTRL_en_pro_efuse_shift                                             (22)
#define EFUSE_EF_CTRL_en_pro_efuse_mask                                              (0x00400000)
#define EFUSE_EF_CTRL_en_pro_efuse(data)                                             (0x00400000&((data)<<22))
#define EFUSE_EF_CTRL_en_pro_efuse_src(data)                                         ((0x00400000&(data))>>22)
#define EFUSE_EF_CTRL_get_en_pro_efuse(data)                                         ((0x00400000&(data))>>22)
#define EFUSE_EF_CTRL_write_enable3_shift                                            (21)
#define EFUSE_EF_CTRL_write_enable3_mask                                             (0x00200000)
#define EFUSE_EF_CTRL_write_enable3(data)                                            (0x00200000&((data)<<21))
#define EFUSE_EF_CTRL_write_enable3_src(data)                                        ((0x00200000&(data))>>21)
#define EFUSE_EF_CTRL_get_write_enable3(data)                                        ((0x00200000&(data))>>21)
#define EFUSE_EF_CTRL_auto_rd_req_shift                                              (20)
#define EFUSE_EF_CTRL_auto_rd_req_mask                                               (0x00100000)
#define EFUSE_EF_CTRL_auto_rd_req(data)                                              (0x00100000&((data)<<20))
#define EFUSE_EF_CTRL_auto_rd_req_src(data)                                          ((0x00100000&(data))>>20)
#define EFUSE_EF_CTRL_get_auto_rd_req(data)                                          ((0x00100000&(data))>>20)
#define EFUSE_EF_CTRL_write_enable2_shift                                            (14)
#define EFUSE_EF_CTRL_write_enable2_mask                                             (0x00004000)
#define EFUSE_EF_CTRL_write_enable2(data)                                            (0x00004000&((data)<<14))
#define EFUSE_EF_CTRL_write_enable2_src(data)                                        ((0x00004000&(data))>>14)
#define EFUSE_EF_CTRL_get_write_enable2(data)                                        ((0x00004000&(data))>>14)
#define EFUSE_EF_CTRL_strobe_shift                                                   (13)
#define EFUSE_EF_CTRL_strobe_mask                                                    (0x00002000)
#define EFUSE_EF_CTRL_strobe(data)                                                   (0x00002000&((data)<<13))
#define EFUSE_EF_CTRL_strobe_src(data)                                               ((0x00002000&(data))>>13)
#define EFUSE_EF_CTRL_get_strobe(data)                                               ((0x00002000&(data))>>13)
#define EFUSE_EF_CTRL_write_enable1_shift                                            (12)
#define EFUSE_EF_CTRL_write_enable1_mask                                             (0x00001000)
#define EFUSE_EF_CTRL_write_enable1(data)                                            (0x00001000&((data)<<12))
#define EFUSE_EF_CTRL_write_enable1_src(data)                                        ((0x00001000&(data))>>12)
#define EFUSE_EF_CTRL_get_write_enable1(data)                                        ((0x00001000&(data))>>12)
#define EFUSE_EF_CTRL_a_shift                                                        (0)
#define EFUSE_EF_CTRL_a_mask                                                         (0x00000FFF)
#define EFUSE_EF_CTRL_a(data)                                                        (0x00000FFF&((data)<<0))
#define EFUSE_EF_CTRL_a_src(data)                                                    ((0x00000FFF&(data))>>0)
#define EFUSE_EF_CTRL_get_a(data)                                                    ((0x00000FFF&(data))>>0)


#define EFUSE_EF_CTRL_ST                                                             0x18038204
#define EFUSE_EF_CTRL_ST_reg_addr                                                    "0xB8038204"
#define EFUSE_EF_CTRL_ST_reg                                                         0xB8038204
#define set_EFUSE_EF_CTRL_ST_reg(data)   (*((volatile unsigned int*) EFUSE_EF_CTRL_ST_reg)=data)
#define get_EFUSE_EF_CTRL_ST_reg   (*((volatile unsigned int*) EFUSE_EF_CTRL_ST_reg))
#define EFUSE_EF_CTRL_ST_inst_adr                                                    "0x0081"
#define EFUSE_EF_CTRL_ST_inst                                                        0x0081
#define EFUSE_EF_CTRL_ST_pro_efuse_act_shift                                         (16)
#define EFUSE_EF_CTRL_ST_pro_efuse_act_mask                                          (0x00010000)
#define EFUSE_EF_CTRL_ST_pro_efuse_act(data)                                         (0x00010000&((data)<<16))
#define EFUSE_EF_CTRL_ST_pro_efuse_act_src(data)                                     ((0x00010000&(data))>>16)
#define EFUSE_EF_CTRL_ST_get_pro_efuse_act(data)                                     ((0x00010000&(data))>>16)
#define EFUSE_EF_CTRL_ST_crc_en_shift                                                (0)
#define EFUSE_EF_CTRL_ST_crc_en_mask                                                 (0x00000001)
#define EFUSE_EF_CTRL_ST_crc_en(data)                                                (0x00000001&((data)<<0))
#define EFUSE_EF_CTRL_ST_crc_en_src(data)                                            ((0x00000001&(data))>>0)
#define EFUSE_EF_CTRL_ST_get_crc_en(data)                                            ((0x00000001&(data))>>0)


#define EFUSE_EF_CRC                                                                 0x18038208
#define EFUSE_EF_CRC_reg_addr                                                        "0xB8038208"
#define EFUSE_EF_CRC_reg                                                             0xB8038208
#define set_EFUSE_EF_CRC_reg(data)   (*((volatile unsigned int*) EFUSE_EF_CRC_reg)=data)
#define get_EFUSE_EF_CRC_reg   (*((volatile unsigned int*) EFUSE_EF_CRC_reg))
#define EFUSE_EF_CRC_inst_adr                                                        "0x0082"
#define EFUSE_EF_CRC_inst                                                            0x0082
#define EFUSE_EF_CRC_crc_ini_shift                                                   (16)
#define EFUSE_EF_CRC_crc_ini_mask                                                    (0x00FF0000)
#define EFUSE_EF_CRC_crc_ini(data)                                                   (0x00FF0000&((data)<<16))
#define EFUSE_EF_CRC_crc_ini_src(data)                                               ((0x00FF0000&(data))>>16)
#define EFUSE_EF_CRC_get_crc_ini(data)                                               ((0x00FF0000&(data))>>16)
#define EFUSE_EF_CRC_crc_out_shift                                                   (0)
#define EFUSE_EF_CRC_crc_out_mask                                                    (0x000000FF)
#define EFUSE_EF_CRC_crc_out(data)                                                   (0x000000FF&((data)<<0))
#define EFUSE_EF_CRC_crc_out_src(data)                                               ((0x000000FF&(data))>>0)
#define EFUSE_EF_CRC_get_crc_out(data)                                               ((0x000000FF&(data))>>0)


#endif
