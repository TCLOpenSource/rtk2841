/*=========================================================================== */
/*o------ initial function ------o */
/*=========================================================================== */
#ifndef _OSD_SR_DRIVER_H
#define _OSD_SR_DRIVER_H

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

typedef enum _OSD_SR_CH_SEL {
    OSD1_SR,
    OSD2_SR,
    OSD3_SR,
    OSD4_SR,
    OSD5_SR,
} OSD_SR_CH_SEL;

typedef enum _PANEL_PIXEL_NUMBER {
    PANEL_1PIXEL = 0,
    PANEL_2PIXEL,
    PANEL_4PIXEL,
} PANEL_PIXEL_NUMBER;

void drv_superresolution_init(void);
void drv_superresolution_LPF_Gain(GDMA_DISPLAY_PLANE plane);
void drv_superresolution_ch_switch(GDMA_DISPLAY_PLANE src, OSD_SR_CH_SEL dest);

void drv_scaleup_init(void);
int drv_scaleup(uint8_t enable, GDMA_DISPLAY_PLANE disPlane);

int osd_sr_init_module(void);
void osd_sr_cleanup_module(void);
void osd_sr_db_apply(void);
int osd_sr_configLocation(GDMA_DISPLAY_PLANE disPlane, int x, int y);
int osd_sr_check_onoff_status(GDMA_DISPLAY_PLANE disPlane);

#endif		/* end of _OSD_SR_DRIVER_H */
