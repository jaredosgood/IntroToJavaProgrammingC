//
// Created by JaredOsgood on 10/4/2026.
//
#include <math.h>
#include "problem3_29.h"

const char *run(double xC1, double yC1, double rC1,
                double xC2, double yC2, double rC2)
{
    auto distance = sqrt(pow(xC2 - xC1, 2) + pow(yC2 - yC1, 2));

    if (distance <= rC1 - rC2)
    {
        return "circle2 is inside circle1";
    }
    if (distance <= rC1 + rC2) {
        return "circle2 overlaps circle1";
    }
    return "circle2 does not overlap circle1";
}
