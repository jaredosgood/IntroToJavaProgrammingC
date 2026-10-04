//
// Created by JaredOsgood on 10/4/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "problem3_29.h"

typedef struct
{
    double xC1, yC1, rC1;
    double xC2, yC2, rC2;
    const char *expected;
} TestCase;

static const TestCase cases[] =
{
    {.xC1 = 0.5, .yC1 = 5.1, .rC1 = 13, .xC2 = 1, .yC2 = 1.7, .rC2 = 4.5, .expected = "circle2 is inside circle1"},
    {.xC1 = 3.4, .yC1 = 5.7, .rC1 = 5.5, .xC2 = 6.7, .yC2 = 3.5, .rC2 = 3, .expected = "circle2 overlaps circle1"},
    {.xC1 = 3.4, .yC1 = 5.5, .rC1 = 1, .xC2 = 5.5, .yC2 = 7.2, .rC2 = 1, .expected = "circle2 does not overlap circle1"},
};

int main(void)
{
    constexpr size_t count = sizeof cases / sizeof cases[0];
    int failures = 0;

    for (size_t i = 0; i < count; i++)
    {
        const TestCase *t = &cases[i];
        const char *actual = run(t->xC1, t->yC1, t->rC1, t->xC2, t->yC2, t->rC2);

        if (strcmp(t->expected, actual) != 0)
        {
            printf("FAIL case %zu: expected \"%s\", got \"%s\"\n", i, t->expected, actual);
            failures++;
        } else
        {
            printf("PASS case %zu\n", i);
        }
    }

    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}