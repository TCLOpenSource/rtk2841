#include <linux/input_event_intercept.h>
#include <linux/spinlock.h>

static struct device *g_intercept_device = NULL;
int input_add_intercept_event(INPUT_EVENT_INTERCEPT_LIST *p_events_list, 
                                                u32 type, u32 code, u32 value, u32 flags)
{
    int ret = -1;
    unsigned long irq_flags;
    struct list_head *node = NULL;
    input_intercept_event *event = NULL;
    if(!p_events_list)
        return ret;
        
    write_lock_irqsave(&p_events_list->events_lock, irq_flags);

    list_for_each(node, &p_events_list->event_list) {
        input_intercept_event *tmp = list_entry(node, input_intercept_event, node);
        if((tmp->type == type) && (tmp->code == code) && (tmp->value == value)) {
                event = tmp;
                break;
        }
    }

    if(!event) {
        event = (input_intercept_event *)kzalloc(sizeof(input_intercept_event), GFP_ATOMIC);
        if(event) {
            event->type = type;
            event->code = code;
            event->value = value;
            event->flags = flags;
            list_add(&event->node, &p_events_list->event_list);
            ret = 0;
        }
    } else {
        event->flags = flags;
        ret = 0;
    }
    write_unlock_irqrestore(&p_events_list->events_lock, irq_flags);
    return ret;
}

int input_remove_intercept_event(INPUT_EVENT_INTERCEPT_LIST *p_events_list, 
                                                u32 type, u32 code, u32 value, u32 flags)
{
    struct list_head *node = NULL;
    input_intercept_event *event = NULL;
    unsigned long irq_flags;
    if(!p_events_list)
        return -1;
        
    write_lock_irqsave(&p_events_list->events_lock, irq_flags);

    list_for_each(node, &p_events_list->event_list) {
        input_intercept_event *tmp = list_entry(node, input_intercept_event, node);
        if((tmp->type == type) && (tmp->code == code) 
            && (tmp->value == value) && (tmp->flags == flags)) {
                event = tmp;
                break;
        }
    }
    
    if(event) {
        list_del(&(event->node));
        kfree(event);
        event = 0;
    }
    write_unlock_irqrestore(&p_events_list->events_lock, irq_flags);
    return 0;
}

int input_query_intercept_event(INPUT_EVENT_INTERCEPT_LIST *p_events_list,
                                    u32 type, u32 code, u32 value, u32 *flags) 
{
    int ret = -1;
    unsigned long irq_flags;
    struct list_head *node = NULL;
    input_intercept_event *event = NULL;
    
    if(!p_events_list)
        return ret;
    read_lock_irqsave(&p_events_list->events_lock, irq_flags);
    list_for_each(node, &p_events_list->event_list) {
        input_intercept_event *tmp = list_entry(node, input_intercept_event, node);
        if((!(tmp->flags & INPUT_INTERCEPT_EVENT_MATCH_TYPE) || (tmp->type == type))
                && (!(tmp->flags & INPUT_INTERCEPT_EVENT_MATCH_CODE) || (tmp->code == code))
                && (!(tmp->flags & INPUT_INTERCEPT_EVENT_MATCH_VALUE) || (tmp->value == value))) {
                event = tmp;
                break;
        }
    }
    if(event) {
        if(flags)
            *flags = event->flags;
        ret = 0;
    }
    read_unlock_irqrestore(&p_events_list->events_lock, irq_flags);    
    return ret;
}

int input_send_intercept_uevent(INPUT_EVENT_INTERCEPT_LIST *p_events_list, 
                                                            struct input_dev *input_dev,
                                                            u32 type, u32 code, u32 value)
{
    int ret = -1;
    unsigned long irq_flags;
    if(!p_events_list || !input_dev)
        return ret;
    spin_lock_irqsave(&p_events_list->uevents_lock, irq_flags);
    if(p_events_list->uevents_num < MAX_INTERCEPT_EVENT_ARRY_NUM) {
            p_events_list->uevents_array[p_events_list->uevents_num].type = type;
            p_events_list->uevents_array[p_events_list->uevents_num].code = code;
            p_events_list->uevents_array[p_events_list->uevents_num].value = value;
            input_get_device(input_dev);
            p_events_list->uevents_array[p_events_list->uevents_num].input_dev = input_dev;
            p_events_list->uevents_num++;
            ret = 0;  
    }
    spin_unlock_irqrestore(&p_events_list->uevents_lock, irq_flags);
    schedule_work(&p_events_list->work);
    return ret;
}

