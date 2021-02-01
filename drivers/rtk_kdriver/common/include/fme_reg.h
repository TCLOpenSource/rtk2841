/**************************************************************
// Spec Version                  : unknown
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Module_Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region 
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2015/9/23 15:3:45
***************************************************************/


#ifndef _FME_REG_H_INCLUDED_
#define _FME_REG_H_INCLUDED_
#ifdef  _FME_USE_STRUCT
typedef struct 
{
unsigned int     reserved_0:24;
unsigned int     EncodeType:2;
unsigned int     EnableMVC:1;
unsigned int     PicType:2;
unsigned int     FirstMbOfPic:1;
unsigned int     LastMbOfSlice:1;
unsigned int     FirstMbOfSlice:1;
}FME_COMM;

typedef struct 
{
unsigned int     hardware:20;
unsigned int     reserved_0:7;
unsigned int     disable16x16BiDir:1;
unsigned int     disable8x8BiDir:1;
unsigned int     only16x16:1;
unsigned int     search:2;
}FME_CTRL;

typedef struct 
{
unsigned int     reg_pskip_8x8th:8;
unsigned int     reg_pskip_coeffMax:8;
unsigned int     reg_xvid_sum4x4th:8;
unsigned int     reg_xvid_firstNZ4x4th:8;
}FME_MD0;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     subMbCostP8x8:8;
unsigned int     reg_pskip_mbth:8;
unsigned int     skip_cost_weight:8;
}FME_MD1;

typedef struct 
{
unsigned int     mbCost16x16L0:8;
unsigned int     mbCost16x16L1:8;
unsigned int     subMbCost8x8L0:8;
unsigned int     subMbCost8x8L1:8;
}FME_MD2;

typedef struct 
{
unsigned int     reserved_0:8;
unsigned int     mbCostB8x8:8;
unsigned int     mbCost16x16Bi:8;
unsigned int     subMbCost8x8Bi:8;
}FME_MD3;

typedef struct 
{
unsigned int     M:16;
unsigned int     subMbCost8x8direct:8;
unsigned int     mbCost16x16direct:8;
}FME_MD4;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     refidx:2;
unsigned int     mvx:12;
unsigned int     mvy:9;
}FME_TOPRR_B2_FW;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     refidx:2;
unsigned int     mvx:12;
unsigned int     mvy:9;
}FME_TOPRR_B2_BW;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     refidx:2;
unsigned int     mvx:12;
unsigned int     mvy:9;
}FME_TOPRR_B3_FW;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     refidx:2;
unsigned int     mvx:12;
unsigned int     mvy:9;
}FME_TOPRR_B3_BW;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     zero:4;
}FME_COL;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     maxfrac:5;
unsigned int     reserved_1:4;
unsigned int     maxintg:4;
unsigned int     bfrac:4;
unsigned int     bintg:4;
unsigned int     reserved_2:1;
unsigned int     lambda:7;
}FME_MVCOST;

typedef struct 
{
unsigned int     run0:4;
unsigned int     run1:4;
unsigned int     run2:4;
unsigned int     run3:4;
unsigned int     run4:4;
unsigned int     run5:4;
unsigned int     run6:4;
unsigned int     run7:4;
}FME_PSKIPCOST0;

typedef struct 
{
unsigned int     run8:4;
unsigned int     run9:4;
unsigned int     run10:4;
unsigned int     run11:4;
unsigned int     run12:4;
unsigned int     run13:4;
unsigned int     run14:4;
unsigned int     run15:4;
}FME_PSKIPCOST1;

typedef struct 
{
unsigned int     reserved_0:18;
unsigned int     chromapicidx_fw:7;
unsigned int     chromapicidx_bw:7;
}FME_SKIPDMA;

typedef struct 
{
unsigned int     reserved_0:19;
unsigned int     flat_qtable:1;
unsigned int     qpy:6;
unsigned int     qpc:6;
}FME_TQ_CNTL;

typedef struct 
{
unsigned int     reserved_0:3;
unsigned int     type:2;
unsigned int     partition:3;
unsigned int     b8x8_0_pred:2;
unsigned int     b8x8_1_pred:2;
unsigned int     b8x8_2_pred:2;
unsigned int     b8x8_3_pred:2;
unsigned int     b8x8_0_list0:2;
unsigned int     b8x8_1_list0:2;
unsigned int     b8x8_2_list0:2;
unsigned int     b8x8_3_list0:2;
unsigned int     b8x8_0_list1:2;
unsigned int     b8x8_1_list1:2;
unsigned int     b8x8_2_list1:2;
unsigned int     b8x8_3_list1:2;
}FME_RLT_MB;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     mvx:12;
unsigned int     mvy:9;
}FME_RLT_FW;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     mvx:12;
unsigned int     mvy:9;
}FME_RLT_BW;

typedef struct 
{
unsigned int     reserved_0:9;
unsigned int     pred:2;
unsigned int     mvx:12;
unsigned int     mvy:9;
}FME_RLT_16X16FW;

typedef struct 
{
unsigned int     reserved_0:11;
unsigned int     mvx:12;
unsigned int     mvy:9;
}FME_RLT_16X16BW;

typedef struct 
{
unsigned int     reserved_0:28;
unsigned int     zero:4;
}FME_RLT_COL;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     cost:18;
}FME_RLT_16X16;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     cost:18;
}FME_RLT_16X16DIRECT;

typedef struct 
{
unsigned int     reserved_0:14;
unsigned int     cost:18;
}FME_RLT_8X8;

typedef struct 
{
unsigned int     reserved_0:13;
unsigned int     skipable:1;
unsigned int     cost:18;
}FME_RLT_SKIP;

typedef struct 
{
unsigned int     status:32;
}FME_DEBUG0;

typedef struct 
{
unsigned int     status:32;
}FME_DEBUG1;

#endif

#define FME_COMM                                                                     0x18036000
#define FME_COMM_reg_addr                                                            "0xB8036000"
#define FME_COMM_reg                                                                 0xB8036000
#define set_FME_COMM_reg(data)   (*((volatile unsigned int*) FME_COMM_reg)=data)
#define get_FME_COMM_reg   (*((volatile unsigned int*) FME_COMM_reg))
#define FME_COMM_inst_adr                                                            "0x0000"
#define FME_COMM_inst                                                                0x0000
#define FME_COMM_EncodeType_shift                                                    (6)
#define FME_COMM_EncodeType_mask                                                     (0x000000C0)
#define FME_COMM_EncodeType(data)                                                    (0x000000C0&((data)<<6))
#define FME_COMM_EncodeType_src(data)                                                ((0x000000C0&(data))>>6)
#define FME_COMM_get_EncodeType(data)                                                ((0x000000C0&(data))>>6)
#define FME_COMM_EnableMVC_shift                                                     (5)
#define FME_COMM_EnableMVC_mask                                                      (0x00000020)
#define FME_COMM_EnableMVC(data)                                                     (0x00000020&((data)<<5))
#define FME_COMM_EnableMVC_src(data)                                                 ((0x00000020&(data))>>5)
#define FME_COMM_get_EnableMVC(data)                                                 ((0x00000020&(data))>>5)
#define FME_COMM_PicType_shift                                                       (3)
#define FME_COMM_PicType_mask                                                        (0x00000018)
#define FME_COMM_PicType(data)                                                       (0x00000018&((data)<<3))
#define FME_COMM_PicType_src(data)                                                   ((0x00000018&(data))>>3)
#define FME_COMM_get_PicType(data)                                                   ((0x00000018&(data))>>3)
#define FME_COMM_FirstMbOfPic_shift                                                  (2)
#define FME_COMM_FirstMbOfPic_mask                                                   (0x00000004)
#define FME_COMM_FirstMbOfPic(data)                                                  (0x00000004&((data)<<2))
#define FME_COMM_FirstMbOfPic_src(data)                                              ((0x00000004&(data))>>2)
#define FME_COMM_get_FirstMbOfPic(data)                                              ((0x00000004&(data))>>2)
#define FME_COMM_LastMbOfSlice_shift                                                 (1)
#define FME_COMM_LastMbOfSlice_mask                                                  (0x00000002)
#define FME_COMM_LastMbOfSlice(data)                                                 (0x00000002&((data)<<1))
#define FME_COMM_LastMbOfSlice_src(data)                                             ((0x00000002&(data))>>1)
#define FME_COMM_get_LastMbOfSlice(data)                                             ((0x00000002&(data))>>1)
#define FME_COMM_FirstMbOfSlice_shift                                                (0)
#define FME_COMM_FirstMbOfSlice_mask                                                 (0x00000001)
#define FME_COMM_FirstMbOfSlice(data)                                                (0x00000001&((data)<<0))
#define FME_COMM_FirstMbOfSlice_src(data)                                            ((0x00000001&(data))>>0)
#define FME_COMM_get_FirstMbOfSlice(data)                                            ((0x00000001&(data))>>0)


