// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:764                    Version flow no.:1.0.244
#ifndef _RPTG_REG_H_INCLUDED_
#define _RPTG_REG_H_INCLUDED_

//#define  _RPTG_USE_STRUCT
#ifdef _RPTG_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:10;
    unsigned int    full:1;
    unsigned int    empty:1;
    unsigned int    reserved_1:1;
    unsigned int    ovflow:1;
    unsigned int    entde:1;
    unsigned int    irq_en:1;
    unsigned int    reserved_2:10;
    unsigned int    vs_polarity:1;
    unsigned int    hs_polarity:1;
    unsigned int    reserved_3:3;
    unsigned int    rptg_en:1;
}RPTG_cr;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    vs_width:12;
    unsigned int    reserved_1:4;
    unsigned int    hs_width:12;
}RPTG_tg0;

typedef struct
{
    unsigned int    vs_vstr:8;
    unsigned int    vs_hstr:12;
    unsigned int    hs_hstr:12;
}RPTG_tg1;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    de_hbph:12;
    unsigned int    reserved_1:4;
    unsigned int    de_hfph:12;
}RPTG_tg2;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    de_vbph:12;
    unsigned int    reserved_1:4;
    unsigned int    de_vfph:12;
}RPTG_tg3;

typedef struct
{
    unsigned int    reserved_0:4;
    unsigned int    de_height:12;
    unsigned int    reserved_1:4;
    unsigned int    de_width:12;
}RPTG_tg4;

typedef struct
{
    unsigned int    pixel_wr_en:1;
    unsigned int    reserved_0:7;
    unsigned int    pixel_in:24;
}RPTG_pixelbuf;
#endif


#define RPTG_CR                                                       0x18005000
#define RPTG_CR_reg_addr                                              "0xb8005000"
#define RPTG_CR_reg                                                   0xb8005000
#define RPTG_CR_inst_addr                                             "0x0000"
#define RPTG_CR_inst                                                  0x0000
#define RPTG_CR_full_shift                                            (21)
#define RPTG_CR_empty_shift                                           (20)
#define RPTG_CR_ovflow_shift                                          (18)
#define RPTG_CR_entde_shift                                           (17)
#define RPTG_CR_irq_en_shift                                          (16)
#define RPTG_CR_vs_polarity_shift                                     (5)
#define RPTG_CR_hs_polarity_shift                                     (4)
#define RPTG_CR_rptg_en_shift                                         (0)
#define RPTG_CR_full_mask                                             (0x00200000)
#define RPTG_CR_empty_mask                                            (0x00100000)
#define RPTG_CR_ovflow_mask                                           (0x00040000)
#define RPTG_CR_entde_mask                                            (0x00020000)
#define RPTG_CR_irq_en_mask                                           (0x00010000)
#define RPTG_CR_vs_polarity_mask                                      (0x00000020)
#define RPTG_CR_hs_polarity_mask                                      (0x00000010)
#define RPTG_CR_rptg_en_mask                                          (0x00000001)
#define RPTG_CR_full(data)                                            (0x00200000&((data)<<21))
#define RPTG_CR_empty(data)                                           (0x00100000&((data)<<20))
#define RPTG_CR_ovflow(data)                                          (0x00040000&((data)<<18))
#define RPTG_CR_entde(data)                                           (0x00020000&((data)<<17))
#define RPTG_CR_irq_en(data)                                          (0x00010000&((data)<<16))
#define RPTG_CR_vs_polarity(data)                                     (0x00000020&((data)<<5))
#define RPTG_CR_hs_polarity(data)                                     (0x00000010&((data)<<4))
#define RPTG_CR_rptg_en(data)                                         (0x00000001&(data))
#define RPTG_CR_get_full(data)                                        ((0x00200000&(data))>>21)
#define RPTG_CR_get_empty(data)                                       ((0x00100000&(data))>>20)
#define RPTG_CR_get_ovflow(data)                                      ((0x00040000&(data))>>18)
#define RPTG_CR_get_entde(data)                                       ((0x00020000&(data))>>17)
#define RPTG_CR_get_irq_en(data)                                      ((0x00010000&(data))>>16)
#define RPTG_CR_get_vs_polarity(data)                                 ((0x00000020&(data))>>5)
#define RPTG_CR_get_hs_polarity(data)                                 ((0x00000010&(data))>>4)
#define RPTG_CR_get_rptg_en(data)                                     (0x00000001&(data))


#define RPTG_TG0                                                      0x18005010
#define RPTG_TG0_reg_addr                                             "0xb8005010"
#define RPTG_TG0_reg                                                  0xb8005010
#define RPTG_TG0_inst_addr                                            "0x0004"
#define RPTG_TG0_inst                                                 0x0004
#define RPTG_TG0_vs_width_shift                                       (16)
#define RPTG_TG0_hs_width_shift                                       (0)
#define RPTG_TG0_vs_width_mask                                        (0x0FFF0000)
#define RPTG_TG0_hs_width_mask                                        (0x00000FFF)
#define RPTG_TG0_vs_width(data)                                       (0x0FFF0000&((data)<<16))
#define RPTG_TG0_hs_width(data)                                       (0x00000FFF&(data))
#define RPTG_TG0_get_vs_width(data)                                   ((0x0FFF0000&(data))>>16)
#define RPTG_TG0_get_hs_width(data)                                   (0x00000FFF&(data))


