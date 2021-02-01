#ifndef __RTK_DDC_LIB_H__
#define __RTK_DDC_LIB_H__

#define HDMI_DDC_COUNT      (3)
#define RTK_VGA_DDC         (0)
#define RTK_HDMI_DDC(x)     (1+x)
#define RTK_MHL_DDC         (4) 


// for low level API
void rtk_ddc_lib_crt_on(void);

int  rtk_ddc_lib_sync_reset(unsigned char id);

int  rtk_ddc_lib_set_write_debounce(unsigned char id, unsigned char clock);

int  rtk_ddc_lib_write_edid(unsigned char id, unsigned char *edid_tbl, unsigned int len);

int  rtk_ddc_lib_read_edid(unsigned char id, unsigned char *edid_tbl, unsigned int len);

int  rtk_ddc_lib_enable(unsigned char id, unsigned char enable);

int  rtk_ddc_lib_set_sda_delay(unsigned char id, unsigned char delay_sel);

// for VGA DDC
#define rtk_vddc_crt_on                             rtk_ddc_lib_crt_on()
#define rtk_vddc_sync_reset()                       rtk_ddc_lib_sync_reset(RTK_VGA_DDC)   
#define rtk_vddc_set_write_debounce(clock)          rtk_ddc_lib_set_write_debounce(RTK_VGA_DDC, clock)
#define rtk_vddc_write_edid(edid_tbl, len)          rtk_ddc_lib_write_edid(RTK_VGA_DDC, edid_tbl, len)
#define rtk_vddc_read_edid(edid_tbl, len)           rtk_ddc_lib_read_edid(RTK_VGA_DDC, edid_tbl, len)
#define rtk_vddc_enable(enable)                     rtk_ddc_lib_enable(RTK_VGA_DDC, enable)
#define rtk_vddc_lib_set_sda_delay(delay_sel)       rtk_ddc_lib_set_sda_delay(RTK_VGA_DDC, delay_sel)

// for HDMI DDC
#define rtk_hddc_crt_on                             rtk_ddc_lib_crt_on()
#define rtk_hddc_sync_reset(id)                     rtk_ddc_lib_sync_reset(RTK_HDMI_DDC(id))   
#define rtk_hddc_set_write_debounce(id,clock)       rtk_ddc_lib_set_write_debounce(RTK_HDMI_DDC(id), clock)
#define rtk_hddc_write_edid(id, edid_tbl, len)      rtk_ddc_lib_write_edid(RTK_HDMI_DDC(id), edid_tbl, len)
#define rtk_hddc_read_edid(id,edid_tbl, len)        rtk_ddc_lib_read_edid(RTK_HDMI_DDC(id), edid_tbl, len)
#define rtk_hddc_enable(id,enable)                  rtk_ddc_lib_enable(RTK_HDMI_DDC(id), enable)
#define rtk_hddc_lib_set_sda_delay(id,delay_sel)    rtk_ddc_lib_set_sda_delay(RTK_HDMI_DDC(id), delay_sel)

// for MHL DDC
#define rtk_mhl_ddc_crt_on                             rtk_ddc_lib_crt_on()
#define rtk_mhl_ddc_sync_reset()                       rtk_ddc_lib_sync_reset(RTK_MHL_DDC)   
#define rtk_mhl_ddc_set_write_debounce(clock)          rtk_ddc_lib_set_write_debounce(RTK_MHL_DDC, clock)
#define rtk_mhl_ddc_write_edid(edid_tbl, len)          rtk_ddc_lib_write_edid(RTK_MHL_DDC, edid_tbl, len)
#define rtk_mhl_ddc_read_edid(edid_tbl, len)           rtk_ddc_lib_read_edid(RTK_MHL_DDC, edid_tbl, len)
#define rtk_mhl_ddc_enable(enable)                     rtk_ddc_lib_enable(RTK_MHL_DDC, enable)
#define rtk_mhl_ddc_lib_set_sda_delay(delay_sel)       rtk_ddc_lib_set_sda_delay(RTK_MHL_DDC, delay_sel)


#endif  // __RTK_DDC_LIB_H__