#define FME_CTRL                                                                     0x18036004
#define FME_CTRL_reg_addr                                                            "0xB8036004"
#define FME_CTRL_reg                                                                 0xB8036004
#define set_FME_CTRL_reg(data)   (*((volatile unsigned int*) FME_CTRL_reg)=data)
#define get_FME_CTRL_reg   (*((volatile unsigned int*) FME_CTRL_reg))
#define FME_CTRL_inst_adr                                                            "0x0001"
#define FME_CTRL_inst                                                                0x0001
#define FME_CTRL_hardware_shift                                                      (12)
#define FME_CTRL_hardware_mask                                                       (0xFFFFF000)
#define FME_CTRL_hardware(data)                                                      (0xFFFFF000&((data)<<12))
#define FME_CTRL_hardware_src(data)                                                  ((0xFFFFF000&(data))>>12)
#define FME_CTRL_get_hardware(data)                                                  ((0xFFFFF000&(data))>>12)
#define FME_CTRL_disable16x16BiDir_shift                                             (4)
#define FME_CTRL_disable16x16BiDir_mask                                              (0x00000010)
#define FME_CTRL_disable16x16BiDir(data)                                             (0x00000010&((data)<<4))
#define FME_CTRL_disable16x16BiDir_src(data)                                         ((0x00000010&(data))>>4)
#define FME_CTRL_get_disable16x16BiDir(data)                                         ((0x00000010&(data))>>4)
#define FME_CTRL_disable8x8BiDir_shift                                               (3)
#define FME_CTRL_disable8x8BiDir_mask                                                (0x00000008)
#define FME_CTRL_disable8x8BiDir(data)                                               (0x00000008&((data)<<3))
#define FME_CTRL_disable8x8BiDir_src(data)                                           ((0x00000008&(data))>>3)
#define FME_CTRL_get_disable8x8BiDir(data)                                           ((0x00000008&(data))>>3)
#define FME_CTRL_only16x16_shift                                                     (2)
#define FME_CTRL_only16x16_mask                                                      (0x00000004)
#define FME_CTRL_only16x16(data)                                                     (0x00000004&((data)<<2))
#define FME_CTRL_only16x16_src(data)                                                 ((0x00000004&(data))>>2)
#define FME_CTRL_get_only16x16(data)                                                 ((0x00000004&(data))>>2)
#define FME_CTRL_search_shift                                                        (0)
#define FME_CTRL_search_mask                                                         (0x00000003)
#define FME_CTRL_search(data)                                                        (0x00000003&((data)<<0))
#define FME_CTRL_search_src(data)                                                    ((0x00000003&(data))>>0)
#define FME_CTRL_get_search(data)                                                    ((0x00000003&(data))>>0)


#define FME_MD0                                                                      0x18036008
#define FME_MD0_reg_addr                                                             "0xB8036008"
#define FME_MD0_reg                                                                  0xB8036008
#define set_FME_MD0_reg(data)   (*((volatile unsigned int*) FME_MD0_reg)=data)
#define get_FME_MD0_reg   (*((volatile unsigned int*) FME_MD0_reg))
#define FME_MD0_inst_adr                                                             "0x0002"
#define FME_MD0_inst                                                                 0x0002
#define FME_MD0_reg_pskip_8x8th_shift                                                (24)
#define FME_MD0_reg_pskip_8x8th_mask                                                 (0xFF000000)
#define FME_MD0_reg_pskip_8x8th(data)                                                (0xFF000000&((data)<<24))
#define FME_MD0_reg_pskip_8x8th_src(data)                                            ((0xFF000000&(data))>>24)
#define FME_MD0_get_reg_pskip_8x8th(data)                                            ((0xFF000000&(data))>>24)
#define FME_MD0_reg_pskip_coeffMax_shift                                             (16)
#define FME_MD0_reg_pskip_coeffMax_mask                                              (0x00FF0000)
#define FME_MD0_reg_pskip_coeffMax(data)                                             (0x00FF0000&((data)<<16))
#define FME_MD0_reg_pskip_coeffMax_src(data)                                         ((0x00FF0000&(data))>>16)
#define FME_MD0_get_reg_pskip_coeffMax(data)                                         ((0x00FF0000&(data))>>16)
#define FME_MD0_reg_xvid_sum4x4th_shift                                              (8)
#define FME_MD0_reg_xvid_sum4x4th_mask                                               (0x0000FF00)
#define FME_MD0_reg_xvid_sum4x4th(data)                                              (0x0000FF00&((data)<<8))
#define FME_MD0_reg_xvid_sum4x4th_src(data)                                          ((0x0000FF00&(data))>>8)
#define FME_MD0_get_reg_xvid_sum4x4th(data)                                          ((0x0000FF00&(data))>>8)
#define FME_MD0_reg_xvid_firstNZ4x4th_shift                                          (0)
#define FME_MD0_reg_xvid_firstNZ4x4th_mask                                           (0x000000FF)
#define FME_MD0_reg_xvid_firstNZ4x4th(data)                                          (0x000000FF&((data)<<0))
#define FME_MD0_reg_xvid_firstNZ4x4th_src(data)                                      ((0x000000FF&(data))>>0)
#define FME_MD0_get_reg_xvid_firstNZ4x4th(data)                                      ((0x000000FF&(data))>>0)


#define FME_MD1                                                                      0x1803600c
#define FME_MD1_reg_addr                                                             "0xB803600C"
#define FME_MD1_reg                                                                  0xB803600C
#define set_FME_MD1_reg(data)   (*((volatile unsigned int*) FME_MD1_reg)=data)
#define get_FME_MD1_reg   (*((volatile unsigned int*) FME_MD1_reg))
#define FME_MD1_inst_adr                                                             "0x0003"
#define FME_MD1_inst                                                                 0x0003
#define FME_MD1_subMbCostP8x8_shift                                                  (16)
#define FME_MD1_subMbCostP8x8_mask                                                   (0x00FF0000)
#define FME_MD1_subMbCostP8x8(data)                                                  (0x00FF0000&((data)<<16))
#define FME_MD1_subMbCostP8x8_src(data)                                              ((0x00FF0000&(data))>>16)
#define FME_MD1_get_subMbCostP8x8(data)                                              ((0x00FF0000&(data))>>16)
#define FME_MD1_reg_pskip_mbth_shift                                                 (8)
#define FME_MD1_reg_pskip_mbth_mask                                                  (0x0000FF00)
#define FME_MD1_reg_pskip_mbth(data)                                                 (0x0000FF00&((data)<<8))
#define FME_MD1_reg_pskip_mbth_src(data)                                             ((0x0000FF00&(data))>>8)
#define FME_MD1_get_reg_pskip_mbth(data)                                             ((0x0000FF00&(data))>>8)
#define FME_MD1_skip_cost_weight_shift                                               (0)
#define FME_MD1_skip_cost_weight_mask                                                (0x000000FF)
#define FME_MD1_skip_cost_weight(data)                                               (0x000000FF&((data)<<0))
#define FME_MD1_skip_cost_weight_src(data)                                           ((0x000000FF&(data))>>0)
#define FME_MD1_get_skip_cost_weight(data)                                           ((0x000000FF&(data))>>0)


#define FME_MD2                                                                      0x18036010
#define FME_MD2_reg_addr                                                             "0xB8036010"
#define FME_MD2_reg                                                                  0xB8036010
#define set_FME_MD2_reg(data)   (*((volatile unsigned int*) FME_MD2_reg)=data)
#define get_FME_MD2_reg   (*((volatile unsigned int*) FME_MD2_reg))
#define FME_MD2_inst_adr                                                             "0x0004"
#define FME_MD2_inst                                                                 0x0004
#define FME_MD2_mbCost16x16L0_shift                                                  (24)
#define FME_MD2_mbCost16x16L0_mask                                                   (0xFF000000)
#define FME_MD2_mbCost16x16L0(data)                                                  (0xFF000000&((data)<<24))
#define FME_MD2_mbCost16x16L0_src(data)                                              ((0xFF000000&(data))>>24)
#define FME_MD2_get_mbCost16x16L0(data)                                              ((0xFF000000&(data))>>24)
#define FME_MD2_mbCost16x16L1_shift                                                  (16)
#define FME_MD2_mbCost16x16L1_mask                                                   (0x00FF0000)
#define FME_MD2_mbCost16x16L1(data)                                                  (0x00FF0000&((data)<<16))
#define FME_MD2_mbCost16x16L1_src(data)                                              ((0x00FF0000&(data))>>16)
#define FME_MD2_get_mbCost16x16L1(data)                                              ((0x00FF0000&(data))>>16)
#define FME_MD2_subMbCost8x8L0_shift                                                 (8)
#define FME_MD2_subMbCost8x8L0_mask                                                  (0x0000FF00)
#define FME_MD2_subMbCost8x8L0(data)                                                 (0x0000FF00&((data)<<8))
#define FME_MD2_subMbCost8x8L0_src(data)                                             ((0x0000FF00&(data))>>8)
#define FME_MD2_get_subMbCost8x8L0(data)                                             ((0x0000FF00&(data))>>8)
#define FME_MD2_subMbCost8x8L1_shift                                                 (0)
#define FME_MD2_subMbCost8x8L1_mask                                                  (0x000000FF)
#define FME_MD2_subMbCost8x8L1(data)                                                 (0x000000FF&((data)<<0))
#define FME_MD2_subMbCost8x8L1_src(data)                                             ((0x000000FF&(data))>>0)
#define FME_MD2_get_subMbCost8x8L1(data)                                             ((0x000000FF&(data))>>0)


