#include "irrc_sysfs.h"

extern unsigned char ir_boot_remoter[32];
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
extern IR_Keycode_List intercept_keycode_list;
#endif
extern uint32_t ir_disable_irda_decode_key;
extern void ir_decode_key_on_off(bool on) ;

const char* ir_core_get_cur_remote_control_name(void);


static ssize_t ir_protocol_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    unsigned int i = 0;

    sprintf(buf, "\nThe current selection is [%d] %s\n", ir_support_protocols[0],
            irda_proto_list[ir_support_protocols[0]].proto_name);

    for(i = 1; i < IRDA_PROTO_LIST_SIZE ; i++) {
        sprintf((buf + strlen(buf)), "\n[%d] %s", irda_proto_list[i].proto_id, irda_proto_list[i].proto_name);
    }

    sprintf((buf + strlen(buf)), "\n\nYou can \"echo id > /sys/venus_ir/ir_protocol\" to switch protocol\n");

    return strlen(buf);
}

static ssize_t ir_protocol_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    /*if(ir_boot_sel_protocol > 0)
        return -EINVAL;
    */

    if (sscanf(buf, "%d", &val) == 1) {

        if(val >= 0 && val < IRDA_PROTO_LIST_SIZE) {
            ir_support_protocols[0] = val;
            ir_protocol = val;

            spin_lock(&ir_lock);
            if(IR_Init(ir_support_protocols[0], ir_support_protocols[1], ON) == 0)
                kfifo_reset(&ir_fifo);
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
            ir_boot_remoter[0] = 0;
            venus_ir_input_set_input_dev_name(ir_core_get_cur_remote_control_name());  
#endif    
            spin_unlock(&ir_lock);

            return n;
        } else {
            IR_WARNING("You don't select any current irda protocol\n");
        }
    }

    return -EINVAL;
}

ir_attr(ir_protocol);

static ssize_t ir_protocol_main0_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", ir_support_protocols[1]);
}

static ssize_t ir_protocol_main0_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        ir_support_protocols[1] = val;
        ir_protocol = val;

        spin_lock(&ir_lock);
        if(IR_Init(ir_support_protocols[0], ir_support_protocols[1], ON) == 0)
            kfifo_reset(&ir_fifo);
        spin_unlock(&ir_lock);

        return n;
    }

    return -EINVAL;
}

ir_attr(ir_protocol_main0);

static int ir_count_protocol_attr_value(unsigned int setting, unsigned int multiplication)
{
    unsigned int irsbc = 20;/*us*/
    return setting * irsbc * multiplication;
}

static int ir_get_register_bits_val(unsigned long reg, unsigned int msb,
                                    unsigned int lsb, unsigned int *val, unsigned int multiplication)
{
    unsigned int reg_val;
    if (msb < lsb || lsb > 31 || msb > 31 || val == NULL)
        return -1;
    ir_set_rx_detect_on_off(0);
    reg_val = rtd_inl(reg);
    reg_val = (reg_val & IR_BITS_MASK(msb, lsb)) >> lsb;
    ir_set_rx_detect_on_off(1);
    *val = ir_count_protocol_attr_value(reg_val, multiplication);
    return 0;
}

