#ifndef __HDMI_ARC_H__
#define __HDMI_ARC_H__

extern int hdmi_arc_init(void);
extern int hdmi_arc_enable(unsigned char en);
extern int hdmi_arc_get_status(void);
extern int hdmi_arc_get_spdif_channel(void);

#endif // __HDMI_ARC_H__
