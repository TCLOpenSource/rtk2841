// This file is generated using the spec version 1.39, firmware template version 1.39and SRIF Parser                                                                                source code SVN rev:780                    Version flow no.:1.1.20
#ifndef _RTC_REG_H_INCLUDED_
#define _RTC_REG_H_INCLUDED_

//#define  _RTC_USE_STRUCT
#ifdef _RTC_USE_STRUCT

typedef struct
{
    unsigned int    reserved_0:25;
    unsigned int    rtcsec:7;
}MIS_rtcsec;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    rtcmin:6;
}MIS_rtcmin;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    rtchr:5;
}MIS_rtchr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rtcdate1:8;
}MIS_rtcdate1;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    rtcdate2:6;
}MIS_rtcdate2;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    almmin:6;
}MIS_almmin;

typedef struct
{
    unsigned int    reserved_0:27;
    unsigned int    almhr:5;
}MIS_almhr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    almdate1:8;
}MIS_almdate1;

typedef struct
{
    unsigned int    reserved_0:26;
    unsigned int    almdate2:6;
}MIS_almdate2;

typedef struct
{
    unsigned int    reserved_0:31;
    unsigned int    rtcstop:1;
}MIS_rtcstop;

typedef struct
{
    unsigned int    reserved_0:29;
    unsigned int    clksel:1;
    unsigned int    bc:2;
}MIS_rtcacr;

typedef struct
{
    unsigned int    reserved_0:24;
    unsigned int    rtcen:8;
}MIS_rtcen;

typedef struct
{
    unsigned int    rtc_alarm_int:1;
    unsigned int    rtc_date_int:1;
    unsigned int    rtc_hour_int:1;
    unsigned int    rtc_min_int:1;
    unsigned int    rtc_hsec_int:1;
    unsigned int    reserved_0:20;
    unsigned int    rtcrst:1;
    unsigned int    reserved_1:1;
    unsigned int    almen:1;
    unsigned int    dainte:1;
    unsigned int    huinte:1;
    unsigned int    muinte:1;
    unsigned int    hsuinte:1;
}MIS_rtccr;
#endif


#define MIS_RTCSEC                                                    0x18011f00
#define MIS_RTCSEC_reg_addr                                           "0xb8011f00"
#define MIS_RTCSEC_reg                                                0xb8011f00
#define MIS_RTCSEC_inst_addr                                          "0x03C0"
#define MIS_RTCSEC_inst                                               0x03C0
#define MIS_RTCSEC_rtcsec_shift                                       (0)
#define MIS_RTCSEC_rtcsec_mask                                        (0x0000007F)
#define MIS_RTCSEC_rtcsec(data)                                       (0x0000007F&(data))
#define MIS_RTCSEC_get_rtcsec(data)                                   (0x0000007F&(data))


#define MIS_RTCMIN                                                    0x18011f04
#define MIS_RTCMIN_reg_addr                                           "0xb8011f04"
#define MIS_RTCMIN_reg                                                0xb8011f04
#define MIS_RTCMIN_inst_addr                                          "0x03C1"
#define MIS_RTCMIN_inst                                               0x03C1
#define MIS_RTCMIN_rtcmin_shift                                       (0)
#define MIS_RTCMIN_rtcmin_mask                                        (0x0000003F)
#define MIS_RTCMIN_rtcmin(data)                                       (0x0000003F&(data))
#define MIS_RTCMIN_get_rtcmin(data)                                   (0x0000003F&(data))


#define MIS_RTCHR                                                     0x18011f08
#define MIS_RTCHR_reg_addr                                            "0xb8011f08"
#define MIS_RTCHR_reg                                                 0xb8011f08
#define MIS_RTCHR_inst_addr                                           "0x03C2"
#define MIS_RTCHR_inst                                                0x03C2
#define MIS_RTCHR_rtchr_shift                                         (0)
#define MIS_RTCHR_rtchr_mask                                          (0x0000001F)
#define MIS_RTCHR_rtchr(data)                                         (0x0000001F&(data))
#define MIS_RTCHR_get_rtchr(data)                                     (0x0000001F&(data))


#define MIS_RTCDATE1                                                  0x18011f0c
#define MIS_RTCDATE1_reg_addr                                         "0xb8011f0c"
#define MIS_RTCDATE1_reg                                              0xb8011f0c
#define MIS_RTCDATE1_inst_addr                                        "0x03C3"
#define MIS_RTCDATE1_inst                                             0x03C3
#define MIS_RTCDATE1_rtcdate1_shift                                   (0)
#define MIS_RTCDATE1_rtcdate1_mask                                    (0x000000FF)
#define MIS_RTCDATE1_rtcdate1(data)                                   (0x000000FF&(data))
#define MIS_RTCDATE1_get_rtcdate1(data)                               (0x000000FF&(data))