static int ir_get_protocol_attr(char *attr_name, unsigned int *val)
{
    int ret = 0;
    if(attr_name == NULL)
        return -1;
    if(strcmp(attr_name, "burst_lead") == 0)
        ret = ir_get_register_bits_val(REG_IR_PSR_RC5_RC6, 31, 24, val, 4);
    else if(strcmp(attr_name, "modulation") == 0)
        ret = ir_get_register_bits_val(REG_IR_PSR_RC5_RC6, 23, 16, val, 1);
    else if(strcmp(attr_name, "data0") == 0)
        ret = ir_get_register_bits_val(REG_IR_PSR_RC5_RC6, 15, 8, val, 1);
    else if(strcmp(attr_name, "data1") == 0)
        ret = ir_get_register_bits_val(REG_IR_PSR_RC5_RC6, 7, 0, val, 1);
    else if(strcmp(attr_name, "burst_repeat") == 0)
        ret = ir_get_register_bits_val(REG_IR_PER_RC5_RC6, 23, 16, val, 4);
    else if(strcmp(attr_name, "silence_repeat") == 0)
        ret = ir_get_register_bits_val(REG_IR_PER_RC5_RC6, 15, 8, val, 4);
    else if(strcmp(attr_name, "silence_lead") == 0)
        ret = ir_get_register_bits_val(REG_IR_PER_RC5_RC6, 7, 0, val, 4);

    else if(strcmp(attr_name, "burst_lead_up") == 0)
        ret = ir_get_register_bits_val(REG_IR_PSR_UP_RC5_RC6, 31, 24, val, 4);
    else if(strcmp(attr_name, "modulation_up") == 0)
        ret = ir_get_register_bits_val(REG_IR_PSR_UP_RC5_RC6, 23, 16, val, 1);
    else if(strcmp(attr_name, "data0_up") == 0)
        ret = ir_get_register_bits_val(REG_IR_PSR_UP_RC5_RC6, 15, 8, val, 1);
    else if(strcmp(attr_name, "data1_up") == 0)
        ret = ir_get_register_bits_val(REG_IR_PSR_UP_RC5_RC6, 7, 0, val, 1);
    else if(strcmp(attr_name, "burst_repeat_up") == 0)
        ret = ir_get_register_bits_val(REG_IR_PER_UP_RC5_RC6, 31, 24, val, 4);
    else if(strcmp(attr_name, "silence_repeat_up") == 0)
        ret = ir_get_register_bits_val(REG_IR_PER_UP_RC5_RC6, 23, 16, val, 4);
    else if(strcmp(attr_name, "end_pattern") == 0)
        ret = ir_get_register_bits_val(REG_IR_PER_UP_RC5_RC6, 15, 8, val, 4);
    else if(strcmp(attr_name, "silence_lead_up") == 0)
        ret = ir_get_register_bits_val(REG_IR_PER_UP_RC5_RC6, 7, 0, val, 4);
    else
        ret = -1;
    return ret;
}

static int ir_count_protocol_attr_setting(unsigned int val, unsigned int divide)
{
    unsigned int irsbc = 20;/*us*/
    unsigned int setting = 0;
    if(divide == 0)
        divide = 1;
    setting = val / (irsbc * divide);
    return setting;
}
static int ir_set_register_bits_val(unsigned long reg, unsigned int msb,
                                    unsigned int lsb, unsigned int val, unsigned int divide)
{
    unsigned int reg_val;
    if (msb < lsb || lsb > 31 || msb > 31)
        return -1;
    val = ir_count_protocol_attr_setting(val, divide);
    ir_set_rx_detect_on_off(0);
    reg_val = rtd_inl(reg);
    IR_DBG( "before %08x == %08x\n", reg, rtd_inl(reg));
    reg_val = (reg_val & (~IR_BITS_MASK(msb, lsb))) |
              ((val << lsb) & IR_BITS_MASK(msb, lsb));
    rtd_outl(reg, reg_val);
    IR_DBG( "after %08x == %08x\n", reg, rtd_inl(reg));
    ir_set_rx_detect_on_off(1);
    return 0;
}

static int ir_set_protocol_attr(char *attr_name, unsigned int val)
{
    int ret = 0;
    if(attr_name == NULL)
        return -1;
    if(strcmp(attr_name, "burst_lead") == 0)
        ret = ir_set_register_bits_val(REG_IR_PSR_RC5_RC6, 31, 24, val, 4);
    else if(strcmp(attr_name, "modulation") == 0)
        ret = ir_set_register_bits_val(REG_IR_PSR_RC5_RC6, 23, 16, val, 1);
    else if(strcmp(attr_name, "data0") == 0)
        ret = ir_set_register_bits_val(REG_IR_PSR_RC5_RC6, 15, 8, val, 1);
    else if(strcmp(attr_name, "data1") == 0)
        ret = ir_set_register_bits_val(REG_IR_PSR_RC5_RC6, 7, 0, val, 1);
    else if(strcmp(attr_name, "burst_repeat") == 0)
        ret = ir_set_register_bits_val(REG_IR_PER_RC5_RC6, 23, 16, val, 4);
    else if(strcmp(attr_name, "silence_repeat") == 0)
        ret = ir_set_register_bits_val(REG_IR_PER_RC5_RC6, 15, 8, val, 4);
    else if(strcmp(attr_name, "silence_lead") == 0)
        ret = ir_set_register_bits_val(REG_IR_PER_RC5_RC6, 7, 0, val, 4);

    else if(strcmp(attr_name, "burst_lead_up") == 0)
        ret = ir_set_register_bits_val(REG_IR_PSR_UP_RC5_RC6, 31, 24, val, 4);
    else if(strcmp(attr_name, "modulation_up") == 0)
        ret = ir_set_register_bits_val(REG_IR_PSR_UP_RC5_RC6, 23, 16, val, 1);
    else if(strcmp(attr_name, "data0_up") == 0)
        ret = ir_set_register_bits_val(REG_IR_PSR_UP_RC5_RC6, 15, 8, val, 1);
    else if(strcmp(attr_name, "data1_up") == 0)
        ret = ir_set_register_bits_val(REG_IR_PSR_UP_RC5_RC6, 7, 0, val, 1);
    else if(strcmp(attr_name, "burst_repeat_up") == 0)
        ret = ir_set_register_bits_val(REG_IR_PER_UP_RC5_RC6, 31, 24, val, 4);
    else if(strcmp(attr_name, "silence_repeat_up") == 0)
        ret = ir_set_register_bits_val(REG_IR_PER_UP_RC5_RC6, 23, 16, val, 4);
    else if(strcmp(attr_name, "end_pattern") == 0)
        ret = ir_set_register_bits_val(REG_IR_PER_UP_RC5_RC6, 15, 8, val, 4);
    else if(strcmp(attr_name, "silence_lead_up") == 0)
        ret = ir_set_register_bits_val(REG_IR_PER_UP_RC5_RC6, 7, 0, val, 4);
    else
        ret = -1;
    return ret;
}

