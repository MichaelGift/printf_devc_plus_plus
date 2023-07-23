#include <stdio.h>
#include <stdarg.h>
#include "main.h"
void handle_integer(va_list args, Flags flags)
{
	int i;
	int num = length_flag_checker(args, flags);
	int num_width = calculate_field_width(num); // Calculate the width of the number

    // Print padding characters (spaces) if necessary before the number
    if (flags.field_width > num_width)
    {
        int padding = flags.field_width - num_width;
        while (padding > 0)
        {
        	if (num < 0)
        		padding--;
            _putchar(' ');
            padding--;
        }
    }
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	else
    {
        if (flags.plus_flag)
            _putchar('+'); // Print "+" sign for positive numbers if the "+" flag is set
        else if (flags.space_flag)
            _putchar(' '); // Print space for positive numbers if the "space" flag is set
    }
	
	if (num  == 0)
	{
		_putchar('0');
		return;
	}

    print_digits(num);
}


/**
* print_digits - prints digits recursively
* @n: number to printed
*/
void print_digits(int n)
{
	if (n == 0)
        return;

    print_digits(n / 10);
    _putchar((n % 10) + '0');
}
