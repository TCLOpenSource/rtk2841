/*
 * rtk_thermal.c - Realtek TMU (Thermal Management Unit)
 *
 *  Copyright (C) 2011 Realtek
 *  Clamp Chien <clamp.chien@realtek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <linux/module.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/clk.h>
#include <linux/workqueue.h>
#include <linux/sysfs.h>
#include <linux/kobject.h>
#include <linux/export.h>
#include <linux/io.h>
#include <linux/mutex.h>
#include <rtk_kdriver/rtk_thermal_sensor.h>
#include <linux/thermal.h>
#include <linux/cpufreq.h>
#include <linux/cpu_cooling.h>
#include <linux/of.h>
#include <linux/of_device.h>

/* Byte-wise swap two items of size SIZE. */
#define SWAP(a, b, size)              \
  do {                        \
      size_t __size = (size);             \
      char *__a = (a), *__b = (b);        \
      do {                    \
      char __tmp = *__a;              \
      *__a++ = *__b;              \
      *__b++ = __tmp;             \
    } while (--__size > 0);           \
    } while (0)

/* Discontinue quicksort algorithm when partition gets below this
   size.  This particular magic number was chosen to work best on a
   Sun 4/260. */
#define MAX_THRESH 4

/* Stack node declarations used to store unfulfilled partition
 * obligations. */
typedef struct {
    char *lo;
    char *hi;
} stack_node;

/* The next 5 #defines implement a very fast in-line stack
 * abstraction.  The stack needs log (total_elements) entries (we
 * could even subtract log(MAX_THRESH)).  Since total_elements has
 * type size_t, we get as upper bound for log (total_elements): bits
 * per byte (CHAR_BIT) * sizeof(size_t).  */

#define CHAR_BIT 8
#define STACK_SIZE  (CHAR_BIT * sizeof(size_t))
#define PUSH(low, high) ((top->lo = (low)), (top->hi = (high)), ++top)
#define POP(low, high)  (--top, (low = top->lo), (high = top->hi))
#define STACK_NOT_EMPTY (stack < top)

void
qsort(void *const pbase, size_t total_elems, size_t size,
      int (*cmp)(const void*, const void*))
{
    char *base_ptr = (char *)pbase;

    const size_t max_thresh = MAX_THRESH * size;

    /* Avoid lossage with unsigned arithmetic below.  */
    if (total_elems == 0) {
        return;
    }

    if (total_elems > MAX_THRESH) {
        char *lo = base_ptr;
        char *hi = &lo[size * (total_elems - 1)];
        stack_node stack[STACK_SIZE];
        stack_node *top = stack + 1;

        while (STACK_NOT_EMPTY) {
            char *left_ptr;
            char *right_ptr;

            /* Select median value from among LO, MID, and
               HI. Rearrange LO and HI so the three values
               are sorted. This lowers the probability of
               picking a pathological pivot value and
               skips a comparison for both the LEFT_PTR
               and RIGHT_PTR in the while loops. */

            char *mid = lo + size * ((hi - lo) / size >> 1);

            if ((*cmp)((void*)mid, (void*)lo) < 0)
                SWAP(mid, lo, size);
            if ((*cmp)((void*)hi, (void*)mid) < 0)
                SWAP(mid, hi, size);
            else
                goto jump_over;
            if ((*cmp)((void*)mid, (void*)lo) < 0)
                SWAP(mid, lo, size);
        jump_over:

            left_ptr = lo + size;
            right_ptr = hi - size;

            /* Here's the famous ``collapse the walls''
               section of quicksort.  Gotta like those
               tight inner loops!  They are the main
               reason that this algorithm runs much faster
               than others. */
            do {
                while ((*cmp)((void*)left_ptr, (void*)mid) < 0)
                    left_ptr += size;

                while ((*cmp)((void*)mid, (void*)right_ptr) < 0)
                    right_ptr -= size;

                if (left_ptr < right_ptr) {
                    SWAP(left_ptr, right_ptr, size);
                    if (mid == left_ptr)
                        mid = right_ptr;
                    else if (mid == right_ptr)
                        mid = left_ptr;
                    left_ptr += size;
                    right_ptr -= size;
                } else if (left_ptr == right_ptr) {
                    left_ptr += size;
                    right_ptr -= size;
                    break;
                }
            } while (left_ptr <= right_ptr);

            /* Set up pointers for next iteration.  First
               determine whether left and right partitions
               are below the threshold size.  If so,
               ignore one or both.  Otherwise, push the
               larger partition's bounds on the stack and
               continue sorting the smaller one. */

            if ((size_t) (right_ptr - lo) <= max_thresh) {
                if ((size_t) (hi - left_ptr) <= max_thresh)
                    /* Ignore both small partitions. */
                    POP(lo, hi);
                else
                    /* Ignore small left partition. */
                    lo = left_ptr;
            } else if ((size_t) (hi - left_ptr) <= max_thresh)
                /* Ignore small right partition. */
                hi = right_ptr;
            else if ((right_ptr - lo) > (hi - left_ptr)) {
                /* Push larger left partition indices. */
                PUSH(lo, right_ptr);
                lo = left_ptr;
            } else {
                /* Push larger right partition indices. */
                PUSH(left_ptr, hi);
                hi = right_ptr;
            }
        }
    }

    /* Once the BASE_PTR array is partially sorted by quicksort
       the rest is completely sorted using insertion sort, since
       this is efficient for partitions below MAX_THRESH
       size. BASE_PTR points to the beginning of the array to
       sort, and END_PTR points at the very last element in the
       array (*not* one beyond it!). */

    {
        char *end_ptr = &base_ptr[size * (total_elems - 1)];
        char *tmp_ptr = base_ptr;
        char *thresh = min(end_ptr, base_ptr + max_thresh);
        char *run_ptr;

        /* Find smallest element in first threshold and place
           it at the array's beginning.  This is the smallest
           array element, and the operation speeds up
           insertion sort's inner loop. */

        for (run_ptr = tmp_ptr + size; run_ptr <= thresh; run_ptr += size)
            if ((*cmp)((void*)run_ptr, (void*)tmp_ptr) < 0)
                tmp_ptr = run_ptr;

        if (tmp_ptr != base_ptr)
            SWAP(tmp_ptr, base_ptr, size);

        /* Insertion sort, running from left-hand-side up to
         * right-hand-side.  */

        run_ptr = base_ptr + size;
        while ((run_ptr += size) <= end_ptr) {
            tmp_ptr = run_ptr - size;
            while ((*cmp)((void*)run_ptr, (void*)tmp_ptr) < 0)
                tmp_ptr -= size;

            tmp_ptr += size;
            if (tmp_ptr != run_ptr) {
                char *trav;

                trav = run_ptr + size;
                while (--trav >= run_ptr) {
                    char c = *trav;
                    char *hi, *lo;

                    for (hi = lo = trav; (lo -= size) >= tmp_ptr; hi = lo)
                        * hi = *lo;
                    *hi = c;
                }
            }
        }
    }
}