static ssize_t ir_protocol_attr_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    unsigned int val = 0;
    if(ir_get_protocol_attr(protocol_attr_name, &val) == 0)
        return sprintf(buf, "the current setting of %s is %d(us)\n", protocol_attr_name, val);
    return 0;
}

static ssize_t ir_protocol_attr_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    unsigned char action[4];
    memset(action, 0, 4);

    if (sscanf(buf, "%3s", action) == 1) {
        IR_DBG( "ir_protocol_attr_store:buf == %s, action == %s\n", buf, action);
        if(strcmp(action, "set") == 0) {
            unsigned int val = 0;
            char attr_name[32] = {0};
            buf += 4;
            if (sscanf(buf, "%s%u", attr_name, &val) == 2) {
                IR_DBG( "ir_protocol_attr_store: set attr_name =%s val =%u\n", attr_name, val);
                if(ir_set_protocol_attr(attr_name, val) == 0)
                    return n;
                else
                    return -EINVAL;
            }
        } else if(strcmp(action, "get") == 0) {
            buf += 4;
            if (sscanf(buf, "%s", protocol_attr_name) == 1) {
                IR_DBG( "ir_protocol_attr_store:get attr_name = %s\n", protocol_attr_name);
                return n;
            } else {
                return -EINVAL;
            }
        }
    }

    return -EINVAL;
}
ir_attr(ir_protocol_attr);


static ssize_t ir_repeat_interval_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", ir_repeat_interval);
}

static ssize_t ir_repeat_interval_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        ir_repeat_interval = val;
        return n;
    }

    return -EINVAL;
}

ir_attr(ir_repeat_interval);

extern unsigned int debounce;
static ssize_t ir_debounce_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", debounce);
}

static ssize_t ir_debounce_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        debounce = val;
        return n;
    }

    return -EINVAL;
}

ir_attr(ir_debounce);

#ifdef CONFIG_DELAY_FIRST_REPEAT
extern unsigned int firstRepeatInterval;
static ssize_t ir_first_repeat_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", firstRepeatInterval);
}

static ssize_t ir_first_repeat_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        firstRepeatInterval = val;
        return n;
    }

    return -EINVAL;
}

ir_attr(ir_first_repeat);
#endif

static ssize_t ir_decode_debug_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    if (strcmp(attr->attr.name, "ir_decode_debug") == 0) {
        return sprintf(buf, "ir decode debug status:%s\n", ir_decode_dbg_en ? "enable" : "disable");
    }
    return 0;
}

static ssize_t ir_decode_debug_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t n)
{
    if(strcmp(attr->attr.name, "ir_decode_debug") == 0) {
        int val;
        if (sscanf(buf, "%d", &val) == 1) {
            ir_decode_dbg_en = val ? 1 : 0;
            return n;
        }
    }
    return -EINVAL;
}

ir_attr(ir_decode_debug);

static ssize_t ir_irda_key_decode_on_off_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "irda_key_on_off == %s\n", (ir_disable_irda_decode_key > 0) ? "on" : "off");
}

