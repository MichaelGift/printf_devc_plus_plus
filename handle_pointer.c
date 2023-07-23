#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void handle_pointer(va_list args, Flags flags) 
{
	int i, hex_digit;
    void *ptr = va_arg(args, void *);
    uintptr_t address = (uintptr_t)ptr;

    // Convert the address to hexadecimal and print it
    for (i = sizeof(address) * 2 - 1; i >= 0; i--) 
	{
        hex_digit = (address >> (i * 4)) & 0xF;
        _putchar(hex_digit < 10 ? '0' + hex_digit : 'a' + (hex_digit - 10));
    }
}
