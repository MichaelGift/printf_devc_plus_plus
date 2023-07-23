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