typedef struct rtk_temperature_callback {
    int degree;
    void (*func)(void *data, int cur_degree, int reg_degree, char *module_name);
    void *data;
    char module_name[20];
} st_rtk_temperature_callback;

#define RTK_TEMPE_CALLBACK_COUNT 20
static st_rtk_temperature_callback temperature_func[RTK_TEMPE_CALLBACK_COUNT];


int compare(const void *a, const void *b)//這函式是 qsort 所需的比較函式
{
    st_rtk_temperature_callback *c = (st_rtk_temperature_callback *)a;
    st_rtk_temperature_callback *d = (st_rtk_temperature_callback *)b;
    if(c->degree < d->degree) {
        return -1;   //傳回 -1 代表 a < b
    } else if (c->degree == d->degree) {
        return 0;   //傳回   0 代表 a = b
    } else return 1;                        //傳回  1 代表 a>b
}

int unregister_temperature_callback(int degree)
{
    int i;
    if(degree > 250 || degree < -250)
        return -1;
    for(i = 0; i < RTK_TEMPE_CALLBACK_COUNT; i++) {
        /* search same degree handler and override it */
        if(degree == temperature_func[i].degree) {
            temperature_func[i].func = NULL;
            temperature_func[i].data = NULL;
            temperature_func[i].degree = -255;
            memset(temperature_func[i].module_name, 0, sizeof(temperature_func[i].module_name));
            qsort((void *)temperature_func, RTK_TEMPE_CALLBACK_COUNT, sizeof(st_rtk_temperature_callback), compare);
            return 0;
        }
    }
    return -1;
}




/* return -1 if wrong parameter
              -2 if callback function full
              0  if successfully
 */
int register_temperature_callback(int degree, void *fn, void* data, char *module_name)
{
    const int mnlen = sizeof(temperature_func[0].module_name) - 1;
    int i;
    if(degree > 250 || degree < -250 || fn == NULL || data == NULL || module_name == NULL)
        return -1;

    for(i = 0; i < RTK_TEMPE_CALLBACK_COUNT; i++) {
        /* search same degree handler and override it */
        if((degree == temperature_func[i].degree) && (temperature_func[i].module_name != NULL) &&
           (strcmp(temperature_func[i].module_name, module_name) == 0)) {
            temperature_func[i].func = fn;
            temperature_func[i].data = data;
            printk("re-register:%d %s %d\n", i, module_name, degree);
            qsort((void *)temperature_func, RTK_TEMPE_CALLBACK_COUNT, sizeof(st_rtk_temperature_callback), compare);
            return 0;
        }
    }

    for(i = 0; i < RTK_TEMPE_CALLBACK_COUNT; i++) {
        /* select to assign null element */
        if(temperature_func[i].func == NULL) {
            temperature_func[i].func = fn;
            temperature_func[i].data = data;
            temperature_func[i].degree = degree;
            strncpy(temperature_func[i].module_name, module_name, mnlen);
            if (strlen(module_name) > mnlen)
                temperature_func[i].module_name[mnlen] = 0;
            qsort((void *)temperature_func, RTK_TEMPE_CALLBACK_COUNT, sizeof(st_rtk_temperature_callback), compare);
            printk("register:%d %s %d\n", i, module_name, degree);
            return 0;
        }
    }

    return -2;
}

