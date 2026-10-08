//
// Created by JaredOsgood on 10/7/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "problem3_31.h"

#define RATE_PROMPT "Enter the exchange rate from dollars to RMB: "
#define DIRECTION_PROMPT "Enter 0 to convert dollars to RMB and 1 vice versa: "
#define RATE_ERROR "Error. The exchange rate must be greater than zero."
#define DIRECTION_ERROR "Error. Please enter 0 or 1."

static int tests_run = 0;
static int tests_failed = 0;

static void assert_equals(const char *test_name, const char *expected, const char *actual)
{
    ++tests_run;
    if (strcmp(expected, actual) == 0)
    {
        printf("PASS %s\n", test_name);
        return;
    }
    ++tests_failed;
    printf("FAIL %s\n  expected: \"%s\"\n  actual:   \"%s\"\n", test_name, expected, actual);
}

typedef struct
{
    double exchange_rate;
    bool dollar_to_rmb;
    double amount;
    const char *expected_output;
} ConvertCase;

static const ConvertCase convert_cases[] =
{
    // Dollars to yuan.
    {6.5, true, 100, "$100.00 is 650.00 yuan"},
    {6.5, true, 0, "$0.00 is 0.00 yuan"},
    {1.0, true, 25.50, "$25.50 is 25.50 yuan"},
    {0.5, true, 10, "$10.00 is 5.00 yuan"},

    // Yuan to dollars.
    {6.5, false, 650, "650.00 yuan is $100.00"},
    {6.5, false, 0, "0.00 yuan is $0.00"},
    {1.0, false, 25.50, "25.50 yuan is $25.50"},
    {0.5, false, 10, "10.00 yuan is $20.00"},

    // Results requiring rounding to two decimal places.
    {6.5, true, 10.25, "$10.25 is 66.63 yuan"},
    {6.5, false, 100, "100.00 yuan is $15.38"},
};

static void converts_amount_correctly()
{
    constexpr size_t case_count = sizeof convert_cases / sizeof convert_cases[0];

    for (size_t i = 0; i < case_count; ++i)
    {
        const ConvertCase *test_case = &convert_cases[i];

        char actual_output[CONVERSION_TEXT_SIZE] = {};
        convert(actual_output, sizeof actual_output, test_case->exchange_rate,
                test_case->dollar_to_rmb, test_case->amount);

        char test_name[128] = {};
        snprintf(test_name, sizeof test_name, "[%zu] rate=%g, dollarToRmb=%s, amount=%g",
                 i + 1, test_case->exchange_rate,
                 test_case->dollar_to_rmb ? "true" : "false", test_case->amount);

        assert_equals(test_name, test_case->expected_output, actual_output);
    }
}

typedef struct
{
    const char *input;
    const char *expected_output;
} ConsoleCase;

static const ConsoleCase console_cases[] =
{
    // Valid dollar-to-yuan conversion.
    {"6.5\n0\n100\n", RATE_PROMPT DIRECTION_PROMPT "Enter the dollar amount: " "$100.00 is 650.00 yuan"},

    // Valid yuan-to-dollar conversion.
    {"6.5\n1\n650\n", RATE_PROMPT DIRECTION_PROMPT "Enter the RMB amount: " "650.00 yuan is $100.00"},

    // Zero exchange rate.
    {"0\n", RATE_PROMPT RATE_ERROR},

    // Negative exchange rate.
    {"-6.5\n", RATE_PROMPT RATE_ERROR},

    // Invalid conversion directions.
    {"6.5\n2\n", RATE_PROMPT DIRECTION_PROMPT DIRECTION_ERROR},
    {"6.5\n-1\n", RATE_PROMPT DIRECTION_PROMPT DIRECTION_ERROR},
};

static void handles_console_input_correctly()
{
    constexpr size_t case_count = sizeof console_cases / sizeof console_cases[0];

    for (size_t i = 0; i < case_count; ++i)
    {
        FILE *in = tmpfile();
        FILE *out = tmpfile();
        if (in == nullptr || out == nullptr)
        {
            fputs("Could not create temporary files.\n", stderr);
            exit(EXIT_FAILURE);
        }

        fputs(console_cases[i].input, in);
        rewind(in);
        (void) run(in, out);

        rewind(out);
        char actual_output[512] = {};
        fread(actual_output, 1, sizeof actual_output - 1, out);

        char expected_output[512] = {};
        snprintf(expected_output, sizeof expected_output, "%s\n", console_cases[i].expected_output);

        char test_name[64] = {};
        snprintf(test_name, sizeof test_name, "[%zu] console behavior", i + 1);
        assert_equals(test_name, expected_output, actual_output);

        fclose(in);
        fclose(out);
    }
}

int main()
{
    converts_amount_correctly();
    handles_console_input_correctly();

    printf("\n%d tests, %d failed\n", tests_run, tests_failed);
    return tests_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}