#define FME_MD3                                                                      0x18036014
#define FME_MD3_reg_addr                                                             "0xB8036014"
#define FME_MD3_reg                                                                  0xB8036014
#define set_FME_MD3_reg(data)   (*((volatile unsigned int*) FME_MD3_reg)=data)
#define get_FME_MD3_reg   (*((volatile unsigned int*) FME_MD3_reg))
#define FME_MD3_inst_adr                                                             "0x0005"
#define FME_MD3_inst                                                                 0x0005
#define FME_MD3_mbCostB8x8_shift                                                     (16)
#define FME_MD3_mbCostB8x8_mask                                                      (0x00FF0000)
#define FME_MD3_mbCostB8x8(data)                                                     (0x00FF0000&((data)<<16))
#define FME_MD3_mbCostB8x8_src(data)                                                 ((0x00FF0000&(data))>>16)
#define FME_MD3_get_mbCostB8x8(data)                                                 ((0x00FF0000&(data))>>16)
#define FME_MD3_mbCost16x16Bi_shift                                                  (8)
#define FME_MD3_mbCost16x16Bi_mask                                                   (0x0000FF00)
#define FME_MD3_mbCost16x16Bi(data)                                                  (0x0000FF00&((data)<<8))
#define FME_MD3_mbCost16x16Bi_src(data)                                              ((0x0000FF00&(data))>>8)
#define FME_MD3_get_mbCost16x16Bi(data)                                              ((0x0000FF00&(data))>>8)
#define FME_MD3_subMbCost8x8Bi_shift                                                 (0)
#define FME_MD3_subMbCost8x8Bi_mask                                                  (0x000000FF)
#define FME_MD3_subMbCost8x8Bi(data)                                                 (0x000000FF&((data)<<0))
#define FME_MD3_subMbCost8x8Bi_src(data)                                             ((0x000000FF&(data))>>0)
#define FME_MD3_get_subMbCost8x8Bi(data)                                             ((0x000000FF&(data))>>0)


#define FME_MD4                                                                      0x18036018
#define FME_MD4_reg_addr                                                             "0xB8036018"
#define FME_MD4_reg                                                                  0xB8036018
#define set_FME_MD4_reg(data)   (*((volatile unsigned int*) FME_MD4_reg)=data)
#define get_FME_MD4_reg   (*((volatile unsigned int*) FME_MD4_reg))
#define FME_MD4_inst_adr                                                             "0x0006"
#define FME_MD4_inst                                                                 0x0006
#define FME_MD4_M_shift                                                              (16)
#define FME_MD4_M_mask                                                               (0xFFFF0000)
#define FME_MD4_M(data)                                                              (0xFFFF0000&((data)<<16))
#define FME_MD4_M_src(data)                                                          ((0xFFFF0000&(data))>>16)
#define FME_MD4_get_M(data)                                                          ((0xFFFF0000&(data))>>16)
#define FME_MD4_subMbCost8x8direct_shift                                             (8)
#define FME_MD4_subMbCost8x8direct_mask                                              (0x0000FF00)
#define FME_MD4_subMbCost8x8direct(data)                                             (0x0000FF00&((data)<<8))
#define FME_MD4_subMbCost8x8direct_src(data)                                         ((0x0000FF00&(data))>>8)
#define FME_MD4_get_subMbCost8x8direct(data)                                         ((0x0000FF00&(data))>>8)
#define FME_MD4_mbCost16x16direct_shift                                              (0)
#define FME_MD4_mbCost16x16direct_mask                                               (0x000000FF)
#define FME_MD4_mbCost16x16direct(data)                                              (0x000000FF&((data)<<0))
#define FME_MD4_mbCost16x16direct_src(data)                                          ((0x000000FF&(data))>>0)
#define FME_MD4_get_mbCost16x16direct(data)                                          ((0x000000FF&(data))>>0)


#define FME_TOPRR_B2_FW                                                              0x1803601c
#define FME_TOPRR_B2_FW_reg_addr                                                     "0xB803601C"
#define FME_TOPRR_B2_FW_reg                                                          0xB803601C
#define set_FME_TOPRR_B2_FW_reg(data)   (*((volatile unsigned int*) FME_TOPRR_B2_FW_reg)=data)
#define get_FME_TOPRR_B2_FW_reg   (*((volatile unsigned int*) FME_TOPRR_B2_FW_reg))
#define FME_TOPRR_B2_FW_inst_adr                                                     "0x0007"
#define FME_TOPRR_B2_FW_inst                                                         0x0007
#define FME_TOPRR_B2_FW_refidx_shift                                                 (21)
#define FME_TOPRR_B2_FW_refidx_mask                                                  (0x00600000)
#define FME_TOPRR_B2_FW_refidx(data)                                                 (0x00600000&((data)<<21))
#define FME_TOPRR_B2_FW_refidx_src(data)                                             ((0x00600000&(data))>>21)
#define FME_TOPRR_B2_FW_get_refidx(data)                                             ((0x00600000&(data))>>21)
#define FME_TOPRR_B2_FW_mvx_shift                                                    (9)
#define FME_TOPRR_B2_FW_mvx_mask                                                     (0x001FFE00)
#define FME_TOPRR_B2_FW_mvx(data)                                                    (0x001FFE00&((data)<<9))
#define FME_TOPRR_B2_FW_mvx_src(data)                                                ((0x001FFE00&(data))>>9)
#define FME_TOPRR_B2_FW_get_mvx(data)                                                ((0x001FFE00&(data))>>9)
#define FME_TOPRR_B2_FW_mvy_shift                                                    (0)
#define FME_TOPRR_B2_FW_mvy_mask                                                     (0x000001FF)
#define FME_TOPRR_B2_FW_mvy(data)                                                    (0x000001FF&((data)<<0))
#define FME_TOPRR_B2_FW_mvy_src(data)                                                ((0x000001FF&(data))>>0)
#define FME_TOPRR_B2_FW_get_mvy(data)                                                ((0x000001FF&(data))>>0)


#define FME_TOPRR_B2_BW                                                              0x18036020
#define FME_TOPRR_B2_BW_reg_addr                                                     "0xB8036020"
#define FME_TOPRR_B2_BW_reg                                                          0xB8036020
#define set_FME_TOPRR_B2_BW_reg(data)   (*((volatile unsigned int*) FME_TOPRR_B2_BW_reg)=data)
#define get_FME_TOPRR_B2_BW_reg   (*((volatile unsigned int*) FME_TOPRR_B2_BW_reg))
#define FME_TOPRR_B2_BW_inst_adr                                                     "0x0008"
#define FME_TOPRR_B2_BW_inst                                                         0x0008
#define FME_TOPRR_B2_BW_refidx_shift                                                 (21)
#define FME_TOPRR_B2_BW_refidx_mask                                                  (0x00600000)
#define FME_TOPRR_B2_BW_refidx(data)                                                 (0x00600000&((data)<<21))
#define FME_TOPRR_B2_BW_refidx_src(data)                                             ((0x00600000&(data))>>21)
#define FME_TOPRR_B2_BW_get_refidx(data)                                             ((0x00600000&(data))>>21)
#define FME_TOPRR_B2_BW_mvx_shift                                                    (9)
#define FME_TOPRR_B2_BW_mvx_mask                                                     (0x001FFE00)
#define FME_TOPRR_B2_BW_mvx(data)                                                    (0x001FFE00&((data)<<9))
#define FME_TOPRR_B2_BW_mvx_src(data)                                                ((0x001FFE00&(data))>>9)
#define FME_TOPRR_B2_BW_get_mvx(data)                                                ((0x001FFE00&(data))>>9)
#define FME_TOPRR_B2_BW_mvy_shift                                                    (0)
#define FME_TOPRR_B2_BW_mvy_mask                                                     (0x000001FF)
#define FME_TOPRR_B2_BW_mvy(data)                                                    (0x000001FF&((data)<<0))
#define FME_TOPRR_B2_BW_mvy_src(data)                                                ((0x000001FF&(data))>>0)
#define FME_TOPRR_B2_BW_get_mvy(data)                                                ((0x000001FF&(data))>>0)


