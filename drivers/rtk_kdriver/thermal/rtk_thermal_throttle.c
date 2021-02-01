/*
 *  rtk_thermal_thorttle.c - A step-by-step Thermal throttling governor
 *
 *  Copyright (C) 2012 Intel Corp
 *  Copyright (C) 2012 Durgadoss R <durgadoss.r@intel.com>
 *
 *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#include <linux/thermal.h>
#include <trace/events/thermal.h>

#include "../../thermal/thermal_core.h"

/**
 * rtk_thermal_throttle - throttles devices associated with the given zone
 * @tz - thermal_zone_device
 * @trip - the trip point
 * @trip_type - type of the trip point
 *
 */
static int rtk_thermal_throttle(struct thermal_zone_device *tz, int trip)
{
    int trip_temp;
    enum thermal_trip_type trip_type;
    enum thermal_trend trend;
    bool throttle = false;
    int old_target;

    if(tz == NULL)
        return -1;

    if (trip == THERMAL_TRIPS_NONE) {
        trip_temp = tz->forced_passive;
        trip_type = THERMAL_TRIPS_NONE;
    } else {
        tz->ops->get_trip_temp(tz, trip, &trip_temp);
        tz->ops->get_trip_type(tz, trip, &trip_type);
    }


    trend = get_tz_trend(tz, trip);
    //printk("Trip%d[type=%d,temp=%d]:trend=%d,throttle=%d\n",
    //          trip, trip_type, trip_temp, trend, throttle);

    if (tz->temperature >= trip_temp) {
        throttle = true;
        trace_thermal_zone_trip(tz, trip, trip_type);
    }


    if(throttle) {
        /* invoked rtk callback here */
        if(tz->ops && tz->ops->notify && tz->ops->get_temp) {
            int degree;
            tz->ops->get_temp(tz, &degree);
            tz->ops->notify(tz, degree / 1000, 0);
        }
    }



//  printk("rtk_thermal_throttle\n");

    return 0;
}

static struct thermal_governor thermal_gov_rtk_thermal = {
    .name       = "rtk_thermal",
    .throttle   = rtk_thermal_throttle,
};

int thermal_gov_rtk_thermal_register(void)
{
    return thermal_register_governor(&thermal_gov_rtk_thermal);
}

void thermal_gov_rtk_thermal_unregister(void)
{
    thermal_unregister_governor(&thermal_gov_rtk_thermal);
}
