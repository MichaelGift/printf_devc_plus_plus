#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void handle_reverse(va_list args, Flags flags) 
{
    const char *str = va_arg(args, const char *);
    int len = 0, i;

    // Calculate the length of the string
    while (str[len] != '\0') 
	{
        len++;
    }

    // Print the reversed string
    for (i = len - 1; i >= 0; i--) 
	{
        _putchar(str[i]);
    }
}