#define FME_TOPRR_B3_FW                                                              0x18036024
#define FME_TOPRR_B3_FW_reg_addr                                                     "0xB8036024"
#define FME_TOPRR_B3_FW_reg                                                          0xB8036024
#define set_FME_TOPRR_B3_FW_reg(data)   (*((volatile unsigned int*) FME_TOPRR_B3_FW_reg)=data)
#define get_FME_TOPRR_B3_FW_reg   (*((volatile unsigned int*) FME_TOPRR_B3_FW_reg))
#define FME_TOPRR_B3_FW_inst_adr                                                     "0x0009"
#define FME_TOPRR_B3_FW_inst                                                         0x0009
#define FME_TOPRR_B3_FW_refidx_shift                                                 (21)
#define FME_TOPRR_B3_FW_refidx_mask                                                  (0x00600000)
#define FME_TOPRR_B3_FW_refidx(data)                                                 (0x00600000&((data)<<21))
#define FME_TOPRR_B3_FW_refidx_src(data)                                             ((0x00600000&(data))>>21)
#define FME_TOPRR_B3_FW_get_refidx(data)                                             ((0x00600000&(data))>>21)
#define FME_TOPRR_B3_FW_mvx_shift                                                    (9)
#define FME_TOPRR_B3_FW_mvx_mask                                                     (0x001FFE00)
#define FME_TOPRR_B3_FW_mvx(data)                                                    (0x001FFE00&((data)<<9))
#define FME_TOPRR_B3_FW_mvx_src(data)                                                ((0x001FFE00&(data))>>9)
#define FME_TOPRR_B3_FW_get_mvx(data)                                                ((0x001FFE00&(data))>>9)
#define FME_TOPRR_B3_FW_mvy_shift                                                    (0)
#define FME_TOPRR_B3_FW_mvy_mask                                                     (0x000001FF)
#define FME_TOPRR_B3_FW_mvy(data)                                                    (0x000001FF&((data)<<0))
#define FME_TOPRR_B3_FW_mvy_src(data)                                                ((0x000001FF&(data))>>0)
#define FME_TOPRR_B3_FW_get_mvy(data)                                                ((0x000001FF&(data))>>0)


#define FME_TOPRR_B3_BW                                                              0x18036028
#define FME_TOPRR_B3_BW_reg_addr                                                     "0xB8036028"
#define FME_TOPRR_B3_BW_reg                                                          0xB8036028
#define set_FME_TOPRR_B3_BW_reg(data)   (*((volatile unsigned int*) FME_TOPRR_B3_BW_reg)=data)
#define get_FME_TOPRR_B3_BW_reg   (*((volatile unsigned int*) FME_TOPRR_B3_BW_reg))
#define FME_TOPRR_B3_BW_inst_adr                                                     "0x000A"
#define FME_TOPRR_B3_BW_inst                                                         0x000A
#define FME_TOPRR_B3_BW_refidx_shift                                                 (21)
#define FME_TOPRR_B3_BW_refidx_mask                                                  (0x00600000)
#define FME_TOPRR_B3_BW_refidx(data)                                                 (0x00600000&((data)<<21))
#define FME_TOPRR_B3_BW_refidx_src(data)                                             ((0x00600000&(data))>>21)
#define FME_TOPRR_B3_BW_get_refidx(data)                                             ((0x00600000&(data))>>21)
#define FME_TOPRR_B3_BW_mvx_shift                                                    (9)
#define FME_TOPRR_B3_BW_mvx_mask                                                     (0x001FFE00)
#define FME_TOPRR_B3_BW_mvx(data)                                                    (0x001FFE00&((data)<<9))
#define FME_TOPRR_B3_BW_mvx_src(data)                                                ((0x001FFE00&(data))>>9)
#define FME_TOPRR_B3_BW_get_mvx(data)                                                ((0x001FFE00&(data))>>9)
#define FME_TOPRR_B3_BW_mvy_shift                                                    (0)
#define FME_TOPRR_B3_BW_mvy_mask                                                     (0x000001FF)
#define FME_TOPRR_B3_BW_mvy(data)                                                    (0x000001FF&((data)<<0))
#define FME_TOPRR_B3_BW_mvy_src(data)                                                ((0x000001FF&(data))>>0)
#define FME_TOPRR_B3_BW_get_mvy(data)                                                ((0x000001FF&(data))>>0)


#define FME_COL                                                                      0x1803602c
#define FME_COL_reg_addr                                                             "0xB803602C"
#define FME_COL_reg                                                                  0xB803602C
#define set_FME_COL_reg(data)   (*((volatile unsigned int*) FME_COL_reg)=data)
#define get_FME_COL_reg   (*((volatile unsigned int*) FME_COL_reg))
#define FME_COL_inst_adr                                                             "0x000B"
#define FME_COL_inst                                                                 0x000B
#define FME_COL_zero_shift                                                           (0)
#define FME_COL_zero_mask                                                            (0x0000000F)
#define FME_COL_zero(data)                                                           (0x0000000F&((data)<<0))
#define FME_COL_zero_src(data)                                                       ((0x0000000F&(data))>>0)
#define FME_COL_get_zero(data)                                                       ((0x0000000F&(data))>>0)


#define FME_MVCOST                                                                   0x18036030
#define FME_MVCOST_reg_addr                                                          "0xB8036030"
#define FME_MVCOST_reg                                                               0xB8036030
#define set_FME_MVCOST_reg(data)   (*((volatile unsigned int*) FME_MVCOST_reg)=data)
#define get_FME_MVCOST_reg   (*((volatile unsigned int*) FME_MVCOST_reg))
#define FME_MVCOST_inst_adr                                                          "0x000C"
#define FME_MVCOST_inst                                                              0x000C
#define FME_MVCOST_maxfrac_shift                                                     (24)
#define FME_MVCOST_maxfrac_mask                                                      (0x1F000000)
#define FME_MVCOST_maxfrac(data)                                                     (0x1F000000&((data)<<24))
#define FME_MVCOST_maxfrac_src(data)                                                 ((0x1F000000&(data))>>24)
#define FME_MVCOST_get_maxfrac(data)                                                 ((0x1F000000&(data))>>24)
#define FME_MVCOST_maxintg_shift                                                     (16)
#define FME_MVCOST_maxintg_mask                                                      (0x000F0000)
#define FME_MVCOST_maxintg(data)                                                     (0x000F0000&((data)<<16))
#define FME_MVCOST_maxintg_src(data)                                                 ((0x000F0000&(data))>>16)
#define FME_MVCOST_get_maxintg(data)                                                 ((0x000F0000&(data))>>16)
#define FME_MVCOST_bfrac_shift                                                       (12)
#define FME_MVCOST_bfrac_mask                                                        (0x0000F000)
#define FME_MVCOST_bfrac(data)                                                       (0x0000F000&((data)<<12))
#define FME_MVCOST_bfrac_src(data)                                                   ((0x0000F000&(data))>>12)
#define FME_MVCOST_get_bfrac(data)                                                   ((0x0000F000&(data))>>12)
#define FME_MVCOST_bintg_shift                                                       (8)
#define FME_MVCOST_bintg_mask                                                        (0x00000F00)
#define FME_MVCOST_bintg(data)                                                       (0x00000F00&((data)<<8))
#define FME_MVCOST_bintg_src(data)                                                   ((0x00000F00&(data))>>8)
#define FME_MVCOST_get_bintg(data)                                                   ((0x00000F00&(data))>>8)
#define FME_MVCOST_lambda_shift                                                      (0)
#define FME_MVCOST_lambda_mask                                                       (0x0000007F)
#define FME_MVCOST_lambda(data)                                                      (0x0000007F&((data)<<0))
#define FME_MVCOST_lambda_src(data)                                                  ((0x0000007F&(data))>>0)
#define FME_MVCOST_get_lambda(data)                                                  ((0x0000007F&(data))>>0)


