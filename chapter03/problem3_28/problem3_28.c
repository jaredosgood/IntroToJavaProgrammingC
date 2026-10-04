//
// Created by JaredOsgood on 10/3/2026.
//
#include "problem3_28.h"

const char *run(double r1_center_x, double r1_center_y,
                double r1_width, double r1_height,
                double r2_center_x, double r2_center_y,
                double r2_width, double r2_height)
{
    const double r1_left = r1_center_x - r1_width / 2;
    const double r1_right = r1_center_x + r1_width / 2;
    const double r1_bottom = r1_center_y - r1_height / 2;
    const double r1_top = r1_center_y + r1_height / 2;

    const double r2_left = r2_center_x - r2_width / 2;
    const double r2_right = r2_center_x + r2_width / 2;
    const double r2_bottom = r2_center_y - r2_height / 2;
    const double r2_top = r2_center_y + r2_height / 2;

    const bool inside =
        r1_left <= r2_left
        && r1_right >= r2_right
        && r1_bottom <= r2_bottom
        && r1_top >= r2_top;

    const bool no_overlap =
        r1_right < r2_left
        || r1_left > r2_right
        || r1_bottom > r2_top
        || r1_top < r2_bottom;

    if (inside) {
        return "r2 is inside r1";
    } else if (no_overlap) {
        return "r2 does not overlap r1";
    } else {
        return "r2 overlaps r1";
    }
}