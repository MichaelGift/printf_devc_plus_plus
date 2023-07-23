#include <stdio.h>
#include <stdarg.h>
#include "main.h"
void handle_unsigned_integer(va_list args, Flags flags)
{
    int num = length_flag_checker(args, flags);
    int num_width = calculate_field_width(num);
    handle_width_flag(num_width, flags, num, print_unsigned_integer);
}
void print_unsigned_integer(unsigned int num, Flags flags)
{
    handle_space_or_plus_flag(flags);

    // Count the number of digits in the unsigned integer
    int digits = 0;
    unsigned int temp = num;
    while (temp > 0)
    {
        temp /= 10;
        digits++;
    }

    // Calculate the divisor to extract each digit
    unsigned int divisor = 1;
    int i;
    for (i = 1; i < digits; i++)
    {
        divisor *= 10;
    }

    // Print each digit one by one
    while (divisor > 0)
    {
        unsigned int digit = num / divisor;
        _putchar(digit + '0');
        num %= divisor;
        divisor /= 10;
    }
}