static void _send_intercept_uevent_func(struct input_dev *input_dev, 
                                            u32 type, u32 code, u32 value)
{
    char event[128] = {0};
    char *envp[2] = {NULL, NULL};
    
    if(input_dev == NULL)
        return;
        
    snprintf(event, sizeof(event), "intercept_event:type=%x,code=%x,value=%x,pid=%u,vid=%u,dev_idx=%u,device=%s@end", 
                    type, code, value, input_dev->id.product, input_dev->id.vendor, INPUT_GET_DEV_IDX(input_dev),
                    (input_dev->name != NULL) ? input_dev->name : "NONE");
	printk("intercept_event:type=%x,code=%x,value=%x,pid=%u,vid=%u,dev_idx=%u,device=%s@end", 
                    type, code, value, input_dev->id.product, input_dev->id.vendor, INPUT_GET_DEV_IDX(input_dev),
                    (input_dev->name != NULL) ? input_dev->name : "NONE");
    envp[0]= event;
    envp[1] = NULL;
	if(g_intercept_device)
        kobject_uevent_env(&g_intercept_device->kobj, KOBJ_CHANGE, envp);
    else
    kobject_uevent_env(&input_dev->dev.kobj, KOBJ_CHANGE, envp);
}



static void _input_intercept_events_work(struct work_struct *work)
{
    INPUT_EVENT_INTERCEPT_LIST *p_events_list = container_of (work, INPUT_EVENT_INTERCEPT_LIST, work);
    if(p_events_list) {
        unsigned long irq_flags;
        u32 uevent_num = 0; 
        input_intercept_uevent *uevents = (input_intercept_uevent *)kmalloc(sizeof(input_intercept_uevent) * MAX_INTERCEPT_EVENT_ARRY_NUM, GFP_KERNEL);
        if(!uevents)
            return;
        spin_lock_irqsave(&p_events_list->uevents_lock, irq_flags);
        if(p_events_list->uevents_num > 0) {
            uevent_num = p_events_list->uevents_num;
            memcpy(uevents, p_events_list->uevents_array, sizeof(uevents[0]) * uevent_num);
            p_events_list->uevents_num = 0;
        }
        spin_unlock_irqrestore(&p_events_list->uevents_lock, irq_flags);
        if(uevent_num) {
            int i = 0;
            for(i = 0; i < uevent_num; i++) {
                _send_intercept_uevent_func(uevents[i].input_dev, 
                            uevents[i].type, uevents[i].code, uevents[i].value);
                input_put_device(uevents[i].input_dev);
            }
        }
        kfree(uevents);
    }
    
}


int input_init_intercept_event_list(struct class *p_class, INPUT_EVENT_INTERCEPT_LIST *p_events_list)
{
    if(!p_class || !p_events_list)
        return -1;

    g_intercept_device = device_create(p_class, NULL, 0, NULL, "input-intercept");
    INIT_LIST_HEAD(&p_events_list->event_list);
    rwlock_init(&p_events_list->events_lock);
    
    p_events_list->uevents_num = 0;
    spin_lock_init(&p_events_list->uevents_lock);
    
    INIT_WORK(&p_events_list->work, _input_intercept_events_work);

    return 0;
}

int input_free_intercept_event_list(struct class *p_class, INPUT_EVENT_INTERCEPT_LIST *p_events_list)
{
    struct list_head *cur_node = NULL;
    struct list_head *prev_node = NULL;
    unsigned long irq_flags;
    
    if(!p_events_list)
        return -1;

    cancel_work_sync(&p_events_list->work);
    write_lock_irqsave(&p_events_list->events_lock, irq_flags);
    list_for_each_safe(cur_node, prev_node, &p_events_list->event_list) {
        input_intercept_event *tmp_struct = NULL;
        list_del(cur_node);
        tmp_struct = list_entry(cur_node, input_intercept_event, node);
        kfree(tmp_struct);
    }
    write_unlock_irqrestore(&p_events_list->events_lock, irq_flags);

    if(g_intercept_device)
        device_destroy(p_class, 0);
    return 0;
}