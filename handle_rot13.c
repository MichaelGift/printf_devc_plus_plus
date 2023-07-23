#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void handle_rot13(va_list args, Flags flags) 
{
    const char *str = va_arg(args, const char *);

    while (*str != '\0') 
	{
        char c = *str;
        if ('a' <= c && c <= 'z') 
		{
            // Rotate lowercase letters
            c = 'a' + (c - 'a' + 13) % 26;
        } else if ('A' <= c && c <= 'Z') 
		{
            // Rotate uppercase letters
            c = 'A' + (c - 'A' + 13) % 26;
        }
        _putchar(c);
        str++;
    }
}
