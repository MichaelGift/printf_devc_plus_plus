#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void handle_octal(va_list args, Flags flags)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
    int i = 0;

    if (num == 0) 
	{
        _putchar('0'); // Special case for 0
        return;
    }
	
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
