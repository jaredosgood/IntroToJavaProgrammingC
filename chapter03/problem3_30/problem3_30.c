//
// Created by JaredOsgood on 10/6/2026.
//
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "problem3_30.h"

char *run_at(int time_zone_offset, int64_t total_millis, char out[static RESULT_SIZE])
{
    auto total_sec = total_millis / 1'000;
    auto curr_sec  = total_sec % 60;

    auto total_min = total_sec / 60;
    auto curr_min  = total_min % 60;

    auto total_hr  = total_min / 60;
    auto curr_hr   = total_hr % 24;

    int64_t curr_hr_local = ((curr_hr + time_zone_offset) % 24 + 24) % 24;

    const char *period = curr_hr_local < 12 ? "AM" : "PM";

    int64_t hour12 = curr_hr_local % 12;
    if (hour12 == 0)
    {
        hour12 = 12;
    }

    snprintf(out, RESULT_SIZE,
            "The current time is %" PRId64 ":%02" PRId64 ":%02" PRId64 " %s",
            hour12, curr_min, curr_sec, period);

    return out;
}

char *run_now(int time_zone_offset, char out[static RESULT_SIZE])
{
    time_t now = time(nullptr);

    int64_t total_millis = now * 1'000;

    return run_at(time_zone_offset, total_millis, out);
}