#define FME_PSKIPCOST0                                                               0x18036034
#define FME_PSKIPCOST0_reg_addr                                                      "0xB8036034"
#define FME_PSKIPCOST0_reg                                                           0xB8036034
#define set_FME_PSKIPCOST0_reg(data)   (*((volatile unsigned int*) FME_PSKIPCOST0_reg)=data)
#define get_FME_PSKIPCOST0_reg   (*((volatile unsigned int*) FME_PSKIPCOST0_reg))
#define FME_PSKIPCOST0_inst_adr                                                      "0x000D"
#define FME_PSKIPCOST0_inst                                                          0x000D
#define FME_PSKIPCOST0_run0_shift                                                    (28)
#define FME_PSKIPCOST0_run0_mask                                                     (0xF0000000)
#define FME_PSKIPCOST0_run0(data)                                                    (0xF0000000&((data)<<28))
#define FME_PSKIPCOST0_run0_src(data)                                                ((0xF0000000&(data))>>28)
#define FME_PSKIPCOST0_get_run0(data)                                                ((0xF0000000&(data))>>28)
#define FME_PSKIPCOST0_run1_shift                                                    (24)
#define FME_PSKIPCOST0_run1_mask                                                     (0x0F000000)
#define FME_PSKIPCOST0_run1(data)                                                    (0x0F000000&((data)<<24))
#define FME_PSKIPCOST0_run1_src(data)                                                ((0x0F000000&(data))>>24)
#define FME_PSKIPCOST0_get_run1(data)                                                ((0x0F000000&(data))>>24)
#define FME_PSKIPCOST0_run2_shift                                                    (20)
#define FME_PSKIPCOST0_run2_mask                                                     (0x00F00000)
#define FME_PSKIPCOST0_run2(data)                                                    (0x00F00000&((data)<<20))
#define FME_PSKIPCOST0_run2_src(data)                                                ((0x00F00000&(data))>>20)
#define FME_PSKIPCOST0_get_run2(data)                                                ((0x00F00000&(data))>>20)
#define FME_PSKIPCOST0_run3_shift                                                    (16)
#define FME_PSKIPCOST0_run3_mask                                                     (0x000F0000)
#define FME_PSKIPCOST0_run3(data)                                                    (0x000F0000&((data)<<16))
#define FME_PSKIPCOST0_run3_src(data)                                                ((0x000F0000&(data))>>16)
#define FME_PSKIPCOST0_get_run3(data)                                                ((0x000F0000&(data))>>16)
#define FME_PSKIPCOST0_run4_shift                                                    (12)
#define FME_PSKIPCOST0_run4_mask                                                     (0x0000F000)
#define FME_PSKIPCOST0_run4(data)                                                    (0x0000F000&((data)<<12))
#define FME_PSKIPCOST0_run4_src(data)                                                ((0x0000F000&(data))>>12)
#define FME_PSKIPCOST0_get_run4(data)                                                ((0x0000F000&(data))>>12)
#define FME_PSKIPCOST0_run5_shift                                                    (8)
#define FME_PSKIPCOST0_run5_mask                                                     (0x00000F00)
#define FME_PSKIPCOST0_run5(data)                                                    (0x00000F00&((data)<<8))
#define FME_PSKIPCOST0_run5_src(data)                                                ((0x00000F00&(data))>>8)
#define FME_PSKIPCOST0_get_run5(data)                                                ((0x00000F00&(data))>>8)
#define FME_PSKIPCOST0_run6_shift                                                    (4)
#define FME_PSKIPCOST0_run6_mask                                                     (0x000000F0)
#define FME_PSKIPCOST0_run6(data)                                                    (0x000000F0&((data)<<4))
#define FME_PSKIPCOST0_run6_src(data)                                                ((0x000000F0&(data))>>4)
#define FME_PSKIPCOST0_get_run6(data)                                                ((0x000000F0&(data))>>4)
#define FME_PSKIPCOST0_run7_shift                                                    (0)
#define FME_PSKIPCOST0_run7_mask                                                     (0x0000000F)
#define FME_PSKIPCOST0_run7(data)                                                    (0x0000000F&((data)<<0))
#define FME_PSKIPCOST0_run7_src(data)                                                ((0x0000000F&(data))>>0)
#define FME_PSKIPCOST0_get_run7(data)                                                ((0x0000000F&(data))>>0)


#define FME_PSKIPCOST1                                                               0x18036038
#define FME_PSKIPCOST1_reg_addr                                                      "0xB8036038"
#define FME_PSKIPCOST1_reg                                                           0xB8036038
#define set_FME_PSKIPCOST1_reg(data)   (*((volatile unsigned int*) FME_PSKIPCOST1_reg)=data)
#define get_FME_PSKIPCOST1_reg   (*((volatile unsigned int*) FME_PSKIPCOST1_reg))
#define FME_PSKIPCOST1_inst_adr                                                      "0x000E"
#define FME_PSKIPCOST1_inst                                                          0x000E
#define FME_PSKIPCOST1_run8_shift                                                    (28)
#define FME_PSKIPCOST1_run8_mask                                                     (0xF0000000)
#define FME_PSKIPCOST1_run8(data)                                                    (0xF0000000&((data)<<28))
#define FME_PSKIPCOST1_run8_src(data)                                                ((0xF0000000&(data))>>28)
#define FME_PSKIPCOST1_get_run8(data)                                                ((0xF0000000&(data))>>28)
#define FME_PSKIPCOST1_run9_shift                                                    (24)
#define FME_PSKIPCOST1_run9_mask                                                     (0x0F000000)
#define FME_PSKIPCOST1_run9(data)                                                    (0x0F000000&((data)<<24))
#define FME_PSKIPCOST1_run9_src(data)                                                ((0x0F000000&(data))>>24)
#define FME_PSKIPCOST1_get_run9(data)                                                ((0x0F000000&(data))>>24)
#define FME_PSKIPCOST1_run10_shift                                                   (20)
#define FME_PSKIPCOST1_run10_mask                                                    (0x00F00000)
#define FME_PSKIPCOST1_run10(data)                                                   (0x00F00000&((data)<<20))
#define FME_PSKIPCOST1_run10_src(data)                                               ((0x00F00000&(data))>>20)
#define FME_PSKIPCOST1_get_run10(data)                                               ((0x00F00000&(data))>>20)
#define FME_PSKIPCOST1_run11_shift                                                   (16)
#define FME_PSKIPCOST1_run11_mask                                                    (0x000F0000)
#define FME_PSKIPCOST1_run11(data)                                                   (0x000F0000&((data)<<16))
#define FME_PSKIPCOST1_run11_src(data)                                               ((0x000F0000&(data))>>16)
#define FME_PSKIPCOST1_get_run11(data)                                               ((0x000F0000&(data))>>16)
#define FME_PSKIPCOST1_run12_shift                                                   (12)
#define FME_PSKIPCOST1_run12_mask                                                    (0x0000F000)
#define FME_PSKIPCOST1_run12(data)                                                   (0x0000F000&((data)<<12))
#define FME_PSKIPCOST1_run12_src(data)                                               ((0x0000F000&(data))>>12)
#define FME_PSKIPCOST1_get_run12(data)                                               ((0x0000F000&(data))>>12)
#define FME_PSKIPCOST1_run13_shift                                                   (8)
#define FME_PSKIPCOST1_run13_mask                                                    (0x00000F00)
#define FME_PSKIPCOST1_run13(data)                                                   (0x00000F00&((data)<<8))
#define FME_PSKIPCOST1_run13_src(data)                                               ((0x00000F00&(data))>>8)
#define FME_PSKIPCOST1_get_run13(data)                                               ((0x00000F00&(data))>>8)
#define FME_PSKIPCOST1_run14_shift                                                   (4)
#define FME_PSKIPCOST1_run14_mask                                                    (0x000000F0)
#define FME_PSKIPCOST1_run14(data)                                                   (0x000000F0&((data)<<4))
#define FME_PSKIPCOST1_run14_src(data)                                               ((0x000000F0&(data))>>4)
#define FME_PSKIPCOST1_get_run14(data)                                               ((0x000000F0&(data))>>4)
#define FME_PSKIPCOST1_run15_shift                                                   (0)
#define FME_PSKIPCOST1_run15_mask                                                    (0x0000000F)
#define FME_PSKIPCOST1_run15(data)                                                   (0x0000000F&((data)<<0))
#define FME_PSKIPCOST1_run15_src(data)                                               ((0x0000000F&(data))>>0)
#define FME_PSKIPCOST1_get_run15(data)                                               ((0x0000000F&(data))>>0)


#define FME_SKIPDMA                                                                  0x1803603c
#define FME_SKIPDMA_reg_addr                                                         "0xB803603C"
#define FME_SKIPDMA_reg                                                              0xB803603C
#define set_FME_SKIPDMA_reg(data)   (*((volatile unsigned int*) FME_SKIPDMA_reg)=data)
#define get_FME_SKIPDMA_reg   (*((volatile unsigned int*) FME_SKIPDMA_reg))
#define FME_SKIPDMA_inst_adr                                                         "0x000F"
#define FME_SKIPDMA_inst                                                             0x000F
#define FME_SKIPDMA_chromapicidx_fw_shift                                            (7)
#define FME_SKIPDMA_chromapicidx_fw_mask                                             (0x00003F80)
#define FME_SKIPDMA_chromapicidx_fw(data)                                            (0x00003F80&((data)<<7))
#define FME_SKIPDMA_chromapicidx_fw_src(data)                                        ((0x00003F80&(data))>>7)
#define FME_SKIPDMA_get_chromapicidx_fw(data)                                        ((0x00003F80&(data))>>7)
#define FME_SKIPDMA_chromapicidx_bw_shift                                            (0)
#define FME_SKIPDMA_chromapicidx_bw_mask                                             (0x0000007F)
#define FME_SKIPDMA_chromapicidx_bw(data)                                            (0x0000007F&((data)<<0))
#define FME_SKIPDMA_chromapicidx_bw_src(data)                                        ((0x0000007F&(data))>>0)
#define FME_SKIPDMA_get_chromapicidx_bw(data)                                        ((0x0000007F&(data))>>0)


