//
// Created by JaredOsgood on 10/7/2026.
//

#include "problem3_31.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static double round_to_cents(double value)
{
    return round(value * 100.0) / 100.0;
}

void convert(char *buffer, size_t size, double exchange_rate, bool dollar_to_rmb, double amount)
{
    if (dollar_to_rmb)
    {
        auto rmb_amount = amount * exchange_rate;
        snprintf(buffer, size, "$%.2f is %.2f yuan", round_to_cents(amount), round_to_cents(rmb_amount));
    } else
    {
        auto dollar_amount = amount / exchange_rate;
        snprintf(buffer, size, "%.2f yuan is $%.2f", round_to_cents(amount), round_to_cents(dollar_amount));
    }
}

static void prompt(FILE *out, const char *text)
{
    fputs(text, out);
    fflush(out);
}

static bool read_double(FILE *in, double *value)
{
    return fscanf(in, "%lf", value) == 1;
}

static int report_invalid_input()
{
    fputs("Error. Input was not a valid number.\n", stderr);
    return EXIT_FAILURE;
}

int run(FILE *in, FILE *out)
{
    prompt(out, "Enter the exchange rate from dollars to RMB: ");
    double exchange_rate = 0.0;
    if (!read_double(in, &exchange_rate))
    {
        return report_invalid_input();
    }
    if (exchange_rate <= 0)
    {
        fputs("Error. The exchange rate must be greater than zero.\n", out);
        return EXIT_SUCCESS;
    }

    prompt(out, "Enter 0 to convert dollars to RMB and 1 vice versa: ");
    int conversion_direction = 0;
    if (fscanf(in, "%d", &conversion_direction) != 1)
    {
        return report_invalid_input();
    }

    char result[CONVERSION_TEXT_SIZE] = {};

    if (conversion_direction == 0)
    {
        prompt(out, "Enter the dollar amount: ");
        double dollar_amount = 0.0;
        if (!read_double(in, &dollar_amount))
        {
            return report_invalid_input();
        }
        convert(result, sizeof result, exchange_rate, true, dollar_amount);
        fprintf(out, "%s\n", result);
    } else if (conversion_direction == 1)
    {
        prompt(out, "Enter the RMB amount: ");
        double rmb_amount = 0.0;
        if (!read_double(in, &rmb_amount))
        {
            return report_invalid_input();
        }
        convert(result, sizeof result, exchange_rate, false, rmb_amount);
        fprintf(out, "%s\n", result);
    } else
    {
        fputs("Error. Please enter 0 or 1.\n", out);
    }
 
    return EXIT_SUCCESS;
}