static ssize_t ir_irda_key_decode_on_off_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    uint32_t val = 0;
    if (sscanf(buf, "%u", &val) == 1) {
        val = (val == 0) ? 0 : 1;
        if(val) {
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
            del_timer_sync(&intercept_keycode_list.timer);
#endif
            ir_decode_key_on_off(OFF);
        } else {
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
            del_timer_sync(&intercept_keycode_list.timer);
#endif
            ir_decode_key_on_off(ON);
        }
        return n;
    }
    return -EINVAL;
}


ir_attr(ir_irda_key_decode_on_off);


#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
static unsigned int scancode = 0;
static unsigned int keycode = 0;

static ssize_t ir_gen_keycode_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return 0;
}

static ssize_t ir_gen_keycode_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t n)
{
    if(strcmp(attr->attr.name, "ir_gen_keycode") == 0) {
        if (sscanf(buf, "%x", &keycode) == 1) {
            venus_ir_gen_keyupdown_event(keycode);
            return n;
        }
    }
    return -EINVAL;
}

ir_attr(ir_gen_keycode);

static ssize_t ir_poll_interval_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "poll_enable = %d, interval = %d\n", ir_poll_enable, ir_poll_interval);
}

static ssize_t ir_poll_interval_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val, enable;

    if (sscanf(buf, "%d %d", &enable, &val) == 2) {
        ir_poll_enable = enable;
        ir_poll_interval = val;
        return n;
    }

    return -EINVAL;
}

ir_attr(ir_poll_interval);

static ssize_t ir_keycode_to_scancode_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "keycode = %d, scancode = 0x%x\n", keycode, scancode);
}

static ssize_t ir_keycode_to_scancode_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    if (sscanf(buf, "%d", &keycode) == 1) {
		scancode = venus_ir_keycode_to_scancode(keycode);
        return n;
    }

    return -EINVAL;
}

ir_attr(ir_keycode_to_scancode);

static ssize_t ir_mute_irda_keyevent_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "irda mute status = %s\n", ir_mute_flag ? "mute" : "unmute");
}

static ssize_t ir_mute_irda_keyevent_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int tmp;
    if (sscanf(buf, "%d", &tmp) == 1) {
        ir_mute_flag = tmp ? 1 : 0;
        return n;
    }
    return -EINVAL;
}

ir_attr(ir_mute_irda_keyevent);

static ssize_t ir_to_mouse_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", ir_to_mouse);
}

static ssize_t ir_to_mouse_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        ir_to_mouse = val;

        return n;
    }

    return -EINVAL;
}

ir_attr(ir_to_mouse);

static ssize_t ir_repeat_event_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", repeat_event);
}

static ssize_t ir_repeat_event_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        repeat_event = val;

        return n;
    }

    return -EINVAL;
}

ir_attr(ir_repeat_event);

static ssize_t ir_rawkey_event_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", rawkey_event);
}

static ssize_t ir_rawkey_event_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        rawkey_event = val;

        return n;
    }

    return -EINVAL;
}

ir_attr(ir_rawkey_event);

static ssize_t ir_report_mode_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    unsigned int i = 0;
    if (strcmp(attr->attr.name, "ir_report_mode") == 0)
    {
        sprintf(buf, "\nThe current selection is [%d] %s\n"
                ,ir_report_mode
                ,ir_report_mode_list[ir_report_mode].name);

        for(i = 0; i < IRDA_REPORT_MODE_MAX ; i++)
            sprintf((buf + strlen(buf)), "\n[%d] %s", i, ir_report_mode_list[i].name);

        sprintf((buf + strlen(buf)), "\n\nYou can \"echo id > /sys/venus_ir/ir_report_mode\" to switch report mode\n");
        return strlen(buf);
    }
    return 0;
}

static ssize_t ir_report_mode_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t n)
{
    if(0 == strcmp(attr->attr.name, "ir_report_mode"))
    {
        int val;
        if (sscanf(buf, "%d", &val) == 1)
        {
            if(IRDA_REPORT_MODE_NORMAL <= val
                    && val < IRDA_REPORT_MODE_MAX)
            {
                ir_report_mode = val;
            }
            else
            {
                IR_WARNING("you don't select any ir_report_mode and set it to %s\n"
                          ,ir_report_mode_list[ir_report_mode].name);
                n = -EINVAL;
            }
            return n;
        }
    }
    return -EINVAL;
}
ir_attr(ir_report_mode);