#define MIS_RTCDATE2                                                  0x18011f10
#define MIS_RTCDATE2_reg_addr                                         "0xb8011f10"
#define MIS_RTCDATE2_reg                                              0xb8011f10
#define MIS_RTCDATE2_inst_addr                                        "0x03C4"
#define MIS_RTCDATE2_inst                                             0x03C4
#define MIS_RTCDATE2_rtcdate2_shift                                   (0)
#define MIS_RTCDATE2_rtcdate2_mask                                    (0x0000003F)
#define MIS_RTCDATE2_rtcdate2(data)                                   (0x0000003F&(data))
#define MIS_RTCDATE2_get_rtcdate2(data)                               (0x0000003F&(data))


#define MIS_ALMMIN                                                    0x18011f14
#define MIS_ALMMIN_reg_addr                                           "0xb8011f14"
#define MIS_ALMMIN_reg                                                0xb8011f14
#define MIS_ALMMIN_inst_addr                                          "0x03C5"
#define MIS_ALMMIN_inst                                               0x03C5
#define MIS_ALMMIN_almmin_shift                                       (0)
#define MIS_ALMMIN_almmin_mask                                        (0x0000003F)
#define MIS_ALMMIN_almmin(data)                                       (0x0000003F&(data))
#define MIS_ALMMIN_get_almmin(data)                                   (0x0000003F&(data))


#define MIS_ALMHR                                                     0x18011f18
#define MIS_ALMHR_reg_addr                                            "0xb8011f18"
#define MIS_ALMHR_reg                                                 0xb8011f18
#define MIS_ALMHR_inst_addr                                           "0x03C6"
#define MIS_ALMHR_inst                                                0x03C6
#define MIS_ALMHR_almhr_shift                                         (0)
#define MIS_ALMHR_almhr_mask                                          (0x0000001F)
#define MIS_ALMHR_almhr(data)                                         (0x0000001F&(data))
#define MIS_ALMHR_get_almhr(data)                                     (0x0000001F&(data))


#define MIS_ALMDATE1                                                  0x18011f1c
#define MIS_ALMDATE1_reg_addr                                         "0xb8011f1c"
#define MIS_ALMDATE1_reg                                              0xb8011f1c
#define MIS_ALMDATE1_inst_addr                                        "0x03C7"
#define MIS_ALMDATE1_inst                                             0x03C7
#define MIS_ALMDATE1_almdate1_shift                                   (0)
#define MIS_ALMDATE1_almdate1_mask                                    (0x000000FF)
#define MIS_ALMDATE1_almdate1(data)                                   (0x000000FF&(data))
#define MIS_ALMDATE1_get_almdate1(data)                               (0x000000FF&(data))


#define MIS_ALMDATE2                                                  0x18011f20
#define MIS_ALMDATE2_reg_addr                                         "0xb8011f20"
#define MIS_ALMDATE2_reg                                              0xb8011f20
#define MIS_ALMDATE2_inst_addr                                        "0x03C8"
#define MIS_ALMDATE2_inst                                             0x03C8
#define MIS_ALMDATE2_almdate2_shift                                   (0)
#define MIS_ALMDATE2_almdate2_mask                                    (0x0000003F)
#define MIS_ALMDATE2_almdate2(data)                                   (0x0000003F&(data))
#define MIS_ALMDATE2_get_almdate2(data)                               (0x0000003F&(data))


#define MIS_RTCSTOP                                                   0x18011f24
#define MIS_RTCSTOP_reg_addr                                          "0xb8011f24"
#define MIS_RTCSTOP_reg                                               0xb8011f24
#define MIS_RTCSTOP_inst_addr                                         "0x03C9"
#define MIS_RTCSTOP_inst                                              0x03C9
#define MIS_RTCSTOP_rtcstop_shift                                     (0)
#define MIS_RTCSTOP_rtcstop_mask                                      (0x00000001)
#define MIS_RTCSTOP_rtcstop(data)                                     (0x00000001&(data))
#define MIS_RTCSTOP_get_rtcstop(data)                                 (0x00000001&(data))


#define MIS_RTCACR                                                    0x18011f28
#define MIS_RTCACR_reg_addr                                           "0xb8011f28"
#define MIS_RTCACR_reg                                                0xb8011f28
#define MIS_RTCACR_inst_addr                                          "0x03CA"
#define MIS_RTCACR_inst                                               0x03CA
#define MIS_RTCACR_clksel_shift                                       (2)
#define MIS_RTCACR_bc_shift                                           (0)
#define MIS_RTCACR_clksel_mask                                        (0x00000004)
#define MIS_RTCACR_bc_mask                                            (0x00000003)
#define MIS_RTCACR_clksel(data)                                       (0x00000004&((data)<<2))
#define MIS_RTCACR_bc(data)                                           (0x00000003&(data))
#define MIS_RTCACR_get_clksel(data)                                   ((0x00000004&(data))>>2)
#define MIS_RTCACR_get_bc(data)                                       (0x00000003&(data))


