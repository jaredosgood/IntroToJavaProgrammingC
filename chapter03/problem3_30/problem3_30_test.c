//
// Created by JaredOsgood on 10/6/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "problem3_30.h"

typedef struct
{
    int offset;
    const char *utc_time;
    const char *expected;
} TestCase;

static int64_t parse_utc_millis(const char *utc)
{
    struct tm tm = {};

    int parsed = sscanf(utc, "%d-%d-%dT%d:%d:%dZ",
        &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec);

    if (parsed != 6)
    {
        return -1;
    }

    tm.tm_year -= 1900;
    tm.tm_mon -= 1;

#ifdef _WIN32
    return (int64_t)_mkgmtime(&tm) * 1'000;  // Windows
#else
    return (int64_t)timegm(&tm) * 1'000;     // Linux/macOS
#endif
}

int main(void)
{
    static const TestCase cases[] = {
        { .offset =  0, .utc_time = "2026-01-01T00:00:00Z", .expected = "The current time is 12:00:00 AM" },
        { .offset =  0, .utc_time = "2026-01-01T00:59:59Z", .expected = "The current time is 12:59:59 AM" },
        { .offset =  0, .utc_time = "2026-01-01T05:07:09Z", .expected = "The current time is 5:07:09 AM" },
        { .offset =  0, .utc_time = "2026-01-01T11:59:59Z", .expected = "The current time is 11:59:59 AM" },
        { .offset =  0, .utc_time = "2026-01-01T12:00:00Z", .expected = "The current time is 12:00:00 PM" },
        { .offset =  0, .utc_time = "2026-01-01T12:59:59Z", .expected = "The current time is 12:59:59 PM" },
        { .offset =  0, .utc_time = "2026-01-01T13:07:09Z", .expected = "The current time is 1:07:09 PM" },
        { .offset =  0, .utc_time = "2026-01-01T23:59:59Z", .expected = "The current time is 11:59:59 PM" },
        { .offset =  3, .utc_time = "2026-01-01T23:15:45Z", .expected = "The current time is 2:15:45 AM" },
        { .offset = -5, .utc_time = "2026-01-01T02:15:45Z", .expected = "The current time is 9:15:45 PM" },
        { .offset =  2, .utc_time = "2026-01-01T10:00:00Z", .expected = "The current time is 12:00:00 PM" },
        { .offset = -2, .utc_time = "2026-01-01T02:00:00Z", .expected = "The current time is 12:00:00 AM" },
    };

    constexpr size_t case_count = sizeof cases / sizeof cases[0];

    int failures = 0;
    for (size_t i = 0; i < case_count; ++i)
    {
        char actual[RESULT_SIZE];
        (void)run_at(cases[i].offset, parse_utc_millis(cases[i].utc_time), actual);

        bool passed = strcmp(actual, cases[i].expected) == 0;

        printf("[%zu] offset=%d, UTC%s: %s\n", i + 1, cases[i].offset, cases[i].utc_time, passed ? "PASS" : "FAIL");

        if (!passed)
        {
            printf("    expected: %s\n  actual: %s\n", cases[i].expected, actual);
            failures++;
        }
    }

    printf("%zu tests, %d failed\n", case_count, failures);
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}