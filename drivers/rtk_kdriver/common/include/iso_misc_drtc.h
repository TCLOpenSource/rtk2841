#ifndef _ISO_MISC_DRTC_H_
#define _ISO_MISC_DRTC_H_
/* ISO RTC */
#define	ISO_RTC_BASE                (0xb8061900)
#define	ISO_RTCSEC                  (ISO_RTC_BASE+0x1900)
#define	ISO_RTCMIN                  (ISO_RTC_BASE+0x1904)
#define	ISO_RTCHR                   (ISO_RTC_BASE+0x1908)
#define	ISO_RTCDATE1                (ISO_RTC_BASE+0x190C)
#define	ISO_RTCDATE2                (ISO_RTC_BASE+0x1910)
#define	ISO_ALMMIN                  (ISO_RTC_BASE+0x1914)
#define	ISO_ALMHR                   (ISO_RTC_BASE+0x1918)
#define	ISO_ALMDATE1                (ISO_RTC_BASE+0x191C)
#define	ISO_ALMDATE2                (ISO_RTC_BASE+0x1920)
#define	ISO_RTCSTOP                 (ISO_RTC_BASE+0x1924)
#define	ISO_RTCACR                  (ISO_RTC_BASE+0x1928)
#define	ISO_RTCEN                   (ISO_RTC_BASE+0x192C)
#define	ISO_RTCCR                   (ISO_RTC_BASE+0x1930)
#endif