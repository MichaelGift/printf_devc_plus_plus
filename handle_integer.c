#include <stdio.h>
#include <stdarg.h>
#include "main.h"
void handle_integer(va_list args, Flags flags)
{
	int i;
	int num = length_flag_checker(args, flags);
	int num_width = calculate_field_width(num);
	handle_width_flag(num_width, flags, num, print_integer);
}
void print_integer(int num, Flags flags)
{
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	else
    {
        handle_space_or_plus_flag(flags);
    }
	
	if (num == 0)
	{
		_putchar('0');
		return;
	}
	
	print_num_recursive(num);
}
void print_num_recursive(int num)
{
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	if (num == 0)
        return;

    print_num_recursive(num / 10);
    _putchar((num % 10) + '0');
}
