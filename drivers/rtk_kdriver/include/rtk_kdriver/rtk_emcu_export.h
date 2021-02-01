#ifndef _RTK_EMCU_EXPORT_H_
#define _RTK_EMCU_EXPORT_H_

#define SUSPEND_BOOTCODE    0
#define SUSPEND_NORMAL      1
#define SUSPEND_RAM         2
#define SUSPEND_WAKEUP      3


typedef enum {
    WKSOR_UNDEF,    // 0: undefine
    WKSOR_KEYPAD,   // 1: wakeup via keypad
    WKSOR_WUT,      // 2: wakeup via timer
    WKSOR_IRDA,     // 3: wakeup via remote control
    WKSOR_CEC,      // 4: wakeup via CEC
    WKSOR_PPS,      // 5: wakeup via VGA
    WKSOR_WOW,      // 6: wakeup via WOW
    WKSOR_MHL,      // 7: wakeup via HML
    WKSOR_RTC,      // 8: wakeup via RTC
    WKSOR_WOV,      // 9: wakeup via voice
    WKSOR_END,      //end
} WAKE_UP_T;

int powerMgr_get_wakeup_source(unsigned int* row, unsigned int* status);

#endif