#define RPTG_TG1                                                      0x18005014
#define RPTG_TG1_reg_addr                                             "0xb8005014"
#define RPTG_TG1_reg                                                  0xb8005014
#define RPTG_TG1_inst_addr                                            "0x0005"
#define RPTG_TG1_inst                                                 0x0005
#define RPTG_TG1_vs_vstr_shift                                        (24)
#define RPTG_TG1_vs_hstr_shift                                        (12)
#define RPTG_TG1_hs_hstr_shift                                        (0)
#define RPTG_TG1_vs_vstr_mask                                         (0xFF000000)
#define RPTG_TG1_vs_hstr_mask                                         (0x00FFF000)
#define RPTG_TG1_hs_hstr_mask                                         (0x00000FFF)
#define RPTG_TG1_vs_vstr(data)                                        (0xFF000000&((data)<<24))
#define RPTG_TG1_vs_hstr(data)                                        (0x00FFF000&((data)<<12))
#define RPTG_TG1_hs_hstr(data)                                        (0x00000FFF&(data))
#define RPTG_TG1_get_vs_vstr(data)                                    ((0xFF000000&(data))>>24)
#define RPTG_TG1_get_vs_hstr(data)                                    ((0x00FFF000&(data))>>12)
#define RPTG_TG1_get_hs_hstr(data)                                    (0x00000FFF&(data))


#define RPTG_TG2                                                      0x18005018
#define RPTG_TG2_reg_addr                                             "0xb8005018"
#define RPTG_TG2_reg                                                  0xb8005018
#define RPTG_TG2_inst_addr                                            "0x0006"
#define RPTG_TG2_inst                                                 0x0006
#define RPTG_TG2_de_hbph_shift                                        (16)
#define RPTG_TG2_de_hfph_shift                                        (0)
#define RPTG_TG2_de_hbph_mask                                         (0x0FFF0000)
#define RPTG_TG2_de_hfph_mask                                         (0x00000FFF)
#define RPTG_TG2_de_hbph(data)                                        (0x0FFF0000&((data)<<16))
#define RPTG_TG2_de_hfph(data)                                        (0x00000FFF&(data))
#define RPTG_TG2_get_de_hbph(data)                                    ((0x0FFF0000&(data))>>16)
#define RPTG_TG2_get_de_hfph(data)                                    (0x00000FFF&(data))


#define RPTG_TG3                                                      0x1800501c
#define RPTG_TG3_reg_addr                                             "0xb800501c"
#define RPTG_TG3_reg                                                  0xb800501c
#define RPTG_TG3_inst_addr                                            "0x0007"
#define RPTG_TG3_inst                                                 0x0007
#define RPTG_TG3_de_vbph_shift                                        (16)
#define RPTG_TG3_de_vfph_shift                                        (0)
#define RPTG_TG3_de_vbph_mask                                         (0x0FFF0000)
#define RPTG_TG3_de_vfph_mask                                         (0x00000FFF)
#define RPTG_TG3_de_vbph(data)                                        (0x0FFF0000&((data)<<16))
#define RPTG_TG3_de_vfph(data)                                        (0x00000FFF&(data))
#define RPTG_TG3_get_de_vbph(data)                                    ((0x0FFF0000&(data))>>16)
#define RPTG_TG3_get_de_vfph(data)                                    (0x00000FFF&(data))


#define RPTG_TG4                                                      0x18005020
#define RPTG_TG4_reg_addr                                             "0xb8005020"
#define RPTG_TG4_reg                                                  0xb8005020
#define RPTG_TG4_inst_addr                                            "0x0008"
#define RPTG_TG4_inst                                                 0x0008
#define RPTG_TG4_de_height_shift                                      (16)
#define RPTG_TG4_de_width_shift                                       (0)
#define RPTG_TG4_de_height_mask                                       (0x0FFF0000)
#define RPTG_TG4_de_width_mask                                        (0x00000FFF)
#define RPTG_TG4_de_height(data)                                      (0x0FFF0000&((data)<<16))
#define RPTG_TG4_de_width(data)                                       (0x00000FFF&(data))
#define RPTG_TG4_get_de_height(data)                                  ((0x0FFF0000&(data))>>16)
#define RPTG_TG4_get_de_width(data)                                   (0x00000FFF&(data))


#define RPTG_PIXELBUF                                                 0x18005030
#define RPTG_PIXELBUF_reg_addr                                        "0xb8005030"
#define RPTG_PIXELBUF_reg                                             0xb8005030
#define RPTG_PIXELBUF_inst_addr                                       "0x000C"
#define RPTG_PIXELBUF_inst                                            0x000C
#define RPTG_PIXELBUF_pixel_wr_en_shift                               (31)
#define RPTG_PIXELBUF_pixel_in_shift                                  (0)
#define RPTG_PIXELBUF_pixel_wr_en_mask                                (0x80000000)
#define RPTG_PIXELBUF_pixel_in_mask                                   (0x00FFFFFF)
#define RPTG_PIXELBUF_pixel_wr_en(data)                               (0x80000000&((data)<<31))
#define RPTG_PIXELBUF_pixel_in(data)                                  (0x00FFFFFF&(data))
#define RPTG_PIXELBUF_get_pixel_wr_en(data)                           ((0x80000000&(data))>>31)
#define RPTG_PIXELBUF_get_pixel_in(data)                              (0x00FFFFFF&(data))
#endif
