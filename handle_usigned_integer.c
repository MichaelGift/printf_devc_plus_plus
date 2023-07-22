#include <stdio.h>
#include <stdarg.h>
void handle_unsigned_integer(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	printf("%u", num);
}