#define FME_TQ_CNTL                                                                  0x18036040
#define FME_TQ_CNTL_reg_addr                                                         "0xB8036040"
#define FME_TQ_CNTL_reg                                                              0xB8036040
#define set_FME_TQ_CNTL_reg(data)   (*((volatile unsigned int*) FME_TQ_CNTL_reg)=data)
#define get_FME_TQ_CNTL_reg   (*((volatile unsigned int*) FME_TQ_CNTL_reg))
#define FME_TQ_CNTL_inst_adr                                                         "0x0010"
#define FME_TQ_CNTL_inst                                                             0x0010
#define FME_TQ_CNTL_flat_qtable_shift                                                (12)
#define FME_TQ_CNTL_flat_qtable_mask                                                 (0x00001000)
#define FME_TQ_CNTL_flat_qtable(data)                                                (0x00001000&((data)<<12))
#define FME_TQ_CNTL_flat_qtable_src(data)                                            ((0x00001000&(data))>>12)
#define FME_TQ_CNTL_get_flat_qtable(data)                                            ((0x00001000&(data))>>12)
#define FME_TQ_CNTL_qpy_shift                                                        (6)
#define FME_TQ_CNTL_qpy_mask                                                         (0x00000FC0)
#define FME_TQ_CNTL_qpy(data)                                                        (0x00000FC0&((data)<<6))
#define FME_TQ_CNTL_qpy_src(data)                                                    ((0x00000FC0&(data))>>6)
#define FME_TQ_CNTL_get_qpy(data)                                                    ((0x00000FC0&(data))>>6)
#define FME_TQ_CNTL_qpc_shift                                                        (0)
#define FME_TQ_CNTL_qpc_mask                                                         (0x0000003F)
#define FME_TQ_CNTL_qpc(data)                                                        (0x0000003F&((data)<<0))
#define FME_TQ_CNTL_qpc_src(data)                                                    ((0x0000003F&(data))>>0)
#define FME_TQ_CNTL_get_qpc(data)                                                    ((0x0000003F&(data))>>0)


#define FME_RLT_MB                                                                   0x18036044
#define FME_RLT_MB_reg_addr                                                          "0xB8036044"
#define FME_RLT_MB_reg                                                               0xB8036044
#define set_FME_RLT_MB_reg(data)   (*((volatile unsigned int*) FME_RLT_MB_reg)=data)
#define get_FME_RLT_MB_reg   (*((volatile unsigned int*) FME_RLT_MB_reg))
#define FME_RLT_MB_inst_adr                                                          "0x0011"
#define FME_RLT_MB_inst                                                              0x0011
#define FME_RLT_MB_type_shift                                                        (27)
#define FME_RLT_MB_type_mask                                                         (0x18000000)
#define FME_RLT_MB_type(data)                                                        (0x18000000&((data)<<27))
#define FME_RLT_MB_type_src(data)                                                    ((0x18000000&(data))>>27)
#define FME_RLT_MB_get_type(data)                                                    ((0x18000000&(data))>>27)
#define FME_RLT_MB_partition_shift                                                   (24)
#define FME_RLT_MB_partition_mask                                                    (0x07000000)
#define FME_RLT_MB_partition(data)                                                   (0x07000000&((data)<<24))
#define FME_RLT_MB_partition_src(data)                                               ((0x07000000&(data))>>24)
#define FME_RLT_MB_get_partition(data)                                               ((0x07000000&(data))>>24)
#define FME_RLT_MB_b8x8_0_pred_shift                                                 (22)
#define FME_RLT_MB_b8x8_0_pred_mask                                                  (0x00C00000)
#define FME_RLT_MB_b8x8_0_pred(data)                                                 (0x00C00000&((data)<<22))
#define FME_RLT_MB_b8x8_0_pred_src(data)                                             ((0x00C00000&(data))>>22)
#define FME_RLT_MB_get_b8x8_0_pred(data)                                             ((0x00C00000&(data))>>22)
#define FME_RLT_MB_b8x8_1_pred_shift                                                 (20)
#define FME_RLT_MB_b8x8_1_pred_mask                                                  (0x00300000)
#define FME_RLT_MB_b8x8_1_pred(data)                                                 (0x00300000&((data)<<20))
#define FME_RLT_MB_b8x8_1_pred_src(data)                                             ((0x00300000&(data))>>20)
#define FME_RLT_MB_get_b8x8_1_pred(data)                                             ((0x00300000&(data))>>20)
#define FME_RLT_MB_b8x8_2_pred_shift                                                 (18)
#define FME_RLT_MB_b8x8_2_pred_mask                                                  (0x000C0000)
#define FME_RLT_MB_b8x8_2_pred(data)                                                 (0x000C0000&((data)<<18))
#define FME_RLT_MB_b8x8_2_pred_src(data)                                             ((0x000C0000&(data))>>18)
#define FME_RLT_MB_get_b8x8_2_pred(data)                                             ((0x000C0000&(data))>>18)
#define FME_RLT_MB_b8x8_3_pred_shift                                                 (16)
#define FME_RLT_MB_b8x8_3_pred_mask                                                  (0x00030000)
#define FME_RLT_MB_b8x8_3_pred(data)                                                 (0x00030000&((data)<<16))
#define FME_RLT_MB_b8x8_3_pred_src(data)                                             ((0x00030000&(data))>>16)
#define FME_RLT_MB_get_b8x8_3_pred(data)                                             ((0x00030000&(data))>>16)
#define FME_RLT_MB_b8x8_0_list0_shift                                                (14)
#define FME_RLT_MB_b8x8_0_list0_mask                                                 (0x0000C000)
#define FME_RLT_MB_b8x8_0_list0(data)                                                (0x0000C000&((data)<<14))
#define FME_RLT_MB_b8x8_0_list0_src(data)                                            ((0x0000C000&(data))>>14)
#define FME_RLT_MB_get_b8x8_0_list0(data)                                            ((0x0000C000&(data))>>14)
#define FME_RLT_MB_b8x8_1_list0_shift                                                (12)
#define FME_RLT_MB_b8x8_1_list0_mask                                                 (0x00003000)
#define FME_RLT_MB_b8x8_1_list0(data)                                                (0x00003000&((data)<<12))
#define FME_RLT_MB_b8x8_1_list0_src(data)                                            ((0x00003000&(data))>>12)
#define FME_RLT_MB_get_b8x8_1_list0(data)                                            ((0x00003000&(data))>>12)
#define FME_RLT_MB_b8x8_2_list0_shift                                                (10)
#define FME_RLT_MB_b8x8_2_list0_mask                                                 (0x00000C00)
#define FME_RLT_MB_b8x8_2_list0(data)                                                (0x00000C00&((data)<<10))
#define FME_RLT_MB_b8x8_2_list0_src(data)                                            ((0x00000C00&(data))>>10)
#define FME_RLT_MB_get_b8x8_2_list0(data)                                            ((0x00000C00&(data))>>10)
#define FME_RLT_MB_b8x8_3_list0_shift                                                (8)
#define FME_RLT_MB_b8x8_3_list0_mask                                                 (0x00000300)
#define FME_RLT_MB_b8x8_3_list0(data)                                                (0x00000300&((data)<<8))
#define FME_RLT_MB_b8x8_3_list0_src(data)                                            ((0x00000300&(data))>>8)
#define FME_RLT_MB_get_b8x8_3_list0(data)                                            ((0x00000300&(data))>>8)
#define FME_RLT_MB_b8x8_0_list1_shift                                                (6)
#define FME_RLT_MB_b8x8_0_list1_mask                                                 (0x000000C0)
#define FME_RLT_MB_b8x8_0_list1(data)                                                (0x000000C0&((data)<<6))
#define FME_RLT_MB_b8x8_0_list1_src(data)                                            ((0x000000C0&(data))>>6)
#define FME_RLT_MB_get_b8x8_0_list1(data)                                            ((0x000000C0&(data))>>6)
#define FME_RLT_MB_b8x8_1_list1_shift                                                (4)
#define FME_RLT_MB_b8x8_1_list1_mask                                                 (0x00000030)
#define FME_RLT_MB_b8x8_1_list1(data)                                                (0x00000030&((data)<<4))
#define FME_RLT_MB_b8x8_1_list1_src(data)                                            ((0x00000030&(data))>>4)
#define FME_RLT_MB_get_b8x8_1_list1(data)                                            ((0x00000030&(data))>>4)
#define FME_RLT_MB_b8x8_2_list1_shift                                                (2)
#define FME_RLT_MB_b8x8_2_list1_mask                                                 (0x0000000C)
#define FME_RLT_MB_b8x8_2_list1(data)                                                (0x0000000C&((data)<<2))
#define FME_RLT_MB_b8x8_2_list1_src(data)                                            ((0x0000000C&(data))>>2)
#define FME_RLT_MB_get_b8x8_2_list1(data)                                            ((0x0000000C&(data))>>2)
#define FME_RLT_MB_b8x8_3_list1_shift                                                (0)
#define FME_RLT_MB_b8x8_3_list1_mask                                                 (0x00000003)
#define FME_RLT_MB_b8x8_3_list1(data)                                                (0x00000003&((data)<<0))
#define FME_RLT_MB_b8x8_3_list1_src(data)                                            ((0x00000003&(data))>>0)
#define FME_RLT_MB_get_b8x8_3_list1(data)                                            ((0x00000003&(data))>>0)


