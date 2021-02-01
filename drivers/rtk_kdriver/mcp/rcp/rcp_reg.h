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


#ifndef __RCP_REG_H__
#define __RCP_REG_H__

#if 1/*for scpu reg mode*/
#define CP_REG_KEY_0_reg                                                             0xB8015034
#define CP_REG_KEY_1_reg                                                             0xB8015038
#define CP_REG_KEY_2_reg                                                             0xB801503C
#define CP_REG_KEY_3_reg                                                             0xB8015040

#define CP_REG_KEY1_0_reg                                                             0xB8015210
#define CP_REG_KEY1_1_reg                                                             0xB8015214
#define CP_REG_KEY1_2_reg                                                             0xB8015218
#define CP_REG_KEY1_3_reg                                                             0xB801521C



#define CP_REG_DATAIN_0_reg                                                          0xB8015044
#define CP_REG_DATAIN_1_reg                                                          0xB8015048
#define CP_REG_DATAIN_2_reg                                                          0xB801504C
#define CP_REG_DATAIN_3_reg                                                          0xB8015050

#define CP_REG_DATAOUT_0_reg                                                         0xB8015054
#define CP_REG_DATAOUT_1_reg                                                         0xB8015058
#define CP_REG_DATAOUT_2_reg                                                         0xB801505C
#define CP_REG_DATAOUT_3_reg                                                         0xB8015060
#define CP_REG_DATAOUT_4_reg                                                         0xB8015064
#define CP_REG_DATAOUT_5_reg                                                         0xB8015068
#define CP_REG_DATAOUT_6_reg                                                         0xB801506C
#define CP_REG_DATAOUT_7_reg                                                         0xB8015070

#define CP_REG_IV_0_reg                                                              0xB80150D0
#define CP_REG_IV_1_reg                                                              0xB80150D4
#define CP_REG_IV_2_reg                                                              0xB80150D8
#define CP_REG_IV_3_reg                                                              0xB80150DC
#define CP_REG_IV_4_reg                                                              0xB80150E0
#define CP_REG_IV_5_reg                                                              0xB80150E4
#define CP_REG_IV_6_reg                                                              0xB80150E8
#define CP_REG_IV_7_reg                                                              0xB80150EC

#define CP_REG_SET_reg                                                               0xB8015074
#define CP_REG_SET1_reg                                                              0xB8015078
#define CP_REG_SET2_reg                                                              0xB801507C

#else

#define CP_REG_KEY_0_reg                                                           0xB8015834
#define CP_REG_KEY_1_reg                                                           0xB8015838
#define CP_REG_KEY_2_reg                                                           0xB801583C
#define CP_REG_KEY_3_reg                                                           0xB8015840

#define CP_REG_DATAIN_0_reg                                                        0xB8015844
#define CP_REG_DATAIN_1_reg                                                        0xB8015848
#define CP_REG_DATAIN_2_reg                                                        0xB801584C
#define CP_REG_DATAIN_3_reg                                                        0xB8015850

#define CP_REG_DATAOUT_0_reg                                                       0xB8015854
#define CP_REG_DATAOUT_1_reg                                                       0xB8015858
#define CP_REG_DATAOUT_2_reg                                                       0xB801585C
#define CP_REG_DATAOUT_3_reg                                                       0xB8015860
#define CP_REG_DATAOUT_4_reg                                                       0xB8015864
#define CP_REG_DATAOUT_5_reg                                                       0xB8015868
#define CP_REG_DATAOUT_6_reg                                                       0xB801586C
#define CP_REG_DATAOUT_7_reg                                                       0xB8015870

#define CP_REG_IV_0_reg                                                            0xB80158D0
#define CP_REG_IV_1_reg                                                            0xB80158D4
#define CP_REG_IV_2_reg                                                            0xB80158D8
#define CP_REG_IV_3_reg                                                            0xB80158DC
#define CP_REG_IV_4_reg                                                            0xB80158E0
#define CP_REG_IV_5_reg                                                            0xB80158E4
#define CP_REG_IV_6_reg                                                            0xB80158E8
#define CP_REG_IV_7_reg                                                            0xB80158EC


#define CP_REG_SET_reg                                                             0xB8015874
#define CP_REG_SET1_reg                                                            0xB8015878
#define CP_REG_SET2_reg                                                            0xB801587C

#endif


#endif
