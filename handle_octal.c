#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void handle_octal(va_list args, Flags flags)
{
	int num = length_flag_checker(args, flags);
    int num_width = calculate_field_width(num);
    handle_width_flag(num_width, flags, num, print_octal);
}
void print_octal(unsigned int num, Flags flags)
{
	
	char buffer[32];
    int i = 0;
    handle_space_or_plus_flag(flags);
	
	// Convert the integer to octal representation
	while (num != 0) 
	{
		buffer[i++] = '0' + (num % 8);
		num /= 8;
	}
	int j;
	// Print the octal representation in reverse order
	for (j = i - 1; j >= 0; j--) 
	{
		_putchar(buffer[j]);
    }
}
