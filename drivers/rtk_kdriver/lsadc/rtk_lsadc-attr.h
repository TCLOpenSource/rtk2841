#ifndef __RTK_LSADC_ATTR_H__
#define __RTK_LSADC_ATTR_H__

extern int log_onoff;

int rtk_lsadc_dev_attr_init(struct class * cls);
void rtk_lsadc_dev_attr_unint(void);

int  rtk_lsadc_create_class_attr(struct class *class);
void  rtk_lsadc_remove_class_attr(struct class *class);


int  rtk_lsadc_create_attr(struct device *device);
void rtk_lsadc_remove_attr(struct device *device);

#endif /*__RTK_LSADC_ATTR_H__ */
