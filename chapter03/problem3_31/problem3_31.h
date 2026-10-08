//
// Created by JaredOsgood on 10/7/2026.
//

#ifndef INTROTOJAVAPROGRAMMINGC_PROBLEM3_31_H
#define INTROTOJAVAPROGRAMMINGC_PROBLEM3_31_H

#include <stddef.h>
#include <stdio.h>

static constexpr size_t CONVERSION_TEXT_SIZE = 64;

void convert(char *buffer, size_t size, double exchange_rate, bool dollar_to_rmb, double amount);

[[nodiscard]] int run(FILE *in, FILE *out);

#endif //INTROTOJAVAPROGRAMMINGC_PROBLEM3_31_H
