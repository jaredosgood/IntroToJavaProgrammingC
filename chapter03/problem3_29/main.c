//
// Created by JaredOsgood on 10/4/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "problem3_29.h"

int main(void)
{
    double xC1, yC1, rC1;
    double xC2, yC2, rC2;

    printf("Enter circle1's center x-, y-coordinates, and radius: ");
    fflush(stdout);

    if (scanf("%lf %lf %lf", &xC1, &yC1, &rC1) != 3)
    {
        fputs("Expected three numbers.\n", stderr);
        return EXIT_FAILURE;
    }

    printf("Enter circle2's center x-, y-coordinates, and radius: ");
    fflush(stdout);

    if (scanf("%lf %lf %lf", &xC2, &yC2, &rC2) != 3)
    {
        fputs("Expected three numbers.\n", stderr);
        return EXIT_FAILURE;
    }

    puts(run(xC1, yC1, rC1, xC2, yC2, rC2));
    return EXIT_SUCCESS;
}