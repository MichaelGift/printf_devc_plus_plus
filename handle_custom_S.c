#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void handle_custom_S(va_list args, Flags flags) 
{
    const char *str = va_arg(args, const char *);

    while (*str != '\0') 
	{
        unsigned char c = *str;
        if (c < 32 || c >= 127) 
		{
			// Handle non-printable characters
            _putchar('\\');
            _putchar('x');
            // Print the hexadecimal representation manually
            char hex_digits[] = "0123456789ABCDEF";
            _putchar(hex_digits[c >> 4]);
            _putchar(hex_digits[c & 0xF]);
        } 
		else 
		{
            // Print printable characters as-is
            _putchar(c);
        }
        str++;
    }
}
