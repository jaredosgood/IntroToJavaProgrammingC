//
// Created by JaredOsgood on 10/6/2026.
//

#ifndef INTROTOJAVAPROGRAMMINGC_PROBLEM3_30_H
#define INTROTOJAVAPROGRAMMINGC_PROBLEM3_30_H

#include <stddef.h>
#include <stdint.h>

static constexpr size_t RESULT_SIZE = 64;

[[nodiscard]] char *run_at(int time_zone_offset, int64_t total_millis, char out[static RESULT_SIZE]);
[[nodiscard]] char *run_now(int time_zone_offset, char out[static RESULT_SIZE]);

#endif //INTROTOJAVAPROGRAMMINGC_PROBLEM3_30_H