static ssize_t ir_is_upload_more_key_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    if (strcmp(attr->attr.name, "ir_is_upload_more_key") == 0)
    {
        return sprintf(buf, "ir_is_upload_more_key:%s\n", ir_is_upload_more_key?"enable" : "disable");;
    }
    return 0;
}

static ssize_t ir_is_upload_more_key_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t n)
{
    if(0 == strcmp(attr->attr.name, "ir_is_upload_more_key"))
    {
        int val;
        if (sscanf(buf, "%d", &val) == 1)
        {
            ir_is_upload_more_key = val ? 1 : 0;
            return n;
        }
    }
    return -EINVAL;
}
ir_attr(ir_is_upload_more_key);


static ssize_t ir_set_intercept_key_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "echo add/del,keycode >/sys/venus/ir_set_intercept_key\n");
}

static ssize_t ir_set_intercept_key_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    char action[4] = {0};
    u32 keycode = 0;
    u32 flags = 0;

    if (sscanf(buf, "%3s,%x, %x", action, &keycode, &flags) == 3) {
        if(strncmp(action, "add", 3) == 0) {
            ir_add_keycode_to_list(&intercept_keycode_list, keycode, flags);
        } else if(strncmp(action, "del", 3) == 0) {
            ir_remove_keycode_from_list(&intercept_keycode_list, keycode);
        } else {
            return -EINVAL;
        }
        return n;
    }

    return -EINVAL;
}


ir_attr(ir_set_intercept_key);


#endif

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE_MOUSE
extern int ir_mouse_pointer_speed;
extern int ir_mouse_pointer_threshold;
extern int ir_mouse_pointer_timer;
extern int ir_mouse_pointer_step;

static ssize_t ir_mouse_pointer_speed_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", ir_mouse_pointer_speed);
}

static ssize_t ir_mouse_pointer_speed_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        ir_mouse_pointer_speed = val;

        return n;
    }

    return -EINVAL;
}

ir_attr(ir_mouse_pointer_speed);

static ssize_t ir_mouse_pointer_threshold_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", ir_mouse_pointer_threshold);
}

static ssize_t ir_mouse_pointer_threshold_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        ir_mouse_pointer_threshold = val;

        return n;
    }

    return -EINVAL;
}

ir_attr(ir_mouse_pointer_threshold);

static ssize_t ir_mouse_pointer_timer_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", ir_mouse_pointer_timer);
}

static ssize_t ir_mouse_pointer_timer_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        ir_mouse_pointer_timer = val;

        return n;
    }

    return -EINVAL;
}

ir_attr(ir_mouse_pointer_timer);

static ssize_t ir_mouse_pointer_step_show(struct kobject * kobj, struct kobj_attribute * attr, char *buf)
{
    return sprintf(buf, "%d\n", ir_mouse_pointer_step);
}

static ssize_t ir_mouse_pointer_step_store(struct kobject * kobj, struct kobj_attribute * attr, const char *buf, size_t n)
{
    int val;

    if (sscanf(buf, "%d", &val) == 1) {
        ir_mouse_pointer_step = val;

        return n;
    }

    return -EINVAL;
}

ir_attr(ir_mouse_pointer_step);
#endif


static struct attribute * ir_attrs[] = {
    &ir_protocol_attr.attr,
    &ir_protocol_main0_attr.attr,
    &ir_protocol_attr_attr.attr,
    &ir_repeat_interval_attr.attr,
    &ir_debounce_attr.attr,
#ifdef CONFIG_DELAY_FIRST_REPEAT
    &ir_first_repeat_attr.attr,
#endif
    &ir_decode_debug_attr.attr,
    &ir_irda_key_decode_on_off_attr.attr,
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE
    &ir_gen_keycode_attr.attr,
    &ir_poll_interval_attr.attr,
    &ir_keycode_to_scancode_attr.attr,
    &ir_mute_irda_keyevent_attr.attr,
    &ir_to_mouse_attr.attr,
    &ir_repeat_event_attr.attr,
    &ir_rawkey_event_attr.attr,
    &ir_report_mode_attr.attr,
    &ir_is_upload_more_key_attr.attr,
    &ir_set_intercept_key_attr.attr,
#endif
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE_MOUSE
    &ir_mouse_pointer_speed_attr.attr,
    &ir_mouse_pointer_threshold_attr.attr,
    &ir_mouse_pointer_timer_attr.attr,
    &ir_mouse_pointer_step_attr.attr,
#endif
    NULL,
};

struct attribute_group ir_attr_group = {
    .attrs = ir_attrs,
};
