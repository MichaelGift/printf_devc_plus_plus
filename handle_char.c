#include <stdarg.h>
#include <stdio.h>
#include "main.h"
void handle_char(va_list args, Flags flags)
{
	int c =  va_arg(args, int);
	_putchar(c);
}
