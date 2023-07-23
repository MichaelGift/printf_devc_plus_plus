#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int length_flag_checker(va_list args, Flags flags)
{
	
	int num; 
	if (flags.length_modifier == 2) // 'l' length modifier
    {
        num = va_arg(args, long int);
        // Handle long integer
        // ...
    }
    else if (flags.length_modifier == 1) // 'h' length modifier
    {
        num = va_arg(args, int); // Or short int, depending on platform
        // Handle short integer
        // ...
    }
    else // No length modifier (regular 'd', 'i')
    {
        num = va_arg(args, int);
        // Handle regular integer
        // ...
    }
    return (num);
}

int calculate_field_width(int num)
{
    int width = (num == 0) ? 1 : 0;
    while (num != 0)
    {
        width++;
        num /= 10;
    }
    return width;
}

void handle_width_flag(int num_width, Flags flags, int num, void (*specific_print_function)(int, Flags))
{
	int num_spaces = flags.field_width - num_width;
	if (flags.plus_flag || flags.space_flag || num < 0)
		num_spaces--;

    if (flags.minus_flag)
    {
    	specific_print_function(num, flags);
        // Left-justified - padding on the right
        while (num_spaces > 0)
        {
            _putchar('_');
            num_spaces--;
        }
    }
    else
    {
        // Right-justified - padding on the left
        while (num_spaces > 0)
        {
        	if (flags.zero_flag)
        		_putchar('0');
            _putchar('_');
            num_spaces--;
        }
        specific_print_function(num, flags);
    }
}
void handle_space_or_plus_flag(Flags flags)
{
	if (flags.plus_flag)
        _putchar('+'); // Print "+" sign for positive numbers if the "+" flag is set
    else if (flags.space_flag)
        _putchar(' '); // Print space for positive numbers if the "space" flag is set
}