EXPORT_SYMBOL(register_temperature_callback);

void callback_fn(void *data, int cur_degree , int reg_degree, char *module_name)
{
    printk("callback current degree :%d reg_degree:%d data:%x %s\n", cur_degree, reg_degree, (data) ? * ((int *)data) : -1, module_name);
}

static int exec_callback_fn(struct thermal_zone_device *thermal, int degree, enum thermal_trip_type type)
{
    int i;

    int calc_degree=0;
    if(degree > 40)
    {
	calc_degree=40+((degree - 40)*10/8);
    }

//  printk("%s %d\n",__func__,degree);
    if(degree > 250 || degree < -250)
        return -1;
    for(i = 0; i < RTK_TEMPE_CALLBACK_COUNT; i++) {
        if(temperature_func[i].func != NULL && temperature_func[i].degree != -255) {
            temperature_func[i].func(temperature_func[i].data, calc_degree, temperature_func[i].degree, temperature_func[i].module_name);
        }
#if 0
        if(degree > 0 && degree_diff < 0 && temperature_func[i].func != NULL) {
            temperature_func[i].func(temperature_func[i].data, calc_degree, temperature_func[i].degree);
            return ;
        }
#endif

    }
    return 0;
}


static int init_flag = 0;
void callback_reg_test(void) //this is just for test callback
{
    int i;
    static int myint[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    if(!init_flag) {
        for(i = 0; i < RTK_TEMPE_CALLBACK_COUNT; i++) {
            temperature_func[i].degree = -255;
            temperature_func[i].func = NULL;
        }
        register_temperature_callback(70, callback_fn, (void *)&myint[0], "CPU");
        register_temperature_callback(70, callback_fn, (void *)&myint[1], "GPU");
        register_temperature_callback(77, callback_fn, (void *)&myint[3], "CPU");
        register_temperature_callback(77, callback_fn, (void *)&myint[4], "GPU");
        register_temperature_callback(80, callback_fn, (void *)&myint[5], "CPU");
        register_temperature_callback(80, callback_fn, (void *)&myint[6], "GPU");
        register_temperature_callback(85, callback_fn, (void *)&myint[7], "CPU");
        register_temperature_callback(85, callback_fn, (void *)&myint[8], "GPU");
        register_temperature_callback(90, callback_fn, (void *)&myint[9], "CPU");
        register_temperature_callback(90, callback_fn, (void *)&myint[2], "GPU");
        for(i = 0; i < RTK_TEMPE_CALLBACK_COUNT; i++) {
            pr_info("register callback temp degree:%d\n", temperature_func[i].degree);
        }
        init_flag = 0;
    }
}

/* Rtk generic registers */
/* In-kernel thermal framework related macros & definations */
#define SENSOR_NAME_LEN 16
#define MAX_TRIP_COUNT  8
#define MAX_COOLING_DEVICE 4
#define MAX_THRESHOLD_LEVS 4
#define ACTIVE_INTERVAL 50000
#define IDLE_INTERVAL 100000 //Have interrupt trigger, enlarge the idle interval
#define MCELSIUS    1000

/* CPU Zone information */
#define PANIC_ZONE      4
#define WARN_ZONE       3
#define MONITOR_ZONE    2
#define SAFE_ZONE       1

#define GET_ZONE(trip) (trip + 2)
#define GET_TRIP(zone) (zone - 2)

#define RTK_ZONE_COUNT  3
enum soc_type {
    SOC_RTK_RTD294X = 1,
    SOC_RTK_RTD298X,
    SOC_RTK_RTD299S,
};

enum calibration_type {
    TYPE_ONE_POINT_TRIMMING,
    TYPE_TWO_POINT_TRIMMING,
    TYPE_NONE,
};

struct freq_clip_table {
    unsigned int freq_clip_max;
    unsigned int temp_level;
    const struct cpumask *mask_val;
};

struct rtk_tmu_data {
    struct rtk_tmu_platform_data *pdata;
    struct resource *mem;
    void __iomem *base;
    /*      int irq; */
    enum soc_type soc;
    int irq;
    struct work_struct irq_work;
    struct mutex lock;
    /*  struct clk *clk; */
    u8 temp_error1, temp_error2;
};

struct thermal_trip_point_conf {
    int trip_val[MAX_TRIP_COUNT];
    int trip_count;
    u8 trigger_falling;
};

struct thermal_cooling_conf {
    struct freq_clip_table freq_data[MAX_TRIP_COUNT];
    int freq_clip_count;
};

static irqreturn_t rtk_tmu_irq(int irq, void *id)
{
    struct rtk_tmu_data *data = id;

    disable_irq_nosync(irq);
    schedule_work(&data->irq_work);
    return IRQ_HANDLED;
}


struct thermal_sensor_conf {
    char name[SENSOR_NAME_LEN];
    int (*read_temperature) (void *data);
    int (*write_emul_temp) (void *drv_data, unsigned long temp);
    struct thermal_trip_point_conf trip_data;
    struct thermal_cooling_conf cooling_data;
    void *private_data;
};

struct rtk_thermal_zone {
    enum thermal_device_mode mode;
    struct thermal_zone_device *therm_dev;
    struct thermal_cooling_device *cool_dev[MAX_COOLING_DEVICE];
    unsigned int cool_dev_size;
    struct platform_device *rtk_dev;
    struct thermal_sensor_conf *sensor_conf;
    bool bind;
};

struct rtk_tmu_platform_data {
    u8 threshold;
    u8 threshold_falling;
    u8 trigger_levels[4];
    bool trigger_level0_en;
    bool trigger_level1_en;
    bool trigger_level2_en;
    bool trigger_level3_en;

    u8 gain;
    u8 reference_voltage;
    u8 noise_cancel_mode;
    u32 efuse_value;

    enum calibration_type cal_type;
    enum soc_type type;
    struct freq_clip_table freq_tab[4];
    unsigned int freq_tab_count;
};

static struct rtk_thermal_zone *th_zone;
#if 1
static void rtk_unregister_thermal(void);
static int rtk_register_thermal(struct thermal_sensor_conf *sensor_conf);
#endif

/* Get mode callback functions for thermal zone */
static int rtk_get_mode(struct thermal_zone_device *thermal,
                        enum thermal_device_mode *mode)
{
    if (th_zone)
        *mode = th_zone->mode;
    return 0;
}

/* Set mode callback functions for thermal zone */
static int rtk_set_mode(struct thermal_zone_device *thermal,
                        enum thermal_device_mode mode)
{
    if(!th_zone) {
        pr_notice("thermal zone is null\n");
        return -1;
    }

    if (!th_zone->therm_dev) {
        pr_notice("thermal zone not registered\n");
        return 0;
    }

    mutex_lock(&th_zone->therm_dev->lock);

    if (mode == THERMAL_DEVICE_ENABLED &&
        !th_zone->sensor_conf->trip_data.trigger_falling)
        th_zone->therm_dev->polling_delay = IDLE_INTERVAL;
    else
        th_zone->therm_dev->polling_delay = IDLE_INTERVAL;

    mutex_unlock(&th_zone->therm_dev->lock);

    th_zone->mode = mode;
    thermal_zone_device_update(th_zone->therm_dev);
    pr_info("thermal polling set for duration=%d msec\n",
            th_zone->therm_dev->polling_delay);
    return 0;
}

/* Get trip type callback functions for thermal zone */
static int rtk_get_trip_type(struct thermal_zone_device *thermal, int trip,
                             enum thermal_trip_type *type)
{
    switch (GET_ZONE(trip)) {
        case MONITOR_ZONE:
        case WARN_ZONE:
            *type = THERMAL_TRIP_ACTIVE;
            break;
        case PANIC_ZONE:
            *type = THERMAL_TRIP_CRITICAL;
            break;
        default:
            return -EINVAL;
    }
    return 0;
}

/* Get trip temperature callback functions for thermal zone */
static int rtk_get_trip_temp(struct thermal_zone_device *thermal, int trip,
                             int *temp)
{
    if (trip < GET_TRIP(MONITOR_ZONE) || trip > GET_TRIP(PANIC_ZONE))
        return -EINVAL;

    *temp = th_zone->sensor_conf->trip_data.trip_val[trip];
    /* convert the temperature into millicelsius */
    *temp = *temp * MCELSIUS;

    return 0;
}

/* Get critical temperature callback functions for thermal zone */
static int rtk_get_crit_temp(struct thermal_zone_device *thermal,
                             int *temp)
{
    int ret;
    /* Panic zone */
    ret = rtk_get_trip_temp(thermal, GET_TRIP(PANIC_ZONE), temp);
    return ret;
}

/* Bind callback functions for thermal zone */
static int rtk_bind(struct thermal_zone_device *thermal,
                    struct thermal_cooling_device *cdev)
{
    int ret = 0, i, tab_size, level;
    struct freq_clip_table *tab_ptr, *clip_data;
    struct thermal_sensor_conf *data = th_zone->sensor_conf;

    tab_ptr = (struct freq_clip_table *)data->cooling_data.freq_data;
    tab_size = data->cooling_data.freq_clip_count;

    if (tab_ptr == NULL || tab_size == 0)
        return -EINVAL;

    /* find the cooling device registered */
    for (i = 0; i < th_zone->cool_dev_size; i++)
        if (cdev == th_zone->cool_dev[i])
            break;

    /* No matching cooling device */
    if (i == th_zone->cool_dev_size)
        return 0;

    /* Bind the thermal zone to the cpufreq cooling device */
    for (i = 0; i < tab_size; i++) {
        clip_data = (struct freq_clip_table *) & (tab_ptr[i]);
        level = cpufreq_cooling_get_level(0, clip_data->freq_clip_max);
        pr_debug("binding level%d\n", level);
        if (level == THERMAL_CSTATE_INVALID)
            return 0;
        switch (GET_ZONE(i)) {
            case MONITOR_ZONE:
            case WARN_ZONE:
                if (thermal_zone_bind_cooling_device(thermal, i, cdev,
                                                     level, 0, THERMAL_WEIGHT_DEFAULT)) {
                    pr_err("error binding cdev inst %d\n", i);
                    ret = -EINVAL;
                }
                th_zone->bind = true;
                break;
            default:
                ret = -EINVAL;
        }
    }

    return ret;
}

/* Unbind callback functions for thermal zone */
static int rtk_unbind(struct thermal_zone_device *thermal,
                      struct thermal_cooling_device *cdev)
{
    int ret = 0, i, tab_size;
    struct thermal_sensor_conf *data = th_zone->sensor_conf;

    if (th_zone->bind == false)
        return 0;

    tab_size = data->cooling_data.freq_clip_count;

    if (tab_size == 0)
        return -EINVAL;

    /* find the cooling device registered */
    for (i = 0; i < th_zone->cool_dev_size; i++)
        if (cdev == th_zone->cool_dev[i])
            break;

    /* No matching cooling device */
    if (i == th_zone->cool_dev_size)
        return 0;

    /* Bind the thermal zone to the cpufreq cooling device */
    for (i = 0; i < tab_size; i++) {
        switch (GET_ZONE(i)) {
            case MONITOR_ZONE:
            case WARN_ZONE:
                if (thermal_zone_unbind_cooling_device(thermal, i,
                                                       cdev)) {
                    pr_err("error unbinding cdev inst=%d\n", i);
                    ret = -EINVAL;
                }
                th_zone->bind = false;
                break;
            default:
                ret = -EINVAL;
        }
    }
    return ret;
}

/* Get temperature callback functions for thermal zone */
static int rtk_get_temp(struct thermal_zone_device *thermal,
                        int *temp)
{
    void *data;

    if (!th_zone->sensor_conf) {
        pr_info("Temperature sensor not initialised\n");
        return -EINVAL;
    }
    data = th_zone->sensor_conf->private_data;
    *temp = th_zone->sensor_conf->read_temperature(data);
    /* convert the temperature into millicelsius */
    *temp = *temp * MCELSIUS;
    return 0;
}

/* Get temperature callback functions for thermal zone */
static int rtk_set_emul_temp(struct thermal_zone_device *thermal,
                             int temp)
{
    void *data;
    int ret = -EINVAL;

    if (!th_zone->sensor_conf) {
        pr_info("Temperature sensor not initialised\n");
        return -EINVAL;
    }
    data = th_zone->sensor_conf->private_data;
    if (th_zone->sensor_conf->write_emul_temp)
        ret = th_zone->sensor_conf->write_emul_temp(data, temp);
    return ret;
}

/* Get the temperature trend */
static int rtk_get_trend(struct thermal_zone_device *thermal,
                         int trip, enum thermal_trend *trend)
{
    int ret;
    int trip_temp;

    ret = rtk_get_trip_temp(thermal, trip, &trip_temp);
    if (ret < 0)
        return ret;

    if (thermal->temperature >= trip_temp)
        *trend = THERMAL_TREND_RAISE_FULL;
    else
        *trend = THERMAL_TREND_DROP_FULL;

    return 0;
}

/* Operation callback functions for thermal zone */
static struct thermal_zone_device_ops const rtk_dev_ops = {
    .bind = rtk_bind,
    .unbind = rtk_unbind,
    .get_temp = rtk_get_temp,
    .set_emul_temp = rtk_set_emul_temp,
    .get_trend = rtk_get_trend,
    .get_mode = rtk_get_mode,
    .set_mode = rtk_set_mode,
    .get_trip_type = rtk_get_trip_type,
    .get_trip_temp = rtk_get_trip_temp,
    .get_crit_temp = rtk_get_crit_temp,
    .notify = exec_callback_fn,
};

#if 1
/*
 * This function may be called from interrupt based temperature sensor
 * when threshold is changed.
 */
static void rtk_report_trigger(void)
{
    unsigned int i;
    char data[10];
    char *envp[] = { data, NULL };

    if (!th_zone || !th_zone->therm_dev)
        return;
    if (th_zone->bind == false) {
        for (i = 0; i < th_zone->cool_dev_size; i++) {
            if (!th_zone->cool_dev[i])
                continue;
            rtk_bind(th_zone->therm_dev, th_zone->cool_dev[i]);
        }
    }

    thermal_zone_device_update(th_zone->therm_dev);

    mutex_lock(&th_zone->therm_dev->lock);
    /* Find the level for which trip happened */
    for (i = 0; i < th_zone->sensor_conf->trip_data.trip_count; i++) {
        if (th_zone->therm_dev->last_temperature <
            th_zone->sensor_conf->trip_data.trip_val[i] * MCELSIUS)
            break;
    }

    if (th_zone->mode == THERMAL_DEVICE_ENABLED &&
        !th_zone->sensor_conf->trip_data.trigger_falling) {
        if (i > 0)
            th_zone->therm_dev->polling_delay = ACTIVE_INTERVAL;
        else
            th_zone->therm_dev->polling_delay = IDLE_INTERVAL;
    }

    snprintf(data, sizeof(data), "%u", i);
    kobject_uevent_env(&th_zone->therm_dev->device.kobj, KOBJ_CHANGE, envp);
    mutex_unlock(&th_zone->therm_dev->lock);
}

/* Register with the in-kernel thermal management */
static int rtk_register_thermal(struct thermal_sensor_conf *sensor_conf)
{
    int ret;
    struct cpumask mask_val;

    if (!sensor_conf || !sensor_conf->read_temperature) {
        pr_err("Temperature sensor not initialised\n");
        return -EINVAL;
    }

    th_zone = kzalloc(sizeof(struct rtk_thermal_zone), GFP_KERNEL);
    if (!th_zone) {
        pr_err("thermal create th_zone failed\n");
        return -ENOMEM;
    }

    th_zone->sensor_conf = sensor_conf;
    cpumask_set_cpu(0, &mask_val);
    th_zone->cool_dev[0] = cpufreq_cooling_register(&mask_val);
    if (IS_ERR(th_zone->cool_dev[0])) {
        pr_err("Failed to register cpufreq cooling device\n");
        ret = -EINVAL;
        goto err_unregister;
    }
    th_zone->cool_dev_size++;

    th_zone->therm_dev = thermal_zone_device_register(sensor_conf->name,
                         RTK_ZONE_COUNT, 0,
                         NULL, &rtk_dev_ops,
                         NULL, 0,
                         sensor_conf->trip_data.trigger_falling
                         ? IDLE_INTERVAL : IDLE_INTERVAL);

    if (IS_ERR(th_zone->therm_dev)) {
        pr_err("Failed to register thermal zone device\n");
        ret = PTR_ERR(th_zone->therm_dev);
        goto err_unregister;
    }
    th_zone->mode = THERMAL_DEVICE_ENABLED;

    pr_info("Kernel TMU registered\n");

    return 0;

err_unregister:
    rtk_unregister_thermal();
    return ret;
}

/* Un-Register with the in-kernel thermal management */
static void rtk_unregister_thermal(void)
{
    int i;

    if (!th_zone)
        return;

    if (th_zone->therm_dev)
        thermal_zone_device_unregister(th_zone->therm_dev);

    for (i = 0; i < th_zone->cool_dev_size; i++) {
        if (th_zone->cool_dev[i])
            cpufreq_cooling_unregister(th_zone->cool_dev[i]);
    }

    kfree(th_zone);
    pr_info("Kernel TMU unregistered\n");
}


static int rtk_tmu_initialize(struct platform_device *pdev)
{

    int ret = 0;
#ifdef CONFIG_RTK_KDRV_ENABLE_THERMAL_CALLBACK
    callback_reg_test();
#endif
    init_rtk_thermal_sensor();
    rtk_thermal_trigger_high(85); //default trigger value, write high first
    rtk_thermal_trigger_low(75);
    return ret;
}

static void rtk_tmu_control(struct platform_device *pdev, bool on)
{
    struct rtk_tmu_data *data = platform_get_drvdata(pdev);
//  struct rtk_tmu_platform_data *pdata = data->pdata;

    mutex_lock(&data->lock);
    if (on) {
        rtk_thermal_sensor_enable(true);
    } else {
        rtk_thermal_sensor_enable(false);

    }
    mutex_unlock(&data->lock);
}

#endif
#if 1
static int rtk_tmu_read(struct rtk_tmu_data *data)
{
    int temp;
    temp = rtk_get_thermal_value();
    if(temp > 40)
	temp=((temp - 40)*8/10) + 40;
    /*printk("sensor value:%d %s\n", temp, __func__);*/
    return temp;
}

static int rtk_tmu_set_emulation(void *drv_data, unsigned long temp)
{
    return 0;
}

static void rtk_tmu_work(struct work_struct *work)
{
    struct rtk_tmu_data *data = container_of(work,
                                struct rtk_tmu_data, irq_work);
    unsigned int reg = rtk_thermal_int_status();
    int temp = rtk_get_thermal_value_ext();
    rtk_report_trigger();
    rtk_thermal_trigger_high(temp + 1);
    rtk_thermal_trigger_low(temp - 1);
    pr_debug("rtk_tmu_work:%x %d\n", reg, temp);
//  exec_callback_fn(temp);
    rtk_thermal_sensor_enable(true);
    enable_irq(data->irq);
}

/*static irqreturn_t rtk_tmu_irq(int irq, void *id)
{
}*/
static struct thermal_sensor_conf rtk_sensor_conf = {
    .name = "rtk-thermal",
    .read_temperature = (int (*)(void *))rtk_tmu_read,
    .write_emul_temp = rtk_tmu_set_emulation,
};
#endif

static struct rtk_tmu_platform_data rtk_rtd299s_default_tmu_data = {
    .threshold = 75,
    .trigger_levels[0] = 5,
    .trigger_levels[1] = 13,
    .trigger_levels[2] = 41,
    .trigger_level0_en = 1,
    .trigger_level1_en = 1,
    .trigger_level2_en = 1,
    .trigger_level3_en = 0,
    .gain = 15,
    .reference_voltage = 7,
    .cal_type = TYPE_ONE_POINT_TRIMMING,
    .freq_tab[0] = {
        .freq_clip_max = 1150 * 1000,
        .temp_level = 85,
    },
    .freq_tab[1] = {
        .freq_clip_max = 700 * 1000,
        .temp_level = 170,
    },
    .freq_tab_count = 2,
    .type = SOC_RTK_RTD299S,
};


#define RTD299S_TMU_DRV_DATA (&rtk_rtd299s_default_tmu_data)
struct rtk_tmu_data rtk_ops = {
    .pdata = &rtk_rtd299s_default_tmu_data,
    .soc = SOC_RTK_RTD299S,
};


#ifdef CONFIG_OF
static const struct of_device_id rtk_tmu_match[] = {
    {
        .compatible = "rtk_rtk299s-tmu",
        .data = (void *)&rtk_ops,
    },
    {},
};

MODULE_DEVICE_TABLE(of, rtk_tmu_match);
#endif

static struct platform_device_id rtk_tmu_driver_ids[] = {
    {
        .name = "rtk-rtd299s-tmu",
        .driver_data = (kernel_ulong_t) RTD299S_TMU_DRV_DATA,
    },
    {},
};

MODULE_DEVICE_TABLE(platform, rtk_tmu_driver_ids);

static inline struct rtk_tmu_platform_data *rtk_get_driver_data(struct
        platform_device
        *pdev)
{
#ifdef CONFIG_OF
    if (pdev->dev.of_node) {
        const struct of_device_id *match;
        match = of_match_node(rtk_tmu_match, pdev->dev.of_node);
        if (!match)
            return NULL;
        return (struct rtk_tmu_platform_data *)match->data;
    }
#endif
    return (struct rtk_tmu_platform_data *)
           platform_get_device_id(pdev)->driver_data;
}
extern void register_cpufreq_callback(void);

static int rtk_tmu_probe(struct platform_device *pdev)
{
#ifdef CONFIG_CPU_FREQ
    struct rtk_tmu_data *data;
    struct rtk_tmu_platform_data *pdata;    /* = pdev->dev.platform_data; */
    int ret, i;
    const struct of_device_id *match;

    match = of_match_device(rtk_tmu_match, &pdev->dev);
    if (!match)
        return -ENODEV;

    data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);

    if (!data) {
        dev_err(&pdev->dev, "Failed to allocate driver structure\n");
        return -ENOMEM;
    }
    data = (struct rtk_tmu_data *)match->data;
    memset(temperature_func, 0, sizeof(temperature_func));
    data->irq = 73;//platform_get_irq(pdev, 0);
    if (data->irq < 0) {
        dev_err(&pdev->dev, "Failed to get platform irq\n");
        return data->irq;
    }

    INIT_WORK(&data->irq_work, rtk_tmu_work);

    data->mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    data->base = devm_ioremap_resource(&pdev->dev, data->mem);
    if (IS_ERR(data->base))
        return PTR_ERR(data->base);
    pdata = data->pdata;
    ret = devm_request_irq(&pdev->dev, data->irq, rtk_tmu_irq,
                           IRQF_TRIGGER_RISING, "rtk-tmu", data);
    if (ret) {
        dev_err(&pdev->dev, "Failed to request irq: %d\n", data->irq);
        return ret;
    }

    data->soc = pdata->type;
    data->pdata = pdata;
    platform_set_drvdata(pdev, data);
    mutex_init(&data->lock);

    ret = rtk_tmu_initialize(pdev);
    if (ret) {
        dev_err(&pdev->dev, "Failed to initialize TMU\n");
        goto err_clk;
    }

    /* Register the sensor with thermal management interface */
    (&rtk_sensor_conf)->private_data = data;
    rtk_sensor_conf.trip_data.trip_count = pdata->trigger_level0_en +
                                           pdata->trigger_level1_en + pdata->trigger_level2_en +
                                           pdata->trigger_level3_en;

    for (i = 0; i < rtk_sensor_conf.trip_data.trip_count; i++)
        rtk_sensor_conf.trip_data.trip_val[i] =
            pdata->threshold + pdata->trigger_levels[i];

    rtk_sensor_conf.trip_data.trigger_falling = pdata->threshold_falling;

    rtk_sensor_conf.cooling_data.freq_clip_count = pdata->freq_tab_count;
    for (i = 0; i < pdata->freq_tab_count; i++) {
        rtk_sensor_conf.cooling_data.freq_data[i].freq_clip_max =
            pdata->freq_tab[i].freq_clip_max;
        rtk_sensor_conf.cooling_data.freq_data[i].temp_level =
            pdata->freq_tab[i].temp_level;
    }

    ret = rtk_register_thermal(&rtk_sensor_conf);
    if (ret) {
        dev_err(&pdev->dev, "Failed to register thermal interface\n");
        goto err_clk;
    }
//  rtk_thermal_trigger_high(85); //default trigger value, write high first
//  rtk_thermal_trigger_low(75);
    rtk_tmu_control(pdev, true);

	register_cpufreq_callback(); 

    return 0;
err_clk:
    platform_set_drvdata(pdev, NULL);
    /*  clk_unprepare(data->clk); */
    return ret;

#else
    init_rtk_thermal_sensor();
    device_enable_async_suspend(&pdev->dev);
    return 0;
#endif
}

