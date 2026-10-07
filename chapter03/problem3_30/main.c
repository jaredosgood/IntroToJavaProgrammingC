//
// Created by JaredOsgood on 10/6/2026.
//
#include <stdio.h>
#include <stdlib.h>

#include "problem3_30.h"

int main(void) {
    printf("Enter the time zone offset to GMT: ");
    fflush(stdout);

    int time_zone_offset;
    if (scanf("%d", &time_zone_offset) != 1) {
        fputs("Invalid input.\n", stderr);
        return EXIT_FAILURE;
    }

    char result[RESULT_SIZE];
    puts(run_now(time_zone_offset, result));

    return EXIT_SUCCESS;
}