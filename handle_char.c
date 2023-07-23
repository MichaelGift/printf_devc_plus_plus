#include <stdarg.h>
#include <stdio.h>
#include "main.h"
void handle_char(va_list args, Flags flags)
{
	int c =  length_flag_checker(args, flags);
	int num_width = calculate_field_width(c);
	handle_width_flag(num_width, flags, c, print_char);
	
}
void print_char(int c, Flags flags)
{
	flags.plus_flag = 0;
	handle_space_or_plus_flag(flags);
	_putchar(c);
}
