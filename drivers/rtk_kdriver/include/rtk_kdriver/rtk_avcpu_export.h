#ifndef _LINUX_RTK_AVCPU_EXPORT_H
#define _LINUX_RTK_AVCPU_EXPORT_H

#define SCPU_STR_STATUS_FLAG_ADDR	0x00000820
#define SCPU_STR_STATUS_SUSPEND_BEGIN	0x2379beef
#define SCPU_STR_STATUS_SUSPEND_CLEAR	0x23792379

extern int resetav_lock(int is_suspend);
extern int resetav_unlock(int is_suspend);
extern int load_av_image(char *, unsigned int, char *, unsigned int, char *, unsigned int);

#endif
