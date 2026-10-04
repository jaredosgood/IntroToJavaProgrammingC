//
// Created by JaredOsgood on 10/3/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "problem3_28.h"

typedef struct
{
    double r1_center_x, r1_center_y, r1_width, r1_height;
    double r2_center_x, r2_center_y, r2_width, r2_height;
    const char *expected_output;
} TestCase;

static const TestCase test_cases[] = {
    {
        .r1_center_x = 2.5, .r1_center_y = 4, .r1_width = 2.5, .r1_height = 43,
        .r2_center_x = 1.5, .r2_center_y = 5, .r2_width = 0.5, .r2_height = 3,
        .expected_output = "r2 is inside r1"
    },
    {
        .r1_center_x = 1, .r1_center_y = 2, .r1_width = 3, .r1_height = 5.5,
      .r2_center_x = 3, .r2_center_y = 4, .r2_width = 4.5, .r2_height = 5,
      .expected_output = "r2 overlaps r1"
    },
    {
        .r1_center_x = 1, .r1_center_y = 2, .r1_width = 3, .r1_height = 3,
      .r2_center_x = 40, .r2_center_y = 45, .r2_width = 3, .r2_height = 2,
      .expected_output = "r2 does not overlap r1"
    },
};
    constexpr size_t test_count = sizeof test_cases / sizeof test_cases[0];

int main(void)
{
    int failures = 0;

    for (size_t i = 0; i < test_count; i++)
    {
        auto tc = &test_cases[i];

        const char *actual_output = run(tc->r1_center_x, tc->r1_center_y, tc->r1_width, tc->r1_height,
            tc->r2_center_x, tc->r2_center_y, tc->r2_width, tc->r2_height);

        if (strcmp(tc->expected_output, actual_output) == 0)
        {
            printf("PASS test %zu\n", i + 1);
        } else
        {
            printf("FAIL test %zu: expected %s, got %s\n", i + 1, tc->expected_output, actual_output);
            failures++;
        }
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}