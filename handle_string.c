#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

void handle_string(va_list args, Flags flags) 
{
    const char *str = va_arg(args, const char *);
    while (*str != '\0') 
	{
        _putchar(*str);
        str++;
    }
}
