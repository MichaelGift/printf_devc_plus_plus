#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void handle_hexadecimal(va_list args, Flags flags) 
{
    unsigned int num = length_flag_checker(args, flags);
    int num_width = calculate_field_width(num);
    handle_width_flag(num_width, flags, num, print_hexadecimal);
}
void print_hexadecimal(unsigned int num, Flags flags)
{
	handle_space_or_plus_flag(flags);
	char buffer[32]; 
    int i = 0;

    if (num == 0) 
	{
        _putchar('0'); // Special case for 0
        return;
    } 
	
	// Convert the integer to hexadecimal representation
	while (num != 0) 
	{
		int rem = num % 16;
		if (rem < 10) 
		{
			buffer[i++] = '0' + rem; // For digits 0 to 9
		} 
		else 
		{
			buffer[i++] = 'a' + (rem - 10); // For letters a to f
		}
		num /= 16;
    }
    
    
    int j;
    // Print the hexadecimal representation in reverse order
	for (j = i - 1; j >= 0; j--) 
	{
		_putchar(buffer[j]);
	}
}