#define MIS_RTCEN                                                     0x18011f2c
#define MIS_RTCEN_reg_addr                                            "0xb8011f2c"
#define MIS_RTCEN_reg                                                 0xb8011f2c
#define MIS_RTCEN_inst_addr                                           "0x03CB"
#define MIS_RTCEN_inst                                                0x03CB
#define MIS_RTCEN_rtcen_shift                                         (0)
#define MIS_RTCEN_rtcen_mask                                          (0x000000FF)
#define MIS_RTCEN_rtcen(data)                                         (0x000000FF&(data))
#define MIS_RTCEN_get_rtcen(data)                                     (0x000000FF&(data))


#define MIS_RTCCR                                                     0x18011f30
#define MIS_RTCCR_reg_addr                                            "0xb8011f30"
#define MIS_RTCCR_reg                                                 0xb8011f30
#define MIS_RTCCR_inst_addr                                           "0x03CC"
#define MIS_RTCCR_inst                                                0x03CC
#define MIS_RTCCR_rtc_alarm_int_shift                                 (31)
#define MIS_RTCCR_rtc_date_int_shift                                  (30)
#define MIS_RTCCR_rtc_hour_int_shift                                  (29)
#define MIS_RTCCR_rtc_min_int_shift                                   (28)
#define MIS_RTCCR_rtc_hsec_int_shift                                  (27)
#define MIS_RTCCR_rtcrst_shift                                        (6)
#define MIS_RTCCR_almen_shift                                         (4)
#define MIS_RTCCR_dainte_shift                                        (3)
#define MIS_RTCCR_huinte_shift                                        (2)
#define MIS_RTCCR_muinte_shift                                        (1)
#define MIS_RTCCR_hsuinte_shift                                       (0)
#define MIS_RTCCR_rtc_alarm_int_mask                                  (0x80000000)
#define MIS_RTCCR_rtc_date_int_mask                                   (0x40000000)
#define MIS_RTCCR_rtc_hour_int_mask                                   (0x20000000)
#define MIS_RTCCR_rtc_min_int_mask                                    (0x10000000)
#define MIS_RTCCR_rtc_hsec_int_mask                                   (0x08000000)
#define MIS_RTCCR_rtcrst_mask                                         (0x00000040)
#define MIS_RTCCR_almen_mask                                          (0x00000010)
#define MIS_RTCCR_dainte_mask                                         (0x00000008)
#define MIS_RTCCR_huinte_mask                                         (0x00000004)
#define MIS_RTCCR_muinte_mask                                         (0x00000002)
#define MIS_RTCCR_hsuinte_mask                                        (0x00000001)
#define MIS_RTCCR_rtc_alarm_int(data)                                 (0x80000000&((data)<<31))
#define MIS_RTCCR_rtc_date_int(data)                                  (0x40000000&((data)<<30))
#define MIS_RTCCR_rtc_hour_int(data)                                  (0x20000000&((data)<<29))
#define MIS_RTCCR_rtc_min_int(data)                                   (0x10000000&((data)<<28))
#define MIS_RTCCR_rtc_hsec_int(data)                                  (0x08000000&((data)<<27))
#define MIS_RTCCR_rtcrst(data)                                        (0x00000040&((data)<<6))
#define MIS_RTCCR_almen(data)                                         (0x00000010&((data)<<4))
#define MIS_RTCCR_dainte(data)                                        (0x00000008&((data)<<3))
#define MIS_RTCCR_huinte(data)                                        (0x00000004&((data)<<2))
#define MIS_RTCCR_muinte(data)                                        (0x00000002&((data)<<1))
#define MIS_RTCCR_hsuinte(data)                                       (0x00000001&(data))
#define MIS_RTCCR_get_rtc_alarm_int(data)                             ((0x80000000&(data))>>31)
#define MIS_RTCCR_get_rtc_date_int(data)                              ((0x40000000&(data))>>30)
#define MIS_RTCCR_get_rtc_hour_int(data)                              ((0x20000000&(data))>>29)
#define MIS_RTCCR_get_rtc_min_int(data)                               ((0x10000000&(data))>>28)
#define MIS_RTCCR_get_rtc_hsec_int(data)                              ((0x08000000&(data))>>27)
#define MIS_RTCCR_get_rtcrst(data)                                    ((0x00000040&(data))>>6)
#define MIS_RTCCR_get_almen(data)                                     ((0x00000010&(data))>>4)
#define MIS_RTCCR_get_dainte(data)                                    ((0x00000008&(data))>>3)
#define MIS_RTCCR_get_huinte(data)                                    ((0x00000004&(data))>>2)
#define MIS_RTCCR_get_muinte(data)                                    ((0x00000002&(data))>>1)
#define MIS_RTCCR_get_hsuinte(data)                                   (0x00000001&(data))
#endif