static int rtk_tmu_remove(struct platform_device *pdev)
{
#ifdef CONFIG_CPU_FREQ
    //struct rtk_tmu_data *data = platform_get_drvdata(pdev);

    rtk_tmu_control(pdev, false);

    rtk_unregister_thermal();

    /*clk_unprepare(data->clk);*/

    platform_set_drvdata(pdev, NULL);
    exit_rtk_thermal_sensor();
#else
    exit_rtk_thermal_sensor();
#endif
    return 0;
}

#ifdef CONFIG_PM
static int rtk_thermal_suspend(struct platform_device *dev)
{
    if(dev)
        dev = dev;
    exit_rtk_thermal_sensor();
    return 0;
}

static int rtk_thermal_resume(struct platform_device *dev)
{
    if(dev)
        dev = dev;
    init_rtk_thermal_sensor();
    return 0;
}

static int rtk_tmu_suspend(struct device *dev)
{
    rtk_thermal_suspend((struct platform_device *)dev);
#ifdef CONFIG_CPU_FREQ
    rtk_tmu_control(to_platform_device(dev), false);
#endif

    return 0;
}

static int rtk_tmu_resume(struct device *dev)
{
#ifdef CONFIG_CPU_FREQ
    struct platform_device *pdev = to_platform_device(dev);
    rtk_tmu_initialize(pdev);
    rtk_tmu_control(pdev, true);
#else
    rtk_thermal_resume((struct platform_device *)dev);
#endif
    return 0;
}

static const struct dev_pm_ops rtk_tmu_pm_ops = {
    .suspend    = rtk_tmu_suspend,
    .resume     = rtk_tmu_resume,
#ifdef CONFIG_HIBERNATION
    .freeze     = rtk_tmu_suspend,
    .thaw       = rtk_tmu_resume,
    .poweroff   = rtk_tmu_suspend,
    .restore    = rtk_tmu_resume,
#endif
};
#endif

static struct platform_driver rtk_tmu_driver = {
    .driver = {
        .name = "rtk-tmu",
        .owner = THIS_MODULE,
#ifdef CONFIG_PM
        .pm = &rtk_tmu_pm_ops,
#endif
        .of_match_table = of_match_ptr(rtk_tmu_match),
    },
    .probe = rtk_tmu_probe,
    .remove = rtk_tmu_remove,
    .id_table = rtk_tmu_driver_ids,
};

//EXPORT_SYMBOL(register_temperature_callback);
//EXPORT_SYMBOL(unregister_temperature_callback);


module_platform_driver(rtk_tmu_driver);

MODULE_DESCRIPTION("RTK TMU Driver");
MODULE_AUTHOR("<clamp.chien@realtek.com.tw");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:rtk-tmu");
