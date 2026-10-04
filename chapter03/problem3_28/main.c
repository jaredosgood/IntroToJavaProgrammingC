//
// Created by JaredOsgood on 10/3/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "problem3_28.h"

int main(void)
{
    double r1_center_x, r1_center_y, r1_width, r1_height;
    double r2_center_x, r2_center_y, r2_width, r2_height;

    printf("Enter r1's center x-, y-coordinates, width, and height: ");
    if (scanf("%lf %lf %lf %lf", &r1_center_x, &r1_center_y, &r1_width, &r1_height) != 4)
    {
        fputs("Invalid input.\n", stderr);
        return EXIT_FAILURE;
    }

    printf("Enter r2's center x-, y-coordinates, width, and height: ");
    if (scanf("%lf %lf %lf %lf", &r2_center_x, &r2_center_y, &r2_width, &r2_height) != 4)
    {
        fputs("Invalid input.\n", stderr);
        return EXIT_FAILURE;
    }

    puts(run(r1_center_x, r1_center_y, r1_width, r1_height,
        r2_center_x, r2_center_y, r2_width, r2_height));

    return EXIT_SUCCESS;
}