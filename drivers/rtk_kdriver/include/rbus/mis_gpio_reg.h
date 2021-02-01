/**
* @file Macarthur5-DesignSpec-MISC_GPIO
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MIS_GPIO_REG_H_
#define _RBUS_MIS_GPIO_REG_H_

#include "rbus_types.h"



//  MIS_GPIO Register Address
#define  MIS_GPIO_GP0DIR                                                         0x1801BD00
#define  MIS_GPIO_GP0DIR_reg_addr                                                "0xB801BD00"
#define  MIS_GPIO_GP0DIR_reg                                                     0xB801BD00
#define  MIS_GPIO_GP0DIR_inst_addr                                               "0x0000"
#define  set_MIS_GPIO_GP0DIR_reg(data)                                           (*((volatile unsigned int*)MIS_GPIO_GP0DIR_reg)=data)
#define  get_MIS_GPIO_GP0DIR_reg                                                 (*((volatile unsigned int*)MIS_GPIO_GP0DIR_reg))
#define  MIS_GPIO_GP0DIR_gpdir_shift                                             (0)
#define  MIS_GPIO_GP0DIR_gpdir_mask                                              (0xFFFFFFFF)
#define  MIS_GPIO_GP0DIR_gpdir(data)                                             (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP0DIR_get_gpdir(data)                                         (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP1DIR                                                         0x1801BD04
#define  MIS_GPIO_GP1DIR_reg_addr                                                "0xB801BD04"
#define  MIS_GPIO_GP1DIR_reg                                                     0xB801BD04
#define  MIS_GPIO_GP1DIR_inst_addr                                               "0x0001"
#define  set_MIS_GPIO_GP1DIR_reg(data)                                           (*((volatile unsigned int*)MIS_GPIO_GP1DIR_reg)=data)
#define  get_MIS_GPIO_GP1DIR_reg                                                 (*((volatile unsigned int*)MIS_GPIO_GP1DIR_reg))
#define  MIS_GPIO_GP1DIR_gpdir_shift                                             (0)
#define  MIS_GPIO_GP1DIR_gpdir_mask                                              (0xFFFFFFFF)
#define  MIS_GPIO_GP1DIR_gpdir(data)                                             (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP1DIR_get_gpdir(data)                                         (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP2DIR                                                         0x1801BD08
#define  MIS_GPIO_GP2DIR_reg_addr                                                "0xB801BD08"
#define  MIS_GPIO_GP2DIR_reg                                                     0xB801BD08
#define  MIS_GPIO_GP2DIR_inst_addr                                               "0x0002"
#define  set_MIS_GPIO_GP2DIR_reg(data)                                           (*((volatile unsigned int*)MIS_GPIO_GP2DIR_reg)=data)
#define  get_MIS_GPIO_GP2DIR_reg                                                 (*((volatile unsigned int*)MIS_GPIO_GP2DIR_reg))
#define  MIS_GPIO_GP2DIR_gpdir_shift                                             (0)
#define  MIS_GPIO_GP2DIR_gpdir_mask                                              (0xFFFFFFFF)
#define  MIS_GPIO_GP2DIR_gpdir(data)                                             (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP2DIR_get_gpdir(data)                                         (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP3DIR                                                         0x1801BD0C
#define  MIS_GPIO_GP3DIR_reg_addr                                                "0xB801BD0C"
#define  MIS_GPIO_GP3DIR_reg                                                     0xB801BD0C
#define  MIS_GPIO_GP3DIR_inst_addr                                               "0x0003"
#define  set_MIS_GPIO_GP3DIR_reg(data)                                           (*((volatile unsigned int*)MIS_GPIO_GP3DIR_reg)=data)
#define  get_MIS_GPIO_GP3DIR_reg                                                 (*((volatile unsigned int*)MIS_GPIO_GP3DIR_reg))
#define  MIS_GPIO_GP3DIR_gpdir_shift                                             (0)
#define  MIS_GPIO_GP3DIR_gpdir_mask                                              (0xFFFFFFFF)
#define  MIS_GPIO_GP3DIR_gpdir(data)                                             (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP3DIR_get_gpdir(data)                                         (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP4DIR                                                         0x1801BD10
#define  MIS_GPIO_GP4DIR_reg_addr                                                "0xB801BD10"
#define  MIS_GPIO_GP4DIR_reg                                                     0xB801BD10
#define  MIS_GPIO_GP4DIR_inst_addr                                               "0x0004"
#define  set_MIS_GPIO_GP4DIR_reg(data)                                           (*((volatile unsigned int*)MIS_GPIO_GP4DIR_reg)=data)
#define  get_MIS_GPIO_GP4DIR_reg                                                 (*((volatile unsigned int*)MIS_GPIO_GP4DIR_reg))
#define  MIS_GPIO_GP4DIR_gpdir_shift                                             (0)
#define  MIS_GPIO_GP4DIR_gpdir_mask                                              (0xFFFFFFFF)
#define  MIS_GPIO_GP4DIR_gpdir(data)                                             (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP4DIR_get_gpdir(data)                                         (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP5DIR                                                         0x1801BD14
#define  MIS_GPIO_GP5DIR_reg_addr                                                "0xB801BD14"
#define  MIS_GPIO_GP5DIR_reg                                                     0xB801BD14
#define  MIS_GPIO_GP5DIR_inst_addr                                               "0x0005"
#define  set_MIS_GPIO_GP5DIR_reg(data)                                           (*((volatile unsigned int*)MIS_GPIO_GP5DIR_reg)=data)
#define  get_MIS_GPIO_GP5DIR_reg                                                 (*((volatile unsigned int*)MIS_GPIO_GP5DIR_reg))
#define  MIS_GPIO_GP5DIR_gpdir_shift                                             (0)
#define  MIS_GPIO_GP5DIR_gpdir_mask                                              (0x7FFFFFFF)
#define  MIS_GPIO_GP5DIR_gpdir(data)                                             (0x7FFFFFFF&(data))
#define  MIS_GPIO_GP5DIR_get_gpdir(data)                                         (0x7FFFFFFF&(data))

#define  MIS_GPIO_GP0DATO                                                        0x1801BD18
#define  MIS_GPIO_GP0DATO_reg_addr                                               "0xB801BD18"
#define  MIS_GPIO_GP0DATO_reg                                                    0xB801BD18
#define  MIS_GPIO_GP0DATO_inst_addr                                              "0x0006"
#define  set_MIS_GPIO_GP0DATO_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP0DATO_reg)=data)
#define  get_MIS_GPIO_GP0DATO_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP0DATO_reg))
#define  MIS_GPIO_GP0DATO_gpdato_shift                                           (0)
#define  MIS_GPIO_GP0DATO_gpdato_mask                                            (0xFFFFFFFF)
#define  MIS_GPIO_GP0DATO_gpdato(data)                                           (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP0DATO_get_gpdato(data)                                       (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP1DATO                                                        0x1801BD1C
#define  MIS_GPIO_GP1DATO_reg_addr                                               "0xB801BD1C"
#define  MIS_GPIO_GP1DATO_reg                                                    0xB801BD1C
#define  MIS_GPIO_GP1DATO_inst_addr                                              "0x0007"
#define  set_MIS_GPIO_GP1DATO_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP1DATO_reg)=data)
#define  get_MIS_GPIO_GP1DATO_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP1DATO_reg))
#define  MIS_GPIO_GP1DATO_gpdato_shift                                           (0)
#define  MIS_GPIO_GP1DATO_gpdato_mask                                            (0xFFFFFFFF)
#define  MIS_GPIO_GP1DATO_gpdato(data)                                           (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP1DATO_get_gpdato(data)                                       (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP2DATO                                                        0x1801BD20
#define  MIS_GPIO_GP2DATO_reg_addr                                               "0xB801BD20"
#define  MIS_GPIO_GP2DATO_reg                                                    0xB801BD20
#define  MIS_GPIO_GP2DATO_inst_addr                                              "0x0008"
#define  set_MIS_GPIO_GP2DATO_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP2DATO_reg)=data)
#define  get_MIS_GPIO_GP2DATO_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP2DATO_reg))
#define  MIS_GPIO_GP2DATO_gpdato_shift                                           (0)
#define  MIS_GPIO_GP2DATO_gpdato_mask                                            (0xFFFFFFFF)
#define  MIS_GPIO_GP2DATO_gpdato(data)                                           (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP2DATO_get_gpdato(data)                                       (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP3DATO                                                        0x1801BD24
#define  MIS_GPIO_GP3DATO_reg_addr                                               "0xB801BD24"
#define  MIS_GPIO_GP3DATO_reg                                                    0xB801BD24
#define  MIS_GPIO_GP3DATO_inst_addr                                              "0x0009"
#define  set_MIS_GPIO_GP3DATO_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP3DATO_reg)=data)
#define  get_MIS_GPIO_GP3DATO_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP3DATO_reg))
#define  MIS_GPIO_GP3DATO_gpdato_shift                                           (0)
#define  MIS_GPIO_GP3DATO_gpdato_mask                                            (0xFFFFFFFF)
#define  MIS_GPIO_GP3DATO_gpdato(data)                                           (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP3DATO_get_gpdato(data)                                       (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP4DATO                                                        0x1801BD28
#define  MIS_GPIO_GP4DATO_reg_addr                                               "0xB801BD28"
#define  MIS_GPIO_GP4DATO_reg                                                    0xB801BD28
#define  MIS_GPIO_GP4DATO_inst_addr                                              "0x000A"
#define  set_MIS_GPIO_GP4DATO_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP4DATO_reg)=data)
#define  get_MIS_GPIO_GP4DATO_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP4DATO_reg))
#define  MIS_GPIO_GP4DATO_gpdato_shift                                           (0)
#define  MIS_GPIO_GP4DATO_gpdato_mask                                            (0xFFFFFFFF)
#define  MIS_GPIO_GP4DATO_gpdato(data)                                           (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP4DATO_get_gpdato(data)                                       (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP5DATO                                                        0x1801BD2C
#define  MIS_GPIO_GP5DATO_reg_addr                                               "0xB801BD2C"
#define  MIS_GPIO_GP5DATO_reg                                                    0xB801BD2C
#define  MIS_GPIO_GP5DATO_inst_addr                                              "0x000B"
#define  set_MIS_GPIO_GP5DATO_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP5DATO_reg)=data)
#define  get_MIS_GPIO_GP5DATO_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP5DATO_reg))
#define  MIS_GPIO_GP5DATO_gpdato_shift                                           (0)
#define  MIS_GPIO_GP5DATO_gpdato_mask                                            (0x7FFFFFFF)
#define  MIS_GPIO_GP5DATO_gpdato(data)                                           (0x7FFFFFFF&(data))
#define  MIS_GPIO_GP5DATO_get_gpdato(data)                                       (0x7FFFFFFF&(data))

#define  MIS_GPIO_GP0DATI                                                        0x1801BD30
#define  MIS_GPIO_GP0DATI_reg_addr                                               "0xB801BD30"
#define  MIS_GPIO_GP0DATI_reg                                                    0xB801BD30
#define  MIS_GPIO_GP0DATI_inst_addr                                              "0x000C"
#define  set_MIS_GPIO_GP0DATI_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP0DATI_reg)=data)
#define  get_MIS_GPIO_GP0DATI_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP0DATI_reg))
#define  MIS_GPIO_GP0DATI_gpdati_shift                                           (0)
#define  MIS_GPIO_GP0DATI_gpdati_mask                                            (0xFFFFFFFF)
#define  MIS_GPIO_GP0DATI_gpdati(data)                                           (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP0DATI_get_gpdati(data)                                       (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP1DATI                                                        0x1801BD34
#define  MIS_GPIO_GP1DATI_reg_addr                                               "0xB801BD34"
#define  MIS_GPIO_GP1DATI_reg                                                    0xB801BD34
#define  MIS_GPIO_GP1DATI_inst_addr                                              "0x000D"
#define  set_MIS_GPIO_GP1DATI_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP1DATI_reg)=data)
#define  get_MIS_GPIO_GP1DATI_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP1DATI_reg))
#define  MIS_GPIO_GP1DATI_gpdati_shift                                           (0)
#define  MIS_GPIO_GP1DATI_gpdati_mask                                            (0xFFFFFFFF)
#define  MIS_GPIO_GP1DATI_gpdati(data)                                           (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP1DATI_get_gpdati(data)                                       (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP2DATI                                                        0x1801BD38
#define  MIS_GPIO_GP2DATI_reg_addr                                               "0xB801BD38"
#define  MIS_GPIO_GP2DATI_reg                                                    0xB801BD38
#define  MIS_GPIO_GP2DATI_inst_addr                                              "0x000E"
#define  set_MIS_GPIO_GP2DATI_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP2DATI_reg)=data)
#define  get_MIS_GPIO_GP2DATI_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP2DATI_reg))
#define  MIS_GPIO_GP2DATI_gpdati_shift                                           (0)
#define  MIS_GPIO_GP2DATI_gpdati_mask                                            (0xFFFFFFFF)
#define  MIS_GPIO_GP2DATI_gpdati(data)                                           (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP2DATI_get_gpdati(data)                                       (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP3DATI                                                        0x1801BD3C
#define  MIS_GPIO_GP3DATI_reg_addr                                               "0xB801BD3C"
#define  MIS_GPIO_GP3DATI_reg                                                    0xB801BD3C
#define  MIS_GPIO_GP3DATI_inst_addr                                              "0x000F"
#define  set_MIS_GPIO_GP3DATI_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP3DATI_reg)=data)
#define  get_MIS_GPIO_GP3DATI_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP3DATI_reg))
#define  MIS_GPIO_GP3DATI_gpdati_shift                                           (0)
#define  MIS_GPIO_GP3DATI_gpdati_mask                                            (0xFFFFFFFF)
#define  MIS_GPIO_GP3DATI_gpdati(data)                                           (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP3DATI_get_gpdati(data)                                       (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP4DATI                                                        0x1801BD40
#define  MIS_GPIO_GP4DATI_reg_addr                                               "0xB801BD40"
#define  MIS_GPIO_GP4DATI_reg                                                    0xB801BD40
#define  MIS_GPIO_GP4DATI_inst_addr                                              "0x0010"
#define  set_MIS_GPIO_GP4DATI_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP4DATI_reg)=data)
#define  get_MIS_GPIO_GP4DATI_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP4DATI_reg))
#define  MIS_GPIO_GP4DATI_gpdati_shift                                           (0)
#define  MIS_GPIO_GP4DATI_gpdati_mask                                            (0xFFFFFFFF)
#define  MIS_GPIO_GP4DATI_gpdati(data)                                           (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP4DATI_get_gpdati(data)                                       (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP5DATI                                                        0x1801BD44
#define  MIS_GPIO_GP5DATI_reg_addr                                               "0xB801BD44"
#define  MIS_GPIO_GP5DATI_reg                                                    0xB801BD44
#define  MIS_GPIO_GP5DATI_inst_addr                                              "0x0011"
#define  set_MIS_GPIO_GP5DATI_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GP5DATI_reg)=data)
#define  get_MIS_GPIO_GP5DATI_reg                                                (*((volatile unsigned int*)MIS_GPIO_GP5DATI_reg))
#define  MIS_GPIO_GP5DATI_gpdati_shift                                           (0)
#define  MIS_GPIO_GP5DATI_gpdati_mask                                            (0x7FFFFFFF)
#define  MIS_GPIO_GP5DATI_gpdati(data)                                           (0x7FFFFFFF&(data))
#define  MIS_GPIO_GP5DATI_get_gpdati(data)                                       (0x7FFFFFFF&(data))

#define  MIS_GPIO_GP0IE                                                          0x1801BD48
#define  MIS_GPIO_GP0IE_reg_addr                                                 "0xB801BD48"
#define  MIS_GPIO_GP0IE_reg                                                      0xB801BD48
#define  MIS_GPIO_GP0IE_inst_addr                                                "0x0012"
#define  set_MIS_GPIO_GP0IE_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP0IE_reg)=data)
#define  get_MIS_GPIO_GP0IE_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP0IE_reg))
#define  MIS_GPIO_GP0IE_gp_shift                                                 (0)
#define  MIS_GPIO_GP0IE_gp_mask                                                  (0xFFFFFFFF)
#define  MIS_GPIO_GP0IE_gp(data)                                                 (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP0IE_get_gp(data)                                             (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP1IE                                                          0x1801BD4C
#define  MIS_GPIO_GP1IE_reg_addr                                                 "0xB801BD4C"
#define  MIS_GPIO_GP1IE_reg                                                      0xB801BD4C
#define  MIS_GPIO_GP1IE_inst_addr                                                "0x0013"
#define  set_MIS_GPIO_GP1IE_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP1IE_reg)=data)
#define  get_MIS_GPIO_GP1IE_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP1IE_reg))
#define  MIS_GPIO_GP1IE_gp_shift                                                 (0)
#define  MIS_GPIO_GP1IE_gp_mask                                                  (0xFFFFFFFF)
#define  MIS_GPIO_GP1IE_gp(data)                                                 (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP1IE_get_gp(data)                                             (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP2IE                                                          0x1801BD50
#define  MIS_GPIO_GP2IE_reg_addr                                                 "0xB801BD50"
#define  MIS_GPIO_GP2IE_reg                                                      0xB801BD50
#define  MIS_GPIO_GP2IE_inst_addr                                                "0x0014"
#define  set_MIS_GPIO_GP2IE_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP2IE_reg)=data)
#define  get_MIS_GPIO_GP2IE_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP2IE_reg))
#define  MIS_GPIO_GP2IE_gp_shift                                                 (0)
#define  MIS_GPIO_GP2IE_gp_mask                                                  (0xFFFFFFFF)
#define  MIS_GPIO_GP2IE_gp(data)                                                 (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP2IE_get_gp(data)                                             (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP3IE                                                          0x1801BD54
#define  MIS_GPIO_GP3IE_reg_addr                                                 "0xB801BD54"
#define  MIS_GPIO_GP3IE_reg                                                      0xB801BD54
#define  MIS_GPIO_GP3IE_inst_addr                                                "0x0015"
#define  set_MIS_GPIO_GP3IE_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP3IE_reg)=data)
#define  get_MIS_GPIO_GP3IE_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP3IE_reg))
#define  MIS_GPIO_GP3IE_gp_shift                                                 (0)
#define  MIS_GPIO_GP3IE_gp_mask                                                  (0xFFFFFFFF)
#define  MIS_GPIO_GP3IE_gp(data)                                                 (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP3IE_get_gp(data)                                             (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP4IE                                                          0x1801BD58
#define  MIS_GPIO_GP4IE_reg_addr                                                 "0xB801BD58"
#define  MIS_GPIO_GP4IE_reg                                                      0xB801BD58
#define  MIS_GPIO_GP4IE_inst_addr                                                "0x0016"
#define  set_MIS_GPIO_GP4IE_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP4IE_reg)=data)
#define  get_MIS_GPIO_GP4IE_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP4IE_reg))
#define  MIS_GPIO_GP4IE_gp_shift                                                 (0)
#define  MIS_GPIO_GP4IE_gp_mask                                                  (0xFFFFFFFF)
#define  MIS_GPIO_GP4IE_gp(data)                                                 (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP4IE_get_gp(data)                                             (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP5IE                                                          0x1801BD5C
#define  MIS_GPIO_GP5IE_reg_addr                                                 "0xB801BD5C"
#define  MIS_GPIO_GP5IE_reg                                                      0xB801BD5C
#define  MIS_GPIO_GP5IE_inst_addr                                                "0x0017"
#define  set_MIS_GPIO_GP5IE_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP5IE_reg)=data)
#define  get_MIS_GPIO_GP5IE_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP5IE_reg))
#define  MIS_GPIO_GP5IE_gp_shift                                                 (0)
#define  MIS_GPIO_GP5IE_gp_mask                                                  (0x7FFFFFFF)
#define  MIS_GPIO_GP5IE_gp(data)                                                 (0x7FFFFFFF&(data))
#define  MIS_GPIO_GP5IE_get_gp(data)                                             (0x7FFFFFFF&(data))

#define  MIS_GPIO_GP0DP                                                          0x1801BD60
#define  MIS_GPIO_GP0DP_reg_addr                                                 "0xB801BD60"
#define  MIS_GPIO_GP0DP_reg                                                      0xB801BD60
#define  MIS_GPIO_GP0DP_inst_addr                                                "0x0018"
#define  set_MIS_GPIO_GP0DP_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP0DP_reg)=data)
#define  get_MIS_GPIO_GP0DP_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP0DP_reg))
#define  MIS_GPIO_GP0DP_gpha_shift                                               (0)
#define  MIS_GPIO_GP0DP_gpha_mask                                                (0xFFFFFFFF)
#define  MIS_GPIO_GP0DP_gpha(data)                                               (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP0DP_get_gpha(data)                                           (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP1DP                                                          0x1801BD64
#define  MIS_GPIO_GP1DP_reg_addr                                                 "0xB801BD64"
#define  MIS_GPIO_GP1DP_reg                                                      0xB801BD64
#define  MIS_GPIO_GP1DP_inst_addr                                                "0x0019"
#define  set_MIS_GPIO_GP1DP_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP1DP_reg)=data)
#define  get_MIS_GPIO_GP1DP_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP1DP_reg))
#define  MIS_GPIO_GP1DP_gpha_shift                                               (0)
#define  MIS_GPIO_GP1DP_gpha_mask                                                (0xFFFFFFFF)
#define  MIS_GPIO_GP1DP_gpha(data)                                               (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP1DP_get_gpha(data)                                           (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP2DP                                                          0x1801BD68
#define  MIS_GPIO_GP2DP_reg_addr                                                 "0xB801BD68"
#define  MIS_GPIO_GP2DP_reg                                                      0xB801BD68
#define  MIS_GPIO_GP2DP_inst_addr                                                "0x001A"
#define  set_MIS_GPIO_GP2DP_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP2DP_reg)=data)
#define  get_MIS_GPIO_GP2DP_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP2DP_reg))
#define  MIS_GPIO_GP2DP_gpha_shift                                               (0)
#define  MIS_GPIO_GP2DP_gpha_mask                                                (0xFFFFFFFF)
#define  MIS_GPIO_GP2DP_gpha(data)                                               (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP2DP_get_gpha(data)                                           (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP3DP                                                          0x1801BD6C
#define  MIS_GPIO_GP3DP_reg_addr                                                 "0xB801BD6C"
#define  MIS_GPIO_GP3DP_reg                                                      0xB801BD6C
#define  MIS_GPIO_GP3DP_inst_addr                                                "0x001B"
#define  set_MIS_GPIO_GP3DP_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP3DP_reg)=data)
#define  get_MIS_GPIO_GP3DP_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP3DP_reg))
#define  MIS_GPIO_GP3DP_gpha_shift                                               (0)
#define  MIS_GPIO_GP3DP_gpha_mask                                                (0xFFFFFFFF)
#define  MIS_GPIO_GP3DP_gpha(data)                                               (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP3DP_get_gpha(data)                                           (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP4DP                                                          0x1801BD70
#define  MIS_GPIO_GP4DP_reg_addr                                                 "0xB801BD70"
#define  MIS_GPIO_GP4DP_reg                                                      0xB801BD70
#define  MIS_GPIO_GP4DP_inst_addr                                                "0x001C"
#define  set_MIS_GPIO_GP4DP_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP4DP_reg)=data)
#define  get_MIS_GPIO_GP4DP_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP4DP_reg))
#define  MIS_GPIO_GP4DP_gpha_shift                                               (0)
#define  MIS_GPIO_GP4DP_gpha_mask                                                (0xFFFFFFFF)
#define  MIS_GPIO_GP4DP_gpha(data)                                               (0xFFFFFFFF&(data))
#define  MIS_GPIO_GP4DP_get_gpha(data)                                           (0xFFFFFFFF&(data))

#define  MIS_GPIO_GP5DP                                                          0x1801BD74
#define  MIS_GPIO_GP5DP_reg_addr                                                 "0xB801BD74"
#define  MIS_GPIO_GP5DP_reg                                                      0xB801BD74
#define  MIS_GPIO_GP5DP_inst_addr                                                "0x001D"
#define  set_MIS_GPIO_GP5DP_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GP5DP_reg)=data)
#define  get_MIS_GPIO_GP5DP_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GP5DP_reg))
#define  MIS_GPIO_GP5DP_gpha_shift                                               (0)
#define  MIS_GPIO_GP5DP_gpha_mask                                                (0x7FFFFFFF)
#define  MIS_GPIO_GP5DP_gpha(data)                                               (0x7FFFFFFF&(data))
#define  MIS_GPIO_GP5DP_get_gpha(data)                                           (0x7FFFFFFF&(data))

#define  MIS_GPIO_GPDEB                                                          0x1801BD78
#define  MIS_GPIO_GPDEB_reg_addr                                                 "0xB801BD78"
#define  MIS_GPIO_GPDEB_reg                                                      0xB801BD78
#define  MIS_GPIO_GPDEB_inst_addr                                                "0x001E"
#define  set_MIS_GPIO_GPDEB_reg(data)                                            (*((volatile unsigned int*)MIS_GPIO_GPDEB_reg)=data)
#define  get_MIS_GPIO_GPDEB_reg                                                  (*((volatile unsigned int*)MIS_GPIO_GPDEB_reg))
#define  MIS_GPIO_GPDEB_write_enable8_shift                                      (31)
#define  MIS_GPIO_GPDEB_clk8_shift                                               (28)
#define  MIS_GPIO_GPDEB_write_enable7_shift                                      (27)
#define  MIS_GPIO_GPDEB_clk7_shift                                               (24)
#define  MIS_GPIO_GPDEB_write_enable6_shift                                      (23)
#define  MIS_GPIO_GPDEB_clk6_shift                                               (20)
#define  MIS_GPIO_GPDEB_write_enable5_shift                                      (19)
#define  MIS_GPIO_GPDEB_clk5_shift                                               (16)
#define  MIS_GPIO_GPDEB_write_enable4_shift                                      (15)
#define  MIS_GPIO_GPDEB_clk4_shift                                               (12)
#define  MIS_GPIO_GPDEB_write_enable3_shift                                      (11)
#define  MIS_GPIO_GPDEB_clk3_shift                                               (8)
#define  MIS_GPIO_GPDEB_write_enable2_shift                                      (7)
#define  MIS_GPIO_GPDEB_clk2_shift                                               (4)
#define  MIS_GPIO_GPDEB_write_enable1_shift                                      (3)
#define  MIS_GPIO_GPDEB_clk1_shift                                               (0)
#define  MIS_GPIO_GPDEB_write_enable8_mask                                       (0x80000000)
#define  MIS_GPIO_GPDEB_clk8_mask                                                (0x70000000)
#define  MIS_GPIO_GPDEB_write_enable7_mask                                       (0x08000000)
#define  MIS_GPIO_GPDEB_clk7_mask                                                (0x07000000)
#define  MIS_GPIO_GPDEB_write_enable6_mask                                       (0x00800000)
#define  MIS_GPIO_GPDEB_clk6_mask                                                (0x00700000)
#define  MIS_GPIO_GPDEB_write_enable5_mask                                       (0x00080000)
#define  MIS_GPIO_GPDEB_clk5_mask                                                (0x00070000)
#define  MIS_GPIO_GPDEB_write_enable4_mask                                       (0x00008000)
#define  MIS_GPIO_GPDEB_clk4_mask                                                (0x00007000)
#define  MIS_GPIO_GPDEB_write_enable3_mask                                       (0x00000800)
#define  MIS_GPIO_GPDEB_clk3_mask                                                (0x00000700)
#define  MIS_GPIO_GPDEB_write_enable2_mask                                       (0x00000080)
#define  MIS_GPIO_GPDEB_clk2_mask                                                (0x00000070)
#define  MIS_GPIO_GPDEB_write_enable1_mask                                       (0x00000008)
#define  MIS_GPIO_GPDEB_clk1_mask                                                (0x00000007)
#define  MIS_GPIO_GPDEB_write_enable8(data)                                      (0x80000000&((data)<<31))
#define  MIS_GPIO_GPDEB_clk8(data)                                               (0x70000000&((data)<<28))
#define  MIS_GPIO_GPDEB_write_enable7(data)                                      (0x08000000&((data)<<27))
#define  MIS_GPIO_GPDEB_clk7(data)                                               (0x07000000&((data)<<24))
#define  MIS_GPIO_GPDEB_write_enable6(data)                                      (0x00800000&((data)<<23))
#define  MIS_GPIO_GPDEB_clk6(data)                                               (0x00700000&((data)<<20))
#define  MIS_GPIO_GPDEB_write_enable5(data)                                      (0x00080000&((data)<<19))
#define  MIS_GPIO_GPDEB_clk5(data)                                               (0x00070000&((data)<<16))
#define  MIS_GPIO_GPDEB_write_enable4(data)                                      (0x00008000&((data)<<15))
#define  MIS_GPIO_GPDEB_clk4(data)                                               (0x00007000&((data)<<12))
#define  MIS_GPIO_GPDEB_write_enable3(data)                                      (0x00000800&((data)<<11))
#define  MIS_GPIO_GPDEB_clk3(data)                                               (0x00000700&((data)<<8))
#define  MIS_GPIO_GPDEB_write_enable2(data)                                      (0x00000080&((data)<<7))
#define  MIS_GPIO_GPDEB_clk2(data)                                               (0x00000070&((data)<<4))
#define  MIS_GPIO_GPDEB_write_enable1(data)                                      (0x00000008&((data)<<3))
#define  MIS_GPIO_GPDEB_clk1(data)                                               (0x00000007&(data))
#define  MIS_GPIO_GPDEB_get_write_enable8(data)                                  ((0x80000000&(data))>>31)
#define  MIS_GPIO_GPDEB_get_clk8(data)                                           ((0x70000000&(data))>>28)
#define  MIS_GPIO_GPDEB_get_write_enable7(data)                                  ((0x08000000&(data))>>27)
#define  MIS_GPIO_GPDEB_get_clk7(data)                                           ((0x07000000&(data))>>24)
#define  MIS_GPIO_GPDEB_get_write_enable6(data)                                  ((0x00800000&(data))>>23)
#define  MIS_GPIO_GPDEB_get_clk6(data)                                           ((0x00700000&(data))>>20)
#define  MIS_GPIO_GPDEB_get_write_enable5(data)                                  ((0x00080000&(data))>>19)
#define  MIS_GPIO_GPDEB_get_clk5(data)                                           ((0x00070000&(data))>>16)
#define  MIS_GPIO_GPDEB_get_write_enable4(data)                                  ((0x00008000&(data))>>15)
#define  MIS_GPIO_GPDEB_get_clk4(data)                                           ((0x00007000&(data))>>12)
#define  MIS_GPIO_GPDEB_get_write_enable3(data)                                  ((0x00000800&(data))>>11)
#define  MIS_GPIO_GPDEB_get_clk3(data)                                           ((0x00000700&(data))>>8)
#define  MIS_GPIO_GPDEB_get_write_enable2(data)                                  ((0x00000080&(data))>>7)
#define  MIS_GPIO_GPDEB_get_clk2(data)                                           ((0x00000070&(data))>>4)
#define  MIS_GPIO_GPDEB_get_write_enable1(data)                                  ((0x00000008&(data))>>3)
#define  MIS_GPIO_GPDEB_get_clk1(data)                                           (0x00000007&(data))

#define  MIS_GPIO_GPDEB_1                                                        0x1801BD7C
#define  MIS_GPIO_GPDEB_1_reg_addr                                               "0xB801BD7C"
#define  MIS_GPIO_GPDEB_1_reg                                                    0xB801BD7C
#define  MIS_GPIO_GPDEB_1_inst_addr                                              "0x001F"
#define  set_MIS_GPIO_GPDEB_1_reg(data)                                          (*((volatile unsigned int*)MIS_GPIO_GPDEB_1_reg)=data)
#define  get_MIS_GPIO_GPDEB_1_reg                                                (*((volatile unsigned int*)MIS_GPIO_GPDEB_1_reg))
#define  MIS_GPIO_GPDEB_1_write_enable4_shift                                    (15)
#define  MIS_GPIO_GPDEB_1_clk4_shift                                             (12)
#define  MIS_GPIO_GPDEB_1_write_enable3_shift                                    (11)
#define  MIS_GPIO_GPDEB_1_clk3_shift                                             (8)
#define  MIS_GPIO_GPDEB_1_write_enable2_shift                                    (7)
#define  MIS_GPIO_GPDEB_1_clk2_shift                                             (4)
#define  MIS_GPIO_GPDEB_1_write_enable1_shift                                    (3)
#define  MIS_GPIO_GPDEB_1_clk1_shift                                             (0)
#define  MIS_GPIO_GPDEB_1_write_enable4_mask                                     (0x00008000)
#define  MIS_GPIO_GPDEB_1_clk4_mask                                              (0x00007000)
#define  MIS_GPIO_GPDEB_1_write_enable3_mask                                     (0x00000800)
#define  MIS_GPIO_GPDEB_1_clk3_mask                                              (0x00000700)
#define  MIS_GPIO_GPDEB_1_write_enable2_mask                                     (0x00000080)
#define  MIS_GPIO_GPDEB_1_clk2_mask                                              (0x00000070)
#define  MIS_GPIO_GPDEB_1_write_enable1_mask                                     (0x00000008)
#define  MIS_GPIO_GPDEB_1_clk1_mask                                              (0x00000007)
#define  MIS_GPIO_GPDEB_1_write_enable4(data)                                    (0x00008000&((data)<<15))
#define  MIS_GPIO_GPDEB_1_clk4(data)                                             (0x00007000&((data)<<12))
#define  MIS_GPIO_GPDEB_1_write_enable3(data)                                    (0x00000800&((data)<<11))
#define  MIS_GPIO_GPDEB_1_clk3(data)                                             (0x00000700&((data)<<8))
#define  MIS_GPIO_GPDEB_1_write_enable2(data)                                    (0x00000080&((data)<<7))
#define  MIS_GPIO_GPDEB_1_clk2(data)                                             (0x00000070&((data)<<4))
#define  MIS_GPIO_GPDEB_1_write_enable1(data)                                    (0x00000008&((data)<<3))
#define  MIS_GPIO_GPDEB_1_clk1(data)                                             (0x00000007&(data))
#define  MIS_GPIO_GPDEB_1_get_write_enable4(data)                                ((0x00008000&(data))>>15)
#define  MIS_GPIO_GPDEB_1_get_clk4(data)                                         ((0x00007000&(data))>>12)
#define  MIS_GPIO_GPDEB_1_get_write_enable3(data)                                ((0x00000800&(data))>>11)
#define  MIS_GPIO_GPDEB_1_get_clk3(data)                                         ((0x00000700&(data))>>8)
#define  MIS_GPIO_GPDEB_1_get_write_enable2(data)                                ((0x00000080&(data))>>7)
#define  MIS_GPIO_GPDEB_1_get_clk2(data)                                         ((0x00000070&(data))>>4)
#define  MIS_GPIO_GPDEB_1_get_write_enable1(data)                                ((0x00000008&(data))>>3)
#define  MIS_GPIO_GPDEB_1_get_clk1(data)                                         (0x00000007&(data))

#define  MIS_GPIO_ISR_GP0A                                                       0x1801BD80
#define  MIS_GPIO_ISR_GP0A_reg_addr                                              "0xB801BD80"
#define  MIS_GPIO_ISR_GP0A_reg                                                   0xB801BD80
#define  MIS_GPIO_ISR_GP0A_inst_addr                                             "0x0020"
#define  set_MIS_GPIO_ISR_GP0A_reg(data)                                         (*((volatile unsigned int*)MIS_GPIO_ISR_GP0A_reg)=data)
#define  get_MIS_GPIO_ISR_GP0A_reg                                               (*((volatile unsigned int*)MIS_GPIO_ISR_GP0A_reg))
#define  MIS_GPIO_ISR_GP0A_int30_shift                                           (31)
#define  MIS_GPIO_ISR_GP0A_int29_shift                                           (30)
#define  MIS_GPIO_ISR_GP0A_int28_shift                                           (29)
#define  MIS_GPIO_ISR_GP0A_int27_shift                                           (28)
#define  MIS_GPIO_ISR_GP0A_int26_shift                                           (27)
#define  MIS_GPIO_ISR_GP0A_int25_shift                                           (26)
#define  MIS_GPIO_ISR_GP0A_int24_shift                                           (25)
#define  MIS_GPIO_ISR_GP0A_int23_shift                                           (24)
#define  MIS_GPIO_ISR_GP0A_int22_shift                                           (23)
#define  MIS_GPIO_ISR_GP0A_int21_shift                                           (22)
#define  MIS_GPIO_ISR_GP0A_int20_shift                                           (21)
#define  MIS_GPIO_ISR_GP0A_int19_shift                                           (20)
#define  MIS_GPIO_ISR_GP0A_int18_shift                                           (19)
#define  MIS_GPIO_ISR_GP0A_int17_shift                                           (18)
#define  MIS_GPIO_ISR_GP0A_int16_shift                                           (17)
#define  MIS_GPIO_ISR_GP0A_int15_shift                                           (16)
#define  MIS_GPIO_ISR_GP0A_int14_shift                                           (15)
#define  MIS_GPIO_ISR_GP0A_int13_shift                                           (14)
#define  MIS_GPIO_ISR_GP0A_int12_shift                                           (13)
#define  MIS_GPIO_ISR_GP0A_int11_shift                                           (12)
#define  MIS_GPIO_ISR_GP0A_int10_shift                                           (11)
#define  MIS_GPIO_ISR_GP0A_int9_shift                                            (10)
#define  MIS_GPIO_ISR_GP0A_int8_shift                                            (9)
#define  MIS_GPIO_ISR_GP0A_int7_shift                                            (8)
#define  MIS_GPIO_ISR_GP0A_int6_shift                                            (7)
#define  MIS_GPIO_ISR_GP0A_int5_shift                                            (6)
#define  MIS_GPIO_ISR_GP0A_int4_shift                                            (5)
#define  MIS_GPIO_ISR_GP0A_int3_shift                                            (4)
#define  MIS_GPIO_ISR_GP0A_int2_shift                                            (3)
#define  MIS_GPIO_ISR_GP0A_int1_shift                                            (2)
#define  MIS_GPIO_ISR_GP0A_int0_shift                                            (1)
#define  MIS_GPIO_ISR_GP0A_write_data_shift                                      (0)
#define  MIS_GPIO_ISR_GP0A_int30_mask                                            (0x80000000)
#define  MIS_GPIO_ISR_GP0A_int29_mask                                            (0x40000000)
#define  MIS_GPIO_ISR_GP0A_int28_mask                                            (0x20000000)
#define  MIS_GPIO_ISR_GP0A_int27_mask                                            (0x10000000)
#define  MIS_GPIO_ISR_GP0A_int26_mask                                            (0x08000000)
#define  MIS_GPIO_ISR_GP0A_int25_mask                                            (0x04000000)
#define  MIS_GPIO_ISR_GP0A_int24_mask                                            (0x02000000)
#define  MIS_GPIO_ISR_GP0A_int23_mask                                            (0x01000000)
#define  MIS_GPIO_ISR_GP0A_int22_mask                                            (0x00800000)
#define  MIS_GPIO_ISR_GP0A_int21_mask                                            (0x00400000)
#define  MIS_GPIO_ISR_GP0A_int20_mask                                            (0x00200000)
#define  MIS_GPIO_ISR_GP0A_int19_mask                                            (0x00100000)
#define  MIS_GPIO_ISR_GP0A_int18_mask                                            (0x00080000)
#define  MIS_GPIO_ISR_GP0A_int17_mask                                            (0x00040000)
#define  MIS_GPIO_ISR_GP0A_int16_mask                                            (0x00020000)
#define  MIS_GPIO_ISR_GP0A_int15_mask                                            (0x00010000)
#define  MIS_GPIO_ISR_GP0A_int14_mask                                            (0x00008000)
#define  MIS_GPIO_ISR_GP0A_int13_mask                                            (0x00004000)
#define  MIS_GPIO_ISR_GP0A_int12_mask                                            (0x00002000)
#define  MIS_GPIO_ISR_GP0A_int11_mask                                            (0x00001000)
#define  MIS_GPIO_ISR_GP0A_int10_mask                                            (0x00000800)
#define  MIS_GPIO_ISR_GP0A_int9_mask                                             (0x00000400)
#define  MIS_GPIO_ISR_GP0A_int8_mask                                             (0x00000200)
#define  MIS_GPIO_ISR_GP0A_int7_mask                                             (0x00000100)
#define  MIS_GPIO_ISR_GP0A_int6_mask                                             (0x00000080)
#define  MIS_GPIO_ISR_GP0A_int5_mask                                             (0x00000040)
#define  MIS_GPIO_ISR_GP0A_int4_mask                                             (0x00000020)
#define  MIS_GPIO_ISR_GP0A_int3_mask                                             (0x00000010)
#define  MIS_GPIO_ISR_GP0A_int2_mask                                             (0x00000008)
#define  MIS_GPIO_ISR_GP0A_int1_mask                                             (0x00000004)
#define  MIS_GPIO_ISR_GP0A_int0_mask                                             (0x00000002)
#define  MIS_GPIO_ISR_GP0A_write_data_mask                                       (0x00000001)
#define  MIS_GPIO_ISR_GP0A_int30(data)                                           (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP0A_int29(data)                                           (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP0A_int28(data)                                           (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP0A_int27(data)                                           (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP0A_int26(data)                                           (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP0A_int25(data)                                           (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP0A_int24(data)                                           (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP0A_int23(data)                                           (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP0A_int22(data)                                           (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP0A_int21(data)                                           (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP0A_int20(data)                                           (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP0A_int19(data)                                           (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP0A_int18(data)                                           (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP0A_int17(data)                                           (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP0A_int16(data)                                           (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP0A_int15(data)                                           (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP0A_int14(data)                                           (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP0A_int13(data)                                           (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP0A_int12(data)                                           (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP0A_int11(data)                                           (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP0A_int10(data)                                           (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP0A_int9(data)                                            (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP0A_int8(data)                                            (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP0A_int7(data)                                            (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP0A_int6(data)                                            (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP0A_int5(data)                                            (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP0A_int4(data)                                            (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP0A_int3(data)                                            (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP0A_int2(data)                                            (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP0A_int1(data)                                            (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP0A_int0(data)                                            (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP0A_write_data(data)                                      (0x00000001&(data))
#define  MIS_GPIO_ISR_GP0A_get_int30(data)                                       ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP0A_get_int29(data)                                       ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP0A_get_int28(data)                                       ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP0A_get_int27(data)                                       ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP0A_get_int26(data)                                       ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP0A_get_int25(data)                                       ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP0A_get_int24(data)                                       ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP0A_get_int23(data)                                       ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP0A_get_int22(data)                                       ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP0A_get_int21(data)                                       ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP0A_get_int20(data)                                       ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP0A_get_int19(data)                                       ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP0A_get_int18(data)                                       ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP0A_get_int17(data)                                       ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP0A_get_int16(data)                                       ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP0A_get_int15(data)                                       ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP0A_get_int14(data)                                       ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP0A_get_int13(data)                                       ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP0A_get_int12(data)                                       ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP0A_get_int11(data)                                       ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP0A_get_int10(data)                                       ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP0A_get_int9(data)                                        ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP0A_get_int8(data)                                        ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP0A_get_int7(data)                                        ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP0A_get_int6(data)                                        ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP0A_get_int5(data)                                        ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP0A_get_int4(data)                                        ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP0A_get_int3(data)                                        ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP0A_get_int2(data)                                        ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP0A_get_int1(data)                                        ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP0A_get_int0(data)                                        ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP0A_get_write_data(data)                                  (0x00000001&(data))

#define  MIS_GPIO_ISR_GP1A                                                       0x1801BD84
#define  MIS_GPIO_ISR_GP1A_reg_addr                                              "0xB801BD84"
#define  MIS_GPIO_ISR_GP1A_reg                                                   0xB801BD84
#define  MIS_GPIO_ISR_GP1A_inst_addr                                             "0x0021"
#define  set_MIS_GPIO_ISR_GP1A_reg(data)                                         (*((volatile unsigned int*)MIS_GPIO_ISR_GP1A_reg)=data)
#define  get_MIS_GPIO_ISR_GP1A_reg                                               (*((volatile unsigned int*)MIS_GPIO_ISR_GP1A_reg))
#define  MIS_GPIO_ISR_GP1A_int61_shift                                           (31)
#define  MIS_GPIO_ISR_GP1A_int60_shift                                           (30)
#define  MIS_GPIO_ISR_GP1A_int59_shift                                           (29)
#define  MIS_GPIO_ISR_GP1A_int58_shift                                           (28)
#define  MIS_GPIO_ISR_GP1A_int57_shift                                           (27)
#define  MIS_GPIO_ISR_GP1A_int56_shift                                           (26)
#define  MIS_GPIO_ISR_GP1A_int55_shift                                           (25)
#define  MIS_GPIO_ISR_GP1A_int54_shift                                           (24)
#define  MIS_GPIO_ISR_GP1A_int53_shift                                           (23)
#define  MIS_GPIO_ISR_GP1A_int52_shift                                           (22)
#define  MIS_GPIO_ISR_GP1A_int51_shift                                           (21)
#define  MIS_GPIO_ISR_GP1A_int50_shift                                           (20)
#define  MIS_GPIO_ISR_GP1A_int49_shift                                           (19)
#define  MIS_GPIO_ISR_GP1A_int48_shift                                           (18)
#define  MIS_GPIO_ISR_GP1A_int47_shift                                           (17)
#define  MIS_GPIO_ISR_GP1A_int46_shift                                           (16)
#define  MIS_GPIO_ISR_GP1A_int45_shift                                           (15)
#define  MIS_GPIO_ISR_GP1A_int44_shift                                           (14)
#define  MIS_GPIO_ISR_GP1A_int43_shift                                           (13)
#define  MIS_GPIO_ISR_GP1A_int42_shift                                           (12)
#define  MIS_GPIO_ISR_GP1A_int41_shift                                           (11)
#define  MIS_GPIO_ISR_GP1A_int40_shift                                           (10)
#define  MIS_GPIO_ISR_GP1A_int39_shift                                           (9)
#define  MIS_GPIO_ISR_GP1A_int38_shift                                           (8)
#define  MIS_GPIO_ISR_GP1A_int37_shift                                           (7)
#define  MIS_GPIO_ISR_GP1A_int36_shift                                           (6)
#define  MIS_GPIO_ISR_GP1A_int35_shift                                           (5)
#define  MIS_GPIO_ISR_GP1A_int34_shift                                           (4)
#define  MIS_GPIO_ISR_GP1A_int33_shift                                           (3)
#define  MIS_GPIO_ISR_GP1A_int32_shift                                           (2)
#define  MIS_GPIO_ISR_GP1A_int31_shift                                           (1)
#define  MIS_GPIO_ISR_GP1A_write_data_shift                                      (0)
#define  MIS_GPIO_ISR_GP1A_int61_mask                                            (0x80000000)
#define  MIS_GPIO_ISR_GP1A_int60_mask                                            (0x40000000)
#define  MIS_GPIO_ISR_GP1A_int59_mask                                            (0x20000000)
#define  MIS_GPIO_ISR_GP1A_int58_mask                                            (0x10000000)
#define  MIS_GPIO_ISR_GP1A_int57_mask                                            (0x08000000)
#define  MIS_GPIO_ISR_GP1A_int56_mask                                            (0x04000000)
#define  MIS_GPIO_ISR_GP1A_int55_mask                                            (0x02000000)
#define  MIS_GPIO_ISR_GP1A_int54_mask                                            (0x01000000)
#define  MIS_GPIO_ISR_GP1A_int53_mask                                            (0x00800000)
#define  MIS_GPIO_ISR_GP1A_int52_mask                                            (0x00400000)
#define  MIS_GPIO_ISR_GP1A_int51_mask                                            (0x00200000)
#define  MIS_GPIO_ISR_GP1A_int50_mask                                            (0x00100000)
#define  MIS_GPIO_ISR_GP1A_int49_mask                                            (0x00080000)
#define  MIS_GPIO_ISR_GP1A_int48_mask                                            (0x00040000)
#define  MIS_GPIO_ISR_GP1A_int47_mask                                            (0x00020000)
#define  MIS_GPIO_ISR_GP1A_int46_mask                                            (0x00010000)
#define  MIS_GPIO_ISR_GP1A_int45_mask                                            (0x00008000)
#define  MIS_GPIO_ISR_GP1A_int44_mask                                            (0x00004000)
#define  MIS_GPIO_ISR_GP1A_int43_mask                                            (0x00002000)
#define  MIS_GPIO_ISR_GP1A_int42_mask                                            (0x00001000)
#define  MIS_GPIO_ISR_GP1A_int41_mask                                            (0x00000800)
#define  MIS_GPIO_ISR_GP1A_int40_mask                                            (0x00000400)
#define  MIS_GPIO_ISR_GP1A_int39_mask                                            (0x00000200)
#define  MIS_GPIO_ISR_GP1A_int38_mask                                            (0x00000100)
#define  MIS_GPIO_ISR_GP1A_int37_mask                                            (0x00000080)
#define  MIS_GPIO_ISR_GP1A_int36_mask                                            (0x00000040)
#define  MIS_GPIO_ISR_GP1A_int35_mask                                            (0x00000020)
#define  MIS_GPIO_ISR_GP1A_int34_mask                                            (0x00000010)
#define  MIS_GPIO_ISR_GP1A_int33_mask                                            (0x00000008)
#define  MIS_GPIO_ISR_GP1A_int32_mask                                            (0x00000004)
#define  MIS_GPIO_ISR_GP1A_int31_mask                                            (0x00000002)
#define  MIS_GPIO_ISR_GP1A_write_data_mask                                       (0x00000001)
#define  MIS_GPIO_ISR_GP1A_int61(data)                                           (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP1A_int60(data)                                           (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP1A_int59(data)                                           (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP1A_int58(data)                                           (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP1A_int57(data)                                           (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP1A_int56(data)                                           (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP1A_int55(data)                                           (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP1A_int54(data)                                           (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP1A_int53(data)                                           (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP1A_int52(data)                                           (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP1A_int51(data)                                           (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP1A_int50(data)                                           (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP1A_int49(data)                                           (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP1A_int48(data)                                           (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP1A_int47(data)                                           (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP1A_int46(data)                                           (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP1A_int45(data)                                           (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP1A_int44(data)                                           (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP1A_int43(data)                                           (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP1A_int42(data)                                           (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP1A_int41(data)                                           (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP1A_int40(data)                                           (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP1A_int39(data)                                           (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP1A_int38(data)                                           (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP1A_int37(data)                                           (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP1A_int36(data)                                           (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP1A_int35(data)                                           (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP1A_int34(data)                                           (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP1A_int33(data)                                           (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP1A_int32(data)                                           (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP1A_int31(data)                                           (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP1A_write_data(data)                                      (0x00000001&(data))
#define  MIS_GPIO_ISR_GP1A_get_int61(data)                                       ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP1A_get_int60(data)                                       ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP1A_get_int59(data)                                       ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP1A_get_int58(data)                                       ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP1A_get_int57(data)                                       ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP1A_get_int56(data)                                       ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP1A_get_int55(data)                                       ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP1A_get_int54(data)                                       ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP1A_get_int53(data)                                       ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP1A_get_int52(data)                                       ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP1A_get_int51(data)                                       ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP1A_get_int50(data)                                       ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP1A_get_int49(data)                                       ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP1A_get_int48(data)                                       ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP1A_get_int47(data)                                       ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP1A_get_int46(data)                                       ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP1A_get_int45(data)                                       ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP1A_get_int44(data)                                       ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP1A_get_int43(data)                                       ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP1A_get_int42(data)                                       ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP1A_get_int41(data)                                       ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP1A_get_int40(data)                                       ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP1A_get_int39(data)                                       ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP1A_get_int38(data)                                       ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP1A_get_int37(data)                                       ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP1A_get_int36(data)                                       ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP1A_get_int35(data)                                       ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP1A_get_int34(data)                                       ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP1A_get_int33(data)                                       ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP1A_get_int32(data)                                       ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP1A_get_int31(data)                                       ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP1A_get_write_data(data)                                  (0x00000001&(data))

#define  MIS_GPIO_ISR_GP2A                                                       0x1801BD88
#define  MIS_GPIO_ISR_GP2A_reg_addr                                              "0xB801BD88"
#define  MIS_GPIO_ISR_GP2A_reg                                                   0xB801BD88
#define  MIS_GPIO_ISR_GP2A_inst_addr                                             "0x0022"
#define  set_MIS_GPIO_ISR_GP2A_reg(data)                                         (*((volatile unsigned int*)MIS_GPIO_ISR_GP2A_reg)=data)
#define  get_MIS_GPIO_ISR_GP2A_reg                                               (*((volatile unsigned int*)MIS_GPIO_ISR_GP2A_reg))
#define  MIS_GPIO_ISR_GP2A_int92_shift                                           (31)
#define  MIS_GPIO_ISR_GP2A_int91_shift                                           (30)
#define  MIS_GPIO_ISR_GP2A_int90_shift                                           (29)
#define  MIS_GPIO_ISR_GP2A_int89_shift                                           (28)
#define  MIS_GPIO_ISR_GP2A_int88_shift                                           (27)
#define  MIS_GPIO_ISR_GP2A_int87_shift                                           (26)
#define  MIS_GPIO_ISR_GP2A_int86_shift                                           (25)
#define  MIS_GPIO_ISR_GP2A_int85_shift                                           (24)
#define  MIS_GPIO_ISR_GP2A_int84_shift                                           (23)
#define  MIS_GPIO_ISR_GP2A_int83_shift                                           (22)
#define  MIS_GPIO_ISR_GP2A_int82_shift                                           (21)
#define  MIS_GPIO_ISR_GP2A_int81_shift                                           (20)
#define  MIS_GPIO_ISR_GP2A_int80_shift                                           (19)
#define  MIS_GPIO_ISR_GP2A_int79_shift                                           (18)
#define  MIS_GPIO_ISR_GP2A_int78_shift                                           (17)
#define  MIS_GPIO_ISR_GP2A_int77_shift                                           (16)
#define  MIS_GPIO_ISR_GP2A_int76_shift                                           (15)
#define  MIS_GPIO_ISR_GP2A_int75_shift                                           (14)
#define  MIS_GPIO_ISR_GP2A_int74_shift                                           (13)
#define  MIS_GPIO_ISR_GP2A_int73_shift                                           (12)
#define  MIS_GPIO_ISR_GP2A_int72_shift                                           (11)
#define  MIS_GPIO_ISR_GP2A_int71_shift                                           (10)
#define  MIS_GPIO_ISR_GP2A_int70_shift                                           (9)
#define  MIS_GPIO_ISR_GP2A_int69_shift                                           (8)
#define  MIS_GPIO_ISR_GP2A_int68_shift                                           (7)
#define  MIS_GPIO_ISR_GP2A_int67_shift                                           (6)
#define  MIS_GPIO_ISR_GP2A_int66_shift                                           (5)
#define  MIS_GPIO_ISR_GP2A_int65_shift                                           (4)
#define  MIS_GPIO_ISR_GP2A_int64_shift                                           (3)
#define  MIS_GPIO_ISR_GP2A_int63_shift                                           (2)
#define  MIS_GPIO_ISR_GP2A_int62_shift                                           (1)
#define  MIS_GPIO_ISR_GP2A_write_data_shift                                      (0)
#define  MIS_GPIO_ISR_GP2A_int92_mask                                            (0x80000000)
#define  MIS_GPIO_ISR_GP2A_int91_mask                                            (0x40000000)
#define  MIS_GPIO_ISR_GP2A_int90_mask                                            (0x20000000)
#define  MIS_GPIO_ISR_GP2A_int89_mask                                            (0x10000000)
#define  MIS_GPIO_ISR_GP2A_int88_mask                                            (0x08000000)
#define  MIS_GPIO_ISR_GP2A_int87_mask                                            (0x04000000)
#define  MIS_GPIO_ISR_GP2A_int86_mask                                            (0x02000000)
#define  MIS_GPIO_ISR_GP2A_int85_mask                                            (0x01000000)
#define  MIS_GPIO_ISR_GP2A_int84_mask                                            (0x00800000)
#define  MIS_GPIO_ISR_GP2A_int83_mask                                            (0x00400000)
#define  MIS_GPIO_ISR_GP2A_int82_mask                                            (0x00200000)
#define  MIS_GPIO_ISR_GP2A_int81_mask                                            (0x00100000)
#define  MIS_GPIO_ISR_GP2A_int80_mask                                            (0x00080000)
#define  MIS_GPIO_ISR_GP2A_int79_mask                                            (0x00040000)
#define  MIS_GPIO_ISR_GP2A_int78_mask                                            (0x00020000)
#define  MIS_GPIO_ISR_GP2A_int77_mask                                            (0x00010000)
#define  MIS_GPIO_ISR_GP2A_int76_mask                                            (0x00008000)
#define  MIS_GPIO_ISR_GP2A_int75_mask                                            (0x00004000)
#define  MIS_GPIO_ISR_GP2A_int74_mask                                            (0x00002000)
#define  MIS_GPIO_ISR_GP2A_int73_mask                                            (0x00001000)
#define  MIS_GPIO_ISR_GP2A_int72_mask                                            (0x00000800)
#define  MIS_GPIO_ISR_GP2A_int71_mask                                            (0x00000400)
#define  MIS_GPIO_ISR_GP2A_int70_mask                                            (0x00000200)
#define  MIS_GPIO_ISR_GP2A_int69_mask                                            (0x00000100)
#define  MIS_GPIO_ISR_GP2A_int68_mask                                            (0x00000080)
#define  MIS_GPIO_ISR_GP2A_int67_mask                                            (0x00000040)
#define  MIS_GPIO_ISR_GP2A_int66_mask                                            (0x00000020)
#define  MIS_GPIO_ISR_GP2A_int65_mask                                            (0x00000010)
#define  MIS_GPIO_ISR_GP2A_int64_mask                                            (0x00000008)
#define  MIS_GPIO_ISR_GP2A_int63_mask                                            (0x00000004)
#define  MIS_GPIO_ISR_GP2A_int62_mask                                            (0x00000002)
#define  MIS_GPIO_ISR_GP2A_write_data_mask                                       (0x00000001)
#define  MIS_GPIO_ISR_GP2A_int92(data)                                           (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP2A_int91(data)                                           (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP2A_int90(data)                                           (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP2A_int89(data)                                           (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP2A_int88(data)                                           (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP2A_int87(data)                                           (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP2A_int86(data)                                           (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP2A_int85(data)                                           (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP2A_int84(data)                                           (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP2A_int83(data)                                           (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP2A_int82(data)                                           (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP2A_int81(data)                                           (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP2A_int80(data)                                           (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP2A_int79(data)                                           (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP2A_int78(data)                                           (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP2A_int77(data)                                           (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP2A_int76(data)                                           (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP2A_int75(data)                                           (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP2A_int74(data)                                           (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP2A_int73(data)                                           (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP2A_int72(data)                                           (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP2A_int71(data)                                           (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP2A_int70(data)                                           (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP2A_int69(data)                                           (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP2A_int68(data)                                           (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP2A_int67(data)                                           (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP2A_int66(data)                                           (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP2A_int65(data)                                           (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP2A_int64(data)                                           (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP2A_int63(data)                                           (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP2A_int62(data)                                           (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP2A_write_data(data)                                      (0x00000001&(data))
#define  MIS_GPIO_ISR_GP2A_get_int92(data)                                       ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP2A_get_int91(data)                                       ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP2A_get_int90(data)                                       ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP2A_get_int89(data)                                       ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP2A_get_int88(data)                                       ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP2A_get_int87(data)                                       ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP2A_get_int86(data)                                       ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP2A_get_int85(data)                                       ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP2A_get_int84(data)                                       ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP2A_get_int83(data)                                       ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP2A_get_int82(data)                                       ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP2A_get_int81(data)                                       ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP2A_get_int80(data)                                       ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP2A_get_int79(data)                                       ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP2A_get_int78(data)                                       ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP2A_get_int77(data)                                       ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP2A_get_int76(data)                                       ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP2A_get_int75(data)                                       ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP2A_get_int74(data)                                       ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP2A_get_int73(data)                                       ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP2A_get_int72(data)                                       ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP2A_get_int71(data)                                       ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP2A_get_int70(data)                                       ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP2A_get_int69(data)                                       ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP2A_get_int68(data)                                       ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP2A_get_int67(data)                                       ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP2A_get_int66(data)                                       ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP2A_get_int65(data)                                       ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP2A_get_int64(data)                                       ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP2A_get_int63(data)                                       ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP2A_get_int62(data)                                       ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP2A_get_write_data(data)                                  (0x00000001&(data))

#define  MIS_GPIO_ISR_GP3A                                                       0x1801BD8C
#define  MIS_GPIO_ISR_GP3A_reg_addr                                              "0xB801BD8C"
#define  MIS_GPIO_ISR_GP3A_reg                                                   0xB801BD8C
#define  MIS_GPIO_ISR_GP3A_inst_addr                                             "0x0023"
#define  set_MIS_GPIO_ISR_GP3A_reg(data)                                         (*((volatile unsigned int*)MIS_GPIO_ISR_GP3A_reg)=data)
#define  get_MIS_GPIO_ISR_GP3A_reg                                               (*((volatile unsigned int*)MIS_GPIO_ISR_GP3A_reg))
#define  MIS_GPIO_ISR_GP3A_int123_shift                                          (31)
#define  MIS_GPIO_ISR_GP3A_int122_shift                                          (30)
#define  MIS_GPIO_ISR_GP3A_int121_shift                                          (29)
#define  MIS_GPIO_ISR_GP3A_int120_shift                                          (28)
#define  MIS_GPIO_ISR_GP3A_int119_shift                                          (27)
#define  MIS_GPIO_ISR_GP3A_int118_shift                                          (26)
#define  MIS_GPIO_ISR_GP3A_int117_shift                                          (25)
#define  MIS_GPIO_ISR_GP3A_int116_shift                                          (24)
#define  MIS_GPIO_ISR_GP3A_int115_shift                                          (23)
#define  MIS_GPIO_ISR_GP3A_int114_shift                                          (22)
#define  MIS_GPIO_ISR_GP3A_int113_shift                                          (21)
#define  MIS_GPIO_ISR_GP3A_int112_shift                                          (20)
#define  MIS_GPIO_ISR_GP3A_int111_shift                                          (19)
#define  MIS_GPIO_ISR_GP3A_int110_shift                                          (18)
#define  MIS_GPIO_ISR_GP3A_int109_shift                                          (17)
#define  MIS_GPIO_ISR_GP3A_int108_shift                                          (16)
#define  MIS_GPIO_ISR_GP3A_int107_shift                                          (15)
#define  MIS_GPIO_ISR_GP3A_int106_shift                                          (14)
#define  MIS_GPIO_ISR_GP3A_int105_shift                                          (13)
#define  MIS_GPIO_ISR_GP3A_int104_shift                                          (12)
#define  MIS_GPIO_ISR_GP3A_int103_shift                                          (11)
#define  MIS_GPIO_ISR_GP3A_int102_shift                                          (10)
#define  MIS_GPIO_ISR_GP3A_int101_shift                                          (9)
#define  MIS_GPIO_ISR_GP3A_int100_shift                                          (8)
#define  MIS_GPIO_ISR_GP3A_int99_shift                                           (7)
#define  MIS_GPIO_ISR_GP3A_int98_shift                                           (6)
#define  MIS_GPIO_ISR_GP3A_int97_shift                                           (5)
#define  MIS_GPIO_ISR_GP3A_int96_shift                                           (4)
#define  MIS_GPIO_ISR_GP3A_int95_shift                                           (3)
#define  MIS_GPIO_ISR_GP3A_int94_shift                                           (2)
#define  MIS_GPIO_ISR_GP3A_int93_shift                                           (1)
#define  MIS_GPIO_ISR_GP3A_write_data_shift                                      (0)
#define  MIS_GPIO_ISR_GP3A_int123_mask                                           (0x80000000)
#define  MIS_GPIO_ISR_GP3A_int122_mask                                           (0x40000000)
#define  MIS_GPIO_ISR_GP3A_int121_mask                                           (0x20000000)
#define  MIS_GPIO_ISR_GP3A_int120_mask                                           (0x10000000)
#define  MIS_GPIO_ISR_GP3A_int119_mask                                           (0x08000000)
#define  MIS_GPIO_ISR_GP3A_int118_mask                                           (0x04000000)
#define  MIS_GPIO_ISR_GP3A_int117_mask                                           (0x02000000)
#define  MIS_GPIO_ISR_GP3A_int116_mask                                           (0x01000000)
#define  MIS_GPIO_ISR_GP3A_int115_mask                                           (0x00800000)
#define  MIS_GPIO_ISR_GP3A_int114_mask                                           (0x00400000)
#define  MIS_GPIO_ISR_GP3A_int113_mask                                           (0x00200000)
#define  MIS_GPIO_ISR_GP3A_int112_mask                                           (0x00100000)
#define  MIS_GPIO_ISR_GP3A_int111_mask                                           (0x00080000)
#define  MIS_GPIO_ISR_GP3A_int110_mask                                           (0x00040000)
#define  MIS_GPIO_ISR_GP3A_int109_mask                                           (0x00020000)
#define  MIS_GPIO_ISR_GP3A_int108_mask                                           (0x00010000)
#define  MIS_GPIO_ISR_GP3A_int107_mask                                           (0x00008000)
#define  MIS_GPIO_ISR_GP3A_int106_mask                                           (0x00004000)
#define  MIS_GPIO_ISR_GP3A_int105_mask                                           (0x00002000)
#define  MIS_GPIO_ISR_GP3A_int104_mask                                           (0x00001000)
#define  MIS_GPIO_ISR_GP3A_int103_mask                                           (0x00000800)
#define  MIS_GPIO_ISR_GP3A_int102_mask                                           (0x00000400)
#define  MIS_GPIO_ISR_GP3A_int101_mask                                           (0x00000200)
#define  MIS_GPIO_ISR_GP3A_int100_mask                                           (0x00000100)
#define  MIS_GPIO_ISR_GP3A_int99_mask                                            (0x00000080)
#define  MIS_GPIO_ISR_GP3A_int98_mask                                            (0x00000040)
#define  MIS_GPIO_ISR_GP3A_int97_mask                                            (0x00000020)
#define  MIS_GPIO_ISR_GP3A_int96_mask                                            (0x00000010)
#define  MIS_GPIO_ISR_GP3A_int95_mask                                            (0x00000008)
#define  MIS_GPIO_ISR_GP3A_int94_mask                                            (0x00000004)
#define  MIS_GPIO_ISR_GP3A_int93_mask                                            (0x00000002)
#define  MIS_GPIO_ISR_GP3A_write_data_mask                                       (0x00000001)
#define  MIS_GPIO_ISR_GP3A_int123(data)                                          (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP3A_int122(data)                                          (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP3A_int121(data)                                          (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP3A_int120(data)                                          (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP3A_int119(data)                                          (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP3A_int118(data)                                          (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP3A_int117(data)                                          (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP3A_int116(data)                                          (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP3A_int115(data)                                          (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP3A_int114(data)                                          (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP3A_int113(data)                                          (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP3A_int112(data)                                          (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP3A_int111(data)                                          (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP3A_int110(data)                                          (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP3A_int109(data)                                          (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP3A_int108(data)                                          (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP3A_int107(data)                                          (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP3A_int106(data)                                          (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP3A_int105(data)                                          (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP3A_int104(data)                                          (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP3A_int103(data)                                          (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP3A_int102(data)                                          (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP3A_int101(data)                                          (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP3A_int100(data)                                          (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP3A_int99(data)                                           (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP3A_int98(data)                                           (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP3A_int97(data)                                           (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP3A_int96(data)                                           (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP3A_int95(data)                                           (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP3A_int94(data)                                           (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP3A_int93(data)                                           (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP3A_write_data(data)                                      (0x00000001&(data))
#define  MIS_GPIO_ISR_GP3A_get_int123(data)                                      ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP3A_get_int122(data)                                      ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP3A_get_int121(data)                                      ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP3A_get_int120(data)                                      ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP3A_get_int119(data)                                      ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP3A_get_int118(data)                                      ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP3A_get_int117(data)                                      ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP3A_get_int116(data)                                      ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP3A_get_int115(data)                                      ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP3A_get_int114(data)                                      ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP3A_get_int113(data)                                      ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP3A_get_int112(data)                                      ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP3A_get_int111(data)                                      ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP3A_get_int110(data)                                      ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP3A_get_int109(data)                                      ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP3A_get_int108(data)                                      ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP3A_get_int107(data)                                      ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP3A_get_int106(data)                                      ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP3A_get_int105(data)                                      ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP3A_get_int104(data)                                      ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP3A_get_int103(data)                                      ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP3A_get_int102(data)                                      ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP3A_get_int101(data)                                      ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP3A_get_int100(data)                                      ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP3A_get_int99(data)                                       ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP3A_get_int98(data)                                       ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP3A_get_int97(data)                                       ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP3A_get_int96(data)                                       ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP3A_get_int95(data)                                       ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP3A_get_int94(data)                                       ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP3A_get_int93(data)                                       ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP3A_get_write_data(data)                                  (0x00000001&(data))

#define  MIS_GPIO_ISR_GP4A                                                       0x1801BD90
#define  MIS_GPIO_ISR_GP4A_reg_addr                                              "0xB801BD90"
#define  MIS_GPIO_ISR_GP4A_reg                                                   0xB801BD90
#define  MIS_GPIO_ISR_GP4A_inst_addr                                             "0x0024"
#define  set_MIS_GPIO_ISR_GP4A_reg(data)                                         (*((volatile unsigned int*)MIS_GPIO_ISR_GP4A_reg)=data)
#define  get_MIS_GPIO_ISR_GP4A_reg                                               (*((volatile unsigned int*)MIS_GPIO_ISR_GP4A_reg))
#define  MIS_GPIO_ISR_GP4A_int154_shift                                          (31)
#define  MIS_GPIO_ISR_GP4A_int153_shift                                          (30)
#define  MIS_GPIO_ISR_GP4A_int152_shift                                          (29)
#define  MIS_GPIO_ISR_GP4A_int151_shift                                          (28)
#define  MIS_GPIO_ISR_GP4A_int150_shift                                          (27)
#define  MIS_GPIO_ISR_GP4A_int149_shift                                          (26)
#define  MIS_GPIO_ISR_GP4A_int148_shift                                          (25)
#define  MIS_GPIO_ISR_GP4A_int147_shift                                          (24)
#define  MIS_GPIO_ISR_GP4A_int146_shift                                          (23)
#define  MIS_GPIO_ISR_GP4A_int145_shift                                          (22)
#define  MIS_GPIO_ISR_GP4A_int144_shift                                          (21)
#define  MIS_GPIO_ISR_GP4A_int143_shift                                          (20)
#define  MIS_GPIO_ISR_GP4A_int142_shift                                          (19)
#define  MIS_GPIO_ISR_GP4A_int141_shift                                          (18)
#define  MIS_GPIO_ISR_GP4A_int140_shift                                          (17)
#define  MIS_GPIO_ISR_GP4A_int139_shift                                          (16)
#define  MIS_GPIO_ISR_GP4A_int138_shift                                          (15)
#define  MIS_GPIO_ISR_GP4A_int137_shift                                          (14)
#define  MIS_GPIO_ISR_GP4A_int136_shift                                          (13)
#define  MIS_GPIO_ISR_GP4A_int135_shift                                          (12)
#define  MIS_GPIO_ISR_GP4A_int134_shift                                          (11)
#define  MIS_GPIO_ISR_GP4A_int133_shift                                          (10)
#define  MIS_GPIO_ISR_GP4A_int132_shift                                          (9)
#define  MIS_GPIO_ISR_GP4A_int131_shift                                          (8)
#define  MIS_GPIO_ISR_GP4A_int130_shift                                          (7)
#define  MIS_GPIO_ISR_GP4A_int129_shift                                          (6)
#define  MIS_GPIO_ISR_GP4A_int128_shift                                          (5)
#define  MIS_GPIO_ISR_GP4A_int127_shift                                          (4)
#define  MIS_GPIO_ISR_GP4A_int126_shift                                          (3)
#define  MIS_GPIO_ISR_GP4A_int125_shift                                          (2)
#define  MIS_GPIO_ISR_GP4A_int124_shift                                          (1)
#define  MIS_GPIO_ISR_GP4A_write_data_shift                                      (0)
#define  MIS_GPIO_ISR_GP4A_int154_mask                                           (0x80000000)
#define  MIS_GPIO_ISR_GP4A_int153_mask                                           (0x40000000)
#define  MIS_GPIO_ISR_GP4A_int152_mask                                           (0x20000000)
#define  MIS_GPIO_ISR_GP4A_int151_mask                                           (0x10000000)
#define  MIS_GPIO_ISR_GP4A_int150_mask                                           (0x08000000)
#define  MIS_GPIO_ISR_GP4A_int149_mask                                           (0x04000000)
#define  MIS_GPIO_ISR_GP4A_int148_mask                                           (0x02000000)
#define  MIS_GPIO_ISR_GP4A_int147_mask                                           (0x01000000)
#define  MIS_GPIO_ISR_GP4A_int146_mask                                           (0x00800000)
#define  MIS_GPIO_ISR_GP4A_int145_mask                                           (0x00400000)
#define  MIS_GPIO_ISR_GP4A_int144_mask                                           (0x00200000)
#define  MIS_GPIO_ISR_GP4A_int143_mask                                           (0x00100000)
#define  MIS_GPIO_ISR_GP4A_int142_mask                                           (0x00080000)
#define  MIS_GPIO_ISR_GP4A_int141_mask                                           (0x00040000)
#define  MIS_GPIO_ISR_GP4A_int140_mask                                           (0x00020000)
#define  MIS_GPIO_ISR_GP4A_int139_mask                                           (0x00010000)
#define  MIS_GPIO_ISR_GP4A_int138_mask                                           (0x00008000)
#define  MIS_GPIO_ISR_GP4A_int137_mask                                           (0x00004000)
#define  MIS_GPIO_ISR_GP4A_int136_mask                                           (0x00002000)
#define  MIS_GPIO_ISR_GP4A_int135_mask                                           (0x00001000)
#define  MIS_GPIO_ISR_GP4A_int134_mask                                           (0x00000800)
#define  MIS_GPIO_ISR_GP4A_int133_mask                                           (0x00000400)
#define  MIS_GPIO_ISR_GP4A_int132_mask                                           (0x00000200)
#define  MIS_GPIO_ISR_GP4A_int131_mask                                           (0x00000100)
#define  MIS_GPIO_ISR_GP4A_int130_mask                                           (0x00000080)
#define  MIS_GPIO_ISR_GP4A_int129_mask                                           (0x00000040)
#define  MIS_GPIO_ISR_GP4A_int128_mask                                           (0x00000020)
#define  MIS_GPIO_ISR_GP4A_int127_mask                                           (0x00000010)
#define  MIS_GPIO_ISR_GP4A_int126_mask                                           (0x00000008)
#define  MIS_GPIO_ISR_GP4A_int125_mask                                           (0x00000004)
#define  MIS_GPIO_ISR_GP4A_int124_mask                                           (0x00000002)
#define  MIS_GPIO_ISR_GP4A_write_data_mask                                       (0x00000001)
#define  MIS_GPIO_ISR_GP4A_int154(data)                                          (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP4A_int153(data)                                          (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP4A_int152(data)                                          (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP4A_int151(data)                                          (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP4A_int150(data)                                          (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP4A_int149(data)                                          (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP4A_int148(data)                                          (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP4A_int147(data)                                          (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP4A_int146(data)                                          (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP4A_int145(data)                                          (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP4A_int144(data)                                          (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP4A_int143(data)                                          (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP4A_int142(data)                                          (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP4A_int141(data)                                          (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP4A_int140(data)                                          (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP4A_int139(data)                                          (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP4A_int138(data)                                          (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP4A_int137(data)                                          (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP4A_int136(data)                                          (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP4A_int135(data)                                          (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP4A_int134(data)                                          (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP4A_int133(data)                                          (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP4A_int132(data)                                          (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP4A_int131(data)                                          (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP4A_int130(data)                                          (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP4A_int129(data)                                          (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP4A_int128(data)                                          (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP4A_int127(data)                                          (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP4A_int126(data)                                          (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP4A_int125(data)                                          (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP4A_int124(data)                                          (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP4A_write_data(data)                                      (0x00000001&(data))
#define  MIS_GPIO_ISR_GP4A_get_int154(data)                                      ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP4A_get_int153(data)                                      ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP4A_get_int152(data)                                      ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP4A_get_int151(data)                                      ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP4A_get_int150(data)                                      ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP4A_get_int149(data)                                      ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP4A_get_int148(data)                                      ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP4A_get_int147(data)                                      ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP4A_get_int146(data)                                      ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP4A_get_int145(data)                                      ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP4A_get_int144(data)                                      ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP4A_get_int143(data)                                      ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP4A_get_int142(data)                                      ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP4A_get_int141(data)                                      ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP4A_get_int140(data)                                      ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP4A_get_int139(data)                                      ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP4A_get_int138(data)                                      ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP4A_get_int137(data)                                      ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP4A_get_int136(data)                                      ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP4A_get_int135(data)                                      ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP4A_get_int134(data)                                      ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP4A_get_int133(data)                                      ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP4A_get_int132(data)                                      ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP4A_get_int131(data)                                      ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP4A_get_int130(data)                                      ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP4A_get_int129(data)                                      ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP4A_get_int128(data)                                      ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP4A_get_int127(data)                                      ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP4A_get_int126(data)                                      ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP4A_get_int125(data)                                      ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP4A_get_int124(data)                                      ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP4A_get_write_data(data)                                  (0x00000001&(data))

#define  MIS_GPIO_ISR_GP5A                                                       0x1801BD94
#define  MIS_GPIO_ISR_GP5A_reg_addr                                              "0xB801BD94"
#define  MIS_GPIO_ISR_GP5A_reg                                                   0xB801BD94
#define  MIS_GPIO_ISR_GP5A_inst_addr                                             "0x0025"
#define  set_MIS_GPIO_ISR_GP5A_reg(data)                                         (*((volatile unsigned int*)MIS_GPIO_ISR_GP5A_reg)=data)
#define  get_MIS_GPIO_ISR_GP5A_reg                                               (*((volatile unsigned int*)MIS_GPIO_ISR_GP5A_reg))
#define  MIS_GPIO_ISR_GP5A_int185_shift                                          (31)
#define  MIS_GPIO_ISR_GP5A_int184_shift                                          (30)
#define  MIS_GPIO_ISR_GP5A_int183_shift                                          (29)
#define  MIS_GPIO_ISR_GP5A_int182_shift                                          (28)
#define  MIS_GPIO_ISR_GP5A_int181_shift                                          (27)
#define  MIS_GPIO_ISR_GP5A_int180_shift                                          (26)
#define  MIS_GPIO_ISR_GP5A_int179_shift                                          (25)
#define  MIS_GPIO_ISR_GP5A_int178_shift                                          (24)
#define  MIS_GPIO_ISR_GP5A_int177_shift                                          (23)
#define  MIS_GPIO_ISR_GP5A_int176_shift                                          (22)
#define  MIS_GPIO_ISR_GP5A_int175_shift                                          (21)
#define  MIS_GPIO_ISR_GP5A_int174_shift                                          (20)
#define  MIS_GPIO_ISR_GP5A_int173_shift                                          (19)
#define  MIS_GPIO_ISR_GP5A_int172_shift                                          (18)
#define  MIS_GPIO_ISR_GP5A_int171_shift                                          (17)
#define  MIS_GPIO_ISR_GP5A_int170_shift                                          (16)
#define  MIS_GPIO_ISR_GP5A_int169_shift                                          (15)
#define  MIS_GPIO_ISR_GP5A_int168_shift                                          (14)
#define  MIS_GPIO_ISR_GP5A_int167_shift                                          (13)
#define  MIS_GPIO_ISR_GP5A_int166_shift                                          (12)
#define  MIS_GPIO_ISR_GP5A_int165_shift                                          (11)
#define  MIS_GPIO_ISR_GP5A_int164_shift                                          (10)
#define  MIS_GPIO_ISR_GP5A_int163_shift                                          (9)
#define  MIS_GPIO_ISR_GP5A_int162_shift                                          (8)
#define  MIS_GPIO_ISR_GP5A_int161_shift                                          (7)
#define  MIS_GPIO_ISR_GP5A_int160_shift                                          (6)
#define  MIS_GPIO_ISR_GP5A_int159_shift                                          (5)
#define  MIS_GPIO_ISR_GP5A_int158_shift                                          (4)
#define  MIS_GPIO_ISR_GP5A_int157_shift                                          (3)
#define  MIS_GPIO_ISR_GP5A_int156_shift                                          (2)
#define  MIS_GPIO_ISR_GP5A_int155_shift                                          (1)
#define  MIS_GPIO_ISR_GP5A_write_data_shift                                      (0)
#define  MIS_GPIO_ISR_GP5A_int185_mask                                           (0x80000000)
#define  MIS_GPIO_ISR_GP5A_int184_mask                                           (0x40000000)
#define  MIS_GPIO_ISR_GP5A_int183_mask                                           (0x20000000)
#define  MIS_GPIO_ISR_GP5A_int182_mask                                           (0x10000000)
#define  MIS_GPIO_ISR_GP5A_int181_mask                                           (0x08000000)
#define  MIS_GPIO_ISR_GP5A_int180_mask                                           (0x04000000)
#define  MIS_GPIO_ISR_GP5A_int179_mask                                           (0x02000000)
#define  MIS_GPIO_ISR_GP5A_int178_mask                                           (0x01000000)
#define  MIS_GPIO_ISR_GP5A_int177_mask                                           (0x00800000)
#define  MIS_GPIO_ISR_GP5A_int176_mask                                           (0x00400000)
#define  MIS_GPIO_ISR_GP5A_int175_mask                                           (0x00200000)
#define  MIS_GPIO_ISR_GP5A_int174_mask                                           (0x00100000)
#define  MIS_GPIO_ISR_GP5A_int173_mask                                           (0x00080000)
#define  MIS_GPIO_ISR_GP5A_int172_mask                                           (0x00040000)
#define  MIS_GPIO_ISR_GP5A_int171_mask                                           (0x00020000)
#define  MIS_GPIO_ISR_GP5A_int170_mask                                           (0x00010000)
#define  MIS_GPIO_ISR_GP5A_int169_mask                                           (0x00008000)
#define  MIS_GPIO_ISR_GP5A_int168_mask                                           (0x00004000)
#define  MIS_GPIO_ISR_GP5A_int167_mask                                           (0x00002000)
#define  MIS_GPIO_ISR_GP5A_int166_mask                                           (0x00001000)
#define  MIS_GPIO_ISR_GP5A_int165_mask                                           (0x00000800)
#define  MIS_GPIO_ISR_GP5A_int164_mask                                           (0x00000400)
#define  MIS_GPIO_ISR_GP5A_int163_mask                                           (0x00000200)
#define  MIS_GPIO_ISR_GP5A_int162_mask                                           (0x00000100)
#define  MIS_GPIO_ISR_GP5A_int161_mask                                           (0x00000080)
#define  MIS_GPIO_ISR_GP5A_int160_mask                                           (0x00000040)
#define  MIS_GPIO_ISR_GP5A_int159_mask                                           (0x00000020)
#define  MIS_GPIO_ISR_GP5A_int158_mask                                           (0x00000010)
#define  MIS_GPIO_ISR_GP5A_int157_mask                                           (0x00000008)
#define  MIS_GPIO_ISR_GP5A_int156_mask                                           (0x00000004)
#define  MIS_GPIO_ISR_GP5A_int155_mask                                           (0x00000002)
#define  MIS_GPIO_ISR_GP5A_write_data_mask                                       (0x00000001)
#define  MIS_GPIO_ISR_GP5A_int185(data)                                          (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP5A_int184(data)                                          (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP5A_int183(data)                                          (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP5A_int182(data)                                          (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP5A_int181(data)                                          (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP5A_int180(data)                                          (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP5A_int179(data)                                          (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP5A_int178(data)                                          (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP5A_int177(data)                                          (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP5A_int176(data)                                          (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP5A_int175(data)                                          (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP5A_int174(data)                                          (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP5A_int173(data)                                          (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP5A_int172(data)                                          (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP5A_int171(data)                                          (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP5A_int170(data)                                          (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP5A_int169(data)                                          (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP5A_int168(data)                                          (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP5A_int167(data)                                          (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP5A_int166(data)                                          (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP5A_int165(data)                                          (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP5A_int164(data)                                          (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP5A_int163(data)                                          (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP5A_int162(data)                                          (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP5A_int161(data)                                          (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP5A_int160(data)                                          (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP5A_int159(data)                                          (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP5A_int158(data)                                          (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP5A_int157(data)                                          (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP5A_int156(data)                                          (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP5A_int155(data)                                          (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP5A_write_data(data)                                      (0x00000001&(data))
#define  MIS_GPIO_ISR_GP5A_get_int185(data)                                      ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP5A_get_int184(data)                                      ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP5A_get_int183(data)                                      ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP5A_get_int182(data)                                      ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP5A_get_int181(data)                                      ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP5A_get_int180(data)                                      ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP5A_get_int179(data)                                      ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP5A_get_int178(data)                                      ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP5A_get_int177(data)                                      ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP5A_get_int176(data)                                      ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP5A_get_int175(data)                                      ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP5A_get_int174(data)                                      ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP5A_get_int173(data)                                      ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP5A_get_int172(data)                                      ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP5A_get_int171(data)                                      ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP5A_get_int170(data)                                      ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP5A_get_int169(data)                                      ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP5A_get_int168(data)                                      ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP5A_get_int167(data)                                      ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP5A_get_int166(data)                                      ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP5A_get_int165(data)                                      ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP5A_get_int164(data)                                      ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP5A_get_int163(data)                                      ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP5A_get_int162(data)                                      ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP5A_get_int161(data)                                      ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP5A_get_int160(data)                                      ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP5A_get_int159(data)                                      ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP5A_get_int158(data)                                      ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP5A_get_int157(data)                                      ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP5A_get_int156(data)                                      ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP5A_get_int155(data)                                      ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP5A_get_write_data(data)                                  (0x00000001&(data))

#define  MIS_GPIO_ISR_GP6A                                                       0x1801BD98
#define  MIS_GPIO_ISR_GP6A_reg_addr                                              "0xB801BD98"
#define  MIS_GPIO_ISR_GP6A_reg                                                   0xB801BD98
#define  MIS_GPIO_ISR_GP6A_inst_addr                                             "0x0026"
#define  set_MIS_GPIO_ISR_GP6A_reg(data)                                         (*((volatile unsigned int*)MIS_GPIO_ISR_GP6A_reg)=data)
#define  get_MIS_GPIO_ISR_GP6A_reg                                               (*((volatile unsigned int*)MIS_GPIO_ISR_GP6A_reg))
#define  MIS_GPIO_ISR_GP6A_int190_shift                                          (5)
#define  MIS_GPIO_ISR_GP6A_int189_shift                                          (4)
#define  MIS_GPIO_ISR_GP6A_int188_shift                                          (3)
#define  MIS_GPIO_ISR_GP6A_int187_shift                                          (2)
#define  MIS_GPIO_ISR_GP6A_int186_shift                                          (1)
#define  MIS_GPIO_ISR_GP6A_write_data_shift                                      (0)
#define  MIS_GPIO_ISR_GP6A_int190_mask                                           (0x00000020)
#define  MIS_GPIO_ISR_GP6A_int189_mask                                           (0x00000010)
#define  MIS_GPIO_ISR_GP6A_int188_mask                                           (0x00000008)
#define  MIS_GPIO_ISR_GP6A_int187_mask                                           (0x00000004)
#define  MIS_GPIO_ISR_GP6A_int186_mask                                           (0x00000002)
#define  MIS_GPIO_ISR_GP6A_write_data_mask                                       (0x00000001)
#define  MIS_GPIO_ISR_GP6A_int190(data)                                          (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP6A_int189(data)                                          (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP6A_int188(data)                                          (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP6A_int187(data)                                          (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP6A_int186(data)                                          (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP6A_write_data(data)                                      (0x00000001&(data))
#define  MIS_GPIO_ISR_GP6A_get_int190(data)                                      ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP6A_get_int189(data)                                      ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP6A_get_int188(data)                                      ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP6A_get_int187(data)                                      ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP6A_get_int186(data)                                      ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP6A_get_write_data(data)                                  (0x00000001&(data))

#define  MIS_GPIO_ISR_GP0DA                                                      0x1801BD9C
#define  MIS_GPIO_ISR_GP0DA_reg_addr                                             "0xB801BD9C"
#define  MIS_GPIO_ISR_GP0DA_reg                                                  0xB801BD9C
#define  MIS_GPIO_ISR_GP0DA_inst_addr                                            "0x0027"
#define  set_MIS_GPIO_ISR_GP0DA_reg(data)                                        (*((volatile unsigned int*)MIS_GPIO_ISR_GP0DA_reg)=data)
#define  get_MIS_GPIO_ISR_GP0DA_reg                                              (*((volatile unsigned int*)MIS_GPIO_ISR_GP0DA_reg))
#define  MIS_GPIO_ISR_GP0DA_int30_shift                                          (31)
#define  MIS_GPIO_ISR_GP0DA_int29_shift                                          (30)
#define  MIS_GPIO_ISR_GP0DA_int28_shift                                          (29)
#define  MIS_GPIO_ISR_GP0DA_int27_shift                                          (28)
#define  MIS_GPIO_ISR_GP0DA_int26_shift                                          (27)
#define  MIS_GPIO_ISR_GP0DA_int25_shift                                          (26)
#define  MIS_GPIO_ISR_GP0DA_int24_shift                                          (25)
#define  MIS_GPIO_ISR_GP0DA_int23_shift                                          (24)
#define  MIS_GPIO_ISR_GP0DA_int22_shift                                          (23)
#define  MIS_GPIO_ISR_GP0DA_int21_shift                                          (22)
#define  MIS_GPIO_ISR_GP0DA_int20_shift                                          (21)
#define  MIS_GPIO_ISR_GP0DA_int19_shift                                          (20)
#define  MIS_GPIO_ISR_GP0DA_int18_shift                                          (19)
#define  MIS_GPIO_ISR_GP0DA_int17_shift                                          (18)
#define  MIS_GPIO_ISR_GP0DA_int16_shift                                          (17)
#define  MIS_GPIO_ISR_GP0DA_int15_shift                                          (16)
#define  MIS_GPIO_ISR_GP0DA_int14_shift                                          (15)
#define  MIS_GPIO_ISR_GP0DA_int13_shift                                          (14)
#define  MIS_GPIO_ISR_GP0DA_int12_shift                                          (13)
#define  MIS_GPIO_ISR_GP0DA_int11_shift                                          (12)
#define  MIS_GPIO_ISR_GP0DA_int10_shift                                          (11)
#define  MIS_GPIO_ISR_GP0DA_int9_shift                                           (10)
#define  MIS_GPIO_ISR_GP0DA_int8_shift                                           (9)
#define  MIS_GPIO_ISR_GP0DA_int7_shift                                           (8)
#define  MIS_GPIO_ISR_GP0DA_int6_shift                                           (7)
#define  MIS_GPIO_ISR_GP0DA_int5_shift                                           (6)
#define  MIS_GPIO_ISR_GP0DA_int4_shift                                           (5)
#define  MIS_GPIO_ISR_GP0DA_int3_shift                                           (4)
#define  MIS_GPIO_ISR_GP0DA_int2_shift                                           (3)
#define  MIS_GPIO_ISR_GP0DA_int1_shift                                           (2)
#define  MIS_GPIO_ISR_GP0DA_int0_shift                                           (1)
#define  MIS_GPIO_ISR_GP0DA_write_data_shift                                     (0)
#define  MIS_GPIO_ISR_GP0DA_int30_mask                                           (0x80000000)
#define  MIS_GPIO_ISR_GP0DA_int29_mask                                           (0x40000000)
#define  MIS_GPIO_ISR_GP0DA_int28_mask                                           (0x20000000)
#define  MIS_GPIO_ISR_GP0DA_int27_mask                                           (0x10000000)
#define  MIS_GPIO_ISR_GP0DA_int26_mask                                           (0x08000000)
#define  MIS_GPIO_ISR_GP0DA_int25_mask                                           (0x04000000)
#define  MIS_GPIO_ISR_GP0DA_int24_mask                                           (0x02000000)
#define  MIS_GPIO_ISR_GP0DA_int23_mask                                           (0x01000000)
#define  MIS_GPIO_ISR_GP0DA_int22_mask                                           (0x00800000)
#define  MIS_GPIO_ISR_GP0DA_int21_mask                                           (0x00400000)
#define  MIS_GPIO_ISR_GP0DA_int20_mask                                           (0x00200000)
#define  MIS_GPIO_ISR_GP0DA_int19_mask                                           (0x00100000)
#define  MIS_GPIO_ISR_GP0DA_int18_mask                                           (0x00080000)
#define  MIS_GPIO_ISR_GP0DA_int17_mask                                           (0x00040000)
#define  MIS_GPIO_ISR_GP0DA_int16_mask                                           (0x00020000)
#define  MIS_GPIO_ISR_GP0DA_int15_mask                                           (0x00010000)
#define  MIS_GPIO_ISR_GP0DA_int14_mask                                           (0x00008000)
#define  MIS_GPIO_ISR_GP0DA_int13_mask                                           (0x00004000)
#define  MIS_GPIO_ISR_GP0DA_int12_mask                                           (0x00002000)
#define  MIS_GPIO_ISR_GP0DA_int11_mask                                           (0x00001000)
#define  MIS_GPIO_ISR_GP0DA_int10_mask                                           (0x00000800)
#define  MIS_GPIO_ISR_GP0DA_int9_mask                                            (0x00000400)
#define  MIS_GPIO_ISR_GP0DA_int8_mask                                            (0x00000200)
#define  MIS_GPIO_ISR_GP0DA_int7_mask                                            (0x00000100)
#define  MIS_GPIO_ISR_GP0DA_int6_mask                                            (0x00000080)
#define  MIS_GPIO_ISR_GP0DA_int5_mask                                            (0x00000040)
#define  MIS_GPIO_ISR_GP0DA_int4_mask                                            (0x00000020)
#define  MIS_GPIO_ISR_GP0DA_int3_mask                                            (0x00000010)
#define  MIS_GPIO_ISR_GP0DA_int2_mask                                            (0x00000008)
#define  MIS_GPIO_ISR_GP0DA_int1_mask                                            (0x00000004)
#define  MIS_GPIO_ISR_GP0DA_int0_mask                                            (0x00000002)
#define  MIS_GPIO_ISR_GP0DA_write_data_mask                                      (0x00000001)
#define  MIS_GPIO_ISR_GP0DA_int30(data)                                          (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP0DA_int29(data)                                          (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP0DA_int28(data)                                          (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP0DA_int27(data)                                          (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP0DA_int26(data)                                          (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP0DA_int25(data)                                          (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP0DA_int24(data)                                          (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP0DA_int23(data)                                          (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP0DA_int22(data)                                          (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP0DA_int21(data)                                          (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP0DA_int20(data)                                          (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP0DA_int19(data)                                          (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP0DA_int18(data)                                          (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP0DA_int17(data)                                          (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP0DA_int16(data)                                          (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP0DA_int15(data)                                          (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP0DA_int14(data)                                          (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP0DA_int13(data)                                          (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP0DA_int12(data)                                          (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP0DA_int11(data)                                          (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP0DA_int10(data)                                          (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP0DA_int9(data)                                           (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP0DA_int8(data)                                           (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP0DA_int7(data)                                           (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP0DA_int6(data)                                           (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP0DA_int5(data)                                           (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP0DA_int4(data)                                           (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP0DA_int3(data)                                           (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP0DA_int2(data)                                           (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP0DA_int1(data)                                           (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP0DA_int0(data)                                           (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP0DA_write_data(data)                                     (0x00000001&(data))
#define  MIS_GPIO_ISR_GP0DA_get_int30(data)                                      ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP0DA_get_int29(data)                                      ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP0DA_get_int28(data)                                      ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP0DA_get_int27(data)                                      ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP0DA_get_int26(data)                                      ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP0DA_get_int25(data)                                      ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP0DA_get_int24(data)                                      ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP0DA_get_int23(data)                                      ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP0DA_get_int22(data)                                      ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP0DA_get_int21(data)                                      ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP0DA_get_int20(data)                                      ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP0DA_get_int19(data)                                      ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP0DA_get_int18(data)                                      ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP0DA_get_int17(data)                                      ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP0DA_get_int16(data)                                      ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP0DA_get_int15(data)                                      ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP0DA_get_int14(data)                                      ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP0DA_get_int13(data)                                      ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP0DA_get_int12(data)                                      ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP0DA_get_int11(data)                                      ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP0DA_get_int10(data)                                      ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP0DA_get_int9(data)                                       ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP0DA_get_int8(data)                                       ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP0DA_get_int7(data)                                       ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP0DA_get_int6(data)                                       ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP0DA_get_int5(data)                                       ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP0DA_get_int4(data)                                       ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP0DA_get_int3(data)                                       ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP0DA_get_int2(data)                                       ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP0DA_get_int1(data)                                       ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP0DA_get_int0(data)                                       ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP0DA_get_write_data(data)                                 (0x00000001&(data))

#define  MIS_GPIO_ISR_GP1DA                                                      0x1801BDA0
#define  MIS_GPIO_ISR_GP1DA_reg_addr                                             "0xB801BDA0"
#define  MIS_GPIO_ISR_GP1DA_reg                                                  0xB801BDA0
#define  MIS_GPIO_ISR_GP1DA_inst_addr                                            "0x0028"
#define  set_MIS_GPIO_ISR_GP1DA_reg(data)                                        (*((volatile unsigned int*)MIS_GPIO_ISR_GP1DA_reg)=data)
#define  get_MIS_GPIO_ISR_GP1DA_reg                                              (*((volatile unsigned int*)MIS_GPIO_ISR_GP1DA_reg))
#define  MIS_GPIO_ISR_GP1DA_int61_shift                                          (31)
#define  MIS_GPIO_ISR_GP1DA_int60_shift                                          (30)
#define  MIS_GPIO_ISR_GP1DA_int59_shift                                          (29)
#define  MIS_GPIO_ISR_GP1DA_int58_shift                                          (28)
#define  MIS_GPIO_ISR_GP1DA_int57_shift                                          (27)
#define  MIS_GPIO_ISR_GP1DA_int56_shift                                          (26)
#define  MIS_GPIO_ISR_GP1DA_int55_shift                                          (25)
#define  MIS_GPIO_ISR_GP1DA_int54_shift                                          (24)
#define  MIS_GPIO_ISR_GP1DA_int53_shift                                          (23)
#define  MIS_GPIO_ISR_GP1DA_int52_shift                                          (22)
#define  MIS_GPIO_ISR_GP1DA_int51_shift                                          (21)
#define  MIS_GPIO_ISR_GP1DA_int50_shift                                          (20)
#define  MIS_GPIO_ISR_GP1DA_int49_shift                                          (19)
#define  MIS_GPIO_ISR_GP1DA_int48_shift                                          (18)
#define  MIS_GPIO_ISR_GP1DA_int47_shift                                          (17)
#define  MIS_GPIO_ISR_GP1DA_int46_shift                                          (16)
#define  MIS_GPIO_ISR_GP1DA_int45_shift                                          (15)
#define  MIS_GPIO_ISR_GP1DA_int44_shift                                          (14)
#define  MIS_GPIO_ISR_GP1DA_int43_shift                                          (13)
#define  MIS_GPIO_ISR_GP1DA_int42_shift                                          (12)
#define  MIS_GPIO_ISR_GP1DA_int41_shift                                          (11)
#define  MIS_GPIO_ISR_GP1DA_int40_shift                                          (10)
#define  MIS_GPIO_ISR_GP1DA_int39_shift                                          (9)
#define  MIS_GPIO_ISR_GP1DA_int38_shift                                          (8)
#define  MIS_GPIO_ISR_GP1DA_int37_shift                                          (7)
#define  MIS_GPIO_ISR_GP1DA_int36_shift                                          (6)
#define  MIS_GPIO_ISR_GP1DA_int35_shift                                          (5)
#define  MIS_GPIO_ISR_GP1DA_int34_shift                                          (4)
#define  MIS_GPIO_ISR_GP1DA_int33_shift                                          (3)
#define  MIS_GPIO_ISR_GP1DA_int32_shift                                          (2)
#define  MIS_GPIO_ISR_GP1DA_int31_shift                                          (1)
#define  MIS_GPIO_ISR_GP1DA_write_data_shift                                     (0)
#define  MIS_GPIO_ISR_GP1DA_int61_mask                                           (0x80000000)
#define  MIS_GPIO_ISR_GP1DA_int60_mask                                           (0x40000000)
#define  MIS_GPIO_ISR_GP1DA_int59_mask                                           (0x20000000)
#define  MIS_GPIO_ISR_GP1DA_int58_mask                                           (0x10000000)
#define  MIS_GPIO_ISR_GP1DA_int57_mask                                           (0x08000000)
#define  MIS_GPIO_ISR_GP1DA_int56_mask                                           (0x04000000)
#define  MIS_GPIO_ISR_GP1DA_int55_mask                                           (0x02000000)
#define  MIS_GPIO_ISR_GP1DA_int54_mask                                           (0x01000000)
#define  MIS_GPIO_ISR_GP1DA_int53_mask                                           (0x00800000)
#define  MIS_GPIO_ISR_GP1DA_int52_mask                                           (0x00400000)
#define  MIS_GPIO_ISR_GP1DA_int51_mask                                           (0x00200000)
#define  MIS_GPIO_ISR_GP1DA_int50_mask                                           (0x00100000)
#define  MIS_GPIO_ISR_GP1DA_int49_mask                                           (0x00080000)
#define  MIS_GPIO_ISR_GP1DA_int48_mask                                           (0x00040000)
#define  MIS_GPIO_ISR_GP1DA_int47_mask                                           (0x00020000)
#define  MIS_GPIO_ISR_GP1DA_int46_mask                                           (0x00010000)
#define  MIS_GPIO_ISR_GP1DA_int45_mask                                           (0x00008000)
#define  MIS_GPIO_ISR_GP1DA_int44_mask                                           (0x00004000)
#define  MIS_GPIO_ISR_GP1DA_int43_mask                                           (0x00002000)
#define  MIS_GPIO_ISR_GP1DA_int42_mask                                           (0x00001000)
#define  MIS_GPIO_ISR_GP1DA_int41_mask                                           (0x00000800)
#define  MIS_GPIO_ISR_GP1DA_int40_mask                                           (0x00000400)
#define  MIS_GPIO_ISR_GP1DA_int39_mask                                           (0x00000200)
#define  MIS_GPIO_ISR_GP1DA_int38_mask                                           (0x00000100)
#define  MIS_GPIO_ISR_GP1DA_int37_mask                                           (0x00000080)
#define  MIS_GPIO_ISR_GP1DA_int36_mask                                           (0x00000040)
#define  MIS_GPIO_ISR_GP1DA_int35_mask                                           (0x00000020)
#define  MIS_GPIO_ISR_GP1DA_int34_mask                                           (0x00000010)
#define  MIS_GPIO_ISR_GP1DA_int33_mask                                           (0x00000008)
#define  MIS_GPIO_ISR_GP1DA_int32_mask                                           (0x00000004)
#define  MIS_GPIO_ISR_GP1DA_int31_mask                                           (0x00000002)
#define  MIS_GPIO_ISR_GP1DA_write_data_mask                                      (0x00000001)
#define  MIS_GPIO_ISR_GP1DA_int61(data)                                          (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP1DA_int60(data)                                          (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP1DA_int59(data)                                          (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP1DA_int58(data)                                          (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP1DA_int57(data)                                          (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP1DA_int56(data)                                          (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP1DA_int55(data)                                          (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP1DA_int54(data)                                          (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP1DA_int53(data)                                          (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP1DA_int52(data)                                          (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP1DA_int51(data)                                          (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP1DA_int50(data)                                          (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP1DA_int49(data)                                          (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP1DA_int48(data)                                          (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP1DA_int47(data)                                          (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP1DA_int46(data)                                          (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP1DA_int45(data)                                          (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP1DA_int44(data)                                          (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP1DA_int43(data)                                          (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP1DA_int42(data)                                          (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP1DA_int41(data)                                          (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP1DA_int40(data)                                          (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP1DA_int39(data)                                          (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP1DA_int38(data)                                          (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP1DA_int37(data)                                          (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP1DA_int36(data)                                          (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP1DA_int35(data)                                          (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP1DA_int34(data)                                          (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP1DA_int33(data)                                          (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP1DA_int32(data)                                          (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP1DA_int31(data)                                          (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP1DA_write_data(data)                                     (0x00000001&(data))
#define  MIS_GPIO_ISR_GP1DA_get_int61(data)                                      ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP1DA_get_int60(data)                                      ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP1DA_get_int59(data)                                      ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP1DA_get_int58(data)                                      ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP1DA_get_int57(data)                                      ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP1DA_get_int56(data)                                      ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP1DA_get_int55(data)                                      ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP1DA_get_int54(data)                                      ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP1DA_get_int53(data)                                      ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP1DA_get_int52(data)                                      ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP1DA_get_int51(data)                                      ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP1DA_get_int50(data)                                      ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP1DA_get_int49(data)                                      ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP1DA_get_int48(data)                                      ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP1DA_get_int47(data)                                      ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP1DA_get_int46(data)                                      ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP1DA_get_int45(data)                                      ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP1DA_get_int44(data)                                      ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP1DA_get_int43(data)                                      ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP1DA_get_int42(data)                                      ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP1DA_get_int41(data)                                      ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP1DA_get_int40(data)                                      ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP1DA_get_int39(data)                                      ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP1DA_get_int38(data)                                      ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP1DA_get_int37(data)                                      ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP1DA_get_int36(data)                                      ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP1DA_get_int35(data)                                      ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP1DA_get_int34(data)                                      ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP1DA_get_int33(data)                                      ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP1DA_get_int32(data)                                      ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP1DA_get_int31(data)                                      ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP1DA_get_write_data(data)                                 (0x00000001&(data))

#define  MIS_GPIO_ISR_GP2DA                                                      0x1801BDA4
#define  MIS_GPIO_ISR_GP2DA_reg_addr                                             "0xB801BDA4"
#define  MIS_GPIO_ISR_GP2DA_reg                                                  0xB801BDA4
#define  MIS_GPIO_ISR_GP2DA_inst_addr                                            "0x0029"
#define  set_MIS_GPIO_ISR_GP2DA_reg(data)                                        (*((volatile unsigned int*)MIS_GPIO_ISR_GP2DA_reg)=data)
#define  get_MIS_GPIO_ISR_GP2DA_reg                                              (*((volatile unsigned int*)MIS_GPIO_ISR_GP2DA_reg))
#define  MIS_GPIO_ISR_GP2DA_int92_shift                                          (31)
#define  MIS_GPIO_ISR_GP2DA_int91_shift                                          (30)
#define  MIS_GPIO_ISR_GP2DA_int90_shift                                          (29)
#define  MIS_GPIO_ISR_GP2DA_int89_shift                                          (28)
#define  MIS_GPIO_ISR_GP2DA_int88_shift                                          (27)
#define  MIS_GPIO_ISR_GP2DA_int87_shift                                          (26)
#define  MIS_GPIO_ISR_GP2DA_int86_shift                                          (25)
#define  MIS_GPIO_ISR_GP2DA_int85_shift                                          (24)
#define  MIS_GPIO_ISR_GP2DA_int84_shift                                          (23)
#define  MIS_GPIO_ISR_GP2DA_int83_shift                                          (22)
#define  MIS_GPIO_ISR_GP2DA_int82_shift                                          (21)
#define  MIS_GPIO_ISR_GP2DA_int81_shift                                          (20)
#define  MIS_GPIO_ISR_GP2DA_int80_shift                                          (19)
#define  MIS_GPIO_ISR_GP2DA_int79_shift                                          (18)
#define  MIS_GPIO_ISR_GP2DA_int78_shift                                          (17)
#define  MIS_GPIO_ISR_GP2DA_int77_shift                                          (16)
#define  MIS_GPIO_ISR_GP2DA_int76_shift                                          (15)
#define  MIS_GPIO_ISR_GP2DA_int75_shift                                          (14)
#define  MIS_GPIO_ISR_GP2DA_int74_shift                                          (13)
#define  MIS_GPIO_ISR_GP2DA_int73_shift                                          (12)
#define  MIS_GPIO_ISR_GP2DA_int72_shift                                          (11)
#define  MIS_GPIO_ISR_GP2DA_int71_shift                                          (10)
#define  MIS_GPIO_ISR_GP2DA_int70_shift                                          (9)
#define  MIS_GPIO_ISR_GP2DA_int69_shift                                          (8)
#define  MIS_GPIO_ISR_GP2DA_int68_shift                                          (7)
#define  MIS_GPIO_ISR_GP2DA_int67_shift                                          (6)
#define  MIS_GPIO_ISR_GP2DA_int66_shift                                          (5)
#define  MIS_GPIO_ISR_GP2DA_int65_shift                                          (4)
#define  MIS_GPIO_ISR_GP2DA_int64_shift                                          (3)
#define  MIS_GPIO_ISR_GP2DA_int63_shift                                          (2)
#define  MIS_GPIO_ISR_GP2DA_int62_shift                                          (1)
#define  MIS_GPIO_ISR_GP2DA_write_data_shift                                     (0)
#define  MIS_GPIO_ISR_GP2DA_int92_mask                                           (0x80000000)
#define  MIS_GPIO_ISR_GP2DA_int91_mask                                           (0x40000000)
#define  MIS_GPIO_ISR_GP2DA_int90_mask                                           (0x20000000)
#define  MIS_GPIO_ISR_GP2DA_int89_mask                                           (0x10000000)
#define  MIS_GPIO_ISR_GP2DA_int88_mask                                           (0x08000000)
#define  MIS_GPIO_ISR_GP2DA_int87_mask                                           (0x04000000)
#define  MIS_GPIO_ISR_GP2DA_int86_mask                                           (0x02000000)
#define  MIS_GPIO_ISR_GP2DA_int85_mask                                           (0x01000000)
#define  MIS_GPIO_ISR_GP2DA_int84_mask                                           (0x00800000)
#define  MIS_GPIO_ISR_GP2DA_int83_mask                                           (0x00400000)
#define  MIS_GPIO_ISR_GP2DA_int82_mask                                           (0x00200000)
#define  MIS_GPIO_ISR_GP2DA_int81_mask                                           (0x00100000)
#define  MIS_GPIO_ISR_GP2DA_int80_mask                                           (0x00080000)
#define  MIS_GPIO_ISR_GP2DA_int79_mask                                           (0x00040000)
#define  MIS_GPIO_ISR_GP2DA_int78_mask                                           (0x00020000)
#define  MIS_GPIO_ISR_GP2DA_int77_mask                                           (0x00010000)
#define  MIS_GPIO_ISR_GP2DA_int76_mask                                           (0x00008000)
#define  MIS_GPIO_ISR_GP2DA_int75_mask                                           (0x00004000)
#define  MIS_GPIO_ISR_GP2DA_int74_mask                                           (0x00002000)
#define  MIS_GPIO_ISR_GP2DA_int73_mask                                           (0x00001000)
#define  MIS_GPIO_ISR_GP2DA_int72_mask                                           (0x00000800)
#define  MIS_GPIO_ISR_GP2DA_int71_mask                                           (0x00000400)
#define  MIS_GPIO_ISR_GP2DA_int70_mask                                           (0x00000200)
#define  MIS_GPIO_ISR_GP2DA_int69_mask                                           (0x00000100)
#define  MIS_GPIO_ISR_GP2DA_int68_mask                                           (0x00000080)
#define  MIS_GPIO_ISR_GP2DA_int67_mask                                           (0x00000040)
#define  MIS_GPIO_ISR_GP2DA_int66_mask                                           (0x00000020)
#define  MIS_GPIO_ISR_GP2DA_int65_mask                                           (0x00000010)
#define  MIS_GPIO_ISR_GP2DA_int64_mask                                           (0x00000008)
#define  MIS_GPIO_ISR_GP2DA_int63_mask                                           (0x00000004)
#define  MIS_GPIO_ISR_GP2DA_int62_mask                                           (0x00000002)
#define  MIS_GPIO_ISR_GP2DA_write_data_mask                                      (0x00000001)
#define  MIS_GPIO_ISR_GP2DA_int92(data)                                          (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP2DA_int91(data)                                          (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP2DA_int90(data)                                          (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP2DA_int89(data)                                          (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP2DA_int88(data)                                          (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP2DA_int87(data)                                          (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP2DA_int86(data)                                          (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP2DA_int85(data)                                          (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP2DA_int84(data)                                          (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP2DA_int83(data)                                          (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP2DA_int82(data)                                          (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP2DA_int81(data)                                          (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP2DA_int80(data)                                          (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP2DA_int79(data)                                          (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP2DA_int78(data)                                          (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP2DA_int77(data)                                          (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP2DA_int76(data)                                          (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP2DA_int75(data)                                          (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP2DA_int74(data)                                          (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP2DA_int73(data)                                          (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP2DA_int72(data)                                          (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP2DA_int71(data)                                          (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP2DA_int70(data)                                          (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP2DA_int69(data)                                          (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP2DA_int68(data)                                          (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP2DA_int67(data)                                          (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP2DA_int66(data)                                          (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP2DA_int65(data)                                          (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP2DA_int64(data)                                          (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP2DA_int63(data)                                          (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP2DA_int62(data)                                          (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP2DA_write_data(data)                                     (0x00000001&(data))
#define  MIS_GPIO_ISR_GP2DA_get_int92(data)                                      ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP2DA_get_int91(data)                                      ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP2DA_get_int90(data)                                      ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP2DA_get_int89(data)                                      ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP2DA_get_int88(data)                                      ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP2DA_get_int87(data)                                      ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP2DA_get_int86(data)                                      ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP2DA_get_int85(data)                                      ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP2DA_get_int84(data)                                      ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP2DA_get_int83(data)                                      ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP2DA_get_int82(data)                                      ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP2DA_get_int81(data)                                      ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP2DA_get_int80(data)                                      ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP2DA_get_int79(data)                                      ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP2DA_get_int78(data)                                      ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP2DA_get_int77(data)                                      ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP2DA_get_int76(data)                                      ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP2DA_get_int75(data)                                      ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP2DA_get_int74(data)                                      ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP2DA_get_int73(data)                                      ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP2DA_get_int72(data)                                      ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP2DA_get_int71(data)                                      ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP2DA_get_int70(data)                                      ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP2DA_get_int69(data)                                      ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP2DA_get_int68(data)                                      ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP2DA_get_int67(data)                                      ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP2DA_get_int66(data)                                      ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP2DA_get_int65(data)                                      ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP2DA_get_int64(data)                                      ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP2DA_get_int63(data)                                      ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP2DA_get_int62(data)                                      ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP2DA_get_write_data(data)                                 (0x00000001&(data))

#define  MIS_GPIO_ISR_GP3DA                                                      0x1801BDA8
#define  MIS_GPIO_ISR_GP3DA_reg_addr                                             "0xB801BDA8"
#define  MIS_GPIO_ISR_GP3DA_reg                                                  0xB801BDA8
#define  MIS_GPIO_ISR_GP3DA_inst_addr                                            "0x002A"
#define  set_MIS_GPIO_ISR_GP3DA_reg(data)                                        (*((volatile unsigned int*)MIS_GPIO_ISR_GP3DA_reg)=data)
#define  get_MIS_GPIO_ISR_GP3DA_reg                                              (*((volatile unsigned int*)MIS_GPIO_ISR_GP3DA_reg))
#define  MIS_GPIO_ISR_GP3DA_int123_shift                                         (31)
#define  MIS_GPIO_ISR_GP3DA_int122_shift                                         (30)
#define  MIS_GPIO_ISR_GP3DA_int121_shift                                         (29)
#define  MIS_GPIO_ISR_GP3DA_int120_shift                                         (28)
#define  MIS_GPIO_ISR_GP3DA_int119_shift                                         (27)
#define  MIS_GPIO_ISR_GP3DA_int118_shift                                         (26)
#define  MIS_GPIO_ISR_GP3DA_int117_shift                                         (25)
#define  MIS_GPIO_ISR_GP3DA_int116_shift                                         (24)
#define  MIS_GPIO_ISR_GP3DA_int115_shift                                         (23)
#define  MIS_GPIO_ISR_GP3DA_int114_shift                                         (22)
#define  MIS_GPIO_ISR_GP3DA_int113_shift                                         (21)
#define  MIS_GPIO_ISR_GP3DA_int112_shift                                         (20)
#define  MIS_GPIO_ISR_GP3DA_int111_shift                                         (19)
#define  MIS_GPIO_ISR_GP3DA_int110_shift                                         (18)
#define  MIS_GPIO_ISR_GP3DA_int109_shift                                         (17)
#define  MIS_GPIO_ISR_GP3DA_int108_shift                                         (16)
#define  MIS_GPIO_ISR_GP3DA_int107_shift                                         (15)
#define  MIS_GPIO_ISR_GP3DA_int106_shift                                         (14)
#define  MIS_GPIO_ISR_GP3DA_int105_shift                                         (13)
#define  MIS_GPIO_ISR_GP3DA_int104_shift                                         (12)
#define  MIS_GPIO_ISR_GP3DA_int103_shift                                         (11)
#define  MIS_GPIO_ISR_GP3DA_int102_shift                                         (10)
#define  MIS_GPIO_ISR_GP3DA_int101_shift                                         (9)
#define  MIS_GPIO_ISR_GP3DA_int100_shift                                         (8)
#define  MIS_GPIO_ISR_GP3DA_int99_shift                                          (7)
#define  MIS_GPIO_ISR_GP3DA_int98_shift                                          (6)
#define  MIS_GPIO_ISR_GP3DA_int97_shift                                          (5)
#define  MIS_GPIO_ISR_GP3DA_int96_shift                                          (4)
#define  MIS_GPIO_ISR_GP3DA_int95_shift                                          (3)
#define  MIS_GPIO_ISR_GP3DA_int94_shift                                          (2)
#define  MIS_GPIO_ISR_GP3DA_int93_shift                                          (1)
#define  MIS_GPIO_ISR_GP3DA_write_data_shift                                     (0)
#define  MIS_GPIO_ISR_GP3DA_int123_mask                                          (0x80000000)
#define  MIS_GPIO_ISR_GP3DA_int122_mask                                          (0x40000000)
#define  MIS_GPIO_ISR_GP3DA_int121_mask                                          (0x20000000)
#define  MIS_GPIO_ISR_GP3DA_int120_mask                                          (0x10000000)
#define  MIS_GPIO_ISR_GP3DA_int119_mask                                          (0x08000000)
#define  MIS_GPIO_ISR_GP3DA_int118_mask                                          (0x04000000)
#define  MIS_GPIO_ISR_GP3DA_int117_mask                                          (0x02000000)
#define  MIS_GPIO_ISR_GP3DA_int116_mask                                          (0x01000000)
#define  MIS_GPIO_ISR_GP3DA_int115_mask                                          (0x00800000)
#define  MIS_GPIO_ISR_GP3DA_int114_mask                                          (0x00400000)
#define  MIS_GPIO_ISR_GP3DA_int113_mask                                          (0x00200000)
#define  MIS_GPIO_ISR_GP3DA_int112_mask                                          (0x00100000)
#define  MIS_GPIO_ISR_GP3DA_int111_mask                                          (0x00080000)
#define  MIS_GPIO_ISR_GP3DA_int110_mask                                          (0x00040000)
#define  MIS_GPIO_ISR_GP3DA_int109_mask                                          (0x00020000)
#define  MIS_GPIO_ISR_GP3DA_int108_mask                                          (0x00010000)
#define  MIS_GPIO_ISR_GP3DA_int107_mask                                          (0x00008000)
#define  MIS_GPIO_ISR_GP3DA_int106_mask                                          (0x00004000)
#define  MIS_GPIO_ISR_GP3DA_int105_mask                                          (0x00002000)
#define  MIS_GPIO_ISR_GP3DA_int104_mask                                          (0x00001000)
#define  MIS_GPIO_ISR_GP3DA_int103_mask                                          (0x00000800)
#define  MIS_GPIO_ISR_GP3DA_int102_mask                                          (0x00000400)
#define  MIS_GPIO_ISR_GP3DA_int101_mask                                          (0x00000200)
#define  MIS_GPIO_ISR_GP3DA_int100_mask                                          (0x00000100)
#define  MIS_GPIO_ISR_GP3DA_int99_mask                                           (0x00000080)
#define  MIS_GPIO_ISR_GP3DA_int98_mask                                           (0x00000040)
#define  MIS_GPIO_ISR_GP3DA_int97_mask                                           (0x00000020)
#define  MIS_GPIO_ISR_GP3DA_int96_mask                                           (0x00000010)
#define  MIS_GPIO_ISR_GP3DA_int95_mask                                           (0x00000008)
#define  MIS_GPIO_ISR_GP3DA_int94_mask                                           (0x00000004)
#define  MIS_GPIO_ISR_GP3DA_int93_mask                                           (0x00000002)
#define  MIS_GPIO_ISR_GP3DA_write_data_mask                                      (0x00000001)
#define  MIS_GPIO_ISR_GP3DA_int123(data)                                         (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP3DA_int122(data)                                         (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP3DA_int121(data)                                         (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP3DA_int120(data)                                         (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP3DA_int119(data)                                         (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP3DA_int118(data)                                         (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP3DA_int117(data)                                         (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP3DA_int116(data)                                         (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP3DA_int115(data)                                         (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP3DA_int114(data)                                         (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP3DA_int113(data)                                         (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP3DA_int112(data)                                         (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP3DA_int111(data)                                         (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP3DA_int110(data)                                         (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP3DA_int109(data)                                         (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP3DA_int108(data)                                         (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP3DA_int107(data)                                         (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP3DA_int106(data)                                         (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP3DA_int105(data)                                         (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP3DA_int104(data)                                         (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP3DA_int103(data)                                         (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP3DA_int102(data)                                         (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP3DA_int101(data)                                         (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP3DA_int100(data)                                         (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP3DA_int99(data)                                          (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP3DA_int98(data)                                          (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP3DA_int97(data)                                          (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP3DA_int96(data)                                          (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP3DA_int95(data)                                          (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP3DA_int94(data)                                          (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP3DA_int93(data)                                          (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP3DA_write_data(data)                                     (0x00000001&(data))
#define  MIS_GPIO_ISR_GP3DA_get_int123(data)                                     ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP3DA_get_int122(data)                                     ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP3DA_get_int121(data)                                     ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP3DA_get_int120(data)                                     ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP3DA_get_int119(data)                                     ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP3DA_get_int118(data)                                     ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP3DA_get_int117(data)                                     ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP3DA_get_int116(data)                                     ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP3DA_get_int115(data)                                     ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP3DA_get_int114(data)                                     ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP3DA_get_int113(data)                                     ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP3DA_get_int112(data)                                     ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP3DA_get_int111(data)                                     ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP3DA_get_int110(data)                                     ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP3DA_get_int109(data)                                     ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP3DA_get_int108(data)                                     ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP3DA_get_int107(data)                                     ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP3DA_get_int106(data)                                     ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP3DA_get_int105(data)                                     ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP3DA_get_int104(data)                                     ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP3DA_get_int103(data)                                     ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP3DA_get_int102(data)                                     ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP3DA_get_int101(data)                                     ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP3DA_get_int100(data)                                     ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP3DA_get_int99(data)                                      ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP3DA_get_int98(data)                                      ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP3DA_get_int97(data)                                      ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP3DA_get_int96(data)                                      ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP3DA_get_int95(data)                                      ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP3DA_get_int94(data)                                      ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP3DA_get_int93(data)                                      ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP3DA_get_write_data(data)                                 (0x00000001&(data))

#define  MIS_GPIO_ISR_GP4DA                                                      0x1801BDAC
#define  MIS_GPIO_ISR_GP4DA_reg_addr                                             "0xB801BDAC"
#define  MIS_GPIO_ISR_GP4DA_reg                                                  0xB801BDAC
#define  MIS_GPIO_ISR_GP4DA_inst_addr                                            "0x002B"
#define  set_MIS_GPIO_ISR_GP4DA_reg(data)                                        (*((volatile unsigned int*)MIS_GPIO_ISR_GP4DA_reg)=data)
#define  get_MIS_GPIO_ISR_GP4DA_reg                                              (*((volatile unsigned int*)MIS_GPIO_ISR_GP4DA_reg))
#define  MIS_GPIO_ISR_GP4DA_int154_shift                                         (31)
#define  MIS_GPIO_ISR_GP4DA_int153_shift                                         (30)
#define  MIS_GPIO_ISR_GP4DA_int152_shift                                         (29)
#define  MIS_GPIO_ISR_GP4DA_int151_shift                                         (28)
#define  MIS_GPIO_ISR_GP4DA_int150_shift                                         (27)
#define  MIS_GPIO_ISR_GP4DA_int149_shift                                         (26)
#define  MIS_GPIO_ISR_GP4DA_int148_shift                                         (25)
#define  MIS_GPIO_ISR_GP4DA_int147_shift                                         (24)
#define  MIS_GPIO_ISR_GP4DA_int146_shift                                         (23)
#define  MIS_GPIO_ISR_GP4DA_int145_shift                                         (22)
#define  MIS_GPIO_ISR_GP4DA_int144_shift                                         (21)
#define  MIS_GPIO_ISR_GP4DA_int143_shift                                         (20)
#define  MIS_GPIO_ISR_GP4DA_int142_shift                                         (19)
#define  MIS_GPIO_ISR_GP4DA_int141_shift                                         (18)
#define  MIS_GPIO_ISR_GP4DA_int140_shift                                         (17)
#define  MIS_GPIO_ISR_GP4DA_int139_shift                                         (16)
#define  MIS_GPIO_ISR_GP4DA_int138_shift                                         (15)
#define  MIS_GPIO_ISR_GP4DA_int137_shift                                         (14)
#define  MIS_GPIO_ISR_GP4DA_int136_shift                                         (13)
#define  MIS_GPIO_ISR_GP4DA_int135_shift                                         (12)
#define  MIS_GPIO_ISR_GP4DA_int134_shift                                         (11)
#define  MIS_GPIO_ISR_GP4DA_int133_shift                                         (10)
#define  MIS_GPIO_ISR_GP4DA_int132_shift                                         (9)
#define  MIS_GPIO_ISR_GP4DA_int131_shift                                         (8)
#define  MIS_GPIO_ISR_GP4DA_int130_shift                                         (7)
#define  MIS_GPIO_ISR_GP4DA_int129_shift                                         (6)
#define  MIS_GPIO_ISR_GP4DA_int128_shift                                         (5)
#define  MIS_GPIO_ISR_GP4DA_int127_shift                                         (4)
#define  MIS_GPIO_ISR_GP4DA_int126_shift                                         (3)
#define  MIS_GPIO_ISR_GP4DA_int125_shift                                         (2)
#define  MIS_GPIO_ISR_GP4DA_int124_shift                                         (1)
#define  MIS_GPIO_ISR_GP4DA_write_data_shift                                     (0)
#define  MIS_GPIO_ISR_GP4DA_int154_mask                                          (0x80000000)
#define  MIS_GPIO_ISR_GP4DA_int153_mask                                          (0x40000000)
#define  MIS_GPIO_ISR_GP4DA_int152_mask                                          (0x20000000)
#define  MIS_GPIO_ISR_GP4DA_int151_mask                                          (0x10000000)
#define  MIS_GPIO_ISR_GP4DA_int150_mask                                          (0x08000000)
#define  MIS_GPIO_ISR_GP4DA_int149_mask                                          (0x04000000)
#define  MIS_GPIO_ISR_GP4DA_int148_mask                                          (0x02000000)
#define  MIS_GPIO_ISR_GP4DA_int147_mask                                          (0x01000000)
#define  MIS_GPIO_ISR_GP4DA_int146_mask                                          (0x00800000)
#define  MIS_GPIO_ISR_GP4DA_int145_mask                                          (0x00400000)
#define  MIS_GPIO_ISR_GP4DA_int144_mask                                          (0x00200000)
#define  MIS_GPIO_ISR_GP4DA_int143_mask                                          (0x00100000)
#define  MIS_GPIO_ISR_GP4DA_int142_mask                                          (0x00080000)
#define  MIS_GPIO_ISR_GP4DA_int141_mask                                          (0x00040000)
#define  MIS_GPIO_ISR_GP4DA_int140_mask                                          (0x00020000)
#define  MIS_GPIO_ISR_GP4DA_int139_mask                                          (0x00010000)
#define  MIS_GPIO_ISR_GP4DA_int138_mask                                          (0x00008000)
#define  MIS_GPIO_ISR_GP4DA_int137_mask                                          (0x00004000)
#define  MIS_GPIO_ISR_GP4DA_int136_mask                                          (0x00002000)
#define  MIS_GPIO_ISR_GP4DA_int135_mask                                          (0x00001000)
#define  MIS_GPIO_ISR_GP4DA_int134_mask                                          (0x00000800)
#define  MIS_GPIO_ISR_GP4DA_int133_mask                                          (0x00000400)
#define  MIS_GPIO_ISR_GP4DA_int132_mask                                          (0x00000200)
#define  MIS_GPIO_ISR_GP4DA_int131_mask                                          (0x00000100)
#define  MIS_GPIO_ISR_GP4DA_int130_mask                                          (0x00000080)
#define  MIS_GPIO_ISR_GP4DA_int129_mask                                          (0x00000040)
#define  MIS_GPIO_ISR_GP4DA_int128_mask                                          (0x00000020)
#define  MIS_GPIO_ISR_GP4DA_int127_mask                                          (0x00000010)
#define  MIS_GPIO_ISR_GP4DA_int126_mask                                          (0x00000008)
#define  MIS_GPIO_ISR_GP4DA_int125_mask                                          (0x00000004)
#define  MIS_GPIO_ISR_GP4DA_int124_mask                                          (0x00000002)
#define  MIS_GPIO_ISR_GP4DA_write_data_mask                                      (0x00000001)
#define  MIS_GPIO_ISR_GP4DA_int154(data)                                         (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP4DA_int153(data)                                         (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP4DA_int152(data)                                         (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP4DA_int151(data)                                         (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP4DA_int150(data)                                         (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP4DA_int149(data)                                         (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP4DA_int148(data)                                         (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP4DA_int147(data)                                         (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP4DA_int146(data)                                         (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP4DA_int145(data)                                         (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP4DA_int144(data)                                         (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP4DA_int143(data)                                         (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP4DA_int142(data)                                         (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP4DA_int141(data)                                         (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP4DA_int140(data)                                         (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP4DA_int139(data)                                         (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP4DA_int138(data)                                         (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP4DA_int137(data)                                         (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP4DA_int136(data)                                         (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP4DA_int135(data)                                         (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP4DA_int134(data)                                         (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP4DA_int133(data)                                         (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP4DA_int132(data)                                         (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP4DA_int131(data)                                         (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP4DA_int130(data)                                         (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP4DA_int129(data)                                         (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP4DA_int128(data)                                         (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP4DA_int127(data)                                         (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP4DA_int126(data)                                         (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP4DA_int125(data)                                         (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP4DA_int124(data)                                         (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP4DA_write_data(data)                                     (0x00000001&(data))
#define  MIS_GPIO_ISR_GP4DA_get_int154(data)                                     ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP4DA_get_int153(data)                                     ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP4DA_get_int152(data)                                     ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP4DA_get_int151(data)                                     ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP4DA_get_int150(data)                                     ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP4DA_get_int149(data)                                     ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP4DA_get_int148(data)                                     ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP4DA_get_int147(data)                                     ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP4DA_get_int146(data)                                     ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP4DA_get_int145(data)                                     ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP4DA_get_int144(data)                                     ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP4DA_get_int143(data)                                     ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP4DA_get_int142(data)                                     ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP4DA_get_int141(data)                                     ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP4DA_get_int140(data)                                     ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP4DA_get_int139(data)                                     ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP4DA_get_int138(data)                                     ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP4DA_get_int137(data)                                     ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP4DA_get_int136(data)                                     ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP4DA_get_int135(data)                                     ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP4DA_get_int134(data)                                     ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP4DA_get_int133(data)                                     ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP4DA_get_int132(data)                                     ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP4DA_get_int131(data)                                     ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP4DA_get_int130(data)                                     ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP4DA_get_int129(data)                                     ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP4DA_get_int128(data)                                     ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP4DA_get_int127(data)                                     ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP4DA_get_int126(data)                                     ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP4DA_get_int125(data)                                     ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP4DA_get_int124(data)                                     ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP4DA_get_write_data(data)                                 (0x00000001&(data))

#define  MIS_GPIO_ISR_GP5DA                                                      0x1801BDB0
#define  MIS_GPIO_ISR_GP5DA_reg_addr                                             "0xB801BDB0"
#define  MIS_GPIO_ISR_GP5DA_reg                                                  0xB801BDB0
#define  MIS_GPIO_ISR_GP5DA_inst_addr                                            "0x002C"
#define  set_MIS_GPIO_ISR_GP5DA_reg(data)                                        (*((volatile unsigned int*)MIS_GPIO_ISR_GP5DA_reg)=data)
#define  get_MIS_GPIO_ISR_GP5DA_reg                                              (*((volatile unsigned int*)MIS_GPIO_ISR_GP5DA_reg))
#define  MIS_GPIO_ISR_GP5DA_int185_shift                                         (31)
#define  MIS_GPIO_ISR_GP5DA_int184_shift                                         (30)
#define  MIS_GPIO_ISR_GP5DA_int183_shift                                         (29)
#define  MIS_GPIO_ISR_GP5DA_int182_shift                                         (28)
#define  MIS_GPIO_ISR_GP5DA_int181_shift                                         (27)
#define  MIS_GPIO_ISR_GP5DA_int180_shift                                         (26)
#define  MIS_GPIO_ISR_GP5DA_int179_shift                                         (25)
#define  MIS_GPIO_ISR_GP5DA_int178_shift                                         (24)
#define  MIS_GPIO_ISR_GP5DA_int177_shift                                         (23)
#define  MIS_GPIO_ISR_GP5DA_int176_shift                                         (22)
#define  MIS_GPIO_ISR_GP5DA_int175_shift                                         (21)
#define  MIS_GPIO_ISR_GP5DA_int174_shift                                         (20)
#define  MIS_GPIO_ISR_GP5DA_int173_shift                                         (19)
#define  MIS_GPIO_ISR_GP5DA_int172_shift                                         (18)
#define  MIS_GPIO_ISR_GP5DA_int171_shift                                         (17)
#define  MIS_GPIO_ISR_GP5DA_int170_shift                                         (16)
#define  MIS_GPIO_ISR_GP5DA_int169_shift                                         (15)
#define  MIS_GPIO_ISR_GP5DA_int168_shift                                         (14)
#define  MIS_GPIO_ISR_GP5DA_int167_shift                                         (13)
#define  MIS_GPIO_ISR_GP5DA_int166_shift                                         (12)
#define  MIS_GPIO_ISR_GP5DA_int165_shift                                         (11)
#define  MIS_GPIO_ISR_GP5DA_int164_shift                                         (10)
#define  MIS_GPIO_ISR_GP5DA_int163_shift                                         (9)
#define  MIS_GPIO_ISR_GP5DA_int162_shift                                         (8)
#define  MIS_GPIO_ISR_GP5DA_int161_shift                                         (7)
#define  MIS_GPIO_ISR_GP5DA_int160_shift                                         (6)
#define  MIS_GPIO_ISR_GP5DA_int159_shift                                         (5)
#define  MIS_GPIO_ISR_GP5DA_int158_shift                                         (4)
#define  MIS_GPIO_ISR_GP5DA_int157_shift                                         (3)
#define  MIS_GPIO_ISR_GP5DA_int156_shift                                         (2)
#define  MIS_GPIO_ISR_GP5DA_int155_shift                                         (1)
#define  MIS_GPIO_ISR_GP5DA_write_data_shift                                     (0)
#define  MIS_GPIO_ISR_GP5DA_int185_mask                                          (0x80000000)
#define  MIS_GPIO_ISR_GP5DA_int184_mask                                          (0x40000000)
#define  MIS_GPIO_ISR_GP5DA_int183_mask                                          (0x20000000)
#define  MIS_GPIO_ISR_GP5DA_int182_mask                                          (0x10000000)
#define  MIS_GPIO_ISR_GP5DA_int181_mask                                          (0x08000000)
#define  MIS_GPIO_ISR_GP5DA_int180_mask                                          (0x04000000)
#define  MIS_GPIO_ISR_GP5DA_int179_mask                                          (0x02000000)
#define  MIS_GPIO_ISR_GP5DA_int178_mask                                          (0x01000000)
#define  MIS_GPIO_ISR_GP5DA_int177_mask                                          (0x00800000)
#define  MIS_GPIO_ISR_GP5DA_int176_mask                                          (0x00400000)
#define  MIS_GPIO_ISR_GP5DA_int175_mask                                          (0x00200000)
#define  MIS_GPIO_ISR_GP5DA_int174_mask                                          (0x00100000)
#define  MIS_GPIO_ISR_GP5DA_int173_mask                                          (0x00080000)
#define  MIS_GPIO_ISR_GP5DA_int172_mask                                          (0x00040000)
#define  MIS_GPIO_ISR_GP5DA_int171_mask                                          (0x00020000)
#define  MIS_GPIO_ISR_GP5DA_int170_mask                                          (0x00010000)
#define  MIS_GPIO_ISR_GP5DA_int169_mask                                          (0x00008000)
#define  MIS_GPIO_ISR_GP5DA_int168_mask                                          (0x00004000)
#define  MIS_GPIO_ISR_GP5DA_int167_mask                                          (0x00002000)
#define  MIS_GPIO_ISR_GP5DA_int166_mask                                          (0x00001000)
#define  MIS_GPIO_ISR_GP5DA_int165_mask                                          (0x00000800)
#define  MIS_GPIO_ISR_GP5DA_int164_mask                                          (0x00000400)
#define  MIS_GPIO_ISR_GP5DA_int163_mask                                          (0x00000200)
#define  MIS_GPIO_ISR_GP5DA_int162_mask                                          (0x00000100)
#define  MIS_GPIO_ISR_GP5DA_int161_mask                                          (0x00000080)
#define  MIS_GPIO_ISR_GP5DA_int160_mask                                          (0x00000040)
#define  MIS_GPIO_ISR_GP5DA_int159_mask                                          (0x00000020)
#define  MIS_GPIO_ISR_GP5DA_int158_mask                                          (0x00000010)
#define  MIS_GPIO_ISR_GP5DA_int157_mask                                          (0x00000008)
#define  MIS_GPIO_ISR_GP5DA_int156_mask                                          (0x00000004)
#define  MIS_GPIO_ISR_GP5DA_int155_mask                                          (0x00000002)
#define  MIS_GPIO_ISR_GP5DA_write_data_mask                                      (0x00000001)
#define  MIS_GPIO_ISR_GP5DA_int185(data)                                         (0x80000000&((data)<<31))
#define  MIS_GPIO_ISR_GP5DA_int184(data)                                         (0x40000000&((data)<<30))
#define  MIS_GPIO_ISR_GP5DA_int183(data)                                         (0x20000000&((data)<<29))
#define  MIS_GPIO_ISR_GP5DA_int182(data)                                         (0x10000000&((data)<<28))
#define  MIS_GPIO_ISR_GP5DA_int181(data)                                         (0x08000000&((data)<<27))
#define  MIS_GPIO_ISR_GP5DA_int180(data)                                         (0x04000000&((data)<<26))
#define  MIS_GPIO_ISR_GP5DA_int179(data)                                         (0x02000000&((data)<<25))
#define  MIS_GPIO_ISR_GP5DA_int178(data)                                         (0x01000000&((data)<<24))
#define  MIS_GPIO_ISR_GP5DA_int177(data)                                         (0x00800000&((data)<<23))
#define  MIS_GPIO_ISR_GP5DA_int176(data)                                         (0x00400000&((data)<<22))
#define  MIS_GPIO_ISR_GP5DA_int175(data)                                         (0x00200000&((data)<<21))
#define  MIS_GPIO_ISR_GP5DA_int174(data)                                         (0x00100000&((data)<<20))
#define  MIS_GPIO_ISR_GP5DA_int173(data)                                         (0x00080000&((data)<<19))
#define  MIS_GPIO_ISR_GP5DA_int172(data)                                         (0x00040000&((data)<<18))
#define  MIS_GPIO_ISR_GP5DA_int171(data)                                         (0x00020000&((data)<<17))
#define  MIS_GPIO_ISR_GP5DA_int170(data)                                         (0x00010000&((data)<<16))
#define  MIS_GPIO_ISR_GP5DA_int169(data)                                         (0x00008000&((data)<<15))
#define  MIS_GPIO_ISR_GP5DA_int168(data)                                         (0x00004000&((data)<<14))
#define  MIS_GPIO_ISR_GP5DA_int167(data)                                         (0x00002000&((data)<<13))
#define  MIS_GPIO_ISR_GP5DA_int166(data)                                         (0x00001000&((data)<<12))
#define  MIS_GPIO_ISR_GP5DA_int165(data)                                         (0x00000800&((data)<<11))
#define  MIS_GPIO_ISR_GP5DA_int164(data)                                         (0x00000400&((data)<<10))
#define  MIS_GPIO_ISR_GP5DA_int163(data)                                         (0x00000200&((data)<<9))
#define  MIS_GPIO_ISR_GP5DA_int162(data)                                         (0x00000100&((data)<<8))
#define  MIS_GPIO_ISR_GP5DA_int161(data)                                         (0x00000080&((data)<<7))
#define  MIS_GPIO_ISR_GP5DA_int160(data)                                         (0x00000040&((data)<<6))
#define  MIS_GPIO_ISR_GP5DA_int159(data)                                         (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP5DA_int158(data)                                         (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP5DA_int157(data)                                         (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP5DA_int156(data)                                         (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP5DA_int155(data)                                         (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP5DA_write_data(data)                                     (0x00000001&(data))
#define  MIS_GPIO_ISR_GP5DA_get_int185(data)                                     ((0x80000000&(data))>>31)
#define  MIS_GPIO_ISR_GP5DA_get_int184(data)                                     ((0x40000000&(data))>>30)
#define  MIS_GPIO_ISR_GP5DA_get_int183(data)                                     ((0x20000000&(data))>>29)
#define  MIS_GPIO_ISR_GP5DA_get_int182(data)                                     ((0x10000000&(data))>>28)
#define  MIS_GPIO_ISR_GP5DA_get_int181(data)                                     ((0x08000000&(data))>>27)
#define  MIS_GPIO_ISR_GP5DA_get_int180(data)                                     ((0x04000000&(data))>>26)
#define  MIS_GPIO_ISR_GP5DA_get_int179(data)                                     ((0x02000000&(data))>>25)
#define  MIS_GPIO_ISR_GP5DA_get_int178(data)                                     ((0x01000000&(data))>>24)
#define  MIS_GPIO_ISR_GP5DA_get_int177(data)                                     ((0x00800000&(data))>>23)
#define  MIS_GPIO_ISR_GP5DA_get_int176(data)                                     ((0x00400000&(data))>>22)
#define  MIS_GPIO_ISR_GP5DA_get_int175(data)                                     ((0x00200000&(data))>>21)
#define  MIS_GPIO_ISR_GP5DA_get_int174(data)                                     ((0x00100000&(data))>>20)
#define  MIS_GPIO_ISR_GP5DA_get_int173(data)                                     ((0x00080000&(data))>>19)
#define  MIS_GPIO_ISR_GP5DA_get_int172(data)                                     ((0x00040000&(data))>>18)
#define  MIS_GPIO_ISR_GP5DA_get_int171(data)                                     ((0x00020000&(data))>>17)
#define  MIS_GPIO_ISR_GP5DA_get_int170(data)                                     ((0x00010000&(data))>>16)
#define  MIS_GPIO_ISR_GP5DA_get_int169(data)                                     ((0x00008000&(data))>>15)
#define  MIS_GPIO_ISR_GP5DA_get_int168(data)                                     ((0x00004000&(data))>>14)
#define  MIS_GPIO_ISR_GP5DA_get_int167(data)                                     ((0x00002000&(data))>>13)
#define  MIS_GPIO_ISR_GP5DA_get_int166(data)                                     ((0x00001000&(data))>>12)
#define  MIS_GPIO_ISR_GP5DA_get_int165(data)                                     ((0x00000800&(data))>>11)
#define  MIS_GPIO_ISR_GP5DA_get_int164(data)                                     ((0x00000400&(data))>>10)
#define  MIS_GPIO_ISR_GP5DA_get_int163(data)                                     ((0x00000200&(data))>>9)
#define  MIS_GPIO_ISR_GP5DA_get_int162(data)                                     ((0x00000100&(data))>>8)
#define  MIS_GPIO_ISR_GP5DA_get_int161(data)                                     ((0x00000080&(data))>>7)
#define  MIS_GPIO_ISR_GP5DA_get_int160(data)                                     ((0x00000040&(data))>>6)
#define  MIS_GPIO_ISR_GP5DA_get_int159(data)                                     ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP5DA_get_int158(data)                                     ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP5DA_get_int157(data)                                     ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP5DA_get_int156(data)                                     ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP5DA_get_int155(data)                                     ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP5DA_get_write_data(data)                                 (0x00000001&(data))

#define  MIS_GPIO_ISR_GP6DA                                                      0x1801BDB4
#define  MIS_GPIO_ISR_GP6DA_reg_addr                                             "0xB801BDB4"
#define  MIS_GPIO_ISR_GP6DA_reg                                                  0xB801BDB4
#define  MIS_GPIO_ISR_GP6DA_inst_addr                                            "0x002D"
#define  set_MIS_GPIO_ISR_GP6DA_reg(data)                                        (*((volatile unsigned int*)MIS_GPIO_ISR_GP6DA_reg)=data)
#define  get_MIS_GPIO_ISR_GP6DA_reg                                              (*((volatile unsigned int*)MIS_GPIO_ISR_GP6DA_reg))
#define  MIS_GPIO_ISR_GP6DA_int190_shift                                         (5)
#define  MIS_GPIO_ISR_GP6DA_int189_shift                                         (4)
#define  MIS_GPIO_ISR_GP6DA_int188_shift                                         (3)
#define  MIS_GPIO_ISR_GP6DA_int187_shift                                         (2)
#define  MIS_GPIO_ISR_GP6DA_int186_shift                                         (1)
#define  MIS_GPIO_ISR_GP6DA_write_data_shift                                     (0)
#define  MIS_GPIO_ISR_GP6DA_int190_mask                                          (0x00000020)
#define  MIS_GPIO_ISR_GP6DA_int189_mask                                          (0x00000010)
#define  MIS_GPIO_ISR_GP6DA_int188_mask                                          (0x00000008)
#define  MIS_GPIO_ISR_GP6DA_int187_mask                                          (0x00000004)
#define  MIS_GPIO_ISR_GP6DA_int186_mask                                          (0x00000002)
#define  MIS_GPIO_ISR_GP6DA_write_data_mask                                      (0x00000001)
#define  MIS_GPIO_ISR_GP6DA_int190(data)                                         (0x00000020&((data)<<5))
#define  MIS_GPIO_ISR_GP6DA_int189(data)                                         (0x00000010&((data)<<4))
#define  MIS_GPIO_ISR_GP6DA_int188(data)                                         (0x00000008&((data)<<3))
#define  MIS_GPIO_ISR_GP6DA_int187(data)                                         (0x00000004&((data)<<2))
#define  MIS_GPIO_ISR_GP6DA_int186(data)                                         (0x00000002&((data)<<1))
#define  MIS_GPIO_ISR_GP6DA_write_data(data)                                     (0x00000001&(data))
#define  MIS_GPIO_ISR_GP6DA_get_int190(data)                                     ((0x00000020&(data))>>5)
#define  MIS_GPIO_ISR_GP6DA_get_int189(data)                                     ((0x00000010&(data))>>4)
#define  MIS_GPIO_ISR_GP6DA_get_int188(data)                                     ((0x00000008&(data))>>3)
#define  MIS_GPIO_ISR_GP6DA_get_int187(data)                                     ((0x00000004&(data))>>2)
#define  MIS_GPIO_ISR_GP6DA_get_int186(data)                                     ((0x00000002&(data))>>1)
#define  MIS_GPIO_ISR_GP6DA_get_write_data(data)                                 (0x00000001&(data))

#define  MIS_GPIO_GP_INT_SEL                                                     0x1801BDB8
#define  MIS_GPIO_GP_INT_SEL_reg_addr                                            "0xB801BDB8"
#define  MIS_GPIO_GP_INT_SEL_reg                                                 0xB801BDB8
#define  MIS_GPIO_GP_INT_SEL_inst_addr                                           "0x002E"
#define  set_MIS_GPIO_GP_INT_SEL_reg(data)                                       (*((volatile unsigned int*)MIS_GPIO_GP_INT_SEL_reg)=data)
#define  get_MIS_GPIO_GP_INT_SEL_reg                                             (*((volatile unsigned int*)MIS_GPIO_GP_INT_SEL_reg))
#define  MIS_GPIO_GP_INT_SEL_intsel_shift                                        (0)
#define  MIS_GPIO_GP_INT_SEL_intsel_mask                                         (0x00000003)
#define  MIS_GPIO_GP_INT_SEL_intsel(data)                                        (0x00000003&(data))
#define  MIS_GPIO_GP_INT_SEL_get_intsel(data)                                    (0x00000003&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MIS_GPIO register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}mis_gpio_gp0dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}mis_gpio_gp1dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}mis_gpio_gp2dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}mis_gpio_gp3dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}mis_gpio_gp4dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gpdir:31;
    };
}mis_gpio_gp5dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}mis_gpio_gp0dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}mis_gpio_gp1dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}mis_gpio_gp2dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}mis_gpio_gp3dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}mis_gpio_gp4dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gpdato:31;
    };
}mis_gpio_gp5dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}mis_gpio_gp0dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}mis_gpio_gp1dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}mis_gpio_gp2dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}mis_gpio_gp3dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}mis_gpio_gp4dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gpdati:31;
    };
}mis_gpio_gp5dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}mis_gpio_gp0ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}mis_gpio_gp1ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}mis_gpio_gp2ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}mis_gpio_gp3ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}mis_gpio_gp4ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gp:31;
    };
}mis_gpio_gp5ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}mis_gpio_gp0dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}mis_gpio_gp1dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}mis_gpio_gp2dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}mis_gpio_gp3dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}mis_gpio_gp4dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  gpha:31;
    };
}mis_gpio_gp5dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  clk8:3;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  clk7:3;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  clk6:3;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  clk5:3;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  clk4:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  clk3:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  clk2:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  clk1:3;
    };
}mis_gpio_gpdeb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  clk4:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  clk3:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  clk2:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  clk1:3;
    };
}mis_gpio_gpdeb_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int30:1;
        RBus_UInt32  int29:1;
        RBus_UInt32  int28:1;
        RBus_UInt32  int27:1;
        RBus_UInt32  int26:1;
        RBus_UInt32  int25:1;
        RBus_UInt32  int24:1;
        RBus_UInt32  int23:1;
        RBus_UInt32  int22:1;
        RBus_UInt32  int21:1;
        RBus_UInt32  int20:1;
        RBus_UInt32  int19:1;
        RBus_UInt32  int18:1;
        RBus_UInt32  int17:1;
        RBus_UInt32  int16:1;
        RBus_UInt32  int15:1;
        RBus_UInt32  int14:1;
        RBus_UInt32  int13:1;
        RBus_UInt32  int12:1;
        RBus_UInt32  int11:1;
        RBus_UInt32  int10:1;
        RBus_UInt32  int9:1;
        RBus_UInt32  int8:1;
        RBus_UInt32  int7:1;
        RBus_UInt32  int6:1;
        RBus_UInt32  int5:1;
        RBus_UInt32  int4:1;
        RBus_UInt32  int3:1;
        RBus_UInt32  int2:1;
        RBus_UInt32  int1:1;
        RBus_UInt32  int0:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int61:1;
        RBus_UInt32  int60:1;
        RBus_UInt32  int59:1;
        RBus_UInt32  int58:1;
        RBus_UInt32  int57:1;
        RBus_UInt32  int56:1;
        RBus_UInt32  int55:1;
        RBus_UInt32  int54:1;
        RBus_UInt32  int53:1;
        RBus_UInt32  int52:1;
        RBus_UInt32  int51:1;
        RBus_UInt32  int50:1;
        RBus_UInt32  int49:1;
        RBus_UInt32  int48:1;
        RBus_UInt32  int47:1;
        RBus_UInt32  int46:1;
        RBus_UInt32  int45:1;
        RBus_UInt32  int44:1;
        RBus_UInt32  int43:1;
        RBus_UInt32  int42:1;
        RBus_UInt32  int41:1;
        RBus_UInt32  int40:1;
        RBus_UInt32  int39:1;
        RBus_UInt32  int38:1;
        RBus_UInt32  int37:1;
        RBus_UInt32  int36:1;
        RBus_UInt32  int35:1;
        RBus_UInt32  int34:1;
        RBus_UInt32  int33:1;
        RBus_UInt32  int32:1;
        RBus_UInt32  int31:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp1a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int92:1;
        RBus_UInt32  int91:1;
        RBus_UInt32  int90:1;
        RBus_UInt32  int89:1;
        RBus_UInt32  int88:1;
        RBus_UInt32  int87:1;
        RBus_UInt32  int86:1;
        RBus_UInt32  int85:1;
        RBus_UInt32  int84:1;
        RBus_UInt32  int83:1;
        RBus_UInt32  int82:1;
        RBus_UInt32  int81:1;
        RBus_UInt32  int80:1;
        RBus_UInt32  int79:1;
        RBus_UInt32  int78:1;
        RBus_UInt32  int77:1;
        RBus_UInt32  int76:1;
        RBus_UInt32  int75:1;
        RBus_UInt32  int74:1;
        RBus_UInt32  int73:1;
        RBus_UInt32  int72:1;
        RBus_UInt32  int71:1;
        RBus_UInt32  int70:1;
        RBus_UInt32  int69:1;
        RBus_UInt32  int68:1;
        RBus_UInt32  int67:1;
        RBus_UInt32  int66:1;
        RBus_UInt32  int65:1;
        RBus_UInt32  int64:1;
        RBus_UInt32  int63:1;
        RBus_UInt32  int62:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp2a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int123:1;
        RBus_UInt32  int122:1;
        RBus_UInt32  int121:1;
        RBus_UInt32  int120:1;
        RBus_UInt32  int119:1;
        RBus_UInt32  int118:1;
        RBus_UInt32  int117:1;
        RBus_UInt32  int116:1;
        RBus_UInt32  int115:1;
        RBus_UInt32  int114:1;
        RBus_UInt32  int113:1;
        RBus_UInt32  int112:1;
        RBus_UInt32  int111:1;
        RBus_UInt32  int110:1;
        RBus_UInt32  int109:1;
        RBus_UInt32  int108:1;
        RBus_UInt32  int107:1;
        RBus_UInt32  int106:1;
        RBus_UInt32  int105:1;
        RBus_UInt32  int104:1;
        RBus_UInt32  int103:1;
        RBus_UInt32  int102:1;
        RBus_UInt32  int101:1;
        RBus_UInt32  int100:1;
        RBus_UInt32  int99:1;
        RBus_UInt32  int98:1;
        RBus_UInt32  int97:1;
        RBus_UInt32  int96:1;
        RBus_UInt32  int95:1;
        RBus_UInt32  int94:1;
        RBus_UInt32  int93:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp3a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int154:1;
        RBus_UInt32  int153:1;
        RBus_UInt32  int152:1;
        RBus_UInt32  int151:1;
        RBus_UInt32  int150:1;
        RBus_UInt32  int149:1;
        RBus_UInt32  int148:1;
        RBus_UInt32  int147:1;
        RBus_UInt32  int146:1;
        RBus_UInt32  int145:1;
        RBus_UInt32  int144:1;
        RBus_UInt32  int143:1;
        RBus_UInt32  int142:1;
        RBus_UInt32  int141:1;
        RBus_UInt32  int140:1;
        RBus_UInt32  int139:1;
        RBus_UInt32  int138:1;
        RBus_UInt32  int137:1;
        RBus_UInt32  int136:1;
        RBus_UInt32  int135:1;
        RBus_UInt32  int134:1;
        RBus_UInt32  int133:1;
        RBus_UInt32  int132:1;
        RBus_UInt32  int131:1;
        RBus_UInt32  int130:1;
        RBus_UInt32  int129:1;
        RBus_UInt32  int128:1;
        RBus_UInt32  int127:1;
        RBus_UInt32  int126:1;
        RBus_UInt32  int125:1;
        RBus_UInt32  int124:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp4a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int185:1;
        RBus_UInt32  int184:1;
        RBus_UInt32  int183:1;
        RBus_UInt32  int182:1;
        RBus_UInt32  int181:1;
        RBus_UInt32  int180:1;
        RBus_UInt32  int179:1;
        RBus_UInt32  int178:1;
        RBus_UInt32  int177:1;
        RBus_UInt32  int176:1;
        RBus_UInt32  int175:1;
        RBus_UInt32  int174:1;
        RBus_UInt32  int173:1;
        RBus_UInt32  int172:1;
        RBus_UInt32  int171:1;
        RBus_UInt32  int170:1;
        RBus_UInt32  int169:1;
        RBus_UInt32  int168:1;
        RBus_UInt32  int167:1;
        RBus_UInt32  int166:1;
        RBus_UInt32  int165:1;
        RBus_UInt32  int164:1;
        RBus_UInt32  int163:1;
        RBus_UInt32  int162:1;
        RBus_UInt32  int161:1;
        RBus_UInt32  int160:1;
        RBus_UInt32  int159:1;
        RBus_UInt32  int158:1;
        RBus_UInt32  int157:1;
        RBus_UInt32  int156:1;
        RBus_UInt32  int155:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp5a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  int190:1;
        RBus_UInt32  int189:1;
        RBus_UInt32  int188:1;
        RBus_UInt32  int187:1;
        RBus_UInt32  int186:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp6a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int30:1;
        RBus_UInt32  int29:1;
        RBus_UInt32  int28:1;
        RBus_UInt32  int27:1;
        RBus_UInt32  int26:1;
        RBus_UInt32  int25:1;
        RBus_UInt32  int24:1;
        RBus_UInt32  int23:1;
        RBus_UInt32  int22:1;
        RBus_UInt32  int21:1;
        RBus_UInt32  int20:1;
        RBus_UInt32  int19:1;
        RBus_UInt32  int18:1;
        RBus_UInt32  int17:1;
        RBus_UInt32  int16:1;
        RBus_UInt32  int15:1;
        RBus_UInt32  int14:1;
        RBus_UInt32  int13:1;
        RBus_UInt32  int12:1;
        RBus_UInt32  int11:1;
        RBus_UInt32  int10:1;
        RBus_UInt32  int9:1;
        RBus_UInt32  int8:1;
        RBus_UInt32  int7:1;
        RBus_UInt32  int6:1;
        RBus_UInt32  int5:1;
        RBus_UInt32  int4:1;
        RBus_UInt32  int3:1;
        RBus_UInt32  int2:1;
        RBus_UInt32  int1:1;
        RBus_UInt32  int0:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp0da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int61:1;
        RBus_UInt32  int60:1;
        RBus_UInt32  int59:1;
        RBus_UInt32  int58:1;
        RBus_UInt32  int57:1;
        RBus_UInt32  int56:1;
        RBus_UInt32  int55:1;
        RBus_UInt32  int54:1;
        RBus_UInt32  int53:1;
        RBus_UInt32  int52:1;
        RBus_UInt32  int51:1;
        RBus_UInt32  int50:1;
        RBus_UInt32  int49:1;
        RBus_UInt32  int48:1;
        RBus_UInt32  int47:1;
        RBus_UInt32  int46:1;
        RBus_UInt32  int45:1;
        RBus_UInt32  int44:1;
        RBus_UInt32  int43:1;
        RBus_UInt32  int42:1;
        RBus_UInt32  int41:1;
        RBus_UInt32  int40:1;
        RBus_UInt32  int39:1;
        RBus_UInt32  int38:1;
        RBus_UInt32  int37:1;
        RBus_UInt32  int36:1;
        RBus_UInt32  int35:1;
        RBus_UInt32  int34:1;
        RBus_UInt32  int33:1;
        RBus_UInt32  int32:1;
        RBus_UInt32  int31:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp1da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int92:1;
        RBus_UInt32  int91:1;
        RBus_UInt32  int90:1;
        RBus_UInt32  int89:1;
        RBus_UInt32  int88:1;
        RBus_UInt32  int87:1;
        RBus_UInt32  int86:1;
        RBus_UInt32  int85:1;
        RBus_UInt32  int84:1;
        RBus_UInt32  int83:1;
        RBus_UInt32  int82:1;
        RBus_UInt32  int81:1;
        RBus_UInt32  int80:1;
        RBus_UInt32  int79:1;
        RBus_UInt32  int78:1;
        RBus_UInt32  int77:1;
        RBus_UInt32  int76:1;
        RBus_UInt32  int75:1;
        RBus_UInt32  int74:1;
        RBus_UInt32  int73:1;
        RBus_UInt32  int72:1;
        RBus_UInt32  int71:1;
        RBus_UInt32  int70:1;
        RBus_UInt32  int69:1;
        RBus_UInt32  int68:1;
        RBus_UInt32  int67:1;
        RBus_UInt32  int66:1;
        RBus_UInt32  int65:1;
        RBus_UInt32  int64:1;
        RBus_UInt32  int63:1;
        RBus_UInt32  int62:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp2da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int123:1;
        RBus_UInt32  int122:1;
        RBus_UInt32  int121:1;
        RBus_UInt32  int120:1;
        RBus_UInt32  int119:1;
        RBus_UInt32  int118:1;
        RBus_UInt32  int117:1;
        RBus_UInt32  int116:1;
        RBus_UInt32  int115:1;
        RBus_UInt32  int114:1;
        RBus_UInt32  int113:1;
        RBus_UInt32  int112:1;
        RBus_UInt32  int111:1;
        RBus_UInt32  int110:1;
        RBus_UInt32  int109:1;
        RBus_UInt32  int108:1;
        RBus_UInt32  int107:1;
        RBus_UInt32  int106:1;
        RBus_UInt32  int105:1;
        RBus_UInt32  int104:1;
        RBus_UInt32  int103:1;
        RBus_UInt32  int102:1;
        RBus_UInt32  int101:1;
        RBus_UInt32  int100:1;
        RBus_UInt32  int99:1;
        RBus_UInt32  int98:1;
        RBus_UInt32  int97:1;
        RBus_UInt32  int96:1;
        RBus_UInt32  int95:1;
        RBus_UInt32  int94:1;
        RBus_UInt32  int93:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp3da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int154:1;
        RBus_UInt32  int153:1;
        RBus_UInt32  int152:1;
        RBus_UInt32  int151:1;
        RBus_UInt32  int150:1;
        RBus_UInt32  int149:1;
        RBus_UInt32  int148:1;
        RBus_UInt32  int147:1;
        RBus_UInt32  int146:1;
        RBus_UInt32  int145:1;
        RBus_UInt32  int144:1;
        RBus_UInt32  int143:1;
        RBus_UInt32  int142:1;
        RBus_UInt32  int141:1;
        RBus_UInt32  int140:1;
        RBus_UInt32  int139:1;
        RBus_UInt32  int138:1;
        RBus_UInt32  int137:1;
        RBus_UInt32  int136:1;
        RBus_UInt32  int135:1;
        RBus_UInt32  int134:1;
        RBus_UInt32  int133:1;
        RBus_UInt32  int132:1;
        RBus_UInt32  int131:1;
        RBus_UInt32  int130:1;
        RBus_UInt32  int129:1;
        RBus_UInt32  int128:1;
        RBus_UInt32  int127:1;
        RBus_UInt32  int126:1;
        RBus_UInt32  int125:1;
        RBus_UInt32  int124:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp4da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int185:1;
        RBus_UInt32  int184:1;
        RBus_UInt32  int183:1;
        RBus_UInt32  int182:1;
        RBus_UInt32  int181:1;
        RBus_UInt32  int180:1;
        RBus_UInt32  int179:1;
        RBus_UInt32  int178:1;
        RBus_UInt32  int177:1;
        RBus_UInt32  int176:1;
        RBus_UInt32  int175:1;
        RBus_UInt32  int174:1;
        RBus_UInt32  int173:1;
        RBus_UInt32  int172:1;
        RBus_UInt32  int171:1;
        RBus_UInt32  int170:1;
        RBus_UInt32  int169:1;
        RBus_UInt32  int168:1;
        RBus_UInt32  int167:1;
        RBus_UInt32  int166:1;
        RBus_UInt32  int165:1;
        RBus_UInt32  int164:1;
        RBus_UInt32  int163:1;
        RBus_UInt32  int162:1;
        RBus_UInt32  int161:1;
        RBus_UInt32  int160:1;
        RBus_UInt32  int159:1;
        RBus_UInt32  int158:1;
        RBus_UInt32  int157:1;
        RBus_UInt32  int156:1;
        RBus_UInt32  int155:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp5da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  int190:1;
        RBus_UInt32  int189:1;
        RBus_UInt32  int188:1;
        RBus_UInt32  int187:1;
        RBus_UInt32  int186:1;
        RBus_UInt32  write_data:1;
    };
}mis_gpio_isr_gp6da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  intsel:2;
    };
}mis_gpio_gp_int_sel_RBUS;

#else //apply LITTLE_ENDIAN

//======MIS_GPIO register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}mis_gpio_gp0dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}mis_gpio_gp1dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}mis_gpio_gp2dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}mis_gpio_gp3dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}mis_gpio_gp4dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:31;
        RBus_UInt32  res1:1;
    };
}mis_gpio_gp5dir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}mis_gpio_gp0dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}mis_gpio_gp1dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}mis_gpio_gp2dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}mis_gpio_gp3dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}mis_gpio_gp4dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:31;
        RBus_UInt32  res1:1;
    };
}mis_gpio_gp5dato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}mis_gpio_gp0dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}mis_gpio_gp1dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}mis_gpio_gp2dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}mis_gpio_gp3dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}mis_gpio_gp4dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:31;
        RBus_UInt32  res1:1;
    };
}mis_gpio_gp5dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}mis_gpio_gp0ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}mis_gpio_gp1ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}mis_gpio_gp2ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}mis_gpio_gp3ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}mis_gpio_gp4ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:31;
        RBus_UInt32  res1:1;
    };
}mis_gpio_gp5ie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}mis_gpio_gp0dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}mis_gpio_gp1dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}mis_gpio_gp2dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}mis_gpio_gp3dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}mis_gpio_gp4dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:31;
        RBus_UInt32  res1:1;
    };
}mis_gpio_gp5dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk1:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  clk2:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  clk3:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  clk4:3;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  clk5:3;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  clk6:3;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  clk7:3;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  clk8:3;
        RBus_UInt32  write_enable8:1;
    };
}mis_gpio_gpdeb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk1:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  clk2:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  clk3:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  clk4:3;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  res1:16;
    };
}mis_gpio_gpdeb_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int0:1;
        RBus_UInt32  int1:1;
        RBus_UInt32  int2:1;
        RBus_UInt32  int3:1;
        RBus_UInt32  int4:1;
        RBus_UInt32  int5:1;
        RBus_UInt32  int6:1;
        RBus_UInt32  int7:1;
        RBus_UInt32  int8:1;
        RBus_UInt32  int9:1;
        RBus_UInt32  int10:1;
        RBus_UInt32  int11:1;
        RBus_UInt32  int12:1;
        RBus_UInt32  int13:1;
        RBus_UInt32  int14:1;
        RBus_UInt32  int15:1;
        RBus_UInt32  int16:1;
        RBus_UInt32  int17:1;
        RBus_UInt32  int18:1;
        RBus_UInt32  int19:1;
        RBus_UInt32  int20:1;
        RBus_UInt32  int21:1;
        RBus_UInt32  int22:1;
        RBus_UInt32  int23:1;
        RBus_UInt32  int24:1;
        RBus_UInt32  int25:1;
        RBus_UInt32  int26:1;
        RBus_UInt32  int27:1;
        RBus_UInt32  int28:1;
        RBus_UInt32  int29:1;
        RBus_UInt32  int30:1;
    };
}mis_gpio_isr_gp0a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int31:1;
        RBus_UInt32  int32:1;
        RBus_UInt32  int33:1;
        RBus_UInt32  int34:1;
        RBus_UInt32  int35:1;
        RBus_UInt32  int36:1;
        RBus_UInt32  int37:1;
        RBus_UInt32  int38:1;
        RBus_UInt32  int39:1;
        RBus_UInt32  int40:1;
        RBus_UInt32  int41:1;
        RBus_UInt32  int42:1;
        RBus_UInt32  int43:1;
        RBus_UInt32  int44:1;
        RBus_UInt32  int45:1;
        RBus_UInt32  int46:1;
        RBus_UInt32  int47:1;
        RBus_UInt32  int48:1;
        RBus_UInt32  int49:1;
        RBus_UInt32  int50:1;
        RBus_UInt32  int51:1;
        RBus_UInt32  int52:1;
        RBus_UInt32  int53:1;
        RBus_UInt32  int54:1;
        RBus_UInt32  int55:1;
        RBus_UInt32  int56:1;
        RBus_UInt32  int57:1;
        RBus_UInt32  int58:1;
        RBus_UInt32  int59:1;
        RBus_UInt32  int60:1;
        RBus_UInt32  int61:1;
    };
}mis_gpio_isr_gp1a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int62:1;
        RBus_UInt32  int63:1;
        RBus_UInt32  int64:1;
        RBus_UInt32  int65:1;
        RBus_UInt32  int66:1;
        RBus_UInt32  int67:1;
        RBus_UInt32  int68:1;
        RBus_UInt32  int69:1;
        RBus_UInt32  int70:1;
        RBus_UInt32  int71:1;
        RBus_UInt32  int72:1;
        RBus_UInt32  int73:1;
        RBus_UInt32  int74:1;
        RBus_UInt32  int75:1;
        RBus_UInt32  int76:1;
        RBus_UInt32  int77:1;
        RBus_UInt32  int78:1;
        RBus_UInt32  int79:1;
        RBus_UInt32  int80:1;
        RBus_UInt32  int81:1;
        RBus_UInt32  int82:1;
        RBus_UInt32  int83:1;
        RBus_UInt32  int84:1;
        RBus_UInt32  int85:1;
        RBus_UInt32  int86:1;
        RBus_UInt32  int87:1;
        RBus_UInt32  int88:1;
        RBus_UInt32  int89:1;
        RBus_UInt32  int90:1;
        RBus_UInt32  int91:1;
        RBus_UInt32  int92:1;
    };
}mis_gpio_isr_gp2a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int93:1;
        RBus_UInt32  int94:1;
        RBus_UInt32  int95:1;
        RBus_UInt32  int96:1;
        RBus_UInt32  int97:1;
        RBus_UInt32  int98:1;
        RBus_UInt32  int99:1;
        RBus_UInt32  int100:1;
        RBus_UInt32  int101:1;
        RBus_UInt32  int102:1;
        RBus_UInt32  int103:1;
        RBus_UInt32  int104:1;
        RBus_UInt32  int105:1;
        RBus_UInt32  int106:1;
        RBus_UInt32  int107:1;
        RBus_UInt32  int108:1;
        RBus_UInt32  int109:1;
        RBus_UInt32  int110:1;
        RBus_UInt32  int111:1;
        RBus_UInt32  int112:1;
        RBus_UInt32  int113:1;
        RBus_UInt32  int114:1;
        RBus_UInt32  int115:1;
        RBus_UInt32  int116:1;
        RBus_UInt32  int117:1;
        RBus_UInt32  int118:1;
        RBus_UInt32  int119:1;
        RBus_UInt32  int120:1;
        RBus_UInt32  int121:1;
        RBus_UInt32  int122:1;
        RBus_UInt32  int123:1;
    };
}mis_gpio_isr_gp3a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int124:1;
        RBus_UInt32  int125:1;
        RBus_UInt32  int126:1;
        RBus_UInt32  int127:1;
        RBus_UInt32  int128:1;
        RBus_UInt32  int129:1;
        RBus_UInt32  int130:1;
        RBus_UInt32  int131:1;
        RBus_UInt32  int132:1;
        RBus_UInt32  int133:1;
        RBus_UInt32  int134:1;
        RBus_UInt32  int135:1;
        RBus_UInt32  int136:1;
        RBus_UInt32  int137:1;
        RBus_UInt32  int138:1;
        RBus_UInt32  int139:1;
        RBus_UInt32  int140:1;
        RBus_UInt32  int141:1;
        RBus_UInt32  int142:1;
        RBus_UInt32  int143:1;
        RBus_UInt32  int144:1;
        RBus_UInt32  int145:1;
        RBus_UInt32  int146:1;
        RBus_UInt32  int147:1;
        RBus_UInt32  int148:1;
        RBus_UInt32  int149:1;
        RBus_UInt32  int150:1;
        RBus_UInt32  int151:1;
        RBus_UInt32  int152:1;
        RBus_UInt32  int153:1;
        RBus_UInt32  int154:1;
    };
}mis_gpio_isr_gp4a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int155:1;
        RBus_UInt32  int156:1;
        RBus_UInt32  int157:1;
        RBus_UInt32  int158:1;
        RBus_UInt32  int159:1;
        RBus_UInt32  int160:1;
        RBus_UInt32  int161:1;
        RBus_UInt32  int162:1;
        RBus_UInt32  int163:1;
        RBus_UInt32  int164:1;
        RBus_UInt32  int165:1;
        RBus_UInt32  int166:1;
        RBus_UInt32  int167:1;
        RBus_UInt32  int168:1;
        RBus_UInt32  int169:1;
        RBus_UInt32  int170:1;
        RBus_UInt32  int171:1;
        RBus_UInt32  int172:1;
        RBus_UInt32  int173:1;
        RBus_UInt32  int174:1;
        RBus_UInt32  int175:1;
        RBus_UInt32  int176:1;
        RBus_UInt32  int177:1;
        RBus_UInt32  int178:1;
        RBus_UInt32  int179:1;
        RBus_UInt32  int180:1;
        RBus_UInt32  int181:1;
        RBus_UInt32  int182:1;
        RBus_UInt32  int183:1;
        RBus_UInt32  int184:1;
        RBus_UInt32  int185:1;
    };
}mis_gpio_isr_gp5a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int186:1;
        RBus_UInt32  int187:1;
        RBus_UInt32  int188:1;
        RBus_UInt32  int189:1;
        RBus_UInt32  int190:1;
        RBus_UInt32  res1:26;
    };
}mis_gpio_isr_gp6a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int0:1;
        RBus_UInt32  int1:1;
        RBus_UInt32  int2:1;
        RBus_UInt32  int3:1;
        RBus_UInt32  int4:1;
        RBus_UInt32  int5:1;
        RBus_UInt32  int6:1;
        RBus_UInt32  int7:1;
        RBus_UInt32  int8:1;
        RBus_UInt32  int9:1;
        RBus_UInt32  int10:1;
        RBus_UInt32  int11:1;
        RBus_UInt32  int12:1;
        RBus_UInt32  int13:1;
        RBus_UInt32  int14:1;
        RBus_UInt32  int15:1;
        RBus_UInt32  int16:1;
        RBus_UInt32  int17:1;
        RBus_UInt32  int18:1;
        RBus_UInt32  int19:1;
        RBus_UInt32  int20:1;
        RBus_UInt32  int21:1;
        RBus_UInt32  int22:1;
        RBus_UInt32  int23:1;
        RBus_UInt32  int24:1;
        RBus_UInt32  int25:1;
        RBus_UInt32  int26:1;
        RBus_UInt32  int27:1;
        RBus_UInt32  int28:1;
        RBus_UInt32  int29:1;
        RBus_UInt32  int30:1;
    };
}mis_gpio_isr_gp0da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int31:1;
        RBus_UInt32  int32:1;
        RBus_UInt32  int33:1;
        RBus_UInt32  int34:1;
        RBus_UInt32  int35:1;
        RBus_UInt32  int36:1;
        RBus_UInt32  int37:1;
        RBus_UInt32  int38:1;
        RBus_UInt32  int39:1;
        RBus_UInt32  int40:1;
        RBus_UInt32  int41:1;
        RBus_UInt32  int42:1;
        RBus_UInt32  int43:1;
        RBus_UInt32  int44:1;
        RBus_UInt32  int45:1;
        RBus_UInt32  int46:1;
        RBus_UInt32  int47:1;
        RBus_UInt32  int48:1;
        RBus_UInt32  int49:1;
        RBus_UInt32  int50:1;
        RBus_UInt32  int51:1;
        RBus_UInt32  int52:1;
        RBus_UInt32  int53:1;
        RBus_UInt32  int54:1;
        RBus_UInt32  int55:1;
        RBus_UInt32  int56:1;
        RBus_UInt32  int57:1;
        RBus_UInt32  int58:1;
        RBus_UInt32  int59:1;
        RBus_UInt32  int60:1;
        RBus_UInt32  int61:1;
    };
}mis_gpio_isr_gp1da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int62:1;
        RBus_UInt32  int63:1;
        RBus_UInt32  int64:1;
        RBus_UInt32  int65:1;
        RBus_UInt32  int66:1;
        RBus_UInt32  int67:1;
        RBus_UInt32  int68:1;
        RBus_UInt32  int69:1;
        RBus_UInt32  int70:1;
        RBus_UInt32  int71:1;
        RBus_UInt32  int72:1;
        RBus_UInt32  int73:1;
        RBus_UInt32  int74:1;
        RBus_UInt32  int75:1;
        RBus_UInt32  int76:1;
        RBus_UInt32  int77:1;
        RBus_UInt32  int78:1;
        RBus_UInt32  int79:1;
        RBus_UInt32  int80:1;
        RBus_UInt32  int81:1;
        RBus_UInt32  int82:1;
        RBus_UInt32  int83:1;
        RBus_UInt32  int84:1;
        RBus_UInt32  int85:1;
        RBus_UInt32  int86:1;
        RBus_UInt32  int87:1;
        RBus_UInt32  int88:1;
        RBus_UInt32  int89:1;
        RBus_UInt32  int90:1;
        RBus_UInt32  int91:1;
        RBus_UInt32  int92:1;
    };
}mis_gpio_isr_gp2da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int93:1;
        RBus_UInt32  int94:1;
        RBus_UInt32  int95:1;
        RBus_UInt32  int96:1;
        RBus_UInt32  int97:1;
        RBus_UInt32  int98:1;
        RBus_UInt32  int99:1;
        RBus_UInt32  int100:1;
        RBus_UInt32  int101:1;
        RBus_UInt32  int102:1;
        RBus_UInt32  int103:1;
        RBus_UInt32  int104:1;
        RBus_UInt32  int105:1;
        RBus_UInt32  int106:1;
        RBus_UInt32  int107:1;
        RBus_UInt32  int108:1;
        RBus_UInt32  int109:1;
        RBus_UInt32  int110:1;
        RBus_UInt32  int111:1;
        RBus_UInt32  int112:1;
        RBus_UInt32  int113:1;
        RBus_UInt32  int114:1;
        RBus_UInt32  int115:1;
        RBus_UInt32  int116:1;
        RBus_UInt32  int117:1;
        RBus_UInt32  int118:1;
        RBus_UInt32  int119:1;
        RBus_UInt32  int120:1;
        RBus_UInt32  int121:1;
        RBus_UInt32  int122:1;
        RBus_UInt32  int123:1;
    };
}mis_gpio_isr_gp3da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int124:1;
        RBus_UInt32  int125:1;
        RBus_UInt32  int126:1;
        RBus_UInt32  int127:1;
        RBus_UInt32  int128:1;
        RBus_UInt32  int129:1;
        RBus_UInt32  int130:1;
        RBus_UInt32  int131:1;
        RBus_UInt32  int132:1;
        RBus_UInt32  int133:1;
        RBus_UInt32  int134:1;
        RBus_UInt32  int135:1;
        RBus_UInt32  int136:1;
        RBus_UInt32  int137:1;
        RBus_UInt32  int138:1;
        RBus_UInt32  int139:1;
        RBus_UInt32  int140:1;
        RBus_UInt32  int141:1;
        RBus_UInt32  int142:1;
        RBus_UInt32  int143:1;
        RBus_UInt32  int144:1;
        RBus_UInt32  int145:1;
        RBus_UInt32  int146:1;
        RBus_UInt32  int147:1;
        RBus_UInt32  int148:1;
        RBus_UInt32  int149:1;
        RBus_UInt32  int150:1;
        RBus_UInt32  int151:1;
        RBus_UInt32  int152:1;
        RBus_UInt32  int153:1;
        RBus_UInt32  int154:1;
    };
}mis_gpio_isr_gp4da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int155:1;
        RBus_UInt32  int156:1;
        RBus_UInt32  int157:1;
        RBus_UInt32  int158:1;
        RBus_UInt32  int159:1;
        RBus_UInt32  int160:1;
        RBus_UInt32  int161:1;
        RBus_UInt32  int162:1;
        RBus_UInt32  int163:1;
        RBus_UInt32  int164:1;
        RBus_UInt32  int165:1;
        RBus_UInt32  int166:1;
        RBus_UInt32  int167:1;
        RBus_UInt32  int168:1;
        RBus_UInt32  int169:1;
        RBus_UInt32  int170:1;
        RBus_UInt32  int171:1;
        RBus_UInt32  int172:1;
        RBus_UInt32  int173:1;
        RBus_UInt32  int174:1;
        RBus_UInt32  int175:1;
        RBus_UInt32  int176:1;
        RBus_UInt32  int177:1;
        RBus_UInt32  int178:1;
        RBus_UInt32  int179:1;
        RBus_UInt32  int180:1;
        RBus_UInt32  int181:1;
        RBus_UInt32  int182:1;
        RBus_UInt32  int183:1;
        RBus_UInt32  int184:1;
        RBus_UInt32  int185:1;
    };
}mis_gpio_isr_gp5da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int186:1;
        RBus_UInt32  int187:1;
        RBus_UInt32  int188:1;
        RBus_UInt32  int189:1;
        RBus_UInt32  int190:1;
        RBus_UInt32  res1:26;
    };
}mis_gpio_isr_gp6da_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intsel:2;
        RBus_UInt32  res1:30;
    };
}mis_gpio_gp_int_sel_RBUS;




#endif 


#endif 