#define FME_RLT_FW_0                                                                 0x18036048
#define FME_RLT_FW_1                                                                 0x1803604C
#define FME_RLT_FW_2                                                                 0x18036050
#define FME_RLT_FW_3                                                                 0x18036054
#define FME_RLT_FW_0_reg_addr                                                        "0xB8036048"
#define FME_RLT_FW_1_reg_addr                                                        "0xB803604C"
#define FME_RLT_FW_2_reg_addr                                                        "0xB8036050"
#define FME_RLT_FW_3_reg_addr                                                        "0xB8036054"
#define FME_RLT_FW_0_reg                                                             0xB8036048
#define FME_RLT_FW_1_reg                                                             0xB803604C
#define FME_RLT_FW_2_reg                                                             0xB8036050
#define FME_RLT_FW_3_reg                                                             0xB8036054
#define set_FME_RLT_FW_0_reg(data)   (*((volatile unsigned int*) FME_RLT_FW_0_reg)=data)
#define set_FME_RLT_FW_1_reg(data)   (*((volatile unsigned int*) FME_RLT_FW_1_reg)=data)
#define set_FME_RLT_FW_2_reg(data)   (*((volatile unsigned int*) FME_RLT_FW_2_reg)=data)
#define set_FME_RLT_FW_3_reg(data)   (*((volatile unsigned int*) FME_RLT_FW_3_reg)=data)
#define get_FME_RLT_FW_0_reg   (*((volatile unsigned int*) FME_RLT_FW_0_reg))
#define get_FME_RLT_FW_1_reg   (*((volatile unsigned int*) FME_RLT_FW_1_reg))
#define get_FME_RLT_FW_2_reg   (*((volatile unsigned int*) FME_RLT_FW_2_reg))
#define get_FME_RLT_FW_3_reg   (*((volatile unsigned int*) FME_RLT_FW_3_reg))
#define FME_RLT_FW_0_inst_adr                                                        "0x0012"
#define FME_RLT_FW_1_inst_adr                                                        "0x0013"
#define FME_RLT_FW_2_inst_adr                                                        "0x0014"
#define FME_RLT_FW_3_inst_adr                                                        "0x0015"
#define FME_RLT_FW_0_inst                                                            0x0012
#define FME_RLT_FW_1_inst                                                            0x0013
#define FME_RLT_FW_2_inst                                                            0x0014
#define FME_RLT_FW_3_inst                                                            0x0015
#define FME_RLT_FW_mvx_shift                                                         (9)
#define FME_RLT_FW_mvx_mask                                                          (0x001FFE00)
#define FME_RLT_FW_mvx(data)                                                         (0x001FFE00&((data)<<9))
#define FME_RLT_FW_mvx_src(data)                                                     ((0x001FFE00&(data))>>9)
#define FME_RLT_FW_get_mvx(data)                                                     ((0x001FFE00&(data))>>9)
#define FME_RLT_FW_mvy_shift                                                         (0)
#define FME_RLT_FW_mvy_mask                                                          (0x000001FF)
#define FME_RLT_FW_mvy(data)                                                         (0x000001FF&((data)<<0))
#define FME_RLT_FW_mvy_src(data)                                                     ((0x000001FF&(data))>>0)
#define FME_RLT_FW_get_mvy(data)                                                     ((0x000001FF&(data))>>0)


#define FME_RLT_BW_0                                                                 0x18036058
#define FME_RLT_BW_1                                                                 0x1803605C
#define FME_RLT_BW_2                                                                 0x18036060
#define FME_RLT_BW_3                                                                 0x18036064
#define FME_RLT_BW_0_reg_addr                                                        "0xB8036058"
#define FME_RLT_BW_1_reg_addr                                                        "0xB803605C"
#define FME_RLT_BW_2_reg_addr                                                        "0xB8036060"
#define FME_RLT_BW_3_reg_addr                                                        "0xB8036064"
#define FME_RLT_BW_0_reg                                                             0xB8036058
#define FME_RLT_BW_1_reg                                                             0xB803605C
#define FME_RLT_BW_2_reg                                                             0xB8036060
#define FME_RLT_BW_3_reg                                                             0xB8036064
#define set_FME_RLT_BW_0_reg(data)   (*((volatile unsigned int*) FME_RLT_BW_0_reg)=data)
#define set_FME_RLT_BW_1_reg(data)   (*((volatile unsigned int*) FME_RLT_BW_1_reg)=data)
#define set_FME_RLT_BW_2_reg(data)   (*((volatile unsigned int*) FME_RLT_BW_2_reg)=data)
#define set_FME_RLT_BW_3_reg(data)   (*((volatile unsigned int*) FME_RLT_BW_3_reg)=data)
#define get_FME_RLT_BW_0_reg   (*((volatile unsigned int*) FME_RLT_BW_0_reg))
#define get_FME_RLT_BW_1_reg   (*((volatile unsigned int*) FME_RLT_BW_1_reg))
#define get_FME_RLT_BW_2_reg   (*((volatile unsigned int*) FME_RLT_BW_2_reg))
#define get_FME_RLT_BW_3_reg   (*((volatile unsigned int*) FME_RLT_BW_3_reg))
#define FME_RLT_BW_0_inst_adr                                                        "0x0016"
#define FME_RLT_BW_1_inst_adr                                                        "0x0017"
#define FME_RLT_BW_2_inst_adr                                                        "0x0018"
#define FME_RLT_BW_3_inst_adr                                                        "0x0019"
#define FME_RLT_BW_0_inst                                                            0x0016
#define FME_RLT_BW_1_inst                                                            0x0017
#define FME_RLT_BW_2_inst                                                            0x0018
#define FME_RLT_BW_3_inst                                                            0x0019
#define FME_RLT_BW_mvx_shift                                                         (9)
#define FME_RLT_BW_mvx_mask                                                          (0x001FFE00)
#define FME_RLT_BW_mvx(data)                                                         (0x001FFE00&((data)<<9))
#define FME_RLT_BW_mvx_src(data)                                                     ((0x001FFE00&(data))>>9)
#define FME_RLT_BW_get_mvx(data)                                                     ((0x001FFE00&(data))>>9)
#define FME_RLT_BW_mvy_shift                                                         (0)
#define FME_RLT_BW_mvy_mask                                                          (0x000001FF)
#define FME_RLT_BW_mvy(data)                                                         (0x000001FF&((data)<<0))
#define FME_RLT_BW_mvy_src(data)                                                     ((0x000001FF&(data))>>0)
#define FME_RLT_BW_get_mvy(data)                                                     ((0x000001FF&(data))>>0)


#define FME_RLT_16X16FW                                                              0x18036068
#define FME_RLT_16X16FW_reg_addr                                                     "0xB8036068"
#define FME_RLT_16X16FW_reg                                                          0xB8036068
#define set_FME_RLT_16X16FW_reg(data)   (*((volatile unsigned int*) FME_RLT_16X16FW_reg)=data)
#define get_FME_RLT_16X16FW_reg   (*((volatile unsigned int*) FME_RLT_16X16FW_reg))
#define FME_RLT_16X16FW_inst_adr                                                     "0x001A"
#define FME_RLT_16X16FW_inst                                                         0x001A
#define FME_RLT_16X16FW_pred_shift                                                   (21)
#define FME_RLT_16X16FW_pred_mask                                                    (0x00600000)
#define FME_RLT_16X16FW_pred(data)                                                   (0x00600000&((data)<<21))
#define FME_RLT_16X16FW_pred_src(data)                                               ((0x00600000&(data))>>21)
#define FME_RLT_16X16FW_get_pred(data)                                               ((0x00600000&(data))>>21)
#define FME_RLT_16X16FW_mvx_shift                                                    (9)
#define FME_RLT_16X16FW_mvx_mask                                                     (0x001FFE00)
#define FME_RLT_16X16FW_mvx(data)                                                    (0x001FFE00&((data)<<9))
#define FME_RLT_16X16FW_mvx_src(data)                                                ((0x001FFE00&(data))>>9)
#define FME_RLT_16X16FW_get_mvx(data)                                                ((0x001FFE00&(data))>>9)
#define FME_RLT_16X16FW_mvy_shift                                                    (0)
#define FME_RLT_16X16FW_mvy_mask                                                     (0x000001FF)
#define FME_RLT_16X16FW_mvy(data)                                                    (0x000001FF&((data)<<0))
#define FME_RLT_16X16FW_mvy_src(data)                                                ((0x000001FF&(data))>>0)
#define FME_RLT_16X16FW_get_mvy(data)                                                ((0x000001FF&(data))>>0)


