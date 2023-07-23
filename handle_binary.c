#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void handle_binary(va_list args, Flags flags) 
{
    unsigned int num = va_arg(args, unsigned int);
    char buffer[32]; // Assuming a maximum of 32 characters for the binary representation
    int i = 0;

    if (num == 0) 
	{
        _putchar('0'); // Special case for 0
        return;
    } 
	
    // Convert the integer to binary representation
        
	while (num != 0) 
	{
        buffer[i++] = '0' + (num & 1);
        num >>= 1;
    }

    int j;
	// Print the binary representation in reverse order
    for (j = i - 1; j >= 0; j--) 
	{
        _putchar(buffer[j]);
    }
}