#define FME_RLT_16X16BW                                                              0x1803606c
#define FME_RLT_16X16BW_reg_addr                                                     "0xB803606C"
#define FME_RLT_16X16BW_reg                                                          0xB803606C
#define set_FME_RLT_16X16BW_reg(data)   (*((volatile unsigned int*) FME_RLT_16X16BW_reg)=data)
#define get_FME_RLT_16X16BW_reg   (*((volatile unsigned int*) FME_RLT_16X16BW_reg))
#define FME_RLT_16X16BW_inst_adr                                                     "0x001B"
#define FME_RLT_16X16BW_inst                                                         0x001B
#define FME_RLT_16X16BW_mvx_shift                                                    (9)
#define FME_RLT_16X16BW_mvx_mask                                                     (0x001FFE00)
#define FME_RLT_16X16BW_mvx(data)                                                    (0x001FFE00&((data)<<9))
#define FME_RLT_16X16BW_mvx_src(data)                                                ((0x001FFE00&(data))>>9)
#define FME_RLT_16X16BW_get_mvx(data)                                                ((0x001FFE00&(data))>>9)
#define FME_RLT_16X16BW_mvy_shift                                                    (0)
#define FME_RLT_16X16BW_mvy_mask                                                     (0x000001FF)
#define FME_RLT_16X16BW_mvy(data)                                                    (0x000001FF&((data)<<0))
#define FME_RLT_16X16BW_mvy_src(data)                                                ((0x000001FF&(data))>>0)
#define FME_RLT_16X16BW_get_mvy(data)                                                ((0x000001FF&(data))>>0)


#define FME_RLT_COL                                                                  0x18036070
#define FME_RLT_COL_reg_addr                                                         "0xB8036070"
#define FME_RLT_COL_reg                                                              0xB8036070
#define set_FME_RLT_COL_reg(data)   (*((volatile unsigned int*) FME_RLT_COL_reg)=data)
#define get_FME_RLT_COL_reg   (*((volatile unsigned int*) FME_RLT_COL_reg))
#define FME_RLT_COL_inst_adr                                                         "0x001C"
#define FME_RLT_COL_inst                                                             0x001C
#define FME_RLT_COL_zero_shift                                                       (0)
#define FME_RLT_COL_zero_mask                                                        (0x0000000F)
#define FME_RLT_COL_zero(data)                                                       (0x0000000F&((data)<<0))
#define FME_RLT_COL_zero_src(data)                                                   ((0x0000000F&(data))>>0)
#define FME_RLT_COL_get_zero(data)                                                   ((0x0000000F&(data))>>0)


#define FME_RLT_16X16                                                                0x18036074
#define FME_RLT_16X16_reg_addr                                                       "0xB8036074"
#define FME_RLT_16X16_reg                                                            0xB8036074
#define set_FME_RLT_16X16_reg(data)   (*((volatile unsigned int*) FME_RLT_16X16_reg)=data)
#define get_FME_RLT_16X16_reg   (*((volatile unsigned int*) FME_RLT_16X16_reg))
#define FME_RLT_16X16_inst_adr                                                       "0x001D"
#define FME_RLT_16X16_inst                                                           0x001D
#define FME_RLT_16X16_cost_shift                                                     (0)
#define FME_RLT_16X16_cost_mask                                                      (0x0003FFFF)
#define FME_RLT_16X16_cost(data)                                                     (0x0003FFFF&((data)<<0))
#define FME_RLT_16X16_cost_src(data)                                                 ((0x0003FFFF&(data))>>0)
#define FME_RLT_16X16_get_cost(data)                                                 ((0x0003FFFF&(data))>>0)


#define FME_RLT_16X16DIRECT                                                          0x18036078
#define FME_RLT_16X16DIRECT_reg_addr                                                 "0xB8036078"
#define FME_RLT_16X16DIRECT_reg                                                      0xB8036078
#define set_FME_RLT_16X16DIRECT_reg(data)   (*((volatile unsigned int*) FME_RLT_16X16DIRECT_reg)=data)
#define get_FME_RLT_16X16DIRECT_reg   (*((volatile unsigned int*) FME_RLT_16X16DIRECT_reg))
#define FME_RLT_16X16DIRECT_inst_adr                                                 "0x001E"
#define FME_RLT_16X16DIRECT_inst                                                     0x001E
#define FME_RLT_16X16DIRECT_cost_shift                                               (0)
#define FME_RLT_16X16DIRECT_cost_mask                                                (0x0003FFFF)
#define FME_RLT_16X16DIRECT_cost(data)                                               (0x0003FFFF&((data)<<0))
#define FME_RLT_16X16DIRECT_cost_src(data)                                           ((0x0003FFFF&(data))>>0)
#define FME_RLT_16X16DIRECT_get_cost(data)                                           ((0x0003FFFF&(data))>>0)


#define FME_RLT_8X8                                                                  0x1803607c
#define FME_RLT_8X8_reg_addr                                                         "0xB803607C"
#define FME_RLT_8X8_reg                                                              0xB803607C
#define set_FME_RLT_8X8_reg(data)   (*((volatile unsigned int*) FME_RLT_8X8_reg)=data)
#define get_FME_RLT_8X8_reg   (*((volatile unsigned int*) FME_RLT_8X8_reg))
#define FME_RLT_8X8_inst_adr                                                         "0x001F"
#define FME_RLT_8X8_inst                                                             0x001F
#define FME_RLT_8X8_cost_shift                                                       (0)
#define FME_RLT_8X8_cost_mask                                                        (0x0003FFFF)
#define FME_RLT_8X8_cost(data)                                                       (0x0003FFFF&((data)<<0))
#define FME_RLT_8X8_cost_src(data)                                                   ((0x0003FFFF&(data))>>0)
#define FME_RLT_8X8_get_cost(data)                                                   ((0x0003FFFF&(data))>>0)


#define FME_RLT_SKIP                                                                 0x18036080
#define FME_RLT_SKIP_reg_addr                                                        "0xB8036080"
#define FME_RLT_SKIP_reg                                                             0xB8036080
#define set_FME_RLT_SKIP_reg(data)   (*((volatile unsigned int*) FME_RLT_SKIP_reg)=data)
#define get_FME_RLT_SKIP_reg   (*((volatile unsigned int*) FME_RLT_SKIP_reg))
#define FME_RLT_SKIP_inst_adr                                                        "0x0020"
#define FME_RLT_SKIP_inst                                                            0x0020
#define FME_RLT_SKIP_skipable_shift                                                  (18)
#define FME_RLT_SKIP_skipable_mask                                                   (0x00040000)
#define FME_RLT_SKIP_skipable(data)                                                  (0x00040000&((data)<<18))
#define FME_RLT_SKIP_skipable_src(data)                                              ((0x00040000&(data))>>18)
#define FME_RLT_SKIP_get_skipable(data)                                              ((0x00040000&(data))>>18)
#define FME_RLT_SKIP_cost_shift                                                      (0)
#define FME_RLT_SKIP_cost_mask                                                       (0x0003FFFF)
#define FME_RLT_SKIP_cost(data)                                                      (0x0003FFFF&((data)<<0))
#define FME_RLT_SKIP_cost_src(data)                                                  ((0x0003FFFF&(data))>>0)
#define FME_RLT_SKIP_get_cost(data)                                                  ((0x0003FFFF&(data))>>0)


#define FME_DEBUG0                                                                   0x18036084
#define FME_DEBUG0_reg_addr                                                          "0xB8036084"
#define FME_DEBUG0_reg                                                               0xB8036084
#define set_FME_DEBUG0_reg(data)   (*((volatile unsigned int*) FME_DEBUG0_reg)=data)
#define get_FME_DEBUG0_reg   (*((volatile unsigned int*) FME_DEBUG0_reg))
#define FME_DEBUG0_inst_adr                                                          "0x0021"
#define FME_DEBUG0_inst                                                              0x0021
#define FME_DEBUG0_status_shift                                                      (0)
#define FME_DEBUG0_status_mask                                                       (0xFFFFFFFF)
#define FME_DEBUG0_status(data)                                                      (0xFFFFFFFF&((data)<<0))
#define FME_DEBUG0_status_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define FME_DEBUG0_get_status(data)                                                  ((0xFFFFFFFF&(data))>>0)


#define FME_DEBUG1                                                                   0x18036088
#define FME_DEBUG1_reg_addr                                                          "0xB8036088"
#define FME_DEBUG1_reg                                                               0xB8036088
#define set_FME_DEBUG1_reg(data)   (*((volatile unsigned int*) FME_DEBUG1_reg)=data)
#define get_FME_DEBUG1_reg   (*((volatile unsigned int*) FME_DEBUG1_reg))
#define FME_DEBUG1_inst_adr                                                          "0x0022"
#define FME_DEBUG1_inst                                                              0x0022
#define FME_DEBUG1_status_shift                                                      (0)
#define FME_DEBUG1_status_mask                                                       (0xFFFFFFFF)
#define FME_DEBUG1_status(data)                                                      (0xFFFFFFFF&((data)<<0))
#define FME_DEBUG1_status_src(data)                                                  ((0xFFFFFFFF&(data))>>0)
#define FME_DEBUG1_get_status(data)                                                  ((0xFFFFFFFF&(data))>>0)


#endif
